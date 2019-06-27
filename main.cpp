//This is a C++ program game for Rock Paper Scissors

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef enum{rock, paper, scissors} choice;

typedef enum{cwin, tie, pwin} result;

string name(choice c)
{
    if(c == rock) return("rock");
    else if(c == paper) return("paper");
    else return("scissors");
}


result gameEval(choice player, choice computer)
{
    string t1, t2;
    t1 = name(player);
    t2 = name(computer);
    cout << "Player: " << t1 << "\tComputer:" << t2 << endl;

    if((player == rock && computer == paper)||
       (player == scissors && computer == rock)||
       (player == paper && computer == scissors))
        return cwin;
    else if((player == paper && computer == rock)||
            (player == rock && computer == scissors)||
            (player == scissors && computer == paper))
            return pwin;
    else
        return tie;
}

choice compChoice()
{
    int c = rand()%3;
    if(c == 0) return rock;
    else if(c == 1) return paper;
    else return scissors;
}

choice playerChoice()
{
    char p = 'x';

    while(p == 'x')
    {
        cout << "Enter Choice: r = Rock, p = paper, and s = scissors: ";
        cin >> p;
        switch(p)
        {
            case '0': case 'R': case 'r':
                    return rock;
            case '1': case 'P': case 'p':
                    return paper;
            case '2': case 'S': case 's':
                    return scissors;
            default:
                    p = 'x';
        }
    }
}

int main()
{
    srand(time(NULL));
    result r;
    int cCount = 0, pCount = 0;
    for(int i = 0; i < 10; i++)
    {
        r = gameEval(playerChoice(), compChoice());
        if(r == cwin) cCount++;
        else if(r == pwin) pCount++;
    }
    cout << "\nPlayer won " << pCount << " times." << endl;
    cout << "Computer won " << cCount << " times." << endl;

    if(pCount == cCount){
        cout << "\nThere is a tie. Nobody wins." << endl;
    } else if(pCount > cCount){
        cout << "\nPlayer Wins!!!" << endl;
    } else if(pCount < cCount){
        cout << "\nComputer Wins!!! Try harder next time." << endl;
    }
}
