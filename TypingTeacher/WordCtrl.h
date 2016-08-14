#pragma once
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <string>

using namespace std;
class WordCtrl
{
private:
	FILE *fp;
	int numberOfwords;
	vector<string> words;
public:
	void Read_File();
	vector<string> Get_Words();
	int Get_numberOfwords();
	WordCtrl();
	~WordCtrl();
};

