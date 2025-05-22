#include <iostream>
#include <cstdlib>

#include <iostream>
#include <cstdlib>

class TRandom {
private:
    unsigned long seed;
public:
    TRandom(unsigned long s) : seed(s) {}
    unsigned char NextByte() {
        seed = seed * 1103515245 + 12345;
        return static_cast<unsigned char>((seed / 65536) % 256);
    }
};

void Coder(unsigned char data[], int len, unsigned long key) {
    TRandom rand(key);
    for (int i = 0; i < len; ++i) {
        data[i] ^= rand.NextByte();
    }
}

void Coder(unsigned char data[], int len, TRandom& rand, unsigned long key) {
    for (int i = 0; i < len; ++i) {
        data[i] ^= rand.NextByte();
    }
}

class Crypter {
private:
    TRandom rand;
public:
    Crypter(unsigned long seed) : rand(seed) {}
    void Process(unsigned char data[], int len) {
        for (int i = 0; i < len; ++i) {
            data[i] ^= rand.NextByte();
        }
    }
};

void Test() {
    unsigned char msg[] = "Hello World";
    int len = sizeof(msg);
    unsigned long key = 12345;
    std::cout << "Original: " << msg << std::endl;
    Coder(msg, len, key);
    std::cout << "Encrypted: "; for (int i = 0; i < len; ++i) std::cout << msg[i]; std::cout << std::endl;
    Coder(msg, len, key);
    std::cout << "Decrypted: " << msg << std::endl;
}


int main(){
	Test(); 
	return 0;
} 

// 问题3：将 rand 改为 TRandom rand（传值），会丢失原状态，重复初始化种子，不可行
// 问题4：改为 const TRandom& rand，不行，因为 NextByte 改变对象状态，不能用于 const
