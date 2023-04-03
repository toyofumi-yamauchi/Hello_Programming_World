#include <iostream>
#include <cstring>

using namespace std;
/**
* http://www7b.biglobe.ne.jp/~robe/cpphtml/mainmenu.html
*/

void f(int x, int y)
{
    char szResult[50];
    sprintf(szResult, "f(%d, %d) = %d", x, y, 2 * x + y);
    // sprintf(input, output(%d, %d, %d...), %d, %d, %d...)
    // %d: 整数
    // %x: 16進数
    // %f: 少数
    // %c: 1文字
    // %s: 文字列   
    cout << szResult << endl;
}

#define NUMBER_FIBO 10
#define LOOP(val, times) for(val = 0; val < (times); val++)
#define MUL1(a, b)   a * b
#define MUL2(a, b) ((a)*(b))
//#define マクロ名(通常大文字) 差し込むテキスト

void ChangeToShowa(int* point)
{
    if(1926 < *point && *point < 1989)
        *point -= 1925;
    else
        *point = 0;
}

void Showa()
{
    int nYear;
    cout << "Type the current year: ";
    cin >> nYear;
    ChangeToShowa(&nYear);
    if(nYear)
        cout << "That is the Year " << nYear << " of the Showa era." << endl;
    else
        cout << "That year is not in the Showa era." << endl;
}

void Display(int array[])
{
    int i;
    for(i = 0; i < 5; i++)
        cout << array[i] << endl;
}
int main()
{
    cout << "---" << endl;
    // Characterは通し番号で管理されている
    cout << "The number assigned to '0' is "  << (int)(unsigned char)'0' << endl;
    cout << "The number assigned to 'a' is "  << (int)(unsigned char)'a' << endl;
    int i;
    char szHello[] = "*+,-./012ABCabc";
    cout << "'" << szHello << "' in ASCII code is" << endl;
    for(i = 0; i < strlen(szHello); i++)
    {
        cout << (int)(unsigned char)szHello[i] << endl; 
    }
    cout << (int)(unsigned char)szHello[i] << endl; 

    cout << "---" << endl;
    //sprintfを使ってみよう
    f(1,2);
    f(182,144);

    cout << "---" << endl;
    // フィボナッチ数列
    // マクロ NUMBER_FIBOを変えれば別のオーダーに対応可能
    int nFibo[NUMBER_FIBO] = {1, 1};
    for(i = 0; i < NUMBER_FIBO - 2; i++)
    {
        nFibo[i + 2] = nFibo[i] + nFibo[i + 1];
    }
    cout << "The " << NUMBER_FIBO << "'th order of Fibonacci number" << endl;
    LOOP(i, NUMBER_FIBO - 1) //for(i = 0; i < (NUMBER_FIBO - 1); i++)
        cout << nFibo[i] << ", ";
    cout << nFibo[i] << "." << endl;

    cout << "---" << endl;
    //マクロのルール 変数は()で囲む
    cout << MUL1(1 + 4, 2 + 8) * 3 << endl;
    cout << MUL2(1 + 4, 2 + 8) * 3 << endl;

    cout << "---" << endl;
    //メモリ上のアドレスを表示する
    int  a;
    char b[10];
    printf("a    : %d\nb    : %d\nmain : %d\n",&a, b, main); //printfは\nで改行

    cout << "---" << endl;
    //アドレスとポインタ
    char c;
    char* p;
    p = &c;
    //cout << " p = " << (unsigned int) p << endl; //(unsigned int)がうまく作用せず
    //cout << "&c = " << (unsigned int)&c << endl; //(unsigned int)がうまく作用せず
    int d; 
    int* P = &d;
    d = 0; // dに0を入れる
    cout << " d = " << d << endl;
    cout << "*P = " << *P << endl;
    *P = 5; //*Pに0を入れる
    cout << " d = " << d << endl;
    cout << "*P = " << *P << endl;
    
    //cout << "---" << endl;
    //Showa();
    //Showa();

    cout << "---" << endl;
    //int i;
    int n[5];
    for(i = 0; i < 5; i++)
        n[i] = i*5;
    for(i = 0; i < 5; i++)
        printf("array[%d]  : %d\n", i, n[i]);
    printf("array     : %d\n", n);
    for(i = 0; i < 5; i++)
        printf("&array[%d] : %d\n", i, &n[i]);
    
    cout << "---" << endl;
    // 参照
    int A;
    int& r = A;
    A = 0;
    cout << "A = " << A << endl;
    cout << "r = " << r << endl;
    r = 100;
    cout << "A = " << A << endl;
    cout << "r = " << r << endl;
    //cout << "&A = " << (unsigned int)&A << endl;
    //cout << "&r = " << (unsigned int)&r << endl;
    
    return 0;
}