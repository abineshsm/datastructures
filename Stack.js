class Stack {
    constructor() {
        this.head = [];
    }

    push(data) {
        this.head.push(data);
    }

    pop() {
        return this.head.pop();
    }

    isEmpty() {
        return this.head.length == 0 ? true : false;
    }

    top() {
        return this.isEmpty() ? null : this.head[this.head.length - 1];
    }
}

module.exports = Stack;