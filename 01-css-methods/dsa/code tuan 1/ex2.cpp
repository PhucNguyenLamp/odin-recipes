#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
struct action {
    string op;
    int (*func)(int, int);
};
int myadd(int x, int y){ return x + y;}
int mysub(int x, int y){ return x - y;}
int mymul(int x, int y){ return x * y;}
int mydiv(int x, int y){ return x / y;}
int infix_cal(const string& input){
    action add, sub, mul, div;
    add.op = "+"; add.func = myadd;
    sub.op = "-"; sub.func = mysub;
    mul.op = "*"; mul.func = mymul;
    div.op = "/"; div.func = mydiv;
    action ops[] = {add, sub, mul, div};
    int opr1, opr2;
    string opr;
    stringstream ss(input);
    ss >> opr1 >> opr >> opr2;
    for(int i = 0; i < 4;i++){
        if (opr == ops[i].op) return ops[i].func(opr1, opr2);
    }
    return 0;
}
int main(){
    cout << infix_cal("-5 * 6");
}
