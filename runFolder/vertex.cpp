//
//  vertex.cpp
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

#include "triangle.h"
#include "vertex.h"
#include "triangulation.h"

vertex::vertex(int VertexID, double vertexX,double vertexY,double vertexZ):
VertexID_(VertexID),vertexX_(vertexX),vertexY_(vertexY),vertexZ_(vertexZ){//constructor
    
    
}

//getter

int vertex::getVertexId(){// get vertex ID
    
    return VertexID_;

}

double vertex::getVertexCoordX(){// get x coordinate of vertex
    
    return vertexX_;

}

double vertex::getVertexCoordY(){// get y coordinate of vertex
    
    return vertexY_;

}

 double vertex::getVertexCoordZ(){// get x coordinate of vertex
     
     return vertexZ_;

 }
vector<double>& vertex::getVertexAttributesVector(){// get eference to Vertex Attributes Vector of vertex
    
 
    return VertexAttributeVector_;
}



//setter

void vertex::setVertexId(int ID){// set vertex ID
    
    VertexID_=ID;
    

}

void vertex::setVertexCoordX(double coordX){// set x coordinate of vertex
    
    vertexX_=coordX;

}

void vertex::setVertexCoordY(double coardY){// set y coordinate of vertex
    
   vertexY_=coardY;

}

 void vertex::setVertexCoordZ(double coardZ){// set z coordinate of vertex
     
    vertexZ_=coardZ;

 }

void vertex::setVertexAttributeVectorElement(int AttributeID,double DesiredValue){// user can use this to specify a element of attribute vector
 
   
    VertexAttributeVector_[AttributeID]=DesiredValue;
    
    
}

void vertex::setVertexAttributeVector(double attribute){ //attribute vector init. for each object while reading from file or creating new object ,friend triangulation class uses
    
    VertexAttributeVector_.push_back(attribute);
    
        
}
