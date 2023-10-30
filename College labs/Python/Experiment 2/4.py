
n =int(input("Enter the number of strings : "))

a = []
for i in range(n) :
    a.append(str(input()))

a.sort()

print("\nSorted string :")
for i in range (0, len(a)):
    print (a[i], end =" ")
print("\n")

string= str(input("Enter the string to be checked : "))

if(string==string[::-1]):
    print(string+" is a Palindrome")
else :
    print(string+" is not a Palindrome")
        