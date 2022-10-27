#include <iostream>
// include additional necessary headers
#include <string> // string
#include <iostream> // cout, endl
#include <thread> // thread, join
#include <stdlib.h> // atoi
#include <vector> // vector

using namespace std;

void query(int n) {
    // Should print: the print number (starting from 0), "SYN", and the three dots "..."
    cout << "[" << n <<"] SYN ... ";
}

void response() {
    // Should print "ACK"
    cout << "ACK" << endl;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: ./handshake <count>\n");
        exit(1);
    }

    /**
     * Steps to follow:
     * 1. Get the "count" from cmd args
     * 2. Create necessary synchronization primitive(s)
     * 3. Create two threads, one for "SYN" and the other for "ACK"
     * 4. Provide the threads with necessary args
     * 5. Update the "query" and "response" functions to synchronize the output
    */

    int count = atoi(argv[1]);
    vector<thread> t_vec;

    for (int i = 0; i < count; i++) {
        t_vec.push_back(thread(query, i));
        t_vec.push_back(thread(response));
    }

    for (int i=0; i < t_vec.size(); i++) {
        t_vec.at(i).join();
    }

    return 0;
}