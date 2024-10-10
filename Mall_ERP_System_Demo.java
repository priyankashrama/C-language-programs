import java.util.Scanner;
import java.util.HashMap;

public class MallERP {

    // Inventory and Sales data
    private static HashMap<String, Integer> inventory = new HashMap<>();
    private static double totalSales = 0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n==== Mall ERP System ====");
            System.out.println("1. Add Product to Inventory");
            System.out.println("2. Sell Product");
            System.out.println("3. View Inventory");
            System.out.println("4. View Total Sales");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    // Add product to inventory
                    System.out.print("Enter product name: ");
                    String productName = scanner.next();
                    System.out.print("Enter quantity: ");
                    int quantity = scanner.nextInt();
                    inventory.put(productName, inventory.getOrDefault(productName, 0) + quantity);
                    System.out.println("Product added: " + productName + " | Quantity: " + quantity);
                    break;

                case 2:
                    // Sell product and calculate sales
                    System.out.print("Enter product name: ");
                    productName = scanner.next();
                    if (inventory.containsKey(productName) && inventory.get(productName) > 0) {
                        System.out.print("Enter quantity to sell: ");
                        quantity = scanner.nextInt();
                        if (inventory.get(productName) >= quantity) {
                            System.out.print("Enter price per unit: ");
                            double pricePerUnit = scanner.nextDouble();
                            double saleAmount = quantity * pricePerUnit;
                            totalSales += saleAmount;
                            inventory.put(productName, inventory.get(productName) - quantity);
                            System.out.println("Sold " + quantity + " units of " + productName + ". Total Sale: $" + saleAmount);
                        } else {
                            System.out.println("Not enough stock!");
                        }
                    } else {
                        System.out.println("Product not available in inventory.");
                    }
                    break;

                case 3:
                    // View inventory
                    System.out.println("Current Inventory:");
                    for (String product : inventory.keySet()) {
                        System.out.println("Product: " + product + " | Quantity: " + inventory.get(product));
                    }
                    break;

                case 4:
                    // View total sales
                    System.out.println("Total Sales: $" + totalSales);
                    break;

                case 5:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice. Try again.");
            }
        } while (choice != 5);
    }
}
