#include <bits/stdc++.h>
using namespace std;

class Human {

};

int main() {
    Human x, y;
}

class Human {
public:
	string name;
	int age;
	string gender;
};
int main() {
    Human x;
	x.name = "Jack";
	x.age = 24;
	x.gender = "male";
	cout << x.name << ' ' << x.age << ' ' << x.gender << '\n';
}

//    Jack 24 male

class Human {
public:
    void walking() {
        cout << "I am walking now\n";
	}
    void running() {
        cout << "I am running now\n";
	}
};
int main() {
    Human x;
	x.walking();
	x.running();
}

//    I am walking now
//    I am running now

class Human {
public:
	string name;
	int age;
	string gender;
	
	Human() {
		name = "";
		age = 0;
		gender = "";
	}
};
int main() {
    Human x;
	cout << x.name << ' ' << x.age << ' ' << x.gender << '\n';
}

class Human {
public:
	string name;
	int age;
	string gender;

	Human(string a, int b, string c) {
		name = a;
		age = b;
		gender = c;
	}
};
int main() {
    Human x("Jack", 24, "male");
	cout << x.name << ' ' << x.age << ' ' << x.gender << '\n';
}

//    Jack 24 male

class Human {
public:
	string name;
	int age;
	string gender;

	Human(string name, int age, string gender) {
		this->name = name;
		this->age = age;
		this->gender = gender;
	}
};
int main() {
    Human x("Jack", 24, "male");
	cout << x.name << ' ' << x.age << ' ' << x.gender << '\n';
}

//    Jack 24 male

class Human {
public:
	string name;
	int age;

	Human(string name, int age) {
		this->name = name;
		this->age = age;
	}
	Human(const Human &obj) {
		this->name = obj.name;
		this->age = obj.age;
	}
};
int main() {
    Human x("Jack", 24);
	Human y(x);
  	cout << "Ref x: " << &x << ' ';
    cout << x.name << ' ' << x.age << '\n';
	cout << "Ref y: " << &y << ' ';
    cout << y.name << ' ' << y.age << '\n';
    x.name = "Mark";
    x.age = 19;
  	cout << "Ref x: " << &x << ' ';
    cout << x.name << ' ' << x.age << '\n';
	cout << "Ref y: " << &y << ' ';
    cout << y.name << ' ' << y.age << '\n';
}

//    Ref x: 0x7ffd647a8fe8 Jack 24
//    Ref y: 0x7ffd647a8f88 Jack 24
//    Ref x: 0x7ffd647a8fe8 Mark 19
//    Ref y: 0x7ffd647a8f88 Jack 24

class Human {
public:
	string name;
	int age;

	Human(string name, int age) {
		this->name = name;
		this->age = age;
	}
};
int main() {
    Human x("Jack", 24);
	Human &y = x;
  	cout << "Ref x: " << &x << ' ';
    cout << x.name << ' ' << x.age << '\n';
	cout << "Ref y: " << &y << ' ';
    cout << y.name << ' ' << y.age << '\n';
    x.name = "Mark";
    x.age = 19;
  	cout << "Ref x: " << &x << ' ';
    cout << x.name << ' ' << x.age << '\n';
	cout << "Ref y: " << &y << ' ';
    cout << y.name << ' ' << y.age << '\n';
}

//    Ref x: 0x7ffd9d1dea28 Jack 24
//    Ref y: 0x7ffd9d1dea28 Jack 24
//    Ref x: 0x7ffd9d1dea28 Mark 19
//    Ref y: 0x7ffd9d1dea28 Mark 19

class Human {
public:
    Human() {
        cout << "Human created\n";
	}
    ~Human() {
        cout << "Human deleted\n";
	}
};
int main() {
    Human *x = new Human();
	delete x;
}

//    Human created
//    Human deleted

class Human {
public:
	string name;
	int age;

	Human(string name, int age) {
		this->name = name;
		this->age = age;
	}
    ~Human() {
        cout << "Human deleted\n";
	}
};
int main() {
    Human *x = new Human("Jack", 24);
    Human *y = new Human("Jack", 24);
	Human* &z = x;

	cout << "ref of x " << &x << '\n';
	cout << "ref of y " << &y << '\n';
	cout << "ref of z " << &z << '\n';

	cout << "deleting x\n";
	delete x;
	cout << "deleting y\n";
	delete y;
	cout << "deleting z\n";
	delete z;
}

//    ref of x 0x7ffd73192510
//    ref of y 0x7ffd731924a0
//    ref of z 0x7ffd73192510
//    deleting x
//    Human deleted
//    deleting y
//    Human deleted
//    deleting z
//    Human deleted
