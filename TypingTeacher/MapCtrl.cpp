#include "MapCtrl.h"



MapCtrl::MapCtrl()
{
	srand(time(NULL));			
}

void MapCtrl::CreateMap(int size)
{
	m_size = size;
	Map = new char*[size];	

	
	for (int i = 0; i < size; i++)
	{
		Map[i] = new char[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			Map[i][j] = ' ';
			if (i == 0 || j == 0 || i == size - 1 || j == size - 1)
			{
				Map[i][j] = '*';
			}
			
		}
	}
}

void MapCtrl::PrintMap()
{
	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			printf("%c", Map[i][j]);

		}
		printf("\n");
	}
}

void MapCtrl::SetWord(string word)
{
	m_word = word;
	m_wordStartindex_y = rand() % (m_size - 10) + 1;
	int word_size = m_word.length();	
	index_word[1] = m_word;
	
	for (int i = m_wordStartindex_y; i < m_wordStartindex_y + word_size; i++)
	{
		Map[1][i] = (char)m_word[i - m_wordStartindex_y];
	}
}
void MapCtrl::ClearFirstLine()
{
	index_word[1] = "";	
}
void MapCtrl::PushLine()
{
	for (int i = m_size - 2; i >= 2; i--)
	{
		index_word[i] = index_word[i - 1];
		for (int j = 1; j < m_size - 2; j++)
		{
			Map[i][j] = ' ';
			Map[i][j] = Map[i - 1][j];
			Map[i - 1][j] = ' ';
		}
	}
}

int MapCtrl::FindWord(char *word)
{
	for (int i = 1; i < m_size - 2; i++)
	{
		if ( strcmp(index_word[i].c_str(), word) == 0)
		{
			
			index_word[i] == "";

			for (int j = 1; j < m_size - 2; j++)
			{
				Map[i][j] = ' ';
			}
			return i;
		}
	}
	return false;
}
MapCtrl::~MapCtrl()
{
}
