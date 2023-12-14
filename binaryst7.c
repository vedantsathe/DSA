#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
    char name[50];
    char number[15];
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(char name[], char number[])
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    strcpy(newNode->name, name);
    strcpy(newNode->number, number);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode *insert(struct TreeNode *root, char name[], char number[])
{
    if (root == NULL)
    {
        return createNode(name, number);
    }

    if (strcmp(name, root->name) < 0)
    {
        root->left = insert(root->left, name, number);
    }
    else if (strcmp(name, root->name) > 0)
    {
        root->right = insert(root->right, name, number);
    }

    return root;
}

struct TreeNode *search(struct TreeNode *root, char name[])
{
    if (root == NULL || strcmp(name, root->name) == 0)
    {
        return root;
    }

    if (strcmp(name, root->name) < 0)
    {
        return search(root->left, name);
    }

    return search(root->right, name);
}

struct TreeNode *findMin(struct TreeNode *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct TreeNode *deleteNode(struct TreeNode *root, char name[])
{
    if (root == NULL)
    {
        return root;
    }

    if (strcmp(name, root->name) < 0)
    {
        root->left = deleteNode(root->left, name);
    }
    else if (strcmp(name, root->name) > 0)
    {
        root->right = deleteNode(root->right, name);
    }
    else
    {
        if (root->left == NULL)
        {
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode *temp = findMin(root->right);
        strcpy(root->name, temp->name);
        strcpy(root->number, temp->number);
        root->right = deleteNode(root->right, temp->name);
    }

    return root;
}

void inOrderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("Name: %s, Number: %s\n", root->name, root->number);
        inOrderTraversal(root->right);
    }
}

int main()
{
    struct TreeNode *root = NULL;
    int choice;
    char name[50], number[15];

    while (1)
    {
        printf("\nPhone Book Menu:\n");
        printf("1. Insert a new name and number\n");
        printf("2. Search for a name\n");
        printf("3. Delete a name\n");
        printf("4. Print entire phone list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the name to insert: ");
            scanf("%s", name);
            printf("Enter the phone number: ");
            scanf("%s", number);
            root = insert(root, name, number);
            printf("%s and %s added to the phone book.\n", name, number);
            break;
        case 2:
            printf("Enter the name to search for: ");
            scanf("%s", name);
            struct TreeNode *result = search(root, name);
            if (result != NULL)
            {
                printf("Number for %s: %s\n", result->name, result->number);
            }
            else
            {
                printf("%s not found in the phone book.\n", name);
            }
            break;
        case 3:
            printf("Enter the name to delete: ");
            scanf("%s", name);
            root = deleteNode(root, name);
            printf("%s removed from the phone book.\n", name);
            break;
        case 4:
            printf("Phone List:\n");
            inOrderTraversal(root);
            break;
        case 5:
            printf("Exiting the phone book.\n");
            exit(0);
        default:
            printf("Invalid choice. Please select a valid option (1-5).\n");
        }
    }

    return 0;
}
