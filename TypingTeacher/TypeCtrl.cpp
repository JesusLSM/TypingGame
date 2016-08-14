#include "TypeCtrl.h"



TypeCtrl::TypeCtrl()
{
	index = 0;
	memset(sentence, '\0', 256);
}
void TypeCtrl::AddCharacter(int input_key) 
{
	//printf("index : %d", index);
	char c_input = (char)input_key;
	sentence[index] = c_input;
	//printf("%s", sentence);
	index++;
}
void TypeCtrl::ResetCharacter()
{
	memset(sentence, '\0', 256);
	index = 0;
}
void TypeCtrl::RemoveCharacter()
{
	for (int i = 0; i < 256; i++)
	{
		if (sentence[i] == '\0' && i != 0)
		{
			memset(&sentence[i - 1], '\0', 1);
			//sentence[i - 1] == '\0'; // null이나 공백으로 해도 화면상에 나옴.. 왜그런지 모르겟음
			index--;
			return;
		}
	}
}
char* TypeCtrl::Sentence()
{
	return sentence;
}
TypeCtrl::~TypeCtrl()
{
}
