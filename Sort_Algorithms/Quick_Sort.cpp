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

void Quick_Sort(float *Array, int low, int high){
    int left = low; int right = high;
    int mid = (left+right)/2;
    while(left <= right){
        while(Array[left] < Array[mid]) left++;
        while(Array[mid] < Array[right]) right--;

        if(left <= right){
            Swap(Array[left], Array[right]);
            left++;
            right--;
        }
    }
    if(low < right) Quick_Sort(Array, low, right);
    if(left < high) Quick_Sort(Array, left, high);
}

int main(){
    int n; cin >> n;
    float *Array = new float(n+1);
    input_data(Array, n);
    Quick_Sort(Array, 0, n-1);
    output_data(Array, n);
    delete[]Array;
    return 0;
}
