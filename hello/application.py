from flask import Flask, render_template, request
import random

#serving this application frm this file
app = Flask(__name__)

@app.route("/")
def index():
#    number = random.randint(0, 1)
    return render_template("index.html")

#    number = random.randint(1, 10)
#    return "<h1>Hello, World!<h1>"
#   return render_template("index.html", name="ganesh", number = number)

@app.route("/goodbye")
def bye():
    return "Good bye"

@app.route("/hello")
def hello():

    name = request.args.get("name")
    if not name:
        return render_template("failure.html")
#it gets name arg in index.html

    return render_template("hello.html", name=name)