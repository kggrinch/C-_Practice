#include "Card.h"
#include <iostream>

Card::Card() : value_(1), suit_()
{

}

Card::Card(int value, Suit suit) : value_(value), suit_(suit)
{
  if(value < 1 || value > 13)
  {
    value_ = 1;
  }
}

// std::string Card::get_card_info_()
// {
//   return value_.to_string() + " " + suit_.to_string();

// }

int Card::value() const
{
  return value_;
}

Suit Card::suit() const
{
  return suit_;
}

std::ostream& operator<<(std::ostream& stream, const Card& card)
{
  std::string card_value, card_suit;
  card_suit = kSUITS[card.suit()];

  switch(card.value())
  {
    case 1:
      card_value = "ace";
      break;
    case 11:
      card_value = "jack";
      break;
    case 12:
      card_value = "queen";
      break;
    case 13:
      card_value = "king";
      break;
    default:
      card_value = std::to_string(card.value());
  }

  stream << card_value << " of " << card_suit;
  return stream;

}
