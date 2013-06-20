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
#include "device/curskbd.h"
#include "useful/plugbox.h"
#include "useful/pic.h"
#include "useful/kout.h"
#include "useful/cpu.h"
#include <curses.h>


extern Key keyBuffer;
/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                    METHODS                      # 
\* * * * * * * * * * * * * * * * * * * * * * * * */
Curses_Keyboard::Curses_Keyboard() : Gate(){

}

void Curses_Keyboard::plugin(){
  //erst registrieren
  plugbox.assign(Plugbox::keyboard, *this);
  //und im PIC erlauben
  pic.allow(Software_PIC::keyboard);
}

Key Curses_Keyboard::key_hit()
{
    Key temp=keyBuffer;
    keyBuffer=Key();
    return temp;
}

void Curses_Keyboard::trigger()
{
      //Zeichen an fester Position ausgeben
    kout.flush();
    kout.setpos(4,10);
    kout << key_hit();
    kout.flush();
}
