#include <bits/stdc++.h>
using namespace std;

class BaseClass {
};
class DerivedClass : public BaseClass {
};


class Human {
protected:
	string name;
	int age;
public:
	Human(string name, int age) : name(name), age(age) {}
    string display_object() {
        return "name: " + this->name + '\n' +
               "age: " + to_string(this->age) + '\n';
	}
};
class Employee : public Human {
public:
	string department;
	int salary;
public:
    Employee(string name, int age, int salary, string department) 
		: Human(name, age), salary(salary), department(department) {}
    string display_object() {
        return Human::display_object() + 
               "salary: " + to_string(this->salary) + '\n' +
               "department: " + this->department + '\n';
	}
};
int main() {
	Human x("Jack", 24);
	cout << x.display_object() << '\n';

	Employee y("Robert", 26, 4000, "IT");
	cout << y.display_object() << '\n';
}

//	name: Jack
//	age: 24

//	name: Robert
//	age: 26
//	salary: 4000
//	department: IT

class Human {
public:
	string name;
	int age;
public:
	Human(string name, int age) : name(name), age(age) {}
    string display_object() {
        return "name: " + this->name + '\n' +
               "age: " + to_string(this->age) + '\n';
	}
};
class Employee : public Human {
public:
	string department;
	int salary;
public:
    Employee(string name, int age, int salary, string department) 
		: Human(name, age), salary(salary), department(department) {}
    string display_object() {
        return Human::display_object() + 
               "salary: " + to_string(this->salary) + '\n' +
               "department: " + this->department + '\n';
	}
};
int main() {
	Employee x("Robert", 26, 4000, "IT");
	cout << x.name << ' ' << x.age << ' ' << x.salary << ' ' << x.department << '\n';
}

//    Robert 26 4000 IT

class Human {
protected:
	string name;
	int age;
public:
	Human(string name, int age) : name(name), age(age) {}
    string display_object() {
        return "name: " + this->name + '\n' +
               "age: " + to_string(this->age) + '\n';
	}
};
class Employee : public Human {
public:
	string department;
	int salary;
public:
    Employee(string name, int age, int salary, string department) 
		: Human(name, age), salary(salary), department(department) {}
    string display_object() {
        return Human::display_object() + 
               "salary: " + to_string(this->salary) + '\n' +
               "department: " + this->department + '\n';
	}
};
int main() {
	Employee x("Robert", 26, 4000, "IT");
	cout << x.name << ' ' << x.age << ' ' << x.salary << ' ' << x.department << '\n';
}

	error: 'name' is a protected member of 'Human'
			cout << x.name << ' ' << x.age << ' ' << x.salar...
					  ^
	note: declared protected here
			string name;
				   ^
	error: 'age' is a protected member of 'Human'
			cout << x.name << ' ' << x.age << ' ' << x.salar...
									   ^
	note: declared protected here
			int age;


class Human {
private:
	string name;
	int age;
public:
	Human(string name, int age) : name(name), age(age) {}
    string display_object() {
        return "name: " + this->name + '\n' +
               "age: " + to_string(this->age) + '\n';
	}
};
class Employee : public Human {
public:
	string department;
	int salary;
public:
    Employee(string name, int age, int salary, string department) 
		: Human(name, age), salary(salary), department(department) {}
    string display_object() {
        return Human::display_object() + 
               "salary: " + to_string(this->salary) + '\n' +
               "department: " + this->department + '\n';
	}
};
int main() {
	Employee x("Robert", 26, 4000, "IT");
	cout << x.name << ' ' << x.age << ' ' << x.salary << ' ' << x.department << '\n';
}

	error: 'name' is a private member of 'Human'
			cout << x.name << ' ' << x.age << ' ' << x.salar...
					  ^
	note: declared private here
			string name;
				   ^
	error: 'age' is a private member of 'Human'
			cout << x.name << ' ' << x.age << ' ' << x.salar...
									   ^
	note: declared private here
			int age;

class Parent {
protected:
	string parent_name;
public:
	Parent(string name) : parent_name(name) {}
    string get_name() {
        return this->parent_name;
	}
};
class Child : public Parent {
public:
	string child_name;
public:
    Child(string first_name, string last_name) 
		: Parent(last_name), child_name(first_name) {}
    string get_name() {
        return this->child_name + ' ' + this->parent_name;
	}
};
int main() {
	Child x("Mark", "Bill");
	cout << x.get_name() << '\n';
}

//    Mark Bill


class Human {
protected:
	string name;
public:
	Human(string name) : name(name) {}
    string greeting() {
        return "Hi my name is " + this->name + '\n';
	}
};
class Employee : public Human {
public:
	int salary;
public:
    Employee(string name, int salary) 
		: Human(name), salary(salary) {}
};
int main() {
	Employee x("Mark", 10000);
	cout << x.greeting() << '\n';
}

//    Hi my name is Mark


class BaseClass {
};
class DerivedClass : public BaseClass {
};

class BaseClass1 {
};
class BaseClass2 {
};
class MultiDerived : public BaseClass1, public BaseClass2 {
};

class BaseClass {
};
class ChildClass : public BaseClass {
};
class GrandChild : public ChildClass {
};

class BaseClass {
};
class DerivedClass1 : public BaseClass {
};
class DerivedClass2 : public BaseClass {
};
class DerivedClass3 : public BaseClass {
};

class BaseClass {
};
class DerivedClass1 : public BaseClass {
};
class DerivedClass2 : public BaseClass {
};
class MultiDerived : public DerivedClass1, public DerivedClass2 {
};


class Human {
protected:
	string name;
	int age;
public:
	Human(string name, int age) : name(name), age(age) {}
    string display_object() {
        return "name: " + this->name + '\n' +
               "age: " + to_string(this->age) + '\n';
	}
};
class Employee : public Human {
public:
	string department;
	int salary;
public:
    Employee(string name, int age, int salary, string department) 
		: Human(name, age), salary(salary), department(department) {}
    string display_object() {
        return Human::display_object() + 
               "salary: " + to_string(this->salary) + '\n' +
               "department: " + this->department + '\n';
	}
};
int main() {
	Employee x("Alex", 32, 10000, "HR");
	cout << x.display_object() << '\n';
}

//    name: Alex
//    age: 32
//    salary: 10000
//    department: HR


class Father {
protected:
	string father_name;
public:
	Father(string name) : father_name(name) {}
    string display_object() {
        return "name: " + this->father_name + '\n';
	}
};
class Mother {
protected:
	string mother_name;
public:
	Mother(string name) : mother_name(name) {}
    string display_object() {
        return "name: " + this->mother_name + '\n';
	}
};
class Child : public Father, public Mother {
public:
	string name;
public:
    Child(string father_name, string mother_name, string name) 
		: Father(father_name), Mother(mother_name), name(name) {}
    string display_object() {
        return Father::display_object() + 
			   Mother::display_object() + 
               "name: " + this->name + '\n';
	}
};
int main() {
	Child x("bill", "alex", "adam");
	cout << x.display_object() << '\n';
}

//    name: bill
//    name: alex
//    name: adam


class Human {
protected:
	string name;
	int age;
public:
	Human(string name, int age) : name(name), age(age) {}
    string display_object() {
        return "name: " + this->name + '\n' +
               "age: " + to_string(this->age) + '\n';
	}
};
class Employee : public Human {
protected:
	string department;
	int salary;
public:
    Employee(string name, int age, int salary, string department) 
		: Human(name, age), salary(salary), department(department) {}
    string display_object() {
        return Human::display_object() + 
               "salary: " + to_string(this->salary) + '\n' +
               "department: " + this->department + '\n';
	}
};
class Leader : public Employee {
public:
	string reports[3];
public:
    Leader(string name, int age, int salary, 
		   string department, string reports[3]) 
		: Employee(name, age, salary, department) {
        for (int i = 0; i < 3; this->reports[i] = reports[i], i++);
    } 
    string display_object() {
		string str_reports = "reports: ";
		for (int i = 0; i < 3; str_reports += this->reports[i] + " ", i++);
        return Employee::display_object() + 
               str_reports + '\n';
	}
};
int main() {
	string reports[3] = {"R1", "R2", "R3"};
	Leader x("Manuel", 28, 20000, "Research", reports);
	cout << x.display_object() << '\n';
}

//    name: Manuel
//    age: 28
//    salary: 20000
//    department: Research
//    reports: R1, R2, R3


class Room {
public:
	string* name;
	float* area;
public:
	Room(string* name, float* area) : name(name), area(area) {}
    string display_object() {
        return "Room: " +
               ("name: " + *(this->name) + ", " +
                "area: " + to_string(*(this->area)) + '\n');
	}
	~Room() {
		delete name;
		delete area;
        cout << "Room deleted\n";
	}
};
class Salesman {
public:
	string name;
	float salary;
public:
	Salesman(string name, float salary) : name(name), salary(salary) {}
    string display_object() {
        return "Salesman: " +
               ("name: " + this->name + ", " +
                "salary: " + to_string(this->salary) + '\n');
	}
};
class Shop {
public:
	int n_rooms;
	Room** rooms;
	int n_salesmen;
	Salesman** salesmen;
public:
	Shop(Room** rooms, int n_rooms, Salesman** salesmen, int n_salesmen) : 
		rooms(rooms), n_rooms(n_rooms), salesmen(salesmen), n_salesmen(n_salesmen) {}
    string display_object() {
		string res = "";
		for (int i = 0; i < n_rooms; res += this->rooms[i]->display_object(), i++);
		for (int i = 0; i < n_salesmen; res += this->salesmen[i]->display_object(), i++);
		return res;
	}
	~Shop() {
		for (int i = 0; i < n_rooms; delete this->rooms[i], i++);
		delete rooms;
        cout << "Shop deleted\n\n";
	}
};
int main() {
	Room* room1 = new Room(new string("R1"), new float(60));
	Room* room2 = new Room(new string("R2"), new float(100));
	Room* room3 = new Room(new string("R3"), new float(80));
	Room* room4 = new Room(new string("R4"), new float(40));
	Room* room5 = new Room(new string("R5"), new float(70));
	Salesman* salesman1 = new Salesman("Jack", 6000);
	Salesman* salesman2 = new Salesman("Alex", 10000);
	Salesman* salesman3 = new Salesman("Bill", 4000);
	Salesman* salesman4 = new Salesman("Muller", 8000);
	Salesman* salesman5 = new Salesman("Peter", 7000);

	Shop* shop1 = new Shop(new Room*[3]{room1, room2, room3}, 3, 
						   new Salesman*[3]{salesman1, salesman2, salesman3}, 3);
	cout << shop1->display_object() << '\n';

	Shop* shop2 = new Shop(new Room*[2]{room4, room5}, 2, 
						   new Salesman*[2]{salesman4, salesman5}, 2);
	cout << shop2->display_object() << '\n';

	delete shop1;

	Room* room6 = new Room(new string("R6"), new float(80));
	Room* room7 = new Room(new string("R7"), new float(40));
	Room* room8 = new Room(new string("R8"), new float(70));
	Shop* shop3 = new Shop(new Room*[3]{room6, room7, room8}, 3, 
						   new Salesman*[3]{salesman1, salesman2, salesman3}, 3);
	cout << shop3->display_object() << '\n';
}

//    Room: name: R1, area: 60.000000
//    Room: name: R2, area: 100.000000
//    Room: name: R3, area: 80.000000
//    Salesman: name: Jack, salary: 6000.000000
//    Salesman: name: Alex, salary: 10000.000000
//    Salesman: name: Bill, salary: 4000.000000

//    Room: name: R4, area: 40.000000
//    Room: name: R5, area: 70.000000
//    Salesman: name: Muller, salary: 8000.000000
//    Salesman: name: Peter, salary: 7000.000000

//    Room deleted
//    Room deleted
//    Room deleted
//    Shop deleted

//    Room: name: R6, area: 80.000000
//    Room: name: R7, area: 40.000000
//    Room: name: R8, area: 70.000000
//    Salesman: name: Jack, salary: 6000.000000
//    Salesman: name: Alex, salary: 10000.000000
//    Salesman: name: Bill, salary: 4000.000000
