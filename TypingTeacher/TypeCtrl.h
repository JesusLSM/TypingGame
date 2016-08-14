#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;
class TypeCtrl
{
private:
	char sentence[256];
	int index;
public:
	void AddCharacter(int input_key);
	void ResetCharacter();
	void RemoveCharacter();
	char* Sentence();
	TypeCtrl();
	~TypeCtrl();
};

