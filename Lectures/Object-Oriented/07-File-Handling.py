f = open('data.txt','w') 
f.write("Pug\n")
f.write("Jack Russell Terrier\n") 
f.write("English Springer Spaniel\n") 
f.write("German Shepherd\n") 
f.write("Staffordshire Bull Terrier\n") 
f.write("Cavalier King Charles Spaniel\n") 
f.write("Golden Retriever\n") 
f.write("West Highland White Terrier\n") 
f.write("Boxer\n") 
f.write("Border Terrier\n") 
f.close() 


f = open("data.txt", "r")  
x = f.read()
f.close()
print(x)

'''
Pug
Jack Russell Terrier
English Springer Spaniel
German Shepherd
Staffordshire Bull Terrier
Cavalier King Charles Spaniel
Golden Retriever
West Highland White Terrier
Boxer
Border Terrier
'''

lines = x.split('\n')
print(lines)

'''
['Pug', 'Jack Russell Terrier', 'English Springer Spaniel', 'German Shepherd', 
 'Staffordshire Bull Terrier', 'Cavalier King Charles Spaniel', 'Golden Retriever', 
 'West Highland White Terrier', 'Boxer', 'Border Terrier', '']
'''

f = open('data.txt','w') 
f.write("This is the write command, ") 
f.write("It allows us to write in a particular file\n") 
f.close()

f = open("data.txt", "r")  
x = f.read()
f.close()
print(x)

#This is the write command, It allows us to write in a particular file

lines = x.split('\n')
print(lines)

#['This is the write command, It allows us to write in a particular file', '']

s = '''Pug
Jack Russell Terrier
English Springer Spaniel
German Shepherd
Staffordshire Bull Terrier
Cavalier King Charles Spaniel
Golden Retriever
West Highland White Terrier
Boxer
Border Terrier
'''

f = open('data.txt','a') 
f.write(s)
f.close() 

f = open("data.txt", "r")  
print(f.read())
f.close() 

'''
This is the write command, It allows us to write in a particular file
Pug
Jack Russell Terrier
English Springer Spaniel
German Shepherd
Staffordshire Bull Terrier
Cavalier King Charles Spaniel
Golden Retriever
West Highland White Terrier
Boxer
Border Terrier
'''
