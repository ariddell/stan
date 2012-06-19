#include <gtest/gtest.h>
#include <test/models/model_test_fixture.hpp>

class Models_BasicDistributions_Wishart2x2 :
  public Model_Test_Fixture<Models_BasicDistributions_Wishart2x2> {
protected:
  virtual void SetUp() {
  }
public:
  static std::vector<std::string> get_model_path() {
    std::vector<std::string> model_path;
    model_path.push_back("models");
    model_path.push_back("basic_distributions");
    model_path.push_back("wishart2x2");
    return model_path;
  }
  static bool has_data() {
    return false;
  }
};

INSTANTIATE_TYPED_TEST_CASE_P(Models_BasicDistributions_Wishart2x2,
			      Model_Test_Fixture,
			      Models_BasicDistributions_Wishart2x2);
