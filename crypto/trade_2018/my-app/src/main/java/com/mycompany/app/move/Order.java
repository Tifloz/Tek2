package com.mycompany.app.move;

public class Order {

    private MoveType type;
    private String pair;
    private double amount;

    public Order(MoveType type, String pair, double amount) {
        this.type = type;
        this.pair = pair;
        this.amount = amount;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s", this.type, this.pair, this.amount);
    }
}
