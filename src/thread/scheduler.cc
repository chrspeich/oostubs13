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
	threads.push_back(&that);
}

/**\~english \todo implement**/
void Scheduler::exit(){
	kill(*active());
}

/**\~english \todo implement**/
void Scheduler::kill(Thread& that){
	ThreadIterator iter = threads.begin();

	while (*iter != &that) iter++;

	threads.erase(iter);

	if (active() == &that) {
		resume();
	}
}

/**\~english \todo implement**/
void Scheduler::resume(){
	Thread* next = threads.front();
	threads.pop_front();
	threads.push_back(next);

	dispatch(*next);
}
