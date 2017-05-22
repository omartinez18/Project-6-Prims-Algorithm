/*
* @filename: mstapp.h
* @about:    Holds function prototypes for int main and readGraph function that
*            that reads in user input and makes function calls accordingly.
* @author:   Omar Martinez: omartinez18
* @Date:     16 May 2017
*/
#ifndef __MSTAPP_H
#define __MSTAPP_H
#include"graph.h"

class MSTapp{
public:
  int main();
  void readGraph();
private:
  Graph myGraph;
};
#endif
