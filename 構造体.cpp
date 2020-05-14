// 構造体(struct)を理解しよう
// 第58章 構造体1 http://www7b.biglobe.ne.jp/~robe/cpphtml/html01/cpp01058.html
// 第59章 構造体2 http://www7b.biglobe.ne.jp/~robe/cpphtml/html01/cpp01059.html
// 第60章 構造体3 http://www7b.biglobe.ne.jp/~robe/cpphtml/html01/cpp01060.html

#include <iostream>
using namespace std;

#define ELEM(array)  (sizeof (array) / sizeof *(array))

struct SStudent{
    char szName[16];
    int  nJapanese;
    int  nMath;
    int  nEnglish;
};

void Disp(const SStudent* pstudent);

int main(){

    SStudent students[] = {
        { "阿東一郎", 73, 98, 86, },
        { "加藤二郎", 64, 45, 40, },
        { "佐藤三郎", 76, 78, 69, },
    };

    int      i;
    for(i = 0; i < ELEM(students); i++)
        Disp(&students[i]);

    return 0;
}

/************** FUNCTIONS **************/
void Disp(const SStudent* pstudent){
    cout << "名前: "   << pstudent->szName    << endl
         << "国語: "   << pstudent->nJapanese << " 点, "
            "数学: "   << pstudent->nMath     << " 点, "
            "英語: "   << pstudent->nEnglish  << " 点" << endl;
}