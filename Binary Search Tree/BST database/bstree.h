//--------------------------------------------------------------------
//
//  Laboratory 11                                          bstree.h
//
//  Class declarations for the linked implementation of the
//  Binary Search Tree ADT -- including the recursive partners of
//  the public member functions
//
//--------------------------------------------------------------------

template < class DT, class KF >   // Forward dec. of the BSTree class
class BSTree;

template < class DT, class KF >
class BSTreeNode                  // Facilitator for the BSTree class
{
private:

    // Constructor
    BSTreeNode(const DT& nodeDataItem,
        BSTreeNode* leftPtr, BSTreeNode* rightPtr);

    // Data members
    DT dataItem;         // Binary search tree data item
    BSTreeNode* left,    // Pointer to the left child
        * right;   // Pointer to the right child

    friend class BSTree<DT, KF>;
};

//--------------------------------------------------------------------

template < class DT, class KF >    // DT : tree data item
class BSTree                       // KF : key field
{
public:

    // Constructor
    BSTree();

    // Destructor
    ~BSTree();

    // Binary search tree manipulation operations
    void insert(const DT& newDataItem);         // Insert data item
    bool retrieve(KF searchKey, DT& searchDataItem) const;   // Retrieve data item
    bool remove(KF deleteKey);                  // Remove data item
    void writeKeys() const;                      // Output keys
    void clear();                                // Clear tree

    // Binary search tree status operations
    bool isEmpty() const;                           // Tree is empty
    bool isFull() const;                            // Tree is full

    // Output the tree structure -- used in testing/debugging
    void showStructure() const;

    // In-lab operations
    void writeLessThan(KF searchKey) const;        // Output keys
                                                  //   < searchKey

private:

    // Recursive partners of the public member functions -- insert
    // prototypes of these functions here.
    void insertSub(BSTreeNode<DT, KF>*& p, const DT& newDataItem);
    bool retrieveSub(BSTreeNode<DT, KF>* p, KF searchKey, DT& searchDataItem) const;
    bool removeSub(BSTreeNode<DT, KF>*& p, KF deleteKey);
    void cutRightmost(BSTreeNode<DT, KF>*& r, BSTreeNode<DT, KF>*& delPtr);
    void writeKeysSub(BSTreeNode<DT, KF>* p) const;
    void clearSub(BSTreeNode<DT, KF>* p);
    void showSub(BSTreeNode<DT, KF>* p, int level) const;

    // In-lab operations
    void writeLTSub(BSTreeNode <DT, KF>* p, const KF searchKey) const;

    // Data member
    BSTreeNode<DT, KF>* root;   // Pointer to the root node
};
