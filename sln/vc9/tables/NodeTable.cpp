#include "table.h"

NodeTable :: NodeTable()
{
	key = "";
	pol = new Polinom;
}

NodeTable :: NodeTable( NodeTable &n)
{
	key = n.GetKey();
	pol = new Polinom(*n.GetPolinom());
}

NodeTable :: NodeTable( string k, Polinom *p)
{
	key = k;
	pol = p;
}

string NodeTable :: GetKey() const
{
	return key;
}

Polinom* NodeTable ::GetPolinom() const
{
	return pol;
}

NodeTable&  NodeTable :: operator=(const NodeTable &n)
{
	if (this == &n) 
	{
		return *this;
	}
	key = n.GetKey();
	pol = n.GetPolinom();
	return *this;
}
bool  NodeTable :: operator==(const NodeTable &n)
{
	if( GetKey() == n.GetKey())
		return true; 
}
