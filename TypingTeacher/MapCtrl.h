#pragma once
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
class MapCtrl
{
private:
	char **Map;
	int m_size;
	int m_wordStartindex_y;
	string index_word[50];
	string m_word;
public:
	void CreateMap(int size);
	void PrintMap();	
	void SetWord(string word);
	void PushLine();
	int FindWord(char *word);
	void ClearFirstLine();
	MapCtrl();
	~MapCtrl();
};

