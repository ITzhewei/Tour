#include <iostream>
#include <cstdlib>
#include "create.h"
#include "search.h"
#include "carGuild.h"


int isCreate(bool Is, int n);

void OutRoadPlan(ALGraph g, string basic_string);

int main() {

    bool createdG = true;//����
    int n;//����
    ALGraph g, g1;//ͼ

    bool IsDetail = false;

    //path�����洢������·����D�����洢��������֮��ľ���
    int path[MAXNODENUM][MAXNODENUM];
    double D[MAXNODENUM][MAXNODENUM];

    showMenu();//�˵�

    while (true) {
        cout << endl << endl << endl;
        cout << "��������Ҫѡ��Ĳ˵��";
        cin >> n;
        //�ж��Ƿ��Ѿ�������ͼ
        n = isCreate(createdG, n);
        createdG = false;
        switch (n) {
            case 0:
                exit(0);
            case 1:
                CreateGraph(g);
                OutputGraph(g, false);//��������
                break;
            case 2:
                OutputGraph(g, true);//�������
                break;
            case 3:
                OutTheTour(g, g1);//�������·��ͼ
                break;
            case 4:
                TopoSort(g1);//�������·�еĻ�·
                break;
            case 5:
                MiniDistanse(g, path, D);//�����·��
                break;
            case 6:
                OutRoadPlan(g, g.nodeList[0].name);//�����·�޽��滮ͼ
                break;
            case 7:
                inputTheDetail(g, IsDetail);//���뾰����ϸ��Ϣ
                break;
            case 8:
                searchNode(g);//����ĳ������ľ�����Ϣ
                break;
            case 9:
                sortByPopular(g);//�������������
                break;
            case 10:
                carGuild();//ͣ��������������¼��Ϣ
                break;
            default:
                exit(0);
        }
    }

}

void OutRoadPlan(ALGraph g, string basic_string) {
    Edge edge;
    int i = locateNode(g, basic_string);

}

int isCreate(bool Is, int n) {
    while (Is && !IsZeroOrOne(n)) {
        cout << "�������ܽ��д˲��������ȴ���ͼ��" << endl;
        cin >> n;
    }

    return n;
}













