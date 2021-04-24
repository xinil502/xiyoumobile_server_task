#define MAXSIZE 1600

typedef struct {
    int* data;
    int top;
} MinStack;


/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* stack;
    stack = (MinStack*)malloc(sizeof(MinStack));
    stack->data = (int*)malloc(MAXSIZE * sizeof(int));
    stack->top = -1;
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    if (obj->top == MAXSIZE - 1) {//如果栈满，就返回空

    }
    else if (obj->top == -1) {//如果栈空，直接进栈,每次入栈两个元素，一个是入栈元素本身，一个是当前栈元素的最小值
        obj->top++;
        obj->data[obj->top] = val;
        obj->top++;
        obj->data[obj->top] = val;
    }
    else {//如果栈不空，就要与栈顶元素作比较
        int temp = obj->data[obj->top];//先记录此时栈顶元素
        obj->top++;//再将要压入栈的元素进栈
        obj->data[obj->top] = val;
        if (temp < val) {//如果原来栈顶元素小于要压栈的元素
            obj->top++;
            obj->data[obj->top] = temp;//就把它放在栈顶
        }
        else {//否则就把要压栈的元素放在栈顶
            obj->top++;
            obj->data[obj->top] = val;
        }
    }

}

void minStackPop(MinStack* obj) {
    if (obj->top == -1) {//如果是空栈

    }
    else {//入栈是两个入，出栈也是两个出
        obj->top--;
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    if (obj->top == -1) {
        return -1;
    }
    return obj->data[obj->top - 1];
}

int minStackGetMin(MinStack* obj) {
    return obj->data[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    obj->data = NULL;
    free(obj);
    obj = NULL;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/