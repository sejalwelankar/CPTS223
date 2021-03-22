//
// Created by seal on 3/21/21.
//

#ifndef PA2_AVLNODE_H
#define PA2_AVLNODE_H
template <class T>
class AVLNode {
    void deleteHelper(AVLNode<T>* ptr)
    {
        if(ptr == nullptr)
        {
            return;
        }
        else
        {
            deleteHelper(ptr->left);
            deleteHelper(ptr->right);
            delete ptr;
        }
    }
public:
    T data;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(T new_data)
    {
        left = nullptr;
        right = nullptr;
        height = 0;
        data = new_data;
    }
    ~AVLNode()
    {

        //deleteHelper(this);
    }


};
#endif //PA2_AVLNODE_H
