// ��ǻ�Ͱ��а� 2021111954 ������
#include "ptyqueue.h"

template <class DT>
PtyQueue<DT>::PtyQueue(int maxNumber)
	
{
	Heap<DT>::Heap(maxNumber);

}

template<class DT>
void PtyQueue<DT>::enqueue(const DT& newDataItem)
{
	Heap<DT>::insert(newDataItem);
	
}

template<class DT>
DT PtyQueue<DT>::dequeue()
{
	DT temp;
	temp = Heap<DT>::removeMax();
	
	return temp;
}
