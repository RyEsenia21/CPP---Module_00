/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryesenia <ryesenia@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:32:58 by ryesenia          #+#    #+#             */
/*   Updated: 2022/06/03 21:33:05 by ryesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Account.hpp"
# include <iomanip>
# include <chrono>

/* 
** Короче тот мейник что дается в самом начале задания по итогк вводит у меня 
** не совсем точные логи, поэтому я написал свой main файл.
*/

int main()
{

	Account* f_w = new Account(42);
	Account* f_w1 = new Account(54);
	Account* f_w2 = new Account(957);
	Account* f_w3 = new Account(432);
	Account* f_w4 = new Account(1234);
	Account* f_w5 = new Account(0);
	Account* f_w6 = new Account(754);
	Account* f_w7 = new Account(16576);
	Account::displayAccountsInfos();
	f_w->displayStatus();
	f_w1->displayStatus();
	f_w2->displayStatus();
	f_w3->displayStatus();
	f_w4->displayStatus();
	f_w5->displayStatus();
	f_w6->displayStatus();
	f_w7->displayStatus();
	f_w->makeDeposit(5);
	f_w1->makeDeposit(765);
	f_w2->makeDeposit(564);
	f_w3->makeDeposit(2);
	f_w4->makeDeposit(87);
	f_w5->makeDeposit(23);
	f_w6->makeDeposit(9);
	f_w7->makeDeposit(20);
	Account::displayAccountsInfos();
	f_w->checkAmount();
	f_w1->checkAmount();
	f_w2->checkAmount();
	f_w3->checkAmount();
	f_w4->checkAmount();
	f_w5->checkAmount();
	f_w6->checkAmount();
	f_w7->checkAmount();
	Account::displayAccountsInfos();
	f_w->makeWithdrawal(48);
	f_w1->makeWithdrawal(34);
	f_w2->makeWithdrawal(657);
	f_w3->makeWithdrawal(4);
	f_w4->makeWithdrawal(76);
	f_w5->makeWithdrawal(24);
	f_w6->makeWithdrawal(657);
	f_w7->makeWithdrawal(7654);
	Account::displayAccountsInfos();
	f_w->checkAmount();
	f_w1->checkAmount();
	f_w2->checkAmount();
	f_w3->checkAmount();
	f_w4->checkAmount();
	f_w5->checkAmount();
	f_w6->checkAmount();
	f_w7->checkAmount();
	delete f_w;
	delete f_w1;
	delete f_w2;
	delete f_w3;
	delete f_w4;
	delete f_w5;
	delete f_w6;
	delete f_w7;
	return (0);
}