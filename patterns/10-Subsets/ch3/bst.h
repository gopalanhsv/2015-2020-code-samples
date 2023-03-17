#ifndef _BST_H_
#define _BST_H_

// System headers
// Local includes
// Using declarations
// Statics, typedefs, globals

class BST {
public:
    static unsigned long long
        numUniqueTrees(long n);
    static unsigned long long
        numUniqueTreesDPMemoization(long n);
private:
    static unsigned long long
        numUniqueTreesRecursive(long n);
    static unsigned long long
        numUniqueTreesRecursiveDPMemoization(long n);
};

#endif /* _BST_H_ */
