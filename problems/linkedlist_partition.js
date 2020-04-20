const { ListNode, LinkedList } = require('../linkedlist');

function partition(head, pIndex) {
    let lowHead = new ListNode(0);
    let highHead = new ListNode(0);
    let low = lowHead;
    let high = highHead;

    while (head != null) {
        if (head.data < pIndex) {
            low.next = head;
            low = low.next;
        } else {
            high.next = head;
            high = high.next;
        }
        head = head.next;
    }
    low.next = highHead.next;
    lowHead = lowHead.next;
    return lowHead;
}

let list = new LinkedList();
list.add(9);
list.add(1);
list.add(2);
list.add(5);
list.add(1);
list.add(7);
// list.print();
list.head = partition(list.head, 4);
list.print();