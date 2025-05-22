#include <iostream>
#include <cstddef> 

class A {
private:
    int data[10]; // 模拟对象内部数据

    // 静态成员用于统计
    static size_t createdCount;
    static size_t destroyedCount;
    static size_t totalAllocatedBytes;
    static size_t currentUsedBytes;

public:
    // 重载 new
    void* operator new(size_t size) {
        createdCount++;
        totalAllocatedBytes += size;
        currentUsedBytes += size;
        std::cout << "[new] size = " << size << std::endl;
        return ::operator new(size);
    }

    // 重载 delete
    void operator delete(void* ptr, size_t size) {
        destroyedCount++;
        currentUsedBytes -= size;
        std::cout << "[delete] size = " << size << std::endl;
        ::operator delete(ptr);
    }

    // 重载 new[]
    void* operator new[](size_t size) {
        // 数组内可能含多个对象，加起来计算
        createdCount++; // 注意：这里只统计一次，可更精细统计
        totalAllocatedBytes += size;
        currentUsedBytes += size;
        std::cout << "[new[]] size = " << size << std::endl;
        return ::operator new[](size);
    }

    // 重载 delete[]
    void operator delete[](void* ptr, size_t size) {
        destroyedCount++; // 同上
        currentUsedBytes -= size;
        std::cout << "[delete[]] size = " << size << std::endl;
        ::operator delete[](ptr);
    }

    // 统计信息
    static void showStats() {
        std::cout << "Created: " << createdCount << std::endl;
        std::cout << "Destroyed: " << destroyedCount << std::endl;
        std::cout << "Total allocated: " << totalAllocatedBytes << " bytes" << std::endl;
        std::cout << "Current in use: " << currentUsedBytes << " bytes" << std::endl;
    }
};

// 静态成员初始化
size_t A::createdCount = 0;
size_t A::destroyedCount = 0;
size_t A::totalAllocatedBytes = 0;
size_t A::currentUsedBytes = 0;

int main() {
    A* a1 = new A;
    A* a2 = new A;
    delete a1;

    A* arr = new A[3];
    delete[] arr;

    A::showStats();
    return 0;
}

