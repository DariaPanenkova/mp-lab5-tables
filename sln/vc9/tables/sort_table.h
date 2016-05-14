#pragma once
#include "polinom.h"
#include "list.h" 
#include "table.h"
#define SORT_TABLE

class SortTable: public Table
{
private:
	int currpos;
	int tabsize;
	NodeTable* data;

	bool IsFull();
	void AllocateMem();
	void AddSort(string k, Polinom *p);
	
public:

	SortTable();
	int GetPos();
	int Find(string k);
	void Insert(string k, Polinom* p);
	void Delete(string k);
	Polinom* GetNode(string k);
};
