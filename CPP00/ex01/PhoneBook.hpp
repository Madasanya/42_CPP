/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:54:19 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/03 18:54:19 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
# define PHONEBOOK_SIZE 8

#include "Contact.hpp"

class PhoneBook {

public:

	Contact phoneBook[PHONEBOOK_SIZE];

	PhoneBook(void);
	~PhoneBook(void);
	void add(void);
	void search(void) const;

private:
	int _printPBSummary(void) const;
	void _printPBIndex(int entries) const;

};

#endif