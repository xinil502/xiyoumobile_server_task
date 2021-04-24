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
    if (obj->top == MAXSIZE - 1) {//���ջ�����ͷ��ؿ�

    }
    else if (obj->top == -1) {//���ջ�գ�ֱ�ӽ�ջ,ÿ����ջ����Ԫ�أ�һ������ջԪ�ر���һ���ǵ�ǰջԪ�ص���Сֵ
        obj->top++;
        obj->data[obj->top] = val;
        obj->top++;
        obj->data[obj->top] = val;
    }
    else {//���ջ���գ���Ҫ��ջ��Ԫ�����Ƚ�
        int temp = obj->data[obj->top];//�ȼ�¼��ʱջ��Ԫ��
        obj->top++;//�ٽ�Ҫѹ��ջ��Ԫ�ؽ�ջ
        obj->data[obj->top] = val;
        if (temp < val) {//���ԭ��ջ��Ԫ��С��Ҫѹջ��Ԫ��
            obj->top++;
            obj->data[obj->top] = temp;//�Ͱ�������ջ��
        }
        else {//����Ͱ�Ҫѹջ��Ԫ�ط���ջ��
            obj->top++;
            obj->data[obj->top] = val;
        }
    }

}

void minStackPop(MinStack* obj) {
    if (obj->top == -1) {//����ǿ�ջ

    }
    else {//��ջ�������룬��ջҲ��������
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