/*
 * TIMER0.h
 *
 *  Created on: Aug 12, 2026
 *      Author: compusoft
 */

#ifndef HAL_TIMER0_TIMER0_H_
#define HAL_TIMER0_TIMER0_H_


#define TIMER0_PRESCALLER_1      1
#define TIMER0_PRESCALLER_8      8
#define TIMER0_PRESCALLER_64     64
#define TIMER0_PRESCALLER_256    256
#define TIMER0_PRESCALLER_1024   1024

#define TIMER0_OVF                 0
#define TIMER0_PWM_PHASE_CORRECT   1
#define TIMER0_PWM_FAST            2
#define TIMER0_CTC                 3


#define TCCR0   (*(volatile u8*)(0x53))
#define TCNT0   (*(volatile u8*)(0x52))
#define OCR0    (*(volatile u8*)(0x5c))
#define TIMSK   (*(volatile u8*)(0x59))
#define TIFR    (*(volatile u8*)(0x58))
#define SREG    (*(volatile u8*)(0x5f))

void MTimer0_voidInit (u16 A_u16Prescaller , u8 A_u8Mode) ;
void MTimer0_voidSetDesiredTime (u32 A_u32DisiredTimeInMicro , void (*fptr)(void)) ;
void MTimer0_voidGenetatePWM (u8 A_u8CompareValue) ;
void MTimer0_voidSetCallback(void (*fptr)(void));

#endif /* HAL_TIMER0_TIMER0_H_ */
