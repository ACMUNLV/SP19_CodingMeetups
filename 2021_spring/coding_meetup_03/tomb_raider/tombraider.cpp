#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1e9;
#define MAXN 505

int n, m, VID;
int rep[MAXN * MAXN * 2], rnk[MAXN * MAXN * 2], cnt[MAXN * MAXN * 2], cntDiff[MAXN * MAXN * 2];
int mirror[128][4], dir[4][2] = { -1, 0, 0, 1, 1, 0, 0, -1 };
bool v[MAXN * MAXN * 2];
char G[MAXN][MAXN];
int id(int i, int j, int t) { return ((i * m + j) << 1) + t; }
int id2(int v, int t) { return (v << 1) + t; }
bool isGargoyle(int x, int y) { return G[x][y] == 'V' || G[x][y] == 'H'; }

int find(int x) {
	if (rep[x] == x) return x;
	return rep[x] = find(rep[x]);
}

void unionset(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return;
	if (rnk[x] > rnk[y]) swap(x, y);
	cnt[y] += cnt[x];
	cntDiff[y] += cntDiff[x];
	rep[x] = y;
	rnk[y] += (rnk[x] == rnk[y]);
}

void same(int x, int y) {
	unionset(id2(x, 0), id2(y, 0));
	unionset(id2(x, 1), id2(y, 1));
}

void diff(int x, int y) {
	unionset(id2(x, 0), id2(y, 1));
	unionset(id2(x, 1), id2(y, 0));
}

void init() {
	mirror['\\'][0] = 3; mirror['\\'][3] = 0; mirror['\\'][1] = 2; mirror['\\'][2] = 1;
	mirror['/'][0] = 1; mirror['/'][1] = 0; mirror['/'][2] = 3; mirror['/'][3] = 2;
	REP(i, 0, n + 1) REP(j, 0, m + 1) REP(t, 0, 2) rep[id(i, j, t)] = id(i, j, t);
	VID = n * m + m;
	REP(i, 0, n) {
		REP(j, 0, m) {
			if (isGargoyle(i, j)) {
				cnt[id(i, j, 0)] = cnt[id(i, j, 1)] = 1;
				if (G[i][j] == 'H') cntDiff[id(i, j, 0)] = 1;
				else cntDiff[id(i, j, 1)] = 1;
			}
		}
	}
}

pair<PII, int> shoot(int x, int y, int d, int mir) {
	if (x < 0 || y < 0 || x >= n || y >= m) return make_pair(PII(), -1);
	if (G[x][y] == '#') return make_pair(PII(x, y), 0);
	if (G[x][y] == '\\' || G[x][y] == '/') {
		int nd = mirror[G[x][y]][d], nx = x + dir[nd][0], ny = y + dir[nd][1];
		return shoot(nx, ny, nd, mir + 1);
	}
	if (G[x][y] == 'V' || G[x][y] == 'H') return make_pair(PII(x, y), mir);
	return shoot(x + dir[d][0], y + dir[d][1], d, mir);
}

int main() {
	cin >> n >> m;
	REP(i, 0, n) cin >> G[i];
	init();
	
	REP(i, 0, n) {
		REP(j, 0, m) {
			if (isGargoyle(i, j)) {
				int sid = i * m + j;
				REP(d, 0, 4) {
					int ni = i + dir[d][0], nj = j + dir[d][1];
					pair<PII, int> hit = shoot(ni, nj, d, 0);
					if (hit.second == -1) continue;
					ni = hit.first.first; nj = hit.first.second;
					if (G[ni][nj] == '#') {
						if (d == 0 || d == 2) diff(sid, VID);
						else same(sid, VID);
					} else { // gargoyle
						int tid = ni * m + nj;
						if (hit.second & 1) diff(sid, tid);
						else same(sid, tid);
					}
					if (find(id2(sid, 0)) == find(id2(sid, 1))) return puts("-1"), 0;
				}
			}
		}
	}
	int V = find(id2(VID, 0)), H = find(id2(VID, 1)), ans = 0;
	REP(i, 0, n) {
		REP(j, 0, m) {
			if (isGargoyle(i, j)) {
				int r = find(id(i, j, 0)), r1 = find(id(i, j, 1));
				if (v[r] || v[r1]) continue;
				v[r] = v[r1] = true;
				if (r == V) ans += cntDiff[r];
				else if (r == H) ans += cnt[r] - cntDiff[r];
				else ans += min(cntDiff[r], cnt[r] - cntDiff[r]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
