#pragma once

#include "Resource.hpp"

class ResourceManager
{
  Resource* r;

public:

    ResourceManager()
    {
      r = new Resource;
    }

    ResourceManager(const ResourceManager& rm)
    {
      r = new Resource{*rm.r};
    }

    ResourceManager(ResourceManager&& rm)
    { 
      r = nullptr;
      r = rm.r;
      rm.r = nullptr;
    }

    ~ResourceManager() 
    {
      delete r;
    }

    double get() 
    { 
      return r->get(); 
    }

    ResourceManager operator=(const ResourceManager& rm)
    {
        if (&rm != this) {
            delete r;
            r = new Resource{*rm.r}; 
        }
        return *this;
    }

    ResourceManager operator=(ResourceManager&& rm)
    {
        if (&rm != this) {
            delete r;
            r = rm.r;
            rm.r = nullptr;
        }
        return *this;
    }
};
