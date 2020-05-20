#include <iostream>
#include"router.h"
#include"link.h"
#include "routers.h"
#include <regex>
//#include <fstream>


int main()
{
    //std::ifstream file("C:\\Users\\marcin\\Documents\\build-router-Desktop_Qt_5_14_2_MinGW_64_bit-Debug\\debug\\file2.txt");
    //std::string strin;
    //std::string strin2;
    //std::string dump;
    //std::vector<int> pos;
    //int po=0;
    //for(int i=1;i<=100;i++)
    //{
      //  std::getline(file,strin);
        //std::getline(file,strin2);
       // std::getline(file,dump);
    //}

    char parent;
    //int odpowiedz;
    //std::cout<<"\nPozycja  "<<i<<std::endl;
    std::cout<<"Podaj tekst"<<std::endl;
    std::string text;
    std::string text2;
    std::regex linki("[A-E][A-E]=[1-9]");
    std::regex parents("routerowi [A-E]");
    //std::regex odp("[0-9]?[0-9]");
    std::getline(std::cin,text);
    //text=strin;
    text2=text;
    std::smatch matches;
    std::smatch matches2;
    //std::smatch matchesodp;
    std::vector<std::string> txt;
    while (std::regex_search(text,matches,linki)) {
        txt.push_back(matches.str());
        text=matches.suffix().str();
    }
    while (std::regex_search(text2,matches2,parents)) {
        parent=matches2.str()[10];
        text2=matches2.suffix().str();
    }
    //while (std::regex_search(strin2,matchesodp,odp)) {
      //  odpowiedz=std::stoi(matchesodp.str());
        //strin2=matchesodp.suffix().str();
    //}
    int h =100;
    int mina=6;
    char tempf;
    int tempw;
    int ms=0;
    int tbls=0;
    Routers routers;
    for(auto &it:routers.pRouters_)
        it->prout=routers.pRouters_;
    for(auto&it:txt)
    {
        routers.addLinks(it[0],it[1],it[3]-'0');
    }
    std::cout<<"nowy wpis do   "<<"Z"<<"  "<<"0"<<std::endl;
    tbls++;
    for (auto &it:routers.pRouters_.at(parent-'A')->links_)
    {
        it.route_->plantMessage(parent,0);
        mina=std::min(it.route_->priority_,mina);
        ms++;
    }
    while(h>0)
    {
        for(auto &it:routers.pRouters_)
        {
            if(it->name_==parent)
                continue;
            if(it->mess.size()>0)
            {
                if(it->trace.fr_==0&&it->trace.we_==0)
                {
                    it->trace.fr_=it->mess.at(0).f_;
                    tempf=it->mess.at(0).f_;
                    for(auto &q:it->links_)
                    {
                        if(q.route_->name_==tempf)
                            tempw=q.weight_;

                    }
                    it->trace.we_=it->mess.at(0).w_+tempw;
                    std::cout<<"nowy wpis  do   "<<it->trace.fr_<<"  "<<it->trace.we_<<std::endl;
                    tbls++;
                    it->mess.erase(it->mess.begin());
                    for(auto &ito:it->links_)
                    {
                        if(ito.route_->name_==it->trace.fr_)
                            continue;
                        ito.route_->plantMessage(it->name_,it->trace.we_);
                        ms++;
                    }
                }
                else
                {
                    Trace temptrace;
                    temptrace.fr_=it->mess.at(0).f_;
                    tempf=it->mess.at(0).f_;
                    for(auto &q:it->links_)
                    {
                        if(q.route_->name_==tempf)
                            tempw=q.weight_;

                    }
                    temptrace.we_=it->mess.at(0).w_+tempw;
                    it->mess.erase(it->mess.begin());
                    if(it->trace.we_>temptrace.we_)
                    {
                        it->trace=temptrace;
                        std::cout<<"nowy wpis  do   "<<it->trace.fr_<<"  "<<it->trace.we_<<std::endl;
                        tbls++;
                        for(auto &ito:it->links_)
                        {
                            if(ito.route_->name_==it->trace.fr_)
                                continue;
                            ito.route_->plantMessage(it->name_,it->trace.we_);
                            ms++;
                        }
                    }
                }
                break;
            }
        }
        h--;
    }

    std::cout<<"\nWiadomosci   "<<ms<<std::endl;
    std::cout<<"Wpisow   "<<tbls<<std::endl;
    //if(tbls==odpowiedz)
    //{
      //  std::cout<<"dobrze"<<std::endl;
        //po++;
    //}
    //else
    //{
      //  std::cout<<odpowiedz<<std::endl;
        //pos.push_back(i);
    //}
//}
    //std::cout<<po<<std::endl;
    //for(auto &it:pos)
      //  std::cout<<it<<std::endl;
    std::cin.get();
    return 0;
}
