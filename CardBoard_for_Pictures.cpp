/*

user: Atul Bahuguna
problem link: https://codeforces.com/problemset/problem/1850/E
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


void solve() {

	ll n, c;
	cin >> n >> c;
	vector<ll> arr(n);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}

	ll low = 0, high = 1e9;
	while (low <= high) {
		ll mid = low + (high - low) / 2;
		ll sum = 0;
		for (ll i = 0; i < n; i++) {
			sum += (arr[i] + 2 * mid) * (arr[i] + 2 * mid);
			if (sum > c) {
				break;
			}
		}
		if (sum == c) {
			cout << mid << endl;
			return;
		}
		if (sum > c) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
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