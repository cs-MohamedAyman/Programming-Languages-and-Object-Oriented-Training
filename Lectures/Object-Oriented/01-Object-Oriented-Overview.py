class Human:
    pass

x = Human()
y = Human()

class Human:
    name = ''
    age = 0
    gender = ''

x = Human()
x.name = 'Jack'
x.age = 24
x.gender = 'male'

print(x.name, x.age, x.gender)

#    Jack 24 male

class Human:
    def walking(self):
        print('I am walking now')
    def running(self):
        print('I am running now')

x = Human()
x.walking()
x.running()

#    I am walking now
#    I am running now

class Human:
    def __init__(self):
        self.name = ''
        self.age = 0
        self.gender = ''

x = Human()
print(x.name, x.age, x.gender)

class Human:
    def __init__(self, name, age, gender):
        self.name = name
        self.age = age
        self.gender = gender

x = Human('Jack', 24, 'male')
print(x.name, x.age, x.gender)

#    Jack 24 male

class Human:
    def __init__(self, name, age):
        self.name = name
        self.age = age

x = Human('Jack', 24)
y = x
print('Ref x:', id(x), x.name, x.age)
print('Ref y:', id(y), y.name, y.age)
x.name = 'Mark'
x.age = 19
print('Ref x:', id(x), x.name, x.age)
print('Ref y:', id(y), y.name, y.age)


#    Ref x: 140382730160256 Jack 24
#    Ref y: 140382730160256 Jack 24
#    Ref x: 140382730160256 Mark 19
#    Ref y: 140382730160256 Mark 19

from copy import deepcopy

class Human:
    def __init__(self, name, age):
        self.name = name
        self.age = age

x = Human('Jack', 24)
y = deepcopy(x)
print('Ref x:', id(x), x.name, x.age)
print('Ref y:', id(y), y.name, y.age)
x.name = 'Mark'
x.age = 19
print('Ref x:', id(x), x.name, x.age)
print('Ref y:', id(y), y.name, y.age)

#    Ref x: 140227030686064 Jack 24
#    Ref y: 140227031389808 Jack 24
#    Ref x: 140227030686064 Mark 19
#    Ref y: 140227031389808 Jack 24

class Human:
    def __init__(self):
        print('Human created')
    def __del__(self):
        print('Human deleted')
        
x = Human()
del x

#    Human created
#    Human deleted

class Human:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def __del__(self):
        print('Human deleted')
    
x = Human('Jack', 24)
y = Human('Jack', 24)
z = x

print('id of x', id(x))
print('id of y', id(y))
print('id of z', id(z))

print('deleting x')
del x
print('deleting y')
del y
print('deleting z')
del z

#    id of x 140341990262912
#    id of y 140341990262240
#    id of z 140341990262912
#    deleting x
#    deleting y
#    Human deleted
#    deleting z
#    Human deleted
