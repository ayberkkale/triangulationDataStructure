//
//  triangle.h
//  Triangulation Program
//
//  Created by M. Ayberk Kale - Autumn 2019 - EEEE3084
//  20203736 The University of Nottingham - Department of EEE
//

#ifndef triangle_h
#define triangle_h

class triangle{
    
public:
 
    triangle(int TriangleID, int VertexIDofTriangle1,int VertexIDofTriangle2,int VertexIDofTriangle3);// constructor
    
    //getter
    int getTriangleID();// get triangle ID
    int getVertexIDofTriangle1();// get getVertexIDofTriangle1
    int getVertexIDofTriangle2();// get getVertexIDofTriangle2
    int getVertexIDofTriangle3();// get getVertexIDofTriangle3
    vector<double>& getTriangleAttributesVector();// get reference to Triangle Attributes Vector
    
   //setter
   void setTriangleID(int TriangleID);// set triangle ID
   void setVertexIDofTriangle1(int VertexIDofTriangle1);// set vertex ID 1 of triangle
   void setVertexIDofTriangle2(int VertexIDofTriangle2);// set vertex ID 2 of triangle
   void setVertexIDofTriangle3(int VertexIDofTriangle3);// set vertex ID 3 of triangle
    
   void setTriangleAttributeVectorElement(int AttributeID,double DesiredValue);// user can use this to specify a element of attribute vector
 
    

    
    
    
private:
    int TriangleID_;// private triangle ID
    int VertexIDofTriangle1_;// private vertex ID 1 of triangle
    int VertexIDofTriangle2_;// private vertex ID 1 of triangle
    int VertexIDofTriangle3_;// private vertex ID 1 of triangle

    vector<double> TriangleAttributeVector_;//attribute vector for each object
    friend class triangulation;
     void setTriangleAttributeVector(double attribute);//attribute vector init. for each object while reading from file or creating new object ,friend triangulation class uses
    
    
    
    
};

#endif /* triangle_h */
