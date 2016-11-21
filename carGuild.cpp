//
// Created by john on 2016/11/13.
//
#include <iostream>
#include <cstdlib>
#include "carGuild.h"
#include "Stack.h"
#include "Queue.h"


using namespace std;

void carGuild() {
    showMenu2();
}


Stack *stack = new Stack;
Stack *stack2 = new Stack;
Queue *queue = new Queue;
int count = 0;
int count2 = 0;

void showMenu2() {
    cout << "       *** ͣ����������� ***   " << endl;
    cout << "================================" << endl;
    cout << "**                               " << endl;
    cout << "**   1--- ���������� 2--- ����������  " << endl;
    cout << "**                               " << endl;
    cout << "**     3 --- �˳� ����            " << endl;
    cout << "**                                " << endl;
    cout << "================================  " << endl;

    while (true) {
        cout << " ��ѡ�� <1 2 3 > : " << endl;
        int in;
        cin >> in;
        switch (in) {
            case 1:
                inCar();
                break;
            case 2:
                outCar();
                break;
            case 3:
                exit(0);
            default:
                exit(0);
        }
    }
}

void outCar() {
    int card;
    int out_time;
    cout << "�����복�ƺ�" << "������ȥ��ʱ��";
    cin >> card >> out_time;
    //��ջ����
    StackNode *node;
    for (int i = 0; i < MAXCAR; i++) {
        node = stack->top;
        pop(stack, count);
        push2(stack2, node, count2);
        if (node->data->number == card) {
            int i = out_time - node->data->ar_time;
            cout << "��Ӧ���Ͻ���Ǯ����(ÿСʱ1��Ǯ):" << i << endl;
            pop2(stack2, count2);
            for (int i = 0; i < count2; i++) {
                push(stack, node, count);
            }
            //���Ӵ���
            if (queue->front != NULL) {
                QueueNode *pNode = deQueue(queue);
                node->data = pNode->data;
                push(stack, node, count);
                cout << "�Ŷ��е�һ����,���ƺ�Ϊ" << node->data->number << "�ĳ�����ͣ����" << endl;
            }
            delete[]node;
            return;
        }
    }

}

void inCar() {
    int card;
    int in_time;
    cout << "�����복�ƺ�" << "������ʱ��Ϊ:";
    cin >> card >> in_time;
    //��ջ����
    zanInode *inode = new zanInode;
    inode->ar_time = in_time;
    inode->number = card;
    if (count < MAXCAR) {
        StackNode *node = new StackNode;
        node->data = inode;
        push(stack, node, count);
        if (count <= MAXCAR) {
            cout << "���ĳ��Ѿ���ͣ����" << count << "�ų���" << endl;
        }
    } else {
        //��Ӵ���
        QueueNode *node = new QueueNode;
        node->data = inode;
        enQueue(queue, node);
        cout << "�����Ѿ�����,���ŶӵȺ�" << endl;
    }
    return;
}