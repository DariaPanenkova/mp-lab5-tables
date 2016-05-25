#include "tree.h"

Tree_El::Tree_El(NodeTable* d)
{
	data = d;
	parent = NULL;
	left = NULL;
	right = NULL;
}
Tree_El::Tree_El()
{
	parent = NULL;
	left = NULL;
	right = NULL;
}

Tree_El::Tree_El(const Tree_El &t)
{
	data = t.GetData();
	left = t.GetLeft();
	right = t.GetRight();
}

NodeTable* Tree_El::GetData() const
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

void Tree_El::SetData(NodeTable* d)
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
void Tree_El::SetParent(Tree_El* r)
{
	parent = r;
}
Tree_El* Tree_El::GetParent() const
{
	return parent;
}
Tree_El& Tree_El:: operator=(const Tree_El &n)
{
	if(this!=&n)
	{
		data = n.GetData();
		parent = n.GetParent();
		left = n.GetLeft();
		right = n.GetRight();
	}
	return *this;

}

Tree::Tree()
{	
	root = NULL;
}

Tree_El* Tree:: Find(Tree_El* r, string k )                     
{
	Tree_El* tmp=r;
	if( root->GetData() == NULL)
	{
		return NULL; 
	}
	if(tmp != NULL)
	{
		while((tmp->GetData())->GetKey() != k)
		{
			if((tmp->GetData())->GetKey() > k)
			{
				if(tmp->GetLeft() != NULL)
					tmp = tmp->GetLeft();
				else
				{
					tmp = NULL;
					break;
				}
			}
			else 
			{
				if(tmp->GetRight() != NULL)
					tmp = tmp->GetRight();
				else
				{
					tmp = NULL;
					break;
				}
			}
		}
	}
	return tmp;
}

Tree_El* Tree::SearchMin(Tree_El* root) 
{
	Tree_El* tmp=root;
	while(tmp->GetLeft() != NULL)
	{
		tmp=tmp->GetLeft();
	}
	return tmp;
}
Tree_El* Tree::SearchMax(Tree_El* root)
{
	Tree_El*  tmp = root;
	while(tmp->GetRight()!=NULL)
	{
		tmp = tmp->GetRight();
	}
	return tmp;
}
Tree_El* Tree:: SearchNext(Tree_El* root)						
{
	Tree_El* tmp = NULL;
	if(root->GetRight() !=NULL)
		tmp = SearchMin(root->GetRight());
	return tmp;
}
Tree_El* Tree:: SearchPrev(Tree_El* root)						
{
	Tree_El* tmp = NULL;
	if(root->GetLeft() != NULL)
		tmp = SearchMax(root->GetLeft());
	else if(root->GetParent() != NULL)
		tmp = root->GetParent();
	return tmp;
}

void Tree:: Insert (Tree_El* n)                     
{
	if(root == NULL)
	{
		root = n;
		root->SetParent(root);
	}
	else 
		if( Find(root,(n->GetData())->GetKey()) != NULL)
		{
			throw "The keys are equal. Paste imposible";
		}
		else
		{
			Tree_El* prev=root;
			Tree_El* tmp=root;
			while(tmp!=NULL)
			{
				prev=tmp;
				if(tmp->GetData()->GetKey() < n->GetData()->GetKey())
					tmp=tmp->GetRight();
				else
					tmp=tmp->GetLeft();
			}
			if(prev->GetData()->GetKey() > n->GetData()->GetKey())
			{
				prev->SetLeft(n);
				(prev->GetLeft())->SetParent(prev);
			}
			else
			{
				prev->SetRight(n);
				(prev->GetRight())->SetParent(prev);
			}
		}
}

void Tree::Delete (string key)                 
{
	if(root == NULL)
	{
		throw "This tree is empty";
	}
	else 
	{
		Tree_El* tmp;
		tmp = Find(root,key);
		if (tmp == NULL)
		{
			throw "This element is not found.";
		}
		else
		{
			Delete(tmp);
		}
	}
}

void Tree::Delete (Tree_El*& tmp)
{
	if(tmp->GetLeft() && tmp->GetRight())
	{
		Tree_El* loc_max = SearchMin( tmp->GetRight());
		tmp->SetData(loc_max->GetData());
		Delete(loc_max);
	}
	else
	{
		if (tmp->GetLeft())
		{
			if (tmp == root)
			{
				root = tmp->GetLeft();
				root->SetParent(root);
			}
			
			
			if(tmp == (tmp->GetParent())->GetLeft())
			{
				(tmp->GetParent())->SetLeft(tmp->GetLeft());
			}
			else 
			{
				(tmp->GetParent())->SetRight(tmp->GetLeft());
			}
		}
		else
			if (tmp->GetRight())
			{
				if (tmp == root)
				{
					root = tmp->GetRight();
					root->SetParent(root);
				}

				if(tmp == (tmp->GetParent())->GetRight())
				{
					(tmp->GetParent())->SetRight(tmp->GetRight());
				}
				else 
				{
					(tmp->GetParent())->SetLeft(tmp->GetRight());
				}
			}
			else
			{
				if (tmp == (tmp->GetParent())->GetLeft())
				{
					tmp->GetParent()->SetLeft(NULL);
				}
				else 
				{
					tmp->GetParent()->SetRight(NULL);
				}
			}
			delete tmp;
	}
}