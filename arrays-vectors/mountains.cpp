#include <bits/stdc++.h>
using namespace std;

int longestMountain(vector<int> &arr)
{
    int maxAns = 0;
    int i = 0;
    while (i < arr.size())
    {
        int leftLength = 0;
        int rightLength = 0;

        int left = i;
        int right = i;
        while (left - 1 >= 0 && arr[left] > arr[left - 1])
        {
            left--;
            leftLength++;
        }
        while (i + 1 < arr.size() && arr[i] > arr[i + 1])
        {
            i++;
            rightLength++;
        }

        if (leftLength > 0 && rightLength > 0)
        {
            int length = rightLength + leftLength + 1;
            maxAns = max(maxAns, length);
        }

        i++;
    }

    return maxAns;
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

    cout << longestMountain(v);

    return 0;
}
