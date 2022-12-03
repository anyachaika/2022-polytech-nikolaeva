#include "Complex.h"
#include "cmath"

Complex::Complex(double real, double imaginary) {
    this->real = real;
    this->imaginary = imaginary;
}

Complex::~Complex() = default;

Complex Complex::operator+(const Complex &other) const {
    return {this->real + other.real, this->imaginary + other.imaginary};
}

Complex Complex::operator-(const Complex &other) const {
    return {this->real - other.real, this->imaginary - other.imaginary};
}

bool Complex::operator==(const Complex &other) const {
    return this->real == other.real && this->imaginary == other.imaginary;
}

double Complex::abs() const {
    return sqrt(this->real * this->real + this->imaginary * this->imaginary);
}
