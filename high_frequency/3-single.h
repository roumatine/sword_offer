#include "..\head.h"

// 饿汉模式
class SinglePattern {
private:
    SinglePattern() {};
    static SinglePattern *p;
public:
    static SinglePattern *instance();

    class CG {
        public:
            ~CG() {
                if (SinglePattern::p != nullptr) {
                    delete SinglePattern::p;
                    SinglePattern::p = nullptr;
                }
            }
    };

    SinglePattern* SinglePattern::p = new SinglePattern();
    SinglePattern* SinglePattern::instance() {
        return p;
    }
};

// 懒汉模式
class singlePattern {
private:
    static singlePattern *p;
    singlePattern() {};
public:
    static singlePattern *instance();
    class CG {
        public:
            ~CG() {
                if (singlePattern::p != nullptr) {
                    delete singlePattern::p;
                    singlePattern::p = nullptr;
                }
            }
    };
    singlePattern *singlePattern::p = nullptr;
    singlePattern *singlePattern::instance() {
        if (p == nullptr) {
            return new singlePattern();
        }
        return p;
    }
};