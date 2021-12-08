class Customer {
    public:
        Customer(string, string, char);
        ~Customer();
        
        void setName(string);
        void setAddress(string);
        void setType(char);

        string getName();
        string getAddress();
        char getType();
    private:
        string name;
        string address;
        char type;
};