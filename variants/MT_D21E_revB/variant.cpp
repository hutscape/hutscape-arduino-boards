/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/*
 * Modified 9 December 2016 by Justin Mattair
 *   for MattairTech boards (www.mattairtech.com)
 *
 * See README.md for documentation and pin mapping information
 */


#include "variant.h"

/*
 * Pins descriptions
 */
const PinDescription g_APinDescription[]=
{
	// 0..1 are unused by default (pins in use by 32.768KHz crystal, which is used by the Arduino core)
	{ PORTA,  0, PIO_MULTI, PER_ATTR_DRIVE_STRONG, PIN_ATTR_DIGITAL, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE },
	{ PORTA,  1, PIO_MULTI, PER_ATTR_DRIVE_STRONG, PIN_ATTR_DIGITAL, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE },
	
	// 2..9 - Analog capable pins (DAC available on 2)
	{ PORTA,  2, PIO_MULTI, PER_ATTR_DRIVE_STRONG, (PIN_ATTR_ADC|PIN_ATTR_DAC|PIN_ATTR_DIGITAL), NOT_ON_TIMER, ADC_Channel0, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // ADC/AIN[0] / DAC
	{ PORTA,  3, PIO_MULTI, PER_ATTR_DRIVE_STRONG, (PIN_ATTR_ADC|PIN_ATTR_REF|PIN_ATTR_DIGITAL), NOT_ON_TIMER, ADC_Channel1, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // ADC/AIN[1]
	{ PORTA,  4, PIO_MULTI, PER_ATTR_DRIVE_STRONG, (PIN_ATTR_ADC|PIN_ATTR_REF|PIN_ATTR_DIGITAL|PIN_ATTR_EXTINT), NOT_ON_TIMER, ADC_Channel4, EXTERNAL_INT_4, GCLK_CCL_NONE }, // ADC/AIN[4]
#if (SAMD || SAMC)
	{ PORTA,  5, PIO_MULTI, PER_ATTR_DRIVE_STRONG, (PIN_ATTR_ADC|PIN_ATTR_DIGITAL|PIN_ATTR_EXTINT), NOT_ON_TIMER, ADC_Channel5, EXTERNAL_INT_5, GCLK_CCL_NONE }, // ADC/AIN[5]
#elif (SAML)
	{ PORTA,  5, PIO_MULTI, PER_ATTR_DRIVE_STRONG, (PIN_ATTR_ADC|PIN_ATTR_DAC|PIN_ATTR_DIGITAL|PIN_ATTR_EXTINT), NOT_ON_TIMER, ADC_Channel5, EXTERNAL_INT_5, GCLK_CCL_NONE },
#endif
	{ PORTA,  6, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD), (PIN_ATTR_ADC|PIN_ATTR_DIGITAL|PIN_ATTR_TIMER), TCC1_CH0, ADC_Channel6, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // ADC/AIN[6], LED
#if (SAMD)
	{ PORTA,  7, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD), (PIN_ATTR_ADC|PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_COM), TCC1_CH1, ADC_Channel7, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // ADC/AIN[7]
	{ PORTA,  8, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD), (PIN_ATTR_ADC|PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_EXTINT|PIN_ATTR_COM), TCC0_CH0, ADC_Channel16, EXTERNAL_INT_NMI, GCLK_CCL_NONE }, // TCC0/WO[0]
	{ PORTA,  9, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD), (PIN_ATTR_ADC|PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_EXTINT|PIN_ATTR_COM), TCC0_CH1, ADC_Channel17, EXTERNAL_INT_9, GCLK_CCL_NONE }, // TCC0/WO[1]
#elif (SAML)
	{ PORTA,  7, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD), (PIN_ATTR_ADC|PIN_ATTR_DIGITAL|PIN_ATTR_TIMER), TCC1_CH1, ADC_Channel7, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // ADC/AIN[7]
	{ PORTA,  8, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD), (PIN_ATTR_ADC|PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_EXTINT), TCC0_CH0, ADC_Channel16, EXTERNAL_INT_NMI, GCLK_CCL_NONE }, // TCC0/WO[0]
	{ PORTA,  9, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD), (PIN_ATTR_ADC|PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_EXTINT), TCC0_CH1, ADC_Channel17, EXTERNAL_INT_9, GCLK_CCL_NONE }, // TCC0/WO[1]
#elif (SAMC)
	{ PORTA,  7, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD), (PIN_ATTR_ADC|PIN_ATTR_DIGITAL|PIN_ATTR_TIMER), TCC1_CH1, ADC_Channel7, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // ADC/AIN[7]
	{ PORTA,  8, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD|PER_ATTR_ADC_ALT), (PIN_ATTR_ADC|PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_EXTINT), TCC0_CH0, ADC_Channel10, EXTERNAL_INT_NMI, GCLK_CCL_NONE }, // TCC0/WO[0]
	{ PORTA,  9, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD|PER_ATTR_ADC_ALT), (PIN_ATTR_ADC|PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_EXTINT), TCC0_CH1, ADC_Channel11, EXTERNAL_INT_9, GCLK_CCL_NONE }, // TCC0/WO[1]
#endif
	
	// 10..11 - SERCOM/UART (Serial1) or Analog or Digital functions
#if (SAMD)
	{ PORTA, 10, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_ALT|PER_ATTR_SERCOM_STD), (PIN_ATTR_ADC|PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_SERCOM|PIN_ATTR_COM), TCC0_CH2, ADC_Channel18, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // TX: SERCOM0/PAD[2]
	{ PORTA, 11, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_ALT|PER_ATTR_SERCOM_STD), (PIN_ATTR_ADC|PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_SERCOM|PIN_ATTR_COM), TCC0_CH3, ADC_Channel19, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // RX: SERCOM0/PAD[3]
#elif (SAML)
	{ PORTA, 10, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_ALT|PER_ATTR_SERCOM_STD), (PIN_ATTR_ADC|PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_SERCOM), TCC0_CH2, ADC_Channel18, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // TX: SERCOM0/PAD[2]
	{ PORTA, 11, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_ALT|PER_ATTR_SERCOM_STD), (PIN_ATTR_ADC|PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_SERCOM), TCC0_CH3, ADC_Channel19, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // RX: SERCOM0/PAD[3]
#elif (SAMC)
	{ PORTA, 10, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_ALT|PER_ATTR_SERCOM_STD), (PIN_ATTR_ADC|PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_SERCOM), TCC0_CH2, ADC_Channel10, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // TX: SERCOM0/PAD[2]
	{ PORTA, 11, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_ALT|PER_ATTR_SERCOM_STD), (PIN_ATTR_ADC|PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_SERCOM), TCC0_CH3, ADC_Channel11, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // RX: SERCOM0/PAD[3]
#endif
	
	// 12..13 pins don't exist
	{ NOT_A_PORT,  0, PIO_NOT_A_PIN, PER_ATTR_NONE, PIN_ATTR_NONE, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // Unused
	{ NOT_A_PORT,  0, PIO_NOT_A_PIN, PER_ATTR_NONE, PIN_ATTR_NONE, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // Unused
	
	// 14..15 - SERCOM/UART (Serial2) or Digital functions
#if (SAMD)
	{ PORTA, 14, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD|PER_ATTR_SERCOM_STD), (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_SERCOM|PIN_ATTR_EXTINT), TC3_CH0, No_ADC_Channel, EXTERNAL_INT_14, GCLK_CCL_NONE }, // TC3/WO[0], HOST_ENABLE
	{ PORTA, 15, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD|PER_ATTR_SERCOM_STD), (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_SERCOM), TC3_CH1, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // TC3/WO[1], ATN
#elif (SAML || SAMC)
	{ PORTA, 14, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD|PER_ATTR_SERCOM_STD), (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_SERCOM|PIN_ATTR_EXTINT), TC4_CH0, No_ADC_Channel, EXTERNAL_INT_14, GCLK_CCL_NONE }, // TC3/WO[0], HOST_ENABLE
	{ PORTA, 15, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD|PER_ATTR_SERCOM_STD), (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_SERCOM), TC4_CH1, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // TC3/WO[1], ATN
#endif
	
	// 16..17 SERCOM/I2C (Wire) or Digital functions
	{ PORTA, 16, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD|PER_ATTR_SERCOM_STD), (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_SERCOM|PIN_ATTR_EXTINT), TCC2_CH0, No_ADC_Channel, EXTERNAL_INT_0, GCLK_CCL_NONE }, // SDA: SERCOM1/PAD[0]
	{ PORTA, 17, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD|PER_ATTR_SERCOM_STD), (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_SERCOM|PIN_ATTR_EXTINT), TCC2_CH1, No_ADC_Channel, EXTERNAL_INT_1, GCLK_CCL_NONE }, // SCL: SERCOM1/PAD[1]
	
	// 18..23 - SERCOM/SPI (SPI) or Digital functions (pins 20..21 do not exist)
	{ PORTA, 18, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_SERCOM_ALT), (PIN_ATTR_DIGITAL|PIN_ATTR_SERCOM|PIN_ATTR_EXTINT), NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_2, GCLK_CCL_NONE }, // SPI MOSI: SERCOM3/PAD[2] (PIN_ATTR_SERCOM_ALT)
	{ PORTA, 19, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_SERCOM_ALT), (PIN_ATTR_DIGITAL|PIN_ATTR_SERCOM|PIN_ATTR_EXTINT|PIN_ATTR_COM), NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_3, GCLK_CCL_NONE }, // SPI SCK: SERCOM3/PAD[3] (PIN_ATTR_SERCOM_ALT)
	{ NOT_A_PORT,  0, PIO_NOT_A_PIN, PER_ATTR_NONE, PIN_ATTR_NONE, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // Unused
	{ NOT_A_PORT,  0, PIO_NOT_A_PIN, PER_ATTR_NONE, PIN_ATTR_NONE, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // Unused
#if (SAMD)
	{ PORTA, 22, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD|PER_ATTR_SERCOM_STD), (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_SERCOM|PIN_ATTR_EXTINT), TC4_CH0, No_ADC_Channel, EXTERNAL_INT_6, GCLK_CCL_NONE }, // SPI MISO: SERCOM3/PAD[0]
	{ PORTA, 23, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD|PER_ATTR_SERCOM_STD), (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_SERCOM|PIN_ATTR_EXTINT|PIN_ATTR_COM), TC4_CH1, No_ADC_Channel, EXTERNAL_INT_7, GCLK_CCL_NONE }, // SPI SS: SERCOM3/PAD[1]
#elif (SAML || SAMC)
	{ PORTA, 22, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD|PER_ATTR_SERCOM_STD), (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_SERCOM|PIN_ATTR_EXTINT), TC0_CH0, No_ADC_Channel, EXTERNAL_INT_6, GCLK_CCL_NONE }, // SPI MISO: SERCOM3/PAD[0]
	{ PORTA, 23, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD|PER_ATTR_SERCOM_STD), (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_SERCOM|PIN_ATTR_EXTINT), TC0_CH1, No_ADC_Channel, EXTERNAL_INT_7, GCLK_CCL_NONE }, // SPI SS: SERCOM3/PAD[1]
#endif
	
	// 24..26 - USB_NEGATIVE and USB_POSITIVE, pin 26 does not exist
#if (SAMD)
	{ PORTA, 24, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD), (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_COM), TC5_CH0, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // USB/DM
	{ PORTA, 25, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD), (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_COM), TC5_CH1, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // USB/DP
#elif (SAML || SAMC)
	{ PORTA, 24, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD), (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_COM), TC1_CH0, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // USB/DM
	{ PORTA, 25, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PER_ATTR_TIMER_STD), (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_COM), TC1_CH1, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // USB/DP
#endif
	{ NOT_A_PORT,  0, PIO_NOT_A_PIN, PER_ATTR_NONE, PIN_ATTR_NONE, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // Unused
	
	// 27..29 Digital functions / A/CS (pin 29 does not exist)
	{ PORTA, 27, PIO_MULTI, PER_ATTR_DRIVE_STRONG, (PIN_ATTR_DIGITAL|PIN_ATTR_EXTINT), NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_15, GCLK_CCL_NONE }, // A/CS
#if (SAMD || SAMC)
	{ PORTA, 28, PIO_MULTI, PER_ATTR_DRIVE_STRONG, (PIN_ATTR_DIGITAL|PIN_ATTR_EXTINT), NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_8, GCLK_CCL_NONE }, // 
#elif (SAML)
	{ NOT_A_PORT,  0, PIO_NOT_A_PIN, PER_ATTR_NONE, PIN_ATTR_NONE, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // Unused
#endif
	{ NOT_A_PORT,  0, PIO_NOT_A_PIN, PER_ATTR_NONE, PIN_ATTR_NONE, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // Unused
	
	// 30..31 Digital functions / Debug interface (SWD CLK and SWD IO)
	{ PORTA, 30, PIO_MULTI, (PER_ATTR_DRIVE_STRONG), (PIN_ATTR_DIGITAL|PIN_ATTR_EXTINT), NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_10, GCLK_CCL_NONE }, // TCC1/WO[0] / SWD CLK
	{ PORTA, 31, PIO_MULTI, (PER_ATTR_DRIVE_STRONG), (PIN_ATTR_DIGITAL|PIN_ATTR_EXTINT), NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_11, GCLK_CCL_NONE }, // TCC1/WO[1] / SWD IO
} ;

#if (SAMD)
const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC5 } ;
#elif (SAML21 || SAMC21)
const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC0, TC1, TC2 } ;
#endif

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;
#if (SAML)
SERCOM sercom4( SERCOM4 ) ;
SERCOM sercom5( SERCOM5 ) ;
#endif

#if defined(ONE_UART) || defined(TWO_UART)
Uart Serial1( SERCOM_INSTANCE_SERIAL1, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;

void SERCOM0_Handler()
{
  Serial1.IrqHandler();
}
#endif

#if defined(TWO_UART)
Uart Serial2( SERCOM_INSTANCE_SERIAL2, PIN_SERIAL2_RX, PIN_SERIAL2_TX, PAD_SERIAL2_RX, PAD_SERIAL2_TX ) ;

void SERCOM2_Handler()
{
  Serial2.IrqHandler();
}
#endif
