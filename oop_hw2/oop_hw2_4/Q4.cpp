#include <vector>
#include <iostream> 

class Hero {
private:
    int charm, fame, attack, defense, magic;
    int items[5] = {0};
public:
    Hero() : charm(0), fame(0), attack(0), defense(0), magic(0) {}

    void Equip(int pos, int item) {
        if (pos >= 0 && pos < 5) items[pos] = item;
        ApplyItem(item);
    }

    void Remove(int pos) {
        if (pos >= 0 && pos < 5) items[pos] = 0;
    }

    void ApplyItem(int item) {
        switch(item) {
            case 1: charm += 2; break;
            case 2: fame += 3; break;
            case 3: attack += 1; break;
            case 4: defense += 2; break;
            case 5: magic += 4; break;
            case 6: charm += 1; magic += 1; break;
        }
    }

    void ShowStats() const {
        std::cout << "Charm: " << charm << ", Fame: " << fame
                  << ", Attack: " << attack << ", Defense: " << defense
                  << ", Magic: " << magic << std::endl;
    }
};

void Test() {
    Hero h;
    h.Equip(0, 1);
    h.Equip(1, 3);
    h.Equip(2, 5);
    h.ShowStats();
    h.Remove(1);
    h.ShowStats();
}

int main(){
	Test();
	return 0;
}
