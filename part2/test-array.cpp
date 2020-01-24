#include "array.h"
#include "string.h"
#include <stdlib.h>
#include <iostream>

/**
 * ArrayTestFrame: this class represents a series of tests to verify that the Array class 
 *                 works as inteded
 * 
 * authors: singh.kar@husky.neu.edu and haiber.ow@husky.neu.edu
 */
class ArrayTestFrame
{
public:
    Object *nothing; // blank object

    String *hello; // String containing "hello"
    String *goodbye; // String containing "goodbye"
    String* zebra; // String containing "zebra"

    Array* empty; // Blank Array of size 0
    Array* tensize; // Blank Array of size 10
    Array* threeunsorted; // Unsorted Array of size 3 with 3 Strings in it
    Array* threesorted; // Sorted Array of size 3 with 3 String in it 
    Array* halfempty; // Array of size 4 with 2 Strings in it

    /**
     * Constructor for the test class which sets the base values for the tests
     */
    ArrayTestFrame()
    {
        setup();
    }
     
    /**
     * Destructor for the ArrayTestFrame. 
     */
    ~ArrayTestFrame(){
        delete nothing;
        delete hello;
        delete goodbye;
        delete zebra;
        delete empty;
        delete tensize;
        delete threeunsorted;
        delete threesorted;
        delete halfempty;
    }
    
    /**
     * Sets the initial values for the fields in the class. 
     */
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

    /**
     * Exits the program with an exit code for not succesful. 
     */
    void FAIL()
    {
        exit(1);
    }

    /**
     * Prints a message representing all of the tests having passed in the test method.
     */
    void OK(const char *m)
    { /** print m */
        std::cout << m << "\n";
    }

    /**
     * Triggers the fail method if the passed in value is not true.
     */
    void t_true(bool p)
    {
        if (!p)
            FAIL();
    }

    /**
     * Triggers the fail method if the passed in value is not false.
     */
    void t_false(bool p)
    {
        if (p)
            FAIL();
    }

    /**
     * Series of tests to verify that the size method of the Array class works correctly. 
     * 
     * Prints "Size Test Passed" if all tests were passed, exits otherwise. 
     */
    void testSize(){
        setup();
        t_true(empty->size() == 0);
        t_true(tensize->size() == 10);
        OK("Size Test Passed");
    }

    /**
     * Series of tests to verify that the length method of the Array class works correctly.
     * 
     * Prints "Length Test Passed" if all tests were passed, exits otherwise. 
     */
    void testLength(){
        setup();
        t_true(threeunsorted->length() == 3);
        t_true(halfempty->length() == 2);
        OK("Length Test Passed");
    }

    /**
     * Series of tests to verify that the add method of the Array class works correctly.
     * 
     * Prints "Add Test Passed" if all tests were passed, exits otherwise.
     */
    void testAdd(){
        setup();
        tensize->add(4, hello);
        t_true(tensize->get(4)->equals(hello));
        
        OK("Add Test Passed");
    }

    void testRemove(){
        setup();
        tensize->add(4,hello);
        t_true(tensize->get(4)->equals(hello));

        tensize->remove(4);
        t_true(tensize->get(4)->equals(nothing));

        OK("Remove Tests Passed");
    }

    void testGet(){
        setup();
        t_true(threesorted->get(1)->equals(hello));

        OK("Get Tests Passed");
    }

    /**
     * Test to verify that the Array class sorts an Array correctly if the sort method is called. 
     * 
     * Prints "Sort Test Passed" if the test is passed, exits otherwise.
     */
    void testSort(){
        setup();

        t_true(threeunsorted->get(0)->equals(zebra));   
        t_true(threeunsorted->get(1)->equals(hello));   
        t_true(threeunsorted->get(2)->equals(goodbye));   

        threeunsorted->sort();

        t_true(threeunsorted->get(0)->equals(goodbye));   
        t_true(threeunsorted->get(1)->equals(hello));   
        t_true(threeunsorted->get(2)->equals(zebra));          

        OK("Sort Test Passed");
    }

    /**
     * Test to verify that the Array class keeps a sorted list sorted if the sort method is called on it. 
     * 
     * Prints "Already Sorted Array Test Passed" if the test is passed, exits otherwise. 
     */
    void testAlreadySorted(){
        setup();

        t_true(threesorted->get(0)->equals(goodbye));   
        t_true(threesorted->get(1)->equals(hello));   
        t_true(threesorted->get(2)->equals(zebra));   

        threesorted->sort();

        t_true(threesorted->get(0)->equals(goodbye));   
        t_true(threesorted->get(1)->equals(hello));   
        t_true(threesorted->get(2)->equals(zebra));          

        OK("Already Sorted Array Test Passed");
    }
};

/**
 * Runs the tests in the ArrayTestFrame class. 
 */
int main(){
    ArrayTestFrame* test = new ArrayTestFrame();
    test->testAdd();
    test->testGet();
    test->testLength();
    test->testRemove();
    test->testSize();
    test->testSort();
    test->testAlreadySorted();
    delete test;
    return 0;
};