#include "hash_table.h"

HashTable::HashTable()
{
	tabsize = 10;
	data = new list<NodeTable>*[tabsize];
	for (int i = 0; i < tabsize; i++)
	{
		data[i] = new list < NodeTable >;
	}
}

void HashTable::Insert(string k, Polinom* p)
{
	int hash = hash_func(k);
	data[hash]->push_back(NodeTable(k, p));
}

void HashTable::Delete(string k)
{
	int hash = hash_func(k);
	Polinom* p = (*this).GetNode(k);
	data[hash]->remove(NodeTable(k, p));
}

Polinom* HashTable::GetNode(string k)
{
	int hash = hash_func(k);
	list<NodeTable>::const_iterator it;
	for (it = data[hash]->begin(); it != data[hash]->end(); ++it)
	{
		if (k == it->GetKey())
		{
			return it->GetPolinom();
		}
	}
	return NULL;
}

int HashTable::hash_func(string s)
{
	int hash = 0;
	for (int i = 0; i < s.size(); i++)
	{
		hash += s[i];
	}
	return hash%tabsize;
}