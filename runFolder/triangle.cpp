//
//  triangle.cpp
//  Triangulation Program
//
//  Created by M. Ayberk Kale - Autumn 2019 - EEEE3084
//  20203736 The University of Nottingham - Department of EEE
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using std::vector;

#include "vertex.h"
#include "triangle.h"
#include "triangulation.h"

triangle::triangle(int TriangleID, int VertexIDofTriangle1,int VertexIDofTriangle2,int VertexIDofTriangle3):
TriangleID_(TriangleID),VertexIDofTriangle1_(VertexIDofTriangle1),VertexIDofTriangle2_(VertexIDofTriangle2),VertexIDofTriangle3_(VertexIDofTriangle3){// constructor
    

    
}

//getter
int triangle::getTriangleID(){// get triangle ID
    return TriangleID_;
}

int triangle::getVertexIDofTriangle1(){// get getVertexIDofTriangle1
    return VertexIDofTriangle1_;
}

int triangle::getVertexIDofTriangle2(){// get getVertexIDofTriangle2
    return VertexIDofTriangle2_;
}

int triangle::getVertexIDofTriangle3(){// get getVertexIDofTriangle3
    return VertexIDofTriangle3_;
}

vector<double>& triangle::getTriangleAttributesVector(){// get reference to Triangle Attributes Vector
    
    
    return TriangleAttributeVector_;
    
}

//setter
void triangle::setTriangleID(int TriangleID){// set triangle ID
    
    TriangleID_=TriangleID;
    
}
void triangle::setVertexIDofTriangle1(int VertexIDofTriangle1){// set vertex ID 1 of triangle
    
    VertexIDofTriangle1_=VertexIDofTriangle1;
    
}
void triangle::setVertexIDofTriangle2(int VertexIDofTriangle2){// set vertex ID 2 of triangle
    
    VertexIDofTriangle2_=VertexIDofTriangle2;
    
}
void triangle::setVertexIDofTriangle3(int VertexIDofTriangle3){// set vertex ID 3 of triangle
    
    VertexIDofTriangle3_=VertexIDofTriangle3;
    
}



void triangle::setTriangleAttributeVectorElement(int AttributeID,double DesiredValue) {// user can use this to specify a element of attribute vector
 
   
    TriangleAttributeVector_[AttributeID]=DesiredValue;
    
    
}

void triangle::setTriangleAttributeVector(double attribute){//attribute vector init. for each object while reading from file or creating new object , friend triangulation class uses
    
 
    TriangleAttributeVector_.push_back(attribute);// push each element to to attribute vector element by element
    
    
}
