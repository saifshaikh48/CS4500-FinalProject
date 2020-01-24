#pragma once
#include "object.h"
#include <stdio.h>
#include <string.h>
#include <cassert>

// Represents a String class implementation.
class String : public Object
{
public:
    // Value of the String
    char *val;
    int size_;

    // Constructor to make Strings
    String(char *input)
    {
        val = input;
        size_ = strlen(val);
    }

    // Constructor to make Strings
    String(const char *input)
    {
        val = duplicate(input);
        size_ = strlen(val);
    }

    ~String()
    {
        delete val;
    }

    // Returns the value of this String.
    char *getValue()
    {
        return val;
    }

    // Concatenates this String with the other one.
    String *concat(String *other)
    {
        size_t buffersize = 0;

        buffersize = buffersize + strlen(val) + strlen(other->getValue());

        char *buffer = new char[buffersize];

        strcpy(buffer, val);
        strcat(buffer, other->getValue());

        return new String(buffer);
    }

    // Checks to see if this String is equal to that object
    // bool equals(Object* other) {
    //     String* temp = dynamic_cast<String*>(other);

    //     return this->equals(temp);
    // }

    // Checks to see if this String is equal to the other one.
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

    char *duplicate(const char *s)
    {
        char *res = new char[strlen(s) + 1];
        strcpy(res, s);
        return res;
    }
};