#include "json.hpp"
#include <string>
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <map>
using namespace std;

string func1()
{
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "li si";
    js["msg"] = "hello ";

    string sendBuf = js.dump();

    return sendBuf;
}

string func2()
{
    json js;
    // 添加数组
    js["id"] = {1, 2, 3, 4, 5};
    // 添加key-value
    js["name"] = "zhang san";
    // 添加对象
    // js["msg"]["zhang san"] = "hello world";
    // js["msg"]["liu shuo"] = "hello china";
    // 上面等同于下面这句一次性添加数组对象
    js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello china"}};

    string jsbuf = js.dump();
    return jsbuf;
}

string  func3()
{
    json js;
    // 直接序列化一个vector容器
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);
    js["list"] = vec;
    // 直接序列化一个map容器
    map<int, string> m;
    m.insert({1, "黄山"});
    m.insert({2, "华山"});
    m.insert({3, "泰山"});
    js["path"] = m;

    string sendbuf = js.dump();
    return sendbuf;
}

int main()
{
    string recvbuf = func3();

    // 数据的反序列化  json字符串反序列化为 数据对象 
    json jsonbuf = json::parse(recvbuf);
    // cout << jsonbuf["msg_type"] << endl; 
    // cout << jsonbuf["from"] << endl; 
    // cout << jsonbuf["to"] << endl; 
    // cout << jsonbuf["msg"] << endl; 

    // cout << jsonbuf["name"] << endl;
    // string arr = jsonbuf["name"];
    // cout << arr << endl;
    // cout << arr[0] << endl;

    // auto msgjs = jsonbuf["msg"];
    // cout << msgjs["zhang san"] << endl;

    vector<int> vec = jsonbuf["list"]; 
    for (int &v : vec)
    {
        cout << v << " ";
    }
    cout << endl;

    map<int, string> mymap = jsonbuf["path"];
    for (auto &p : mymap)
    {
        cout << p.first <<" "<< p.second << endl;
    }
    return 0;

}