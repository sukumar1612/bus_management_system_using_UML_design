#ifndef login_h
#define login_h
class login{
        public:
                char name[50];
                int age;
                char gender;
                char special_needs[50];
                int adhar_number;
                char user_name[50];
                char password[50];
                void get_details();
                int authenticate();
                void display_details();
};
#endif // login_h
