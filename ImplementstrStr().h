/**
 *Solution 1
 *time:O(n*m) space:O(1)
 *暴力法
 */
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int n=strlen(haystack),m=strlen(needle);
        for(int i=0;i<=n-m;++i)
        {
            int j;
            for(j=0;j<m;++j)
            {
                if(*(haystack+i+j)!=*(needle+j))break;
            }
            if(j==m)return haystack+i;
        }
        return nullptr;
    }
};

/**
 *Solution 2
 *time:O(n+m) space:O(m)
 *KMP
 */
clas
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int ind=kmp(haystack,needle);
        if(ind==-1)return nullptr;
        else return haystack+ind;
    }
private:
    int kmp(char *str,char *pattern)
    {
        int n=strlen(str),m=strlen(pattern);
        if(m==0)return 0;
        vector<int> pi(m,-1);
        for(int i=-1,j=1;j<m;++j)
        {
            while(i>-1&&*(pattern+j)!=*(pattern+i+1))i=pi[i];
            if(*(pattern+j)==*(pattern+i+1))++i;
            pi[j]=i;
        }
        for(int i=-1,j=0;j<n;++j)
        {
            while(i>-1&&*(pattern+i+1)!=*(str+j))i=pi[i];
            if(*(pattern+i+1)==*(str+j))++i;
            if(i==m-1)return j-i;
        }
        return -1;
    }
};
