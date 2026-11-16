#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 题目描述
// 玩过RPG（尤其是国产RPG）的童鞋都应该对迷宫这种神棍的设定深恶痛绝，尤其是当你转了半小时之后发现回到了原地，这种感觉真是无比的痛苦。。。万一游戏还中途崩溃了那真是连掀桌子、砸键盘、摔鼠标的心都有了……
// 经过无数次的TRIAL AND ERROR之后，玩家终于下定决心认定迷宫存在的意义就是延长游戏时间，SO，他决定借鉴著名的左手定则（就是在每一个路口，我们都选择最左边的方向，左转的优先级最高，其次为向前，最后为右转，如果实在走进了一个死胡同，那就连续右转两次，回头向后走。稍微研究一下这种走迷宫的方法，我们就发现在这个过程中，事实上我们的左手可以始终放在墙上。）对迷宫进行探索。
// 但是呢，左手定则并不能保证遍历到迷宫中的每一个点。悲剧的是，某项重要的通关道具被放在了这个迷宫中……幸运的是，游戏迷宫的地图可以绘制出来，现在请求你的帮助。对于一个给定的地图，他想知道是不是能够通过左手定则取得这件道具。

// 关于输入
// 多组数据。
// 对于每组数据，第一行有两个整数N,M代表接下来有n行字符串，每行m个字符，其中0 < n <= 100, 0 < m <= 100，表示一个n × m的迷宫。
// 其中‘#’表示墙，‘S’表示起点，‘T’表示道具，‘.’表示空地。
// 接下来是一个方向（NSWE），表示起始面向的方向。
// 数据保证最外一圈都是墙。

// 左手定则是否一定能循环?

// dir = 0 1 2 3  表示n e s w
// dx[] dy[] 表示i=dir时移动一次的位移
string direction = "NESW";
vector<vector<char>> v{};
vector<vector<int>> vis{}; // 墙壁处为-2，未走过处为-1，走过处为第一次经过时的dir

int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};

// 如何判断已经走过所有可达的区域？重复回到一处且方向相同，或者所有非墙壁点被遍历，即vis没有-1

bool allreached(vector<vector<int>> &vis)
{
    bool reachedall = true;
    for (auto a : vis)
    {
        for (auto b : a)
        {
            if (b == -1)
                reachedall = false;
        }
    }
    return reachedall;
}

int left(int dir)
{
    return (dir + 4 - 1) % 4;
}
int front(int dir)
{
    return (dir) % 4;
}
int right(int dir)
{
    return (dir + 1) % 4;
}

void lefthandgo(vector<vector<char>> &v, vector<vector<int>> &vis, int dir, int x, int y)
{ // x，y 按值复制
    while (!allreached(vis) && (dir != vis[x][y]))
    {

        if (vis[x][y] == -1)
            vis[x][y] = dir;
        if (v[x + dx[left(dir)]][y + dy[left(dir)]] != '#')
        {
            dir = left(dir);
            x += dx[dir];
            y += dy[dir];
        }
        else if (v[x + dx[front(dir)]][y + dy[front(dir)]] != '#')
        {
            x += dx[dir];
            y += dy[dir];
        }
        else if (v[x + dx[right(dir)]][y + dy[right(dir)]] != '#')
        {
            dir = right(dir);
            x += dx[dir];
            y += dy[dir];
        }
        else
        {
            dir = (dir + 2) % 4;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    while (cin >> n >> m)
    {

        v.resize(n, vector<char>(m));
        vis.resize(n, vector<int>(m));
        int xs, ys, xt, yt;
        // 初始化v和vis
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
                if (v[i][j] == '#')
                    vis[i][j] = -2;
                if (v[i][j] == '.')
                    vis[i][j] = -1;
                if (v[i][j] == 'S')
                {
                    vis[i][j] = -1;
                    xs = i;
                    ys = j;
                }
                if (v[i][j] == 'T')
                {
                    vis[i][j] = -1;
                    xt = i;
                    yt = j;
                }
            }
        }
        // 输入初始dir
        char c;
        int dir;

        cin >> c;
        for (int i = 0; i < 4; i++)
        {
            if (c == direction[i])
                dir = i;
        }
        //
        lefthandgo(v, vis, dir, xs, ys);
        if (vis[xt][yt] == (-1))
            cout << "NO";
        else
            cout << "YES";
        cout << endl;
        v.clear();
        vis.clear();
    }

    return 0;
}