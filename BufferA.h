#ifndef BUFFERA_H
#define BUFFERA_H

#include "Monitor.h"

class BufferA : public Monitor
{
public:
    BufferA(Monitor& b)
    :bufferB(b)
    {}

    void push(int input);
    int pop();
    void BufferBOdd();


private:
    inline bool bOddParity()
    {
        return (bufferB.getSize() % 2 != 0);
    }

    Condition oddB;
    Monitor& bufferB;
};

#endif
