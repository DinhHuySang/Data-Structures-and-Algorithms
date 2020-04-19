#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
};
typedef node* tro;

void init_list(tro &list){
    list = NULL;
}

void add_last(tro &list, int x){
    node *q = new node;
    q->data = x;
    q->next = NULL;
    if(list == NULL) list = q;
    else {
        node *p = new node;
        p = list;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = q;
    }
}
void nhap_node(tro &list, int &n){
    cout<<"nhap "<<n<<" node vao danh sach" << endl;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        add_last(list,x);
    }
}

void duyet_node(tro &list){
    node *p = list;
    while(p != NULL){
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}
void add_first(tro &list, int x){
    node *q = new node;
    q->data = x;
    q->next = list;
    list = q;

}

void insert_vitri_batki(tro &list, int x, int vitri){
    node *q = new node;
    if(list == NULL){
        q->data = x;
        q->next = NULL;
    }
    else{
        q->data = x;
        node *p = list;
        int i=0;
        while(p != NULL){
            if(i==vitri-1){
                break;
            }
            p = p->next;
            i++;
        }
        q->next = p->next;
        p->next = q;
    }
}
int len(tro &list){
    node*p = list;
    int i=0;
    while (p != NULL)
    {
        i++;
        p = p->next;
    }
    return i;
}
void Xoa_node(tro &list, int vitri){
    node* p = list;
    if(vitri == 0){
        list = list->next;
        return;
    }
    else if(vitri ==len(list)-1){
        node *p = list;
        while (p->next->next!=NULL)
        {
            p=p->next;
        }
        p->next = p->next->next;
        return;
    }
    else{
        int i=0;
        while (i!=vitri-1)
        {
            p=p->next;
            i++;
        }
        p->next = p->next->next;
        return;

    }

}
int main(){
    tro list;
    cout << "nhap so luong node = ";
    int n; cin >> n;
    init_list(list);
    nhap_node(list,n);
    duyet_node(list);
    int f;
    cout << "nhap node can them vao dau list = "; cin >> f;
    add_first(list,f);
    duyet_node(list);
    int k, vitri;
    cout << "nhap so can chen = "; cin >> k;
    cout << "nhap vi tri can chen = "; cin >> vitri;
    insert_vitri_batki(list,k,vitri);
    duyet_node(list);
    cout << "nhap vi tri can xoa = "; cin >> vitri;
    Xoa_node(list,vitri);
    duyet_node(list);

    return 0;
}