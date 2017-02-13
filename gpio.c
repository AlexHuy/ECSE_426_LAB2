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
	GPIOA_init.Pull = GPIO_NOPULL;
	GPIOA_init.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	//GPIOA_init.Alternate = 
	
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
		case(0):
			switch(segment) {
				case(0):
					
				case(1):
					
				case(2):
					
				case(3):
					
				case(4):
					
				case(5):
					
				case(6):
					
				case(7):
					
				case(8):
					
				case(9):
					
			}
		case(1):
			switch(segment) {
				case(0):
					
				case(1):
					
				case(2):
					
				case(3):
					
				case(4):
					
				case(5):
					
				case(6):
					
				case(7):
					
				case(8):
					
				case(9):
					
			}
		case(2):
			switch(segment) {
				case(0):
					
				case(1):
					
				case(2):
					
				case(3):
					
				case(4):
					
				case(5):
					
				case(6):
					
				case(7):
					
				case(8):
					
				case(9):
					
			}
		case(3):
			switch(segment) {
				case(0):
					
				case(1):
					
				case(2):
					
				case(3):
					
				case(4):
					
				case(5):
					
				case(6):
					
				case(7):
					
				case(8):
					
				case(9):
					
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
