#include <vector>
#include <string>
using namespace std;
struct dbSettings {
    string_view db_name;
    int db_connection_timeout;
    bool db_allow_exceptions;
    DBLogLevel db_log_level;
};

vector<Person> LoadPersons(
    dbSettings settings, int min_age, int max_age, string_view name_filter) {
    DBConnector connector(settings.db_allow_exceptions, settings.db_log_level);
    DBHandler db;
    if (settings.db_name.starts_with("tmp."s)) {
        db = connector.ConnectTmp(settings.db_name, settings.db_connection_timeout);
    }
    else {
        db = connector.Connect(settings.db_name, settings.db_connection_timeout);
    }
    if (!settings.db_allow_exceptions && !db.IsOK()) {
        return {};
    }

    ostringstream query_str;
    query_str << "from Persons "s
        << "select Name, Age "s
        << "where Age between "s << min_age << " and "s << max_age << " "s
        << "and Name like '%"s << db.Quote(name_filter) << "%'"s;
    DBQuery query(query_str.str());

    vector<Person> persons;
    for (auto [name, age] : db.LoadRows<string, int>(query)) {
        persons.push_back({ move(name), age });
    }
    return persons;
}