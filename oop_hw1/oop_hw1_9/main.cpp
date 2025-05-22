#include <iostream>
#include <string>
#include <vector>

class Pen {
public:
    void write() {}
};

class FountainPen : public Pen {
public:
    void refill() {}
};

class File {
public:
    std::string name;
};

class Directory {
public:
    std::vector<File> files;
};

class Printer {
public:
    void print(const std::string& doc) {}
};

class Monitor {
public:
    void display(const std::string& img) {}
};

class Sun {
public:
    void shine() {}
};

class Moon {
public:
    void reflect() {}
};
