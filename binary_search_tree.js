class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class BinarySearchTree {
    constructor() {
        this.root = null;
    }

    insert(root, data) {
        if (root == null)
            root = new Node(data);
        else if (data <= root.data)
            root.left = this.insert(root.left, data);
        else root.right = this.insert(root.right, data);
        return root;
    }

    inorderPrint(root) {
        if (root == null)
            return;
        this.inorderPrint(root.left);
        console.log(root.data);
        this.inorderPrint(root.right);
    }

    height(root) {
        if (root == null)
            return -1;
        // console.log("height of - ", root.data);
        return Math.max(this.height(root.left), this.height(root.right)) + 1;
    }

    diameter(root) {
        if (root == null)
            return -1;
        return Math.max(this.height(root.left) + this.height(root.right) + 2, this.diameter(root.left), this.diameter(root.right));
    }
}

let bst = new BinarySearchTree();
bst.root = bst.insert(bst.root, 11);
bst.root = bst.insert(bst.root, 6);
// bst.root = bst.insert(bst.root, 15);
bst.root = bst.insert(bst.root, 5);
bst.root = bst.insert(bst.root, 3);
// bst.root = bst.insert(bst.root, 7);
// bst.root = bst.insert(bst.root, 8);
// bst.root = bst.insert(bst.root, 9);
// bst.root = bst.insert(bst.root, 10);
bst.root = bst.insert(bst.root, 2);
// bst.inorderPrint(bst.root);
console.log(bst.diameter(bst.root));