#include "Monitor.h"

Semaphore::Semaphore(int value)
  {
     std::string exception = "sem_init: failed";
     if( sem_init(&sem, 0, value) != 0 )
       throw exception;
  }

Semaphore::~Semaphore()
  {
	  sem_destroy(&sem);
  }

void Semaphore::down()
  {
     std::string exception = "sem_wait: failed";
     if( sem_wait(&sem) != 0 )
       throw exception;
  }

void Semaphore::up()
  {
     std::string exception = "sem_post: failed";
     if( sem_post(&sem) != 0 )
       throw exception;
  }

void Condition::wait()
	{
		semaphore.down();
	}

bool Condition::signal()
	{
		if( waitingCounter > 0)
		{
			--waitingCounter;
			semaphore.up();
			return true;
		}
		else
			return false;
	}

void Monitor::enter()
	{
		access.down();
	}

void Monitor::leave()
	{
		access.up();
	}

void Monitor::wait( Condition & cond )
	{
		++cond.waitingCounter;
		leave();
		cond.wait();
	}

void Monitor::signal( Condition & cond )
	{
		if( cond.signal() )
			enter();
	}

int Monitor::getSize()
    {
        return buffer.size();
    }

bool Monitor::Full()
    {
        return buffer.size() == bufferSize;
    }

bool Monitor::Empty()
    {
        return buffer.size() == 0;
    }
