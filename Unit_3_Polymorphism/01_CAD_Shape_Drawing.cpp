#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159265359 * radius * radius;
    }

    void draw() const override {
        cout << "Drawing circle with radius "
             << radius << endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w)
        : length(l), width(w) {}

    double area() const override {
        return length * width;
    }

    void draw() const override {
        cout << "Drawing rectangle with length "
             << length << " and width "
             << width << endl;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h)
        : base(b), height(h) {}

    double area() const override {
        return 0.5 * base * height;
    }

    void draw() const override {
        cout << "Drawing triangle with base "
             << base << " and height "
             << height << endl;
    }
};

int main() {
    vector<unique_ptr<Shape>> shapes;

    shapes.push_back(make_unique<Circle>(5));
    shapes.push_back(make_unique<Rectangle>(10, 6));
    shapes.push_back(make_unique<Triangle>(8, 4));

    cout << "=== CAD Shape Drawing System ===" << endl;

    for (const auto& shape : shapes) {
        shape->draw();
        cout << "Area: " << shape->area() << endl;
        cout << endl;
    }

    return 0;
}