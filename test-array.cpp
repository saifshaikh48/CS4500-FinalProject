// #pragma once
// #include "array.h"
// #include "string.h"
// #include <stdlib.h>
// #include <iostream>

// /**
//  * ArrayTestFrame: this class represents a series of tests to verify that the Array class 
//  *                 works as inteded
//  * 
//  * authors: singh.kar@husky.neu.edu and haiber.ow@husky.neu.edu
//  */
// class ArrayTestFrame
// {
// public:
//     Object *nothing; // blank object

//     String *hello;   // String containing "hello"
//     String *goodbye; // String containing "goodbye"
//     String *zebra;   // String containing "zebra"

//     Array *empty;         // Blank Array of size 0
//     Array *tensize;       // Blank Array of size 10
//     Array *threeunsorted; // Unsorted Array of size 3 with 3 Strings in it
//     Array *threesorted;   // Sorted Array of size 3 with 3 String in it
//     Array *halfempty;     // Array of size 4 with 2 Strings in it

//     /**
//      * Constructor for the test class which sets the base values for the tests
//      */
//     ArrayTestFrame()
//     {
//         setup();
//     }

//     /**
//      * Destructor for the ArrayTestFrame. 
//      */
//     ~ArrayTestFrame()
//     {
//         delete nothing;
//         delete hello;
//         delete goodbye;
//         delete zebra;
//         delete empty;
//         delete tensize;
//         delete threeunsorted;
//         delete threesorted;
//         delete halfempty;
//     }

//     /**
//      * Sets the initial values for the fields in the class. 
//      */
//     void setup()
//     {
//         nothing = new Object();

//         hello = new String("hello");
//         goodbye = new String("goodbye");
//         zebra = new String("zebra");

//         empty = new Array(0);
//         tensize = new Array(10);
//         threeunsorted = new Array(3);
//         threesorted = new Array(3);
//         threeunsorted = new Array(3);
//         halfempty = new Array(2);

//         threesorted->add(0, goodbye);
//         threesorted->add(1, hello);
//         threesorted->add(2, zebra);

//         threeunsorted->add(0, zebra);
//         threeunsorted->add(1, hello);
//         threeunsorted->add(2, goodbye);

//         halfempty->add(0, hello);
//         halfempty->add(1, goodbye);
//     }

//     /**
//      * Exits the program with an exit code for not succesful. 
//      */
//     void FAIL()
//     {
//         exit(1);
//     }

//     /**
//      * Prints a message representing all of the tests having passed in the test method.
//      */
//     void OK(const char *m)
//     { /** print m */
//         std::cout << m << "\n";
//     }

//     /**
//      * Triggers the fail method if the passed in value is not true.
//      */
//     void t_true(bool p)
//     {
//         if (!p)
//             FAIL();
//     }

//     /**
//      * Triggers the fail method if the passed in value is not false.
//      */
//     void t_false(bool p)
//     {
//         if (p)
//             FAIL();
//     }

//     /**
//      * Series of tests to verify that the size method of the Array class works correctly. 
//      * 
//      * Prints "Size Test Passed" if all tests passed, exits otherwise. 
//      */
//     void testSize()
//     {
//         setup();
//         t_true(empty->size() == 0);
//         t_true(tensize->size() == 10);
//         OK("Size Test Passed");
//     }

//     /**
//      * Series of tests to verify that the length method of the Array class works correctly.
//      * 
//      * Prints "Length Test Passed" if all tests passed, exits otherwise. 
//      */
//     void testLength()
//     {
//         setup();
//         t_true(threeunsorted->length() == 3);
//         t_true(halfempty->length() == 2);
//         OK("Length Test Passed");
//     }

//     *
//      * Series of tests to verify that the add method of the Array class works correctly.
//      * 
//      * Prints "Add Test Passed" if all tests passed, exits otherwise.
     
//     void testAdd()
//     {
//         setup();
//         tensize->add(4, hello);
//         t_true(tensize->get(4)->equals(hello));

//         OK("Add Test Passed");
//     }

//     /**
//      * Series of tests to verify that the remove method of the Array class works correctly.
//      * 
//      * Prints "Remove Tests Passed" if all tests passed, exits otherwise.
//      */
//     void testRemove()
//     {
//         setup();
//         tensize->add(4, hello);
//         t_true(tensize->get(4)->equals(hello));

//         tensize->remove(4);
//         t_true(tensize->get(4)->equals(nothing));

//         OK("Remove Tests Passed");
//     }

//     /**
//      * Series of tests to verify that the get method of the Array class works crrectly.
//      * 
//      * Prints "Get Tests Passed" if all tests passed, exits otherwise. 
//      */
//     void testGet()
//     {
//         setup();
//         t_true(threesorted->get(1)->equals(hello));

//         OK("Get Tests Passed");
//     }

//     /**
//      * Test to verify that the Array class sorts an Array correctly if the sort method is called. 
//      * 
//      * Prints "Sort Test Passed" if the test is passed, exits otherwise.
//      */
//     void testSort()
//     {
//         setup();

//         t_true(threeunsorted->get(0)->equals(zebra));
//         t_true(threeunsorted->get(1)->equals(hello));
//         t_true(threeunsorted->get(2)->equals(goodbye));

//         threeunsorted->sort();

//         t_true(threeunsorted->get(0)->equals(goodbye));
//         t_true(threeunsorted->get(1)->equals(hello));
//         t_true(threeunsorted->get(2)->equals(zebra));

//         OK("Sort Test Passed");
//     }

//     /**
//      * Test to verify that the Array class keeps a sorted list sorted if the sort method is called on it. 
//      * 
//      * Prints "Already Sorted Array Test Passed" if the test is passed, exits otherwise. 
//      */
//     void testAlreadySorted()
//     {
//         setup();

//         t_true(threesorted->get(0)->equals(goodbye));
//         t_true(threesorted->get(1)->equals(hello));
//         t_true(threesorted->get(2)->equals(zebra));

//         threesorted->sort();

//         t_true(threesorted->get(0)->equals(goodbye));
//         t_true(threesorted->get(1)->equals(hello));
//         t_true(threesorted->get(2)->equals(zebra));

//         OK("Already Sorted Array Test Passed");
//     }

//     /**
//      * Test to verify that the equals function can tell when two arrays are equal and when they are not. 
//      * 
//      * Prints "Equals Test Passed" if the test is passed, exits otherwise.
//      */
//     void testEquals()
//     {
//         setup();
//         t_true(threeunsorted->equals(threeunsorted));
//         t_false(threeunsorted->equals(threesorted));
//         OK("Equals Test Passed");
//     }

//     /**
//      * Test to verify that the hash function returns the correct hash value when called.
//      * 
//      * Prints "Hash Test Passed" if the test is passed, exits otherwise.
//      */
//     void testHash()
//     {
//         setup();
//         t_true(threesorted->hash() == threesorted->hash());
//         t_false(threesorted->hash() == threeunsorted->hash());
//         OK("Hash Test Passed");
//     }
// };

// /**
//  * Runs the tests in the ArrayTestFrame class. 
//  */
// int main()
// {
//     ArrayTestFrame *test = new ArrayTestFrame();
//     test->testAdd();
//     test->testGet();
//     test->testLength();
//     test->testRemove();
//     test->testSize();
//     test->testSort();
//     test->testAlreadySorted();
//     test->testEquals();
//     test->testHash();
//     delete test;
//     return 0;
// };
#include "object.h"  // Your file with the CwC declaration of Object
#include "string.h" // Your file with the CwC declaration of String
#include "array.h"  // Your file with the array classes
#include <math.h>
#include <iostream>

void FAIL() {   exit(1);    }
void OK(const char* m) { printf("%s\n",m); }
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }
 
void test1() {
  
  IntArray * s = new IntArray();
  IntArray * t = new IntArray();
  IntArray * u = new IntArray();

  u->push_back(5);
  
  t_true(s->equals(s));
  t_true(s->equals(t));
  t_false(s->equals(u));
  
  s->push_back(5);
  
  t_true(s->hash() == u->hash());
  t_true(s->equals(u));
  
  s->add(0, 4); 
  
  t_true(s->get(0) == 4); 
  
  t->add_all(0, u);
  
  t_true(t->size() == 1); 
  
  t->clear(); 
  
  t_true(t->size() == 0); 
  t_true(s->index_of(4) == 0); 
  t_true(s->index_of(5) == 1); 
  t_true(s->remove(1) == 5); 
  t_true(u->set(0, 7) == 5); 
  t_false(u->is_empty()); 

  u->remove(0); 

  t_true(u->is_empty());

  u->push_back(-25);

  t_true(u->get(0) == -25);

  OK("1");
}
 
void test2() {
  BoolArray * s = new BoolArray();
  BoolArray * t = new BoolArray();
  BoolArray * u = new BoolArray();
  
  u->push_back(1);
  
  t_true(s->equals(s));
  t_true(s->equals(t));
  t_false(s->equals(u));
  
  s->push_back(1);
  
  t_true(s->hash() == u->hash());
  t_true(s->equals(u));
  
  s->add(0, false); 
  
  t_true(s->get(0) == false); 
  
  t->add_all(0, u);
  
  t_true(t->size() == 1); 
  
  t->clear(); 
  
  t_true(t->size() == 0); 
  t_true(s->index_of(0) == false); 
  t_true(s->index_of(1) == true); 
  t_true(s->remove(1) == true); 
  t_true(u->set(0, false) == true); 
  t_true(u->get(0) == false);
  t_false(u->is_empty()); 

  u->remove(0); 

  t_true(u->is_empty());

  t->clear(); 

  t_true(t->size() == 0);

  OK("2");
}
 
void test3() {
  StrArray * s = new StrArray();
  String* t = new String("Test");
  String* t2 = new String("Test2");
  String* t3 = new String("Test3");
  String* r = new String("replaced");

  s->add(0, t);
  String* test = s->remove(0);
  s->add(0, t2); 
  s->push_back(t3);
  String* replaced = s->set(1, r);
  s->clear();
  t_true(test->equals(t));
  t_true(replaced->equals(t3));
  t_true(s->is_empty());
  t_true(s->size() == 0);
  OK("3");
}

void test4() {
  StrArray * s = new StrArray();
  StrArray * t = new StrArray();
  StrArray * u = new StrArray();
  
  String* hi = new String("hi");
  String* hello = new String("hello");

  u->push_back(hello);
  
  t_true(s->equals(s));
  t_true(s->equals(t));
  t_false(s->equals(u));
  
  s->add(0,hello);
  
  t_true(s->hash() == u->hash());
  t_true(s->equals(u));
  
  s->add(0, hi); 
  
  t_true(s->get(0)->equals(hi)); 
  
  t->add_all(0, u);
  
  t_true(t->size() == 1); 
  
  t->clear(); 
  
  t_true(t->size() == 0); 
  t_true(s->index_of(hi) == 0); 
  t_true(s->index_of(hello)== 1); 
  t_true(s->remove(1)->equals(hello)); 
  t_true(u->set(0, hi)->equals(hello)); 
  t_true(u->get(0)->equals(hi));
  t_false(u->is_empty()); 

  u->remove(0); 

  t_true(u->is_empty());

  t->clear(); 

  String* five = new String("five");
  t->add(0, five); 
  t->add(1, five); //this add behaves similar to push_back
  t->add(1, five); 

  t_true(t->size() == 3);

  OK("4");
}
 
void test5() {
  FloatArray * s = new FloatArray();
  FloatArray * t = new FloatArray();
  FloatArray * u = new FloatArray();
  
  u->push_back(5.7);
  
  t_true(s->equals(s));
  t_true(s->equals(t));
  t_false(s->equals(u));
  
  s->push_back(5.7);
  
  t_true(s->hash() == u->hash());
  t_true(s->equals(u));

  s->add(0, 4.2); 

  t_true(abs(s->get(0) - 4.2) < 0.00001); 

  t->add_all(0, u);

  t_true(t->size() == 1); 

  t->clear(); 
  
  t_true(t->size() == 0); 
  t_true(s->index_of(4.2) == 0); 
  t_true(s->index_of(5.7) == 1); 
  t_true(abs(s->remove(1) - 5.7) < 0.00001); 
  t_true(abs(u->set(0, 16) - 5.7) < 0.00001); 
  t_true(abs(u->get(0) - 16.0) < 0.00001);
  t_true(u->index_of(16) == 0);
  t_false(u->is_empty()); 

  u->remove(0); 

  t_true(u->is_empty());

  u->push_back(-17.4);

  t_true(u->index_of(-17.4) == 0);

  OK("5");
}

void test6() {
 String * s = new String("Hello");
 String * t = new String("World");
 String * u = s->concat(t);
 t_true(s->equals(s));
 t_false(s->equals(t));
 t_false(s->equals(u));

 t_true(u->size() == 10); 
 t_true(s->charAt(2) == s->charAt(3));
 t_true(s->charAt(0) == 'H'); 
 t_true(s->charAt(3) == t->charAt(3));

 
 String * tsetett = new String();
 t_true(tsetett->isEmpty()); 
 t_true(tsetett->size() == 0); 
 tsetett = tsetett->concat(u);
 t_true(tsetett->size() == 10); 
 t_true(tsetett->equals(u)); 
 t_false(tsetett->isEmpty()); 

 String * test = s->clone();
 OK("6");
 t_true(test->equals(s)); 
 t_true(test->hash() == s->hash()); 

 t_true(test->compare(s) == 0);
 t_true(test->compare(t) < 0);
 t_true(u->compare(s) > 0);
 t_false(u->compare(test) == 0);

 OK("6");
}
 
int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  return 0;
}