/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlotalcd <carlotalcd@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:40:17 by carlotalcd        #+#    #+#             */
/*   Updated: 2026/01/15 17:50:23 by carlotalcd       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <iostream>
#include <cstdlib>

void identify(Base& p);
void identify(Base* p);
Base* generate();

int main()
{
    std::srand(std::time(NULL));

    std::cout << "--- Generando objeto aleatorio ---" << std::endl;
    Base* ptr = generate();

    std::cout << "\n--- Identificando por PUNTERO ---" << std::endl;
    identify(ptr);

    std::cout << "\n--- Identificando por REFERENCIA ---" << std::endl;
    identify(*ptr);

    delete ptr;

    return 0;
}