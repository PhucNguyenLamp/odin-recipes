#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
string many_infix_cal(const string& input){
    stringstream ss(input);
    string line, temp;
    while (getline(ss,line,'\n')){
        stringstream ss2(line);
        int opr1, opr2;
        string opr;
        ss2 >> opr1 >> opr >> opr2;
        if(opr == "+") temp += to_string(opr1 + opr2) + " ";
        if(opr == "-") temp += to_string(opr1 - opr2) + " ";
        if(opr == "*") temp += to_string(opr1 * opr2) + " ";
        if(opr == "/") temp += to_string(opr1 / opr2) + " ";
    }
    return temp;
}
int main(){
    cout << many_infix_cal("10 + 2\n14 * 2\n102 - 10");
}