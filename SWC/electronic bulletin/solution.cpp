// TODO: replace queue to vector to store childs
#define MAXL    (10)
#include <string>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;


struct user {
    string name;
    int point;
};

struct message {
    int id;
    int id_post; // if message id is a post, id_post is zero
    string user;
    int point;
	int point_alone;
	vector<int> childs;
};


struct cmpU {
    bool operator() (user a, user b) const {
        if(a.point == b.point) return a.name < b.name;
        else return a.point > b.point;
    }
};


struct cmpM {
    bool operator() (message a, message b) const {
        if(a.point == b.point) return a.id < b.id;
        else return a.point > b.point;
    }
};

unordered_map<string, user> user_map;
unordered_map<int, message> message_map;
set<user, cmpU> top_user;
set<message, cmpM> top_message;

int editPointUser(user u, int p) {
	string name = u.name;
	top_user.erase(u);
	u.point = u.point + p;
	user_map[name] = u;
	top_user.insert(u);

	return u.point;
}

int editPointPost(message m, int p) {
	int id = m.id;
	top_message.erase(m);
	m.point = m.point + p;
	message_map[id] = m;
	top_message.insert(m);

	return m.point;
}

void removeCommentOrReply(message m) {
	int point_alone = m.point_alone;
	int id = m.id;
	user writer = user_map[m.user];
	message target = message_map[m.id_post];
	message post;
	if(target.id_post == 0) {
		post = target;
	} else {
		post = message_map[target.id_post];
	}
	editPointPost(post, -point_alone);
	editPointUser(writer, -point_alone);
	while(!message_map[id].childs.empty()) {
		message rep = message_map[message_map[id].childs.front()];
		int rep_point = rep.point_alone;
		editPointPost(message_map[post.id], -rep_point);
		editPointUser(user_map[post.user], -rep_point);
		message_map[id].childs.pop();
	}

	
	
}

void init()
{
    user_map.clear();
    message_map.clear();
    top_user.clear();
    top_message.clear();
    return;
}


int writeMessage(char mUser[], int mID, int mPoint)
{  
    string name = mUser;
    int ret = 0;
    if(user_map.find(name) == user_map.end()) {
        user new_user;
        new_user.name = name;
        new_user.point = mPoint;
       
        user_map[name] = new_user;


        top_user.insert(new_user);
        ret = mPoint;
    } else {
		ret = editPointUser(user_map[name], mPoint);
    }
   
    message new_message;
    new_message.id = mID;
    new_message.id_post = 0;
    new_message.user = name;
    new_message.point = mPoint;
	new_message.point_alone = mPoint;


    message_map[mID] = new_message;
    top_message.insert(new_message);
   
	cout << "writemessage: " << ret << endl;
    return ret;
}


int commentTo(char mUser[], int mID, int mTargetID, int mPoint)
{
	string name = mUser;
	
	if(user_map.find(name) == user_map.end()) {
        user new_user;
        new_user.name = name;
        new_user.point = mPoint;
       
        user_map[name] = new_user;

        top_user.insert(new_user);
    } else {
        editPointUser(user_map[name], mPoint);
    }

	message target_message = message_map[mTargetID];
	message_map[mTargetID].childs.push(mID);

	int ret = 0;
	message post;
	if(target_message.id_post == 0) {
		ret = editPointPost(target_message, mPoint);		
	} else {
		post = message_map[target_message.id_post];
		ret = editPointPost(post, mPoint);
	}

	message new_message;
	new_message.id = mID;
    new_message.id_post = mTargetID;
    new_message.user = name;
    new_message.point = 0;
	new_message.point_alone = mPoint;

    message_map[mID] = new_message;

	cout << "commentto: " << ret << endl;
    return ret;
}


int erase(int mID)
{
	int ret = 0;
	message delete_message = message_map[mID];
	user writer = user_map[delete_message.user];
	string name = writer.name;
	int point_alone = delete_message.point_alone;
	
	
	if(delete_message.id_post == 0) {
		cout << "previous user point" << user_map[name].point << ", ";
		editPointUser(writer, -point_alone);
		top_message.erase(delete_message);
		
		while(!message_map[mID].childs.empty()) {
			message com = message_map[message_map[mID].childs.front()];
			int com_id = com.id;
			cout << com.user;
			editPointUser(user_map[com.user], -com.point_alone);
			message_map[mID].childs.pop();

			while(!message_map[com_id].childs.empty()) {
				message rep = message_map[message_map[com_id].childs.front()];
				editPointUser(user_map[rep.user], -rep.point_alone);
				message_map[com_id].childs.pop();
		}	
		}
		ret = user_map[name].point;
	} else {
		cout << "previous post point" << message_map[delete_message.id_post].point << ", ";
		removeCommentOrReply(message_map[mID]);
		ret = message_map[delete_message.id_post].point;
	}
	cout << "erase: " << ret << endl;
	return ret;
}


void getBestMessages(int mBestMessageList[])
{
	set<message, cmpM>::iterator itr = top_message.begin();
	int i=0;
	while(i<5) {
		int id = itr->id;
		mBestMessageList[i] = id;
		cout << id << " " << itr->point << endl;
		i++;
		itr++;
	}
    return;
}


void getBestUsers(char mBestUserList[][MAXL + 1])
{
	set<user, cmpU>::iterator itr = top_user.begin();
	int i=0;
	while(i<5) {
		string name = itr->name;
		cout << name << " " << itr-> point << endl;
		for(int j = 0; j < name.length(); j++) {
			mBestUserList[i][j] = name[j];
		}

		i++;
		itr++;
	}

    return;
}

