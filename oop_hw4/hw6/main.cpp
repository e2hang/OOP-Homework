#include <iostream>
#include <cstddef> 

class A {
private:
    int data[10]; // ģ������ڲ�����

    // ��̬��Ա����ͳ��
    static size_t createdCount;
    static size_t destroyedCount;
    static size_t totalAllocatedBytes;
    static size_t currentUsedBytes;

public:
    // ���� new
    void* operator new(size_t size) {
        createdCount++;
        totalAllocatedBytes += size;
        currentUsedBytes += size;
        std::cout << "[new] size = " << size << std::endl;
        return ::operator new(size);
    }

    // ���� delete
    void operator delete(void* ptr, size_t size) {
        destroyedCount++;
        currentUsedBytes -= size;
        std::cout << "[delete] size = " << size << std::endl;
        ::operator delete(ptr);
    }

    // ���� new[]
    void* operator new[](size_t size) {
        // �����ڿ��ܺ�������󣬼���������
        createdCount++; // ע�⣺����ֻͳ��һ�Σ��ɸ���ϸͳ��
        totalAllocatedBytes += size;
        currentUsedBytes += size;
        std::cout << "[new[]] size = " << size << std::endl;
        return ::operator new[](size);
    }

    // ���� delete[]
    void operator delete[](void* ptr, size_t size) {
        destroyedCount++; // ͬ��
        currentUsedBytes -= size;
        std::cout << "[delete[]] size = " << size << std::endl;
        ::operator delete[](ptr);
    }

    // ͳ����Ϣ
    static void showStats() {
        std::cout << "Created: " << createdCount << std::endl;
        std::cout << "Destroyed: " << destroyedCount << std::endl;
        std::cout << "Total allocated: " << totalAllocatedBytes << " bytes" << std::endl;
        std::cout << "Current in use: " << currentUsedBytes << " bytes" << std::endl;
    }
};

// ��̬��Ա��ʼ��
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

