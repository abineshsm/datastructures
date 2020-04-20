let MinStack = function () {
    this.head = [];
    this.tail = -1;
}

MinStack.prototype.push = function (data) {
    this.head.push(data);
    this.tail++;
}

MinStack.prototype.pop = function () {
    this.head.pop();
    --this.tail;
    this.tail = this.tail < -1 ? -1 : this.tail;
}

MinStack.prototype.top = function(){
    return this.tail >= 0 ? this.head[this.tail] : null;
}

MinStack.prototype.getMin = function(){
    let min = Number.POSITIVE_INFINITY;
    this.head.forEach(item => {
        if(item < min)
            min = item;
    })
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