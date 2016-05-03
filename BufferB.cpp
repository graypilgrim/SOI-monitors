#include "BufferB.h"

void BufferB::setObserverA(BufferA* xx)
    {
        bufferA = xx;
    }

void BufferB::setObserverC(BufferC* xx)
    {
        bufferC = xx;
    }

void BufferB::push(int input)
    {
        enter();

        if(Full())
            wait(notFull);

        buffer.push_back(input);

        inform();
        signal(notEmpty);
        leave();
    }

int BufferB::pop()
    {
        enter();

        if(Empty())
            wait(notEmpty);

        int result = buffer.front();
        buffer.pop_front();

        inform();
        signal(notFull);
        leave();

        return result;

    }

void BufferB::inform()
{
    if(buffer.size() % 2 != 0)
        bufferA->BufferBOdd();

    if(buffer.size() == bufferSize || buffer.size() % 2 == 0)
        bufferC->BufferBEvenOrFull();
}
