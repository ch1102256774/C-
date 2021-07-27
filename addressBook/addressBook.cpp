#include <iostream>
#include <string>
#include <cmath>
#include <process.h>
#include <conio.h>
#include <fstream>

using namespace std;

//�����ϵ��������1000
const int max_num = 1000;						
 
//������ϵ�˽ṹ�� 
struct Contact_person{		
	string name;						//���� 
	string address;						//סַ 
	string gender;			//���ʹ��ö�����ͣ��л���Ů 
	int age;							//���� 
	string phone_number; 				//��ϵ�绰 
};

//Ӧ�����ļ���ȡ��������ÿ�γ������е�����д���ļ��У�������ϵ����Ϣ 
//����ͨѶ¼����ϵ�˽ṹ�������
struct Contact_person address_book[1000];		

//��ǰ��ϵ������
int current_num = 0;
 
//�˵�״̬λ
short int menu_state = 9;

//�Ƿ��˳����������
bool isRun = true; 
 
 //��������
 void menu();
 void show_menu();
 void add_person();
 void show_person();
 void delete_person();
 void find_person();
 void revise_person();
 void clear_person();
 void exit_addressBook();
 void writePersonArray(char filename[],Contact_person a[], int n);
 int readPersonArray(char filename[],Contact_person a[], int nmax);
 
//��������� 
int main(){
	char filename[] = "addressBook.txt"; 
	current_num = readPersonArray(filename,address_book,1000);		//�����ļ��е����� ,��ȡ��ϵ������ 
	cout << current_num;
	while(isRun){
		menu();
	}
	writePersonArray(filename,address_book,current_num);			//������д���ļ� 
	return 0;
}

//***********************************************************************************//
//***********************************************************************************//
//********************************�ⲿ��������***************************************//
 
//��ʽ�˵�����������������ִ�У�������Ӧ�ĺ������ţ����й��ܳ��� 
void menu(){
	menu_state = 9;			//��������״̬λΪ9
	system("cls");			//ִ�п���̨����ָ��
	show_menu();			//��ӡ��ʾ���� 
	while(menu_state==9){
	 	cout << "�������Ӧ�Ĺ��ܼ���"; 
	 	cin >> menu_state;		//������Ӧ��״̬λ�������Ӧ����
	 	switch(menu_state){
	 	case 1: add_person(); break;
	 	case 2: show_person(); break;
	 	case 3: delete_person(); break;
	 	case 4: find_person(); break;
	 	case 5: revise_person(); break;
	 	case 6: clear_person(); break;
	 	case 0: exit_addressBook(); break;
	 	default: 
	 		cout << "����������������룡����"; 
	 		cout << "\n��������ص��˵�ҳ��"; 
	 		while(!_kbhit()){
	 			//����а������£����˳�whileѭ�����������γ��� 
			 }
	 }
	}
}

//��ӡ�˵������� 
void show_menu(){
	cout << "*****************************\n";
	cout << "*****************************\n";
	cout << "********1  �����ϵ��********\n";
	cout << "********2  ��ʾ��ϵ��********\n";
	cout << "********3  ɾ����ϵ��********\n";
	cout << "********4  ������ϵ��********\n";
	cout << "********5  �޸���ϵ��********\n";
	cout << "********6  �����ϵ��********\n";
	cout << "********0  �˳�ͨѶ¼********\n";
	cout << "*****************************\n";
	cout << "*****************************\n";
} 

//�����ϵ�˺������û�������ϵ����Ϣ����װ�ɽṹ��������ͨѶ¼������ 
void add_person(){
	int n = current_num;		//��λ��Ҫ�����ϵ�˵�λ��
	current_num += 1;			//����������һ 
	struct Contact_person *p_addPerson = &address_book[n];	//���λ�õĽṹ��ָ�� 
	cout << "��������ϵ��������";
	cin >>  (*p_addPerson).name;
	cout << "��������ϵ��סַ��";
	cin >> (*p_addPerson).address;
	cout << "��������ϵ���Ա�";
	cin >> (*p_addPerson).gender;
	cout << "��������ϵ�����䣺";
	cin >> (*p_addPerson). age;
	cout << "��������ϵ�˵绰��";
	cin >> (*p_addPerson).phone_number;
	cout << "������ɣ�����ӵ���ϵ����Ϣ��ʽ���£�\n";
	cout << "������" << (*p_addPerson).name << "  " << "סַ��" << (*p_addPerson).address;
	cout << "  �Ա�" << (*p_addPerson).gender << "  " << "���䣺" << (*p_addPerson).age;
	cout << "  �绰��" << (*p_addPerson).phone_number;
	cout << "\n��������˻����˵���";
	while(!_kbhit()){
		//���û�а�������һֱ�ȴ��� 
	}
}

//��ʽ��ϵ�˺��������������ϵ����Ϣ��ʹ���б�ѭ��
void show_person(){
	cout << "���е���ϵ����Ϣ��ʽ���£�\n";
	int i = 0;
	for(i=0;i<current_num;i++){
		struct Contact_person *p_addPerson = &address_book[i];	//���λ�õĽṹ��ָ�� 
		cout << "������" << (*p_addPerson).name << "  " << "סַ��" << (*p_addPerson).address;
		cout << "  �Ա�" << (*p_addPerson).gender << "  " << "���䣺" << (*p_addPerson).age;
		cout << "  �绰��" << (*p_addPerson).phone_number << endl;
	}
	cout << "\n��������˻����˵���";
	while(!_kbhit()){
		//���û�а�������һֱ�ȴ��� 
	}
} 

//ɾ����ϵ�˺�����ɾ��ĳһ����ϵ�ˣ���ϵ��������һ
void delete_person(){
	string person_name = "";
	cout << "��������ϵ��������";
	cin >> person_name;
	int i = 0;
	for(i=0;i<current_num;i++){
		if(person_name == address_book[i].name){
			for(int j=i;j<current_num-1;j++){
				address_book[j] = address_book[j+1];
			}
			address_book[current_num] = {};
			current_num -= 1; 
			break;
		}
	}
	if(i>=current_num){
		cout << "���޴��ˣ�����";
	} 
	cout << "\n��������˻����˵���";
	while(!_kbhit()){
		//���û�а�������һֱ�ȴ��� 
	} 
} 

//������ϵ�˺���������ĳ����ϵ�ˣ�������Ϣ
void find_person(){
	string person_name = "";
	cout << "��������ϵ��������";
	cin >> person_name;
	int i = 0;
	for(i=0;i<current_num;i++){
		if(person_name == address_book[i].name){
			struct Contact_person *p_addPerson = &address_book[i];	//���λ�õĽṹ��ָ�� 
			cout << "�����ҵ���ϵ����Ϣ��ʽ���£�\n";
			cout << "������" << (*p_addPerson).name << "  " << "סַ��" << (*p_addPerson).address;
			cout << "  �Ա�" << (*p_addPerson).gender << "  " << "���䣺" << (*p_addPerson).age;
			cout << "  �绰��" << (*p_addPerson).phone_number;
			break;		//Ĭ��û��ͬ��������ϵ�� 
		}
	}
	if(i>=current_num){
		cout << "���޴��ˣ�����";
	} 
	cout << "\n��������˻����˵���";
	while(!_kbhit()){
		//���û�а�������һֱ�ȴ��� 
	}
}

//�޸���ϵ�˺������û�������Ϣ���޸Ķ�Ӧ����ϵ����Ϣ
void revise_person(){
	string person_name = "";
	cout << "��������ϵ��������";
	cin >> person_name;
	int i = 0;
	for(i=0;i<current_num;i++){
		if(person_name == address_book[i].name){
			struct Contact_person *p_addPerson = &address_book[i];	//���λ�õĽṹ��ָ�� 
			cout << "�����޸���ϵ����Ϣ\n"; 
			cout << "��������ϵ��������";
			cin >>  (*p_addPerson).name;
			cout << "��������ϵ��סַ��";
			cin >> (*p_addPerson).address;
			cout << "��������ϵ���Ա�";
			cin >> (*p_addPerson).gender;
			cout << "��������ϵ�����䣺";
			cin >> (*p_addPerson). age;
			cout << "��������ϵ�˵绰��";
			cin >> (*p_addPerson).phone_number;
			cout << "������ɣ�����ӵ���ϵ����Ϣ��ʽ���£�\n";
			cout << "������" << (*p_addPerson).name << "  " << "סַ��" << (*p_addPerson).address;
			cout << "  �Ա�" << (*p_addPerson).gender << "  " << "���䣺" << (*p_addPerson).age;
			cout << "  �绰��" << (*p_addPerson).phone_number;
			break;
		}
	}
	if(i>=current_num){
		cout << "���޴��ˣ�����";
	} 
	cout << "\n��������˻����˵���";
	while(!_kbhit()){
		//���û�а�������һֱ�ȴ��� 
	}
	 
} 

//�����ϵ�˺����������ϵ�����飬
void clear_person(){
	for(int i=0;i<current_num;i++){
		address_book[i] = {};
	}
	current_num = 0;	
	cout << "��ϵ���б�����ա�";
	cout << "\n��������˻����˵���";
	while(!_kbhit()){
		//���û�а�������һֱ�ȴ��� 
	}
} 

//�˳�ͨѶ¼�������˳�������
void exit_addressBook(){
	isRun = false;
} 

//������д��txt�ļ����� 
// n Ϊ���� a ��Ԫ�ظ�����filename Ϊд����ļ���
void writePersonArray(char filename[], Contact_person a[], int n)
{
	int count = 0;
	ofstream out;
	out.open(filename);
	if(!out.is_open()){
		cout << "Error:file open fail.";
		exit(1);
	}
	else{
		for(count=0;count<n;count++){
			out << a[count].name << " " << a[count].address << " " << a[count].gender << " " \
				<< a[count].age << " " << a[count].phone_number << endl;
		}
		out.close();
	}
}

//��txt�ļ��������麯�� 
// ���� filename �ļ��ж�ȡ nmax ��ѧ����Ϣ�������浽���� a���ú�������ʵ�ʶ�ȡ�ļ�¼��������
int readPersonArray(char filename[], Contact_person address_book[], int nmax)
{
	ifstream in;
	in.open(filename);
	int count = 0;
	if(!in.is_open()){
		cout << "Error: open file fail!!!" << endl;
		exit(1);
	}
	while(!in.eof() && count <nmax){
		in >> address_book[count].name >> address_book[count].address >>address_book[count].gender  \
			>> address_book[count].age >> address_book[count].phone_number;
		count ++ ;
	}
	count -- ;			//eof()�����������ļ���βʱ�������ڽ���һ�ζ�ȡ��������ȥ������Ԫ�أ���ʱû�뵽���õĽ������ 
	in.close();
	return count;
}
