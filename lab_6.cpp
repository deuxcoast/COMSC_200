#include <iostream>
#include <string>
using namespace std;

// ContactMeans represents contact details
class ContactMeans {
   private:
    string m_email{};
    string m_phone{};

   public:
    ContactMeans() = default;
    ContactMeans(const string& email) : m_email{email} {}
    ContactMeans(const string& email, const string& phone)
        : m_email{email}, m_phone{phone} {};

    string GetEmail() const { return m_email; }
    string GetPhone() const { return m_phone; }

    void SetEmail(const string& email) { m_email = email; }
    void SetPhone(const string& phone_number) { m_phone = phone_number; }
};

// Contact represents a contact with a name and contact details
class Contact {
   private:
    string m_first_name{};
    string m_last_name{};
    ContactMeans m_contact_info{};

   public:
    Contact() = default;

    Contact(const string& first,
            const string& last,
            const ContactMeans& contact)
        : m_first_name{first}, m_last_name{last}, m_contact_info{contact} {};

    string GetName() const { return m_first_name + " " + m_last_name; }

    string GetEmail() const { return m_contact_info.GetEmail(); }

    string GetPhone() const { return m_contact_info.GetPhone(); }

    void SetName(const string& first_name, const string& last_name) {
        m_first_name = first_name;
        m_last_name = last_name;
    }

    void SetEmail(const string& email) { m_contact_info.SetEmail(email); }

    void SetPhone(const string& phone) { m_contact_info.SetPhone(phone); }
};

// ContactLinkedList stores contacts in a linked list
class ContactLinkedList {
   private:
    struct ContactNode {
        Contact value;
        ContactNode* next;
        ContactNode(const Contact& contact) : value(contact), next(nullptr) {}
    };

    ContactNode* head;

   public:
    ContactLinkedList() : head(nullptr) {}

    void insert(const Contact& contact) {
        ContactNode* newNode = new ContactNode(contact);
        if (!head || contact.GetName() < head->value.GetName()) {
            newNode->next = head;
            head = newNode;
            return;
        }
        ContactNode* current = head;
        while (current->next &&
               current->next->value.GetName() < contact.GetName()) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    void remove(const string& name) {
        if (!head)
            return;
        if (head->value.GetName() == name) {
            ContactNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        ContactNode* current = head;
        while (current->next && current->next->value.GetName() != name) {
            current = current->next;
        }
        if (current->next) {
            ContactNode* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    void display() {
        ContactNode* current = head;
        while (current) {
            cout << current->value.GetName() << " | "
                 << current->value.GetEmail() << " | "
                 << current->value.GetPhone() << endl;
            current = current->next;
        }
    }
};

int main() {
    ContactLinkedList contactList;
    contactList.insert(
        Contact("Conor", "Ney", {"conor.ux@gmail.com", "650-815-9480"}));
    contactList.insert(
        Contact("Dana", "Rausch", {"dana.rausch5@gmail.com", "650-545-2044"}));
    contactList.insert(
        Contact("Hunter", "Ney", {"hney@me.com", "650-343-8998"}));

    cout << "Contacts List:" << endl;
    contactList.display();

    cout << "\nDeleting 'Hunter Ney'\n";
    contactList.remove("Hunter Ney");
    contactList.display();

    return 0;
}
