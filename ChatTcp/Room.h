#pragma once
#include <string>
#include <vector>
#include "socket_compat.h"
using namespace std;
struct Room {
    string name;
    string password;
    int maxUsers;
    vector<pair<socket_t, string>> clients;
};

void addClient(Room& room, socket_t client, const string& name);
void removeClient(Room& room, socket_t client);
void broadcast(Room& room, const string& msg, socket_t sender = invalid_socket_v);