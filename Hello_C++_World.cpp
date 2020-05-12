// 04-03-2020
// Let's refresh with C++

#include <iostream>
using namespace std;

#define ELEM(array)  (sizeof (array) / sizeof *(array))

struct SStudent
{
    char szName[16];
    int  nJapanese;
    int  nMath;
    int  nEnglish;
};

void Disp(const SStudent& student)
{
    cout << "名前 : "   << student.szName    << endl
         << "　国語 : " << student.nJapanese << " 点, "
            "数学 : "   << student.nMath     << " 点, "
            "英語 : "   << student.nEnglish  << " 点" << endl;
}

int x = 25;  // int型の変数
int *ptr = &x;  // int型へのポインタ

double y[2];
int p;

int main()
{
    cout << "Hello C++ World" << endl;
    y[0] = 0;
    for (p = 0; p < 3; p++) {
        y[p] = p + 1;
    }

    double *y = &y[3];

    cout << "x = " << x << endl;
    cout << "&x = " << &x << endl;
    cout << "*ptr = " << *ptr << endl;
    cout << "ptr = " << ptr << endl;
    cout << "y[0] = " << y[0] << endl;
    cout << "y[1] = " << y[1] << endl;
    cout << "y[2] = " << y[2] << endl;
    cout << "y = " << *y << endl;

    SStudent students[] = {
        { "赤井孝",   73, 98, 86, },
        { "笠井大介", 64, 45, 40, },
        { "吉田叶",   76, 78, 69, },
    };
    int      i;

    for(i = 0; i < ELEM(students); i++)
        Disp(students[i]);

    return 0;
}