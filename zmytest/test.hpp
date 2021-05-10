
#ifndef ZMYTEST_HPP
#define ZMYTEST_HPP
#include "../vector/vector.hpp"
/* ************************************************************************** */
namespace lasd
{

  template <typename Data>
  void riempi(lasd::Vector<Data>& v, int n);

  void riempiString(lasd::Vector<std::string>& v, int dim);
  void MenuVec(int type, int dim);
  void MenuLnk(int type, int dim);
  void MenuUtente();

}

/* ************************************************************************** */

#endif
