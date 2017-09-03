#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> vec = vector<int>();
    while (true)
    {
        int tmp;
        cin>>tmp;
        if (tmp == 0) break;
        vec.push_back(tmp);
    }
    for (int i=vec.size() - 1; i >= 0; i--)
    {
        cout<<vec[i]<<" ";
    }
    //getchar();
    //getchar();
    return 0;
}
