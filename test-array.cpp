#include "object.h"  // Your file with the CwC declaration of Object
#include "string.h" // Your file with the CwC declaration of String
#include "array.h"  // Your file with the array classes
#include <math.h>
void FAIL() {   exit(1);    }
void OK(const char* m) { printf("%s\n", m); }
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
  
  delete s;
  delete t;
  delete u;

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
  
  s->add(0, 0); 
  
  t_true(s->get(0) == 0); 
  
  t->add_all(0, u);
  
  t_true(t->size() == 1); 
  
  t->clear(); 
  
  t_true(t->size() == 0); 
  t_true(s->index_of(0) == 0); 
  t_true(s->index_of(1) == 1); 
  t_true(s->remove(1) == 1); 
  t_true(u->set(0, 0) == 1); 
  t_true(u->get(0) == 0);
  t_false(u->is_empty()); 

  u->remove(0); 

  t_true(u->is_empty());

  t->clear(); 

  t_true(t->size() == 0);

  delete s;
  delete t;
  delete u;

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
 
  delete test;
  delete replaced;
  t_true(s->is_empty());
  t_true(s->size() == 0);
 
  delete s;
  delete t2;
  delete r;

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
  String* removed = s->remove(1);
  t_true(removed->equals(hello));
  String* set = u->set(0, hi);
  t_true(set->equals(hello));
  delete set;
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
 
  delete s;
  delete t;
  delete u;

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
  t_true(s->index_of(4.2f) == 0); 
  t_true(s->index_of(5.7f) == 1); 
  t_true(abs(s->remove(1) - 5.7) < 0.00001); 
  t_true(abs(u->set(0, 16) - 5.7) < 0.00001); 
  t_true(abs(u->get(0) - 16.0) < 0.00001);
  t_true(u->index_of(16.0f) == 0);
  t_false(u->is_empty()); 

  u->remove(0); 

  t_true(u->is_empty());

  u->push_back(-17.4);

  t_true(u->index_of(-17.4f) == 0);
 
  delete s;
  delete t;
  delete u;

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

/* 
 String * tsetett = new String();
 t_true(tsetett->isEmpty()); 
 t_true(tsetett->size() == 0); 
 tsetett = tsetett->concat(u);
 t_true(tsetett->size() == 10); 
 t_true(tsetett->equals(u)); 
 t_false(tsetett->isEmpty()); 

 String * test = s->clone();
 t_true(test->equals(s)); 
 t_true(test->hash() == s->hash()); 

 t_true(test->compare(s) == 0);
 t_true(test->compare(t) < 0);
 t_true(u->compare(s) > 0);
 t_false(u->compare(test) == 0);
 
 delete test;
 delete tsetett;
 delete s;
 delete t;
 delete u;
*/
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

