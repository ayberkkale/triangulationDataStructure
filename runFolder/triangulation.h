//
//  triangulation.h
//  Triangulation Program
//
//  Created by M. Ayberk Kale - Autumn 2019 - EEEE3084
//  20203736 The University of Nottingham - Department of EEE
//

#ifndef triangulation_h
#define triangulation_h



class triangulation{
    
public:
    
    triangulation();// object constructor

    void operator<<(ifstream& theFile); //input File to Triangulation
    
    //getter
    int getVertexAmount();// eg. triangulation 1 = 1467
    int getVertexElementAmount();//3 for triangle
    int getVertexAttributeAmount();//0 for triangulation1
    
    int getTriangleAmount();// eg. triangulation 1 = 1467
    int getTriangleElementAmount();//3 for triangle
    int getTriangleAttributeAmount();//17 for triangulation1
    
    vector<vertex>& getVerticesVector();// Brings the reference to container for vertices
    vector<triangle>& getTrianglesVector();// Brings the reference to container for triangles
    
    void addVertex(double x, double y,double z);// add vertex to vertices container , creates vertex object in operation
    void addVertexWithAttributes(double x, double y,double z,double *vertexAttributesArray); // add vertex to vertices container , creates vertex object in operation with attributes

    void addTriangleWithAttributes(int VertexID1, int VertexID2,int VertexID3,double *triangleAttributesArray);  // add triangle to triangles container,creates triangle object in operation with attributes
    void addTriangle(int VertexID1, int VertexID2,int VertexID3); // add triangle to triangles container,creates triangle object in operation


    void operator>>(ofstream& theoutput);//Triangulation to output File
    
    double areaOfTriangle(double x1, double y1, double x2, double y2, double x3, double y3); // find area of triangles with 3 points' coordinates
       
    double findContainingTriangle(double x, double y);//is a point inside a triangle
    
    vector<double> findCircumCentrebyCoordinates(double x1, double y1, double x2, double y2, double x3, double y3); // finds a circumcircle Ox,Oy.Or of a triangle with coordinates
    
    vector<double> findCircumCentrebyTriangleID(int TriangleNo); // finds a circumcircle Ox,Oy.Or of a triangle in the triangulation
    
    void findContainingCircumCircleforVertex(int myvertexID_finds_only_inversecting_vertices); //only gives vertices that not owned by that triangles
    
    void createCircumcircleData();//create circumcircle data if user want to use function:findCircumCentrebyTriangleID, findCircumCentrebyCoordinates, findContainingCircumCircleforVertex
    
    void printCircumCentreInfo(); // to print all circum_circle data_to_screen
    
    bool isDelaunay();//bool printTheIntersectingValuesonScreen
    
    vector<double> findVertexOwnedTrianglesinTriangulation(int VertexID);  // Find  which Triangle  has specific vertex
    
    void printVertexInfoofID_toScreen(int desiredVertexID);// prints specific vertex info to screen
    void printTriangleInfoofID_toScreen(int desiredTriangleID);// prints specific triangle info to screen
    
    


    
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
     template<typename U> double integrate_by_constant_value_approx(U theFunction){ // integration accepts the function object user gives
        
        findCircumCentrePrintonScreen=false;//don't print circumcircle data on screen
         double integral_result(0);
         
         for(int i=0;i<triangleInfo[0];i++){// do for all triangles
          
           double x1=(vertices[(triangles[i].getVertexIDofTriangle1())].getVertexCoordX()); // get triangle i'th x1
           double y1=(vertices[(triangles[i].getVertexIDofTriangle1())].getVertexCoordY());// get triangle i'th y1
           double x2=(vertices[(triangles[i].getVertexIDofTriangle2())].getVertexCoordX());// get triangle i'th x2
           double y2=(vertices[(triangles[i].getVertexIDofTriangle2())].getVertexCoordY());// get triangle i'th y2
           double x3=(vertices[(triangles[i].getVertexIDofTriangle3())].getVertexCoordX());// get triangle i'th x3
           double y3=(vertices[(triangles[i].getVertexIDofTriangle3())].getVertexCoordY());// get triangle i'th y3
          
          double A =  areaOfTriangle (x1, y1, x2, y2, x3, y3); // find the area of triangle
         vector<double> circumCircleInfo = findCircumCentrebyCoordinates( x1,  y1,  x2,  y2,  x3,  y3);// find circum centre of triangle by coordinates
             double f_x= circumCircleInfo[0];// circum centre x  of triangle
             double f_y=circumCircleInfo[1];// circum centre y  of triangle

             integral_result+=A*(theFunction(f_x,f_y)); // put fx, fy to the the function as arguments// can be parallelized
             
             //Constant value approximation:sum of all ((AT:triangle area)* f (OxT ,OyT ))
           
             circumCircleInfo.empty();
             
         }// do for all triangles , sum all up
         
         cout<<"Integral Result by Constant Value Approximation: "<<integral_result<<endl;
         return integral_result;// do for all triangles , sum all up, give the result
        
        
    }

/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
    template<typename U> double integrate_by_linear_interpolation_approx(U theFunction){
       
        double integral_result2(0);
        
        for(int i=0;i<triangleInfo[0];i++){// do for all triangles
         
          double x1=(vertices[(triangles[i].getVertexIDofTriangle1())].getVertexCoordX()); // get triangle i'th x1
          double y1=(vertices[(triangles[i].getVertexIDofTriangle1())].getVertexCoordY());// get triangle i'th y1
          double x2=(vertices[(triangles[i].getVertexIDofTriangle2())].getVertexCoordX());// get triangle i'th x2
          double y2=(vertices[(triangles[i].getVertexIDofTriangle2())].getVertexCoordY());// get triangle i'th y2
          double x3=(vertices[(triangles[i].getVertexIDofTriangle3())].getVertexCoordX());// get triangle i'th x3
          double y3=(vertices[(triangles[i].getVertexIDofTriangle3())].getVertexCoordY());// get triangle i'th y3
         
         double A =  areaOfTriangle (x1, y1, x2, y2, x3, y3);// find the area of triangle
            
    
            integral_result2+=(A/3)*(theFunction(x1,y1)+theFunction(x2,y2)+theFunction(x3,y3));// put x1, y1 ,x2,y2 and x3,y3 to the the function as arguments , multiple with one third of total area // can be parallelized
         //Linear interpolation approximation:sum of all ((AT:triangle area/3)* (f (x1 ,y1 )+f (x2 ,y2 )+f (x3 ,y3 )))
            
        }
        
        cout<<"Integral Result by Linear Interpolation Approximation: "<<integral_result2<<endl;
        return integral_result2;// do for all triangles , sum all up, give the result
        
    }
/*     --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
    
    
private:
    
    vector<vertex> vertices; // vertices vector
    vector<triangle> triangles; // triangles vectors
    
    int vertexInfo[3]; // vertex info eg.how many vertices, 3 point,0 attribute
    int triangleInfo[3];// triangle info eg.how many triangles, 3 vertices,17 attributes
    
    
    vector<string> verticesAttributeNames_; // attribute name of  vertices
    vector<string> triangleAttributeNames_; // attribute name of  triangles
    
    vector<vector<double> > circumCircleData;//isDelaunay using this vector of vectors only
    
    bool containCalculatedCCincircumCircleDataVector;// prevent user function calls corrupt circumCircleData vector used by delaunay
    

    bool isDelaunaybool;// the delaunay check condition that returns by the function
    

    bool findCircumCentrePrintonScreen;// prevent Delaunay printing all the values on to the screen
    
    double Delaunay_determinant;//make sure matrix has inverse
    
    int vertexAmount_;// eg. in triangulation 1 = 1467
    int vertexElementAmount_;//3 for triangle
    int vertexAttributeAmount_;//3 for triangle
    
    int triangleAmount_;// eg. triangulation 1 = 1467
    int triangleElementAmount_;//3 for triangle
    int triangleAttributeAmount_;//3 for triangle
    
    vector<vector<double> > test_triangulation;//contain all_the_triangulations data in one place if needed
    

    
};

#endif /* triangulation_h */

