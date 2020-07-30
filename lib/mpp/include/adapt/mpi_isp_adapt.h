/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2012-2019. All rights reserved.
 * Description: Function of mpi_isp_adapt.h
 * Author: ISP SW
 * Create: 2012/06/28
 */

#ifndef __MPI_ISP_ADAPT_H__
#define __MPI_ISP_ADAPT_H__

#include "hi_type.h"
#include "hi_common_adapt.h"
#include "hi_comm_isp_adapt.h"
#include "hi_comm_3a_adapt.h"
#include "hi_debug_adapt.h"
#include "hi_comm_sns_adapt.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

hi_s32 hi_mpi_isp_init(hi_vi_pipe vi_pipe);
hi_s32 hi_mpi_isp_mem_init(hi_vi_pipe vi_pipe);
hi_s32 hi_mpi_isp_run(hi_vi_pipe vi_pipe);
hi_s32 hi_mpi_isp_run_once(hi_vi_pipe vi_pipe);
hi_s32 hi_mpi_isp_exit(hi_vi_pipe vi_pipe);

hi_s32 hi_mpi_isp_sensor_reg_callback(hi_vi_pipe vi_pipe, hi_isp_sns_attr_info *sns_attr_info,
                                      hi_isp_sensor_register *sns_register);
hi_s32 hi_mpi_isp_sensor_unreg_callback(hi_vi_pipe vi_pipe, SENSOR_ID sensor_id);

/* if have registered multy libs, set bind attr to appoint the active lib. */
hi_s32 hi_mpi_isp_set_bind_attr(hi_vi_pipe vi_pipe, const hi_isp_bind_attr *bind_attr);
hi_s32 hi_mpi_isp_get_bind_attr(hi_vi_pipe vi_pipe, hi_isp_bind_attr *bind_attr);
hi_s32 hi_mpi_isp_ae_lib_reg_callback(hi_vi_pipe vi_pipe, hi_isp_alg_lib *ae_lib, hi_isp_ae_register *ae_register);
hi_s32 hi_mpi_isp_awb_lib_reg_callback(hi_vi_pipe vi_pipe, hi_isp_alg_lib *awb_lib, hi_isp_awb_register *awb_register);
hi_s32 hi_mpi_isp_ae_lib_unreg_callback(hi_vi_pipe vi_pipe, hi_isp_alg_lib *ae_lib);
hi_s32 hi_mpi_isp_awb_lib_unreg_callback(hi_vi_pipe vi_pipe, hi_isp_alg_lib *awb_lib);

hi_s32 hi_mpi_isp_get_lightbox_gain(hi_vi_pipe vi_pipe,
                                    hi_isp_awb_calibration_gain *awb_calibration_gain);

hi_s32 hi_mpi_isp_set_pub_attr(hi_vi_pipe vi_pipe, const hi_isp_pub_attr *pub_attr);
hi_s32 hi_mpi_isp_get_pub_attr(hi_vi_pipe vi_pipe, hi_isp_pub_attr *pub_attr);

hi_s32 hi_mpi_isp_set_pipe_differ_attr(hi_vi_pipe vi_pipe, const hi_isp_pipe_diff_attr *pipe_differ);
hi_s32 hi_mpi_isp_get_pipe_differ_attr(hi_vi_pipe vi_pipe, hi_isp_pipe_diff_attr *pipe_differ);

hi_s32 hi_mpi_isp_get_vd_time_out(hi_vi_pipe vi_pipe, hi_isp_vd_type isp_vd_type, hi_u32 milli_sec);
hi_s32 hi_mpi_isp_query_inner_state_info(hi_vi_pipe vi_pipe, hi_isp_inner_state_info *inner_state_info);
hi_s32 hi_mpi_isp_get_ae_statistics(hi_vi_pipe vi_pipe, hi_isp_ae_statistics *ae_stat);
hi_s32 hi_mpi_isp_get_ae_stitch_statistics(hi_vi_pipe vi_pipe, hi_isp_ae_stitch_statistics *stitch_stat);
hi_s32 hi_mpi_isp_get_mg_statistics(hi_vi_pipe vi_pipe, hi_isp_mg_statistics *mg_stat);

hi_s32 hi_mpi_isp_get_wb_statistics(hi_vi_pipe vi_pipe, hi_isp_wb_statistics *wb_stat);
hi_s32 hi_mpi_isp_get_wb_stitch_statistics(hi_vi_pipe vi_pipe, hi_isp_wb_stitch_statistics *stitch_wb_stat);

hi_s32 hi_mpi_isp_get_focus_statistics(hi_vi_pipe vi_pipe, hi_isp_af_statistics *af_stat);

hi_s32 hi_mpi_isp_set_statistics_config(hi_vi_pipe vi_pipe, const hi_isp_statistics_cfg *stat_cfg);
hi_s32 hi_mpi_isp_get_statistics_config(hi_vi_pipe vi_pipe, hi_isp_statistics_cfg *stat_cfg);

hi_s32 hi_mpi_isp_get_isp_reg_attr(hi_vi_pipe vi_pipe, hi_isp_reg_attr *isp_reg_attr);

hi_s32 hi_mpi_isp_set_fmw_state(hi_vi_pipe vi_pipe, const hi_isp_fmw_state state);
hi_s32 hi_mpi_isp_get_fmw_state(hi_vi_pipe vi_pipe, hi_isp_fmw_state *state);

hi_s32 hi_mpi_isp_set_debug(hi_vi_pipe vi_pipe, const hi_isp_debug_info *isp_debug);
hi_s32 hi_mpi_isp_get_debug(hi_vi_pipe vi_pipe, hi_isp_debug_info *isp_debug);

hi_s32 hi_mpi_isp_set_mod_param(const hi_isp_mod_param *mod_param);
hi_s32 hi_mpi_isp_get_mod_param(hi_isp_mod_param *mod_param);
hi_s32 hi_mpi_isp_set_ctrl_param(hi_vi_pipe vi_pipe, const hi_isp_ctrl_param *isp_ctrl_param);
hi_s32 hi_mpi_isp_get_ctrl_param(hi_vi_pipe vi_pipe, hi_isp_ctrl_param *isp_ctrl_param);

hi_s32 hi_mpi_isp_set_fswdr_attr(hi_vi_pipe vi_pipe, const hi_isp_wdr_fs_attr *fswdr_attr);
hi_s32 hi_mpi_isp_get_fswdr_attr(hi_vi_pipe vi_pipe, hi_isp_wdr_fs_attr *fswdr_attr);

hi_s32 hi_mpi_isp_set_drc_attr(hi_vi_pipe vi_pipe, const hi_isp_drc_attr *drc);
hi_s32 hi_mpi_isp_get_drc_attr(hi_vi_pipe vi_pipe, hi_isp_drc_attr *drc);

hi_s32 hi_mpi_isp_set_dehaze_attr(hi_vi_pipe vi_pipe, const hi_isp_dehaze_attr *dehaze_attr);
hi_s32 hi_mpi_isp_get_dehaze_attr(hi_vi_pipe vi_pipe, hi_isp_dehaze_attr *dehaze_attr);

hi_s32 hi_mpi_isp_set_ldci_attr(hi_vi_pipe vi_pipe, const hi_isp_ldci_attr *ldci_attr);
hi_s32 hi_mpi_isp_get_ldci_attr(hi_vi_pipe vi_pipe, hi_isp_ldci_attr *ldci_attr);

hi_s32 hi_mpi_isp_set_sns_slave_attr(hi_slave_dev slave_dev, const hi_isp_slave_sns_sync *sns_sync);
hi_s32 hi_mpi_isp_get_sns_slave_attr(hi_slave_dev slav_edev, hi_isp_slave_sns_sync *sns_sync);

hi_s32 hi_mpi_isp_set_module_control(hi_vi_pipe vi_pipe, const hi_isp_module_ctrl *mod_ctrl);
hi_s32 hi_mpi_isp_get_module_control(hi_vi_pipe vi_pipe, hi_isp_module_ctrl *mod_ctrl);

hi_s32 hi_mpi_isp_set_dp_calibrate(hi_vi_pipe vi_pipe, const hi_isp_dp_static_calibrate *dp_calibrate);
hi_s32 hi_mpi_isp_get_dp_calibrate(hi_vi_pipe vi_pipe, hi_isp_dp_static_calibrate *dp_calibrate);

hi_s32 hi_mpi_isp_set_dp_static_attr(hi_vi_pipe vi_pipe, const hi_isp_dp_static_attr *dp_static_attr);
hi_s32 hi_mpi_isp_get_dp_static_attr(hi_vi_pipe vi_pipe,  hi_isp_dp_static_attr *dp_static_attr);

hi_s32 hi_mpi_isp_set_dp_dynamic_attr(hi_vi_pipe vi_pipe, const hi_isp_dp_dynamic_attr *dp_dynamic_attr);
hi_s32 hi_mpi_isp_get_dp_dynamic_attr(hi_vi_pipe vi_pipe, hi_isp_dp_dynamic_attr *dp_dynamic_attr);

hi_s32 hi_mpi_isp_set_dis_attr(hi_vi_pipe vi_pipe, const hi_isp_dis_attr *dis_attr);
hi_s32 hi_mpi_isp_get_dis_attr(hi_vi_pipe vi_pipe, hi_isp_dis_attr *dis_attr);

hi_s32 hi_mpi_isp_set_mesh_shading_attr(hi_vi_pipe vi_pipe, const hi_isp_shading_attr *shading_attr);
hi_s32 hi_mpi_isp_get_mesh_shading_attr(hi_vi_pipe vi_pipe, hi_isp_shading_attr *shading_attr);

hi_s32 hi_mpi_isp_set_mesh_shading_gain_lut_attr(hi_vi_pipe vi_pipe,
                                                 const hi_isp_shading_lut_attr *shading_lut_attr);
hi_s32 hi_mpi_isp_get_mesh_shading_gain_lut_attr(hi_vi_pipe vi_pipe,
                                                 hi_isp_shading_lut_attr *shading_lut_attr);

hi_s32 hi_mpi_isp_set_radial_shading_attr(hi_vi_pipe vi_pipe,
                                          const hi_isp_radial_shading_attr *radial_shading_attr);
hi_s32 hi_mpi_isp_get_radial_shading_attr(hi_vi_pipe vi_pipe,
                                          hi_isp_radial_shading_attr *radial_shading_attr);

hi_s32 hi_mpi_isp_set_auto_color_shading_attr(hi_vi_pipe vi_pipe, const hi_isp_acs_attr *acs_attr);
hi_s32 hi_mpi_isp_get_auto_color_shading_attr(hi_vi_pipe vi_pipe, hi_isp_acs_attr *acs_attr);

hi_s32 hi_mpi_isp_set_radial_shading_lut(hi_vi_pipe vi_pipe,
                                         const hi_isp_radial_shading_lut_attr *radial_shading_lut_attr);
hi_s32 hi_mpi_isp_get_radial_shading_lut(hi_vi_pipe vi_pipe,
                                         hi_isp_radial_shading_lut_attr *radial_shading_lut_attr);

hi_s32 hi_mpi_isp_mesh_shading_calibration(hi_vi_pipe vi_pipe, hi_u16 *src_raw,
                                           hi_isp_mlsc_calibration_cfg *mlsc_cali_cfg,
                                           hi_isp_mesh_shading_table *mlsc_table);

hi_s32 hi_mpi_isp_radial_shading_calibration(hi_vi_pipe vi_pipe, hi_u16 *src_raw,
    hi_isp_rlsc_calibration_cfg *rlsc_cali_cfg, hi_isp_radial_shading_table *rlsc_table);

hi_s32 hi_mpi_isp_set_nr_attr(hi_vi_pipe vi_pipe, const hi_isp_nr_attr *nr_attr);
hi_s32 hi_mpi_isp_get_nr_attr(hi_vi_pipe vi_pipe, hi_isp_nr_attr *nr_attr);

hi_s32 hi_mpi_isp_set_de_attr(hi_vi_pipe vi_pipe, const hi_isp_de_attr *de_attr);
hi_s32 hi_mpi_isp_get_de_attr(hi_vi_pipe vi_pipe, hi_isp_de_attr *de_attr);

hi_s32 hi_mpi_isp_set_color_tone_attr(hi_vi_pipe vi_pipe, const hi_isp_color_tone_attr *ct_attr);
hi_s32 hi_mpi_isp_get_color_tone_attr(hi_vi_pipe vi_pipe, hi_isp_color_tone_attr *ct_attr);

hi_s32 hi_mpi_isp_set_gamma_attr(hi_vi_pipe vi_pipe, const hi_isp_gamma_attr *gamma_attr);
hi_s32 hi_mpi_isp_get_gamma_attr(hi_vi_pipe vi_pipe, hi_isp_gamma_attr *gamma_attr);
hi_s32 hi_mpi_isp_set_pre_gamma_attr(hi_vi_pipe vi_pipe, const hi_isp_pregamma_attr *pre_gamma_attr);
hi_s32 hi_mpi_isp_get_pre_gamma_attr(hi_vi_pipe vi_pipe, hi_isp_pregamma_attr *pre_gamma_attr);

hi_s32 hi_mpi_isp_set_pre_log_lut_attr(hi_vi_pipe vi_pipe, const hi_isp_preloglut_attr *pre_log_lut_attr);
hi_s32 hi_mpi_isp_get_pre_log_lut_attr(hi_vi_pipe vi_pipe, hi_isp_preloglut_attr *pre_log_lut_attr);

hi_s32 hi_mpi_isp_set_log_lut_attr(hi_vi_pipe vi_pipe, const hi_isp_loglut_attr *log_lut_attr);
hi_s32 hi_mpi_isp_get_log_lut_attr(hi_vi_pipe vi_pipe, hi_isp_loglut_attr *log_lut_attr);
hi_s32 hi_mpi_isp_set_local_cac_attr(hi_vi_pipe vi_pipe, const hi_isp_local_cac_attr *local_cac_attr);
hi_s32 hi_mpi_isp_get_local_cac_attr(hi_vi_pipe vi_pipe, hi_isp_local_cac_attr *local_cac_attr);

hi_s32 hi_mpi_isp_set_global_cac_attr(hi_vi_pipe vi_pipe, const hi_isp_global_cac_attr *global_cac_attr);
hi_s32 hi_mpi_isp_get_global_cac_attr(hi_vi_pipe vi_pipe, hi_isp_global_cac_attr *global_cac_attr);

hi_s32 hi_mpi_isp_set_rc_attr(hi_vi_pipe vi_pipe, const hi_isp_rc_attr *rc_attr);
hi_s32 hi_mpi_isp_get_rc_attr(hi_vi_pipe vi_pipe, hi_isp_rc_attr *rc_attr);

hi_s32 hi_mpi_isp_set_sharpen_attr(hi_vi_pipe vi_pipe, const hi_isp_sharpen_attr *shp_attr);
hi_s32 hi_mpi_isp_get_sharpen_attr(hi_vi_pipe vi_pipe, hi_isp_sharpen_attr *shp_attr);

hi_s32 hi_mpi_isp_set_edge_mark_attr(hi_vi_pipe vi_pipe, const hi_isp_edge_mark_attr *isp_edge_mark_attr);
hi_s32 hi_mpi_isp_get_edge_mark_attr(hi_vi_pipe vi_pipe, hi_isp_edge_mark_attr *isp_edge_mark_attr);

hi_s32 hi_mpi_isp_set_hlc_attr(hi_vi_pipe vi_pipe, const hi_isp_hlc_attr *isp_hlc_attr);
hi_s32 hi_mpi_isp_get_hlc_attr(hi_vi_pipe vi_pipe, hi_isp_hlc_attr *isp_hlc_attr);

hi_s32 hi_mpi_isp_set_crosstalk_attr(hi_vi_pipe vi_pipe, const hi_isp_cr_attr *cr_attr);
hi_s32 hi_mpi_isp_get_crosstalk_attr(hi_vi_pipe vi_pipe, hi_isp_cr_attr *cr_attr);

hi_s32 hi_mpi_isp_set_ca_attr(hi_vi_pipe vi_pipe, const hi_isp_ca_attr *ca_attr);
hi_s32 hi_mpi_isp_get_ca_attr(hi_vi_pipe vi_pipe, hi_isp_ca_attr *ca_attr);

hi_s32 hi_mpi_isp_set_anti_false_color_attr(hi_vi_pipe vi_pipe,
                                            const hi_isp_antifalsecolor_attr *anti_false_color);
hi_s32 hi_mpi_isp_get_anti_false_color_attr(hi_vi_pipe vi_pipe,
                                            hi_isp_antifalsecolor_attr *anti_false_color);

hi_s32 hi_mpi_isp_set_demosaic_attr(hi_vi_pipe vi_pipe, const hi_isp_demosaic_attr *demosaic_attr);
hi_s32 hi_mpi_isp_get_demosaic_attr(hi_vi_pipe vi_pipe, hi_isp_demosaic_attr *demosaic_attr);

hi_s32 hi_mpi_isp_set_black_level_attr(hi_vi_pipe vi_pipe, const hi_isp_black_level *black_level);
hi_s32 hi_mpi_isp_get_black_level_attr(hi_vi_pipe vi_pipe, hi_isp_black_level *black_level);

hi_s32 hi_mpi_isp_set_clut_attr(hi_vi_pipe vi_pipe, const hi_isp_clut_attr *clut_attr);
hi_s32 hi_mpi_isp_get_clut_attr(hi_vi_pipe vi_pipe, hi_isp_clut_attr *clut_attr);

hi_s32 hi_mpi_isp_set_clut_coeff(hi_vi_pipe vi_pipe, const hi_isp_clut_lut *clut_lut);
hi_s32 hi_mpi_isp_get_clut_coeff(hi_vi_pipe vi_pipe, hi_isp_clut_lut *clut_lut);

hi_s32 hi_mpi_isp_set_dcf_info(hi_vi_pipe vi_pipe, const hi_isp_dcf_info *isp_dcf);
hi_s32 hi_mpi_isp_get_dcf_info(hi_vi_pipe vi_pipe, hi_isp_dcf_info *isp_dcf);

hi_s32 hi_mpi_isp_set_csc_attr(hi_vi_pipe vi_pipe, const hi_isp_csc_attr *csc_attr);
hi_s32 hi_mpi_isp_get_csc_attr(hi_vi_pipe vi_pipe, hi_isp_csc_attr *cscf_attr);

hi_s32 hi_mpi_isp_set_rgbir_attr(hi_vi_pipe vi_pipe, const hi_isp_rgbir_attr *rgbir_attr);
hi_s32 hi_mpi_isp_get_rgbir_attr(hi_vi_pipe vi_pipe, hi_isp_rgbir_attr *rgbir_attr);

hi_s32 hi_mpi_isp_set_register(hi_vi_pipe vi_pipe, hi_u32 addr, hi_u32 value);
hi_s32 hi_mpi_isp_get_register(hi_vi_pipe vi_pipe, hi_u32 addr, hi_u32 *value);

/* block, return fpn frame when this is function is called. */
hi_s32 hi_mpi_isp_fpn_calibrate(hi_vi_pipe vi_pipe, hi_isp_fpn_calibrate_attr *calibrate_attr);
hi_s32 hi_mpi_isp_set_fpn_attr(hi_vi_pipe vi_pipe, const hi_isp_fpn_attr *fpn_attr);
hi_s32 hi_mpi_isp_get_fpn_attr(hi_vi_pipe vi_pipe, hi_isp_fpn_attr *fpn_attr);

hi_s32 hi_mpi_isp_get_dng_image_static_info(hi_vi_pipe vi_pipe,
                                            hi_isp_dng_image_static_info *dng_image_static_info);
hi_s32 hi_mpi_isp_set_dng_color_param(hi_vi_pipe vi_pipe, const hi_isp_dng_color_param *dng_color_param);
hi_s32 hi_mpi_isp_get_dng_color_param(hi_vi_pipe vi_pipe, hi_isp_dng_color_param *dng_color_param);

hi_s32 hi_mpi_isp_set_smart_info(hi_vi_pipe vi_pipe, const hi_isp_smart_info *smart_info);
hi_s32 hi_mpi_isp_get_smart_info(hi_vi_pipe vi_pipe, hi_isp_smart_info *smart_info);

hi_s32 hi_mpi_isp_set_tunnel_info(hi_vi_pipe vi_pipe, const hi_isp_tunnel_info *tunnel_info);
hi_s32 hi_mpi_isp_get_tunnel_info(hi_vi_pipe vi_pipe, hi_isp_tunnel_info *tunnel_info);
hi_s32 hi_mpi_isp_set_frame_info(hi_vi_pipe vi_pipe, const hi_isp_frame_info *isp_frame);
hi_s32 hi_mpi_isp_get_frame_info(hi_vi_pipe vi_pipe, const hi_isp_frame_info *isp_frame);

hi_s32 hi_mpi_isp_ir_auto_run_once(hi_vi_pipe vi_pipe, hi_isp_ir_auto_attr *ir_attr);
hi_s32 hi_mpi_isp_set_raw_pos(hi_vi_pipe vi_pipe, const  hi_isp_raw_pos_attr *raw_pos_attr);
hi_s32 hi_mpi_isp_get_raw_pos(hi_vi_pipe vi_pipe,   hi_isp_raw_pos_attr *raw_pos_attr);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */
#endif /* __MPI_ISP_ADAPT_H__ */
