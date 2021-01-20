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

// away_div(num, denom) returns the division 
//  of num and denom, but will always round up
int away_div(int num, int denom) {
  if (num < 0 && denom < 0){
    if (-num <= -denom) {return 1;}
    return 1+ away_div(num-denom,denom);
  }
  if (num < 0){
    if (num >= -denom) {return -1;}
    return away_div(num+denom,denom) -1;
  }
  if (denom < 0){
    if (num <= -denom) {return -1;}
    return away_div(num+denom,denom) -1;
  }
  if (num <= denom) {return 1;}
  return 1+ away_div(num-denom,denom);
}

// abs(num) returns the absolutve 
//  value of num
int abs (int num){
  if (num < 0){return -num;}
  return num;
}
// round_nice(num, denom) returns the division 
//  of num and denom, but will always round up
//  if the remainder/denom is greater then a third
int round_nice(int num, int denom) {
 if ((abs(num)%abs(denom))*3 >= abs(denom)){
  return (away_div(num,denom)); 
 }
  return ((num-num%denom)/denom); 
}

// max(a,b) returns the larger value between
//  a and b
// requires: both a and b are integers

int max(int a, int b) {
  return (a > b)? a : b;
}

// cookie_order(mint, chocolate, vanilla) returns the number 
//  of boxes of cookies you need to buy in order to get
//  the number of cookies you want
// requires: mint,chocolate,vanilla are all non-negitive
int cookie_order(int mint, int chocolate, int vanilla) {
  return away_div(mint,22) + away_div(max(chocolate,vanilla),10);
}


// cookie_order(canadian, hawaiian, spicy
//              vegan, slices_per_pizza) 
//  returns the number of boxes of pizza such that you
//   can satsify each catigory 
// requires: canadian, hawiian, spicy, vegan all non negitive
//           slices_per_pizza even and positive

int pizza_order(int canadian, int hawaiian, int spicy, int vegan,
                int slices_per_pizza) {
  return away_div(away_div(canadian, slices_per_pizza/2)
            + away_div(hawaiian,slices_per_pizza/2)
            + away_div(spicy,slices_per_pizza/2)
         ,2) 
         + away_div(vegan,slices_per_pizza);
}

int main(void) {
  // Positive away_div Testing
  assert(away_div(4, 3) == 2);
  assert(away_div(4, 1) == 4);
  assert(away_div(7, 2) == 4);
  assert(away_div(11, 3) == 4);
  assert(away_div(0, 2) == 1);
  
  // Negative away_div Testing
  assert(away_div(-4, 3) == -2);
  assert(away_div(4, -1) == -4);
  assert(away_div(-7, -2) == 4);
  assert(away_div(-11, 3) == -4);
  assert(away_div(0, -2) == -1);
  
  // Positive round_nice Testing
  assert(round_nice(4, 3) == 2);
  assert(round_nice(7, 6) == 1);
  assert(round_nice(7, 2) == 4);
  assert(round_nice(11, 3) == 4);
  assert(round_nice(0, 2) == 0);
  
  // Negative away_div Testing
  assert(round_nice(-4, 3) == -2);
  assert(round_nice(4, -1) == -4);
  assert(round_nice(-7, -6) == 1);
  assert(round_nice(-8, 6) == -2);
  assert(round_nice(0, -2) == 0);
  
  // cookie_order Testing
  assert(cookie_order(44, 20, 20) == 4);
  assert(cookie_order(23, 20, 20) == 4);
  assert(cookie_order(44, 21, 20) == 5);
  assert(cookie_order(44, 20, 0) == 4);
  assert(cookie_order(44, 241, 20) == 27);
  assert(cookie_order(44, 20, 17) == 4);
  assert(cookie_order(1, 1, 9) == 2);
  assert(cookie_order(22, 19, 19) == 3);
  
  // pizza_order Testing
  assert(pizza_order(8, 8, 8, 8, 8) == 4);
  assert(pizza_order(2, 2, 2, 8, 8) == 3);
  assert(pizza_order(2, 4, 4, 5, 8) == 3);
  assert(pizza_order(5, 5, 6, 4, 10) == 3);
  assert(pizza_order(5, 5, 6, 4, 4) == 6);
  assert(pizza_order(9, 3, 6, 6, 6) == 4);
  

  // ADD YOUR OWN TESTS BELOW:

}
