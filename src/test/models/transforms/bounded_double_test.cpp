#include <gtest/gtest.h>
#include <test/models/model_test_fixture.hpp>

class Models_Transforms_BoundedDouble : 
  public Model_Test_Fixture<Models_Transforms_BoundedDouble> {
protected:
  virtual void SetUp() {
  }
public:
  static std::vector<std::string> get_model_path() {
    std::vector<std::string> model_path;
    model_path.push_back("models");
    model_path.push_back("transforms");
    model_path.push_back("bounded_double");
    return model_path;
  }
  static bool has_data() {
    return false;
  }
};

INSTANTIATE_TYPED_TEST_CASE_P(Models_Transforms_BoundedDouble,
			      Model_Test_Fixture,
			      Models_Transforms_BoundedDouble);
