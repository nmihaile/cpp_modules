/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:36:25 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/11 19:04:38 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_replace.hpp"

static void	error_msg(std::string msg)
{
	std::cerr << msg << std::endl;
}

bool	ft_replace(std::string inFileName, std::string s1, std::string s2)
{
	std::string		outFileName = inFileName + ".replace";
	std::ifstream	inFile(inFileName.c_str());

	if (s1.empty())
		return (error_msg("Error: string1: is empty."), true);

	if (!inFile.is_open())
		return (error_msg("Error: failed to open: " + inFileName), true);

	std::ofstream	outFile(outFileName.c_str());
	if (!outFile.is_open())
	{
		inFile.close();
		return (error_msg("Error: failed to open: " + outFileName), true);
	}

	std::string		line;
	std::getline(inFile, line, '\0');
	if (inFile.fail())
	{
		inFile.close();
		outFile.close();
		return (error_msg("Error: failed to read from `" + inFileName + "'"), true);
	}
			
	std::size_t	pos = line.find(s1);
	while (pos != line.npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos = line.find(s1, pos + s2.length());
	}
	outFile << line;
	if (outFile.fail())
	{
		inFile.close();
		outFile.close();
		return (error_msg("Error: failed to write to `" + outFileName + "'"), true);
	}

	return (false);
}
