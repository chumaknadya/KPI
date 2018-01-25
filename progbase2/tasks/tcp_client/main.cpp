#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <iostream>
#include "progbase-cpp/net.h"
#include <QString>
#include <QDebug>
#include <vector>



using namespace std;
using namespace progbase::net;

void print_array(vector<int> array) {
    int curr;
    for(vector<int>::iterator it = array.begin(); it != array.end(); ++it) {
          curr = *it;
          cout << curr << " ";
    }
    cout << " " <<endl;

}
vector<int> task_for_input_vector_of_integers(vector <int> array,vector<int> newArray) {
    cout << "Сформувати новий вектор цілих числел, що містить попарні суми сусідніх елементів вхідного вектора" <<endl;
    for (int i = 0;i < array.size();i++) {
        if ( i == 0) {
               newArray.push_back(array.at(i+1));
         } else if(i == array.size()-1) {
               newArray.push_back(array.at(i-1));
         } else {
               newArray.push_back(array.at(i+1) + array.at(i-1));
         }
    }
    cout << " " <<endl;

    return newArray;
}

vector<int> JsonLoader_loadFromString(const QString & jsonString,vector<int> array_of_int) {

     QJsonDocument jdoc = QJsonDocument::fromJson(jsonString.toUtf8());
     QJsonObject root = jdoc.object();
     if (root.value("status").toBool()) {
          QJsonValue datav = root.value("data");
          if(datav.isArray()){
                QJsonArray array = datav.toArray();
                for (auto item : array) {
                    array_of_int.push_back(item.toInt());
                }

          }
       } else {
           cout << root.value("error").toString().toStdString() << "  " << endl;
       }


     return array_of_int;
}

int main() {

       TcpClient client;
       NetMessage message(100);
       string data;
       try {
           client.connect(IpAddress("127.0.0.1", 3777));
           cout << ">> Please input string" << endl;
           string request;
           cin >> request;
           message.setDataString(request);
           client.send(message);
           cout << ">> Request sent" << endl;
           do {
               client.receive(message);
               std::string str = message.dataAsString();
               data += str;
               cout << ">> Received " << str.length() << " bytes: " << endl << str << endl;
           } while (!message.isEmpty());
       } catch(NetException const & exc) {
           cerr << exc.what() << endl;
       }
       QString jsonString = QString::fromStdString(data);
       vector<int>array_from_recieve_message;
       array_from_recieve_message = JsonLoader_loadFromString(jsonString,array_from_recieve_message);
       print_array(array_from_recieve_message);
       if (array_from_recieve_message.size() != 0) {
               vector<int> newArrayOfIntegers;
               newArrayOfIntegers = task_for_input_vector_of_integers(array_from_recieve_message,newArrayOfIntegers);
               print_array(newArrayOfIntegers);
               newArrayOfIntegers.clear();
       }


       array_from_recieve_message.clear();

    return 0;
}
