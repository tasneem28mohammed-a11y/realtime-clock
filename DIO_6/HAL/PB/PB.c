/*
 * PB.c
 *
 *  Created on: Aug 5, 2026
 *      Author: compusoft
 */
#include "../../LIB/BitMath.h"
#include "../../LIB/STd_Types.h"

#include "../../MCAL/DIO/DIO.h"

#include "PB.h"
#include <util/delay.h>

void HPB_voidInit (A_u8PbPort , A_u8PbPin)
{
	MDIO_voidInitPin(A_u8PbPort, A_u8PbPin, DIO_INPUT) ;
	MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin, DIO_HIGH) ;
}
u8   HPB_u8GetStatues (A_u8PbPort , A_u8PbPin)
{
	u8 L_u8PbStaus ;
	L_u8PbStaus =  MDIO_u8ReadPinValue(A_u8PbPort, A_u8PbPin) ;
	if (L_u8PbStaus == PB_PRESSED)
	{
		_delay_ms(20) ;
		if (MDIO_u8ReadPinValue(A_u8PbPort, A_u8PbPin) == PB_PRESSED)
		{
			L_u8PbStaus = PB_PRESSED ;
		    while (MDIO_u8ReadPinValue(A_u8PbPort, A_u8PbPin) == PB_PRESSED) ;
		    _delay_ms(20) ;
		}
		else
		{
			L_u8PbStaus = PB_NOT_PRESSED ;
		}
	}
	return L_u8PbStaus ;
}
