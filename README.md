# C++实现通讯录管理系统
参考黑马程序员C++课程的功能需求，同时新增了文件读写功能，使得通讯录能够长期保存。

## 实现功能

该程序实现了一个通讯录管理系统。

- 程序开始执行时，能在控制台向用户显式菜单栏信息，并读取存档至[](addressBook/addressBook.txt)文件中的联系人信息。

  <img src="https://github.com/ch1102256774/addressBook-amanagement-system/tree/main/image/menu.PNG" alt="image-20210727153650360" style="zoom:100%;" />

- 这之后，用户通过选择不同的功能按键，分别能够执行添加、显示、删除、查找、修改、清空联系人和退出程序操作。

  ![添加联系人信息](https://github.com/ch1102256774/addressBook-amanagement-system/tree/main/image/add.png)

- 若用户选择退出程序功能，程序在退出之前将联系人信息重新写入[](addressBook/addressBook.txt)文件中，保存修改之后的通讯录。

  ![退出程序](https://github.com/ch1102256774/addressBook-amanagement-system/tree/main/image/exit.png)

## 数据结构

- ### 联系人结构体

  ```c++
  struct Contact_person{		
  	string name;						//姓名 
  	string address;						//住址 
  	string gender;			//如何使用枚举类型：男或者女 
  	int age;							//年龄 
  	string phone_number; 				//联系电话 
  };
  ```

  联系人结构体名称为Contact_person，分别包含联系人的姓名、住址、性别、年龄和电话等信息。其中年龄使用整形表示，其他使用string类类型表示。

- ### 通讯录结构体数组

  ```c++
  struct Contact_person address_book[1000];	
  ```

  用结构体数组保存联系人信息，设置联系人上限为1000.

- ### 菜单栏的状态位

  ```c++
  short int menu_state = 9;
  ```

  设置菜单栏状态位，默认值为9，表示菜单栏的显式页面。

## 菜单功能

```c++
void menu();
void show_menu();
```

- 该部分希望实现当用户刚开始进入程序，以及每次执行完对应的功能之后，控制台能够只包含菜单栏的显式信息。
- 该部分的实现思路是使用while循环使得控制台界面停留在菜单栏，使用switch分支语句进入对应功能。

- 具体来说，程序首先初始化菜单栏状态位`menu_state = 9`,用户选择对应的功能键后，`menu_state`对应做出改变，并执行相应的功能。执行完成后`menu_state`重新设置为9，通过这一设计程序能够始终返回控制台，除非用户选择退出程序操作。

## 添加联系人

```c++
void add_person();
```

使用定义的变量`current_num`定位要添加的位置，之后`current_num++`.通过`cin`和`cout`提示用户输入联系人信息并保存

## 显式联系人

```c++
void show_person();
```

输出联系人列表中的所有信息

## 删除联系人

```C++
void delete_person();
```

- 通过用户输入姓名，删除列表中的对应元素
- 若数组中不存在含有该姓名的元素，提示用户“查无此人”

## 查找联系人

```c++
void find_person();
```

- 通过用户输入姓名，查找列表中的对应元素并显式在控制台
- 若数组中不存在含有该姓名的元素，提示用户“查无此人”

## 修改联系人

```C++
void revise_person();
```

- 通过用户输入姓名，查找列表中的对应元素，并提示用户修改信息
- 若数组中不存在含有该姓名的元素，提示用户“查无此人”

## 清空联系人

```c++
void clear_person();
```

将联系人结构体数组`address_book`置空

## 退出程序

```C++
void exit_addressBook();
```

通过设置标志位`isRun`为`false`，退出while循环，结束程序

## 通讯录文档读写功能

```C++
void writePersonArray(char filename[],Contact_person a[], int n);
int readPersonArray(char filename[],Contact_person a[], int nmax);
```

- 黑马程序员课程中的实现代码，并没有实现将用户数据保存到外部的文本文件中。当程序关闭时，与该程序相关的内存被释放，这将导致用户修改的联系人信息无法永久保存。
- 为了将数据长期保存，程序中添加了读文档和写文档的功能，分别由上述两个函数实现。
- `writePersonArray`函数中,下面的代码将每条用户的信息单行储存，不同类型数据空格隔开，方便读取

```c++
for(count=0;count<n;count++){
			out << a[count].name << " " << a[count].address << " " << a[count].gender << " " \
				<< a[count].age << " " << a[count].phone_number << endl;
		}
```

- `readPersonArray`函数中，下面的代码将读取文档中的联系人信息，直到文件末尾

```c++
while(!in.eof() && count <nmax){
		in >> address_book[count].name >> address_book[count].address >>address_book[count].gender  \
			>> address_book[count].age >> address_book[count].phone_number;
		count ++ ;
	}
```

这里需要注意的是，`eof()`方法当发现读到文档末尾时，仍然会再执行该读写操作一遍。然而文档末尾没有联系人信息，导致最后一个联系人结构体数组的元素为空。这个问题暂时没想到很好的解决办法，暂时在程序末尾执行`count--`命令使强制去除最后一个数组元素，大家有更好的解决办法可以提出来。
