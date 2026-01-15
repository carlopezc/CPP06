/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlotalcd <carlotalcd@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:19:08 by carlotalcd        #+#    #+#             */
/*   Updated: 2026/01/15 17:19:32 by carlotalcd       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data myData;
    myData.info = "Top Secret Data";

    Data* originalPtr = &myData;
    
    uintptr_t raw = Serializer::serialize(originalPtr);

    Data* restoredPtr = Serializer::deserialize(raw);

    std::cout << "Original Ptr: " << originalPtr << std::endl;
    std::cout << "Raw Integer : " << raw << " (Hex: 0x" << std::hex << raw << std::dec << ")" << std::endl;
    std::cout << "Restored Ptr: " << restoredPtr << std::endl;

    std::cout << "--------------------------------" << std::endl;

    if (originalPtr == restoredPtr)
    {
        std::cout << "SUCCESS! ✅ Pointers match." << std::endl;
        std::cout << "Data content: " << restoredPtr->info << std::endl;
    }
    else
    {
        std::cout << "FAILURE! ❌ Pointers do not match." << std::endl;
    }
    return 0;
}