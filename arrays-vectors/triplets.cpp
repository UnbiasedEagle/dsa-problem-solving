#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > threeSum(vector<int> v, int target)
{
    sort(v.begin(), v.end());

    vector<vector<int> > ans;

    for (int i = 0; i < v.size() - 2; i++)
    {
        if (i > 0 && v[i] == v[i - 1])
        {
            continue;
        }
        int comp = target - v[i];
        int left = i + 1;
        int right = v.size() - 1;

        while (left < right)
        {
            int sum = v[left] + v[right];
            if (sum == comp)
            {
                ans.push_back({v[i], v[left], v[right]});
                right--;
                while (left < right && v[right] == v[right + 1])
                {
                    right--;
                }
            }
            else if (sum > comp)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }

    int target;
    cin >> target;

    vector<vector<int> > ans = threeSum(v, target);

    sort(ans.begin(), ans.end());

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}