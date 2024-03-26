#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

struct Point {
    long long x, y;

    Point operator-(const Point &other) const {
        return {x - other.x, y - other.y};
    }

    Point(long long x, long long y) : x(x), y(y) {}
    Point() {}
};

long long cross(const Point &p, const Point &q) {
    return p.x * q.y - p.y * q.x;
}

long long orient(const Point &o, const Point &p, const Point &q) {
    return cross(p - o, q - o);
}

vector<Point> points;
static int N;
static long long queries = 0;

bool contains(const Point &i, const Point &a, const Point &b, const Point &c) {
    bool o1 = orient(a, b, i) > 0;
    bool o2 = orient(b, c, i) > 0;
    bool o3 = orient(c, a, i) > 0;

    return o1 == o2 && o2 == o3;
}

void assert_format(bool test) {
    if (!test) {
        cout << "Richiesta malformata. / Malformed query.";
        exit(1);
    }
}

bool radar(int i, int a, int b, int c) {
    assert_format(i != a && i != b && i != c && a != b && a != c && b != c);
    assert_format(0 <= i && i < N);
    assert_format(0 <= a && a < N);
    assert_format(0 <= b && b < N);
    assert_format(0 <= c && c < N);
    queries++;

    return contains(points[i], points[a], points[b], points[c]);
}

vector<int> activate(int N);

int main() {
    // decommenta queste due righe per leggere da / scrivere su file
    // uncomment these two lines to read from / write to file
    // assert(freopen("input.txt", "r", stdin));
    // assert(freopen("output.txt", "w", stdout));

    assert(cin >> N);
    points.resize(N);
    for (auto &[x, y]: points) {
        assert(cin >> x);
        assert(cin >> y);
    }

    vector<int> ans = activate(N);
    
    cout << queries << endl;
    cout << ans.size() << '\n';
    for (int point: ans) {
        cout << point << ' ' ;
    }
    cout << '\n';
}
