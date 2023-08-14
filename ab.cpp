// CODE BY Vaibhav Goel
 // Copying or sharing of this code without permission of the Author is strictly prohibited!!!
#include<bits/stdc++.h>
#include<conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
const int width=20  ;
const int height=20;
int x,y,fruitX,fruitY,score;
int tailX[100],tailY[100];
int nTail;
enum eDirection {Stop,LEFT,RIGHT,UP,DOWN};
eDirection dir;
void Setup(){
gameOver=false;
dir=Stop;
x=width/2;
y=height/2;
fruitX=2+rand()%(width-3);
fruitY=2+rand()%(height-3);
score=0;
}
void Draw(){
system("cls");
    
for(int i=0;i<width;i++)
cout<<"#";
cout<<endl;
for(int i=1;i<height-1;i++){
    for(int j=0;j<width;j++){
        if(j==0)
        cout<<'#';
        else if(j==width-1)
        cout<<'#'<<endl;
        else if(i==fruitY && j==fruitX)
        cout<<'F';
        else if(i==y && j==x)
        cout<<'O';
        else{
            bool print=false;
        for(int k=0;k<nTail;k++){
            if(tailX[k]==j  && tailY[k]==i){
            cout<<"o";
            print=true; 
            }
        }
        if(!print)
        cout<<" ";
        }
        

    }
}
for(int i=0;i<width;i++)
cout<<"#";
cout<<endl;
cout<<"Score :"<<score<<endl;
}
void Input(){
if(kbhit()){
char c=getch();
if(c=='a')
dir=LEFT;
else if(c=='s')
dir=DOWN;
else if(c=='d')
dir=RIGHT;
else if(c=='w')
dir=UP;
else if(c=='x'){
gameOver=true;
}
}
}
void Logic(){
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for(int i=1;i<nTail;i++){
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }
if(dir==UP)
y--;
else if(dir==DOWN)
y++;
else if(dir==RIGHT)
x++;
else if(dir==LEFT)
x--;
if(x<0 ||x>=width || y<0 ||y>=height)
gameOver=true;
if(x==fruitX && y== fruitY){
    
    score+=10;
 fruitX=2+rand()%(width-3);
fruitY=2+rand()%(height-3); 
nTail++;  
}
}
int main(){
Setup();
while(!gameOver){

    // cout<<x<<" "<<y<<endl;
    Draw();
    Input();
    Logic();
Sleep(10);
}

return 0;
}