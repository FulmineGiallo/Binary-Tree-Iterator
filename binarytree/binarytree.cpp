
#include "../stack/stack.hpp"

namespace lasd
{

// ************************************************************************** NODE

// Opertator == (Node)
template<typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& newNode) const noexcept{
  bool val = true;

  if(Element() == newNode.Element()){
    if(HasLeftChild() && newNode.HasLeftChild()){
      val = (LeftChild() == newNode.LeftChild());
    }else if (HasLeftChild() || newNode.HasLeftChild()){
      return false;
    }
    if(val){
      if(HasRightChild() && newNode.HasLeftChild()){
        val = RightChild() == newNode.RightChild;
      }else if(HasRightChild() || newNode.HasRightChild()){
        return false;
    }
  }
  return val;
  }
}

// Opertator != (Node)
template<typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& newNode) const noexcept{
  return !(*this == newNode);
}

// Opertator ==
template<typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree& tree) const noexcept{
  return Root() == tree.Root();
}

// Opertator !=
template<typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree& tree) const noexcept{
  return Root() != tree.Root();
}

//****************************************************************************** PRE ORDER

// Specific constructors
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& pre){
  node = pre.Root();
}

// Copy constructor
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data>& pre){
  stack = pre.stack;
  node = pre.node;
}

// Move constructor
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data>&& pre) noexcept{
  stack = std::move(pre.stack);
  node = std::move(pre.node);
}

// Copy assignment
template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data>& pre){
  stack = pre.stack;
  node = pre.node;
  return *this;
}

// Move assignment
template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data>&& pre) noexcept{
  stack = std::move(pre.stack);
  node = std::move(pre.node);
  return *this;
}

// Opertator ==
template<typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data>& pre) const noexcept{
  if(stack == pre.stack && node == pre.node){
    return true;
  }else{
    return false;
  }
}

// Operator !=
template<typename Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator<Data>& pre) const noexcept{
  return !(*this == pre);
}

// Operator *
template<typename Data>
Data& BTPreOrderIterator<Data>::operator*() const
{
  if (Terminated()){
    throw std::out_of_range("Iteratore terminato!");
  }else{
    return node.Element();
  }
}

// Terminated
template<typename Data>
bool BTPreOrderIterator<Data>::Terminated() noexcept{
  return node == nullptr;
}

// Operator ++
template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++()
{
  if (node.HasLeftChild()){
    stack.push(node.RightChild());
    node = node.LeftChild;
  }else{
    if(node.HasRightChild()){
      node = node.RightChild();
    }else{
      if(stack.Empty()){
        node = nullptr;
      }else{
        stack.TopNPop();
      }
    }
  }
}

//****************************************************************************** POST ORDER

// Specific constructors
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BinaryTree<Data>& post)
{
  Node tmp = post.Root();
  while(tmp.HasLeftChild() || tmp.HasRightChild()){
    stack.push(tmp);
    if(tmp.HasLeftChild()){
      tmp = tmp.LeftChild();
    }else{
      tmp = tmp.RightChild();
    }
    node = tmp;
  }
}

// Copy constructor
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator& post){
  node = post.node;
  stack = post.stack;
}

// Move constructor
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator&& post) noexcept{
  node = std::move(post.node);
  stack = std::move(post.stack);
}

// Copy assignment
template<typename Data>
BTPostOrderIterator& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator& post){
  node = post.node;
  stack = post.stack;
  return *this;
}

// Move assignment
template<typename Data>
BTPostOrderIterator& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator&& post) noexcept
{
  node = std::move(post.node);
  stack = std::move(post.stack);
  return *this;
}

// Operator ==
template<typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator& post) const noexcept{
  if(node == post.node && stack == post.stack){
    return true;
  }else{
    return false;
  }
}

// Operator !=
template<typename Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator& post) const noexcept{
  return !(*this == post);
}

// Operator *
template<typename Data>
Data& BTPostOrderIterator<Data>::operator*(){
  return node;
}

// Terminated
template<typename Data>
bool BTPostOrderIterator<Data>::Terminated() noexcept{
  return node == nullptr && stack.Empty();
}

// // Operator ++
// template<typename Data>
// BTPostOrderIterator& BTPostOrderIterator<Data>::operator++(){
//   if(!stack.Empty()){
//     if(stack.Top().RightChild() != node){
//       node = stack.Top().RightChild();
//       while (node.HasLeftChild() || node.HasRightChild()){
//         if(node.HasLeftChild()){
//           stack.push(node);
//           node = node.LeftChild();
//         }else{
//           stack.push(node);
//           node = node.RightChild();
//         }
//       }
//       if(stack.Top().HasRightChild){
//         node = stack.Top().RightChild();
//       }
//       node = stack.TopNPop();
//     }
//     // node = stack.Top().RightChild()
//     // Forse ti sposti sul sottoalbero destro
//   }
// }

/* ************************************************************************** */

}
