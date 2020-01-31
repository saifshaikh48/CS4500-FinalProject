#pragma once
#include "object.h"
#include "string.h"
#include <assert.h>

// /**
//  * Array: this class represents an array of Objects or Strings
//  * 
//  * authors: singh.kar@husky.neu.edu and haiber.ow@husky.neu.edu
//  */
// class Array : public Object
// {
// public:
//     size_t size_;
//     size_t len_;
//     Object** elements_;

//     /**
//      * Builds an array of the given size.
//      * 
//      * @arg size  the size of the array
//      */
//     Array(size_t size)
//     {
//         size_ = size;
//         len_ = 0; 

//         if (size== 0) {
//             elements_ = nullptr;
//         }
//         else {
//             elements_ = new Object*[size];
//             for (int i = 0; i < size_; i++) {
//                 elements_[i] = new Object();
//             }
//         }
//     }

//     /**
//      * Destructor for the array.
//      */
//     ~Array()
//     {
//         delete []elements_;
//     }

//     /**
//      * Returns the total size of the array. 
//      */
//     size_t size()
//     {
//         return size_;
//     }

//     /**
//      * Returns the number of Objects in the array.
//      */
//     size_t length()
//     {
//         return len_;
//     }

//     /**
//      * Adds the given Object to the array at the given index.
//      * 
//      * @arg index  the index where the object will be added
//      * @arg obj  the Object being added to the array
//      */
//     void add(size_t index, Object *obj)
//     {
//         assert(index <= size_);

//         if (index < size_) {
//             // if (get(index)->equals(new Object())) {
//             //     elements_[index] = obj; 
//             //     return;
//             // }
//             Object ** temp_ = new Object*[size_ + 1];
            
//             for (int i = 0; i < size_; i++) {
//                 if (i < index) {
//                     temp_[i] = elements_[i];
//                 }
//                 else if (i > index) {
//                     temp_[i] = elements_[i - 1];
//                 }
//                 else { 
//                     if (get(index)->equals(new Object())) {
//                         elements_[index] = obj; 
//                         size_+= 1;
//                     }
//                     else {
//                         temp_[i] = obj;
//                     }
//                 }
//             }
//             len_ += 1;
//             delete []elements_;
//             elements_ = temp_;
//             return;
//         }

//         else if (index == size_) {
//             Object** temp_array_ = new Object*[size_ + 1]; 
            
//             for (int i = 0; i < size_ + 1; i++) {
//                 if (index == i) {
//                     temp_array_[i] = obj;
//                 }
//                 else {
//                     temp_array_[i] = elements_[i];
//                 }
//             }
//             len_ += 1; 
//             size_+= 1;
//             delete []elements_;
//             elements_ = temp_array_;
//         }
//     }

//     /**
//      * Removes the Object at the given index.
//      * 
//      * @arg index  the index of the Object being removed
//      */
//     void remove(size_t index)
//     {
//         assert(index >= 0 && index < size_);

//         for (int i = 0; i < size_; i++) {
//             if (index == i) {
//                 Object* empty_object = new Object();
//                 if (get(i)->equals(empty_object)) {
//                     return;
//                 } 
//                 elements_[i] = new Object();               
//             }
//         }

//         delete []elements_; 
//         len_ -= 1;
//     }

//     /**
//      * Returns the Object at the given index.
//      * 
//      * @arg index  the index of the Object being returned
//      */
//     Object *get(size_t index)
//     {
//         assert(index >= 0 && index < size_);
//         return elements_[index];
//     }

//     /**
//      * Sorts the array in alphanumeric ascending order. 
//      */
//     void sort()
//     {
//         for (int i = 1; i < size_; i++) {
//             int j = i;
//             String* val = dynamic_cast<String*>(elements_[j - 1]);
//             String* val2 = dynamic_cast<String*>(elements_[j]);
//             while(j > 0 && val->compare(val2) < 0) {
//                 Object* temp = elements_[j - 1];
//                 elements_[j - 1] = elements_[j];
//                 elements_[j] = temp;
//                 j--;
//             }
//         }
//     }

//     /**
//      * Checks to see if this array is equal to that one.
//      * 
//      * @arg other  the second array being compared to this one
//      */
//     virtual bool equals(Object *other) override
//     {
//         Array* val = dynamic_cast<Array*>(other);

//         if (val->size() != size_ || val->length() != len_) {
//             return false; 
//         }
//         else { 
//             for (int i = 0; i < size_; i++) {
//                 if (!elements_[i]->equals(val->elements_[i])) {
//                     return false;
//                 }
//             }
//             return true;
//         }
//     }

//     /**
//      * Returns the hash value for this Array.
//      */
//     virtual int hash() override
//     {
//         int hash = size_; 
//         for (int i = 0; i < size_; i++) {
//             hash += i * elements_[i]->hash();
//         }

//         return hash;
//     }
// };

class StrArray : public Object {
public:
    String** values;
    size_t length_;

    StrArray() : Object() {
        values = nullptr;
        length_ = 0;
    }

    StrArray(String** str, size_t size) : Object() {
        values = new String*[size];

        for(size_t i = 0; i < size; i++) {
            values[i] = str[i];
        }
        
        length_ = size;
    }

    ~StrArray() { 
        delete[] values; 
    }

    void push_back(String* e) { // Appends e to end
        add(length_, e);
    }

    void add(size_t i, String* e) { // Inserts e at i 
        assert(i <= length_);

        String** newArr = nullptr;
        size_t newSize = length_ + 1;
        newArr = new String*[newSize];

        for (size_t j = 0; j < newSize; ++j)
        {
            if (j < i) {
                newArr[j] = values[j];
            }
            else if (j > i) {
                newArr[j] = values[j - 1];
            }
            else {
                newArr[j] = e;
            }
        }

        delete[] values;
        values = newArr;
        length_ = newSize;
    }

    void add_all(size_t i, StrArray* c) { // Inserts all of elements in c into this list at i
        size_t cSize = c->size();

        for (int j = 0; j < cSize; ++j)
        {
            add(j + i, c->values[j]);
        }
    }

    void clear() { // Removes all of elements from this list
        delete[] values;
        values = nullptr;
        length_ = 0;
    }
    
    bool equals(Object* o) override { // Compares o with this list for equality.
        StrArray* strArray_ = dynamic_cast<StrArray*>(o);
        
        if(strArray_ == nullptr || strArray_->length_ != length_) {
            return false;
        }

        for (int i = 0; i < length_; ++i)
        {
            if(values[i]->equals(strArray_->values[i]) == false) {
                return false;
            }
        }

        return true;
    }
    
    String* get(size_t index) { // Returns the element at index
        assert(index < length_);

        return values[index];
    }
    
    size_t hash() override { // Returns the hash code value for this list.
        size_t hash = length_;

        for (size_t i = 0; i < length_; ++i) {
            hash += i * values[i]->hash();
        }

        return hash;
    }
    
    size_t index_of(Object* o) { // Returns the index of the first occurrence of o, or >size() if not there
        for (size_t i = 0; i < length_; ++i)
        {
            if (values[i]->equals(o))
            {
                return i;
            }
        }

        return length_ + 1;
    }

    String* remove(size_t i) { //Removes the element at i, returns the removed element
        assert(i < length_);

        String** newArr = nullptr;
        size_t newSize = length_ - 1;
        newArr = new String*[newSize];

        String* valRemoved = nullptr;

        for (size_t j = 0; j < length_; ++j)
        {
            if (j < i) {
                newArr[j] = values[j];
            }
            else if (j > i) {
                newArr[j - 1] = values[j];
            }
            else {
                valRemoved = new String[values[j]->size()];
                valRemoved = values[j];
            }
        }

        delete[] values;
        values = newArr;
        length_ = newSize;

        return valRemoved;
    }
    
    String* set(size_t i, String* e) { // Replaces the element at i with e, returns the replaced element
        assert(i < length_);

        add(i, e);

        return remove(i + 1);
    }
    
    size_t size() { // Return the number of elements in the collection
        return length_;
    }

    bool is_empty() {
        return length_ == 0;
    }

};

class FloatArray : public Object {
public:
    float* values;
    size_t length_;

    FloatArray() : Object() {
        values = nullptr;
        length_ = 0;
    }

    FloatArray(float* flt, size_t size) : Object() {
        values = new float[size];

        for(size_t i = 0; i < size; i++) {
            values[i] = flt[i];
        }
        
        length_ = size;
    }

    ~FloatArray() { 
        delete[] values; 
    }

    void push_back(float e) { // Appends e to end
        add(length_, e);
    }

    void add(size_t i, float e) { // Inserts e at i 
        assert(i <= length_);

        float* newArr = nullptr;
        size_t newSize = length_ + 1;
        newArr = new float[newSize];

        for (size_t j = 0; j < newSize; ++j)
        {
            if (j < i) {
                newArr[j] = values[j];
            }
            else if (j > i) {
                newArr[j] = values[j - 1];
            }
            else {
                newArr[j] = e;
            }
        }

        delete[] values;
        values = newArr;
        length_ = newSize;
    }

    void add_all(size_t i, FloatArray* c) { // Inserts all of elements in c into this list at i
        size_t cSize = c->size();

        for (int j = 0; j < cSize; ++j)
        {
            add(j + i, c->values[j]);
        }
    }

    void clear() { // Removes all of elements from this list
        delete[] values;
        values = nullptr;
        length_ = 0;
    }
    
    bool equals(Object* o) override { // Compares o with this list for equality.
        FloatArray* fltArray = dynamic_cast<FloatArray*>(o);
        
        if(fltArray == nullptr || fltArray->length_ != length_) {
            return false;
        }

        for (int i = 0; i < length_; ++i)
        {
            if (values[i] != fltArray->values[i]) {
                return false;
            }
             
        }

        return true;
    }
    
    float get(size_t index) { // Returns the element at index
        assert(index < length_);

        return values[index];
    }
    
    size_t hash() override { // Returns the hash code value for this list.
        size_t hash = length_;

        for (size_t i = 0; i < length_; ++i) {
            hash += i * values[i];
        }

        return hash;
    }
    
    size_t index_of(float o) { // Returns the index of the first occurrence of o, or >size() if not there
        for (size_t i = 0; i < length_; ++i)
        {
            if (values[i] == o)
            {
                return i;
            }
        }

        return length_ + 1;
    }

    float remove(size_t i) { //Removes the element at i, returns the removed element
        assert(i < length_);

        float* newArr = nullptr;
        size_t newSize = length_ - 1;
        newArr = new float[newSize];

        float valRemoved;

        for (size_t j = 0; j < length_; ++j)
        {
            if (j < i) {
                newArr[j] = values[j];
            }
            else if (j > i) {
                newArr[j - 1] = values[j];
            }
            else {
                valRemoved = values[j];
            }
        }

        delete[] values;
        values = newArr;
        length_ = newSize;

        return valRemoved;
    }
    
    float set(size_t i, float e) { // Replaces the element at i with e, returns the replaced element
        assert(i < length_);

        add(i, e);

        return remove(i + 1);
    }
    
    size_t size() { // Return the number of elements in the collection
        return length_;
    }

    bool is_empty() {
        return length_ == 0;
    }
};

class IntArray : public Object {
public:
    int* values;
    size_t length_;

    IntArray() : Object() {
        values = nullptr;
        length_ = 0;
    }

    IntArray(int* int_, size_t size) : Object() {
        values = new int[size];

        for(size_t i = 0; i < size; i++) {
            values[i] = int_[i];
        }
        
        length_ = size;
    }

    ~IntArray() { 
        delete[] values; 
    }

    void push_back(int e) { // Appends e to end
        add(length_, e);
    }

    void add(size_t i, int e) { // Inserts e at i 
        assert(i <= length_);

        int* newArr = nullptr;
        size_t newSize = length_ + 1;
        newArr = new int[newSize];

        for (size_t j = 0; j < newSize; ++j)
        {
            if (j < i) {
                newArr[j] = values[j];
            }
            else if (j > i) {
                newArr[j] = values[j - 1];
            }
            else {
                newArr[j] = e;
            }
        }

        delete[] values;
        values = newArr;
        length_ = newSize;
    }

    void add_all(size_t i, IntArray* c) { // Inserts all of elements in c into this list at i
        size_t cSize = c->size();

        for (int j = 0; j < cSize; ++j)
        {
            add(j + i, c->values[j]);
        }
    }

    void clear() { // Removes all of elements from this list
        delete[] values;
        values = nullptr;
        length_ = 0;
    }
    
    bool equals(Object* o) override { // Compares o with this list for equality.
        IntArray* intArray_ = dynamic_cast<IntArray*>(o);
        
        if(intArray_ == nullptr || intArray_->length_ != length_) {
            return false;
        }

        for (int i = 0; i < length_; ++i)
        {
            if (values[i] != intArray_->values[i]) {
                return false;  
            }
             
        }

        return true;
    }
    
    int get(size_t index) { // Returns the element at index
        assert(index < length_);

        return values[index];
    }
    
    size_t hash() override { // Returns the hash code value for this list.
        size_t hash = length_;

        for (size_t i = 0; i < length_; ++i) {
            hash += i * values[i];
        }

        return hash;
    }
    
    size_t index_of(int o) { // Returns the index of the first occurrence of o, or >size() if not there
        for (size_t i = 0; i < length_; ++i)
        {
            if (values[i] == (o))
            {
                return i;
            }
        }

        return length_ + 1;
    }

    int remove(size_t i) { //Removes the element at i, returns the removed element
        assert(i < length_);

        int* newArr = nullptr;
        size_t newSize = length_ - 1;
        newArr = new int[newSize];

        int valRemoved;

        for (size_t j = 0; j < length_; ++j)
        {
            if (j < i) {
                newArr[j] = values[j];
            }
            else if (j > i) {
                newArr[j - 1] = values[j];
            }
            else {
                valRemoved = values[j];
            }
        }

        delete[] values;
        values = newArr;
        length_ = newSize;

        return valRemoved;
    }
    
    int set(size_t i, int e) { // Replaces the element at i with e, returns the replaced element
        assert(i < length_);

        add(i, e);

        return remove(i + 1);
    }
    
    size_t size() { // Return the number of elements in the collection
        return length_;
    }

    bool is_empty() {
        return length_ == 0;
    }
};

class BoolArray : public Object {
public:
    bool* values;
    size_t length_;

    BoolArray() : Object() {
        values = nullptr;
        length_ = 0;
    }

    BoolArray(bool* bl, size_t size) : Object() {
        values = new bool[size];

        for(size_t i = 0; i < size; i++) {
            values[i] = bl[i];
        }
        
        length_ = size;
    }

    ~BoolArray() { 
        delete[] values; 
    }

    void push_back(bool e) { // Appends e to end
        add(length_, e);
    }

    void add(size_t i, bool e) { // Inserts e at i 
        assert(i <= length_);

        bool* newArr = nullptr;
        size_t newSize = length_ + 1;
        newArr = new bool[newSize];

        for (size_t j = 0; j < newSize; ++j)
        {
            if (j < i) {
                newArr[j] = values[j];
            }
            else if (j > i) {
                newArr[j] = values[j - 1];
            }
            else {
                newArr[j] = e;
            }
        }

        delete[] values;
        values = newArr;
        length_ = newSize;
    }

    void add_all(size_t i, BoolArray* c) { // Inserts all of elements in c into this list at i
        size_t cSize = c->size();

        for (int j = 0; j < cSize; ++j)
        {
            add(j + i, c->values[j]);
        }
    }

    void clear() { // Removes all of elements from this list
        delete[] values;
        values = nullptr;
        length_ = 0;
    }
    
    bool equals(Object* o) override { // Compares o with this list for equality.
        BoolArray* boolArray_ = dynamic_cast<BoolArray*>(o);
        
        if(boolArray_ == nullptr || boolArray_->length_ != length_) {
            return false;
        }

        for (int i = 0; i < length_; ++i)
        {
            if (values[i] != boolArray_->values[i]) {
                return false;  
            }
             
        }

        return true;
    }
    
    bool get(size_t index) { // Returns the element at index
        assert(index < length_);

        return values[index];
    }
    
    size_t hash() override { // Returns the hash code value for this list.
        size_t hash = length_;

        for (size_t i = 0; i < length_; ++i) {
            hash += i * values[i];
        }

        return hash;
    }
    
    size_t index_of(bool o) { // Returns the index of the first occurrence of o, or >size() if not there
        
        for (size_t i = 0; i < length_; ++i)
        {
            if (values[i] == (o))
            {
                return i;
            }
        }

        return length_ + 1;
    }

    bool remove(size_t i) { //Removes the element at i, returns the removed element
        assert(i < length_);

        bool* newArr = nullptr;
        size_t newSize = length_ - 1;
        newArr = new bool[newSize];

        bool valRemoved;

        for (size_t j = 0; j < length_; ++j)
        {
            if (j < i) {
                newArr[j] = values[j];
            }
            else if (j > i) {
                newArr[j - 1] = values[j];
            }
            else {
                valRemoved = values[j];
            }
        }

        delete[] values;
        values = newArr;
        length_ = newSize;

        return valRemoved;
    }
    
    bool set(size_t i, bool e) { // Replaces the element at i with e, returns the replaced element
        assert(i < length_);

        add(i, e);

        return remove(i + 1);
    }
    
    size_t size() { // Return the number of elements in the collection
        return length_;
    }

    bool is_empty() {
        return length_ == 0;
    }
};

