#include <iostream>

/*
* Implements an integer set
* Can absolutely determine if integers are present in a set, as well as add
* or remove them from membership
*/

class intset
{
	public:
	bool * items;
	int count;
	intset()
	{
		this->items[0] = {};
		this->count = 0;
		this->max = 0;
	}
	void add(int elem)
	{
		if(elem <= this->max)
		{
			this->items[elem] = true;
		}
		else
		{
			//if int is too high, expands the set
			this->putHigher(elem);
		}
	}
	//checks for set membership
	bool contains(int elem)
	{
		return this->items[elem] == true;
	}
	
	//removes from set
	void remove(int elem)
	{
		if(elem <= this->max)
		{
			this->items[elem] = false;
		}
	}
	private:
	int max;
	//method to increase max size of set, and have new max element
	void putHigher(int newmax)
	{
		bool * newarr;
		newarr[newmax] = {};
		std::copy(this->items, this->items+this->max, newarr);
		this->items = newarr;
		this->items[newmax] = true;
		this->count++;
	}
};

int main()
{
	intset i;
	i.add(4);
	std::cout << "true" << std::endl;
}
