#include <random>
enum class Rank {
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    ACE,
    JACK,
    QUEEN,
    KING
};

enum class Suit {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

class Card {
private:
    Rank rank;
    Suit suit;
    bool isFlipped;
public:
    explicit Card(bool isFlipped) : isFlipped(isFlipped) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> rankDist(static_cast<int>(Rank::TWO), static_cast<int>(Rank::KING));
        std::uniform_int_distribution<int> suitDist(static_cast<int>(Suit::CLUBS), static_cast<int>(Suit::SPADES));
        rank = static_cast<Rank>(rankDist(gen));
        suit = static_cast<Suit>(suitDist(gen));
    }
    Card& operator=(const Card& other) {
        if (this == &other)
            return *this;
        rank = other.rank;
        suit = other.suit;
        isFlipped = other.isFlipped;
        return *this;
    }
    ~Card() = default;
    int GetValue() const;
    char GetColour() const;
    bool IsFlipped() const;
};

