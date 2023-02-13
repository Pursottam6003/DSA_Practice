#include <bits/stdc++.h>
using namespace std;

void search(char pat[], char txt[],int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int d =256; 
    int i,j;
    int p =0 ; //hash value for pattern 
    int t = 0; // hash value for txt 
    int h =1;
    // the value of h would be pow(d,m-1) %q;

    for(i=0;i<M-1;i++)
    {
        h = (h *d)%q;
    }

    // calculate the hash value of pattern and first window of text

    for(i=0;i<M;i++)
    {
        p = (d *p +pat[i])%q;
        t = (d *t + txt[i]) %q;
    }

    // slide the pattern over text one by one 
    for(i =0;i<=N-M;i++)
    {
        // checkk the hash values of current window of text
        // and pattern of the hash valuies match then onlu 
        // check for characters one ny one 

        if(p ==t)
        {
            // check for character one by one 
            for(j =0;j<M;j++)
            {
                if(txt[i+j] != pat[j])
                {
                    break;
                }
            }
        }

        if(j==M)
        {
            cout<<"Pattern found at index "<< i<<endl;
        }

        // calcualte the hash value of next window of text
        // remove the leading digit add trainling digit 

        if(i < N-M)
        {
            t = (d * (t- txt[i] *h) + txt[i+M])%q;

            // we might ge t negative value of t  converting 
            if(t<0) t = t+q;
        }
    }
}

int main()
{
    char txt[] ="GEEKS FOR GEEKS";
    char pat[] = "GEEK";

    // we mod to avoid overflowing of value 
    // but we shoudl take a big q as possible to 
    // avlod collisions

    int q  = INT_MAX;

    // function call 
    search(pat,txt,q);

    return 0;
}