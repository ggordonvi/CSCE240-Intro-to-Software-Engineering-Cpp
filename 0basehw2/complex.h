/*
 * Copyright 2018
 * Created by George E Gordon
 */

 #include <cmath>
 #include <iostream>
 #include <string>
 using std::cout;
 using std::cin;
 using std::endl;
 using std::string;
 using std::to_string;
 using std::ostream;
 using std::istream;

	typedef string String;

	class Complex {
		public:

			//Default Constructor
			Complex(void);
			//Parameter: imaginary
			Complex(double);
			//Parameter: real, imaginary
			Complex(double, double);

			//Accessors and mutators
			double real(void);
			void real(double);
			double imag(void);
			void imag(double);

			//Addition prototypes
			Complex Add(Complex &);
			Complex Add(double);
			Complex Add(int);

			//Multiplication prototypes
			Complex Mul(Complex &);
			Complex Mul(double);
			Complex Mul(int);

			//To String and To Complex
			String ToString(void);
			static Complex ToComplex(String);

			//Operator Overload
			friend Complex operator+(Complex&, Complex&);
			friend Complex operator+(Complex&, int);
			friend Complex operator+(Complex&, double);
			friend Complex operator+(int, Complex&);
			friend Complex operator+(double, Complex&);

			friend Complex operator*(Complex&, Complex&);
			friend Complex operator*(Complex&, int);
			friend Complex operator*(Complex&, double);
			friend Complex operator*(int, Complex&);
			friend Complex operator*(double, Complex&);

			//Output functions
			friend ostream& operator<<(ostream&, Complex&);
			friend istream& operator>>(istream&, Complex&);
		
		private:
			double imag_;
			double real_;
	};