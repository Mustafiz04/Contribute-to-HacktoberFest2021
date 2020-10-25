#include <stdio.h>
#include <stdlib.h>

//structure of recuried type
struct matrix{
    char ballColour;
    int currentCapacity;
    int MaxCapacity ;
};
int noOfPlayers;
int ROW,COLUMN;
char *playersColour;
struct matrix ** grid;
int *status;
void checking_printMatrix();
void printMatrix();
void init_Grid();
void playerUpdate(char,int,int,int);
void reactionUpdate(char ,int , int);
void getPlayer(int );
void chainReaction(char, int ,int);
int checkWin();
void sleep();

//Driver Function
int main()
{
    init_Grid();
    for(int i=0; i<noOfPlayers; i++)
    getPlayer(i);

    while(1){
        for(int i=0; i<noOfPlayers; i++){
            if(status[i]){
                getPlayer(i);
                if(checkWin())
                    return 0;
            }
        }
    }
    return 0;
}

//function to get dimension of x and y from the player , update and print the Matrix
void getPlayer(int num){
    int tempX,tempY;
    printf("\nPlayer %d (%c):  Enter the box Value : ",num+1,playersColour[num]);
    fflush(stdin);

    // loop run untill it gets 2 values
    while(scanf("%d,%d",&tempX,&tempY) != 2){
        printf("Enter correct value : ");
        getchar();
    }

    playerUpdate(playersColour[num],tempX,tempY,num);
}

//Function to Print the values of matrix
void printMatrix(){
    system("clear");
    printf("\n\t\t\t\tCHAIN REATION GAME \n\n");
    printf("\t\t\t    |");
    for(int i=0; i<COLUMN; printf("%3d |",i++));
    printf("\n");
    for(int i=0; i<ROW; i++,printf("\n")){
        printf("\t\t\t");
        for(int i=0; i<=COLUMN; printf("-----"),i++);

        printf("\n");
        printf("\t\t\t%3d |",i);
        for(int j=0; j<COLUMN; j++){
            if(grid[i][j].currentCapacity ==0)
                printf("    |");
            else
                printf(" %c%d |",grid[i][j].ballColour,grid[i][j].currentCapacity);
        }
    }
    printf("\t\t\t");
    for(int i=0; i<=COLUMN; printf("-----"),i++);
    printf("\n");
}

//update the value
void playerUpdate(char colour, int i , int j, int playerNumber ){
    if(i<ROW && i>=0 && j>=0 && j<COLUMN && (grid[i][j].ballColour == colour || grid[i][j].ballColour == ' ') ){
        if(grid[i][j].currentCapacity+1 <= grid[i][j].MaxCapacity){
            grid[i][j].currentCapacity++;
            grid[i][j].ballColour=colour;
        }
        else{
            grid[i][j].currentCapacity++;
            chainReaction(colour,i,j);
        }
    }
    else{
        getchar();
        printf("\nYOU CANNOT CHOOSE THIS BOX.... TRY AGAIN\n");
        getPlayer(playerNumber);
    }
    printMatrix();
}

//function to perform chain chainReaction
void chainReaction(char colour,int i,int j){
    printMatrix();
    sleep();
    grid[i][j].currentCapacity=0;
    grid[i][j].ballColour = ' ';
    if(i+1 < ROW){
        reactionUpdate(colour,i+1,j);
    }
    if(i-1 >= 0){
        reactionUpdate(colour,i-1,j);
    }
    if(j+1 < COLUMN){
        reactionUpdate(colour,i,j+1);
    }
    if(j-1 >= 0){
        reactionUpdate(colour,i,j-1);
    }
}

//fuction to update matrix
void reactionUpdate(char colour,int i, int j){
    if(grid[i][j].currentCapacity+1 <= grid[i][j].MaxCapacity){
            grid[i][j].currentCapacity++;
            grid[i][j].ballColour=colour;
    }
    else{
        grid[i][j].currentCapacity++;
        chainReaction(colour,i,j);
    }
}

//function to check weather there is a win
int checkWin(){
    for(int k=0; k<noOfPlayers; k++){
        if(status[k]){
            status[k]=0;
            for(int i=0; i<ROW; i++){
                for(int j=0; j<COLUMN; j++){
                    if(grid[i][j].ballColour == playersColour[k]){
                        status[k]= 1;
                        break;
                    }
                }
            if(status[k])
                break;
            }
        if(status[k] != 1)
            printf("\n-------- Opps !!! Player %d (%c) ELEMINATED -----------\n",k+1,playersColour[k]);
        }
    }

    //check weather any one won
    int sum=0;
    for(int i=0; i<noOfPlayers; i++)
        sum += status[i];

    //if any one won then find who
    if(sum==1){
        for(int i=0; i<noOfPlayers; i++){
            if(status[i] == 1){
                printf("\n\n---------- Congragulations!!!!! PLAYER %d WON the match -----------",i+1);
                return 1;
            }
        }
    }
    return 0;
}

//Function to sleep for some time
void sleep(){
    int c, d;
    for (c = 1; c <= 32767; c++)
        for (d = 1; d <= 100; d++)
           {;;;}
}

//Function to initialize the values of the matrix
void init_Grid(){
    system("clear");
    printf("\n---------------------------- CHAIN REATION GAME ----------------------------\n\n");
    //getting the values from the user
    printf("\nEnter No of Rows : ");
    scanf("%d",&ROW);
    printf("Enter No of Columns : ");
    scanf("%d",&COLUMN);

    // loop run untill the no of players is greater than 2;
    do{
        printf("Enter No of Players : ");
        scanf("%d",&noOfPlayers);
    }while(noOfPlayers <=1 ? printf("MINIMUM PLAYERS COUNT IS 2.\n") : 0);


    playersColour = calloc(sizeof(char),noOfPlayers);    //dynamically creating the array to store colors

    //getting the colors form the user
    for(int i=0; i<noOfPlayers; i++){
        printf("Choose a distint letter for player %d : ",i+1);
        fflush(stdin);
        getchar();
        scanf("%c",&playersColour[i]);
    }

    //Dynamically creating the matrix with required size
    grid = (struct matrix **) calloc(sizeof(struct matrix *) , ROW);
    for(int i=0; i<ROW; i++){
        grid[i] = (struct matrix*) calloc (sizeof(struct matrix) , COLUMN);
    }

    //Dynamically creating the status array to check wheather the player is eligible or not
    status = malloc(sizeof(int)*noOfPlayers);
    for(int i=0; i<noOfPlayers; i++)
        status[i]=1;

    //populating the matrix with default values
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COLUMN; j++){
            if(i==0 || j==0 )
                grid[i][j].MaxCapacity=2;
            else if(j==COLUMN-1)
                grid[i][COLUMN-1].MaxCapacity=2;
            else if(i==ROW-1)
                grid[ROW-1][j].MaxCapacity=2;
            else
                grid[i][j].MaxCapacity=3;
            grid[i][j].ballColour=' ';
        }
    }
    grid[0][0].MaxCapacity=1;
    grid[ROW-1][COLUMN-1].MaxCapacity=1;
    grid[0][COLUMN-1].MaxCapacity=1;
    grid[ROW-1][0].MaxCapacity=1;
    printMatrix();
}
