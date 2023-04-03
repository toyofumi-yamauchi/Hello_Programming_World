#include <iostream>

using namespace std;
/**
* http://www7b.biglobe.ne.jp/~robe/cpphtml/mainmenu.html
*/

int f(int x, int y)
{
    // cout << "f = 2 * x + y" << endl;
    return 2 * x + y;
}

void F(int x, int y)
{
    cout << "F(" << x << "," << y << ") = " << 2 * x + y << endl;
}

void Hello()
{
    cout << "Hello World" << endl;
}

int c = 0;
void Test()
{
    int d = 0;
    c++;
    d++;
    cout << c << " <- c | d -> " << d << endl;
    return;
}
int d = 0;

void age()
{
    int a;
    cout << "Which year were you born?: ";
    cin >> a;
    if(0 <= a && a <= 2020) // use || for "or"
    {
        int b = 2020 - a;
        cout << "You are " << b << "-yaers-old, right?" << endl; 
    }  
    if(a == 1995)
    {
        cout << "By the way, you are of my age." << endl;
    }
    
    else
    {
        cout << "Are you coming from future?" << endl;
    }
}

void division()
{
    int a,b;
    cout << "Type 1st number: ";
    cin >> a;
    cout << "Type 2nd number: ";
    cin >> b;
    if(b == 0)
    {
        cout << "                 You cannot divide by 0!" << endl;
    }
    else
    {
        cout << "                 " << a << " ÷ " << b << " = " << a/b << "..." << a%b << endl;
    }
    return;
    
}

int Change_to_Heisei(int a)
{
    if(1989 <= a && a <= 2019)
        return a - 1988;
    else
        return 0;        
}

void Heisei()
{
    int a;
    cout << "Type current year: ";
    cin >> a;
    if(Change_to_Heisei(a) == 0)
        cout << "                   That year is not Heisei." << endl;
    else
        cout << "                   That year is Year " << Change_to_Heisei(a) << " of Heisei Era." << endl; 
}

void Points()
{
    int a;
    cout << "What point did you get in the last exam?: ";
    cin >> a;
    cout << "Oh, you made " << a * (0 <= a && a <= 100) << " points! Cool." << endl;
}

int N[] = {
        641, 703, 405, 598, 402, 752, 330,   0, 445, 662, 
        254, 710, 467, 530, 548, 485, 244, 396, 601, 510, 
        532, 687, 623, 420, 647, 587, 490, 647, 575, 688, 
        764, 633, 712, 312, 655, 425, 722, 631, 680, 602};

int main()
{
    cout << "Hello!VisualStudioCode" << endl;

    cout << "---" << endl;

    cout << 2 << '+' << 3 << '=' << 2 + 3 << endl;
    cout << "π = " << 3.14159 << "..." << endl;

    cout << "---" << endl;

    cout << "2 + 2 = " << 2 + 2 << endl;
    cout << "1 - 5 = " << 1 - 5 << endl;
    cout << "2 * 9 = " << 2 * 9 << endl;
    cout << "9 / 3 = " << 9 / 3 << endl;
    cout << "9 / 2 = " << 9 / 2 << endl;
    cout << "9 % 2 = " << 9 % 2 << endl;
    cout << "9.0 / 2 = " << 9.0 / 2 << endl;
    cout << "9.0 / 4 = " << 9.0 / 4 << endl;
    cout << "2 + 2 * 4 = " << 2 + 2 * 4 << endl;
    cout << "(1 - 5) / 2 = " << (1 - 5) / 2 << endl;
    cout << "(1 - 4) / 2 = " << (1 - 4) / 2 << endl;
    cout << "(1.0 - 4) / 2 = " << (1.0 - 4) / 2 << endl;
    cout << "(1 - 4) / 2.0 = " << (1 - 4) / 2.0 << endl;

    cout << "---" << endl;

    int a;
    a = 5;
    cout << "a = " << a << endl;
    cout << "a * 2 = " << a * 2 << endl;

    cout << "---" << endl;

    int b = 0;
    cout << "b = " << b << endl;
    b += 2;
    cout << "b += 2        -> b = " << b << endl;
    b++;
    cout << "b++           -> b = " << b << endl;
    b =  b * 5 + b;
    cout << "b = b * 5 + b -> b = " << b << endl;

    cout << "---" << endl;

    cout << "f(1,2) = " << f(1,2) << endl;
    cout << "f(182,144) = " << f(182,144) << endl;

    cout << "---" << endl;

    F(1,2);
    F(182,144);

    cout << "---" << endl;

    Hello();

    cout << "---" << endl;

    Test();
    Test();
    Test();

    cout << "---" << endl;

    cout << "Enter your favorite number: ";
    // cin >> a;
    a = 47;
    cout << "Your favorite number ("<< a <<") times 3 is " << a * 3 << endl;

    //cout << "---" << endl;

    //age(); // type 1995
    //age(); // type 2000
    //age(); // type 2021

    //cout << "---" << endl;

    //division(); // type 17 and 3
    //division(); // type 3 and 0

    //cout << "---" << endl;

    //Heisei(); // type 1995
    //Heisei(); // type 2020

    //cout << "---" << endl;

    //Points(); // type 94
    //Points(); // type -10

    cout << "---" << endl;

    int i;
    for(i = 0; i <= 5; i++)
    {
        cout << "***" << i << endl;
    }

    cout << "---" << endl;

    int n[2];
    n[0] = 100;
    cout << "n[0] = " << n[0] << endl;
    n[1] = 200;
    cout << "n[0] = " << n[0] << endl;
    n[0] = 300;
    cout << "n[0] = " << n[0] << endl;

    cout << "---" << endl;

    //int i; // commented out for avoiding the redefining
    int nSum = 0;
    for (i = 0; i < sizeof(N)/sizeof(*N); i++)
        nSum += N[i];
    cout << "The average is " << nSum / 40.0 << "." << endl;

    cout << "---" << endl;

    for(i = 5; i < 10; i += 2)
        cout << i << endl;
 
    cout << "---" << endl;

    for(i = 10000; i < 10; i++)
        cout << i << endl;

    cout << "---" << endl;
    
    a = 0;
    for(i = 0; a < 10; i++)
    {
        cout << i << ", " << a << endl;
        a += 2;
    }

    cout << "---" << endl;

    a = 0;
    for(; a < 10;)
    {
        cout << i << ", " << a << endl;
        a += 2;
    }

    cout << "---" << endl;

    i = 0;
    do
    {
        cout << "Is this shown up?" << endl;
    } while (i != 0);
    
    cout << "---" << endl;

    /**
    while(1)
    {
        cout << "Type your 1st number: " << endl;
        cin >> a;
        cout << "Type your 2nd number: " << endl;
        cin >> b;
        if(b == 0)
        {
            cout << "You cannot divide by 0!" << endl;
            break;
        }
        cout << a << " / " << b << " = "
        << a / b << "..." << a % b << endl;
    }
    cout << "The program has ended." << endl;

    cout << "---" << endl;

    for(i = 0; i < 5; i++)
    {
        cout << "Type your 1st number: " << endl;
        cin >> a;
        cout << "Type your 2nd number: " << endl;
        cin >> b;
        if(b == 0)
        {
            cout << "You cannot divide by 0!" << endl;
            continue;
        }
        cout << a << " / " << b << " = "
        << a / b << "..." << a % b << endl;
    }
    cout << "The program has ended." << endl;

    cout << "---" << endl;

   int sign;
   int result;

   for(i = 0; i < 5; i++)
   {
       cout << "1st number: ";
       cin >> a;
       cout << "2nd number: ";
       cin >> b;
       cout << "Choose sign: 1.+, 2.-, 3.x, 4./ ->";
       cin >> sign;
       switch(sign)
       {
           case 1:
           result = a + b; break;
           case 2:
           result = a - b; break;
           case 3:
           result = a * b; break;
           case 4:
           result = a / b; break;
           default:
           cout << "The unvalid operator input." << endl;
           continue;
       }
       cout << "The answer is " << result << "." << endl;
   }
    */


    return 0;
}