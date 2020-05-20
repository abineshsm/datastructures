const BinarySearchTree = require('../binary_search_tree');

function isBalanced(bst) {
    return Math.abs(bst.height(bst.root.left) - bst.height(bst.root.right)) > 1 ? false : true;
}

let bst = new BinarySearchTree();
bst.root = bst.insert(bst.root, 11);
bst.root = bst.insert(bst.root, 6);
bst.root = bst.insert(bst.root, 15);
bst.root = bst.insert(bst.root, 17);
bst.root = bst.insert(bst.root, 5);
bst.root = bst.insert(bst.root, 3);
console.log(isBalanced(bst));