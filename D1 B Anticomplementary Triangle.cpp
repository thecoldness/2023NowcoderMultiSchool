#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Max_n = 1e6 + 5;

struct node
{
	ll x , y;
	node(ll a , ll b):x(a),y(b){}
	node(){}
	node operator - (node &a)
	{
		return node(x - a.x , y - a.y);
	}
}a[Max_n];

ll operator * (node a , node b)
{
	return abs(a.x * b.y - a.y * b.x);
}

int read()
{
	int x;
	scanf("%d" , &x);
	return x;
}

int n;

ll calc(int x , int y , int z)
{
	return (a[y] - a[x]) * (a[z] - a[x]);
}

int main()
{
	n = read();
	for(int i = 0 ; i < n ; ++ i)
	{
		int x = read() , y = read();
		a[i] = node(x , y);
	}
	int s = 0 , l = 1 , r = 2;
	while(true)
	{
		bool flag = true;
		while((r + 1) % n != s && calc(s , l , (r + 1) % n) > calc(s , l , r))
			r = (r + 1) % n , flag = false;
		while((r - 1 + n) % n != l && calc(s , l , (r - 1 + n) % n) > calc(s , l , r))
			r = (r - 1 + n) % n , flag = false;
		while((l + 1) % n != r && calc(s , (l + 1) % n , r) > calc(s , l , r))
			l = (l + 1) % n , flag = false;
		while((l - 1 + n) % n != s && calc(s , (l - 1 + n) % n , r) > calc(s , l , r))
			l = (l - 1 + n) % n , flag = false;
		while((s + 1) % n != l && calc((s + 1) % n , l , r) > calc(s , l , r))
			s = (s + 1) % n , flag = false;
		while((s - 1 + n) % n != r && calc((s - 1 + n) % n , l , r) > calc(s , l , r))
			s = (s - 1 + n) % n , flag = false;
		if(flag) break;
	}
	printf("%d %d %d\n" , s + 1 , l + 1 , r + 1);
}
