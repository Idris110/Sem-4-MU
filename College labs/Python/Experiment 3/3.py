
def add(*nums) :
    sum = 0
    for i in range(len(nums)):
        sum += int(nums[i])
    return sum

def sub(*nums) :
    diff = nums[0]
    for i in range(1,len(nums)):
        diff -= int(nums[i])
    return diff

def multiply(*nums) :
    multi = 1
    for i in range(len(nums)):
        multi *= int(nums[i])
    return multi

def div(*nums) :
    div = nums[0]
    for i in range(1,len(nums)):
        div /= int(nums[i])
    return div


print("1. Add \t2. Sub \t3. Multiply  4. Divide")
choice = int(input("Enter your choice : "))

nums = str(input("Enter the numbers : "))
parm = list(map(int,nums.split()))

if(choice == 1) : 
    print("Result of addition : " +str(add(*parm))+"\n")
elif(choice == 2) :
    print("Result of subtraction : " +str(sub(*parm))+"\n")
elif(choice == 3) :
    print("Result of multiplication : " +str(multiply(*parm))+"\n")
elif(choice == 4) :
     print("Result of division : " +str(div(*parm))+"\n")
