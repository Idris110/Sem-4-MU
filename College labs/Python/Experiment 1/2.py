name = str(input("Enter your name : "))
age = int(input("Enter age : "))

print("""\nUsing str.format()
Your name is {}, you're {}\n""".format(name,age))
print("""Using modulo operator
Your name is %s, you're %d\n"""%(name,age))