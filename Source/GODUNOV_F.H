
#ifndef _GODUNOV_F_H_
#define _GODUNOV_F_H_

#ifdef BL_LANG_FORT
#    define FORT_TEST_U_RHO         testurho
#    define FORT_TEST_UMAC_RHO      testumacrho
#    define FORT_ESTDT              estmdt
#    define FORT_TRANSVEL           transvel
#    define FORT_ESTATE             estate
#    define FORT_ESTATE_FPU         estatefpu
#    define FORT_ESTATE_BDS         estatebds
#    define FORT_ADV_FORCING        advforcing
#    define FORT_SYNC_ADV_FORCING   syncadvforcing
#    define FORT_CONSSCALMINMAX     consscalminmax
#    define FORT_CONVSCALMINMAX     convscalminmax
#    define FORT_UPDATE_TF          updatetf
#    define FORT_CORRECT_TF         correcttf
#    define FORT_UPDATE_AOFS_TF     updateaofstf
#    define FORT_UPDATE_AOFS_TF_GP  updateaofstfgp
#    define FORT_SUM_TF_GP_VISC     sumtfgpvisc
#    define FORT_SUM_TF_DIVU_VISC   sumtfdivuvisc
#    define FORT_SUM_TF_GP          sumtfgp
#    define FORT_SUM_TF_DIVU        sumtfdivu
#    define FORT_SET_PARAMS         setparams
#else
#  if defined(BL_FORT_USE_UPPERCASE)
#    define FORT_TEST_U_RHO         TESTURHO 
#    define FORT_TEST_UMAC_RHO      TESTUMACRHO
#    define FORT_ESTDT              ESTMDT 
#    define FORT_TRANSVEL           TRANSVEL  
#    define FORT_ESTATE             ESTATE    
#    define FORT_ESTATE_FPU         ESTATEFPU
#    define FORT_ESTATE_BDS         ESTATEBDS
#    define FORT_ADV_FORCING        ADVFORCING    
#    define FORT_SYNC_ADV_FORCING   SYNCADVFORCING   
#    define FORT_CONSSCALMINMAX     CONSSCALMINMAX
#    define FORT_CONVSCALMINMAX     CONVSCALMINMAX
#    define FORT_UPDATE_TF          UPDATETF 
#    define FORT_CORRECT_TF         CORRECTTF 
#    define FORT_UPDATE_AOFS_TF     UPDATEAOFSTF 
#    define FORT_UPDATE_AOFS_TF_GP  UPDATEAOFSTFGP 
#    define FORT_SUM_TF_GP_VISC     SUMTFGPVISC 
#    define FORT_SUM_TF_DIVU_VISC   SUMTFDIVUVISC 
#    define FORT_SUM_TF_GP          SUMTFGP 
#    define FORT_SUM_TF_DIVU        SUMTFDIVU 
#    define FORT_SET_PARAMS         SETPARAMS
#  elif defined(BL_FORT_USE_LOWERCASE)
#    define FORT_TEST_U_RHO         testurho
#    define FORT_TEST_UMAC_RHO      testumacrho
#    define FORT_ESTDT              estmdt
#    define FORT_TRANSVEL           transvel
#    define FORT_ESTATE             estate
#    define FORT_ESTATE_FPU         estatefpu
#    define FORT_ESTATE_BDS         estatebds
#    define FORT_ADV_FORCING        advforcing
#    define FORT_SYNC_ADV_FORCING   syncadvforcing
#    define FORT_CONSSCALMINMAX     consscalminmax
#    define FORT_CONVSCALMINMAX     convscalminmax
#    define FORT_UPDATE_TF          updatetf
#    define FORT_CORRECT_TF         correcttf
#    define FORT_UPDATE_AOFS_TF     updateaofstf
#    define FORT_UPDATE_AOFS_TF_GP  updateaofstfgp
#    define FORT_SUM_TF_GP_VISC     sumtfgpvisc
#    define FORT_SUM_TF_DIVU_VISC   sumtfdivuvisc
#    define FORT_SUM_TF_GP          sumtfgp
#    define FORT_SUM_TF_DIVU        sumtfdivu
#    define FORT_SET_PARAMS         setparams
#  elif defined(BL_FORT_USE_UNDERSCORE)
#    define FORT_TEST_U_RHO         testurho_
#    define FORT_TEST_UMAC_RHO      testumacrho_
#    define FORT_ESTDT              estmdt_
#    define FORT_TRANSVEL           transvel_
#    define FORT_ESTATE             estate_
#    define FORT_ESTATE_FPU         estatefpu_
#    define FORT_ESTATE_BDS         estatebds_
#    define FORT_ADV_FORCING        advforcing_
#    define FORT_SYNC_ADV_FORCING   syncadvforcing_
#    define FORT_CONSSCALMINMAX     consscalminmax_
#    define FORT_CONVSCALMINMAX     convscalminmax_
#    define FORT_UPDATE_TF          updatetf_
#    define FORT_CORRECT_TF         correcttf_
#    define FORT_UPDATE_AOFS_TF     updateaofstf_
#    define FORT_UPDATE_AOFS_TF_GP  updateaofstfgp_
#    define FORT_SUM_TF_GP_VISC     sumtfgpvisc_
#    define FORT_SUM_TF_DIVU_VISC   sumtfdivuvisc_
#    define FORT_SUM_TF_GP          sumtfgp_
#    define FORT_SUM_TF_DIVU        sumtfdivu_
#    define FORT_SET_PARAMS         setparams_
#  endif

#include <ArrayLim.H>

extern "C"
{
   void FORT_TEST_U_RHO(const Real* u,  ARLIM_P(vlo), ARLIM_P(vhi),
			const Real* v,  ARLIM_P(vlo), ARLIM_P(vhi),
#if (BL_SPACEDIM == 3)                          
			const Real* w,  ARLIM_P(vlo), ARLIM_P(vhi),
#endif
			const Real* rh, ARLIM_P(rlo), ARLIM_P(rhi),
			const int* lo, const int* hi, const Real* dt, 
			const Real* dx, Real* cflmax, 
			const Real* u_max, int* verbose);
   
   void FORT_TEST_UMAC_RHO(const Real* um, ARLIM_P(ulo), ARLIM_P(uhi),
			   const Real* vm, ARLIM_P(vlo), ARLIM_P(vhi),
#if (BL_SPACEDIM == 3)                            
			   const Real* wm, ARLIM_P(wlo), ARLIM_P(whi),
#endif                                              
			   const Real* rh, ARLIM_P(rlo), ARLIM_P(rhi),
			   const int* lo, const int* hi, const Real* dt, 
			   const Real* dx, Real* cfl, const Real* u_max);
   
   void FORT_ESTDT(const Real* Udat,  ARLIM_P(vlo), ARLIM_P(vhi),
		   const Real* Tfdat, ARLIM_P(tlo), ARLIM_P(thi),
		   const Real* rdat,  ARLIM_P(rlo), ARLIM_P(rhi),
		   const int* lo, const int* hi, Real* dt, 
		   const Real* dx, Real* cfl, Real* u_max);
   
   void FORT_TRANSVEL( const Real* u_dat, const Real* uad_dat, 
		       const Real* xhi_dat, const Real* slx_dat, 
		       const int* ubc, Real* slxscr, Real* Imx, Real* Ipx, 
                       Real* sedgex, ARLIM_P(sedgexlo), ARLIM_P(sedgexhi),

		       const Real* v_dat, const Real* vad_dat, 
		       const Real* yhi_dat, const Real* sly_dat, 
		       const int* vbc, Real*slyscr, Real* Imy, Real* Ipy,
                       Real* sedgey, ARLIM_P(sedgeylo), ARLIM_P(sedgeyhi),
#if (BL_SPACEDIM == 3)
		       const Real* w_dat, const Real* wad_dat, 
		       const Real* zhi_dat, const Real* slz_dat, 
		       const int* wbc, Real* slzscr, Real* Imz, Real* Ipz,
                       Real* sedgez, ARLIM_P(sedgezlo), ARLIM_P(sedgezhi),
#endif    
		       ARLIM_P(u_lo),ARLIM_P(u_hi),
		       ARLIM_P(w_lo),ARLIM_P(w_hi),
		       ARLIM_P(I_lo),ARLIM_P(I_hi),
		       Real* dsvl, ARLIM_P(dsvl_lo),ARLIM_P(dsvl_hi),
		       Real* sm, Real* sp, ARLIM_P(smp_lo),ARLIM_P(smp_hi),
		       const int* lo, const int* hi, Real* dt, 
		       const Real* dx, int* use_forces_in_trans, 
		       const Real* tforcedat, int* ppm_type);
   
   void FORT_ESTATE(const Real* s_dat, const Real* tfr_dat, 
		    ARLIM_P(s_lo),ARLIM_P(s_hi),
		    const Real* u_dat, const Real* xlo_dat, 
		    const Real* xhi_dat, const Real* slx_dat, 
		    const Real* uad_dat,
		    Real* slxscr, Real* stxlo, Real* stxhi,
		    const Real* uedge_dat, ARLIM_P(ue_lo), ARLIM_P(ue_hi),
                    const Real* stx,       ARLIM_P(stx_lo),ARLIM_P(stx_hi), Real* Imx, Real* Ipx,
                    Real* sedgex, ARLIM_P(sedgexlo), ARLIM_P(sedgexhi),
		    
		    const Real* v_dat, const Real* ylo_dat, 
		    const Real* yhi_dat, const Real* sly_dat, 
		    const Real* vad_dat,
		    Real* slyscr, Real* stylo, Real* styhi,
		    const Real* vedge_dat, ARLIM_P(ve_lo), ARLIM_P(ve_hi),
                    const Real* sty,       ARLIM_P(sty_lo),ARLIM_P(sty_hi), Real* Imy, Real* Ipy,
                    Real* sedgey, ARLIM_P(sedgeylo), ARLIM_P(sedgeyhi),
#if (BL_SPACEDIM == 3)
		    const Real* w_dat, const Real* zlo_dat, 
		    const Real* zhi_dat, const Real* slz_dat, 
		    const Real* wad_dat,
		    Real* slzscr, Real* stzlo, Real* stzhi,
		    const Real* wedge_dat, ARLIM_P(we_lo), ARLIM_P(we_hi),
                    const Real* stz,       ARLIM_P(stz_lo),ARLIM_P(stz_hi), Real* Imz, Real* Ipz,
                    Real* sedgez, ARLIM_P(sedgezlo), ARLIM_P(sedgezhi),

		    const Real* xedge_dat, const Real* yedge_dat, const Real* zedge_dat,
		    const Real* xylo_dat,  const Real* xzlo_dat,  const Real* yxlo_dat,
		    const Real* yzlo_dat,  const Real* zxlo_dat,  const Real* zylo_dat,
		    const Real* xyhi_dat,  const Real* xzhi_dat,  const Real* yxhi_dat,
		    const Real* yzhi_dat,  const Real* zxhi_dat,  const Real* zyhi_dat,

		    bool* corner_couple,
#endif
		    ARLIM_P(ww_lo),ARLIM_P(ww_hi),
		    ARLIM_P(I_lo),ARLIM_P(I_hi),
                    Real* dsvl, ARLIM_P(dsvl_lo),ARLIM_P(dsvl_hi),
                    Real* sm, Real* sp, ARLIM_P(smp_lo),ARLIM_P(smp_hi),
		    const int* bc, const int* lo, const int* hi, 
		    Real* dt, const Real* dx, int* fort_ind, int* velpred, 
		    int* use_forces_in_trans, int* ppm_type);
   
   void FORT_ESTATE_FPU(const Real* s_dat, const Real* tfr_dat, const Real* divu_dat,
		    ARLIM_P(s_lo),ARLIM_P(s_hi),
		    const Real* xlo_dat, 
		    const Real* xhi_dat, const Real* slx_dat, 
		    Real* slxscr, Real* stxlo, Real* stxhi,
		    const Real* uedge_dat, ARLIM_P(ue_lo), ARLIM_P(ue_hi),
                    const Real* stx,       ARLIM_P(stx_lo),ARLIM_P(stx_hi), Real* Imx, Real* Ipx,
                    Real* sedgex, ARLIM_P(sedgexlo), ARLIM_P(sedgexhi),

		    const Real* ylo_dat, 
		    const Real* yhi_dat, const Real* sly_dat, 
		    Real* slyscr, Real* stylo, Real* styhi,
		    const Real* vedge_dat, ARLIM_P(ve_lo), ARLIM_P(ve_hi),
                    const Real* sty,       ARLIM_P(sty_lo),ARLIM_P(sty_hi), Real* Imy, Real* Ipy,
                    Real* sedgey, ARLIM_P(sedgeylo), ARLIM_P(sedgeyhi),

#if (BL_SPACEDIM == 3)
		    const Real* zlo_dat, 
		    const Real* zhi_dat, const Real* slz_dat, 
		    Real* slzscr, Real* stzlo, Real* stzhi,
		    const Real* wedge_dat, ARLIM_P(we_lo), ARLIM_P(we_hi),
                    const Real* stz,       ARLIM_P(stz_lo),ARLIM_P(stz_hi), Real* Imz, Real* Ipz,
                    Real* sedgez, ARLIM_P(sedgezlo), ARLIM_P(sedgezhi),

		    const Real* xedge_dat, const Real* yedge_dat, const Real* zedge_dat,
		    const Real* xylo_dat,  const Real* xzlo_dat,  const Real* yxlo_dat,
		    const Real* yzlo_dat,  const Real* zxlo_dat,  const Real* zylo_dat,
		    const Real* xyhi_dat,  const Real* xzhi_dat,  const Real* yxhi_dat,
		    const Real* yzhi_dat,  const Real* zxhi_dat,  const Real* zyhi_dat,

       	            bool* corner_couple,
#endif
		    ARLIM_P(ww_lo),ARLIM_P(ww_hi),
		    ARLIM_P(I_lo),ARLIM_P(I_hi),
                    Real* dsvl, ARLIM_P(dsvl_lo),ARLIM_P(dsvl_hi),
                    Real* sm, Real* sp, ARLIM_P(smp_lo),ARLIM_P(smp_hi),
		    const int* bc, const int* lo, const int* hi, 
		    Real* dt, const Real* dx, int* fort_ind, 
		    int* use_forces_in_trans, int* iconserv, int* ppm_type);

   void FORT_ESTATE_BDS(const Real* s_dat, const Real* tfr_dat, const Real* divu_dat,
		    ARLIM_P(s_lo),ARLIM_P(s_hi),
		    const Real* xlo_dat, 
		    const Real* xhi_dat, const Real* slx_dat, 
		    Real* slxscr, Real* stxlo, Real* stxhi,
		    const Real* uedge_dat, ARLIM_P(ue_lo), ARLIM_P(ue_hi),
                    const Real* stx,       ARLIM_P(stx_lo),ARLIM_P(stx_hi),
		    const Real* ylo_dat, 
		    const Real* yhi_dat, const Real* sly_dat, 
		    Real* slyscr, Real* stylo, Real* styhi,
		    const Real* vedge_dat, ARLIM_P(ve_lo), ARLIM_P(ve_hi),
                    const Real* sty,       ARLIM_P(sty_lo),ARLIM_P(sty_hi),
#if (BL_SPACEDIM == 3)
		    const Real* zlo_dat, 
		    const Real* zhi_dat, const Real* slz_dat, 
		    Real* slzscr, Real* stzlo, Real* stzhi,
		    const Real* wedge_dat, ARLIM_P(we_lo), ARLIM_P(we_hi),
                    const Real* stz,       ARLIM_P(stz_lo),ARLIM_P(stz_hi),
#endif
		    ARLIM_P(ww_lo),ARLIM_P(ww_hi),
		    const int* bc, const int* lo, const int* hi, 
		    Real* dt, const Real* dx, int* fort_ind, 
		    int* use_forces_in_trans, int* iconserv);
   
   void FORT_ADV_FORCING(const Real* aofs_dat, ARLIM_P(a_lo), ARLIM_P(a_hi),

			 const Real* xflux_dat, ARLIM_P(xflux_lo),ARLIM_P(xflux_hi),
                         const Real* uedge_dat, ARLIM_P(uedge_lo),ARLIM_P(uedge_hi),
			 const Real* areax_dat, ARLIM_P(ax_lo), ARLIM_P(ax_hi),

			 const Real* yflux_dat, ARLIM_P(yflux_lo),ARLIM_P(yflux_hi),
                         const Real* vedge_dat, ARLIM_P(vedge_lo),ARLIM_P(vedge_hi),
			 const Real* areay_dat, ARLIM_P(ay_lo), ARLIM_P(ay_hi),
#if (BL_SPACEDIM == 3)                                                    
			 const Real* zflux_dat, ARLIM_P(zflux_lo),ARLIM_P(zflux_hi),
                         const Real* wedge_dat, ARLIM_P(wedge_lo),ARLIM_P(wedge_hi),
			 const Real* areaz_dat, ARLIM_P(az_lo), ARLIM_P(az_hi),
#endif
			 const Real* vol_dat, ARLIM_P(v_lo),ARLIM_P(v_hi),
			 const int* lo, const int* hi, int* iconserv);
   
   void FORT_SYNC_ADV_FORCING(const Real* sync_dat,ARLIM_P(s_lo),ARLIM_P(s_hi),
			      
			      const Real* xflux_dat, ARLIM_P(xflux_lo),ARLIM_P(xflux_hi),
                              const Real* ucorr_dat, ARLIM_P(ucorr_lo),ARLIM_P(ucorr_hi),
			      const Real* areax_dat, ARLIM_P(ax_lo), ARLIM_P(ax_hi),
			      
			      const Real* yflux_dat, ARLIM_P(yflux_lo),ARLIM_P(yflux_hi),
                              const Real* vcorr_dat, ARLIM_P(vcorr_lo),ARLIM_P(vcorr_hi),
			      const Real* areay_dat, ARLIM_P(ay_lo), ARLIM_P(ay_hi),
#if (BL_SPACEDIM == 3)                                             
			      const Real* zflux_dat, ARLIM_P(zflux_lo),ARLIM_P(zflux_hi),
                              const Real* wcorr_dat, ARLIM_P(wcorr_lo),ARLIM_P(wcorr_hi),
			      const Real* areaz_dat, ARLIM_P(az_lo), ARLIM_P(az_hi),
#endif
			      const Real* vol_dat, ARLIM_P(v_lo),ARLIM_P(v_hi),
			      const int* lo, const int* hi, int* iconserv);
   
   void FORT_CONVSCALMINMAX (const Real* Sold_dat, 
                             ARLIM_P(slo), ARLIM_P(shi),
                             const Real* Snew_dat, 
                             ARLIM_P(snlo), ARLIM_P(snhi),
#if (BL_SPACEDIM == 3)
			     const Real* smin_dat, const Real* smax_dat,
			     ARLIM_P(lo),ARLIM_P(hi),
#endif
			     const int* lo, const int* hi, const int* bc);

   void FORT_CONSSCALMINMAX (const Real* Sold_dat, const Real* Snew_dat, 
			     const Real*  Rho_dat, const Real* Rhon_dat,
                             ARLIM_P(slo), ARLIM_P(shi),
#if (BL_SPACEDIM == 3)
			     const Real* smin_dat, const Real* smax_dat,
			     ARLIM_P(lo),ARLIM_P(hi),
#endif
			     const int* lo, const int* hi, const int* bc);
   
   void  FORT_UPDATE_TF(const Real* SOdat, ARLIM_P(slo), ARLIM_P(shi), 
			const Real* SNdat, ARLIM_P(slo), ARLIM_P(shi),
			const Real* Tfdat, ARLIM_P(tlo), ARLIM_P(thi),
			const int* lo, const int* hi, Real* dt, int* num_comp);
   
   void FORT_CORRECT_TF(const Real* SSdat, const Real* SPdat, ARLIM_P(slo), ARLIM_P(shi),
			const Real* TSdat, const Real* TNdat, ARLIM_P(tlo), ARLIM_P(thi),
			const int* lo, const int* hi, Real* dt, int* num_comp);
   
   void FORT_UPDATE_AOFS_TF(const Real* SOdat, ARLIM_P(slo), ARLIM_P(shi), 
			    const Real* SNdat, ARLIM_P(slo), ARLIM_P(shi),
			    const Real* AOdat, ARLIM_P(alo), ARLIM_P(ahi),
			    const Real* Tfdat, ARLIM_P(tlo), ARLIM_P(thi),
			    const int* lo, const int* hi, 
			    Real* dt, int* num_comp);
   
   void FORT_UPDATE_AOFS_TF_GP(const Real* UOdat, ARLIM_P(ulo), ARLIM_P(uhi),
			       const Real* UNdat, ARLIM_P(ulo), ARLIM_P(uhi),
			       const Real* AOdat, ARLIM_P(alo), ARLIM_P(ahi),
			       const Real* Tfdat, ARLIM_P(tlo), ARLIM_P(thi),
			       const Real* GPdat, ARLIM_P(glo), ARLIM_P(ghi),
			       const Real* RHdat, ARLIM_P(rlo), ARLIM_P(rhi),
			       const int* lo, const int* hi, Real* dt);
   
   void FORT_SUM_TF_GP_VISC(const Real* Tfdat, ARLIM_P(tlo), ARLIM_P(thi),
			    const Real* VIdat, ARLIM_P(vlo), ARLIM_P(vhi),
			    const Real* GPdat, ARLIM_P(glo), ARLIM_P(ghi),
			    const Real* RHdat, ARLIM_P(rlo), ARLIM_P(rhi),
			    const int* tlo, const int* thi);
   
   void FORT_SUM_TF_DIVU_VISC(const Real* Sdat,  ARLIM_P(slo), ARLIM_P(shi),
			      const Real* Tfdat, ARLIM_P(tlo), ARLIM_P(thi),
			      const Real* DUdat, ARLIM_P(dlo), ARLIM_P(dhi),
			      const Real* VIdat, ARLIM_P(vlo), ARLIM_P(vhi),
			      const Real* RHdat, ARLIM_P(rlo), ARLIM_P(rhi),
			      const int* tlo, const int* thi, 
			      int* num_comp, int* iconserv);
   
   void FORT_SUM_TF_GP(const Real* Tfdat, ARLIM_P(tlo), ARLIM_P(thi),
		       const Real* GPdat, ARLIM_P(glo), ARLIM_P(ghi),
		       const Real* RHdat, ARLIM_P(rlo), ARLIM_P(rhi),
		       const int* tlo, const int* thi);
   
   void FORT_SUM_TF_DIVU(const Real* Sdat,  ARLIM_P(slo), ARLIM_P(shi),
			 const Real* Tfdat, ARLIM_P(tlo), ARLIM_P(thi),
			 const Real* DUdat, ARLIM_P(dlo), ARLIM_P(dhi),
			 const Real* RHdat, ARLIM_P(rlo), ARLIM_P(rhi),
			 const int* tlo, const int* thi, 
			 int* num_comp, int* iconserv);
   
   void FORT_SET_PARAMS(const int& slope_order,
			const int& use_unlimited_slopes);
}
#endif

#endif /*_GODUNOV_F_H_*/