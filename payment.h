#ifndef pay_h
#define pay_h
class payment{
            public:
                    virtual int pay()=0;
};

class card:public payment{
                    int card_number;
                    int cvv;
            public:
                    int pay();
};
class cash:public payment{
                        int amount;
                public:
                        int pay();
};
class check:public payment{
                    int check_number;
            public:
                    int pay();
};
#endif // pay_h
