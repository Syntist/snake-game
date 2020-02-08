#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
 
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
 
void gotoxy(short x, short y);
void border();
int checker();
void refresh();
void initial();
void body();
void bender();
void hidecursor();
void Delay(long double);
void score();
 
void up();
void down();
void left();
void right();
 
void food();
 
int lox[100],loy[100];
 
int fx,fy,check,ch,fix;
 
int count=3;
 
int speed;
 
int main(){
    int run;
    speed=100;
    initial();
    border();
    hidecursor();
    gotoxy(25,1);
    printf("Snake Game Created By Syntist");
   
    for(run=1;run>0;){
        refresh();
        score();
        food();
       
        if(kbhit()){
            ch=getch();
            if(ch==UP && fix==2){
                ch=DOWN;
            }
            else if(ch==DOWN && fix==1){
                ch=UP;
            }
            else if(ch==LEFT && fix==4){
                ch=RIGHT;
            }
            else if(ch==RIGHT && fix==3){
                ch=LEFT;
            }
        }
       
        bender();
        Delay(speed);
        run=checker();
    }
   
    return 0;
}
 
void bender(){
   
    if(ch==UP){
        up();
    }
    else if(ch==DOWN){
        down();
    }
    else if(ch==LEFT){
        left();
    }  
    else if(ch==RIGHT){
        right();
    }
 
}
 
void body(){
    int x,y;
    y=count-1;
        for(x=count-2;x>=0;x--){
            lox[y]=lox[x];
            loy[y]=loy[x];
            y--;
        }
}
 
void initial(){
    int x;
    lox[0]=40;
    loy[0]=14;
    for(x=1;x<count;x++){
        lox[x]=lox[0]-x;
        lox[x]=lox[0]-x;
        loy[x]=loy[0];
    }
}
 
void gotoxy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
 
void refresh(){
    int x,y;
    y=5;
    while(y<24){
        for(x=11;x<70;x++){
            gotoxy(x,y);
            printf(" ");
        }
        y++;
    }
}
 
void border(){
    int i;
    for(i=10;i<71;i++)
   {
       gotoxy(i,4);
            printf("!");
       gotoxy(i,24);
            printf("!");
   }
   for(i=4;i<25;i++)
   {
       gotoxy(10,i);
            printf("!");
       gotoxy(70,i);
            printf("!");
   }
}
 
 
int checker(){
    int i;
    for(i=1;i<count;i++){
        if(lox[0]==lox[i] && loy[0]==loy[i]){
            gotoxy(75,8);
            printf("Game Over!!!");
            Sleep(700);
            return 0;
        }
    }
   
    if(lox[0]==10 || lox[0]==71 || loy[0]==4 || loy[0]==24){
        gotoxy(75,8);
        printf("Game Over!!!");
        Sleep(700);
        return 0;
    }
   
    else{
        return 1;
    }
}
 
 
void right(){
    int i,x,y;
    for(i=0;i<count;i++){
        x=lox[i];
        y=loy[i];
        if(i==0){
            gotoxy(x,y);           
            printf("%c",178);
        }
        else{
            gotoxy(x,y);
            printf("%c",176);
        }
    }
    body();
    lox[0]=lox[0]+1;
    fix=4;
}
 
void left(){
    int i,x,y;
    for(i=0;i<count;i++){
        x=lox[i];
        y=loy[i];
        if(i==0){
            gotoxy(x,y);           
            printf("%c",178);
        }
        else{
            gotoxy(x,y);
            printf("%c",176);
        }
    }
    body();
    lox[0]=lox[0]-1;
    fix=3;
}
 
void up(){
    int i,x,y;
    for(i=0;i<count;i++){
        x=lox[i];
        y=loy[i];
        if(i==0){
            gotoxy(x,y);           
            printf("%c",178);
        }
        else{
            gotoxy(x,y);
            printf("%c",176);
        }
    }
    body();
    loy[0]=loy[0]-1;
    fix=1;
}
 
void down(){
    int i,x,y;
    for(i=0;i<count;i++){
        x=lox[i];
        y=loy[i];
        if(i==0){
            gotoxy(x,y);           
            printf("%c",178);
        }
        else{
            gotoxy(x,y);
            printf("%c",176);
        }
    }
    body();
    loy[0]=loy[0]+1;
    fix=2;
}
 
void food(){
    if(check!=1){
        fx = (rand()%60) + 11;
        fy = (rand()%19) + 5;
        check=1;
    }
    else if(check==1){
        if(lox[0]==fx && loy[0]==fy){
            check=0;
            count++;
            speed=speed-2;
        }
    }
    gotoxy(fx,fy);
    printf("F");
}
 
void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
 
void Delay(long double k)
{
    long double i;
    for(i=0;i<=(10000000);i++);
}
 
void score(){
    gotoxy(75,6);
    printf("Score = %3d",count-3);
}
