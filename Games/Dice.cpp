/*********************************************
 * 
 * 
 *          AUTHOR : SURENDIRAN S 
 * 
 *       https://github.com/SurendiranS
 * 
 * 
 * *******************************************/


#include <bits/stdc++.h>
#include <unistd.h>
#include <termios.h>
using namespace std;

vector<int> score1;
vector<int> score2;
int chances;
int cur_chance;
string player1 = "a";
string player2 = "b";


//function to clear the input stream
void clean_stdin(void)
{
    int stdin_copy = dup(STDIN_FILENO);
        /* remove garbage from stdin */
        tcdrain(stdin_copy);
        tcflush(stdin_copy, TCIFLUSH);
        close(stdin_copy);
}


// function to generate random number from 1 to 6
int dice(){
    int n = rand();
    return n%6 + 1; 
}


//gets input from user during every chance
void chance(int player){
    vector<int> score;
    int temp;
    system("clear");
    cout<< "\t\t\t CHANCE : "<< cur_chance<<"\n";
    clean_stdin();
    cout<< "\n\n\n"<<(player == 1 ? player1 : player2) <<" Press ENTER key : ";
    while(1){
        getchar();
        temp = dice();
        score.push_back(temp);
        if(temp != 6 and temp != 1){
            cout<<"\nIt's "<<temp<<'\n';
            sleep(2);
            clean_stdin();
            break;
        }
        cout<<"\nWell done it's "<<temp<<" You got another move : ";
        clean_stdin();
    }
    if(player == 1){
        for(auto i : score)
            score1.push_back(i);
    }
    else{
        for(auto i : score)
            score2.push_back(i);
    }
}


//function to print the winner
void gameOver(){
    system("clear");
    int pla1 = accumulate(score1.begin(), score1.end(),0);
    int pla2 = accumulate(score2.begin(), score2.end(),0);
    cout<< "\n\n\n\t\t" << "WINNER WINNER CHICKEN DINNER !!!\n\n\n";
    cout<< "\t\t\t";
    if(pla1 > pla2)
        cout<< player1 << " WON!!!!";
    else if(pla1 < pla2)
        cout<< player2 << " WON!!!!";
    else
        cout<<"OOPSSS !!! It's DRAW";
    cout<< "\n\n\n";
    cout<< player1 <<" got : ";
    for(auto i : score1)
        cout<< i <<" + ";
    cout<<"  =  "<<pla1;
    cout<< "\n\n"<<player2<< " got : ";
    for(auto i : score2)
        cout<< i << " + ";
    cout<<"  =  "<<pla2;
}


int main(){
    srand(time(0));
    cout<<"\n\n\n\t\t\tWELCOME TO DICE GAME\n";
    cout<<"\nEnter Player 1 name : ";
    cin>> player1;
    getchar();
    cout<<"\nEnter Player 2 name : ";
    cin>> player2;
    getchar();
    cout<<"\nEnter No of Chances for each player : ";
    cin>> chances;
    getchar();
    clean_stdin();
    while(chances--){
        cur_chance++;
        chance(1);
        chance(2);
    }
    gameOver();
}
