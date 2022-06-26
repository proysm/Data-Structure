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

//-----------------------------------------------------------------

template < class DT, class KF >    // DT : tree data item
class BSTree                       // KF : key field
{
public:

    // Constructor
    BSTree();

    // Destructor
    ~BSTree();

    // Binary search tree manipulation operations
    bool isValid();

private:

    // Recursive partners of the public member functions -- insert
    // prototypes of these functions here.
    void cutRightmost(BSTreeNode<DT, KF>*& r, BSTreeNode<DT, KF>*& delPtr);
    void cutLeftmost(BSTreeNode<DT, KF>*& r, BSTreeNode<DT, KF>*& delPtr);
    bool checkValid(BSTreeNode<DT, KF>* p, KF temp1, KF temp2);
    
    // Data member
    BSTreeNode<DT, KF>* root;   // Pointer to the root node

};
