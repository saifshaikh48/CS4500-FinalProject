#pragma once

#include "object.h"
#include <iostream> //only for print() function as specified by a spec team
/**
* Represents a string class, or a character 'list'
*/
class String : public Object {
  public:
  
  char* str; 
  size_t len;

  /**
     * Creates a String given an array of characters.
     * 
     * @arg input  the value of the String that is being created
     */
    String(char *input)
    {
        len = 0; 

        while (input[len] != '\0') {
            len ++;
        }

        str = new char[len + 1]; 
        
        for (int i = 0; i < len; i ++) {
            str[i] = input[i];
        }
    }

  /**
  * Create a string and copy the contents of the given array.
  * @param c is the character array to be copied and used.
  */
  String(const char* c) {
    len = 0; 

    while (c[len] != '\0') {
      len ++;
    }

    str = new char[len + 1]; 
    
    for (int i = 0; i < len; i ++) {
      str[i] = c[i];
    }
  }


  // Constructor taking in string
  String(String *const s) {
    len = s->size();
    str = new char[len + 1]; 

    for (int i = 0; i < len; i++) {
      str[i] = s->str[i];
    }

  }

  //default
  String() {
    len = 0;
    str = nullptr;
  }
  
  /**
  * Delete this string and the character array associated with it.
  */
  ~String() {
    delete str;
  }

  /**
  * Hash this string.
  * @return an integer hash of this string.
  */
  virtual size_t hash() override {
    size_t hash = len;

    for (size_t i = 0; i < len; ++i) {
      hash += i * static_cast<size_t>(str[i]);
    }
    return hash;
  }

  /**
  * Is this string equal to that object?
  * @param o is the object to be compared to.
  * @return a boolean determining if these two objects are the same.
  */
  virtual bool equals(Object* o) override {
    String* val = dynamic_cast<String*>(o);

    if(val != nullptr && val->size() == len && compare(val) == 0) {
      return true;
    }
    else {
      return false;
    }
  }

  // Overrides object equals (overload)
    virtual bool equals(Object const *other) override { 
      
      String* temp_str = dynamic_cast<String*>(const_cast<Object*>(other));
      
      return this->equals(temp_str);
    }
  

  /**
  * Print this string.
  */
  void print() {
    printf("%s", str);
  }

  /**
  * Take the other string, and compare to see if we are bigger.
  * @param s is the string to compare to.
  * @return an integer smaller than 0 if this is smaller, equal to 0 if
  * they are the same, and greater than 0 if we are bigger.
  */
  int compare(String* const s) {
    int i = 0;

    while(s->str[i] != '\0' || str[i] != '\0') { 
    
      if (s->str[i] > str[i]) {
        return -1;
      }

      else if (s->str[i] < str[i]) {
        return 1;
      }
      i++;
    } 

    return 0;
  }

  /**
  * Concatenate this string with that string. Do not modify either.
  * @param s is the string to concatenate to.
  * @return a concatenated version of both strings.
  */
  String* concat(String* const s) {
    char* newCharArray = new char[len + s->len + 1];

    for(size_t i = 0; i < len; i++) {
      newCharArray[i] = this->str[i];
    }

    for(size_t j = len; j < len + s->len; j++) {
      newCharArray[j] = s->str[j - len];
    }

    String* newStr = new String(newCharArray);

    return newStr;
  }

  /**
  * Return the size of this string.
  */
  size_t size() {
    return len;
  }


  /**
     * Converts a const char* into a char*
     * 
     * @arg s  the const char* to be converted
     */
    char *duplicate(const char *s)
    {
        
        int i = 0;
        while (s[i] != '\0') {
            i++;
        }
        char *res = new char[i + 1];

        for (int j = 0; j < i; j++) {
            res[j] = s[j];
        }

        return res;
    }


    char charAt(size_t index) {
        assert(index < len); 

        return str[index];
    }

    String* clone() {
        String* s = new String(str);
        return s;
    }

    bool isEmpty() {
        return len == 0; 
    }
};

