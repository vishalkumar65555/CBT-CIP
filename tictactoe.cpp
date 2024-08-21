#include<iostream>
using namespace std;

char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row,column;
bool draw=false;

void display_board()
{
    system("cls");
    cout<<"\n\n TIC\tTAC\tTOE\tGAME"<<endl;
   cout<<"\tPlayer1 [X]\n\tPlayer2 [O]\n\n";

   
    //interface

   cout<<"\t\t     |     |     \n";
   cout<<"\t\t"<<"  "<<arr[0][0]<<"  |"<<"  "<<arr[0][1]<<"  |"<<"  "<<arr[0][2]<<"\n";
   cout<<"\t\t_____|_____|_____\n";
   cout<<"\t\t     |     |     \n";
   cout<<"\t\t"<<"  "<<arr[1][0]<<"  |"<<"  "<<arr[1][1]<<"  |"<<"  "<<arr[1][2]<<"\n";
   cout<<"\t\t_____|_____|_____\n";
   cout<<"\t\t     |     |     \n";
   cout<<"\t\t"<<"  "<<arr[2][0]<<"  |"<<"  "<<arr[2][1]<<"  |"<<"  "<<arr[2][2]<<"\n";
   cout<<"\t\t     |     |     \n";
}
void player_turn()
{
   int choice;
   if(turn=='X')
   cout<<"\n    Player1 [X] Turn: \n";
   if(turn=='O')
   cout<<"\n    Player2 [O] Turn: \n";
   cin>>choice;
   switch(choice)
   {
    case 1:row=0;column=0;break;
    case 2:row=0;column=1;break;
    case 3:row=0;column=2;break;
    case 4:row=1;column=0;break;
    case 5:row=1;column=1;break;
    case 6:row=1;column=2;break;
    case 7:row=2;column=0;break;
    case 8:row=2;column=1;break;
    case 9:row=2;column=2;break;
    default:
    cout<<"Invalid choice\n";
    break;
   }
   if(turn=='X' && arr[row][column]!='X'&&arr[row][column]!='O')
   {
    arr[row][column]='X';
    turn='O';
   }
   else if(turn=='O'&& arr[row][column]!='X'&&arr[row][column]!='O')
   {
    arr[row][column]='O';
    turn='X';
   }
   else
   {
    cout<<"Box already filled!! Please try again\n\n";
    player_turn();
   }
   display_board();
   
}
bool gameover()
{   //check win
    for(int i=0;i<3;i++)
    if(arr[i][0]==arr[i][1]&&arr[i][0]==arr[i][2]||arr[0][i]==arr[1][i]&&arr[0][i]==arr[2][i])
    return false;
    if(arr[0][0]==arr[1][1]&&arr[0][0]==arr[2][2]||arr[0][2]==arr[1][1]&&arr[0][0]==arr[2][0])
    return false;
    //check playing
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    {
    if(arr[i][j]!='X'&&arr[i][j]!='O')
    return true;
    }

    //check draws
    draw=true;
    return false;


}
int main()
{ 
    while(gameover())
    { 
    display_board();
   player_turn();
   gameover();
   }
   if(turn=='X'&& draw==false)
    cout<<"PLAYER 2 WINS[O] CONGRATULATIONS!!\n";
   else if(turn=='O'&& draw==false)
    cout<<"PLAYER 1 WINS[X] CONGRATULATIONS!!";
    else{
        cout<<"game draw!!\n";
    }
   return 0;
}