#include <iostream>
using namespace std;

class String{
private:
    char* m_data;
public:
    String (const char* cstr = 0);
    String (const String& str);
    char* get_cstr () const{
        return m_data;
    }
    String& operator= (const String& str);
    String& method();
//    最后一个 析构函数
    ~String();

};

String::~String() {
    delete[] m_data;
}

String &String::operator=(const String& str) {
    // 先要考虑是不是自己
    if(this == &str){
        return *this;
    }
    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data,str.m_data);
    return *this;
}

String::String(const String &str) {
    m_data = new char [strlen(str.m_data) + 1];
    strcpy(m_data,str.m_data);
}

String::String(const char *cstr) {
    if(cstr){
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data,cstr);
    }
    else{
        // 未指定初值
        m_data = new char[1];
        *m_data = '/0';
    }
}

//重载操作符
ostream& operator << (ostream& os,const String& str){
    os << str.get_cstr() ;
    return os;
}

int main() {
    String s1("hello jay");
    cout << s1 << endl;
    cout << "-----------------------" << endl;
    String s2("hello rose");
    cout << s2 << endl;
    cout << "-----------------------" << endl;

    String s3(s2);
    cout << s3 << endl;
    cout << "-----------------------" << endl;
    s3 = s1;
    cout << s3 << endl;
    return 0;
}
