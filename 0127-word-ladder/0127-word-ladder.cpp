class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        if (set.find(endWord) == set.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        set.erase(beginWord);

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord) return steps;

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (set.find(word) != set.end()) {
                        set.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};