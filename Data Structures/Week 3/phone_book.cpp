#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>

using std::string;
using std::vector;
using std::cin;
using std::set;

struct Query {
    string type, name;
    int number;
    bool operator<(const Query& Q) const
    {
        return number < Q.number;
    }
    bool operator>(const Query& Q) const
    {
        return number > Q.number;
    }
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}
vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    std::unordered_map<int, string> contacts;
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {

            contacts[queries[i].number] = queries[i].name;

        } else if (queries[i].type == "del") {
            contacts.erase(queries[i].number);
        } else {
            string response = "not found";
            if (contacts.count(queries[i].number))
            {
                response = contacts[queries[i].number];
            }
            result.push_back(response);
        }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
