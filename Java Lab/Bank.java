import java.util.Scanner;

class Account {
	String name, type_of_account;
	int account_number;
	boolean chequebook;
	float amount;
	Scanner in = new Scanner(System.in);	

	Account() {
		System.out.print("enter name: ");
		name = in.next();
		System.out.print("enter type of account: ");
		type_of_account = in.next();
		System.out.print("enter account number: ");
		account_number = in.nextInt();
	}
	
	void deposit() {
		System.out.print("enter amount to deposit: ");
		amount += in.nextFloat();
	}

	void withdraw() {
		System.out.print("enter the amount to withdraw: ");
		amount -= in.nextFloat();
	}

	void display() {
		System.out.println("balance: " + amount);
	}
}

class Savings extends Account {
	float ci;

	Savings() {
		chequebook = false;
		System.out.print("enter ci: ");
		ci = in.nextFloat();
	}
		
	void calcinterest() {
		System.out.println("enter the time: ");
		float interest = (float) (ci * amount * in.nextInt() / 100);
		System.out.println("interest amount: " + interest);
		amount += interest;
	}
}

class Current extends Account {
	float min;
	float penalty;

	Current() {
		chequebook = true;
		System.out.print("enter minimum value: ");
		min = in.nextFloat();
		System.out.print("enter penalty: ");
		penalty = in.nextFloat();
	}

	void withdraw() {
		System.out.print("enter the amount to withdraw: ");
		if (amount < min){
		       	System.out.println("less than min, cannot withdraw and penalty imposed");
			amount -= penalty;
			return;
		}
		amount -= in.nextFloat();
	}
}

class BankDemo {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("enter number of accounts: ");
		Account[] bank = new Account[in.nextInt()];
		for (int i = 0; i < bank.length; i++) {
			System.out.println("1. current");
		System.out.println("2. savings");
		System.out.println("enter choice: ");
		int choice = in.nextInt();
	   if (choice == 1) bank[i] = new Current();
		else if (choice == 2) bank[i] = new Savings();
		else System.out.println("invalid choice");	

		System.out.println("1. withdraw");
		System.out.println("2. deposit");
		choice = in.nextInt();
	       	if (choice == 1) { bank[i].withdraw(); bank[i].display(); }
		else if (choice == 2) { bank[i].deposit(); bank[i].display(); }
		else System.out.println("invalid choice");
		}
	}
}
