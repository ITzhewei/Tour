//
// Created by john on 2016/11/13.
//

#include <iostream>
#include "create.h"
#include "search.h"

void sortByPopular(ALGraph g) {
    int a[MAX_VERTEX_NUM];
    for (int i = 0; i < g.vexnum; ++i) {
        a[i] = g.adjlist[i].popularValue;
    }
    quickSort(a, 0, 7);
    cout << "���ܻ�ӭ�ľ�������Ϊ:" << endl;
    for (int j = 0; j < g.vexnum; ++j) {
        for (int i = 0; i < g.vexnum; ++i) {
            if (g.adjlist[i].popularValue == a[j]) {
                cout << g.adjlist[i].name <<"  "<< g.adjlist[i].popularValue << endl;
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
    for (int j = 0; j < g.vexnum; ++j) {
        bool exites = g.adjlist[j].name == name;
        if (exites) {
            cout << "�������ϸ��ϢΪ:" << g.adjlist[j].desc << endl;
            cout << "������ܻ�ӭ�̶�Ϊ:" << g.adjlist[j].popularValue;
        }
    }
}

//������ϸ������Ϣ
void inputTheDetail(ALGraph &g, bool isDetail) {
    cout << "�����뾰������� ���� ���ܻ�ӭ�̶�(����������ʾ,����Խ��Խ�ܻ�ӭ)";
    string name, desc;
    int popularValue;
    for (int i = 0; i < g.vexnum; ++i) {
        cin >> name >> desc >> popularValue;
        for (int j = 0; j < g.vexnum; ++j) {
            bool exites = g.adjlist[j].name == name;
            if (exites) {
                g.adjlist[j].desc = desc;
                g.adjlist[j].popularValue = popularValue;
            }
        }
    }
    for (int k = 0; k < g.vexnum; ++k) {
        cout << g.adjlist[k].name << "   " << g.adjlist[k].desc << "�ܻ�ӭ�̶�Ϊ:"
             << g.adjlist[k].popularValue << endl;
    }
    isDetail = true;
}
