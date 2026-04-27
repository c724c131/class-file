package CH07;

interface PaymentProcessor{
    void processPayment(int amount);
}
class CreditCardProcessor implements PaymentProcessor{
    public void processPayment(int amount){
        System.out.println("신용 카드 결제" + amount);
    }
}
class NaverPayProcessor implements PaymentProcessor{
    @Override
    public void processPayment(int amount){
        System.out.println("네이버 페이 결제 : " + amount);
    }
}

public class PaymentService {
    private PaymentProcessor processor;
    public PaymentService(PaymentProcessor processor){
        this.processor = processor;
    }
    public void process(int amount){
        processor.processPayment(amount);
    }

    public static void main(String[] args){
        PaymentProcessor creditCard = new CreditCardProcessor();
        PaymentProcessor naverPay = new NaverPayProcessor();

        PaymentService service = new PaymentService(creditCard);
        service.process(10000);

        service = new PaymentService(naverPay);
        service.process(20000);
    }
}
