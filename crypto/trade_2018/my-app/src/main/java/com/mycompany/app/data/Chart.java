package com.mycompany.app.data;

import java.util.Date;
import java.util.HashMap;

public class Chart {

    // Stores candles in a Map with the candle's timestamp as key
    // for easy retrieval.
    private HashMap<Long, Candle> candles;

    public Chart() {
        this.candles = new HashMap<>();
    }

    public void addCandle(Candle candle) {
        this.candles.put(candle.getDate().getTime(), candle);
    }

    public Candle getCandleAt(Date date) {
        return this.candles.get(date.getTime());
    }

    public HashMap<Long, Candle> getCandles() {
        return this.candles;
    }

    public double SMA(int amount, Date currentDate, int interval) {
        double sum = 0;
        int count = 0;

        for (int i = 0; i < amount; i++) {
            Date date = new Date(currentDate.getTime() - (interval * i));
            Candle candle = getCandleAt(date);

            if (candle != null) {
                sum += getCandleAt(date).getClose();
                count++;
            }
        }

        return sum / count;
    }
}
