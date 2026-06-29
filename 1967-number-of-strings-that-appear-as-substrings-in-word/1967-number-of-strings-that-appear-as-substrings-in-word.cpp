class Solution {
    //Better approach 
    //O(N*M*K)
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for(string &p:patterns){
            if(word.find(p)!=string::npos) cnt++; //TC: (M*K)
        }
        return cnt;
    }
};