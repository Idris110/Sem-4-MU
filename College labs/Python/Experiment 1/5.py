
n = int(input("Enter the value of 'n': "))
a = 0
b = 1
sum = 0
count = 1

print("Fibonacci Series: ", end=" ")
while(count <= n):
    print(sum, end=" ")
    a = b
    b = sum
    sum = a + b
    count +=1
