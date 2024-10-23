/*
 
 
* @file: [E][H2329] [Pro] Electronic Bulletin Board
 
 
* @brief: Sample Answer
 
 
* @copyright: All rights reserved (c) 2023 Samsung Electronics, Inc.
 
 
*/
 
 
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <cstring>
 
 
using namespace std;
 
 
#define MAXL    (10)
 
 
struct User
{
    char name[MAXL + 1];
    int total;
     
    void init(char *str)
    {
        strcpy(name, str);
        total = 0;
    }
};
 
 
struct Comp4User
{
    bool operator() (pair<int, User*> a, pair<int, User*> b)
    {
        return a.first != b.first ? a.first < b.first : strcmp(a.second->name, b.second->name) > 0;
    }
};
 
 
priority_queue<pair<int, User*>, vector<pair<int, User*>>, Comp4User> pqu;
 
 
int userCnt;
User userlist[10000];
 
 
User* getUser()
{
    return &userlist[userCnt++];
}
 
 
unordered_map<string, User*> cdb;
 
 
struct Message
{
    int id;
    User* user;
     
    Message* parent;
    vector<Message*> comments;
     
    Message* main;
     
    int point;
    int total;
 
 
    bool alive;
     
    void init(int _id, int _point, User* _user, Message* _parent = nullptr)
    {
        id = _id;
        point = total = _point;
 
 
        user = _user;
        user->total += point;
 
 
        comments.clear();
         
        parent = _parent;
        if (parent != nullptr)
        {
            parent->add(this, point);
            main = parent->main;
        }
        else
        {
            main = this;
        }
 
 
        alive = true;
    }
     
    void add(Message* comment, int addpoint)
    {
        comments.push_back(comment);
 
 
        Message* ptr = this;
        while (ptr != nullptr)
        {
            ptr->total += addpoint;
            ptr = ptr->parent;
        }
    }
     
    void remove()
    {
        if (!alive) return;
 
 
        alive = false;
                 
        user->total -= point;
        pqu.push({user->total, user});
         
        for (auto p : comments)
            p->remove();
    }
     
    void erase()
    {
        remove();
 
 
        int delpoint = total;
         
        Message* ptr = this;
        while (ptr != nullptr)
        {
            ptr->total -= delpoint;
            ptr = ptr->parent;
        }
    }
 
 
};
 
 
struct Comp4Message
{
    bool operator() (pair<int, Message*> a, pair<int, Message*> b)
    {
        return a.first != b.first ? a.first < b.first : a.second->id > b.second->id;
    }
};
 
 
priority_queue<pair<int, Message*>, vector<pair<int, Message*>>, Comp4Message> pqm;
 
 
int messageCnt;
Message messagelist[50001];
 
 
Message* getMessage()
{
    return &messagelist[messageCnt++];
}
 
 
unordered_map<int, Message*> mdb;
 
 
User* findUser(char user[])
{
    string str(user);
    User* obj = cdb[str];
 
 
    if (obj == nullptr)
    {
        obj = getUser();
        obj->init(user);
        cdb[str] = obj;
    }
 
 
    return obj;
}
 
 
void init()
{
    userCnt = messageCnt = 0;
     
    while (!pqu.empty()) pqu.pop();
    while (!pqm.empty()) pqm.pop();
 
 
    cdb.clear();
    mdb.clear();
}
 
 
int writeMessage(char mUser[], int mID, int mPoint)
{
    User* obj = findUser(mUser);
    Message* ptr = getMessage();
 
 
    ptr->init(mID, mPoint, obj);
    mdb[mID] = ptr;
     
    pqu.push({obj->total, obj});
    pqm.push({ptr->total, ptr});
 
 
    return obj->total;
}
 
 
int commentTo(char mUser[], int mID, int mTargetID, int mPoint)
{
    User* obj = findUser(mUser);
    Message* ptr = getMessage();
    Message* par = mdb[mTargetID];
 
 
    ptr->init(mID, mPoint, obj, par);
    mdb[mID] = ptr;
     
    ptr = ptr->main;
    pqu.push({obj->total, obj});
    pqm.push({ptr->total, ptr});
 
 
    return ptr->total;
}
 
 
int erase(int mID)
{
    Message* ptr = mdb[mID];
 
 
    ptr->erase();
 
 
    pqm.push({ptr->main->total, ptr->main});
 
 
    return ptr->parent == nullptr ? ptr->user->total : ptr->main->total;
}
 
 
void getBestMessages(int mBestMessageList[])
{
    int cnt = 0;
    Message* msglist[5];
     
    while (cnt < 5)
    {
        int total = pqm.top().first;
        Message* ptr = pqm.top().second;
         
        pqm.pop();
         
        if (ptr->alive == false || ptr->total != total || (cnt > 0 && msglist[cnt - 1] == ptr))
            continue;
         
        msglist[cnt] = ptr;
        mBestMessageList[cnt++] = ptr->id;
    }
     
    for (int i = 0; i < 5; ++i)
        pqm.push({msglist[i]->total, msglist[i]});
}
 
 
void getBestUsers(char mBestUserList[][MAXL + 1])
{
    int cnt = 0;
    User* userlist[5];
     
    while (cnt < 5)
    {
        int total = pqu.top().first;
        User* obj = pqu.top().second;
 
 
        pqu.pop();
         
        if (obj->total != total || (cnt > 0 && userlist[cnt - 1] == obj))
            continue;
         
        userlist[cnt] = obj;
        strcpy(mBestUserList[cnt++], obj->name);
    }
     
    for (int i = 0; i < 5; ++i)
        pqu.push({userlist[i]->total, userlist[i]});
}