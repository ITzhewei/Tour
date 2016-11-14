#include <iostream>
#include <cstdlib>
#include "create.h"
#include "search.h"
#include "carGuild.h"


int main() {

    bool Is = true;//����
    int n;//����
    ALGraph G, G1;//ͼ

    bool IsDetail = false;

    //path�����洢������·����D�����洢��������֮��ľ���
    int path[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    double D[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

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
                OutputGraph(G, false);//��������
                break;
            case 2:
                OutputGraph(G, true);//�������
                break;
            case 3:
                CreateTourSortGraph(G, G1);
                break;
//            case 4:
//                TopoSort(G1);
//                break;
            case 5:
                MiniDistanse(G, path, D);
                break;
//            case 6:
//                MiniSpanTree(G, G.adjlist[0].name);
//                break;
            case 7:
                inputTheDetail(G, IsDetail);
                break;
            case 8:
                searchNode(G);
                break;
            case 9:
                sortByPopular(G);
                break;
            case 10:
                carGuild();
                break;
            default:
                exit(0);
        }
    }

}













