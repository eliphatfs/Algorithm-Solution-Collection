#include <iostream>
#include <cstdio>
using namespace std;
int after[131071] = {0};
int before[131071] = {0};
int n,q;

int main()
{
    cin>>n>>q;
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &after[i]);
        before[after[i]] = i;
    }
    int qtype, id, c;
    for (int i=1; i<=q; i++)
    {
        scanf("%d", &qtype);
        if (qtype == 0)
        {
            scanf("%d", &id);
            after[before[id]] = after[id];
            before[after[id]] = before[id];
            before[0] = after[0] = before[id] = after[id] = 0;
        }
        else
        {
            scanf("%d%d", &id, &c);
            for (int j=0; j<c; j++)
            {
                id = after[id];
                if (id == 0) { id = -1; break; }
            }
            printf("%d\n", id);
        }
    }
    return 0;
} 
