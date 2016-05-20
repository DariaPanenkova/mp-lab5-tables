#pragma once

#include "table.h"

class Tree_El
{
private:
	NodeTable data;
	Tree_El* left;
	Tree_El* right;
public:
	Tree_El();
	Tree_El(NodeTable d);
	Tree_El(const Tree_El &t);

	NodeTable GetData() const;
	Tree_El* GetLeft() const;
	Tree_El* GetRight() const;
	void SetData(NodeTable d);
	void SetLeft(Tree_El* l);
	void SetRight(Tree_El* r);
};

class Tree
{
public:
	Tree_El* root;
	Tree(); 
	
	void Insert(string k, Polinom *p);

};