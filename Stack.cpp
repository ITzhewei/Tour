//
// Created by john on 2016/11/14.
//

#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;


void push(Stack *stack, StackNode *node, int &count) {
    //��Ӵ���
//    if (count >= MAXCAR) {
//        cout << "��ǰ�����Ѿ�����,�����ŶӵȺ�";
//        QueueNode *queueNode = new QueueNode;
//        queueNode->data = node->data;
//        delete (node);
//        enQueue(queue, queueNode);
//        return;
//    }
    count++;
    node->link = stack->top;
    stack->top = node;
}


StackNode *pop(Stack *stack, int &count) {
    count--;
    stack->top = stack->top->link;
//    if (queue->front->data->number) {
//        QueueNode *pNode = deQueue(queue);
//        StackNode *node = new StackNode;
//        node->data = pNode->data;
//        delete (pNode);
//        push(stack, node, count);
//        if (count <= 5) {
//            cout << "���ƺ�Ϊ" << node->data->number << "�ĳ��Ѿ���ͣ����" << count << "�ų���" << endl;
//        }
//    }
    return stack->top;
}


void push2(Stack *stack, StackNode *node, int &count) {
    node->link = stack->top;
    stack->top = node;
}

StackNode *pop2(Stack *stack, int &count) {
    stack->top = stack->top->link;
    return stack->top;
}
