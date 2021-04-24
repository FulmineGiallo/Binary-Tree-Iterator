
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst: virtual public Stack<Data>, virtual protected List<Data>
{

private:

  // ...

protected:

  using List<Data>::size; //riferimento a size, oppure ad altro
  using List<Data>::testa; //riferimento a testa per implementare lo

  //Nello stackLst, gli inserimenti Push() avvengono tramite insertAtFront().
  //Nello stackLst, le  rimozioni    Pop()  avvengono tramite RemoveFromFront().

public:

  // Default constructor, senza parametri. dovrebbe richiamare quello di List
  StackLst() = default;

  // StackLst() specifier;

  /* ************************************************************************ */

  // Specific constructor
  StackLst(const LinearContainer<Data>& con); //DONE

  /* ************************************************************************ */

  // Copy constructor
  StackLst(const StackLst<Data>& newStack); //DONE

  // Move constructor
  StackLst(StackLst&&) noexcept; //DONE


  /* ************************************************************************ */
  // Destructor
  ~StackLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackLst<Data>& operator=(const StackLst&);  //DONE

  // Move assignment
  StackLst<Data>& operator=(StackLst&&) noexcept; //DONE

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackLst&) const noexcept; //DONE
  bool operator!=(const StackLst&) const noexcept; //DONE

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  //metodi pubblici, fare ovverride
  void Push(const Data& val); // Override Stack member (copy of the value) //DONE
  void Push(Data&& val) noexcept; // Override Stack member (move of the value)     //DONE


  /****************************************************************************/

  Data& Top() const override; // Override Stack member (must throw std::length_error when empty) DONE
  void Pop()  override; // Override Stack member (must throw std::length_error when empty) DONE
  Data TopNPop() override; // Override Stack member (must throw std::length_error when empty) DONE

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member DONE
  // non ci sarà motivo di fare l'ovveride di empty e size

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
