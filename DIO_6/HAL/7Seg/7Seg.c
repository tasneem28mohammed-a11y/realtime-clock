/*
 * 7Seg.c
 *
 *  Created on: Aug 5, 2026
 *      Author: compusoft
 */

#include "../../LIB/BitMath.h"
#include "../../LIB/STd_Types.h"

#include "../../MCAL/DIO/DIO.h"

#include "7Seg.h"

u8 GR_u8Numbers [] =
{
		0x3F ,
		0x06 ,
		0x5B ,
		0x4F ,
		0x66 ,
		0x6D ,
		0x7D ,
		0x07 ,
		0x7F ,
		0x6F
};


void H7SEG_voidInit (Seg_Connections Seg)
{
	MDIO_voidInitPort(Seg.A_u8SegPort, 0xff) ;
	MDIO_voidInitPin(Seg.A_u8CommPort, Seg.A_u8CommPin, DIO_OUTPUT) ;
}
void H7SEG_voidDisplayNumber (Seg_Connections Seg , u8 A_u8Number)
{
	switch (Seg.A_u8SegType)
	{
	case COMM_ANOED :
		MDIO_voidSetPinValue(Seg.A_u8CommPort, Seg.A_u8CommPin, DIO_HIGH) ;
		break ;
	case COMM_CATH  :
		MDIO_voidSetPinValue(Seg.A_u8CommPort, Seg.A_u8CommPin, DIO_LOW) ;
		break ;
	}
	switch (Seg.A_u8SegType)
	{
	case COMM_ANOED :
		MDIO_voidSetPortValue(Seg.A_u8SegPort, ~GR_u8Numbers [A_u8Number]) ;
		break ;
	case COMM_CATH  :
		MDIO_voidSetPortValue(Seg.A_u8SegPort, GR_u8Numbers [A_u8Number]) ;
		break ;
	}
}
void H7SEG_voidOff (Seg_Connections Seg)
{
	switch (Seg.A_u8SegType)
	{
	case COMM_ANOED :
		MDIO_voidSetPinValue(Seg.A_u8CommPort, Seg.A_u8CommPin, DIO_LOW) ;
		break ;
	case COMM_CATH  :
		MDIO_voidSetPinValue(Seg.A_u8CommPort, Seg.A_u8CommPin, DIO_HIGH) ;
		break ;
	}
}
