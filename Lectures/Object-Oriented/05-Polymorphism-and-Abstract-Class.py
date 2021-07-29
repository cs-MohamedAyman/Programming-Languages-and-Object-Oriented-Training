class Shape:
    def __init__(self, name):
        self.name = name
    def area(self):
        pass
    def fact(self):
        return "This is a two-dimensional shape."
    def __str__(self):
        return 'shape name: ' + self.name

class Square(Shape):
    def __init__(self, length):
        super().__init__("Square")
        self.length = length
    def area(self):
        return self.length * self.length
    def fact(self):
        return "Squares have each angle equal to 90 degrees" + \
               " and all sides have an equal length."

class Rectangle(Shape):
    def __init__(self, length, width):
        super().__init__("Rectangle")
        self.length = length
        self.width = width
    def area(self):
        return self.length * self.width
    def fact(self):
        return "Rectangles have each angle equal to 90 degrees."

class Circle(Shape):
    def __init__(self, radius):
        super().__init__("Circle")
        self.radius = radius
    def area(self):
        return 3.1415 * self.radius * self.radius
    def fact(self):
        return "Circles have not any sides."

def display_shape_details(x):
    print('Shape ' + x.name + ' has area', x.area())
    print('and the shape fact is', x.fact())
    print('------------------------------------------')

a = Square(4)
b = Rectangle(4, 5)
c = Circle(7)
d = Shape('Polygon')
arr = [a, b, c ,d]
for i in arr:
    display_shape_details(i)

'''
Shape Square has area 16
and the shape fact is Squares have each angle equal to 90 degrees and all sides have an equal length.
------------------------------------------
Shape Rectangle has area 20
and the shape fact is Rectangles have each angle equal to 90 degrees
------------------------------------------
Shape Circle has area 153.9335
and the shape fact is Circles have not any sides.
------------------------------------------
Shape Polygon has area None
and the shape fact is This is a two-dimensional shape.
------------------------------------------
'''
