//  File Name: Node.cpp
//  Created by Vaibhav Vijay on 2013-10-13.
//  Copyright (c) 2013 Vaibhav Vijay. All rights reserved.
//  Last updated: October 2013
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Node.h"
#include "Resistor.h"

extern Resistor *arrayResistor; //1//Provides access to global Node array declared in the Rparser.cpp file
using namespace std;
#define MAX_RESISTORS_PER_NODE 5

//Contructor: initialises everything to 0
Node :: Node()
{
    numRes = 0;

}
//Mutator to add the resistor index of the resistor connected to a node
//Returns true if not full
bool Node::addResistor (int rIndex)
{

    if(numRes>=MAX_RESISTORS_PER_NODE)
    {
        cout<<"Error: node is full"<<endl;
        return false;
    }
    else
    {
        resIDArray[numRes] = rIndex;
        return true;
    }

}
//Mutator to print the details of the resistors connected to a node
void Node::print(int NodeIndex)
{
    cout<<"Connections at node "<<NodeIndex<<": "<<numRes<<" resistor(s)"<<endl;
    for(int i =0; i<numRes ; i++)
    {
        int x;
        cout<<"  ";
        x = resIDArray[i];
        arrayResistor[x].print();
    }

}

//Mutator to count the number of resistors connected to a node
void Node::Resnum()
{
    numRes++;
}
//Mutator to initialize everything to zero
void Node::deleteN()
{
    int i;
    numRes = 0;
    for(i =0; i<MAX_RESISTORS_PER_NODE ; i++)
    {
        resIDArray[i] = 0 ;
    }
}

Node::~Node()
{

}
