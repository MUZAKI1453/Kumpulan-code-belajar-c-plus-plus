#include <iostream>
using namespace std;

class TreeNode {
    public:
        char data;
        TreeNode* left;     // pointer ke anak kiri
        TreeNode* right;    // pointer ke anak kanan

        // ini adalah constructor untuk inisialisasi node baru
        TreeNode(char val) : data(val), left(nullptr), right(nullptr) {

        }

};

int main() {

    // Membuat instance dari TreeNode
    TreeNode* root = new TreeNode('A');
    TreeNode* nodeB = new TreeNode('B');
    TreeNode* nodeC = new TreeNode('C');
    TreeNode* nodeD = new TreeNode('D');
    TreeNode* nodeE = new TreeNode('E');
    TreeNode* nodeF = new TreeNode('F');
    TreeNode* nodeG = new TreeNode('G');

    // membangun struktur pohon
    root-> left   = nodeB;
    root-> right  = nodeC;

    nodeB-> left  = nodeD;
    nodeB-> right = nodeE;

    nodeC-> left  = nodeF;
    nodeC-> right = nodeG;

    // mengakses data
    cout << "akses data" << endl;
    cout << "root -> left  -> right -> data : " << root -> left  -> left -> data << endl;
    cout << "root -> right -> left  -> data : " << root -> right -> left -> data << endl;

    return 0;
}
