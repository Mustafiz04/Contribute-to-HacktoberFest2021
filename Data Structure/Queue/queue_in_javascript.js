class Node {
	constructor(value) {
		this.value = value;
		this.next = null;
	}
}

class Queue {
	constructor(value) {
		this.first = new Node(value);
		this.last = this.first;
		this.length = 1;
	}

	// adds the element to the last of Queue
	// constant time complexity
	enqueue(value = null) {
		if (!value) {
			console.log("Cannot push to the Queue: Value Empty");
			return;
		}
		const newNode = new Node(value);
		this.last.next = newNode;
		this.last = newNode;
		this.length++;
	}

	// removes the element from the first of the Queue
	// constant time complex...
	dequeue() {
		if (this.isEmpty()) {
			console.log("Cannot pop from the Queue : Queue Empty");
			return;
		}
		const unWantedNode = this.first;
		console.log("Node deleted from first : ", unWantedNode.value);
		if (this.first === this.last) {
			this.first = null;
			this.last = null;
		} else {
			this.first = this.first.next;
		}
		this.length--;
	}

	// traverse through the list
	// linear time
	traverse() {
		if (this.isEmpty()) {
			console.log("Cannot traverse : Queue Empty");
			return;
		}
		let leader = this.first;
		console.log("Queue displayed : ");
		while (leader) {
			console.log(leader.value);
			leader = leader.next;
		}
	}

	// returns the top element from the Queue
	// constant time
	peek() {
		if (this.isEmpty()) {
			console.log("Cannot peek from the Queue : Queue Empty");
			return;
		}
		console.log("Peek Node value : ", this.first.value);
		return this.first;
	}

	// checks if the Queue is empty
	// constant time complexity
	isEmpty() {
		if (!this.first) {
			return true;
		}
		return false;
	}
}

const myQueue = new Queue(10);
myQueue.enqueue(20);
myQueue.enqueue(30);
myQueue.enqueue(40);
myQueue.traverse();
myQueue.peek();
myQueue.dequeue();
myQueue.dequeue();
myQueue.dequeue();
myQueue.dequeue();
myQueue.dequeue();
myQueue.peek();
console.log(myQueue);
