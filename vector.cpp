
#include <iostream>
#include <string>
#include <vector>
const int max = 3;
template<typename Iterator>
void divideInto(const Iterator begin, const Iterator end)
{
    const int length = std::distance(begin, end);

    Iterator advance_iterator;
    if (length > max) {
        advance_iterator = begin;
        advance_iterator += max;
        divideInto(advance_iterator, end);
    } else {
        advance_iterator = end;
    }

    for(Iterator i = begin; i < advance_iterator; i++)
    {
        std::cout << *i;
    }
    printf("\n");
}

int main(int, char* [])
{
    std::vector<std::string> v;
    v.push_back("hoge_1");
    v.push_back("hoge_2");
    v.push_back("hoge_3");
    v.push_back("hoge_4");
    v.push_back("hoge_5");
    v.push_back("hoge_6");
    v.push_back("hoge_7");
    v.push_back("hoge_8");
    v.push_back("hoge_9");
    v.push_back("hoge_10");

    divideInto(v.cbegin(), v.cend());

    return 0;
}
