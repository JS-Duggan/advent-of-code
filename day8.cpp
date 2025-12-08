#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>

using namespace std;

/**
* implement simple uf, using size because that is relevant
* to the question answer
*/
class union_find {
  public:
    union_find(int);
    int find(int);
    bool merge(int, int);
    vector<int> largest(int);

  private:
    vector<int> parent;
    vector<int> size;
};

union_find::union_find(int n) : parent(n), size(n, 1) {
  iota(parent.begin(), parent.end(), 0);
};

int union_find::find(int v) {
  if (parent[v] == v) return v;
  return parent[v] = find(parent[v]);
}

bool union_find::merge(int v1, int v2) {
  int r1 = find(v1);
  int r2 = find(v2);

  if (r1 == r2) return false;

  parent[r2] = r1;
  size[r1] += size[r2];
  return true;
}

vector<int> union_find::largest(int n) {
  vector<int> largest_sets;

  for (int i = 0; i < parent.size(); i++) {
    if (find(i) == i) largest_sets.push_back(size[i]);
  }

  nth_element(largest_sets.begin(), largest_sets.begin() + 3, largest_sets.end(), greater<>());
  vector<int> ans(largest_sets.begin(), largest_sets.begin() + n);

  return ans;
}

struct edge {
  long long weight;
  int u;
  int v;
};

struct edge_compare {
    bool operator()(const edge& a, const edge& b) const {
        return a.weight > b.weight;
    }
};

long long part1(vector<string> input) {
  int n = input.size();
  union_find uf(n);

  vector<vector<long long>> pos(n);

  /* convert input to positions */
  for (int s = 0; s < n; s++) {
    for (int i = 0; i < 3; i++) {
      int idx = input[s].find(',');
      pos[s].push_back(stol(input[s].substr(0, idx)));
      if (idx < input[s].size()) input[s].erase(0, idx + 1);
    }
  }
  
  priority_queue<edge, vector<edge>, edge_compare> pq;
  /* create edges and add to pq based on size */
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      long long dist = 0;
      for (int x = 0; x < 3; x++) {
        long long diff = pos[i][x] - pos[j][x];
        dist += diff * diff;
      }
      pq.push({dist, i, j});
    }
  }

  /* union the first n edges */
  for (int i = 0; i < 1000; i++) {
    edge e = pq.top();
    uf.merge(e.u, e.v);
    pq.pop();
  }


  /* find size of top 3 groups*/
  vector<int> largest = uf.largest(3);
  long long ans = 1;
  for (int i = 0; i < 3; i++) {
    ans *= largest[i];
  }

  return ans;
}


long long part2(vector<string> input) {
  int n = input.size();
  union_find uf(n);

  vector<vector<long long>> pos(n);

  /* convert input to positions */
  for (int s = 0; s < n; s++) {
    for (int i = 0; i < 3; i++) {
      int idx = input[s].find(',');
      pos[s].push_back(stol(input[s].substr(0, idx)));
      if (idx < input[s].size()) input[s].erase(0, idx + 1);
    }
  }
  
  priority_queue<edge, vector<edge>, edge_compare> pq;
  /* create edges and add to pq based on size */
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      long long dist = 0;
      for (int x = 0; x < 3; x++) {
        long long diff = pos[i][x] - pos[j][x];
        dist += diff * diff;
      }
      pq.push({dist, i, j});
    }
  }

  /* union all edges, recording the last join */
  int u;
  int v;
  while(!pq.empty()) {
    edge e = pq.top();
    pq.pop();
    if(uf.merge(e.u, e.v)) {
      u = e.u;
      v = e.v;
    }
  }

  return pos[u][0] * pos[v][0];
}
int main() {
  string s;
  vector<string> input;
  while (getline(cin, s)) input.push_back(s);

  cout << part2(input) << "\n";
}
