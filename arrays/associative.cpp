#include <iostream>
#include <string>

/*
* Implements associative array
Does not use a hash function, just swapping priority 
*/

template<class T>
class Amap
{
	struct item
	{
		std::string key;
		T value;
	};
	public:
	item items[];
	Amap()
	{
		this->size = 20;
		this->last = -1;
		this->items[20] = {};
	}
	
	void set(std::string key, T val)
	{
		if(this->last < this->size-1)
		{
			this->last++;
			items[this->last] = item{key, val};
		}
		//calls extension function
		else
		{
			this->extend();
			this->last++;
			items[this->last] = item{key, val};
		}
	}
	//gets an item based on its key
	T get(std::string key)
	{
		for(int i=0;i<this->size;i++)
		{
			if(this->items[i].key.compare(key) == 0)
			{
				T ret = this->items[i].value;
				this->placefront();
				return ret;
			}
		}
	}
	
	private:
	int size;
	int last;
	
	void extend(){
		int newsize = this->size + 20;
		item newarr[newsize];
		for(int i=0;i<this->size;i++)
		{
			newarr[i] = this->items[i];
		}
		this->items = newarr;
		this->size = newsize;
	}
	
	void placefront(int index)
	{
		item hold = this->items[index];
		this->items[index] = this->items[0];
		this->items[0] = hold;
	}
};

int main() {
	Amap<int> d;
	d.set("foo", 6);
	std::cout << d.get("foo") << std::endl;
}
