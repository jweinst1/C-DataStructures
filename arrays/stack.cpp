#include <iostream>
//implements basic stack without vector backbone

template <class T> class Stack {
	//internal struct for nodes
	struct stackNode {
		T elem;
		stackNode * next;
	};
	
	public:
	stackNode items;
	int size;
	
	Stack(){
		this->size = 0;
	}
	//returns top item on stack
	T top(){
		if(this->size != 0) {
			return this->items.elem;
		}
		else {
			throw "Empty Stack";
		}
	}
	
	void push(T elem) {
		if(this->size == 0){
			this->items = {elem, NULL};
			this->size++;
		}
		else {
			//extends the stack chain forward.
			stackNode newnode = {elem, &this->items};
			this->items = newnode;
			this->size++;
		}
	}
	//returns the top element;
	T pop(){
		if(this->size == 1){
			T retrieved = this->items.elem;
			this->items = NULL;
			this->size = 0;
			return retrieved;
		}
		else if(this->size > 1) {
			T retrieved = this->items.elem;
			this->items = *this->items.next;
			this->size--;
			return retrieved;
		}
	}
};



int main() {
	Stack<int> r;
	r.push(3);
	r.push(7);
	std::cout << r.top() << std::endl;
}
//7
