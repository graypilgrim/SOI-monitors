#ifndef ENTIETIES_H
#define ENTIETIES_H

#include "BufferA.h"
#include "BufferB.h"
#include "BufferC.h"

void* Producer(void* buffer);

void* Consumer(void* msg);

struct ConsumerData
{
    Monitor** buffers;
    int index;
};


#endif
