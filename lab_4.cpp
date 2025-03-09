#include <array>
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

int main() {
    array<Contact, 10> contact_arr{};
    contact_arr[0] =
        Contact("Conor", "Ney", {"conor.ux@gmail.com", "650-815-9480"});
    contact_arr[1] =
        Contact("Dana", "Rausch", {"dana.rausch5@gmail.com", "650-545-2044"});
    contact_arr[2] = Contact("Hunter", "Ney", {"hney@me.com", "650-343-8998"});

    for (size_t i{3}; i < 10; i++) {
        contact_arr[i] = Contact();
    }

    // Update a contact
    contact_arr[2].SetName("Tara", "Raani");
    contact_arr[2].SetEmail("traani@aol.com");
    contact_arr[2].SetPhone("433-434-7889");

    // Print to confirm contact information is updated
    cout << contact_arr[2].GetName() << " | " << contact_arr[2].GetEmail()
         << " | " << contact_arr[2].GetPhone() << endl;

    return 0;
}
