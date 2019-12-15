/* DESIGNED By
**            _ _ _ _      _ _ _
** |         |            |     |
** |         |_ _ _ _     |     |
** |         |            |     |
** |_ _ _ _  |_ _ _ _     |_ _ _| Dahal
*/
#include<stdio.h>
#include<stdlib.h>
#define mausam 1
#define RED "\033[0;31m"
#define RESET "\033[0m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[0;34m"
#define CYAN "\033[0;36m"
#define MAGNETA "\033[0;35m"
#define nextLine "\n"
#define nextLines "\n\n"
#define COMPUTERMOVE "X"
#define USERMOVE "O"
#define RETURN_KEY 10
int game();
int clear();
int whoPlaysFirst();
int notice(int);
int quit_message();
int print_Theme_board();
int User_Play_board(int);
int computerPlayes();
int set_board();
int colors(char[]);
int bye_bye();
//void ask_User_Name();
void greet();
char board[10][10];
int player = 0;
char userName[20];
int user = 0;
int total_moves = 0;
int choises_done[10];
int check_Cell(int);
int check_Cell_Computer(int);
int check_Win_orGameOut();
int check_win(int);
int user_win();
int computer_win();
int check_game_out();
int game_out();
int check_row(int);
int check_column(int);
int check_diagonals();
/*#define greet(){\
        printf("\t\t\tTIC TAC TOE GAME\033[0m");\
		printf("\t\033[0;34m\n\n\n\t....................................................\n");\
		printf("\t.--------------------Hello!------------------------.\n");\
		printf("\t.----------You are Wellcome to this game.----------.\n");\
		printf("\t....................................................\033[0m\n\n\n\n\n\n\n\n\n");\
		printf("Press any key to continue......");\
	       }*/
 //--------------------------------------------------------
int main() {
    for(int i=0;i<9;i++)
        choises_done[i] = 0;
 	game();
   return 0;

}
 //--------------------------------------------------------
 /*void greet(){
    colors("red");
    printf("\t\t\tTIC TAC TOE GAME");
    colors("blue");
    printf("\t\n\n\n\t....................................................\n");
    printf("\t.--------------------Hello!------------------------.\n");
    printf("\t.----------You are Wellcome to this game.----------.\n");
    printf("\t....................................................\n\n\n\n\n\n\n\n\n");
    colors("reset");
    printf("Press any key to continue......");
    getchar();
 }*/
 void greet(){
    /*_
       |
     _ |
    (_),
    /|\
    /|\*/

    printf("\t"YELLOW" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n"RESET);
    printf(YELLOW"\t|"RESET""BLUE"-----------------------------------------------------------"RESET""YELLOW"|\n");
    printf("\t|"RESET""BLUE"------------------"RESET""MAGNETA"|"RED"Tic Tac Toe Game"MAGNETA"|"BLUE"-----------------------"RESET""YELLOW"|\n");
    printf("\t|"RESET""BLUE"-----------------------------------------------------------"RESET""YELLOW"|\n");
    printf("\t|"RESET""CYAN"==========================================================="RESET""YELLOW"|\n");
    printf("\t|"RESET""BLUE"-----------------------------------------------------------"RESET""YELLOW"|\n");
    printf("\t|"RESET""BLUE"-----------------------------------------------------------"RESET""YELLOW"|\n");
    printf("\t|"RESET""BLUE"--------------------"RESET""GREEN"Hello!"RESET""BLUE"-------------------------"RED"|"MAGNETA"  _  "RED"|"RESET""BLUE"-"RESET""YELLOW"|\n");
    printf("\t|"RESET""BLUE"----------"RESET""GREEN"You are wellcome to this Game"RESET""BLUE"------------"RED"|"MAGNETA" (_) "RED"|"RESET""BLUE"-"RESET""YELLOW"|\n");
    printf("\t|"RESET""BLUE"---------------------------------------------------"RED"|"MAGNETA" /|\\ "RED"|"RESET""BLUE"-"RESET""YELLOW"|\n");
    printf("\t|"RESET""BLUE"---------------------------------------------------"RED"|"MAGNETA" /|\\ "RED"|"RESET""BLUE"-"RESET""YELLOW"|\n");
    printf("\t|"RESET""BLUE"-----------------------------------------------------------"RESET""YELLOW"|\n");
    printf("\t|"RESET""BLUE"------------------------------------------"GREEN"Designed By LeO"BLUE"--"RESET""YELLOW"|\n");
    printf(YELLOW"\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "RESET"\n");
    printf("\n\n");
    /*printf("\t\t\t\t\t\t\t\t  _"nextLine);
    printf("\t\t\t\t\t\t\t\t   |"nextLine);
    printf("\t\t\t\t\t\t\t\t _ |"nextLine);
    printf("\t\t\t\t\t\t\t\t\(_\),"nextLine);
    printf("\t\t\t\t\t\t\t\t/|\\"nextLine);
    printf("\t\t\t\t\t\t\t\t/|\\"nextLine);*/
    printf("\n\n\n\nPress any key to continue......");
    getchar();
 }
 //--------------------------------------------------------
 int game(){

    set_board();
 	clear();
 	player = whoPlaysFirst();
 	if(player == 1){
        notice(player);
        quit_message();
        loop:
        print_Theme_board();
        int cell_choise = 0;
        user++;
        printf("User Input:");
        scanf("%d",&cell_choise);
        while(cell_choise!=000){
            User_Play_board(cell_choise);
            if(user == 1){
                computer:
                computerPlayes();
                check_Win_orGameOut();
                user--;
            }
            if(user == 0){
                printf("User Input:");
                scanf("%d",&cell_choise);
                User_Play_board(cell_choise);
                check_Win_orGameOut();
                user++;
                //goto computer;
            } else if(cell_choise >9){
                cell_choise = 0;
                goto loop;
            }
            else{
              //printf(RED"-------------------------ERROR-------------------------\n\n\n"RESET);
            }
        }
        bye_bye();
        return 0;
 	}
 	else if(player == 0){
        notice(player);
        quit_message();
        print_Theme_board();
 	}
 	else{
        return 0;
    }

 	return 0;

 }
 //--------------------------------------------------------
 int clear(){

    system("clear");
 	for(int i=1;i<=100;i++)
 		printf(nextLine);

   return 0;
 }
 /*
 int clear(){

    clrscr();

 }

 int clear(){

    system("clear");
    return 0;

 }
 */
 //--------------------------------------------------------
 int whoPlaysFirst(){

   #if mausam == 1
 	char choise_first = ' ';
 	greet();
 	clear();
 	//ask_User_Name();
 	clear();
 	printf("\n\n\nLet the computer play first\?(y/n):");
 	scanf("%c",&choise_first);
 	clear();
 	if(choise_first == RETURN_KEY){ //ASCII value for return key or enter key
 		printf(nextLine);
 		printf("First Player(Default):");
 		colors("green");
 		printf(" Computer");
 		colors("reset");
 		printf(nextLine);
 		return 0;
 	}
 	else if(choise_first == 'y'){
 		printf(nextLine);
 		printf("First Player:");
 		colors("green");
 		printf(" Computer");
 		colors("reset");
 		printf(nextLine);
 		return 0;
 	}
 	else if(choise_first == 'n'){
 		printf(nextLine);
 		printf("First Player:");
 		colors("green");
 		printf("%s",userName);
 		colors("reset");
 		printf(nextLine);
 		return 1;
 	}
 	else{
 		clear();
 		printf(RED"-------------------------ERROR-------------------------\n\n\n"RESET);
 		return 1000;
 	}
 	return 0;
   #endif
   return 2;

 }
 //--------------------------------------------------------
 int notice(int player){

 	if( player == 0 ){
 		printf(nextLines);
 		printf("Symbols");
 		printf("\nUser     = " GREEN "%s" RESET,COMPUTERMOVE);
 		printf("\nComputer = " GREEN "%s" RESET,USERMOVE);
 		printf(nextLine);
 	}
 	else if(player == 1){
 		printf(nextLines);
 		printf("Symbols");
 		printf("\nUser     = " GREEN "%s" RESET,USERMOVE);
 		printf("\nComputer = " GREEN "%s" RESET,COMPUTERMOVE);
 		printf(nextLine);
 	}
 	else if(player == 2){
 		printf(RED"Sorry User is not Mausam. __|__\n\n");
 	}
 	else{
 		return 0;
    }
    return 0;
 }
 //--------------------------------------------------------
 int print_Theme_board(){

 	printf(nextLines);
 	printf("Choose a cell numbered from 1 to 9 as below and play\n");
    colors("blue");
    printf("_________________\n");
	printf("|");
	colors("reset");
	printf(" 1  ");
	colors("blue");
	printf("|  ");
	colors("reset");
	printf("2  ");
	colors("blue");
	printf("|  ");
	colors("reset");
	printf("3 ");
	colors("blue");
	printf("|\n");
	colors("blue");
	printf("|---------------|\n");
	printf("|");
	colors("reset");
	printf(" 4  ");
	colors("blue");
	printf("|  ");
	colors("reset");
	printf("5  ");
	colors("blue");
	printf("|  ");
	colors("reset");
	printf("6 ");
	colors("blue");
	printf("|\n");
	colors("blue");
	printf("|---------------|\n");
	printf("| ");
	colors("reset");
	printf("7  ");
	colors("blue");
	printf("|  ");
	colors("reset");
	printf("8  ");
	colors("blue");
	printf("| ");
	colors("reset");
	printf("9  ");
	colors("blue");
	printf("|\n");
	colors("blue");
    printf("-----------------\n\n\n");
    colors("reset");
    return 0;

 }
 //--------------------------------------------------------
 int User_Play_board(int cell_choise){

  if(check_Cell_Computer(cell_choise)){
 	  if((cell_choise == 1 || cell_choise == 2 || cell_choise == 3)){
 		   board[0][cell_choise-1] = 'O';
       choises_done[cell_choise-1] = 1;
       total_moves++;
 	   }
 	   if((cell_choise == 4 || cell_choise == 5 || cell_choise == 6)){
 		    board[1][cell_choise-4] = 'O';
        choises_done[cell_choise-1] = 1;
        total_moves++;
 	   }
 	   if(cell_choise == 7 || cell_choise == 8 || cell_choise == 9){
 		    board[2][cell_choise-7] = 'O';
        choises_done[cell_choise-1] = 1;
        total_moves++;
 	   }
 	   else{

 	   }
     print_Board();
 	   //set_board(board[][10]);
 	   /*printf(nextLines);
 	   printf("_________________\n");
 	   printf("| %c  |  %c  | %c  |\n",board[0][0],board[0][1], board[0][2]);
	   printf("|---------------|\n");
	   printf("| %c  |  %c  | %c  |\n",board[1][0],board[1][1], board[1][2]);
	   printf("|---------------|\n");
	   printf("| %c  |  %c  | %c  |\n",board[2][0],board[2][1], board[2][2]);
	   printf("-----------------\n\n\n");*/
   }else{
     printf(RED"\nWrong Input\n"RESET);
   }
	return 0;
 }
 //--------------------------------------------------------
 int set_board(){

 	int i=0,j=0;
 	for(i=0;i<3;i++){
 		for(j=0;j<3;j++){
 			board[i][j] = ' ';
 		}
 	}
 	return 0;

 }
 //--------------------------------------------------------
 int computerPlayes(){
   //AI KEPT HERE
   printf("Hahahhahaha\n\n");
   int moves = 8;
   int randomnumber;
   random:
   randomnumber = rand() % (moves+1-0)+0;

   if(check_Cell(randomnumber)){
     printf("%d",randomnumber);
     if((randomnumber == 0 || randomnumber == 1 || randomnumber == 2)){
      board[0][randomnumber] = 'X';
      choises_done[randomnumber] = 1;
      total_moves++;
    }
    if((randomnumber == 3 || randomnumber == 4 || randomnumber == 5)){
       board[1][randomnumber-3] = 'X';
       choises_done[randomnumber] = 1;
       total_moves++;
    }
    if(randomnumber == 6 || randomnumber == 7 || randomnumber == 8){
       board[2][randomnumber-6] = 'X';
       choises_done[randomnumber] = 1;
       total_moves++;
    }
   }else {
     if(total_moves<9){
       goto random;
     }else{
       game_out();
     }
   }
    /*return 0;
   if(board[0][1] == 'O' && board[0][1]!= 'O' && board[0][2]!= 'O'){
     choises_done[2] = 1;
     board[0][1] = 'X';
   }*/
   print_Board();
  return 0;
 }
 //--------------------------------------------------------
 int quit_message(){
    printf("\033[0;31m\nPress \"q\" to quit.\n");
    printf("\033[0m" );
    return 0;
 }
 //--------------------------------------------------------
 int colors(char choosen_color[]){
  if(choosen_color == "red")
        printf("\033[0;31m");
    if(choosen_color == "reset")
        printf("\033[0m");
    if(choosen_color == "blue")
        printf("\033[0;34m");
    if(choosen_color == "yellow")
        printf("\033[1;33m");
    if(choosen_color == "green")
        printf("\033[0;32m");
    if(choosen_color == "magenta")
        printf("\033[0;35m");
    if(choosen_color == "cyan")
        printf("\033[0;36m");

   return 0;
 }
 //--------------------------------------------------------
 /*void ask_User_Name(){
    printf("\nEnter your name:");
    scanf("%s",&userName);
 }*/
 //--------------------------------------------------------
int bye_bye(){
    printf("Thank you!");
    return 0;
}
//--------------------------------------------------------
int check_Cell_Computer(int cell){

  if(choises_done[cell-1] == 0){

    return 1;

  }else{
    return 0;
  }

}
//--------------------------------------------------------
int check_Cell(int cell){

  if(choises_done[cell] == 0){

    return 1;

  }else{
    return 0;
  }

}
//--------------------------------------------------------
int  print_Board(){
  printf(nextLines);
  printf("_________________\n");
  printf("| %c  |  %c  | %c  |\n",board[0][0],board[0][1], board[0][2]);
  printf("|---------------|\n");
  printf("| %c  |  %c  | %c  |\n",board[1][0],board[1][1], board[1][2]);
  printf("|---------------|\n");
  printf("| %c  |  %c  | %c  |\n",board[2][0],board[2][1], board[2][2]);
  printf("-----------------\n\n\n");
}
//--------------------------------------------------------
int check_Win_orGameOut(){

  if(check_win(1)){
    user_win();
  }
  else if(check_win(0)){
    computer_win();
  }
  else if(check_game_out()){
    game_out();
  }
  else
  return 0;
}
//--------------------------------------------------------
int check_win(int player){
  if(player == 1){ //user
    if(check_row(1)){
      return 1;
    }else if(check_column(1)){
      return 1;
    }else if(check_diagonals(1)){
      return 1;
    }
  }
  if(player == 0){ //Computer
    if(check_row(0)){
      return 1;
    }else if(check_column(0)){
      return 1;
    }else if(check_diagonals(0)){
      return 1;
    }
    /*if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return(1);
    */
  }
  return 0;
}
//--------------------------------------------------------
int user_win(){

  clear();
  printf("User Won.");

}
//--------------------------------------------------------
int computer_win(){

  clear();
  printf("Computer won.");

}
//--------------------------------------------------------
int check_game_out(){
  return 0;
}
//--------------------------------------------------------
int game_out(){
  clear();
  printf("Game Out");
}
//--------------------------------------------------------
int check_row(int user){
  if(user == 1){
    if(board[0][1] == board[0][1] == board[0][2] == 'O')
      return 1;
    if(board[1][0] == board[1][1] == board[1][2] == 'O')
      return 1;
    if(board[2][0] == board[2][1] == board[2][2] == 'O')
      return 1;
  }
  if(user == 0){
    if(board[0][1] == board[0][1] == board[0][2] == 'X')
      return 1;
    if(board[1][0] == board[1][1] == board[1][2] == 'X')
      return 1;
    if(board[2][0] == board[2][1] == board[2][2] == 'X')
      return 1;
  }
  return 0;
}
//--------------------------------------------------------
int check_column(int user){
  if(user == 1){
    if(board[0][0] == board[1][0] == board[2][0] == 'O')
      return 1;
    if(board[0][1] == board[1][1] == board[2][1] == 'O')
      return 1;
    if(board[0][2] == board[1][2] == board[2][2] == 'O')
      return 1;
  }
  if(user == 0){
    if(board[0][0] == board[1][0] == board[2][0] == 'X')
      return 1;
    if(board[0][1] == board[1][1] == board[2][1] == 'X')
      return 1;
    if(board[0][2] == board[1][2] == board[2][2] == 'X')
      return 1;
  }
}
//--------------------------------------------------------
int check_diagonals(int user){
  if(user == 1){
    if(board[0][0] == board[1][1] == board[2][2] == 'O'){
      return 1;
    }
    if(board[0][2] == board[1][1] == board[2][0] == 'O'){
      return 1;
    }
  }
  if(user == 0){
    if(board[0][0] == board[1][1] == board[2][2] == 'X'){
      return 1;
    }
    if(board[0][2] == board[1][1] == board[2][0] == 'X'){
      return 1;
    }
  }
}
//--------------------------------------------------------
