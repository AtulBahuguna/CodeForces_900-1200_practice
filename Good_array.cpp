/*

user: Atul Bahuguna

*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i,st,en) for(ll i=st;i<en;i++)
#define F first
#define S second
#define vi vector<ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

/*****************************GCD function***********************/

int gcd(int a, int b) {

	if (a == 0) {
		return b;
	}

	// make sure always pass abs(a) and abs(b);

	return gcd(b, a % b);
}


ll power(ll base, ll n) {
	ll res = 1;
	while (n) {
		if (n % 2 == 1) {
			res = res * base;
			n--;
		}
		base = base * base;
		n /= 2;
	}

	return res;
}

bool is_prime[10000001];

void sieve() {

	ll maxN = 10000000;

	for (ll i = 1; i <= maxN; i++) {
		is_prime[i] = true;
	}
	is_prime[0] = is_prime[1] = false;

	for (ll i = 2; i * i <= maxN; i++) {
		if (is_prime[i]) {
			for (ll j = i * i; j <= maxN; j += i) {
				is_prime[j] = false;
			}
		}
	}


}


/*******************************Main function Program*******************/

bool valid(string s) {
	int cnt = 0;
	for (auto it : s) {
		if (it == '(') {
			cnt++;
		} else {
			if (cnt <= 0) {
				return false;
			}
			cnt--;
		}
	}
	return (cnt == 0);
}
// vector<string>nice;
void recursion(string s, int n, vector<string>&nice) {
	if (s.size() == 2 * n) {
		if (valid(s)) {
			nice.push_back(s);;
		}
		return;

	}
	string open = s + '(';
	recursion(open, n, nice);
	string closed = s + ')';
	recursion(closed, n, nice);
	// return s;
}

void solve() {

	string s;
	cin >> s;
	int len = s.length();
	if (valid(s)) {
		cout << "NO" << endl;
		return;
	} else {
		cout << "YES" << endl;
		vector<string>nice;
		recursion("", len, nice);
		cout << nice[0] << endl;
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

	ios::sync_with_stdio(false); cin.tie(NULL);
	sieve();
	ll T;
	cin >> T;
	while (T--) {
		solve();

	}
	return 0;
}