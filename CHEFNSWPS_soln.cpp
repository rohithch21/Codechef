#include<bits/stdc++.h>
#define int      long long int
#define nitro    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define pb       push_back
#define pi       3.1415926535897932384626
#define mod      1000000007
#define endl     '\n'
#define DEBUG    false
#define F        first
#define S        second
#pragma GCC optimize "trapv"

using namespace std;

/* 
Make a map for all elements in A and B vector - mp;
find min in all of the vector A and B - mini
Make another map with keys same mp and values half of mp - halfmp.
now iterate through the temp = halfmp to find temp[A[i]] - if not present add to vector vec1 else reduce number of values by 1
now iterate through the temp2 = halfmp to find temp2[B[i]] - if not present add to vector vec2 else reduce number of values by 1
sort vec1 in ascending and vec2 in descending.
iterate through vec1 and vec  
ans = ans + min(2*mini,min(vec1[i],vec[i]))
Solutiion below is efficient in time and space.
*/

void printVector(vector<int> &vec){
    for(int i = 0; i< vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

void printMap(map<int,int> m){
    cout << " { ";
    for(auto i : m){
        cout << i.first << " : " << i.second << " , ";
    }
    cout << " }\n";
}

signed main()
{
 nitro;
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 int t;
 cin>>t;
 while(t--)
 {
     int n;
     cin>>n;
     vector<int> a(n),b(n);
     std::map<int, int> m1,m2,m3,m4,m5;
     for(int i=0;i<n;i++){
     cin>>a[i];
     m1[a[i]]++;
     m3[a[i]]++;
     }
     cout << "m1 = ";
     printMap(m1);
     cout << "m3 = ";
     printMap(m3);

     for(int i=0;i<n;i++){
     cin>>b[i];
     m2[b[i]]++;
     m3[b[i]]++;
     }
     cout << "m2 = ";
     printMap(m2);
     cout << "m3 = ";
     printMap(m3);

     int f=0;
     for(auto i:m3)
     {
         if(i.S%2!=0)
         {
             f=1;
             break;
         }
     }
     cout << "f = " << f << endl ;

     int ta[n],tb[n];
     for(int i=0;i<n;i++)
     ta[i]=a[i];
     for(int i=0;i<n;i++)
     tb[i]=b[i];
     sort(ta,ta+n);
     sort(tb,tb+n);
     int p=0;
     for(int i=0;i<n;i++)
     {
         if(ta[i]!=tb[i])
         {
             p=1;
             break;
         }
     }
     if(p==0)
     cout<<0<<endl;
     else if(f==1)
     cout<<-1<<endl;
     else
     {
     	int ans=0;
     	int m=INT_MAX;
     	for(int i=0;i<n;i++)
     	m=min(m,a[i]);
        cout << "m = " << m << endl;
     	for(int i=0;i<n;i++)
     	m=min(m,b[i]);
         cout << "m = " << m << endl;
        for(auto i:m1)
        {
            if(i.S>m2[i.F])
            m4[i.F]=(i.S-m2[i.F])/2;
        }
        cout << "m4 = ";
        printMap(m4);
        for(auto i:m2)
        {
            if(i.S>m1[i.F])
            m5[i.F]=(i.S-m1[i.F])/2;
        }
        cout << "m5 = ";
        printMap(m5);
        std::vector<int> v1,v2;
        for(auto i:m4)
        {
            for(int j=0;j<i.S;j++)
            v1.pb(i.F);
        }
        for(auto i:m5)
        {
            for(int j=0;j<i.S;j++)
            v2.pb(i.F);
        }

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end(),greater<int>());
        cout << "v1 = ";
        printVector(v1);
        cout << "v2 (descending) = ";
        printVector(v2);
        for(int i=0;i<v1.size();i++)
        {
        	int k1=v1[i];
        	int k2=v2[i];
        	ans+=min(2*m,(min(k1,k2)));
        }
        cout<<ans<<endl;
     }
 }
 return 0;
}
	 