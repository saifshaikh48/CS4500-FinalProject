#pragma once
#include "object.h"
#include <stdlib.h>

/**
 * Array: this class represents an array of Objects or Strings
 * 
 * authors: singh.kar@husky.neu.edu and haiber.ow@husky.neu.edu
 */
class Array : public Object
{
public:
    /**
     * Builds an array of the given size.
     * 
     * @arg size  the size of the array
     */
    Array(size_t size)
    {
    }

    /**
     * Destructor for the array.
     */
    ~Array()
    {
    }

    /**
     * Returns the total size of the array. 
     */
    size_t size()
    {
    }

    /**
     * Returns the number of Objects in the array.
     */
    size_t length()
    {
    }

    /**
     * Adds the given Object to the array at the given index.
     * 
     * @arg index  the index where the object will be added
     * @arg obj  the Object being added to the array
     */
    void add(size_t index, Object *obj)
    {
    }

    /**
     * Removes the Object at the given index.
     * 
     * @arg index  the index of the Object being removed
     */
    Object *remove(size_t index)
    {
    }

    /**
     * Returns the Object at the given index.
     * 
     * @arg index  the index of the Object being returned
     */
    Object *get(size_t index)
    {
    }

    /**
     * Sorts the array in alphanumeric ascending order. 
     */
    void sort()
    {
    }

    /**
     * Checks to see if this array is equal to that one.
     * 
     * @arg other  the second array being compared to this one
     */
    bool equals(Array *other)
    {
    }

    /**
     * Returns the hash value for this Array.
     */
    size_t hash()
    {
    }
};