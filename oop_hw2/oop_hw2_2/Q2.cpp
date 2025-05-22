#include <iostream>
using namespace std;

class Book {
private:
    int totalPages;
    int pagesRead;
public:
    Book(int total) : totalPages(total), pagesRead(0) {}
    void Read(int pages) { pagesRead += pages; if (pagesRead > totalPages) pagesRead = totalPages; }
    int GetTotalPages() const { return totalPages; }
    int GetPagesRead() const { return pagesRead; }
    int GetPagesLeft() const { return totalPages - pagesRead; }
};

void Test() {
    Book b(100);
    b.Read(30);
    std::cout << "Read: " << b.GetPagesRead() << ", Left: " << b.GetPagesLeft() << std::endl;
    b.Read(80);
    std::cout << "Read: " << b.GetPagesRead() << ", Left: " << b.GetPagesLeft() << std::endl;
}

int main(){
	Test(); 
	return 0;
}
