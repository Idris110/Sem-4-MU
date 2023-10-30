import mysql.connector

def submit() :
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

        nam=uname=pwd=bran="test2"
        yea=2021
        data = [nam, uname, pwd, bran, yea]
        insert_query = "insert into college_id values(%s,%s,%s,%s,%s)"
        cursor.execute(insert_query, data)
        conn.commit()
        # popup details saved !

        print("Roll no\t"+"Pass\t" +"Name\t"+"Year\tBranch")

        cursor.execute("select * from college_id;")
        data = cursor.fetchall()
        for record in data :
            for value in record :
                print(value, end=" \t")
            print()

    except Exception as e :
        print(e)

submit()