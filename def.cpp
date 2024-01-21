#include <iostream>

//to include the user files
#include "dec.h"

using namespace std;
//global variables
string board[9]={" "," "," "," "," "," "," "," "," "};
int player=1;
int position=0;

void introduction()
{
    cout << "Press [Enter]key to begin the game";
    getchar();//used to get char from the useror in this case enter key, This haults the screen until ip recieved.
    cout << "\n";
    
    //To print the board
    cout << "\n";
    cout << "TIC-TAC-TOE" << endl;
    cout << "Player 1  chooses X" << endl;
    cout << "Player 2  chooses O" << endl;

    cout<<"The 3x3 Playground is set:\n\n";
  
    cout << "     |     |      \n";
    cout << "  1  |  2  |  3   \n";
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
    cout << "  4  |  5  |  6   \n";
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
    cout << "  7  |  8  |  9   \n";
    cout << "     |     |      \n\n";
}


bool is_winner(){
    bool winner= false;

    //checking rows
    if((board[0]==board[1]) && (board[1]==board[2]) && board[0]!= " "){
        winner=true;
    }
    else if((board[3]==board[4]) && (board[4]==board[5]) && board[3]!= " "){
        winner=true;
    }
    else if((board[6]==board[7]) && (board[7]==board[8]) && board[6]!= " "){
        winner = true;
    }
    
    //checking columns 
    else if((board[0]==board[3]) && (board[3]==board[6]) && board[0]!=" "){
        winner =true;
    }
    else if((board[1]==board[4]) && (board[4]==board[7]) && board[1]!= " "){
        winner=true;
    }
    else if((board[2]==board[5]) && (board[5]==board[8]) && board[2]!=" "){
        winner=true;
    }

    //checking diagonal
    else if((board[0]==board[4]) && (board[4]==board[8]) && board[0]!=" "){
        winner=true;
    }
    else if((board[2]==board[4]) && (board[4]==board[6]) && board[2]!=" "){
        winner=true;
    }

    return winner;
}

bool filled_up()
{
    bool filled=true;

    for(int i=0;i<9;i++){
        if(board[i]== " ")
        {
            filled=false;
        }
    }
    return filled;
}


void draw(){
  cout<<  "     |     |      \n";
  cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
  cout << "_____|_____|_____ \n";
  cout << "     |     |      \n";
  cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
  cout << "_____|_____|_____ \n";
  cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
  cout << "     |     |      \n";
  cout << "\n";
}

void set_position(){
    cout<<"Player "<<player<<"'s turn (Enter: 1-9)";   //1-9 (Enter: (1-9))
    while(!(cin>>position)){
        cout << "Please enter a valid number between 1 - 9" << endl;
        cin.clear();
        cin.ignore();
    }

    while(board[position-1]!=" ")
    {
        cout << "Positon marked already.Choose a different position.";
        cout<<"Player "<<player<<"'s turn (Enter: 1-9)";   //1-9 (Enter: (1-9))
        cin>>position;
        cout<<"\n";
    }
}

void update_board()
{
  
  if (player % 2 == 1){
    board[position - 1] = "X";   //1-9        0-8
  }
  else
  {
    board[position - 1] = "O";
  }
}

void change_player()
{
    if(player==1)
    {
        player++;
    }
    else{
        player--;
    }
}

void take_turn(){
    while(!is_winner() && !filled_up()){
        set_position();
        update_board();
        change_player();
        draw();
    }
}

void end_game()
{
	if(is_winner())
	{
		cout<<"Congragulations! You WIN player "<< player << endl;
		
	}
	
	else if(filled_up())
	{
		cout<<"Its a tie!"<<endl;
	}
}
