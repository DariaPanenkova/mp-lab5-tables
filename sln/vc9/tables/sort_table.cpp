#include "sort_table.h"

SortTable::SortTable()
{
	currpos = 0;
	tabsize = 2;
	data = new NodeTable[tabsize];
}

bool SortTable::IsFull() {
	if (currpos == tabsize) {
		return true;
	}
	return false;
}

int SortTable::GetPos()
{
	return currpos;
}

void SortTable::AllocateMem() 
{
	
	NodeTable* tmp = new NodeTable[tabsize*2];
	for (int i = 0; i < tabsize; i++)
	{
		tmp[i] = data[i];
	}
	delete[] data;
	tabsize = 2 * tabsize;
	data = tmp;
}

int SortTable::Find(string k)
{
	if (currpos == 0)
		return -1;

	int left = -1;

	int right = currpos;

	int m;
	while( left < right - 1)
	{
		m = (left + right) / 2;
		if ( data[m].GetKey() < k)
			left = m;
		else 
			right = m;
	}
	 
	return right;
}

void SortTable:: AddSort(string k, Polinom *p)
{
	if (currpos == 0)
	{
		data[0] = NodeTable(k, p);
		currpos++;
		return;
	}

	if (k < data[0].GetKey())
	{
		for (int i = currpos; i > 0; i--) 
		{
			data[i] = data[i - 1];
		}
		data[0] = NodeTable(k, p);
		currpos++;
		return;
	}

	if (k > data[currpos-1].GetKey())
	{
		data[currpos] = NodeTable(k, p);
		currpos++;
		return;
	}

	int ind = Find(k);

	for (int i = currpos; i > ind; i--)
	{
		data[i] = data[i - 1];
	}
	data[ind] = NodeTable(k, p);
	currpos++;
}


void SortTable::Insert(string k, Polinom* p)
{

	if (currpos == tabsize)
	{
		AllocateMem();
	}
	 AddSort(k, p);
}

void SortTable::Delete(string key)
{
	int ind = Find(key);
	for (int i = ind; i < currpos-1; i++)
	{
		data[i] = data[i + 1];
	}
	data[currpos - 1] = NodeTable("",NULL);
	currpos--;
}

Polinom* SortTable::GetNode(string key)
{
	int i = Find(key);
	if (i == -1)
	{
		return NULL;
	}
	return data[i].GetPolinom();
}