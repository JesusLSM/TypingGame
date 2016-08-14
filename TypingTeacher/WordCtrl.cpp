#include "WordCtrl.h"



WordCtrl::WordCtrl()
{
	numberOfwords = 0;
}

void WordCtrl::Read_File()
{
	char buf[256];
	fp = fopen("word_list.txt", "r");
	
	while (fscanf(fp, "%s", buf) != EOF)
	{
		numberOfwords++;
		words.push_back(buf);
	}
	
	fclose(fp);
}

vector<string> WordCtrl::Get_Words()
{
	return words;
}

int WordCtrl::Get_numberOfwords()
{
	return numberOfwords;
}
WordCtrl::~WordCtrl()
{
}
