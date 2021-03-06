/* Include files */

#include "threeLinks_opt_joint_limit_sfun.h"
#include "c4_threeLinks_opt_joint_limit.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "threeLinks_opt_joint_limit_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c4_debug_family_names[4] = { "nargin", "nargout", "J", "P_J"
};

/* Function Declarations */
static void initialize_c4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance);
static void initialize_params_c4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance);
static void enable_c4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance);
static void disable_c4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance);
static void set_sim_state_c4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance, const mxArray
   *c4_st);
static void finalize_c4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance);
static void sf_gateway_c4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance);
static void mdl_start_c4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance);
static void initSimStructsc4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_threeLinks_opt_joint_limitInstanceStruct
  *chartInstance, const mxArray *c4_b_P_J, const char_T *c4_identifier, real_T
  c4_y[6]);
static void c4_b_emlrt_marshallIn(SFc4_threeLinks_opt_joint_limitInstanceStruct *
  chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[6]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_c_emlrt_marshallIn
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static real_T c4_norm(SFc4_threeLinks_opt_joint_limitInstanceStruct
                      *chartInstance, real_T c4_x[4]);
static void c4_warning(SFc4_threeLinks_opt_joint_limitInstanceStruct
  *chartInstance);
static void c4_b_warning(SFc4_threeLinks_opt_joint_limitInstanceStruct
  *chartInstance, char_T c4_varargin_1[14]);
static void c4_d_emlrt_marshallIn(SFc4_threeLinks_opt_joint_limitInstanceStruct *
  chartInstance, const mxArray *c4_sprintf, const char_T *c4_identifier, char_T
  c4_y[14]);
static void c4_e_emlrt_marshallIn(SFc4_threeLinks_opt_joint_limitInstanceStruct *
  chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  char_T c4_y[14]);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_f_emlrt_marshallIn
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_g_emlrt_marshallIn
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance, const mxArray
   *c4_b_is_active_c4_threeLinks_opt_joint_limit, const char_T *c4_identifier);
static uint8_T c4_h_emlrt_marshallIn
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_threeLinks_opt_joint_limitInstanceStruct *
  chartInstance);
static void init_simulink_io_address
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc4_threeLinks_opt_joint_limit(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_is_active_c4_threeLinks_opt_joint_limit = 0U;
}

static void initialize_params_c4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  const mxArray *c4_b_y = NULL;
  uint8_T c4_hoistedGlobal;
  const mxArray *c4_c_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(2, 1), false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", *chartInstance->c4_P_J, 0, 0U, 1U,
    0U, 2, 3, 2), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_hoistedGlobal = chartInstance->c4_is_active_c4_threeLinks_opt_joint_limit;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance, const mxArray
   *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[6];
  int32_T c4_i0;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("P_J", c4_u, 0)),
                      "P_J", c4_dv0);
  for (c4_i0 = 0; c4_i0 < 6; c4_i0++) {
    (*chartInstance->c4_P_J)[c4_i0] = c4_dv0[c4_i0];
  }

  chartInstance->c4_is_active_c4_threeLinks_opt_joint_limit =
    c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "is_active_c4_threeLinks_opt_joint_limit", c4_u, 1)),
    "is_active_c4_threeLinks_opt_joint_limit");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_threeLinks_opt_joint_limit(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance)
{
  int32_T c4_i1;
  int32_T c4_i2;
  uint32_T c4_debug_family_var_map[4];
  real_T c4_b_J[6];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  real_T c4_b_P_J[6];
  int32_T c4_i3;
  int32_T c4_i4;
  real_T c4_a[6];
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  real_T c4_x;
  real_T c4_y[4];
  int32_T c4_i9;
  real_T c4_b_x;
  int32_T c4_i10;
  real_T c4_b[6];
  real_T c4_c_x;
  int32_T c4_i11;
  real_T c4_d_x;
  real_T c4_b_y;
  real_T c4_e_x;
  real_T c4_f_x;
  int32_T c4_i12;
  real_T c4_g_x;
  int32_T c4_i13;
  real_T c4_c_y;
  real_T c4_d;
  real_T c4_h_x;
  real_T c4_i_x;
  real_T c4_j_x;
  real_T c4_k_x;
  real_T c4_d_y;
  real_T c4_l_x;
  real_T c4_m_x;
  real_T c4_n_x;
  real_T c4_e_y;
  real_T c4_b_d;
  real_T c4_A;
  real_T c4_b_A;
  real_T c4_B;
  real_T c4_b_B;
  real_T c4_o_x;
  real_T c4_p_x;
  real_T c4_f_y;
  real_T c4_g_y;
  real_T c4_q_x;
  real_T c4_r_x;
  real_T c4_h_y;
  real_T c4_i_y;
  real_T c4_r;
  real_T c4_c_B;
  real_T c4_d_B;
  real_T c4_j_y;
  real_T c4_k_y;
  real_T c4_l_y;
  real_T c4_m_y;
  real_T c4_t;
  real_T c4_c_A;
  real_T c4_d_A;
  real_T c4_e_B;
  real_T c4_f_B;
  real_T c4_s_x;
  real_T c4_t_x;
  real_T c4_n_y;
  real_T c4_o_y;
  real_T c4_u_x;
  real_T c4_v_x;
  real_T c4_p_y;
  real_T c4_q_y;
  real_T c4_r_y;
  real_T c4_s_y;
  real_T c4_t_y[4];
  real_T c4_e_A;
  real_T c4_f_A;
  real_T c4_g_B;
  real_T c4_h_B;
  real_T c4_w_x;
  real_T c4_x_x;
  real_T c4_u_y;
  real_T c4_v_y;
  real_T c4_y_x;
  real_T c4_ab_x;
  real_T c4_w_y;
  real_T c4_x_y;
  real_T c4_y_y;
  real_T c4_ab_y;
  real_T c4_n1x;
  int32_T c4_i14;
  real_T c4_n1xinv;
  real_T c4_bb_y[4];
  real_T c4_rc;
  real_T c4_bb_x;
  boolean_T c4_b_b;
  int32_T c4_i15;
  int32_T c4_i16;
  real_T c4_cb_x;
  const mxArray *c4_cb_y = NULL;
  static char_T c4_rfmt[6] = { '%', '1', '4', '.', '6', 'e' };

  int32_T c4_i17;
  int32_T c4_i18;
  const mxArray *c4_db_y = NULL;
  int32_T c4_i19;
  char_T c4_str[14];
  int32_T c4_i20;
  int32_T c4_i21;
  const mxArray *c4_eb_y = NULL;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i1 = 0; c4_i1 < 6; c4_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c4_J)[c4_i1], 0U, 1U, 0U,
                          chartInstance->c4_sfEvent, false);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i2 = 0; c4_i2 < 6; c4_i2++) {
    c4_b_J[c4_i2] = (*chartInstance->c4_J)[c4_i2];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_b_J, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_b_P_J, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 2);
  for (c4_i3 = 0; c4_i3 < 6; c4_i3++) {
    c4_a[c4_i3] = c4_b_J[c4_i3];
  }

  c4_i4 = 0;
  for (c4_i5 = 0; c4_i5 < 2; c4_i5++) {
    c4_i7 = 0;
    for (c4_i8 = 0; c4_i8 < 3; c4_i8++) {
      c4_b[c4_i8 + c4_i4] = c4_b_J[c4_i7 + c4_i5];
      c4_i7 += 2;
    }

    c4_i4 += 3;
  }

  for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
    c4_i9 = 0;
    c4_i10 = 0;
    for (c4_i11 = 0; c4_i11 < 2; c4_i11++) {
      c4_y[c4_i9 + c4_i6] = 0.0;
      c4_i12 = 0;
      for (c4_i13 = 0; c4_i13 < 3; c4_i13++) {
        c4_y[c4_i9 + c4_i6] += c4_a[c4_i12 + c4_i6] * c4_b[c4_i13 + c4_i10];
        c4_i12 += 2;
      }

      c4_i9 += 2;
      c4_i10 += 3;
    }
  }

  c4_x = c4_y[1];
  c4_b_x = c4_x;
  c4_c_x = c4_b_x;
  c4_d_x = c4_c_x;
  c4_b_y = muDoubleScalarAbs(c4_d_x);
  c4_e_x = 0.0;
  c4_f_x = c4_e_x;
  c4_g_x = c4_f_x;
  c4_c_y = muDoubleScalarAbs(c4_g_x);
  c4_d = c4_b_y + c4_c_y;
  c4_h_x = c4_y[0];
  c4_i_x = c4_h_x;
  c4_j_x = c4_i_x;
  c4_k_x = c4_j_x;
  c4_d_y = muDoubleScalarAbs(c4_k_x);
  c4_l_x = 0.0;
  c4_m_x = c4_l_x;
  c4_n_x = c4_m_x;
  c4_e_y = muDoubleScalarAbs(c4_n_x);
  c4_b_d = c4_d_y + c4_e_y;
  if (c4_d > c4_b_d) {
    c4_b_A = c4_y[0];
    c4_b_B = c4_y[1];
    c4_p_x = c4_b_A;
    c4_g_y = c4_b_B;
    c4_r_x = c4_p_x;
    c4_i_y = c4_g_y;
    c4_r = c4_r_x / c4_i_y;
    c4_d_B = c4_r * c4_y[3] - c4_y[2];
    c4_k_y = c4_d_B;
    c4_m_y = c4_k_y;
    c4_t = 1.0 / c4_m_y;
    c4_d_A = c4_y[3];
    c4_f_B = c4_y[1];
    c4_t_x = c4_d_A;
    c4_o_y = c4_f_B;
    c4_v_x = c4_t_x;
    c4_q_y = c4_o_y;
    c4_s_y = c4_v_x / c4_q_y;
    c4_t_y[0] = c4_s_y * c4_t;
    c4_t_y[1] = -c4_t;
    c4_f_A = -c4_y[2];
    c4_h_B = c4_y[1];
    c4_x_x = c4_f_A;
    c4_v_y = c4_h_B;
    c4_ab_x = c4_x_x;
    c4_x_y = c4_v_y;
    c4_ab_y = c4_ab_x / c4_x_y;
    c4_t_y[2] = c4_ab_y * c4_t;
    c4_t_y[3] = c4_r * c4_t;
  } else {
    c4_A = c4_y[1];
    c4_B = c4_y[0];
    c4_o_x = c4_A;
    c4_f_y = c4_B;
    c4_q_x = c4_o_x;
    c4_h_y = c4_f_y;
    c4_r = c4_q_x / c4_h_y;
    c4_c_B = c4_y[3] - c4_r * c4_y[2];
    c4_j_y = c4_c_B;
    c4_l_y = c4_j_y;
    c4_t = 1.0 / c4_l_y;
    c4_c_A = c4_y[3];
    c4_e_B = c4_y[0];
    c4_s_x = c4_c_A;
    c4_n_y = c4_e_B;
    c4_u_x = c4_s_x;
    c4_p_y = c4_n_y;
    c4_r_y = c4_u_x / c4_p_y;
    c4_t_y[0] = c4_r_y * c4_t;
    c4_t_y[1] = -c4_r * c4_t;
    c4_e_A = -c4_y[2];
    c4_g_B = c4_y[0];
    c4_w_x = c4_e_A;
    c4_u_y = c4_g_B;
    c4_y_x = c4_w_x;
    c4_w_y = c4_u_y;
    c4_y_y = c4_y_x / c4_w_y;
    c4_t_y[2] = c4_y_y * c4_t;
    c4_t_y[3] = c4_t;
  }

  c4_n1x = c4_norm(chartInstance, c4_y);
  for (c4_i14 = 0; c4_i14 < 4; c4_i14++) {
    c4_bb_y[c4_i14] = c4_t_y[c4_i14];
  }

  c4_n1xinv = c4_norm(chartInstance, c4_bb_y);
  c4_rc = 1.0 / (c4_n1x * c4_n1xinv);
  if ((c4_n1x == 0.0) || (c4_n1xinv == 0.0) || (c4_rc == 0.0)) {
    c4_warning(chartInstance);
  } else {
    c4_bb_x = c4_rc;
    c4_b_b = muDoubleScalarIsNaN(c4_bb_x);
    if (c4_b_b || (c4_rc < 2.2204460492503131E-16)) {
      c4_cb_x = c4_rc;
      c4_cb_y = NULL;
      sf_mex_assign(&c4_cb_y, sf_mex_create("y", c4_rfmt, 10, 0U, 1U, 0U, 2, 1,
        6), false);
      c4_db_y = NULL;
      sf_mex_assign(&c4_db_y, sf_mex_create("y", &c4_cb_x, 0, 0U, 0U, 0U, 0),
                    false);
      c4_d_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                            (sfGlobalDebugInstanceStruct, "sprintf", 1U, 2U, 14,
        c4_cb_y, 14, c4_db_y), "sprintf", c4_str);
      c4_b_warning(chartInstance, c4_str);
    }
  }

  c4_i15 = 0;
  for (c4_i16 = 0; c4_i16 < 2; c4_i16++) {
    c4_i18 = 0;
    for (c4_i19 = 0; c4_i19 < 3; c4_i19++) {
      c4_b[c4_i19 + c4_i15] = c4_b_J[c4_i18 + c4_i16];
      c4_i18 += 2;
    }

    c4_i15 += 3;
  }

  for (c4_i17 = 0; c4_i17 < 6; c4_i17++) {
    c4_b_P_J[c4_i17] = 0.0;
  }

  for (c4_i20 = 0; c4_i20 < 3; c4_i20++) {
    c4_i21 = 0;
    c4_i22 = 0;
    for (c4_i23 = 0; c4_i23 < 2; c4_i23++) {
      c4_b_P_J[c4_i21 + c4_i20] = 0.0;
      c4_i25 = 0;
      for (c4_i26 = 0; c4_i26 < 2; c4_i26++) {
        c4_b_P_J[c4_i21 + c4_i20] += c4_b[c4_i25 + c4_i20] * c4_t_y[c4_i26 +
          c4_i22];
        c4_i25 += 3;
      }

      c4_i21 += 3;
      c4_i22 += 2;
    }
  }

  sf_mex_printf("%s =\\n", "P_J");
  c4_eb_y = NULL;
  sf_mex_assign(&c4_eb_y, sf_mex_create("y", c4_b_P_J, 0, 0U, 1U, 0U, 2, 3, 2),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c4_eb_y);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i24 = 0; c4_i24 < 6; c4_i24++) {
    (*chartInstance->c4_P_J)[c4_i24] = c4_b_P_J[c4_i24];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_threeLinks_opt_joint_limitMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c4_i27 = 0; c4_i27 < 6; c4_i27++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c4_P_J)[c4_i27], 1U, 1U, 0U,
                          chartInstance->c4_sfEvent, false);
  }
}

static void mdl_start_c4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc4_threeLinks_opt_joint_limit
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)c4_machineNumber;
  (void)c4_chartNumber;
  (void)c4_instanceNumber;
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_i28;
  int32_T c4_i29;
  const mxArray *c4_y = NULL;
  int32_T c4_i30;
  real_T c4_u[6];
  SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance;
  chartInstance = (SFc4_threeLinks_opt_joint_limitInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_i28 = 0;
  for (c4_i29 = 0; c4_i29 < 2; c4_i29++) {
    for (c4_i30 = 0; c4_i30 < 3; c4_i30++) {
      c4_u[c4_i30 + c4_i28] = (*(real_T (*)[6])c4_inData)[c4_i30 + c4_i28];
    }

    c4_i28 += 3;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 3, 2), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_threeLinks_opt_joint_limitInstanceStruct
  *chartInstance, const mxArray *c4_b_P_J, const char_T *c4_identifier, real_T
  c4_y[6])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_P_J), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_P_J);
}

static void c4_b_emlrt_marshallIn(SFc4_threeLinks_opt_joint_limitInstanceStruct *
  chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[6])
{
  real_T c4_dv1[6];
  int32_T c4_i31;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv1, 1, 0, 0U, 1, 0U, 2, 3, 2);
  for (c4_i31 = 0; c4_i31 < 6; c4_i31++) {
    c4_y[c4_i31] = c4_dv1[c4_i31];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_P_J;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[6];
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance;
  chartInstance = (SFc4_threeLinks_opt_joint_limitInstanceStruct *)
    chartInstanceVoid;
  c4_b_P_J = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_P_J), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_P_J);
  c4_i32 = 0;
  for (c4_i33 = 0; c4_i33 < 2; c4_i33++) {
    for (c4_i34 = 0; c4_i34 < 3; c4_i34++) {
      (*(real_T (*)[6])c4_outData)[c4_i34 + c4_i32] = c4_y[c4_i34 + c4_i32];
    }

    c4_i32 += 3;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_i35;
  int32_T c4_i36;
  const mxArray *c4_y = NULL;
  int32_T c4_i37;
  real_T c4_u[6];
  SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance;
  chartInstance = (SFc4_threeLinks_opt_joint_limitInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_i35 = 0;
  for (c4_i36 = 0; c4_i36 < 3; c4_i36++) {
    for (c4_i37 = 0; c4_i37 < 2; c4_i37++) {
      c4_u[c4_i37 + c4_i35] = (*(real_T (*)[6])c4_inData)[c4_i37 + c4_i35];
    }

    c4_i35 += 2;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 2, 3), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance;
  chartInstance = (SFc4_threeLinks_opt_joint_limitInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_c_emlrt_marshallIn
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance;
  chartInstance = (SFc4_threeLinks_opt_joint_limitInstanceStruct *)
    chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_threeLinks_opt_joint_limit_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static real_T c4_norm(SFc4_threeLinks_opt_joint_limitInstanceStruct
                      *chartInstance, real_T c4_x[4])
{
  real_T c4_y;
  int32_T c4_j;
  real_T c4_b_j;
  real_T c4_s;
  int32_T c4_i;
  real_T c4_b_x;
  real_T c4_b_i;
  boolean_T c4_b;
  real_T c4_c_x;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_b_y;
  boolean_T exitg1;
  (void)chartInstance;
  c4_y = 0.0;
  c4_j = 0;
  exitg1 = false;
  while ((!exitg1) && (c4_j < 2)) {
    c4_b_j = 1.0 + (real_T)c4_j;
    c4_s = 0.0;
    for (c4_i = 0; c4_i < 2; c4_i++) {
      c4_b_i = 1.0 + (real_T)c4_i;
      c4_c_x = c4_x[((int32_T)c4_b_i + (((int32_T)c4_b_j - 1) << 1)) - 1];
      c4_d_x = c4_c_x;
      c4_e_x = c4_d_x;
      c4_b_y = muDoubleScalarAbs(c4_e_x);
      c4_s += c4_b_y;
    }

    c4_b_x = c4_s;
    c4_b = muDoubleScalarIsNaN(c4_b_x);
    if (c4_b) {
      c4_y = rtNaN;
      exitg1 = true;
    } else {
      if (c4_s > c4_y) {
        c4_y = c4_s;
      }

      c4_j++;
    }
  }

  return c4_y;
}

static void c4_warning(SFc4_threeLinks_opt_joint_limitInstanceStruct
  *chartInstance)
{
  const mxArray *c4_y = NULL;
  static char_T c4_cv0[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c4_b_y = NULL;
  static char_T c4_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c4_c_y = NULL;
  static char_T c4_msgID[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't',
    'r', 'i', 'x' };

  (void)chartInstance;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv0, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_msgID, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c4_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c4_b_y, 14, c4_c_y));
}

static void c4_b_warning(SFc4_threeLinks_opt_joint_limitInstanceStruct
  *chartInstance, char_T c4_varargin_1[14])
{
  const mxArray *c4_y = NULL;
  static char_T c4_cv2[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c4_b_y = NULL;
  static char_T c4_cv3[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c4_c_y = NULL;
  static char_T c4_msgID[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i', 'o',
    'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  const mxArray *c4_d_y = NULL;
  (void)chartInstance;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv2, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv3, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_msgID, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_varargin_1, 10, 0U, 1U, 0U, 2, 1,
    14), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c4_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    3U, 14, c4_b_y, 14, c4_c_y, 14, c4_d_y));
}

static void c4_d_emlrt_marshallIn(SFc4_threeLinks_opt_joint_limitInstanceStruct *
  chartInstance, const mxArray *c4_sprintf, const char_T *c4_identifier, char_T
  c4_y[14])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_sprintf), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_sprintf);
}

static void c4_e_emlrt_marshallIn(SFc4_threeLinks_opt_joint_limitInstanceStruct *
  chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  char_T c4_y[14])
{
  char_T c4_cv4[14];
  int32_T c4_i38;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_cv4, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c4_i38 = 0; c4_i38 < 14; c4_i38++) {
    c4_y[c4_i38] = c4_cv4[c4_i38];
  }

  sf_mex_destroy(&c4_u);
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance;
  chartInstance = (SFc4_threeLinks_opt_joint_limitInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_f_emlrt_marshallIn
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i39;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i39, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i39;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance;
  chartInstance = (SFc4_threeLinks_opt_joint_limitInstanceStruct *)
    chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_g_emlrt_marshallIn
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance, const mxArray
   *c4_b_is_active_c4_threeLinks_opt_joint_limit, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_threeLinks_opt_joint_limit), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_threeLinks_opt_joint_limit);
  return c4_y;
}

static uint8_T c4_h_emlrt_marshallIn
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_threeLinks_opt_joint_limitInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance)
{
  chartInstance->c4_J = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_P_J = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c4_threeLinks_opt_joint_limit_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2409229974U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2695305236U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(869403323U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(20614060U);
}

mxArray* sf_c4_threeLinks_opt_joint_limit_get_post_codegen_info(void);
mxArray *sf_c4_threeLinks_opt_joint_limit_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Y2aBg1pmGVw0GKzFseBDGB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(2);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c4_threeLinks_opt_joint_limit_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_threeLinks_opt_joint_limit_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_threeLinks_opt_joint_limit_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c4_threeLinks_opt_joint_limit_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c4_threeLinks_opt_joint_limit_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c4_threeLinks_opt_joint_limit(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"P_J\",},{M[8],M[0],T\"is_active_c4_threeLinks_opt_joint_limit\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_threeLinks_opt_joint_limit_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance =
      (SFc4_threeLinks_opt_joint_limitInstanceStruct *)sf_get_chart_instance_ptr
      (S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _threeLinks_opt_joint_limitMachineNumber_,
           4,
           1,
           1,
           0,
           2,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_threeLinks_opt_joint_limitMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _threeLinks_opt_joint_limitMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _threeLinks_opt_joint_limitMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"J");
          _SFD_SET_DATA_PROPS(1,2,0,1,"P_J");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,46);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2U;
          dimVector[1]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _threeLinks_opt_joint_limitMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance =
      (SFc4_threeLinks_opt_joint_limitInstanceStruct *)sf_get_chart_instance_ptr
      (S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c4_J);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c4_P_J);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sPtGjOO5rAP2NnLg95lkllC";
}

static void sf_opaque_initialize_c4_threeLinks_opt_joint_limit(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_threeLinks_opt_joint_limitInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_threeLinks_opt_joint_limit
    ((SFc4_threeLinks_opt_joint_limitInstanceStruct*) chartInstanceVar);
  initialize_c4_threeLinks_opt_joint_limit
    ((SFc4_threeLinks_opt_joint_limitInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_threeLinks_opt_joint_limit(void
  *chartInstanceVar)
{
  enable_c4_threeLinks_opt_joint_limit
    ((SFc4_threeLinks_opt_joint_limitInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_threeLinks_opt_joint_limit(void
  *chartInstanceVar)
{
  disable_c4_threeLinks_opt_joint_limit
    ((SFc4_threeLinks_opt_joint_limitInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_threeLinks_opt_joint_limit(void
  *chartInstanceVar)
{
  sf_gateway_c4_threeLinks_opt_joint_limit
    ((SFc4_threeLinks_opt_joint_limitInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_threeLinks_opt_joint_limit
  (SimStruct* S)
{
  return get_sim_state_c4_threeLinks_opt_joint_limit
    ((SFc4_threeLinks_opt_joint_limitInstanceStruct *)sf_get_chart_instance_ptr
     (S));                             /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_threeLinks_opt_joint_limit(SimStruct* S,
  const mxArray *st)
{
  set_sim_state_c4_threeLinks_opt_joint_limit
    ((SFc4_threeLinks_opt_joint_limitInstanceStruct*)sf_get_chart_instance_ptr(S),
     st);
}

static void sf_opaque_terminate_c4_threeLinks_opt_joint_limit(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_threeLinks_opt_joint_limitInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_threeLinks_opt_joint_limit_optimization_info();
    }

    finalize_c4_threeLinks_opt_joint_limit
      ((SFc4_threeLinks_opt_joint_limitInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_threeLinks_opt_joint_limit
    ((SFc4_threeLinks_opt_joint_limitInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_threeLinks_opt_joint_limit(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_threeLinks_opt_joint_limit
      ((SFc4_threeLinks_opt_joint_limitInstanceStruct*)sf_get_chart_instance_ptr
       (S));
  }
}

static void mdlSetWorkWidths_c4_threeLinks_opt_joint_limit(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_threeLinks_opt_joint_limit_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 4);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2359011292U));
  ssSetChecksum1(S,(1176474246U));
  ssSetChecksum2(S,(1146947747U));
  ssSetChecksum3(S,(2154738109U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_threeLinks_opt_joint_limit(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_threeLinks_opt_joint_limit(SimStruct *S)
{
  SFc4_threeLinks_opt_joint_limitInstanceStruct *chartInstance;
  chartInstance = (SFc4_threeLinks_opt_joint_limitInstanceStruct *)utMalloc
    (sizeof(SFc4_threeLinks_opt_joint_limitInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_threeLinks_opt_joint_limitInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_threeLinks_opt_joint_limit;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_threeLinks_opt_joint_limit;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_threeLinks_opt_joint_limit;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c4_threeLinks_opt_joint_limit;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_threeLinks_opt_joint_limit;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_threeLinks_opt_joint_limit;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_threeLinks_opt_joint_limit;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_threeLinks_opt_joint_limit;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_threeLinks_opt_joint_limit;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_threeLinks_opt_joint_limit;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_threeLinks_opt_joint_limit;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c4_threeLinks_opt_joint_limit(chartInstance);
}

void c4_threeLinks_opt_joint_limit_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_threeLinks_opt_joint_limit(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_threeLinks_opt_joint_limit(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_threeLinks_opt_joint_limit(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_threeLinks_opt_joint_limit_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
