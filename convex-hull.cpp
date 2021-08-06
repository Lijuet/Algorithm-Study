#include <bits/stdc++.h>

using namespace std;

bool is_convex_hull_segment(const pair<int, int> &first, pair<int, int> &second, const vector<pair<int, int>> &a) {
    auto [x1, y1] = first;
    auto [x2, y2] = second;
    int inc = (x2 - x1 ? (y2 - y1) / (x2 - x1) : INT_MAX);
    int bias = y2 - inc * x2;
    int pos = 0, neg = 0;

    auto check_side = [&](int x, int y) {
        if (inc == INT_MAX) return x - first.first;
        if (inc == 0) return y - second.second;
        return y - (inc * x + bias); 
    };

    for (auto point : a) {
        if (point == first || point == second) continue;
        if (check_side(point.first, point.second) > 0) pos++;
        else if (check_side(point.first, point.second) < 0) neg++;
        else {
            if (point.first < first.first || point.first > second.first) return false;
        }
    }
    if (pos > 0 && neg > 0) return false;
    else return true;
}

vector<pair<int, int>> brute_convex(const vector<pair<int, int>> &a) {
    set<pair<int, int>> ans;

    for (int i = 0; i < a.size() - 1; i++) {
        auto first = a[i];
        for (int j = i + 1; j < a.size(); j++) {
            auto second = a[j];
            if (first == second) continue;
            if (is_convex_hull_segment(first, second, a)) {
                ans.insert(first);
                ans.insert(second);
            }
        }
    }

    vector<pair<int, int>> ret(ans.begin(), ans.end());
    sort(ret.begin(), ret.end());
    return ret;
}

vector<pair<int, int>> merge_convex(const vector<pair<int, int>> &left, const vector<pair<int, int>> &right)

vector<pair<int, int>> DAQ_convex(const vector<pair<int, int>> &a) {
    if(a.size() < 5) return brute_convex(a);

    //Divide DQA_hull
    vector<pair<int, int>> left, right, left_convex, right_convex;

    for (int i = 0; i < a.size() / 2; i++) left.push_back(a[i]);
    for (int i = a.size() / 2 + 1; i < a.size(); i++) right.push_back(a[i]);

    left_convex = DAQ_convex(left);
    right_convex = DAQ_convex(right);

    return merge_convex(left, right);
}

vector<pair<int, int>> make_convex_hull(const vector<pair<int, int>> &a) {
    return DAQ_convex(a);
}


int main(){
    vector<pair<int, int>> a;
    a.push_back(make_pair(0, 0));
    a.push_back(make_pair(1, -4));
    a.push_back(make_pair(-1, -5));
    a.push_back(make_pair(-5, -3));
    a.push_back(make_pair(-3, -1));
    a.push_back(make_pair(-1, -3));
    a.push_back(make_pair(-2, -2));
    a.push_back(make_pair(-1, -1));
    a.push_back(make_pair(-2, -1));
    a.push_back(make_pair(-1, 1));

    // sorting the set of points according
    // to the x-coordinate
    sort(a.begin(), a.end());

    vector<pair<int, int>>ans = make_convex_hull(a);

    cout << "convex hull:\n";
    for (auto e:ans)
        cout << e.first << " " << e.second << endl;

    return 0;

}