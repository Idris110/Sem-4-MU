import mysql.connector
from tkinter import *
from tkinter import ttk

def register():
    name1=name.get()
    con1=contact.get()
    email1=email.get()
    gen1=str(gender.get())
    city1=city.get()
    state1=state.get()
    if False:
        message.set("fill the empty field!!!")
    else:
        try:
            conn = mysql.connector.connect(host='localhost',user='root',password='1234',db='all_nighter')
            cursor = conn.cursor()

            create_query = '''create table if not exists regist
            (name1 varchar(50),
            con1 varchar(50),
            email1 varchar(30),
            gen1 varchar(20),
            city1 varchar(20),
            state1 varchar(20)
            );'''
            cursor.execute(create_query)

            data = [name1,con1,email1,gen1,city1,state1]
            insert_query = "insert into regist values(%s,%s,%s,%s,%s,%s)"
            cursor.execute(insert_query, data)
            # conn.commit()

            print("\nAll records from database : \nRecord 0 :\n")
            count = 0
            cursor.execute("select * from regist;")
            data = cursor.fetchall()
            for record in data :
                count = count+1
                for value in record :
                    print(value, end="\n")
                print("\nRecord "+ str(count)+" :")

        except Exception as e :
            print(e)
        message.set("Stored successfully")

def Registrationform():
    global reg_screen
    reg_screen = Tk()
    reg_screen.title("Registration Form")
    reg_screen.geometry("350x400")
    global message,name,contact,email,gender,city,state
    name = StringVar()
    contact = StringVar()
    email=StringVar()
    gender=IntVar()
    city=StringVar()
    state=StringVar()
    message=StringVar()
    Label(reg_screen,width="300", text="Please enter details below", bg="orange",fg="white").pack()
    Label(reg_screen, text="Name * ").place(x=20,y=40)
    Entry(reg_screen, textvariable=name).place(x=90,y=42)
    Label(reg_screen, text="Contact * ").place(x=20,y=80)
    Entry(reg_screen, textvariable=contact).place(x=90,y=82)
    Label(reg_screen, text="Email * ").place(x=20, y=120)
    Entry(reg_screen, textvariable=email).place(x=90, y=122)
    Label   (reg_screen, text="Gender * ").place(x=20, y=160)
    Radiobutton(reg_screen,text="Male",variable=gender,value=1).place(x=90,y=162)
    Radiobutton(reg_screen, text="Female", variable=gender, value=2).place(x=150, y=162)
    Label(reg_screen, text="City * ").place(x=20, y=200)
    monthchoosen = ttk.Combobox(reg_screen, width=27,
    textvariable=city)
    monthchoosen['values'] = (
    ' Mumbai',
    ' Bhopal',
    ' Patna',
    ' Indore',
    ' Nagpur',
    ' Motihari',
    ' Pune',
    ' Gwalior',
    ' Jabalpur',)
    monthchoosen.current()
    monthchoosen.place(x=90,y=202)
    monthchoosen['values'] = (' Mumbai',
    ' Bhopal',
    ' Patna',
    ' Indore',
    ' Nagpur',
    ' Motihari',
    ' Pune',
    ' Gwalior',
    ' Jabalpur',)
    monthchoosen.current()
    monthchoosen.place(x=90,y=202)
    Label(reg_screen, text="State * ").place(x=20, y=240)
    monthchoosen = ttk.Combobox(reg_screen, width=27,
    textvariable=state)
    monthchoosen['values'] = (' Madhya Pradesh',
    ' Maharashtra',
    ' Bihar',
    ' Punjab',
    ' Gujrat',)
    monthchoosen.current()
    monthchoosen.place(x=90, y=242)
    Label(reg_screen,
    text="",textvariable=message).place(x=95,y=264)
    Button(reg_screen, text="Register", width=10, height=1,
    bg="orange",command=register).place(x=105,y=300)
    reg_screen.mainloop()

Registrationform()