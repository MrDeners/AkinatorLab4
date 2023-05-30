#ifndef INC_5_1_FUNCTIONS_H
#define INC_5_1_FUNCTIONS_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <Windows.h>
#define size 255
#define size_ten 10
struct TreeNode
{
    char *data;
    struct TreeNode *left;
    struct TreeNode *right;
};
void freeTree(struct TreeNode *root);
void menu(void);
struct TreeNode *createInitialNode();
struct TreeNode *newNode(char *string);
struct TreeNode *gameplay(struct TreeNode *root, int *attempts, int *correct);
bool choice();
void saveBinaryTree(struct TreeNode *root, FILE *fp);
struct TreeNode *readBinaryTree(FILE *fp);
#endif