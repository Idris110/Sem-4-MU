def square(n) : return n*n

def cube(n) : return n*n*n

def incBy4(func,n) :
    return func(n) + 4

def multiBy2(func,n) :
    return func(n) * 4

print("Increase result by 4 after squaring 3"+str(incBy4(square, 3)))
print("Multiply result by 2 after squaring 3"+str(multiBy2(square, 3)))

print("Increase result by 4 after cubing 3"+str(incBy4(cube, 3)))
print("Multiply result by 2 after squaring 3"+str(multiBy2(cube, 3))+"\n")
