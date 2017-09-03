#include <cstdio>
#include <vector>
using namespace std;
int maze[5][5];
int visited[5][5] = {{0}};
struct Point
{
    int px, py;
    void move(int direction)
    {
        switch (direction)
        {
            case 0:
                px++;
                break;
            case 1:
                py++;
                break;
            case 2:
                px--;
                break;
            case 3:
                py--;
                break;
        }
    }
    void moveback(int direction)
    {
        switch (direction)
        {
            case 0:
                px--;
                break;
            case 1:
                py--;
                break;
            case 2:
                px++;
                break;
            case 3:
                py++;
                break;
        }
    }
    void print()
    {
        printf("(%d, %d)\n", px, py);
    }
};
Point pos;
vector<Point> route = vector<Point>();
vector<Point> * minRoute = NULL;
void sch()
{
    for (int i=0; i<4; i++)
    {
        pos.move(i);
        if (pos.px < 5 && pos.py < 5 && pos.px >= 0 && pos.py >= 0 && visited[pos.px][pos.py] == 0 && maze[pos.px][pos.py] == 0)
        {
            route.push_back(pos);
            visited[pos.px][pos.py] = 1;
            if (pos.px == 4 && pos.py == 4)
            {
                if (minRoute == NULL || route.size() < minRoute->size())
                    minRoute = new vector<Point>(route);
            }
            else sch();
            route.pop_back();
            visited[pos.px][pos.py] = 0;
        }
        pos.moveback(i);
    }
}
int main()
{
    for (int i=0; i<25; i++)
        scanf("%d", &maze[i/5][i%5]);
    pos.px = pos.py = 0;
    sch();
    pos.px = pos.py = 0;
    pos.print();
    for (int i=0; i<minRoute->size(); i++)
        (*minRoute)[i].print();
    //getchar();getchar();
    return 0;
}
