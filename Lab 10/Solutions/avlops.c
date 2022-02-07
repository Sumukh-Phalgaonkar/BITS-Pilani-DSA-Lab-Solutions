#include<stdio.h>

struct node* highest(struct node* x, struct node* y, struct node* z)
{
    struct node* max = x;
    if((y->value)>(max->value))
        max = y;
    if((z -> value) > (max -> value))
        max = z;

    return max;
}

struct node* lowest(struct node* x, struct node* y, struct node* z)
{
   struct node* min = x;
   if((y -> value)<(min -> value))
   {
       min = y;
   } 
   if((z ->value)<(min -> value))
   {
       min = z;
   }
   return min;
}

struct node* middle(struct node* x, struct node* y, struct node* z)
{
    int a = x->value, b = y-> value, c = z->value;
    if((a>b && a<c)||(a>c && a<b))
    return x;
    if((b>a && b<c)|| (b>c && b<a))
    return y;
    if((c>a && c<b)|| (c>b && c<a))
    return z;
}


struct node* rotate(struct node* x, struct node* y, struct node*z)
{
    struct node* a = lowest(x,y,z);
    struct node* b = middle(x,y,z);
    struct node* c = highest(x,y,z);

    struct node* t0 = a -> left;
    struct node* t1;
    struct node* t2;
    struct node* t3 = c -> right;

    if(a->right != b)
    {
        t1 = a->right;
    }
    else
    t1 = b -> left;

    if(b->right != c)
    {
        t2 = b -> right;
    }
    else
    t2 = c -> left;
    //Assignment done

    b -> left = a;
    b -> right = c;
    a -> left = t0;
    a -> right = t1;
    c -> left = t2;
    c -> right = t3;

    inithinfo(a);
    inithinfo(b);
    inithinfo(c);
    
    
    return b;
}



void add_avl(struct node* r, struct node* k, struct node* root)
{
    if(r == NULL)
        r = k;
    
    else if ((r -> value) > (k -> value))
    {
        add_avl(r -> left,k,root);
    }
    else if ((r -> value) < (k -> value))
    {
        add_avl(r -> right , k, root);
    }
    else
    {
       add_avl(r -> left, k, root); // Taken by convention
    }
    struct node* temp =k;
    inithinfo(k);
    while(temp!=NULL)
    {
        temp= getparent(root,temp);
        inithinfo(temp);
        if(temp->hinfo > 1)
        rotate((temp->right->hinfo == 1?temp->right->right:temp->right->left),temp->right,temp);
        if(temp->hinfo < -1)
        rotate((temp->left->hifo == 1?temp->left->right;temp->left->left),temp->left,temp);
    }

   
}


struct node* getparent(struct node* root, struct node* n)
{
    if(n->value == root->value)
    return NULL;
    if((root->left->value == n->value)||(root->right->value == n->value))
    return root;
    else if(root->value > n->value)
    return getparent(root->left,n);
    else 
    return getparent(root->right, n);
}


void delete_avl(struct node* root, int key)
{
    struct node* p = find(root, key);
    struct node* q;
    if(p == NULL)
    {
        printf("not present \n");
    }

    if(((p -> left)==NULL)&&((p -> right)==NULL)) // leaf node
    {
        q = getparent(root,p);
        free(p);
    }
    else
    {
        struct node* s = successor(root,p);
        p-> value = s->value;
        delete(s);
    }


    inithinfo(q);
    while(q != NULL)
    {
        q = getparent(q);
        inithinfo(q);
         if(q->hinfo > 1)
        rotate((q->right->hinfo == 1?q->right->right:q->right->left),q->right, q);
        if(q->hinfo < -1)
        rotate((q->left->hifo == 1?q->left->right;q->left->left),q->left, q);
    }
}