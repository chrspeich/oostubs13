/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                 Technische Informatik II                                      *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                               *
 *                                      O _ S T R E A M                                          *
 *                                                                                               *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "object/o_stream.h"

static char* ziffern = "0123456789ABCDEF";

/** \todo implementieren **/
O_Stream::O_Stream() : Stringbuffer(){
  /* ToDo: insert sourcecode */
	base = dec;
}

/** \todo implementieren **/
O_Stream::~O_Stream(){
  /* ToDo: insert sourcecode */
}

/** \todo implementieren **/
O_Stream& O_Stream::operator << (char value) {
  	put(value);	
	/* ToDo: insert sourcecode */
  return *this;
}

/** \todo implementieren **/
O_Stream& O_Stream::operator << (unsigned char value) {
	
	put(value);	
	
  /* ToDo: insert sourcecode */
  return *this;
}

/** \todo implementieren **/
O_Stream& O_Stream::operator << (char* value) {
	
	for(int n = 0; value[n]!='\0'; n++) {
		put(value[n]);
	}		

  /* ToDo: insert sourcecode */
  return *this;
}

/** \todo implementieren **/
O_Stream& O_Stream::operator << (const char* value) {

	for(int n = 0; value[n]!='\0'; n++) {
		put(value[n]);
	}

  /* ToDo: insert sourcecode */
  return *this;
}

/** \todo implementieren **/
O_Stream& O_Stream::operator << (short value) {
  /* ToDo: insert sourcecode */
	
	this->operator<<((long)value);		
	
  return *this;
}

/** \todo implementieren **/
O_Stream& O_Stream::operator << (unsigned short value) {

	this->operator<<((unsigned long)value);  


  return *this;
}

/** \todo implementieren **/
O_Stream& O_Stream::operator << (int value) {
  /* ToDo: insert sourcecode */

	this->operator<<((long)value);

  return *this;
}

/** \todo implementieren **/
O_Stream& O_Stream::operator << (unsigned int value) {
  /* ToDo: insert sourcecode */

	this->operator<<((unsigned long)value);

  return *this;

}

/** \todo implementieren **/
O_Stream& O_Stream::operator << (long value) {
  /* ToDo: insert sourcecode */
	
	if (value<0) {
		put('-');
		value = value * -1;
	}

	this->operator<<((unsigned long) value);	
  return *this;
}

/** \todo implementieren **/
O_Stream& O_Stream::operator << (unsigned long value) {
  /* ToDo: insert sourcecode */

	char zahl[sizeof(unsigned long)*32];
	int n=0;

	if (base>10) {
		put('0');
		put('x');

	}
	
	if (value == 0) {
		put(ziffern[0]);
	}

	while (value != 0) {
		int x = value%base;
		value = value/base;
		zahl[n] = ziffern[x];
		n++;
	}

	n--;

	while (n>=0) {
		put(zahl[n]);
		n--;
	}	


  return *this;
}

/** \todo implementieren **/
O_Stream& O_Stream::operator << (void* value) {

	put('*');
	
	this-> operator<<((unsigned int)value);

  return *this;
}

/** \todo implementieren **/
O_Stream& O_Stream::operator << (FGColor fgColor){

	flush();
	setfgColor((int)fgColor.color);

  return *this;
}

/** \todo implementieren **/
O_Stream& O_Stream::operator << (BGColor bgColor){
  /* ToDo: insert sourcecode */
	
	flush();
	setbgColor((int)bgColor.color);	

  return *this;
}

/** \todo implementieren **/
O_Stream& O_Stream::operator << (Blink blink){
  /* ToDo: insert sourcecode */
	
	flush();
	setblink(blink.blink);

  return *this;
}

/** \todo implementieren **/
O_Stream& endl (O_Stream& os) {
  /* ToDo: insert sourcecode */

	os.put('\n');
	os.flush();

  return os;
}

/** \todo implementieren **/
O_Stream& bin (O_Stream& os) {

	os.base = (enum O_Stream::Base)2;

  /* ToDo: insert sourcecode */
  return os;
}

/** \todo implementieren **/
O_Stream& oct (O_Stream& os) {
  /* ToDo: insert sourcecode */

	os.base = (enum O_Stream::Base)8;

  return os;
}

/** \todo implementieren **/
O_Stream& dec (O_Stream& os) {
  /* ToDo: insert sourcecode */

	os.base = (enum O_Stream::Base)10;

  return os;
}

/** \todo implementieren **/
O_Stream& hex (O_Stream& os) {
  /* ToDo: insert sourcecode */

	os.base = (enum O_Stream::Base)16;

  return os;
}

O_Stream& O_Stream::operator << (O_Stream& (*f) (O_Stream&)) {
  return f(*this);
}
