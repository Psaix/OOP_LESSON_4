#include "ArrayInt.h"
#include <iostream>
#include <vector>
#include <algorithm>



class Card {
public:
	enum rank : int {
		HEARTS,
		DIAMONDS,
		SPADES,
		CLUBS
	};
	enum suit : char {
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEEN,
		KING,
		ACE,
	};

private:
	bool m_IsFaceUp;
	rank m_Rank;
	suit m_Suit;

public:

	Card(bool Face, rank Rank, suit Suit) : m_IsFaceUp(Face), m_Rank(Rank), m_Suit(Suit) {}

	bool Flip() {
		if (m_IsFaceUp)
			m_IsFaceUp = false;
		else
			m_IsFaceUp = true;
		return m_IsFaceUp;
	}

	int GetValue() {
		switch (m_Suit) {
		case TWO:
			return 2;
			break;
		case THREE:
			return 3;
			break;
		case FOUR:
			return 4;
			break;
		case FIVE:
			return 5;
			break;
		case SIX:
			return 6;
			break;
		case SEVEN:
			return 7;
			break;
		case EIGHT:
			return 8;
			break;
		case NINE:
			return 9;
			break;
		case TEN:
			return 10;
			break;
		case JACK:
			return 10;
			break;
		case QUEEN:
			return 10;
			break;
		case KING:
			return 10;
			break;
		case ACE:
			return 1;
			break;
		default:
			break;
		}
	}

	~Card() {}
};


//____________________________________________________________________________________________________________
//____________________________________________TASK3___________________________________________________________
//____________________________________________________________________________________________________________


class Hand {
private:
	std::vector <Card*> m_Cards;

public:
	void Add(Card* pCard) {

		m_Cards.push_back(pCard);
	}

	void Clear() {

		std::vector<Card*>::iterator iter;
		for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
		{
			delete* iter;
			*iter = 0;
		}
		m_Cards.clear();
	}

	int GetValue() const {

		if (m_Cards.empty())
		{
			return 0;
		}

		if (m_Cards[0]->GetValue() == 0)
		{
			return 0;
		}

		int total = 0;
		std::vector<Card*>::const_iterator iter;
		for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
		{
			total += (*iter)->GetValue();
		}

		bool contains_Ace = false;
		for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
		{
			if ((*iter)->GetValue() == Card::ACE)
			{
				contains_Ace = true;
			}
		}

		if (contains_Ace && total <= 11)
		{
			total += 10;
		}
		return total;

	}

};


int main()
{

//____________________________________________________________________________________________________________
//____________________________________________TASK2___________________________________________________________
//____________________________________________________________________________________________________________


	
	std::vector<int> varray = { 1, 2, 3, 3, 4, 5, 7 };

	std::sort(varray.begin(), varray.end());

	int uniqNum = 0;

	if (varray.size() == 1)
		uniqNum = 1;
	else 
	{
		uniqNum = 1;
		for (std::vector<int>::iterator it = varray.begin(); it < varray.end() - 1; ++it) {
			if ((*it) != *(it + 1)) uniqNum++;
		}
	}
	std::cout << uniqNum << std::endl;


	return 0;
}
