#include <iostream>
using namespace std;

class String 
{
private:
    char* str; 

    size_t calcLength(const char* c_str) const 
    {
        size_t length = 0;
        while (c_str[length] != '\0') 
        {
            length++;
        }
        return length;
    }

    void copyStr(char* dest, const char* src) const 
    {
        size_t i = 0;
        while (src[i] != '\0') 
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

    void concatStr(char* dest, const char* src) const 
    {
        size_t destLen = calcLength(dest);
        size_t srcLen = calcLength(src);
        for (size_t i = 0; i <= srcLen; i++) 
        {
            dest[destLen + i] = src[i];
        }
    }

    int compareStr(const char* str1, const char* str2) const 
    {
        size_t i = 0;
        while (str1[i] != '\0' && str2[i] != '\0') 
        {
            if (str1[i] != str2[i]) 
            {
                return str1[i] - str2[i];
            }
            i++;
        }
        return str1[i] - str2[i];
    }

public:
    String() 
    {
        str = new char[1];
        str[0] = '\0';
    }

    String(const char* c_str) 
    {
        size_t length = calcLength(c_str);
        str = new char[length + 1];
        copyStr(str, c_str);
    }

    String(const String& other) 
    {
        size_t length = calcLength(other.str);
        str = new char[length + 1];
        copyStr(str, other.str);
    }

    String& operator=(const String& other) 
    {
        if (this != &other) 
        {
            delete[] str;
            size_t length = calcLength(other.str);
            str = new char[length + 1];
            copyStr(str, other.str);
        }
        return *this;
    }

    size_t length() const 
    {
        return calcLength(str);
    }

    void clear() 
    {
        delete[] str;
        str = new char[1];
        str[0] = '\0';
    }

    ~String() 
    {
        delete[] str;
    }

    String operator+(const String& other) const 
    {
        size_t newLength = length() + other.length();
        char* newStr = new char[newLength + 1];
        copyStr(newStr, str);
        concatStr(newStr, other.str);
        String result(newStr);
        delete[] newStr;
        return result;
    }

    String& operator+=(const String& other) 
    {
        size_t newLength = length() + other.length();
        char* newStr = new char[newLength + 1];
        copyStr(newStr, str);
        concatStr(newStr, other.str);
        delete[] str;
        str = newStr;
        return *this;
    }

    bool operator==(const String& other) const 
    {
        return compareStr(str, other.str) == 0;
    }

    bool operator!=(const String& other) const 
    {
        return !(*this == other);
    }

    void print() const 
    {
        cout << str << endl;
    }
};

int main() {
    String str1;
    cout << "Empty string: ";
    str1.print();

    String str2("Hello, world!");
    cout << "String with text: ";
    str2.print();

    String str3 = str2;
    cout << "Copy of str2: ";
    str3.print();

    str1 = str3;
    cout << "str1 after assignment from str3: ";
    str1.print();

    String str4 = str1 + str2;
    cout << "Concatenation of str1 and str2: ";
    str4.print();

    str1 += str2;
    cout << "str1 after concatenation with str2: ";
    str1.print();

    cout << "Are str1 and str3 equal? " << (str1 == str3 ? "Yes" : "No") << endl;
    cout << "Are str1 and str2 unequal? " << (str1 != str2 ? "Yes" : "No") << endl;

    str1.clear();
    cout << "str1 after clearing: ";
    str1.print();
}
