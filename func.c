#include "func.h"
struct TreeNode *gameplay(struct TreeNode *root, int *attempts, int *correct)
{
    do
    {
        system("cls");
        struct TreeNode *cursor = root;
        int choice;
        char Polina[size_ten];
        while (cursor->left || cursor->right)
        {
            printf("\033[1;30m%s\033[0m\n", cursor->data);
            // scanf_s("%d", &choice);
            fgets(Polina, 10, stdin);
            if (strcmp(Polina, "yes") == 1)
                cursor = cursor->right;
            else
                cursor = cursor->left;
            system("cls");
        }
        system("cls");
        printf("\033[1;30mIs it\033[0m \033[1;32m%s? \033[0m\n", cursor->data);
        // scanf_s("%d", &choice);
        fgets(Polina, size_ten, stdin);
        (*attempts)++;
        if (strcmp(Polina, "yes") == 1)
        {
            (*correct)++;
            printf("Yes, I win!\n");
            char command[1024];
            sprintf(command, "start https://www.bing.com/search?q=%s", cursor->data);
            system(command);
            Sleep(3000);
        }
        else
        {
            printf("What is it?\n");
            rewind(stdin);
            char *personAnswer = (char *)calloc(size, sizeof(char));
            gets(personAnswer);
            printf("How is %s different from %s? Ask a question that can be answered yes or no.\n", personAnswer, cursor->data);
            rewind(stdin);
            char *question = (char *)calloc(size, sizeof(char));
            gets(question);
            printf("What is the answer to this question for %s?", personAnswer);
            int choice1;
            scanf_s("%d", &choice1);
            char *oldAnswer = cursor->data;
            if (choice1 == 1)
            {
                cursor->data = question;
                cursor->right = newNode(personAnswer);
                cursor->left = newNode(oldAnswer);
            }
            else
            {
                cursor->data = question;
                cursor->right = newNode(oldAnswer);
                cursor->left = newNode(personAnswer);
            }
        }
        system("cls");
    } while (choice());
    system("cls");
    return root;
}

bool choice()
{
    int ch;
    printf("Enter the 1 for continue play, or any button for end game : \n");
    scanf_s("%d", &ch);
    if (ch == 1)
        return true;
    else
        return false;
}

void saveBinaryTree(struct TreeNode *root, FILE *fp)
{
    if (root == NULL)
    {
        fputs("nullptr\n", fp);
        return;
    }
    fputs(root->data, fp);
    fputs("\n", fp);
    saveBinaryTree(root->left, fp);
    saveBinaryTree(root->right, fp);
}

struct TreeNode *readBinaryTree(FILE *fp)
{
    char *str = (char *)calloc(size, sizeof(char));
    fgets(str, size, fp);
    if (strcmp(str, "nullptr\n") == 0)
    {
        return NULL;
    }
    struct TreeNode *root = newNode(strtok(str, "\n"));
    root->left = readBinaryTree(fp);
    root->right = readBinaryTree(fp);
    return root;
}

void freeTree(struct TreeNode *root)
{
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);

    free(root);
}