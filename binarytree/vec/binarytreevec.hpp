
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public BinaryTree<Data> { // Must extend BinaryTree<Data>

private:

  // ...

protected:

  using BinaryTree<Data>::Node;

  struct NodeVec : virtual public Node { // Must extend Node

  private:

    // ...
    Data elemento;
    int indiceNodoCurr;

  protected:



  public:

    Data& Element() noexcept; // Mutable access to the element (concrete function should not throw exceptions)
    Data& Element() const noexcept; // Immutable access to the element (concrete function should not throw exceptions)

    bool IsLeaf() noexcept; // (concrete function should not throw exceptions)
    bool HasLeftChild() noexcept; // (concrete function should not throw exceptions)
    bool HasRightChild() noexcept; // (concrete function should not throw exceptions)

    NodoVec& LeftChild(); // (concrete function must throw std::out_of_range when not existent)
    NodoVec& RightChild(); // (concrete function must throw std::out_of_range when not existent)

  };

  Vector<NodeVec> vettore;


public:

  // Default constructor
  BinaryTreeVec() = default; //Albero vuoto

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeVec(const LinearContainer&); // A binary tree obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeVec(const BinaryTreeVec&);

  // Move constructor
  BinaryTreeVec(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeVec<Data>& operator=(const BinaryTreeVec<Data>& albero)

  // Move assignment
  BinaryTreeVec<Data>& operator=(BinaryTreeVec&&) noexcept

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // se > 0
  // int Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member
  // svuoto vettore con Vector<Data>::Clear();
};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
