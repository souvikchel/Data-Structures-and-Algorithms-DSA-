#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void printItinerary(unordered_map<string, string> tickets) {
    // Step 1: Store all destination cities
    unordered_set<string> to;

    for (pair<string, string> ticket : tickets) { // (from -> to)
        to.insert(ticket.second);
    }

    // Step 2: Find starting point (which is not in "to" set)
    string start = "";
    for (pair<string, string> ticket : tickets) {
        if (to.find(ticket.first) == to.end()) { // starting point
            start = ticket.first;
            break;
        }
    }

    // Step 3: Print itinerary
    cout << start << " -> ";
    while (tickets.count(start)) {
        cout << tickets[start] << " -> ";
        start = tickets[start];
    }

    cout << "destination" << endl;
}

int main() {
    unordered_map<string, string> tickets;

    // Example input
    tickets["Chennai"] = "Bangalore";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";

    printItinerary(tickets);

    return 0;
}