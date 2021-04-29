
namespace lasd {

/* ************************************************************************** */
//Copy constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& albero)
{
  vettore = albero.vettore;
}
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const LinearContainer<Data>& con)
{
  vettore.Resize(con.Size());
  for(unsigned long i = 0; i < con.Size(); i++){
    vettore[i].Element = con[i];
    vettore[i].currIndex = i;
  }
}
//Move constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec&& albero) noexcept
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
//Move Assigment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec&& albero) noexcept
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
  if(2*(indiceNodoCurr+ 1) + 2<= vettore.Size())
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
// LeftChild
template <typename Data>
NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild()
{
  if(HasLeftChild())
  {
    return vector[2*(indiceNodoCurr + 1)];
  }
  else
  {
    throw std::out_of_range("Il nodo corrente non ha figlio sinistro!");
  }
}

// RightChild
template <typename Data>
NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild()
{
  if(HasRightChild())
  {
    return vector[2*(indiceNodoCurr + 1) + 1];
  }
  else
  {
    throw std::out_of_range("Il nodo corrente non ha figlio destro!");
  }
}
//Metodo Root()
template <typename Data>
NodeVec& BinaryTreeVec<Data>::Root()
{
  if(vettore.Size() < 0)
    throw std::length_error("Albero Vuoto, non puoi recuperare la Root!");
  else
    return vettore[0];
}

//Metodo Clear()
template <typename Data>
void BinaryTreeVec<Data>::Clear()
{
  vettore.Clear();
}
// Opertator ==
template <typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec& albero2) const noexcept
{
  return  Root() == albero2.Root();
}
// Opertator !=
template <typename Data>
bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec& albero2) const noexcept
{
  return !(Root() == albero2.Root());
}
/* ************************************************************************** */

}
