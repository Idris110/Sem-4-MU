class Employee:
    empcount=0
    def __init__(self,id):
        self.id=id

    def set_id(self,id):
        self.id = id

    def set_emp_count(self,empcount):
        self.empcount=empcount
    
    def set_name(self,name):
        self.name = name

    def get_name(self):
        return self.name

    def get_id(self):
        return self.id

n=int(input("Enter the number of employees: \n"))
id = []
name = []
for i in range (n):
    id.append(input("Enter Employee-{} ID: \n".format(i+1)))
    name.append(input("Enter Employee-{} Name: \n".format(i+1)))

print()
print("Employee Id \t Employee Name")
for j in range(n):
    emp=Employee(id[j])
    emp.set_name(name[j])
    
    print(emp.get_id(),"\t\t",emp.get_name())
