#include "monom.h"

Monom::Monom(double c, int d)
{
	Coef=c;
	Deg=d;
}

Monom::	Monom(const Monom &mon)
{
	Coef=mon.Coef;
	Deg=mon.Deg;
}


int Monom::GetDeg()
{
	return Deg;
}

void Monom::SetDeg(int d)
{
	Deg = d;
}

double Monom::GetCoef()
{
	return Coef;
}

void Monom::SetCoef(double c)
{
	Coef = c;
}
Monom& Monom:: operator=(const Monom &mon)
{
	if(this == &mon)
		return *this;
	Coef=mon.Coef;
	Deg=mon.Deg;
	return *this;
} 

bool Monom::operator==(const Monom &mon) const
{
	if(this == &mon)
		return true;
	else
		if((Coef==mon.Coef)&&(Deg==mon.Deg))
			return true;
		else
			return false;
}

bool Monom::operator!=(const Monom &mon) const
{
	return !(*this==mon);
}

bool Monom::operator>(const Monom& mon)
{
	if (Deg == mon.Deg)
		if ( Coef > mon.Coef)
			return true;
	if( Deg > mon.Deg)
		return true;
	return false;
}

bool Monom::operator<(const Monom& mon)
{
	if (Deg == mon.Deg)
		if ( Coef < mon.Coef)
			return true;
	if( Deg < mon.Deg)
		return true;
	return false;
}

Monom Monom::operator+(const Monom& mon)
{
	if( Deg != mon.Deg )
		throw ("Разные степени");
	Monom res(Coef + mon.Coef,Deg);

	return res;
}

Monom Monom::operator-(const Monom& mon)
{
	if( Deg != mon.Deg )
		throw ("Рызные степени");
	Monom res(0,Deg);

	res.Coef= Coef - mon.Coef;
	return res;
}


Monom Monom::operator * (const Monom &mon)
{
	if( (Deg + mon.Deg) > 999 )
		throw ("Некоректные степени");
	Monom res;

	res.Coef= Coef * mon.Coef;
	res.Deg= Deg + mon.Deg;

	return res;
}