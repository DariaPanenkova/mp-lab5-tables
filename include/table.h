#pragma once
#include "polinom.h"
#include "list.h" 
#include <string>
using namespace std;
class NodeTable
{
private:
	string key;
	Polinom *pol;

public:
	NodeTable();
	NodeTable(const NodeTable &n);
	NodeTable(string k, Polinom *p);


	string GetKey() const;
	Polinom* GetPolinom() const;
	NodeTable& operator=(const NodeTable &n);
	bool operator==(const NodeTable &n);
};

class Table
{
public:

	virtual int Find(string k) = 0;
	virtual void Insert(string k, Polinom* p) = 0;
	virtual void Delete(string k) = 0;
	virtual Polinom* GetNode(string k) = 0 ;
};