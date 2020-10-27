/********************************************************
*
*
*               Author : Surendiran s
*
*
*         Github : https://github.com/SurendiranS
*
*
*********************************************************/


#include <bits/stdc++.h>
#include <chrono>
using namespace std;


void gameOver();
int round();
void sleep(int);
int score;
int level;


int main(){
  system("clear");
  srand(time(0));
  cout<< "\n\n\n\t\t\tWelcome to MASTER MING GAME\n\n\n";
  cout<< "TRY TO REMEMBER THE RANDOM NUMBERS SHOWN AND ENTER WHEN ASKED\n\n\n";
  while(1){
    ++level;
    if(round()){      
      continue;
    }
    break;
  }
}


int round(){
  system("clear");
  cout<< "\n\n\n\t\t\tMASTER MING GAME\n\n\n";
  cout<< "\t[LEVEL] = " << level << "\t\t\t\t\t\t[SCORE] = "<<score;
  cout<<"\n\n\n";
  cout<<"Try to remember the following " << level*3 << " numbers :\n\n";
  std::vector<int> arr(level*3);
  for(int i=0; i<level*3; ++i){
    arr[i] = rand()%100+1;
    cout<< arr[i] << '\n';
    sleep(1200);
  }
  cout<<'\n';
  // system("clear");
  cout<< "\n\n\n\t\t\tMASTER MING GAME\n\n\n";
  cout<<"Enter all the "<< level*3 << " numbers one by one : \n";
  for(int i=0,temp; i<level*3; ++i){
    cin>> temp;
    if(temp == arr[i]){
      cout<< "\t\t Good!\n";
      score += level;
    }
    else{
      cout<< "\t\t Oops it's wrong\n";
      gameOver();
      return 0;
    }
  }
  return 1;
}


void sleep(int number_of_seconds ){
 int milli_seconds = 1000 * number_of_seconds;
    // Storing start time 
    clock_t start_time = clock(); 
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds); 
}


void gameOver(){
  system("clear");
  cout<< "\n\n\n\t\t\t   MASTER MING GAME\n";
  cout<< "\n\n\t\t\t      GAME OVER\n\n";
  cout<< "\t\t\t   Your Score = " <<score<<"\n\n ";
}
