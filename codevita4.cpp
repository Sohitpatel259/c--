// Tina planned to travel from city A to city B, but unfortunately, due to a strike on that day, many flights were cancelled, with only a few flights still in operation. As always, she aimed to spend as little money as possible while reaching city B within the allotted time.

// Considering the available flights between each pair of cities, their take-off and landing times, ticket costs, and the time intervals in which she prefers to travel, determine the minimum amount she needs to spend to reach city B from city A.

// Constraints
// 1 <= N <= 50

// 1 <= cost of ticket <= 10000

// Her journey will be completed on the same day and won't extend past 11:59 Pm.

// Hours and minutes will be represented as two-digit numbers, with a leading zero if necessary.

// There will be more than one flight between two cities with different timings and / or costs.

// Assume that flights are always on time and are never delayed.

// Ignore switch-over time between flights at an in-transit location i.e. assume it to be zero.

// Input
// First line consists of N, denoting the total number of flights operating on that day in different locations.

// Next N lines consist of five space separated elements in the format "from to take-off landing cost" where,

// from - the departure location of the flight i.e. City A

// to - the destination location of the flight i.e. City B

// take-off - the time the flight departs

// landing - the time the flight arrives

// cost - the ticket price

// Output
// Print a single integer representing the minimum cost Tina needs to spend to travel from city A to city B. If she cannot reach the city B, print "Impossible".

// Time Limit (secs)
// 1

// Examples
// Example 1

// Input

// 8

// Mumbai Delhi 03:00Pm 05:00Pm 3300

// Ahmedabad Delhi 05:50Pm 06:45Pm 2000

// Hyderabad Mumbai 02:00Pm 03:30Pm 2100

// Kochi Bhubaneswar 12:00Pm 02:00Pm 4400

// Chennai Delhi 04:00Pm 07:00Pm 8500

// Mumbai Ahmedabad 04:00Pm 05:45Pm 2700

// Chennai Hyderabad 12:00Pm 01:45Pm 1500

// Hyderabad Mumbai 10:00Am 12:00Pm 4500

// Chennai Delhi

// 11:00Am 07:00Pm

// Output

// 8300

// Explanation

// Tina needs to travel from Chennai to Delhi and her preferred time of travel is between 11 AM and 7 PM. This means that first flight should leave from Chennai after 10:59 Am and she should be in Delhi no later than 7 PM.

// While there are several routes from Chennai to Delhi, the path Chennai -> Hyderabad -> Mumbai -> Ahmedabad -> Delhi offers a lower cost and falls within the given time constraints.

// Example 2

// Input

// 5

// Trichy Kochi 08:00Am 09:30Am 5400

// Kashmir Kanyakumari 11:30Am 03:00Pm 10000

// Chennai Kanyakumari 02:30Pm 03:30Pm 2500

// Kashmir Chennai 10:00Am 12:00Pm 8500

// Mumbai Bengaluru 12:00Am 02:00Am 4300

// Kashmir Kanyakumari

// 06:00Am 08:00Pm

// Output

// 10000

// Explanation

// Tina needs to travel from Kashmir to Kanyakumari and her preferred time of travel is between 06 AM and 8 PM. This means that first flight should leave from Kashmir after 5:59 Am and she should be in Kanyakumari no later than 7 PM.

// While there are several routes from Kashmir to Kanyakumari, the direct path Kashmir -> Kanyakumari offers a lower cost and falls within the given time constraints.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits.h>

using namespace std;

struct Flight {
    string from, to;
    int takeOffTime, landingTime, cost;
};

int timeToMinutes(const string &time) {
    int hours, minutes;
    char ampm;
    sscanf(time.c_str(), "%d:%d%c", &hours, &minutes, &ampm);
    if (ampm == 'P' && hours != 12) hours += 12;
    if (ampm == 'A' && hours == 12) hours = 0;
    return hours * 60 + minutes;
}

struct CityInfo {
    int cost, time;
    bool operator>(const CityInfo& other) const {
        return cost > other.cost;  // For Dijkstra's algorithm, we use min-heap by cost
    }
};

int main() {
    int N;
    cin >> N;
    vector<Flight> flights;

    // Read flights
    for (int i = 0; i < N; i++) {
        string from, to, takeOff, landing;
        int cost;
        cin >> from >> to >> takeOff >> landing >> cost;
        flights.push_back({from, to, timeToMinutes(takeOff), timeToMinutes(landing), cost});
    }

    string startCity, endCity, preferredStart, preferredEnd;
    cin >> startCity >> endCity >> preferredStart >> preferredEnd;
    int startTime = timeToMinutes(preferredStart);
    int endTime = timeToMinutes(preferredEnd);

    // Min-heap priority queue (Dijkstra's style)
    priority_queue<CityInfo, vector<CityInfo>, greater<CityInfo>> pq;
    unordered_map<string, int> minCost;
    
    // Initialize the start city with 0 cost and startTime
    pq.push({0, startTime});  // {cost, time}
    minCost[startCity] = 0;

    // Process the queue
    while (!pq.empty()) {
        // Extract the top element from the priority queue
        CityInfo current = pq.top();
        pq.pop();
        
        int currentCost = current.cost;  // The cost to reach the current city
        int currentTime = current.time;  // The current time after taking the flight

        // If we reached the destination city and within the valid time
        if (currentCost <= endTime) {
            cout << currentCost << endl;
            return 0;
        }

        // Traverse all the flights
        for (const auto& flight : flights) {
            if (flight.from == startCity) {
                if (currentTime <= flight.takeOffTime && currentTime <= endTime) {
                    int newCost = currentCost + flight.cost;
                    if (newCost < minCost[flight.to]) {
                        pq.push({newCost, flight.landingTime});
                        minCost[flight.to] = newCost;
                    }
                }
            }
        }
    }

    // If no path is found
    cout << "Impossible" << endl;
    return 0;
}
