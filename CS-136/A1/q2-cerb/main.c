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

// qualify_cerb_logical(age, stopped_working,
//                      quit_voluntarily, ei_eligible
//                      income_12months, income_4weeks) 
//  returns if a person can qualify for CERB
//   given some of there information, uses only
//   logical opperators.
bool qualify_cerb_logical(int age, bool stopped_working, 
                          bool quit_voluntarily,bool ei_eligible,
                          int income_12months, int income_4weeks) {
  return (age >= 15) && (income_12months >= 5000) && 
         (income_4weeks < 1000) && 
         (ei_eligible || (stopped_working && !quit_voluntarily));
}

//  qualify_cerb_if    (age, stopped_working,
//                      quit_voluntarily, ei_eligible
//                      income_12months, income_4weeks) 
//  returns if a person can qualify for CERB
//   given some of there information, uses only
//   ifs.

bool qualify_cerb_if(int age, bool stopped_working,
                     bool quit_voluntarily, bool ei_eligible,
                     int income_12months, int income_4weeks) {
  if (age < 15) {return false;}
  if (income_12months < 5000) {return false;}
  if (income_4weeks >= 1000) {return false;}
  if (ei_eligible) {return true;}
  if (stopped_working){
    if (quit_voluntarily) {return false;}
    else {return true;}
  }
  return false;
}


int main(void) {
  
  // Failure Cases:
  assert(!qualify_cerb_logical(22, true, false, true, 5000, 1000));
  assert(!qualify_cerb_logical(22, true, false, true, 4999, 500));
  assert(!qualify_cerb_logical(14, true, false, true, 5999, 500));
  assert(!qualify_cerb_logical(15, true, true, false, 5999, 600));
  assert(!qualify_cerb_logical(15, false, true, false, 5999, 600));
  
  assert(!qualify_cerb_if(22, true, false, true, 5000, 1000));
  assert(!qualify_cerb_if(22, true, false, true, 4999, 500));
  assert(!qualify_cerb_if(14, true, false, true, 5999, 500));
  assert(!qualify_cerb_if(15, true, true, false, 5999, 600));
  assert(!qualify_cerb_if(15, false, true, false, 5999, 600));
  
  // General Cases:
  assert(qualify_cerb_logical(22, true, false, true, 5000, 512));
  assert(qualify_cerb_logical(2651, true, false, true, 52151515, 500));
  assert(qualify_cerb_logical(51, true, true, true, 5999, 500));
  assert(qualify_cerb_logical(15, true, false, false, 5999, 600));
  assert(qualify_cerb_logical(15, false, true, true, 5999, 600));
  
  assert(!qualify_cerb_if(22, true, false, true, 5000, 1000));
  assert(!qualify_cerb_if(22, true, false, true, 4999, 500));
  assert(!qualify_cerb_if(14, true, false, true, 5999, 500));
  assert(!qualify_cerb_if(15, true, true, false, 5999, 600));
  assert(!qualify_cerb_if(15, false, true, false, 5999, 600));

  // ADD YOUR OWN TESTS BELOW:

}
