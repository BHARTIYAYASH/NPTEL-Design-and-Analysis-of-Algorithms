#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Event {
    int start;
    int duration;
    int end;
};

bool compareByEndDate(const Event &a, const Event &b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;
    
    vector<Event> events(n);
    
    for (int i = 0; i < n; i++) {
        cin >> events[i].start >> events[i].duration;
        events[i].end = events[i].start + events[i].duration - 1;
    }
    
    sort(events.begin(), events.end(), compareByEndDate);
    
    int count = 0;
    int lastEndDate = 0;
    
    for (int i = 0; i < n; i++) {
        if (events[i].start > lastEndDate) {
            count++;
            lastEndDate = events[i].end;
        }
    }
    
    cout << count << endl;
    
    return 0;
}