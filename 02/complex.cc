/*
 * Copyright 2018
 * Created by George E Gordon
 */

#include "complex.h"

/*
*	Constructors:
*	Default:
*	- sets real and imag to 0.0
*	2nd:
*	- accepts double, assign to imag, real = 0.0
*	3rd:
*	- accepts 2 doubles, first to real, second to imag
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
*	Real Overload
*	- get (double) from private variables 'this'
*	- set (double) to private real variable / void no return
*/
double Complex::real() const {
  return this->real_;
}
void Complex::real(double new_real_val) {
  this->real_ = new_real_val;
}
/*
*	Imag Overload
*	- get (double) from private variables 'this'
*	- set (double) to private real variable / void no return
*/
double Complex::imag() const {
  return this->imag_;
}
void Complex::imag(double new_imag_val) {
  this->imag_ = new_imag_val;
}

/*
*	Addition Method
*	Accept one parameter
*
*	1.	Add both reals from each complex
*	2.	Add both imags from each complex
*	3.	Return new complex
*/
const Complex Complex::Add(const Complex & complex_two) const {
  Complex new_add_complex;
  new_add_complex.real(real_ + complex_two.real());
  new_add_complex.imag(imag_ + complex_two.imag());

  return new_add_complex;
}
const Complex Complex::Add(double add_double) const {
  Complex new_add_complex;
  Complex double_complex = Complex(add_double, 0.0);
  new_add_complex.real(real_ + double_complex.real());
  new_add_complex.imag(imag_ + double_complex.imag());

  return new_add_complex;
}
const Complex Complex::Add(int add_int) const {
  Complex new_add_complex;
  Complex int_complex = Complex(static_cast<double>(add_int), 0.0);
  new_add_complex.real(real_ + int_complex.real());
  new_add_complex.imag(imag_ + int_complex.imag());

  return new_add_complex;
}
/*
*	+ operator
*	When adding a int or double, it converts the int or double
*	into a complex, then adds both complexs together.
*		- Assumed that int and double cast to real position
*/
const Complex operator+(const Complex & lhs, const Complex & rhs) {
  return lhs.Add(rhs);
}
const Complex operator+(const Complex & lhs_complex, int rhs) {
  Complex rhs_complex = Complex(static_cast<double>(rhs), 0.0);
  return lhs_complex.Add(rhs_complex);
}
const Complex operator+(const Complex & lhs_complex, double rhs) {
  Complex rhs_complex = Complex(rhs, 0.0);
  return lhs_complex.Add(rhs_complex);
}
const Complex operator+(int lhs, const Complex & rhs_complex) {
  Complex lhs_complex = Complex(static_cast<double>(lhs), 0.0);
  return lhs_complex.Add(rhs_complex);
}
const Complex operator+(double lhs, const Complex & rhs_complex) {
  Complex lhs_complex = Complex(lhs, 0.0);
  return lhs_complex.Add(rhs_complex);
}

/*
*	Multiplication Method
*	Accept one parameter
*
*	Multiplication process:
*		(x + yi)(a + bi) = (xa – yb) + (xb + ya)i
*	1.	For new real, multiply both complex reals, 
*			and both complex imags and subtract
*	2.	For new imag, multiply c1 real by c2 imag,
*			and c1 imag by c2 real and add
*	Automatically assumes i squared is dealt with
*/
const Complex Complex::Mul(const Complex & complex_two) const {
  Complex new_mul_complex;
  new_mul_complex.real((real_ * complex_two.real())
    - (imag_ * complex_two.imag()));
  new_mul_complex.imag((real_ * complex_two.imag())
    + (imag_ * complex_two.real()));

  return new_mul_complex;
}
const Complex Complex::Mul(double add_double) const {
  Complex new_mul_complex;
  Complex double_complex = Complex(add_double, 0.0);
  new_mul_complex.real((real_ * double_complex.real())
    - (imag_ * double_complex.imag()));
  new_mul_complex.imag((real_ * double_complex.imag())
    + (imag_ * double_complex.real()));

  return new_mul_complex;
}
const Complex Complex::Mul(int add_int) const {
  Complex new_mul_complex;
  Complex int_complex = Complex(static_cast<double>(add_int), 0.0);
  new_mul_complex.real((real_ * int_complex.real())
    - (imag_ * int_complex.imag()));
  new_mul_complex.imag((real_ * int_complex.imag())
    + (imag_ * int_complex.real()));

  return new_mul_complex;
}
/*
*	* operator
*	When multiplying a int or double, it converts the int 
*	or double into a complex, then adds both complexs together.
*		- Assumed that int and double cast to real position
*/
const Complex operator*(const Complex & lhs, const Complex & rhs) {
  return lhs.Mul(rhs);
}
const Complex operator*(const Complex & lhs_complex, int rhs) {
  Complex rhs_complex = Complex(static_cast<double>(rhs), 0.0);
  return lhs_complex.Mul(rhs_complex);
}
const Complex operator*(const Complex & lhs_complex, double rhs) {
  Complex rhs_complex = Complex(rhs, 0.0);
  return lhs_complex.Mul(rhs_complex);
}
const Complex operator*(int lhs, const Complex & rhs_complex) {
  Complex lhs_complex = Complex(static_cast<double>(lhs), 0.0);
  return lhs_complex.Mul(rhs_complex);
}
const Complex operator*(double lhs, const Complex & rhs_complex) {
  Complex lhs_complex = Complex(lhs, 0.0);
  return lhs_complex.Mul(rhs_complex);
}

/*
*	To String Method
*	Process:
*	1.	Checks if whole number
*		a.	Base case - real > 0.0 && imag > 1.0
*		b.	imag is 1.0
*		c.	imag < 0.0
*		d.	imag = 0.0
*		e.	real = 0.0
*	2.	Else floating point
*		a.	base case
*		b.	imag < 0
*/
const string Complex::ToString() const {
  string new_string = "";
  //  if whole number
  if (floor(this->real_) == this->real_ && floor(this->imag_) == this->imag_) {
  //  base case
    if (this->real_ > 0.0 && this->imag_ > 1.0) {
      new_string = "(" + to_string(round(this->real_ * 100)/100).substr(0, 1)
        + " + " + to_string(round((this->imag_) * 100)/100).substr(0, 1) + "i)";
    }
    //  imag is 1.0
    if (this->imag_ == 1.0) {
      new_string = "(" + to_string(round(this->real_ * 100)/100).substr(0, 1)
        + " + " + "i)";
    }
    //  imag less than 0
    if (this->imag_ < 0.0) {
      new_string = "(" + to_string(round(this->real_*100)/100).substr(0, 1)
        + " - " + to_string(round((this->imag_*-1.0) * 100)/100).substr(0, 1)
        + "i)";
    }
    //  imag is 0
    if (this->imag_ == 0.0) {
      new_string = "(" + to_string(round(this->real_ * 100)/100).substr(0, 1)
        + ")";
    }
    //  real is 0
    if (this->real_ == 0.0) {
      new_string = "(" + to_string(round(this->imag_ * 100)/100).substr(0, 1)
        + "i)";
    }
    } else {
    /*  non whole floating point
     *  capturing to the .00
    */
    //  base case
    if (this->real_ > 0.0 && this->imag_ > 1.0) {
      new_string = "(" + to_string(round(this->real_ * 100)/100).substr(0, 4)
        + " + " + to_string(round(this->imag_ * 100)/100).substr(0, 4) + "i)";
    }
    //  imag less than 0
    if (this->imag_ < 0.0) {
      new_string = "(" + to_string(round(this->real_ * 100)/100).substr(0, 4)
        + " - " + to_string(round((this->imag_*-1.0) * 100)/100).substr(0, 4)
        + "i)";
    }
  }
  return new_string;
}

/*
*	To Complex Method
*	To Complex Process:
*	** Probably a much better way to do this - potentially fix **
*	1.	For loop to iterate through the string
*		a.	length = 1 (assuming single real value)
*		b.	length = 2 (assuming single imaginary value)
*		c.	length > 2, real digits
*		d.	after + operator, imaginary digits
*		e.	after - operator, imaginary  digits
*		f.	set + operator
*		g.	set - operator
*		h.	move forward
*	2.	If no real or imaginary, meaning string not set, set to default 0.0
*	3.	Convert string to double using std::stod (cplusplus.com)
*	4.	Check for negative, to convert imaginary to negative expression
*	5.	Build complex with new double values
*/
const Complex Complex::ToComplex(string& string_complex) {
  string real = "";
  string imag = "";
  unsigned int i = 0;
  int op_spot = 0;

  for (i = 0; i < string_complex.length(); ++i) {
    if (string_complex.length() == 1) {
      real += string_complex.at(i);
    } else if (string_complex.length() == 2) {
      imag += string_complex.at(i);
    } else if (string_complex.length() > 2 && op_spot == 0
      && string_complex.at(i) != '+'
      && string_complex.at(i) != 'i'
      && string_complex.at(i) != '-') {
      real += string_complex.at(i);
    } else if (op_spot == 1 && string_complex.at(i) != '+'
      && string_complex.at(i) != 'i'
      && string_complex.at(i) != '-') {
      imag += string_complex.at(i);
    } else if (op_spot == 2 && string_complex.at(i) != '+'
      && string_complex.at(i) != 'i'
      && string_complex.at(i) != '-') {
      imag += string_complex.at(i);
    } else if (string_complex.at(i) == '+') {
      op_spot = 1;
    } else if (string_complex.at(i) == '-') {
      op_spot = 2;
    } else {
      i++;
    }
  }
  if (real == "") {
    real = "0.0";
  }
  if (imag == "") {
    imag = "0.0";
  }

  double real_dbl = std::stod(real);
  double imag_dbl = std::stod(imag);
  if (op_spot == 2) {
    imag_dbl *= -1.0;
  }
  Complex new_complex = Complex(real_dbl, imag_dbl);
  return new_complex;
}

/*
*	>> Function
*	1.	Accept istream object and Complex object
*	2.	Extract a string of the type in ToString
*	3.	Returns a complex number
*/
istream& operator>>(istream& in, Complex& rhs) {
  double a_real;
  double a_imag;
  in >> a_real >> a_imag;
  rhs = Complex(a_real, a_imag);
  return in;
}

/*
*	<< Function
*	1.	Accept ostream object and Complex object
*	2.	Add complex to the ostream object
*	3.	Return ostream like cout
*/
ostream& operator<<(ostream& out, const Complex& rhs) {
  out << rhs.ToString();
  return out;
}
