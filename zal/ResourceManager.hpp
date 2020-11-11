#pragma once

#include "Resource.hpp"

class ResourceManager
{
  public:
  ResourceManager()
  {r = new Resource;}

  ~ResourceManager() {delete r;}

  ResourceManager(const ResourceManager& rm)
  {r = new Resource{*rm.r};}


  ResourceManager operator=(const ResourceManager& rm)
  {
  
           if (&rm != this) {
            delete r;
            r = new Resource{*rm.r}; 
        }
    return *this;
  }
     ResourceManager& operator=(const ResourceManager&& rm)
  {
  
           if (&rm != this) {
            delete r;
            r = rm.r;
            rm.r = nullptr; 
        }
    return *this;
  }
 
double get() {return r->get();}
  ResourceManager(ResourceManager&& rm)
  {

    r = nullptr;
    r=rm.r;
    rm.r=nullptr;
  }
private:
  Resource *r;
  
};
