package com.mycompany.app.bot;

import com.mycompany.app.move.Move;
import com.mycompany.app.move.MoveType;
import com.mycompany.app.move.Order;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

import static java.lang.Math.sqrt;

public class BotStarter {
    private static int index = 0;
    private static int max = 15;
    private static int dimension = 1;
    private static double[] paired = new double[max];
    private static double[] paired2 = new double[max];
    private static double[] paired3 = new double[max];

    private static HashMap<Integer, double[]> sample = new HashMap<>();

    public static void main(String[] args) {
        BotParser parser = new BotParser(new BotStarter());
        sample.put(1, paired);
        sample.put(2, paired2);
        sample.put(3, paired3);
        parser.run();
    }

    Move makeTrades(BotState state) {
        double treshold = 0.01;  // 1% treshold for buying or selling
        return Calc(state);

//        String symbol = "ETH";
//        return BuyAndHODL(state, symbol);
    }

    private MoveType Bollinger(double[] array) {
        double u = 0;
        double sigma = 0;
        double fi = 15;
        double fiDown = 1;
        double bUp = 0;
        double bDown = 0;
        for (double v : array) u += v;
        u = u / array.length;
        for (double v : array) sigma += ((v - u) * (v - u));
        sigma = sqrt(sigma);
        sigma = sigma / array.length;
        bUp = u + (fi * sigma);
        bDown = u - (fiDown * sigma);

        if (array[array.length - 1] > bUp) {
            return MoveType.SELL;

        }
        if (array[array.length - 1] < bDown) {
            return MoveType.BUY;

        }
        return MoveType.PASS;
    }

    private Move Calc(BotState state) {
        ArrayList<Order> orders = new ArrayList<>();

        state.getCharts().forEach((pair, chart) -> {
            if (dimension == 4) {
                index++;
                dimension = 1;
            }
            if (index < max) {
                sample.get(dimension)[index] = chart.getCandleAt(state.getDate()).getClose();
                dimension++;
                return;
            } else {
                for (int i = 1; i < max; i++) {
                    sample.get(dimension)[i - 1] = sample.get(dimension)[i];
                }
                sample.get(dimension)[sample.get(dimension).length - 1] = chart.getCandleAt(state.getDate()).getClose();
            }
            MoveType type = Bollinger(sample.get(dimension));
            double amount = getAmount(type, pair, state.getStacks(), sample.get(dimension)[2]) / 2;
            if (amount <= 0 || type == MoveType.PASS) {
                dimension++;
                return;
            }
            orders.add(new Order(type, pair, amount));
            dimension++;
        });
        return new Move(orders);

    }

    private double getAmount(MoveType type, String pair, HashMap<String, Double> stacks, double price) {
        String[] split = pair.split("_");
        double amount;
        if (type == MoveType.SELL) {
            amount = stacks.get(split[1]);
        } else {
            amount = stacks.get(split[0]) / price;
            amount = amount - (amount * 0.1);
        }

        if (amount < 0.00001) {
            return 0;
        }

        return amount;
    }
}
