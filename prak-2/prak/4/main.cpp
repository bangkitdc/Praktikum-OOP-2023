#include <iostream>
#include "Tool.hpp"
#include "Pickaxe.hpp"
#include "ReinforcedAxe.hpp"

int main() {
  Pickaxe *p1 = new Pickaxe();
  p1->use();
  p1->enchant();

  Pickaxe *p2 = new Pickaxe(*p1);
  Pickaxe *p3 = new Pickaxe();

  *p3 = *p3;

  ReinforcedAxe *r1 = new ReinforcedAxe();

  r1->use();
  ReinforcedAxe *r2 = new ReinforcedAxe(*r1);

  r2->enchant();

  ReinforcedAxe *r3 = new ReinforcedAxe(*r1 + *r2);

  r3->repair();

  delete r1; delete r2;
  delete r3;

  delete p1;
  delete p2;

  return 0;
}