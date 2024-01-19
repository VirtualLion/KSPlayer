/* header auto-generated by pidl */

#ifndef _PIDL_HEADER_krb5pac
#define _PIDL_HEADER_krb5pac

#include <stdint.h>

#include <core/ntstatus.h>

#include <gen_ndr/security.h>
#include <gen_ndr/lsa.h>
#include <gen_ndr/netlogon.h>
#include <gen_ndr/samr.h>
#ifndef _HEADER_krb5pac
#define _HEADER_krb5pac

#define NETLOGON_GENERIC_KRB5_PAC_VALIDATE	( 3 )
struct PAC_LOGON_NAME {
	NTTIME logon_time;
	uint16_t size;/* [value(2*strlen_m(account_name))] */
	const char *account_name;/* [charset(UTF16)] */
};

struct PAC_SIGNATURE_DATA {
	uint32_t type;
	DATA_BLOB signature;/* [flag(LIBNDR_FLAG_REMAINING)] */
}/* [flag(LIBNDR_PRINT_ARRAY_HEX),public] */;

struct PAC_DOMAIN_GROUP_MEMBERSHIP {
	struct dom_sid2 *domain_sid;/* [unique] */
	struct samr_RidWithAttributeArray groups;
};

struct PAC_LOGON_INFO {
	struct netr_SamInfo3 info3;
	struct PAC_DOMAIN_GROUP_MEMBERSHIP resource_groups;
};

/* bitmap PAC_CREDENTIAL_NTLM_FLAGS */
#define PAC_CREDENTIAL_NTLM_HAS_LM_HASH ( 0x00000001 )
#define PAC_CREDENTIAL_NTLM_HAS_NT_HASH ( 0x00000002 )

struct PAC_CREDENTIAL_NTLM_SECPKG {
	uint32_t version;/* [value(0)] */
	uint32_t flags;
	struct samr_Password lm_password;/* [noprint] */
	struct samr_Password nt_password;/* [noprint] */
}/* [public] */;

struct PAC_CREDENTIAL_SUPPLEMENTAL_SECPKG {
	struct lsa_String package_name;
	uint32_t credential_size;
	uint8_t *credential;/* [noprint,size_is(credential_size),unique] */
}/* [public] */;

struct PAC_CREDENTIAL_DATA {
	uint32_t credential_count;
	struct PAC_CREDENTIAL_SUPPLEMENTAL_SECPKG *credentials;/* [size_is(credential_count)] */
}/* [public] */;

struct PAC_CREDENTIAL_DATA_CTR {
	struct PAC_CREDENTIAL_DATA *data;/* [unique] */
}/* [public] */;

struct PAC_CREDENTIAL_DATA_NDR {
	struct PAC_CREDENTIAL_DATA_CTR ctr;/* [subcontext(0xFFFFFC01)] */
}/* [public] */;

struct PAC_CREDENTIAL_INFO {
	uint32_t version;/* [value(0)] */
	uint32_t encryption_type;
	DATA_BLOB encrypted_data;/* [flag(LIBNDR_FLAG_REMAINING)] */
}/* [public] */;

struct PAC_CONSTRAINED_DELEGATION {
	struct lsa_String proxy_target;
	uint32_t num_transited_services;
	struct lsa_String *transited_services;/* [size_is(num_transited_services),unique] */
};

/* bitmap PAC_UPN_DNS_FLAGS */
#define PAC_UPN_DNS_FLAG_CONSTRUCTED ( 0x00000001 )
#define PAC_UPN_DNS_FLAG_HAS_SAM_NAME_AND_SID ( 0x00000002 )

struct PAC_UPN_DNS_INFO_SAM_NAME_AND_SID {
	uint16_t samaccountname_size;/* [value(2*strlen_m(samaccountname))] */
	const char * samaccountname;/* [flag(LIBNDR_FLAG_ALIGN8|LIBNDR_FLAG_STR_NOTERM|LIBNDR_FLAG_REMAINING),relative_short,subcontext(0),subcontext_size(samaccountname_size)] */
	uint16_t objectsid_size;/* [value(ndr_size_dom_sid(objectsid,ndr->flags))] */
	struct dom_sid *objectsid;/* [relative_short,subcontext(0),subcontext_size(objectsid_size)] */
};

union PAC_UPN_DNS_INFO_EX {
	struct PAC_UPN_DNS_INFO_SAM_NAME_AND_SID sam_name_and_sid;/* [case(PAC_UPN_DNS_FLAG_HAS_SAM_NAME_AND_SID)] */
}/* [nodiscriminant] */;

struct PAC_UPN_DNS_INFO {
	uint16_t upn_name_size;/* [value(2*strlen_m(upn_name))] */
	const char * upn_name;/* [flag(LIBNDR_FLAG_ALIGN8|LIBNDR_FLAG_STR_NOTERM|LIBNDR_FLAG_REMAINING),relative_short,subcontext(0),subcontext_size(upn_name_size)] */
	uint16_t dns_domain_name_size;/* [value(2*strlen_m(dns_domain_name))] */
	const char * dns_domain_name;/* [flag(LIBNDR_FLAG_ALIGN8|LIBNDR_FLAG_STR_NOTERM|LIBNDR_FLAG_REMAINING),relative_short,subcontext(0),subcontext_size(dns_domain_name_size)] */
	uint32_t flags;
	union PAC_UPN_DNS_INFO_EX ex;/* [switch_is(flags&PAC_UPN_DNS_FLAG_HAS_SAM_NAME_AND_SID)] */
};

/* bitmap PAC_ATTRIBUTE_INFO_FLAGS */
#define PAC_ATTRIBUTE_FLAG_PAC_WAS_REQUESTED ( 0x00000001 )
#define PAC_ATTRIBUTE_FLAG_PAC_WAS_GIVEN_IMPLICITLY ( 0x00000002 )

struct PAC_ATTRIBUTES_INFO {
	uint32_t flags_length;
	uint32_t flags;
};

struct PAC_REQUESTER_SID {
	struct dom_sid sid;
};

struct PAC_LOGON_INFO_CTR {
	struct PAC_LOGON_INFO *info;/* [unique] */
}/* [public] */;

struct PAC_CONSTRAINED_DELEGATION_CTR {
	struct PAC_CONSTRAINED_DELEGATION *info;/* [unique] */
}/* [public] */;

enum PAC_TYPE
#ifndef USE_UINT_ENUMS
 {
	PAC_TYPE_LOGON_INFO=(int)(1),
	PAC_TYPE_CREDENTIAL_INFO=(int)(2),
	PAC_TYPE_SRV_CHECKSUM=(int)(6),
	PAC_TYPE_KDC_CHECKSUM=(int)(7),
	PAC_TYPE_LOGON_NAME=(int)(10),
	PAC_TYPE_CONSTRAINED_DELEGATION=(int)(11),
	PAC_TYPE_UPN_DNS_INFO=(int)(12),
	PAC_TYPE_CLIENT_CLAIMS_INFO=(int)(13),
	PAC_TYPE_DEVICE_INFO=(int)(14),
	PAC_TYPE_DEVICE_CLAIMS_INFO=(int)(15),
	PAC_TYPE_TICKET_CHECKSUM=(int)(16),
	PAC_TYPE_ATTRIBUTES_INFO=(int)(17),
	PAC_TYPE_REQUESTER_SID=(int)(18),
	PAC_TYPE_FULL_CHECKSUM=(int)(19)
}
#else
 { __do_not_use_enum_PAC_TYPE=0x7FFFFFFF}
#define PAC_TYPE_LOGON_INFO ( 1 )
#define PAC_TYPE_CREDENTIAL_INFO ( 2 )
#define PAC_TYPE_SRV_CHECKSUM ( 6 )
#define PAC_TYPE_KDC_CHECKSUM ( 7 )
#define PAC_TYPE_LOGON_NAME ( 10 )
#define PAC_TYPE_CONSTRAINED_DELEGATION ( 11 )
#define PAC_TYPE_UPN_DNS_INFO ( 12 )
#define PAC_TYPE_CLIENT_CLAIMS_INFO ( 13 )
#define PAC_TYPE_DEVICE_INFO ( 14 )
#define PAC_TYPE_DEVICE_CLAIMS_INFO ( 15 )
#define PAC_TYPE_TICKET_CHECKSUM ( 16 )
#define PAC_TYPE_ATTRIBUTES_INFO ( 17 )
#define PAC_TYPE_REQUESTER_SID ( 18 )
#define PAC_TYPE_FULL_CHECKSUM ( 19 )
#endif
;

struct DATA_BLOB_REM {
	DATA_BLOB remaining;/* [flag(LIBNDR_FLAG_REMAINING)] */
};

union PAC_INFO {
	struct PAC_LOGON_INFO_CTR logon_info;/* [case(PAC_TYPE_LOGON_INFO),subcontext(0xFFFFFC01)] */
	struct PAC_CREDENTIAL_INFO credential_info;/* [case(PAC_TYPE_CREDENTIAL_INFO)] */
	struct PAC_SIGNATURE_DATA srv_cksum;/* [case(PAC_TYPE_SRV_CHECKSUM)] */
	struct PAC_SIGNATURE_DATA kdc_cksum;/* [case(PAC_TYPE_KDC_CHECKSUM)] */
	struct PAC_LOGON_NAME logon_name;/* [case(PAC_TYPE_LOGON_NAME)] */
	struct PAC_CONSTRAINED_DELEGATION_CTR constrained_delegation;/* [case(PAC_TYPE_CONSTRAINED_DELEGATION),subcontext(0xFFFFFC01)] */
	struct PAC_UPN_DNS_INFO upn_dns_info;/* [case(PAC_TYPE_UPN_DNS_INFO)] */
	struct PAC_SIGNATURE_DATA ticket_checksum;/* [case(PAC_TYPE_TICKET_CHECKSUM)] */
	struct PAC_ATTRIBUTES_INFO attributes_info;/* [case(PAC_TYPE_ATTRIBUTES_INFO)] */
	struct PAC_REQUESTER_SID requester_sid;/* [case(PAC_TYPE_REQUESTER_SID)] */
	struct PAC_SIGNATURE_DATA full_checksum;/* [case(PAC_TYPE_FULL_CHECKSUM)] */
	struct DATA_BLOB_REM unknown;/* [default,subcontext(0)] */
}/* [gensize,nodiscriminant,public] */;

struct PAC_BUFFER {
	enum PAC_TYPE type;
	uint32_t _ndr_size;/* [value(_ndr_size_PAC_INFO(info,type,LIBNDR_FLAG_ALIGN8))] */
	union PAC_INFO *info;/* [flag(LIBNDR_FLAG_ALIGN8),relative,subcontext(0),subcontext_size(NDR_ROUND(_ndr_size,8)),switch_is(type)] */
	uint32_t _pad;/* [value(0)] */
}/* [nopull,nopush,public] */;

struct PAC_DATA {
	uint32_t num_buffers;
	uint32_t version;
	struct PAC_BUFFER *buffers;
}/* [public] */;

struct PAC_BUFFER_RAW {
	enum PAC_TYPE type;
	uint32_t ndr_size;
	struct DATA_BLOB_REM *info;/* [flag(LIBNDR_FLAG_ALIGN8),relative,subcontext(0),subcontext_size(NDR_ROUND(ndr_size,8))] */
	uint32_t _pad;/* [value(0)] */
}/* [public] */;

struct PAC_DATA_RAW {
	uint32_t num_buffers;
	uint32_t version;
	struct PAC_BUFFER_RAW *buffers;
}/* [public] */;

struct PAC_Validate {
	uint32_t MessageType;/* [value(NETLOGON_GENERIC_KRB5_PAC_VALIDATE)] */
	uint32_t ChecksumLength;
	int32_t SignatureType;
	uint32_t SignatureLength;
	DATA_BLOB ChecksumAndSignature;/* [flag(LIBNDR_FLAG_REMAINING)] */
}/* [public] */;

struct netsamlogoncache_entry {
	time_t timestamp;
	struct netr_SamInfo3 info3;
}/* [public] */;

#endif /* _HEADER_krb5pac */
#endif /* _PIDL_HEADER_krb5pac */
