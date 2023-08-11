// https://www.codingninjas.com/studio/problems/counting-graphs_8357237?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
int countingGraphs(int N)
{
    // W    rite your code here.
    int n = 1;
    if (N >= 1)
    {
        n = (N * (N + 1)) / 2 - N;
    }

    int res = pow(2, n);
    return res;
}