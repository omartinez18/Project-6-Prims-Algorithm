/*
* @filename: minpriority.h
* @about:    Holds function prototypes that builds, inserts, decrease the key of an index 
*            and extracts the minimum element in a minpriority queue.
* @author:   Omar Martinez: omartinez18
* @Date:     16 May 2017
*/
#ifndef __MINPRIORTY_H
#define __MINPRIORTY_H

#include<string>
#include<vector>
#include<cmath>

using std::string;
using std::vector;

class MinPriorityQ{

  public:

    ~MinPriorityQ();
    void insert(string id, int key);
    void decreaseKey(string id, int newKey);
    string extractMin();
    bool isMember(string id);
    bool empty();

  private:
    class Element{
      public:
        Element();
        Element(string id, int key);
        string id;
        int key;
        string getID(){return id;}
        int getKey(){return key;}
    };
    std::vector<Element> minHeap;
    void buildMinHeap();
    void minHeapify(unsigned int i);
    int parent(int i);
    int left(int i);
    int right(int i);

};
#endif
