// "ローベルのC++教室"をもう一度最初から
// 第１部 第６２章まで

#include <iostream>
using namespace std;

// 関数を決める
/* int f(引数){
    return 戻り値 // ここでの型はintになる
}*/
int f(int x, int y){
    return 2*x+y;
}
void g(){ //戻り値がいらない場合はvoidを使う
    cout << "g() = 戻り値なしの関数" << endl;
}
// 関数のプロトタイプの使い方
int h(int x, int y);

// マクロ
// #define マクロ名 差し込むテキスト
#define speed_of_light 3e8 // [m/s]
// 定数
// const 型 名前 = 値
const double R_gas = 8.314; // [J/mol/K]
// マクロと定数は全部大文字にしておくと後々楽(らしい)

// ポインタを使った参照渡し
#define n 5
void m(double* pointer);

// 構造体について
struct R{       // Rという構造体を宣言(オブジェクト)
   double s;    // 変数を宣言(メンバ)
   double t[];  // 配列を宣言(メンバ)
};
R r; // 構造体の中の要素を宣言
void U(R* w);

struct Species{
    double mass;
    double charge;
};
Species electron;
Species ion;
void W(Species* point);

int main(){
    
    // まずは Hello World から
    cout << "Hello ローベルのC++教室\n" << endl;

    // 割り算のルール
    cout << "9/2 = " << 9/2 << endl;        // 普通の割り算
    cout << "9.0/2 = " << 9.0/2 << endl;    // 少数を使うと少数まで計算できる
    cout << "9/2.0 = " << 9/2.0 << endl;    // 少数を使うと少数まで計算できる 
    cout << "9%2 = " << 9%2 << "\n" << endl;        // ％を使うと余りが計算できる

    // 変数
    int a; // 変数の型を宣言
    a = 1; // 変数に値を代入
    cout << "a = " << a << endl;
    int b = 2; // 変数の型の宣言と値の代入を同時に
    cout << "b = " << b << "\n" << endl;

    // 関数を使ってみる
    cout << "f(x,y) = 2*x+y" << endl;
    cout << "f(1,2) = 2*1+2 = " << f(1,2) << endl;
    cout << "2*f(1,2) = " << f(1,2)*2 << endl;
    g();
    cout << "h(x,y) = 3*x+2*y" << endl;
    cout << "h(1,2) = 3*1+2*2 = " << h(1,2) << "\n" << endl;

    // forループ
    for(int i = 0; i < 5; i++){
        cout << "this is " << i << "'th loop" << endl;
    }
    cout << "\n" << endl;

    // 配列変数
    int c[4];   // これでc[0], c[1], c[2]. c[3]という４つの変数を宣言
    c[0] = 0;   // c[0]に代入
    c[1] = 1;   // c[1]に代入
    c[2] = 2;   // c[2]に代入
    c[3] = 3;   // c[3]に代入
    cout << "c[0] = " << c[0] <<endl;
    cout << "c[1] = " << c[1] <<endl;
    cout << "c[2] = " << c[2] <<endl;
    cout << "c[3] = " << c[3] <<endl;
    int d[4] = {0,1,2,3};  // 上の作業を一度に
    for(int i = 0; i < 4; i++){ 
        cout << "d[" << i << "] = " << d[i] << endl;
    } // 今回はfor loopを使ってみた
    int e[]={}; // for loopを使って代入をやってみる。={}がないと大きさ未定の配列が作れない？
    for(int i = 0; i <= 5; i++){ //ここでループした分だけ配列に変数が追加されていく
        e[i] = i;
        cout << "e[" << i <<"] = " << e[i] << endl;
    }
    cout << "\n" << endl;

    // マクロを使ってみる
    cout << "speed of light is " << speed_of_light << " [m/s]" << "\n" << endl;

    // アドレスについて
    double i = 1;
    double j[2];
    j[0] = 2;
    j[1] = 3;
    cout << "i =    " << i << endl;
    cout << "j[0] = " << j[0] << endl;
    cout << "j[1] = " << j[1] << endl;
    cout << "&i =    " << &i << endl;    // &を使うと変数のアドレスが分かる
    cout << "&j =    " << &j << endl;    // 配列でも同じ
    cout << "j  =    " << j << endl;     // 配列では&を使わなくてもアドレスが表示される
    cout << "&j[0] = " << &j[0] << endl; // 配列の場所は配列の最初の数字と同じ場所にある
    cout << "&j[1] = " << &j[1] << "\n" << endl; // それ以降は一個づつずれていく

    // ポインタについて
    int k;
    int* l = &k; // lはkのアドレスを格納するポインタ
    k = 1;
    cout << " l = " << l << endl;   // lにkのアドレスが入ってる
    cout << "&k = " << &k << endl;  // &kはkのアドレスを示す
    cout << " k = " << k << endl;   // k = 1
    cout << "*l = " << *l << endl;  // *lにはkの値が入ってる
    *l = 2;
    cout << "after '*l = 2'" << endl; 
    cout << "*l = " << *l << endl;  // *lを使ってkの値を変えることもできる
    cout << " k = " << k << "\n" << endl;
    
    // ポインタを使った参照渡しの例
    double o[n];
    cout << "o" << endl;
    for(int i = 0; i < n; i++){
        o[i] = i*5;
        cout << "o[" << i << "] = " << &o[i] << endl;
        //cout << "value   = " << o[i] << endl;
    }
    m(o);
    cout << "\n" << endl;

    // 配列のサイズはこれ
    cout << ((sizeof o)/(sizeof *o))<< endl;
    cout << "\n" << endl;

    // 参照について
    int p;
    int& q = a;
    // これで一発で参照できる

    // 構造体
    r.s = 1;    // r.sを普通の変数みたいに扱える
    cout << "r.s = " << r.s << endl;
    for(int i = 0; i < n; i++){ // r.tを普通の配列みたいに扱える
        r.t[i] = i*3;
        cout << "r.t[" << i << "] = " << r.t[i] << endl;
    }
    cout << "\n" << endl;

    U(&r); //&をつかって参照してる

    // 構造体の参照
    electron.mass = 9.11e-31;
    electron.charge = -1.6e-19;
    ion.mass = 2.18e-25;
    ion.charge = 1.6e-19;

    W(&electron);
    W(&ion);

};

// プロトタイプで決めた関数を定義
int h(int x, int y){
    return 3*x+2*y;
}

void m(double* pointer){
    cout << "pointer" << endl;
    for(int i = 0; i < n; i++){
        cout << "pinter[" << i << "] = " << &pointer[i] << endl;
        //cout << "value   = " << pointer[i] << endl;
    }
}

void U(R* w){   //wがRに対するポインター的な役割(&を使った参照先とつながっている)
    cout << "w->s = " << w->s << endl; // 
    double z = w->s;
    cout << "z = w->s" << endl;
    cout << "2*x = " << 2*z << endl;
    for(int i = 0; i < n; i++){
        cout << "w->t[" << i << "] = " << w->t[i] << endl;
    }
    cout << "\n" << endl;
}

void W(Species* point){
    cout << "mass is " << point->mass << " [kg]" << endl;
    cout << "charge is " << point->charge << " [C]" << endl;
}