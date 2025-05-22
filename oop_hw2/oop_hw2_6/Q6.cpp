#include <iostream>
using namespace std; 

class Monster {
private:
    int speed, hitpoint, damage, defense;
public:
    Monster(int s, int h, int d, int def) : speed(s), hitpoint(h), damage(d), defense(def) {}

    bool operator>(const Monster& other) const {
        if (speed != other.speed) return speed > other.speed;
        if (hitpoint != other.hitpoint) return hitpoint > other.hitpoint;
        if (damage != other.damage) return damage > other.damage;
        return defense > other.defense;
    }

    void Attack(Monster& other) const {
        int harm = std::max(2 * damage - other.defense, 1);
        other.hitpoint -= harm;
        std::cout << "Monster attacks for " << harm << " damage. Opponent HP: " << other.hitpoint << std::endl;
    }

    void Fight(Monster& other) {
        Monster* first = this;
        Monster* second = &other;
        if (!(*this > other)) std::swap(first, second);

        while (first->hitpoint > 0 && second->hitpoint > 0) {
            first->Attack(*second);
            if (second->hitpoint <= 0) break;
            second->Attack(*first);
        }
    }
};

void Test() {
    Monster m1(10, 30, 5, 2);
    Monster m2(8, 35, 4, 3);
    m1.Fight(m2);
}

int main(){
	Test();
	return 0;
}

