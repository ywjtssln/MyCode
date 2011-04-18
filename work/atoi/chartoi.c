#include "chartoi.h"

/*
 * Name: long ChToInt(const char *ch)
 * Func: if ch has int charactors, change to int and return
 *
 * Para: 
 *       const char *ch    Point to the text
 *       int n             Lenth of the string
 * 
 * ret : long 
 *
 * 2011.4.12 by zy
 *
 */
long ChToInt(const char *ch, int n)
{
	long i = 0;
	if(n > 1){
		return ch[0] == '-' ? (ChToInt(ch, n - 1)*10 - (ch[n-1] - '0'))
			: (ChToInt(ch, n - 1)*10 + (ch[n-1] - '0'));

	} else {
		return ch[0] == '-' ? 0 : (ch[0] - '0'); 

	}


}
