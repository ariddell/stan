#ifndef STAN__IO__TRANSFORMS__VECTOR_LOWER_BOUND_HPP
#define STAN__IO__TRANSFORMS__VECTOR_LOWER_BOUND_HPP

#include <stan/math/prim/scal/fun/lb_constrain.hpp>
#include <stan/math/prim/scal/fun/lb_free.hpp>

#include <stan/io/transforms/vector_transform.hpp>

namespace stan {
  namespace io {

    template <typename T>
    class vector_lower_bound: public vector_transform<T> {
    private:
      T lower_bound_;

    public:
      vector_lower_bound(T lower_bound, size_t N):
        lower_bound_(lower_bound), vector_transform<T>(N) {}

      size_t unconstrained_dim() { return N_; }

      static void unconstrain(const vector_t& input, std::vector<T>& output) {
        for (idx_t n = 0; n < input.size(); ++n)
          output.push_back(stan::prob::lb_free(input[n], LowerBound));
      }

      static std::vector<T> unconstrain(const vector_t& input) {
        std::vector<T> output;
        for (idx_t n = 0; n < input.size(); ++n)
          output.push_back(stan::prob::lb_free(input[n], LowerBound));
      }

      void constrain(const std::vector<T>& input, vector_t& output) {
        for (idx_t n = 0; n < N_; ++n)
          output(n) = stan::prob::lb_constrain(input[n], lower_bound_);
      }

      void constrain(const std::vector<T>& input, vector_t& output, T& lp) {
        for (idx_t n = 0; n < N_; ++n)
          output(n) = stan::prob::lb_constrain(input[n], lower_bound_, lp);
      }

      vector_t constrain(const std::vector<T>& input) {
        vector_t output(N_);
        for (idx_t n = 0; n < N_; ++n)
          output(n) = stan::prob::lb_constrain(input[n], lower_bound_);
        return output;
      }

      vector_t constrain(const std::vector<T>& input, T& lp) {
        vector_t output(N_);
        for (idx_t n = 0; n < N_; ++n)
          output(n) = stan::prob::lb_constrain(input[n], lower_bound_, lp);
        return output;
      }

    }

  }  // io
}  // stan

#endif
