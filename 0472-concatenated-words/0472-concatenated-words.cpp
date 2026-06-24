class Solution {
    //TC : O(n * (l^4) ) -====> on memo O(n*l^3)
public:
    unordered_map<string, bool> mp; //memoization
    bool isConcatenated(string word, unordered_set<string> &us){
        int n = word.length();
        if(mp.count(word)) return mp[word]; 
        for(int i=0;i<n;i++){
            string prefix = word.substr(0,i+1); // TC: substr = (l)
            string suffix = word.substr(i+1);

            if((us.count(prefix) && us.count(suffix)) || (us.count(prefix) && isConcatenated(suffix, us)) ){
                return mp[word] = true;
            }
           
        }
         return mp[word] = false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        mp.clear();
        unordered_set<string> us(begin(words), end(words));
        vector<string> result;
        for(int i=0;i<n;i++){
            string word = words[i];
            if(isConcatenated(word,us)) result.push_back(word);
        }
        return result;
    }
};