// This program implements the game of Tic-Tac-Toe where you can play against the computer.
#include <iostream>
using namespace std;

const int SIZE =3;

void display_table (char board[SIZE][SIZE]) ;
void clear_table (char board[SIZE][SIZE]) ;
bool check_table_full (char board[SIZE][SIZE]) ; 
bool check_legal_option(char board[SIZE][SIZE], int row, int col) ;
void generate_player2_move (char board[SIZE][SIZE]) ;
int check_three_in_a_row (char board[SIZE][SIZE]) ;
bool check_end_of_game (char board[SIZE][SIZE]) ;
void get_player1_move (char board[SIZE][SIZE]) ;
void print_winner (char board[SIZE][SIZE]) ;

int main(){
    //Declare the tic-tac-toe board
 char board[SIZE][SIZE];
 //The row and column of the move for either player 1 or 2
 int row, col;
 //Clear the table
 clear_table(board);
 //Display the table
 display_table(board);
 do
 {
 //Have player 1 enter their move
 get_player1_move(board);
 //Generate player 2 move
 generate_player2_move(board);
 //Do this while the game hasn't ended
 }while(!check_end_of_game(board));
 //After the game is over, print who won
 
 print_winner(board);
 return 0;
}

void display_table (char board[SIZE][SIZE]) 
{
cout << "The current state of the game is: " << endl;
for ( int i=0; i < SIZE ; i++){
    for (int j=0 ; j < SIZE ; j++ ){
        cout <<  board [i][j] << ' ';
        }
        cout << '\n';}
}

void clear_table (char board[SIZE][SIZE]) 
{
    for ( int i=0; i < SIZE ; i++){
    for (int j=0 ; j < SIZE ; j++ ){
        board [i][j]= '_' ;
        }}
}
bool check_table_full (char board[SIZE][SIZE])  
{
    for ( int i=0; i < SIZE ; i++){
    for (int j=0 ; j < SIZE ; j++){
        if (board [i][j]== '_'){
            return false;}
            else{
                return true;
            }
    }
    }
    return 0; 
}

bool check_legal_option(char board[SIZE][SIZE], int row, int col)
{ 
    
    if (row <= SIZE && col <= SIZE){
    for ( int i=0; i < SIZE ; i++){
    for (int j=0 ; j < SIZE ; j++){
        if (board[SIZE][SIZE] == ' ') {
            return true;}
            else
            return false;
    } 
    }
    }
    
    return 0;
    }
void generate_player2_move(char board[SIZE][SIZE]){
    if (!check_end_of_game(board)){
        int row; int col;
    do{
        row = rand() % 3;
        col = rand() % 3;
        }
    while (board[row][col] =='X' || board[row][col] == 'O');
    board[row][col]= 'X' ;
    cout << "Player 2 has entered [row, col]: " << row + 1 <<" , " << col + 1 << endl;
    display_table(board);
    }
    } 

int check_three_in_a_row (char board[SIZE][SIZE]){
    if(
        board[0][0] == 'O' && board[0][1]== 'O' && board[0][2]== 'O' || board[1][0] == 'O' && board[1][1]== 'O' && board[1][2]== 'O' ||
        board[2][0] == 'O' && board[2][1]== 'O' && board[2][2]== 'O' || board[0][0] == 'O' && board[1][0]== 'O' && board[2][0]== 'O' ||
        board[0][1] == 'O' && board[1][1]== 'O' && board[2][1]== 'O' || board[0][2] == 'O' && board[1][2]== 'O' && board[2][2]== 'O' ||
        board[0][0] == 'O' && board[1][1]== 'O' && board[2][2]== 'O' || board[0][2] == 'O' && board[1][1]== 'O' && board[2][0]== 'O'
    )
        return 1;
        else if (
        board[0][0] == 'X' && board[0][1]== 'X' && board[0][2]== 'X' || board[1][0] == 'X' && board[1][1]== 'X' && board[1][2]== 'X' ||
        board[2][0] == 'X' && board[2][1]== 'X' && board[2][2]== 'X' || board[0][0] == 'X' && board[1][0]== 'X' && board[2][0]== 'X' ||
        board[0][1] == 'X' && board[1][1]== 'X' && board[2][1]== 'X' || board[0][2] == 'X' && board[1][2]== 'X' && board[2][2]== 'X' ||
        board[0][0] == 'X' && board[1][1]== 'X' && board[2][2]== 'X' || board[0][2] == 'X' && board[1][1]== 'X' && board[2][0]== 'X'
        )
        return 2;
        else
        return 0;
}
bool check_end_of_game (char board[SIZE][SIZE]) {
    if (check_three_in_a_row(board) == 0){
        return false;}
        else{
            return true;
        }
    
}
void get_player1_move (char board[SIZE][SIZE]){
    int row; int col;
    if (!check_end_of_game(board)){
        int row; int col;
    if (!check_legal_option(board, row-1, col-1)){
        cout << "Player 1 enter your selection [row col]: " ;
        cin >>row;
        cin >> col;
        }
    
    board[row-1][col-1]= 'O';
    display_table(board);
    
    }
}
void print_winner (char board[SIZE][SIZE]) {
    if (check_three_in_a_row(board) == 1){
        cout << "Congratulations, Player 1 wins!" << endl;}
        else if (check_three_in_a_row(board) == 2){
         cout << "Congratulations, Player 2 wins!" << endl;    
        }
    
}













