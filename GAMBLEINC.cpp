#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

int dealCard(int& numA, int& num2, int& num3, int& num4, int& num5, int& num6, int& num7, int& num8, int& num9, int& num10, int& numJ, int& numQ, int& numK, int& sizeDeck) {
    int a = rand() % 13 + 1; //assigning random values to players from 1-13 (Ace to King)
    if (a == 13) {
        numK -= 1;
    }
    else if (a == 12) {
        numQ -= 1;
    }
    else if (a == 11) {
        numJ -= 1;
    }
    else if (a == 10) {
        num10 -= 1;
    }
    else if (a == 9) {
        num9 -= 1;
    }
    else if (a == 8) {
        num8 -= 1;
    }
    else if (a == 7) {
        num7 -= 1;
    }
    else if (a == 6) {
        num6 -= 1;
    }
    else if (a == 5) {
        num5 -= 1;
    }
    else if (a == 4) {
        num4 -= 1;
    }
    else if (a == 3) {
        num3 -= 1;
    }
    else if (a == 2) {
        num2 -= 1;
    }
    else if (a == 1) {
        numA -= 1;
    }
    sizeDeck = numA + num2 + num3 + num4 + num5 + num6 + num7 + num8 + num9 + num10 + numJ + numQ + numK;
    return a;
}

void determinePlayerHand(vector<int>& playerCards, vector<int>& playerActualCards) {
    cout << " --------------------------" << endl;
    cout << "Your current hand is: ";
    for (int i = playerCards.size(); i > 0 ; i--)
        if (playerCards[i] == 1) {
            int aceValue;
            cout << "You have drawn an Ace.\nPlease choose the value to be 1 or 11: ";
            cin >> aceValue;
            while (aceValue != 1 && aceValue != 11) {
                cout << "Invalid input. Please enter 1 or 11: " << endl;
                cin >> aceValue;
            }
            cout << "A ";
            playerActualCards.push_back(aceValue);
        }
        else if (playerCards[i] >= 2 && playerCards[i] <= 10) {
            cout << playerCards[i] << " ";
            playerActualCards.push_back(playerCards[i]);
        }
        else if (playerCards[i] == 11) {
            cout << "J ";
            playerActualCards.push_back(10);
        }
        else if (playerCards[i] == 12) {
            cout << "Q ";
            playerActualCards.push_back(10);
        }
        else {
            cout << "K ";
            playerActualCards.push_back(10);
        }
    cout << endl << " --------------------------" << endl;
}

void determineDealerHand(vector<int>& dealerCards, vector<int>& dealerActualCards) {
    cout << " --------------------------" << endl;
    cout << "The Dealer's current hand is: ";
    for (int i = 0; i < dealerCards.size(); i++)
        if (dealerCards[i] == 1) {
            cout << "A ";
            dealerActualCards.push_back(1);
        }
        else if (dealerCards[i] >= 2 && dealerCards[i] <= 10) {
            cout << dealerCards[i] << " ";
            dealerActualCards.push_back(dealerCards[i]);
        }
        else if (dealerCards[i] == 11) {
            cout << "J ";
            dealerActualCards.push_back(10);
        }
        else if (dealerCards[i] == 12) {
            cout << "Q ";
            dealerActualCards.push_back(10);
        }
        else {
            cout << "K ";
            dealerActualCards.push_back(10);
        }
    cout << endl << " --------------------------" << endl;
}

int determinePlayerHandWorth(vector<int>& playerActualCards) {
    int playerHandSize = 0;
    for (int i = 0; i < playerActualCards.size(); i++) {
        playerHandSize += playerActualCards[i];
    }
    cout << "**********************" << endl;
    cout << "Your current Size is: ";
    cout << playerHandSize;
    cout << endl << "**********************" << endl;
    playerActualCards.clear();
    return playerHandSize;
}

int determineDealerHandWorth(vector<int>& dealerActualCards) {
    int dealerHandSize = 0;
    for (int i = 0; i < dealerActualCards.size(); i++) {
        dealerHandSize += dealerActualCards[i];
    }
    cout << "**********************" << endl;
    cout << "Dealer's current Size is: ";
    cout << dealerHandSize;
    cout << endl << "**********************" << endl;
    dealerActualCards.clear();
    return dealerHandSize;
}

double pNotBust(int handValue, int sizeDeck, int numA, int num2, int num3, int num4, int num5, int num6, int num7, int num8, int num9, int num10, int numJ, int numQ, int numK) {
    int maxNum = 21 - handValue;
    double goodCards = 0.0;
    if (maxNum >= 10) {
        goodCards = numA + num2 + num3 + num4 + num5 + num6 + num7 + num8 + num9 + num10 + numJ + numQ + numK;
    }
    if (maxNum == 9) {
        goodCards = numA + num2 + num3 + num4 + num5 + num6 + num7 + num8 + num9;
    }
    if (maxNum == 8) {
        goodCards = numA + num2 + num3 + num4 + num5 + num6 + num7 + num8;
    }
    if (maxNum == 7) {
        goodCards = numA + num2 + num3 + num4 + num5 + num6 + num7;
    }
    if (maxNum == 6) {
        goodCards = numA + num2 + num3 + num4 + num5 + num6;
    }
    if (maxNum == 5) {
        goodCards = numA + num2 + num3 + num4 + num5;
    }
    if (maxNum == 4) {
        goodCards = numA + num2 + num3 + num4;
    }
    if (maxNum == 3) {
        goodCards = numA + num2 + num3;
    }
    if (maxNum == 2) {
        goodCards = numA + num2;
    }
    if (maxNum == 1) {
        goodCards = numA;
    }
    return (goodCards / sizeDeck) * 100;
}
int deterDealerMove(int dealerCardWorth) {
    if (dealerCardWorth <= 16) { // if dealers hand is less than 16 the dealer will hit
        return 1;
    }
    else { // otherwise the dealer will stand.
        return 0;
    }
}
int main() {
    vector<int> playerCards;
    vector<int> playerActualCards;
    int playerCardWorth;
    string playerChoice;

    vector<int> dealerCards;
    vector<int> dealerActualCards;
    int dealerCardWorth;
    int dealerChoice;

    srand(time(0));
    int sizeDeck;

    int numA = 4;
    int num2 = 4;
    int num3 = 4;
    int num4 = 4;
    int num5 = 4;
    int num6 = 4;
    int num7 = 4;
    int num8 = 4;
    int num9 = 4;
    int num10 = 4;
    int numJ = 4;
    int numQ = 4;
    int numK = 4;

    playerCards.push_back(dealCard(numA, num2, num3, num4, num5, num6, num7, num8, num9, num10, numJ, numQ, numK, sizeDeck));
    playerCards.push_back(dealCard(numA, num2, num3, num4, num5, num6, num7, num8, num9, num10, numJ, numQ, numK, sizeDeck));
    dealerCards.push_back(dealCard(numA, num2, num3, num4, num5, num6, num7, num8, num9, num10, numJ, numQ, numK, sizeDeck));
    dealerCards.push_back(dealCard(numA, num2, num3, num4, num5, num6, num7, num8, num9, num10, numJ, numQ, numK, sizeDeck));

    determinePlayerHand(playerCards, playerActualCards);
    determineDealerHand(dealerCards, dealerActualCards);

    playerCardWorth = determinePlayerHandWorth(playerActualCards);
    dealerCardWorth = determineDealerHandWorth(dealerActualCards);

    cout<< "Probability For Player To Not Bust On Next Hit: " << pNotBust(playerCardWorth, sizeDeck, numA, num2, num3, num4, num5, num6, num7, num8, num9, num10, numJ, numQ, numK) << "%"<< endl;
  cout<< "Probability For Dealer To Not Bust On Next Hit: " << pNotBust(dealerCardWorth, sizeDeck, numA, num2, num3, num4, num5, num6, num7, num8, num9, num10, numJ, numQ, numK) << "%"<< endl;
    if (playerCardWorth == 21) {
        cout << "You win!" << endl;
        return 0;
    }
    cout << "\nHit or Stand, please enter y/n: " << endl;
    cin >> playerChoice;
    while (playerChoice == "y") {
        playerCards.push_back(dealCard(numA, num2, num3, num4, num5, num6, num7, num8, num9, num10, numJ, numQ, numK, sizeDeck));
        determinePlayerHand(playerCards, playerActualCards);
        playerCardWorth = determinePlayerHandWorth(playerActualCards);

        if (playerCardWorth == 21) {
            cout << "You win!" << endl;
            return 0;
        }
        else if (playerCardWorth > 21) {
            cout << "You Bust! Dealer Wins!" << endl;
            return 0;
        }
          cout<< "Probability For Player To Not Bust On Next Hit: " << pNotBust(playerCardWorth, sizeDeck, numA, num2, num3, num4, num5, num6, num7, num8, num9, num10, numJ, numQ, numK) << "%"<< endl;
      cout<< "Probability For Dealer To Not Bust On Next Hit: " << pNotBust(dealerCardWorth, sizeDeck, numA, num2, num3, num4, num5, num6, num7, num8, num9, num10, numJ, numQ, numK) << "%"<< endl;
        cout << "\nPlayer: Do You want to Hit or Stand? Please enter y/n: " << endl;
        cin >> playerChoice;
    }
    dealerChoice = deterDealerMove(dealerCardWorth);
    while (dealerChoice == 1)
    {
       dealerCards.push_back(dealCard(numA, num2, num3, num4, num5, num6, num7, num8, num9, num10, numJ, numQ, numK, sizeDeck));               
       determineDealerHand(dealerCards, dealerActualCards);
       dealerCardWorth = determineDealerHandWorth(dealerActualCards);
       dealerChoice = deterDealerMove(dealerCardWorth);
    }
  if (dealerCardWorth >= 22) {
    cout << "Dealer Busts, Player Wins!" << endl;
  }
  else if (playerCardWorth > dealerCardWorth && dealerCardWorth <=21 ){
      cout << "Player Wins" << endl;
  } else if (playerCardWorth == dealerCardWorth && dealerCardWorth <=21){
    cout << "It's a tie :(";
  }
  else {
    cout << "Dealer Wins" << endl;
  }
    return 0;
}
