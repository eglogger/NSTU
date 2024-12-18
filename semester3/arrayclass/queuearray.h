#ifndef ARRAYCLASS_QUEUEARRAY_H
#define ARRAYCLASS_QUEUEARRAY_H

#include "array.h"


class QueueArray : public Array {

public:

    QueueArray(int size);
    QueueArray(const QueueArray& other);
    void enqueue(int elem);
    int dequeue();
    int front() const;

private:

    int frontIndex;
};


#endif //ARRAYCLASS_QUEUEARRAY_H
