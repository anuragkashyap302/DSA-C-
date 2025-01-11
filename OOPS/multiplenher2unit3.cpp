#include <iostream>
using namespace std;
// Base class Shape
class Shape // base class 1
{
protected:
	int width;
	int height;
public:
	void setWidth(int w)
	{
		width = w;
	}
	void setHeight(int h)
	{
		height = h;
	}

};

// Base class PaintCost
class PaintCost // second base class
{
	public:
	int getCost(int area)
		{
			return area * 70;
		}
};
// Derived class
class Rectangle: public Shape, protected PaintCost
{
	public:
	int getArea()
	{
		return (width * height);
	}
};

int main()
{
	Rectangle Rect;
	int area;
	Rect.setWidth(5);
	Rect.setHeight(7);
	area = Rect.getArea();
	// Print the area of the object.
	cout << "Total area: " << Rect.getArea() << endl;
	// Print the total cost of painting
//	cout << "Total paint cost: Rs" << Rect.getCost(area) << endl;
	return 0;
}