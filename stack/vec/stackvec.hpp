
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec: virtual public Stack<Data>, virtual protected Vector<Data>
{

private:

  // ...

protected:

  using Vector<Data>::size;
  using Vector<Data>::Elements;
  int indice = -1; // forse dovrebbe essere -1

public:

  // Default constructor
  StackVec(); //DONE
  /* ************************************************************************ */

  // Specific constructor
  StackVec(const LinearContainer<Data>& con); // A stack obtained from a LinearContainer DONE

  /* ************************************************************************ */

  // Copy constructor
  StackVec<Data>(const StackVec<Data>&); //DONE

  // Move constructor
  StackVec(StackVec<Data>&&) noexcept; //DONE

  /* ************************************************************************ */
  // Destructor
  ~StackVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackVec<Data>& operator=(const StackVec<Data>& newVec); //DONE

  // Move assignment
  StackVec<Data>& operator=(StackVec<Data>&& newVec) noexcept; //DONE

  /* ************************************************************************ */
  // Comparison operators
  bool operator==(const StackVec<Data>&) const noexcept; //
  bool operator!=(const StackVec<Data>&) const noexcept; //

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  void Push(const Data& val) override; // Override Stack member (copy of the value) fare il test estensione DONE
  void Push(Data&& val) noexcept override; // Override Stack member (move of the value) DONE
  /****************************************/

  Data& Top() const override; // Override Stack member (must throw std::length_error when empty) DONE
  void Pop() override; // Override Stack member (must throw std::length_error when empty) decrementa l'indice, senza cancellare, verà sovrascritto poi, fare il test riduzione DONE
  Data TopNPop() override; // Override Stack member (must throw std::length_error when empty) DONE

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)
  bool Empty() const noexcept; // Override Container member     DONE
  unsigned long Size() const noexcept; // Override Container member DONE
  void Clear() ; // Override Container member DONE

protected:
  // Auxiliary member functions
  void Expand(); // è void, perchè puoi stackvec.Expand();
  void Reduce();

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
