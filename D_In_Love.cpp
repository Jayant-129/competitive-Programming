    #include<bits/stdc++.h>
    int main()
    {
        std::multiset<int>a,b;
        char c[2];
        int l,r;
        for(scanf("%*d");~scanf("%s%d%d",c,&l,&r);
        puts(a.size()&&*a.rbegin()>*b.begin()?"YES":"NO"))
        if(*c&4)
        a.erase(a.find(l)),b.erase(b.find(r));
        else a.insert(l),b.insert(r);
    }