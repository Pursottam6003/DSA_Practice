class Solution {
public:
    /*
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            for (; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
        }
        return -1;
    }
    */
    // Advance algorithm rabin karp  approach 

    int hashValue(string str,int RADIX,int MOD,int m)
    {
        int ans=0;
        long factor =1;

        for(int i=m-1;i >=0;i--)
        {
            ans += ((int) (str[i]-'a')*factor) % MOD;
            // updating the factor as by multiple of radix power
            factor = (factor * RADIX) % MOD;
        }
        return ans % MOD;
    }
    int strStr(string haystack,string needle)
    {
        int m = needle.size();
        int n = haystack.size(); 

        if(n<m) return -1;

        //constant variables
        int RADIX = 26;
        int MOD = 1000000033;

        long max_weight = 1;

        for(int i=0;i<m;i++)
        {
            max_weight= (max_weight *RADIX) % MOD;
        }

        // compute the hash of needles
        long hashNeedle = hashValue (needle,RADIX,MOD,m);
        long hashHay =0;

        // check for each m - strubstring of haystack stariting at index windowstart
        for(int windowStart =0;windowStart <= n-m;windowStart++)
        {
            // for first time 
            if(windowStart ==0){
                // compute hash of first subtring 
                hashHay = hashValue(haystack,RADIX,MOD,m);
            }

            else {
                // update hash using previous hash value in O(1)
                hashHay = ((hashHay *RADIX) % MOD - ((int)
                (haystack[windowStart-1]-'a')* max_weight )% MOD + 
                (int)(haystack[windowStart+m -1]-'a') +MOD ) % MOD;
            }

            // if the hash matches , then check by character by character 

            if(hashNeedle == hashHay)
            {
                for(int i=0;i<m;i++)
                {
                    if(needle[i] != haystack[i+windowStart])
                    {
                        break;
                    }

                    if(i ==m-1)
                    {
                        return windowStart;
                    }
                }
            }
        }
        return -1;


    }

};