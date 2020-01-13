package com.mycompany.app.data;

import java.util.Date;

public class Candle {

    private String pair;
    private Date date;
    private double high;
    private double low;
    private double open;
    private double close;
    private double volume;

    public Candle(String[] format, String input) {
        String[] values = input.split(",");

        for (int i = 0; i < format.length; i++) {
            String key = format[i];
            String value = values[i];

            switch (key) {
                case "pair":
                    this.pair = value;
                    break;
                case "date":
                    this.date = new Date(Long.parseLong(value));
                    break;
                case "high":
                    this.high = Double.parseDouble(value);
                    break;
                case "low":
                    this.low = Double.parseDouble(value);
                    break;
                case "open":
                    this.open = Double.parseDouble(value);
                    break;
                case "close":
                    this.close = Double.parseDouble(value);
                    break;
                case "volume":
                    this.volume = Double.parseDouble(value);
                    break;
            }
        }
    }

    public String getPair() {
        return this.pair;
    }

    public Date getDate() {
        return this.date;
    }

    public double getHigh() {
        return this.high;
    }

    public double getLow() {
        return this.low;
    }

    public double getOpen() {
        return this.open;
    }

    public double getClose() {
        return this.close;
    }

    public double getVolume() {
        return this.volume;
    }
}
