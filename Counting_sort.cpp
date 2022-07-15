#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define REP(n) for (int i=0; i<n; i++)
#define INF 1e9




ll getHP(ll n);
ll power(ll u, ll v);
ll sumChiff(ll n);
int* revArr(int arr[], int l);
string tolow(string s);




int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    // freopen("input.txt", "r", stdin);
    int arr[] = {2,1,10,11,8,3,6,4,1,8};
    int ln = sizeof(arr)/4; // 4 == sizeof(int)
    int mx = 0, mn = INF;
    for (int i=0; i<ln; i++) mx = max(mx, arr[i]);
    for (int i=0; i<ln; i++) mn = min(mn, arr[i]);
    int diff = mx-mn+1;
    int occ_arr[diff] = {0};
    for (int i=0; i<ln; i++) occ_arr[arr[i]-1]++;
    printf("[+] Occ Array");
    for (int i=0; i<diff; i++) printf("%i\n", occ_arr[i]);
    vector<int> sorted_arr;
    for (int i=0; i<diff; i++){
        int occ = occ_arr[i];
        if (occ > 0){
            for (int k=0; k<occ; k++) sorted_arr.push_back(mn+i);
        }
    }
    printf("[+] Sorted Array \n");
    for (int i=0; i<ln; i++){
        printf("%i\n", sorted_arr[i]);
    }
    // freopen("output.txt", "w", stdout);
	return 0;
}








ll mul(ll u , ll v)
{
    return u*v;
}






ll power(ll u, ll v)
{
    if(u==0)
        return 0;
    ll ans=1;
    ll acc=u;
    while(v)
	{
        if(v%2)
		{
            ans=mul(ans,acc);
        }
        acc = mul(acc,acc);
        v/=2;
    }
    return ans;
}


ll getHP(ll n)
{
	ll i=1;
	while (1)
	{
		if (!(n / power(10, i)))
			return i-1; // n==0 if i++ --> i--
		i++;
	}
}



ll sumChiff(ll n)
{
	ll s = 0;
	while (1)
	{
		if (!n){return s;}
		s += n%10;
		n /= 10;
	}
}






int* revArr(int arr[], int l)
{
    int* tab = (int *) malloc(sizeof(int)*l);
    for (int i=0; i<l; i++)
    {
        tab[i]=arr[l-1-i];
    }
    return tab;
}



string tolow(string s){
    string ls = "";
    const int l = s.length();
    for (int i=0; i<l; i++){
        ls += tolower(s[i]);
    }
    return ls;
}