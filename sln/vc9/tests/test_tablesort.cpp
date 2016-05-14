#include "table.h"
#include "sort_table.h"
#include <gtest.h>
#include "polinom.h"
TEST(TableSort, can_create_table_sort) 
{
	ASSERT_NO_THROW(SortTable t);
}

TEST(TableSort, can_insert_polinom) 
{
	SortTable t;
	Polinom p;
	p.AddMonom(Monom(3, 125));
	t.Insert("a", &p);
	EXPECT_EQ(3, t.GetNode("a")->operator[](0).GetCoef());
}
TEST(TableSort, can_insert_two_polinom) {
	SortTable t;
	Polinom p,d;
	p.AddMonom(Monom(2, 125));
	d.AddMonom(Monom(6, 423));
	d.AddMonom(Monom(34, 700));
	t.Insert("a", &p);
	t.Insert("b", &d);
	EXPECT_EQ(2, t.GetNode("a")->operator[](0).GetCoef());
	EXPECT_EQ(34, t.GetNode("b")->operator[](0).GetCoef());
	EXPECT_EQ(6, t.GetNode("b")->operator[](1).GetCoef());

}

TEST(TableSort, can_delete) 
{
	SortTable t;
	Polinom p, d, g;
	p.AddMonom(Monom(1, 100));
	d.AddMonom(Monom(2, 200));
	g.AddMonom(Monom(3, 300));
	t.Insert("aaa", &g);
	t.Insert("a", &p);
	t.Insert("aa", &d);
	t.Delete("aa");

	EXPECT_EQ(1, t.GetNode("a")->operator[](0).GetCoef());
	EXPECT_EQ(3, t.GetNode("aaa")->operator[](0).GetCoef());
}

TEST(TableSort, can_get_pos) 
{
	SortTable t;
	Polinom p, d, g;
	p.AddMonom(Monom(1, 100));
	string s= "a";
	for (int i = 0; i < 5; i++)
	{
		t.Insert(s, &p);
		s += "a";
	}
	EXPECT_EQ(5, t.GetPos());
}

TEST(TableSort, can_insert_sort)
{
	SortTable t;
	Polinom p, d;
	p.AddMonom(Monom(1, 100));
	d.AddMonom(Monom(3, 300));
	t.Insert("b", &p);
	t.Insert("a",&d);
	EXPECT_EQ(3, t.GetNode("a")->operator[](0).GetCoef());
	EXPECT_EQ(1, t.GetNode("b")->operator[](0).GetCoef());
}

TEST(TableSort, can_insert_orderly_2) 
{
	SortTable t;
	Polinom p, d, r;
	p.AddMonom(Monom(1, 100));
	d.AddMonom(Monom(2, 300));
	r.AddMonom(Monom(3, 400));
	t.Insert("ab", &r);
	t.Insert("a", &p);
	t.Insert("b", &d);
	EXPECT_EQ(1, t.GetNode("a")->operator[](0).GetCoef());

	EXPECT_EQ(2, t.GetNode("b")->operator[](0).GetCoef()); 
	EXPECT_EQ(3, t.GetNode("ab")->operator[](0).GetCoef());
	EXPECT_EQ(3, t.GetPos());
}