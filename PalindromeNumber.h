/**
 *Solution 1
 *time:O(1) space:O(1)
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int div=1;
        while(x/div>=10)div*=10;
        while(x>0)
        {
            if(x/div!=x%10)return false;
            else
            {
                x=x%div/10;
                div/=100;
            }
        }
        return true;
    }
};

/**
 *Solution 2
 *time:O(1) space:O(1)
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        string s1(to_string(x)),s2(s1.rbegin(),s1.rend());
        return s1==s2;
    }
};
