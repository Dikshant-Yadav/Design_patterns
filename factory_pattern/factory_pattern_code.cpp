#include <bits/stdc++.h>
using namespace std;

class database_conn
{
public:
    virtual void dosomething() = 0;
    virtual ~database_conn() {} 
};


class sqlconn : public database_conn
{
public:
    void dosomething() override
    {
        cout << "you got sql connection" << endl;
    }
};


class mongoconn : public database_conn
{
public:
    void dosomething() override
    {
        cout << "you got mongo connection" << endl;
    }
};


class postgresqlconn : public database_conn
{
public:
    void dosomething() override
    {
        cout << "you got postgresql connection" << endl;
    }
};


class dbconn_factory
{
    string namedb;
    database_conn *conn1;

public:
    database_conn *makeconn(string namedb)
    {
        if (namedb == "sql")
        {
            return new sqlconn();
        }
        if (namedb == "postgresql")
        {
            return new postgresqlconn();
        }
        if (namedb == "mongo")
        {
            return new mongoconn();
        }
        return nullptr;
    }
};



int main()
{
    dbconn_factory *factory1 = new dbconn_factory();
    database_conn *myconn;
    string s = "sql";
    myconn = factory1->makeconn(s);
    myconn->dosomething();
    delete myconn; 
    
    s = "mongo";
    myconn = factory1->makeconn(s);
    myconn->dosomething();
    delete myconn; 
    
    s = "postgresql";
    myconn = factory1->makeconn(s);
    myconn->dosomething();
    delete myconn; 
    
    delete factory1; 
    
    return 0;
}
