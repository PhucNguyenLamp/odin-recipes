#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
typedef struct Item* ptr;
struct Item{
    int value;
    ptr next;
};
ptr inputList(){
    ptr head = NULL;
    ptr temp;
    int number;
    cin >> number;
    if (number < 0) return NULL;
    while (number >= 0){
        if (head == NULL){
            head = new Item;
            head->value = number;
            head->next = NULL;
        } else {
            temp = new Item;
            temp->value = number;
            temp->next = head;
            head = temp;
        }
        cin >> number;
    }
    return head;
}
int main(){
    cout << inputList()->value;

}
