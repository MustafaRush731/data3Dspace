/*
 * TODO: Add file name, author, date, purpose
 */

#ifndef _VERTEXSET_H
#define _VERTEXSET_H

#include <cstdlib>
#include <iostream>
#include "Vertex.h"

using namespace std;  // Debatable.  Easier for now.

class VertexSet {
	
	// Private data memebers
	
	private: 
	    Vertex ** vertices; // Dynamic array of POINTERS TO Vertex objects
	    int nVertices;
	    int nAllocated;
	    double luminosity;
	    double lowerBounds[ 3 ];
	    double upperBounds[ 3 ];
	    
	// Public methods
	
	public: 
	    
	    // Two constructors and one destructor
		VertexSet( );
		VertexSet( int initialCapacity );
		~VertexSet( );
		
		int getNumberOfVertices( ) const;
		bool addVertex(const Vertex & vertex);
		Vertex * getVertexByID( int id ) const;
		bool intersect( const Vertex & vertex) const;
		void printStats( ostream & out ) const;
		void printAll( ostream & out )const;
};

#endif //_VERTEXSET_H
