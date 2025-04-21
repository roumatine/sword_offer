#include "..\head.h"

class sealed_class1 {
public:
    static sealed_class1 *get_instance() {
        return new sealed_class1();
    }
    static void delete_instance(sealed_class1 * p_instance) {
        delete p_instance;
    }

private:
    sealed_class1() {}
    ~sealed_class1() {}
};


template <typename T> class make_sealed {
    friend T;

private:
    make_sealed() {}
    ~make_sealed() {}
};

class sealed_class2 : virtual public make_sealed<sealed_class2> {
public:
    sealed_class2() {}
    ~sealed_class2() {}
};