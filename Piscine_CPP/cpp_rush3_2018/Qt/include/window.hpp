/*
** EPITECH PROJECT, 2022
** MyGKrellm
** File description:
** Created by Florian Louvet,
*/
#ifndef MYGKRELLM_WINDOW_HPP
#define MYGKRELLM_WINDOW_HPP

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

    private:
    Ui::MainWindow *ui;
};

#endif //MYGKRELLM_WINDOW_HPP
