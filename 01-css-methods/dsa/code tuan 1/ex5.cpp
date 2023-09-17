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
ptr inputList(){
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
void printList(ptr first){
    ptr temp = first;
    while (temp != NULL){
        cout << temp->coef << "," << temp->exp << " ";
        temp = temp->next;
    }
}
void normalizePolynomial(ptr& first){
    ptr temp = first;
    int highest = 0;
    while (temp != NULL){
        if (temp->exp > highest) highest = temp->exp;
        temp = temp->next;
    }
    temp = first;
    int coefs[highest+1]={0};
    for (int i=0;i<=highest;i++){
        while (temp != NULL){
            if (temp->exp == i){
                coefs[i]+=temp->coef;
            }
            temp = temp->next;
        }
        temp = first;
    }
    first = NULL;
    ptr head = NULL;
    for (int i=0;i<=highest;i++){
        if (coefs[i] != 0){
            if (first == NULL){
                first = new Item;
                first->coef = coefs[i];
                first->exp = i;
                first->next = NULL;
                head = first;
            } else {
                temp = new Item;
                temp->coef = coefs[i];
                temp->exp = i;
                temp->next = NULL;
                head->next = temp;
                head = temp;
            }
                
        }
    }
}
int main(){
    ptr first = inputList();
    normalizePolynomial(first);
    printList(first);
    return 0;
}

