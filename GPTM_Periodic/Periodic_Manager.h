/*
 * Periodic_Manager.h
 *
 *  Created on: Aug 29, 2023
 *      Author: Hussam Elsayed
 */
#include "tm4c123gh6pm.h"

#ifndef PERIODIC_MANAGER_H_
#define PERIODIC_MANAGER_H_

/* Prototype for the functions */
void GPIO_Inint (void) ;
void GPTM_Init  (void) ;
void GPTM_Delay (int Delay_Ms) ;

#endif /* PERIODIC_MANAGER_H_ */
