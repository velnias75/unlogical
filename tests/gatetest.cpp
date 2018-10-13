/*
 * Copyright 2018 by Heiko Schäfer <heiko@rangun.de>
 *
 * This file is part of unlogical.
 *
 * DiskFit is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * DiskFit is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with DiskFit.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cppunit/extensions/HelperMacros.h>

#include "gatetest.h"

#include "orgate.h"
#include "andgate.h"
#include "xorgate.h"

CPPUNIT_TEST_SUITE_REGISTRATION(GateTest);

void GateTest::testORGate() {
    CPPUNIT_ASSERT(!Commons::Lab::unlogical::gate::ORGate(false, false)());
    CPPUNIT_ASSERT( Commons::Lab::unlogical::gate::ORGate(false, true)());
    CPPUNIT_ASSERT( Commons::Lab::unlogical::gate::ORGate(true,  false)());
    CPPUNIT_ASSERT( Commons::Lab::unlogical::gate::ORGate(true,  true)());
}

void GateTest::testANDGate() {
    CPPUNIT_ASSERT(!Commons::Lab::unlogical::gate::ANDGate(false, false)());
    CPPUNIT_ASSERT(!Commons::Lab::unlogical::gate::ANDGate(false, true)());
    CPPUNIT_ASSERT(!Commons::Lab::unlogical::gate::ANDGate(true,  false)());
    CPPUNIT_ASSERT( Commons::Lab::unlogical::gate::ANDGate(true,  true)());    
}

void GateTest::testXORGate() {
    CPPUNIT_ASSERT(!Commons::Lab::unlogical::gate::XORGate(false, false)());
    CPPUNIT_ASSERT( Commons::Lab::unlogical::gate::XORGate(false, true)());
    CPPUNIT_ASSERT( Commons::Lab::unlogical::gate::XORGate(true,  false)());
    CPPUNIT_ASSERT(!Commons::Lab::unlogical::gate::XORGate(true,  true)());
}
