/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:56:08 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/03 18:56:08 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

class Contact
{
public:

	Contact(void);
	~Contact(void);

	void fillContact (void);

	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickName(void) const;
	std::string getPhone(void) const;
	std::string getDarkSecret(void) const;

	void setFirstName(std::string _firstName);
	void setLastName(std::string _lastName);
	void setNickName(std::string _nickName);
	void setPhone(std::string _phone);
	void setDarkSecret(std::string _darkSecret);

	static int _numContacts;
	
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phone;
	std::string _darkSecret;

	int _checkName(std::string name) const;
	int _checkPhone(std::string phone) const;
	int _checkSecret(std::string secret) const;
};

#endif