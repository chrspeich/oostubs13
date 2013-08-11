#include "thread/semaphore.h"
#include "useful/scheduler.h" //fuer die Aufrufe in scheduler unten

/** \todo Implement constructor **/
Semaphore::Semaphore(unsigned int value){
	//Interne Variable auf value setzen
	counter = value;
}


/** \todo Implement method **/
void Semaphore::p(){
	//decrease value or block calling thread
	if(counter <= 0)
		scheduler.block(*this);
	else
		counter--;
}

/** \todo Implement method **/
void Semaphore::v(){
	//increase value or wake up blocked thread
	if(counter <= 0 && !empty())
		scheduler.wakeup(dequeue());
	else
		counter++;
}
