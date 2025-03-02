#include <cctype>
#include <iostream>
#include <string>
using namespace std;

enum class MenuOpts {
    InvalidChoice,
    GetNumOfNonWSCharacters,
    GetNumOfWords,
    FindText,
    ReplaceExclamation,
    ShortenSpace,
    Quit,
};

void GetUserInput(string& userText);
void PrintMenu();
MenuOpts ValidateMenuChoice(char userChoice);
void ExecuteMenu(char userChoice, string& userText);

int GetNumOfNonWSCharacters(const string userText);
int GetNumOfWords(const string userText);
int FindText(string find, string userText);
void ReplaceExclamation(string& userText);
void ShortenSpace(string& userText);

/* Define your functions here. */
void GetUserInput(string& userText) {
    cout << "Enter a sample text:" << endl;

    getline(cin, userText);
    cout << endl << "You entered: " << userText << endl;
}

void PrintMenu() {
    cout << endl;
    cout << "MENU" << endl;
    cout << "c - Number of non-whitespace characters" << endl;
    cout << "w - Number of words" << endl;
    cout << "f - Find text" << endl;
    cout << "r - Replace all !'s" << endl;
    cout << "s - Shorten spaces" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
}

MenuOpts ValidateMenuChoice(char userChoice) {
    MenuOpts choice{MenuOpts::InvalidChoice};
    switch (userChoice) {
        case 'c':
            choice = MenuOpts::GetNumOfNonWSCharacters;
            break;
        case 'w':
            choice = MenuOpts::GetNumOfWords;
            break;
        case 'f':
            choice = MenuOpts::FindText;
            break;
        case 'r':
            choice = MenuOpts::ReplaceExclamation;
            break;
        case 's':
            choice = MenuOpts::ShortenSpace;
            break;
        case 'q':
            choice = MenuOpts::Quit;
            break;
        default:
            choice = MenuOpts::InvalidChoice;
            break;
    }

    return choice;
}

void ExecuteMenu(char menu_selection, string& userText) {
    MenuOpts userChoice{ValidateMenuChoice(menu_selection)};
    int nonWSCount{}, wordCount{}, searchCount{};
    string searchString{};

    switch (userChoice) {
        case MenuOpts::GetNumOfNonWSCharacters:
            nonWSCount = GetNumOfNonWSCharacters(userText);
            cout << "Number of non-whitespace characters: " << nonWSCount
                 << endl;
            break;
        case MenuOpts::GetNumOfWords:
            wordCount = GetNumOfWords(userText);
            cout << "Number of words: " << wordCount << endl;
            break;
        case MenuOpts::FindText:
            cin.ignore();
            cout << "Enter a word or phrase to be found:" << endl;
            getline(cin, searchString);

            searchCount = FindText(searchString, userText);
            cout << "\"" << searchString << "\" instances: " << searchCount
                 << endl;
            break;
        case MenuOpts::ReplaceExclamation:
            ReplaceExclamation(userText);
            cout << "Edited text: ";
            cout << userText << endl;
            break;
        case MenuOpts::ShortenSpace:
            ShortenSpace(userText);
            cout << "Edited text: ";
            cout << userText << endl;
            break;
        default:
            break;
    }
}

int GetNumOfNonWSCharacters(const string userText) {
    int countNonWS{};
    for (size_t i{}; i < userText.size(); i++) {
        if (!isspace(userText.at(i)))
            countNonWS++;
    }
    return countNonWS;
}
int GetNumOfWords(const string userText) {
    int countNumWords{};

    int prevChar{userText.at(0)};

    for (size_t i{1}; i < userText.size(); i++) {
        if (!isspace(prevChar) && isspace(userText.at(i))) {
            countNumWords++;
        }
        prevChar = userText.at(i);
    }
    if (!isspace(userText.at(userText.size() - 1)))
        countNumWords++;

    return countNumWords;
}
int FindText(string find, string userText) {
    int searchCount{};
    size_t findIdx{};

    for (size_t i{}; i < userText.size(); i++) {
        if (find.at(findIdx) == userText.at(i)) {
            findIdx++;
        }
        if (findIdx == find.size() - 1) {
            findIdx = 0;
            searchCount++;
        }
    }
    return searchCount;
}
void ReplaceExclamation(string& userText) {
    for (size_t i{}; i < userText.size(); i++) {
        if (userText.at(i) == '!') {
            userText.at(i) = '.';
        }
    }
}
void ShortenSpace(string& userText) {
    string sanitizedText{userText.at(0)};

    for (size_t i{1}; i < userText.size(); i++) {
        if (isspace(userText.at(i - 1)) && (isspace(userText.at(i)))) {
            continue;
        }
        sanitizedText.append(1, userText.at(i));
    }
    userText = sanitizedText;
}

int main() {
    string userText{};
    char menu_selection{};
    MenuOpts userChoice{};

    GetUserInput(userText);

    while (userChoice != MenuOpts::Quit) {
        PrintMenu();
        cout << "Choose an option:" << endl;
        cin >> menu_selection;
        userChoice = ValidateMenuChoice(menu_selection);

        if (userChoice != MenuOpts::InvalidChoice) {
            ExecuteMenu(menu_selection, userText);
        }
    }

    return 0;
}
