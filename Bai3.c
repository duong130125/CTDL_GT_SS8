#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Hàm tạo nút mới
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm chèn giá trị vào cây
struct Node *insertNode(struct Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Hàm tìm kiếm giá trị trong cây
int search(struct Node *root, int value)
{
    if (root == NULL)
    {
        printf("Not Found\n");
        return 0;
    }
    if (root->data == value)
    {
        printf("Found\n");
        return 1;
    }
    if (value < root->data)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
}

// Hàm main
int main()
{
    struct Node *root = NULL;

    // Chèn các giá trị vào cây
    root = insertNode(root, 20);
    root = insertNode(root, 10);
    root = insertNode(root, 30);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 25);
    root = insertNode(root, 35);

    // Tìm kiếm các giá trị trong cây
    int value;

    printf("Nhập giá trị cần tìm: ");
    scanf("%d", &value);
    search(root, value);

    printf("Nhập giá trị khác để tìm kiếm: ");
    scanf("%d", &value);
    search(root, value);

    return 0;
}
