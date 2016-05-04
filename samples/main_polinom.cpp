#include "polinom.h"
#include <iostream>
using namespace std;
void main()
{
	int sp1;
	int a;
	Monom monom1;
	double koef,st;
	Polinom p1, p2,pol;
	Polinom res;
	int b = 1;
	while (b == 1)
	{
		cout << "size polinom 1" << endl;
		cin >> sp1;
		for (int i = 0; i < sp1; i++)
		{
			cout << "Element " << i << ":  " << endl;
			cout << "koef =";
			cin >> koef;
			monom1.SetCoef(koef);
			cout << "deg = ";
			cin >> st;
			monom1.SetDeg(st);
			p1.AddMonom(monom1);
		}
		cout << "polinom1: ";
		p1.print();
		cout << endl;
		cout << "size polinom 2" << endl;
		cin >> sp1;
		for (int i = 0; i < sp1; i++)
		{
			cout << "Element " << i << ":  " << endl;
			cout << "koef = ";
			cin >> koef;
			monom1.SetCoef(koef);
			cout << "deg = ";
			cin >> st;
			monom1.SetDeg(st);
			p2.AddMonom(monom1);
		}
		cout << "vash polinom2: ";
		p2.print();
		cout << endl;
		int k = 1;
		while (k == 1)
		{
			cout << "Select operation 1: +; 2:-; 3:* ";
			cin >> a;
			if (a == 1)
			{
				res = p1 + p2;
				cout << "Result";
				res.print();
			}
			if (a == 2)
			{
				res = p1 - p2;
				cout << "Result";
				res.print();
			}
			if (a == 3)
			{
				res = p1 * p2;
				cout << "Result";
				res.print();
			}
			cout << "Choose other operation?" << endl;
			cout << "yes-1" << endl;
			cout << "no-2" << endl;
			cin >> k;
		}
		p1 = pol;
		p2 = pol;
		cout << "Choose other polinom?" << endl;
		cout << "yes-1" << endl;
		cout << "exit-2" << endl;
		cin >> b;
	}
	
	system("pause");
}