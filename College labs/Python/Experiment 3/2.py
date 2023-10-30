def isPangram(s) :
    s=s.lower()
    alphabetSet = "abcdefghijklmnopqrstuvwxyz"

    for i in alphabetSet :
        if(i not in s) : return False
    
    return True

s = str(input("Enter the string to be checked :"))

if(isPangram(s)) : print('"'+s+'" is a pangram\n')
else : print('"'+s+'" is not a pangram\n')