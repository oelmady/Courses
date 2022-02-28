public class Car {
    // instance variables
    String make;
    String model;
    int year;
    boolean isNew;
    double miles;
    String owner;

    public static void main(String[] args) {
        
    }

    public void sell (String newOwner) {
        owner = newOwner;
        if (isNew) {
            isNew = false;
        }
    }
    
    public boolean isOld() {
        int thisYear = 
        Calendar.getInstance().get(Calendar.YEAR);
        return (thisYear - year > 10);
        }
}
