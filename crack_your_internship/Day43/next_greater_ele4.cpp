    
    /*
    Explanation
Use two stack s1 and s2.
Similar to "Next Greater Element"
s1 stores the index of elements
that have not found their first greater element.

s2 stores the index of elements
that have found their first greater element,
have not found their second greater element.

For each a = A[i] in A
We first compare the a with the tail elements in s2,
pop all element smaller than a,
because a is their second greater element.

Then we compare the a with the tail elements in s1,
move all elements smaller than a to the tail of s2,
because a is their first greater element.

We repeatly do this for all A[i] and finally return the result.
    */
    vector<int> secondGreaterElement(vector<int>& A) {
        int n = A.size();
        vector<int> res(n, -1), s1, s2, tmp;
        for (int i = 0 ;i < n; ++i) {
            while (!s2.empty() && A[s2.back()] < A[i])
                res[s2.back()] = A[i], s2.pop_back();
            while (!s1.empty() && A[s1.back()] < A[i])
                tmp.push_back(s1.back()), s1.pop_back();
            while (!tmp.empty())
                s2.push_back(tmp.back()), tmp.pop_back();
            s1.push_back(i);
        }
        return res;
    }