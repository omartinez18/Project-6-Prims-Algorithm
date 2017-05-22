/*
* @filename: minpriority.cpp
* @about:    Holds functions that builds, inserts, decrease the key of an index
*            and extracts the minimum element in a minpriority queue.
* @author:   Omar Martinez: omartinez18
* @Date:     16 May 2017
*/
#include"minpriority.h"
#include<iostream>
/*
* @function:MinPriorityQ::~MinPriorityQ().
* @brief: Destructor for MinPriorityQ class.
* @param: none.
* @return:none.
*/
MinPriorityQ::~MinPriorityQ(){
  minHeap.clear();
}
/*
* @function:MinPriorityQ::Element::Element(string id, int key).
* @brief: Element class overloaded constructor in MinPriorityQ class.
* @param: String id holds element value and element key value.
* @return:none.
*/
MinPriorityQ::Element::Element(string id, int key){
  this->id=id;
  this->key=key;
}
/*
* @function:MinPriorityQ::Element::Element().
* @brief: Element class constructor in MinPriorityQ class.
* @param: none.
* @return:none.
*/
MinPriorityQ::Element::Element(){
  id=" ";
  key=0;
}//element constructor
/*
* @function: void MinPriorityQ::insert(string id, int key).
* @brief: Creates element object that holds id and key from parameter and
*         pushes it into the heap. Then calls buildMinHeap().
* @param: String id holds element value and element key value.
* @return:none.
*/
void MinPriorityQ::insert(string id, int key){
  Element el(id, key);
  minHeap.push_back(el);
  buildMinHeap();
}//insert
/*
* @function: void MinPriorityQ::decreaseKey(string id, int newKey).
* @brief:
* @param: String id holds element value and element key value.
* @return:none.
*/
void MinPriorityQ::decreaseKey(string id, int newKey){
/*  for(int i=0;i <minHeap.size();i++){
    if(minHeap[i]->id==id){
      minHeap[i]->key=newKey;
    }
  }//for*/
  if(isMember(id)!=true){
    return;
  }
  int i=0;
  for(int y=0;minHeap[i].id !=id;y++){
    i++;
  }
  if(newKey > minHeap[i].key){
    return;
  }
  else{
    minHeap[i].key=newKey;
    while(i>0 && minHeap[parent(i)].key > minHeap[i].key){
      std::swap(minHeap[i],minHeap[parent(i)]);
      i=parent(i);
    }
  }
}//decreaseKey
string MinPriorityQ::extractMin(){
/*  string keyHolder=minHeap[0]->key;
  int index=0;
  for(int i=0;i<minHeap.size();i++){
    if(minHeap[i]->key<keyHolder){
      keyHolder=minHeap[i]->key;
      index=i;
    }
  }//for
  Element el=minHeap[index];
  std::cout<<keyHolder;
  minHeap.erase(index+1);
  return keyHolder;*/
  Element minimum;
  if(minHeap.size()==0){
    return "empty";
  }
  if(minHeap.size()==1){
      minimum=minHeap[0];
      minHeap.erase(minHeap.begin());
      return minimum.getID();
  }
  minHeapify(0);
  minimum=minHeap[0];
  minHeap[0]=minHeap[minHeap.size()-1];
  minHeap.erase(minHeap.begin());
  minHeapify(0);
  return minimum.getID();
}//extractMin
bool MinPriorityQ::isMember(string id){
  for(unsigned int i=0;i<minHeap.size();i++){
    if(minHeap[i].getID()==id){
      return true;
    }//if
  }//for
  return false;
}//isMember
/*
* @function: void MinPriorityQ::buildMinHeap().
* @brief: Produces a min heap from an unordered array.
* @param: none.
* @return:none.
*/
void MinPriorityQ::buildMinHeap(){
  for(unsigned int i=(minHeap.size()-1)/2;i>0;i--){
    minHeapify(i);
  }//for
}//buildMinHeap
/*
* @function: void MinPriorityQ::buildMinHeap().
* @brief: Produces a min heap from an unordered array.
* @param: Unsigned int i that holds the index number of an element in the heap.
* @return:none.
*/
void MinPriorityQ::minHeapify(unsigned int i){
  unsigned int lowest=0;
  //std::cout<<"here1\n";
  unsigned int l=left(i);
  unsigned int r=right(i);
  if(l <= (minHeap.size()-1) && minHeap[l].getKey() < minHeap[i].getKey()){
    lowest=l;
  }//if
  else{
    lowest=i;
  }//else
  if(r <= (minHeap.size()-1) && minHeap[r].getKey() < minHeap[lowest].getKey()){
    lowest=r;
  }//if
  //std::cout<<"here2\n";
  if(lowest!=i){
    //std::cout<<"here3\n";
    //Element el=minHeap[i];
    //minHeap[i]=minHeap[lowest];
    std::swap(minHeap[i],minHeap[lowest]);
    //minHeap[lowest]=el;
    minHeapify(lowest);
  }
//  std::cout<<"here4\n";
}//minHeapify
/*
* @function: int MinPriorityQ::parent(int i).
* @brief: Finds the parent of i.
* @param: Int i is the index of an element being used for the function.
* @return:Index number of the parent of i.
*/
int MinPriorityQ::parent(int i){
  return i/2;
}//parent
/*
* @function: int MinPriorityQ::left(int i).
* @brief: Finds the left child of i.
* @param: Int i is the index of an element being used for the function.
* @return:Index number of the left child of i.
*/
int MinPriorityQ::left(int i){
  return (2*i);
}//left
/*
* @function: int MinPriorityQ::right(int i).
* @brief: Finds the right child of i.
* @param: Int i is the index of an element being used for the function.
* @return:Index number of the right child of i.
*/
int MinPriorityQ::right(int i){
  return  (2*i)+1;
}//right
/*
* @function: bool MinPriorityQ::empty().
* @brief: Checks to see if the minHeap is empty.
* @param: none.
* @return: true if minHeap is empty and false if it is not.
*/
bool MinPriorityQ::empty(){
  if(minHeap.size()==0){
    return true;
  }
  else{
    return false;
  }
}
