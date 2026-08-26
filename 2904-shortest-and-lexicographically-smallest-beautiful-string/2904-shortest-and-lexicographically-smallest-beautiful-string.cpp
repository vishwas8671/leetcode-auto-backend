class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l=0,cnt=0,best=INT_MAX;
        string ans="";
        for(int r=0;r<s.size();r++){
            cnt+=s[r]=='1';
            while(cnt>k) cnt-=s[l++]=='1';
            if(cnt==k){
                while(s[l]=='0') l++;
                string cur=s.substr(l,r-l+1);
                if(cur.size()<best||(cur.size()==best&&cur<ans)){
                    best=cur.size();
                    ans=cur;
                }
            }
        }
        return ans;
    }
};