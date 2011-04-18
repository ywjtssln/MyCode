#include "min.h"

/*
 * Name: int MinDiff(const *int array, int len)
 * Func: Find the smallest difference in array, and return it
 *
 * Para: 
 *       const int *array      Point to the array
 *       int len               The lenth of teh array
 * 
 * Ret : void
 * 
 * O(n^2)
 *
 * 2011.4.14 by zy
 *
 */

int MinDiff(const int *array, int len)
{
	int diff = abs(array[0] - array[1]);
	int i = 0, j = 0;
	int tmp;

	for(; i < len ; i++)
		for(j = i + 1; j < len; j++){
			tmp = abs(array[i] - array[j]);
			diff = tmp < diff ? tmp : diff;
		}

	return diff;

}
