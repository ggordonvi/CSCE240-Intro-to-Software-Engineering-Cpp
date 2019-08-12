/*
 * Copyright 2018
 * Created by George E Gordon
 */

#ifndef _GGORDON_HW_02_05_COMPLEX_H_  // NOLINT
#define _GGORDON_HW_02_05_COMPLEX_H_  // NOLINT

#include <cmath>
#include <iostream>
#include <string>
#include <cassert>
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
  /*
   * TODO: assert the correctness of the string representation of the Complex
   * instance in str_complex when converting.
   */
  static const Complex ToComplex(const string& str_complex);

  /*
   * TODO: examine the contents of the parameters to make sure a valid
   * representation of a Complex instance is stored.
   */
  static bool IsComplex(const string& in_string);
  static bool IsComplex(istream& in_stream);

  /* TODO: Implement the LT and operator< methods and functions */
  bool LT(const Complex& rhs) const;
  bool LT(double rhs) const;
  bool LT(int rhs) const;
  bool operator<(const Complex& rhs) const;
  bool operator<(double rhs) const;
  bool operator<(int rhs) const;
  friend bool operator<(double lhs, const Complex& rhs);
  friend bool operator<(int lhs, const Complex& rhs);

  /* TODO: assert the correctness of the Complex string in lhs */
  friend istream& operator>>(istream& lhs, Complex& rhs);

  /*
   * Keep these from your previous submission or implement them so that I may
   * unit test your class.
   */
  Complex();
  explicit Complex(double imag);
  Complex(double real, double imag);

  double real() const;
  double imag() const;

  void real(double real);
  void imag(double imag);

 private:
  double real_;
  double imag_;
};

#endif  // NOLINT