class Solution {
    public:
        int firstUniqChar(string s) {
            int l = s.length();
            unordered_map<char,int> table;
            for(char c : s)
            {
                table[c]++;
            }
            for(int i=0; i<l; i++)
            {
                if(table[s[i]] == 1)
                {
                    return i;
                }
            }
            return -1;
        }
    };
