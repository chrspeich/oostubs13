/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                   Technische Informatik II                                    * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *                                                                                               * 
 *                                         P L U G B O X                                         * 
 *                                                                                               * 
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                    INCLUDES                     #
\* * * * * * * * * * * * * * * * * * * * * * * * */
#include "machine/plugbox.h"
#include "useful/panic.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                    METHODS                      # 
\* * * * * * * * * * * * * * * * * * * * * * * * */

/** \todo \~german implementieren \~english write implementation*/
Plugbox::Plugbox(){
	for (unsigned short slot = 0; slot < NUMBER_OF_GATES; slot++)
		assign(slot, panic);
}

/** \todo \~german implementieren \~english write implementation*/
void Plugbox::assign(unsigned short slot, Gate& gate){
	gates[slot] = &gate;
}

/** \todo \~german implementieren \~english write implementation*/
Gate& Plugbox::report(unsigned short slot){
  /// \todo Dummy entfernen, remove dummy
  return *gates[slot];
}
