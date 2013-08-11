#include "thread/organizer.h"

/** \todo Implement method **/
void Organizer::block(Waitingroom& room){
	//active in Waiting queue, switch to next ready thread
	active()->waiting_in(&room);
	room.enqueue(*active());
	exit();
}

/** \todo Implement method **/
void Organizer::wakeup(Customer& customer){
	//remove from waiting queue, put to ready queue
	customer.waiting_in()->remove(customer);
	customer.waiting_in(0);
	ready(customer);
}

/** \todo Implement method **/
void Organizer::kill(Customer& that){
	//if customer waiting in a room, then remove from waiting queue, else kill
	Waitingroom *wait = that.waiting_in();
	if(wait)
	{
		wait->remove(that);
	}
	else 
		Scheduler :: kill(that);
}

Customer* Organizer::active() const{
    return static_cast<Customer*>(Scheduler::active());
}
