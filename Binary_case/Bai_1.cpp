#include <iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node * right;
};
typedef node* tree;

void init_tree(tree &t){
    t = NULL;
}

void insert(tree &t, int x){
    if(t == NULL){
        node *p = new node;
        p->data = x;
        p->left = p->right = NULL;
        t = p;
    }
    else{
        if(t->data > x){
            insert(t->left,x);
        }
        else if(t->data < x){
            insert(t->right,x);
        }
    }
}

void creat_tree(tree &t, int num_of_elements){

	init_tree(t);
    cout << "nhap du lieu vao cay" << endl;

	for(int i=0; i<num_of_elements; i++){
        int x; cin >> x;
        insert(t,x);
    }
}

tree search(tree t, int x){
    if(t==NULL) return NULL;
    else{

        if(x < t->data) search(t->left,x);
        else if(x > t->data) search(t->right,x);
        else return t;
    }
}

void TimPhanTuTheMangTraiNhatChoCayConPhai(tree &p, tree &q){
    if(q->left != NULL) TimPhanTuTheMangTraiNhatChoCayConPhai(p,q->left);
    else{
        p->data = q->data;
        p = q;
        q = q->right;
    }
}

void TimPhanTuTheMangPhaiNhatChoCayConTrai(tree &p, tree &q){
    if(q->right != NULL) TimPhanTuTheMangPhaiNhatChoCayConTrai(p,q->right);
    else{
        p->data = q->data;
        p = q;
        q = q->left;
    }
}

void Del(tree &t, int x){
    if(t==NULL){
        cout << "co nut nao dau ma xoa";
        return;
    }
    else{

        if(t->data > x)  Del(t->left,x);
        else if(t->data < x)  Del(t->right,x);
        else {

            node *p = t;
            if(t->left == NULL) t = t->right;
            else if(t->right == NULL) t = t->left;
            else{
                TimPhanTuTheMangPhaiNhatChoCayConTrai(p,t->left);
            }
            delete p;
        }
    }

}

void add(tree &t, int x){
    if(t==NULL){
        node *p = new node;
        p->data = x;
        p->left = p->right = NULL;
        t = p;
    }
    else{
        if(t->data > x) add(t->left,x);
        else if(t->data < x) add(t->right,x);
        else{

            if(t->left == NULL){
                t->data = x;
                t = t->right;
            }
            else if(t->right == NULL){
                t->data = x;
                t = t->left;
            }

        }

    }
}

void Top_Down_Left_Right(tree t){
    if(t != NULL){
        cout << t->data << "  ";
        Top_Down_Left_Right(t->left);
        Top_Down_Left_Right(t->right);
    }
}
int main(){
    int num_of_elements;
    cout << "nhap so node trong cay = "; cin >> num_of_elements;
    tree t;
    creat_tree(t,num_of_elements);
    cout << "duyet cay: " << endl;
    Top_Down_Left_Right(t);

    int x;
    cout << "nhap Node can tim  = "; cin >> x;
    cout << endl;
    node *s = search(t,x);
    if(s == NULL) cout << "khong tim thay node" << endl;
    else cout << "co node can tim trong cay " << endl;

    int de;
    cout << "nhap node can xoa "; cin >> de;
    Del(t,de);
    cout << endl << "sau khi xoa" <<  endl;
    Top_Down_Left_Right(t);


    sang : int ele;
    cout << "nhap phan tu can them = "; cin >> ele;
    add(t,ele);
    cout << "sau khi them" << endl;
    Top_Down_Left_Right(t);
    goto sang;
        system("pause");
    return 0;
}