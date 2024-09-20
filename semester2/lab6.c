#include <stdio.h>
#include <stdlib.h>

typedef struct TREE {

    int num1;
    int num2;

    struct TREE* left;
    struct TREE* center;
    struct TREE* right;
}TREE;


TREE* inittree() {

    TREE* tree;

    tree = (TREE*)malloc(sizeof(TREE));

    tree->left = NULL;
    tree->center = NULL;
    tree->right = NULL;
    tree->num1 = 0;
    tree->num2 = 0;

    return tree;
}


void printtree(TREE* tree) {

    if (tree) {

        printtree(tree->left);
        printf("%d ", tree->num1);
        printtree(tree->center);

        if (tree->num2 != 0)
            printf("%d ", tree->num2);

        printtree(tree->right);
    }
}


void add(TREE* root, int num) {

    if (root->num1 < num && root->num2 < num && root->num2 != 0) {

        if (root->right)
            add(root->right, num);

        else {
            TREE* tmp = inittree();
            tmp->num1 = num;
            root->right = tmp;
        }
    }

    if (root->num1 > num && root->num2 != 0) {

        if (root->left)
            add(root->left, num);

        else {
            TREE* tmp = inittree();
            tmp->num1 = num;
            root->left = tmp;
        }
    }

    if (root->num2 == 0) {

        root->num2 = num;

        if ((root->num1 < root->num2 ? root->num1 : root->num2) == num) {
            root->num2 = root->num1;
            root->num1 = num;
        }
    }

    if (root->num1 < num && root->num2 > num) {

        if (root->center)
            add(root->center, num);

        else {
            TREE* tmp = inittree();
            tmp->num1 = num;
            root->center = tmp;
        }
    }
}


void freetree(TREE* root) {

    if (root) {
        freetree(root->left);
        freetree(root->center);
        freetree(root->right);
        free(root);
    }
}


int main() {

    TREE* root;

    root = inittree();
    root->num1 = 7;
    root->num2 = 16;

    add(root, 3);
    add(root, 9);
    add(root, 1);
    add(root, 2);
    add(root, 32);
    add(root, 4);
    add(root, 11);
    add(root, 15);
    add(root, 14);

    printtree(root);

    freetree(root);

    return 0;
}
