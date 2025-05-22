#include <iostream>
#include "page.h"
using std::cin;
using std::cout;
using std::endl;

int main() {
    Paginate pager(13);
    for (int i = 1;i <= 13;i++)
    {
        //i当前页，13总页数
        pager.setPage(i).show();
    }
    cout << "START MOVING...." << endl;
    pager.setPage(5).show();
    pager.next().show();
    pager.prev().show();
    //直接翻5页
    pager.nextN().show();
    pager.next().show();
    pager.prevN().show();
    return 0;
}