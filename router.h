#ifndef ROUTER_H
#define ROUTER_H
#include"link.h"
#include<vector>
struct Message
{
    Message(char f,int w):f_(f),w_(w){}
    char f_;
    int w_;
};
struct Trace
{
    char fr_=0;
    int we_=0;
};

class Router
{
public:
    Router(char,int);
    char name_;
    void addLink(char r,int weight);
    std::vector<Router*> prout;
    std::vector<Message> mess;
    void plantMessage(char,int);
    Trace trace;
    int priority_;
    std::vector<class Link> links_;
    void writeTrace(char fr,int we);
};

#endif // ROUTER_H
