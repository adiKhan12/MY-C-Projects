// implementation of binary search tree

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *create_node(int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(node *root, int data) {
    if (data < root->data) {
        if (root->left == NULL) {
            root->left = create_node(data);
        } else {
            insert_node(root->left, data);
        }
    } else {
        if (root->right == NULL) {
            root->right = create_node(data);
        } else {
            insert_node(root->right, data);
        }
    }
}

void print_tree(node *root) { 
    if (root == NULL) {
        return;
    }
    print_tree(root->left); // this is the recursive call and preorder traversal
    printf("%d ", root->data);
    print_tree(root->right);
}

// search for a node in the tree

node *search_node(node *root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}


int main() {
    node *root = create_node(5);
    insert_node(root, 3);
    insert_node(root, 7);
    insert_node(root, 1);
    insert_node(root, 4);
    insert_node(root, 6);
    insert_node(root, 8);

    // lets traverse the tree using in-order traversal
    print_tree(root);

    // lets search for a node in the tree
    node *found_node = search_node(root, 7);
    if (found_node != NULL) {
        printf("Found node: %d", found_node->data);
    } else {
        printf("Node not found");
    }
}
