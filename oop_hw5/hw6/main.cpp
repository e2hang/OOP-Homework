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
		cout << "����һ��ǽ" << endl;
	}
	void Paint(int newColor)
	{
		color = newColor;
		cout << "������ɫ��ˢǽ" << endl;
	}
	int GetColor() const
	{
		return color;
	}
	virtual void display() {
		cout << "ע����ɫ����ɫ0��1��2��3��4��5��6��7����8" << endl;
		cout << "Wall Color ? : " << this->GetColor() << endl;

	}
	virtual ~Wall() {
		cout << "����Wall" << endl;
	}
private:
	int color;
};
class Door
{
public:
	Door() :openOrClose(false)
	{
		cout << "����һ����" << endl;
	}
	void Open()
	{
		if (!IsOpened())
		{
			openOrClose = true;
			cout << "�ű�����" << endl;
		}
		else
		{
			cout << "�ſ����أ�" << endl;
		}
	}
	void Close()
	{
		if (IsOpened())
		{
			openOrClose = false;
			cout << "�ű�������" << endl;
		}
		else
		{
			cout << "�Ź����أ�" << endl;
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
//��ɫ����ɫ0��1��2��3��4��5��6��7����8
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
		cout << "ע����ɫ����ɫ0��1��2��3��4��5��6��7����8" << endl;
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
		cout << "ע����ɫ����ɫ0��1��2��3��4��5��6��7����8" << endl;
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
	Wall* t1 = &a1;  //����ת��
	WallWithDoor* t2 = dynamic_cast<WallWithDoor*> (p);//����ת��
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