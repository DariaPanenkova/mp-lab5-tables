#include <gtest.h>
#include "polinom.h"
#include "monom.h"
// тесты мономов и полиномов
TEST(MONOM, can_compare_monoms_with_dif_deg)
{
	Monom m1(2,110);
	Monom m2(4,111);

	EXPECT_FALSE(m1==m2);
	EXPECT_TRUE(m1!=m2);
}

TEST(MONOM, can_compare_monoms_with_dif_coef)
{
	Monom m1(2,110);
	Monom m2(4,110);

	EXPECT_FALSE(m1==m2);
	EXPECT_TRUE(m1!=m2);
}

TEST(MONOM, can_compare_equal_monoms)
{
	Monom m1(2,110);
	Monom m2(2,110);

	EXPECT_TRUE(m1==m2);
}
TEST(MONOM, can_add_monoms)
{
	Monom m1(2,110);
	Monom m2(4,110);

	Monom exp(6,110);

	EXPECT_EQ(exp, m1+m2);
}
TEST(MONOM, can_not_add_monoms_with_diff_deg)
{
	Monom m1(2,110);
	Monom m2(4,111);

	ASSERT_ANY_THROW(m1+m2);
}
TEST(MONOM, compare_large_deg)
{
	Monom m1(2,1);
	Monom m2(2,5);

	EXPECT_TRUE(m2>m1);
	EXPECT_FALSE(m2<m1);
}
TEST(MONOM, compare_large_coef)
{
	Monom m1(8,3);
	Monom m2(10,3);

	EXPECT_TRUE(m2>m1);
	EXPECT_FALSE(m2<m1);
}
TEST(MONOM, can_sub_monoms)
{
	Monom m1(2,110);
	Monom m2(4,110);

	Monom exp(-2,110);

	EXPECT_EQ(exp, m1-m2);
}
TEST(MONOM, can_not_sub_monoms_with_diff_deg)
{
	Monom m1(2,110);
	Monom m2(4,111);

	ASSERT_ANY_THROW(m1-m2);
}

TEST(MONOM, can_multiply_monoms)
{
	Monom m1(10,1);
	Monom m2(4,3);

	EXPECT_EQ(4,(m1*m2).GetDeg());
	EXPECT_EQ(40,(m1*m2).GetCoef());

}

TEST(POLINOM, can_create_polinom)
{
	ASSERT_NO_THROW(Polinom p);
}
TEST(POLINOM, can_add_sort_monom)
{
	Polinom p1;

	p1.AddMonom(Monom(-1,196));
	p1.AddMonom(Monom(3,489));
	
	EXPECT_EQ(3,p1[0].GetCoef());
	EXPECT_EQ(-1,p1[1].GetCoef());

}
TEST(POLINOM, can_add_polinoms)
{
	Polinom p1;

	p1.AddMonom(Monom(1,1));
	p1.AddMonom(Monom(3,4));

	Polinom p2;

	p2.AddMonom(Monom(4,1));
	p2.AddMonom(Monom(2,3));

	Polinom r;

	r=p1+p2;


	EXPECT_EQ(3,r[0].GetCoef());
	EXPECT_EQ(2,r[1].GetCoef());
	EXPECT_EQ(5,r[2].GetCoef());

}
TEST(POLINOM, can_add_polinoms_1)
{
	Polinom p1;

	p1.AddMonom(Monom(1,1));
	

	Polinom p2;

	p2.AddMonom(Monom(4,6));
	
	Polinom r;

	r=p1+p2;

	EXPECT_EQ(2,r.polinom->GetSize());
	EXPECT_EQ(4,r[0].GetCoef());
	EXPECT_EQ(1,r[1].GetCoef());
	

}
TEST(POLINOM, can_add_polinoms_with_null_coef)
{
	Polinom p1;

	p1.AddMonom(Monom(1,1));
	p1.AddMonom(Monom(3,4));

	Polinom p2;

	p2.AddMonom(Monom(-1,1));
	p2.AddMonom(Monom(2,3));

	Polinom r;

	r=p1+p2;

	EXPECT_EQ(2,r.polinom->GetSize());
	EXPECT_EQ(3,r[0].GetCoef());
	EXPECT_EQ(2,r[1].GetCoef());

}
TEST(POLINOM, can_multiply_const_polinom)
{
	Polinom p1;
	Polinom r;

	p1.AddMonom(Monom(1,1));
	p1.AddMonom(Monom(9,10));

	Monom b(-1,0);

	r = p1 * b;
	EXPECT_EQ(-9,r[0].GetCoef());
	EXPECT_EQ(-1,r[1].GetCoef());

}


TEST(POLINOM, can_sub_polinoms)
{
	Polinom p1;

	p1.AddMonom(Monom(1,1));
	p1.AddMonom(Monom(3,4));

	Polinom p2;

	p2.AddMonom(Monom(4,1));
	p2.AddMonom(Monom(2,3));

	Polinom r;

	r=p1-p2;

	EXPECT_EQ(3, r.polinom->GetSize());
	EXPECT_EQ(3,r[0].GetCoef());
	EXPECT_EQ(-2,r[1].GetCoef());
	EXPECT_EQ(-3,r[2].GetCoef());

}

TEST(POLINOM, can_sub_polinoms_1)
{
	Polinom p1;

	p1.AddMonom(Monom(1,1));

	Polinom p2;

	p2.AddMonom(Monom(4,4));

	Polinom r;

	r=p1-p2;

	EXPECT_EQ(2, r.polinom->GetSize());
	EXPECT_EQ(-4,r[0].GetCoef());
	EXPECT_EQ(1,r[1].GetCoef());
	


}
TEST(POLINOM, can_reconstr_polinom)
{
	Polinom p1;

	p1.AddMonom(Monom(1,1));
	p1.AddMonom(Monom(3,4));
	p1.AddMonom(Monom(10,4));
	p1.AddMonom(Monom(4,654));
	p1.AddMonom(Monom(25,654));

	
	p1.Reconstr();

	EXPECT_EQ(29,p1[0].GetCoef());
	EXPECT_EQ(13,p1[1].GetCoef());
	EXPECT_EQ(1,p1[2].GetCoef());

}
TEST(POLINOM, can_reconstr_polinom_delliting)
{
	Polinom p1;

	p1.AddMonom(Monom(-8,8));
	p1.AddMonom(Monom(3,5));
	p1.AddMonom(Monom(-3,5));
	p1.AddMonom(Monom(1,1));

	
	p1.Reconstr();

	EXPECT_EQ(2, p1.polinom->GetSize());

}
TEST(POLINOM, can_multip_polinoms)
{
	Polinom p1;

	p1.AddMonom(Monom(1,1));
	p1.AddMonom(Monom(3,4));

	Polinom p2;

	p2.AddMonom(Monom(4,1));
	p2.AddMonom(Monom(2,4));

	Polinom r;

	r=p1*p2;

	EXPECT_EQ(6,r[0].GetCoef());
	EXPECT_EQ(14,r[1].GetCoef());
	EXPECT_EQ(4,r[2].GetCoef());
}

TEST(POLINOM, can_multip_polinoms_with_zero_coeff_deliting)
{
	Polinom p1;

	p1.AddMonom(Monom(1,1));
	p1.AddMonom(Monom(3,4));

	Polinom p2;

	p2.AddMonom(Monom(1,1));
	p2.AddMonom(Monom(-3,4));

	Polinom r;

	r=p1*p2; // (1, 2) (-9, 8) 

	EXPECT_EQ(-9,r[0].GetCoef());
	EXPECT_EQ(8,r[0].GetDeg());
	EXPECT_EQ(1,r[1].GetCoef());
	EXPECT_EQ(2,r[1].GetDeg());
}

TEST(POLINOM, sub_polinom)
{
	Polinom p1;

	p1.AddMonom(Monom(14,123));

	Polinom p2;

	p2.AddMonom(Monom(175,158));

	Polinom r;

	r=p1-p2;

	EXPECT_EQ(-175,r[0].GetCoef());
	EXPECT_EQ(158,r[0].GetDeg());
	EXPECT_EQ(14,r[1].GetCoef());
	EXPECT_EQ(123,r[1].GetDeg());


}