/*
 * Copyright 2018
 * Created by George E Gordon
 */

 #include "complex.h"

//constructors
Complex::Complex() {
	real_ = 0.0;
	imag_ = 0.0;
}
Complex::Complex(double new_imag) {
	real_ = 0.0;
	imag_ = new_imag;
}
Complex::Complex(double new_real, double new_imag) {
	real_ = new_real;
	imag_ = new_imag;
}

//Getters and setters??
double Complex::real()  {
	return this->real_;
}
void Complex::real(double new_real) {
	this->real_ = new_real;
}
double Complex::imag() {
	return this->imag_;
}
void Complex::imag(double new_imag) {
	this->imag_ = new_imag;
}

//Addition
 Complex Complex::Add(Complex & other_complex) {
	Complex new_complex;
	
	new_complex.real(real_ + other_complex.real());
	new_complex.imag(imag_ + other_complex.imag());

	return new_complex;
}
 Complex Complex::Add(double real_add)  { }
 Complex Complex::Add(int real_add)  { }

//Multiplication
 Complex Complex::Mul(Complex & other_complex) {
	Complex new_complex;
	
	new_complex.real((real_*other_complex.real()) - (imag_*other_complex.imag()));
	new_complex.imag((real_*other_complex.imag()) + (imag_*other_complex.real()));

	return new_complex;
}
Complex Complex::Mul(double real_mult) { }
Complex Complex::Mul(int real_mult) { }

//To string
 String Complex::ToString() {
	int real_int = 0;
	int imag_int = 0;
	char operation = ' ';
	String return_string = "";

	return_string = to_string(this->real_) + " + " + to_string(this->imag_) + "i";

	return return_string;
}

//To complex
static Complex ToComplex(String complex_string) {
	Complex return_complex;
	String real_string;
	String imag_string;
	int iter = 0;

	for(iter = 0; complex_string.at(iter) != '+'; ++iter) {
		real_string += complex_string.at(iter);
	}
}

 Complex operator+(Complex & lhs_complex, Complex & rhs_complex) {
	return lhs_complex.Add(rhs_complex);
}
 Complex operator+(Complex & lhs_complex, int rhs) {
	return lhs_complex.Add(rhs);
}
 Complex operator+(Complex & lhs_complex, double rhs) {
	return lhs_complex.Add(rhs);
}


 Complex operator*(Complex & lhs_complex, Complex & rhs_complex) {
	return lhs_complex.Mul(rhs_complex);
}
 Complex operator*(Complex & lhs_complex, int rhs) {
	return lhs_complex.Mul(rhs);
}
 Complex operator*(Complex & lhs_complex, double rhs) {
	return lhs_complex.Mul(rhs);
}


istream& operator>>(istream& in, Complex& rhs) {
	double re = 0.0, im = 0.0;
	char c = 0;
	in >> c;
	if (c == '(') {
		in >> re >> c;
		if (c == ',') in >> im >> c;
		if (c == 'i') in >> c;
		if (c != ')') in.clear();
	} else {
		in.putback(c);
		in >> re;
	}
	if (in) {
		rhs = Complex(re, im);
	}
	return in;
}

ostream& operator<<(ostream& out,  Complex& rhs) {
  out << rhs.ToString();

  return out;
}