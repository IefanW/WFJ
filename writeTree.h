#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#ifndef WRITETREE_H
#define WRITETREE_H
void writeTree( Node *head );
void writeNode( FILE *fp, Node *node );
void printOut( FILE *fp, Node *node );
void growTree(Node *node);
void destroyTree(Node *node);
#endif
