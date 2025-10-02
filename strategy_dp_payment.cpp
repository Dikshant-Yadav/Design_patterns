#include <iostream>
#include <string>
using namespace std;

// Strategy Interface
class PaymentStrategy {
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentStrategy() {}
};

// Concrete Strategy: Credit Card Payment
class CreditCardPayment : public PaymentStrategy {
private:
    string cardNumber;
    string name;
    string cvv;
    string expiryDate;

public:
    CreditCardPayment(string cardNum, string cardName, string cvvCode, string expiry) 
        : cardNumber(cardNum), name(cardName), cvv(cvvCode), expiryDate(expiry) {}
    
    void pay(double amount) override {
        cout << "Processing Credit Card Payment..." << endl;
        cout << "Amount: $" << amount << endl;
        cout << "Card Number: ****" << cardNumber.substr(cardNumber.length() - 4) << endl;
        cout << "Cardholder: " << name << endl;
        cout << "Payment Successful via Credit Card!" << endl;
        cout << "-----------------------------------" << endl;
    }
};

// Concrete Strategy: PayPal Payment
class PayPalPayment : public PaymentStrategy {
private:
    string email;
    string password;

public:
    PayPalPayment(string userEmail, string userPassword) 
        : email(userEmail), password(userPassword) {}
    
    void pay(double amount) override {
        cout << "Processing PayPal Payment..." << endl;
        cout << "Amount: $" << amount << endl;
        cout << "Email: " << email << endl;
        cout << "Logging into PayPal account..." << endl;
        cout << "Payment Successful via PayPal!" << endl;
        cout << "-----------------------------------" << endl;
    }
};

// Concrete Strategy: UPI Payment
class UPIPayment : public PaymentStrategy {
private:
    string upiId;

public:
    UPIPayment(string id) : upiId(id) {}
    
    void pay(double amount) override {
        cout << "Processing UPI Payment..." << endl;
        cout << "Amount: Rs." << amount << endl;
        cout << "UPI ID: " << upiId << endl;
        cout << "Sending payment request..." << endl;
        cout << "Payment Successful via UPI!" << endl;
        cout << "-----------------------------------" << endl;
    }
};

// Concrete Strategy: Cash on Delivery
class CashOnDelivery : public PaymentStrategy {
private:
    string address;

public:
    CashOnDelivery(string deliveryAddress) : address(deliveryAddress) {}
    
    void pay(double amount) override {
        cout << "Cash on Delivery Selected..." << endl;
        cout << "Amount to be paid: $" << amount << endl;
        cout << "Delivery Address: " << address << endl;
        cout << "Please keep cash ready at the time of delivery." << endl;
        cout << "Order Confirmed with COD!" << endl;
        cout << "-----------------------------------" << endl;
    }
};

// Context Class: Shopping Cart
class ShoppingCart {
private:
    PaymentStrategy* paymentMethod;
    double totalAmount;

public:
    ShoppingCart() : paymentMethod(nullptr), totalAmount(0.0) {}
    
    void setPaymentMethod(PaymentStrategy* method) {
        paymentMethod = method;
    }
    
    void setAmount(double amount) {
        totalAmount = amount;
    }
    
    void checkout() {
        if (paymentMethod == nullptr) {
            cout << "Error: No payment method selected!" << endl;
            return;
        }
        
        cout << "\n=== CHECKOUT ===" << endl;
        cout << "Total Cart Value: $" << totalAmount << endl;
        cout << endl;
        paymentMethod->pay(totalAmount);
    }
    
    ~ShoppingCart() {
        // Note: We don't delete paymentMethod here as it's managed externally
    }
};

int main() {
    // Create shopping cart
    ShoppingCart* cart = new ShoppingCart();
    cart->setAmount(2500.50);
    
    cout << "========== PAYMENT STRATEGY DEMO ==========" << endl;
    
    // Payment Option 1: Credit Card
    cout << "\n--- Customer chooses Credit Card ---" << endl;
    PaymentStrategy* creditCard = new CreditCardPayment(
        "1234567890123456", 
        "John Doe", 
        "123", 
        "12/25"
    );
    cart->setPaymentMethod(creditCard);
    cart->checkout();
    
    // Payment Option 2: PayPal
    cout << "\n--- Customer switches to PayPal ---" << endl;
    PaymentStrategy* paypal = new PayPalPayment(
        "john.doe@example.com", 
        "securePassword123"
    );
    cart->setPaymentMethod(paypal);
    cart->checkout();
    
    // Payment Option 3: UPI
    cout << "\n--- Customer switches to UPI ---" << endl;
    PaymentStrategy* upi = new UPIPayment("john@paytm");
    cart->setPaymentMethod(upi);
    cart->checkout();
    
    // Payment Option 4: Cash on Delivery
    cout << "\n--- Customer chooses Cash on Delivery ---" << endl;
    PaymentStrategy* cod = new CashOnDelivery("123 Main Street, New York, NY");
    cart->setPaymentMethod(cod);
    cart->checkout();
    
    // Cleanup
    delete creditCard;
    delete paypal;
    delete upi;
    delete cod;
    delete cart;
    
    return 0;
}