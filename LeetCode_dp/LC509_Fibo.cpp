#include <iostream>
using namespace std;

int FiboRec(int n){
    if ( n == 0)
    return 0;
    if (n==1)
    return 1;
    return FiboRec(n-1)+FiboRec(n-2);
}

int main(){

    for (int n = 0;n<10;n++){
       cout << FiboRec(n) << endl; 
    }
    return 0;
}