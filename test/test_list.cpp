#include <gtest.h>
#include "list.h"

TEST(LIST,can_not_get_elem_empty_list)
{
	List<int> l;

	ASSERT_ANY_THROW(l.GetElm(4));
}

TEST(LIST,can_not_get_elem_negative_pos)
{
	List<int> l;

	ASSERT_ANY_THROW(l.GetElm(-1));
}
TEST(LIST, can_add_elem_to_head_when_list_empty)
{
	List<int> l;
	l.AddToHead(2);

	EXPECT_EQ(2,l.GetElm(0)->GetData());
}
TEST(LIST, can_add_elem_to_head)
{
	List<int> l;
	l.AddToHead(2);
	l.AddToHead(3);

	EXPECT_EQ(3,l.GetElm(0)->GetData());	
}
TEST(LIST, can_add_to_tail_when_list_empty)
{
	List<int> l;
	l.AddToTail(2);

	EXPECT_EQ(2,l.GetElm(0)->GetData());

}
TEST(LIST, can_add_elem_to_tail)
{
	List<int> l;
	l.AddToTail(2);
	l.AddToTail(3);

	EXPECT_EQ(3,l.GetElm(1)->GetData());	
}
TEST(LIST, can_add_elem)
{
	List<int> l;
	l.AddToHead(2);
	l.AddToHead(3);
	l.AddSortElem(1);
	EXPECT_EQ(1,l.GetElm(2)->GetData());
}
TEST(LIST, can_delete_elem)
{
	List<int> l;
	l.AddToHead(2);
	l.AddToHead(3);
	l.AddToHead(4);


	
	l.DeleteElem(l.GetElm(1));
	EXPECT_EQ(2,l.GetElm(1)->GetData());

}