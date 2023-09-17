#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
typedef struct Item* ptr;
struct Item{
    double coef; // coefficient
    int exp; // exponent
    ptr next;
};
ptr inputPolynomial(){
    ptr head = NULL;
    ptr temp;
    double coef;
    int exp;
    cin >> coef >> exp;
    if (coef == 0) return NULL;
    while (coef != 0){
        if (head == NULL){
            head = new Item;
            head->coef = coef;
            head->exp = exp;
            head->next = NULL;
        } else {
            temp = new Item;
            temp->coef = coef;
            temp->exp = exp;
            temp->next = head;
            head = temp;
        }
        cin >> coef >> exp;
    }
    return head;
}
int main(){

}