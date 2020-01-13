package com.mycompany.app.move;

import java.util.ArrayList;
import java.util.stream.Collectors;

public class Move {

    private ArrayList<Order> orders;

    public Move(ArrayList<Order> orders) {
        this.orders = orders;
    }

    @Override
    public String toString() {
        if (this.orders.isEmpty()) {
            return MoveType.PASS.toString();
        }

        return this.orders.stream().map(Order::toString).collect(Collectors.joining(";"));
    }
}
