#include <iostream>
#include <cmath>

using namespace std;

class Shape {
public:
    virtual void Print() const = 0;
    virtual double Area() const = 0;
};

class RavnobedrenTriangle : public Shape {
protected:
    double a;
    double b;
public:
    RavnobedrenTriangle(double a, double b) : a(a), b(b) {}
    
    void Print() const override {
        cout << "Ravnobedren Triangle: A=" << a << ", B=" << b << ", Area=" << Area() << endl;
    }

    double Area() const override {
        double height = sqrt(b * b - (a / 2) * (a / 2));
        return (a * height) / 2;
    }
};

class Trapez : public Shape {
protected:
    double a1;
    double a2;
    double height;
public:
    Trapez(double a1, double a2, double height) : a1(a1), a2(a2), height(height) {}

    void Print() const override {
        cout << "Trapezoid: a1=" << a1 << ", a2=" << a2 << ", Height=" << height << ", Area=" << Area() << endl;
    }

    double Area() const override {
        return ((a1 + a2) / 2) * height;
    }
};

bool CompareArea(const Shape &s1, const Shape &s2) {
    return s1.Area() > s2.Area();
}

int main() {
    RavnobedrenTriangle triangle(4, 5);
    Trapez trapez(3, 5, 4);

    triangle.Print();
    trapez.Print();

    cout << "Triangle has larger area: " << CompareArea(triangle, trapez) << endl;

    return 0;
}

