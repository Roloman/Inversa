// MCM_Algoritmos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "MCD.h"

#include <bitset>
#define M 1028



MCD::MCD()
{

}

MCD::~MCD()
{
    //dtor
}

ZZ MCD::Valor_Absoluto(ZZ a)
{
    if (a < 0)
        return a * -1;
    else
    {
        return a;
    }
}

ZZ MCD::modulo(ZZ a, ZZ b)
{
    return a - ((a / b) * b);
}

ZZ MCD::ejer1(ZZ a, ZZ b)
{
    ZZ r = modulo(a, b);
    while (r != 0)
    {
        cout << a << " = " << a / b << " (" << b << ") + " << a - (b * (a / b)) << endl;
        a = b;
        b = r;
        r = modulo(a, b);
    }
    cout << a << " = " << a / b << " (" << b << ") + " << a - (b * (a / b)) << endl;
    return b;
}

ZZ MCD::ejer2(ZZ a, ZZ b)
{
    ZZ r = modulo(a, b);
    while (r != 0)
    {
        //cout << "a: " << a << " b: " << b << " r: " << r;

        if (r > b / 2)
        {
            r = b - r;
            //cout << "r= " << r << endl;
        }
        a = b;
        b = r;
        r = modulo(a, b);
    }
    return b;
}

ZZ MCD::ejer3(ZZ a, ZZ b)
{
    //cout << "a: " << a << " b: " << b << endl;
    if (b == 0)
        return a;
    return ejer3(b, modulo(a, b));
}

ZZ MCD:: ejer4(ZZ a, ZZ b)
{
    ZZ dos = ZZ(2);
    //cout << "a: " << a << " b: " << b << endl;
    if (Valor_Absoluto(b) > Valor_Absoluto(a))
        return ejer4(b, a);
    if (b == 0)
        return a;
    if (modulo(a, dos) == 0 && modulo(b, dos) == 0)
        return 2 * ejer4(a / 2, b / 2);
    if ( modulo(a, dos) == 0 && modulo(b, dos) != 0)
        return ejer4(a / 2, b);
    if (modulo(a, dos) != 0 && modulo(b, dos) == 0)
        return ejer4(a, b / 2);
    else
    {
        return ejer4((Valor_Absoluto(a) - Valor_Absoluto(b)) / 2, b);
    }
}

ZZ MCD::ejer5(ZZ x, ZZ y)
{
    ZZ g = ZZ(1);
    ZZ t;
    while (x % 2 == 0 && y % 2 == 0)
    {
        x = x / 2;
        y = y / 2;
        g = 2 * g;
        //cout << "x: " << x << " y: " << y << " g: " << g << endl;
    }
    while (x != 0)
    {
        while (x % 2 == 0)
        {
            x = x / 2;
        }
        while (y % 2 == 0)
        {
            y = y / 2;
        }
        t = Valor_Absoluto(x - y) / 2;
        if (x >= y)
        {
            x = t;
        }
        else
        {
            y = t;
        }
    }
    return g * y;
}

int ejer51(int x, int y)
{
    ZZ f;
    bitset<8> bsx(x);
    bitset<8> bsy(y);
    bitset<8> bsg(1);
    bitset<8> bst;
    bitset<8> cero(0);
    int g = 1;
    int t;
    while (bsx[0] == 0 && bsy[0] == 0)
    {
        bsx >>=1;
        bsy >>= 1;
        g = 2 * g;
        //cout << "x: " << x << " y: " << y << " g: " << g << endl;
    }
    while (bsx != 0)
    {
        while (bsx[0] == 0)
        {
            bsx >>= 1;
        }
        while (bsy[0] == 0)
        {
            bsy >>= 1;
        }
        bsy >>= 1;
        //bst = bsx - bsy;
        if (x >= y)
        {
            x = t;
        }
        else
        {
            y = t;
        }
    }
    return g * y;
}

ZZ MCD::ejer6(ZZ a, ZZ b)
{
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
        {
            b = b - a;
        }
    }
    return a;
}

ZZ MCD::Euclides_Recursivo(ZZ a, ZZ b)
{
    ZZ r = modulo(a, b);
    cout << "a: " << a << " b: " << b << " r: " << r;
    if (r == 0)
        return b;
    return Euclides_Recursivo(b, r);
}

ZZ MCD::Euclides_Iterativo(ZZ a, ZZ b)
{
    ZZ r = modulo(a, b);
    ZZ q;
    while (b > 0)
    {
        q = a / b;
        r = a - q * r;
        a = b;
        b = r;
        cout << "a: " << a << " b: " << b << " r: " << r << " q: " << q << endl;
    }
    return a;
}



ZZ MCD::Extendido_Euclides(ZZ a, ZZ b)
{
    ZZ q;
    ZZ r, r1, r2;
    ZZ s, s1, s2;
    ZZ t, t1, t2;

    r1 = a;
    r2 = b;
    s1 = ZZ(1);
    s2 = ZZ(0);
    t1 = ZZ(0);
    t2 = ZZ(1);

    while (r2 > 0) {

        q = r1 / r2;
        r = r1 - (q * r2);
        r1 = r2;
        r2 = r;
    
        s = s1 - (q * s2);
        s1 = s2;
        s2 = s;
    
        t = t1 - (q * t2);
        t1 = t2;
        t2 = t;
    }
    r = r1;
    s = s1;
    t = t1;
    if (s < 0)
        s = s % b;
    if (t < 0)
        t = t % a;
    cout << a << "(" << s << ") + " << b << "(" << t << ") = " << r << endl;
    return s;
}

ZZ MCD::Inversa(ZZ a, ZZ b) {
    
    ZZ r = ZZ(0);
    ZZ c;
    if (ejer1(a, b) == 1) {

        c = Extendido_Euclides(a, b);
        if (c < 0) 
            c = modulo(c, b);

    }
    else
    {
        cout << a << " No tiene inversa" << endl;
        return r;
    }
    return c;
}

void hallar_k() {

    int x, f, k;
    cout << "x = ";
    cin >> x;
    cout << "b/d = ";
    cin >> f;
    cout << "k = ";
    cin >> k;
    //cout << "x0 + fk" << endl;
    cout << x + (f * k) << endl;
}

int main()
{
    MCD f;
    ZZ a, b, c;
    //cin >> a;
    //cin >> b;
    //f.Extendido_Euclides(a, b);
    //f.ejer1(a, b);
    //cout << f.Inversa(a, b) << endl;

    
    //int x = 0;
    //int y = 0;
    //cin >> x;
    bitset<8> bs1("10000100"); // 10000011
    bitset<8> bs2("00000111");
    //bitset<8> bset2(x);
    //cout << bs1 << endl;
    //cout << bs2 << endl;
    //cout << "& " << (bs1 | bs2) << endl;
    //cin >> bset2;
    
    //cout << "bset2 = " << bset2 << endl;
    //cout << bs1 << endl;
    if (bs1[0] == 1) {
        //std::cout << "1st bit is 1" << std::endl;
    }



    //hallar_k();

    //std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
