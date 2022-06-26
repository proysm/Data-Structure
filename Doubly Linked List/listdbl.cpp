#include <iostream>
#include "listdbl.h"

using namespace std;

template < class DT >
ListNode<DT>::ListNode(const DT& data, ListNode* priorPtr, ListNode* nextPtr)
    :dataItem(data), prior(priorPtr), next(nextPtr)
{

}

// Constructor
template < class DT >
List<DT>::List(int ignored)
    :head(0), cursor(0)
{

}

// Destructor
template < class DT >
List<DT>::~List()
{
    delete head;
    delete cursor;
}


//------------ List manipulation operations ------------------

// Insert after cursor
template < class DT >
void List<DT>::insert(const DT& newDataItem)
{
    if (isEmpty()) //리스트가 빈 경우
    {
        head = new ListNode<DT>(newDataItem, NULL, NULL);
        cursor = head;
    }
    else if (cursor->next == NULL) //커서가 리스트의 마지막에 있을 때
    {
        ListNode<DT>* tempNode; // new
        tempNode = new ListNode<DT>(newDataItem, NULL, NULL);

        cursor->next = tempNode;
        tempNode->prior = cursor;
        cursor = tempNode;
    }
    else // 커서가 리스트 바깥 쪽에 있지 않은 경우
    {
        ListNode<DT>* tempNode; // new
        ListNode<DT>* nextNode; // 커서 다음
        tempNode = new ListNode<DT>(newDataItem, NULL, NULL);
        nextNode = cursor->next;

        tempNode->prior = cursor; 
        cursor->next = tempNode;
        tempNode->next = nextNode;
        nextNode->prior = tempNode;
        cursor = tempNode;
    }
}

// Remove data item
template < class DT >
void List<DT>::remove()
{
    ListNode<DT>* nextNode; // 커서의 다음
    ListNode<DT>* priorNode; // 커서의 이전
    ListNode<DT>* deleteNode; // 임시 저장

    if (isEmpty()) //리스트가 비었음
    {
        cout << "List is Empty." << endl;
    }
    else if (cursor->prior == NULL) //커서가 맨 앞
    {
        deleteNode = cursor;
        nextNode = cursor->next;
        cursor = nextNode;
        head = nextNode;
        nextNode->prior = NULL;
        delete deleteNode;
    }
    else if (cursor->next == NULL) //커서가 맨 뒤
    {
        deleteNode = cursor;
        priorNode = cursor->prior;
        priorNode->next = NULL; 
        cursor = head;
        delete deleteNode;
    }
    else if (cursor->prior == NULL && cursor->next == NULL) //노드가 하나 남음
    {
        deleteNode = cursor;
        cursor, head = NULL;
        delete deleteNode;
    }
    else
    {
        deleteNode = cursor;
        priorNode = cursor->prior;
        nextNode = cursor->next;
        priorNode->next = nextNode;
        nextNode->prior = priorNode;
        cursor = priorNode;
        delete deleteNode;
    }
}

// Replace data item
template < class DT >
void List<DT>::replace(const DT& newElement)
{
    ListNode<DT>* nextNode; // 커서의 다음을 가리킴
    ListNode<DT>* priorNode; // 커서의 이전을 가리킴
    ListNode<DT>* deleteNode; //삭제
    ListNode<DT>* tempNode; // 임시 저장
    tempNode = new ListNode<DT>(newElement, NULL, NULL);
    deleteNode = cursor; // 포인터 정의
    priorNode = cursor->prior;
    nextNode = cursor->next;

    if (isEmpty()) cout << "The list is Empty" << endl;
    else if (priorNode == NULL)
    {
        tempNode->next = nextNode;
        nextNode->prior = tempNode;
        cursor = tempNode; // 새로운 data를 넣는다.
        head = tempNode;
        delete deleteNode;
    }
    else if (nextNode == NULL)
    {
        tempNode->prior = priorNode; 
        priorNode->next = tempNode;
        cursor = tempNode; 
        delete deleteNode;
    }
    else
    {
        tempNode->prior = priorNode; // prior와 next로 묶어준다.
        priorNode->next = tempNode;
        tempNode->next = nextNode;
        nextNode->prior = tempNode;

        cursor = tempNode; // 새로운 data를 넣는다.
        delete deleteNode;
    }
}

// Clear list
template < class DT >
void List<DT>::clear()
{
    if (isEmpty()) cout << "The list is already Empty.";
    while (!isEmpty())
    {
        ListNode<DT>* deleteNode; //요소를 지우기 위한 임시저장소
        deleteNode = head;
        head = head->next;
        delete deleteNode;
    }
}


//------------ List status operations ------------------

// List is empty
template < class DT >
bool List<DT>::isEmpty() const
{
    return(head == NULL);
}

// List is full
template < class DT >
bool List<DT>::isFull() const
{
    return 0; //리스트는 가득 찰 수 없음
}


//------------ List manipulation operations ------------------

// Go to beginning
template < class DT >
void List<DT>::gotoBeginning()
{
    ListNode<DT>* tempNode;
    tempNode = cursor->prior;
    while(tempNode != NULL)
    {
        cursor = cursor->prior;
        tempNode = cursor->prior;
    }
}

// Go to end
template < class DT >
void List<DT>::gotoEnd()
{
    ListNode<DT>* tempNode;
    tempNode = cursor->next;
    while (tempNode != NULL)
    {
        cursor = cursor->next;
        tempNode = cursor->next;
    }
}

// Go to next data item
template < class DT >
bool List<DT>::gotoNext()
{
    ListNode<DT>* nextNode;
    nextNode = cursor->next;
    if (isEmpty() || nextNode == NULL) return false;
    else
    {
        cursor = cursor->next;
    }
}

// Go to prior data item
template < class DT >
bool List<DT>::gotoPrior()
{
    ListNode<DT>* priorNode;
    priorNode = cursor->prior;
    if (isEmpty() || priorNode == NULL) return false;
    else
    {
        cursor = cursor->prior;
    }

}


template < class DT >
DT List<DT>::getCursor() const
{
    DT element;
    if (isEmpty()) cout << "The list is Empty." << endl;
    else
    {
        element = cursor->dataItem;
    }
    return element;
}


//-----------------------------------------------------------

template < class DT >
void List<DT>::showStructure() const
{
    ListNode<DT>* p;   // Iterates through the list

    if (head == nullptr)
        cout << "Empty list" << endl;
    else
    {
        p = head;
        do
        {
            if (p == cursor)
                cout << "[" << p->dataItem << "] ";
            else
                cout << p->dataItem << " ";
            p = p->next;
        } while (p != NULL);
        cout << endl;
    }

}


//-----------------------------------------------------------

// In-lab opertions
template < class DT >
int List<DT>::getLength() const
{
    int sizeCnt=0;
    ListNode<DT>* p;
    p = head;
    do
    {
        if(p->dataItem != NULL)
            sizeCnt++;
        p = p->next;
    } while (p != NULL);
    return sizeCnt;
}

template < class DT >
int List<DT>::getPosition() const
{
    int positionCnt = 0;
    ListNode<DT>* p;
    p = head;
    while (1)
    {
        if (p->dataItem == cursor->dataItem)
        {
            break;
        }       
        positionCnt++;
        p = p->next;
    }

    return positionCnt;
}