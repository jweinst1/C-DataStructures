#include <iostream>
/*
* Implements continous array of integers
*/

struct intlist {
	int items[10];
	intlist * ext;
};
//sets the initial ext pointer to NULL
intlist genintlist(){
	intlist gen;
	gen.ext = NULL;
	return gen;
}

class ContinousArr {
	public:
	intlist cont;
	int count;
	int capacity;
	ContinousArr(){
		this->cont = genintlist();
		this->last = intlist{NULL, NULL};
		this->cont.ext = &this->last;
		this->count = 0;
		this->capacity = 10;
		this->current = this->cont;
	}
	void set(int index, int value){
		if(index < 10){
			this->current.items[index] = value;
			this->current = this->cont;
		}
		else {
			if(this->is_end()){
				this->extend();
				this->movecurrent();
				this->set(index-10, value);
			}
			else {
				this->movecurrent();
				this->set(index-10, value);
			}
		}
	}
	//combs through the arrays and retrieves an integer
	int get(int index){
		if(index < 10){
			return this->current.items[index];
		}
		else {
			this->movecurrent();
			return this->get(index - 10);
		}
	}
	private:
	//used for extensions
	intlist last;
	intlist current;
	
	void extend(){
		intlist newnode = genintlist();
		this->cont.ext = &newnode;
		newnode.ext = &this->last;
		this->capacity += 10;
	}
	//moves the current reference up one.
	void movecurrent(){
		if(this->cont.ext != NULL){
			this->current = *this->cont.ext;
		}
	}
	//determines if current reference is an end.
	bool is_end(){
		return this->current.ext != NULL;
	}
};



int main() {
	ContinousArr a;
	a.set(14, 5);
	std::cout << a.get(14) << std::endl;
}
