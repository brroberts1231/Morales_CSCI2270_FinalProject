#include <iostream>
#include <string>
#include "Deck.h"
#include <stdlib.h>
using namespace std;
int main(){
    string players, operation, ai;
    int Players, Spot, AI, op, hoomans;
    playahs:
    cout<<"How many players will there be? (5 max)"<<endl;
    getline(cin,players);
    Players=stoi(players);
    if(Players<0||Players>5){
        cout<<"Not a valid number."<<endl;
        goto playahs;
    }
    ai_players:
    cout<<"How many players will be AI? (0-"<<Players<<")"<<endl;
    getline(cin,ai);
    AI=stoi(ai);
    if(AI<0||AI>Players){
        cout<<"Not a valid number."<<endl;
        goto ai_players;
    }
    Deck d(Players);
    if(AI!=0){
        hoomans=Players-AI;
        for(int i=0;i<hoomans;i++){
            Spot=rand()%Players-1;
            d.players[Spot].ai=false; //Changed player to players
        }
    }
    else{
        for(int i=0;i<Players;i++){
            d.players[i].ai=false; //Changed player to players
        }
    }
    d.DealCards(Players);
    for(int i=0;i<Players;i++){
        bool turn=true;
        if(!d.players[i].ai){ //Changed player to players
            while(turn){
                cout<<"Player "<<i+1<<", your hand is "<<d.players[i].hand<<".\nWould you like to\n1.Hit\n2.Stay\n3.See what the other hands are"<<endl; //Changed player to players
                getline(cin,operation);
                op=stoi(operation);
                switch(op){
                    case 1:
                        turn=d.hit(i);
                        break;
                    case 2:
                        turn=false;
                        break;
                    case 3:
                        d.peek(i); //supposed to input a value
                        break;
                    default:
                        cout<<"That is not a valid option."<<endl;
                }
            }
        }
        else{
            while(turn){
                cout<<"Player "<<i+1<<"'s hand is "<<d.players[i].hand<<endl; //Changed player to players
                if(d.players[i].sum()<17){ //Changed player to players
                    cout<<"Player "<<i+1<<" hits."<<endl;
                    turn=d.hit(i);
                }
                else{
                    cout<<"Player "<<i+1<<" stays."<<endl;
                    turn=false;
                }
            }
        }
    }
    //d.dealer(); doesn't exist?
    d.declare(Players); //supposed to take in an int, not sure what it should take in, but hopefully a step in the right direction
    return 0;
}
