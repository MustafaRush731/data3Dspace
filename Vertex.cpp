/*
 * TODO: Add file name, author, date, purpose
 */

#include "Vertex.h"

/*
 * Vertex implementation
 */
 
// Initialize the static int class variable.
int Vertex::nextID = 0;
 
// TODO:  Set initial values in constructor.  Make getters functional

// Two constructors
// Note that the first one  must assign a new unique value to ID, 
// making use of static int nextID

//this contrsuctor initializes the value of the vertex
Vertex::Vertex( double X,  double Y,  double Z,  double luminosity ) {
	
	// Sample.  "this->luminosity" refers to class variable, 
	//              "= luminosity" refers to the passed parameter
	this->coordinates[0] = X;
  this->coordinates[1] = Y;
  this->coordinates[2] = Z;
	this->luminosity = luminosity;
  // next id increments because it is a static variable then id will hold that nextID value
  nextID += 1;
  this -> ID = nextID;
}

/*  The copy constructor should copy all the data of the input vertex,
	including the ID.  That has potential problems, but is better than
	the alternative ( creating a new unique ID for the copy ) for our
	purposes at the moment.
	
	Note:  This is an important function, because the system uses it 
	every time a Vertex is passed by value, by copying the Vertex
	onto the call stack.  Strange things break until you write this.	
*/

// is a copy constructor that will take all values from one vertex to another
Vertex::Vertex( const Vertex & vertex ) {
	
	// this->luminosity = vertex.luminosity;	// Sample.  Copy from vertex to *this
	luminosity = vertex.luminosity;				// Better Sample.  this-> is not needed here
  this->coordinates[0] = vertex.coordinates[0];
  this->coordinates[1] = vertex.coordinates[1];
  this->coordinates[2] = vertex.coordinates[2];
  this->ID = vertex.ID;
}

// Destructor.  ( This method has nothing to do right now. )

Vertex::~Vertex( ) {
	
}

// Getters return class values

// gets the value of id 
int Vertex::getID( ) const {
  return ID;
}

//gets the value of the X coordinate 
double  Vertex::getX( ) const {
  return coordinates[0];
}

// gets the value of Y or coordinate 1
double Vertex::getY( ) const {
  return coordinates[1];
}

//lets the user have access to Value Z or coordinates 2
double Vertex::getZ( ) const {
  return coordinates[2];
}

//lets the user have access to the luminosity
double Vertex::getLuminosity( ) const {
  return luminosity;
}

// The following function is not a class method, but is related to the class.
// ( Note no Vertex:: scope resolution. )

 // The following function allows code like this, where v is a Vertex:
 //			cout << "Vertex v = " << v << endl;
 // Note the code sends output to the variable "out", not cout
 
 ostream & operator << ( ostream & out, const Vertex & vertex ) {
 	
 	out << "( X: " << vertex.getX( );
 	
 	// TODO:  Add lines here to send Y, Z, and luminosity to out
 	out << " Y: " << vertex.getY( );
  out << " Z: " << vertex.getZ( );
  out << " Luminosity: " << vertex.getLuminosity( );
 	out << " )";
 	
 	return out;  // Allows multiple << operators on a line as shown above.	
 	
 } // operator << ( ostream &, Vertex ) 

