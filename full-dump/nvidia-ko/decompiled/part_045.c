// ===== 00502450 libspdm_hash_final =====

undefined8 libspdm_hash_final(uint param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  if (param_1 == 8) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x193,
               "false");
    return 0;
  }
  if (param_1 < 9) {
    if (param_1 == 2) {
      uVar1 = libspdm_sha384_final(param_2,param_3);
      return uVar1;
    }
    if (param_1 == 4) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x18c,
                 "false");
      return 0;
    }
    if (param_1 == 1) {
      uVar1 = libspdm_sha256_final(param_2,param_3);
      return uVar1;
    }
  }
  else {
    if (param_1 == 0x20) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x1a1,
                 "false");
      return 0;
    }
    if (param_1 == 0x40) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x1a8,
                 "false");
      return 0;
    }
    if (param_1 == 0x10) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x19a,
                 "false");
      return 0;
    }
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x1ac,"false"
            );
  return 0;
}


// ===== 00502580 libspdm_hash_all =====

undefined8 libspdm_hash_all(uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  if (param_1 == 8) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x1ce,
               "false");
    return 0;
  }
  if (param_1 < 9) {
    if (param_1 == 2) {
      uVar1 = libspdm_sha384_hash_all(param_2,param_3,param_4);
      return uVar1;
    }
    if (param_1 == 4) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x1c7,
                 "false");
      return 0;
    }
    if (param_1 == 1) {
      uVar1 = libspdm_sha256_hash_all(param_2,param_3,param_4);
      return uVar1;
    }
  }
  else {
    if (param_1 == 0x20) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x1dc,
                 "false");
      return 0;
    }
    if (param_1 == 0x40) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x1e3,
                 "false");
      return 0;
    }
    if (param_1 == 0x10) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x1d5,
                 "false");
      return 0;
    }
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x1e7,"false"
            );
  return 0;
}


// ===== 005026b0 libspdm_get_measurement_hash_size =====

undefined4 libspdm_get_measurement_hash_size(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 - 1 < (param_1 ^ param_1 - 1)) {
    uVar1 = 0;
    if (param_1 != 0) {
      for (; (param_1 >> uVar1 & 1) == 0; uVar1 = uVar1 + 1) {
      }
    }
    uVar2 = 0xffffffff;
    if (param_1 != 0) {
      uVar2 = uVar1;
    }
    if (uVar2 < 8) {
      return *(undefined4 *)(CSWTCH_10 + (ulong)uVar2 * 4);
    }
  }
  return 0;
}


// ===== 005026f0 libspdm_hkdf_extract =====

undefined8
libspdm_hkdf_extract
          (uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6,undefined8 param_7)

{
  undefined8 uVar1;
  
  if (param_1 == 8) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hkdf.c",0x27,
               "false",param_5,param_6,param_7);
    return 0;
  }
  if (param_1 < 9) {
    if (param_1 == 2) {
      uVar1 = libspdm_hkdf_sha384_extract(param_2,param_3,param_4);
      return uVar1;
    }
    if (param_1 == 4) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hkdf.c",0x20,
                 "false",param_5,param_6,param_7);
      return 0;
    }
    if (param_1 == 1) {
      uVar1 = libspdm_hkdf_sha256_extract(param_2);
      return uVar1;
    }
  }
  else {
    if (param_1 == 0x20) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hkdf.c",0x35,
                 "false",param_5,param_6,param_7);
      return 0;
    }
    if (param_1 == 0x40) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hkdf.c",0x3c,
                 "false",param_5,param_6,param_7);
      return 0;
    }
    if (param_1 == 0x10) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hkdf.c",0x2e,
                 "false",param_5,param_6,param_7);
      return 0;
    }
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hkdf.c",0x40,"false",
             param_5,param_6,param_7);
  return 0;
}


// ===== 00502830 libspdm_hkdf_expand =====

undefined8
libspdm_hkdf_expand(uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  undefined8 uVar1;
  
  if (param_1 == 8) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hkdf.c",99,"false",
               param_5,param_6,param_7);
    return 0;
  }
  if (param_1 < 9) {
    if (param_1 == 2) {
      uVar1 = libspdm_hkdf_sha384_expand(param_2,param_3,param_4);
      return uVar1;
    }
    if (param_1 == 4) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hkdf.c",0x5c,
                 "false",param_5,param_6,param_7);
      return 0;
    }
    if (param_1 == 1) {
      uVar1 = libspdm_hkdf_sha256_expand(param_2);
      return uVar1;
    }
  }
  else {
    if (param_1 == 0x20) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hkdf.c",0x71,
                 "false",param_5,param_6,param_7);
      return 0;
    }
    if (param_1 == 0x40) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hkdf.c",0x78,
                 "false",param_5,param_6,param_7);
      return 0;
    }
    if (param_1 == 0x10) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hkdf.c",0x6a,
                 "false",param_5,param_6,param_7);
      return 0;
    }
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hkdf.c",0x7c,"false",
             param_5,param_6,param_7);
  return 0;
}


// ===== 00502970 libspdm_hmac_all =====

undefined8
libspdm_hmac_all(uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5,undefined8 param_6)

{
  undefined8 uVar1;
  
  if (param_1 == 8) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hmac.c",0x18a,
               "false");
    return 0;
  }
  if (param_1 < 9) {
    if (param_1 == 2) {
      uVar1 = libspdm_hmac_sha384_all(param_2,param_3,param_4,param_5,param_6);
      return uVar1;
    }
    if (param_1 == 4) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hmac.c",0x183,
                 "false");
      return 0;
    }
    if (param_1 == 1) {
      uVar1 = libspdm_hmac_sha256_all(param_2);
      return uVar1;
    }
  }
  else {
    if (param_1 == 0x20) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hmac.c",0x198,
                 "false");
      return 0;
    }
    if (param_1 == 0x40) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hmac.c",0x19f,
                 "false");
      return 0;
    }
    if (param_1 == 0x10) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hmac.c",0x191,
                 "false");
      return 0;
    }
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hmac.c",0x1a3,"false"
            );
  return 0;
}


// ===== 00502aa0 libspdm_get_random_number =====

undefined8 libspdm_get_random_number(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 1;
  }
  uVar1 = libspdm_random_bytes(param_2,param_1);
  return uVar1;
}


// ===== 00502ad0 libspdm_allocate_req_session_id =====

undefined8 libspdm_allocate_req_session_id(long param_1,char param_2)

{
  if (param_2 == '\0') {
    if ((*(uint *)(param_1 + 0xb44) != 0) &&
       (*(uint *)(param_1 + 0xb44) <= *(uint *)(param_1 + 0xb4c))) {
      libspdm_debug_print(0x80000000,"libspdm_allocate_req_session_id - MAX DHE session\n");
      return 0;
    }
  }
  else if ((*(uint *)(param_1 + 0xb48) != 0) &&
          (*(uint *)(param_1 + 0xb48) <= *(uint *)(param_1 + 0xb50))) {
    libspdm_debug_print(0x80000000,"libspdm_allocate_req_session_id - MAX PSK session\n");
    return 0;
  }
  if (*(short *)(param_1 + 0x908) != 0) {
    libspdm_debug_print(0x80000000,"libspdm_allocate_req_session_id - MAX session_id\n");
    return 0;
  }
  return 0xffffffff;
}


// ===== 00502b70 libspdm_build_opaque_data_supported_version_data =====

void libspdm_build_opaque_data_supported_version_data
               (long param_1,ulong *param_2,undefined8 *param_3)

{
  byte bVar1;
  ulong uVar2;
  undefined8 *puVar3;
  long lVar4;
  
  if (*(char *)(param_1 + 0x140) != '\0') {
    uVar2 = libspdm_get_opaque_data_supported_version_data_size();
    if (*param_2 < uVar2) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_common.c",0x3d,
                 "*data_out_size >= final_data_size");
      bVar1 = libspdm_get_connection_version(param_1);
    }
    else {
      bVar1 = libspdm_get_connection_version(param_1);
    }
    if (bVar1 < 0x12) {
      *param_3 = 0x101444d5446;
      puVar3 = param_3 + 1;
    }
    else {
      *(undefined1 *)param_3 = 1;
      libspdm_write_uint24((undefined1 *)((long)param_3 + 1),0);
      puVar3 = (undefined8 *)((long)param_3 + 4);
    }
    lVar4 = (long)puVar3 + 7;
    *(undefined2 *)puVar3 = 0;
    bVar1 = *(byte *)(param_1 + 0x140);
    *(undefined2 *)((long)puVar3 + 4) = 0x101;
    *(ushort *)((long)puVar3 + 2) = bVar1 + 3 + (ushort)bVar1;
    bVar1 = *(byte *)(param_1 + 0x140);
    *(byte *)((long)puVar3 + 6) = bVar1;
    libspdm_copy_mem(lVar4,(undefined1 *)((long)param_3 + (*param_2 - lVar4)),param_1 + 0x142,
                     (ulong)bVar1 * 2);
    lVar4 = lVar4 + (ulong)*(byte *)(param_1 + 0x140) * 2;
    libspdm_zero_mem(lVar4,(undefined1 *)((long)param_3 + (uVar2 - lVar4)));
    return;
  }
  *param_2 = 0;
  return;
}


// ===== 00502c90 libspdm_process_opaque_data_version_selection_data =====

/* WARNING: Removing unreachable block (ram,0x00502cf1) */
/* WARNING: Removing unreachable block (ram,0x00502cfc) */
/* WARNING: Removing unreachable block (ram,0x00502d08) */
/* WARNING: Removing unreachable block (ram,0x00502d1c) */
/* WARNING: Removing unreachable block (ram,0x00502d30) */
/* WARNING: Removing unreachable block (ram,0x00502d51) */
/* WARNING: Removing unreachable block (ram,0x00502d71) */
/* WARNING: Removing unreachable block (ram,0x00502d40) */
/* WARNING: Removing unreachable block (ram,0x00502de0) */
/* WARNING: Removing unreachable block (ram,0x00502de4) */
/* WARNING: Removing unreachable block (ram,0x00502da8) */

undefined8 libspdm_process_opaque_data_version_selection_data(long param_1)

{
  undefined8 uStack_40;
  undefined1 local_30 [8];
  
  if (*(char *)(param_1 + 0x140) != '\0') {
    libspdm_get_element_from_opaque_data();
    libspdm_debug_print(0x40,"get element error!\n",local_30,uStack_40);
    return 0x80010005;
  }
  return 0;
}


// ===== 00502e00 libspdm_init_connection =====

ulong libspdm_init_connection(undefined8 param_1,char param_2)

{
  uint uVar1;
  ulong uVar2;
  
  uVar2 = libspdm_get_version(param_1,0,0);
  if ((((uint)(uVar2 >> 0x1c) & 0xf) != 8) && (uVar2 = 0, param_2 == '\0')) {
    uVar2 = libspdm_get_capabilities(param_1);
    if (((uint)(uVar2 >> 0x1c) & 0xf) != 8) {
      uVar1 = libspdm_negotiate_algorithms(param_1);
      uVar2 = (ulong)uVar1;
      if (uVar1 >> 0x1c != 8) {
        uVar2 = 0;
      }
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 00502e60 libspdm_start_session =====

uint libspdm_start_session
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined4 *param_8,
               undefined8 param_9,undefined8 param_10)

{
  byte bVar1;
  uint uVar2;
  long lVar3;
  char *pcVar4;
  char local_19 [9];
  
  if (param_2 != '\0') {
    return 0x80010002;
  }
  pcVar4 = local_19;
  uVar2 = libspdm_send_receive_key_exchange
                    (param_1,param_5,param_6,param_7,param_8,param_9,pcVar4,param_10);
  if (uVar2 >> 0x1c == 8) {
    libspdm_debug_print(0x40,"libspdm_start_session - libspdm_send_receive_key_exchange - %xu\n",
                        uVar2);
    return uVar2;
  }
  lVar3 = libspdm_get_session_info_via_session_id(param_1,*param_8,pcVar4);
  if (lVar3 == 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_communication.c",
               0x47,"false");
    return 0x80010003;
  }
  bVar1 = *(byte *)(lVar3 + 5);
  if (bVar1 != 2) {
    if (bVar1 < 3) goto LAB_00502ed7;
    if (bVar1 != 4) {
      libspdm_debug_print(0x40,"libspdm_start_session - unknown mut_auth_requested - 0x%x\n");
      return 0x80010005;
    }
  }
  uVar2 = libspdm_encapsulated_request(param_1,param_8,bVar1,local_19);
  libspdm_debug_print(0x40,"libspdm_start_session - libspdm_encapsulated_request - %xu\n",uVar2);
  if (uVar2 >> 0x1c == 8) {
    return uVar2;
  }
LAB_00502ed7:
  if (local_19[0] == '\x0f') {
    local_19[0] = -1;
  }
  uVar2 = libspdm_send_receive_finish(param_1,*param_8,local_19[0]);
  libspdm_debug_print(0x40,"libspdm_start_session - libspdm_send_receive_finish - %xu\n",uVar2);
  return uVar2;
}


// ===== 00502fe0 libspdm_send_data =====

ulong libspdm_send_data(long param_1,undefined8 param_2,undefined1 param_3,undefined8 param_4,
                       ulong param_5)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  long local_48;
  ulong local_40 [2];
  
  uVar1 = *(uint *)(param_1 + 0x11c);
  uVar2 = libspdm_acquire_sender_buffer(param_1,local_40,&local_48);
  if (((uint)(uVar2 >> 0x1c) & 0xf) != 8) {
    uVar2 = (ulong)*(uint *)(param_1 + 0x120);
    uVar3 = (ulong)uVar1;
    if (local_40[0] < uVar2 + uVar3) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_communication.c"
                 ,0x145,
                 "message_size >= transport_header_size + context->local_context.capability.transport_tail_size"
                );
      uVar2 = (ulong)*(uint *)(param_1 + 0x120);
    }
    uVar2 = (local_40[0] - uVar3) - uVar2;
    if (uVar2 < param_5) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_communication.c"
                 ,0x14b,"spdm_request_size >= request_size");
    }
    libspdm_copy_mem(local_48 + uVar3,uVar2,param_4,param_5);
    uVar1 = libspdm_send_request(param_1,param_2,param_3,param_5,local_48 + uVar3);
    libspdm_release_sender_buffer(param_1);
    uVar2 = (ulong)uVar1;
  }
  return uVar2;
}


// ===== 005030f0 libspdm_receive_data =====

ulong libspdm_receive_data
                (undefined8 param_1,undefined4 *param_2,undefined1 param_3,undefined8 param_4,
                ulong *param_5)

{
  uint uVar1;
  ulong uVar2;
  long local_58;
  ulong local_50;
  long local_48;
  ulong local_40 [2];
  
  uVar2 = libspdm_acquire_receiver_buffer(param_1,local_40,&local_48);
  if (((uint)(uVar2 >> 0x1c) & 0xf) != 8) {
    local_58 = local_48;
    local_50 = local_40[0];
    uVar1 = libspdm_receive_response(param_1,param_2,param_3,&local_50,&local_58);
    if (uVar1 >> 0x1c == 8) {
      libspdm_release_receiver_buffer(param_1);
      uVar2 = (ulong)uVar1;
    }
    else if (((*(char *)(local_58 + 1) == '\x7f') && (*(char *)(local_58 + 2) == '\x06')) &&
            (param_2 != (undefined4 *)0x0)) {
      libspdm_free_session_id(param_1,*param_2);
      libspdm_release_receiver_buffer(param_1);
      uVar2 = 0x8001000f;
    }
    else {
      if (*param_5 < local_50) {
        *param_5 = local_50;
        libspdm_release_receiver_buffer(param_1);
        return 0x8001000d;
      }
      libspdm_copy_mem(param_4);
      *param_5 = local_50;
      libspdm_release_receiver_buffer(param_1);
      uVar2 = 0;
    }
  }
  return uVar2;
}


// ===== 00503200 libspdm_send_receive_data =====

void libspdm_send_receive_data
               (undefined8 param_1,undefined8 param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  uint uVar1;
  
  uVar1 = libspdm_send_data(param_1,param_2,param_3);
  if (uVar1 >> 0x1c != 8) {
    libspdm_receive_data(param_1,param_2,param_3,param_6,param_7);
    return;
  }
  return;
}


// ===== 00503270 libspdm_get_encap_response_certificate =====

undefined8
libspdm_get_encap_response_certificate
          (long param_1,ulong param_2,byte *param_3,ulong *param_4,byte *param_5)

{
  long lVar1;
  ushort uVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  undefined8 uVar6;
  ulong uVar7;
  uint uVar8;
  undefined8 uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong local_58;
  ulong local_50;
  ushort local_42;
  
  bVar3 = libspdm_get_connection_version();
  if (bVar3 < 0x11) {
    uVar6 = 0x82;
    uVar9 = 7;
    goto LAB_005032d3;
  }
  bVar3 = *param_3;
  bVar4 = libspdm_get_connection_version(param_1);
  if (bVar3 != bVar4) {
    uVar6 = 0;
    uVar9 = 0x41;
    goto LAB_005032d3;
  }
  cVar5 = libspdm_is_capabilities_flag_supported(param_1,1,2,0);
  if (cVar5 == '\0') {
    uVar6 = 0x82;
    uVar9 = 7;
    goto LAB_005032d3;
  }
  if ((param_2 < 8) || (bVar3 = param_3[2], 7 < bVar3)) goto LAB_005034c0;
  lVar1 = param_1 + (ulong)bVar3 * 8;
  if (*(long *)(lVar1 + 0x150) != 0) {
    uVar7 = *(ulong *)(lVar1 + 400);
    if ((*param_3 < 0x13) || ((param_3[3] & 1) == 0)) {
      uVar2 = *(ushort *)(param_3 + 4);
      local_50 = (ulong)uVar2;
      if (uVar7 <= local_50) goto LAB_005034c0;
      uVar8 = 0x1000;
      if (*(ushort *)(param_3 + 6) < 0x1001) {
        uVar8 = (uint)*(ushort *)(param_3 + 6);
      }
      local_42 = (ushort)uVar8;
      uVar11 = (ulong)(uVar8 + uVar2);
      if (uVar7 < uVar11) {
        uVar8 = (int)uVar7 - (uint)uVar2;
        local_42 = (ushort)uVar8;
        local_58 = (ulong)(uVar8 & 0xffff);
        uVar11 = local_58 + 8;
        uVar7 = uVar7 - ((uVar8 & 0xffff) + (uint)uVar2);
      }
      else {
        local_58 = (ulong)local_42;
        uVar7 = uVar7 - uVar11;
        uVar11 = local_58 + 8;
      }
    }
    else {
      if (uVar7 == 0) {
LAB_005034c0:
        uVar6 = 0;
        uVar9 = 1;
        goto LAB_005032d3;
      }
      local_58 = 0;
      uVar11 = 8;
      local_50 = 0;
      local_42 = 0;
    }
    libspdm_reset_message_buffer_via_request_code(param_1,0,param_3[1]);
    uVar10 = *param_4;
    if (uVar10 < uVar11) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_encap_certificate.c"
                 ,0x6d,"*response_size >= sizeof(spdm_certificate_response_t) + length");
      uVar10 = *param_4;
    }
    *param_4 = uVar11;
    libspdm_zero_mem(param_5,uVar11);
    bVar4 = *param_3;
    param_5[1] = 2;
    param_5[3] = 0;
    *param_5 = bVar4;
    param_5[2] = bVar3;
    if ((0x12 < *param_3) && (*(char *)(param_1 + 0x64a) != '\0')) {
      param_5[3] = *(byte *)(param_1 + 0x1d9 + (ulong)bVar3);
    }
    *(short *)(param_5 + 6) = (short)uVar7;
    *(ushort *)(param_5 + 4) = local_42;
    libspdm_copy_mem(param_5 + 8,uVar10 - 8,local_50 + *(long *)(lVar1 + 0x150),local_58);
    uVar8 = libspdm_append_message_mut_b(param_1,param_3,param_2);
    if ((uVar8 >> 0x1c != 8) &&
       (uVar8 = libspdm_append_message_mut_b(param_1,param_5,*param_4), uVar8 >> 0x1c != 8)) {
      return 0;
    }
  }
  uVar6 = 0;
  uVar9 = 5;
LAB_005032d3:
  uVar6 = libspdm_generate_encap_error_response(param_1,uVar9,uVar6,param_4,param_5);
  return uVar6;
}


// ===== 00503590 libspdm_get_encap_response_digest =====

undefined8
libspdm_get_encap_response_digest
          (long param_1,ulong param_2,byte *param_3,ulong *param_4,byte *param_5)

{
  int iVar1;
  long lVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  ulong uVar9;
  ulong uVar10;
  long lVar11;
  undefined8 uVar12;
  long lVar13;
  
  bVar3 = libspdm_get_connection_version();
  if (bVar3 < 0x11) {
    uVar8 = 0x81;
    uVar12 = 7;
  }
  else {
    bVar3 = *param_3;
    bVar4 = libspdm_get_connection_version(param_1);
    if (bVar3 == bVar4) {
      cVar5 = libspdm_is_capabilities_flag_supported(param_1,1,2,0);
      if (cVar5 == '\0') {
        uVar8 = 0x81;
        uVar12 = 7;
      }
      else if (param_2 < 4) {
        uVar8 = 0;
        uVar12 = 1;
      }
      else {
        libspdm_reset_message_buffer_via_request_code(param_1,0,param_3[1]);
        uVar6 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
        uVar7 = libspdm_get_cert_slot_count(param_1);
        lVar11 = 0;
        if (0x12 < *param_3) {
          lVar11 = (ulong)*(byte *)(param_1 + 0x64a) << 2;
        }
        uVar9 = (ulong)uVar7 & 0xff;
        uVar10 = ((ulong)uVar6 + lVar11) * uVar9 + 4;
        if (*param_4 < uVar10) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_encap_digests.c"
                     ,0x4f,
                     "*response_size >= sizeof(spdm_digest_response_t) + (hash_size + additional_size) * slot_count"
                    );
        }
        *param_4 = uVar10;
        libspdm_zero_mem(param_5,uVar10);
        bVar3 = *param_3;
        param_5[3] = 0;
        param_5[1] = 1;
        param_5[2] = 0;
        *param_5 = bVar3;
        if (0x12 < *param_3) {
          param_5[2] = *(byte *)(param_1 + 0x1d0);
        }
        bVar3 = 0;
        lVar13 = 0;
        lVar11 = (ulong)((uVar7 & 0xff) * uVar6) + 4;
        lVar2 = uVar9 + lVar11;
        do {
          if (*(long *)(param_1 + 0x150 + lVar13 * 8) != 0) {
            param_5[3] = param_5[3] | (byte)(1 << ((byte)lVar13 & 0x1f));
            cVar5 = libspdm_generate_cert_chain_hash
                              (param_1,lVar13,param_5 + (ulong)(bVar3 * uVar6) + 4);
            if ((0x12 < *param_3) && (*(char *)(param_1 + 0x64a) != '\0')) {
              uVar10 = (ulong)bVar3;
              param_5[uVar10 + lVar11] = *(byte *)(param_1 + 0x1d1 + lVar13);
              param_5[uVar10 + lVar2] = *(byte *)(param_1 + 0x1d9 + lVar13);
              *(undefined2 *)(param_5 + uVar9 + uVar10 * 2 + lVar2) =
                   *(undefined2 *)(param_1 + 0x1e2 + lVar13 * 2);
            }
            if (cVar5 == '\0') goto LAB_005038d6;
            bVar3 = bVar3 + 1;
          }
          lVar13 = lVar13 + 1;
        } while (lVar13 != 8);
        uVar6 = libspdm_append_message_mut_b(param_1,param_3,param_2);
        if ((uVar6 >> 0x1c != 8) &&
           (uVar6 = libspdm_append_message_mut_b(param_1,param_5,*param_4), uVar6 >> 0x1c != 8)) {
          if (*(char *)(param_1 + 0x8c) == '\0') {
            iVar1 = *(int *)(param_1 + 0xb18);
          }
          else {
            iVar1 = *(int *)(param_1 + 0x88);
          }
          if ((((iVar1 == 0) ||
               (lVar11 = libspdm_get_session_info_via_session_id(param_1), lVar11 == 0)) ||
              (*(char *)(param_1 + 0x64a) == '\0')) ||
             (uVar6 = libspdm_append_message_encap_d(param_1,lVar11,1,param_5,*param_4),
             uVar6 >> 0x1c != 8)) {
            return 0;
          }
        }
LAB_005038d6:
        uVar8 = 0;
        uVar12 = 5;
      }
    }
    else {
      uVar8 = 0;
      uVar12 = 0x41;
    }
  }
  uVar8 = libspdm_generate_encap_error_response(param_1,uVar12,uVar8,param_4,param_5);
  return uVar8;
}


// ===== 00503900 libspdm_generate_encap_error_response =====

undefined8
libspdm_generate_encap_error_response
          (undefined8 param_1,undefined1 param_2,undefined1 param_3,ulong *param_4,
          undefined1 *param_5)

{
  undefined1 uVar1;
  
  if (*param_4 < 4) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_encap_error.c",
               0x13,"*response_size >= sizeof(spdm_error_response_t)");
  }
  *param_4 = 4;
  uVar1 = libspdm_get_connection_version(param_1);
  param_5[1] = 0x7f;
  *param_5 = uVar1;
  param_5[2] = param_2;
  param_5[3] = param_3;
  return 0;
}


// ===== 00503980 libspdm_get_encap_response_key_update =====

undefined8
libspdm_get_encap_response_key_update
          (long param_1,long param_2,char *param_3,ulong *param_4,char *param_5)

{
  long lVar1;
  undefined4 uVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  undefined8 uVar9;
  undefined1 local_3c [12];
  
  bVar3 = libspdm_get_connection_version();
  if (bVar3 < 0x11) {
    uVar7 = 0xe9;
    uVar9 = 7;
  }
  else {
    cVar5 = *param_3;
    cVar4 = libspdm_get_connection_version(param_1);
    if (cVar5 != cVar4) {
      uVar7 = 0;
      uVar9 = 0x41;
      goto LAB_005039e2;
    }
    cVar5 = libspdm_is_capabilities_flag_supported(param_1,1,0x4000,0x4000);
    if (cVar5 == '\0') {
      uVar7 = 0xe9;
      uVar9 = 7;
      goto LAB_005039e2;
    }
    if (*(char *)(param_1 + 0x8c) != '\0') {
      uVar2 = *(undefined4 *)(param_1 + 0x88);
      lVar8 = libspdm_get_session_info_via_session_id(param_1,uVar2);
      if (((lVar8 != 0) &&
          (iVar6 = libspdm_secured_message_get_session_state(*(undefined8 *)(lVar8 + 0x1f0)),
          iVar6 == 2)) && (param_2 == 4)) {
        lVar1 = lVar8 + 0x1e8;
        libspdm_zero_mem(local_3c,4);
        if (param_3[2] == '\x01') {
          cVar5 = libspdm_consttime_is_mem_equal(lVar1,local_3c,4);
          if (cVar5 == '\0') goto LAB_00503a9b;
          libspdm_debug_print(0x40,"libspdm_create_update_session_data_key[%x] Responder\n",uVar2);
          cVar5 = libspdm_create_update_session_data_key(*(undefined8 *)(lVar8 + 0x1f0),1);
          libspdm_copy_mem(lVar1,4,param_3,4);
        }
        else {
          if ((param_3[2] != '\x03') || (*(char *)(lVar8 + 0x1ea) != '\x01')) goto LAB_00503a9b;
          libspdm_debug_print(0x40,"libspdm_activate_update_session_data_key[%x] Responder new\n",
                              uVar2);
          cVar5 = libspdm_activate_update_session_data_key(*(undefined8 *)(lVar8 + 0x1f0),1,1);
          libspdm_zero_mem(lVar1,4);
        }
        if (cVar5 != '\0') {
          libspdm_reset_message_buffer_via_request_code(param_1,lVar8,param_3[1]);
          if (*param_4 < 4) {
            libspdm_debug_assert
                      ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_encap_key_update.c"
                       ,0x8c,"*response_size >= sizeof(spdm_key_update_response_t)");
          }
          *param_4 = 4;
          libspdm_zero_mem(param_5,4);
          cVar5 = *param_3;
          param_5[1] = 'i';
          *param_5 = cVar5;
          param_5[2] = param_3[2];
          param_5[3] = param_3[3];
          return 0;
        }
LAB_00503a9b:
        uVar7 = libspdm_generate_encap_error_response(param_1,1,0,param_4,param_5);
        return uVar7;
      }
    }
    uVar7 = 0;
    uVar9 = 1;
  }
LAB_005039e2:
  uVar7 = libspdm_generate_encap_error_response(param_1,uVar9,uVar7,param_4,param_5);
  return uVar7;
}


// ===== 00503c40 libspdm_encapsulated_request =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong libspdm_encapsulated_request(long param_1,undefined4 *param_2,byte param_3,byte *param_4)

{
  undefined1 *puVar1;
  byte *pbVar2;
  char cVar3;
  undefined1 uVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  undefined4 uVar8;
  long lVar9;
  ulong uVar10;
  code *pcVar11;
  ulong uVar12;
  byte *pbVar13;
  long local_78;
  ulong local_70;
  byte *local_60;
  ulong local_58;
  long local_50;
  byte *local_48;
  ulong local_40 [2];
  
  cVar3 = libspdm_is_encap_supported();
  if (cVar3 == '\0') {
    return 0x80010002;
  }
  if (param_2 == (undefined4 *)0x0) {
    if (param_3 == 0) {
      libspdm_reset_message_mut_b(param_1);
      libspdm_reset_message_mut_c(param_1);
      *(undefined1 *)(param_1 + 0x8c) = 0;
      *(undefined4 *)(param_1 + 0x88) = 0;
    }
    else {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_encap_request.c"
                 ,0xa0,"mut_auth_requested == 0");
      libspdm_reset_message_mut_b(param_1);
      libspdm_reset_message_mut_c(param_1);
      *(undefined1 *)(param_1 + 0x8c) = 0;
      *(undefined4 *)(param_1 + 0x88) = 0;
      if (param_3 == 4) goto LAB_00503cd5;
    }
  }
  else {
    lVar9 = libspdm_get_session_info_via_session_id(param_1,*param_2);
    if (lVar9 == 0) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_encap_request.c"
                 ,0x97,"false");
      return 0x80010003;
    }
    if ((param_3 & 0xfd) != 0) {
      if (param_3 == 4) {
        libspdm_reset_message_mut_b(param_1);
        libspdm_reset_message_mut_c(param_1);
        *(undefined1 *)(param_1 + 0x8c) = 1;
        *(undefined4 *)(param_1 + 0x88) = *param_2;
LAB_00503cd5:
        puVar1 = *(undefined1 **)(param_1 + 0x48);
        uVar4 = libspdm_get_connection_version(param_1);
        bVar6 = 0;
        *puVar1 = uVar4;
        *(undefined2 *)(puVar1 + 1) = 0x81;
        puVar1[3] = 0;
        local_78 = *(long *)(param_1 + 0x48);
        *(undefined8 *)(param_1 + 0x50) = 4;
        local_70 = 4;
        goto LAB_00503d18;
      }
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_encap_request.c"
                 ,0x9a,
                 "(mut_auth_requested == 0) || (mut_auth_requested == SPDM_KEY_EXCHANGE_RESPONSE_MUT_AUTH_REQUESTED_WITH_ENCAP_REQUEST) || (mut_auth_requested == SPDM_KEY_EXCHANGE_RESPONSE_MUT_AUTH_REQUESTED_WITH_GET_DIGESTS)"
                );
    }
    libspdm_reset_message_mut_b(param_1);
    libspdm_reset_message_mut_c(param_1);
    *(undefined1 *)(param_1 + 0x8c) = 1;
    *(undefined4 *)(param_1 + 0x88) = *param_2;
  }
  uVar12 = (ulong)*(uint *)(param_1 + 0x11c);
  uVar10 = libspdm_acquire_sender_buffer(param_1,local_40,&local_48);
  if (((uint)(uVar10 >> 0x1c) & 0xf) == 8) {
    return uVar10;
  }
  if (local_40[0] < *(uint *)(param_1 + 0x120) + uVar12) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_encap_request.c",
               0xc9,
               "message_size >= transport_header_size + spdm_context->local_context.capability.transport_tail_size"
              );
  }
  *(undefined1 *)(param_1 + 0xb30) = 1;
  pbVar13 = local_48 + uVar12;
  bVar6 = libspdm_get_connection_version(param_1);
  *pbVar13 = bVar6;
  pbVar13[1] = 0xea;
  pbVar13[2] = 0;
  pbVar13[3] = 0;
  libspdm_reset_message_buffer_via_request_code(param_1,0,0xea);
  uVar10 = libspdm_send_spdm_request(param_1,param_2,4,pbVar13);
  uVar7 = (uint)uVar10;
  if (((uint)(uVar10 >> 0x1c) & 0xf) == 8) {
LAB_00504318:
    libspdm_release_sender_buffer(param_1);
    return (ulong)uVar7;
  }
  libspdm_release_sender_buffer(param_1);
  pbVar13 = *(byte **)(param_1 + 0x48);
  uVar10 = libspdm_acquire_receiver_buffer(param_1,local_40,&local_48);
  if (((uint)(uVar10 >> 0x1c) & 0xf) == 8) {
    return uVar10;
  }
  if (local_40[0] < uVar12) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_encap_request.c",
               0xeb,"message_size >= transport_header_size");
  }
  local_58 = local_40[0];
  local_60 = local_48;
  uVar10 = libspdm_receive_spdm_response(param_1,param_2,&local_58,&local_60);
  pbVar2 = local_60;
  uVar7 = (uint)uVar10;
  if (((uint)(uVar10 >> 0x1c) & 0xf) == 8) {
LAB_005043c0:
    libspdm_release_receiver_buffer(param_1);
    return (ulong)uVar7;
  }
  if ((local_60[1] != 0x6a) || (*local_60 != *pbVar13)) {
LAB_00504192:
    libspdm_release_receiver_buffer(param_1);
    return 0x80010005;
  }
  if (local_58 < 4) {
LAB_00503f0b:
    libspdm_release_receiver_buffer(param_1);
    return 0x80010006;
  }
  libspdm_append_msg_log(param_1,local_60);
  if (local_58 == 4) {
LAB_005042ae:
    libspdm_release_receiver_buffer(param_1);
    return 0;
  }
  bVar6 = pbVar2[2];
  local_70 = local_58 - 4;
  uVar8 = libspdm_get_scratch_buffer_last_spdm_request_capacity(param_1);
  libspdm_copy_mem(*(undefined8 *)(param_1 + 0x48),uVar8,pbVar2 + 4,local_70);
  *(ulong *)(param_1 + 0x50) = local_70;
  local_78 = *(long *)(param_1 + 0x48);
  libspdm_release_receiver_buffer(param_1);
LAB_00503d18:
  do {
    uVar12 = (ulong)*(uint *)(param_1 + 0x11c);
    uVar10 = libspdm_acquire_sender_buffer(param_1,local_40,&local_48);
    if (((uint)(uVar10 >> 0x1c) & 0xf) == 8) {
      return uVar10;
    }
    uVar10 = (ulong)*(uint *)(param_1 + 0x120);
    if (local_40[0] < uVar10 + uVar12) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_encap_request.c"
                 ,0x12a,
                 "message_size >= transport_header_size + spdm_context->local_context.capability.transport_tail_size"
                );
      uVar10 = (ulong)*(uint *)(param_1 + 0x120);
    }
    *(undefined1 *)(param_1 + 0xb30) = 1;
    pbVar13 = local_48 + uVar12;
    lVar9 = local_40[0] + (-4 - uVar12);
    bVar5 = libspdm_get_connection_version(param_1);
    *pbVar13 = bVar5;
    local_50 = lVar9 - uVar10;
    pbVar13[1] = 0xeb;
    pbVar13[2] = bVar6;
    pbVar13[3] = 0;
    cVar3 = *(char *)(local_78 + 1);
    if (local_70 < 4) {
      uVar10 = libspdm_generate_encap_error_response(param_1,7,cVar3,&local_50,pbVar13 + 4);
    }
    else {
      if (cVar3 == -0x7f) {
        pcVar11 = libspdm_get_encap_response_digest;
      }
      else if (cVar3 == -0x7e) {
        pcVar11 = libspdm_get_encap_response_certificate;
      }
      else if (cVar3 == -0x17) {
        pcVar11 = libspdm_get_encap_response_key_update;
      }
      else {
        pcVar11 = *(code **)(param_1 + 0xa0);
        if (pcVar11 == (code *)0x0) {
          uVar10 = libspdm_generate_encap_error_response(param_1,4,0,&local_50,pbVar13 + 4);
          goto LAB_00503e16;
        }
      }
      uVar10 = (*pcVar11)(param_1,local_70,local_78,&local_50);
    }
LAB_00503e16:
    uVar7 = (uint)uVar10;
    if (((uint)(uVar10 >> 0x1c) & 0xf) == 8) goto LAB_00504318;
    uVar10 = libspdm_send_spdm_request(param_1,param_2,local_50 + 4,pbVar13);
    uVar7 = (uint)uVar10;
    if (((uint)(uVar10 >> 0x1c) & 0xf) == 8) goto LAB_00504318;
    libspdm_release_sender_buffer(param_1);
    pbVar13 = *(byte **)(param_1 + 0x48);
    uVar10 = libspdm_acquire_receiver_buffer(param_1,local_40,&local_48);
    if (((uint)(uVar10 >> 0x1c) & 0xf) == 8) {
      return uVar10;
    }
    if (local_40[0] < uVar12) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_encap_request.c"
                 ,0x158,"message_size >= transport_header_size");
    }
    local_58 = local_40[0];
    local_60 = local_48;
    uVar10 = libspdm_receive_spdm_response(param_1,param_2,&local_58,&local_60);
    pbVar2 = local_60;
    uVar7 = (uint)uVar10;
    if (((uint)(uVar10 >> 0x1c) & 0xf) == 8) goto LAB_005043c0;
    if ((local_60[1] != 0x6b) || (*local_60 != *pbVar13)) goto LAB_00504192;
    if (*local_60 < 0x12) {
      if (local_58 < 4) goto LAB_00503f0b;
      uVar10 = 4;
    }
    else {
      if (local_58 < 8) goto LAB_00503f0b;
      if (local_60[4] != pbVar13[2]) goto LAB_00504192;
      uVar10 = 8;
    }
    bVar6 = local_60[3];
    if (bVar6 != 1) {
      if (bVar6 == 2) {
        if (local_58 < (ulong)(uVar10 != 4) * 4 + 5) goto LAB_00503f0b;
        uVar12 = local_58;
        if ((param_4 != (byte *)0x0) && (*param_4 == 0)) {
          bVar6 = local_60[uVar10];
          *param_4 = bVar6;
          if ((7 < bVar6) ||
             (((0x12 < *local_60 && (*(char *)(param_1 + 0x64a) != '\0')) &&
              ((*(byte *)(param_1 + 0x1e2 + (ulong)bVar6 * 2) & 1) == 0)))) goto LAB_00504192;
        }
      }
      else {
        if (bVar6 != 0) goto LAB_00504192;
        uVar12 = uVar10;
        if (uVar10 != local_58) goto LAB_00503f0b;
      }
      libspdm_append_msg_log(param_1,local_60,uVar12);
      goto LAB_005042ae;
    }
    bVar6 = local_60[2];
    libspdm_append_msg_log(param_1,local_60);
    local_70 = local_58 - uVar10;
    uVar8 = libspdm_get_scratch_buffer_last_spdm_request_capacity(param_1);
    libspdm_copy_mem(*(undefined8 *)(param_1 + 0x48),uVar8,pbVar2 + uVar10,local_70);
    *(ulong *)(param_1 + 0x50) = local_70;
    local_78 = *(long *)(param_1 + 0x48);
    libspdm_release_receiver_buffer(param_1);
  } while( true );
}


// ===== 00504460 libspdm_verify_finish_rsp_hmac =====

undefined4
libspdm_verify_finish_rsp_hmac(long param_1,undefined8 param_2,undefined8 param_3,ulong param_4)

{
  uint uVar1;
  undefined4 uVar2;
  ulong local_60;
  undefined1 local_58 [48];
  
  uVar1 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
  local_60 = (ulong)uVar1;
  if (local_60 != param_4) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_finish.c",0x2d,
               "hash_size == hmac_data_size");
  }
  uVar2 = libspdm_calculate_th_hmac_for_finish_rsp(param_1,param_2,&local_60,local_58);
  if ((char)uVar2 == '\0') {
    return uVar2;
  }
  libspdm_debug_print(0x40,"th_curr hmac - ");
  libspdm_internal_dump_data(local_58,local_60);
  libspdm_debug_print(0x40,&DAT_00da8742);
  uVar2 = libspdm_consttime_is_mem_equal(local_58,param_3,local_60);
  if ((char)uVar2 != '\0') {
    libspdm_debug_print(0x40,"!!! verify_finish_rsp_hmac - PASS !!!\n");
    return uVar2;
  }
  libspdm_debug_print(0x40,"!!! verify_finish_rsp_hmac - FAIL !!!\n");
  return uVar2;
}


// ===== 00504570 libspdm_generate_finish_req_hmac =====

undefined4 libspdm_generate_finish_req_hmac(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  ulong local_50;
  undefined1 local_48 [48];
  
  uVar1 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
  local_50 = (ulong)uVar1;
  uVar2 = libspdm_calculate_th_hmac_for_finish_req(param_1,param_2,&local_50,local_48);
  if ((char)uVar2 != '\0') {
    libspdm_debug_print(0x40,"th_curr hmac - ");
    libspdm_internal_dump_data(local_48,local_50);
    libspdm_debug_print(0x40,&DAT_00da8742);
    libspdm_copy_mem(param_3,local_50,local_48,local_50);
  }
  return uVar2;
}


// ===== 00504610 libspdm_generate_finish_req_signature =====

uint libspdm_generate_finish_req_signature(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  ulong local_58;
  ulong local_50;
  undefined1 local_48 [48];
  
  uVar1 = libspdm_get_req_asym_signature_size(*(undefined2 *)(param_1 + 0x284));
  local_58 = (ulong)uVar1;
  uVar1 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
  local_50 = (ulong)uVar1;
  uVar1 = libspdm_calculate_th_hash_for_finish(param_1,param_2,&local_50,local_48);
  if ((char)uVar1 != '\0') {
    libspdm_debug_print(0x40,"th_curr hash - ");
    libspdm_internal_dump_data(local_48,local_50);
    libspdm_debug_print(0x40,&DAT_00da8742);
    uVar1 = libspdm_requester_data_sign
                      (param_1,*(undefined2 *)(param_1 + 0x23c),0xe5,
                       *(undefined2 *)(param_1 + 0x284),*(undefined4 *)(param_1 + 0x27c),1,local_48,
                       local_50,param_3,&local_58);
    if ((char)uVar1 != '\0') {
      libspdm_debug_print(0x40,"signature - ");
      libspdm_internal_dump_data(param_3,local_58);
      libspdm_debug_print(0x40,&DAT_00da8742);
      return uVar1 & 0xff;
    }
  }
  return uVar1;
}


// ===== 00504740 libspdm_send_receive_finish =====

uint libspdm_send_receive_finish(long param_1,undefined4 param_2,byte param_3)

{
  uint uVar1;
  undefined8 uVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  ulong uVar8;
  char *pcVar9;
  long lVar10;
  ulong uVar11;
  ulong uVar12;
  ulong local_d0;
  ulong local_c8;
  char *local_c0;
  undefined4 local_8c;
  char *local_88;
  ulong local_80;
  char *local_78;
  ulong local_70;
  undefined1 local_68 [56];
  
  uVar2 = *(undefined8 *)(param_1 + 0xb28);
  *(undefined1 *)(param_1 + 0xb30) = 1;
  uVar11 = (ulong)*(byte *)(param_1 + 0xb25);
  do {
    local_8c = param_2;
    bVar3 = libspdm_get_connection_version(param_1);
    if (bVar3 < 0x11) {
      return 0x80010002;
    }
    lVar7 = libspdm_get_session_info_via_session_id(param_1,local_8c);
    if (lVar7 == 0) goto LAB_00504c90;
    cVar4 = libspdm_is_capabilities_flag_supported(param_1,1,0x200,0x200);
    if (cVar4 == '\0') {
      uVar6 = 0x80010002;
      goto LAB_00504c96;
    }
    if ((*(uint *)(param_1 + 0x238) < 3) ||
       (iVar5 = libspdm_secured_message_get_session_state(*(undefined8 *)(lVar7 + 0x1f0)),
       iVar5 != 1)) {
      uVar6 = 0x80010003;
      goto LAB_00504c96;
    }
    if (*(char *)(lVar7 + 5) == '\0') {
      if (param_3 != 0) {
LAB_00504c90:
        uVar6 = 0x80010001;
        goto LAB_00504c96;
      }
    }
    else if ((byte)(param_3 - 8) < 0xf7) goto LAB_00504c90;
    uVar1 = *(uint *)(param_1 + 0x11c);
    uVar6 = libspdm_acquire_sender_buffer(param_1,&local_70,&local_78);
    if (uVar6 >> 0x1c != 8) {
      uVar8 = (ulong)uVar1;
      uVar12 = (ulong)*(uint *)(param_1 + 0x120);
      if (local_70 < uVar8 + uVar12) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_finish.c",
                   0x199,
                   "message_size >= transport_header_size + spdm_context->local_context.capability.transport_tail_size"
                  );
        uVar12 = (ulong)*(uint *)(param_1 + 0x120);
      }
      pcVar9 = local_78 + uVar8;
      uVar12 = (local_70 - uVar8) - uVar12;
      if (uVar12 < 4) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_finish.c",
                   0x19f,"spdm_request_size >= sizeof(spdm_request->header)");
      }
      cVar4 = libspdm_get_connection_version(param_1);
      lVar10 = 4;
      local_c8 = 0;
      *pcVar9 = cVar4;
      pcVar9[1] = -0x1b;
      pcVar9[2] = '\0';
      pcVar9[3] = '\0';
      if (*(char *)(lVar7 + 5) != '\0') {
        pcVar9[2] = '\x01';
        pcVar9[3] = param_3;
        uVar6 = libspdm_get_req_asym_signature_size(*(undefined2 *)(param_1 + 0x284));
        local_c8 = (ulong)uVar6;
        lVar10 = local_c8 + 4;
      }
      *(byte *)(param_1 + 0x648) = param_3;
      if ((*(char *)(lVar7 + 5) != '\0') && (param_3 != 0xff)) {
        *(undefined8 *)(param_1 + 0x638) = *(undefined8 *)(param_1 + 0x150 + (ulong)param_3 * 8);
        *(undefined8 *)(param_1 + 0x640) = *(undefined8 *)(param_1 + 400 + (ulong)param_3 * 8);
      }
      uVar6 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
      local_d0 = (ulong)uVar6;
      if (uVar12 < local_d0 + lVar10) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_finish.c",
                   0x1b8,
                   "spdm_request_size >= sizeof(spdm_finish_request_t) + signature_size + hmac_size"
                  );
      }
      uVar6 = libspdm_append_message_f(param_1,lVar7,1,pcVar9,4);
      if (uVar6 >> 0x1c != 8) {
        local_c0 = pcVar9 + 4;
        if (*(char *)(lVar7 + 5) == '\0') {
LAB_005049a5:
          cVar4 = libspdm_generate_finish_req_hmac(param_1,lVar7,local_c0);
          if (cVar4 != '\0') {
            uVar6 = libspdm_append_message_f(param_1,lVar7,1,local_c0,local_d0);
            if ((uVar6 >> 0x1c == 8) ||
               (uVar6 = libspdm_send_spdm_request(param_1,&local_8c,local_d0 + lVar10,pcVar9),
               uVar6 >> 0x1c == 8)) goto LAB_00504cd0;
            libspdm_reset_message_buffer_via_request_code(param_1,lVar7,0xe5);
            libspdm_release_sender_buffer(param_1);
            pcVar9 = *(char **)(param_1 + 0x48);
            uVar6 = libspdm_acquire_receiver_buffer(param_1,&local_70,&local_78);
            if (uVar6 >> 0x1c == 8) goto LAB_00504cd8;
            if (local_70 < uVar8) {
              libspdm_debug_assert
                        ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_finish.c"
                         ,0x1f2,"message_size >= transport_header_size");
            }
            local_80 = local_70;
            local_88 = local_78;
            uVar6 = libspdm_receive_spdm_response(param_1,&local_8c,&local_80,&local_88);
            if (uVar6 >> 0x1c == 8) goto LAB_00504dde;
            if (local_80 < 4) {
LAB_00504deb:
              uVar6 = 0x80010006;
            }
            else if (*local_88 == *pcVar9) {
              if (local_88[1] == '\x7f') {
                if (local_88[2] == '\x06') {
                  uVar6 = 0x8001000f;
                }
                else {
                  if (local_88[2] != 'B') {
                    libspdm_reset_message_f(param_1,lVar7);
                  }
                  uVar6 = libspdm_handle_error_response_main
                                    (param_1,&local_8c,&local_80,&local_88,0xe5,0x65);
                  if (uVar6 >> 0x1c != 8) goto LAB_00504ad3;
                }
              }
              else {
                if (local_88[1] != 'e') goto LAB_00504dd8;
LAB_00504ad3:
                cVar4 = libspdm_is_capabilities_flag_supported(param_1,1,0x8000,0x8000);
                if (cVar4 == '\0') {
                  local_d0 = 0;
                  uVar8 = 4;
                }
                else {
                  uVar8 = local_d0 + 4;
                }
                if (local_80 < uVar8) goto LAB_00504deb;
                uVar6 = libspdm_append_message_f(param_1,lVar7,1,local_88,4);
                if (uVar6 >> 0x1c != 8) {
                  cVar4 = libspdm_is_capabilities_flag_supported(param_1,1,0x8000,0x8000);
                  if (cVar4 != '\0') {
                    libspdm_debug_print(0x40,"verify_data (0x%zx):\n",local_d0);
                    libspdm_internal_dump_hex(local_88 + 4,local_d0);
                    uVar6 = 0x80020001;
                    cVar4 = libspdm_verify_finish_rsp_hmac(param_1,lVar7,local_88 + 4,local_d0);
                    if ((cVar4 == '\0') ||
                       (uVar6 = libspdm_append_message_f(param_1,lVar7,1,local_88 + 4,local_d0),
                       uVar6 >> 0x1c == 8)) goto LAB_00504dde;
                  }
                  libspdm_debug_print(0x40,"libspdm_generate_session_data_key[%x]\n",local_8c);
                  cVar4 = libspdm_calculate_th2_hash(param_1,lVar7,1,local_68);
                  if ((cVar4 != '\0') &&
                     (cVar4 = libspdm_generate_session_data_key
                                        (*(undefined8 *)(lVar7 + 0x1f0),local_68), cVar4 != '\0')) {
                    libspdm_secured_message_set_session_state(*(undefined8 *)(lVar7 + 0x1f0),2);
                    libspdm_append_msg_log(param_1,local_88,local_80);
                    libspdm_release_receiver_buffer(param_1);
                    return 0;
                  }
                  uVar6 = 0x80020000;
                }
              }
            }
            else {
LAB_00504dd8:
              uVar6 = 0x80010005;
            }
LAB_00504dde:
            libspdm_release_receiver_buffer(param_1);
            goto LAB_00504cd8;
          }
        }
        else {
          cVar4 = libspdm_generate_finish_req_signature(param_1,lVar7,local_c0);
          if (cVar4 != '\0') {
            uVar6 = libspdm_append_message_f(param_1,lVar7,1,local_c0,local_c8);
            local_c0 = local_c0 + local_c8;
            if (uVar6 >> 0x1c == 8) goto LAB_00504cd0;
            goto LAB_005049a5;
          }
        }
        uVar6 = 0x80020000;
        libspdm_release_sender_buffer(param_1);
        goto LAB_00504c96;
      }
LAB_00504cd0:
      libspdm_release_sender_buffer(param_1);
    }
LAB_00504cd8:
    if (uVar6 != 0x80010008) {
LAB_00504c96:
      libspdm_free_session_id(param_1,local_8c);
      return uVar6;
    }
    libspdm_sleep(uVar2);
    if (uVar11 == 0) {
      return 0x80010008;
    }
    uVar11 = uVar11 - 1;
  } while( true );
}


// ===== 00504e90 libspdm_get_capabilities =====

uint libspdm_get_capabilities(long param_1)

{
  undefined8 uVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  byte bVar5;
  ulong uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  byte bVar10;
  uint uVar11;
  uint uVar12;
  ulong uVar13;
  ulong uVar14;
  undefined8 uVar15;
  byte bVar16;
  byte *pbVar17;
  byte local_70;
  byte *local_58;
  ulong local_50;
  byte *local_48;
  ulong local_40 [2];
  
  uVar1 = *(undefined8 *)(param_1 + 0xb28);
  *(undefined1 *)(param_1 + 0xb30) = 0;
  uVar6 = (ulong)*(byte *)(param_1 + 0xb25);
  do {
    if (*(int *)(param_1 + 0x238) != 1) {
      return 0x80010003;
    }
    libspdm_reset_message_buffer_via_request_code(param_1,0,0xe1);
    uVar13 = (ulong)*(uint *)(param_1 + 0x11c);
    uVar3 = libspdm_acquire_sender_buffer(param_1,local_40,&local_48);
    if (uVar3 >> 0x1c != 8) {
      uVar14 = (ulong)*(uint *)(param_1 + 0x120);
      if (local_40[0] < uVar13 + uVar14) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_capabilities.c"
                   ,0xdf,
                   "message_size >= transport_header_size + spdm_context->local_context.capability.transport_tail_size"
                  );
        uVar14 = (ulong)*(uint *)(param_1 + 0x120);
      }
      uVar14 = (local_40[0] - uVar13) - uVar14;
      pbVar17 = local_48 + uVar13;
      if (uVar14 < 4) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_capabilities.c"
                   ,0xe5,"spdm_request_size >= sizeof(spdm_request->header)");
        libspdm_zero_mem(pbVar17);
        bVar2 = libspdm_get_connection_version(param_1);
        *pbVar17 = bVar2;
        if (bVar2 < 0x12) {
          if (bVar2 != 0x11) goto LAB_00505286;
LAB_005053ae:
          uVar15 = 0xc;
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_capabilities.c"
                     ,0xec,
                     "spdm_request_size >= sizeof(spdm_get_capabilities_request_t) - sizeof(spdm_request->data_transfer_size) - sizeof(spdm_request->max_spdm_msg_size)"
                    );
          bVar2 = *pbVar17;
        }
        else {
LAB_005052e6:
          uVar15 = 0x14;
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_capabilities.c"
                     ,0xe9,"spdm_request_size >= sizeof(spdm_get_capabilities_request_t)");
          bVar2 = *pbVar17;
        }
LAB_00505290:
        pbVar17[3] = 0;
        pbVar17[1] = 0xe1;
        pbVar17[2] = 0;
        if (0x10 < bVar2) goto LAB_00504f9b;
      }
      else {
        libspdm_zero_mem(pbVar17);
        bVar2 = libspdm_get_connection_version(param_1);
        *pbVar17 = bVar2;
        if (bVar2 < 0x12) {
          if (bVar2 == 0x11) {
            if (uVar14 < 0xc) goto LAB_005053ae;
            bVar2 = 0x11;
            uVar15 = 0xc;
          }
          else {
LAB_00505286:
            bVar2 = *pbVar17;
            uVar15 = 4;
          }
          goto LAB_00505290;
        }
        if (uVar14 < 0x14) goto LAB_005052e6;
        pbVar17[3] = 0;
        uVar15 = 0x14;
        pbVar17[1] = 0xe1;
        pbVar17[2] = 0;
LAB_00504f9b:
        pbVar17[5] = *(byte *)(param_1 + 0xf8);
        uVar4 = libspdm_mask_capability_flags(param_1,1,*(undefined4 *)(param_1 + 0x10c));
        *(undefined4 *)(pbVar17 + 8) = uVar4;
        if (0x11 < *pbVar17) {
          *(undefined4 *)(pbVar17 + 0xc) = *(undefined4 *)(param_1 + 0x110);
          *(undefined4 *)(pbVar17 + 0x10) = *(undefined4 *)(param_1 + 0x118);
        }
      }
      uVar3 = libspdm_send_spdm_request(param_1,0,uVar15,pbVar17);
      if (uVar3 >> 0x1c == 8) {
        libspdm_release_sender_buffer(param_1);
      }
      else {
        libspdm_release_sender_buffer(param_1);
        pbVar17 = *(byte **)(param_1 + 0x48);
        uVar3 = libspdm_acquire_receiver_buffer(param_1,local_40,&local_48);
        if (uVar3 >> 0x1c != 8) {
          if (local_40[0] < uVar13) {
            libspdm_debug_assert
                      ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_capabilities.c"
                       ,0x113,"message_size >= transport_header_size");
          }
          local_50 = local_40[0];
          local_58 = local_48;
          uVar3 = libspdm_receive_spdm_response(param_1,0,&local_50,&local_58);
          if (uVar3 >> 0x1c != 8) {
            if (local_50 < 4) goto LAB_00505390;
            bVar2 = *local_58;
            if (bVar2 == *pbVar17) {
              if (local_58[1] == 0x7f) {
                uVar3 = libspdm_handle_simple_error_response(param_1);
                if (uVar3 >> 0x1c == 8) goto LAB_00505246;
                bVar2 = *local_58;
              }
              else if (local_58[1] != 0x61) goto LAB_00505240;
              if (bVar2 < 0x12) {
                if (local_50 < 0xc) {
LAB_00505390:
                  uVar3 = 0x80010006;
                  libspdm_release_receiver_buffer(param_1);
                  goto LAB_0050524e;
                }
              }
              else if (local_50 < 0x14) goto LAB_00505390;
              local_50 = (-(ulong)(*pbVar17 < 0x12) & 0xfffffffffffffff8) + 0x14;
              uVar3 = *(uint *)(local_58 + 8);
              uVar7 = uVar3 >> 3;
              bVar2 = (byte)uVar7 & 3;
              if ((bVar2 != 3) && (((uVar7 & 3) != 0 || ((uVar3 & 0x20) == 0)))) {
                bVar5 = *local_58;
                uVar8 = uVar3 >> 1;
                uVar12 = uVar3 >> 2;
                uVar9 = uVar8 & 1;
                bVar16 = (byte)uVar8 & 1;
                if (bVar5 == 0x10) {
                  if ((uVar7 & 2) == 0) {
                    if (bVar16 == ((byte)uVar12 & 1)) goto LAB_00505235;
                  }
                  else {
joined_r0x005054dd:
                    if (uVar9 != 0) goto LAB_00505235;
                  }
                }
                else if (bVar5 < 0x11) {
LAB_00505235:
                  if (local_58[5] < 0x20) {
                    uVar3 = libspdm_append_message_a(param_1,pbVar17,uVar15);
                    if ((uVar3 >> 0x1c != 8) &&
                       (uVar3 = libspdm_append_message_a(param_1,local_58,local_50),
                       uVar3 >> 0x1c != 8)) {
                      *(byte *)(param_1 + 0x240) = local_58[5];
                      uVar4 = libspdm_mask_capability_flags(param_1,0,*(undefined4 *)(local_58 + 8))
                      ;
                      *(undefined4 *)(param_1 + 0x254) = uVar4;
                      if (*local_58 < 0x12) {
                        *(undefined4 *)(param_1 + 600) = 0;
                        uVar4 = 0;
                      }
                      else {
                        *(undefined4 *)(param_1 + 600) = *(undefined4 *)(local_58 + 0xc);
                        uVar4 = *(undefined4 *)(local_58 + 0x10);
                      }
                      *(undefined4 *)(param_1 + 0x260) = uVar4;
                      uVar3 = 0;
                      *(undefined4 *)(param_1 + 0x238) = 2;
                      libspdm_append_msg_log(param_1,local_58,local_50);
                    }
                    goto LAB_00505246;
                  }
                }
                else {
                  uVar9 = uVar3 >> 10;
                  if (((byte)uVar9 & 3) != 3) {
                    uVar11 = uVar3 >> 9;
                    local_70 = (byte)(uVar3 >> 0xf);
                    if ((uVar11 & 1) == 0 && (uVar9 & 3) == 0) {
                      if ((((uVar3 >> 6 | (uint)(byte)((byte)(uVar3 >> 7) | local_70) | uVar3 >> 0xd
                            | uVar3 >> 0xe) & 1) == 0) &&
                         (((uVar3 & 0x2000000) == 0 || (bVar5 != 0x13)))) goto LAB_0050517e;
                    }
                    else if (((uVar3 >> 7 & 1) != 0) &&
                            (((local_70 & (uVar9 & 3) != 0) == 0 || ((uVar11 & 1) != 0)))) {
LAB_0050517e:
                      uVar9 = uVar3 >> 8;
                      bVar10 = (byte)(uVar3 >> 0x16) & 3;
                      if (((uVar3 >> 0x10 | uVar8) & 1) == 0) {
                        if ((((((uVar11 & 0xff | uVar12) & 1) == 0) && (bVar2 != 2)) &&
                            ((uVar9 & 1) == 0)) && ((bVar5 != 0x13 || (bVar10 != 2))))
                        goto LAB_005051d3;
                      }
                      else if ((bVar16 & (byte)(uVar3 >> 0x10) & 1) == 0) {
                        if (((uVar11 & 0xff | uVar12) & 1) == 0) {
                          if (((uVar7 & 2) == 0) || ((uVar9 & 1) != 0)) goto LAB_00505240;
LAB_005051d3:
                          if (bVar5 == 0x11) goto LAB_00505235;
                        }
                        else {
                          if ((uVar9 & 1) == 0) goto LAB_005051d3;
                          if (bVar5 == 0x11) {
                            uVar9 = uVar3 & 0x1000;
                            goto joined_r0x005054dd;
                          }
                        }
                        if (((uVar8 & 1) != 0) || (((uVar3 >> 0x12 | uVar3 >> 0x13) & 1) == 0)) {
                          bVar2 = (byte)(uVar3 >> 0x13) & 1 ^ 1;
                          if (((bVar2 & (byte)(uVar3 >> 0x14)) == 0) &&
                             (((bVar2 & (byte)(uVar3 >> 0x15)) == 0 || ((uVar3 >> 0x14 & 1) != 0))))
                          {
                            if (bVar5 == 0x13) {
                              bVar2 = (byte)(uVar3 >> 0x18);
                              bVar5 = bVar2 >> 2 & 3;
                              if ((((bVar10 == 3) || (bVar5 == 3)) ||
                                  ((bVar16 = bVar2 >> 4 & 1, bVar5 != 0 && (bVar16 == 0)))) ||
                                 (((uVar3 & 0x10000) != 0 &&
                                  ((bVar2 >> 5 & 1) != 0 || (bVar5 != 0 || bVar16 != 0)))))
                              goto LAB_00505240;
                            }
                            uVar7 = *(uint *)(local_58 + 0xc);
                            if ((0x29 < uVar7) &&
                               ((uVar7 <= *(uint *)(local_58 + 0x10) &&
                                (((uVar3 & 0x20000) != 0 || (uVar7 == *(uint *)(local_58 + 0x10)))))
                               )) goto LAB_00505235;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
LAB_00505240:
            uVar3 = 0x80010005;
          }
LAB_00505246:
          libspdm_release_receiver_buffer(param_1);
        }
      }
    }
LAB_0050524e:
    if (uVar3 != 0x80010008) {
      return uVar3;
    }
    libspdm_sleep(uVar1);
    if (uVar6 == 0) {
      return 0x80010008;
    }
    uVar6 = uVar6 - 1;
  } while( true );
}


// ===== 00505600 libspdm_try_get_certificate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint libspdm_try_get_certificate
               (long param_1,undefined4 *param_2,byte param_3,ushort param_4,ulong *param_5,
               long param_6,undefined8 param_7,undefined8 param_8)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ulong uVar4;
  char cVar5;
  byte bVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  long lVar11;
  ulong uVar12;
  int iVar13;
  ulong uVar14;
  ulong uVar15;
  byte *pbVar16;
  ulong uVar17;
  ushort local_7a;
  byte *local_58;
  ulong local_50;
  byte *local_48;
  ulong local_40 [2];
  
  if (7 < param_3) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_certificate.c"
               ,0x5c,"slot_id < SPDM_MAX_SLOT_COUNT");
  }
  if (param_5 == (ulong *)0x0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_certificate.c"
               ,0x5d,"cert_chain_size != NULL");
    uVar4 = _DAT_00000000;
  }
  else {
    uVar4 = *param_5;
  }
  if (uVar4 == 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_certificate.c"
               ,0x5e,"*cert_chain_size > 0");
  }
  if (param_6 == 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_certificate.c"
               ,0x5f,"cert_chain != NULL");
  }
  cVar5 = libspdm_is_capabilities_flag_supported(param_1,1,0,2);
  if (cVar5 == '\0') {
    return 0x80010002;
  }
  if (*(uint *)(param_1 + 0x238) < 3) {
    return 0x80010003;
  }
  if (param_2 == (undefined4 *)0x0) {
    lVar11 = 0;
  }
  else {
    lVar11 = libspdm_get_session_info_via_session_id(param_1,*param_2);
    if (lVar11 == 0) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_certificate.c"
                 ,0x6f,"false");
      return 0x80010003;
    }
    iVar7 = libspdm_secured_message_get_session_state(*(undefined8 *)(lVar11 + 0x1f0));
    if (iVar7 != 2) {
      return 0x80010003;
    }
  }
  uVar9 = 0;
  libspdm_reset_message_buffer_via_request_code(param_1,lVar11,0x82);
  uVar15 = 0;
  cVar5 = libspdm_is_capabilities_flag_supported(param_1,1,0x20000,0x20000);
  uVar17 = (ulong)*(uint *)(param_1 + 0x11c);
  uVar4 = *param_5;
  local_7a = 0;
  do {
    uVar8 = libspdm_acquire_sender_buffer(param_1,local_40,&local_48);
    if (uVar8 >> 0x1c == 8) {
      return uVar8;
    }
    uVar12 = (ulong)*(uint *)(param_1 + 0x120);
    if (local_40[0] < uVar12 + uVar17) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_certificate.c"
                 ,0x8d,
                 "message_size >= transport_header_size + spdm_context->local_context.capability.transport_tail_size"
                );
      uVar12 = (ulong)*(uint *)(param_1 + 0x120);
    }
    pbVar16 = local_48 + uVar17;
    if ((local_40[0] - uVar17) - uVar12 < 8) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_certificate.c"
                 ,0x93,"spdm_request_size >= sizeof(spdm_get_certificate_request_t)");
    }
    bVar6 = libspdm_get_connection_version(param_1);
    pbVar16[1] = 0x82;
    *pbVar16 = bVar6;
    pbVar16[3] = 0;
    pbVar16[2] = param_3;
    *(short *)(pbVar16 + 4) = (short)uVar15;
    if (param_4 < (ushort)uVar9) {
      uVar9 = (uint)param_4;
    }
    if ((short)uVar15 == 0) {
      uVar9 = (uint)param_4;
    }
    *(short *)(pbVar16 + 6) = (short)uVar9;
    libspdm_debug_print(0x40,"request (offset 0x%x, size 0x%x):\n",uVar15 & 0xffff,uVar9);
    uVar9 = libspdm_send_spdm_request(param_1,param_2,8,pbVar16);
    if (uVar9 >> 0x1c == 8) {
      libspdm_release_sender_buffer(param_1);
      return 0x80040000;
    }
    libspdm_release_sender_buffer(param_1);
    pbVar16 = *(byte **)(param_1 + 0x48);
    uVar9 = libspdm_acquire_receiver_buffer(param_1,local_40,&local_48);
    if (uVar9 >> 0x1c == 8) {
      return uVar9;
    }
    if (local_40[0] < uVar17) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_certificate.c"
                 ,0xb2,"message_size >= transport_header_size");
    }
    local_50 = local_40[0];
    local_58 = local_48;
    uVar8 = libspdm_receive_spdm_response(param_1,param_2,&local_50,&local_58);
    if (uVar8 >> 0x1c == 8) {
      libspdm_release_receiver_buffer(param_1);
      return 0x80040001;
    }
    if (local_50 < 4) goto LAB_00505aa7;
    if (*local_58 != *pbVar16) goto LAB_00505aca;
    if (local_58[1] == 0x7f) {
      uVar8 = libspdm_handle_error_response_main(param_1,param_2,&local_50,&local_58,0x82,2);
      if (uVar8 >> 0x1c == 8) goto LAB_00505aa7;
    }
    else if (local_58[1] != 2) goto LAB_00505aca;
    if (local_50 < 8) goto LAB_00505aa7;
    uVar2 = *(ushort *)(local_58 + 4);
    uVar12 = (ulong)uVar2;
    if (((*(ushort *)(pbVar16 + 6) < uVar2) || (uVar2 == 0)) || ((local_58[2] & 0xf) != param_3))
    goto LAB_00505aca;
    if (0x12 < *pbVar16) {
      libspdm_debug_print(0x40,"cert_info - 0x%02x\n",local_58[3]);
      bVar6 = local_58[3] & 7;
      if (*(char *)(param_1 + 0x64b) == '\0') {
        if (bVar6 != 0) goto LAB_00505aca;
LAB_00505cd8:
        if (*(char *)(param_1 + 0x414 + (ulong)param_3) != '\0') goto LAB_00505aca;
      }
      else {
        if (((local_58[3] & 4) != 0) || ((param_3 == 0 && (bVar6 == 3)))) goto LAB_00505aca;
        if (bVar6 == 0) {
          if (*(short *)(local_58 + 4) != 0) goto LAB_00505aca;
          goto LAB_00505cd8;
        }
        bVar1 = *(byte *)(param_1 + 0x414 + (ulong)param_3);
        if (bVar1 != 0) {
          if (bVar1 != bVar6) goto LAB_00505aca;
          uVar12 = (ulong)*(ushort *)(local_58 + 4);
          goto LAB_005058a6;
        }
      }
      *(byte *)(param_1 + 0x414 + (ulong)param_3) = bVar6;
      uVar12 = (ulong)*(ushort *)(local_58 + 4);
    }
LAB_005058a6:
    uVar14 = uVar12 + 8;
    if (local_50 < uVar14) {
LAB_00505aa7:
      libspdm_release_receiver_buffer(param_1);
      return 0x80010006;
    }
    uVar2 = *(ushort *)(pbVar16 + 4);
    iVar7 = 0xffff - (uint)uVar2;
    iVar13 = (int)uVar12;
    if (iVar7 < iVar13) {
LAB_00505aca:
      libspdm_release_receiver_buffer(param_1);
      return 0x80010005;
    }
    uVar3 = *(ushort *)(local_58 + 6);
    uVar9 = (uint)uVar3;
    if (iVar7 - iVar13 < (int)uVar9) goto LAB_00505aca;
    if (uVar2 == 0) {
      local_7a = uVar3 + (short)uVar12;
      if (((cVar5 != '\0') && (*(short *)(pbVar16 + 6) == -1)) && (uVar3 != 0)) goto LAB_00505aca;
    }
    else if (iVar13 + (uint)uVar2 + (uint)uVar3 != (uint)local_7a) goto LAB_00505aca;
    local_50 = uVar14;
    if ((param_2 == (undefined4 *)0x0) &&
       ((uVar8 = libspdm_append_message_b(param_1,pbVar16,8), uVar8 >> 0x1c == 8 ||
        (uVar8 = libspdm_append_message_b(param_1,local_58,local_50), uVar8 >> 0x1c == 8)))) {
LAB_00505aa7:
      libspdm_release_receiver_buffer(param_1);
      return uVar8;
    }
    if (uVar4 < *(ushort *)(local_58 + 4) + uVar15) {
      libspdm_release_receiver_buffer(param_1);
      return 0x8001000c;
    }
    libspdm_debug_print(0x40,"Certificate (offset 0x%x, size 0x%x):\n",*(undefined2 *)(pbVar16 + 4))
    ;
    libspdm_internal_dump_hex(local_58 + 8,*(undefined2 *)(local_58 + 4));
    libspdm_copy_mem(param_6 + uVar15,uVar4 - uVar15,local_58 + 8,*(undefined2 *)(local_58 + 4));
    uVar15 = uVar15 + *(ushort *)(local_58 + 4);
    if (*(uint *)(param_1 + 0x238) < 5) {
      *(undefined4 *)(param_1 + 0x238) = 5;
    }
    libspdm_append_msg_log(param_1,local_58,local_50);
    libspdm_release_receiver_buffer(param_1);
    if (uVar3 == 0) {
      *param_5 = uVar15;
      if (0xffff < uVar15) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_certificate.c"
                   ,0x162,"*cert_chain_size <= SPDM_MAX_CERTIFICATE_CHAIN_SIZE");
      }
      if (*(code **)(param_1 + 0x228) == (code *)0x0) {
        cVar5 = libspdm_verify_peer_cert_chain_buffer_integrity(param_1,param_6,uVar15);
        if (cVar5 == '\0') {
          return 0x80020001;
        }
        cVar5 = libspdm_verify_peer_cert_chain_buffer_authority
                          (param_1,param_6,uVar15,param_7,param_8);
        if (cVar5 == '\0') {
          uVar8 = 0x40020003;
        }
      }
      else {
        cVar5 = (**(code **)(param_1 + 0x228))(param_1,param_3,uVar15,param_6,param_7,param_8);
        if (cVar5 == '\0') {
          return 0x80020001;
        }
      }
      *(byte *)(param_1 + 0x630) = param_3;
      lVar11 = (ulong)param_3 * 0x40;
      cVar5 = libspdm_hash_all(*(undefined4 *)(param_1 + 0x27c),param_6,uVar15,
                               param_1 + 0x430 + lVar11);
      if (cVar5 == '\0') {
        uVar8 = 0x80020000;
      }
      else {
        uVar10 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
        *(undefined4 *)(param_1 + 0x460 + lVar11) = uVar10;
        cVar5 = libspdm_get_leaf_cert_public_key_from_cert_chain
                          (*(undefined4 *)(param_1 + 0x27c),*(undefined4 *)(param_1 + 0x278),param_6
                           ,uVar15,param_1 + 0x468 + lVar11);
        if (cVar5 == '\0') {
          uVar8 = 0x80030000;
        }
        else if (uVar8 != 0x40020003) {
          uVar8 = 0;
        }
      }
      return uVar8;
    }
  } while( true );
}


// ===== 00505f00 libspdm_get_certificate =====

int libspdm_get_certificate
              (long param_1,undefined8 param_2,undefined1 param_3,undefined8 param_4,
              undefined8 param_5)

{
  undefined8 uVar1;
  int iVar2;
  ulong uVar3;
  
  uVar1 = *(undefined8 *)(param_1 + 0xb28);
  uVar3 = (ulong)*(byte *)(param_1 + 0xb25);
  *(undefined1 *)(param_1 + 0xb30) = 1;
  while( true ) {
    iVar2 = libspdm_try_get_certificate(param_1,param_2,param_3,0x1000,param_4,param_5,0);
    if (iVar2 != -0x7ffefff8) {
      return iVar2;
    }
    libspdm_sleep(uVar1);
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
  }
  return -0x7ffefff8;
}


// ===== 00505fa0 libspdm_verify_measurement_signature =====

undefined4
libspdm_verify_measurement_signature
          (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  byte bVar1;
  undefined4 uVar2;
  char cVar3;
  long local_68;
  undefined8 local_60;
  undefined1 local_58 [48];
  
  local_60 = 0x30;
  uVar2 = libspdm_calculate_l1l2_hash(param_1,param_2,&local_60,local_58);
  libspdm_reset_message_m(param_1,param_2);
  if ((char)uVar2 == '\0') {
    return uVar2;
  }
  bVar1 = *(byte *)(param_1 + 0x630);
  if (bVar1 < 8) {
    if (bVar1 != 0xf) goto LAB_005060b2;
  }
  else if (bVar1 != 0xf) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_measurements.c"
               ,0x2e,"(slot_id < SPDM_MAX_SLOT_COUNT) || (slot_id == 0xF)");
LAB_005060b2:
    local_68 = *(long *)(param_1 + 0x468 + (ulong)bVar1 * 0x40);
    if (local_68 == 0) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_measurements.c"
                 ,0x51,"context != NULL");
    }
    uVar2 = libspdm_asym_verify_hash_ex
                      (*(undefined2 *)(param_1 + 0x23c),0x60,*(undefined4 *)(param_1 + 0x278),
                       *(undefined4 *)(param_1 + 0x27c),local_68,local_58,local_60,param_3,param_4,
                       param_1 + 0xb90);
    cVar3 = (char)uVar2;
    goto joined_r0x00506105;
  }
  uVar2 = libspdm_asym_get_public_key_from_der
                    (*(undefined4 *)(param_1 + 0x278),*(undefined8 *)(param_1 + 0x218),
                     *(undefined8 *)(param_1 + 0x220),&local_68);
  if ((char)uVar2 == '\0') {
    return uVar2;
  }
  uVar2 = libspdm_asym_verify_hash_ex
                    (*(undefined2 *)(param_1 + 0x23c),0x60,*(undefined4 *)(param_1 + 0x278),
                     *(undefined4 *)(param_1 + 0x27c),local_68,local_58,local_60,param_3,param_4,
                     param_1 + 0xb90);
  libspdm_asym_free(*(undefined4 *)(param_1 + 0x278),local_68);
  cVar3 = (char)uVar2;
joined_r0x00506105:
  if (cVar3 == '\0') {
    libspdm_debug_print(0x80000000,"!!! verify_measurement_signature - FAIL !!!\n");
    return uVar2;
  }
  libspdm_debug_print(0x40,"!!! verify_measurement_signature - PASS !!!\n");
  return uVar2;
}


// ===== 00506180 libspdm_try_get_measurement =====

/* WARNING: Type propagation algorithm not settling */

ulong libspdm_try_get_measurement
                (long param_1,undefined4 *param_2,byte param_3,byte param_4,byte param_5,
                long param_6,byte *param_7,byte *param_8,uint *param_9,undefined8 param_10,
                long param_11,long param_12,long param_13,long param_14,ulong *param_15)

{
  byte bVar1;
  ulong uVar2;
  char cVar3;
  byte bVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  long lVar9;
  ulong uVar10;
  long lVar11;
  byte *pbVar12;
  ulong uVar13;
  byte bVar14;
  byte *pbVar15;
  byte *pbVar16;
  ulong local_88;
  long local_78;
  byte *local_58;
  ulong local_50;
  byte *local_48;
  ulong local_40 [2];
  
  if (param_5 < 8) {
    if (param_5 == 0xf) goto LAB_005061bb;
  }
  else if (param_5 == 0xf) {
LAB_005061bb:
    if (*(long *)(param_1 + 0x220) == 0) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_measurements.c"
                 ,0xb1,
                 "(slot_id_param != 0xf) || (spdm_context->local_context.peer_public_key_provision_size != 0)"
                );
    }
  }
  else {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_measurements.c"
               ,0xb0,"(slot_id_param < SPDM_MAX_SLOT_COUNT) || (slot_id_param == 0xF)");
  }
  cVar3 = libspdm_is_capabilities_flag_supported(param_1,1,0,0x18);
  if (cVar3 == '\0') {
    return 0x80010002;
  }
  if (*(char *)(param_1 + 0x128) == '\0') {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_measurements.c"
               ,0xbb,"spdm_context->local_context.algorithm.measurement_spec != 0");
  }
  if (*(uint *)(param_1 + 0x238) < 3) {
    return 0x80010003;
  }
  if (param_2 == (undefined4 *)0x0) {
    lVar9 = 0;
  }
  else {
    lVar9 = libspdm_get_session_info_via_session_id(param_1,*param_2);
    if (lVar9 == 0) {
      return 0x80010003;
    }
    iVar6 = libspdm_secured_message_get_session_state(*(undefined8 *)(lVar9 + 0x1f0));
    if (iVar6 != 2) {
      return 0x80010003;
    }
  }
  cVar3 = libspdm_is_capabilities_flag_supported(param_1,1,0,8);
  if (cVar3 == '\0') {
    if ((param_3 & 1) == 0) goto LAB_0050626d;
    uVar7 = libspdm_get_asym_signature_size(*(undefined4 *)(param_1 + 0x278));
    local_88 = (ulong)uVar7;
  }
  else {
    if ((param_3 & 1) != 0) {
      return 0x80010001;
    }
LAB_0050626d:
    local_88 = 0;
  }
  libspdm_reset_message_buffer_via_request_code(param_1,0,0xe0);
  *(byte *)(param_1 + 0x630) = param_5;
  uVar7 = *(uint *)(param_1 + 0x11c);
  uVar10 = libspdm_acquire_sender_buffer(param_1,local_40,&local_48);
  if (((uint)(uVar10 >> 0x1c) & 0xf) == 8) {
    return uVar10;
  }
  uVar10 = (ulong)*(uint *)(param_1 + 0x120);
  uVar13 = (ulong)uVar7;
  if (local_40[0] < uVar13 + uVar10) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_measurements.c"
               ,0xe6,
               "message_size >= transport_header_size + spdm_context->local_context.capability.transport_tail_size"
              );
    uVar10 = (ulong)*(uint *)(param_1 + 0x120);
  }
  pbVar16 = local_48 + uVar13;
  uVar10 = (local_40[0] - uVar13) - uVar10;
  if (uVar10 < 4) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_measurements.c"
               ,0xec,"spdm_request_size >= sizeof(spdm_request->header)");
  }
  bVar4 = libspdm_get_connection_version(param_1);
  pbVar16[1] = 0xe0;
  *pbVar16 = bVar4;
  pbVar16[2] = param_3;
  pbVar16[3] = param_4;
  if ((param_3 & 1) == 0) {
    if (0x12 < bVar4) {
      if (uVar10 < 0xc) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_measurements.c"
                   ,0x114,
                   "spdm_request_size >= sizeof(spdm_request->header) + SPDM_REQ_CONTEXT_SIZE");
        if (param_12 == 0) {
          local_78 = 0xc;
          goto LAB_005063b0;
        }
LAB_00506856:
        local_78 = 0xc;
        goto LAB_0050685e;
      }
      if (param_12 != 0) goto LAB_00506856;
      local_78 = 0xc;
      lVar11 = 4;
      goto LAB_005063be;
    }
    local_78 = 4;
    if (param_12 != 0) {
LAB_0050685e:
      libspdm_zero_mem(param_12,0x20);
      goto LAB_005063b0;
    }
  }
  else {
    if (bVar4 < 0x13) {
      if (bVar4 < 0x11) {
        if (uVar10 < 0x24) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_measurements.c"
                     ,0xfa,
                     "spdm_request_size >= sizeof(spdm_get_measurements_request_t) - sizeof(spdm_request->slot_id_param)"
                    );
        }
        local_78 = 0x24;
      }
      else {
        if (uVar10 < 0x25) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_measurements.c"
                     ,0xf7,"spdm_request_size >= sizeof(spdm_get_measurements_request_t)");
        }
        local_78 = 0x25;
      }
    }
    else {
      if (uVar10 < 0x2d) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_measurements.c"
                   ,0xf3,
                   "spdm_request_size >= sizeof(spdm_get_measurements_request_t) + SPDM_REQ_CONTEXT_SIZE"
                  );
      }
      local_78 = 0x2d;
    }
    pbVar12 = pbVar16 + 4;
    if (param_11 == 0) {
      cVar3 = libspdm_get_random_number(0x20,pbVar12);
      if (cVar3 == '\0') {
        libspdm_release_sender_buffer(param_1);
        return 0x80060000;
      }
    }
    else {
      libspdm_copy_mem(pbVar12,0x20,param_11,0x20);
    }
    libspdm_debug_print(0x40,"RequesterNonce - ");
    libspdm_internal_dump_data(pbVar12,0x20);
    libspdm_debug_print(0x40,&DAT_00da91ae);
    pbVar16[0x24] = param_5;
    if (param_12 != 0) {
      libspdm_copy_mem(param_12,0x20,pbVar12,0x20);
    }
LAB_005063b0:
    if (0x12 < *pbVar16) {
      lVar11 = local_78 + -8;
LAB_005063be:
      pbVar12 = pbVar16 + lVar11;
      if (param_6 == 0) {
        libspdm_zero_mem(pbVar12,8);
      }
      else {
        libspdm_copy_mem(pbVar12,8,param_6,8);
      }
      libspdm_debug_print(0x40,"RequesterContext - ");
      libspdm_internal_dump_data(pbVar12,8);
      libspdm_debug_print(0x40,&DAT_00da91ae);
    }
  }
  uVar7 = libspdm_send_spdm_request(param_1,param_2,local_78,pbVar16);
  if (uVar7 >> 0x1c == 8) {
    libspdm_release_sender_buffer(param_1);
    return (ulong)uVar7;
  }
  libspdm_release_sender_buffer(param_1);
  pbVar16 = *(byte **)(param_1 + 0x48);
  uVar10 = libspdm_acquire_receiver_buffer(param_1,local_40,&local_48);
  if (((uint)(uVar10 >> 0x1c) & 0xf) == 8) {
    return uVar10;
  }
  if (local_40[0] < uVar13) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_measurements.c"
               ,0x13d,"message_size >= transport_header_size");
  }
  local_58 = local_48;
  local_50 = local_40[0];
  uVar10 = libspdm_receive_spdm_response(param_1,param_2,&local_50);
  uVar7 = (uint)uVar10;
  if (((uint)(uVar10 >> 0x1c) & 0xf) == 8) goto LAB_00506c00;
  if (local_50 < 4) {
LAB_005069b0:
    uVar7 = 0x80010006;
    goto LAB_005068d5;
  }
  if (*local_58 != *pbVar16) goto LAB_005068d0;
  if (local_58[1] == 0x7f) {
    uVar10 = libspdm_handle_error_response_main(param_1,param_2,&local_50,&local_58,0xe0,0x60);
    uVar7 = (uint)uVar10;
    if (((uint)(uVar10 >> 0x1c) & 0xf) == 8) goto LAB_00506c00;
  }
  else if (local_58[1] != 0x60) goto LAB_005068d0;
  if (local_50 < 8) goto LAB_005069b0;
  bVar4 = local_58[4];
  if (param_4 == 0) {
    if (bVar4 != 0) goto LAB_005068d0;
    uVar10 = 0;
    iVar6 = libspdm_read_uint24(local_58 + 5);
    uVar8 = 0;
    if (iVar6 != 0) goto LAB_005068d0;
LAB_00506510:
    pbVar12 = local_58 + 8;
    if ((param_3 & 1) == 0) {
      if (local_50 < uVar10 + 10) goto LAB_005069b0;
      pbVar15 = pbVar12 + uVar10;
      libspdm_debug_print(0x40,"nonce (0x%x) - ",0x20);
      libspdm_internal_dump_data(pbVar15,0x20);
      libspdm_debug_print(0x40,&DAT_00da91ae);
      if (param_13 != 0) {
        libspdm_copy_mem(param_13,0x20,pbVar15,0x20);
      }
      uVar5 = libspdm_read_uint16(pbVar15 + 0x20);
      if (uVar5 < 0x401) {
        pbVar15 = pbVar15 + 0x22;
        uVar13 = (ulong)uVar5;
        if ((uVar5 == 0) ||
           (cVar3 = libspdm_process_general_opaque_data_check(param_1,uVar13,pbVar15), cVar3 != '\0'
           )) {
          if (*pbVar16 < 0x13) {
            lVar11 = uVar10 + 0x2a;
          }
          else {
            lVar11 = uVar10 + 0x32;
          }
          uVar2 = lVar11 + uVar13;
          if (local_50 < uVar2) goto LAB_005069b0;
          local_50 = uVar2;
          if ((param_14 != 0) && (param_15 != (ulong *)0x0)) {
            if (*param_15 <= uVar13) goto LAB_00506d0d;
            libspdm_copy_mem(param_14,*param_15,pbVar15,uVar13);
            *param_15 = uVar13;
          }
          if (0x12 < *pbVar16) {
            libspdm_debug_print(0x40,"RequesterContext - ");
            libspdm_internal_dump_data(pbVar15 + uVar13,8);
            libspdm_debug_print(0x40,&DAT_00da91ae);
            cVar3 = libspdm_consttime_is_mem_equal(pbVar16 + local_78 + -8,pbVar15 + uVar13,8);
            if (cVar3 == '\0') goto LAB_005068d0;
          }
          if ((*local_58 < 0x12) || ((local_58[3] & 0x30) == 0)) {
            uVar13 = libspdm_append_message_m(param_1,lVar9,pbVar16,local_78);
            uVar7 = (uint)uVar13;
            if (((uint)(uVar13 >> 0x1c) & 0xf) != 8) {
              uVar13 = libspdm_append_message_m(param_1,lVar9,local_58,local_50);
              uVar7 = (uint)uVar13;
              if (((uint)(uVar13 >> 0x1c) & 0xf) != 8) {
LAB_0050673b:
                if (((param_7 != (byte *)0x0) && (*param_7 = 0, 0x11 < *local_58)) &&
                   ((param_3 & 1) != 0)) {
                  *param_7 = local_58[3] & 0x30;
                }
                if (param_4 == 0) {
                  bVar4 = local_58[2];
                  *param_8 = bVar4;
                  if ((byte)(bVar4 - 1) < 0xfe) {
LAB_00506784:
                    libspdm_append_msg_log(param_1,local_58,local_50);
                    uVar7 = 0;
                    goto LAB_005068e6;
                  }
                }
                else {
                  bVar4 = local_58[4];
                  *param_8 = bVar4;
                  if (*param_9 < uVar8) goto LAB_00506d0d;
                  if (3 < uVar8) {
                    bVar14 = 1;
                    uVar7 = 0;
                    do {
                      pbVar16 = pbVar12 + uVar7;
                      if ((((((long)((ulong)uVar8 - (ulong)uVar7) <
                              (long)(ulong)*(ushort *)(pbVar16 + 2)) ||
                            (bVar1 = pbVar16[1], bVar1 == 0)) ||
                           (((bVar1 - 1 & bVar1) != 0 ||
                            ((bVar1 != *(byte *)(param_1 + 0x270) || (0xfd < (byte)(*pbVar16 - 1))))
                            ))) || ((*pbVar16 != param_4 && (param_4 != 0xff)))) || (bVar4 < bVar14)
                         ) goto LAB_005068d0;
                      bVar14 = bVar14 + 1;
                      uVar7 = uVar7 + 4 + (uint)*(ushort *)(pbVar16 + 2);
                    } while (uVar7 < uVar8);
                    if (uVar7 == uVar8) {
                      *param_9 = uVar7;
                      libspdm_copy_mem(param_10,uVar10,pbVar12,uVar10);
                      goto LAB_00506784;
                    }
                  }
                }
                goto LAB_005068d0;
              }
            }
LAB_00506c00:
            if (uVar7 == 0x80010009) goto LAB_005068e6;
            goto LAB_005068d5;
          }
        }
      }
      goto LAB_005068d0;
    }
    if (local_50 < uVar10 + 0x2a) goto LAB_005069b0;
    if ((0x10 < *local_58) && (param_5 != (local_58[3] & 0xf))) goto LAB_005068d0;
    pbVar15 = pbVar12 + uVar10;
    libspdm_debug_print(0x40,"nonce (0x%x) - ",0x20);
    libspdm_internal_dump_data(pbVar15,0x20);
    libspdm_debug_print(0x40,&DAT_00da91ae);
    if (param_13 != 0) {
      libspdm_copy_mem(param_13,0x20,pbVar15);
    }
    uVar5 = libspdm_read_uint16(pbVar15 + 0x20);
    if (0x400 < uVar5) goto LAB_005068d0;
    if ((*local_58 < 0x12) || ((*(byte *)(param_1 + 0x271) & 0xf) != 0)) {
      if (uVar5 == 0) {
        uVar13 = 0;
      }
      else {
        uVar13 = (ulong)uVar5;
        cVar3 = libspdm_process_general_opaque_data_check(param_1,uVar13,pbVar15 + 0x22);
        if (cVar3 == '\0') goto LAB_005068d0;
      }
    }
    else {
      if (uVar5 != 0) goto LAB_005068d0;
      uVar13 = 0;
    }
    if (*pbVar16 < 0x13) {
      lVar11 = uVar10 + 0x2a;
    }
    else {
      lVar11 = uVar10 + 0x32;
    }
    uVar2 = lVar11 + local_88 + uVar13;
    if (local_50 < uVar2) goto LAB_005069b0;
    local_50 = uVar2;
    if ((param_14 == 0) || (param_15 == (ulong *)0x0)) {
LAB_0050664b:
      pbVar15 = pbVar15 + 0x22 + uVar13;
      if (0x12 < *pbVar16) {
        libspdm_debug_print(0x40,"RequesterContext - ");
        libspdm_internal_dump_data(pbVar15,8);
        libspdm_debug_print(0x40,&DAT_00da91ae);
        cVar3 = libspdm_consttime_is_mem_equal(pbVar16 + local_78 + -8,pbVar15,8);
        if (cVar3 == '\0') goto LAB_005068d0;
        pbVar15 = pbVar15 + 8;
      }
      uVar13 = libspdm_append_message_m(param_1,lVar9,pbVar16,local_78);
      uVar7 = (uint)uVar13;
      if (((uint)(uVar13 >> 0x1c) & 0xf) != 8) {
        uVar13 = libspdm_append_message_m(param_1,lVar9,local_58,local_50 - local_88);
        uVar7 = (uint)uVar13;
        if (((uint)(uVar13 >> 0x1c) & 0xf) != 8) {
          libspdm_debug_print(0x40,"signature (0x%zx):\n",local_88);
          libspdm_internal_dump_hex(pbVar15,local_88);
          cVar3 = libspdm_verify_measurement_signature(param_1,lVar9,pbVar15,local_88);
          uVar7 = 0x80020001;
          if (cVar3 != '\0') {
            libspdm_reset_message_m(param_1,lVar9);
            goto LAB_0050673b;
          }
          goto LAB_005068d5;
        }
      }
      goto LAB_00506c00;
    }
    if (uVar13 < *param_15) {
      libspdm_copy_mem(param_14,*param_15,pbVar15 + 0x22);
      *param_15 = uVar13;
      goto LAB_0050664b;
    }
LAB_00506d0d:
    uVar7 = 0x8001000d;
  }
  else {
    if (param_4 == 0xff) {
      if ((byte)(bVar4 - 1) < 0xfe) goto LAB_00506cae;
    }
    else if (bVar4 == 1) {
LAB_00506cae:
      uVar8 = libspdm_read_uint24(local_58 + 5);
      uVar10 = (ulong)uVar8;
      if (uVar10 + 8 <= local_50) {
        libspdm_debug_print(0x40,"measurement_record_length - 0x%06x\n",uVar10);
        goto LAB_00506510;
      }
      goto LAB_005069b0;
    }
LAB_005068d0:
    uVar7 = 0x80010005;
  }
LAB_005068d5:
  libspdm_reset_message_m(param_1,lVar9);
LAB_005068e6:
  libspdm_release_receiver_buffer(param_1);
  return (ulong)uVar7;
}


// ===== 00506e90 libspdm_get_measurement_ex =====

int libspdm_get_measurement_ex
              (long param_1,undefined8 param_2,undefined1 param_3,undefined1 param_4,
              undefined1 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
              undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
              undefined8 param_13,undefined8 param_14)

{
  undefined8 uVar1;
  int iVar2;
  ulong uVar3;
  
  uVar1 = *(undefined8 *)(param_1 + 0xb28);
  *(undefined1 *)(param_1 + 0xb30) = 1;
  uVar3 = (ulong)*(byte *)(param_1 + 0xb25);
  while( true ) {
    iVar2 = libspdm_try_get_measurement
                      (param_1,param_2,param_3,param_4,param_5,0,param_6,param_7,param_8,param_9,
                       param_10,param_11,param_12,param_13,param_14);
    if (iVar2 != -0x7ffefff8) {
      return iVar2;
    }
    libspdm_sleep(uVar1);
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
  }
  return -0x7ffefff8;
}


// ===== 00506f60 libspdm_get_version =====

uint libspdm_get_version(long param_1,byte *param_2,long param_3)

{
  byte bVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char cVar4;
  uint uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  char *pcVar9;
  undefined1 local_5a [2];
  char *local_58;
  ulong local_50;
  char *local_48;
  ulong local_40 [2];
  
  uVar8 = (ulong)*(byte *)(param_1 + 0xb25);
  uVar2 = *(undefined8 *)(param_1 + 0xb28);
  *(undefined1 *)(param_1 + 0xb30) = 0;
  do {
    libspdm_reset_message_a(param_1);
    libspdm_reset_message_d(param_1);
    libspdm_reset_message_b(param_1);
    libspdm_reset_message_c(param_1);
    libspdm_reset_context(param_1);
    libspdm_reset_message_buffer_via_request_code(param_1,0,0x84);
    uVar7 = (ulong)*(uint *)(param_1 + 0x11c);
    uVar5 = libspdm_acquire_sender_buffer(param_1,local_40,&local_48);
    if (uVar5 >> 0x1c != 8) {
      uVar6 = (ulong)*(uint *)(param_1 + 0x120);
      if (local_40[0] < uVar7 + uVar6) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_version.c"
                   ,0x45,
                   "message_size >= transport_header_size + spdm_context->local_context.capability.transport_tail_size"
                  );
        uVar6 = (ulong)*(uint *)(param_1 + 0x120);
      }
      pcVar9 = local_48 + uVar7;
      if ((local_40[0] - uVar7) - uVar6 < 4) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_version.c"
                   ,0x4b,"spdm_request_size >= sizeof(spdm_get_version_request_t)");
      }
      pcVar9[0] = '\x10';
      pcVar9[1] = -0x7c;
      pcVar9[2] = '\0';
      pcVar9[3] = '\0';
      uVar5 = libspdm_send_spdm_request(param_1,0,4,pcVar9);
      if (uVar5 >> 0x1c == 8) {
        libspdm_release_sender_buffer(param_1);
      }
      else {
        libspdm_release_sender_buffer(param_1);
        uVar3 = *(undefined8 *)(param_1 + 0x48);
        uVar5 = libspdm_acquire_receiver_buffer(param_1,local_40,&local_48);
        if (uVar5 >> 0x1c != 8) {
          if (local_40[0] < uVar7) {
            libspdm_debug_assert
                      ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_get_version.c"
                       ,0x60,"message_size >= transport_header_size");
          }
          local_50 = local_40[0];
          local_58 = local_48;
          uVar5 = libspdm_receive_spdm_response(param_1,0,&local_50,&local_58);
          if (uVar5 >> 0x1c != 8) {
            if (local_50 < 4) goto LAB_00507170;
            if (*local_58 != '\x10') goto LAB_005070e9;
            if (local_58[1] == '\x7f') {
              if (local_58[2] == 'B') {
                libspdm_release_receiver_buffer(param_1);
                return 0x8001000a;
              }
              uVar5 = libspdm_handle_simple_error_response();
              if (uVar5 >> 0x1c == 8) goto LAB_00507270;
            }
            else if (local_58[1] != '\x04') goto LAB_005070e9;
            if (local_50 < 6) {
LAB_00507170:
              libspdm_release_receiver_buffer(param_1);
              return 0x80010006;
            }
            if (4 < (byte)(local_58[5] - 1U)) {
LAB_005070e9:
              libspdm_release_receiver_buffer(param_1);
              return 0x80010005;
            }
            uVar7 = (ulong)(byte)(local_58[5] + 3) * 2;
            if (local_50 < uVar7) goto LAB_00507170;
            local_50 = uVar7;
            uVar5 = libspdm_append_message_a(param_1,uVar3,4);
            if (uVar5 >> 0x1c != 8) {
              uVar5 = libspdm_append_message_a(param_1,local_58,local_50);
              if (uVar5 >> 0x1c != 8) {
                cVar4 = libspdm_negotiate_connection_version
                                  (local_5a,param_1 + 0xea,*(undefined1 *)(param_1 + 0xe8),
                                   local_58 + 6,local_58[5]);
                if (cVar4 == '\0') {
                  libspdm_reset_message_a(param_1);
                  libspdm_release_receiver_buffer(param_1);
                  return 0x80010007;
                }
                libspdm_copy_mem(param_1 + 0x23c,2,local_5a,2);
                if ((param_2 != (byte *)0x0) && (param_3 != 0)) {
                  bVar1 = local_58[5];
                  if (*param_2 < bVar1) {
                    *param_2 = bVar1;
                    libspdm_reset_message_a(param_1);
                    libspdm_release_receiver_buffer(param_1);
                    return 0x8001000d;
                  }
                  *param_2 = bVar1;
                  libspdm_copy_mem(param_3,(ulong)bVar1 * 2,local_58 + 6,(ulong)bVar1 * 2);
                  libspdm_version_number_sort(param_3,*param_2);
                }
                *(undefined4 *)(param_1 + 0x238) = 1;
                libspdm_append_msg_log(param_1,local_58,local_50);
                *(undefined1 *)(param_1 + 0x233) = 1;
                libspdm_release_receiver_buffer(param_1);
                return 0;
              }
              libspdm_reset_message_a(param_1);
            }
          }
LAB_00507270:
          libspdm_release_receiver_buffer(param_1);
        }
      }
    }
    if (uVar5 != 0x80010008) {
      return uVar5;
    }
    libspdm_sleep(uVar2);
    if (uVar8 == 0) {
      return 0x80010008;
    }
    uVar8 = uVar8 - 1;
  } while( true );
}


// ===== 00507390 libspdm_handle_simple_error_response =====

int libspdm_handle_simple_error_response(long param_1,char param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = -0x7ffefff7;
  if ((param_2 != 'B') && (iVar3 = -0x7ffefff8, param_2 != '\x03')) {
    if (((byte)(*(char *)(*(long *)(param_1 + 0x48) + 1) + 0x13U) < 2) && (param_2 == '\f')) {
      bVar1 = libspdm_get_connection_version();
      if (bVar1 < 0x13) {
        return -0x7ffeffee;
      }
      cVar2 = libspdm_is_capabilities_flag_supported(param_1,1,0,0x200000);
      return (-(uint)(cVar2 == '\0') & 0xfffffff8) + 0x80010012;
    }
    iVar3 = -0x7ffefff6;
    if (param_2 == 'C') {
      *(undefined4 *)(param_1 + 0x238) = 0;
      return -0x7ffefff5;
    }
  }
  return iVar3;
}


// ===== 00507430 libspdm_handle_error_response_main =====

undefined8
libspdm_handle_error_response_main
          (undefined8 param_1,undefined4 *param_2,undefined8 param_3,long *param_4)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = *param_4;
  if (*(char *)(lVar2 + 1) != '\x7f') {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_handle_error_response.c"
               ,0x1a5,"spdm_response->request_response_code == SPDM_ERROR");
  }
  cVar1 = *(char *)(lVar2 + 2);
  if (cVar1 == '\x06') {
    if (param_2 != (undefined4 *)0x0) {
      libspdm_free_session_id(param_1,*param_2);
      return 0x8001000f;
    }
  }
  else if (cVar1 == 'B') {
    return 0x80010009;
  }
  uVar3 = libspdm_handle_simple_error_response(param_1);
  return uVar3;
}


// ===== 005074d0 libspdm_heartbeat =====

uint libspdm_heartbeat(long param_1,undefined4 param_2)

{
  uint uVar1;
  undefined8 uVar2;
  ulong uVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  char *pcVar11;
  undefined4 local_5c;
  char *local_58;
  ulong local_50;
  char *local_48;
  ulong local_40 [2];
  
  uVar2 = *(undefined8 *)(param_1 + 0xb28);
  *(undefined1 *)(param_1 + 0xb30) = 1;
  uVar10 = (ulong)*(byte *)(param_1 + 0xb25);
  local_5c = param_2;
  bVar4 = libspdm_get_connection_version(param_1);
  do {
    if (bVar4 < 0x11) {
      return 0x80010002;
    }
    lVar8 = libspdm_get_session_info_via_session_id(param_1,local_5c);
    if (lVar8 == 0) {
      return 0x80010001;
    }
    cVar5 = libspdm_is_capabilities_flag_supported(param_1,1,0x2000,0x2000);
    if (cVar5 == '\0') {
      return 0x80010002;
    }
    if (((*(uint *)(param_1 + 0x238) < 3) ||
        (iVar6 = libspdm_secured_message_get_session_state(*(undefined8 *)(lVar8 + 0x1f0)),
        iVar6 != 2)) || (*(char *)(lVar8 + 8) == '\0')) {
      return 0x80010003;
    }
    uVar1 = *(uint *)(param_1 + 0x11c);
    uVar7 = libspdm_acquire_sender_buffer(param_1,local_40,&local_48);
    if (uVar7 >> 0x1c != 8) {
      uVar3 = (ulong)uVar1;
      uVar9 = (ulong)*(uint *)(param_1 + 0x120);
      if (local_40[0] < uVar3 + uVar9) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_heartbeat.c",
                   0x47,
                   "message_size >= transport_header_size + spdm_context->local_context.capability.transport_tail_size"
                  );
        uVar9 = (ulong)*(uint *)(param_1 + 0x120);
      }
      pcVar11 = local_48 + uVar3;
      if ((local_40[0] - uVar3) - uVar9 < 4) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_heartbeat.c",
                   0x4d,"spdm_request_size >= sizeof(spdm_heartbeat_request_t)");
      }
      cVar5 = libspdm_get_connection_version(param_1);
      pcVar11[3] = '\0';
      *pcVar11 = cVar5;
      pcVar11[1] = -0x18;
      pcVar11[2] = '\0';
      uVar7 = libspdm_send_spdm_request(param_1,&local_5c,4,pcVar11);
      if (uVar7 >> 0x1c == 8) {
        libspdm_release_sender_buffer(param_1);
      }
      else {
        libspdm_release_sender_buffer(param_1);
        pcVar11 = *(char **)(param_1 + 0x48);
        libspdm_reset_message_buffer_via_request_code(param_1,lVar8,0xe8);
        uVar7 = libspdm_acquire_receiver_buffer(param_1,local_40,&local_48);
        if (uVar7 >> 0x1c != 8) {
          if (local_40[0] < uVar3) {
            libspdm_debug_assert
                      ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_heartbeat.c"
                       ,100,"message_size >= transport_header_size");
          }
          local_50 = local_40[0];
          local_58 = local_48;
          uVar7 = libspdm_receive_spdm_response(param_1,&local_5c,&local_50,&local_58);
          if (uVar7 >> 0x1c != 8) {
            if (local_50 < 4) goto LAB_005076da;
            if (*local_58 != *pcVar11) {
LAB_005077b0:
              libspdm_release_receiver_buffer(param_1);
              return 0x80010005;
            }
            if (local_58[1] == '\x7f') {
              uVar7 = libspdm_handle_error_response_main
                                (param_1,&local_5c,&local_50,&local_58,0xe8,0x68);
              if (uVar7 >> 0x1c == 8) goto LAB_005077f0;
            }
            else if (local_58[1] != 'h') goto LAB_005077b0;
            if (local_50 == 4) {
              libspdm_append_msg_log(param_1,local_58,4);
              libspdm_release_receiver_buffer(param_1);
              return 0;
            }
LAB_005076da:
            libspdm_release_receiver_buffer(param_1);
            return 0x80010006;
          }
LAB_005077f0:
          libspdm_release_receiver_buffer(param_1);
        }
      }
    }
    if (uVar7 != 0x80010008) {
      return uVar7;
    }
    libspdm_sleep(uVar2);
    if (uVar10 == 0) {
      return 0x80010008;
    }
    uVar10 = uVar10 - 1;
    local_5c = param_2;
    bVar4 = libspdm_get_connection_version(param_1);
  } while( true );
}


// ===== 00507860 libspdm_verify_key_exchange_rsp_hmac =====

undefined4
libspdm_verify_key_exchange_rsp_hmac
          (long param_1,undefined8 param_2,undefined8 param_3,ulong param_4)

{
  uint uVar1;
  undefined4 uVar2;
  ulong local_60;
  undefined1 local_58 [48];
  
  uVar1 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
  local_60 = (ulong)uVar1;
  if (local_60 != param_4) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_key_exchange.c",
               0x3a,"hash_size == hmac_data_size");
  }
  uVar2 = libspdm_calculate_th_hmac_for_exchange_rsp(param_1,param_2,1,&local_60,local_58);
  if ((char)uVar2 == '\0') {
    return uVar2;
  }
  libspdm_debug_print(0x40,"th_curr hmac - ");
  libspdm_internal_dump_data(local_58,local_60);
  libspdm_debug_print(0x40,&DAT_00da94e2);
  uVar2 = libspdm_consttime_is_mem_equal(local_58,param_3,local_60);
  if ((char)uVar2 != '\0') {
    libspdm_debug_print(0x40,"!!! verify_key_exchange_hmac - PASS !!!\n");
    return uVar2;
  }
  libspdm_debug_print(0x80000000,"!!! verify_key_exchange_hmac - FAIL !!!\n");
  return uVar2;
}


// ===== 00507980 libspdm_verify_key_exchange_rsp_signature =====

undefined4
libspdm_verify_key_exchange_rsp_signature
          (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  long local_78;
  ulong local_70;
  undefined1 local_68 [56];
  
  uVar2 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
  bVar1 = *(byte *)(param_1 + 0x630);
  local_70 = (ulong)uVar2;
  if ((byte)(bVar1 - 8) < 0xf7) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_key_exchange.c",
               0x8d,"(slot_id < SPDM_MAX_SLOT_COUNT) || (slot_id == 0xFF)");
    uVar3 = libspdm_calculate_th_hash_for_exchange(param_1,param_2,&local_70,local_68);
    if ((char)uVar3 == '\0') {
      return uVar3;
    }
    libspdm_debug_print(0x40,"th_curr hash - ");
    libspdm_internal_dump_data(local_68,local_70);
    libspdm_debug_print(0x40,&DAT_00da94e2);
    libspdm_debug_print(0x40,"signature - ");
    libspdm_internal_dump_data(param_3,param_4);
    libspdm_debug_print(0x40,&DAT_00da94e2);
  }
  else {
    uVar3 = libspdm_calculate_th_hash_for_exchange(param_1,param_2,&local_70,local_68);
    if ((char)uVar3 == '\0') {
      return uVar3;
    }
    libspdm_debug_print(0x40,"th_curr hash - ");
    libspdm_internal_dump_data(local_68,local_70);
    libspdm_debug_print(0x40,&DAT_00da94e2);
    libspdm_debug_print(0x40,"signature - ");
    libspdm_internal_dump_data(param_3,param_4);
    libspdm_debug_print(0x40,&DAT_00da94e2);
    if (bVar1 == 0xff) {
      uVar3 = libspdm_asym_get_public_key_from_der
                        (*(undefined4 *)(param_1 + 0x278),*(undefined8 *)(param_1 + 0x218),
                         *(undefined8 *)(param_1 + 0x220),&local_78);
      if ((char)uVar3 == '\0') {
        return uVar3;
      }
      uVar3 = libspdm_asym_verify_hash_ex
                        (*(undefined2 *)(param_1 + 0x23c),100,*(undefined4 *)(param_1 + 0x278),
                         *(undefined4 *)(param_1 + 0x27c),local_78,local_68,local_70,param_3,param_4
                         ,param_1 + 0xb90);
      libspdm_asym_free(*(undefined4 *)(param_1 + 0x278),local_78);
      goto LAB_00507ac5;
    }
  }
  local_78 = *(long *)(param_1 + 0x468 + (ulong)bVar1 * 0x40);
  if (local_78 == 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_key_exchange.c",
               0xda,"context != NULL");
  }
  uVar3 = libspdm_asym_verify_hash_ex
                    (*(undefined2 *)(param_1 + 0x23c),100,*(undefined4 *)(param_1 + 0x278),
                     *(undefined4 *)(param_1 + 0x27c),local_78,local_68,local_70,param_3,param_4,
                     param_1 + 0xb90);
LAB_00507ac5:
  if ((char)uVar3 == '\0') {
    libspdm_debug_print(0x80000000,"!!! verify_key_exchange_signature - FAIL !!!\n");
  }
  else {
    libspdm_debug_print(0x40,"!!! verify_key_exchange_signature - PASS !!!\n");
  }
  return uVar3;
}


// ===== 00507c60 libspdm_try_send_receive_key_exchange =====

ulong libspdm_try_send_receive_key_exchange
                (long param_1,byte param_2,byte param_3,byte param_4,undefined4 *param_5,
                byte *param_6,byte *param_7,long param_8,long param_9,long param_10,long param_11,
                long param_12,ulong param_13,long param_14,ulong *param_15)

{
  byte *pbVar1;
  long lVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  char cVar6;
  char cVar7;
  short sVar8;
  ushort uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  ulong uVar13;
  long lVar14;
  long lVar15;
  ulong uVar16;
  ulong uVar17;
  ulong uVar18;
  byte *pbVar19;
  byte *pbVar20;
  byte *pbVar21;
  uint local_d8;
  byte local_c8;
  ulong local_a0;
  byte *local_98;
  ulong local_90;
  ulong local_88;
  ulong local_80;
  byte *local_78;
  ulong local_70;
  undefined1 local_68 [56];
  
  if ((byte)(param_3 - 8) < 0xf7) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_key_exchange.c",
               0x12e,"(slot_id < SPDM_MAX_SLOT_COUNT) || (slot_id == 0xff)");
  }
  else if ((param_3 == 0xff) && (*(long *)(param_1 + 0x220) == 0)) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_key_exchange.c",
               0x12f,
               "(slot_id != 0xff) || (spdm_context->local_context.peer_public_key_provision_size != 0)"
              );
  }
  if ((byte)(param_2 - 2) < 0xfd) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_key_exchange.c",
               0x131,
               "measurement_hash_type == SPDM_KEY_EXCHANGE_REQUEST_NO_MEASUREMENT_SUMMARY_HASH || measurement_hash_type == SPDM_KEY_EXCHANGE_REQUEST_TCB_COMPONENT_MEASUREMENT_HASH || measurement_hash_type == SPDM_KEY_EXCHANGE_REQUEST_ALL_MEASUREMENTS_HASH"
              );
  }
  bVar3 = libspdm_get_connection_version(param_1);
  if (((0x12 < bVar3) && ((param_4 & 2) != 0)) &&
     (cVar4 = libspdm_is_capabilities_flag_supported(param_1,1,0,0x2000000), cVar4 == '\0')) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_key_exchange.c",
               0x134,
               "(libspdm_get_connection_version(spdm_context) < SPDM_MESSAGE_VERSION_13) || ((session_policy & SPDM_KEY_EXCHANGE_REQUEST_SESSION_POLICY_EVENT_ALL_POLICY) == 0) || libspdm_is_capabilities_flag_supported( spdm_context, true, 0, SPDM_GET_CAPABILITIES_RESPONSE_FLAGS_EVENT_CAP)"
              );
  }
  bVar3 = libspdm_get_connection_version(param_1);
  if ((bVar3 < 0x11) ||
     (cVar4 = libspdm_is_capabilities_flag_supported(param_1,1,0x200,0x200), cVar4 == '\0')) {
    return 0x80010002;
  }
  if (*(uint *)(param_1 + 0x238) < 3) {
    return 0x80010003;
  }
  bVar3 = libspdm_get_connection_version(param_1);
  if ((0x11 < bVar3) && ((*(byte *)(param_1 + 0x271) & 0xf) != 2)) {
    return 0x80010004;
  }
  sVar8 = libspdm_allocate_req_session_id(param_1,0);
  if (sVar8 == 0) {
    return 0x8001000e;
  }
  libspdm_reset_message_buffer_via_request_code(param_1,0,0xe4);
  *(byte *)(param_1 + 0x630) = param_3;
  uVar10 = *(uint *)(param_1 + 0x11c);
  uVar13 = libspdm_acquire_sender_buffer(param_1,&local_70,&local_78);
  if (((uint)(uVar13 >> 0x1c) & 0xf) == 8) {
    return uVar13;
  }
  uVar13 = (ulong)*(uint *)(param_1 + 0x120);
  uVar18 = (ulong)uVar10;
  if (local_70 < uVar18 + uVar13) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_key_exchange.c",
               0x15d,
               "message_size >= transport_header_size + spdm_context->local_context.capability.transport_tail_size"
              );
    uVar13 = (ulong)*(uint *)(param_1 + 0x120);
  }
  pbVar21 = local_78 + uVar18;
  uVar13 = (local_70 - uVar18) - uVar13;
  if (uVar13 < 0x28) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_key_exchange.c",
               0x163,"spdm_request_size >= sizeof(spdm_key_exchange_request_t)");
  }
  bVar3 = libspdm_get_connection_version(param_1);
  pbVar21[3] = param_3;
  pbVar19 = pbVar21 + 8;
  *pbVar21 = bVar3;
  pbVar21[1] = 0xe4;
  pbVar21[2] = param_2;
  if (param_9 == 0) {
    cVar4 = libspdm_get_random_number(0x20,pbVar19);
    if (cVar4 == '\0') {
      libspdm_release_sender_buffer(param_1);
      return 0x80060000;
    }
  }
  else {
    libspdm_copy_mem(pbVar19,0x20,param_9,0x20);
  }
  libspdm_debug_print(0x40,"RequesterRandomData (0x%x) - ",0x20);
  libspdm_internal_dump_data(pbVar19,0x20);
  libspdm_debug_print(0x40,&DAT_00da94e2);
  if (param_10 != 0) {
    libspdm_copy_mem(param_10,0x20,pbVar19,0x20);
  }
  pbVar21[7] = 0;
  *(short *)(pbVar21 + 4) = sVar8;
  bVar3 = 0;
  if (0x11 < *pbVar21) {
    bVar3 = param_4;
  }
  pbVar21[6] = bVar3;
  uVar10 = libspdm_get_dhe_pub_key_size(*(undefined2 *)(param_1 + 0x280));
  local_88 = (ulong)uVar10;
  lVar14 = libspdm_secured_message_dhe_new
                     (*(undefined2 *)(param_1 + 0x23c),*(undefined2 *)(param_1 + 0x280),1);
  if (lVar14 == 0) {
LAB_00508874:
    libspdm_release_sender_buffer(param_1);
    return 0x80020000;
  }
  pbVar19 = pbVar21 + 0x28;
  if (uVar13 < local_88 + 0x28) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_key_exchange.c",
               0x18d,"spdm_request_size >= sizeof(spdm_key_exchange_request_t) + dhe_key_size");
  }
  cVar4 = libspdm_secured_message_dhe_generate_key
                    (*(undefined2 *)(param_1 + 0x280),lVar14,pbVar19,&local_88);
  if (cVar4 == '\0') {
    libspdm_secured_message_dhe_free(*(undefined2 *)(param_1 + 0x280),lVar14);
    goto LAB_00508874;
  }
  libspdm_debug_print(0x40,"RequesterKey (0x%zx):\n",local_88);
  libspdm_internal_dump_hex(pbVar19,local_88);
  pbVar19 = pbVar19 + local_88;
  if (param_12 == 0) {
    local_80 = libspdm_get_opaque_data_supported_version_data_size(param_1);
    if (uVar13 < local_80 + 0x2a + local_88) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_key_exchange.c"
                 ,0x1ab,
                 "spdm_request_size >= sizeof(spdm_key_exchange_request_t) + dhe_key_size + sizeof(uint16_t) + opaque_key_exchange_req_size"
                );
    }
    libspdm_write_uint16(pbVar19,local_80 & 0xffff);
    libspdm_build_opaque_data_supported_version_data(param_1,&local_80,pbVar19 + 2);
  }
  else {
    if (0x400 < param_13) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_key_exchange.c"
                 ,0x19c,"requester_opaque_data_size <= SPDM_MAX_OPAQUE_DATA_SIZE");
    }
    if (uVar13 < local_88 + 0x2a + param_13) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_key_exchange.c"
                 ,0x19e,
                 "spdm_request_size >= sizeof(spdm_key_exchange_request_t) + dhe_key_size + sizeof(uint16_t) + requester_opaque_data_size"
                );
    }
    libspdm_write_uint16(pbVar19,param_13 & 0xffff);
    libspdm_copy_mem(pbVar19 + 2,(uVar13 - local_88) + -0x28,param_12,param_13);
    local_80 = param_13;
  }
  lVar2 = local_80 - (long)pbVar21;
  uVar10 = libspdm_send_spdm_request(param_1,0,pbVar19 + lVar2 + 2,pbVar21);
  if (uVar10 >> 0x1c == 8) {
    libspdm_secured_message_dhe_free(*(undefined2 *)(param_1 + 0x280),lVar14);
    libspdm_release_sender_buffer(param_1);
    return (ulong)uVar10;
  }
  libspdm_release_sender_buffer(param_1);
  pbVar21 = *(byte **)(param_1 + 0x48);
  uVar10 = libspdm_acquire_receiver_buffer(param_1,&local_70,&local_78);
  if (uVar10 >> 0x1c == 8) {
    libspdm_secured_message_dhe_free(*(undefined2 *)(param_1 + 0x280),lVar14);
    return (ulong)uVar10;
  }
  if (local_70 < uVar18) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_key_exchange.c",
               0x1ca,"message_size >= transport_header_size");
  }
  local_98 = local_78;
  local_90 = local_70;
  uVar13 = libspdm_receive_spdm_response(param_1,0,&local_90,&local_98);
  uVar10 = (uint)uVar13;
  if (((uint)(uVar13 >> 0x1c) & 0xf) == 8) {
LAB_005089d7:
    libspdm_secured_message_dhe_free(*(undefined2 *)(param_1 + 0x280),lVar14);
    goto LAB_00508640;
  }
  if (local_90 < 4) {
LAB_00508790:
    libspdm_secured_message_dhe_free(*(undefined2 *)(param_1 + 0x280),lVar14);
    uVar10 = 0x80010006;
  }
  else {
    if (*local_98 == *pbVar21) {
      if (local_98[1] == 0x7f) {
        uVar13 = libspdm_handle_error_response_main(param_1,0,&local_90,&local_98,0xe4,100);
        uVar10 = (uint)uVar13;
        if (((uint)(uVar13 >> 0x1c) & 0xf) == 8) goto LAB_005089d7;
      }
      else if (local_98[1] != 100) goto LAB_005088d0;
      if (local_90 < 0x28) goto LAB_00508790;
      cVar4 = libspdm_is_capabilities_flag_supported(param_1,1,0x2000,0x2000);
      if ((cVar4 != '\0') || (local_98[2] == 0)) {
        if (param_6 != (byte *)0x0) {
          *param_6 = local_98[2];
        }
        *param_7 = local_98[7] & 0xf;
        bVar3 = local_98[6];
        local_c8 = bVar3 & 7;
        if ((bVar3 & 7) == 0) {
LAB_00508183:
          uVar11 = libspdm_get_asym_signature_size(*(undefined4 *)(param_1 + 0x278));
          uVar10 = libspdm_get_measurement_summary_hash_size(param_1,1,param_2);
          local_d8 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
          local_a0 = (ulong)local_d8;
          cVar4 = libspdm_is_capabilities_flag_supported(param_1,1,0x8000,0x8000);
          if (cVar4 != '\0') {
            local_a0 = 0;
            local_d8 = 0;
          }
          uVar13 = (ulong)uVar10;
          uVar18 = (ulong)uVar11;
          if (local_90 < uVar13 + 0x2a + local_88 + uVar18 + local_a0) goto LAB_00508790;
          libspdm_debug_print(0x40,"ResponderRandomData (0x%x) - ",0x20);
          libspdm_internal_dump_data(local_98 + 8,0x20);
          libspdm_debug_print(0x40,&DAT_00da94e2);
          if (param_11 != 0) {
            libspdm_copy_mem(param_11,0x20,local_98 + 8,0x20);
          }
          libspdm_debug_print(0x40,"ResponderKey (0x%zx):\n",local_88);
          libspdm_internal_dump_hex(local_98 + 0x28,local_88);
          pbVar1 = local_98 + local_88 + 0x28;
          libspdm_debug_print(0x40,"measurement_summary_hash (0x%x) - ",uVar10);
          libspdm_internal_dump_data(pbVar1,uVar13);
          libspdm_debug_print(0x40,&DAT_00da94e2);
          uVar9 = libspdm_read_uint16(pbVar1 + uVar13);
          if (uVar9 < 0x401) {
            uVar17 = (ulong)uVar9;
            if (local_90 < uVar13 + 0x2a + local_88 + uVar18 + local_a0 + uVar17) goto LAB_00508790;
            pbVar20 = pbVar1 + uVar13 + 2;
            if ((uVar9 == 0) ||
               ((cVar4 = libspdm_process_general_opaque_data_check(param_1,uVar17,pbVar20),
                cVar4 != '\0' &&
                (uVar10 = libspdm_process_opaque_data_version_selection_data(param_1,uVar17,pbVar20)
                , uVar10 >> 0x1c != 8)))) {
              if ((param_14 != 0) && (param_15 != (ulong *)0x0)) {
                if (*param_15 <= uVar17) {
                  libspdm_secured_message_dhe_free(*(undefined2 *)(param_1 + 0x280),lVar14);
                  uVar10 = 0x8001000d;
                  goto LAB_00508640;
                }
                libspdm_copy_mem(param_14,*param_15,pbVar20,uVar17);
                *param_15 = uVar17;
              }
              local_90 = uVar13 + 0x2a + local_88 + uVar18 + local_a0 + uVar17;
              uVar12 = libspdm_generate_session_id(sVar8,*(undefined2 *)(local_98 + 4));
              *param_5 = uVar12;
              lVar15 = libspdm_assign_session_id(param_1,uVar12,0);
              if (lVar15 == 0) {
                libspdm_secured_message_dhe_free(*(undefined2 *)(param_1 + 0x280),lVar14);
                uVar10 = 0x8001000e;
                goto LAB_00508640;
              }
              uVar16 = libspdm_append_message_k(param_1,lVar15,1,pbVar21,pbVar19 + lVar2 + 2);
              uVar10 = (uint)uVar16;
              if (((uint)(uVar16 >> 0x1c) & 0xf) != 8) {
                uVar16 = libspdm_append_message_k
                                   (param_1,lVar15,1,local_98,(local_90 - uVar18) - local_a0);
                uVar10 = (uint)uVar16;
                if (((uint)(uVar16 >> 0x1c) & 0xf) != 8) {
                  pbVar20 = pbVar20 + uVar17;
                  libspdm_debug_print(0x40,"signature (0x%x):\n",uVar11);
                  libspdm_internal_dump_hex(pbVar20,uVar18);
                  cVar4 = libspdm_verify_key_exchange_rsp_signature(param_1,lVar15,pbVar20,uVar18);
                  if (cVar4 == '\0') {
                    libspdm_free_session_id(param_1,*param_5);
                    libspdm_secured_message_dhe_free(*(undefined2 *)(param_1 + 0x280),lVar14);
LAB_00508b20:
                    uVar10 = 0x80020001;
                    goto LAB_00508640;
                  }
                  uVar17 = libspdm_append_message_k(param_1,lVar15,1,pbVar20,uVar18);
                  uVar10 = (uint)uVar17;
                  if (((uint)(uVar17 >> 0x1c) & 0xf) != 8) {
                    cVar4 = libspdm_secured_message_dhe_compute_key
                                      (*(undefined2 *)(param_1 + 0x280),lVar14,local_98 + 0x28,
                                       local_88,*(undefined8 *)(lVar15 + 0x1f0));
                    libspdm_secured_message_dhe_free(*(undefined2 *)(param_1 + 0x280),lVar14);
                    if (cVar4 == '\0') {
                      libspdm_free_session_id(param_1,*param_5);
                    }
                    else {
                      libspdm_debug_print(0x40,"libspdm_generate_session_handshake_key[%x]\n");
                      cVar4 = libspdm_calculate_th1_hash(param_1,lVar15,1,local_68);
                      if ((cVar4 != '\0') &&
                         (cVar4 = libspdm_generate_session_handshake_key
                                            (*(undefined8 *)(lVar15 + 0x1f0),local_68),
                         cVar4 != '\0')) {
                        cVar4 = libspdm_is_capabilities_flag_supported(param_1,1,0x8000,0x8000);
                        if (cVar4 == '\0') {
                          pbVar20 = pbVar20 + uVar18;
                          libspdm_debug_print(0x40,"verify_data (0x%x):\n",local_d8);
                          libspdm_internal_dump_hex(pbVar20,local_a0);
                          cVar4 = libspdm_verify_key_exchange_rsp_hmac
                                            (param_1,lVar15,pbVar20,local_a0);
                          if (cVar4 == '\0') {
                            libspdm_free_session_id(param_1,*param_5);
                            goto LAB_00508b20;
                          }
                          uVar10 = libspdm_append_message_k(param_1,lVar15,1,pbVar20,local_a0);
                          if (uVar10 >> 0x1c == 8) {
                            libspdm_free_session_id(param_1,*param_5);
                            goto LAB_00508640;
                          }
                        }
                        if (param_8 != 0) {
                          libspdm_copy_mem(param_8,uVar13,pbVar1,uVar13);
                        }
                        *(byte *)(lVar15 + 8) = local_98[2];
                        *(byte *)(lVar15 + 7) = param_4;
                        *(byte *)(lVar15 + 5) = local_c8;
                        libspdm_secured_message_set_session_state(*(undefined8 *)(lVar15 + 0x1f0),1)
                        ;
                        libspdm_append_msg_log(param_1,local_98,local_90);
                        uVar10 = 0;
                        goto LAB_00508640;
                      }
                      libspdm_free_session_id(param_1,*param_5);
                    }
                    uVar10 = 0x80020000;
                    goto LAB_00508640;
                  }
                }
              }
              libspdm_free_session_id(param_1,*param_5);
              libspdm_secured_message_dhe_free(*(undefined2 *)(param_1 + 0x280),lVar14);
              goto LAB_00508640;
            }
          }
        }
        else {
          cVar4 = libspdm_is_capabilities_flag_supported(param_1,1,0x100,0x100);
          bVar5 = libspdm_is_capabilities_flag_supported(param_1,1,0x1000,0x1000);
          cVar6 = libspdm_is_capabilities_flag_supported(param_1,1,2,0);
          cVar7 = libspdm_is_capabilities_flag_supported(param_1,1,0x10000,0);
          if ((cVar4 != '\0') && ((0x16UL >> ((ulong)bVar3 & 7) & 1) != 0)) {
            if (local_c8 == 1) {
              if (cVar6 == '\0') {
                if ((cVar7 == '\0') || (*param_7 == 0xf)) goto LAB_00508a59;
              }
              else if ((*param_7 < 8) && (cVar7 == '\0')) {
LAB_00508a59:
                if (((*pbVar21 < 0x13) || (*(char *)(param_1 + 0x64a) == '\0')) || (*param_7 == 0xf)
                   ) goto LAB_00508183;
                bVar5 = *(byte *)(param_1 + 0x1e2 + (ulong)*param_7 * 2) & 1;
                goto joined_r0x00508a8a;
              }
            }
            else if (cVar7 == '\0') {
joined_r0x00508a8a:
              if (bVar5 != 0) goto LAB_00508183;
            }
          }
        }
      }
    }
LAB_005088d0:
    libspdm_secured_message_dhe_free(*(undefined2 *)(param_1 + 0x280),lVar14);
    uVar10 = 0x80010005;
  }
LAB_00508640:
  libspdm_release_receiver_buffer(param_1);
  return (ulong)uVar10;
}


// ===== 00508c20 libspdm_send_receive_key_exchange =====

int libspdm_send_receive_key_exchange
              (long param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
              undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  undefined8 uVar1;
  int iVar2;
  ulong uVar3;
  
  uVar1 = *(undefined8 *)(param_1 + 0xb28);
  uVar3 = (ulong)*(byte *)(param_1 + 0xb25);
  *(undefined1 *)(param_1 + 0xb30) = 1;
  while( true ) {
    iVar2 = libspdm_try_send_receive_key_exchange
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,0,0,0,0,0,0,0
                      );
    if (iVar2 != -0x7ffefff8) {
      return iVar2;
    }
    libspdm_sleep(uVar1);
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
  }
  return -0x7ffefff8;
}


// ===== 00508cf0 libspdm_key_update =====

uint libspdm_key_update(long param_1,undefined4 param_2,char param_3)

{
  uint uVar1;
  undefined8 uVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  char *pcVar11;
  ulong uVar12;
  ulong *local_88;
  char **local_80;
  char local_6d;
  undefined4 local_5c;
  char *local_58;
  ulong local_50;
  char *local_48;
  ulong local_40 [2];
  
  uVar2 = *(undefined8 *)(param_1 + 0xb28);
  *(undefined1 *)(param_1 + 0xb30) = 1;
  uVar12 = (ulong)*(byte *)(param_1 + 0xb25);
  local_6d = '\0';
  do {
    local_5c = param_2;
    bVar3 = libspdm_get_connection_version(param_1);
    if ((bVar3 < 0x11) ||
       (cVar4 = libspdm_is_capabilities_flag_supported(param_1,1,0x4000,0x4000), cVar4 == '\0')) {
      return 0x80010002;
    }
    if (*(uint *)(param_1 + 0x238) < 3) {
      return 0x80010003;
    }
    lVar8 = libspdm_get_session_info_via_session_id(param_1,local_5c);
    if (lVar8 == 0) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_key_update.c",
                 0x44,"false");
      return 0x80010003;
    }
    iVar6 = libspdm_secured_message_get_session_state(*(undefined8 *)(lVar8 + 0x1f0));
    if (iVar6 != 2) {
      return 0x80010003;
    }
    libspdm_reset_message_buffer_via_request_code(param_1,lVar8,0xe9);
    if (local_6d == '\0') {
      uVar1 = *(uint *)(param_1 + 0x11c);
      uVar7 = libspdm_acquire_sender_buffer(param_1,local_40);
      if (uVar7 >> 0x1c != 8) {
        uVar10 = (ulong)uVar1;
        uVar9 = (ulong)*(uint *)(param_1 + 0x120);
        if (local_40[0] < uVar10 + uVar9) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_key_update.c"
                     ,0x58,
                     "message_size >= transport_header_size + spdm_context->local_context.capability.transport_tail_size"
                    );
          uVar9 = (ulong)*(uint *)(param_1 + 0x120);
        }
        local_80 = &local_48;
        local_88 = local_40;
        pcVar11 = local_48 + uVar10;
        if ((local_40[0] - uVar10) - uVar9 < 4) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_key_update.c"
                     ,0x5e,"spdm_request_size >= sizeof(spdm_key_update_request_t)");
        }
        cVar5 = libspdm_get_connection_version(param_1);
        pcVar11[1] = -0x17;
        *pcVar11 = cVar5;
        pcVar11[2] = '\x02' - param_3;
        pcVar11[3] = '\0';
        cVar5 = libspdm_get_random_number(1,pcVar11 + 3);
        if (cVar5 == '\0') goto LAB_00509260;
        if (param_3 == '\0') {
          libspdm_debug_print(0x40,"libspdm_create_update_session_data_key[%x] Responder\n",local_5c
                             );
          cVar5 = libspdm_create_update_session_data_key(*(undefined8 *)(lVar8 + 0x1f0),1);
          if (cVar5 == '\0') {
            libspdm_release_sender_buffer(param_1);
            return 0x80020000;
          }
        }
        uVar7 = libspdm_send_spdm_request(param_1,&local_5c,4,pcVar11);
        if (uVar7 >> 0x1c == 8) goto LAB_005092b8;
        libspdm_release_sender_buffer(param_1);
        pcVar11 = *(char **)(param_1 + 0x48);
        uVar7 = libspdm_acquire_receiver_buffer(param_1,local_88,local_80);
        if (uVar7 >> 0x1c != 8) {
          if (local_40[0] < uVar10) {
            libspdm_debug_assert
                      ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_key_update.c"
                       ,0x8e,"message_size >= transport_header_size");
          }
          local_50 = local_40[0];
          local_58 = local_48;
          uVar7 = libspdm_receive_spdm_response(param_1,&local_5c,&local_50,&local_58);
          if (uVar7 >> 0x1c != 8) {
            if (local_58[1] == '\x7f') {
              uVar7 = libspdm_handle_error_response_main
                                (param_1,&local_5c,&local_50,&local_58,0xe9,0x69);
              if (uVar7 >> 0x1c != 8) {
LAB_005093eb:
                if (param_3 == '\0') {
                  libspdm_debug_print(0x40,
                                      "libspdm_activate_update_session_data_key[%x] Responder new\n"
                                      ,local_5c);
                  cVar5 = libspdm_activate_update_session_data_key
                                    (*(undefined8 *)(lVar8 + 0x1f0),1,1);
                  if (cVar5 == '\0') goto LAB_0050939c;
                }
                libspdm_debug_print(0x40,"libspdm_create_update_session_data_key[%x] Requester\n",
                                    local_5c);
                cVar5 = libspdm_create_update_session_data_key(*(undefined8 *)(lVar8 + 0x1f0),0);
                if (cVar5 == '\0') goto LAB_0050939c;
                libspdm_debug_print(0x40,
                                    "libspdm_activate_update_session_data_key[%x] Requester new\n",
                                    local_5c);
                cVar5 = libspdm_activate_update_session_data_key(*(undefined8 *)(lVar8 + 0x1f0),0,1)
                ;
                if (cVar5 == '\0') goto LAB_0050939c;
                libspdm_append_msg_log(param_1,local_58,local_50);
                libspdm_release_receiver_buffer(param_1);
                goto LAB_00508dcc;
              }
            }
            else {
              uVar7 = 0x80010006;
              if (local_50 == 4) {
                if ((((*local_58 == *pcVar11) && (local_58[1] == 'i')) &&
                    (local_58[2] == pcVar11[2])) && (local_58[3] == pcVar11[3])) goto LAB_005093eb;
                uVar7 = 0x80010005;
              }
            }
          }
          if (param_3 == '\0') {
            libspdm_debug_print(0x40,"libspdm_activate_update_session_data_key[%x] Responder old\n",
                                local_5c);
            cVar4 = libspdm_activate_update_session_data_key(*(undefined8 *)(lVar8 + 0x1f0),1,0);
            if (cVar4 == '\0') {
LAB_0050939c:
              libspdm_release_receiver_buffer(param_1);
              return 0x80020000;
            }
          }
          goto LAB_0050918c;
        }
      }
    }
    else {
LAB_00508dcc:
      local_80 = &local_48;
      local_88 = local_40;
      uVar10 = (ulong)*(uint *)(param_1 + 0x11c);
      uVar7 = libspdm_acquire_sender_buffer(param_1,local_88,local_80);
      local_6d = cVar4;
      if (uVar7 >> 0x1c != 8) {
        uVar9 = (ulong)*(uint *)(param_1 + 0x120);
        if (local_40[0] < uVar10 + uVar9) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_key_update.c"
                     ,0xee,
                     "message_size >= transport_header_size + spdm_context->local_context.capability.transport_tail_size"
                    );
          uVar9 = (ulong)*(uint *)(param_1 + 0x120);
        }
        pcVar11 = local_48 + uVar10;
        if ((local_40[0] - uVar10) - uVar9 < 4) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_key_update.c"
                     ,0xf4,"spdm_request_size >= sizeof(spdm_key_update_request_t)");
        }
        cVar4 = libspdm_get_connection_version(param_1);
        pcVar11[3] = '\x01';
        *pcVar11 = cVar4;
        pcVar11[1] = -0x17;
        pcVar11[2] = '\x03';
        local_6d = libspdm_get_random_number(1,pcVar11 + 3);
        if (local_6d == '\0') {
LAB_00509260:
          libspdm_release_sender_buffer(param_1);
          return 0x80060000;
        }
        uVar7 = libspdm_send_spdm_request(param_1,&local_5c,4,pcVar11);
        if (uVar7 >> 0x1c == 8) {
LAB_005092b8:
          libspdm_release_sender_buffer(param_1);
        }
        else {
          libspdm_release_sender_buffer(param_1);
          pcVar11 = *(char **)(param_1 + 0x48);
          uVar7 = libspdm_acquire_receiver_buffer(param_1,local_88,local_80);
          if (uVar7 >> 0x1c != 8) {
            if (local_40[0] < uVar10) {
              libspdm_debug_assert
                        ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_key_update.c"
                         ,0x10f,"message_size >= transport_header_size");
            }
            local_50 = local_40[0];
            local_58 = local_48;
            uVar7 = libspdm_receive_spdm_response(param_1,&local_5c,&local_50,&local_58);
            if (uVar7 >> 0x1c != 8) {
              if ((local_58[1] != '\x7f') ||
                 (uVar7 = libspdm_handle_error_response_main
                                    (param_1,&local_5c,&local_50,&local_58,0xe9,0x69),
                 uVar7 >> 0x1c != 8)) {
                if (local_50 != 4) {
                  libspdm_debug_print(0x40,"SpdmVerifyKey[%x] Failed\n",local_5c);
                  libspdm_release_receiver_buffer(param_1);
                  return 0x80010006;
                }
                if (*local_58 == *pcVar11) {
                  if (((local_58[1] == 'i') && (local_58[2] == pcVar11[2])) &&
                     (local_58[3] == pcVar11[3])) {
                    libspdm_debug_print(0x40,"SpdmVerifyKey[%x] Success\n",local_5c);
                    libspdm_append_msg_log(param_1,local_58,local_50);
                    libspdm_release_receiver_buffer(param_1);
                    return 0;
                  }
                  libspdm_debug_print(0x40,"SpdmVerifyKey[%x] Failed\n",local_5c);
                }
                libspdm_release_receiver_buffer(param_1);
                return 0x80010005;
              }
              libspdm_debug_print(0x40,"SpdmVerifyKey[%x] Failed\n",local_5c);
            }
LAB_0050918c:
            libspdm_release_receiver_buffer(param_1);
          }
        }
      }
    }
    if (uVar7 != 0x80010008) {
      return uVar7;
    }
    libspdm_sleep(uVar2);
    if (uVar12 == 0) {
      return 0x80010008;
    }
    uVar12 = uVar12 - 1;
  } while( true );
}


// ===== 005094d0 libspdm_negotiate_algorithms =====

uint libspdm_negotiate_algorithms(long param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  ulong uVar10;
  byte *pbVar11;
  ulong uVar12;
  ulong uVar13;
  byte *pbVar14;
  byte *pbVar15;
  bool bVar16;
  byte *local_58;
  byte *local_50;
  byte *local_48;
  byte *local_40 [2];
  
  uVar4 = *(undefined8 *)(param_1 + 0xb28);
  *(undefined1 *)(param_1 + 0xb30) = 0;
  uVar12 = (ulong)*(byte *)(param_1 + 0xb25);
  do {
    if (*(int *)(param_1 + 0x238) != 2) {
      return 0x80010003;
    }
    libspdm_reset_message_buffer_via_request_code(param_1,0,0xe3);
    pbVar11 = (byte *)(ulong)*(uint *)(param_1 + 0x11c);
    uVar8 = libspdm_acquire_sender_buffer(param_1,local_40,&local_48);
    if (uVar8 >> 0x1c != 8) {
      uVar10 = (ulong)*(uint *)(param_1 + 0x120);
      if (local_40[0] < pbVar11 + uVar10) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_negotiate_algorithms.c"
                   ,0x67,
                   "message_size >= transport_header_size + spdm_context->local_context.capability.transport_tail_size"
                  );
        uVar10 = (ulong)*(uint *)(param_1 + 0x120);
      }
      pbVar15 = local_40[0] + (-uVar10 - (long)pbVar11);
      pbVar14 = local_48 + (long)pbVar11;
      if (pbVar15 < (byte *)0x20) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_negotiate_algorithms.c"
                   ,0x6d,"spdm_request_size >= sizeof(spdm_negotiate_algorithms_request_t)");
      }
      libspdm_zero_mem(pbVar14);
      bVar5 = libspdm_get_connection_version(param_1);
      *pbVar14 = bVar5;
      if (bVar5 < 0x11) {
        pbVar14[2] = 0;
        pbVar14[4] = 0x20;
        pbVar14[5] = 0;
        if (pbVar15 < (byte *)0x20) goto LAB_00509c10;
        pbVar14[1] = 0xe3;
        pbVar14[3] = 0;
        pbVar14[6] = *(byte *)(param_1 + 0x128);
        *(undefined4 *)(pbVar14 + 8) = *(undefined4 *)(param_1 + 0x130);
        *(undefined4 *)(pbVar14 + 0xc) = *(undefined4 *)(param_1 + 0x134);
        pbVar14[0x1c] = 0;
        pbVar14[0x1d] = 0;
      }
      else {
        bVar6 = ((((*(short *)(param_1 + 0x138) != 0) - (*(short *)(param_1 + 0x13a) == 0)) -
                 (*(short *)(param_1 + 0x13c) == 0)) + '\x03') - (*(short *)(param_1 + 0x13e) == 0);
        pbVar14[2] = bVar6;
        bVar6 = 0xc - ('\x04' - bVar6);
        *(ushort *)(pbVar14 + 4) = (ushort)bVar6 << 2;
        if (pbVar15 < (byte *)((ulong)bVar6 << 2)) {
LAB_00509c10:
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_negotiate_algorithms.c"
                     ,0x8b,"spdm_request_size >= spdm_request->length");
          bVar5 = *pbVar14;
        }
        pbVar14[1] = 0xe3;
        pbVar14[3] = 0;
        pbVar14[6] = *(byte *)(param_1 + 0x128);
        if (bVar5 < 0x12) {
LAB_005096a0:
          *(undefined4 *)(pbVar14 + 8) = *(undefined4 *)(param_1 + 0x130);
          uVar3 = *(undefined4 *)(param_1 + 0x134);
          pbVar14[0x1c] = 0;
          pbVar14[0x1d] = 0;
          *(undefined4 *)(pbVar14 + 0xc) = uVar3;
          if (bVar5 < 0x11) goto LAB_0050978b;
        }
        else {
          pbVar14[7] = *(byte *)(param_1 + 0x129) & 0xf;
          if (bVar5 != 0x12) {
            pbVar14[7] = *(byte *)(param_1 + 0x129);
            pbVar14[0x1f] = *(byte *)(param_1 + 0x12a);
            uVar8 = *(uint *)(param_1 + 0x254) & 0xc000000;
            if (uVar8 == 0x4000000) {
LAB_00509c46:
              *(undefined1 *)(param_1 + 0x64b) = 1;
              bVar5 = *pbVar14;
              pbVar14[7] = pbVar14[7] | 0x10;
            }
            else {
              if (uVar8 == 0x8000000) {
                if ((*(byte *)(param_1 + 0x129) & 0x10) != 0) goto LAB_00509c46;
              }
              else if (uVar8 != 0) {
                return 0x80010005;
              }
              *(undefined1 *)(param_1 + 0x64b) = 0;
              bVar5 = *pbVar14;
              pbVar14[7] = pbVar14[7] & 0xef;
            }
            goto LAB_005096a0;
          }
          *(undefined4 *)(pbVar14 + 8) = *(undefined4 *)(param_1 + 0x130);
          uVar3 = *(undefined4 *)(param_1 + 0x134);
          pbVar14[0x1c] = 0;
          pbVar14[0x1d] = 0;
          *(undefined4 *)(pbVar14 + 0xc) = uVar3;
        }
        bVar16 = *(short *)(param_1 + 0x138) != 0;
        if (bVar16) {
          pbVar14[0x20] = 2;
          pbVar14[0x21] = 0x20;
          *(undefined2 *)(pbVar14 + 0x22) = *(undefined2 *)(param_1 + 0x138);
        }
        uVar10 = (ulong)bVar16;
        if (*(short *)(param_1 + 0x13a) != 0) {
          (pbVar14 + uVar10 * 4 + 0x20)[0] = 3;
          (pbVar14 + uVar10 * 4 + 0x20)[1] = 0x20;
          *(undefined2 *)(pbVar14 + uVar10 * 4 + 0x22) = *(undefined2 *)(param_1 + 0x13a);
          uVar10 = uVar10 + 1;
        }
        if (*(short *)(param_1 + 0x13c) != 0) {
          (pbVar14 + uVar10 * 4 + 0x20)[0] = 4;
          (pbVar14 + uVar10 * 4 + 0x20)[1] = 0x20;
          *(undefined2 *)(pbVar14 + uVar10 * 4 + 0x22) = *(undefined2 *)(param_1 + 0x13c);
          uVar10 = uVar10 + 1;
        }
        if (*(short *)(param_1 + 0x13e) != 0) {
          (pbVar14 + uVar10 * 4 + 0x20)[0] = 5;
          (pbVar14 + uVar10 * 4 + 0x20)[1] = 0x20;
          *(undefined2 *)(pbVar14 + uVar10 * 4 + 0x22) = *(undefined2 *)(param_1 + 0x13e);
          uVar10 = uVar10 + 1;
        }
        if (pbVar14[2] != uVar10) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_negotiate_algorithms.c"
                     ,0xdb,"index == spdm_request->header.param1");
        }
      }
LAB_0050978b:
      uVar1 = *(undefined2 *)(pbVar14 + 4);
      uVar8 = libspdm_send_spdm_request(param_1,0,uVar1,pbVar14);
      if (uVar8 >> 0x1c == 8) {
        libspdm_release_sender_buffer(param_1);
      }
      else {
        libspdm_release_sender_buffer(param_1);
        pbVar14 = *(byte **)(param_1 + 0x48);
        uVar8 = libspdm_acquire_receiver_buffer(param_1,local_40,&local_48);
        if (uVar8 >> 0x1c != 8) {
          if (local_40[0] < pbVar11) {
            libspdm_debug_assert
                      ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_negotiate_algorithms.c"
                       ,0xed,"message_size >= transport_header_size");
          }
          local_50 = local_40[0];
          local_58 = local_48;
          uVar8 = libspdm_receive_spdm_response(param_1,0,&local_50,&local_58);
          if (uVar8 >> 0x1c == 8) {
LAB_00509b36:
            libspdm_release_receiver_buffer(param_1);
          }
          else {
            if ((byte *)0x3 < local_50) {
              if (*local_58 != *pbVar14) {
LAB_00509b30:
                uVar8 = 0x80010005;
                goto LAB_00509b36;
              }
              if (local_58[1] == 0x7f) {
                uVar8 = libspdm_handle_simple_error_response(param_1);
                if (uVar8 >> 0x1c == 8) goto LAB_00509b36;
              }
              else if (local_58[1] != 99) goto LAB_00509b30;
              if ((byte *)0x23 < local_50) {
                bVar5 = local_58[6];
                if ((((((bVar5 != 0) && ((bVar5 - 1 & bVar5) != 0)) ||
                      ((0x11 < *pbVar14 &&
                       ((bVar5 = local_58[7] & 0xf, (local_58[7] & 0xf) != 0 &&
                        ((bVar5 - 1 & bVar5) != 0)))))) ||
                     ((uVar8 = *(uint *)(local_58 + 8), uVar8 != 0 && ((uVar8 - 1 & uVar8) != 0))))
                    || (((uVar8 = *(uint *)(local_58 + 0xc), uVar8 != 0 &&
                         ((uVar8 - 1 & uVar8) != 0)) ||
                        ((uVar8 = *(uint *)(local_58 + 0x10), uVar8 != 0 &&
                         ((uVar8 - 1 & uVar8) != 0)))))) ||
                   ((local_58[0x20] != 0 || (local_58[0x21] != 0)))) goto LAB_00509b30;
                uVar10 = (ulong)local_58[2];
                if ((byte *)(uVar10 * 4 + 0x24) <= local_50) {
                  if ((*local_58 < 0x11) || (uVar10 == 0)) {
                    local_50 = (byte *)0x24;
                  }
                  else {
                    uVar13 = 0;
                    pbVar11 = local_58 + 0x24;
                    bVar5 = local_58[0x24];
                    do {
                      pbVar15 = pbVar11;
                      if ((local_58 + (long)local_50 < pbVar15) ||
                         (uVar13 == (ulong)(local_50 + -0x24) >> 2)) goto LAB_00509d40;
                      bVar6 = *pbVar15;
                      if (((3 < (byte)(bVar6 - 2)) ||
                          ((((uVar13 != 0 && (bVar6 <= bVar5)) || (pbVar15[1] >> 4 != 2)) ||
                           ((pbVar15[1] & 0xf) != 0)))) ||
                         ((uVar2 = *(ushort *)(pbVar15 + 2), uVar2 != 0 &&
                          ((uVar2 - 1 & uVar2) != 0)))) goto LAB_00509b30;
                      uVar13 = uVar13 + 1;
                      pbVar11 = pbVar15 + 4;
                      bVar5 = bVar6;
                    } while (uVar10 != uVar13);
                    local_50 = pbVar15 + (4 - (long)local_58);
                  }
                  if ((byte *)(ulong)*(ushort *)(local_58 + 4) == local_50) {
                    uVar8 = libspdm_append_message_a(param_1,pbVar14,uVar1);
                    if ((uVar8 >> 0x1c == 8) ||
                       (uVar8 = libspdm_append_message_a(param_1,local_58,local_50),
                       uVar8 >> 0x1c == 8)) goto LAB_00509b36;
                    *(byte *)(param_1 + 0x270) = local_58[6];
                    if ((0x11 < *local_58) &&
                       (*(byte *)(param_1 + 0x271) = local_58[7] & 0xf, 0x12 < *local_58)) {
                      *(byte *)(param_1 + 0x271) = local_58[7];
                      *(byte *)(param_1 + 0x272) = local_58[0x1f];
                    }
                    *(undefined4 *)(param_1 + 0x274) = *(undefined4 *)(local_58 + 8);
                    *(undefined4 *)(param_1 + 0x278) = *(undefined4 *)(local_58 + 0xc);
                    *(undefined4 *)(param_1 + 0x27c) = *(undefined4 *)(local_58 + 0x10);
                    cVar7 = libspdm_is_capabilities_flag_supported(param_1,1,0,0x18);
                    if ((cVar7 == '\0') || (pbVar14[6] == 0)) {
                      if (*(char *)(param_1 + 0x270) == '\0') {
LAB_005099e6:
                        cVar7 = libspdm_is_capabilities_flag_supported(param_1,1,0,2);
                        if ((((((cVar7 == '\0') &&
                               (cVar7 = libspdm_is_capabilities_flag_supported(param_1,1,0,4),
                               cVar7 == '\0')) &&
                              (cVar7 = libspdm_is_capabilities_flag_supported(param_1,1,0,0x10),
                              cVar7 == '\0')) &&
                             ((cVar7 = libspdm_is_capabilities_flag_supported(param_1,1,0x200,0x200)
                              , cVar7 == '\0' &&
                              (cVar7 = libspdm_is_capabilities_flag_supported(param_1,1,0xc00,0xc00)
                              , cVar7 == '\0')))) ||
                            ((iVar9 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c)),
                             iVar9 != 0 &&
                             ((*(uint *)(param_1 + 0x134) & *(uint *)(param_1 + 0x27c)) != 0)))) &&
                           (((((cVar7 = libspdm_is_capabilities_flag_supported(param_1,1,0,2),
                               cVar7 == '\0' &&
                               (cVar7 = libspdm_is_capabilities_flag_supported(param_1,1,0,4),
                               cVar7 == '\0')) &&
                              (cVar7 = libspdm_is_capabilities_flag_supported(param_1,1,0,0x10),
                              cVar7 == '\0')) &&
                             (cVar7 = libspdm_is_capabilities_flag_supported(param_1,1,0x200,0x200),
                             cVar7 == '\0')) ||
                            ((iVar9 = libspdm_get_asym_signature_size(), iVar9 != 0 &&
                             ((*(uint *)(param_1 + 0x130) & *(uint *)(param_1 + 0x278)) != 0)))))) {
                          if (*local_58 < 0x11) {
                            *(undefined1 *)(param_1 + 0x271) = 0;
                            *(undefined8 *)(param_1 + 0x280) = 0;
LAB_0050a057:
                            uVar8 = 0;
                            *(undefined4 *)(param_1 + 0x238) = 3;
                            libspdm_append_msg_log(param_1,local_58,local_50);
                            goto LAB_00509b36;
                          }
                          uVar10 = (ulong)local_58[2];
                          pbVar11 = local_58 +
                                    ((ulong)local_58[0x20] + (ulong)local_58[0x21]) * 4 + 0x24;
                          for (uVar13 = 0; uVar13 < uVar10; uVar13 = uVar13 + 1) {
                            bVar5 = *pbVar11;
                            if (bVar5 == 4) {
                              *(undefined2 *)(param_1 + 0x284) = *(undefined2 *)(pbVar11 + 2);
                              uVar10 = (ulong)local_58[2];
                            }
                            else if (bVar5 < 5) {
                              if (bVar5 == 2) {
                                *(undefined2 *)(param_1 + 0x280) = *(undefined2 *)(pbVar11 + 2);
                                uVar10 = (ulong)local_58[2];
                              }
                              else if (bVar5 == 3) {
                                *(undefined2 *)(param_1 + 0x282) = *(undefined2 *)(pbVar11 + 2);
                                uVar10 = (ulong)local_58[2];
                              }
                            }
                            else if (bVar5 == 5) {
                              *(undefined2 *)(param_1 + 0x286) = *(undefined2 *)(pbVar11 + 2);
                              uVar10 = (ulong)local_58[2];
                            }
                            pbVar11 = pbVar11 + (ulong)(pbVar11[1] & 0xf) * 4 + 4;
                          }
                          cVar7 = libspdm_is_capabilities_flag_supported(param_1,1,0x200,0x200);
                          if ((((cVar7 == '\0') ||
                               ((iVar9 = libspdm_get_dhe_pub_key_size
                                                   (*(undefined2 *)(param_1 + 0x280)), iVar9 != 0 &&
                                ((*(ushort *)(param_1 + 0x138) & *(ushort *)(param_1 + 0x280)) != 0)
                                ))) && (((cVar7 = libspdm_is_capabilities_flag_supported
                                                            (param_1,1,0x40,0x40), cVar7 == '\0' &&
                                         (cVar7 = libspdm_is_capabilities_flag_supported
                                                            (param_1,1,0x80,0x80), cVar7 == '\0'))
                                        || ((iVar9 = libspdm_get_aead_key_size
                                                               (*(undefined2 *)(param_1 + 0x282)),
                                            iVar9 != 0 &&
                                            ((*(ushort *)(param_1 + 0x13a) &
                                             *(ushort *)(param_1 + 0x282)) != 0)))))) &&
                             ((cVar7 = libspdm_is_capabilities_flag_supported(param_1,1,0x100,0x100)
                              , cVar7 == '\0' ||
                              ((iVar9 = libspdm_get_req_asym_signature_size
                                                  (*(undefined2 *)(param_1 + 0x284)), iVar9 != 0 &&
                               ((*(ushort *)(param_1 + 0x13c) & *(ushort *)(param_1 + 0x284)) != 0))
                              )))) {
                            cVar7 = libspdm_is_capabilities_flag_supported(param_1,1,0x200,0x200);
                            if ((cVar7 != '\0') ||
                               (cVar7 = libspdm_is_capabilities_flag_supported
                                                  (param_1,1,0xc00,0xc00), cVar7 != '\0')) {
                              if ((*(short *)(param_1 + 0x286) != 1) ||
                                 ((*(byte *)(param_1 + 0x13e) & 1) == 0)) goto LAB_00509e10;
                              if (0x11 < *local_58) {
                                if ((*(byte *)(param_1 + 0x271) & 0xf) != 2) goto LAB_00509e10;
                                if (*local_58 != 0x12) {
                                  cVar7 = libspdm_is_capabilities_flag_supported
                                                    (param_1,1,0,0x1000000);
                                  if ((cVar7 == '\0') || (pbVar14[0x1f] == 0)) {
                                    if (*(char *)(param_1 + 0x272) == '\0') goto LAB_0050a021;
                                  }
                                  else if (*(char *)(param_1 + 0x272) == '\x01') goto LAB_0050a021;
                                  goto LAB_00509b30;
                                }
                              }
                            }
LAB_0050a021:
                            if (*pbVar14 < 0x13) goto LAB_0050a057;
                            uVar8 = *(uint *)(param_1 + 0x10c) & 0xc000000;
                            if ((*(byte *)(param_1 + 0x271) & 0x10) == 0) {
                              if (uVar8 != 0x4000000) {
                                *(undefined1 *)(param_1 + 0x64a) = 0;
                                goto LAB_0050a057;
                              }
                            }
                            else if (uVar8 != 0) {
                              *(undefined1 *)(param_1 + 0x64a) = 1;
                              goto LAB_0050a057;
                            }
                          }
                        }
LAB_00509e10:
                        uVar8 = 0x80010007;
                        goto LAB_00509b36;
                      }
                    }
                    else if (*(char *)(param_1 + 0x270) == '\x01') {
                      iVar9 = libspdm_get_measurement_hash_size(*(undefined4 *)(param_1 + 0x274));
                      if (iVar9 != 0) goto LAB_005099e6;
                      goto LAB_00509e10;
                    }
                    goto LAB_00509b30;
                  }
                }
              }
            }
LAB_00509d40:
            uVar8 = 0x80010006;
            libspdm_release_receiver_buffer(param_1);
          }
        }
      }
    }
    if (uVar8 != 0x80010008) {
      return uVar8;
    }
    libspdm_sleep(uVar4);
    if (uVar12 == 0) {
      return 0x80010008;
    }
    uVar12 = uVar12 - 1;
  } while( true );
}


// ===== 0050a110 libspdm_send_request =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint libspdm_send_request
               (long param_1,undefined4 *param_2,undefined1 param_3,undefined8 param_4,long param_5)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  ulong uVar5;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  long local_50;
  undefined8 local_48;
  undefined8 local_40 [2];
  
  uVar1 = *(undefined1 *)(param_5 + 1);
  uVar4 = libspdm_get_code_str(uVar1);
  if (param_2 == (undefined4 *)0x0) {
    libspdm_debug_print(0x40,"libspdm_send_spdm_request[%x] msg %s(0x%x), size (0x%zx): \n",0,uVar4,
                        uVar1,param_4);
    libspdm_internal_dump_hex(param_5,param_4);
    libspdm_get_scratch_buffer(param_1,&local_58,&local_50);
    libspdm_get_sender_buffer(param_1,&local_48,local_40);
    local_68 = local_48;
    local_60 = local_40[0];
  }
  else {
    libspdm_debug_print(0x40,"libspdm_send_spdm_request[%x] msg %s(0x%x), size (0x%zx): \n",*param_2
                        ,uVar4,uVar1,param_4);
    libspdm_internal_dump_hex(param_5,param_4);
    uVar5 = (ulong)*(uint *)(param_1 + 0x11c);
    libspdm_get_scratch_buffer(param_1,&local_58,&local_50);
    libspdm_get_sender_buffer(param_1,&local_48,local_40);
    local_68 = local_48;
    local_60 = local_40[0];
    libspdm_copy_mem(local_58 + uVar5,local_50 - uVar5,param_5,param_4);
    param_5 = uVar5 + local_58;
  }
  if ((1 < (byte)(*(char *)(param_5 + 1) + 0x7bU)) && (*(char *)(param_5 + 1) != -1)) {
    uVar3 = libspdm_get_scratch_buffer_last_spdm_request_capacity(param_1);
    libspdm_copy_mem(*(undefined8 *)(param_1 + 0x48),uVar3,param_5,param_4);
    *(undefined8 *)(param_1 + 0x50) = param_4;
  }
  uVar2 = (**(code **)(param_1 + 0x38))(param_1,param_2,param_3,1,param_4,param_5,&local_60);
  if (uVar2 >> 0x1c == 8) {
    libspdm_debug_print(0x40,"transport_encode_message status - %xu\n",uVar2,&local_68);
    if ((param_2 != (undefined4 *)0x0) && ((uVar2 & 0xfffffffd) == 0x80020000)) {
      libspdm_free_session_id(param_1,*param_2);
    }
  }
  else {
    uVar2 = (**(code **)(param_1 + 8))(param_1,local_60,local_68,*(undefined8 *)(param_1 + 0x100));
    if (uVar2 >> 0x1c == 8) {
      uVar3 = 0;
      if (param_2 != (undefined4 *)0x0) {
        uVar3 = *param_2;
      }
      libspdm_debug_print(0x40,"libspdm_send_spdm_request[%x] status - %xu\n",uVar3,uVar2);
    }
  }
  return uVar2;
}


// ===== 0050a360 libspdm_receive_response =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint libspdm_receive_response(long param_1,int *param_2,char param_3,long *param_4,long *param_5)

{
  undefined1 uVar1;
  char cVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  int iVar7;
  int iVar8;
  ulong uVar9;
  undefined8 extraout_RDX;
  long lVar10;
  long *plVar11;
  char local_61;
  long local_60;
  long local_58;
  int *local_50;
  long local_48;
  long local_40 [2];
  
  if (*(char *)(param_1 + 0xb30) == '\0') {
    uVar9 = (ulong)*(uint *)(param_1 + 0x108);
  }
  else {
    uVar9 = 1L << (*(byte *)(param_1 + 0x240) & 0x3f);
  }
  local_60 = *param_5;
  local_58 = *param_4;
  uVar3 = (**(code **)(param_1 + 0x10))
                    (param_1,&local_58,&local_60,uVar9 + *(long *)(param_1 + 0x100));
  if (uVar3 >> 0x1c == 8) {
    iVar8 = 0;
    if (param_2 != (int *)0x0) {
      iVar8 = *param_2;
    }
    libspdm_debug_print(0x40,"libspdm_receive_spdm_response[%x] status - %xu\n",iVar8,uVar3);
    return uVar3;
  }
  local_61 = '\0';
  uVar3 = *(uint *)(param_1 + 0x11c);
  local_50 = (int *)0x0;
  libspdm_get_scratch_buffer(param_1,&local_48,local_40);
  *param_5 = local_48 + (ulong)uVar3;
  lVar4 = local_40[0] - (ulong)uVar3;
  *param_4 = lVar4;
  lVar10 = *param_5;
  plVar11 = param_4;
  uVar3 = (**(code **)(param_1 + 0x40))
                    (param_1,&local_50,&local_61,0,local_58,local_60,param_4,param_5);
  cVar2 = '\0';
  lVar5 = 0;
  if (uVar3 == 0x80010011) {
    if (local_50 == (int *)0x0) {
      return 0x80010003;
    }
    lVar5 = libspdm_get_secured_message_context_via_session_id
                      (param_1,*local_50,extraout_RDX,plVar11);
    if (lVar5 == 0) {
      return 0x80010003;
    }
    cVar2 = libspdm_activate_update_session_data_key(lVar5,1,0);
    if (cVar2 == '\0') {
      return 0x80010003;
    }
    local_61 = '\0';
    local_50 = (int *)0x0;
    *param_5 = lVar10;
    *param_4 = lVar4;
    uVar3 = (**(code **)(param_1 + 0x40))
                      (param_1,&local_50,&local_61,0,local_58,local_60,param_4,param_5);
  }
  if (param_2 == (int *)0x0) {
    if (local_50 != (int *)0x0) {
      iVar7 = *local_50;
      iVar8 = 0;
LAB_0050a6a4:
      libspdm_debug_print(0x40,"libspdm_receive_spdm_response[%x] GetSessionId - %x\n",iVar8,iVar7);
      goto LAB_0050a673;
    }
    if (param_3 == '\0') {
      if (local_61 != '\0') goto LAB_0050a738;
    }
    else if (local_61 == '\0') {
LAB_0050a738:
      iVar8 = 0;
LAB_0050a660:
      libspdm_debug_print(0x40,"libspdm_receive_spdm_response[%x] app_message mismatch\n",iVar8);
LAB_0050a673:
      if (*(char *)(param_1 + 0x90) == '\x06') {
        return 0x8001000f;
      }
      return 0x80040001;
    }
    if (uVar3 >> 0x1c == 8) {
      iVar8 = 0;
      goto LAB_0050a4ae;
    }
    lVar10 = *param_4;
    uVar1 = *(undefined1 *)(*param_5 + 1);
    uVar6 = libspdm_get_code_str(uVar1);
    iVar8 = 0;
  }
  else {
    iVar8 = *param_2;
    if (local_50 == (int *)0x0) {
      libspdm_debug_print(0x40,"libspdm_receive_spdm_response[%x] GetSessionId - NULL\n");
      goto LAB_0050a673;
    }
    iVar7 = *local_50;
    if (iVar7 != iVar8) goto LAB_0050a6a4;
    if (param_3 == '\0') {
      if (local_61 != '\0') goto LAB_0050a660;
    }
    else if (local_61 == '\0') goto LAB_0050a660;
    if (uVar3 >> 0x1c == 8) {
      if (*(char *)(param_1 + 0x90) == '\x06') {
        libspdm_free_session_id(param_1,iVar8);
        iVar8 = *param_2;
      }
LAB_0050a4ae:
      libspdm_debug_print(0x40,"libspdm_receive_spdm_response[%x] status - %xu\n",iVar8,uVar3);
      goto LAB_0050a4d4;
    }
    lVar10 = *param_4;
    uVar1 = *(undefined1 *)(*param_5 + 1);
    uVar6 = libspdm_get_code_str(uVar1);
    iVar8 = *param_2;
  }
  libspdm_debug_print(0x40,"libspdm_receive_spdm_response[%x] msg %s(0x%x), size (0x%zx): \n",iVar8,
                      uVar6,uVar1,lVar10);
  libspdm_internal_dump_hex(*param_5,*param_4);
LAB_0050a4d4:
  if (cVar2 == '\0') {
    return uVar3;
  }
  if ((lVar5 != 0) && (local_50 != (int *)0x0)) {
    cVar2 = libspdm_create_update_session_data_key(lVar5,1);
    if (cVar2 == '\0') {
      return 0x80010003;
    }
    return uVar3;
  }
  return 0x80010003;
}


// ===== 0050a7a0 libspdm_send_spdm_request =====

ulong libspdm_send_spdm_request(long param_1,undefined4 *param_2,ulong param_3,long param_4)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  long lVar5;
  
  if ((((*(uint *)(param_1 + 600) < param_3) && (*(uint *)(param_1 + 600) != 0)) ||
      ((*(uint *)(param_1 + 0x114) < param_3 && (*(uint *)(param_1 + 0x114) != 0)))) &&
     (cVar1 = libspdm_is_capabilities_flag_supported(param_1,1,0x20000,0x20000), cVar1 == '\0')) {
    uVar4 = 0x80040000;
  }
  else {
    if ((param_2 != (undefined4 *)0x0) &&
       (cVar1 = libspdm_is_capabilities_flag_supported(param_1,1,0x8000,0x8000), cVar1 != '\0')) {
      lVar5 = libspdm_get_session_info_via_session_id(param_1,*param_2);
      if (lVar5 == 0) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_send_receive.c"
                   ,0x249,"session_info != NULL");
        return 0x80010003;
      }
      iVar2 = libspdm_secured_message_get_session_state(*(undefined8 *)(lVar5 + 0x1f0));
      if ((iVar2 == 1) && (*(char *)(lVar5 + 4) == '\0')) {
        param_2 = (undefined4 *)0x0;
      }
    }
    if ((*(uint *)(param_1 + 0x260) < param_3) && (*(uint *)(param_1 + 0x260) != 0)) {
      libspdm_debug_print(0x80000000,"request_size > rsp max_spdm_msg_size\n");
      uVar4 = 0x80010013;
    }
    else {
      if (*(uint *)(param_1 + 0x118) < param_3) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_send_receive.c"
                   ,0x25a,"request_size <= spdm_context->local_context.capability.max_spdm_msg_size"
                  );
      }
      uVar3 = libspdm_get_msg_log_size(param_1);
      libspdm_append_msg_log(param_1,param_4,param_3);
      if (((*(char *)(param_4 + 1) == -0x7c) || (*(char *)(param_4 + 1) == -0x1f)) ||
         (((param_3 <= *(uint *)(param_1 + 600) || (*(uint *)(param_1 + 600) == 0)) &&
          ((param_3 <= *(uint *)(param_1 + 0x114) || (*(uint *)(param_1 + 0x114) == 0)))))) {
        uVar4 = libspdm_send_request(param_1,param_2,0,param_3,param_4);
        if (((uint)(uVar4 >> 0x1c) & 0xf) != 8) {
          return uVar4;
        }
      }
      else {
        uVar4 = 0x8001000d;
      }
      *(undefined8 *)(param_1 + 0xb80) = uVar3;
    }
  }
  return uVar4;
}


// ===== 0050a9a0 libspdm_receive_spdm_response =====

undefined8
libspdm_receive_spdm_response
          (undefined8 param_1,undefined4 *param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  if ((param_2 != (undefined4 *)0x0) &&
     (cVar1 = libspdm_is_capabilities_flag_supported(param_1,1,0x8000,0x8000), cVar1 != '\0')) {
    lVar4 = libspdm_get_session_info_via_session_id(param_1,*param_2);
    if (lVar4 == 0) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_requester_lib/libspdm_req_send_receive.c"
                 ,0x2a5,"session_info != NULL");
      return 0x80010003;
    }
    iVar2 = libspdm_secured_message_get_session_state(*(undefined8 *)(lVar4 + 0x1f0));
    if ((iVar2 == 1) && (*(char *)(lVar4 + 4) == '\0')) {
      param_2 = (undefined4 *)0x0;
    }
  }
  uVar3 = libspdm_receive_response(param_1,param_2,0,param_3,param_4);
  return uVar3;
}


// ===== 0050aa70 libspdm_secured_message_get_context_size =====

undefined8 libspdm_secured_message_get_context_size(void)

{
  return 0x430;
}


// ===== 0050aa80 libspdm_secured_message_init_context =====

void libspdm_secured_message_init_context(undefined8 param_1)

{
  libspdm_zero_mem(param_1,0x430);
  return;
}


// ===== 0050aa90 libspdm_secured_message_set_use_psk =====

void libspdm_secured_message_set_use_psk(long param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x48) = param_2;
  return;
}


// ===== 0050aaa0 libspdm_secured_message_set_session_state =====

void libspdm_secured_message_set_session_state(long param_1,int param_2)

{
  *(int *)(param_1 + 0x4c) = param_2;
  if (param_2 != 2) {
    return;
  }
  libspdm_clear_handshake_secret();
  libspdm_clear_master_secret(param_1);
  return;
}


// ===== 0050aad0 libspdm_secured_message_get_session_state =====

undefined4 libspdm_secured_message_get_session_state(long param_1)

{
  return *(undefined4 *)(param_1 + 0x4c);
}


// ===== 0050aae0 libspdm_secured_message_set_session_type =====

void libspdm_secured_message_set_session_type(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}


// ===== 0050aaf0 libspdm_secured_message_set_algorithms =====

void libspdm_secured_message_set_algorithms
               (long param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4,
               undefined2 param_5,undefined2 param_6,undefined2 param_7)

{
  uint uVar1;
  
  *(undefined2 *)(param_1 + 4) = param_2;
  *(undefined2 *)(param_1 + 6) = param_3;
  *(undefined4 *)(param_1 + 8) = param_4;
  *(undefined2 *)(param_1 + 0xc) = param_5;
  *(undefined2 *)(param_1 + 0xe) = param_6;
  *(undefined2 *)(param_1 + 0x10) = param_7;
  uVar1 = libspdm_get_hash_size(param_4);
  *(ulong *)(param_1 + 0x18) = (ulong)uVar1;
  uVar1 = libspdm_get_dhe_pub_key_size(*(undefined2 *)(param_1 + 0xc));
  *(ulong *)(param_1 + 0x20) = (ulong)uVar1;
  uVar1 = libspdm_get_aead_key_size(*(undefined2 *)(param_1 + 0xe));
  *(ulong *)(param_1 + 0x28) = (ulong)uVar1;
  uVar1 = libspdm_get_aead_iv_size(*(undefined2 *)(param_1 + 0xe));
  *(ulong *)(param_1 + 0x30) = (ulong)uVar1;
  uVar1 = libspdm_get_aead_tag_size(*(undefined2 *)(param_1 + 0xe));
  *(ulong *)(param_1 + 0x38) = (ulong)uVar1;
  return;
}


// ===== 0050ab70 libspdm_secured_message_set_max_spdm_session_sequence_number =====

void libspdm_secured_message_set_max_spdm_session_sequence_number(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x40) = param_2;
  return;
}


// ===== 0050ab80 libspdm_secured_message_set_sequence_number_endian =====

void libspdm_secured_message_set_sequence_number_endian(long param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x420) = param_2;
  return;
}


// ===== 0050ab90 libspdm_secured_message_export_master_secret =====

undefined8
libspdm_secured_message_export_master_secret(long param_1,undefined8 param_2,ulong *param_3)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = *(ulong *)(param_1 + 0x18);
  uVar2 = *param_3;
  if (uVar1 < *param_3) {
    *param_3 = uVar1;
    uVar2 = uVar1;
  }
  libspdm_copy_mem(param_2,uVar2,param_1 + 0x3f0,uVar2);
  return 1;
}


// ===== 0050abd0 libspdm_secured_message_clear_export_master_secret =====

void libspdm_secured_message_clear_export_master_secret(long param_1)

{
  if (param_1 == 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_secured_message_lib/libspdm_secmes_context_data.c"
               ,0xe9,"spdm_secured_message_context != NULL");
  }
  libspdm_zero_mem(param_1 + 0x3f0,0x30);
  return;
}


// ===== 0050ac30 libspdm_secured_message_set_last_spdm_error_struct =====

void libspdm_secured_message_set_last_spdm_error_struct(long param_1,undefined8 param_2)

{
  libspdm_copy_mem(param_1 + 0x424,8,param_2,8);
  return;
}


// ===== 0050ac60 generate_iv =====

void generate_iv(ulong param_1,long param_2,undefined8 param_3,ulong param_4,byte param_5)

{
  ulong uVar1;
  long lVar2;
  undefined8 local_40;
  byte local_34 [20];
  
  local_40 = param_1;
  libspdm_copy_mem(param_2,0xc);
  if (1 < param_5) {
    if ((byte)(param_5 - 2) < 2) {
      local_40 = local_40 >> 0x38 | (local_40 & 0xff000000000000) >> 0x28 |
                 (local_40 & 0xff0000000000) >> 0x18 | (local_40 & 0xff00000000) >> 8 |
                 (local_40 & 0xff000000) << 8 | (local_40 & 0xff0000) << 0x18 |
                 (local_40 & 0xff00) << 0x28 | local_40 << 0x38;
      uVar1 = param_4 - 8;
      libspdm_copy_mem((long)&local_40 + param_4 + 4,param_4,&local_40,8);
      if (7 < param_4) {
        do {
          *(byte *)(param_2 + uVar1) = *(byte *)(param_2 + uVar1) ^ local_34[uVar1];
          uVar1 = uVar1 + 1;
        } while (param_4 != uVar1);
      }
    }
    return;
  }
  libspdm_copy_mem(local_34,0xc,&local_40,8);
  lVar2 = 0;
  do {
    *(byte *)(param_2 + lVar2) = *(byte *)(param_2 + lVar2) ^ local_34[lVar2];
    lVar2 = lVar2 + 1;
  } while (lVar2 != 8);
  return;
}


// ===== 0050ad40 libspdm_encode_secured_message =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

uint libspdm_encode_secured_message
               (int *param_1,undefined4 param_2,char param_3,long param_4,long param_5,
               ulong *param_6,undefined4 *param_7,long param_8)

{
  long lVar1;
  short *psVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  byte bVar10;
  char cVar11;
  ushort uVar12;
  uint uVar13;
  int *piVar14;
  ulong uVar15;
  ulong uVar16;
  long lVar17;
  long lVar18;
  short *psVar19;
  long *plVar20;
  int *local_98;
  uint local_5c;
  long local_58 [2];
  undefined1 local_44 [20];
  
  uVar12 = (**(code **)(param_8 + 0x18))(*(undefined2 *)((long)param_1 + 6));
  if (0x12ff < uVar12) {
    return 0x80010002;
  }
  iVar5 = *param_1;
  if (iVar5 - 1U < 2) {
    iVar6 = param_1[0x13];
  }
  else {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_secured_message_lib/libspdm_secmes_encode_decode.c"
               ,0x80,
               "(session_type == LIBSPDM_SESSION_TYPE_MAC_ONLY) || (session_type == LIBSPDM_SESSION_TYPE_ENC_MAC)"
              );
    iVar6 = param_1[0x13];
  }
  if (1 < iVar6 - 1U) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_secured_message_lib/libspdm_secmes_encode_decode.c"
               ,0x83,
               "(session_state == LIBSPDM_SESSION_STATE_HANDSHAKING) || (session_state == LIBSPDM_SESSION_STATE_ESTABLISHED)"
              );
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_secured_message_lib/libspdm_secmes_encode_decode.c"
               ,0xae,"false");
    return 0x80010003;
  }
  if (iVar6 == 2) {
    if (param_3 == '\0') {
      local_98 = param_1 + 0xb6;
      uVar16 = *(ulong *)(param_1 + 0xc2);
      piVar14 = param_1 + 0xbe;
    }
    else {
      local_98 = param_1 + 0xa8;
      uVar16 = *(ulong *)(param_1 + 0xb4);
      piVar14 = param_1 + 0xb0;
    }
LAB_0050aec5:
    if (*(ulong *)(param_1 + 0x10) <= uVar16) {
      return 0x80020002;
    }
  }
  else {
    if (param_3 == '\0') {
      local_98 = param_1 + 0x82;
      uVar16 = *(ulong *)(param_1 + 0x8e);
      piVar14 = param_1 + 0x8a;
      goto LAB_0050aec5;
    }
    local_98 = param_1 + 0x74;
    uVar16 = *(ulong *)(param_1 + 0x80);
    piVar14 = param_1 + 0x7c;
    if (*(ulong *)(param_1 + 0x10) <= uVar16) {
      return 0x80020002;
    }
  }
  lVar7 = *(long *)(param_1 + 0xe);
  uVar8 = *(undefined8 *)(param_1 + 10);
  uVar9 = *(undefined8 *)(param_1 + 0xc);
  generate_iv(uVar16,local_44,piVar14,uVar9,(char)param_1[0x108]);
  local_58[1] = 0;
  bVar10 = (**(code **)(param_8 + 8))(uVar16,local_58 + 1);
  if (8 < bVar10) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_secured_message_lib/libspdm_secmes_encode_decode.c"
               ,0xbd,"sequence_num_in_header_size <= sizeof(sequence_num_in_header)");
  }
  if (iVar6 == 1) {
    if (param_3 == '\0') {
      *(long *)(param_1 + 0x8e) = *(long *)(param_1 + 0x8e) + 1;
    }
    else {
      *(long *)(param_1 + 0x80) = *(long *)(param_1 + 0x80) + 1;
    }
  }
  else if (param_3 == '\0') {
    *(long *)(param_1 + 0xc2) = *(long *)(param_1 + 0xc2) + 1;
  }
  else {
    *(long *)(param_1 + 0xb4) = *(long *)(param_1 + 0xb4) + 1;
  }
  uVar16 = (ulong)bVar10;
  lVar17 = uVar16 + 6;
  if (iVar5 == 1) {
    lVar17 = lVar17 + param_4;
    uVar15 = lVar17 + lVar7;
    if ((*param_6 < uVar15) &&
       (libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_secured_message_lib/libspdm_secmes_encode_decode.c"
                   ,0x113,"*secured_message_size >= total_secured_message_size"), *param_6 < uVar15)
       ) goto LAB_0050b212;
    *param_6 = uVar15;
    psVar2 = (short *)((long)param_7 + uVar16 + 4);
    *param_7 = param_2;
    libspdm_copy_mem(param_7 + 1,*param_6 - 4,local_58 + 1,uVar16);
    psVar19 = psVar2 + 1;
    *psVar2 = (short)param_4 + (short)lVar7;
    libspdm_copy_mem(psVar19,(long)param_7 + (*param_6 - (long)psVar19),param_5);
    uVar3 = *(undefined2 *)((long)param_1 + 0xe);
    uVar4 = *(undefined2 *)((long)param_1 + 6);
    plVar20 = (long *)0x0;
    psVar19 = (short *)0x0;
    lVar18 = 0;
    param_5 = 0;
    lVar1 = lVar17;
  }
  else {
    if (iVar5 != 2) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_secured_message_lib/libspdm_secmes_encode_decode.c"
                 ,0x136,"false");
      return 0x80010002;
    }
    uVar13 = (**(code **)(param_8 + 0x10))();
    local_58[0] = 2;
    local_5c = 0;
    if (uVar13 != 0) {
      local_5c = 0;
      cVar11 = libspdm_get_random_number(4,&local_5c);
      if (cVar11 == '\0') {
        return 0x80060000;
      }
      uVar13 = local_5c % uVar13 + 1;
      local_5c = uVar13 & 0xff;
      local_58[0] = (ulong)(uVar13 & 0xff) + 2;
    }
    local_58[0] = local_58[0] + param_4;
    uVar15 = lVar7 + lVar17 + local_58[0];
    if ((*param_6 < uVar15) &&
       (libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_secured_message_lib/libspdm_secmes_encode_decode.c"
                   ,0xe4,"*secured_message_size >= total_secured_message_size"), *param_6 < uVar15))
    {
LAB_0050b212:
      *param_6 = uVar15;
      return 0x8001000d;
    }
    *param_6 = uVar15;
    *param_7 = param_2;
    psVar19 = (short *)((long)param_7 + uVar16 + 4);
    libspdm_copy_mem(param_7 + 1,*param_6 - 4,local_58 + 1,uVar16);
    *psVar19 = (short)local_58[0] + (short)lVar7;
    *(short *)(param_5 + -2) = (short)param_4;
    cVar11 = libspdm_get_random_number(local_5c,param_4 + param_5);
    if (cVar11 == '\0') {
      return 0x80060000;
    }
    plVar20 = local_58;
    psVar19 = psVar19 + 1;
    uVar3 = *(undefined2 *)((long)param_1 + 0xe);
    uVar4 = *(undefined2 *)((long)param_1 + 6);
    param_5 = param_5 + -2;
    lVar18 = local_58[0];
    lVar1 = local_58[0] + lVar17;
  }
  cVar11 = libspdm_aead_encryption
                     (uVar4,uVar3,local_98,uVar8,local_44,uVar9,param_7,lVar17,param_5,lVar18,
                      lVar1 + (long)param_7,lVar7,psVar19,plVar20);
  return -(uint)(cVar11 == '\0') & 0x80020000;
}


// ===== 0050b2a0 libspdm_decode_secured_message =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

undefined8
libspdm_decode_secured_message
          (int *param_1,int param_2,char param_3,ulong param_4,int *param_5,ulong *param_6,
          undefined8 *param_7,long param_8)

{
  long lVar1;
  ushort *puVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  byte bVar8;
  char cVar9;
  undefined1 uVar10;
  ushort uVar11;
  ulong uVar12;
  long lVar13;
  long lVar14;
  ulong uVar15;
  undefined8 uVar16;
  ushort *puVar17;
  int *local_a8;
  int *local_90;
  ulong local_78;
  ulong local_60 [2];
  undefined1 local_4c [4];
  int local_48;
  undefined1 local_44 [20];
  
  local_4c[0] = 0;
  local_48 = 0;
  libspdm_secured_message_set_last_spdm_error_struct(param_1,local_4c);
  local_4c[0] = 6;
  local_48 = param_2;
  uVar11 = (**(code **)(param_8 + 0x18))(*(undefined2 *)((long)param_1 + 6));
  if (0x12ff < uVar11) {
    return 0x80010002;
  }
  iVar4 = *param_1;
  if (iVar4 - 1U < 2) {
    iVar5 = param_1[0x13];
  }
  else {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_secured_message_lib/libspdm_secmes_encode_decode.c"
               ,0x185,
               "(session_type == LIBSPDM_SESSION_TYPE_MAC_ONLY) || (session_type == LIBSPDM_SESSION_TYPE_ENC_MAC)"
              );
    iVar5 = param_1[0x13];
  }
  if (1 < iVar5 - 1U) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_secured_message_lib/libspdm_secmes_encode_decode.c"
               ,0x188,
               "(session_state == LIBSPDM_SESSION_STATE_HANDSHAKING) || (session_state == LIBSPDM_SESSION_STATE_ESTABLISHED)"
              );
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_secured_message_lib/libspdm_secmes_encode_decode.c"
               ,0x1b3,"false");
    return 0x80010003;
  }
  if (iVar5 == 2) {
    if (param_3 == '\0') {
      local_a8 = param_1 + 0xb6;
      local_90 = param_1 + 0xbe;
      local_78 = *(ulong *)(param_1 + 0xc2);
    }
    else {
      local_a8 = param_1 + 0xa8;
      local_90 = param_1 + 0xb0;
      local_78 = *(ulong *)(param_1 + 0xb4);
    }
LAB_0050b469:
    if (*(ulong *)(param_1 + 0x10) <= local_78) {
LAB_0050b376:
      libspdm_secured_message_set_last_spdm_error_struct(param_1,local_4c);
      return 0x80020002;
    }
  }
  else {
    if (param_3 == '\0') {
      local_a8 = param_1 + 0x82;
      local_90 = param_1 + 0x8a;
      local_78 = *(ulong *)(param_1 + 0x8e);
      goto LAB_0050b469;
    }
    local_a8 = param_1 + 0x74;
    local_90 = param_1 + 0x7c;
    local_78 = *(ulong *)(param_1 + 0x80);
    if (*(ulong *)(param_1 + 0x10) <= local_78) goto LAB_0050b376;
  }
  uVar15 = *(ulong *)(param_1 + 0xe);
  uVar6 = *(undefined8 *)(param_1 + 10);
  uVar7 = *(undefined8 *)(param_1 + 0xc);
  generate_iv(local_78,local_44,local_90,uVar7,(char)param_1[0x108]);
  local_60[1] = 0;
  bVar8 = (**(code **)(param_8 + 8))(local_78,local_60 + 1);
  if (8 < bVar8) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_secured_message_lib/libspdm_secmes_encode_decode.c"
               ,0x1c4,"sequence_num_in_header_size <= sizeof(sequence_num_in_header)");
  }
  if (iVar5 == 1) {
    if (param_3 == '\0') {
      *(long *)(param_1 + 0x8e) = *(long *)(param_1 + 0x8e) + 1;
    }
    else {
      *(long *)(param_1 + 0x80) = *(long *)(param_1 + 0x80) + 1;
    }
  }
  else if (param_3 == '\0') {
    *(long *)(param_1 + 0xc2) = *(long *)(param_1 + 0xc2) + 1;
  }
  else {
    *(long *)(param_1 + 0xb4) = *(long *)(param_1 + 0xb4) + 1;
  }
  uVar12 = (ulong)bVar8;
  lVar1 = uVar12 + 6;
  if (iVar4 == 1) {
    if (uVar15 + lVar1 <= param_4) {
      if ((*param_5 != param_2) ||
         (cVar9 = libspdm_consttime_is_mem_equal(param_5 + 1,local_60 + 1), cVar9 == '\0'))
      goto LAB_0050b848;
      puVar17 = (ushort *)((long)param_5 + uVar12 + 4);
      uVar12 = (ulong)*puVar17;
      if ((uVar12 <= param_4 - lVar1) && (uVar15 <= uVar12)) {
        lVar14 = uVar12 + (lVar1 - uVar15);
        lVar13 = (long)param_5 + lVar14;
        cVar9 = libspdm_aead_decryption
                          (*(undefined2 *)((long)param_1 + 6),*(undefined2 *)((long)param_1 + 0xe),
                           local_a8,uVar6,local_44,uVar7,param_5,lVar14,0,0,lVar13,uVar15,0,0);
        bVar8 = *(byte *)(param_1 + 0x108);
        if (((bVar8 & 0xfd) == 0) || (local_78 != 1)) {
          if (cVar9 == '\0') goto LAB_0050b7bb;
        }
        else if (cVar9 == '\0') {
          uVar16 = 2;
          if (bVar8 != 1) {
            if (bVar8 != 3) {
              libspdm_debug_assert
                        ("src/libraries/libspdm/3.5.0/library/spdm_secured_message_lib/libspdm_secmes_encode_decode.c"
                         ,0x34,&DAT_00daa59d);
            }
            uVar16 = 0;
          }
          generate_iv(1,local_44,local_90,uVar7,uVar16);
          cVar9 = libspdm_aead_decryption
                            (*(undefined2 *)((long)param_1 + 6),*(undefined2 *)((long)param_1 + 0xe)
                             ,local_a8,uVar6,local_44,uVar7,param_5,
                             (ulong)*puVar17 + (lVar1 - uVar15),0,0,lVar13,uVar15,0,0);
          if (cVar9 == '\0') goto LAB_0050b7bb;
          if ((char)param_1[0x108] == '\x01') {
            uVar10 = 2;
          }
          else {
            if ((char)param_1[0x108] != '\x03') {
              libspdm_debug_assert
                        ("src/libraries/libspdm/3.5.0/library/spdm_secured_message_lib/libspdm_secmes_encode_decode.c"
                         ,0x34,&DAT_00daa59d);
            }
            uVar10 = 0;
          }
          *(undefined1 *)(param_1 + 0x108) = uVar10;
        }
        else {
          *(char *)(param_1 + 0x108) = (bVar8 != 1) * '\x02';
        }
        uVar15 = *puVar17 - uVar15;
        if (*param_6 < uVar15) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_secured_message_lib/libspdm_secmes_encode_decode.c"
                     ,0x2a6,"*app_message_size >= plain_text_size");
        }
LAB_0050b64f:
        *param_7 = puVar17 + 1;
        *param_6 = uVar15;
        return 0;
      }
    }
  }
  else {
    if (iVar4 != 2) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_secured_message_lib/libspdm_secmes_encode_decode.c"
                 ,0x2ac,"false");
      return 0x80010002;
    }
    if (uVar15 + lVar1 <= param_4) {
      if ((*param_5 != param_2) ||
         (cVar9 = libspdm_consttime_is_mem_equal(param_5 + 1,local_60 + 1), cVar9 == '\0')) {
LAB_0050b848:
        libspdm_secured_message_set_last_spdm_error_struct(param_1,local_4c);
        return 0x80010005;
      }
      puVar2 = (ushort *)((long)param_5 + uVar12 + 4);
      uVar12 = (ulong)*puVar2;
      if ((uVar12 <= param_4 - lVar1) && (uVar15 <= uVar12)) {
        local_60[0] = uVar12 - uVar15;
        if (*param_6 < local_60[0]) {
          return 0x8001000d;
        }
        libspdm_zero_mem(*param_7);
        puVar2 = puVar2 + 1;
        puVar17 = (ushort *)*param_7;
        lVar13 = local_60[0] + lVar1 + (long)param_5;
        cVar9 = libspdm_aead_decryption
                          (*(undefined2 *)((long)param_1 + 6),*(undefined2 *)((long)param_1 + 0xe),
                           local_a8,uVar6,local_44,uVar7,param_5,lVar1,puVar2,local_60[0],lVar13,
                           uVar15,puVar17,local_60);
        if (((*(byte *)(param_1 + 0x108) & 0xfd) == 0) || (local_78 != 1)) {
          if (cVar9 == '\0') {
LAB_0050b7bb:
            if (param_3 == '\0') {
              cVar9 = *(char *)((long)param_1 + 0x3e1);
            }
            else {
              cVar9 = (char)param_1[0xf8];
            }
            if (cVar9 != '\0') {
              return 0x80010011;
            }
            libspdm_secured_message_set_last_spdm_error_struct(param_1,local_4c);
            return 0x80020000;
          }
        }
        else {
          libspdm_debug_print(0x40,"Sequence number endianness is not determined.\n");
          libspdm_debug_print(0x40,"Attempting to determine endianness.\n");
          cVar3 = (char)param_1[0x108];
          if (cVar9 == '\0') {
            uVar16 = 2;
            if (cVar3 != '\x01') {
              if (cVar3 != '\x03') {
                libspdm_debug_assert
                          ("src/libraries/libspdm/3.5.0/library/spdm_secured_message_lib/libspdm_secmes_encode_decode.c"
                           ,0x34,&DAT_00daa59d);
              }
              uVar16 = 0;
            }
            generate_iv(1,local_44,local_90,uVar7,uVar16);
            cVar9 = libspdm_aead_decryption
                              (*(undefined2 *)((long)param_1 + 6),
                               *(undefined2 *)((long)param_1 + 0xe),local_a8,uVar6,local_44,uVar7,
                               param_5,lVar1,puVar2,local_60[0],lVar13,uVar15,puVar17,local_60);
            if (cVar9 == '\0') goto LAB_0050b7bb;
            if ((char)param_1[0x108] == '\x01') {
              uVar10 = 2;
            }
            else {
              if ((char)param_1[0x108] != '\x03') {
                libspdm_debug_assert
                          ("src/libraries/libspdm/3.5.0/library/spdm_secured_message_lib/libspdm_secmes_encode_decode.c"
                           ,0x34,&DAT_00daa59d);
              }
              uVar10 = 0;
            }
            *(undefined1 *)(param_1 + 0x108) = uVar10;
          }
          else {
            *(char *)(param_1 + 0x108) = (cVar3 != '\x01') * '\x02';
          }
        }
        uVar15 = (ulong)*puVar17;
        if (uVar15 <= local_60[0]) {
          if (*param_6 < uVar15) {
            libspdm_debug_assert
                      ("src/libraries/libspdm/3.5.0/library/spdm_secured_message_lib/libspdm_secmes_encode_decode.c"
                       ,0x245,"*app_message_size >= plain_text_size");
          }
          goto LAB_0050b64f;
        }
      }
    }
  }
  libspdm_secured_message_set_last_spdm_error_struct(param_1,local_4c);
  return 0x80010006;
}


// ===== 0050bb00 libspdm_secured_message_dhe_new =====

void libspdm_secured_message_dhe_new(undefined2 param_1,undefined2 param_2,undefined1 param_3)

{
  libspdm_dhe_new(param_1,param_2,param_3);
  return;
}


// ===== 0050bb20 libspdm_secured_message_dhe_free =====

void libspdm_secured_message_dhe_free(undefined2 param_1)

{
  libspdm_dhe_free(param_1);
  return;
}


// ===== 0050bb30 libspdm_secured_message_dhe_generate_key =====

void libspdm_secured_message_dhe_generate_key(undefined2 param_1)

{
  libspdm_dhe_generate_key(param_1);
  return;
}


// ===== 0050bb40 libspdm_secured_message_dhe_compute_key =====

ulong libspdm_secured_message_dhe_compute_key(undefined2 param_1)

{
  ulong uVar1;
  long in_R8;
  undefined1 local_78 [104];
  
  uVar1 = libspdm_dhe_compute_key(param_1);
  if ((char)uVar1 != '\0') {
    libspdm_copy_mem(in_R8 + 0x50,0x60,local_78,0x60);
    libspdm_zero_mem(local_78,0x60);
    uVar1 = uVar1 & 0xff;
    *(undefined8 *)(in_R8 + 0x20) = 0x60;
  }
  return uVar1;
}


// ===== 0050bbb0 libspdm_bin_concat =====

void libspdm_bin_concat(undefined4 param_1,undefined8 param_2,long param_3,long param_4,
                       undefined2 param_5,long param_6,long param_7,ulong *param_8)

{
  ulong uVar1;
  byte bVar2;
  long lVar3;
  undefined2 local_3a [5];
  
  lVar3 = 0;
  if (param_4 != 0) {
    lVar3 = param_6;
  }
  uVar1 = lVar3 + 10 + param_3;
  local_3a[0] = param_5;
  if (*param_8 < uVar1) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_secured_message_lib/libspdm_secmes_session.c"
               ,0x24,"*out_bin_size >= final_size");
  }
  *param_8 = uVar1;
  libspdm_copy_mem(param_7,uVar1,local_3a,2);
  libspdm_copy_mem(param_7 + 2,*param_8 - 2,"spdmx.x ",8);
  bVar2 = (byte)((uint)param_1 >> 8);
  *(byte *)(param_7 + 6) = (bVar2 >> 4) + 0x30;
  *(byte *)(param_7 + 8) = (bVar2 & 0xf) + 0x30;
  libspdm_copy_mem(param_7 + 10,*param_8 - 10,param_2,param_3);
  if (param_4 != 0) {
    libspdm_copy_mem(param_7 + 10 + param_3,(*param_8 - 10) - param_3,param_4,param_6);
  }
  return;
}


// ===== 0050bcd0 libspdm_generate_aead_key_and_iv =====

undefined4
libspdm_generate_aead_key_and_iv
          (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  ulong uVar6;
  undefined8 local_148;
  undefined8 local_140;
  undefined1 local_138 [128];
  undefined1 local_b8 [136];
  
  uVar1 = *(ulong *)(param_1 + 0x30);
  uVar2 = *(undefined8 *)(param_1 + 0x18);
  uVar3 = *(ulong *)(param_1 + 0x28);
  local_148 = 0x80;
  libspdm_bin_concat(*(undefined2 *)(param_1 + 4),&DAT_00daa61e,3,0,uVar3 & 0xffff,uVar2,local_138,
                     &local_148);
  uVar4 = local_148;
  libspdm_debug_print(0x40,"bin_str5 (0x%zx):\n",local_148);
  libspdm_internal_dump_hex(local_138,uVar4);
  uVar6 = uVar3;
  uVar5 = libspdm_hkdf_expand(*(undefined4 *)(param_1 + 8),param_2,uVar2,local_138,uVar4,param_3);
  if ((char)uVar5 != '\0') {
    libspdm_debug_print(0x40,"key (0x%zx) - ",uVar3,uVar6);
    libspdm_internal_dump_data(param_3,uVar3);
    libspdm_debug_print(0x40,&DAT_00daa644);
    local_140 = 0x80;
    libspdm_bin_concat(*(undefined2 *)(param_1 + 4),&DAT_00daa646,2,0,uVar1 & 0xffff,uVar2,local_b8,
                       &local_140);
    uVar4 = local_140;
    libspdm_debug_print(0x40,"bin_str6 (0x%zx):\n",local_140);
    libspdm_internal_dump_hex(local_b8,uVar4);
    uVar5 = libspdm_hkdf_expand(*(undefined4 *)(param_1 + 8),param_2,uVar2,local_b8,uVar4,param_4,
                                uVar1);
    if ((char)uVar5 != '\0') {
      libspdm_debug_print(0x40,"iv (0x%zx) - ",uVar1);
      libspdm_internal_dump_data(param_4,uVar1);
      libspdm_debug_print(0x40,&DAT_00daa644);
    }
  }
  return uVar5;
}


// ===== 0050bed0 libspdm_generate_finished_key =====

undefined4 libspdm_generate_finished_key(long param_1,undefined8 param_2,undefined8 param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined8 local_c0;
  undefined1 local_b8 [136];
  
  uVar1 = *(ulong *)(param_1 + 0x18);
  local_c0 = 0x80;
  libspdm_bin_concat(*(undefined2 *)(param_1 + 4),"finished",8,0,uVar1 & 0xffff,uVar1,local_b8);
  uVar2 = local_c0;
  libspdm_debug_print(0x40,"bin_str7 (0x%zx):\n",local_c0);
  libspdm_internal_dump_hex(local_b8,uVar2);
  uVar3 = libspdm_hkdf_expand(*(undefined4 *)(param_1 + 8),param_2,uVar1,local_b8,uVar2,param_3,
                              uVar1);
  if ((char)uVar3 != '\0') {
    libspdm_debug_print(0x40,"finished_key (0x%zx) - ",uVar1,&local_c0);
    libspdm_internal_dump_data(param_3,uVar1);
    libspdm_debug_print(0x40,&DAT_00daa644);
  }
  return uVar3;
}


// ===== 0050bfd0 libspdm_generate_session_handshake_key =====

ulong libspdm_generate_session_handshake_key(long param_1,undefined8 param_2)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined8 local_178;
  undefined8 local_170;
  undefined1 local_168 [48];
  undefined1 local_138 [128];
  undefined1 local_b8 [136];
  
  uVar2 = *(ulong *)(param_1 + 0x18);
  if (*(char *)(param_1 + 0x48) == '\0') {
    libspdm_debug_print(0x40,"[DHE Secret]: ");
    libspdm_internal_dump_hex_str(param_1 + 0x50,*(undefined8 *)(param_1 + 0x20));
    libspdm_debug_print(0x40,&DAT_00daa644);
    uVar4 = 0x50c043;
    libspdm_zero_mem(local_168,0x30);
    uVar3 = libspdm_hkdf_extract
                      (*(undefined4 *)(param_1 + 8),param_1 + 0x50,*(undefined8 *)(param_1 + 0x20),
                       local_168,uVar2,param_1 + 0xb0,uVar2);
    if ((char)uVar3 == '\0') {
      return uVar3;
    }
    libspdm_debug_print(0x40,"handshake_secret (0x%zx) - ",uVar2,uVar4);
    libspdm_internal_dump_data(param_1 + 0xb0,uVar2);
    libspdm_debug_print(0x40,&DAT_00daa644);
  }
  local_178 = 0x80;
  libspdm_bin_concat(*(undefined2 *)(param_1 + 4),"req hs data",0xb,param_2,uVar2 & 0xffff,uVar2,
                     local_138,&local_178);
  uVar4 = local_178;
  libspdm_debug_print(0x40,"bin_str1 (0x%zx):\n",local_178);
  libspdm_internal_dump_hex(local_138,uVar4);
  lVar1 = param_1 + 0x110;
  if ((*(char *)(param_1 + 0x48) != '\0') ||
     (uVar3 = libspdm_hkdf_expand(*(undefined4 *)(param_1 + 8),param_1 + 0xb0,uVar2,local_138,uVar4,
                                  lVar1,uVar2), (char)uVar3 != '\0')) {
    libspdm_debug_print(0x40,"request_handshake_secret (0x%zx) - ",uVar2);
    libspdm_internal_dump_data(lVar1,uVar2);
    libspdm_debug_print(0x40,&DAT_00daa644);
    local_170 = 0x80;
    libspdm_bin_concat(*(undefined2 *)(param_1 + 4),"rsp hs data",0xb,param_2,uVar2 & 0xffff,uVar2,
                       local_b8,&local_170);
    uVar4 = local_170;
    libspdm_debug_print(0x40,"bin_str2 (0x%zx):\n",local_170);
    libspdm_internal_dump_hex(local_b8,uVar4);
    if ((*(char *)(param_1 + 0x48) != '\0') ||
       (uVar3 = libspdm_hkdf_expand(*(undefined4 *)(param_1 + 8),param_1 + 0xb0,uVar2,local_b8,uVar4
                                    ,param_1 + 0x140,uVar2), (char)uVar3 != '\0')) {
      libspdm_debug_print(0x40,"response_handshake_secret (0x%zx) - ",uVar2);
      libspdm_internal_dump_data(param_1 + 0x140,uVar2);
      libspdm_debug_print(0x40,&DAT_00daa644);
      uVar3 = libspdm_generate_finished_key(param_1,lVar1,param_1 + 0x170);
      if ((((char)uVar3 != '\0') &&
          (uVar3 = libspdm_generate_finished_key(param_1,param_1 + 0x140,param_1 + 0x1a0),
          (char)uVar3 != '\0')) &&
         (uVar3 = libspdm_generate_aead_key_and_iv(param_1,lVar1,param_1 + 0x1d0,param_1 + 0x1f0),
         (char)uVar3 != '\0')) {
        *(undefined8 *)(param_1 + 0x200) = 0;
        uVar3 = libspdm_generate_aead_key_and_iv
                          (param_1,param_1 + 0x140,param_1 + 0x208,param_1 + 0x228);
        if ((char)uVar3 != '\0') {
          *(undefined8 *)(param_1 + 0x238) = 0;
          libspdm_zero_mem(param_1 + 0x50,0x60);
          return uVar3 & 0xff;
        }
      }
    }
  }
  return uVar3;
}


// ===== 0050c370 libspdm_generate_session_data_key =====

ulong libspdm_generate_session_data_key(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  char cVar5;
  byte bVar6;
  ulong uVar7;
  undefined8 *extraout_RDX;
  undefined8 *puVar8;
  undefined8 *extraout_RDX_00;
  undefined8 *extraout_RDX_01;
  undefined8 *extraout_RDX_02;
  undefined1 *local_2c0;
  undefined8 local_2b8;
  undefined8 local_2b0;
  undefined8 local_2a8;
  undefined8 local_2a0;
  undefined1 local_298 [48];
  undefined1 local_268 [48];
  undefined1 local_238 [128];
  undefined1 local_1b8 [128];
  undefined1 local_138 [128];
  undefined1 local_b8 [136];
  
  puVar3 = *(undefined8 **)(param_1 + 0x18);
  if (*(char *)(param_1 + 0x48) == '\0') {
    local_2b8 = 0x80;
    libspdm_bin_concat(*(undefined2 *)(param_1 + 4),"derived",7,0,(ulong)puVar3 & 0xffff,puVar3,
                       local_238,&local_2b8);
    uVar4 = local_2b8;
    libspdm_debug_print(0x40,"bin_str0 (0x%zx):\n",local_2b8);
    libspdm_internal_dump_hex(local_238,uVar4);
    uVar7 = libspdm_hkdf_expand(*(undefined4 *)(param_1 + 8),param_1 + 0xb0,puVar3,local_238,uVar4,
                                local_298);
    if ((char)uVar7 == '\0') {
      return uVar7;
    }
    libspdm_debug_print(0x40,"salt1 (0x%zx) - ",puVar3);
    libspdm_internal_dump_data(local_298,puVar3);
    libspdm_debug_print(0x40,&DAT_00daa644);
    libspdm_zero_mem(local_268,0x30);
    cVar5 = libspdm_hkdf_extract
                      (*(undefined4 *)(param_1 + 8),local_268,puVar3,local_298,puVar3,param_1 + 0xe0
                       ,puVar3);
    bVar6 = 0;
    puVar8 = extraout_RDX_00;
    if (cVar5 == '\0') goto LAB_0050c652;
    libspdm_debug_print(0x40,"master_secret (0x%zx) - ",puVar3);
    libspdm_internal_dump_data(param_1 + 0xe0,puVar3);
    libspdm_debug_print(0x40,&DAT_00daa644);
  }
  uVar7 = (ulong)puVar3 & 0xffff;
  puVar8 = &local_2b0;
  local_2b0 = 0x80;
  libspdm_bin_concat(*(undefined2 *)(param_1 + 4),"req app data",0xc,param_2,uVar7,puVar3,local_1b8)
  ;
  uVar4 = local_2b0;
  libspdm_debug_print(0x40,"bin_str3 (0x%zx):\n",local_2b0);
  libspdm_internal_dump_hex(local_1b8,uVar4);
  lVar1 = param_1 + 0x240;
  if (*(char *)(param_1 + 0x48) == '\0') {
    cVar5 = libspdm_hkdf_expand(*(undefined4 *)(param_1 + 8),param_1 + 0xe0,puVar3,local_1b8,uVar4,
                                lVar1,puVar3);
    bVar6 = 0;
    if (cVar5 == '\0') goto LAB_0050c652;
  }
  libspdm_debug_print(0x40,"request_data_secret (0x%zx) - ",puVar3);
  libspdm_internal_dump_data(lVar1,puVar3);
  libspdm_debug_print(0x40,&DAT_00daa644);
  local_2a8 = 0x80;
  libspdm_bin_concat(*(undefined2 *)(param_1 + 4),"rsp app data",0xc,param_2,uVar7,puVar3,local_138,
                     &local_2a8);
  uVar4 = local_2a8;
  libspdm_debug_print(0x40,"bin_str4 (0x%zx):\n",local_2a8);
  libspdm_internal_dump_hex(local_138,uVar4);
  lVar2 = param_1 + 0x270;
  if ((*(char *)(param_1 + 0x48) == '\0') &&
     (cVar5 = libspdm_hkdf_expand(*(undefined4 *)(param_1 + 8),param_1 + 0xe0,puVar3,local_138,uVar4
                                  ,lVar2,puVar3), cVar5 == '\0')) {
    bVar6 = 0;
    puVar8 = extraout_RDX_01;
  }
  else {
    libspdm_debug_print(0x40,"response_data_secret (0x%zx) - ",puVar3);
    libspdm_internal_dump_data(lVar2,puVar3);
    libspdm_debug_print(0x40,&DAT_00daa644);
    local_2a0 = 0x80;
    libspdm_bin_concat(*(undefined2 *)(param_1 + 4),"exp master",10,param_2,uVar7,puVar3,local_b8,
                       &local_2a0);
    uVar4 = local_2a0;
    libspdm_debug_print(0x40,"bin_str8 (0x%zx):\n",local_2a0);
    libspdm_internal_dump_hex(local_b8,uVar4);
    if (*(char *)(param_1 + 0x48) == '\0') {
      puVar8 = puVar3;
      cVar5 = libspdm_hkdf_expand(*(undefined4 *)(param_1 + 8),param_1 + 0xe0,puVar3,local_b8,uVar4,
                                  param_1 + 0x3f0);
      bVar6 = 0;
      if (cVar5 == '\0') goto LAB_0050c652;
    }
    libspdm_debug_print(0x40,"export_master_secret (0x%zx) - ",puVar3);
    libspdm_internal_dump_data(param_1 + 0x3f0,puVar3);
    libspdm_debug_print(0x40,&DAT_00daa644);
    cVar5 = libspdm_generate_aead_key_and_iv(param_1,lVar1,param_1 + 0x2a0,param_1 + 0x2c0);
    bVar6 = 0;
    puVar8 = extraout_RDX;
    if (cVar5 != '\0') {
      *(undefined8 *)(param_1 + 0x2d0) = 0;
      bVar6 = libspdm_generate_aead_key_and_iv(param_1,lVar2,param_1 + 0x2d8,param_1 + 0x2f8);
      puVar8 = extraout_RDX_02;
      if (bVar6 != 0) {
        *(undefined8 *)(param_1 + 0x308) = 0;
      }
    }
  }
LAB_0050c652:
  local_2c0 = local_298;
  libspdm_zero_mem(local_2c0,puVar3,puVar8);
  return (ulong)bVar6;
}


// ===== 0050c870 libspdm_create_update_session_data_key =====

undefined8 libspdm_create_update_session_data_key(long param_1,int param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 *puVar4;
  undefined8 local_c0;
  undefined1 local_b8 [136];
  
  uVar1 = *(ulong *)(param_1 + 0x18);
  local_c0 = 0x80;
  puVar4 = local_b8;
  libspdm_bin_concat(*(undefined2 *)(param_1 + 4),"traffic upd",0xb,0,uVar1 & 0xffff,uVar1);
  uVar2 = local_c0;
  libspdm_debug_print(0x40,"bin_str9 (0x%zx):\n",local_c0);
  libspdm_internal_dump_hex(local_b8,uVar2);
  if (param_2 == 0) {
    libspdm_copy_mem(param_1 + 0x310,0x30,param_1 + 0x240,0x30,puVar4,&local_c0);
    libspdm_copy_mem(param_1 + 0x370,0x20,param_1 + 0x2a0,0x20);
    libspdm_copy_mem(param_1 + 0x390,0xc,param_1 + 0x2c0,0xc);
    *(undefined8 *)(param_1 + 0x3a0) = *(undefined8 *)(param_1 + 0x2d0);
    uVar3 = libspdm_hkdf_expand(*(undefined4 *)(param_1 + 8),param_1 + 0x240,uVar1,local_b8,uVar2,
                                param_1 + 0x240,uVar1);
    if ((char)uVar3 != '\0') {
      libspdm_debug_print(0x40,"RequestDataSecretUpdate (0x%zx) - ",uVar1);
      libspdm_internal_dump_data(param_1 + 0x240,uVar1);
      libspdm_debug_print(0x40,&DAT_00daa644);
      uVar3 = libspdm_generate_aead_key_and_iv
                        (param_1,param_1 + 0x240,param_1 + 0x2a0,param_1 + 0x2c0);
      if ((char)uVar3 != '\0') {
        *(undefined8 *)(param_1 + 0x2d0) = 0;
        *(undefined1 *)(param_1 + 0x3e0) = 1;
        return uVar3;
      }
    }
  }
  else {
    uVar3 = 0;
    if (param_2 == 1) {
      libspdm_copy_mem(param_1 + 0x340,0x30,param_1 + 0x270,0x30,puVar4,&local_c0);
      libspdm_copy_mem(param_1 + 0x3a8,0x20,param_1 + 0x2d8,0x20);
      libspdm_copy_mem(param_1 + 0x3c8,0xc,param_1 + 0x2f8,0xc);
      *(undefined8 *)(param_1 + 0x3d8) = *(undefined8 *)(param_1 + 0x308);
      uVar3 = libspdm_hkdf_expand(*(undefined4 *)(param_1 + 8),param_1 + 0x270,uVar1,local_b8,uVar2,
                                  param_1 + 0x270,uVar1);
      if ((char)uVar3 != '\0') {
        libspdm_debug_print(0x40,"ResponseDataSecretUpdate (0x%zx) - ",uVar1,0x50c98b);
        libspdm_internal_dump_data(param_1 + 0x270,uVar1);
        libspdm_debug_print(0x40,&DAT_00daa644);
        uVar3 = libspdm_generate_aead_key_and_iv
                          (param_1,param_1 + 0x270,param_1 + 0x2d8,param_1 + 0x2f8);
        if ((char)uVar3 != '\0') {
          *(undefined8 *)(param_1 + 0x308) = 0;
          *(undefined1 *)(param_1 + 0x3e1) = 1;
        }
      }
    }
  }
  return uVar3;
}


// ===== 0050cb70 libspdm_clear_handshake_secret =====

void libspdm_clear_handshake_secret(long param_1)

{
  libspdm_zero_mem(param_1 + 0xb0,0x30);
  libspdm_zero_mem(param_1 + 0x110,0x130);
  *(undefined2 *)(param_1 + 0x3e0) = 0;
  return;
}


// ===== 0050cbc0 libspdm_clear_master_secret =====

void libspdm_clear_master_secret(long param_1)

{
  libspdm_zero_mem(param_1 + 0xe0,0x30);
  return;
}


// ===== 0050cbe0 libspdm_activate_update_session_data_key =====

undefined8 libspdm_activate_update_session_data_key(long param_1,int param_2,char param_3)

{
  if (param_3 == '\0') {
    if (param_2 != 0) {
      if (param_2 != 1) {
        return 1;
      }
      if (*(char *)(param_1 + 0x3e1) != '\0') {
        libspdm_copy_mem(param_1 + 0x270,0x30,param_1 + 0x340,0x30);
        libspdm_copy_mem(param_1 + 0x2d8,0x20,param_1 + 0x3a8,0x20);
        libspdm_copy_mem(param_1 + 0x2f8,0xc,param_1 + 0x3c8,0xc);
        *(undefined8 *)(param_1 + 0x308) = *(undefined8 *)(param_1 + 0x3d8);
      }
LAB_0050cccf:
      libspdm_zero_mem(param_1 + 0x340,0x30);
      libspdm_zero_mem(param_1 + 0x3a8,0x20);
      libspdm_zero_mem(param_1 + 0x3c8,0xc);
      *(undefined1 *)(param_1 + 0x3e1) = 0;
      *(undefined8 *)(param_1 + 0x3d8) = 0;
      return 1;
    }
    if (*(char *)(param_1 + 0x3e0) != '\0') {
      libspdm_copy_mem(param_1 + 0x240,0x30,param_1 + 0x310,0x30);
      libspdm_copy_mem(param_1 + 0x2a0,0x20,param_1 + 0x370,0x20);
      libspdm_copy_mem(param_1 + 0x2c0,0xc,param_1 + 0x390,0xc);
      *(undefined8 *)(param_1 + 0x2d0) = *(undefined8 *)(param_1 + 0x3a0);
    }
  }
  else if (param_2 != 0) {
    if (param_2 != 1) {
      return 1;
    }
    goto LAB_0050cccf;
  }
  libspdm_zero_mem(param_1 + 0x310,0x30);
  libspdm_zero_mem(param_1 + 0x370,0x20);
  libspdm_zero_mem(param_1 + 0x390,0xc);
  *(undefined1 *)(param_1 + 0x3e0) = 0;
  *(undefined8 *)(param_1 + 0x3a0) = 0;
  return 1;
}


// ===== 0050ce40 libspdm_hmac_all_with_request_finished_key =====

void libspdm_hmac_all_with_request_finished_key
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  libspdm_hmac_all(*(undefined4 *)(param_1 + 8),param_2,param_3,param_1 + 0x170,
                   *(undefined8 *)(param_1 + 0x18),param_4);
  return;
}


// ===== 0050ce60 libspdm_hmac_all_with_response_finished_key =====

void libspdm_hmac_all_with_response_finished_key
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  libspdm_hmac_all(*(undefined4 *)(param_1 + 8),param_2,param_3,param_1 + 0x1a0,
                   *(undefined8 *)(param_1 + 0x18),param_4);
  return;
}


// ===== 0050ce80 libspdm_consttime_is_mem_equal =====

bool libspdm_consttime_is_mem_equal(byte *param_1,byte *param_2,long param_3)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  if (param_3 != 0) {
    bVar1 = 0;
    pbVar2 = param_1;
    do {
      pbVar3 = pbVar2 + 1;
      bVar1 = bVar1 | *pbVar2 ^ *param_2;
      param_2 = param_2 + 1;
      pbVar2 = pbVar3;
    } while (param_1 + param_3 != pbVar3);
    return bVar1 == 0;
  }
  return true;
}


// ===== 0050ced0 libspdm_sleep =====

void libspdm_sleep(void)

{
  return;
}


// ===== 0050cee0 libspdm_pem_to_der =====

undefined8 libspdm_pem_to_der(long param_1,long param_2,ulong param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((param_2 == 0 || param_3 < 0x3a) || param_1 == 0) {
    return 0;
  }
  iVar1 = portMemCmp(param_1,"-----BEGIN CERTIFICATE-----\n",0x1c);
  if (iVar1 == 0) {
    iVar1 = portMemCmp(param_1 + -0x1a + param_3,"-----END CERTIFICATE-----\n",0x1a);
    if (iVar1 == 0) {
      uVar2 = libspdm_decode_base64(param_1 + 0x1c,param_2,param_3 - 0x36,param_4);
      return uVar2;
    }
  }
  return 0;
}


// ===== 0050cf80 libspdm_der_to_pem =====

undefined8 libspdm_der_to_pem(long param_1,long param_2,ulong param_3,ulong *param_4)

{
  undefined8 uVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  long local_40 [2];
  
  uVar6 = *param_4;
  if (0x1b < uVar6) {
    uVar3 = uVar6 - 0x1c;
    lVar4 = param_2 + 0x1c;
    portMemCopy(param_2,uVar6,"-----BEGIN CERTIFICATE-----\n",0x1c);
    if (param_3 != 0) {
      lVar5 = 0;
      uVar6 = 0;
      do {
        uVar7 = uVar6 + 0x30;
        lVar2 = param_3 - uVar6;
        if (uVar7 < param_3) {
          lVar2 = 0x30;
        }
        local_40[0] = uVar3 - lVar5;
        uVar1 = libspdm_encode_base64(uVar6 + param_1,lVar4 + lVar5,lVar2,local_40);
        if ((char)uVar1 == '\0') {
          return uVar1;
        }
        *(undefined1 *)(lVar4 + local_40[0] + lVar5) = 10;
        lVar5 = local_40[0] + lVar5 + 1;
        uVar6 = uVar7;
      } while (uVar7 < param_3);
      lVar4 = lVar4 + lVar5;
      uVar3 = uVar3 - lVar5;
    }
    if (0x1a < uVar3) {
      portMemCopy(lVar4,uVar3,"-----END CERTIFICATE-----\n",0x1b);
      *param_4 = (lVar4 + 0x1b) - param_2;
      return 1;
    }
  }
  return 0;
}


// ===== 0050d0d0 libspdm_ec_get_public_key_from_der =====

undefined8 libspdm_ec_get_public_key_from_der(void)

{
  libspdm_debug_assert("src/libraries/libspdm/nvidia/nvspdm_crypt_null.c",0x3b,"false");
  return 0;
}


// ===== 0050d100 libspdm_rsa_get_public_key_from_der =====

undefined8 libspdm_rsa_get_public_key_from_der(void)

{
  return 1;
}


// ===== 0050d110 nvspdm_check_and_clear_libspdm_assert =====

byte nvspdm_check_and_clear_libspdm_assert(void)

{
  byte bVar1;
  
  bVar1 = g_libspdmAssertHit;
  g_libspdmAssertHit = 0;
  return bVar1 ^ 1;
}


// ===== 0050d130 libspdm_debug_assert =====

void libspdm_debug_assert(void)

{
  nvDbg_Printf("src/libraries/libspdm/nvidia/nvspdm_debuglib.c",0x37,"libspdm_debug_assert",4,
               "NVRM: libspdm assertion hit!\n");
  g_libspdmAssertHit = 1;
  return;
}


// ===== 0050d170 libspdm_debug_print =====

void libspdm_debug_print(void)

{
  return;
}


// ===== 0050d180 libspdm_copy_mem =====

void libspdm_copy_mem(long param_1,ulong param_2,long param_3,ulong param_4)

{
  long lVar1;
  
  if ((param_1 == 0) || ((long)param_2 < 0)) {
    libspdm_debug_assert("src/libraries/libspdm/nvidia/nvspdm_memlib.c",0x62,&DAT_00daa9b5);
    return;
  }
  if (param_3 == 0) {
    libspdm_debug_assert("src/libraries/libspdm/nvidia/nvspdm_memlib.c",0x68,&DAT_00daa9b5);
    return;
  }
  if ((param_4 <= param_2) && (-1 < (long)param_4)) {
    lVar1 = portMemCopy();
    if (lVar1 != 0) {
      return;
    }
    libspdm_debug_assert("src/libraries/libspdm/nvidia/nvspdm_memlib.c",0x77,&DAT_00daa9b5);
    return;
  }
  libspdm_debug_assert("src/libraries/libspdm/nvidia/nvspdm_memlib.c",0x6f,&DAT_00daa9b5);
  return;
}


// ===== 0050d230 libspdm_zero_mem =====

void libspdm_zero_mem(undefined8 param_1,undefined8 param_2)

{
  portMemSet(param_1,0,param_2);
  return;
}


// ===== 0050d240 libspdm_requester_data_sign =====

undefined1
libspdm_requester_data_sign
          (undefined8 param_1,undefined2 param_2,char param_3,short param_4,int param_5,
          undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined8 param_9,
          undefined8 param_10)

{
  char cVar1;
  long lVar2;
  undefined1 uVar3;
  
  uVar3 = param_3 != -0x1b || (param_4 != 8 || param_5 != 2);
  if (param_3 != -0x1b || (param_4 != 8 || param_5 != 2)) {
    return 0;
  }
  lVar2 = libspdm_rsa_new();
  if (lVar2 != 0) {
    cVar1 = libspdm_rsa_set_key(lVar2,0,g_rsa3k_modulus_mutual_authentication_prod,0x180);
    uVar3 = 0;
    if (cVar1 != '\0') {
      cVar1 = libspdm_rsa_set_key(lVar2,2,g_rsa3k_private_exponent_mutual_authentication_prod,0x180)
      ;
      uVar3 = 0;
      if (cVar1 != '\0') {
        cVar1 = libspdm_rsa_set_key(lVar2,1,&g_rsa3k_public_exponent_mutual_authentication_prod,4);
        uVar3 = 0;
        if (cVar1 != '\0') {
          uVar3 = libspdm_req_asym_sign_hash
                            (param_2,0xe5,8,2,lVar2,param_7,param_8,param_9,param_10);
        }
      }
    }
    libspdm_rsa_free(lVar2);
  }
  return uVar3;
}


// ===== 0050d330 _reusemappingdbAddMappingCallback =====

undefined8
_reusemappingdbAddMappingCallback
          (long *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)_portMemAllocatorAlloc(*(undefined8 *)(param_1[1] + 0x38),0x68);
  if (puVar2 != (undefined8 *)0x0) {
    *puVar2 = param_4;
    puVar2[1] = 1;
    lVar1 = *param_1;
    puVar2[4] = param_2;
    puVar2[2] = lVar1;
    puVar2[3] = param_3;
    *param_1 = (long)puVar2;
    param_1[2] = param_1[2] + 1;
    return 0;
  }
  nvAssertFailedNoLog("pEntry != NULL","src/libraries/mapping_reuse/mapping_reuse.c",0xaa);
  return 0x51;
}


// ===== 0050d3c0 reusemappingdbInit =====

void reusemappingdbInit(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                       undefined8 param_5,undefined8 param_6)

{
  mapInitIntrusive_IMPL(param_1 + 0x20,0x18);
  mapInit_IMPL(param_1,param_2,0x10);
  *(undefined8 *)(param_1 + 0x30) = param_3;
  *(undefined8 *)(param_1 + 0x38) = param_2;
  *(undefined8 *)(param_1 + 0x40) = param_4;
  *(undefined8 *)(param_1 + 0x48) = param_5;
  *(undefined8 *)(param_1 + 0x50) = param_6;
  return;
}


// ===== 0050d430 reusemappingdbDestruct =====

void reusemappingdbDestruct(long param_1)

{
  mapDestroyIntrusive_IMPL(param_1 + 0x20);
  mapDestroy_IMPL(param_1);
  portMemSet(param_1,0,0x58);
  return;
}


// ===== 0050d470 reusemappingdbUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void reusemappingdbUnmap(long param_1,undefined8 param_2,ulong param_3,long param_4)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  long lVar4;
  bool bVar5;
  long *plVar6;
  long *plVar7;
  ulong uVar8;
  undefined8 uVar9;
  ulong uVar10;
  ulong uVar11;
  
  lVar1 = param_1 + 0x20;
  plVar6 = (long *)mapFindGEQ_IMPL(lVar1,param_3);
  uVar11 = param_3;
  if (plVar6 != (long *)0x0) {
    bVar5 = true;
    uVar10 = param_3;
    do {
      plVar7 = (long *)mapNext_IMPL(lVar1,plVar6);
      uVar8 = mapKey_IMPL(lVar1,plVar6);
      lVar4 = *plVar6;
      if ((uVar8 < param_3) || (uVar11 = lVar4 + uVar8, param_4 + param_3 < uVar11)) {
        uVar11 = uVar10;
        if (!bVar5) {
          return;
        }
        break;
      }
      if (uVar8 - uVar10 == 0) {
        plVar2 = plVar6 + 1;
        *plVar2 = *plVar2 + -1;
        lVar3 = *plVar2;
      }
      else {
        (**(code **)(param_1 + 0x48))(*(undefined8 *)(param_1 + 0x30),param_2,uVar10,uVar8 - uVar10)
        ;
        plVar2 = plVar6 + 1;
        *plVar2 = *plVar2 + -1;
        lVar3 = *plVar2;
      }
      if (lVar3 == 0) {
        lVar3 = plVar6[2];
        uVar9 = mapFind_IMPL(param_1,lVar3);
        mapRemoveIntrusive_IMPL(lVar1,plVar6);
        mapRemoveIntrusive_IMPL(uVar9,plVar6);
        (**(code **)(param_1 + 0x48))(*(undefined8 *)(param_1 + 0x30),lVar3,uVar8,lVar4);
        _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x38),plVar6);
      }
      bVar5 = false;
      uVar10 = uVar11;
      plVar6 = plVar7;
    } while (plVar7 != (long *)0x0);
  }
  if (param_4 + param_3 == uVar11) {
    return;
  }
  (**(code **)(param_1 + 0x48))
            (*(undefined8 *)(param_1 + 0x30),param_2,uVar11,(param_4 + param_3) - uVar11);
  return;
}


// ===== 0050d640 reusemappingdbMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

int reusemappingdbMap(long param_1,undefined8 param_2,ulong param_3,long param_4,long *param_5,
                     ulong param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  bool bVar9;
  uint uVar10;
  long lVar11;
  bool bVar12;
  undefined8 uStack_a0;
  long local_60;
  undefined8 *local_50;
  long local_48;
  long local_40;
  
  uVar10 = (uint)param_6 & 2;
  bVar12 = (bool)((byte)param_6 & 1 | (byte)(uVar10 >> 1));
  if (bVar12 == false) {
    nvAssertFailedNoLog("bSingleRange || bNoReuse","src/libraries/mapping_reuse/mapping_reuse.c",
                        0xd4);
    return 0x56;
  }
  uStack_a0 = 0x50d69c;
  local_60 = mapFind_IMPL();
  if (local_60 == 0) {
    local_60 = mapInsertNew_IMPL(param_1,param_2);
    uStack_a0 = 0x50d8dc;
    mapInitIntrusive_IMPL(local_60,0x40);
    if (local_60 != 0) goto LAB_0050d6ad;
    nvAssertFailedNoLog("pPhysicalMap != NULL","src/libraries/mapping_reuse/mapping_reuse.c",0xdd);
LAB_0050d903:
    iVar3 = 0x51;
  }
  else {
LAB_0050d6ad:
    bVar9 = (bool)((byte)(uVar10 >> 1) ^ 1);
    if (((param_6 & 1) != 0) && (bVar9 != false)) {
      plVar5 = (long *)mapFindLEQ_IMPL(local_60,param_3);
      bVar9 = bVar12;
      if (plVar5 == (long *)0x0) {
        uStack_a0 = 0x50d9ed;
        plVar5 = (long *)mapFindGEQ_IMPL(local_60,param_3);
        if (plVar5 == (long *)0x0) goto LAB_0050d6c4;
      }
      uVar6 = mapKey_IMPL(local_60);
      if (uVar6 < param_3) {
LAB_0050d8b0:
        if (uVar6 + *plVar5 <= param_3) {
LAB_0050d845:
          uStack_a0 = 0x50d84e;
          plVar5 = (long *)mapNext_IMPL(local_60);
          if (plVar5 == (long *)0x0) goto LAB_0050d6c4;
        }
      }
      else if (param_3 + param_4 <= uVar6) {
        if (uVar6 == param_3) goto LAB_0050d8b0;
        goto LAB_0050d845;
      }
      uVar6 = mapKey_IMPL(local_60);
      lVar4 = *plVar5;
      uStack_a0 = 0x50d885;
      uVar7 = mapKey_IMPL(param_1 + 0x20);
      if (uVar6 < param_3) {
        bVar9 = uVar6 + lVar4 <= param_3;
      }
      else if ((uVar6 < param_4 + param_3) || ((uVar6 == param_3 && (param_3 < lVar4 + param_3)))) {
        if ((lVar4 == param_4) && (uVar6 == param_3)) {
          param_5[1] = 1;
          plVar5[1] = plVar5[1] + 1;
          puVar8 = (undefined8 *)_portMemAllocatorAlloc(*(undefined8 *)(param_1 + 0x38),0x10);
          *param_5 = (long)puVar8;
          if (puVar8 != (undefined8 *)0x0) {
            *puVar8 = uVar7;
            puVar8[1] = param_4;
            return 0;
          }
          nvAssertFailedNoLog("pMemoryArea->pRanges != NULL",
                              "src/libraries/mapping_reuse/mapping_reuse.c",0x103);
          goto LAB_0050d903;
        }
        bVar9 = false;
      }
    }
LAB_0050d6c4:
    local_40 = 0;
    local_50 = (undefined8 *)0x0;
    local_48 = param_1;
    iVar3 = (**(code **)(param_1 + 0x40))
                      (*(undefined8 *)(param_1 + 0x30),param_2,param_3,param_4,param_6,&local_50,
                       _reusemappingdbAddMappingCallback);
    if (iVar3 == 0) {
      lVar4 = _portMemAllocatorAlloc(*(undefined8 *)(param_1 + 0x38),local_40 << 4,uStack_a0);
      param_5[1] = 0;
      *param_5 = lVar4;
      if (lVar4 != 0) {
        lVar11 = 0;
        puVar8 = local_50;
        if (local_50 == (undefined8 *)0x0) {
          return 0;
        }
        while( true ) {
          local_50 = (undefined8 *)puVar8[2];
          uVar7 = *puVar8;
          uVar1 = puVar8[3];
          uVar2 = puVar8[4];
          param_5[1] = lVar11 + 1;
          lVar11 = (local_40 - (lVar11 + 1)) * 0x10;
          *(undefined8 *)(lVar4 + lVar11) = uVar1;
          *(undefined8 *)(lVar4 + 8 + lVar11) = uVar7;
          if (bVar9 == false) {
            _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x38),puVar8);
          }
          else {
            puVar8[2] = param_2;
            mapInsertExisting_IMPL(local_60,uVar2,puVar8);
            mapInsertExisting_IMPL(param_1 + 0x20,uVar1,puVar8);
          }
          if (local_50 == (undefined8 *)0x0) break;
          lVar11 = param_5[1];
          lVar4 = *param_5;
          puVar8 = local_50;
        }
        return 0;
      }
      nvAssertOkFailedNoLog
                (0x51,"pMemoryArea->pRanges != NULL","src/libraries/mapping_reuse/mapping_reuse.c",
                 0x117);
      iVar3 = 0x51;
    }
    else {
      nvAssertOkFailedNoLog
                (iVar3,
                 "pReuseMappingDb->pMapCb(pReuseMappingDb->pGlobalCtx, pAllocCtx, range, cachingFlags, &token, _reusemappingdbAddMappingCallback)"
                 ,"src/libraries/mapping_reuse/mapping_reuse.c",0x111);
    }
    if (local_50 != (undefined8 *)0x0) {
      do {
        puVar8 = local_50;
        (**(code **)(param_1 + 0x48))
                  (*(undefined8 *)(param_1 + 0x30),param_2,local_50[3],*local_50,
                   *(code **)(param_1 + 0x48));
        local_50 = (undefined8 *)local_50[2];
        _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x38),puVar8);
      } while (local_50 != (undefined8 *)0x0);
      return iVar3;
    }
  }
  return iVar3;
}


// ===== 0050dae0 gmmuFmtGetPde =====

long gmmuFmtGetPde(long param_1,long param_2,uint param_3)

{
  if (*(char *)(param_2 + 4) == '\0') {
    return 0;
  }
  if (*(char *)(param_2 + 4) != '\x01') {
    if (param_3 < 2) {
      return *(long *)(param_1 + 0x18) + 0x10 + (ulong)param_3 * 0x100;
    }
    nvAssertFailedNoLog("subLevel < MMU_FMT_MAX_SUB_LEVELS","src/libraries/mmu/gmmu_fmt.c",0x39);
    return 0;
  }
  return *(long *)(param_1 + 0x10);
}


// ===== 0050db40 gmmuFmtEntryIsPte =====

uint gmmuFmtEntryIsPte(long param_1,long param_2,long param_3)

{
  byte bVar1;
  long lVar2;
  uint uVar3;
  
  bVar1 = *(byte *)(param_2 + 3);
  if (*(char *)(param_2 + 4) == '\0') {
    if (bVar1 != 0) {
      return 1;
    }
  }
  else if (bVar1 != 0) {
    lVar2 = *(long *)(param_1 + 0x20);
    uVar3 = (*(uint *)(param_3 + (ulong)*(ushort *)(lVar2 + 0xe)) & *(uint *)(lVar2 + 4)) >>
            ((byte)*(undefined2 *)(lVar2 + 0xc) & 0x1f);
    return CONCAT31((int3)(uVar3 >> 8),(byte)uVar3 ^ *(byte *)(lVar2 + 0x10));
  }
  if (*(char *)(param_2 + 4) != '\0') {
    return (uint)bVar1;
  }
  nvAssertFailedNoLog("bPageDir","src/libraries/mmu/gmmu_fmt.c",0x53);
  return (uint)bVar1;
}


// ===== 0050dbc0 gmmuFmtPdePhysAddrFld =====

int * gmmuFmtPdePhysAddrFld(int *param_1,int param_2)

{
  if (*param_1 == 3) {
    return param_1 + 0x28;
  }
  if (param_2 != 1) {
    if (param_2 - 3U < 2) {
      return param_1 + 8;
    }
    nvAssertFailedNoLog(&DAT_00daae73,"src/libraries/mmu/gmmu_fmt.c",0x6e);
    return (int *)0x0;
  }
  return param_1 + 0x18;
}


// ===== 0050dc20 gmmuFmtPtePhysAddrFld =====

long gmmuFmtPtePhysAddrFld(long param_1,uint param_2)

{
  if (param_2 == 2) {
    return param_1 + 0xb0;
  }
  if (param_2 < 3) {
    if (param_2 == 1) {
      return param_1 + 0x70;
    }
  }
  else if (param_2 - 3 < 2) {
    return param_1 + 0x30;
  }
  nvAssertFailedNoLog(&DAT_00daae73,"src/libraries/mmu/gmmu_fmt.c",0x88);
  return 0;
}


// ===== 0050dc70 gmmuFmtInitPteCompTags =====

void gmmuFmtInitPteCompTags
               (long param_1,byte *param_2,undefined4 *param_3,ulong param_4,undefined8 param_5,
               int param_6,long param_7)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  byte bVar9;
  long lVar10;
  uint *puVar11;
  long lVar12;
  uint uVar13;
  uint uVar14;
  
  lVar3 = *(long *)(param_1 + 0x20);
  lVar12 = 1L << (*param_2 & 0x3f);
  if ((lVar12 - 1U & param_4) != 0) {
    nvAssertFailedNoLog("0 == (surfOffset & (pageSize - 1))","src/libraries/mmu/gmmu_fmt.c",0xa3);
  }
  uVar7 = *(uint *)(lVar3 + 0x194);
  bVar9 = 0;
  uVar13 = 0;
  if (uVar7 != 0) {
    uVar13 = uVar7 >> ((byte)*(undefined2 *)(lVar3 + 0x19c) & 0x1f);
    uVar7 = uVar7 - (uVar7 >> 1 & 0x55555555);
    uVar7 = (uVar7 & 0x33333333) + (uVar7 >> 2 & 0x33333333);
    bVar9 = (char)*param_3 - (char)(((uVar7 >> 4) + uVar7 & 0xf0f0f0f) * 0x1010101 >> 0x18);
  }
  if (param_6 != 0) {
    iVar8 = 0;
    do {
      uVar7 = param_3[2];
      uVar5 = param_4 + lVar12;
      uVar14 = (uint)(param_4 >> ((byte)*param_3 & 0x3f));
      if (((uVar7 <= uVar14) &&
          (uVar6 = (uint)(uVar5 - 1 >> ((byte)*param_3 & 0x3f)),
          uVar7 <= uVar6 && uVar6 <= (uint)param_3[3])) && (uVar14 <= (uint)param_3[3])) {
        lVar4 = *(long *)(param_1 + 0x20);
        iVar1 = param_3[5];
        iVar2 = param_3[4];
        lVar10 = (ulong)((uint)param_2[2] * iVar8) + param_7;
        *(uint *)(lVar10 + (ulong)*(ushort *)(lVar4 + 0x186)) =
             param_3[1] << ((byte)*(undefined2 *)(lVar4 + 0x184) & 0x1f) |
             *(uint *)(lVar10 + (ulong)*(ushort *)(lVar4 + 0x186)) & *(uint *)(lVar4 + 0x180);
        lVar4 = *(long *)(param_1 + 0x20);
        *(uint *)(lVar10 + (ulong)*(ushort *)(lVar4 + 0x192)) =
             *(uint *)(lVar10 + (ulong)*(ushort *)(lVar4 + 0x192)) & *(uint *)(lVar4 + 0x18c) |
             (uVar14 - uVar7) * iVar1 + iVar2 << ((byte)*(undefined2 *)(lVar4 + 400) & 0x1f);
        if (uVar13 != 0) {
          puVar11 = (uint *)(lVar10 + (ulong)*(ushort *)(lVar3 + 0x19e));
          *puVar11 = ((uint)(param_4 >> (bVar9 & 0x3f)) & uVar13) <<
                     ((byte)*(undefined2 *)(lVar3 + 0x19c) & 0x1f) |
                     *puVar11 & *(uint *)(lVar3 + 0x198);
        }
      }
      iVar8 = iVar8 + 1;
      param_4 = uVar5;
    } while (param_6 != iVar8);
  }
  return;
}


// ===== 0050de80 mmuFmtAllPageSizes =====

ulong mmuFmtAllPageSizes(byte *param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  long lVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  ulong uVar15;
  byte *pbVar16;
  byte *pbVar17;
  byte *pbVar18;
  ulong uVar19;
  byte *pbVar20;
  byte *pbVar21;
  byte *pbVar22;
  byte *pbVar23;
  ulong uVar24;
  byte *pbVar25;
  byte *pbVar26;
  long lVar27;
  ulong uVar28;
  byte *pbVar29;
  ulong uVar30;
  byte *pbVar31;
  ulong uVar32;
  byte *pbVar33;
  ulong uVar34;
  ulong uVar35;
  ulong uVar36;
  ulong uVar37;
  
  uVar15 = 0;
  if (param_1[3] != 0) {
    uVar15 = 1L << (*param_1 & 0x3f);
  }
  bVar7 = param_1[4];
  if (bVar7 != 0) {
    pbVar1 = *(byte **)(param_1 + 0x10) + 0x18;
    pbVar2 = pbVar1;
    pbVar23 = *(byte **)(param_1 + 0x10);
    while( true ) {
      pbVar20 = pbVar2;
      uVar35 = 0;
      if (pbVar23[3] != 0) {
        uVar35 = 1L << (*pbVar23 & 0x3f);
      }
      bVar8 = pbVar23[4];
      if (bVar8 != 0) {
        pbVar2 = *(byte **)(pbVar23 + 0x10) + 0x18;
        pbVar23 = *(byte **)(pbVar23 + 0x10);
        pbVar25 = pbVar2;
        while( true ) {
          uVar32 = 0;
          if (pbVar23[3] != 0) {
            uVar32 = 1L << (*pbVar23 & 0x3f);
          }
          bVar9 = pbVar23[4];
          if (bVar9 != 0) {
            pbVar3 = *(byte **)(pbVar23 + 0x10) + 0x18;
            pbVar4 = pbVar3;
            pbVar23 = *(byte **)(pbVar23 + 0x10);
            while( true ) {
              pbVar21 = pbVar4;
              uVar28 = 0;
              if (pbVar23[3] != 0) {
                uVar28 = 1L << (*pbVar23 & 0x3f);
              }
              bVar10 = pbVar23[4];
              if (bVar10 != 0) {
                pbVar4 = *(byte **)(pbVar23 + 0x10) + 0x18;
                pbVar23 = *(byte **)(pbVar23 + 0x10);
                pbVar26 = pbVar4;
                while( true ) {
                  uVar36 = 0;
                  if (pbVar23[3] != 0) {
                    uVar36 = 1L << (*pbVar23 & 0x3f);
                  }
                  bVar11 = pbVar23[4];
                  if (bVar11 != 0) {
                    pbVar5 = *(byte **)(pbVar23 + 0x10) + 0x18;
                    pbVar16 = pbVar5;
                    pbVar23 = *(byte **)(pbVar23 + 0x10);
                    while( true ) {
                      pbVar22 = pbVar16;
                      uVar37 = 0;
                      if (pbVar23[3] != 0) {
                        uVar37 = 1L << (*pbVar23 & 0x3f);
                      }
                      bVar12 = pbVar23[4];
                      if (bVar12 != 0) {
                        pbVar23 = *(byte **)(pbVar23 + 0x10);
                        pbVar16 = pbVar23;
                        do {
                          pbVar29 = pbVar16 + 0x18;
                          uVar24 = 0;
                          if (pbVar16[3] != 0) {
                            uVar24 = 1L << (*pbVar16 & 0x3f);
                          }
                          bVar13 = pbVar16[4];
                          if (bVar13 != 0) {
                            pbVar16 = *(byte **)(pbVar16 + 0x10);
                            pbVar17 = pbVar16;
                            do {
                              pbVar33 = pbVar17 + 0x18;
                              uVar30 = 0;
                              if (pbVar17[3] != 0) {
                                uVar30 = 1L << (*pbVar17 & 0x3f);
                              }
                              bVar14 = pbVar17[4];
                              if (bVar14 != 0) {
                                pbVar17 = *(byte **)(pbVar17 + 0x10);
                                pbVar18 = pbVar17;
                                do {
                                  pbVar31 = pbVar18 + 0x18;
                                  uVar34 = 0;
                                  if (pbVar18[3] != 0) {
                                    uVar34 = 1L << (*pbVar18 & 0x3f);
                                  }
                                  if (pbVar18[4] != 0) {
                                    lVar27 = *(long *)(pbVar18 + 0x10) + 0x18;
                                    lVar6 = lVar27 + (ulong)(pbVar18[4] - 1) * 0x18;
                                    uVar19 = mmuFmtAllPageSizes();
                                    uVar34 = uVar34 | uVar19;
                                    for (; lVar27 != lVar6; lVar27 = lVar27 + 0x18) {
                                      uVar19 = mmuFmtAllPageSizes(lVar27);
                                      uVar34 = uVar34 | uVar19;
                                    }
                                  }
                                  uVar30 = uVar30 | uVar34;
                                  pbVar18 = pbVar31;
                                } while (pbVar17 + (ulong)(bVar14 - 1) * 0x18 + 0x18 != pbVar31);
                              }
                              uVar24 = uVar24 | uVar30;
                              pbVar17 = pbVar33;
                            } while (pbVar16 + (ulong)(bVar13 - 1) * 0x18 + 0x18 != pbVar33);
                          }
                          uVar37 = uVar37 | uVar24;
                          pbVar16 = pbVar29;
                        } while (pbVar23 + (ulong)(bVar12 - 1) * 0x18 + 0x18 != pbVar29);
                      }
                      uVar36 = uVar36 | uVar37;
                      if (pbVar5 + (ulong)(bVar11 - 1) * 0x18 == pbVar22) break;
                      pbVar16 = pbVar22 + 0x18;
                      pbVar23 = pbVar22;
                    }
                  }
                  uVar28 = uVar28 | uVar36;
                  if (pbVar4 + (ulong)(bVar10 - 1) * 0x18 == pbVar26) break;
                  pbVar23 = pbVar26;
                  pbVar26 = pbVar26 + 0x18;
                }
              }
              uVar32 = uVar32 | uVar28;
              if (pbVar3 + (ulong)(bVar9 - 1) * 0x18 == pbVar21) break;
              pbVar4 = pbVar21 + 0x18;
              pbVar23 = pbVar21;
            }
          }
          uVar35 = uVar35 | uVar32;
          if (pbVar25 == pbVar2 + (ulong)(bVar8 - 1) * 0x18) break;
          pbVar23 = pbVar25;
          pbVar25 = pbVar25 + 0x18;
        }
      }
      uVar15 = uVar15 | uVar35;
      if (pbVar20 == pbVar1 + (ulong)(bVar7 - 1) * 0x18) break;
      pbVar2 = pbVar20 + 0x18;
      pbVar23 = pbVar20;
    }
    return uVar15;
  }
  return uVar15;
}


// ===== 0050e260 mmuFmtFindLevelWithPageShift =====

byte * mmuFmtFindLevelWithPageShift(byte *param_1,ulong param_2)

{
  long lVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte bVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  long lVar14;
  byte *pbVar15;
  byte *pbVar16;
  byte *pbVar17;
  byte *pbVar18;
  byte *pbVar19;
  byte *pbVar20;
  
  if (*param_1 == param_2) {
    return param_1;
  }
  if (param_1[4] != 0) {
    pbVar19 = *(byte **)(param_1 + 0x10);
    pbVar2 = pbVar19 + (ulong)(param_1[4] - 1) * 0x18 + 0x18;
    do {
      if (param_2 == *pbVar19) {
        return pbVar19;
      }
      if (pbVar19[4] != 0) {
        pbVar17 = *(byte **)(pbVar19 + 0x10);
        pbVar3 = pbVar17 + (ulong)(pbVar19[4] - 1) * 0x18 + 0x18;
        do {
          if (param_2 == *pbVar17) {
            return pbVar17;
          }
          if (pbVar17[4] != 0) {
            pbVar16 = *(byte **)(pbVar17 + 0x10);
            pbVar4 = pbVar16 + (ulong)(pbVar17[4] - 1) * 0x18 + 0x18;
            do {
              if (param_2 == *pbVar16) {
                return pbVar16;
              }
              if (pbVar16[4] != 0) {
                pbVar18 = *(byte **)(pbVar16 + 0x10);
                pbVar5 = pbVar18 + (ulong)(pbVar16[4] - 1) * 0x18 + 0x18;
                do {
                  if (param_2 == *pbVar18) {
                    return pbVar18;
                  }
                  if (pbVar18[4] != 0) {
                    pbVar15 = *(byte **)(pbVar18 + 0x10);
                    pbVar6 = pbVar15 + (ulong)(pbVar18[4] - 1) * 0x18 + 0x18;
                    do {
                      if (param_2 == *pbVar15) {
                        return pbVar15;
                      }
                      if (pbVar15[4] != 0) {
                        pbVar13 = *(byte **)(pbVar15 + 0x10);
                        pbVar7 = pbVar13 + (ulong)(pbVar15[4] - 1) * 0x18 + 0x18;
                        do {
                          if (param_2 == *pbVar13) {
                            return pbVar13;
                          }
                          if (pbVar13[4] != 0) {
                            pbVar20 = *(byte **)(pbVar13 + 0x10);
                            pbVar8 = pbVar20 + (ulong)(pbVar13[4] - 1) * 0x18 + 0x18;
                            do {
                              if (param_2 == *pbVar20) {
                                return pbVar20;
                              }
                              if (pbVar20[4] != 0) {
                                pbVar12 = *(byte **)(pbVar20 + 0x10);
                                pbVar9 = pbVar12 + (ulong)(pbVar20[4] - 1) * 0x18 + 0x18;
                                do {
                                  if (param_2 == *pbVar12) {
                                    return pbVar12;
                                  }
                                  bVar10 = pbVar12[4];
                                  if (bVar10 != 0) {
                                    lVar14 = *(long *)(pbVar12 + 0x10);
                                    lVar1 = lVar14 + 0x18;
                                    do {
                                      pbVar11 = (byte *)mmuFmtFindLevelWithPageShift(lVar14);
                                      if (pbVar11 != (byte *)0x0) {
                                        return pbVar11;
                                      }
                                      lVar14 = lVar14 + 0x18;
                                    } while (lVar1 + (ulong)(bVar10 - 1) * 0x18 != lVar14);
                                  }
                                  pbVar12 = pbVar12 + 0x18;
                                } while (pbVar9 != pbVar12);
                              }
                              pbVar20 = pbVar20 + 0x18;
                            } while (pbVar8 != pbVar20);
                          }
                          pbVar13 = pbVar13 + 0x18;
                        } while (pbVar13 != pbVar7);
                      }
                      pbVar15 = pbVar15 + 0x18;
                    } while (pbVar15 != pbVar6);
                  }
                  pbVar18 = pbVar18 + 0x18;
                } while (pbVar18 != pbVar5);
              }
              pbVar16 = pbVar16 + 0x18;
            } while (pbVar16 != pbVar4);
          }
          pbVar17 = pbVar17 + 0x18;
        } while (pbVar17 != pbVar3);
      }
      pbVar19 = pbVar19 + 0x18;
    } while (pbVar19 != pbVar2);
    return (byte *)0x0;
  }
  return (byte *)0x0;
}


// ===== 0050e590 mmuFmtFindLevelParent =====

long mmuFmtFindLevelParent(long param_1,long param_2,uint *param_3)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  uint uVar9;
  long lVar10;
  long lVar11;
  uint uVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  uint uVar16;
  long lVar17;
  long lVar18;
  long local_c8;
  long local_b8;
  uint local_b0;
  uint local_ac;
  long local_a0;
  long local_88;
  uint local_80;
  uint local_7c;
  uint local_64;
  
  local_c8 = 0;
  local_b0 = 0;
  if (*(char *)(param_1 + 4) != '\0') {
    do {
      lVar2 = local_c8 + *(long *)(param_1 + 0x10);
      if (lVar2 == param_2) {
        if (param_3 != (uint *)0x0) {
          *param_3 = local_b0;
        }
        return param_1;
      }
      local_b8 = 0;
      local_ac = 0;
      if (*(char *)(lVar2 + 4) != '\0') {
        do {
          lVar17 = local_b8 + *(long *)(lVar2 + 0x10);
          if (param_2 == lVar17) {
            if (param_3 == (uint *)0x0) {
              return lVar2;
            }
            *param_3 = local_ac;
            return lVar2;
          }
          local_a0 = 0;
          local_80 = 0;
          if (*(char *)(lVar17 + 4) != '\0') {
            do {
              lVar13 = local_a0 + *(long *)(lVar17 + 0x10);
              if (param_2 == lVar13) {
                if (param_3 == (uint *)0x0) {
                  return lVar17;
                }
                *param_3 = local_80;
                return lVar17;
              }
              local_88 = 0;
              local_7c = 0;
              if (*(char *)(lVar13 + 4) != '\0') {
                do {
                  lVar18 = local_88 + *(long *)(lVar13 + 0x10);
                  if (param_2 == lVar18) {
                    if (param_3 == (uint *)0x0) {
                      return lVar13;
                    }
                    *param_3 = local_7c;
                    return lVar13;
                  }
                  local_64 = 0;
                  lVar4 = 0;
                  if (*(char *)(lVar18 + 4) != '\0') {
                    do {
                      lVar14 = *(long *)(lVar18 + 0x10) + lVar4;
                      if (param_2 == lVar14) {
                        if (param_3 == (uint *)0x0) {
                          return lVar18;
                        }
                        *param_3 = local_64;
                        return lVar18;
                      }
                      lVar10 = 0;
                      if (*(char *)(lVar14 + 4) != '\0') {
                        uVar16 = 0;
                        do {
                          lVar7 = *(long *)(lVar14 + 0x10) + lVar10;
                          if (param_2 == lVar7) {
                            if (param_3 == (uint *)0x0) {
                              return lVar14;
                            }
                            *param_3 = uVar16;
                            return lVar14;
                          }
                          lVar3 = 0;
                          if (*(char *)(lVar7 + 4) != '\0') {
                            uVar9 = 0;
                            do {
                              lVar1 = *(long *)(lVar7 + 0x10) + lVar3;
                              if (param_2 == lVar1) {
                                if (param_3 == (uint *)0x0) {
                                  return lVar7;
                                }
                                *param_3 = uVar9;
                                return lVar7;
                              }
                              lVar11 = 0;
                              uVar5 = 0;
                              if (*(char *)(lVar1 + 4) != '\0') {
                                do {
                                  lVar6 = *(long *)(lVar1 + 0x10) + lVar11;
                                  if (param_2 == lVar6) {
                                    if (param_3 != (uint *)0x0) {
                                      *param_3 = uVar5;
                                    }
                                    return lVar1;
                                  }
                                  lVar15 = 0;
                                  uVar12 = 0;
                                  if (*(char *)(lVar6 + 4) != '\0') {
                                    do {
                                      lVar8 = *(long *)(lVar6 + 0x10) + lVar15;
                                      if (param_2 == lVar8) {
                                        if (param_3 == (uint *)0x0) {
                                          return lVar6;
                                        }
                                        *param_3 = uVar12;
                                        return lVar6;
                                      }
                                      lVar8 = mmuFmtFindLevelParent(lVar8,param_2,param_3);
                                      if (lVar8 != 0) {
                                        return lVar8;
                                      }
                                      uVar12 = uVar12 + 1;
                                      lVar15 = lVar15 + 0x18;
                                    } while (uVar12 < *(byte *)(lVar6 + 4));
                                  }
                                  uVar5 = uVar5 + 1;
                                  lVar11 = lVar11 + 0x18;
                                } while (uVar5 < *(byte *)(lVar1 + 4));
                              }
                              uVar9 = uVar9 + 1;
                              lVar3 = lVar3 + 0x18;
                            } while (uVar9 < *(byte *)(lVar7 + 4));
                          }
                          uVar16 = uVar16 + 1;
                          lVar10 = lVar10 + 0x18;
                        } while (uVar16 < *(byte *)(lVar14 + 4));
                      }
                      local_64 = local_64 + 1;
                      lVar4 = lVar4 + 0x18;
                    } while (local_64 < *(byte *)(lVar18 + 4));
                  }
                  local_7c = local_7c + 1;
                  local_88 = local_88 + 0x18;
                } while (local_7c < *(byte *)(lVar13 + 4));
              }
              local_80 = local_80 + 1;
              local_a0 = local_a0 + 0x18;
            } while (local_80 < *(byte *)(lVar17 + 4));
          }
          local_ac = local_ac + 1;
          local_b8 = local_b8 + 0x18;
        } while (local_ac < *(byte *)(lVar2 + 4));
      }
      local_b0 = local_b0 + 1;
      local_c8 = local_c8 + 0x18;
    } while (local_b0 < *(byte *)(param_1 + 4));
  }
  return 0;
}


// ===== 0050ea40 mmuFmtGetNextLevel =====

long mmuFmtGetNextLevel(long param_1,long param_2)

{
  long lVar1;
  byte bVar2;
  long lVar3;
  
  if (param_1 != param_2) {
    bVar2 = *(byte *)(param_1 + 4);
    if (bVar2 == 1) {
      return *(long *)(param_1 + 0x10);
    }
    if (bVar2 != 0) {
      lVar3 = *(long *)(param_1 + 0x10);
      lVar1 = lVar3 + 0x18;
      do {
        if (param_2 == lVar3) {
          return lVar3;
        }
        lVar3 = lVar3 + 0x18;
      } while (lVar3 != lVar1 + (ulong)(bVar2 - 1) * 0x18);
    }
  }
  return 0;
}


// ===== 0050eab0 mmuFmtConvertLevelIdToSuffix =====

undefined8 mmuFmtConvertLevelIdToSuffix(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (*(uint *)(param_1 + 8) < 7) {
    uVar1 = *(undefined8 *)(CSWTCH_8 + (ulong)*(uint *)(param_1 + 8) * 8);
  }
  return uVar1;
}


// ===== 0050ead0 _mmuWalkLevelInstRelease =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _mmuWalkLevelInstRelease(undefined8 *param_1,undefined8 *param_2,long param_3)

{
  int iVar1;
  
  if (*(int *)(param_3 + 0x44) == 0) {
    iVar1 = *(int *)(param_3 + 0x4c);
  }
  else {
    nvAssertFailedNoLog("0 == pLevelInst->numValid","src/libraries/mmu/mmu_walk.c",0x4f9);
    iVar1 = *(int *)(param_3 + 0x4c);
  }
  if (iVar1 != 0) {
    nvAssertFailedNoLog("0 == pLevelInst->numReserved","src/libraries/mmu/mmu_walk.c",0x4fa);
  }
  btreeUnlink(param_3,param_2 + 3);
  if (*(long *)(param_3 + 0x38) != 0) {
    (**(code **)(param_1[1] + 8))(*param_1,*param_2,*(undefined8 *)(param_3 + 8));
  }
  portMemFree(*(undefined8 *)(param_3 + 0x58));
  portMemFree(param_3);
  return;
}


// ===== 0050eb80 _mmuWalkLevelInstancesForceFree =====

void _mmuWalkLevelInstancesForceFree(undefined8 param_1,long *param_2)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  long local_30;
  
  local_30 = 0;
  if (param_2 != (long *)0x0) {
    while (btreeEnumStart(0,&local_30,param_2[3]), local_30 != 0) {
      *(undefined4 *)(local_30 + 0x44) = 0;
      *(undefined4 *)(local_30 + 0x4c) = 0;
      _mmuWalkLevelInstRelease(param_1,param_2);
    }
    lVar1 = param_2[2];
    param_2[3] = 0;
    if ((lVar1 == 0) || (*(char *)(*param_2 + 4) == '\0')) {
      return;
    }
    uVar2 = 0;
    lVar3 = 0;
    while( true ) {
      uVar2 = uVar2 + 1;
      _mmuWalkLevelInstancesForceFree(param_1,lVar1 + lVar3);
      if (*(byte *)(*param_2 + 4) <= uVar2) break;
      lVar1 = param_2[2];
      lVar3 = lVar3 + 0x68;
    }
  }
  return;
}


// ===== 0050ec60 _mmuWalkLevelDestroy.isra.0 =====

void _mmuWalkLevelDestroy_isra_0(long *param_1)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  
  lVar1 = param_1[2];
  if (lVar1 != 0) {
    if (*(char *)(*param_1 + 4) != '\0') {
      uVar2 = 0;
      lVar3 = 0;
      do {
        lVar1 = lVar1 + lVar3;
        uVar2 = uVar2 + 1;
        lVar3 = lVar3 + 0x68;
        _mmuWalkLevelDestroy_isra_0(lVar1);
        lVar1 = param_1[2];
      } while (uVar2 < *(byte *)(*param_1 + 4));
    }
    portMemFree();
  }
  if (param_1[3] != 0) {
    nvAssertFailedNoLog("NULL == pLevel->pInstances","src/libraries/mmu/mmu_walk.c",0x3af);
    return;
  }
  return;
}


// ===== 0050ecf0 _mmuWalkLevelInit.isra.0 =====

ulong _mmuWalkLevelInit_isra_0(long param_1,long param_2,long *param_3)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  
  *param_3 = param_2;
  param_3[1] = param_1;
  if (*(byte *)(param_2 + 4) != 0) {
    lVar3 = (ulong)*(byte *)(param_2 + 4) * 0x68;
    lVar1 = portMemAllocNonPaged(lVar3);
    param_3[2] = lVar1;
    if (lVar1 == 0) {
      return 0x51;
    }
    portMemSet(lVar1,0,lVar3);
    if (*(char *)(param_2 + 4) != '\0') {
      lVar1 = 0;
      lVar3 = 0;
      do {
        uVar2 = _mmuWalkLevelInit_isra_0
                          (param_3,*(long *)(param_2 + 0x10) + lVar1 * 0x18,param_3[2] + lVar3);
        if ((int)uVar2 != 0) {
          nvAssertOkFailedNoLog
                    (uVar2 & 0xffffffff,
                     "_mmuWalkLevelInit(pWalk, pLevel, pLevelFmt->subLevels + subLevel, pLevel->subLevels + subLevel)"
                     ,"src/libraries/mmu/mmu_walk.c",0x391);
          return uVar2 & 0xffffffff;
        }
        lVar1 = lVar1 + 1;
        lVar3 = lVar3 + 0x68;
      } while ((uint)lVar1 < (uint)*(byte *)(param_2 + 4));
      return uVar2;
    }
  }
  return 0;
}


// ===== 0050ee20 mmuWalkGetEntryState =====

byte mmuWalkGetEntryState(long param_1,uint param_2)

{
  return *(byte *)(*(long *)(param_1 + 0x58) + (ulong)param_2) & 0x3f;
}


// ===== 0050ee40 mmuWalkCreate =====

ulong mmuWalkCreate(long param_1,undefined8 param_2,long param_3,undefined1 param_4,long *param_5,
                   undefined8 param_6)

{
  undefined8 *puVar1;
  ulong uVar2;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pRootFmt","src/libraries/mmu/mmu_walk.c",0x61);
  }
  else if (param_3 == 0) {
    nvAssertFailedNoLog("NULL != pCb","src/libraries/mmu/mmu_walk.c",0x62);
  }
  else {
    if (param_5 != (long *)0x0) {
      puVar1 = (undefined8 *)portMemAllocNonPaged(0xf70);
      if (puVar1 == (undefined8 *)0x0) {
        nvAssertFailedNoLog("NV_OK == status","src/libraries/mmu/mmu_walk.c",0x68);
        uVar2 = 0x51;
      }
      else {
        portMemSet(puVar1,0,0xf70);
        *puVar1 = param_2;
        puVar1[1] = param_3;
        *(undefined1 *)(puVar1 + 2) = param_4;
        puVar1[0x10] = param_6;
        *(undefined2 *)(puVar1 + 0x11) = 0x100;
        uVar2 = _mmuWalkLevelInit_isra_0(0,param_1,puVar1 + 3);
        if ((int)uVar2 == 0) {
          *param_5 = (long)puVar1;
        }
        else {
          nvAssertFailedNoLog("NV_OK == status","src/libraries/mmu/mmu_walk.c",0x74);
          _mmuWalkLevelDestroy_isra_0(puVar1 + 3);
          portMemFree(puVar1);
          uVar2 = uVar2 & 0xffffffff;
        }
      }
      return uVar2;
    }
    nvAssertFailedNoLog("NULL != ppWalk","src/libraries/mmu/mmu_walk.c",99);
  }
  return 0x1f;
}


// ===== 0050efe0 mmuWalkDestroy =====

void mmuWalkDestroy(long param_1)

{
  if (param_1 != 0) {
    _mmuWalkLevelDestroy_isra_0(param_1 + 0x18);
    portMemFree(param_1);
    return;
  }
  return;
}


// ===== 0050f020 mmuWalkGetUserCtx =====

undefined8 mmuWalkGetUserCtx(undefined8 *param_1)

{
  return *param_1;
}


// ===== 0050f030 mmuWalkSetUserCtx =====

undefined8 mmuWalkSetUserCtx(undefined8 *param_1,undefined8 param_2)

{
  if (param_1 != (undefined8 *)0x0) {
    *param_1 = param_2;
    return 0;
  }
  nvAssertFailedNoLog("NULL != pWalk","src/libraries/mmu/mmu_walk.c",0xb3);
  return 0x40;
}


// ===== 0050f070 mmuWalkGetCallbacks =====

undefined8 mmuWalkGetCallbacks(long param_1)

{
  return *(undefined8 *)(param_1 + 8);
}


// ===== 0050f080 mmuWalkSetCallbacks =====

void mmuWalkSetCallbacks(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 8) = param_2;
  return;
}


// ===== 0050f090 mmuWalkLevelInstancesForceFree =====

void mmuWalkLevelInstancesForceFree(long param_1)

{
  if (param_1 != 0) {
    _mmuWalkLevelInstancesForceFree(param_1,param_1 + 0x18);
    return;
  }
  return;
}


// ===== 0050f0c0 mmuWalkFindLevel =====

long * mmuWalkFindLevel(long param_1,long param_2)

{
  byte bVar1;
  long lVar2;
  long lVar3;
  long *plVar4;
  
  plVar4 = (long *)(param_1 + 0x18);
  do {
    lVar3 = *plVar4;
    if (lVar3 == param_2) {
      return plVar4;
    }
    if (lVar3 == 0) {
      nvAssertFailedNoLog("pLevel->pFmt != NULL","src/libraries/mmu/mmu_walk.c",0xe6);
      return (long *)0x0;
    }
    bVar1 = *(byte *)(lVar3 + 4);
    if (bVar1 != 1) {
      if (bVar1 == 0) {
        return (long *)0x0;
      }
      lVar3 = *(long *)(lVar3 + 0x10);
      lVar2 = 0;
      do {
        if (param_2 == lVar3) {
          return (long *)(lVar2 * 0x68 + plVar4[2]);
        }
        lVar2 = lVar2 + 1;
        lVar3 = lVar3 + 0x18;
      } while ((uint)lVar2 < (uint)bVar1);
      return (long *)0x0;
    }
    plVar4 = (long *)plVar4[2];
  } while (plVar4 != (long *)0x0);
  return (long *)0x0;
}


// ===== 0050f160 mmuWalkRootRelease =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void mmuWalkRootRelease(undefined8 *param_1)

{
  long lVar1;
  char cVar2;
  
  lVar1 = param_1[6];
  if (((lVar1 != 0) && (*(int *)(lVar1 + 0x48) + *(int *)(lVar1 + 0x44) == 0)) &&
     (*(int *)(lVar1 + 0x4c) == 0)) {
    cVar2 = (**(code **)(param_1[1] + 0x10))(*param_1,param_1[3],0,0);
    if (cVar2 == '\0') {
      nvAssertFailedNoLog("bDone","src/libraries/mmu/mmu_walk.c",0x2d1);
    }
    _mmuWalkLevelInstRelease(param_1,param_1 + 3,lVar1);
    return;
  }
  return;
}


// ===== 0050f210 mmuWalkSetEntryState =====

void mmuWalkSetEntryState(long param_1,ulong param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  
  param_2 = param_2 & 0xffffffff;
  bVar1 = *(byte *)(*(long *)(param_1 + 0x58) + param_2) & 0x3f;
  if (bVar1 < 4) {
    if (bVar1 < 2) {
      if (bVar1 != 0) {
        iVar2 = *(int *)(param_1 + 0x48);
        if (iVar2 == 0) {
          nvAssertFailedNoLog("0 != pLevelInst->numSparse","src/libraries/mmu/mmu_walk.c",0x2f3);
          iVar2 = *(int *)(param_1 + 0x48);
        }
        *(int *)(param_1 + 0x48) = iVar2 + -1;
      }
    }
    else {
      iVar2 = *(int *)(param_1 + 0x44);
      if (iVar2 == 0) {
        nvAssertFailedNoLog("0 != pLevelInst->numValid","src/libraries/mmu/mmu_walk.c",0x2ef);
        iVar2 = *(int *)(param_1 + 0x44);
      }
      *(int *)(param_1 + 0x44) = iVar2 + -1;
    }
  }
  else if (bVar1 == 4) {
    iVar2 = *(int *)(param_1 + 0x54);
    if (iVar2 == 0) {
      nvAssertFailedNoLog("0 != pLevelInst->numNv4k","src/libraries/mmu/mmu_walk.c",0x2f7);
      iVar2 = *(int *)(param_1 + 0x54);
    }
    *(int *)(param_1 + 0x54) = iVar2 + -1;
  }
  else {
    nvAssertFailedNoLog(&DAT_00dab09b,"src/libraries/mmu/mmu_walk.c",0x2fd);
  }
  if (param_3 < 4) {
    if (param_3 < 2) {
      if (param_3 != 0) {
        *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
      }
    }
    else {
      *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
    }
  }
  else if (param_3 == 4) {
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
  }
  else {
    nvAssertFailedNoLog(&DAT_00dab09b,"src/libraries/mmu/mmu_walk.c",0x310);
  }
  *(byte *)(*(long *)(param_1 + 0x58) + param_2) =
       (byte)param_3 & 0x3f | *(byte *)(*(long *)(param_1 + 0x58) + param_2) & 0xc0;
  return;
}


// ===== 0050f400 _mmuWalkPdeRelease =====

/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _mmuWalkPdeRelease(undefined8 *param_1,undefined8 *param_2,long *param_3,long param_4,
                       uint param_5,undefined8 param_6)

{
  byte bVar1;
  long lVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  ulong uVar6;
  byte *pbVar7;
  long lVar8;
  uint uVar9;
  long *plVar10;
  long lVar11;
  long *plVar12;
  uint local_74;
  int local_5c;
  long local_58 [5];
  
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  local_74 = 0;
  if ((*(byte *)(param_2 + 3) & 1) != 0) {
    local_74 = *(uint *)*param_2;
  }
  bVar1 = *(byte *)(*param_3 + 4);
  if (bVar1 == 0) {
    if ((*(byte *)(*(long *)(param_4 + 0x58) + (ulong)param_5) & 0x3f) == local_74) {
      return;
    }
  }
  else {
    uVar6 = (ulong)(bVar1 - 1);
    lVar11 = uVar6 * 0x68;
    uVar9 = (uint)bVar1;
    bVar3 = false;
    plVar12 = local_58 + uVar6 + 2;
    plVar10 = local_58 + uVar6;
    do {
      uVar9 = uVar9 - 1;
      iVar5 = btreeSearch(param_6,plVar10,*(undefined8 *)(param_3[2] + 0x18 + lVar11));
      if (iVar5 == 0) {
        lVar8 = *param_3;
        lVar2 = *plVar10;
        if (((*(char *)(lVar8 + 4) == '\x02') && (uVar9 == 0)) &&
           ((*(byte *)(param_1 + 2) & 2) != 0)) {
          if (((*(int *)(local_58[0] + 0x54) ==
                1 << (((*(char **)param_3[2])[1] - **(char **)param_3[2]) + 1U & 0x1f)) &&
              (*(int *)(local_58[0] + 0x4c) == 0)) && ((local_58[3] == 0 || (bVar3))))
          goto LAB_0050f5a4;
          local_58[2] = *(undefined8 *)(lVar2 + 0x38);
          if ((*(byte *)(*(long *)(param_4 + 0x58) + (ulong)param_5) & 0x3f) == 3 && !bVar3)
          goto LAB_0050f55b;
          goto LAB_0050f6bb;
        }
        if ((*(int *)(lVar2 + 0x48) + *(int *)(lVar2 + 0x44) == 0) &&
           (*(int *)(lVar2 + 0x50) + *(int *)(lVar2 + 0x4c) == 0)) {
          bVar3 = (bool)(bVar3 | *(long *)(lVar2 + 0x38) != 0);
        }
        else {
          *plVar12 = *(long *)(lVar2 + 0x38);
          local_74 = 3;
        }
      }
      lVar11 = lVar11 + -0x68;
      plVar10 = plVar10 + -1;
      plVar12 = plVar12 + -1;
    } while (uVar9 != 0);
    if ((*(byte *)(*(long *)(param_4 + 0x58) + (ulong)param_5) & 0x3f) == local_74 && !bVar3) {
      lVar8 = *param_3;
      goto LAB_0050f55b;
    }
  }
LAB_0050f5a4:
  local_5c = 0;
  if (local_74 < 2) {
    (**(code **)(param_1[1] + 0x20))
              (*param_1,*param_3,*(undefined8 *)(param_4 + 0x38),param_5,param_5,local_74,&local_5c)
    ;
    if (local_5c != 1) {
      nvAssertFailedNoLog("progress == 1","src/libraries/mmu/mmu_walk.c",0x5f2);
      return;
    }
    pbVar7 = (byte *)(*(long *)(param_4 + 0x58) + (ulong)param_5);
    if ((*pbVar7 & 0x40) != 0) {
      iVar5 = *(int *)(param_4 + 0x50);
      if (iVar5 == 0) {
        nvAssertFailedNoLog("0 != pLevelInst->numHybrid","src/libraries/mmu/mmu_walk.c",0x335);
        pbVar7 = (byte *)((ulong)param_5 + *(long *)(param_4 + 0x58));
        iVar5 = *(int *)(param_4 + 0x50);
      }
      *(int *)(param_4 + 0x50) = iVar5 + -1;
      *pbVar7 = *pbVar7 & 0xbf;
    }
  }
  else {
    if (local_74 != 3) {
      nvAssertFailedNoLog(&DAT_00dab09b,"src/libraries/mmu/mmu_walk.c",0x5ff);
      return;
    }
    lVar8 = *param_3;
LAB_0050f6bb:
    local_5c = 0;
    cVar4 = (**(code **)(param_1[1] + 0x18))
                      (*param_1,lVar8,*(undefined8 *)(param_4 + 0x38),param_5,local_58 + 2);
    local_74 = 3;
    if (cVar4 == '\0') {
      nvAssertFailedNoLog("bDone","src/libraries/mmu/mmu_walk.c",0x5fc);
      return;
    }
  }
  mmuWalkSetEntryState(param_4,param_5,local_74);
  lVar8 = *param_3;
LAB_0050f55b:
  if (*(char *)(lVar8 + 4) != '\0') {
    lVar11 = 0;
    do {
      if ((local_58[lVar11] != 0) && (local_58[lVar11 + 2] == 0)) {
        _mmuWalkLevelInstRelease(param_1,(ulong)(-(int)lVar11 & 0x68) + param_3[2]);
        lVar8 = *param_3;
      }
      lVar11 = lVar11 + 1;
    } while ((uint)lVar11 < (uint)*(byte *)(lVar8 + 4));
  }
  return;
}


// ===== 0050f800 _mmuWalkLevelInstAcquire.constprop.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */

int _mmuWalkLevelInstAcquire_constprop_0
              (undefined8 *param_1,long *param_2,ulong param_3,ulong param_4,char param_5,
              char param_6,char param_7,char *param_8,long *param_9,byte param_10)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  undefined8 uVar6;
  code *pcVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  byte local_61;
  uint local_44;
  long local_40 [2];
  
  local_40[0] = 0;
  iVar3 = btreeSearch(param_3,local_40,param_2[3]);
  if (iVar3 == 0) {
    pcVar8 = (char *)*param_2;
    local_61 = 0;
    cVar2 = pcVar8[1];
LAB_0050f94b:
    lVar5 = *(long *)(local_40[0] + 0x38);
    uVar10 = *(uint *)(local_40[0] + 0x40);
    iVar3 = (**(code **)param_1[1])
                      (*param_1,pcVar8,-1L << (cVar2 + 1U & 0x3f) & param_3,param_4,param_5,
                       local_40[0] + 0x38,local_40[0] + 0x40);
    if (iVar3 == 0) {
      if (*param_8 == '\0') {
        if ((lVar5 != *(long *)(local_40[0] + 0x38)) || (uVar10 != *(uint *)(local_40[0] + 0x40))) {
          nvAssertFailedNoLog("pOldMem == pLevelInst->pMemDesc && oldSize == pLevelInst->memSize",
                              "src/libraries/mmu/mmu_walk.c",0x4de,local_40[0],param_8);
        }
LAB_0050fade:
        *param_9 = local_40[0];
        return 0;
      }
      bVar1 = *(byte *)(*param_2 + 2);
      local_44 = 0;
      uVar11 = *(uint *)(local_40[0] + 0x40) / (uint)bVar1;
      uVar4 = uVar11 - 1;
      if (*(long *)(local_40[0] + 0x38) == 0) {
        nvAssertFailedNoLog("NULL != pLevelInst->pMemDesc","src/libraries/mmu/mmu_walk.c",0x4b2);
      }
      uVar9 = (uint)((ulong)uVar10 / (ulong)bVar1);
      if (uVar4 < uVar9) {
        nvAssertFailedNoLog("entryIndexLo <= entryIndexHi","src/libraries/mmu/mmu_walk.c",0x4b3);
      }
      if (param_7 == '\0') {
        if (bVar1 <= uVar10) {
          pcVar7 = *(code **)(param_1[1] + 0x28);
          if (pcVar7 == (code *)0x0) {
            nvAssertFailedNoLog("NULL != pWalk->pCb->CopyEntries","src/libraries/mmu/mmu_walk.c",
                                0x4bf);
            pcVar7 = *(code **)(param_1[1] + 0x28);
          }
          puVar12 = &local_44;
          (*pcVar7)(*param_1,*param_2,lVar5,*(undefined8 *)(local_40[0] + 0x38),0,uVar9 - 1);
          if (uVar9 != local_44) {
            nvAssertFailedNoLog("progress == entryIndexLo","src/libraries/mmu/mmu_walk.c",0x4c7,
                                puVar12);
          }
          (**(code **)(param_1[1] + 8))(*param_1,*param_2,*(undefined8 *)(local_40[0] + 8),lVar5);
        }
        if ((*(char *)((long)param_1 + 0x89) != '\0') &&
           ((**(code **)(param_1[1] + 0x20))
                      (*param_1,*param_2,*(undefined8 *)(local_40[0] + 0x38),
                       (ulong)uVar10 / (ulong)bVar1,uVar4,(uint)param_10 + (uint)param_10,&local_44)
           , uVar11 - uVar9 != local_44)) {
          nvAssertFailedNoLog("progress == entryIndexHi - entryIndexLo + 1",
                              "src/libraries/mmu/mmu_walk.c",0x4d8);
        }
        goto LAB_0050fade;
      }
      iVar3 = 0x40;
      nvAssertFailedNoLog("NV_OK == status","src/libraries/mmu/mmu_walk.c",0x4b9);
    }
    else {
      nvAssertFailedNoLog("NV_OK == status","src/libraries/mmu/mmu_walk.c",0x4a3);
    }
    if (local_61 == 0) {
      return iVar3;
    }
  }
  else {
    if (param_5 != '\x01' || param_6 != '\0') {
      *param_9 = 0;
      return 0;
    }
    if (param_7 != '\0') {
      nvAssertFailedNoLog("!bCommit","src/libraries/mmu/mmu_walk.c",0x474);
      return 0x40;
    }
    local_40[0] = portMemAllocNonPaged(0x60);
    if (local_40[0] == 0) {
      nvAssertFailedNoLog("NV_OK == status","src/libraries/mmu/mmu_walk.c",0x47c);
    }
    else {
      portMemSet(local_40[0],0,0x60);
      *(ulong *)(local_40[0] + 8) = -(1L << (*(char *)(*param_2 + 1) + 1U & 0x3f)) & param_3;
      lVar5 = 1L << (*(char *)(*param_2 + 1) + 1U & 0x3f);
      *(ulong *)(local_40[0] + 0x10) = lVar5 + -1 + (-lVar5 & param_4);
      iVar3 = btreeInsert(local_40[0],param_2 + 3);
      lVar5 = local_40[0];
      if (iVar3 != 0) {
        nvAssertFailedNoLog("NV_OK == status","src/libraries/mmu/mmu_walk.c",0x484);
        goto LAB_0050fb72;
      }
      iVar3 = 1 << ((((char *)*param_2)[1] - *(char *)*param_2) + 1U & 0x1f);
      uVar6 = portMemAllocNonPaged(iVar3);
      *(undefined8 *)(lVar5 + 0x58) = uVar6;
      if (*(long *)(local_40[0] + 0x58) != 0) {
        portMemSet(*(long *)(local_40[0] + 0x58),0,iVar3);
        uVar10 = 0;
        if (param_10 == 0) {
          pcVar8 = (char *)*param_2;
          local_61 = 1;
          cVar2 = pcVar8[1];
        }
        else {
          do {
            uVar11 = uVar10 + 1;
            mmuWalkSetEntryState(local_40[0],uVar10,4);
            pcVar8 = (char *)*param_2;
            cVar2 = pcVar8[1];
            uVar10 = uVar11;
          } while (uVar11 < (uint)(1 << ((cVar2 - *pcVar8) + 1U & 0x1f)));
          local_61 = param_10;
        }
        goto LAB_0050f94b;
      }
      nvAssertFailedNoLog("NV_OK == status","src/libraries/mmu/mmu_walk.c",0x48a);
    }
    iVar3 = 0x51;
  }
LAB_0050fb72:
  if (local_40[0] != 0) {
    _mmuWalkLevelInstRelease(param_1,param_2);
  }
  return iVar3;
}


// ===== 0050fd10 _mmuWalkPdeAcquire =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _mmuWalkPdeAcquire(undefined8 *param_1,long param_2,long *param_3,long param_4,
                      undefined4 param_5,int param_6,ulong param_7,ulong param_8,long *param_9)

{
  char cVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  long lVar5;
  ulong uVar6;
  byte *pbVar7;
  long *plVar8;
  uint uVar9;
  undefined8 *puVar10;
  bool bVar11;
  byte bVar12;
  byte local_85;
  byte local_59;
  undefined8 local_58 [2];
  long local_48 [3];
  
  local_58[0] = 0;
  local_58[1] = 0;
  bVar12 = *(byte *)(*param_3 + 4);
  local_48[0] = 0;
  local_48[1] = 0;
  if (bVar12 < 2) {
    if (bVar12 != 0) goto LAB_0050fdfc;
    bVar12 = *(byte *)(param_2 + 0x18);
  }
  else {
    lVar5 = 0;
    do {
      iVar2 = btreeSearch(param_7,(long)local_48 + lVar5,
                          *(undefined8 *)(lVar5 * 0xd + param_3[2] + 0x18));
      uVar6 = param_8;
      if (iVar2 == 0) {
        pbVar7 = (byte *)(*(long *)(*param_3 + 0x10) + lVar5 * 3);
        uVar6 = ((ulong)*(uint *)(*(long *)((long)local_48 + lVar5) + 0x40) / (ulong)pbVar7[2] <<
                (*pbVar7 & 0x3f)) + -1 + (-(1L << (pbVar7[1] + 1 & 0x3f)) & param_7);
        if (uVar6 <= param_8) {
          uVar6 = param_8;
        }
      }
      param_8 = uVar6;
      lVar5 = lVar5 + 8;
    } while ((ulong)bVar12 * 8 - lVar5 != 0);
LAB_0050fdfc:
    uVar9 = (uint)bVar12;
    local_85 = 0;
    uVar6 = (ulong)(uVar9 - 1);
    lVar5 = uVar6 * 0x68;
    puVar10 = local_58 + uVar6;
    plVar8 = param_9 + uVar6;
    while( true ) {
      iVar2 = (int)uVar6;
      bVar11 = iVar2 == param_6;
      local_59 = 0;
      bVar12 = *(byte *)(param_1 + 2) & 2;
      if ((*(byte *)(param_1 + 2) & 2) == 0) {
        bVar4 = *(byte *)(param_2 + 0x18);
      }
      else {
        bVar4 = *(byte *)(param_2 + 0x18);
        if (((iVar2 == 0) && (uVar9 != 1)) && ((bVar4 & 2) == 0)) {
          bVar11 = bVar11 || param_9[1] != 0;
          bVar12 = *param_9 == 0;
        }
        else {
          bVar12 = 0;
        }
      }
      iVar3 = _mmuWalkLevelInstAcquire_constprop_0
                        (param_1,param_3[2] + lVar5,param_7,param_8,bVar11,bVar4 >> 1 & 1,
                         bVar4 >> 3 & 1,&local_59,plVar8,bVar12);
      if (iVar3 != 0) {
        nvAssertOkFailedNoLog
                  (iVar3,
                   "_mmuWalkLevelInstAcquire(pWalk, pLevel->subLevels + subLevelIdx, vaLo, vaLimit, bTarget, pOpParams->bRelease, pOpParams->bCommit, &bChanged, &pSubLevelInsts[subLevelIdx], bInitNv4k)"
                   ,"src/libraries/mmu/mmu_walk.c",0x55b);
        return iVar3;
      }
      if (*plVar8 == 0) {
        if (((*(byte *)(param_2 + 0x18) & 2) == 0) && (bVar11 != false)) {
          nvAssertFailedNoLog("pOpParams->bRelease || !bTarget","src/libraries/mmu/mmu_walk.c",0x564
                             );
        }
      }
      else {
        local_85 = local_85 | local_59;
        *puVar10 = *(undefined8 *)(*plVar8 + 0x38);
      }
      puVar10 = puVar10 + -1;
      plVar8 = plVar8 + -1;
      lVar5 = lVar5 + -0x68;
      if (iVar2 == 0) break;
      uVar6 = (ulong)(iVar2 - 1);
    }
    if ((((*(byte *)(param_1 + 2) & 2) != 0) && (uVar9 != 1)) &&
       ((param_9[1] != 0 && (*param_9 == 0)))) {
      nvAssertFailedNoLog(&DAT_00dab09b,"src/libraries/mmu/mmu_walk.c",0x573);
    }
    if (local_85 != 0) goto LAB_0050ffb0;
    bVar12 = *(byte *)(param_2 + 0x18);
  }
  if ((bVar12 & 8) == 0) {
    return 0;
  }
LAB_0050ffb0:
  cVar1 = (**(code **)(param_1[1] + 0x18))
                    (*param_1,*param_3,*(undefined8 *)(param_4 + 0x38),param_5,local_58);
  if (cVar1 != '\0') {
    mmuWalkSetEntryState(param_4,param_5,3);
    return 0;
  }
  nvAssertFailedNoLog("bDone","src/libraries/mmu/mmu_walk.c",0x57d);
  return 0x40;
}


// ===== 005100a0 mmuWalkRootAcquire =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int mmuWalkRootAcquire(undefined8 *param_1,undefined8 param_2,undefined8 param_3,char param_4)

{
  char cVar1;
  int iVar2;
  char local_31;
  long local_30 [2];
  
  local_30[0] = 0;
  local_31 = '\0';
  iVar2 = _mmuWalkLevelInstAcquire_constprop_0
                    (param_1,param_1 + 3,param_2,param_3,1,0,param_4,&local_31,local_30,0);
  if (iVar2 == 0) {
    iVar2 = 0;
    if ((local_31 != '\0') || ((param_4 != '\0' && (local_30[0] != 0)))) {
      cVar1 = (**(code **)(param_1[1] + 0x10))
                        (*param_1,param_1[3],*(undefined8 *)(local_30[0] + 0x38),0);
      if (cVar1 == '\0') {
        iVar2 = 0x40;
        nvAssertFailedNoLog("bDone","src/libraries/mmu/mmu_walk.c",0x2b7);
      }
    }
    return iVar2;
  }
  nvAssertOkFailedNoLog
            (iVar2,
             "_mmuWalkLevelInstAcquire(pWalk, &pWalk->root, vaLo, vaHi, NV_TRUE, NV_FALSE, bCommit, &bChanged, &pLevelInst, NV_FALSE )"
             ,"src/libraries/mmu/mmu_walk.c",0x2aa);
  return iVar2;
}


// ===== 00510190 mmuWalkSetEntryReserved =====

void mmuWalkSetEntryReserved(long param_1,uint param_2,char param_3)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(*(long *)(param_1 + 0x58) + (ulong)param_2);
  if ((char)*pbVar1 < '\0') {
    if (*(int *)(param_1 + 0x4c) == 0) {
      nvAssertFailedNoLog("0 != pLevelInst->numReserved","src/libraries/mmu/mmu_walk.c",0x321);
      pbVar1 = (byte *)((ulong)param_2 + *(long *)(param_1 + 0x58));
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + -1;
      if (param_3 != '\0') {
        *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
      }
      *pbVar1 = *pbVar1 & 0x7f | param_3 << 7;
      return;
    }
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + -1;
  }
  if (param_3 != '\0') {
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  }
  *pbVar1 = *pbVar1 & 0x7f | param_3 << 7;
  return;
}


// ===== 00510240 mmuWalkSetEntryHybrid =====

void mmuWalkSetEntryHybrid(long param_1,uint param_2,byte param_3)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(*(long *)(param_1 + 0x58) + (ulong)param_2);
  if ((*pbVar1 & 0x40) != 0) {
    if (*(int *)(param_1 + 0x50) == 0) {
      nvAssertFailedNoLog("0 != pLevelInst->numHybrid","src/libraries/mmu/mmu_walk.c",0x335);
      pbVar1 = (byte *)((ulong)param_2 + *(long *)(param_1 + 0x58));
      *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + -1;
      if (param_3 != 0) {
        *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
      }
      *pbVar1 = (param_3 & 1) << 6 | *pbVar1 & 0xbf;
      return;
    }
    *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + -1;
  }
  if (param_3 != 0) {
    *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
  }
  *pbVar1 = (param_3 & 1) << 6 | *pbVar1 & 0xbf;
  return;
}


// ===== 005102e0 mmuFmtCalcAlignedEntryIndices =====

void mmuFmtCalcAlignedEntryIndices
               (byte *param_1,uint param_2,uint param_3,byte *param_4,int *param_5,int *param_6)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  
  if ((param_5 == (int *)0x0) || (param_6 == (int *)0x0)) {
    nvAssertFailedNoLog("pIndexLoOut != NULL && pIndexHiOut != NULL","src/libraries/mmu/mmu_walk.c",
                        0x35d);
  }
  if ((param_1 == (byte *)0x0) || (param_4 == (byte *)0x0)) {
    nvAssertFailedNoLog("pPageFmtIn != NULL && pPageFmtOut != NULL","src/libraries/mmu/mmu_walk.c",
                        0x35e);
  }
  uVar3 = 1L << (*param_1 & 0x3f);
  uVar1 = 1L << (*param_4 & 0x3f);
  if (uVar3 < uVar1) {
    uVar1 = uVar1 >> (*param_1 & 0x3f);
    if (uVar1 >> 0x20 != 0) {
      nvAssertFailedNoLog("NvU64_HI32(pageSizeRatio) == 0","src/libraries/mmu/mmu_walk.c",0x366);
    }
    *param_5 = (int)(param_2 / uVar1);
    *param_6 = (int)(param_3 / uVar1);
    return;
  }
  uVar3 = uVar3 >> (*param_4 & 0x3f);
  if (uVar3 >> 0x20 != 0) {
    nvAssertFailedNoLog("NvU64_HI32(pageSizeRatio) == 0","src/libraries/mmu/mmu_walk.c",0x36d);
  }
  iVar2 = (int)uVar3;
  *param_5 = param_2 * iVar2;
  *param_6 = (param_3 + 1) * iVar2 + -1;
  return;
}


// ===== 005104b0 _mmuWalkResolveSubLevelConflicts.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */

undefined8
_mmuWalkResolveSubLevelConflicts_isra_0
          (undefined8 *param_1,undefined8 *param_2,long *param_3,int param_4,ulong param_5,
          ulong param_6)

{
  byte bVar1;
  byte *pbVar2;
  long lVar3;
  uint uVar4;
  long lVar5;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  uint uVar10;
  undefined8 uStack_b0;
  uint local_90;
  uint local_88;
  int *local_80;
  byte *local_68;
  long local_60;
  int local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c [3];
  
  local_68 = (byte *)*param_2;
  local_60 = *param_3;
  pbVar2 = (byte *)param_2[0xd];
  lVar3 = param_3[1];
  local_4c = 0;
  if (param_4 == 0) {
    bVar1 = *local_68;
    uVar7 = ~(-1L << (local_68[1] + 1 & 0x3f)) & -1L << (bVar1 & 0x3f);
    uStack_b0 = 0x510546;
    mmuFmtCalcAlignedEntryIndices
              (local_68,(uVar7 & param_5) >> (bVar1 & 0x3f),(param_6 & uVar7) >> (bVar1 & 0x3f),
               pbVar2,&local_48,&local_44);
    local_68 = pbVar2;
    lVar5 = lVar3;
    local_40 = local_48;
    local_3c[0] = local_44;
  }
  else {
    bVar1 = *pbVar2;
    uVar7 = ~(-1L << (pbVar2[1] + 1 & 0x3f)) & -1L << (bVar1 & 0x3f);
    uVar8 = (param_5 & uVar7) >> (bVar1 & 0x3f);
    uVar7 = (param_6 & uVar7) >> (bVar1 & 0x3f);
    mmuFmtCalcAlignedEntryIndices
              (pbVar2,uVar8 & 0xffffffff,uVar7 & 0xffffffff,local_68,&local_40,local_3c);
    uStack_b0 = 0x5105fe;
    mmuFmtCalcAlignedEntryIndices(local_68,local_40,local_3c[0],pbVar2,&local_48,&local_44);
    lVar5 = local_60;
    if ((param_4 == 1) && (lVar3 != 0)) {
      if (local_60 == 0) {
        return 0;
      }
      bVar1 = *(byte *)(*(long *)(local_60 + 0x58) + (ulong)local_3c[0]);
      local_88 = (uint)uVar7;
      uVar4 = local_44;
      if (((*(byte *)(*(long *)(local_60 + 0x58) + (ulong)local_40) & 0x3f) == 1) &&
         (local_90 = (uint)uVar8, local_48 < local_90)) {
        (**(code **)(param_1[1] + 0x20))
                  (*param_1,pbVar2,*(undefined8 *)(lVar3 + 0x38),local_48,local_90 - 1,1);
        uVar6 = local_48;
        if (local_90 - local_48 != local_4c) {
          nvAssertFailedNoLog("progress == entryIndexLo - indexLo_Small",
                              "src/libraries/mmu/mmu_walk.c",0x412);
          return 0x40;
        }
        for (; uVar4 = local_44, uVar6 <= local_90 - 1; uVar6 = uVar6 + 1) {
          uStack_b0 = 0x510892;
          mmuWalkSetEntryState(lVar3,uVar6,1);
        }
      }
      uVar9 = local_3c[0];
      uVar6 = local_40;
      if (((bVar1 & 0x3f) == 1) && (local_88 < uVar4)) {
        local_80 = &local_4c;
        uVar10 = local_88 + 1;
        (**(code **)(param_1[1] + 0x20))
                  (*param_1,pbVar2,*(undefined8 *)(lVar3 + 0x38),uVar10,uVar4,1,local_80);
        if (uVar4 - local_88 != local_4c) {
          nvAssertFailedNoLog("progress == indexHi_Small - entryIndexHi",
                              "src/libraries/mmu/mmu_walk.c",0x421);
          return 0x40;
        }
        for (; uVar10 <= uVar4; uVar10 = uVar10 + 1) {
          uStack_b0 = 0x5106e2;
          mmuWalkSetEntryState(lVar3,uVar10,1);
        }
      }
      goto LAB_0051071b;
    }
  }
  if (local_60 == 0) {
    return 0;
  }
  uVar9 = local_3c[0];
  uVar6 = local_40;
  local_60 = lVar5;
  if (lVar3 == 0) {
    return 0;
  }
LAB_0051071b:
  local_80 = &local_4c;
  (**(code **)(param_1[1] + 0x20))
            (*param_1,local_68,*(undefined8 *)(local_60 + 0x38),uVar6,uVar9,0,local_80);
  if ((uVar9 + 1) - uVar6 == local_4c) {
    for (; uVar6 <= uVar9; uVar6 = uVar6 + 1) {
      mmuWalkSetEntryState(local_60,uVar6,0);
    }
    return 0;
  }
  nvAssertFailedNoLog("progress == indexHi_tmp - indexLo_tmp + 1","src/libraries/mmu/mmu_walk.c",
                      0x443,uStack_b0);
  return 0x40;
}


// ===== 00510940 mmuWalkProcessPdes =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int mmuWalkProcessPdes(undefined8 *param_1,undefined8 *param_2,long *param_3,long param_4,
                      ulong param_5,ulong param_6)

{
  byte bVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  ulong uVar9;
  long *plVar10;
  ulong uVar11;
  byte bVar12;
  ulong uVar13;
  ulong uVar14;
  byte *pbVar15;
  ulong uVar16;
  ulong uVar17;
  byte *pbVar18;
  uint uVar19;
  bool bVar20;
  int *piVar21;
  ulong local_a0;
  uint local_90;
  uint local_8c;
  ulong local_88;
  ulong local_68;
  ulong local_60;
  uint local_50;
  int local_4c;
  long local_48 [3];
  
  if (param_2 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("pOpParams != NULL","src/libraries/mmu/mmu_walk.c",0x117);
    return 0x1f;
  }
  iVar5 = (*(code *)param_2[1])(param_1,param_2,param_3,param_4,param_5,param_6);
  if (iVar5 != 0x4d) {
    return iVar5;
  }
  pbVar18 = (byte *)*param_3;
  bVar12 = *pbVar18;
  uVar16 = -(1L << (bVar12 & 0x3f)) & ~(-1L << (pbVar18[1] + 1 & 0x3f));
  uVar14 = (param_5 & uVar16) >> (bVar12 & 0x3f);
  local_a0 = (uVar16 & param_6) >> (bVar12 & 0x3f);
  uVar16 = uVar14 & 0xffffffff;
  if ((uint)uVar14 <= (uint)local_a0) {
    iVar5 = 0;
    local_a0 = local_a0 & 0xffffffff;
    local_8c = 0;
    local_90 = 0;
    local_88 = -(1L << (pbVar18[1] + 1 & 0x3f)) & param_5;
    plVar10 = param_3;
    local_68 = param_6;
    local_60 = param_5;
    do {
      uVar19 = (uint)uVar16;
      uVar14 = uVar16 & 0xffffffff;
      local_48[0] = 0;
      local_48[1] = 0;
      pbVar15 = (byte *)(*(long *)(param_4 + 0x58) + uVar14);
      local_50 = 0;
      uVar6 = *pbVar15 & 0x3f;
      bVar20 = uVar6 != 3;
      if ((((*(byte *)(param_2 + 3) & 2) != 0) && (bVar20)) && ((*pbVar15 & 0x40) == 0)) {
LAB_00510e91:
        iVar8 = 0;
        goto LAB_00510ed2;
      }
      uVar17 = local_88 + (uVar14 << (bVar12 & 0x3f));
      uVar11 = (uVar17 - 1) + (1L << (bVar12 & 0x3f));
      if ((*(byte *)(param_2 + 3) & 1) == 0) {
LAB_00510c09:
        uVar4 = local_8c;
        uVar3 = local_90;
        uVar14 = uVar17;
        if (uVar17 <= local_60) {
          uVar14 = local_60;
        }
        uVar9 = uVar11;
        if (local_68 <= uVar11) {
          uVar9 = local_68;
        }
        iVar8 = (*(code *)param_2[2])(*param_2,plVar10,&local_50,uVar14,uVar9);
        if (iVar8 == 0) {
          iVar7 = _mmuWalkPdeAcquire(param_1,param_2,plVar10,param_4,uVar16 & 0xffffffff,local_50,
                                     uVar14,uVar9,local_48);
          if (iVar7 == 0) {
            uVar13 = (ulong)local_50;
            if (((*(byte *)(param_2 + 3) & 2) != 0) && (local_48[uVar13] == 0)) goto LAB_00510ed2;
            if (uVar6 == 1) {
              if (uVar17 < local_60) {
                iVar8 = mmuWalkProcessPdes(param_1,g_opParamsSparsify,uVar13 * 0x68 + plVar10[2],
                                           local_48[uVar13],uVar17,uVar14 - 1);
                if (iVar8 != 0) {
                  nvAssertFailedNoLog("NV_OK == status","src/libraries/mmu/mmu_walk.c",0x1c9);
                  goto LAB_00510ea8;
                }
                uVar13 = (ulong)local_50;
              }
              if (local_68 < uVar11) {
                iVar8 = mmuWalkProcessPdes(param_1,g_opParamsSparsify,uVar13 * 0x68 + plVar10[2],
                                           local_48[uVar13],uVar9 + 1,uVar11);
                if (iVar8 != 0) {
                  nvAssertFailedNoLog("NV_OK == status","src/libraries/mmu/mmu_walk.c",0x1d8);
                  goto LAB_00510ea8;
                }
                uVar13 = (ulong)local_50;
              }
            }
            if ((*(char *)(*plVar10 + 4) != '\x01') && ((*(byte *)(param_2 + 3) & 4) == 0)) {
              iVar8 = _mmuWalkResolveSubLevelConflicts_isra_0
                                (param_1,plVar10[2],local_48,uVar13,uVar14,uVar9);
              if (iVar8 != 0) {
                nvAssertFailedNoLog("NV_OK == status","src/libraries/mmu/mmu_walk.c",0x1e7);
                iVar8 = 0x40;
                goto LAB_00510ea8;
              }
              uVar13 = (ulong)local_50;
            }
            iVar8 = (*(code *)param_2[1])
                              (param_1,param_2,uVar13 * 0x68 + plVar10[2],local_48[uVar13],uVar14,
                               uVar9);
            if (iVar8 == 0x4d) {
              plVar10[4] = param_4;
              *(uint *)((long)plVar10 + 0x44) = uVar19;
              plVar10[5] = local_60;
              param_4 = local_48[local_50];
              plVar10[6] = local_68;
              plVar10[7] = local_88;
              *(uint *)(plVar10 + 8) = (uint)local_a0;
              local_90 = 0;
              *(uint *)(plVar10 + 9) = uVar3;
              local_8c = 0;
              *(uint *)((long)plVar10 + 0x4c) = uVar4;
              *(int *)(plVar10 + 10) = iVar5;
              plVar10[0xb] = uVar17;
              plVar10 = (long *)((ulong)local_50 * 0x68 + plVar10[2]);
              bVar12 = ((byte *)*plVar10)[1];
              bVar1 = *(byte *)*plVar10;
              local_88 = -(1L << (bVar12 + 1 & 0x3f)) & uVar14;
              uVar11 = -(1L << (bVar1 & 0x3f)) & ~(-1L << (bVar12 + 1 & 0x3f));
              uVar16 = (uVar14 & uVar11) >> (bVar1 & 0x3f);
              local_a0 = (uVar11 & uVar9) >> (bVar1 & 0x3f);
              local_68 = uVar9;
              local_60 = uVar14;
              iVar5 = 0;
              goto LAB_00510dea;
            }
            if (iVar8 != 0) {
              nvAssertFailedNoLog("NV_OK == status","src/libraries/mmu/mmu_walk.c",0x21d);
            }
          }
          else {
            nvAssertFailedNoLog("NV_OK == status","src/libraries/mmu/mmu_walk.c",0x1ad);
            iVar8 = iVar7;
          }
        }
        else {
          nvAssertFailedNoLog("NV_OK == status","src/libraries/mmu/mmu_walk.c",0x19e);
        }
LAB_00510ea8:
        _mmuWalkPdeRelease(param_1,param_2,plVar10,param_4,uVar16 & 0xffffffff,uVar17);
LAB_00510ed2:
        if ((plVar10 == param_3) && (uVar19 == (uint)local_a0)) {
          return iVar8;
        }
        do {
          uVar19 = (uint)uVar16;
          if ((uint)local_a0 != uVar19) goto LAB_00510f75;
          while( true ) {
            plVar10 = (long *)plVar10[1];
            if (plVar10 == (long *)0x0) {
              nvAssertFailedNoLog("pLevel->pParent != NULL","src/libraries/mmu/mmu_walk.c",0x25a);
              return 0x40;
            }
            local_60 = plVar10[5];
            param_4 = plVar10[4];
            uVar19 = *(uint *)((long)plVar10 + 0x44);
            uVar16 = (ulong)uVar19;
            local_a0._0_4_ = *(uint *)(plVar10 + 8);
            local_68 = plVar10[6];
            local_88 = plVar10[7];
            local_90 = *(uint *)(plVar10 + 9);
            local_8c = *(uint *)((long)plVar10 + 0x4c);
            iVar5 = (int)plVar10[10];
            _mmuWalkPdeRelease(param_1,param_2,plVar10,param_4,uVar16,plVar10[0xb]);
            if (plVar10 != param_3) break;
            if ((uint)local_a0 == uVar19) {
              return iVar8;
            }
LAB_00510f75:
            if (iVar8 == 0) {
              local_a0 = (ulong)(uint)local_a0;
              goto LAB_00510f84;
            }
          }
        } while( true );
      }
      puVar2 = (uint *)*param_2;
      if (iVar5 != 0) {
        if (((uVar6 != *puVar2) && (local_60 <= uVar17 && bVar20)) && (uVar11 <= local_68)) {
          iVar5 = iVar5 + 1;
          local_8c = uVar19;
          if (uVar19 < (uint)local_a0) goto LAB_00510f84;
          if (iVar5 == 0) goto LAB_00510bf4;
        }
LAB_00510b38:
        piVar21 = &local_4c;
        local_4c = 0;
        (**(code **)(param_1[1] + 0x20))
                  (*param_1,pbVar18,*(undefined8 *)(param_4 + 0x38),local_90,local_8c,puVar2[1]);
        uVar3 = local_90;
        if ((local_8c + 1) - local_90 == local_4c) {
          for (; uVar3 <= local_8c; uVar3 = uVar3 + 1) {
            mmuWalkSetEntryState(param_4,uVar3,*puVar2);
          }
          pbVar15 = (byte *)(*(long *)(param_4 + 0x58) + uVar14);
LAB_00510bf4:
          iVar5 = 0;
          if (*puVar2 == (*pbVar15 & 0x3f)) goto LAB_00510e91;
          goto LAB_00510c09;
        }
        nvAssertFailedNoLog(&DAT_00dab09b,"src/libraries/mmu/mmu_walk.c",0x187,piVar21);
        iVar8 = 0x40;
        goto LAB_00510ea8;
      }
      local_90 = uVar19;
      local_8c = uVar19;
      if (((*puVar2 == uVar6) || (uVar17 < local_60 || !bVar20)) || (local_68 < uVar11))
      goto LAB_00510bf4;
      iVar5 = 1;
      if ((uint)local_a0 <= uVar19) goto LAB_00510b38;
LAB_00510f84:
      uVar16 = (ulong)(uVar19 + 1);
LAB_00510dea:
      if ((uint)local_a0 < (uint)uVar16) goto LAB_0051114f;
      pbVar18 = (byte *)*plVar10;
      bVar12 = *pbVar18;
    } while( true );
  }
LAB_0051120e:
  nvAssertFailedNoLog("pLevel != pLevelOrig","src/libraries/mmu/mmu_walk.c",0x289);
  return 0x40;
LAB_0051114f:
  if (plVar10 != param_3) {
    return 0;
  }
  goto LAB_0051120e;
}


// ===== 00511230 mmuWalkGetTraceInfo =====

void mmuWalkGetTraceInfo(long param_1,uint param_2,undefined8 param_3)

{
  if (param_2 < 7) {
    memcpy(param_3,param_1 + 0x90 + (ulong)param_2 * 0x220,0x220);
    return;
  }
  nvAssertFailedNoLog("level < MMU_TRACE_MAX_LEVEL","src/libraries/mmu/mmu_walk.c",0x640);
  return;
}


// ===== 00511280 mmuWalkSetTraceInfo =====

void mmuWalkSetTraceInfo(long param_1,uint param_2,undefined8 param_3)

{
  if (param_2 < 7) {
    memcpy(param_1 + 0x90 + (ulong)param_2 * 0x220,param_3,0x220);
    return;
  }
  nvAssertFailedNoLog("level < MMU_TRACE_MAX_LEVEL","src/libraries/mmu/mmu_walk.c",0x64c);
  return;
}


// ===== 005112d0 _mmuWalkCommitPDEsSelectSubLevel =====

undefined8 _mmuWalkCommitPDEsSelectSubLevel(long param_1,long *param_2,uint *param_3)

{
  byte bVar1;
  uint uVar2;
  long lVar3;
  
  bVar1 = *(byte *)(*param_2 + 4);
  if (bVar1 == 1) {
    *param_3 = 0;
    return 0;
  }
  if (bVar1 != 0) {
    lVar3 = *(long *)(*param_2 + 0x10);
    uVar2 = 0;
    do {
      if (param_1 == lVar3) {
        *param_3 = uVar2;
        return 0;
      }
      uVar2 = uVar2 + 1;
      lVar3 = lVar3 + 0x18;
    } while (uVar2 != bVar1);
  }
  return 0x40;
}


// ===== 00511330 _mmuWalkCommitPDEs =====

undefined8 _mmuWalkCommitPDEs(undefined8 param_1,long *param_2,long *param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if ((*param_3 != *param_2) && (uVar1 = 0x4d, *(char *)(*param_3 + 4) == '\0')) {
    nvAssertFailedNoLog("0 != pLevel->pFmt->numSubLevels","src/libraries/mmu/mmu_walk_commit.c",0x58
                       );
    return 0x1f;
  }
  return uVar1;
}


// ===== 00511380 mmuWalkCommitPDEs =====

ulong mmuWalkCommitPDEs(long param_1,byte *param_2,ulong param_3,long param_4)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  byte *local_48;
  code *local_40;
  code *local_38;
  ulong local_30;
  
  local_48 = (byte *)0x0;
  local_40 = (code *)0x0;
  local_38 = (code *)0x0;
  local_30 = 0;
  lVar2 = mmuWalkFindLevel();
  if (lVar2 == 0) {
    nvAssertFailedNoLog("NULL != mmuWalkFindLevel(pWalk, pLevelFmt)",
                        "src/libraries/mmu/mmu_walk_commit.c",0x2d);
    return 0x1f;
  }
  uVar3 = ~(-1L << (*param_2 & 0x3f));
  if ((param_3 & uVar3) == 0) {
    if ((param_4 + 1U & uVar3) != 0) {
      nvAssertFailedNoLog("NV_IS_ALIGNED(vaHi + 1, mmuFmtLevelPageSize(pLevelFmt))",
                          "src/libraries/mmu/mmu_walk_commit.c",0x31);
      return 0x1f;
    }
    uVar1 = mmuWalkRootAcquire(param_1,param_3,param_4,1);
    if (uVar1 == 0) {
      local_30 = local_30 | 0xc;
      local_40 = _mmuWalkCommitPDEs;
      local_38 = _mmuWalkCommitPDEsSelectSubLevel;
      local_48 = param_2;
      uVar3 = mmuWalkProcessPdes(param_1,&local_48,param_1 + 0x18,*(undefined8 *)(param_1 + 0x30),
                                 param_3,param_4);
    }
    else {
      nvAssertFailedNoLog("NV_OK == status","src/libraries/mmu/mmu_walk_commit.c",0x36);
      uVar3 = (ulong)uVar1;
    }
  }
  else {
    nvAssertFailedNoLog("NV_IS_ALIGNED(vaLo, mmuFmtLevelPageSize(pLevelFmt))",
                        "src/libraries/mmu/mmu_walk_commit.c",0x2f);
    uVar3 = 0x1f;
  }
  return uVar3;
}


// ===== 005114f0 mmuWalkFill =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */

undefined8
mmuWalkFill(undefined8 *param_1,undefined8 *param_2,long *param_3,long param_4,ulong param_5,
           ulong param_6)

{
  char cVar1;
  byte *pbVar2;
  undefined4 *puVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  int iVar7;
  byte bVar8;
  ulong uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  ulong uVar13;
  int *piVar14;
  uint local_70;
  int local_60;
  int local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  long local_48;
  long local_40 [2];
  
  if (param_4 == 0) {
    return 0;
  }
  pbVar2 = (byte *)*param_3;
  if (pbVar2[4] != 0) {
    return 0x4d;
  }
  bVar8 = *pbVar2;
  puVar3 = (undefined4 *)*param_2;
  local_60 = 0;
  if (pbVar2[3] == 0) {
    nvAssertFailedNoLog("pLevel->pFmt->bPageTable","src/libraries/mmu/mmu_walk_fill.c",0x57);
    return 0x1f;
  }
  uVar9 = ~(-1L << (pbVar2[1] + 1 & 0x3f)) & -1L << (bVar8 & 0x3f);
  uVar13 = (param_5 & uVar9) >> (bVar8 & 0x3f);
  uVar9 = (param_6 & uVar9) >> (bVar8 & 0x3f);
  uVar10 = (uint)uVar13;
  bVar8 = (pbVar2[1] - *pbVar2) + 1;
  if ((uVar13 & 0xffffffff) >> (bVar8 & 0x3f) != (uVar9 & 0xffffffff) >> (bVar8 & 0x3f)) {
    nvAssertFailedNoLog("(entryIndexLo / numEntries) == (entryIndexHi / numEntries)",
                        "src/libraries/mmu/mmu_walk_fill.c",0x5a);
    return 0x1f;
  }
  local_70 = (uint)uVar9;
  if ((param_1[0x10] == 0) || (*(char *)(param_1 + 0x11) == '\0')) {
    (**(code **)(param_1[1] + 0x20))
              (*param_1,pbVar2,*(undefined8 *)(param_4 + 0x38),uVar13 & 0xffffffff,
               uVar9 & 0xffffffff,puVar3[1],&local_60);
  }
  else {
    iVar7 = 1 << (bVar8 & 0x1f);
    uVar11 = iVar7 - 1;
    (**(code **)(param_1[1] + 0x20))
              (*param_1,pbVar2,param_1[0x10],uVar11 & uVar10,uVar11 & local_70,puVar3[1],&local_60);
    (**(code **)(param_1[1] + 0x30))
              (*param_1,param_1[0x10],*(undefined8 *)(param_4 + 0x38),uVar13 & 0xffffffff,
               uVar9 & 0xffffffff,iVar7,*(undefined1 *)(*param_3 + 2));
  }
  uVar11 = local_70 + 1;
  if (uVar11 - uVar10 != local_60) {
    nvAssertFailedNoLog("progress == entryIndexHi - entryIndexLo + 1",
                        "src/libraries/mmu/mmu_walk_fill.c",0x82);
    return 0x40;
  }
  if (uVar10 <= local_70) {
    uVar13 = uVar13 & 0xffffffff;
    do {
      uVar12 = (int)uVar13 + 1;
      mmuWalkSetEntryState(param_4,uVar13,*puVar3);
      uVar13 = (ulong)uVar12;
    } while (uVar12 <= local_70);
  }
  if ((*(byte *)(param_1 + 2) & 2) == 0) {
    return 0;
  }
  if (puVar3[1] != 0) {
    return 0;
  }
  cVar1 = *(char *)*param_3;
  local_5c = 0;
  plVar4 = *(long **)(param_3[1] + 0x10);
  local_48 = 0;
  local_40[0] = 0;
  param_5 = -1L << (*(char *)(*plVar4 + 1) + 1U & 0x3f) & param_5;
  btreeSearch(param_5,&local_48,plVar4[3]);
  btreeSearch(param_5,local_40,plVar4[0x10]);
  if (cVar1 != '\f') {
    if (cVar1 == '\x10') {
      mmuFmtCalcAlignedEntryIndices(*plVar4,uVar10,local_70,plVar4[0xd],&local_58,&local_54);
      lVar5 = local_40[0];
      if (local_40[0] != 0) {
        for (; local_58 <= local_54; local_58 = local_58 + 1) {
          iVar7 = mmuWalkGetEntryState(lVar5,local_58);
          if (iVar7 != 0) {
            nvAssertFailedNoLog("_isRangeAllInvalid(pLevel4KInst, indexLo_4K, indexHi_4K)",
                                "src/libraries/mmu/mmu_walk_fill.c",0x163);
            goto LAB_005118ce;
          }
        }
      }
      (**(code **)(param_1[1] + 0x20))
                (*param_1,*plVar4,*(undefined8 *)(local_48 + 0x38),uVar10,uVar9 & 0xffffffff,2,
                 &local_5c);
      if (uVar11 - uVar10 == local_5c) {
        for (; uVar10 <= local_70; uVar10 = uVar10 + 1) {
          mmuWalkSetEntryState(local_48,uVar10,4);
        }
        return 0;
      }
      nvAssertFailedNoLog("progress == entryIndexHi - entryIndexLo + 1",
                          "src/libraries/mmu/mmu_walk_fill.c",0x16a);
    }
    else {
      nvAssertFailedNoLog(&DAT_00dab6aa,"src/libraries/mmu/mmu_walk_fill.c",0x177);
    }
    goto LAB_005118ce;
  }
  mmuFmtCalcAlignedEntryIndices(plVar4[0xd],uVar10,local_70,*plVar4,&local_50,&local_4c);
  mmuFmtCalcAlignedEntryIndices(*plVar4,local_50,local_4c,plVar4[0xd],&local_58,&local_54);
  lVar5 = local_40[0];
  if (local_50 == local_4c) {
    if ((local_40[0] != 0) && (uVar10 = local_58, local_58 <= local_54)) {
      do {
        iVar7 = mmuWalkGetEntryState(lVar5,uVar10);
        if (iVar7 != 0) {
          local_50 = local_50 + 1;
          break;
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 <= local_54);
      goto LAB_00511a72;
    }
  }
  else {
    if (local_58 < uVar10) {
      if (local_40[0] != 0) {
        uVar12 = local_58;
        if (local_58 <= uVar10 - 1) {
          do {
            iVar7 = mmuWalkGetEntryState(lVar5,uVar12);
            if (iVar7 != 0) {
              local_50 = local_50 + 1;
              break;
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 <= uVar10 - 1);
          goto LAB_00511a19;
        }
        uVar10 = local_54;
        if (local_54 <= local_70) goto LAB_00511a72;
        goto joined_r0x00511a3a;
      }
    }
    else {
LAB_00511a19:
      if ((local_70 < local_54) && (lVar5 = local_40[0], uVar10 = local_54, local_40[0] != 0)) {
joined_r0x00511a3a:
        for (; lVar6 = local_40[0], local_40[0] = lVar5, uVar11 <= uVar10; uVar11 = uVar11 + 1) {
          iVar7 = mmuWalkGetEntryState(lVar6,uVar11);
          if (iVar7 != 0) {
            local_4c = local_4c - 1;
            break;
          }
          lVar5 = local_40[0];
          local_40[0] = lVar6;
        }
      }
    }
LAB_00511a72:
    if (local_4c < local_50) {
      return 0;
    }
  }
  piVar14 = &local_5c;
  (**(code **)(param_1[1] + 0x20))
            (*param_1,*plVar4,*(undefined8 *)(local_48 + 0x38),local_50,local_4c,2);
  if ((local_4c + 1) - local_50 == local_5c) {
    uVar10 = local_50;
    if (local_50 <= local_4c) {
      do {
        uVar11 = uVar10 + 1;
        mmuWalkSetEntryState(local_48,uVar10,4);
        uVar10 = uVar11;
      } while (uVar11 <= local_4c);
    }
    return 0;
  }
  nvAssertFailedNoLog("progress == indexHi_64K - indexLo_64K + 1",
                      "src/libraries/mmu/mmu_walk_fill.c",0x14d,piVar14);
LAB_005118ce:
  nvAssertFailedNoLog("status == NV_OK","src/libraries/mmu/mmu_walk_fill.c",0x8d);
  return 0x40;
}


// ===== 00511bc0 mmuWalkFillSelectSubLevel =====

long mmuWalkFillSelectSubLevel
               (undefined8 param_1,long *param_2,undefined4 *param_3,ulong param_4,long param_5)

{
  long lVar1;
  byte bVar2;
  long lVar3;
  undefined8 local_40 [2];
  
  lVar1 = *param_2;
  if (*(char *)(lVar1 + 4) == '\x01') {
    *param_3 = 0;
    return 0;
  }
  if (*(char *)(lVar1 + 4) == '\0') {
    lVar1 = 0x40;
  }
  else {
    lVar3 = 0;
    bVar2 = 0;
    do {
      while ((~(-1L << (*(byte *)(*(long *)(lVar1 + 0x10) + lVar3 * 0x18) & 0x3f)) &
             (param_5 + 1U | param_4)) == 0) {
        local_40[0] = 0;
        if (bVar2 == 0) {
          *param_3 = (int)lVar3;
        }
        lVar1 = btreeSearch(param_4,local_40,*(undefined8 *)(lVar3 * 0x68 + param_2[2] + 0x18));
        if ((int)lVar1 == 0) {
          *param_3 = (int)lVar3;
          return lVar1;
        }
        lVar1 = *param_2;
        lVar3 = lVar3 + 1;
        bVar2 = 1;
        if ((uint)*(byte *)(lVar1 + 4) <= (uint)lVar3) goto LAB_00511cb2;
      }
      lVar3 = lVar3 + 1;
    } while ((uint)lVar3 < (uint)*(byte *)(lVar1 + 4));
LAB_00511cb2:
    lVar1 = (ulong)(bVar2 ^ 1) << 6;
  }
  return lVar1;
}


// ===== 00511d10 mmuWalkGetPageLevelInfo =====

undefined8
mmuWalkGetPageLevelInfo
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,
          undefined4 *param_5)

{
  long lVar1;
  undefined8 uVar2;
  long local_30 [2];
  
  lVar1 = mmuWalkFindLevel();
  *param_4 = 0;
  local_30[0] = 0;
  *param_5 = 0;
  if (lVar1 == 0) {
    nvAssertFailedNoLog("NULL != pLevel","src/libraries/mmu/mmu_walk_info.c",0x2e);
    return 0x1f;
  }
  uVar2 = btreeSearch(param_3,local_30,*(undefined8 *)(lVar1 + 0x18));
  if ((int)uVar2 != 0) {
    return 0;
  }
  *param_4 = *(undefined8 *)(local_30[0] + 0x38);
  *param_5 = *(undefined4 *)(local_30[0] + 0x40);
  return uVar2;
}


// ===== 00511dc0 _mmuWalkMapSelectSubLevel =====

undefined8 _mmuWalkMapSelectSubLevel(long *param_1,long *param_2,uint *param_3)

{
  byte bVar1;
  uint uVar2;
  long lVar3;
  
  bVar1 = *(byte *)(*param_2 + 4);
  if (bVar1 == 1) {
    *param_3 = 0;
    return 0;
  }
  if (bVar1 != 0) {
    lVar3 = *(long *)(*param_2 + 0x10);
    uVar2 = 0;
    do {
      if (*param_1 == lVar3) {
        *param_3 = uVar2;
        return 0;
      }
      uVar2 = uVar2 + 1;
      lVar3 = lVar3 + 0x18;
    } while (uVar2 != bVar1);
  }
  return 0x40;
}


// ===== 00511e30 _mmuWalkMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _mmuWalkMap(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,long param_4,
               ulong param_5,ulong param_6)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  ulong uVar4;
  uint uVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  uint uVar10;
  int local_3c [3];
  
  if (param_4 == 0) {
    nvAssertFailedNoLog("NULL != pLevelInst","src/libraries/mmu/mmu_walk_map.c",0x6e);
    return 0x1f;
  }
  if (param_3 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("NULL != pLevel","src/libraries/mmu/mmu_walk_map.c",0x6f);
    return 0x1f;
  }
  pbVar2 = (byte *)*param_3;
  param_2 = (undefined8 *)*param_2;
  if (pbVar2 != (byte *)*param_2) {
    if (pbVar2[4] != 0) {
      return 0x4d;
    }
    nvAssertFailedNoLog("0 != pLevel->pFmt->numSubLevels","src/libraries/mmu/mmu_walk_map.c",0x74);
    return 0x1f;
  }
  bVar1 = *pbVar2;
  local_3c[0] = 0;
  uVar4 = ~(-1L << (pbVar2[1] + 1 & 0x3f)) & -(1L << (bVar1 & 0x3f));
  uVar8 = (param_5 & uVar4) >> (bVar1 & 0x3f);
  uVar7 = (param_6 & uVar4) >> (bVar1 & 0x3f);
  uVar5 = (uint)uVar8;
  uVar4 = uVar8 & 0xffffffff;
  uVar10 = (uint)uVar7;
  if (pbVar2[4] == 0) {
    (*(code *)param_2[2])
              (*param_1,param_2,*(undefined8 *)(param_4 + 0x38),uVar8 & 0xffffffff,
               uVar7 & 0xffffffff,local_3c);
    if ((uVar10 + 1) - uVar5 == local_3c[0]) goto joined_r0x00511fd6;
  }
  else if (uVar10 < uVar5) {
    (*(code *)param_2[2])
              (*param_1,param_2,*(undefined8 *)(param_4 + 0x38),uVar8 & 0xffffffff,
               uVar7 & 0xffffffff,local_3c);
    if (local_3c[0] == (uVar10 + 1) - uVar5) {
      return 0;
    }
  }
  else {
    bVar1 = pbVar2[1];
    uVar4 = uVar8 & 0xffffffff;
    do {
      iVar3 = mmuWalkGetEntryState(param_4,uVar4);
      if (iVar3 != 2) {
        lVar6 = (uVar4 << (*(byte *)*param_3 & 0x3f)) + (-(1L << (bVar1 + 1 & 0x3f)) & param_5);
        iVar3 = mmuWalkProcessPdes(param_1,g_opParamsUnmap,param_3,param_4,lVar6,
                                   lVar6 + -1 + (1L << (*(byte *)*param_3 & 0x3f)));
        if (iVar3 != 0) {
          nvAssertOkFailedNoLog
                    (iVar3,
                     "mmuWalkProcessPdes(pWalk, &g_opParamsUnmap, pLevel, pLevelInst, entryVaLo, entryVaHi)"
                     ,"src/libraries/mmu/mmu_walk_map.c",0x8e);
          return iVar3;
        }
        iVar3 = mmuWalkGetEntryState(param_4,uVar4);
        if (iVar3 == 3) {
          mmuWalkSetEntryHybrid(param_4,uVar4,1);
        }
      }
      uVar9 = (int)uVar4 + 1;
      uVar4 = (ulong)uVar9;
    } while (uVar9 <= uVar10);
    uVar4 = uVar8 & 0xffffffff;
    (*(code *)param_2[2])
              (*param_1,param_2,*(undefined8 *)(param_4 + 0x38),uVar4,uVar7 & 0xffffffff,local_3c);
    if (local_3c[0] == (uVar10 + 1) - uVar5) {
      do {
        uVar5 = (int)uVar4 + 1;
        mmuWalkSetEntryState(param_4,uVar4,2);
        uVar4 = (ulong)uVar5;
joined_r0x00511fd6:
      } while (uVar5 <= uVar10);
      return 0;
    }
  }
  nvAssertFailedNoLog("progress == entryIndexHi - entryIndexLo + 1",
                      "src/libraries/mmu/mmu_walk_map.c",0xaa);
  return 0x40;
}


// ===== 00512150 mmuWalkMap =====

ulong mmuWalkMap(long param_1,ulong param_2,ulong param_3,long param_4)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  char *pcVar4;
  uint local_4c;
  long local_48;
  code *local_40;
  code *local_38;
  undefined8 local_30;
  
  local_48 = 0;
  local_40 = (code *)0x0;
  local_38 = (code *)0x0;
  local_30 = 0;
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pWalk","src/libraries/mmu/mmu_walk_map.c",0x34);
  }
  else if (param_4 == 0) {
    nvAssertFailedNoLog("NULL != pTarget","src/libraries/mmu/mmu_walk_map.c",0x35);
  }
  else {
    if (param_2 <= param_3) {
      local_4c = mmuWalkRootAcquire();
      if (local_4c != 0) {
        uVar3 = 0x3a;
        pcVar4 = "NV_OK == status";
LAB_005122aa:
        nvAssertFailedNoLog(pcVar4,"src/libraries/mmu/mmu_walk_map.c",uVar3);
        return (ulong)local_4c;
      }
      local_40 = _mmuWalkMap;
      local_38 = _mmuWalkMapSelectSubLevel;
      local_48 = param_4;
      uVar2 = mmuWalkProcessPdes(param_1,&local_48,param_1 + 0x18,*(undefined8 *)(param_1 + 0x30),
                                 param_2,param_3);
      local_4c = (uint)uVar2;
      if (local_4c != 0) {
        nvDbg_Printf("src/libraries/mmu/mmu_walk_map.c",0x48,"mmuWalkMap",4,
                     "NVRM: Failed to map VA Range 0x%llx to 0x%llx. Status = 0x%08x\n",param_2,
                     param_3,uVar2);
        nvAssertFailedNoLog(&DAT_00dab821,"src/libraries/mmu/mmu_walk_map.c",0x4b);
        iVar1 = mmuWalkUnmap(param_1,param_2,param_3);
        if (iVar1 != 0) {
          nvDbg_Printf("src/libraries/mmu/mmu_walk_map.c",0x51,"mmuWalkMap",4,
                       "NVRM: Unmap failed with status = 0x%08x\n",iVar1);
          uVar3 = 0x54;
          pcVar4 = "NV_OK == unmapStatus";
          goto LAB_005122aa;
        }
      }
      return uVar2 & 0xffffffff;
    }
    nvAssertFailedNoLog("vaLo <= vaHi","src/libraries/mmu/mmu_walk_map.c",0x36);
  }
  return 0x1f;
}


// ===== 00512370 mmuWalkModifyLevelInstance =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int mmuWalkModifyLevelInstance
              (undefined8 *param_1,long param_2,ulong param_3,long param_4,uint param_5,char param_6
              ,char param_7,undefined1 param_8)

{
  byte bVar1;
  byte bVar2;
  long lVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  undefined8 *puVar7;
  long lVar8;
  long lVar9;
  uint uVar10;
  long *plVar11;
  uint uVar12;
  uint uVar13;
  undefined8 uStack_a0;
  int local_64;
  long local_60;
  long local_58;
  long local_50 [4];
  
  puVar7 = (undefined8 *)mmuWalkFindLevel();
  local_60 = 0;
  if (*(long *)(param_1[1] + 0x28) == 0) {
    nvAssertFailedNoLog("NULL != pWalk->pCb->CopyEntries","src/libraries/mmu/mmu_walk_migrate.c",
                        0x34);
    return 0x56;
  }
  if (puVar7 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("NULL != pLevel","src/libraries/mmu/mmu_walk_migrate.c",0x37);
    return 0x1f;
  }
  uStack_a0 = 0x5123d2;
  iVar6 = btreeSearch(param_3,&local_60,puVar7[3]);
  if (iVar6 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar6,"btreeSearch(vaBase, (NODE**)&pLevelInst, &pLevel->pInstances->node)",
               "src/libraries/mmu/mmu_walk_migrate.c",0x3a);
    return iVar6;
  }
  if (local_60 == 0) {
    nvAssertFailedNoLog("NULL != pLevelInst","src/libraries/mmu/mmu_walk_migrate.c",0x3b);
    return 0x1f;
  }
  lVar3 = *(long *)(local_60 + 0x38);
  uVar13 = *(uint *)(local_60 + 0x40);
  *(long *)(local_60 + 0x38) = param_4;
  *(uint *)(local_60 + 0x40) = param_5;
  if (param_7 == '\0') {
    if (param_6 != '\0') goto LAB_00512519;
    if (puVar7[1] != 0) goto LAB_005125a0;
LAB_005125e7:
    cVar5 = (**(code **)(param_1[1] + 0x10))(*param_1,param_1[3],param_4,param_8);
    if (cVar5 == '\0') {
      nvAssertFailedNoLog("bDone","src/libraries/mmu/mmu_walk_migrate.c",0x73);
    }
  }
  else {
    if (*(ulong *)(local_60 + 8) != param_3) {
      nvAssertFailedNoLog("vaBase == pLevelInst->node.keyStart",
                          "src/libraries/mmu/mmu_walk_migrate.c",0x4b);
      return 0x1f;
    }
    if (param_6 == '\0') {
      plVar11 = (long *)puVar7[1];
      if (plVar11 == (long *)0x0) goto LAB_005125e7;
    }
    else {
LAB_00512519:
      uVar13 = uVar13 / *(byte *)(param_2 + 2);
      uVar12 = uVar13 - 1;
      param_5 = param_5 / *(byte *)(param_2 + 2);
      uVar10 = param_5 - 1;
      uVar4 = uVar10;
      if (uVar12 <= uVar10) {
        uVar4 = uVar12;
      }
      (**(code **)(param_1[1] + 0x28))(*param_1,*puVar7,lVar3,param_4,0,uVar4,&local_64);
      if (uVar4 + 1 != local_64) {
        uStack_a0 = 0x512828;
        nvAssertFailedNoLog("progress == entryIndexHiCopy + 1",
                            "src/libraries/mmu/mmu_walk_migrate.c",0x5c);
      }
      if ((uVar12 < uVar10) &&
         ((**(code **)(param_1[1] + 0x20))(*param_1,*puVar7,param_4,uVar13,uVar10,0,&local_64),
         param_5 - uVar13 != local_64)) {
        nvAssertFailedNoLog("progress == entryIndexHiNew - entryIndexHiOld",
                            "src/libraries/mmu/mmu_walk_migrate.c",0x68,uStack_a0);
      }
      plVar11 = (long *)puVar7[1];
      if (plVar11 == (long *)0x0) goto LAB_005125e7;
      if (param_7 == '\0') goto LAB_005125a0;
    }
    local_58 = 0;
    local_50[1] = 0;
    local_50[2] = 0;
    bVar1 = ((byte *)*plVar11)[1];
    bVar2 = *(byte *)*plVar11;
    iVar6 = btreeSearch(param_3,&local_58,plVar11[3]);
    if (iVar6 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar6,"btreeSearch(vaBase, (NODE**)&pParentInst, &pParent->pInstances->node)",
                 "src/libraries/mmu/mmu_walk_migrate.c",0x80);
      return iVar6;
    }
    if (local_58 == 0) {
      nvAssertFailedNoLog("NULL != pParentInst","src/libraries/mmu/mmu_walk_migrate.c",0x81);
    }
    lVar9 = *plVar11;
    if (*(char *)(lVar9 + 4) != '\0') {
      lVar8 = 0;
      uVar13 = 0;
      do {
        if (puVar7 == (undefined8 *)(plVar11[2] + lVar8)) {
          local_50[(ulong)uVar13 + 1] = param_4;
        }
        else {
          local_50[0] = 0;
          iVar6 = btreeSearch(param_3,local_50,((undefined8 *)(plVar11[2] + lVar8))[3]);
          if (iVar6 != 0) {
            nvCheckOkFailedNoLog
                      (4,iVar6,
                       "btreeSearch(vaBase, (NODE**)&pOtherInst, &pSubLevel->pInstances->node)",
                       "src/libraries/mmu/mmu_walk_migrate.c",0x91);
            return iVar6;
          }
          if (local_50[0] != 0) {
            local_50[(ulong)uVar13 + 1] = *(undefined8 *)(local_50[0] + 0x38);
          }
        }
        lVar9 = *plVar11;
        uVar13 = uVar13 + 1;
        lVar8 = lVar8 + 0x68;
      } while (uVar13 < *(byte *)(lVar9 + 4));
    }
    cVar5 = (**(code **)(param_1[1] + 0x18))
                      (*param_1,lVar9,*(undefined8 *)(local_58 + 0x38),
                       (-1L << (bVar2 & 0x3f) & param_3 & ~(-1L << (bVar1 + 1 & 0x3f))) >>
                       (bVar2 & 0x3f),local_50 + 1,*(code **)(param_1[1] + 0x18));
    if (cVar5 == '\0') {
      nvAssertFailedNoLog("bDone","src/libraries/mmu/mmu_walk_migrate.c",0x9c);
    }
  }
LAB_005125a0:
  if ((lVar3 == param_4) && (*(byte *)(lVar3 + 100) < 2)) {
    return 0;
  }
  (**(code **)(param_1[1] + 8))(*param_1,*puVar7,*(undefined8 *)(local_60 + 8),lVar3);
  return 0;
}


// ===== 00512890 mmuWalkMigrateLevelInstance =====

void mmuWalkMigrateLevelInstance(void)

{
  mmuWalkModifyLevelInstance();
  return;
}


// ===== 005128b0 _mmuWalkReserveSelectSubLevel =====

undefined8 _mmuWalkReserveSelectSubLevel(long param_1,long *param_2,uint *param_3)

{
  byte bVar1;
  uint uVar2;
  long lVar3;
  
  bVar1 = *(byte *)(*param_2 + 4);
  if (bVar1 == 1) {
    *param_3 = 0;
    return 0;
  }
  if (bVar1 != 0) {
    lVar3 = *(long *)(*param_2 + 0x10);
    uVar2 = 0;
    do {
      if (param_1 == lVar3) {
        *param_3 = uVar2;
        return 0;
      }
      uVar2 = uVar2 + 1;
      lVar3 = lVar3 + 0x18;
    } while (uVar2 != bVar1);
  }
  return 0x40;
}


// ===== 00512910 _mmuWalkReserveEntries =====

undefined8
_mmuWalkReserveEntries
          (undefined8 param_1,undefined8 *param_2,undefined8 *param_3,undefined8 param_4,
          ulong param_5,ulong param_6)

{
  byte bVar1;
  byte *pbVar2;
  ulong uVar3;
  undefined8 uVar4;
  uint uVar5;
  ulong uVar6;
  
  pbVar2 = (byte *)*param_3;
  if (pbVar2 == (byte *)*param_2) {
    bVar1 = *pbVar2;
    uVar3 = ~(-1L << (pbVar2[1] + 1 & 0x3f)) & -1L << (bVar1 & 0x3f);
    uVar6 = (param_5 & uVar3) >> (bVar1 & 0x3f);
    uVar5 = (uint)uVar6;
    uVar6 = uVar6 & 0xffffffff;
    while (uVar5 <= (uint)((param_6 & uVar3) >> (bVar1 & 0x3f))) {
      uVar5 = (int)uVar6 + 1;
      mmuWalkSetEntryReserved(param_4,uVar6,1);
      uVar6 = (ulong)uVar5;
    }
    return 0;
  }
  uVar4 = 0x4d;
  if (pbVar2[4] == 0) {
    nvAssertFailedNoLog("0 != pLevel->pFmt->numSubLevels","src/libraries/mmu/mmu_walk_reserve.c",
                        0x97);
    uVar4 = 0x1f;
  }
  return uVar4;
}


// ===== 005129f0 _mmuWalkReleaseEntries =====

undefined8
_mmuWalkReleaseEntries
          (undefined8 param_1,undefined8 *param_2,undefined8 *param_3,undefined8 param_4,
          ulong param_5,ulong param_6)

{
  byte bVar1;
  byte *pbVar2;
  ulong uVar3;
  undefined8 uVar4;
  uint uVar5;
  ulong uVar6;
  
  pbVar2 = (byte *)*param_3;
  if (pbVar2 == (byte *)*param_2) {
    bVar1 = *pbVar2;
    uVar3 = ~(-1L << (pbVar2[1] + 1 & 0x3f)) & -1L << (bVar1 & 0x3f);
    uVar6 = (param_5 & uVar3) >> (bVar1 & 0x3f);
    uVar5 = (uint)uVar6;
    uVar6 = uVar6 & 0xffffffff;
    while (uVar5 <= (uint)((param_6 & uVar3) >> (bVar1 & 0x3f))) {
      uVar5 = (int)uVar6 + 1;
      mmuWalkSetEntryReserved(param_4,uVar6,0);
      uVar6 = (ulong)uVar5;
    }
    return 0;
  }
  uVar4 = 0x4d;
  if (pbVar2[4] == 0) {
    nvAssertFailedNoLog("0 != pLevel->pFmt->numSubLevels","src/libraries/mmu/mmu_walk_reserve.c",
                        0xbc);
    uVar4 = 0x1f;
  }
  return uVar4;
}


// ===== 00512ad0 mmuWalkReleaseEntries =====

int mmuWalkReleaseEntries(long param_1,byte *param_2,ulong param_3,long param_4)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  char *pcVar5;
  byte *local_48;
  code *local_40;
  code *local_38;
  ulong local_30;
  
  local_48 = (byte *)0x0;
  local_40 = (code *)0x0;
  local_38 = (code *)0x0;
  local_30 = 0;
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pWalk","src/libraries/mmu/mmu_walk_reserve.c",0x66);
  }
  else {
    lVar2 = mmuWalkFindLevel();
    uVar4 = 0x68;
    pcVar5 = "NULL != mmuWalkFindLevel(pWalk, pLevelFmt)";
    if (lVar2 != 0) {
      uVar4 = 0x6a;
      pcVar5 = "NV_IS_ALIGNED(vaLo, mmuFmtLevelPageSize(pLevelFmt))";
      uVar3 = ~(-1L << (*param_2 & 0x3f));
      if ((uVar3 & param_3) == 0) {
        if ((param_4 + 1U & uVar3) == 0) {
          if (*(long *)(param_1 + 0x30) != 0) {
            local_30 = local_30 | 6;
            local_40 = _mmuWalkReleaseEntries;
            local_38 = _mmuWalkReserveSelectSubLevel;
            local_48 = param_2;
            iVar1 = mmuWalkProcessPdes(param_1,&local_48,param_1 + 0x18,*(long *)(param_1 + 0x30),
                                       param_3,param_4);
            if (iVar1 == 0) {
              mmuWalkRootRelease(param_1);
            }
            else {
              nvAssertFailedNoLog("NV_OK == status","src/libraries/mmu/mmu_walk_reserve.c",0x7c);
            }
            return iVar1;
          }
          return 0;
        }
        uVar4 = 0x6c;
        pcVar5 = "NV_IS_ALIGNED(vaHi + 1, mmuFmtLevelPageSize(pLevelFmt))";
      }
    }
    nvAssertFailedNoLog(pcVar5,"src/libraries/mmu/mmu_walk_reserve.c",uVar4);
  }
  return 0x1f;
}


// ===== 00512c70 mmuWalkReserveEntries =====

int mmuWalkReserveEntries(long param_1,byte *param_2,ulong param_3,long param_4,undefined1 param_5)

{
  int iVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  byte *local_58;
  code *local_50;
  code *local_48;
  ulong local_40;
  
  local_58 = (byte *)0x0;
  local_50 = (code *)0x0;
  local_48 = (code *)0x0;
  local_40 = 0;
  lVar3 = mmuWalkFindLevel();
  if (lVar3 == 0) {
    nvAssertFailedNoLog("NULL != mmuWalkFindLevel(pWalk, pLevelFmt)",
                        "src/libraries/mmu/mmu_walk_reserve.c",0x2f);
  }
  else {
    uVar4 = ~(-1L << (*param_2 & 0x3f));
    if ((param_3 & uVar4) == 0) {
      if ((param_4 + 1U & uVar4) == 0) {
        iVar1 = mmuWalkRootAcquire(param_1,param_3,param_4,0);
        if (iVar1 != 0) {
          nvAssertFailedNoLog("NV_OK == status","src/libraries/mmu/mmu_walk_reserve.c",0x38);
          return iVar1;
        }
        if (*(char *)(param_1 + 0x89) != '\0') {
          *(undefined1 *)(param_1 + 0x89) = param_5;
          local_40 = local_40 | 4;
          local_50 = _mmuWalkReserveEntries;
          local_48 = _mmuWalkReserveSelectSubLevel;
          local_58 = param_2;
          iVar1 = mmuWalkProcessPdes(param_1,&local_58,param_1 + 0x18,
                                     *(undefined8 *)(param_1 + 0x30),param_3,param_4);
          if ((iVar1 != 0) &&
             (iVar2 = mmuWalkReleaseEntries(param_1,param_2,param_3,param_4), iVar2 != 0)) {
            nvAssertFailedNoLog("NV_OK == tmpStatus","src/libraries/mmu/mmu_walk_reserve.c",0x51);
          }
          *(undefined1 *)(param_1 + 0x89) = 1;
          return iVar1;
        }
        nvAssertFailedNoLog("pWalk->bInvalidateOnReserve","src/libraries/mmu/mmu_walk_reserve.c",
                            0x39);
        return 0x40;
      }
      nvAssertFailedNoLog("NV_IS_ALIGNED(vaHi + 1, mmuFmtLevelPageSize(pLevelFmt))",
                          "src/libraries/mmu/mmu_walk_reserve.c",0x33);
    }
    else {
      nvAssertFailedNoLog("NV_IS_ALIGNED(vaLo, mmuFmtLevelPageSize(pLevelFmt))",
                          "src/libraries/mmu/mmu_walk_reserve.c",0x31);
    }
  }
  return 0x1f;
}


// ===== 00512e60 mmuWalkSparsify =====

ulong mmuWalkSparsify(long param_1,ulong param_2,ulong param_3,undefined1 param_4)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pWalk","src/libraries/mmu/mmu_walk_sparse.c",0x30);
  }
  else {
    if (param_2 <= param_3) {
      uVar1 = mmuWalkRootAcquire();
      if (uVar1 == 0) {
        *(undefined1 *)(param_1 + 0x88) = param_4;
        uVar3 = mmuWalkProcessPdes(param_1,g_opParamsSparsify,param_1 + 0x18,
                                   *(undefined8 *)(param_1 + 0x30),param_2,param_3);
        if ((int)uVar3 != 0) {
          nvDbg_Printf("src/libraries/mmu/mmu_walk_sparse.c",0x44,"mmuWalkSparsify",4,
                       "NVRM: Failed to sparsify VA Range 0x%llx to 0x%llx. Status = 0x%08x\n",
                       param_2,param_3,uVar3);
          nvAssertFailedNoLog(&DAT_00dabc94,"src/libraries/mmu/mmu_walk_sparse.c",0x47);
          iVar2 = mmuWalkUnmap(param_1,param_2,param_3);
          if (iVar2 != 0) {
            nvDbg_Printf("src/libraries/mmu/mmu_walk_sparse.c",0x4f,"mmuWalkSparsify",4,
                         "NVRM: Unmap failed with status = 0x%08x\n",iVar2);
            nvAssertFailedNoLog("NV_OK == unmapStatus","src/libraries/mmu/mmu_walk_sparse.c",0x52);
          }
        }
        uVar3 = uVar3 & 0xffffffff;
        *(undefined1 *)(param_1 + 0x88) = 0;
      }
      else {
        nvAssertFailedNoLog("NV_OK == status","src/libraries/mmu/mmu_walk_sparse.c",0x35);
        uVar3 = (ulong)uVar1;
      }
      return uVar3;
    }
    nvAssertFailedNoLog("vaLo <= vaHi","src/libraries/mmu/mmu_walk_sparse.c",0x31);
  }
  return 0x1f;
}


// ===== 00513030 mmuWalkUnmap =====

int mmuWalkUnmap(long param_1,ulong param_2,ulong param_3,undefined8 param_4)

{
  int iVar1;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pWalk","src/libraries/mmu/mmu_walk_unmap.c",0x2f);
  }
  else {
    if (param_2 <= param_3) {
      iVar1 = 0;
      if (*(long *)(param_1 + 0x30) != 0) {
        iVar1 = mmuWalkProcessPdes(param_1,g_opParamsUnmap,param_1 + 0x18);
        if (iVar1 != 0) {
          nvDbg_Printf("src/libraries/mmu/mmu_walk_unmap.c",0x3b,"mmuWalkUnmap",4,
                       "NVRM: Failed to unmap VA Range 0x%llx to 0x%llx. Status = 0x%08x\n",param_2,
                       param_3);
          nvAssertFailedNoLog(&DAT_00dabd6d,"src/libraries/mmu/mmu_walk_unmap.c",0x3e);
        }
        mmuWalkRootRelease(param_1);
      }
      return iVar1;
    }
    nvAssertFailedNoLog("vaLo <= vaHi","src/libraries/mmu/mmu_walk_unmap.c",0x30,param_4,param_2);
  }
  return 0x1f;
}


// ===== 00513150 msgqGetMetaSize =====

undefined8 msgqGetMetaSize(void)

{
  return 0xe8;
}


// ===== 00513160 msgqInit =====

undefined8 msgqInit(long *param_1,long param_2)

{
  if (param_2 != 0) {
    portMemSet(param_2,0,0xe8);
    if (param_1 != (long *)0x0) {
      *param_1 = param_2;
    }
    return 0;
  }
  return 0xffffffff;
}


// ===== 005131a0 msgqTxCreate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
msgqTxCreate(ulong *param_1,ulong param_2,uint param_3,uint param_4,int param_5,int param_6,
            uint param_7)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  
  if (((((param_1 != (ulong *)0x0) && ((char)param_1[0xf] == '\0')) && (0xf < param_4)) &&
      ((param_4 <= param_3 && (param_5 - 3U < 10)))) &&
     ((param_6 - 3U < 10 && ((param_2 != 0 && ((param_2 & param_5 - 1) == 0)))))) {
    iVar2 = 1 << ((byte)param_5 & 0x1f);
    uVar3 = iVar2 + 0x1fU & -iVar2;
    iVar2 = 1 << ((byte)param_6 & 0x1f);
    *(uint *)(param_1 + 0xd) = uVar3;
    uVar1 = uVar3 + 3 + iVar2 & -iVar2;
    *(uint *)((long)param_1 + 0x6c) = uVar1;
    if (uVar1 + param_4 <= param_3) {
      uVar4 = uVar3 + param_2;
      param_1[10] = (ulong)param_3 << 0x20;
      *(uint *)((long)param_1 + 100) = param_7;
      uVar3 = (param_3 - uVar1) / param_4;
      *(uint *)(param_1 + 0xb) = param_4;
      *(undefined4 *)(param_1 + 0xc) = 0;
      *param_1 = param_2;
      param_1[2] = uVar4;
      param_1[4] = uVar1 + param_2;
      *(undefined1 *)(param_1 + 0xf) = 1;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(uint *)((long)param_1 + 0x5c) = uVar3;
      *(uint *)((long)param_1 + 0x74) = uVar3 - 1;
      if (((param_7 & 1) == 0) || ((param_1[0x12] & 1) == 0)) {
        *(undefined1 *)((long)param_1 + 0xa5) = 0;
        param_1[9] = param_2 + 0x10;
        param_1[6] = uVar4;
        if (*(char *)((long)param_1 + 0xa4) != '\0') {
          param_1[8] = param_1[3];
        }
      }
      else {
        param_1[9] = param_2 + 0x10;
        *(undefined1 *)((long)param_1 + 0xa5) = 1;
        param_1[8] = uVar4;
        param_1[6] = param_1[3];
      }
      if ((code *)param_1[0x1b] != (code *)0x0) {
        (*(code *)param_1[0x1b])(param_2,0x20,(ulong)(param_3 - uVar1) % (ulong)param_4);
      }
      if ((code *)param_1[0x17] == (code *)0x0) {
        portMemCopy(param_2,0x20,param_1 + 10,0x20);
      }
      else {
        iVar2 = (*(code *)param_1[0x17])(param_2,param_1 + 10,0x20,0x101,param_1[0x18]);
        if (iVar2 != 0) {
          return 0xffffffff;
        }
      }
      if ((code *)param_1[0x1a] != (code *)0x0) {
        (*(code *)param_1[0x1a])(param_2,0x20);
      }
      if ((code *)param_1[0x1c] != (code *)0x0) {
        (*(code *)param_1[0x1c])();
      }
      if ((code *)param_1[0x15] != (code *)0x0) {
        (*(code *)param_1[0x15])(0,param_1[0x16]);
      }
      return 0;
    }
  }
  return 0xffffffff;
}


// ===== 005133f0 msgqRxLink =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 msgqRxLink(long param_1,long param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  long lVar5;
  
  if ((param_1 != 0) && (*(char *)(param_1 + 0xa4) == '\0')) {
    if (param_4 < 0x10) {
      uVar4 = 0xfffffffe;
    }
    else if (param_3 < param_4) {
      uVar4 = 0xfffffffd;
    }
    else if (param_2 == 0) {
      uVar4 = 0xfffffffb;
    }
    else {
      *(long *)(param_1 + 8) = param_2;
      lVar5 = param_2;
      if (*(code **)(param_1 + 200) != (code *)0x0) {
        (**(code **)(param_1 + 200))(param_2,0x20);
        lVar5 = *(long *)(param_1 + 8);
      }
      if (*(code **)(param_1 + 0xb8) == (code *)0x0) {
        portMemCopy(param_1 + 0x7c,0x20,lVar5,0x20);
      }
      else {
        iVar2 = (**(code **)(param_1 + 0xb8))
                          (param_1 + 0x7c,lVar5,0x20,0,*(undefined8 *)(param_1 + 0xc0));
        if (iVar2 != 0) {
          return 0xfffffff5;
        }
      }
      uVar1 = *(uint *)(param_1 + 0x98);
      if (param_3 < uVar1 + param_4) {
        uVar4 = 0xfffffffa;
      }
      else if (*(uint *)(param_1 + 0x80) == param_3) {
        if (*(uint *)(param_1 + 0x84) == param_4) {
          if (*(int *)(param_1 + 0x7c) == 0) {
            if (((*(uint *)(param_1 + 0x94) < 0x20) ||
                ((ulong)uVar1 < (ulong)*(uint *)(param_1 + 0x68) + 4)) ||
               (*(uint *)(param_1 + 0x88) != (param_3 - uVar1) / param_4)) {
              uVar4 = 0xfffffff6;
            }
            else {
              *(undefined1 *)(param_1 + 0xa4) = 1;
              puVar3 = (undefined4 *)((ulong)*(uint *)(param_1 + 0x94) + param_2);
              *(undefined4 **)(param_1 + 0x18) = puVar3;
              lVar5 = *(long *)(param_1 + 8) + 0x10;
              *(ulong *)(param_1 + 0x28) = param_2 + (ulong)uVar1;
              if (((*(byte *)(param_1 + 100) & 1) == 0) || ((*(byte *)(param_1 + 0x90) & 1) == 0)) {
                *(undefined1 *)(param_1 + 0xa5) = 0;
                *(long *)(param_1 + 0x38) = lVar5;
                *(undefined4 **)(param_1 + 0x40) = puVar3;
                if (*(char *)(param_1 + 0x78) != '\0') {
                  *(undefined8 *)(param_1 + 0x30) = *(undefined8 *)(param_1 + 0x10);
                }
              }
              else {
                *(undefined1 *)(param_1 + 0xa5) = 1;
                *(long *)(param_1 + 0x38) = lVar5;
                *(undefined4 **)(param_1 + 0x40) = *(undefined4 **)(param_1 + 0x10);
                *(undefined4 **)(param_1 + 0x30) = puVar3;
                puVar3 = *(undefined4 **)(param_1 + 0x10);
              }
              if (*(code **)(param_1 + 0xd8) != (code *)0x0) {
                (**(code **)(param_1 + 0xd8))(puVar3,4);
                puVar3 = *(undefined4 **)(param_1 + 0x40);
              }
              *(undefined4 *)(param_1 + 0x9c) = 0;
              if (*(code **)(param_1 + 0xb8) == (code *)0x0) {
                *puVar3 = 0;
              }
              else {
                iVar2 = (**(code **)(param_1 + 0xb8))
                                  (puVar3,param_1 + 0x9c,4,
                                   (uint)(*(char *)(param_1 + 0xa5) != '\0') << 8 | 1,
                                   *(undefined8 *)(param_1 + 0xc0));
                if (iVar2 != 0) {
                  return 0xfffffff4;
                }
              }
              if (*(code **)(param_1 + 0xd0) != (code *)0x0) {
                (**(code **)(param_1 + 0xd0))(*(undefined8 *)(param_1 + 0x40),4);
              }
              if (*(code **)(param_1 + 0xe0) != (code *)0x0) {
                (**(code **)(param_1 + 0xe0))();
              }
              if (*(code **)(param_1 + 0xa8) != (code *)0x0) {
                (**(code **)(param_1 + 0xa8))(1,*(undefined8 *)(param_1 + 0xb0));
              }
              uVar4 = 0;
            }
          }
          else {
            uVar4 = 0xfffffff7;
          }
        }
        else {
          uVar4 = 0xfffffff8;
        }
      }
      else {
        uVar4 = 0xfffffff9;
      }
    }
    return uVar4;
  }
  return 0xffffffff;
}


// ===== 00513770 msgqTxGetFreeSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint msgqTxGetFreeSpace(long param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_1 != 0) && (*(char *)(param_1 + 0x78) != '\0')) {
    if (*(code **)(param_1 + 0xb8) != (code *)0x0) {
      iVar1 = (**(code **)(param_1 + 0xb8))
                        (param_1 + 0x70,*(uint **)(param_1 + 0x30),4,
                         (ulong)(*(char *)(param_1 + 0xa5) == '\0') << 8,
                         *(undefined8 *)(param_1 + 0xc0));
      if (iVar1 == 0) {
        uVar3 = *(uint *)(param_1 + 0x5c);
        if (*(uint *)(param_1 + 0x70) < uVar3) {
          uVar2 = ((uVar3 - 1) - *(int *)(param_1 + 0x60)) + *(uint *)(param_1 + 0x70);
          if (uVar3 <= uVar2) {
            uVar2 = uVar2 - uVar3;
          }
          *(uint *)(param_1 + 0x74) = uVar2;
          return uVar2;
        }
      }
      return 0;
    }
    uVar3 = **(uint **)(param_1 + 0x30);
    uVar2 = *(uint *)(param_1 + 0x5c);
    *(uint *)(param_1 + 0x70) = uVar3;
    if (uVar3 < uVar2) {
      uVar3 = ((uVar2 - 1) - *(int *)(param_1 + 0x60)) + uVar3;
      if (uVar2 <= uVar3) {
        uVar3 = uVar3 - uVar2;
      }
      *(uint *)(param_1 + 0x74) = uVar3;
      return uVar3;
    }
  }
  return 0;
}


// ===== 00513830 msgqTxGetWriteBuffer =====

long msgqTxGetWriteBuffer(long param_1,uint param_2)

{
  uint uVar1;
  
  if ((param_1 != 0) && (*(char *)(param_1 + 0x78) != '\0')) {
    if (*(uint *)(param_1 + 0x74) <= param_2) {
      uVar1 = msgqTxGetFreeSpace();
      if (uVar1 <= param_2) {
        return 0;
      }
    }
    uVar1 = *(uint *)(param_1 + 0x5c);
    param_2 = *(int *)(param_1 + 0x60) + param_2;
    if (param_2 < uVar1) {
      uVar1 = 0;
    }
    return (ulong)((param_2 - uVar1) * *(int *)(param_1 + 0x58)) + *(long *)(param_1 + 0x20);
  }
  return 0;
}


// ===== 005138a0 msgqTxSubmitBuffers =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

undefined8 msgqTxSubmitBuffers(long param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if ((param_1 == 0) || (*(char *)(param_1 + 0x78) == '\0')) {
    return 0xffffffff;
  }
  if ((*(uint *)(param_1 + 0x74) < param_2) && (uVar3 = msgqTxGetFreeSpace(), uVar3 < param_2)) {
    return 0xffffffff;
  }
  if (*(code **)(param_1 + 0xd0) != (code *)0x0) {
    (**(code **)(param_1 + 0xd0))
              (*(undefined8 *)(param_1 + 0x20),*(int *)(param_1 + 0x58) * *(int *)(param_1 + 0x5c));
  }
  uVar1 = *(int *)(param_1 + 0x60) + param_2;
  uVar3 = *(uint *)(param_1 + 0x5c);
  if (uVar1 < *(uint *)(param_1 + 0x5c)) {
    uVar3 = 0;
  }
  iVar2 = uVar1 - uVar3;
  *(int *)(param_1 + 0x60) = iVar2;
  if (*(code **)(param_1 + 0xb8) == (code *)0x0) {
    **(int **)(param_1 + 0x48) = iVar2;
  }
  else {
    iVar2 = (**(code **)(param_1 + 0xb8))
                      (*(int **)(param_1 + 0x48),param_1 + 0x60,4,0x101,
                       *(undefined8 *)(param_1 + 0xc0));
    if (iVar2 != 0) {
      uVar3 = *(uint *)(param_1 + 0x60);
      if (uVar3 < param_2) {
        uVar3 = uVar3 + *(int *)(param_1 + 0x5c);
      }
      *(uint *)(param_1 + 0x60) = uVar3 - param_2;
      return 0xfffffffe;
    }
  }
  *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) - param_2;
  if (*(code **)(param_1 + 0xd0) != (code *)0x0) {
    (**(code **)(param_1 + 0xd0))(*(undefined8 *)(param_1 + 0x48),4);
  }
  if (*(code **)(param_1 + 0xe0) != (code *)0x0) {
    (**(code **)(param_1 + 0xe0))();
  }
  if (*(code **)(param_1 + 0xa8) != (code *)0x0) {
    (**(code **)(param_1 + 0xa8))(0,*(undefined8 *)(param_1 + 0xb0));
  }
  return 0;
}


// ===== 005139c0 msgqRxGetReadAvailable =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint msgqRxGetReadAvailable(long param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_1 != 0) && (*(char *)(param_1 + 0xa4) != '\0')) {
    if (*(code **)(param_1 + 0xb8) != (code *)0x0) {
      iVar1 = (**(code **)(param_1 + 0xb8))
                        (param_1 + 0x8c,*(uint **)(param_1 + 0x38),4,0,
                         *(undefined8 *)(param_1 + 0xc0));
      if (iVar1 == 0) {
        uVar3 = *(uint *)(param_1 + 0x88);
        if (*(uint *)(param_1 + 0x8c) < uVar3) {
          uVar2 = (uVar3 - *(int *)(param_1 + 0x9c)) + *(uint *)(param_1 + 0x8c);
          if (uVar3 <= uVar2) {
            uVar2 = uVar2 - uVar3;
          }
          *(uint *)(param_1 + 0xa0) = uVar2;
          return uVar2;
        }
      }
      return 0;
    }
    uVar3 = **(uint **)(param_1 + 0x38);
    uVar2 = *(uint *)(param_1 + 0x88);
    *(uint *)(param_1 + 0x8c) = uVar3;
    if (uVar3 < uVar2) {
      uVar3 = (uVar2 - *(int *)(param_1 + 0x9c)) + uVar3;
      if (uVar2 <= uVar3) {
        uVar3 = uVar3 - uVar2;
      }
      *(uint *)(param_1 + 0xa0) = uVar3;
      return uVar3;
    }
  }
  return 0;
}


// ===== 00513a80 msgqRxGetReadBuffer =====

long msgqRxGetReadBuffer(long param_1,uint param_2)

{
  uint uVar1;
  
  if ((param_1 != 0) && (*(char *)(param_1 + 0xa4) != '\0')) {
    if (*(uint *)(param_1 + 0xa0) <= param_2) {
      uVar1 = msgqRxGetReadAvailable();
      if (uVar1 <= param_2) {
        return 0;
      }
    }
    uVar1 = *(uint *)(param_1 + 0x88);
    param_2 = *(int *)(param_1 + 0x9c) + param_2;
    if (param_2 < uVar1) {
      uVar1 = 0;
    }
    return (ulong)((param_2 - uVar1) * *(int *)(param_1 + 0x84)) + *(long *)(param_1 + 0x28);
  }
  return 0;
}


// ===== 00513b00 msgqRxMarkConsumed =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 msgqRxMarkConsumed(long param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if ((param_1 == 0) || (*(char *)(param_1 + 0xa4) == '\0')) {
    return 0xffffffff;
  }
  if ((*(uint *)(param_1 + 0xa0) < param_2) && (uVar3 = msgqRxGetReadAvailable(), uVar3 < param_2))
  {
    return 0xffffffff;
  }
  uVar1 = *(int *)(param_1 + 0x9c) + param_2;
  uVar3 = *(uint *)(param_1 + 0x88);
  if (uVar1 < *(uint *)(param_1 + 0x88)) {
    uVar3 = 0;
  }
  iVar2 = uVar1 - uVar3;
  *(int *)(param_1 + 0x9c) = iVar2;
  if (*(code **)(param_1 + 0xb8) == (code *)0x0) {
    **(int **)(param_1 + 0x40) = iVar2;
  }
  else {
    iVar2 = (**(code **)(param_1 + 0xb8))
                      (*(int **)(param_1 + 0x40),param_1 + 0x9c,4,
                       (uint)(*(char *)(param_1 + 0xa5) != '\0') << 8 | 1,
                       *(undefined8 *)(param_1 + 0xc0));
    if (iVar2 != 0) {
      uVar3 = *(uint *)(param_1 + 0x9c);
      if (uVar3 < param_2) {
        uVar3 = uVar3 + *(int *)(param_1 + 0x88);
      }
      *(uint *)(param_1 + 0x9c) = uVar3 - param_2;
      return 0xfffffffe;
    }
  }
  *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) - param_2;
  if (*(code **)(param_1 + 0xd0) != (code *)0x0) {
    (**(code **)(param_1 + 0xd0))(*(undefined8 *)(param_1 + 0x40),4);
  }
  if (*(code **)(param_1 + 0xe0) != (code *)0x0) {
    (**(code **)(param_1 + 0xe0))();
  }
  if (*(code **)(param_1 + 0xa8) != (code *)0x0) {
    (**(code **)(param_1 + 0xa8))(1,*(undefined8 *)(param_1 + 0xb0));
  }
  return 0;
}


// ===== 00513c40 bitVectorClrAll_IMPL =====

undefined8 bitVectorClrAll_IMPL(long param_1,ushort param_2)

{
  if (param_1 != 0) {
    portMemSet(param_1,0,(ulong)(((int)(param_2 - 1) >> 6) + 1) << 3);
    return 0;
  }
  nvAssertFailedNoLog("NULL != pBitVector","src/libraries/nvbitvector/nvbitvector.c",0x3e);
  return 0x1f;
}


// ===== 00513c90 bitVectorClr_IMPL =====

undefined8 bitVectorClr_IMPL(long param_1,uint param_2,uint param_3)

{
  ulong *puVar1;
  byte bVar2;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBitVector","src/libraries/nvbitvector/nvbitvector.c",0x53);
  }
  else {
    if (param_3 < param_2) {
      bVar2 = (byte)param_3 & 0x3f;
      puVar1 = (ulong *)(param_1 + (ulong)(param_3 >> 6) * 8);
      *puVar1 = *puVar1 & (-2L << bVar2 | 0xfffffffffffffffeU >> 0x40 - bVar2);
      return 0;
    }
    nvAssertFailedNoLog("idx < bitVectorLast","src/libraries/nvbitvector/nvbitvector.c",0x54);
  }
  return 0x1f;
}


// ===== 00513d00 bitVectorClrRange_IMPL =====

undefined8 bitVectorClrRange_IMPL(long param_1,ushort param_2,ulong param_3,ulong param_4)

{
  ulong *puVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  ulong uVar5;
  uint uVar6;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBitVector","src/libraries/nvbitvector/nvbitvector.c",0x6a);
  }
  else if ((ulong)(long)(int)(param_2 - 1) < param_4) {
    nvAssertFailedNoLog("rangeContains(rangeMake(0, bitVectorLast - 1), range)",
                        "src/libraries/nvbitvector/nvbitvector.c",0x6b);
  }
  else {
    uVar5 = param_3 & 0xffffffff;
    uVar3 = (ushort)param_3;
    while( true ) {
      while( true ) {
        if ((ushort)param_4 < uVar3) {
          return 0;
        }
        uVar4 = (uint)uVar5;
        uVar6 = uVar4 & 0xffff;
        bVar2 = (byte)uVar5;
        if ((((uVar5 & 0x3f) != 0) || (param_4 < uVar6 + 0x3f)) || (uVar6 + 0x3f < param_3)) break;
        uVar5 = (ulong)(uVar4 + 0x40);
        *(undefined8 *)(param_1 + (ulong)(uint)((int)uVar6 >> 6) * 8) = 0;
        uVar3 = (ushort)(uVar4 + 0x40);
      }
      if (param_2 <= uVar6) break;
      uVar5 = (ulong)(uVar4 + 1);
      puVar1 = (ulong *)(param_1 + (ulong)(uVar6 >> 6) * 8);
      *puVar1 = *puVar1 & ~(1L << (bVar2 & 0x3f));
      uVar3 = (ushort)(uVar4 + 1);
    }
    nvAssertFailedNoLog("idx < bitVectorLast","src/libraries/nvbitvector/nvbitvector.c",0x54);
  }
  return 0x1f;
}


// ===== 00513df0 bitVectorSetAll_IMPL =====

undefined8 bitVectorSetAll_IMPL(long param_1,ushort param_2)

{
  ulong *puVar1;
  uint uVar2;
  
  if (param_1 != 0) {
    uVar2 = (int)(param_2 - 1) >> 6;
    portMemSet(param_1,0xff,(ulong)(uVar2 + 1) << 3);
    puVar1 = (ulong *)(param_1 + (ulong)uVar2 * 8);
    *puVar1 = *puVar1 & 0xffffffffffffffffU >> (-(char)param_2 & 0x3fU);
    return 0;
  }
  nvAssertFailedNoLog("NULL != pBitVector","src/libraries/nvbitvector/nvbitvector.c",0x92);
  return 0x1f;
}


// ===== 00513e80 bitVectorSet_IMPL =====

undefined8 bitVectorSet_IMPL(long param_1,uint param_2,uint param_3)

{
  ulong *puVar1;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBitVector","src/libraries/nvbitvector/nvbitvector.c",0xaa);
  }
  else {
    if (param_3 < param_2) {
      puVar1 = (ulong *)(param_1 + (ulong)(param_3 >> 6) * 8);
      *puVar1 = *puVar1 | 1L << ((byte)param_3 & 0x3f);
      return 0;
    }
    nvAssertFailedNoLog("idx < bitVectorLast","src/libraries/nvbitvector/nvbitvector.c",0xab);
  }
  return 0x1f;
}


// ===== 00513ef0 bitVectorSetRange_IMPL =====

undefined8 bitVectorSetRange_IMPL(long param_1,ushort param_2,ulong param_3,ulong param_4)

{
  ulong *puVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  ulong uVar5;
  uint uVar6;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBitVector","src/libraries/nvbitvector/nvbitvector.c",0xc2);
  }
  else if ((ulong)(long)(int)(param_2 - 1) < param_4) {
    nvAssertFailedNoLog("rangeContains(rangeMake(0, bitVectorLast - 1), range)",
                        "src/libraries/nvbitvector/nvbitvector.c",0xc3);
  }
  else {
    uVar5 = param_3 & 0xffffffff;
    uVar3 = (ushort)param_3;
    while( true ) {
      while( true ) {
        if ((ushort)param_4 < uVar3) {
          return 0;
        }
        uVar4 = (uint)uVar5;
        uVar6 = uVar4 & 0xffff;
        bVar2 = (byte)uVar5;
        if ((((uVar5 & 0x3f) != 0) || (param_4 < uVar6 + 0x3f)) || (uVar6 + 0x3f < param_3)) break;
        uVar5 = (ulong)(uVar4 + 0x40);
        *(undefined8 *)(param_1 + (ulong)(uint)((int)uVar6 >> 6) * 8) = 0xffffffffffffffff;
        uVar3 = (ushort)(uVar4 + 0x40);
      }
      if (param_2 <= uVar6) break;
      uVar5 = (ulong)(uVar4 + 1);
      puVar1 = (ulong *)(param_1 + (ulong)(uVar6 >> 6) * 8);
      *puVar1 = *puVar1 | 1L << (bVar2 & 0x3f);
      uVar3 = (ushort)(uVar4 + 1);
    }
    nvAssertFailedNoLog("idx < bitVectorLast","src/libraries/nvbitvector/nvbitvector.c",0xab);
  }
  return 0x1f;
}


// ===== 00513fe0 bitVectorTestAllSet_IMPL =====

undefined8 bitVectorTestAllSet_IMPL(long param_1,ushort param_2)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBitVector","src/libraries/nvbitvector/nvbitvector.c",0x151);
    return 0;
  }
  uVar1 = 0;
  uVar3 = (int)(param_2 - 1) >> 6;
  if (uVar3 != 0xffffffff) {
    do {
      uVar2 = 0xffffffffffffffff;
      if (uVar3 <= (uint)uVar1) {
        uVar2 = 0xffffffffffffffff >> (-(char)param_2 & 0x3fU);
      }
      if ((*(ulong *)(param_1 + uVar1 * 8) & uVar2) != uVar2) {
        return 0;
      }
      uVar1 = uVar1 + 1;
    } while (uVar3 + 1 != uVar1);
  }
  return 1;
}


// ===== 00514070 __pfx_bitVectorTestAllCleared_IMPL =====

undefined8 __pfx_bitVectorTestAllCleared_IMPL(long param_1,ushort param_2)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBitVector","src/libraries/nvbitvector/nvbitvector.c",0x172);
    return 0;
  }
  uVar1 = 0;
  uVar3 = (int)(param_2 - 1) >> 6;
  if (uVar3 != 0xffffffff) {
    do {
      uVar2 = 0xffffffffffffffff;
      if (uVar3 <= (uint)uVar1) {
        uVar2 = 0xffffffffffffffff >> (-(char)param_2 & 0x3fU);
      }
      if ((*(ulong *)(param_1 + uVar1 * 8) & uVar2) != 0) {
        return 0;
      }
      uVar1 = uVar1 + 1;
    } while (uVar3 + 1 != uVar1);
  }
  return 1;
}


// ===== 00514080 bitVectorTestAllCleared_IMPL =====

undefined8 bitVectorTestAllCleared_IMPL(long param_1,ushort param_2)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBitVector","src/libraries/nvbitvector/nvbitvector.c",0x172);
    return 0;
  }
  uVar1 = 0;
  uVar3 = (int)(param_2 - 1) >> 6;
  if (uVar3 != 0xffffffff) {
    do {
      uVar2 = 0xffffffffffffffff;
      if (uVar3 <= (uint)uVar1) {
        uVar2 = 0xffffffffffffffff >> (-(char)param_2 & 0x3fU);
      }
      if ((*(ulong *)(param_1 + uVar1 * 8) & uVar2) != 0) {
        return 0;
      }
      uVar1 = uVar1 + 1;
    } while (uVar3 + 1 != uVar1);
  }
  return 1;
}


// ===== 00514110 __pfx_bitVectorTestEqual_IMPL =====

undefined8 __pfx_bitVectorTestEqual_IMPL(long param_1,ushort param_2,long param_3,ushort param_4)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBitVectorA","src/libraries/nvbitvector/nvbitvector.c",0x196);
  }
  else if (param_3 == 0) {
    nvAssertFailedNoLog("NULL != pBitVectorB","src/libraries/nvbitvector/nvbitvector.c",0x197);
  }
  else {
    if (param_2 == param_4) {
      uVar1 = 0;
      uVar3 = (int)(param_2 - 1) >> 6;
      if (uVar3 != 0xffffffff) {
        do {
          uVar2 = 0xffffffffffffffff;
          if (uVar3 <= (uint)uVar1) {
            uVar2 = 0xffffffffffffffff >> (-(char)param_2 & 0x3fU);
          }
          if (((*(ulong *)(param_1 + uVar1 * 8) ^ *(ulong *)(param_3 + uVar1 * 8)) & uVar2) != 0) {
            return 0;
          }
          uVar1 = uVar1 + 1;
        } while (uVar3 + 1 != uVar1);
      }
      return 1;
    }
    nvAssertFailedNoLog("(bitVectorALast == bitVectorBLast)",
                        "src/libraries/nvbitvector/nvbitvector.c",0x198);
  }
  return 0x1f;
}


// ===== 00514120 bitVectorTestEqual_IMPL =====

undefined8 bitVectorTestEqual_IMPL(long param_1,ushort param_2,long param_3,ushort param_4)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBitVectorA","src/libraries/nvbitvector/nvbitvector.c",0x196);
  }
  else if (param_3 == 0) {
    nvAssertFailedNoLog("NULL != pBitVectorB","src/libraries/nvbitvector/nvbitvector.c",0x197);
  }
  else {
    if (param_2 == param_4) {
      uVar1 = 0;
      uVar3 = (int)(param_2 - 1) >> 6;
      if (uVar3 != 0xffffffff) {
        do {
          uVar2 = 0xffffffffffffffff;
          if (uVar3 <= (uint)uVar1) {
            uVar2 = 0xffffffffffffffff >> (-(char)param_2 & 0x3fU);
          }
          if (((*(ulong *)(param_1 + uVar1 * 8) ^ *(ulong *)(param_3 + uVar1 * 8)) & uVar2) != 0) {
            return 0;
          }
          uVar1 = uVar1 + 1;
        } while (uVar3 + 1 != uVar1);
      }
      return 1;
    }
    nvAssertFailedNoLog("(bitVectorALast == bitVectorBLast)",
                        "src/libraries/nvbitvector/nvbitvector.c",0x198);
  }
  return 0x1f;
}


// ===== 00514210 bitVectorTest_IMPL =====

uint bitVectorTest_IMPL(long param_1,uint param_2,uint param_3)

{
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBitVector","src/libraries/nvbitvector/nvbitvector.c",0x1e1);
  }
  else {
    if (param_3 < param_2) {
      return (uint)(*(ulong *)(param_1 + (ulong)(param_3 >> 6) * 8) >> ((byte)param_3 & 0x3f)) & 1;
    }
    nvAssertFailedNoLog("idx < bitVectorLast","src/libraries/nvbitvector/nvbitvector.c",0x1e2);
  }
  return 0;
}


// ===== 00514280 bitVectorAnd_IMPL =====

undefined8
bitVectorAnd_IMPL(long param_1,ushort param_2,long param_3,ushort param_4,long param_5,
                 ushort param_6)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBitVectorDst","src/libraries/nvbitvector/nvbitvector.c",0x206);
  }
  else if (param_3 == 0) {
    nvAssertFailedNoLog("NULL != pBitVectorA","src/libraries/nvbitvector/nvbitvector.c",0x207);
  }
  else if (param_5 == 0) {
    nvAssertFailedNoLog("NULL != pBitVectorB","src/libraries/nvbitvector/nvbitvector.c",0x208);
  }
  else {
    if ((param_2 == param_4) && (param_4 == param_6)) {
      uVar1 = 0;
      uVar3 = (int)(param_2 - 1) >> 6;
      if (uVar3 != 0xffffffff) {
        do {
          uVar2 = 0xffffffffffffffff;
          if (uVar3 <= (uint)uVar1) {
            uVar2 = 0xffffffffffffffff >> (-(char)param_2 & 0x3fU);
          }
          *(ulong *)(param_1 + uVar1 * 8) =
               *(ulong *)(param_3 + uVar1 * 8) & *(ulong *)(param_5 + uVar1 * 8) & uVar2;
          uVar1 = uVar1 + 1;
        } while (uVar3 + 1 != uVar1);
      }
      return 0;
    }
    nvAssertFailedNoLog("((bitVectorDstLast == bitVectorALast) && (bitVectorALast == bitVectorBLast))"
                        ,"src/libraries/nvbitvector/nvbitvector.c",0x209);
  }
  return 0x1f;
}


// ===== 005143c0 bitVectorOr_IMPL =====

undefined8
bitVectorOr_IMPL(long param_1,ushort param_2,long param_3,ushort param_4,long param_5,ushort param_6
                )

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBitVectorDst","src/libraries/nvbitvector/nvbitvector.c",0x238);
  }
  else if (param_3 == 0) {
    nvAssertFailedNoLog("NULL != pBitVectorA","src/libraries/nvbitvector/nvbitvector.c",0x239);
  }
  else if (param_5 == 0) {
    nvAssertFailedNoLog("NULL != pBitVectorB","src/libraries/nvbitvector/nvbitvector.c",0x23a);
  }
  else {
    if ((param_2 == param_4) && (param_4 == param_6)) {
      uVar1 = 0;
      uVar3 = (int)(param_2 - 1) >> 6;
      if (uVar3 != 0xffffffff) {
        do {
          uVar2 = 0xffffffffffffffff;
          if (uVar3 <= (uint)uVar1) {
            uVar2 = 0xffffffffffffffff >> (-(char)param_2 & 0x3fU);
          }
          *(ulong *)(param_1 + uVar1 * 8) =
               (*(ulong *)(param_3 + uVar1 * 8) | *(ulong *)(param_5 + uVar1 * 8)) & uVar2;
          uVar1 = uVar1 + 1;
        } while (uVar3 + 1 != uVar1);
      }
      return 0;
    }
    nvAssertFailedNoLog("((bitVectorDstLast == bitVectorALast) && (bitVectorALast == bitVectorBLast))"
                        ,"src/libraries/nvbitvector/nvbitvector.c",0x23b);
  }
  return 0x1f;
}


// ===== 00514500 bitVectorComplement_IMPL =====

undefined8 bitVectorComplement_IMPL(long param_1,ushort param_2,long param_3,ushort param_4)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBitVectorDst","src/libraries/nvbitvector/nvbitvector.c",0x298);
  }
  else if (param_3 == 0) {
    nvAssertFailedNoLog("NULL != pBitVectorSrc","src/libraries/nvbitvector/nvbitvector.c",0x299);
  }
  else {
    if (param_2 == param_4) {
      uVar1 = 0;
      uVar3 = (int)(param_2 - 1) >> 6;
      if (uVar3 != 0xffffffff) {
        do {
          uVar2 = 0xffffffffffffffff;
          if (uVar3 <= (uint)uVar1) {
            uVar2 = 0xffffffffffffffff >> (-(char)param_2 & 0x3fU);
          }
          *(ulong *)(param_1 + uVar1 * 8) = ~*(ulong *)(param_3 + uVar1 * 8) & uVar2;
          uVar1 = uVar1 + 1;
        } while (uVar3 + 1 != uVar1);
      }
      return 0;
    }
    nvAssertFailedNoLog("((bitVectorDstLast == bitVectorSrcLast))",
                        "src/libraries/nvbitvector/nvbitvector.c",0x29a);
  }
  return 0x1f;
}


// ===== 005145f0 bitVectorCopy_IMPL =====

undefined8 bitVectorCopy_IMPL(long param_1,short param_2,long param_3,short param_4)

{
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBitVectorDst","src/libraries/nvbitvector/nvbitvector.c",0x2bf);
  }
  else if (param_3 == 0) {
    nvAssertFailedNoLog("NULL != pBitVectorSrc","src/libraries/nvbitvector/nvbitvector.c",0x2c0);
  }
  else {
    if (param_2 == param_4) {
      if (param_1 != param_3) {
        portMemCopy();
        return 0;
      }
      nvAssertFailedNoLog("pBitVectorDst != pBitVectorSrc","src/libraries/nvbitvector/nvbitvector.c"
                          ,0x2c2);
      return 0x10006;
    }
    nvAssertFailedNoLog("bitVectorDstLast == bitVectorSrcLast",
                        "src/libraries/nvbitvector/nvbitvector.c",0x2c1);
  }
  return 0x1f;
}


// ===== 005146c0 bitVectorCountTrailingZeros_IMPL =====

uint bitVectorCountTrailingZeros_IMPL(long param_1,ushort param_2)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBitVector","src/libraries/nvbitvector/nvbitvector.c",0x2db);
    return 0;
  }
  uVar4 = (int)(param_2 - 1) >> 6;
  if (uVar4 != 0xffffffff) {
    uVar3 = 0;
    while( true ) {
      uVar2 = 0xffffffffffffffff;
      if (uVar4 <= (uint)uVar3) {
        uVar2 = 0xffffffffffffffff >> (-(char)param_2 & 0x3fU);
      }
      uVar2 = uVar2 & *(ulong *)(param_1 + uVar3 * 8);
      if (uVar2 != 0) break;
      uVar3 = uVar3 + 1;
      if (uVar3 == uVar4 + 1) {
        return (uint)param_2;
      }
    }
    iVar1 = 0;
    for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1 | 0x8000000000000000) {
      iVar1 = iVar1 + 1;
    }
    return (uint)uVar3 * 0x40 + iVar1;
  }
  return (uint)param_2;
}


// ===== 00514760 bitVectorCountSetBits_IMPL =====

int bitVectorCountSetBits_IMPL(long param_1,ushort param_2)

{
  ulong uVar1;
  ulong uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBitVector","src/libraries/nvbitvector/nvbitvector.c",0x329);
  }
  else {
    uVar4 = (int)(param_2 - 1) >> 6;
    if (uVar4 != 0xffffffff) {
      uVar2 = 0;
      iVar3 = 0;
      do {
        uVar1 = 0xffffffffffffffff;
        if (uVar4 <= (uint)uVar2) {
          uVar1 = 0xffffffffffffffff >> (-(char)param_2 & 0x3fU);
        }
        uVar1 = uVar1 & *(ulong *)(param_1 + uVar2 * 8);
        uVar2 = uVar2 + 1;
        uVar1 = uVar1 - (uVar1 >> 1 & 0x5555555555555555);
        uVar1 = (uVar1 >> 2 & 0x3333333333333333) + (uVar1 & 0x3333333333333333);
        iVar3 = iVar3 + (uint)(byte)((uVar1 + (uVar1 >> 4) & 0xf0f0f0f0f0f0f0f) * 0x101010101010101
                                    >> 0x38);
      } while (uVar2 != uVar4 + 1);
      return iVar3;
    }
  }
  return 0;
}


// ===== 00514860 bitVectorToRaw_IMPL =====

undefined8 bitVectorToRaw_IMPL(long param_1,ushort param_2,long param_3,ulong param_4)

{
  ulong uVar1;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBitVector","src/libraries/nvbitvector/nvbitvector.c",0x345);
  }
  else {
    if (param_3 != 0) {
      uVar1 = (ulong)(((int)(param_2 - 1) >> 6) + 1) << 3;
      if (uVar1 <= (param_4 & 0xffffffff)) {
        portMemCopy(param_3,uVar1,param_1,uVar1);
        return 0;
      }
      nvAssertFailedNoLog("rawMaskSize >= byteSize","src/libraries/nvbitvector/nvbitvector.c",0x347)
      ;
      return 2;
    }
    nvAssertFailedNoLog("NULL != pRawMask","src/libraries/nvbitvector/nvbitvector.c",0x346);
  }
  return 0x1f;
}


// ===== 00514900 bitVectorFromRaw_IMPL =====

undefined8 bitVectorFromRaw_IMPL(long param_1,ushort param_2,long param_3,ulong param_4)

{
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBitVector","src/libraries/nvbitvector/nvbitvector.c",0x35b);
  }
  else {
    if (param_3 != 0) {
      if ((ulong)(((int)(param_2 - 1) >> 6) + 1) << 3 <= (param_4 & 0xffffffff)) {
        portMemCopy();
        return 0;
      }
      nvAssertFailedNoLog("rawMaskSize >= byteSize","src/libraries/nvbitvector/nvbitvector.c",0x35d)
      ;
      return 2;
    }
    nvAssertFailedNoLog("NULL != pRawMask","src/libraries/nvbitvector/nvbitvector.c",0x35c);
  }
  return 0x1f;
}


// ===== 005149a0 bitVectorGetSlice_IMPL =====

undefined8
bitVectorGetSlice_IMPL(long param_1,ushort param_2,ulong param_3,ulong param_4,ulong *param_5)

{
  byte bVar1;
  ulong uVar2;
  byte bVar3;
  ulong uVar4;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pBitVector != NULL","src/libraries/nvbitvector/nvbitvector.c",0x378);
    return 0x1f;
  }
  if (param_3 <= param_4) {
    if (0x40 < (param_4 + 1) - param_3) {
      nvAssertFailedNoLog("rangeLength(range) <= 8 * sizeof(NvU64)",
                          "src/libraries/nvbitvector/nvbitvector.c",0x379);
      return 0x1f;
    }
    if (param_4 == 0xffffffffffffffff) {
      nvAssertFailedNoLog("range.hi != NV_U64_MAX","src/libraries/nvbitvector/nvbitvector.c",0x37a);
      return 0x1f;
    }
  }
  if ((ulong)(long)(int)(param_2 - 1) < param_4) {
    nvAssertFailedNoLog("rangeContains(rangeMake(0, bitVectorLast - 1), range)",
                        "src/libraries/nvbitvector/nvbitvector.c",0x37b);
    return 0x1f;
  }
  uVar4 = param_3 >> 6;
  uVar2 = param_4 >> 6;
  bVar3 = (byte)param_3 & 0x3f;
  bVar1 = (byte)param_4 & 0x3f;
  if (uVar4 == uVar2) {
    *param_5 = ((0xffffffffffffffffU >> ((bVar1 ^ 0x3f) + bVar3 & 0x3f)) << bVar3 &
               *(ulong *)(param_1 + uVar4 * 8)) >> bVar3;
  }
  else {
    if (uVar4 != uVar2 - 1) {
      nvAssertFailedNoLog("NV_BITVECTOR_IDX(range.lo) == NV_BITVECTOR_IDX(range.hi) - 1",
                          "src/libraries/nvbitvector/nvbitvector.c",0x38b);
      return 0x1f;
    }
    uVar4 = ((0xffffffffffffffffU >> bVar3) << bVar3 & *(ulong *)(param_1 + uVar4 * 8)) >> bVar3;
    *param_5 = uVar4;
    *param_5 = (0xffffffffffffffffU >> (bVar1 ^ 0x3f) & *(ulong *)(param_1 + uVar2 * 8)) <<
               (-bVar3 & 0x3f) | uVar4;
  }
  return 0;
}


// ===== 00514b20 fullyDeriveWrapper =====

long fullyDeriveWrapper(long *param_1)

{
  return (long)param_1 - (ulong)*(uint *)(*param_1 + 0x10);
}


// ===== 00514b40 __nvoc_objGetClassId =====

uint __nvoc_objGetClassId(long *param_1)

{
  return *(uint *)(**(long **)((long)param_1 - (ulong)*(uint *)(*param_1 + 0x10)) + 4) & 0xffffff;
}


// ===== 00514b60 __nvoc_objGetClassInfo =====

undefined8 __nvoc_objGetClassInfo(long *param_1)

{
  return **(undefined8 **)((long)param_1 - (ulong)*(uint *)(*param_1 + 0x10));
}


// ===== 00514b80 objAddChild_IMPL =====

void objAddChild_IMPL(long param_1,long param_2)

{
  if (*(long *)(param_2 + 0x10) == 0) {
    *(long *)(param_2 + 0x10) = param_1;
    *(undefined8 *)(param_2 + 0x20) = *(undefined8 *)(param_1 + 0x18);
    *(long *)(param_1 + 0x18) = param_2;
    return;
  }
  nvAssertFailedNoLog("pChild->pParent == NULL","src/libraries/nvoc/src/runtime.c",0x4c);
  *(long *)(param_2 + 0x10) = param_1;
  *(undefined8 *)(param_2 + 0x20) = *(undefined8 *)(param_1 + 0x18);
  *(long *)(param_1 + 0x18) = param_2;
  return;
}


// ===== 00514c00 objRemoveChild_IMPL =====

void objRemoveChild_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 *puVar2;
  
  if (*(long *)(param_2 + 0x10) != param_1) {
    nvAssertFailedNoLog("pObj == pChild->pParent","src/libraries/nvoc/src/runtime.c",0x72);
  }
  *(undefined8 *)(param_2 + 0x10) = 0;
  lVar1 = *(long *)(param_1 + 0x18);
  if (lVar1 != 0) {
    puVar2 = (undefined8 *)(param_1 + 0x18);
    do {
      if (lVar1 == param_2) {
        *puVar2 = *(undefined8 *)(lVar1 + 0x20);
        return;
      }
      puVar2 = (undefined8 *)(lVar1 + 0x20);
      lVar1 = *(long *)(lVar1 + 0x20);
    } while (lVar1 != 0);
  }
  return;
}


// ===== 00514c90 objGetChild_IMPL =====

undefined8 objGetChild_IMPL(long param_1)

{
  if (param_1 != 0) {
    return *(undefined8 *)(param_1 + 0x18);
  }
  nvAssertFailedNoLog("pObj != NULL","src/libraries/nvoc/src/runtime.c",0x83);
  return uRam0000000000000018;
}


// ===== 00514cd0 objGetSibling_IMPL =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 objGetSibling_IMPL(long param_1)

{
  if (param_1 != 0) {
    return *(undefined8 *)(param_1 + 0x20);
  }
  nvAssertFailedNoLog("pObj != NULL","src/libraries/nvoc/src/runtime.c",0x89);
  return _DAT_00000020;
}


// ===== 00514d10 __nvoc_objCreateDynamic =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

undefined8
__nvoc_objCreateDynamic
          (undefined8 param_1,undefined8 param_2,long param_3,undefined4 param_4,undefined8 param_5,
          undefined8 param_6)

{
  undefined8 uVar1;
  undefined4 local_50 [2];
  undefined1 *local_48;
  undefined1 *local_40;
  undefined1 local_38 [32];
  undefined8 local_18;
  undefined8 local_10;
  
  if (param_3 == 0) {
    return 0x1f;
  }
  if (*(long *)(param_3 + 0x18) != 0) {
    local_48 = &stack0x00000008;
    local_50[0] = 0x20;
    local_40 = local_38;
    local_18 = param_5;
    local_10 = param_6;
    uVar1 = (**(code **)(param_3 + 0x18))
                      (param_1,param_2,param_4,local_50,*(code **)(param_3 + 0x18));
    return uVar1;
  }
  return 0x22;
}


// ===== 00514d80 objDynamicCastById_IMPL =====

long * objDynamicCastById_IMPL(long *param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  
  if ((param_1 != (long *)0x0) && ((*(uint *)(*(long *)*param_1 + 4) & 0xffffff) != param_2)) {
    param_1 = (long *)((long)param_1 - (ulong)*(uint *)((long *)*param_1 + 2));
    if ((*(uint *)(*(long *)*param_1 + 4) & 0xffffff) == param_2) {
      return param_1;
    }
    puVar2 = *(uint **)(*(long *)*param_1 + 0x20);
    puVar1 = puVar2 + (ulong)*puVar2 * 2;
    if (*puVar2 != 0) {
      do {
        if (param_2 == (*(uint *)(**(long **)(puVar2 + 2) + 4) & 0xffffff)) {
          return (long *)((long)param_1 + (ulong)*(uint *)(*(long **)(puVar2 + 2) + 2));
        }
        puVar2 = puVar2 + 2;
      } while (puVar1 != puVar2);
    }
    return (long *)0x0;
  }
  return param_1;
}


// ===== 00514e30 objFindAncestor_IMPL =====

long objFindAncestor_IMPL(undefined8 param_1,undefined4 param_2)

{
  long *plVar1;
  long lVar2;
  
  plVar1 = (long *)objDynamicCastById_IMPL(param_1,__nvoc_class_def_Object._4_4_ & 0xffffff);
  if (plVar1 == (long *)0x0) {
    nvAssertFailedNoLog("pObj != NULL","src/libraries/nvoc/src/runtime.c",0x3f);
  }
  do {
    plVar1 = (long *)plVar1[2];
    if (plVar1 == (long *)0x0) {
      nvAssertFailedNoLog(&DAT_00dac096,"src/libraries/nvoc/src/runtime.c",0x46);
      return 0;
    }
    lVar2 = objDynamicCastById_IMPL(plVar1,param_2);
  } while (lVar2 == 0);
  return (long)plVar1 - (ulong)*(uint *)(*plVar1 + 0x10);
}


// ===== 00514ee0 __nvoc_objDelete =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_objDelete(long *param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    return;
  }
  (**(code **)(*(long *)((long)param_1 - (ulong)*(uint *)(*param_1 + 0x10)) + 8))();
  plVar2 = (long *)objDynamicCastById_IMPL(param_1,__nvoc_class_def_Object._4_4_ & 0xffffff);
  lVar1 = plVar2[2];
  if (lVar1 != 0) {
    plVar2[2] = 0;
    plVar3 = *(long **)(lVar1 + 0x18);
    if (plVar3 != (long *)0x0) {
      plVar4 = (long *)(lVar1 + 0x18);
      do {
        if (plVar3 == plVar2) {
          *plVar4 = plVar2[4];
          break;
        }
        plVar4 = plVar3 + 4;
        plVar3 = (long *)plVar3[4];
      } while (plVar3 != (long *)0x0);
    }
  }
  plVar3 = (long *)plVar2[3];
  if (plVar3 != (long *)0x0) {
    nv_printf(0xffffffff,"NVOC: %s: Child class %s not freed from parent class %s.",
              "__nvoc_objDelete",
              *(undefined8 *)(**(long **)((long)plVar3 - (ulong)*(uint *)(*plVar3 + 0x10)) + 0x10),
              *(undefined8 *)(**(long **)((long)plVar2 - (ulong)*(uint *)(*plVar2 + 0x10)) + 0x10));
  }
  if ((*(byte *)((long)plVar2 + 0x2c) & 2) != 0) {
    return;
  }
  portMemFree((long)param_1 - (ulong)*(uint *)(*param_1 + 0x10));
  return;
}


// ===== 00515000 __nvoc_dynamicCast =====

void __nvoc_dynamicCast(undefined8 param_1,long param_2)

{
  objDynamicCastById_IMPL(param_1,*(uint *)(param_2 + 4) & 0xffffff);
  return;
}


// ===== 00515020 __nvoc_destructFromBase =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_destructFromBase(long *param_1)

{
  (**(code **)(*(long *)((long)param_1 - (ulong)*(uint *)(*param_1 + 0x10)) + 8))();
  return;
}


// ===== 00515040 nvocGetExportedMethodDefFromMethodInfo_IMPL =====

long nvocGetExportedMethodDefFromMethodInfo_IMPL(uint *param_1,uint param_2)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_1 != (uint *)0x0) {
    if ((*(long *)(param_1 + 2) != 0) && (*param_1 != 0)) {
      uVar3 = *param_1;
      uVar6 = 0;
      while( true ) {
        uVar4 = uVar3;
        uVar5 = uVar6 + uVar4 >> 1;
        lVar1 = *(long *)(param_1 + 2) + (ulong)uVar5 * 0x28;
        uVar2 = *(uint *)(lVar1 + 0x10);
        if (uVar2 == param_2) {
          return lVar1;
        }
        if ((uVar4 == uVar5) || (uVar6 == uVar5)) break;
        uVar3 = uVar5;
        if (uVar2 <= param_2) {
          uVar3 = uVar4;
          uVar6 = uVar5;
        }
      }
    }
  }
  return 0;
}


// ===== 005150a0 objGetExportedMethodDef_IMPL =====

long objGetExportedMethodDef_IMPL(undefined8 *param_1,uint param_2)

{
  uint *puVar1;
  long lVar2;
  uint *puVar3;
  ulong uVar4;
  
  puVar3 = *(uint **)(*(long *)*param_1 + 0x20);
  if (*puVar3 == 0) {
    return 0;
  }
  uVar4 = (ulong)param_2;
  puVar1 = puVar3 + (ulong)*puVar3 * 2;
  do {
    lVar2 = nvocGetExportedMethodDefFromMethodInfo_IMPL
                      (*(undefined8 *)(**(long **)(puVar3 + 2) + 0x28),uVar4 & 0xffffffff);
    if (lVar2 != 0) {
      return lVar2;
    }
    puVar3 = puVar3 + 2;
  } while (puVar3 != puVar1);
  return 0;
}


// ===== 00515100 portInitialize =====

undefined8 portInitialize(void)

{
  int iVar1;
  
  iVar1 = portState;
  LOCK();
  portState = portState + 1;
  UNLOCK();
  if (iVar1 != 0) {
    return 0;
  }
  portSyncInitialize();
  portMemInitialize();
  portCryptoInitialize();
  portCpuInitialize();
  return 0;
}


// ===== 00515140 portShutdown =====

void portShutdown(void)

{
  LOCK();
  portState = portState + -1;
  UNLOCK();
  if (portState != 0) {
    return;
  }
  portCpuShutdown();
  portCryptoShutdown();
  portMemShutdown(1);
  portSyncShutdown();
  return;
}


// ===== 00515170 portIsInitialized =====

undefined4 portIsInitialized(void)

{
  return CONCAT31((int3)((uint)portState >> 8),portState != 0);
}


// ===== 00515180 portCpuInitialize =====

void portCpuInitialize(void)

{
  gCpuPortState[0x18] = 0;
  return;
}


// ===== 00515190 portCpuShutdown =====

void portCpuShutdown(void)

{
  gCpuPortState[0x18] = 0;
  return;
}


// ===== 005151a0 portCryptoShutdown =====

void portCryptoShutdown(void)

{
  portMemFree(portCryptoDefaultGenerator);
  portCryptoDefaultGenerator = 0;
  return;
}


// ===== 005151d0 portCryptoPseudoRandomGeneratorCreate =====

void portCryptoPseudoRandomGeneratorCreate(long param_1)

{
  ulong *puVar1;
  ulong uVar2;
  
  puVar1 = (ulong *)portMemAllocNonPaged(0x10);
  if (puVar1 != (ulong *)0x0) {
    uVar2 = (param_1 + 0x9e3779b97f4a7c15U >> 0x1e ^ param_1 + 0x9e3779b97f4a7c15U) *
            -0x40a7b892e31b1a47;
    uVar2 = (uVar2 >> 0x1b ^ uVar2) * -0x6b2fb644ecceee15;
    *puVar1 = uVar2 ^ uVar2 >> 0x1f;
    uVar2 = (param_1 + 0x3c6ef372fe94f82aU >> 0x1e ^ param_1 + 0x3c6ef372fe94f82aU) *
            -0x40a7b892e31b1a47;
    uVar2 = (uVar2 >> 0x1b ^ uVar2) * -0x6b2fb644ecceee15;
    puVar1[1] = uVar2 ^ uVar2 >> 0x1f;
  }
  return;
}


// ===== 00515280 portCryptoInitialize =====

void portCryptoInitialize(void)

{
  undefined8 uVar1;
  
  uVar1 = osGetTimestamp();
  if (portCryptoDefaultGenerator != 0) {
    portMemFree();
  }
  portCryptoDefaultGenerator = portCryptoPseudoRandomGeneratorCreate(uVar1);
  return;
}


// ===== 005152c0 portCryptoPseudoRandomGeneratorDestroy =====

void portCryptoPseudoRandomGeneratorDestroy(void)

{
  portMemFree();
  return;
}


// ===== 005152d0 portCryptoPseudoRandomGeneratorGetU32 =====

int portCryptoPseudoRandomGeneratorGetU32(ulong *param_1)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar2 = *param_1;
  uVar1 = param_1[1];
  *param_1 = uVar1;
  uVar2 = uVar2 ^ uVar2 << 0x17;
  uVar2 = uVar1 >> 5 ^ uVar1 ^ uVar2 ^ uVar2 >> 0x12;
  param_1[1] = uVar2;
  return (int)uVar2 + (int)uVar1;
}


// ===== 00515310 _portMemAllocatorAllocNonPagedWrapper =====

void _portMemAllocatorAllocNonPagedWrapper(undefined8 param_1,undefined8 param_2)

{
  _portMemAllocNonPagedUntracked(param_2);
  return;
}


// ===== 00515320 _portMemAllocatorFreeWrapper =====

void _portMemAllocatorFreeWrapper(undefined8 param_1,undefined8 param_2)

{
  _portMemFreeUntracked(param_2);
  return;
}


// ===== 00515330 _portMemAllocatorAllocPagedWrapper =====

void _portMemAllocatorAllocPagedWrapper(undefined8 param_1,undefined8 param_2)

{
  _portMemAllocPagedUntracked(param_2);
  return;
}


// ===== 00515340 _portMemAllocatorFreeExistingWrapper =====

void _portMemAllocatorFreeExistingWrapper(long param_1,ulong param_2)

{
  uint *puVar1;
  long *plVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  
  plVar2 = *(long **)(param_1 + 0x20);
  uVar6 = plVar2[1];
  if (param_2 < uVar6) {
    return;
  }
  if ((ulong)*(uint *)(plVar2 + 2) * 0x10 + uVar6 < param_2) {
    return;
  }
  lVar3 = *plVar2;
  if (lVar3 == 0) {
    uVar6 = (long)(param_2 - uVar6) >> 4;
    if (*(uint *)(plVar2 + 2) <= (uint)uVar6) {
      return;
    }
  }
  else {
    portSyncSpinlockAcquire(lVar3);
    uVar6 = (long)(param_2 - plVar2[1]) >> 4;
    if (*(uint *)(plVar2 + 2) <= (uint)uVar6) goto LAB_0051540b;
  }
  uVar6 = uVar6 & 0xffffffff;
  do {
    puVar1 = (uint *)((long)plVar2 + (uVar6 >> 5) * 4 + 0x14);
    *puVar1 = *puVar1 & ~(1 << ((byte)uVar6 & 0x1f));
    uVar4 = *(uint *)(plVar2 + 2) + (int)uVar6;
    uVar5 = 1 << ((byte)uVar4 & 0x1f);
    puVar1 = (uint *)((long)plVar2 + (ulong)(uVar4 >> 5) * 4 + 0x14);
    uVar4 = *puVar1;
    if ((uVar4 & uVar5) != 0) {
      *puVar1 = ~uVar5 & uVar4;
      break;
    }
    uVar4 = (int)uVar6 + 1;
    uVar6 = (ulong)uVar4;
  } while (uVar4 < *(uint *)(plVar2 + 2));
  if (lVar3 == 0) {
    return;
  }
LAB_0051540b:
  portSyncSpinlockRelease(lVar3);
  return;
}


// ===== 00515440 _portMemAllocatorAllocExistingWrapper =====

long _portMemAllocatorAllocExistingWrapper(long param_1,long param_2)

{
  uint *puVar1;
  long *plVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  long lVar10;
  
  plVar2 = *(long **)(param_1 + 0x20);
  uVar9 = *(uint *)(plVar2 + 2);
  uVar7 = (uint)(param_2 + 0xfU >> 4);
  if (uVar9 < uVar7) {
    return 0;
  }
  lVar3 = *plVar2;
  if (lVar3 == 0) {
    if (uVar9 == 0) {
      return 0;
    }
  }
  else {
    portSyncSpinlockAcquire();
    uVar9 = *(uint *)(plVar2 + 2);
    if (uVar9 == 0) {
      lVar10 = 0;
      goto LAB_00515505;
    }
  }
  uVar5 = 0;
  uVar8 = 0;
LAB_005154d6:
  do {
    uVar4 = (uint)uVar5;
    if (*(int *)((long)plVar2 + (uVar5 >> 5) * 4 + 0x14) != -1) {
      if ((*(uint *)((long)plVar2 + (uVar5 >> 5) * 4 + 0x14) & 1 << ((byte)uVar5 & 0x1f)) != 0) {
        uVar8 = uVar9 - uVar4;
        goto LAB_005154eb;
      }
      if (uVar7 != uVar8 + 1) goto code_r0x005154cd;
      uVar7 = uVar4 - uVar8;
      lVar10 = (ulong)uVar7 * 0x10 + plVar2[1];
      if (uVar8 <= uVar4) {
        do {
          bVar6 = (byte)uVar7;
          uVar9 = uVar7 >> 5;
          uVar7 = uVar7 + 1;
          puVar1 = (uint *)((long)plVar2 + (ulong)uVar9 * 4 + 0x14);
          *puVar1 = *puVar1 | 1 << (bVar6 & 0x1f);
        } while (uVar4 + 1 != uVar7);
        uVar9 = *(uint *)(plVar2 + 2);
      }
      puVar1 = (uint *)((long)plVar2 + (ulong)(uVar4 + uVar9 >> 5) * 4 + 0x14);
      *puVar1 = *puVar1 | 1 << ((byte)(uVar4 + uVar9) & 0x1f);
      goto LAB_005154fc;
    }
    uVar4 = uVar4 + 0x1f;
    uVar8 = (uVar9 - 1) - uVar4;
LAB_005154eb:
    if (uVar8 < uVar7) break;
    uVar5 = (ulong)(uVar4 + 1);
    uVar8 = 0;
  } while (uVar4 + 1 < uVar9);
  goto LAB_005154f9;
code_r0x005154cd:
  uVar5 = (ulong)(uVar4 + 1);
  uVar8 = uVar8 + 1;
  if (uVar9 <= uVar4 + 1) goto LAB_005154f9;
  goto LAB_005154d6;
LAB_005154f9:
  lVar10 = 0;
LAB_005154fc:
  if (lVar3 == 0) {
    return lVar10;
  }
LAB_00515505:
  portSyncSpinlockRelease(lVar3);
  return lVar10;
}


// ===== 005155e0 _portMemAllocatorCreateOnExistingBlock.part.0 =====

undefined8 *
_portMemAllocatorCreateOnExistingBlock_part_0(undefined8 *param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  uint uVar5;
  ulong uVar6;
  uint uVar7;
  
  uVar3 = (long)param_1 + 0x4fU & 0xfffffffffffffff0;
  param_1[4] = param_1 + 5;
  uVar6 = uVar3 - ((long)param_1 + 0x3c);
  uVar2 = (long)param_1 + param_2 + -0x10 & 0xfffffffffffffff0;
  param_1[5] = param_3;
  *param_1 = _portMemAllocatorAllocExistingWrapper;
  uVar4 = uVar6 & 0xffffffff;
  param_1[1] = _portMemAllocatorFreeExistingWrapper;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[6] = uVar3;
  if (uVar2 < uVar3) {
    *(undefined4 *)(param_1 + 7) = 0;
  }
  else {
    iVar1 = (int)((long)(uVar2 - uVar3) >> 4) + 1;
    *(int *)(param_1 + 7) = iVar1;
    if ((uint)((int)uVar6 << 3) < (uint)(iVar1 * 2)) {
      uVar5 = ((int)uVar3 - (int)param_1) - 0x2c;
      do {
        uVar4 = (ulong)uVar5;
        iVar1 = iVar1 + -1;
        uVar3 = uVar3 + 0x10;
        uVar7 = uVar5 * 8;
        uVar5 = uVar5 + 0x10;
      } while (uVar7 < (uint)(iVar1 * 2));
      param_1[6] = uVar3;
      *(int *)(param_1 + 7) = iVar1;
    }
  }
  portMemSet((long)param_1 + 0x3c,0,uVar4);
  return param_1;
}


// ===== 005156b0 _portMemAllocatorReleaseWrapper =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _portMemAllocatorReleaseWrapper(long param_1)

{
  if (param_1 != 0) {
    if (portMemGlobals._112_8_ != 0) {
      LOCK();
      *(int *)(portMemGlobals._112_8_ + 0x18) = *(int *)(portMemGlobals._112_8_ + 0x18) + -1;
      UNLOCK();
      LOCK();
      portMemGlobals._24_4_ = portMemGlobals._24_4_ + -1;
      UNLOCK();
    }
    (*(code *)portMemGlobals._96_8_)(0x56ec78,param_1);
    return;
  }
  return;
}


// ===== 00515700 portMemShutdown =====

void portMemShutdown(void)

{
  undefined8 uVar1;
  
  LOCK();
  portMemGlobals._328_4_ = portMemGlobals._328_4_ + -1;
  UNLOCK();
  if (portMemGlobals._328_4_ != 0) {
    return;
  }
  portSyncSpinlockAcquire(portMemGlobals._80_8_);
  uVar1 = portMemGlobals._176_8_;
  *(undefined8 *)(portMemGlobals._184_8_ + 8) = portMemGlobals._176_8_;
  *(undefined8 *)(uVar1 + 0x10) = portMemGlobals._184_8_;
  portSyncSpinlockRelease(portMemGlobals._80_8_);
  LOCK();
  portMemGlobals._332_4_ = portMemGlobals._332_4_ + -1;
  UNLOCK();
  portSyncSpinlockDestroy(portMemGlobals._80_8_);
  _portMemFreeUntracked(portMemGlobals._80_8_);
  portMemSet(portMemGlobals,0,0x150);
  return;
}


// ===== 00515780 portMemAllocPaged =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Removing unreachable block (ram,0x0051582e) */

long portMemAllocPaged(long param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  int iVar6;
  
  if (param_1 == 0) {
    return 0;
  }
  lVar5 = (*(code *)portMemGlobals._88_8_)(0x56ec78,param_1);
  uVar4 = portMemGlobals._112_8_;
  if ((lVar5 != 0) && (portMemGlobals._112_8_ != 0)) {
    LOCK();
    piVar1 = (int *)(portMemGlobals._112_8_ + 0x18);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    LOCK();
    *(int *)(uVar4 + 0x1c) = *(int *)(uVar4 + 0x1c) + 1;
    UNLOCK();
    LOCK();
    *(long *)(uVar4 + 0x30) = *(long *)(uVar4 + 0x30) + param_1;
    UNLOCK();
    piVar1 = (int *)(uVar4 + 0x20);
    do {
      iVar6 = *piVar1;
      if (*(long *)(uVar4 + 0x38) != 0) break;
      LOCK();
      iVar3 = *piVar1;
      if (iVar6 == iVar3) {
        *piVar1 = iVar2 + 1;
      }
      UNLOCK();
    } while (iVar6 != iVar3);
    LOCK();
    iVar2 = portMemGlobals._24_4_ + 1;
    UNLOCK();
    iVar6 = portMemGlobals._24_4_ + 1;
    LOCK();
    portMemGlobals._28_4_ = portMemGlobals._28_4_ + 1;
    UNLOCK();
    LOCK();
    portMemGlobals._48_8_ = portMemGlobals._48_8_ + param_1;
    UNLOCK();
    portMemGlobals._24_4_ = iVar2;
    if (portMemGlobals._56_8_ == 0) {
      LOCK();
      UNLOCK();
      portMemGlobals._32_4_ = iVar6;
    }
  }
  return lVar5;
}


// ===== 00515850 portMemAllocNonPaged =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Removing unreachable block (ram,0x005158fe) */

long portMemAllocNonPaged(long param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  int iVar6;
  
  if (param_1 == 0) {
    return 0;
  }
  lVar5 = (*(code *)portMemGlobals._128_8_)(0x56eca0,param_1);
  uVar4 = portMemGlobals._152_8_;
  if ((lVar5 != 0) && (portMemGlobals._152_8_ != 0)) {
    LOCK();
    piVar1 = (int *)(portMemGlobals._152_8_ + 0x18);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    LOCK();
    *(int *)(uVar4 + 0x1c) = *(int *)(uVar4 + 0x1c) + 1;
    UNLOCK();
    LOCK();
    *(long *)(uVar4 + 0x30) = *(long *)(uVar4 + 0x30) + param_1;
    UNLOCK();
    piVar1 = (int *)(uVar4 + 0x20);
    do {
      iVar6 = *piVar1;
      if (*(long *)(uVar4 + 0x38) != 0) break;
      LOCK();
      iVar3 = *piVar1;
      if (iVar6 == iVar3) {
        *piVar1 = iVar2 + 1;
      }
      UNLOCK();
    } while (iVar6 != iVar3);
    LOCK();
    iVar2 = portMemGlobals._24_4_ + 1;
    UNLOCK();
    iVar6 = portMemGlobals._24_4_ + 1;
    LOCK();
    portMemGlobals._28_4_ = portMemGlobals._28_4_ + 1;
    UNLOCK();
    LOCK();
    portMemGlobals._48_8_ = portMemGlobals._48_8_ + param_1;
    UNLOCK();
    portMemGlobals._24_4_ = iVar2;
    if (portMemGlobals._56_8_ == 0) {
      LOCK();
      UNLOCK();
      portMemGlobals._32_4_ = iVar6;
    }
  }
  return lVar5;
}


// ===== 00515920 portMemFree =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void portMemFree(long param_1)

{
  if (param_1 != 0) {
    if (portMemGlobals._112_8_ != 0) {
      LOCK();
      *(int *)(portMemGlobals._112_8_ + 0x18) = *(int *)(portMemGlobals._112_8_ + 0x18) + -1;
      UNLOCK();
      LOCK();
      portMemGlobals._24_4_ = portMemGlobals._24_4_ + -1;
      UNLOCK();
    }
    (*(code *)portMemGlobals._96_8_)(0x56ec78,param_1);
    return;
  }
  return;
}


// ===== 00515970 portMemAllocatorCreateOnExistingBlock =====

undefined8 portMemAllocatorCreateOnExistingBlock(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_2 - 0x40U < 0x7fffffc0) && (param_1 != 0)) {
    uVar1 = _portMemAllocatorCreateOnExistingBlock_part_0(param_1,param_2,0);
    return uVar1;
  }
  return 0;
}


// ===== 005159a0 portMemAllocatorRelease =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

void portMemAllocatorRelease(long param_1)

{
  long lVar1;
  long lVar2;
  
  if (param_1 != 0) {
    lVar1 = *(long *)(param_1 + 0x18);
    if (lVar1 != 0) {
      portSyncSpinlockAcquire(portMemGlobals._80_8_);
      lVar2 = *(long *)(lVar1 + 8);
      *(long *)(*(long *)(lVar1 + 0x10) + 8) = lVar2;
      *(undefined8 *)(lVar2 + 0x10) = *(undefined8 *)(lVar1 + 0x10);
      portSyncSpinlockRelease(portMemGlobals._80_8_);
      LOCK();
      portMemGlobals._332_4_ = portMemGlobals._332_4_ + -1;
      UNLOCK();
      if (*(code **)(param_1 + 0x10) != (code *)0x0) {
        (**(code **)(param_1 + 0x10))(param_1);
        return;
      }
      return;
    }
    if (*(code **)(param_1 + 0x10) != (code *)0x0) {
      (**(code **)(param_1 + 0x10))();
      return;
    }
  }
  return;
}


// ===== 00515a40 portMemAllocatorGetGlobalNonPaged =====

undefined8 portMemAllocatorGetGlobalNonPaged(void)

{
  return 0x56eca0;
}


// ===== 00515a50 portMemInitializeAllocatorTracking =====

void portMemInitializeAllocatorTracking(long param_1,long *param_2)

{
  if (portMemGlobals._328_4_ == 0) {
    portMemSet(param_2,0,0x50);
    if (param_1 != 0) {
      *(undefined8 *)(param_1 + 0x18) = 0;
      return;
    }
  }
  else {
    *param_2 = param_1;
    if (param_1 != 0) {
      *(long **)(param_1 + 0x18) = param_2;
    }
    portSyncSpinlockAcquire(portMemGlobals._80_8_);
    param_2[2] = (long)portMemGlobals;
    param_2[1] = portMemGlobals._8_8_;
    portMemGlobals._8_8_ = param_2;
    *(long **)(param_2[1] + 0x10) = param_2;
    portSyncSpinlockRelease(portMemGlobals._80_8_);
    portMemSet(param_2 + 3,0,0x38);
    LOCK();
    portMemGlobals._332_4_ = portMemGlobals._332_4_ + 1;
    UNLOCK();
  }
  return;
}


// ===== 00515b00 portMemInitialize =====

void portMemInitialize(void)

{
  undefined4 uVar1;
  
  uVar1 = portMemGlobals._328_4_;
  LOCK();
  portMemGlobals._328_4_ = portMemGlobals._328_4_ + 1;
  UNLOCK();
  if (uVar1 != 0) {
    return;
  }
  portMemGlobals._0_8_ = 0;
  portMemGlobals._16_8_ = portMemGlobals;
  portMemGlobals._8_8_ = portMemGlobals;
  portMemSet(0x56ec38,0,0x38);
  portMemGlobals._80_8_ = _portMemAllocNonPagedUntracked(portSyncSpinlockSize);
  portSyncSpinlockInitialize(portMemGlobals._80_8_);
  portMemGlobals._88_8_ = _portMemAllocatorAllocPagedWrapper;
  portMemGlobals._128_8_ = _portMemAllocatorAllocNonPagedWrapper;
  portMemGlobals._96_8_ = _portMemAllocatorFreeWrapper;
  portMemGlobals._136_8_ = _portMemAllocatorFreeWrapper;
  portMemGlobals._104_8_ = 0;
  portMemGlobals._144_8_ = 0;
  portMemGlobals._120_8_ = 0x56ecc8;
  portMemGlobals._160_8_ = 0x56ecc8;
  portMemInitializeAllocatorTracking(0x56ec78,0x56ecc8);
  portMemGlobals._112_8_ = 0x56ecc8;
  portMemGlobals._152_8_ = 0x56ecc8;
  return;
}


// ===== 00515c00 portMemAllocatorCreateNonPaged =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Removing unreachable block (ram,0x00515ca8) */

undefined8 * portMemAllocatorCreateNonPaged(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  int iVar6;
  
  puVar5 = (undefined8 *)(*(code *)portMemGlobals._128_8_)(0x56eca0,0x78);
  uVar4 = portMemGlobals._152_8_;
  if (puVar5 != (undefined8 *)0x0) {
    if (portMemGlobals._152_8_ != 0) {
      LOCK();
      piVar1 = (int *)(portMemGlobals._152_8_ + 0x18);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      LOCK();
      *(int *)(uVar4 + 0x1c) = *(int *)(uVar4 + 0x1c) + 1;
      UNLOCK();
      LOCK();
      *(long *)(uVar4 + 0x30) = *(long *)(uVar4 + 0x30) + 0x78;
      UNLOCK();
      piVar1 = (int *)(uVar4 + 0x20);
      do {
        iVar6 = *piVar1;
        if (*(long *)(uVar4 + 0x38) != 0) break;
        LOCK();
        iVar3 = *piVar1;
        if (iVar6 == iVar3) {
          *piVar1 = iVar2 + 1;
        }
        UNLOCK();
      } while (iVar6 != iVar3);
      LOCK();
      iVar2 = portMemGlobals._24_4_ + 1;
      UNLOCK();
      iVar6 = portMemGlobals._24_4_ + 1;
      LOCK();
      portMemGlobals._28_4_ = portMemGlobals._28_4_ + 1;
      UNLOCK();
      LOCK();
      portMemGlobals._48_8_ = portMemGlobals._48_8_ + 0x78;
      UNLOCK();
      portMemGlobals._24_4_ = iVar2;
      if (portMemGlobals._56_8_ == 0) {
        LOCK();
        UNLOCK();
        portMemGlobals._32_4_ = iVar6;
      }
    }
    *puVar5 = _portMemAllocatorAllocNonPagedWrapper;
    puVar5[4] = puVar5 + 5;
    puVar5[1] = _portMemAllocatorFreeWrapper;
    puVar5[2] = _portMemAllocatorReleaseWrapper;
    portMemInitializeAllocatorTracking(puVar5);
  }
  return puVar5;
}


// ===== 00515cf0 _portMemAllocatorAlloc =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Removing unreachable block (ram,0x00515da6) */

long _portMemAllocatorAlloc(undefined8 *param_1,long param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  int iVar6;
  
  if ((param_2 == 0) || (param_1 == (undefined8 *)0x0)) {
    return 0;
  }
  lVar5 = (*(code *)*param_1)();
  if ((lVar5 != 0) && (lVar4 = param_1[3], lVar4 != 0)) {
    LOCK();
    piVar1 = (int *)(lVar4 + 0x18);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    LOCK();
    *(int *)(lVar4 + 0x1c) = *(int *)(lVar4 + 0x1c) + 1;
    UNLOCK();
    LOCK();
    *(long *)(lVar4 + 0x30) = *(long *)(lVar4 + 0x30) + param_2;
    UNLOCK();
    piVar1 = (int *)(lVar4 + 0x20);
    do {
      iVar6 = *piVar1;
      if (*(long *)(lVar4 + 0x38) != 0) break;
      LOCK();
      iVar3 = *piVar1;
      if (iVar6 == iVar3) {
        *piVar1 = iVar2 + 1;
      }
      UNLOCK();
    } while (iVar6 != iVar3);
    LOCK();
    iVar2 = portMemGlobals._24_4_ + 1;
    UNLOCK();
    iVar6 = portMemGlobals._24_4_ + 1;
    LOCK();
    portMemGlobals._28_4_ = portMemGlobals._28_4_ + 1;
    UNLOCK();
    LOCK();
    portMemGlobals._48_8_ = portMemGlobals._48_8_ + param_2;
    UNLOCK();
    portMemGlobals._24_4_ = iVar2;
    if (portMemGlobals._56_8_ == 0) {
      LOCK();
      UNLOCK();
      portMemGlobals._32_4_ = iVar6;
    }
  }
  return lVar5;
}


// ===== 00515dc0 _portMemAllocatorFree =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _portMemAllocatorFree(long param_1,long param_2)

{
  int *piVar1;
  
  if ((param_2 != 0) && (param_1 != 0)) {
    if (*(long *)(param_1 + 0x18) != 0) {
      LOCK();
      piVar1 = (int *)(*(long *)(param_1 + 0x18) + 0x18);
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      LOCK();
      portMemGlobals._24_4_ = portMemGlobals._24_4_ + -1;
      UNLOCK();
    }
    (**(code **)(param_1 + 8))();
    return;
  }
  return;
}


// ===== 00515e00 portMemExTrackingGetActiveStats =====

undefined8 portMemExTrackingGetActiveStats(long param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  undefined1 *puVar2;
  
  if (param_1 == 0) {
    puVar2 = portMemGlobals;
  }
  else {
    puVar2 = *(undefined1 **)(param_1 + 0x18);
    if (puVar2 == (undefined1 *)0x0) {
      return 0x57;
    }
  }
  *param_2 = *(undefined4 *)(puVar2 + 0x18);
  uVar1 = *(undefined8 *)(puVar2 + 0x28);
  *(undefined8 *)(param_2 + 4) = uVar1;
  *(undefined8 *)(param_2 + 2) = uVar1;
  *(undefined8 *)(param_2 + 6) = 0;
  return 0;
}


// ===== 00515e50 _portMemAllocPagedUntracked =====

undefined8 _portMemAllocPagedUntracked(long param_1)

{
  undefined8 local_10;
  
  local_10 = 0;
  if (param_1 == 0) {
    return 0;
  }
  os_alloc_mem(&local_10,param_1);
  return local_10;
}


// ===== 00515e90 _portMemAllocNonPagedUntracked =====

undefined8 _portMemAllocNonPagedUntracked(long param_1)

{
  undefined8 local_10;
  
  local_10 = 0;
  if (param_1 == 0) {
    return 0;
  }
  os_alloc_mem(&local_10,param_1);
  return local_10;
}


// ===== 00515ed0 _portMemFreeUntracked =====

void _portMemFreeUntracked(long param_1)

{
  if (param_1 != 0) {
    os_free_mem();
    return;
  }
  return;
}


// ===== 00515ef0 portMemCopy =====

long portMemCopy(long param_1,ulong param_2,long param_3,ulong param_4)

{
  long lVar1;
  
  if (param_2 == 0) {
    return param_1;
  }
  if ((param_3 != 0 && param_1 != 0) && (param_4 <= param_2)) {
    lVar1 = os_mem_copy(param_1,param_3,(int)param_4);
    return lVar1;
  }
  return 0;
}


// ===== 00515f30 portMemSet =====

long portMemSet(long param_1,undefined1 param_2,long param_3)

{
  long lVar1;
  
  if ((param_3 != 0) && (param_1 != 0)) {
    lVar1 = os_mem_set(param_1,param_2);
    return lVar1;
  }
  return param_1;
}


// ===== 00515f60 portMemCmp =====

undefined8 portMemCmp(long param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  
  if (param_3 == 0) {
    return 0;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = os_mem_cmp();
    return uVar1;
  }
  return 0xffffffff;
}


// ===== 00515fa0 portMemMove =====

ulong portMemMove(ulong param_1,ulong param_2,ulong param_3,ulong param_4)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  bool bVar8;
  
  if ((param_1 == 0 || param_3 == 0) || (param_2 < param_4)) {
    return 0;
  }
  if (param_1 == param_3) {
    return param_1;
  }
  uVar6 = param_1;
  if ((((uint)param_3 | (uint)param_1) & 3) == 0) {
    uVar2 = param_4 >> 2;
    uVar4 = (ulong)((uint)param_4 & 3);
    lVar7 = uVar2 - 1;
    if (param_1 <= param_3) {
      lVar5 = 0;
      if (uVar2 != 0) {
        do {
          *(undefined4 *)(param_1 + lVar5) = *(undefined4 *)(param_3 + lVar5);
          lVar5 = lVar5 + 4;
        } while (lVar5 != uVar2 * 4);
        param_3 = param_3 + 4 + lVar7 * 4;
        uVar6 = param_1 + 4 + lVar7 * 4;
      }
      goto LAB_00516063;
    }
    lVar5 = param_1 + param_4;
    lVar3 = param_3 + param_4;
    if (uVar4 == 0) goto LAB_0051601d;
  }
  else {
    uVar4 = param_4;
    if (param_1 <= param_3) {
LAB_00516063:
      uVar2 = 0;
      if (uVar4 == 0) {
        return param_1;
      }
      do {
        *(undefined1 *)(uVar6 + uVar2) = *(undefined1 *)(param_3 + uVar2);
        uVar2 = uVar2 + 1;
      } while (uVar4 != uVar2);
      return param_1;
    }
    if (param_4 == 0) {
      return param_1;
    }
    lVar7 = -1;
    uVar2 = 0;
  }
  lVar3 = (param_3 + param_4) - uVar4;
  lVar5 = (param_1 + param_4) - uVar4;
  do {
    uVar4 = uVar4 - 1;
    *(undefined1 *)(lVar5 + uVar4) = *(undefined1 *)(lVar3 + uVar4);
  } while (uVar4 != 0);
LAB_0051601d:
  if (uVar2 == 0) {
    return param_1;
  }
  lVar1 = lVar7 * -4;
  do {
    *(undefined4 *)(lVar5 + lVar1 + -4 + lVar7 * 4) =
         *(undefined4 *)(lVar3 + lVar1 + -4 + lVar7 * 4);
    bVar8 = lVar7 != 0;
    lVar7 = lVar7 + -1;
  } while (bVar8);
  return param_1;
}


// ===== 00516110 portMemExCopyFromUser =====

undefined8 portMemExCopyFromUser(undefined8 param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  
  if (param_2 == 0) {
    return 0x3d;
  }
  if (param_3 != 0) {
    uVar1 = os_memcpy_from_user(param_2,param_1);
    return uVar1;
  }
  return 0x1f;
}


// ===== 00516150 portMemExCopyToUser =====

undefined8 portMemExCopyToUser(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 0x3d;
  }
  if (param_3 != 0) {
    uVar1 = os_memcpy_to_user(param_2,param_1);
    return uVar1;
  }
  return 0x1f;
}


// ===== 00516190 portMemExSafeForPagedAlloc =====

undefined8 portMemExSafeForPagedAlloc(void)

{
  return 1;
}


// ===== 005161a0 portMemExSafeForNonPagedAlloc =====

undefined8 portMemExSafeForNonPagedAlloc(void)

{
  return 1;
}


// ===== 005161c0 portStringBufferToHex.part.0 =====

ulong portStringBufferToHex_part_0(long param_1,ulong param_2,long param_3,long param_4)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  ulong uVar4;
  ulong uVar5;
  
  uVar4 = param_4 * 2;
  if (param_2 <= (ulong)(param_4 * 2)) {
    uVar4 = param_2 - 1;
  }
  if (uVar4 != 0) {
    uVar5 = 0;
    do {
      bVar1 = *(byte *)(param_3 + (uVar5 >> 1));
      bVar2 = bVar1 >> 4;
      if ((uVar5 & 1) != 0) {
        bVar2 = bVar1 & 0xf;
      }
      cVar3 = bVar2 + 0x30;
      if (9 < bVar2) {
        cVar3 = bVar2 + 0x57;
      }
      *(char *)(param_1 + uVar5) = cVar3;
      uVar5 = uVar5 + 1;
    } while (uVar4 != uVar5);
  }
  *(undefined1 *)(param_1 + uVar4) = 0;
  return uVar4;
}


// ===== 00516240 portStringLength =====

long portStringLength(char *param_1)

{
  char *pcVar1;
  
  pcVar1 = param_1;
  if (*param_1 == '\0') {
    return 0;
  }
  do {
    pcVar1 = pcVar1 + 1;
  } while (*pcVar1 != '\0');
  return (long)pcVar1 - (long)param_1;
}


// ===== 00516270 portStringLengthSafe =====

long portStringLengthSafe(char *param_1,long param_2)

{
  char *pcVar1;
  
  pcVar1 = param_1;
  if (param_2 == 0) {
    return 0;
  }
  do {
    if (*pcVar1 == '\0') break;
    pcVar1 = pcVar1 + 1;
  } while (pcVar1 != param_1 + param_2);
  return (long)pcVar1 - (long)param_1;
}


// ===== 005162b0 portStringCompare =====

int portStringCompare(long param_1,long param_2,long param_3)

{
  byte bVar1;
  long lVar2;
  
  lVar2 = 0;
  if (param_3 != 0) {
    do {
      bVar1 = *(byte *)(param_1 + lVar2);
      if (bVar1 != *(byte *)(param_2 + lVar2)) {
        return (uint)bVar1 - (uint)*(byte *)(param_2 + lVar2);
      }
    } while ((bVar1 != 0) && (lVar2 = lVar2 + 1, param_3 != lVar2));
  }
  return 0;
}


// ===== 00516300 portStringCopy =====

ulong portStringCopy(long param_1,ulong param_2,char *param_3,ulong param_4)

{
  char *pcVar1;
  long lVar2;
  
  if (param_4 == 0) {
    param_4 = 0;
    lVar2 = -1;
  }
  else {
    pcVar1 = param_3;
    do {
      if (*pcVar1 == '\0') break;
      pcVar1 = pcVar1 + 1;
    } while (pcVar1 != param_3 + param_4);
    if (param_4 == (long)pcVar1 - (long)param_3) {
      if (param_2 <= param_4) {
        param_4 = param_2;
      }
    }
    else {
      param_4 = ((long)pcVar1 - (long)param_3) + 1;
      if (param_2 < param_4) {
        param_4 = param_2;
      }
    }
    lVar2 = param_4 - 1;
    if (1 < param_4) {
      portMemCopy(param_1,param_2,param_3);
      *(undefined1 *)(param_1 + lVar2) = 0;
      return param_4;
    }
  }
  *(undefined1 *)(param_1 + lVar2) = 0;
  return param_4;
}


// ===== 005163c0 portStringCat =====

char * portStringCat(char *param_1,long param_2,char *param_3,ulong param_4)

{
  char *pcVar1;
  ulong uVar2;
  ulong uVar3;
  char *pcVar4;
  long lVar5;
  
  lVar5 = 0;
  uVar3 = 0;
  pcVar4 = param_1;
  if (param_2 != 0) {
    do {
      if (*pcVar4 == '\0') break;
      pcVar4 = pcVar4 + 1;
    } while (pcVar4 != param_1 + param_2);
    lVar5 = (long)pcVar4 - (long)param_1;
    uVar3 = param_2 - lVar5;
  }
  if (param_4 != 0) {
    pcVar1 = param_3;
    do {
      if (*pcVar1 == '\0') break;
      pcVar1 = pcVar1 + 1;
    } while (pcVar1 != param_3 + param_4);
    uVar2 = ((long)pcVar1 - (long)param_3) + 1;
    if (uVar3 < uVar2) {
      uVar2 = uVar3;
    }
    if (param_4 <= uVar3) {
      uVar3 = param_4;
    }
    if (param_4 == (long)pcVar1 - (long)param_3) {
      uVar2 = uVar3;
    }
    if (uVar2 != 0) {
      if (uVar2 != 1) {
        portMemCopy(pcVar4,param_2,param_3,uVar2 - 1);
      }
      param_1[(uVar2 - 1) + lVar5] = '\0';
    }
  }
  return param_1;
}


// ===== 005164a0 portStringConvertAsciiToUtf16 =====

ulong portStringConvertAsciiToUtf16(undefined2 *param_1,ulong param_2,char *param_3,long param_4)

{
  ulong uVar1;
  ulong uVar2;
  char *pcVar3;
  ulong uVar4;
  undefined2 *puVar5;
  
  uVar4 = 0;
  if (param_2 != 0) {
    puVar5 = param_1;
    if (param_4 != 0) {
      pcVar3 = param_3;
      do {
        if (*pcVar3 == '\0') break;
        pcVar3 = pcVar3 + 1;
      } while (pcVar3 != param_3 + param_4);
      uVar4 = (long)pcVar3 - (long)param_3;
      if (uVar4 < param_2) {
        param_2 = uVar4 - 1;
      }
      else {
        uVar4 = param_2 - 1;
        param_2 = param_2 - 2;
      }
      uVar2 = uVar4;
      while (uVar1 = param_2, puVar5 = param_1 + uVar4, uVar2 != 0) {
        param_1[uVar1] = (short)param_3[uVar1];
        param_2 = uVar1 - 1;
        uVar2 = uVar1;
      }
    }
    *puVar5 = 0;
  }
  return uVar4;
}


// ===== 00516520 portStringBufferToHex =====

undefined8 portStringBufferToHex(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if (param_2 != 0) {
    uVar1 = portStringBufferToHex_part_0();
    return uVar1;
  }
  return 0;
}


// ===== 00516540 portStringBufferToHexGroups =====

ulong portStringBufferToHexGroups
                (undefined1 *param_1,long param_2,long param_3,ulong param_4,long param_5,
                long param_6,char *param_7)

{
  long lVar1;
  undefined1 *puVar2;
  ulong uVar3;
  long lVar4;
  char *pcVar5;
  ulong uVar6;
  long lVar7;
  long local_68;
  
  uVar6 = 0;
  if (param_2 != 0) {
    pcVar5 = param_7;
    if (*param_7 == '\0') {
      local_68 = 0;
    }
    else {
      do {
        pcVar5 = pcVar5 + 1;
      } while (*pcVar5 != '\0');
      local_68 = (long)pcVar5 - (long)param_7;
    }
    if (param_5 == 0) {
      uVar6 = 0;
      puVar2 = param_1;
    }
    else {
      uVar6 = 0;
      lVar7 = 0;
      do {
        puVar2 = param_1 + uVar6;
        if (param_2 - 1U <= uVar6) goto LAB_00516640;
        uVar3 = (ulong)(*(uint *)(param_6 + lVar7 * 4) >> 1);
        if (param_4 < uVar3) {
          uVar3 = param_4;
        }
        param_4 = param_4 - uVar3;
        lVar4 = param_2;
        lVar1 = portStringBufferToHex_part_0(puVar2,param_2 - uVar6,param_3,uVar3);
        uVar6 = uVar6 + lVar1;
        if (param_5 + -1 != lVar7) {
          portMemCopy(param_1 + uVar6,lVar4 - uVar6,param_7,local_68);
          uVar6 = uVar6 + local_68;
        }
        lVar7 = lVar7 + 1;
        param_3 = param_3 + uVar3;
      } while (param_5 != lVar7);
      puVar2 = param_1 + uVar6;
    }
LAB_00516640:
    *puVar2 = 0;
  }
  return uVar6;
}


// ===== 00516690 portSyncSpinlockInitialize =====

undefined8 portSyncSpinlockInitialize(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    *(undefined8 *)(param_1 + 0x10) = 0;
    uVar1 = os_alloc_spinlock();
    return uVar1;
  }
  return 0x3d;
}


// ===== 005166c0 portSyncSpinlockDestroy =====

void portSyncSpinlockDestroy(undefined8 *param_1)

{
  os_free_spinlock(*param_1);
  if (param_1[2] != 0) {
    _portMemAllocatorFree(param_1[2],param_1);
    return;
  }
  return;
}


// ===== 00516700 portSyncSpinlockAcquire =====

void portSyncSpinlockAcquire(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = os_acquire_spinlock(*param_1);
  param_1[1] = uVar1;
  return;
}


// ===== 00516730 portSyncSpinlockRelease =====

void portSyncSpinlockRelease(undefined8 *param_1)

{
  os_release_spinlock(*param_1,param_1[1]);
  return;
}


// ===== 00516740 portSyncMutexInitialize =====

undefined8 portSyncMutexInitialize(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    *(undefined8 *)(param_1 + 8) = 0;
    uVar1 = os_alloc_mutex();
    return uVar1;
  }
  return 0x3d;
}


// ===== 00516770 portSyncMutexDestroy =====

void portSyncMutexDestroy(undefined8 *param_1)

{
  os_free_mutex(*param_1);
  if (param_1[1] != 0) {
    _portMemAllocatorFree(param_1[1],param_1);
    return;
  }
  return;
}


// ===== 005167b0 portSyncMutexAcquire =====

void portSyncMutexAcquire(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = os_acquire_mutex(*param_1);
  if (iVar1 == 0) {
    return;
  }
  out_string(
            "Assertion failed: \"status == NV_OK\" at src/libraries/nvport/sync/sync_unix_kernel_os.c:133\n"
            );
  os_dbg_breakpoint();
  return;
}


// ===== 005167f0 portSyncMutexRelease =====

void portSyncMutexRelease(undefined8 *param_1)

{
  os_release_mutex(*param_1);
  return;
}


// ===== 00516800 portSyncSemaphoreDestroy =====

void portSyncSemaphoreDestroy(undefined8 *param_1)

{
  os_free_semaphore(*param_1);
  if (param_1[1] != 0) {
    _portMemAllocatorFree(param_1[1],param_1);
    return;
  }
  return;
}


// ===== 00516840 portSyncSemaphoreAcquire =====

void portSyncSemaphoreAcquire(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = os_acquire_semaphore(*param_1);
  if (iVar1 == 0) {
    return;
  }
  out_string(
            "Assertion failed: \"status == NV_OK\" at src/libraries/nvport/sync/sync_unix_kernel_os.c:198\n"
            );
  os_dbg_breakpoint();
  return;
}


// ===== 00516880 portSyncSemaphoreRelease =====

void portSyncSemaphoreRelease(undefined8 *param_1)

{
  os_release_semaphore(*param_1);
  return;
}


// ===== 00516890 portSyncRwLockInitialize =====

byte portSyncRwLockInitialize(long *param_1)

{
  long lVar1;
  
  if (param_1 != (long *)0x0) {
    param_1[1] = 0;
    lVar1 = os_alloc_rwlock();
    *param_1 = lVar1;
    return -(lVar1 == 0) & 0x51;
  }
  return 0x3d;
}


// ===== 005168d0 portSyncRwLockDestroy =====

void portSyncRwLockDestroy(undefined8 *param_1)

{
  os_free_rwlock(*param_1);
  if (param_1[1] != 0) {
    _portMemAllocatorFree(param_1[1],param_1);
    return;
  }
  return;
}


// ===== 00516910 portSyncRwLockAcquireRead =====

void portSyncRwLockAcquireRead(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = os_acquire_rwlock_read(*param_1);
  if (iVar1 == 0) {
    return;
  }
  out_string(
            "Assertion failed: \"status == NV_OK\" at src/libraries/nvport/sync/sync_unix_kernel_os.c:262\n"
            );
  os_dbg_breakpoint();
  return;
}


// ===== 00516950 portSyncRwLockAcquireReadConditional =====

bool portSyncRwLockAcquireReadConditional(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = os_cond_acquire_rwlock_read(*param_1);
  return iVar1 == 0;
}


// ===== 00516970 portSyncRwLockAcquireWrite =====

void portSyncRwLockAcquireWrite(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = os_acquire_rwlock_write(*param_1);
  if (iVar1 == 0) {
    return;
  }
  out_string(
            "Assertion failed: \"status == NV_OK\" at src/libraries/nvport/sync/sync_unix_kernel_os.c:285\n"
            );
  os_dbg_breakpoint();
  return;
}


// ===== 005169b0 portSyncRwLockAcquireWriteConditional =====

bool portSyncRwLockAcquireWriteConditional(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = os_cond_acquire_rwlock_write(*param_1);
  return iVar1 == 0;
}


// ===== 005169d0 portSyncRwLockReleaseRead =====

void portSyncRwLockReleaseRead(undefined8 *param_1)

{
  os_release_rwlock_read(*param_1);
  return;
}


// ===== 005169e0 portSyncRwLockReleaseWrite =====

void portSyncRwLockReleaseWrite(undefined8 *param_1)

{
  os_release_rwlock_write(*param_1);
  return;
}


// ===== 005169f0 portSyncExSafeToSleep =====

void portSyncExSafeToSleep(void)

{
  os_semaphore_may_sleep();
  return;
}


// ===== 00516a00 portSyncExSafeToWake =====

undefined8 portSyncExSafeToWake(void)

{
  return 1;
}


// ===== 00516a10 portSyncSpinlockCreate =====

long portSyncSpinlockCreate(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = _portMemAllocatorAlloc(param_1,portSyncSpinlockSize);
  lVar3 = lVar2;
  if (lVar2 != 0) {
    *(undefined8 *)(lVar2 + 0x10) = 0;
    iVar1 = os_alloc_spinlock(lVar2);
    if (iVar1 == 0) {
      *(undefined8 *)(lVar2 + 0x10) = param_1;
    }
    else {
      lVar3 = 0;
      _portMemAllocatorFree(param_1,lVar2);
    }
  }
  return lVar3;
}


// ===== 00516a70 portSyncMutexCreate =====

long portSyncMutexCreate(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = _portMemAllocatorAlloc(param_1,portSyncMutexSize);
  lVar3 = lVar2;
  if (lVar2 != 0) {
    *(undefined8 *)(lVar2 + 8) = 0;
    iVar1 = os_alloc_mutex(lVar2);
    if (iVar1 == 0) {
      *(undefined8 *)(lVar2 + 8) = param_1;
    }
    else {
      lVar3 = 0;
      _portMemAllocatorFree(param_1,lVar2);
    }
  }
  return lVar3;
}


// ===== 00516ad0 portSyncSemaphoreCreate =====

long * portSyncSemaphoreCreate(long param_1,undefined4 param_2)

{
  long *plVar1;
  long lVar2;
  
  plVar1 = (long *)_portMemAllocatorAlloc(param_1,portSyncSemaphoreSize);
  if (plVar1 != (long *)0x0) {
    plVar1[1] = 0;
    lVar2 = os_alloc_semaphore(param_2);
    *plVar1 = lVar2;
    if (lVar2 == 0) {
      _portMemAllocatorFree(param_1);
      return (long *)0x0;
    }
    plVar1[1] = param_1;
  }
  return plVar1;
}


// ===== 00516b50 portSyncRwLockCreate =====

long * portSyncRwLockCreate(long param_1)

{
  long *plVar1;
  long lVar2;
  
  plVar1 = (long *)_portMemAllocatorAlloc(param_1,portSyncRwLockSize);
  if (plVar1 != (long *)0x0) {
    plVar1[1] = 0;
    lVar2 = os_alloc_rwlock();
    *plVar1 = lVar2;
    if (lVar2 == 0) {
      _portMemAllocatorFree(param_1);
      return (long *)0x0;
    }
    plVar1[1] = param_1;
  }
  return plVar1;
}


// ===== 00516bc0 portSyncInitialize =====

void portSyncInitialize(void)

{
  portSyncSpinlockSize = 0x18;
  portSyncMutexSize = 0x10;
  portSyncSemaphoreSize = 0x10;
  portSyncRwLockSize = 0x10;
  return;
}


// ===== 00516c00 portSyncShutdown =====

void portSyncShutdown(void)

{
  return;
}


// ===== 00516c10 portThreadGetCurrentThreadId =====

undefined8 portThreadGetCurrentThreadId(void)

{
  undefined8 local_10;
  
  local_10 = 0;
  os_get_current_thread(&local_10);
  return local_10;
}


// ===== 00516c40 portUtilIsInterruptContext =====

void portUtilIsInterruptContext(void)

{
  os_is_isr();
  return;
}


// ===== 00516c50 ntz_64 =====

char ntz_64(ulong param_1)

{
  param_1 = -param_1 & param_1;
  return ((param_1 & 0x5555555555555555) == 0) + ((int)param_1 == 0) * ' ' + (param_1 == 0) +
         ((param_1 & 0xffff0000ffff) == 0) * '\x10' + ((param_1 & 0xff00ff00ff00ff) == 0) * '\b' +
         ((param_1 & 0xf0f0f0f0f0f0f0f) == 0) * '\x04' +
         ((param_1 & 0x3333333333333333) == 0) * '\x02';
}


// ===== 00516ce0 allocPartialList =====

void allocPartialList(long param_1,long *param_2)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  long *plVar7;
  
  plVar7 = (long *)listHead_IMPL(param_1 + 0x30);
  uVar1 = plVar7[1];
  uVar5 = ntz_64(uVar1);
  bVar4 = (byte)uVar5 & 0x3f;
  if (*(uint *)(param_1 + 0x78) <= uVar5) {
    nvAssertFailedNoLog("freeIdx < pPool->ratio","src/libraries/poolalloc/poolalloc.c",0xb3);
  }
  plVar7[1] = uVar1 & (-2L << bVar4 | 0xfffffffffffffffeU >> 0x40 - bVar4);
  uVar6 = ntz_64();
  if (*(uint *)(param_1 + 0x78) <= uVar6) {
    listRemoveIntrusive_IMPL(param_1 + 0x30,plVar7);
    listPrependExisting_IMPL(param_1 + 0x18,plVar7);
  }
  lVar2 = *(long *)(param_1 + 0x70);
  lVar3 = *plVar7;
  param_2[1] = (long)plVar7;
  *param_2 = (ulong)uVar5 * lVar2 + lVar3;
  return;
}


// ===== 00516db0 poolListDestroy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void poolListDestroy(long param_1,long param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 local_38;
  undefined8 *local_30;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pList != NULL","src/libraries/poolalloc/poolalloc.c",0x58);
  }
  puVar1 = (undefined8 *)listHead_IMPL(param_1);
  while (puVar1 != (undefined8 *)0x0) {
    puVar2 = (undefined8 *)listNext_IMPL(param_1,puVar1);
    local_38 = *puVar1;
    local_30 = (undefined8 *)puVar1[2];
    if ((undefined8 *)puVar1[2] == (undefined8 *)0x0) {
      local_30 = puVar1;
    }
    (**(code **)(param_2 + 0x58))
              (*(undefined8 *)(param_2 + 0x60),*(undefined8 *)(param_2 + 0x68),&local_38);
    listRemoveIntrusive_IMPL(param_1,puVar1);
    _portMemAllocatorFree(*(undefined8 *)(param_2 + 0x48),puVar1);
    puVar1 = puVar2;
  }
  return;
}


// ===== 00516e80 allocFreeList =====

void allocFreeList(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)listHead_IMPL();
  puVar2[1] = 0xfffffffffffffffe;
  if (*(uint *)(param_1 + 0x78) < 2) {
    listRemoveIntrusive_IMPL(param_1,puVar2);
    listPrependExisting_IMPL(param_1 + 0x18,puVar2);
  }
  else {
    listRemoveIntrusive_IMPL(param_1,puVar2);
    listPrependExisting_IMPL(param_1 + 0x30,puVar2);
  }
  uVar1 = *puVar2;
  param_2[1] = puVar2;
  *param_2 = uVar1;
  return;
}


// ===== 00516f00 poolInitialize =====

long poolInitialize(ulong param_1,ulong param_2,undefined8 param_3,undefined8 param_4,
                   undefined8 param_5,undefined8 param_6,undefined4 param_7)

{
  long lVar1;
  char *pcVar2;
  
  lVar1 = _portMemAllocatorAlloc(param_6,0x80);
  if (lVar1 != 0) {
    *(ulong *)(lVar1 + 0x68) = param_1;
    *(ulong *)(lVar1 + 0x70) = param_2;
    *(undefined8 *)(lVar1 + 0x60) = param_5;
    *(undefined8 *)(lVar1 + 0x48) = param_6;
    *(undefined8 *)(lVar1 + 0x50) = param_3;
    *(undefined8 *)(lVar1 + 0x58) = param_4;
    *(int *)(lVar1 + 0x78) = (int)(param_1 / param_2);
    *(undefined4 *)(lVar1 + 0x7c) = param_7;
    listInitIntrusive_IMPL(lVar1,0x18,param_1 % param_2);
    listInitIntrusive_IMPL(lVar1 + 0x18,0x18);
    listInitIntrusive_IMPL(lVar1 + 0x30,0x18);
    pcVar2 = "disabled";
    if ((*(byte *)(lVar1 + 0x7c) & 1) != 0) {
      pcVar2 = "enabled";
    }
    nvDbg_Printf("src/libraries/poolalloc/poolalloc.c",0xfb,"poolInitialize",1,
                 "NVRM: Initialized pool with upstreamPageSize = %lldB, allocPageSize = %lldB and autoPopulate %s\n"
                 ,*(undefined8 *)(lVar1 + 0x68),*(undefined8 *)(lVar1 + 0x70),pcVar2);
  }
  return lVar1;
}


// ===== 00517000 poolReserve =====

/* WARNING: Function: __x86_indirect_thunk_rbx replaced with injection: x86_indirect_thunk_rbx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int poolReserve(long param_1,ulong param_2)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 *puVar8;
  
  if ((param_1 == 0) || (*(long *)(param_1 + 0x50) == 0)) {
    return 0x1f;
  }
  iVar3 = 0;
  uVar2 = listCount_IMPL();
  if (uVar2 < param_2) {
    uVar6 = param_2 - uVar2;
    pcVar1 = *(code **)(param_1 + 0x50);
    puVar4 = (undefined8 *)_portMemAllocatorAlloc(*(undefined8 *)(param_1 + 0x48),uVar6 * 0x10);
    if (puVar4 != (undefined8 *)0x0) {
      iVar3 = (*pcVar1)(*(undefined8 *)(param_1 + 0x60),*(undefined8 *)(param_1 + 0x68),uVar6,puVar4
                       );
      uVar7 = 0;
      puVar8 = puVar4;
      if (iVar3 == 0) {
        do {
          puVar5 = (undefined8 *)_portMemAllocatorAlloc(*(undefined8 *)(param_1 + 0x48),0x28);
          if (puVar5 == (undefined8 *)0x0) {
            nvAssertFailedNoLog("pNode != NULL","src/libraries/poolalloc/poolalloc.c",300);
            puVar8 = puVar4 + uVar7 * 2;
            if (uVar7 < uVar6) {
              do {
                uVar7 = uVar7 + 1;
                (**(code **)(param_1 + 0x58))
                          (*(undefined8 *)(param_1 + 0x60),*(undefined8 *)(param_1 + 0x68),puVar8);
                puVar8 = puVar8 + 2;
              } while (uVar6 != uVar7);
            }
            iVar3 = 0x51;
            goto LAB_00517157;
          }
          uVar7 = uVar7 + 1;
          listPrependExisting_IMPL(param_1,puVar5);
          *puVar5 = *puVar8;
          puVar5[1] = 0xffffffffffffffff;
          puVar5[2] = puVar8[1];
          puVar8 = puVar8 + 2;
        } while (uVar6 != uVar7);
        uVar2 = listCount_IMPL(param_1);
        if (param_2 != uVar2) {
          nvAssertFailedNoLog("freeLength == numPages","src/libraries/poolalloc/poolalloc.c",0x136);
        }
      }
      else {
        nvCheckOkFailedNoLog
                  (2,iVar3,
                   "allocCb(pPool->callBackInfo.pUpstreamCtx, pPool->upstreamPageSize, totalAlloc, pPageHandle)"
                   ,"src/libraries/poolalloc/poolalloc.c",0x122);
      }
LAB_00517157:
      _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x48),puVar4);
      return iVar3;
    }
    iVar3 = 0x51;
    nvAssertFailedNoLog("pPageHandle != NULL","src/libraries/poolalloc/poolalloc.c",0x120);
  }
  return iVar3;
}


// ===== 00517220 poolTrim =====

/* WARNING: Function: __x86_indirect_thunk_r15 replaced with injection: x86_indirect_thunk_r15 */

void poolTrim(long param_1,ulong param_2)

{
  code *pcVar1;
  uint uVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined8 local_48;
  undefined8 *local_40;
  
  if ((param_1 == 0) || (*(long *)(param_1 + 0x58) == 0)) {
    return;
  }
  uVar2 = listCount_IMPL();
  if (param_2 < uVar2) {
    lVar4 = 0;
    pcVar1 = *(code **)(param_1 + 0x58);
    do {
      puVar3 = (undefined8 *)listHead_IMPL(param_1);
      local_48 = *puVar3;
      local_40 = (undefined8 *)puVar3[2];
      if ((undefined8 *)puVar3[2] == (undefined8 *)0x0) {
        local_40 = puVar3;
      }
      lVar4 = lVar4 + 1;
      (*pcVar1)(*(undefined8 *)(param_1 + 0x60),*(undefined8 *)(param_1 + 0x68),&local_48);
      listRemoveIntrusive_IMPL(param_1,puVar3);
      _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x48),puVar3);
    } while (uVar2 - param_2 != lVar4);
    uVar2 = listCount_IMPL(param_1);
    if (param_2 != uVar2) {
      nvAssertFailedNoLog("freeLength == preserveNum","src/libraries/poolalloc/poolalloc.c",0x16d);
      return;
    }
  }
  return;
}


// ===== 00517340 poolAllocate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 poolAllocate(long param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  
  iVar1 = listCount_IMPL(param_1 + 0x30);
  if (iVar1 != 0) {
    allocPartialList(param_1,param_2);
    return 0;
  }
  iVar1 = listCount_IMPL(param_1);
  if (iVar1 == 0) {
    if ((*(uint *)(param_1 + 0x7c) & 3) == 1) {
      iVar1 = (**(code **)(param_1 + 0x50))
                        (*(undefined8 *)(param_1 + 0x60),*(undefined8 *)(param_1 + 0x68),1,param_2);
      if (iVar1 == 0) {
        puVar2 = (undefined8 *)_portMemAllocatorAlloc(*(undefined8 *)(param_1 + 0x48),0x28);
        listPrependExisting_IMPL(param_1,puVar2);
        *puVar2 = *param_2;
        puVar2[1] = 0xffffffffffffffff;
        puVar2[2] = param_2[1];
        goto LAB_005173f3;
      }
    }
    return 0x51;
  }
LAB_005173f3:
  allocFreeList(param_1,param_2);
  return 0;
}


// ===== 00517430 poolFree =====

void poolFree(long param_1,long *param_2)

{
  long *plVar1;
  ulong uVar2;
  ulong uVar3;
  
  plVar1 = (long *)param_2[1];
  uVar3 = 1L << ((byte)((ulong)(*param_2 - *plVar1) / *(ulong *)(param_1 + 0x70)) & 0x3f) |
          plVar1[1];
  plVar1[1] = uVar3;
  uVar2 = ~uVar3 - (~uVar3 >> 1 & 0x5555555555555555);
  uVar2 = (uVar2 & 0x3333333333333333) + (uVar2 >> 2 & 0x3333333333333333);
  if ((byte)(((uVar2 >> 4) + uVar2 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38) + 1 ==
      *(int *)(param_1 + 0x78)) {
    listRemoveIntrusive_IMPL(param_1 + 0x18);
    if (plVar1[1] != -1) {
      listPrependExisting_IMPL(param_1 + 0x30);
      return;
    }
    listPrependExisting_IMPL(param_1);
    return;
  }
  if (uVar3 != 0xffffffffffffffff) {
    return;
  }
  listRemoveIntrusive_IMPL(param_1 + 0x30);
  listPrependExisting_IMPL(param_1,plVar1);
  return;
}


// ===== 00517540 poolAllocateContig =====

undefined8 poolAllocateContig(long param_1,uint param_2,undefined8 param_3)

{
  char cVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  uint uVar10;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  if (*(uint *)(param_1 + 0x78) < param_2) {
    nvAssertFailedNoLog("numPages <= pPool->ratio","src/libraries/poolalloc/poolalloc.c",0x1b7);
    return 0x1f;
  }
  iVar2 = listCount_IMPL();
  if (iVar2 == 0) {
    uVar8 = 0x40;
    nvAssertFailedNoLog("listCount(&pPool->freeList) > 0","src/libraries/poolalloc/poolalloc.c",
                        0x1ba);
  }
  else {
    lVar3 = listHead_IMPL(param_1);
    plVar4 = (long *)listAppendNew_IMPL(param_3);
    if (plVar4 == (long *)0x0) {
      return 0x51;
    }
    allocFreeList(param_1,plVar4);
    lVar9 = *plVar4;
    lVar5 = listHead_IMPL(param_1 + 0x30);
    if (lVar3 == lVar5) {
      uVar10 = 1;
      if (1 < param_2) {
        do {
          plVar4 = (long *)listAppendNew_IMPL(param_3);
          if (plVar4 == (long *)0x0) {
            uVar8 = 0x51;
            goto LAB_005175c5;
          }
          allocPartialList(param_1,plVar4);
          lVar9 = lVar9 + *(long *)(param_1 + 0x70);
          if (lVar9 != *plVar4) goto LAB_005175bf;
          uVar10 = uVar10 + 1;
        } while (param_2 != uVar10);
      }
      return 0;
    }
LAB_005175bf:
    uVar8 = 0x40;
LAB_005175c5:
    uVar6 = listTail_IMPL(param_3);
    uVar7 = listHead_IMPL(param_3);
    listIterRange_IMPL(&local_78,param_3,uVar7,uVar6);
    local_58 = local_78;
    local_50 = local_70;
    local_48 = local_68;
    local_40 = local_60;
    while (cVar1 = listIterNext_IMPL(&local_58), cVar1 != '\0') {
      poolFree(param_1,local_58);
    }
    listDestroy_IMPL(param_3);
  }
  return uVar8;
}


// ===== 00517750 poolDestroy =====

void poolDestroy(long param_1)

{
  poolListDestroy(param_1 + 0x18,param_1);
  poolListDestroy(param_1 + 0x30,param_1);
  poolListDestroy(param_1,param_1);
  _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x48),param_1);
  return;
}


// ===== 005177a0 poolGetListLength =====

void poolGetListLength(long param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pPool != NULL","src/libraries/poolalloc/poolalloc.c",0x236);
  }
  if (param_2 != (undefined4 *)0x0) {
    uVar1 = listCount_IMPL(param_1);
    *param_2 = uVar1;
  }
  if (param_3 != (undefined4 *)0x0) {
    uVar1 = listCount_IMPL(param_1 + 0x30);
    *param_3 = uVar1;
  }
  if (param_4 != (undefined4 *)0x0) {
    uVar1 = listCount_IMPL(param_1 + 0x18);
    *param_4 = uVar1;
  }
  return;
}


// ===== 00517820 _rsAccessGetSharedRights =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _rsAccessGetSharedRights(long *param_1,long param_2,long *param_3,uint *param_4)

{
  long *plVar1;
  long lVar2;
  char cVar3;
  long *plVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  long local_90;
  long local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  uint local_60;
  uint local_5c;
  long local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  portMemSet(&local_60,0,4);
  portMemSet(&local_5c,0,4);
  portMemSet(param_4,0,4);
  if (*param_1 != param_2) {
    local_90 = 0;
    lVar7 = 0;
    plVar4 = param_1;
    if (param_3 != (long *)0x0) {
      local_90 = *param_3;
      lVar7 = param_3[3];
    }
    do {
      if ((char)plVar4[0x21] != '\0') {
        plVar4 = plVar4 + 0x1c;
        goto LAB_005178e1;
      }
      plVar1 = plVar4 + 3;
      plVar4 = (long *)*plVar1;
    } while ((long *)*plVar1 != (long *)0x0);
    if (local_90 != 0) {
      plVar4 = (long *)(local_90 + 0x58);
LAB_005178e1:
      uVar5 = listTail_IMPL(plVar4);
      uVar6 = listHead_IMPL(plVar4);
      listIterRange_IMPL(&local_88,plVar4,uVar6,uVar5);
      local_58 = local_88;
      local_50 = local_80;
      local_48 = local_78;
      local_40 = local_70;
LAB_00517940:
      cVar3 = listIterNext_IMPL(&local_58);
      if (cVar3 != '\0') {
        while( true ) {
          lVar2 = local_58;
          cVar3 = (**(code **)(*(long *)param_1[1] + 0xb0))
                            ((long *)param_1[1],param_2,lVar7,local_58);
          if (cVar3 == '\0') break;
          if ((*(byte *)(lVar2 + 10) & 2) != 0) goto LAB_00517940;
          local_60 = local_60 | *(uint *)(lVar2 + 4);
          cVar3 = listIterNext_IMPL(&local_58);
          if (cVar3 == '\0') goto LAB_005179a0;
        }
        if ((*(byte *)(lVar2 + 10) & 2) != 0) {
          local_5c = local_5c | *(uint *)(lVar2 + 4);
        }
        goto LAB_00517940;
      }
LAB_005179a0:
      if (local_90 != 0) {
        local_90 = local_90 + 0x80;
        uVar5 = listTail_IMPL(local_90);
        uVar6 = listHead_IMPL(local_90);
        listIterRange_IMPL(&local_88,local_90,uVar6,uVar5);
        local_58 = local_88;
        local_50 = local_80;
        local_48 = local_78;
        local_40 = local_70;
LAB_00517a10:
        cVar3 = listIterNext_IMPL(&local_58);
        if (cVar3 != '\0') {
          while( true ) {
            lVar2 = local_58;
            cVar3 = (**(code **)(*(long *)param_1[1] + 0xb0))
                              ((long *)param_1[1],param_2,lVar7,local_58);
            if (cVar3 == '\0') break;
            if ((*(byte *)(lVar2 + 10) & 2) != 0) goto LAB_00517a10;
            local_60 = local_60 | *(uint *)(lVar2 + 4);
            cVar3 = listIterNext_IMPL(&local_58);
            if (cVar3 == '\0') goto LAB_00517a64;
          }
          if ((*(byte *)(lVar2 + 10) & 2) != 0) {
            local_5c = local_5c | *(uint *)(lVar2 + 4);
          }
          goto LAB_00517a10;
        }
      }
    }
LAB_00517a64:
    *param_4 = (*param_4 | local_60) & ~local_5c;
  }
  return;
}


// ===== 00517ae0 _rsAccessGrantCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

byte _rsAccessGrantCallback
               (long param_1,long param_2,long param_3,uint *param_4,undefined8 param_5,
               ushort param_6)

{
  char cVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    nvDbg_Printf("src/libraries/resserv/src/rs_access_map.c",0x1ee,"_rsAccessGrantCallback",3,
                 "NVRM: Called with NULL pCallContext, skipping permission checks\n");
    if ((param_4 != (uint *)0x0) && ((*param_4 & 1 << ((byte)param_6 & 0x1f)) != 0)) {
      return 0;
    }
    uVar2 = *(uint *)(&g_rsAccessMetadata + (ulong)param_6 * 4);
  }
  else {
    if ((param_4 != (uint *)0x0) && ((*param_4 & 1 << ((byte)param_6 & 0x1f)) != 0)) {
      return 0;
    }
    uVar2 = *(uint *)(&g_rsAccessMetadata + (ulong)param_6 * 4);
    if ((uVar2 & 4) == 0) {
      if (((uVar2 & 2) != 0) && (1 < *(uint *)(param_2 + 0x28))) {
        return 0;
      }
    }
    else if (*(int *)(param_2 + 0x28) != 0) {
      return 0;
    }
  }
  if (((uVar2 & 0x10) != 0) && (*(int *)(param_1 + 0x10) == *(int *)(param_3 + 0x48))) {
    return 0;
  }
  cVar1 = (**(code **)(**(long **)(param_1 + 8) + 0xa8))
                    (*(long **)(param_1 + 8),param_3,param_5,param_6);
  return -(cVar1 == '\0') & 0x1b;
}


// ===== 00517bf0 rsAccessUpdateRights.part.0 =====

void rsAccessUpdateRights_part_0(long param_1,undefined8 param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  byte bVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  
  uVar8 = 0;
  do {
    uVar7 = uVar8 & 0xffffffff;
    uVar6 = uVar8 & 0xffffffff;
    bVar5 = (byte)uVar6;
    uVar4 = resservGetTlsCallContext();
    if (param_3 != (uint *)0x0) {
      while (bVar5 = (byte)uVar6, (*param_3 & 1 << (bVar5 & 0x1f)) == 0) {
        uVar8 = uVar8 + 1;
        if (uVar8 == 4) {
          return;
        }
        uVar7 = uVar8 & 0xffffffff;
        uVar6 = uVar8 & 0xffffffff;
        uVar4 = resservGetTlsCallContext();
      }
    }
    if (((&g_rsAccessMetadata)[uVar8 * 4] & 8) != 0) {
      iVar1 = _rsAccessGrantCallback(param_1,uVar4,param_2,0,0,uVar7 & 0xffff);
      uVar2 = 1 << (bVar5 & 0x1f);
      uVar3 = ~uVar2 & *(uint *)(param_1 + 0x10c);
      if (iVar1 == 0) {
        uVar3 = *(uint *)(param_1 + 0x10c) | uVar2;
      }
      *(uint *)(param_1 + 0x10c) = uVar3;
    }
    uVar8 = uVar8 + 1;
  } while (uVar8 != 4);
  return;
}


// ===== 00517cb0 rsAccessGetAvailableRights =====

void rsAccessGetAvailableRights(long *param_1,long param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = resservGetTlsCallContext();
  portMemSet(param_3,0,4);
  if (param_2 != *param_1) {
    _rsAccessGetSharedRights(param_1,param_2,uVar1,param_3);
    return;
  }
  portMemCopy(param_3,4,(long)param_1 + 0x10c,4);
  return;
}


// ===== 00517d30 rsAccessLookup =====

long rsAccessLookup(long *param_1,long param_2)

{
  long lVar1;
  
  lVar1 = (long)param_1 + 0x10c;
  if (*param_1 != param_2) {
    lVar1 = 0;
  }
  return lVar1;
}


// ===== 00517d50 rsAccessCheckRights =====

byte rsAccessCheckRights(long *param_1,long param_2,long param_3)

{
  char cVar1;
  undefined1 local_2c [12];
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pRightsRequired != NULL","src/libraries/resserv/src/rs_access_map.c",0xbe);
    return 0x1f;
  }
  cVar1 = rsAccessMaskIsEmpty(param_3);
  if (cVar1 == '\0') {
    if (param_2 == *param_1) {
      rsAccessUpdateRights_part_0(param_1,param_2,param_3);
    }
    rsAccessGetAvailableRights(param_1,param_2,local_2c);
    cVar1 = rsAccessMaskIsSubset(local_2c,param_3);
    return -(cVar1 == '\0') & 0x1b;
  }
  return 0;
}


// ===== 00517e00 rsAccessUpdateRights =====

void rsAccessUpdateRights(long *param_1,long param_2)

{
  if (param_2 != *param_1) {
    return;
  }
  rsAccessUpdateRights_part_0();
  return;
}


// ===== 00517e20 rsShareListLookup =====

int * rsShareListLookup(undefined8 param_1,int *param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  int *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  uVar2 = listTail_IMPL();
  uVar3 = listHead_IMPL(param_1);
  listIterRange_IMPL(&local_68,param_1,uVar3,uVar2);
  local_48 = local_68;
  local_40 = local_60;
  local_38 = local_58;
  local_30 = local_50;
  do {
    cVar1 = listIterNext_IMPL(&local_48);
    if (cVar1 == '\0') {
      return (int *)0x0;
    }
  } while ((((local_48 == (int *)0x0) || (param_2 == (int *)0x0)) ||
           ((short)local_48[2] != (short)param_2[2])) ||
          ((((*(byte *)((long)local_48 + 10) ^ *(byte *)((long)param_2 + 10)) & 2) != 0 ||
           (((short)local_48[2] == 3 && (*local_48 != *param_2))))));
  return local_48;
}


// ===== 00517ee0 rsShareListInsert =====

undefined8 rsShareListInsert(undefined8 param_1,long param_2,long param_3)

{
  long lVar1;
  
  lVar1 = rsShareListLookup();
  if (lVar1 == 0) {
    lVar1 = listAppendValue_IMPL(param_1,param_2);
    if (lVar1 == 0) {
      return 0x51;
    }
  }
  else {
    *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) | *(uint *)(param_2 + 4);
  }
  if (param_3 != 0) {
    portMemCopy(param_3,4,lVar1 + 4,4);
  }
  return 0;
}


// ===== 00517f60 rsShareListRemove =====

void rsShareListRemove(undefined8 param_1,long param_2,long param_3)

{
  char cVar1;
  long lVar2;
  
  lVar2 = rsShareListLookup();
  if (lVar2 == 0) {
    if (param_3 != 0) {
      portMemSet(param_3,0,4);
      return;
    }
  }
  else {
    *(uint *)(lVar2 + 4) = *(uint *)(lVar2 + 4) & ~*(uint *)(param_2 + 4);
    if (param_3 != 0) {
      portMemCopy(param_3,4,lVar2 + 4,4);
    }
    cVar1 = rsAccessMaskIsEmpty(lVar2 + 4);
    if (cVar1 != '\0') {
      listRemove_IMPL(param_1,lVar2);
      return;
    }
  }
  return;
}


// ===== 00518030 rsShareListCopy =====

undefined8 rsShareListCopy(undefined8 param_1,long param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  if (param_2 == 0) {
    return 0;
  }
  uVar2 = listTail_IMPL(param_2);
  uVar3 = listHead_IMPL(param_2);
  listIterRange_IMPL(&local_68,param_2,uVar3,uVar2);
  local_48 = local_68;
  local_40 = local_60;
  local_38 = local_58;
  local_30 = local_50;
  do {
    cVar1 = listIterNext_IMPL(&local_48);
    if (cVar1 == '\0') {
      return 0;
    }
    lVar4 = listAppendValue_IMPL(param_1,local_48);
  } while (lVar4 != 0);
  return 0x51;
}


// ===== 00518100 rsAccessGetActiveShareList =====

void rsAccessGetActiveShareList(void)

{
  FUN_0051812d();
  return;
}


// ===== 0051812d FUN_0051812d =====

long FUN_0051812d(long param_1,long param_2)

{
  long lVar1;
  
  while( true ) {
    if (param_1 == 0) {
      lVar1 = param_2 + 0x58;
      if (param_2 == 0) {
        lVar1 = 0;
      }
      return lVar1;
    }
    if (*(char *)(param_1 + 0x108) != '\0') break;
    param_1 = *(long *)(param_1 + 0x18);
  }
  return param_1 + 0xe0;
}


// ===== 00518150 rsAccessGrantRights =====

byte rsAccessGrantRights(long *param_1,undefined8 param_2,long param_3,long param_4,uint *param_5,
                        undefined8 param_6)

{
  long *plVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  long *plVar8;
  uint local_44;
  uint local_40;
  uint local_3c [3];
  
  portMemSet(&local_44,0,4);
  if (param_4 == 0) {
    plVar1 = (long *)param_1[3];
    if (plVar1 == (long *)0x0) {
      portMemSet(&local_44,0xff,4);
    }
    else {
      if (param_3 == *plVar1) {
        portMemCopy(&local_44,4,(long)plVar1 + 0x10c,4);
      }
      if (param_5 != (uint *)0x0) {
        local_44 = local_44 | *param_5;
      }
    }
    bVar2 = false;
  }
  else {
    portMemCopy(&local_44,4,param_4,4);
    bVar2 = true;
  }
  cVar3 = rsAccessMaskIsEmpty(&local_44);
  if (cVar3 == '\0') {
    puVar7 = (uint *)((long)param_1 + 0x10c);
    if (param_3 != *param_1) {
      puVar7 = local_3c;
      portMemSet(local_3c,0,4);
    }
    if (((param_5 != (uint *)0x0) && (bVar2)) &&
       (cVar3 = rsAccessMaskIsSubset(&local_44,param_5), cVar3 == '\0')) {
      return 0x1b;
    }
    plVar1 = (long *)param_1[3];
    plVar8 = plVar1;
    if (plVar1 != (long *)0x0) {
      plVar8 = (long *)0x0;
      if (param_3 == *plVar1) {
        plVar8 = (long *)((long)plVar1 + 0x10c);
      }
    }
    _rsAccessGetSharedRights(param_1,param_3,param_2,&local_40);
    uVar5 = 0;
    do {
      uVar6 = 1 << ((byte)uVar5 & 0x1f);
      if ((local_44 & uVar6) != 0) {
        if (((local_40 & uVar6) == 0) &&
           (iVar4 = _rsAccessGrantCallback(param_1,param_2,param_3,plVar8,param_6,uVar5 & 0xffff),
           iVar4 != 0)) {
          if (bVar2) {
            return 0x1b;
          }
        }
        else {
          *puVar7 = *puVar7 | uVar6;
        }
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 != 4);
    if (param_5 != (uint *)0x0) {
      cVar3 = rsAccessMaskIsSubset(puVar7,param_5);
      return -(cVar3 == '\0') & 0x1b;
    }
  }
  return 0;
}


// ===== 00518340 rsAccessMaskIsSubset =====

undefined8 rsAccessMaskIsSubset(uint *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  while ((uVar1 = 1 << ((byte)iVar2 & 0x1f), (*param_2 & uVar1) == 0 || ((*param_1 & uVar1) != 0)))
  {
    iVar2 = iVar2 + 1;
    if (iVar2 == 4) {
      return 1;
    }
  }
  return 0;
}


// ===== 00518370 rsAccessMaskIsEmpty =====

bool rsAccessMaskIsEmpty(byte *param_1)

{
  return (*param_1 & 0xf) == 0;
}


// ===== 00518380 rsAccessMaskFromArray =====

void rsAccessMaskFromArray(uint *param_1,ushort *param_2,long param_3)

{
  ushort *puVar1;
  
  portMemSet(param_1,0,4);
  if (param_2 == (ushort *)0x0) {
    nvAssertFailedNoLog("pRightsArray != NULL","src/libraries/resserv/src/rs_access_rights.c",0x76);
    return;
  }
  puVar1 = param_2 + param_3;
  if (param_3 != 0) {
    do {
      if (*param_2 < 4) {
        *param_1 = *param_1 | 1 << ((byte)*param_2 & 0x1f);
      }
      param_2 = param_2 + 1;
    } while (param_2 != puVar1);
  }
  return;
}


// ===== 00518420 _unmapInterMapping =====

void _unmapInterMapping(undefined8 param_1,long param_2,long param_3,long param_4,
                       undefined8 *param_5,undefined8 param_6)

{
  int iVar1;
  undefined8 local_c0 [2];
  long local_b0;
  undefined8 local_98;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 *local_50;
  undefined8 local_48;
  
  portMemSet(&local_80,0,0x48);
  portMemSet(local_c0,0,0x40);
  local_68 = 0;
  local_78 = CONCAT44(*(undefined4 *)(param_4 + 0x60),
                      *(undefined4 *)(*(long *)(param_4 + 0x10) + 0x10));
  local_70 = *(undefined8 *)(param_4 + 0x68);
  local_80 = CONCAT44(*(undefined4 *)(param_3 + 0x10),*(undefined4 *)(param_2 + 0x48));
  local_58 = *(undefined8 *)(param_4 + 0x78);
  local_c0[0] = *param_5;
  local_b0 = param_5[2];
  if (param_5[2] == 0) {
    local_b0 = *(long *)(param_4 + 0x10);
  }
  local_98 = param_5[5];
  local_50 = local_c0;
  local_48 = param_6;
  iVar1 = serverUpdateLockFlagsForInterAutoUnmap(param_1,&local_80);
  if (iVar1 == 0) {
    serverInterUnmap(param_1,&local_80);
  }
  return;
}


// ===== 00518520 clientCanShareResource_IMPL.part.0 =====

void clientCanShareResource_IMPL_part_0
               (undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  int iVar1;
  uint *puVar2;
  uint local_2c;
  
  iVar1 = rsAccessCheckRights(param_2,param_1,param_3 + 4);
  if (iVar1 != 0x1b) {
    return;
  }
  portMemCopy(&local_2c,4,param_3 + 4,4);
  puVar2 = (uint *)rsAccessLookup(param_2,param_1);
  if (puVar2 != (uint *)0x0) {
    local_2c = local_2c & ~*puVar2;
  }
  rsAccessGrantRights(param_2,param_4,param_1,&local_2c,0,0);
  return;
}


// ===== 005185c0 _refRemoveAllDependencies =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _refRemoveAllDependencies(long param_1)

{
  long *plVar1;
  undefined8 *puVar2;
  
  while( true ) {
    puVar2 = (undefined8 *)multimapFirstItem_IMPL(param_1 + 0xb0);
    if (puVar2 == (undefined8 *)0x0) break;
    refRemoveDependant(*puVar2,param_1);
  }
  plVar1 = *(long **)(param_1 + 0x1c0);
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x50))(plVar1,param_1);
  }
  plVar1 = *(long **)(param_1 + 0x1b8);
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x48))(plVar1,param_1);
    return;
  }
  return;
}


// ===== 00518640 clientConstruct_IMPL =====

undefined8 clientConstruct_IMPL(long param_1,undefined8 param_2,undefined4 *param_3)

{
  *(uint *)(param_1 + 0x4c) = (uint)(1 < **(uint **)(param_3 + 0xe));
  *(undefined4 *)(param_1 + 0x48) = *param_3;
  mapInit_IMPL(param_1 + 0x58,param_2,0x1e0);
  listInitIntrusive_IMPL(param_1 + 0xc0,0x1c8);
  listInit_IMPL(param_1 + 0x78,param_2,8);
  *(undefined1 *)(param_1 + 0x50) = 1;
  *(undefined8 *)(param_1 + 0xa0) = 0x80000caf00000;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined8 *)(param_1 + 0xa8) = 1;
  *(undefined8 *)(param_1 + 0xb0) = 0;
  return 0;
}


// ===== 005186e0 clientSetHandleGenerator_IMPL =====

undefined8 clientSetHandleGenerator_IMPL(long param_1,int param_2,uint param_3)

{
  if (*(int *)(param_1 + 0xa0) == param_2) {
    if (param_3 < *(uint *)(param_1 + 0xb8)) {
      return 0x40;
    }
  }
  else if (*(uint *)(param_1 + 0xb8) != 0) {
    return 0x40;
  }
  if (param_2 != 0 || param_3 != 0) {
    if ((param_2 != 0) && (param_3 != 0)) {
      *(int *)(param_1 + 0xa0) = param_2;
      *(uint *)(param_1 + 0xa4) = param_3;
      return 0;
    }
    return 0x3b;
  }
  *(undefined8 *)(param_1 + 0xa0) = 0x80000caf00000;
  return 0;
}


// ===== 00518750 clientShareResource_IMPL =====

undefined8
clientShareResource_IMPL(undefined8 param_1,long param_2,long param_3,undefined8 *param_4)

{
  long lVar1;
  byte bVar2;
  undefined8 uVar3;
  
  bVar2 = *(byte *)(param_3 + 10);
  if ((bVar2 & 1) == 0) {
    uVar3 = clientCanShareResource_IMPL_part_0();
    if ((int)uVar3 != 0) {
      return uVar3;
    }
    bVar2 = *(byte *)(param_3 + 10);
  }
  lVar1 = param_2 + 0xe0;
  if (*(char *)(param_2 + 0x108) == '\0') {
    if ((bVar2 & 4) != 0) {
      uVar3 = 0;
      if (param_4 != (undefined8 *)0x0) {
        uVar3 = *param_4;
      }
      uVar3 = rsAccessGetActiveShareList(param_2,uVar3);
      uVar3 = rsShareListCopy(lVar1,uVar3);
      if ((int)uVar3 != 0) {
        return uVar3;
      }
    }
    *(undefined1 *)(param_2 + 0x108) = 1;
    bVar2 = *(byte *)(param_3 + 10);
  }
  if ((bVar2 & 4) == 0) {
    listDestroy_IMPL(lVar1);
    bVar2 = *(byte *)(param_3 + 10);
  }
  if ((bVar2 & 1) != 0) {
    rsShareListRemove();
    return 0;
  }
  uVar3 = rsShareListInsert(lVar1,param_3,0);
  return uVar3;
}


// ===== 00518840 clientShareResourceTargetClient_IMPL =====

undefined8
clientShareResourceTargetClient_IMPL
          (long param_1,undefined8 param_2,int *param_3,undefined8 param_4)

{
  uint uVar1;
  uint *puVar2;
  undefined8 uVar3;
  
  if ((short)param_3[2] != 3) {
    nvAssertFailedNoLog("pSharePolicy->type == RS_SHARE_TYPE_CLIENT",
                        "src/libraries/resserv/src/rs_client.c",0x107);
  }
  if (*param_3 != *(int *)(param_1 + 0x48)) {
    nvAssertFailedNoLog("pSharePolicy->target == pClient->hClient",
                        "src/libraries/resserv/src/rs_client.c",0x108);
  }
  if ((*(byte *)((long)param_3 + 10) & 1) == 0) {
    uVar3 = clientCanShareResource_IMPL_part_0(param_1,param_2,param_3,param_4);
    if ((int)uVar3 != 0) {
      return uVar3;
    }
  }
  puVar2 = (uint *)rsAccessLookup(param_2,param_1);
  uVar1 = *puVar2 | param_3[1];
  if ((*(byte *)((long)param_3 + 10) & 1) != 0) {
    uVar1 = ~param_3[1] & *puVar2;
  }
  *puVar2 = uVar1;
  return 0;
}


// ===== 00518940 clientSetRestrictedRange_IMPL =====

undefined8 clientSetRestrictedRange_IMPL(long param_1,uint param_2,int param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0x40;
  if (*(int *)(param_1 + 0xb8) == 0) {
    if (param_3 == 0) {
      uVar1 = 0x3b;
      if (param_2 == 0) {
        *(undefined8 *)(param_1 + 0xa8) = 1;
        *(undefined8 *)(param_1 + 0xb0) = 0;
        return 0;
      }
    }
    else {
      if (!CARRY4(param_3 - 1U,param_2)) {
        *(ulong *)(param_1 + 0xa8) = (ulong)param_2;
        *(ulong *)(param_1 + 0xb0) = (ulong)((param_3 - 1U) + param_2);
        return 0;
      }
      uVar1 = 0x3f;
    }
  }
  return uVar1;
}


// ===== 005189b0 clientDestruct_IMPL =====

void clientDestruct_IMPL(long param_1)

{
  int iVar1;
  long lVar2;
  
  iVar1 = mapCount_IMPL(param_1 + 0x58);
  if (iVar1 != 0) {
    nvAssertFailedNoLog("mapCount(&pClient->resourceMap) == 0",
                        "src/libraries/resserv/src/rs_client.c",0x142);
  }
  lVar2 = param_1 + 0x78;
  mapDestroy_IMPL(param_1 + 0x58);
  iVar1 = listCount_IMPL(lVar2);
  if (iVar1 == 0) {
    listDestroy_IMPL(lVar2);
    return;
  }
  nvAssertFailedNoLog("listCount(&pClient->accessBackRefList) == 0",
                      "src/libraries/resserv/src/rs_client.c",0x145);
  listDestroy_IMPL(lVar2);
  return;
}


// ===== 00518a40 clientGetResource_IMPL =====

undefined8 clientGetResource_IMPL(long param_1,undefined4 param_2,int param_3,undefined8 *param_4)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  lVar1 = mapFind_IMPL(param_1 + 0x58,param_2);
  if (lVar1 == 0) {
    uVar3 = 0x57;
    uVar2 = 0;
  }
  else if (*(int *)(lVar1 + 0x118) == param_3) {
    uVar2 = *(undefined8 *)(lVar1 + 8);
    uVar3 = 0;
  }
  else {
    uVar2 = 0;
    uVar3 = 0x22;
  }
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = uVar2;
  }
  return uVar3;
}


// ===== 00518aa0 clientGetResourceRef_IMPL =====

undefined8 clientGetResourceRef_IMPL(long param_1,undefined4 param_2,long *param_3)

{
  long lVar1;
  
  lVar1 = mapFind_IMPL(param_1 + 0x58,param_2);
  if (lVar1 != 0) {
    if (param_3 != (long *)0x0) {
      *param_3 = lVar1;
    }
    return 0;
  }
  return 0x57;
}


// ===== 00518ae0 clientGetResourceRefByType_IMPL =====

undefined8
clientGetResourceRefByType_IMPL(long param_1,undefined4 param_2,int param_3,long *param_4)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = mapFind_IMPL(param_1 + 0x58,param_2);
  if (lVar1 != 0) {
    uVar2 = 0x33;
    if (*(int *)(lVar1 + 0x118) == param_3) {
      if (param_4 != (long *)0x0) {
        *param_4 = lVar1;
      }
      uVar2 = 0;
    }
    return uVar2;
  }
  return 0x57;
}


// ===== 00518b30 clientValidate_IMPL =====

undefined8 clientValidate_IMPL(void)

{
  return 0;
}


// ===== 00518b40 clientValidateLocks_IMPL =====

undefined8 clientValidateLocks_IMPL(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(param_3 + 0x18);
  lVar2 = portThreadGetCurrentThreadId();
  uVar3 = 0x2f;
  if (lVar1 == lVar2) {
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 00518b70 clientGetCachedPrivilege_IMPL =====

undefined8 clientGetCachedPrivilege_IMPL(void)

{
  return 0;
}


// ===== 00518b80 clientIsAdmin_IMPL =====

undefined8 clientIsAdmin_IMPL(void)

{
  return 0;
}


// ===== 00518b90 clientUnmapMemory_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong clientUnmapMemory_IMPL
                (long param_1,long param_2,undefined8 param_3,long *param_4,undefined8 *param_5)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  ulong extraout_RDX;
  ulong uVar4;
  ulong extraout_RDX_00;
  ulong extraout_RDX_01;
  ulong uVar5;
  undefined4 uVar6;
  undefined8 local_b0;
  undefined1 local_a8 [8];
  long local_a0;
  long local_98;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  
  lVar1 = *param_4;
  local_b0 = 0;
  portMemSet(local_a8,0,0x70);
  if (param_5 != (undefined8 *)0x0) {
    local_80 = *param_5;
    local_78 = param_5[1];
    local_70 = param_5[2];
    local_68 = param_5[3];
  }
  local_a0 = param_1;
  local_98 = param_2;
  local_88 = param_3;
  uVar2 = resservSwapTlsCallContext(&local_b0,local_a8);
  uVar5 = (ulong)uVar2;
  if (uVar2 == 0) {
    uVar2 = (**(code **)(**(long **)(param_2 + 8) + 0x80))(*(long **)(param_2 + 8),local_a8,lVar1);
    uVar5 = (ulong)uVar2;
    iVar3 = resservRestoreTlsCallContext(local_b0);
    uVar4 = extraout_RDX;
    if (iVar3 != 0) {
      nvAssertOkFailedNoLog
                (iVar3,"resservRestoreTlsCallContext(pOldContext)",
                 "src/libraries/resserv/src/rs_client.c",0x387);
      uVar4 = extraout_RDX_01;
    }
    if (uVar2 != 0) {
      nvDbg_Printf("src/libraries/resserv/src/rs_client.c",0x38b,"clientUnmapMemory_IMPL",4,
                   "NVRM: hClient %x: Failed to unmap cpu mapping: hResource: %x error: 0x%x\n",
                   *(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_2 + 0x10));
      uVar4 = uVar5;
      if (lVar1 != 0) {
        uVar6 = 0;
        if (*(long *)(lVar1 + 0x20) != 0) {
          uVar6 = *(undefined4 *)(*(long *)(lVar1 + 0x20) + 0x10);
        }
        nvDbg_Printf("src/libraries/resserv/src/rs_client.c",0x392,"clientUnmapMemory_IMPL",4,
                     "NVRM: hContext: %x\n",uVar6);
        uVar4 = extraout_RDX_00;
      }
    }
    refRemoveMapping(param_2,lVar1,uVar4);
    *param_4 = 0;
  }
  else {
    nvAssertOkFailedNoLog
              (uVar2,"resservSwapTlsCallContext(&pOldContext, &callContext)",
               "src/libraries/resserv/src/rs_client.c",900);
  }
  return uVar5;
}


// ===== 00518d60 clientInterMap_IMPL =====

undefined8 clientInterMap_IMPL(void)

{
  return 0x23;
}


// ===== 00518d70 clientInterUnmap_IMPL =====

undefined8 clientInterUnmap_IMPL(void)

{
  return 0x23;
}


// ===== 00518d80 clientGenResourceHandle_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 clientGenResourceHandle_IMPL(long *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((int)param_1[0x14] == 0) {
    nvAssertFailedNoLog("pClient->handleRangeStart != 0","src/libraries/resserv/src/rs_client.c",
                        0x3bf);
  }
  uVar1 = *(uint *)((long)param_1 + 0xa4);
  if (uVar1 == 0) {
    nvAssertFailedNoLog("pClient->handleRangeSize != 0","src/libraries/resserv/src/rs_client.c",
                        0x3c0);
    uVar1 = *(uint *)((long)param_1 + 0xa4);
  }
  uVar2 = *(uint *)(param_1 + 0x17);
  *(uint *)(param_1 + 0x17) = uVar2 + 1;
  iVar4 = uVar2 % uVar1 + (int)param_1[0x14];
  iVar3 = (**(code **)(*param_1 + 0x78))(param_1,iVar4,0);
  if (iVar3 != 0) {
    do {
      uVar1 = *(uint *)(param_1 + 0x17);
      *(uint *)(param_1 + 0x17) = uVar1 + 1;
      iVar5 = uVar1 % *(uint *)((long)param_1 + 0xa4) + (int)param_1[0x14];
      iVar3 = (**(code **)(*param_1 + 0x78))(param_1,iVar5,0);
      if (iVar4 == iVar5) break;
    } while (iVar3 != 0);
    iVar4 = iVar5;
    if (iVar3 != 0) {
      return 0x1a;
    }
  }
  if (*(uint *)((long)param_1 + 0xa4) <= (uint)(iVar4 - (int)param_1[0x14])) {
    nvAssertFailedNoLog("hResource - pClient->handleRangeStart < pClient->handleRangeSize",
                        "src/libraries/resserv/src/rs_client.c",0x3d4);
  }
  *param_2 = iVar4;
  return 0;
}


// ===== 00518ed0 clientAssignResourceHandle_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

undefined8 clientAssignResourceHandle_IMPL(long *param_1,int *param_2)

{
  undefined8 uVar1;
  
  if (param_2 == (int *)0x0) {
    return 0x1f;
  }
  if (*param_2 != 0) {
    uVar1 = (**(code **)(*param_1 + 0x78))(param_1,*param_2,1,*(code **)(*param_1 + 0x78));
    return uVar1;
  }
  uVar1 = clientGenResourceHandle_IMPL();
  return uVar1;
}


// ===== 00518f10 clientDestructResourceRef_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
clientDestructResourceRef_IMPL
          (long param_1,long param_2,long param_3,undefined8 param_4,undefined8 param_5)

{
  long lVar1;
  long *plVar2;
  char cVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 local_b8 [4];
  long *local_98 [4];
  undefined8 local_78 [3];
  undefined8 local_60;
  long *local_50;
  undefined8 local_40;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pResourceRef != NULL","src/libraries/resserv/src/rs_client.c",0x430);
    iVar4 = listCount_IMPL(0x150);
  }
  else {
    iVar4 = listCount_IMPL(param_3 + 0x150);
  }
  if (iVar4 != 0) {
    nvAssertFailedNoLog("listCount(&pResourceRef->backRefs) == 0",
                        "src/libraries/resserv/src/rs_client.c",0x431);
  }
  iVar4 = listCount_IMPL(param_3 + 0x128);
  if (iVar4 != 0) {
    nvAssertFailedNoLog("listCount(&pResourceRef->cpuMappings) == 0",
                        "src/libraries/resserv/src/rs_client.c",0x432);
  }
  iVar4 = listCount_IMPL(param_3 + 0x188);
  if (iVar4 != 0) {
    nvAssertFailedNoLog("listCount(&pResourceRef->interBackRefsMappable) == 0",
                        "src/libraries/resserv/src/rs_client.c",0x433);
  }
  iVar4 = listCount_IMPL(param_3 + 0x1a0);
  if (iVar4 != 0) {
    nvAssertFailedNoLog("listCount(&pResourceRef->interBackRefsContext) == 0",
                        "src/libraries/resserv/src/rs_client.c",0x434);
  }
  iVar4 = mapCount_IMPL(param_3 + 0x168);
  if (iVar4 != 0) {
    nvAssertFailedNoLog("mapCount(&pResourceRef->interMappingContextMap) == 0",
                        "src/libraries/resserv/src/rs_client.c",0x435);
  }
  listDestroyIntrusive_IMPL(param_3 + 0x150);
  listDestroy_IMPL(param_3 + 0x128);
  listDestroyIntrusive_IMPL(param_3 + 0x188);
  listDestroyIntrusive_IMPL(param_3 + 0x1a0);
  mapDestroy_IMPL(param_3 + 0x168);
  listDestroy_IMPL(param_3 + 0xe0);
  lVar1 = param_3 + 0x20;
  if (*(int *)(param_3 + 0x44) != 0) {
    nvAssertFailedNoLog("0 == multimapCountItems(&pResourceRef->childRefMap)",
                        "src/libraries/resserv/src/rs_client.c",0x445);
    nvDbg_Printf("src/libraries/resserv/src/rs_client.c",0x448,"clientDestructResourceRef_IMPL",4,
                 "NVRM: Resource %x (Class %x) has unfreed children!\n",
                 *(undefined4 *)(param_3 + 0x10),*(undefined4 *)(param_3 + 0x11c));
    uVar6 = mapFindLEQ_IMPL(lVar1,0xffffffffffffffff);
    uVar7 = mapFindGEQ_IMPL(lVar1,0);
    mapIterRange_IMPL(local_b8,lVar1,uVar7,uVar6);
    while (cVar3 = mapIterNext_IMPL(local_b8), uVar6 = local_b8[0], cVar3 != '\0') {
      uVar7 = mapFindLEQ_IMPL(local_b8[0],0xffffffffffffffff);
      uVar6 = mapFindGEQ_IMPL(uVar6,0);
      multimapItemIterRange_IMPL(local_98,lVar1,uVar6,uVar7);
      while (cVar3 = multimapItemIterNext_IMPL(local_98), cVar3 != '\0') {
        plVar2 = (long *)*local_98[0];
        nvDbg_Printf("src/libraries/resserv/src/rs_client.c",0x453,"clientDestructResourceRef_IMPL",
                     4,"NVRM: Child %x (Class %x) is still alive!\n",(int)plVar2[2],
                     *(undefined4 *)((long)plVar2 + 0x11c));
        portMemSet(local_78,0,0x40);
        local_78[0] = CONCAT44((int)plVar2[2],*(undefined4 *)(*plVar2 + 0x48));
        local_60 = param_4;
        local_50 = plVar2;
        local_40 = param_5;
        iVar4 = (**(code **)(*(long *)*plVar2 + 0x50))((long *)*plVar2,param_2,local_78);
        if (iVar4 != 0) {
          nvAssertFailedNoLog("tmpStatus == NV_OK","src/libraries/resserv/src/rs_client.c",0x461,
                              0x5191ec);
        }
      }
    }
  }
  multimapDestroy_IMPL(lVar1);
  if (*(int *)(param_3 + 0x74) != 0) {
    nvAssertFailedNoLog("0 == multimapCountItems(&pResourceRef->cachedRefMap)",
                        "src/libraries/resserv/src/rs_client.c",0x468);
  }
  multimapDestroy_IMPL(param_3 + 0x50);
  while (puVar5 = (undefined8 *)multimapFirstItem_IMPL(param_3 + 0xb0), puVar5 != (undefined8 *)0x0)
  {
    refRemoveDependant(*puVar5,param_3);
  }
  multimapDestroy_IMPL(param_3 + 0xb0);
  while (puVar5 = (undefined8 *)multimapFirstItem_IMPL(param_3 + 0x80), puVar5 != (undefined8 *)0x0)
  {
    refRemoveDependant(param_3,*puVar5);
  }
  multimapDestroy_IMPL(param_3 + 0x80);
  mapRemove_IMPL(param_1 + 0x58,param_3);
  LOCK();
  *(long *)(param_2 + 0xb8) = *(long *)(param_2 + 0xb8) + -1;
  UNLOCK();
  return 0;
}


// ===== 00519390 clientUnmapResourceRefMappings =====

undefined8 clientUnmapResourceRefMappings(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  long lVar1;
  undefined4 uVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  undefined8 local_c0 [5];
  ulong local_98;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 local_60;
  undefined8 *local_48;
  undefined8 *local_40;
  
  lVar3 = param_2[2];
  lVar1 = lVar3 + 0x128;
  lVar5 = listHead_IMPL(lVar1);
  if (lVar5 != 0) {
    do {
      portMemSet(&local_80,0,0x48);
      portMemSet(local_c0,0,0x40);
      local_80 = *(undefined4 *)(param_1 + 0x48);
      local_7c = local_80;
      if (*(long *)(lVar5 + 0x20) != 0) {
        local_7c = *(undefined4 *)(*(long *)(lVar5 + 0x20) + 0x10);
      }
      local_78 = *(undefined4 *)(lVar3 + 0x10);
      local_70 = *(undefined8 *)(lVar5 + 0x18);
      local_60 = 1;
      local_64 = *(undefined4 *)(lVar5 + 0x48);
      local_68 = *(undefined4 *)(lVar5 + 0x10);
      local_c0[0] = *param_3;
      local_98 = param_3[5] | 2;
      local_48 = local_c0;
      local_40 = param_2 + 5;
      iVar4 = serverUnmap(*param_2,local_80,local_78,&local_80);
      if (iVar4 != 0) {
        uVar2 = *(undefined4 *)(lVar3 + 0x10);
        nvDbg_Printf("src/libraries/resserv/src/rs_client.c",0x4a2,"clientUnmapResourceRefMappings",
                     4,"NVRM: Failed to auto-unmap (status=0x%x) hClient %x: hResource: %x\n",iVar4,
                     *(undefined4 *)(param_1 + 0x48));
        nvDbg_Printf("src/libraries/resserv/src/rs_client.c",0x4a4,"clientUnmapResourceRefMappings",
                     4,"NVRM: hContext: %x at addr %p\n",local_7c);
        lVar6 = listHead_IMPL(lVar1);
        if (lVar6 == lVar5) {
          nvAssertFailedNoLog(&DAT_00dac9df,"src/libraries/resserv/src/rs_client.c",0x4aa,uVar2);
          refRemoveMapping(lVar3);
        }
      }
      lVar5 = listHead_IMPL(lVar1);
    } while (lVar5 != 0);
  }
  return 0;
}


// ===== 00519590 clientFreeResource_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint clientFreeResource_IMPL(long *param_1,undefined8 param_2,long param_3)

{
  long *plVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  long *plVar14;
  long *plVar15;
  ulong uVar16;
  undefined8 extraout_RDX;
  long lVar17;
  bool bVar18;
  ulong uVar19;
  undefined8 local_138;
  undefined8 local_130 [5];
  undefined4 local_104;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined8 local_e0;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined1 local_d0;
  undefined8 *local_b8;
  undefined8 *local_b0;
  undefined8 local_a8;
  long *local_a0;
  long local_98;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  
  local_138 = 0;
  lVar7 = mapFind_IMPL(param_1 + 0xb,*(undefined4 *)(param_3 + 4));
  if (lVar7 == 0) {
    return 0x57;
  }
  cVar4 = refPendingFree(lVar7,param_1);
  if (cVar4 != '\0') {
    listRemoveIntrusive_IMPL(param_1 + 0x18,lVar7);
  }
  uVar5 = 0;
  lVar8 = *(long *)(lVar7 + 0x18);
  if (*(char *)(lVar7 + 0x124) == '\0') {
    plVar1 = *(long **)(lVar7 + 8);
    portMemSet(&local_a8,0,0x70);
    local_88 = *(undefined8 *)(param_3 + 0x18);
    puVar2 = *(undefined8 **)(param_3 + 0x38);
    if (puVar2 != (undefined8 *)0x0) {
      local_80 = *puVar2;
      local_78 = puVar2[1];
      local_70 = puVar2[2];
      local_68 = puVar2[3];
    }
    local_a8 = param_2;
    local_a0 = param_1;
    local_98 = lVar7;
    uVar5 = resservSwapTlsCallContext(&local_138,&local_a8);
    if (uVar5 == 0) {
      resSetFreeParams_IMPL(plVar1,&local_a8,param_3);
      (**(code **)(*plVar1 + 0x40))(plVar1);
      clientUnmapResourceRefMappings(param_1,&local_a8,*(undefined8 *)(param_3 + 0x18));
      puVar2 = *(undefined8 **)(param_3 + 0x18);
      lVar9 = local_98 + 0x150;
      lVar10 = listHead_IMPL(lVar9);
      if (lVar10 != 0) {
        do {
          lVar11 = *(long *)(lVar10 + 0x28);
          portMemSet(&local_f0,0,0x48);
          portMemSet(local_130,0,0x40);
          local_f0 = (undefined4)param_1[9];
          local_ec = local_f0;
          if (*(long *)(lVar10 + 0x20) != 0) {
            local_ec = *(undefined4 *)(*(long *)(lVar10 + 0x20) + 0x10);
          }
          local_e8 = *(undefined4 *)(lVar11 + 0x10);
          local_e0 = *(undefined8 *)(lVar10 + 0x18);
          local_d0 = 1;
          local_d4 = *(undefined4 *)(lVar10 + 0x48);
          local_d8 = *(undefined4 *)(lVar10 + 0x10);
          local_b0 = &local_80;
          local_130[0] = *puVar2;
          local_104 = *(undefined4 *)((long)puVar2 + 0x2c);
          local_b8 = local_130;
          iVar6 = serverUnmap(local_a8,local_f0,*(undefined4 *)(lVar11 + 0x10),&local_f0);
          if (iVar6 != 0) {
            nvDbg_Printf("src/libraries/resserv/src/rs_client.c",0x4de,"_clientUnmapBackRefMappings"
                         ,4,
                         "NVRM: Failed to auto-unmap backref (status=0x%x) hClient %x: hResource: %x\n"
                         ,iVar6,(int)param_1[9],*(undefined4 *)(lVar11 + 0x10));
            nvDbg_Printf("src/libraries/resserv/src/rs_client.c",0x4e0,"_clientUnmapBackRefMappings"
                         ,4,"NVRM: hContext: %x at addr %p\n",local_ec,local_e0);
            lVar11 = listHead_IMPL(lVar9);
            if (lVar10 == lVar11) {
              nvAssertFailedNoLog(&DAT_00dac9df,"src/libraries/resserv/src/rs_client.c",0x4e5);
              listRemoveIntrusive_IMPL(lVar9);
            }
          }
          lVar10 = listHead_IMPL(lVar9);
        } while (lVar10 != 0);
      }
      lVar10 = local_98;
      uVar3 = *(undefined8 *)(param_3 + 0x18);
      lVar9 = local_98 + 0x168;
      lVar11 = mapFindGEQ_IMPL(lVar9,0);
      while (lVar17 = lVar11, lVar11 != 0) {
        while( true ) {
          lVar11 = mapNext_IMPL(lVar9,lVar17);
          lVar12 = mapFindGEQ_IMPL(lVar17,0);
          if (lVar12 == 0) break;
          do {
            while( true ) {
              lVar13 = mapNext_IMPL(lVar17,lVar12);
              iVar6 = _unmapInterMapping(local_a8,param_1,lVar10,lVar12,uVar3,&local_80);
              if (iVar6 == 0) break;
              nvDbg_Printf("src/libraries/resserv/src/rs_client.c",0x535,"_clientUnmapInterMappings"
                           ,4,"NVRM: Failed to auto-unmap (status=0x%x) hClient %x: hMapper: %x\n",
                           iVar6,(int)param_1[9],*(undefined4 *)(lVar10 + 0x10));
              nvDbg_Printf("src/libraries/resserv/src/rs_client.c",0x537,"_clientUnmapInterMappings"
                           ,4,"NVRM: hMappable: %x hContext: %x\n",
                           *(undefined4 *)(*(long *)(lVar12 + 8) + 0x10),
                           *(undefined4 *)(*(long *)(lVar12 + 0x10) + 0x10));
              lVar12 = lVar13;
              if (lVar13 == 0) goto LAB_00519a86;
            }
            lVar12 = lVar13;
          } while (lVar13 != 0);
LAB_00519a86:
          lVar17 = lVar11;
          if (lVar11 == 0) goto LAB_00519a96;
        }
      }
LAB_00519a96:
      lVar10 = local_98;
      uVar3 = *(undefined8 *)(param_3 + 0x18);
      lVar9 = local_98 + 0x188;
      plVar14 = (long *)listHead_IMPL(lVar9);
      bVar18 = plVar14 == (long *)0x0;
      if (bVar18) {
        plVar14 = (long *)listHead_IMPL(lVar10 + 0x1a0);
      }
LAB_00519ae0:
      if (plVar14 != (long *)0x0) {
LAB_00519ae9:
        do {
          lVar11 = *plVar14;
          iVar6 = _unmapInterMapping(local_a8,param_1,lVar11,plVar14,uVar3,&local_80);
          if (iVar6 == 0) {
LAB_00519d10:
            if (bVar18) {
              plVar14 = (long *)listHead_IMPL(lVar10 + 0x1a0);
              goto LAB_00519ae0;
            }
          }
          else {
            if (bVar18) {
              plVar15 = (long *)listHead_IMPL(lVar10 + 0x1a0);
              uVar16 = (ulong)*(uint *)(lVar11 + 0x10);
              nvDbg_Printf("src/libraries/resserv/src/rs_client.c",0x562,
                           "_clientUnmapInterBackRefMappings",4,
                           "NVRM: Failed to auto-unmap backref (status=0x%x) hClient %x: hMapper: %x\n"
                           ,iVar6,(int)param_1[9]);
              uVar19 = (ulong)*(uint *)(plVar14[2] + 0x10);
              nvDbg_Printf("src/libraries/resserv/src/rs_client.c",0x564,
                           "_clientUnmapInterBackRefMappings",4,"NVRM: hMappable: %x hContext: %x\n"
                           ,*(undefined4 *)(plVar14[1] + 0x10));
              if (plVar14 == plVar15) {
LAB_00519ce7:
                nvAssertFailedNoLog(&DAT_00dac9df,"src/libraries/resserv/src/rs_client.c",0x569);
                refRemoveInterMapping(lVar11,plVar14,0);
                goto LAB_00519d10;
              }
              plVar14 = (long *)listHead_IMPL(lVar10 + 0x1a0,uVar16,extraout_RDX,uVar19);
              if (plVar14 == (long *)0x0) goto LAB_00519bd6;
              goto LAB_00519ae9;
            }
            plVar15 = (long *)listHead_IMPL(lVar9);
            nvDbg_Printf("src/libraries/resserv/src/rs_client.c",0x562,
                         "_clientUnmapInterBackRefMappings",4,
                         "NVRM: Failed to auto-unmap backref (status=0x%x) hClient %x: hMapper: %x\n"
                         ,iVar6,(int)param_1[9]);
            nvDbg_Printf("src/libraries/resserv/src/rs_client.c",0x564,
                         "_clientUnmapInterBackRefMappings",4,"NVRM: hMappable: %x hContext: %x\n",
                         *(undefined4 *)(plVar14[1] + 0x10),*(undefined4 *)(plVar14[2] + 0x10));
            if (plVar14 == plVar15) goto LAB_00519ce7;
          }
          plVar14 = (long *)listHead_IMPL(lVar9);
        } while (plVar14 != (long *)0x0);
        plVar14 = (long *)listHead_IMPL(lVar10 + 0x1a0);
        bVar18 = true;
        goto LAB_00519ae0;
      }
LAB_00519bd6:
      *(undefined1 *)(lVar7 + 0x124) = 1;
      _refRemoveAllDependencies(lVar7);
      uVar5 = serverFreeResourceRpcUnderLock(param_2,param_3);
      if ((uVar5 & 0xffffffef) != 0) {
        nvAssertFailedNoLog("(status == NV_OK) || (status == NV_ERR_GPU_IN_FULLCHIP_RESET)",
                            "src/libraries/resserv/src/rs_client.c",0x34c);
      }
      __nvoc_objDelete(plVar1);
      *(undefined8 *)(lVar7 + 8) = 0;
      iVar6 = resservRestoreTlsCallContext(local_138);
      if (iVar6 == 0) {
        cVar4 = *(char *)(param_3 + 8);
        goto joined_r0x00519c52;
      }
      nvAssertOkFailedNoLog
                (iVar6,"resservRestoreTlsCallContext(pOldContext)",
                 "src/libraries/resserv/src/rs_client.c",0x355);
    }
    else {
      nvAssertOkFailedNoLog
                (uVar5,"resservSwapTlsCallContext(&pOldContext, &callContext)",
                 "src/libraries/resserv/src/rs_client.c",0x338);
    }
  }
  cVar4 = *(char *)(param_3 + 8);
joined_r0x00519c52:
  if (cVar4 == '\0') {
    if (lVar8 != 0) {
      multimapRemoveItemByKey_IMPL
                (lVar8 + 0x20,*(undefined4 *)(lVar7 + 0x118),*(undefined4 *)(lVar7 + 0x10));
    }
    lVar8 = mapFind_IMPL(param_1 + 0xb,(int)param_1[9]);
    if (lVar8 != 0) {
      refUncacheRef(lVar8,lVar7);
    }
    iVar6 = (**(code **)(*param_1 + 0x58))
                      (param_1,param_2,lVar7,*(undefined8 *)(param_3 + 0x18),
                       *(undefined8 *)(param_3 + 0x38));
    if (iVar6 != 0) {
      nvAssertFailedNoLog("tmpStatus == NV_OK","src/libraries/resserv/src/rs_client.c",0x366);
    }
  }
  return uVar5;
}


// ===== 00519e40 indexAdd =====

byte indexAdd(undefined8 param_1,undefined4 param_2,long param_3)

{
  long lVar1;
  long local_20;
  
  local_20 = param_3;
  if ((param_3 == 0) || (*(int *)(param_3 + 0x10) == 0)) {
    nvAssertFailedNoLog("pResourceRef != NULL && pResourceRef->hResource != 0",
                        "src/libraries/resserv/src/rs_client.c",0x581);
  }
  lVar1 = multimapFindSubmap_IMPL(param_1,param_2);
  if ((lVar1 == 0) && (lVar1 = multimapInsertSubmap_IMPL(param_1,param_2), lVar1 == 0)) {
    return 0x1a;
  }
  lVar1 = multimapInsertItemValue_IMPL(param_1,param_2,*(undefined4 *)(local_20 + 0x10),&local_20);
  return -(lVar1 == 0) & 0x1a;
}


// ===== 00519ee0 indexRemove =====

undefined8 indexRemove(undefined8 param_1,undefined4 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  
  if ((param_3 == 0) || (iVar1 = *(int *)(param_3 + 0x10), iVar1 == 0)) {
    nvAssertFailedNoLog("pResourceRef != NULL && pResourceRef->hResource != 0",
                        "src/libraries/resserv/src/rs_client.c",0x59a);
    iVar1 = *(int *)(param_3 + 0x10);
  }
  lVar2 = multimapFindItem_IMPL(param_1,param_2,iVar1);
  if (lVar2 != 0) {
    multimapRemoveItem_IMPL(param_1,lVar2);
    return 0;
  }
  return 0x57;
}


// ===== 00519f70 _clientAllocResourceHelper =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _clientAllocResourceHelper(long *param_1,long param_2,long param_3,undefined4 *param_4)

{
  long *plVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  long lVar9;
  undefined8 *puVar10;
  undefined8 uVar11;
  undefined8 *local_118;
  long local_f8;
  undefined8 local_f0;
  undefined1 local_e8 [64];
  long local_a8;
  long *local_a0;
  undefined8 *local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  
  uVar2 = *param_4;
  iVar6 = *(int *)(param_3 + 4);
  plVar1 = param_1 + 0xb;
  local_f8 = 0;
  local_f0 = 0;
  lVar9 = mapFind_IMPL(plVar1);
  if (((lVar9 == 0) && ((int)param_1[9] != iVar6)) && (iVar6 != 0)) {
    return 0x57;
  }
  uVar5 = *(undefined4 *)(param_3 + 0xc);
  uVar3 = *(undefined8 *)(param_2 + 0x18);
  puVar10 = (undefined8 *)mapInsertNew_IMPL(plVar1,uVar2);
  if (puVar10 == (undefined8 *)0x0) {
    if (local_f8 == 0) {
      return 0x1a;
    }
LAB_0051a549:
    iVar6 = 0x1a;
LAB_0051a352:
    local_118 = &local_f0;
    local_f0 = 0;
    _refRemoveAllDependencies(puVar10);
    portMemSet(local_e8,0,0x40);
    portMemSet(&local_a8,0,0x70);
    puVar4 = *(undefined8 **)(param_3 + 0x38);
    local_80 = *puVar4;
    local_78 = puVar4[1];
    local_70 = puVar4[2];
    local_68 = puVar4[3];
    local_88 = *(undefined8 *)(param_3 + 0x18);
    local_a8 = param_2;
    local_a0 = param_1;
    local_98 = puVar10;
    iVar7 = resservSwapTlsCallContext(local_118,&local_a8);
    if (iVar7 == 0) {
      resSetFreeParams_IMPL(local_f8,&local_a8,local_e8);
      __nvoc_objDelete(local_f8);
      iVar7 = resservRestoreTlsCallContext(local_f0);
      if (iVar7 != 0) {
        nvAssertOkFailedNoLog
                  (iVar7,"resservRestoreTlsCallContext(pOldContext)",
                   "src/libraries/resserv/src/rs_client.c",0x2f9);
      }
    }
    else {
      nvDbg_Printf("src/libraries/resserv/src/rs_client.c",0x2fd,"_clientAllocResourceHelper",4,
                   "NVRM: Failed to set call context! Error: 0x%x\n",iVar7);
    }
    if (puVar10 == (undefined8 *)0x0) {
      return iVar6;
    }
LAB_0051a250:
    if (lVar9 == 0) goto LAB_0051a26e;
  }
  else {
    if ((*(char *)((long)param_1 + 0x51) == '\0') && (uVar8 = mapCount_IMPL(plVar1), 99999 < uVar8))
    {
      nvDbg_Printf("src/libraries/resserv/src/rs_client.c",0x406,"_clientConstructResourceRef",3,
                   "NVRM: Client 0x%08x has allocated a large number of resources. [Current classid: 0x%04x]\n"
                   ,(int)param_1[9],uVar5);
      nvDbg_Printf("src/libraries/resserv/src/rs_client.c",0x407,"_clientConstructResourceRef",3,
                   "NVRM: The client may be leaking resources. This warning can be ignored if the allocations were intentional.\n"
                  );
      *(undefined1 *)((long)param_1 + 0x51) = 1;
    }
    *puVar10 = param_1;
    uVar11 = RsResInfoByExternalClassId(uVar5);
    *(undefined4 *)((long)puVar10 + 0x11c) = uVar5;
    puVar10[0x22] = uVar11;
    uVar5 = RsResInfoGetInternalClassId(uVar11);
    puVar10[0x3b] = uVar3;
    *(undefined4 *)(puVar10 + 0x23) = uVar5;
    puVar10[1] = 0;
    puVar10[3] = lVar9;
    *(undefined4 *)(puVar10 + 0x24) = 0;
    *(undefined4 *)(puVar10 + 2) = uVar2;
    multimapInit_IMPL(puVar10 + 4,uVar3,8,8,0x10);
    multimapInit_IMPL(puVar10 + 10,uVar3,8,8,0x10);
    multimapInit_IMPL(puVar10 + 0x10,uVar3,8,8,0x10);
    multimapInit_IMPL(puVar10 + 0x16,uVar3,8,8,0x10);
    listInit_IMPL(puVar10 + 0x25,uVar3,0x58);
    listInitIntrusive_IMPL(puVar10 + 0x2a,0x30);
    mapInit_IMPL(puVar10 + 0x2d,uVar3,0x10);
    listInitIntrusive_IMPL(puVar10 + 0x34,0x28);
    listInitIntrusive_IMPL(puVar10 + 0x31,0x18);
    listInit_IMPL(puVar10 + 0x1c,uVar3,0xc);
    LOCK();
    *(long *)(param_2 + 0xb8) = *(long *)(param_2 + 0xb8) + 1;
    UNLOCK();
    portMemSet(&local_a8,0,0x70);
    local_90 = *(undefined8 *)(param_3 + 0x58);
    local_88 = *(undefined8 *)(param_3 + 0x18);
    puVar4 = *(undefined8 **)(param_3 + 0x38);
    if (puVar4 == (undefined8 *)0x0) {
      iVar6 = 0x1f;
      local_98 = puVar10;
      local_a0 = param_1;
      local_a8 = param_2;
joined_r0x0051a33e:
      if (local_f8 != 0) goto LAB_0051a352;
      goto LAB_0051a250;
    }
    local_80 = *puVar4;
    local_78 = puVar4[1];
    local_70 = puVar4[2];
    local_68 = puVar4[3];
    local_a8 = param_2;
    local_a0 = param_1;
    local_98 = puVar10;
    iVar6 = resservSwapTlsCallContext(&local_f0,&local_a8);
    if (iVar6 != 0) {
      nvAssertOkFailedNoLog
                (iVar6,"resservSwapTlsCallContext(&pOldContext, &callContext)",
                 "src/libraries/resserv/src/rs_client.c",0x2a9);
      goto joined_r0x0051a33e;
    }
    iVar6 = resservResourceFactory(*(undefined8 *)(param_2 + 0x18),&local_a8,param_3,&local_f8);
    iVar7 = resservRestoreTlsCallContext(local_f0);
    if (iVar7 != 0) {
      nvAssertOkFailedNoLog
                (iVar7,"resservRestoreTlsCallContext(pOldContext)",
                 "src/libraries/resserv/src/rs_client.c",0x2ad);
    }
    if (iVar6 != 0) goto joined_r0x0051a33e;
    resSetFreeParams_IMPL(local_f8,0,0);
    *(undefined8 **)(param_3 + 0x28) = puVar10;
    puVar10[1] = local_f8;
    *(undefined8 **)(local_f8 + 0x48) = puVar10;
    if (lVar9 == 0) {
LAB_0051a4a6:
      if ((*(char *)(param_2 + 0x43) == '\0') ||
         (iVar6 = rsAccessGrantRights(puVar10,&local_a8,param_1,*(undefined8 *)(param_3 + 0x60),
                                      *(undefined8 *)(param_3 + 0x70),
                                      *(undefined8 *)(param_3 + 0x40)), iVar6 == 0)) {
        *param_4 = uVar2;
        return 0;
      }
      goto joined_r0x0051a33e;
    }
    uVar8 = *(int *)(lVar9 + 0x120) + 1;
    *(uint *)(puVar10 + 0x24) = uVar8;
    if (6 < uVar8) {
      iVar6 = 0x16;
      goto LAB_0051a352;
    }
    iVar6 = indexAdd(lVar9 + 0x20,*(undefined4 *)(puVar10 + 0x23),puVar10);
    if (iVar6 == 0) goto LAB_0051a4a6;
    iVar6 = 0x1a;
    if (local_f8 != 0) goto LAB_0051a549;
  }
  indexRemove(lVar9 + 0x20,*(undefined4 *)(puVar10 + 0x23),puVar10);
LAB_0051a26e:
  (**(code **)(*param_1 + 0x58))
            (param_1,param_2,puVar10,*(undefined8 *)(param_3 + 0x18),*(undefined8 *)(param_3 + 0x38)
            );
  return iVar6;
}


// ===== 0051a630 clientAllocResource_IMPL =====

void clientAllocResource_IMPL(void)

{
  _clientAllocResourceHelper();
  return;
}


// ===== 0051a640 clientCopyResource_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int clientCopyResource_IMPL(long param_1,long param_2,long param_3)

{
  long lVar1;
  undefined8 *puVar2;
  long *plVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 local_128;
  long local_120;
  long local_118;
  undefined8 local_110;
  long local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  ulong local_b0;
  undefined8 local_a8;
  undefined8 local_98;
  long local_90;
  undefined4 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_60;
  long local_58;
  
  local_128 = 0;
  lVar7 = mapFind_IMPL(param_1 + 0x58,*(undefined4 *)(param_3 + 0xc));
  if (lVar7 == 0) {
    iVar5 = 0x57;
  }
  else {
    portMemSet(&local_120,0,0x70);
    local_110 = *(undefined8 *)(param_3 + 0x38);
    puVar2 = *(undefined8 **)(param_3 + 0x48);
    local_f8 = *puVar2;
    local_f0 = puVar2[1];
    local_e8 = puVar2[2];
    local_e0 = puVar2[3];
    local_100 = *(undefined8 *)(param_3 + 0x50);
    local_120 = param_2;
    local_118 = param_1;
    local_108 = lVar7;
    iVar5 = resservSwapTlsCallContext(&local_128,&local_120);
    if (iVar5 == 0) {
      if (((**(uint **)(param_3 + 0x48) < 2) || ((*(byte *)(param_3 + 0x20) & 1) != 0)) &&
         ((*(char *)(param_2 + 0x43) != '\0' ||
          (*(int *)(*(long *)(param_3 + 0x28) + 0x48) != *(int *)(param_1 + 0x48))))) {
        portMemSet(&local_b0,0,4);
        local_b0 = local_b0 | 1;
        iVar5 = rsAccessCheckRights(*(undefined8 *)(param_3 + 0x38),param_1,&local_b0);
      }
      else {
        lVar1 = param_2 + 0x80;
        uVar8 = listTail_IMPL(lVar1);
        uVar9 = listHead_IMPL(lVar1);
        listIterRange_IMPL(&local_b0,lVar1,uVar9,uVar8);
        do {
          cVar4 = listIterNext_IMPL(&local_b0);
          if (cVar4 == '\0') goto LAB_0051a82d;
        } while ((((*(byte *)(local_b0 + 10) & 2) == 0) || ((*(byte *)(local_b0 + 4) & 1) == 0)) ||
                (plVar3 = *(long **)(*(long *)(param_3 + 0x38) + 8),
                cVar4 = (**(code **)(*plVar3 + 0xb0))(plVar3,param_1,lVar7), cVar4 != '\0'));
        iVar5 = 0x3f;
      }
LAB_0051a82d:
      iVar6 = resservRestoreTlsCallContext(local_128);
      if (iVar6 != 0) {
        nvAssertOkFailedNoLog
                  (iVar6,"resservRestoreTlsCallContext(pOldContext)",
                   "src/libraries/resserv/src/rs_client.c",0x23c);
      }
      if (iVar5 == 0) {
        portMemSet(&local_b0,0,0x78);
        local_58 = *(long *)(param_3 + 0x38);
        local_a8 = CONCAT44(*(undefined4 *)(local_58 + 0x11c),*(undefined4 *)(param_3 + 0x10));
        local_78 = *(undefined8 *)(param_3 + 0x48);
        local_b0 = CONCAT44(*(undefined4 *)(param_3 + 0xc),*(undefined4 *)(param_1 + 0x48));
        local_60 = *(undefined8 *)(param_3 + 0x28);
        local_70 = *(undefined8 *)(param_3 + 0x18);
        local_98 = *(undefined8 *)(param_3 + 0x50);
        local_80 = *(undefined4 *)(param_3 + 0x20);
        local_90 = param_1;
        iVar5 = _clientAllocResourceHelper(param_1,param_2,&local_b0,param_3 + 0x10);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar5,"resservSwapTlsCallContext(&pOldContext, &callContext)",
                 "src/libraries/resserv/src/rs_client.c",0x217);
    }
  }
  return iVar5;
}


// ===== 0051a950 clientValidateNewResourceHandle_IMPL =====

byte clientValidateNewResourceHandle_IMPL(long param_1,uint param_2,char param_3)

{
  ulong uVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  
  if ((*(uint *)(param_1 + 0x48) == param_2) || (param_2 == 0)) {
    return 0x33;
  }
  uVar4 = (ulong)param_2;
  if (param_3 != '\0') {
    uVar1 = *(ulong *)(param_1 + 0xb0);
    uVar3 = uVar4;
    if (uVar1 <= uVar4) {
      uVar3 = uVar1;
    }
    if ((*(ulong *)(param_1 + 0xa8) <= uVar3) && (uVar4 <= uVar1)) {
      return 0x33;
    }
  }
  lVar2 = mapFind_IMPL(param_1 + 0x58);
  return -(lVar2 != 0) & 0x19;
}


// ===== 0051a9b0 clientresConstruct_IMPL =====

undefined8 clientresConstruct_IMPL(long param_1,long param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0x33;
  if (*(int *)(*(long *)(param_2 + 8) + 0x48) == *(int *)(*(long *)(param_2 + 0x10) + 0x10)) {
    *(long *)(param_1 + 0x88) = *(long *)(param_2 + 8);
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 0051a9e0 clientresDestruct_IMPL =====

void clientresDestruct_IMPL(void)

{
  return;
}


// ===== 0051a9f0 indexRefIter =====

undefined8 * indexRefIter(undefined8 *param_1,long param_2,undefined4 param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  portMemSet(&local_48,0,0x20);
  if (param_2 == 0) {
    nvAssertFailedNoLog("pIndex","src/libraries/resserv/src/rs_client.c",0x5e7);
  }
  lVar1 = multimapFindSubmap_IMPL(param_2,param_3);
  if (lVar1 != 0) {
    uVar2 = mapFindLEQ_IMPL(lVar1,0xffffffffffffffff);
    uVar3 = mapFindGEQ_IMPL(lVar1,0);
    multimapItemIterRange_IMPL(&local_68,param_2,uVar3,uVar2);
    local_48 = local_68;
    local_40 = local_60;
    local_38 = local_58;
    local_30 = local_50;
  }
  *param_1 = local_48;
  param_1[1] = local_40;
  param_1[2] = local_38;
  param_1[3] = local_30;
  return param_1;
}


// ===== 0051aaf0 indexRefIterAll =====

undefined8 indexRefIterAll(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("pIndex","src/libraries/resserv/src/rs_client.c",0x5f6);
  }
  uVar1 = multimapLastItem_IMPL(param_2);
  uVar2 = multimapFirstItem_IMPL(param_2);
  multimapItemIterRange_IMPL(param_1,param_2,uVar2,uVar1);
  return param_1;
}


// ===== 0051ab60 indexRefIterNext =====

void indexRefIterNext(void)

{
  multimapItemIterNext_IMPL();
  return;
}


// ===== 0051ab70 clientRefIter =====

undefined8 *
clientRefIter(undefined8 *param_1,long param_2,long param_3,int param_4,uint param_5,char param_6)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  long local_60;
  long local_58;
  int local_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  undefined1 local_40;
  char cStack_3f;
  undefined6 uStack_3e;
  
  portMemSet(&local_80,0,0x48);
  if (param_2 == 0) {
    nvAssertFailedNoLog(&DAT_00dac9df,"src/libraries/resserv/src/rs_client.c",0x616);
    goto LAB_0051ad52;
  }
  if ((param_3 == 0) &&
     (param_3 = mapFind_IMPL(param_2 + 0x58,*(undefined4 *)(param_2 + 0x48)), param_3 == 0))
  goto LAB_0051ad52;
  if ((param_5 == 3) || ((param_5 & 0xfffffffd) == 0)) {
    if (param_5 == 0) {
      lVar1 = param_3 + 0x20;
    }
    else if ((param_5 & 0xfffffffd) == 0) {
      lVar1 = param_3 + 0x50;
    }
    else {
      lVar1 = param_3 + 0x80;
    }
    if (param_4 != 0 && param_6 != '\0') {
      lVar2 = multimapFindSubmap_IMPL(lVar1,param_4);
      if (lVar2 == 0) goto LAB_0051ad52;
      indexRefIter(&local_c8,lVar1,param_4);
      goto LAB_0051ad0c;
    }
    uVar3 = multimapLastItem_IMPL(lVar1);
    uVar4 = multimapFirstItem_IMPL(lVar1);
    multimapItemIterRange_IMPL(&local_a0,lVar1,uVar4,uVar3);
    local_80 = local_a0;
    local_78 = local_98;
    local_70 = local_90;
    local_68 = local_88;
  }
  else {
    lVar1 = param_2 + 0x58;
    uVar3 = mapFindLEQ_IMPL(lVar1,0xffffffffffffffff);
    uVar4 = mapFindGEQ_IMPL(lVar1,0);
    mapIterRange_IMPL(&local_c8,lVar1,uVar4,uVar3);
LAB_0051ad0c:
    local_80 = local_c8;
    local_78 = local_c0;
    local_70 = local_b8;
    local_68 = local_b0;
  }
  local_40 = (undefined1)param_5;
  local_60 = param_2;
  local_58 = param_3;
  local_50 = param_4;
  cStack_3f = param_6;
LAB_0051ad52:
  *param_1 = local_80;
  param_1[1] = local_78;
  param_1[2] = local_70;
  param_1[3] = local_68;
  param_1[4] = local_60;
  param_1[5] = local_58;
  param_1[6] = CONCAT44(uStack_4c,local_50);
  param_1[7] = local_48;
  param_1[8] = CONCAT62(uStack_3e,CONCAT11(cStack_3f,local_40));
  return param_1;
}


// ===== 0051ae10 clientRefOrderedIter =====

void clientRefOrderedIter
               (undefined8 param_1,long param_2,long param_3,undefined4 param_4,undefined1 param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined1 local_140 [8];
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  long local_58;
  long local_50;
  undefined4 local_48;
  undefined1 local_44;
  
  portMemSet(local_140,0,0x108);
  if (param_2 == 0) {
    nvAssertFailedNoLog(&DAT_00dac9df,"src/libraries/resserv/src/rs_client.c",0x657);
  }
  else if ((param_3 != 0) ||
          (param_3 = mapFind_IMPL(param_2 + 0x58,*(undefined4 *)(param_2 + 0x48)), param_3 != 0)) {
    local_140[0] = 0xff;
    uVar1 = multimapLastItem_IMPL(param_3 + 0x20);
    uVar2 = multimapFirstItem_IMPL(param_3 + 0x20);
    multimapItemIterRange_IMPL(&local_160,param_3 + 0x20,uVar2,uVar1);
    local_138 = local_160;
    local_130 = local_158;
    local_128 = local_150;
    local_120 = local_148;
    local_58 = param_2;
    local_50 = param_3;
    local_48 = param_4;
    local_44 = param_5;
  }
  memcpy(param_1,local_140,0x108);
  return;
}


// ===== 0051af60 clientRefOrderedIterNext =====

undefined8 clientRefOrderedIterNext(long param_1,char *param_2)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  if (param_2 != (char *)0x0) {
    lVar1 = *(long *)(param_2 + 0xe8);
    if ((lVar1 == param_1) && (lVar4 = *(long *)(param_2 + 0xf0), lVar4 != 0)) {
      cVar2 = *param_2;
      if (cVar2 == -1) {
        *param_2 = '\0';
        if ((*(int *)(lVar4 + 0x10) != *(int *)(lVar1 + 0x48)) &&
           (((*(int *)(param_2 + 0xf8) == 0 || (*(int *)(param_2 + 0xf8) == *(int *)(lVar4 + 0x118))
             ) && (*(long *)(lVar4 + 8) != 0)))) {
          *(long *)(param_2 + 0x100) = lVar4;
          return 1;
        }
        cVar2 = '\0';
      }
      param_2[0x100] = '\0';
      param_2[0x101] = '\0';
      param_2[0x102] = '\0';
      param_2[0x103] = '\0';
      param_2[0x104] = '\0';
      param_2[0x105] = '\0';
      param_2[0x106] = '\0';
      param_2[0x107] = '\0';
      do {
        while( true ) {
          uVar3 = multimapItemIterNext_IMPL(param_2 + (long)cVar2 * 0x20 + 8);
          cVar2 = *param_2;
          if ((char)uVar3 != '\0') break;
          if (cVar2 == '\0') {
            return uVar3;
          }
          cVar2 = cVar2 + -1;
          *param_2 = cVar2;
        }
        lVar1 = **(long **)(param_2 + (long)cVar2 * 0x20 + 8);
        if (cVar2 < '\x06') {
          *param_2 = cVar2 + '\x01';
          lVar4 = (long)(char)(cVar2 + '\x01') * 0x20;
          uVar3 = multimapLastItem_IMPL(lVar1 + 0x20);
          uVar5 = multimapFirstItem_IMPL(lVar1 + 0x20);
          multimapItemIterRange_IMPL(&local_58,lVar1 + 0x20,uVar5,uVar3);
          *(undefined8 *)(param_2 + lVar4 + 8) = local_58;
          *(undefined8 *)(param_2 + lVar4 + 0x10) = local_50;
          *(undefined8 *)(param_2 + lVar4 + 0x18) = local_48;
          *(undefined8 *)(param_2 + lVar4 + 0x20) = local_40;
        }
        cVar2 = refHasAncestor(lVar1,*(undefined8 *)(param_2 + 0xf0));
        if (cVar2 == '\0') goto LAB_0051b050;
        if (*(int *)(param_2 + 0xf8) == 0) {
LAB_0051b06f:
          if (*(long *)(lVar1 + 8) != 0) {
            *(long *)(param_2 + 0x100) = lVar1;
            return 1;
          }
        }
        else if (param_2[0xfc] == '\0') {
          lVar4 = objDynamicCastById_IMPL(*(undefined8 *)(lVar1 + 8));
          if (lVar4 != 0) goto LAB_0051b06f;
        }
        else if (*(int *)(param_2 + 0xf8) == *(int *)(lVar1 + 0x118)) goto LAB_0051b06f;
LAB_0051b050:
        cVar2 = *param_2;
      } while( true );
    }
    if (lVar1 == 0) {
      return 0;
    }
  }
  nvAssertFailedNoLog("pIt != NULL && pIt->pClient == NULL","src/libraries/resserv/src/rs_client.c",
                      0x67a);
  return 0;
}


// ===== 0051b190 clientRefIterNext =====

undefined8 clientRefIterNext(long param_1,undefined8 *param_2)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 *puVar6;
  
  if (param_2 != (undefined8 *)0x0) {
    if ((param_2[4] == param_1) && (param_2[5] != 0)) {
      param_2[7] = 0;
      if (((*(byte *)(param_2 + 8) & 0xfd) == 0) || (*(byte *)(param_2 + 8) == 3)) {
        uVar4 = multimapItemIterNext_IMPL();
        bVar2 = true;
      }
      else {
        uVar4 = mapIterNext_IMPL(param_2);
        bVar2 = false;
      }
      if ((char)uVar4 == '\0') {
        return uVar4;
      }
      puVar6 = (undefined8 *)*param_2;
      if (!bVar2) goto LAB_0051b299;
      iVar1 = *(int *)(param_2 + 6);
      puVar6 = (undefined8 *)*puVar6;
      if (iVar1 == 0) goto LAB_0051b24e;
LAB_0051b220:
      if (*(char *)((long)param_2 + 0x41) == '\0') goto LAB_0051b270;
      if (*(int *)(puVar6 + 0x23) == iVar1) {
LAB_0051b27e:
        do {
          if (puVar6[1] != 0) goto LAB_0051b255;
          do {
            if (bVar2) goto LAB_0051b230;
            while( true ) {
              while( true ) {
                do {
                  uVar4 = mapIterNext_IMPL(param_2);
                  if ((char)uVar4 == '\0') {
                    return uVar4;
                  }
                  puVar6 = (undefined8 *)*param_2;
LAB_0051b299:
                } while (((undefined8 *)param_2[5] != puVar6) &&
                        (cVar3 = refHasAncestor(puVar6), cVar3 == '\0'));
                if (*(int *)(param_2 + 6) != 0) break;
                if (puVar6[1] != 0) goto LAB_0051b255;
              }
              if (*(char *)((long)param_2 + 0x41) == '\0') break;
              if (*(int *)(puVar6 + 0x23) == *(int *)(param_2 + 6)) goto LAB_0051b27e;
            }
LAB_0051b270:
            lVar5 = objDynamicCastById_IMPL(puVar6[1]);
          } while (lVar5 == 0);
        } while( true );
      }
LAB_0051b230:
      do {
        uVar4 = multimapItemIterNext_IMPL(param_2);
        if ((char)uVar4 == '\0') {
          return uVar4;
        }
        iVar1 = *(int *)(param_2 + 6);
        puVar6 = *(undefined8 **)*param_2;
        if (iVar1 != 0) goto LAB_0051b220;
LAB_0051b24e:
        if (puVar6[1] != 0) {
LAB_0051b255:
          param_2[7] = puVar6;
          return 1;
        }
      } while( true );
    }
    if (param_2[4] == 0) {
      return 0;
    }
  }
  nvAssertFailedNoLog("pIt != NULL && pIt->pClient == NULL","src/libraries/resserv/src/rs_client.c",
                      0x6c9);
  return 0;
}


// ===== 0051b330 clientPostProcessPendingFreeList_IMPL =====

undefined8 clientPostProcessPendingFreeList_IMPL(undefined8 param_1,undefined8 *param_2)

{
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  return 0;
}


// ===== 0051b350 clientAddAccessBackRef_IMPL =====

undefined8 clientAddAccessBackRef_IMPL(long param_1,long *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)listPrependNew_IMPL(param_1 + 0x78);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *(undefined4 *)(*param_2 + 0x48);
    puVar1[1] = (int)param_2[2];
    return 0;
  }
  return 0x1a;
}


// ===== 0051b3a0 clientFreeAccessBackRefs_IMPL =====

void clientFreeAccessBackRefs_IMPL(long param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  long lVar3;
  long local_50;
  undefined4 local_44;
  undefined1 local_40 [4];
  undefined2 local_3c;
  undefined1 local_3a;
  
  while( true ) {
    puVar2 = (undefined4 *)listHead_IMPL(param_1 + 0x78);
    if (puVar2 == (undefined4 *)0x0) break;
    iVar1 = serverGetClientUnderLock(param_2,*puVar2,&local_50);
    if (iVar1 == 0) {
      lVar3 = mapFind_IMPL(local_50 + 0x58,puVar2[1]);
      if (lVar3 != 0) {
        local_3c = 3;
        local_44 = *(undefined4 *)(param_1 + 0x48);
        local_3a = 1;
        portMemSet(local_40,0xff,4);
        rsShareListRemove(lVar3 + 0xe0,&local_44,0);
      }
    }
    listRemove_IMPL(param_1 + 0x78,puVar2);
  }
  return;
}


// ===== 0051b470 resConstruct_IMPL =====

undefined8 resConstruct_IMPL(long param_1,long param_2)

{
  long lVar1;
  
  if (param_2 != 0) {
    lVar1 = *(long *)(param_2 + 0x10);
    *(undefined1 *)(param_1 + 0x60) = 1;
    *(long *)(lVar1 + 8) = param_1;
    *(long *)(param_1 + 0x48) = lVar1;
    if (*(char *)(param_1 + 0x60) != '\0') {
      *(long *)(param_1 + 0x50) = param_2;
      *(undefined8 *)(param_1 + 0x58) = 0;
    }
  }
  return 0;
}


// ===== 0051b4a0 resPreDestruct_IMPL =====

void resPreDestruct_IMPL(void)

{
  return;
}


// ===== 0051b4b0 resDestruct_IMPL =====

void resDestruct_IMPL(void)

{
  return;
}


// ===== 0051b4c0 resSetFreeParams_IMPL =====

undefined8 resSetFreeParams_IMPL(long param_1,undefined8 param_2,undefined8 param_3)

{
  if (*(char *)(param_1 + 0x60) != '\0') {
    *(undefined8 *)(param_1 + 0x50) = param_2;
    *(undefined8 *)(param_1 + 0x58) = param_3;
  }
  return 0;
}


// ===== 0051b4e0 resGetFreeParams_IMPL =====

undefined8 resGetFreeParams_IMPL(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = *(undefined8 *)(param_1 + 0x50);
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = *(undefined8 *)(param_1 + 0x58);
  }
  return 0;
}


// ===== 0051b4ff resControlLookup_IMPL.cold =====

void resControlLookup_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0051b510 resControlLookup_IMPL =====

undefined8 resControlLookup_IMPL(long param_1,long param_2,long *param_3)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  long lVar4;
  undefined8 uVar5;
  
  uVar1 = *(undefined4 *)(param_2 + 8);
  *param_3 = 0;
  lVar4 = fullyDeriveWrapper();
  uVar5 = 0;
  if (lVar4 != 0) {
    uVar5 = fullyDeriveWrapper(param_1);
  }
  lVar4 = objGetExportedMethodDef_IMPL(uVar5,uVar1);
  if (lVar4 != 0) {
    iVar2 = *(int *)(lVar4 + 0x14);
    if ((iVar2 != 0) && (iVar2 != *(int *)(param_2 + 0x18))) {
      if (param_1 != 0) {
        nvDbg_Printf("src/libraries/resserv/src/rs_resource.c",0x87,"resControlLookup_IMPL",2,
                     "NVRM: hObject 0x%08x, cmd 0x%08x: bad paramsize %d, expected %d\n",
                     *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x40) + 0x48) + 0x10),
                     *(undefined4 *)(param_2 + 8),*(int *)(param_2 + 0x18),iVar2);
        return 0x3a;
      }
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    *param_3 = lVar4;
    return 0;
  }
  return 0x56;
}


// ===== 0051b600 resControl_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined8 resControl_IMPL(long *param_1,undefined8 *param_2,long param_3)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 uVar3;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 *local_40 [2];
  
  uVar1 = *param_2;
  local_48 = 0;
  local_44 = 1;
  uVar3 = resControlLookup_IMPL(param_1,param_3,local_40);
  if ((int)uVar3 == 0) {
    if (local_40[0] == (undefined8 *)0x0) {
      nvAssertFailedNoLog("pEntry != NULL","src/libraries/resserv/src/rs_resource.c",0xae);
      uVar3 = 0x56;
    }
    else {
      serverControl_InitCookie(local_40[0],*(undefined8 *)(param_3 + 0x60));
      uVar3 = (**(code **)(*param_1 + 0x50))(param_1,param_2,param_3);
      if (((int)uVar3 == 0) &&
         (uVar3 = serverControl_Prologue(uVar1,param_3,&local_44,&local_48), (int)uVar3 == 0)) {
        local_4c = (**(code **)(*param_1 + 0x58))(param_1,param_2,param_3);
        iVar2 = local_4c;
        if ((local_4c == 0) &&
           ((iVar2 = (**(code **)(*param_1 + 0x68))(param_1,param_2,param_3), iVar2 == 0 ||
            (iVar2 == 0x10006)))) {
          uVar3 = objDynamicCastById_IMPL(param_1,*(uint *)(local_40[0][3] + 4) & 0xffffff);
          if (iVar2 != 0x10006) {
            if (*(int *)((long)local_40[0] + 0x14) == 0) {
              local_4c = (*(code *)*local_40[0])(uVar3);
            }
            else {
              local_4c = (*(code *)*local_40[0])(uVar3,*(undefined8 *)(param_3 + 0x10));
            }
          }
          (**(code **)(*param_1 + 0x70))(param_1,param_2,param_3);
          iVar2 = local_4c;
        }
        local_4c = iVar2;
        (**(code **)(*param_1 + 0x60))(param_1,param_2,param_3);
        uVar3 = serverControl_Epilogue(uVar1,param_3,local_44,&local_48,local_4c);
      }
    }
  }
  return uVar3;
}


// ===== 0051b7c0 resControlFilter_IMPL =====

undefined8 resControlFilter_IMPL(void)

{
  return 0;
}


// ===== 0051b7d0 resControlSerialization_Prologue_IMPL =====

undefined8 resControlSerialization_Prologue_IMPL(void)

{
  return 0;
}


// ===== 0051b7e0 resControlSerialization_Epilogue_IMPL =====

void resControlSerialization_Epilogue_IMPL(void)

{
  return;
}


// ===== 0051b7f0 resControl_Prologue_IMPL =====

undefined8 resControl_Prologue_IMPL(void)

{
  return 0;
}


// ===== 0051b800 resControl_Epilogue_IMPL =====

void resControl_Epilogue_IMPL(void)

{
  return;
}


// ===== 0051b810 resGetRefCount_IMPL =====

undefined8 resGetRefCount_IMPL(void)

{
  return 1;
}


// ===== 0051b820 resMap_IMPL =====

undefined8 resMap_IMPL(void)

{
  return 0x56;
}


// ===== 0051b830 resUnmap_IMPL =====

undefined8 resUnmap_IMPL(void)

{
  return 0x56;
}


// ===== 0051b840 resMapTo_IMPL =====

undefined8 resMapTo_IMPL(void)

{
  return 0x33;
}


// ===== 0051b850 resUnmapFrom_IMPL =====

undefined8 resUnmapFrom_IMPL(void)

{
  return 0x33;
}


// ===== 0051b860 resCanCopy_IMPL =====

undefined8 resCanCopy_IMPL(void)

{
  return 0;
}


// ===== 0051b870 resIsDuplicate_IMPL =====

undefined8 resIsDuplicate_IMPL(void)

{
  return 0x56;
}


// ===== 0051b880 resAccessCallback_IMPL =====

undefined8 resAccessCallback_IMPL(void)

{
  return 0;
}


// ===== 0051b890 resShareCallback_IMPL =====

undefined4 resShareCallback_IMPL(undefined8 param_1,long param_2,undefined8 param_3,int *param_4)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (((short)param_4[2] != 1) && (uVar1 = 0, (short)param_4[2] == 3)) {
    return CONCAT31((int3)((uint)*(int *)(param_2 + 0x48) >> 8),*param_4 == *(int *)(param_2 + 0x48)
                   );
  }
  return uVar1;
}


// ===== 0051b8c0 refFindCpuMappingWithFilter =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */

undefined8 refFindCpuMappingWithFilter(long param_1,long param_2,code *param_3,long *param_4)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog(&DAT_00dace2f,"src/libraries/resserv/src/rs_resource.c",0x19d);
  }
  else {
    param_1 = param_1 + 0x128;
    uVar3 = listTail_IMPL(param_1);
    uVar4 = listHead_IMPL(param_1);
    listIterRange_IMPL(&local_78,param_1,uVar4,uVar3);
    local_58 = local_78;
    local_50 = local_70;
    local_48 = local_68;
    local_40 = local_60;
    while (cVar2 = listIterNext_IMPL(&local_58), lVar1 = local_58, cVar2 != '\0') {
      if ((*(long *)(local_58 + 0x18) == param_2) &&
         ((param_3 == (code *)0x0 || (cVar2 = (*param_3)(local_58), cVar2 != '\0')))) {
        *param_4 = lVar1;
        return 0;
      }
    }
  }
  return 0x57;
}


// ===== 0051b9c0 refFindCpuMapping =====

void refFindCpuMapping(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  refFindCpuMappingWithFilter(param_1,param_2,0,param_3);
  return;
}


// ===== 0051b9d0 refFindChildOfType =====

undefined8 refFindChildOfType(long param_1,undefined4 param_2,char param_3,long *param_4)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 local_78 [4];
  long *local_58 [5];
  
  param_1 = param_1 + 0x20;
  if (param_3 == '\0') {
    uVar3 = mapFindLEQ_IMPL(param_1,0xffffffffffffffff);
    uVar4 = mapFindGEQ_IMPL(param_1,0);
    mapIterRange_IMPL(local_78,param_1,uVar4,uVar3);
    do {
      do {
        cVar2 = mapIterNext_IMPL(local_78);
        uVar3 = local_78[0];
        if (cVar2 == '\0') {
          return 0x57;
        }
        uVar4 = mapFindLEQ_IMPL(local_78[0],0xffffffffffffffff);
        uVar3 = mapFindGEQ_IMPL(uVar3,0);
        multimapItemIterRange_IMPL(local_58,param_1,uVar3,uVar4);
        cVar2 = multimapItemIterNext_IMPL(local_58);
      } while (cVar2 == '\0');
      lVar1 = *local_58[0];
      lVar5 = objDynamicCastById_IMPL(*(undefined8 *)(lVar1 + 8),param_2);
    } while (lVar5 == 0);
    if (param_4 != (long *)0x0) {
      *param_4 = lVar1;
    }
  }
  else {
    indexRefIter(local_58,param_1,param_2);
    cVar2 = indexRefIterNext(local_58);
    if (cVar2 == '\0') {
      return 0x57;
    }
    if (param_4 != (long *)0x0) {
      *param_4 = *local_58[0];
    }
  }
  return 0;
}


// ===== 0051bb40 refFindAncestorOfType =====

undefined8 refFindAncestorOfType(long param_1,int param_2,long *param_3)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x18);
  while( true ) {
    if (lVar1 == 0) {
      return 0x57;
    }
    if (*(int *)(lVar1 + 0x118) == param_2) break;
    lVar1 = *(long *)(lVar1 + 0x18);
  }
  if (*(char *)(lVar1 + 0x124) != '\0') {
    return 0x57;
  }
  if (param_3 != (long *)0x0) {
    *param_3 = lVar1;
  }
  return 0;
}


// ===== 0051bb90 refHasAncestor =====

undefined8 refHasAncestor(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x18);
  while( true ) {
    if (lVar1 == 0) {
      return 0;
    }
    if (param_2 == lVar1) break;
    lVar1 = *(long *)(lVar1 + 0x18);
  }
  return 1;
}


// ===== 0051bbc0 refAddMapping =====

ulong refAddMapping(long param_1,long param_2,long param_3,undefined8 *param_4)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 *puVar3;
  ulong uVar4;
  
  puVar3 = (undefined8 *)listAppendNew_IMPL(param_1 + 0x128);
  if (puVar3 == (undefined8 *)0x0) {
    return 0x51;
  }
  uVar4 = refAllocCpuMappingPrivate(param_2,puVar3);
  if ((int)uVar4 != 0) {
    listRemove_IMPL(param_1 + 0x128,puVar3);
    return uVar4 & 0xffffffff;
  }
  if ((param_3 != 0) && (param_1 != param_3)) {
    for (lVar2 = *(long *)(param_1 + 0x18); lVar2 != 0; lVar2 = *(long *)(lVar2 + 0x18)) {
      if (param_3 == lVar2) goto LAB_0051bc42;
    }
    listAppendExisting_IMPL(param_3 + 0x150,puVar3);
    uVar4 = uVar4 & 0xffffffff;
  }
LAB_0051bc42:
  *puVar3 = *(undefined8 *)(param_2 + 0x10);
  puVar3[1] = *(undefined8 *)(param_2 + 0x18);
  uVar1 = *(undefined4 *)(param_2 + 0x28);
  puVar3[4] = param_3;
  *(undefined4 *)(puVar3 + 2) = uVar1;
  puVar3[5] = param_1;
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = puVar3;
    return uVar4;
  }
  return uVar4;
}


// ===== 0051bd00 refRemoveMapping =====

void refRemoveMapping(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_2 + 0x20);
  if (lVar1 != 0) {
    for (lVar2 = *(long *)(param_1 + 0x18); lVar2 != 0; lVar2 = *(long *)(lVar2 + 0x18)) {
      if (lVar1 == lVar2) goto LAB_0051bd3e;
    }
    listRemoveIntrusive_IMPL(lVar1 + 0x150,param_2);
  }
LAB_0051bd3e:
  refFreeCpuMappingPrivate(param_2);
  listRemove_IMPL(param_1 + 0x128,param_2);
  return;
}


// ===== 0051bd80 refCreateInterMapping =====

undefined8 refCreateInterMapping(long param_1,long *param_2)

{
  long lVar1;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pMapperRef != NULL","src/libraries/resserv/src/rs_resource.c",0x26d);
  }
  else {
    if (param_2 != (long *)0x0) {
      if (*(long *)(param_1 + 0x1d8) == 0) {
        nvAssertFailedNoLog("pMapperRef->pAllocator != NULL",
                            "src/libraries/resserv/src/rs_resource.c",0x26f);
        return 0x40;
      }
      lVar1 = _portMemAllocatorAlloc(*(long *)(param_1 + 0x1d8),0x80);
      if (lVar1 != 0) {
        portMemSet(lVar1,0,0x80);
        *param_2 = lVar1;
        return 0;
      }
      *param_2 = 0;
      return 0x51;
    }
    nvAssertFailedNoLog("ppInterMapping != NULL","src/libraries/resserv/src/rs_resource.c",0x26e);
  }
  return 0x1f;
}


// ===== 0051be80 refDestroyInterMapping =====

undefined8 refDestroyInterMapping(long param_1,long param_2)

{
  if (param_1 == 0) {
    nvAssertFailedNoLog("pMapperRef != NULL","src/libraries/resserv/src/rs_resource.c",0x286);
  }
  else {
    if (param_2 != 0) {
      if (*(long *)(param_1 + 0x1d8) != 0) {
        _portMemAllocatorFree();
        return 0;
      }
      nvAssertFailedNoLog("pMapperRef->pAllocator != NULL","src/libraries/resserv/src/rs_resource.c"
                          ,0x288);
      return 0x40;
    }
    nvAssertFailedNoLog("pInterMapping != NULL","src/libraries/resserv/src/rs_resource.c",0x287);
  }
  return 0x1f;
}


// ===== 0051bf10 refAddInterMapping =====

undefined8 refAddInterMapping(long param_1,long param_2,long param_3,long param_4,long *param_5)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pMapperRef != NULL","src/libraries/resserv/src/rs_resource.c",0x29b);
    return 0x1f;
  }
  if (param_2 == 0) {
    nvAssertFailedNoLog("pMappableRef != NULL","src/libraries/resserv/src/rs_resource.c",0x29c);
    return 0x1f;
  }
  if (param_1 == param_2) {
    nvAssertFailedNoLog("pMappableRef != pMapperRef","src/libraries/resserv/src/rs_resource.c",0x29d
                       );
    return 0x1f;
  }
  if (param_5 == (long *)0x0) {
    nvAssertFailedNoLog("pInterMapping != NULL","src/libraries/resserv/src/rs_resource.c",0x29e);
    return 0x1f;
  }
  lVar2 = mapFind_IMPL(param_1 + 0x168,*(undefined4 *)(param_4 + 0x10));
  if (lVar2 == 0) {
    lVar2 = mapInsertNew_IMPL(param_1 + 0x168,*(undefined4 *)(param_4 + 0x10));
    mapInitIntrusive_IMPL(lVar2,0x38);
    if (lVar2 == 0) {
      nvAssertFailedNoLog("pInterMappings != NULL","src/libraries/resserv/src/rs_resource.c",0x2a6);
      return 0x51;
    }
  }
  cVar1 = mapInsertExisting_IMPL(lVar2,param_3,param_5);
  if (cVar1 == '\0') {
    lVar2 = mapFind_IMPL(lVar2,param_3);
    if (lVar2 != 0) {
      nvDbg_Printf("src/libraries/resserv/src/rs_resource.c",0x2ae,"refAddInterMapping",4,
                   "NVRM: Duplicate inter mapping detected at dmaOffset: 0x%llX. newSize: 0x%llX existingSize: 0x%llX\n"
                   ,param_3,param_5[0xe],*(undefined8 *)(lVar2 + 0x70));
      return 0x1f;
    }
    nvDbg_Printf("src/libraries/resserv/src/rs_resource.c",0x2b5,"refAddInterMapping",4,
                 "NVRM: Failed to add inter mapping at dmaOffset: 0x%llX\n",param_3);
    uVar3 = 0x40;
  }
  else {
    listAppendExisting_IMPL(param_2 + 0x188,param_5);
    for (lVar2 = *(long *)(param_1 + 0x18); lVar2 != 0; lVar2 = *(long *)(lVar2 + 0x18)) {
      if (lVar2 == param_4) goto LAB_0051c02e;
    }
    for (lVar2 = *(long *)(param_2 + 0x18); lVar2 != 0; lVar2 = *(long *)(lVar2 + 0x18)) {
      if (lVar2 == param_4) goto LAB_0051c02e;
    }
    listAppendExisting_IMPL(param_4 + 0x1a0,param_5);
LAB_0051c02e:
    param_5[1] = param_2;
    uVar3 = 0;
    param_5[2] = param_4;
    *param_5 = param_1;
    param_5[0xd] = param_3;
  }
  return uVar3;
}


// ===== 0051c1d0 refRemoveInterMapping =====

void refRemoveInterMapping(long param_1,long param_2,char param_3)

{
  long lVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  
  lVar1 = *(long *)(param_2 + 0x10);
  lVar2 = *(long *)(param_2 + 8);
  lVar5 = mapFind_IMPL(param_1 + 0x168,*(undefined4 *)(lVar1 + 0x10));
  listRemoveIntrusive_IMPL(lVar2 + 0x188,param_2);
  for (lVar3 = *(long *)(param_1 + 0x18); lVar3 != 0; lVar3 = *(long *)(lVar3 + 0x18)) {
    if (lVar3 == lVar1) goto joined_r0x0051c241;
  }
  for (lVar2 = *(long *)(lVar2 + 0x18); lVar2 != 0; lVar2 = *(long *)(lVar2 + 0x18)) {
    if (lVar2 == lVar1) goto joined_r0x0051c241;
  }
  listRemoveIntrusive_IMPL(lVar1 + 0x1a0,param_2);
joined_r0x0051c241:
  if (lVar5 == 0) {
    nvAssertFailedNoLog("pInterMappings != NULL","src/libraries/resserv/src/rs_resource.c",0x2e6);
  }
  mapRemoveIntrusive_IMPL(lVar5,param_2);
  if ((param_3 == '\0') && (iVar4 = mapCount_IMPL(lVar5), iVar4 == 0)) {
    mapDestroyIntrusive_IMPL(lVar5);
    mapRemove_IMPL(param_1 + 0x168,lVar5);
    return;
  }
  return;
}


// ===== 0051c310 refUncacheRef =====

void refUncacheRef(long param_1,long param_2)

{
  indexRemove(param_1 + 0x50,*(undefined4 *)(param_2 + 0x118),param_2);
  return;
}


// ===== 0051c330 refAddDependant =====

undefined8 refAddDependant(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  for (lVar1 = *(long *)(param_2 + 0x18); lVar1 != 0; lVar1 = *(long *)(lVar1 + 0x18)) {
    if (param_1 == lVar1) {
      return 0;
    }
  }
  uVar2 = indexAdd(param_2 + 0xb0,*(undefined4 *)(param_1 + 0x118));
  if ((int)uVar2 != 0) {
    return uVar2;
  }
  uVar2 = indexAdd(param_1 + 0x80,*(undefined4 *)(param_2 + 0x118),param_2);
  return uVar2;
}


// ===== 0051c3b0 refRemoveDependant =====

void refRemoveDependant(long param_1,long param_2)

{
  indexRemove(param_2 + 0xb0,*(undefined4 *)(param_1 + 0x118),param_1);
  indexRemove(param_1 + 0x80,*(undefined4 *)(param_2 + 0x118),param_2);
  return;
}


// ===== 0051c400 refPendingFree =====

bool refPendingFree(long param_1,long param_2)

{
  long lVar1;
  
  if ((*(long *)(param_1 + 0x1d0) == 0) && (*(long *)(param_1 + 0x1c8) == 0)) {
    lVar1 = listHead_IMPL(param_2 + 0xc0);
    return lVar1 == param_1;
  }
  return true;
}


// ===== 0051c450 resAddAdditionalDependants_IMPL =====

void resAddAdditionalDependants_IMPL(void)

{
  return;
}


// ===== 0051c460 serverInterUnmapMapping =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int serverInterUnmapMapping
              (long *param_1,long param_2,undefined8 *param_3,long param_4,byte param_5)

{
  int iVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  long local_48;
  long local_40 [2];
  
  local_48 = 0;
  local_40[0] = 0;
  refRemoveInterMapping(param_2,param_3,1);
  if ((ulong)param_3[0xd] < *(ulong *)(param_4 + 0x10)) {
    iVar2 = refCreateInterMapping(param_2,&local_48);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,"refCreateInterMapping(pMapperRef, &pNewMappingLeft)",
                 "src/libraries/resserv/src/rs_server.c",0x91c);
      goto LAB_0051c4ee;
    }
    *(long *)(local_48 + 0x70) = *(long *)(param_4 + 0x10) - param_3[0xd];
    iVar2 = refAddInterMapping(param_2,param_3[1],param_3[0xd],param_3[2]);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,
                 "refAddInterMapping(pMapperRef, pMapping->pMappableRef, pMapping->dmaOffset, pMapping->pContextRef, pNewMappingLeft)"
                 ,"src/libraries/resserv/src/rs_server.c",0x920);
      goto LAB_0051c4ee;
    }
    *(undefined4 *)(local_48 + 0x60) = *(undefined4 *)(param_3 + 0xc);
    *(undefined4 *)(local_48 + 100) = *(undefined4 *)((long)param_3 + 100);
    uVar4 = *(long *)(param_4 + 0x10) + *(long *)(param_4 + 0x18);
    if (uVar4 < (ulong)(param_3[0xd] + param_3[0xe])) goto LAB_0051c61f;
  }
  else {
    uVar4 = *(ulong *)(param_4 + 0x10) + *(long *)(param_4 + 0x18);
    if (uVar4 < (ulong)(param_3[0xd] + param_3[0xe])) {
LAB_0051c61f:
      iVar2 = refCreateInterMapping(param_2,local_40);
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,"refCreateInterMapping(pMapperRef, &pNewMappingRight)",
                   "src/libraries/resserv/src/rs_server.c",0x92f);
        goto LAB_0051c4ee;
      }
      *(ulong *)(local_40[0] + 0x70) = (param_3[0xe] + param_3[0xd]) - uVar4;
      iVar2 = refAddInterMapping(param_2,param_3[1],uVar4,param_3[2]);
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,
                   "refAddInterMapping(pMapperRef, pMapping->pMappableRef, newMappingRightDmaOffset, pMapping->pContextRef, pNewMappingRight)"
                   ,"src/libraries/resserv/src/rs_server.c",0x933);
        goto LAB_0051c4ee;
      }
      *(undefined4 *)(local_40[0] + 0x60) = *(undefined4 *)(param_3 + 0xc);
      *(undefined4 *)(local_40[0] + 100) = *(undefined4 *)((long)param_3 + 100);
    }
  }
  *(undefined4 *)(param_4 + 0x20) = *(undefined4 *)(param_3[1] + 0x10);
  *(undefined8 *)(param_4 + 0x28) = param_3[0xf];
  iVar2 = (**(code **)(*param_1 + 0x70))(param_1,param_2,param_4);
LAB_0051c4ee:
  if ((iVar2 == 0) || ((param_5 & 1) == 0)) {
    if ((local_48 == 0) && (local_40[0] == 0)) {
      lVar3 = mapFind_IMPL(param_2 + 0x168,*(undefined4 *)(param_3[2] + 0x10));
      if (lVar3 == 0) {
        nvAssertFailedNoLog("pInterMappings != NULL","src/libraries/resserv/src/rs_server.c",0x960);
      }
      iVar1 = mapCount_IMPL(lVar3);
      if (iVar1 == 0) {
        mapDestroyIntrusive_IMPL(lVar3);
        mapRemove_IMPL(param_2 + 0x168,lVar3);
      }
    }
    refDestroyInterMapping(param_2,param_3);
  }
  else {
    if (local_48 != 0) {
      refRemoveInterMapping(param_2,local_48,1);
      refDestroyInterMapping(param_2,local_48);
    }
    if (local_40[0] != 0) {
      refRemoveInterMapping(param_2,local_40[0],1);
      refDestroyInterMapping(param_2,local_40[0]);
    }
    iVar1 = refAddInterMapping(*param_3,param_3[1],param_3[0xd],param_3[2],param_3);
    if (iVar1 != 0) {
      nvAssertOkFailedNoLog
                (iVar1,
                 "refAddInterMapping(pMapping->pMapperRef, pMapping->pMappableRef, pMapping->dmaOffset, pMapping->pContextRef, pMapping)"
                 ,"src/libraries/resserv/src/rs_server.c",0x952);
      iVar2 = iVar1;
    }
  }
  return iVar2;
}


// ===== 0051c780 _serverFindNextAvailableClientHandleInBucket.isra.0 =====

undefined8
_serverFindNextAvailableClientHandleInBucket_isra_0
          (long param_1,uint param_2,uint *param_3,long *param_4)

{
  long lVar1;
  uint uVar2;
  
  param_1 = param_1 + (ulong)(param_2 & 0x3ff) * 0x18;
  lVar1 = listHead_IMPL(param_1);
  *param_4 = 0;
  uVar2 = param_2;
  if (lVar1 == 0) {
    *param_3 = param_2;
  }
  else {
    do {
      while (*(uint *)(lVar1 + 0x10) < uVar2) {
LAB_0051c7d8:
        lVar1 = listNext_IMPL(param_1,lVar1);
        if (lVar1 == 0) goto LAB_0051c840;
      }
      if (*(uint *)(lVar1 + 0x10) != uVar2) {
        if ((param_2 ^ uVar2) < 0x100000) {
          *param_3 = uVar2;
          *param_4 = lVar1;
          return 0;
        }
        return 0x1a;
      }
      uVar2 = uVar2 + 0x400;
      if (((param_2 ^ uVar2) & 0x3ff) == 0) goto LAB_0051c7d8;
      nvAssertFailedNoLog("(hClientIn & RS_CLIENT_HANDLE_BUCKET_MASK) == (hClientOut & RS_CLIENT_HANDLE_BUCKET_MASK)"
                          ,"src/libraries/resserv/src/rs_server.c",0xcb7);
      lVar1 = listNext_IMPL(param_1,lVar1);
    } while (lVar1 != 0);
LAB_0051c840:
    if (0xfffff < (param_2 ^ uVar2)) {
      return 0x1a;
    }
    *param_3 = uVar2;
  }
  return 0;
}


// ===== 0051c8b0 __serverFindClientEntryByHandle =====

undefined8
__serverFindClientEntryByHandle
          (long param_1,uint param_2,uint param_3,int param_4,char param_5,long *param_6)

{
  uint *puVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  
  if (param_4 == 1) {
    portSyncSpinlockAcquire(*(undefined8 *)(param_1 + 0x20));
  }
  lVar2 = *(long *)(param_1 + 8) + (ulong)(param_2 & 0x3ff) * 0x18;
  lVar3 = listHead_IMPL(lVar2);
  do {
    if (lVar3 == 0) break;
    lVar4 = listNext_IMPL(lVar2,lVar3);
    puVar1 = (uint *)(lVar3 + 0x10);
    if (*puVar1 == param_2) {
      if (*(long *)(lVar3 + 8) == 0) {
        if ((param_3 & 1) == 0) break;
        if (param_5 != '\0') {
          if (*(char *)(lVar3 + 0x28) != '\0') goto LAB_0051c9c7;
          goto LAB_0051c9df;
        }
      }
      else if (*(char *)(lVar3 + 0x28) == '\0') {
        if (param_5 != '\0') goto LAB_0051c9df;
      }
      else {
        if ((param_3 & 2) == 0) break;
        if (param_5 != '\0') {
LAB_0051c9c7:
          nvAssertFailedNoLog("!pClientEntry->bPendingFree","src/libraries/resserv/src/rs_server.c",
                              0xc7c);
LAB_0051c9df:
          LOCK();
          *(int *)(lVar3 + 0x24) = *(int *)(lVar3 + 0x24) + 1;
          UNLOCK();
        }
      }
      if (param_6 != (long *)0x0) {
        *param_6 = lVar3;
      }
      uVar5 = 1;
      goto LAB_0051c924;
    }
    lVar3 = lVar4;
  } while (*puVar1 <= param_2);
  uVar5 = 0;
LAB_0051c924:
  if (param_4 == 1) {
    portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x20));
    return uVar5;
  }
  return uVar5;
}


// ===== 0051c9f0 _serverUnlockClientWithLockInfo.constprop.0 =====

void _serverUnlockClientWithLockInfo_constprop_0
               (long param_1,undefined8 *param_2,undefined8 *param_3,uint *param_4)

{
  int *piVar1;
  
  if ((*param_4 & 2) != 0) {
    param_2[3] = 0xffffffffffffffff;
    portSyncRwLockReleaseWrite(*param_2);
    *(uint *)((long)param_3 + 0x2c) = *(uint *)((long)param_3 + 0x2c) & 0xffffff7f;
    *param_3 = 0;
    *param_4 = *param_4 & 0xfffffffd;
  }
  LOCK();
  piVar1 = (int *)((long)param_2 + 0x24);
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (*piVar1 != 0) {
    return;
  }
  param_2[1] = 0;
  *(undefined4 *)(param_2 + 2) = 0;
  portSyncRwLockDestroy(*param_2);
  _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x18),param_2);
  return;
}


// ===== 0051ca80 _serverUnlockDualClientWithLockInfo.constprop.0 =====

void _serverUnlockDualClientWithLockInfo_constprop_0
               (long param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
               uint *param_5)

{
  int *piVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  if ((*param_5 & 2) != 0) {
    puVar2 = param_3;
    puVar3 = param_2;
    if (*(uint *)(param_3[1] + 0x48) < *(uint *)(param_2[1] + 0x48)) {
      puVar2 = param_2;
      puVar3 = param_3;
    }
    puVar2[3] = 0xffffffffffffffff;
    portSyncRwLockReleaseWrite(*puVar2);
    if (*(int *)(param_2[1] + 0x48) != *(int *)(param_3[1] + 0x48)) {
      puVar3[3] = 0xffffffffffffffff;
      portSyncRwLockReleaseWrite(*puVar3);
    }
    *(uint *)((long)param_4 + 0x2c) = *(uint *)((long)param_4 + 0x2c) & 0xffffff7f;
    *param_4 = 0;
    param_4[1] = 0;
    *param_5 = *param_5 & 0xfffffffd;
  }
  LOCK();
  piVar1 = (int *)((long)param_2 + 0x24);
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (*piVar1 == 0) {
    param_2[1] = 0;
    *(undefined4 *)(param_2 + 2) = 0;
    portSyncRwLockDestroy(*param_2);
    _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x18),param_2);
  }
  if (param_2 != param_3) {
    LOCK();
    piVar1 = (int *)((long)param_3 + 0x24);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 == 0) {
      param_3[1] = 0;
      *(undefined4 *)(param_3 + 2) = 0;
      portSyncRwLockDestroy(*param_3);
      _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x18),param_3);
      return;
    }
  }
  return;
}


// ===== 0051cbc0 _serverFreeClient.isra.0 =====

void _serverFreeClient_isra_0(long param_1,long param_2)

{
  long lVar1;
  int *piVar2;
  uint uVar3;
  undefined8 *puVar4;
  int iVar5;
  undefined8 *puVar6;
  long lVar7;
  undefined8 uVar8;
  undefined4 local_44;
  undefined8 *local_40 [2];
  
  uVar3 = *(uint *)(param_2 + 4);
  local_44 = 0;
  portSyncSpinlockAcquire(*(undefined8 *)(param_1 + 0x20));
  lVar1 = *(long *)(param_1 + 8) + (ulong)(uVar3 & 0x3ff) * 0x18;
  puVar6 = (undefined8 *)listHead_IMPL(lVar1);
  do {
    local_40[0] = puVar6;
    if (puVar6 == (undefined8 *)0x0) {
LAB_0051cc54:
      portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x20));
      return;
    }
    if (uVar3 == *(uint *)(puVar6 + 2)) {
      if ((puVar6[1] != 0) && (*(char *)(puVar6 + 5) == '\0')) {
        *(undefined1 *)(puVar6 + 5) = 1;
        portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x20));
        lVar1 = *(long *)(param_1 + 0x48);
        lVar7 = portThreadGetCurrentThreadId();
        if ((lVar1 == lVar7) &&
           (lVar1 = local_40[0][3], lVar7 = portThreadGetCurrentThreadId(), puVar4 = local_40[0],
           lVar1 == lVar7)) {
          local_40[0][3] = 0xffffffffffffffff;
          portSyncRwLockReleaseWrite(*local_40[0]);
          LOCK();
          piVar2 = (int *)((long)puVar4 + 0x24);
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (*piVar2 == 0) {
            puVar4[1] = 0;
            *(undefined4 *)(puVar4 + 2) = 0;
            portSyncRwLockDestroy(*puVar4);
            _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x18),puVar4);
          }
          listRemoveFirstByValue_IMPL(param_1 + 0xe8,local_40);
        }
        while (puVar4 = local_40[0], 1 < *(uint *)((long)local_40[0] + 0x24)) {
          portSyncRwLockAcquireWrite(*local_40[0]);
          uVar8 = portThreadGetCurrentThreadId();
          puVar4[3] = uVar8;
          local_40[0][3] = 0xffffffffffffffff;
          portSyncRwLockReleaseWrite(*local_40[0]);
        }
        LOCK();
        *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0xb0) + -1;
        UNLOCK();
        iVar5 = serverResLock_Prologue
                          (param_1,1,*(undefined8 *)(*(long *)(param_2 + 0x10) + 0x18),&local_44,0);
        if (iVar5 == 0) {
          lVar1 = puVar6[1];
          uVar3 = *(uint *)(lVar1 + 0x48);
          clientFreeAccessBackRefs_IMPL(lVar1,param_1);
          if (*(char *)(lVar1 + 0x52) != '\0') {
            portSyncSpinlockAcquire(*(undefined8 *)(param_1 + 0xe0));
            listRemoveIntrusive_IMPL(param_1 + 0xc0,lVar1);
            portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0xe0));
          }
          piVar2 = (int *)((long)puVar6 + 0x24);
          __nvoc_objDelete(lVar1);
          portSyncSpinlockAcquire(*(undefined8 *)(param_1 + 0x20));
          listRemoveIntrusive_IMPL(*(long *)(param_1 + 8) + (ulong)(uVar3 & 0x3ff) * 0x18,puVar6);
          portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x20));
          if (*(int *)((long)puVar6 + 0x24) != 1) {
            nvAssertFailedNoLog("pClientEntry->refCount == 1",
                                "src/libraries/resserv/src/rs_server.c",0x212);
          }
          LOCK();
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (*piVar2 == 0) {
            puVar6[1] = 0;
            *(undefined4 *)(puVar6 + 2) = 0;
            portSyncRwLockDestroy(*puVar6);
            _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x18),puVar6);
          }
          serverResLock_Epilogue
                    (param_1,1,*(undefined8 *)(*(long *)(param_2 + 0x10) + 0x18),&local_44);
          return;
        }
        serverResLock_Epilogue
                  (param_1,1,*(undefined8 *)(*(long *)(param_2 + 0x10) + 0x18),&local_44);
        portSyncSpinlockAcquire(*(undefined8 *)(param_1 + 0x20));
        *(undefined1 *)(puVar6 + 5) = 0;
LAB_0051cd0e:
        portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x20));
        return;
      }
      goto LAB_0051cc54;
    }
    if (uVar3 < *(uint *)(puVar6 + 2)) goto LAB_0051cd0e;
    puVar6 = (undefined8 *)listNext_IMPL(lVar1,puVar6);
  } while( true );
}


// ===== 0051ceb0 _serverGetAndLockClientEntryByHandle =====

uint _serverGetAndLockClientEntryByHandle
               (long param_1,undefined8 param_2,int param_3,undefined8 *param_4)

{
  int *piVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 *local_30;
  
  uVar2 = __serverFindClientEntryByHandle(param_1,param_2,0,1,1,&local_30);
  if ((char)uVar2 != '\0') {
    if (param_3 == 0) {
      portSyncRwLockAcquireRead();
      LOCK();
      *(int *)(local_30 + 4) = *(int *)(local_30 + 4) + 1;
      UNLOCK();
      if (*(char *)(local_30 + 5) == '\0') {
        *param_4 = local_30;
LAB_0051cf33:
        return uVar2 & 0xff;
      }
      LOCK();
      *(int *)(local_30 + 4) = *(int *)(local_30 + 4) + -1;
      UNLOCK();
      portSyncRwLockReleaseRead(*local_30);
    }
    else {
      portSyncRwLockAcquireWrite(*local_30);
      uVar3 = portThreadGetCurrentThreadId();
      if (*(char *)(local_30 + 5) == '\0') {
        local_30[3] = uVar3;
        *param_4 = local_30;
        goto LAB_0051cf33;
      }
      local_30[3] = 0xffffffffffffffff;
      portSyncRwLockReleaseWrite(*local_30);
    }
    LOCK();
    piVar1 = (int *)((long)local_30 + 0x24);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 == 0) {
      local_30[1] = 0;
      *(undefined4 *)(local_30 + 2) = 0;
      portSyncRwLockDestroy(*local_30);
      _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x18),local_30);
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 0051cff0 _serverLockClientWithLockInfo.constprop.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong _serverLockClientWithLockInfo_constprop_0
                (long param_1,ulong param_2,char param_3,long *param_4,uint *param_5,long *param_6)

{
  int *piVar1;
  long lVar2;
  undefined8 *puVar3;
  char cVar4;
  long lVar5;
  ulong uVar6;
  
  if ((*(byte *)(param_4 + 5) & 2) == 0) {
    lVar2 = *(long *)(param_1 + 0x48);
    lVar5 = portThreadGetCurrentThreadId();
    param_2 = param_2 & 0xffffffff;
    if (lVar2 == lVar5) goto LAB_0051d100;
    if ((*(byte *)((long)param_4 + 0x2c) & 0x80) != 0) {
      cVar4 = __serverFindClientEntryByHandle(param_1,param_2,0,1,1,param_6);
      if (cVar4 != '\x01') {
        nvAssertFailedNoLog("_serverGetClientEntryByHandle(pServer, hClient, 0, CLIENT_LIST_LOCK_UNLOCKED, ppClientEntry)"
                            ,"src/libraries/resserv/src/rs_server.c",0xd90);
        return 0x33;
      }
      if (*param_4 == 0) {
        nvAssertFailedNoLog("pLockInfo->pClient != NULL","src/libraries/resserv/src/rs_server.c",
                            0xd93);
      }
      else if (*param_4 == *(long *)(*param_6 + 8)) {
        lVar2 = *(long *)(*param_6 + 0x18);
        lVar5 = portThreadGetCurrentThreadId();
        if (lVar2 == lVar5) goto joined_r0x0051d15f;
        nvAssertFailedNoLog("(*ppClientEntry)->lockOwnerTid == portThreadGetCurrentThreadId()",
                            "src/libraries/resserv/src/rs_server.c",0xd97);
      }
      else {
        nvAssertFailedNoLog("pLockInfo->pClient == (*ppClientEntry)->pClient",
                            "src/libraries/resserv/src/rs_server.c",0xd95);
      }
      uVar6 = 0x40;
      goto LAB_0051d0c2;
    }
    cVar4 = _serverGetAndLockClientEntryByHandle(param_1,param_2,1,param_6);
    if (cVar4 == '\0') {
      return 0x33;
    }
    *(uint *)((long)param_4 + 0x2c) = *(uint *)((long)param_4 + 0x2c) | 0x80;
    *param_4 = *(long *)(*param_6 + 8);
    *param_5 = *param_5 | 2;
  }
  else {
LAB_0051d100:
    cVar4 = __serverFindClientEntryByHandle(param_1,param_2,0,1,1,param_6);
    if (cVar4 == '\0') {
      return 0x33;
    }
  }
joined_r0x0051d15f:
  if (param_3 == '\0') {
    return 0;
  }
  uVar6 = (**(code **)(**(long **)(*param_6 + 8) + 0x38))(*(long **)(*param_6 + 8),param_1);
  if ((int)uVar6 == 0) {
    return uVar6;
  }
LAB_0051d0c2:
  puVar3 = (undefined8 *)*param_6;
  if ((*param_5 & 2) == 0) {
    if (puVar3 != (undefined8 *)0x0) {
      LOCK();
      piVar1 = (int *)((long)puVar3 + 0x24);
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (*piVar1 == 0) {
        puVar3[1] = 0;
        *(undefined4 *)(puVar3 + 2) = 0;
        portSyncRwLockDestroy(*puVar3);
        _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x18),puVar3);
        uVar6 = uVar6 & 0xffffffff;
      }
      *param_6 = 0;
    }
  }
  else {
    _serverUnlockClientWithLockInfo_constprop_0(param_1,puVar3,param_4,param_5);
    uVar6 = uVar6 & 0xffffffff;
  }
  return uVar6;
}


// ===== 0051d250 serverFreeResourceTreeLockAndFindResource.constprop.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong serverFreeResourceTreeLockAndFindResource_constprop_0
                (undefined8 param_1,undefined4 *param_2,undefined4 param_3,undefined8 param_4,
                long *param_5,undefined8 param_6)

{
  undefined8 uVar1;
  uint uVar2;
  ulong uVar3;
  long local_40 [2];
  
  uVar1 = *(undefined8 *)(param_2 + 6);
  uVar3 = serverTopLock_Prologue(param_1,param_3,uVar1);
  if (((int)uVar3 == 0) &&
     (uVar3 = _serverLockClientWithLockInfo_constprop_0(param_1,*param_2,1,uVar1,param_4,local_40),
     (int)uVar3 == 0)) {
    if (local_40[0] == 0) {
      nvAssertFailedNoLog("pClientEntry != NULL","src/libraries/resserv/src/rs_server.c",0xe93);
    }
    else if (*(int *)(local_40[0] + 0x20) != 0) {
      nvAssertFailedNoLog("!serverIsClientLockedForRead(pClientEntry)",
                          "src/libraries/resserv/src/rs_server.c",0x47c);
      return 0x2f;
    }
    *param_5 = local_40[0];
    uVar2 = (**(code **)(**(long **)(local_40[0] + 8) + 0x30))
                      (*(long **)(local_40[0] + 8),*(undefined8 *)(param_2 + 0xe));
    if (uVar2 == 0) {
      uVar3 = clientGetResourceRef_IMPL(*(undefined8 *)(local_40[0] + 8),param_2[1],param_6);
      if ((int)uVar3 == 0) {
        return uVar3;
      }
      nvDbg_Printf("src/libraries/resserv/src/rs_server.c",0x488,
                   "serverFreeResourceTreeLockAndFindResource",1,
                   "NVRM: hObject 0x%x not found for client 0x%x\n",param_2[1],*param_2);
    }
    return (ulong)uVar2;
  }
  return uVar3;
}


// ===== 0051d3a0 _serverLockDualClientWithLockInfo.constprop.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong _serverLockDualClientWithLockInfo_constprop_0
                (long param_1,uint param_2,uint param_3,char param_4,long *param_5,uint *param_6,
                long *param_7,long *param_8)

{
  int *piVar1;
  undefined8 *puVar2;
  uint uVar3;
  char cVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  long *plVar8;
  uint uVar9;
  
  *param_7 = 0;
  *param_8 = 0;
  plVar8 = param_8;
  if (((*(byte *)(param_5 + 5) & 2) == 0) &&
     (lVar6 = *(long *)(param_1 + 0x48), lVar5 = portThreadGetCurrentThreadId(), lVar6 != lVar5)) {
    if (param_2 <= param_3) {
      param_8 = param_7;
      uVar9 = param_2;
      uVar3 = param_3;
      if ((*(byte *)((long)param_5 + 0x2c) & 0x80) == 0) goto LAB_0051d61a;
LAB_0051d41b:
      if (param_5[1] == 0) {
        nvAssertFailedNoLog("pLockInfo->pSecondClient != NULL",
                            "src/libraries/resserv/src/rs_server.c",0xe02);
        return 0x40;
      }
      if (*(uint *)(*param_5 + 0x48) != uVar9) {
        nvAssertFailedNoLog("pLockInfo->pClient->hClient == hClient1st",
                            "src/libraries/resserv/src/rs_server.c",0xe03);
        return 0x40;
      }
      if (*(uint *)(param_5[1] + 0x48) != uVar3) {
        nvAssertFailedNoLog("pLockInfo->pSecondClient->hClient == hClient2nd",
                            "src/libraries/resserv/src/rs_server.c",0xe04);
        return 0x40;
      }
      cVar4 = __serverFindClientEntryByHandle(param_1,uVar9,0,1,1,param_7);
      if (cVar4 == '\x01') {
        if (*(long *)(*param_7 + 8) == *param_5) {
          lVar6 = *(long *)(*param_7 + 0x18);
          lVar5 = portThreadGetCurrentThreadId();
          if (lVar6 == lVar5) {
            if (uVar9 == uVar3) {
              lVar6 = *param_7;
              *plVar8 = lVar6;
            }
            else {
              cVar4 = __serverFindClientEntryByHandle(param_1,uVar3,0,1,1,plVar8);
              if (cVar4 != '\x01') {
                nvAssertFailedNoLog("_serverGetClientEntryByHandle(pServer, hClient2nd, 0, CLIENT_LIST_LOCK_UNLOCKED, ppClientEntry2nd)"
                                    ,"src/libraries/resserv/src/rs_server.c",0xe15);
                goto LAB_0051d707;
              }
              lVar6 = *plVar8;
            }
            if (*(long *)(lVar6 + 8) == param_5[1]) {
              if (*(long *)(lVar6 + 0x18) == *(long *)(*param_7 + 0x18)) goto joined_r0x0051d4d1;
              nvAssertFailedNoLog("(*ppClientEntry2nd)->lockOwnerTid == (*ppClientEntry1st)->lockOwnerTid"
                                  ,"src/libraries/resserv/src/rs_server.c",0xe1c);
            }
            else {
              nvAssertFailedNoLog("(*ppClientEntry2nd)->pClient == pLockInfo->pSecondClient",
                                  "src/libraries/resserv/src/rs_server.c",0xe1a);
            }
          }
          else {
            nvAssertFailedNoLog("(*ppClientEntry1st)->lockOwnerTid == portThreadGetCurrentThreadId()"
                                ,"src/libraries/resserv/src/rs_server.c",0xe0b);
          }
        }
        else {
          nvAssertFailedNoLog("(*ppClientEntry1st)->pClient == pLockInfo->pClient",
                              "src/libraries/resserv/src/rs_server.c",0xe09);
        }
        uVar7 = 0x40;
        param_8 = plVar8;
        goto LAB_0051d57d;
      }
      nvAssertFailedNoLog("_serverGetClientEntryByHandle(pServer, hClient1st, 0, CLIENT_LIST_LOCK_UNLOCKED, ppClientEntry1st)"
                          ,"src/libraries/resserv/src/rs_server.c",0xe06);
LAB_0051d707:
      uVar7 = 0x33;
      param_8 = plVar8;
      goto LAB_0051d57d;
    }
    plVar8 = param_7;
    param_7 = param_8;
    uVar9 = param_3;
    uVar3 = param_2;
    if ((*(byte *)((long)param_5 + 0x2c) & 0x80) != 0) goto LAB_0051d41b;
LAB_0051d61a:
    cVar4 = _serverGetAndLockClientEntryByHandle(param_1,uVar9,1,param_8);
    if (cVar4 == '\0') {
      return 0x33;
    }
    param_7 = param_8;
    if (param_2 == param_3) {
      *plVar8 = *param_8;
    }
    else {
      cVar4 = _serverGetAndLockClientEntryByHandle(param_1,uVar3,1,plVar8);
      if (cVar4 == '\0') {
        puVar2 = (undefined8 *)*param_8;
        puVar2[3] = 0xffffffffffffffff;
        portSyncRwLockReleaseWrite(*puVar2);
        goto LAB_0051d707;
      }
    }
    *(uint *)((long)param_5 + 0x2c) = *(uint *)((long)param_5 + 0x2c) | 0x80;
    *param_5 = *(long *)(*param_8 + 8);
    param_5[1] = *(long *)(*plVar8 + 8);
    *param_6 = *param_6 | 2;
joined_r0x0051d4d1:
    param_8 = plVar8;
    if (param_4 == '\0') {
      return 0;
    }
    uVar7 = (**(code **)(**(long **)(*param_7 + 8) + 0x38))(*(long **)(*param_7 + 8),param_1);
    if ((int)uVar7 != 0) goto LAB_0051d57d;
    if (param_2 != param_3) {
      uVar7 = (**(code **)(**(long **)(*param_8 + 8) + 0x38))(*(long **)(*param_8 + 8),param_1);
    }
  }
  else {
    cVar4 = __serverFindClientEntryByHandle(param_1,param_2,0,1,1,param_7);
    if (cVar4 == '\0') {
      return 0x33;
    }
    if (param_2 != param_3) {
      cVar4 = __serverFindClientEntryByHandle(param_1,param_3,0,1,1,param_8);
      if (cVar4 != '\x01') {
        nvAssertFailedNoLog("_serverGetClientEntryByHandle(pServer, hClient2, 0, CLIENT_LIST_LOCK_UNLOCKED, ppClientEntry2nd)"
                            ,"src/libraries/resserv/src/rs_server.c",0xde7);
        uVar7 = 0x33;
        goto LAB_0051d57d;
      }
      goto joined_r0x0051d4d1;
    }
    lVar6 = *param_7;
    *param_8 = lVar6;
    if (param_4 == '\0') {
      return 0;
    }
    plVar8 = *(long **)(lVar6 + 8);
    uVar7 = (**(code **)(*plVar8 + 0x38))(plVar8,param_1);
  }
  if ((int)uVar7 == 0) {
    return uVar7;
  }
LAB_0051d57d:
  puVar2 = (undefined8 *)*param_7;
  if ((*param_6 & 2) != 0) {
    _serverUnlockDualClientWithLockInfo_constprop_0(param_1,puVar2,*param_8,param_5,param_6);
    return uVar7 & 0xffffffff;
  }
  if (puVar2 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)((long)puVar2 + 0x24);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 == 0) {
      puVar2[1] = 0;
      *(undefined4 *)(puVar2 + 2) = 0;
      portSyncRwLockDestroy(*puVar2);
      _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x18),puVar2);
      uVar7 = uVar7 & 0xffffffff;
    }
    *param_7 = 0;
  }
  puVar2 = (undefined8 *)*param_8;
  if (puVar2 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)((long)puVar2 + 0x24);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 == 0) {
      puVar2[1] = 0;
      *(undefined4 *)(puVar2 + 2) = 0;
      portSyncRwLockDestroy(*puVar2);
      _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x18),puVar2);
      uVar7 = uVar7 & 0xffffffff;
    }
    *param_8 = 0;
    return uVar7;
  }
  return uVar7;
}


// ===== 0051d8e0 serverConstruct =====

undefined4 serverConstruct(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar2 = portMemAllocatorCreateNonPaged();
  *param_1 = param_2;
  *(long *)(param_1 + 6) = lVar2;
  *(undefined8 *)(param_1 + 0x2a) = 0xc1d00000c1e00000;
  *(undefined1 *)(param_1 + 5) = 1;
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined1 *)((long)param_1 + 0x43) = 1;
  *(undefined8 *)(param_1 + 0x12) = 0xffffffffffffffff;
  LOCK();
  param_1[0x2c] = 0;
  UNLOCK();
  LOCK();
  *(undefined8 *)(param_1 + 0x2e) = 0;
  UNLOCK();
  param_1[0x14] = 0;
  lVar3 = _portMemAllocatorAlloc(lVar2,0x6000);
  *(long *)(param_1 + 2) = lVar3;
  if (lVar3 != 0) {
    lVar5 = 0;
    while( true ) {
      lVar3 = lVar3 + lVar5;
      lVar5 = lVar5 + 0x18;
      listInitIntrusive_IMPL(lVar3,0x30);
      if (lVar5 == 0x6000) break;
      lVar3 = *(long *)(param_1 + 2);
    }
    param_1[4] = 0;
    lVar3 = portSyncSpinlockCreate(lVar2);
    *(long *)(param_1 + 8) = lVar3;
    if (lVar3 == 0) goto LAB_0051da57;
    uVar4 = portSyncSpinlockCreate(lVar2);
    *(undefined8 *)(param_1 + 10) = uVar4;
    mapInitIntrusive_IMPL(param_1 + 0xc,0x50);
    listInit_IMPL(param_1 + 0x16,lVar2,0xc);
    listInit_IMPL(param_1 + 0x20,lVar2,0xc);
    iVar1 = serverInitGlobalSharePolicies(param_1);
    if (iVar1 == 0) {
      listInitIntrusive_IMPL(param_1 + 0x30,0xe0);
      uVar4 = portSyncSpinlockCreate(lVar2);
      *(undefined8 *)(param_1 + 0x38) = uVar4;
      return 0;
    }
    mapDestroyIntrusive_IMPL(param_1 + 0xc);
    listDestroy_IMPL(param_1 + 0x16);
    listDestroy_IMPL(param_1 + 0x20);
  }
  if (*(long *)(param_1 + 8) != 0) {
    portSyncSpinlockDestroy();
  }
LAB_0051da57:
  if (*(long *)(param_1 + 10) != 0) {
    portSyncSpinlockDestroy();
  }
  lVar3 = *(long *)(param_1 + 2);
  if (lVar3 != 0) {
    lVar5 = 0;
    do {
      lVar3 = lVar3 + lVar5;
      lVar5 = lVar5 + 0x18;
      listDestroyIntrusive_IMPL(lVar3);
      lVar3 = *(long *)(param_1 + 2);
    } while (lVar5 != 0x6000);
    _portMemAllocatorFree(lVar2,lVar3);
  }
  if (lVar2 != 0) {
    portMemAllocatorRelease(lVar2);
  }
  return 0x1a;
}


// ===== 0051dad0 serverSetClientHandleBase =====

int serverSetClientHandleBase(long param_1,int param_2)

{
  int iVar1;
  undefined4 local_6c;
  undefined1 local_68 [72];
  
  local_6c = 0;
  portMemSet(local_68,0,0x40);
  iVar1 = serverTopLock_Prologue(param_1,1,local_68,&local_6c);
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0xa8) == param_2) {
      nvDbg_Printf("src/libraries/resserv/src/rs_server.c",0x1ed,"serverSetClientHandleBase",4,
                   "NVRM: Error setting fixed Client handle base\n");
    }
    else {
      *(int *)(param_1 + 0xac) = param_2;
    }
    serverTopLock_Epilogue(param_1,1,local_68,&local_6c);
    return 0;
  }
  nvAssertOkFailedNoLog
            (iVar1,"serverTopLock_Prologue(pServer, LOCK_ACCESS_WRITE, &lockInfo, &releaseFlags)",
             "src/libraries/resserv/src/rs_server.c",0x1e4);
  return iVar1;
}


// ===== 0051dbb0 serverAllocClient =====

int serverAllocClient(long param_1,uint *param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  long *plVar6;
  uint uVar7;
  uint local_60;
  uint local_50;
  uint local_4c;
  long local_48;
  long local_40 [2];
  
  local_48 = 0;
  if (*(char *)(param_1 + 0x14) == '\0') {
    return 0x55;
  }
  uVar7 = *param_2;
  local_50 = uVar7;
  uVar3 = serverAllocClientHandleBase
                    (param_1,(byte)param_2[0xd] >> 5 & 1,*(undefined8 *)(param_2 + 0xe));
  lVar5 = portSyncRwLockCreate(*(undefined8 *)(param_1 + 0x18));
  if (lVar5 == 0) {
    return 0x1a;
  }
  plVar6 = (long *)_portMemAllocatorAlloc(*(undefined8 *)(param_1 + 0x18),0x40);
  if (plVar6 == (long *)0x0) {
    iVar4 = 0x1a;
    goto LAB_0051dcee;
  }
  portMemSet(plVar6,0,0x40);
  *plVar6 = lVar5;
  portSyncSpinlockAcquire(*(undefined8 *)(param_1 + 0x20));
  if (uVar7 == 0) {
    uVar7 = *(uint *)(param_1 + 0x10);
    local_60 = uVar7 & 0x3ff;
    do {
      local_50 = uVar3 | uVar7;
      uVar7 = uVar7 + 1;
      if (uVar7 < 0x100000) {
        if ((uVar7 & 0x3ff) == local_60) goto LAB_0051dcc6;
      }
      else {
        uVar7 = 0;
        if (local_60 == 0) goto LAB_0051dcc6;
      }
      iVar4 = _serverFindNextAvailableClientHandleInBucket_isra_0
                        (*(undefined8 *)(param_1 + 8),local_50,&local_50,local_40);
    } while (iVar4 != 0);
    *(uint *)(param_1 + 0x10) = uVar7;
    uVar7 = local_50;
LAB_0051ddc8:
    piVar1 = (int *)((long)plVar6 + 0x24);
    *(uint *)(plVar6 + 2) = uVar7;
    *plVar6 = lVar5;
    LOCK();
    *piVar1 = 1;
    UNLOCK();
    *(undefined1 *)(plVar6 + 5) = 0;
    if (*(uint *)(plVar6 + 2) != 0) {
      lVar5 = *(long *)(param_1 + 8) + (ulong)(*(uint *)(plVar6 + 2) & 0x3ff) * 0x18;
      if (local_40[0] == 0) {
        listAppendExisting_IMPL(lVar5,plVar6);
      }
      else {
        listInsertExisting_IMPL(lVar5,local_40[0],plVar6);
      }
      if ((char)plVar6[5] != '\0') {
        nvAssertFailedNoLog("!pClientEntry->bPendingFree","src/libraries/resserv/src/rs_server.c",
                            0xc7c);
      }
      LOCK();
      *(int *)((long)plVar6 + 0x24) = *(int *)((long)plVar6 + 0x24) + 1;
      UNLOCK();
      portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x20));
      portSyncRwLockAcquireWrite(*plVar6);
      lVar5 = portThreadGetCurrentThreadId();
      uVar7 = local_50;
      plVar6[3] = lVar5;
      *param_2 = local_50;
      param_2[2] = local_50;
      iVar4 = resservClientFactory(*(undefined8 *)(param_1 + 0x18),param_2,&local_48);
      if (iVar4 == 0) {
        iVar4 = clientAllocResource_IMPL(local_48,param_1,param_2);
        if (iVar4 == 0) {
          portSyncSpinlockAcquire(*(undefined8 *)(param_1 + 0x20));
          plVar6[1] = local_48;
          LOCK();
          *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0xb0) + 1;
          UNLOCK();
          portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x20));
          plVar6[3] = -1;
          portSyncRwLockReleaseWrite(*plVar6);
          goto LAB_0051decd;
        }
        plVar6[3] = -1;
        portSyncRwLockReleaseWrite(*plVar6);
      }
      else {
        plVar6[3] = -1;
        iVar4 = 0x1a;
        portSyncRwLockReleaseWrite(*plVar6);
      }
      portSyncSpinlockAcquire(*(undefined8 *)(param_1 + 0x20));
      listRemoveIntrusive_IMPL(*(long *)(param_1 + 8) + (ulong)(uVar7 & 0x3ff) * 0x18,plVar6);
      portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x20));
      LOCK();
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (*piVar1 == 0) {
        plVar6[1] = 0;
        *(undefined4 *)(plVar6 + 2) = 0;
        portSyncRwLockDestroy(*plVar6);
        _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x18),plVar6);
      }
      __nvoc_objDelete(local_48);
LAB_0051decd:
      LOCK();
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (*piVar1 == 0) {
        plVar6[1] = 0;
        *(undefined4 *)(plVar6 + 2) = 0;
        portSyncRwLockDestroy(*plVar6);
        _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x18),plVar6);
        return iVar4;
      }
      return iVar4;
    }
    iVar4 = 0x33;
  }
  else {
    local_4c = 0;
    iVar4 = 0x19;
    cVar2 = __serverFindClientEntryByHandle(param_1,uVar7,3,0,0,0);
    if (cVar2 == '\0') {
      iVar4 = _serverFindNextAvailableClientHandleInBucket_isra_0
                        (*(undefined8 *)(param_1 + 8),uVar7,&local_4c,local_40);
      if (iVar4 == 0) {
        if (uVar7 == local_4c) goto LAB_0051ddc8;
        iVar4 = 0x40;
        nvDbg_Printf("src/libraries/resserv/src/rs_server.c",0xd28,
                     "_serverCreateEntryAndLockForNewClient",4,
                     "NVRM: Client handle mismatch: %x != %x.\n",uVar7,local_4c);
      }
      else {
LAB_0051dcc6:
        iVar4 = 0x1a;
      }
    }
  }
  portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x20));
  _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x18),plVar6);
LAB_0051dcee:
  portSyncRwLockDestroy(lVar5);
  return iVar4;
}


// ===== 0051e010 serverAllocResource =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong serverAllocResource(long param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  ulong uVar9;
  bool bVar10;
  long lVar11;
  long *plVar12;
  undefined4 local_cc;
  undefined4 local_c8;
  int local_c4;
  undefined8 local_c0;
  long local_b8;
  long local_b0;
  undefined8 local_a8 [15];
  ulong uVar8;
  
  local_cc = 0;
  local_b8 = 0;
  local_b0 = 0;
  uVar1 = param_2[3];
  uVar9 = 0;
  do {
    uVar5 = (int)uVar9 + 0x20;
    uVar8 = (ulong)uVar5;
    *(undefined8 *)((long)local_a8 + uVar9) = 0;
    *(undefined8 *)((long)local_a8 + uVar9 + 8) = 0;
    *(undefined8 *)((long)local_a8 + uVar9 + 0x10) = 0;
    *(undefined8 *)((long)local_a8 + uVar9 + 0x18) = 0;
    uVar9 = uVar8;
  } while (uVar5 < 0x60);
  *(undefined8 *)((long)local_a8 + uVar8) = 0;
  *(undefined8 *)((long)local_a8 + uVar8 + 8) = 0;
  if (*(char *)(param_1 + 0x14) == '\0') {
    return 0x55;
  }
  lVar3 = *(long *)(param_2 + 6);
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pLockInfo != NULL","src/libraries/resserv/src/rs_server.c",0x2e7);
    return 0x1f;
  }
  iVar2 = *(int *)(lVar3 + 0x2c);
  uVar9 = serverAllocApiCopyIn(param_1,param_2,&local_c0);
  if ((int)uVar9 != 0) {
    return uVar9;
  }
  bVar10 = uVar1 == 0x41 || uVar1 < 2;
  iVar6 = serverAllocResourceLookupLockFlags(param_1,1,param_2,&local_c8);
  if ((iVar6 == 0) && (iVar6 = serverTopLock_Prologue(param_1,local_c8,lVar3,&local_cc), iVar6 == 0)
     ) {
    iVar6 = serverDeserializeAllocDown
                      (local_a8,param_2[3],param_2 + 0x10,param_2 + 0x12,param_2 + 0xc);
    if (iVar6 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar6,
                 "serverDeserializeAllocDown(&callContext, pParams->externalClassId, &pParams->pAllocParams, &pParams->paramsSize, &pParams->allocFlags)"
                 ,"src/libraries/resserv/src/rs_server.c",0x2f8);
      goto LAB_0051e137;
    }
    if (bVar10) {
      iVar6 = serverAllocClient(param_1,param_2);
LAB_0051e300:
      if (iVar6 != 0) {
        nvDbg_Printf("src/libraries/resserv/src/rs_server.c",0x343,"serverAllocResource",1,
                     "NVRM: hParent 0x%08x : hClass 0x%08x allocation failed\n",param_2[1],
                     param_2[3]);
      }
      iVar6 = serverAllocEpilogue_WAR(param_1,iVar6,bVar10,param_2);
      goto LAB_0051e137;
    }
    iVar6 = serverAllocLookupSecondClient(param_2[3],*(undefined8 *)(param_2 + 0x10),&local_c4);
    if (iVar6 != 0) goto LAB_0051e144;
    if (local_c4 != 0) {
      plVar12 = &local_b8;
      iVar6 = _serverLockDualClientWithLockInfo_constprop_0
                        (param_1,*param_2,local_c4,1,lVar3,&local_cc,plVar12,&local_b0);
      lVar11 = local_b8;
      if (iVar6 == 0) {
        if (local_b8 == 0) {
          nvAssertFailedNoLog("pClientEntry != NULL","src/libraries/resserv/src/rs_server.c",0xe93,
                              plVar12);
LAB_0051e4fc:
          lVar4 = local_b0;
          if (local_b0 == 0) {
            nvAssertFailedNoLog("pClientEntry != NULL","src/libraries/resserv/src/rs_server.c",0xe93
                               );
          }
          else if (*(int *)(local_b0 + 0x20) != 0) goto LAB_0051e326;
          if ((*(char *)(*(long *)(lVar11 + 8) + 0x50) == '\0') ||
             (*(char *)(*(long *)(lVar4 + 8) + 0x50) == '\0')) goto LAB_0051e52f;
          goto LAB_0051e2b0;
        }
        if (*(int *)(local_b8 + 0x20) == 0) goto LAB_0051e4fc;
LAB_0051e326:
        nvAssertFailedNoLog("(!serverIsClientLockedForRead((pClientEntry)) && !serverIsClientLockedForRead((pSecondClientEntry)))"
                            ,"src/libraries/resserv/src/rs_server.c",0x327);
LAB_0051e33e:
        iVar6 = 0x2f;
      }
      goto LAB_0051e350;
    }
    iVar6 = _serverLockClientWithLockInfo_constprop_0(param_1,*param_2,1,lVar3,&local_cc,&local_b8);
    if (iVar6 == 0) {
      if (local_b8 != 0) {
        if (*(int *)(local_b8 + 0x20) != 0) {
          nvAssertFailedNoLog("!serverIsClientLockedForRead(pClientEntry)",
                              "src/libraries/resserv/src/rs_server.c",0x312);
          goto LAB_0051e33e;
        }
        if (*(char *)(*(long *)(local_b8 + 8) + 0x50) != '\0') goto LAB_0051e2b0;
LAB_0051e52f:
        iVar6 = 0x40;
        goto LAB_0051e350;
      }
      nvAssertFailedNoLog("pClientEntry != NULL","src/libraries/resserv/src/rs_server.c",0xe93);
      if (*(char *)(_DAT_00000008 + 0x50) == '\0') {
        iVar6 = 0x40;
        goto LAB_0051e144;
      }
LAB_0051e2b0:
      lVar11 = local_b8;
      plVar12 = *(long **)(local_b8 + 8);
      *(long **)(param_2 + 8) = plVar12;
      iVar6 = (**(code **)(*plVar12 + 0x30))(plVar12,*(undefined8 *)(param_2 + 0xe));
      if (iVar6 == 0) {
        iVar6 = serverAllocResourceUnderLock(param_1,param_2);
        goto LAB_0051e300;
      }
      goto LAB_0051e360;
    }
    lVar11 = local_b8;
    if (local_b8 == 0) goto LAB_0051e144;
  }
  else {
LAB_0051e137:
    if (uVar1 == 0x41 || uVar1 < 2) goto LAB_0051e144;
LAB_0051e350:
    lVar11 = local_b8;
    if (local_b8 == 0) goto LAB_0051e144;
LAB_0051e360:
    if (local_b0 != 0) {
      _serverUnlockDualClientWithLockInfo_constprop_0(param_1,lVar11,local_b0,lVar3,&local_cc);
      goto LAB_0051e144;
    }
  }
  _serverUnlockClientWithLockInfo_constprop_0(param_1,lVar11,lVar3,&local_cc);
LAB_0051e144:
  iVar7 = serverSerializeAllocUp(local_a8,param_2[3],param_2 + 0x10,param_2 + 0x12,param_2 + 0xc);
  if ((iVar7 != 0) &&
     (nvCheckOkFailedNoLog
                (4,iVar7,
                 "serverSerializeAllocUp(&callContext, pParams->externalClassId, &pParams->pAllocParams, &pParams->paramsSize, &pParams->allocFlags)"
                 ,"src/libraries/resserv/src/rs_server.c",0x35f), iVar6 == 0)) {
    iVar6 = iVar7;
  }
  serverFreeSerializeStructures(local_a8,*(undefined8 *)(param_2 + 0x10));
  serverTopLock_Epilogue(param_1,local_c8,lVar3,&local_cc);
  uVar9 = serverAllocApiCopyOut(param_1,iVar6,local_c0);
  if (*(int *)(lVar3 + 0x2c) != iVar2) {
    nvAssertFailedNoLog("pLockInfo->state == initialLockState",
                        "src/libraries/resserv/src/rs_server.c",0x368);
    uVar9 = uVar9 & 0xffffffff;
  }
  return uVar9;
}


// ===== 0051e600 clientUpdatePendingFreeList_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 clientUpdatePendingFreeList_IMPL(long param_1,long param_2,long param_3,char param_4)

{
  undefined8 *puVar1;
  long *plVar2;
  char cVar3;
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  cVar3 = refPendingFree(param_2,param_1);
  if (param_4 == '\0') {
    if (cVar3 == '\0') {
      listPrependExisting_IMPL(param_1 + 0xc0,param_2);
    }
  }
  else {
    if (param_2 != param_3) {
      for (puVar1 = *(undefined8 **)(param_1 + 0xd8); puVar1 != (undefined8 *)0x0;
          puVar1 = (undefined8 *)*puVar1) {
        if (param_2 == puVar1[1]) {
          nvAssertFailedNoLog("pFsRef != pTargetRef","src/libraries/resserv/src/rs_server.c",0x3b5);
          return 0;
        }
      }
    }
    if (cVar3 != '\0') {
      listRemoveIntrusive_IMPL(param_1 + 0xc0,param_2);
    }
    listPrependExisting_IMPL(param_1 + 0xc0,param_2);
  }
  indexRefIterAll(&local_68,param_2 + 0x20);
  local_48 = local_68;
  local_40 = local_60;
  local_38 = local_58;
  local_30 = local_50;
  cVar3 = indexRefIterNext(&local_48);
  while (cVar3 != '\0') {
    clientUpdatePendingFreeList_IMPL(param_1,*local_48,param_3,1);
    cVar3 = indexRefIterNext(&local_48);
  }
  indexRefIterAll(&local_68,param_2 + 0x80);
  local_48 = local_68;
  local_40 = local_60;
  local_38 = local_58;
  local_30 = local_50;
  cVar3 = indexRefIterNext(&local_48);
  while (cVar3 != '\0') {
    clientUpdatePendingFreeList_IMPL(param_1,*local_48,param_3,1);
    cVar3 = indexRefIterNext(&local_48);
  }
  plVar2 = *(long **)(param_2 + 8);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0xb8))(param_1,plVar2,param_3);
  }
  return 0;
}


// ===== 0051e7e0 serverCopyResource =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int serverCopyResource(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  char cVar7;
  int iVar8;
  undefined8 uVar9;
  undefined4 local_58;
  undefined4 local_54;
  long local_50;
  long local_48;
  long local_40 [2];
  
  lVar3 = *(long *)(param_2 + 0x14);
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  if (*(char *)(param_1 + 0x14) == '\0') {
    return 0x55;
  }
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pLockInfo != NULL","src/libraries/resserv/src/rs_server.c",0x680);
    return 0x1f;
  }
  uVar1 = *param_2;
  uVar2 = param_2[2];
  iVar8 = serverCopyResourceLookupLockFlags(param_1,1,param_2,&local_54);
  if ((iVar8 != 0) || (iVar8 = serverTopLock_Prologue(param_1,local_54,lVar3,&local_58), iVar8 != 0)
     ) {
    serverResLock_Epilogue(param_1,1,*(undefined8 *)(param_2 + 0x14),&local_58);
    goto LAB_0051e871;
  }
  iVar8 = _serverLockDualClientWithLockInfo_constprop_0
                    (param_1,uVar1,uVar2,1,lVar3,&local_58,&local_50);
  lVar4 = local_50;
  if (iVar8 == 0) {
    if (local_50 == 0) {
      nvAssertFailedNoLog("pClientEntry != NULL","src/libraries/resserv/src/rs_server.c",0xe93);
LAB_0051e902:
      lVar6 = local_48;
      if (local_48 == 0) {
        nvAssertFailedNoLog("pClientEntry != NULL","src/libraries/resserv/src/rs_server.c",0xe93);
      }
      else if (*(int *)(local_48 + 0x20) != 0) goto LAB_0051ea30;
      lVar4 = *(long *)(lVar4 + 8);
      if ((*(char *)(lVar4 + 0x50) == '\0') ||
         (plVar5 = *(long **)(lVar6 + 8), (char)plVar5[10] == '\0')) {
        iVar8 = 0x40;
      }
      else {
        iVar8 = (**(code **)(*plVar5 + 0x30))(plVar5,*(undefined8 *)(param_2 + 0x12));
        if (iVar8 == 0) {
          iVar8 = clientGetResourceRef_IMPL(lVar4,param_2[1],local_40);
          if (iVar8 == 0) {
            if (*(char *)(local_40[0] + 0x124) == '\0') {
              iVar8 = clientGetResourceRef_IMPL(plVar5,param_2[3],param_2 + 0x10);
              if (iVar8 != 0) {
                uVar1 = param_2[2];
                uVar9 = 0x6b3;
                uVar2 = param_2[3];
                goto LAB_0051ebbc;
              }
              cVar7 = (**(code **)(**(long **)(local_40[0] + 8) + 0x30))();
              if (cVar7 == '\0') {
                iVar8 = 0x1f;
              }
              else {
                iVar8 = clientAssignResourceHandle_IMPL(plVar5,param_2 + 4);
                if (iVar8 == 0) {
                  *(long *)(param_2 + 10) = lVar4;
                  *(long **)(param_2 + 0xc) = plVar5;
                  *(long *)(param_2 + 0xe) = local_40[0];
                  iVar8 = serverUpdateLockFlagsForCopy(param_1,param_2);
                  if ((iVar8 == 0) &&
                     (iVar8 = serverResLock_Prologue
                                        (param_1,1,*(undefined8 *)(param_2 + 0x14),&local_58,0),
                     iVar8 == 0)) {
                    iVar8 = clientCopyResource_IMPL(plVar5,param_1,param_2);
                  }
                }
              }
            }
            else {
              iVar8 = 0x6e;
            }
          }
          else {
            uVar1 = *param_2;
            uVar9 = 0x6a6;
            uVar2 = param_2[1];
LAB_0051ebbc:
            nvDbg_Printf("src/libraries/resserv/src/rs_server.c",uVar9,"serverCopyResource",2,
                         "NVRM: Failed to find handle 0x%x under client 0x%x\n",uVar2,uVar1);
          }
        }
      }
    }
    else {
      if (*(int *)(local_50 + 0x20) == 0) goto LAB_0051e902;
LAB_0051ea30:
      iVar8 = 0x2f;
      nvAssertFailedNoLog("(!serverIsClientLockedForRead((pClientEntrySrc)) && !serverIsClientLockedForRead((pClientEntryDst)))"
                          ,"src/libraries/resserv/src/rs_server.c",0x691);
    }
  }
  lVar4 = local_50;
  serverResLock_Epilogue(param_1,1,*(undefined8 *)(param_2 + 0x14),&local_58);
  if ((lVar4 != 0) && (local_48 != 0)) {
    _serverUnlockDualClientWithLockInfo_constprop_0(param_1,lVar4,local_48,lVar3,&local_58);
  }
LAB_0051e871:
  serverTopLock_Epilogue(param_1,local_54,lVar3,&local_58);
  return iVar8;
}


// ===== 0051ec00 serverShareResourceAccess =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int serverShareResourceAccess(long param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  int iVar6;
  int iVar7;
  long *plVar8;
  long *plVar9;
  long lVar10;
  undefined4 *puVar11;
  undefined8 *puVar12;
  byte bVar13;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  long local_c8;
  long local_c0;
  ulong local_b8;
  long local_b0;
  long local_a8;
  long *local_a0;
  long local_98;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  long local_60;
  
  bVar13 = 0;
  local_d4 = 0;
  local_c8 = 0;
  if (*(char *)(param_1 + 0x14) == '\0') {
    return 0x55;
  }
  if (*(char *)(param_1 + 0x43) == '\0') {
    return 0x6d;
  }
  piVar2 = *(int **)(param_2 + 2);
  if ((piVar2 == (int *)0x0) || (7 < *(ushort *)(piVar2 + 2))) {
    return 0x1f;
  }
  lVar3 = *(long *)(param_2 + 6);
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pLockInfo != NULL","src/libraries/resserv/src/rs_server.c",0x773);
    return 0x1f;
  }
  if (*(ushort *)(piVar2 + 2) != 3) {
    iVar6 = serverShareResourceLookupLockFlags(param_1,1,param_2,&local_b8);
    if ((iVar6 != 0) ||
       (iVar6 = serverTopLock_Prologue(param_1,local_b8 & 0xffffffff,lVar3,&local_d4), iVar6 != 0))
    goto LAB_0051ec9f;
    iVar6 = _serverLockClientWithLockInfo_constprop_0(param_1,*param_2,1,lVar3,&local_d4,&local_c8);
    lVar10 = local_c8;
    if (iVar6 == 0) {
      if (local_c8 == 0) {
        nvAssertFailedNoLog("pClientEntry != NULL","src/libraries/resserv/src/rs_server.c",0xe93);
      }
      else if (*(int *)(local_c8 + 0x20) != 0) {
        nvAssertFailedNoLog("!serverIsClientLockedForRead(pClientEntry)",
                            "src/libraries/resserv/src/rs_server.c",0x788);
        iVar6 = 0x2f;
        goto LAB_0051ed60;
      }
      plVar9 = *(long **)(lVar10 + 8);
      iVar6 = (**(code **)(*plVar9 + 0x30))(plVar9,*(undefined8 *)(param_2 + 4));
      if (((iVar6 == 0) &&
          (iVar6 = clientGetResourceRef_IMPL(plVar9,param_2[1],&local_b0), iVar6 == 0)) &&
         (iVar6 = 0x6e, *(char *)(local_b0 + 0x124) == '\0')) {
        portMemSet(&local_a8,0,0x70);
        local_98 = local_b0;
        puVar12 = *(undefined8 **)(param_2 + 4);
        local_80 = *puVar12;
        local_78 = puVar12[1];
        local_70 = puVar12[2];
        local_68 = puVar12[3];
        local_88 = *(undefined8 *)(param_2 + 6);
        local_a8 = param_1;
        local_a0 = plVar9;
        plVar8 = (long *)tlsEntryAcquire(1);
        if (plVar8 == (long *)0x0) {
          nvAssertOkFailedNoLog
                    (0x40,"resservSwapTlsCallContext(&pOldContext, &callContext)",
                     "src/libraries/resserv/src/rs_server.c",0x7a2);
          iVar6 = 0x40;
        }
        else {
          lVar10 = *plVar8;
          *plVar8 = (long)&local_a8;
          if (((lVar10 != 0) && (local_60 != 0)) && (*(long *)(lVar10 + 0x48) != 0)) {
            *(byte *)(local_60 + 0x69) =
                 *(byte *)(local_60 + 0x69) | *(byte *)(*(long *)(lVar10 + 0x48) + 0x69);
          }
          iVar6 = (**(code **)(*plVar9 + 0x88))
                            (plVar9,local_b0,*(undefined8 *)(param_2 + 2),&local_a8);
          plVar9 = (long *)tlsEntryAcquire(1);
          if (plVar9 == (long *)0x0) {
            nvAssertOkFailedNoLog
                      (0x1f,"resservRestoreTlsCallContext(pOldContext)",
                       "src/libraries/resserv/src/rs_server.c",0x7a6);
          }
          else {
            *plVar9 = lVar10;
            tlsEntryRelease(1);
            tlsEntryRelease(1);
          }
        }
      }
    }
LAB_0051ed60:
    if (local_c8 != 0) {
      _serverUnlockClientWithLockInfo_constprop_0(param_1,local_c8,lVar3,&local_d4);
    }
LAB_0051ec9f:
    serverTopLock_Epilogue(param_1,local_b8 & 0xffffffff,lVar3,&local_d4);
    return iVar6;
  }
  iVar6 = *param_2;
  local_d0 = 0;
  local_b8 = 0;
  iVar1 = *piVar2;
  local_c0 = 0;
  iVar7 = serverShareResourceLookupLockFlags(param_1,1,param_2,&local_cc);
  if ((iVar7 != 0) || (iVar7 = serverTopLock_Prologue(param_1,local_cc,lVar3,&local_d0), iVar7 != 0)
     ) goto LAB_0051ede1;
  iVar7 = _serverLockDualClientWithLockInfo_constprop_0
                    (param_1,iVar6,iVar1,1,lVar3,&local_d0,&local_c0,&local_b8);
  lVar10 = local_c0;
  if (iVar7 == 0) {
    if (local_c0 == 0) {
      nvAssertFailedNoLog("pClientEntry != NULL","src/libraries/resserv/src/rs_server.c",0xe93);
LAB_0051ee8d:
      uVar5 = local_b8;
      if (local_b8 == 0) {
        nvAssertFailedNoLog("pClientEntry != NULL","src/libraries/resserv/src/rs_server.c",0xe93);
      }
      else if (*(int *)(local_b8 + 0x20) != 0) goto LAB_0051eea8;
      plVar9 = *(long **)(lVar10 + 8);
      uVar4 = *(undefined8 *)(uVar5 + 8);
      iVar7 = clientGetResourceRef_IMPL(plVar9,param_2[1],&local_b0);
      if ((iVar7 == 0) && (iVar7 = 0x6e, *(char *)(local_b0 + 0x124) == '\0')) {
        portMemSet(&local_a8,0,0x70);
        local_98 = local_b0;
        local_88 = *(undefined8 *)(param_2 + 6);
        puVar11 = *(undefined4 **)(param_2 + 4);
        puVar12 = &local_80;
        for (lVar10 = 8; lVar10 != 0; lVar10 = lVar10 + -1) {
          *(undefined4 *)puVar12 = *puVar11;
          puVar11 = puVar11 + (ulong)bVar13 * -2 + 1;
          puVar12 = (undefined8 *)((long)puVar12 + (ulong)bVar13 * -8 + 4);
        }
        local_a8 = param_1;
        local_a0 = plVar9;
        plVar8 = (long *)tlsEntryAcquire(1);
        if (plVar8 == (long *)0x0) {
          nvAssertOkFailedNoLog
                    (0x40,"resservSwapTlsCallContext(&pOldContext, &callContext)",
                     "src/libraries/resserv/src/rs_server.c",0x729);
          iVar7 = 0x40;
        }
        else {
          lVar10 = *plVar8;
          *plVar8 = (long)&local_a8;
          if (((lVar10 != 0) && (local_60 != 0)) && (*(long *)(lVar10 + 0x48) != 0)) {
            *(byte *)(local_60 + 0x69) =
                 *(byte *)(local_60 + 0x69) | *(byte *)(*(long *)(lVar10 + 0x48) + 0x69);
          }
          if (((iVar6 != iVar1) ||
              (iVar7 = clientShareResourceTargetClient_IMPL
                                 (plVar9,local_b0,*(undefined8 *)(param_2 + 2),&local_a8),
              iVar7 == 0)) && (iVar7 = clientAddAccessBackRef_IMPL(uVar4,local_b0), iVar7 == 0)) {
            iVar7 = (**(code **)(*plVar9 + 0x88))
                              (plVar9,local_b0,*(undefined8 *)(param_2 + 2),&local_a8);
          }
          plVar9 = (long *)tlsEntryAcquire(1);
          if (plVar9 == (long *)0x0) {
            nvAssertOkFailedNoLog
                      (0x1f,"resservRestoreTlsCallContext(pOldContext)",
                       "src/libraries/resserv/src/rs_server.c",0x741);
          }
          else {
            *plVar9 = lVar10;
            tlsEntryRelease(1);
            tlsEntryRelease(1);
          }
        }
      }
    }
    else {
      if (*(int *)(local_c0 + 0x20) == 0) goto LAB_0051ee8d;
LAB_0051eea8:
      nvAssertFailedNoLog("(!serverIsClientLockedForRead((pClientEntryOwner)) && !serverIsClientLockedForRead((pClientEntryTarget)))"
                          ,"src/libraries/resserv/src/rs_server.c",0x711);
      iVar7 = 0x2f;
    }
  }
  if ((local_c0 != 0) && (local_b8 != 0)) {
    _serverUnlockDualClientWithLockInfo_constprop_0(param_1,local_c0,local_b8,lVar3,&local_d0);
  }
LAB_0051ede1:
  serverTopLock_Epilogue(param_1,local_cc,lVar3,&local_d0);
  return iVar7;
}


// ===== 0051f3c0 serverMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong serverMap(undefined8 param_1,undefined4 param_2,undefined4 param_3,long param_4)

{
  long lVar1;
  long *plVar2;
  undefined8 *puVar3;
  long lVar4;
  uint uVar5;
  ulong uVar6;
  long *plVar7;
  ulong uVar8;
  ulong extraout_RDX;
  ulong extraout_RDX_00;
  ulong extraout_RDX_01;
  ulong extraout_RDX_02;
  ulong extraout_RDX_03;
  ulong extraout_RDX_04;
  ulong extraout_RDX_05;
  ulong extraout_RDX_06;
  ulong extraout_RDX_07;
  ulong extraout_RDX_08;
  ulong extraout_RDX_09;
  ulong extraout_RDX_10;
  ulong uVar9;
  long lVar10;
  undefined4 local_d0;
  undefined4 local_cc;
  long local_c8;
  long local_c0;
  undefined8 local_b8;
  long local_b0;
  undefined1 local_a8 [8];
  long *local_a0;
  long local_98;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  long local_60;
  
  lVar1 = *(long *)(param_4 + 0x38);
  local_c8 = 0;
  local_c0 = 0;
  local_b8 = 0;
  local_b0 = 0;
  local_d0 = 0;
  local_cc = 1;
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pLockInfo != NULL","src/libraries/resserv/src/rs_server.c",1999);
    uVar8 = extraout_RDX_08;
LAB_0051f7cf:
    uVar9 = 0x40;
  }
  else {
    uVar5 = serverMapLookupLockFlags(param_1,1,param_4,&local_cc);
    uVar9 = (ulong)uVar5;
    uVar8 = extraout_RDX;
    if (uVar5 == 0) {
      uVar5 = serverTopLock_Prologue(param_1,local_cc,lVar1,&local_d0);
      uVar9 = (ulong)uVar5;
      uVar8 = extraout_RDX_00;
      if (uVar5 == 0) {
        uVar5 = _serverLockClientWithLockInfo_constprop_0
                          (param_1,param_2,1,lVar1,&local_d0,&local_c8);
        lVar10 = local_c8;
        uVar9 = (ulong)uVar5;
        uVar8 = extraout_RDX_01;
        if (uVar5 == 0) {
          plVar7 = *(long **)(local_c8 + 8);
          if ((char)plVar7[10] == '\0') goto LAB_0051f7cf;
          uVar5 = (**(code **)(*plVar7 + 0x30))(plVar7,*(undefined8 *)(param_4 + 0x40));
          uVar9 = (ulong)uVar5;
          uVar8 = extraout_RDX_02;
          if (uVar5 == 0) {
            uVar5 = clientGetResourceRef_IMPL(plVar7,param_3,&local_c0);
            uVar9 = (ulong)uVar5;
            uVar8 = extraout_RDX_03;
            if (uVar5 == 0) {
              plVar2 = *(long **)(local_c0 + 8);
              if (plVar2 == (long *)0x0) {
                uVar9 = 0x56;
              }
              else {
                uVar5 = serverMap_Prologue(param_1,param_4);
                uVar9 = (ulong)uVar5;
                uVar8 = extraout_RDX_04;
                if (uVar5 == 0) {
                  uVar5 = serverResLock_Prologue(param_1,1,lVar1,&local_d0,0);
                  uVar9 = (ulong)uVar5;
                  uVar8 = extraout_RDX_05;
                  if (uVar5 == 0) {
                    if (*(int *)(param_4 + 0x34) != 0) {
                      uVar6 = clientGetResourceRef_IMPL(plVar7,*(int *)(param_4 + 0x34),&local_b8);
                      uVar9 = uVar6 & 0xffffffff;
                      if ((int)uVar6 != 0) {
                        uVar8 = (ulong)*(uint *)(param_4 + 0x34);
                        nvDbg_Printf("src/libraries/resserv/src/rs_server.c",0x802,"serverMap",1,
                                     "NVRM: hClient %x: Cannot find hContext: 0x%x\n",(int)plVar7[9]
                                     ,uVar8,uVar6);
                        goto LAB_0051f46b;
                      }
                    }
                    uVar5 = refAddMapping(local_c0,param_4,local_b8,&local_b0);
                    uVar9 = (ulong)uVar5;
                    uVar8 = extraout_RDX_06;
                    if (uVar5 == 0) {
                      portMemSet(local_a8,0,0x70);
                      local_98 = local_c0;
                      local_88 = *(undefined8 *)(param_4 + 0x38);
                      puVar3 = *(undefined8 **)(param_4 + 0x40);
                      if (puVar3 != (undefined8 *)0x0) {
                        local_80 = *puVar3;
                        local_78 = puVar3[1];
                        local_70 = puVar3[2];
                        local_68 = puVar3[3];
                      }
                      local_a0 = plVar7;
                      plVar7 = (long *)tlsEntryAcquire(1);
                      if (plVar7 == (long *)0x0) {
                        nvAssertOkFailedNoLog
                                  (0x40,"resservSwapTlsCallContext(&pOldContext, &callContext)",
                                   "src/libraries/resserv/src/rs_server.c",0x814);
                        uVar8 = extraout_RDX_10;
                        goto LAB_0051f7cf;
                      }
                      lVar4 = *plVar7;
                      *plVar7 = (long)local_a8;
                      if (((lVar4 != 0) && (local_60 != 0)) && (*(long *)(lVar4 + 0x48) != 0)) {
                        *(byte *)(local_60 + 0x69) =
                             *(byte *)(local_60 + 0x69) | *(byte *)(*(long *)(lVar4 + 0x48) + 0x69);
                      }
                      uVar5 = (**(code **)(*plVar2 + 0x78))(plVar2,local_a8,param_4,local_b0);
                      uVar9 = (ulong)uVar5;
                      plVar7 = (long *)tlsEntryAcquire(1);
                      if (plVar7 == (long *)0x0) {
                        nvAssertOkFailedNoLog
                                  (0x1f,"resservRestoreTlsCallContext(pOldContext)",
                                   "src/libraries/resserv/src/rs_server.c",0x818);
                        uVar8 = extraout_RDX_09;
                      }
                      else {
                        *plVar7 = lVar4;
                        tlsEntryRelease(1);
                        tlsEntryRelease(1);
                        uVar8 = extraout_RDX_07;
                      }
                      if (uVar5 == 0) {
                        if (*(undefined8 **)(param_4 + 0x20) != (undefined8 *)0x0) {
                          **(undefined8 **)(param_4 + 0x20) = *(undefined8 *)(local_b0 + 0x18);
                        }
                        goto LAB_0051f48a;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0051f46b:
  lVar10 = local_c8;
  if (local_b0 != 0) {
    refRemoveMapping(local_c0,local_b0,uVar8);
    lVar10 = local_c8;
  }
LAB_0051f48a:
  serverResLock_Epilogue(param_1,1,lVar1,&local_d0);
  if (lVar10 != 0) {
    _serverUnlockClientWithLockInfo_constprop_0(param_1,lVar10,lVar1,&local_d0);
  }
  serverTopLock_Epilogue(param_1,local_cc,lVar1,&local_d0);
  return uVar9;
}


// ===== 0051f890 serverUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int serverUnmap(undefined8 param_1,undefined4 param_2,undefined4 param_3,long param_4)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  int iVar4;
  undefined4 local_58;
  undefined4 local_54;
  long local_50;
  long local_48;
  undefined1 local_40 [16];
  
  lVar1 = *(long *)(param_4 + 0x38);
  local_50 = 0;
  local_58 = 0;
  local_54 = 1;
  if (lVar1 == 0) {
    iVar4 = 0x40;
    nvAssertFailedNoLog("pLockInfo != NULL","src/libraries/resserv/src/rs_server.c",0x849);
  }
  else {
    iVar4 = serverUnmapLookupLockFlags(param_1,1,param_4,&local_54);
    if (iVar4 == 0) {
      iVar4 = serverTopLock_Prologue(param_1,local_54,lVar1,&local_58);
      if (iVar4 == 0) {
        iVar4 = _serverLockClientWithLockInfo_constprop_0
                          (param_1,param_2,1,lVar1,&local_58,&local_50);
        lVar3 = local_50;
        if (iVar4 == 0) {
          plVar2 = *(long **)(local_50 + 8);
          iVar4 = (**(code **)(*plVar2 + 0x30))(plVar2,*(undefined8 *)(param_4 + 0x40));
          if (iVar4 == 0) {
            iVar4 = clientGetResourceRef_IMPL(plVar2,param_3,&local_48);
            if (iVar4 == 0) {
              if (*(long *)(local_48 + 8) == 0) {
                iVar4 = 0x56;
              }
              else {
                iVar4 = serverUnmap_Prologue(param_1,param_4);
                if (iVar4 == 0) {
                  iVar4 = refFindCpuMappingWithFilter
                                    (local_48,*(undefined8 *)(param_4 + 0x10),
                                     *(undefined8 *)(param_4 + 0x30),local_40);
                  if (iVar4 == 0) {
                    iVar4 = serverResLock_Prologue(param_1,1,lVar1,&local_58,0);
                    if (iVar4 == 0) {
                      iVar4 = (**(code **)(*plVar2 + 0x60))
                                        (plVar2,local_48,lVar1,local_40,
                                         *(undefined8 *)(param_4 + 0x40));
                    }
                  }
                }
              }
            }
            goto LAB_0051fa30;
          }
          serverUnmap_Epilogue(param_1,param_4);
          serverResLock_Epilogue(param_1,1,lVar1,&local_58);
        }
        else {
LAB_0051fa30:
          serverUnmap_Epilogue(param_1,param_4);
          serverResLock_Epilogue(param_1,1,lVar1,&local_58);
          if (lVar3 == 0) goto LAB_0051f90d;
        }
        _serverUnlockClientWithLockInfo_constprop_0(param_1,lVar3,lVar1,&local_58);
        goto LAB_0051f90d;
      }
    }
  }
  serverUnmap_Epilogue(param_1,param_4);
  serverResLock_Epilogue(param_1,1,lVar1,&local_58);
LAB_0051f90d:
  serverTopLock_Epilogue(param_1,local_54,lVar1,&local_58);
  return iVar4;
}


// ===== 0051fad0 serverInterMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int serverInterMap(undefined8 param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 *puVar2;
  long lVar3;
  int iVar4;
  long *plVar5;
  long *plVar6;
  long local_e0;
  undefined4 local_d8;
  undefined4 local_d4;
  long local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  long local_b0;
  undefined8 local_a8;
  long *local_a0;
  undefined8 local_98;
  undefined8 local_90;
  long local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  long local_60;
  
  lVar1 = *(long *)(param_2 + 0x10);
  local_d0 = 0;
  local_c8 = 0;
  local_b0 = 0;
  local_d4 = 0;
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pLockInfo != NULL","src/libraries/resserv/src/rs_server.c",0x89d);
    return 0x1f;
  }
  if (*(long *)(param_2 + 6) == 0) {
    return 0x2e;
  }
  iVar4 = serverInterMapLookupLockFlags(param_1,1,param_2,&local_d8);
  if ((iVar4 == 0) && (iVar4 = serverTopLock_Prologue(param_1,local_d8,lVar1,&local_d4), iVar4 == 0)
     ) {
    iVar4 = _serverLockClientWithLockInfo_constprop_0(param_1,*param_2,1,lVar1,&local_d4,&local_d0);
    local_e0 = local_d0;
    if (iVar4 != 0) {
LAB_0051fc82:
      serverInterMap_Epilogue(param_1,param_2,&local_d4);
      goto LAB_0051fc90;
    }
    plVar6 = *(long **)(local_d0 + 8);
    if ((char)plVar6[10] != '\0') {
      iVar4 = (**(code **)(*plVar6 + 0x30))(plVar6,*(undefined8 *)(param_2 + 0x12));
      if ((((iVar4 != 0) ||
           (iVar4 = clientGetResourceRef_IMPL(plVar6,param_2[1],&local_c8), iVar4 != 0)) ||
          (iVar4 = clientGetResourceRef_IMPL(plVar6,param_2[2],&local_c0), iVar4 != 0)) ||
         (iVar4 = clientGetResourceRef_IMPL(plVar6,param_2[3],&local_b8), iVar4 != 0))
      goto LAB_0051fc82;
      *(undefined8 *)(lVar1 + 0x10) = local_b8;
      portMemSet(&local_a8,0,0x70);
      local_98 = local_c8;
      local_90 = local_b8;
      puVar2 = *(undefined8 **)(param_2 + 0x12);
      if (puVar2 != (undefined8 *)0x0) {
        local_80 = *puVar2;
        local_78 = puVar2[1];
        local_70 = puVar2[2];
        local_68 = puVar2[3];
      }
      local_a8 = param_1;
      local_a0 = plVar6;
      local_88 = lVar1;
      plVar5 = (long *)tlsEntryAcquire(1);
      if (plVar5 == (long *)0x0) {
        nvAssertOkFailedNoLog
                  (0x40,"resservSwapTlsCallContext(&pOldContext, &callContext)",
                   "src/libraries/resserv/src/rs_server.c",0x8d5);
        serverInterMap_Epilogue(param_1,param_2,&local_d4);
        iVar4 = 0x40;
LAB_0051fc90:
        if (local_b0 != 0) goto LAB_0051fb8d;
      }
      else {
        lVar3 = *plVar5;
        *plVar5 = (long)&local_a8;
        if (((lVar3 != 0) && (local_60 != 0)) && (*(long *)(lVar3 + 0x48) != 0)) {
          *(byte *)(local_60 + 0x69) =
               *(byte *)(local_60 + 0x69) | *(byte *)(*(long *)(lVar3 + 0x48) + 0x69);
        }
        iVar4 = serverInterMap_Prologue(param_1,local_c8,local_c0,param_2,&local_d4);
        if ((iVar4 == 0) &&
           (iVar4 = (**(code **)(*plVar6 + 0x68))(plVar6,local_c8,local_c0,param_2), iVar4 == 0)) {
          iVar4 = refCreateInterMapping(local_c8,&local_b0);
          if (iVar4 == 0) {
            *(undefined8 *)(local_b0 + 0x70) = *(undefined8 *)(param_2 + 6);
            iVar4 = refAddInterMapping(local_c8,local_c0,*(undefined8 *)(param_2 + 0xc),local_b8);
            if (iVar4 != 0) goto LAB_0051ff89;
            *(undefined4 *)(local_b0 + 0x60) = param_2[8];
            *(undefined4 *)(local_b0 + 100) = param_2[9];
            *(undefined8 *)(local_b0 + 0x78) = *(undefined8 *)(param_2 + 0xe);
            serverInterMap_Epilogue(param_1,param_2,&local_d4);
          }
          else {
            nvAssertOkFailedNoLog
                      (iVar4,"refCreateInterMapping(pMapperRef, &pMapping)",
                       "src/libraries/resserv/src/rs_server.c",0x8e3);
            serverInterMap_Epilogue(param_1,param_2,&local_d4);
          }
        }
        else {
LAB_0051ff89:
          serverInterMap_Epilogue(param_1,param_2,&local_d4);
        }
        plVar6 = (long *)tlsEntryAcquire(1);
        if (plVar6 == (long *)0x0) {
          nvAssertOkFailedNoLog
                    (0x1f,"resservRestoreTlsCallContext(pOldContext)",
                     "src/libraries/resserv/src/rs_server.c",0x8f3);
        }
        else {
          *plVar6 = lVar3;
          tlsEntryRelease(1);
          tlsEntryRelease(1);
        }
        if (iVar4 != 0) goto LAB_0051fc90;
      }
      goto LAB_0051fbae;
    }
    iVar4 = 0x40;
    serverInterMap_Epilogue(param_1,param_2,&local_d4);
    if (local_b0 != 0) goto LAB_0051fb8d;
  }
  else {
    serverInterMap_Epilogue(param_1,param_2,&local_d4);
    local_e0 = 0;
    if (local_b0 == 0) goto LAB_0051fbcd;
LAB_0051fb8d:
    refRemoveInterMapping(local_c8,local_b0,0);
    refDestroyInterMapping(local_c8,local_b0);
LAB_0051fbae:
    if (local_e0 == 0) goto LAB_0051fbcd;
  }
  _serverUnlockClientWithLockInfo_constprop_0(param_1,local_e0,lVar1,&local_d4);
LAB_0051fbcd:
  serverTopLock_Epilogue(param_1,local_d8,lVar1,&local_d4);
  return iVar4;
}


// ===== 00520000 serverInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int serverInterUnmap(undefined8 param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 *puVar2;
  long lVar3;
  ulong uVar4;
  char cVar5;
  int iVar6;
  long *plVar7;
  long lVar8;
  long *plVar9;
  long lVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  int local_f8;
  long local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  long local_c0;
  long local_b8;
  long local_b0;
  undefined8 local_a8;
  long *local_a0;
  long local_98;
  long local_90;
  long local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  long local_60;
  
  lVar1 = *(long *)(param_2 + 0xc);
  local_c0 = 0;
  local_c4 = 0;
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pLockInfo != NULL","src/libraries/resserv/src/rs_server.c",0x9e8);
    return 0x1f;
  }
  local_f8 = serverInterUnmapLookupLockFlags(param_1,1,param_2,&local_c8);
  if (local_f8 == 0) {
    local_f8 = serverTopLock_Prologue(param_1,local_c8,lVar1,&local_c4);
    local_d0 = 0;
    if (local_f8 == 0) {
      local_f8 = _serverLockClientWithLockInfo_constprop_0
                           (param_1,*param_2,1,lVar1,&local_c4,&local_c0);
      local_d0 = local_c0;
      if (local_f8 == 0) {
        plVar9 = *(long **)(local_c0 + 8);
        local_f8 = (**(code **)(*plVar9 + 0x30))(plVar9,*(undefined8 *)(param_2 + 0xe));
        if ((((local_f8 == 0) &&
             (local_f8 = clientGetResourceRef_IMPL(plVar9,param_2[1],&local_b8), local_f8 == 0)) &&
            ((*(char *)(local_b8 + 0x124) == '\0' || (*(long *)(local_b8 + 8) != 0)))) &&
           (local_f8 = clientGetResourceRef_IMPL(plVar9,param_2[2],&local_b0), local_f8 == 0)) {
          portMemSet(&local_a8,0,0x70);
          local_90 = local_b0;
          local_98 = local_b8;
          puVar2 = *(undefined8 **)(param_2 + 0xe);
          if (puVar2 != (undefined8 *)0x0) {
            local_80 = *puVar2;
            local_78 = puVar2[1];
            local_70 = puVar2[2];
            local_68 = puVar2[3];
          }
          if (*(long *)(lVar1 + 0x10) == 0) {
            *(long *)(lVar1 + 0x10) = local_b0;
          }
          local_a8 = param_1;
          local_a0 = plVar9;
          local_88 = lVar1;
          plVar7 = (long *)tlsEntryAcquire(1);
          if (plVar7 != (long *)0x0) {
            lVar3 = *plVar7;
            *plVar7 = (long)&local_a8;
            if (((lVar3 != 0) && (local_60 != 0)) && (*(long *)(lVar3 + 0x48) != 0)) {
              *(byte *)(local_60 + 0x69) =
                   *(byte *)(local_60 + 0x69) | *(byte *)(*(long *)(lVar3 + 0x48) + 0x69);
            }
            local_f8 = serverResLock_Prologue(param_1,1,lVar1,&local_c4,0);
            if ((local_f8 == 0) &&
               (local_f8 = serverInterUnmap_Prologue(param_1,param_2), local_f8 == 0)) {
              uVar4 = *(ulong *)(param_2 + 4);
              uVar13 = *(ulong *)(param_2 + 6);
              lVar8 = mapFind_IMPL(local_b8 + 0x168,*(undefined4 *)(local_b0 + 0x10));
              if (uVar13 == 0) {
                if ((lVar8 == 0) || (lVar8 = mapFind_IMPL(lVar8,uVar4), lVar8 == 0)) {
                  local_f8 = 0x57;
                }
                else {
                  *(undefined8 *)(param_2 + 4) = *(undefined8 *)(lVar8 + 0x68);
                  *(undefined8 *)(param_2 + 6) = *(undefined8 *)(lVar8 + 0x70);
                  local_f8 = serverInterUnmapMapping(plVar9,local_b8,lVar8,param_2,0);
                  if (local_f8 != 0) {
                    nvAssertOkFailedNoLog
                              (local_f8,
                               "serverInterUnmapMapping(pClient, pMapperRef, pMapping, pParams, bPartialUnmap)"
                               ,"src/libraries/resserv/src/rs_server.c",0x98d);
                  }
                }
              }
              else if (lVar8 != 0) {
                lVar10 = mapFindLEQ_IMPL(lVar8,uVar4);
                uVar11 = uVar13 + uVar4;
                if (lVar10 == 0) {
                  lVar10 = mapFindGEQ_IMPL(lVar8,uVar4);
                  if (CARRY8(uVar13,uVar4)) goto LAB_00520698;
                  if (lVar10 != 0) goto LAB_005204b8;
                }
                else if (CARRY8(uVar13,uVar4)) {
LAB_00520698:
                  nvCheckFailedNoLog(4,"portSafeAddU64(unmapDmaOffset, unmapSize, &unmapEnd)",
                                     "src/libraries/resserv/src/rs_server.c",0x9a2);
LAB_005206b5:
                  local_f8 = 0x1f;
                }
                else {
LAB_005204b8:
                  local_f8 = 0;
                  uVar13 = *(ulong *)(lVar10 + 0x68);
                  while (uVar13 < uVar11) {
                    lVar12 = mapNext_IMPL(lVar8,lVar10);
                    uVar13 = *(ulong *)(lVar10 + 0x68);
                    uVar14 = uVar13 + *(ulong *)(lVar10 + 0x70);
                    if (CARRY8(uVar13,*(ulong *)(lVar10 + 0x70))) {
                      nvAssertFailedNoLog("portSafeAddU64(pMapping->dmaOffset, pMapping->size, &mappingEnd)"
                                          ,"src/libraries/resserv/src/rs_server.c",0x9ab);
LAB_005205e2:
                      local_f8 = 0x40;
                      break;
                    }
                    if (uVar4 < uVar14) {
                      if ((uVar11 < uVar14) || (uVar13 < uVar4)) {
                        cVar5 = (**(code **)(**(long **)(local_b8 + 8) + 0x88))();
                        if (cVar5 == '\0') {
                          nvCheckOkFailedNoLog
                                    (4,0x1f,"resIsPartialUnmapSupported(pMapperRef->pResource)",
                                     "src/libraries/resserv/src/rs_server.c",0x9b6);
                          goto LAB_005206b5;
                        }
                        if (*(long *)(lVar10 + 0x78) != 0) {
                          nvAssertOkFailedNoLog
                                    (0x40,"pMapping->pMemDesc == NULL",
                                     "src/libraries/resserv/src/rs_server.c",0x9bc);
                          goto LAB_005205e2;
                        }
                      }
                      uVar13 = *(ulong *)(lVar10 + 0x68);
                      if (*(ulong *)(lVar10 + 0x68) <= uVar4) {
                        uVar13 = uVar4;
                      }
                      if (uVar11 <= uVar14) {
                        uVar14 = uVar11;
                      }
                      *(ulong *)(param_2 + 4) = uVar13;
                      *(ulong *)(param_2 + 6) = uVar14 - uVar13;
                      iVar6 = serverInterUnmapMapping(plVar9,local_b8,lVar10,param_2,1);
                      if (iVar6 != 0) {
                        nvAssertOkFailedNoLog
                                  (iVar6,
                                   "serverInterUnmapMapping(pClient, pMapperRef, pMapping, pParams, bPartialUnmap)"
                                   ,"src/libraries/resserv/src/rs_server.c",0x9c8);
                        local_f8 = iVar6;
                        break;
                      }
                    }
                    if (lVar12 == 0) break;
                    lVar10 = lVar12;
                    uVar13 = *(ulong *)(lVar12 + 0x68);
                  }
                }
              }
            }
            serverInterUnmap_Epilogue(param_1,param_2);
            serverResLock_Epilogue(param_1,1,lVar1,&local_c4);
            plVar9 = (long *)tlsEntryAcquire(1);
            if (plVar9 == (long *)0x0) {
              nvAssertOkFailedNoLog
                        (0x1f,"resservRestoreTlsCallContext(pOldContext)",
                         "src/libraries/resserv/src/rs_server.c",0xa2e);
            }
            else {
              *plVar9 = lVar3;
              tlsEntryRelease(1);
              tlsEntryRelease(1);
            }
            goto LAB_00520095;
          }
          local_f8 = 0x40;
          nvAssertOkFailedNoLog
                    (0x40,"resservSwapTlsCallContext(&pOldContext, &callContext)",
                     "src/libraries/resserv/src/rs_server.c",0xa1a);
        }
      }
    }
  }
  else {
    local_d0 = 0;
  }
  serverInterUnmap_Epilogue(param_1,param_2);
  serverResLock_Epilogue(param_1,1,lVar1,&local_c4);
LAB_00520095:
  if (local_d0 != 0) {
    _serverUnlockClientWithLockInfo_constprop_0(param_1,local_d0,lVar1,&local_c4);
  }
  serverTopLock_Epilogue(param_1,local_c8,lVar1,&local_c4);
  return local_f8;
}


