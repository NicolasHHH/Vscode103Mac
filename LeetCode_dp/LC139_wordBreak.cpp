
# include <iostream>
using namespace std;
# include <vector> 
# include <string>
# include <unordered_set>

//hard 

bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set <string> ();
        for (auto word: wordDict) {
            wordDictSet.insert(word);
        }

        auto dp = vector <bool> (s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }


int main(){
    string s = "pineapple";
    vector<string> dic(2);
    dic[0] = "pine" ;
    dic[1] = "pineapple" ;
    cout << endl<<wordBreak(s,dic)<<endl;
}