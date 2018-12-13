#include "structureTree.h"

#ifndef BUILDTREE_H
#define BUILDTREE_H
Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void removeChildren( Node *parent);
void flagSet(Node *node);
void counter(Node*node);
void adapt(Node *node);
extern int count_add;
extern int count_remove;
#endif
