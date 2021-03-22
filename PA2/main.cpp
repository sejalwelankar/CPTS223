#include "AVL.h"

int main()
{
    srand(unsigned(time(NULL)));
    int ascending[50];
    int descending[50];
    int random[50];
    for (int i = 0; i < 50; i++)
    {
        ascending[i] = 2 * i + 1;
        descending[50 - i - 1] = 2 * i + 1;
        random[i] = 2 * i + 1;
    }
    shuffle_array(random, 50);
    AVLTree<int> TreeAscending(ascending[0]);
    AVLTree<int> TreeDescending(descending[0]);
    AVLTree<int> TreeRandom(random[0]);
    for (int i = 1; i < 50; i++)
    {
        TreeAscending.insert(ascending[i]);
        TreeDescending.insert(descending[i]);
        TreeRandom.insert(random[i]);
    }
    cout << "Height of tree with elements inserted in ascending order is : " << TreeAscending.height() << endl;
    cout << "Height of tree with elements inserted in descending order is : " << TreeDescending.height() << endl;
    cout << "Height of tree with elements inserted in random order is : " << TreeRandom.height() << endl;
    cout << "Result of validate for tree with elements inserted in ascending order is : " << TreeAscending.validate() << endl;
    cout << "Result of validate for tree with elements inserted in descending order is : " << TreeDescending.validate() << endl;
    cout << "Result of validate for tree with elements inserted in random order is : " << TreeRandom.validate() << endl;
    cout << "Checking whether odd values from 1 - 100 are present in the three AVL trees" << endl;
    cout << "Number\tTreeAscending\tTreeDescending\tTreeRandom" << endl;
    for (int i = 1; i < 101; i++)
    {
        cout << i << "\t" << TreeAscending.contains(i) << "\t" << TreeDescending.contains(i) << "\t" << TreeRandom.contains(i) << endl;
        if (i % 2 == 1 && (TreeAscending.contains(i) == 0 || TreeDescending.contains(i) == 0 || TreeRandom.contains(i) == 0))
        {
            cout << "My AVL tree implementation is wrong" << endl;
        }

    }

}


