class Queue {
    constructor() {
        this.head = [];
    }

    enqueue(data) {
        this.head.push(data);
    }

    dequeue() {
        return this.head.shift();
    }

    front() {
        return !this.isEmpty() ? this.head[0] : null;
    }

    isEmpty() {
        return this.head.length == 0 ? true : false;
    }
}

module.exports = Queue;