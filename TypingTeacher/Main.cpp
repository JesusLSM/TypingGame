#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <string>
#include <string.h>
#include "MapCtrl.h"
#include "TypeCtrl.h"
#include "WordCtrl.h"
using namespace std;

#define MAPSIZE 40
#define ENTERKEY 13
#define BACKSPACE 8
#define GAP 3

string Select_Word(vector<string> &vt_ptr, int numberOfwords);

int main() {
	TypeCtrl *tCtrl = new TypeCtrl();	
	WordCtrl wCtrl;
	MapCtrl mCtrl;
	int input_key;	
	vector<string> words;
	string selectedWord;
	int numberOfwords;
	int Correct;
	int Score;
	int gap;
	int findIndex;

	gap = GAP;
	Score = 0;
	Correct = false;

	// Ÿ�� �õ�
	srand(time(NULL));

	// �ܾ� �а� ���� ����
	wCtrl.Read_File();
	words = wCtrl.Get_Words();
	numberOfwords = wCtrl.Get_numberOfwords();

	// �ܾ� ���� ����
	selectedWord = Select_Word(words, numberOfwords);
	//printf("%s\n", selectedWord.c_str());
	
	// �⺻ �� �����
	mCtrl.CreateMap(MAPSIZE);
	mCtrl.SetWord(selectedWord);
	
	
	// Ű���� �б�

	while (1) 
	{
		if (_kbhit()) {
			input_key = _getch();
			// ���� ���� �� ����� �ܾ� ã��
			if (input_key == ENTERKEY)
			{
				findIndex = mCtrl.FindWord(tCtrl->Sentence());
				if (findIndex)
				{					
					// �ܾ ã���� ���� ���� ����, ���ھ�+1
					tCtrl->ResetCharacter();
					Score++;
				
				}
				else
				{
					tCtrl->ResetCharacter();
				}

			}
			// Backsace ���� �� ���� �ϳ� ����
			else if (input_key == BACKSPACE)
			{
				tCtrl->RemoveCharacter();				
			}
			// �ϳ��� �߰�
			else
			{
				tCtrl->AddCharacter(input_key);
			}
			
			
		}
		system("cls");
		
		mCtrl.PushLine(); // ���� ���پ� �б�

		// gap���� �ܾ� �߰�
		if (gap <= 0)
		{
			selectedWord = Select_Word(words, numberOfwords);
			mCtrl.SetWord(selectedWord);
			gap = GAP;
		}
		else
		{
			mCtrl.ClearFirstLine();
		}
		// �� ����Ʈ
		mCtrl.PrintMap();

		// ���� ������ �ܾ�, ���ھ� ����Ʈ	
		printf("%s\n SCORE : %d", tCtrl->Sentence(), Score);
		
		
		

		gap--;
		Sleep(1000/10);
	} // while(1)

	
}

string Select_Word(vector<string> &vt_ptr, int numberOfwords)
{
	int rand_index;

	rand_index = rand() % numberOfwords;

	return vt_ptr[rand_index];			
}