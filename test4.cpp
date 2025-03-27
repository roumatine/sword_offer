#include "face4.h"

void Test(char *testName, char str[], int len, char exp[]) {
    if (testName != nullptr) {
        std::cout << testName << "begins: ";
    }
    ReplaceBlank(str, len);

    if (exp == nullptr && str == nullptr) {
        std::cout << "passed." << std::endl;
    } else if(exp == nullptr && str != nullptr) {
        std::cout << "failed." << std::endl;
    } else if(strcmp(str, exp) == 0) {
        std::cout << "passed." << std::endl;
    } else {
        std::cout << "failed." << std::endl;
    }
}

void Test1() {
    const int len = 200;
    char str[len] = "hello world";
    Test("Test1 ", str, len, "hello%20world");
}

void Test2()
{
    const int length = 100;

    char str[length] = " helloworld";
    Test("Test2", str, length, "%20helloworld");
}

void Test3()
{
    const int length = 100;

    char str[length] = "helloworld ";
    Test("Test3", str, length, "helloworld%20");
}

void Test4()
{
    const int length = 100;

    char str[length] = "hello  world";
    Test("Test4", str, length, "hello%20%20world");
}

void Test5()
{
    Test("Test5", nullptr, 0, nullptr);
}

// 传入内容为空的字符串
void Test6()
{
    const int length = 100;

    char str[length] = "";
    Test("Test6", str, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;

    char str[length] = " ";
    Test("Test7", str, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
    const int length = 100;

    char str[length] = "helloworld";
    Test("Test8", str, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;

    char str[length] = "   ";
    Test("Test9", str, length, "%20%20%20");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}

