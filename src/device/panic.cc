/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                   Technische Informatik II                                    * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *                                                                                               * 
 *                                          P A N I C                                            * 
 *                                                                                               * 
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                    INCLUDES                     #
\* * * * * * * * * * * * * * * * * * * * * * * * */
#include "device/panic.h"
#include "useful/kout.h"
#include "useful/cpu.h"


/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                    METHODS                      # 
\* * * * * * * * * * * * * * * * * * * * * * * * */





/** \todo \~german implementieren \~english write implementation*/
Panic::Panic() : Gate() {
}

/** \todo \~german implementieren \~english write implementation*/
void Panic::trigger(){

	kout << "PANIC!!! Interrupt Number: ";	
	kout << gateInterruptNumber;
	kout.flush();
	cpu.disable_int();
	cpu.halt();
	
}
