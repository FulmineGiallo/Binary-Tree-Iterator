
namespace lasd
{

/* ************************************************************************** */
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk()
{
  delete sx;
  delete dx;
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
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() noexcept
{
    if(sx != nullptr)
      return true;
    else
      return false;
}
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() noexcept
{
    if(dx != nullptr)
      return true;
    else
      return false;
}
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() noexcept
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
  // if(HasLeftChild() == true)
  //   return *sx;
  // else
  // {
  //   throw std::out_of_range("Il nodo corrente non ha figlio sinitro!");
  // }
  NodeLnk& tmp = *sx;
  return tmp;
}
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild() const
{
  // if(HasRightChild() == true)
  //   return *dx;
  // else
  // {
  //   throw std::out_of_range("Il nodo corrente non ha figlio destro!");
  // }
  NodeLnk& tmp = *dx;
  return tmp;
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::Insert(const LinearContainer<Data>& con, unsigned long i, NodeLnk* root)
{
  // if(i < con.Size())
  // {
  //   root = new NodeLnk(con[i]);
  //   root->left  = Insert(con,(i*2)+1, root->left);
  //   root->right = Insert(con,(i*2)+2, root->right);
  // }
  // return root;
}

//Constructor with LinearContainer
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const LinearContainer<Data>& con)
{
  // root = Insert(con,0,root);
}


template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::Insert(NodeLnk* root)
{
  // NodeLnk* tmp = new NodeLnk();
  // tmp->element = root.Element();
  // if(root.HasLeftChild())
  //   tmp->left = Insert(root->left);
  // if(root.HasRightChild())
  //   tmp->right = Insert(root->right);
  // return tmp;
}
//Constructor Copy
template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk<Data>& albero2)
{
  // root = Insert(albero2.Root());
}
//Constructor Move
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data>&& albero2) noexcept
{
  // root = std::move(albero2.Root());
}

template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk()
{
  Clear();
}
template <typename Data>
void BinaryTreeLnk<Data>::Clear()
{
    delete root;
}

template<typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data>& albero2)
{
  // if(!albero2.Empty())
  //   root = Insert(albero2.Root());
  return *this;
}
template<typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data>&& albero2) noexcept
{
  // root = std::move(albero2.Root());
  return *this;
}

template<typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data>& albero2) const noexcept{
  return (Root() == albero2.Root());
}
template<typename Data>
bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data>& albero2) const noexcept{
  return !(Root() == albero2.Root());
}
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root() const
{
  // if(HasRightChild() == true)
  //   return *dx;
  // else
  // {
  //   throw std::out_of_range("Il nodo corrente non ha figlio destro!");
  // }

}
/* ************************************************************************** */

}
