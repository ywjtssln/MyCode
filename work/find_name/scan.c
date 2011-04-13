#include "scan.h"

typedef enum text_status{
	OUT_OF_WORD,
	IN_THE_WORD,
}TEXT_STATUS;

typedef struct word_msg{
	const char *begin;
	const char *end;
} WORD_MSG;


static const char *get_word(const char *ptr, WORD_MSG *msg)
{
	TEXT_STATUS status = OUT_OF_WORD;
	msg->begin = NULL;
	msg->end = NULL;
	
	while(*ptr){
		if((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z')
				|| *ptr == '?' || *ptr == '*'){
			if(status == OUT_OF_WORD){
				status = IN_THE_WORD;
				msg->begin = ptr;
			}
		} else {
			if(status == IN_THE_WORD){
				status = OUT_OF_WORD;
				msg->end = ptr;
				return ptr;
			}
		}
		++ptr;
	}
	if(status == IN_THE_WORD)
		msg->end = ptr;

	return ptr;
}
			

static int check_word(WORD_MSG *name, WORD_MSG *word)
{
	const char *name_ptr = name->begin;
	const char *word_ptr = word->begin;

	if(!name || !word)
		return 0;
	
	while((name_ptr != name->end) && (word_ptr != word->end)){
		switch(*name_ptr){
			case '?':
				break;
			case '*':
				while((*name_ptr == '*') || (*name_ptr == '?'))
					name_ptr++;

				if(name_ptr == name->end)
					return 1;

				while((*word_ptr != *name_ptr) && (word_ptr != word->end))
					word_ptr++;

				break;
			default:
				if(*name_ptr != *word_ptr)
					return 0;
		}

		word_ptr++;
		name_ptr++;

	}

	if((name_ptr == name->end) && (word_ptr == word->end))
		return 1;

	return 0;

}

static inline void print_word(WORD_MSG *n)
{
	const char *tmp_ptr = n->begin;

	while(tmp_ptr != n->end){
		printf("%c", *tmp_ptr);
		tmp_ptr++;
	}
	printf(" ");
}

/*
 * Name: void scan(const char* pszText, const char* pszName)
 * Func: Find Name in a text.
 *
 * Para: 
 *       const char *pszText   Point to the text
 *       const char *pszName   Point to the Name
 * 
 * ret : void
 *
 * 2011.4.12 by zy
 *
 */
void scan(const char* pszText, const char* pszName)
{
	int flag = 0;
	WORD_MSG name1, name2;
	WORD_MSG tmp1_word = {NULL, NULL};
	WORD_MSG tmp2_word = {NULL, NULL};
	const char *pos = pszText;

	if(!pszText || !pszName){
		printf("WARNING : para illegal.\n");
		return;
	}
	get_word(pszName, &name1);
	get_word(name1.end, &name2);

	while(*pos){
		pos = get_word(pos, &tmp2_word);

		if(check_word(&name1, &tmp1_word) && check_word(&name2, &tmp2_word)){
			printf("FIND NAME : ");
			print_word(&tmp1_word);
			print_word(&tmp2_word);
			printf("\n");
		}
		tmp1_word = tmp2_word;
	}
	printf("SCAN OVER.\n");

	return;
}
