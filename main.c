#include <msp430.h> 
#include "ATD.h"


/*
 * main.c
 */

	unsigned int compare;


int main(void) {
	WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled

	P1DIR |= BIT0 | BIT6;                    // Set P1.0 to output direction
	P1OUT &= ~(BIT0 | BIT6);                    // Set P1.0 to output direction

	while (1) {

		compare = readRightSensor();
		P1DIR |= BIT0 | BIT6;                    // Set P1.0 to output direction

		if (compare < 0x1FF)
			P1OUT &= ~BIT0;                       // Clear P1.0 LED off
		else {
			P1OUT |= BIT0; 							// Set P1.0 LED on
		}

		compare = readMiddleSensor();
		P1DIR |= BIT0 | BIT6;                    // Set P1.0 to output direction

		if (compare < 0x1FF)
			P1OUT &= ~(BIT0 | BIT6);                       // Clear P1.0 LED off
		else
			P1OUT |= BIT0 | BIT6;                        // Set P1.0 LED on

		compare = readLeftSensor();

		P1DIR |= BIT0 | BIT6; // Set P1.0 to output direction

		if (compare < 0x1FF)
			P1OUT &= ~BIT6;                       // Clear P1.0 LED off
		else
			P1OUT |= BIT6;                        // Set P1.0 LED on
	}
}
//// ADC10 interrupt service routine
//#pragma vector=ADC10_VECTOR
//__interrupt void ADC10_ISR(void) {
//	__bic_SR_register_on_exit(CPUOFF);
//	// Clear CPUOFF bit from 0(SR)
//}



