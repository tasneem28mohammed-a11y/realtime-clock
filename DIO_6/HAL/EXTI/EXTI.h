/*
 * EXTI.h
 *
 *  Created on: Aug 12, 2026
 *      Author: compusoft
 */

#ifndef HAL_EXTI_EXTI_H_
#define HAL_EXTI_EXTI_H_


#define MCUCR   (*(volatile u8*)(0x55))
#define MCUCSR  (*(volatile u8*)(0x54))
#define GICR    (*(volatile u8*)(0x5B))
#define GIFR    (*(volatile u8*)(0x5A))
#define SREG    (*(volatile u8*)(0x5f))

#define SENSE_LOW_LEVEL  0
#define SENSE_ON_CHANGE  1
#define SENSE_FAILLING   2
#define SENSE_RISING     3


void MEXTI0_voidInit (u8 A_u8Sensing) ;
void MEXTI1_voidInit (u8 A_u8Sensing) ;
void MEXTI2_voidInit (u8 A_u8Sensing) ;
void MEXTI0_voidCallBack (void (*fptr)(void)) ;
void MEXTI1_voidCallBack (void (*fptr)(void)) ;
void MEXTI2_voidCallBack (void (*fptr)(void)) ;


#endif /* HAL_EXTI_EXTI_H_ */
