#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    int ans=0;
    cin>>a>>b>>c;
    int lasty=c/b+1;
    for(int yi=0;yi<lasty;yi++)
    {
            int xi=0;
            while(1)
            {
                    int anstmp=xi*a+yi*b;
                    xi++;
                    if(anstmp==c)ans++;
                    if(anstmp>c)break;
            }
    }
    cout<<ans;
    return 0;
}
