#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure for a node
typedef struct node
{
    int id;
    char name[50];
    struct node *left;
    struct node *right;
}
node;

//function to create a new node
node* create_node(int id, char name[50])
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->id = id;
    strcpy(new_node->name, name);
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

//function to insert a node in the tree
void insert(node **tree, int id, char name[50])
{
    //if tree is empty, create a root node
    if(*tree == NULL)
    {
        *tree = create_node(id, name);
    }

    //if the id is less than the current node, insert in left subtree
    else if(id < (*tree)->id)
    {
        insert(&(*tree)->left, id, name);
    }

    //if the id is greater than the current node, insert in right subtree
    else if(id > (*tree)->id)
    {
        insert(&(*tree)->right, id, name);
    }
}

//function to search for a node in the tree
node* search(node *tree, int id)
{
    //if tree is empty or if id is found
    if(tree == NULL || tree->id == id)
    {
        return tree;
    }

    //if id is less than the current node, search in left subtree
    if(id < tree->id)
    {
        return search(tree->left, id);
    }

    //if id is greater than the current node, search in right subtree
    if(id > tree->id)
    {
        return search(tree->right, id);
    }
}

//function to delete a node from the tree
node* delete(node *tree, int id)
{
    //search for the node to be deleted
    node *temp = search(tree, id);

    //if node is not found
    if(temp == NULL)
    {
        return tree;
    }

    //if tree is empty
    if(tree == NULL)
    {
        return NULL;
    }

    //if the node to be deleted is the root node
    if(tree == temp)
    {
        //if the root node has no child
        if(tree->left == NULL && tree->right == NULL)
        {
            free(tree);
            return NULL;
        }

        //if the root node has one child
        if(tree->left == NULL || tree->right == NULL)
        {
            node *temp2;
            if(temp->left == NULL)
            {
                temp2 = temp->right;
            }
            else
            {
                temp2 = temp->left;
            }

            free(temp);
            return temp2;
        }

        //if the root node has two children, find minimum in the right subtree
        node *temp2 = tree->right;
        while(temp2->left != NULL)
        {
            temp2 = temp2->left;
        }

        //replace root node with minimum node in the right subtree
        tree->id = temp2->id;
        strcpy(tree->name, temp2->name);

        //delete the minimum node in the right subtree
        tree->right = delete(tree->right, temp2->id);
        return tree;
    }

    //if the node to be deleted is not the root node
    node *parent = tree;
    int is_left = 0;

    //find the parent node
    while(parent != NULL)
    {
        if(parent->left == temp)
        {
            is_left = 1;
            break;
        }

        if(parent->right == temp)
        {
            is_left = 0;
            break;
        }

        if(id < parent->id)
        {
            parent = parent->left;
        }
        else
        {
            parent = parent->right;
        }
    }

    //if the node to be deleted has no child
    if(temp->left == NULL && temp->right == NULL)
    {
        if(is_left)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }

        free(temp);
        return tree;
    }

    //if the node to be deleted has one child
    if(temp->left == NULL || temp->right == NULL)
    {
        node *child;
        if(temp->left == NULL)
        {
            child = temp->right;
        }
        else
        {
            child = temp->left;
        }

        if(is_left)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }

        free(temp);
        return tree;
    }

    //if the node to be deleted has two children, find minimum in the right subtree
    node *temp2 = temp->right;
    while(temp2->left != NULL)
    {
        temp2 = temp2->left;
    }

    //replace node to be deleted with minimum node in the right subtree
    temp->id = temp2->id;
    strcpy(temp->name, temp2->name);

    //delete the minimum node in the right subtree
    temp->right = delete(temp->right, temp2->id);
    return tree;
}

//function to print the tree in inorder traversal
void print_tree(node *tree)
{
    if(tree != NULL)
    {
        print_tree(tree->left);
        printf("%d %s\n", tree->id, tree->name);
        print_tree(tree->right);
    }
}

int main()
{
    node *tree = NULL;

    while(1)
    {
        printf("\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Print\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        if(choice == 1)
        {
            int id;
            char name[50];
            printf("Enter id: ");
            scanf("%d", &id);
            printf("Enter name: ");
            scanf("%s", name);
            insert(&tree, id, name);
        }
        else if(choice == 2)
        {
            int id;
            printf("Enter id: ");
            scanf("%d", &id);
            tree = delete(tree, id);
        }
        else if(choice == 3)
        {
            int id;
            printf("Enter id: ");
            scanf("%d", &id);
            node *temp = search(tree, id);
            if(temp == NULL)
            {
                printf("Node not found\n");
            }
            else
            {
                printf("Node found\n");
                printf("Id: %d\n", temp->id);
                printf("Name: %s\n", temp->name);
            }
        }
        else if(choice == 4)
        {
            print_tree(tree);
        }
        else
        {
            break;
        }
    }

    return 0;
}