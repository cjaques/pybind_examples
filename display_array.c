#include <stdio.h>
#include "display_array.h"

void loop_array(double * array, int N)
{
	int i;
	for(i = 0;i<N;i++)
	{
		printf("val[%d] = %f \n", i, array[i]);
	}
}

