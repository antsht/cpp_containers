#ifndef S21_TEST_CLASS_H_
#define S21_TEST_CLASS_H_
#include <ostream>
#include <string>

class TestUnit {
 public:
  std::string name;
  int level;

  bool operator==(const TestUnit &tu) const {
    return (name == tu.name && level == tu.level);
  }

  bool operator!=(const TestUnit &tu) const {
    if (name == tu.name && level == tu.level) return false;
    return true;
  }

  bool operator<(const TestUnit &tu) const {
    if (name == tu.name) return level < tu.level;
    return name < tu.name;
  }

  bool operator>(const TestUnit &tu) const {
    if (name == tu.name) return level > tu.level;
    return name > tu.name;
  }

  friend std::ostream &operator<<(std::ostream &out, const TestUnit &tu) {
    out << tu.name << " " << tu.level;
    return out;
  }
};

class TestUnitComparator {
 public:
  bool operator()(const TestUnit &a, const TestUnit &b) const { return a > b; }
};
#endif
