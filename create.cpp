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
    cin >> g.vNodeNum >> g.eNodeNum;
    cout << endl << "                " << "\"��������������Ϣ\"" << endl << endl;
    cout << "���������������֣�";

    for (int i = 0; i < g.vNodeNum; ++i) {
        cin >> g.nodeList[i].name;
        g.nodeList[i].firstNode = NULL;
    }
    //��������
    string v1, v2;//����������
    int w;//����֮��ľ���
    cout << "�����붥�� �Լ�Ȩֵ";
    for (int j = 0; j < g.eNodeNum; ++j) {
//        cout << "�������" << j + 1 << "���ߵ����������Լ��ñߵ�Ȩֵ��";
        cin >> v1 >> v2 >> w;
        //�õ������ڵ��λ��
        int index1 = locateNode(g, v1);
        int index2 = locateNode(g, v2);
        if (index1 == -1 || index2 == -1) {
            cout << "û�иõ�ַ,����������";
            j--;
        }
        //���߽�����
        insert(g, w, index1, index2);
    }
}

void insert(ALGraph &g, int w, int index1, int index2) {
    ENode *node1 = new ENode;
    ENode *node2 = new ENode;
    //���õ�һ���ڵ�
    node1->w = w;
    node1->location = index2;//�������ڽڵ�
    node1->nextENode = g.nodeList[index1].firstNode;
    g.nodeList[index1].firstNode = node1;
    //���õڶ����ڵ�
    node2->w = w;
    node2->location = index1;
    node2->nextENode = g.nodeList[index2].firstNode;
    g.nodeList[index2].firstNode = node2;
}

int locateNode(ALGraph g, string nodeName) {
    for (int i = 0; i < g.vNodeNum; ++i) {
        if (nodeName == g.nodeList[i].name) {
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
    a = new double *[g.vNodeNum];
    for (i = 0; i < g.vNodeNum; i++)
        a[i] = new double[g.vNodeNum];

    //��ʼ����������
    for (int k = 0; k < g.vNodeNum; k++)
        for (int l = 0; l < g.vNodeNum; l++)
            if (k == l)
                a[k][l] = 0;
            else
                a[k][l] = INFINITY;

    //����������и�ֵ
    ENode *node = new ENode;
    for (int m = 0; m < g.vNodeNum; m++) {
        for (node = g.nodeList[m].firstNode; node; node = node->nextENode) {
            int i = node->location;
            a[m][i] = node->w;
        }
    }
    if (isprint) {
        //�������鲢���
        for (i = 0; i < g.vNodeNum; i++)
            cout << "\t" << g.nodeList[i].name;
        cout << endl;

        for (i = 0; i < g.vNodeNum; i++) {
            cout << g.nodeList[i].name << "\t";
            for (j = 0; j < g.vNodeNum; j++)
                cout << a[i][j] << "\t";
            cout << endl;
        }
    }
    delete[]node;
}

/**
 * ����·��ͼ
 */
bool visited[MAXNODENUM];//����һ�����鱣��ͼ�Ľڵ��Ƿ������
string node1List[MAXNODENUM];//�����������
int k;
ENode *p = new ENode;

void DFS(ALGraph G, int v) {
    visited[v] = true;
    node1List[k++] = G.nodeList[v].name;

    for (p = G.nodeList[v].firstNode; p; p = p->nextENode)
        if (!visited[p->location]) {
            DFS(G, p->location);
            p = G.nodeList[v].firstNode;
        }
}

void DFSTraverse(ALGraph G) {
    int v;
    for (v = 0; v < G.vNodeNum; v++)
        visited[v] = false;//��ʼ����������Ϊû�б�����
    for (v = 0; v < G.vNodeNum; v++)
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

string node2List[2 * MAXNODENUM];//�洢������·ͼ�Ķ����������

void OutTheTour(ALGraph g, ALGraph &g1) {
    DFSTraverse(g);
    cout << endl;
    int i, j, n = 0;
    bool Is;
    for (i = 0; i < g.vNodeNum - 1; i++) {
        k = 0;
        Is = true;
        while (Is) {
            node2List[n++] = node1List[i + k];
            if (IsEdge(g, node1List[i + k], node1List[i + 1]))//�������֮���б߾�ֱ��������������
                Is = false;
            else
                k--;//���û�оͻ��ݣ�ֱ���ҵ���vex[i+1]�бߵ�
        }
    }
    node2List[n] = node1List[i];//�����һ������Ž�vex������
    //����·��ͼ
    for (i = 0; i <= n; i++)
        visited[i] = false;
    for (i = 0; i < g.vNodeNum; i++)//��ʼ������ͼ
    {
        g1.nodeList[i].name = g.nodeList[i].name;
        g1.nodeList[i].firstNode = NULL;
    }
    g1.vNodeNum = g.vNodeNum;
    g1.eNodeNum = n;
    for (int l = 0; l < n - 1; l++) {
        cout << node2List[l];
        int i = l;
        ENode *node = new ENode;
        int eNodeLocation = locateNode(g1, node2List[i + 1]);
        node->location = eNodeLocation;
        node->w = 5;
        int vNodeLocation = locateNode(g1, node2List[i]);
        node->nextENode = g1.nodeList[vNodeLocation].firstNode;
        g1.nodeList[vNodeLocation].firstNode = node;
    }
//    createGraph2(g, g1, i, j, n);
    cout << "����·��Ϊ��";
    for (i = 0; i <= n; i++)
        cout << node2List[i] << "->";//���������·ͼ
    cout << endl;
}

//void createGraph2(const ALGraph &g, ALGraph &g1, int i, int j, int n) {
//    for (i = 0; i <= n; i++)
//        visited[i] = false;
//    for (i = 0; i < g.vNodeNum; i++)//��ʼ������ͼ
//    {
//        g1.nodeList[i].name = g.nodeList[i].name;
//        g1.nodeList[i].firstNode = NULL;
//    }
//
//    int edgeNum = 0;//��¼������·ͼ�еıߵĸ���
//    for (k = 0; k < n; k++) {
//        i = locateNode(g, node2List[k]);
//        j = locateNode(g, node2List[k + 1]);
//        if (visited[j])//����õ��Ѿ��ڵ�����·ͼ�У���Ѱ�����Ƿ����Ѿ��ڵ�����·ͼ�еĵ��γɻ�·
//        {
//            int m = k + 2;//��������ֱ��ǰ��
//            if (m <= n)//�ж��Ƿ񳬳��洢������·ͼ������
//            {
//                while (visited[locateNode(g, node2List[m])])//ֱ�������µĽڵ�Ϊֹ
//                {
//                    /*�ж�����������ԭ���ľ����ֲ�ͼ���Ƿ��бߣ�����о������������ߣ����߼��������*/
//                    if (IsEdge(g, node2List[k], node2List[m])) {
//                        j = locateNode(g, node2List[m]);
//                        ENode *P = new ENode;
//                        ENode *Q = new ENode;
//                        P->location = j;
//                        P->w = a[i][j];
//
//                        Q = g1.nodeList[i].firstNode;
//                        g1.nodeList[i].firstNode = P;
//                        P->nextENode = Q;
//
//                        edgeNum++;
//                    }
//                    if (++m >= n)//����ڲ��ҵĹ����е�������ĩβ��ǿ���˳�
//                        break;
//                }
//            }
//        } else//���û���ڵ�����·ͼ�о���������
//        {
//            visited[i] = visited[j] = true;
//
//            ENode *P = new ENode;
//            ENode *Q = new ENode;
//            P->location = j;
//            P->w = a[i][j];
//
//            Q = g1.nodeList[i].firstNode;
//            g1.nodeList[i].firstNode = P;
//            P->nextENode = Q;
//
//            edgeNum++;
//        }
//
//    }
//    g1.vNodeNum = g.vNodeNum;//��ֵ������·ͼ�ж���ĸ���
//    g1.eNodeNum = edgeNum;//��ֵ������·ͼ�бߵĸ���
//}
void createGraph2(const ALGraph &g, ALGraph &g1, int i, int j, int n) {

}

/**
 * �һ�·
 */
int TopoSort(ALGraph G1) {
    string *a = new string[G1.vNodeNum];//�����ڻ�·�еĶ����ݴ����ַ�����a��
    int *indegree = new int[G1.vNodeNum];//Ϊ����������鿪�ٿռ�
    int top = 0, base = 0;
    int *S = new int[G1.vNodeNum];//Ϊ����ջ���ٿռ�
    int i = 0;
    for (; i < G1.vNodeNum; i++)//��ʼ�������������
        indegree[i] = 0;
    getInDegree(G1, indegree);//��������Ⱥ������������������
    for (i = 0; i < G1.vNodeNum; i++)
        if (!indegree[i])//����ȼ�Ϊ0�Ķ�����ջ
            S[top++] = i;
    int count = 0;//��¼�Ѿ������������еĶ���ĸ���
    int k;
    ENode *p = new ENode;
    while (top != base)//��ջ�����Ǽ���ѭ��
    {
        k = S[--top];
        a[count++] = G1.nodeList[k].name;
        for (p = G1.nodeList[k].firstNode; p; p = p->nextENode)
            if (!(--indegree[p->location]))//�����ȼ�Ϊ0������ջ
                S[top++] = p->location;
    }
    if (count < G1.vNodeNum) {
        cout << endl << "ͼ���л�·,��·Ϊ��" << endl;
        for (i = 0; i < G1.vNodeNum; i++) {
            for (k = 0; k < count; k++)
                if (G1.nodeList[i].name == a[k])//�������������a�еĶ�����ͬ������ѭ����˵������ѭ����
                    break;
            if (k >= count)
                cout << G1.nodeList[i].name;
        }
        delete[]a;
        delete[]indegree;
        delete[]S;
        return false;
    } else {
        cout << "ͼ��û�л�·" << endl;
        delete[]a;
        delete[]indegree;
        delete[]S;
        return true;
    }

}

void getInDegree(ALGraph g1, int indegree[])//�������������
{
    ENode *p = new ENode;
    for (int i = 0; i < g1.vNodeNum; i++)
        for (p = g1.nodeList[i].firstNode; p; p = p->nextENode)//���������еı�
            indegree[p->location]++;
    delete p;
}

/**
 * ����������֮������·��,����̾���
 */
void ShortestPath(ALGraph G, int path[][MAXNODENUM], double D[][MAXNODENUM])//�����·��
{
    int u, v, w;
    for (v = 0; v < G.vNodeNum; v++)
        for (w = 0; w < G.vNodeNum; w++) {
            D[v][w] = a[v][w];//����̾����ʼ��Ϊ��������֮���Ȩֵ
            if (a[v][w] < INFINITY)
                path[v][w] = v;//�����·����ʼ��Ϊ�����ǰһ���������
        }
    for (u = 0; u < G.vNodeNum; u++)
        for (v = 0; v < G.vNodeNum; v++)
            for (w = 0; w < G.vNodeNum; w++)
                if (D[v][u] + D[u][w] < D[v][w])//����¼���Ľ�㵼�����·������ˣ��͸�������ͬʱ��¼���ӵ�·���ı��
                {
                    D[v][w] = D[v][u] + D[u][w];
                    path[v][w] = u;
                }
}

void MiniDistanse(ALGraph G1, int path[][MAXNODENUM], double D[][MAXNODENUM])//������·��
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

void OutPutShortestPath(ALGraph G, int path[][MAXNODENUM], double D[][MAXNODENUM], int i,
                        int j) {
    if (path[i][j] == i)
        cout << G.nodeList[i].name << "--" << G.nodeList[j].name << endl;//������������·���ϵıߵ����˶���
    else {
        OutPutShortestPath(G, path, D, i, path[i][j]);//�����Ҿ������м�·��
        OutPutShortestPath(G, path, D, path[i][j], j);
    }
}

/**
 *�����·�޽��滮ͼ
 */
