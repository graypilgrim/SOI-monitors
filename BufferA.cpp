#include "BufferA.h"


void BufferA::push(int input)
    {
        enter();

        if(Full())
            wait(notFull);

        if( !bOddParity() )
            wait(oddB);

        buffer.push_back(input);

        signal(notEmpty);
        leave();
    }

int BufferA::pop()
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

void BufferA::BufferBOdd()
    {
        signal(oddB);
    }
