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

#include <cppunit/extensions/HelperMacros.h>

#include "arithtest.h"

#include "halfadder.h"
#include "number.h"

CPPUNIT_TEST_SUITE_REGISTRATION ( AdderTest );

template<class T, int N>
struct CppUnit::assertion_traits<Commons::Lab::unlogical::Number<T, N> > {

    static bool equal ( const Commons::Lab::unlogical::Number<T, N>& x, const Commons::Lab::unlogical::Number<T, N>& y ) {
        return x == y;
    }

    static std::string toString ( const Commons::Lab::unlogical::Number<T, N>& x ) {
        OStringStream ost;
        ost << +typename Commons::Lab::unlogical::Number<T, N>::number_type ( x );
        return ost.str();
    }
};

void AdderTest::testHalfAdder() {

    Commons::Lab::unlogical::arith::HalfAdder ha_case1 ( false, false );
    CPPUNIT_ASSERT ( !ha_case1().result );
    CPPUNIT_ASSERT ( !ha_case1().carry );

    Commons::Lab::unlogical::arith::HalfAdder ha_case2 ( false, true );
    CPPUNIT_ASSERT ( ha_case2().result );
    CPPUNIT_ASSERT ( !ha_case2().carry );

    Commons::Lab::unlogical::arith::HalfAdder ha_case3 ( true, false );
    CPPUNIT_ASSERT ( ha_case3().result );
    CPPUNIT_ASSERT ( !ha_case3().carry );

    Commons::Lab::unlogical::arith::HalfAdder ha_case4 ( true, true );
    CPPUNIT_ASSERT ( !ha_case4().result );
    CPPUNIT_ASSERT ( ha_case4().carry );
}

void AdderTest::testFullAdder() {

    Commons::Lab::unlogical::arith::FullAdder fa_case1_1 ( false, false, false );
    CPPUNIT_ASSERT ( !fa_case1_1().result );
    CPPUNIT_ASSERT ( !fa_case1_1().carry );

    Commons::Lab::unlogical::arith::FullAdder fa_case1_2 ( false, false, true );
    CPPUNIT_ASSERT ( fa_case1_2().result );
    CPPUNIT_ASSERT ( !fa_case1_2().carry );

    Commons::Lab::unlogical::arith::FullAdder fa_case2_1 ( false, true, false );
    CPPUNIT_ASSERT ( fa_case2_1().result );
    CPPUNIT_ASSERT ( !fa_case2_1().carry );

    Commons::Lab::unlogical::arith::FullAdder fa_case2_2 ( false, true, true );
    CPPUNIT_ASSERT ( !fa_case2_2().result );
    CPPUNIT_ASSERT ( fa_case2_2().carry );

    Commons::Lab::unlogical::arith::FullAdder fa_case3_1 ( true, false, false );
    CPPUNIT_ASSERT ( fa_case3_1().result );
    CPPUNIT_ASSERT ( !fa_case3_1().carry );

    Commons::Lab::unlogical::arith::FullAdder fa_case3_2 ( true, false, true );
    CPPUNIT_ASSERT ( !fa_case3_2().result );
    CPPUNIT_ASSERT ( fa_case3_2().carry );

    Commons::Lab::unlogical::arith::FullAdder fa_case4_1 ( true, true, false );
    CPPUNIT_ASSERT ( !fa_case4_1().result );
    CPPUNIT_ASSERT ( fa_case4_1().carry );

    Commons::Lab::unlogical::arith::FullAdder fa_case4_2 ( true, true, true );
    CPPUNIT_ASSERT ( fa_case4_2().result );
    CPPUNIT_ASSERT ( fa_case4_2().carry );
}

void AdderTest::testCarryRippleAdder() {

    Commons::Lab::unlogical::arith::CarryRippleAdder<uint8_t, 8> cra0 ( 0u, 0u );
    CPPUNIT_ASSERT_EQUAL ( ( uint8_t ) ( 0u ), cra0() );

    Commons::Lab::unlogical::arith::CarryRippleAdder<uint8_t, 8> cra1 ( 11u, 13u );
    CPPUNIT_ASSERT_EQUAL ( ( uint8_t ) ( 24u ), cra1() );

    Commons::Lab::unlogical::arith::CarryRippleAdder<uint8_t, 8> cra2 ( 60u, 60u );
    CPPUNIT_ASSERT_EQUAL ( ( uint8_t ) ( 120u ), cra2() );

    Commons::Lab::unlogical::arith::CarryRippleAdder<uint8_t, 8> cra3 ( 128u, 127u );
    CPPUNIT_ASSERT_EQUAL ( ( uint8_t ) ( 255u ), cra3() );
}

void AdderTest::testSubtractor() {

    Commons::Lab::unlogical::arith::Subtractor<int8_t, 8> sub0 ( 0, 0 );
    CPPUNIT_ASSERT_EQUAL ( ( int8_t ) ( 0 ), sub0() );

    Commons::Lab::unlogical::arith::Subtractor<int8_t, 8> sub1 ( 6, 5 );
    CPPUNIT_ASSERT_EQUAL ( ( int8_t ) ( 1 ), sub1() );

    Commons::Lab::unlogical::arith::Subtractor<int8_t, 8> sub2 ( 5, 6 );
    CPPUNIT_ASSERT_EQUAL ( ( int8_t ) ( -1 ), sub2() );

    Commons::Lab::unlogical::arith::Subtractor<int8_t, 8> sub3 ( 0, 127 );
    CPPUNIT_ASSERT_EQUAL ( ( int8_t ) ( -127 ), sub3() );
}

void AdderTest::testNumber() {

    typedef Commons::Lab::unlogical::Number<int8_t, 8> NUM8;

    NUM8 n1 ( 0 ), n2 ( 0 );
    CPPUNIT_ASSERT_EQUAL ( NUM8 ( 0 ), ( n1 + n2 ) );
    CPPUNIT_ASSERT_EQUAL ( NUM8 ( 0 ), ( n1 - n2 ) );

    NUM8 n3 ( 8 ), n4 ( 2 );
    CPPUNIT_ASSERT_EQUAL ( NUM8 ( 10 ), ( n3 + n4 ) );
    CPPUNIT_ASSERT_EQUAL ( NUM8 ( 10 ), ( n4 + n3 ) );

    CPPUNIT_ASSERT_EQUAL ( NUM8 ( 6 ), ( n3 - n4 ) );
    CPPUNIT_ASSERT_EQUAL ( NUM8 ( -6 ), ( n4 - n3 ) );

    CPPUNIT_ASSERT_EQUAL ( NUM8 ( 16 ), ( n3 * n4 ) );
    CPPUNIT_ASSERT_EQUAL ( NUM8 ( 16 ), ( n4 * n3 ) );

    NUM8 n5 ( -8 ), n6 ( 2 );
    CPPUNIT_ASSERT_EQUAL ( NUM8 ( -16 ), ( n5 * n6 ) );
    CPPUNIT_ASSERT_EQUAL ( NUM8 ( -16 ), ( n6 * n5 ) );
}
