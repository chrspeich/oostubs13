/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                 Technische Informatik II                                      *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                               *
 *                                         S C H E D U L E R                                     *
 *                                                                                               *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                   INCLUDES                      #
\* * * * * * * * * * * * * * * * * * * * * * * * */

#include "thread/scheduler.h"
#include "thread/lock.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                   METHODS                       #
\* * * * * * * * * * * * * * * * * * * * * * * * */

/**\~english \todo implement**/
void Scheduler::schedule(Thread& first){
	ready(first);
	
	go(first);
}

/**\~english \todo implement**/
void Scheduler::ready(Thread& that){
	Lock lock;

	threads.push_back(&that);
}

/**\~english \todo implement**/
void Scheduler::exit(){
	kill(*active());
}

/**\~english \todo implement**/
void Scheduler::kill(Thread& that){
	{
		Lock lock;

		ThreadIterator iter = threads.begin();

		while (*iter != &that) iter++;

		threads.erase(iter);
	}

	if (active() == &that) {
		resume();
	}
}

/**\~english \todo implement**/
void Scheduler::resume(){
	Thread* next;
	{
		Lock lock;

		next = threads.front();
		threads.pop_front();
		threads.push_back(next);
	}

	dispatch(*next);
}
