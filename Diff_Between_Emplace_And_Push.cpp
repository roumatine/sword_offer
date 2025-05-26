#include "head.h"

struct Person {
    string name;
    int age;
    // 初始构造函数
    Person(string p_name, int p_age): name(std::move(p_name)), age(p_age) {
        cout << "I have been constructed. " << endl;
    }
    // 拷贝构造函数
    Person(const Person& other): name(std::move(other.name)), age(other.age) {
        cout << "I have been copy constructed. " << endl;
    }
    // 转移构造函数
    Person(Person&& other): name(std::move(other.name)), age(other.age) {
        cout << "I have been moved. " << endl;
    }
};

int main() {
    vector<Person> vec;
    cout << "emplace_back: " << endl;
    vec.emplace_back("Jame", 23);

    vector<Person> vec2;
    cout << "push_back: " << endl;
    vec2.push_back(Person("Mike", 32));
    return 0;
}