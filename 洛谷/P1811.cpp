#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;

struct sct //struct constraint
{
	int p1, p2, p3;
	bool operator<(sct oth) const
	{
		if (p1 < oth.p1) return true;
		else if (p1 > oth.p1) return false;
		if (p2 < oth.p2) return true;
		else if (p2 > oth.p2) return false;
		if (p3 < oth.p3) return true;
		return false;
	}
};

struct edge
{
	int to;
	int id;
};

int n, m, k;
vector<edge> edges[3072];
queue<int> bfq = queue<int>();
vector<int> depth[3072];
vector<int> pre[3072];
vector<edge> pree[3072];
int cnt[3072] = {0};
map<sct, int> constraints;
bool vise[65536];
stack<edge> croute;

void bfs()
{
	while (!bfq.empty())
	{
		int cur = bfq.front();
		bfq.pop();
		//cout<<cur;
		if (pree[cur].size() > 0)
		{
			/*if (depth[cur][cnt[cur]] <= croute.size())
				croute.pop();
			croute.push(pree[cur][cnt[cur]]);*/
		}
		if (cur != n)
		for (int i=0; i<edges[cur].size(); i++)
		{
			edge * e = &edges[cur][i];
			if (vise[e->id]) continue;
			sct cons;
			if (pre[cur].size() > 0)
			{
				cons.p1 = pre[cur][cnt[cur]];
				cons.p2 = cur;
				cons.p3 = e->to;
				if (constraints[cons] > 0) continue;
				//cout<<cons.p1<<cons.p2<<cons.p3<<endl;
			}
			vise[e->id] = true;
			depth[e->to].push_back(depth[cur][cnt[cur]]+1);
			pre[e->to].push_back(cur);
			pree[e->to].push_back(*e);
			//if (e->to == 3 && pre[e->to].size() == 2) cout<<666<<endl;
			//cout<<e->to<<pre[e->to][pre[e->to].size()-1]<<endl;
			//cout<<pre[3].size()<<endl;
			bfq.push(e->to);
		}
		cnt[cur]++;
		if (cur==n) return;
	}
}
int main()
{
	memset(vise, 0, sizeof(vise));
	scanf("%d%d%d", &n, &m, &k);
	depth[1].push_back(0);
	for (int i=0; i<m; i++)
	{
		int s, f;
		scanf("%d%d", &s, &f);
		edge es, ef;
		es.to = f;
		ef.to = s;
		es.id = i * 2;
		ef.id = i * 2 + 1;
		edges[s].push_back(es);
		edges[f].push_back(ef);
	}
	for (int i=0; i<k; i++)
	{
		sct s;
		scanf("%d%d%d", &s.p1, &s.p2, &s.p3);
		constraints[s] = 1;
	}
	bfq.push(1);
	bfs();
	//cin.get(), cin.get();
	cout<<depth[n][0]<<endl;
	//cin.get();
	int cur = n;
	stack<int> route;
	//cout<<1<<(char)32;
	//for (int i=0; i<croute.size(); i++)
	while (cur != 1)
	{
	/*	route.push(croute.top().to);
		croute.pop();
	}*/
		route.push(cur);
		//printf("%d%d ", cur, pre[3].size());
		//cout<<cur<<(char)32<<cnt[cur]<<(char)32<<pre[cur].size();
		//cin.get();
		int nn = pre[cur][--cnt[cur]];
		//pre[cur].pop_back();
		cur = nn;
	}
	cout<<1<<(char)32;
	while (!route.empty())
	{
		printf("%d ", route.top());
		route.pop();
	}
	return 0;
}