#include "array.h"
#include "string.h"
#include <stdlib.h>
#include <iostream>

/**
 * Object: this class represents the most basic methods of an object and is intended to be
 *         extended by other classes.
 * 
 * authors: singh.kar@husky.neu.edu and haiber.ow@husky.neu.edu
 */
class ArrayTestFrame
{
public:
    Object *nothing;

    String *hello;
    String *goodbye;
    String* zebra;

    Array* empty;
    Array* tensize;
    Array* threeunsorted;
    Array* threesorted;
    Array* halfempty;

    ArrayTestFrame()
    {
        setup();
    }
     
    ~ArrayTestFrame(){
        delete nothing;
        delete hello;
        delete goodbye;
        delete empty;
        delete tensize;
    }
    
    void setup()
    {
        nothing = new Object();

        hello = new String("hello");
        goodbye = new String("goodbye");
        zebra = new String("zebra");

        empty = new Array(0);
        tensize = new Array(10);
        threeunsorted = new Array(3);
        threesorted = new Array(3);
        threeunsorted = new Array(3);
        halfempty = new Array(2);

        threesorted->add(0, goodbye);
        threesorted->add(1, hello);
        threesorted->add(2, zebra);

        threeunsorted->add(0, zebra);
        threeunsorted->add(1, hello);
        threeunsorted->add(2, goodbye);

        halfempty->add(0, hello);
        halfempty->add(1, goodbye);
    }

    void FAIL()
    {
        exit(1);
    }

    void OK(const char *m)
    { /** print m */
        std::cout << m << "\n";
    }

    void t_true(bool p)
    {
        if (!p)
            FAIL();
    }

    void t_false(bool p)
    {
        if (p)
            FAIL();
    }

    void testSize(){
        setup();
        t_true(empty->size() == 0);
        t_true(tensize->size() == 10);
        OK("Size Test Passed");
    }

    void testLength(){
        setup();
        t_true(threeunsorted->length() == 3);
        t_true(halfempty->length() == 2);
        OK("Length Test Passed");
    }

    void testAdd(){
        setup();
        
    }

    void testRemove(){
        setup();
    }

    void testGet(){
        setup();
    }

    void testSort(){
        setup();
    }
};

int main(){
    ArrayTestFrame* test = new ArrayTestFrame();
    test->testAdd();
    test->testGet();
    test->testLength();
    test->testRemove();
    test->testSize();
    test->testSort();
    delete test;
    return 1;
};