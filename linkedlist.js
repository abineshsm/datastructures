class ListNode {
    constructor(data, next = null) {
        this.data = data;
        this.next = next;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
    }

    add(data) {
        let node = new ListNode(data);
        if (!this.head) {
            this.head = node;
            return;
        }
        let current = this.head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = node;
    }

    insert(data, pos) {
        let node = new ListNode(data);
        if (!this.head) {
            this.head = node;
            return;
        }
        let current = this.head;
        while (current.next != null && pos > 2) {
            current = current.next;
            pos--;
        }
        let temp = current.next;
        current.next = node;
        node.next = temp;
    }

    delete(index) {
        if (!this.head)
            return;
        if (index == 1) {
            this.head = this.head.next;
            return;
        }
        let prev = null;
        let current = this.head;
        while (current.next != null && index > 1) {
            prev = current;
            current = current.next;
            index--;
        }
        prev.next = current.next;
    }

    print() {
        let current = this.head;
        while (current != null) {
            console.log(current.data);
            current = current.next;
        }
    }

    isEmpty() {
        return this.head ? false : true;
    }
}

module.exports = { ListNode, LinkedList };


// let list = new LinkedList();
// list.add(1);
// list.add(2);
// list.add(4);
// list.insert(3, 3);
// list.insert(6,6);
// list.insert(5, 5);
// list.delete(5);
// list.print();