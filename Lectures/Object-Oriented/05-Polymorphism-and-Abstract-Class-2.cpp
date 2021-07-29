#include <bits/stdc++.h>
using namespace std;

class Shape {
protected:
    int dim1, dim2;
public:
    Shape(int d1=0, int d2=0) {
        cout << "Shape Constructor\n";
        this->dim1 = d1; 
		this->dim2 = d2;
    }
    ~Shape() {
        cout << "Shape Destructor\n";
    }
    virtual float area() = 0;
	virtual void info() {
		cout << "Shape Info: " << this->dim1 << ' ' << this->dim2 << '\n';
	}

    int get_dim1() {return this->dim1;}
    int get_dim2() {return this->dim2;}
    virtual void set_dim1(int d1) {this->dim1 = d1;}
    virtual void set_dim2(int d2) {this->dim2 = d2;}
};

class Rectangle : public Shape {
public:
    Rectangle(int width, int length) : Shape (width, length) {
        cout << "Rectangle Constructor\n";
	}
    ~Rectangle() { 
		cout << "Rectangle Destructor\n";
	}
    float area() {
		return this->dim1*this->dim2;
    }
	void info() {
		cout << "Rectangle Info: " << this->dim1 << ' ' << this->dim2 << '\n';
	}
};

class Square : public Rectangle {
public:
    Square(int side) : Rectangle (side, side) {
        cout << "Square Constructor\n";
	}
    ~Square() { 
		cout << "Square Destructor\n";
	}
	void info() {
		cout << "Square Info: " << this->dim1 << ' ' << this->dim2 << '\n';
	}

    void set_dim1(int d1) {this->dim1 = this->dim2 = d1;}
    void set_dim2(int d2) {this->dim2 = this->dim1 = d2;}
};

class Triangle : public Shape {
public:
    Triangle(int base, int height) : Shape (base, height) {
        cout << "Triangle Constructor\n";
	}
    ~Triangle() {
		cout << "Triangle Destructor\n";
	}
    float area() {
        return 0.5*this->dim1*this->dim2;
    }
	void info() {
		cout << "Triangle Info: " << this->dim1 << ' ' << this->dim2 << '\n';
	}
};

class Circle : public Shape {
public:
    Circle(int radius) : Shape (radius, radius) {
        cout << "Circle Constructor\n";
	}
    ~Circle() { 
		cout << "Circle Destructor\n";
	}
    float area () {
        return 3.14159*this->dim1*this->dim2;
    }
	void info() {
		cout << "Circle Info: " << this->dim1 << ' ' << this->dim2 << '\n';
	}

    void set_dim1(int d1) {this->dim1 = this->dim2 = d1;}
    void set_dim2(int d2) {this->dim2 = this->dim1 = d2;}
};

void display_shape(Shape* x) {
	x->info();
	cout << "Area is : " << x->area() << '\n';
}

int main() {
    Rectangle R(10, 20);
/*
Shape Constructor
Rectangle Constructor
*/
    Square S(20);
/*
Shape Constructor
Rectangle Constructor
Square Constructor
*/
    Triangle T(30, 40);
/*
Shape Constructor
Triangle Constructor
*/
    Circle C(40);
/*
Shape Constructor
Circle Constructor
*/
	
	vector<Shape*> v = {&R, &S, &T, &C};
	for (auto it : v)
		display_shape(it);
/*
Rectangle Info: 10 20
Area is : 200

Square Info: 20 20
Area is : 400

Triangle Info: 30 40
Area is : 600

Circle Info: 40 40
Area is : 5026.54
*/
}
/*
Circle Destructor
Shape Destructor

Triangle Destructor
Shape Destructor

Square Destructor
Rectangle Destructor
Shape Destructor

Rectangle Destructor
Shape Destructor
*/
