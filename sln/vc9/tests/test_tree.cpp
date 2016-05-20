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
	t.Insert("a",&p);
	EXPECT_EQ( *((t.root)->GetData()).GetPolinom(), p); 
}
