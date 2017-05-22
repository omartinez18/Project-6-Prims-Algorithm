/*
* @filename: graph.h
* @about:    Holds function prototypes that add edges into the adjacencylist, that
*            add vertices into a vertices list and a function that Creates
*            a minimum spanning tree from the given vertices and edges.
* @author:   Omar Martinez: omartinez18
* @Date:     16 May 2017
*/
#ifndef __GRAPH_H
#define __GRAPH_H
#include"minpriority.h"
#include<iostream>
#include <string>
#include <vector>
#include <map>
using std::string;

class Graph{

public:
  Graph();
  ~Graph();
  void addVertex(string name);
  void addEdge(string from, string to, int weight);
  void mst(string start);
private:
  class Vertex{
  public:
    Vertex();
    Vertex(string pi, int key);
    string pi;
    int key;
  };
  class Neighbor{
  public:
    Neighbor();
    Neighbor(string name, int weight);
    string name;
    int weight;
    bool operator<(const Neighbor& n) const { return name < n.name; }
  };
  std::map<string, Vertex> vertices;
  std::map<string, std::vector<Neighbor> > adjList;
  MinPriorityQ minQ;
};
#endif
