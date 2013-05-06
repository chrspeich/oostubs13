/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                 Technische Informatik II                                      *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                               *
 *                                 S T R I N G B U F F E R                                       *
 *                                                                                               *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "object/strbuf.h"

/* ToDo: insert sourcecode */ 

Stringbuffer::Stringbuffer(){

	pos = 0;

}



void Stringbuffer::put(char c){


		buffer[pos] = c;
		pos++;

	if (pos>=BUFFER_SIZE-1) {	
		flush();
	}	

}
