class Solution {
    //Approach 1: Brute Force
    //TC: n^2 
    //SC : n
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = word.size();
        unordered_set<string> s;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int size = j-i+1;
                s.insert(word.substr(i,size));
            }
        }
        int c = 0;
        for(string &p:patterns){
            if(s.count(p))c++;
        }
        return c;
    }
};