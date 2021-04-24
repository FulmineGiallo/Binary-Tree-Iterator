
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec { // Must extend BinaryTree<Data>

private:

  // ...

protected:

  // using BinaryTree<Data>::???;

  // ...

  struct NodeVec { // Must extend Node

  private:

    // ...

  protected:

    // Data dato;
    // int indiceNodoCurr;

  public:

    // ...

  };
  // Vetctor<NodeVec> nodi;
public:

  // Default constructor
  // BinaryTreeVec() specifiers; //Albero vuoto

  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeVec(argument) specifiers;

  // Move constructor
  // BinaryTreeVec(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeVec() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

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
