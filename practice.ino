#include <avr/io.h>
int main(void)
{
	unsigned char TB7SEG[] = {
	0b00111111, 0b00000110, 0b01011011, 0b01001111,
	0b01100110, 0b01101101, 0b01111101, 0b00000111,
	0b01111111, 0b01101111, 0b01110111, 0b01111100,
	0b00111001, 0b01011110, 0b01111001, 0b01110001,
        0b01010010};
	signed char DISPLY;
	signed char SWITCH,MODE,x1,x2,y;
	DDRD = 0xFF; //output D
        DDRC = 0x00; //input C
	DDRB = 0x00; //input B
	while(1)
	{
		SWITCH = PINB;

		x1 = SWITCH & 0b00000111;

                x2 = SWITCH & 0b00111000;
                x2 = x2 >> 3;
                
                MODE = PINC;
                MODE = MODE & 0b00011000;
                MODE = MODE >> 3;
                
                if(MODE == 0)
                {
                  y = x1;
                }
                else if(MODE == 1)
                {
                  y = x2;
                }
                else if(MODE == 2)
                {
                  y = x1+x2;
                }
                else
                {
                  y = x1-x2;
                  if(y < 0)
                    y = 16;
                }
                
		DISPLY = TB7SEG[y];
		PORTD = ~DISPLY;
	}
}
