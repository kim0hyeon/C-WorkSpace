cmake_minimum_required(VERSION 3.27)
project(OOP_Project07)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOP_Project07 Account.h Account.cpp AccountHandler.h HighCreditAccount.h
        AccountHandler.cpp BankingCommonDec1.h BankingSystemMain.cpp NormalAccount.h)
