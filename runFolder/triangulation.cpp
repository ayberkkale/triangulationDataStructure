//
//  triangulation.cpp
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


#include <math.h>

#include <sys/time.h>
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
triangulation::triangulation(){// object constructor
    isDelaunaybool=false;
}
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
void triangulation::operator<<(ifstream& theFile) {//input File to Triangulation

     findCircumCentrePrintonScreen=true;// set true while init. of file, used for prevent Delaunay printing all the values on to the screen
   
       
    int l;
       for(int i=0;i<3;i++){
           theFile>>l;
           vertexInfo[i]=l;// read first line that has 3 elements into the vertex info array
           
       }
            vertexAmount_=vertexInfo[0];// eg. triangulation 1 = 1467 // set them to private variables as well
               vertexElementAmount_=vertexInfo[1];//3 for triangle
              vertexAttributeAmount_=vertexInfo[2];//0 for triangulation 1
    
      
       int vertexID;// element of vertex
       double vertexCoordX;// element of vertex
       double vertexCoordY;// element of vertex
       double vertexCoordZ;// element of vertex
       
       
     double k;
       
           for(int i=0;i<vertexInfo[0];i++){//no attributes
                  theFile>>vertexID>>vertexCoordX>>vertexCoordY>>vertexCoordZ; // read the line set to the variables
                  
              
                 vertices.push_back(vertex(vertexID, vertexCoordX, vertexCoordY, vertexCoordZ));// create a vertex object with constructor and push into the container vertices
        
               
               for(int j=0;j<vertexInfo[2]&&(vertexInfo[2]>0);j++){//if vertex with attributes
                   
                   theFile>>k;// read rest of the line
                   vertices[vertexID].setVertexAttributeVector(k);// set vertex attributes element by element using special function, this function pushes the data to a vector  VertexAttributeVector_ in vertex class element by element (friend private function only using while data reading from file)
                   
               }
               
              }
    
           if(vertexInfo[2]>0){// if vertex has attributes the file must have the attribute names after the vertex values before the start of triangles
                   char c [40];

                   theFile.getline(c, 40);
                   for(int i=0;i<vertexInfo[2];i++){
                   theFile.getline(c, 40);
                       verticesAttributeNames_.push_back(c);//read them into vertex attribute name container
    
                       
                   }
    
           }
       
       //VERTEX END
    
       int y;
 
       for(int i=0;i<3;i++){// read the line that has 3 elements into the triangles info array
           theFile>>y;
              triangleInfo[i]=y;
          }
     
     triangleAmount_=triangleInfo[0];// eg. triangulation 1 = 1467 // set them to private variables as well
     triangleElementAmount_=triangleInfo[1];//3 for triangle
     triangleAttributeAmount_=triangleInfo[2];//3 for triangle
    

       int TriangleID;// element of triangle
       int VertexIDofTriangle1;// element of triangle
       int VertexIDofTriangle2;// element of triangle
       int VertexIDofTriangle3;// element of triangle

    double z;
       for(int i=0;i<triangleInfo[0];i++){
           theFile>>TriangleID>>VertexIDofTriangle1>>VertexIDofTriangle2>>VertexIDofTriangle3;// read the line set to the variables
           
           
           
           triangles.push_back(triangle(TriangleID, VertexIDofTriangle1, VertexIDofTriangle2, VertexIDofTriangle3));// create a triangle object with constructor and push into the container triangles
           for(int j=0;j<triangleInfo[2]&&(triangleInfo[2]>0);j++){//with attributes
                     theFile>>z;

                triangles[TriangleID].setTriangleAttributeVector(z);// set triangle attributes element by element using special function, this function pushes the data to a vector  TrianglesAttributeVector_ in vertex class element by element (friend private function only using while data reading from file)
               
                 }
         
       
       }
    
       
    if(triangleInfo[2]>0){// if triangle has attributes the file must have the attribute names after the triangle values
            char c [40];
 
            theFile.getline(c, 40);
            for(int i=0;i<triangleInfo[2];i++){
            theFile.getline(c, 40);
                triangleAttributeNames_.push_back(c);//read them into triangle attribute name container
            
            }
    }

    
}
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
int triangulation:: getVertexAmount(){ // eg. triangulation 1 = 1467
    vertexAmount_=vertexInfo[0]; // make sure it is updated
    return vertexAmount_;
}
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

int triangulation:: getVertexElementAmount(){//3 for triangle
    vertexElementAmount_=vertexInfo[1]; // make sure it is updated
    return vertexElementAmount_;
}
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
int triangulation::getVertexAttributeAmount(){//0 for triangulation1
    vertexAttributeAmount_=vertexInfo[2]; // make sure it is updated
    return vertexAttributeAmount_;
}
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
int triangulation::getTriangleAmount(){// eg. triangulation 1 = 1467
    triangleAmount_=triangleInfo[0]; // make sure it is updated
    return triangleAmount_;
}
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
int triangulation::getTriangleElementAmount(){//3 for triangle
     triangleElementAmount_=triangleInfo[1]; // make sure it is updated
    return triangleElementAmount_;
}
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
int triangulation::getTriangleAttributeAmount(){//17 for triangulation1
     triangleAttributeAmount_=triangleInfo[2]; // make sure it is updated
    return triangleAttributeAmount_;
}
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

vector<vertex>& triangulation::getVerticesVector(){
    
    return vertices; // returns reference to the vertices container
}
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
vector<triangle>& triangulation::getTrianglesVector(){
    
    return triangles; // returns reference to the triangles container
}
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
void triangulation::addVertex(double x, double y,double z){// add vertex to vertices container , creates vertex object in operation
    
    if(vertexInfo[2]==0){// if vertex don't have attributes
    vertices.push_back(vertex(vertexInfo[0],x,y,z));// create new vertex object push into vertices container with the last ID
    vertexInfo[0]+=1;// increment ID amount
        cout<<"New vertex added ID, x, y, z: "<<vertices[vertexInfo[0]-1].getVertexId()<<" "<<vertices[vertexInfo[0]-1].getVertexCoordX()<<" "<<vertices[vertexInfo[0]-1].getVertexCoordY()<<" "<<vertices[vertexInfo[0]-1].getVertexCoordZ()<<endl; //print on screen
        cout<<"Total Vertices: "<<vertexInfo[0]<<endl;
    }else{
        
        cout<<"Use 'addVertexWithAttributes' Function Other Vertices have attributes"<<endl;
        
    }

}
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

void triangulation::addVertexWithAttributes(double x, double y,double z,double *AttributesArray){// add vertex to vertices container , creates vertex object in operation with attributes
    
    if(vertexInfo[2]>0){// if vertex has attributes
        vertices.push_back(vertex(vertexInfo[0],x,y,z));// create new vertex object push into vertices container with the last ID
             vertexInfo[0]+=1;// increment ID amount
   for(int i=0;i<vertexInfo[2];i++){// read the given attributes array to function
   
            vertices[vertices.size()-1].setVertexAttributeVector(AttributesArray[i]);// set attributes element by element(private friend function)

       }
        cout<<"New vertex added ID, x, y, z, attributes: "<<vertices[vertexInfo[0]-1].getVertexId()<<" "<<vertices[vertexInfo[0]-1].getVertexCoordX()<<" "<<vertices[vertexInfo[0]-1].getVertexCoordY()<<" "<<vertices[vertexInfo[0]-1].getVertexCoordZ()<<" , ";
        for(int j=0;j<vertexInfo[2];j++){
            
            cout<<vertices[vertexInfo[0]-1].getVertexAttributesVector()[j]<<" ";
            
        }
        
        
        cout<<endl;//print on screen
        cout<<"Total Vertices: "<<vertexInfo[0]<<endl;
    }else{
        
        cout<<"Use 'addVertex' Function Other Vertices doesn't have attributes"<<endl;
        
    }
    

}

/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
void triangulation::addTriangleWithAttributes(int VertexID1, int VertexID2,int VertexID3,double *triangleAttributesArray){// add triangle to triangles container,creates triangle object in operation with attributes
    
     if(((VertexID3<vertexInfo[0])+(VertexID2<vertexInfo[0])+(VertexID1<vertexInfo[0]))==3){// check given IDs are in vertexamount
        if((VertexID1!=VertexID2)&&(VertexID1!=VertexID3)&&(VertexID2!=VertexID3)){
                    if(triangleInfo[2]>0){// if triangle has attributes
                        triangles.push_back(triangle(triangleInfo[0], VertexID1, VertexID2, VertexID3));// create new triangle object push into triangles container with the last ID
                            triangleInfo[0]+=1;// increment ID amount
                    for(int i=0;i<triangleInfo[2];i++){// read the given attributes array to function
                        triangles[triangles.size()-1].setTriangleAttributeVector(triangleAttributesArray[i]);// set attributes element by element(private friend function)
                            

                        }
                        cout<<"New Triangle added ID, VertexID1, VertexID2, VertexID3, Attributes: "<<triangles[triangleInfo[0]-1].getTriangleID()<<" "<<triangles[triangleInfo[0]-1].getVertexIDofTriangle1()<<" "<<triangles[triangleInfo[0]-1].getVertexIDofTriangle2()<<" "<<triangles[triangleInfo[0]-1].getVertexIDofTriangle3()<<" , ";
                        for(int j=0;j<triangleInfo[2];j++){
                            
                            cout<<triangles[triangleInfo[0]-1].getTriangleAttributesVector()[j]<<" ";
                            
                        }
                        
                        //print on screen
                        cout<<endl;
                        cout<<"Total Triangles: "<<triangleInfo[0]<<endl;

                    }else{
                            
                            cout<<"Use 'addTriangle' Function Other Triangles doesn't have attributes"<<endl;
                            

                    }
              }else{
                  
                  cout<<"You cannot use the same vertex multiple times"<<endl;
                   
              }
    
     }else{
         
         cout<<"Use vertices in the triangulation!, Max Vertex ID Can Be Used:"<<vertexInfo[0]-1<<endl;
         
     }
    
}
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
void triangulation::addTriangle(int VertexID1, int VertexID2,int VertexID3){// add triangle to triangles container,creates triangle object in operation

    
     if(((VertexID3<vertexInfo[0])+(VertexID2<vertexInfo[0])+(VertexID1<vertexInfo[0]))==3){// check given IDs are in vertexamount
         if((VertexID1!=VertexID2)&&(VertexID1!=VertexID3)&&(VertexID2!=VertexID3)){
            if(triangleInfo[2]==0){
                  triangles.push_back(triangle(triangleInfo[0], VertexID1, VertexID2, VertexID3));// create new triangle object push into triangles container with the last ID
                       triangleInfo[0]+=1;// increment ID amount
        
                  cout<<"New Triangle added ID, VertexID1, VertexID2, VertexID3: "<<triangles[triangleInfo[0]-1].getTriangleID()<<" "<<triangles[triangleInfo[0]-1].getVertexIDofTriangle1()<<" "<<triangles[triangleInfo[0]-1].getVertexIDofTriangle2()<<" "<<triangles[triangleInfo[0]-1].getVertexIDofTriangle3()<<endl;
                  cout<<"Total Triangles: "<<triangleInfo[0]<<endl; //print on screen
              }else{
                  
                  cout<<"Use 'addTriangleWithAttributes' Function Other Triangles have attributes"<<endl;
                  
              }
        }else{

            cout<<"You cannot use the same vertex multiple times"<<endl;

        }
     }else{
         
         cout<<"Use vertices in the triangulation!, Max Vertex ID Can Be Used:"<<vertexInfo[0]-1<<endl;
        
         
     }
    
}
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

void triangulation::operator>>(ofstream& theoutput){//Triangulation to output File

    
    for(int i=0;i<2;i++){
        theoutput<<vertexInfo[i]<<" ";// write first line that has 3 elements from the vertex info array
    }
    theoutput<<vertexInfo[2]<<endl;
    
    for(int i=0;i<vertexInfo[0];i++){// write the line read to the variables of object in the container
     
           theoutput<<vertices[i].getVertexId()<<" "<<vertices[i].getVertexCoordX()<<" "<<vertices[i].getVertexCoordY()<<" "<<vertices[i].getVertexCoordZ();
           
        for(int j=0;j<vertexInfo[2]&&(vertexInfo[2]>0);j++){//with attributes
          

            theoutput<<" "<<vertices[i].getVertexAttributesVector()[j];
            // write attributes if any
        }
  
         theoutput<<endl;
       
    }
    for(int i=0;i<vertexInfo[2]&&(vertexInfo[2]>0);i++){
           theoutput<<verticesAttributeNames_[i]<<endl;//write attribute names if any
       }

    for(int i=0;i<2;i++){// write the line that has 3 elements from the triangles info array
          theoutput<<triangleInfo[i]<<" ";
      }
      theoutput<<triangleInfo[2]<<endl;
    
    for(int i=0;i<triangleInfo[0];i++){// write the line read to the variables of object in the container

    theoutput<<triangles[i].getTriangleID()<<" "<<triangles[i].getVertexIDofTriangle1()<<" "<<triangles[i].getVertexIDofTriangle2()<<" "<<triangles[i].getVertexIDofTriangle3();
    
     for(int j=0;j<triangleInfo[2]&&(triangleInfo[2]>0);j++){//with attributes
         
         theoutput<<" "<<triangles[i].getTriangleAttributesVector()[j];
        // write attributes if any
     }
      
        theoutput<<endl;
    }
    for(int i=0;i<triangleInfo[2]&&(triangleInfo[2]>0);i++){// write attributes names if any
        theoutput<<triangleAttributeNames_[i]<<endl;
    }
 
}



/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
double triangulation::areaOfTriangle(double x1, double y1, double x2, double y2, double x3, double y3){// find area of triangles with 3 points' coordinates
    
  
        return fabs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))*0.500);//area of a Triangle by formula (Coordinate Geometry)
    
}

/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
double triangulation::findContainingTriangle(double x, double y){//is a point inside a triangle
    double ANStriangleID=-1;
    // can be parallelized
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;
    
      double A;
      double A1;
      double A2;
      double A3;
    
    for(int i=0;i<triangleInfo[0];i++){// do for all triangles
        
        x1=(vertices[(triangles[i].getVertexIDofTriangle1())].getVertexCoordX()); // get triangle i'th x1
        y1=(vertices[(triangles[i].getVertexIDofTriangle1())].getVertexCoordY());// get triangle i'th y1
        x2=(vertices[(triangles[i].getVertexIDofTriangle2())].getVertexCoordX());// get triangle i'th x2
        y2=(vertices[(triangles[i].getVertexIDofTriangle2())].getVertexCoordY());// get triangle i'th y2
        x3=(vertices[(triangles[i].getVertexIDofTriangle3())].getVertexCoordX());// get triangle i'th x3
        y3=(vertices[(triangles[i].getVertexIDofTriangle3())].getVertexCoordY());// get triangle i'th y3
        
        A =  areaOfTriangle (x1, y1, x2, y2, x3, y3);//calcuate total area of the triangle
        A1 = areaOfTriangle (x, y, x2, y2, x3, y3);//calcuate area of the triangle with vertex POINT , 2, 3
        A2 = areaOfTriangle (x1, y1, x, y, x3, y3);//calcuate area of the triangle with vertex 1, POINT, 3
        A3 = areaOfTriangle (x1, y1, x2, y2, x, y);//calcuate area of the triangle with vertex  1 , 2, POINT

        //   Check if sum of A1, A2 and A3 is same as A
         //   Check if sum of (A1, A2 and A3+A)/2 is same as A if same it is inside the triangle
        if((float)A == ((float)( A + A1 + A2 + A3)*0.50)){// decrease precision to float to get rid of small inperfect calculation
            
            ANStriangleID=triangles[i].getTriangleID(); // return that triangle ID
   
        }
        
    }
    
    cout<<"Point ("<<x<<" , "<<y<<") is in triangle number: "<< ANStriangleID<<endl; // print that triangle ID to screen
    return ANStriangleID;
}

/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
vector<double> triangulation::findCircumCentrebyCoordinates(double x1, double y1, double x2, double y2, double x3, double y3){// finds a circumcircle Ox,Oy.Or of a triangle with coordinates
    
    
    vector<double> answer;
    answer.clear();
    double circumCentreX(0);// ox
    double circumCentreY(0);//oy
    double circumRadiusR(0);//r

    
    /*
       Matrix B      Matrix A    Circum Data Matrix
     |x1^2+y1^2|     |x1 y1 1|     |      2*Ox   |
     |x2^2+y2^2| =   |x2 y2 1| *   |      2*Oy   |
     |x3^2+y3^2|     |x3 y3 1|     |R^2-Ox^2-Oy^2|
     
     
    "INVERSE_A * B = Circum Data Matrix"

     multiple(product): inverse_matrixA * matrix B = get the Circumdata Matrix
     */
    double detA=x1*y2-x1*y3-x2*y1+x2*y3+y1*x3-x3*y2;// calculate the determinant of matrix to make sure it has inverse
   
    Delaunay_determinant=detA;// triangles has to have circumcircles so has to have a non zero determinant
    
    double invA_row1[3]={(y2-y3)/detA,(y3-y1)/detA,(y1-y2)/detA}; // calculate the inverse matrix row 1
    
    double invA_row2[3]={(x3-x2)/detA,(x1-x3)/detA,(x2-x1)/detA};// calculate the inverse matrix row 2
    
    double invA_row3[3]={(x2*y3-y2*x3)/detA,(y1*x3-x1*y3)/detA,(x1*y2-y1*x2)/detA};// calculate the inverse matrix row 3

        
    double matrixB_row1=x1*x1+y1*y1;// calculate matrix B ROW 1
    double matrixB_row2=x2*x2+y2*y2;// calculate matrix B ROW 1
    double matrixB_row3=x3*x3+y3*y3;// calculate matrix B ROW 1
    
    double matrixB[3]={matrixB_row1,matrixB_row2,matrixB_row3};
    
    for(int i=0;i<3;i++){
        
        circumCentreX+=(invA_row1[i]*matrixB[i])*0.5; // calculate Circum Data Matrix row1 /2 = Ox
        
    }
    
    for(int i=0;i<3;i++){
           
           circumCentreY+=(invA_row2[i]*matrixB[i])*0.5; // calculate Circum Data Matrix row2 /2 = Oy
           
    }
       
    double temp=0;
    
    for(int i=0;i<3;i++){
           
           temp+=(invA_row3[i]*matrixB[i]); // calculate Circum Data Matrix row3
           
    }

    circumRadiusR=sqrt(temp+(circumCentreX*circumCentreX)+(circumCentreY*circumCentreY));// calculate Or from the Circum Data Matrix row3
    
    answer.push_back(circumCentreX);answer.push_back(circumCentreY);answer.push_back(circumRadiusR); // contain this calculation in a vector return this
        
   
    if(containCalculatedCCincircumCircleDataVector)  circumCircleData.push_back(answer); //means if user calls this function won't mess up with triangulation's vector for delaunay
        
    if(findCircumCentrePrintonScreen) cout<<"circumCentre x is: "<<circumCentreX<<", circumCentre y is: "<<circumCentreY<<", circumRadiusR is: "<<circumRadiusR<<endl;

    return answer;
}
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
vector<double>triangulation::findCircumCentrebyTriangleID(int TriangleNo){// finds a circumcircle Ox,Oy.Or of a triangle in the triangulation
    
    // can be parallelized
    vector<double> answer;
 double x1;
 double y1;
 double x2;
 double y2;
 double x3;
 double y3;
    
    x1=(vertices[(triangles[TriangleNo].getVertexIDofTriangle1())].getVertexCoordX()); // get triangle i'th x1
    y1=(vertices[(triangles[TriangleNo].getVertexIDofTriangle1())].getVertexCoordY());// get triangle i'th y1
    x2=(vertices[(triangles[TriangleNo].getVertexIDofTriangle2())].getVertexCoordX());// get triangle i'th x2
    y2=(vertices[(triangles[TriangleNo].getVertexIDofTriangle2())].getVertexCoordY());// get triangle i'th y2
    x3=(vertices[(triangles[TriangleNo].getVertexIDofTriangle3())].getVertexCoordX());// get triangle i'th x3
    y3=(vertices[(triangles[TriangleNo].getVertexIDofTriangle3())].getVertexCoordY());// get triangle i'th y3
    
    answer=findCircumCentrebyCoordinates( x1,  y1,  x2,  y2,  x3,  y3); // finds a circumcircle Ox,Oy.Or of a triangle send the coordinates
    
    
    return answer;
}


/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
void triangulation::findContainingCircumCircleforVertex(int myvertexID){//only gives vertices that not owned by that triangles
    
    //the point is inside the circle if d<r, on the circle if d=r, and outside the circle if  d>r
        
    double dtop1;

    double r;
    
    bool check1=0;
    bool check2=0;
    bool check3=0;
    for(int i=0;i<circumCircleData.size();i++){// do all triangles // can be parallelized
        
       
        check1=(myvertexID==triangles[i].getVertexIDofTriangle1());// make sure the vertex is not the vertex of actual circumcircle triangle's vertex
        check2=(myvertexID==triangles[i].getVertexIDofTriangle2());// make sure the vertex is not the vertex of actual circumcircle triangle's vertex
        check3=(myvertexID==triangles[i].getVertexIDofTriangle3());// make sure the vertex is not the vertex of actual circumcircle triangle's vertex
        int totalcheck=check1+check2+check3;// if this is zero it is not triangles own vertex otherwise it is
        
        
        dtop1=((vertices[myvertexID].getVertexCoordX()-circumCircleData[i][0])*(vertices[myvertexID].getVertexCoordX()-circumCircleData[i][0]))+((vertices[myvertexID].getVertexCoordY()-circumCircleData[i][1])*(vertices[myvertexID].getVertexCoordY()-circumCircleData[i][1]));// distance between two points Ox,Oy and vertex X,Y
       
        
       
        r=circumCircleData[i][2];
       
        if( (sqrt(dtop1)<=r)) {    //the vertex is inside the circle if d<r, on the circle if d=r
  
            if(totalcheck==0) {// make sure the vertex is not the vertex of actual circumcircle triangle's vertex
                cout<<"Triangle ID "<<i<<" has the inserceting vertex ID inside its circumcircle: "<<myvertexID<<endl;
                isDelaunaybool=false;
            }
   
        }

    }


    
}
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
void triangulation::createCircumcircleData(){//create circumcircle data if user want to use function:findCircumCentrebyTriangleID, findCircumCentrebyCoordinates, findContainingCircumCircleforVertex
        
        Delaunay_determinant=1;
        findCircumCentrePrintonScreen=false;
     
            containCalculatedCCincircumCircleDataVector=true;
        if(circumCircleData.empty()){
                for(int i=0;i<triangleInfo[0]&&Delaunay_determinant!=0;i++){
                    

                    findCircumCentrebyTriangleID(i);// circumcirc vector

                }

        }else{
        circumCircleData.clear();
                for(int i=0;i<triangleInfo[0]&&Delaunay_determinant!=0;i++){
                    

                    findCircumCentrebyTriangleID(i);// circumcirc vector

                }
        
        }
        

}

        
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

void triangulation::printCircumCentreInfo(){// to print all circum_circle data_to_screen
    findCircumCentrePrintonScreen=false;
    cout<<"TriangleID Cx Cy Cr"<<endl;
        vector<double> temp;
    for(int i=0;i<triangles.size();i++){
        
        temp=findCircumCentrebyTriangleID(i); // calculate the OX,OY,OR
        cout<<i<<" ";
        for(int j=0;j<3;j++){
            cout<<temp[j]<<" ";//print to screen
        }
        
        cout<<endl;
    }
    findCircumCentrePrintonScreen=true;
    
}

/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

bool triangulation::isDelaunay() {//bool printTheIntersectingValuesonScreen
         
        findCircumCentrePrintonScreen=false;// print the circumcircle on screen false for internal usage
        
    if(circumCircleData.empty()) createCircumcircleData();// calculate the circumcircles if not already
    
    
    isDelaunaybool=true;// answer boolean set true assumption
        
        struct timeval start_time,end_time;//timer
        gettimeofday(&start_time,NULL);//timer
    
    for(int i=0;i<vertices.size();i++){// can be parallelized
        findContainingCircumCircleforVertex(vertices[i].getVertexId()); // use the function send each vertex to compare
    }
        
    gettimeofday(&end_time,NULL);//timer ended
    
        double time=(end_time.tv_sec - start_time.tv_sec+(end_time.tv_usec-start_time.tv_usec)/1e6); // time to find
        
    
    
    
    if(isDelaunaybool==false){
        cout<<"Triangulation is not delaunay"<<endl;
    }else{
         cout<<"Triangulation is delaunay"<<endl;
    }

    
    cout<<endl<<"Time to check each vertices in circumcircle of a triangle for the triangulation has took: "<<time<<"s"<<endl;
     
    findCircumCentrePrintonScreen=true;// print the circumcircle on screen true for later user usage
        
    containCalculatedCCincircumCircleDataVector=false;//for user usage don't contain anymore circumcircle calculation in other function calls
        
    return isDelaunaybool;
    
}
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
vector<double> triangulation::findVertexOwnedTrianglesinTriangulation(int VertexID){// Find  which Triangle  has specific vertex

        vector<double> answer;
        
        for(int i=0;i<triangleInfo[0];i++){// for all triangles // can be parallelized
            
                       
            if(triangles[i].getVertexIDofTriangle1()==VertexID){// search all vertices of triangles for each vertex
    
                    answer.push_back(i);
        
                    cout<<"Triangle ID "<<i<<" has the vertex ID: "<<VertexID<<endl;
        
            }else if(triangles[i].getVertexIDofTriangle2()==VertexID){
        
                     answer.push_back(i);
                           
                    cout<<"Triangle ID "<<i<<" has the vertex ID: "<<VertexID<<endl;
            
            }else if(triangles[i].getVertexIDofTriangle3()==VertexID){
            
            
                    answer.push_back(i);
                           
                    cout<<"Triangle ID "<<i<<" has the vertex ID: "<<VertexID<<endl;
            
            }
                           
                       
                   
            
        
        }
        
        
        return answer;
}
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

void triangulation::printVertexInfoofID_toScreen(int desiredVertexID){// prints specific vertex info to screen
    
    cout<<vertices[desiredVertexID].getVertexId()<<" "<<vertices[desiredVertexID].getVertexCoordX()<<" "<<vertices[desiredVertexID].getVertexCoordY()<<" "<<vertices[desiredVertexID].getVertexCoordZ();// get the data prints to screen
    
 for(int j=0;j<vertexInfo[2]&&(vertexInfo[2]>0);j++){//with attributes if any
     
     cout<<" "<<vertices[desiredVertexID].getVertexAttributesVector()[j];

 }
    cout<<endl;
}
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
void triangulation::printTriangleInfoofID_toScreen(int desiredTriangleID){// prints specific triangle info to screen
    
     cout<<triangles[desiredTriangleID].getTriangleID()<<" "<<triangles[desiredTriangleID].getVertexIDofTriangle1()<<" "<<triangles[desiredTriangleID].getVertexIDofTriangle2()<<" "<<triangles[desiredTriangleID].getVertexIDofTriangle3();// get the data prints to screen
    
     for(int j=0;j<triangleInfo[2]&&(triangleInfo[2]>0);j++){//with attributes if any
         cout<<" "<<triangles[desiredTriangleID].getTriangleAttributesVector()[j];

     }
    
    cout<<endl;

}
    /*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

