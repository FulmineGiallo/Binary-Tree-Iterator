
namespace lasd {

/* ************************************************************************** */

//Copy constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& albero)
{
  vettore = albero.vettore;
}
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec&&) noexcept
{
  vettore = std::move(albero.vettore);
}
//Copy Assigment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& albero)
{
  vettore = albero.vettore;
  return *this;
}
//Move assigment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec&&) noexcept
{
  vettore = std::move(albero.vettore);
  return *this;
}

template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept
{
    return vettore[indiceNodoCurr];
}
template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept
{
    return vettore[indiceNodoCurr];
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() noexcept
{
  if(2*(indiceNodoCurr+ 1) + 1<= vettore.Size())
    return true;
  else
    return false;

}
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() noexcept
{
  if(2*(indiceNodoCurr+ 1) + 2 <= vettore.Size())
    return true;
  else
    return false;
}
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::IsLeaf() noexcept
{
  if(!(HasLeftChild() || HasRightChild()))
    return true;
  else
    return false;
}
/* ************************************************************************** */

}
