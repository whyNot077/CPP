# CPP 06 : Cast
1. c-ctyle cast  
This method is not recommended in C++ programming. Because of the broad, unresponsible freedom of conversion right of the compiler, it can make unexpected errors. 
```c++
int* ptr = new int(5);
double* doublePtr = (double*)ptr;
```

2. static_cast  
In static_cast, the compiler checks its conversion in the compile time, making it simple, reliable, and fast.  
```c++
void ScalarConverter::ConvertChar(double str) {
    char c;

    if (str < CHAR_MIN || str > CHAR_MAX)
        std::cout << CHAR << IMPOSSIBLE << '\n';
    else if (str < 32 || str > 126)
        std::cout << CHAR << NON_DISPLAYABLE << '\n';
    else {
        c = static_cast<char>(str);
        std::cout << CHAR << c << '\n';
    }
}
```
But if you need to perform the more complex conversion, use dynamic_cast, const_cast, or reinterpret_cast. These casting methods convert types at the runtime, so it's possible to have runtime overhead but more flexibility.  

3. dynamic_cast    
Dynamic cast is for convert between inheritance relationship. I needs at least one virtual fuction, because it should get a information about class memory layout by seeking virtual table. 
```c++
void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        static_cast<void>(a);
    }
    catch (std::exception& e) {
        try {
            B& b = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
            static_cast<void>(b);
        }
        catch (std::exception& e) {
            try {
                C& c = dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
                static_cast<void>(c);
            }
            catch (std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
    }
}
```
4. const_cast  
If you need to modify the value of the const instance, you may consider const_cast. It allows you to temporarily remove the const qualifier, change the value, and restore it afterward. However, modifying a const instance might have unintended consequences.  
```c++
const char c = 'A';
char& cRef = const_cast<char&>(c);
cRef = 'B';
```

5. reinterpret_cast  
reinterpret_cast is employed for converting between different pointer types, particularly pointer-to-pointer conversions. However, it's risky due to potential variations in behavior across OS. Also, its lack of compatibility checks between types can lead to memory inconsistencies and undefined behavior. So if you can use other casting, such as static_cast, dynamic_cast, and const_cast, use them instead of reinterpret_cast.  

```c++
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
```
**What is serialization?**


# CPP 07 : Template

```c++
template<typename T>
```
This line informs the compiler that a template is being declared and that T is a placeholder for a type that will be supplied later. The compiler doesn't replace T at runtime; rather, it generates the appropriate function or class definitions at compile-time based on the types used to instantiate the template.  

```c++
template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
```
This code defines a function template for the swap function. The compiler will generate different versions of this function for different types T as needed, during compile-time.  

```c++
template <typename T, typename Func>
void iter(T* array, size_t length, Func func) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}
```
This code showcases a function template named iter, which not only takes an array of type T and its length but also another function func. It demonstrates that templates can be versatile and can take multiple type parameters.  

