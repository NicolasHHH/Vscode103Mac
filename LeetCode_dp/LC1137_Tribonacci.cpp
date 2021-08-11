#include <iostream>
using namespace std;

int Tribo(int n){
    if ( n == 0)
    return 0;
    if (n==1)
    return 1;
    if ( n == 2)
    return 1;
    int a = 0 , b= 1, c=1;
    for (int i = 0; i<n-2;i++){
        
        int d = c;
        c = a + b + d;
        a = b;
        b = d;
    }
    return c;
    
}

int main(){

    for (int n = 0;n<26;n++){ 
        cout << Tribo(n) << endl;
    }
    return 0;
}