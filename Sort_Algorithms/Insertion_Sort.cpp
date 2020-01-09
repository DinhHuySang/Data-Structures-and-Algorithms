#include <bits/stdc++.h>
using namespace std;

void input_data(float *array_a, int numbers_of_element){
    for(int i=0; i<numbers_of_element; i++) cin >> array_a[i];
}

void output_data(float *array_a, int numbers_of_element){
    for(int i=0; i<numbers_of_element; i++) cout << array_a[i] << ' ';
    cout << endl;
}
void Swap(float &a, float &b){
    float temp = a;
    a = b;
    b = temp;
}

void Insert_Sort(float *a, int n){
    for(int i=1; i<n; i++){
        float temp = a[i];
        int j = i-1;
        while(j>-1 && temp<=a[j]){
            a[j+1] = a[j];
            j -= 1;
        }
        a[j+1] = temp;
    }
}

int main(){
    int n; cin >> n;
    float *Array = new float(n+1);
    input_data(Array, n);
    Insert_Sort(Array, n);
    output_data(Array, n);
    delete[]Array;
    return 0;
}
