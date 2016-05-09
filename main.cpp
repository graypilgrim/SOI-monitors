#include "Entities.h"

#define ENTIETIES_NUMBER 5
#define CONS_AMOUNT 2
#define PRODUCER_A 0
#define PRODUCER_B 1
#define PRODUCER_C 2
#define CONSUMER_1 3
#define CONSUMER_2 4

int main()
{
    pthread_t threads[ENTIETIES_NUMBER];

    Monitor* buffers[3];
    ConsumerData cd[CONS_AMOUNT];
    BufferB bufferB;
    BufferA bufferA = BufferA(bufferB);
    BufferC bufferC = BufferC(bufferB);
    bufferB.setObserverA(&bufferA);
    bufferB.setObserverC(&bufferC);

    buffers[0] = &bufferA;
    buffers[1] = &bufferB;
    buffers[2] = &bufferC;


    srand(time(NULL));

    pthread_create(&threads[PRODUCER_B], NULL, Producer, (void *)&bufferB);
    pthread_create(&threads[PRODUCER_A], NULL, Producer, (void *)&bufferA);
    pthread_create(&threads[PRODUCER_C], NULL, Producer, (void *)&bufferC);

    for(int i = 0; i < CONS_AMOUNT; ++i)
    {
        cd[i].buffers = buffers;
        cd[i].index = i;
        pthread_create(&threads[3 + i], NULL, Consumer, (void *)&cd[i]);
    }

    while(true)
    {
        printf("%d %d %d\n", bufferA.getSize(), bufferB.getSize(),bufferC.getSize());
        usleep(DELAY);
    }

    for(int i = 0; i < ENTIETIES_NUMBER; ++i)
        pthread_join(threads[i], (void **)NULL);

    return 0;
}
