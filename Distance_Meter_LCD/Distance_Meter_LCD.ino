#include	<LiquidCrystal.h>
LiquidCrystal	lcd(12,	11,	5,	4,	3,	2);			//	RS,	E,	DB4,	DB5,	DB6,	DB7
#define	trigPin	9
#define	echoPin	10
void	setup()	{
lcd.begin(16,	2);
pinMode(trigPin,	OUTPUT);
pinMode(echoPin,	INPUT);
lcd.print("Distance	Meter");
delay(1500);
lcd.clear();
}
void	loop()	{
long	duration,	distance;
digitalWrite(trigPin,	LOW);
delayMicroseconds(2);
digitalWrite(trigPin,	HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,	LOW);
duration	=	pulseIn(echoPin,	HIGH);
distance	=	duration	*	0.034	/	2;
lcd.setCursor(0,	0);
lcd.print("Distance:");
lcd.setCursor(0,	1);
lcd.print(distance);
lcd.print("	cm	");
delay(500);
}
