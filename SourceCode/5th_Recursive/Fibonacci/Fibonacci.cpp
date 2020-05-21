/** 
 * author: zzw5005
 * date: 2020/1/5 11:25
*/

#include <iostream>

/**
 * 递归版 斐波那契数列
 * 效率较低，不建议使用
 * @return
 */
unsigned int Fib(unsigned int n){
    if(n < 2){
        return n;
    }else{
        return Fib(n - 1) + Fib(n - 2);
    }
}


/**
 * 迭代(循环)版 斐波那契数列
 * 效率较高，推荐使用
 * @return
 */
unsigned int iterativeFib(unsigned int n){
    if(n < 2){
        return n;
    }else{
        register int i = 2, prev = 0, current = 1, next = 1;
        for(; i <= n; ++i){
            next = prev + current;
            prev = current;
            current = next;
        }

        return next;
    }
}

int main6nb3(){
    unsigned int n = 8;
    int result1 = Fib(n);
    int result2 = iterativeFib(n);

    std::cout << "Fib(" << n << "): " << result1 << std::endl;
    std::cout << "iterativeFib(" << n << "): " << result2 << std::endl;

    return 0;
}



















