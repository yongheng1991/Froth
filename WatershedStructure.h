
/*
*  (WatershedStructure��)���ڴ洢���ص�WatershedPixel
*   �����ɸ����ص����������
*/
#ifndef WATERSHEDSTRUCTURE_H
#define WATERSHEDSTRUCTURE_H

#include <algorithm>
#include "WatershedPixel.h"


class WatershedStructure {
    std::vector<WatershedPixel*> watershedStructure;

static bool CustomFun(WatershedPixel* pl,WatershedPixel*pr)
    {
        bool res=0;
        res =pl->getIntHeight() < pr->getIntHeight();
        return res;
    }

public:
    WatershedStructure(uchar* pixels, int width, int height)
    {	// �ṹ�幹�캯��


        watershedStructure.reserve(width * height);	 // �������ص�����Ԥ����ռ�
        /* ��ÿ�����ص���Ϣ����ṹ�� */
        for (int y = 0; y < height; ++y)
            for (int x = 0; x < width; ++x)
                watershedStructure.push_back(new WatershedPixel(x, y, pixels[x+y*width]));//��WatershedPixel����ѹ��vector��watershedStructure

        /* ����������ص��8��ͨ�������� */
        for (int y = 0; y < height; ++y) {
            //int offset = y * width;
//            int topOffset = offset + width;
//            int bottomOffset = offset - width;

            for (int x = 0; x < width; ++x) {
				int currentindex = x + y*width;	// ��ǰ���ص�����
                WatershedPixel* currentPixel = watershedStructure.at(currentindex);

				if (x - 1 >= 0) {
                    currentPixel->addNeighbour(watershedStructure.at(currentindex-1)); // ������
                    if (y - 1 >= 0)	 // ���½�
                        currentPixel->addNeighbour(watershedStructure.at(currentindex-1 - width));
                    if (y + 1 < height)	 // ���Ͻ�
                        currentPixel->addNeighbour(watershedStructure.at(currentindex-1 + width));
                }

                if (x + 1 < width) {
                    currentPixel->addNeighbour(watershedStructure.at(currentindex+1)); // ������
                    if (y - 1 >= 0)	 // ���½�
                        currentPixel->addNeighbour(watershedStructure.at(currentindex+1 - width));
                    if (y + 1 < height) // ���Ͻ�
                        currentPixel->addNeighbour(watershedStructure.at(currentindex+1 + width));
                }

                if (y - 1 >= 0) // ������
                    currentPixel->addNeighbour(watershedStructure.at(currentindex-width));

                if (y + 1 < height)	 // ������
                    currentPixel->addNeighbour(watershedStructure.at(currentindex+width));
            }
        }

		/* ���ݻҶ�ֵ�Խṹ���е��������ص��С����������� */
//  std::sort(watershedStructure.begin(), watershedStructure.end(),[](WatershedPixel* pl, WatershedPixel* pr) { return pl->getIntHeight() < pr->getIntHeight(); });

   std::sort(watershedStructure.begin(),watershedStructure.end(),CustomFun);

    } // �������
    ~WatershedStructure() {	// �ͷ���������ռ�ռ�
        while (!watershedStructure.empty()) {
            WatershedPixel* p = watershedStructure.back();
            delete p; p = NULL;
            watershedStructure.pop_back();
        }
    }

    int size() { return watershedStructure.size(); }	// �������ص�����

    WatershedPixel* at(int i) { return watershedStructure.at(i); }	// ����ĳ�����ص�
};

#endif
