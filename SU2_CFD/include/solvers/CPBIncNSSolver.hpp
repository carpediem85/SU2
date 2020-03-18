#pragma once

#include "CPBIncEulerSolver.hpp"

/*!
 * \class CPBIncNSSolver
 * \brief Main class for defining the pressure based incompressible Navier-Stokes flow solver.
 * \ingroup Navier_Stokes_Equations
 */
class CPBIncNSSolver : public CPBIncEulerSolver {
private:
  su2double Viscosity_Inf;  /*!< \brief Viscosity at the infinity. */
  su2double Tke_Inf;        /*!< \brief Turbulent kinetic energy at the infinity. */
  su2double
  *CD_Visc,            /*!< \brief Drag coefficient (viscous contribution) for each boundary. */
  *CL_Visc,            /*!< \brief Lift coefficient (viscous contribution) for each boundary. */
  *CSF_Visc,           /*!< \brief Side force coefficient (viscous contribution) for each boundary. */
  *CMx_Visc,           /*!< \brief Moment x coefficient (viscous contribution) for each boundary. */
  *CMy_Visc,           /*!< \brief Moment y coefficient (viscous contribution) for each boundary. */
  *CMz_Visc,           /*!< \brief Moment z coefficient (viscous contribution) for each boundary. */
  *CoPx_Visc,          /*!< \brief Moment x coefficient (viscous contribution) for each boundary. */
  *CoPy_Visc,          /*!< \brief Moment y coefficient (viscous contribution) for each boundary. */
  *CoPz_Visc,          /*!< \brief Moment z coefficient (viscous contribution) for each boundary. */
  *CFx_Visc,           /*!< \brief Force x coefficient (viscous contribution) for each boundary. */
  *CFy_Visc,           /*!< \brief Force y coefficient (viscous contribution) for each boundary. */
  *CFz_Visc,           /*!< \brief Force z coefficient (viscous contribution) for each boundary. */
  *Surface_CL_Visc,    /*!< \brief Lift coefficient (viscous contribution) for each monitoring surface. */
  *Surface_CD_Visc,    /*!< \brief Drag coefficient (viscous contribution) for each monitoring surface. */
  *Surface_CSF_Visc,   /*!< \brief Side-force coefficient (viscous contribution) for each monitoring surface. */
  *Surface_CEff_Visc,  /*!< \brief Side-force coefficient (viscous contribution) for each monitoring surface. */
  *Surface_CFx_Visc,   /*!< \brief Force x coefficient (viscous contribution) for each monitoring surface. */
  *Surface_CFy_Visc,   /*!< \brief Force y coefficient (viscous contribution) for each monitoring surface. */
  *Surface_CFz_Visc,   /*!< \brief Force z coefficient (viscous contribution) for each monitoring surface. */
  *Surface_CMx_Visc,   /*!< \brief Moment x coefficient (viscous contribution) for each monitoring surface. */
  *Surface_CMy_Visc,   /*!< \brief Moment y coefficient (viscous contribution) for each monitoring surface. */
  *Surface_CMz_Visc,   /*!< \brief Moment z coefficient (viscous contribution) for each monitoring surface. */
  *CEff_Visc,          /*!< \brief Efficiency (Cl/Cd) (Viscous contribution) for each boundary. */
  *CMerit_Visc,        /*!< \brief Rotor Figure of Merit (Viscous contribution) for each boundary. */
  *CT_Visc,            /*!< \brief Thrust coefficient (viscous contribution) for each boundary. */
  *CQ_Visc,            /*!< \brief Torque coefficient (viscous contribution) for each boundary. */
  *HF_Visc,            /*!< \brief Heat load (viscous contribution) for each boundary. */
  *MaxHF_Visc,         /*!< \brief Maximum heat flux (viscous contribution) for each boundary. */
  ***HeatConjugateVar, /*!< \brief Conjugate heat transfer variables for each boundary and vertex. */
  ***CSkinFriction;    /*!< \brief Skin friction coefficient for each boundary and vertex. */
  su2double
  *ForceViscous,       /*!< \brief Viscous force for each boundary. */
  *MomentViscous;      /*!< \brief Inviscid moment for each boundary. */
  su2double
  AllBound_CD_Visc,     /*!< \brief Drag coefficient (viscous contribution) for all the boundaries. */
  AllBound_CL_Visc,     /*!< \brief Lift coefficient (viscous contribution) for all the boundaries. */
  AllBound_CSF_Visc,    /*!< \brief Sideforce coefficient (viscous contribution) for all the boundaries. */
  AllBound_CMx_Visc,    /*!< \brief Moment x coefficient (inviscid contribution) for all the boundaries. */
  AllBound_CMy_Visc,    /*!< \brief Moment y coefficient (inviscid contribution) for all the boundaries. */
  AllBound_CMz_Visc,    /*!< \brief Moment z coefficient (inviscid contribution) for all the boundaries. */
  AllBound_CoPx_Visc,   /*!< \brief Moment x coefficient (inviscid contribution) for all the boundaries. */
  AllBound_CoPy_Visc,   /*!< \brief Moment y coefficient (inviscid contribution) for all the boundaries. */
  AllBound_CoPz_Visc,   /*!< \brief Moment z coefficient (inviscid contribution) for all the boundaries. */
  AllBound_CEff_Visc,   /*!< \brief Efficient coefficient (Viscous contribution) for all the boundaries. */
  AllBound_CFx_Visc,    /*!< \brief Force x coefficient (inviscid contribution) for all the boundaries. */
  AllBound_CFy_Visc,    /*!< \brief Force y coefficient (inviscid contribution) for all the boundaries. */
  AllBound_CFz_Visc,    /*!< \brief Force z coefficient (inviscid contribution) for all the boundaries. */
  AllBound_CMerit_Visc, /*!< \brief Rotor Figure of Merit coefficient (Viscous contribution) for all the boundaries. */
  AllBound_CT_Visc,     /*!< \brief Thrust coefficient (viscous contribution) for all the boundaries. */
  AllBound_CQ_Visc,     /*!< \brief Torque coefficient (viscous contribution) for all the boundaries. */
  AllBound_HF_Visc,     /*!< \brief Heat load (viscous contribution) for all the boundaries. */
  AllBound_MaxHF_Visc;  /*!< \brief Maximum heat flux (viscous contribution) for all boundaries. */
  su2double
  StrainMag_Max,
  Omega_Max;            /*!< \brief Maximum Strain Rate magnitude and Omega. */
  
public:
  
  /*!
   * \brief Constructor of the class.
   */
  CPBIncNSSolver(void);
    
  /*!
   * \overload
   * \param[in] geometry - Geometrical definition of the problem.
   * \param[in] config - Definition of the particular problem.
   */
  CPBIncNSSolver(CGeometry *geometry, CConfig *config, unsigned short iMesh);
    
  /*!
   * \brief Destructor of the class.
   */
  ~CPBIncNSSolver(void);
    
  /*!
   * \brief Provide the non dimensional lift coefficient.
   * \param[in] val_marker - Surface marker where the coefficient is computed.
   * \return Value of the lift coefficient on the surface <i>val_marker</i>.
   */
  su2double GetSurface_CL_Visc(unsigned short val_marker);
  
  /*!
   * \brief Provide the non dimensional drag coefficient.
   * \param[in] val_marker - Surface marker where the coefficient is computed.
   * \return Value of the drag coefficient on the surface <i>val_marker</i>.
   */
  su2double GetSurface_CD_Visc(unsigned short val_marker);
    
  /*!
   * \brief Provide the non dimensional side-force coefficient.
   * \param[in] val_marker - Surface marker where the coefficient is computed.
   * \return Value of the side-force coefficient on the surface <i>val_marker</i>.
   */
  su2double GetSurface_CSF_Visc(unsigned short val_marker);
    
  /*!
   * \brief Provide the non dimensional side-force coefficient.
   * \param[in] val_marker - Surface marker where the coefficient is computed.
   * \return Value of the side-force coefficient on the surface <i>val_marker</i>.
   */
  su2double GetSurface_CEff_Visc(unsigned short val_marker);
    
    /*!
   * \brief Provide the non dimensional x force coefficient.
   * \param[in] val_marker - Surface marker where the coefficient is computed.
   * \return Value of the x force coefficient on the surface <i>val_marker</i>.
   */
  su2double GetSurface_CFx_Visc(unsigned short val_marker);
  
  /*!
   * \brief Provide the non dimensional y force coefficient.
   * \param[in] val_marker - Surface marker where the coefficient is computed.
   * \return Value of the y force coefficient on the surface <i>val_marker</i>.
   */
  su2double GetSurface_CFy_Visc(unsigned short val_marker);
    
  /*!
   * \brief Provide the non dimensional z force coefficient.
   * \param[in] val_marker - Surface marker where the coefficient is computed.
   * \return Value of the z force coefficient on the surface <i>val_marker</i>.
   */
  su2double GetSurface_CFz_Visc(unsigned short val_marker);
    
  /*!
   * \brief Provide the non dimensional x moment coefficient.
   * \param[in] val_marker - Surface marker where the coefficient is computed.
   * \return Value of the x moment coefficient on the surface <i>val_marker</i>.
   */
  su2double GetSurface_CMx_Visc(unsigned short val_marker);
  
  /*!
   * \brief Provide the non dimensional y moment coefficient.
   * \param[in] val_marker - Surface marker where the coefficient is computed.
   * \return Value of the y moment coefficient on the surface <i>val_marker</i>.
   */
  su2double GetSurface_CMy_Visc(unsigned short val_marker);
  
  /*!
   * \brief Provide the non dimensional z moment coefficient.
   * \param[in] val_marker - Surface marker where the coefficient is computed.
   * \return Value of the z moment coefficient on the surface <i>val_marker</i>.
   */
  su2double GetSurface_CMz_Visc(unsigned short val_marker);
  
  /*!
   * \brief Get the inviscid contribution to the lift coefficient.
   * \return Value of the lift coefficient (inviscid contribution).
   */
  su2double GetAllBound_CL_Visc(void);
  
  /*!
   * \brief Get the inviscid contribution to the drag coefficient.
   * \return Value of the drag coefficient (inviscid contribution).
   */
  su2double GetAllBound_CD_Visc(void);
  
  /*!
   * \brief Get the inviscid contribution to the sideforce coefficient.
   * \return Value of the sideforce coefficient (inviscid contribution).
   */
  su2double GetAllBound_CSF_Visc(void);
  
  /*!
   * \brief Get the inviscid contribution to the efficiency coefficient.
   * \return Value of the efficiency coefficient (inviscid contribution).
   */
  su2double GetAllBound_CEff_Visc(void);
  
  /*!
   * \brief Get the inviscid contribution to the efficiency coefficient.
   * \return Value of the efficiency coefficient (inviscid contribution).
   */
  su2double GetAllBound_CMx_Visc(void);
  
  /*!
   * \brief Get the inviscid contribution to the efficiency coefficient.
   * \return Value of the efficiency coefficient (inviscid contribution).
   */
  su2double GetAllBound_CMy_Visc(void);

  /*!
   * \brief Get the inviscid contribution to the efficiency coefficient.
   * \return Value of the efficiency coefficient (inviscid contribution).
   */
  su2double GetAllBound_CMz_Visc(void);

  /*!
   * \brief Get the inviscid contribution to the efficiency coefficient.
   * \return Value of the efficiency coefficient (inviscid contribution).
   */
  su2double GetAllBound_CoPx_Visc(void);

  /*!
   * \brief Get the inviscid contribution to the efficiency coefficient.
   * \return Value of the efficiency coefficient (inviscid contribution).
   */
  su2double GetAllBound_CoPy_Visc(void);

  /*!
   * \brief Get the inviscid contribution to the efficiency coefficient.
   * \return Value of the efficiency coefficient (inviscid contribution).
   */
  su2double GetAllBound_CoPz_Visc(void);

  /*!
   * \brief Get the inviscid contribution to the efficiency coefficient.
   * \return Value of the efficiency coefficient (inviscid contribution).
   */
  su2double GetAllBound_CFx_Visc(void);
  
  /*!
   * \brief Get the inviscid contribution to the efficiency coefficient.
   * \return Value of the efficiency coefficient (inviscid contribution).
   */
  su2double GetAllBound_CFy_Visc(void);
  
  /*!
   * \brief Get the inviscid contribution to the efficiency coefficient.
   * \return Value of the efficiency coefficient (inviscid contribution).
   */
  su2double GetAllBound_CFz_Visc(void);
  
  /*!
   * \brief Compute the viscosity at the infinity.
   * \return Value of the viscosity at the infinity.
   */
  su2double GetViscosity_Inf(void);
  
  /*!
   * \brief Get the turbulent kinetic energy at the infinity.
   * \return Value of the turbulent kinetic energy at the infinity.
   */
  su2double GetTke_Inf(void);
  
  /*!
   * \brief Compute the time step for solving the Navier-Stokes equations with turbulence model.
   * \param[in] geometry - Geometrical definition of the problem.
   * \param[in] solver_container - Container vector with all the solutions.
   * \param[in] config - Definition of the particular problem.
   * \param[in] iMesh - Index of the mesh in multigrid computations.
   * \param[in] Iteration - Index of the current iteration.
   */
  void SetTime_Step(CGeometry *geometry, CSolver **solver_container, CConfig *config,
                    unsigned short iMesh, unsigned long Iteration);
  
  /*!
   * \brief Restart residual and compute gradients.
   * \param[in] geometry - Geometrical definition of the problem.
   * \param[in] solver_container - Container vector with all the solutions.
   * \param[in] config - Definition of the particular problem.
   * \param[in] iRKStep - Current step of the Runge-Kutta iteration.
   * \param[in] RunTime_EqSystem - System of equations which is going to be solved.
   * \param[in] Output - boolean to determine whether to print output.
   */
  void Preprocessing(CGeometry *geometry, CSolver **solver_container, CConfig *config, unsigned short iMesh, unsigned short iRKStep, unsigned short RunTime_EqSystem, bool Output);
  
  /*!
   * \brief A virtual member.
   * \param[in] geometry - Geometrical definition of the problem.
   * \param[in] solver_container - Container vector with all the solutions.
   * \param[in] config - Definition of the particular problem.
   * \param[in] iMesh - Index of the mesh in multigrid computations.
   */
  void Postprocessing(CGeometry *geometry, CSolver **solver_container, CConfig *config, unsigned short iMesh);
  
  /*!
   * \brief Compute the velocity^2, SoundSpeed, Pressure, Enthalpy, Viscosity.
   * \param[in] solver_container - Container vector with all the solutions.
   * \param[in] config - Definition of the particular problem.
   * \param[in] Output - boolean to determine whether to print output.
   * \return - The number of non-physical points.
   */
  unsigned long SetPrimitive_Variables(CSolver **solver_container, CConfig *config, bool Output);
  
  /*!
   * \brief Impose a no-slip condition.
   * \param[in] geometry - Geometrical definition of the problem.
   * \param[in] solver_container - Container vector with all the solutions.
   * \param[in] conv_numerics - Description of the numerical method.
   * \param[in] visc_numerics - Description of the numerical method.
   * \param[in] config - Definition of the particular problem.
   * \param[in] val_marker - Surface marker where the boundary condition is applied.
   */
  void BC_HeatFlux_Wall(CGeometry *geometry, CSolver **solver_container, CNumerics *conv_numerics, CNumerics *visc_numerics, CConfig *config, unsigned short val_marker);

  /*!
   * \brief Impose an isothermal temperature condition at the wall.
   * \param[in] geometry - Geometrical definition of the problem.
   * \param[in] solver_container - Container vector with all the solutions.
   * \param[in] conv_numerics - Description of the numerical method.
   * \param[in] visc_numerics - Description of the numerical method.
   * \param[in] config - Definition of the particular problem.
   * \param[in] val_marker - Surface marker where the boundary condition is applied.
   */
  void BC_Isothermal_Wall(CGeometry *geometry, CSolver **solver_container, CNumerics *conv_numerics, CNumerics *visc_numerics, CConfig *config, unsigned short val_marker);

  /*!
   * \brief Compute the viscous forces and all the addimensional coefficients.
   * \param[in] geometry - Geometrical definition of the problem.
   * \param[in] config - Definition of the particular problem.
   */
  void Friction_Forces(CGeometry *geometry, CConfig *config);
  /*!
   * \brief Get the non dimensional lift coefficient (viscous contribution).
   * \param[in] val_marker - Surface marker where the coefficient is computed.
   * \return Value of the lift coefficient (viscous contribution) on the surface <i>val_marker</i>.
   */
  su2double GetCL_Visc(unsigned short val_marker);

  /*!
   * \brief Get the non dimensional sideforce coefficient (viscous contribution).
   * \param[in] val_marker - Surface marker where the coefficient is computed.
   * \return Value of the sideforce coefficient (viscous contribution) on the surface <i>val_marker</i>.
   */
  su2double GetCSF_Visc(unsigned short val_marker);
  
  /*!
   * \brief Get the non dimensional drag coefficient (viscous contribution).
   * \param[in] val_marker - Surface marker where the coefficient is computed.
   * \return Value of the drag coefficient (viscous contribution) on the surface <i>val_marker</i>.
   */
  su2double GetCD_Visc(unsigned short val_marker);
  
  /*!
   * \brief Compute the viscous residuals.
   * \param[in] geometry - Geometrical definition of the problem.
   * \param[in] solver_container - Container vector with all the solutions.
   * \param[in] numerics - Description of the numerical method.
   * \param[in] config - Definition of the particular problem.
   * \param[in] iMesh - Index of the mesh in multigrid computations.
   * \param[in] iRKStep - Current step of the Runge-Kutta iteration.
   */
  void Viscous_Residual(CGeometry *geometry, CSolver **solver_container, CNumerics **numerics_container,
                        CConfig *config, unsigned short iMesh, unsigned short iRKStep);
  
  /*!
   * \brief Get the skin friction coefficient.
   * \param[in] val_marker - Surface marker where the coefficient is computed.
   * \param[in] val_vertex - Vertex of the marker <i>val_marker</i> where the coefficient is evaluated.
   * \return Value of the skin friction coefficient.
   */
  su2double GetCSkinFriction(unsigned short val_marker, unsigned long val_vertex, unsigned short val_dim);
   
  /*!
   * \brief Get the y plus.
   * \param[in] val_marker - Surface marker where the coefficient is computed.
   * \param[in] val_vertex - Vertex of the marker <i>val_marker</i> where the coefficient is evaluated.
   * \return Value of the y plus.
   */
  su2double GetYPlus(unsigned short val_marker, unsigned long val_vertex);
  
  /*!
   * \brief Get the max Omega.
   * \return Value of the max Omega.
   */
  su2double GetOmega_Max(void);
  
  /*!
   * \brief Get the max Strain rate magnitude.
   * \return Value of the max Strain rate magnitude.
   */
  su2double GetStrainMag_Max(void);
  
  /*!
   * \brief A virtual member.
   * \return Value of the StrainMag_Max
   */
  void SetStrainMag_Max(su2double val_strainmag_max);
  
  /*!
   * \brief A virtual member.
   * \return Value of the Omega_Max
   */
  void SetOmega_Max(su2double val_omega_max);

};