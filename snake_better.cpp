#include<iostream>
#include<conio.h>
#include<ctime>


bool gg;                            //game over

const int lat=20;                   //marime teren
const int inalt=15;

int x,y,fructx,fructy,scor;

int snakeX[50],snakeY[50];                  //sarpe
int lungSarpe;
enum Directie{STOP=0,LEFT,RIGHT,UP,DOWN};       //Controale
Directie dir;


void Start(){
    gg=false;
    dir=STOP;
    x=lat/2;
    y=inalt/2;
    fructx=rand()%lat;                          //coordonate fruct
    fructy=rand()%inalt;
}


void Desen(){
    system("cls");
    
    for(int i=0;i<=lat+1;i++)                   //tavan
        printf("-");

    printf("\n");

    for(int i=0;i<inalt;i++){

        for(int j=0;j<lat;j++){

            switch(j){
                case 0:
                    printf("|");                    //perete stanga
                    break;
                default:
                    break;
            }

            if(i==y && j==x)

                printf("0");

            else if(i==fructy && j==fructx)

                printf("@");

                else {
                    bool print=false;
                    for(int k=0;k<lungSarpe;k++){
                        if(snakeX[k]==j && snakeY[k]==i){
                            printf("0");
                            print=true;
                        }
                    }
                    if(!print) 
                        printf(" ");
                    
                }

            switch(j){
                case lat-1:
                    printf("|");                        //perete dreapta
                    break;  
                default:
                    break;
            }

        }
        printf("\n");
    }

    for(int i=0;i<=lat+1;i++)
        printf("-");                                      //podea

    printf("\n");
    printf("Score:%i\n",scor);
}


void Move(){

    if(kbhit()){

        if(lungSarpe==0)
            switch(getch()) {

            case 'w':
                    dir=UP;
                    break;

            case 's':
                    dir=DOWN;
                    break;

            case 'a':
                    dir=LEFT;
                    break;

            case 'd':
                    dir=RIGHT;
                    break;
            default:
                break;

        }

        else
            switch(getch()) {

                case 'w':
                    if(dir!=DOWN){
                        dir=UP;}
                        break;

                case 's':
                    if(dir!=UP){
                        dir=DOWN;}
                        break;

                case 'a':
                    if(dir!=RIGHT){
                        dir=LEFT;}
                        break;

                case 'd':
                    if(dir!=LEFT){
                        dir=RIGHT;}
                        break;
                default:
                    break;

            }

    }

}



void Game(){
    int prevX=snakeX[0];
    int prevY=snakeY[0];
    int prev2X,prev2Y;
    snakeX[0]=x;
    snakeY[0]=y;

    for(int i=1;i<lungSarpe;i++){
        prev2X=snakeX[i];
        prev2Y=snakeY[i];
        snakeX[i]=prevX;
        snakeY[i]=prevY;
        prevX = prev2X;
        prevY = prev2Y ;
    }

    switch (dir){
        case UP:
            y--;
            break;

        case DOWN:
            y++;
            break;

        case LEFT:
            x--;
            break;

        case RIGHT:
            x++;
            break;
        
        default:
            break;
    }

    if(x>=lat)                                              //coliziune cu peretii(
        x=0;
    else if(x<0)
        x=lat-1;
    if(y>=inalt)
        y=0;
    else if(y<0)
        y=inalt-1;                                          //)

    for(int i=0;i<lungSarpe;i++){

        if(snakeX[i]==x && snakeY[i]==y)
            gg=true;
    }

    if(x==fructx && y==fructy){
        scor+=10;
        fructx=rand()%lat;
        fructy=rand()%inalt;
        lungSarpe++;
    }

}


int main(){
    srand((unsigned) time(NULL));
    rand();
    Start();

    while(!gg){
    Desen();
    Move();
    Game();
    }
    printf("Gane over!");
    return 0;
}