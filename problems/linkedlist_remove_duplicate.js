const LinkedList = require('../js_linkedlist');

let list = new LinkedList();
list.add(1);
list.add(2);
list.add(4);
list.insert(3, 3);
list.insert(6,6);
list.insert(5, 5);
list.delete(5);
list.print();