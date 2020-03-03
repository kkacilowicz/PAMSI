#pragma once
class Trojkat
{
public:

	double a;
	double b;
	double c;

	double Obwod(Trojkat T) {
		double ob;
		ob = T.a + T.b + T.c;

		return ob;
	};

};

