#include <bits/stdc++.h>
using namespace std;

class Point {
public:
    int x, y, z;
	Point(int x=0, int y=0, int z=0) : x(x), y(y), z(z) {}
    friend ostream& operator<<(ostream &output, Point &p) { 
        output << "Point(" << p.x << ", " << p.y << ", " << p.z << ")";
        return output;
    }
    friend istream& operator>>(istream  &input, Point &p) { 
        input >> p.x >> p.y >> p.z;
        return input;            
    }
};
int main() {
    Point p1;
	Point p2(2, 3, 1);
	cout << p1 << ' ' << p2 << '\n';
    cin >> p1 >> p2;
	cout << p1 << ' ' << p2 << '\n';
}

/*
Point(0, 0, 0) Point(2, 3, 1)
1 6 4
7 2 3 
Point(1, 6, 4) Point(7, 2, 3)
*/

class Point {
public:
    int x, y, z;
	Point(int x=0, int y=0, int z=0) : x(x), y(y), z(z) {}
    friend ostream& operator<<(ostream &output, Point &p) { 
        output << "Point(" << p.x << ", " << p.y << ", " << p.z << ")";
        return output;
    }
    void operator++() {
        ++this->x, ++this->y, ++this->z;
    }
    void operator++(int) {
        this->x++, this->y++, this->z++;
    }
    void operator--() {
        --this->x, --this->y, --this->z;
    }
    void operator--(int) {
        this->x--, this->y--, this->z--;
    }
    Point operator+(Point obj) {
        Point p(this->x+obj.x, this->y+obj.y, this->z+obj.z);
        return p;
    }
    Point operator-(Point obj) {
        Point p(this->x-obj.x, this->y-obj.y, this->z-obj.z);
        return p;
    }
    Point operator*(int scalar) {
        Point p(this->x*scalar, this->y*scalar, this->z*scalar);
        return p;
    }
    Point operator/(int scalar) {
        Point p(this->x/scalar, this->y/scalar, this->z/scalar);
        return p;
    }
    Point operator%(int scalar) {
        Point p(this->x%scalar, this->y%scalar, this->z%scalar);
        return p;
    }
};
int main() {
	Point p1;
	Point p2(2, 3, 1);
	cout << p1 << ' ' << p2 << '\n';
	p1 = p1 + p2;
	cout << p1 << ' ' << p2 << '\n';
	p2 = p2 + p1;
	cout << p1 << ' ' << p2 << '\n';
	p1++;
	p2++;
	cout << p1 << ' ' << p2 << '\n';
	++p1;
	++p2;
	cout << p1 << ' ' << p2 << '\n';
	p1 = p1 * 4;
	p2 = p2 * 4;
	cout << p1 << ' ' << p2 << '\n';
	p1 = p1 / 2;
	p2 = p2 / 2;
	cout << p1 << ' ' << p2 << '\n';
	p1 = p1 % 5;
	p2 = p2 % 5;
	cout << p1 << ' ' << p2 << '\n';
	p1 = p1 - p2;
	cout << p1 << ' ' << p2 << '\n';
	p1--;
	p2--;
	cout << p1 << ' ' << p2 << '\n';
	--p1;
	--p2;
	cout << p1 << ' ' << p2 << '\n';
}

/*
Point(0, 0, 0)    Point(2, 3, 1)
Point(2, 3, 1)    Point(2, 3, 1)
Point(2, 3, 1)    Point(4, 6, 2)
Point(3, 4, 2)    Point(5, 7, 3)
Point(4, 5, 3)    Point(6, 8, 4)
Point(16, 20, 12) Point(24, 32, 16)
Point(8, 10, 6)   Point(12, 16, 8)
Point(3, 0, 1)    Point(2, 1, 3)
Point(1, -1, -2)  Point(2, 1, 3)
Point(0, -2, -3)  Point(1, 0, 2)
Point(-1, -3, -4) Point(0, -1, 1)
*/

class Point {
public:
    int x, y, z;
	Point(int x=0, int y=0, int z=0) : x(x), y(y), z(z) {}
    friend ostream& operator<<(ostream &output, Point &p) { 
        output << "Point(" << p.x << ", " << p.y << ", " << p.z << ")";
        return output;
    }
    bool operator<(Point obj) {
        return (this->x < obj.x) ||
               (this->x == obj.x && this->y < obj.y) ||
               (this->x == obj.x && this->y == obj.y && this->z < obj.z);
    }
    bool operator<=(Point obj) {
        return (this->x <= obj.x) ||
               (this->x == obj.x && this->y <= obj.y) ||
               (this->x == obj.x && this->y == obj.y && this->z <= obj.z);
    }
    bool operator>(Point obj) {
        return (this->x > obj.x) ||
               (this->x == obj.x && this->y > obj.y) ||
               (this->x == obj.x && this->y == obj.y && this->z > obj.z);
    }
    bool operator>=(Point obj) {
        return (this->x >= obj.x) ||
               (this->x == obj.x && this->y >= obj.y) ||
               (this->x == obj.x && this->y == obj.y && this->z >= obj.z);
    }
    bool operator==(Point obj) {
        return (this->x == obj.x && this->y == obj.y && this->z == obj.z);
    }
    bool operator!=(Point obj) {
        return !(this->x == obj.x && this->y == obj.y && this->z == obj.z);
	}
};
int main() {
	Point p1(4, 1, 3);
	Point p2(4, 1, 3);
	cout << p1 << ' ' << p2 << '\n';
	cout << (p1 == p2) << '\n';
	cout << (p1 != p2) << '\n';
	cout << (p1 < p2) << '\n';
	cout << (p1 <= p2) << '\n';
	cout << (p1 > p2) << '\n';
	cout << (p1 >= p2) << '\n';
}

/*
Point(4, 1, 3) Point(4, 1, 3)
1
0
0
1
0
1
*/

class Point {
public:
    int x, y, z;
	Point(int x=0, int y=0, int z=0) : x(x), y(y), z(z) {}
    friend ostream& operator<<(ostream &output, Point &p) { 
        output << "Point(" << p.x << ", " << p.y << ", " << p.z << ")";
        return output;
    }
    Point operator<<(int bits) {
        Point p(this->x << bits, this->y << bits, this->z << bits);
        return p;
    }
    Point operator>>(int bits) {
        Point p(this->x >> bits, this->y >> bits, this->z >> bits);
        return p;
    }
    Point operator&(Point obj) {
        Point p(this->x & obj.x, this->y & obj.y, this->z & obj.z);
        return p;
    }
    Point operator|(Point obj) {
        Point p(this->x | obj.x, this->y | obj.y, this->z | obj.z);
        return p;
    }
    Point operator^(Point obj) {
        Point p(this->x ^ obj.x, this->y ^ obj.y, this->z ^ obj.z);
        return p;
    }
    Point operator~() {
        Point p(~this->x, ~this->y, ~this->z);
        return p;
    }
    Point operator+() {
        Point p(+this->x, +this->y, +this->z);
        return p;
    }
    Point operator-() {
        Point p(-this->x, -this->y, -this->z);
        return p;
    }
};
int main() {
	Point p1(3, 2, 5);
	Point p2(4, 1, 2);
	cout << p1 << ' ' << p2 << '\n';
	p1 = p1 << 3;
	p2 = p2 << 2;
	cout << p1 << ' ' << p2 << '\n';
	p1 = p1 >> 1;
	p2 = p2 >> 1;
	cout << p1 << ' ' << p2 << '\n';
	p1 = p1 & p2;
	cout << p1 << ' ' << p2 << '\n';
	p2 = p2 | p1;
	cout << p1 << ' ' << p2 << '\n';
	p1 = p1 ^ p2;
	cout << p1 << ' ' << p2 << '\n';
	p2 = p2 ^ p1;
	cout << p1 << ' ' << p2 << '\n';
	p1 = ~p1;
	p2 = ~p2;
	cout << p1 << ' ' << p2 << '\n';
	p1 = -p1;
	p2 = -p2;
	cout << p1 << ' ' << p2 << '\n';
	p1 = +p1;
	p2 = +p2;
	cout << p1 << ' ' << p2 << '\n';
}

/*
Point(3, 2, 5)    Point(4, 1, 2)
Point(24, 16, 40) Point(16, 4, 8)
Point(12, 8, 20)  Point(8, 2, 4)
Point(8, 0, 4)    Point(8, 2, 4)
Point(8, 0, 4)    Point(8, 2, 4)
Point(0, 2, 0)    Point(8, 2, 4)
Point(0, 2, 0)    Point(8, 0, 4)
Point(-1, -3, -1) Point(-9, -1, -5)
Point(1, 3, 1)    Point(9, 1, 5)
Point(1, 3, 1)    Point(9, 1, 5)
*/

class Point {
public:
    int x, y, z;
	Point(int x=0, int y=0, int z=0) : x(x), y(y), z(z) {}
    friend ostream& operator<<(ostream &output, Point &p) { 
        output << "Point(" << p.x << ", " << p.y << ", " << p.z << ")";
        return output;
    }
    void operator+=(Point obj) {
        this->x+=obj.x, this->y+=obj.y, this->z+=obj.z;
    }
    void operator-=(Point obj) {
        this->x-=obj.x, this->y-=obj.y, this->z-=obj.z;
    }
    void operator*=(int scalar) {
        this->x*=scalar, this->y*=scalar, this->z*=scalar;
    }
    void operator/=(int scalar) {
        this->x/=scalar, this->y/=scalar, this->z/=scalar;
    }
    void operator%=(int scalar) {
        this->x%=scalar, this->y%=scalar, this->z%=scalar;
    }
};
int main() {
	Point p1;
	Point p2(2, 3, 1);
	cout << p1 << ' ' << p2 << '\n';
	p1 += p2;
	cout << p1 << ' ' << p2 << '\n';
	p2 += p1;
	cout << p1 << ' ' << p2 << '\n';
	p1 *= 4;
	p2 *= 4;
	cout << p1 << ' ' << p2 << '\n';
	p1 /= 2;
	p2 /= 2;
	cout << p1 << ' ' << p2 << '\n';
	p1 %= 5;
	p2 %= 5;
	cout << p1 << ' ' << p2 << '\n';
	p1 -= p2;
	cout << p1 << ' ' << p2 << '\n';
	p2 -= p1;
	cout << p1 << ' ' << p2 << '\n';
}

/*
Point(0, 0, 0)   Point(2, 3, 1)
Point(2, 3, 1)   Point(2, 3, 1)
Point(2, 3, 1)   Point(4, 6, 2)
Point(8, 12, 4)  Point(16, 24, 8)
Point(4, 6, 2)   Point(8, 12, 4)
Point(4, 1, 2)   Point(3, 2, 4)
Point(1, -1, -2) Point(3, 2, 4)
Point(1, -1, -2) Point(2, 3, 6)
*/

class Point {
public:
    int x, y, z;
	Point(int x=0, int y=0, int z=0) : x(x), y(y), z(z) {}
    friend ostream& operator<<(ostream &output, Point &p) { 
        output << "Point(" << p.x << ", " << p.y << ", " << p.z << ")";
        return output;
    }
    friend istream& operator>>(istream  &input, Point &p) { 
        input >> p.x >> p.y >> p.z;
        return input;            
    }
    void operator=(Point &p) {
        this->x=p.x, this->y=p.y, this->z=p.z;
    }
};
class Points {
private:
    int N;
	Point *pnts;
public:
	Points(int N) {
        this->N = N;
		this->pnts = new Point[N];
	}
    Point& operator[](int i) {
        if (i >= N || i < -N) {
            cout << "Index out of bounds\n";
            Point temp;
            return temp;
        }
        return pnts[(i+N)%N];
    }
};
int main() {
	int N = 5;
    Point p1(3, 1, 4), p2(2, 8, -1), p3(7, 1, -2);
	Points arr(N);
	arr[0] = p2;
	arr[-1] = p1;
	arr[1] = p2;
	arr[-2] = p1;
	arr[2] = p3;
	for (int i = 0; i < N+2; i++)
		cout << arr[i] << '\n';
}

/*
Point(2, 8, -1)
Point(2, 8, -1)
Point(7, 1, -2)
Point(3, 1, 4)
Point(3, 1, 4)
Index out of bounds
Point(0, 0, 0)
Index out of bounds
Point(0, 0, 0)
*/
