class Solution {
    //Easy but discussion must be in the interview
public:
    bool checkFreq(string s){
        int arr[26];
        for(char &ch:s){
            int i = ch -'a';
            arr[i]++;
            if(arr[i]>1) return true;
        }
        return false;
    }
    bool buddyStrings(string s, string goal) {
        
        if(s.length() != goal.length()) return false;

        vector<int> index;

        if(s==goal){
            return checkFreq(s); //if any char appears twice then it can be possible to swap 1
        }

        for(int i=0;i<s.length();i++){
            if(s[i]!=goal[i]){
                index.push_back(i);
            }
            
        }
        if(index.size()!=2) return false;

        swap(s[index[0]],s[index[1]]);
        return s == goal;
    }
};