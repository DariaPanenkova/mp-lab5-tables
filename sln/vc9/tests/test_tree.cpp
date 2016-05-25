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
	t.Insert(new Tree_El(B));
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
	t.Insert(new Tree_El(B));
	t.Insert(new Tree_El(B1));
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
	t.Insert(new Tree_El(B));
	t.Insert(new Tree_El(B1));
	t.Delete("2");
	EXPECT_EQ(t.root->GetRight(), (Tree_El*)NULL); 
}

TEST(TREE, can_delete_with_one_son)
{
	Tree t;
	Polinom p,p1,p2,p3,p4,p5,p6;
	p.AddMonom(Monom(1, 100));
	p1.AddMonom(Monom(2, 101));
	p2.AddMonom(Monom(3, 102));
	p3.AddMonom(Monom(4, 103));
	p4.AddMonom(Monom(5, 104));
	p5.AddMonom(Monom(6, 105));
	p6.AddMonom(Monom(7, 106));

	NodeTable* B = new NodeTable("4",&p);
	NodeTable* B1 = new NodeTable("6",&p1);
	NodeTable* B2 = new NodeTable("2",&p2);
	NodeTable* B3 = new NodeTable("3",&p3);
	NodeTable* B4 = new NodeTable("1",&p4);
	NodeTable* B5 = new NodeTable("7",&p5);
	
	t.Insert(new Tree_El(B));
	t.Insert(new Tree_El(B1));
	t.Insert(new Tree_El(B2));
	t.Insert(new Tree_El(B3));
	t.Insert(new Tree_El(B4));
	t.Insert(new Tree_El(B5));

    t.Delete("6");

	EXPECT_EQ( *( (((t.root)->GetRight())->GetData())->GetPolinom()), p5); 
}

TEST(TREE, can_delete_with_two_sons)
{
	Tree t;
	Polinom p,p1,p2,p3,p4,p5,p6;
	p.AddMonom(Monom(1, 100));
	p1.AddMonom(Monom(2, 101));
	p2.AddMonom(Monom(3, 102));
	p3.AddMonom(Monom(4, 103));
	p4.AddMonom(Monom(5, 104));
	p5.AddMonom(Monom(6, 105));
	p6.AddMonom(Monom(7, 106));

	NodeTable* B = new NodeTable("4",&p);
	NodeTable* B1 = new NodeTable("6",&p1);
	NodeTable* B2 = new NodeTable("2",&p2);
	NodeTable* B3 = new NodeTable("3",&p3);
	NodeTable* B4 = new NodeTable("1",&p4);
	NodeTable* B5 = new NodeTable("7",&p5);
	NodeTable* B6 = new NodeTable("5",&p6);
	
	t.Insert(new Tree_El(B));
	t.Insert(new Tree_El(B1));
	t.Insert(new Tree_El(B2));
	t.Insert(new Tree_El(B3));
	t.Insert(new Tree_El(B4));
	t.Insert(new Tree_El(B5));
	t.Insert(new Tree_El(B6));

	t.Delete("6");

	EXPECT_EQ( *((t.root)->GetData())->GetPolinom(), p); 
	EXPECT_EQ( *( (((t.root)->GetRight())->GetData())->GetPolinom()), p5); 
	EXPECT_EQ( *( (((t.root)->GetLeft())->GetData())->GetPolinom()), p2); 
	EXPECT_EQ( (t.root)->GetRight()->GetRight(), (Tree_El*)NULL); 
	EXPECT_EQ( *( ((((t.root)->GetRight())->GetLeft())->GetData())->GetPolinom()), p6);
}


TEST(TREE, can_delete_root_with_left)
{
	Tree t;
	Polinom p,p1;
	p.AddMonom(Monom(1, 100));
	p1.AddMonom(Monom(76, 107));
	NodeTable* B = new NodeTable("2",&p);
	NodeTable* B1 = new NodeTable("1",&p1);
	t.Insert(new Tree_El(B));
	t.Insert(new Tree_El(B1));
	t.Delete("2");
	EXPECT_EQ( *((t.root)->GetData())->GetPolinom(), p1); 
}

TEST(TREE, can_delete_root_with_right)
{
	Tree t;
	Polinom p,p1;
	p.AddMonom(Monom(1, 100));
	p1.AddMonom(Monom(76, 107));
	NodeTable* B = new NodeTable("1",&p);
	NodeTable* B1 = new NodeTable("2",&p1);
	t.Insert(new Tree_El(B));
	t.Insert(new Tree_El(B1));
	t.Delete("1");
	EXPECT_EQ( *((t.root)->GetData())->GetPolinom(), p1); 
}

TEST(TREE, can_delete_root_with_two_sons)
{
	Tree t;
	Polinom p,p1, p2;
	p.AddMonom(Monom(1, 100));
	p1.AddMonom(Monom(76, 107));
	p2.AddMonom(Monom(3, 108));

	NodeTable* B = new NodeTable("1",&p);
	NodeTable* B1 = new NodeTable("2",&p1);
	NodeTable* B2 = new NodeTable("3",&p2);

    t.Insert(new Tree_El(B1));
	t.Insert(new Tree_El(B));
	t.Insert(new Tree_El(B2));
	t.Delete("2");
	EXPECT_EQ( *((t.root)->GetData())->GetPolinom(), p2); 
}



TEST(TREE, can_insert)
{
	Tree t;
	Polinom p,p1,p2,p3,p4,p5,p6;
	p.AddMonom(Monom(1, 100));
	p1.AddMonom(Monom(2, 101));
	p2.AddMonom(Monom(3, 102));
	p3.AddMonom(Monom(4, 103));
	p4.AddMonom(Monom(5, 104));
	p5.AddMonom(Monom(6, 105));
	p6.AddMonom(Monom(7, 106));

	NodeTable* B = new NodeTable("4",&p);
	NodeTable* B1 = new NodeTable("6",&p1);
	NodeTable* B2 = new NodeTable("2",&p2);
	NodeTable* B3 = new NodeTable("3",&p3);
	NodeTable* B4 = new NodeTable("1",&p4);
	NodeTable* B5 = new NodeTable("7",&p5);
	NodeTable* B6 = new NodeTable("5",&p6);

	
	t.Insert(new Tree_El(B));
	t.Insert(new Tree_El(B1));
	t.Insert(new Tree_El(B2));
	t.Insert(new Tree_El(B3));
	t.Insert(new Tree_El(B4));
	t.Insert(new Tree_El(B5));
	t.Insert(new Tree_El(B6));
	EXPECT_EQ( *((t.root)->GetData())->GetPolinom(), p); 
	EXPECT_EQ( *( (((t.root)->GetRight())->GetData())->GetPolinom()), p1); 
	EXPECT_EQ( *( (((t.root)->GetLeft())->GetData())->GetPolinom()), p2); 
	EXPECT_EQ( *( ((((t.root)->GetRight())->GetRight())->GetData())->GetPolinom()), p5); 
	EXPECT_EQ( *( ((((t.root)->GetRight())->GetLeft())->GetData())->GetPolinom()), p6); 
	EXPECT_EQ( *( ((((t.root)->GetLeft())->GetRight())->GetData())->GetPolinom()), p3); 
	EXPECT_EQ( *( ((((t.root)->GetLeft())->GetLeft())->GetData())->GetPolinom()), p4); 
}

TEST(TREE, can_delete)
{
	Tree t;
	Polinom p,p1,p2,p3,p4,p5,p6;
	p.AddMonom(Monom(1, 100));
	p1.AddMonom(Monom(2, 101));
	p2.AddMonom(Monom(3, 102));
	p3.AddMonom(Monom(4, 103));
	p4.AddMonom(Monom(5, 104));
	p5.AddMonom(Monom(6, 105));
	p6.AddMonom(Monom(7, 106));

	NodeTable* B = new NodeTable("4",&p);
	NodeTable* B1 = new NodeTable("6",&p1);
	NodeTable* B2 = new NodeTable("2",&p2);
	NodeTable* B3 = new NodeTable("3",&p3);
	NodeTable* B4 = new NodeTable("1",&p4);
	NodeTable* B5 = new NodeTable("7",&p5);
	NodeTable* B6 = new NodeTable("5",&p6);

	
	t.Insert(new Tree_El(B));
	t.Insert(new Tree_El(B1));
	t.Insert(new Tree_El(B2));
	t.Insert(new Tree_El(B3));
	t.Insert(new Tree_El(B4));
	t.Insert(new Tree_El(B5));
	t.Insert(new Tree_El(B6));

	t.Delete("4");

	EXPECT_EQ( *((t.root)->GetData())->GetPolinom(), p6); 
	EXPECT_EQ( *( (((t.root)->GetRight())->GetData())->GetPolinom()), p1); 
	EXPECT_EQ( *( (((t.root)->GetLeft())->GetData())->GetPolinom()), p2); 
	EXPECT_EQ( *( ((((t.root)->GetRight())->GetRight())->GetData())->GetPolinom()), p5); 
	EXPECT_EQ( t.root->GetRight()->GetLeft(), (Tree_El*)NULL); 
	EXPECT_EQ( *( ((((t.root)->GetLeft())->GetRight())->GetData())->GetPolinom()), p3); 
	EXPECT_EQ( *( ((((t.root)->GetLeft())->GetLeft())->GetData())->GetPolinom()), p4); 
}

TEST(TREE, can_delete2)
{
	Tree t;
	Polinom p,p1,p2,p3,p4,p5,p6, p7;
	p.AddMonom(Monom(1, 100));
	p1.AddMonom(Monom(2, 101));
	p2.AddMonom(Monom(3, 102));
	p3.AddMonom(Monom(4, 103));
	p4.AddMonom(Monom(5, 104));
	p5.AddMonom(Monom(6, 105));
	p6.AddMonom(Monom(7, 106));
    p7.AddMonom(Monom(7, 106));


	NodeTable* B = new NodeTable("40",&p);
	NodeTable* B1 = new NodeTable("60",&p1);
	NodeTable* B2 = new NodeTable("20",&p2);
	NodeTable* B3 = new NodeTable("30",&p3);
	NodeTable* B4 = new NodeTable("10",&p4);
	NodeTable* B5 = new NodeTable("70",&p5);
	NodeTable* B6 = new NodeTable("50",&p6);
    NodeTable* B7 = new NodeTable("55",&p7);
	
	t.Insert(new Tree_El(B));
	t.Insert(new Tree_El(B1));
	t.Insert(new Tree_El(B2));
	t.Insert(new Tree_El(B3));
	t.Insert(new Tree_El(B4));
	t.Insert(new Tree_El(B5));
	t.Insert(new Tree_El(B6));
	t.Insert(new Tree_El(B7));

	t.Delete("40");

	EXPECT_EQ( *((t.root)->GetData())->GetPolinom(), p6); 
	EXPECT_EQ( *( (((t.root)->GetRight())->GetData())->GetPolinom()), p1); 
	EXPECT_EQ( *( (((t.root)->GetLeft())->GetData())->GetPolinom()), p2); 
	EXPECT_EQ( *( ((((t.root)->GetRight())->GetRight())->GetData())->GetPolinom()), p5); 
	EXPECT_EQ( t.root->GetRight()->GetLeft()->GetData()->GetKey(), "55"); 
	EXPECT_EQ( *( ((((t.root)->GetLeft())->GetRight())->GetData())->GetPolinom()), p3); 
	EXPECT_EQ( *( ((((t.root)->GetLeft())->GetLeft())->GetData())->GetPolinom()), p4); 
}

