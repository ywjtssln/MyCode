#include "scan.h"

int main(int argc, char **argv){

	char *text = "This is an example! we got ming z here, and ming zz here,"
				   "and mings zww here, and mingb zjj here";
	char *name = "m*g z*";

	
	printf("TEXT: %s \n", text);
	printf("KEY WORD: %s \n", name);

	scan(text, name);

	return 0;
}
