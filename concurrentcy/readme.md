# C++并发编程

## 简单入门

L001 - L007为 C++11的多线程入门<br>

大致用代码讲解如下<br>

1.讲解主线程和子线程的具体运行，main函数里的是主线程，创建的线程是子线程，其中可能会遇到子线程仍在运行，但是主线程结束的情况，这会报错。我们可以用join函数让主线程阻塞来等待子线程运行。detach可以让主线程和子线程进行分离<br>

2.创建thread线程的语法<br>

3.如何以类的成员函数作为线程入口以及派生类的成员函数作为线程入口 L005.cpp<br>

4.lambda函数作为线程入口 L006.cpp<br>

5. 用call_once来保证线程只运行一次<br>
