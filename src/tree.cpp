#include "tree.h"

Tree_El::Tree_El(NodeTable d)
{
	data = d;
	left=NULL;
	right=NULL;
}
Tree_El::Tree_El()
{
	left=NULL;
	right=NULL;
}

Tree_El::Tree_El(const Tree_El &t)
{
	data = t.GetData();
	left = t.GetLeft();
	right = t.GetRight();
}

NodeTable Tree_El::GetData() const
{
	return data;
}

Tree_El* Tree_El::GetLeft() const
{
	return left;
}

Tree_El* Tree_El::GetRight() const
{
	return right;
}

void Tree_El::SetData(NodeTable d)
{
	data = d;
}

void Tree_El::SetLeft(Tree_El* l)
{
	left = l;
}

void Tree_El::SetRight(Tree_El* r)
{
	right = r;
}


Tree::Tree()
{	
	root = NULL;
}

void Tree::Insert(string k, Polinom *p)
{
	if ( root == NULL)
	{	
		root = new Tree_El( NodeTable(k,p));
		return;
	}



	
}
