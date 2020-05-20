var Node = function (key, value, next = null, prev = null) {
    this.key = key;
    this.value = value;
    this.prev = prev;
    this.next = next;
}

var LRUCache = function (capacity) {
    this.capacity = capacity;
    this.head = null;
    this.tail = null;
    this.size = 0;
    this.cache = {};
};

LRUCache.prototype.get = function (key) {
    if (this.cache.hasOwnProperty(key)) {
        let value = this.cache[key].value;
        this.remove(key);
        this.put(key, value);
        return value;
    }
    else
        return -1;
};

LRUCache.prototype.put = function (key, value) {
    if (this.cache.hasOwnProperty(key))
        this.remove(key);
    if (this.size == this.capacity)
        this.remove(this.tail.key);
        
    if (this.head == null)
        this.head = this.tail = new Node(key, value);
    else {
        let node = new Node(key, value, this.head);
        this.head.prev = node;
        this.head = node;
    }
    this.cache[key] = this.head;
    this.size++;
};

LRUCache.prototype.remove = function (key) {
    let node = this.cache[key];
    if (node) {
        if (this.head == node)
            this.head = node.next;
        else
            node.prev.next = node.next;

        if (this.tail == node)
            this.tail = node.prev;
        else
            node.next.prev = node.prev;

        delete this.cache[key];
        this.size--;
    }
}


var obj = new LRUCache(2)
console.log(obj.get(2))
obj.put(2, 6)
console.log(obj.get(1))
obj.put(1, 5)
obj.put(1, 2)
console.log(obj.cache)
console.log(obj.get(1))
console.log(obj.get(2));
// console.log(obj.cache)
