/*
 * TIMER0.c
 *
 *  Created on: Aug 12, 2026
 *      Author: compusoft
 */

#include "../../LIB/BitMath.h"
#include "../../LIB/STd_Types.h"
#include "../../MCAL/DIO/DIO.h"
#include "Timer0.h"
u32 G_u32Prescaller ;
u32 G_u32Counter ;
void (*Timer0_ptr)(void);

void MTimer0_voidInit(u16 A_u16Prescaller, u8 A_u8Mode)
{
    G_u32Prescaller = A_u16Prescaller;

    switch(A_u16Prescaller)
    {
        case TIMER0_PRESCALLER_1:
            SET_BIT(TCCR0, 0);
            CLR_BIT(TCCR0, 1);
            CLR_BIT(TCCR0, 2);
            break;

        case TIMER0_PRESCALLER_8:
            CLR_BIT(TCCR0, 0);
            SET_BIT(TCCR0, 1);
            CLR_BIT(TCCR0, 2);
            break;

        case TIMER0_PRESCALLER_64:
            SET_BIT(TCCR0, 0);
            SET_BIT(TCCR0, 1);
            CLR_BIT(TCCR0, 2);
            break;

        case TIMER0_PRESCALLER_256:
            CLR_BIT(TCCR0, 0);
            CLR_BIT(TCCR0, 1);
            SET_BIT(TCCR0, 2);
            break;

        case TIMER0_PRESCALLER_1024:
            SET_BIT(TCCR0, 0);
            CLR_BIT(TCCR0, 1);
            SET_BIT(TCCR0, 2);
            break;
    }


    switch(A_u8Mode)
    {
        case TIMER0_OVF:

            CLR_BIT(TCCR0, 6);
            CLR_BIT(TCCR0, 3);

            SET_BIT(SREG, 7);
            SET_BIT(TIMSK, 0);

            break;


        case TIMER0_PWM_PHASE_CORRECT:

            SET_BIT(TCCR0, 6);
            CLR_BIT(TCCR0, 3);

            MDIO_voidInitPin(
                DIO_PORTB,
                DIO_PIN3,
                DIO_OUTPUT
            );

            CLR_BIT(TCCR0, 4);
            SET_BIT(TCCR0, 5);

            break;


        case TIMER0_PWM_FAST:

            SET_BIT(TCCR0, 6);
            SET_BIT(TCCR0, 3);

            MDIO_voidInitPin(
                DIO_PORTB,
                DIO_PIN3,
                DIO_OUTPUT
            );

            CLR_BIT(TCCR0, 4);
            SET_BIT(TCCR0, 5);

            break;


        case TIMER0_CTC:
            CLR_BIT(TCCR0, 6);
            SET_BIT(TCCR0, 3);

            TCNT0 = 0;
            OCR0 = 124;

            SET_BIT(SREG, 7);
            SET_BIT(TIMSK, 1);


            break;
    }
}


void MTimer0_voidSetDesiredTime(
    u32 A_u32DisiredTimeInMicro,
    void (*fptr)(void)
)
{
    u32 L_u32OverFlowTime = 32 * G_u32Prescaller;

    f32 L_f32DesiredOvfCounts =
        A_u32DisiredTimeInMicro / L_u32OverFlowTime;

    u32 L_u32PreloadValue;

    Timer0_ptr = fptr;


    if(L_f32DesiredOvfCounts < 1.0)
    {
        G_u32Counter = 1;

        L_u32PreloadValue =
            256 - 256 * L_f32DesiredOvfCounts;

        TCNT0 = L_u32PreloadValue;
    }


    else if(L_f32DesiredOvfCounts == 1.0)
    {
        G_u32Counter = 1;
    }


    else if(L_f32DesiredOvfCounts > 1.0)
    {
        G_u32Counter = L_f32DesiredOvfCounts;

        if(
            (L_f32DesiredOvfCounts -
            (u32)L_f32DesiredOvfCounts) != 0
        )
        {
            G_u32Counter++;

            L_u32PreloadValue =
                256 *
                (
                    1 -
                    (
                        L_f32DesiredOvfCounts -
                        (u32)L_f32DesiredOvfCounts
                    )
                );

            TCNT0 = L_u32PreloadValue;
        }
    }
}

void MTimer0_voidGenetatePWM(u8 A_u8CompareValue)
{
    OCR0 = A_u8CompareValue;
}


void __vector_10(void) __attribute__((signal));

void __vector_10(void)
{
    static u16 L_u16Counter = 0;

    L_u16Counter++;

    if(L_u16Counter >= 1000)
    {
        L_u16Counter = 0;

        Timer0_ptr();
    }
}



void MTimer0_voidSetCallback(void (*fptr)(void))
{
    Timer0_ptr = fptr;
}
