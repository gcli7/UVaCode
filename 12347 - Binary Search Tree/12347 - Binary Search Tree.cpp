#include <cstdio>

using namespace std;

struct Node {
    Node(int n) : value(n), parent(NULL), left(NULL), right(NULL) {}
    
    int value;
    Node *parent;
    Node *left;
    Node *right;
};

Node *root;

void printResult(Node *n) {
    if(n->left != NULL)
        printResult(n->left);

    if(n->right != NULL)
        printResult(n->right);

    printf("%d\n", n->value);

}

int main(int argc, char **argv) {
    int input = 0;

    scanf("%d", &input);

    root = new Node(input);

    while(scanf("%d", &input) != -1) {
        Node *node = new Node(input);
        Node *p = root;

        while(true) {
            if(input > p->value) {
                if(p->right == NULL) {
                    p->right = node;
                    node->parent = p;

                    break;
                }
                else {
                    p = p->right;

                    continue;
                }
            }
            else {
                if(p->left == NULL) {
                    p->left = node;
                    node->parent = p;

                    break;
                }
                else {
                    p = p->left;

                    continue;
                }
            }
        }
    }
    printResult(root);

    return 0;
}