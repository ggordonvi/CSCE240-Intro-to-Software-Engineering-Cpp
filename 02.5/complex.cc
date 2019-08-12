/*
 * Copyright 2018
 * Created by George E Gordon
 */

#include "complex.h" // NOLINT

/*
*  Constructors:
*  Default:
*  - sets real and imag to 0.0
*  2nd:
*  - accepts double, assign to imag, real = 0.0
*  3rd:
*  - accepts 2 doubles, first to real, second to imag
*/
Complex::Complex() {
  real_ = 0.0;
  imag_ = 0.0;
}
Complex::Complex(double new_imag_val) {
  real_ = 0.0;
  imag_ = new_imag_val;
}
Complex::Complex(double new_real_val, double new_imag_val) {
  real_ = new_real_val;
  imag_ = new_imag_val;
}

/*
*  Real Overload
*  - get (double) from private variables 'this'
*  - set (double) to private real variable / void no return
*/
double Complex::real() const {
  return this->real_;
}
void Complex::real(double new_real_val) {
  this->real_ = new_real_val;
}
/*
*  Imag Overload
*  - get (double) from private variables 'this'
*  - set (double) to private real variable / void no return
*/
double Complex::imag() const {
  return this->imag_;
}
void Complex::imag(double new_imag_val) {
  this->imag_ = new_imag_val;
}

/*
*  ToComplex Method
*  Process:
*    - Initialize variables used to help check validity
*    - For loop to iterate through the string
*    - Switch to check each char on the string
*        - Open parenthesis, mark and move
*        - Close parenthesis, mark and move
*            - if imag not marked, only a real, set real
*        - + or - operator, set real, set pos or negative
*        - i, set imaginary
*        - " " space, move along
*        - tab, set tab error
*        - new line, set new line error
*        - default: add value to string
*    - Check if real or imag are blank, set to 0.0
*    - Check errors, assert on error
*    - Make strings into doubles
*    - If - in complex number, make imag negative
*    - Return new complex
*/
const Complex Complex::ToComplex(const string& complex_string) {
  int open_par = 0;
  int pos_or_neg = 0;
  int op = 0;
  int im = 0;
  int close_par = 0;
  int tab = 0;
  int new_line = 0;
  string build_string;
  string real_string = "";
  string imag_string = "";
  double real;
  double imag;

  for (unsigned int i = 0; i < complex_string.length(); i++) {
    switch (complex_string.at(i)) {
      case '(':
        open_par += 1;
        break;
      case '+':
        real_string = build_string;
        build_string = "";
        pos_or_neg = 1;
        op += 1;
        break;
      case '-':
        real_string = build_string;
        build_string = "";
        pos_or_neg = 2;
        op += 1;
        break;
      case ')':
        if (im == 0) {
          real_string = build_string;
        }
        close_par += 1;
        break;
      case 'i':
        imag_string = build_string;
        im += 1;
        break;
      case ' ':
        break;
      case '\t':
        tab = 1;
        break;
      case '\n':
        new_line = 1;
        break;
      default:
        build_string += complex_string.at(i);
    }
  }

  if (real_string == "") {
    real_string = "0.0";
  }
  if (imag_string == "") {
    imag_string = "0.0";
  }
  if (im == 1 && real_string == "0.0" && imag_string == "0.0") {
    imag_string = "1.0";
  }

  assert(im <= 1 && "More than one imaginary!");
  assert(op <= 1 && "More than one operator!");
  assert(open_par <= 1 && "No open parenthesis or too many!");
  assert(close_par <= 1 && "No close parenthesis or too many!");
  assert(tab == 0 && "No tabs allowed!");
  assert(new_line == 0 && "No new lines allowed!");


  real = stod(real_string);
  imag = stod(imag_string);
  if (pos_or_neg == 2) {
    imag = imag * -1.0;
  }
  return Complex(real, imag);
}

/*
*  IsComplex methods (string&) 
*  String Method:
*    - Checks for open parenthesis
*    - Checks for close parenthesis
*    - Checks for no tabs or new lines
*    - Returns true or false on complex number string validity
*/
bool Complex::IsComplex(const string& in_string) {
  int open_par = 0;
  int op = 0;
  int im = 0;
  int close_par = 0;
  int tab = 0;
  int new_line = 0;

  for (unsigned int i = 0; i < in_string.length(); i++) {
    switch (in_string.at(i)) {
      case '(':
        open_par += 1;
        break;
      case '+':
        op += 1;
        break;
      case '-':
        op += 1;
        break;
      case ')':
        close_par += 1;
        break;
      case 'i':
        im += 1;
        break;
      case ' ':
        break;
      case '\t':
        tab = 1;
        break;
      case '\n':
        new_line = 1;
        break;
      default:
        break;
    }
  }
  if (open_par == 1 && close_par == 1 && tab == 0
        && new_line == 0 && op <= 1 && im <= 1) {
    return true;
  } else {
    return false;
  }
}

/*
*  IsComplex methods (istream&)
*  IStream Method:
*    - Uses get to grab the next char in stream
*    - Checks for open parenthesis
*    - Checks for close parenthesis
*    - Checks for no tabs or new lines
*    - If error, return false
*    - Or no errors, return true
*/
bool Complex::IsComplex(istream& in_stream) {
  int open_par = 0;
  int op = 0;
  int im = 0;
  int close_par = 0;
  int tab = 0;
  int new_line = 0;
  char token;

  while (in_stream.get(token)) {
    switch (token) {
      case '(':
        open_par += 1;
        break;
      case '+':
        op += 1;
        break;
      case '-':
        op += 1;
        break;
      case ')':
        close_par += 1;
        break;
      case 'i':
        im += 1;
        break;
      case ' ':
        break;
      case '\t':
        tab = 1;
        break;
      case '\n':
        new_line = 1;
        break;
      default:
        break;
    }
  }
  if (open_par == 1 && close_par == 1 && tab == 0
        && new_line == 0 && op <= 1 && im <= 1) {
    return true;
  } else {
    return false;
  }
}

/*
*  LT Methods (less than)
*  Methods:
*    Complex < Complex
*    Complex < double
*    Complex < int
*  Process:
*    - Intialize comparable doubles
*    - Take the modulus of both sides, with formula given
*        - v-hat = sqrt(a^2 + b^2)
*    - If left hand side modulus < right hand side modulus
*        - return true
*    - Otherwise false
*/
bool Complex::LT(const Complex& a_complex) const {
  double lhs_modulus;
  double rhs_modulus;

  lhs_modulus = sqrt(pow(this->real_, 2.0) + pow(this->imag_, 2.0));
  rhs_modulus = sqrt(pow(a_complex.real(), 2.0) + pow(a_complex.imag(), 2.0));

  if (lhs_modulus < rhs_modulus)
    return true;
  else
    return false;
}
bool Complex::LT(double a_double) const {
  double lhs_modulus;
  double rhs_modulus;

  lhs_modulus = sqrt(pow(this->real_, 2.0) + pow(this->imag_, 2.0));
  rhs_modulus = sqrt(pow(a_double, 2.0));

  if (lhs_modulus < rhs_modulus)
    return true;
  else
    return false;
}
bool Complex::LT(int a_int) const {
  double lhs_modulus;
  double rhs_modulus;
  double a_double = static_cast<double>(a_int) * 1.0;

  lhs_modulus = sqrt(pow(this->real_, 2.0) + pow(this->imag_, 2.0));
  rhs_modulus = sqrt(pow(a_double, 2.0));

  if (lhs_modulus < rhs_modulus)
    return true;
  else
    return false;
}
/*
*  < operator
*  Process:
*  - Call LT method for:
*    - Complex < complex
*    - Complex < double
*    - Complex < int  
*  - Create complex, then call LT method for:
*    - double < complex
*    - int < complex
*/
bool Complex::operator<(const Complex& rhs_complex) const {
  return LT(rhs_complex);
}
bool Complex::operator<(double rhs_double) const {
  return LT(rhs_double);
}
bool Complex::operator<(int rhs_int) const {
  return LT(rhs_int);
}
bool operator<(double lhs_double, const Complex& rhs_complex) {
  Complex lhs_complex = Complex(lhs_double);
  return lhs_complex.LT(rhs_complex);
}
bool operator<(int lhs_int, const Complex& rhs_complex) {
  Complex lhs_complex = Complex(static_cast<double>(lhs_int));
  return lhs_complex.LT(rhs_complex);
}

/*
*  >> function
*
*/
istream& operator>>(istream& lhs, Complex& rhs) {
  int open_par = 0;
  int pos_or_neg = 0;
  int im = 0;
  int close_par = 0;
  int tab = 0;
  int new_line = 0;
  string build_string;
  string real_string = "";
  string imag_string = "";
  double real;
  double imag;
  char token;

  while (lhs.get(token)) {
    switch (token) {
      case '(':
        open_par = 1;
        break;
      case '+':
        real_string = build_string;
        build_string = "";
        pos_or_neg = 1;
        break;
      case '-':
        real_string = build_string;
        build_string = "";
        pos_or_neg = 2;
        break;
      case ')':
        if (im == 0) {
          real_string = build_string;
        }
        close_par = 1;
        break;
      case 'i':
        imag_string = build_string;
        im = 1;
      case ' ':
        break;
      case '\t':
        tab = 1;
        break;
      case '\n':
        new_line = 1;
      default:
        build_string += token;
    }
  }

  if (real_string == "") {
    real_string = "0.0";
  }
  if (imag_string == "") {
    imag_string = "0.0";
  }

  assert(open_par == 1 && "No open parenthesis");
  assert(close_par == 1 && "No close parenthesis");
  assert(tab == 0 && "No tabs allowed");
  assert(new_line == 0 && "No new lines allowed");

  real = stod(real_string);
  imag = stod(imag_string);
  if (pos_or_neg == 2) {
    imag = imag * -1.0;
  }
  rhs.real(real);
  rhs.imag(imag);

  return lhs;
}
