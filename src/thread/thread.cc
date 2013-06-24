/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                 Technische Informatik II                                      *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                               *
 *                                         T H R E A D                                           *
 *                                                                                               *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                   INCLUDES                      #
\* * * * * * * * * * * * * * * * * * * * * * * * */

#include "thread/thread.h"
#include "useful/scheduler.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                   METHODS                       #
\* * * * * * * * * * * * * * * * * * * * * * * * */

/**\~english \todo implement**/
void Thread::kickoff(Thread* thread){
	thread->action();
	thread->exit();
}

/**\~english \todo implement**/
Thread::Thread(){
	if (getcontext(&context) < 0) {
		// TODO: error
	}

	context.uc_link = 0;
	context.uc_stack.ss_sp = stack;
	context.uc_stack.ss_size = 1024*1024;

	makecontext(&context, (void(*)())Thread::kickoff, 1, this);
}

/**\~english \todo implement**/
Thread::~Thread(){
}

/**\~english \todo implement**/
void Thread::resume(){
	scheduler.resume();
}

/**\~english \todo implement**/
void Thread::exit(){
	scheduler.exit();
}
