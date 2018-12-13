#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "structureTree.h"
#include "writeTree.h"
#include "buildTree.h" 

int levelTime;

void writeTree( Node *head ) {

  FILE *fp = fopen("quad.out","w");

  writeNode(fp,head);

  fclose(fp);

  return;
}

//destroy the tree

void destroyTree(Node *node){
    int j;
    if( node->child[0]==NULL){
    	free(node);
	}else{
        for(j=0;j<4;++j)
        {
            destroyTree(node->child[j]);
            node->child[j]=NULL;
        }
        free(node);
    }
    return;
}

// recursively visit the leaf nodes

void writeNode( FILE *fp, Node *node ) {

  int i;

  if( node->child[0] == NULL )
    printOut( fp, node );
  else {
    for ( i=0; i<4; ++i ) {
      writeNode( fp, node->child[i] );
    }
  }
  return;
}
void printOut( FILE *fp, Node *node ) {
  double x = node->xy[0];
  double y = node->xy[1];
  int level = node->level;
  double h = pow(2.0,-level);

  fprintf(fp, " %g %g\n",x,y);
  fprintf(fp, " %g %g\n",x+h,y);
  fprintf(fp, " %g %g\n",x+h,y+h);
  fprintf(fp, " %g %g\n",x,y+h);
  fprintf(fp, " %g %g\n\n",x,y);

  return;
}
void growTree(Node *node){
	int i;
	levelTime+=1;
	if(node->child[0]==NULL){
		makeChildren(node);
	}else{
		for(i=0;i<4;i++){
			growTree(node->child[i]);
		}
	}
}
