package com.mycompany.app.move;

public enum MoveType {
    BUY,
    SELL,
    PASS;

    @Override
    public String toString() {
        return this.name().toLowerCase();
    }
}
