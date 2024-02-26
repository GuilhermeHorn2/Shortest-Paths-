#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <queue>

void Dijkstra(int strt, std::vector<std::vector<int>> &graph, std::vector<int> &dists);

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

 std::vector<int> dists;
 Dijkstra(0, graph, dists);

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

void Dijkstra(int strt, std::vector<std::vector<int>> &graph, std::vector<int> &dists)
{
 set_list(0, graph, dists);

 std::vector<int> mrkd;
 for (int i = 0; i < graph.size(); i++)
 {
  mrkd.push_back(0);
 }
 int curr = strt;
 while (true)
 {
  mrkd[curr] = 1;
  // search for the adjs
  int min = 0;
  int idx = -1;
  for (int i = 0; i < graph[curr].size(); i++)
  {
   int path = graph[curr][i];
   if (path != 0 && mrkd[i] == 0)
   {
    if (dists[i] > dists[curr] + path)
    {
     dists[i] = dists[curr] + path;
     if (dists[i] < min || idx == -1)
     {
      min = dists[i];
      idx = i;
     }
    }
   }
  }
  if (idx == -1)
  {
   break;
  }
  curr = idx;
 }
}
