/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                   Technische Informatik II                                    * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *                                                                                               * 
 *                                       K E Y B O A R D                                         * 
 *                                                                                               * 
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                    INCLUDES                     #
\* * * * * * * * * * * * * * * * * * * * * * * * */
#include "device/keyboard.h"
#include "machine/pic.h"
#include "machine/plugbox.h"
#include "device/cgastr.h"

extern Plugbox plugbox;
extern PIC pic;
extern CGA_Stream kout;
extern unsigned int globalTaskChoice;

/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                    METHODS                      # 
\* * * * * * * * * * * * * * * * * * * * * * * * */
/** \todo \~german implementieren \~english write implementation */
Keyboard::Keyboard() : Keyboard_Controller() ,Gate() {
}

/** \todo \~german implementieren \~english write implementation */
void Keyboard::plugin(){
	plugbox.assign(32 + PIC::keyboard, *this);
	pic.allow(PIC::keyboard);
}

/** \todo \~german implementieren \~english write implementation */
void Keyboard::trigger(){
	Key k = key_hit();
	if(k.valid()) {
		if (k.alt() && k.ctrl() && k.scancode() == 83) {
            reboot();
        }
        else if (k.alt() && k.scancode() == 2) {
            globalTaskChoice = 1;
        }
        else if (k.alt() && k.scancode() == 3) {
            globalTaskChoice = 2;
        }
        else {
        	unsigned short x,y;
        	kout.getpos(x,y);
        	kout.flush();
        	kout.setpos(0, 20);
        	kout << k.ascii();
        	kout.flush();
        	kout.setpos(x,y);
		}
	}
	pic.ack(false);
}
