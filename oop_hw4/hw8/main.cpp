#include <iostream>
#include "page.h"
using std::cin;
using std::cout;
using std::endl;

int main() {
    Paginate pager(13);
    for (int i = 1;i <= 13;i++)
    {
        //i��ǰҳ��13��ҳ��
        pager.setPage(i).show();
    }
    cout << "START MOVING...." << endl;
    pager.setPage(5).show();
    pager.next().show();
    pager.prev().show();
    //ֱ�ӷ�5ҳ
    pager.nextN().show();
    pager.next().show();
    pager.prevN().show();
    return 0;
}