#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

class Wall
{
public:
	Wall() :color(0)
	{
		cout << "构造一面墙" << endl;
	}
	void Paint(int newColor)
	{
		color = newColor;
		cout << "用新颜色粉刷墙" << endl;
	}
	int GetColor() const
	{
		return color;
	}
	virtual void display() {
		cout << "注明颜色：无色0红1橙2黄3绿4青5蓝6紫7其他8" << endl;
		cout << "Wall Color ? : " << this->GetColor() << endl;

	}
	virtual ~Wall() {
		cout << "析构Wall" << endl;
	}
private:
	int color;
};
class Door
{
public:
	Door() :openOrClose(false)
	{
		cout << "构造一扇门" << endl;
	}
	void Open()
	{
		if (!IsOpened())
		{
			openOrClose = true;
			cout << "门被打开了" << endl;
		}
		else
		{
			cout << "门开着呢！" << endl;
		}
	}
	void Close()
	{
		if (IsOpened())
		{
			openOrClose = false;
			cout << "门被关上了" << endl;
		}
		else
		{
			cout << "门关着呢！" << endl;
		}
	}
	bool IsOpened() const
	{
		return openOrClose;
	}
	virtual ~Door() {

	}
private:
	bool openOrClose;
};
//颜色：无色0红1橙2黄3绿4青5蓝6紫7其他8
class WallWithDoor : public Wall, public Door{
public:
	WallWithDoor() : Door(), Wall(){}
	WallWithDoor(bool fl,int cl) {
		this->Paint(cl);
		fl == true ? this->Open() : this->Close();
		if (cl == 1) this->Close();
		if (cl == 4) this->Open();
	}
	void display() {
		cout << "注明颜色：无色0红1橙2黄3绿4青5蓝6紫7其他8" << endl;
		cout << "Door is Open? :" << this->IsOpened() << endl;
		cout << "Wall Color ? : " << this->GetColor() << endl;
	}
};

class WallWithDoor_Combined {
private:
	Door x;
	Wall y;
public:
	WallWithDoor_Combined() : x(), y() {}
	WallWithDoor_Combined(bool fl, int cl) {
		y.Paint(cl);
		fl == true ? x.Open() : x.Close();
		if (cl == 1) x.Close();
		if (cl == 4) x.Open();
	}
	void display() {
		cout << "注明颜色：无色0红1橙2黄3绿4青5蓝6紫7其他8" << endl;
		cout << "Door is Open? :" << x.IsOpened() << endl;
		cout << "Wall Color ? : " << y.GetColor() << endl;
	}
};

int main() {
	WallWithDoor a1(true,1);
	WallWithDoor a2(true, 2);
	WallWithDoor a3(true, 4);
	WallWithDoor_Combined b1(true,1);
	WallWithDoor_Combined b2(true, 2);
	WallWithDoor_Combined b3(true, 4);
	Wall* p = new Wall();
	Wall* t1 = &a1;  //向上转换
	WallWithDoor* t2 = dynamic_cast<WallWithDoor*> (p);//向下转换
	cout << typeid(t2).name() << endl;
	p->display();
	a1.display();
	a2.display();
	a3.display();
	b1.display();
	b2.display();
	b3.display();
	return 0;
}