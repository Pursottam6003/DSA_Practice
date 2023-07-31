// https://www.codingninjas.com/studio/problems/l-to-r-xor_8160412?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
int calculateXOR(int n)
{

    if (n % 4 == 0)
        return n;

    if (n % 4 == 1)
        return 1;

    if (n % 4 == 2)
        return n + 1;

    if (n % 4 == 3)
        return 0;
}

int findXOR(int L, int R)
{

    return calculateXOR(R) ^ calculateXOR(L - 1);
}