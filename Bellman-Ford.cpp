#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <queue>

void Bellman_Ford(int strt, std::vector<std::vector<int>> &graph, std::vector<int> &dists);

void print_vec(std::vector<int> &v);

int main()
{
 /* ?_n;||(or) e &&(and)*/

 std::vector<int> a = {0, 5, 3, 7, 0};
 std::vector<int> b = {5, 0, 0, 3, 2};
 std::vector<int> c = {3, 0, 0, 1, 0};
 std::vector<int> d = {7, 3, 1, 0, 2};
 std::vector<int> e = {0, 2, 0, 2, 0};
 std::vector<std::vector<int>> graph = {a, b, c, d, e};

 // Bellman-Ford i very usefull when you need the shortest path form a specific node to
 // all others

 std::vector<int> dists;
 Bellman_Ford(0, graph, dists);
 print_vec(dists);

 return 0;
}

void print_vec(std::vector<int> &v)
{
 for (int i = 0; i < v.size(); i++)
 {
  std::cout << v[i] << ' ';
 }
}

void set_list(int strt, std::vector<std::vector<int>> &graph, std::vector<int> &dists)
{
 int inf = 0;
 for (int i = 0; i < graph.size(); i++)
 {
  for (int j = 0; j < graph[i].size(); j++)
  {
   inf += graph[i][j];
  }
 }
 for (int i = 0; i < graph.size(); i++)
 {
  dists.push_back(inf);
 }
 dists[strt] = 0;
}
void Bellman_Ford(int strt, std::vector<std::vector<int>> &graph, std::vector<int> &dists)
{
 set_list(strt, graph, dists);

 std::queue<int> adj;
 adj.push(strt);
 int n = 2 * graph.size(); // We iterate at most n rounds and the argument is if
 // algorithm runs more than this we say that there is a negative cycle
 int c = 0;
 // if exists a negative cycle the algortihm will run more than n times
 while (!adj.empty() && c <= n)
 {
  int curr = adj.front();
  // get adj and check if is possible to reduce any cost
  for (int i = 0; i < graph[curr].size(); i++)
  {
   int path = graph[curr][i];
   if (path != 0)
   {
    if (dists[curr] + path < dists[i])
    {
     dists[i] = dists[curr] + path;
     adj.push(i);
    }
   }
  }
  adj.pop();
  c++;
 }
}
