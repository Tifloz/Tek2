package com.mycompany.app.bot;

import com.mycompany.app.data.Candle;
import com.mycompany.app.data.Chart;

import java.util.Date;
import java.util.HashMap;

public class BotState {

    private int MAX_TIMEBANK;
    private int TIME_PER_MOVE;
    private int CANDLE_INTERVAL;
    private int CANDLES_TOTAL;
    private int CANDLES_GIVEN;
    private int INITIAL_STACK;
    private String[] CANDLE_FORMAT;
    private double TRANSACTION_FEE;

    private int timebank;
    private Date date;
    private HashMap<String, Double> stacks;
    private HashMap<String, Chart> charts;

    BotState() {
        this.stacks = new HashMap<>();
        this.charts = new HashMap<>();
    }

    public void updateChart(String pair, String candleString) {
        if (!this.charts.containsKey(pair)) {
            this.charts.put(pair, new Chart());
        }

        Candle candle = new Candle(CANDLE_FORMAT, candleString);
        this.charts.get(pair).addCandle(candle);
    }

    public void updateStack(String symbol, double amount) {
        this.stacks.put(symbol, amount);
    }

    public HashMap<String, Chart> getCharts() {
        return this.charts;
    }

    public HashMap<String, Double> getStacks() {
        return this.stacks;
    }

    public int getTimebank() {
        return this.timebank;
    }

    public void setTimebank(int value) {
        this.timebank = value;
    }

    public Date getDate() {
        return this.date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public int getMaxTimebank() {
        return MAX_TIMEBANK;
    }

    public void setMaxTimebank(int value) {
        MAX_TIMEBANK = value;
    }

    public int getTimePerMove() {
        return TIME_PER_MOVE;
    }

    public void setTimePerMove(int value) {
        TIME_PER_MOVE = value;
    }

    public int getCandleInterval() {
        return CANDLE_INTERVAL;
    }

    public void setCandleInterval(int value) {
        CANDLE_INTERVAL = value;
    }

    public int getCandlesTotal() {
        return CANDLES_TOTAL;
    }

    public void setCandlesTotal(int value) {
        CANDLES_TOTAL = value;
    }

    public int getCandlesGiven() {
        return CANDLES_GIVEN;
    }

    public void setCandlesGiven(int value) {
        CANDLES_GIVEN = value;
    }

    public int getInitialStack() {
        return INITIAL_STACK;
    }

    public void setInitialStack(int value) {
        INITIAL_STACK = value;
    }

    public String[] getCandleFormat() {
        return CANDLE_FORMAT;
    }

    public void setCandleFormat(String[] value) {
        CANDLE_FORMAT = value;
    }

    public double getTransactionFee() {
        return TRANSACTION_FEE;
    }

    public void setTransactionFee(double value) {
        TRANSACTION_FEE = value;
    }
}
