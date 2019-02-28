#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
    private:
        int N;
        vector<pair<int, int>> lengths;
        vector<pair<int, string>> res;
        unordered_set<string> seen;
    public:
        void prepData() {
            cin >> N;
            int a;
            for (int i = 0; i < N; i++) {
                cin >> a;
                lengths.push_back(make_pair(a, i+1));
            }
            sort(lengths.begin(), lengths.end());
            res.push_back(make_pair(0, "YES"));
        }

        bool dfs(string s, int l, int dex) {
            bool found = false;
            if (seen.find(s) != seen.end()) return false;

            if (s.length() == l) {
                res.push_back(make_pair(dex, s));
                seen.insert(s);
                return true;
            }

            found |= dfs(s+"0", l, dex);
            if (found) return found;

            found |= dfs(s+"1", l, dex);

            if (s == "" && found == false) {
                res.clear();
                res.push_back(make_pair(0,"NO"));
                return false;
            }

            return found;
        }

        void main() {
            prepData();

            for (auto i: lengths) {
                dfs("", i.first, i.second);
            }

            sort(res.begin(), res.end());
            for (auto i: res) {
                cout << i.second << endl;
            }
        }
};

int main() {
    Solution s;
    s.main();
    return 0;
}