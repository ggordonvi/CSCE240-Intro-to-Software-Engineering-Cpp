/* Copyright 2018 */
#ifndef TEST_H_  // NOLINT
#define TEST_H_  // NOLINT

#include <ctime>
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::to_string;
typedef std::string String;
#include <sstream>
typedef std::stringstream StrStream;

#include "complex.h"  // NOLINT

bool TestToComplex();
bool TestComplexLT();
bool TestComplex();
bool TestIsComplex();
bool TestIsComplexStream();
bool TestCinOp();


/* Use to log result of Unit Test in passed and failed vars */
void Run(bool result, int* passed, int* failed);

#endif  // NOLINT