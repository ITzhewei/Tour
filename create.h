//
// Created by john on 2016/11/8.
//
#include <string>
#include <list>

using namespace std;
#ifndef TOUR_LIST_H
#define TOUR_LIST_H

#define MAXNODENUM 20 //����ͼ�����ڵ���
#define INFINITY 32767 //����Զ

extern double **a;//����ͼ��ȫ�ֶ������

/**
 * ����ͼ
 */
//�߱���
typedef struct ENode {
    int location;//������λ��
    struct ENode *nextENode;//��һ���ڵ�
    double w;//����֮�����
} ENode;
//����
typedef struct VNode {
    string name;//��������
    string desc;//�������ϸ����
    int popularValue;//�ܻ�ӭ�̶�
    ENode *firstNode;//���еı�
} VNode, NodeList[MAXNODENUM];

//ͼ�ڽӱ�
typedef struct {
    NodeList nodeList;
    int vNodeNum, eNodeNum;
} ALGraph;

//��
typedef struct edge {
    string vNodeName;
    int lowcost;
} Edge[MAXNODENUM];//���帨������


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
void OutputGraph(ALGraph g, bool isprint);
void insert(ALGraph &g, int w, int index1, int index2);
/**
 * ����·��ͼ
 */
//�ݹ����
void DFS(ALGraph G, int v);

//ͼ����ȱ���
void DFSTraverse(ALGraph G);

//�ж�Ҫ�������������֮���Ƿ���ֱ�������ı�
bool IsEdge(ALGraph G, string v1, string v2);

//���·��
void OutTheTour(ALGraph g, ALGraph &g1);

//��������·��ͼ
void createGraph2(const ALGraph &g, ALGraph &g1, int i, int j, int n);

/**
 * �һ�·
 */
int TopoSort(ALGraph G1);//��������

void getInDegree(ALGraph g1, int *indegree);//����ÿ���������ȣ��洢��indegree������
/**
 * ����������֮������·��,����̾���
 */
void ShortestPath(ALGraph G, int path[][MAXNODENUM], double D[][MAXNODENUM]);//�������·��

void OutPutShortestPath(ALGraph G, int path[][MAXNODENUM], double D[][MAXNODENUM], int i,
                        int j);//�����·��
void MiniDistanse(ALGraph G, int path[][MAXNODENUM], double D[][MAXNODENUM]);//������·��
/**
 *�����·�޽��滮ͼ
 */


#endif //TOUR_LIST_H
