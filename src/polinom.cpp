#include "polinom.h"
#include <iostream>
Polinom::Polinom()
{
	polinom = new List<Monom>;
}

Polinom::Polinom(const Polinom &pol)
{
	polinom = new List<Monom>;
	Node<Monom>* curr = pol.polinom->GetHead();

	while( curr != NULL)
	{
		polinom->AddSortElem(curr->GetData());
		curr = curr->GetNext();
	}
}
void Polinom::AddMonom(Monom m)
{
	if (m.GetCoef() !=0)
	{
	polinom->AddSortElem(m);
	}
}

void Polinom::DeleteMonom(Node<Monom> *m)
{
	polinom->DeleteElem(m);
}

Monom& Polinom::operator[](int pos)
{
	if (pos < 0 || pos > polinom->GetSize() )
	{
		throw("Некорректная позиция");
	}
	Node<Monom>* current = polinom->GetHead();
	for (int i = 0; i < pos; i++)
	{
		current = current->GetNext();
	}
	return current->GetData();
	
}

Polinom Polinom::operator =(const Polinom& p)
{
	if (this == &p)
		return *this;

	delete polinom;

	polinom = new List < Monom >;

	Node<Monom> *curr = p.polinom->GetHead();

	while (curr != NULL) {
		polinom->AddSortElem(curr->GetData());
		curr = curr->GetNext();
	}
	return *this;

}
Polinom  operator+ (const Polinom& l,const Polinom& p)
{
	Polinom res;
	Node<Monom>* currl= l.polinom->GetHead();
	Node<Monom>* currp= p.polinom->GetHead();

	if ( l.polinom->GetSize() == 0)
		return res = p;
	if( p.polinom->GetSize() == 0)
		return res = l;

	while( currl != NULL && currp !=NULL )
		{
			if (currl->GetData().Deg == currp->GetData().Deg) 
			{
				Monom m = currl->GetData()+currp->GetData();
				if (abs(m.GetCoef()) > 1e-10)
					res.polinom->AddToTail(currl->GetData()+currp->GetData());
				//res.AddMonom(currl->GetData()+currp->GetData())	;
					currl = currl->GetNext();
					currp = currp->GetNext();
			}
			else

				if(currl->GetData() > currp->GetData())
				{
					res.polinom->AddToTail(currl->GetData());
					//res.AddMonom(currl->GetData());
					currl = currl->GetNext();
				}
				else
				{
					res.polinom->AddToTail(currp->GetData());
					//res.AddMonom(currp->GetData());
					currp = currp->GetNext();
				}
	}
	while (currl != NULL) {
		res.polinom->AddToTail(currl->GetData());
		//res.AddMonom(currl->GetData());
		currl = currl->GetNext();
	}

	while (currp != NULL) {
		res.polinom->AddToTail(currp->GetData());
		//res.AddMonom(currp->GetData());
		currp = currp->GetNext();
	}

	//res.Reconstr();

	return res;

}

Polinom operator*(const Polinom& l,const Monom& r)
{
	Polinom *res = new Polinom;
	Node<Monom>* curr = l.polinom->GetHead();
	while (curr != NULL)
	{
		res->AddMonom(curr->GetData()*r);
		curr = curr->GetNext();
	}
	return *res;
}
Polinom  operator- (const Polinom& l,const Polinom& p)
{
	Polinom res;
	Polinom p1(p);
	Monom a(-1,0);
	if ( l.polinom->GetSize() == 0)
		return res = p1 * a;
	if( p.polinom->GetSize() == 0)
		return res = l;
	Polinom res1(p1 * a);
	res = l + res1;
	res.Reconstr();
	return res;
	
}
void Polinom::Reconstr()
{
	
	/*if (polinom->GetHead()->GetNext() == NULL)
	{
		return;
	}*/
	Node<Monom>* curr = polinom->GetHead()->GetNext();
	Node<Monom>* prev = polinom->GetHead();

	while (curr != NULL)
	{
		int i = 0;
		if (curr->GetData().GetDeg() == prev->GetData().GetDeg())
		{

					prev->SetData(prev->GetData()+curr->GetData());
					polinom->DeleteElem(curr);
					curr = prev->GetNext();
				
			i++;
		}
		if (prev->GetData().GetCoef() == 0)
		{
			polinom->DeleteElem(prev);
			prev = curr;
			curr = prev->GetNext();
			i++;
		}
		if (curr==NULL)
		{
			break;
		}
		if (i==0)
		{
		prev = curr;
		curr = curr->GetNext();
		}
	}

}

Polinom operator*(const Polinom& l,const Polinom& r)
{
	Polinom *res = new Polinom;
	Node<Monom>* curr_l = l.polinom->GetHead();
	Node<Monom>* curr_r = r.polinom->GetHead();

	while(curr_l !=NULL)
	{
		while(curr_r !=NULL)
		{
			res->AddMonom(curr_l->GetData() * curr_r->GetData());
			curr_r = curr_r->GetNext();
		}

		curr_l = curr_l->GetNext();
		curr_r = r.polinom->GetHead();
	}
	res->Reconstr();
	return *res;

}

	
void Polinom::print()
{
Node<Monom>* curr = polinom->GetHead();
while (curr != NULL)
{
	/*if (curr->GetData().GetCoef() == 1.0)
		std::cout<< "+xyz(" <<curr->GetData().GetDeg()<< ")";*/
	if (curr->GetData().GetDeg() >=0)
		std:: cout<< "+" << curr->GetData().GetCoef() << "xyz("<< curr->GetData().GetDeg()<<")";
	if (curr->GetData().GetCoef() < 0)
		std:: cout << curr->GetData().GetCoef() << "xyz(" << curr->GetData().GetDeg() << ")";
	curr = curr->GetNext();
}
//std::cout << endl;
}