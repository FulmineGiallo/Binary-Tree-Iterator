
namespace lasd
{

/* ***************************************************************************/

template <typename Data>
StackLst<Data>::StackLst(const LinearContainer<Data>& con)
{
  unsigned int currSize = con.Size();
  for( unsigned int i = 0;  i < currSize; i++)
    List<Data>::InsertAtBack(con[i]);
}

// Copy constructor
template <typename Data>
StackLst<Data>::StackLst(const StackLst<Data>& newStack):List<Data>::List(newStack)
{}

//move constructor
template <typename Data>
StackLst<Data>::StackLst(StackLst<Data>&& newStack) noexcept :List<Data>(std::move(newStack))
{}

// Copy assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst& newStack)
{
  List<Data>::operator=(newStack);
  return *this;
}
// Move assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst&& newStack) noexcept
{
  List<Data>::operator=(std::move(newStack));
  return *this;
}

template <typename Data>
bool StackLst<Data>::operator==(const StackLst<Data>& newStack) const noexcept
{
    return List<Data>::operator==(newStack);
}

template <typename Data>
bool StackLst<Data>::operator!=(const StackLst<Data>& newStack) const noexcept
{
    return !(*this == newStack);
}

//Copy PUSH
template <typename Data>
void StackLst<Data>::Push(const Data& val)
{
  List<Data>::InsertAtFront(val);
}
//Move PUSH
template <typename Data>
void StackLst<Data>::Push(Data&& val) noexcept
{
    List<Data>::InsertAtFront(std::move(val));
}

template <typename Data>
Data& StackLst<Data>::Top() const
{
  return List<Data>::Front();
}

template <typename Data>
void StackLst<Data>::Pop()
{
    List<Data>::RemoveFromFront();
}

template <typename Data>
Data StackLst<Data>::TopNPop()
{
  Data valueRemoved;
  valueRemoved = Top();
  Pop();
  return valueRemoved;
}

template <typename Data>
void StackLst<Data>::Clear()
{
  List<Data>::Clear();
}
/* ************************************************************************** */

}
