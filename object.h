#include <stddef.h>
#pragma once

// Generic object.
class Object {

    public:

        /**
        * The constructor for this object.
        */
        Object() {
        }

        ~Object() {
            
        }

        /**
        * Is this object equal to that object?
        * @param o is the object to compare equality to.
        * @return   whether this object is equal to that object.
        */
        virtual bool equals(Object* o) {
            return this == o;
        }

        /**
        * Determines whether this object is equal to another object
        *
        * Args:
        * - other: the object to compare this object to
        */
        virtual bool equals(Object const *other) {
            return this == other;
        }

        /**
        * Calculate this object's hash.
        * @return a natural number of a hash for this object.
        */
        virtual size_t hash() {
            return 0;
        }

        /**
        * Calculate this object's hash (helper method).
        * @return a natural number of a hash for this object.
        */
        virtual size_t hash_me_() {
            return reinterpret_cast<size_t>(this);
        }

};
