from abc import *
class printer(ABC):
    @abstractmethod
    def _print(self,text):
        pass
    
    @abstractmethod
    def disconnect(self):
        pass

class Ibm(printer):
    def _print(self, text):
        print(text)
    def disconnect(self):
         print("bye")
class hp:
    def _print(self, text):
        print(text)
    
    def disconnect(self):
         print("bye")
name = input("Printer name : ")
text = input("Enter text : ")
if name== 'HP':
    p=hp()
elif name== 'IBM':
    p=Ibm()
    
p._print(text)
p.disconnect()
