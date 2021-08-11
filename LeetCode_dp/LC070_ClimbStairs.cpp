# include <iostream>
using namespace std;
#include <vector> 


static int climbStairsRec(int n){
    if ( n == 1 )
    return 1;
    if ( n == 0 )
    return 0;
    if ( n == 2 )
    return 2; 
    return climbStairsRec(n-2) + climbStairsRec(n-1);
}

int static climbStairs(int n){
    if ( n == 1 )
    return 1;
    if ( n == 0 )
    return 0;
    if ( n == 2 )
    return 2; 
    int ln[n+1];
    ln[0] = 0;
    ln[1] = 1;
    ln[2] = 2;
    for( int i = 3 ; i < n+1;i++){
        ln[i] = ln[i-1] + ln[i-2];
    }
    return ln[n];
}
int climbStairsKey(int n) {
    int p = 0, q = 0, r = 1;
    for (int i = 1; i <= n; ++i) {
        p = q; 
        q = r; 
        r = p + q;
    }
    return r;
}

// Matrice
vector<vector<long long> > multiply(vector<vector<long long> > &a, vector<vector<long long> > &b) {
        vector<vector<long long> > c(2, vector<long long>(2));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
    return c;
}

vector<vector<long long> > matrixPow ( vector < vector<long long> > a, int n) {
    vector<vector<long long> > ret(2, vector<long long>(2)) ;
    ret[0][0] = 1;
    ret[0][1] = 0;
    ret[1][0] = 0;
    ret[1][1] = 1;
    while (n > 0) {
        if ((n & 1) == 1) {
           ret = multiply(ret, a);
        }
        n >>= 1;
        a = multiply(a, a);
    }
    return ret;
}
int climbStairsMat(int n) {
        vector<vector<long long> > ret(2, vector<long long>(2)) ;
        ret[0][0] = 1;
        ret[0][1] = 1;
        ret[1][0] = 1;
        ret[1][1] = 0;
        vector<vector<long long> > res = matrixPow(ret, n);
        return res[0][0];
    }

int main(){
    cout << climbStairsRec(8) << endl;
    cout << climbStairs(45) << endl;
    cout << climbStairsMat(45) << endl;
    return 0;
}