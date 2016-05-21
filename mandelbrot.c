/*
 ============================================================================
 Name        : mandelbrot.c
 Author      : Richard Kosegi
 Version     : 2012
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagPIXEL {
	int x;
	int y;
} PIXEL;

#define	ROWS	30
#define	COLS	80

int *array;

void dump(int *array, int cols, int rows);
void mandelbrot(int *array, int cols, int rows);
void setPixel(int *array, int cols, int rows, int x /* column */,
		int y /* row */, int value);


int main(void) {
	int arraySize = ROWS * COLS * sizeof(int);
	array = malloc(arraySize);
	memset(array, 0, arraySize);


	mandelbrot(array, COLS, ROWS);
	dump(array, COLS, ROWS);

	free(array);

	return EXIT_SUCCESS;
}


void dump(int *array, int cols, int rows) {
	int idx;
	for (idx = 0; idx < rows * cols; idx++) {

		//printf("[%u:%u:%u] = %u\n",col, row, idx,array[idx]);
		printf("%u", array[idx]);

		if (((idx + 1) % cols) == 0)
			printf("\n");

	}
}


void mandelbrot(int *array, int cols, int rows) {
	double MinRe = -2.0;
	double MaxRe = 2.0;
	double MinIm = -1.2;
	double MaxIm = MinIm+(MaxRe-MinRe)*rows/cols;
	double Re_factor = (MaxRe-MinRe)/(cols-1);
	double Im_factor = (MaxIm-MinIm)/(rows-1);
	unsigned MaxIterations = 30;
	unsigned n, x, y;

	for(y=0; y<rows; ++y)
	{
	    double c_im = MaxIm - y*Im_factor;
	    for( x=0; x<cols; ++x)
	    {
	        double c_re = MinRe + x*Re_factor;

	        double Z_re = c_re, Z_im = c_im;
	        int isInside = 1;
	        for( n=0; n<MaxIterations; ++n)
	        {
	            double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
	            if(Z_re2 + Z_im2 > 4)
	            {
	                isInside = 0;
	                break;
	            }
	            Z_im = 2*Z_re*Z_im + c_im;
	            Z_re = Z_re2 - Z_im2 + c_re;
	        }
	        if(isInside)
	        setPixel(array, cols, rows, x, y, 1);
	    }
	}
}

void setPixel(int *array, int cols, int rows, int x /* column */,
		int y /* row */, int value) {
	int idx = x + cols * y;

	array[idx] = value;

}
