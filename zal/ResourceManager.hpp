#pragma once

#include "Resource.hpp"
using namespace std;

class ResourceManager
{
  ResourceManager() /* na stercie, wskaźnik do r lista inic */
  {r = new Resource;}

  ~ResourceManager() {delete r}

  ResourceManager(const ResourceManager& rm) /* stwórz nowy obiekt będący kopią *(rm.r) i przepisze jego adres do r    */
  {r = new Resource{*rm.r}}


  ResourceManager& operator=(const ResourceManager& rm)
  {
    //zwolnij bieżący zasób na ktory wskazuje return - nie usuniemy to wyciek pamięci
    //swtórz nowy obiekt będący kopia *(rm.r) i przypisz jego adres do return

    return *this;
  }

  ResourceManager(ResourceManager&& rm)
  {
    //sprawdz czy &rm i this to nie to samo, jeśli tak, nie rób nic
    r = nullptr;
    r=rm.r;
    rm.r=nullptr;
  }

  Resource *r;
    double get() {return r->get();}
};
