#ifndef __c4_threeLinks_opt_joint_limit_h__
#define __c4_threeLinks_opt_joint_limit_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_threeLinks_opt_joint_limitInstanceStruct
#define typedef_SFc4_threeLinks_opt_joint_limitInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_threeLinks_opt_joint_limit;
  real_T (*c4_J)[6];
  real_T (*c4_P_J)[6];
} SFc4_threeLinks_opt_joint_limitInstanceStruct;

#endif                                 /*typedef_SFc4_threeLinks_opt_joint_limitInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c4_threeLinks_opt_joint_limit_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_threeLinks_opt_joint_limit_get_check_sum(mxArray *plhs[]);
extern void c4_threeLinks_opt_joint_limit_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
