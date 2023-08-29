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


void solve() {

	ll n; cin >> n;
	deque<ll>q;
	string s = "";
	vi arr(n);
	rep(i, 0, n)cin >> arr[i];

	bool flag = false;
	vi nice;
	for (ll i = 0; i < n; i++) {
		if (nice.size() == 0) {
			s += '1';
			nice.push_back(arr[0]);
			continue;
		}

		if (arr[i] >= nice.back() && !flag) {
			nice.push_back(arr[i]);
			s += '1';
		}
		else if (!flag && arr[i] <= nice.front()) {
			nice.push_back(arr[i]);
			flag = true;
			s += '1';
		}
		else if (flag && arr[i] >= nice.back() && arr[i] <= nice.front()) {
			s += '1';
			nice.push_back(arr[i]);
		} else {
			s += '0';
		}

	}
	cout << s << endl;
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