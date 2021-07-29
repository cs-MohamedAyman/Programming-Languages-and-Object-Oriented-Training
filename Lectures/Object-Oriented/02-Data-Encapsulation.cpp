#include <bits/stdc++.h>
using namespace std;

class Human {
public:
	string name;
	int age;

	Human(string name, int age) {
		this->name = name;
		this->age = age;
	}
	string get_name() {
		return this->name;
	}
	void set_name(string name) {
		this->name = name;
	}
	int get_age() {
		return this->age;
	}
	void set_age(int age) {
		this->age = age;
	}
};
int main() {
    Human x("Jack", 24);
	cout << x.get_name() << ' ' << x.get_age() << '\n';
	x.set_name("Muller");
	x.set_age(27);
	cout << x.get_name() << ' ' << x.get_age() << '\n';
}

//    Jack 24
//    Muller 27


class Human {
public:
	string name;
	int age;

	Human(string name, int age) {
		this->name = name;
		this->age = age;
	}
	string get_name() {
		return this->name;
	}
	void set_name(string name) {
		this->name = name;
	}
	int get_age() {
		return this->age;
	}
	void set_age(int age) {
		if (age < 0)
			return;
		this->age = age;
	}
};
int main() {
    Human x("Jack", 24);
	cout << x.get_name() << ' ' << x.get_age() << '\n';
	x.set_name("Muller");
	x.set_age(-27);
	cout << x.get_name() << ' ' << x.get_age() << '\n';
}

//    Jack 24
//    Muller 24


class Human {
private:
	string name;
	int age;
public:
	Human(string name, int age) {
		this->name = name;
		this->age = age;
	}
	string get_name() {
		return this->name;
	}
	void set_name(string name) {
		this->name = name;
	}
	int get_age() {
		return this->age;
	}
	void set_age(int age) {
		this->age = age;
	}
};
int main() {
    Human x("Jack", 24);
	cout << x.get_name() << ' ' << x.get_age() << '\n';
	cout << x.name << ' ' << x.age << '\n';
}

//    Jack 24
/*
error: 'name' is a private member of 'Human'
cout << x.name << ' ' << x.age << '\n';
          ^
note: declared private here
string name;
       ^
error: 'age' is a private member of 'Human'
cout << x.name << ' ' << x.age << '\n';
                           ^
note: declared private here
int age;
*/

class Human {
private:
	string name;
	int age;
public:
	Human(string name, int age) {
		this->name = name;
		this->age = age;
	}
	int get_age() {
		return this->age;
	}
    friend string display_name(Human);
    friend void increment_age(Human&, int);
};
string display_name(Human y) {
    return y.name;
}
void increment_age(Human &y, int n) {
    y.age += n;
}
int main() {
    Human x("Jack", 24);
	cout << display_name(x) << ' ' << x.get_age() << '\n';
    increment_age(x, 10);
	cout << display_name(x) << ' ' << x.get_age() << '\n';
}

//    Jack 24
//    Jack 34

class Mother;
class Father;

class Mother {
private:
    string name;
    int age;
    friend void display_parents(Mother, Father);
public:
    Mother(string name, int age) : name(name), age(age) {}
};
class Father {
private:
    string name;
    int age;
    friend void display_parents(Mother, Father);
public:
    Father(string name, int age) : name(name), age(age) {}
};
void display_parents(Mother x, Father y) {
    cout << x.name << " " << y.name << '\n';
    cout << x.age << "   " << y.age << '\n';
}
int main() {
    Mother x("Mary", 29);
    Father y("Adam", 30);
    display_parents(x, y);
}

//    Mary Adam
//    29   30

class Human {
private:
	string name;
	void set_full_name(string full_name) {
		this->name = full_name;
	}
public:
	Human() {
		this->name = "";
	}
	void set_name(string first_name, string last_name) {
		set_full_name(first_name + " " + last_name);
	}
	string get_name() {
		return this->name;
	}
};
int main() {
    Human x;
	x.set_name("Jack", "Muller");
	cout << x.get_name() << '\n';
	x.set_full_name("Mark Bill");
	cout << x.get_name() << '\n';
}

//    Jack Muller
/*
error: 'set_full_name' is a private member of 'Human'
x.set_full_name("Mark Bill");
  ^
note: declared private here
void set_full_name(string full_name) {
*/

class Employee {
private:
	float salary;
	float get_net_salary() {
		return this->salary * 0.85;
	}
public:
	Employee() {
		this->salary = 0;
	}
	void set_salary(float salary) {
		this->salary = salary;
	}
	float get_salary() {
		return get_net_salary();
	}
};
int main() {
    Employee x;
	x.set_salary(1000);
	cout << x.get_salary() << '\n';
	cout << x.get_net_salary() << '\n';
}

//    850
/*
error: 'get_net_salary' is a private member of
      'Employee'
        cout << x.get_net_salary() << '\n';
                  ^
note: declared private here
        float get_net_salary() {
*/

class Employee {
public:
    static float raise_amount;
    string first_name;
    string last_name;
    Employee(string first_name, string last_name) {
        this->first_name = first_name;
        this->last_name = last_name;
	}
    void update_raise_amount(float raise_amount) {
        this->raise_amount = raise_amount;
    }
};

float Employee::raise_amount = 0.15;

int main() {
	Employee x("Jack", "Bill");
	Employee y("Mark", "Peter");

	cout << x.first_name << ' ' << x.last_name << ' ' 
		 << x.raise_amount << '\n';
	cout << y.first_name << ' ' << y.last_name << ' ' 
		 << y.raise_amount << '\n';
    x.update_raise_amount(0.13);
	cout << x.first_name << ' ' << x.last_name << ' ' 
		 << x.raise_amount << '\n';
	cout << y.first_name << ' ' << y.last_name << ' ' 
		 << y.raise_amount << '\n';
}

//    Jack Bill 0.15
//    Mark Peter 0.15
//    Jack Bill 0.13
//    Mark Peter 0.13

class Employee {
public:
    static string company_name;
    string first_name;
    string last_name;
    Employee(string first_name, string last_name) {
        this->first_name = first_name;
        this->last_name = last_name;
	}
    string generate_email() {
        return this->first_name + "_" + this->last_name +
               "@" + company_name + ".com";
	}
    void update_company_name(string company_name) {
        this->company_name = company_name;
    }
};

string Employee::company_name = "google";

int main() {
	Employee x("Jack", "Bill");
	Employee y("Mark", "Peter");

	cout << x.generate_email() << '\n';
	cout << y.generate_email() << '\n';
    x.update_company_name("yahoo");
	cout << x.generate_email() << '\n';
	cout << y.generate_email() << '\n';
}

//    Jack_Bill@google.com
//    Mark_Peter@google.com
//    Jack_Bill@yahoo.com
//    Mark_Peter@yahoo.com

class Employee {
public:
	string name;
	float salary;
	
    static string combine_name(string first_name, string last_name) {
        return first_name + " " + last_name;
	}
    static float calc_net_salary(float salary) {
        return salary * 0.85;
	}
    Employee(string first_name, string last_name, float salary) {
        this->name = combine_name(first_name, last_name);
        this->salary = calc_net_salary(salary);
	}
};
int main() {
	Employee x("Jack", "Bill", 10000);
	cout << x.name << ' ' << x.salary << '\n';
}

//    Jack Bill 8500

class Employee {
public:
    static string company_name;
    string email;
    float salary;
    
	static string combine_name(string first_name, string last_name) {
        return first_name + "_" + last_name;
	}
    static float calc_net_salary(float salary) {
        return salary * 0.85;
	}
    static string generate_email(string first_name, string last_name) {
        return combine_name(first_name, last_name) + 
               "@" + company_name + ".com";
	}
    Employee(string first_name, string last_name, float salary) {
        this->salary = calc_net_salary(salary);
        this->email = generate_email(first_name, last_name);
   }
};

string Employee::company_name = "amazon";

int main() {
	Employee x("Jack", "Bill", 10000);
	cout << x.email << ' ' << x.salary << '\n';
}

//    Jack_Bill@amazon.com 8500

class Human {
private:
	string name;
	int age;
public:
	Human(string name, int age);
	string get_name();
	void set_name(string name);
	int get_age();
	void set_age(int age);
};
Human::Human(string name, int age) {
	this->name = name;
	this->age = age;
}
string Human::get_name() {
	return this->name;
}
void Human::set_name(string name) {
	this->name = name;
}
int Human::get_age() {
	return this->age;
}
void Human::set_age(int age) {
	this->age = age;
}
int main() {
    Human x("Jack", 24);
	cout << x.get_name() << ' ' << x.get_age() << '\n';
}

//    Jack 24
