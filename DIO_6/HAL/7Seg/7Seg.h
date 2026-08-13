/*
 * 7Seg.h
 *
 *  Created on: Aug 5, 2026
 *      Author: compusoft
 */

#ifndef HAL_7SEG_7SEG_H_
#define HAL_7SEG_7SEG_H_

typedef struct
{
	u8 A_u8SegPort ;
	u8 A_u8SegType ;
	u8 A_u8CommPort;
	u8 A_u8CommPin ;
}Seg_Connections;

#define COMM_ANOED  1
#define COMM_CATH   0

void H7SEG_voidInit (Seg_Connections Seg) ;
void H7SEG_voidDisplayNumber (Seg_Connections Seg , u8 A_u8Number) ;
void H7SEG_voidOff (Seg_Connections Seg) ;

#endif /* HAL_7SEG_7SEG_H_ */
