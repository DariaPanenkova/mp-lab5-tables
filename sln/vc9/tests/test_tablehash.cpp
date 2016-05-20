#include "table.h"
#include "hash_table.h"
#include <gtest.h>
#include "polinom.h"

TEST(TableHash, can_create_table_hash) 
{
	ASSERT_NO_THROW (HashTable t);
}

TEST(TableHash, can_Insert) 
{
	HashTable t;
	Polinom p;
	p.AddMonom(Monom(1, 100));
	t.Insert("a", &p);
	EXPECT_EQ(1, t.GetNode("a")->operator[](0).GetCoef());
}
TEST(TableHash, can_delete) 
{
	HashTable t;
	Polinom p;
	p.AddMonom(Monom(1, 100));
	t.Insert("a", &p);
	t.Delete("a");
	EXPECT_EQ(NULL, t.GetNode("a"));
}

TEST(TableHash, can_not_find)
{
	HashTable t;
	EXPECT_EQ(NULL, t.GetNode("a"));
}
TEST(TableHash, can_find_hashfunc_a)
{
	HashTable t;
	string a = "a";
	int hash = t.hash_func(a); 
	EXPECT_EQ(7, hash);
}
