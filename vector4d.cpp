#include <iostream>
#include <cmath>
using namespace std;

class vector4d {
private:
    float a, b, c, d;

public:
    vector4d() : a(0), b(0), c(0), d(0) {}
    vector4d(float a, float b, float c, float d) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    float magnitude() const {
        return sqrt(a * a + b * b + c * c + d * d);
    }

    bool unitvector() const {
        return fabs(magnitude() - 1.0) < 1e-6;
    }

    // Dot product and subtraction
    friend float dotproduct(const vector4d& v1, const vector4d& v2);
    friend vector4d operator-(const vector4d& v1, const vector4d& v2);

    // Additive inverse
    vector4d operator-() const {
        return vector4d(-a, -b, -c, -d);
    }

    void print() const {
        cout << "(" << a << ", " << b << ", " << c << ", " << d << ")" << endl;
    }
};

float dotproduct(const vector4d& v1, const vector4d& v2) {
    return v1.a * v2.a + v1.b * v2.b + v1.c * v2.c + v1.d * v2.d;
}

vector4d operator-(const vector4d& v1, const vector4d& v2) {
    return vector4d(v1.a - v2.a,
                    v1.b - v2.b,
                    v1.c - v2.c,
                    v1.d - v2.d);
}

int main() {
    vector4d v1(1.0, 4.0, 3.0, 2.0);
    vector4d v2(2.0, 5.0, 8.0, 9.0);

    cout << "Magnitude of v1: " << v1.magnitude() << endl;
    cout << "Is v1 a unit vector? " << boolalpha << v1.unitvector() << endl;

    cout << "v1 = "; v1.print();
    cout << "v2 = "; v2.print();

    cout << "Dot Product: " << dotproduct(v1, v2) << endl;

    vector4d v3 = v1 - v2;
    cout << "v1 - v2 = "; v3.print();

    vector4d v4 = -v1;
    cout << "Additive inverse of v1 = "; v4.print();

    return 0;
}

