/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                 Technische Informatik II                                      *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                               *
 *                                    C G A _ S T R E A M                                        *
 *                                                                                               *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "device/cgastr.h"

/** \todo implementieren **/
void CGA_Stream::flush () {

	print(buffer, pos);
	pos = 0;
  /* ToDo: insert sourcecode */ 
}

/** \todo implementieren **/
void CGA_Stream::setAttributes(int fgColor, int bgColor, bool blink){
	this->CGA_Screen::setAttributes(fgColor, bgColor, blink);
	/* ToDo: insert sourcecode */ 
}

void CGA_Stream::setfgColor(int fgColor) {
	this->CGA_Screen::setfgColor(fgColor);
}

void CGA_Stream::setbgColor(int bgColor) { 
	this->CGA_Screen::setbgColor(bgColor);
}

void CGA_Stream::setblink(bool blink) { 
	this->CGA_Screen::setblink(blink);
}
