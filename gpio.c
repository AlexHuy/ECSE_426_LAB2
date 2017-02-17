/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
/* USER CODE BEGIN 0 */
GPIO_InitTypeDef GPIOA_init;
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */
void init_GPIO() {
	GPIOA_init.Pin = GPIO_PIN_All;
	GPIOA_init.Mode = GPIO_MODE_OUTPUT_PP;
	GPIOA_init.Pull = GPIO_PULLUP;
	GPIOA_init.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	
	HAL_GPIO_Init(GPIOA, &GPIOA_init);
}
/* USER CODE END 1 */

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
     PXX   ------> YYYYYY
		 
		 Continue your GPIO configuration information as abow.
*/

/* USER CODE BEGIN 2 */
void set_LED(int digit, int segment) {
	switch(digit) {
		//Controls the first digit 1000
		case(0):
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET); 
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET); 				
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET); 			
			switch(segment) {
				//Sets the LCD to be equal to zero.
				case(0):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c				
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); //Pin g
				//Sets the LCD to be equal to one.
				case(1):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c				
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); //Pin g	
				//Sets the LCD to be equal to two.					
				case(2):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to three.
				case(3):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to four.					
				case(4):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to five.					
				case(5):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to six.					
				case(6):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to seven.					
				case(7):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); //Pin g		
				//Sets the LCD to be equal to eight.					
				case(8):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to nine.					
				case(9):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to NUL.				
				case(10):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); //Pin g					
			}
			//Controls the second digit 0100
		case(1):
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET); 
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET); 				
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET); 					
			switch(segment) {
//Sets the LCD to be equal to zero.
				case(0):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c				
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); //Pin g
				//Sets the LCD to be equal to one.
				case(1):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c				
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); //Pin g	
				//Sets the LCD to be equal to two.					
				case(2):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to three.
				case(3):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to four.					
				case(4):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to five.					
				case(5):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to six.					
				case(6):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to seven.					
				case(7):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); //Pin g		
				//Sets the LCD to be equal to eight.					
				case(8):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to nine.					
				case(9):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to NUL.				
				case(10):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); //Pin g	
			}
		//Controls the second digit 0010
		case(2):
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET); 
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET); 				
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET); 
			switch(segment) {
//Sets the LCD to be equal to zero.
				case(0):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c				
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); //Pin g
				//Sets the LCD to be equal to one.
				case(1):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c				
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); //Pin g	
				//Sets the LCD to be equal to two.					
				case(2):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to three.
				case(3):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to four.					
				case(4):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to five.					
				case(5):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to six.					
				case(6):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to seven.					
				case(7):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); //Pin g		
				//Sets the LCD to be equal to eight.					
				case(8):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to nine.					
				case(9):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to NUL.				
				case(10):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); //Pin g	
			}
		//Controls the second digit 0001
		case(3):
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET); 
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET); 				
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET); 
			switch(segment) {
//Sets the LCD to be equal to zero.
				case(0):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c				
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); //Pin g
				//Sets the LCD to be equal to one.
				case(1):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c				
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); //Pin g	
				//Sets the LCD to be equal to two.					
				case(2):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to three.
				case(3):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to four.					
				case(4):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to five.					
				case(5):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to six.					
				case(6):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to seven.					
				case(7):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); //Pin g		
				//Sets the LCD to be equal to eight.					
				case(8):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to nine.					
				case(9):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); //Pin g		
				//Sets the LCD to be equal to NUL.				
				case(10):
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET); //Pin a
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); //Pin b
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET); //Pin c
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Pin d
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //Pin e
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); //Pin f
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); //Pin g	
			}
	}
}
/* USER CODE END 2 */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
