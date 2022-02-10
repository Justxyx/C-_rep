#include <iostream>
using namespace  std;


class String {
public:
    char * m_data;
public:
    String(const char* cstr=0){
        if (cstr)
        {
            m_data = new char[strlen(cstr) + 1];
            strcpy(m_data, cstr);
        }
        else
        {
            m_data = new char[1];
            *m_data = '\0';  //这里也许可以这样写：*m_data='';(网友观点)
        }
    }
    String(const String& str = 0){
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data,str.m_data);
    }
    String& operator=(const String& str){
        if(this == &str){
            return *this;
        }
        delete[] m_data;
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
        return *this;
    }


};

//  操作符重载
ostream& operator <<(ostream& os,const String& str){
    os << str.m_data ;
    return os;
}


int main() {
    String s("hello");
    String S2("jay");
    cout << s << endl;
    return 0;
}


