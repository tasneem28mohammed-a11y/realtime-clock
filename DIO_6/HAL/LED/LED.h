/*
 * LED.h
 *
 *  Created on: Aug 5, 2026
 *      Author: compusoft
 */

#ifndef HAL_LED_LED_H_
#define HAL_LED_LED_H_

void HLED_voidInit      (A_u8LedPort , A_u8LedPin) ;
void HLED_voidTurnOn    (A_u8LedPort , A_u8LedPin) ;
void HLED_voidTurnOff   (A_u8LedPort , A_u8LedPin) ;
void HLED_voidTogStatus (A_u8LedPort , A_u8LedPin) ;


#endif /* HAL_LED_LED_H_ */
