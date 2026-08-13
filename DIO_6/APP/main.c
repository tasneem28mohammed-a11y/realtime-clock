/*
 * main.c
 *
 *  Created on: Aug 8, 2026
 *      Author: compusoft
 */

#include "../LIB/BitMath.h"
#include "../LIB/STd_Types.h"

#include "../MCAL/DIO/DIO.h"
#include "../HAL/LED/LED.h"
#include "../HAL/TIMER0/TIMER0.h"
#include "../HAL/PB/PB.h"
#include "../HAL/7Seg/7Seg.h"
#include "../HAL/EXTI/EXTI.h"
#include <util/delay.h>

volatile u8 G_u8Seconds = 0;
volatile u8 G_u8Minutes = 0;
volatile u8 G_u8Hours   = 0;

Seg_Connections SEG1 =
{ DIO_PORTD,COMM_CATH, DIO_PORTC, DIO_PIN0};

Seg_Connections SEG2 =
{DIO_PORTD,COMM_CATH, DIO_PORTC,DIO_PIN1};

Seg_Connections SEG3 =
{ DIO_PORTD, COMM_CATH, DIO_PORTC, DIO_PIN2};

Seg_Connections SEG4 =
{DIO_PORTD, COMM_CATH, DIO_PORTC,DIO_PIN3};

Seg_Connections SEG5 =
{DIO_PORTD,COMM_CATH,DIO_PORTC,DIO_PIN4};

Seg_Connections SEG6 =
{DIO_PORTD,COMM_CATH,DIO_PORTC,DIO_PIN5};


void RTC_voidUpdateTime(void)
{
    G_u8Seconds++;
    if(G_u8Seconds >= 60){
        G_u8Seconds = 0;
        G_u8Minutes++;

        if(G_u8Minutes >= 60)
        {
            G_u8Minutes = 0;
            G_u8Hours++;

            if(G_u8Hours >= 24)
            {
                G_u8Hours = 0;
            }
        }
    }
}

void main(void)
{
    u8 L_u8SecTens;
    u8 L_u8SecUnits;

    u8 L_u8MinTens;
    u8 L_u8MinUnits;

    u8 L_u8HourTens;
    u8 L_u8HourUnits;


    H7SEG_voidInit(SEG1);
    H7SEG_voidInit(SEG2);
    H7SEG_voidInit(SEG3);
    H7SEG_voidInit(SEG4);
    H7SEG_voidInit(SEG5);
    H7SEG_voidInit(SEG6);


    H7SEG_voidOff(SEG1);
    H7SEG_voidOff(SEG2);
    H7SEG_voidOff(SEG3);
    H7SEG_voidOff(SEG4);
    H7SEG_voidOff(SEG5);
    H7SEG_voidOff(SEG6);

    HPB_voidInit(DIO_PORTB, DIO_PIN0);
    HPB_voidInit(DIO_PORTB, DIO_PIN1);
    HPB_voidInit(DIO_PORTB, DIO_PIN2);
    HPB_voidInit(DIO_PORTB, DIO_PIN3);

    MTimer0_voidInit(TIMER0_PRESCALLER_64, TIMER0_CTC  );
     MTimer0_voidSetCallback(RTC_voidUpdateTime);

    while(1)
    {
        if(HPB_u8GetStatues(DIO_PORTB, DIO_PIN0) == PB_PRESSED)
        {
            G_u8Hours++;

            if(G_u8Hours >= 24)
            {
                G_u8Hours = 0;
            }
        }

        if(HPB_u8GetStatues(DIO_PORTB, DIO_PIN1) == PB_PRESSED)
        {
            if(G_u8Hours == 0)
            {
                G_u8Hours = 23;
            }
            else
            {
                G_u8Hours--;
            }
        }
        if(HPB_u8GetStatues(DIO_PORTB, DIO_PIN2) == PB_PRESSED)
        {
            G_u8Minutes++;

            if(G_u8Minutes >= 60)
            {
                G_u8Minutes = 0;
            }
        }

        if(HPB_u8GetStatues(DIO_PORTB, DIO_PIN3) == PB_PRESSED)
        {
            if(G_u8Minutes == 0)
            {
                G_u8Minutes = 59;
            }
            else
            {
                G_u8Minutes--;
            }
        }

        L_u8SecTens   = G_u8Seconds / 10;
        L_u8SecUnits  = G_u8Seconds % 10;

        L_u8MinTens   = G_u8Minutes / 10;
        L_u8MinUnits  = G_u8Minutes % 10;

        L_u8HourTens  = G_u8Hours / 10;
        L_u8HourUnits = G_u8Hours % 10;

        H7SEG_voidOff(SEG1);
        H7SEG_voidOff(SEG2);
        H7SEG_voidOff(SEG3);
        H7SEG_voidOff(SEG4);
        H7SEG_voidOff(SEG5);
        H7SEG_voidOff(SEG6);

        H7SEG_voidDisplayNumber(SEG5, L_u8HourTens);

        _delay_ms(3);

        H7SEG_voidOff(SEG5);

        H7SEG_voidDisplayNumber(SEG6, L_u8HourUnits);

        _delay_ms(3);

        H7SEG_voidOff(SEG6);

        H7SEG_voidDisplayNumber(SEG3, L_u8MinTens);

        _delay_ms(3);

        H7SEG_voidOff(SEG3);

        H7SEG_voidDisplayNumber(SEG4, L_u8MinUnits);

        _delay_ms(3);

        H7SEG_voidOff(SEG4);

        H7SEG_voidDisplayNumber(SEG1, L_u8SecTens);

        _delay_ms(3);


        H7SEG_voidOff(SEG1);

        H7SEG_voidDisplayNumber(SEG2, L_u8SecUnits);

        _delay_ms(3);
    }
}
