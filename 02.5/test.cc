/* Copyright 2018 */
#include "test.h"  // NOLINT

bool TestToComplex() {
  cout << "----Testing To Complex----" << endl;
  bool valid = false;

  Complex new_complex;
  Complex a_complex;
  String complex_string = "(2.2+3.5i)";
  cout << "Complex string (2.2+3.5i) to complex... " << endl;
  new_complex = a_complex.ToComplex(complex_string);
  cout << "Real: " << new_complex.real() << ", " << "Imag: " << new_complex.imag() << endl;
  if(new_complex.real() == 2.2 && new_complex.imag() == 3.5)
  {
    valid = true;
  }

  String complex_string1 = "(3.2223+4.2233i)";
  cout << "Complex string (3.2223+4.2233i) to complex... " << endl;
  new_complex = a_complex.ToComplex(complex_string1);
  cout << "Real: " << new_complex.real() << ", " << "Imag: " << new_complex.imag() << endl;
  if(new_complex.real() == 2.2 && new_complex.imag() == 3.5)
  {
    valid = true;
  }

  String complex_string2 = "(2+5i)";
  cout << "Complex string (2+5i) to complex... " << endl;
  new_complex = a_complex.ToComplex(complex_string2);
  cout << "Real: " << new_complex.real() << ", " << "Imag: " << new_complex.imag() << endl;
  if(new_complex.real() == 2.2 && new_complex.imag() == 3.5)
  {
    valid = true;
  }

  String complex_string3 = "(2.2)";
  cout << "Complex string (2.2) to complex... " << endl;
  new_complex = a_complex.ToComplex(complex_string3);
  cout << "Real: " << new_complex.real() << ", " << "Imag: " << new_complex.imag() << endl;
  if(new_complex.real() == 2.2 && new_complex.imag() == 3.5)
  {
    valid = true;
  }

  String complex_string4 = "(3.5i)";
  cout << "Complex string (3.5i) to complex... " << endl;
  new_complex = a_complex.ToComplex(complex_string4);
  cout << "Real: " << new_complex.real() << ", " << "Imag: " << new_complex.imag() << endl;
  if(new_complex.real() == 2.2 && new_complex.imag() == 3.5)
  {
    valid = true;
  }

  cout << "Testing Errors -- blocked out, assert used" << endl;
/*
  cout << "Testing: (i)" << endl;
  String wrong_complex = "(i)";
  new_complex = a_complex.ToComplex(wrong_complex);
  cout << "Real: " << new_complex.real() << ", " << "Imag: " << new_complex.imag() << endl;
  if(new_complex.real() == 2.0 && new_complex.imag() == 3.2)
  {
    valid = true;
  }
  */
  /*
  cout << "Testing missing open paran: 2.0 - 3.2i)" << endl;
  String wrong_complex = "2.0 - 3.2i)";
  new_complex = a_complex.ToComplex(wrong_complex);
  cout << "Real: " << new_complex.real() << ", " << "Imag: " << new_complex.imag() << endl;
  if(new_complex.real() == 2.0 && new_complex.imag() == 3.2)
  {
    valid = true;
  }
  */
  /*
  cout << "Testing missing close paran: (2.0 - 3.2i" << endl;
  String wrong_complex2 = "(2.0 - 3.2i";
  new_complex = a_complex.ToComplex(wrong_complex2);
  cout << "Real: " << new_complex.real() << ", " << "Imag: " << new_complex.imag() << endl;
  if(new_complex.real() == 2.0 && new_complex.imag() == 3.2)
  {
    valid = true;
  }
  */
  /*
  cout << "Testing tab error: (2.0 - 3.2i)" << endl;
  String wrong_complex3 = "(2.0 - \t 3.2i)";
  new_complex = a_complex.ToComplex(wrong_complex3);
  cout << "Real: " << new_complex.real() << ", " << "Imag: " << new_complex.imag() << endl;
  if(new_complex.real() == 2.0 && new_complex.imag() == 3.2)
  {
    valid = true;
  }
  */
  /*
  cout << "Testing new line error: (2.0/n - 3.2i)" << endl;
  String wrong_complex4 = "(2.0 \n - 3.2i)";
  new_complex = a_complex.ToComplex(wrong_complex4);
  cout << "Real: " << new_complex.real() << ", " << "Imag: " << new_complex.imag() << endl;
  if(new_complex.real() == 2.0 && new_complex.imag() == 3.2)
  {
    valid = true;
  }
  */
  
  

  return valid;
}

bool TestComplexLT() {
  cout << "----Testing Less Than----" << endl;
  bool valid = false;
  Complex complex_a = Complex(1.0,2.0);
  Complex complex_b = Complex(2.0,5.0);
  Complex complex_c = Complex(7.0,3.0);
  Complex complex_d = Complex(2.0,5.0);
  double db_s = 1.0;
  double db_l = 10.0;
  int int_s = 1;
  int int_l = 10;

  cout << "LT(complex)" << " : ";
  if(complex_a.LT(complex_b)) {
	  valid = true;
	  cout << "True" << endl;
  } else {
	  cout << "False" << endl;
  }
  cout << "LT(dobule)" << " : ";
  if(complex_c.LT(db_l)) {
	  valid = true;
	  cout << "True" << endl;
  } else {
	  cout << "False" << endl;
  }
  cout << "LT(int)" << " : ";
  if(complex_c.LT(int_l)) {
	  valid = true;
	  cout << "True" << endl;
  } else {
	  cout << "False" << endl;
  }
  cout << "< complex" << " : ";
  if(complex_a < complex_c) {
	  valid = true;
	  cout << "True" << endl;
  } else {
	  cout << "False" << endl;
  }
  cout << "< double" << " : ";
  if(complex_a < db_l) {
	  valid = true;
	  cout << "True" << endl;
  } else {
	  cout << "False" << endl;
  }
  cout << "< int" << " : ";
  if(complex_a < int_l) {
	  valid = true;
	  cout << "True" << endl;
  } else {
	  cout << "False" << endl;
  }

  return valid;
}

bool TestComplex() {
  cout << "----Testing Complex----" << endl;
  bool valid = false;
  Complex complex_x = Complex(10.0);
  Complex complex_y = Complex(3.0, 5.0);


  cout << "Complex(10.0) should be (0, 10) : ";
  if(complex_x.imag() == 10) {
	  valid = true;
	  cout << "True" << endl;
  } else {
	  cout << "False" << endl;
  }
  cout << "Complex(3.0, 5.0) should be (3, 5) : ";
  if(complex_y.real() == 3 && complex_y.imag() == 5) {
	  valid = true;
	  cout << "True" << endl;
  } else {
	  cout << "False" << endl;
  }

  complex_x.real(5.0);
  cout << "Complex(0, 10) changing real to 5.0: (5, 10) : ";
  if(complex_x.real() == 5 && complex_x.imag() == 10) {
	  valid = true;
	  cout << "True" << endl;
  } else {
	  cout << "False" << endl;
  }complex_x.imag(2.0);
  cout << "Complex(5, 10) changing imag to 2.0: (5, 2) : ";
  if(complex_x.real() == 5 && complex_x.imag() == 2) {
	  valid = true;
	  cout << "True" << endl;
  } else {
	  cout << "False" << endl;
  }
  
  return valid;
}

bool TestIsComplex() {
  cout << "----Testing Is Complex----" << endl;
  bool valid = false;
  bool validcomplex = true;
  
  String complex1 = "(2.0 + 3.0i)";
  String complex2 = "2.0 + 3.0i)";
  String complex3 = "(2.0 + 3.0i";
  String complex4 = "(2.0\t + 3.0i)";
  String complex5 = "(2.0\n + 3.0i)";
  String complex6 = "(2.0)";
  String complex7 = "(3.0i)";
  String complex8 = "(2.2i + 2.5i)";
  String complex9 = "(i)";
  String complex10 = "(2.2 + - 2.5i)";
  String complex11 = "((2.2) - 2.5i)";

  if (Complex::IsComplex(complex1)) {
    valid = true;
    cout << "(2.0 + 3.0i) is proper." << endl;
  } else {
    cout << "(2.0 + 3.0i) is not proper" << endl;
  }
  if (Complex::IsComplex(complex2)) {
    cout << "2.0 + 3.0i) is proper." << endl;
  } else {
    valid = true;
    cout << "2.0 + 3.0i) is not proper" << endl;
  }
  if (Complex::IsComplex(complex3)) {
    cout << "(2.0 + 3.0i is proper." << endl;
  } else {
    valid = true;
    cout << "(2.0 + 3.0i is not proper" << endl;
  }
  if (Complex::IsComplex(complex4)) {
    cout << "(2.0\t + 3.0i) is proper." << endl;
  } else {
    valid = true;
    cout << "(2.0\t + 3.0i) is not proper" << endl;
  }
  if (Complex::IsComplex(complex5)) {
    cout << "(2.0\n + 3.0i) is proper." << endl;
  } else {
    valid = true;
    cout << "(2.0\n + 3.0i) is not proper" << endl;
  }
  if (Complex::IsComplex(complex6)) {
    valid = true;
    cout << "(2.0) is proper." << endl;
  } else {
    cout << "(2.0) is not proper" << endl;
  }
  if (Complex::IsComplex(complex7)) {
    valid = true;
    cout << "(3.0i) is proper." << endl;
  } else {
    cout << "(3.0i) is not proper" << endl;
  }
  if (Complex::IsComplex(complex8)) {
    cout << "(2.2i + 2.5i) is proper." << endl;
  } else {
    valid = true;
    cout << "(2.2i + 2.5i) is not proper" << endl;
  }
  if (Complex::IsComplex(complex9)) {
    valid = true;
    cout << "(i) is proper." << endl;
  } else {
    cout << "(i) is not proper" << endl;
  }
  if (Complex::IsComplex(complex10)) {
    cout << "(2.2 + - 2.5i) is proper." << endl;
  } else {
    valid = true;
    cout << "(2.2 + - 2.5i) is not proper" << endl;
  }
  if (Complex::IsComplex(complex11)) {
    cout << "((2.2) + 2.5i) is proper." << endl;
  } else {
    valid = true;
    cout << "((2.2) + 2.5i) is not proper" << endl;
  }
  
  return valid;
}

bool TestIsComplexStream() {
  cout << "----Testing Is Complex Stream----" << endl;
  bool valid = false;
  StrStream sstr("(3.1+2.5i)");
  cout << "String stream contains complex: (3.1+2.5i)" << endl;
  
  if (Complex::IsComplex(sstr) == true) {
    valid = true;
  }
  //cout << cin.getline() << endl;
  //REVERSE PUT BACK stream
  cout << sstr.str() << endl;

  return valid;
}

bool TestCinOp() {
  cout << "----Testing >> Operator----" << endl;
  bool valid = false;
  StrStream sstr("(2.2-3.4i)");
  Complex complex_a;
  Complex complex_b;

  sstr >> complex_a;
  //String thestring = sstr.str();
  //cout << thestring << endl;

  cout << "String stream of (2.2-3.4i) to complex..." << endl;
  cout << "Real: " << complex_a.real() << " Imag: " << complex_a.imag() << endl;
  if(complex_a.real() == 2.2 && complex_a.imag() == -3.4) {
    valid = true;
    cout << "Complex a is right!" << endl;
  }
  

  return valid;
}


/* Improve test speed by creating one Rational and passing it around */
int main(int argc, char* argv[]) {
  srand(time(nullptr));  // pass nullptr to time to get return value

  cout << "Testing Complex Class\n" << endl;

  int passed = 0, failed = 0;
  String align = "  ";

  Run(TestToComplex(), &passed, &failed);
  cout << passed << " of " << (passed + failed) << " passed\n" << endl;
  Run(TestComplexLT(), &passed, &failed);
  cout << passed << " of " << (passed + failed) << " passed\n" << endl;
  Run(TestComplex(), &passed, &failed);
  cout << passed << " of " << (passed + failed) << " passed\n" << endl;
  Run(TestIsComplex(), &passed, &failed);
  cout << passed << " of " << (passed + failed) << " passed\n" << endl;
  Run(TestIsComplexStream(), &passed, &failed);
  cout << passed << " of " << (passed + failed) << " passed\n" << endl;
  Run(TestCinOp(), &passed, &failed);
  cout << passed << " of " << (passed + failed) << " passed\n" << endl;

  return 0;
}

void Run(bool result, int* passed, int* failed) {
  if (result)
    ++(*passed);

  else
    ++(*failed);
}