#include <iostream>
#include <unistd.h>
#include "SystemCore.hpp"
#include "User.hpp"
#include "Date.hpp"
#include "System.hpp"
#include "Cpu.hpp"
#include "Ram.hpp"

int startTextMode()
{
	int quit = 0;
	SystemCore Core;
	User User;
	Date Date;
	System System;
	Cpu Cpu;
	Ram Ram;
	int passCPU = 0;
	int passRAM = 0;

	User.update();
	while (1) {
		clear();
		usleep(50000);
		printw("Press q to quit || SystemCore Monitoring {Text Version}");
		quit = getch();
		if (quit == 'q')
			break;
		else if (quit == 'u')
			User.onScreen(!User.isEnable());
		else if (quit == 'd')
			Date.onScreen(!Date.isEnable());
		else if (quit == 's')
			System.onScreen(!System.isEnable());
		else if (quit == 'c')
			Cpu.onScreen(!Cpu.isEnable());
		else if (quit == 'r')
			Ram.onScreen(!Ram.isEnable());
		if (User.isEnable())
			User.DisplayUserHost();
		if (System.isEnable()) {
			System.update();
			System.DisplaySystem();
		}
		if (Date.isEnable()) {
			Date.update();
			Date.DisplayDateTime();
		}
		if (Cpu.isEnable()) {
			if (passCPU >= 20) {
				Cpu.update();
				passCPU = 0;
			}
			Cpu.DisplayCpu();
		}
		if (Ram.isEnable()) {
			if (passRAM >= 20) {
				Ram.update();
				passRAM = 0;
			}
			Ram.DisplayRam();
		}
		passCPU++;
		passRAM++;
		mvwprintw(stdscr, 25, 1, "Disable/Enable press u for User, d for Date, s for System, c for CPU, r for RAM");
		refresh();
	}
	endwin();
	return 0;
}
