/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                   Technische Informatik II                                    * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *                                                                                               * 
 *                                            P I C                                              * 
 *                                                                                               * 
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                    INCLUDES                     #
\* * * * * * * * * * * * * * * * * * * * * * * * */
#include "machine/pic.h"
#include "machine/io_port.h"


/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                    METHODS                      # 
\* * * * * * * * * * * * * * * * * * * * * * * * */

/** \todo \~german verstehen \~english understand */
PIC::PIC(): ctrl_1(0x20), ctrl_2(0xa0), mask_1(0x21), mask_2(0xa1) {
  ctrl_1.outb(0x11); // Init PIC1
  ctrl_2.outb(0x11); // Init PIC2
  
  mask_1.outb(32); // PIC1 interrupts begin at 32
  mask_2.outb(40); // PIC2 interrupts begin at 40
  
  mask_1.outb(4); // Tell PIC1 that there is an Slave(PIC2) at IRQ2
  mask_2.outb(2); // Tell PIC2 it's identity (IRQ2)
  
  mask_1.outb(3); // PC and Auto EOI (Resets IRQ level after EOI)
  mask_2.outb(3);
  
  mask_1.outb(0xFB); // Mask all IRQs except  2 (the slave)
  mask_2.outb(0xFF); // Mask all irq
}

/** \todo \~german implementieren \~english write implementation*/
void PIC::allow(Interrupts interrupt){
  // The interrupt is on PIC1
  if (interrupt < 8) {
    char value = mask_1.inb(); // Get current mask
    value &= ~(1 << interrupt); // Remove bit for interrupt
    mask_1.outb(value); // Set mask
  }
  else {
    char value = mask_2.inb(); // Get current mask
    value &= ~(1 << (interrupt - 8)); // Remove bit for interrupt
    mask_2.outb(value); // Set mask
  }
}

/** \todo \~german implementieren \~english write implementation*/
void PIC::forbid(Interrupts interrupt){
  // The interrupt is on PIC1
  if (interrupt < 8) {
    char value = mask_1.inb(); // Get current mask
    value |= (1 << interrupt); // Set bit for interrupt
    mask_1.outb(value); // Set mask
  }
  else {
    char value = mask_2.inb(); // Get current mask
    value |= (1 << (interrupt - 8)); // Set bit for interrupt
    mask_2.outb(value); // Set mask
  }
}

/** \todo \~german implementieren \~english write implementation*/
void PIC::ack(bool secondPIC){
  if(secondPIC)
    ctrl_2.outb(0x20); // Send EOI to PIC2
  else
    ctrl_1.outb(0x20); // Send EOI to PIC1
}

/** \todo \~german implementieren \~english write implementation*/
unsigned char PIC::getISR(bool secondPIC){
  if (secondPIC) {
    ctrl_2.outb(0x0b); // We want to read the ISR from PIC2
    return mask_2.inb();
  }
  else {
    ctrl_1.outb(0x0b); // We want to read the ISR from PIC1
    return mask_1.inb();
  }
}
