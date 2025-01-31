#include <ctime>
#include <iostream>
char getCchoice();
char getUchoice();
void showchoice(char userChoice, char computerChoice);
void showWInner(char userChoice, char computerChoice);
int main()
{
    char replay;
    srand(time(NULL));

    do
    {

        char userChoice = getUchoice();
        char ComputerChoice = getCchoice();
        std::cout << "LET THE GAME BEGIN: ";
        showchoice(userChoice, ComputerChoice);
        showWInner(userChoice, ComputerChoice);
        std::cout << "\nWANNA PLAY AGAIN? PRESS Q TO CONTINUE OR ANY OTHER KEY TO EXIT: ";
        std::cin >> replay;
        replay = toupper(replay);

    } while (replay == 'Q');
    std::cout << "\n THANKS FOR PLAYING!";
    return 0;
}
char getCchoice()
{
    int num = (rand() % 3 + 1);
    switch (num)
    {
    case 1:
        return 'R';
        break;
    case 2:
        return 'P';
        break;
    case 3:
        return 'S';
        break;

    default:
        break;
    }
}
char getUchoice()
{
    char user;
    std::cout << "CHOOSE R P OR S";
    std::cin >> user;
    user = toupper(user);
    do
    {
        std::cout << "PLEASE ENTER A VALID CHOICE BETWEEN P R AND S";
        std::cin >> user;
    } while (user != 'R' && user != 'S' && user != 'P');

    return user;
}
void showchoice(char userChoice, char computerChoice)
{
    std::cout << "the user choice was :  " << userChoice << "  \n the computer choice was:  " << computerChoice << '\n';
}
void showWInner(char userChoice, char computerChoice)
{
    static int Uwins = 0;
    static int Cwins = 0;
    static int tTimes = 0;
    if (userChoice == computerChoice)
    {
        std::cout << "ITS A TIE \n";
        tTimes += 1;
    }
    else if (userChoice == 'R' && computerChoice == 'P')
    {
        std::cout << "COMPUTER WINS! \n";
        Cwins += 1;
    }
    else if (userChoice == 'P' && computerChoice == 'R')
    {
        std::cout << "USER WINS! \n";
        Uwins += 1;
    }
    else if (userChoice == 'S' && computerChoice == 'P')
    {
        std::cout << "USER WINS! \n";
        Uwins += 1;
    }
    else if (userChoice == 'P' && computerChoice == 'S')
    {
        std::cout << "COMPUTER WINS! \n";
        Cwins += 1;
    }
    else if (userChoice == 'R' && computerChoice == 'S')
    {
        std::cout << "USER WINS! \n";
        Uwins += 1;
    }
    else if (userChoice == 'S' && computerChoice == 'R')
    {
        std::cout << "COMPUTER WINS! \n";
        Cwins += 1;
    }
    std::cout << "THERE HAS BEEN  " << tTimes << " TIES and " << Uwins << " USER WINS  AND " << Cwins << " Computer wins! \n";
}
