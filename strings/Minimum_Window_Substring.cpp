#include <iostream>
using namespace std;
#include <bits/stdc++.h>

std::string minWindow(std::string s, std::string t)
{
    if (s.empty() || t.empty() || s.length() < t.length())
    {
        return "";
    }

    std::vector<int> map(128, 0);
    int count = t.length();
    int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;

    for (char c : t)
    {
        map[c]++;
    }
    while (end < s.length())
    {
        if (map[s[end++]]-- > 0)
        {
            count--;
        }
        while (count == 0)
        {
            if (end - start < minLen)
            {
                startIndex = start;
                minLen = end - start;
            }

            if (map[s[start++]]++ == 0)
            {
                count++;
            }
        }
    }

    return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
}
int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";
    string s3 = minWindow(s2, s1);
    cout << "min window substr is:"<<s3;
    return 0;
}