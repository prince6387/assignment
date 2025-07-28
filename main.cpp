#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include "json.hpp" // nlohmann/json

using json = nlohmann::json;
using namespace std;

typedef long long ll;

// Convert string in given base to decimal
ll baseToDecimal(const string& val, int base) {
    ll result = 0;
    for (size_t i = 0; i < val.length(); ++i) {
        char c = val[i];
        int digit = isdigit(c) ? c - '0' : tolower(c) - 'a' + 10;
        result = result * base + digit;
    }
    return result;
}

// Lagrange interpolation to compute f(0) from k points
double lagrangeInterpolation(const vector<pair<int, ll>>& points) {
    double result = 0.0;
    int k = points.size();

    for (int i = 0; i < k; ++i) {
        double xi = points[i].first;
        double yi = static_cast<double>(points[i].second);
        double term = yi;

        for (int j = 0; j < k; ++j) {
            if (i != j) {
                double xj = points[j].first;
                term *= (-xj) / (xi - xj);
            }
        }

        result += term;
    }

    return round(result);
}

// Read and parse JSON file, return first k (x, y) decoded points
vector<pair<int, ll>> parseJsonFile(const string& filename, int& k_out) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Cannot open file: " << filename << endl;
        exit(1);
    }

    json data;
    file >> data;
    file.close();

    int k = data["keys"]["k"];
    k_out = k;

    vector<pair<int, ll>> points;
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (it.key() == "keys") continue;
        if (points.size() >= k) break;

        int x = stoi(it.key());
        int base = stoi(it.value()["base"].get<string>());
        string val = it.value()["value"];

        ll y = baseToDecimal(val, base);
        points.push_back(make_pair(x, y));
    }

    return points;
}

int main() {
    int k1, k2;

    // Read and decode points from both JSON files
    vector<pair<int, ll>> points1 = parseJsonFile("test1.json", k1);
    vector<pair<int, ll>> points2 = parseJsonFile("test2.json", k2);

    // Apply Lagrange interpolation to find secret (f(0))
    ll secret1 = static_cast<ll>(lagrangeInterpolation(points1));
    ll secret2 = static_cast<ll>(lagrangeInterpolation(points2));

    // Print results
    cout << "Secret of Test Case 1: " << secret1 << endl;
    cout << "Secret of Test Case 2: " << secret2 << endl;

    return 0;
}
