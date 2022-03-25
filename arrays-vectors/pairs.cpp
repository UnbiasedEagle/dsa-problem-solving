#include <bits/stdc++.h>
using namespace std;

pair<int, int> pairsa(vector<int> arr, int target)
{

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            int sum = arr[i] + arr[j];
            if (sum == target)
            {
                return {arr[i], arr[j]};
            }
        }
    }

    return {-1, -1};
}

pair<int, int> pairsb(vector<int> arr, int target)
{
    sort(arr.begin(), arr.end());

    int start = 0;
    int end = arr.size() - 1;

    while (start < end)
    {
        int sum = arr[start] + arr[end];
        if (sum == target)
        {
            return {arr[start], arr[end]};
        }

        if (sum > target)
        {
            end--;
        }
        else
        {
            start++;
        }
    }

    return {-1, -1};
}

pair<int, int> pairsc(vector<int> arr, int target)
{
    unordered_set<int> s;

    for (int i = 0; i < arr.size(); i++)
    {
        int comp = target - arr[i];
        if (s.find(comp) != s.end())
        {
            return {comp, arr[i]};
        }
        s.insert(arr[i]);
    }

    return {-1, -1};
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    int target;
    cin >> target;
    // pair<int, int> ans = pairsa(arr, target);
    // pair<int, int> ans = pairsb(arr, target);
    pair<int, int> ans = pairsc(arr, target);
    cout << ans.first << " " << ans.second;
    return 0;
}