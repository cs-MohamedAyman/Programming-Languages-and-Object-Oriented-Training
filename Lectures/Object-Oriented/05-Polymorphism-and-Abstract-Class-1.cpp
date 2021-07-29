#include <bits/stdc++.h> 
using namespace std;

class Shape {
protected:
	float width, length;
public:
	Shape(float width = 0, float length = 0) : width(width), length(length) {}
	virtual float area() = 0;
	string fact() {
		return "This is a two-dimensional shape.";
	}
};

class Square : public Shape {
public:
	Square(float length = 0) : Shape(length, length) {}
	float area () {
		return length * length;
	}
	string fact() {
        return "Squares have each angle equal to 90 degrees and all sides have an equal length.";
	}
};

class Rectangle : public Shape {
public:
	Rectangle(float width = 0, float length = 0) : Shape(width, length) {}
	float area () {
		return width * length;
	}
	string fact() {
        return "Rectangles have each angle equal to 90 degrees.";
	}
};

class Triangle : public Shape {
public:
	Triangle(float width = 0, float length = 0) : Shape(width, length) {}
	float area () { 
		return width * length / 2.0;
	}
	string fact() {
        return "Triangles have three sides.";
	}
};

void display_shape_details(Shape* x) {
    cout << "This shape has area " << x->area() << '\n';
    cout << "and the shape fact is " << x->fact() << '\n';
    cout << "------------------------------------------\n";
}

int main() {
   Shape *sh;
   Rectangle a(10, 7);
   Triangle  b(10, 5);
   Square 	 c(6);
   Shape 	 d(6, 8);

   sh = &a;
   display_shape_details(sh);
   sh = &b;
   display_shape_details(sh);
   sh = &c;
   display_shape_details(sh);
   sh = &d;
   display_shape_details(sh);
}
/*
This shape has area 70
and the shape fact is Rectangles have each angle equal to 90 degrees.
------------------------------------------
This shape has area 25
and the shape fact is Triangles have three sides.
------------------------------------------
This shape has area 36
and the shape fact is Squares have each angle equal to 90 degrees and all sides have an equal length.
------------------------------------------
This shape has area 0
and the shape fact is This is a two-dimensional shape.
------------------------------------------
*/
