//
// Created by Oleksandr Bykovskyi on 6/2/21.
//
#include <iostream>

using namespace std;

class My {
public:

    My(std::string s): s_(s) {}

    ~My() {
        cout << "Destroy My==" << s_ << endl;
    }
    void p() {}

private:
    std::string s_;
};

class Container {
public:
    Container(My* my): my_(my) {}
private:
    My* my_;
};

My* test_other() {
    My* my = new My("1");
    return my;
}

My* test_other2() {
    static My my("3");
    return &my;
}

Container test() {
    My my("2");
    my.p();

    My* other_my_ptr = test_other();
    other_my_ptr->p();
    delete other_my_ptr;

    My* my3 = test_other2();
    Container c(my3);
    return c;
}

int main() {
    Container c = test();
    cout << "!! END" << endl;
    return 0;
}