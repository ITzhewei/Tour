#include <iostream>
#include <cstdlib>
#include "create.h"



int main() {

    bool Is = true;//����
    int n;//����
    ALGraph G,G1;//ͼ

    showMenu();//�˵�

    while (true) {
        cout << endl << endl << endl;
        cout << "��������Ҫѡ��Ĳ˵��";
        cin >> n;

        while (Is && !IsZeroOrOne(n)) {
            cout << "�������ܽ��д˲��������ȴ���ͼ��" << endl;
            cin >> n;
        }
        Is = false;

        switch (n) {
            case 0:
                exit(0);
            case 1:
                CreateGraph(G);
                break;
            case 2:
                OutputGraph(G);
                break;
            case 3:
                CreateTourSortGraph(G, G1);
                break;
//            case 4:
//                TopoSort(G1);
//                break;
//            case 5:
//                MiniDistanse(G, path, D);
//                break;
//            case 6:
//                MiniSpanTree(G, G.adjlist[0].name);
//                break;
            default:
                exit(0);
        }
    }

}










