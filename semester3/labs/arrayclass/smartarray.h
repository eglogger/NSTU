#ifndef ARRAYCLASS_SMARTARRAY_H
#define ARRAYCLASS_SMARTARRAY_H

#include "array.h"


class SmartArray : public Array {
public:
    SmartArray(int size);
    SmartArray(const SmartArray& other);
    void add(int elem) override;
    int get(int index) const override;
    void set(int index, int new_elem) override;
};


#endif //ARRAYCLASS_SMARTARRAY_H
