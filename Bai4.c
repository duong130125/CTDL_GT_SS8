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

// Hàm thêm đỉnh vào cây theo dạng nhị phân (cho ví dụ đơn giản)
struct Node *insert(struct Node *root, int parentData, int childData, char direction)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == parentData)
    {
        if (direction == 'L')
        {
            root->left = createNode(childData);
        }
        else if (direction == 'R')
        {
            root->right = createNode(childData);
        }
        return root;
    }

    insert(root->left, parentData, childData, direction);
    insert(root->right, parentData, childData, direction);
    return root;
}

// Hàm tính chiều cao của cây bằng đệ quy
int calculateHeight(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Hàm hiển thị cây theo thứ tự trước (Preorder Traversal)
void displayTree(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    displayTree(root->left);
    displayTree(root->right);
}

int main()
{
    // Tạo gốc của cây
    struct Node *root = createNode(1);

    // Thêm các đỉnh vào cây
    insert(root, 1, 2, 'L');
    insert(root, 1, 3, 'R');
    insert(root, 2, 4, 'L');
    insert(root, 2, 5, 'R');
    insert(root, 3, 6, 'L');

    // Hiển thị các đỉnh của cây
    printf("Cac dinh trong cay: ");
    displayTree(root);
    printf("\n");

    // Tính chiều cao của cây
    int height = calculateHeight(root);
    printf("Chieu cao cua cay: %d\n", height);

    return 0;
}
