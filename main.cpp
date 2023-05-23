#include <iostream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;

int RPS;
string pickRPS;
int win=0;
int lost=0;
int draw=0;


//tworzenie losowej wartości z kamiennych(Rock)=0 nożyczek(Scissors)=1 i papieru(Paper)=2
void randomRPS(){
    RPS = rand()%3;
}
//Gracz wybiera RPS
void getFromUserRPS(){
    vector<string> vec={"R","r","rock","Rock","0","S","s","Scissors","scissors","1","P","p","Paper","paper","2"};
    vector<string> rock={"R","r","rock","Rock","0"};
    vector<string> scissors={"S","s","Scissors","scissors","1"};
    vector<string> paper={"P","p","Paper","paper","2"};
    cout<<"Write 0,r,R,Rock,rock-you pick Rock"<<endl<<"1,S,s,Scissors,scissors-you pick Scissors"<<endl<<"2,p,P,Paper,paper-you pick Paper"<<endl<<"What you pick : ";
    getline(cin,pickRPS);
        //sprawdzanie rzeby uzytkownik wybral paper nozyczek lub kamien
        if (find(vec.begin(), vec.end(), pickRPS) != vec.end() ){
            if(find(rock.begin(), rock.end(), pickRPS) != rock.end()){
                pickRPS="0";
            }
            if(find(scissors.begin(), scissors.end(), pickRPS) != scissors.end()){
                pickRPS="1";
            }
            if(find(paper.begin(), paper.end(), pickRPS) != paper.end()){
                pickRPS="2";
            }
        }else{return getFromUserRPS();}
}
//Wypisywanie wygrales przegrales czy remis
void verification(int verify){
    if(verify==0){cout<<"U have win"<<endl;win++;}
    if(verify==1){cout<<"U have draw"<<endl;draw++;}
    if(verify==2){cout<<"U have lost"<<endl;lost++;}
}
//sam kod który zprawdza wynik
void gameRPS(){
    getFromUserRPS();
    randomRPS();
        if(RPS==0){
            if(pickRPS=="0"){verification(1);}
            if(pickRPS=="1"){verification(0);}
            if(pickRPS=="2"){verification(2);}
        }
        if(RPS==1){
            if(pickRPS=="0"){verification(2);}
            if(pickRPS=="1"){verification(1);}
            if(pickRPS=="2"){verification(0);}
        }
        if(RPS==2){
            if(pickRPS=="0"){verification(0);}
            if(pickRPS=="1"){verification(2);}
            if(pickRPS=="2"){verification(1);}
        }
}
//rachunek
void score(){
    cout<<"You win "<<win<<" times"<<endl;
    cout<<"You lost "<<lost<<" times"<<endl;
    cout<<"You draw "<<draw<<" times"<<endl;
}
//zasady
void rules(){
    cout<<"En-The winner is determined according to the following rules:"<<endl;
    cout<<"    Paper beats stone (paper wraps stone)."<<endl;
    cout<<"    Stone defeats scissors (stone dulls or breaks scissors)."<<endl;
    cout<<"    Scissors beat paper (scissors cut paper)."<<endl;
    cout<<"Pl-Zwyciezca jest ustalany wedlug nastepujacych zasad:"<<endl;
    cout<<"    Papier bije kamien (papier owija kamien)."<<endl;
    cout<<"    Kamien pokonuje nozyce (kamien tepi lub lamie nozyce)."<<endl;
    cout<<"    Nozyczki bija papier (papier ciety nozyczkami)."<<endl;

}
//menu wyboru akcji
void menu(){
    string change;
    vector<int> vec={1,2,3};
    cout<<"------MENU------"<<endl;
    cout<<"Pick 1-play game RPS(Rock Paper Scissors)"<<endl<<"2-score"<<endl<<"3-rules"<<endl<<"Write your pick : ";
    getline(cin,change);
    int a = atoi(change.c_str());
    if (find(vec.begin(), vec.end(), a) != vec.end() ){
        if(a==1){cout<<"------GAME------"<<endl;gameRPS();menu();}
        if(a==2){cout<<"------SCORE------"<<endl;score();menu();}
        if(a==3){cout<<"------RULES------"<<endl;rules();menu();}
    }else{return menu();}
}
int main(){
    srand (time(NULL));
    menu();
    return 0;
}
