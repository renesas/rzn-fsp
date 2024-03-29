/***********************************************************************************************************************
 * Copyright [2020-2023] Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
 *
 * This software and documentation are supplied by Renesas Electronics Corporation and/or its affiliates and may only
 * be used with products of Renesas Electronics Corp. and its affiliates ("Renesas").  No other uses are authorized.
 * Renesas products are sold pursuant to Renesas terms and conditions of sale.  Purchasers are solely responsible for
 * the selection and use of Renesas products and Renesas assumes no liability.  No license, express or implied, to any
 * intellectual property right is granted by Renesas.  This software is protected under all applicable laws, including
 * copyright laws. Renesas reserves the right to change or discontinue this software and/or this documentation.
 * THE SOFTWARE AND DOCUMENTATION IS DELIVERED TO YOU "AS IS," AND RENESAS MAKES NO REPRESENTATIONS OR WARRANTIES, AND
 * TO THE FULLEST EXTENT PERMISSIBLE UNDER APPLICABLE LAW, DISCLAIMS ALL WARRANTIES, WHETHER EXPLICITLY OR IMPLICITLY,
 * INCLUDING WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT, WITH RESPECT TO THE
 * SOFTWARE OR DOCUMENTATION.  RENESAS SHALL HAVE NO LIABILITY ARISING OUT OF ANY SECURITY VULNERABILITY OR BREACH.
 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT WILL RENESAS BE LIABLE TO YOU IN CONNECTION WITH THE SOFTWARE OR
 * DOCUMENTATION (OR ANY PERSON OR ENTITY CLAIMING RIGHTS DERIVED FROM YOU) FOR ANY LOSS, DAMAGES, OR CLAIMS WHATSOEVER,
 * INCLUDING, WITHOUT LIMITATION, ANY DIRECT, CONSEQUENTIAL, SPECIAL, INDIRECT, PUNITIVE, OR INCIDENTAL DAMAGES; ANY
 * LOST PROFITS, OTHER ECONOMIC DAMAGE, PROPERTY DAMAGE, OR PERSONAL INJURY; AND EVEN IF RENESAS HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH LOSS, DAMAGES, CLAIMS OR COSTS.
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @ingroup RENESAS_INTERFACES
 * @defgroup ETHSW_API Ethernet Switch Interface
 * @brief Interface for Ethernet Switch functions.
 *
 * @section ETHSW_API_Summary Summary
 * The ETHSW module (r_ethsw) provides an API for Ethernet Switch that use the ETHSW peripheral.
 *
 * The ETHSW interface supports the following features:
 * - Link change check support
 *
 * Implemented by:
 * - @ref ETHSW
 *
 * @{
 **********************************************************************************************************************/

#ifndef R_ETHSW_API_H
#define R_ETHSW_API_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* Register definitions, common services and error codes. */
#include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define ETHSW_API_VERSION_MAJOR    (1U) // DEPRECATED
#define ETHSW_API_VERSION_MINOR    (3U) // DEPRECATED

#define ETHSW_MAC_ADDR_LEN         (6U)

/** Ethernet port macros */
#define ETHSW_PORT_HOST            ((ethsw_port_cast) (1U << 30))
#define ETHSW_PORT_MASK            ((ethsw_port_cast) ((uint64_t) 1 << 31))

// ELWSC #define ETHSW_PORT_HOST_CNT    1
#define ETHSW_PORT(x)        ((ethsw_port_cast) (x) & ~ETHSW_PORT_MASK)
#define ETHSW_PORT_BIT(x)    ((ethsw_port_cast) (1 << (x)) | ETHSW_PORT_MASK)
#define ETHSW_PORT_BITS            (~(ETHSW_PORT_HOST | ETHSW_PORT_MASK))

#define ETHSW_STATE_DEFAULT        0   ///< default state
#define ETHSW_STATE_UNKNOWN        1   ///< unknown state
#define ETHSW_STATE_DOWN           2   ///< state down
#define ETHSW_STATE_UP             3   ///< state up

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/**  speed and duplex of the port */
typedef enum e_ethsw_link_speed
{
    ETHSW_LINK_SPEED_NO_LINK = 0,      ///< Link is not established
    ETHSW_LINK_SPEED_10H     = 1,      ///< Link status is 10Mbit/s and half duplex
    ETHSW_LINK_SPEED_10F     = 2,      ///< Link status is 10Mbit/s and full duplex
    ETHSW_LINK_SPEED_100H    = 3,      ///< Link status is 100Mbit/s and half duplex
    ETHSW_LINK_SPEED_100F    = 4,      ///< Link status is 100Mbit/s and full duplex
    ETHSW_LINK_SPEED_1000H   = 5,      ///< Link status is 1000Mbit/s and half duplex
    ETHSW_LINK_SPEED_1000F   = 6       ///< Link status is 1000Mbit/s and full duplex
} ethsw_link_speed_t;

/** Event code of callback function */
typedef enum e_ethsw_event
{
    ETHSW_EVENT_LINK_CHG               ///< Link status change detection event
} ethsw_event_t;

/** Enable/Disable Management Port Specific Frame Tagging */
typedef enum e_ethsw_specifig_tag
{
    ETHSW_SPECIFIC_TAG_DISABLE = 0,    ///< Disable
    ETHSW_SPECIFIC_TAG_ENABLE  = 1     ///< Enable
} ethsw_specifig_tag_t;

/** Enable/Disable PHYLINK Change Interrupt */
typedef enum e_ethsw_phylink
{
    ETHSW_PHYLINK_DISABLE = 0,         ///< Disable
    ETHSW_PHYLINK_ENABLE  = 1          ///< Enable
} ethsw_phylink_t;

/** Callback function parameter data */
typedef struct st_ethsw_callback_args
{
    uint32_t      channel;             ///< Device channel number
    ethsw_event_t event;               ///< Event code

    uint32_t status_link;              ///< Link status bit0:port0. bit1:port1. bit2:port2, bit3:port3

    void const * p_context;            ///< Placeholder for user data.  Set in @ref ethsw_api_t::open function in @ref ethsw_cfg_t.
} ethsw_callback_args_t;

/** Control block.  Allocate an instance specific control block to pass into the API calls.
 * @par Implemented as
 * - ethsw_instance_ctrl_t
 */
typedef void ethsw_ctrl_t;

/** Configuration parameters. */
typedef struct st_ethsw_cfg
{
    uint8_t channel;                                     ///< Channel

    ethsw_specifig_tag_t specific_tag;                   ///< Management port specific frmame tag
    uint32_t             specific_tag_id;                ///< Management port specific frmame tag ID

    ethsw_phylink_t phylink;                             ///< Enable or disable link status change by PHYLINK
    ///< Call callback function when enable

    IRQn_Type irq;                                       ///< MCU interrupt number
    uint8_t   ipl;                                       ///< MCU interrupt priority

    void (* p_callback)(ethsw_callback_args_t * p_args); ///< Callback provided when an ISR occurs.

    /** Placeholder for user data.  Passed to the user callback in ethsw_callback_args_t. */
    void const * p_context;
    void const * p_extend;                               ///< Placeholder for user extension.
} ethsw_cfg_t;

typedef uint32_t ethsw_port_mask_t;
typedef uint32_t ethsw_port_cast;
typedef uint8_t  ethsw_mac_addr_t[ETHSW_MAC_ADDR_LEN];

/** MAC table entry */
typedef struct st_ethsw_mactab_entry
{
    ethsw_mac_addr_t * mac_addr;       ///< MAC address pointer
    uint16_t           vlan_id;        ///< VLAN ID
    uint32_t           port_mask;      ///< port mask
    uint32_t           priority;       ///< switching priority
} ethsw_mactab_entry_t;

/** MAC table config */
typedef struct st_ethsw_mactab_conf
{
    bool learn;                        ///< Enable/disable MAC learning
    bool aging;                        ///< Enable/disable address aging
    bool migration;                    ///< Enable/disable the migration of devices from one port to another
    bool pervlan;                      ///< Enable/disable per VLAN MAC learning
    bool discunknown;                  ///< Enable/disable discarding of unknown destination frames
} ethsw_mactab_conf_t;

/** MAC table clear/flush modes */
typedef enum e_ethsw_mactab_clr_modes
{
    ETHSW_MACTAB_CLR_STATIC,           ///< Static MAC table entries
    ETHSW_MACTAB_CLR_DYNAMIC,          ///< Learned MAC table entries
    ETHSW_MACTAB_CLR_ALL               ///< Static and learn entries
} ethsw_mactab_clr_modes_t;

/** flood domain configuration for unknown frames */
typedef struct st_ethsw_flood_unk_conf
{
    ethsw_port_mask_t port_mask_bcast; ///< flood domain port mask for broadcasts with unkown destination
    ethsw_port_mask_t port_mask_mcast; ///< flood domain port mask for multicasts with unkown destination
    ethsw_port_mask_t port_mask_ucast; ///< flood domain port mask for unicasts with unkown destination
} ethsw_flood_unk_conf_t;

/** DLR events for the DLR State Machine */
typedef enum e_ethsw_dlr_event
{
    ETHSW_DLR_EVENT_LINKLOST,          ///< Link was lost
    ETHSW_DLR_EVENT_OWNFRAME,          ///< the device received its own frame
    ETHSW_DLR_EVENT_LINKRESTORED,      ///< Link is restored
    ETHSW_DLR_EVENT_BEACONFRAME,       ///< Beacon Frame received
    ETHSW_DLR_EVENT_BEACONTIMEOUT,     ///< Beacon Timer timed out
    ETHSW_DLR_EVENT_NEWSUPERVISOR,     ///< a new Ring Supervisor was detected
    ETHSW_DLR_EVENT_NEWSTATE           ///< Beacon Hardware detected new state
} ethsw_dlr_event_t;

/** DLR initilize */
typedef struct st_ethsw_dlr_init
{
    ethsw_mac_addr_t * p_host_addr;    ///< host MAC address pointer
    void (* p_dlr_callback)(           ///< callback function pointer
        ethsw_dlr_event_t event,
        uint32_t          port);
} ethsw_dlr_init_t;

/** Functions implemented at the HAL layer will follow this API. */
typedef struct st_ethsw_api
{
    /** Open driver.
     * @par Implemented as
     * - @ref R_ETHSW_Open()
     *
     * @param[in]  p_api_ctrl       Pointer to control structure.
     * @param[in]  p_cfg            Pointer to pin configuration structure.
     */
    fsp_err_t (* open)(ethsw_ctrl_t * const p_api_ctrl, ethsw_cfg_t const * const p_cfg);

    /** Close driver.
     * @par Implemented as
     * - @ref R_ETHSW_Close()
     *
     * @param[in]  p_api_ctrl       Pointer to control structure.
     */
    fsp_err_t (* close)(ethsw_ctrl_t * const p_api_ctrl);

    /** Configs speed and duplex of the port.
     * @par Implemented as
     * - @ref R_ETHSW_SpeedCfg()
     *
     * @param[in]  p_api_ctrl       Pointer to control structure.
     * @param[in]  port             Port number.
     * @param[in]  speed            Speed and Duplex,
     */
    fsp_err_t (* speedCfg)(ethsw_ctrl_t * const p_api_ctrl, uint8_t const port, ethsw_link_speed_t const speed);

    /** DEPRECATED Return the version of the driver.
     * @par Implemented as
     * - @ref R_ETHSW_VersionGet()
     *
     * @param[out] p_data           Memory address to return version information to.
     */
    fsp_err_t (* versionGet)(fsp_version_t * const p_data);

    /** Sets the static MAC address entry for the given MAC address.
     * @par Implemented as
     * - @ref R_ETHSW_MacTableSet()
     *
     * @param[in]  p_api_ctrl       Pointer to control structure.
     * @param[in]  p_mac_tab        Pointer to MAC table entry.
     */
    fsp_err_t (* macTableSet)(ethsw_ctrl_t * const p_api_ctrl, ethsw_mactab_entry_t * p_mac_tab);

    /** Retrieves the port mask for the given MAC address from the static MAC table.
     * @par Implemented as
     * - @ref R_ETHSW_MacTableGet()
     *
     * @param[in]       p_api_ctrl       Pointer to control structure.
     * @param[in,out]   p_mac_tab        Pointer to MAC table entry.
     */
    fsp_err_t (* macTableGet)(ethsw_ctrl_t * const p_api_ctrl, ethsw_mactab_entry_t * p_mac_tab);

    /** Configures the MAC learning and aging parameters of MAC table.
     * @par Implemented as
     * - @ref R_ETHSW_MacTableConfSet()
     *
     * @param[in]  p_api_ctrl       Pointer to control structure.
     * @param[in]  p_mac_tab_cnf    Pointer to MAC table config.
     */
    fsp_err_t (* macTableConfSet)(ethsw_ctrl_t * const p_api_ctrl, ethsw_mactab_conf_t * p_mac_tab_cnf);

    /** Clears specific types of entries from the MAC table or clears the whole table.
     * @par Implemented as
     * - @ref R_ETHSW_MacTableClear()
     *
     * @param[in]  p_api_ctrl       Pointer to control structure.
     * @param[in]  p_mac_tab_clr    Pointer to MAC table clear mode.
     */
    fsp_err_t (* macTableClear)(ethsw_ctrl_t * const p_api_ctrl, ethsw_mactab_clr_modes_t * p_mac_tab_clr);

    /** Sets learning state for the given port.
     * @par Implemented as
     * - @ref R_ETHSW_LearningSet()
     *
     * @param[in]  p_api_ctrl       Pointer to control structure.
     * @param[in]  port             Port number.
     * @param[in]  p_flag_learn     Pointer to learning flag.
     */
    fsp_err_t (* learningSet)(ethsw_ctrl_t * const p_api_ctrl, uint32_t port, bool enable);

    /** Enables the forwarding of incoming frames on a port for RSTP.
     * @par Implemented as
     * - @ref R_ETHSW_PortForwardAdd()
     *
     * @param[in]  p_api_ctrl       Pointer to control structure.
     * @param[in]  port             Port number.
     */
    fsp_err_t (* portForwardAdd)(ethsw_ctrl_t * const p_api_ctrl, uint32_t port);

    /** Disables the forwarding of incoming frames on a port for RSTP.
     * @par Implemented as
     * - @ref R_ETHSW_PortForwardDel()
     *
     * @param[in]  p_api_ctrl       Pointer to control structure.
     * @param[in]  port             Port number.
     */
    fsp_err_t (* portForwardDel)(ethsw_ctrl_t * const p_api_ctrl, uint32_t port);

    /** Sets the flood domain port masks for frames with unknown destinations.
     * @par Implemented as
     * - @ref  R_ETHSW_FloodUnknownSet()
     *
     * @param[in]  p_api_ctrl       Pointer to control structure.
     * @param[in]  p_flood_unk_conf Pointer to configuration of flood domain for frames with unknown destination.
     */
    fsp_err_t (* floodUnknownSet)(ethsw_ctrl_t * const p_api_ctrl, ethsw_flood_unk_conf_t * p_flood_unk_conf);

    /** Gets link state for given port.
     * @par Implemented as
     * - @ref  R_ETHSW_LinkStateGet()
     *
     * @param[in]  p_api_ctrl       Pointer to control structure.
     * @param[in]  port             Port number.
     * @param[out] p_state_link     Pointer to Link state (up/down).
     */
    fsp_err_t (* linkStateGet)(ethsw_ctrl_t * const p_api_ctrl, uint32_t port, uint32_t * p_state_link);

    /** Sets maximum frame size of given port.
     * @par Implemented as
     * - @ref  R_ETHSW_FrameSizeMaxSet()
     *
     * @param[in]       p_api_ctrl              Pointer to control structure.
     * @param[in]       port                    Port number.
     * @param[in]       frame_size_max          Maximum frame size.
     */
    fsp_err_t (* frameSizeMaxSet)(ethsw_ctrl_t * const p_api_ctrl, uint32_t port, uint32_t frame_size_max);

    /** Initialize DLR module.
     * @par Implemented as
     * - @ref  R_ETHSW_DlrInitSet()
     *
     * @param[in]       p_api_ctrl              Pointer to control structure.
     * @param[in]       p_dlr_init              Pointer to DLR initilize info.
     */
    fsp_err_t (* dlrInitSet)(ethsw_ctrl_t * const p_api_ctrl, ethsw_dlr_init_t * p_dlr_init);

    /** Uninitialize DLR module.
     * @par Implemented as
     * - @ref  R_ETHSW_DlrUninitSet()
     *
     * @param[in]       p_api_ctrl              Pointer to control structure.
     */
    fsp_err_t (* dlrUninitSet)(ethsw_ctrl_t * const p_api_ctrl);

    /** Enable DLR module.
     * @par Implemented as
     * - @ref  R_ETHSW_DlrEnableSet()
     *
     * @param[in]       p_api_ctrl              Pointer to control structure.
     */
    fsp_err_t (* dlrEnableSet)(ethsw_ctrl_t * const p_api_ctrl);

    /** Disable DLR module.
     * @par Implemented as
     * - @ref  R_ETHSW_DlrDisableSet()
     *
     * @param[in]       p_api_ctrl              Pointer to control structure.
     */
    fsp_err_t (* dlrDisableSet)(ethsw_ctrl_t * const p_api_ctrl);

    /** Gets DLR last beacon status.
     * @par Implemented as
     * - @ref  R_ETHSW_DlrBeaconStateGet()
     *
     * @param[in]       p_api_ctrl              Pointer to control structure.
     * @param[in]       port                    Port number.
     * @param[out]      p_state_dlr             Pointer to DLR last beacon status.
     */
    fsp_err_t (* dlrBeaconStateGet)(ethsw_ctrl_t * const p_api_ctrl, uint32_t port, uint32_t * p_state_dlr);

    /** Gets DLR node status.
     * @par Implemented as
     * - @ref  R_ETHSW_DlrNodeStateGet()
     *
     * @param[in]       p_api_ctrl              Pointer to control structure.
     * @param[out]      p_state_dlr             Pointer to DLR node status.
     */
    fsp_err_t (* dlrNodeStateGet)(ethsw_ctrl_t * const p_api_ctrl, uint32_t * p_state_dlr);

    /** Gets IP address of DLR supervisor.
     * @par Implemented as
     * - @ref  R_ETHSW_DlrSvIpGet()
     *
     * @param[in]       p_api_ctrl              Pointer to control structure.
     * @param[out]      p_state_dlr             Pointer to IP address of DLR supervisor.
     */
    fsp_err_t (* dlrSvIpGet)(ethsw_ctrl_t * const p_api_ctrl, uint32_t * p_state_dlr);

    /** Gets preference of DLR supervisor.
     * @par Implemented as
     * - @ref  R_ETHSW_DlrSvPrecGet()
     *
     * @param[in]       p_api_ctrl              Pointer to control structure.
     * @param[out]      p_state_dlr             Pointer to preference of DLR supervisor.
     */
    fsp_err_t (* dlrSvPrecGet)(ethsw_ctrl_t * const p_api_ctrl, uint32_t * p_state_dlr);

    /** Gets VLAN ID of DLR beacon frame.
     * @par Implemented as
     * - @ref  R_ETHSW_DlrVlanGet()
     *
     * @param[in]       p_api_ctrl              Pointer to control structure.
     * @param[out]      p_state_dlr             Pointer to VLAN ID of DLR beacon frame.
     */
    fsp_err_t (* dlrVlanGet)(ethsw_ctrl_t * const p_api_ctrl, uint32_t * p_state_dlr);

    /** Gets MAC address of DLR beacon frame.
     * @par Implemented as
     * - @ref  R_ETHSW_DlrSvMacGet()
     *
     * @param[in]       p_api_ctrl              Pointer to control structure.
     * @param[out]      pp_addr_mac             Pointer to pointer to MAC address of DLR beacon frame.
     */
    fsp_err_t (* dlrSvMacGet)(ethsw_ctrl_t * const p_api_ctrl, ethsw_mac_addr_t * pp_addr_mac);
} ethsw_api_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
typedef struct st_ethsw_instance
{
    ethsw_ctrl_t      * p_ctrl;        ///< Pointer to the control structure for this instance
    ethsw_cfg_t const * p_cfg;         ///< Pointer to the configuration structure for this instance
    ethsw_api_t const * p_api;         ///< Pointer to the API structure for this instance
} ethsw_instance_t;

/*******************************************************************************************************************//**
 * @} (end addtogroup ETHSW_API)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* R_ETHSW_API_H */
