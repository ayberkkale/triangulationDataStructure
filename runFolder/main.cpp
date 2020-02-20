//
//  Triangulation Program
//
//
//  Created by M. Ayberk Kale - Autumn 2019 - EEEE3084
//  20203736 The University of Nottingham - Department of EEE
//

#include <iostream>// input output stream
#include <fstream>// file stream
#include <string>
#include <vector>
using namespace std;
using std::vector;


#include <math.h>


#include "vertex.h"// vertex class
#include "triangle.h"// triangle class
#include "triangulation.h"// triangulation class




 //*---------FOR TEST 5----------------- *//

class myFunction {
      
  public:
  
  double operator()(double x,double y){
      //return sin(x)+cos(y);
      return 1;// declare your function the integrate here
  }
    
};
//*--------- END OF TEST 5----------------- *//

int main()
{
    //*-----------------------------------------------------TEST 1------------------------------------------------------ *//
    
    cout<<"\n*--------------------------Test 1 Read & Add Vertex and Print to A File--------------------------*\n"<<endl;
    ifstream myInputFile_test1("./triangulation#1.tri");//input file stream

    triangulation myTriangulation_test1;// create triangulation object
    myTriangulation_test1<<myInputFile_test1;// read file into triangulation
   myInputFile_test1.close();// close input file
    
   myTriangulation_test1.addVertex(140, 333, 1004);// without attributes give x,y,z coordinates ID will be given auto from the last ID+1
    myTriangulation_test1.addVertex(142, 331, 1004);// give x,y,z coordinates ID will be given auto from the last ID+1
     myTriangulation_test1.addVertex(143, 337, 1004);// give x,y,z coordinates ID will be given auto from the last ID+1
    
    
    ofstream theOutput_test1("./triangulation#1_output_test1.tri"); //output file stream
    
    myTriangulation_test1>>theOutput_test1;// print triangulation object to output file stream
    
    theOutput_test1.close();// close output file
    
    //*-----------------------------------------------------TEST 2------------------------------------------------------ *//
     cout<<"\n*--------------------------Test 2 Read & Add Triangle and Print to A File--------------------------*\n"<<endl;
    
     ifstream myInputFile_test2("./triangulation#1.tri");//input file stream
     
     triangulation myTriangulation_test2;// create triangulation object
     myTriangulation_test2<<myInputFile_test2;// read file into triangulation
    myInputFile_test2.close();// close input file
    
    double triangleAttributesValuesArray[17]={1, 1, 1, 10, 132756, 0 ,1 ,0 ,0, 0 ,0.921752 ,2335 ,0, 0, 1, 0, 0};// attribute array must be same as other triangles
     
     // give vertex ID1, ID2, ID3 and attribute array,
                                                                                                    //ID will be given auto from the last ID+1
    cout<<endl;
    
    myTriangulation_test2.addTriangleWithAttributes(1400, 100, 300, triangleAttributesValuesArray);// give vertex ID1, ID2, ID3 and attribute array,
                                                                                                        //ID will be given auto from the last ID+1
    
    cout<<"Don't try to add triangle with multiple occurence of same vertex"<<endl;
    myTriangulation_test2.addTriangleWithAttributes(1400,1400,200,triangleAttributesValuesArray); //not letting adding vertex multiple occur. 

     ofstream theOutput_test2("./triangulation#1_output_test2.tri");//output file stream
     
     myTriangulation_test2>>theOutput_test2;// print triangulation object to output file stream
     
     theOutput_test2.close();// close output file
    
    

     
     //*-----------------------------------------------------TEST 3------------------------------------------------------ *//
      cout<<"\n*--------------------------Test 3 Triangulation Read Change Vertex or Triangle Content & Print to A File--------------------------*\n"<<endl;
     
      ifstream myInputFile_test3("./triangulation#2.tri");//input file stream
      
      triangulation myTriangulation_test3;// create triangulation object
      myTriangulation_test3  <<  myInputFile_test3;// read file into triangulation
     myInputFile_test3.close();// close input file
     
        myTriangulation_test3.printVertexInfoofID_toScreen(2);// function that prints vertex's data to screen
    
        myTriangulation_test3.getVerticesVector()[2].setVertexCoordX(3);// how to change coordinate X of vertex: '2' is vertexID, '3' is the new set value
    
        myTriangulation_test3.getVerticesVector()[2].setVertexCoordY(32);// how to change coordinate Y of vertex: '2' is vertexID ,'32' is the new set value
    
        myTriangulation_test3.getVerticesVector()[2].setVertexCoordZ(1005);// how to change coordinate Z of vertex: '2' is vertexID, '1005' is the new set value
    
    
    cout<<myTriangulation_test3.getVerticesVector()[2].getVertexId()<<" " <<myTriangulation_test3.getVerticesVector()[2].getVertexCoordX()<<" " <<myTriangulation_test3.getVerticesVector()[2].getVertexCoordY()<<" " <<myTriangulation_test3.getVerticesVector()[2].getVertexCoordZ()<<" :Newly Set Values\n"<<endl; // how to get Vertex object data from triangulation class vertices vector container , ID of container and vertex ID is have to be same don't change ID if you don't know what to do
    
    
    
    myTriangulation_test3.printTriangleInfoofID_toScreen(41);// function that prints triangle's data to screen
    
    myTriangulation_test3.getTrianglesVector()[41].setVertexIDofTriangle1(44); // how to change  vertex ID 1 of triangle: '41' is trianleID, '44' is the new set vertex
    
    myTriangulation_test3.getTrianglesVector()[41].setVertexIDofTriangle2(49);// how to change  vertex ID 2 of triangle: '41' is trianleID, '49' is the new set vertex
    
    myTriangulation_test3.getTrianglesVector()[41].setVertexIDofTriangle3(51);// how to change  vertex ID 3 of triangle: '41' is trianleID, '51' is the new set vertex
    
    myTriangulation_test3.getTrianglesVector()[41].setTriangleAttributeVectorElement(4, 33561);// how to change one attribute of triangle: '41' is attribute ID, '33561' is the new set vertex
    
    cout<<myTriangulation_test3.getTrianglesVector()[41].getTriangleID()<<" " <<myTriangulation_test3.getTrianglesVector()[41].getVertexIDofTriangle1()<<" " <<myTriangulation_test3.getTrianglesVector()[41].getVertexIDofTriangle2()<<" " <<myTriangulation_test3.getTrianglesVector()[41].getVertexIDofTriangle3()<<" "; // how to get Triangle object data from triangulation class triangles vector container , ID of container and triangle ID is have to be same don't change ID if you don't know what to do
    
    for(int i=0;i<myTriangulation_test3.getTriangleAttributeAmount();i++){
        
        cout<<myTriangulation_test3.getTrianglesVector()[41].getTriangleAttributesVector()[i]<<" ";// get triangle object 41 from container of triangles ,get the reference of triangles attributes container of that object i'th element
    }
    cout<<":Newly set values"<<endl;
    
    

    string theOutput_test3_location="./triangulation#2_output_test3.tri";
    
      ofstream theOutput_test3(theOutput_test3_location.c_str()); //output file stream
      
      myTriangulation_test3>>theOutput_test3;// print triangulation object to output file stream
      
      theOutput_test3.close();// close output file
    
    cout<<"\nThe Triangulation Print Location: "<<theOutput_test3_location<<endl;
    
    
       //*-----------------------------------------------------TEST 4------------------------------------------------------ *//
        cout<<"\n*--------------------------Test 4 Triangulation isDelaunay by checking in Circumcircle--------------------------* \n"<<endl;
    
    
                                    //*-----------TEST 4 - Triangulation # 1------------- *//
       cout<<"\n *Triangulation #1 \n"<<endl;
        ifstream myInputFile_test4("./triangulation#1.tri");//**//
        
        triangulation myTriangulation_test4;// create triangulation object
        myTriangulation_test4  <<  myInputFile_test4;// read file into triangulation
       myInputFile_test4.close();// close input file
    
        bool triCheck1= myTriangulation_test4.isDelaunay(); // check if it delaunay returns boolean ,print to screen
    
        cout<<endl<<"Boolean for Checking Delaunay triangulation # 1: "<<triCheck1<<endl;
    

    
                                 //*-----------TEST 4 - Triangulation # 2------------- *//
        cout<<"\n Triangulation #2 \n"<<endl;
     ifstream myInputFile_test4_2("./triangulation#2.tri");//**//
     
     triangulation myTriangulation_test4_2;// create triangulation object
     myTriangulation_test4_2  <<  myInputFile_test4_2;// read file into triangulation
        myInputFile_test4_2.close();// close input file
     
     bool triCheck2= myTriangulation_test4_2.isDelaunay();// check if it delaunay returns boolean ,print to screen
     cout<<endl<<"Boolean for Checking Delaunay triangulation # 2: "<<triCheck2<<endl;
    
                                 //*-----------TEST 4 - Triangulation # 3------------- *//
    cout<<"\n Triangulation #3 \n"<<endl;
     ifstream myInputFile_test4_3("./triangulation#3.tri");//**//
     
     triangulation myTriangulation_test4_3;// create triangulation object
     myTriangulation_test4_3  <<  myInputFile_test4_3;// read file into triangulation
    myInputFile_test4_3.close();// close input file
     

     bool triCheck3= myTriangulation_test4_3.isDelaunay();// check if it delaunay returns boolean ,print to screen
    

     cout<<endl<<"Boolean for Checking Delaunay triangulation # 3: "<<triCheck3<<endl;

                                 //*-----------TEST 4 - Triangulation # 4------------- *//
    cout<<"\n Triangulation #4 \n"<<endl;
     ifstream myInputFile_test4_4("./triangulation#4.tri");//**//
     
     triangulation myTriangulation_test4_4;// create triangulation object
     myTriangulation_test4_4  <<  myInputFile_test4_4;// read file into triangulation
    myInputFile_test4_4.close();// close input file
     
     bool triCheck4= myTriangulation_test4_4.isDelaunay();// check if it delaunay returns boolean ,print to screen
    
     cout<<endl<<"Boolean for Checking Delaunay triangulation # 4: "<<triCheck4<<endl;
    
       
       //*-----------------------------------------------------TEST 5------------------------------------------------------ *//
        cout<<"\n*--------------------------Test 5 Integrate By Two Methods--------------------------*\n"<<endl;
       
        ifstream myInputFile_test5("./triangulation_test5_only_one_triangle.tri");
        
        triangulation myTriangulation_test5;// create triangulation object
        myTriangulation_test5  <<  myInputFile_test5;// read file into triangulation
       myInputFile_test5.close();// close input file

        cout<<"The Function is '1' which used with a triangulation with one triangle. Integration should be the area of that triangle.\n"<<endl;
    
            //0 -147.011 -2.06649 1004
            //1 -145.37 -1.86448 1004  // coordinates of the triangles
            // 2 -146.241 -3.3838 1004
    
        cout<<"Area of Triangle with these three vertices (0 -147.011 -2.06649 ,1 -145.37 -1.86448,2 -146.241 -3.3838) :"<<myTriangulation_test5.areaOfTriangle(-147.011, -2.06649, -145.37, -1.86448, -146.241, -3.3838)<<endl; // given coordinates of triangles
    
        myFunction A; // Function as a object myobject declared in Global Var.
    
        myTriangulation_test5.integrate_by_constant_value_approx(A); // integrate function object in the integration functor
      
        myTriangulation_test5.integrate_by_linear_interpolation_approx(A); // integrate function object in the integration functor
    
    //*-----------------------------------------------------TEST 6------------------------------------------------------ *//
        cout<<"\n*--------------------------Test 6 Given a Point x,y Find which triangle contains it--------------------------*\n"<<endl;

        ifstream myInputFile_test6("./triangulation#1.tri");

        triangulation myTriangulation_test6;// create triangulation object

        myTriangulation_test6  <<  myInputFile_test6;// read file into triangulation

        myInputFile_test6.close();// close input file
       
        int containingTriangleID1 = myTriangulation_test6.findContainingTriangle(181, -17.5);// give x,y should be in triangle 2619
        cout<<"The Return Triangle ID of the Function: "<<containingTriangleID1<<endl;

    
        int containingTriangleID2 =myTriangulation_test6.findContainingTriangle(-82, -5.85);// give x,y should be in triangle 157
        cout<<"The Return Triangle ID of the Function: "<<containingTriangleID2<<endl;
    
    //*-----------------------------------------------------TEST 7------------------------------------------------------ *//
     cout<<"\n*--------------------------Test 7 Find Circumcircle of a Triangle or Coordinate --------------------------*\n"<<endl;

     ifstream myInputFile_test7("./triangulation#1.tri");

     triangulation myTriangulation_test7;// create triangulation object

     myTriangulation_test7  <<  myInputFile_test7;// read file into triangulation

     myInputFile_test7.close();// close input file
    
    int desired_triangle_ID=100;
    
    vector<double> myTriangleCircumCircle = myTriangulation_test7.findCircumCentrebyTriangleID(desired_triangle_ID);// give a triangle ID returns vector
    
    cout<<endl<<"The return from the function of a triangleID Ox Oy Or:"<<desired_triangle_ID<<" "<<myTriangleCircumCircle[0]<<" "<<myTriangleCircumCircle[1]<<" "<<myTriangleCircumCircle[2]<<endl<<endl; // print the values of return vector
    
     vector<double> aTriangleCircumCircleData = myTriangulation_test7.findCircumCentrebyCoordinates(100, 200, 300, 500, 600, 200); // give coordinates returns vector
                                                                                                    //x1,y1,x2,y2,x3,y3
    //myTriangulation_test7.printCircumCentreInfo(); // to print all circum_circle data_to_screen
    
    //*-----------------------------------------------------TEST 8------------------------------------------------------ *//
    cout<<"\n*--------------------------Test 8 Find  which Triangle's circumcircle has a vertex (only intersecting not owned ones)--------------------------*\n"<<endl;

    ifstream myInputFile_test8("./triangulation#1.tri");

    triangulation myTriangulation_test8;// create triangulation object

    myTriangulation_test8  <<  myInputFile_test8;// read file into triangulation

    myInputFile_test8.close();// close input file
    
    myTriangulation_test8.createCircumcircleData();// in order to use find in circumcircle function create the circumcircle data for triangles

    myTriangulation_test8.findContainingCircumCircleforVertex(309); // give and ID
    
   
    
    //*-----------------------------------------------------TEST 9------------------------------------------------------ *//
    cout<<"\n*--------------------------Test 9 Find  which Triangle  has specific vertex --------------------------*\n"<<endl;

    ifstream myInputFile_test9("./triangulation#1.tri");

    triangulation myTriangulation_test9;// create triangulation object

    myTriangulation_test9  <<  myInputFile_test9;// read file into triangulation

    myInputFile_test9.close();// close input file
    
    vector<double> triangle_IDs = myTriangulation_test9.findVertexOwnedTrianglesinTriangulation(1253); // give a vertex ID, looks all vertices of triangles
    cout<<endl;
    cout<<"Return values of function: ";
    for(int i=0;i<triangle_IDs.size();i++){
        cout<<triangle_IDs[i]<<" ";// print the given result
    }
    cout<<endl;
    
    //*-----------------------------------------------------TEST 10------------------------------------------------------ *//
        
        cout<<"\n*--------------------------Test 10 Vertex Attribute & Triangle Non Attribute Test --------------------------*\n"<<endl;
     
    ifstream myInputFile_test10("./triangulation_vertex_with_attributes_test10.tri");
     
    triangulation myTriangulationforVertexAttributes_test10;// create triangulation object
    
    myTriangulationforVertexAttributes_test10<<myInputFile_test10;// read file into triangulation
    
     myInputFile_test10.close();// close input file
    
    
   double VertexAttributesValuesArray[3]={16,18,13};// attribute array must be same as other vertices
   
    myTriangulationforVertexAttributes_test10.addVertexWithAttributes(140, 333, 1004, VertexAttributesValuesArray);// without attributes give x,y,z coordinates and attribute array,
                                                                                                                    //ID will be given auto from the last ID+1
 
    myTriangulationforVertexAttributes_test10.getVerticesVector()[myTriangulationforVertexAttributes_test10.getVertexAmount()-1].setVertexAttributeVectorElement(1, 319);
    // change attribute ID '1' to '319' from '333'
    
    cout<<"Change the vertex attribute function(setVertexAttributeVectorElement) ";
    cout<<myTriangulationforVertexAttributes_test10.getVerticesVector()[myTriangulationforVertexAttributes_test10.getVertexAmount()-1].getVertexId()<<" " <<myTriangulationforVertexAttributes_test10.getVerticesVector()[myTriangulationforVertexAttributes_test10.getVertexAmount()-1].getVertexCoordX()<<" " <<myTriangulationforVertexAttributes_test10.getVerticesVector()[myTriangulationforVertexAttributes_test10.getVertexAmount()-1].getVertexCoordY()<<" " <<myTriangulationforVertexAttributes_test10.getVerticesVector()[myTriangulationforVertexAttributes_test10.getVertexAmount()-1].getVertexCoordZ()<<" "; // how to get Vertex object data from triangulation class vertices vector container , ID of container and vertex ID is have to be same don't change ID if you don't know what to do
    
    for(int i=0;i<myTriangulationforVertexAttributes_test10.getVertexElementAmount();i++){
        
        cout<<myTriangulationforVertexAttributes_test10.getVerticesVector()[myTriangulationforVertexAttributes_test10.getVertexAmount()-1].getVertexAttributesVector()[i]<<" ";// get last vertex object from container of vertices ,get the reference of vertex attributes container of that object i'th element
    }
    cout<<":Newly set values"<<endl;
    

    myTriangulationforVertexAttributes_test10.addTriangle(4,2,3); // vertex ID1,2,3// add new triangle with triangulation without attributes

    cout<<"Don't try to add triangle with multiple occurence of same vertex"<<endl;
    myTriangulationforVertexAttributes_test10.addTriangle(4,4,3); //not letting adding vertex for twice 

  ofstream theOutputforVertexAttributes_test10("./myTriangulationforVertexAttributes_1_output_test10.tri"); //output file stream
     
      myTriangulationforVertexAttributes_test10>>theOutputforVertexAttributes_test10;// print triangulation object to output file stream
     
   theOutputforVertexAttributes_test10.close();// close output file
   
     
    cout<<endl;
}



