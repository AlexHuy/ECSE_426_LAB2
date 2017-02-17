#include <stdint.h>
#include <math.h>
#include <stdint.h>

struct FIR_coeff {
	float b0;
	float b1;
	float b2;
	float b3;
	float b4;   
};
//Defines the structure of the coefficients for the FIR filter.
uint32_t FIR_C(uint32_t input, struct FIR_coeff* coeff, int Order);