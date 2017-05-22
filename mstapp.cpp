/*
* @filename: mstapp.cpp
* @about:    Holds main int main and readGraph functions. 
* @author:   Omar Martinez: omartinez18
* @Date:     16 May 2017
*/
#include"graph.h"
#include"mstapp.h"
#include<stdlib.h>
#include<iostream>
#include<cstring>
/*
* @function: int main().
* @brief: Creates MSTapp class object to call readGraph().
* @param: none.
* @return: Returns 0 to end function.
*/
int main(){
  MSTapp app;
  app.readGraph();
  return 0;
}
/*
* @function: void MSTapp::readGraph().
* @brief: Reads in user input and adds edges and vertices to there list.
* @param: none.
* @return: none.
*/
void MSTapp::readGraph(){
  std::string input;
  std::string to;
  std::string from;
  int weight=0;
  std::getline(std::cin,input);
  //std::string first=input.substr(0,1);//takes first inserted vertex
  //input.erase(0,2);//deletes first inserted vertex + space in front
  while(input.size()!=0){
    signed int found = input.find(" ");
    std::string str= input.substr(0,1);
    myGraph.addVertex(str);
    input.erase(0,found+1);
    if(found==-1){
        break;
    }
  }//while
  std::cin>>from;
  std::cin>>to;
  std::cin>>weight;
  std::string first=from;
  myGraph.addEdge(from,to,weight);
  while(std::cin.peek() != EOF){
    //std::cout<<"here\n";
    std::cin >> from;
    std::cin >> to;
    std::cin >> weight;
    myGraph.addEdge(from,to,weight);
  }
//  std::cout<<"here2\n";
    myGraph.mst(first);
}
