const BinarySearchTree = require('../BinarySearchTree')

var isCousins = function (root, x, y) {
    
};

var depth = function (root, x, parent, level) {
    if(root == null)
        return null
    if(root.data == x)
        return {parent, level}
    let left = depth(root.left, x, root, level + 1)
    let right = depth(root.right, x, root, level + 1)
    return left ? left : right; 
}

let bst = new BinarySearchTree();
bst.root = bst.insert(bst.root, 5);
bst.root = bst.insert(bst.root, 4);
bst.root = bst.insert(bst.root, 6);
bst.root = bst.insert(bst.root, 7);
bst.root = bst.insert(bst.root, 2);
// bst.inorderPrint(bst.root);

var a = depth(bst.root, 7, null, 0)
var b = depth(bst.root, 2, null, 0)
console.log(a.parent == b.parent)
