/*
 * Copyright 2018
 * Created by George E Gordon
 */

 #include <iostream>
 using std::cin;
 using std::cout;
 using std::endl;

 #include <cstdlib>
 //using rand
 //using srand

 int main(int argc, char** argv) {
   //Signed int variable to hold the input
   signed int number = 0;
   //Signed int variable to copy number for output later
   signed int number_copy = 0;
   //Signed int variable to hold the sum
   signed int sum;

   //Take in the integer being given by the user
   cin >> number;
   //Copy the number for later output
   number_copy = number;

   //Do-while loop
   do {
     //Increse the sum by adding the each individual integer from the
     // whole integer value, using modulo to grab the 10s position
     sum = sum + number % 10;
     //Divide the number by 10 to move to next 10s position
     number = number / 10;
     //When the number is equal or less than 0, end loop
   } while(number != 0);

   //Print the original number with the copy, and then print the sum
   cout << "The sum of " << number_copy << " is: " << sum << endl;

   return 0;
 }
