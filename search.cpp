//
// Created by john on 2016/11/13.
//

#include <iostream>
#include <cstring>
#include "create.h"
#include "search.h"

void sortByPopular(ALGraph g) {
    int a[MAXNODENUM];
    for (int i = 0; i < g.vNodeNum; ++i) {
        a[i] = g.nodeList[i].popularValue;
    }
    quickSort(a, 0, 7);
    cout << "���ܻ�ӭ�ľ�������Ϊ:" << endl;
    for (int j = 0; j < g.vNodeNum; ++j) {
        for (int i = 0; i < g.vNodeNum; ++i) {
            if (g.nodeList[i].popularValue == a[j]) {
                cout << g.nodeList[i].name << "  " << g.nodeList[i].popularValue << endl;
            }
        }
    }
}

void quickSort(int s[], int l, int r) {
    if (l < r) {
        int i = l, j = r, x = s[l];
        while (i < j) {
            while (i < j && s[j] >= x) // ���������ҵ�һ��С��x����
                j--;
            if (i < j)
                s[i++] = s[j];
            while (i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
                i++;
            if (i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quickSort(s, l, i - 1); // �ݹ����
        quickSort(s, i + 1, r);
    }
}

//����
void searchNode(ALGraph g) {
    cout << "�����뾰�������";
    string name;
    cin >> name;
    for (int j = 0; j < g.vNodeNum; ++j) {
        bool exites = g.nodeList[j].name == name;
        if (exites) {
            cout << "�������ϸ��ϢΪ:" << g.nodeList[j].desc << endl;
            cout << "������ܻ�ӭ�̶�Ϊ:" << g.nodeList[j].popularValue;
        }
    }
}

//������ϸ������Ϣ
void inputTheDetail(ALGraph &g, bool isDetail) {
    cout << "�����뾰������� ���� ���ܻ�ӭ�̶�(����������ʾ,����ԽСԽ�ܻ�ӭ)";
    string name, desc;
    int popularValue;
    for (int i = 0; i < g.vNodeNum; ++i) {
        cin >> name >> desc >> popularValue;
        for (int j = 0; j < g.vNodeNum; ++j) {
            bool exites = g.nodeList[j].name == name;
            if (exites) {
                g.nodeList[j].desc = desc;
                g.nodeList[j].popularValue = popularValue;
            }
        }
    }
    for (int k = 0; k < g.vNodeNum; ++k) {
        cout << g.nodeList[k].name << "   " << g.nodeList[k].desc << "�ܻ�ӭ�̶�Ϊ:"
             << g.nodeList[k].popularValue << endl;
    }
    isDetail = true;
}
