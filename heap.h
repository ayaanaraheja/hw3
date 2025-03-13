#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int m_aryness;
  std::vector<T> heap;
  PComparator comp;

  void trickleUp(size_t index);
  void trickleDown(size_t index);
};



// constuctor + destructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_aryness(m), comp(c) {
  if (m < 2) {
    throw std::invalid_argument("m must be at least 2");
  }
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}




// OTHER MEMBER FUNCTIONS
// Add implementation of member functions here
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  heap.push_back(item);
  trickleUp(heap.size() - 1);
}
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return heap.empty();
}
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return heap.size();
}




// TOP() AND POP() SEMI GIVEN
// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap[0];
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  std::swap(heap[0], heap.back());
  heap.pop_back();
  if (!heap.empty()) {
    trickleDown(0);
  }
}




// MY FUNCTIONS
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(size_t index) {
  while (index > 0) {
    size_t parent = (index - 1) / m_aryness;
    if (comp(heap[index], heap[parent])) {
      std::swap(heap[index], heap[parent]);
      index = parent;
    } else {
      break;
    }
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(size_t index) {
  while (true) {
    size_t bestChild = m_aryness * index + 1;  // First child
    if (bestChild >= heap.size()) break;

    for (size_t i = 1; i < m_aryness; ++i) {
      size_t child = m_aryness * index + 1 + i;
      if (child < heap.size() && comp(heap[child], heap[bestChild])) {
        bestChild = child;
      }
    }

    if (comp(heap[bestChild], heap[index])) {
      std::swap(heap[index], heap[bestChild]);
      index = bestChild;
    } else {
      break;
    }
  }
}


#endif

