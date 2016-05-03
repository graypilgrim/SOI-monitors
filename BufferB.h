#ifndef BUFFERB_H
#define BUFFERB_H

#include "Monitor.h"
#include "BufferA.h"
#include "BufferC.h"

class BufferB : public Monitor
{
public:
    BufferB()
    :bufferA(nullptr), bufferC(nullptr)
    {}

    void setObserverA(BufferA* xx);
    void setObserverC(BufferC* xx);
    void push(int input);
    int pop();

private:
    void inform();

    BufferA* bufferA;
    BufferC* bufferC;
};

#endif
