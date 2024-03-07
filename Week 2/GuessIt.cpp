#include <bits/stdc++.h>

using namespace std;

/// func protoypes
int getPlayerInput();
int machineGuess(int input);
void printAns(int answer, int guessCount);
void playGuessIt();

/// global var
int guessCount=1;

int main(int argc, string argv[])
{
    char isContinued;
    do {
        playGuessIt();
        cout << "\n Play again? (y/n): ";
        cin >> isContinued;
    } while(isContinued == 'y' || isContinued == 'Y');
    return 0;
}

int getPlayerInput()
{
    int n;
    do {
    cout << "Enter an integer between 1 and 100: ";
    cin >> n;
    if ((n>100) || (n<1)) cout << "INVALID NUMBER \n";
    } while ((n>100) || (n<1));
    return n;
}

int machineGuess(int input)
{
    int num=50, low=1, high =100;

    do {
        if (num<input)
        {
            low=num+1;
            num = (high+low)/2;
            guessCount++;
        }
        else if (num>input)
        {
            high= num-1;
            num = (high+low)/2;
            guessCount++;
        }
    } while (num!=input);
    return num;
}

void printAns(int answer, int guessCount)
{
    cout << "Your input number is: " << answer << "\n";
    cout << "It took me: " << guessCount << " guesses \n";
}

void playGuessIt()
{
    int answer = getPlayerInput();
    int machine = machineGuess(answer);
    printAns(machine, guessCount);
}
