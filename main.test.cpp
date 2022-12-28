
#include <iostream>
#include "myString.h"

using namespace std;

#include <cstring>
#include <assert.h>

int main()
{

  //-------------------- Default CTOR() ---------
  myString A;
  cout << "(1): Default CTOR  ---------------" << endl;
  //A.PrintMe();
  cout << A << endl;
  assert(A.getLength() == 0);

  //-------------------- CTOR() with argument/parameter ---------
  char aWord[10];
  strcpy(aWord, "hello");
  myString B(aWord);
  cout << "(2): CTOR with arg ---------------" << endl;
  cout << B << endl;
  assert(B.getLength() == 5);

  //-------------------- Copy CTOR() ---------
  myString C(B);
  cout << "(3): Copy CTOR ---------------" << endl;
  cout << C << endl;
  assert(C.getLength() == 5);

  //-------------------- operator= "an array of chars" ---------
  char junk[10];
  strcpy(junk, "foobar");

  A = junk;
  cout << "------------------------------" << endl;
  cout << "(4): A = (array of chars) " << endl;
  cout << A << endl;
  assert(A.getLength() == 6);

  //-------------------- operator= "another myString object ---------
  assert(B.getLength() == 5);
  B = A;
  cout << "------------------------------" << endl;
  cout << "(5): B = A" << endl;
  cout << B << endl;
  assert(B.getLength() == 6);


  //-------------------- operator+ ---------

  myString D;

  cout << "------------------------------" << endl;
  cout << "(6): D = A + B (concat)" << endl;

  D = A + B;
  cout << "\tAfter concat: " << D << endl;
  cout << "A: " << A << "B: " << B << endl;
  assert(D.getLength() == 12);

  //-------------------- operator[] ---------

  cout << "(7): oneLetter = D[i]" << endl;
  char oneLetter;
  oneLetter = D[0];                 // initial letter
  assert(oneLetter == 'f');

  oneLetter = D[ D.getLength()-1 ];  // last letter
  assert(oneLetter == 'r');

  //--------------------  <,<=,>,>=,!=,==  ---------
  // RELATIONAL ops
  cout << "(8): Testing all relational operators" << endl;

  assert (D > B);  cout << "> ";
  assert (A >= B); cout << ">= ";
  assert (A == B); cout << "== ";
  assert (D != A); cout << "!= ";
  assert (B < D);  cout << "< ";
  assert (A <= B); cout << "<= " << endl;

// ============ * operator =================

    cout << "\n(9) multiplying: " << endl;
    myString Q;
    myString U("fooby");
    Q = (U*4);
    cout << "Q = U*4: " << Q << endl;

// =========== exponential operator ===========
    cout << "(10) testing exp operator:" << endl;

    // assign to another
    myString X;
    myString Y("aA-did this work?-zZ");
    (X^Y);
    cout << "Y pText being capitalized into X:\n" << Y;
    cout << "X: " << X << endl;


    // self assignment
    myString L("sad lowercase letters");
    cout << "Before: " << L;
    (L^L);
    cout << "After: " << L;


  cout << endl << "------------------------------------------" << endl;
  cout << "(N): Testing DTORs" << endl;
  return 0;
}
