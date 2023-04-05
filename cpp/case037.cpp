#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv)
{
    int mode = 0;

    char text[128] {'\0'};
    char cryptograph[128] {'\0'};

    while (mode != 3)
    {
        cout << "输入工作模式：1->加密，2->解密，3->退出系统!" << endl;
        cin >> mode;

        switch (mode) 
        {
            case 1:
            {
                cout << "请输入要加密的明文：" << endl;
                scanf("%s", text);
                int length = strlen(text);
                for (int i = 0; i < length; ++i)
                {
                    cryptograph[i] = text[i] + i + 5;
                }
                cryptograph[length] = '\0';
                cout << "密文为: " << cryptograph << endl;
            }
            break;
            case 2:
            {
                cout << "请输入要解密的密文：" << endl;
                scanf("%s", cryptograph);
                int length = strlen(cryptograph);
                for (int i = 0; i < length; ++i)
                {
                    text[i] = cryptograph[i] - i - 5;
                }
                text[length] = '\0';
                cout << "原始明文为: " << text << endl;
            }
            break;
            case 3: break;
            default:
            {
                cout << "请输入指定的工作模式" << endl;
            }
        }
    }
    return 0;
}