#include <iostream> 
#include <string>
#include <utility>

enum Suit { Spade, Heart, Diamond, Club };
enum Rank { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

class Card {
private:
    int id;
    Suit suit;
    Rank rank;
    int backId;
    int width, height;
    std::pair<int, int> topLeft;
public:
    Card(int _id, Suit _suit, Rank _rank, int _backId, int _w, int _h, std::pair<int, int> _tl)
        : id(_id), suit(_suit), rank(_rank), backId(_backId), width(_w), height(_h), topLeft(_tl) {}

    Card(const Card& other) : id(other.id), suit(other.suit), rank(other.rank), backId(other.backId),
        width(other.width), height(other.height), topLeft(other.topLeft) {}

    int GetBackId() const { return backId; }
    void SetBackId(int id) { backId = id; }
    bool IsSameSuit(const Card& other) const { return suit == other.suit; }
    bool IsSameRank(const Card& other) const { return rank == other.rank; }
    bool IsSuit(Suit s) const { return suit == s; }
    bool IsRank(Rank r) const { return rank == r; }
    void SetPosition(int x, int y) { topLeft = {x, y}; }
    std::pair<int, int> GetBottomRight() const { return {topLeft.first + width, topLeft.second + height}; }
};

void Test() {
    Card c1(0, Spade, Ace, 1, 100, 150, {0, 0});
    Card c2(1, Spade, King, 2, 100, 150, {100, 0});
    std::cout << "Same Suit: " << c1.IsSameSuit(c2) << std::endl;
    std::cout << "Bottom Right: (" << c1.GetBottomRight().first << ", " << c1.GetBottomRight().second << ")\n";
}

int main(){
	Test(); 
	return 0;
}
