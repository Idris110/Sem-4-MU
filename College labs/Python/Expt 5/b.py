class Employee:
    def __init__(self, id):
        self.id = id  
    def setname(self, name):
        self.name = name      
    def getName(self):
        return self.name
    def getId(self):
        return self.id
        
class Student:
    def __init__(self, college):
        self.college = college
        
    def getCollege(self):
        return self.college
        
class Intern(Employee, Student):
    def __init__(self, id, college, period):
        Employee.__init__(self,id)
        Student.__init__(self,college)
        self.period = period
        
    def setDetails(self, name):
        self.name = name
        
    def getDetails(self):
        return self.name
        
intern1 = Intern("1","TSEC","3 months")
intern1.setDetails("Idris")
print("Intern Name : "+intern1.getName())
print("Intern ID: "+intern1.getId())
print("College Name "+intern1.getCollege())
print("Internship Tenure: "+intern1.period)
