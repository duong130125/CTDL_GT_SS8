#include <stdio.h>
#include <stdlib.h>

// Cấu trúc của một nút trong cây
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

// Hàm thêm đỉnh vào cây tìm kiếm nhị phân
struct Node *insertBST(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insertBST(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertBST(root->right, data);
    }

    return root;
}

// Hàm tìm kiếm giá trị trong cây
int searchBST(struct Node *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->data == key)
    {
        return 1;
    }
    else if (key < root->data)
    {
        return searchBST(root->left, key);
    }
    else
    {
        return searchBST(root->right, key);
    }
}

// Hàm duyệt cây theo thứ tự tăng dần (Inorder Traversal)
void inorderTraversal(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main()
{
    struct Node *root = NULL;

    // Trường hợp 1: Chèn và duyệt cây
    int values1[] = {5, 3, 7, 2, 4, 6, 8};
    int n1 = sizeof(values1) / sizeof(values1[0]);
    for (int i = 0; i < n1; i++)
    {
        root = insertBST(root, values1[i]);
    }

    printf("Duyet cay theo thu tu inorder: ");
    inorderTraversal(root);
    printf("\n");

    // Trường hợp 2: Tìm kiếm giá trị trong cây (có tồn tại)
    int searchValue1 = 7;
    if (searchBST(root, searchValue1))
    {
        printf("Gia tri %d ton tai trong cay.\n", searchValue1);
    }
    else
    {
        printf("Gia tri %d khong ton tai trong cay.\n", searchValue1);
    }

    // Trường hợp 3: Tìm kiếm giá trị trong cây (không tồn tại)
    int searchValue2 = 10;
    if (searchBST(root, searchValue2))
    {
        printf("Gia tri %d ton tai trong cay.\n", searchValue2);
    }
    else
    {
        printf("Gia tri %d khong ton tai trong cay.\n", searchValue2);
    }

    return 0;
}
