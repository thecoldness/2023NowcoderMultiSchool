#include <bits/stdc++.h>
using namespace std;

int read()
{
	int x;
	scanf("%d" , &x);
	return x;
}

int A , B , all , g;

typedef long long ll;

int exgcd(int a , int b , ll &x , ll &y)
{
	if(!b) return x = 1 , y = 0 , a;
	int d = exgcd(b , a % b , x , y) , t = x;
	return x = y , y = t - a / b * y , d;
}

ll aabs(ll x)
{
	return x >= 0 ? x : -x;
}

void solve()
{
	A = read() , B = read() , all = read();
	g = __gcd(A , B);
	if(all % g) return puts("-1") , void();
	ll x , y;
	exgcd(A / g , B / g , x , y);
	x *= all / g , y *= all / g;
	int a = A / g , b = B / g;
	// printf("a = %d , b = %d\n" , a , b);
	ll k = (x - (x % b)) / b;
	x = x % b , y = y + k * a;
	ll ans = 1e18;
    auto work = [&](ll r , ll s) {
        if (r >= 0 && s >= 0) ans = min(ans, 2 * (r + s));
        else ans = min(ans, 2 * (abs(r) + abs(s)) - 1);
    };
	work(x + b , y - a) , work(x , y) , work(x - b , y + a);
	k = (y - (y % a)) / a;
	y = y % a , x = x + k * b;
	work(x + b , y - a) , work(x , y) , work(x - b , y + a);
	printf("%lld\n" , ans);
}

int main()
{
	for(int _ = read() ; _ ; -- _)
		solve();
}
