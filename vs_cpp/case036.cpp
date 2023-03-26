/**
 * @author yangjian
 * @brief 获取用户输入
 * @version 0.1
 * @date 2023-03-14
 * 
 * @copyright Copyright (c) 2023
 */
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main(int argc, char** argv)
{
	char userName[10]{ '\0' };
	char password[10]{ '\0' };

	cout << "请输入用户名：\n";
	cin >> userName;

	cout << "请输入密码：\n";
	cin >> password;

	cout << "-----------------------\n";
	cout << "|       登录框        |\n";
	cout << "|---------------------|\n";
	cout << "| 用户名 | " << userName << setw(13 - strlen(userName)) << " |\n";
	cout << "|---------------------|\n";
	cout << "| 密  码 | " << password << setw(13 - strlen(password)) << " |\n";
	cout << "|---------------------|\n";
	return 0;

}
