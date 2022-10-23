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
    int m;
    std::vector<T> pq;
    PComparator p;
    void heapify(int idx);
    void trickleUp(int loc);
};


// Add implementation of member functions here


// We will start top() for you to handle the case of
// calling top on an empty heap

template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
    // Here we use exceptions to handle the case of trying
    // to access the top element of an empty heap
    if(empty()){
        throw std::underflow_error("I'm empty");

    }
    // If we get here we know the heap has at least 1 item
    // Add code to return the top element
  else return pq[0];


}


// We will start pop() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
    if(empty()){
        throw std::underflow_error("I'm empty");
    }
		if(pq.size() == 1){
			std::swap(pq[0], pq.back());
      pq.pop_back();
		}
    else{
      std::swap(pq[0], pq.back());
      pq.pop_back();
			heapify(0);
    }
  

}

template<typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) {
this->m = m;
this->p = c;
}

template<typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {

}

template<typename T, typename PComparator>
void Heap<T, PComparator>::push(const T &item) {

    pq.push_back(item);
		if(pq.size() == 1){
			
		}
		else{
    trickleUp(pq.size()-1);
		}
}
template<typename T, typename PComparator>
void Heap<T, PComparator>::heapify(int idx)
{
   if((unsigned)(idx*m + 1) >= pq.size()) {
		 return;
		 }
		 
    int smallerChild = m*idx + 1; // start w/ left
		int min = smallerChild;
		if(smallerChild < (int) (pq.size() - 1)){
			int rightChild;
			for(int i = 1; (i < m && (unsigned)(smallerChild + i) < pq.size()); i++){
				rightChild = smallerChild + i;
					if(p(pq[rightChild], pq[min]))
							min = rightChild;
			
		}
		}
		
	if(p(pq[min], pq[idx])){
		std::swap(pq[idx], pq[min]);
		heapify(min);
	}
}
template<typename T, typename PComparator>

void Heap<T, PComparator>::trickleUp(int loc)
{
	if(loc == 0){
		return;
	}

    int parent = (loc - 1)/m;
    while(parent >= 0 && p(pq[loc], pq[parent]))
    { std::swap(pq[parent], pq[loc]);
        //loc = parent;
        //parent = (loc - 1)/m;
				trickleUp(parent);
    }
	
		
}
template<typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
    return pq.empty();
}

template<typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
    return pq.size();
}



#endif

