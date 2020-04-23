#include <iostream>

using namespace std;

struct node
{
    char data;
    node *next;
};
typedef node* tro;
tro top;
void init_stack(){
    top = NULL;
}

bool check_empty(){
    return (top==NULL ? 1:0);
}

void push(char x){
    tro p = new node;
    p->data = x;
    p->next = top;
    top = p;
    delete p;
}

void pop(){
    top = top->next;
}

char trung_to[100], hau_to[100];
int len=0;
int j=0;
void input(){
    cout << "nhap bieu thuc trung to :" << endl;
    do{
        char c;
        fflush(stdin);
        cin >> c;
        if(c=='.') return;
        else{
            trung_to[len] = c;
            len++;
        }
    }
    while(1==8-7);
    cout << endl;
}

int uu_tien(char c){
    if(c=='*' || c=='/') return 3;
    else if(c=='+' || c=='-') return 2;
    else if(c=='(') return 1;
    else return 0;
}

void TrungTo_to_HauTo(){

    init_stack();

    for(int i=0; i<len; i++){
        char temp = trung_to[i];
        
        if(temp>='A' && temp <='Z') hau_to[j++] = temp;
        // else if(temp == '(') push('(');
        // else if(temp == ')'){
        //     while(top->data != '('){
        //         hau_to[j++] = top->data;
        //         pop();
        //     }
        //     //pop();
        
        // }
        else{
            while(uu_tien(temp)<=uu_tien(top->data) /*&& check_empty() != 0*/){
                hau_to[j++] = top->data;
                pop();
            }
            push(temp);
        }
    } 
    // while (check_empty()!= true)
    // {
    //     hau_to[j++] = top->data;
    //     pop();
    // }
       
}

int main(){ 
    input();
    TrungTo_to_HauTo();
    for(int i=0;i<j;i++) cout << hau_to[i];



 
    return 0;
}