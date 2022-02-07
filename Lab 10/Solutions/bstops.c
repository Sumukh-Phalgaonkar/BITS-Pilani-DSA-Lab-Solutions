#include<stdio.h>

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
        delete(s);
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