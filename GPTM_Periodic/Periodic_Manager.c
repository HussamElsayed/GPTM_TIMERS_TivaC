/*
 * Periodic_Manager.c
 *
 *  Created on: Aug 29, 2023
 *      Author: Hussam Elsayed
 */
#include "Periodic_Manager.h"

void GPIO_Inint (void)
{  /* Initialization for portF pins 1,2 and 3 as digital and output */
    SYSCTL_RCGCGPIO_R |= (1<<5) ;
    while(SYSCTL_RCGCGPIO_R == 0){}
    GPIO_PORTF_DIR_R |= 0x0E ;
    GPIO_PORTF_DEN_R |= 0x0E ;
}

void GPTM_Init  (void)
{   /* Configure Timer 0 as Periodic, 32-bit mode and 1 melli-second for interval */
    SYSCTL_RCGCTIMER_R |= (1<<0) ;
    while(SYSCTL_RCGCTIMER_R ==0) {}
    TIMER0_CTL_R |= 0 ;
    TIMER0_CFG_R &= ~0x07 ;
    TIMER0_TAMR_R |= 0x02 ;
    TIMER0_TAILR_R = 15999 ;
    TIMER0_ICR_R |= (1<<0) ;
    TIMER0_CTL_R |= (1<<0) ;
}

void GPTM_Delay (int Delay_Ms)           // Delay using GPTM timer periodic mode
{
    int i ;
    for( i=0 ; i<Delay_Ms ; i++)
    {
    while ((TIMER0_RIS_R & 0x01) == 0 ) ;  // Waiting for timer elapse

    TIMER0_ICR_R = 0x01 ;                 // Clear timer flag

    }
}

void Start_App()
{
    GPIO_Inint() ;
    GPTM_Init() ;
    while(1)
    {
        GPIO_PORTF_DATA_R ^= 0x0E ;
        GPTM_Delay(1000) ;
    }
}
