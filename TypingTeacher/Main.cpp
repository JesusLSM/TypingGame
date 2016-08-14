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

	// 타임 시드
	srand(time(NULL));

	// 단어 읽고 정보 저장
	wCtrl.Read_File();
	words = wCtrl.Get_Words();
	numberOfwords = wCtrl.Get_numberOfwords();

	// 단어 랜덤 선택
	selectedWord = Select_Word(words, numberOfwords);
	//printf("%s\n", selectedWord.c_str());
	
	// 기본 맵 만들기
	mCtrl.CreateMap(MAPSIZE);
	mCtrl.SetWord(selectedWord);
	
	
	// 키보드 읽기

	while (1) 
	{
		if (_kbhit()) {
			input_key = _getch();
			// 엔터 누를 시 저장된 단어 찾기
			if (input_key == ENTERKEY)
			{
				findIndex = mCtrl.FindWord(tCtrl->Sentence());
				if (findIndex)
				{					
					// 단어를 찾으면 현재 버퍼 리셋, 스코어+1
					tCtrl->ResetCharacter();
					Score++;
				
				}
				else
				{
					tCtrl->ResetCharacter();
				}

			}
			// Backsace 누를 시 버퍼 하나 지움
			else if (input_key == BACKSPACE)
			{
				tCtrl->RemoveCharacter();				
			}
			// 하나씩 추가
			else
			{
				tCtrl->AddCharacter(input_key);
			}
			
			
		}
		system("cls");
		
		mCtrl.PushLine(); // 라인 한줄씩 밀기

		// gap마다 단어 추가
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
		// 맵 프린트
		mCtrl.PrintMap();

		// 현재 버퍼의 단어, 스코어 프린트	
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