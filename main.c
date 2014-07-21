#include <avr/io.h>
#include <lcd.h>
#include <delay.h>

int main(void)
{
	DDRA=0x00;
	PORTA=0x00;
	DDRB=0xF0;
	PORTB=0x00;
	
	lcd_init();
	lcd_gotoxy(0,1);
	lcd_string("show hand");
	
	while(1)
	{
	
	
		if(bit_is_clear(PINA,PA5))
		{
			PORTB=0x80;
			lcd_gotoxy(0,1);
			lcd_string("left turn");
		}
		
		else
		if(bit_is_clear(PINA,PA2))
		{
			PORTB=0xA0;
			lcd_gotoxy(0,1);
			lcd_string("Forward  ");
		}
		
		else
		if(bit_is_clear(PINA,PA1))
		{
			PORTB=0x20;
			lcd_gotoxy(0,1);
			lcd_string("right turn");
		}
		
		else
		{
			PORTB=0x00;
			lcd_gotoxy(0,1);
			lcd_string("stop      ");
			delayms(100);
			lcd_gotoxy(0,1);
			lcd_string("show hand ");
		}
	}
}