#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 31

typedef struct node
{
    int index;
    char* name;
    struct node* parent;
    struct node* left;
    struct node* right;

}node;

node* insert(node* tree, char* name, int index)
{
    node* person = malloc(sizeof(node));
    person->index = index;
    person->right = NULL;
    person->left = NULL;
    person->parent = NULL;
    person->name = malloc(N*sizeof(char));
    strcpy(person->name, name);
    node* x = tree;
    node* y = NULL;

    if(tree == NULL)
    {
        tree = person;
        return tree;
    }
    while(x != NULL)
    {
        y = x;
        if(x->index < index) x = x->right;
        else x = x->left;
    }

    if(y->index < index)
    {
        y->right = person;
        person->parent = y;
    }
    else
    {
        y->left = person;
        person->parent = y;
    }
    return tree;
}

node* find(node* tree, int index)
{
    while(tree != NULL && tree-> index != index)
    {
        if(tree->index > index) tree = tree->left;
        else tree = tree->right;
    }
    if(tree == NULL) return NULL;
    if(tree->index == index) return tree;
}

node* tree_succesor(node* y)
{
    if(y->right != NULL)
    {
        y = y->right;
        while(y->left != NULL) y = y->left;
        return y;
    }
    node* z = y->parent;
    while(z != NULL && y == z->right)
    {
        y = z;
        z = z->parent;
    }
    return y;
}

node* delete_from_tree(node* tree, int index)
{
    node* wsk = find(tree, index);
    node* x;
    node* y;

    if(wsk == NULL) return tree;
    else
    {
        if(wsk-> left == NULL || wsk->right == NULL) y = wsk;
        else
        {
            y = tree_succesor(y);
        }
        if(y->left != NULL) x = y->left;
        else
        {
            x = y->right;
        }
        if(x != NULL)
        {
            x->parent = y->parent;
        }

        if(y->parent == NULL)
        {
            tree = x;

        }
        else
        {
            if(y == (y->parent)->left) (y->parent)->left = x;
            else
            {
                (y->parent)->right = x;
            }
            if(y != wsk)
            {
                if(wsk == wsk->parent->left) wsk->parent->left = y;
                else wsk->parent->right = y;
                y->left = wsk->left;
                y->right = wsk->right;
            }
            }
        }

        return tree;
}


void delete_tree(node* root)
{
    if(root == NULL) return;
    delete_tree(root->left);
    delete_tree(root->right);
    free(root->name);
    free(root);
}
int main()
{
    int a, r, f;
    char name[N];
    int index;
    scanf("%d %d %d", &a, &r, &f);

    node* tree = NULL;
    while(a--)
    {
        scanf("%d", &index);
        scanf("%s", name);
        tree = insert(tree, name, index);
    }

    while(r--)
    {
        scanf("%d", &index);
        tree = delete_from_tree(tree, index);
    }
    while(f--)
    {
        scanf("%d", &index);
        node* wsk = find(tree, index);
        if(wsk != NULL)
        {
            printf("%s\n", wsk->name);
        }
        else printf("NO\n");
    }
}
