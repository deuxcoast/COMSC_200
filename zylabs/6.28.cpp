#include <iostream>
#include <vector>
using namespace std;

size_t ARR_SIZE{5};
void GetUserInput(vector<int>& jersey_vec, vector<int>& rating_vec);
void OutputRoster(const vector<int>& jersey_vec, const vector<int>& rating_vec);

void GetUserInput(vector<int>& jersey_vec, vector<int>& rating_vec) {
    for (size_t i{}; i < jersey_vec.size(); i++) {
        cout << "Enter player " << i + 1 << "'s jersey number:" << endl;
        cin >> jersey_vec.at(i);

        cout << "Enter player " << i + 1 << "'s rating:" << endl;
        cin >> rating_vec.at(i);
        cout << endl;
    }
}

void OutputRoster(const vector<int>& jersey_vec,
                  const vector<int>& rating_vec) {
    cout << "ROSTER" << endl;
    for (size_t i{}; i < jersey_vec.size(); i++) {
        cout << "Player " << i + 1;
        cout << " -- ";
        cout << "Jersey number: " << jersey_vec.at(i) << ", ";
        cout << "Rating: " << rating_vec.at(i) << endl;
    }
}

void OutputMenu() {
    cout << endl;
    cout << "MENU" << endl;
    cout << "a - Add player" << endl;
    cout << "d - Remove player" << endl;
    cout << "u - Update player rating" << endl;
    cout << "r - Output players above a rating" << endl;
    cout << "o - Output roster" << endl;
    cout << "q - Quit" << endl;

    cout << endl << "Choose an option:" << endl;
}

void AddPlayer(vector<int>& jersey_vec, vector<int>& rating_vec) {
    cout << "Enter a new player's jersey number:" << endl;
    int jersey_num{};
    cin >> jersey_num;
    jersey_vec.push_back(jersey_num);

    cout << "Enter the player's rating:" << endl;
    int rating_num{};
    cin >> rating_num;
    rating_vec.push_back(rating_num);
}

void DeletePlayer(vector<int>& jersey_vec, vector<int>& rating_vec) {
    cout << "Enter a jersey number" << endl;
    int jersey_num{};
    cin >> jersey_num;

    for (size_t i{}; i < jersey_vec.size(); i++) {
        if (jersey_vec.at(i) == jersey_num) {
            int idx = static_cast<int>(i);
            jersey_vec.erase(jersey_vec.begin() + idx);
            rating_vec.erase(rating_vec.begin() + idx);
        }
    }
}

void UpdatePlayer(vector<int>& jersey_vec, vector<int>& rating_vec) {
    int jersey_num{};
    int rating_num{};
    cout << "Enter a jersey number" << endl;
    cin >> jersey_num;
    cout << "Enter a new rating for player:" << endl;
    cin >> rating_num;

    for (size_t i{}; i < jersey_vec.size(); i++) {
        if (jersey_vec.at(i) == jersey_num) {
            jersey_vec.at(i) = jersey_num;
            rating_vec.at(i) = rating_num;
        }
    }
}

void OutputAbove(vector<int>& jersey_vec, vector<int>& rating_vec) {
    int rating_threshold{};
    cout << "Enter a rating:" << endl;
    cin >> rating_threshold;
    cout << endl;
    cout << "ABOVE " << rating_threshold << endl;

    for (size_t i{}; i < rating_vec.size(); i++) {
        if (rating_vec.at(i) > rating_threshold) {
            cout << "Player " << i + 1;
            cout << " -- ";
            cout << "Jersey number: " << jersey_vec.at(i) << ", ";
            cout << "Rating: " << rating_vec.at(i) << endl;
        }
    }
}
void ExecuteMenu(vector<int>& jersey_vec, vector<int>& rating_vec) {
    char userMenuSelection{};

    while (userMenuSelection != 'q') {
        OutputMenu();
        cin >> userMenuSelection;

        switch (userMenuSelection) {
            case 'a':
                AddPlayer(jersey_vec, rating_vec);
                break;
            case 'd':
                DeletePlayer(jersey_vec, rating_vec);
                break;
            case 'u':
                UpdatePlayer(jersey_vec, rating_vec);
                break;
            case 'r':
                OutputAbove(jersey_vec, rating_vec);
                break;
            case 'o':
                OutputRoster(jersey_vec, rating_vec);
                break;
            case 'q':
                break;
            default:
                continue;
        }
    }
}

int main() {
    vector<int> jersey_vec(ARR_SIZE);
    vector<int> rating_vec(ARR_SIZE);

    GetUserInput(jersey_vec, rating_vec);
    OutputRoster(jersey_vec, rating_vec);
    ExecuteMenu(jersey_vec, rating_vec);
}
