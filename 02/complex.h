/*
* Copyright 2018
* Created by George E Gordon
*/

#ifndef _GGORDON_HW_2_COMPLEX_H_  //NOLINT
#define _GGORDON_HW_2_COMPLEX_H_  //NOLINT

#include <cmath>
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::to_string;
using std::ostream;
using std::istream;
using std::stod;

typedef std::string string;


class Complex {
 public:
  Complex();
  Complex(double imag);
  Complex(double real, double imag);

  double real() const;
  void real(double real);

  double imag() const;
  void imag(double imag);

  const Complex Add(const Complex& rhs) const;
  const Complex Add(double rhs) const;
  const Complex Add(int rhs) const;
  friend const Complex operator+(const Complex& lhs, const Complex& rhs);
  friend const Complex operator+(const Complex& lhs, double rhs);
  friend const Complex operator+(const Complex& lhs, int rhs);
  friend const Complex operator+(double lhs, const Complex& rhs);
  friend const Complex operator+(int lhs, const Complex& rhs);

  const Complex Mul(const Complex& rhs) const;
  const Complex Mul(double rhs) const;
  const Complex Mul(int rhs) const;
  friend const Complex operator*(const Complex& lhs, const Complex& rhs);
  friend const Complex operator*(const Complex& lhs, double rhs);
  friend const Complex operator*(const Complex& lhs, int rhs);
  friend const Complex operator*(double lhs, const Complex& rhs);
  friend const Complex operator*(int lhs, const Complex& rhs);

  const string ToString() const;
  static const Complex ToComplex(string& string_complex);

  friend istream& operator>>(istream& lhs, Complex& rhs);
  friend ostream& operator<<(ostream& lhs, const Complex& rhs);

 private:
  double real_;
  double imag_;
  string string_complex = "nan";
};

#endif  //NOLINT