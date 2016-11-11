//
// Created by john on 2016/11/8.
//
#include <string>
#include <list>

using namespace std;
#ifndef TOUR_LIST_H
#define TOUR_LIST_H

#define MAX_VERTEX_NUM 20 //����ͼ�����ڵ���
#define INFINITY 32767 //����Զ

extern double **a;//����ͼ��ȫ�ֶ������

/**
 * ����ͼ
 */
//�߱���
typedef struct ArcNode {
    int adjvex;//������λ��
    struct ArcNode *nextarc;//��һ���ڵ�
    double w;//����֮�����
} ArcNode;
//����
typedef struct VNode {
    string name;//����
    ArcNode *firstarc;//���еı�
} VNode, AdjList[MAX_VERTEX_NUM];
//ͼ�ڽӱ�
typedef struct {
    AdjList adjlist;
    int vexnum, arcnum;
} ALGraph;
//��
typedef struct edge {
    string vex;
    int lowcost;
} Edge[MAX_VERTEX_NUM];//���帨������


/**
 * ����ͼ
 */
//�˵�
void showMenu();

//����
bool IsZeroOrOne(int n);

void CreateGraph(ALGraph &g);

//��λ���
int locateNode(ALGraph g, string nodeName);

/**
 * ���ͼ
 */
void OutputGraph(ALGraph g);

/**
 * ����·��ͼ
 */
void DFS(ALGraph G, int v);//�ݹ����

void DFSTraverse(ALGraph G);//ͼ����ȱ���

bool IsEdge(ALGraph G, string v1, string v2);//�ж�Ҫ�������������֮���Ƿ���ֱ�������ı�

void CreateTourSortGraph(ALGraph G, ALGraph G1);

#endif //TOUR_LIST_H
