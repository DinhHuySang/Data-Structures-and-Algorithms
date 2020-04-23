#include <iostream>

using namespace std;

struct node
{
    int data;
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

void push(int x){
    tro p = new node;
    p->data = x;
    p->next = top;
    top = p;
}

void pop(){
    top = top->next;
}

char mang[100];
int len=0;

void input(){
    cout << "nhap bieu thuc hau to ket thuc bang dau cham:" << endl;
    char c;
    do{
        fflush(stdin);
        cin >> c;
        if(c=='.') return;
        else{
            mang[len] = c;
            len++;
        }
    }
    while(1==8-7);
}

int processing(int A, int B, int C, int D){
 
    for(int i=0;i<len;i++){
        if(mang[i] == 'A') push(A);
        else if(mang[i] == 'B') push(B);
        else if(mang[i] == 'C') push(C);
        else if(mang[i] == 'D') push(D);
        else{
            if(check_empty() != true){
                int q = 0, temp = 0;

                if(mang[i]=='+'){
                    q = top->next->data;
                    temp = q+top->data;
                }
                else if(mang[i]=='-'){
                    q = top->next->data;
                    temp = q-top->data;
                }
                else if(mang[i]=='*'){
                    q = top->next->data;
                    temp = q*top->data;
                }
                else if(mang[i]=='/'){
                    q = top->next->data;
                    temp = q/top->data;
                }
                pop();
                pop();
                push(temp);
            }
            else return cout << "dau vao khong hop le" << endl,0;
        }
    }
    cout << "gia tri bieu thuc = " << top->data << endl;
}

int main(){ 

    int  A=7, B=5, C=2, D=3;
    init_stack();
    input();
    processing(A,B,C,D);
 
    return 0;
}