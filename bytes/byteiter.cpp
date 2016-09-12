#include <iostream>
#include <string>
//iterator to take in string, and iterate unsigned chars

/*
Uses default arguments to accept input of string or const char *
*/

class byteIter
{
	public:
	std::string data;
	unsigned char current;
	
	byteIter(const char* input = "")
	{
		data = input;
		index = 0;
		iter = true;
	}
	
	unsigned char next()
	{
		if(iter)
		{
			current = data[index];
			index++;
			if(index == data.size()) iter = false;
			return current;
		}
	}
	
	unsigned char last()
	{
		return current;
	}
	
	private:
	int index;
	bool iter;
};


int main() {
	byteIter b;
	std::cout << "enter something >";
	std::cin >> b.data;
	for(int i=0; i<b.data.size();i++) std::cout << b.next();
}
