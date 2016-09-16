#include <iostream>
//Implementaton of matrix class

class Matrix
{
	public:
	int mat[5][5];
	
	Matrix()
	{
		mat[5][5] = {};
	}
	
	void set(int x, int y, int val)
	{
		if(x < 5 && y < 5)
		{
			mat[x][y] = val;
		}
	}
	
	int get(int x, int y)
	{
		if(x < 5 && y < 5)
		{
			return mat[x][y];
		}
		return 0;
	}
	//prints all elements of the matrix
	void print()
	{
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				std::cout << mat[i][j];
			}
			std::cout << std::endl;
		}
	}
};


int main() {
	
}
