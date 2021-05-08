
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk: virtual public BinaryTree<Data> { // Must extend BinaryTree<Data>

private:

  // ...

protected:

  using BinaryTree<Data>::size;

  struct NodeLnk: virtual public BinaryTree<Data>::Node { // Must extend Node

  private:

    // ...

  protected:

    // ...

  public:
    NodeLnk() = default;
    NodeLnk(const Data&);
    ~NodeLnk();
    Data element;
    NodeLnk* right = nullptr;
    NodeLnk* left = nullptr;

    Data& Element() noexcept override;
    const Data& Element() const noexcept override;
    bool IsLeaf() const noexcept override;
    bool HasLeftChild() const noexcept override;
    bool HasRightChild() const noexcept override;
    NodeLnk& LeftChild() const override;
    NodeLnk& RightChild() const override;



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
  NodeLnk& Root() const override;   // Override BinaryTree member (throw std::length_error when empty)


  /* ************************************************************************ */

  // Specific member functions (inherited from Container)
  // type Clear() specifiers;
  void Clear() override; // Override Container member

  // Funzione Insert
  NodeLnk* BuildTree(NodeLnk*);
  // Funzione Insert (LinearContainer)
  NodeLnk* BuildTree(const LinearContainer<Data>&, unsigned int, NodeLnk*);

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
