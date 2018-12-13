#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "buildTree.h"
#include "writeTree.h"
#include "structureTree.h"
#include "quadtreeStructure.h"

int main( int argc, char **argv ) {

  Node *head;

  // make the head node
  head = makeNode( 0.0,0.0, 0 );
  growTree( head );
  growTree( head );
  growTree( head );
  //flagSet(head);
  //counter(head);
  
  adapt(head);

  // make a tree
  //makeChildren( head );
  //makeChildren( head->child[1] );
  //growTree( head ); 
  //destroyTree(head);
  //removeChildren(head->child[1]->child[1]);
  // print the tree for Gnuplot
  writeTree( head );
  
  return 0;
}
