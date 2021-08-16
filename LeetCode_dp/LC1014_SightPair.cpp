# include <iostream>
using namespace std;
#include <vector> 

int time_maxScoreSightseeingPair(vector<int>& values) {
    int len = values.size();
    int maxRang = 0;
    int score = 0;

    for (int i = 0; i< len; i++){
        score = 0;
        int current = values[i];
        for (int j = i+1;j<len;j++){
            score = max (score,values[j]+current + i - j);
        }
        maxRang = max(maxRang,score);
    }

    return maxRang;
}

int calcul(int i, int j,vector<int>& values){
    return values[i]+values[j]+i-j;
}
int maxScoreSightseeingPair(vector<int>& values) {
    int len = values.size();
    int maxRang = 0;
    int score = 0;
    int depart = 0;

    for (int i = 1; i< len; i++){
        score = 0;
        int diff = calcul(depart,i,values);
        int voisin = calcul(i-1,i,values);
        if (diff < voisin){
            depart = i-1;
            score = voisin;
        }
        else score = diff;
        maxRang = max(maxRang,score);
    }
    return maxRang;
}

int main(){
    int n = 15;
    int b[] = {402,224,922,720,323,714,129,303,556,532,925,824,466,169,725};
    vector<int> a(n);
    for (int i=0; i<n;i++){
        a[i] = b[i];
    }
    int res = maxScoreSightseeingPair(a);
    cout << endl;
    cout <<res;
}