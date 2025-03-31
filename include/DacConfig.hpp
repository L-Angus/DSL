#pragma once
#include <cmath>
#include <cstdint>
#include <vector>

// 低32位寄存器
struct DACCFG3_L {
  uint32_t QDAC_FSC_Adj : 10;  // [9:0]
  uint32_t AUX_IDAC_Data : 10; // [19:10]
  uint32_t AUX_QDAC_Data : 10; // [29:20]
  uint32_t DAC_SPI_select : 1; // [30]
  uint32_t reserved : 1;       // [31]
};

// 高32位寄存器
struct DACCFG3_H {
  uint32_t I_Phase_Adj : 10;  // [9:0]
  uint32_t Q_Phase_Adj : 10;  // [19:10]
  uint32_t IDAC_FSC_Adj : 10; // [29:20]
  uint32_t AUX_QDAC_sign : 1; // [30]
  uint32_t AUX_IDAC_sign : 1; // [31]
};

class DACRegister {
private:
  union {
    struct {
      DACCFG3_L low;
      DACCFG3_H high;
    };
    uint64_t fullValue;
  };

public:
  DACRegister() : fullValue(0) {}

  // 修改为直接接收10位整数值 [0, 1023]
  void setQDACFscAdj(uint32_t code) { low.QDAC_FSC_Adj = code & 0x3FF; }

  void setAuxIDACData(uint32_t data) { low.AUX_IDAC_Data = data & 0x3FF; }

  void setAuxQDACData(uint32_t data) { low.AUX_QDAC_Data = data & 0x3FF; }

  void setDacPath(bool is3Q4Path) { low.DAC_SPI_select = is3Q4Path ? 1 : 0; }

  // 修改为直接接收10位整数值 [0, 511]
  void setIPhaseAdj(uint32_t code) { high.I_Phase_Adj = code & 0x1FF; }

  // 修改为直接接收10位整数值 [0, 511]
  void setQPhaseAdj(uint32_t code) { high.Q_Phase_Adj = code & 0x1FF; }

  void setIDACFscAdj(uint32_t data) { high.IDAC_FSC_Adj = data & 0x3FF; }

  void setAuxQDACSign(bool isPositive) {
    high.AUX_QDAC_sign = isPositive ? 0 : 1;
  }

  void setAuxIDACSign(bool isPositive) {
    high.AUX_IDAC_sign = isPositive ? 0 : 1;
  }

  uint32_t getLowReg() const {
    return *reinterpret_cast<const uint32_t *>(&low);
  }

  uint32_t getHighReg() const {
    return *reinterpret_cast<const uint32_t *>(&high);
  }

  uint64_t getFullValue() const { return fullValue; }

  std::vector<uint8_t> getFullValueAsBytes() const {
    std::vector<uint8_t> bytes(8);
    for (size_t i = 0; i < 8; ++i) {
      bytes[i] = static_cast<uint8_t>((fullValue >> (i * 8)) & 0xFF);
    }
    return bytes;
  }
};

#include <iostream>

class A {
public:
  A() { std::cout << "A()" << std::endl; }
  ~A() { std::cout << "~A()" << std::endl; }
  virtual void print1() { std::cout << "A::print1" << std::endl; }

protected:
  int a;
};
class B : public A {
public:
  B() { std::cout << "B()" << std::endl; }
  ~B() { std::cout << "~B()" << std::endl; }
  void print1() { std::cout << "B::print1: " << std::endl; }
  void print2() {
    a = 3;
    std::cout << "print2: " << a << std::endl;
  }
};