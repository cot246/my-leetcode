/**
 *Solution 1
 *time:O(n) space:O(1)
 */
 class Solution {
public:
    string addBinary(string a, string b) {
        int lena=a.size(),lenb=b.size();
        if(!lena)return b;
        if(!lenb)return a;
        if(lena<lenb)return addBinary(b,a);
        int inc=0,i=1;
        for(;i<=lenb;++i)
        {
            int ia=a[lena-i]-'0',ib=b[lenb-i]-'0';
            a[lena-i]='0'+(ia+ib+inc)%2;
            inc=(ia+ib+inc)/2;
        }
        while(inc>0&&lena>=i)
        {
            int ia=a[lena-i]-'0';
            a[lena-i]='0'+(ia+inc)%2;
            inc=(ia+inc)/2;
            ++i;
        }
        if(inc>0)
        {
            a.insert(a.begin(),'1');
        }
        return a;
    }
};

/**
 *Solution 2
 *time:O(n) space:O(1)
 */
 class Solution {
public:
    string addBinary(string a, string b) {
        int lena=a.size(),lenb=b.size();
        if(!lena)return b;
        if(!lenb)return a;
        if(lena<lenb)return addBinary(b,a);
        int inc=0;
        for(int i=1;i<=lena;++i)
        {
            const int ia=a[lena-i]-'0';
            const int ib=lenb>=i?b[lenb-i]-'0':0;
            a[lena-i]='0'+(ia+ib+inc)%2;
            inc=(ia+ib+inc)/2;
        }
        if(inc>0)
        {
            a.insert(a.begin(),'1');
        }
        return a;
    }
};
