#include "tree.h"
#include <gtest.h>

TEST(TREE, can_creat_tree)
{
	ASSERT_NO_THROW (Tree t);
}

TEST(TREE, can_insert_first_elem)
{
	Tree t;
	Polinom p;
	p.AddMonom(Monom(1, 100));
	NodeTable* B = new NodeTable("a",&p);
	t.Insert(Tree_El(B));
	EXPECT_EQ( *((t.root)->GetData())->GetPolinom(), p); 
}
TEST(TREE, can_insert_elem)
{
	Tree t;
	Polinom p,p1;
	p.AddMonom(Monom(1, 100));
	p1.AddMonom(Monom(76, 107));
	NodeTable* B = new NodeTable("1",&p);
	NodeTable* B1 = new NodeTable("2",&p1);
	t.Insert(Tree_El(B));
	t.Insert(Tree_El(B1));
	EXPECT_EQ( *((t.root)->GetData())->GetPolinom(), p); 
	EXPECT_EQ( *( (((t.root)->GetRight())->GetData())->GetPolinom()), p1); 
}

TEST(TREE, can_delete_elem)
{
	Tree t;
	Polinom p,p1;
	p.AddMonom(Monom(1, 100));
	p1.AddMonom(Monom(76, 107));
	NodeTable* B = new NodeTable("1",&p);
	NodeTable* B1 = new NodeTable("2",&p1);
	t.Insert(Tree_El(B));
	t.Insert(Tree_El(B1));
	t.Delete(&Tree_El(B));
	EXPECT_EQ( *((t.root)->GetData())->GetPolinom(), p1); 
}