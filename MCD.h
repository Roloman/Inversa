#pragma once

#include <NTL/ZZ.h>
#include <iostream>

using namespace std;
using namespace NTL;

class MCD
{
public:
	MCD();
	ZZ Valor_Absoluto(ZZ a);
	ZZ modulo(ZZ a, ZZ b);
	
	ZZ ejer1(ZZ a, ZZ b);
	ZZ ejer2(ZZ a, ZZ b);
	ZZ ejer3(ZZ a, ZZ b);
	ZZ ejer4(ZZ a, ZZ b);
	ZZ ejer5(ZZ x, ZZ y);
	//ZZ ejer51(ZZ x, ZZ y);
	ZZ ejer6(ZZ a, ZZ b);

	ZZ Inversa(ZZ a, ZZ b);
	ZZ Extendido_Euclides(ZZ a, ZZ b);
	ZZ Euclides_Recursivo(ZZ a, ZZ b);
	ZZ Euclides_Iterativo(ZZ a, ZZ b);

	virtual ~MCD();
protected:
private:
};
