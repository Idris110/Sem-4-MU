
for i in range(6):
    for j in range(5-i):
        print(end=" ")
    for j in range(i+1):
        print(j+1,end="")
    for j in range(i,0,-1):
        print(j,end="")
    print()