// problem link: https://leetcode.com/problems/longest-common-prefix/

// NAIVE SOLUTION
// idea: compare first pair of strings and compare longest prefix of them with the rest 
// time complexity: O (n*(sum of strings.size()))
// space complexity: O(prefix.size())


// BETTER SOLUTION WITH SORTING
// idea: sort strings first, so that we only need to compare the first string with the last one 
// time complexity: O(log(n) + min(str[0).size(), str[n-1].size()))
// space complexity: O(prefix.size()) 

class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans="";
        sort(v.begin(),v.end());
        int n=v.size();
        string first=v[0],last=v[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }
        return ans;
    }
};
