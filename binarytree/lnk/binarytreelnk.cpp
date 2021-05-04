
namespace lasd
{

/* ************************************************************************** */
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk()
{
  delete sx;
  delete dx;

}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& value)
{
  element = value;
}

//Mutable
template <typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept
{
  return element;
}
//Immutable
template <typename Data>
const Data& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept
{
  return element;
}
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept
{
    if(sx != nullptr)
      return true;
    else
      return false;
}
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept
{
    if(dx != nullptr)
      return true;
    else
      return false;
}
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept
{
    if(HasLeftChild() || HasRightChild())
    {
      return true;
    }
    else
      return false;
}
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const
{
  if(HasLeftChild() == true)
    return *sx;
  else
  {
    throw std::out_of_range("Il nodo corrente non ha figlio sinitro!");
  }

}
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild() const
{
  if(HasRightChild() == true)
    return *dx;
  else
  {
    throw std::out_of_range("Il nodo corrente non ha figlio destro!");
  }

}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::Insert(const LinearContainer<Data>& con, unsigned long i, NodeLnk* root)
{
  if(i < con.Size())
  {
    root = new NodeLnk(con[i]);
    root->sx  = Insert(con,(i*2)+1, root->sx);
    root->dx  = Insert(con,(i*2)+2, root->dx);
  }
  return root;
}

//Constructor with LinearContainer
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const LinearContainer<Data>& con)
{
  root = Insert(con,0,root);
  size = con.Size();
}


template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::Insert(NodeLnk* radice)
{
  root = new NodeLnk();
  root->element = radice->Element();
  if(root->HasLeftChild())
    root->sx = Insert(radice->sx); //costruzione sottoalbero sx, e lo attacco
  if(root->HasRightChild())
    root->dx = Insert(radice->dx); //costruzione sottoalbero dx, e lo attacco
  return root;
}
//Constructor Copy
template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk<Data>& albero2)
{
  if(albero2.size > 0)
  {
    root = albero2.root;
  }
}
//Constructor Move
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data>&& albero2) noexcept
{
  std::swap(root, albero2.root);
  std::swap(size, albero2.size);
}

template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk()
{
  // Clear();
}
template <typename Data>
void BinaryTreeLnk<Data>::Clear()
{
    delete root;
    // root = nullptr;
    // size = 0;

}
// template<typename Data>
// typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk& nodo)
// {
//   Clear();
//   element = nodo.element;
//   if(nodo.HasLeftChild())
//     sx = Insert(&nodo.sx);
//   if(nodo.HasRightChild())
//     dx = Insert(&nodo.dx);
// }
// template<typename Data>
// typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk&& nodo) noexcept
// {
//   std::swap(Root(), nodo.Root());
//
// }
template<typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data>& albero2)
{
  if(!albero2.Empty())
    root = Insert(&albero2.Root());

  size = albero2.size;
  return *this;
}
template<typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data>&& albero2) noexcept
{
  std::swap(root, albero2.root);
  std::swap(size, albero2.size);
  return *this;
}

template<typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data>& albero2) const noexcept
{
  if(size == albero2.size)
    return (Root() == albero2.Root());
  else
    return false;
}
template<typename Data>
bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data>& albero2) const noexcept
{
  return !(Root() == albero2.Root());
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root() const
{
  if(size > 0)
    return *root; //(*root) mi riferisco al valore puntato.
  else
    throw std::length_error("BinaryTreeLnk è vuoto");
}
/* ************************************************************************** */

}
