#pragma once

#include "table.h"

class Tree_El
{
private:
	NodeTable* data;
	Tree_El* left;
	Tree_El* right;
	Tree_El* parent;
public:
	Tree_El();
	Tree_El(NodeTable* d);
	Tree_El(const Tree_El &t);


	NodeTable* GetData() const;
	Tree_El* GetLeft() const;
	Tree_El* GetRight() const;
	Tree_El* GetParent() const;

	void SetData(NodeTable* d);
	void SetLeft(Tree_El* l);
	void SetRight(Tree_El* r);
	void SetParent(Tree_El* r);

	Tree_El& operator=(const Tree_El &n);

};

class Tree
{
public:
	Tree_El* root;
	Tree(); 

	Tree_El* Find(Tree_El* n, string k);
	NodeTable* Find(string k);
	Tree_El* SearchMin(Tree_El* r);
	Tree_El* SearchMax(Tree_El* r);
	Tree_El* SearchNext(Tree_El* r);
	Tree_El* SearchPrev(Tree_El* r);
	void Insert(Tree_El &n);
	void Delete (string k);
	void Delete (Tree_El * tmp);

};