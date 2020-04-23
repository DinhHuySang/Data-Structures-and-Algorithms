#include <iostream>

using namespace std;

struct node 
{
    char ngoac;
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

void push(char ng){
    tro p = new node;
    p->ngoac = ng;
    p->next = top;
    top = p;
}

void pop(){
    top = top->next;
}

void display(){
    if(check_empty()) cout << "day la chuoi ngoac DUNG" << endl;
    else{
        cout << "day la chuoi ngoac KHONG DUNG" << endl;
    }
}

int len=0;
char mang[100];
void nhap(){
    cout << "nhap chuoi ngoac va ket thuc bang dau cham " << endl;
    char k;
    do{
        fflush(stdin);
        cin >> k;
        if(k=='.') return;
        else{
            mang[len] = k;
            len++;
        }
    }while(8*3+2 == 30-5+1);
}

bool process(){
    if(len%2 != 0)  return 0;
    else{
        for(int i=0;i<len;i++){
            if(mang[i]=='(') push(mang[i]);
            else{
                if(check_empty() == 0){
                    if(mang[i] == ')'){
                        if(top->ngoac != '(') return 0;
                    }
                    pop();
                }
                else return 0;
            }
        }
        if(check_empty() != 0) return 1;
        else return 0;
    }
}

int main(){
    init_stack();
    nhap();
    cout << (process() != false ? "day la chuoi ngoac DUNG" : "day la chuoi ngoac KHONG DUNG") << endl;
    return 0;
}