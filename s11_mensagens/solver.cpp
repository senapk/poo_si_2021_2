#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <sstream>
#include <tuple>
#include <algorithm>
using namespace std;

template <typename T>
using ptr = shared_ptr<T>;

//guardar o texto e o usuario
//Interface
class IMsg {
public:
    virtual string getSender() = 0;
    virtual string getText() = 0;
    virtual ~IMsg() {}
    friend ostream& operator<<(ostream& os, IMsg& msg);
};

ostream& operator<<(ostream& os, IMsg& msg) {
    os << msg.getSender() << ":" << msg.getText();
    return os;
}

class Msg : public IMsg {
    string sender;
    string text;
public:
    Msg(string sender, string text) {
        this->sender = sender;
        this->text = text;
    }
    virtual string getSender() override {
        return sender;
    }
    virtual string getText() override {
        return text;
    }
};

class MsgPremium : public Msg {
    bool read {false};
public:
    MsgPremium(string sender, string text) : Msg(sender, text) {}
    
    virtual string getText() override {
        read = true;
        return Msg::getText();
    }

    virtual string inspect() {
        return Msg::getText();
    }

    virtual bool getRead() {
        return read;
    }
};

//guardar, recuperar e enviar as mensagens
class User {
    string username;
protected:
    vector<ptr<IMsg>> inbox;
    vector<ptr<IMsg>> sent;
public:
    User(string username) : username(username) {}

    virtual void sendMsg(User* receiver, string text) {
        auto msg = make_shared<Msg>(this->username, text);
        receiver->inboxStore(msg);
        this->sent.push_back(msg);
    }

    virtual void inboxStore(ptr<IMsg> msg) {
        inbox.push_back(msg);
    }

    virtual string getInbox() {
        stringstream ss;
        for (auto msg : this->inbox)
            ss << *msg << endl;
        this->inbox.clear();
        return ss.str();
    }

    virtual string getSent() {
        stringstream ss;
        for (auto msg : this->sent)
            ss << *msg << endl;
        return ss.str();
    }
    virtual string getUsername() {
        return username;
    }
    virtual ~User() {}
};

class UserPremium : public User {
public:
    UserPremium(string username) : User(username) {}
    virtual void sendMsg(User* receiver, string text) {
        std::cout << "enviando message premium" << std::endl;
        auto msg = make_shared<MsgPremium>(this->getUsername(), text);
        receiver->inboxStore(msg);
        this->sent.push_back(msg);
    }

    virtual string getSent() {
        std::cout << "lendo mensagem premium" << std::endl;
        stringstream ss;
        for (auto msg : this->sent) {
            auto premium = dynamic_cast<MsgPremium*>(msg.get());
            if (premium) {
                ss << premium->getSender() << ":" << premium->inspect() 
                   << ":" << (premium->getRead() ? "lido" : "unread") << endl;
            } else {
                ss << *msg << endl;
            }
        }
        return ss.str();
    }
};

//encontrar e gerenciar os usuarios
class UserManager {
    map<string, ptr<User>> users;

public:
    UserManager() {}

    void addUser(ptr<User> user) {
        if (users.find(user->getUsername()) == users.end()) {
            users[user->getUsername()] = user;
        } else {
            throw runtime_error("User " + user->getUsername() + " already exists");
        }
    }

    string getUsernames() {
        string result;
        for (auto& user : users) {
            result += user.first + " ";
        }
        return result;
    }

    User* findUser(string username) {
        auto it = users.find(username);
        if (it == users.end())
            throw runtime_error("User " + username + " not found");
        return it->second.get();
    }

    void sendMsg(string sender, string receiver, string text) {
        auto senderUser = findUser(sender);
        auto receiverUser = findUser(receiver);
        senderUser->sendMsg(receiverUser, text);
    }
};

template <typename T>
T read(stringstream& ss) {
    T t;
    ss >> t;
    return t;
}

template <typename... Args>
auto parse(std::istream& is) {
    std::tuple<Args...> t;
    std::apply([&is](auto&&... args) {((is >> args), ...);}, t);
    return t;
}

int main(){
    UserManager um;

    while(true) {
        std::string line{}, cmd{};
        std::getline(std::cin, line);
        std::stringstream ss(line);
        ss >> cmd;
        std::cout << "$" << line << '\n';
        try{
            if (cmd == "end") {
                break;
            } else if (cmd == "show") {
                cout << um.getUsernames() << endl;
            } else if (cmd == "add") {
                um.addUser(make_shared<User>(read<string>(ss)));
            } else if (cmd == "premium") {
                um.addUser(make_shared<UserPremium>(read<string>(ss)));
            } else if (cmd == "send") {//sender receiver texto a ser enviado
                string sender = read<string>(ss);
                string receiver = read<string>(ss);
                string text{};
                getline(ss, text);
                um.sendMsg(sender, receiver, text.substr(1));
            } else if (cmd == "sent") {
                cout << um.findUser(read<string>(ss))->getSent() << endl;
            } else if (cmd == "inbox") {
                cout << um.findUser(read<string>(ss))->getInbox() << endl;
            } else {
                std::cout << "fail: comando invalido" << '\n';
            }
        } catch (const std::exception& e) {
            std::cout << "fail: " << e.what() << '\n';
        }
    }
    return 0;
}

// int main() {
//     Msg msg("user1", "hello");
//     cout << msg << endl;
// }

/*
add maria
premium musk
send maria musk voce gosta de xilito?
inbox musk
sent maria
inbox musk
sent maria







*/