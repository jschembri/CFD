#include <iostream>
using namespace std;

class CRectangle{
	int x,y;
	public:
		void set_values(int,int);
		int area(){
			return x*y;
		}
};

class Triangle {
		int height, base;
	public:
		Triangle (int,int);
		double area(){
			return height*base /2;
		}
};	

void CRectangle::set_values(int a, int b){
	x = a;
	y = b;
}

Triangle::Triangle(int a, int b){
	height = a;
	base = b;
}

int main(){
	CRectangle rect;
	Triangle tri (2,2);
	rect.set_values(3,4);
	cout <<"area: " << rect.area() << endl;
	cout << "Triangle Area is: "<< tri.area() << endl;
	return 0;

}
