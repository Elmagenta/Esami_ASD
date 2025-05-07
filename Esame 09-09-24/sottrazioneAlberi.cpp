typedef struct Node {
    int key;
    Node* left;
    Node* right;
}* PNode;

void sottrazioneAlberi(PNode r1, PNode r2) {
    if (r1 && r2) {
        r1->key -= r2->key;
        sottrazioneAlberi(r1->left, r2->left);
        sottrazioneAlberi(r1->right, r2->right);
    }
}