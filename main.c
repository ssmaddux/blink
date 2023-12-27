
/* R - PF1
	 B - PF2
	 G - PF3 */
	 
/* Clock enable portF                                      0x400FE000+0x608  => 0x400FE608 => RCGCPIO
	 Digitalise the portFpins                                0x40025000+0x51C  => 0x4002551C => GPIOFDEN
	 Direction for portF for configure Input or output       0x40025000+0x400  => 0x40025400 => GPIOPFDIR
	 Data to portF                                           0x40025000+0x000  => 0x400253FC => GPIOFDATA 
	 0000 0000 0000 0000 0000 0011 1111 1100 --- 0x000003FCU this gets added to line 9. To be able to write to the data register you need to make this change to the data register
*/

void delay(long d)
{
	while (d--);
}


int main()
{
	unsigned int *RCGCGPIO;
	RCGCGPIO = (unsigned int *)0x400FE608U;
	*RCGCGPIO = 0x20U; // clock for port F ON

	
	unsigned int *GPIOFDEN;
	GPIOFDEN = (unsigned int *)0x4002551CU;
	*GPIOFDEN = 0x0000000EU; // PF1,PF2,PF3 are digitalised. Also this is the same conversion for line 30

	
	unsigned int *GPIOPFDIR;
	GPIOPFDIR = (unsigned int *)0x40025400U;
	*GPIOPFDIR = 0x0EU; // PF1,PF2,PF3 as output
	
	unsigned int *GPIOFDATA;
	GPIOFDATA = (unsigned int *)0x400253FCU;
	
	

	

	while(1)
	{
		*GPIOFDATA = 0x08U; //  Glow PF1 Green led
		delay(1000000);
		//*GPIOFDATA = 0x00U; //  turn off
		delay(1000000);
		*GPIOFDATA = 0x02U; // Glow Red
		delay(1000000);
		*GPIOFDATA = 0x04U; // Glow Blue
		delay(1000000);
	}
}
