#pragma once
#include "object.h"
#include <stdio.h>
#include <string.h>

/**
 * Object: this class represents a string of characters
 * 
 * authors: singh.kar@husky.neu.edu and haiber.ow@husky.neu.edu
 */
class String : public Object
{
public:
    char *val; // value of the String 
    int size_; // length of the String

    /**
     * Creates a String given an array of characters.
     * 
     * @arg input  the value of the String that is being created
     */
    String(char *input)
    {
        val = input;
        size_ = strlen(val);
    }

    /**
     * Creates a String given an array of characters.
     * 
     * @arg input  the value of the String that is being created
     */
    String(const char *input)
    {
        val = duplicate(input);
        size_ = strlen(val);
    }

    /**
     * Destructor to delete the value of this String. 
     */
    ~String()
    {
        delete val;
    }

    /**
     * Returns the value of this String in char* form. 
     */
    char *getValue()
    {
        return val;
    }

    /**
     * Concatenates this String with the other one.
     * 
     * @arg other  the String being appended to the end of this one
     */
    String *concat(String *other)
    {
        size_t buffersize = 0;

        buffersize = buffersize + strlen(val) + strlen(other->getValue());

        char *buffer = new char[buffersize];

        strcpy(buffer, val);
        strcat(buffer, other->getValue());

        return new String(buffer);
    }

    /**
     * Checks to see if this String is equal to the other one.
     * 
     * @arg other  the String being compared against
     */
    bool equals(String *other)
    {
        char *str1 = val;
        char *str2 = other->getValue();

        int result;
        result = strcmp(str1, str2);
        if (result == 0)
        {
            return true;
        }
        else
        {
            return false;
        }

        // Don't need the local variables anymore.
        delete str1;
        delete str2;
    }

    /**
     * Converts a const char* into a char*
     * 
     * @arg s  the const char* to be converted
     */
    char *duplicate(const char *s)
    {
        char *res = new char[strlen(s) + 1];
        strcpy(res, s);
        return res;
    }
};