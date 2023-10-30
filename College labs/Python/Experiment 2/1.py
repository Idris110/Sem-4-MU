import array

arr = array.array('i')
x = int(input("Enter the length of array: "))
for i in range(0, x):
    num = int(input("Enter element %d: "%i))
    arr.append(num)

print("\nInitial array :")
for i in range (0, len(arr)):
    print (arr[i], end =" ")
print()

arr.append(90)

print("\nAfter appending 90 :")
for i in range (0, len(arr)):
    print (arr[i], end =" ")
print()

print("\nAfter reversing :")
rev=arr[::-1]
for i in range (0, len(arr)):
    print (rev[i], end =" ")
print()

print("\nItem size :"+ str(arr.itemsize))

print("\nAfter removing element with index 1 :")
arr.pop(1)

for i in range (0, len(arr)):
    print (arr[i], end =" ")
print()

print("\nAfter inserting 69 at index 3 :")
arr.insert(3, 69)

for i in range (0, len(arr)):
    print (arr[i], end =" ")
print()
