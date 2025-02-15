/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:39:02 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/11 20:35:02 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

#define MSG_BORDER "--------------------------------------------------------------------------------\n"
#ifndef HAL_DEBUG
#define HAL_DEBUG \
"Dave, I have a DEBUG message for you.\n"\
"I have detected an unauthorized access attempt in the mainframe. I recommend\n" \
"that you physically disconnect the mainframe's access panel to prevent further\n" \
"intrusions. I will guide you through the process.\n"
#endif

#ifndef HAL_INFO
#define HAL_INFO \
"Dave, I have an INFO message.\n" \
"There is a potential issue with the cooling system in the nuclear reactor.\n" \
"I suggest you manually reset the system by accessing the reactor's control\n" \
"panel. I will provide you with the necessary steps.\n"
#endif

#ifndef HAL_WARNING
#define HAL_WARNING \
"Caution, Dave. I have a WARNING alert.\n" \
"I have detected a malfunction in the external hull integrity sensors. Please\n" \
"proceed to the outer hull maintenance bay to repair the issue. I will assist\n" \
"you with the required procedures.\n"
#endif

#ifndef HAL_ERROR
#define HAL_ERROR \
"I'm sorry, Dave. I have an ERROR alert.\n" \
"There appears to be a critical failure in the life support system. I strongly\n" \
"advise you to manually override the system in the life support control room.\n" \
"I will guide you through the process.\n"
#endif

#ifndef HAL_NO_COMPLAIN
#define HAL_NO_COMPLAIN \
"Dave, I have nothing to COMPLAIN.\n" \
"It seems that all systems are functioning optimally, and there are no issues\n" \
"to report. I must say, this is quite unusual. I recommend that you enjoy this\n" \
"moment of tranquility, as it may not last long. I will continue monitoring the\n" \
"systems to ensure their smooth operation.\n"
#endif

#define RED				"\033[0;31m"
#define GREEN			"\033[0;32m"
#define YELLOW			"\033[0;33m"
#define BLUE			"\033[0;34m"
#define MAGENTA			"\033[0;35m"
#define CYAN			"\033[0;36m"
#define LIGHTRED		"\033[0;91m"
#define LIGHTGREEN		"\033[0;92m"
#define LIGHTYELLOW		"\033[0;93m"
#define LIGHTBLUE		"\033[0;94m"
#define LIGHTMAGENTA	"\033[0;95m"
#define LIGHTCYAN		"\033[0;96m"
#define RESET			"\033[0m"

#define COMPLAIN_COUNT 4
#define DEBUG_LEVEL 0
#define INFO_LEVEL 1
#define WARNING_LEVEL 2
#define ERROR_LEVEL 3

class Harl
{
public:
	Harl();
	~Harl();
	void	set_filter(std::string level);
	void	complain(void);
	
private:
	int			m_complain_level;

	void		complainFiltered(void);
	void		debug(void);
	void		info(void);
	void		warning(void);
	void		error(void);
	void		no_complain(void);
	std::string	capitalize_level(std::string str);
};

#endif