import csv

x = [[1.3, 2, 3, 4, 5],
     [2, 6, 7, 3, 1.5],
     [3, 9, 2.2, 7, 4]]

f = open('data.csv', 'w')
w = csv.writer(f)
w.writerows(x)
f.close()

f = open('data.csv', 'r')
r = csv.reader(f)
print(list(r))
f.close()

#[['1.3', '2', '3', '4', '5'], [], ['2', '6', '7', '3', '1.5'], [], ['3', '9', '2.2', '7', '4'], []]

f = open('data.csv', 'w')
x = ['column_A', 'column_B', 'column_C']
w = csv.DictWriter(f, fieldnames = x)
w.writeheader()
w.writerow({'column_A': 7, 'column_B': 'Paris', 'column_C': 1.2})
w.writerow({'column_A': 8, 'column_B': 'Rome', 'column_C': 6.3})
w.writerow({'column_C': -8.4, 'column_A': 5, 'column_B': 'Madrid'})
w.writerow({'column_B': 'Moscow', 'column_C': 11.3, 'column_A': -3})
f.close()

f = open('data.csv')
r = csv.DictReader(f)
for i in r:
    print(i['column_A'], i['column_B'], i['column_C'])
f.close()

'''
7 Paris 1.2
8 Rome 6.3
5 Madrid -8.4
-3 Moscow 11.3
'''
