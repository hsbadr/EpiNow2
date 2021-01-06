// Generated by rstantools.  Do not edit by hand.

/*
    EpiNow2 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    EpiNow2 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with EpiNow2.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.21.0
#include <stan/model/model_header.hpp>
namespace model_exp_namespace {
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using namespace stan::math;
static int current_statement_begin__;
stan::io::program_reader prog_reader__() {
  stan::io::program_reader reader;
  reader.add_event(0, 0, "start", "model_exp");
  reader.add_event(19, 17, "end", "model_exp");
  return reader;
}
#include <stan_meta_header.hpp>
class model_exp : public stan::model::model_base_crtp<model_exp> {
 private:
  int N;
  vector_d low;
  vector_d up;
  double lam_mean;

 public:
  model_exp(stan::io::var_context& context__, std::ostream* pstream__ = 0)
      : model_base_crtp(0) {
    ctor_body(context__, 0, pstream__);
  }
  model_exp(stan::io::var_context& context__, unsigned int random_seed__,
            std::ostream* pstream__ = 0)
      : model_base_crtp(0) {
    ctor_body(context__, random_seed__, pstream__);
  }
  void ctor_body(stan::io::var_context& context__, unsigned int random_seed__,
                 std::ostream* pstream__) {
    typedef double local_scalar_t__;
    boost::ecuyer1988 base_rng__ =
        stan::services::util::create_rng(random_seed__, 0);
    (void)base_rng__;  // suppress unused var warning
    current_statement_begin__ = -1;
    static const char* function__ = "model_exp_namespace::model_exp";
    (void)function__;  // dummy to suppress unused var warning
    size_t pos__;
    (void)pos__;  // dummy to suppress unused var warning
    std::vector<int> vals_i__;
    std::vector<double> vals_r__;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void)DUMMY_VAR__;  // suppress unused var warning
    try {
      // initialize data block variables from context__
      current_statement_begin__ = 2;
      context__.validate_dims("data initialization", "N", "int",
                              context__.to_vec());
      N = int(0);
      vals_i__ = context__.vals_i("N");
      pos__ = 0;
      N = vals_i__[pos__++];
      current_statement_begin__ = 3;
      validate_non_negative_index("low", "N", N);
      context__.validate_dims("data initialization", "low", "vector_d",
                              context__.to_vec(N));
      low = Eigen::Matrix<double, Eigen::Dynamic, 1>(N);
      vals_r__ = context__.vals_r("low");
      pos__ = 0;
      size_t low_j_1_max__ = N;
      for (size_t j_1__ = 0; j_1__ < low_j_1_max__; ++j_1__) {
        low(j_1__) = vals_r__[pos__++];
      }
      current_statement_begin__ = 4;
      validate_non_negative_index("up", "N", N);
      context__.validate_dims("data initialization", "up", "vector_d",
                              context__.to_vec(N));
      up = Eigen::Matrix<double, Eigen::Dynamic, 1>(N);
      vals_r__ = context__.vals_r("up");
      pos__ = 0;
      size_t up_j_1_max__ = N;
      for (size_t j_1__ = 0; j_1__ < up_j_1_max__; ++j_1__) {
        up(j_1__) = vals_r__[pos__++];
      }
      current_statement_begin__ = 5;
      context__.validate_dims("data initialization", "lam_mean", "double",
                              context__.to_vec());
      lam_mean = double(0);
      vals_r__ = context__.vals_r("lam_mean");
      pos__ = 0;
      lam_mean = vals_r__[pos__++];
      // initialize transformed data variables
      // execute transformed data statements
      // validate transformed data
      // validate, set parameter ranges
      num_params_r__ = 0U;
      param_ranges_i__.clear();
      current_statement_begin__ = 8;
      num_params_r__ += 1;
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, current_statement_begin__,
                                  prog_reader__());
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
  }
  ~model_exp() {}
  void transform_inits(const stan::io::var_context& context__,
                       std::vector<int>& params_i__,
                       std::vector<double>& params_r__,
                       std::ostream* pstream__) const {
    typedef double local_scalar_t__;
    stan::io::writer<double> writer__(params_r__, params_i__);
    size_t pos__;
    (void)pos__;  // dummy call to supress warning
    std::vector<double> vals_r__;
    std::vector<int> vals_i__;
    current_statement_begin__ = 8;
    if (!(context__.contains_r("lambda")))
      stan::lang::rethrow_located(
          std::runtime_error(std::string("Variable lambda missing")),
          current_statement_begin__, prog_reader__());
    vals_r__ = context__.vals_r("lambda");
    pos__ = 0U;
    context__.validate_dims("parameter initialization", "lambda", "double",
                            context__.to_vec());
    double lambda(0);
    lambda = vals_r__[pos__++];
    try {
      writer__.scalar_lb_unconstrain(0, lambda);
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(
          std::runtime_error(
              std::string("Error transforming variable lambda: ") + e.what()),
          current_statement_begin__, prog_reader__());
    }
    params_r__ = writer__.data_r();
    params_i__ = writer__.data_i();
  }
  void transform_inits(const stan::io::var_context& context,
                       Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                       std::ostream* pstream__) const {
    std::vector<double> params_r_vec;
    std::vector<int> params_i_vec;
    transform_inits(context, params_i_vec, params_r_vec, pstream__);
    params_r.resize(params_r_vec.size());
    for (int i = 0; i < params_r.size(); ++i) params_r(i) = params_r_vec[i];
  }
  template <bool propto__, bool jacobian__, typename T__>
  T__ log_prob(std::vector<T__>& params_r__, std::vector<int>& params_i__,
               std::ostream* pstream__ = 0) const {
    typedef T__ local_scalar_t__;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void)DUMMY_VAR__;  // dummy to suppress unused var warning
    T__ lp__(0.0);
    stan::math::accumulator<T__> lp_accum__;
    try {
      stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
      // model parameters
      current_statement_begin__ = 8;
      local_scalar_t__ lambda;
      (void)lambda;  // dummy to suppress unused var warning
      if (jacobian__)
        lambda = in__.scalar_lb_constrain(0, lp__);
      else
        lambda = in__.scalar_lb_constrain(0);
      // model body
      current_statement_begin__ = 11;
      lp_accum__.add(uniform_log<propto__>(lambda, (1 / (5 * lam_mean)),
                                           (1 / (0.2 * lam_mean))));
      current_statement_begin__ = 13;
      for (int i = 1; i <= N; ++i) {
        current_statement_begin__ = 14;
        lp_accum__.add(stan::math::log(
            (exponential_cdf(get_base1(up, i, "up", 1), lambda) -
             exponential_cdf(get_base1(low, i, "low", 1), lambda))));
      }
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, current_statement_begin__,
                                  prog_reader__());
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
    lp_accum__.add(lp__);
    return lp_accum__.sum();
  }  // log_prob()
  template <bool propto, bool jacobian, typename T_>
  T_ log_prob(Eigen::Matrix<T_, Eigen::Dynamic, 1>& params_r,
              std::ostream* pstream = 0) const {
    std::vector<T_> vec_params_r;
    vec_params_r.reserve(params_r.size());
    for (int i = 0; i < params_r.size(); ++i)
      vec_params_r.push_back(params_r(i));
    std::vector<int> vec_params_i;
    return log_prob<propto, jacobian, T_>(vec_params_r, vec_params_i, pstream);
  }
  void get_param_names(std::vector<std::string>& names__) const {
    names__.resize(0);
    names__.push_back("lambda");
  }
  void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
    dimss__.resize(0);
    std::vector<size_t> dims__;
    dims__.resize(0);
    dimss__.push_back(dims__);
  }
  template <typename RNG>
  void write_array(RNG& base_rng__, std::vector<double>& params_r__,
                   std::vector<int>& params_i__, std::vector<double>& vars__,
                   bool include_tparams__ = true, bool include_gqs__ = true,
                   std::ostream* pstream__ = 0) const {
    typedef double local_scalar_t__;
    vars__.resize(0);
    stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
    static const char* function__ = "model_exp_namespace::write_array";
    (void)function__;  // dummy to suppress unused var warning
    // read-transform, write parameters
    double lambda = in__.scalar_lb_constrain(0);
    vars__.push_back(lambda);
    double lp__ = 0.0;
    (void)lp__;  // dummy to suppress unused var warning
    stan::math::accumulator<double> lp_accum__;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void)DUMMY_VAR__;  // suppress unused var warning
    if (!include_tparams__ && !include_gqs__) return;
    try {
      if (!include_gqs__ && !include_tparams__) return;
      if (!include_gqs__) return;
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, current_statement_begin__,
                                  prog_reader__());
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
  }
  template <typename RNG>
  void write_array(RNG& base_rng,
                   Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                   Eigen::Matrix<double, Eigen::Dynamic, 1>& vars,
                   bool include_tparams = true, bool include_gqs = true,
                   std::ostream* pstream = 0) const {
    std::vector<double> params_r_vec(params_r.size());
    for (int i = 0; i < params_r.size(); ++i) params_r_vec[i] = params_r(i);
    std::vector<double> vars_vec;
    std::vector<int> params_i_vec;
    write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams,
                include_gqs, pstream);
    vars.resize(vars_vec.size());
    for (int i = 0; i < vars.size(); ++i) vars(i) = vars_vec[i];
  }
  std::string model_name() const { return "model_exp"; }
  void constrained_param_names(std::vector<std::string>& param_names__,
                               bool include_tparams__ = true,
                               bool include_gqs__ = true) const {
    std::stringstream param_name_stream__;
    param_name_stream__.str(std::string());
    param_name_stream__ << "lambda";
    param_names__.push_back(param_name_stream__.str());
    if (!include_gqs__ && !include_tparams__) return;
    if (include_tparams__) {
    }
    if (!include_gqs__) return;
  }
  void unconstrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
    std::stringstream param_name_stream__;
    param_name_stream__.str(std::string());
    param_name_stream__ << "lambda";
    param_names__.push_back(param_name_stream__.str());
    if (!include_gqs__ && !include_tparams__) return;
    if (include_tparams__) {
    }
    if (!include_gqs__) return;
  }
};  // model
}  // namespace model_exp_namespace
typedef model_exp_namespace::model_exp stan_model;
#ifndef USING_R
stan::model::model_base& new_model(stan::io::var_context& data_context,
                                   unsigned int seed,
                                   std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}
#endif
#endif
