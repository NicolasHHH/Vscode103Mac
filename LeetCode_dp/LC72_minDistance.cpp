# include <iostream>
using namespace std;
#include <vector> 

int minDistance(string word1, string word2) {
    int len1 = word1.size();
    int len2 = word2.size();
    if (len1 == 0) return len2;
    if (len2 == 0) return len1;

    int dp[len1][len2];
    int meme1 = 0;
    int meme2 = 0;
    if (word1[0] == word2[0]){
        dp[0][0] = 0;
        meme1 = 1;
        meme2 = 1;
    }
    else{
        dp[0][0] = 1;
    }
    for(int i = 1; i < len1; i++){
        if(word1[i] == word2[0] && meme1 == 0){
            meme1 = 1;
            dp[i][0] = dp[i-1][0];
        }
        else{
            dp[i][0] = dp[i-1][0]+1;
        }
    }
    for(int j = 1; j < len2; j++){
        if(word1[0] == word2[j] && meme2 == 0){
            meme2 = 1;
            dp[0][j] = dp[0][j-1];
        }
        else{
            dp[0][j] = dp[0][j-1]+1;
        }
    }
    int adddel;
    int subs;
    for(int i = 1; i < len1; i++){
        for(int j = 1; j < len2; j++){
            adddel = min(dp[i][j-1],dp[i-1][j])+1;
            if (word1[i] == word2[j]){
                subs = dp[i-1][j-1];
            }
            else subs = dp[i-1][j-1]+1;
            dp[i][j] = min(adddel,subs);
        }
    }
    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            cout<< dp[i][j]<<" ";
        }
        cout <<endl;
    }
    cout<< endl;
    return dp[len1-1][len2-1];
}

int main(){
    string word1 = "arrrr";
    string word2 = "ar";
    
    cout << minDistance(word1,word2);
}