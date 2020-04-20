const LinkedList = require('../linkedlist');

function kthNodeFromLast(head, k) {
    if (head == null)
        return 0;
    let i = kthNodeFromLast(head.next, k) + 1;
    if (i == k)
        console.log(head.data);
    return i;
}

let list = new LinkedList();
list.add(1);
list.add(2);
list.add(4);
list.insert(3, 3);
list.insert(6, 6);
list.insert(5, 5);
// list.delete(5);
// list.print();
kthNodeFromLast(list.head, 5);
