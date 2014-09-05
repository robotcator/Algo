#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

typedef struct Node{
    int key;
    Node *left;
    Node *right;
}node;

void Insert(node **root, int key);
void Delete(node **root, int key);
node* Search(node **root, int key);

node* Predecessor(node *root);
node* Successor(node *root);
node* mininum(node *x);
node* maxinum(node *x);
node* Parent(node **root, int key);

void Insert(node **root, int key)
{
    //printf("%p\n", root);

    node* s = new Node;
    s->key = key;
    s->left = s->right = NULL;

    if(*root == NULL) *root = s;
    else {
      node* p = *root;
      node* f = NULL;
      while(p){
        f = p;
        if(key < p->key) p = p->left;
        else p = p->right;
      }

      if(key < f->key) f->left = s;
      else f->right = s;
    }
}


/*
void Delete(node **root, int key)
{
  node *x = Search(root, key);
  node **y = &x;

  node *p = NULL;
  node *s = NULL;
  if((*y)->right == NULL){
    p = *y;
    printf("%d\n", (*y)->key);
    y = &((*y)->left);
    delete p;
  }
  else if((*y)->left == NULL){
    p = x;
    y = &((*y)->right);
    delete p;
  }
  else{
    p = x;
    s = x->left;
    while(s->right != NULL){
      p = s;
      s = s->right;
    }
    x->key = s->key;
    if(p != x)  p->right = s->left;
    else p->left = s->left;
    delete s;
  }
}
*/
node* Parent(node **root, int key)
{
  if(key == (*root)->key) return NULL;
  else {
    node *x = *root;
    node *y = NULL;
    while(x != NULL){
      if(x->key == key) return y;
      y = x;
      if(x->key < key) x = x->right;
      else x = y->left;
    }
  }
}


void Transplant(node **root, node *u, node *v)
{
  node* Pu = Parent(root, u->key);

  if(Pu == NULL) *root = v;
  // 如果u为根节点
  else if(u == Pu->left)
  // 如果为祖先的右子树 LR
    Pu->left = v;
  else
  // RR
    Pu->right = v;
  /*
  if(v != NULL){
    node* Pv = Parent(root, v->key);
    Pv = Pu;
  }
  */
}

void Delete(node** root, int key)
{
  node *x = Search(root, key);
  if(x->left == NULL){
    Transplant(root, x, x->right);
  }
  else if(x->right == NULL){
    Transplant(root, x, x->left);
  }
  else {
    node *y = mininum(x->right);
    // 后继值
    node *Py = Parent(root, y->key);

    if(Py != x){
      Transplant(root, y, y->right);
      y->right = x->right;
      /*
      node* PyR = Parent(root, y->right->key);
      PyR = y;
      */
    }
    Transplant(root, x, y);
    y->left = x->left;
    /*
    node *PyL = Parent(root, y->left->key);
    PyL = y;
    */
  }
}


node* Search(node **root, int key)
{
  node *x = *root;
  if(x->key == key) return x;
  else {
      if(x->key < key) return Search(&(x->right), key);
      else return Search(&(x->left), key);
  }
}

node* mininum(node *x)
{
  node *y = x;
  while(y->left != NULL){
    y = y->left;
  }
  return y;
}

node* maxinum(node *x)
{
  node *y = x;
  while(y->right != NULL){
    y = y->right;
  }
  return y;
}
/*
void Traverse(node **root, int depth){
  //printf("%p\n", root);
  //**root 是根节点的地址
  if(*root != NULL){
    Traverse(&((*root)->right), depth+1);
    cout << setw(8*depth) << " ";
		cout << (*root)->key << endl;
    Traverse(&((*root)->left), depth+1);
  }
}
*/

void Traverse(node **root)
{
  node* s[100];
  int num = 0;
  while(*root != NULL){

  }

}
void Free(node *root)
{
  if(root != NULL){
    Free(root->left);
    Free(root->right);
    delete root;
  }
}

void creat(node **T, int a[], int n)
{
  int i;
  // printf("%p\n", T);
  // printf("%p\n", *T);
  // printf("\n");
  *T = NULL;

  for(int i = 0; i < n; i ++){
    Insert(T, a[i]);
  }
}

int main()
{
    int a[] = {15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    node* root = NULL;
   // printf("%p\n", root);
   // printf("%p\n", &root);
   // printf("\n");
   // creat(&root, a, 11);
   // the adress of pointerx
    for(int i = 0; i < 11; i ++){
      Insert(&root, a[i]);
    }
   // printf("\n");
    Traverse(&root, 0);
    //node *x = Search(&root, 2);
    node *x = Parent(&root, 2);
    //printf("%d\n", x->key);

    for(int i = 0; i < 4; i ++){
      Delete(&root, a[i]);
      Traverse(&root, 0);

    }
    Free(root);
    return 0;
}
