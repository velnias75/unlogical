/*
 * Copyright 2018 by Heiko Schäfer <heiko@rangun.de>
 *
 * This file is part of unlogical.
 *
 * unlogical is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * unlogical is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with unlogical.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NUMBER_H
#define NUMBER_H

#include "subtractor.h"

namespace Commons {

namespace Lab {

namespace unlogical {
    
template<class T, int N>
class Number {
public:
    
    typedef T number_type;
    
    Number(const T& n) : m_num(n) {}
    
    operator number_type() const {
        return m_num;
    }
    
    bool operator==(const Number& o) const {
        return m_num == o;
    }
    
    Number operator+(const Number& o) const {
        return arith::CarryRippleAdder<T, N>(m_num, o)();
    }
    
    Number operator-(const Number& o) const {
        return arith::Subtractor<T, N>(m_num, o)();
    }
    
    Number operator-() const {
        return arith::CarryRippleAdder<T, N>(~m_num, 1)();
    }
    
    Number operator*(const Number& o) const {

        Number<T, N> aux(0);
        
        const number_type &fac(o.m_num < 0 ? (-o).m_num : o.m_num);
        const number_type &times(m_num < 0 ? -m_num : m_num);
        
        for(number_type n = 0; n < times; ++n) {
            aux = arith::CarryRippleAdder<T, N>(aux, fac)();
        }
        
        return ((o.m_num < 0) != (m_num < 0)) ? -aux : aux;
    }
    
private:
    number_type m_num;
};

}

}

}

#endif /* NUMBER_H */
