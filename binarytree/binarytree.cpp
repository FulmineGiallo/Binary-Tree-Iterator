
// #include "..."

namespace lasd {

/* ************************************************************************** */

template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& node2) const noexcept
{
  //Usare approccio Ricorsivo
  bool ret = true;

  if(Element() == node2.Element())
  {
    if(HasLeftChild() && node2.HasLeftChild())
    {
      ret = (LeftChild() == nodo2.LeftChild());
    }
    else if(HasLeftChild() || node2.HasLeftChild())
      return false;
    if(ret) //Se tutti i rami sinistri sono uguali, allora posso controllare tutti i rami destri.
    {
      if(HasRightChild() && node2.HasRightChild())
      {
        ret = (RightChild() == nodo2.RightChild());
      }
      else if(HasRightChild() || node2.HasRightChild())
        return false;
    }
  }
  return ret;
}
template <typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& node2) const noexcept
{
  return !(*this == node2);
}


template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree& albero2) const noexcept
{
  return Root() == albero2.Root();
}
template <typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree& albero2) const noexcept
{
  return !(Root() == albero2.Root());
}


template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& tree)
{
  curr = tree.Root();
}
/* ************************************************************************** */

}
