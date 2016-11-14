//
// Created by john on 2016/11/8.
//
#include <iostream>
#include "create.h"

/**
 * ����ͼ
 */
void showMenu() {
    cout << "                  ";
    cout << "=====================" << endl;
    cout << "                        ";
    cout << "��ӭʹ�þ���������Ϣ����ϵͳ" << endl;
    cout << "                        ";
    cout << "  **��ѡ��˵�**" << endl;
    cout << "                  ";
    cout << "=====================" << endl;
    cout << "                  ";
    cout << "0���˳�ϵͳ��" << endl;
    cout << "                  ";
    cout << "1��������������ֲ�ͼ��" << endl;
    cout << "                  ";
    cout << "2�������������ֲ�ͼ��" << endl;
    cout << "                  ";
    cout << "3�����������·ͼ��" << endl;
    cout << "                  ";
    cout << "4�����������·ͼ�еĻ�·��" << endl;
    cout << "                  ";
    cout << "5�����������������·������̾��롣" << endl;
    cout << "                  ";
    cout << "6�������·�޽��滮ͼ��" << endl;
    cout << "                  ";
    cout << "7�����뾰����ϸ��Ϣ��" << endl;
    cout << "                  ";
    cout << "8������ĳ������ľ�����Ϣ��" << endl;
    cout << "                  ";
    cout << "9���Ѿ��㰴���ܻ�ӭ�̶Ƚ�������" << endl;
    cout << "                  ";
    cout << "10��ͣ��������������¼��Ϣ��" << endl;
    cout << "                  ";
}

bool IsZeroOrOne(int n) {
    if (n == 0 || n == 1)
        return true;
    return false;
}

void CreateGraph(ALGraph &g) {
    cout << "�����붥�����ͱ�����";
    cin >> g.vexnum >> g.arcnum;
    cout << endl << "                " << "\"��������������Ϣ\"" << endl << endl;
    cout << "���������������֣�";

    for (int i = 0; i < g.vexnum; ++i) {
        cin >> g.adjlist[i].name;
        g.adjlist[i].firstarc = NULL;
    }
    //��������
    string v1, v2;//����������
    int w;//����֮��ľ���
    cout << "�����붥�� �Լ�Ȩֵ";
    for (int j = 0; j < g.arcnum; ++j) {
//        cout << "�������" << j + 1 << "���ߵ����������Լ��ñߵ�Ȩֵ��";
        cin >> v1 >> v2 >> w;
        //�õ������ڵ��λ��
        int index1 = locateNode(g, v1);
        int index2 = locateNode(g, v2);
        if (index1 == -1 || index2 == -1) {
            cout << "û�иõ�ַ,����������";
            j--;
        }
        ArcNode *node1 = new ArcNode;
        ArcNode *node2 = new ArcNode;
        //���õ�һ���ڵ�

        node1->w = w;
        node1->adjvex = index2;//�������ڽڵ�
        node1->nextarc = g.adjlist[index1].firstarc;
        g.adjlist[index1].firstarc = node1;
        //���õڶ����ڵ�
        node2->w = w;
        node2->adjvex = index1;
        node2->nextarc = g.adjlist[index2].firstarc;
        g.adjlist[index2].firstarc = node2;

    }
}

int locateNode(ALGraph g, string nodeName) {
    for (int i = 0; i < g.vexnum; ++i) {
        if (nodeName == g.adjlist[i].name) {
            return i;
        }
    }
    return -1;//��λʧ��
}

/**
 * ���Ϊ����ͼ
 */

double **a;

void OutputGraph(ALGraph g, bool isprint) {
    int i, j;
    //���ڽӾ����������ռ�
    a = new double *[g.vexnum];
    for (i = 0; i < g.vexnum; i++)
        a[i] = new double[g.vexnum];

    //��ʼ����������
    for (int k = 0; k < g.vexnum; k++)
        for (int l = 0; l < g.vexnum; l++)
            if (k == l)
                a[k][l] = 0;
            else
                a[k][l] = INFINITY;

    //����������и�ֵ
    ArcNode *node = new ArcNode;
    for (int m = 0; m < g.vexnum; m++) {
        for (node = g.adjlist[m].firstarc; node; node = node->nextarc) {
            int i = node->adjvex;
            a[m][i] = node->w;
        }
    }
    if (isprint) {
        //�������鲢���
        for (i = 0; i < g.vexnum; i++)
            cout << "\t" << g.adjlist[i].name;
        cout << endl;
        for (i = 0; i < g.vexnum; i++) {
            cout << g.adjlist[i].name << "\t";
            for (j = 0; j < g.vexnum; j++)
                cout << a[i][j] << "\t";
            cout << endl;
        }
    }
    delete[]node;
}

/**
 * ����·��ͼ
 */
bool visited[MAX_VERTEX_NUM];//����һ�����鱣��ͼ�Ľڵ��Ƿ������
string vex[MAX_VERTEX_NUM];//�����������
int k;
ArcNode *p = new ArcNode;

void DFS(ALGraph G, int v) {
    visited[v] = true;
    vex[k++] = G.adjlist[v].name;

    for (p = G.adjlist[v].firstarc; p; p = p->nextarc)
        if (!visited[p->adjvex]) {
            DFS(G, p->adjvex);
            p = G.adjlist[v].firstarc;
        }
}

void DFSTraverse(ALGraph G) {
    int v;
    for (v = 0; v < G.vexnum; v++)
        visited[v] = false;//��ʼ����������Ϊû�б�����
    for (v = 0; v < G.vexnum; v++)
        if (!visited[v])//���û�б����ʾͶ������������ȱ���
            DFS(G, v);
}

bool IsEdge(ALGraph G, string v1, string v2)//�ж���������֮���Ƿ��б�
{
    int i = locateNode(G, v1);
    int j = locateNode(G, v2);
    if (a[i][j] < INFINITY)//�������������֮���б߾ͷ���Ϊ�棬���򷵻ؼ�
        return true;
    return false;
}

string vex1[2 * MAX_VERTEX_NUM];//�洢������·ͼ�Ķ����������
void CreateTourSortGraph(ALGraph G, ALGraph G1) {
    DFSTraverse(G);
    cout << endl;
    int i, j, n = 0;
    bool Is;
    for (i = 0; i < G.vexnum - 1; i++) {
        k = 0;
        Is = true;
        while (Is) {
            vex1[n++] = vex[i + k];
            if (IsEdge(G, vex[i + k], vex[i + 1]))//�������֮���б߾�ֱ��������������
                Is = false;
            else
                k--;//���û�оͻ��ݣ�ֱ���ҵ���vex[i+1]�бߵ�
        }
    }
    vex1[n] = vex[i];//�����һ������Ž�vex������
    for (i = 0; i <= n; i++)
        visited[i] = false;
    for (i = 0; i < G.vexnum; i++)//��ʼ������ͼ
    {
        G1.adjlist[i].name = G.adjlist[i].name;
        G1.adjlist[i].firstarc = NULL;
    }

    int arcnum = 0;//��¼������·ͼ�еıߵĸ���
    for (k = 0; k < n; k++) {
        i = locateNode(G, vex1[k]);
        j = locateNode(G, vex1[k + 1]);
        if (visited[j])//����õ��Ѿ��ڵ�����·ͼ�У���Ѱ�����Ƿ����Ѿ��ڵ�����·ͼ�еĵ��γɻ�·
        {
            int m = k + 2;//��������ֱ��ǰ��
            if (m <= n)//�ж��Ƿ񳬳��洢������·ͼ������
            {
                while (visited[locateNode(G, vex1[m])])//ֱ�������µĽڵ�Ϊֹ
                {
                    /*�ж�����������ԭ���ľ����ֲ�ͼ���Ƿ��бߣ�����о������������ߣ����߼��������*/
                    if (IsEdge(G, vex1[k], vex1[m])) {
                        j = locateNode(G, vex1[m]);
                        ArcNode *P = new ArcNode;
                        ArcNode *Q = new ArcNode;
                        P->adjvex = j;
                        P->w = a[i][j];

                        Q = G1.adjlist[i].firstarc;
                        G1.adjlist[i].firstarc = P;
                        P->nextarc = Q;

                        arcnum++;
                    }
                    if (++m >= n)//����ڲ��ҵĹ����е�������ĩβ��ǿ���˳�
                        break;
                }
            }
        } else//���û���ڵ�����·ͼ�о���������
        {
            visited[i] = visited[j] = true;

            ArcNode *P = new ArcNode;
            ArcNode *Q = new ArcNode;
            P->adjvex = j;
            P->w = a[i][j];

            Q = G1.adjlist[i].firstarc;
            G1.adjlist[i].firstarc = P;
            P->nextarc = Q;

            arcnum++;
        }

    }
    G1.vexnum = G.vexnum;//��ֵ������·ͼ�ж���ĸ���
    G1.arcnum = arcnum;//��ֵ������·ͼ�бߵĸ���
    cout << "����·��Ϊ��";
    for (i = 0; i <= n; i++)
        cout << vex1[i] << "->";//���������·ͼ
    cout << endl;
}

/**
 * �һ�·
 */


/**
 * ����������֮������·��,����̾���
 */
void ShortestPath(ALGraph G, int path[][MAX_VERTEX_NUM], double D[][MAX_VERTEX_NUM])//�����·��
{
    int u, v, w;
    for (v = 0; v < G.vexnum; v++)
        for (w = 0; w < G.vexnum; w++) {
            D[v][w] = a[v][w];//����̾����ʼ��Ϊ��������֮���Ȩֵ
            if (a[v][w] < INFINITY)
                path[v][w] = v;//�����·����ʼ��Ϊ�����ǰһ���������
        }
    for (u = 0; u < G.vexnum; u++)
        for (v = 0; v < G.vexnum; v++)
            for (w = 0; w < G.vexnum; w++)
                if (D[v][u] + D[u][w] < D[v][w])//����¼���Ľ�㵼�����·������ˣ��͸�������ͬʱ��¼���ӵ�·���ı��
                {
                    D[v][w] = D[v][u] + D[u][w];
                    path[v][w] = u;
                }
}

void MiniDistanse(ALGraph G1, int path[][MAX_VERTEX_NUM], double D[][MAX_VERTEX_NUM])//������·��
{
    ShortestPath(G1, path, D);
    string A, B;
    cout << "������Ҫ��ѯ�����������������ƣ�";
    cin >> A >> B;
    int i = locateNode(G1, A);
    int j = locateNode(G1, B);
    cout << "���·��Ϊ��";
    OutPutShortestPath(G1, path, D, i, j);
    cout << "��̾���Ϊ��" << D[i][j] << endl;
}

void OutPutShortestPath(ALGraph G, int path[][MAX_VERTEX_NUM], double D[][MAX_VERTEX_NUM], int i,
                        int j) {
    if (path[i][j] == i)
        cout << G.adjlist[i].name << "--" << G.adjlist[j].name << endl;//������������·���ϵıߵ����˶���
    else {
        OutPutShortestPath(G, path, D, i, path[i][j]);//�����Ҿ������м�·��
        OutPutShortestPath(G, path, D, path[i][j], j);
    }
}
