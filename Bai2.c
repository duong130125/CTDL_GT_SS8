#include <stdio.h>
#include <stdlib.h>

// Cấu trúc một nút trong cây
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Hàm tạo một nút mới
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm thêm một nút con trái hoặc phải vào cây
void addChild(Node *parent, int data, char side)
{
    if (side == 'L')
    {
        parent->left = createNode(data);
    }
    else if (side == 'R')
    {
        parent->right = createNode(data);
    }
}

// Hàm tìm và in các đỉnh ở lớp 2
void findLevel2Nodes(Node *root)
{
    if (root == NULL)
    {
        printf("Cây rỗng.\n");
        return;
    }

    // Kiểm tra nếu nút gốc có các con
    if (root->left == NULL && root->right == NULL)
    {
        printf("Không có đỉnh lớp 2.\n");
        return;
    }

    printf("Các đỉnh lớp 2: ");
    if (root->left)
    {
        if (root->left->left)
            printf("%d ", root->left->left->data);
        if (root->left->right)
            printf("%d ", root->left->right->data);
    }
    if (root->right)
    {
        if (root->right->left)
            printf("%d ", root->right->left->data);
        if (root->right->right)
            printf("%d ", root->right->right->data);
    }
    printf("\n");
}

// Hàm duyệt cây theo thứ tự trước (hỗ trợ hiển thị cấu trúc cây)
void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    // Tạo cây mẫu
    Node *root = createNode(1);    // Gốc là 1
    addChild(root, 2, 'L');        // Thêm 2 là con trái của 1
    addChild(root, 3, 'R');        // Thêm 3 là con phải của 1
    addChild(root->left, 4, 'L');  // Thêm 4 là con trái của 2
    addChild(root->left, 5, 'R');  // Thêm 5 là con phải của 2
    addChild(root->right, 6, 'L'); // Thêm 6 là con trái của 3

    // Hiển thị cấu trúc cây
    printf("Cấu trúc cây (duyệt trước): ");
    preorderTraversal(root);
    printf("\n");

    // Tìm và hiển thị các đỉnh ở lớp 2
    findLevel2Nodes(root);

    return 0;
}
