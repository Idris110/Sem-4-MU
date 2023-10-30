import array

arr = array.array('i',[3,4,6,9,13,14,16,17])
out = array.array('i',[])
print("\nInitial array :")
for i in range (0, len(arr)):
    print (arr[i], end =" ")
print()

print("Filtered array :")
for i in range(len(arr)) :
    composite = False

    for j in range(2,arr[i]):
        if(arr[i]%j==0) : 
            composite =True
            break
    
    if(composite) :
         out.append(arr[i])

for i in range (0, len(out)):
    print (out[i], end =" ")
print()