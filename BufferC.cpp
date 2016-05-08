#include "BufferC.h"

void BufferC::push(int input)
    {
        enter();

        if(Full())
            wait(notFull);

        if( !bFullnessOrParity() )
            wait(evenOrFullB);

        buffer.push_back(input);

        signal(notEmpty);
        leave();
    }

int BufferC::pop()
    {
        enter();

        if(Empty())
            wait(notEmpty);

        int result = buffer.front();
        buffer.pop_front();

        signal(notFull);
        leave();

        return result;
    }

void BufferC::BufferBEvenOrFull()
    {
        signal(evenOrFullB);
    }

inline bool BufferC::bFullnessOrParity()
{
    return (bufferB.Full() || bufferB.getSize() % 2 == 0);
}
