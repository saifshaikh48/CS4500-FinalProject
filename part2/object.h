#pragma once

/**
 * Object: this class represents the most basic methods of an object and is intended to be
 *         extended by other classes
 * 
 * authors: singh.kar@husky.neu.edu and haiber.ow@husky.neu.edu
 */
class Object
{
public:
    /**
     * Simple constructor for an Object. 
     */
    Object()
    {
    }

    /**
     * Destructor for an Object.
     */
    ~Object()
    {
    }

    /**
     * Checks to see if this Object is equal to the given one.
     * 
     * @arg other  another object
     */
    virtual bool equals(Object *other)
    {
    }

    /**
     * Returns the hash value for this Object.
     */
    virtual size_t hash()
    {
    }
};