/*
 * EXTI.c
 *
 *  Created on: Aug 12, 2026
 *      Author: compusoft
 */
#include "../../LIB/BitMath.h"
#include "../../LIB/STd_Types.h"

#include "EXTI.h"

void (*EXTI0_ptr)(void) ;
void (*EXTI1_ptr)(void) ;
void (*EXTI2_ptr)(void) ;
void MEXTI0_voidInit (u8 A_u8Sensing)
{
	SET_BIT(SREG , 7) ;
	SET_BIT(GICR , 6) ;
	switch (A_u8Sensing)
	{
	case SENSE_LOW_LEVEL :
		CLR_BIT(MCUCR , 0) ;
		CLR_BIT(MCUCR , 1) ;
		break ;
	case SENSE_ON_CHANGE :
		SET_BIT(MCUCR , 0) ;
		CLR_BIT(MCUCR , 1) ;
		break ;
	case SENSE_FAILLING  :
		CLR_BIT(MCUCR , 0) ;
		SET_BIT(MCUCR , 1) ;
		break ;
	case SENSE_RISING    :
		SET_BIT(MCUCR , 0) ;
		SET_BIT(MCUCR , 1) ;
		break ;
	}
}
void MEXTI1_voidInit (u8 A_u8Sensing)
{
	SET_BIT(SREG , 7) ;
	SET_BIT(GICR , 7) ;
	switch (A_u8Sensing)
	{
	case SENSE_LOW_LEVEL :
		CLR_BIT(MCUCR , 2) ;
		CLR_BIT(MCUCR , 3) ;
		break ;
	case SENSE_ON_CHANGE :
		SET_BIT(MCUCR , 2) ;
		CLR_BIT(MCUCR , 3) ;
		break ;
	case SENSE_FAILLING  :
		CLR_BIT(MCUCR , 2) ;
		SET_BIT(MCUCR , 3) ;
		break ;
	case SENSE_RISING    :
		SET_BIT(MCUCR , 2) ;
		SET_BIT(MCUCR , 3) ;
		break ;
	}
}
void MEXTI2_voidInit (u8 A_u8Sensing)
{
	SET_BIT(SREG , 7) ;
	SET_BIT(GICR , 5) ;
	switch (A_u8Sensing)
	{
	case SENSE_FAILLING  :
		CLR_BIT(MCUCSR , 6) ;
		break ;
	case SENSE_RISING    :
		SET_BIT(MCUCSR , 6) ;
		break ;
	}
}
void MEXTI0_voidCallBack (void (*fptr)(void))
{
	EXTI0_ptr = fptr ;
}
void MEXTI1_voidCallBack (void (*fptr)(void))
{
	EXTI1_ptr = fptr ;
}
void MEXTI2_voidCallBack (void (*fptr)(void))
{
	EXTI2_ptr = fptr ;
}
//EXTI0 ISR
void __vector_1 (void)__attribute__((signal)) ;
void __vector_1 (void)
{
	EXTI0_ptr () ;
}

//EXTI1 ISR
void __vector_2 (void)__attribute__((signal)) ;
void __vector_2 (void)
{
	EXTI1_ptr () ;
}

//EXTI3 ISR
void __vector_3 (void)__attribute__((signal)) ;
void __vector_3 (void)
{
	EXTI2_ptr () ;
}


