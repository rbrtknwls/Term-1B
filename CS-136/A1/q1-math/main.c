///////////////////////////////////////////////////////////////////////////// 
// INTEGRITY STATEMENT (v3)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement:
// https://student.cs.uwaterloo.ca/~cs136/current/assignments/integrity.shtml
/////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with: 
 
// None 
//  
// Name: Robert Knowles 
// login ID: r2knowle
///////////////////////////////////////////////////////////////////////////// 

#include "cs136.h"

// note: All of the functions are currently returning 4.
//       This is often done (early in the course) so that your code
//       will "run" and pass the public tests before you have
//       implemented all of the functions.

//       You should replace each "return 4;" with your implementation


// max(a,b) returns the larger value between
//  a and b
// requires: both a and b are integers

int max(int a, int b) {
  return (a > b)? a : b;
}

// expt(a,b) returns the value of b^n
// requires: requires n is non-negitive
int expt(int b, int n) {
  if (n <= 0){
    return (1);
  }
  return (b * expt(b, n-1));
}

// sqrt_int(n, i) returns the integer square root of n
//  by rounding down and using the iterator i
// requires: requires n is non-negitive
int sqrt_down(int n, int i){
  if (i*i <= n && n < (i+1)*(i+1) ){
    return i;
  }
  return sqrt_down(n, i+1);
}

// sqrt_int(n) returns the integer square root of n
//  by rounding down, using sqrt_down()
// requires: requires n is non-negitive
int sqrt_int(int n) {
  return sqrt_down(n,0);
}
      
// log_2_up(n, i) returns the second log of n
//  by rounding up, using iterator i
// requires: requires n is greater then 0
int log_2_up(int n, int i) {
  if (expt(2,i-1) <= n && n <= expt(2,i)){
    return i;
  }
  return log_2_up(n,i+1);
} 

// log_2(n) returns the second log of n
//  by rounding up, using log_2_up()
// requires: requires n is greater then 0
int log_2(int n) {
  return log_2_up(n, 0);
}


int main(void) {
  
  // Max Tests (Edge):
  assert(max(-1, 4) == 4);
  assert(max(-1, -5) == -1);
  assert(max(0, 0) == 0);
  
  // Max Tests (Normal):
  assert(max(2, 5) == 5);
  assert(max(9999, 9998) == 9999);
  assert(max(12, 12) == 12);
  assert(max(-12, 12) == 12);
  
  // Expt Tests (Edge):
  assert(expt(-1, 0) == 1);
  assert(expt(0, 0) == 1);
  assert(expt(-3, 3) == -27);
  
  // Expt Tests (Normal):
  assert(expt(2, 4) == 16);
  assert(expt(1, 15) == 1);
  assert(expt(-3, 4) == 81);
  assert(expt(-4, 2) == 16);
  assert(expt(2, 2) == 4);
  
  // sqrt_int Tests (Edge):
  assert(sqrt_int(0) == 0);
  assert(sqrt_int(1) == 1);
  
  // sqrt_int Tests (Normal):
  assert(sqrt_int(2) == 1);
  assert(sqrt_int(4) == 2);
  assert(sqrt_int(8) == 2);
  assert(sqrt_int(9) == 3);
  assert(sqrt_int(16) == 4);
  
  // log_2 Tests (Edge):
  assert(log_2(1) == 0);
  assert(log_2(2) == 1);
  
  // log_2 Tests (Normal):
  assert(log_2(3) == 2);
  assert(log_2(4) == 2);
  assert(log_2(6) == 3);
  assert(log_2(9) == 4);
  assert(log_2(16) == 4);
  assert(log_2(18) == 5);
  
  // ADD YOUR OWN TESTS BELOW:
  
  return 0;
  
}
