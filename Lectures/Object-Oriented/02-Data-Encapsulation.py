class Human:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def get_name(self):
        return self.name
    def set_name(self, name):
        self.name = name
    def get_age(self):
        return self.age
    def set_age(self, age):
        self.age = age
    
x = Human('Jack', 24)
print(x.get_name(), x.get_age())
x.set_name('Muller')
x.set_age(27)
print(x.get_name(), x.get_age())

#    Jack 24
#    Muller 27

class Human:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def get_name(self):
        return self.name
    def set_name(self, name):
        self.name = name
    def get_age(self):
        return self.age
    def set_age(self, age):
        if age < 0:
            return
        self.age = age
    
x = Human('Jack', 24)
print(x.get_name(), x.get_age())
x.set_name('Muller')
x.set_age(-27)
print(x.get_name(), x.get_age())

#    Jack 24
#    Muller 24

class Human:
    def __init__(self, name, age):
        self.__name = name
        self.__age = age
    def get_name(self):
        return self.__name
    def set_name(self, name):
        self.__name = name
    def get_age(self):
        return self.__age
    def set_age(self, age):
        self.__age = age

x = Human('Jack', 24)
print(x.get_name(), x.get_age())
print(x.__name, x.__age)

#    Jack 24
'''
Traceback (most recent call last):
  File "main.py", line 16, in <module>
    print(x.__name, x.__age)
AttributeError: 'Human' object has no attribute '__name'
Traceback (most recent call last):
  File "main.py", line 16, in <module>
    print(x.__name, x.__age)
AttributeError: 'Human' object has no attribute '__age'
'''

class Human:
    def __init__(self):
        self.__name = ''
    def __set_full_name(self, full_name):
        self.__name = full_name
    def set_name(self, first_name, last_name):
        self.__set_full_name(first_name + ' ' + last_name)
    def get_name(self):
        return self.__name

x = Human()
x.set_name('Jack', 'Muller')
print(x.get_name())
x.__set_full_name('Mark Bill')
print(x.get_name())

#    Jack Muller
'''
Traceback (most recent call last):
  File "main.py", line 14, in <module>
    x.__set_full_name('Mark', 'Bill')
AttributeError: 'Human' object has no attribute '__set_full_name'
'''

class Employee:
	def __init__(self):
		self.__salary = 0
	def __get_net_salary(self):
		return self.salary * 0.85
	def set_salary(self, salary):
		self.salary = salary
	def get_salary(self):
		return self.__get_net_salary()

x = Employee()
x.set_salary(1000)
print(x.get_salary())
print(x.__get_net_salary())

#    850.0
'''
Traceback (most recent call last):
  File "main.py", line 14, in <module>
    print(x.__get_net_salary())
AttributeError: 'Employee' object has no attribute '__get_net_salary'
'''

class Employee:
    raise_amount = 0.15
    def __init__(self, first_name, last_name):
        self.first_name = first_name
        self.last_name = last_name

x = Employee('Jack', 'Bill')
y = Employee('Mark', 'Peter')

print(x.first_name, x.last_name, x.raise_amount)
print(y.first_name, y.last_name, y.raise_amount)
Employee.raise_amount = 0.13
print(x.first_name, x.last_name, x.raise_amount)
print(y.first_name, y.last_name, y.raise_amount)

#    Jack Bill 0.15
#    Mark Peter 0.15
#    Jack Bill 0.13
#    Mark Peter 0.13

class Employee:
    company_name = 'yahoo'
    def __init__(self, first_name, last_name):
        self.first_name = first_name
        self.last_name = last_name
    def generate_email(self):
        return self.first_name + '_' + self.last_name + \
               '@' + Employee.company_name + '.com'

x = Employee('Jack', 'Bill')
y = Employee('Mark', 'Peter')

print(x.generate_email())
print(y.generate_email())
Employee.company_name = 'google'
print(x.generate_email())
print(y.generate_email())

#    Jack_Bill@yahoo.com
#    Mark_Peter@yahoo.com
#    Jack_Bill@google.com
#    Mark_Peter@google.com

class Employee:
    @staticmethod
    def combine_name(first_name, last_name):
        return first_name + ' ' + last_name
    @staticmethod
    def calc_net_salary(salary):
        return salary * 0.85
    def __init__(self, first_name, last_name, salary):
        self.name = Employee.combine_name(first_name, last_name)
        self.salary = Employee.calc_net_salary(salary)

x = Employee('Jack', 'Bill', 10000)
print(x.name, x.salary)

#    Jack Bill 8500.0

class Employee:
    company_name = 'amazon'
    @staticmethod
    def combine_name(first_name, last_name):
        return first_name + '_' + last_name
    @staticmethod
    def calc_net_salary(salary):
        return salary * 0.85
    @staticmethod
    def generate_email(first_name, last_name):
        return Employee.combine_name(first_name, last_name) + \
               '@' + Employee.company_name + '.com'
    def __init__(self, first_name, last_name, salary):
        self.salary = Employee.calc_net_salary(salary)
        self.email = Employee.generate_email(first_name, last_name)

x = Employee('Jack', 'Bill', 10000)
print(x.email, x.salary)

#    Jack_Bill@amazon.com 8500.0

class Employee:
    '''This is a sample class called Employee'''
    def __init__(self, first_name = '', last_name = ''):
        self.first_name = first_name
        self.last_name = last_name
    def get_first_name(self):
        return self.first_name
    def set_first_name(self, first_name):
        self.first_name = first_name
    def get_last_name(self):
        return self.last_name
    def set_last_name(self, last_name):
        self.last_name = last_name
    def __del__(self):
        del self.first_name
        del self.last_name

x = Employee('Peter', 'Jack')
print(x.__dict__)
print(x.__doc__)
print(Employee.__doc__)
print(Employee.__name__)
print(x.__module__)
print(Employee.__module__)

#    {'first_name': 'Peter', 'last_name': 'Jack'}
#    This is a sample class called Employee
#    This is a sample class called Employee
#    Employee
#    __main__
#    __main__

x = Employee('Bill', 'Jack')
print(hasattr(x, 'first_name'))
print(hasattr(x, 'last_name'))
print(getattr(x, 'first_name'))
print(getattr(x, 'last_name'))
setattr(x, 'first_name', 'Mark')
setattr(x, 'last_name', 'Mark')
print(getattr(x, 'first_name'))
print(getattr(x, 'last_name'))
delattr(x, 'first_name')
delattr(x, 'last_name')
print(hasattr(x, 'first_name'))
print(hasattr(x, 'last_name'))

#    True
#    True
#    Bill
#    Jack
#    Mark
#    Mark
#    False
#    False
