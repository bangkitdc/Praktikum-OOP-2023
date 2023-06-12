class DebitCard implements IPaymentMethod {
    double balance;

    // TODO
    // Inisialisasi balance menjadi 0
    public DebitCard() {
        balance = 0;
    }

    // TODO
    // Getter
    public double getBalance() {
        return balance;
    }

    // TODO
    // Menambahkan amount ke balance
    // Mengembalikan true
    public boolean deposit(double amount) {
        this.balance += amount;
        return true;
    }
    // TODO
    // Mengurangi amount dari balance
    // Mengembalikan false apabila amount melebihi balance
    public boolean withdraw(double amount) {
        if (amount > balance) {
            return false;
        }
        balance -= amount;
        return true;
    }
    // TODO
    // Mengurangi amount dari balance
    // Mengembalikan false apabila amount melebihi balance
    public boolean pay(double price) {
        if (price > balance) {
            return false;
        }
        balance -= price;
        return true;
    }
}