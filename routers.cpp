#include "routers.h"

Routers::Routers()
{
    for(int i=1;i<=5;i++)
    {
        pRouters_.push_back(new Router('A'+i-1,i));
    }
}
void Routers::addLinks(char z,char x,int w)
{
    pRouters_.at(z-'A')->addLink(x,w);
    pRouters_.at(x-'A')->addLink(z,w);
}
