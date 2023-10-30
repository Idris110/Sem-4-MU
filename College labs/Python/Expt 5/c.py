class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __str__(self):
        return "({0},{1})".format(self.x, self.y)

    def __add__(self, second):
        x = self.x + second.x
        y = self.y + second.y
        return Point(x, y)


p1 = Point(1, 2)
p2 = Point(2, 3)
p3 = Point("Idris ", "Hello ")
p4 = Point("Ratlamwala", "World")

print(p1+p2)
print(p3+p4)
