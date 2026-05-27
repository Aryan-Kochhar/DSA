class Solution {
public:
bool check(string haystack, string needle,int start)
{
    int i=1;
    int j=start+1;
    while(i<needle.length()&&j<haystack.length())
    {
        if(haystack[j]!=needle[i])
        {
            return false;
        }
        i++;
        j++;
    }
    if(j>=haystack.length()&&i<needle.length())
    {
        return false;
    }
    return true;
}
    int strStr(string haystack, string needle) {
        if(haystack.length()<needle.length())
        {
            return -1;
        }
        int i=0;
        int j=0;
        for(int i=0;i<haystack.length();i++)
        {
            if(haystack[i]==needle[0])
            {
                bool found=check(haystack,needle,i);
                if(found==true)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};