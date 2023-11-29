// TC: O(n)
// MC: O(1)
class Solution {
public:
    int romanToInt(string s) {
        int v = 0;
        vector<int> roman(128);
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        for(int i=0;i<s.size()-1;i++) {
            if (roman[s[i]] < roman[s[i + 1]]) {
                v -= roman[s[i]];
            } else {
                v+= roman[s[i]];
            }
        }
        return v + roman[s.back()];
    }
};