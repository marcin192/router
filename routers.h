#ifndef ROUTERS_H
#define ROUTERS_H
#include "router.h"
#include <vector>
class Routers
{
public:
    Routers();
    std::vector<Router*> pRouters_;
    void addLinks(char z,char x,int w);
};

#endif // ROUTERS_H
