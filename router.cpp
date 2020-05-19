#include "router.h"
#include <iostream>

Router::Router(char name,int priority):name_(name),priority_(priority)
{

}
void Router::addLink(char r,int weight)
{

    switch(r)
    {
    case 'A':
        links_.push_back(Link{prout.at(r-'A'),weight});
        break;
    case 'B':
        links_.push_back(Link{prout.at(r-'A'),weight});
        break;
    case 'C':
        links_.push_back(Link{prout.at(r-'A'),weight});
        break;
    case 'D':
        links_.push_back(Link{prout.at(r-'A'),weight});
        break;
    case 'E':
        links_.push_back(Link{prout.at(r-'A'),weight});
        break;

    }

}
void Router::plantMessage(char f, int w )
{
    mess.push_back(Message{f,w});
    std::cout<<"Wyslano wiadomosc  z  "<<f<<"  "<<w<<std::endl;
}
void Router::writeTrace(char fr,int we)
{
    trace.fr_=fr;
    trace.we_=we;
}
