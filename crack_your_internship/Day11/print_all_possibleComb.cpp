void subsets(string ip , string op , vector<string>&v)
{
    if(ip.size() == 1)
    {
        op += ip[0];
        v.push_back(op);
        return;
    }
    subsets(ip.substr(1) , op+ip[0] , v);
    subsets(ip.substr(1) , op+ip[0]+" " , v);
}

vector<string>spaceString(char str[])
{
    vector<string>v;
    subsets(str,"",v);
    return v;
}