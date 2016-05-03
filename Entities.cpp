#include "Entities.h"

void* Producer(void* buffer)
{
    Monitor* buf = (class Monitor*) buffer;
    int input = rand() % 30;

    while(true)
    {
        buf->push(input);

        usleep(1000);
    }
}


void* Consumer(void* msg)
{
    int producer;
    int result;
    ConsumerData* cd = (struct ConsumerData*)msg;
    Monitor** bufs = (class Monitor**)cd->buffers;
    int index = cd->index;

    while(true)
    {
        producer = rand() % 3;

        for(int  i = 0; i < 4*index; ++i)
            printf("\t");
        printf("Consumer%d choose Producer %c\n", index, 'A' + producer);

        result = (bufs[producer])->pop();

        for(int  i = 0; i < 4*index; ++i)
            printf("\t");
        printf("Consumer%d picked %d\n", index, result);

        usleep(1000);
    }
}
