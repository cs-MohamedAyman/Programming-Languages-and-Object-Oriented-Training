while True:
    x = int(input("Please enter a number: "))
    print(x, 'squared is', x**2)

while True:
    try:
        x = int(input("Please enter a number: "))
        print(x, 'squared is', x**2)
    except ValueError:
        print("Please enter a valid number!")

while True:
    try:
        x = int(input("Please enter a number: "))
    except ValueError:
        print("Please enter a valid number!")
    else:
        print(x, 'squared is', x**2)

count = 0
while True:
    try:
        x = int(input("Please enter a number: "))
    except ValueError:
        print("Please enter a valid number!")
    else:
        print(x, 'squared is', x**2)
    finally:
        print("Ran %s time(s)" % count)
        count += 1

try:
   # do something
   pass
except ValueError:
   # handle ValueError exception
   pass
except (TypeError, ZeroDivisionError):
   # handle multiple exceptions
   # TypeError and ZeroDivisionError
   pass
except:
   # handle all other exceptions
   pass
'''
BaseException
	Exception
		StandardError
			ArithmeticError
				ZeroDivisionError
			EnvironmentError
				IOError
				OSError
			RuntimeError
			LookupError
				IndexError
				KeyError
			SyntaxError
				IndentationError
'''
