#include <iostream>
using namespace std;
class String{
private:
    char* m_data;
public:
//    1. 普通构造函数
    String (const char* str = 0);
//2.  get 函数
    char *getMData() const;
//    3.
    String(const String& str);
//    4.
    String& operator =(const String& str);
    ~String();
};

String::~String() {
    delete[] m_data;
}

String &String::operator=(const String &str) {
    if(this == &str ){
        return *this;
    }
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data,str.m_data);
    return *this;
}

String::String(const String &str) {
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data,str.m_data);
}

String::String(const char* str) {
//    如果不等于0
    if(str){
        m_data = new char[strlen(str) + 1];
        strcpy(m_data,str);
    }else{
        m_data = new char[1];
        *m_data = '/0';
    }
}

char *String::getMData() const {
    return m_data;
}

ostream& operator <<(ostream& os,String& str){
    cout << str.getMData() << endl;
}

int main() {
    String s1("hello");
    String s2("111111");
    cout << s1 << endl;
    cout << s2 << endl;
//    String s3(s2);
//    cout << s3 << endl;
    return 0;
}
