
#include <iostream>
#include <vector>
using namespace std;

int addRungs(vector<int> &rungs, int dist)
{
    int height = 0;
    int ans = 0;
    int h;
    for (int i = 0; i < rungs.size(); i++)
    {
        h = rungs[i] - height;
        if (h > dist)
        {
            if (dist == 1)
            {
                ans += h - 1;
            }
            else
            {
                ans += h / dist;
            }
        }
        height = rungs[i];
    }
    return ans;
}
int main()
{
    vector<int> rungs = {4, 8, 12, 16};
    int dist = 3;
    cout << addRungs(rungs, dist) << endl;
    return 0;
}
