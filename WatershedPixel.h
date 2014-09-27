
/*
* (WatershedPixel��)���ݻҶ�ֵ��ͼ�����ؽ�������
*/
#ifndef WATERSHEDPIXEL_H
#define WATERSHEDPIXEL_H

#include <vector>

class WatershedPixel {
	static const int INIT = -1;	// ������ʼ��ͼ��
	static const int MASK = -2;	// ָʾ�����ص㽫������ÿ���㼶�ĳ�ʼֵ��
	static const int WSHED = 0;	// �������ص�����ĳ����ˮ��
	static const int FICTITIOUS = -3;	// �������ص�

	int x;	// ���ص�x����
	int y;	// ���ص�y����
	char height;	// ���ص�ĻҶ�ֵ
	int label;	// ���ڷ�ˮ���û�㷨�ı�ǩ
	int dist;	// ��������ʱ�õ��ľ���

	std::vector<WatershedPixel*> neighbours;	// ������������

public:
	WatershedPixel(int x, int y, char height) { // ���ص㹹�캯��
		this->x = x;
		this->y = y;
		this->height = height;
		label = INIT;
		dist = 0;
		neighbours.reserve(8);	//�����ڴ����ڴ洢8��ͨ����������
	}
	WatershedPixel() { label = FICTITIOUS; } // �������ص㹹�캯��

	void addNeighbour(WatershedPixel* neighbour) { // �����������
		neighbours.push_back(neighbour);
	}
	std::vector<WatershedPixel*>& getNeighbours() { // ��ȡ��������
		return neighbours; 
	}

	/* ��ȡ���ػҶ�ֵ������*/
	char getHeight() const { return height; } 
	int getIntHeight() const { return (int) height&0xff; } //����ת��ʱ����&0xff�ٳ���
	int getX() const {	return x; }
    int getY() const {	return y; }

	/* ���úͻ�ȡ��ǩ */
    void setLabel(int label) { this->label = label; }
    void setLabelToINIT() { label = INIT; }
    void setLabelToMASK() { label = MASK; }
    void setLabelToWSHED() { label = WSHED; }
    int getLabel() {   return label; }

	/* �жϵ�ǰ��ǩ״̬ */
    bool isLabelINIT() { return label == INIT; }
    bool isLabelMASK() { return label == MASK; }
    bool isLabelWSHED() { return label == WSHED; }

	/* ���úͻ�ȡ���� */
    void setDistance(int distance) { dist = distance; }
    int getDistance() { return dist; }

	/* �ж��Ƿ�Ϊ�������� */
    bool isFICTITIOUS() { return label == FICTITIOUS; }

	/* �ж��Ƿ�������������Ϊ��ˮ�루���ڻ������ķ�ˮ�룩 */
    bool allNeighboursAreWSHED() {
        for (unsigned i = 0 ; i < neighbours.size() ; i++) {
            WatershedPixel* r =  neighbours.at(i);
            if ( !r->isLabelWSHED() ) return false;
        }
        return true;
    }
};

#endif