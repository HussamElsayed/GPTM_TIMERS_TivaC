/*
 * PWM_Maneger.c
 *
 *  Created on: Aug 29, 2023
 *      Author: EME
 */

#include "PWM_Manager.h"


void Timer1A_PWM_Init(void) {

    SYSCTL_RCGCTIMER_R |= 0x02;
    SYSCTL_RCGCGPIO_R |= 0x20;

    while ((SYSCTL_RCGCTIMER_R & 0x02) == 0) {}

    GPIO_PORTF_AFSEL_R  |= 0x04;
    GPIO_PORTF_PCTL_R   |= 0x00000700;
    GPIO_PORTF_DEN_R    |= 0x04;



    TIMER1_CTL_R &= ~0x00000001;
    TIMER1_CFG_R = 0x00000004;
    TIMER1_TAMR_R = 0x0000000A;
    TIMER1_TAILR_R = 10000;
    TIMER1_TAMATCHR_R = 0;
    TIMER1_CTL_R |= 0x00000001U;
}

void Delay(void)         //Software delay for 1 melli-sec
{  int i=0 ;
for (; i<762*3 ;i++)
{}

}


void Start_APP(void)
{ Timer1A_PWM_Init() ;          // Call the Initialization function
while (1)                  // Super loop for the program
{
    int i=0 ;
    while (i<10000)      //Loop for increasing the brightness
    {
        TIMER1_TAMATCHR_R = i ;     // Update TAMATCHR register value each iteration
        Delay() ;                  // Delay to observe the brightness change
        i++ ;
    }

    while (i>0)            //Loop for decreasing the brightness
    {
        TIMER1_TAMATCHR_R = i ;   // Update TAMATCHR register value each iteration
        Delay() ;                   // Delay to observe the brightness change
        i-- ;
    }
}
}
