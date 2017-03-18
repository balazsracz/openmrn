/*
* Copyright (C) 2016 Texas Instruments Incorporated
*
* All rights reserved. Property of Texas Instruments Incorporated.
* Restricted rights to use, duplicate or disclose this code are
* granted through contract.
*
* The program may not be used without the written permission of
* Texas Instruments Incorporated or against the terms and conditions
* stipulated in the agreement under which this program has been supplied,
* and under no circumstances can it be used with non-TI connectivity device.
*
*/
/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#ifndef __SL_COMPAT_H__
#define __SL_COMPAT_H__

#ifdef __cplusplus
extern "C" {
#endif
#ifdef SUPPORT_SL_R1_API
/* Updated Macro Definitions */
#define SL_DEVICE_GENERAL_CONFIGURATION SL_DEVICE_GENERAL
#define SL_DEVICE_GENERAL_CONFIGURATION_DATE_TIME SL_DEVICE_GENERAL_DATE_TIME
#define SL_SCAN_SEC_TYPE_OPEN SL_WLAN_SEC_TYPE_OPEN
#define SL_SCAN_SEC_TYPE_WEP SL_WLAN_SEC_TYPE_WEP
#define SL_SCAN_SEC_TYPE_WPA SL_WLAN_SEC_TYPE_WPA
#define SL_SCAN_SEC_TYPE_WPA2 SL_WLAN_SEC_TYPE_WPA_WPA2
#define FS_MODE_OPEN_WRITE SL_FS_WRITE
#define FS_MODE_OPEN_READ SL_FS_READ

#define SL_POLICY_CONNECTION SL_WLAN_POLICY_CONNECTION
#define SL_POLICY_SCAN SL_WLAN_POLICY_SCAN
#define SL_POLICY_PM SL_WLAN_POLICY_PM
#define SL_POLICY_P2P SL_WLAN_POLICY_P2P
#define SL_NORMAL_POLICY SL_WLAN_NORMAL_POLICY
#define SL_BSSID_LENGTH SL_WLAN_BSSID_LENGTH
#define SL_WLAN_CONNECT_EVENT SL_WLAN_EVENT_CONNECT
#define SL_WLAN_DISCONNECT_EVENT SL_WLAN_EVENT_DISCONNECT
#define SL_WLAN_SMART_CONFIG_COMPLETE_EVENT SL_WLAN_EVENT_PROVISIONING_STATUS
#define SL_WLAN_STA_CONNECTED_EVENT SL_WLAN_EVENT_P2P_CLIENT_ADDED
#define SL_WLAN_STA_DISCONNECTED_EVENT SL_WLAN_EVENT_P2P_CLIENT_REMOVED
#define SL_USER_INITIATED_DISCONNECTION SL_WLAN_DISCONNECT_USER_INITIATED
#define WLAN_AP_OPT_SSID SL_WLAN_AP_OPT_SSID
#define WLAN_AP_OPT_CHANNEL SL_WLAN_AP_OPT_CHANNEL
#define WLAN_AP_OPT_HIDDEN_SSID SL_WLAN_AP_OPT_HIDDEN_SSID
#define WLAN_AP_OPT_SECURITY_TYPE SL_WLAN_AP_OPT_SECURITY_TYPE
#define WLAN_AP_OPT_PASSWORD SL_WLAN_AP_OPT_PASSWORD
#define WLAN_AP_OPT_MAX_STATIONS SL_WLAN_AP_OPT_MAX_STATIONS
#define SL_SEC_TYPE_OPEN SL_WLAN_SEC_TYPE_OPEN
#define SL_SEC_TYPE_WEP SL_WLAN_SEC_TYPE_WEP
#define SL_SEC_TYPE_WPA SL_WLAN_SEC_TYPE_WPA
#define SL_SEC_TYPE_WPA_WPA2 SL_WLAN_SEC_TYPE_WPA_WPA2
#define WLAN_GENERAL_PARAM_OPT_STA_TX_POWER                                    \
    SL_WLAN_GENERAL_PARAM_OPT_STA_TX_POWER
#define WLAN_GENERAL_PARAM_OPT_AP_TX_POWER SL_WLAN_GENERAL_PARAM_OPT_AP_TX_POWER
#define SL_REMOVE_RX_FILTER SL_WLAN_RX_FILTER_REMOVE
#define SL_NETAPP_IP_LEASED_EVENT SL_NETAPP_EVENT_DHCPV4_LEASED
#define SL_NETAPP_IP_RELEASED_EVENT SL_NETAPP_EVENT_DHCPV4_RELEASED
#define SL_NETAPP_IPV4_IPACQUIRED_EVENT SL_NETAPP_EVENT_IPV4_ACQUIRED
#define SL_NETAPP_HTTPGETTOKENVALUE_EVENT SL_NETAPP_EVENT_HTTP_TOKEN_GET
#define SL_NETAPP_HTTPPOSTTOKENVALUE_EVENT SL_NETAPP_EVENT_HTTP_TOKEN_POST
#define SL_NET_APP_HTTP_SERVER_ID SL_NETAPP_HTTP_SERVER_ID
#define SL_IPV4_DNS_CLIENT SL_NETCFG_IPV4_DNS_CLIENT
#define SL_MAC_ADDRESS_GET SL_NETCFG_MAC_ADDRESS_GET
#define SL_MAC_ADDRESS_SET SL_NETCFG_MAC_ADDRESS_SET
#define SL_IPV4_STA_P2P_CL_DHCP_ENABLE SL_NETCFG_IPV4_DHCP_CLIENT
#define SL_SO_SECURE_FILES_DH_KEY_FILE_NAME                                    \
    SL_SO_SECURE_FILES_PEER_CERT_OR_DH_KEY_FILE_NAME
#define SO_SECURE_DOMAIN_NAME_VERIFICATION SL_SO_SECURE_DOMAIN_NAME_VERIFICATION
/*** Updatetd Structure Names ***/
#define Sl_WlanNetworkEntry_t SlWlanNetworkEntry_t
#define SlHttpServerEvent_t SlNetAppHttpServerEvent_t
#define SlHttpServerResponse_t SlNetAppHttpServerResponse_t
#define APModeStaConnected P2PClientAdded
#define APModestaDisconnected P2PClientRemoved
#define STAandP2PModeWlanConnected Connect
#define STAandP2PModeDisconnected Disconnect
#define SlSecParams_t SlWlanSecParams_t
#define SlSecParamsExt_t SlWlanSecParamsExt_t
#define SlGetSecParamsExt_t SlWlanGetSecParamsExt_t
#define SlWlanProtocolInfoElement_t SlWlanInfoElement_t
#define SlWlanProtocolSetInfoElement_t SlWlanSetInfoElement_t
#define slWlanConnectAsyncResponse_t SlWlanEventDisconnect_t /* ??? */
#define _WlanRxFilterOperationCommandBuff_t SlWlanRxFilterOperationCommandBuff_t
#define slPeerInfoAsyncResponse_t SlWlanEventP2PClientAdded_t
#define SlVersionFull SlDeviceVersion_t
#define SlSockSecureMethod SlSockSecureMethod_t
#define SlSockSecureMask SlSockSecureMask_t
/*** Updatetd Structure Members Names ***/
#define AllocatedLen StorageSize
#define FileLen Len
#define NonblockingEnabled NonBlockingEnabled
#define reason Reason
#define reason_code ReasonCode
#define sd Sd
#define type Type
#define val Val
#define mac Mac
#define secureMask SecureMask
#define secureMethod SecureMethod
#define sl_tm_year tm_year
#define sl_tm_mon tm_mon
#define sl_tm_day tm_day
#define sl_tm_hour tm_hour
#define sl_tm_min tm_min
#define sl_tm_sec tm_sec
#define socketAsyncEvent SocketAsyncEvent
#define deviceDriverReport DeviceDriverReport
#define deviceEvent DeviceEvent
#define deviceReport DeviceReport
#define ipAcquiredV4 IpAcquiredV4
#define ipLeased IpLeased
#define ipReleased IpReleased
#define status Status
#define rssi Rssi
#define bssid Bssid
#define ssid Ssid
#define ssid_len SsidLen
#define sec_type SecurityInfo
#define ssid_name SsidName
#define FilterIdMask FilterBitmap
/*** Updatetd Error Names ***/
#define SL_FS_ERR_FILE_NOT_EXISTS SL_ERROR_FS_FILE_NOT_EXISTS
#define SL_EAGAIN SL_ERROR_BSD_EAGAIN
#define SL_ENSOCK SL_ERROR_BSD_ENSOCK
#define SL_INEXE SL_ERROR_BSD_INEXE
#define SL_ESECCLOSED SL_ERROR_BSD_ESECCLOSED
#define SL_ECLOSE SL_ERROR_BSD_ECLOSE
#define SL_ESECT00MANYSSLOPENED SL_ERROR_BSD_ESECT00MANYSSLOPENED
#define SL_FS_FILE_HAS_NOT_BEEN_CLOSE_CORRECTLY                                \
    SL_ERROR_FS_FILE_HAS_NOT_BEEN_CLOSE_CORRECTLY
#define SL_ESEC_RSA_WRONG_TYPE_E
#define SL_ESEC_ASN_SIG_CONFIRM_E SL_ERROR_BSD_ESEC_ASN_SIG_CONFIRM_E
#define ROLE_STA_ERR SL_ERROR_ROLE_STA_ERR
#define ROLE_AP_ERR SL_ERROR_ROLE_AP_ERR
#define ROLE_P2P_ERR SL_ERROR_ROLE_P2P_ERR
/*** Update Macro Functions ***/
#define SL_CONNECTION_POLICY(Auto, Fast, Open, anyP2P, autoSmartConfig)        \
    SL_WLAN_CONNECTION_POLICY(Auto, Fast, anyP2P, autoSmartConfig)
#define SL_SCAN_POLICY(enable) SL_WLAN_SCAN_POLICY(enable, 0)
#define FS_MODE_OPEN_CREATE(_maxSize_, _flag_)                                 \
    (SL_FS_CREATE | SL_FS_CREATE_MAX_SIZE(_maxSize_))
/*** Updatetd Function ***/
#define sl_WlanRxFilterSet(opcode, maskeSize, mask)                            \
    sl_WlanSet(SL_WLAN_RX_FILTERS_ID, opcode, mask, maskeSize)
#define sl_DevSet sl_DeviceSet
#define sl_DevGet sl_DeviceGet
#endif // SUPPORT_SL_R1_API
#ifdef __cplusplus
}
#endif /* __cplusplus */

#include "ti/drivers/net/wifi/simplelink.h"
#include "ti/drivers/net/wifi/fs.h"


static inline _i32 sl_FsOpen(const _u8 *pFileName,const _u32 AccessModeAndMaxSize,_u32 *pToken,_i32 *pFileHandle) {
    _i32 hnd = sl_FsOpen(pFileName, AccessModeAndMaxSize, pToken);
    if (hnd >= 0) {
        *pFileHandle = hnd;
        return 0;
    }
    return hnd;
}

#endif /* __SL_COMPAT_H__ */
