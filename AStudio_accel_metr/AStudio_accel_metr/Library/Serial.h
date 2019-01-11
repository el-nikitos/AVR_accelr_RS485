
void Seral_open(unsigned char ubrr)	{
	//UBRRH = (unsigned char)(ubrr>>8);
	
	UBRRH = 0;
	UBRRL = (unsigned char)(ubrr);
	
	
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
	
}
 
 
 void Seral_write(byte data)	{
	 while ( !((UCSRA)&(1<<UDRE)) );
	 
	 UDR = data;
 }