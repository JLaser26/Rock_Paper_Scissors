#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

string input(){
    string inp;
    cout << "Choose {ROCK, PAPER, SCISSORS}: ";
    cin >> inp;
    if (inp == "ROCK" || inp == "PAPER" || inp == "SCISSORS")
    {
        return inp;
    }
    else{
        cout << "\nINVALID INPUT\n";
        inp = "X";
        return inp;
    }
    
}

string random_pick(){
    string rp;
    string arr[3] = {"ROCK", "PAPER", "SCISSORS"};
    int size = sizeof(arr) / sizeof(arr[0]);
    srand(time(nullptr));
    int random_index = rand() % size;
    return arr[random_index];
}

int main()
{
    bool want_play = true;
    do
    {
        char wp;
        cout << "\n--------------------------------------------\n";
        cout << "Do you want to Play (y/n):- ";
        cin >> wp;
        if (wp == 'y' || wp == 'Y')
        {
            string user_input = input();
            string computer_input = random_pick();

            if (user_input == computer_input){
                cout << "Computer picked: " << computer_input;
                cout << "\nDRAW\n";
                continue;
            }
            else if (user_input == "ROCK" && computer_input == "SCISSORS")
            {
                cout << "Computer picked: " << computer_input;
                cout << "\nYOU WIN!\n";
            }
            else if (user_input == "PAPER" && computer_input == "ROCK")
            {
                cout << "Computer picked: " << computer_input;
                cout << "\nYOU WIN!\n";
            }
            else if (user_input == "SCISSORS" && computer_input == "PAPER")
            {
                cout << "Computer picked: " << computer_input;
                cout << "\nYOU WIN!\n";
            }
            else if (user_input == "X")
            {
                continue;
            }
            
            else{
                cout << "Computer picked: " << computer_input;
                cout << "\nComputer WON\n";
            }
            
        }
        else if (wp == 'n' || wp == 'N')
        {
            want_play = false;
        }
        else{
            cout << "\nInvalid Input\n";
            continue;
        }
        
        
    } while (want_play);
    
    // Pause before exit
    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover input
    cin.get(); // wait for Enter
    return 0;
}
