#ifndef MONITOR_H
#define MONITOR_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <deque>

class Semaphore
{
public:

  Semaphore(int value);
  ~Semaphore();
  void down();
  void up();


private:
	sem_t sem;
};

class Condition
{
  friend class Monitor;

public:
	Condition()
    : semaphore(0)
	{
		waitingCounter = 0;
	}

	void wait();
	bool signal();

private:
	Semaphore semaphore;
	int waitingCounter;
};


class Monitor
{
public:
	Monitor()
    : bufferSize(9), access(1)
   {}

	void enter();
	void leave();
	void wait( Condition & cond );
	void signal( Condition & cond );

    virtual void push(int) = 0;
    virtual int pop() = 0;

    int getSize();
    bool Full();
    bool Empty();

protected:
    const size_t bufferSize;
	Semaphore access;
    Condition notFull;
    Condition notEmpty;
    std::deque<int> buffer;
};

#endif
