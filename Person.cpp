#include <iostream>

class Person
{
    private:
        std::string m_name;
        int m_age;
    public:
        Person() : m_name(""), m_age(0) {}  

        Person(std::string name, int age) : m_name(name), m_age(age) {}

        void setname(std::string name)
        {
            m_name = name;
        }
        void setage(int age)
        {
            m_age = age;
        }
        std::string getname() const
        {
            return m_name;
        }
        int getage() const
        {
            return m_age;
        }
        bool operator==(const Person& other) const
        {
            return m_name == other.m_name && m_age == other.m_age;
        }

};
Person find(Person p[], int sz, const std::string& name)
{
    for(int i = 0; i < sz; ++i)
    {
        if(p[i].getname() == name)
        {
            return p[i];
        }
    }
    return Person();
}

Person get_oldest(Person* arr, int sz)
{
    int max = arr[0].getage();
    int index = 0;
    for(int i = 1; i < sz; ++i)
    {
        if(arr[i].getage() > max)
        {
            max = arr[i].getage();
            index = i;
        }

    }
    return arr[index];

}
void swap(Person *obj1, Person *obj2)
{
    Person tmp = *obj1;
    *obj1 = *obj2;
    *obj2 = tmp;
}

Person* reverse(Person* arr, int s)
{
    
    for(int i = 0; i < s /  2; ++i)
    {
        swap(&arr[i], &arr[s - 1 - i]);
    }
    for(int i = 0; i < s; ++i)
    {
        std::cout << arr[i].getname() << std::endl;
        std::cout << arr[i].getage() << std::endl;
    }
    return arr;
    
}

void inicalization(Person *person, int size)
{
    
    for(int i = 0; i < size; ++i)
    {
        std::string name;
        int age = 0;
        std::cout << "Enter name in index[" << i << "]" << std::endl;
        std::cin >> name;
        person[i].setname(name);
        std::cout << "Enter age in index[" << i << "]" << std::endl;
        std::cin >> age;
        person[i].setage(age);
    }
    
}
int main()
{
    
    int size = 3;
    Person person[size];
    inicalization(person, size);
    return 0;
}
