#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Cấu trúc dữ liệu cho nút của cây nhị phân
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Hàm tạo nút mới
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm kiểm tra đệ quy tính chất BST
bool isBSTUtil(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return true; // Cây rỗng là BST
    }

    // Kiểm tra nếu giá trị nút không nằm trong khoảng hợp lệ
    if (root->data <= min || root->data >= max)
    {
        return false;
    }

    // Kiểm tra đệ quy cho cây con trái và cây con phải
    return isBSTUtil(root->left, min, root->data) && isBSTUtil(root->right, root->data, max);
}

// Hàm chính kiểm tra BST
bool isBST(Node *root)
{
    return isBSTUtil(root, -2147483648, 2147483647); // Khoảng giá trị mặc định của int
}

// Hàm chính
int main()
{
    // Tạo cây ví dụ 1
    Node *root1 = createNode(10);
    root1->left = createNode(5);
    root1->right = createNode(15);
    root1->left->left = createNode(3);
    root1->left->right = createNode(7);
    root1->right->left = createNode(12);
    root1->right->right = createNode(20);

    if (isBST(root1))
    {
        printf("Cây 1 là cây nhị phân tìm kiếm (BST).\n");
    }
    else
    {
        printf("Cây 1 không là cây nhị phân tìm kiếm.\n");
    }

    // Tạo cây ví dụ 2
    Node *root2 = createNode(10);
    root2->left = createNode(5);
    root2->right = createNode(15);
    root2->left->left = createNode(6);
    root2->left->right = createNode(7);
    root2->right->left = createNode(12);
    root2->right->right = createNode(20);

    if (isBST(root2))
    {
        printf("Cây 2 là cây nhị phân tìm kiếm (BST).\n");
    }
    else
    {
        printf("Cây 2 không là cây nhị phân tìm kiếm.\n");
    }

    // Trường hợp cây rỗng
    Node *root3 = NULL;
    if (isBST(root3))
    {
        printf("Cây 3 là cây nhị phân tìm kiếm (BST).\n");
    }
    else
    {
        printf("Cây 3 không là cây nhị phân tìm kiếm.\n");
    }

    return 0;
}
