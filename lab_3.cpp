#include <iostream>
#include <string>
using namespace std;

class PhoneNumber {
   private:
    int m_area_code{};
    int m_local_number{};

   public:
    PhoneNumber() {
        m_area_code = -1;
        m_local_number = -1;
    }
    PhoneNumber(int area, int local) {
        m_area_code = area;
        m_local_number = local;
    }
    void SetPhoneNumber(int area, int local) {
        m_area_code = area;
        m_local_number = local;
    }
    string GetPhoneNumber() {
        return to_string(m_area_code) + "-" + to_string(m_local_number);
    }
};

class Contact {
   private:
    string m_first_name{};
    string m_last_name{};
    string m_email{};
    PhoneNumber m_phone{};

   public:
    Contact() = default;
    Contact(string first, string last, string email, int area, int local) {
        m_first_name = first;
        m_last_name = last;
        m_email = email;
        m_phone = PhoneNumber(area, local);
    };
    string GetName() { return m_first_name + m_last_name; }
    string GetEmail() { return m_email; }
    PhoneNumber GetPhone() { return m_phone; }

    void SetName(string first_name, string last_name) {
        m_first_name = first_name;
        m_last_name = last_name;
    }

    void SetEmail(string email) { m_email = email; }
    void SetPhone(int areaCode, int localNum) {
        PhoneNumber phone(areaCode, localNum);
        m_phone = phone;
    }
};

int main() {
    Contact contact_arr[10];
    contact_arr[0] =
        Contact("Conor", "Ney", "conor.ux@gmail.com", 650, 8159480);
    contact_arr[1] =
        Contact("Dana", "Rausch", "dana.rausch5@gmail.com", 650, 5452044);
    contact_arr[2] = Contact("Hunter", "Ney", "hney@me.com", 650, 3438998);

    for (int i{3}; i < 10; i++) {
        contact_arr[i] = Contact();
    }

    // Update a contact
    contact_arr[2].SetName("Tara", "Raani");
    contact_arr[2].SetEmail("traani@aol.com");
    contact_arr[2].SetPhone(433, 4347889);

    cout << contact_arr[2].GetName() << " " << contact_arr[2].GetEmail() << " "
         << contact_arr[2].GetPhone().GetPhoneNumber() << endl;
}
