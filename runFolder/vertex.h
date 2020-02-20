//
//  vertex.h
//  Triangulation Program
//
//  Created by M. Ayberk Kale - Autumn 2019 - EEEE3084
//  20203736 The University of Nottingham - Department of EEE
//

#ifndef vertex_h
#define vertex_h
class vertex{
    
public:
    vertex(int VertexID, double vertexX,double vertexY,double vertexZ);//constructor
    
 
    //getter
    int getVertexId();// get vertex ID
    double getVertexCoordX();// get x coordinate of vertex
    double getVertexCoordY();// get y coordinate of vertex
    double getVertexCoordZ();// get x coordinate of vertex
    vector<double>& getVertexAttributesVector();// get eference to Vertex Attributes Vector of vertex
   
   //setter
    
   void setVertexId(int ID);// set vertex ID
   void setVertexCoordX(double coordX);// set x coordinate of vertex
   void setVertexCoordY(double coardY);// set y coordinate of vertex
   void setVertexCoordZ(double coardZ);// set z coordinate of vertex
   void setVertexAttributeVectorElement(int AttributeID,double DesiredValue);// user can use this to specify a element of attribute vector
 
    
private:
    int VertexID_;// private vertex ID
    double vertexX_;// private x coordinate of vertex
    double vertexY_;// private y coordinate of vertex
    double vertexZ_;// private z coordinate of vertex
    
    vector<double> VertexAttributeVector_;//attribute vector for each object
    friend class triangulation;
     void setVertexAttributeVector(double attribute);//attribute vector init. for each object while reading from file or creating new object ,friend triangulation class uses
    
};

#endif /* vertex_h */
