class BaseClass:
    pass
class DerivedClass(BaseClass):
    pass


class Human:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def __str__(self):
        return 'name: ' + self.name + '\n' + \
               'age: ' + str(self.age) + '\n'

class Employee(Human):
    def __init__(self, name, age, salary, department):
        Human.__init__(self, name, age)
        self.salary = salary
        self.department = department
    def __str__(self):
        return Human.__str__(self) + \
               'salary: ' + str(self.salary) + '\n' + \
               'department: ' + self.department + '\n'

x = Human('Jack', 24)
print(x)

y = Employee('Robert', 26, 4000, 'IT')
print(y)

#    name: Jack
#    age: 24

#    name: Robert
#    age: 26
#    salary: 4000
#    department: IT


class Human:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def __str__(self):
        return 'name: ' + self.name + '\n' + \
               'age: ' + str(self.age) + '\n'

class Employee(Human):
    def __init__(self, name, age, salary, department):
        super().__init__(name, age)
        self.salary = salary
        self.department = department
    def __str__(self):
        return super().__str__() + \
               'salary: ' + str(self.salary) + '\n' + \
               'department: ' + self.department + '\n'

x = Human('Jack', 24)
print(x)

y = Employee('Robert', 26, 4000, 'IT')
print(y)

#   name: Jack
#   age: 24

#   name: Robert
#   age: 26
#   salary: 4000
#   department: IT


class Human:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def __str__(self):
        return 'name: ' + self.name + '\n' + \
               'age: ' + str(self.age) + '\n'

class Employee(Human):
    def __init__(self, name, age, salary, department):
        super().__init__(name, age)
        self.salary = salary
        self.department = department
    def __str__(self):
        return super().__str__() + \
               'salary: ' + str(self.salary) + '\n' + \
               'department: ' + self.department + '\n'

x = Employee('Robert', 26, 4000, 'IT')
print(x.name, x.age, x.salary, x.department)

#    Robert 26 4000 IT


class Human:
    def __init__(self, name, age):
        self._name = name
        self._age = age
    def __str__(self):
        return 'name: ' + self.name + '\n' + \
               'age: ' + str(self.age) + '\n'

class Employee(Human):
    def __init__(self, name, age, salary, department):
        super().__init__(name, age)
        self.salary = salary
        self.department = department
    def __str__(self):
        return super().__str__() + \
               'salary: ' + str(self.salary) + '\n' + \
               'department: ' + self.department + '\n'

x = Employee('Robert', 26, 4000, 'IT')
print(x._name, x._age, x.salary, x.department)

#    Robert 26 4000 IT


class Human:
    def __init__(self, name, age):
        self.__name = name
        self.__age = age
    def __str__(self):
        return 'name: ' + self.name + '\n' + \
               'age: ' + str(self.age) + '\n'

class Employee(Human):
    def __init__(self, name, age, salary, department):
        super().__init__(name, age)
        self.salary = salary
        self.department = department
    def __str__(self):
        return super().__str__() + \
               'salary: ' + str(self.salary) + '\n' + \
               'department: ' + self.department + '\n'

x = Employee('Robert', 26, 4000, 'IT')
print(x.__name, x.__age, x.salary, x.department)

    Traceback (most recent call last):
      File "main.py", line 20, in <module>
        print(x.__name, x.__age, x.salary, x.department)
    AttributeError: 'Employee' object has no attribute '__name'

    Traceback (most recent call last):
      File "main.py", line 20, in <module>
        print(x.__age, x.salary, x.department)
    AttributeError: 'Employee' object has no attribute '__age'


class Parent:
    def __init__(self, name):
        self.parent_name = name
    def get_name(self):
        return self.parent_name

class Child(Parent):
    def __init__(self, first_name, last_name):
        super().__init__(last_name)
        self.child_name = first_name
    def get_name(self):
        return self.child_name + ' ' + self.parent_name

x = Child('Mark', 'Bill')
print(x.get_name())

#    Mark Bill


class Human:
    def __init__(self, name):
        self.name = name
    def greeting(self):
        return 'Hi my name is ' + self.name + '\n'

class Employee(Human):
    def __init__(self, name, salary):
        super().__init__(name)
        self.salary = salary

x = Employee('Mark', 10000)
print(x.greeting())

#    Hi my name is Mark


class BaseClass:
    pass
class DerivedClass(BaseClass):
    pass

class BaseClass1:
    pass
class BaseClass2:
    pass
class MultiDerived(BaseClass1, BaseClass2): 
    pass

class BaseClass:
    pass
class ChildClass(BaseClass):
    pass
class GrandChild(ChildClass):
    pass

class BaseClass:
    pass
class DerivedClass1(BaseClass):
    pass
class DerivedClass2(BaseClass):
    pass
class DerivedClass3(BaseClass):
    pass

class BaseClass:
    pass
class DerivedClass1(BaseClass):
    pass
class DerivedClass2(BaseClass):
    pass
class MultiDerived(DerivedClass1, DerivedClass2): 
    pass


class Human:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def __str__(self):
        return 'name: ' + self.name + '\n' + \
               'age: ' + str(self.age) + '\n'

class Employee(Human):
    def __init__(self, name, age, salary, department):
        Human.__init__(self, name, age)
        self.salary = salary
        self.department = department
    def __str__(self):
        return Human.__str__(self) + \
               'salary: ' + str(self.salary) + '\n' + \
               'department: ' + self.department + '\n'

x = Employee('Alex', 32, 10000, 'HR')
print(x)

#    name: Alex
#    age: 32
#    salary: 10000
#    department: HR


class Father:
    def __init__(self, name):
        self.father_name = name
    def __str__(self):
        return 'name: ' + self.father_name + '\n'

class Mother:
    def __init__(self, name):
        self.mother_name = name
    def __str__(self):
        return 'name: ' + self.mother_name + '\n'

class Child(Father, Mother):
    def __init__(self, father_name, mother_name, name):
        Father.__init__(self, father_name)
        Mother.__init__(self, mother_name)
        self.name = name
    def __str__(self):
        return Father.__str__(self) + \
               Mother.__str__(self) + \
               'name: ' + self.name + '\n'

x = Child('bill', 'alex', 'adam')
print(x)

#    name: bill
#    name: alex
#    name: adam


class Human:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def __str__(self):
        return 'name: ' + self.name + '\n' + \
               'age: ' + str(self.age) + '\n'

class Employee(Human):
    def __init__(self, name, age, salary, department):
        Human.__init__(self, name, age)
        self.salary = salary
        self.department = department
    def __str__(self):
        return Human.__str__(self) + \
               'salary: ' + str(self.salary) + '\n' + \
               'department: ' + self.department + '\n'

class Leader(Employee):
    def __init__(self, name, age, salary, department, reports):
        Employee.__init__(self, name, age, salary, department)
        self.reports = reports
    def __str__(self):
        return Employee.__str__(self) + \
               'reports: ' + str(self.reports) + '\n' 

x = Leader('Manuel', 28, 20000, 'Research', ['R1', 'R2', 'R3'])
print(x)

#    name: Manuel
#    age: 28
#    salary: 20000
#    department: Research
#    reports: ['R1', 'R2', 'R3']


class Room:
    def __init__(self, name, area):
        self.name = name
        self.area = area
    def __str__(self):
        return 'Room: ' + \
               'name: ' + self.name + ', ' + \
               'area: ' + str(self.area) + '\n'
    def __del__(self):
        del self.name
        del self.area
        print('Room deleted')

class Salesman:
    def __init__(self, name, salary):
        self.name = name
        self.salary = salary
    def __str__(self):
        return 'Salesman: ' + \
               'name: ' + self.name + ', ' + \
               'salary: ' + str(self.salary) + '\n'

class Shop:
    def __init__(self, rooms, salesmen):
        self.rooms = rooms
        self.salesmen = salesmen
    def __str__(self):
        res = ''
        for i in self.rooms: res += str(i)
        for i in self.salesmen: res += str(i)
        return res
    def __del__(self):
        for i in self.rooms: 
            Room.__del__(i)
        del self.rooms
        print('Shop deleted\n')
        

room1 = Room('R1', 60)
room2 = Room('R2', 100)
room3 = Room('R3', 80)
room4 = Room('R4', 40)
room5 = Room('R5', 70)
salesman1 = Salesman('Jack', 6000)
salesman2 = Salesman('Alex', 10000)
salesman3 = Salesman('Bill', 4000)
salesman4 = Salesman('Muller', 8000)
salesman5 = Salesman('Peter', 7000)

shop1_rooms = [room1, room2, room3]
shop1_salesmen = [salesman1, salesman2, salesman3]
shop1 = Shop(shop1_rooms, shop1_salesmen)
print(shop1)

shop2_rooms = [room4, room5]
shop2_salesmen = [salesman4, salesman5]
shop2 = Shop(shop2_rooms, shop2_salesmen)
print(shop2)

del shop1

room6 = Room('R6', 80)
room7 = Room('R7', 40)
room8 = Room('R8', 70)
shop3_rooms = [room6, room7, room8]
shop3_salesmen = [salesman1, salesman2, salesman3]
shop3 = Shop(shop3_rooms, shop3_salesmen)
print(shop3)

#    Room: name: R1, area: 60
#    Room: name: R2, area: 100
#    Room: name: R3, area: 80
#    Salesman: name: Jack, salary: 6000
#    Salesman: name: Alex, salary: 10000
#    Salesman: name: Bill, salary: 4000

#    Room: name: R4, area: 40
#    Room: name: R5, area: 70
#    Salesman: name: Muller, salary: 8000
#    Salesman: name: Peter, salary: 7000

#    Room deleted
#    Room deleted
#    Room deleted
#    Shop deleted

#    Room: name: R6, area: 80
#    Room: name: R7, area: 40
#    Room: name: R8, area: 70
#    Salesman: name: Jack, salary: 6000
#    Salesman: name: Alex, salary: 10000
#    Salesman: name: Bill, salary: 4000
