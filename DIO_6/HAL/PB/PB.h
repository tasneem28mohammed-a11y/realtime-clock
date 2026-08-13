/*
 * PB.h
 *
 *  Created on: Aug 5, 2026
 *      Author: compusoft
 */

#ifndef HAL_PB_PB_H_
#define HAL_PB_PB_H_


#define PB_PRESSED      0
#define PB_NOT_PRESSED  1

void HPB_voidInit (A_u8PbPort , A_u8PbPin) ;
u8   HPB_u8GetStatues (A_u8PbPort , A_u8PbPin) ;


#endif /* HAL_PB_PB_H_ */
