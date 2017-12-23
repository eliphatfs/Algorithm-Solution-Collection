#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
multiset<int> a[Maxn];
int T,n,m,op,t;
int s[Maxn],tot[Maxn],cntt[Maxn];
int s1[Maxn];
set<int> now;
set<pair<int,int> > p;
void add(int pos,int val)
{
	for (;pos<=n;pos+=pos&(-pos))
		s1[pos]+=val;
}
int query(int pos)
{
	int res=0;
	for (;pos;pos-=pos&(-pos))
		res+=s1[pos];
	return res;
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d",&s[i]);
		scanf("%d",&m);
		int cnt=0;
		now.clear();
		p.clear();
		memset(a,0,sizeof(a));
		memset(tot,0,sizeof(tot));
		memset(cntt,0,sizeof(cntt));
		memset(s1,0,sizeof(s1));
		int ss=0;
		while (m--)
		{
			scanf("%d%d",&t,&op);
			while (cnt>0&&(*p.begin()).first<=t)
			{
				int y=(*p.begin()).second;
				++tot[y];
				if (tot[y]==1) now.insert(y);
				add(y,1);
				p.erase(*p.begin());
				--cntt[y];
				--cnt;
				a[y].erase(*a[y].begin());
				++ss;
			}
			if (op==0)
			{
				int id;
				scanf("%d",&id);
				a[id].insert(t+s[id]);
				++cntt[id];
				p.insert(make_pair(t+s[id],id));
				++cnt;
			}
			else if (op==1)
			{
				if (ss==0) printf("Yazid is angry.\n");
				else
				{
					int t=(*now.begin());
					add(t,-1);
					--tot[t];
					if (tot[t]==0) now.erase(t);
					printf("%d\n",t);
					--ss;
				}
			} else if (op==2)
			{
				int id;
				scanf("%d",&id);
				if (tot[id]>0)
				{
					--tot[id];
					if (tot[id]==0) now.erase(id);
					add(id,-1);
					printf("Succeeded!\n");
					--ss;
				} else if (cntt[id]>0) printf("%d\n",(*a[id].begin())-t);
				else printf("YJQQQAQ is angry.\n");
			} else
			{
				int lx,rx;
				scanf("%d%d",&lx,&rx);
				printf("%d\n",query(rx)-query(lx-1));
			}
		}
	}
	return 0;
}
