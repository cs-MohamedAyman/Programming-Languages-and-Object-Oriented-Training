class Point:
    def __init__(self, x=0, y=0, z=0):
        self.x = x ; self.y = y ; self.z = z
    def __str__(self):
        return 'Point(%d, %d, %d)' % (self.x, self.y, self.z)

p1 = Point()
p2 = Point(2, 3, 1)
print(p1, p2)

'''
Point(0, 0, 0)  Point(2, 3, 1)
'''

class Point:
    def __init__(self, x=0, y=0, z=0):
        self.x = x ; self.y = y ; self.z = z
    def __str__(self):
        return 'Point(' + str(self.x) + ', ' + str(self.y) + ', ' + str(self.z) + ')'
    def __add__(self, obj):
        return Point(self.x + obj.x, self.y + obj.y, self.z + obj.z)
    def __sub__(self, obj):
        return Point(self.x - obj.x, self.y - obj.y, self.z - obj.z)
    def __mul__(self, scalar):
        return Point(self.x * scalar, self.y * scalar, self.z * scalar)
    def __mod__(self, scalar):
        return Point(self.x % scalar, self.y % scalar, self.z % scalar)
    def __floordiv__(self, scalar):
        return Point(self.x // scalar, self.y // scalar, self.z // scalar)
    def __truediv__(self, scalar):
        return Point(self.x / scalar, self.y / scalar, self.z / scalar)
    def __pow__(self, scalar):
        return Point(self.x ** scalar, self.y ** scalar, self.z ** scalar)

p1 = Point()
p2 = Point(2, 3, 1)
print(p1, p2)
p1 = p1 + p2
print(p1, p2)
p2 = p2 + p1
print(p1, p2)
p1 = p1 * 4
p2 = p2 * 4
print(p1, p2)
p1 = p1 // 2
p2 = p2 // 2
print(p1, p2)
p1 = p1 % 5
p2 = p2 % 5
print(p1, p2)
p1 = p1 - p2
print(p1, p2)
p1 = p1 ** 2
p2 = p2 ** 2
print(p1, p2)
p1 = p1 / 1
p2 = p2 / 1
print(p1, p2)

'''
Point(0, 0, 0)       Point(2, 3, 1)
Point(2, 3, 1)       Point(2, 3, 1)
Point(2, 3, 1)       Point(4, 6, 2)
Point(8, 12, 4)      Point(16, 24, 8)
Point(4, 6, 2)       Point(8, 12, 4)
Point(4, 1, 2)       Point(3, 2, 4)
Point(1, -1, -2)     Point(3, 2, 4)
Point(1, 1, 4)       Point(9, 4, 16)
Point(1.0, 1.0, 4.0) Point(9.0, 4.0, 16.0)
'''

class Point:
    def __init__(self, x=0, y=0, z=0):
        self.x = x ; self.y = y ; self.z = z
    def __str__(self):
        return 'Point(%d, %d, %d)' % (self.x, self.y, self.z)
    def __lt__(self, obj):
        return (self.x < obj.x) or \
               (self.x == obj.x and self.y < obj.y) or \
               (self.x == obj.x and self.y == obj.y and self.z < obj.z)
    def __le__(self, obj):
        return (self.x <= obj.x) or \
               (self.x == obj.x and self.y <= obj.y) or \
               (self.x == obj.x and self.y == obj.y and self.z <= obj.z)
    def __gt__(self, obj):
        return (self.x > obj.x) or \
               (self.x == obj.x and self.y > obj.y) or \
               (self.x == obj.x and self.y == obj.y and self.z > obj.z)
    def __ge__(self, obj):
        return (self.x >= obj.x) or \
               (self.x == obj.x and self.y >= obj.y) or \
               (self.x == obj.x and self.y == obj.y and self.z >= obj.z)
    def __eq__(self, obj):
        return (self.x == obj.x and self.y == obj.y and self.z == obj.z)
    def __ne__(self, obj):
        return not(self.x == obj.x and self.y == obj.y and self.z == obj.z)

p1 = Point(4, 1, 3)
p2 = Point(4, 1, 3)
print(p1, p2)
print(p1 == p2)
print(p1 != p2)
print(p1 < p2)
print(p1 <= p2)
print(p1 > p2)
print(p1 >= p2)

'''
Point(4, 1, 3) Point(4, 1, 3)
True
False
False
True
False
True
'''

class Point:
    def __init__(self, x=0, y=0, z=0):
        self.x = x ; self.y = y ; self.z = z
    def __str__(self):
        return 'Point(%d, %d, %d)' % (self.x, self.y, self.z)
    def __lshift__(self, bits):
        return Point(self.x << bits, self.y << bits, self.z << bits)
    def __rshift__(self, bits):
        return Point(self.x >> bits, self.y >> bits, self.z >> bits)
    def __and__(self, obj):
        return Point(self.x & obj.x, self.y & obj.y, self.z & obj.z)
    def __or__(self, obj):
        return Point(self.x | obj.x, self.y | obj.y, self.z | obj.z)
    def __xor__(self, obj):
        return Point(self.x ^ obj.x, self.y ^ obj.y, self.z ^ obj.z)
    def __invert__(self):
        return Point(~self.x, ~self.y, ~self.z)
    def __pos__(self):
        return Point(+self.x, +self.y, +self.z)
    def __neg__(self):
        return Point(-self.x, -self.y, -self.z)

p1 = Point(3, 2, 5)
p2 = Point(4, 1, 2)
print(p1, p2)
p1 = p1 << 3
p2 = p2 << 2
print(p1, p2)
p1 = p1 >> 1
p2 = p2 >> 1
print(p1, p2)
p1 = p1 & p2
print(p1, p2)
p2 = p2 | p1
print(p1, p2)
p1 = p1 ^ p2
print(p1, p2)
p2 = p2 ^ p1
print(p1, p2)
p1 = ~p1
p2 = ~p2
print(p1, p2)
p1 = -p1
p2 = -p2
print(p1, p2)
p1 = +p1
p2 = +p2
print(p1, p2)

'''
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
'''

class Point:
    def __init__(self, x=0, y=0, z=0):
        self.x = x ; self.y = y ; self.z = z
    def __str__(self):
        return 'Point(%d, %d, %d)' % (self.x, self.y, self.z)
    def __iadd__(self, obj):
        self.x += obj.x ; self.y += obj.y ; self.z += obj.z
        return self
    def __isub__(self, obj):
        self.x -= obj.x ; self.y -= obj.y ; self.z -= obj.z
        return self
    def __imul__(self, scalar):
        self.x *= scalar ; self.y *= scalar ; self.z *= scalar
        return self
    def __imod__(self, scalar):
        self.x %= scalar ; self.y %= scalar ; self.z %= scalar
        return self
    def __ifloordiv__(self, scalar):
        self.x //= scalar ; self.y //= scalar ; self.z //= scalar
        return self
    def __itruediv__(self, scalar):
        self.x /= scalar ; self.y /= scalar ; self.z /= scalar
        return self
    def __ipow__(self, scalar):
        self.x **= scalar ; self.y **= scalar ; self.z **= scalar
        return self

p1 = Point()
p2 = Point(2, 3, 1)
print(p1, p2)
p1 += p2
print(p1, p2)
p2 += p1
print(p1, p2)
p1 *= 4
p2 *= 4
print(p1, p2)
p1 //= 2
p2 //= 2
print(p1, p2)
p1 %= 5
p2 %= 5
print(p1, p2)
p1 **= 2
p2 **= 2
print(p1, p2)
p1 -= p2
print(p1, p2)
p2 -= p1
print(p1, p2)

'''
Point(0, 0, 0)    Point(2, 3, 1)
Point(2, 3, 1)    Point(2, 3, 1)
Point(2, 3, 1)    Point(4, 6, 2)
Point(8, 12, 4)   Point(16, 24, 8)
Point(4, 6, 2)    Point(8, 12, 4)
Point(4, 1, 2)    Point(3, 2, 4)
Point(16, 1, 4)   Point(9, 4, 16)
Point(7, -3, -12) Point(9, 4, 16)
Point(7, -3, -12) Point(2, 7, 28)
'''

class Point:
    def __init__(self, x=0, y=0, z=0):
        self.x = x ; self.y = y ; self.z = z
    def __str__(self):
        return 'Point(%d, %d, %d)' % (self.x, self.y, self.z)
    def __getitem__(self, idx):
        if idx == 0 or idx == -3: return self.x
        if idx == 1 or idx == -2: return self.y
        if idx == 2 or idx == -1: return self.z
        print('Index out of bounds')
        return -(1<<63)
    def __setitem__(self, idx, item):
        if idx == 0 or idx == -3: self.x = item
        if idx == 1 or idx == -2: self.y = item
        if idx == 2 or idx == -1: self.z = item

p = Point(3, 1, 4)
print(p[0])
print(p[1])
print(p[2])
print(p[-1])
print(p[-2])
print(p[-3])
print(p[3])
print(p[-4])

class Point:
    def __init__(self, x=0, y=0, z=0):
        self.x = x ; self.y = y ; self.z = z
    def __str__(self):
        return 'Point(%d, %d, %d)' % (self.x, self.y, self.z)
    def copy(self, p):
        self.x = p.x ; self.y = p.y ; self.z = p.z

class Points:
    def __init__(self, N):
        self.__N = N
        self.__pnts = [Point() for i in range(N)]
    def __getitem__(self, idx):
        if i >= self.__N or i < -self.__N:
            print('Index out of bounds')
            return Point()
        return self.__pnts[idx]
    def __setitem__(self, idx, item):
        if -self.__N <= idx < self.__N:
            self.__pnts[idx].copy(item)

N = 5
p1 = Point(3, 1, 4)
p2 = Point(2, 8, -1)
p3 = Point(7, 1, -2)
arr = Points(N)
arr[0] = p2
arr[-1] = p1
arr[1] = p2
arr[-2] = p1
arr[2] = p3
for i in range(N+2):
    print(arr[i])

'''
Point(2, 8, -1)
Point(2, 8, -1)
Point(7, 1, -2)
Point(3, 1, 4)
Point(3, 1, 4)
Index out of bounds
Point(0, 0, 0)
Index out of bounds
Point(0, 0, 0)
'''
