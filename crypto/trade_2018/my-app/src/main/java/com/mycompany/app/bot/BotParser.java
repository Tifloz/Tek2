package com.mycompany.app.bot;

import com.mycompany.app.move.Move;

import java.util.Date;
import java.util.Scanner;

public class BotParser {

    private Scanner scanner;
    private BotStarter bot;
    private BotState currentState;

    BotParser(BotStarter bot) {
        this.scanner = new Scanner(System.in);
        this.bot = bot;
        this.currentState = new BotState();
    }

    /**
     * Keeps consuming all input over the stdin channel
     */
    void run() {
        while (this.scanner.hasNextLine()) {
            String line = this.scanner.nextLine();
            if (line.length() == 0) continue;

            String[] parts = line.split(" ");
            switch (parts[0]) {
                case "settings":
                    parseSettings(parts[1], parts[2]);
                    break;
                case "update":
                    if (parts[1].equals("game")) {
                        parseGameData(parts[2], parts[3]);
                    }
                    break;
                case "action":
                    this.currentState.setTimebank(Integer.parseInt(parts[2]));
                    Move move = this.bot.makeTrades(this.currentState);

                    System.out.println(move.toString());
                    break;
                default:
                    System.err.println("Unknown command");
            }
        }
    }

    private void parseSettings(String key, String value) {
        try {
            switch (key) {
                case "timebank":
                    int time = Integer.parseInt(value);
                    this.currentState.setMaxTimebank(time);
                    this.currentState.setTimebank(time);
                    break;
                case "time_per_move":
                    this.currentState.setTimePerMove(Integer.parseInt(value));
                    break;
                case "player_names":
                case "your_bot":
                    break;
                case "candle_interval":
                    this.currentState.setCandleInterval(Integer.parseInt(value));
                    break;
                case "candle_format":
                    this.currentState.setCandleFormat(value.split(","));
                    break;
                case "candles_total":
                    this.currentState.setCandlesTotal(Integer.parseInt(value));
                    break;
                case "candles_given":
                    this.currentState.setCandlesGiven(Integer.parseInt(value));
                    break;
                case "initial_stack":
                    this.currentState.setInitialStack(Integer.parseInt(value));
                    break;
                case "transaction_fee_percent":
                    this.currentState.setTransactionFee(Double.parseDouble(value));
                    break;
                default:
                    System.err.println(String.format(
                            "Cannot parse settings input with key '%s'", key));
            }
        } catch (Exception e) {
            System.err.println(String.format(
                    "Cannot parse settings value '%s' for key '%s'", value, key));
            e.printStackTrace();
        }
    }

    private void parseGameData(String key, String value) {
        try {
            switch (key) {
                case "next_candles":
                    String[] chartStrings = value.split(";");
                    String dateString = chartStrings[0].split(",")[1];

                    this.currentState.setDate(new Date(Long.parseLong(dateString)));

                    for (String candleString : chartStrings) {
                        String[] split = candleString.trim().split(",");
                        this.currentState.updateChart(split[0], candleString);
                    }
                    break;
                case "stacks":
                    for (String stack : value.split(",")) {
                        String[] split = stack.trim().split(":");
                        this.currentState.updateStack(split[0], Double.parseDouble(split[1]));
                    }
                    break;
                default:
                    System.err.println(String.format(
                            "Cannot parse game data input with key '%s'", key));
            }
        } catch (Exception e) {
            System.err.println(String.format(
                    "Cannot parse game data value '%s' for key '%s'", value, key));
            e.printStackTrace();
        }
    }
}
