#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define MAX_SIZE 100

bool isMatching(char exp[], int n) {
    int top = 0;

    for (int i = 0; i < n; i++) {
        if (exp[i] == '(' ) {
            // 遇到左括号，入栈
            top++;
        }
        else if (exp[i] == ')' ) {
            // 遇到右括号，检查栈顶元素是否匹配
            top--;
            if (top < 0)return false;
        }
        //TODO:限制字符串小于int最大值
    }

    return top == 0;  // 如果栈为空，说明所有括号都匹配
}
typedef struct {
    int a;
    int b;
}test;
typedef struct {
    test* tt;
}test1;
int main() {
    char exp[] = "((a + b) * (c - d))";
    int n = sizeof(exp) / sizeof(exp[0]);

    if (isMatching(exp, n - 1)) {
        printf("括号匹配正确\n");
    }
    else {
        printf("括号匹配错误\n");
    }
    test1 t1= {
        .tt = (&(test){1,1}),
    };
    t1.tt->a = 90;
    printf("test %d", t1.tt->a);
    return 0;
}
