/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlotalcd <carlotalcd@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:25:33 by carlotalcd        #+#    #+#             */
/*   Updated: 2026/01/15 14:55:27 by carlotalcd       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string par)
{
    double num;
    char *end;

    if (par.length() == 1 && !isdigit(par[0]))
        num = static_cast<double>(par[0]);
    else
    {
        num = std::strtod(par.c_str(), &end);
        if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0'))
        {
            std::cout << "Impossible convert" << std::endl;
            return;
        }
    }
    
    std::cout << "Float: " << static_cast<float>(num);
    if (!(std::isnan(num) || std::isinf(num)) && (num - static_cast<int>(num) == 0)) {
        std::cout << ".0";
    }
    std::cout << "f" << std::endl;

    std::cout << "double: " << static_cast<double>(num);
    if (!(std::isnan(num) || std::isinf(num)) && (num - static_cast<int>(num) == 0)) {
        std::cout << ".0";
    }
    std::cout << std::endl;
    
    std::cout << "Int: ";
    if (num > 2147483647 || num < -2147483648 || std::isnan(num) || std::isinf(num)) {
        std::cout << "impossible";
    } else {
        std::cout << static_cast<int>(num);
    }
    std::cout << std::endl;

    
    std::cout << "Char : " ;
    if (num < 0 || num > 127 || std::isnan(num)) {
        std::cout << "impossible";
    } else if (!isprint(static_cast<char>(num))) {
        std::cout << "Non displayable";
    } else {
        std::cout << "'" << static_cast<char>(num) << "'";
    }
    std::cout << std::endl;
    return ;
}