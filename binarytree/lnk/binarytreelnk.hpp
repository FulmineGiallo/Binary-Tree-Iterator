
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk: virtual public BinaryTree<Data>
{

private:

  // ...

protected:

  // using BinaryTree<Data>::???;

  struct NodeLnk: virtual public BinaryTree<Data>::Node
  { // Must extend Node

  private:



  protected:



  public:
    ~NodeLnk();
    NodeLnk() = default;

    Data element;

    NodeLnk *dx = nullptr;
    NodeLnk *sx = nullptr;

    Data& Element() noexcept;
    const Data& Element() const noexcept;
    bool IsLeaf() noexcept;
    bool HasLeftChild() noexcept;
    bool HasRightChild() noexcept;
    NodeLnk& LeftChild() const;
    NodeLnk& RightChild() const;

  };
NodeLnk *root = nullptr;
public:

  // Default constructor
  // BinaryTreeLnk() specifiers;
  BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeLnk(argument) specifiers;
  // A binary tree obtained from a LinearContainer
  BinaryTreeLnk(const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeLnk(argument) specifiers;
  BinaryTreeLnk(const BinaryTreeLnk&);

  // Move constructor
  // BinaryTreeLnk(argument) specifiers;
  BinaryTreeLnk(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeLnk() specifiers;
  ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BinaryTreeLnk& operator=(const BinaryTreeLnk<Data>& tree);

  // Move assignment
  // type operator=(argument) specifiers;
  BinaryTreeLnk& operator=(BinaryTreeLnk<Data>&& tree) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BinaryTreeLnk<Data>&) const noexcept;

  // type operator!=(argument) specifiers;
  bool operator!=(const BinaryTreeLnk<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)
  // type Root() specifiers;
  // Override BinaryTree member (throw std::length_error when empty)
  NodeLnk& Root() const override;


  /* ************************************************************************ */

  // Specific member functions (inherited from Container)
  // type Clear() specifiers;
  // Override Container member
  void Clear() override;

  NodeLnk& Insert(const LinearContainer<Data>& con, unsigned long i, NodeLnk* root);
  NodeLnk& Insert(NodeLnk* root);
};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
