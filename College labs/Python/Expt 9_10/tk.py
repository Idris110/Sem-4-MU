import mysql.connector
from tkinter import *
from tkinter import messagebox
def login():
    uname=rollno.get()
    pwd=password.get()
    nam=name.get()
    yea=int(year.get())
    bran=branch.get()

    try:
        conn = mysql.connector.connect(host='localhost',user='root',password='1234',db='stud_db')
        cursor = conn.cursor()

        create_query = '''create table if not exists college_id
        (stud_name varchar(50),
        username varchar(50),
        passw varchar(20),
        branch varchar(20),
        year_ int
        );'''
        cursor.execute(create_query)

        data = [nam, uname, pwd, bran, yea]
        insert_query = "insert into college_id values(%s,%s,%s,%s,%s)"
        cursor.execute(insert_query, data)
        conn.commit()

        print("Name            \t"+ "Roll no  \t"+ "Pass\t" +"Branch\t" +"year")
        cursor.execute("select * from college_id;")
        data = cursor.fetchall()
        for record in data :
            for value in record :
                print(value, end=" \t")
            print()

    except Exception as e :
        print(e)


    if uname=='' or pwd==''or nam==''or yea==''or bran=='':
       messagebox.showerror('Error', 'Plese enter all details')
    else:
        messagebox.showinfo('Successful', 'Your data is saved\nsuccessfully !')

def Loginform():
    global login_screen
    login_screen = Tk()
    login_screen.title("College Id Form")
    bgCol='#adfffc'
    login_screen.geometry("400x350")
    login_screen.configure(bg=bgCol) 
    global  message
    global rollno
    global password
    global name
    global branch
    global year
    rollno = StringVar()
    password = StringVar()
    message=StringVar()
    name=StringVar()
    branch=StringVar()
    year=StringVar()
    Label(login_screen,width="300", text="Please enter details below", bg="#56a8a5",fg="white").pack()
    yoff=20
    llogin = Label(login_screen, text="rollno :")
    llogin.config(font=("Courier", 14),bg=bgCol)
    llogin.place(x=20,y=40+yoff)
    Entry(login_screen, textvariable=rollno).place(
        x=150,y=42+yoff,width=200,height=25)

    lpass = Label(login_screen, text="Password :")
    lpass.config(font=("Courier", 14),bg=bgCol)
    lpass.place(x=20,y=80+yoff)
    Entry(login_screen, textvariable=password ,show="*").place(
        x=150,y=82+yoff,width=200,height=25)

    lname = Label(login_screen, text="Name :")
    lname.config(font=("Courier", 14),bg=bgCol)
    lname.place(x=20,y=120+yoff)
    Entry(login_screen, textvariable=name ).place(
        x=150,y=122+yoff,width=200,height=25)

    lbra = Label(login_screen, text="Branch :")
    lbra.config(font=("Courier", 14),bg=bgCol)
    lbra.place(x=20,y=160+yoff)
    Entry(login_screen, textvariable=branch ).place(
        x=150,y=162+yoff,width=200,height=25)

    lyear = Label(login_screen, text="Year :")
    lyear.config(font=("Courier", 14),bg=bgCol)
    lyear.place(x=20,y=200+yoff)
    Entry(login_screen, textvariable=year ).place(
        x=150,y=202+yoff,width=200,height=25)
    
    but = Button(login_screen, text="Login", width=10, height=1, bg="orange",command=login)
    but.config(font=("Calibri", 14))
    but.place(x=140,y=260+yoff)
    login_screen.mainloop()
    
Loginform()