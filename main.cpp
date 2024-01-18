class MyClass
{
    public:
    int my_int_data;
    MyClass(int x):
    my_int_data{x}
    {
        std::cout << "Constructor of MyClass" << std::endl;
    }
    ~MyClass()
    {
        std::cout << "Destructor of MyClass" << std::endl;
    }
};

int main()
{
    MyQueue<MyClass*> mys;
    for(int j=20;j<30;++j)
    {
        MyClass* ptr = new MyClass(j);
        mys.push(ptr);
    }
    mys.printValues();

    mys.clear();

    return 0;
}
