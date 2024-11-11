#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        if (sentence[0] != sentence[n - 1]) return false;

        for(int i = 1; i<n; i++){
            if(sentence[i] == ' ' && sentence[i-1] != sentence[i+1])
                return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    string str = "leetcode exercises sound delightful";
    cout<<s.isCircularSentence(str)<<endl; // True
    str = "eetcode";
    cout<<s.isCircularSentence(str)<<endl; //True
    str = "Leetcode is cool";
    cout<<s.isCircularSentence(str)<<endl; // False
}
