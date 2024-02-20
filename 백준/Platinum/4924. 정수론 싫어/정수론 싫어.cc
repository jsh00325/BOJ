#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6, LOW = -987654321;
bool isPrime[MX+1];
vector<int> pv;
int p[MX+1], pf[MX+1];

struct node { int lmax, rmax, max, sum; } seg[4*MX];

node get_next_node(const node& l, const node& r) {
	return {
		max(l.lmax, l.sum + r.lmax),
		max(r.rmax, l.rmax + r.sum),
		max(l.rmax+r.lmax, max(l.max, r.max)),
		l.sum + r.sum
	};
}

void build(int idx, int l, int r) {
	if (l == r) { seg[idx] = {p[l], p[l], p[l], p[l]}; return; }
	
	int mid = (l + r) >> 1, lidx = idx<<1, ridx = lidx+1;
	build(lidx, l, mid); build(ridx, mid+1, r);
	seg[idx] = get_next_node(seg[lidx], seg[ridx]);
}

node query(int idx, int l, int r, int st, int en) {
	if (r < st || en < l) return {LOW, LOW, LOW, 0};
	if (st <= l && r <= en) return seg[idx];

	int mid = (l + r) >> 1;
	node lq = query(idx<<1, l, mid, st, en);
	node rq = query((idx<<1)+1, mid+1, r, st, en);
	return get_next_node(lq, rq);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 2; i <= MX; ++i) isPrime[i] = 1;
	for (int i = 2; i*i <= MX; ++i) if (isPrime[i])
		for (int j = i*i; j <= MX; j += i) isPrime[j] = 0;
	for (int i = 2; i <= MX; ++i) if (isPrime[i]) pv.push_back(i), p[i] = 1;

	for (int i = 2; i <= MX; ++i) {
		for (auto& x : pv) {
			if (i*x > MX) break;
			if (p[i*x] == 0) p[i*x] = p[i] + p[x];
		}
	}
	p[1] = -1;
	for (int i = 2; i <= MX; ++i) p[i] -= (isPrime[i] ? 3 : 1);


	build(1, 1, MX);
	for (int tc = 1; ; ++tc) {
		int l, u; cin >> l >> u;
		if (l == -1 && u == -1) break;
		node ans = query(1, 1, MX, l, u);
		cout << tc << ". " << ans.max << '\n';
	}
}