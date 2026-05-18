#include "Room.h"
#include <algorithm>
using namespace std;

void addClient(Room& room, socket_t client, const string& name) {
    room.clients.push_back({ client, name });
}

void removeClient(Room& room, socket_t client) {
    room.clients.erase(
        remove_if(room.clients.begin(), room.clients.end(),
            [client](auto& p) { return p.first == client; }),
        room.clients.end()
    );
}

void broadcast(Room& room, const string& msg, socket_t sender) {
    for (size_t i = 0; i < room.clients.size(); ++i) {
        socket_t c = room.clients[i].first;
        if (c != sender) {
            send(c, msg.c_str(), static_cast<int>(msg.size()), 0);
        }
    }
}