#include <iostream>
#include <vector>
#include <string>

using namespace std;
//联系人
struct contact {
    string name;    //姓名
    char sex[4];   //性别
    int age;    //年龄
    int phone;   //电话
    string address; //地址
};


//启动系统
void startSystem(vector<contact>);

//显示菜单
void showMenu();

//退出系统
void exitSystem();

//添加联系人
void addContact();

//显示联系人
void showContact();

void showContact(contact);

//查找联系人
bool findContact(string contact_name);

contact *findContact(string contact_name, int contact_phone);

//删除联系人
void removeContact(string contact_name, int contact_phone);

//修改联系人
bool updateContact(contact *contact);

//全局变量，用于存储所有的联系人
vector<contact> contacts;

int main() {

    //启动系统
    startSystem(contacts);
    return 0;
}

void showMenu() {
    cout << "欢迎使用通讯录管理系统" << endl;
    cout << "1.添加联系人" << endl;
    cout << "2.显示联系人" << endl;
    cout << "3.删除联系人" << endl;
    cout << "4.查找联系人" << endl;
    cout << "5.修改联系人" << endl;
    cout << "6.清空联系人" << endl;
    cout << "0.退出联系人" << endl;
    cout << "********************" << endl;
}

void exitSystem() {
    cout << "程序已退出,欢迎再次使用.";
    exit(0);
}

/**
 * 启动系统
 * @param contacts 所有的联系人
 */
void startSystem(vector<contact> contacts) {
    //用户的选择
    int choose = 0;
    while (true) {
        showMenu();
        cin >> choose;
        switch (choose) {
            case 1:
                //添加联系人
                addContact();
                cout << "===========================" << endl;
                break;
            case 2:
                //显示联系人
                showContact();
                cout << "===========================" << endl;
                break;
            case 3: {
                //指定联系人的姓名和电话
                string tmp_name;
                int tmp_phone;
                cout << "请输入联系人的姓名:";
                cin >> tmp_name;
                cout << "请输入联系人的电话:";
                cin >> tmp_phone;
                removeContact(tmp_name, tmp_phone);
                cout << "===========================" << endl;
                break;
            }
            case 4: {
                //查找指定的联系人
                string tmp_name;
                cout << "请输入要查找的联系人的姓名:";
                cin >> tmp_name;
                if (!findContact(tmp_name))
                    cout << "查无此人" << endl;

                cout << "===========================" << endl;
                break;
            }
            case 5: {
                //修改联系人信息
                string tmp_name;
                int tmp_phone;
                cout << "请输入要修改的联系人的姓名:";
                cin >> tmp_name;
                cout << "请输入要修改的联系人的电话:";
                cin >> tmp_phone;
                cout << "===========================" << endl;
                updateContact(findContact(tmp_name, tmp_phone));
            }
                break;
            case 6: {
                char choose[1];
                cout<<"你确定要清除所有的联系人信息吗?\t[Y/n]";
                cin>>choose;
                if('Y'==choose[0]){
                    for (int i = 0; i < contacts.size(); ++i) {
                        contacts.erase(contacts.begin()+i);
                    }
                    cout<<"清除成功.";
                }else{
                    cout<<"清除失败!"<<endl;
                }
                cout << "===========================" << endl;
                break;
            }
            case 0: //退出系统
                exitSystem();
                break;
        }
        if (!choose)
            break;
    }
}

/**
 * 添加联系人
 * @TODO 向所有联系人vector内新增一个联系人
 */
void addContact() {
    contact c;
    cout << "请输入姓名：";
    cin >> c.name;
    cout << "请输入性别:";
    cin >> c.sex;
    cout << "请输入年龄:";
    cin >> c.age;
    cout << "请输入电话:";
    cin >> c.phone;
    cout << "请输入地址:";
    cin >> c.address;
    contacts.push_back(c);
    cout << "新增成功!" << endl;
}

/**
 * 显示所有联系人
 * @TODO 遍历输出vector内的所有联系人信息
 */
void showContact() {
    for (int i = 0; i < contacts.size(); ++i) {
        cout << "姓名:" << contacts.at(i).name << "\t性别:" << contacts.at(i).sex << "\t年龄:" << contacts.at(i).age
             << "\t电话:" << contacts.at(i).phone << "\t地址:" << contacts.at(i).address << endl;
    }
}

/**
 * 显示联系人信息
 * @TODO 显示具体的联系人的信息
 * @param c 指定的联系人
 */
void showContact(contact c) {
    cout << "姓名:" << c.name << "\t性别:" << c.sex << "\t年龄:" << c.age << "\t电话:" << c.phone << "\t地址:" << c.address
         << endl;
}

/**
 * 删除联系人
 * @TODO 根据姓名和电话，删除指定联系人的信息
 * @param contact_name
 * @param contact_phone
 */
void removeContact(string contact_name, int contact_phone) {
    bool isRemove = false;

    for (int i = 0; i < contacts.size(); ++i) {
        if (!contacts.at(i).name.compare(contact_name) && contacts.at(i).phone == contact_phone) {
            contacts.erase(contacts.begin() + i);
            cout << "删除成功!" << endl;
            isRemove = true;
            break;
        }
    }
    if (!isRemove)
        cout << "删除失败!" << endl;
}

/**
 * 查找联系人
 * @TODO 根据姓名,遍历vector查找联系人信息
 * @param contact_name
 * @return
 */
bool findContact(string contact_name) {
    bool isFind = false;
    for (int i = 0; i < contacts.size(); ++i) {
        if (!contacts.at(i).name.compare(contact_name)) {
            isFind = true;
            showContact(contacts.at(i));
        }
    }
    return isFind;
}

/**
 * 查找联系人
 * @param contact_name 指定的姓名
 * @param phone 指定的电话
 * @return 查找到的联系人
 */
contact *findContact(string contact_name, int phone) {
    for (int i = 0; i < contacts.size(); ++i) {
        if (!contacts.at(i).name.compare(contact_name) && contacts.at(i).phone == phone)
            return &contacts.at(i);
    }
}

/**
 * 修改联系人
 * @TODO 修改指定联系人的所有信息
 * @param contact
 * @return
 */
bool updateContact(contact *contact) {
    string name, address;
    char sex[4], choose[1];
    int age, phone;
    cout << "您要修改的联系人为:" << contact->name << endl;
    cout << "----------------------" << endl;
    cout << "请输入姓名:";
    cin >> name;
    cout << "请输入性别:";
    cin >> sex;
    cout << "请输入年龄:";
    cin >> age;
    cout << "请输入电话:";
    cin >> phone;
    cout << "请输入地址:";
    cin >> address;

    cout << "确定要修改" << contact->name << "的信息吗?\t[Y/n]";
    cin >> choose;
    if ('Y' == *choose) {
        contact->name = name;
        contact->name = name;
        contact->age = age;
        contact->phone = phone;
        contact->address = address;
        cout << "修改成功." << endl;
        return true;
    }
    cout << "修改失败!";
    return false;
}
