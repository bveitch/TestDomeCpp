/*
   Question: TestDome - MagicForest

   A magic forest is a set of nodes and edges. An edge connects two
   distinct nodes. Two nodes cannot be connected by more than one edge. A
   subset of nodes is a tree if it has the following two properties:

   1. For any two nodes in the subset there is exactly one series of
      edges Xi connecting them.

   2. There is no edge connecting a node from the subset to a node outside
      the subset.

   Write a class that can calculate the number of trees in a magic forest.

   For example, if we have a magic forest with 10 nodes (0-9) and edges
   1-2, 3-4, 3-5, 4-5, 6-7, 6-8, and 6-9, countTrees should return 3 as
   there are three trees (0), (1, 2), and (6, 7, 8, 9) in that magic
   forest. A subset of nodes (3, 4, 5) is not a tree since there are two
   series of edges connecting each two nodes. Nodes 3 and 5 are connected
   via direct edge 3-5 and via series of edges 3-4 and 4-5.
*/

#include <iostream>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <unordered_map>
#include <vector>

class Edge
{
public:

   Edge(int from, int to)
   {
      this->from = from;
      this->to = to;
   }

   int GetFrom() const
   {
      return from;
   }

   int GetTo() const
   {
      return to;
   }

private:

   int from;
   int to;
};

class MagicForest
{
    std::unordered_map<int,std::vector<int>> adj;
    std::vector<bool> visited;


public:
   /**
   *   \brief Initializes a new instance of the MagicForest class.
   *
   *   \param nodes Number of nodes in the magic forest. Nodes are numbered 0 .. nodes-1.
   *   \param edges List of edges.
   *
   **/
   MagicForest(int nodes, const std::vector<Edge>& edges):visited(nodes,false)
   {
        for(auto& edge: edges){
            int from=edge.GetFrom();
            int to=edge.GetTo();
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
   }

    void DFS(int u){
        visited[u] = true;
        for (int i=0; i<adj[u].size(); i++){
            if (!visited[adj[u][i]]) DFS(adj[u][i]);
        }
    }

   int countTrees()
   {
       auto count=0;
       for(auto &p: adj){
           if(!visited[p.first]){
               DFS(p.first);
               count++;
           }
       }
      return count;
   }
};


#ifndef RunTests
int main(int argc, const char* argv[])
{
   std::vector<Edge> edges;
   edges.push_back(Edge(1, 2));
   edges.push_back(Edge(3, 4));
   edges.push_back(Edge(3, 5));
   edges.push_back(Edge(4, 5));
   edges.push_back(Edge(6, 7));
   edges.push_back(Edge(6, 8));
   edges.push_back(Edge(6, 9));

   MagicForest forest(10, edges);

   std::cout << forest.countTrees();
}
#endif