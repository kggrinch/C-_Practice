#ifndef CARD_H_
#define CARD_H_
#include <iostream>


enum Suit {kHeart, kDiamond, kClub, kSpade}; // kHeart = 0, kDiamond=1, kClub=2, kSpade=3
const std::string kSUITS[4] = {"hearts", "diamond", "clubs", "spade"};

class Card
{
  private:
    int value_;
    Suit suit_;

  public:

    // Constructors
    Card();

    Card(int values, Suit suit);

    // Getter
    // std::string get_card_info_();

    int value() const;

    Suit suit() const;

    friend std::ostream& operator<<(std::ostream& stream, const Card& card); // friend of a class can access members of the class.

};

#endif