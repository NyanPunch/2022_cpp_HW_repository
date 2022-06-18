#include "GradeManager.h"

GradeManager::GradeManager()
{
	cout << "GradeManager ����Ʈ ������ ȣ��\n";
	m_std = NULL;
	m_stdnum = 0;
}

GradeManager::GradeManager(int m_stdnum)
{
	cout << "GradeManager ���� ������ ȣ��\n";
	this->m_stdnum = m_stdnum;
	this->m_std = new Student[m_stdnum];
}

GradeManager::~GradeManager()
{
	delete[] this->m_std;
}

void GradeManager::Execute()
{
	int command = 0;
	int i = 0, temp = 0; //temp = �Ϻ� �۵� ���� ����
	string stdname;
	Student* std;

	while (command != 6) {
		PrintMenu();		//�޴� ���
		cin >> command; cin.ignore(); //Ŀ�ǵ� �Է�
		/* 2~5���� �л� ���� ���Է»��·� �Է½� */
		if (command != 1 && temp == 0 && command != 6) {
			cout << "\n!!!�л� �������� �Է����ּ���!!!\n";
			continue;
		}
		/* �л� ������ �Էµ� ���·� �� �� �� �Է� �� ����� ���� */
		if (command == 1 && temp == 1) {
			cout << "\n!!������ ���Ͻø� 5���� �Է����ּ���!!\n";
			continue;
		}

		switch(command) {
		case 1: //���� �Է�
			for (i = 0; i < this->m_stdnum; i++) {
				m_std[i].InputData();
			}
			temp = 1;		//���� ���Է� ����
			break;
		case 2: //���� ���
			for (i = 0; i < this->m_stdnum; i++) {
				m_std[i].PrintData();
			}
			break;
		case 3: //�л� �˻�
			cout << "ã�� �л��� �̸��� �Է����ּ��� : ";
			getline(cin, stdname);
			std = StdSearch(stdname);
			std->PrintData();
			break;
		case 4: //�л� ����Ʈ ���
			PrintAllStdList();
			break;
		case 5: //���� ����
			Modify();
			break;
		case 6:
			cout << "\n ���α׷��� �����մϴ�.\n";
			break;
		default:
			cout << "\n �������� �ʴ� ��ɾ��Դϴ�.\n";
			break;
		}
	}
}

void GradeManager::PrintMenu()
{
	cout << "\n====== �޴� ======\n";
	cout << " 1. �л� ���� �Է�\n";
	cout << " 2. ��ü ���� ����\n";
	cout << " 3. �л� �˻�\n";
	cout << " 4. �л� ��� ����\n";
	cout << " 5. �л� ���� ����\n";
	cout << " 6. ���α׷� ����\n";
	cout << "\n ���ϴ� ����� �Է��ϼ���(1~6) : ";
}
//stdname == �˻��� �̸�
Student* GradeManager::StdSearch(string stdname) const
{
	int temp = 0, i;
	for (i = 0; i < this->m_stdnum; i++) { //return == �޸��ּ� �����Ұ�
		if (this->m_std[i].GetName().compare(stdname) == 0) {
			temp = 1; break;
		}
	}
	if (temp == 1) return &(this->m_std[i]);
	cout << "\nã���ô� �л��� �����ϴ�!\n";
	return NULL;
}

void GradeManager::PrintAllStdList() const
{
	cout << "===============================\n";
	cout << "  �̸�            �й�	        \n";
	cout << "===============================\n";
	for (int i = 0; i < m_stdnum; i++) {
		cout <<"  " << m_std[i].GetName() << "\t" << m_std[i].GetHakbun() << endl;
	}
	cout << "===============================\n";
}

void GradeManager::Modify()
{
	string stdname; //������ �л��̸�
	Student* std;
	cout << "������ �� �л��� �̸��� �Է��ϼ��� : ";
	getline(cin, stdname);
	std = StdSearch(stdname);
	if (std) std->Modify();
}
