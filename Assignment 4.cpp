#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Node {
public:
    char value;
    Node* left;
    Node* right;
    Node(char c) : value(c), left(NULL), right(NULL) {}
};

// Class to implement stack operations
class Stack {
    stack<Node*> st;

public:
    void push(Node* node) {
        st.push(node);
    }

    Node* pop() {
        if (st.empty()) return NULL;
        Node* node = st.top();
        st.pop();
        return node;
    }

    bool isEmpty() {
        return st.empty();
    }
};

// Class to implement expression tree and traversals
class ExpressionTree {
public:
    // Recursive traversals
    void inorderRecursive(Node* root) {
        if (root == NULL) return;
        inorderRecursive(root->left);
        cout << root->value << " ";
        inorderRecursive(root->right);
    }

    void preorderRecursive(Node* root) {
        if (root == NULL) return;
        cout << root->value << " ";
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }

    void postorderRecursive(Node* root) {
        if (root == NULL) return;
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        cout << root->value << " ";
    }

    // Non-recursive traversals
    void inorderNonRecursive(Node* root) {
        stack<Node*> s;
        Node* current = root;

        while (current != NULL || !s.empty()) {
            while (current != NULL) {
                s.push(current);
                current = current->left;
            }

            current = s.top();
            s.pop();
            cout << current->value << " ";
            current = current->right;
        }
    }

    void preorderNonRecursive(Node* root) {
        if (root == NULL) return;
        stack<Node*> s;
        s.push(root);

        while (!s.empty()) {
            Node* node = s.top();
            s.pop();
            cout << node->value << " ";

            if (node->right != NULL) s.push(node->right);
            if (node->left != NULL) s.push(node->left);
        }
    }

    void postorderNonRecursive(Node* root) {
        if (root == NULL) return;
        stack<Node*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            Node* node = s1.top();
            s1.pop();
            s2.push(node);

            if (node->left != NULL) s1.push(node->left);
            if (node->right != NULL) s1.push(node->right);
        }

        while (!s2.empty()) {
            Node* node = s2.top();
            s2.pop();
            cout << node->value << " ";
        }
    }

    // Build expression tree from postfix
    Node* buildTreeFromPostfix(const string& expr) {
        Stack stack;
        for (size_t i = 0; i < expr.length(); ++i) {
            char c = expr[i];
            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
                Node* op = new Node(c);
                Node* right = stack.pop();
                Node* left = stack.pop();
                op->left = left;
                op->right = right;
                stack.push(op);
            } else {
                stack.push(new Node(c));
            }
        }
        return stack.pop();
    }

    // Build expression tree from prefix
    Node* buildTreeFromPrefix(const string& expr) {
        Stack stack;
        for (int i = expr.length() - 1; i >= 0; --i) {
            char c = expr[i];
            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
                Node* op = new Node(c);
                Node* left = stack.pop();
                Node* right = stack.pop();
                op->left = left;
                op->right = right;
                stack.push(op);
            } else {
                stack.push(new Node(c));
            }
        }
        return stack.pop();
    }
};

int main() {
    ExpressionTree tree;
    string expr;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Build and traverse expression tree from postfix expression\n";
        cout << "2. Build and traverse expression tree from prefix expression\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 3) break;

        Node* root = NULL;

        if (choice == 1) {
            cout << "Enter postfix expression: ";
            cin >> expr;
            root = tree.buildTreeFromPostfix(expr);
        } else if (choice == 2) {
            cout << "Enter prefix expression: ";
            cin >> expr;
            root = tree.buildTreeFromPrefix(expr);
        }

        if (root == NULL) {
            cout << "Invalid expression.\n";
            continue;
        }

        int traversalChoice;
        cout << "\nTraversal options:\n";
        cout << "1. Inorder Traversal (Recursive)\n";
        cout << "2. Preorder Traversal (Recursive)\n";
        cout << "3. Postorder Traversal (Recursive)\n";
        cout << "4. Inorder Traversal (Non-Recursive)\n";
        cout << "5. Preorder Traversal (Non-Recursive)\n";
        cout << "6. Postorder Traversal (Non-Recursive)\n";
        cout << "Enter your choice: ";
        cin >> traversalChoice;

        switch (traversalChoice) {
            case 1:
                cout << "Inorder Traversal (Recursive): ";
                tree.inorderRecursive(root);
                break;
            case 2:
                cout << "Preorder Traversal (Recursive): ";
                tree.preorderRecursive(root);
                break;
            case 3:
                cout << "Postorder Traversal (Recursive): ";
                tree.postorderRecursive(root);
                break;
            case 4:
                cout << "Inorder Traversal (Non-Recursive): ";
                tree.inorderNonRecursive(root);
                break;
            case 5:
                cout << "Preorder Traversal (Non-Recursive): ";
                tree.preorderNonRecursive(root);
                break;
            case 6:
                cout << "Postorder Traversal (Non-Recursive): ";
                tree.postorderNonRecursive(root);
                break;
            default:
                cout << "Invalid choice.\n";
        }
        cout << endl;
    }

    return 0;
}

