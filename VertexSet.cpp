/*
 * TODO: Add file name, author, date, purpose
 */

#include "VertexSet.h"

using namespace std; // Debatable, but easier for now.

/*  Constructors initialize class variables, many to zero.
	VertexSet constructors need to set nAllocated according
	to the initial size of the dynamic array of Vertex pointers,
	and then use new to dynamically allocate an array of that
	size for vertices.  )
*/
// make every vertices i to none pointers

// No-argument constructor.  Set allocated to 10 by default
//also initiallises the vertices array to be used with the VertexSet contructors
//sets nVertices to 0
VertexSet::VertexSet( ) {
  nAllocated = 10;
  vertices = new Vertex* [nAllocated];
  nVertices = 0;
} // Constructor ( )

// Constructor with an argument. 
// Set allocated to the value of the passed-in argument
VertexSet::VertexSet( int initialCapacity) {
  nAllocated = initialCapacity;
  vertices = new Vertex* [nAllocated];
  nVertices = 0;
} // Constructor( int )

// Destructor needs to free all associated dynamic memory
// Including all the dynamically allocated Vertices, and then
// the array storing them.
VertexSet::~VertexSet( ) {
  //loops through the amount of vertices there are and deletes each value within the array
  for(int i = 0; i<nVertices; i++){
    delete vertices[i];
  }
  delete[] vertices;
} // Destructor

// This looks like a getter, but it could also count vertices instead
//returns the value of how many Vertices there are
int VertexSet::getNumberOfVertices( ) const {
  return nVertices;
} // getNumberOfVertices

// Add a vertex to the set.  Allocate new memory as needed.
// Returns true if successful, false otherwise
bool VertexSet::addVertex(const Vertex & vertex) {
  /*  TODO: 
		1. Create a dynamically allocated copy of the passed-in vertex
		2. Grow the dynamic array if necessary
		( new throws an Exception if it fails.  Handling that
		  is an optional enhancement.  Otherwise assume it works. )
		3. Add the pointer to the new Vertex to the array, and update counters,
		   luminosity, and upper and lower bounds
		4. If all goes well, return true.
	*/
  Vertex* pTemp = new Vertex( vertex );
  //if the amount of vertices exceeds the amount allocated then double the size of the nAllocated
  if(nAllocated <= nVertices){
    Vertex** pTemp2 = vertices;
    //double the size of the vertices ussing malloc 
    vertices = (Vertex**)malloc(2*nAllocated*sizeof(Vertex));
    for(int i = 0; i<nAllocated; i++){
      //loop through how many nAllocated originally have vertices hold its originall values from before doubling its allocated space
      vertices[i] = pTemp2[i];
    }
    delete(pTemp2);
    pTemp2 = NULL;
    nAllocated = 2*nAllocated;
  }
  //set values in vertices one by one for pTemp
  vertices[this->nVertices]= pTemp;
  //vertices is incremented by one
  nVertices++;

  //set max values to the first value from the vertices
  double maxX = vertices[0]->getX();
  double maxY = vertices[0]->getY();
  double maxZ = vertices[0]->getZ();
  //loop through the current vertices and see weather the max values for each coordinate is greater then or equall to the prev value entered
  for(int i = 0; i < nVertices; i++){
    if(maxX <= vertices[i]->getX()){
    maxX = vertices[i]->getX();
    this->upperBounds[0] = maxX;
  }if(maxY <= vertices[i]->getY()){
    maxY = vertices[i]->getY();
    this->upperBounds[1] = maxY;  
  }if(maxZ <= vertices[i]->getZ()){
    maxZ = vertices[i]->getZ();
    this->upperBounds[2] = maxZ;
    }
  }

  //set max values to the first value from the vertices
  double minX = vertices[0]->getX();
  double minY = vertices[0]->getY();
  double minZ = vertices[0]->getZ();
  //loop through the current vertices and see weather the max values for each coordinate is greater then or equall to the prev value entered
  for(int i = 0; i < nVertices; i++){
  if(minX >= vertices[i]->getX()){
    minX = vertices[i]->getX();
    this->lowerBounds[0] = minX;
  }if(minY >= vertices[i]->getY()){
    minY = vertices[i]->getY();
    this->lowerBounds[1] = minY;  
  }if(minZ >= vertices[i]->getZ()){
    minZ = vertices[i]->getZ();
    this->lowerBounds[2] = minZ;
    }
  }
  //if vertices is not empty then the transfer was completed successfully 
  if(vertices != NULL){
    return true;
  }
  return false;
} // addVertex

// Return true if there is an intersection, false otherwise
bool VertexSet::intersect( const Vertex & vertex ) const {
  Vertex pTemp2 = Vertex(vertex);
  //nested if statments to make sure each corrdinate in the second vertex is within the bounds of the first vertex set 
  if(pTemp2.getX() >= this->lowerBounds[0] && pTemp2.getX() <= this->upperBounds[0]){
    if(pTemp2.getY() >= this->lowerBounds[1] && pTemp2.getY() <= this->upperBounds[1]){
      if(pTemp2.getZ() >= this->lowerBounds[2] && pTemp2.getZ() <= this->upperBounds[2]){
        return true;
      }
    }
  }
  return false;  // TODO:  Replace this line with code that checks.
} // intersect

// The following function "prints" to outStream all the information about
// a VertexSet, except the actual vertices themselves.
void VertexSet::printStats( ostream & outStream ) const {
  double totalLuminosity= 0;
  double average = 0;
  //loop throuhj the total amount of vertices
	for( int i = 0; i < nVertices; i++){
    //total values indicates going through each vertices and adding the current to the prev
    totalLuminosity += vertices[i]->getLuminosity();
    //average indicated the total luminosity divided by how many vertices there are
    average = totalLuminosity / nVertices;
  }
  //print the info
	outStream << "This vertex set has " << nVertices << " stored out of " << nAllocated << " available.\n";
  outStream << "the average Luminosity for this set is " << average << endl;
  outStream << "This vertexSet upper and lower bounds for X are " << this->upperBounds[0]  << "  " << this->lowerBounds[0] << endl;
  outStream << "This vertexSet upper and lower bounds for Y are " << this->upperBounds[1]  << "  " << this->lowerBounds[1] << endl;
  outStream << "This vertexSet upper and lower bounds for Z are " << this->upperBounds[2]  << "  " << this->lowerBounds[2] << endl;
	return;

} // printStats


// The following function "prints" to outStream all the information about
// a VertexSet, including the actual vertices themselves.
void VertexSet::printAll( ostream & outStream ) const {	
	//TODO:  print luminosity and upper and lower bounds, and vertex data.
  printStats(cout);
  cout << endl;
  outStream << "The vertices in the VertexSet are" << endl;
  //loops through the vertex set and prints each coordinate
  for(int i = 0; i < nVertices; i++){
    outStream << vertices[i]->getX() << " " << vertices[i]->getY() << " " << vertices[i]->getZ() << " " << vertices[i]->getLuminosity() << endl;
  }
	//ALTERNATIVE:  Have this method call printStats, and then print the extra information.
	return;
} // printAll

// Return the address of the vertex with the given ID, or NULL otherwise
Vertex * VertexSet::getVertexByID( int id ) const {
  for(int i = 0; i < nVertices; i++){
    //if the id entered is equall to the ID within that specific vertice ID then return the address of the vertices
    if(id == vertices[i]->getID()){
      return *&vertices[i];
    }
  }
	return NULL; // TODO:  Replace this line with code to find the Vertex *

} // getVertexByID



