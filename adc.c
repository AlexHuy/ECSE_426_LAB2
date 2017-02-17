/**
  ******************************************************************************
  * File Name          : ADC.c
  * Description        : This file provides code for the configuration
  *                      of the ADC instances.
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
#include "adc.h"
#include "FIR_C.h"

/* USER CODE BEGIN 0 */
ADC_HandleTypeDef ADC1_Handle;
ADC_InitTypeDef ADC1_Init;
ADC_ChannelConfTypeDef ADC1_Channel;

void init_ADC() {
	//Initialize ADC_InitTypeDef instance
	//Sets all ADCs clock to their maximum value of half the system clock (4MHz).
	ADC1_Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
	//Sets resolution of ADC to 12bit.
	ADC1_Init.Resolution = ADC_RESOLUTION_12B;
	ADC1_Init.DataAlign = ADC_DATAALIGN_RIGHT;
	//Disables multi channel scanning and instead only uses a single channel.
	ADC1_Init.ScanConvMode = DISABLE;
	ADC1_Init.EOCSelection = DISABLE;
	//Sets the ADC to not continuously convert data.
	ADC1_Init.ContinuousConvMode = ENABLE;
	ADC1_Init.DMAContinuousRequests = DISABLE;
	ADC1_Init.NbrOfConversion = 1;
	ADC1_Init.DiscontinuousConvMode = DISABLE;
	ADC1_Init.NbrOfDiscConversion = 0;
	ADC1_Init.ExternalTrigConv = ADC_SOFTWARE_START;
	ADC1_Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	
	//Initialize ADC_HandleTypeDef instance
	ADC1_Handle.Instance = ADC1;
	ADC1_Handle.Init = ADC1_Init;
	
	//Initialize ADC_ChannelConfTypeDef instance
	//Sets up the temperature sensor to work (located channel 16).
	ADC1_Channel.Channel = ADC_CHANNEL_16;
	ADC1_Channel.Rank = 1; 
	ADC1_Channel.SamplingTime = ADC_SAMPLETIME_480CYCLES; 
	ADC1_Channel.Offset = 0;
	
	HAL_ADC_Init(&ADC1_Handle);
	HAL_ADC_ConfigChannel(&ADC1_Handle, &ADC1_Channel);
	HAL_ADC_Start(&ADC1_Handle);
}

float read_temp() {
	float adc_data;
	struct FIR_coeff coeff;
	coeff.b0 = 0.1;
	coeff.b1 = 0.15;
	coeff.b2 = 0.5;
	coeff.b3 = 0.15;
	coeff.b4 = 0.1;
	
     adc_data = HAL_ADC_GetValue(&ADC1_Handle);
     return adc_data;
	/*HAL_StatusTypeDef status;
	status = HAL_ADC_PollForConversion(&ADC1_Handle, 0);
	if(status == HAL_OK) {
		adc_data = HAL_ADC_GetValue(&ADC1_Handle);
		return FIR_C(adc_data, &coeff, 4);
	}
	else if(status == HAL_ERROR || status == HAL_TIMEOUT)
		return -1;*/
}
/* USER CODE END 0 */



/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
