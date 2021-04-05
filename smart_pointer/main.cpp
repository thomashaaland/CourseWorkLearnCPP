#include "Sclass.h"
#include <memory>
#include <cassert>

std::unique_ptr<Sclass> pass_through(std::unique_ptr<Sclass> p) {
  return p;
}

int main() {

  auto s = std::make_unique<Sclass>();
  auto ss = pass_through(std::move(s));
  assert(!s);
  
  return 0;
}
