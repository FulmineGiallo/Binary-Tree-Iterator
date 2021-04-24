
#ifndef STACK_HPP
#define STACK_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Stack: virtual public Container
{

private:

  // ...

protected:

  // ...

public:

  Stack() = default;
  // Destructor
  ~Stack() = default;

  /* ************************************************************************ */

  // Copy assignment
  Stack& operator=(const Stack<Data>&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  Stack& operator=(Stack<Data>&&) = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Stack<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const Stack<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual void Push(const Data& val) = 0; // Copy of the value
  virtual void Push(Data&& val) noexcept = 0; // Move of the value
  /*****************************************************/
  virtual Data& Top() const = 0;// (concrete function must throw std::length_error when empty)
  virtual void  Pop() = 0; // (concrete function must throw std::length_error when empty)
  virtual Data  TopNPop() = 0; // (concrete function must throw std::length_error when empty)

};

/* ************************************************************************** */

}

#endif
