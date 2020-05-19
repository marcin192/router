#ifndef LINK_H
#define LINK_H
#include "router.h"

class Link
{
public:
    Link(class Router*,int);
    class Router* route_;
    int weight_;
};

#endif // LINK_H
