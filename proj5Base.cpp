/*
 *  TODO:  Add file name, author, date, and purpose
 *
 *	TODO:  Create a makefile and use make.
 *         In the meantime, the following command will build proj5Base:
 *
 *         gcc -g -o proj5Base proj5Base.cpp Vertex.cpp VertexSet.cpp
 */
 
 #include <cstdlib>
 #include <iostream>
 #include "Vertex.h"
 #include "VertexSet.h"

 using namespace std;	// Debatable, but easier for now.

 int main( int argc, char ** argv ) {
   VertexSet setVertex;   
   
   double X = 0;
   double Y = 0;
   double Z = 0;
   double luminosity = 0;
   while(1){
     //user enters 4 inputs for the vertices
     cin >> X >> Y >> Z >> luminosity;
     //if the user enters a negative luminosity then break from while loop
     if(luminosity < 0 ){
       break;
     }
     // vertex instance that takes the users input as the constructor
     Vertex vertex1(X,Y,Z,luminosity);

     //if adding the vertex to the array was successful then continue
     if(setVertex.addVertex(vertex1) == true){
       continue;
       //else print a error message 
       }else{
       cout << "something went wrong" << endl; 
     }
  }
   //here we are simply printing out the stats without the vertices
   setVertex.printStats(cout);
   
   cout << endl;
   double X_2 = 0;
   double Y_2 = 0;
   double Z_2 = 0;
   double luminosity_2 = 0;
   while(1){
     //similar to what we did above but reading in a second set of values for a new vertex
     cin >> X_2 >> Y_2 >> Z_2 >> luminosity_2;
     if(luminosity_2 < 0 ){
       break;
     }
      // vertex instance that takes the users input as the constructor
     Vertex vertex2(X_2,Y_2,Z_2,luminosity_2);
     //if the intersection was successful then print that the cordinated are intersecting
     if(setVertex.intersect(vertex2) == true){
       cout << "This coordinte intersects with the set" << endl;
     }else{
       cout << "This coordinate does not intersect with the set" << endl;
     }
  }
   //here we are printing the states plus the each vertics from the set
  setVertex.printAll(cout);
	return 0;
  	
 } // main
 
 
