/*
* @filename: graph.cpp
* @about:    Holds functions that add edges into the adjacencylist, that
*            add vertices into a vertices list and a function that Creates
*            a minimum spanning tree from the given vertices and edges.
* @author:   Omar Martinez: omartinez18
* @Date:     16 May 2017
*/
#include"graph.h"
#include<algorithm>
/*
* @function: void Graph::mst(string start).
* @brief: Creates a minimum spanning tree from given edges and vertices. Each
*         each step adds a light edge that connects start to an isolated vertex.
*         Terminates when minQ is empty.
* @param: String start is the first vertice inserted.
* @return: none.
*/
void Graph::mst(string start){
  vertices[start].key=0;
  int mstWeight=0;
  //std::cout<<"here";
  minQ.insert(start,vertices[start].key);
  std::map<string, std::vector<Neighbor> >::iterator iter;//iterator
//  std::cout<<"here2";
  for(iter=adjList.begin();iter!=adjList.end();iter++){
    std::sort(iter->second.begin(),iter->second.end());//adjacency list sort
  }//for
  std::map<string, Vertex>::iterator vertIter;
//  std::cout<<"here3";
  for(vertIter=++vertices.begin();vertIter!=vertices.end();vertIter++){//iterator
    minQ.insert(vertIter->first,vertIter->second.key);//inserts into minQ
  }
//  std::cout<<"here4";
  while(minQ.empty()!= true){
    std::string str=minQ.extractMin();
  //  std::cout<<"here5";
    for(unsigned int i = 0;i != adjList[str].size();i++){
      if(adjList[str][i].weight < vertices[adjList[str][i].name].key){
        vertices[adjList[str][i].name].pi=str;
        vertices[adjList[str][i].name].key=adjList[str][i].weight;
        minQ.decreaseKey(adjList[str][i].name,adjList[str][i].weight);
      }//if
    }//for
    mstWeight=mstWeight+vertices[str].key;
    std::cout<<str<<" "<<vertices[str].pi<<" "<<vertices[str].key<<"\n";
  }//while
  std::cout<<"Total Weight: "<<mstWeight<<"\n";
}//mst
/*
* @function: void Graph::addEdge(string from, string to, int weight).
* @brief: Adds an edge into the adjacency list by creating a Neighbor class object
*         that holds the objects name and weight.
* @param: String from is the vertex in which the edge comes from. String to
*         is the vertex of where the edge will end at. Int weight holds the
*         weight of the newly created edge.
* @return: none.
*/
void Graph::addEdge(string from, string to, int weight){
  std::cout<<from<<to<<weight<<"\n";
  Neighbor neigh;
  neigh.name=to;
  neigh.weight=weight;
  adjList[from].push_back(neigh);
  neigh.name=from;
  adjList[to].push_back(neigh);
}
/*
* @function: void Graph::addVertex(string name).
* @brief: Adds a edge into the vertex list by creating a vertex class object.
* @param: String name holds the name of the newly created vertex.
* @return: none.
*/
void Graph::addVertex(string name){
  Vertex vert;
  vert.pi="NIL";
  vert.key=100;
  vertices[name]=vert;
}
/*
* @function: Graph::Vertex::Vertex().
* @brief: Vertex class constructor inside graph class.
* @param: none.
* return: none.
*/
Graph::Vertex::Vertex(){
  pi="";
  key=0;
}
/*
* @function: Graph::Neighbor::Neighbor().
* @brief: Neighbor class constructor inside graph class.
* @param: none.
* return: none.
*/
Graph::Neighbor::Neighbor(){
  name="";
  weight=0;
}
/*
* @function: Graph::Neighbor::Neighbor(string name, int weight).
* @brief: Neighbor class overloaded constructor inside graph class.
* @param: String name and int weight that allows Neighbor class objects to hold
*         a name and a weight.
* return: none.
*/
Graph::Neighbor::Neighbor(string name, int weight){
  this->name=name;
  this->weight=weight;
}
/*
* @function:  Graph::Graph().
* @brief: Graph constructor.
* @param: none.
* return: none.
*/
Graph::Graph(){}
/*
* @function:  Graph::~Graph().
* @brief: Graph destructor.
* @param: none.
* return: none.
*/
Graph::~Graph(){}
