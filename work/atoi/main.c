#include <stdio.h>
#include "chartoi.h"

int main(int argc, char **argv){
	char i1[] = "1234";
	char i2[] = "-1345";

	printf("char string 1 is %s\n", i1);
	printf("char string 1 change to int  is %d\n", ChToInt(i1, 4));

	printf("char string 2 is %s\n", i2);
	printf("char string 2 change to int  is %d\n", ChToInt(i2, 5));

	return 0;

}
