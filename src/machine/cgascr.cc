/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                 Technische Informatik II                                      *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                               *
 *                                    C G A _ S C R E E N                                        *
 *                                                                                               *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
#include "machine/cgascr.h"

/** \todo implementieren **/
CGA_Screen::CGA_Screen() : controll_port(0x3D4), data_port(0x3D5) {
  /* ToDo: insert sourcecode */
    cgaBuffer = (uint16_t*)0xB8000;
    setAttributes(0x7, 0x0, false);
    x = 0;
    y = 0;
    clear();
    
}

/** \todo implementieren **/
CGA_Screen::~CGA_Screen(){
  /* ToDo: insert sourcecode */ 
}

/** \todo implementieren **/
void CGA_Screen::setpos (unsigned short x, unsigned short y) {
  /* ToDo: insert sourcecode */
    cursor_x = x;
    cursor_y = y;
    controll_port.outb(0x0F);
    data_port.outb((y*80+x)&0xFF);
    controll_port.outb(0x0E);
    data_port.outb((y*80+x)>>8);   
}

/** \todo implementieren **/
void CGA_Screen::getpos (unsigned short& x, unsigned short& y) const{
  /* ToDo: insert sourcecode */
    x = cursor_x;
    y = cursor_y; 
}

/** \todo implementieren **/
void CGA_Screen::show (unsigned short x, unsigned short y, char c, unsigned char attrib) {
  /* ToDo: insert sourcecode */ 
    cgaBuffer[y*80+x] = ((uint16_t)attrib<<8) | c;
}

/** \todo implementieren **/
void CGA_Screen::print (const char* string, unsigned int n) {
    for(int i = 0; i < n; i++) {
        show(x,y,string[i], ((uint16_t)blink<<7) | ((uint16_t)bgColor<<4) | ((uint16_t)fgColor));
        x++;
        if (x>=80) {
            x = 0;
            y++;
        }
        if (y>=25) {
            scrollup();
            y--;
        }
    }
}

/** \todo implementieren **/
void CGA_Screen::scrollup () {
    for(int i = 80; i<25*80; i++) {
        cgaBuffer[i-80] = cgaBuffer[i];
    }
    for(int i = 0; i<80; i++) {
        show(i, 24, ' ', ((uint16_t)blink<<7) | ((uint16_t)bgColor<<4) | ((uint16_t)fgColor)); 
    }
}

void CGA_Screen::clear () {
  /* ToDo: insert sourcecode */
    for(int y=0; y<25; y++) {
        for(int x=0; x<80; x++) {
            show(x, y, ' ', ((uint16_t)blink<<7) | ((uint16_t)bgColor<<4) | ((uint16_t)fgColor));
        }
    }
             
}

/** \todo implementieren **/
void CGA_Screen::setAttributes(int fg_Color, int bg_Color, bool _blink){
  /* ToDo: insert sourcecode */
    fgColor = fg_Color;
    bgColor = bg_Color;
    blink = _blink;     
}
