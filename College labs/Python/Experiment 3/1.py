def isPerfect(n) :
    sum = 0
    for i in range(1,n) :
        if(n % i == 0) :
            sum += i
    
    if(sum == n) : return True
    return False

n = int(input("Enter the number to be checked : "))

if(isPerfect(n)) :
    print("Perfect number\n")
else :
    print("Not a perfect number\n")