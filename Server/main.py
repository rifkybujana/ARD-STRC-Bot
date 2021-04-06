from flask import Flask, redirect, request, render_template, url_for
from flask_mysqldb import MySQL

app = Flask(__name__)

app.config['MYSQL_HOST'] = 'localhost'
app.config['MYSQL_PASSWORD'] = '<Your Mysql Password>'
app.config['MYSQL_USER'] = '<Your MySQL Username>'
app.config['MYSQL_DB'] = '<Your MySQL database name>'

mysql = MySQL(app)

@app.route('/', methods=["POST", "GET"])
def GoToRoom():
    room = None
    
    if request.method == "POST":
        room = request.form['Enter_room'][-1]
        cur = mysql.connection.cursor()
        cur.execute("""UPDATE room SET cur_room = {} WHERE id = 1;""".format(room))
        mysql.connection.commit()
        cur.close()
    
    if not room:
        cur = mysql.connection.cursor()
        cur.execute("""SELECT cur_room FROM room WHERE id = 1""")
        room = str(cur.fetchall()[0][0])

    return render_template("index.html", data=room)

@app.route('/reset_position')
def ResetPos():
    cur = mysql.connection.cursor()
    cur.execute("""UPDATE room SET cur_room = 0 WHERE id = 1;""")
    mysql.connection.commit()
    cur.close()

    return redirect('/')

@app.route('/Get')
def GetRoom():
    cur = mysql.connection.cursor()
    cur.execute("""SELECT cur_room FROM room WHERE id = 1""")
    room = str(cur.fetchall()[0][0])

    return room

if __name__ == "__main__":
    app.run(host="0.0.0.0", debug=True)