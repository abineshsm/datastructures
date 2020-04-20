let Node = function(data, next = null){
    this.data = data;
    this.next = next;
}

let MinStack = function(){
    this.head = null;
}

MinStack.prototype.push = (data) => {
    let node = new Node(data);
    if (!this.head) {
        this.head = node;
        return;
    }
    node.next = this.head;
    this.head = node;
}

MinStack.prototype.pop = () => {
    if (!this.head)
        return;
    this.head = this.head.next;
}

MinStack.prototype.top = () => {
    if (!this.head)
        return null;
    return this.head.data;
}

MinStack.prototype.getMin = () => {
    if (!this.head)
        return null;
    let current = this.head;
    let min = Number.POSITIVE_INFINITY;
    while (current != null) {
        if (current.data < min)
            min = current.data;
        current = current.next;
    }
    return min;
}

let stack = new MinStack();
stack.push(-200);
stack.push(1);
stack.push(2);
console.log(stack.getMin());
console.log(stack.top());
stack.pop();
console.log(stack.top());
