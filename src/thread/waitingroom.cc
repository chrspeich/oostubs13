#include "thread/waitingroom.h"

/** \todo Implement method **/
Waitingroom::~Waitingroom(){
}

/** \todo Implement method **/
void Waitingroom::remove(Customer& that){
	//customer aus queue entfernen	
	if(queue.empty());
		return;

	for(CustomerIterator iter = queue.begin(); iter != queue.end(); iter++)
	{
		if(*iter == &that)
			queue.erase(iter);
	}
}

/** \todo Implement method **/
void Waitingroom::enqueue(Customer& that){
	//customer am ende der waiting queue einfuegen
	queue.push_back(&that);
}

/** \todo Implement method **/
Customer& Waitingroom::dequeue(){
	//Customer am Anfang entfernen
	Customer *cmr = queue.front();
	queue.pop_front();

  return *reinterpret_cast<Customer*>(cmr);
}
