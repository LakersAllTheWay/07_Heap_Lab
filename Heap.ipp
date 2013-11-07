#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
	backingArray = new std::pair<Pri, T>[10];
	numItems = 0;
	arrSize = 10;
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
	delete[] backingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
  //TODO
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
  //TODO
  if ((numItems + 1) > arrSize) {
	grow();
  }
  backingArray[numItems] = toAdd;
  numItems++;
  bubbleUp(numItems - 1);
 
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
  //TODO
	int p = (index - 1)/2;
	
	while (index > 0 && (backingArray[index].first < backingArray[p].first)) {
		//swap i and p
		std::pair <Pri, T> temp = backingArray[index];
		backingArray[index].first = backingArray[p].first;
		backingArray[index].second = backingArray[p].second;
		backingArray[p].first = temp.first;
		backingArray[p].second = temp.second;
		index = p;
		p = (index - 1)/2;
	}
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
	do {
		int j = -1;
		int right = (2*index)+2;
		if (right < numItems && (backingArray[right].first < backingArray[index].first)){
			int left = (2*index)+1;
			if (backingArray[left].first < backingArray[right].first){
				j = left;
			}
			else {
				j = right;
			}
		}
		else {
			int left = (2*index)+1;
			if (left < numItems && (backingArray[left].first < backingArray[index].first)){
				j = left;
			}
		}
		if (j >= 0){
			std::pair <Pri, T> temp = backingArray[index];
			backingArray[index].first = backingArray[j].first;
			backingArray[index].second = backingArray[j].second;
			backingArray[j].first = temp.first;
			backingArray[j].second = temp.second;
			//index = j;
			//j = (index - 1)/2;
		}
		index = j;
	} while (index <= 0);
}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
  //TODO
  
  std::pair<Pri, T> x = backingArray[0];
	backingArray[0] = backingArray[numItems-1];
	numItems--;
	trickleDown(0);
    return x;
  //std::pair<Pri,T> tmp;
  //return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  //TODO
  return numItems;
}
