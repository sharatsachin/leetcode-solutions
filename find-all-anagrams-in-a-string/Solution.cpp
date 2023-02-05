// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int q[26] = {0};
        int r[20105][26] = {{0}};
        vector<int> v;
        for(char x : p){
            q[x-'a']++;
        }

        for(int i=1; i<=s.length(); i++){
            for(int j=0;j<26;j++){
                r[i][j] = r[i-1][j] + ((s[i-1]-'a')==j);
            }
        }

        for(int i=0; i+p.length()<=s.length(); i++){
            bool k = true;
            for(int j=0;j<26;j++){
                if (r[i+p.length()][j] - r[i][j] != q[j]) k = false;
            }
            if(k == true) v.push_back(i);
        }
        return v;
    }
};