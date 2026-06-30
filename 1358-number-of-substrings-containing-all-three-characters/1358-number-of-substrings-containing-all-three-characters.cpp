class Solution {
    // TC: O(n)
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        //Track the last seen index of the char a, b, c\

        int lastA = -1, lastB = -1, lastC = -1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                lastA = i;
            else if (s[i] == 'b')
                lastB = i;
            else if (s[i] == 'c')
                lastC = i;

            if (lastA != -1 && lastB != -1 && lastC != -1) {
                // from the min index of any char to the last will be no of
                // valid substr

                ans += min({lastA, lastB, lastC}) + 1;
            }
        }
        return ans;
    }
};