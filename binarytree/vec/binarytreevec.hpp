
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public BinaryTree<Data>
{

private:

  // ...

protected:

  struct NodeVec : virtual public  BinaryTree<Data>::Node
  {
    private:

    protected:

    public:
      ~NodeVec() = default;
      Data elemento;
      int indiceNodoCurr;
      
      Data& Element() noexcept; // Mutable access to the element (concrete function should not throw exceptions)
      const Data& Element() const noexcept; // Immutable access to the element (concrete function should not throw exceptions)

      bool IsLeaf() noexcept; // (concrete function should not throw exceptions)
      bool HasLeftChild() noexcept; // (concrete function should not throw exceptions)
      bool HasRightChild() noexcept; // (concrete function should not throw exceptions)

      NodeVec& LeftChild() const; // (concrete function must throw std::out_of_range when not existent)
      NodeVec& RightChild() const; // (concrete function must throw std::out_of_range when not existent)

  };

  Vector<NodeVec> vettore();


public:
  // Default constructor
  BinaryTreeVec() = default; //Albero vuoto

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeVec(const LinearContainer<Data>&); // A binary tree obtained from a LinearContainer

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
  BinaryTreeVec<Data>& operator=(const BinaryTreeVec<Data>& albero);

  // Move assignment
  BinaryTreeVec<Data>& operator=(BinaryTreeVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeVec<Data>&) const noexcept;
  bool operator!=(const BinaryTreeVec<Data>&) const noexcept;

  /* ************************************************************************ */
  // Specific member functions (inherited from BinaryTree)
  NodeVec& Root() const override; // Override BinaryTree member (throw std::length_error when empty)
  /* ************************************************************************ */
  // Specific member functions (inherited from Container)
  void Clear() override; // Override Container member
  // svuoto vettore con Vector<Data>::Clear();
};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
