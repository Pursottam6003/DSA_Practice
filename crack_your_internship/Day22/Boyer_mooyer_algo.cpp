
// c++ program for bad character heuristic of boyer 
// moore string matching algorithm

#include <bits/stdc++.h>
using namespace std;

#define NO_OF_CHARS 256

void badCharHeuristic(string str,int size,int badChar[NO_OF_CHARS])
{
    int i;

    // initialize all occurences as -1
    for(int i=0;i<NO_OF_CHARS;i++)
    {
        badChar[i]=-1;
    }

    // fill hte actual value of last occurrences

    // of a char 
    for(int i=0;i<size;i++)
    {
        badChar[(int)str[i]] =i;
    }
}
void search(string txt,string pat)
{
    int n = txt.size();
    int m = pat.size();

    // storing bad char 

    int badChar[NO_OF_CHARS];
    // full the bad array by calling te preprocessing funcitno badcharheristic for 
    // given pattern 

    badCharHeuristic(pat,m,badChar);

    int s=0; // s is shift of the pattern wuth respect of text

    while(s <= (n-m))
    {
        int j = m-1;
        // comparing from last 

        // keep reducing index j of pattern while characters of pattern and 
        // texts are matching at this shieft s

        while( j >=0 && pat[j]== txt[s+j])
        {
            j--;
        }

        // if the pattern is preseudt at current shift
        // then index j will become -1 after the above loop

        if(j <0)
        {
            cout<<"pattern occurs at shift " <<s <<endl;
                /* Shift the pattern so that the next
            character in text aligns with the last
            occurrence of it in pattern.
            The condition s+m < n is necessary for
            the case when pattern occurs at the end
            of text */

            s += (s+m < n) ? m - badChar[txt[s+m]] :1;
        }

        else 
        {
            // shfit the pattern so that the bad character
            // in text aligns with the last occurences of it 
            // in pattern . The max function is used to make 
            // sure that we get a positive shift 

            // we may get a negative shift if the last occurances of bad
            // character in pattern is on the right side of curr char

            s += max(1,j-badChar[txt[s+j]]);
        }

    }




}
int main()
{
    string txt = "ABAABCD";
    string pat ="ABC";
    // CALLING THe function 

    search(txt,pat);
    return 0;
}