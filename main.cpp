#include <iostream>
#include <memory>
#include <vector>


using namespace std;


class Subscriber
{
    public:
        virtual void update_status(string status) = 0;
};

class WhatsappClient : public Subscriber
{
    public:
        WhatsappClient(string name)
        : _name{name} {}

        void update_status(string status)
        {
            cout << "Client received message via whatsapp: " << status << endl;
        }

    private:
        string _name;
};

class InstagramClient : public Subscriber
{
    public:
        InstagramClient(string name)
        : _name{name} {}

        void update_status(string status)
        {
            cout << "Client received message via instagram: " << status << endl;
        }

    private:
        string _name;
};

class FacebookClient : public Subscriber
{
    public:
        FacebookClient(string name)
        : _name{name} {}

        void update_status(string status)
        {
            cout << "Client received message via facebook: " << status << endl;
        }

    private:
        string _name;
};

class MasterBaker : public Subscriber
{
    public:
        MasterBaker(string name)
        : _name{name} {}

        void update_status(string status)
        {
            cout << "Master Baker received message: " << status << endl;
        }

    private:
        string _name;
};

class NotificationSender
{
    public:

        NotificationSender() {};

        void set_product_status(string product_status)
        {
            _product_status = product_status;
            sendNotification();
        }

        void sendNotification()
        {
            for (const auto& subscriber : _subscribers )
            {
                subscriber->update_status(_product_status);
            }
        }

        void add_subscriber(shared_ptr<Subscriber> subscriber)
        {
            _subscribers.push_back(subscriber);
        }

    private:
        string _product_status;
        vector<shared_ptr<Subscriber>> _subscribers;
};

class Article
{
    public:
        Article(string name)
        : _name{name} {}

    private:
        string _name;
        double price;

};

class Sender
{
    public:
        Sender(string name)
        : _name{name} {}

    private:
        string _name;
};

class Order
{
    public:
        Order(int code)
        : _code{code} {}

    void sendNotification()
    {

    }

    void setClient(shared_ptr<Subscriber> client)
    {
        _client = client;
    }

    void setMasterBaker(shared_ptr<MasterBaker> masterBaker)
    {
        _masterBaker = masterBaker;
    }

    void addArticle(shared_ptr<Article> article)
    {
        _articles.push_back(article);
    }

    private:
        int _code;
        shared_ptr<Subscriber> _client;
        shared_ptr<MasterBaker> _masterBaker;
        shared_ptr<Sender> _sender;
        vector<shared_ptr<Article>> _articles;
};


int main()
{

    auto notification_sender = make_shared<NotificationSender>();

    auto master_baker_1 = make_shared<MasterBaker>("Jose");
    auto customer_1 = make_shared<WhatsappClient>("Eduardo");

    notification_sender->set_product_status("Meep");

    notification_sender->add_subscriber(customer_1);

    notification_sender->sendNotification();

    return 0;
}