#include <iostream>

using namespace std;
#define N 20

struct  node
{
    int data;
    node *next;
};

typedef struct node* tro;
tro top;

void init_stack(){
    top = NULL;
}

bool stack_is_full_checking(){
    tro p = top;
    int len = 0;
    while(p != NULL){
        len++;
        p=p->next;
    }
    return (len==N ? 1:0);
}

bool stack_is_empty_checking(){
    node *p = top;
    return (p==NULL ? 1:0);
}

void push(int e){
    node* temp = new node;

    temp->data = e;
    temp->next = top;
    top = temp;

}

void pop(){
    if(stack_is_empty_checking()) cout << "stack underflow " << endl;
    else{
        top = top->next;
    }
}

void display(){
    tro p = top;
    if(stack_is_empty_checking()) cout << "stack underflow" << endl;
    else{
        cout << "stack elements are: ";
        while (p != NULL)
        {
            cout << p->data << ' ';
            p = p->next;
        }
        
    }
    cout << endl;
}

void doi_nhi_phan(int values){
    while(values != 0){
        push(values%2);
        values /= 2;
    }
}
int main(){
    int num;
    init_stack();
    doi_nhi_phan(10);
    display();
    return 0;
}