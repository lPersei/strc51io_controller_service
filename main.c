#include "strc51io.h"

void main(){
	//inicjalizacja zmiennych
	char c[4]; 
	char d;
	int i;
	//Jednoczesnie mozna otworzyc tylko jedno urzadzenie wejscia i jedno urzadzenie wyjscia
	devopen(RS232_INPUT); //Port rs232 -> Urzadzenie wejscia
	devopen(RS232_OUTPUT); //Port rs232 -> Urzadzenie wyjscia
	scanf("%s %d", &c, &i);
	printf("string: %s, hex: %x, oct: %o, dec: %d", c, i, i, i);
	devopen(LCD_OUTPUT); //Wyswietlacz LCD -> Urzadzenie wyjscia
	lcd_clear_screen();
	printf("string: %s, hex: %x, oct: %o, dec: %d", c, i, i, i);
	devopen(LED_OUTPUT); //Wyswietlacz LED -> Urzadzenie wyjscia
	putchar(cyfra_3);
	putchar(cyfra_4);
	putchar(cyfra_5);
	putchar(cyfra_6);

	devopen(KB_INPUT); //Klawiatura -> Urzadzenie wejscia
	devopen(RS232_OUTPUT); //Port rs232 -> Urzadzenie wyjscia
	d = getchar();
	putchar(d + 'a');

	devopen(NO_INPUT_DEVICE); //Zamkniecie urzadzenia wejscia
	devopen(NO_OUTPUT_DEVICE); //Zamkniecie urzadzenia wyjscia

	//generacja dzwieku BUZZERa
    for(;;){
		buzzer_mksound(100);
    }
}