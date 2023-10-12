/*
	���� 3:
	- baseDMA, lacksDMA, hasDMA Ŭ������ �ϳ��� �߻�ȭ ���� Ŭ�����κ��� �Ļ��ǵ��� ����
	- �߻�ȭ ���� Ŭ���� �������� �迭 ����Ͽ� ��� �׽�Ʈ
	- ������ ����ϴ� ���� �޼��� View() �߰�
*/

#include <iostream>
#include "pe13-3.h"

int main() {
	using std::cout;
	using std::endl;
	using std::cin;

	DMA* p_dma[4];
	char label[40];
	int rating;

	char kind;
	for (int i = 0; i < 4; i++) {
		cout << "���� �Է��Ͻʽÿ�: ";
		cin.getline(label, 39);
		cout << "�򰡸� �Է��Ͻʽÿ�: ";
		cin >> rating;
		cout << "baseDMA ��ü�� 1, lacksDMA ��ü�� 2, hasDMA ��ü�� 3�� �Է��Ͻʽÿ�: ";
		while (cin >> kind && (kind != '1' && kind != '2' && kind != '3'))
			cout << "1 �ƴϸ� 2, 3�� �Է��Ͻʽÿ�: ";

		if (kind == '1') {
			p_dma[i] = new baseDMA(label, rating);
			cin.get();
		}
		else if (kind == '2') {
			char color[40];
			cin.get();
			cout << "������ �Է��Ͻʽÿ�: ";
			cin.getline(color, 39);
			p_dma[i] = new lacksDMA(color, label, rating);
		}
		else {
			char style[40];
			cin.get();
			cout << "��Ÿ���� �Է��Ͻʽÿ�: ";
			cin.getline(style, 39);
			p_dma[i] = new hasDMA(style, label, rating);
		}
	}
	cout << endl;

	for (int i = 0; i < 4; i++) {
		p_dma[i]->View();
		cout << endl;
	}

	for (int i = 0; i < 4; i++)
		delete p_dma[i];
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}