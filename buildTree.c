#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "structureTree.h"
#include "writeTree.h"
#include "quadtreeStructure.h"
Node *makeNode( double x, double y, int level ) {

  int i;

  Node *node = (Node *)malloc(sizeof(Node));

  node->level = level;

  node->xy[0] = x;
  node->xy[1] = y;

  for( i=0;i<4;++i )
    node->child[i] = NULL;

  return node;
}

// split a leaf nodes into 4 children

void makeChildren( Node *parent ) {

  double x = parent->xy[0];
  double y = parent->xy[1];
  int level = parent->level;

  double hChild = pow(2.0,-(level+1));

  parent->child[0] = makeNode( x,y, level+1 );
  parent->child[1] = makeNode( x+hChild,y, level+1 );
  parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
  parent->child[3] = makeNode( x,y+hChild, level+1 );
  return;
}
void removeChildren(Node *parent){
	int k;
	for(k=0;k<4;k++){
		parent->child[k]=NULL;
		free(parent->child[k]);
	}
	return;
}
void flagSet(Node *node){
	int i=0;
	node->flag=0;
	double location=nodeValue(node,0.0);
	if(node->child[i]==NULL){
		if(location>0.5){
			node->flag=1;
		}
		if(location<-0.5){
			node->flag=-1;
		}
	}
	else{
		for(i=0;i<4;++i){
			flagSet(node->child[i]);
		}
	}
	return;
}
int t1,t2;
int count_add,count_remove;

int counter(Node*node)
{
	int i;
	if(node->child[0]==NULL&& node->flag==1)
	{
		makeChildren(node);
		count_add+=4;
		t1+=1;
	}
	else if(node->child[0]!=NULL)
	{
		for(i=0;i<4;i++)
			{
			counter( node->child[i]);
			}
		int j=0;
		for(i=0;i<4;i++)
		{
			if(node->child[i]->flag==-1)
				j++;
		}
		if(j==4)
		{
			removeChildren(node);
			count_remove+=4;
			t2+=1;
		}
	}


	return 0;
}



void adapt(Node *head){
	int maxLevel=6;
	if(head->level<maxLevel){
		do{
			t1=0,t2=0;
			flagSet(head);
			counter(head);
			printf("%d,%d\n",count_add,count_remove);
		}
		while(t1!=0&&t2!=0);
	}
	return;
}
