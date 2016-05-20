#pragma once
#include "polinom.h" 
#include "table.h"
#include <list>
class HashTable : public Table
{
private:
	list<NodeTable> **data;
	int tabsize;

	
	
public:
	HashTable();
	int hash_func(string s);
	int Find(string key) { return 0; };
	void Insert(string k, Polinom *p);
	void Delete(string k);
	Polinom* GetNode(string k);
};