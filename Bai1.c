#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một nút trong cây nhị phân
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Hàm tạo một nút mới
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm chèn một nút vào cây nhị phân tìm kiếm (Binary Search Tree - BST)
struct Node *insertNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Duyệt Tiền Thứ Tự (Pre-order Traversal)
void preOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Duyệt Trung Thứ Tự (In-order Traversal)
void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Duyệt Hậu Thứ Tự (Post-order Traversal)
void postOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct Node *root = NULL;
    int n, value;

    printf("Nhập số lượng giá trị cần thêm vào cây: ");
    scanf("%d", &n);

    printf("Nhập các giá trị: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("\nDuyệt Tiền Thứ Tự: \n");
    preOrderTraversal(root);

    printf("\n\nDuyệt Trung Thứ Tự: \n");
    inOrderTraversal(root);

    printf("\n\nDuyệt Hậu Thứ Tự: \n");
    postOrderTraversal(root);

    return 0;
}
