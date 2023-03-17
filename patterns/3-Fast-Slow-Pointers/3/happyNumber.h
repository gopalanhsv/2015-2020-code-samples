#ifndef _HAPPY_NUM_H_
#define _HAPPY_NUM_H_

class Number {
public:
    static bool isHappyNumber(unsigned int n);
private:

    static unsigned long sumOfDigitsSquared(unsigned long n);
};

#endif /* _HAPPY_NUM_H_ */
