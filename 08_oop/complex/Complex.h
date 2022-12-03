#pragma once

class Complex {
public:
    Complex(double real = 0, double imaginary = 0);
    ~Complex();

    Complex operator+(const Complex &other) const;
    Complex operator-(const Complex &other) const;
    bool operator==(const Complex &other) const;
    double abs() const;
private:
    double real;
    double imaginary;
};

