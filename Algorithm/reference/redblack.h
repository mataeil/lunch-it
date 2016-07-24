#ifndef REDBLACK_H_   
#define REDBLACK_H_

struct Node{
	int val;
	char color;
	Node *left,*right,*parent;
};
Node *root;

void initNode(Node *n){
	n->color = 'r';
	n->left = NULL;
	n->right = NULL;
	n->parent = NULL;
}

Node *addNode(int val){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->val = val;
	initNode(newNode);

	if(root == NULL){		
		root = newNode;
		return newNode;
	}
	Node *cur = root;
	while(true){
		if(cur->val > val){
			if(cur->left == NULL){
				cur->left = newNode;
				newNode->parent = cur;
				return newNode;
			}else{
				cur = cur->left;
				continue;
			}
		}else{
			if(cur->right == NULL){
				cur->right = newNode;
				newNode->parent = cur;
				return newNode;
			}else{
				cur = cur->right;
				continue;
			}
		}
	}
}

Node *grandparent(Node *n){
	if ((n != NULL) && (n->parent != NULL))	return n->parent->parent;
 	else	return NULL;
}

Node *uncle(Node *n){
	Node *g = grandparent(n);
 	if (g == NULL) return NULL; 
 	if (n->parent == g->left) return g->right;
 	else return g->left;
}

void rotate_left(Node *n){	
	if(root == n)
		root = n->right;
	Node *c = n->right;
	Node *p = n->parent;

	if (c->left != NULL)
  		c->left->parent = n;

 	n->right = c->left;
 	n->parent = c;
 	c->left = n;
 	c->parent = p;

	if (p != NULL) {
  		if (p->left == n)
   		p->left = c;
  	else
   		p->right = c;
 	} 	
}

void rotate_right(Node *n){		
	if(root == n)
		root = n->left;
		
	Node *c = n->left;
 	Node *p = n->parent;

 	if (c->right != NULL)	c->right->parent = n;

 	n->left = c->right;
 	n->parent = c;
 	c->right = n;
 	c->parent = p;

 	if (p != NULL) {
  		if (p->right == n)
   		p->right = c;
  	else
   		p->left = c;
 	}
}

void insertRB_proc(Node *n){
	if (n->parent == NULL){
		n->color = 'b';
		return;
	}	
	if (n->parent->color == 'b')	
		return;
	else{
		Node *u = uncle(n), *g;		
		if ((u != NULL) && (u->color == 'r')) {
			n->parent->color = 'b';
	  		u->color = 'b';
	  		g = grandparent(n);
	  		g->color = 'r';	  		
	  		insertRB_proc(g);
	 	} 
		else{
	  		Node *g = grandparent(n);
			if ((n == n->parent->right) && (n->parent == g->left)) {
				rotate_left(n->parent);
				n = n->left;
		 	} else if ((n == n->parent->left) && (n->parent == g->right)) {
		  		rotate_right(n->parent);
		  		n = n->right;
		 	}
		 	g = grandparent(n);
		 	n->parent->color = 'b';
		 	g->color = 'r';		 	
		 	if (n == n->parent->left)
		  		rotate_right(g);
		 	else
		  		rotate_left(g);
	 	}
	}	
}

void insertRB(int val){
	Node* curNode = addNode(val);
	insertRB_proc(curNode);
}

#endif REDBLACK_H_
