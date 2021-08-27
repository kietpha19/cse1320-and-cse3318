#include <iostream>
using namespace std;

struct node {
    int num;
    struct node *p;
};
typedef struct node NODE;

struct list{
    NODE *head;
    NODE *last;
};
typedef struct list LIST;

void createList(LIST **l){

}

int main(){

    system("pause");
    return 0;
}