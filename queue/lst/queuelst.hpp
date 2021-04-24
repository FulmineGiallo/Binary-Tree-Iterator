
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst: virtual public Queue<Data>, virtual protected List<Data>
{

private:

  // ...

protected:

  using List<Data>::size;
  using List<Data>::testa;
  using List<Data>::coda;


public:

  // Default constructor
  QueueLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  QueueLst(const LinearContainer<Data>& con); // A queue obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  QueueLst(const QueueLst<Data>& newQueue);

  // Move constructor
  QueueLst(QueueLst<Data>&& newQueue) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~QueueLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  QueueLst<Data>& operator=(const QueueLst<Data>& newQueue);

  // Move assignment
  QueueLst<Data>& operator=(QueueLst<Data>&& newQueue) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const QueueLst<Data>& newQueue) const noexcept;
  bool operator!=(const QueueLst<Data>& newQueue) const noexcept;

  /* ************************************************************************ */

  // Specific member functions
  void Enqueue(const Data&); // Copy of the value
  void Enqueue(Data&&) noexcept; // Move of the value

  /************************************************************************** */
  Data& Head() const; // (concrete function must throw std::length_error when empty)
  void Dequeue(); // (concrete function must throw std::length_error when empty)
  Data HeadNDequeue(); // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */
  // Specific member functions (inherited from Container)
  void Clear() override; // Override Container member

};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
