#ifndef PA2_AVL_H
#define PA2_AVL_H

#include "Header.h"
#include "AVLNode.h"
//AVL tree example given in class refrenced

template <class T>
class AVLTree
{
private :
    AVLNode <T>* root;
    void HelperInsert(T new_data, AVLNode<T>* & ptr)
    {
        if (ptr == nullptr)
        {
            ptr = new AVLNode <T>(new_data);
        }

        else if (ptr->data > new_data)
        {

            HelperInsert(new_data, ptr->left);
            if (Heighthelper(ptr->left) - Heighthelper(ptr->right) == 2)
            {
                if (new_data < ptr->left->data)
                {
                    rotatewithLeftChild(ptr);
                }
                else
                {
                    doublewithLeftChild(ptr);
                }
            }
        }
        else if(ptr->data < new_data )
        {

            HelperInsert(new_data, ptr->right);
            if (Heighthelper(ptr->right) - Heighthelper(ptr->left) == 2)
            {
                if (new_data > ptr->right->data)
                {
                    rotatewithRightChild(ptr);
                }
                else
                {
                    doublewithRightChild(ptr);
                }
            }

        }

        else
        {
            //do nothing
        }

    }
    int Heighthelper(AVLNode<T>* ptr)
    {

        if (!ptr)
        {
            return -1;
        }
        else
        {
            ptr->height =  1 + max(Heighthelper(ptr->left), Heighthelper(ptr->right));
            return ptr-> height;
        }

    }
    int containsHelper(T check_data, AVLNode<T>* ptr)
    {
        if (ptr != nullptr)
        {
            if (check_data > ptr->data)
            {
                return containsHelper(check_data, ptr->right);
            }
            else if (check_data < ptr->data)
            {
                return containsHelper(check_data, ptr->left);
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 0;
        }
    }
    void rotatewithLeftChild(AVLNode<T> * & ptr)
    {
        AVLNode <T> *temp = ptr->left;
        ptr->left = temp->right;
        temp->right = ptr;
        ptr->height = Heighthelper(ptr);
        temp->height = max(Heighthelper(temp->left), ptr->height) + 1;
        ptr = temp;

    }
    void rotatewithRightChild(AVLNode<T> * & ptr)
    {
        AVLNode<T>* temp = ptr->right;
        ptr->right = temp->left;
        temp->left = ptr;
        ptr->height = Heighthelper(ptr);
        temp->height = max(Heighthelper(temp->right), ptr->height) + 1;
        ptr = temp;
    }
    void doublewithLeftChild(AVLNode <T>*& ptr)
    {
        rotatewithRightChild(ptr->left);
        rotatewithLeftChild(ptr);
    }
    void doublewithRightChild(AVLNode <T>*& ptr)
    {
        rotatewithLeftChild(ptr->right);
        rotatewithRightChild(ptr);
    }

public:
    //constructor
    AVLTree(T new_data)
    {
        root = new AVLNode <T> (new_data) ;
        root->height = Heighthelper(root);
    }
    // destructor
    ~AVLTree()
    {
        cout << endl << "Destructor called";
        delete root;
    }
    /* Code written with refrence of code given in class */
    void insert(T new_data)
    {
        HelperInsert(new_data, root);
        root->height = Heighthelper(root);
    }
    //returns height of tree
    int height()
    {
        return root->height;
    }
    //checks whether a given value is in tree. Returns 1 if it is in the tree 0 if it is not
    int contains(T check_data)
    {
        return containsHelper(check_data, root);

    }
    // checks wheter tree is balanced returns 1 if yes 0 if no
    int validate()
    {
        int k = root->left->height - root->right->height;
        int height_diff = abs(k);
        if (height_diff > 1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }



};


#endif //PA2_AVL_H
