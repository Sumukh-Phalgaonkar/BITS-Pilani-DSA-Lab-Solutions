/*************Name: Sumukh Phalgaonkar	***********ID: 2019A7PS0011P******************************/
/*******Note: The functions read(), add(), and delete() have been implemented according to the question Q1 (b). The function rotate() , add_avl(), and delete_avl() have been implemneted
as a solution to question Q1 (c),(d), and (e) respectively. Please note that both functions add() and add_avl() take a node and not a value to be inserted. Function createnode() has
been provided for this purpose. If the function rotate() is required to be called on its own then the nodes x,y and z need to be provided as arguments. The functions getparent()
and successor() might come in handy for this. However for add_avl() and delete_avl(), the values for x,y,z are calculated within the function. No main function has been implemented here.
hinfo stores the height balance information******************/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node* left;
    struct node* right;
    int hinfo : 3;// hinfo contains the height balance information
};


void add (struct node* r, struct node* k)
{
    if(r == NULL)
        r = k;
    
    else if ((r -> value) > (k -> value))
    {
        add(r -> left,k);
    }
    else if ((r -> value) < (k -> value))
    {
        add(r -> right , k);
    }
    else
    {
       add(r -> left, k); // Taken by convention
    }

}

int height(struct node* r)
{
    if(r == NULL)
        return 0;
    else
    {
    int lh = height(r -> left);
    int rh = height(r -> right);
    if(lh > rh)
        return (lh+1);
    else
        return (rh+1); 
    }
}


struct node* find(struct node* r, int key)
{
    if(r == NULL)
    {
        printf("Not found \n");
        return r;      
    }
    else if (r -> value == key)
    {
        printf("Found \n");
        return r;
    }
    else if (r -> value > key)
    {
       return(find(r->left,key));
    }
    else
    {
        return(find(r->right,key));
    }
}

struct node* successor(struct node* root, struct node* n)
{
    struct node* suc = NULL;
    if(n -> right != NULL)
    {
        suc = n -> right;
        while(suc -> left != NULL)
        {
            suc = suc -> left;
        }
        return suc;
    }
    struct node* t = root;
    while(t != NULL)
    {
        if((n -> value) < (t -> value))
        {
            suc = t;
            t = t -> left;
        }
        else if ((n -> value) > (t -> value))
        {
            t = t -> right;
        }
        else
            break;
    }
    return suc;
}

void delete(struct node* root, int key)
{
    struct node* p = find(root, key);
    if(p == NULL)
    {
        printf("not present \n");
    }

    if(((p -> left)==NULL)&&((p -> right)==NULL)) // leaf node
    {
        free(p);
    }
    else
    {
        struct node* s = successor(root,p);
        p-> value = s->value;
        delete(root,s->value);
    }
}



struct node* createnode(int key)
{
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t -> value =key;
    t->left =NULL;
    t -> right = NULL;
    t -> hinfo = 0;
    return t;
}

void inithinfo(struct node* p)
{
    p->hinfo = height(p->right) - height(p->left);
}


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
        rotate((temp->left->hinfo == 1?temp->left->right:temp->left->left),temp->left,temp);
    }

   
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
        delete(root,s->value);
    }


    inithinfo(q);
    while(q != NULL)
    {
        q = getparent(root,q);
        inithinfo(q);
         if(q->hinfo > 1)
        rotate((q->right->hinfo == 1?q->right->right:q->right->left),q->right, q);
        if(q->hinfo < -1)
        rotate((q->left->hinfo == 1?q->left->right:q->left->left),q->left, q);
    }
}

int main()
{
	
}
