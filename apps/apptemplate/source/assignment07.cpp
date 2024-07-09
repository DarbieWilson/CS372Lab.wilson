//
// File:   assignment7.cpp
// Author: Darbie Wilson
// Purpose:
// Abstract Base Class for Graph. Adjaceny List and Matix
//

#include <iostream>
using namespace std;
{
template<class N>
class AdjListGraph: public Graph<N> {
private:
  using Edges = std::list<std::<pair<int, int>>;
  std::vector<N> nodeVector;
  std::vector<Edges> edgesVector;
public:
  AdjListGraph() : Graph<N>() {};
  AdjListGraph(const AdjListGraph& other) : Graph<N>() {}
  AdjListGraph& operator= (const AdjListGraph &source) {}
  AdjListGraph(std::vector<N> newNodes, std::vector<pair<N,N>> newEdges) :
    Graph<N>(newNodes, newEdges) {}
  ~AdjListGraph() {}
  virtual bool adjacent(N x, N y) {}
  virtual std::vector<N> neighbors(N x) {}
  virtual void addNode(N node) {}
  virtual void addEdge(N x, N y) []
  virtual void deleteEdge(N x, N y) {}
};

template<class N>
class AdjMatrixGraph: public Graph<N> {
private:
  const static int MaxSize = 100;
  std::vector<N> nodeVector;
  std::byte adjMatrix[maxSize][maxSize];
  unsigned int numNodes = 0;
public:
  AdjMatrixGraph() : Graph<N>() {};
  AdjMatrixGraph(const AdjMatrixGraph& other) : Graph<N>() {}
  AdjMatrixGraph& operator= (const AdjMatrixGraph &source) {}
  AdjMatrixGraph(std::vector<N> newNodes, std::vector<pair<N,N>> newEdges) :
    Graph<N>(newNodes, newEdges) {}
  ~AdjMatrixGraph() {}
  virtual bool adjacent(N x, N y) {}
  virtual std::vector<N> neighbors(N x) {}
  virtual void addNode(N node) {}
  virtual void addEdge(N x, N y) []
  virtual void deleteEdge(N x, N y) {}
};

  return 0;
}
