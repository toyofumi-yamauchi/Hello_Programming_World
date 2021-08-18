// 04-03-2020
// Let's refresh with C++

#include <iostream>
using namespace std;

int x = 25;  // int型の変数
int *ptr = &x;  // int型へのポインタ

double y[3];
int y0 = 0;
int size = 3;
int p;

struct Test{    // 以下の変数を含むTestという型を宣言
    int     i;  // 変数1
    double  a;  // 変数2
    double  b;  // 変数3
    double  c;  // 変数4
};
Test test; // ここで変数を宣言している
// これ以降test.変数でその変数を扱うことができる

#define m_e 9.1e-31
#define q   1.6e-19
#define N_e 200000

struct Particle{
    double  x;
    double  v;
};
struct Species{
    double   mass;
    double   charge;
    int      N_particle;
    Particle *part;
};

int f(int x, int y){
    return 2 * x + y;
}
void g(int x, int y){
    cout << "g(x,y) = x ^ 2 + y" << endl;
    cout << "g(" << x << "," << y << ") = " << 2*x+y << "\n" << endl;
}

int main()
{
    cout << "Hello C++ World\n" << endl;
    
    cout << "x    = " << x << endl;
    cout << "&x   = " << &x << endl;
    cout << "*ptr = " << *ptr << endl;
    cout << "ptr  = " << ptr << "\n" << endl;

    y[0] = y0;
    for (p = 1; p <= size-1; p++) {
        y[p] = y[p-1] + 1;
    }
    double *point = &y[1];
    cout << "y[0]   = " << y[0] << endl;
    cout << "y[1]   = " << y[1] << endl;
    cout << "y[2]   = " << y[size-1] << endl;
    cout << "*point = " << *point << "\n" << endl;

    Test test[] = {
        {1,1,1,1},
        {1,2,3,5},
        {2,3,9,10},
        {3,4,12,15}
    };
    //cout << "test.i = " << test.i << endl;
    //cout << "test.a = " << test.a << endl;
    //cout << "test.b = " << test.b << endl;
    //cout << "test.c = " << test.c << endl;
    //cout << "*b = " << *b << "\n" << endl;

    Species electron;

    electron.mass      =   m_e;
    electron.charge    =   -q;
    electron.part      =   new Particle[N_e];
    cout << "electron.mass = " << electron.mass << endl;
    cout << "electron.charge = " << electron.charge << endl;
    cout << "electron.part = " << electron.part << "\n" << endl;

    cout << "f(x,y) = 2 * x + y" << endl;
    cout << "f(1,2) = " << f(1,2) << endl;
    g(2,4);
}