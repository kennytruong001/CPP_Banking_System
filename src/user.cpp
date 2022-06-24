// Constructor
User::User(std::string username, float balance = 0)
    :username(username),
    balance(balance){}

// Getters
std::string User::getUsername() {
    return username;
}

float User::getBalance() {
    return balance;
}