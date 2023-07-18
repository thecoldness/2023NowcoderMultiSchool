#include <bits/stdc++.h>
using namespace std;

int read()
{
	int x;
	scanf("%d" , &x);
	return x;
}

const int Max_n = 1e5 + 5;

int n , a[3][Max_n] , f[3][Max_n] , ta[Max_n] , tb[Max_n] , Q , q[Max_n][3];
int len[3] , p[3][Max_n];

typedef long long ll;

ll ans[Max_n];

ll C[5], M[5], x, y;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {x = 1, y = 0; return a;}
    ll r = exgcd(b, a % b, x, y), tmp;
    tmp = x; x = y; y = tmp - (a / b) * y;
    return r;
}
ll inv(ll a, ll b) {
    ll r = exgcd(a, b, x, y);
    while (x < 0) x += b;
    return x;
}

ll excrt()
{
	bool flag = true;
	for(int i = 2 ; i <= 3 ; ++ i)
	{
		ll M1 = M[i - 1], M2 = M[i], C2 = C[i], C1 = C[i - 1], T = gcd(M1, M2);
	    if ((C2 - C1) % T != 0) {flag = 0; break;}
	    M[i] = (M1 * M2) / T;
	    C[i] = ( inv( M1 / T , M2 / T ) * (C2 - C1) / T ) % (M2 / T) * M1 + C1;
	    C[i] = (C[i] % M[i] + M[i]) % M[i];
	}
	return flag ? C[3] : 1e18;
}

int main()
{
	n = read();
	for(int i = 0 ; i < 3 ; ++ i)
		for(int j = 1 ; j <= n ; ++ j)
			a[i][j] = f[i][j] = read();
	for(int i = 0 ; i < 3 ; ++ i)
		for(int j = 1 ; j <= 2 ; ++ j)
		{
			for(int k = 1 ; k <= n ; ++ k)
				ta[k] = f[i][k] , tb[k] = a[(i + j) % 3][k];
			for(int k = 1 ; k <= n ; ++ k)
				f[i][k] = ta[tb[k]];
		}
	Q = read();
	for(int i = 1 ; i <= Q ; ++ i)
		ans[i] = 1e18;
	for(int i = 1 ; i <= Q ; ++ i)
		q[i][0] = read() , q[i][1] = read() , q[i][2] = read();
	int nw[3] = {1 , 1 , 1};
	for(int use = 0 ; use < 3 ; ++ use)
	{
		for(int t = 0 ; t < 3 ; ++ t)
		{
			for(int i = 1 ; i <= n ; ++ i)
				p[t][i] = -1;
			int bg = nw[t] , step = 0;
			p[t][bg] = 0;
			nw[t] = f[t][nw[t]] , ++ step;
			while(nw[t] != bg)
			{
				p[t][nw[t]] = step;
				nw[t] = f[t][nw[t]] , ++ step;
			}
			len[t] = step;
		}
		for(int id = 1 ; id <= Q ; ++ id)
			if(p[0][q[id][0]] >= 0 && p[1][q[id][1]] >= 0 && p[2][q[id][2]] >= 0)
			{
				C[1] = p[0][q[id][0]] , M[1] = len[0];
				C[2] = p[1][q[id][1]] , M[2] = len[1];
				C[3] = p[2][q[id][2]] , M[3] = len[2];
				ans[id] = min(ans[id] , excrt() * 3 + use);
			}
		int nw0 = nw[0] , nw1 = nw[1] , nw2 = nw[2];
		nw[0] = a[0][nw1] , nw[1] = a[1][nw2] , nw[2] = a[2][nw0];
	}
	for(int i = 1 ; i <= Q ; ++ i)
		printf("%lld\n" , (ans[i] == 1e18 ? -1 : ans[i]));
}
