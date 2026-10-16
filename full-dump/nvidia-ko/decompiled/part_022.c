// ===== 00238fc0 nvswitch_reset_persistent_link_hw_state_ls10 =====

void nvswitch_reset_persistent_link_hw_state_ls10(undefined8 param_1,uint param_2)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvswitch_get_link(param_1,param_2 & 0xff);
  if ((lVar2 != 0) && (cVar1 = nvswitch_is_link_in_reset(param_1,lVar2), cVar1 == '\0')) {
    nvswitch_minion_send_command(param_1,param_2,0x70,0);
    cVar1 = nvswitch_are_link_clocks_on_ls10(param_1,lVar2,7);
    if (cVar1 != '\0') {
      nvswitch_minion_send_command(param_1,param_2,0x94,4);
      nvswitch_minion_send_command(param_1,param_2,0x26,0);
      return;
    }
  }
  return;
}


// ===== 00239070 nvswitch_request_tl_link_state_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_r15 replaced with injection: x86_indirect_thunk_r15 */

int nvswitch_request_tl_link_state_ls10(long param_1,uint param_2,char param_3)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  ulong uVar8;
  undefined8 uVar9;
  undefined1 local_40 [16];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 200);
  pcVar2 = *(code **)(lVar1 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
  iVar6 = (*pcVar2)(lVar1,9,0,uVar5);
  if ((iVar6 == -1) ||
     (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0')) {
    return -9;
  }
  iVar6 = nvswitch_wait_for_tl_request_ready_lr10(param_1);
  if (iVar6 != 0) {
    return iVar6;
  }
  pcVar2 = *(code **)(lVar1 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
  iVar6 = (*pcVar2)(lVar1,9,0,uVar5,pcVar2);
  if ((iVar6 == -1) ||
     (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar2 = *(code **)(lVar1 + 0x920);
  uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
  uVar8 = (*pcVar2)(lVar1,9,0,uVar5,0x280,pcVar2);
  if ((uVar8 & 4) != 0) {
    pcVar2 = *(code **)(lVar1 + 0x910);
    uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
    iVar6 = (*pcVar2)(lVar1,9,0,uVar5,pcVar2);
    if ((iVar6 == -1) ||
       (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar2 = *(code **)(lVar1 + 0x928);
    uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
    (*pcVar2)(lVar1,9,0,uVar5,0x280,4);
  }
  pcVar2 = *(code **)(lVar1 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
  iVar6 = (*pcVar2)(lVar1,9,0,uVar5,pcVar2);
  if ((iVar6 == -1) ||
     (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar2 = *(code **)(lVar1 + 0x928);
  uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
  (*pcVar2)(lVar1,9,0,uVar5,0x480,param_2 & 0xf);
  if (param_3 != '\0') {
    if (param_2 == 9) {
      uVar9 = 4000000;
    }
    else if (param_2 < 10) {
      if (param_2 == 1) {
        uVar9 = 10000000000;
      }
      else {
        uVar9 = 5000000;
        if (param_2 != 2) {
          return 8;
        }
      }
    }
    else {
      uVar9 = 10000000;
      if (param_2 != 0xd) {
        return 8;
      }
    }
    nvswitch_timeout_create(uVar9,local_40);
    while( true ) {
      cVar3 = nvswitch_timeout_check(local_40);
      pcVar2 = *(code **)(lVar1 + 0x910);
      uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
      iVar6 = (*pcVar2)(lVar1,9,0,uVar5);
      if ((iVar6 == -1) ||
         (cVar4 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar4 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x920);
      uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
      uVar7 = (*pcVar2)(lVar1,9,0,uVar5,0x484);
      if ((uVar7 & 0xf) == param_2) break;
      nvswitch_os_sleep(1);
      if (cVar3 != '\0') {
        pcVar2 = *(code **)(lVar1 + 0x910);
        uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
        iVar6 = (*pcVar2)(lVar1,9,0,uVar5);
        if ((iVar6 == -1) ||
           (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0')) {
          nvswitch_assert_log();
        }
        pcVar2 = *(code **)(lVar1 + 0x920);
        uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
        uVar7 = (*pcVar2)(lVar1,9,0,uVar5,0x484);
        iVar6 = -7;
        if ((uVar7 & 0xf) == param_2) {
          iVar6 = 10;
        }
        return iVar6;
      }
    }
    return 0;
  }
  return 0;
}


// ===== 00239490 nvswitch_launch_ALI_link_training_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */

undefined8 nvswitch_launch_ALI_link_training_ls10(long param_1,long param_2,undefined1 param_3)

{
  code *pcVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 uVar5;
  
  cVar2 = nvswitch_is_tnvl_mode_locked();
  if (cVar2 != '\0') {
    return 0xf;
  }
  if (param_2 != 0) {
    pcVar1 = *(code **)(param_1 + 0x910);
    uVar3 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
    iVar4 = (*pcVar1)(param_1,9,0,uVar3);
    if (((iVar4 != -1) &&
        (cVar2 = nvswitch_is_link_valid(param_1,*(undefined4 *)(param_2 + 0x38)), cVar2 != '\0')) &&
       (*(uint *)(param_2 + 0x38) < 0x40)) {
      cVar2 = nvswitch_is_link_in_reset(param_1,param_2);
      if (cVar2 == '\0') {
        return 0;
      }
      iVar4 = nvswitch_minion_set_sim_mode_ls10(param_1,param_2);
      if (((iVar4 == 0) &&
          (iVar4 = nvswitch_minion_set_smf_settings_ls10(param_1,param_2), iVar4 == 0)) &&
         (iVar4 = nvswitch_minion_select_uphy_tables_ls10(param_1,param_2), iVar4 == 0)) {
        nvswitch_setup_link_loopback_mode(param_1,*(undefined4 *)(param_2 + 0x38));
        uVar5 = nvswitch_request_tl_link_state_ls10(param_2,1,param_3);
        return uVar5;
      }
      return 0x78;
    }
  }
  return 0xfffffff7;
}


// ===== 002395f0 nvswitch_execute_unilateral_link_shutdown_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */
/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */

void nvswitch_execute_unilateral_link_shutdown_ls10(long param_1)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint local_2c;
  
  local_2c = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 200);
  pcVar2 = *(code **)(lVar1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
  iVar7 = (*pcVar2)(lVar1,0xb,0,uVar4);
  if ((iVar7 != -1) &&
     (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 != '\0')) {
    iVar7 = 3;
    while (iVar5 = nvswitch_request_tl_link_state_ls10(param_1,0xd,1), iVar5 != 0) {
      pcVar2 = *(code **)(lVar1 + 0x910);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
      iVar5 = (*pcVar2)(lVar1,9,0,uVar4);
      if ((iVar5 == -1) ||
         (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x920);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
      uVar6 = (*pcVar2)(lVar1,9,0,uVar4,0x480);
      iVar5 = nvswitch_minion_get_dl_status(lVar1,*(undefined4 *)(param_1 + 0x38),0xff,0,&local_2c);
      if (iVar5 == 0) {
        if ((local_2c & 0xff00) != 0x5000) {
          return;
        }
        if ((uVar6 & 0xff00) != 0x8000) {
          return;
        }
      }
      iVar7 = iVar7 + -1;
      if (iVar7 == 0) {
        return;
      }
    }
  }
  return;
}


// ===== 00239760 nvswitch_reset_and_train_link_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r15 replaced with injection: x86_indirect_thunk_r15 */

int nvswitch_reset_and_train_link_ls10(long param_1,long param_2)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint local_3c [3];
  
  iVar3 = 0;
  nvswitch_execute_unilateral_link_shutdown_ls10(param_2);
  nvswitch_corelib_clear_link_state_lr10(param_2);
  cVar2 = cciIsLinkManaged(param_1,*(undefined4 *)(param_2 + 0x38));
  if (cVar2 == '\0') {
    iVar7 = 3;
    do {
      iVar3 = nvswitch_request_tl_link_state_ls10(param_2,9,1);
      if (iVar3 == 0) goto LAB_002398c8;
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
      iVar6 = (*pcVar1)(param_1,9,0,uVar4);
      if ((iVar6 == -1) ||
         (cVar2 = nvswitch_is_link_valid(param_1,*(undefined4 *)(param_2 + 0x38)), cVar2 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar1 = *(code **)(param_1 + 0x920);
      uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
      uVar5 = (*pcVar1)(param_1,9,0,uVar4,0x480);
      iVar6 = nvswitch_minion_get_dl_status(param_1,*(undefined4 *)(param_2 + 0x38),0xff,0,local_3c)
      ;
      if (iVar6 == 0) {
        if ((local_3c[0] & 0xff00) != 0x5000) {
          return iVar3;
        }
        if ((uVar5 & 0xff00) != 0x8000) {
          return iVar3;
        }
        iVar3 = nvswitch_request_tl_link_state_ls10(param_2,9,1);
      }
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    if (iVar3 == 0) {
LAB_002398c8:
      iVar3 = nvswitch_launch_ALI_link_training(param_1,param_2,0);
    }
  }
  return iVar3;
}


// ===== 002398f0 nvswitch_cci_initialization_sequence_ls10 =====

void nvswitch_cci_initialization_sequence_ls10(undefined8 param_1,ulong param_2)

{
  int iVar1;
  undefined1 local_1d8 [200];
  undefined8 local_110;
  undefined1 local_f8 [16];
  undefined1 *local_e8;
  undefined4 local_c0;
  
  local_c0 = (undefined4)param_2;
  local_e8 = local_1d8;
  local_110 = param_1;
  iVar1 = nvswitch_minion_send_command(param_1,param_2,0xd,0);
  if (iVar1 == 0) {
    iVar1 = nvswitch_minion_send_command(param_1,param_2 & 0xffffffff,0x58,0);
    if (iVar1 == 0) {
      iVar1 = _nvswitch_init_dl_pll(local_f8);
      if (iVar1 == 0) {
        nvswitch_minion_send_command(param_1,param_2 & 0xffffffff,0x22,0);
        return;
      }
    }
  }
  return;
}


// ===== 00239990 nvswitch_cci_deinitialization_sequence_ls10 =====

void nvswitch_cci_deinitialization_sequence_ls10(undefined8 param_1,undefined8 param_2)

{
  nvswitch_minion_send_command(param_1,param_2,0x59,0);
  return;
}


// ===== 002399a0 nvswitch_cci_enable_iobist_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8 nvswitch_cci_enable_iobist_ls10(long param_1,ulong param_2,char param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  ulong uVar6;
  code *pcVar7;
  
  uVar6 = param_2 & 0xffffffff;
  pcVar7 = *(code **)(param_1 + 0x910);
  if (param_3 == '\0') {
    uVar2 = nvswitch_get_link_eng_inst(param_1,param_2,0xb);
    iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
    if (iVar3 == -1) {
LAB_0023a3ca:
      nvswitch_assert_log();
    }
    else {
      cVar1 = nvswitch_is_link_valid(param_1,uVar6);
      if (cVar1 == '\0') goto LAB_0023a3ca;
    }
    pcVar7 = *(code **)(param_1 + 0x920);
    uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
    uVar4 = (*pcVar7)(param_1,0xb,0,uVar2,0x2e14);
    pcVar7 = *(code **)(param_1 + 0x910);
    uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
    iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
    if (iVar3 == -1) {
LAB_0023a678:
      nvswitch_assert_log();
    }
    else {
      cVar1 = nvswitch_is_link_valid(param_1,uVar6);
      if (cVar1 == '\0') goto LAB_0023a678;
    }
    pcVar7 = *(code **)(param_1 + 0x928);
    uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
    (*pcVar7)(param_1,0xb,0,uVar2,0x2e14,uVar4 & 0xfffffffe);
    pcVar7 = *(code **)(param_1 + 0x910);
    uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
    iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
    if (iVar3 == -1) {
LAB_0023a668:
      nvswitch_assert_log();
    }
    else {
      cVar1 = nvswitch_is_link_valid(param_1,uVar6);
      if (cVar1 == '\0') goto LAB_0023a668;
    }
    pcVar7 = *(code **)(param_1 + 0x920);
    uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
    uVar4 = (*pcVar7)(param_1,0xb,0,uVar2,0x2e18);
    pcVar7 = *(code **)(param_1 + 0x910);
    uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
    iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
    if (iVar3 == -1) {
LAB_0023a658:
      nvswitch_assert_log();
    }
    else {
      cVar1 = nvswitch_is_link_valid(param_1,uVar6);
      if (cVar1 == '\0') goto LAB_0023a658;
    }
    pcVar7 = *(code **)(param_1 + 0x928);
    uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
    (*pcVar7)(param_1,0xb,0,uVar2,0x2e18,uVar4 & 0xfffffff7);
    pcVar7 = *(code **)(param_1 + 0x910);
    uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
    iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
    if (iVar3 == -1) {
LAB_0023a648:
      nvswitch_assert_log();
    }
    else {
      cVar1 = nvswitch_is_link_valid(param_1,uVar6);
      if (cVar1 == '\0') goto LAB_0023a648;
    }
    pcVar7 = *(code **)(param_1 + 0x920);
    uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
    uVar4 = (*pcVar7)(param_1,0xb,0,uVar2,0x2e18);
    uVar4 = uVar4 & 0xfffffffb;
    pcVar7 = *(code **)(param_1 + 0x910);
    uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
    iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
    if (iVar3 == -1) {
LAB_0023a619:
      nvswitch_assert_log();
    }
    else {
      cVar1 = nvswitch_is_link_valid(param_1,uVar6);
      if (cVar1 == '\0') goto LAB_0023a619;
    }
    pcVar7 = *(code **)(param_1 + 0x928);
    uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
    uVar5 = 0x2e18;
    goto LAB_0023a37f;
  }
  uVar2 = nvswitch_get_link_eng_inst(param_1,param_2,0xb);
  iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
  if (iVar3 == -1) {
LAB_002399f7:
    nvswitch_assert_log();
  }
  else {
    cVar1 = nvswitch_is_link_valid(param_1,uVar6);
    if (cVar1 == '\0') goto LAB_002399f7;
  }
  pcVar7 = *(code **)(param_1 + 0x920);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  uVar4 = (*pcVar7)(param_1,0xb,0,uVar2,0x2e14);
  pcVar7 = *(code **)(param_1 + 0x910);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
  if (iVar3 == -1) {
LAB_0023a6f8:
    nvswitch_assert_log();
  }
  else {
    cVar1 = nvswitch_is_link_valid(param_1,uVar6);
    if (cVar1 == '\0') goto LAB_0023a6f8;
  }
  pcVar7 = *(code **)(param_1 + 0x928);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  (*pcVar7)(param_1,0xb,0,uVar2,0x2e14,uVar4 | 10);
  pcVar7 = *(code **)(param_1 + 0x910);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
  if (iVar3 == -1) {
LAB_0023a6e8:
    nvswitch_assert_log();
  }
  else {
    cVar1 = nvswitch_is_link_valid(param_1,param_2 & 0xffffffff);
    if (cVar1 == '\0') goto LAB_0023a6e8;
  }
  pcVar7 = *(code **)(param_1 + 0x920);
  uVar2 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,0xb);
  uVar4 = (*pcVar7)(param_1,0xb,0,uVar2,0x2e10);
  pcVar7 = *(code **)(param_1 + 0x910);
  uVar2 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,0xb);
  iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
  if (iVar3 == -1) {
LAB_0023a738:
    nvswitch_assert_log();
  }
  else {
    cVar1 = nvswitch_is_link_valid(param_1,uVar6);
    if (cVar1 == '\0') goto LAB_0023a738;
  }
  pcVar7 = *(code **)(param_1 + 0x928);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  (*pcVar7)(param_1,0xb,0,uVar2,0x2e10,uVar4 | 3);
  pcVar7 = *(code **)(param_1 + 0x910);
  uVar2 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,0xb);
  iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
  if (iVar3 == -1) {
LAB_0023a728:
    nvswitch_assert_log();
  }
  else {
    cVar1 = nvswitch_is_link_valid(param_1,param_2 & 0xffffffff);
    if (cVar1 == '\0') goto LAB_0023a728;
  }
  pcVar7 = *(code **)(param_1 + 0x920);
  uVar2 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,0xb);
  (*pcVar7)(param_1,0xb,0,uVar2,0x2e08);
  pcVar7 = *(code **)(param_1 + 0x910);
  uVar2 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,0xb);
  iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
  if (iVar3 == -1) {
LAB_0023a718:
    nvswitch_assert_log();
  }
  else {
    cVar1 = nvswitch_is_link_valid(param_1,uVar6);
    if (cVar1 == '\0') goto LAB_0023a718;
  }
  pcVar7 = *(code **)(param_1 + 0x928);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  (*pcVar7)(param_1,0xb,0,uVar2,0x2e08,0x7845bdcd);
  pcVar7 = *(code **)(param_1 + 0x910);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
  if (iVar3 == -1) {
LAB_0023a708:
    nvswitch_assert_log();
  }
  else {
    cVar1 = nvswitch_is_link_valid(param_1,uVar6);
    if (cVar1 == '\0') goto LAB_0023a708;
  }
  pcVar7 = *(code **)(param_1 + 0x920);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  (*pcVar7)(param_1,0xb,0,uVar2,0x2e0c);
  pcVar7 = *(code **)(param_1 + 0x910);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
  if (iVar3 == -1) {
LAB_0023a7b8:
    nvswitch_assert_log();
  }
  else {
    cVar1 = nvswitch_is_link_valid(param_1,uVar6);
    if (cVar1 == '\0') goto LAB_0023a7b8;
  }
  pcVar7 = *(code **)(param_1 + 0x928);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  (*pcVar7)(param_1,0xb,0,uVar2,0x2e0c,0x124507ff);
  pcVar7 = *(code **)(param_1 + 0x910);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
  if (iVar3 == -1) {
LAB_0023a7a8:
    nvswitch_assert_log();
  }
  else {
    cVar1 = nvswitch_is_link_valid(param_1,uVar6);
    if (cVar1 == '\0') goto LAB_0023a7a8;
  }
  pcVar7 = *(code **)(param_1 + 0x920);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  (*pcVar7)(param_1,0xb,0,uVar2,0x2e00);
  pcVar7 = *(code **)(param_1 + 0x910);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
  if (iVar3 == -1) {
LAB_0023a798:
    nvswitch_assert_log();
  }
  else {
    cVar1 = nvswitch_is_link_valid(param_1,uVar6);
    if (cVar1 == '\0') goto LAB_0023a798;
  }
  pcVar7 = *(code **)(param_1 + 0x928);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  (*pcVar7)(param_1,0xb,0,uVar2,0x2e00,0xad3d6c5b);
  pcVar7 = *(code **)(param_1 + 0x910);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
  if (iVar3 == -1) {
LAB_0023a788:
    nvswitch_assert_log();
  }
  else {
    cVar1 = nvswitch_is_link_valid(param_1,uVar6);
    if (cVar1 == '\0') goto LAB_0023a788;
  }
  pcVar7 = *(code **)(param_1 + 0x920);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  (*pcVar7)(param_1,0xb,0,uVar2,0x2e04);
  pcVar7 = *(code **)(param_1 + 0x910);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
  if (iVar3 == -1) {
LAB_0023a778:
    nvswitch_assert_log();
  }
  else {
    cVar1 = nvswitch_is_link_valid(param_1,uVar6);
    if (cVar1 == '\0') goto LAB_0023a778;
  }
  pcVar7 = *(code **)(param_1 + 0x928);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  (*pcVar7)(param_1,0xb,0,uVar2,0x2e04,0xbe35879e);
  pcVar7 = *(code **)(param_1 + 0x910);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
  if (iVar3 == -1) {
LAB_0023a768:
    nvswitch_assert_log();
  }
  else {
    cVar1 = nvswitch_is_link_valid(param_1,uVar6);
    if (cVar1 == '\0') goto LAB_0023a768;
  }
  pcVar7 = *(code **)(param_1 + 0x920);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  uVar4 = (*pcVar7)(param_1,0xb,0,uVar2,0x2e10);
  pcVar7 = *(code **)(param_1 + 0x910);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
  if (iVar3 == -1) {
LAB_0023a758:
    nvswitch_assert_log();
  }
  else {
    cVar1 = nvswitch_is_link_valid(param_1,uVar6);
    if (cVar1 == '\0') goto LAB_0023a758;
  }
  pcVar7 = *(code **)(param_1 + 0x928);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  (*pcVar7)(param_1,0xb,0,uVar2,0x2e10,uVar4 & 0xfffff007 | 0x5ec);
  pcVar7 = *(code **)(param_1 + 0x910);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
  if (iVar3 == -1) {
LAB_0023a748:
    nvswitch_assert_log();
  }
  else {
    cVar1 = nvswitch_is_link_valid(param_1,uVar6);
    if (cVar1 == '\0') goto LAB_0023a748;
  }
  pcVar7 = *(code **)(param_1 + 0x920);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  uVar4 = (*pcVar7)(param_1,0xb,0,uVar2,0x2e18);
  pcVar7 = *(code **)(param_1 + 0x910);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
  if (iVar3 == -1) {
LAB_0023a6b8:
    nvswitch_assert_log();
  }
  else {
    cVar1 = nvswitch_is_link_valid(param_1,uVar6);
    if (cVar1 == '\0') goto LAB_0023a6b8;
  }
  pcVar7 = *(code **)(param_1 + 0x928);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  (*pcVar7)(param_1,0xb,0,uVar2,0x2e18,uVar4 | 0x2000c);
  pcVar7 = *(code **)(param_1 + 0x910);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
  if (iVar3 == -1) {
LAB_0023a6a8:
    nvswitch_assert_log();
  }
  else {
    cVar1 = nvswitch_is_link_valid(param_1,uVar6);
    if (cVar1 == '\0') goto LAB_0023a6a8;
  }
  pcVar7 = *(code **)(param_1 + 0x920);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  uVar4 = (*pcVar7)(param_1,0xb,0,uVar2,0x2e14);
  pcVar7 = *(code **)(param_1 + 0x910);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  iVar3 = (*pcVar7)(param_1,0xb,0,uVar2,pcVar7);
  if (iVar3 == -1) {
LAB_0023a698:
    nvswitch_assert_log();
  }
  else {
    cVar1 = nvswitch_is_link_valid(param_1,uVar6);
    if (cVar1 == '\0') goto LAB_0023a698;
  }
  pcVar7 = *(code **)(param_1 + 0x928);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  (*pcVar7)(param_1,0xb,0,uVar2,0x2e14,uVar4 | 4);
  nvswitch_os_sleep(5);
  pcVar7 = *(code **)(param_1 + 0x910);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
  if (iVar3 == -1) {
LAB_0023a688:
    nvswitch_assert_log();
  }
  else {
    cVar1 = nvswitch_is_link_valid(param_1,uVar6);
    if (cVar1 == '\0') goto LAB_0023a688;
  }
  pcVar7 = *(code **)(param_1 + 0x928);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  (*pcVar7)(param_1,0xb,0,uVar2,0x2e14,uVar4 & 0xfffffffb);
  pcVar7 = *(code **)(param_1 + 0x910);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
  if (iVar3 == -1) {
LAB_0023a6d8:
    nvswitch_assert_log();
  }
  else {
    cVar1 = nvswitch_is_link_valid(param_1,uVar6);
    if (cVar1 == '\0') goto LAB_0023a6d8;
  }
  pcVar7 = *(code **)(param_1 + 0x920);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  uVar4 = (*pcVar7)(param_1,0xb,0,uVar2,0x2e14);
  uVar4 = uVar4 | 1;
  pcVar7 = *(code **)(param_1 + 0x910);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  iVar3 = (*pcVar7)(param_1,0xb,0,uVar2);
  if (iVar3 == -1) {
LAB_0023a6c8:
    nvswitch_assert_log();
  }
  else {
    cVar1 = nvswitch_is_link_valid(param_1,uVar6);
    if (cVar1 == '\0') goto LAB_0023a6c8;
  }
  pcVar7 = *(code **)(param_1 + 0x928);
  uVar2 = nvswitch_get_link_eng_inst(param_1,uVar6,0xb);
  uVar5 = 0x2e14;
LAB_0023a37f:
  (*pcVar7)(param_1,0xb,0,uVar2,uVar5,uVar4);
  return 0;
}


// ===== 0023a7d0 nvswitch_does_link_need_termination_enabled_ls10 =====

undefined8 nvswitch_does_link_need_termination_enabled_ls10(void)

{
  return 0;
}


// ===== 0023a7e0 nvswitch_link_termination_setup_ls10 =====

undefined8 nvswitch_link_termination_setup_ls10(void)

{
  return 0xfffffff3;
}


// ===== 0023a7f0 nvswitch_ctrl_get_link_l1_capability_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r12 replaced with injection: x86_indirect_thunk_r12 */
/* WARNING: Function: __x86_indirect_thunk_r15 replaced with injection: x86_indirect_thunk_r15 */

undefined8 nvswitch_ctrl_get_link_l1_capability_ls10(long param_1,ulong param_2,byte *param_3)

{
  code *pcVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  
  uVar7 = param_2 & 0xffffffff;
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar3 = nvswitch_get_link_eng_inst(param_1,param_2,9);
  iVar4 = (*pcVar1)(param_1,9,0,uVar3);
  if (iVar4 == -1) {
LAB_0023a910:
    nvswitch_assert_log();
  }
  else {
    cVar2 = nvswitch_is_link_valid(param_1,uVar7);
    if (cVar2 == '\0') goto LAB_0023a910;
  }
  pcVar1 = *(code **)(param_1 + 0x920);
  uVar3 = nvswitch_get_link_eng_inst(param_1,uVar7,9);
  uVar5 = (*pcVar1)(param_1,9,0,uVar3,0x638);
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar3 = nvswitch_get_link_eng_inst(param_1,uVar7,9);
  iVar4 = (*pcVar1)(param_1,9,0,uVar3);
  if (iVar4 != -1) {
    cVar2 = nvswitch_is_link_valid(param_1,param_2 & 0xffffffff);
    if (cVar2 != '\0') goto LAB_0023a8c4;
  }
  nvswitch_assert_log();
LAB_0023a8c4:
  pcVar1 = *(code **)(param_1 + 0x920);
  uVar3 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,9);
  uVar6 = (*pcVar1)(param_1,9,0,uVar3,0x688);
  *param_3 = (byte)(uVar5 >> 1) & 1 & (byte)(uVar6 >> 1);
  return 0;
}


// ===== 0023a920 nvswitch_ctrl_get_link_l1_threshold_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */

undefined8 nvswitch_ctrl_get_link_l1_threshold_ls10(long param_1,ulong param_2,uint *param_3)

{
  code *pcVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar3 = nvswitch_get_link_eng_inst(param_1,param_2,9);
  iVar4 = (*pcVar1)(param_1,9,0,uVar3);
  if (iVar4 != -1) {
    cVar2 = nvswitch_is_link_valid(param_1,param_2 & 0xffffffff);
    if (cVar2 != '\0') goto LAB_0023a973;
  }
  nvswitch_assert_log();
LAB_0023a973:
  pcVar1 = *(code **)(param_1 + 0x920);
  uVar3 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,9);
  uVar5 = (*pcVar1)(param_1,9,0,uVar3,0x40c);
  *param_3 = uVar5 & 0x1fff;
  return 0;
}


// ===== 0023a9c0 nvswitch_ctrl_set_link_l1_threshold_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */
/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */

undefined8 nvswitch_ctrl_set_link_l1_threshold_ls10(long param_1,uint param_2)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  ulong local_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 200);
  if ((((*(char *)(lVar1 + 0x25) == '\0') && (*(char *)(lVar1 + 0x24) == '\0')) &&
      (*(char *)(lVar1 + 0x26) == '\0')) && (*(int *)(lVar1 + 0x58) != 0)) {
    uVar6 = *(undefined4 *)(param_1 + 0x38);
    iVar4 = nvswitch_lib_get_bios_version(lVar1,&local_30);
    if (iVar4 != 0) {
      local_30 = 0;
    }
    if (*(uint *)(lVar1 + 0xd0) == 0) {
      uVar7 = param_2 & 0x1fff;
      if ((0xfffffffd < param_2 - 1) && (uVar7 = 1, 0x961040ffff < local_30)) {
        pcVar2 = *(code **)(lVar1 + 0x910);
        uVar5 = nvswitch_get_link_eng_inst(lVar1,uVar6,9);
        iVar4 = (*pcVar2)(lVar1,9,0,uVar5);
        if ((iVar4 == -1) || (cVar3 = nvswitch_is_link_valid(lVar1,uVar6), cVar3 == '\0')) {
          nvswitch_assert_log();
        }
        pcVar2 = *(code **)(lVar1 + 0x920);
        uVar5 = nvswitch_get_link_eng_inst(lVar1,uVar6,9);
        uVar7 = (*pcVar2)(lVar1,9,0,uVar5,0x7c0);
        uVar7 = uVar7 & 0x1fff;
      }
    }
    else {
      uVar7 = *(uint *)(lVar1 + 0xd0) & 0x1fff;
    }
    pcVar2 = *(code **)(lVar1 + 0x910);
    uVar5 = nvswitch_get_link_eng_inst(lVar1,uVar6,9);
    iVar4 = (*pcVar2)(lVar1,9,0,uVar5);
    if ((iVar4 == -1) || (cVar3 = nvswitch_is_link_valid(lVar1,uVar6), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar2 = *(code **)(lVar1 + 0x928);
    uVar5 = nvswitch_get_link_eng_inst(lVar1,uVar6,9);
    (*pcVar2)(lVar1,9,0,uVar5,0x40c,uVar7);
    pcVar2 = *(code **)(lVar1 + 0x910);
    uVar5 = nvswitch_get_link_eng_inst(lVar1,uVar6,9);
    iVar4 = (*pcVar2)(lVar1,9,0,uVar5);
    if ((iVar4 == -1) || (cVar3 = nvswitch_is_link_valid(lVar1,uVar6), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar2 = *(code **)(lVar1 + 0x920);
    uVar5 = nvswitch_get_link_eng_inst(lVar1,uVar6,9);
    uVar7 = (*pcVar2)(lVar1,9,0,uVar5,0x400);
    pcVar2 = *(code **)(lVar1 + 0x910);
    uVar5 = nvswitch_get_link_eng_inst(lVar1,uVar6,9);
    iVar4 = (*pcVar2)(lVar1,9,0,uVar5);
    if ((iVar4 == -1) || (cVar3 = nvswitch_is_link_valid(lVar1,uVar6), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar2 = *(code **)(lVar1 + 0x928);
    uVar6 = nvswitch_get_link_eng_inst(lVar1,uVar6,9);
    (*pcVar2)(lVar1,9,0,uVar6,0x400,uVar7 | 0x100);
    return 0;
  }
  return 0xfffffff3;
}


// ===== 0023ac80 nvswitch_init_lpwr_regs_ls10 =====

void nvswitch_init_lpwr_regs_ls10(long param_1)

{
  if (param_1 != 0) {
    nvswitch_ctrl_set_link_l1_threshold_ls10
              (param_1,*(undefined4 *)(*(long *)(*(long *)(param_1 + 0x10) + 200) + 0xd0));
    return;
  }
  return;
}


// ===== 0023acb0 nvswitch_ctrl_set_ganged_link_table_ls10 =====

undefined8 nvswitch_ctrl_set_ganged_link_table_ls10(void)

{
  return 0xfffffff3;
}


// ===== 0023acc0 nvswitch_init_npg_multicast_ls10 =====

void nvswitch_init_npg_multicast_ls10(void)

{
  return;
}


// ===== 0023acd0 _nvswitch_get_engine_base_ls10 =====

uint _nvswitch_get_engine_base_ls10
               (long param_1,uint param_2,uint param_3,char param_4,uint *param_5)

{
  uint uVar1;
  long lVar2;
  char *pcVar3;
  char cVar4;
  bool bVar5;
  
  lVar2 = 0;
  if (*(int *)(param_1 + 0x1f88) == 7) {
    lVar2 = *(long *)(param_1 + 0x1f90);
  }
  if (param_2 == 0x24) {
    if (param_4 == '\0') {
      if ((param_3 < 0x10) && (*(char *)(lVar2 + 0x66d0 + (ulong)param_3 * 0x20) != '\0')) {
        pcVar3 = (char *)(lVar2 + 0x66d0 + (ulong)param_3 * 0x20);
        cVar4 = *pcVar3;
        goto LAB_0023b340;
      }
    }
    else if (param_3 == 0) {
      if (*(char *)(lVar2 + 0x68d0) != '\0') {
        pcVar3 = (char *)(lVar2 + 0x68d0);
        goto LAB_0023af30;
      }
      goto LAB_0023b1a8;
    }
  }
  else if (param_2 < 0x25) {
    if (param_2 == 0x1b) {
      if ((param_4 == '\0') && (param_3 == 0)) {
        if (*(char *)(lVar2 + 0x3890) != '\0') {
          pcVar3 = (char *)(lVar2 + 0x3890);
          goto LAB_0023aee0;
        }
        goto LAB_0023b1a8;
      }
    }
    else if (param_2 < 0x1c) {
      if (param_2 == 0x17) {
        if ((param_4 == '\0') && (param_3 == 0)) {
          if ((&DAT_00003650)[lVar2] != '\0') {
            pcVar3 = &DAT_00003650 + lVar2;
            goto LAB_0023aee0;
          }
          goto LAB_0023b1a8;
        }
      }
      else if (param_2 < 0x18) {
        if (param_2 < 0x14) {
          if (0xf < param_2 - 1) {
            bVar5 = param_3 != 0;
            param_3 = 0;
            uVar1 = -(uint)(bVar5 || param_4 != '\0');
            goto LAB_0023ad97;
          }
        }
        else if (((param_2 == 0x14) && (param_4 == '\0')) && (param_3 == 0)) {
          if (*(char *)(lVar2 + 0x35d0) != '\0') {
            pcVar3 = (char *)(lVar2 + 0x35d0);
            goto LAB_0023aee0;
          }
          goto LAB_0023b1a8;
        }
      }
      else if (param_2 == 0x19) {
        if ((param_4 == '\0') && (param_3 == 0)) {
          if (*(char *)(lVar2 + 14000) != '\0') {
            pcVar3 = (char *)(lVar2 + 14000);
            goto LAB_0023aee0;
          }
          goto LAB_0023b1a8;
        }
      }
      else if (((param_2 == 0x1a) && (param_4 == '\0')) && (param_3 == 0)) {
        if (*(char *)(lVar2 + 0x3870) != '\0') {
          pcVar3 = (char *)(lVar2 + 0x3870);
LAB_0023aee0:
          if (*(int *)(pcVar3 + 0xc) == 2) {
LAB_0023af38:
            uVar1 = *(uint *)(pcVar3 + 0x10);
            *param_5 = uVar1;
            return -(uint)(uVar1 == 0) & 0xfffffff5;
          }
          goto LAB_0023aee8;
        }
LAB_0023b1a8:
        uVar1 = 0xffffffff;
        goto LAB_0023ad97;
      }
    }
    else if (param_2 == 0x21) {
      if (param_4 == '\0') {
        if ((param_3 < 0x10) && (*(char *)(lVar2 + 0x5c30 + (ulong)param_3 * 0x20) != '\0')) {
          pcVar3 = (char *)(lVar2 + 0x5c30 + (ulong)param_3 * 0x20);
          cVar4 = *pcVar3;
          goto LAB_0023b340;
        }
      }
      else if (param_3 == 0) {
        if (*(char *)(lVar2 + 0x5e30) != '\0') {
          pcVar3 = (char *)(lVar2 + 0x5e30);
          goto LAB_0023af30;
        }
        goto LAB_0023b1a8;
      }
    }
    else if (param_2 < 0x22) {
      if (param_2 == 0x1d) {
        if ((param_4 == '\0') && (param_3 == 0)) {
          if (*(char *)(lVar2 + 0x3750) != '\0') {
            pcVar3 = (char *)(lVar2 + 0x3750);
            goto LAB_0023aee0;
          }
          goto LAB_0023b1a8;
        }
      }
      else if (param_2 == 0x1e) {
        if ((param_4 == '\0') && (param_3 == 0)) {
          if (*(char *)(lVar2 + 0x3770) != '\0') {
            pcVar3 = (char *)(lVar2 + 0x3770);
            goto LAB_0023aee0;
          }
          goto LAB_0023b1a8;
        }
      }
      else if (param_2 == 0x1c) {
        if (param_4 == '\0') {
          if ((param_3 < 4) && (*(char *)(lVar2 + 0x38b0 + (ulong)param_3 * 0x20) != '\0')) {
            pcVar3 = (char *)(lVar2 + 0x38b0 + (ulong)param_3 * 0x20);
            cVar4 = *pcVar3;
            goto LAB_0023b340;
          }
        }
        else if (param_3 == 0) {
          if (*(char *)(lVar2 + 0x3930) != '\0') {
            pcVar3 = (char *)(lVar2 + 0x3930);
            goto LAB_0023af30;
          }
          goto LAB_0023b1a8;
        }
      }
    }
    else if (param_2 == 0x22) {
      if (param_4 == '\0') {
        if ((param_3 < 0x10) && (*(char *)(lVar2 + 0x5a10 + (ulong)param_3 * 0x20) != '\0')) {
          pcVar3 = (char *)(lVar2 + 0x5a10 + (ulong)param_3 * 0x20);
          cVar4 = *pcVar3;
          goto LAB_0023b340;
        }
      }
      else if (param_3 == 0) {
        if (*(char *)(lVar2 + 0x5c10) != '\0') {
          pcVar3 = (char *)(lVar2 + 0x5c10);
          goto LAB_0023af30;
        }
        goto LAB_0023b1a8;
      }
    }
    else if (param_4 == '\0') {
      if ((param_3 < 0x40) && (*(char *)(lVar2 + 0x79f0 + (ulong)param_3 * 0x20) != '\0')) {
        pcVar3 = (char *)(lVar2 + 0x79f0 + (ulong)param_3 * 0x20);
        cVar4 = *pcVar3;
LAB_0023b340:
        if (cVar4 != '\0') goto LAB_0023aee0;
        goto LAB_0023afc8;
      }
    }
    else if ((param_3 < 4) && (*(char *)(lVar2 + 0x81f0 + (ulong)param_3 * 0x20) != '\0')) {
      pcVar3 = (char *)(lVar2 + 0x81f0 + (ulong)param_3 * 0x20);
      cVar4 = *pcVar3;
      goto LAB_0023afc0;
    }
  }
  else if (param_2 == 0x31) {
    if (param_4 == '\0') {
      if ((param_3 < 0x40) && (*(char *)(lVar2 + 0x42b0 + (ulong)param_3 * 0x20) != '\0')) {
        pcVar3 = (char *)(lVar2 + 0x42b0 + (ulong)param_3 * 0x20);
        cVar4 = *pcVar3;
        goto LAB_0023b340;
      }
    }
    else if ((param_3 < 4) && (*(char *)(lVar2 + 0x4ab0 + (ulong)param_3 * 0x20) != '\0')) {
      pcVar3 = (char *)(lVar2 + 0x4ab0 + (ulong)param_3 * 0x20);
      cVar4 = *pcVar3;
LAB_0023afc0:
      if (cVar4 != '\0') goto LAB_0023af30;
LAB_0023afc8:
      uVar1 = 0xfffffff7;
      param_3 = 0;
      goto LAB_0023ad97;
    }
  }
  else if (param_2 < 0x32) {
    if (param_2 == 0x29) {
      if (param_4 == '\0') {
        if ((param_3 < 0x40) && (*(char *)(lVar2 + 0x7170 + (ulong)param_3 * 0x20) != '\0')) {
          pcVar3 = (char *)(lVar2 + 0x7170 + (ulong)param_3 * 0x20);
          cVar4 = *pcVar3;
          goto LAB_0023b340;
        }
      }
      else if ((param_3 < 4) && (*(char *)(lVar2 + 0x7970 + (ulong)param_3 * 0x20) != '\0')) {
        pcVar3 = (char *)(lVar2 + 0x7970 + (ulong)param_3 * 0x20);
        cVar4 = *pcVar3;
        goto LAB_0023afc0;
      }
    }
    else if (param_2 < 0x2a) {
      if (param_2 == 0x27) {
        if (param_4 == '\0') {
          if ((param_3 < 0x40) && (*(char *)(lVar2 + 0x8270 + (ulong)param_3 * 0x20) != '\0')) {
            pcVar3 = (char *)(lVar2 + 0x8270 + (ulong)param_3 * 0x20);
            cVar4 = *pcVar3;
            goto LAB_0023b340;
          }
        }
        else if ((param_3 < 4) && (*(char *)(lVar2 + 0x8a70 + (ulong)param_3 * 0x20) != '\0')) {
          pcVar3 = (char *)(lVar2 + 0x8a70 + (ulong)param_3 * 0x20);
          cVar4 = *pcVar3;
          goto LAB_0023afc0;
        }
      }
      else if (param_2 == 0x28) {
        if (param_4 == '\0') {
          if ((param_3 < 0x10) && (*(char *)(lVar2 + 0x68f0 + (ulong)param_3 * 0x20) != '\0')) {
            pcVar3 = (char *)(lVar2 + 0x68f0 + (ulong)param_3 * 0x20);
            cVar4 = *pcVar3;
            goto LAB_0023b340;
          }
        }
        else if (param_3 == 0) {
          if (*(char *)(lVar2 + 0x6af0) == '\0') goto LAB_0023b1a8;
          pcVar3 = (char *)(lVar2 + 0x6af0);
          goto LAB_0023af30;
        }
      }
      else if (param_2 == 0x26) {
        if (param_4 == '\0') {
          if ((param_3 < 0x10) && (*(char *)(lVar2 + 0x57f0 + (ulong)param_3 * 0x20) != '\0')) {
            pcVar3 = (char *)(lVar2 + 0x57f0 + (ulong)param_3 * 0x20);
            cVar4 = *pcVar3;
            goto LAB_0023b340;
          }
        }
        else if (param_3 == 0) {
          if (*(char *)(lVar2 + 0x59f0) == '\0') goto LAB_0023b1a8;
          pcVar3 = (char *)(lVar2 + 0x59f0);
          goto LAB_0023af30;
        }
      }
    }
    else if (param_2 == 0x2a) {
      if (param_4 == '\0') {
        if ((param_3 < 0x10) && (*(char *)(lVar2 + 0x64b0 + (ulong)param_3 * 0x20) != '\0')) {
          pcVar3 = (char *)(lVar2 + 0x64b0 + (ulong)param_3 * 0x20);
          cVar4 = *pcVar3;
          goto LAB_0023b340;
        }
      }
      else if (param_3 == 0) {
        if (*(char *)(lVar2 + 0x66b0) == '\0') goto LAB_0023b1a8;
        pcVar3 = (char *)(lVar2 + 0x66b0);
LAB_0023af30:
        if (*(int *)(pcVar3 + 0xc) == 3) goto LAB_0023af38;
LAB_0023aee8:
        uVar1 = 0xfffffff5;
        param_3 = 0;
        goto LAB_0023ad97;
      }
    }
    else if (param_2 == 0x30) {
      if (param_4 == '\0') {
        if ((param_3 < 0x10) && (*(char *)(lVar2 + 0x3e70 + (ulong)param_3 * 0x20) != '\0')) {
          pcVar3 = (char *)(lVar2 + 0x3e70 + (ulong)param_3 * 0x20);
          cVar4 = *pcVar3;
          goto LAB_0023b340;
        }
      }
      else if (param_3 == 0) {
        if (*(char *)(lVar2 + 0x4070) == '\0') goto LAB_0023b1a8;
        pcVar3 = (char *)(lVar2 + 0x4070);
        goto LAB_0023af30;
      }
    }
  }
  else if (param_2 == 0x44) {
    if (param_4 == '\0') {
      if ((param_3 < 3) && (*(char *)(lVar2 + 0xa570 + (ulong)param_3 * 0x20) != '\0')) {
        pcVar3 = (char *)(lVar2 + 0xa570 + (ulong)param_3 * 0x20);
        cVar4 = *pcVar3;
        goto LAB_0023b340;
      }
    }
    else if (param_3 == 0) {
      if (*(char *)(lVar2 + 0xa5d0) == '\0') goto LAB_0023b1a8;
      pcVar3 = (char *)(lVar2 + 0xa5d0);
      goto LAB_0023af30;
    }
  }
  else if (param_2 < 0x45) {
    if (param_2 == 0x42) {
      if (param_4 == '\0') {
        if ((param_3 < 3) && (*(char *)(lVar2 + 0xa470 + (ulong)param_3 * 0x20) != '\0')) {
          pcVar3 = (char *)(lVar2 + 0xa470 + (ulong)param_3 * 0x20);
          cVar4 = *pcVar3;
          goto LAB_0023b340;
        }
      }
      else if (param_3 == 0) {
        if (*(char *)(lVar2 + 0xa4d0) == '\0') goto LAB_0023b1a8;
        pcVar3 = (char *)(lVar2 + 0xa4d0);
        goto LAB_0023af30;
      }
    }
    else if (param_2 == 0x43) {
      if (param_4 == '\0') {
        if ((param_3 < 0x24) && (*(char *)(lVar2 + 0xa670 + (ulong)param_3 * 0x20) != '\0')) {
          pcVar3 = (char *)(lVar2 + 0xa670 + (ulong)param_3 * 0x20);
          cVar4 = *pcVar3;
          goto LAB_0023b340;
        }
      }
      else if ((param_3 < 0xc) && (*(char *)(lVar2 + 0xaaf0 + (ulong)param_3 * 0x20) != '\0')) {
        pcVar3 = (char *)(lVar2 + 0xaaf0 + (ulong)param_3 * 0x20);
        cVar4 = *pcVar3;
        goto LAB_0023afc0;
      }
    }
    else if (param_2 == 0x32) {
      if (param_4 == '\0') {
        if ((param_3 < 0x10) && (*(char *)(lVar2 + 0x4b30 + (ulong)param_3 * 0x20) != '\0')) {
          pcVar3 = (char *)(lVar2 + 0x4b30 + (ulong)param_3 * 0x20);
          cVar4 = *pcVar3;
          goto LAB_0023b340;
        }
      }
      else if (param_3 == 0) {
        if (*(char *)(lVar2 + 0x4d30) == '\0') goto LAB_0023b1a8;
        pcVar3 = (char *)(lVar2 + 0x4d30);
        goto LAB_0023af30;
      }
    }
  }
  else if (param_2 == 0x45) {
    if (param_4 == '\0') {
      if ((param_3 < 0x24) && (*(char *)(lVar2 + 0xb370 + (ulong)param_3 * 0x20) != '\0')) {
        pcVar3 = (char *)(lVar2 + 0xb370 + (ulong)param_3 * 0x20);
        cVar4 = *pcVar3;
        goto LAB_0023b340;
      }
    }
    else if ((param_3 < 0xc) && (*(char *)(lVar2 + 0xb7f0 + (ulong)param_3 * 0x20) != '\0')) {
      pcVar3 = (char *)(lVar2 + 0xb7f0 + (ulong)param_3 * 0x20);
      cVar4 = *pcVar3;
      goto LAB_0023afc0;
    }
  }
  else if (param_2 == 0x46) {
    if (param_4 == '\0') {
      if ((param_3 < 3) && (*(char *)(lVar2 + 0xb270 + (ulong)param_3 * 0x20) != '\0')) {
        pcVar3 = (char *)(lVar2 + 0xb270 + (ulong)param_3 * 0x20);
        cVar4 = *pcVar3;
        goto LAB_0023b340;
      }
    }
    else if (param_3 == 0) {
      if (*(char *)(lVar2 + 0xb2d0) == '\0') goto LAB_0023b1a8;
      pcVar3 = (char *)(lVar2 + 0xb2d0);
      goto LAB_0023af30;
    }
  }
  uVar1 = 0xffffffff;
  param_3 = 0;
LAB_0023ad97:
  *param_5 = param_3;
  return uVar1;
}


// ===== 0023b680 nvswitch_get_num_links_ls10 =====

undefined8 nvswitch_get_num_links_ls10(void)

{
  return 0x40;
}


// ===== 0023b690 nvswitch_get_num_links_per_nvlipt_ls10 =====

undefined8 nvswitch_get_num_links_per_nvlipt_ls10(void)

{
  return 4;
}


// ===== 0023b69a nvswitch_get_latency_sample_interval_msec_ls10.cold =====

void nvswitch_get_latency_sample_interval_msec_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0023b6b0 nvswitch_get_latency_sample_interval_msec_ls10 =====

undefined4 nvswitch_get_latency_sample_interval_msec_ls10(long param_1)

{
  code *pcVar1;
  
  if (*(int *)(param_1 + 0x1f88) == 7) {
    return **(undefined4 **)(&DAT_0000dde0 + *(long *)(param_1 + 0x1f90));
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0023b6e0 nvswitch_is_soe_supported_ls10 =====

bool nvswitch_is_soe_supported_ls10(long param_1)

{
  return *(char *)(param_1 + 0x26) == '\0';
}


// ===== 0023b6f0 nvswitch_is_spi_supported_ls10 =====

undefined8 nvswitch_is_spi_supported_ls10(void)

{
  return 0;
}


// ===== 0023b700 nvswitch_get_bios_size_ls10 =====

undefined8 nvswitch_get_bios_size_ls10(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x100000;
  return 0;
}


// ===== 0023b70d nvswitch_get_link_public_id_ls10.cold =====

void nvswitch_get_link_public_id_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0023b720 nvswitch_get_link_public_id_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvswitch_get_link_public_id_ls10(long param_1,uint param_2,uint *param_3)

{
  code *pcVar1;
  char cVar2;
  
  cVar2 = (**(code **)(param_1 + 0x520))();
  if ((param_3 != (uint *)0x0) && (cVar2 != '\0')) {
    param_2 = param_2 >> 2;
    *param_3 = param_2;
    if (param_2 < 0x10) {
      if (*(int *)(param_1 + 0x1f88) == 7) {
        return -(uint)(*(char *)((ulong)param_2 * 0x20 + *(long *)(param_1 + 0x1f90) + 0x5a10) ==
                      '\0');
      }
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
  }
  return -1;
}


// ===== 0023b7a0 nvswitch_get_link_local_idx_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_get_link_local_idx_ls10(long param_1,uint param_2,uint *param_3)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = (**(code **)(param_1 + 0x520))();
  if ((param_3 == (uint *)0x0) || (cVar1 == '\0')) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
    *param_3 = param_2 & 3;
  }
  return uVar2;
}


// ===== 0023b7e0 nvswitch_get_remap_table_selector_ls10 =====

undefined8
nvswitch_get_remap_table_selector_ls10(undefined8 param_1,uint param_2,undefined4 *param_3)

{
  if (param_2 < 4) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(CSWTCH_135 + (ulong)param_2 * 4);
    }
    return 0;
  }
  return 0xfffffff3;
}


// ===== 0023b810 nvswitch_get_ingress_ram_size_ls10 =====

int nvswitch_get_ingress_ram_size_ls10(undefined8 param_1,uint param_2)

{
  int iVar1;
  
  if (param_2 < 5) {
    iVar1 = 0x40;
    if (param_2 < 3) {
      return (-(uint)(param_2 == 0) & 0x800) + 0x800;
    }
  }
  else {
    iVar1 = (uint)(param_2 == 0x4000) << 7;
  }
  return iVar1;
}


// ===== 0023b850 nvswitch_get_caps_nvlink_version_ls10 =====

undefined8 nvswitch_get_caps_nvlink_version_ls10(void)

{
  return 7;
}


// ===== 0023b860 nvswitch_get_bios_nvlink_config_ls10 =====

long nvswitch_get_bios_nvlink_config_ls10(long param_1)

{
  if (*(int *)(param_1 + 0x1f88) != 7) {
    return 0xbf78;
  }
  return *(long *)(param_1 + 0x1f90) + 0xbf78;
}


// ===== 0023b890 nvswitch_init_nxbar_ls10 =====

undefined8 nvswitch_init_nxbar_ls10(void)

{
  return 0;
}


// ===== 0023b8a0 nvswitch_get_max_persistent_message_count_ls10 =====

undefined8 nvswitch_get_max_persistent_message_count_ls10(void)

{
  return 0x80;
}


// ===== 0023b8b0 nvswitch_read_vbios_link_entries_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
nvswitch_read_vbios_link_entries_ls10
          (long param_1,int param_2,int param_3,undefined1 *param_4,int *param_5)

{
  undefined8 uVar1;
  undefined *puVar2;
  int iVar3;
  undefined1 local_60 [48];
  
  *param_5 = 0;
  if (param_3 == 0) {
    uVar1 = 0x3b;
  }
  else {
    iVar3 = 0;
    do {
      while( true ) {
        puVar2 = &DAT_00cc74dd;
        if (*(char *)(param_1 + 0x1fe8) != '\0') {
          puVar2 = &DAT_00cc74e1;
        }
        uVar1 = (**(code **)(param_1 + 0x790))(param_1,local_60,param_2,0,puVar2);
        if ((int)uVar1 != 0) {
          return uVar1;
        }
        *param_4 = (char)local_60._0_4_;
        param_4[1] = (char)local_60._4_4_;
        param_4[2] = (char)local_60._8_4_;
        param_4[3] = (char)local_60._12_4_;
        param_4[4] = (char)local_60._16_4_;
        param_4[5] = (char)local_60._20_4_;
        param_4[6] = (char)local_60._24_4_;
        if (*(char *)(param_1 + 0x1fe8) == '\0') break;
LAB_0023b994:
        iVar3 = iVar3 + 1;
        param_2 = param_2 + 7;
        param_4 = param_4 + 10;
        if (param_3 == iVar3) goto LAB_0023b9b5;
      }
      param_4[7] = (char)local_60._28_4_;
      param_4[8] = (char)local_60._32_4_;
      param_4[9] = (char)local_60._36_4_;
      if (*(char *)(param_1 + 0x1fe8) != '\0') goto LAB_0023b994;
      iVar3 = iVar3 + 1;
      param_2 = param_2 + 10;
      param_4 = param_4 + 10;
    } while (param_3 != iVar3);
  }
LAB_0023b9b5:
  *param_5 = param_3;
  return uVar1;
}


// ===== 0023b9f0 nvswitch_alloc_chipdevice_ls10 =====

long nvswitch_alloc_chipdevice_ls10(long param_1)

{
  long lVar1;
  
  lVar1 = nvswitch_os_malloc_trace(0xf8a0,0,0);
  if (lVar1 != 0) {
    nvswitch_os_memset(lVar1,0,0xf8a0);
  }
  *(undefined4 *)(param_1 + 0x1f88) = 7;
  return lVar1;
}


// ===== 0023ba40 nvswitch_ctrl_get_board_part_number_ls10 =====

undefined8 nvswitch_ctrl_get_board_part_number_ls10(long param_1,long param_2)

{
  char *pcVar1;
  long lVar2;
  undefined8 uVar3;
  
  pcVar1 = *(char **)(param_1 + 0xf40);
  if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
    uVar3 = 0xfffffff3;
  }
  else {
    nvswitch_os_memset(param_2,0,0x14);
    lVar2 = 0;
    do {
      *(char *)(param_2 + lVar2) = (char)*(undefined4 *)(pcVar1 + lVar2 * 4 + 0x210);
      lVar2 = lVar2 + 1;
    } while (lVar2 != 0x14);
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 0023bab0 nvswitch_ctrl_register_read_ls10 =====

int nvswitch_ctrl_register_read_ls10(long *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_1c;
  
  iVar1 = _nvswitch_get_engine_base_ls10(param_1,*param_2,param_2[1],0,&local_1c);
  if (iVar1 == 0) {
    if ((ulong)(uint)(local_1c + param_2[2]) < *(ulong *)(*param_1 + 0x68)) {
      uVar2 = nvswitch_reg_read_32();
      param_2[3] = uVar2;
    }
    else {
      iVar1 = -0xb;
    }
  }
  return iVar1;
}


// ===== 0023bb10 nvswitch_get_eng_base_ls10 =====

undefined4 nvswitch_get_eng_base_ls10(long param_1,uint param_2,int param_3,uint param_4)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  
  lVar3 = 0;
  if (*(int *)(param_1 + 0x1f88) == 7) {
    lVar3 = *(long *)(param_1 + 0x1f90);
  }
  if (0x2d < param_2) {
    return 0xffffffff;
  }
  uVar2 = (ulong)param_2;
  lVar1 = uVar2 * 0x128 + lVar3;
  if (param_2 != *(uint *)(lVar1 + 8)) {
    nvswitch_assert_log();
  }
  if (param_3 == 0) {
    if (param_4 < *(uint *)(lVar1 + 0xc)) {
      return *(undefined4 *)(lVar3 + ((ulong)param_4 + 4 + uVar2 * 0x4a) * 4);
    }
  }
  else {
    if (param_3 == 1) {
      return *(undefined4 *)(lVar3 + 0x110 + uVar2 * 0x128);
    }
    if ((param_3 == 2) && (param_4 < *(uint *)(lVar3 + 0x120 + uVar2 * 0x128))) {
      return *(undefined4 *)(lVar3 + 4 + ((ulong)param_4 + 0x44 + uVar2 * 0x4a) * 4);
    }
  }
  return 0xffffffff;
}


// ===== 0023bc00 nvswitch_check_io_sanity_ls10 =====

undefined8 nvswitch_check_io_sanity_ls10(long *param_1)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  undefined4 uVar6;
  ulong uVar7;
  undefined4 uVar8;
  char cVar9;
  char cVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  long lVar15;
  char *local_e0;
  undefined4 local_cc;
  undefined1 local_c8 [8];
  undefined8 local_c0;
  ulong local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined8 local_7c;
  ulong local_74;
  undefined8 local_6c;
  undefined8 local_64;
  undefined8 local_5c;
  undefined8 local_54;
  ulong local_4c;
  ulong local_44;
  undefined4 local_3c;
  
  uVar11 = nvswitch_reg_read_32(param_1,0);
  if (uVar11 == 0) {
    local_e0 = "Firmware recovery mode";
    local_cc = 0x2719;
  }
  else if ((uVar11 == 0xffffffff) || ((uVar11 & 0xffff0000) == 0xbadf0000)) {
    local_e0 = "IO failure";
    local_cc = 0x2717;
  }
  else {
    if (*(char *)((long)param_1 + 0x26) != '\0') {
      return 0;
    }
    nvswitch_timeout_create(10000000000,local_c8);
    do {
      cVar9 = nvswitch_timeout_check(local_c8);
      cVar10 = nvswitch_reg_read_32(param_1,0x660bc);
      if (cVar10 == -1) {
        return 0;
      }
      nvswitch_os_sleep(1);
    } while (cVar9 == '\0');
    local_e0 = "Firmware initialization failure";
    local_cc = 0x2718;
  }
  local_c0 = 0;
  lVar15 = 1;
  local_b8 = 0;
  local_b0 = 0;
  local_a8 = 0;
  local_a0 = 0;
  local_98 = 0;
  local_90 = 0;
  local_88 = 0;
  local_80 = 0;
  local_7c = 0;
  local_74 = 0;
  local_6c = 0;
  local_64 = 0;
  local_5c = 0;
  local_54 = 0;
  local_4c = 0;
  local_44 = 0;
  local_3c = 0;
  uVar12 = nvswitch_reg_read_32(param_1,0x660bc);
  do {
    uVar13 = nvswitch_reg_read_32(param_1,(int)lVar15 * 4 + 0x284dc);
    *(undefined4 *)((long)&local_7c + lVar15 * 4) = uVar13;
    lVar15 = lVar15 + 1;
  } while (lVar15 != 0x11);
  lVar15 = 2;
  do {
    uVar13 = nvswitch_reg_read_32(param_1,(int)lVar15 * 4 + 0x8f0318);
    *(undefined4 *)((long)&local_c0 + lVar15 * 4) = uVar13;
    lVar15 = lVar15 + 1;
  } while (lVar15 != 6);
  iVar14 = nvswitch_translate_hw_error(local_cc);
  if (iVar14 == 1) {
    nvswitch_assert_log();
  }
  uVar8 = local_3c;
  uVar7 = local_74;
  uVar5 = local_b0;
  uVar4 = local_b8;
  uVar1 = local_44 >> 0x20;
  uVar2 = local_4c >> 0x20;
  uVar6 = local_7c._4_4_;
  uVar13 = local_b0._4_4_;
  lVar15 = *param_1;
  uVar3 = local_b8 >> 0x20;
  nvswitch_os_print(5,
                    "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, %s (0x%x/0x%x, 0x%x, 0x%x, 0x%x/0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n"
                    ,param_1 + 1,*(undefined4 *)(lVar15 + 0x40),*(undefined1 *)(lVar15 + 0x44),
                    *(undefined1 *)(lVar15 + 0x45),*(undefined1 *)(lVar15 + 0x46),local_cc,local_e0,
                    uVar12,local_b8 & 0xffffffff,uVar3,local_b0 & 0xffffffff,local_b0._4_4_,
                    local_7c._4_4_,local_74 & 0xffffffff,uVar2,uVar1,local_3c);
  nvswitch_os_report_error
            (param_1[3],local_cc,
             "Fatal, %s (0x%x/0x%x, 0x%x, 0x%x, 0x%x/0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n",local_e0,uVar12
             ,uVar4 & 0xffffffff,uVar3,uVar5 & 0xffffffff,uVar13,uVar6,uVar7 & 0xffffffff,uVar2,
             uVar1,uVar8);
  nvswitch_lib_smbpbi_log_sxid
            (param_1,local_cc,
             "Fatal, %s (0x%x/0x%x, 0x%x, 0x%x, 0x%x/0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n",local_e0,uVar12
             ,uVar4 & 0xffffffff,uVar3,uVar5 & 0xffffffff,uVar13,uVar6,uVar7 & 0xffffffff,uVar2,
             uVar1,uVar8);
  return 0xfffffffb;
}


// ===== 0023bfc5 nvswitch_destroy_device_state_ls10.cold =====

void nvswitch_destroy_device_state_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0023bfd0 nvswitch_destroy_device_state_ls10 =====

void nvswitch_destroy_device_state_ls10(long param_1)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  
  if (*(int *)(param_1 + 0x1f88) == 7) {
    lVar1 = *(long *)(param_1 + 0x1f90);
    if ((&DAT_00003650)[lVar1] != '\0') {
      cVar3 = nvswitch_is_soe_supported();
      if (cVar3 != '\0') {
        cVar3 = nvswitch_is_tnvl_mode_enabled(param_1);
        if (cVar3 == '\0') {
          nvswitch_soe_unregister_events(param_1);
        }
        nvswitch_unload_soe_ls10(param_1);
      }
    }
    if (*(long *)(&DAT_0000dde0 + lVar1) != 0) {
      nvswitch_os_free();
    }
    if (*(long *)(lVar1 + 0xde90) != 0) {
      nvswitch_os_free();
    }
    nvswitch_free_chipdevice(param_1);
    nvswitch_i2c_destroy(param_1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 0023c070 nvswitch_initialize_pmgr_ls10 =====

undefined8 nvswitch_initialize_pmgr_ls10(undefined8 param_1)

{
  nvswitch_init_pmgr_ls10();
  nvswitch_init_pmgr_devices_ls10(param_1);
  return 0;
}


// ===== 0023c0a0 nvswitch_ctrl_set_residency_bins_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_ctrl_set_residency_bins_ls10(long param_1,int *param_2)

{
  char cVar1;
  ulong uVar2;
  code *pcVar3;
  undefined8 uVar4;
  uint uVar5;
  
  cVar1 = nvswitch_is_tnvl_mode_locked();
  if (cVar1 != '\0') {
    return 0xfffffff1;
  }
  uVar5 = param_2[2];
  if (uVar5 < (uint)param_2[1]) {
LAB_0023c220:
    uVar4 = 0xffffffff;
  }
  else {
    if (*param_2 == 0) {
      uVar2 = (ulong)uVar5 * 0x535;
      if (0x3e7ffffff < uVar2) goto LAB_0023c220;
      (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x273c,uVar2 / 1000);
      uVar4 = 0x2738;
      pcVar3 = *(code **)(param_1 + 0x928);
      uVar5 = (uint)(((ulong)(uint)param_2[1] * 0x535) / 1000);
    }
    else {
      if (*param_2 != 1) {
        return 0xfffffff3;
      }
      uVar2 = (ulong)uVar5 * 0x535;
      if (0x3e7ffffff < uVar2) goto LAB_0023c220;
      (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x2f3c,uVar2 / 1000);
      uVar4 = 0x2f38;
      pcVar3 = *(code **)(param_1 + 0x928);
      uVar5 = (uint)(((ulong)(uint)param_2[1] * 0x535) / 1000);
    }
    (*pcVar3)(param_1,5,1,0,uVar4,uVar5 & 0xffffff);
    uVar4 = 0;
  }
  return uVar4;
}


// ===== 0023c250 nvswitch_get_link_eng_inst_ls10 =====

uint nvswitch_get_link_eng_inst_ls10(undefined8 param_1,uint param_2,uint param_3)

{
  uint uVar1;
  ulong uVar2;
  
  uVar1 = nvswitch_get_num_links();
  if ((param_2 < uVar1) && (param_3 < 0x11)) {
    uVar2 = 1L << ((byte)param_3 & 0x3f);
    if ((uVar2 & 0x8e20) != 0) {
      return param_2;
    }
    if ((uVar2 & 66000) != 0) {
      return param_2 >> 2;
    }
  }
  return 0xffffffff;
}


// ===== 0023c2b0 nvswitch_ctrl_register_write_ls10 =====

ulong nvswitch_ctrl_register_write_ls10(long *param_1,undefined4 *param_2)

{
  char cVar1;
  ulong uVar2;
  int local_1c;
  
  cVar1 = nvswitch_is_tnvl_mode_locked();
  if (cVar1 == '\0') {
    uVar2 = _nvswitch_get_engine_base_ls10
                      (param_1,*param_2,param_2[1],*(undefined1 *)(param_2 + 2),&local_1c);
    if ((int)uVar2 == 0) {
      if ((ulong)(uint)(local_1c + param_2[3]) < *(ulong *)(*param_1 + 0x68)) {
        nvswitch_reg_write_32();
        uVar2 = uVar2 & 0xffffffff;
      }
      else {
        uVar2 = 0xfffffff5;
      }
    }
  }
  else {
    uVar2 = 0xfffffff1;
  }
  return uVar2;
}


// ===== 0023c330 nvswitch_ctrl_get_fom_values_ls10 =====

undefined4 nvswitch_ctrl_get_fom_values_ls10(undefined8 param_1,undefined4 *param_2)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  long lVar4;
  undefined4 local_2c [3];
  
  cVar1 = nvswitch_is_tnvl_mode_locked();
  if (cVar1 == '\0') {
    lVar4 = nvswitch_get_link(param_1,*(undefined1 *)param_2);
    if (lVar4 == 0) {
      uVar3 = 0xffffffff;
    }
    else {
      cVar1 = nvswitch_is_link_in_reset(param_1,lVar4);
      if (cVar1 == '\0') {
        nvswitch_minion_get_dl_status(param_1,*param_2,0xa0,0,local_2c);
        *(undefined4 *)((long)param_2 + 6) = local_2c[0];
        uVar3 = nvswitch_minion_get_dl_status(param_1,*param_2,0xa1,0,local_2c);
        *(undefined4 *)((long)param_2 + 10) = local_2c[0];
        uVar2 = nvswitch_get_sublink_width(param_1,*param_2);
        *(undefined1 *)(param_2 + 1) = uVar2;
      }
      else {
        uVar3 = 0xfffffff8;
      }
    }
  }
  else {
    uVar3 = 0xfffffff1;
  }
  return uVar3;
}


// ===== 0023c3e0 nvswitch_eng_wr_ls10 =====

undefined1  [16]
nvswitch_eng_wr_ls10
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
          ulong param_6)

{
  char cVar1;
  int iVar2;
  undefined1 auVar3 [16];
  
  iVar2 = nvswitch_get_eng_base_ls10();
  if (iVar2 == -1) {
    auVar3 = nvswitch_assert_log();
    return auVar3;
  }
  cVar1 = nvswitch_is_tnvl_mode_enabled(param_1);
  if (cVar1 != '\0') {
    nvswitch_tnvl_eng_wr_32_ls10(param_1,param_2,param_3,param_4,iVar2,param_5);
    auVar3._8_8_ = 0x23c41d;
    auVar3._0_8_ = param_6 & 0xffffffff;
    return auVar3;
  }
  auVar3 = nvswitch_reg_write_32(param_1,param_5 + iVar2,param_6 & 0xffffffff);
  return auVar3;
}


// ===== 0023c490 nvswitch_parse_bios_image_ls10 =====

void nvswitch_parse_bios_image_ls10(void)

{
  nvswitch_parse_bios_image_lr10();
  return;
}


// ===== 0023c4a0 nvswitch_ctrl_inband_send_data_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_ctrl_inband_send_data_ls10(long param_1,uint *param_2)

{
  uint uVar1;
  char cVar2;
  undefined8 uVar3;
  ulong uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *local_48;
  uint local_40;
  byte local_3c;
  
  if (0x13ff < *param_2 - 1) {
    return 0xffffffff;
  }
  cVar2 = (**(code **)(param_1 + 0x520))(param_1,param_2[1]);
  if (cVar2 != '\0') {
    uVar7 = *param_2;
    local_48 = param_2 + 2;
    local_3c = 1;
    uVar1 = param_2[1];
    uVar5 = uVar7 + 0xff >> 8;
    if (uVar5 == 0) {
      local_40 = uVar7;
      nvswitch_assert_log();
    }
    else {
      uVar4 = 0x100;
      if (uVar7 < 0x101) {
        uVar4 = (ulong)uVar7;
      }
      uVar6 = 0;
      do {
        if (uVar5 - 1 == uVar6) {
          local_3c = local_3c & 0xfd | 4;
        }
        local_40 = (int)uVar4;
        uVar3 = nvswitch_minion_send_inband_data_ls10(param_1,uVar1,&local_48);
        if ((int)uVar3 != 0) {
          return uVar3;
        }
        uVar7 = uVar7 - (int)uVar4;
        local_48 = (uint *)((long)local_48 + uVar4);
        local_3c = 2;
        uVar4 = 0x100;
        if (uVar7 < 0x101) {
          uVar4 = (ulong)uVar7;
        }
        uVar6 = uVar6 + 1;
      } while (uVar5 != uVar6);
    }
    param_2[0x502] = *param_2;
    return 0;
  }
  return 0xffffffff;
}


// ===== 0023c5f0 nvswitch_ctrl_inband_read_data_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_ctrl_inband_read_data_ls10(long param_1,undefined4 *param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = (**(code **)(param_1 + 0x520))(param_1,*param_2);
  if (cVar1 != '\0') {
    uVar2 = nvswitch_inband_read_data(param_1,param_2 + 2,*param_2,param_2 + 1);
    return uVar2;
  }
  return 0xffffffff;
}


// ===== 0023c640 nvswitch_ctrl_set_nvlink_error_threshold_ls10 =====

undefined8 nvswitch_ctrl_set_nvlink_error_threshold_ls10(undefined8 param_1,ulong *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  char cVar5;
  
  uVar4 = *param_2;
  if (uVar4 != 0) {
    cVar5 = '\0';
    while( true ) {
      for (; (uVar4 & 1) == 0; uVar4 = uVar4 >> 1) {
        cVar5 = cVar5 + '\x01';
      }
      lVar3 = nvswitch_get_link(param_1,cVar5);
      if (lVar3 != 0) {
        uVar2 = *(uint *)(lVar3 + 0x38);
        if ((*(byte *)((long)param_2 + (ulong)uVar2 * 0xc + 0x10) & 1) == 0) {
          *(undefined1 *)(lVar3 + 0xd4) = *(undefined1 *)((long)param_2 + (ulong)uVar2 * 0xc + 8);
          *(undefined1 *)(lVar3 + 0xd5) = *(undefined1 *)((long)param_2 + (ulong)uVar2 * 0xc + 9);
          *(undefined1 *)(lVar3 + 0xd6) = *(undefined1 *)((long)param_2 + (ulong)uVar2 * 0xc + 10);
          *(undefined1 *)(lVar3 + 0xd7) = *(undefined1 *)((long)param_2 + (ulong)uVar2 * 0xc + 0xb);
          uVar1 = *(undefined1 *)((long)param_2 + (ulong)uVar2 * 0xc + 0xc);
          *(undefined1 *)(lVar3 + 0xd9) = 1;
          *(undefined1 *)(lVar3 + 0xd8) = uVar1;
          nvswitch_configure_error_rate_threshold_interrupt_ls10(lVar3,0);
          nvswitch_set_error_rate_threshold_ls10(lVar3,0);
          nvswitch_configure_error_rate_threshold_interrupt_ls10
                    (lVar3,*(undefined1 *)
                            ((long)param_2 + (ulong)*(uint *)(lVar3 + 0x38) * 0xc + 0xc));
        }
        else {
          *(undefined1 *)(lVar3 + 0xd9) = 0;
          nvswitch_configure_error_rate_threshold_interrupt_ls10(lVar3,0);
          nvswitch_set_error_rate_threshold_ls10(lVar3,1);
          nvswitch_configure_error_rate_threshold_interrupt_ls10(lVar3,1);
        }
      }
      if (uVar4 >> 1 == 0) break;
      uVar4 = uVar4 >> 1;
      cVar5 = cVar5 + '\x01';
    }
  }
  return 0;
}


// ===== 0023c770 nvswitch_ctrl_get_nvlink_error_threshold_ls10 =====

undefined8 nvswitch_ctrl_get_nvlink_error_threshold_ls10(undefined8 param_1,ulong *param_2)

{
  long lVar1;
  ulong uVar2;
  char cVar3;
  
  uVar2 = *param_2;
  if (uVar2 != 0) {
    cVar3 = '\0';
    while( true ) {
      for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1) {
        cVar3 = cVar3 + '\x01';
      }
      lVar1 = nvswitch_get_link(param_1,cVar3);
      if (lVar1 != 0) {
        nvswitch_get_error_rate_threshold_ls10(lVar1);
        *(undefined1 *)((long)param_2 + (ulong)*(uint *)(lVar1 + 0x38) * 0xc + 8) =
             *(undefined1 *)(lVar1 + 0xd4);
        *(undefined1 *)((long)param_2 + (ulong)*(uint *)(lVar1 + 0x38) * 0xc + 9) =
             *(undefined1 *)(lVar1 + 0xd5);
        *(undefined1 *)((long)param_2 + (ulong)*(uint *)(lVar1 + 0x38) * 0xc + 10) =
             *(undefined1 *)(lVar1 + 0xd6);
        *(undefined1 *)((long)param_2 + (ulong)*(uint *)(lVar1 + 0x38) * 0xc + 0xb) =
             *(undefined1 *)(lVar1 + 0xd7);
        *(undefined1 *)((long)param_2 + (ulong)*(uint *)(lVar1 + 0x38) * 0xc + 0xc) =
             *(undefined1 *)(lVar1 + 0xd8);
        *(undefined1 *)((long)param_2 + (ulong)*(uint *)(lVar1 + 0x38) * 0xc + 0xd) =
             *(undefined1 *)(lVar1 + 0xda);
      }
      uVar2 = uVar2 >> 1;
      if (uVar2 == 0) break;
      cVar3 = cVar3 + '\x01';
    }
  }
  return 0;
}


// ===== 0023c890 nvswitch_ctrl_get_inforom_version_ls10 =====

undefined8 nvswitch_ctrl_get_inforom_version_ls10(long param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xf40);
  if ((lVar1 != 0) && (*(char *)(lVar1 + 0xe30) != '\0')) {
    nvswitch_inforom_string_copy(lVar1 + 0xe90,param_2,0x10);
    return 0;
  }
  return 0xfffffff3;
}


// ===== 0023c8d0 nvswitch_initialize_device_state_ls10 =====

void nvswitch_initialize_device_state_ls10(long param_1)

{
  *(undefined1 *)(param_1 + 0xf58) = 1;
  nvswitch_initialize_device_state_lr10();
  return;
}


// ===== 0023c8e0 nvswitch_ctrl_get_sw_info_ls10 =====

undefined8 nvswitch_ctrl_get_sw_info_ls10(undefined8 param_1,uint *param_2)

{
  uint *puVar1;
  undefined8 uVar2;
  
  if (0x20 < *param_2) {
    return 0xffffffff;
  }
  nvswitch_os_memset(param_2 + 0x21,0,0x80);
  if (*param_2 != 0) {
    puVar1 = param_2 + *param_2;
    uVar2 = 0;
    do {
      while (1 < param_2[1]) {
        param_2 = param_2 + 1;
        uVar2 = 0xffffffff;
        if (param_2 == puVar1) {
          return 0xffffffff;
        }
      }
      param_2[0x21] = 1;
      param_2 = param_2 + 1;
    } while (param_2 != puVar1);
    return uVar2;
  }
  return 0;
}


// ===== 0023c960 nvswitch_is_bios_supported_ls10 =====

bool nvswitch_is_bios_supported_ls10(long param_1)

{
  char cVar1;
  
  if (*(char *)(param_1 + 0x25) != '\0') {
    return false;
  }
  if ((*(char *)(param_1 + 0x24) == '\0') && (*(char *)(param_1 + 0x26) == '\0')) {
    cVar1 = nvswitch_is_soe_supported();
    return cVar1 != '\0';
  }
  return false;
}


// ===== 0023c9a0 nvswitch_initialize_ip_wrappers_ls10 =====

void nvswitch_initialize_ip_wrappers_ls10(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = nvswitch_nvs_top_prod_ls10();
  if (iVar1 == 0) {
    iVar1 = nvswitch_apply_prod_nvlw_ls10(param_1);
    if (iVar1 == 0) {
      nvswitch_apply_prod_nxbar_ls10(param_1);
      return;
    }
  }
  return;
}


// ===== 0023c9e0 nvswitch_reg_write_32_ls10 =====

void nvswitch_reg_write_32_ls10(long *param_1,uint param_2,undefined4 param_3)

{
  char cVar1;
  
  if (*(long *)(*param_1 + 0x78) == 0) {
    return;
  }
  cVar1 = nvswitch_is_tnvl_mode_enabled();
  if (cVar1 != '\0') {
    nvswitch_tnvl_reg_wr_32_ls10(param_1,param_2,param_3);
    return;
  }
  nvswitch_os_mem_write32((ulong)param_2 + *(long *)(*param_1 + 0x78),param_3);
  return;
}


// ===== 0023ca40 nvswitch_update_link_state_led_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void nvswitch_update_link_state_led_ls10(long param_1)

{
  long lVar1;
  long lVar2;
  bool bVar3;
  byte bVar4;
  char cVar5;
  byte bVar6;
  ulong uVar7;
  undefined2 *puVar8;
  byte bVar9;
  ulong *puVar10;
  undefined8 uVar11;
  long *plVar12;
  byte bVar13;
  ulong uVar14;
  int iVar15;
  undefined1 auVar16 [16];
  byte local_58;
  ulong local_40 [2];
  
  bVar4 = *(byte *)(param_1 + 0xd30) & 0xf;
  uVar7 = nvswitch_get_enabled_link_mask();
  if (uVar7 != 0) {
    iVar15 = 0;
    uVar14 = uVar7;
    do {
      if ((uVar7 & 1) != 0) {
        cVar5 = cciIsLinkManaged(param_1,iVar15);
        if (cVar5 != '\0') {
          uVar14 = ~(1L << ((byte)iVar15 & 0x3f)) & uVar14;
        }
        if (uVar7 >> 1 == 0) goto LAB_0023cac0;
      }
      uVar7 = uVar7 >> 1;
      iVar15 = iVar15 + 1;
    } while( true );
  }
LAB_0023cc18:
  nvswitch_assert_log();
  *(undefined1 *)(param_1 + 0xd31) = 5;
  if (bVar4 == 5) {
    return;
  }
  nvswitch_assert_log();
  bVar13 = 5;
  uVar11 = 0;
LAB_0023cc40:
  iVar15 = nvswitch_cci_ports_cpld_write(param_1,0x31,uVar11);
  if (iVar15 != 0) {
    return;
  }
  *(byte *)(param_1 + 0xd30) = bVar13;
  return;
LAB_0023cac0:
  if (uVar14 != 0) {
    bVar13 = 5;
    cVar5 = '\0';
    local_58 = *(byte *)(param_1 + 0xd30) & 0xf;
    uVar7 = uVar14;
joined_r0x0023caf4:
    for (; (uVar7 & 1) == 0; uVar7 = uVar7 >> 1) {
      cVar5 = cVar5 + '\x01';
    }
    auVar16 = nvswitch_get_link(param_1,cVar5);
    if ((auVar16._0_8_ == 0) ||
       (iVar15 = (**(code **)(param_1 + 0x6b8))
                           (auVar16._0_8_,local_40,auVar16._8_8_,*(code **)(param_1 + 0x6b8)),
       iVar15 != 0)) {
LAB_0023cb37:
      if (bVar13 != 0) {
        bVar13 = 1;
      }
    }
    else if (local_40[0] == 3) {
      bVar13 = 0;
    }
    else {
      if (local_40[0] < 4) {
        if (local_40[0] == 0) goto LAB_0023cb37;
        if (local_40[0] != 1) goto LAB_0023cb9c;
      }
      else if ((local_40[0] != 4) && (local_40[0] != 10)) {
LAB_0023cb9c:
        bVar6 = 2;
        if (bVar13 < 3) {
          bVar6 = bVar13;
        }
        bVar9 = 1;
        if (bVar13 == 0) {
          bVar9 = bVar13;
        }
        bVar13 = bVar6;
        if (local_58 != 2) {
          bVar13 = bVar9;
        }
        goto LAB_0023cb42;
      }
      if (3 < bVar13) {
        bVar13 = 3;
      }
    }
LAB_0023cb42:
    if (uVar7 >> 1 != 0) {
      cVar5 = cVar5 + '\x01';
      uVar7 = uVar7 >> 1;
      goto joined_r0x0023caf4;
    }
    if (bVar13 != 3) {
      *(byte *)(param_1 + 0xd31) = bVar13;
      if (bVar4 == bVar13) {
        return;
      }
      uVar11 = 0;
      if (bVar13 != 1) {
        if (bVar13 == 2) {
          uVar11 = 3;
        }
        else {
          bVar13 = 0;
          uVar11 = 5;
        }
      }
      goto LAB_0023cc40;
    }
    puVar8 = (undefined2 *)nvswitch_os_malloc_trace(0x810,0,0);
    if (puVar8 == (undefined2 *)0x0) {
      nvswitch_os_free(0);
    }
    else {
      *(ulong *)(puVar8 + 4) = uVar14;
      *puVar8 = 3;
      iVar15 = nvswitch_ctrl_get_throughput_counters(param_1);
      if (iVar15 == 0) {
        puVar10 = (ulong *)(param_1 + 0xd38);
        plVar12 = (long *)(puVar8 + 0xc);
        bVar3 = false;
        do {
          if ((uVar14 & 1) != 0) {
            uVar7 = *puVar10;
            lVar1 = plVar12[1];
            lVar2 = *plVar12;
            *puVar10 = lVar1 + lVar2;
            bVar3 = (bool)(bVar3 | uVar7 < (ulong)(lVar1 + lVar2));
            if (uVar14 >> 1 == 0) goto LAB_0023cd48;
          }
          uVar14 = uVar14 >> 1;
          puVar10 = puVar10 + 1;
          plVar12 = plVar12 + 4;
        } while( true );
      }
      nvswitch_os_free(puVar8);
    }
    goto LAB_0023cd0f;
  }
  goto LAB_0023cc18;
LAB_0023cd48:
  nvswitch_os_free(puVar8);
  if (bVar3) {
    *(undefined1 *)(param_1 + 0xd31) = 4;
    if (bVar4 == 4) {
      return;
    }
    bVar13 = 4;
    uVar11 = 4;
    goto LAB_0023cc40;
  }
LAB_0023cd0f:
  *(undefined1 *)(param_1 + 0xd31) = 3;
  if (bVar4 == 3) {
    return;
  }
  uVar11 = 2;
  goto LAB_0023cc40;
}


// ===== 0023cd90 nvswitch_get_device_dma_width_ls10 =====

undefined8 nvswitch_get_device_dma_width_ls10(void)

{
  return 0x40;
}


// ===== 0023cda0 nvswitch_init_warm_reset_ls10 =====

void nvswitch_init_warm_reset_ls10(void)

{
  return;
}


// ===== 0023cdb0 nvswitch_post_init_blacklist_device_setup_ls10 =====

void nvswitch_post_init_blacklist_device_setup_ls10(void)

{
  return;
}


// ===== 0023cdc0 nvswitch_send_inband_nack_ls10 =====

void nvswitch_send_inband_nack_ls10(undefined8 param_1,long param_2,undefined4 param_3)

{
  long local_18;
  undefined4 local_10;
  undefined1 local_c;
  
  *(undefined4 *)(param_2 + 10) = 0x7a;
  if ((*(short *)(param_2 + 0xe) != 2) && (*(short *)(param_2 + 0xe) != 5)) {
    return;
  }
  *(undefined2 *)(param_2 + 0xe) = 3;
  *(undefined4 *)(param_2 + 0x10) = 0;
  local_10 = 0x1c;
  local_c = 5;
  local_18 = param_2;
  nvswitch_minion_send_inband_data_ls10(param_1,param_3,&local_18);
  return;
}


// ===== 0023ce20 nvswitch_get_eng_count_ls10 =====

uint nvswitch_get_eng_count_ls10(long param_1,uint param_2,int param_3)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  
  lVar2 = 0;
  if (*(int *)(param_1 + 0x1f88) == 7) {
    lVar2 = *(long *)(param_1 + 0x1f90);
  }
  if (0x2d < param_2) {
    return 0;
  }
  uVar3 = (ulong)param_2;
  lVar1 = uVar3 * 0x128 + lVar2;
  if (param_2 != *(uint *)(lVar1 + 8)) {
    nvswitch_assert_log();
  }
  if (param_3 == 0) {
    return *(uint *)(lVar1 + 0xc);
  }
  if (param_3 == 1) {
    return (uint)(*(int *)(lVar2 + 0x110 + uVar3 * 0x128) != -1);
  }
  if (param_3 == 2) {
    return *(uint *)(lVar2 + 0x120 + uVar3 * 0x128);
  }
  return 0;
}


// ===== 0023cee0 nvswitch_led_shutdown_ls10 =====

void nvswitch_led_shutdown_ls10(long param_1)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0xd31) = 1;
  iVar1 = nvswitch_cci_ports_cpld_write(param_1,0x31,0);
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 0xd30) = 1;
  }
  return;
}


// ===== 0023cf14 nvswitch_ctrl_get_soe_heartbeat_ls10.cold =====

void nvswitch_ctrl_get_soe_heartbeat_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0023cf30 nvswitch_ctrl_get_soe_heartbeat_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_ctrl_get_soe_heartbeat_ls10(long param_1,ulong *param_2)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  undefined8 uVar7;
  ulong uVar8;
  
  cVar2 = nvswitch_is_cci_supported();
  if (cVar2 == '\0') {
    uVar7 = 0xfffffff3;
  }
  else {
    uVar3 = nvswitch_reg_read_32(param_1,0x2120c);
LAB_0023cf8b:
    do {
      if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)invalidInstructionException();
          (*pcVar6)();
        }
        lVar1 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(&DAT_000031c0 + lVar1) != 0x2b) {
          nvswitch_assert_log();
        }
        if ((*(int *)(lVar1 + 0x31c4) == 0) || (*(int *)(lVar1 + 0x31c8) == -1)) {
          nvswitch_assert_log();
          uVar5 = 0xbadfbadf;
          goto LAB_0023cfdd;
        }
        uVar5 = nvswitch_reg_read_32(param_1,*(int *)(lVar1 + 0x31c8) + 0x410);
        pcVar6 = *(code **)(param_1 + 0x920);
        if (pcVar6 != nvswitch_eng_rd_ls10) goto LAB_0023d15d;
LAB_0023cff0:
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)invalidInstructionException();
          (*pcVar6)();
        }
        lVar1 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(&DAT_000031c0 + lVar1) != 0x2b) {
          nvswitch_assert_log();
        }
        if ((*(int *)(lVar1 + 0x31c4) == 0) || (*(int *)(lVar1 + 0x31c8) == -1)) {
          nvswitch_assert_log();
          uVar8 = 0xbadfbadf;
          goto LAB_0023d02d;
        }
        uVar4 = nvswitch_reg_read_32(param_1,*(int *)(lVar1 + 0x31c8) + 0x400);
        uVar8 = (ulong)uVar4;
        pcVar6 = *(code **)(param_1 + 0x920);
        if (pcVar6 != nvswitch_eng_rd_ls10) goto LAB_0023d104;
LAB_0023d040:
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)invalidInstructionException();
          (*pcVar6)();
        }
        lVar1 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(&DAT_000031c0 + lVar1) != 0x2b) {
          nvswitch_assert_log();
        }
        if ((*(int *)(lVar1 + 0x31c4) != 0) && (*(int *)(lVar1 + 0x31c8) != -1)) {
          uVar4 = nvswitch_reg_read_32(param_1,*(int *)(lVar1 + 0x31c8) + 0x410);
          if (uVar4 == uVar5) break;
          goto LAB_0023cf8b;
        }
        nvswitch_assert_log();
        uVar4 = 0xbadfbadf;
      }
      else {
        uVar5 = (**(code **)(param_1 + 0x920))(param_1,0x2b,0,0,0x410);
LAB_0023cfdd:
        pcVar6 = *(code **)(param_1 + 0x920);
        if (pcVar6 == nvswitch_eng_rd_ls10) goto LAB_0023cff0;
LAB_0023d15d:
        uVar4 = (*pcVar6)(param_1,0x2b,0,0,0x400);
        uVar8 = (ulong)uVar4;
LAB_0023d02d:
        pcVar6 = *(code **)(param_1 + 0x920);
        if (pcVar6 == nvswitch_eng_rd_ls10) goto LAB_0023d040;
LAB_0023d104:
        uVar4 = (*pcVar6)(param_1,0x2b,0,0,0x410);
      }
    } while (uVar4 != uVar5);
    *param_2 = (ulong)uVar4 << 0x20 | uVar8;
    *(uint *)(param_2 + 1) = (uint)((uVar3 & 0x1000) != 0);
    uVar7 = 0;
  }
  return uVar7;
}


// ===== 0023d1a9 nvswitch_ctrl_get_internal_latency_ls10.cold =====

void nvswitch_ctrl_get_internal_latency_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0023d1c0 nvswitch_ctrl_get_internal_latency_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r15 replaced with injection: x86_indirect_thunk_r15 */

undefined8 nvswitch_ctrl_get_internal_latency_ls10(long param_1,uint *param_2)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  
  lVar8 = 0;
  if (*(int *)(param_1 + 0x1f88) == 7) {
    lVar8 = *(long *)(param_1 + 0x1f90);
  }
  uVar6 = *param_2;
  if (uVar6 < 8) {
    cVar3 = nvswitch_is_tnvl_mode_locked();
    if (cVar3 == '\0') {
      nvswitch_os_memset(param_2,0,0xa10);
      *param_2 = uVar6;
      uVar9 = 0;
      nvswitch_internal_latency_bin_log(param_1);
      while( true ) {
        uVar4 = nvswitch_get_num_links(param_1);
        if (uVar4 <= (uint)uVar9) break;
        pcVar2 = *(code **)(param_1 + 0x910);
        uVar4 = nvswitch_get_link_eng_inst(param_1,uVar9,5);
        if (pcVar2 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)invalidInstructionException();
            (*pcVar2)();
          }
          lVar10 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar10 + 0x5d0) != 5) {
            nvswitch_assert_log();
          }
          if (uVar4 < *(uint *)(lVar10 + 0x5d4)) {
            iVar5 = *(int *)(lVar10 + 0x5d8 + (ulong)uVar4 * 4);
            goto LAB_0023d28b;
          }
        }
        else {
          iVar5 = (*pcVar2)(param_1,5,0,uVar4);
LAB_0023d28b:
          if (iVar5 != -1) {
            cVar3 = nvswitch_is_link_valid(param_1,uVar9);
            if (cVar3 != '\0') {
              lVar10 = (ulong)uVar6 * 0x518 + uVar9 * 0x14;
              *(ulong *)(param_2 + uVar9 * 10 + 4) =
                   (ulong)*(uint *)(*(long *)(&DAT_0000dde0 + lVar8) + lVar10 + 0x2c);
              *(ulong *)(param_2 + uVar9 * 10 + 6) =
                   (ulong)*(uint *)(*(long *)(&DAT_0000dde0 + lVar8) + lVar10 + 0x30);
              *(ulong *)(param_2 + uVar9 * 10 + 8) =
                   (ulong)*(uint *)(*(long *)(&DAT_0000dde0 + lVar8) + lVar10 + 0x34);
              *(ulong *)(param_2 + uVar9 * 10 + 10) =
                   (ulong)*(uint *)(*(long *)(&DAT_0000dde0 + lVar8) + lVar10 + 0x38);
              *(ulong *)(param_2 + uVar9 * 10 + 0xc) =
                   (ulong)*(uint *)(lVar10 + *(long *)(&DAT_0000dde0 + lVar8) + 0x28);
            }
          }
        }
        uVar9 = (ulong)((uint)uVar9 + 1);
      }
      lVar10 = (ulong)uVar6 * 0x518;
      *(ulong *)(param_2 + 2) =
           (ulong)(*(long *)(*(long *)(&DAT_0000dde0 + lVar8) + lVar10 + 0x20) -
                  *(long *)(*(long *)(&DAT_0000dde0 + lVar8) + lVar10 + 0x18)) / 1000000;
      *(undefined8 *)(*(long *)(&DAT_0000dde0 + lVar8) + lVar10 + 0x18) =
           *(undefined8 *)(*(long *)(&DAT_0000dde0 + lVar8) + lVar10 + 0x20);
      *(undefined4 *)(*(long *)(&DAT_0000dde0 + lVar8) + lVar10 + 0x10) = 0;
      uVar9 = 0;
      while( true ) {
        uVar6 = nvswitch_get_num_links(param_1);
        if (uVar6 <= (uint)uVar9) break;
        lVar1 = lVar10 + uVar9 * 0x14;
        *(undefined4 *)(*(long *)(&DAT_0000dde0 + lVar8) + lVar1 + 0x2c) = 0;
        *(undefined4 *)(*(long *)(&DAT_0000dde0 + lVar8) + lVar1 + 0x30) = 0;
        *(undefined4 *)(*(long *)(&DAT_0000dde0 + lVar8) + lVar1 + 0x34) = 0;
        *(undefined4 *)(*(long *)(&DAT_0000dde0 + lVar8) + lVar1 + 0x38) = 0;
        *(undefined4 *)(lVar1 + *(long *)(&DAT_0000dde0 + lVar8) + 0x28) = 0;
        uVar9 = (ulong)((uint)uVar9 + 1);
      }
      uVar7 = 0;
    }
    else {
      uVar7 = 0xfffffff1;
    }
  }
  else {
    uVar7 = 0xffffffff;
  }
  return uVar7;
}


// ===== 0023d455 nvswitch_ctrl_set_latency_bins_ls10.cold =====

void nvswitch_ctrl_set_latency_bins_ls10_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  undefined8 unaff_R13;
  
  *(undefined8 *)(unaff_RBP + -0x18) = unaff_R13;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0023d480 nvswitch_ctrl_set_latency_bins_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_ctrl_set_latency_bins_ls10(long param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  code *pcVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  
  cVar8 = nvswitch_is_tnvl_mode_locked();
  if (cVar8 != '\0') {
    return 0xfffffff1;
  }
  iVar10 = 0x10c;
  while( true ) {
    uVar1 = *param_2;
    if ((0x2706 < uVar1 - 10) || (uVar2 = param_2[1], 0x2706 < uVar2 - 10)) {
      return 0xffffffff;
    }
    uVar3 = param_2[2];
    if (0x2706 < uVar3 - 10) {
      return 0xffffffff;
    }
    if (uVar2 < uVar1) break;
    if (uVar3 < uVar2) {
      return 0xffffffff;
    }
    uVar5 = 1330000000 / (1000000000 / (ulong)uVar1);
    *param_2 = (uint)uVar5;
    param_2[1] = (uint)(1330000000 / (1000000000 / (ulong)uVar2));
    uVar6 = 1000000000 / (ulong)uVar3;
    param_2[2] = (uint)(1330000000 / uVar6);
    if (*(code **)(param_1 + 0x910) == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)invalidInstructionException();
        (*pcVar7)();
      }
      lVar4 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar4 + 0x5d0) != 5) {
        nvswitch_assert_log(uVar3,uVar6,1330000000 % uVar6);
      }
      iVar9 = *(int *)(lVar4 + 0x6d8);
    }
    else {
      iVar9 = (**(code **)(param_1 + 0x910))(param_1,5,1,0);
    }
    nvswitch_reg_write_32(param_1,iVar9 + -4 + iVar10,uVar5);
    uVar1 = param_2[1];
    if (*(code **)(param_1 + 0x910) == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)invalidInstructionException();
        (*pcVar7)();
      }
      lVar4 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar4 + 0x5d0) != 5) {
        nvswitch_assert_log();
      }
      iVar9 = *(int *)(lVar4 + 0x6d8);
    }
    else {
      iVar9 = (**(code **)(param_1 + 0x910))(param_1,5,1,0);
    }
    nvswitch_reg_write_32(param_1,iVar9 + iVar10,uVar1);
    uVar1 = param_2[2];
    if (*(code **)(param_1 + 0x910) == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)invalidInstructionException();
        (*pcVar7)();
      }
      lVar4 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar4 + 0x5d0) != 5) {
        nvswitch_assert_log();
      }
      iVar9 = *(int *)(lVar4 + 0x6d8);
    }
    else {
      iVar9 = (**(code **)(param_1 + 0x910))(param_1,5,1,0);
    }
    iVar9 = iVar9 + 4 + iVar10;
    iVar10 = iVar10 + 0x34;
    nvswitch_reg_write_32(param_1,iVar9,uVar1);
    param_2 = param_2 + 3;
    if (iVar10 == 0x2ac) {
      return 0;
    }
  }
  return 0xffffffff;
}


// ===== 0023d726 nvswitch_clear_nport_rams_ls10.cold =====

void nvswitch_clear_nport_rams_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0023d760 nvswitch_clear_nport_rams_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_clear_nport_rams_ls10(long param_1)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  undefined1 local_40 [16];
  
  uVar8 = 0;
  uVar7 = 0;
  do {
    uVar6 = (uint)uVar7;
    if (*(code **)(param_1 + 0x918) == nvswitch_get_eng_count_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar1 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar1 + 0x5d0) != 5) {
        nvswitch_assert_log();
      }
      uVar4 = *(uint *)(lVar1 + 0x5d4);
    }
    else {
      uVar4 = (**(code **)(param_1 + 0x918))(param_1,5,0);
    }
    if (uVar4 <= uVar6) {
      (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x4c,0x7ff01);
      nvswitch_timeout_create(25000000,local_40);
      do {
        uVar7 = 0;
        cVar3 = nvswitch_timeout_check(local_40);
        while( true ) {
          uVar6 = (uint)uVar7;
          if (*(code **)(param_1 + 0x918) == nvswitch_get_eng_count_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)invalidInstructionException();
              (*pcVar2)();
            }
            lVar1 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar1 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            uVar4 = *(uint *)(lVar1 + 0x5d4);
          }
          else {
            uVar4 = (**(code **)(param_1 + 0x918))(param_1,5,0);
          }
          if (uVar4 <= uVar6) break;
          if (*(code **)(param_1 + 0x910) == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)invalidInstructionException();
              (*pcVar2)();
            }
            lVar1 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar1 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if (uVar6 < *(uint *)(lVar1 + 0x5d4)) {
              iVar5 = *(int *)(lVar1 + 0x5d8 + uVar7 * 4);
              goto LAB_0023d915;
            }
          }
          else {
            iVar5 = (**(code **)(param_1 + 0x910))(param_1,5,0,uVar7);
LAB_0023d915:
            if ((iVar5 != -1) && ((uVar8 >> (uVar7 & 0x3f) & 1) != 0)) {
              if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
                if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                  pcVar2 = (code *)invalidInstructionException();
                  (*pcVar2)();
                }
                lVar1 = *(long *)(param_1 + 0x1f90);
                if (*(int *)(lVar1 + 0x5d0) != 5) {
                  nvswitch_assert_log();
                }
                if ((*(uint *)(lVar1 + 0x5d4) <= uVar6) ||
                   (iVar5 = *(int *)(lVar1 + 0x5d8 + uVar7 * 4), iVar5 == -1)) {
                  nvswitch_assert_log();
                  goto LAB_0023d970;
                }
                iVar5 = nvswitch_reg_read_32(param_1,iVar5 + 0x4c);
              }
              else {
                iVar5 = (**(code **)(param_1 + 0x920))(param_1,5,0,uVar7,0x4c);
              }
              if (iVar5 == 0x7ff01) {
                uVar8 = ~(1L << ((byte)uVar7 & 0x3f)) & uVar8;
              }
            }
          }
LAB_0023d970:
          uVar7 = (ulong)(uVar6 + 1);
        }
        if (uVar8 == 0) {
          return 0;
        }
        nvswitch_os_sleep(1);
        if (cVar3 != '\0') {
          return 0xfffffff8;
        }
      } while( true );
    }
    if (*(code **)(param_1 + 0x910) == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar1 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar1 + 0x5d0) != 5) {
        nvswitch_assert_log();
      }
      if (uVar6 < *(uint *)(lVar1 + 0x5d4)) {
        iVar5 = *(int *)(lVar1 + 0x5d8 + uVar7 * 4);
        goto LAB_0023d805;
      }
    }
    else {
      iVar5 = (**(code **)(param_1 + 0x910))(param_1,5,0,uVar7);
LAB_0023d805:
      if (iVar5 != -1) {
        uVar8 = uVar8 | 1L << (uVar7 & 0x3f);
      }
    }
    uVar7 = (ulong)(uVar6 + 1);
  } while( true );
}


// ===== 0023da7b nvswitch_get_nvlink_ecc_errors_ls10.cold =====

void nvswitch_get_nvlink_ecc_errors_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0023daa0 nvswitch_get_nvlink_ecc_errors_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

undefined8 nvswitch_get_nvlink_ecc_errors_ls10(long param_1,ulong *param_2)

{
  code *pcVar1;
  long lVar2;
  char cVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  long lVar9;
  ulong *puVar10;
  undefined8 uVar11;
  uint uVar12;
  byte bVar13;
  ulong *puVar14;
  ulong uVar15;
  ulong *puVar16;
  uint uVar17;
  uint local_3c [3];
  
  cVar3 = nvswitch_is_tnvl_mode_locked();
  if (cVar3 == '\0') {
    nvswitch_os_memset(param_2 + 1,0,0xe00);
    uVar15 = *param_2;
    if (uVar15 == 0) {
      return 0;
    }
    uVar17 = 0;
    puVar14 = param_2;
    for (; uVar5 = (uint)uVar15 & 1, (uVar15 & 1) == 0; uVar15 = uVar15 >> 1) {
LAB_0023db03:
      uVar17 = uVar17 + 1;
      puVar14 = puVar14 + 7;
    }
    lVar9 = nvswitch_get_link(param_1,uVar17 & 0xff);
    if (lVar9 != 0) {
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar9 + 0x38),0xb);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0xcc0) != 0xb) {
          nvswitch_assert_log();
        }
        if (*(uint *)(lVar2 + 0xcc4) <= uVar6) goto LAB_0023dcc0;
        iVar8 = *(int *)(lVar2 + 0xcc8 + (ulong)uVar6 * 4);
      }
      else {
        iVar8 = (*pcVar1)(param_1,0xb,0);
      }
      if (((iVar8 != -1) &&
          (cVar3 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar9 + 0x38)), cVar3 != '\0')) &&
         (uVar6 = nvswitch_get_num_links(param_1), uVar17 < uVar6)) {
        uVar6 = (**(code **)(param_1 + 0xa40))(param_1,uVar17);
        uVar7 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar9 + 0x38),7);
        cVar3 = nvswitch_is_minion_initialized(param_1,uVar7);
        puVar16 = puVar14 + 1;
        cVar4 = nvswitch_link_lane_reversed_lr10(param_1,*(undefined4 *)(lVar9 + 0x38));
        while( true ) {
          if ((uVar5 - 1 < uVar6) && (cVar3 != '\0')) {
            uVar11 = nvswitch_minion_get_dl_status(param_1,uVar17,uVar5 + 0x4b,0,local_3c);
            if ((int)uVar11 != 0) {
              return uVar11;
            }
            uVar12 = (uVar6 & 0xff) - uVar5;
            if (cVar4 == '\0') {
              uVar12 = uVar5 - 1;
            }
            puVar10 = (ulong *)((long)puVar14 + ((ulong)uVar12 & 0xff) * 0xc + 8);
            *(undefined1 *)((long)param_2 + (ulong)uVar17 * 0x38 + (ulong)(uVar12 & 0xff) * 0xc + 8)
                 = 1;
            bVar13 = (byte)(local_3c[0] >> 0x1f);
            uVar12 = local_3c[0] & 0x7fffffff;
          }
          else {
            local_3c[0] = 0;
            bVar13 = 0;
            uVar12 = 0;
            *(undefined1 *)puVar16 = 0;
            puVar10 = puVar16;
          }
          *(uint *)((long)puVar10 + 4) = uVar12;
          puVar16 = (ulong *)((long)puVar16 + 0xc);
          *(byte *)(puVar10 + 1) = bVar13;
          if (uVar5 == 2) break;
          uVar5 = 2;
        }
        if (cVar3 == '\0') {
          local_3c[0] = 0;
          uVar5 = 0;
          bVar13 = 0;
        }
        else {
          uVar11 = nvswitch_minion_get_dl_status(param_1,uVar17,0x4b,0,local_3c);
          if ((int)uVar11 != 0) {
            return uVar11;
          }
          bVar13 = (byte)(local_3c[0] >> 0x1f);
          uVar5 = local_3c[0] & 0x7fffffff;
        }
        *(uint *)(puVar14 + 7) = uVar5;
        *(byte *)((long)puVar14 + 0x3c) = bVar13;
        if (uVar15 >> 1 == 0) {
          return 0;
        }
        goto LAB_0023db03;
      }
    }
LAB_0023dcc0:
    uVar11 = 0xffffffff;
  }
  else {
    uVar11 = 0xfffffff1;
  }
  return uVar11;
}


// ===== 0023ddd6 nvswitch_launch_ALI_ls10.cold =====

void nvswitch_launch_ALI_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0023dde0 nvswitch_launch_ALI_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r15 replaced with injection: x86_indirect_thunk_r15 */

undefined8 nvswitch_launch_ALI_ls10(long *param_1)

{
  code *pcVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  undefined8 uVar8;
  ulong uVar9;
  
  uVar6 = nvswitch_get_enabled_link_mask();
  if (*(long *)((long)param_1 + 0x5c) == 0) {
    if (*(char *)(*param_1 + 0xb1) == '\0') {
      return 7;
    }
    if (uVar6 != 0) {
      uVar9 = 0;
      do {
        for (; (uVar6 & 1) == 0; uVar6 = uVar6 >> 1) {
          uVar9 = uVar9 + 1;
        }
        uVar4 = nvswitch_get_num_links(param_1);
        if (uVar4 <= uVar9) {
          nvswitch_assert_log();
        }
        lVar7 = nvswitch_get_link(param_1,uVar9 & 0xff);
        if (lVar7 != 0) {
          pcVar1 = (code *)param_1[0x122];
          uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar7 + 0x38),9);
          if (pcVar1 == nvswitch_get_eng_base_ls10) {
            if ((int)param_1[0x3f1] != 7) {
                    /* WARNING: Does not return */
              pcVar1 = (code *)invalidInstructionException();
              (*pcVar1)();
            }
            lVar2 = param_1[0x3f2];
            if (*(int *)(lVar2 + 0xa70) != 9) {
              nvswitch_assert_log();
            }
            if (*(uint *)(lVar2 + 0xa74) <= uVar4) goto LAB_0023dedb;
            iVar5 = *(int *)(lVar2 + 0xa78 + (ulong)uVar4 * 4);
          }
          else {
            iVar5 = (*pcVar1)(param_1,9,0,uVar4);
          }
          if (((iVar5 != -1) &&
              (cVar3 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar7 + 0x38)), cVar3 != '\0')
              ) && (cVar3 = cciIsLinkManaged(param_1,uVar9 & 0xffffffff), cVar3 == '\0')) {
            nvswitch_launch_ALI_link_training(param_1,lVar7,0);
          }
        }
LAB_0023dedb:
        uVar6 = uVar6 >> 1;
        if (uVar6 == 0) break;
        uVar9 = uVar9 + 1;
      } while( true );
    }
    uVar8 = 0;
  }
  else {
    uVar8 = 0xfffffff3;
  }
  return uVar8;
}


// ===== 0023df9a nvswitch_get_link_ip_version_ls10.cold =====

void nvswitch_get_link_ip_version_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0023dfb0 nvswitch_get_link_ip_version_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 nvswitch_get_link_ip_version_ls10(long param_1,undefined8 param_2)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  
  lVar7 = 0;
  if (*(int *)(param_1 + 0x1f88) == 7) {
    lVar7 = *(long *)(param_1 + 0x1f90);
  }
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_2,0xb);
  uVar6 = (ulong)uVar4;
  if (*(code **)(param_1 + 0x910) == nvswitch_get_eng_base_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    lVar2 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar2 + 0xcc0) == 0xb) {
      uVar1 = *(uint *)(lVar2 + 0xcc4);
    }
    else {
      nvswitch_assert_log();
      uVar1 = *(uint *)(lVar2 + 0xcc4);
    }
    if (uVar1 <= uVar4) {
      return 0;
    }
    iVar5 = *(int *)(lVar2 + 0xcc8 + uVar6 * 4);
  }
  else {
    iVar5 = (**(code **)(param_1 + 0x910))(param_1,0xb,0,uVar6);
  }
  if (iVar5 == -1) {
    return 0;
  }
  return *(undefined4 *)(lVar7 + 0x7178 + uVar6 * 0x20);
}


// ===== 0023e084 nvswitch_get_board_id_ls10.cold =====

void nvswitch_get_board_id_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0023e090 nvswitch_get_board_id_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvswitch_get_board_id_ls10(long param_1,undefined2 *param_2)

{
  long lVar1;
  code *pcVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  
  if (param_2 == (undefined2 *)0x0) {
    iVar4 = -1;
  }
  else {
    iVar4 = nvswitch_lib_get_bios_version(param_1,0);
    if (iVar4 != 0) {
      return iVar4;
    }
    if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar1 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar1 + 0x130) == 1) {
        iVar4 = *(int *)(lVar1 + 0x134);
      }
      else {
        nvswitch_assert_log();
        iVar4 = *(int *)(lVar1 + 0x134);
      }
      if ((iVar4 == 0) || (*(int *)(lVar1 + 0x138) == -1)) {
        nvswitch_assert_log();
        uVar3 = 0xbadf;
      }
      else {
        nvswitch_reg_read_32(param_1,*(int *)(lVar1 + 0x138) + 0x4fc);
        uVar3 = extraout_var;
      }
    }
    else {
      (**(code **)(param_1 + 0x920))(param_1,1,0,0,0x4fc);
      uVar3 = extraout_var_00;
    }
    *param_2 = uVar3;
    iVar4 = 0;
  }
  return iVar4;
}


// ===== 0023e1aa nvswitch_write_fabric_state_ls10.cold =====

void nvswitch_write_fabric_state_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0023e1c0 nvswitch_write_fabric_state_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_write_fabric_state_ls10(long param_1)

{
  int iVar1;
  long lVar2;
  code *pcVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  *(int *)(param_1 + 0x1fc0) = *(int *)(param_1 + 0x1fc0) + 1;
  if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    lVar2 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar2 + 0x130) == 1) {
      iVar1 = *(int *)(lVar2 + 0x134);
    }
    else {
      nvswitch_assert_log();
      iVar1 = *(int *)(lVar2 + 0x134);
    }
    if ((iVar1 == 0) || (*(int *)(lVar2 + 0x138) == -1)) {
      nvswitch_assert_log();
      uVar4 = 0xbadfb81f;
    }
    else {
      uVar4 = nvswitch_reg_read_32(param_1,*(int *)(lVar2 + 0x138) + 0x514);
      uVar4 = uVar4 & 0xfffff83f;
    }
  }
  else {
    uVar4 = (**(code **)(param_1 + 0x920))(param_1,1,0,0,0x514);
    uVar4 = uVar4 & 0xfffff83f;
  }
  (**(code **)(param_1 + 0x928))
            (param_1,1,0,0,0x514,
             (*(uint *)(param_1 + 0x1fac) & 7) << 0xe |
             (*(uint *)(param_1 + 0x1fb4) & 0x1f) << 6 | uVar4 & 0xfe07ff |
             (*(uint *)(param_1 + 0x1fb0) & 7) << 0xb | *(int *)(param_1 + 0x1fc0) << 0x18);
  return 0;
}


// ===== 0023e316 nvswitch_ctrl_get_bios_info_ls10.cold =====

void nvswitch_ctrl_get_bios_info_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0023e330 nvswitch_ctrl_get_bios_info_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_ctrl_get_bios_info_ls10(long param_1,ulong *param_2)

{
  int iVar1;
  long lVar2;
  code *pcVar3;
  byte bVar4;
  uint uVar5;
  undefined8 uVar6;
  ulong uVar7;
  
  if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    lVar2 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar2 + 0x130) == 1) {
      iVar1 = *(int *)(lVar2 + 0x134);
    }
    else {
      nvswitch_assert_log();
      iVar1 = *(int *)(lVar2 + 0x134);
    }
    if ((iVar1 == 0) || (*(int *)(lVar2 + 0x138) == -1)) {
      nvswitch_assert_log();
      uVar7 = 0xbadfbadf;
    }
    else {
      uVar5 = nvswitch_reg_read_32(param_1,*(int *)(lVar2 + 0x138) + 0x4f8);
      uVar7 = (ulong)uVar5;
    }
  }
  else {
    uVar5 = (**(code **)(param_1 + 0x920))(param_1,1,0,0,0x4f8);
    uVar7 = (ulong)uVar5;
  }
  if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    lVar2 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar2 + 0x130) == 1) {
      iVar1 = *(int *)(lVar2 + 0x134);
    }
    else {
      nvswitch_assert_log();
      iVar1 = *(int *)(lVar2 + 0x134);
    }
    if ((iVar1 == 0) || (*(int *)(lVar2 + 0x138) == -1)) {
      nvswitch_assert_log();
      bVar4 = 0xdf;
    }
    else {
      bVar4 = nvswitch_reg_read_32(param_1,*(int *)(lVar2 + 0x138) + 0x4fc);
    }
  }
  else {
    bVar4 = (**(code **)(param_1 + 0x920))(param_1,1,0,0,0x4fc);
  }
  if ((int)(uVar7 >> 0x10) == 0x9610) {
    uVar6 = 0;
    *param_2 = uVar7 << 8 | (ulong)bVar4;
  }
  else {
    uVar6 = 0xfffffff8;
  }
  return uVar6;
}


// ===== 0023e4e0 nvswitch_is_smbpbi_supported_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint nvswitch_is_smbpbi_supported_ls10(long param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  ulong local_20 [2];
  
  uVar2 = nvswitch_is_smbpbi_supported_lr10();
  if ((char)uVar2 != '\0') {
    cVar1 = nvswitch_is_tnvl_mode_enabled(param_1);
    if (cVar1 != '\0') {
      return 0;
    }
    local_20[0] = 0;
    if (*(code **)(param_1 + 0x808) == nvswitch_ctrl_get_bios_info_ls10) {
      iVar3 = nvswitch_ctrl_get_bios_info_ls10();
    }
    else {
      iVar3 = (**(code **)(param_1 + 0x808))(param_1,local_20);
    }
    uVar2 = 0;
    if (iVar3 == 0) {
      return (uint)(0x961021ffff < local_20[0]);
    }
  }
  return uVar2;
}


// ===== 0023e580 nvswitch_is_inforom_supported_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_is_inforom_supported_ls10(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  ulong local_10;
  
  if (*(char *)(param_1 + 0x25) != '\0') {
    return 0;
  }
  if ((*(char *)(param_1 + 0x24) == '\0') && (*(char *)(param_1 + 0x26) == '\0')) {
    uVar2 = nvswitch_is_soe_supported();
    if ((char)uVar2 != '\0') {
      local_10 = 0;
      if (*(code **)(param_1 + 0x808) == nvswitch_ctrl_get_bios_info_ls10) {
        iVar1 = nvswitch_ctrl_get_bios_info_ls10();
      }
      else {
        iVar1 = (**(code **)(param_1 + 0x808))(param_1,&local_10);
      }
      uVar2 = 0;
      if (iVar1 == 0) {
        return CONCAT71(0x961016ff,0x961016ffff < local_10);
      }
    }
    return uVar2;
  }
  return 0;
}


// ===== 0023e609 nvswitch_ctrl_get_ingress_reqlinkid_ls10.cold =====

void nvswitch_ctrl_get_ingress_reqlinkid_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0023e620 nvswitch_ctrl_get_ingress_reqlinkid_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */

undefined8 nvswitch_ctrl_get_ingress_reqlinkid_ls10(long param_1,uint *param_2)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  
  pcVar2 = *(code **)(param_1 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
  if (pcVar2 == nvswitch_get_eng_base_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    lVar3 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar3 + 0x5d0) == 5) {
      uVar1 = *(uint *)(lVar3 + 0x5d4);
    }
    else {
      nvswitch_assert_log();
      uVar1 = *(uint *)(lVar3 + 0x5d4);
    }
    if (uVar1 <= uVar5) {
      return 0xffffffff;
    }
    iVar6 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar5 * 4);
  }
  else {
    iVar6 = (*pcVar2)(param_1,5,0,uVar5);
  }
  if ((iVar6 != -1) && (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 != '\0')) {
    uVar5 = *param_2;
    if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar3 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar3 + 0x5d0) == 5) {
        uVar1 = *(uint *)(lVar3 + 0x5d4);
      }
      else {
        nvswitch_assert_log();
        uVar1 = *(uint *)(lVar3 + 0x5d4);
      }
      if ((uVar5 < uVar1) && (iVar6 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar5 * 4), iVar6 != -1)) {
        uVar5 = nvswitch_reg_read_32(param_1,iVar6 + 0x54);
        param_2[1] = uVar5 & 0x7ff;
      }
      else {
        nvswitch_assert_log();
        param_2[1] = 0x2df;
      }
    }
    else {
      uVar5 = (**(code **)(param_1 + 0x920))(param_1,5,0,uVar5,0x54);
      param_2[1] = uVar5 & 0x7ff;
    }
    return 0;
  }
  return 0xffffffff;
}


// ===== 0023e7b6 nvswitch_ctrl_get_mc_rid_table_ls10.cold =====

void nvswitch_ctrl_get_mc_rid_table_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0023e7c0 nvswitch_ctrl_get_mc_rid_table_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */

undefined8 nvswitch_ctrl_get_mc_rid_table_ls10(long param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  code *pcVar3;
  long lVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  byte local_140;
  undefined1 local_13f;
  byte local_13e;
  byte local_13d;
  byte local_13c;
  ushort local_13b;
  undefined1 local_139;
  undefined1 local_138 [272];
  
  uVar2 = *param_2;
  pcVar3 = *(code **)(param_1 + 0x910);
  uVar6 = nvswitch_get_link_eng_inst(param_1,uVar2,5);
  if (pcVar3 == nvswitch_get_eng_base_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    lVar4 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar4 + 0x5d0) == 5) {
      uVar1 = *(uint *)(lVar4 + 0x5d4);
    }
    else {
      nvswitch_assert_log();
      uVar1 = *(uint *)(lVar4 + 0x5d4);
    }
    if (uVar1 <= uVar6) {
      return 0xffffffff;
    }
    iVar7 = *(int *)(lVar4 + 0x5d8 + (ulong)uVar6 * 4);
  }
  else {
    iVar7 = (*pcVar3)(param_1,5,0,uVar6);
  }
  if ((iVar7 != -1) && (cVar5 = nvswitch_is_link_valid(param_1,uVar2), cVar5 != '\0')) {
    if (*(char *)(param_2 + 2) == '\0') {
      if ((uint)param_2[1] < 0x80) goto LAB_0023e86e;
    }
    else if ((uint)param_2[1] < 0x10) {
LAB_0023e86e:
      cVar5 = nvswitch_is_tnvl_mode_locked(param_1);
      if (cVar5 != '\0') {
        return 0xfffffff1;
      }
      nvswitch_os_memset(&local_140,0,0x118);
      local_140 = (byte)param_2[1];
      local_13f = *(undefined1 *)(param_2 + 2);
      uVar8 = nvswitch_mc_read_mc_rid_entry_ls10(param_1,uVar2,&local_140);
      if ((int)uVar8 == 0) {
        nvswitch_os_memset(param_2,0,0x1ec);
        *param_2 = uVar2;
        param_2[1] = (uint)local_140;
        *(undefined1 *)(param_2 + 2) = local_13f;
        uVar8 = nvswitch_mc_unwind_directives_ls10
                          (param_1,local_138,param_2 + 3,param_2 + 0x43,param_2 + 0x55,
                           param_2 + 0x65,param_2 + 0x75);
        if ((int)uVar8 == 0) {
          param_2[0x53] = (uint)local_13e;
          param_2[0x54] = (uint)local_13d;
          param_2[0x79] = (uint)local_13c;
          *(ushort *)(param_2 + 0x7a) = local_13b << 8 | local_13b >> 8;
          *(undefined1 *)((long)param_2 + 0x1ea) = local_139;
          return uVar8;
        }
        return uVar8;
      }
      return uVar8;
    }
  }
  return 0xffffffff;
}


// ===== 0023e9f7 nvswitch_ctrl_clear_multicast_id_error_vector_ls10.cold =====

void nvswitch_ctrl_clear_multicast_id_error_vector_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0023ea10 nvswitch_ctrl_clear_multicast_id_error_vector_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */

undefined8 nvswitch_ctrl_clear_multicast_id_error_vector_ls10(long param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  code *pcVar3;
  long lVar4;
  char cVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  long lVar9;
  
  pcVar3 = *(code **)(param_1 + 0x910);
  uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
  if (pcVar3 == nvswitch_get_eng_base_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    lVar9 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar9 + 0x5d0) == 5) {
      uVar1 = *(uint *)(lVar9 + 0x5d4);
    }
    else {
      nvswitch_assert_log();
      uVar1 = *(uint *)(lVar9 + 0x5d4);
    }
    if (uVar1 <= uVar6) {
      return 0xffffffff;
    }
    iVar8 = *(int *)(lVar9 + 0x5d8 + (ulong)uVar6 * 4);
  }
  else {
    iVar8 = (*pcVar3)(param_1,5,0,(ulong)uVar6);
  }
  if ((iVar8 == -1) || (cVar5 = nvswitch_is_link_valid(param_1,*param_2), cVar5 == '\0')) {
    return 0xffffffff;
  }
  lVar9 = 1;
  do {
    pcVar3 = *(code **)(param_1 + 0x910);
    uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
    if (pcVar3 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)invalidInstructionException();
        (*pcVar3)();
      }
      lVar4 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar4 + 0x5d0) != 5) {
        nvswitch_assert_log();
      }
      if (uVar6 < *(uint *)(lVar4 + 0x5d4)) {
        iVar8 = *(int *)(lVar4 + 0x5d8 + (ulong)uVar6 * 4);
        goto LAB_0023eb12;
      }
LAB_0023eb27:
      nvswitch_assert_log();
    }
    else {
      iVar8 = (*pcVar3)(param_1,5,0,uVar6);
LAB_0023eb12:
      if ((iVar8 == -1) || (cVar5 = nvswitch_is_link_valid(param_1,*param_2), cVar5 == '\0'))
      goto LAB_0023eb27;
    }
    uVar2 = param_2[lVar9];
    pcVar3 = *(code **)(param_1 + 0x928);
    uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
    iVar8 = (int)lVar9;
    lVar9 = lVar9 + 1;
    (*pcVar3)(param_1,5,0,uVar7,iVar8 * 4 + 0x47c,uVar2);
    if (lVar9 == 5) {
      return 0;
    }
  } while( true );
}


// ===== 0023ebeb nvswitch_ctrl_set_mc_rid_table_ls10.cold =====

void nvswitch_ctrl_set_mc_rid_table_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0023ec00 nvswitch_ctrl_set_mc_rid_table_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */

undefined8 nvswitch_ctrl_set_mc_rid_table_ls10(long param_1,undefined4 *param_2)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined4 local_144;
  undefined1 local_140;
  char local_13f;
  undefined1 local_13e;
  undefined1 local_13d;
  undefined1 local_13c;
  undefined1 local_13b;
  char local_13a;
  char local_139;
  
  local_144 = 0;
  cVar4 = nvswitch_is_link_valid(param_1,*param_2);
  if (cVar4 != '\0') {
    pcVar2 = *(code **)(param_1 + 0x910);
    uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
    if (pcVar2 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar3 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar3 + 0x5d0) == 5) {
        uVar1 = *(uint *)(lVar3 + 0x5d4);
      }
      else {
        nvswitch_assert_log();
        uVar1 = *(uint *)(lVar3 + 0x5d4);
      }
      if (uVar1 <= uVar5) {
        return 0xffffffff;
      }
      iVar6 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar5 * 4);
    }
    else {
      iVar6 = (*pcVar2)(param_1,5,0,uVar5);
    }
    if ((iVar6 != -1) && (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 != '\0')) {
      if (*(char *)(param_2 + 2) == '\0') {
        if (0x7f < (uint)param_2[1]) {
          return 0xffffffff;
        }
      }
      else if (0xf < (uint)param_2[1]) {
        return 0xffffffff;
      }
      cVar4 = nvswitch_is_tnvl_mode_locked(param_1);
      if (cVar4 != '\0') {
        return 0xfffffff1;
      }
      local_139 = *(char *)((long)param_2 + 0x1ea);
      if (local_139 == '\0') {
        uVar7 = nvswitch_mc_invalidate_mc_rid_entry_ls10
                          (param_1,*param_2,param_2[1],*(undefined1 *)(param_2 + 2),1);
        return uVar7;
      }
      if (param_2[0x53] - 1 < 0x40) {
        local_13f = *(char *)(param_2 + 2);
        local_13a = *(char *)(param_2 + 0x7a);
        if ((local_13f == '\0') || (local_13a == '\0')) {
          local_13e = (undefined1)param_2[0x53];
          local_13d = (undefined1)param_2[0x54];
          local_140 = (undefined1)param_2[1];
          local_13c = (undefined1)param_2[0x79];
          local_13b = *(undefined1 *)((long)param_2 + 0x1e9);
          uVar7 = nvswitch_mc_build_mcp_list_ls10
                            (param_1,param_2 + 3,param_2 + 0x55,param_2 + 0x65,param_2 + 0x75,
                             param_2 + 0x43,&local_140,&local_144);
          if ((int)uVar7 == 0) {
            uVar7 = nvswitch_mc_program_mc_rid_entry_ls10(param_1,*param_2,&local_140,local_144);
            return uVar7;
          }
          return uVar7;
        }
      }
    }
  }
  return 0xffffffff;
}


// ===== 0023ee73 nvswitch_ctrl_get_multicast_id_error_vector_ls10.cold =====

void nvswitch_ctrl_get_multicast_id_error_vector_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0023eea0 nvswitch_ctrl_get_multicast_id_error_vector_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r15 replaced with injection: x86_indirect_thunk_r15 */
/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */

undefined8 nvswitch_ctrl_get_multicast_id_error_vector_ls10(long param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  long lVar4;
  char cVar5;
  uint uVar6;
  undefined4 uVar7;
  long lVar8;
  int iVar9;
  
  pcVar3 = *(code **)(param_1 + 0x910);
  uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
  if (pcVar3 == nvswitch_get_eng_base_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    lVar8 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar8 + 0x5d0) == 5) {
      uVar1 = *(uint *)(lVar8 + 0x5d4);
    }
    else {
      nvswitch_assert_log();
      uVar1 = *(uint *)(lVar8 + 0x5d4);
    }
    if (uVar1 <= uVar6) {
      return 0xffffffff;
    }
    iVar9 = *(int *)(lVar8 + 0x5d8 + (ulong)uVar6 * 4);
  }
  else {
    iVar9 = (*pcVar3)(param_1,5,0,(ulong)uVar6);
  }
  if ((iVar9 == -1) || (cVar5 = nvswitch_is_link_valid(param_1,*param_2), cVar5 == '\0')) {
    return 0xffffffff;
  }
  lVar8 = 1;
  do {
    pcVar3 = *(code **)(param_1 + 0x910);
    uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
    if (pcVar3 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)invalidInstructionException();
        (*pcVar3)();
      }
      lVar4 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar4 + 0x5d0) != 5) {
        nvswitch_assert_log();
      }
      if (uVar6 < *(uint *)(lVar4 + 0x5d4)) {
        iVar9 = *(int *)(lVar4 + 0x5d8 + (ulong)uVar6 * 4);
        goto LAB_0023ef9f;
      }
LAB_0023efb4:
      nvswitch_assert_log();
    }
    else {
      iVar9 = (*pcVar3)(param_1,5,0,(ulong)uVar6);
LAB_0023ef9f:
      if ((iVar9 == -1) || (cVar5 = nvswitch_is_link_valid(param_1,*param_2), cVar5 == '\0'))
      goto LAB_0023efb4;
    }
    pcVar3 = *(code **)(param_1 + 0x920);
    iVar9 = (int)lVar8 * 4 + 0x47c;
    uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
    if (pcVar3 == nvswitch_eng_rd_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)invalidInstructionException();
        (*pcVar3)();
      }
      lVar4 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar4 + 0x5d0) != 5) {
        nvswitch_assert_log();
      }
      if ((uVar6 < *(uint *)(lVar4 + 0x5d4)) &&
         (iVar2 = *(int *)(lVar4 + 0x5d8 + (ulong)uVar6 * 4), iVar2 != -1)) {
        uVar7 = nvswitch_reg_read_32(param_1,iVar2 + iVar9);
      }
      else {
        nvswitch_assert_log();
        uVar7 = 0xbadfbadf;
      }
    }
    else {
      uVar7 = (*pcVar3)(param_1,5,0,uVar6,iVar9);
    }
    param_2[lVar8] = uVar7;
    lVar8 = lVar8 + 1;
    if (lVar8 == 5) {
      return 0;
    }
  } while( true );
}


// ===== 0023f100 nvswitch_eng_rd_ls10 =====

undefined8 nvswitch_eng_rd_ls10(long param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  ulong uVar4;
  long lVar5;
  
  lVar5 = 0;
  if (*(int *)(param_1 + 0x1f88) == 7) {
    lVar5 = *(long *)(param_1 + 0x1f90);
  }
  if (0x2d < param_2) goto LAB_0023f17d;
  uVar4 = (ulong)param_2;
  lVar2 = uVar4 * 0x128 + lVar5;
  if (param_2 == *(uint *)(lVar2 + 8)) {
    if (param_3 != 0) goto LAB_0023f160;
LAB_0023f13d:
    if (*(uint *)(lVar2 + 0xc) <= param_4) goto LAB_0023f17d;
    iVar1 = *(int *)(lVar5 + ((ulong)param_4 + 4 + uVar4 * 0x4a) * 4);
  }
  else {
    nvswitch_assert_log();
    if (param_3 == 0) goto LAB_0023f13d;
LAB_0023f160:
    if (param_3 == 1) {
      iVar1 = *(int *)(lVar5 + 0x110 + uVar4 * 0x128);
    }
    else {
      if ((param_3 != 2) || (*(uint *)(lVar5 + 0x120 + uVar4 * 0x128) <= param_4))
      goto LAB_0023f17d;
      iVar1 = *(int *)(lVar5 + 4 + ((ulong)param_4 + 0x44 + uVar4 * 0x4a) * 4);
    }
  }
  if (iVar1 != -1) {
    uVar3 = nvswitch_reg_read_32(param_1,param_5 + iVar1);
    return uVar3;
  }
LAB_0023f17d:
  nvswitch_assert_log(param_1);
  return 0xbadfbadf;
}


// ===== 0023f210 nvswitch_ctrl_get_rb_stall_busy_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_ctrl_get_rb_stall_busy_ls10(long param_1,undefined4 *param_2)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  char cVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined8 uVar16;
  ulong uVar17;
  long lVar18;
  
  cVar13 = nvswitch_is_link_valid(param_1,*param_2);
  if (cVar13 == '\0') {
    uVar16 = 0xffffffff;
  }
  else {
    cVar13 = nvswitch_is_tnvl_mode_locked(param_1);
    if (cVar13 == '\0') {
      if (param_2[1] == 0) {
        (**(code **)(param_1 + 0x928))(param_1,5,0,*param_2,0x2700,3);
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar14 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar14 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2708);
        }
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar15 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar15 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2704);
        }
        uVar17 = CONCAT44(uVar15,uVar14) * 1000;
        auVar7._8_8_ = 0;
        auVar7._0_8_ = uVar17;
        lVar18 = SUB168(ZEXT816(0x895077d684835c61) * auVar7,8);
        *(ulong *)(param_2 + 2) = lVar18 + (uVar17 - lVar18 >> 1) >> 10;
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar14 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar14 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,10000);
        }
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar15 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar15 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x270c);
        }
        uVar17 = CONCAT44(uVar15,uVar14) * 1000;
        auVar8._8_8_ = 0;
        auVar8._0_8_ = uVar17;
        lVar18 = SUB168(ZEXT816(0x895077d684835c61) * auVar8,8);
        *(ulong *)(param_2 + 6) = lVar18 + (uVar17 - lVar18 >> 1) >> 10;
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar14 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar14 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2718);
        }
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar15 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar15 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2714);
        }
        uVar17 = CONCAT44(uVar15,uVar14) * 1000;
        auVar9._8_8_ = 0;
        auVar9._0_8_ = uVar17;
        lVar18 = SUB168(ZEXT816(0x895077d684835c61) * auVar9,8);
        *(ulong *)(param_2 + 4) = lVar18 + (uVar17 - lVar18 >> 1) >> 10;
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar14 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar14 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2720);
        }
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar15 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar15 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x271c);
        }
        uVar17 = CONCAT44(uVar15,uVar14) * 1000;
        auVar10._8_8_ = 0;
        auVar10._0_8_ = uVar17;
        lVar18 = SUB168(ZEXT816(0x895077d684835c61) * auVar10,8);
        *(ulong *)(param_2 + 8) = lVar18 + (uVar17 - lVar18 >> 1) >> 10;
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar14 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar14 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2728);
        }
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar15 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar15 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2724);
        }
        uVar17 = CONCAT44(uVar15,uVar14) * 1000;
        auVar11._8_8_ = 0;
        auVar11._0_8_ = uVar17;
        lVar18 = SUB168(ZEXT816(0x895077d684835c61) * auVar11,8);
        *(ulong *)(param_2 + 0xc) = lVar18 + (uVar17 - lVar18 >> 1) >> 10;
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar14 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar14 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2730);
        }
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar15 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar15 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x272c);
        }
        uVar17 = CONCAT44(uVar15,uVar14) * 1000;
        auVar12._8_8_ = 0;
        auVar12._0_8_ = uVar17;
        lVar18 = SUB168(ZEXT816(0x895077d684835c61) * auVar12,8);
        *(ulong *)(param_2 + 10) = lVar18 + (uVar17 - lVar18 >> 1) >> 10;
        (**(code **)(param_1 + 0x928))(param_1,5,0,*param_2,0x2700,1);
      }
      else {
        if (param_2[1] != 1) {
          return 0xfffffff3;
        }
        (**(code **)(param_1 + 0x928))(param_1,5,0,*param_2,0x2f00,3);
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar14 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar14 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2f08);
        }
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar15 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar15 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2f04);
        }
        uVar17 = CONCAT44(uVar15,uVar14) * 1000;
        auVar1._8_8_ = 0;
        auVar1._0_8_ = uVar17;
        lVar18 = SUB168(ZEXT816(0x895077d684835c61) * auVar1,8);
        *(ulong *)(param_2 + 2) = lVar18 + (uVar17 - lVar18 >> 1) >> 10;
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar14 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar14 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2f10);
        }
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar15 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar15 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2f0c);
        }
        uVar17 = CONCAT44(uVar15,uVar14) * 1000;
        auVar2._8_8_ = 0;
        auVar2._0_8_ = uVar17;
        lVar18 = SUB168(ZEXT816(0x895077d684835c61) * auVar2,8);
        *(ulong *)(param_2 + 6) = lVar18 + (uVar17 - lVar18 >> 1) >> 10;
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar14 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar14 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2f18);
        }
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar15 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar15 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2f14);
        }
        uVar17 = CONCAT44(uVar15,uVar14) * 1000;
        auVar3._8_8_ = 0;
        auVar3._0_8_ = uVar17;
        lVar18 = SUB168(ZEXT816(0x895077d684835c61) * auVar3,8);
        *(ulong *)(param_2 + 4) = lVar18 + (uVar17 - lVar18 >> 1) >> 10;
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar14 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar14 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2f20);
        }
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar15 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar15 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2f1c);
        }
        uVar17 = CONCAT44(uVar15,uVar14) * 1000;
        auVar4._8_8_ = 0;
        auVar4._0_8_ = uVar17;
        lVar18 = SUB168(ZEXT816(0x895077d684835c61) * auVar4,8);
        *(ulong *)(param_2 + 8) = lVar18 + (uVar17 - lVar18 >> 1) >> 10;
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar14 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar14 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2f28);
        }
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar15 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar15 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2f24);
        }
        uVar17 = CONCAT44(uVar15,uVar14) * 1000;
        auVar5._8_8_ = 0;
        auVar5._0_8_ = uVar17;
        lVar18 = SUB168(ZEXT816(0x895077d684835c61) * auVar5,8);
        *(ulong *)(param_2 + 0xc) = lVar18 + (uVar17 - lVar18 >> 1) >> 10;
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar14 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar14 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2f30);
        }
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar15 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar15 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2f2c);
        }
        uVar17 = CONCAT44(uVar15,uVar14) * 1000;
        auVar6._8_8_ = 0;
        auVar6._0_8_ = uVar17;
        lVar18 = SUB168(ZEXT816(0x895077d684835c61) * auVar6,8);
        *(ulong *)(param_2 + 10) = lVar18 + (uVar17 - lVar18 >> 1) >> 10;
        (**(code **)(param_1 + 0x928))(param_1,5,0,*param_2,0x2f00,1);
      }
      uVar16 = 0;
    }
    else {
      uVar16 = 0xfffffff1;
    }
  }
  return uVar16;
}


// ===== 0023fb34 nvswitch_ctrl_get_residency_bins_ls10.cold =====

void nvswitch_ctrl_get_residency_bins_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0023fba0 nvswitch_ctrl_get_residency_bins_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_ctrl_get_residency_bins_ls10(long param_1,uint *param_2)

{
  int iVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  code *pcVar6;
  char cVar7;
  uint uVar8;
  ulong uVar9;
  undefined8 uVar10;
  ulong uVar11;
  long lVar12;
  ulong *puVar13;
  ulong *puVar14;
  
  cVar7 = nvswitch_is_link_valid(param_1,*param_2);
  if (cVar7 == '\0') {
    uVar10 = 0xffffffff;
  }
  else {
    cVar7 = nvswitch_is_tnvl_mode_locked(param_1);
    if (cVar7 == '\0') {
      if (param_2[1] == 0) {
        (**(code **)(param_1 + 0x928))(param_1,5,0,*param_2,0x2734,3);
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar8 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar8 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2738);
        }
        uVar11 = (ulong)(uVar8 & 0xffffff) * 1000;
        auVar4._8_8_ = 0;
        auVar4._0_8_ = uVar11;
        lVar12 = SUB168(ZEXT816(0x895077d684835c61) * auVar4,8);
        param_2[2] = (uint)(lVar12 + (uVar11 - lVar12 >> 1) >> 10);
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar8 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar8 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x273c);
        }
        uVar11 = (ulong)(uVar8 & 0xffffff) * 1000;
        auVar5._8_8_ = 0;
        auVar5._0_8_ = uVar11;
        lVar12 = SUB168(ZEXT816(0x895077d684835c61) * auVar5,8);
        param_2[3] = (uint)(lVar12 + (uVar11 - lVar12 >> 1) >> 10);
        (**(code **)(param_1 + 0x928))(param_1,5,0,*param_2,0x2740,0x80000000);
        puVar14 = (ulong *)(param_2 + 4);
        do {
          uVar8 = *param_2;
          if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)invalidInstructionException();
              (*pcVar6)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if ((uVar8 < *(uint *)(lVar12 + 0x5d4)) &&
               (iVar1 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar8 * 4), iVar1 != -1)) {
              uVar8 = nvswitch_reg_read_32(param_1,iVar1 + 0x2744);
              uVar11 = (ulong)uVar8;
            }
            else {
              nvswitch_assert_log();
              uVar11 = 0xbadfbadf;
            }
          }
          else {
            uVar8 = (**(code **)(param_1 + 0x920))(param_1,5,0,(ulong)uVar8,0x2744);
            uVar11 = (ulong)uVar8;
          }
          uVar8 = *param_2;
          if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)invalidInstructionException();
              (*pcVar6)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if ((uVar8 < *(uint *)(lVar12 + 0x5d4)) &&
               (iVar1 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar8 * 4), iVar1 != -1)) {
              lVar12 = nvswitch_reg_read_32(param_1,iVar1 + 0x2744);
              uVar9 = lVar12 << 0x20;
            }
            else {
              nvswitch_assert_log();
              uVar9 = 0xbadfbadf00000000;
            }
          }
          else {
            lVar12 = (**(code **)(param_1 + 0x920))(param_1,5,0,uVar8,0x2744);
            uVar9 = lVar12 << 0x20;
          }
          *puVar14 = uVar9 | uVar11;
          uVar8 = *param_2;
          if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)invalidInstructionException();
              (*pcVar6)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if ((uVar8 < *(uint *)(lVar12 + 0x5d4)) &&
               (iVar1 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar8 * 4), iVar1 != -1)) {
              uVar8 = nvswitch_reg_read_32(param_1,iVar1 + 0x2744);
              uVar11 = (ulong)uVar8;
            }
            else {
              nvswitch_assert_log();
              uVar11 = 0xbadfbadf;
            }
          }
          else {
            uVar8 = (**(code **)(param_1 + 0x920))(param_1,5,0,(ulong)uVar8,0x2744);
            uVar11 = (ulong)uVar8;
          }
          uVar8 = *param_2;
          if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)invalidInstructionException();
              (*pcVar6)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if ((uVar8 < *(uint *)(lVar12 + 0x5d4)) &&
               (iVar1 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar8 * 4), iVar1 != -1)) {
              lVar12 = nvswitch_reg_read_32(param_1,iVar1 + 0x2744);
              uVar9 = lVar12 << 0x20;
            }
            else {
              nvswitch_assert_log();
              uVar9 = 0xbadfbadf00000000;
            }
          }
          else {
            lVar12 = (**(code **)(param_1 + 0x920))(param_1,5,0,uVar8,0x2744);
            uVar9 = lVar12 << 0x20;
          }
          puVar14[1] = uVar9 | uVar11;
          uVar8 = *param_2;
          if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)invalidInstructionException();
              (*pcVar6)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if ((uVar8 < *(uint *)(lVar12 + 0x5d4)) &&
               (iVar1 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar8 * 4), iVar1 != -1)) {
              uVar8 = nvswitch_reg_read_32(param_1,iVar1 + 0x2744);
              uVar11 = (ulong)uVar8;
            }
            else {
              nvswitch_assert_log();
              uVar11 = 0xbadfbadf;
            }
          }
          else {
            uVar8 = (**(code **)(param_1 + 0x920))(param_1,5,0,(ulong)uVar8,0x2744);
            uVar11 = (ulong)uVar8;
          }
          uVar8 = *param_2;
          if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)invalidInstructionException();
              (*pcVar6)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if ((uVar8 < *(uint *)(lVar12 + 0x5d4)) &&
               (iVar1 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar8 * 4), iVar1 != -1)) {
              lVar12 = nvswitch_reg_read_32(param_1,iVar1 + 0x2744);
              uVar9 = lVar12 << 0x20;
            }
            else {
              nvswitch_assert_log();
              uVar9 = 0xbadfbadf00000000;
            }
          }
          else {
            lVar12 = (**(code **)(param_1 + 0x920))(param_1,5,0,uVar8,0x2744);
            uVar9 = lVar12 << 0x20;
          }
          puVar13 = puVar14 + 3;
          puVar14[2] = uVar9 | uVar11;
          puVar14 = puVar13;
        } while (puVar13 != (ulong *)(param_2 + 0x304));
        (**(code **)(param_1 + 0x928))(param_1,5,0,*param_2,0x2734,1);
      }
      else {
        if (param_2[1] != 1) {
          return 0xfffffff3;
        }
        (**(code **)(param_1 + 0x928))(param_1,5,0,*param_2,0x2f34,3);
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar8 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar8 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2f38);
        }
        uVar11 = (ulong)(uVar8 & 0xffffff) * 1000;
        auVar2._8_8_ = 0;
        auVar2._0_8_ = uVar11;
        lVar12 = SUB168(ZEXT816(0x895077d684835c61) * auVar2,8);
        param_2[2] = (uint)(lVar12 + (uVar11 - lVar12 >> 1) >> 10);
        if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
          uVar8 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar8 = (**(code **)(param_1 + 0x920))(param_1,5,0,*param_2,0x2f3c);
        }
        uVar11 = (ulong)(uVar8 & 0xffffff) * 1000;
        auVar3._8_8_ = 0;
        auVar3._0_8_ = uVar11;
        lVar12 = SUB168(ZEXT816(0x895077d684835c61) * auVar3,8);
        param_2[3] = (uint)(lVar12 + (uVar11 - lVar12 >> 1) >> 10);
        (**(code **)(param_1 + 0x928))(param_1,5,0,*param_2,0x2f40,0x400);
        puVar14 = (ulong *)(param_2 + 4);
        do {
          uVar8 = *param_2;
          if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)invalidInstructionException();
              (*pcVar6)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if ((uVar8 < *(uint *)(lVar12 + 0x5d4)) &&
               (iVar1 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar8 * 4), iVar1 != -1)) {
              uVar8 = nvswitch_reg_read_32(param_1,iVar1 + 0x2f44);
              uVar11 = (ulong)uVar8;
            }
            else {
              nvswitch_assert_log();
              uVar11 = 0xbadfbadf;
            }
          }
          else {
            uVar8 = (**(code **)(param_1 + 0x920))(param_1,5,0,(ulong)uVar8,0x2f44);
            uVar11 = (ulong)uVar8;
          }
          uVar8 = *param_2;
          if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)invalidInstructionException();
              (*pcVar6)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if ((uVar8 < *(uint *)(lVar12 + 0x5d4)) &&
               (iVar1 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar8 * 4), iVar1 != -1)) {
              lVar12 = nvswitch_reg_read_32(param_1,iVar1 + 0x2f44);
              uVar9 = lVar12 << 0x20;
            }
            else {
              nvswitch_assert_log();
              uVar9 = 0xbadfbadf00000000;
            }
          }
          else {
            lVar12 = (**(code **)(param_1 + 0x920))(param_1,5,0,uVar8,0x2f44);
            uVar9 = lVar12 << 0x20;
          }
          *puVar14 = uVar9 | uVar11;
          uVar8 = *param_2;
          if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)invalidInstructionException();
              (*pcVar6)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if ((uVar8 < *(uint *)(lVar12 + 0x5d4)) &&
               (iVar1 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar8 * 4), iVar1 != -1)) {
              uVar8 = nvswitch_reg_read_32(param_1,iVar1 + 0x2f44);
              uVar11 = (ulong)uVar8;
            }
            else {
              nvswitch_assert_log();
              uVar11 = 0xbadfbadf;
            }
          }
          else {
            uVar8 = (**(code **)(param_1 + 0x920))(param_1,5,0,(ulong)uVar8,0x2f44);
            uVar11 = (ulong)uVar8;
          }
          uVar8 = *param_2;
          if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)invalidInstructionException();
              (*pcVar6)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if ((uVar8 < *(uint *)(lVar12 + 0x5d4)) &&
               (iVar1 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar8 * 4), iVar1 != -1)) {
              lVar12 = nvswitch_reg_read_32(param_1,iVar1 + 0x2f44);
              uVar9 = lVar12 << 0x20;
            }
            else {
              nvswitch_assert_log();
              uVar9 = 0xbadfbadf00000000;
            }
          }
          else {
            lVar12 = (**(code **)(param_1 + 0x920))(param_1,5,0,uVar8,0x2f44);
            uVar9 = lVar12 << 0x20;
          }
          puVar14[1] = uVar9 | uVar11;
          uVar8 = *param_2;
          if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)invalidInstructionException();
              (*pcVar6)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if ((uVar8 < *(uint *)(lVar12 + 0x5d4)) &&
               (iVar1 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar8 * 4), iVar1 != -1)) {
              uVar8 = nvswitch_reg_read_32(param_1,iVar1 + 0x2f44);
              uVar11 = (ulong)uVar8;
            }
            else {
              nvswitch_assert_log();
              uVar11 = 0xbadfbadf;
            }
          }
          else {
            uVar8 = (**(code **)(param_1 + 0x920))(param_1,5,0,(ulong)uVar8,0x2f44);
            uVar11 = (ulong)uVar8;
          }
          uVar8 = *param_2;
          if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)invalidInstructionException();
              (*pcVar6)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if ((uVar8 < *(uint *)(lVar12 + 0x5d4)) &&
               (iVar1 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar8 * 4), iVar1 != -1)) {
              lVar12 = nvswitch_reg_read_32(param_1,iVar1 + 0x2f44);
              uVar9 = lVar12 << 0x20;
            }
            else {
              nvswitch_assert_log();
              uVar9 = 0xbadfbadf00000000;
            }
          }
          else {
            lVar12 = (**(code **)(param_1 + 0x920))(param_1,5,0,uVar8,0x2f44);
            uVar9 = lVar12 << 0x20;
          }
          puVar13 = puVar14 + 3;
          puVar14[2] = uVar11 | uVar9;
          puVar14 = puVar13;
        } while (puVar13 != (ulong *)(param_2 + 0x304));
        (**(code **)(param_1 + 0x928))(param_1,5,0,*param_2,0x2f34,1);
      }
      uVar10 = 0;
    }
    else {
      uVar10 = 0xfffffff1;
    }
  }
  return uVar10;
}


// ===== 0024078f nvswitch_init_nport_ls10.cold =====

void nvswitch_init_nport_ls10_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  undefined8 unaff_R13;
  
  *(undefined8 *)(unaff_RBP + -0x10) = unaff_R13;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002407b0 nvswitch_init_nport_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_init_nport_ls10(long param_1)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  uint uVar5;
  undefined8 uVar6;
  
  if (*(code **)(param_1 + 0x918) == nvswitch_get_eng_count_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)invalidInstructionException();
      (*pcVar4)();
    }
    lVar1 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar1 + 0x5d0) != 5) {
      nvswitch_assert_log();
    }
    uVar3 = *(uint *)(lVar1 + 0x5d4);
  }
  else {
    uVar3 = (**(code **)(param_1 + 0x918))(param_1,5,0);
  }
  if (uVar3 == 0) {
    return 0;
  }
  uVar5 = 0;
  do {
    if (*(code **)(param_1 + 0x910) == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)invalidInstructionException();
        (*pcVar4)();
      }
      lVar1 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar1 + 0x5d0) != 5) {
        nvswitch_assert_log();
      }
      if (uVar5 < *(uint *)(lVar1 + 0x5d4)) {
        iVar2 = *(int *)(lVar1 + 0x5d8 + (ulong)uVar5 * 4);
        goto joined_r0x0024085c;
      }
    }
    else {
      iVar2 = (**(code **)(param_1 + 0x910))(param_1,5,0,uVar5);
joined_r0x0024085c:
      if (iVar2 != -1) {
        if (uVar3 == uVar5) {
          return 0;
        }
        pcVar4 = *(code **)(param_1 + 0x920);
        if ((*(byte *)(param_1 + 0xa2) & 0x10) == 0) {
          if (pcVar4 == nvswitch_eng_rd_ls10) {
            uVar3 = nvswitch_eng_rd_ls10();
          }
          else {
            uVar3 = (*pcVar4)(param_1,5,0,uVar5,0x6040);
          }
          (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x6040,uVar3 | 0x200);
          uVar3 = *(uint *)(param_1 + 0xa0) & 0xfffff;
          if (uVar3 == 0) goto LAB_002408ff;
          pcVar4 = *(code **)(param_1 + 0x928);
          uVar6 = 0x6044;
        }
        else {
          if (pcVar4 == nvswitch_eng_rd_ls10) {
            uVar3 = nvswitch_eng_rd_ls10();
          }
          else {
            uVar3 = (*pcVar4)(param_1,5,0,uVar5,0x6040);
          }
          pcVar4 = *(code **)(param_1 + 0x928);
          uVar3 = uVar3 & 0xfffffdff;
          uVar6 = 0x6040;
        }
        (*pcVar4)(param_1,5,1,0,uVar6,uVar3);
LAB_002408ff:
        (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x5c,0x40000);
        return 0;
      }
    }
    uVar5 = uVar5 + 1;
    if (uVar3 == uVar5) {
      return 0;
    }
  } while( true );
}


// ===== 002409fe nvswitch_ctrl_get_nvlink_lp_counters_ls10.cold =====

void nvswitch_ctrl_get_nvlink_lp_counters_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00240a10 nvswitch_ctrl_get_nvlink_lp_counters_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */
/* WARNING: Type propagation algorithm not settling */

undefined8 nvswitch_ctrl_get_nvlink_lp_counters_ls10(long param_1,undefined4 *param_2)

{
  code *pcVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  uint uVar7;
  uint local_2c;
  
  cVar3 = nvswitch_is_tnvl_mode_locked();
  if (cVar3 != '\0') {
    return 0xfffffff1;
  }
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*param_2,0xb);
  if (pcVar1 == nvswitch_get_eng_base_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    lVar2 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar2 + 0xcc0) == 0xb) {
      uVar7 = *(uint *)(lVar2 + 0xcc4);
    }
    else {
      nvswitch_assert_log();
      uVar7 = *(uint *)(lVar2 + 0xcc4);
    }
    if (uVar7 <= uVar4) {
      return 0xffffffff;
    }
    iVar5 = *(int *)(lVar2 + 0xcc8 + (ulong)uVar4 * 4);
  }
  else {
    iVar5 = (*pcVar1)(param_1,0xb,0,(ulong)uVar4);
  }
  if ((iVar5 != -1) && (cVar3 = nvswitch_is_link_valid(param_1,*param_2), cVar3 != '\0')) {
    uVar4 = param_2[1];
    uVar7 = uVar4 & 1;
    if (uVar7 != 0) {
      uVar6 = nvswitch_minion_get_dl_status(param_1,*param_2,0x21,0,&local_2c);
      if ((int)uVar6 != 0) {
        return uVar6;
      }
      param_2[2] = local_2c & 0x7fffffff;
    }
    if ((uVar4 & 4) != 0) {
      uVar6 = nvswitch_minion_get_dl_status(param_1,*param_2,0x22,0,&local_2c);
      if ((int)uVar6 != 0) {
        return uVar6;
      }
      uVar7 = uVar7 | 4;
      param_2[4] = local_2c & 0x7fffffff;
    }
    if ((uVar4 & 8) != 0) {
      uVar6 = nvswitch_minion_get_dl_status(param_1,*param_2,0x26,0,&local_2c);
      if ((int)uVar6 != 0) {
        return uVar6;
      }
      uVar7 = uVar7 | 8;
      param_2[5] = local_2c & 0x7fffffff;
    }
    if ((uVar4 & 0x10) != 0) {
      uVar6 = nvswitch_minion_get_dl_status(param_1,*param_2,0x25,0,&local_2c);
      if ((int)uVar6 != 0) {
        return uVar6;
      }
      uVar7 = uVar7 | 0x10;
      param_2[6] = local_2c & 0x7fffffff;
    }
    if ((uVar4 & 0x20) != 0) {
      uVar6 = nvswitch_minion_get_dl_status(param_1,*param_2,0x2a,0,&local_2c);
      if ((int)uVar6 != 0) {
        return uVar6;
      }
      uVar7 = uVar7 | 0x20;
      param_2[7] = local_2c & 0x7fffffff;
    }
    param_2[1] = uVar7;
    return 0;
  }
  return 0xffffffff;
}


// ===== 00240c8a nvswitch_ctrl_get_nvlink_status_ls10.cold =====

void nvswitch_ctrl_get_nvlink_status_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00240ca0 nvswitch_ctrl_get_nvlink_status_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

int nvswitch_ctrl_get_nvlink_status_ls10(long param_1,ulong *param_2)

{
  code *pcVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  long lVar7;
  ulong uVar8;
  uint uVar9;
  
  iVar4 = nvswitch_ctrl_get_nvlink_status_lr10();
  if ((iVar4 != 0) || (uVar8 = *param_2, uVar8 == 0)) {
    return iVar4;
  }
  param_2 = param_2 + 2;
  uVar9 = 0;
  do {
    if ((uVar8 & 1) != 0) {
      uVar5 = nvswitch_get_num_links(param_1);
      if (uVar5 <= uVar9) {
        nvswitch_assert_log();
      }
      lVar7 = nvswitch_get_link(param_1,uVar9 & 0xff);
      if (lVar7 != 0) {
        uVar5 = 0xffffffff;
        if ((int)*param_2 == 3) {
          pcVar1 = *(code **)(param_1 + 0x910);
          uVar5 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar7 + 0x38),9);
          if (pcVar1 == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar1 = (code *)invalidInstructionException();
              (*pcVar1)();
            }
            lVar2 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar2 + 0xa70) != 9) {
              nvswitch_assert_log();
            }
            if (uVar5 < *(uint *)(lVar2 + 0xa74)) {
              iVar4 = *(int *)(lVar2 + 0xa78 + (ulong)uVar5 * 4);
              goto LAB_00240de8;
            }
LAB_00240e05:
            nvswitch_assert_log();
          }
          else {
            iVar4 = (*pcVar1)(param_1,9,0,uVar5);
LAB_00240de8:
            if ((iVar4 == -1) ||
               (cVar3 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar7 + 0x38)), cVar3 == '\0'
               )) goto LAB_00240e05;
          }
          pcVar1 = *(code **)(param_1 + 0x920);
          uVar6 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar7 + 0x38),9);
          if (pcVar1 == nvswitch_eng_rd_ls10) {
            uVar5 = nvswitch_eng_rd_ls10();
          }
          else {
            uVar5 = (*pcVar1)(param_1,9,0,uVar6,0x400);
          }
          uVar5 = uVar5 >> 2 & 1;
        }
        *(uint *)((long)param_2 + 4) = uVar5;
      }
      if (uVar8 >> 1 == 0) {
        return 0;
      }
    }
    uVar8 = uVar8 >> 1;
    uVar9 = uVar9 + 1;
    param_2 = param_2 + 0x17;
  } while( true );
}


// ===== 00240eb7 nvswitch_ctrl_get_fatal_error_scope_ls10.cold =====

void nvswitch_ctrl_get_fatal_error_scope_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00240ee0 nvswitch_ctrl_get_fatal_error_scope_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r15 replaced with injection: x86_indirect_thunk_r15 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_ctrl_get_fatal_error_scope_ls10(long param_1,byte *param_2)

{
  long lVar1;
  code *pcVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  ulong uVar7;
  
  if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    lVar1 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar1 + 0x130) == 1) {
      iVar6 = *(int *)(lVar1 + 0x134);
    }
    else {
      nvswitch_assert_log();
      iVar6 = *(int *)(lVar1 + 0x134);
    }
    if ((iVar6 == 0) || (*(int *)(lVar1 + 0x138) == -1)) {
      nvswitch_assert_log();
      bVar3 = 0;
    }
    else {
      uVar5 = nvswitch_reg_read_32(param_1,*(int *)(lVar1 + 0x138) + 0x514);
      bVar3 = (byte)(uVar5 >> 5) & 1;
    }
  }
  else {
    uVar5 = (**(code **)(param_1 + 0x920))(param_1,1,0,0,0x514);
    bVar3 = (byte)(uVar5 >> 5) & 1;
  }
  *param_2 = bVar3;
  uVar7 = 0;
  do {
    cVar4 = nvswitch_is_link_valid(param_1,uVar7 & 0xffffffff);
    bVar3 = 0;
    if (cVar4 == '\0') {
LAB_00240f80:
      param_2[uVar7 + 1] = bVar3;
    }
    else {
      pcVar2 = *(code **)(param_1 + 0x910);
      uVar5 = nvswitch_get_link_eng_inst(param_1,uVar7 & 0xffffffff,5);
      if (pcVar2 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        lVar1 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar1 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar5 < *(uint *)(lVar1 + 0x5d4)) {
          iVar6 = *(int *)(lVar1 + 0x5d8 + (ulong)uVar5 * 4);
          goto LAB_00241007;
        }
LAB_0024101b:
        nvswitch_assert_log();
      }
      else {
        iVar6 = (*pcVar2)(param_1,5,0,uVar5);
LAB_00241007:
        if ((iVar6 == -1) ||
           (cVar4 = nvswitch_is_link_valid(param_1,uVar7 & 0xffffffff), cVar4 == '\0'))
        goto LAB_0024101b;
      }
      pcVar2 = *(code **)(param_1 + 0x920);
      uVar5 = nvswitch_get_link_eng_inst(param_1,uVar7 & 0xffffffff,5);
      if (pcVar2 != nvswitch_eng_rd_ls10) {
        bVar3 = (*pcVar2)(param_1,5,0,(ulong)uVar5,0xfc0);
        bVar3 = bVar3 & 1;
        goto LAB_00240f80;
      }
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar1 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar1 + 0x5d0) != 5) {
        nvswitch_assert_log();
      }
      if ((*(uint *)(lVar1 + 0x5d4) <= uVar5) ||
         (iVar6 = *(int *)(lVar1 + 0x5d8 + (ulong)uVar5 * 4), iVar6 == -1)) {
        nvswitch_assert_log();
        bVar3 = 1;
        goto LAB_00240f80;
      }
      bVar3 = nvswitch_reg_read_32(param_1,iVar6 + 0xfc0);
      param_2[uVar7 + 1] = bVar3 & 1;
    }
    uVar7 = uVar7 + 1;
    if (uVar7 == 0x40) {
      return 0;
    }
  } while( true );
}


// ===== 0024113b nvswitch_load_uuid_ls10.cold =====

void nvswitch_load_uuid_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00241160 nvswitch_load_uuid_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_load_uuid_ls10(long param_1)

{
  int iVar1;
  long lVar2;
  code *pcVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    lVar2 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar2 + 0x130) == 1) {
      iVar1 = *(int *)(lVar2 + 0x134);
    }
    else {
      nvswitch_assert_log();
      iVar1 = *(int *)(lVar2 + 0x134);
    }
    if ((iVar1 == 0) || (*(int *)(lVar2 + 0x138) == -1)) {
      nvswitch_assert_log();
      local_28 = 0xbadfbadf;
    }
    else {
      local_28 = nvswitch_reg_read_32(param_1,*(int *)(lVar2 + 0x138) + 0xc30);
    }
  }
  else {
    local_28 = (**(code **)(param_1 + 0x920))(param_1,1,0,0,0xc30);
  }
  if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    lVar2 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar2 + 0x130) == 1) {
      iVar1 = *(int *)(lVar2 + 0x134);
    }
    else {
      nvswitch_assert_log();
      iVar1 = *(int *)(lVar2 + 0x134);
    }
    if ((iVar1 == 0) || (*(int *)(lVar2 + 0x138) == -1)) {
      nvswitch_assert_log();
      local_24 = 0xbadfbadf;
    }
    else {
      local_24 = nvswitch_reg_read_32(param_1,*(int *)(lVar2 + 0x138) + 0xc34);
    }
  }
  else {
    local_24 = (**(code **)(param_1 + 0x920))(param_1,1,0,0,0xc34);
  }
  if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    lVar2 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar2 + 0x130) == 1) {
      iVar1 = *(int *)(lVar2 + 0x134);
    }
    else {
      nvswitch_assert_log();
      iVar1 = *(int *)(lVar2 + 0x134);
    }
    if ((iVar1 == 0) || (*(int *)(lVar2 + 0x138) == -1)) {
      nvswitch_assert_log();
      local_20 = 0xbadfbadf;
    }
    else {
      local_20 = nvswitch_reg_read_32(param_1,*(int *)(lVar2 + 0x138) + 0xc38);
    }
  }
  else {
    local_20 = (**(code **)(param_1 + 0x920))(param_1,1,0,0,0xc38);
  }
  if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    lVar2 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar2 + 0x130) == 1) {
      iVar1 = *(int *)(lVar2 + 0x134);
    }
    else {
      nvswitch_assert_log();
      iVar1 = *(int *)(lVar2 + 0x134);
    }
    if ((iVar1 == 0) || (*(int *)(lVar2 + 0x138) == -1)) {
      nvswitch_assert_log();
      local_1c = 0xbadfbadf;
    }
    else {
      local_1c = nvswitch_reg_read_32(param_1,*(int *)(lVar2 + 0x138) + 0xc3c);
    }
  }
  else {
    local_1c = (**(code **)(param_1 + 0x920))(param_1,1,0,0,0xc3c);
  }
  nvswitch_os_memcpy(param_1 + 0x1f98,&local_28,0x10);
  return;
}


// ===== 0024144f nvswitch_set_fatal_error_ls10.cold =====

void nvswitch_set_fatal_error_ls10_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  undefined8 unaff_R14;
  
  *(undefined8 *)(unaff_RBP + -8) = unaff_R14;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00241470 nvswitch_set_fatal_error_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */

void nvswitch_set_fatal_error_ls10(long param_1,char param_2,uint param_3)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  char cVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  
  uVar5 = nvswitch_get_num_links();
  if (uVar5 <= param_3) {
    nvswitch_assert_log();
  }
  *(undefined1 *)(param_1 + 0xf68 + (ulong)param_3 * 0x40) = 1;
  if (param_2 != '\0') {
    if (*(code **)(param_1 + 0x920) == nvswitch_eng_rd_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)invalidInstructionException();
        (*pcVar3)();
      }
      lVar2 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar2 + 0x130) == 1) {
        iVar8 = *(int *)(lVar2 + 0x134);
      }
      else {
        nvswitch_assert_log();
        iVar8 = *(int *)(lVar2 + 0x134);
      }
      if ((iVar8 == 0) || (*(int *)(lVar2 + 0x138) == -1)) {
        nvswitch_assert_log();
        uVar5 = 0xbadfbaff;
      }
      else {
        uVar5 = nvswitch_reg_read_32(param_1,*(int *)(lVar2 + 0x138) + 0x514);
        uVar5 = uVar5 | 0x20;
      }
    }
    else {
      uVar5 = (**(code **)(param_1 + 0x920))(param_1,1,0,0,0x514);
      uVar5 = uVar5 | 0x20;
    }
    (**(code **)(param_1 + 0x928))(param_1,1,0,0,0x514,uVar5);
    return;
  }
  pcVar3 = *(code **)(param_1 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(param_1,param_3,5);
  if (pcVar3 == nvswitch_get_eng_base_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) goto LAB_0024145c;
    lVar2 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar2 + 0x5d0) == 5) {
      uVar7 = *(uint *)(lVar2 + 0x5d4);
    }
    else {
      nvswitch_assert_log();
      uVar7 = *(uint *)(lVar2 + 0x5d4);
    }
    if (uVar5 < uVar7) {
      iVar8 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar5 * 4);
      goto LAB_002416e2;
    }
LAB_002415bf:
    nvswitch_assert_log();
  }
  else {
    iVar8 = (*pcVar3)(param_1,5,0,uVar5);
LAB_002416e2:
    if ((iVar8 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,param_3), cVar4 == '\0'))
    goto LAB_002415bf;
  }
  pcVar3 = *(code **)(param_1 + 0x920);
  uVar6 = nvswitch_get_link_eng_inst(param_1,param_3,5);
  if (pcVar3 == nvswitch_eng_rd_ls10) {
    uVar5 = nvswitch_eng_rd_ls10();
  }
  else {
    uVar5 = (*pcVar3)(param_1,5,0,uVar6,0xfc0);
  }
  pcVar3 = *(code **)(param_1 + 0x910);
  uVar7 = nvswitch_get_link_eng_inst(param_1,param_3,5);
  if (pcVar3 == nvswitch_get_eng_base_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
LAB_0024145c:
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    lVar2 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar2 + 0x5d0) == 5) {
      uVar1 = *(uint *)(lVar2 + 0x5d4);
    }
    else {
      nvswitch_assert_log();
      uVar1 = *(uint *)(lVar2 + 0x5d4);
    }
    if (uVar7 < uVar1) {
      iVar8 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar7 * 4);
      goto LAB_0024165b;
    }
  }
  else {
    iVar8 = (*pcVar3)(param_1,5,0,uVar7);
LAB_0024165b:
    if ((iVar8 != -1) && (cVar4 = nvswitch_is_link_valid(param_1,param_3), cVar4 != '\0'))
    goto LAB_00241674;
  }
  nvswitch_assert_log();
LAB_00241674:
  pcVar3 = *(code **)(param_1 + 0x928);
  uVar6 = nvswitch_get_link_eng_inst(param_1,param_3,5);
  (*pcVar3)(param_1,5,0,uVar6,0xfc0,uVar5 | 1);
  return;
}


// ===== 002417b6 nvswitch_ctrl_set_remap_policy_ls10.cold =====

void nvswitch_ctrl_set_remap_policy_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00241850 nvswitch_ctrl_set_remap_policy_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */

int nvswitch_ctrl_set_remap_policy_ls10(long param_1,undefined4 *param_2)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  code *pcVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  undefined8 uVar9;
  char cVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  undefined4 uVar14;
  uint uVar15;
  undefined4 *puVar16;
  uint uVar17;
  uint local_50;
  uint local_3c [3];
  
  local_3c[0] = 0xffffffff;
  cVar10 = nvswitch_is_tnvl_mode_locked();
  if (cVar10 != '\0') {
    return -0xf;
  }
  pcVar5 = *(code **)(param_1 + 0x910);
  uVar11 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
  if (pcVar5 == nvswitch_get_eng_base_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)invalidInstructionException();
      (*pcVar5)();
    }
    lVar6 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar6 + 0x5d0) == 5) {
      uVar15 = *(uint *)(lVar6 + 0x5d4);
    }
    else {
      nvswitch_assert_log();
      uVar15 = *(uint *)(lVar6 + 0x5d4);
    }
    if (uVar15 <= uVar11) {
      return -1;
    }
    iVar12 = *(int *)(lVar6 + 0x5d8 + (ulong)uVar11 * 4);
  }
  else {
    iVar12 = (*pcVar5)(param_1,5,0,(ulong)uVar11);
  }
  if ((iVar12 == -1) || (cVar10 = nvswitch_is_link_valid(param_1,*param_2), cVar10 == '\0')) {
    return -1;
  }
  iVar12 = nvswitch_get_remap_table_selector(param_1,param_2[1],local_3c);
  if (iVar12 != 0) {
    return iVar12;
  }
  uVar11 = nvswitch_get_ingress_ram_size(param_1,local_3c[0]);
  if (uVar11 <= (uint)param_2[2]) {
    return -1;
  }
  uVar15 = param_2[3];
  if (0x40 < uVar15) {
    return -1;
  }
  if (uVar11 < param_2[2] + uVar15) {
    return -1;
  }
  if (uVar15 != 0) {
    puVar16 = param_2;
    do {
      if (param_2[1] == 3) {
        if (0x7f < (uint)puVar16[5]) {
          return -1;
        }
      }
      else if (0x7ff < (uint)puVar16[5]) {
        return -1;
      }
      if (3 < (uint)puVar16[6]) {
        return -1;
      }
      if ((puVar16[7] & 0x3fffffe8) != 0) {
        return -1;
      }
      if (((puVar16[7] & 0x40000000) != 0) && (param_2[1] != 3)) {
        return -1;
      }
      if ((*(ulong *)(puVar16 + 8) & 0xfff0007fffffffff) != 0) {
        return -1;
      }
      if (0xffff < (uint)puVar16[10]) {
        return -1;
      }
      if (0xffff < (uint)puVar16[0xb]) {
        return -1;
      }
      if (0xffff < (uint)puVar16[0xc]) {
        return -1;
      }
      uVar7 = *(ulong *)(puVar16 + 0x10);
      if ((uVar7 & 0xffffff80001fffff) != 0) {
        return -1;
      }
      uVar8 = *(ulong *)(puVar16 + 0x12);
      if (uVar8 < uVar7) {
        return -1;
      }
      if (((uVar8 - uVar7 | uVar8) & 0xffffff80001fffff) != 0) {
        return -1;
      }
      if (*(long *)(puVar16 + 0xe) != 0) {
        return -1;
      }
      puVar16 = puVar16 + 0x10;
    } while (param_2 + (ulong)uVar15 * 0x10 != puVar16);
  }
  cVar10 = nvswitch_is_tnvl_mode_locked(param_1);
  if (cVar10 != '\0') {
    return -0xf;
  }
  uVar4 = *param_2;
  if (param_2[1] != 3) {
    iVar12 = nvswitch_soe_issue_ingress_stop(param_1,uVar4,1);
    uVar11 = local_3c[0];
    if (iVar12 != 0) {
      return iVar12;
    }
    uVar15 = param_2[3];
    uVar4 = *param_2;
    uVar17 = param_2[2];
    cVar10 = nvswitch_is_tnvl_mode_locked(param_1);
    if (cVar10 != '\0') goto LAB_00242828;
    pcVar5 = *(code **)(param_1 + 0x910);
    uVar13 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
    if (pcVar5 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)invalidInstructionException();
        (*pcVar5)();
      }
      lVar6 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar6 + 0x5d0) != 5) {
        nvswitch_assert_log();
      }
      if (uVar13 < *(uint *)(lVar6 + 0x5d4)) {
        iVar12 = *(int *)(lVar6 + 0x5d8 + (ulong)uVar13 * 4);
        goto LAB_00241b12;
      }
LAB_00241b26:
      nvswitch_assert_log();
    }
    else {
      iVar12 = (*pcVar5)(param_1,5,0,(ulong)uVar13);
LAB_00241b12:
      if ((iVar12 == -1) || (cVar10 = nvswitch_is_link_valid(param_1,uVar4), cVar10 == '\0'))
      goto LAB_00241b26;
    }
    pcVar5 = *(code **)(param_1 + 0x928);
    uVar14 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
    (*pcVar5)(param_1,5,0,uVar14,0x1080,(uVar11 & 7) << 0x10 | uVar17 & 0x3fff | 0x80000000);
    if (uVar15 != 0) {
      puVar16 = param_2;
      do {
        uVar7 = *(ulong *)(puVar16 + 0x12);
        pcVar5 = *(code **)(param_1 + 0x910);
        uVar9 = *(undefined8 *)(puVar16 + 8);
        uVar8 = *(ulong *)(puVar16 + 0x10);
        uVar17 = puVar16[7] & 0x80000017;
        uVar11 = puVar16[7] & 0x17 | 0x20;
        if (-1 < (int)uVar17) {
          uVar11 = uVar17;
        }
        uVar17 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
        if (pcVar5 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)invalidInstructionException();
            (*pcVar5)();
          }
          lVar6 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar6 + 0x5d0) != 5) {
            nvswitch_assert_log();
          }
          if (uVar17 < *(uint *)(lVar6 + 0x5d4)) {
            iVar12 = *(int *)(lVar6 + 0x5d8 + (ulong)uVar17 * 4);
            goto LAB_00241be1;
          }
LAB_00241bf5:
          nvswitch_assert_log();
        }
        else {
          iVar12 = (*pcVar5)(param_1,5,0,uVar17);
LAB_00241be1:
          if ((iVar12 == -1) || (cVar10 = nvswitch_is_link_valid(param_1,uVar4), cVar10 == '\0'))
          goto LAB_00241bf5;
        }
        iVar12 = puVar16[0xb];
        uVar2 = *(ushort *)(puVar16 + 10);
        pcVar5 = *(code **)(param_1 + 0x928);
        uVar14 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
        (*pcVar5)(param_1,5,0,uVar14,0x1094,(uint)uVar2 | iVar12 << 0x10);
        pcVar5 = *(code **)(param_1 + 0x910);
        uVar17 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
        if (pcVar5 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)invalidInstructionException();
            (*pcVar5)();
          }
          lVar6 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar6 + 0x5d0) != 5) {
            nvswitch_assert_log();
          }
          if (uVar17 < *(uint *)(lVar6 + 0x5d4)) {
            iVar12 = *(int *)(lVar6 + 0x5d8 + (ulong)uVar17 * 4);
            goto LAB_00241cb4;
          }
LAB_00241cc8:
          nvswitch_assert_log();
        }
        else {
          iVar12 = (*pcVar5)(param_1,5,0,uVar17);
LAB_00241cb4:
          if ((iVar12 == -1) || (cVar10 = nvswitch_is_link_valid(param_1,uVar4), cVar10 == '\0'))
          goto LAB_00241cc8;
        }
        uVar3 = *(undefined2 *)(puVar16 + 0xc);
        pcVar5 = *(code **)(param_1 + 0x928);
        uVar14 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
        (*pcVar5)(param_1,5,0,uVar14,0x1098,uVar3);
        pcVar5 = *(code **)(param_1 + 0x910);
        uVar17 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
        if (pcVar5 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)invalidInstructionException();
            (*pcVar5)();
          }
          lVar6 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar6 + 0x5d0) != 5) {
            nvswitch_assert_log();
          }
          if (uVar17 < *(uint *)(lVar6 + 0x5d4)) {
            iVar12 = *(int *)(lVar6 + 0x5d8 + (ulong)uVar17 * 4);
            goto LAB_00241d7d;
          }
LAB_00241d91:
          nvswitch_assert_log();
        }
        else {
          iVar12 = (*pcVar5)(param_1,5,0,uVar17);
LAB_00241d7d:
          if ((iVar12 == -1) || (cVar10 = nvswitch_is_link_valid(param_1,uVar4), cVar10 == '\0'))
          goto LAB_00241d91;
        }
        pcVar5 = *(code **)(param_1 + 0x928);
        uVar17 = (uint)(uVar7 >> 0x15);
        local_50 = uVar17 & 0x3ffff;
        uVar14 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
        (*pcVar5)(param_1,5,0,uVar14,0x109c,(uint)(uVar8 >> 0x15) & 0xffff | uVar17 << 0x10);
        pcVar5 = *(code **)(param_1 + 0x910);
        uVar17 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
        if (pcVar5 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)invalidInstructionException();
            (*pcVar5)();
          }
          lVar6 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar6 + 0x5d0) != 5) {
            nvswitch_assert_log();
          }
          if (uVar17 < *(uint *)(lVar6 + 0x5d4)) {
            iVar12 = *(int *)(lVar6 + 0x5d8 + (ulong)uVar17 * 4);
            goto LAB_00241e62;
          }
LAB_00241e76:
          nvswitch_assert_log();
        }
        else {
          iVar12 = (*pcVar5)(param_1,5,0,uVar17);
LAB_00241e62:
          if ((iVar12 == -1) || (cVar10 = nvswitch_is_link_valid(param_1,uVar4), cVar10 == '\0'))
          goto LAB_00241e76;
        }
        uVar17 = puVar16[5];
        pcVar5 = *(code **)(param_1 + 0x928);
        uVar14 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
        (*pcVar5)(param_1,5,0,uVar14,0x10a0,uVar17 & 0x7ff | uVar11 << 0xf);
        pcVar5 = *(code **)(param_1 + 0x910);
        uVar11 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
        if (pcVar5 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)invalidInstructionException();
            (*pcVar5)();
          }
          lVar6 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar6 + 0x5d0) != 5) {
            nvswitch_assert_log();
          }
          if (uVar11 < *(uint *)(lVar6 + 0x5d4)) {
            iVar12 = *(int *)(lVar6 + 0x5d8 + (ulong)uVar11 * 4);
            goto LAB_00241f3a;
          }
LAB_00241f4e:
          nvswitch_assert_log();
        }
        else {
          iVar12 = (*pcVar5)(param_1,5,0,uVar11);
LAB_00241f3a:
          if ((iVar12 == -1) || (cVar10 = nvswitch_is_link_valid(param_1,uVar4), cVar10 == '\0'))
          goto LAB_00241f4e;
        }
        pcVar5 = *(code **)(param_1 + 0x928);
        uVar14 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
        (*pcVar5)(param_1,5,0,uVar14,0x10a4,(uint)(uVar8 >> 0x25) & 3 | (local_50 >> 0x10) << 4);
        pcVar5 = *(code **)(param_1 + 0x910);
        uVar11 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
        if (pcVar5 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)invalidInstructionException();
            (*pcVar5)();
          }
          lVar6 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar6 + 0x5d0) != 5) {
            nvswitch_assert_log();
          }
          if (uVar11 < *(uint *)(lVar6 + 0x5d4)) {
            iVar12 = *(int *)(lVar6 + 0x5d8 + (ulong)uVar11 * 4);
            goto LAB_00242009;
          }
LAB_0024201d:
          nvswitch_assert_log();
        }
        else {
          iVar12 = (*pcVar5)(param_1,5,0);
LAB_00242009:
          if ((iVar12 == -1) || (cVar10 = nvswitch_is_link_valid(param_1,uVar4), cVar10 == '\0'))
          goto LAB_0024201d;
        }
        uVar11 = puVar16[6];
        bVar1 = *(byte *)(puVar16 + 4);
        pcVar5 = *(code **)(param_1 + 0x928);
        puVar16 = puVar16 + 0x10;
        uVar14 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
        (*pcVar5)(param_1,5,0,uVar14,0x1090,
                  (uVar11 & 3) << 0xf | (uint)bVar1 << 0x1f | (uint)((ulong)uVar9 >> 0x27) & 0x1fff)
        ;
      } while (param_2 + (ulong)uVar15 * 0x10 != puVar16);
    }
LAB_00242828:
    iVar12 = nvswitch_soe_issue_ingress_stop(param_1,*param_2,0);
    return iVar12;
  }
  uVar11 = param_2[3];
  uVar15 = param_2[2];
  cVar10 = nvswitch_is_tnvl_mode_locked(param_1);
  if (cVar10 != '\0') {
    return 0;
  }
  pcVar5 = *(code **)(param_1 + 0x910);
  uVar17 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
  if (pcVar5 == nvswitch_get_eng_base_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)invalidInstructionException();
      (*pcVar5)();
    }
    lVar6 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar6 + 0x5d0) != 5) {
      nvswitch_assert_log();
    }
    if (uVar17 < *(uint *)(lVar6 + 0x5d4)) {
      iVar12 = *(int *)(lVar6 + 0x5d8 + (ulong)uVar17 * 4);
      goto LAB_00242225;
    }
  }
  else {
    iVar12 = (*pcVar5)(param_1,5,0,(ulong)uVar17);
LAB_00242225:
    if ((iVar12 != -1) && (cVar10 = nvswitch_is_link_valid(param_1,uVar4), cVar10 != '\0'))
    goto LAB_0024224e;
  }
  nvswitch_assert_log();
LAB_0024224e:
  pcVar5 = *(code **)(param_1 + 0x928);
  uVar14 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
  (*pcVar5)(param_1,5,0,uVar14,0x1084,uVar15 & 0x7f | 0x80000000);
  if (uVar11 == 0) {
    return 0;
  }
  puVar16 = param_2 + (ulong)uVar11 * 0x10;
  do {
    uVar11 = param_2[7];
    uVar7 = *(ulong *)(param_2 + 0x12);
    pcVar5 = *(code **)(param_1 + 0x910);
    uVar9 = *(undefined8 *)(param_2 + 8);
    uVar8 = *(ulong *)(param_2 + 0x10);
    uVar15 = uVar11 & 0x17 | 0x20;
    if (-1 < (int)(uVar11 & 0x80000017)) {
      uVar15 = uVar11 & 0x80000017;
    }
    uVar17 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
    if (pcVar5 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)invalidInstructionException();
        (*pcVar5)();
      }
      lVar6 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar6 + 0x5d0) != 5) {
        nvswitch_assert_log();
      }
      if (uVar17 < *(uint *)(lVar6 + 0x5d4)) {
        iVar12 = *(int *)(lVar6 + 0x5d8 + (ulong)uVar17 * 4);
        goto LAB_00242301;
      }
LAB_00242315:
      nvswitch_assert_log();
    }
    else {
      iVar12 = (*pcVar5)(param_1,5,0,uVar17);
LAB_00242301:
      if ((iVar12 == -1) || (cVar10 = nvswitch_is_link_valid(param_1,uVar4), cVar10 == '\0'))
      goto LAB_00242315;
    }
    iVar12 = param_2[0xb];
    uVar2 = *(ushort *)(param_2 + 10);
    pcVar5 = *(code **)(param_1 + 0x928);
    uVar14 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
    (*pcVar5)(param_1,5,0,uVar14,0x10f4,(uint)uVar2 | iVar12 << 0x10);
    pcVar5 = *(code **)(param_1 + 0x910);
    uVar17 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
    if (pcVar5 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)invalidInstructionException();
        (*pcVar5)();
      }
      lVar6 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar6 + 0x5d0) != 5) {
        nvswitch_assert_log();
      }
      if (uVar17 < *(uint *)(lVar6 + 0x5d4)) {
        iVar12 = *(int *)(lVar6 + 0x5d8 + (ulong)uVar17 * 4);
        goto LAB_002423d4;
      }
LAB_002423e8:
      nvswitch_assert_log();
    }
    else {
      iVar12 = (*pcVar5)(param_1,5,0,uVar17);
LAB_002423d4:
      if ((iVar12 == -1) || (cVar10 = nvswitch_is_link_valid(param_1,uVar4), cVar10 == '\0'))
      goto LAB_002423e8;
    }
    uVar3 = *(undefined2 *)(param_2 + 0xc);
    pcVar5 = *(code **)(param_1 + 0x928);
    uVar14 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
    (*pcVar5)(param_1,5,0,uVar14,0x10f8,uVar3);
    pcVar5 = *(code **)(param_1 + 0x910);
    uVar17 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
    if (pcVar5 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)invalidInstructionException();
        (*pcVar5)();
      }
      lVar6 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar6 + 0x5d0) != 5) {
        nvswitch_assert_log();
      }
      if (uVar17 < *(uint *)(lVar6 + 0x5d4)) {
        iVar12 = *(int *)(lVar6 + 0x5d8 + (ulong)uVar17 * 4);
        goto LAB_0024249d;
      }
LAB_002424b1:
      nvswitch_assert_log();
    }
    else {
      iVar12 = (*pcVar5)(param_1,5,0,uVar17);
LAB_0024249d:
      if ((iVar12 == -1) || (cVar10 = nvswitch_is_link_valid(param_1,uVar4), cVar10 == '\0'))
      goto LAB_002424b1;
    }
    pcVar5 = *(code **)(param_1 + 0x928);
    uVar17 = (uint)(uVar7 >> 0x15);
    local_50 = uVar17 & 0x3ffff;
    uVar14 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
    (*pcVar5)(param_1,5,0,uVar14,0x10fc,(uint)(uVar8 >> 0x15) & 0xffff | uVar17 << 0x10);
    pcVar5 = *(code **)(param_1 + 0x910);
    uVar17 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
    if (pcVar5 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)invalidInstructionException();
        (*pcVar5)();
      }
      lVar6 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar6 + 0x5d0) != 5) {
        nvswitch_assert_log();
      }
      if (uVar17 < *(uint *)(lVar6 + 0x5d4)) {
        iVar12 = *(int *)(lVar6 + 0x5d8 + (ulong)uVar17 * 4);
        goto LAB_00242582;
      }
LAB_00242596:
      nvswitch_assert_log();
    }
    else {
      iVar12 = (*pcVar5)(param_1,5,0,uVar17);
LAB_00242582:
      if ((iVar12 == -1) || (cVar10 = nvswitch_is_link_valid(param_1,uVar4), cVar10 == '\0'))
      goto LAB_00242596;
    }
    uVar17 = param_2[5];
    pcVar5 = *(code **)(param_1 + 0x928);
    uVar14 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
    (*pcVar5)(param_1,5,0,uVar14,0x1100,uVar11 >> 8 & 0x400000 | uVar17 & 0x7f | uVar15 << 0xf);
    pcVar5 = *(code **)(param_1 + 0x910);
    uVar11 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
    if (pcVar5 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)invalidInstructionException();
        (*pcVar5)();
      }
      lVar6 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar6 + 0x5d0) != 5) {
        nvswitch_assert_log();
      }
      if (uVar11 < *(uint *)(lVar6 + 0x5d4)) {
        iVar12 = *(int *)(lVar6 + 0x5d8 + (ulong)uVar11 * 4);
        goto LAB_00242668;
      }
LAB_0024267c:
      nvswitch_assert_log();
    }
    else {
      iVar12 = (*pcVar5)(param_1,5,0,uVar11);
LAB_00242668:
      if ((iVar12 == -1) || (cVar10 = nvswitch_is_link_valid(param_1,uVar4), cVar10 == '\0'))
      goto LAB_0024267c;
    }
    pcVar5 = *(code **)(param_1 + 0x928);
    uVar14 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
    (*pcVar5)(param_1,5,0,uVar14,0x1104,(uint)(uVar8 >> 0x25) & 3 | (local_50 >> 0x10) << 4);
    pcVar5 = *(code **)(param_1 + 0x910);
    uVar11 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
    if (pcVar5 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)invalidInstructionException();
        (*pcVar5)();
      }
      lVar6 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar6 + 0x5d0) != 5) {
        nvswitch_assert_log();
      }
      if (uVar11 < *(uint *)(lVar6 + 0x5d4)) {
        iVar12 = *(int *)(lVar6 + 0x5d8 + (ulong)uVar11 * 4);
        goto LAB_0024272e;
      }
LAB_00242742:
      nvswitch_assert_log();
    }
    else {
      iVar12 = (*pcVar5)(param_1,5,0,uVar11);
LAB_0024272e:
      if ((iVar12 == -1) || (cVar10 = nvswitch_is_link_valid(param_1,uVar4), cVar10 == '\0'))
      goto LAB_00242742;
    }
    uVar11 = param_2[6];
    bVar1 = *(byte *)(param_2 + 4);
    pcVar5 = *(code **)(param_1 + 0x928);
    param_2 = param_2 + 0x10;
    uVar14 = nvswitch_get_link_eng_inst(param_1,uVar4,5);
    (*pcVar5)(param_1,5,0,uVar14,0x10f0,
              (uVar11 & 3) << 0xf | (uint)bVar1 << 0x1f | (uint)((ulong)uVar9 >> 0x27) & 0x1fff);
    if (param_2 == puVar16) {
      return 0;
    }
  } while( true );
}


// ===== 0024296f nvswitch_pri_ring_init_ls10.cold =====

void nvswitch_pri_ring_init_ls10_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  undefined8 unaff_R14;
  undefined8 unaff_R15;
  
  *(undefined8 *)(unaff_RBP + -0x10) = unaff_R14;
  *(undefined8 *)(unaff_RBP + -8) = unaff_R15;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002429b0 nvswitch_pri_ring_init_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_pri_ring_init_ls10(long *param_1)

{
  long lVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char cVar8;
  uint uVar9;
  undefined4 uVar10;
  ulong uVar11;
  int iVar12;
  long lVar13;
  ulong uVar14;
  ulong uVar15;
  undefined1 local_c8 [8];
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined8 local_7c;
  ulong local_74;
  undefined8 local_6c;
  undefined8 local_64;
  undefined8 local_5c;
  undefined8 local_54;
  undefined8 local_4c;
  undefined8 local_44;
  undefined4 local_3c;
  
  if (*(char *)((long)param_1 + 0x26) != '\0') {
    return 0;
  }
  nvswitch_timeout_create(10000000000,local_c8);
  while( true ) {
    cVar8 = nvswitch_timeout_check(local_c8);
    uVar9 = nvswitch_reg_read_32(param_1,0x660bc);
    if ((uVar9 & 0xff) == 0xff) break;
    nvswitch_os_sleep(1);
    if (cVar8 != '\0') {
      lVar13 = 1;
      local_c0 = 0;
      local_b8 = 0;
      local_b0 = 0;
      local_a8 = 0;
      local_a0 = 0;
      local_98 = 0;
      local_90 = 0;
      local_88 = 0;
      local_80 = 0;
      local_7c = 0;
      local_74 = 0;
      local_6c = 0;
      local_64 = 0;
      local_5c = 0;
      local_54 = 0;
      local_4c = 0;
      local_44 = 0;
      local_3c = 0;
      do {
        iVar12 = (int)lVar13 * 4 + 0x4dc;
        if ((code *)param_1[0x124] == nvswitch_eng_rd_ls10) {
          if ((int)param_1[0x3f1] != 7) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)invalidInstructionException();
            (*pcVar2)();
          }
          lVar1 = param_1[0x3f2];
          if (*(int *)(lVar1 + 0x130) != 1) {
            nvswitch_assert_log();
          }
          if ((*(int *)(lVar1 + 0x134) == 0) || (*(int *)(lVar1 + 0x138) == -1)) {
            nvswitch_assert_log();
            uVar10 = 0xbadfbadf;
          }
          else {
            uVar10 = nvswitch_reg_read_32(param_1,iVar12 + *(int *)(lVar1 + 0x138));
          }
        }
        else {
          uVar10 = (*(code *)param_1[0x124])(param_1,1,0,0,iVar12);
        }
        *(undefined4 *)((long)&local_7c + lVar13 * 4) = uVar10;
        lVar13 = lVar13 + 1;
      } while (lVar13 != 0x11);
      lVar13 = 2;
      do {
        uVar10 = nvswitch_reg_read_32(param_1,(int)lVar13 * 4 + 0x8f0318);
        *(undefined4 *)((long)&local_c0 + lVar13 * 4) = uVar10;
        lVar13 = lVar13 + 1;
      } while (lVar13 != 6);
      iVar12 = nvswitch_translate_hw_error(0x2718);
      if (iVar12 == 1) {
        nvswitch_assert_log();
      }
      uVar7 = local_3c;
      uVar11 = local_b8;
      uVar10 = local_b8._4_4_;
      uVar15 = local_74 & 0xffffffff;
      uVar6 = local_44._4_4_;
      uVar5 = local_4c._4_4_;
      uVar4 = local_7c._4_4_;
      uVar3 = local_b0._4_4_;
      lVar13 = *param_1;
      uVar14 = local_b0 & 0xffffffff;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Firmware initialization failure (0x%x/0x%x, 0x%x, 0x%x, 0x%x/0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n"
                        ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),*(undefined1 *)(lVar13 + 0x44),
                        *(undefined1 *)(lVar13 + 0x45),*(undefined1 *)(lVar13 + 0x46),0x2718,uVar9,
                        local_b8 & 0xffffffff,local_b8._4_4_,uVar14,local_b0._4_4_,local_7c._4_4_,
                        uVar15,local_4c._4_4_,local_44._4_4_,local_3c);
      nvswitch_os_report_error
                (param_1[3],0x2718,
                 "Fatal, Firmware initialization failure (0x%x/0x%x, 0x%x, 0x%x, 0x%x/0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n"
                 ,uVar9,uVar11 & 0xffffffff,uVar10,uVar14,uVar3,uVar4,uVar15,uVar5,uVar6,uVar7);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2718,
                 "Fatal, Firmware initialization failure (0x%x/0x%x, 0x%x, 0x%x, 0x%x/0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n"
                 ,uVar9,uVar11 & 0xffffffff,uVar10,uVar14,uVar3,uVar4,uVar15,uVar5,uVar6,uVar7);
      nvswitch_inforom_bbx_add_sxid(param_1,0x2718,0,0,0);
      return 0xfffffffb;
    }
  }
  if ((code *)param_1[0x124] == nvswitch_eng_rd_ls10) {
    if ((int)param_1[0x3f1] != 7) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    lVar13 = param_1[0x3f2];
    if (*(int *)(&DAT_00002bf8 + lVar13) == 0x26) {
      iVar12 = *(int *)(lVar13 + 0x2bfc);
    }
    else {
      nvswitch_assert_log();
      iVar12 = *(int *)(lVar13 + 0x2bfc);
    }
    if ((iVar12 == 0) || (*(int *)(lVar13 + 0x2c00) == -1)) {
      nvswitch_assert_log();
      return 0xfffffff9;
    }
    uVar9 = nvswitch_reg_read_32(param_1,*(int *)(lVar13 + 0x2c00) + 0x174);
  }
  else {
    uVar9 = (*(code *)param_1[0x124])(param_1,0x26,0,0,0x174);
  }
  if ((uVar9 & 7) == 4) {
    return 0;
  }
  if ((uVar9 & 7) != 2) {
    return 0xfffffff9;
  }
  (*(code *)param_1[0x125])(param_1,0x26,0,0,0x174,0x100);
  if (*(char *)((long)param_1 + 0x24) == '\0') {
    nvswitch_timeout_create(1000000,local_c8);
  }
  else {
    nvswitch_timeout_create(10000000,local_c8);
  }
  do {
    cVar8 = nvswitch_timeout_check(local_c8);
    if ((code *)param_1[0x124] == nvswitch_eng_rd_ls10) {
      if ((int)param_1[0x3f1] != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar13 = param_1[0x3f2];
      if (*(int *)(&DAT_00002bf8 + lVar13) != 0x26) {
        nvswitch_assert_log();
      }
      if ((*(int *)(lVar13 + 0x2bfc) != 0) && (*(int *)(lVar13 + 0x2c00) != -1)) {
        uVar11 = nvswitch_reg_read_32(param_1,*(int *)(lVar13 + 0x2c00) + 0x174);
        goto LAB_00242b73;
      }
      nvswitch_assert_log();
    }
    else {
      uVar11 = (*(code *)param_1[0x124])(param_1,0x26,0,0,0x174);
LAB_00242b73:
      if ((uVar11 & 0x300) == 0) {
        if (*(char *)((long)param_1 + 0x24) == '\0') {
          nvswitch_timeout_create(1000000,local_c8);
        }
        else {
          nvswitch_timeout_create(5000000,local_c8);
        }
        break;
      }
    }
    if (cVar8 != '\0') {
      return 0xfffffff9;
    }
  } while( true );
LAB_00242ba9:
  cVar8 = nvswitch_timeout_check(local_c8);
  if ((code *)param_1[0x124] == nvswitch_eng_rd_ls10) {
    if ((int)param_1[0x3f1] != 7) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    lVar13 = param_1[0x3f2];
    if (*(int *)(&DAT_00002bf8 + lVar13) != 0x26) {
      nvswitch_assert_log();
    }
    if ((*(int *)(lVar13 + 0x2bfc) != 0) && (*(int *)(lVar13 + 0x2c00) != -1)) {
      uVar9 = nvswitch_reg_read_32(param_1,*(int *)(lVar13 + 0x2c00) + 0x174);
      goto LAB_00242c13;
    }
    nvswitch_assert_log();
  }
  else {
    uVar9 = (*(code *)param_1[0x124])(param_1,0x26,0,0,0x174);
LAB_00242c13:
    if ((uVar9 & 7) == 4) {
      if ((code *)param_1[0x124] == nvswitch_eng_rd_ls10) {
        nvswitch_eng_rd_ls10();
      }
      else {
        (*(code *)param_1[0x124])(param_1,0x2a,0,0,0x58);
      }
      if ((code *)param_1[0x124] == nvswitch_eng_rd_ls10) {
        nvswitch_eng_rd_ls10();
        return 0;
      }
      (*(code *)param_1[0x124])(param_1,0x2a,0,0,0x5c);
      return 0;
    }
  }
  if (cVar8 != '\0') {
    return 0xfffffff9;
  }
  goto LAB_00242ba9;
}


// ===== 0024308b nvswitch_ctrl_set_remap_policy_valid_ls10.cold =====

void nvswitch_ctrl_set_remap_policy_valid_ls10_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  undefined8 unaff_R13;
  
  *(undefined8 *)(unaff_RBP + -0x18) = unaff_R13;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00243190 nvswitch_ctrl_set_remap_policy_valid_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r12 replaced with injection: x86_indirect_thunk_r12 */
/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */

undefined8 nvswitch_ctrl_set_remap_policy_valid_ls10(long param_1,undefined4 *param_2)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined8 uVar10;
  uint local_68;
  uint local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  uint local_54;
  uint local_50;
  uint local_3c [3];
  
  iVar1 = param_2[2];
  cVar4 = nvswitch_is_tnvl_mode_locked();
  if (cVar4 == '\0') {
    pcVar2 = *(code **)(param_1 + 0x910);
    uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
    if (pcVar2 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar3 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar3 + 0x5d0) == 5) {
        uVar6 = *(uint *)(lVar3 + 0x5d4);
      }
      else {
        nvswitch_assert_log();
        uVar6 = *(uint *)(lVar3 + 0x5d4);
      }
      if (uVar5 < uVar6) {
        iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar5 * 4);
        goto LAB_00243225;
      }
    }
    else {
      iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar5);
LAB_00243225:
      if ((iVar9 != -1) && (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 != '\0')) {
        uVar10 = nvswitch_get_remap_table_selector(param_1,param_2[1],local_3c);
        if ((int)uVar10 != 0) {
          return uVar10;
        }
        uVar5 = nvswitch_get_ingress_ram_size(param_1,local_3c[0]);
        if ((((uint)param_2[2] < uVar5) && ((uint)param_2[3] < 0x41)) &&
           ((uint)(param_2[2] + param_2[3]) <= uVar5)) {
          cVar4 = nvswitch_is_tnvl_mode_locked(param_1);
          if (cVar4 == '\0') {
            uVar10 = nvswitch_soe_issue_ingress_stop(param_1,*param_2,1);
            if ((int)uVar10 != 0) {
              return uVar10;
            }
            if (param_2[1] == 3) {
              if (param_2[3] != 0) {
                uVar5 = 0;
                do {
                  pcVar2 = *(code **)(param_1 + 0x910);
                  uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  if (pcVar2 == nvswitch_get_eng_base_ls10) {
                    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)invalidInstructionException();
                      (*pcVar2)();
                    }
                    lVar3 = *(long *)(param_1 + 0x1f90);
                    if (*(int *)(lVar3 + 0x5d0) != 5) {
                      nvswitch_assert_log();
                    }
                    if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                      iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                      goto LAB_00243cad;
                    }
LAB_00243cc1:
                    nvswitch_assert_log();
                  }
                  else {
                    iVar9 = (*pcVar2)(param_1,5,0,uVar6);
LAB_00243cad:
                    if ((iVar9 == -1) ||
                       (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                    goto LAB_00243cc1;
                  }
                  pcVar2 = *(code **)(param_1 + 0x928);
                  uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  (*pcVar2)(param_1,5,0,uVar7,0x1084,iVar1 + uVar5 & 0x7f);
                  pcVar2 = *(code **)(param_1 + 0x910);
                  uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  if (pcVar2 == nvswitch_get_eng_base_ls10) {
                    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)invalidInstructionException();
                      (*pcVar2)();
                    }
                    lVar3 = *(long *)(param_1 + 0x1f90);
                    if (*(int *)(lVar3 + 0x5d0) != 5) {
                      nvswitch_assert_log();
                    }
                    if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                      iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                      goto LAB_00243d5b;
                    }
LAB_00243d6f:
                    nvswitch_assert_log();
                  }
                  else {
                    iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_00243d5b:
                    if ((iVar9 == -1) ||
                       (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                    goto LAB_00243d6f;
                  }
                  pcVar2 = *(code **)(param_1 + 0x920);
                  uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  if (pcVar2 == nvswitch_eng_rd_ls10) {
                    local_50 = nvswitch_eng_rd_ls10();
                  }
                  else {
                    local_50 = (*pcVar2)(param_1,5,0,uVar7,0x10f0);
                  }
                  pcVar2 = *(code **)(param_1 + 0x910);
                  uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  if (pcVar2 == nvswitch_get_eng_base_ls10) {
                    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)invalidInstructionException();
                      (*pcVar2)();
                    }
                    lVar3 = *(long *)(param_1 + 0x1f90);
                    if (*(int *)(lVar3 + 0x5d0) != 5) {
                      nvswitch_assert_log();
                    }
                    if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                      iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                      goto LAB_00243e0e;
                    }
LAB_00243e22:
                    nvswitch_assert_log();
                  }
                  else {
                    iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_00243e0e:
                    if ((iVar9 == -1) ||
                       (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                    goto LAB_00243e22;
                  }
                  pcVar2 = *(code **)(param_1 + 0x920);
                  uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  if (pcVar2 == nvswitch_eng_rd_ls10) {
                    local_54 = nvswitch_eng_rd_ls10();
                  }
                  else {
                    local_54 = (*pcVar2)(param_1,5,0,uVar7,0x10f4);
                  }
                  pcVar2 = *(code **)(param_1 + 0x910);
                  uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  if (pcVar2 == nvswitch_get_eng_base_ls10) {
                    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)invalidInstructionException();
                      (*pcVar2)();
                    }
                    lVar3 = *(long *)(param_1 + 0x1f90);
                    if (*(int *)(lVar3 + 0x5d0) != 5) {
                      nvswitch_assert_log();
                    }
                    if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                      iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                      goto LAB_00243ec1;
                    }
LAB_00243ed5:
                    nvswitch_assert_log();
                  }
                  else {
                    iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_00243ec1:
                    if ((iVar9 == -1) ||
                       (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                    goto LAB_00243ed5;
                  }
                  pcVar2 = *(code **)(param_1 + 0x920);
                  uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  if (pcVar2 == nvswitch_eng_rd_ls10) {
                    local_58 = nvswitch_eng_rd_ls10();
                  }
                  else {
                    local_58 = (*pcVar2)(param_1,5,0,uVar7,0x10f8);
                  }
                  pcVar2 = *(code **)(param_1 + 0x910);
                  uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  if (pcVar2 == nvswitch_get_eng_base_ls10) {
                    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)invalidInstructionException();
                      (*pcVar2)();
                    }
                    lVar3 = *(long *)(param_1 + 0x1f90);
                    if (*(int *)(lVar3 + 0x5d0) != 5) {
                      nvswitch_assert_log();
                    }
                    if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                      iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                      goto LAB_00243f74;
                    }
LAB_00243f88:
                    nvswitch_assert_log();
                  }
                  else {
                    iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_00243f74:
                    if ((iVar9 == -1) ||
                       (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                    goto LAB_00243f88;
                  }
                  pcVar2 = *(code **)(param_1 + 0x920);
                  uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  if (pcVar2 == nvswitch_eng_rd_ls10) {
                    local_5c = nvswitch_eng_rd_ls10();
                  }
                  else {
                    local_5c = (*pcVar2)(param_1,5,0,uVar7,0x10fc);
                  }
                  pcVar2 = *(code **)(param_1 + 0x910);
                  uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  if (pcVar2 == nvswitch_get_eng_base_ls10) {
                    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)invalidInstructionException();
                      (*pcVar2)();
                    }
                    lVar3 = *(long *)(param_1 + 0x1f90);
                    if (*(int *)(lVar3 + 0x5d0) != 5) {
                      nvswitch_assert_log();
                    }
                    if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                      iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                      goto LAB_00244027;
                    }
LAB_0024403b:
                    nvswitch_assert_log();
                  }
                  else {
                    iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_00244027:
                    if ((iVar9 == -1) ||
                       (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                    goto LAB_0024403b;
                  }
                  pcVar2 = *(code **)(param_1 + 0x920);
                  uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  if (pcVar2 == nvswitch_eng_rd_ls10) {
                    local_60 = nvswitch_eng_rd_ls10();
                  }
                  else {
                    local_60 = (*pcVar2)(param_1,5,0,uVar7,0x1100);
                  }
                  pcVar2 = *(code **)(param_1 + 0x910);
                  uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  if (pcVar2 == nvswitch_get_eng_base_ls10) {
                    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)invalidInstructionException();
                      (*pcVar2)();
                    }
                    lVar3 = *(long *)(param_1 + 0x1f90);
                    if (*(int *)(lVar3 + 0x5d0) != 5) {
                      nvswitch_assert_log();
                    }
                    if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                      iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                      goto LAB_002440dc;
                    }
LAB_002440f0:
                    nvswitch_assert_log();
                  }
                  else {
                    iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_002440dc:
                    if ((iVar9 == -1) ||
                       (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                    goto LAB_002440f0;
                  }
                  pcVar2 = *(code **)(param_1 + 0x920);
                  uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  if (pcVar2 == nvswitch_eng_rd_ls10) {
                    uVar7 = nvswitch_eng_rd_ls10();
                  }
                  else {
                    uVar7 = (*pcVar2)(param_1,5,0,uVar7,0x1104);
                  }
                  pcVar2 = *(code **)(param_1 + 0x910);
                  local_64 = (uint)*(byte *)((long)param_2 + (ulong)uVar5 + 0x10);
                  uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  if (pcVar2 == nvswitch_get_eng_base_ls10) {
                    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)invalidInstructionException();
                      (*pcVar2)();
                    }
                    lVar3 = *(long *)(param_1 + 0x1f90);
                    if (*(int *)(lVar3 + 0x5d0) != 5) {
                      nvswitch_assert_log();
                    }
                    if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                      iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                      goto LAB_002441a1;
                    }
LAB_002441b5:
                    nvswitch_assert_log();
                  }
                  else {
                    iVar9 = (*pcVar2)(param_1,5,0,uVar6);
LAB_002441a1:
                    if ((iVar9 == -1) ||
                       (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                    goto LAB_002441b5;
                  }
                  pcVar2 = *(code **)(param_1 + 0x928);
                  uVar8 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  (*pcVar2)(param_1,5,0,uVar8,0x1104,uVar7);
                  pcVar2 = *(code **)(param_1 + 0x910);
                  uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  if (pcVar2 == nvswitch_get_eng_base_ls10) {
                    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)invalidInstructionException();
                      (*pcVar2)();
                    }
                    lVar3 = *(long *)(param_1 + 0x1f90);
                    if (*(int *)(lVar3 + 0x5d0) != 5) {
                      nvswitch_assert_log();
                    }
                    if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                      iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                      goto LAB_00244249;
                    }
LAB_0024425d:
                    nvswitch_assert_log();
                  }
                  else {
                    iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_00244249:
                    if ((iVar9 == -1) ||
                       (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                    goto LAB_0024425d;
                  }
                  pcVar2 = *(code **)(param_1 + 0x928);
                  uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  (*pcVar2)(param_1,5,0,uVar7,0x1100,local_60);
                  pcVar2 = *(code **)(param_1 + 0x910);
                  uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  if (pcVar2 == nvswitch_get_eng_base_ls10) {
                    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)invalidInstructionException();
                      (*pcVar2)();
                    }
                    lVar3 = *(long *)(param_1 + 0x1f90);
                    if (*(int *)(lVar3 + 0x5d0) != 5) {
                      nvswitch_assert_log();
                    }
                    if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                      iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                      goto LAB_002442f0;
                    }
LAB_00244304:
                    nvswitch_assert_log();
                  }
                  else {
                    iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_002442f0:
                    if ((iVar9 == -1) ||
                       (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                    goto LAB_00244304;
                  }
                  pcVar2 = *(code **)(param_1 + 0x928);
                  uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  (*pcVar2)(param_1,5,0,uVar7,0x10fc,local_5c);
                  pcVar2 = *(code **)(param_1 + 0x910);
                  uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  if (pcVar2 == nvswitch_get_eng_base_ls10) {
                    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)invalidInstructionException();
                      (*pcVar2)();
                    }
                    lVar3 = *(long *)(param_1 + 0x1f90);
                    if (*(int *)(lVar3 + 0x5d0) != 5) {
                      nvswitch_assert_log();
                    }
                    if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                      iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                      goto LAB_00244397;
                    }
LAB_002443ab:
                    nvswitch_assert_log();
                  }
                  else {
                    iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_00244397:
                    if ((iVar9 == -1) ||
                       (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                    goto LAB_002443ab;
                  }
                  pcVar2 = *(code **)(param_1 + 0x928);
                  uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  (*pcVar2)(param_1,5,0,uVar7,0x10f8,local_58);
                  pcVar2 = *(code **)(param_1 + 0x910);
                  uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  if (pcVar2 == nvswitch_get_eng_base_ls10) {
                    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)invalidInstructionException();
                      (*pcVar2)();
                    }
                    lVar3 = *(long *)(param_1 + 0x1f90);
                    if (*(int *)(lVar3 + 0x5d0) != 5) {
                      nvswitch_assert_log();
                    }
                    if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                      iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                      goto LAB_0024443e;
                    }
LAB_00244452:
                    nvswitch_assert_log();
                  }
                  else {
                    iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_0024443e:
                    if ((iVar9 == -1) ||
                       (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                    goto LAB_00244452;
                  }
                  pcVar2 = *(code **)(param_1 + 0x928);
                  uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  (*pcVar2)(param_1,5,0,uVar7,0x10f4,local_54);
                  pcVar2 = *(code **)(param_1 + 0x910);
                  uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  if (pcVar2 == nvswitch_get_eng_base_ls10) {
                    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)invalidInstructionException();
                      (*pcVar2)();
                    }
                    lVar3 = *(long *)(param_1 + 0x1f90);
                    if (*(int *)(lVar3 + 0x5d0) != 5) {
                      nvswitch_assert_log();
                    }
                    if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                      iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                      goto LAB_002444e5;
                    }
LAB_002444f9:
                    nvswitch_assert_log();
                  }
                  else {
                    iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_002444e5:
                    if ((iVar9 == -1) ||
                       (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                    goto LAB_002444f9;
                  }
                  pcVar2 = *(code **)(param_1 + 0x928);
                  uVar5 = uVar5 + 1;
                  uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                  (*pcVar2)(param_1,5,0,uVar7,0x10f0,local_50 & 0x7fffffff | local_64 << 0x1f);
                } while (uVar5 < (uint)param_2[3]);
              }
            }
            else if (param_2[3] != 0) {
              uVar5 = 0;
              local_50 = (local_3c[0] & 7) << 0x10;
              do {
                pcVar2 = *(code **)(param_1 + 0x910);
                uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                if (pcVar2 == nvswitch_get_eng_base_ls10) {
                  if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                    pcVar2 = (code *)invalidInstructionException();
                    (*pcVar2)();
                  }
                  lVar3 = *(long *)(param_1 + 0x1f90);
                  if (*(int *)(lVar3 + 0x5d0) != 5) {
                    nvswitch_assert_log();
                  }
                  if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                    iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                    goto LAB_00243532;
                  }
LAB_00243546:
                  nvswitch_assert_log();
                }
                else {
                  iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_00243532:
                  if ((iVar9 == -1) ||
                     (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                  goto LAB_00243546;
                }
                pcVar2 = *(code **)(param_1 + 0x928);
                local_50 = iVar1 + uVar5 & 0x3fff | local_50 & 0xffffc000;
                uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                (*pcVar2)(param_1,5,0,uVar7,0x1080,local_50);
                pcVar2 = *(code **)(param_1 + 0x910);
                uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                if (pcVar2 == nvswitch_get_eng_base_ls10) {
                  if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                    pcVar2 = (code *)invalidInstructionException();
                    (*pcVar2)();
                  }
                  lVar3 = *(long *)(param_1 + 0x1f90);
                  if (*(int *)(lVar3 + 0x5d0) != 5) {
                    nvswitch_assert_log();
                  }
                  if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                    iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                    goto LAB_002435f3;
                  }
LAB_00243607:
                  nvswitch_assert_log();
                }
                else {
                  iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_002435f3:
                  if ((iVar9 == -1) ||
                     (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                  goto LAB_00243607;
                }
                pcVar2 = *(code **)(param_1 + 0x920);
                uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                if (pcVar2 == nvswitch_eng_rd_ls10) {
                  local_54 = nvswitch_eng_rd_ls10();
                }
                else {
                  local_54 = (*pcVar2)(param_1,5,0,uVar7,0x1090);
                }
                pcVar2 = *(code **)(param_1 + 0x910);
                uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                if (pcVar2 == nvswitch_get_eng_base_ls10) {
                  if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                    pcVar2 = (code *)invalidInstructionException();
                    (*pcVar2)();
                  }
                  lVar3 = *(long *)(param_1 + 0x1f90);
                  if (*(int *)(lVar3 + 0x5d0) != 5) {
                    nvswitch_assert_log();
                  }
                  if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                    iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                    goto LAB_002436a6;
                  }
LAB_002436ba:
                  nvswitch_assert_log();
                }
                else {
                  iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_002436a6:
                  if ((iVar9 == -1) ||
                     (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                  goto LAB_002436ba;
                }
                pcVar2 = *(code **)(param_1 + 0x920);
                uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                if (pcVar2 == nvswitch_eng_rd_ls10) {
                  local_58 = nvswitch_eng_rd_ls10();
                }
                else {
                  local_58 = (*pcVar2)(param_1,5,0,uVar7,0x1094);
                }
                pcVar2 = *(code **)(param_1 + 0x910);
                uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                if (pcVar2 == nvswitch_get_eng_base_ls10) {
                  if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                    pcVar2 = (code *)invalidInstructionException();
                    (*pcVar2)();
                  }
                  lVar3 = *(long *)(param_1 + 0x1f90);
                  if (*(int *)(lVar3 + 0x5d0) != 5) {
                    nvswitch_assert_log();
                  }
                  if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                    iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                    goto LAB_00243759;
                  }
LAB_0024376d:
                  nvswitch_assert_log();
                }
                else {
                  iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_00243759:
                  if ((iVar9 == -1) ||
                     (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                  goto LAB_0024376d;
                }
                pcVar2 = *(code **)(param_1 + 0x920);
                uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                if (pcVar2 == nvswitch_eng_rd_ls10) {
                  local_5c = nvswitch_eng_rd_ls10();
                }
                else {
                  local_5c = (*pcVar2)(param_1,5,0,uVar7,0x1098);
                }
                pcVar2 = *(code **)(param_1 + 0x910);
                uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                if (pcVar2 == nvswitch_get_eng_base_ls10) {
                  if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                    pcVar2 = (code *)invalidInstructionException();
                    (*pcVar2)();
                  }
                  lVar3 = *(long *)(param_1 + 0x1f90);
                  if (*(int *)(lVar3 + 0x5d0) != 5) {
                    nvswitch_assert_log();
                  }
                  if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                    iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                    goto LAB_0024380c;
                  }
LAB_00243820:
                  nvswitch_assert_log();
                }
                else {
                  iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_0024380c:
                  if ((iVar9 == -1) ||
                     (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                  goto LAB_00243820;
                }
                pcVar2 = *(code **)(param_1 + 0x920);
                uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                if (pcVar2 == nvswitch_eng_rd_ls10) {
                  local_60 = nvswitch_eng_rd_ls10();
                }
                else {
                  local_60 = (*pcVar2)(param_1,5,0,uVar7,0x109c);
                }
                pcVar2 = *(code **)(param_1 + 0x910);
                uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                if (pcVar2 == nvswitch_get_eng_base_ls10) {
                  if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                    pcVar2 = (code *)invalidInstructionException();
                    (*pcVar2)();
                  }
                  lVar3 = *(long *)(param_1 + 0x1f90);
                  if (*(int *)(lVar3 + 0x5d0) != 5) {
                    nvswitch_assert_log();
                  }
                  if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                    iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                    goto LAB_002438bf;
                  }
LAB_002438d3:
                  nvswitch_assert_log();
                }
                else {
                  iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_002438bf:
                  if ((iVar9 == -1) ||
                     (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                  goto LAB_002438d3;
                }
                pcVar2 = *(code **)(param_1 + 0x920);
                uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                if (pcVar2 == nvswitch_eng_rd_ls10) {
                  local_64 = nvswitch_eng_rd_ls10();
                }
                else {
                  local_64 = (*pcVar2)(param_1,5,0,uVar7,0x10a0);
                }
                pcVar2 = *(code **)(param_1 + 0x910);
                uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                if (pcVar2 == nvswitch_get_eng_base_ls10) {
                  if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                    pcVar2 = (code *)invalidInstructionException();
                    (*pcVar2)();
                  }
                  lVar3 = *(long *)(param_1 + 0x1f90);
                  if (*(int *)(lVar3 + 0x5d0) != 5) {
                    nvswitch_assert_log();
                  }
                  if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                    iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                    goto LAB_00243974;
                  }
LAB_00243988:
                  nvswitch_assert_log();
                }
                else {
                  iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_00243974:
                  if ((iVar9 == -1) ||
                     (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                  goto LAB_00243988;
                }
                pcVar2 = *(code **)(param_1 + 0x920);
                uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                if (pcVar2 == nvswitch_eng_rd_ls10) {
                  uVar7 = nvswitch_eng_rd_ls10();
                }
                else {
                  uVar7 = (*pcVar2)(param_1,5,0,uVar7,0x10a4);
                }
                pcVar2 = *(code **)(param_1 + 0x910);
                local_68 = (uint)*(byte *)((long)param_2 + (ulong)uVar5 + 0x10);
                uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                if (pcVar2 == nvswitch_get_eng_base_ls10) {
                  if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                    pcVar2 = (code *)invalidInstructionException();
                    (*pcVar2)();
                  }
                  lVar3 = *(long *)(param_1 + 0x1f90);
                  if (*(int *)(lVar3 + 0x5d0) != 5) {
                    nvswitch_assert_log();
                  }
                  if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                    iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                    goto LAB_00243a39;
                  }
LAB_00243a4d:
                  nvswitch_assert_log();
                }
                else {
                  iVar9 = (*pcVar2)(param_1,5,0,uVar6);
LAB_00243a39:
                  if ((iVar9 == -1) ||
                     (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                  goto LAB_00243a4d;
                }
                pcVar2 = *(code **)(param_1 + 0x928);
                uVar8 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                (*pcVar2)(param_1,5,0,uVar8,0x10a4,uVar7);
                pcVar2 = *(code **)(param_1 + 0x910);
                uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                if (pcVar2 == nvswitch_get_eng_base_ls10) {
                  if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                    pcVar2 = (code *)invalidInstructionException();
                    (*pcVar2)();
                  }
                  lVar3 = *(long *)(param_1 + 0x1f90);
                  if (*(int *)(lVar3 + 0x5d0) != 5) {
                    nvswitch_assert_log();
                  }
                  if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                    iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                    goto LAB_00243ae1;
                  }
LAB_00243af5:
                  nvswitch_assert_log();
                }
                else {
                  iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_00243ae1:
                  if ((iVar9 == -1) ||
                     (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                  goto LAB_00243af5;
                }
                pcVar2 = *(code **)(param_1 + 0x928);
                uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                (*pcVar2)(param_1,5,0,uVar7,0x10a0,local_64);
                pcVar2 = *(code **)(param_1 + 0x910);
                uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                if (pcVar2 == nvswitch_get_eng_base_ls10) {
                  if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                    pcVar2 = (code *)invalidInstructionException();
                    (*pcVar2)();
                  }
                  lVar3 = *(long *)(param_1 + 0x1f90);
                  if (*(int *)(lVar3 + 0x5d0) != 5) {
                    nvswitch_assert_log();
                  }
                  if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                    iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                    goto LAB_00243b88;
                  }
LAB_00243b9c:
                  nvswitch_assert_log();
                }
                else {
                  iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_00243b88:
                  if ((iVar9 == -1) ||
                     (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                  goto LAB_00243b9c;
                }
                pcVar2 = *(code **)(param_1 + 0x928);
                uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                (*pcVar2)(param_1,5,0,uVar7,0x109c,local_60);
                pcVar2 = *(code **)(param_1 + 0x910);
                uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                if (pcVar2 == nvswitch_get_eng_base_ls10) {
                  if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                    pcVar2 = (code *)invalidInstructionException();
                    (*pcVar2)();
                  }
                  lVar3 = *(long *)(param_1 + 0x1f90);
                  if (*(int *)(lVar3 + 0x5d0) != 5) {
                    nvswitch_assert_log();
                  }
                  if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                    iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                    goto LAB_0024331d;
                  }
LAB_00243331:
                  nvswitch_assert_log();
                }
                else {
                  iVar9 = (*pcVar2)(param_1,5,0,uVar6);
LAB_0024331d:
                  if ((iVar9 == -1) ||
                     (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                  goto LAB_00243331;
                }
                pcVar2 = *(code **)(param_1 + 0x928);
                uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                (*pcVar2)(param_1,5,0,uVar7,0x1098,local_5c);
                pcVar2 = *(code **)(param_1 + 0x910);
                uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                if (pcVar2 == nvswitch_get_eng_base_ls10) {
                  if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                    pcVar2 = (code *)invalidInstructionException();
                    (*pcVar2)();
                  }
                  lVar3 = *(long *)(param_1 + 0x1f90);
                  if (*(int *)(lVar3 + 0x5d0) != 5) {
                    nvswitch_assert_log();
                  }
                  if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                    iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                    goto LAB_002433c4;
                  }
LAB_002433d8:
                  nvswitch_assert_log();
                }
                else {
                  iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_002433c4:
                  if ((iVar9 == -1) ||
                     (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                  goto LAB_002433d8;
                }
                pcVar2 = *(code **)(param_1 + 0x928);
                uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                (*pcVar2)(param_1,5,0,uVar7,0x1094,local_58);
                pcVar2 = *(code **)(param_1 + 0x910);
                uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                if (pcVar2 == nvswitch_get_eng_base_ls10) {
                  if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                    pcVar2 = (code *)invalidInstructionException();
                    (*pcVar2)();
                  }
                  lVar3 = *(long *)(param_1 + 0x1f90);
                  if (*(int *)(lVar3 + 0x5d0) != 5) {
                    nvswitch_assert_log();
                  }
                  if (uVar6 < *(uint *)(lVar3 + 0x5d4)) {
                    iVar9 = *(int *)(lVar3 + 0x5d8 + (ulong)uVar6 * 4);
                    goto LAB_0024346b;
                  }
LAB_0024347f:
                  nvswitch_assert_log();
                }
                else {
                  iVar9 = (*pcVar2)(param_1,5,0,(ulong)uVar6);
LAB_0024346b:
                  if ((iVar9 == -1) ||
                     (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
                  goto LAB_0024347f;
                }
                pcVar2 = *(code **)(param_1 + 0x928);
                uVar5 = uVar5 + 1;
                uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
                (*pcVar2)(param_1,5,0,uVar7,0x1090,local_54 & 0x7fffffff | local_68 << 0x1f);
              } while (uVar5 < (uint)param_2[3]);
            }
            uVar10 = nvswitch_soe_issue_ingress_stop(param_1,*param_2,0);
            return uVar10;
          }
          goto LAB_00244995;
        }
      }
    }
    uVar10 = 0xffffffff;
  }
  else {
LAB_00244995:
    uVar10 = 0xfffffff1;
  }
  return uVar10;
}


// ===== 0024499f nvswitch_internal_latency_bin_log_ls10.cold =====

void nvswitch_internal_latency_bin_log_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00244a90 nvswitch_internal_latency_bin_log_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r12 replaced with injection: x86_indirect_thunk_r12 */
/* WARNING: Function: __x86_indirect_thunk_rbx replaced with injection: x86_indirect_thunk_rbx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

void nvswitch_internal_latency_bin_log_ls10(long param_1)

{
  int *piVar1;
  long lVar2;
  code *pcVar3;
  char cVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  long lVar11;
  long lVar12;
  ulong uVar13;
  int iVar14;
  uint uVar15;
  ulong uVar16;
  uint local_3c;
  
  if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar2 = *(long *)(param_1 + 0x1f90);
  if ((*(long *)(&DAT_0000dde0 + lVar2) == 0) ||
     (cVar4 = nvswitch_is_tnvl_mode_locked(), cVar4 != '\0')) {
    return;
  }
  lVar11 = nvswitch_os_get_platform_time();
  lVar12 = *(long *)(*(long *)(&DAT_0000dde0 + lVar2) + 8);
  *(long *)(*(long *)(&DAT_0000dde0 + lVar2) + 8) = lVar11;
  if ((((*(char *)(param_1 + 0x25) == '\0') || (*(char *)(param_1 + 0x26) == '\0')) && (lVar12 != 0)
      ) && ((ulong)**(uint **)(&DAT_0000dde0 + lVar2) * 1000000 < (ulong)(lVar11 - lVar12))) {
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x104,0x11);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x104,1);
    return;
  }
  uVar16 = 0;
  do {
    uVar5 = nvswitch_get_num_links(param_1);
    uVar15 = (uint)uVar16;
    if (uVar5 <= uVar15) {
      return;
    }
    pcVar3 = *(code **)(param_1 + 0x910);
    uVar5 = nvswitch_get_link_eng_inst(param_1,uVar16,5);
    if (pcVar3 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)invalidInstructionException();
        (*pcVar3)();
      }
      lVar12 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar12 + 0x5d0) != 5) {
        nvswitch_assert_log();
      }
      if (uVar5 < *(uint *)(lVar12 + 0x5d4)) {
        iVar14 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar5 * 4);
        goto LAB_00244b57;
      }
    }
    else {
      iVar14 = (*pcVar3)(param_1,5,0,uVar5);
LAB_00244b57:
      if ((iVar14 != -1) && (cVar4 = nvswitch_is_link_valid(param_1,uVar16), cVar4 != '\0')) {
        pcVar3 = *(code **)(param_1 + 0x910);
        uVar5 = nvswitch_get_link_eng_inst(param_1,uVar16,5);
        if (pcVar3 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)invalidInstructionException();
            (*pcVar3)();
          }
          lVar12 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar12 + 0x5d0) == 5) {
            uVar7 = *(uint *)(lVar12 + 0x5d4);
          }
          else {
            nvswitch_assert_log();
            uVar7 = *(uint *)(lVar12 + 0x5d4);
          }
          if (uVar5 < uVar7) {
            iVar14 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar5 * 4);
            goto LAB_00245a68;
          }
LAB_00244c18:
          nvswitch_assert_log();
        }
        else {
          iVar14 = (*pcVar3)(param_1,5,0,(ulong)uVar5);
LAB_00245a68:
          if ((iVar14 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,uVar16), cVar4 == '\0'))
          goto LAB_00244c18;
        }
        pcVar3 = *(code **)(param_1 + 0x928);
        uVar6 = nvswitch_get_link_eng_inst(param_1,uVar16,5);
        (*pcVar3)(param_1,5,0,uVar6,0x104,0x11);
        pcVar3 = *(code **)(param_1 + 0x910);
        uVar5 = nvswitch_get_link_eng_inst(param_1,uVar16,5);
        if (pcVar3 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)invalidInstructionException();
            (*pcVar3)();
          }
          lVar12 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar12 + 0x5d0) == 5) {
            uVar7 = *(uint *)(lVar12 + 0x5d4);
          }
          else {
            nvswitch_assert_log();
            uVar7 = *(uint *)(lVar12 + 0x5d4);
          }
          if (uVar5 < uVar7) {
            iVar14 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar5 * 4);
            goto LAB_00245a38;
          }
LAB_00244ca9:
          nvswitch_assert_log();
        }
        else {
          iVar14 = (*pcVar3)(param_1,5,0,(ulong)uVar5);
LAB_00245a38:
          if ((iVar14 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,uVar16), cVar4 == '\0'))
          goto LAB_00244ca9;
        }
        pcVar3 = *(code **)(param_1 + 0x920);
        uVar6 = nvswitch_get_link_eng_inst(param_1,uVar16,5);
        if (pcVar3 == nvswitch_eng_rd_ls10) {
          uVar5 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar5 = (*pcVar3)(param_1,5,0,uVar6,0x40);
        }
        local_3c = 0;
        iVar14 = 0x118;
        do {
          if ((uVar5 & 1) == 0) {
            while ((0x21UL >> ((ulong)local_3c & 0x3f) & 1) == 0) {
              local_3c = local_3c + 1;
              if (local_3c == 8) goto LAB_00245689;
              iVar14 = iVar14 + 0x34;
            }
          }
          else {
            while ((0xe1UL >> ((ulong)local_3c & 0x3f) & 1) == 0) {
              local_3c = local_3c + 1;
              if (local_3c == 8) goto LAB_00245689;
              iVar14 = iVar14 + 0x34;
            }
          }
          pcVar3 = *(code **)(param_1 + 0x910);
          uVar7 = nvswitch_get_link_eng_inst(param_1,uVar16,5);
          if (pcVar3 == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if (uVar7 < *(uint *)(lVar12 + 0x5d4)) {
              iVar8 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar7 * 4);
              goto LAB_00244d8d;
            }
LAB_00244da1:
            nvswitch_assert_log();
          }
          else {
            iVar8 = (*pcVar3)(param_1,5,0,(ulong)uVar7);
LAB_00244d8d:
            if ((iVar8 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,uVar16), cVar4 == '\0'))
            goto LAB_00244da1;
          }
          if (*(code **)(param_1 + 0x910) == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            iVar8 = -1;
            if (uVar15 < *(uint *)(lVar12 + 0x5d4)) {
              iVar8 = *(int *)(lVar12 + 0x5d8 + uVar16 * 4);
            }
          }
          else {
            iVar8 = (**(code **)(param_1 + 0x910))(param_1,5,0,uVar16);
          }
          iVar8 = nvswitch_reg_read_32(param_1,iVar8 + 4 + iVar14);
          pcVar3 = *(code **)(param_1 + 0x910);
          uVar7 = nvswitch_get_link_eng_inst(param_1,uVar16,5);
          if (pcVar3 == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if (uVar7 < *(uint *)(lVar12 + 0x5d4)) {
              iVar9 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar7 * 4);
              goto LAB_00244e64;
            }
LAB_00244e78:
            nvswitch_assert_log();
          }
          else {
            iVar9 = (*pcVar3)(param_1,5,0,uVar7);
LAB_00244e64:
            if ((iVar9 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,uVar16), cVar4 == '\0'))
            goto LAB_00244e78;
          }
          if (*(code **)(param_1 + 0x910) == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if (uVar15 < *(uint *)(lVar12 + 0x5d4)) {
              iVar9 = *(int *)(lVar12 + 0x5d8 + uVar16 * 4);
            }
            else {
              iVar9 = -1;
            }
          }
          else {
            iVar9 = (**(code **)(param_1 + 0x910))(param_1,5,0,uVar16);
          }
          nvswitch_reg_read_32(param_1,iVar9 + 8 + iVar14);
          uVar13 = (ulong)local_3c;
          piVar1 = (int *)(uVar13 * 0x518 + uVar16 * 0x14 + *(long *)(&DAT_0000dde0 + lVar2) + 0x2c)
          ;
          *piVar1 = *piVar1 + iVar8;
          pcVar3 = *(code **)(param_1 + 0x910);
          uVar7 = nvswitch_get_link_eng_inst(param_1,uVar16,5);
          if (pcVar3 == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if (uVar7 < *(uint *)(lVar12 + 0x5d4)) {
              iVar9 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar7 * 4);
              goto LAB_00244f72;
            }
LAB_00244f86:
            nvswitch_assert_log();
          }
          else {
            iVar9 = (*pcVar3)(param_1,5,0,uVar7);
LAB_00244f72:
            if ((iVar9 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,uVar16), cVar4 == '\0'))
            goto LAB_00244f86;
          }
          if (*(code **)(param_1 + 0x910) == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            iVar9 = -1;
            if (uVar15 < *(uint *)(lVar12 + 0x5d4)) {
              iVar9 = *(int *)(lVar12 + 0x5d8 + uVar16 * 4);
            }
          }
          else {
            iVar9 = (**(code **)(param_1 + 0x910))(param_1,5,0,uVar16);
          }
          iVar9 = nvswitch_reg_read_32(param_1,iVar9 + 0xc + iVar14);
          pcVar3 = *(code **)(param_1 + 0x910);
          uVar7 = nvswitch_get_link_eng_inst(param_1,uVar16,5);
          if (pcVar3 == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if (uVar7 < *(uint *)(lVar12 + 0x5d4)) {
              iVar10 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar7 * 4);
              goto LAB_0024505c;
            }
LAB_00245070:
            nvswitch_assert_log();
          }
          else {
            iVar10 = (*pcVar3)(param_1,5,0,uVar7);
LAB_0024505c:
            if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,uVar16), cVar4 == '\0'))
            goto LAB_00245070;
          }
          if (*(code **)(param_1 + 0x910) == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            iVar10 = -1;
            if (uVar15 < *(uint *)(lVar12 + 0x5d4)) {
              iVar10 = *(int *)(lVar12 + 0x5d8 + uVar16 * 4);
            }
          }
          else {
            iVar10 = (**(code **)(param_1 + 0x910))(param_1,5,0,uVar16);
          }
          nvswitch_reg_read_32(param_1,iVar10 + 0x10 + iVar14);
          piVar1 = (int *)(uVar13 * 0x518 + uVar16 * 0x14 + *(long *)(&DAT_0000dde0 + lVar2) + 0x30)
          ;
          *piVar1 = *piVar1 + iVar8;
          pcVar3 = *(code **)(param_1 + 0x910);
          uVar7 = nvswitch_get_link_eng_inst(param_1,uVar16,5);
          if (pcVar3 == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if (uVar7 < *(uint *)(lVar12 + 0x5d4)) {
              iVar8 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar7 * 4);
              goto LAB_00245155;
            }
LAB_00245169:
            nvswitch_assert_log();
          }
          else {
            iVar8 = (*pcVar3)(param_1,5,0,uVar7);
LAB_00245155:
            if ((iVar8 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,uVar16), cVar4 == '\0'))
            goto LAB_00245169;
          }
          if (*(code **)(param_1 + 0x910) == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            iVar8 = -1;
            if (uVar15 < *(uint *)(lVar12 + 0x5d4)) {
              iVar8 = *(int *)(lVar12 + 0x5d8 + uVar16 * 4);
            }
          }
          else {
            iVar8 = (**(code **)(param_1 + 0x910))(param_1,5,0,uVar16);
          }
          iVar8 = nvswitch_reg_read_32(param_1,iVar8 + 0x14 + iVar14);
          pcVar3 = *(code **)(param_1 + 0x910);
          uVar7 = nvswitch_get_link_eng_inst(param_1,uVar16,5);
          if (pcVar3 == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if (uVar7 < *(uint *)(lVar12 + 0x5d4)) {
              iVar10 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar7 * 4);
              goto LAB_0024522c;
            }
LAB_00245240:
            nvswitch_assert_log();
          }
          else {
            iVar10 = (*pcVar3)(param_1,5,0,uVar7);
LAB_0024522c:
            if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,uVar16), cVar4 == '\0'))
            goto LAB_00245240;
          }
          if (*(code **)(param_1 + 0x910) == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            iVar10 = -1;
            if (uVar15 < *(uint *)(lVar12 + 0x5d4)) {
              iVar10 = *(int *)(lVar12 + 0x5d8 + uVar16 * 4);
            }
          }
          else {
            iVar10 = (**(code **)(param_1 + 0x910))(param_1,5,0,uVar16);
          }
          nvswitch_reg_read_32(param_1,iVar10 + 0x18 + iVar14);
          piVar1 = (int *)(uVar13 * 0x518 + uVar16 * 0x14 + *(long *)(&DAT_0000dde0 + lVar2) + 0x34)
          ;
          *piVar1 = *piVar1 + iVar9;
          pcVar3 = *(code **)(param_1 + 0x910);
          uVar7 = nvswitch_get_link_eng_inst(param_1,uVar16,5);
          if (pcVar3 == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if (uVar7 < *(uint *)(lVar12 + 0x5d4)) {
              iVar9 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar7 * 4);
              goto LAB_00245321;
            }
LAB_00245335:
            nvswitch_assert_log();
          }
          else {
            iVar9 = (*pcVar3)(param_1,5,0,uVar7);
LAB_00245321:
            if ((iVar9 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,uVar16), cVar4 == '\0'))
            goto LAB_00245335;
          }
          if (*(code **)(param_1 + 0x910) == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            iVar9 = -1;
            if (uVar15 < *(uint *)(lVar12 + 0x5d4)) {
              iVar9 = *(int *)(lVar12 + 0x5d8 + uVar16 * 4);
            }
          }
          else {
            iVar9 = (**(code **)(param_1 + 0x910))(param_1,5,0,uVar16);
          }
          iVar9 = nvswitch_reg_read_32(param_1,iVar9 + 0x1c + iVar14);
          pcVar3 = *(code **)(param_1 + 0x910);
          uVar7 = nvswitch_get_link_eng_inst(param_1,uVar16,5);
          if (pcVar3 == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if (uVar7 < *(uint *)(lVar12 + 0x5d4)) {
              iVar10 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar7 * 4);
              goto LAB_002453f8;
            }
LAB_0024540c:
            nvswitch_assert_log();
          }
          else {
            iVar10 = (*pcVar3)(param_1,5,0,uVar7);
LAB_002453f8:
            if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,uVar16), cVar4 == '\0'))
            goto LAB_0024540c;
          }
          if (*(code **)(param_1 + 0x910) == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            iVar10 = -1;
            if (uVar15 < *(uint *)(lVar12 + 0x5d4)) {
              iVar10 = *(int *)(lVar12 + 0x5d8 + uVar16 * 4);
            }
          }
          else {
            iVar10 = (**(code **)(param_1 + 0x910))(param_1,5,0,uVar16);
          }
          nvswitch_reg_read_32(param_1,iVar10 + 0x20 + iVar14);
          piVar1 = (int *)(uVar13 * 0x518 + uVar16 * 0x14 + *(long *)(&DAT_0000dde0 + lVar2) + 0x38)
          ;
          *piVar1 = *piVar1 + iVar8;
          pcVar3 = *(code **)(param_1 + 0x910);
          uVar7 = nvswitch_get_link_eng_inst(param_1,uVar16,5);
          if (pcVar3 == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if (uVar7 < *(uint *)(lVar12 + 0x5d4)) {
              iVar8 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar7 * 4);
              goto LAB_002454ed;
            }
LAB_00245501:
            nvswitch_assert_log();
          }
          else {
            iVar8 = (*pcVar3)(param_1,5,0,uVar7);
LAB_002454ed:
            if ((iVar8 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,uVar16), cVar4 == '\0'))
            goto LAB_00245501;
          }
          if (*(code **)(param_1 + 0x910) == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            iVar8 = -1;
            if (uVar15 < *(uint *)(lVar12 + 0x5d4)) {
              iVar8 = *(int *)(lVar12 + 0x5d8 + uVar16 * 4);
            }
          }
          else {
            iVar8 = (**(code **)(param_1 + 0x910))(param_1,5,0,uVar16);
          }
          nvswitch_reg_read_32(param_1,iVar8 + -4 + iVar14);
          pcVar3 = *(code **)(param_1 + 0x910);
          uVar7 = nvswitch_get_link_eng_inst(param_1,uVar16,5);
          if (pcVar3 == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            if (uVar7 < *(uint *)(lVar12 + 0x5d4)) {
              iVar8 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar7 * 4);
              goto LAB_002455c1;
            }
LAB_002455d5:
            nvswitch_assert_log();
          }
          else {
            iVar8 = (*pcVar3)(param_1,5,0,uVar7);
LAB_002455c1:
            if ((iVar8 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,uVar16), cVar4 == '\0'))
            goto LAB_002455d5;
          }
          if (*(code **)(param_1 + 0x910) == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            lVar12 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar12 + 0x5d0) != 5) {
              nvswitch_assert_log();
            }
            iVar8 = -1;
            if (uVar15 < *(uint *)(lVar12 + 0x5d4)) {
              iVar8 = *(int *)(lVar12 + 0x5d8 + uVar16 * 4);
            }
          }
          else {
            iVar8 = (**(code **)(param_1 + 0x910))(param_1,5,0,uVar16);
          }
          iVar8 = iVar8 + iVar14;
          iVar14 = iVar14 + 0x34;
          nvswitch_reg_read_32(param_1,iVar8);
          lVar12 = uVar13 * 0x518;
          local_3c = local_3c + 1;
          piVar1 = (int *)(lVar12 + uVar16 * 0x14 + *(long *)(&DAT_0000dde0 + lVar2) + 0x28);
          *piVar1 = *piVar1 + iVar9;
          *(long *)(*(long *)(&DAT_0000dde0 + lVar2) + lVar12 + 0x20) = lVar11;
          piVar1 = (int *)(lVar12 + *(long *)(&DAT_0000dde0 + lVar2) + 0x10);
          *piVar1 = *piVar1 + 1;
        } while (local_3c != 8);
LAB_00245689:
        pcVar3 = *(code **)(param_1 + 0x910);
        uVar5 = nvswitch_get_link_eng_inst(param_1,uVar16,5);
        if (pcVar3 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)invalidInstructionException();
            (*pcVar3)();
          }
          lVar12 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar12 + 0x5d0) == 5) {
            uVar7 = *(uint *)(lVar12 + 0x5d4);
          }
          else {
            nvswitch_assert_log();
            uVar7 = *(uint *)(lVar12 + 0x5d4);
          }
          if (uVar5 < uVar7) {
            iVar14 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar5 * 4);
            goto LAB_002456e5;
          }
LAB_002456f9:
          nvswitch_assert_log();
        }
        else {
          iVar14 = (*pcVar3)(param_1,5,0,(ulong)uVar5);
LAB_002456e5:
          if ((iVar14 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,uVar16), cVar4 == '\0'))
          goto LAB_002456f9;
        }
        pcVar3 = *(code **)(param_1 + 0x928);
        uVar6 = nvswitch_get_link_eng_inst(param_1,uVar16,5);
        (*pcVar3)(param_1,5,0,uVar6,0x104,1);
      }
    }
    uVar16 = (ulong)(uVar15 + 1);
  } while( true );
}


// ===== 00245be1 nvswitch_ctrl_get_counters_ls10.cold =====

void nvswitch_ctrl_get_counters_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00245c80 nvswitch_ctrl_get_counters_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_r15 replaced with injection: x86_indirect_thunk_r15 */

undefined8 nvswitch_ctrl_get_counters_ls10(long param_1,undefined1 *param_2)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  bool bVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  long lVar12;
  ulong uVar13;
  undefined8 uVar14;
  int iVar15;
  bool bVar16;
  ulong local_60;
  ulong local_58;
  ulong local_50;
  uint local_3c [3];
  
  lVar12 = nvswitch_get_link(param_1,*param_2);
  if (lVar12 == 0) {
    return 0xffffffff;
  }
  pcVar2 = *(code **)(param_1 + 0x910);
  uVar8 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar12 + 0x38),0xb);
  if (pcVar2 == nvswitch_get_eng_base_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    lVar3 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar3 + 0xcc0) == 0xb) {
      uVar10 = *(uint *)(lVar3 + 0xcc4);
    }
    else {
      nvswitch_assert_log();
      uVar10 = *(uint *)(lVar3 + 0xcc4);
    }
    if (uVar10 <= uVar8) {
      return 0xffffffff;
    }
    iVar11 = *(int *)(lVar3 + 0xcc8 + (ulong)uVar8 * 4);
  }
  else {
    iVar11 = (*pcVar2)(param_1,0xb,0,(ulong)uVar8);
  }
  if (iVar11 == -1) {
    return 0xffffffff;
  }
  cVar5 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar12 + 0x38));
  if (cVar5 == '\0') {
    return 0xffffffff;
  }
  uVar9 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar12 + 0x38),7);
  cVar5 = nvswitch_is_minion_initialized(param_1,uVar9);
  uVar8 = *(uint *)(param_2 + 4);
  if ((uVar8 & 0xf) != 0) {
    pcVar2 = *(code **)(param_1 + 0x910);
    uVar10 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar12 + 0x38),10);
    if (pcVar2 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar3 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar3 + 0xb98) == 10) {
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      else {
        nvswitch_assert_log();
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      if (uVar10 < uVar1) {
        iVar11 = *(int *)(lVar3 + 0xba0 + (ulong)uVar10 * 4);
        goto LAB_00246929;
      }
LAB_0024611b:
      nvswitch_assert_log();
    }
    else {
      iVar11 = (*pcVar2)(param_1,10,0,uVar10);
LAB_00246929:
      if ((iVar11 == -1) ||
         (cVar6 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar12 + 0x38)), cVar6 == '\0'))
      goto LAB_0024611b;
    }
    pcVar2 = *(code **)(param_1 + 0x910);
    uVar10 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar12 + 0x38),10);
    if (pcVar2 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar3 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar3 + 0xb98) == 10) {
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      else {
        nvswitch_assert_log();
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      iVar11 = 0x154f;
      if (uVar10 < uVar1) {
        iVar11 = *(int *)(lVar3 + 0xba0 + (ulong)uVar10 * 4) + 0x1550;
      }
    }
    else {
      iVar11 = (*pcVar2)(param_1,10,0,uVar10);
      iVar11 = iVar11 + 0x1550;
    }
    pcVar2 = *(code **)(param_1 + 0x910);
    uVar10 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar12 + 0x38),10);
    if (pcVar2 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar3 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar3 + 0xb98) == 10) {
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      else {
        nvswitch_assert_log();
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      if (uVar10 < uVar1) {
        iVar15 = *(int *)(lVar3 + 0xba0 + (ulong)uVar10 * 4);
        goto LAB_002468e1;
      }
LAB_002461eb:
      nvswitch_assert_log();
    }
    else {
      iVar15 = (*pcVar2)(param_1,10,0,uVar10);
LAB_002468e1:
      if ((iVar15 == -1) ||
         (cVar6 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar12 + 0x38)), cVar6 == '\0'))
      goto LAB_002461eb;
    }
    pcVar2 = *(code **)(param_1 + 0x910);
    uVar10 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar12 + 0x38),10);
    if (pcVar2 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar3 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar3 + 0xb98) == 10) {
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      else {
        nvswitch_assert_log();
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      iVar15 = 0x154b;
      if (uVar10 < uVar1) {
        iVar15 = *(int *)(lVar3 + 0xba0 + (ulong)uVar10 * 4) + 0x154c;
      }
    }
    else {
      iVar15 = (*pcVar2)(param_1,10,0,uVar10);
      iVar15 = iVar15 + 0x154c;
    }
    local_50 = nvswitch_read_64bit_counter(param_1,iVar15,iVar11);
    if ((long)local_50 < 0) {
      local_50 = local_50 & 0x7fffffffffffffff;
      param_2[8] = 1;
    }
    pcVar2 = *(code **)(param_1 + 0x910);
    uVar10 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar12 + 0x38),10);
    if (pcVar2 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar3 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar3 + 0xb98) == 10) {
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      else {
        nvswitch_assert_log();
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      if (uVar10 < uVar1) {
        iVar11 = *(int *)(lVar3 + 0xba0 + (ulong)uVar10 * 4);
        goto LAB_002469a9;
      }
LAB_002462ce:
      nvswitch_assert_log();
    }
    else {
      iVar11 = (*pcVar2)(param_1,10,0,uVar10);
LAB_002469a9:
      if ((iVar11 == -1) ||
         (cVar6 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar12 + 0x38)), cVar6 == '\0'))
      goto LAB_002462ce;
    }
    pcVar2 = *(code **)(param_1 + 0x910);
    uVar10 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar12 + 0x38),10);
    if (pcVar2 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar3 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar3 + 0xb98) == 10) {
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      else {
        nvswitch_assert_log();
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      iVar11 = 0x15a3;
      if (uVar10 < uVar1) {
        iVar11 = *(int *)(lVar3 + 0xba0 + (ulong)uVar10 * 4) + 0x15a4;
      }
    }
    else {
      iVar11 = (*pcVar2)(param_1,10,0,uVar10);
      iVar11 = iVar11 + 0x15a4;
    }
    pcVar2 = *(code **)(param_1 + 0x910);
    uVar10 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar12 + 0x38),10);
    if (pcVar2 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar3 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar3 + 0xb98) == 10) {
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      else {
        nvswitch_assert_log();
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      if (uVar10 < uVar1) {
        iVar15 = *(int *)(lVar3 + 0xba0 + (ulong)uVar10 * 4);
        goto LAB_00246959;
      }
LAB_0024639b:
      nvswitch_assert_log();
    }
    else {
      iVar15 = (*pcVar2)(param_1,10,0,uVar10);
LAB_00246959:
      if ((iVar15 == -1) ||
         (cVar6 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar12 + 0x38)), cVar6 == '\0'))
      goto LAB_0024639b;
    }
    pcVar2 = *(code **)(param_1 + 0x910);
    uVar10 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar12 + 0x38),10);
    if (pcVar2 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar3 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar3 + 0xb98) == 10) {
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      else {
        nvswitch_assert_log();
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      iVar15 = 0x159f;
      if (uVar10 < uVar1) {
        iVar15 = *(int *)(lVar3 + 0xba0 + (ulong)uVar10 * 4) + 0x15a0;
      }
    }
    else {
      iVar15 = (*pcVar2)(param_1,10,0,uVar10);
      iVar15 = iVar15 + 0x15a0;
    }
    local_58 = nvswitch_read_64bit_counter(param_1,iVar15,iVar11);
    if ((long)local_58 < 0) {
      local_58 = local_58 & 0x7fffffffffffffff;
      param_2[9] = 1;
    }
    pcVar2 = *(code **)(param_1 + 0x910);
    uVar10 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar12 + 0x38),10);
    if (pcVar2 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar3 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar3 + 0xb98) == 10) {
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      else {
        nvswitch_assert_log();
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      if (uVar10 < uVar1) {
        iVar11 = *(int *)(lVar3 + 0xba0 + (ulong)uVar10 * 4);
        goto LAB_00246881;
      }
LAB_0024647e:
      nvswitch_assert_log();
    }
    else {
      iVar11 = (*pcVar2)(param_1,10,0,uVar10);
LAB_00246881:
      if ((iVar11 == -1) ||
         (cVar6 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar12 + 0x38)), cVar6 == '\0'))
      goto LAB_0024647e;
    }
    pcVar2 = *(code **)(param_1 + 0x910);
    uVar10 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar12 + 0x38),10);
    if (pcVar2 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar3 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar3 + 0xb98) == 10) {
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      else {
        nvswitch_assert_log();
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      iVar11 = 0x1d4f;
      if (uVar10 < uVar1) {
        iVar11 = *(int *)(lVar3 + 0xba0 + (ulong)uVar10 * 4) + 0x1d50;
      }
    }
    else {
      iVar11 = (*pcVar2)(param_1,10,0,uVar10);
      iVar11 = iVar11 + 0x1d50;
    }
    pcVar2 = *(code **)(param_1 + 0x910);
    uVar10 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar12 + 0x38),10);
    if (pcVar2 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar3 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar3 + 0xb98) == 10) {
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      else {
        nvswitch_assert_log();
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      if (uVar10 < uVar1) {
        iVar15 = *(int *)(lVar3 + 0xba0 + (ulong)uVar10 * 4);
        goto LAB_002469d9;
      }
LAB_0024654b:
      nvswitch_assert_log();
    }
    else {
      iVar15 = (*pcVar2)(param_1,10,0,uVar10);
LAB_002469d9:
      if ((iVar15 == -1) ||
         (cVar6 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar12 + 0x38)), cVar6 == '\0'))
      goto LAB_0024654b;
    }
    pcVar2 = *(code **)(param_1 + 0x910);
    uVar10 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar12 + 0x38),10);
    if (pcVar2 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar3 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar3 + 0xb98) == 10) {
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      else {
        nvswitch_assert_log();
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      iVar15 = 0x1d4b;
      if (uVar10 < uVar1) {
        iVar15 = *(int *)(lVar3 + 0xba0 + (ulong)uVar10 * 4) + 0x1d4c;
      }
    }
    else {
      iVar15 = (*pcVar2)(param_1,10,0,uVar10);
      iVar15 = iVar15 + 0x1d4c;
    }
    local_60 = nvswitch_read_64bit_counter(param_1,iVar15,iVar11);
    if ((long)local_60 < 0) {
      local_60 = local_60 & 0x7fffffffffffffff;
      param_2[10] = 1;
    }
    pcVar2 = *(code **)(param_1 + 0x910);
    uVar10 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar12 + 0x38),10);
    if (pcVar2 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar3 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar3 + 0xb98) == 10) {
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      else {
        nvswitch_assert_log();
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      if (uVar10 < uVar1) {
        iVar11 = *(int *)(lVar3 + 0xba0 + (ulong)uVar10 * 4);
        goto LAB_002468b1;
      }
LAB_0024662e:
      nvswitch_assert_log();
    }
    else {
      iVar11 = (*pcVar2)(param_1,10,0,uVar10);
LAB_002468b1:
      if ((iVar11 == -1) ||
         (cVar6 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar12 + 0x38)), cVar6 == '\0'))
      goto LAB_0024662e;
    }
    pcVar2 = *(code **)(param_1 + 0x910);
    uVar10 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar12 + 0x38),10);
    if (pcVar2 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar3 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar3 + 0xb98) == 10) {
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      else {
        nvswitch_assert_log();
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      iVar11 = 0x1da3;
      if (uVar10 < uVar1) {
        iVar11 = *(int *)(lVar3 + 0xba0 + (ulong)uVar10 * 4) + 0x1da4;
      }
    }
    else {
      iVar11 = (*pcVar2)(param_1,10,0,uVar10);
      iVar11 = iVar11 + 0x1da4;
    }
    pcVar2 = *(code **)(param_1 + 0x910);
    uVar10 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar12 + 0x38),10);
    if (pcVar2 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar3 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar3 + 0xb98) == 10) {
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      else {
        nvswitch_assert_log();
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      if (uVar10 < uVar1) {
        iVar15 = *(int *)(lVar3 + 0xba0 + (ulong)uVar10 * 4);
        goto LAB_00246a29;
      }
LAB_002466fb:
      nvswitch_assert_log();
    }
    else {
      iVar15 = (*pcVar2)(param_1,10,0,uVar10);
LAB_00246a29:
      if ((iVar15 == -1) ||
         (cVar6 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar12 + 0x38)), cVar6 == '\0'))
      goto LAB_002466fb;
    }
    pcVar2 = *(code **)(param_1 + 0x910);
    uVar10 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar12 + 0x38),10);
    if (pcVar2 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar3 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar3 + 0xb98) == 10) {
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      else {
        nvswitch_assert_log();
        uVar1 = *(uint *)(lVar3 + 0xb9c);
      }
      iVar15 = 0x1d9f;
      if (uVar10 < uVar1) {
        iVar15 = *(int *)(lVar3 + 0xba0 + (ulong)uVar10 * 4) + 0x1da0;
      }
    }
    else {
      iVar15 = (*pcVar2)(param_1,10,0,uVar10);
      iVar15 = iVar15 + 0x1da0;
    }
    uVar13 = nvswitch_read_64bit_counter(param_1,iVar15,iVar11);
    if ((long)uVar13 < 0) {
      param_2[0xb] = 1;
      uVar13 = uVar13 & 0x7fffffffffffffff;
    }
    *(ulong *)(param_2 + 0x28) = uVar13;
    *(ulong *)(param_2 + 0x10) = local_50;
    *(ulong *)(param_2 + 0x18) = local_58;
    *(ulong *)(param_2 + 0x20) = local_60;
  }
  if ((uVar8 & 0x10000) == 0) {
    if ((uVar8 & 0x10000000) != 0) {
      if (cVar5 == '\0') {
LAB_00245d8d:
        uVar13 = 0;
      }
      else {
LAB_00245fc6:
        cVar6 = nvswitch_is_tnvl_mode_locked(param_1);
        if (cVar6 != '\0') {
          return 0xfffffff1;
        }
        uVar14 = nvswitch_minion_get_dl_status
                           (param_1,*(undefined4 *)(lVar12 + 0x38),0x42,0,local_3c);
        if ((int)uVar14 != 0) {
          return uVar14;
        }
        uVar13 = (ulong)(local_3c[0] & 0x7fffffff);
      }
      *(ulong *)(param_2 + 0xf0) = uVar13;
    }
  }
  else if (cVar5 == '\0') {
    *(undefined8 *)(param_2 + 0x90) = 0;
    if ((uVar8 & 0x10000000) != 0) goto LAB_00245d8d;
  }
  else {
    cVar6 = nvswitch_is_tnvl_mode_locked(param_1);
    if (cVar6 != '\0') {
      return 0xfffffff1;
    }
    uVar14 = nvswitch_minion_get_dl_status(param_1,*(undefined4 *)(lVar12 + 0x38),0x41,0,local_3c);
    if ((int)uVar14 != 0) {
      return uVar14;
    }
    local_3c[0] = local_3c[0] & 0x7fffffff;
    *(ulong *)(param_2 + 0x90) = (ulong)local_3c[0];
    if ((uVar8 & 0x10000000) != 0) goto LAB_00245fc6;
  }
  local_3c[0] = 0;
  cVar6 = nvswitch_link_lane_reversed_lr10(param_1,*(undefined4 *)(lVar12 + 0x38));
  bVar4 = false;
LAB_00245db0:
  bVar16 = (bool)(bVar4 ^ 1);
  if (cVar6 == '\0') {
    bVar16 = bVar4;
  }
  if (cVar5 == '\0') {
    local_3c[0] = 0;
  }
  else {
    cVar7 = nvswitch_is_tnvl_mode_locked(param_1);
    if (cVar7 != '\0') {
      return 0xfffffff1;
    }
    uVar14 = nvswitch_minion_get_dl_status(param_1,*(undefined4 *)(lVar12 + 0x38),0x81,0,local_3c);
    if ((int)uVar14 != 0) {
      return uVar14;
    }
  }
  if ((1 << (bVar4 + 0x11U & 0x1f) & uVar8) == 0) {
    if (bVar4) goto LAB_00245e03;
LAB_00245f2a:
    bVar4 = true;
    goto LAB_00245db0;
  }
  uVar10 = local_3c[0] >> 8;
  if (!bVar16) {
    uVar10 = local_3c[0];
  }
  if (!bVar4) {
    *(ulong *)(param_2 + 0x98) = (ulong)(uVar10 & 0xff);
    goto LAB_00245f2a;
  }
  *(ulong *)(param_2 + 0xa0) = (ulong)(uVar10 & 0xff);
LAB_00245e03:
  if ((uVar8 & 0x2000000) == 0) {
    if ((uVar8 & 0x4000000) != 0) {
      if (cVar5 == '\0') goto LAB_00245e98;
LAB_002467a9:
      cVar6 = nvswitch_is_tnvl_mode_locked(param_1);
      if (cVar6 != '\0') {
        return 0xfffffff1;
      }
      uVar14 = nvswitch_minion_get_dl_status(param_1,*(undefined4 *)(lVar12 + 0x38),0x11,0,local_3c)
      ;
      if ((int)uVar14 != 0) {
        return uVar14;
      }
      local_3c[0] = local_3c[0] & 0x7fffffff;
      *(ulong *)(param_2 + 0xe0) = (ulong)local_3c[0];
      goto joined_r0x002467f5;
    }
    if ((uVar8 & 0x8000000) != 0) {
      if (cVar5 == '\0') goto LAB_00245ef8;
      goto LAB_0024601f;
    }
LAB_00246061:
    uVar10 = uVar8 & 0x40000000;
    if ((uVar8 & 0x40000000) == 0) {
      if (-1 < (int)uVar8) {
        return 0;
      }
      if (cVar5 == '\0') {
LAB_00246090:
        uVar13 = 0;
        goto LAB_00246092;
      }
    }
    else {
      if (cVar5 == '\0') {
LAB_00245f10:
        uVar13 = 0;
        local_3c[0] = 0;
        goto LAB_00245eb8;
      }
LAB_00246d39:
      uVar10 = 0x40000000;
    }
LAB_00246d40:
    cVar5 = nvswitch_is_tnvl_mode_locked(param_1);
    if (cVar5 != '\0') {
      return 0xfffffff1;
    }
    uVar14 = nvswitch_minion_get_dl_status(param_1,*(undefined4 *)(lVar12 + 0x38),0x8b,0,local_3c);
    if ((int)uVar14 != 0) {
      return uVar14;
    }
    if (uVar10 != 0) {
      uVar13 = (ulong)(ushort)local_3c[0];
      goto LAB_00245eb8;
    }
  }
  else {
    if (cVar5 != '\0') {
      cVar6 = nvswitch_is_tnvl_mode_locked(param_1);
      if (cVar6 != '\0') {
        return 0xfffffff1;
      }
      uVar14 = nvswitch_minion_get_dl_status(param_1,*(undefined4 *)(lVar12 + 0x38),0x29,0,local_3c)
      ;
      if ((int)uVar14 != 0) {
        return uVar14;
      }
      local_3c[0] = local_3c[0] & 0x7fffffff;
      *(ulong *)(param_2 + 0xd8) = (ulong)local_3c[0];
      if ((uVar8 & 0x4000000) != 0) goto LAB_002467a9;
joined_r0x002467f5:
      if ((uVar8 & 0x8000000) != 0) {
LAB_0024601f:
        cVar6 = nvswitch_is_tnvl_mode_locked(param_1);
        if (cVar6 != '\0') {
          return 0xfffffff1;
        }
        uVar14 = nvswitch_minion_get_dl_status
                           (param_1,*(undefined4 *)(lVar12 + 0x38),0x40,0,local_3c);
        if ((int)uVar14 != 0) {
          return uVar14;
        }
        local_3c[0] = local_3c[0] & 0x7fffffff;
        *(ulong *)(param_2 + 0xe8) = (ulong)local_3c[0];
        goto LAB_00246061;
      }
      uVar10 = uVar8 & 0x40000000;
      if ((uVar8 & 0x40000000) != 0) goto LAB_00246d39;
      if (-1 < (int)uVar8) {
        return uVar14;
      }
      goto LAB_00246d40;
    }
    *(undefined8 *)(param_2 + 0xd8) = 0;
    if ((uVar8 & 0x4000000) == 0) {
      if ((uVar8 & 0x8000000) == 0) {
        uVar13 = 0;
        local_3c[0] = 0;
        if ((uVar8 & 0x40000000) != 0) goto LAB_00245eb8;
      }
      else {
LAB_00245ef8:
        *(undefined8 *)(param_2 + 0xe8) = 0;
        if ((uVar8 & 0x40000000) != 0) goto LAB_00245f10;
      }
LAB_00245e50:
      if (-1 < (int)uVar8) {
        return 0;
      }
      goto LAB_00246090;
    }
LAB_00245e98:
    *(undefined8 *)(param_2 + 0xe0) = 0;
    if ((uVar8 & 0x8000000) != 0) goto LAB_00245ef8;
    if ((uVar8 & 0x40000000) == 0) goto LAB_00245e50;
    uVar13 = 0;
    local_3c[0] = 0;
LAB_00245eb8:
    *(ulong *)(param_2 + 0x100) = uVar13;
    if (-1 < (int)uVar8) {
      return 0;
    }
  }
  uVar13 = (ulong)(local_3c[0] >> 0x10);
LAB_00246092:
  *(ulong *)(param_2 + 0x108) = uVar13;
  return 0;
}


// ===== 00247098 nvswitch_ctrl_clear_counters_ls10.cold =====

void nvswitch_ctrl_clear_counters_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00247110 nvswitch_ctrl_clear_counters_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r15 replaced with injection: x86_indirect_thunk_r15 */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

undefined8 nvswitch_ctrl_clear_counters_ls10(long param_1,ulong *param_2)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  char cVar4;
  char cVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  long lVar10;
  undefined8 uVar11;
  ulong uVar12;
  uint uVar13;
  
  cVar4 = nvswitch_is_tnvl_mode_locked();
  if (cVar4 == '\0') {
    cVar4 = '\0';
    uVar12 = *param_2;
    if (uVar12 != 0) {
      do {
        for (; (uVar12 & 1) == 0; uVar12 = uVar12 >> 1) {
          cVar4 = cVar4 + '\x01';
        }
        lVar10 = nvswitch_get_link(param_1,cVar4);
        if (lVar10 != 0) {
          uVar13 = (uint)param_2[1];
          if (0x3fffffff < uVar13) {
            uVar13 = uVar13 & 0x3fffffff;
            nvswitch_minion_send_command(param_1,*(undefined4 *)(lVar10 + 0x38),0x73,0);
          }
          pcVar2 = *(code **)(param_1 + 0x910);
          uVar6 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),10);
          if (pcVar2 == nvswitch_get_eng_base_ls10) {
            if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)invalidInstructionException();
              (*pcVar2)();
            }
            lVar3 = *(long *)(param_1 + 0x1f90);
            if (*(int *)(lVar3 + 0xb98) != 10) {
              nvswitch_assert_log();
            }
            if (uVar6 < *(uint *)(lVar3 + 0xb9c)) {
              iVar9 = *(int *)(lVar3 + 0xba0 + (ulong)uVar6 * 4);
              goto LAB_0024721d;
            }
LAB_00247239:
            if ((uVar13 & 0x10) != 0) goto LAB_002478e0;
            if (uVar13 == 0) goto joined_r0x0024724f;
          }
          else {
            iVar9 = (*pcVar2)(param_1,10,0);
LAB_0024721d:
            if (((iVar9 == -1) ||
                (cVar5 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar10 + 0x38)),
                cVar5 == '\0')) || ((uVar13 & 0xf) == 0)) goto LAB_00247239;
            pcVar2 = *(code **)(param_1 + 0x910);
            uVar6 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),10);
            if (pcVar2 == nvswitch_get_eng_base_ls10) {
              if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)invalidInstructionException();
                (*pcVar2)();
              }
              lVar3 = *(long *)(param_1 + 0x1f90);
              if (*(int *)(lVar3 + 0xb98) != 10) {
                nvswitch_assert_log();
              }
              if (uVar6 < *(uint *)(lVar3 + 0xb9c)) {
                iVar9 = *(int *)(lVar3 + 0xba0 + (ulong)uVar6 * 4);
                goto LAB_00247a49;
              }
LAB_002472da:
              nvswitch_assert_log();
            }
            else {
              iVar9 = (*pcVar2)(param_1,10,0,uVar6);
LAB_00247a49:
              if ((iVar9 == -1) ||
                 (cVar5 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar10 + 0x38)),
                 cVar5 == '\0')) goto LAB_002472da;
            }
            pcVar2 = *(code **)(param_1 + 0x920);
            uVar7 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),10);
            if (pcVar2 == nvswitch_eng_rd_ls10) {
              uVar6 = nvswitch_eng_rd_ls10();
            }
            else {
              uVar6 = (*pcVar2)(param_1,10,0,uVar7,0x150c);
            }
            pcVar2 = *(code **)(param_1 + 0x910);
            uVar8 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),10);
            if (pcVar2 == nvswitch_get_eng_base_ls10) {
              if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)invalidInstructionException();
                (*pcVar2)();
              }
              lVar3 = *(long *)(param_1 + 0x1f90);
              if (*(int *)(lVar3 + 0xb98) != 10) {
                nvswitch_assert_log();
              }
              if (uVar8 < *(uint *)(lVar3 + 0xb9c)) {
                iVar9 = *(int *)(lVar3 + 0xba0 + (ulong)uVar8 * 4);
                goto LAB_00247396;
              }
LAB_002473ac:
              nvswitch_assert_log();
            }
            else {
              iVar9 = (*pcVar2)(param_1,10,0,uVar8);
LAB_00247396:
              if ((iVar9 == -1) ||
                 (cVar5 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar10 + 0x38)),
                 cVar5 == '\0')) goto LAB_002473ac;
            }
            pcVar2 = *(code **)(param_1 + 0x928);
            uVar7 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),10);
            (*pcVar2)(param_1,10,0,uVar7,0x150c,uVar6 | 0x2000000);
            pcVar2 = *(code **)(param_1 + 0x910);
            uVar6 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),10);
            if (pcVar2 == nvswitch_get_eng_base_ls10) {
              if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)invalidInstructionException();
                (*pcVar2)();
              }
              lVar3 = *(long *)(param_1 + 0x1f90);
              if (*(int *)(lVar3 + 0xb98) != 10) {
                nvswitch_assert_log();
              }
              if (uVar6 < *(uint *)(lVar3 + 0xb9c)) {
                iVar9 = *(int *)(lVar3 + 0xba0 + (ulong)uVar6 * 4);
                goto LAB_00247463;
              }
LAB_00247479:
              nvswitch_assert_log();
            }
            else {
              iVar9 = (*pcVar2)(param_1,10,0,uVar6);
LAB_00247463:
              if ((iVar9 == -1) ||
                 (cVar5 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar10 + 0x38)),
                 cVar5 == '\0')) goto LAB_00247479;
            }
            pcVar2 = *(code **)(param_1 + 0x920);
            uVar7 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),10);
            if (pcVar2 == nvswitch_eng_rd_ls10) {
              uVar6 = nvswitch_eng_rd_ls10();
            }
            else {
              uVar6 = (*pcVar2)(param_1,10,0,uVar7,0x1560);
            }
            pcVar2 = *(code **)(param_1 + 0x910);
            uVar8 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),10);
            if (pcVar2 == nvswitch_get_eng_base_ls10) {
              if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)invalidInstructionException();
                (*pcVar2)();
              }
              lVar3 = *(long *)(param_1 + 0x1f90);
              if (*(int *)(lVar3 + 0xb98) != 10) {
                nvswitch_assert_log();
              }
              if (uVar8 < *(uint *)(lVar3 + 0xb9c)) {
                iVar9 = *(int *)(lVar3 + 0xba0 + (ulong)uVar8 * 4);
                goto LAB_00247535;
              }
LAB_0024754b:
              nvswitch_assert_log();
            }
            else {
              iVar9 = (*pcVar2)(param_1,10,0,uVar8);
LAB_00247535:
              if ((iVar9 == -1) ||
                 (cVar5 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar10 + 0x38)),
                 cVar5 == '\0')) goto LAB_0024754b;
            }
            pcVar2 = *(code **)(param_1 + 0x928);
            uVar7 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),10);
            (*pcVar2)(param_1,10,0,uVar7,0x1560,uVar6 | 0x2000000);
            pcVar2 = *(code **)(param_1 + 0x910);
            uVar6 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),10);
            if (pcVar2 == nvswitch_get_eng_base_ls10) {
              if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)invalidInstructionException();
                (*pcVar2)();
              }
              lVar3 = *(long *)(param_1 + 0x1f90);
              if (*(int *)(lVar3 + 0xb98) != 10) {
                nvswitch_assert_log();
              }
              if (uVar6 < *(uint *)(lVar3 + 0xb9c)) {
                iVar9 = *(int *)(lVar3 + 0xba0 + (ulong)uVar6 * 4);
                goto LAB_00247602;
              }
LAB_00247618:
              nvswitch_assert_log();
            }
            else {
              iVar9 = (*pcVar2)(param_1,10,0,uVar6);
LAB_00247602:
              if ((iVar9 == -1) ||
                 (cVar5 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar10 + 0x38)),
                 cVar5 == '\0')) goto LAB_00247618;
            }
            pcVar2 = *(code **)(param_1 + 0x920);
            uVar7 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),10);
            if (pcVar2 == nvswitch_eng_rd_ls10) {
              uVar6 = nvswitch_eng_rd_ls10();
            }
            else {
              uVar6 = (*pcVar2)(param_1,10,0,uVar7,0x1d0c);
            }
            pcVar2 = *(code **)(param_1 + 0x910);
            uVar8 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),10);
            if (pcVar2 == nvswitch_get_eng_base_ls10) {
              if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)invalidInstructionException();
                (*pcVar2)();
              }
              lVar3 = *(long *)(param_1 + 0x1f90);
              if (*(int *)(lVar3 + 0xb98) != 10) {
                nvswitch_assert_log();
              }
              if (uVar8 < *(uint *)(lVar3 + 0xb9c)) {
                iVar9 = *(int *)(lVar3 + 0xba0 + (ulong)uVar8 * 4);
                goto LAB_002476d4;
              }
LAB_002476ea:
              nvswitch_assert_log();
            }
            else {
              iVar9 = (*pcVar2)(param_1,10,0,uVar8);
LAB_002476d4:
              if ((iVar9 == -1) ||
                 (cVar5 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar10 + 0x38)),
                 cVar5 == '\0')) goto LAB_002476ea;
            }
            pcVar2 = *(code **)(param_1 + 0x928);
            uVar7 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),10);
            (*pcVar2)(param_1,10,0,uVar7,0x1d0c,uVar6 | 0x2000000);
            pcVar2 = *(code **)(param_1 + 0x910);
            uVar6 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),10);
            if (pcVar2 == nvswitch_get_eng_base_ls10) {
              if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)invalidInstructionException();
                (*pcVar2)();
              }
              lVar3 = *(long *)(param_1 + 0x1f90);
              if (*(int *)(lVar3 + 0xb98) != 10) {
                nvswitch_assert_log();
              }
              if (uVar6 < *(uint *)(lVar3 + 0xb9c)) {
                iVar9 = *(int *)(lVar3 + 0xba0 + (ulong)uVar6 * 4);
                goto LAB_002477a1;
              }
LAB_002477b7:
              nvswitch_assert_log();
            }
            else {
              iVar9 = (*pcVar2)(param_1,10,0,uVar6);
LAB_002477a1:
              if ((iVar9 == -1) ||
                 (cVar5 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar10 + 0x38)),
                 cVar5 == '\0')) goto LAB_002477b7;
            }
            pcVar2 = *(code **)(param_1 + 0x920);
            uVar7 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),10);
            if (pcVar2 == nvswitch_eng_rd_ls10) {
              uVar6 = nvswitch_eng_rd_ls10();
            }
            else {
              uVar6 = (*pcVar2)(param_1,10,0,uVar7,0x1d60);
            }
            pcVar2 = *(code **)(param_1 + 0x910);
            uVar8 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),10);
            if (pcVar2 == nvswitch_get_eng_base_ls10) {
              if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)invalidInstructionException();
                (*pcVar2)();
              }
              lVar3 = *(long *)(param_1 + 0x1f90);
              if (*(int *)(lVar3 + 0xb98) != 10) {
                nvswitch_assert_log();
              }
              if (uVar8 < *(uint *)(lVar3 + 0xb9c)) {
                iVar9 = *(int *)(lVar3 + 0xba0 + (ulong)uVar8 * 4);
                goto LAB_00247873;
              }
LAB_00247889:
              nvswitch_assert_log();
            }
            else {
              iVar9 = (*pcVar2)(param_1,10,0,uVar8);
LAB_00247873:
              if ((iVar9 == -1) ||
                 (cVar5 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar10 + 0x38)),
                 cVar5 == '\0')) goto LAB_00247889;
            }
            pcVar2 = *(code **)(param_1 + 0x928);
            uVar7 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),10);
            (*pcVar2)(param_1,10,0,uVar7,0x1d60,uVar6 | 0x2000000);
            if ((uVar13 & 0x10) == 0) goto LAB_002478f4;
LAB_002478e0:
            nvswitch_minion_send_command(param_1,*(undefined4 *)(lVar10 + 0x38),0x71,0);
          }
LAB_002478f4:
          if ((uVar13 & 0x27fe0000) != 0) {
            uVar7 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),7);
            cVar5 = nvswitch_is_minion_initialized(param_1,uVar7);
            if (cVar5 == '\0') {
              if ((uVar13 & 0x17ff0000) != 0) {
                pcVar2 = *(code **)(param_1 + 0x910);
                uVar6 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),0xb);
                if (pcVar2 == nvswitch_get_eng_base_ls10) {
                  if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                    pcVar2 = (code *)invalidInstructionException();
                    (*pcVar2)();
                  }
                  lVar3 = *(long *)(param_1 + 0x1f90);
                  if (*(int *)(lVar3 + 0xcc0) == 0xb) {
                    uVar8 = *(uint *)(lVar3 + 0xcc4);
                  }
                  else {
                    nvswitch_assert_log();
                    uVar8 = *(uint *)(lVar3 + 0xcc4);
                  }
                  if (uVar6 < uVar8) {
                    iVar9 = *(int *)(lVar3 + 0xcc8 + (ulong)uVar6 * 4);
                    goto LAB_00247c19;
                  }
LAB_00247acb:
                  nvswitch_assert_log();
                }
                else {
                  iVar9 = (*pcVar2)(param_1,0xb,0,uVar6);
LAB_00247c19:
                  if ((iVar9 == -1) ||
                     (cVar5 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar10 + 0x38)),
                     cVar5 == '\0')) goto LAB_00247acb;
                }
                pcVar2 = *(code **)(param_1 + 0x920);
                uVar7 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),0xb);
                if (pcVar2 == nvswitch_eng_rd_ls10) {
                  uVar6 = nvswitch_eng_rd_ls10();
                }
                else {
                  uVar6 = (*pcVar2)(param_1,0xb,0,uVar7,0x3280);
                }
                pcVar2 = *(code **)(param_1 + 0x910);
                uVar8 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),0xb);
                if (pcVar2 == nvswitch_get_eng_base_ls10) {
                  if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                    pcVar2 = (code *)invalidInstructionException();
                    (*pcVar2)();
                  }
                  lVar3 = *(long *)(param_1 + 0x1f90);
                  if (*(int *)(lVar3 + 0xcc0) == 0xb) {
                    uVar1 = *(uint *)(lVar3 + 0xcc4);
                  }
                  else {
                    nvswitch_assert_log();
                    uVar1 = *(uint *)(lVar3 + 0xcc4);
                  }
                  if (uVar8 < uVar1) {
                    iVar9 = *(int *)(lVar3 + 0xcc8 + (ulong)uVar8 * 4);
                    goto LAB_00247b78;
                  }
LAB_00247b8e:
                  nvswitch_assert_log();
                }
                else {
                  iVar9 = (*pcVar2)(param_1,0xb,0,uVar8);
LAB_00247b78:
                  if ((iVar9 == -1) ||
                     (cVar5 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar10 + 0x38)),
                     cVar5 == '\0')) goto LAB_00247b8e;
                }
                pcVar2 = *(code **)(param_1 + 0x928);
                uVar7 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),0xb);
                (*pcVar2)(param_1,0xb,0,uVar7,0x3280,uVar6 | 0x107);
              }
              if ((uVar13 & 0x20000000) != 0) {
                pcVar2 = *(code **)(param_1 + 0x910);
                uVar13 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),0xb);
                if (pcVar2 == nvswitch_get_eng_base_ls10) {
                  if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
                    pcVar2 = (code *)invalidInstructionException();
                    (*pcVar2)();
                  }
                  lVar3 = *(long *)(param_1 + 0x1f90);
                  if (*(int *)(lVar3 + 0xcc0) == 0xb) {
                    uVar6 = *(uint *)(lVar3 + 0xcc4);
                  }
                  else {
                    nvswitch_assert_log();
                    uVar6 = *(uint *)(lVar3 + 0xcc4);
                  }
                  if (uVar13 < uVar6) {
                    iVar9 = *(int *)(lVar3 + 0xcc8 + (ulong)uVar13 * 4);
                    goto LAB_0024799a;
                  }
LAB_002479b0:
                  nvswitch_assert_log();
                }
                else {
                  iVar9 = (*pcVar2)(param_1,0xb,0,uVar13);
LAB_0024799a:
                  if ((iVar9 == -1) ||
                     (cVar5 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar10 + 0x38)),
                     cVar5 == '\0')) goto LAB_002479b0;
                }
                pcVar2 = *(code **)(param_1 + 0x920);
                uVar7 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar10 + 0x38),0xb);
                if (pcVar2 == nvswitch_eng_rd_ls10) {
                  nvswitch_eng_rd_ls10();
                }
                else {
                  (*pcVar2)(param_1,0xb,0,uVar7,0x3280);
                }
              }
            }
            else {
              uVar11 = nvswitch_minion_clear_dl_error_counters_ls10
                                 (param_1,*(undefined4 *)(lVar10 + 0x38));
              if ((int)uVar11 != 0) {
                return uVar11;
              }
            }
          }
        }
joined_r0x0024724f:
        if (uVar12 >> 1 == 0) break;
        uVar12 = uVar12 >> 1;
        cVar4 = cVar4 + '\x01';
      } while( true );
    }
    uVar11 = 0;
  }
  else {
    uVar11 = 0xfffffff1;
  }
  return uVar11;
}


// ===== 00247e39 nvswitch_set_training_mode_ls10.cold =====

void nvswitch_set_training_mode_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00247ea0 nvswitch_set_training_mode_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r15 replaced with injection: x86_indirect_thunk_r15 */

undefined8 nvswitch_set_training_mode_ls10(long *param_1)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  char cVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  uint local_3c;
  
  uVar8 = nvswitch_get_enabled_link_mask();
  if (*(long *)((long)param_1 + 0x5c) == 0) {
    if ((int)param_1[0x17] == 2) {
      if (uVar8 != 0) {
        uVar11 = 0;
joined_r0x00248014:
        for (; (uVar8 & 1) == 0; uVar8 = uVar8 >> 1) {
          uVar11 = uVar11 + 1;
        }
        uVar5 = nvswitch_get_num_links(param_1);
        if (uVar5 <= uVar11) {
          nvswitch_assert_log();
        }
        lVar9 = nvswitch_get_link(param_1,uVar11 & 0xff);
        if (lVar9 != 0) {
          pcVar2 = (code *)param_1[0x122];
          uVar5 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar9 + 0x38),9);
          if (pcVar2 == nvswitch_get_eng_base_ls10) {
            if ((int)param_1[0x3f1] != 7) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)invalidInstructionException();
              (*pcVar2)();
            }
            lVar3 = param_1[0x3f2];
            if (*(int *)(lVar3 + 0xa70) != 9) {
              nvswitch_assert_log();
            }
            if (*(uint *)(lVar3 + 0xa74) <= uVar5) goto LAB_002480af;
            iVar7 = *(int *)(lVar3 + 0xa78 + (ulong)uVar5 * 4);
          }
          else {
            iVar7 = (*pcVar2)(param_1,9,0,uVar5);
          }
          if ((iVar7 != -1) &&
             (cVar4 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar9 + 0x38)), cVar4 != '\0'))
          {
            pcVar2 = (code *)param_1[0x122];
            uVar5 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar9 + 0x38),9);
            if (pcVar2 == nvswitch_get_eng_base_ls10) {
              if ((int)param_1[0x3f1] != 7) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)invalidInstructionException();
                (*pcVar2)();
              }
              lVar3 = param_1[0x3f2];
              if (*(int *)(lVar3 + 0xa70) == 9) {
                uVar1 = *(uint *)(lVar3 + 0xa74);
              }
              else {
                nvswitch_assert_log();
                uVar1 = *(uint *)(lVar3 + 0xa74);
              }
              if (uVar5 < uVar1) {
                iVar7 = *(int *)(lVar3 + 0xa78 + (ulong)uVar5 * 4);
                goto LAB_002484ea;
              }
LAB_00248324:
              nvswitch_assert_log();
            }
            else {
              iVar7 = (*pcVar2)(param_1,9,0,uVar5);
LAB_002484ea:
              if ((iVar7 == -1) ||
                 (cVar4 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar9 + 0x38)),
                 cVar4 == '\0')) goto LAB_00248324;
            }
            pcVar2 = (code *)param_1[0x124];
            uVar6 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar9 + 0x38),9);
            if (pcVar2 == nvswitch_eng_rd_ls10) {
              uVar10 = nvswitch_eng_rd_ls10();
            }
            else {
              uVar10 = (*pcVar2)(param_1,9,0,uVar6,0x680);
            }
            if ((uVar10 & 0x10000000) == 0) {
              return 0xfffffff3;
            }
            pcVar2 = (code *)param_1[0x122];
            uVar5 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar9 + 0x38),9);
            if (pcVar2 == nvswitch_get_eng_base_ls10) {
              if ((int)param_1[0x3f1] != 7) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)invalidInstructionException();
                (*pcVar2)();
              }
              lVar3 = param_1[0x3f2];
              if (*(int *)(lVar3 + 0xa70) == 9) {
                uVar1 = *(uint *)(lVar3 + 0xa74);
              }
              else {
                nvswitch_assert_log();
                uVar1 = *(uint *)(lVar3 + 0xa74);
              }
              if (uVar5 < uVar1) {
                iVar7 = *(int *)(lVar3 + 0xa78 + (ulong)uVar5 * 4);
                goto LAB_0024851a;
              }
LAB_002483c4:
              nvswitch_assert_log();
            }
            else {
              iVar7 = (*pcVar2)(param_1,9,0,uVar5);
LAB_0024851a:
              if ((iVar7 == -1) ||
                 (cVar4 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar9 + 0x38)),
                 cVar4 == '\0')) goto LAB_002483c4;
            }
            pcVar2 = (code *)param_1[0x124];
            uVar6 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar9 + 0x38),9);
            if (pcVar2 == nvswitch_eng_rd_ls10) {
              local_3c = nvswitch_eng_rd_ls10();
            }
            else {
              local_3c = (*pcVar2)(param_1,9,0,uVar6,0x624);
            }
            pcVar2 = (code *)param_1[0x122];
            uVar5 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar9 + 0x38),9);
            if (pcVar2 == nvswitch_get_eng_base_ls10) {
              if ((int)param_1[0x3f1] != 7) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)invalidInstructionException();
                (*pcVar2)();
              }
              lVar3 = param_1[0x3f2];
              if (*(int *)(lVar3 + 0xa70) == 9) {
                uVar1 = *(uint *)(lVar3 + 0xa74);
              }
              else {
                nvswitch_assert_log();
                uVar1 = *(uint *)(lVar3 + 0xa74);
              }
              if (uVar5 < uVar1) {
                iVar7 = *(int *)(lVar3 + 0xa78 + (ulong)uVar5 * 4);
                goto LAB_00248462;
              }
LAB_00248477:
              nvswitch_assert_log();
            }
            else {
              iVar7 = (*pcVar2)(param_1,9,0,uVar5);
LAB_00248462:
              if ((iVar7 == -1) ||
                 (cVar4 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar9 + 0x38)),
                 cVar4 == '\0')) goto LAB_00248477;
            }
            pcVar2 = (code *)param_1[0x125];
            uVar6 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar9 + 0x38),9);
            (*pcVar2)(param_1,9,0,uVar6,0x624,local_3c | 2);
          }
        }
LAB_002480af:
        uVar8 = uVar8 >> 1;
        if (uVar8 != 0) {
          uVar11 = uVar11 + 1;
          goto joined_r0x00248014;
        }
      }
    }
    else if ((int)param_1[0x17] == 1) {
      if (uVar8 != 0) {
        uVar11 = 0;
joined_r0x002485b4:
        for (; (uVar8 & 1) == 0; uVar8 = uVar8 >> 1) {
          uVar11 = uVar11 + 1;
        }
        uVar5 = nvswitch_get_num_links(param_1);
        if (uVar5 <= uVar11) {
          nvswitch_assert_log();
        }
        lVar9 = nvswitch_get_link(param_1,uVar11 & 0xff);
        if (lVar9 != 0) {
          pcVar2 = (code *)param_1[0x122];
          uVar5 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar9 + 0x38),9);
          if (pcVar2 == nvswitch_get_eng_base_ls10) {
            if ((int)param_1[0x3f1] != 7) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)invalidInstructionException();
              (*pcVar2)();
            }
            lVar3 = param_1[0x3f2];
            if (*(int *)(lVar3 + 0xa70) != 9) {
              nvswitch_assert_log();
            }
            if (*(uint *)(lVar3 + 0xa74) <= uVar5) goto LAB_0024865a;
            iVar7 = *(int *)(lVar3 + 0xa78 + (ulong)uVar5 * 4);
          }
          else {
            iVar7 = (*pcVar2)(param_1,9,0,uVar5);
          }
          if ((iVar7 != -1) &&
             (cVar4 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar9 + 0x38)), cVar4 != '\0'))
          {
            pcVar2 = (code *)param_1[0x122];
            uVar5 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar9 + 0x38),9);
            if (pcVar2 == nvswitch_get_eng_base_ls10) {
              if ((int)param_1[0x3f1] != 7) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)invalidInstructionException();
                (*pcVar2)();
              }
              lVar3 = param_1[0x3f2];
              if (*(int *)(lVar3 + 0xa70) != 9) {
                nvswitch_assert_log();
              }
              if (uVar5 < *(uint *)(lVar3 + 0xa74)) {
                iVar7 = *(int *)(lVar3 + 0xa78 + (ulong)uVar5 * 4);
                goto LAB_002488e7;
              }
LAB_00248744:
              nvswitch_assert_log();
            }
            else {
              iVar7 = (*pcVar2)(param_1,9,0,uVar5);
LAB_002488e7:
              if ((iVar7 == -1) ||
                 (cVar4 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar9 + 0x38)),
                 cVar4 == '\0')) goto LAB_00248744;
            }
            pcVar2 = (code *)param_1[0x124];
            uVar6 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar9 + 0x38),9);
            if (pcVar2 == nvswitch_eng_rd_ls10) {
              local_3c = nvswitch_eng_rd_ls10();
            }
            else {
              local_3c = (*pcVar2)(param_1,9,0,uVar6,0x624);
            }
            pcVar2 = (code *)param_1[0x122];
            uVar5 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar9 + 0x38),9);
            if (pcVar2 == nvswitch_get_eng_base_ls10) {
              if ((int)param_1[0x3f1] != 7) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)invalidInstructionException();
                (*pcVar2)();
              }
              lVar3 = param_1[0x3f2];
              if (*(int *)(lVar3 + 0xa70) != 9) {
                nvswitch_assert_log();
              }
              if (uVar5 < *(uint *)(lVar3 + 0xa74)) {
                iVar7 = *(int *)(lVar3 + 0xa78 + (ulong)uVar5 * 4);
                goto LAB_002487e2;
              }
LAB_002487f7:
              nvswitch_assert_log();
            }
            else {
              iVar7 = (*pcVar2)(param_1,9,0,uVar5);
LAB_002487e2:
              if ((iVar7 == -1) ||
                 (cVar4 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar9 + 0x38)),
                 cVar4 == '\0')) goto LAB_002487f7;
            }
            pcVar2 = (code *)param_1[0x125];
            uVar6 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar9 + 0x38),9);
            (*pcVar2)(param_1,9,0,uVar6,0x624,local_3c & 0xfffffffd);
          }
        }
LAB_0024865a:
        uVar8 = uVar8 >> 1;
        if (uVar8 != 0) {
          uVar11 = uVar11 + 1;
          goto joined_r0x002485b4;
        }
      }
    }
    else if (uVar8 != 0) {
      uVar11 = 0;
      do {
        for (; (uVar8 & 1) == 0; uVar8 = uVar8 >> 1) {
          uVar11 = uVar11 + 1;
        }
        uVar5 = nvswitch_get_num_links(param_1);
        if (uVar5 <= uVar11) {
          nvswitch_assert_log();
        }
        lVar9 = nvswitch_get_link(param_1,uVar11 & 0xff);
        if (lVar9 != 0) {
          pcVar2 = (code *)param_1[0x122];
          uVar5 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar9 + 0x38),9);
          if (pcVar2 == nvswitch_get_eng_base_ls10) {
            if ((int)param_1[0x3f1] != 7) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)invalidInstructionException();
              (*pcVar2)();
            }
            lVar3 = param_1[0x3f2];
            if (*(int *)(lVar3 + 0xa70) != 9) {
              nvswitch_assert_log();
            }
            if (*(uint *)(lVar3 + 0xa74) <= uVar5) goto LAB_00247faa;
            iVar7 = *(int *)(lVar3 + 0xa78 + (ulong)uVar5 * 4);
          }
          else {
            iVar7 = (*pcVar2)(param_1,9,0,uVar5);
          }
          if ((iVar7 != -1) &&
             (cVar4 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar9 + 0x38)), cVar4 != '\0'))
          {
            pcVar2 = (code *)param_1[0x122];
            uVar5 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar9 + 0x38),9);
            if (pcVar2 == nvswitch_get_eng_base_ls10) {
              if ((int)param_1[0x3f1] != 7) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)invalidInstructionException();
                (*pcVar2)();
              }
              lVar3 = param_1[0x3f2];
              if (*(int *)(lVar3 + 0xa70) != 9) {
                nvswitch_assert_log();
              }
              if (uVar5 < *(uint *)(lVar3 + 0xa74)) {
                iVar7 = *(int *)(lVar3 + 0xa78 + (ulong)uVar5 * 4);
                goto LAB_00248152;
              }
LAB_00248167:
              nvswitch_assert_log();
            }
            else {
              iVar7 = (*pcVar2)(param_1,9,0,uVar5);
LAB_00248152:
              if ((iVar7 == -1) ||
                 (cVar4 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar9 + 0x38)),
                 cVar4 == '\0')) goto LAB_00248167;
            }
            pcVar2 = (code *)param_1[0x124];
            uVar6 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar9 + 0x38),9);
            if (pcVar2 == nvswitch_eng_rd_ls10) {
              uVar10 = nvswitch_eng_rd_ls10();
            }
            else {
              uVar10 = (*pcVar2)(param_1,9,0,uVar6,0x624);
            }
            if ((uVar10 & 2) == 0) {
              *(undefined1 *)(*param_1 + 0xb1) = 0;
              return 0;
            }
            pcVar2 = (code *)param_1[0x122];
            uVar5 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar9 + 0x38),9);
            if (pcVar2 == nvswitch_get_eng_base_ls10) {
              if ((int)param_1[0x3f1] != 7) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)invalidInstructionException();
                (*pcVar2)();
              }
              lVar3 = param_1[0x3f2];
              if (*(int *)(lVar3 + 0xa70) != 9) {
                nvswitch_assert_log();
              }
              if (uVar5 < *(uint *)(lVar3 + 0xa74)) {
                iVar7 = *(int *)(lVar3 + 0xa78 + (ulong)uVar5 * 4);
                goto LAB_0024820a;
              }
LAB_0024821f:
              nvswitch_assert_log();
            }
            else {
              iVar7 = (*pcVar2)(param_1,9,0,uVar5);
LAB_0024820a:
              if ((iVar7 == -1) ||
                 (cVar4 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar9 + 0x38)),
                 cVar4 == '\0')) goto LAB_0024821f;
            }
            pcVar2 = (code *)param_1[0x124];
            uVar6 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar9 + 0x38),9);
            if (pcVar2 == nvswitch_eng_rd_ls10) {
              uVar10 = nvswitch_eng_rd_ls10();
            }
            else {
              uVar10 = (*pcVar2)(param_1,9,0,uVar6,0x680);
            }
            if ((uVar10 & 0x10000000) == 0) {
              *(undefined1 *)(*param_1 + 0xb1) = 0;
              return 0;
            }
            *(undefined1 *)(*param_1 + 0xb1) = 1;
          }
        }
LAB_00247faa:
        uVar8 = uVar8 >> 1;
        if (uVar8 == 0) {
          return 0;
        }
        uVar11 = uVar11 + 1;
      } while( true );
    }
  }
  return 0;
}


// ===== 002489b1 nvswitch_ctrl_get_remap_policy_ls10.cold =====

void nvswitch_ctrl_get_remap_policy_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00248a40 nvswitch_ctrl_get_remap_policy_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r12 replaced with injection: x86_indirect_thunk_r12 */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */
/* WARNING: Function: __x86_indirect_thunk_rbx replaced with injection: x86_indirect_thunk_rbx */

int nvswitch_ctrl_get_remap_policy_ls10(long param_1,undefined4 *param_2)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  undefined8 uVar11;
  code *pcVar12;
  bool bVar13;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_3c [3];
  
  cVar2 = nvswitch_is_tnvl_mode_locked();
  if (cVar2 != '\0') {
    return -0xf;
  }
  pcVar12 = *(code **)(param_1 + 0x910);
  uVar3 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
  if (pcVar12 == nvswitch_get_eng_base_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar12 = (code *)invalidInstructionException();
      (*pcVar12)();
    }
    lVar1 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar1 + 0x5d0) == 5) {
      uVar5 = *(uint *)(lVar1 + 0x5d4);
    }
    else {
      nvswitch_assert_log();
      uVar5 = *(uint *)(lVar1 + 0x5d4);
    }
    if (uVar5 <= uVar3) {
      return -1;
    }
    iVar4 = *(int *)(lVar1 + 0x5d8 + (ulong)uVar3 * 4);
  }
  else {
    iVar4 = (*pcVar12)(param_1,5,0,(ulong)uVar3);
  }
  if ((iVar4 == -1) || (cVar2 = nvswitch_is_link_valid(param_1,*param_2), cVar2 == '\0')) {
    return -1;
  }
  iVar4 = nvswitch_get_remap_table_selector(param_1,param_2[1],local_3c);
  if (iVar4 != 0) {
    return iVar4;
  }
  uVar3 = nvswitch_get_ingress_ram_size(param_1,local_3c[0]);
  if (uVar3 <= (uint)param_2[2]) {
    return -1;
  }
  cVar2 = nvswitch_is_tnvl_mode_locked(param_1);
  if (cVar2 != '\0') {
    return -0xf;
  }
  nvswitch_os_memset(param_2 + 6,0,0x1000);
  local_4c = param_2[2];
  pcVar12 = *(code **)(param_1 + 0x910);
  if (param_2[1] == 3) {
    uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
    if (pcVar12 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
        pcVar12 = (code *)invalidInstructionException();
        (*pcVar12)();
      }
      lVar1 = *(long *)(param_1 + 0x1f90);
      if (*(int *)(lVar1 + 0x5d0) != 5) {
        nvswitch_assert_log();
      }
      if (uVar5 < *(uint *)(lVar1 + 0x5d4)) {
        iVar4 = *(int *)(lVar1 + 0x5d8 + (ulong)uVar5 * 4);
        goto LAB_00249904;
      }
LAB_00249918:
      nvswitch_assert_log();
    }
    else {
      iVar4 = (*pcVar12)(param_1,5,0,(ulong)uVar5);
LAB_00249904:
      if ((iVar4 == -1) || (cVar2 = nvswitch_is_link_valid(param_1,*param_2), cVar2 == '\0'))
      goto LAB_00249918;
    }
    uVar5 = param_2[2];
    pcVar12 = *(code **)(param_1 + 0x928);
    uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
    uVar5 = uVar5 & 0x7f;
    uVar11 = 0x1084;
    goto LAB_00248bf3;
  }
  uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
  if (pcVar12 == nvswitch_get_eng_base_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar12 = (code *)invalidInstructionException();
      (*pcVar12)();
    }
    lVar1 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar1 + 0x5d0) == 5) {
      uVar7 = *(uint *)(lVar1 + 0x5d4);
    }
    else {
      nvswitch_assert_log();
      uVar7 = *(uint *)(lVar1 + 0x5d4);
    }
    if (uVar5 < uVar7) {
      iVar4 = *(int *)(lVar1 + 0x5d8 + (ulong)uVar5 * 4);
      goto LAB_002495f0;
    }
LAB_00248bb1:
    nvswitch_assert_log();
  }
  else {
    iVar4 = (*pcVar12)(param_1,5,0,(ulong)uVar5);
LAB_002495f0:
    if ((iVar4 == -1) || (cVar2 = nvswitch_is_link_valid(param_1,*param_2), cVar2 == '\0'))
    goto LAB_00248bb1;
  }
  pcVar12 = *(code **)(param_1 + 0x928);
  uVar5 = (local_3c[0] & 7) << 0x10 | param_2[2] & 0x3fff;
  uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
  uVar11 = 0x1080;
LAB_00248bf3:
  (*pcVar12)(param_1,5,0,uVar6,uVar11,uVar5 | 0x80000000);
  local_50 = 0;
  if (local_4c < uVar3) {
    local_50 = 0;
    do {
      pcVar12 = *(code **)(param_1 + 0x910);
      if (param_2[1] == 3) {
        uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar12 = (code *)invalidInstructionException();
            (*pcVar12)();
          }
          lVar1 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar1 + 0x5d0) != 5) {
            nvswitch_assert_log();
          }
          if (uVar5 < *(uint *)(lVar1 + 0x5d4)) {
            iVar4 = *(int *)(lVar1 + 0x5d8 + (ulong)uVar5 * 4);
            goto LAB_002491bd;
          }
LAB_002491d1:
          nvswitch_assert_log();
        }
        else {
          iVar4 = (*pcVar12)(param_1,5,0,(ulong)uVar5);
LAB_002491bd:
          if ((iVar4 == -1) || (cVar2 = nvswitch_is_link_valid(param_1,*param_2), cVar2 == '\0'))
          goto LAB_002491d1;
        }
        pcVar12 = *(code **)(param_1 + 0x920);
        uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_eng_rd_ls10) {
          uVar5 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar5 = (*pcVar12)(param_1,5,0,uVar6,0x10f0);
        }
        pcVar12 = *(code **)(param_1 + 0x910);
        uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar12 = (code *)invalidInstructionException();
            (*pcVar12)();
          }
          lVar1 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar1 + 0x5d0) != 5) {
            nvswitch_assert_log();
          }
          if (uVar7 < *(uint *)(lVar1 + 0x5d4)) {
            iVar4 = *(int *)(lVar1 + 0x5d8 + (ulong)uVar7 * 4);
            goto LAB_0024926f;
          }
LAB_00249283:
          nvswitch_assert_log();
        }
        else {
          iVar4 = (*pcVar12)(param_1,5,0,(ulong)uVar7);
LAB_0024926f:
          if ((iVar4 == -1) || (cVar2 = nvswitch_is_link_valid(param_1,*param_2), cVar2 == '\0'))
          goto LAB_00249283;
        }
        pcVar12 = *(code **)(param_1 + 0x920);
        uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_eng_rd_ls10) {
          local_54 = nvswitch_eng_rd_ls10();
        }
        else {
          local_54 = (*pcVar12)(param_1,5,0,uVar6,0x10f4);
        }
        pcVar12 = *(code **)(param_1 + 0x910);
        uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar12 = (code *)invalidInstructionException();
            (*pcVar12)();
          }
          lVar1 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar1 + 0x5d0) != 5) {
            nvswitch_assert_log();
          }
          if (uVar7 < *(uint *)(lVar1 + 0x5d4)) {
            iVar4 = *(int *)(lVar1 + 0x5d8 + (ulong)uVar7 * 4);
            goto LAB_00249322;
          }
LAB_00249336:
          nvswitch_assert_log();
        }
        else {
          iVar4 = (*pcVar12)(param_1,5,0,(ulong)uVar7);
LAB_00249322:
          if ((iVar4 == -1) || (cVar2 = nvswitch_is_link_valid(param_1,*param_2), cVar2 == '\0'))
          goto LAB_00249336;
        }
        pcVar12 = *(code **)(param_1 + 0x920);
        uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_eng_rd_ls10) {
          local_58 = nvswitch_eng_rd_ls10();
        }
        else {
          local_58 = (*pcVar12)(param_1,5,0,uVar6,0x10f8);
        }
        pcVar12 = *(code **)(param_1 + 0x910);
        uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar12 = (code *)invalidInstructionException();
            (*pcVar12)();
          }
          lVar1 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar1 + 0x5d0) != 5) {
            nvswitch_assert_log();
          }
          if (uVar7 < *(uint *)(lVar1 + 0x5d4)) {
            iVar4 = *(int *)(lVar1 + 0x5d8 + (ulong)uVar7 * 4);
            goto LAB_002493d5;
          }
LAB_002493e9:
          nvswitch_assert_log();
        }
        else {
          iVar4 = (*pcVar12)(param_1,5,0,(ulong)uVar7);
LAB_002493d5:
          if ((iVar4 == -1) || (cVar2 = nvswitch_is_link_valid(param_1,*param_2), cVar2 == '\0'))
          goto LAB_002493e9;
        }
        pcVar12 = *(code **)(param_1 + 0x920);
        uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_eng_rd_ls10) {
          uVar7 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar7 = (*pcVar12)(param_1,5,0,uVar6,0x10fc);
        }
        pcVar12 = *(code **)(param_1 + 0x910);
        uVar8 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar12 = (code *)invalidInstructionException();
            (*pcVar12)();
          }
          lVar1 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar1 + 0x5d0) != 5) {
            nvswitch_assert_log();
          }
          if (uVar8 < *(uint *)(lVar1 + 0x5d4)) {
            iVar4 = *(int *)(lVar1 + 0x5d8 + (ulong)uVar8 * 4);
            goto LAB_0024948d;
          }
LAB_002494a1:
          nvswitch_assert_log();
        }
        else {
          iVar4 = (*pcVar12)(param_1,5,0,uVar8);
LAB_0024948d:
          if ((iVar4 == -1) || (cVar2 = nvswitch_is_link_valid(param_1,*param_2), cVar2 == '\0'))
          goto LAB_002494a1;
        }
        pcVar12 = *(code **)(param_1 + 0x920);
        uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_eng_rd_ls10) {
          uVar8 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar8 = (*pcVar12)(param_1,5,0,uVar6,0x1100);
        }
        pcVar12 = *(code **)(param_1 + 0x910);
        uVar9 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar12 = (code *)invalidInstructionException();
            (*pcVar12)();
          }
          lVar1 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar1 + 0x5d0) != 5) {
            nvswitch_assert_log();
          }
          if (uVar9 < *(uint *)(lVar1 + 0x5d4)) {
            iVar4 = *(int *)(lVar1 + 0x5d8 + (ulong)uVar9 * 4);
            goto LAB_00249552;
          }
LAB_00249566:
          nvswitch_assert_log();
        }
        else {
          iVar4 = (*pcVar12)(param_1,5,0,uVar9);
LAB_00249552:
          if ((iVar4 == -1) || (cVar2 = nvswitch_is_link_valid(param_1,*param_2), cVar2 == '\0'))
          goto LAB_00249566;
        }
        pcVar12 = *(code **)(param_1 + 0x920);
        uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        uVar11 = 0x1104;
      }
      else {
        uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar12 = (code *)invalidInstructionException();
            (*pcVar12)();
          }
          lVar1 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar1 + 0x5d0) != 5) {
            nvswitch_assert_log();
          }
          if (uVar5 < *(uint *)(lVar1 + 0x5d4)) {
            iVar4 = *(int *)(lVar1 + 0x5d8 + (ulong)uVar5 * 4);
            goto LAB_00248c69;
          }
LAB_00248c7d:
          nvswitch_assert_log();
        }
        else {
          iVar4 = (*pcVar12)(param_1,5,0,(ulong)uVar5);
LAB_00248c69:
          if ((iVar4 == -1) || (cVar2 = nvswitch_is_link_valid(param_1,*param_2), cVar2 == '\0'))
          goto LAB_00248c7d;
        }
        pcVar12 = *(code **)(param_1 + 0x920);
        uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_eng_rd_ls10) {
          uVar5 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar5 = (*pcVar12)(param_1,5,0,uVar6,0x1090);
        }
        pcVar12 = *(code **)(param_1 + 0x910);
        uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar12 = (code *)invalidInstructionException();
            (*pcVar12)();
          }
          lVar1 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar1 + 0x5d0) != 5) {
            nvswitch_assert_log();
          }
          if (uVar7 < *(uint *)(lVar1 + 0x5d4)) {
            iVar4 = *(int *)(lVar1 + 0x5d8 + (ulong)uVar7 * 4);
            goto LAB_00248d1b;
          }
LAB_00248d2f:
          nvswitch_assert_log();
        }
        else {
          iVar4 = (*pcVar12)(param_1,5,0,(ulong)uVar7);
LAB_00248d1b:
          if ((iVar4 == -1) || (cVar2 = nvswitch_is_link_valid(param_1,*param_2), cVar2 == '\0'))
          goto LAB_00248d2f;
        }
        pcVar12 = *(code **)(param_1 + 0x920);
        uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_eng_rd_ls10) {
          local_54 = nvswitch_eng_rd_ls10();
        }
        else {
          local_54 = (*pcVar12)(param_1,5,0,uVar6,0x1094);
        }
        pcVar12 = *(code **)(param_1 + 0x910);
        uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar12 = (code *)invalidInstructionException();
            (*pcVar12)();
          }
          lVar1 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar1 + 0x5d0) != 5) {
            nvswitch_assert_log();
          }
          if (uVar7 < *(uint *)(lVar1 + 0x5d4)) {
            iVar4 = *(int *)(lVar1 + 0x5d8 + (ulong)uVar7 * 4);
            goto LAB_00248dce;
          }
LAB_00248de2:
          nvswitch_assert_log();
        }
        else {
          iVar4 = (*pcVar12)(param_1,5,0,(ulong)uVar7);
LAB_00248dce:
          if ((iVar4 == -1) || (cVar2 = nvswitch_is_link_valid(param_1,*param_2), cVar2 == '\0'))
          goto LAB_00248de2;
        }
        pcVar12 = *(code **)(param_1 + 0x920);
        uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_eng_rd_ls10) {
          local_58 = nvswitch_eng_rd_ls10();
        }
        else {
          local_58 = (*pcVar12)(param_1,5,0,uVar6,0x1098);
        }
        pcVar12 = *(code **)(param_1 + 0x910);
        uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar12 = (code *)invalidInstructionException();
            (*pcVar12)();
          }
          lVar1 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar1 + 0x5d0) != 5) {
            nvswitch_assert_log();
          }
          if (uVar7 < *(uint *)(lVar1 + 0x5d4)) {
            iVar4 = *(int *)(lVar1 + 0x5d8 + (ulong)uVar7 * 4);
            goto LAB_00248e81;
          }
LAB_00248e95:
          nvswitch_assert_log();
        }
        else {
          iVar4 = (*pcVar12)(param_1,5,0,(ulong)uVar7);
LAB_00248e81:
          if ((iVar4 == -1) || (cVar2 = nvswitch_is_link_valid(param_1,*param_2), cVar2 == '\0'))
          goto LAB_00248e95;
        }
        pcVar12 = *(code **)(param_1 + 0x920);
        uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_eng_rd_ls10) {
          uVar7 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar7 = (*pcVar12)(param_1,5,0,uVar6,0x109c);
        }
        pcVar12 = *(code **)(param_1 + 0x910);
        uVar8 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar12 = (code *)invalidInstructionException();
            (*pcVar12)();
          }
          lVar1 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar1 + 0x5d0) != 5) {
            nvswitch_assert_log();
          }
          if (uVar8 < *(uint *)(lVar1 + 0x5d4)) {
            iVar4 = *(int *)(lVar1 + 0x5d8 + (ulong)uVar8 * 4);
            goto LAB_00248f39;
          }
LAB_00248f4d:
          nvswitch_assert_log();
        }
        else {
          iVar4 = (*pcVar12)(param_1,5,0,uVar8);
LAB_00248f39:
          if ((iVar4 == -1) || (cVar2 = nvswitch_is_link_valid(param_1,*param_2), cVar2 == '\0'))
          goto LAB_00248f4d;
        }
        pcVar12 = *(code **)(param_1 + 0x920);
        uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_eng_rd_ls10) {
          uVar8 = nvswitch_eng_rd_ls10();
        }
        else {
          uVar8 = (*pcVar12)(param_1,5,0,uVar6,0x10a0);
        }
        pcVar12 = *(code **)(param_1 + 0x910);
        uVar9 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        if (pcVar12 == nvswitch_get_eng_base_ls10) {
          if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
            pcVar12 = (code *)invalidInstructionException();
            (*pcVar12)();
          }
          lVar1 = *(long *)(param_1 + 0x1f90);
          if (*(int *)(lVar1 + 0x5d0) != 5) {
            nvswitch_assert_log();
          }
          if (uVar9 < *(uint *)(lVar1 + 0x5d4)) {
            iVar4 = *(int *)(lVar1 + 0x5d8 + (ulong)uVar9 * 4);
            goto LAB_00248ffe;
          }
LAB_00249012:
          nvswitch_assert_log();
        }
        else {
          iVar4 = (*pcVar12)(param_1,5,0,uVar9);
LAB_00248ffe:
          if ((iVar4 == -1) || (cVar2 = nvswitch_is_link_valid(param_1,*param_2), cVar2 == '\0'))
          goto LAB_00249012;
        }
        pcVar12 = *(code **)(param_1 + 0x920);
        uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
        uVar11 = 0x10a4;
      }
      if (pcVar12 == nvswitch_eng_rd_ls10) {
        uVar9 = nvswitch_eng_rd_ls10();
      }
      else {
        uVar9 = (*pcVar12)(param_1,5,0,uVar6,uVar11);
      }
      if (((((uVar8 == 0 && uVar7 == 0) && local_58 == 0) && uVar9 == 0) && uVar5 == 0) &&
          local_54 == 0) {
        bVar13 = true;
      }
      else {
        pbVar10 = (byte *)(param_2 + 6 + (ulong)local_50 * 0x10);
        *(uint *)(pbVar10 + 8) = uVar5 >> 0xf & 3;
        pbVar10[0x28] = 0;
        pbVar10[0x29] = 0;
        pbVar10[0x2a] = 0;
        pbVar10[0x2b] = 0;
        pbVar10[0x2c] = 0;
        pbVar10[0x2d] = 0;
        pbVar10[0x2e] = 0;
        pbVar10[0x2f] = 0;
        *pbVar10 = (byte)(uVar5 >> 0x1f);
        *(uint *)(pbVar10 + 0x18) = local_54 & 0xffff;
        *(uint *)(pbVar10 + 0x20) = local_58 & 0xffff;
        *(uint *)(pbVar10 + 0x1c) = local_54 >> 0x10;
        *(ulong *)(pbVar10 + 0x10) = (ulong)(uVar5 & 0x1fff) << 0x27;
        *(ulong *)(pbVar10 + 0x38) = (ulong)((uVar9 & 0x30) << 0xc | uVar7 >> 0x10) << 0x15;
        *(ulong *)(pbVar10 + 0x30) = (ulong)((uVar9 & 3) << 0x10 | uVar7 & 0xffff) << 0x15;
        uVar5 = uVar8 & 0x7ff;
        if (param_2[1] == 3) {
          uVar5 = uVar8 & 0x7f;
        }
        uVar7 = uVar8 >> 0xf;
        *(uint *)(pbVar10 + 4) = uVar5;
        uVar5 = uVar7 & 0x5f | 0x80000000;
        if ((uVar7 & 0x20) == 0) {
          uVar5 = uVar7 & 0x7f;
        }
        *(uint *)(pbVar10 + 0xc) = uVar5;
        if ((param_2[1] == 3) && ((uVar8 & 0x400000) != 0)) {
          *(uint *)(pbVar10 + 0xc) = *(uint *)(pbVar10 + 0xc) | 0x40000000;
        }
        bVar13 = local_50 != 0x3f;
        local_50 = local_50 + 1;
      }
      local_4c = local_4c + 1;
    } while ((local_4c < uVar3) && (bVar13));
  }
  param_2[3] = local_50;
  param_2[4] = local_4c;
  return 0;
}


// ===== 002499b4 nvswitch_set_nport_port_config_ls10.cold =====

void nvswitch_set_nport_port_config_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00249b10 nvswitch_set_nport_port_config_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */
/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */

undefined4 nvswitch_set_nport_port_config_ls10(long param_1,undefined4 *param_2)

{
  code *pcVar1;
  long lVar2;
  undefined8 uVar3;
  char cVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  
  if (0x7ff < (uint)param_2[2]) {
    return 0xffffffff;
  }
  if (0xf < (uint)param_2[3]) {
    return 0xffffffff;
  }
  cVar4 = nvswitch_is_tnvl_mode_locked();
  if (cVar4 != '\0') {
    return 0xfffffff1;
  }
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
  if (pcVar1 == nvswitch_get_eng_base_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    lVar2 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar2 + 0x5d0) == 5) {
      uVar7 = *(uint *)(lVar2 + 0x5d4);
    }
    else {
      nvswitch_assert_log();
      uVar7 = *(uint *)(lVar2 + 0x5d4);
    }
    if (uVar5 < uVar7) {
      iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar5 * 4);
      goto LAB_00249f1b;
    }
LAB_00249bb1:
    nvswitch_assert_log();
  }
  else {
    iVar10 = (*pcVar1)(param_1,5,0,uVar5);
LAB_00249f1b:
    if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
    goto LAB_00249bb1;
  }
  pcVar1 = *(code **)(param_1 + 0x920);
  uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
  if (pcVar1 == nvswitch_eng_rd_ls10) {
    uVar5 = nvswitch_eng_rd_ls10();
  }
  else {
    uVar5 = (*pcVar1)(param_1,5,0,uVar6,0x40);
  }
  uVar7 = param_2[1];
  if (uVar7 == 2) {
    uVar5 = uVar5 | 1;
  }
  else {
    if ((2 < uVar7) && (uVar7 != 3)) {
      return 0xffffffff;
    }
    uVar5 = uVar5 & 0xfffffffe;
  }
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
  if (pcVar1 == nvswitch_get_eng_base_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    lVar2 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar2 + 0x5d0) != 5) {
      nvswitch_assert_log();
    }
    if (uVar7 < *(uint *)(lVar2 + 0x5d4)) {
      iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar7 * 4);
      goto LAB_00249c6c;
    }
LAB_00249c81:
    nvswitch_assert_log();
  }
  else {
    iVar10 = (*pcVar1)(param_1,5,0,(ulong)uVar7);
LAB_00249c6c:
    if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
    goto LAB_00249c81;
  }
  pcVar1 = *(code **)(param_1 + 0x928);
  uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
  (*pcVar1)(param_1,5,0,uVar6,0x40,uVar5);
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
  if (pcVar1 == nvswitch_get_eng_base_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    lVar2 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar2 + 0x5d0) != 5) {
      nvswitch_assert_log();
    }
    if (uVar5 < *(uint *)(lVar2 + 0x5d4)) {
      iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar5 * 4);
      goto LAB_00249d13;
    }
LAB_00249d28:
    nvswitch_assert_log();
  }
  else {
    iVar10 = (*pcVar1)(param_1,5,0,(ulong)uVar5);
LAB_00249d13:
    if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
    goto LAB_00249d28;
  }
  uVar5 = param_2[3];
  uVar7 = param_2[2];
  pcVar1 = *(code **)(param_1 + 0x928);
  uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
  (*pcVar1)(param_1,5,0,uVar6,0x54,uVar7 & 0x7ff | (uVar5 & 0xf) << 0xf);
  if (param_2[1] == 2) {
    cVar4 = nvswitch_is_soe_supported(param_1);
    if (cVar4 == '\0') {
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar5 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar5 * 4);
          goto LAB_0024a08b;
        }
LAB_0024a0a0:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,(ulong)uVar5);
LAB_0024a08b:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024a0a0;
      }
      pcVar1 = *(code **)(param_1 + 0x920);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_eng_rd_ls10) {
        uVar5 = nvswitch_eng_rd_ls10();
      }
      else {
        uVar5 = (*pcVar1)(param_1,5,0,uVar6,0x40);
      }
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar7 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar7 * 4);
          goto LAB_0024a145;
        }
LAB_0024a15a:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,uVar7);
LAB_0024a145:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024a15a;
      }
      pcVar1 = *(code **)(param_1 + 0x928);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      (*pcVar1)(param_1,5,0,uVar6,0x40,uVar5 & 0xffffc1f9 | 0x30001);
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar5 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar5 * 4);
          goto LAB_0024a1fb;
        }
LAB_0024a210:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,(ulong)uVar5);
LAB_0024a1fb:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024a210;
      }
      pcVar1 = *(code **)(param_1 + 0x920);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_eng_rd_ls10) {
        uVar5 = nvswitch_eng_rd_ls10();
      }
      else {
        uVar5 = (*pcVar1)(param_1,5,0,uVar6,0x4040);
      }
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar7 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar7 * 4);
          goto LAB_0024a2b5;
        }
LAB_0024a2ca:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,uVar7);
LAB_0024a2b5:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024a2ca;
      }
      pcVar1 = *(code **)(param_1 + 0x928);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      (*pcVar1)(param_1,5,0,uVar6,0x4040,uVar5 & 0xfffffdff);
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar5 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar5 * 4);
          goto LAB_0024a364;
        }
LAB_0024a379:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,(ulong)uVar5);
LAB_0024a364:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024a379;
      }
      pcVar1 = *(code **)(param_1 + 0x920);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_eng_rd_ls10) {
        uVar5 = nvswitch_eng_rd_ls10();
      }
      else {
        uVar5 = (*pcVar1)(param_1,5,0,uVar6,0x4414);
      }
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar7 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar7 * 4);
          goto LAB_0024a41e;
        }
LAB_0024a433:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,uVar7);
LAB_0024a41e:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024a433;
      }
      pcVar1 = *(code **)(param_1 + 0x928);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      (*pcVar1)(param_1,5,0,uVar6,0x4414,uVar5 & 0xfffae8ff);
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar5 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar5 * 4);
          goto LAB_0024a4cd;
        }
LAB_0024a4e2:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,(ulong)uVar5);
LAB_0024a4cd:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024a4e2;
      }
      pcVar1 = *(code **)(param_1 + 0x920);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_eng_rd_ls10) {
        uVar5 = nvswitch_eng_rd_ls10();
      }
      else {
        uVar5 = (*pcVar1)(param_1,5,0,uVar6,0x4408);
      }
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar7 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar7 * 4);
          goto LAB_0024a587;
        }
LAB_0024a59c:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,uVar7);
LAB_0024a587:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024a59c;
      }
      pcVar1 = *(code **)(param_1 + 0x928);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      (*pcVar1)(param_1,5,0,uVar6,0x4408,uVar5 & 0xfffae8ff);
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar5 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar5 * 4);
          goto LAB_0024a636;
        }
LAB_0024a64b:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,(ulong)uVar5);
LAB_0024a636:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024a64b;
      }
      pcVar1 = *(code **)(param_1 + 0x920);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_eng_rd_ls10) {
        uVar5 = nvswitch_eng_rd_ls10();
      }
      else {
        uVar5 = (*pcVar1)(param_1,5,0,uVar6,0x4404);
      }
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar7 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar7 * 4);
          goto LAB_0024a6f0;
        }
LAB_0024a705:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,uVar7);
LAB_0024a6f0:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024a705;
      }
      pcVar1 = *(code **)(param_1 + 0x928);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      (*pcVar1)(param_1,5,0,uVar6,0x4404,uVar5 & 0xfffae8ff);
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar5 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar5 * 4);
          goto LAB_0024a79f;
        }
LAB_0024a7b4:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,(ulong)uVar5);
LAB_0024a79f:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024a7b4;
      }
      pcVar1 = *(code **)(param_1 + 0x920);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_eng_rd_ls10) {
        uVar5 = nvswitch_eng_rd_ls10();
      }
      else {
        uVar5 = (*pcVar1)(param_1,5,0,uVar6,0x440c);
      }
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar7 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar7 * 4);
          goto LAB_0024a859;
        }
LAB_0024a86e:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,uVar7);
LAB_0024a859:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024a86e;
      }
      pcVar1 = *(code **)(param_1 + 0x928);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      (*pcVar1)(param_1,5,0,uVar6,0x440c,uVar5 & 0xfffff7ff);
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar5 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar5 * 4);
          goto LAB_0024a908;
        }
LAB_0024a91d:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,(ulong)uVar5);
LAB_0024a908:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024a91d;
      }
      pcVar1 = *(code **)(param_1 + 0x920);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_eng_rd_ls10) {
        uVar5 = nvswitch_eng_rd_ls10();
      }
      else {
        uVar5 = (*pcVar1)(param_1,5,0,uVar6,0x1414);
      }
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar7 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar7 * 4);
          goto LAB_0024a9c2;
        }
LAB_0024a9d7:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,uVar7);
LAB_0024a9c2:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024a9d7;
      }
      pcVar1 = *(code **)(param_1 + 0x928);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      (*pcVar1)(param_1,5,0,uVar6,0x1414,uVar5 & 0xff9ffbbd);
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar5 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar5 * 4);
          goto LAB_0024aa71;
        }
LAB_0024aa86:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,(ulong)uVar5);
LAB_0024aa71:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024aa86;
      }
      pcVar1 = *(code **)(param_1 + 0x920);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_eng_rd_ls10) {
        uVar5 = nvswitch_eng_rd_ls10();
      }
      else {
        uVar5 = (*pcVar1)(param_1,5,0,uVar6,0x1408);
      }
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar7 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar7 * 4);
          goto LAB_0024ab2b;
        }
LAB_0024ab40:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,uVar7);
LAB_0024ab2b:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024ab40;
      }
      pcVar1 = *(code **)(param_1 + 0x928);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      (*pcVar1)(param_1,5,0,uVar6,0x1408,uVar5 & 0xff9ffbbd);
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar5 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar5 * 4);
          goto LAB_0024abda;
        }
LAB_0024abef:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,(ulong)uVar5);
LAB_0024abda:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024abef;
      }
      pcVar1 = *(code **)(param_1 + 0x920);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_eng_rd_ls10) {
        uVar5 = nvswitch_eng_rd_ls10();
      }
      else {
        uVar5 = (*pcVar1)(param_1,5,0,uVar6,0x1404);
      }
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar7 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar7 * 4);
          goto LAB_0024ac94;
        }
LAB_0024aca9:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,uVar7);
LAB_0024ac94:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024aca9;
      }
      pcVar1 = *(code **)(param_1 + 0x928);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      (*pcVar1)(param_1,5,0,uVar6,0x1404,uVar5 & 0xff9ffbbd);
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar5 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar5 * 4);
          goto LAB_0024ad43;
        }
LAB_0024ad58:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,(ulong)uVar5);
LAB_0024ad43:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024ad58;
      }
      pcVar1 = *(code **)(param_1 + 0x920);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_eng_rd_ls10) {
        uVar5 = nvswitch_eng_rd_ls10();
      }
      else {
        uVar5 = (*pcVar1)(param_1,5,0,uVar6,0x1704);
      }
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar7 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar7 * 4);
          goto LAB_0024adfd;
        }
LAB_0024ae12:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,uVar7);
LAB_0024adfd:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024ae12;
      }
      pcVar1 = *(code **)(param_1 + 0x928);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      (*pcVar1)(param_1,5,0,uVar6,0x1704,(ulong)(uVar5 >> 8) << 8);
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar5 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar5 * 4);
          goto LAB_0024aea8;
        }
LAB_0024aebd:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,(ulong)uVar5);
LAB_0024aea8:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024aebd;
      }
      pcVar1 = *(code **)(param_1 + 0x920);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_eng_rd_ls10) {
        uVar5 = nvswitch_eng_rd_ls10();
      }
      else {
        uVar5 = (*pcVar1)(param_1,5,0,uVar6,0x140c);
      }
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar7 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar7 * 4);
          goto LAB_0024af62;
        }
LAB_0024af77:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,uVar7);
LAB_0024af62:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024af77;
      }
      pcVar1 = *(code **)(param_1 + 0x928);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      (*pcVar1)(param_1,5,0,uVar6,0x140c,uVar5 & 0x61bf73);
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar5 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar5 * 4);
          goto LAB_0024b011;
        }
LAB_0024b026:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,(ulong)uVar5);
LAB_0024b011:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024b026;
      }
      pcVar1 = *(code **)(param_1 + 0x920);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_eng_rd_ls10) {
        uVar5 = nvswitch_eng_rd_ls10();
      }
      else {
        uVar5 = (*pcVar1)(param_1,5,0,uVar6,0x170c);
      }
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar7 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar7 * 4);
          goto LAB_0024b0cb;
        }
LAB_0024b0e0:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,uVar7);
LAB_0024b0cb:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024b0e0;
      }
      pcVar1 = *(code **)(param_1 + 0x928);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      (*pcVar1)(param_1,5,0,uVar6,0x170c,(ulong)(uVar5 >> 8) << 8);
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar5 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar5 * 4);
          goto LAB_0024b176;
        }
LAB_0024b18b:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,(ulong)uVar5);
LAB_0024b176:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024b18b;
      }
      pcVar1 = *(code **)(param_1 + 0x920);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_eng_rd_ls10) {
        uVar5 = nvswitch_eng_rd_ls10();
      }
      else {
        uVar5 = (*pcVar1)(param_1,5,0,uVar6,0x6414);
      }
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar7 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar7 * 4);
          goto LAB_0024b230;
        }
LAB_0024b245:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,uVar7);
LAB_0024b230:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024b245;
      }
      pcVar1 = *(code **)(param_1 + 0x928);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      (*pcVar1)(param_1,5,0,uVar6,0x6414,uVar5 & 0xffffffc1);
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar5 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar5 * 4);
          goto LAB_0024b2dc;
        }
LAB_0024b2f1:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,(ulong)uVar5);
LAB_0024b2dc:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024b2f1;
      }
      pcVar1 = *(code **)(param_1 + 0x920);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_eng_rd_ls10) {
        uVar5 = nvswitch_eng_rd_ls10();
      }
      else {
        uVar5 = (*pcVar1)(param_1,5,0,uVar6,0x6408);
      }
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar7 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar7 * 4);
          goto LAB_0024b396;
        }
LAB_0024b3ab:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,uVar7);
LAB_0024b396:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024b3ab;
      }
      pcVar1 = *(code **)(param_1 + 0x928);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      (*pcVar1)(param_1,5,0,uVar6,0x6408,uVar5 & 0xffffffc1);
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar5 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar5 * 4);
          goto LAB_0024b442;
        }
LAB_0024b457:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,(ulong)uVar5);
LAB_0024b442:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024b457;
      }
      pcVar1 = *(code **)(param_1 + 0x920);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_eng_rd_ls10) {
        uVar5 = nvswitch_eng_rd_ls10();
      }
      else {
        uVar5 = (*pcVar1)(param_1,5,0,uVar6,0x6404);
      }
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar7 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar7 * 4);
          goto LAB_0024b4fc;
        }
LAB_0024b511:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,uVar7);
LAB_0024b4fc:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024b511;
      }
      pcVar1 = *(code **)(param_1 + 0x928);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      (*pcVar1)(param_1,5,0,uVar6,0x6404,uVar5 & 0xffffffc1);
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar5 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar5 * 4);
          goto LAB_0024b5a8;
        }
LAB_0024b5bd:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,(ulong)uVar5);
LAB_0024b5a8:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024b5bd;
      }
      pcVar1 = *(code **)(param_1 + 0x920);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_eng_rd_ls10) {
        uVar5 = nvswitch_eng_rd_ls10();
      }
      else {
        uVar5 = (*pcVar1)(param_1,5,0,uVar6,0x640c);
      }
      pcVar1 = *(code **)(param_1 + 0x910);
      uVar7 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar2 = *(long *)(param_1 + 0x1f90);
        if (*(int *)(lVar2 + 0x5d0) != 5) {
          nvswitch_assert_log();
        }
        if (uVar7 < *(uint *)(lVar2 + 0x5d4)) {
          iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar7 * 4);
          goto LAB_0024b662;
        }
LAB_0024b677:
        nvswitch_assert_log();
      }
      else {
        iVar10 = (*pcVar1)(param_1,5,0,uVar7);
LAB_0024b662:
        if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
        goto LAB_0024b677;
      }
      pcVar1 = *(code **)(param_1 + 0x928);
      uVar6 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
      (*pcVar1)(param_1,5,0,uVar6,0x640c,uVar5 & 0xfffffffe);
      goto LAB_00249d8a;
    }
    uVar6 = nvswitch_set_nport_tprod_state_ls10(param_1,*param_2);
  }
  else {
LAB_00249d8a:
    uVar6 = 0;
  }
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
  if (pcVar1 == nvswitch_get_eng_base_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    lVar2 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar2 + 0x5d0) != 5) {
      nvswitch_assert_log();
    }
    if (uVar5 < *(uint *)(lVar2 + 0x5d4)) {
      iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar5 * 4);
      goto LAB_00249de7;
    }
LAB_00249dfc:
    nvswitch_assert_log();
  }
  else {
    iVar10 = (*pcVar1)(param_1,5,0,uVar5);
LAB_00249de7:
    if ((iVar10 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 == '\0'))
    goto LAB_00249dfc;
  }
  uVar3 = *(undefined8 *)(param_2 + 6);
  pcVar1 = *(code **)(param_1 + 0x928);
  uVar8 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
  (*pcVar1)(param_1,5,0,uVar8,0x74,uVar3);
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
  if (pcVar1 == nvswitch_get_eng_base_ls10) {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    lVar2 = *(long *)(param_1 + 0x1f90);
    if (*(int *)(lVar2 + 0x5d0) != 5) {
      nvswitch_assert_log();
    }
    if (uVar5 < *(uint *)(lVar2 + 0x5d4)) {
      iVar10 = *(int *)(lVar2 + 0x5d8 + (ulong)uVar5 * 4);
      goto LAB_00249e97;
    }
  }
  else {
    iVar10 = (*pcVar1)(param_1,5,0,uVar5);
LAB_00249e97:
    if ((iVar10 != -1) && (cVar4 = nvswitch_is_link_valid(param_1,*param_2), cVar4 != '\0'))
    goto LAB_00249eb1;
  }
  nvswitch_assert_log();
LAB_00249eb1:
  uVar8 = param_2[7];
  pcVar1 = *(code **)(param_1 + 0x928);
  uVar9 = nvswitch_get_link_eng_inst(param_1,*param_2,5);
  (*pcVar1)(param_1,5,0,uVar9,0x78,uVar8);
  return uVar6;
}


// ===== 0024bc60 nvswitch_set_ganged_link_table_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_set_ganged_link_table_ls10(long param_1,uint param_2,undefined4 *param_3,uint param_4)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  cVar1 = nvswitch_is_tnvl_mode_locked();
  if (cVar1 == '\0') {
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x5080,param_2 & 0xff | 0x80000000);
    if (param_4 != 0) {
      puVar2 = param_3;
      do {
        puVar3 = puVar2 + 2;
        (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x5094,puVar2[1]);
        (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x5098,0);
        (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x5090,*puVar2);
        puVar2 = puVar3;
      } while (puVar3 != param_3 + (ulong)param_4 * 2);
    }
  }
  return;
}


// ===== 0024bd52 nvswitch_initialize_route_ls10.cold =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nvswitch_initialize_route_ls10_cold(void)

{
  code *pcVar1;
  
  _DAT_0000dde0 = nvswitch_os_malloc_trace(0x28d0,0,0);
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0024bd80 nvswitch_initialize_route_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int nvswitch_initialize_route_ls10(long param_1)

{
  code *pcVar1;
  byte bVar2;
  int iVar3;
  long lVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  long lVar7;
  ulong uVar8;
  byte bVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  undefined4 local_98 [24];
  undefined4 local_38 [2];
  
  lVar7 = 0;
  if (*(int *)(param_1 + 0x1f88) == 7) {
    lVar7 = *(long *)(param_1 + 0x1f90);
  }
  lVar4 = nvswitch_os_malloc_trace(0x800,0,0);
  if (lVar4 == 0) {
    iVar3 = -2;
  }
  else {
    uVar11 = 0;
    do {
      uVar10 = 0;
      uVar8 = 0;
      uVar12 = 0x10;
      bVar9 = 0xfc;
      do {
        iVar3 = (int)uVar8;
        bVar2 = (char)uVar8 * '\x04';
        uVar8 = (ulong)(iVar3 + 1);
        uVar10 = uVar10 | ((uVar11 & 0xffffffff) % uVar12 &
                          0xffffffffffffffffU >> ((bVar9 & 0x3c) + bVar2 & 0x3f)) << (bVar2 & 0x3f);
        uVar12 = uVar8;
        bVar9 = bVar9 - 4;
      } while (iVar3 != 0xf);
      *(ulong *)(lVar4 + uVar11 * 8) = uVar10;
      uVar11 = uVar11 + 1;
    } while (uVar11 != 0x100);
    nvswitch_set_ganged_link_table_ls10(param_1,0,lVar4,0x100);
    *(long *)(lVar7 + 0xde90) = lVar4;
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x50a0,0);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x50a8,0x22);
    if (*(int *)(param_1 + 0x1f88) != 7) {
      _DAT_0000dde0 = nvswitch_os_malloc_trace(0x28d0,0,0);
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    lVar7 = *(long *)(param_1 + 0x1f90);
    lVar4 = nvswitch_os_malloc_trace(0x28d0,0,0);
    *(long *)(&DAT_0000dde0 + lVar7) = lVar4;
    if (lVar4 == 0) {
      iVar3 = -2;
    }
    else {
      nvswitch_os_memset(lVar4,0,0x28d0);
      puVar5 = local_98;
      do {
        *puVar5 = 0x78;
        puVar6 = puVar5 + 3;
        puVar5[1] = 200;
        puVar5[2] = 1000;
        puVar5 = puVar6;
      } while (local_38 != puVar6);
      **(undefined4 **)(&DAT_0000dde0 + lVar7) = 21600000;
      iVar3 = nvswitch_ctrl_set_latency_bins(param_1);
      if (iVar3 != 0) {
        nvswitch_assert_log();
        return iVar3;
      }
      (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x100,0);
      (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x2a8,0xffffffff);
      (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x2ac,0xffffffff);
      (**(code **)(param_1 + 0x928))(param_1,1,0,0,0x40,1);
      (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x104,1);
      (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x2734,3);
      (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x2734,1);
      (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x2f34,3);
      (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x2f34,1);
      (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x2700,3);
      (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x2700,1);
      (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x2f00,3);
      (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x2f00,1);
      iVar3 = 0;
    }
  }
  return iVar3;
}


// ===== 0024c1a0 nvswitch_link_disable_interrupts_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_link_disable_interrupts_ls10(long param_1,ulong param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  
  uVar4 = param_2 >> 2 & 0x3fffffff;
  uVar2 = (uint)param_2 & 3;
  cVar1 = nvswitch_is_soe_supported();
  if (cVar1 == '\0') {
    (**(code **)(param_1 + 0x928))(param_1,5,0,param_2 & 0xffffffff,0x470,0);
  }
  else {
    nvswitch_soe_set_nport_interrupts_ls10(param_1,param_2 & 0xffffffff,0);
  }
  iVar3 = uVar2 * 0x40;
  (**(code **)(param_1 + 0x928))(param_1,6,0,uVar4,(uVar2 + 0xc) * 0x40,0);
  (**(code **)(param_1 + 0x928))(param_1,6,0,uVar4,iVar3 + 0x308,0);
  (**(code **)(param_1 + 0x928))(param_1,6,0,uVar4,iVar3 + 0x310,0);
  return;
}


// ===== 0024c282 _nvswitch_reset_and_drain_links_ls10.cold =====

void _nvswitch_reset_and_drain_links_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0024c2d0 _nvswitch_reset_and_drain_links_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */
/* WARNING: Function: __x86_indirect_thunk_rbx replaced with injection: x86_indirect_thunk_rbx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

undefined8 _nvswitch_reset_and_drain_links_ls10(undefined8 *param_1,ulong param_2,char param_3)

{
  code *pcVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  long lVar9;
  ulong uVar10;
  undefined8 uVar11;
  long lVar12;
  ulong uVar13;
  int iVar14;
  long lVar15;
  uint local_70;
  int local_5c;
  uint local_48;
  uint local_44;
  undefined1 local_40 [16];
  
  lVar15 = 0;
  if (*(int *)(param_1 + 0x3f1) == 7) {
    lVar15 = param_1[0x3f2];
  }
  if (param_2 == 0) {
    return 0xffffffff;
  }
  iVar14 = 0;
  uVar13 = param_2;
joined_r0x0024c323:
  for (; (uVar13 & 1) == 0; uVar13 = uVar13 >> 1) {
    iVar14 = iVar14 + 1;
  }
  cVar2 = nvswitch_is_link_valid(param_1,iVar14);
  if (cVar2 != '\0') {
    pcVar1 = (code *)param_1[0x122];
    uVar4 = nvswitch_get_link_eng_inst(param_1,iVar14,5);
    if (pcVar1 == nvswitch_get_eng_base_ls10) {
      if (*(int *)(param_1 + 0x3f1) != 7) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)invalidInstructionException();
        (*pcVar1)();
      }
      lVar9 = param_1[0x3f2];
      if (*(int *)(lVar9 + 0x5d0) != 5) {
        nvswitch_assert_log();
      }
      if (*(uint *)(lVar9 + 0x5d4) <= uVar4) goto LAB_0024c430;
      iVar7 = *(int *)(lVar9 + 0x5d8 + (ulong)uVar4 * 4);
    }
    else {
      iVar7 = (*pcVar1)(param_1,5,0,uVar4);
    }
    if ((iVar7 != -1) && (cVar2 = nvswitch_is_link_valid(param_1,iVar14), cVar2 != '\0')) {
      pcVar1 = (code *)param_1[0x122];
      uVar4 = nvswitch_get_link_eng_inst(param_1,iVar14,6);
      if (pcVar1 == nvswitch_get_eng_base_ls10) {
        if (*(int *)(param_1 + 0x3f1) != 7) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar9 = param_1[0x3f2];
        if (*(int *)(lVar9 + 0x6f8) != 6) {
          nvswitch_assert_log();
        }
        if (*(uint *)(lVar9 + 0x6fc) <= uVar4) goto LAB_0024c430;
        iVar7 = *(int *)(lVar9 + 0x700 + (ulong)uVar4 * 4);
      }
      else {
        iVar7 = (*pcVar1)(param_1,6,0,uVar4);
      }
      if (iVar7 != -1) {
        nvswitch_is_link_valid(param_1,iVar14);
      }
    }
  }
LAB_0024c430:
  if (uVar13 >> 1 != 0) {
    iVar14 = iVar14 + 1;
    uVar13 = uVar13 >> 1;
    goto joined_r0x0024c323;
  }
  local_5c = 3;
  uVar13 = 0;
LAB_0024c4fd:
  uVar4 = (uint)uVar13;
  if ((param_2 & 1) != 0) {
    lVar9 = nvswitch_get_link(param_1,uVar13 & 0xff);
    if ((lVar9 != 0) && (cVar2 = nvswitch_is_link_in_reset(param_1,lVar9), cVar2 == '\0')) {
      nvlink_lib_unregister_link(lVar9);
      if ((code *)param_1[0x124] == nvswitch_eng_rd_ls10) {
        uVar10 = nvswitch_eng_rd_ls10();
      }
      else {
        uVar10 = (*(code *)param_1[0x124])(param_1,5,0,uVar13 & 0xffffffff,0x4400);
      }
      if ((uVar10 & 0x201d) == 0) {
        nvswitch_link_disable_interrupts_ls10(param_1,uVar13 & 0xffffffff);
        if (param_3 == '\0') {
          nvswitch_timeout_create(10000000,local_40);
          do {
            cVar2 = nvswitch_timeout_check(local_40);
            iVar14 = nvswitch_minion_get_dl_status
                               (param_1,*(undefined4 *)(lVar9 + 0x38),1,0,&local_48);
            if ((iVar14 == 0) && ((short)local_48 == 0x29)) goto LAB_0024c5bc;
          } while (cVar2 == '\0');
        }
        else {
          nvswitch_execute_unilateral_link_shutdown_ls10(lVar9);
LAB_0024c5bc:
          nvswitch_corelib_clear_link_state_lr10(lVar9);
          nvswitch_soe_issue_nport_reset_ls10(param_1,uVar4);
          do {
            iVar14 = nvswitch_request_tl_link_state_ls10(lVar9,9,1);
            if (iVar14 == 0) {
              nvswitch_soe_restore_nport_state_ls10(param_1,uVar13 & 0xffffffff);
              uVar6 = uVar4 >> 2;
              local_70 = uVar4 & 3;
              cVar2 = nvswitch_is_soe_supported(param_1);
              if (cVar2 == '\0') {
                (*(code *)param_1[0x125])(param_1,5,0,uVar13 & 0xffffffff,0x470,7);
              }
              else {
                nvswitch_soe_set_nport_interrupts_ls10(param_1,uVar13 & 0xffffffff,1);
              }
              (*(code *)param_1[0x125])(param_1,6,0,uVar6,(local_70 + 0xc) * 0x40,9);
              (*(code *)param_1[0x125])(param_1,6,0,uVar6,local_70 * 0x40 + 0x308,0x16);
              (*(code *)param_1[0x125])(param_1,6,0,uVar6,local_70 * 0x40 + 0x310,0);
              pcVar1 = (code *)param_1[0x122];
              uVar6 = nvswitch_get_link_eng_inst(param_1,uVar13 & 0xffffffff,9);
              if (pcVar1 == nvswitch_get_eng_base_ls10) {
                if (*(int *)(param_1 + 0x3f1) != 7) {
                    /* WARNING: Does not return */
                  pcVar1 = (code *)invalidInstructionException();
                  (*pcVar1)();
                }
                lVar12 = param_1[0x3f2];
                if (*(int *)(lVar12 + 0xa70) != 9) {
                  nvswitch_assert_log();
                }
                if (uVar6 < *(uint *)(lVar12 + 0xa74)) {
                  iVar14 = *(int *)(lVar12 + 0xa78 + (ulong)uVar6 * 4);
                  goto LAB_0024cd40;
                }
LAB_0024c87b:
                nvswitch_assert_log();
              }
              else {
                iVar14 = (*pcVar1)(param_1,9,0,uVar6);
LAB_0024cd40:
                if ((iVar14 == -1) ||
                   (cVar2 = nvswitch_is_link_valid(param_1,uVar13 & 0xffffffff), cVar2 == '\0'))
                goto LAB_0024c87b;
              }
              pcVar1 = (code *)param_1[0x124];
              uVar5 = nvswitch_get_link_eng_inst(param_1,uVar13 & 0xffffffff,9);
              if (pcVar1 == nvswitch_eng_rd_ls10) {
                uVar6 = nvswitch_eng_rd_ls10();
              }
              else {
                uVar6 = (*pcVar1)(param_1,9,0,uVar5,0x300);
              }
              pcVar1 = (code *)param_1[0x122];
              uVar8 = nvswitch_get_link_eng_inst(param_1,uVar13 & 0xffffffff,9);
              if (pcVar1 == nvswitch_get_eng_base_ls10) {
                if (*(int *)(param_1 + 0x3f1) != 7) {
                    /* WARNING: Does not return */
                  pcVar1 = (code *)invalidInstructionException();
                  (*pcVar1)();
                }
                lVar12 = param_1[0x3f2];
                if (*(int *)(lVar12 + 0xa70) != 9) {
                  nvswitch_assert_log();
                }
                if (uVar8 < *(uint *)(lVar12 + 0xa74)) {
                  iVar14 = *(int *)(lVar12 + 0xa78 + (ulong)uVar8 * 4);
                  goto LAB_0024cd17;
                }
LAB_0024c91e:
                nvswitch_assert_log();
              }
              else {
                iVar14 = (*pcVar1)(param_1,9,0,uVar8);
LAB_0024cd17:
                if ((iVar14 == -1) ||
                   (cVar2 = nvswitch_is_link_valid(param_1,uVar13 & 0xffffffff), cVar2 == '\0'))
                goto LAB_0024c91e;
              }
              pcVar1 = (code *)param_1[0x125];
              uVar5 = nvswitch_get_link_eng_inst(param_1,uVar13 & 0xffffffff,9);
              (*pcVar1)(param_1,9,0,uVar5,0x300,uVar6 | 3);
              pcVar1 = (code *)param_1[0x122];
              uVar6 = nvswitch_get_link_eng_inst(param_1,uVar13 & 0xffffffff,9);
              if (pcVar1 == nvswitch_get_eng_base_ls10) {
                if (*(int *)(param_1 + 0x3f1) != 7) {
                    /* WARNING: Does not return */
                  pcVar1 = (code *)invalidInstructionException();
                  (*pcVar1)();
                }
                lVar12 = param_1[0x3f2];
                if (*(int *)(lVar12 + 0xa70) != 9) {
                  nvswitch_assert_log();
                }
                if (uVar6 < *(uint *)(lVar12 + 0xa74)) {
                  iVar14 = *(int *)(lVar12 + 0xa78 + (ulong)uVar6 * 4);
                  goto LAB_0024ccee;
                }
LAB_0024c9b9:
                nvswitch_assert_log();
              }
              else {
                iVar14 = (*pcVar1)(param_1,9,0,uVar6);
LAB_0024ccee:
                if ((iVar14 == -1) ||
                   (cVar2 = nvswitch_is_link_valid(param_1,uVar13 & 0xffffffff), cVar2 == '\0'))
                goto LAB_0024c9b9;
              }
              pcVar1 = (code *)param_1[0x124];
              uVar5 = nvswitch_get_link_eng_inst(param_1,uVar13 & 0xffffffff,9);
              if (pcVar1 == nvswitch_eng_rd_ls10) {
                uVar6 = nvswitch_eng_rd_ls10();
              }
              else {
                uVar6 = (*pcVar1)(param_1,9,0,uVar5,0x30c);
              }
              pcVar1 = (code *)param_1[0x122];
              uVar8 = nvswitch_get_link_eng_inst(param_1,uVar13 & 0xffffffff,9);
              if (pcVar1 == nvswitch_get_eng_base_ls10) {
                if (*(int *)(param_1 + 0x3f1) != 7) {
                    /* WARNING: Does not return */
                  pcVar1 = (code *)invalidInstructionException();
                  (*pcVar1)();
                }
                lVar12 = param_1[0x3f2];
                if (*(int *)(lVar12 + 0xa70) != 9) {
                  nvswitch_assert_log();
                }
                if (uVar8 < *(uint *)(lVar12 + 0xa74)) {
                  iVar14 = *(int *)(lVar12 + 0xa78 + (ulong)uVar8 * 4);
                  goto LAB_0024ca61;
                }
LAB_0024ca74:
                nvswitch_assert_log();
              }
              else {
                iVar14 = (*pcVar1)(param_1,9,0,uVar8);
LAB_0024ca61:
                if ((iVar14 == -1) ||
                   (cVar2 = nvswitch_is_link_valid(param_1,uVar13 & 0xffffffff), cVar2 == '\0'))
                goto LAB_0024ca74;
              }
              pcVar1 = (code *)param_1[0x125];
              uVar5 = nvswitch_get_link_eng_inst(param_1,uVar13 & 0xffffffff,9);
              (*pcVar1)(param_1,9,0,uVar5,0x30c,uVar6 | 1);
              *(undefined1 *)(param_1 + uVar13 * 8 + 0x1ed) = 0;
              iVar14 = nvlink_lib_register_link(*param_1,lVar9);
              if (iVar14 != 0) goto LAB_0024c560;
              pcVar1 = (code *)param_1[0x122];
              uVar6 = nvswitch_get_link_eng_inst(param_1,uVar13 & 0xffffffff,5);
              if (pcVar1 == nvswitch_get_eng_base_ls10) {
                if (*(int *)(param_1 + 0x3f1) != 7) {
                    /* WARNING: Does not return */
                  pcVar1 = (code *)invalidInstructionException();
                  (*pcVar1)();
                }
                lVar12 = param_1[0x3f2];
                if (*(int *)(lVar12 + 0x5d0) != 5) {
                  nvswitch_assert_log();
                }
                if (uVar6 < *(uint *)(lVar12 + 0x5d4)) {
                  iVar14 = *(int *)(lVar12 + 0x5d8 + (ulong)uVar6 * 4);
                  goto LAB_0024cb46;
                }
LAB_0024cb59:
                nvswitch_assert_log();
              }
              else {
                iVar14 = (*pcVar1)(param_1,5,0,uVar6);
LAB_0024cb46:
                if ((iVar14 == -1) ||
                   (cVar2 = nvswitch_is_link_valid(param_1,uVar13 & 0xffffffff), cVar2 == '\0'))
                goto LAB_0024cb59;
              }
              pcVar1 = (code *)param_1[0x125];
              uVar5 = nvswitch_get_link_eng_inst(param_1,uVar13 & 0xffffffff,5);
              (*pcVar1)(param_1,5,0,uVar5,0xfc0,0);
              cVar2 = cciIsLinkManaged(param_1,uVar13 & 0xffffffff);
              if ((cVar2 == '\0') &&
                 (iVar14 = nvswitch_request_tl_link_state_ls10(lVar9,1,0), iVar14 != 0))
              goto LAB_0024c4f4;
              nvswitch_timeout_create(1000000,local_40);
              goto LAB_0024cbf9;
            }
            pcVar1 = (code *)param_1[0x122];
            uVar6 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar9 + 0x38),9);
            if (pcVar1 == nvswitch_get_eng_base_ls10) {
              if (*(int *)(param_1 + 0x3f1) != 7) {
                    /* WARNING: Does not return */
                pcVar1 = (code *)invalidInstructionException();
                (*pcVar1)();
              }
              lVar12 = param_1[0x3f2];
              if (*(int *)(lVar12 + 0xa70) != 9) {
                nvswitch_assert_log();
              }
              if (uVar6 < *(uint *)(lVar12 + 0xa74)) {
                iVar14 = *(int *)(lVar12 + 0xa78 + (ulong)uVar6 * 4);
                goto LAB_0024c61d;
              }
LAB_0024c633:
              nvswitch_assert_log();
            }
            else {
              iVar14 = (*pcVar1)(param_1,9,0,uVar6);
LAB_0024c61d:
              if ((iVar14 == -1) ||
                 (cVar2 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar9 + 0x38)),
                 cVar2 == '\0')) goto LAB_0024c633;
            }
            pcVar1 = (code *)param_1[0x124];
            uVar5 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar9 + 0x38),9);
            if (pcVar1 == nvswitch_eng_rd_ls10) {
              uVar6 = nvswitch_eng_rd_ls10();
            }
            else {
              uVar6 = (*pcVar1)(param_1,9,0,uVar5,0x480);
            }
            iVar14 = nvswitch_minion_get_dl_status
                               (param_1,*(undefined4 *)(lVar9 + 0x38),0xff,0,&local_48);
          } while (((iVar14 != 0) ||
                   (((local_48 & 0xff00) == 0x5000 && ((uVar6 & 0xff00) == 0x8000)))) &&
                  (local_5c = local_5c + -1, local_5c != 0));
        }
      }
      iVar14 = nvlink_lib_register_link(*param_1,lVar9);
      if (iVar14 != 0) {
LAB_0024c560:
        nvswitch_destroy_link(lVar9);
      }
    }
    goto LAB_0024c4f4;
  }
  goto LAB_0024c4f9;
LAB_0024cbf9:
  do {
    cVar2 = nvswitch_timeout_check(local_40);
    lVar12 = nvswitch_get_link(param_1,uVar13 & 0xff);
    if ((lVar12 != 0) &&
       (iVar14 = nvswitch_minion_get_dl_status(param_1,uVar13 & 0xffffffff,1,0,&local_44),
       iVar14 == 0)) {
      uVar6 = local_44 & 0xffff;
      if (uVar6 == 0x13) {
LAB_0024cc42:
        cVar3 = nvswitch_are_link_clocks_on_ls10(param_1,lVar12,3);
        if (cVar3 == '\0') goto LAB_0024cbf0;
      }
      else if (uVar6 < 0x14) {
        if ((local_44 & 0xfffe) == 0) goto LAB_0024cbf0;
      }
      else if (uVar6 == 0x25) goto LAB_0024cc42;
      nvswitch_set_dlpl_interrupts_ls10(lVar9);
      break;
    }
LAB_0024cbf0:
  } while (cVar2 == '\0');
LAB_0024c4f4:
  if (param_2 >> 1 == 0) {
    uVar11 = nvswitch_os_get_platform_time();
    *(undefined8 *)(lVar15 + 57000 + (ulong)(uVar4 + 1) * 0x60) = uVar11;
    return 0;
  }
LAB_0024c4f9:
  param_2 = param_2 >> 1;
  uVar13 = uVar13 + 1;
  goto LAB_0024c4fd;
}


// ===== 0024ce80 nvswitch_reset_and_drain_links_ls10 =====

int nvswitch_reset_and_drain_links_ls10(undefined8 param_1,ulong param_2,undefined1 param_3)

{
  char cVar1;
  ulong uVar2;
  int iVar3;
  
  if (param_2 != 0) {
    iVar3 = 0;
    uVar2 = param_2;
    while( true ) {
      for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1) {
        iVar3 = iVar3 + 1;
      }
      cVar1 = cciIsLinkManaged(param_1,iVar3);
      if (cVar1 != '\0') {
        param_2 = ~(1L << ((byte)iVar3 & 0x3f)) & param_2;
      }
      if (uVar2 >> 1 == 0) break;
      iVar3 = iVar3 + 1;
      uVar2 = uVar2 >> 1;
    }
  }
  cVar1 = nvswitch_is_tnvl_mode_locked(param_1);
  if (cVar1 == '\0') {
    iVar3 = _nvswitch_reset_and_drain_links_ls10(param_1,param_2,param_3);
    iVar3 = -(uint)(iVar3 != 0);
  }
  else {
    iVar3 = -0xf;
  }
  return iVar3;
}


// ===== 0024cf30 nvswitch_cci_reset_and_drain_links_ls10 =====

void nvswitch_cci_reset_and_drain_links_ls10(undefined8 param_1,ulong param_2,undefined1 param_3)

{
  char cVar1;
  ulong uVar2;
  int iVar3;
  
  if (param_2 != 0) {
    iVar3 = 0;
    uVar2 = param_2;
    while( true ) {
      for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1) {
        iVar3 = iVar3 + 1;
      }
      cVar1 = cciIsLinkManaged(param_1,iVar3);
      if (cVar1 == '\0') {
        param_2 = ~(1L << ((byte)iVar3 & 0x3f)) & param_2;
      }
      if (uVar2 >> 1 == 0) break;
      iVar3 = iVar3 + 1;
      uVar2 = uVar2 >> 1;
    }
  }
  _nvswitch_reset_and_drain_links_ls10(param_1,param_2,param_3);
  return;
}


// ===== 0024cfc0 nvswitch_setup_hal_ls10 =====

void nvswitch_setup_hal_ls10(long param_1)

{
  *(code **)(param_1 + 0x4f8) = nvswitch_initialize_device_state_ls10;
  *(undefined8 *)(param_1 + 0x1f80) = 0x100000003;
  *(code **)(param_1 + 0x500) = nvswitch_destroy_device_state_ls10;
  *(code **)(param_1 + 0x508) = nvswitch_determine_platform_lr10;
  *(code **)(param_1 + 0x510) = nvswitch_get_num_links_ls10;
  *(code **)(param_1 + 0x518) = nvswitch_get_num_links_per_nvlipt_ls10;
  *(code **)(param_1 + 0x520) = nvswitch_is_link_valid_lr10;
  *(code **)(param_1 + 0x528) = nvswitch_set_fatal_error_ls10;
  *(code **)(param_1 + 0x530) = nvswitch_get_swap_clk_default_lr10;
  *(code **)(param_1 + 0x538) = nvswitch_get_latency_sample_interval_msec_ls10;
  *(code **)(param_1 + 0x540) = nvswitch_internal_latency_bin_log_ls10;
  *(code **)(param_1 + 0x548) = nvswitch_ecc_writeback_task_lr10;
  *(code **)(param_1 + 0x550) = nvswitch_monitor_thermal_alert_ls10;
  *(code **)(param_1 + 0x558) = nvswitch_hw_counter_shutdown_lr10;
  *(code **)(param_1 + 0x560) = nvswitch_get_rom_info_ls10;
  *(code **)(param_1 + 0x568) = nvswitch_lib_enable_interrupts_ls10;
  *(code **)(param_1 + 0x570) = nvswitch_lib_disable_interrupts_ls10;
  *(code **)(param_1 + 0x578) = nvswitch_lib_check_interrupts_ls10;
  *(code **)(param_1 + 0x580) = nvswitch_lib_service_interrupts_ls10;
  *(code **)(param_1 + 0x588) = nvswitch_hw_counter_read_counter_lr10;
  *(code **)(param_1 + 0x590) = nvswitch_is_link_in_use_lr10;
  *(code **)(param_1 + 0x598) = nvswitch_reset_and_drain_links_ls10;
  *(code **)(param_1 + 0x5a0) = nvswitch_ctrl_get_info_lr10;
  *(code **)(param_1 + 0x5a8) = nvswitch_ctrl_get_nvlink_status_ls10;
  *(code **)(param_1 + 0x5b0) = nvswitch_ctrl_get_counters_ls10;
  *(code **)(param_1 + 0x5b8) = nvswitch_ctrl_set_switch_port_config_lr10;
  *(code **)(param_1 + 0x5c0) = nvswitch_set_nport_port_config_ls10;
  *(code **)(param_1 + 0x5c8) = nvswitch_ctrl_get_ingress_request_table_lr10;
  *(code **)(param_1 + 0x5d0) = nvswitch_ctrl_set_ingress_request_table_lr10;
  *(code **)(param_1 + 0x5d8) = nvswitch_ctrl_set_ingress_request_valid_lr10;
  *(code **)(param_1 + 0x5e0) = nvswitch_ctrl_get_ingress_response_table_lr10;
  *(code **)(param_1 + 0x5e8) = nvswitch_ctrl_set_ingress_response_table_lr10;
  *(code **)(param_1 + 0x5f0) = nvswitch_ctrl_set_ganged_link_table_ls10;
  *(code **)(param_1 + 0x5f8) = nvswitch_init_npg_multicast_ls10;
  *(code **)(param_1 + 0x600) = nvswitch_init_warm_reset_ls10;
  *(code **)(param_1 + 0x608) = nvswitch_ctrl_set_remap_policy_ls10;
  *(code **)(param_1 + 0x610) = nvswitch_ctrl_get_remap_policy_ls10;
  *(code **)(param_1 + 0x618) = nvswitch_ctrl_set_remap_policy_valid_ls10;
  *(code **)(param_1 + 0x620) = nvswitch_ctrl_set_routing_id_lr10;
  *(code **)(param_1 + 0x628) = nvswitch_ctrl_get_routing_id_lr10;
  *(code **)(param_1 + 0x630) = nvswitch_ctrl_set_routing_id_valid_lr10;
  *(code **)(param_1 + 0x638) = nvswitch_ctrl_set_routing_lan_lr10;
  *(code **)(param_1 + 0x640) = nvswitch_ctrl_get_routing_lan_lr10;
  *(code **)(param_1 + 0x648) = nvswitch_ctrl_set_routing_lan_valid_lr10;
  *(code **)(param_1 + 0x650) = nvswitch_ctrl_get_internal_latency_ls10;
  *(code **)(param_1 + 0x658) = nvswitch_ctrl_set_latency_bins_ls10;
  *(code **)(param_1 + 0x660) = nvswitch_ctrl_get_ingress_reqlinkid_ls10;
  *(code **)(param_1 + 0x668) = nvswitch_i2c_get_port_info_ls10;
  *(code **)(param_1 + 0x670) = nvswitch_ctrl_register_read_ls10;
  *(code **)(param_1 + 0x678) = nvswitch_ctrl_register_write_ls10;
  *(code **)(param_1 + 0x680) = nvswitch_ctrl_i2c_indexed_ls10;
  *(code **)(param_1 + 0x688) = nvswitch_ctrl_therm_read_temperature_ls10;
  *(code **)(param_1 + 0x690) = nvswitch_ctrl_therm_get_temperature_limit_ls10;
  *(code **)(param_1 + 0x698) = nvswitch_ctrl_get_throughput_counters_lr10;
  *(code **)(param_1 + 0x6a0) = nvswitch_corelib_add_link_lr10;
  *(code **)(param_1 + 0x6a8) = nvswitch_corelib_remove_link_lr10;
  *(code **)(param_1 + 0x6b0) = nvswitch_corelib_set_dl_link_mode_ls10;
  *(code **)(param_1 + 0x6b8) = nvswitch_corelib_get_dl_link_mode_ls10;
  *(code **)(param_1 + 0x6c0) = nvswitch_corelib_set_tl_link_mode_lr10;
  *(code **)(param_1 + 0x6c8) = nvswitch_corelib_get_tl_link_mode_ls10;
  *(code **)(param_1 + 0x6d0) = nvswitch_corelib_set_tx_mode_ls10;
  *(code **)(param_1 + 0x6d8) = nvswitch_corelib_get_tx_mode_ls10;
  *(code **)(param_1 + 0x6e0) = nvswitch_corelib_set_rx_mode_lr10;
  *(code **)(param_1 + 0x6e8) = nvswitch_corelib_get_rx_mode_ls10;
  *(code **)(param_1 + 0x6f0) = nvswitch_corelib_set_rx_detect_lr10;
  *(code **)(param_1 + 0x6f8) = nvswitch_corelib_get_rx_detect_ls10;
  *(code **)(param_1 + 0x700) = nvswitch_corelib_training_complete_ls10;
  *(code **)(param_1 + 0x708) = nvswitch_get_device_dma_width_ls10;
  *(code **)(param_1 + 0x710) = nvswitch_get_link_ip_version_ls10;
  *(code **)(param_1 + 0x718) = nvswitch_ctrl_get_fom_values_ls10;
  *(code **)(param_1 + 0x720) = nvswitch_deassert_link_reset_lr10;
  *(code **)(param_1 + 0x728) = nvswitch_is_soe_supported_ls10;
  *(code **)(param_1 + 0x730) = nvswitch_init_soe_ls10;
  *(code **)(param_1 + 0x738) = nvswitch_is_inforom_supported_ls10;
  *(code **)(param_1 + 0x740) = nvswitch_is_spi_supported_ls10;
  *(code **)(param_1 + 0x748) = nvswitch_is_bios_supported_ls10;
  *(code **)(param_1 + 0x750) = nvswitch_get_bios_size_ls10;
  *(code **)(param_1 + 0x758) = nvswitch_is_smbpbi_supported_ls10;
  *(code **)(param_1 + 0x760) = nvswitch_post_init_device_setup_lr10;
  *(code **)(param_1 + 0x768) = nvswitch_post_init_blacklist_device_setup_ls10;
  *(code **)(param_1 + 0x770) = nvswitch_setup_system_registers_lr10;
  *(code **)(param_1 + 0x778) = nvswitch_setup_link_system_registers_ls10;
  *(code **)(param_1 + 0x780) = nvswitch_load_link_disable_settings_ls10;
  *(code **)(param_1 + 0x788) = nvswitch_read_vbios_link_entries_ls10;
  *(code **)(param_1 + 0x790) = nvswitch_vbios_read_structure_lr10;
  *(code **)(param_1 + 0x798) = nvswitch_get_nvlink_ecc_errors_ls10;
  *(code **)(param_1 + 0x7a0) = nvswitch_inforom_ecc_log_error_event_lr10;
  *(code **)(param_1 + 0x7a8) = nvswitch_oms_set_device_disable_ls10;
  *(code **)(param_1 + 0x7b0) = nvswitch_oms_get_device_disable_ls10;
  *(code **)(param_1 + 0x7b8) = nvswitch_inforom_nvl_log_error_event_ls10;
  *(code **)(param_1 + 0x7c0) = nvswitch_inforom_nvl_update_link_correctable_error_info_ls10;
  *(code **)(param_1 + 0x7c8) = nvswitch_inforom_nvl_get_max_correctable_error_rate_ls10;
  *(code **)(param_1 + 2000) = nvswitch_inforom_nvl_get_errors_ls10;
  *(code **)(param_1 + 0x7d8) = nvswitch_inforom_nvl_setL1Threshold_ls10;
  *(code **)(param_1 + 0x7e0) = nvswitch_inforom_nvl_getL1Threshold_ls10;
  *(code **)(param_1 + 0x7e8) = nvswitch_inforom_nvl_setup_nvlink_state_ls10;
  *(code **)(param_1 + 0x7f0) = nvswitch_inforom_ecc_get_errors_lr10;
  *(code **)(param_1 + 0x7f8) = nvswitch_load_uuid_ls10;
  *(code **)(param_1 + 0x800) = nvswitch_i2c_set_hw_speed_mode_lr10;
  *(code **)(param_1 + 0x808) = nvswitch_ctrl_get_bios_info_ls10;
  *(code **)(param_1 + 0x810) = nvswitch_ctrl_get_inforom_version_ls10;
  *(code **)(param_1 + 0x818) = nvswitch_read_oob_blacklist_state_lr10;
  *(code **)(param_1 + 0x820) = nvswitch_write_fabric_state_ls10;
  *(code **)(param_1 + 0x828) = nvswitch_initialize_oms_state_ls10;
  *(code **)(param_1 + 0x830) = nvswitch_oms_inforom_flush_ls10;
  *(code **)(param_1 + 0x838) = nvswitch_inforom_ecc_get_total_errors_ls10;
  *(code **)(param_1 + 0x840) = nvswitch_inforom_load_obd_ls10;
  *(code **)(param_1 + 0x848) = nvswitch_bbx_add_sxid_ls10;
  *(code **)(param_1 + 0x850) = nvswitch_bbx_unload_ls10;
  *(code **)(param_1 + 0x858) = nvswitch_bbx_load_ls10;
  *(code **)(param_1 + 0x860) = nvswitch_bbx_get_sxid_ls10;
  *(code **)(param_1 + 0x868) = nvswitch_bbx_get_data_ls10;
  *(code **)(param_1 + 0x870) = nvswitch_smbpbi_alloc_ls10;
  *(code **)(param_1 + 0x878) = nvswitch_smbpbi_post_init_hal_ls10;
  *(code **)(param_1 + 0x880) = nvswitch_smbpbi_destroy_hal_ls10;
  *(code **)(param_1 + 0x888) = nvswitch_smbpbi_send_unload_ls10;
  *(code **)(param_1 + 0x890) = nvswitch_smbpbi_dem_load_ls10;
  *(code **)(param_1 + 0x898) = nvswitch_smbpbi_dem_flush_ls10;
  *(code **)(param_1 + 0x8a0) = nvswitch_smbpbi_get_dem_num_messages_ls10;
  *(code **)(param_1 + 0x8a8) = nvswitch_smbpbi_log_message_ls10;
  *(code **)(param_1 + 0x8b0) = nvswitch_smbpbi_send_init_data_ls10;
  *(code **)(param_1 + 0x8b8) = nvswitch_set_minion_initialized_ls10;
  *(code **)(param_1 + 0x8c0) = nvswitch_is_minion_initialized_ls10;
  *(code **)(param_1 + 0x8c8) = nvswitch_get_link_public_id_ls10;
  *(code **)(param_1 + 0x8d0) = nvswitch_get_link_local_idx_ls10;
  *(code **)(param_1 + 0x8d8) = nvswitch_set_training_error_info_lr10;
  *(code **)(param_1 + 0x8e0) = nvswitch_ctrl_get_fatal_error_scope_ls10;
  *(code **)(param_1 + 0x8e8) = nvswitch_init_scratch_lr10;
  *(code **)(param_1 + 0x8f0) = nvswitch_device_discovery_ls10;
  *(code **)(param_1 + 0x8f8) = nvswitch_filter_discovery_ls10;
  *(code **)(param_1 + 0x900) = nvswitch_process_discovery_ls10;
  *(code **)(param_1 + 0x908) = nvswitch_init_minion_ls10;
  *(code **)(param_1 + 0x910) = nvswitch_get_eng_base_ls10;
  *(code **)(param_1 + 0x918) = nvswitch_get_eng_count_ls10;
  *(code **)(param_1 + 0x920) = nvswitch_eng_rd_ls10;
  *(code **)(param_1 + 0x928) = nvswitch_eng_wr_ls10;
  *(code **)(param_1 + 0x930) = nvswitch_reg_write_32_ls10;
  *(code **)(param_1 + 0x938) = nvswitch_get_link_eng_inst_ls10;
  *(code **)(param_1 + 0x940) = nvswitch_alloc_chipdevice_ls10;
  *(code **)(param_1 + 0x948) = nvswitch_init_thermal_ls10;
  *(code **)(param_1 + 0x950) = nvswitch_init_pll_config_ls10;
  *(code **)(param_1 + 0x958) = nvswitch_init_pll_ls10;
  *(code **)(param_1 + 0x960) = nvswitch_init_clock_gating_ls10;
  *(code **)(param_1 + 0x968) = nvswitch_read_physical_id_ls10;
  *(code **)(param_1 + 0x970) = nvswitch_get_caps_nvlink_version_ls10;
  *(code **)(param_1 + 0x978) = nvswitch_initialize_interrupt_tree_ls10;
  *(code **)(param_1 + 0x980) = nvswitch_init_dlpl_interrupts_ls10;
  *(code **)(param_1 + 0x988) = nvswitch_initialize_pmgr_ls10;
  *(code **)(param_1 + 0x990) = nvswitch_initialize_ip_wrappers_ls10;
  *(code **)(param_1 + 0x998) = nvswitch_initialize_route_ls10;
  *(code **)(param_1 + 0x9a0) = nvswitch_soe_unregister_events_ls10;
  *(code **)(param_1 + 0x9a8) = nvswitch_soe_register_event_callbacks_ls10;
  *(code **)(param_1 + 0x9b0) = nvswitch_get_bios_nvlink_config_ls10;
  *(code **)(param_1 + 0x9b8) = nvswitch_minion_send_command_ls10;
  *(code **)(param_1 + 0x9c0) = nvswitch_init_nport_ls10;
  *(code **)(param_1 + 0x9c8) = nvswitch_init_nxbar_ls10;
  *(code **)(param_1 + 0x9d0) = nvswitch_clear_nport_rams_ls10;
  *(code **)(param_1 + 0x9d8) = nvswitch_pri_ring_init_ls10;
  *(code **)(param_1 + 0x9e0) = nvswitch_get_remap_table_selector_ls10;
  *(code **)(param_1 + 0x9e8) = nvswitch_get_ingress_ram_size_ls10;
  *(code **)(param_1 + 0x9f0) = nvswitch_minion_get_dl_status_ls10;
  *(code **)(param_1 + 0x9f8) = nvswitch_corelib_get_uphy_load_ls10;
  *(code **)(param_1 + 0xa00) = nvswitch_is_i2c_supported_ls10;
  *(code **)(param_1 + 0xa08) = nvswitch_poll_sublink_state_lr10;
  *(code **)(param_1 + 0xa10) = nvswitch_setup_link_loopback_mode_lr10;
  *(code **)(param_1 + 0xa18) = nvswitch_reset_persistent_link_hw_state_ls10;
  *(code **)(param_1 + 0xa20) = nvswitch_store_topology_information_ls10;
  *(code **)(param_1 + 0xa28) = nvswitch_init_lpwr_regs_ls10;
  *(code **)(param_1 + 0xa30) = nvswitch_program_l1_scratch_reg_ls10;
  *(code **)(param_1 + 0xa38) = nvswitch_set_training_mode_ls10;
  *(code **)(param_1 + 0xa40) = nvswitch_get_sublink_width_ls10;
  *(code **)(param_1 + 0xa48) = nvswitch_i2c_is_device_access_allowed_ls10;
  *(code **)(param_1 + 0xa50) = nvswitch_parse_bios_image_ls10;
  *(code **)(param_1 + 0xa58) = nvswitch_is_link_in_reset_ls10;
  *(code **)(param_1 + 0xa60) = nvswitch_init_buffer_ready_ls10;
  *(code **)(param_1 + 0xa68) = nvswitch_ctrl_get_nvlink_lp_counters_ls10;
  *(code **)(param_1 + 0xa70) = nvswitch_apply_recal_settings_ls10;
  *(code **)(param_1 + 0xa78) = nvswitch_service_nvldl_fatal_link_ls10;
  *(code **)(param_1 + 0xa80) = nvswitch_service_minion_link_ls10;
  *(code **)(param_1 + 0xa88) = nvswitch_ctrl_get_sw_info_ls10;
  *(code **)(param_1 + 0xa90) = nvswitch_ctrl_get_err_info_lr10;
  *(code **)(param_1 + 0xa98) = nvswitch_ctrl_clear_counters_ls10;
  *(code **)(param_1 + 0xaa0) = nvswitch_ctrl_set_nvlink_error_threshold_ls10;
  *(code **)(param_1 + 0xaa8) = nvswitch_ctrl_get_nvlink_error_threshold_ls10;
  *(code **)(param_1 + 0xab0) = nvswitch_ctrl_get_board_part_number_ls10;
  *(code **)(param_1 + 0xab8) = nvswitch_ctrl_therm_read_voltage_ls10;
  *(code **)(param_1 + 0xac0) = nvswitch_soe_init_l2_state_ls10;
  *(code **)(param_1 + 0xac8) = nvswitch_ctrl_therm_read_power_ls10;
  *(code **)(param_1 + 0xad0) = nvswitch_get_board_id_ls10;
  *(code **)(param_1 + 0xad8) = nvswitch_does_link_need_termination_enabled_ls10;
  *(code **)(param_1 + 0xae0) = nvswitch_link_termination_setup_ls10;
  *(code **)(param_1 + 0xae8) = nvswitch_check_io_sanity_ls10;
  *(code **)(param_1 + 0xaf0) = nvswitch_ctrl_get_link_l1_capability_ls10;
  *(code **)(param_1 + 0xaf8) = nvswitch_ctrl_get_link_l1_threshold_ls10;
  *(code **)(param_1 + 0xb00) = nvswitch_ctrl_set_link_l1_threshold_ls10;
  *(code **)(param_1 + 0xb08) = nvswitch_fsp_update_cmdq_head_tail_ls10;
  *(code **)(param_1 + 0xb10) = nvswitch_fsp_get_cmdq_head_tail_ls10;
  *(code **)(param_1 + 0xb18) = nvswitch_fsp_update_msgq_head_tail_ls10;
  *(code **)(param_1 + 0xb20) = nvswitch_fsp_get_msgq_head_tail_ls10;
  *(code **)(param_1 + 0xb28) = nvswitch_fsp_get_channel_size_ls10;
  *(code **)(param_1 + 0xb30) = nvswitch_fsp_nvdm_to_seid_ls10;
  *(code **)(param_1 + 0xb38) = nvswitch_fsp_create_mctp_header_ls10;
  *(code **)(param_1 + 0xb40) = nvswitch_fsp_create_nvdm_header_ls10;
  *(code **)(param_1 + 0xb48) = nvswitch_fsp_validate_mctp_payload_header_ls10;
  *(code **)(param_1 + 0xb50) = nvswitch_fsp_process_nvdm_msg_ls10;
  *(code **)(param_1 + 0xb58) = nvswitch_fsp_process_cmd_response_ls10;
  *(code **)(param_1 + 0xb60) = nvswitch_fsp_config_ememc_ls10;
  *(code **)(param_1 + 0xb68) = nvswitch_fsp_write_to_emem_ls10;
  *(code **)(param_1 + 0xb70) = nvswitch_fsp_read_from_emem_ls10;
  *(code **)(param_1 + 0xb78) = nvswitch_fsp_error_code_to_nvlstatus_map_ls10;
  *(code **)(param_1 + 0xb80) = nvswitch_fsp_get_packet_info_ls10;
  *(code **)(param_1 + 0xb88) = nvswitch_fsprpc_get_caps_ls10;
  *(code **)(param_1 + 0xb90) = nvswitch_soe_issue_ingress_stop_ls10;
  *(code **)(param_1 + 0xb98) = nvswitch_detect_tnvl_mode_ls10;
  *(code **)(param_1 + 0xba0) = nvswitch_is_tnvl_mode_enabled_ls10;
  *(code **)(param_1 + 0xba8) = nvswitch_is_tnvl_mode_locked_ls10;
  *(code **)(param_1 + 0xbb0) = nvswitch_tnvl_get_attestation_certificate_chain_ls10;
  *(code **)(param_1 + 3000) = nvswitch_tnvl_get_attestation_report_ls10;
  *(code **)(param_1 + 0xbc0) = nvswitch_tnvl_send_fsp_lock_config_ls10;
  *(code **)(param_1 + 0xbc8) = nvswitch_tnvl_get_status_ls10;
  *(code **)(param_1 + 0xbd0) = nvswitch_send_tnvl_prelock_cmd_ls10;
  *(code **)(param_1 + 0xbd8) = nvswitch_tnvl_disable_interrupts_ls10;
  *(code **)(param_1 + 0xbe0) = nvswitch_is_cci_supported_ls10;
  *(code **)(param_1 + 0xbe8) = nvswitch_cci_setup_gpio_pins_ls10;
  *(code **)(param_1 + 0xbf0) = nvswitch_cci_get_cci_link_mode_ls10;
  *(code **)(param_1 + 0xbf8) = nvswitch_cci_discovery_ls10;
  *(code **)(param_1 + 0xc00) = nvswitch_cci_get_xcvrs_present_ls10;
  *(code **)(param_1 + 0xc08) = nvswitch_cci_get_xcvrs_present_change_ls10;
  *(code **)(param_1 + 0xc10) = nvswitch_cci_reset_ls10;
  *(code **)(param_1 + 0xc18) = nvswitch_cci_reset_links_ls10;
  *(code **)(param_1 + 0xc20) = nvswitch_cci_ports_cpld_read_ls10;
  *(code **)(param_1 + 0xc28) = nvswitch_cci_ports_cpld_write_ls10;
  *(code **)(param_1 + 0xc30) = nvswitch_cci_update_link_state_led_ls10;
  *(code **)(param_1 + 0xc38) = nvswitch_cci_set_xcvr_led_state_ls10;
  *(code **)(param_1 + 0xc40) = nvswitch_cci_get_xcvr_led_state_ls10;
  *(code **)(param_1 + 0xc48) = nvswitch_cci_setup_onboard_ls10;
  *(code **)(param_1 + 0xc50) = nvswitch_cci_setup_module_path_ls10;
  *(code **)(param_1 + 0xc58) = nvswitch_cci_module_access_cmd_ls10;
  *(code **)(param_1 + 0xc60) = nvswitch_cci_apply_control_set_values_ls10;
  *(code **)(param_1 + 0xc68) = nvswitch_cci_reset_and_drain_links_ls10;
  *(code **)(param_1 + 0xc70) = nvswitch_cci_cmis_cage_bezel_marking_ls10;
  *(code **)(param_1 + 0xc78) = nvswitch_cci_get_grading_values_ls10;
  *(code **)(param_1 + 0xc80) = nvswitch_cci_get_xcvr_mask_ls10;
  *(code **)(param_1 + 0xc88) = nvswitch_cci_set_xcvr_present_ls10;
  *(code **)(param_1 + 0xc90) = nvswitch_cci_destroy_ls10;
  *(code **)(param_1 + 0xc98) = nvswitch_ctrl_get_soe_heartbeat_ls10;
  *(code **)(param_1 + 0xca0) = nvswitch_update_link_state_led_ls10;
  *(code **)(param_1 + 0xca8) = nvswitch_led_shutdown_ls10;
  *(code **)(param_1 + 0xcb0) = nvswitch_launch_ALI_ls10;
  *(code **)(param_1 + 0xcb8) = nvswitch_launch_ALI_link_training_ls10;
  *(code **)(param_1 + 0xcc0) = nvswitch_ctrl_inband_send_data_ls10;
  *(code **)(param_1 + 0xcc8) = nvswitch_ctrl_inband_read_data_ls10;
  *(code **)(param_1 + 0xcd0) = nvswitch_send_inband_nack_ls10;
  *(code **)(param_1 + 0xcd8) = nvswitch_get_max_persistent_message_count_ls10;
  *(code **)(param_1 + 0xce0) = nvswitch_ctrl_set_mc_rid_table_ls10;
  *(code **)(param_1 + 0xce8) = nvswitch_ctrl_get_mc_rid_table_ls10;
  *(code **)(param_1 + 0xcf0) = nvswitch_ctrl_set_residency_bins_ls10;
  *(code **)(param_1 + 0xcf8) = nvswitch_ctrl_get_residency_bins_ls10;
  *(code **)(param_1 + 0xd00) = nvswitch_ctrl_get_rb_stall_busy_ls10;
  *(code **)(param_1 + 0xd08) = nvswitch_ctrl_get_multicast_id_error_vector_ls10;
  *(code **)(param_1 + 0xd10) = nvswitch_ctrl_clear_multicast_id_error_vector_ls10;
  *(code **)(param_1 + 0xd18) = nvswitch_reset_and_train_link_ls10;
  return;
}


// ===== 0024db10 nvswitch_minion_get_dl_status_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */
/* WARNING: Function: __x86_indirect_thunk_r15 replaced with injection: x86_indirect_thunk_r15 */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */

undefined8
nvswitch_minion_get_dl_status_ls10
          (long param_1,ulong param_2,uint param_3,uint param_4,undefined4 *param_5)

{
  code *pcVar1;
  char cVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 *local_50;
  undefined1 local_40 [16];
  
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_2,7);
  iVar5 = (*pcVar1)(param_1,7,0,uVar4);
  if ((iVar5 != -1) && (cVar2 = nvswitch_is_link_valid(param_1,param_2 & 0xffffffff), cVar2 != '\0')
     ) {
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,7);
    cVar2 = nvswitch_is_minion_initialized(param_1,uVar4);
    if (cVar2 == '\0') {
      return 0xfffffff8;
    }
  }
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,7);
  iVar5 = (*pcVar1)(param_1,7,0,uVar4);
  if ((iVar5 == -1) || (cVar2 = nvswitch_is_link_valid(param_1,param_2 & 0xffffffff), cVar2 == '\0')
     ) {
    nvswitch_assert_log();
  }
  pcVar1 = *(code **)(param_1 + 0x928);
  iVar5 = ((uint)param_2 & 3) * 4;
  iVar7 = iVar5 + 0x2980;
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,7);
  (*pcVar1)(param_1,7,0,uVar4,iVar7,(param_3 & 0xff) << 0x10 | param_4 & 0xffff);
  if (((*(char *)(param_1 + 0x26) == '\0') && (*(char *)(param_1 + 0x24) == '\0')) &&
     (*(char *)(param_1 + 0x25) == '\0')) {
    nvswitch_timeout_create(5000000,local_40);
  }
  else {
    nvswitch_timeout_create(20000000000,local_40);
  }
  while( true ) {
    local_50 = local_40;
    cVar2 = nvswitch_timeout_check(local_50);
    pcVar1 = *(code **)(param_1 + 0x910);
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,7);
    iVar6 = (*pcVar1)(param_1,7,0,uVar4);
    if ((iVar6 == -1) ||
       (cVar3 = nvswitch_is_link_valid(param_1,param_2 & 0xffffffff), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar1 = *(code **)(param_1 + 0x920);
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,7);
    iVar6 = (*pcVar1)(param_1,7,0,uVar4,iVar7);
    if (iVar6 < 0) break;
    if ((*(char *)(param_1 + 0x26) != '\0') || (*(char *)(param_1 + 0x25) != '\0')) {
      nvswitch_os_sleep(1);
    }
    if (cVar2 != '\0') {
      return 0xfffffff8;
    }
  }
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,7);
  iVar7 = (*pcVar1)(param_1,7,0,uVar4);
  if ((iVar7 == -1) || (cVar2 = nvswitch_is_link_valid(param_1,param_2 & 0xffffffff), cVar2 == '\0')
     ) {
    nvswitch_assert_log();
  }
  pcVar1 = *(code **)(param_1 + 0x920);
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,7);
  uVar4 = (*pcVar1)(param_1,7,0,uVar4,iVar5 + 0x29c0);
  *param_5 = uVar4;
  return 0;
}


// ===== 0024ddf0 nvswitch_minion_send_command_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */
/* WARNING: Function: __x86_indirect_thunk_r15 replaced with injection: x86_indirect_thunk_r15 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */

undefined8 nvswitch_minion_send_command_ls10(long *param_1,ulong param_2,uint param_3,uint param_4)

{
  code *pcVar1;
  long lVar2;
  char cVar3;
  char cVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  ulong uVar10;
  uint local_5c;
  uint local_58;
  undefined1 *local_50;
  undefined4 local_44;
  undefined1 local_40 [16];
  
  uVar10 = param_2 & 0xffffffff;
  pcVar1 = (code *)param_1[0x122];
  local_44 = 0;
  uVar5 = nvswitch_get_link_eng_inst(param_1,param_2,7);
  iVar8 = (*pcVar1)(param_1,7,0,uVar5);
  if ((iVar8 != -1) && (cVar3 = nvswitch_is_link_valid(param_1,uVar10), cVar3 != '\0')) {
    uVar5 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,7);
    cVar3 = nvswitch_is_minion_initialized(param_1,uVar5);
    if (cVar3 == '\0') {
      return 0;
    }
  }
  pcVar1 = (code *)param_1[0x122];
  uVar5 = nvswitch_get_link_eng_inst(param_1,uVar10,7);
  iVar8 = (*pcVar1)(param_1,7,0,uVar5);
  if ((iVar8 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_2 & 0xffffffff), cVar3 == '\0')
     ) {
    nvswitch_assert_log();
  }
  pcVar1 = (code *)param_1[0x124];
  uVar5 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,7);
  iVar8 = ((uint)param_2 & 3) * 4 + 0x2900;
  uVar6 = (*pcVar1)(param_1,7,0,uVar5,iVar8);
  if ((uVar6 & 0x40000000) == 0) {
    if (param_3 == 0xd) {
      cVar3 = nvswitch_is_tnvl_mode_locked(param_1);
      if (cVar3 != '\0') {
        return 0xfffffff1;
      }
      local_58 = (*(code *)param_1[0x124])(param_1,5,0,param_2 & 0xffffffff,0x1470);
      (*(code *)param_1[0x125])(param_1,5,0,param_2 & 0xffffffff,0x1470,local_58 & 0xfffffffd);
      local_5c = (*(code *)param_1[0x124])(param_1,5,0,param_2 & 0xffffffff,0x4470);
      (*(code *)param_1[0x125])(param_1,5,0,param_2 & 0xffffffff,0x4470,local_5c & 0xfffffbff);
    }
    else {
      local_5c = 0;
      local_58 = 0;
      if (param_3 == 0x40) {
        pcVar1 = (code *)param_1[0x125];
        uVar5 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,7);
        (*pcVar1)(param_1,7,0,uVar5,0x28b0,param_4);
        uVar6 = param_4;
      }
    }
    pcVar1 = (code *)param_1[0x122];
    uVar5 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,7);
    iVar7 = (*pcVar1)(param_1,7,0,uVar5);
    if ((iVar7 == -1) ||
       (cVar3 = nvswitch_is_link_valid(param_1,param_2 & 0xffffffff), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar1 = (code *)param_1[0x125];
    uVar5 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,7);
    (*pcVar1)(param_1,7,0,uVar5,iVar8,param_3 & 0xff | uVar6 & 0xffffff00 | 0x40000000);
    if (((*(char *)((long)param_1 + 0x26) == '\0') && (*(char *)((long)param_1 + 0x24) == '\0')) &&
       (*(char *)((long)param_1 + 0x25) == '\0')) {
      nvswitch_timeout_create(5000000,local_40);
    }
    else {
      nvswitch_timeout_create(10000000000,local_40);
    }
    do {
      local_50 = local_40;
      cVar3 = nvswitch_timeout_check(local_50);
      pcVar1 = (code *)param_1[0x122];
      uVar5 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,7);
      iVar7 = (*pcVar1)(param_1,7,0,uVar5);
      if ((iVar7 == -1) ||
         (cVar4 = nvswitch_is_link_valid(param_1,param_2 & 0xffffffff), cVar4 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar1 = (code *)param_1[0x124];
      uVar5 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,7);
      uVar6 = (*pcVar1)(param_1,7,0,uVar5,iVar8);
      if ((int)uVar6 < 0) {
        if ((uVar6 & 0x40000000) == 0) {
          if (param_3 != 0xd) {
            return 0;
          }
          (*(code *)param_1[0x125])(param_1,5,0,param_2 & 0xffffffff,0x1470,local_58);
          (*(code *)param_1[0x125])(param_1,5,0,param_2 & 0xffffffff,0x4470,local_5c);
          return 0;
        }
        nvswitch_minion_get_dl_status(param_1,param_2 & 0xffffffff,0xff,0,&local_44);
        pcVar1 = (code *)param_1[0x122];
        uVar5 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,7);
        iVar7 = (*pcVar1)(param_1,7,0,uVar5);
        if ((iVar7 == -1) ||
           (cVar3 = nvswitch_is_link_valid(param_1,param_2 & 0xffffffff), cVar3 == '\0')) {
          nvswitch_assert_log();
        }
        pcVar1 = (code *)param_1[0x125];
        uVar5 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,7);
        (*pcVar1)(param_1,7,0,uVar5,iVar8,0x40000000);
        goto LAB_0024e21f;
      }
      nvswitch_os_sleep(1);
    } while (cVar3 == '\0');
    iVar8 = nvswitch_translate_hw_error(0x55f7);
    if (iVar8 == 1) {
      nvswitch_assert_log();
    }
    lVar2 = *param_1;
    nvswitch_os_print(5,
                      "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d DLCMD TIMEOUT: cmd=0x%x DL_CMD=0x%0x\n"
                      ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                      *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x55f7,uVar10,
                      param_3,uVar6);
    nvswitch_os_report_error
              (param_1[3],0x55f7,"Non-fatal, Link %02d DLCMD TIMEOUT: cmd=0x%x DL_CMD=0x%0x\n",
               param_2 & 0xffffffff,param_3,uVar6);
    nvswitch_lib_smbpbi_log_sxid
              (param_1,0x55f7,"Non-fatal, Link %02d DLCMD TIMEOUT: cmd=0x%x DL_CMD=0x%0x\n",
               param_2 & 0xffffffff,param_3,uVar6);
    nvswitch_inforom_bbx_add_sxid(param_1,0x55f7,0,0,0);
    nvswitch_record_error
              (param_1,param_1 + 0x24,0x55f7,param_2 & 0xffffffff,0,1,0,0,0,0,0x14b,&DAT_00cc784b);
LAB_0024e21f:
    uVar9 = 0xfffffff8;
  }
  else {
    iVar8 = nvswitch_translate_hw_error(0x55f6);
    if (iVar8 == 1) {
      nvswitch_assert_log();
    }
    lVar2 = *param_1;
    nvswitch_os_print(5,
                      "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d DLCMD FAULT: cmd=0x%x DL_CMD=0x%x\n"
                      ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                      *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x55f6,uVar10,
                      param_3,uVar6);
    nvswitch_os_report_error
              (param_1[3],0x55f6,"Non-fatal, Link %02d DLCMD FAULT: cmd=0x%x DL_CMD=0x%x\n",
               param_2 & 0xffffffff,param_3,uVar6);
    nvswitch_lib_smbpbi_log_sxid
              (param_1,0x55f6,"Non-fatal, Link %02d DLCMD FAULT: cmd=0x%x DL_CMD=0x%x\n",
               param_2 & 0xffffffff,param_3,uVar6);
    nvswitch_inforom_bbx_add_sxid(param_1,0x55f6,0,0,0);
    nvswitch_record_error
              (param_1,param_1 + 0x24,0x55f6,param_2 & 0xffffffff,0,1,0,0,0,0,0xcb,&DAT_00cc784b);
    uVar9 = 0xfffffff9;
  }
  return uVar9;
}


// ===== 0024e4c4 nvswitch_init_minion_ls10.cold =====

void nvswitch_init_minion_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0024e4d0 nvswitch_init_minion_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint nvswitch_init_minion_ls10(long param_1)

{
  code *pcVar1;
  bool bVar2;
  char cVar3;
  ulong uVar4;
  uint uVar5;
  
  bVar2 = false;
  uVar5 = 0;
  do {
    if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    if (((*(char *)((ulong)uVar5 * 0x20 + *(long *)(param_1 + 0x1f90) + 0x5c30) != '\0') &&
        (uVar4 = (**(code **)(param_1 + 0x920))(param_1,7,0,uVar5,8), (uVar4 & 0x10) == 0)) &&
       (cVar3 = (**(code **)(param_1 + 0x920))(param_1,7,0,uVar5,0x2830), cVar3 == '\x01')) {
      nvswitch_set_minion_initialized(param_1,uVar5,1);
      bVar2 = true;
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 != 0x10);
  return -(uint)!bVar2 & 0xfffffffb;
}


// ===== 0024e5a0 nvswitch_set_minion_initialized_ls10 =====

undefined8 nvswitch_set_minion_initialized_ls10(long param_1,uint param_2,byte param_3)

{
  long lVar1;
  
  lVar1 = 0;
  if (*(int *)(param_1 + 0x1f88) == 7) {
    lVar1 = *(long *)(param_1 + 0x1f90);
  }
  if ((param_2 < 0x10) && (*(char *)(lVar1 + 0x5c30 + (ulong)param_2 * 0x20) != '\0')) {
    *(uint *)(lVar1 + 0x5c34 + (ulong)param_2 * 0x20) = (uint)param_3;
    return 0;
  }
  return 0xffffffff;
}


// ===== 0024e5f0 nvswitch_is_minion_initialized_ls10 =====

uint nvswitch_is_minion_initialized_ls10(long param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  
  lVar4 = 0;
  if (*(int *)(param_1 + 0x1f88) == 7) {
    lVar4 = *(long *)(param_1 + 0x1f90);
  }
  uVar3 = 0;
  if (param_2 < 0x10) {
    lVar4 = lVar4 + (ulong)param_2 * 0x20;
    bVar1 = *(byte *)(lVar4 + 0x5c30);
    uVar3 = (uint)bVar1;
    if (bVar1 != 0) {
      iVar2 = *(int *)(lVar4 + 0x5c34);
      uVar3 = CONCAT31((int3)((uint)iVar2 >> 8),iVar2 != 0);
    }
  }
  return uVar3;
}


// ===== 0024e630 nvswitch_minion_set_sim_mode_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8 nvswitch_minion_set_sim_mode_ls10(long param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  
  if (2 < *(int *)(param_1 + 0xac) - 1U) {
    return 0;
  }
  uVar1 = *(uint *)(param_2 + 0x38);
  uVar7 = nvswitch_minion_send_command(param_1,uVar1,*(int *)(param_1 + 0xac) + 0x7f,0);
  if ((int)uVar7 == 0) {
    pcVar2 = *(code **)(param_1 + 0x910);
    uVar4 = nvswitch_get_link_eng_inst(param_1,uVar1,7);
    iVar5 = (*pcVar2)(param_1,7,0,uVar4,pcVar2);
    if ((iVar5 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,uVar1), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar2 = *(code **)(param_1 + 0x928);
    iVar5 = (uVar1 & 3) * 4 + 0x2920;
    uVar4 = nvswitch_get_link_eng_inst(param_1,uVar1,7);
    (*pcVar2)(param_1,7,0,uVar4,iVar5,0x50);
    uVar7 = nvswitch_minion_send_command(param_1,uVar1,0x84,0);
    if ((int)uVar7 == 0) {
      pcVar2 = *(code **)(param_1 + 0x910);
      uVar4 = nvswitch_get_link_eng_inst(param_1,uVar1,7);
      iVar6 = (*pcVar2)(param_1,7,0,uVar4,pcVar2);
      if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,uVar1), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(param_1 + 0x928);
      uVar4 = nvswitch_get_link_eng_inst(param_1,uVar1,7);
      (*pcVar2)(param_1,7,0,uVar4,iVar5,0x26);
      uVar7 = nvswitch_minion_send_command(param_1,uVar1,0x85,0);
      return uVar7;
    }
  }
  return uVar7;
}


// ===== 0024e7f0 nvswitch_minion_set_smf_settings_ls10 =====

undefined8 nvswitch_minion_set_smf_settings_ls10(long param_1,long param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = *(int *)(param_1 + 0xb0) - 1;
  if (3 < uVar1) {
    return 0;
  }
  uVar2 = nvswitch_minion_send_command
                    (param_1,*(undefined4 *)(param_2 + 0x38),
                     *(undefined4 *)(CSWTCH_23 + (ulong)uVar1 * 4),0);
  return uVar2;
}


// ===== 0024e820 nvswitch_minion_select_uphy_tables_ls10 =====

undefined8 nvswitch_minion_select_uphy_tables_ls10(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if (*(int *)(param_1 + 0xb4) == 1) {
    uVar1 = nvswitch_minion_send_command(param_1,*(undefined4 *)(param_2 + 0x38),0x8d,0);
    return uVar1;
  }
  if (*(int *)(param_1 + 0xb4) == 2) {
    uVar1 = nvswitch_minion_send_command(param_1,*(undefined4 *)(param_2 + 0x38),0x8e,0);
    return uVar1;
  }
  return 0;
}


// ===== 0024e860 nvswitch_minion_get_rxdet_status_ls10 =====

int nvswitch_minion_get_rxdet_status_ls10(long param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  ulong uVar6;
  long lVar7;
  uint local_34;
  undefined1 local_30 [8];
  
  uVar6 = (ulong)param_2;
  if (((*(char *)(param_1 + 0x26) == '\0') && (*(char *)(param_1 + 0x24) == '\0')) &&
     (*(char *)(param_1 + 0x25) == '\0')) {
    nvswitch_timeout_create(20000000,local_30);
  }
  else {
    nvswitch_timeout_create(30000000000,local_30);
  }
  do {
    cVar1 = nvswitch_timeout_check(local_30);
    iVar2 = nvswitch_minion_get_dl_status(param_1,uVar6,0x12,0,&local_34);
    if (iVar2 != 0) {
      return iVar2;
    }
    if ((local_34 & 0x300) == 0x200) {
      lVar7 = (ulong)param_2 * 0x40;
      *(uint *)(param_1 + 0xf70 + lVar7) = local_34 & 0xff;
      cVar1 = nvswitch_link_lane_reversed_lr10(param_1);
      if (cVar1 == '\0') {
        return 0;
      }
      uVar3 = *(uint *)(param_1 + 0xf70 + lVar7);
      if (uVar3 == 0) {
        uVar5 = 0;
      }
      else {
        bVar4 = 1;
        uVar5 = 0;
        for (; ((uVar3 & 1) == 0 || (uVar5 = uVar5 | 1 << (bVar4 & 0x1f), uVar3 >> 1 != 0));
            uVar3 = uVar3 >> 1) {
          bVar4 = bVar4 - 1;
        }
      }
      *(uint *)(param_1 + 0xf70 + (ulong)param_2 * 0x40) = uVar5;
      return 0;
    }
    if ((local_34 & 0x300) == 0x300) {
      *(uint *)(param_1 + 0xf70 + uVar6 * 0x40) = local_34 & 0xff;
      cVar1 = nvswitch_link_lane_reversed_lr10(param_1,uVar6);
      if (cVar1 == '\0') {
        return -8;
      }
      uVar3 = *(uint *)(param_1 + 0xf70 + uVar6 * 0x40);
      if (uVar3 == 0) {
        uVar5 = 0;
      }
      else {
        bVar4 = 1;
        uVar5 = 0;
        for (; ((uVar3 & 1) == 0 || (uVar5 = uVar5 | 1 << (bVar4 & 0x1f), uVar3 >> 1 != 0));
            uVar3 = uVar3 >> 1) {
          bVar4 = bVar4 - 1;
        }
      }
      *(uint *)(param_1 + 0xf70 + uVar6 * 0x40) = uVar5;
      return -8;
    }
    nvswitch_os_sleep(1);
  } while (cVar1 == '\0');
  return -8;
}


// ===== 0024ea60 nvswitch_minion_clear_dl_error_counters_ls10 =====

void nvswitch_minion_clear_dl_error_counters_ls10(undefined8 param_1,undefined8 param_2)

{
  nvswitch_minion_send_command(param_1,param_2,0x70,0);
  return;
}


// ===== 0024ea70 nvswitch_minion_send_inband_data_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */

int nvswitch_minion_send_inband_data_ls10(long param_1,ulong param_2,long *param_3)

{
  byte bVar1;
  code *pcVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  ulong uVar9;
  uint uVar10;
  long lVar11;
  bool bVar12;
  undefined4 local_48;
  uint local_44;
  undefined1 local_40 [16];
  
  uVar10 = *(uint *)(param_3 + 1);
  local_48 = 0;
  lVar11 = *param_3;
  local_44 = 0;
  if (uVar10 - 1 < 0x100) {
    bVar1 = *(byte *)((long)param_3 + 0xc);
    pcVar2 = *(code **)(param_1 + 0x928);
    iVar8 = ((uint)param_2 & 3) * 4 + 0x2920;
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_2,7);
    (*pcVar2)(param_1,7,0,uVar4,iVar8,(uint)bVar1 << 0x10 | uVar10 - 1);
    iVar5 = nvswitch_minion_send_command(param_1,param_2 & 0xffffffff,0x33,0);
    if (iVar5 == 0) {
      do {
        uVar6 = 4;
        if (uVar10 < 5) {
          uVar6 = uVar10;
        }
        nvswitch_os_memcpy(&local_48,lVar11);
        uVar4 = local_48;
        pcVar2 = *(code **)(param_1 + 0x928);
        uVar7 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,7);
        (*pcVar2)(param_1,7,0,uVar7,iVar8,uVar4);
        iVar5 = nvswitch_minion_send_command(param_1,param_2 & 0xffffffff,0x34,0);
        if (iVar5 != 0) {
          bVar12 = true;
          goto LAB_0024ebe3;
        }
        uVar10 = uVar10 - uVar6;
        uVar9 = 4;
        if (uVar10 < 5) {
          uVar9 = (ulong)uVar10;
        }
        lVar11 = lVar11 + uVar9;
      } while (uVar10 != 0);
      iVar5 = nvswitch_minion_send_command(param_1,param_2 & 0xffffffff,0x35,0);
      bVar12 = true;
      if (iVar5 == 0) {
        nvswitch_timeout_create(8000000000,local_40);
        do {
          cVar3 = nvswitch_timeout_check(local_40);
          iVar5 = nvswitch_minion_get_dl_status(param_1,param_2 & 0xffffffff,1,0,&local_44);
          if (iVar5 != 0) {
LAB_0024ece7:
            bVar12 = cVar3 == '\0';
            iVar5 = -8;
            goto LAB_0024ebe3;
          }
          iVar5 = 0;
          if ((local_44 & 0x2000000) != 0) {
            return 0;
          }
          if ((local_44 & 0x4000000) != 0) goto LAB_0024ece7;
          nvswitch_service_minion_all_links_ls10(param_1);
          nvswitch_os_sleep(10);
        } while (cVar3 == '\0');
        bVar12 = false;
      }
LAB_0024ebe3:
      iVar8 = nvswitch_minion_send_command(param_1,param_2 & 0xffffffff,0x37,0);
      if ((iVar8 == 0) &&
         (iVar8 = nvswitch_minion_get_dl_status(param_1,param_2 & 0xffffffff,1,0,&local_44),
         iVar8 == 0)) {
        if ((local_44 & 0x2000000) == 0) {
          if (!bVar12) {
            iVar5 = -0xc;
          }
        }
        else {
          iVar5 = 0;
        }
      }
    }
  }
  else {
    iVar5 = -8;
  }
  return iVar5;
}


// ===== 0024ed30 nvswitch_minion_receive_inband_data_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */
/* WARNING: Function: __x86_indirect_thunk_r12 replaced with injection: x86_indirect_thunk_r12 */

void nvswitch_minion_receive_inband_data_ls10(long param_1,uint param_2)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  ulong uVar12;
  uint local_3c [3];
  
  uVar12 = (ulong)param_2;
  iVar3 = nvswitch_minion_send_command(param_1,uVar12,0x30,0);
  if (iVar3 != 0) goto LAB_0024ed68;
  pcVar2 = *(code **)(param_1 + 0x920);
  iVar3 = (param_2 & 3) * 4 + 0x2920;
  uVar4 = nvswitch_get_link_eng_inst(param_1,uVar12,7);
  uVar5 = (*pcVar2)(param_1,7,0,uVar4,iVar3);
  local_3c[0] = uVar5;
  if ((uVar5 & 0x70000) == 0) goto LAB_0024ed68;
  if ((uVar5 >> 0x10 & 1) == 0) {
LAB_0024ee71:
    lVar7 = *(long *)(param_1 + 0xf78 + uVar12 * 0x40);
    if (lVar7 == 0) goto LAB_0024ed68;
    uVar9 = (uVar5 & 0xff) + 1;
    if (*(uint *)(lVar7 + 0x1410) + uVar9 < 0x1401) {
      lVar7 = lVar7 + 0x10 + (ulong)*(uint *)(lVar7 + 0x1410);
      uVar11 = 0;
      uVar10 = uVar9;
      while (iVar6 = nvswitch_minion_send_command(param_1,param_2,0x31,0), iVar6 == 0) {
        pcVar2 = *(code **)(param_1 + 0x920);
        uVar4 = nvswitch_get_link_eng_inst(param_1,param_2,7);
        local_3c[0] = (*pcVar2)(param_1,7,0,uVar4,iVar3);
        uVar8 = 4;
        if (uVar10 < 5) {
          uVar8 = (ulong)uVar10;
        }
        uVar10 = uVar10 - (int)uVar8;
        nvswitch_os_memcpy(lVar7,local_3c);
        lVar7 = lVar7 + uVar8;
        if ((uVar5 & 0xff) >> 2 == uVar11) {
          iVar3 = nvswitch_minion_send_command(param_1,param_2,0x32,0);
          if (iVar3 == 0) {
            piVar1 = (int *)(*(long *)(param_1 + 0xf78 + uVar12 * 0x40) + 0x1410);
            *piVar1 = *piVar1 + uVar9;
            if ((uVar5 >> 0x10 & 4) == 0) {
              return;
            }
            nvswitch_filter_messages(param_1,param_2);
            return;
          }
          break;
        }
        uVar11 = uVar11 + 1;
      }
      goto LAB_0024ed68;
    }
  }
  else if (*(long *)(param_1 + 0xf78 + uVar12 * 0x40) == 0) {
    lVar7 = nvswitch_os_malloc_trace(0x1418,0,0);
    *(long *)(param_1 + 0xf78 + uVar12 * 0x40) = lVar7;
    if (lVar7 == 0) goto LAB_0024ed68;
    *(undefined4 *)(lVar7 + 0x1410) = 0;
    goto LAB_0024ee71;
  }
  nvswitch_assert_log();
LAB_0024ed68:
  nvswitch_minion_send_command(param_1,param_2,0x36,0);
  param_1 = param_1 + uVar12 * 0x40;
  if (*(long *)(param_1 + 0xf78) != 0) {
    nvswitch_os_free();
    *(undefined8 *)(param_1 + 0xf78) = 0;
  }
  return;
}


// ===== 0024efe0 nvswitch_minion_get_ali_debug_registers_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r15 replaced with injection: x86_indirect_thunk_r15 */

undefined8 nvswitch_minion_get_ali_debug_registers_ls10(long param_1,long param_2,long param_3)

{
  uint uVar1;
  code *pcVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar1 = *(uint *)(param_2 + 0x38);
  nvswitch_minion_get_dl_status(param_1,uVar1,0xff,0,param_3);
  nvswitch_minion_get_dl_status(param_1,*(undefined4 *)(param_2 + 0x38),1,0,param_3 + 4);
  pcVar2 = *(code **)(param_1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),7);
  iVar5 = (*pcVar2)(param_1,7,0,uVar4);
  if (iVar5 != -1) {
    cVar3 = nvswitch_is_link_valid(param_1,*(undefined4 *)(param_2 + 0x38));
    if (cVar3 != '\0') goto LAB_0024f074;
  }
  nvswitch_assert_log();
LAB_0024f074:
  pcVar2 = *(code **)(param_1 + 0x920);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),7);
  uVar4 = (*pcVar2)(param_1,7,0,uVar4,(uVar1 & 3) * 4 + 0x2a00);
  *(undefined4 *)(param_3 + 8) = uVar4;
  return 0;
}


// ===== 0024f0c0 nvswitch_mc_build_mcp_list_ls10 =====

undefined8
nvswitch_mc_build_mcp_list_ls10
          (long param_1,long param_2,int *param_3,long param_4,long param_5,long param_6,
          long param_7,uint *param_8)

{
  undefined2 *puVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  uint *puVar9;
  uint *puVar10;
  ulong uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  char cVar15;
  uint uVar16;
  uint uVar17;
  byte *pbVar18;
  uint *puVar19;
  uint uVar20;
  ulong uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint local_398;
  uint local_394;
  long local_390;
  byte local_37a [66];
  undefined4 local_338;
  byte abStack_334 [252];
  uint local_238 [130];
  
  if (((((param_1 != 0) && (param_2 != 0)) && (param_3 != (int *)0x0)) &&
      ((param_4 != 0 && (param_5 != 0)))) &&
     ((param_6 != 0 && ((param_7 != 0 && (param_8 != (uint *)0x0)))))) {
    bVar2 = *(byte *)(param_7 + 3);
    uVar16 = bVar2 - 1;
    if (uVar16 < 0x10) {
      uVar23 = 0;
      for (piVar6 = param_3; *piVar6 - 1U < 0x20; piVar6 = piVar6 + 1) {
        uVar23 = uVar23 + *piVar6;
        if (piVar6 == param_3 + uVar16) {
          if (0x20 < uVar23) {
            return 0xffffffff;
          }
          puVar1 = (undefined2 *)(param_7 + 8);
          nvswitch_os_memset(puVar1,0,0x100);
          puVar7 = puVar1;
          do {
            *(byte *)((long)puVar7 + 7) = *(byte *)((long)puVar7 + 7) | 8;
            puVar8 = puVar7 + 4;
            *puVar7 = 0xfff;
            *(undefined1 *)((long)puVar7 + 3) = 0xf;
            puVar7 = puVar8;
          } while (puVar8 != (undefined2 *)(param_7 + 0x108));
          local_394 = 0;
          uVar16 = 0xff;
          local_390 = 0;
          local_398 = 0;
          do {
            uVar23 = param_3[local_390];
            puVar19 = &local_338;
            nvswitch_os_memset(&local_338,0,0x100);
            puVar9 = puVar19;
            do {
              *(byte *)((long)puVar9 + 7) = *(byte *)((long)puVar9 + 7) | 8;
              puVar10 = puVar9 + 2;
              *(undefined2 *)puVar9 = 0xfff;
              *(char *)((long)puVar9 + 3) = '\x0f';
              puVar9 = puVar10;
            } while (puVar10 != local_238);
            uVar17 = uVar23 - 1;
            if (0x1f < uVar17) {
              return 0xffffffff;
            }
            nvswitch_os_memset(local_37a,0,0x42);
            uVar21 = 0;
            uVar11 = 0;
            do {
              uVar25 = *(uint *)(param_2 + (ulong)local_398 * 4 + uVar11 * 4);
              if ((uVar21 >> ((ulong)uVar25 & 0x3f) & 1) != 0) {
                return 0xffffffff;
              }
              if (0x3f < uVar25) {
                return 0xffffffff;
              }
              bVar3 = *(byte *)((ulong)local_398 + param_6 + uVar11);
              uVar20 = (&nvswitch_portmap_ls10)[(ulong)uVar25 * 2];
              uVar4 = (&DAT_00cc7864)[(ulong)uVar25 * 2];
              local_238[uVar11 * 2] = uVar20;
              local_238[uVar11 * 2 + 1] = uVar4;
              if (3 < bVar3) {
                return 0xffffffff;
              }
              uVar11 = uVar11 + 1;
              uVar21 = uVar21 | 1L << ((byte)uVar25 & 0x3f);
              local_37a[(ulong)uVar4 + (ulong)uVar20 * 0xb] = bVar3;
            } while (uVar11 != uVar23);
            uVar11 = (ulong)uVar16;
            *(undefined1 *)(param_7 + 0x108 + local_390) = (undefined1)local_394;
            if (*(char *)(param_5 + local_390) != '\0') {
              uVar16 = *(uint *)(param_4 + local_390 * 4);
              if (uVar23 <= uVar16) {
                return 0xffffffff;
              }
              uVar25 = 0;
              do {
                if (uVar16 == uVar25) {
                  uVar11 = (ulong)*(uint *)(param_2 + (ulong)(local_398 + uVar16) * 4);
                }
                uVar25 = uVar25 + 1;
              } while (uVar23 != uVar25);
            }
            if (local_394 == 0x20) {
              return 0xfffffff9;
            }
            uVar16 = (uint)uVar11;
            pbVar18 = (byte *)&local_338;
            puVar9 = local_238;
            do {
              while( true ) {
                uVar25 = *puVar9;
                uVar20 = puVar9[1];
                pbVar18[6] = 0;
                *pbVar18 = (byte)(uVar25 >> 1);
                bVar3 = local_37a[(ulong)(uVar20 & 0xff) + (ulong)uVar25 * 0xb];
                if ((uVar25 & 1) == 0) break;
                pbVar18[3] = (byte)uVar20;
                pbVar18[1] = 0xf;
                pbVar18[4] = bVar3;
                if (((uVar16 < 0x40) && ((&nvswitch_portmap_ls10)[uVar11 * 2] == uVar25)) &&
                   ((&DAT_00cc7864)[uVar11 * 2] == (uVar20 & 0xff))) {
                  pbVar18[6] = 2;
                }
LAB_0024f3fa:
                pbVar18 = pbVar18 + 8;
                puVar9 = puVar9 + 2;
                if (abStack_334 + (ulong)uVar23 * 8 + -4 == pbVar18) goto LAB_0024f472;
              }
              pbVar18[1] = (byte)uVar20;
              pbVar18[3] = 0xf;
              pbVar18[2] = bVar3;
              if (((0x3f < uVar16) || ((&nvswitch_portmap_ls10)[uVar11 * 2] != uVar25)) ||
                 ((&DAT_00cc7864)[uVar11 * 2] != (uVar20 & 0xff))) goto LAB_0024f3fa;
              pbVar18[6] = 1;
              pbVar18 = pbVar18 + 8;
              puVar9 = puVar9 + 2;
            } while (abStack_334 + (ulong)uVar23 * 8 + -4 != pbVar18);
LAB_0024f472:
            uVar22 = 0;
            abStack_334[(ulong)uVar17 * 8 + 3] = abStack_334[(ulong)uVar17 * 8 + 3] | 4;
            uVar24 = 0;
            uVar20 = 0;
            pbVar18 = (byte *)&local_338;
            uVar25 = 0;
            uVar4 = 0;
            do {
              while( true ) {
                uVar5 = uVar4 + 1;
                if (uVar4 != uVar17) break;
                uVar24 = uVar24 + 1;
                pbVar18[7] = pbVar18[7] & 0xf3 | 4;
                abStack_334[(ulong)uVar20 * 8 + 1] = (char)uVar5 - (char)uVar20;
                pbVar18 = pbVar18 + 8;
                uVar25 = uVar17;
                uVar4 = uVar5;
                if (uVar5 == uVar23) goto LAB_0024f521;
              }
              if ((uVar25 - uVar20 == 2) ||
                 (uVar22 = uVar22 | 1 << (*pbVar18 & 0x1f), (1 << (pbVar18[8] & 0x1f) & uVar22) != 0
                 )) {
                pbVar18[7] = pbVar18[7] & 0xf7;
                uVar24 = uVar24 + 1;
                abStack_334[(ulong)uVar20 * 8 + 1] = (char)uVar5 - (char)uVar20;
                uVar22 = 0;
                uVar25 = uVar4;
                uVar20 = uVar5;
              }
              pbVar18 = pbVar18 + 8;
              uVar4 = uVar5;
            } while (uVar5 != uVar23);
LAB_0024f521:
            if (0xb < uVar24) {
              return 0xffffffff;
            }
            puVar12 = &local_338;
            uVar17 = 0;
            while( true ) {
              cVar15 = *(char *)((long)puVar12 + 6);
              uVar17 = uVar17 + 1;
              if (cVar15 == '\0') goto LAB_0024f580;
              bVar3 = *(byte *)((long)puVar12 + 7);
              puVar14 = puVar12;
              while ((bVar3 & 4) != 0) {
                *(byte *)((long)puVar14 + 7) = bVar3 | 8;
                puVar12 = puVar14;
                if (cVar15 == '\x01') {
                  *(byte *)((long)puVar14 + 7) = bVar3 & 0xef | 8;
                }
                else if (cVar15 == '\x02') {
                  *(byte *)((long)puVar14 + 7) = bVar3 | 0x18;
                }
LAB_0024f580:
                do {
                  puVar13 = puVar12;
                  if (uVar23 <= uVar17) goto LAB_0024f610;
                  cVar15 = *(char *)((long)puVar13 + 0xe);
                  puVar14 = puVar13 + 2;
                  uVar17 = uVar17 + 1;
                  puVar12 = puVar14;
                } while (cVar15 == '\0');
                bVar3 = *(byte *)((long)puVar13 + 0xf);
              }
              *(byte *)((long)puVar14 + 7) = bVar3 | 0x10;
              if (uVar23 <= uVar17) break;
              puVar12 = puVar14 + 2;
              if (cVar15 == '\x01') {
                *(byte *)((long)puVar14 + 0xf) = *(byte *)((long)puVar14 + 0xf) & 0xef;
                cVar15 = *(char *)((long)puVar14 + 6);
              }
              if (cVar15 == '\x02') {
                *(byte *)((long)puVar14 + 0xf) = *(byte *)((long)puVar14 + 0xf) | 0x10;
              }
            }
            nvswitch_assert_log();
LAB_0024f610:
            uVar17 = uVar23 + local_394;
            if (0x20 < uVar17) {
              return 0xfffffff6;
            }
            puVar7 = puVar1 + (ulong)local_394 * 4;
            uVar25 = 0;
            do {
              if ((char)*puVar19 == -1) {
                return 0xfffffff9;
              }
              uVar25 = uVar25 + 1;
              nvswitch_os_memcpy(puVar7,puVar19,8);
              puVar19 = puVar19 + 2;
              puVar7 = puVar7 + 4;
            } while (uVar25 < uVar23);
            local_398 = local_398 + uVar23;
            local_390 = local_390 + 1;
            local_394 = uVar17;
            if (bVar2 <= (uint)local_390) {
              *param_8 = uVar17;
              return 0;
            }
          } while( true );
        }
      }
    }
  }
  return 0xffffffff;
}


// ===== 0024f780 nvswitch_mc_unwind_directives_ls10 =====

undefined8
nvswitch_mc_unwind_directives_ls10
          (undefined8 param_1,byte *param_2,long param_3,long param_4,long param_5,long param_6,
          long param_7)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  long lVar6;
  uint uVar7;
  ulong uVar8;
  int iVar9;
  int iVar10;
  char cVar11;
  ulong uVar12;
  
  iVar10 = 0;
  iVar9 = 0;
  uVar12 = 0;
  uVar8 = 0;
  do {
    bVar1 = *param_2;
joined_r0x0024f7ba:
    if (bVar1 == 0xff) {
      return 0;
    }
    bVar2 = param_2[7];
    bVar3 = param_2[1];
    bVar4 = param_2[3];
    bVar5 = param_2[4];
    if ((bVar2 & 4) == 0) {
      if (iVar9 == 0x1f) {
        if (bVar3 == 0xf) {
          if (bVar4 == 0xf) {
            return 0;
          }
          goto LAB_0024fac9;
        }
LAB_0024f99c:
        cVar11 = '\0';
LAB_0024f810:
        uVar7 = (uint)bVar1 * 2;
        if ((bVar2 & 1) == 0) {
          if ((6 < uVar7) || (0xb < bVar3)) goto LAB_0024f9ea;
          lVar6 = 0;
          while (((&nvswitch_portmap_ls10)[lVar6 * 2] != uVar7 ||
                 ((&DAT_00cc7864)[lVar6 * 2] != (uint)bVar3))) {
            lVar6 = lVar6 + 1;
            if (lVar6 == 0x40) goto LAB_0024f9ea;
          }
        }
        else {
          if ((6 < uVar7 + 1) || (0xb < bVar3)) goto LAB_0024f9ea;
          lVar6 = 0;
          while (((&nvswitch_portmap_ls10)[lVar6 * 2] != uVar7 + 1 ||
                 ((&DAT_00cc7864)[lVar6 * 2] != (uint)bVar3))) {
            lVar6 = lVar6 + 1;
            if (lVar6 == 0x40) goto LAB_0024f9ea;
          }
        }
        uVar7 = (uint)uVar8;
        if (0x3f < uVar7) goto LAB_0024f9ea;
        iVar10 = iVar10 + 1;
        *(byte *)(param_4 + uVar8) = param_2[2];
        *(int *)(param_3 + uVar8 * 4) = (int)lVar6;
        if (cVar11 == '\x01') {
          *(uint *)(param_6 + uVar12 * 4) = uVar7;
          *(undefined1 *)(param_7 + uVar12) = 1;
        }
        uVar8 = (ulong)(uVar7 + 1);
        if (bVar4 != 0xf) goto LAB_0024f8b0;
        goto LAB_0024f93d;
      }
      if ((bVar2 & 0x10) != 0) {
LAB_0024fa5b:
        cVar11 = ((param_2[0xf] & 0x10) != 0) + '\x01';
        goto LAB_0024fa6a;
      }
      if (bVar3 != 0xf) goto LAB_0024f99c;
      cVar11 = '\0';
      if (bVar4 != 0xf) goto LAB_0024f8b0;
      goto LAB_0024f954;
    }
    if ((bVar2 & 8) != 0) {
      if ((bVar2 & 0x10) == 0) {
        cVar11 = '\x01';
      }
      else {
        cVar11 = '\x02';
      }
      if (bVar3 != 0xf) goto LAB_0024f810;
      if (bVar4 != 0xf) goto LAB_0024f8b0;
LAB_0024f942:
      *(int *)(param_5 + uVar12 * 4) = iVar10;
      iVar10 = 0;
      uVar12 = (ulong)((int)uVar12 + 1);
LAB_0024f954:
      iVar9 = iVar9 + 1;
      if (iVar9 == 0x20) {
        return 0;
      }
      bVar1 = param_2[8];
      param_2 = param_2 + 8;
      goto joined_r0x0024f7ba;
    }
    if (iVar9 == 0x1f) {
      if (bVar3 != 0xf) goto LAB_0024f99c;
      if (bVar4 == 0xf) {
        *(int *)(param_5 + uVar12 * 4) = iVar10;
        return 0;
      }
LAB_0024fac9:
      cVar11 = '\0';
LAB_0024f8b0:
      uVar7 = (uint)bVar1 * 2;
      if ((bVar2 & 2) == 0) {
        if ((6 < uVar7 + 1) || (0xb < bVar4)) goto LAB_0024f9ea;
        lVar6 = 0;
        while (((&DAT_00cc7864)[lVar6 * 2] != (uint)bVar4 ||
               ((&nvswitch_portmap_ls10)[lVar6 * 2] != uVar7 + 1))) {
          lVar6 = lVar6 + 1;
          if (lVar6 == 0x40) goto LAB_0024f9ea;
        }
      }
      else {
        if ((bVar1 != 3 && 5 < uVar7) || (0xb < bVar4)) goto LAB_0024f9ea;
        lVar6 = 0;
        while (((&nvswitch_portmap_ls10)[lVar6 * 2] != uVar7 ||
               ((&DAT_00cc7864)[lVar6 * 2] != (uint)bVar4))) {
          lVar6 = lVar6 + 1;
          if (lVar6 == 0x40) goto LAB_0024f9ea;
        }
      }
      uVar7 = (uint)uVar8;
      if (0x3f < uVar7) {
LAB_0024f9ea:
        nvswitch_assert_log();
        return 0xfffffff9;
      }
      iVar10 = iVar10 + 1;
      *(byte *)(param_4 + uVar8) = bVar5;
      *(int *)(param_3 + uVar8 * 4) = (int)lVar6;
      if (cVar11 == '\x02') {
        *(uint *)(param_6 + uVar12 * 4) = uVar7;
        *(undefined1 *)(param_7 + uVar12) = 1;
      }
      uVar8 = (ulong)(uVar7 + 1);
LAB_0024f93d:
      if ((bVar2 & 4) == 0) goto LAB_0024f954;
      goto LAB_0024f942;
    }
    cVar11 = '\0';
    if ((bVar2 & 0x10) != 0) goto LAB_0024fa5b;
LAB_0024fa6a:
    if (bVar3 != 0xf) goto LAB_0024f810;
    if (bVar4 != 0xf) goto LAB_0024f8b0;
    if ((bVar2 & 4) != 0) goto LAB_0024f942;
    iVar9 = iVar9 + 1;
    param_2 = param_2 + 8;
  } while( true );
}


// ===== 0024fb00 nvswitch_mc_invalidate_mc_rid_entry_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
nvswitch_mc_invalidate_mc_rid_entry_ls10
          (long param_1,undefined4 param_2,uint param_3,char param_4,char param_5)

{
  char cVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  cVar1 = nvswitch_is_link_valid();
  if (((cVar1 != '\0') && (param_3 < 0x10 || param_4 == '\0')) && (param_3 < 0x80)) {
    cVar1 = nvswitch_is_tnvl_mode_locked(param_1);
    if (cVar1 == '\0') {
      iVar2 = 4;
      (**(code **)(param_1 + 0x928))
                (param_1,5,0,param_2,0x5600,(uint)(param_4 != '\0') << 0x10 | param_3);
      if (param_5 != '\0') {
        do {
          (**(code **)(param_1 + 0x928))(param_1,5,0,param_2,0x5618,0);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
        iVar2 = 0x20;
        do {
          (**(code **)(param_1 + 0x928))(param_1,5,0,param_2,0x5614,0);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      (**(code **)(param_1 + 0x928))(param_1,5,0,param_2,0x5610,0);
      return 0;
    }
    return 0xfffffff1;
  }
  return 0xffffffff;
}


// ===== 0024fc40 nvswitch_mc_program_mc_rid_entry_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
nvswitch_mc_program_mc_rid_entry_ls10(long param_1,undefined4 param_2,byte *param_3,uint param_4)

{
  byte bVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  undefined8 uVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  
  if (param_1 != 0) {
    cVar3 = nvswitch_is_link_valid();
    if (((((param_3 == (byte *)0x0) || (cVar3 == '\0')) || ((param_3[1] != 0 && (0xf < *param_3))))
        || (((((char)*param_3 < '\0' || (0x20 < param_4)) || (0xf < (byte)(param_3[3] - 1))) ||
            (0x3f < (byte)(param_3[2] - 1))))) || ((param_3[6] != 0 && (0xf < param_3[4])))) {
      uVar5 = 0xffffffff;
    }
    else {
      cVar3 = nvswitch_is_tnvl_mode_locked(param_1);
      if (cVar3 == '\0') {
        (**(code **)(param_1 + 0x928))
                  (param_1,5,0,param_2,0x5600,(uint)(param_3[1] != 0) << 0x10 | *param_3 & 0x7f);
        uVar4 = (uint)param_3[3];
        if (param_3[3] != 0) {
          uVar8 = 0;
          do {
            iVar7 = (int)uVar8;
            lVar2 = uVar8 + 0x108;
            uVar8 = (ulong)(iVar7 + 1U);
            uVar6 = param_3[lVar2] & 0x1f;
            if (iVar7 + 1U < uVar4) {
              uVar6 = uVar6 | (param_3[uVar8 + 0x108] & 0x1f) << 8;
              uVar8 = (ulong)(iVar7 + 2U);
              if (iVar7 + 2U < uVar4) {
                uVar6 = uVar6 | (param_3[uVar8 + 0x108] & 0x1f) << 0x10;
                uVar8 = (ulong)(iVar7 + 3U);
                if (iVar7 + 3U < uVar4) {
                  lVar2 = uVar8 + 0x108;
                  uVar8 = (ulong)(iVar7 + 4);
                  uVar6 = uVar6 | (param_3[lVar2] & 0x1f) << 0x18;
                }
              }
            }
            (**(code **)(param_1 + 0x928))(param_1,5,0,param_2,0x5618,uVar6);
            uVar4 = (uint)param_3[3];
          } while ((uint)uVar8 < (uint)param_3[3]);
        }
        if (param_4 != 0) {
          uVar8 = 0;
          do {
            bVar1 = param_3[(uVar8 & 0xffffffff) * 8 + 0xf];
            (**(code **)(param_1 + 0x928))
                      (param_1,5,0,param_2,0x5614,
                       (bVar1 >> 2 & 1) << 0x12 |
                       (param_3[uVar8 * 8 + 10] & 3) << 5 | (param_3[uVar8 * 8 + 0xb] & 0xf) << 7 |
                       param_3[uVar8 * 8 + 9] & 0xf | (param_3[uVar8 * 8 + 0xc] & 3) << 0xc |
                       (param_3[uVar8 * 8 + 8] & 3) << 0xe | (bVar1 & 1) << 4 |
                       (bVar1 >> 1 & 1) << 0xb | (bVar1 >> 4 & 1) << 0x10 | (bVar1 >> 3 & 1) << 0x11
                      );
            uVar8 = uVar8 + 1;
          } while (uVar8 != param_4);
          uVar4 = (uint)param_3[3];
        }
        uVar4 = (param_3[6] & 1) << 0x1e |
                (uVar4 & 0xf) << 8 | (param_3[4] & 0xf) << 0x10 | param_3[2] - 1 & 0x3f | 0x80000000
        ;
        if (param_3[1] == 0) {
          uVar4 = uVar4 | (param_3[5] & 1) << 0x1d;
        }
        (**(code **)(param_1 + 0x928))(param_1,5,0,param_2,0x5610,uVar4);
        uVar5 = 0;
      }
      else {
        uVar5 = 0xfffffff1;
      }
    }
    return uVar5;
  }
  return 0xffffffff;
}


// ===== 0024ff60 nvswitch_mc_read_mc_rid_entry_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_mc_read_mc_rid_entry_ls10(long param_1,undefined4 param_2,byte *param_3)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  ulong uVar5;
  undefined8 uVar6;
  uint uVar7;
  ulong uVar8;
  
  if ((param_1 != 0) && (param_3 != (byte *)0x0)) {
    if (param_3[1] == 0) {
      if (-1 < (char)*param_3) {
LAB_0024ff8b:
        cVar2 = nvswitch_is_tnvl_mode_locked();
        if (cVar2 == '\0') {
          (**(code **)(param_1 + 0x928))
                    (param_1,5,0,param_2,0x5600,(uint)(param_3[1] != 0) << 0x10 | *param_3 & 0x7f);
          uVar5 = (**(code **)(param_1 + 0x920))(param_1,5,0,param_2,0x5610);
          param_3[7] = (byte)(uVar5 >> 0x1f) & 1;
          if ((int)uVar5 < 0) {
            param_3[2] = ((byte)uVar5 & 0x3f) + 1;
            bVar1 = (byte)(uVar5 >> 8) & 0xf;
            if ((uVar5 & 0xf00) == 0) {
              bVar1 = 0x10;
            }
            param_3[3] = bVar1;
            if (param_3[1] == 0) {
              param_3[4] = (byte)(uVar5 >> 0x10) & 0xf;
              param_3[6] = (byte)(uVar5 >> 0x1e) & 1;
            }
            uVar8 = 0;
            param_3[5] = (byte)(uVar5 >> 0x18) >> 5 & 1;
            do {
              uVar3 = (**(code **)(param_1 + 0x920))(param_1,5,0,param_2,0x5614);
              param_3[uVar8 * 8 + 9] = (byte)uVar3 & 0xf;
              uVar5 = uVar8 & 0xffffffff;
              param_3[uVar5 * 8 + 0xf] = param_3[uVar5 * 8 + 0xf] & 0xfe | (byte)(uVar3 >> 4) & 1;
              param_3[uVar8 * 8 + 10] = (byte)(uVar3 >> 5) & 3;
              param_3[uVar8 * 8 + 0xb] = (byte)(uVar3 >> 7) & 0xf;
              param_3[uVar5 * 8 + 0xf] =
                   param_3[uVar5 * 8 + 0xf] & 0xfd | ((byte)(uVar3 >> 0xb) & 1) * '\x02';
              param_3[uVar8 * 8 + 0xc] = (byte)(uVar3 >> 0xc) & 3;
              param_3[uVar8 * 8 + 8] = (byte)(uVar3 >> 0xe) & 3;
              uVar8 = uVar8 + 1;
              param_3[uVar5 * 8 + 0xf] =
                   (byte)((uVar3 >> 0x11 & 1) << 3) | (byte)((uVar3 >> 0x12 & 1) << 2) |
                   (byte)((uVar3 >> 0x10 & 1) << 4) | param_3[uVar5 * 8 + 0xf] & 0xe3;
            } while (uVar8 != 0x20);
            uVar3 = (uint)param_3[3];
            uVar5 = 0;
            while (uVar7 = (uint)uVar5, uVar7 < uVar3) {
              uVar4 = (**(code **)(param_1 + 0x920))(param_1,5,0,param_2,0x5618);
              param_3[uVar5 + 0x108] = (byte)uVar4 & 0x1f;
              bVar1 = param_3[3];
              uVar3 = (uint)bVar1;
              uVar5 = (ulong)(uVar7 + 1);
              if (uVar7 + 1 < (uint)bVar1) {
                param_3[uVar5 + 0x108] = (byte)((uint)uVar4 >> 8) & 0x1f;
                uVar5 = (ulong)(uVar7 + 2);
                if (uVar7 + 2 < (uint)bVar1) {
                  param_3[uVar5 + 0x108] = (byte)((uint)uVar4 >> 0x10) & 0x1f;
                  uVar5 = (ulong)(uVar7 + 3);
                  if (uVar7 + 3 < (uint)bVar1) {
                    param_3[uVar5 + 0x108] = (byte)((uint)uVar4 >> 0x18) & 0x1f;
                    uVar5 = (ulong)(uVar7 + 4);
                  }
                }
              }
            }
          }
          uVar6 = 0;
        }
        else {
          uVar6 = 0xfffffff1;
        }
        return uVar6;
      }
    }
    else if (*param_3 < 0x10) goto LAB_0024ff8b;
  }
  return 0xffffffff;
}


// ===== 00250220 nvswitch_init_pmgr_ls10 =====

void nvswitch_init_pmgr_ls10(long param_1)

{
  uint *puVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  ulong uVar6;
  
  nvswitch_i2c_init();
  lVar2 = *(long *)(param_1 + 0xf48);
  if (lVar2 == 0) {
    return;
  }
  *(undefined2 *)(lVar2 + 0x194) = 0x101;
  uVar6 = nvswitch_reg_read_32(param_1,0xd7a0);
  if ((((uVar6 & 0x10) == 0) || (uVar6 = nvswitch_reg_read_32(param_1,0xd7a4), (uVar6 & 0x10) == 0))
     || (uVar6 = nvswitch_reg_read_32(param_1,0xd7a8), (uVar6 & 0x10) == 0)) {
    *(undefined1 *)(lVar2 + 0x195) = 0;
  }
  lVar3 = *(long *)(param_1 + 0xf48);
  cVar4 = nvswitch_is_soe_supported(param_1);
  if ((cVar4 != '\0') &&
     (iVar5 = nvswitch_os_alloc_contig_memory
                        (*(undefined8 *)(param_1 + 0x18),lVar3 + 0x198,0x200,
                         *(int *)(param_1 + 0xf38) == 0x20), iVar5 == 0)) {
    nvswitch_os_memset(*(undefined8 *)(lVar3 + 0x198),0,0x200);
    iVar5 = nvswitch_os_map_dma_region
                      (*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(lVar3 + 0x198),lVar3 + 0x1a0,
                       0x200,2);
    if (iVar5 == 0) goto LAB_002502f9;
    nvswitch_os_free_contig_memory
              (*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(lVar3 + 0x198),0x200);
    *(undefined8 *)(lVar3 + 0x198) = 0;
  }
  *(undefined1 *)(lVar2 + 0x194) = 0;
LAB_002502f9:
  lVar2 = *(long *)(param_1 + 0xf48);
  puVar1 = (uint *)(lVar2 + 0x164);
  *puVar1 = *puVar1 | 3;
  *(undefined4 *)(lVar2 + 0x50) = 0;
  lVar2 = *(long *)(param_1 + 0xf48);
  puVar1 = (uint *)(lVar2 + 0x168);
  *puVar1 = *puVar1 | 3;
  *(undefined4 *)(lVar2 + 0xa8) = 0;
  lVar2 = *(long *)(param_1 + 0xf48);
  puVar1 = (uint *)(lVar2 + 0x16c);
  *puVar1 = *puVar1 | 3;
  *(undefined4 *)(lVar2 + 0x100) = 0;
  return;
}


// ===== 002503b0 nvswitch_init_pmgr_devices_ls10 =====

void nvswitch_init_pmgr_devices_ls10(long param_1)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  undefined1 *puVar5;
  short local_a;
  
  lVar4 = 0;
  if (*(int *)(param_1 + 0x1f88) == 7) {
    lVar4 = *(long *)(param_1 + 0x1f90);
  }
  lVar1 = *(long *)(param_1 + 0xf48);
  if (((*(char *)(param_1 + 0x26) == '\0') && (*(char *)(param_1 + 0x24) == '\0')) &&
     (*(char *)(param_1 + 0x25) == '\0')) {
    iVar3 = nvswitch_get_board_id(param_1,&local_a);
    if ((iVar3 == 0) && (local_a == 0x571)) {
      puVar5 = nvswitch_gpio_pin_4300;
      uVar2 = 5;
    }
    else {
      puVar5 = nvswitch_gpio_pin_Default;
      uVar2 = 3;
    }
  }
  else {
    puVar5 = (undefined1 *)0x0;
    uVar2 = 0;
  }
  *(undefined1 **)(lVar4 + 0xddd0) = puVar5;
  *(undefined4 *)(&DAT_0000ddd8 + lVar4) = uVar2;
  *(undefined8 *)(lVar1 + 0x178) = 0;
  *(undefined4 *)(lVar1 + 0x180) = 0;
  return;
}


// ===== 00250460 nvswitch_get_rom_info_ls10 =====

undefined8 nvswitch_get_rom_info_ls10(void)

{
  return 0;
}


// ===== 00250467 nvswitch_read_physical_id_ls10.cold =====

void nvswitch_read_physical_id_ls10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00250470 nvswitch_read_physical_id_ls10 =====

uint nvswitch_read_physical_id_ls10(long param_1)

{
  undefined1 *puVar1;
  long lVar2;
  code *pcVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  
  if (*(int *)(param_1 + 0x1f88) != 7) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar2 = *(long *)(param_1 + 0x1f90);
  uVar7 = 0;
  if (*(int *)(&DAT_0000ddd8 + lVar2) != 0) {
    uVar7 = 0;
    lVar6 = 0;
    lVar5 = *(long *)(lVar2 + 0xddd0);
    do {
      puVar1 = (undefined1 *)(lVar5 + lVar6 * 0x10);
      if (*(int *)(puVar1 + 4) - 0xd1U < 7) {
        nvswitch_reg_write_32(param_1,0xd740,CONCAT11(*(int *)(puVar1 + 0xc) == 0xb,*puVar1));
        uVar4 = nvswitch_reg_read_32(param_1,0xd740);
        lVar5 = *(long *)(lVar2 + 0xddd0);
        uVar7 = uVar7 | (uVar4 >> 9 & 1) <<
                        ((char)*(undefined4 *)(lVar5 + 4 + lVar6 * 0x10) + 0x2fU & 0x1f);
      }
      lVar6 = lVar6 + 1;
    } while ((uint)lVar6 < *(uint *)(&DAT_0000ddd8 + lVar2));
  }
  return uVar7;
}


// ===== 00250560 nvswitch_ctrl_i2c_indexed_ls10 =====

undefined8 nvswitch_ctrl_i2c_indexed_ls10(long param_1,char *param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0xf48);
  if (lVar1 != 0) {
    if (param_2 == (char *)0x0) {
      return 0xffffffff;
    }
    if ((*(int *)(param_1 + 0xc0) != 1) && ((*(uint *)(param_2 + 4) & 0x100) == 0)) {
      if (*param_2 == '\0') {
        *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffff1ff | 0x600;
      }
      if (*(char *)(lVar1 + 0x194) == '\0') {
        return 0xfffffff3;
      }
      uVar2 = soeI2CAccess_HAL();
      return uVar2;
    }
    if (*(char *)(lVar1 + 0x195) != '\0') {
      uVar2 = nvswitch_ctrl_i2c_indexed_lr10();
      return uVar2;
    }
  }
  return 0xfffffff3;
}


// ===== 002505d0 nvswitch_is_i2c_supported_ls10 =====

bool nvswitch_is_i2c_supported_ls10(long param_1)

{
  long lVar1;
  bool bVar2;
  
  lVar1 = *(long *)(param_1 + 0xf48);
  bVar2 = false;
  if ((lVar1 != 0) && (bVar2 = true, *(char *)(lVar1 + 0x194) == '\0')) {
    return *(char *)(lVar1 + 0x195) != '\0';
  }
  return bVar2;
}


// ===== 00250610 nvswitch_i2c_is_device_access_allowed_ls10 =====

undefined8 nvswitch_i2c_is_device_access_allowed_ls10(void)

{
  return 1;
}


// ===== 00250620 nvswitch_i2c_get_port_info_ls10 =====

undefined8 nvswitch_i2c_get_port_info_ls10(undefined8 param_1,int param_2)

{
  int iVar1;
  undefined8 uVar2;
  short local_1a;
  
  iVar1 = nvswitch_get_board_id(param_1,&local_1a);
  if ((iVar1 == 0) && ((local_1a != 0x4fe || (param_2 != 2)))) {
    uVar2 = nvswitch_i2c_get_port_info_lr10(param_1,param_2);
    return uVar2;
  }
  return 0;
}


// ===== 00250680 nvswitch_smbpbi_alloc_ls10 =====

undefined8 nvswitch_smbpbi_alloc_ls10(void)

{
  return 0;
}


// ===== 00250690 nvswitch_smbpbi_post_init_hal_ls10 =====

undefined8 nvswitch_smbpbi_post_init_hal_ls10(void)

{
  return 0;
}


// ===== 002506a0 nvswitch_smbpbi_destroy_hal_ls10 =====

void nvswitch_smbpbi_destroy_hal_ls10(void)

{
  return;
}


// ===== 002506b0 nvswitch_smbpbi_get_dem_num_messages_ls10 =====

undefined8 nvswitch_smbpbi_get_dem_num_messages_ls10(void)

{
  return 0xfffffff3;
}


// ===== 002506c0 nvswitch_smbpbi_dem_load_ls10 =====

undefined8 nvswitch_smbpbi_dem_load_ls10(void)

{
  return 0xfffffff3;
}


// ===== 002506d0 nvswitch_smbpbi_log_message_ls10 =====

undefined1  [16]
nvswitch_smbpbi_log_message_ls10(long param_1,undefined4 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  undefined8 in_RAX;
  ulong uVar4;
  undefined8 uVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 local_84 [4];
  undefined1 local_80 [12];
  undefined2 local_74 [2];
  undefined1 local_70;
  undefined1 local_6f;
  undefined1 local_6e;
  undefined1 local_6d;
  undefined4 local_6c;
  undefined4 local_68;
  undefined1 local_64 [52];
  
  lVar1 = *(long *)(param_1 + 0xf50);
  if ((lVar1 == 0) || (*(long *)(param_1 + 0xd20) == 0)) {
    auVar12._8_8_ = param_3;
    auVar12._0_8_ = in_RAX;
    return auVar12;
  }
  uVar9 = *(uint *)(lVar1 + 0x10);
  auVar10._4_4_ = 0;
  auVar10._0_4_ = uVar9;
  auVar10._8_4_ = uVar9 + 1;
  *(int *)(lVar1 + 0x10) = auVar10._8_4_;
  if (uVar9 != 0) {
    auVar10._12_4_ = 0;
    return auVar10;
  }
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0xd20) + 8);
  nvswitch_os_memset(local_74,0,0x3c);
  local_70 = 4;
  uVar7 = (uint)param_3;
  local_74[0] = 0x3c09;
  uVar9 = 0x50;
  if (uVar7 < 0x51) {
    uVar9 = uVar7;
  }
  local_6f = (undefined1)uVar9;
  local_6c = param_2;
  uVar4 = nvswitch_os_get_platform_time_epoch();
  auVar3._8_8_ = 0;
  auVar3._0_8_ = uVar4 >> 9;
  uVar5 = SUB168(auVar3 * ZEXT816(0x44b82fa09b5a53),0);
  puVar6 = (undefined1 *)((uVar4 >> 9) / 0x1dcd65);
  local_68 = SUB84(puVar6,0);
  if (uVar7 != 0) {
    uVar7 = 0;
    do {
      uVar8 = 0x2a;
      if (uVar9 < 0x2b) {
        uVar8 = uVar9;
      }
      nvswitch_os_memcpy(local_64,(ulong)(uVar7 & 0xff) + param_4);
      local_6d = (undefined1)uVar8;
      local_6e = (char)uVar7;
      nvswitch_timeout_create(1000000000,local_80);
      puVar6 = local_84;
      uVar5 = flcnQueueCmdPostBlocking(param_1,uVar2,local_74,0,0,0,puVar6,local_80);
      if ((int)uVar5 != 0) break;
      uVar7 = uVar7 + uVar8;
      uVar9 = uVar9 - uVar8;
    } while (uVar9 != 0);
  }
  *(undefined4 *)(lVar1 + 0x10) = 0;
  auVar11._8_8_ = puVar6;
  auVar11._0_8_ = uVar5;
  return auVar11;
}


// ===== 00250880 nvswitch_smbpbi_send_init_data_ls10 =====

undefined1  [16] nvswitch_smbpbi_send_init_data_ls10(long param_1,undefined8 param_2,ulong param_3)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 *puVar4;
  undefined1 local_74 [4];
  undefined1 local_70 [12];
  undefined2 local_64 [2];
  undefined1 local_60;
  undefined1 local_5f [15];
  undefined1 local_50;
  
  if (*(long *)(param_1 + 0xf50) != 0) {
    uVar1 = *(undefined8 *)(*(long *)(param_1 + 0xd20) + 8);
    nvswitch_os_memset(local_64,0,0x3c);
    local_60 = 5;
    local_64[0] = 0x1509;
    nvswitch_os_strncpy(local_5f,"595.71.05",0x10);
    local_50 = 0;
    nvswitch_timeout_create(1000000000,local_70);
    puVar4 = local_74;
    auVar3._0_8_ = flcnQueueCmdPostBlocking(param_1,uVar1,local_64,0,0,0,puVar4,local_70);
    auVar3._8_8_ = puVar4;
    return auVar3;
  }
  auVar2._8_8_ = 0;
  auVar2._0_8_ = param_3;
  return auVar2 << 0x40;
}


// ===== 00250930 nvswitch_smbpbi_send_unload_ls10 =====

void nvswitch_smbpbi_send_unload_ls10(void)

{
  nvswitch_smbpbi_send_unload_lr10();
  return;
}


// ===== 00250940 nvswitch_smbpbi_dem_flush_ls10 =====

void nvswitch_smbpbi_dem_flush_ls10(void)

{
  return;
}


// ===== 00250950 _soeFetchEngines_LS10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _soeFetchEngines_LS10(long param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined1 *)(param_3 + 1) = 0;
  iVar1 = (**(code **)(param_1 + 0x910))(param_1,2,0,0);
  if (iVar1 == -1) {
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(param_1 + 0x910))(param_1,2,0,0);
  }
  *param_3 = uVar2;
  *(undefined1 *)(param_4 + 1) = 0;
  *param_4 = 0;
  return;
}


// ===== 002509d0 _nvswitch_soe_attach_detach_driver_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

void _nvswitch_soe_attach_detach_driver_ls10(long param_1,char param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (**(code **)(param_1 + 0x920))(param_1,1,0,0,0x514);
  uVar1 = uVar2 | 1;
  if (param_2 == '\0') {
    uVar1 = uVar2 & 0xfffffffe;
  }
  (**(code **)(param_1 + 0x928))(param_1,1,0,0,0x514,uVar1);
  return;
}


// ===== 00250a30 _soeIsCpuHalted_LS10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint _soeIsCpuHalted_LS10(long param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(param_1 + 0x920))(param_1,2,0,0,5000);
  return uVar1 >> 4 & 1;
}


// ===== 00250a60 _soeIntrStatus_LS10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint _soeIntrStatus_LS10(long param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = (**(code **)(param_1 + 0x920))(param_1,2,0,0,8);
  uVar2 = (**(code **)(param_1 + 0x920))(param_1,2,0,0,0x1528);
  uVar3 = (**(code **)(param_1 + 0x920))(param_1,2,0,0,0x152c);
  return uVar3 & uVar1 & uVar2;
}


// ===== 00250ae0 _soeHandleInitEvent_LS10 =====

undefined8 _soeHandleInitEvent_LS10(void)

{
  nvswitch_assert_log();
  return 0xffff;
}


// ===== 00250b00 _soeUpdateInitMsgQueuesInfo =====

ulong _soeUpdateInitMsgQueuesInfo(undefined8 param_1,long param_2)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  long local_30 [2];
  
  lVar1 = *(long *)(param_2 + 8);
  if (lVar1 == 0) {
    nvswitch_assert_log();
  }
  lVar2 = *(long *)(lVar1 + 0x58);
  if (lVar2 == 0) {
    nvswitch_assert_log();
  }
  local_30[0] = *(long *)(lVar2 + 0x30);
  uVar3 = flcnQueueConstruct_dmem_nvswitch(param_1,lVar1,local_30,0,0,0x1000080,0x80,4);
  if ((int)uVar3 == 0) {
    local_30[0] = *(long *)(lVar2 + 0x30) + 0xa8;
    uVar3 = flcnQueueConstruct_dmem_nvswitch(param_1,lVar1,local_30,1,0,0x1000000,0x80,4);
    if ((int)uVar3 == 0) {
      *(undefined1 *)(lVar1 + 0x31) = 1;
      return uVar3;
    }
  }
  nvswitch_assert_log();
  return uVar3 & 0xffffffff;
}


// ===== 00250be0 _soeProcessMessages_LS10 =====

ulong _soeProcessMessages_LS10(undefined8 param_1,long param_2)

{
  long lVar1;
  byte bVar2;
  uint uVar3;
  ulong uVar4;
  undefined1 local_58 [2];
  byte local_56;
  
  lVar1 = *(long *)(param_2 + 8);
  if (*(char *)(lVar1 + 0x31) == '\0') {
    uVar3 = _soeUpdateInitMsgQueuesInfo();
    if (uVar3 != 0) {
      nvswitch_assert_log();
      return (ulong)uVar3;
    }
    _nvswitch_soe_attach_detach_driver_ls10(param_1,1);
  }
  while (uVar4 = flcnQueueReadData(param_1,lVar1,1,local_58,1), (int)uVar4 == 0) {
    bVar2 = local_56 & 4;
    local_56 = local_56 & 4;
    if (bVar2 == 0) {
      flcnQueueResponseHandle(param_1,lVar1,local_58);
    }
    else {
      flcnQueueEventHandle(param_1,lVar1,local_58,0);
    }
  }
  return uVar4;
}


// ===== 00250c90 _soeServiceHalt_LS10 =====

void _soeServiceHalt_LS10(undefined8 param_1,long param_2)

{
  flcnDbgInfoCaptureRiscvPcTrace_HAL(param_1,*(undefined8 *)(param_2 + 8));
  nvswitch_assert_log();
  return;
}


// ===== 00250cb0 _soeService_LS10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 _soeService_LS10(long *param_1,long param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  long lVar7;
  uint uVar8;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  undefined8 uVar9;
  
  lVar1 = *(long *)(param_2 + 8);
  if (lVar1 == 0) {
    nvswitch_assert_log();
    return 0x1f;
  }
  uVar4 = _soeIntrStatus_LS10();
  if (uVar4 == 0) {
    return 0;
  }
  if ((uVar4 & 2) == 0) {
    uVar8 = 0;
    uVar9 = extraout_RDX;
  }
  else {
    iVar6 = nvswitch_translate_hw_error(0x6598);
    if (iVar6 == 1) {
      nvswitch_assert_log();
    }
    lVar2 = *param_1;
    uVar8 = 2;
    nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, SOE Watchdog error\n",
                      param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                      *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x6598);
    nvswitch_os_report_error(param_1[3],0x6598,"SOE Watchdog error\n");
    nvswitch_lib_smbpbi_log_sxid(param_1,0x6598,"SOE Watchdog error\n");
    nvswitch_inforom_bbx_add_sxid(param_1,0x6598,0,0,0);
    nvswitch_assert_log();
    uVar9 = extraout_RDX_00;
  }
  if ((uVar4 & 0x20) != 0) {
    uVar8 = uVar8 | 0x20;
    iVar6 = nvswitch_translate_hw_error(0x6597);
    if (iVar6 == 1) {
      nvswitch_assert_log();
    }
    lVar2 = *param_1;
    nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, SOE EXTERR\n",param_1 + 1,
                      *(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                      *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x6597);
    nvswitch_os_report_error(param_1[3],0x6597,"SOE EXTERR\n");
    nvswitch_lib_smbpbi_log_sxid(param_1,0x6597,"SOE EXTERR\n");
    nvswitch_inforom_bbx_add_sxid(param_1,0x6597,0,0,0);
    uVar9 = extraout_RDX_01;
  }
  if ((uVar4 & 0x10) != 0) {
    uVar8 = uVar8 | 0x10;
    iVar6 = nvswitch_translate_hw_error(0x6596);
    if (iVar6 == 1) {
      nvswitch_assert_log();
    }
    lVar2 = *param_1;
    uVar9 = 0x6596;
    nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, SOE HALTED\n",param_1 + 1,
                      *(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                      *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46));
    nvswitch_os_report_error(param_1[3],0x6596,"SOE HALTED\n");
    nvswitch_lib_smbpbi_log_sxid(param_1,0x6596,"SOE HALTED\n");
    nvswitch_inforom_bbx_add_sxid(param_1,0x6596,0,0,0);
    soeServiceHalt_HAL(param_1,param_2);
  }
  if ((uVar4 & 0x40) == 0) {
    if ((uVar4 & 0x80) != 0) {
      uVar8 = uVar8 | 0x80;
    }
    flcnRegWrite_HAL(param_1,lVar1,4,uVar8);
    uVar5 = _soeIntrStatus_LS10(param_1);
  }
  else {
    soeProcessMessages_HAL(param_1,param_2,uVar9);
    if ((uVar4 & 0x80) == 0) {
      uVar8 = uVar8 | 0x40;
    }
    else {
      uVar8 = uVar8 | 0xc0;
    }
    flcnRegWrite_HAL(param_1,lVar1,4,uVar8);
    uVar5 = _soeIntrStatus_LS10(param_1);
    lVar2 = *(long *)(lVar1 + 0x58);
    if (lVar2 == 0) {
      nvswitch_assert_log();
    }
    lVar7 = *(long *)(lVar2 + 0x30);
    if (lVar7 == 0) {
      nvswitch_assert_log();
      lVar7 = *(long *)(lVar2 + 0x30);
    }
    cVar3 = (**(code **)(lVar7 + 0xb0))(param_1,lVar1,lVar7 + 0xa8);
    if (cVar3 == '\0') {
      flcnRegWrite_HAL(param_1,lVar1,0,0x40);
    }
  }
  flcnIntrRetrigger_HAL(param_1,lVar1);
  return uVar5;
}


// ===== 00251060 _soeWaitForInitAck_LS10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _soeWaitForInitAck_LS10(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  
  lVar1 = *(long *)(param_2 + 8);
  uVar3 = (**(code **)(param_1 + 0x920))(param_1,1,0,0,0x4ec);
  if ((uVar3 & 1) == 0) {
    nvswitch_assert_log();
    return 0x55;
  }
  iVar2 = 0;
  if (*(char *)(lVar1 + 0x31) == '\0') {
    iVar2 = _soeUpdateInitMsgQueuesInfo(param_1,param_2);
    if (iVar2 == 0) {
      _nvswitch_soe_attach_detach_driver_ls10(param_1,1);
      return 0;
    }
    nvswitch_assert_log();
  }
  return iVar2;
}


// ===== 00251110 _soeI2CAccess_LS10 =====

ulong _soeI2CAccess_LS10(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  ulong uVar6;
  undefined4 local_84;
  undefined1 local_80 [12];
  undefined2 local_74 [2];
  undefined1 local_70;
  undefined8 local_6c;
  undefined2 local_64;
  
  if (param_2 == 0) {
    return 0xffffffff;
  }
  lVar1 = *(long *)(param_1 + 0xf48);
  if ((lVar1 != 0) && (*(char *)(lVar1 + 0x194) != '\0')) {
    uVar2 = *(undefined8 *)(lVar1 + 0x1a0);
    lVar1 = *(long *)(lVar1 + 0x198);
    uVar6 = nvswitch_os_sync_dma_region_for_cpu(*(undefined8 *)(param_1 + 0x18),uVar2,0x200,1);
    if ((int)uVar6 == 0) {
      nvswitch_os_memcpy(lVar1,param_2,0x114);
      uVar6 = nvswitch_os_sync_dma_region_for_device(*(undefined8 *)(param_1 + 0x18),uVar2,0x200,1);
      if ((int)uVar6 == 0) {
        uVar3 = *(undefined8 *)(*(long *)(param_1 + 0xd20) + 8);
        cVar4 = nvswitch_is_tnvl_mode_locked(param_1);
        if (cVar4 == '\0') {
          nvswitch_os_memset(local_74,0,0x3c);
          local_74[0] = 0x140b;
          local_64 = 0x200;
          local_70 = 3;
          local_84 = 0;
          local_6c = uVar2;
          nvswitch_timeout_create(5000000000,local_80);
          iVar5 = flcnQueueCmdPostBlocking(param_1,uVar3,local_74,0,0,0,&local_84,local_80);
          if (iVar5 == 0) {
            uVar6 = nvswitch_os_sync_dma_region_for_cpu
                              (*(undefined8 *)(param_1 + 0x18),uVar2,0x200,0);
            if ((int)uVar6 == 0) {
              nvswitch_os_memcpy(param_2,lVar1,0x114);
              if (*(byte *)(lVar1 + 0x1ff) < 0x3f) {
                uVar6 = (ulong)(uint)(int)(char)CSWTCH_8[*(byte *)(lVar1 + 0x1ff)];
              }
              else {
                uVar6 = 0xfffffff9;
              }
            }
          }
          else {
            uVar6 = 0xfffffff8;
          }
        }
        else {
          uVar6 = 0xf;
        }
      }
    }
    return uVar6;
  }
  return 0xfffffff3;
}


// ===== 002512e0 nvswitch_soe_issue_nport_reset_ls10 =====

uint nvswitch_soe_issue_nport_reset_ls10(long param_1,undefined4 param_2)

{
  undefined8 uVar1;
  int iVar2;
  undefined4 local_74;
  undefined1 local_70 [12];
  undefined2 local_64 [2];
  undefined1 local_60;
  undefined4 local_5c;
  
  local_74 = 0;
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0xd20) + 8);
  nvswitch_os_memset(local_64,0,0x3c);
  local_64[0] = 0xc0b;
  local_60 = 4;
  local_5c = param_2;
  nvswitch_timeout_create(5000000,local_70);
  iVar2 = flcnQueueCmdPostBlocking(param_1,uVar1,local_64,0,0,0,&local_74,local_70);
  return -(uint)(iVar2 != 0) & 0xfffffff8;
}


// ===== 00251370 nvswitch_soe_restore_nport_state_ls10 =====

uint nvswitch_soe_restore_nport_state_ls10(long param_1,undefined4 param_2)

{
  undefined8 uVar1;
  int iVar2;
  undefined4 local_74;
  undefined1 local_70 [12];
  undefined2 local_64 [2];
  undefined1 local_60;
  undefined4 local_5c;
  
  local_74 = 0;
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0xd20) + 8);
  nvswitch_os_memset(local_64,0,0x3c);
  local_64[0] = 0xc0b;
  local_60 = 5;
  local_5c = param_2;
  nvswitch_timeout_create(5000000,local_70);
  iVar2 = flcnQueueCmdPostBlocking(param_1,uVar1,local_64,0,0,0,&local_74,local_70);
  return -(uint)(iVar2 != 0) & 0xfffffff8;
}


// ===== 00251400 nvswitch_set_nport_tprod_state_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint nvswitch_set_nport_tprod_state_ls10(long param_1,undefined4 param_2)

{
  undefined8 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_74;
  undefined1 local_70 [12];
  undefined2 local_64 [2];
  undefined1 local_60;
  undefined4 local_5c;
  
  local_74 = 0;
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0xd20) + 8);
  iVar2 = (**(code **)(param_1 + 0x910))(param_1,5,0,param_2);
  if (iVar2 == -1) {
    uVar3 = 0xffffffff;
  }
  else {
    nvswitch_os_memset(local_64,0,0x3c);
    local_64[0] = 0xc0b;
    local_60 = 6;
    local_5c = param_2;
    nvswitch_timeout_create(5000000,local_70);
    iVar2 = flcnQueueCmdPostBlocking(param_1,uVar1,local_64,0,0,0,&local_74,local_70);
    uVar3 = -(uint)(iVar2 != 0) & 0xfffffff8;
  }
  return uVar3;
}


// ===== 002514c0 nvswitch_soe_init_l2_state_ls10 =====

void nvswitch_soe_init_l2_state_ls10(long param_1)

{
  undefined8 uVar1;
  char cVar2;
  undefined4 local_64;
  undefined1 local_60 [12];
  undefined2 local_54 [2];
  undefined1 local_50;
  
  local_64 = 0;
  cVar2 = nvswitch_is_soe_supported();
  if (cVar2 != '\0') {
    uVar1 = *(undefined8 *)(*(long *)(param_1 + 0xd20) + 8);
    nvswitch_os_memset(local_54,0,0x3c);
    local_54[0] = 0x50b;
    local_50 = 8;
    nvswitch_timeout_create(5000000,local_60);
    flcnQueueCmdPostBlocking(param_1,uVar1,local_54,0,0,0,&local_64,local_60);
  }
  return;
}


// ===== 00251550 nvswitch_soe_set_nport_interrupts_ls10 =====

uint nvswitch_soe_set_nport_interrupts_ls10(long param_1,undefined4 param_2,undefined1 param_3)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_74;
  undefined1 local_70 [12];
  undefined2 local_64 [2];
  undefined1 local_60;
  undefined4 local_5c;
  undefined1 local_58;
  
  local_74 = 0;
  cVar2 = nvswitch_is_soe_supported();
  if (cVar2 == '\0') {
    uVar4 = 0xfffffff8;
  }
  else {
    uVar1 = *(undefined8 *)(*(long *)(param_1 + 0xd20) + 8);
    nvswitch_os_memset(local_64,0,0x3c);
    local_64[0] = 0x100b;
    local_60 = 10;
    local_5c = param_2;
    local_58 = param_3;
    nvswitch_timeout_create(5000000,local_70);
    iVar3 = flcnQueueCmdPostBlocking(param_1,uVar1,local_64,0,0,0,&local_74,local_70);
    uVar4 = -(uint)(iVar3 != 0) & 0xfffffff9;
  }
  return uVar4;
}


// ===== 00251610 nvswitch_soe_disable_nport_fatal_interrupts_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_soe_disable_nport_fatal_interrupts_ls10
               (long param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  undefined4 local_8c;
  undefined1 local_88 [8];
  undefined8 local_80;
  undefined2 local_74 [2];
  undefined1 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined1 local_64;
  
  local_8c = 0;
  local_80 = 0;
  iVar3 = (**(code **)(param_1 + 0x808))(param_1,&local_80);
  if ((iVar3 == 0) && (0x36ffff < ((uint)local_80 & 0xff0000))) {
    cVar2 = nvswitch_is_soe_supported(param_1);
    if (cVar2 != '\0') {
      uVar1 = *(undefined8 *)(*(long *)(param_1 + 0xd20) + 8);
      nvswitch_os_memset(local_74,0,0x3c);
      local_74[0] = 0x140b;
      local_70 = 0xf;
      local_6c = param_2;
      local_68 = param_3;
      local_64 = param_4;
      nvswitch_timeout_create(5000000,local_88);
      flcnQueueCmdPostBlocking(param_1,uVar1,local_74,0,0,0,&local_8c,local_88);
    }
  }
  return;
}


// ===== 00251710 nvswitch_soe_issue_ingress_stop_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 nvswitch_soe_issue_ingress_stop_ls10(long param_1,undefined4 param_2,char param_3)

{
  undefined8 uVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 local_94;
  undefined1 local_90 [8];
  undefined8 local_88;
  undefined1 local_80 [12];
  undefined2 local_74 [2];
  undefined1 local_70;
  undefined4 local_6c;
  char local_68;
  
  local_94 = 0;
  local_88 = 0;
  cVar2 = nvswitch_is_soe_supported();
  if ((cVar2 == '\0') || (iVar4 = (**(code **)(param_1 + 0x808))(param_1,&local_88), iVar4 != 0)) {
    uVar6 = 0;
  }
  else {
    uVar6 = 0;
    if (0x4bffff < ((uint)local_88 & 0xff0000)) {
      uVar1 = *(undefined8 *)(*(long *)(param_1 + 0xd20) + 8);
      nvswitch_os_memset(local_74,0,0x3c);
      local_74[0] = 0x100b;
      local_70 = 0x10;
      local_6c = param_2;
      local_68 = param_3;
      nvswitch_timeout_create(5000000,local_90);
      iVar4 = flcnQueueCmdPostBlocking(param_1,uVar1,local_74,0,0,0);
      if (iVar4 == 0) {
        if (param_3 == '\0') {
          return 0;
        }
        nvswitch_timeout_create(1000000,local_90,&local_94,local_90);
        do {
          cVar2 = nvswitch_timeout_check(local_90);
          uVar5 = (**(code **)(param_1 + 0x920))(param_1,5,0,param_2,0x474);
          if ((~uVar5 & 3) == 0) {
            return 0;
          }
          if (*(char *)(param_1 + 0x26) == '\0') {
            nvswitch_timeout_create(2000,local_80);
            do {
              cVar3 = nvswitch_timeout_check(local_80);
            } while (cVar3 == '\0');
          }
        } while (cVar2 == '\0');
        if ((uVar5 & 1) != 0) {
          if ((uVar5 & 2) != 0) {
            return 0;
          }
          return 0xfffffff9;
        }
      }
      uVar6 = 0xfffffff9;
    }
  }
  return uVar6;
}


// ===== 002518e0 nvswitch_soe_clear_engine_interrupt_counter_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint nvswitch_soe_clear_engine_interrupt_counter_ls10
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_8c;
  undefined1 local_88 [8];
  undefined8 local_80;
  undefined2 local_74 [2];
  undefined1 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  
  local_8c = 0;
  local_80 = 0;
  cVar2 = nvswitch_is_soe_supported();
  uVar4 = 0;
  if (cVar2 != '\0') {
    iVar3 = (**(code **)(param_1 + 0x808))(param_1,&local_80);
    if ((iVar3 == 0) && (0x6dffff < ((uint)local_80 & 0xff0000))) {
      uVar1 = *(undefined8 *)(*(long *)(param_1 + 0xd20) + 8);
      nvswitch_os_memset(local_74,0,0x3c);
      local_74[0] = 0x140b;
      local_70 = 0x11;
      local_6c = param_2;
      local_68 = param_3;
      local_64 = param_4;
      nvswitch_timeout_create(5000000,local_88);
      iVar3 = flcnQueueCmdPostBlocking(param_1,uVar1,local_74,0,0,0,&local_8c,local_88);
      uVar4 = -(uint)(iVar3 != 0) & 0xfffffff9;
    }
    else {
      uVar4 = 0xfffffff3;
    }
  }
  return uVar4;
}


// ===== 00251a00 nvswitch_soe_update_intr_report_en_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
nvswitch_soe_update_intr_report_en_ls10
          (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_8c;
  undefined1 local_88 [8];
  undefined8 local_80;
  undefined2 local_74 [2];
  undefined1 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  
  local_8c = 0;
  local_80 = 0;
  cVar1 = nvswitch_is_soe_supported();
  if (((cVar1 == '\0') || (iVar2 = (**(code **)(param_1 + 0x808))(param_1,&local_80), iVar2 != 0))
     || (((uint)local_80 & 0xff0000) < 0x6e0000)) {
    uVar3 = 0xfffffff3;
  }
  else {
    uVar3 = *(undefined8 *)(*(long *)(param_1 + 0xd20) + 8);
    nvswitch_os_memset(local_74,0,0x3c);
    local_70 = 0x12;
    local_74[0] = 0x180b;
    local_6c = param_2;
    local_68 = param_3;
    local_64 = param_4;
    local_60 = param_5;
    nvswitch_timeout_create(5000000,local_88);
    iVar2 = flcnQueueCmdPostBlocking(param_1,uVar3,local_74,0,0,0,&local_8c,local_88);
    uVar3 = 0xfffffff9;
    if (iVar2 == 0) {
      uVar3 = 0;
    }
  }
  return uVar3;
}


// ===== 00251b40 nvswitch_soe_reg_wr_32_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint nvswitch_soe_reg_wr_32_ls10(long *param_1,uint param_2,undefined4 param_3)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  undefined4 local_7c;
  undefined1 local_78 [8];
  undefined8 local_70;
  undefined2 local_64 [2];
  undefined1 local_60;
  uint local_5c;
  undefined4 local_58;
  
  local_7c = 0;
  local_70 = 0;
  cVar2 = nvswitch_is_soe_supported();
  if (cVar2 != '\0') {
    if (*(long *)(*param_1 + 0x78) == 0) {
      return 0xfffffff5;
    }
    iVar3 = (*(code *)param_1[0x101])(param_1,&local_70);
    if ((iVar3 == 0) && (0x60ffff < ((uint)local_70 & 0xff0000))) {
      uVar1 = *(undefined8 *)(param_1[0x1a4] + 8);
      nvswitch_os_memset(local_64,0,0x3c);
      local_64[0] = 0x1010;
      local_60 = 0;
      local_5c = param_2;
      local_58 = param_3;
      nvswitch_timeout_create(5000000,local_78);
      iVar3 = flcnQueueCmdPostBlocking(param_1,uVar1,local_64,0,0,0,&local_7c,local_78);
      return -(uint)(iVar3 != 0) & 0xfffffff9;
    }
    nvswitch_os_mem_write32((ulong)param_2 + *(long *)(*param_1 + 0x78),param_3);
  }
  return 0;
}


// ===== 00251c60 nvswitch_soe_eng_wr_32_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint nvswitch_soe_eng_wr_32_ls10
               (long *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,uint param_6,undefined4 param_7)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  undefined4 local_8c;
  undefined1 local_88 [8];
  undefined8 local_80;
  undefined2 local_74 [2];
  undefined1 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  uint local_5c;
  undefined4 local_58;
  
  local_8c = 0;
  local_80 = 0;
  cVar2 = nvswitch_is_soe_supported();
  if (cVar2 != '\0') {
    if (*(long *)(*param_1 + 0x78) == 0) {
      return 0xfffffff5;
    }
    iVar3 = (*(code *)param_1[0x101])(param_1,&local_80);
    if ((iVar3 == 0) && (0x60ffff < ((uint)local_80 & 0xff0000))) {
      uVar1 = *(undefined8 *)(param_1[0x1a4] + 8);
      nvswitch_os_memset(local_74,0,0x3c);
      local_74[0] = 0x2010;
      local_70 = 2;
      local_58 = param_7;
      local_6c = param_2;
      local_68 = param_3;
      local_64 = param_4;
      local_60 = param_5;
      local_5c = param_6;
      nvswitch_timeout_create(5000000,local_88);
      iVar3 = flcnQueueCmdPostBlocking(param_1,uVar1,local_74,0,0,0,&local_8c,local_88);
      return -(uint)(iVar3 != 0) & 0xfffffff9;
    }
    nvswitch_os_mem_write32((ulong)param_6 + *(long *)(*param_1 + 0x78),param_7);
  }
  return 0;
}


// ===== 00251dc0 nvswitch_init_soe_ls10 =====

int nvswitch_init_soe_ls10(long *param_1)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined8 extraout_RDX;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined8 uVar9;
  undefined1 local_74 [4];
  undefined1 local_70 [12];
  undefined2 local_64 [30];
  
  lVar1 = *(long *)(param_1[0x1a4] + 8);
  cVar3 = soeIsCpuHalted_HAL(param_1,*(undefined8 *)(lVar1 + 0x48));
  if (cVar3 == '\0') {
    iVar4 = flcnRegRead_HAL(param_1,lVar1,0x44);
    if (iVar4 == 7) {
      cVar3 = nvswitch_is_tnvl_mode_enabled(param_1);
      if ((cVar3 == '\0') && (iVar4 = nvswitch_soe_register_event_callbacks(param_1), iVar4 != 0)) {
        iVar5 = nvswitch_translate_hw_error(0x6593);
        if (iVar5 == 1) {
          nvswitch_assert_log();
        }
        lVar1 = *param_1;
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Failed to register SOE events\n"
                          ,param_1 + 1,*(undefined4 *)(lVar1 + 0x40),*(undefined1 *)(lVar1 + 0x44),
                          *(undefined1 *)(lVar1 + 0x45),*(undefined1 *)(lVar1 + 0x46),0x6593);
        nvswitch_os_report_error(param_1[3],0x6593,"Failed to register SOE events\n");
        nvswitch_lib_smbpbi_log_sxid(param_1,0x6593,"Failed to register SOE events\n");
        nvswitch_inforom_bbx_add_sxid(param_1,0x6593,0,0,0);
        iVar5 = nvswitch_translate_hw_error(0x6592);
        if (iVar5 == 1) {
          nvswitch_assert_log();
        }
        lVar1 = *param_1;
        nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, SOE init failed(2)\n",
                          param_1 + 1,*(undefined4 *)(lVar1 + 0x40),*(undefined1 *)(lVar1 + 0x44),
                          *(undefined1 *)(lVar1 + 0x45),*(undefined1 *)(lVar1 + 0x46),0x6592);
        nvswitch_os_report_error(param_1[3],0x6592,"SOE init failed(2)\n");
        nvswitch_lib_smbpbi_log_sxid(param_1,0x6592,"SOE init failed(2)\n");
        nvswitch_inforom_bbx_add_sxid(param_1,0x6592,0,0,0);
        return iVar4;
      }
      puVar8 = local_70;
      uVar9 = *(undefined8 *)(param_1[0x1a4] + 8);
      nvswitch_os_memset(local_64,0,0x3c);
      local_64[0] = 0x402;
      nvswitch_timeout_create(5000000000,puVar8);
      puVar7 = local_74;
      iVar4 = flcnQueueCmdPostBlocking(param_1,uVar9,local_64,0,0,0);
      if (iVar4 == 0) {
        return 0;
      }
      nvswitch_assert_log(puVar8,puVar7);
      iVar4 = nvswitch_translate_hw_error(0x6592);
      if (iVar4 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      uVar9 = 0x6592;
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, SOE init failed(4)\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46));
      nvswitch_os_report_error(param_1[3],0x6592,"SOE init failed(4)\n");
      nvswitch_lib_smbpbi_log_sxid(param_1,0x6592,"SOE init failed(4)\n");
      nvswitch_inforom_bbx_add_sxid(param_1,0x6592,0,0,0);
      goto LAB_00252060;
    }
    iVar4 = nvswitch_translate_hw_error(0x6592);
    if (iVar4 == 1) {
      nvswitch_assert_log();
    }
    lVar2 = *param_1;
    nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, SOE init failed(1)\n",
                      param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                      *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x6592);
    nvswitch_os_report_error(param_1[3],0x6592,"SOE init failed(1)\n");
    pcVar6 = "SOE init failed(1)\n";
  }
  else {
    iVar4 = nvswitch_translate_hw_error(0x6592);
    if (iVar4 == 1) {
      nvswitch_assert_log();
    }
    lVar2 = *param_1;
    nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, SOE init Failed(0)\n",
                      param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                      *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x6592);
    nvswitch_os_report_error(param_1[3],0x6592,"SOE init Failed(0)\n");
    pcVar6 = "SOE init Failed(0)\n";
  }
  nvswitch_lib_smbpbi_log_sxid(param_1,0x6592,pcVar6);
  nvswitch_inforom_bbx_add_sxid(param_1,0x6592,0,0,0);
  uVar9 = extraout_RDX;
LAB_00252060:
  soeService_HAL(param_1,*(undefined8 *)(lVar1 + 0x48),uVar9);
  flcnDbgInfoCapturePcTrace_HAL(param_1,lVar1);
  nvswitch_assert_log();
  return -8;
}


// ===== 002521c0 nvswitch_unload_soe_ls10 =====

undefined8 nvswitch_unload_soe_ls10(undefined8 param_1)

{
  _nvswitch_soe_attach_detach_driver_ls10(param_1,0);
  return 0;
}


// ===== 002521e0 nvswitch_soe_register_event_callbacks_ls10 =====

uint nvswitch_soe_register_event_callbacks_ls10(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  
  lVar1 = *(long *)(param_1 + 0xd20);
  uVar2 = *(undefined8 *)(lVar1 + 8);
  iVar3 = flcnQueueEventRegister
                    (param_1,uVar2,5,0,nvswitch_therm_soe_callback_ls10,0,lVar1 + 0x2810);
  if ((iVar3 == 0) &&
     (iVar3 = flcnQueueEventRegister
                        (param_1,uVar2,0xe,0,nvswitch_cci_soe_callback_ls10,0,lVar1 + 0x2814),
     iVar3 == 0)) {
    iVar3 = flcnQueueEventRegister
                      (param_1,uVar2,0xf,0,nvswitch_heartbeat_soe_callback_ls10,0,lVar1 + 0x2818);
    return -(uint)(iVar3 != 0) & 0xfffffff8;
  }
  return 0xfffffff8;
}


// ===== 002522a0 nvswitch_soe_unregister_events_ls10 =====

void nvswitch_soe_unregister_events_ls10(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0xd20);
  uVar2 = *(undefined8 *)(lVar1 + 8);
  flcnQueueEventUnregister(param_1,uVar2,*(undefined4 *)(lVar1 + 0x2810));
  flcnQueueEventUnregister(param_1,uVar2,*(undefined4 *)(lVar1 + 0x2814));
  flcnQueueEventUnregister(param_1,uVar2,*(undefined4 *)(lVar1 + 0x2818));
  return;
}


// ===== 00252300 nvswitch_send_tnvl_prelock_cmd_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_send_tnvl_prelock_cmd_ls10(long param_1)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_7c;
  undefined1 local_78 [8];
  undefined8 local_70;
  undefined2 local_64 [2];
  undefined1 local_60;
  
  local_7c = 0;
  local_70 = 0;
  cVar1 = nvswitch_is_soe_supported();
  if (((cVar1 == '\0') || (iVar2 = (**(code **)(param_1 + 0x808))(param_1,&local_70), iVar2 != 0))
     || (((uint)local_70 & 0xff0000) < 0x590000)) {
    uVar3 = 0xfffffff3;
  }
  else {
    uVar3 = *(undefined8 *)(*(long *)(param_1 + 0xd20) + 8);
    nvswitch_os_memset(local_64,0,0x3c);
    local_60 = 1;
    local_64[0] = 0x510;
    nvswitch_timeout_create(5000000,local_78);
    iVar2 = flcnQueueCmdPostBlocking(param_1,uVar3,local_64,0,0,0,&local_7c,local_78);
    uVar3 = 0xfffffff9;
    if (iVar2 == 0) {
      uVar3 = 0;
    }
  }
  return uVar3;
}


// ===== 002523f0 soeSetupHal_LS10 =====

void soeSetupHal_LS10(long *param_1)

{
  long lVar1;
  
  lVar1 = *param_1;
  soeSetupHal_LR10();
  *(code **)(lVar1 + 0x68) = _soeFetchEngines_LS10;
  *(code **)(lVar1 + 0x20) = _soeHandleInitEvent_LS10;
  *(code **)(lVar1 + 200) = _soeIsCpuHalted_LS10;
  *(code **)(lVar1 + 0x80) = _soeService_LS10;
  *(code **)(lVar1 + 0x88) = _soeServiceHalt_LS10;
  *(code **)(lVar1 + 0x70) = _soeProcessMessages_LS10;
  *(code **)(lVar1 + 0x78) = _soeWaitForInitAck_LS10;
  *(code **)(lVar1 + 0x100) = _soeI2CAccess_LS10;
  return;
}


// ===== 00252460 nvswitch_apply_prod_nvlw_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_apply_prod_nvlw_ls10(long param_1)

{
  (**(code **)(param_1 + 0x928))(param_1,0x2c,1,0,0x204,1);
  (**(code **)(param_1 + 0x928))(param_1,0x2c,1,0,0x110,0);
  return 0;
}


// ===== 002524c0 nvswitch_apply_prod_nxbar_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_apply_prod_nxbar_ls10(long param_1)

{
  (**(code **)(param_1 + 0x928))(param_1,0x2d,1,0,0x48,0x48);
  (**(code **)(param_1 + 0x928))(param_1,0x2d,1,0,0x4c,0);
  (**(code **)(param_1 + 0x928))(param_1,0xd,1,0,0x48,0x48);
  (**(code **)(param_1 + 0x928))(param_1,0xd,1,0,0x4c,0);
  return 0;
}


// ===== 00252570 nvswitch_nvs_top_prod_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_nvs_top_prod_ls10(long param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  (**(code **)(param_1 + 0x928))(param_1,0x11,0,0,0x6a00,0);
  (**(code **)(param_1 + 0x928))(param_1,0x2a,0,0,0xa8,0);
  while( true ) {
    uVar1 = (**(code **)(param_1 + 0x918))(param_1,0x24,0);
    if (uVar1 <= uVar3) break;
    iVar2 = (**(code **)(param_1 + 0x910))(param_1,0x24,0,uVar3);
    if (iVar2 != -1) {
      (**(code **)(param_1 + 0x928))(param_1,0x24,0,uVar3,0x150,0);
    }
    uVar3 = uVar3 + 1;
  }
  uVar3 = 0;
  while( true ) {
    uVar1 = (**(code **)(param_1 + 0x918))(param_1,0x25,0);
    if (uVar1 <= uVar3) break;
    iVar2 = (**(code **)(param_1 + 0x910))(param_1,0x25,0,uVar3);
    if (iVar2 != -1) {
      (**(code **)(param_1 + 0x928))(param_1,0x25,0,uVar3,0x48,0);
    }
    uVar3 = uVar3 + 1;
  }
  (**(code **)(param_1 + 0x928))(param_1,0x2b,0,0,0x600,0);
  (**(code **)(param_1 + 0x928))(param_1,1,0,0,0x40,1);
  nvswitch_reg_write_32(param_1,0x1df130,0x1fe);
  (**(code **)(param_1 + 0x928))(param_1,2,0,0,0x70c,0x1f2a737);
  (**(code **)(param_1 + 0x928))(param_1,2,0,0,0x134,0x1ffffe);
  (**(code **)(param_1 + 0x928))(param_1,2,0,0,0x83c,0x3c);
  (**(code **)(param_1 + 0x928))(param_1,2,0,0,0xe28,0);
  (**(code **)(param_1 + 0x928))(param_1,0x28,0,0,0x150,0);
  (**(code **)(param_1 + 0x928))(param_1,0x29,0,0,0x48,0);
  (**(code **)(param_1 + 0x928))(param_1,0x26,0,0,0x150,0);
  (**(code **)(param_1 + 0x928))(param_1,0x27,0,0,0x48,0);
  (**(code **)(param_1 + 0x928))(param_1,0x14,0,0,0x2720,0x40);
  (**(code **)(param_1 + 0x928))(param_1,0x14,0,0,0x2724,0);
  (**(code **)(param_1 + 0x928))(param_1,0x14,0,0,10000,0x40);
  (**(code **)(param_1 + 0x928))(param_1,0x14,0,0,0x2714,0);
  (**(code **)(param_1 + 0x928))(param_1,0x14,0,0,0x2700,0x40);
  (**(code **)(param_1 + 0x928))(param_1,0x14,0,0,0x2704,0);
  (**(code **)(param_1 + 0x928))(param_1,0x14,0,0,0x3a00,0xb000b);
  (**(code **)(param_1 + 0x928))(param_1,0x14,0,0,0x3a04,0);
  (**(code **)(param_1 + 0x928))(param_1,0x15,0,0,0xf00,0xb004b);
  (**(code **)(param_1 + 0x928))(param_1,0x15,0,0,0xf04,0);
  return 0;
}


// ===== 00252957 nvswitch_init_thermal_ls10.cold =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nvswitch_init_thermal_ls10_cold(void)

{
  code *pcVar1;
  
  _DAT_0000dde8 = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00252970 nvswitch_init_thermal_ls10 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 nvswitch_init_thermal_ls10(long param_1)

{
  code *pcVar1;
  
  if (*(int *)(param_1 + 0x1f88) == 7) {
    *(undefined4 *)(&DAT_0000dde8 + *(long *)(param_1 + 0x1f90)) = 0;
    return 0;
  }
  _DAT_0000dde8 = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002529a0 nvswitch_ctrl_therm_read_temperature_ls10 =====

/* WARNING: Type propagation algorithm not settling */

int nvswitch_ctrl_therm_read_temperature_ls10(undefined8 param_1,uint *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (*param_2 == 0) {
    return -1;
  }
  nvswitch_os_memset(param_2 + 1,0,0x40);
  uVar4 = *param_2;
  if ((uVar4 & 1) == 0) {
    if ((uVar4 & 2) != 0) goto LAB_00252ac3;
LAB_002529df:
    uVar5 = uVar4;
    if ((uVar4 & 4) != 0) goto LAB_00252b05;
joined_r0x00252b1e:
    uVar3 = uVar4;
    if ((uVar5 & 8) != 0) {
      cVar1 = nvswitch_is_tnvl_mode_locked(param_1);
      if (cVar1 != '\0') goto LAB_00252f06;
      uVar3 = *param_2;
      uVar4 = uVar3 & 0xfffffff7;
      *param_2 = uVar4;
    }
    uVar5 = uVar4;
    if ((uVar3 & 0x10) != 0) {
      uVar4 = nvswitch_reg_read_32(param_1,0x66f28);
      uVar5 = nvswitch_reg_read_32(param_1,0x66f10);
      param_2[5] = ((uVar5 & 0x3fff) << 3 | -(uint)((uVar5 & 0x2000) != 0) & 0xfffe0000) -
                   ((uVar4 & 0x3fff) << 3 | -(uint)((uVar4 & 0x2000) != 0) & 0xfffe0000);
      uVar5 = *param_2;
      uVar4 = uVar5 & 0xffffffef;
      *param_2 = uVar4;
    }
    uVar3 = uVar4;
    if ((uVar5 & 0x20) != 0) {
      uVar4 = nvswitch_reg_read_32(param_1,0x66f2c);
      uVar5 = nvswitch_reg_read_32(param_1,0x66f14);
      param_2[6] = ((uVar5 & 0x3fff) << 3 | -(uint)((uVar5 & 0x2000) != 0) & 0xfffe0000) -
                   ((uVar4 & 0x3fff) << 3 | -(uint)((uVar4 & 0x2000) != 0) & 0xfffe0000);
      uVar3 = *param_2;
      uVar4 = uVar3 & 0xffffffdf;
      *param_2 = uVar4;
    }
    uVar5 = uVar4;
    if ((uVar3 & 0x40) != 0) {
      uVar4 = nvswitch_reg_read_32(param_1,0x66f30);
      uVar5 = nvswitch_reg_read_32(param_1,0x66f18);
      param_2[7] = ((uVar5 & 0x3fff) << 3 | -(uint)((uVar5 & 0x2000) != 0) & 0xfffe0000) -
                   ((uVar4 & 0x3fff) << 3 | -(uint)((uVar4 & 0x2000) != 0) & 0xfffe0000);
      uVar5 = *param_2;
      uVar4 = uVar5 & 0xffffffbf;
      *param_2 = uVar4;
    }
    uVar3 = uVar4;
    if ((uVar5 & 0x80) != 0) {
      uVar4 = nvswitch_reg_read_32(param_1,0x66f34);
      uVar5 = nvswitch_reg_read_32(param_1,0x66f1c);
      param_2[8] = ((uVar5 & 0x3fff) << 3 | -(uint)((uVar5 & 0x2000) != 0) & 0xfffe0000) -
                   ((uVar4 & 0x3fff) << 3 | -(uint)((uVar4 & 0x2000) != 0) & 0xfffe0000);
      uVar3 = *param_2;
      uVar4 = uVar3 & 0xffffff7f;
      *param_2 = uVar4;
    }
    uVar5 = uVar4;
    if ((uVar3 & 0x100) != 0) {
      uVar4 = nvswitch_reg_read_32(param_1,0x66f38);
      uVar5 = nvswitch_reg_read_32(param_1,0x66f20);
      param_2[9] = ((uVar5 & 0x3fff) << 3 | -(uint)((uVar5 & 0x2000) != 0) & 0xfffe0000) -
                   ((uVar4 & 0x3fff) << 3 | -(uint)((uVar4 & 0x2000) != 0) & 0xfffe0000);
      uVar5 = *param_2;
      uVar4 = uVar5 & 0xfffffeff;
      *param_2 = uVar4;
    }
    uVar3 = uVar4;
    if ((uVar5 & 0x200) != 0) {
      uVar4 = nvswitch_reg_read_32(param_1,0x66f3c);
      uVar5 = nvswitch_reg_read_32(param_1,0x66f24);
      param_2[10] = ((uVar5 & 0x3fff) << 3 | -(uint)((uVar5 & 0x2000) != 0) & 0xfffe0000) -
                    ((uVar4 & 0x3fff) << 3 | -(uint)((uVar4 & 0x2000) != 0) & 0xfffe0000);
      uVar3 = *param_2;
      uVar4 = uVar3 & 0xfffffdff;
      *param_2 = uVar4;
    }
    uVar5 = uVar4;
    if ((uVar3 & 0x400) != 0) {
      uVar4 = nvswitch_reg_read_32(param_1,0x66fb0);
      uVar5 = nvswitch_reg_read_32(param_1,0x66fa0);
      param_2[0xb] = ((uVar5 & 0x3fff) << 3 | -(uint)((uVar5 & 0x2000) != 0) & 0xfffe0000) -
                     ((uVar4 & 0x3fff) << 3 | -(uint)((uVar4 & 0x2000) != 0) & 0xfffe0000);
      uVar5 = *param_2;
      uVar4 = uVar5 & 0xfffffbff;
      *param_2 = uVar4;
    }
    uVar3 = uVar4;
    if ((uVar5 & 0x800) != 0) {
      uVar4 = nvswitch_reg_read_32(param_1,0x66fb4);
      uVar5 = nvswitch_reg_read_32(param_1,0x66fa4);
      param_2[0xc] = ((uVar5 & 0x3fff) << 3 | -(uint)((uVar5 & 0x2000) != 0) & 0xfffe0000) -
                     ((uVar4 & 0x3fff) << 3 | -(uint)((uVar4 & 0x2000) != 0) & 0xfffe0000);
      uVar3 = *param_2;
      uVar4 = uVar3 & 0xfffff7ff;
      *param_2 = uVar4;
    }
    if ((uVar3 & 0x1000) != 0) {
      uVar4 = nvswitch_reg_read_32(param_1,0x66fb8);
      uVar5 = nvswitch_reg_read_32(param_1,0x66fa8);
      param_2[0xd] = ((uVar5 & 0x3fff) << 3 | -(uint)((uVar5 & 0x2000) != 0) & 0xfffe0000) -
                     ((uVar4 & 0x3fff) << 3 | -(uint)((uVar4 & 0x2000) != 0) & 0xfffe0000);
      uVar4 = *param_2 & 0xffffefff;
      *param_2 = uVar4;
    }
    iVar2 = -(uint)(uVar4 != 0);
  }
  else {
    uVar4 = nvswitch_reg_read_32(param_1,0x66f40);
    uVar3 = nvswitch_reg_read_32(param_1,0x66f28);
    param_2[0x11] = 0;
    uVar5 = *param_2;
    param_2[1] = ((uVar4 & 0x3fff) << 3 | -(uint)((uVar4 & 0x2000) != 0) & 0xfffe0000) -
                 ((uVar3 & 0x3fff) << 3 | -(uint)((uVar3 & 0x2000) != 0) & 0xfffe0000);
    uVar4 = uVar5 & 0xfffffffe;
    *param_2 = uVar4;
    if ((uVar5 & 2) == 0) goto LAB_002529df;
LAB_00252ac3:
    uVar4 = nvswitch_reg_read_32(param_1,0x66f40);
    param_2[0x12] = 0;
    param_2[2] = (uVar4 & 0x3fff) << 3 | -(uint)((uVar4 & 0x2000) != 0) & 0xfffe0000;
    uVar3 = *param_2;
    uVar4 = uVar3 & 0xfffffffd;
    *param_2 = uVar4;
    uVar5 = uVar4;
    if ((uVar3 & 4) == 0) goto joined_r0x00252b1e;
LAB_00252b05:
    cVar1 = nvswitch_is_tnvl_mode_locked(param_1);
    if (cVar1 == '\0') {
      uVar5 = *param_2;
      uVar4 = uVar5 & 0xfffffffb;
      *param_2 = uVar4;
      goto joined_r0x00252b1e;
    }
LAB_00252f06:
    iVar2 = -0xf;
  }
  return iVar2;
}


// ===== 00252f10 nvswitch_ctrl_therm_get_temperature_limit_ls10 =====

undefined8 nvswitch_ctrl_therm_get_temperature_limit_ls10(undefined8 param_1,int *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = nvswitch_reg_read_32(param_1,0x66f44);
  uVar1 = (uint)uVar2;
  if (*param_2 != 0) {
    if (*param_2 != 1) {
      return 0xffffffff;
    }
    uVar1 = (uint)((ulong)uVar2 >> 0x10) & 0xffff;
  }
  param_2[1] = (uVar1 & 0x3fff) << 3 | -(uint)((uVar1 & 0x2000) != 0) & 0xfffe0000;
  return 0;
}


// ===== 00252f70 nvswitch_monitor_thermal_alert_ls10 =====

void nvswitch_monitor_thermal_alert_ls10(void)

{
  return;
}


// ===== 00252f80 nvswitch_therm_soe_callback_ls10 =====

void nvswitch_therm_soe_callback_ls10(long *param_1,long param_2,undefined8 param_3,ulong param_4)

{
  long *plVar1;
  char cVar2;
  char cVar3;
  long lVar4;
  int iVar5;
  undefined *puVar6;
  ulong uVar7;
  uint uVar8;
  uint uVar9;
  undefined8 extraout_RDX;
  uint uVar10;
  
  if (*(char *)(param_2 + 4) == '\0') {
    plVar1 = param_1 + 1;
    uVar8 = *(uint *)(param_2 + 8);
    uVar10 = *(uint *)(param_2 + 0xc);
    cVar2 = *(char *)(param_2 + 0x10);
    if (*(char *)(param_2 + 5) == '\0') {
      uVar9 = uVar8 >> 8 | 0xff000000;
      if (-1 < (int)uVar8) {
        uVar9 = uVar8 >> 8;
      }
      uVar8 = uVar10 >> 8 | 0xff000000;
      if (-1 < (int)uVar10) {
        uVar8 = uVar10 >> 8;
      }
      iVar5 = nvswitch_translate_hw_error(0x2715);
      if (iVar5 == 1) {
        nvswitch_assert_log();
      }
      lVar4 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, NVSWITCH Temperature %dC | TSENSE WARN Threshold %dC\n"
                        ,plVar1,*(undefined4 *)(lVar4 + 0x40),*(undefined1 *)(lVar4 + 0x44),
                        *(undefined1 *)(lVar4 + 0x45),*(undefined1 *)(lVar4 + 0x46),0x2715,uVar9,
                        uVar8);
      nvswitch_os_report_error
                (param_1[3],0x2715,"NVSWITCH Temperature %dC | TSENSE WARN Threshold %dC\n",uVar9,
                 uVar8);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2715,"NVSWITCH Temperature %dC | TSENSE WARN Threshold %dC\n",uVar9,uVar8
                );
      nvswitch_inforom_bbx_add_sxid(param_1,0x2715,0,0,0);
      iVar5 = nvswitch_translate_hw_error(0x2715);
      if (iVar5 == 1) {
        nvswitch_assert_log();
      }
      puVar6 = &DAT_00cc7e1f;
      if (cVar2 == '\0') {
        puVar6 = &DAT_00cc7e22;
      }
      lVar4 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Thermal Slowdown Disengaged | Links Thermal Mode %s\n"
                        ,plVar1,*(undefined4 *)(lVar4 + 0x40),*(undefined1 *)(lVar4 + 0x44),
                        *(undefined1 *)(lVar4 + 0x45),*(undefined1 *)(lVar4 + 0x46),0x2715,puVar6);
      nvswitch_os_report_error
                (param_1[3],0x2715,"Thermal Slowdown Disengaged | Links Thermal Mode %s\n",puVar6);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2715,"Thermal Slowdown Disengaged | Links Thermal Mode %s\n",puVar6);
      nvswitch_inforom_bbx_add_sxid(param_1,0x2715,0,0,0);
      iVar5 = nvswitch_translate_hw_error(0x2715);
      if (iVar5 == 1) {
        nvswitch_assert_log();
      }
      lVar4 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Thermal slowdown Disengaged\n"
                        ,plVar1,*(undefined4 *)(lVar4 + 0x40),*(undefined1 *)(lVar4 + 0x44),
                        *(undefined1 *)(lVar4 + 0x45),*(undefined1 *)(lVar4 + 0x46),0x2715);
      nvswitch_os_report_error(param_1[3],0x2715,"Thermal slowdown Disengaged\n");
      nvswitch_lib_smbpbi_log_sxid(param_1,0x2715,"Thermal slowdown Disengaged\n");
      nvswitch_inforom_bbx_add_sxid(param_1,0x2715,0,0,0);
      return;
    }
    cVar3 = *(char *)(param_2 + 0x12);
    if (*(char *)(param_2 + 0x11) != '\0') {
      uVar9 = uVar8 >> 8 | 0xff000000;
      if (-1 < (int)uVar8) {
        uVar9 = uVar8 >> 8;
      }
      uVar8 = uVar10 >> 8 | 0xff000000;
      if (-1 < (int)uVar10) {
        uVar8 = uVar10 >> 8;
      }
      iVar5 = nvswitch_translate_hw_error(0x2714);
      if (iVar5 == 1) {
        nvswitch_assert_log();
      }
      lVar4 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, NVSWITCH Temperature %dC | TSENSE WARN Threshold %dC\n"
                        ,plVar1,*(undefined4 *)(lVar4 + 0x40),*(undefined1 *)(lVar4 + 0x44),
                        *(undefined1 *)(lVar4 + 0x45),*(undefined1 *)(lVar4 + 0x46),0x2714,uVar9,
                        uVar8);
      nvswitch_os_report_error
                (param_1[3],0x2714,"NVSWITCH Temperature %dC | TSENSE WARN Threshold %dC\n",uVar9,
                 uVar8);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2714,"NVSWITCH Temperature %dC | TSENSE WARN Threshold %dC\n",uVar9,uVar8
                );
      nvswitch_inforom_bbx_add_sxid(param_1,0x2714,0,0,0);
      iVar5 = nvswitch_translate_hw_error(0x2714);
      if (iVar5 == 1) {
        nvswitch_assert_log();
      }
      lVar4 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Thermal Slowdown Engaged | Temp higher than WARN Threshold\n"
                        ,plVar1,*(undefined4 *)(lVar4 + 0x40),*(undefined1 *)(lVar4 + 0x44),
                        *(undefined1 *)(lVar4 + 0x45),*(undefined1 *)(lVar4 + 0x46),0x2714);
      nvswitch_os_report_error
                (param_1[3],0x2714,"Thermal Slowdown Engaged | Temp higher than WARN Threshold\n");
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2714,"Thermal Slowdown Engaged | Temp higher than WARN Threshold\n");
      nvswitch_inforom_bbx_add_sxid(param_1,0x2714,0,0,0);
    }
    iVar5 = nvswitch_translate_hw_error(0x2714);
    if (iVar5 == 1) {
      nvswitch_assert_log();
    }
    puVar6 = &DAT_00cc7e1f;
    if (cVar2 == '\0') {
      puVar6 = &DAT_00cc7e22;
    }
    lVar4 = *param_1;
    nvswitch_os_print(5,
                      "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Thermal Slowdown Engaged | Links Thermal Mode %s\n"
                      ,plVar1,*(undefined4 *)(lVar4 + 0x40),*(undefined1 *)(lVar4 + 0x44),
                      *(undefined1 *)(lVar4 + 0x45),*(undefined1 *)(lVar4 + 0x46),0x2714,puVar6);
    nvswitch_os_report_error
              (param_1[3],0x2714,"Thermal Slowdown Engaged | Links Thermal Mode %s\n",puVar6);
    nvswitch_lib_smbpbi_log_sxid
              (param_1,0x2714,"Thermal Slowdown Engaged | Links Thermal Mode %s\n",puVar6);
    nvswitch_inforom_bbx_add_sxid(param_1,0x2714,0,0,0);
    if (cVar3 == '\0') {
      return;
    }
    iVar5 = nvswitch_translate_hw_error(0x2714);
    if (iVar5 == 1) {
      nvswitch_assert_log();
    }
    lVar4 = *param_1;
    uVar7 = (ulong)*(byte *)(lVar4 + 0x46);
    nvswitch_os_print(5,
                      "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Thermal Slowdown Engaged | PMGR WARN Threshold reached\n"
                      ,plVar1,*(undefined4 *)(lVar4 + 0x40),*(undefined1 *)(lVar4 + 0x44),
                      *(undefined1 *)(lVar4 + 0x45),uVar7,0x2714);
    nvswitch_os_report_error
              (param_1[3],0x2714,"Thermal Slowdown Engaged | PMGR WARN Threshold reached\n");
    nvswitch_lib_smbpbi_log_sxid
              (param_1,0x2714,"Thermal Slowdown Engaged | PMGR WARN Threshold reached\n");
    nvswitch_inforom_bbx_add_sxid(param_1,0x2714,0,0,0,uVar7);
    return;
  }
  if (*(char *)(param_2 + 4) != '\x01') {
    nvswitch_assert_log();
    return;
  }
  cVar2 = *(char *)(param_2 + 0x11);
  if (*(char *)(param_2 + 0x10) != '\0') {
    uVar10 = *(uint *)(param_2 + 8) >> 8;
    uVar8 = uVar10 | 0xff000000;
    if (-1 < (int)*(uint *)(param_2 + 8)) {
      uVar8 = uVar10;
    }
    uVar9 = *(uint *)(param_2 + 0xc) >> 8;
    uVar10 = uVar9 | 0xff000000;
    if (-1 < (int)*(uint *)(param_2 + 0xc)) {
      uVar10 = uVar9;
    }
    iVar5 = nvswitch_translate_hw_error(0x2716);
    if (iVar5 == 1) {
      nvswitch_assert_log();
    }
    lVar4 = *param_1;
    nvswitch_os_print(5,
                      "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, NVSWITCH Temperature %dC | OVERT Threshold %dC\n"
                      ,param_1 + 1,*(undefined4 *)(lVar4 + 0x40),*(undefined1 *)(lVar4 + 0x44),
                      *(undefined1 *)(lVar4 + 0x45),*(undefined1 *)(lVar4 + 0x46),0x2716,uVar8,
                      uVar10);
    nvswitch_os_report_error
              (param_1[3],0x2716,"NVSWITCH Temperature %dC | OVERT Threshold %dC\n",uVar8,uVar10);
    nvswitch_lib_smbpbi_log_sxid
              (param_1,0x2716,"NVSWITCH Temperature %dC | OVERT Threshold %dC\n",uVar8,uVar10);
    nvswitch_inforom_bbx_add_sxid(param_1,0x2716,0,0,0);
    iVar5 = nvswitch_translate_hw_error(0x2716);
    if (iVar5 == 1) {
      nvswitch_assert_log();
    }
    lVar4 = *param_1;
    param_2 = 0x2716;
    param_4 = (ulong)*(byte *)(lVar4 + 0x46);
    nvswitch_os_print(5,
                      "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, TSENSE OVERT Threshold reached. Shutting Down\n"
                      ,param_1 + 1,*(undefined4 *)(lVar4 + 0x40),*(undefined1 *)(lVar4 + 0x44),
                      *(undefined1 *)(lVar4 + 0x45));
    nvswitch_os_report_error(param_1[3],0x2716,"TSENSE OVERT Threshold reached. Shutting Down\n");
    nvswitch_lib_smbpbi_log_sxid(param_1,0x2716,"TSENSE OVERT Threshold reached. Shutting Down\n");
    nvswitch_inforom_bbx_add_sxid(param_1,0x2716,0,0,0);
    param_3 = extraout_RDX;
  }
  if (cVar2 == '\0') {
    return;
  }
  iVar5 = nvswitch_translate_hw_error(0x2714,param_2,param_3,param_4);
  if (iVar5 == 1) {
    nvswitch_assert_log();
  }
  lVar4 = *param_1;
  nvswitch_os_print(5,
                    "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, PMGR OVERT Threshold reached. Shutting Down\n"
                    ,param_1 + 1,*(undefined4 *)(lVar4 + 0x40),*(undefined1 *)(lVar4 + 0x44),
                    *(undefined1 *)(lVar4 + 0x45),*(undefined1 *)(lVar4 + 0x46),0x2714);
  nvswitch_os_report_error(param_1[3],0x2714,"PMGR OVERT Threshold reached. Shutting Down\n");
  nvswitch_lib_smbpbi_log_sxid(param_1,0x2714,"PMGR OVERT Threshold reached. Shutting Down\n");
  nvswitch_inforom_bbx_add_sxid(param_1,0x2714,0,0,0);
  return;
}


// ===== 00253780 nvswitch_ctrl_therm_read_voltage_ls10 =====

int nvswitch_ctrl_therm_read_voltage_ls10(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  undefined4 local_b4;
  undefined1 local_b0 [12];
  undefined2 local_a4 [2];
  undefined1 local_a0;
  undefined2 local_68 [2];
  char local_63;
  undefined8 local_60;
  undefined4 local_58;
  
  cVar2 = nvswitch_is_soe_supported();
  if (cVar2 == '\0') {
    iVar3 = -0xd;
  }
  else if (param_2 == (undefined8 *)0x0) {
    iVar3 = -1;
  }
  else {
    uVar1 = *(undefined8 *)(*(long *)(param_1 + 0xd20) + 8);
    nvswitch_os_memset(param_2,0,0xc);
    nvswitch_os_memset(local_a4,0,0x3c);
    nvswitch_os_memset(local_68,0,0x40);
    local_a4[0] = 0x50b;
    local_68[0] = 0x140b;
    local_a0 = 7;
    local_b4 = 0;
    nvswitch_timeout_create(5000000000,local_b0);
    iVar3 = flcnQueueCmdPostBlocking(param_1,uVar1,local_a4,local_68,0,0,&local_b4,local_b0);
    if (iVar3 == 0) {
      if (local_63 != '\0') {
        return (uint)(local_63 != '>') * 3 + -10;
      }
      *param_2 = local_60;
      *(undefined4 *)(param_2 + 1) = local_58;
      iVar3 = 0;
    }
    else {
      iVar3 = -8;
    }
  }
  return iVar3;
}


// ===== 002538e0 nvswitch_ctrl_therm_read_power_ls10 =====

int nvswitch_ctrl_therm_read_power_ls10(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  undefined4 local_b4;
  undefined1 local_b0 [12];
  undefined2 local_a4 [2];
  undefined1 local_a0;
  undefined2 local_68 [2];
  char local_63;
  undefined8 local_60;
  undefined4 local_58;
  
  cVar2 = nvswitch_is_soe_supported();
  if (cVar2 == '\0') {
    iVar3 = -0xd;
  }
  else if (param_2 == (undefined8 *)0x0) {
    iVar3 = -1;
  }
  else {
    uVar1 = *(undefined8 *)(*(long *)(param_1 + 0xd20) + 8);
    nvswitch_os_memset(param_2,0,0xc);
    nvswitch_os_memset(local_a4,0,0x3c);
    nvswitch_os_memset(local_68,0,0x40);
    local_a4[0] = 0x50b;
    local_68[0] = 0x140b;
    local_a0 = 9;
    local_b4 = 0;
    nvswitch_timeout_create(5000000000,local_b0);
    iVar3 = flcnQueueCmdPostBlocking(param_1,uVar1,local_a4,local_68,0,0,&local_b4,local_b0);
    if (iVar3 == 0) {
      if (local_63 != '\0') {
        return (uint)(local_63 != '>') * 3 + -10;
      }
      *param_2 = local_60;
      *(undefined4 *)(param_2 + 1) = local_58;
      iVar3 = 0;
    }
    else {
      iVar3 = -8;
    }
  }
  return iVar3;
}


// ===== 00253a40 _pem_write_buffer_ls10.constprop.0 =====

undefined8
_pem_write_buffer_ls10_constprop_0
          (long param_1,ulong param_2,long param_3,ulong param_4,ulong *param_5)

{
  ulong uVar1;
  char cVar2;
  byte bVar3;
  undefined1 uVar4;
  char cVar5;
  uint uVar6;
  long lVar7;
  ulong uVar8;
  char *pcVar9;
  uint uVar10;
  long lVar11;
  char *pcVar12;
  
  lVar11 = ((param_2 + 2) / 3) * 4;
  uVar1 = lVar11 + 0x37 + (lVar11 + 0x3fU >> 6);
  if (param_4 < uVar1) {
    return 0xfffffffe;
  }
  nvswitch_os_memcpy(param_3,"-----BEGIN CERTIFICATE-----\n",0x1c);
  pcVar12 = (char *)(param_3 + 0x1c);
  if (param_2 < 3) {
    uVar8 = 0;
  }
  else {
    lVar11 = 0;
    lVar7 = 0;
    while( true ) {
      lVar11 = lVar11 + 4;
      uVar6 = (uint)*(byte *)(param_1 + lVar7) << 0x10 | (uint)*(byte *)(param_1 + 1 + lVar7) << 8;
      uVar10 = (uint)*(byte *)(param_1 + 2 + lVar7);
      cVar2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
              [*(byte *)(param_1 + lVar7) >> 2];
      pcVar12[3] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[uVar10 & 0x3f]
      ;
      *pcVar12 = cVar2;
      cVar2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
              [uVar6 >> 0xc & 0x3f];
      pcVar12[2] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                   [(uVar6 | uVar10) >> 6 & 0x3f];
      pcVar12[1] = cVar2;
      if (lVar11 == 0x40) {
        pcVar12[4] = '\n';
        lVar11 = 0;
        pcVar12 = pcVar12 + 5;
      }
      else {
        pcVar12 = pcVar12 + 4;
      }
      if (param_2 <= lVar7 + 5U) break;
      lVar7 = lVar7 + 3;
    }
    uVar8 = lVar7 + 3;
    if ((param_2 == uVar8) && (lVar11 != 0)) {
      *pcVar12 = '\n';
      pcVar12 = pcVar12 + 1;
      goto LAB_00253b77;
    }
  }
  pcVar9 = pcVar12;
  if (param_2 - 1 == uVar8) {
    bVar3 = *(byte *)(param_1 + uVar8);
    pcVar12[4] = '\n';
    pcVar9 = pcVar12 + 5;
    cVar2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[bVar3 >> 2];
    pcVar12[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                 [(bVar3 & 3) << 4];
    *pcVar12 = cVar2;
    pcVar12[2] = '=';
    pcVar12[3] = '=';
  }
  pcVar12 = pcVar9;
  if (param_2 - 2 == uVar8) {
    bVar3 = *(byte *)(param_1 + uVar8);
    uVar4 = *(undefined1 *)(param_1 + 1 + uVar8);
    pcVar12 = pcVar9 + 5;
    cVar2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[bVar3 >> 2];
    cVar5 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
            [(ushort)(CONCAT11(bVar3,uVar4) >> 4) & 0x3f];
    pcVar9[2] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                [(uint)CONCAT11(bVar3,uVar4) * 4 & 0x3c];
    *pcVar9 = cVar2;
    pcVar9[1] = cVar5;
    pcVar9[3] = '=';
    pcVar9[4] = '\n';
  }
LAB_00253b77:
  nvswitch_os_memcpy(pcVar12,"-----END CERTIFICATE-----\n",0x1b);
  *param_5 = uVar1;
  return 0;
}


// ===== 00253c80 _calc_x509_cert_size_ls10.constprop.0 =====

undefined8 _calc_x509_cert_size_ls10_constprop_0(long param_1,byte *param_2,uint *param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  if ((byte *)(param_1 + 4U) < param_2) {
    bVar1 = *(byte *)(param_1 + 1);
    uVar3 = (uint)bVar1;
    if ((char)bVar1 < '\0') {
      bVar1 = (bVar1 & 0x3f) + 2;
      pbVar5 = (byte *)((ulong)bVar1 + param_1);
      if (param_2 < pbVar5) {
        return 0xfffffffe;
      }
      pbVar4 = (byte *)(param_1 + 3);
      uVar3 = (uint)*(byte *)(param_1 + 2);
      if (pbVar4 < pbVar5) {
        do {
          bVar2 = *pbVar4;
          pbVar4 = pbVar4 + 1;
          uVar3 = uVar3 * 0x100 + (uint)bVar2;
        } while (pbVar5 != pbVar4);
      }
      uVar3 = uVar3 + bVar1;
    }
    if (((byte *)(param_1 + (ulong)(uVar3 - 1)) <= param_2) && (uVar3 != 1)) {
      *param_3 = uVar3;
      return 0;
    }
  }
  return 0xfffffffe;
}


// ===== 00253d00 nvswitch_tnvl_get_attestation_certificate_chain_ls10 =====

undefined4 nvswitch_tnvl_get_attestation_certificate_chain_ls10(undefined8 param_1,long param_2)

{
  ulong uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  undefined1 *puVar10;
  long lVar11;
  ulong uVar12;
  long lVar13;
  long lVar14;
  undefined4 uVar15;
  ulong uVar16;
  uint local_50;
  uint local_4c;
  long local_48;
  long local_40 [2];
  
  local_50 = 0;
  local_4c = 0;
  if (param_2 == 0) {
    return 0xffffffff;
  }
  cVar5 = nvswitch_is_tnvl_mode_enabled();
  if (cVar5 == '\0') {
    return 0xfffffff3;
  }
  lVar7 = nvswitch_os_malloc_trace(0x1000,0,0);
  lVar8 = nvswitch_os_malloc_trace(0x1400,0,0);
  lVar9 = nvswitch_os_malloc_trace(0x1400,0,0);
  if ((lVar7 != 0 && lVar8 != 0) && (lVar9 != 0)) {
    nvswitch_os_memset(lVar7,0,0x1000);
    nvswitch_os_memset(lVar8,0,0x1400);
    nvswitch_os_memset(lVar9,0,0x1400);
    puVar10 = (undefined1 *)nvswitch_os_malloc_trace(4,0,0);
    lVar11 = nvswitch_os_malloc_trace(0x1445,0,0);
    if ((puVar10 == (undefined1 *)0x0) || (lVar11 == 0)) {
      nvswitch_os_free(puVar10);
      nvswitch_os_free(lVar11);
    }
    else {
      *puVar10 = 0;
      *(undefined2 *)(puVar10 + 2) = 0x100;
      nvswitch_timeout_create(5000000000,local_40);
      iVar6 = nvswitch_fsp_send_and_read_message(param_1,puVar10,4,0x1f,lVar11,0x1445);
      if (((iVar6 != 0) || (*(char *)(lVar11 + 0xd) != '\0')) ||
         (0x1000 < *(ushort *)(lVar11 + 0x11))) {
        nvswitch_os_free(puVar10);
        nvswitch_os_free(lVar11);
LAB_00253ed5:
        uVar15 = 0xfffffff8;
        goto LAB_00253ef2;
      }
      nvswitch_os_memcpy(lVar7,lVar11 + 0x45);
      uVar2 = *(ushort *)(lVar11 + 0x11);
      nvswitch_os_free(puVar10);
      nvswitch_os_free(lVar11);
      lVar11 = lVar7 + -0x35 + (ulong)uVar2;
      iVar6 = _calc_x509_cert_size_ls10_constprop_0(lVar7,lVar11,&local_50);
      uVar3 = local_50;
      if (iVar6 == 0) {
        uVar16 = (ulong)local_50;
        lVar14 = lVar7 + uVar16;
        iVar6 = _calc_x509_cert_size_ls10_constprop_0(lVar14,lVar11,&local_4c);
        uVar4 = local_4c;
        if (iVar6 == 0) {
          uVar12 = (ulong)local_4c;
          if (lVar11 != lVar14 + -1 + uVar12) goto LAB_00253ed5;
          uVar1 = uVar16 + 0x74b + uVar12;
          if (((uVar1 < 0x1401) &&
              (lVar11 = nvswitch_os_memcpy(lVar8,TNVL_L1_CERTIFICATE_DER,0x20f), lVar11 != 0)) &&
             ((lVar11 = nvswitch_os_memcpy(lVar8 + 0x20f,TNVL_L2_CERTIFICATE_DER,0x28e), lVar11 != 0
              && (lVar11 = nvswitch_os_memcpy(lVar8 + 0x49d,TNVL_L3_CERTIFICATE_DER,0x2ae),
                 lVar11 != 0)))) {
            lVar11 = nvswitch_os_memcpy(lVar8 + 0x74b,lVar7,uVar16);
            if ((lVar11 != 0) &&
               (lVar11 = nvswitch_os_memcpy(lVar8 + 0x74b + uVar16,lVar14,uVar12), lVar11 != 0)) {
              if (uVar3 + 0x74b + uVar4 != uVar1) goto LAB_00253ed5;
              local_48 = 0;
              local_40[0] = 0;
              iVar6 = _pem_write_buffer_ls10_constprop_0(lVar14,uVar12,lVar9,0x1400,&local_48);
              lVar11 = local_48;
              if (iVar6 == 0) {
                lVar14 = lVar9 + -1 + local_48;
                iVar6 = _pem_write_buffer_ls10_constprop_0
                                  (lVar7,uVar16,lVar14,0x1401 - local_48,local_40);
                if ((iVar6 == 0) && (lVar11 = lVar11 + local_40[0], 0xa88 < lVar11 - 0x97aU)) {
                  lVar14 = lVar14 + -1 + local_40[0];
                  lVar13 = nvswitch_os_memcpy(lVar14,
                                              "-----BEGIN CERTIFICATE-----\nMIICqTCCAi+gAwIBAgIQcidIXMg4KYZ1y7ooFz5gUjAKBggqhkjOPQQDAzA9MR4w\nHAYDVQQDDBVOVklESUEgR0gxMDAgSWRlbnRpdHkxGzAZBgNVBAoMEk5WSURJQSBD\nb3Jwb3JhdGlvbjAgFw0yMjAzMDEwMDAwMDBaGA85OTk5MTIzMTIzNTk1OVowUzEn\nMCUGA1UEAwweTlZJRElBIExTXzEwIFByb3Zpc2lvbmVyIElDQSAxMRswGQYDVQQK\nDBJOVklESUEgQ29ycG9yYXRpb24xCzAJBgNVBAYTAlVTMHYwEAYHKoZIzj0CAQYF\nK4EEACIDYgAEyGbP8B2aF0Zd0V5GhWfcnC8K8BXUJMGPhAWQo88WymU0Az+u2Y7B\nzI9li0TyXhth18dB1yqodYgH3KKU1c0beV1OkAUvnlx3JpNPhx8nfdlhpM9jqsXG\nJXeJixW5+VOlo4HbMIHYMA8GA1UdEwEB/wQFMAMBAf8wDgYDVR0PAQH/BAQDAgEG\nMDwGA1UdHwQ1MDMwMaAvoC2GK2h0dHA6Ly9jcmwubmRpcy5udmlkaWEuY29tL2Ny\nbC9sMi1naDEwMC5jcmwwNwYIKwYBBQUHAQEEKzApMCcGCCsGAQUFBzABhhtodHRw\nOi8vb2NzcC5uZGlzLm52aWRpYS5jb20wHQYDVR0OBBYEFBFA9xSZ0ALwvOeei4fR\nvon435VEMB8GA1UdIwQYMBaAFAdCoOsDnIBge6FBYZlNriX3wpseMAoGCCqGSM49\nBAMDA2gAMGUCMQDWLHcBKxi9QVrfMoDcIg3gLBRe5oEo/Q4KR3WaUMz9ABxMHK9Y\nK4xPtjXW4Bup5FwCMBhLpTQqsly8gQ6w1CIyMEC4n/LSjM65TC4pGVokSyjpoyp0\ngWjuEBq1vBNs76Ge8A==\n-----END CERTIFICATE-----\n"
                                              ,0x3d9);
                  if ((lVar13 != 0) &&
                     ((lVar13 = nvswitch_os_memcpy(lVar14 + 0x3d9,
                                                                                                      
                                                  "-----BEGIN CERTIFICATE-----\nMIICijCCAhCgAwIBAgIQTCVe3jvQAb8/SjtgX8qJijAKBggqhkjOPQQDAzA1MSIw\nIAYDVQQDDBlOVklESUEgRGV2aWNlIElkZW50aXR5IENBMQ8wDQYDVQQKDAZOVklE\nSUEwIBcNMjIwMTEyMDAwMDAwWhgPOTk5OTEyMzEyMzU5NTlaMD0xHjAcBgNVBAMM\nFU5WSURJQSBHSDEwMCBJZGVudGl0eTEbMBkGA1UECgwSTlZJRElBIENvcnBvcmF0\naW9uMHYwEAYHKoZIzj0CAQYFK4EEACIDYgAE+pg+tDUuILlZILk5wg22YEJ9Oh6c\nyPcsv3IvgRWcV4LeZK1pTCoQDIplZ0E4qsLG3G04pxsbMhxbqkiz9pqlTV2rtuVg\nSmIqnSYkU1jWXsPS9oVLCGE8VRLl1JvqyOxUo4HaMIHXMA8GA1UdEwEB/wQFMAMB\nAf8wDgYDVR0PAQH/BAQDAgEGMDsGA1UdHwQ0MDIwMKAuoCyGKmh0dHA6Ly9jcmwu\nbmRpcy5udmlkaWEuY29tL2NybC9sMS1yb290LmNybDA3BggrBgEFBQcBAQQrMCkw\nJwYIKwYBBQUHMAGGG2h0dHA6Ly9vY3NwLm5kaXMubnZpZGlhLmNvbTAdBgNVHQ4E\nFgQUB0Kg6wOcgGB7oUFhmU2uJffCmx4wHwYDVR0jBBgwFoAUV4X/g/JjzGV9aLc6\nW/SNSsv7SV8wCgYIKoZIzj0EAwMDaAAwZQIxAPIQhnveFxYIrPzBqViT2I34SfS4\nJGWFnk/1UcdmgJmp+7l6rH/C4qxwntYSgeYrlQIwdjQuofHnhd1RL09OBO34566J\nC9bYAosT/86cCojiGjhLnal9hJOH0nS/lrbaoc5a\n-----END CERTIFICATE-----\n"
                                                  ,0x3ac), lVar13 != 0 &&
                      (lVar14 = nvswitch_os_memcpy(lVar14 + 0x785,
                                                                                                      
                                                  "-----BEGIN CERTIFICATE-----\nMIICCzCCAZCgAwIBAgIQLTZwscoQBBHB/sDoKgZbVDAKBggqhkjOPQQDAzA1MSIw\nIAYDVQQDDBlOVklESUEgRGV2aWNlIElkZW50aXR5IENBMQ8wDQYDVQQKDAZOVklE\nSUEwIBcNMjExMTA1MDAwMDAwWhgPOTk5OTEyMzEyMzU5NTlaMDUxIjAgBgNVBAMM\nGU5WSURJQSBEZXZpY2UgSWRlbnRpdHkgQ0ExDzANBgNVBAoMBk5WSURJQTB2MBAG\nByqGSM49AgEGBSuBBAAiA2IABA5MFKM7+KViZljbQSlgfky/RRnEQScW9NDZF8SX\ngAW96r6u/Ve8ZggtcYpPi2BS4VFu6KfEIrhN6FcHG7WP05W+oM+hxj7nyA1r1jkB\n2Ry70YfThX3Ba1zOryOP+MJ9vaNjMGEwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8B\nAf8EBAMCAQYwHQYDVR0OBBYEFFeF/4PyY8xlfWi3Olv0jUrL+0lfMB8GA1UdIwQY\nMBaAFFeF/4PyY8xlfWi3Olv0jUrL+0lfMAoGCCqGSM49BAMDA2kAMGYCMQCPeFM3\nTASsKQVaT+8S0sO9u97PVGCpE9d/I42IT7k3UUOLSR/qvJynVOD1vQKVXf0CMQC+\nEY55WYoDBvs2wPAH1Gw4LbcwUN8QCff8bFmV4ZxjCRr4WXTLFHBKjbfneGSBWwA=\n-----END CERTIFICATE-----\n"
                                                  ,0x301), lVar14 != 0)))) {
                    uVar16 = lVar11 + 0xa84;
                    if (uVar16 < 0x1401) {
                      nvswitch_os_memcpy(param_2,lVar9,uVar16);
                      *(int *)(param_2 + 0x1400) = (int)uVar16;
                      uVar15 = 0;
                      goto LAB_00253ef2;
                    }
                    goto LAB_00253ed5;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  uVar15 = 0xfffffffe;
LAB_00253ef2:
  nvswitch_os_free(lVar7);
  nvswitch_os_free(lVar8);
  nvswitch_os_free(lVar9);
  return uVar15;
}


// ===== 00254160 nvswitch_tnvl_get_attestation_report_ls10 =====

int nvswitch_tnvl_get_attestation_report_ls10(undefined8 param_1,long param_2)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  long lVar4;
  undefined1 local_30 [8];
  
  if (param_2 == 0) {
    iVar2 = -1;
  }
  else {
    cVar1 = nvswitch_is_tnvl_mode_enabled();
    if (cVar1 == '\0') {
      iVar2 = -0xd;
    }
    else {
      puVar3 = (undefined1 *)nvswitch_os_malloc_trace(0x24,0,0);
      lVar4 = nvswitch_os_malloc_trace(0x2015,0,0);
      if ((puVar3 == (undefined1 *)0x0) || (lVar4 == 0)) {
        iVar2 = -2;
      }
      else {
        *puVar3 = 1;
        *(undefined2 *)(puVar3 + 2) = 0x100;
        nvswitch_os_memcpy(puVar3 + 4,param_2,0x20);
        nvswitch_timeout_create(10000000000,local_30);
        iVar2 = nvswitch_fsp_send_and_read_message(param_1,puVar3,0x24,0x1f,lVar4,0x2015);
        if (iVar2 == 0) {
          if ((*(char *)(lVar4 + 0xd) == '\x01') && (*(uint *)(lVar4 + 0x11) < 0x2001)) {
            nvswitch_os_memcpy(param_2 + 0x20,lVar4 + 0x15,*(uint *)(lVar4 + 0x11),0x2541fc);
            *(undefined4 *)(param_2 + 0x2020) = *(undefined4 *)(lVar4 + 0x11);
          }
          else {
            iVar2 = -8;
          }
        }
      }
      nvswitch_os_free(puVar3);
      nvswitch_os_free(lVar4);
    }
  }
  return iVar2;
}


// ===== 002542c0 nvswitch_detect_tnvl_mode_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_detect_tnvl_mode_ls10(long param_1)

{
  ulong uVar1;
  
  uVar1 = (**(code **)(param_1 + 0x920))(param_1,1,0,0,0xc50);
  if ((uVar1 & 1) != 0) {
    *(undefined4 *)(param_1 + 0x1fec) = 1;
  }
  return 0;
}


// ===== 00254310 nvswitch_is_tnvl_mode_enabled_ls10 =====

undefined4 nvswitch_is_tnvl_mode_enabled_ls10(long param_1)

{
  return CONCAT31((int3)((uint)*(int *)(param_1 + 0x1fec) >> 8),*(int *)(param_1 + 0x1fec) != 0);
}


// ===== 00254320 nvswitch_is_tnvl_mode_locked_ls10 =====

bool nvswitch_is_tnvl_mode_locked_ls10(long param_1)

{
  return *(int *)(param_1 + 0x1fec) == 3;
}


// ===== 00254330 nvswitch_tnvl_send_fsp_lock_config_ls10 =====

undefined8 nvswitch_tnvl_send_fsp_lock_config_ls10(undefined8 param_1)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  long lVar4;
  undefined8 uVar5;
  undefined1 local_30 [16];
  
  cVar1 = nvswitch_is_tnvl_mode_enabled();
  if (cVar1 == '\0') {
    uVar5 = 0xfffffff3;
  }
  else {
    puVar3 = (undefined1 *)nvswitch_os_malloc_trace(4,0,0);
    lVar4 = nvswitch_os_malloc_trace(0x11,0,0);
    if ((puVar3 == (undefined1 *)0x0) || (lVar4 == 0)) {
      uVar5 = 0xfffffffe;
    }
    else {
      *puVar3 = 2;
      *(undefined2 *)(puVar3 + 2) = 0x100;
      nvswitch_timeout_create(5000000000,local_30);
      uVar5 = 0xfffffff8;
      iVar2 = nvswitch_fsp_send_and_read_message(param_1,puVar3,4,0x1f,lVar4,0x11);
      if ((iVar2 == 0) && (uVar5 = 0xfffffff8, *(char *)(lVar4 + 0xd) == '\x02')) {
        uVar5 = 0;
      }
    }
    nvswitch_os_free(puVar3);
    nvswitch_os_free(lVar4);
  }
  return uVar5;
}


// ===== 00254420 nvswitch_tnvl_get_status_ls10 =====

undefined8 nvswitch_tnvl_get_status_ls10(long param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x1fec);
  return 0;
}


// ===== 00254430 nvswitch_tnvl_eng_wr_32_ls10 =====

void nvswitch_tnvl_eng_wr_32_ls10
               (long *param_1,uint param_2,undefined4 param_3,undefined4 param_4,ulong param_5,
               uint param_6,undefined4 param_7)

{
  long lVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  ulong uVar5;
  
  if (*(long *)(*param_1 + 0x78) == 0) {
    return;
  }
  param_5 = param_5 & 0xffffffff;
  uVar5 = (ulong)param_6;
  cVar2 = nvswitch_is_tnvl_mode_enabled();
  if (cVar2 == '\0') {
    iVar3 = nvswitch_translate_hw_error(0x271a);
    if (iVar3 == 1) {
      nvswitch_assert_log();
    }
    lVar1 = *param_1;
    nvswitch_os_print(5,
                      "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, ENG reg-write failed. TNVL mode is not enabled\n"
                      ,param_1 + 1,*(undefined4 *)(lVar1 + 0x40),*(undefined1 *)(lVar1 + 0x44),
                      *(undefined1 *)(lVar1 + 0x45),*(undefined1 *)(lVar1 + 0x46),0x271a);
    nvswitch_os_report_error(param_1[3],0x271a,"ENG reg-write failed. TNVL mode is not enabled\n");
    pcVar4 = "ENG reg-write failed. TNVL mode is not enabled\n";
  }
  else {
    if (param_2 == 7) {
      if ((param_6 - 0x2980 < 0xd) && ((0x1111UL >> ((ulong)(param_6 - 0x2980) & 0x3f) & 1) != 0))
      goto LAB_00254517;
    }
    else if (param_2 < 8) {
      if (param_2 == 2) goto LAB_00254517;
      if (param_2 == 4) {
        if ((param_6 & 0xfffffffb) == 0x580) goto LAB_00254517;
      }
      else if ((param_2 == 1) && (param_6 == 0x514)) goto LAB_00254517;
    }
    else if (param_2 == 0x2c) {
      if ((param_6 & 0xfffffffb) == 0x150) goto LAB_00254517;
    }
    else if ((param_2 < 0x2d) && ((param_2 == 0x11 || (param_2 == 0x1d)))) {
LAB_00254517:
      nvswitch_os_mem_write32(param_5 + uVar5 + *(long *)(*param_1 + 0x78),param_7);
      return;
    }
    cVar2 = nvswitch_is_tnvl_mode_locked(param_1);
    if (cVar2 == '\0') {
      iVar3 = nvswitch_soe_eng_wr_32_ls10(param_1,param_2,param_3,param_4,param_5,uVar5);
      if (iVar3 == 0) {
        return;
      }
      iVar3 = nvswitch_translate_hw_error(0x271a);
      if (iVar3 == 1) {
        nvswitch_assert_log();
      }
      lVar1 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, TNVL ENG_WR failure - 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\n"
                        ,param_1 + 1,*(undefined4 *)(lVar1 + 0x40),*(undefined1 *)(lVar1 + 0x44),
                        *(undefined1 *)(lVar1 + 0x45),*(undefined1 *)(lVar1 + 0x46),0x271a,param_2,
                        param_4,param_3,param_5,uVar5,param_7);
      nvswitch_os_report_error
                (param_1[3],0x271a,"TNVL ENG_WR failure - 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\n",param_2,
                 param_4,param_3,param_5,uVar5,param_7);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x271a,"TNVL ENG_WR failure - 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\n",param_2,
                 param_4,param_3,param_5,uVar5,param_7);
      goto LAB_002545fb;
    }
    iVar3 = nvswitch_translate_hw_error(0x271a);
    if (iVar3 == 1) {
      nvswitch_assert_log();
    }
    lVar1 = *param_1;
    nvswitch_os_print(5,
                      "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, TNVL ENG_WR failure - 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\n"
                      ,param_1 + 1,*(undefined4 *)(lVar1 + 0x40),*(undefined1 *)(lVar1 + 0x44),
                      *(undefined1 *)(lVar1 + 0x45),*(undefined1 *)(lVar1 + 0x46),0x271a,param_2,
                      param_4,param_3,param_5,uVar5,param_7);
    nvswitch_os_report_error
              (param_1[3],0x271a,"TNVL ENG_WR failure - 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\n",param_2,
               param_4,param_3,param_5,uVar5,param_7);
    nvswitch_lib_smbpbi_log_sxid
              (param_1,0x271a,"TNVL ENG_WR failure - 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\n",param_2,
               param_4,param_3,param_5,uVar5,param_7);
    nvswitch_inforom_bbx_add_sxid(param_1,0x271a,0,0,0);
    iVar3 = nvswitch_translate_hw_error(0x271a);
    if (iVar3 == 1) {
      nvswitch_assert_log();
    }
    lVar1 = *param_1;
    nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, TNVL mode is locked\n",
                      param_1 + 1,*(undefined4 *)(lVar1 + 0x40),*(undefined1 *)(lVar1 + 0x44),
                      *(undefined1 *)(lVar1 + 0x45),*(undefined1 *)(lVar1 + 0x46),0x271a);
    nvswitch_os_report_error(param_1[3],0x271a,"TNVL mode is locked\n");
    pcVar4 = "TNVL mode is locked\n";
  }
  nvswitch_lib_smbpbi_log_sxid(param_1,0x271a,pcVar4);
LAB_002545fb:
  nvswitch_inforom_bbx_add_sxid(param_1,0x271a,0,0,0);
  return;
}


// ===== 00254880 nvswitch_tnvl_reg_wr_32_ls10 =====

void nvswitch_tnvl_reg_wr_32_ls10(long *param_1,uint param_2,undefined4 param_3)

{
  long lVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  
  if (*(long *)(*param_1 + 0x78) == 0) {
    nvswitch_assert_log();
    return;
  }
  uVar4 = (ulong)param_2;
  cVar2 = nvswitch_is_tnvl_mode_enabled();
  if (cVar2 == '\0') {
    iVar3 = nvswitch_translate_hw_error(0x271a);
    if (iVar3 == 1) {
      nvswitch_assert_log();
    }
    lVar1 = *param_1;
    nvswitch_os_print(5,
                      "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Reg-write failed. TNVL mode is not enabled\n"
                      ,param_1 + 1,*(undefined4 *)(lVar1 + 0x40),*(undefined1 *)(lVar1 + 0x44),
                      *(undefined1 *)(lVar1 + 0x45),*(undefined1 *)(lVar1 + 0x46),0x271a);
    nvswitch_os_report_error(param_1[3],0x271a,"Reg-write failed. TNVL mode is not enabled\n");
    nvswitch_lib_smbpbi_log_sxid(param_1,0x271a,"Reg-write failed. TNVL mode is not enabled\n");
  }
  else {
    if ((param_2 - 0x8f0000 < 0x4000) || (param_2 - 0x840000 < 0x4000)) {
      nvswitch_os_mem_write32(uVar4 + *(long *)(*param_1 + 0x78),param_3);
      return;
    }
    cVar2 = nvswitch_is_tnvl_mode_locked(param_1);
    if (cVar2 == '\0') {
      iVar3 = nvswitch_soe_reg_wr_32_ls10(param_1,uVar4,param_3);
      if (iVar3 == 0) {
        return;
      }
      iVar3 = nvswitch_translate_hw_error(0x271a);
      if (iVar3 == 1) {
        nvswitch_assert_log();
      }
      lVar1 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, TNVL REG_WR failure - 0x%08x, 0x%08x\n"
                        ,param_1 + 1,*(undefined4 *)(lVar1 + 0x40),*(undefined1 *)(lVar1 + 0x44),
                        *(undefined1 *)(lVar1 + 0x45),*(undefined1 *)(lVar1 + 0x46),0x271a,uVar4,
                        param_3);
      nvswitch_os_report_error
                (param_1[3],0x271a,"TNVL REG_WR failure - 0x%08x, 0x%08x\n",param_2,param_3);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x271a,"TNVL REG_WR failure - 0x%08x, 0x%08x\n",uVar4,param_3);
    }
    else {
      iVar3 = nvswitch_translate_hw_error(0x271a);
      if (iVar3 == 1) {
        nvswitch_assert_log();
      }
      lVar1 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, TNVL REG_WR failure - 0x%08x, 0x%08x\n"
                        ,param_1 + 1,*(undefined4 *)(lVar1 + 0x40),*(undefined1 *)(lVar1 + 0x44),
                        *(undefined1 *)(lVar1 + 0x45),*(undefined1 *)(lVar1 + 0x46),0x271a,uVar4,
                        param_3);
      nvswitch_os_report_error
                (param_1[3],0x271a,"TNVL REG_WR failure - 0x%08x, 0x%08x\n",uVar4,param_3);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x271a,"TNVL REG_WR failure - 0x%08x, 0x%08x\n",uVar4,param_3);
      nvswitch_inforom_bbx_add_sxid(param_1,0x271a,0,0,0);
      iVar3 = nvswitch_translate_hw_error(0x271a);
      if (iVar3 == 1) {
        nvswitch_assert_log();
      }
      lVar1 = *param_1;
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, TNVL mode is locked\n",
                        param_1 + 1,*(undefined4 *)(lVar1 + 0x40),*(undefined1 *)(lVar1 + 0x44),
                        *(undefined1 *)(lVar1 + 0x45),*(undefined1 *)(lVar1 + 0x46),0x271a);
      nvswitch_os_report_error(param_1[3],0x271a,"TNVL mode is locked\n");
      nvswitch_lib_smbpbi_log_sxid(param_1,0x271a,"TNVL mode is locked\n");
    }
  }
  nvswitch_inforom_bbx_add_sxid(param_1,0x271a,0,0,0);
  return;
}


// ===== 00254bd0 nvswitch_tnvl_disable_interrupts_ls10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_tnvl_disable_interrupts_ls10(long *param_1)

{
  long lVar1;
  char cVar2;
  int iVar3;
  
  cVar2 = nvswitch_is_tnvl_mode_enabled();
  if (cVar2 != '\0') {
    (*(code *)param_1[0x125])(param_1,0x11,0,0,0x1c004,0xffff);
    (*(code *)param_1[0x125])(param_1,0x11,0,0,0x1c018,0xffff);
    (*(code *)param_1[0x125])(param_1,0x11,0,0,0x1c024,0xffffffff);
    return;
  }
  iVar3 = nvswitch_translate_hw_error(0x271a);
  if (iVar3 == 1) {
    nvswitch_assert_log();
  }
  lVar1 = *param_1;
  nvswitch_os_print(5,
                    "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Failed to disable non-fatal/legacy interrupts. TNVL mode is not enabled\n"
                    ,param_1 + 1,*(undefined4 *)(lVar1 + 0x40),*(undefined1 *)(lVar1 + 0x44),
                    *(undefined1 *)(lVar1 + 0x45),*(undefined1 *)(lVar1 + 0x46),0x271a);
  nvswitch_os_report_error
            (param_1[3],0x271a,
             "Failed to disable non-fatal/legacy interrupts. TNVL mode is not enabled\n");
  nvswitch_lib_smbpbi_log_sxid
            (param_1,0x271a,
             "Failed to disable non-fatal/legacy interrupts. TNVL mode is not enabled\n");
  nvswitch_inforom_bbx_add_sxid(param_1,0x271a,0,0,0);
  return;
}


// ===== 00254d00 _nvswitch_corelib_add_link =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_corelib_add_link(long param_1)

{
  (**(code **)(*(long *)(*(long *)(param_1 + 0x10) + 200) + 0x6a0))();
  return;
}


// ===== 00254d20 _nvswitch_corelib_remove_link =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_corelib_remove_link(long param_1)

{
  (**(code **)(*(long *)(*(long *)(param_1 + 0x10) + 200) + 0x6a8))();
  return;
}


// ===== 00254d40 _nvswitch_corelib_set_dl_link_mode =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_corelib_set_dl_link_mode(long param_1)

{
  (**(code **)(*(long *)(*(long *)(param_1 + 0x10) + 200) + 0x6b0))();
  return;
}


// ===== 00254d60 _nvswitch_corelib_get_dl_link_mode =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_corelib_get_dl_link_mode(long param_1)

{
  (**(code **)(*(long *)(*(long *)(param_1 + 0x10) + 200) + 0x6b8))();
  return;
}


// ===== 00254d80 _nvswitch_corelib_set_tl_link_mode =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_corelib_set_tl_link_mode(long param_1)

{
  (**(code **)(*(long *)(*(long *)(param_1 + 0x10) + 200) + 0x6c0))();
  return;
}


// ===== 00254da0 _nvswitch_corelib_get_tl_link_mode =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_corelib_get_tl_link_mode(long param_1)

{
  (**(code **)(*(long *)(*(long *)(param_1 + 0x10) + 200) + 0x6c8))();
  return;
}


// ===== 00254dc0 _nvswitch_corelib_set_tx_mode =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_corelib_set_tx_mode(long param_1)

{
  (**(code **)(*(long *)(*(long *)(param_1 + 0x10) + 200) + 0x6d0))();
  return;
}


// ===== 00254de0 _nvswitch_corelib_get_tx_mode =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_corelib_get_tx_mode(long param_1)

{
  (**(code **)(*(long *)(*(long *)(param_1 + 0x10) + 200) + 0x6d8))();
  return;
}


// ===== 00254e00 _nvswitch_corelib_set_rx_mode =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_corelib_set_rx_mode(long param_1)

{
  (**(code **)(*(long *)(*(long *)(param_1 + 0x10) + 200) + 0x6e0))();
  return;
}


// ===== 00254e20 _nvswitch_corelib_get_rx_mode =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_corelib_get_rx_mode(long param_1)

{
  (**(code **)(*(long *)(*(long *)(param_1 + 0x10) + 200) + 0x6e8))();
  return;
}


// ===== 00254e40 _nvswitch_corelib_set_rx_detect =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_corelib_set_rx_detect(long param_1)

{
  (**(code **)(*(long *)(*(long *)(param_1 + 0x10) + 200) + 0x6f0))();
  return;
}


// ===== 00254e60 _nvswitch_corelib_get_rx_detect =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_corelib_get_rx_detect(long param_1)

{
  (**(code **)(*(long *)(*(long *)(param_1 + 0x10) + 200) + 0x6f8))();
  return;
}


// ===== 00254e80 _nvswitch_corelib_training_complete =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_corelib_training_complete(long param_1)

{
  (**(code **)(*(long *)(*(long *)(param_1 + 0x10) + 200) + 0x700))();
  return;
}


// ===== 00254ea0 _nvswitch_corelib_get_uphy_load =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_corelib_get_uphy_load(long param_1)

{
  (**(code **)(*(long *)(*(long *)(param_1 + 0x10) + 200) + 0x9f8))();
  return;
}


// ===== 00254ec0 _nvswitch_corelib_write_discovery_token =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _nvswitch_corelib_write_discovery_token(long param_1)

{
  long lVar1;
  
  if (*(uint *)(param_1 + 0x5c) < 7) {
    return 0;
  }
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 200);
  (**(code **)(lVar1 + 0xa20))(lVar1,param_1);
  return 0;
}


// ===== 00254f00 _nvswitch_corelib_read_discovery_token =====

undefined8 _nvswitch_corelib_read_discovery_token(void)

{
  return 0;
}


// ===== 00254f10 _nvswitch_corelib_get_cci_link_mode =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_corelib_get_cci_link_mode(long param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 200);
  (**(code **)(lVar1 + 0xbf0))(lVar1,*(undefined4 *)(param_1 + 0x38),param_2);
  return;
}


// ===== 00254f40 _nvswitch_corelib_ali_training =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void _nvswitch_corelib_ali_training(long param_1)

{
  long lVar1;
  code *pcVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 200);
  pcVar2 = *(code **)(lVar1 + 0xcb8);
  (*pcVar2)(lVar1,param_1,0,pcVar2);
  return;
}


// ===== 00254f60 _nvswitch_update_link_state_led =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_update_link_state_led(long param_1)

{
  (**(code **)(param_1 + 0xca0))();
  return;
}


// ===== 00254f70 nvswitch_internal_latency_bin_log =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_internal_latency_bin_log(long param_1)

{
  (**(code **)(param_1 + 0x540))();
  return;
}


// ===== 00254f80 nvswitch_ecc_writeback_task =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_ecc_writeback_task(long param_1)

{
  (**(code **)(param_1 + 0x548))();
  return;
}


// ===== 00254f90 nvswitch_monitor_thermal_alert =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_monitor_thermal_alert(long param_1)

{
  (**(code **)(param_1 + 0x550))();
  return;
}


// ===== 00254fa0 _nvswitch_perform_i2c_transfer =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
_nvswitch_perform_i2c_transfer
          (long param_1,undefined4 param_2,byte param_3,short param_4,byte param_5,
          undefined1 param_6,uint param_7,undefined8 param_8)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  byte local_14c [2];
  ushort local_14a;
  uint local_148;
  undefined4 local_144;
  undefined1 local_140;
  uint local_13c;
  undefined1 local_138 [264];
  
  memset(local_14c,0,0x114);
  iVar4 = nvswitch_os_is_admin();
  if (iVar4 == 0) {
    return 0xfffffff1;
  }
  uVar6 = *(uint *)((ulong)param_5 * 0x58 + *(long *)(param_1 + 0xf48) + 0x50);
  if (4 < uVar6) {
    return 0xffffffff;
  }
  local_14a = param_4 * 2;
  iVar4 = *(int *)(param_1 + 0xbc);
  uVar6 = uVar6 * 0x200 + 0x60d;
  local_14c[0] = param_5;
  local_144 = param_2;
  if (param_3 == 3) {
    uVar6 = uVar6 | 0x20;
    bVar1 = 0x100 < param_7;
    if (iVar4 == 1) {
      if (0x100 < param_7) {
        return 0xffffffff;
      }
      nvswitch_os_memcpy(local_138,param_8,param_7);
      bVar1 = false;
    }
    else {
LAB_002550f7:
      cVar3 = (**(code **)(param_1 + 0xa48))(param_1,param_5,local_14a & 0xff,0);
      if (cVar3 == '\0') {
        return 0xffffffff;
      }
      if (bVar1) {
        return 0xffffffff;
      }
      bVar2 = false;
      nvswitch_os_memcpy(local_138,param_8,param_7);
      bVar1 = false;
      if ((uVar6 & 0xe0) != 0x20) goto LAB_00255160;
    }
LAB_002550bb:
    bVar2 = bVar1;
    local_140 = param_6;
  }
  else if (param_3 < 4) {
    if (param_3 == 1) {
      if (iVar4 != 1) {
        bVar1 = 0x100 < param_7;
        goto LAB_002550f7;
      }
      if (0x100 < param_7) {
        return 0xffffffff;
      }
      bVar2 = false;
      nvswitch_os_memcpy(local_138,param_8,param_7);
    }
    else {
      if (param_3 == 2) {
        uVar6 = uVar6 | 0x22;
        if (iVar4 == 1) {
          if (0x100 < param_7) {
            return 0xffffffff;
          }
          local_14c[1] = 1;
          bVar1 = true;
          goto LAB_002550bb;
        }
      }
      else if (iVar4 == 1) {
        if (0x100 < param_7) {
          return 0xffffffff;
        }
        local_14c[1] = 1;
        local_13c = param_7;
        local_148 = uVar6;
        uVar5 = (**(code **)(param_1 + 0x680))(param_1,local_14c);
        if ((int)uVar5 != 0) {
          return uVar5;
        }
        goto LAB_00255230;
      }
      bVar1 = 0x100 < param_7;
LAB_00255066:
      cVar3 = (**(code **)(param_1 + 0xa48))(param_1,param_5,local_14a & 0xff,1);
      if ((cVar3 == '\0') || (bVar1)) {
        return 0xffffffff;
      }
      local_14c[1] = 1;
      bVar2 = true;
      bVar1 = true;
      if ((uVar6 & 0xe0) == 0x20) goto LAB_002550bb;
    }
  }
  else if (param_3 == 4) {
    param_7 = 0;
    bVar1 = false;
    if (iVar4 != 1) goto LAB_00255066;
    local_14c[1] = 1;
    bVar2 = true;
  }
  else {
    if (param_3 != 5) {
      return 0xffffffff;
    }
    param_7 = 0;
    bVar1 = false;
    if (iVar4 != 1) goto LAB_002550f7;
    bVar2 = false;
    nvswitch_os_memcpy(local_138,param_8,0);
  }
LAB_00255160:
  local_13c = param_7;
  local_148 = uVar6;
  uVar5 = (**(code **)(param_1 + 0x680))(param_1,local_14c);
  if ((int)uVar5 != 0) {
    return uVar5;
  }
  if (!bVar2) {
    return uVar5;
  }
LAB_00255230:
  nvswitch_os_memcpy(param_8,local_138,param_7);
  return 0;
}


// ===== 00255390 _nvswitch_check_pending_data_and_notify.part.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_check_pending_data_and_notify_part_0(long param_1,long param_2)

{
  uint uVar1;
  long *plVar2;
  uint uVar3;
  
  plVar2 = (long *)(param_1 + 0xf80);
  for (uVar3 = 0; uVar1 = (**(code **)(param_1 + 0x510))(param_1), uVar3 < uVar1; uVar3 = uVar3 + 1)
  {
    if (((long *)*plVar2 != plVar2) || ((long *)plVar2[2] != plVar2 + 2)) {
      nvswitch_os_notify_client_event
                (*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_2 + 0x18),
                 *(undefined4 *)(param_2 + 0x10));
    }
    plVar2 = plVar2 + 8;
  }
  return;
}


// ===== 00255400 _nvswitch_unregister_links =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_unregister_links(long *param_1)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  long local_30 [2];
  
  local_30[0] = 0;
  if ((((param_1 != (long *)0x0) && (lVar1 = *param_1, *(long *)(lVar1 + 0xa8) == 3)) &&
      (*(long *)(lVar1 + 0x78) != 0)) && (*(char *)(lVar1 + 0xb0) != '\0')) {
    *(undefined1 *)(lVar1 + 0xb0) = 0;
    lVar1 = param_1[0x3f6];
    for (uVar5 = 0; uVar3 = (*(code *)param_1[0xa2])(param_1), uVar5 < uVar3; uVar5 = uVar5 + 1) {
      iVar4 = nvlink_lib_get_link(*param_1,uVar5,local_30);
      if (iVar4 == 0) {
        nvlink_lib_unregister_link(local_30[0]);
        lVar2 = local_30[0];
        if (*(long *)(local_30[0] + 0x98) != 0) {
          nvswitch_os_free();
        }
        nvswitch_os_free(lVar2);
      }
    }
    if ((int)lVar1 != 3) {
      nvswitch_inforom_nvlink_flush(param_1);
      return;
    }
  }
  return;
}


// ===== 00255500 nvswitch_is_lr10_device_id =====

undefined8 nvswitch_is_lr10_device_id(int param_1)

{
  int *piVar1;
  
  piVar1 = &nvswitch_lr10_device_ids;
  do {
    if (param_1 == *piVar1) {
      return 1;
    }
    piVar1 = piVar1 + 1;
  } while (piVar1 != (int *)&DAT_00cc9ba4);
  return 0;
}


// ===== 00255530 nvswitch_is_ls10_device_id =====

undefined8 nvswitch_is_ls10_device_id(int param_1)

{
  int *piVar1;
  
  piVar1 = &nvswitch_ls10_device_ids;
  do {
    if (param_1 == *piVar1) {
      return 1;
    }
    piVar1 = piVar1 + 1;
  } while (piVar1 != &nvswitch_lr10_device_ids);
  return 0;
}


// ===== 00255560 nvswitch_lib_deferred_task_dispatcher =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

long nvswitch_lib_deferred_task_dispatcher(long *param_1)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  uint uVar6;
  ulong uVar7;
  bool bVar8;
  
  lVar3 = nvswitch_os_get_platform_time();
  if ((param_1 != (long *)0x0) && (*(long *)(*param_1 + 0xa8) == 3)) {
    uVar7 = lVar3 + 100000000;
    plVar1 = (long *)param_1[0x1d];
    while (plVar2 = plVar1, plVar2 != (long *)0x0) {
      uVar4 = nvswitch_os_get_platform_time();
      uVar6 = *(uint *)(plVar2 + 7);
      uVar5 = plVar2[6] + plVar2[5];
      if (uVar4 < uVar5) {
        bVar8 = plVar2[6] == uVar4;
      }
      else {
        plVar2[6] = uVar4;
        lVar3 = *param_1;
        if ((((*(long *)(lVar3 + 0xa8) == 3) && (*(long *)(lVar3 + 0x78) != 0)) &&
            (*(char *)(lVar3 + 0xb0) != '\0')) || ((uVar6 & 1) != 0)) {
          if ((uVar6 & 4) == 0) {
            (*(code *)plVar2[3])(param_1);
          }
          else {
            (*(code *)plVar2[2])(param_1,plVar2[4]);
          }
          uVar6 = *(uint *)(plVar2 + 7);
          uVar5 = plVar2[5] + plVar2[6];
          bVar8 = uVar4 == plVar2[6];
        }
        else {
          uVar5 = plVar2[5] + uVar4;
          bVar8 = true;
        }
      }
      if (uVar5 < uVar7) {
        uVar7 = uVar5;
      }
      plVar1 = (long *)plVar2[1];
      if (((uVar6 & 2) != 0) && (bVar8)) {
        lVar3 = *plVar2;
        if (lVar3 == 0) {
          param_1[0x1d] = (long)plVar1;
          if (plVar1 != (long *)0x0) {
            *plVar1 = 0;
          }
          nvswitch_os_free(plVar2);
          plVar1 = (long *)param_1[0x1d];
        }
        else {
          *(long **)(lVar3 + 8) = plVar1;
          if (plVar1 != (long *)0x0) {
            *plVar1 = lVar3;
          }
          nvswitch_os_free(plVar2);
          plVar1 = *(long **)(lVar3 + 8);
        }
      }
    }
    uVar5 = nvswitch_os_get_platform_time();
    lVar3 = uVar7 - uVar5;
    if (uVar7 < uVar5) {
      lVar3 = 0;
    }
    return lVar3;
  }
  return -1;
}


// ===== 00255730 nvswitch_lib_check_api_version =====

undefined8 nvswitch_lib_check_api_version(long param_1,long param_2,uint param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  
  uVar1 = nvswitch_os_strlen("595.71.05");
  if ((param_2 == 0) || (param_1 == 0)) {
    uVar2 = 0xffffffff;
  }
  else if (param_3 < uVar1) {
    uVar2 = 0xfffffffe;
  }
  else {
    nvswitch_os_memset(param_2,0);
    nvswitch_os_strncpy(param_2,"595.71.05",uVar1);
    *(undefined1 *)(param_2 + (ulong)(param_3 - 1)) = 0;
    uVar2 = nvswitch_os_strncmp(param_1,param_2,uVar1);
    if ((int)uVar2 != 0) {
      uVar2 = 0xfffffff3;
    }
  }
  return uVar2;
}


// ===== 002557f0 nvswitch_is_inforom_supported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_is_inforom_supported(long param_1)

{
  (**(code **)(param_1 + 0x738))();
  return;
}


// ===== 00255800 nvswitch_is_spi_supported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_is_spi_supported(long param_1)

{
  (**(code **)(param_1 + 0x740))();
  return;
}


// ===== 00255810 nvswitch_is_bios_supported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_is_bios_supported(long param_1)

{
  (**(code **)(param_1 + 0x748))();
  return;
}


// ===== 00255820 nvswitch_is_smbpbi_supported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_is_smbpbi_supported(long param_1)

{
  (**(code **)(param_1 + 0x758))();
  return;
}


// ===== 00255830 nvswitch_is_soe_supported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_is_soe_supported(long param_1)

{
  (**(code **)(param_1 + 0x728))();
  return;
}


// ===== 00255840 nvswitch_init_soe =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_init_soe(long param_1)

{
  (**(code **)(param_1 + 0x730))();
  return;
}


// ===== 00255850 nvswitch_soe_init_l2_state =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_soe_init_l2_state(long param_1)

{
  (**(code **)(param_1 + 0xac0))();
  return;
}


// ===== 00255860 nvswitch_soe_issue_ingress_stop =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_soe_issue_ingress_stop(long param_1,undefined8 param_2,undefined1 param_3)

{
  (**(code **)(param_1 + 0xb90))(param_1,param_2,param_3);
  return;
}


// ===== 00255880 nvswitch_fsp_update_cmdq_head_tail =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_fsp_update_cmdq_head_tail(long param_1)

{
  (**(code **)(param_1 + 0xb08))();
  return;
}


// ===== 00255890 nvswitch_fsp_get_cmdq_head_tail =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_fsp_get_cmdq_head_tail(long param_1)

{
  (**(code **)(param_1 + 0xb10))();
  return;
}


// ===== 002558a0 nvswitch_fsp_update_msgq_head_tail =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_fsp_update_msgq_head_tail(long param_1)

{
  (**(code **)(param_1 + 0xb18))();
  return;
}


// ===== 002558b0 nvswitch_fsp_get_msgq_head_tail =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_fsp_get_msgq_head_tail(long param_1)

{
  (**(code **)(param_1 + 0xb20))();
  return;
}


// ===== 002558c0 nvswitch_fsp_get_channel_size =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_fsp_get_channel_size(long param_1)

{
  (**(code **)(param_1 + 0xb28))();
  return;
}


// ===== 002558d0 nvswitch_fsp_nvdm_to_seid =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_fsp_nvdm_to_seid(long param_1,undefined1 param_2)

{
  (**(code **)(param_1 + 0xb30))(param_1,param_2);
  return;
}


// ===== 002558f0 nvswitch_fsp_create_mctp_header =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_fsp_create_mctp_header
               (long param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
               undefined1 param_5)

{
  (**(code **)(param_1 + 0xb38))(param_1,param_2,param_3,param_4,param_5);
  return;
}


// ===== 00255910 nvswitch_fsp_create_nvdm_header =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_fsp_create_nvdm_header(long param_1)

{
  (**(code **)(param_1 + 0xb40))();
  return;
}


// ===== 00255920 nvswitch_fsp_get_packet_info =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_fsp_get_packet_info(long param_1)

{
  (**(code **)(param_1 + 0xb80))();
  return;
}


// ===== 00255930 nvswitch_fsp_validate_mctp_payload_header =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_fsp_validate_mctp_payload_header(long param_1)

{
  (**(code **)(param_1 + 0xb48))();
  return;
}


// ===== 00255940 nvswitch_fsp_process_nvdm_msg =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_fsp_process_nvdm_msg(long param_1)

{
  (**(code **)(param_1 + 0xb50))();
  return;
}


// ===== 00255950 nvswitch_fsp_process_cmd_response =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_fsp_process_cmd_response(long param_1)

{
  (**(code **)(param_1 + 0xb58))();
  return;
}


// ===== 00255960 nvswitch_fsp_config_ememc =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_fsp_config_ememc
               (long param_1,undefined8 param_2,undefined1 param_3,undefined1 param_4)

{
  (**(code **)(param_1 + 0xb60))(param_1,param_2,param_3,param_4);
  return;
}


// ===== 00255980 nvswitch_fsp_write_to_emem =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_fsp_write_to_emem(long param_1)

{
  (**(code **)(param_1 + 0xb68))();
  return;
}


// ===== 00255990 nvswitch_fsp_read_from_emem =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_fsp_read_from_emem(long param_1)

{
  (**(code **)(param_1 + 0xb70))();
  return;
}


// ===== 002559a0 nvswitch_fsp_error_code_to_nvlstatus_map =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_fsp_error_code_to_nvlstatus_map(long param_1)

{
  (**(code **)(param_1 + 0xb78))();
  return;
}


// ===== 002559b0 nvswitch_tnvl_disable_interrupts =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_tnvl_disable_interrupts(long param_1)

{
  (**(code **)(param_1 + 0xbd8))();
  return;
}


// ===== 002559c0 nvswitch_get_sublink_width =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_get_sublink_width(long param_1)

{
  (**(code **)(param_1 + 0xa40))();
  return;
}


// ===== 002559d0 nvswitch_lib_read_fabric_state =====

undefined8
nvswitch_lib_read_fabric_state
          (long *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  if (((param_1 != (long *)0x0) && (*(long *)(*param_1 + 0xa8) == 3)) &&
     (*(long *)(*param_1 + 0x78) != 0)) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = (int)param_1[0x3f6];
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)((long)param_1 + 0x1fb4);
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *(undefined4 *)((long)param_1 + 0x1fac);
    }
    return 0;
  }
  return 0xffffffff;
}


// ===== 00255a30 _nvswitch_construct_port_event_log =====

int _nvswitch_construct_port_event_log(undefined8 *param_1,uint param_2,undefined1 param_3)

{
  long lVar1;
  
  if (param_1 == (undefined8 *)0x0) {
    nvswitch_os_assert_log("NVSwitch: Assertion failed\n");
  }
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = 0;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 4) = param_3;
  *(undefined1 *)((long)param_1 + 0x21) = 0;
  if (param_2 == 0) {
    return 0;
  }
  lVar1 = nvswitch_os_malloc_trace((ulong)param_2 * 0x28,0,0);
  param_1[3] = lVar1;
  if (lVar1 != 0) {
    *(uint *)(param_1 + 2) = param_2;
    nvswitch_os_memset(lVar1,0,(ulong)param_2 * 0x28);
  }
  return ((*(uint *)(param_1 + 2) == param_2) - 2) + (uint)(*(uint *)(param_1 + 2) == param_2);
}


// ===== 00255b00 nvswitch_lib_validate_device_id =====

undefined8 nvswitch_lib_validate_device_id(int param_1)

{
  int *piVar1;
  
  piVar1 = &nvswitch_lr10_device_ids;
  do {
    if (param_1 == *piVar1) {
      return 1;
    }
    piVar1 = piVar1 + 1;
  } while (piVar1 != (int *)&DAT_00cc9ba4);
  piVar1 = &nvswitch_ls10_device_ids;
  do {
    if (param_1 == *piVar1) {
      return 1;
    }
    piVar1 = piVar1 + 1;
  } while (piVar1 != &nvswitch_lr10_device_ids);
  return 0;
}


// ===== 00255b50 nvswitch_lib_post_init_blacklist_device =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_lib_post_init_blacklist_device(long param_1)

{
  (**(code **)(param_1 + 0x768))();
  return;
}


// ===== 00255b60 nvswitch_lib_get_client_event =====

undefined8 nvswitch_lib_get_client_event(long *param_1,long param_2,undefined8 *param_3)

{
  long *plVar1;
  
  *param_3 = 0;
  if ((param_1 == (long *)0x0) || (*(long *)(*param_1 + 0xa8) != 3)) {
    return 0xffffffff;
  }
  plVar1 = (long *)param_1[0x3fb];
  while( true ) {
    if (plVar1 == param_1 + 0x3fb) {
      return 0xfffffffd;
    }
    if (plVar1[3] == param_2) break;
    plVar1 = (long *)*plVar1;
  }
  *param_3 = plVar1;
  if ((int)plVar1[2] != 5) {
    return 0;
  }
  _nvswitch_check_pending_data_and_notify_part_0();
  return 0;
}


// ===== 00255bf0 nvswitch_lib_add_client_event =====

int nvswitch_lib_add_client_event(long *param_1,long param_2,uint param_3)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  
  if (((param_1 != (long *)0x0) && (*(long *)(*param_1 + 0xa8) == 3)) && (param_3 < 6)) {
    iVar2 = nvswitch_os_add_client_event(param_1[3]);
    if (iVar2 == 0) {
      plVar3 = (long *)nvswitch_os_malloc_trace(0x20,0,0);
      if (plVar3 != (long *)0x0) {
        *(uint *)(plVar3 + 2) = param_3;
        plVar3[3] = param_2;
        lVar1 = param_1[0x3fb];
        *(long **)(lVar1 + 8) = plVar3;
        *plVar3 = lVar1;
        plVar3[1] = (long)(param_1 + 0x3fb);
        param_1[0x3fb] = (long)plVar3;
        return 0;
      }
      iVar2 = -2;
    }
    return iVar2;
  }
  return -1;
}


// ===== 00255cc0 nvswitch_lib_remove_client_events =====

undefined8 nvswitch_lib_remove_client_events(long *param_1,long param_2)

{
  long *plVar1;
  long lVar2;
  long *plVar3;
  undefined8 uVar4;
  long *plVar5;
  long *plVar6;
  
  if ((param_1 != (long *)0x0) && (*(long *)(*param_1 + 0xa8) == 3)) {
    plVar6 = (long *)param_1[0x3fb];
    plVar1 = param_1 + 0x3fb;
    if (plVar6 != plVar1) {
      plVar3 = (long *)*plVar6;
      do {
        plVar5 = plVar3;
        if (param_2 == plVar6[3]) {
          do {
            lVar2 = *plVar6;
            plVar3 = (long *)plVar6[1];
            *(long **)(lVar2 + 8) = plVar3;
            *plVar3 = lVar2;
            plVar6[1] = (long)plVar6;
            *plVar6 = (long)plVar6;
            nvswitch_os_free();
            do {
              plVar6 = plVar5;
              plVar5 = (long *)*plVar6;
              if (plVar6 == plVar1) {
                uVar4 = nvswitch_os_remove_client_event(param_1[3]);
                return uVar4;
              }
            } while (param_2 != plVar6[3]);
          } while( true );
        }
        plVar3 = (long *)*plVar5;
        plVar6 = plVar5;
      } while (plVar5 != plVar1);
    }
    uVar4 = nvswitch_os_remove_client_event(param_1[3]);
    return uVar4;
  }
  return 0;
}


// ===== 00255da0 nvswitch_lib_notify_client_events =====

undefined8 nvswitch_lib_notify_client_events(long *param_1,uint param_2)

{
  long *plVar1;
  undefined8 uVar2;
  
  if (((param_1 != (long *)0x0) && (*(long *)(*param_1 + 0xa8) == 3)) && (param_2 < 6)) {
    plVar1 = (long *)param_1[0x3fb];
    while( true ) {
      if (plVar1 == param_1 + 0x3fb) {
        return 0;
      }
      if ((*(uint *)(plVar1 + 2) == param_2) &&
         (uVar2 = nvswitch_os_notify_client_event(param_1[3],plVar1[3],param_2), (int)uVar2 != 0))
      break;
      plVar1 = (long *)*plVar1;
    }
    return uVar2;
  }
  return 0xffffffff;
}


// ===== 00255e40 nvswitch_record_port_event =====

void nvswitch_record_port_event
               (undefined8 param_1,uint *param_2,undefined4 param_3,undefined1 param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  
  if (param_2 == (uint *)0x0) {
    nvswitch_os_assert_log("NVSwitch: Assertion failed\n");
  }
  uVar1 = param_2[4];
  if ((uVar1 != 0) && (*(long *)(param_2 + 6) != 0)) {
    uVar2 = param_2[1];
    uVar3 = *param_2;
    if (uVar1 == uVar2) {
      if ((char)param_2[8] == '\0') {
        return;
      }
      *(undefined1 *)((long)param_2 + 0x21) = 1;
      *param_2 = (uVar3 + 1) % uVar1;
    }
    else {
      param_2[1] = uVar2 + 1;
    }
    lVar6 = ((ulong)(uVar3 + uVar2) % (ulong)uVar1) * 0x28;
    *(undefined4 *)(*(long *)(param_2 + 6) + 0x18 + lVar6) = param_3;
    *(undefined1 *)(*(long *)(param_2 + 6) + lVar6) = param_4;
    lVar4 = *(long *)(param_2 + 6);
    uVar5 = nvswitch_os_get_platform_time();
    *(undefined8 *)(lVar6 + lVar4 + 0x20) = uVar5;
    *(undefined8 *)(*(long *)(param_2 + 6) + 8 + lVar6) = *(undefined8 *)(param_2 + 2);
  }
  *(long *)(param_2 + 2) = *(long *)(param_2 + 2) + 1;
  return;
}


// ===== 00255f30 nvswitch_get_port_event =====

void nvswitch_get_port_event
               (undefined8 param_1,int *param_2,undefined8 *param_3,uint param_4,int *param_5)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  if (param_2 == (int *)0x0) {
    nvswitch_os_assert_log("NVSwitch: Assertion failed\n");
  }
  if (param_3 != (undefined8 *)0x0) {
    if (param_4 < (uint)param_2[1]) {
      puVar1 = (undefined8 *)
               (*(long *)(param_2 + 6) +
               ((ulong)(*param_2 + param_4) % (ulong)(uint)param_2[4]) * 0x28);
      *param_3 = *puVar1;
      param_3[1] = puVar1[1];
      param_3[2] = puVar1[2];
      param_3[3] = puVar1[3];
      param_3[4] = puVar1[4];
    }
    else {
      nvswitch_os_memset(param_3,0,0x28);
      *(undefined1 *)param_3 = 2;
      uVar2 = nvswitch_os_get_platform_time();
      param_3[4] = uVar2;
    }
  }
  if (param_5 != (int *)0x0) {
    *param_5 = param_2[1];
  }
  return;
}


// ===== 00256010 nvswitch_ctrl_get_port_events =====

undefined8 nvswitch_ctrl_get_port_events(long param_1,ulong *param_2)

{
  undefined8 *puVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  ulong uVar5;
  uint uVar6;
  uint local_54;
  undefined8 local_50;
  ulong local_48;
  undefined8 local_40;
  undefined8 local_38;
  ulong local_30;
  
  local_54 = 0;
  nvswitch_os_memset(param_2 + 3,0,0x400);
  uVar2 = *(ulong *)(param_1 + 0x150);
  *(undefined4 *)(param_2 + 2) = 0;
  param_2[1] = uVar2;
  *(undefined1 *)((long)param_2 + 0x14) = *(undefined1 *)(param_1 + 0x169);
  nvswitch_get_port_event(param_1,param_1 + 0x148,&local_50,0,&local_54);
  uVar3 = local_54;
  if (local_54 != 0) {
    if (local_48 < *param_2) {
      uVar6 = (int)*param_2 - (int)local_48;
      if (local_54 <= uVar6) {
        return 0;
      }
    }
    else {
      uVar6 = 0;
    }
    uVar4 = (uint)param_2[2];
    for (; (uVar4 < 0x40 && (uVar6 < uVar3)); uVar6 = uVar6 + 1) {
      if (uVar6 < *(uint *)(param_1 + 0x14c)) {
        puVar1 = (undefined8 *)
                 (*(long *)(param_1 + 0x160) +
                 ((ulong)(*(int *)(param_1 + 0x148) + uVar6) % (ulong)*(uint *)(param_1 + 0x158)) *
                 0x28);
        local_50 = *puVar1;
        local_48 = puVar1[1];
        local_40 = puVar1[2];
        local_38 = puVar1[3];
        local_30 = puVar1[4];
      }
      else {
        nvswitch_os_memset(&local_50,0,0x28);
        local_50 = CONCAT71(local_50._1_7_,2);
        local_30 = nvswitch_os_get_platform_time();
      }
      uVar2 = param_2[2];
      uVar5 = (ulong)(uint)uVar2;
      *(undefined1 *)(param_2 + uVar5 * 2 + 3) = (undefined1)local_50;
      uVar4 = (uint)uVar2 + 1;
      param_2[uVar5 * 2 + 4] = local_30;
      *(undefined4 *)((long)param_2 + uVar5 * 0x10 + 0x1c) = (undefined4)local_38;
      *(uint *)(param_2 + 2) = uVar4;
    }
    *param_2 = local_48 + 1;
  }
  return 0;
}


// ===== 002561b0 nvswitch_lib_get_log_count =====

undefined8
nvswitch_lib_get_log_count
          (long *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  long lVar1;
  
  if ((((param_1 != (long *)0x0) && (lVar1 = *param_1, *(long *)(lVar1 + 0xa8) == 3)) &&
      (*(long *)(lVar1 + 0x78) != 0)) &&
     (((*(char *)(lVar1 + 0xb0) != '\0' &&
       (param_2 != (undefined4 *)0x0 && param_3 != (undefined4 *)0x0)) &&
      (param_4 != (undefined4 *)0x0)))) {
    *param_2 = *(undefined4 *)((long)param_1 + 0xfc);
    *param_3 = *(undefined4 *)((long)param_1 + 0x124);
    *param_4 = *(undefined4 *)((long)param_1 + 0x14c);
    return 0;
  }
  return 0xffffffff;
}


// ===== 00256220 nvswitch_lib_load_platform_info =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_lib_load_platform_info(long *param_1)

{
  if (((param_1 != (long *)0x0) && (*(long *)(*param_1 + 0xa8) == 3)) &&
     (*(long *)(*param_1 + 0x78) != 0)) {
    (*(code *)param_1[0xa1])();
    return 0;
  }
  return 0xffffffff;
}


// ===== 00256260 nvswitch_lib_get_device_info =====

void nvswitch_lib_get_device_info(long *param_1,long *param_2)

{
  if (((param_1 != (long *)0x0) && (*(long *)(*param_1 + 0xa8) == 3)) && (param_2 != (long *)0x0)) {
    *param_2 = *param_1 + 0x40;
    return;
  }
  nvswitch_os_assert_log("NVSwitch: Assertion failed\n");
  return;
}


// ===== 002562a0 nvswitch_lib_get_bios_version =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_lib_get_bios_version(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 local_20 [2];
  
  local_20[0] = 0;
  if (param_1 == 0) {
    return 0xffffffff;
  }
  uVar1 = (**(code **)(param_1 + 0x808))(param_1,local_20);
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = local_20[0];
    return uVar1;
  }
  return uVar1;
}


// ===== 00256300 nvswitch_lib_use_pin_irq =====

undefined1 nvswitch_lib_use_pin_irq(long param_1)

{
  return *(undefined1 *)(param_1 + 0x26);
}


// ===== 00256310 nvswitch_lib_register_device =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvswitch_lib_register_device
              (uint param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,ushort param_5,
              long param_6,undefined4 param_7,undefined8 *param_8)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  int *piVar7;
  undefined8 uVar8;
  undefined4 local_3c [3];
  
  cVar1 = nvlink_lib_is_initialized();
  if (cVar1 == '\0') {
    return -5;
  }
  if ((param_8 == (undefined8 *)0x0) || (param_6 == 0)) {
    return -1;
  }
  *param_8 = 0;
  plVar4 = (long *)nvswitch_os_malloc_trace(0x1ff0,0,0);
  if (plVar4 == (long *)0x0) {
    return -2;
  }
  nvswitch_os_memset(plVar4,0,0x1ff0);
  nvswitch_os_snprintf(plVar4 + 1,0xb,"nvswitch%d",param_7);
  lVar5 = nvswitch_os_malloc_trace(0xd8,0,0);
  if (lVar5 == 0) {
    iVar2 = -2;
    goto LAB_00256513;
  }
  nvswitch_os_memset(lVar5,0,0xd8);
  lVar6 = nvswitch_os_malloc_trace(0x10,0,0);
  *(long *)(lVar5 + 0x28) = lVar6;
  if (lVar6 != 0) {
    nvswitch_os_memcpy(lVar6,"nvidia-nvswitch",0x10);
    *plVar4 = lVar5;
    plVar4[3] = param_6;
    *(undefined4 *)(plVar4 + 4) = param_7;
    *(long **)(lVar5 + 0x30) = plVar4 + 1;
    *(undefined8 *)(*plVar4 + 0x38) = 0;
    *(uint *)(*plVar4 + 0x40) = param_1 & 0xffff;
    *(undefined1 *)(*plVar4 + 0x44) = param_2;
    *(undefined1 *)(*plVar4 + 0x45) = param_3;
    *(undefined1 *)(*plVar4 + 0x46) = param_4;
    *(uint *)(*plVar4 + 0x48) = (uint)param_5;
    *(long **)(*plVar4 + 200) = plVar4;
    *(undefined8 *)(*plVar4 + 0xa8) = 3;
    plVar4[0x3f5] = 0x100002710;
    *(undefined4 *)(plVar4 + 0x3f8) = 0;
    plVar4[0x3f6] = 1;
    *(undefined4 *)((long)plVar4 + 0x1fec) = 0;
    piVar7 = &nvswitch_lr10_device_ids;
    do {
      if (*(int *)(*plVar4 + 0x48) == *piVar7) {
        nvswitch_setup_hal_lr10(plVar4);
        goto LAB_00256540;
      }
      piVar7 = piVar7 + 1;
    } while (piVar7 != (int *)&DAT_00cc9ba4);
    piVar7 = &nvswitch_ls10_device_ids;
LAB_002564e0:
    if (*(int *)(*plVar4 + 0x48) != *piVar7) goto code_r0x002564e4;
    nvswitch_setup_hal_ls10(plVar4);
LAB_00256540:
    *(undefined4 *)((long)plVar4 + 0x9c) = 0;
    iVar2 = nvswitch_os_read_registry_dword(plVar4[3],"ATOControl",local_3c);
    if (iVar2 == 0) {
      *(undefined4 *)((long)plVar4 + 0x9c) = local_3c[0];
    }
    *(undefined4 *)(plVar4 + 0x14) = 0;
    iVar2 = nvswitch_os_read_registry_dword(plVar4[3],"STOControl",local_3c);
    if (iVar2 == 0) {
      *(undefined4 *)(plVar4 + 0x14) = local_3c[0];
    }
    *(undefined4 *)(plVar4 + 0x19) = 0;
    iVar2 = nvswitch_os_read_registry_dword(plVar4[3],"CRCBitErrorRateShort",local_3c);
    if (iVar2 == 0) {
      *(undefined4 *)(plVar4 + 0x19) = local_3c[0];
    }
    *(undefined4 *)((long)plVar4 + 0xcc) = 0;
    iVar2 = nvswitch_os_read_registry_dword(plVar4[3],"CRCBitErrorRateLong",local_3c);
    if (iVar2 == 0) {
      *(undefined4 *)((long)plVar4 + 0xcc) = local_3c[0];
    }
    *(undefined4 *)(plVar4 + 0x1b) = 0;
    iVar2 = nvswitch_os_read_registry_dword(plVar4[3],"SurpressLinkErrorsForGpuReset",local_3c);
    if (iVar2 == 0) {
      *(undefined4 *)(plVar4 + 0x1b) = local_3c[0];
    }
    *(undefined4 *)((long)plVar4 + 0x74) = 1;
    iVar2 = nvswitch_os_read_registry_dword(plVar4[3],"CCIControl",local_3c);
    if (iVar2 == 0) {
      *(undefined4 *)((long)plVar4 + 0x74) = local_3c[0];
    }
    plVar4[0xf] = 0;
    *(undefined4 *)(plVar4 + 0x10) = 5;
    iVar2 = nvswitch_os_read_registry_dword(plVar4[3],"CCIMaxOnboardAttempts",local_3c);
    if (iVar2 == 0) {
      *(undefined4 *)(plVar4 + 0x10) = local_3c[0];
    }
    *(undefined4 *)((long)plVar4 + 0x84) = 1;
    iVar2 = nvswitch_os_read_registry_dword(plVar4[3],"CCIErrorLogEnable",local_3c);
    if (iVar2 == 0) {
      *(undefined4 *)((long)plVar4 + 0x84) = local_3c[0];
    }
    plVar4[5] = 1;
    plVar4[6] = 0x100000001;
    plVar4[7] = 0;
    uVar3 = (*(code *)plVar4[0xa6])(plVar4);
    *(undefined8 *)((long)plVar4 + 0x44) = 0xffffffffffffffff;
    *(undefined4 *)(plVar4 + 8) = uVar3;
    *(undefined8 *)((long)plVar4 + 0x4c) = 0;
    *(undefined8 *)((long)plVar4 + 0x54) = 0x100000000;
    iVar2 = nvswitch_os_read_registry_dword(plVar4[3],"EnablePM",local_3c);
    if (iVar2 == 0) {
      *(undefined4 *)(plVar4 + 0xb) = local_3c[0];
    }
    *(undefined8 *)((long)plVar4 + 0x5c) = 0;
    *(undefined8 *)((long)plVar4 + 100) = 1;
    plVar4[0x11] = 1;
    plVar4[0x12] = 0x25800000000;
    *(undefined4 *)(plVar4 + 0x13) = 0x1e;
    *(undefined4 *)((long)plVar4 + 0xa4) = 0;
    plVar4[0x15] = 0;
    plVar4[0x16] = 0;
    plVar4[0x17] = 0;
    plVar4[0x18] = 0;
    plVar4[0x1a] = 0;
    iVar2 = nvswitch_os_read_registry_dword(plVar4[3],"MINIONIntr",local_3c);
    if (iVar2 == 0) {
      *(undefined4 *)((long)plVar4 + 0xd4) = local_3c[0];
    }
    *(undefined4 *)((long)plVar4 + 0xdc) = 0;
    plVar4[0x1c] = 0x200000000;
    *(bool *)(*plVar4 + 0xb1) = (int)plVar4[0x17] == 2;
    iVar2 = nvlink_lib_register_device(*plVar4);
    if (iVar2 == 0) {
      *param_8 = plVar4;
      return 0;
    }
    uVar8 = *(undefined8 *)(lVar5 + 0x28);
    goto LAB_00256506;
  }
  iVar2 = -2;
  uVar8 = 0;
LAB_00256506:
  nvswitch_os_free(uVar8);
  nvswitch_os_free(lVar5);
LAB_00256513:
  nvswitch_os_free(plVar4);
  return iVar2;
code_r0x002564e4:
  piVar7 = piVar7 + 1;
  if (piVar7 == &nvswitch_lr10_device_ids) goto code_r0x002564ed;
  goto LAB_002564e0;
code_r0x002564ed:
  uVar8 = *(undefined8 *)(lVar5 + 0x28);
  iVar2 = -0xd;
  goto LAB_00256506;
}


// ===== 00256870 nvswitch_lib_unregister_device =====

void nvswitch_lib_unregister_device(long *param_1)

{
  if ((param_1 != (long *)0x0) && (*(long *)(*param_1 + 0xa8) == 3)) {
    nvlink_lib_unregister_device(*param_1);
    nvswitch_os_free(*(undefined8 *)(*param_1 + 0x28));
    nvswitch_os_free(*param_1);
    nvswitch_os_free(param_1);
    return;
  }
  nvswitch_os_assert_log("NVSwitch: Assertion failed\n");
  return;
}


// ===== 002568d0 nvswitch_lib_get_valid_ports_mask =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_lib_get_valid_ports_mask(long *param_1,uint *param_2)

{
  int iVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  
  if (((param_1 != (long *)0x0) && (*(long *)(*param_1 + 0xa8) == 3)) && (param_2 != (uint *)0x0)) {
    uVar4 = 0;
    uVar3 = 0;
    iVar1 = *(int *)((long)param_1 + 0xbc);
    do {
      uVar2 = (*(code *)param_1[0xcd])(param_1,uVar3);
      if ((iVar1 == 1) || ((uVar2 & 2) != 0)) {
        if ((uVar2 & 1) != 0) {
          uVar4 = uVar4 | 1 << (uVar3 & 0x1f);
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 != 4);
    *param_2 = uVar4;
    return 0;
  }
  return 0xffffffff;
}


// ===== 00256960 nvswitch_lib_is_i2c_supported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_lib_is_i2c_supported(long *param_1)

{
  undefined8 uVar1;
  
  if ((param_1 != (long *)0x0) && (*(long *)(*param_1 + 0xa8) == 3)) {
    uVar1 = (*(code *)param_1[0x140])();
    return uVar1;
  }
  nvswitch_os_assert_log("NVSwitch: Assertion failed\n");
  return 0;
}


// ===== 002569a0 nvswitch_lib_i2c_transfer =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
nvswitch_lib_i2c_transfer
          (long *param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,undefined1 param_5
          ,undefined4 param_6,undefined8 param_7)

{
  ulong uVar1;
  undefined8 uVar2;
  
  if ((param_1 != (long *)0x0) && (*(long *)(*param_1 + 0xa8) == 3)) {
    uVar1 = (*(code *)param_1[0xcd])();
    if (((*(int *)((long)param_1 + 0xbc) == 1) || ((uVar1 & 2) != 0)) && ((uVar1 & 1) != 0)) {
      uVar2 = _nvswitch_perform_i2c_transfer
                        (param_1,3,param_3,param_4,param_2,param_5,param_6,param_7);
    }
    else {
      uVar2 = 0xffffffff;
    }
    return uVar2;
  }
  nvswitch_os_assert_log("NVSwitch: Assertion failed\n");
  return 0xfffffff8;
}


// ===== 00256a70 nvswitch_timeout_create =====

void nvswitch_timeout_create(long param_1,long *param_2)

{
  long lVar1;
  
  lVar1 = nvswitch_os_get_platform_time();
  *param_2 = lVar1 + param_1;
  return;
}


// ===== 00256aa0 nvswitch_timeout_check =====

bool nvswitch_timeout_check(ulong *param_1)

{
  ulong uVar1;
  
  uVar1 = nvswitch_os_get_platform_time();
  return *param_1 <= uVar1;
}


// ===== 00256ad0 nvswitch_task_create =====

undefined8
nvswitch_task_create(long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  puVar2 = (undefined8 *)nvswitch_os_malloc_trace(0x40,0,0);
  if (puVar2 == (undefined8 *)0x0) {
    uVar3 = 0xfffffffe;
  }
  else {
    puVar2[3] = param_2;
    puVar2[4] = 0;
    puVar2[5] = param_3;
    uVar3 = nvswitch_os_get_platform_time();
    *(undefined4 *)(puVar2 + 7) = param_4;
    puVar2[6] = uVar3;
    *puVar2 = 0;
    puVar1 = *(undefined8 **)(param_1 + 0xe8);
    puVar2[1] = puVar1;
    if (puVar1 != (undefined8 *)0x0) {
      *puVar1 = puVar2;
    }
    *(undefined8 **)(param_1 + 0xe8) = puVar2;
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 00256b80 nvswitch_task_create_args =====

undefined8
nvswitch_task_create_args
          (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,uint param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  puVar2 = (undefined8 *)nvswitch_os_malloc_trace(0x40,0,0);
  if (puVar2 == (undefined8 *)0x0) {
    uVar3 = 0xfffffffe;
  }
  else {
    puVar2[2] = param_3;
    puVar2[4] = param_2;
    puVar2[5] = param_4;
    uVar3 = nvswitch_os_get_platform_time();
    *(uint *)(puVar2 + 7) = param_5 | 4;
    puVar2[6] = uVar3;
    *puVar2 = 0;
    puVar1 = *(undefined8 **)(param_1 + 0xe8);
    puVar2[1] = puVar1;
    if (puVar1 != (undefined8 *)0x0) {
      *puVar1 = puVar2;
    }
    *(undefined8 **)(param_1 + 0xe8) = puVar2;
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 00256c30 nvswitch_destroy_device_state =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_destroy_device_state(long param_1)

{
  (**(code **)(param_1 + 0x500))();
  return;
}


// ===== 00256c40 nvswitch_set_nport_port_config =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_set_nport_port_config(long param_1)

{
  (**(code **)(param_1 + 0x5c0))();
  return;
}


// ===== 00256c50 nvswitch_init_npg_multicast =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_init_npg_multicast(long param_1)

{
  (**(code **)(param_1 + 0x5f8))();
  return;
}


// ===== 00256c60 nvswitch_init_warm_reset =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_init_warm_reset(long param_1)

{
  (**(code **)(param_1 + 0x600))();
  return;
}


// ===== 00256c70 nvswitch_ctrl_i2c_indexed =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_ctrl_i2c_indexed(long param_1)

{
  (**(code **)(param_1 + 0x680))();
  return;
}


// ===== 00256c80 nvswitch_ctrl_set_latency_bins =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_ctrl_set_latency_bins(long param_1)

{
  (**(code **)(param_1 + 0x658))();
  return;
}


// ===== 00256c90 nvswitch_ctrl_get_throughput_counters =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_ctrl_get_throughput_counters(long param_1)

{
  (**(code **)(param_1 + 0x698))();
  return;
}


// ===== 00256ca0 nvswitch_does_link_need_termination_enabled =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_does_link_need_termination_enabled(long param_1)

{
  (**(code **)(param_1 + 0xad8))();
  return;
}


// ===== 00256cb0 nvswitch_link_termination_setup =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_link_termination_setup(long param_1)

{
  (**(code **)(param_1 + 0xae0))();
  return;
}


// ===== 00256cc0 nvswitch_inband_read_data =====

undefined8
nvswitch_inband_read_data(long param_1,undefined8 param_2,uint param_3,undefined4 *param_4)

{
  long *plVar1;
  long lVar2;
  long *plVar3;
  
  lVar2 = ((ulong)param_3 + 0x3e) * 0x40;
  plVar1 = (long *)(param_1 + lVar2);
  plVar3 = plVar1;
  if ((*(long **)(param_1 + 0xf80 + (ulong)param_3 * 0x40) == plVar1) &&
     (plVar3 = (long *)(param_1 + 0x10 + lVar2), plVar3 == (long *)plVar1[2])) {
    *param_4 = 0;
    return 0xfffffffd;
  }
  plVar1 = (long *)*plVar3;
  if (plVar1 != plVar3) {
    *param_4 = *(undefined4 *)(plVar1 + 0x282);
    nvswitch_os_memcpy(param_2,plVar1 + 2);
    plVar3 = (long *)plVar1[1];
    lVar2 = *plVar1;
    *(long **)(lVar2 + 8) = plVar3;
    *plVar3 = lVar2;
    plVar1[1] = (long)plVar1;
    *plVar1 = (long)plVar1;
    nvswitch_os_free(plVar1);
    return 0;
  }
  return 0;
}


// ===== 00256d60 nvswitch_filter_messages =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_filter_messages(long *param_1,uint param_2)

{
  long *plVar1;
  long lVar2;
  short sVar3;
  uint uVar4;
  long *plVar5;
  long *plVar6;
  uint uVar7;
  ulong uVar8;
  
  uVar8 = (ulong)param_2;
  plVar1 = (long *)param_1[uVar8 * 8 + 0x1ef];
  if ((*(long *)(*param_1 + 0xa8) == 3) && (*(long *)(*param_1 + 0x78) != 0)) {
    sVar3 = *(short *)((long)plVar1 + 0x1e);
    if (sVar3 == 4) goto LAB_00256e80;
    if (*(int *)((long)param_1 + 0x1fac) != 2) goto LAB_00256dc4;
    lVar2 = param_1[uVar8 * 8 + 0x1f2];
    *(long **)(lVar2 + 8) = plVar1;
    *plVar1 = lVar2;
    plVar1[1] = (long)(param_1 + uVar8 * 8 + 0x1f2);
    param_1[uVar8 * 8 + 0x1f2] = (long)plVar1;
LAB_00256e22:
    nvswitch_lib_notify_client_events(param_1,5);
    goto LAB_00256dd8;
  }
  nvswitch_os_assert_log("NVSwitch: Assertion failed\n");
  sVar3 = *(short *)((long)plVar1 + 0x1e);
  if (sVar3 == 4) {
LAB_00256e80:
    plVar5 = (long *)param_1[uVar8 * 8 + 0x1f0];
    plVar6 = param_1 + (uVar8 + 0x3e) * 8;
    if (plVar6 == plVar5) {
      uVar7 = 0;
    }
    else {
      uVar7 = 0;
      do {
        plVar5 = (long *)*plVar5;
        uVar7 = uVar7 + 1;
      } while (plVar6 != plVar5);
    }
    uVar4 = (*(code *)param_1[0x19b])(param_1);
    if (uVar7 < uVar4) {
      lVar2 = param_1[uVar8 * 8 + 0x1f0];
      *(long **)(lVar2 + 8) = plVar1;
      *plVar1 = lVar2;
      plVar1[1] = (long)plVar6;
      param_1[uVar8 * 8 + 0x1f0] = (long)plVar1;
      goto LAB_00256e22;
    }
    sVar3 = *(short *)((long)plVar1 + 0x1e);
    if (sVar3 != 2) goto LAB_00256dca;
LAB_00256e38:
    (*(code *)param_1[0x19a])(param_1,plVar1 + 2,param_2);
  }
  else {
LAB_00256dc4:
    if (sVar3 == 2) goto LAB_00256e38;
LAB_00256dca:
    if (sVar3 == 5) goto LAB_00256e38;
  }
  nvswitch_os_free(plVar1);
LAB_00256dd8:
  param_1[uVar8 * 8 + 0x1ef] = 0;
  return;
}


// ===== 00256f40 nvswitch_create_link =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_create_link(undefined8 *param_1,ulong param_2,long *param_3)

{
  undefined8 uVar1;
  uint uVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  
  uVar2 = (*(code *)param_1[0xa2])();
  if (100 < uVar2) {
    nvswitch_os_assert_log("NVSwitch: Assertion failed\n");
  }
  lVar4 = nvswitch_os_malloc_trace(0xe0,0,0);
  if (lVar4 == 0) {
    return 0xfffffffe;
  }
  nvswitch_os_memset(lVar4,0,0xe0);
  lVar5 = nvswitch_os_malloc_trace(7,0,0);
  if (lVar5 == 0) {
    nvswitch_os_free(lVar4);
    return 0xfffffffe;
  }
  nvswitch_os_memset(lVar5,0,7);
  nvswitch_os_snprintf(lVar5,7,"link%d",param_2 & 0xffffffff);
  uVar1 = *param_1;
  *(long *)(lVar4 + 0x30) = lVar5;
  *(int *)(lVar4 + 0x38) = (int)param_2;
  *(undefined8 *)(lVar4 + 0x10) = uVar1;
  *(undefined4 *)(lVar4 + 0x48) = 0;
  *(undefined1 *)(lVar4 + 0x68) = 0;
  uVar3 = (*(code *)param_1[0xe2])(param_1,param_2 & 0xffffffff);
  *(undefined4 *)(lVar4 + 0x5c) = uVar3;
  uVar6 = param_1[7];
  if (uVar6 == 0) {
    if (*(char *)(param_1 + 0x42) == '\0') goto LAB_00257041;
    uVar6 = param_1[0x44];
  }
  if ((uVar6 >> (param_2 & 0x3f) & 1) != 0) {
    *(undefined1 *)(lVar4 + 0x68) = 1;
  }
LAB_00257041:
  link_handlers._160_8_ = _nvswitch_corelib_ali_training;
  link_handlers._152_8_ = _nvswitch_corelib_get_cci_link_mode;
  link_handlers._144_8_ = _nvswitch_corelib_get_uphy_load;
  *(long *)(lVar4 + 0x98) = lVar5;
  *(undefined1 **)(lVar4 + 0x90) = link_handlers;
  link_handlers._0_8_ = _nvswitch_corelib_add_link;
  link_handlers._8_8_ = _nvswitch_corelib_remove_link;
  link_handlers._40_8_ = _nvswitch_corelib_set_dl_link_mode;
  link_handlers._48_8_ = _nvswitch_corelib_get_dl_link_mode;
  link_handlers._56_8_ = _nvswitch_corelib_set_tl_link_mode;
  link_handlers._64_8_ = _nvswitch_corelib_get_tl_link_mode;
  link_handlers._72_8_ = _nvswitch_corelib_set_tx_mode;
  link_handlers._80_8_ = _nvswitch_corelib_get_tx_mode;
  link_handlers._88_8_ = _nvswitch_corelib_set_rx_mode;
  link_handlers._96_8_ = _nvswitch_corelib_get_rx_mode;
  link_handlers._104_8_ = _nvswitch_corelib_set_rx_detect;
  link_handlers._112_8_ = _nvswitch_corelib_get_rx_detect;
  link_handlers._136_8_ = _nvswitch_corelib_training_complete;
  link_handlers._120_8_ = _nvswitch_corelib_write_discovery_token;
  link_handlers._128_8_ = _nvswitch_corelib_read_discovery_token;
  *param_3 = lVar4;
  return 0;
}


// ===== 00257170 nvswitch_lib_initialize_device =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvswitch_lib_initialize_device(long *param_1)

{
  long lVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  byte bVar10;
  ulong uVar11;
  uint uVar12;
  uint uVar13;
  long local_40 [2];
  
  local_40[0] = 0;
  if (((param_1 == (long *)0x0) || (lVar8 = *param_1, *(long *)(lVar8 + 0xa8) != 3)) ||
     (*(long *)(lVar8 + 0x78) == 0)) {
    return -1;
  }
  uVar11 = 0;
  if (*(char *)(lVar8 + 0xb0) != '\0') {
    return 0;
  }
  param_1[0x3fc] = (long)(param_1 + 0x3fb);
  param_1[0x3fb] = (long)(param_1 + 0x3fb);
  while( true ) {
    uVar13 = (*(code *)param_1[0xa2])(param_1);
    uVar7 = uVar11 & 0xff;
    if (uVar13 <= (uint)uVar7) break;
    uVar9 = uVar11 & 0xff;
    uVar11 = (ulong)((int)uVar11 + 1);
    param_1[uVar7 * 8 + 0x1f1] = (long)(param_1 + (uVar9 + 0x3e) * 8);
    param_1[uVar7 * 8 + 0x1f0] = (long)(param_1 + (uVar9 + 0x3e) * 8);
    param_1[uVar9 * 8 + 499] = (long)(param_1 + (uVar9 + 0x3e) * 8 + 2);
    param_1[uVar9 * 8 + 0x1f2] = (long)(param_1 + (uVar9 + 0x3e) * 8 + 2);
  }
  if (*(long *)(*param_1 + 0xa8) != 3) {
    return -1;
  }
  if (*(long *)(*param_1 + 0x78) == 0) {
    return -1;
  }
  (*(code *)param_1[0xa1])(param_1);
  cVar2 = (*(code *)param_1[0xe5])(param_1);
  if (cVar2 != '\0') {
    lVar8 = soeAllocNew();
    param_1[0x1a4] = lVar8;
    if (lVar8 == 0) {
      return -2;
    }
    iVar4 = soeInit(param_1,lVar8,*(undefined4 *)(*param_1 + 0x48));
    if (iVar4 != 0) {
LAB_002572b4:
      nvswitch_os_free(lVar8);
      param_1[0x1a4] = 0;
      return iVar4;
    }
    iVar4 = flcnableConstruct_HAL(param_1,lVar8);
    if (iVar4 != 0) {
      iVar4 = -8;
      soeDestroy(param_1,lVar8);
      goto LAB_002572b4;
    }
  }
  cVar2 = nvswitch_is_cci_supported(param_1);
  if (cVar2 != '\0') {
    lVar8 = cciAllocNew();
    param_1[0x1a5] = lVar8;
    if (lVar8 == 0) {
      iVar4 = -2;
      goto LAB_002575ee;
    }
    iVar4 = cciInit(param_1,lVar8,*(undefined4 *)(*param_1 + 0x48));
    if (iVar4 != 0) {
      nvswitch_os_free(lVar8);
      param_1[0x1a5] = 0;
      goto LAB_002575ee;
    }
  }
  iVar4 = (*(code *)param_1[0xe1])(param_1);
  if (iVar4 != 0) {
    iVar5 = nvswitch_os_set_dma_mask(param_1[3],iVar4);
    if (iVar5 == 0) {
      *(int *)(param_1 + 0x1e7) = iVar4;
    }
    else {
      iVar4 = nvswitch_os_set_dma_mask(param_1[3],0x20);
      if (iVar4 == 0) {
        *(undefined4 *)(param_1 + 0x1e7) = 0x20;
      }
    }
  }
  iVar4 = (*(code *)param_1[0x9f])(param_1);
  if (iVar4 == 0) {
    (*(code *)param_1[0xff])(param_1);
    cVar2 = nvswitch_os_is_uuid_in_blacklist(param_1 + 0x3f3);
    cVar3 = (*(code *)param_1[0xe7])(param_1);
    if (cVar3 == '\0') {
LAB_002573b2:
      (*(code *)param_1[0x103])(param_1);
      (*(code *)param_1[0x104])(param_1);
      cVar3 = (*(code *)param_1[0x174])(param_1);
      if (cVar3 == '\0') {
        nvswitch_task_create(param_1,nvswitch_fabric_state_heartbeat,1000000000,1);
      }
      if (*(int *)((long)param_1 + 0x1fb4) == 1) {
        return 0;
      }
      uVar13 = 0;
      if (cVar2 == '\x01') {
        if (*(long *)(*param_1 + 0xa8) != 3) {
          return 0;
        }
        if (*(long *)(*param_1 + 0x78) != 0) {
          if ((int)param_1[0x3f6] != 3) {
            param_1[0x3f6] = 0x200000003;
            (*(code *)param_1[0x104])(param_1);
            return 0;
          }
          return 0;
        }
        return 0;
      }
      while( true ) {
        uVar12 = uVar13 & 0xff;
        uVar6 = (*(code *)param_1[0xa2])(param_1);
        bVar10 = 0;
        if (uVar6 <= uVar12) break;
        cVar2 = (*(code *)param_1[0xa4])(param_1,uVar12);
        if (cVar2 != '\0') {
          iVar4 = nvswitch_create_link(param_1,uVar12,local_40);
          if (iVar4 != 0) {
            iVar4 = -2;
            goto LAB_0025770a;
          }
          iVar4 = nvlink_lib_register_link(*param_1,local_40[0]);
          lVar8 = local_40[0];
          if (iVar4 != 0) {
            if (*(long *)(local_40[0] + 0x98) != 0) {
              nvswitch_os_free();
            }
            nvswitch_os_free(lVar8);
            goto LAB_0025770a;
          }
          (*(code *)param_1[0x143])(param_1,uVar12);
          (*(code *)param_1[0x146])(param_1,uVar12);
          (**(code **)(*(long *)(*(long *)(local_40[0] + 0x10) + 200) + 0xa28))();
        }
        uVar13 = uVar13 + 1;
      }
      iVar4 = (*(code *)param_1[0x147])(param_1);
      if (iVar4 == 0) {
        (*(code *)param_1[0x11d])(param_1);
        iVar4 = nvswitch_construct_error_log(param_1 + 0x1f,0x400,0);
        if ((iVar4 == 0) &&
           (iVar4 = nvswitch_construct_error_log(param_1 + 0x24,0x400,1), iVar4 == 0)) {
          iVar4 = _nvswitch_construct_port_event_log(param_1 + 0x29,0x400,1);
          if (iVar4 == 0) {
            if (((int)param_1[0x11] == 1) &&
               (cVar2 = (*(code *)param_1[0x174])(param_1), cVar2 == '\0')) {
              uVar13 = (*(code *)param_1[0xa7])(param_1);
              nvswitch_task_create
                        (param_1,nvswitch_internal_latency_bin_log,(ulong)uVar13 * 900000,0);
            }
            cVar2 = (*(code *)param_1[0x174])(param_1);
            if (cVar2 == '\0') {
              nvswitch_task_create(param_1,nvswitch_ecc_writeback_task,60000000000,0);
            }
            if ((((*(char *)((long)param_1 + 0x25) == '\0') &&
                 (*(char *)((long)param_1 + 0x24) == '\0')) &&
                (*(char *)((long)param_1 + 0x26) == '\0')) &&
               (cVar2 = (*(code *)param_1[0x174])(param_1), cVar2 == '\0')) {
              nvswitch_task_create(param_1,nvswitch_monitor_thermal_alert,100000000,0);
            }
            *(undefined1 *)(*param_1 + 0xb0) = 1;
            return 0;
          }
          iVar4 = -2;
        }
        else {
          nvswitch_destroy_error_log(param_1,param_1 + 0x1f);
          nvswitch_destroy_error_log(param_1,param_1 + 0x24);
        }
        *(undefined1 *)((long)param_1 + 0x169) = 0;
        param_1[0x29] = 0;
        *(undefined4 *)(param_1 + 0x2b) = 0;
        if (param_1[0x2c] != 0) {
          nvswitch_os_free();
          param_1[0x2c] = 0;
        }
      }
LAB_0025770a:
      while( true ) {
        uVar13 = (*(code *)param_1[0xa2])(param_1);
        if (uVar13 <= bVar10) break;
        iVar5 = nvlink_lib_get_link(*param_1,(uint)bVar10,local_40);
        if (iVar5 == 0) {
          nvlink_lib_unregister_link(local_40[0]);
          lVar8 = local_40[0];
          if (*(long *)(local_40[0] + 0x98) != 0) {
            nvswitch_os_free();
          }
          nvswitch_os_free(lVar8);
        }
        bVar10 = bVar10 + 1;
      }
      nvswitch_destroy_inforom_objects(param_1);
    }
    else {
      iVar4 = nvswitch_initialize_inforom(param_1);
      if (iVar4 != 0) goto LAB_002575c4;
      iVar4 = nvswitch_initialize_inforom_objects(param_1);
      if (iVar4 == 0) goto LAB_002573b2;
    }
    nvswitch_destroy_inforom(param_1);
  }
LAB_002575c4:
  lVar8 = param_1[0x1a5];
  if (lVar8 != 0) {
    cciDestroy(param_1,lVar8);
    nvswitch_os_free(lVar8);
    param_1[0x1a5] = 0;
  }
LAB_002575ee:
  lVar8 = param_1[0x1a4];
  if (lVar8 != 0) {
    flcnableDestruct_HAL(param_1,lVar8);
    soeDestroy(param_1,lVar8);
    nvswitch_os_free(lVar8);
    param_1[0x1a4] = 0;
  }
  lVar8 = param_1[0x1d];
  param_1[0x1d] = 0;
  while (lVar8 != 0) {
    lVar1 = *(long *)(lVar8 + 8);
    nvswitch_os_free(lVar8);
    lVar8 = lVar1;
  }
  return iVar4;
}


// ===== 00257960 nvswitch_destroy_link =====

void nvswitch_destroy_link(long param_1)

{
  if (*(long *)(param_1 + 0x98) != 0) {
    nvswitch_os_free();
    nvswitch_os_free(param_1);
    return;
  }
  nvswitch_os_free(param_1);
  return;
}


// ===== 002579a0 nvswitch_get_num_links =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_get_num_links(long param_1)

{
  (**(code **)(param_1 + 0x510))();
  return;
}


// ===== 002579b0 nvswitch_is_link_valid =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_is_link_valid(long param_1)

{
  (**(code **)(param_1 + 0x520))();
  return;
}


// ===== 002579c0 nvswitch_get_link =====

undefined8 nvswitch_get_link(undefined8 *param_1,undefined1 param_2)

{
  undefined8 local_10;
  
  local_10 = 0;
  nvlink_lib_get_link(*param_1,param_2,&local_10);
  return local_10;
}


// ===== 002579f0 nvswitch_get_enabled_link_mask =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong nvswitch_get_enabled_link_mask(undefined8 *param_1)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  undefined1 local_30 [16];
  
  uVar4 = 0;
  uVar3 = 0;
  while( true ) {
    uVar2 = (*(code *)param_1[0xa2])(param_1);
    if (uVar2 <= (uint)uVar3) break;
    iVar1 = nvlink_lib_get_link(*param_1,uVar3,local_30);
    if (iVar1 == 0) {
      uVar4 = uVar4 | 1L << (uVar3 & 0x3f);
    }
    uVar3 = (ulong)((uint)uVar3 + 1);
  }
  return uVar4;
}


// ===== 00257a60 nvswitch_fabric_state_heartbeat =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

void nvswitch_fabric_state_heartbeat(long *param_1)

{
  long *plVar1;
  char cVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  long *plVar6;
  ulong uVar7;
  long *plVar8;
  bool bVar9;
  
  if ((param_1 == (long *)0x0) || (*(long *)(*param_1 + 0xa8) != 3)) {
    return;
  }
  lVar4 = nvswitch_os_get_platform_time();
  if (*(int *)((long)param_1 + 0x1fac) == 2) {
    if ((ulong)(lVar4 - param_1[0x3f7]) <= (ulong)*(uint *)(param_1 + 0x3f5) * 1000000)
    goto LAB_00257be8;
    *(undefined4 *)((long)param_1 + 0x1fac) = 3;
  }
  uVar7 = 0;
  while( true ) {
    uVar3 = (*(code *)param_1[0xa2])(param_1);
    if (uVar3 <= (uint)uVar7) break;
    cVar2 = (*(code *)param_1[0xa4])(param_1,uVar7);
    if (cVar2 != '\0') {
      uVar5 = nvswitch_get_enabled_link_mask(param_1);
      cVar2 = (*(code *)param_1[0xa4])(param_1,uVar7);
      if ((cVar2 != '\0') && ((uVar5 >> (uVar7 & 0x3f) & 1) != 0)) {
        plVar6 = (long *)param_1[uVar7 * 8 + 0x1f2];
        if (param_1 + uVar7 * 8 + 0x1f2 != plVar6) {
          plVar8 = (long *)*plVar6;
          do {
            if ((*(short *)((long)plVar6 + 0x1e) == 2) || (*(short *)((long)plVar6 + 0x1e) == 5)) {
              (*(code *)param_1[0x19a])(param_1,plVar6 + 2,uVar7,plVar6,(code *)param_1[0x19a]);
            }
            plVar1 = (long *)plVar6[1];
            lVar4 = *plVar6;
            *(long **)(lVar4 + 8) = plVar1;
            *plVar1 = lVar4;
            plVar6[1] = (long)plVar6;
            *plVar6 = (long)plVar6;
            nvswitch_os_free(plVar6);
            bVar9 = plVar8 != param_1 + uVar7 * 8 + 0x1f2;
            plVar6 = plVar8;
            plVar8 = (long *)*plVar8;
          } while (bVar9);
        }
      }
    }
    uVar7 = (ulong)((uint)uVar7 + 1);
  }
LAB_00257be8:
  (*(code *)param_1[0x104])(param_1);
  return;
}


// ===== 00257c10 nvswitch_lib_post_init_device =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvswitch_lib_post_init_device(long *param_1)

{
  long lVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  uint uVar6;
  ulong uVar7;
  long local_38;
  long local_30 [2];
  
  if ((((param_1 == (long *)0x0) || (lVar1 = *param_1, *(long *)(lVar1 + 0xa8) != 3)) ||
      (*(long *)(lVar1 + 0x78) == 0)) || (*(char *)(lVar1 + 0xb0) == '\0')) {
    iVar3 = -8;
  }
  else {
    iVar3 = (*(code *)param_1[0xec])();
    if ((iVar3 == 0) &&
       ((cVar2 = (*(code *)param_1[0xe9])(param_1), cVar2 == '\0' ||
        ((iVar3 = nvswitch_bios_get_image(param_1), iVar3 == 0 &&
         (iVar3 = (*(code *)param_1[0x14a])(param_1), iVar3 == 0)))))) {
      cVar2 = nvswitch_is_cci_supported(param_1);
      if (cVar2 != '\0') {
        iVar3 = cciLoad(param_1);
        if (iVar3 != 0) {
          return iVar3;
        }
        uVar5 = nvswitch_get_enabled_link_mask(param_1);
        if (uVar5 != 0) {
          iVar3 = 0;
          uVar7 = uVar5;
          while( true ) {
            for (; (uVar5 & 1) == 0; uVar5 = uVar5 >> 1) {
              iVar3 = iVar3 + 1;
            }
            cVar2 = cciIsLinkManaged(param_1,iVar3);
            if (cVar2 != '\0') {
              uVar7 = ~(1L << ((byte)iVar3 & 0x3f)) & uVar7;
            }
            uVar5 = uVar5 >> 1;
            if (uVar5 == 0) break;
            iVar3 = iVar3 + 1;
          }
          if (uVar7 != 0) {
            nvswitch_task_create(param_1,_nvswitch_update_link_state_led,1000000000,0);
          }
        }
      }
      iVar3 = (*(code *)param_1[0xee])(param_1);
      if (iVar3 == 0) {
        nvswitch_smbpbi_post_init(param_1);
        if (((*(char *)((long)param_1 + 0x25) != '\0') || (*(char *)((long)param_1 + 0x24) != '\0'))
           || (*(char *)((long)param_1 + 0x26) != '\0')) {
          (*(code *)param_1[0x196])(param_1);
        }
        for (uVar6 = 0; uVar4 = (*(code *)param_1[0xa2])(param_1), uVar6 < uVar4; uVar6 = uVar6 + 1)
        {
          cVar2 = (*(code *)param_1[0xa4])(param_1,uVar6);
          if ((((cVar2 != '\0') && (cVar2 = cciIsLinkManaged(param_1,uVar6), cVar2 == '\0')) &&
              (iVar3 = nvlink_lib_get_link(*param_1,uVar6,local_30), iVar3 == 0)) &&
             ((iVar3 = (**(code **)(*(long *)(*(long *)(local_30[0] + 0x10) + 200) + 0x6b8))
                                 (local_30[0],&local_38), iVar3 == 0 && (local_38 == 3)))) {
            (*(code *)param_1[0x1a3])(param_1,local_30[0]);
          }
        }
        return 0;
      }
    }
  }
  return iVar3;
}


// ===== 00257e90 _nvswitch_ctrl_inband_flush_data.part.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_ctrl_inband_flush_data_part_0(long param_1,ulong *param_2)

{
  undefined8 *puVar1;
  char cVar2;
  ulong uVar3;
  ulong uVar4;
  uint uVar5;
  ulong uVar6;
  long *plVar7;
  long *plVar8;
  ulong uVar9;
  long *plVar10;
  bool bVar11;
  
  uVar3 = nvswitch_get_enabled_link_mask();
  uVar9 = *param_2;
  if (uVar9 == 0) {
    return;
  }
  uVar6 = 0;
  plVar8 = (long *)(param_1 + 0xf80);
  do {
    uVar5 = (uint)uVar6;
    while ((uVar9 & 1) != 0) {
      cVar2 = (**(code **)(param_1 + 0x520))(param_1,uVar6);
      if ((cVar2 != '\0') && ((uVar3 >> (uVar6 & 0x3f) & 1) != 0)) {
        uVar4 = nvswitch_get_enabled_link_mask(param_1);
        cVar2 = (**(code **)(param_1 + 0x520))(param_1,uVar6);
        if ((cVar2 != '\0') && ((uVar4 >> (uVar6 & 0x3f) & 1) != 0)) {
          plVar7 = (long *)plVar8[2];
          if (plVar8 + 2 != plVar7) {
            plVar10 = (long *)*plVar7;
            do {
              puVar1 = (undefined8 *)plVar7[1];
              plVar10[1] = (long)puVar1;
              *puVar1 = plVar10;
              plVar7[1] = (long)plVar7;
              *plVar7 = (long)plVar7;
              nvswitch_os_free();
              bVar11 = plVar10 != plVar8 + 2;
              plVar7 = plVar10;
              plVar10 = (long *)*plVar10;
            } while (bVar11);
          }
          plVar7 = (long *)*plVar8;
          if (plVar7 != plVar8) {
            plVar10 = (long *)*plVar7;
            do {
              puVar1 = (undefined8 *)plVar7[1];
              plVar10[1] = (long)puVar1;
              *puVar1 = plVar10;
              plVar7[1] = (long)plVar7;
              *plVar7 = (long)plVar7;
              nvswitch_os_free();
              bVar11 = plVar10 != plVar8;
              plVar7 = plVar10;
              plVar10 = (long *)*plVar10;
            } while (bVar11);
          }
        }
      }
      uVar9 = uVar9 >> 1;
      if (uVar9 == 0) {
        return;
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulong)uVar5;
      plVar8 = plVar8 + 8;
    }
    uVar6 = (ulong)(uVar5 + 1);
    uVar9 = uVar9 >> 1;
    plVar8 = plVar8 + 8;
  } while( true );
}


// ===== 00257fe0 nvswitch_lib_shutdown_device =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_lib_shutdown_device(long *param_1)

{
  long lVar1;
  undefined8 *puVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  bool bVar6;
  long local_30 [2];
  
  if (((param_1 != (long *)0x0) && (*(long *)(*param_1 + 0xa8) == 3)) &&
     (*(long *)(*param_1 + 0x78) != 0)) {
    if ((int)param_1[0x3f6] != 3) {
      *(undefined4 *)(param_1 + 0x3f6) = 0;
    }
    *(undefined4 *)((long)param_1 + 0x1fac) = 0;
    (*(code *)param_1[0x104])();
    (*(code *)param_1[0xab])(param_1);
    local_30[0] = nvswitch_get_enabled_link_mask(param_1);
    if (local_30[0] != 0) {
      _nvswitch_ctrl_inband_flush_data_part_0(param_1,local_30);
    }
    lVar1 = param_1[0x1a5];
    if (lVar1 != 0) {
      cciDestroy(param_1,lVar1);
      nvswitch_os_free(lVar1);
      param_1[0x1a5] = 0;
    }
    (*(code *)param_1[0x195])(param_1);
    _nvswitch_unregister_links(param_1);
    nvswitch_destroy_error_log(param_1,param_1 + 0x1f);
    nvswitch_destroy_error_log(param_1,param_1 + 0x24);
    param_1[0x29] = 0;
    *(undefined4 *)(param_1 + 0x2b) = 0;
    *(undefined1 *)((long)param_1 + 0x169) = 0;
    if (param_1[0x2c] != 0) {
      nvswitch_os_free();
      param_1[0x2c] = 0;
    }
    nvswitch_smbpbi_unload(param_1);
    plVar4 = (long *)param_1[0x3fb];
    if (plVar4 != param_1 + 0x3fb) {
      plVar5 = (long *)*plVar4;
      do {
        puVar2 = (undefined8 *)plVar4[1];
        plVar5[1] = (long)puVar2;
        *puVar2 = plVar5;
        plVar4[1] = (long)plVar4;
        *plVar4 = (long)plVar4;
        nvswitch_os_free();
        bVar6 = plVar5 != param_1 + 0x3fb;
        plVar4 = plVar5;
        plVar5 = (long *)*plVar5;
      } while (bVar6);
    }
    nvswitch_destroy_inforom_objects(param_1);
    nvswitch_destroy_inforom(param_1);
    nvswitch_smbpbi_destroy(param_1);
    (*(code *)param_1[0xa0])(param_1);
    if (param_1[0x3fa] != 0) {
      nvswitch_os_free();
      param_1[0x3fa] = 0;
    }
    lVar1 = param_1[0x1a4];
    if (lVar1 != 0) {
      flcnableDestruct_HAL(param_1,lVar1);
      soeDestroy(param_1,lVar1);
      nvswitch_os_free(lVar1);
      param_1[0x1a4] = 0;
    }
    lVar1 = param_1[0x1d];
    param_1[0x1d] = 0;
    while (lVar1 != 0) {
      lVar3 = *(long *)(lVar1 + 8);
      nvswitch_os_free(lVar1);
      lVar1 = lVar3;
    }
    return 0;
  }
  return 0xffffffff;
}


// ===== 00258220 nvswitch_set_fatal_error =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_set_fatal_error(long param_1,undefined1 param_2)

{
  (**(code **)(param_1 + 0x528))(param_1,param_2);
  return;
}


// ===== 00258240 nvswitch_get_rom_info =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_get_rom_info(long param_1)

{
  (**(code **)(param_1 + 0x560))();
  return;
}


// ===== 00258250 nvswitch_lib_enable_interrupts =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_lib_enable_interrupts(long *param_1)

{
  if (((param_1 != (long *)0x0) && (*(long *)(*param_1 + 0xa8) == 3)) &&
     (*(long *)(*param_1 + 0x78) != 0)) {
    (*(code *)param_1[0xad])();
    return;
  }
  nvswitch_os_assert_log("NVSwitch: Assertion failed\n");
  return;
}


// ===== 00258290 nvswitch_lib_disable_interrupts =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_lib_disable_interrupts(long *param_1)

{
  if (((param_1 != (long *)0x0) && (*(long *)(*param_1 + 0xa8) == 3)) &&
     (*(long *)(*param_1 + 0x78) != 0)) {
    (*(code *)param_1[0xae])();
    return;
  }
  nvswitch_os_assert_log("NVSwitch: Assertion failed\n");
  return;
}


// ===== 002582d0 nvswitch_lib_check_interrupts =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_lib_check_interrupts(long *param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  if ((((param_1 != (long *)0x0) && (lVar1 = *param_1, *(long *)(lVar1 + 0xa8) == 3)) &&
      (*(long *)(lVar1 + 0x78) != 0)) && (*(char *)(lVar1 + 0xb0) != '\0')) {
    uVar2 = (*(code *)param_1[0xaf])();
    return uVar2;
  }
  return 0xffffffff;
}


// ===== 00258310 nvswitch_lib_service_interrupts =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_lib_service_interrupts(long *param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  if ((((param_1 != (long *)0x0) && (lVar1 = *param_1, *(long *)(lVar1 + 0xa8) == 3)) &&
      (*(long *)(lVar1 + 0x78) != 0)) && (*(char *)(lVar1 + 0xb0) != '\0')) {
    uVar2 = (*(code *)param_1[0xb0])();
    return uVar2;
  }
  return 0xffffffff;
}


// ===== 00258350 nvswitch_hw_counter_read_counter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_hw_counter_read_counter(long param_1)

{
  (**(code **)(param_1 + 0x588))();
  return;
}


// ===== 00258360 nvswitch_reg_write_32 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_reg_write_32(long *param_1)

{
  if (*(long *)(*param_1 + 0x78) != 0) {
    (*(code *)param_1[0x126])();
    return;
  }
  return;
}


// ===== 00258390 nvswitch_validate_pll_config =====

undefined1  [16] nvswitch_validate_pll_config(long param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined1 auVar3 [16];
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  uint uVar7;
  undefined1 auVar8 [16];
  undefined8 in_stack_00000008;
  int iStack0000000000000010;
  int iStack0000000000000014;
  int iStack0000000000000018;
  int iStack000000000000001c;
  int iStack0000000000000020;
  uint uStack0000000000000024;
  uint uStack0000000000000028;
  uint uStack000000000000002c;
  uint uStack0000000000000030;
  uint uStack0000000000000034;
  uint in_stack_00000038;
  
  if (((*(int *)(param_1 + 0x170) == 0) || (*(char *)(param_1 + 0x1d4) == '\0')) ||
     (*(char *)(param_1 + 0x1d8) == '\0')) {
    uVar7 = param_2[1];
  }
  else {
    iStack000000000000001c = *(int *)(param_1 + 0x1ec);
    uVar7 = param_2[1];
    in_stack_00000008._4_4_ = *(int *)(param_1 + 0x1dc);
    iStack0000000000000010 = *(int *)(param_1 + 0x1e0);
    iStack0000000000000014 = *(int *)(param_1 + 0x1e4);
    iStack0000000000000018 = *(int *)(param_1 + 0x1e8);
    iStack0000000000000020 = *(int *)(param_1 + 0x1f0);
    uStack0000000000000024 = *(uint *)(param_1 + 500);
    uStack0000000000000028 = *(uint *)(param_1 + 0x1f8);
    uStack000000000000002c = *(uint *)(param_1 + 0x1fc);
    uStack0000000000000030 = *(uint *)(param_1 + 0x200);
    uStack0000000000000034 = *(uint *)(param_1 + 0x204);
    in_stack_00000038 = *(uint *)(param_1 + 0x208);
  }
  if (uVar7 == 0) {
    nvswitch_os_assert_log("NVSwitch: Assertion failed\n");
    uVar7 = param_2[3];
  }
  else {
    uVar7 = param_2[3];
  }
  uVar6 = (ulong)uStack0000000000000024;
  if (uVar7 == 0) {
    nvswitch_os_assert_log("NVSwitch: Assertion failed\n");
  }
  uVar7 = *param_2;
  if ((((((uint)(in_stack_00000008._4_4_ * 1000) <= uVar7) &&
        (uVar7 <= (uint)(iStack0000000000000010 * 1000))) &&
       ((uVar1 = param_2[1], uVar1 <= uStack0000000000000028 &&
        ((uStack0000000000000024 <= uVar1 && (uVar4 = param_2[2], uVar4 <= uStack0000000000000030)))
        ))) && (uStack000000000000002c <= uVar4)) &&
     ((uVar2 = param_2[3], uVar2 <= in_stack_00000038 && (uStack0000000000000034 <= uVar2)))) {
    uVar4 = uVar4 * uVar7;
    uVar5 = uVar4 / uVar1;
    uVar6 = (ulong)uVar4 % (ulong)uVar1;
    if (((uint)(iStack0000000000000014 * 1000) <= uVar5) &&
       (uVar5 <= (uint)(iStack0000000000000018 * 1000))) {
      uVar6 = (ulong)(uint)(iStack000000000000001c * 1000);
      if (((uint)(iStack000000000000001c * 1000) <= uVar7 / uVar1) &&
         (uVar6 = (ulong)(uint)(iStack0000000000000020 * 1000),
         uVar7 / uVar1 <= (uint)(iStack0000000000000020 * 1000))) {
        param_2[6] = uVar5;
        uVar7 = uVar1 * uVar2 << ((byte)param_2[4] & 0x1f);
        param_2[7] = uVar4 / uVar7;
        auVar3._8_8_ = 0;
        auVar3._0_8_ = (ulong)uVar4 % (ulong)uVar7;
        return auVar3 << 0x40;
      }
    }
  }
  auVar8._8_8_ = uVar6;
  auVar8._0_8_ = 0xfffffff8;
  return auVar8;
}


// ===== 00258600 nvswitch_init_pll_config =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_init_pll_config(long param_1)

{
  (**(code **)(param_1 + 0x950))();
  return;
}


// ===== 00258610 nvswitch_init_pll =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_init_pll(long param_1)

{
  (**(code **)(param_1 + 0x958))();
  return;
}


// ===== 00258620 nvswitch_init_clock_gating =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_init_clock_gating(long param_1)

{
  (**(code **)(param_1 + 0x960))();
  return;
}


// ===== 00258630 nvswitch_lib_get_uuid =====

void nvswitch_lib_get_uuid(long *param_1,long param_2)

{
  long lVar1;
  
  if ((((param_1 != (long *)0x0) && (lVar1 = *param_1, *(long *)(lVar1 + 0xa8) == 3)) &&
      (*(long *)(lVar1 + 0x78) != 0)) && ((*(char *)(lVar1 + 0xb0) != '\0' && (param_2 != 0)))) {
    nvswitch_os_memcpy(param_2,param_1 + 0x3f3,0x10);
    return;
  }
  return;
}


// ===== 00258680 nvswitch_lib_get_physid =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_lib_get_physid(long *param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  undefined8 local_120 [16];
  undefined4 local_9c;
  
  if ((((param_1 != (long *)0x0) && (param_2 != (undefined4 *)0x0)) &&
      (*(long *)(*param_1 + 0xa8) == 3)) && (*(long *)(*param_1 + 0x78) != 0)) {
    local_120[0] = 0x20300000001;
    uVar1 = (*(code *)param_1[0xb4])(param_1,local_120);
    if ((int)uVar1 == 0) {
      *param_2 = local_9c;
    }
    return uVar1;
  }
  return 0xffffffff;
}


// ===== 00258700 nvswitch_lib_smbpbi_log_sxid =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_lib_smbpbi_log_sxid
               (long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  int iVar1;
  undefined4 local_c8 [2];
  undefined1 *local_c0;
  undefined1 *local_b8;
  undefined1 local_a9 [81];
  undefined1 local_58 [24];
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  local_40 = param_4;
  local_38 = param_5;
  local_30 = param_6;
  nvswitch_os_memset(local_a9,0,0x51);
  local_c0 = &stack0x00000008;
  local_b8 = local_58;
  local_c8[0] = 0x18;
  iVar1 = nvswitch_os_vsnprintf(local_a9,0x51,param_3,local_c8);
  if (-1 < iVar1) {
    if (0x4f < iVar1) {
      iVar1 = 0x4f;
    }
    (**(code **)(param_1 + 0x8a8))(param_1,param_2,iVar1 + 1,local_a9);
  }
  return;
}


// ===== 002587b0 nvswitch_reg_read_32 =====

uint nvswitch_reg_read_32(long *param_1,uint param_2)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (*(long *)(*param_1 + 0x78) != 0) {
    uVar2 = nvswitch_os_mem_read32(*(long *)(*param_1 + 0x78) + (ulong)param_2);
    if ((uVar2 & 0xffff0000) == 0xbadf0000) {
      uVar3 = nvswitch_os_mem_read32(*(undefined8 *)(*param_1 + 0x78));
      if ((uVar3 & 0xffff0000) == 0xbadf0000) {
        iVar4 = nvswitch_translate_hw_error(0x2717);
        if (iVar4 == 1) {
          nvswitch_os_assert_log("NVSwitch: Assertion failed\n");
        }
        lVar1 = *param_1;
        nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, IO failure\n",
                          param_1 + 1,*(undefined4 *)(lVar1 + 0x40),*(undefined1 *)(lVar1 + 0x44),
                          *(undefined1 *)(lVar1 + 0x45),*(undefined1 *)(lVar1 + 0x46),0x2717);
        nvswitch_os_report_error(param_1[3],0x2717,"IO failure\n");
        nvswitch_lib_smbpbi_log_sxid(param_1,0x2717,"IO failure\n");
        nvswitch_inforom_bbx_add_sxid(param_1,0x2717,0,0,0);
      }
    }
    return uVar2;
  }
  return 0xffffffff;
}


// ===== 002588d0 nvswitch_read_64bit_counter =====

undefined8 nvswitch_read_64bit_counter(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  
  iVar1 = nvswitch_reg_read_32(param_1,param_3);
  do {
    uVar2 = nvswitch_reg_read_32(param_1,param_2);
    iVar3 = nvswitch_reg_read_32(param_1,param_3);
    bVar4 = iVar1 != iVar3;
    iVar1 = iVar3;
  } while (bVar4);
  return CONCAT44(iVar3,uVar2);
}


// ===== 00258950 nvswitch_set_minion_initialized =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_set_minion_initialized(long param_1,undefined8 param_2,undefined1 param_3)

{
  (**(code **)(param_1 + 0x8b8))(param_1,param_2,param_3);
  return;
}


// ===== 00258970 nvswitch_is_minion_initialized =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_is_minion_initialized(long param_1)

{
  (**(code **)(param_1 + 0x8c0))();
  return;
}


// ===== 00258980 nvswitch_device_discovery =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_device_discovery(long param_1)

{
  (**(code **)(param_1 + 0x8f0))();
  return;
}


// ===== 00258990 nvswitch_filter_discovery =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_filter_discovery(long param_1)

{
  (**(code **)(param_1 + 0x8f8))();
  return;
}


// ===== 002589a0 nvswitch_process_discovery =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_process_discovery(long param_1)

{
  (**(code **)(param_1 + 0x900))();
  return;
}


// ===== 002589b0 nvswitch_init_minion =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_init_minion(long param_1)

{
  (**(code **)(param_1 + 0x908))();
  return;
}


// ===== 002589c0 nvswitch_get_link_eng_inst =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_get_link_eng_inst(long param_1)

{
  (**(code **)(param_1 + 0x938))();
  return;
}


// ===== 002589d0 nvswitch_alloc_chipdevice =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_alloc_chipdevice(long param_1)

{
  (**(code **)(param_1 + 0x940))();
  return;
}


// ===== 002589e0 nvswitch_free_chipdevice =====

void nvswitch_free_chipdevice(long param_1)

{
  if (*(long *)(param_1 + 0x1f90) != 0) {
    nvswitch_os_free(*(long *)(param_1 + 0x1f90));
    *(undefined8 *)(param_1 + 0x1f90) = 0;
    return;
  }
  return;
}


// ===== 00258a20 nvswitch_init_thermal =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_init_thermal(long param_1)

{
  (**(code **)(param_1 + 0x948))();
  return;
}


// ===== 00258a30 nvswitch_read_physical_id =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_read_physical_id(long param_1)

{
  (**(code **)(param_1 + 0x968))();
  return;
}


// ===== 00258a40 nvswitch_get_caps_nvlink_version =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_get_caps_nvlink_version(long param_1)

{
  (**(code **)(param_1 + 0x970))();
  return;
}


// ===== 00258a50 nvswitch_initialize_interrupt_tree =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_initialize_interrupt_tree(long param_1)

{
  (**(code **)(param_1 + 0x978))();
  return;
}


// ===== 00258a60 nvswitch_init_dlpl_interrupts =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_init_dlpl_interrupts(long param_1)

{
  (**(code **)(*(long *)(*(long *)(param_1 + 0x10) + 200) + 0x980))();
  return;
}


// ===== 00258a80 nvswitch_initialize_pmgr =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_initialize_pmgr(long param_1)

{
  (**(code **)(param_1 + 0x988))();
  return;
}


// ===== 00258a90 nvswitch_initialize_ip_wrappers =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_initialize_ip_wrappers(long param_1)

{
  (**(code **)(param_1 + 0x990))();
  return;
}


// ===== 00258aa0 nvswitch_initialize_route =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_initialize_route(long param_1)

{
  (**(code **)(param_1 + 0x998))();
  return;
}


// ===== 00258ab0 nvswitch_soe_unregister_events =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_soe_unregister_events(long param_1)

{
  (**(code **)(param_1 + 0x9a0))();
  return;
}


// ===== 00258ac0 nvswitch_soe_register_event_callbacks =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_soe_register_event_callbacks(long param_1)

{
  (**(code **)(param_1 + 0x9a8))();
  return;
}


// ===== 00258ad0 nvswitch_get_bios_nvlink_config =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_get_bios_nvlink_config(long param_1)

{
  (**(code **)(param_1 + 0x9b0))();
  return;
}


// ===== 00258ae0 nvswitch_minion_send_command =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_minion_send_command(long param_1)

{
  (**(code **)(param_1 + 0x9b8))();
  return;
}


// ===== 00258af0 nvswitch_init_nport =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_init_nport(long param_1)

{
  (**(code **)(param_1 + 0x9c0))();
  return;
}


// ===== 00258b00 nvswitch_init_nxbar =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_init_nxbar(long param_1)

{
  (**(code **)(param_1 + 0x9c8))();
  return;
}


// ===== 00258b10 nvswitch_clear_nport_rams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_clear_nport_rams(long param_1)

{
  (**(code **)(param_1 + 0x9d0))();
  return;
}


// ===== 00258b20 nvswitch_pri_ring_init =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_pri_ring_init(long param_1)

{
  (**(code **)(param_1 + 0x9d8))();
  return;
}


// ===== 00258b30 nvswitch_get_remap_table_selector =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_get_remap_table_selector(long param_1)

{
  (**(code **)(param_1 + 0x9e0))();
  return;
}


// ===== 00258b40 nvswitch_get_ingress_ram_size =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_get_ingress_ram_size(long param_1)

{
  (**(code **)(param_1 + 0x9e8))();
  return;
}


// ===== 00258b50 nvswitch_minion_get_dl_status =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_minion_get_dl_status(long param_1)

{
  (**(code **)(param_1 + 0x9f0))();
  return;
}


// ===== 00258b60 nvswitch_poll_sublink_state =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_poll_sublink_state(long param_1)

{
  (**(code **)(param_1 + 0xa08))();
  return;
}


// ===== 00258b70 nvswitch_setup_link_loopback_mode =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_setup_link_loopback_mode(long param_1)

{
  (**(code **)(param_1 + 0xa10))();
  return;
}


// ===== 00258b80 nvswitch_store_topology_information =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_store_topology_information(long param_1)

{
  (**(code **)(param_1 + 0xa20))();
  return;
}


// ===== 00258b90 nvswitch_init_lpwr_regs =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_init_lpwr_regs(long param_1)

{
  (**(code **)(*(long *)(*(long *)(param_1 + 0x10) + 200) + 0xa28))();
  return;
}


// ===== 00258bb0 nvswitch_check_io_sanity =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_check_io_sanity(long param_1)

{
  (**(code **)(param_1 + 0xae8))();
  return;
}


// ===== 00258bc0 nvswitch_launch_ALI =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_launch_ALI(long param_1)

{
  (**(code **)(param_1 + 0xcb0))();
  return;
}


// ===== 00258bd0 nvswitch_is_link_in_reset =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_is_link_in_reset(long param_1)

{
  (**(code **)(param_1 + 0xa58))();
  return;
}


// ===== 00258be0 nvswitch_init_buffer_ready =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_init_buffer_ready(long param_1,undefined8 param_2,undefined1 param_3)

{
  (**(code **)(param_1 + 0xa60))(param_1,param_2,param_3);
  return;
}


// ===== 00258c00 nvswitch_apply_recal_settings =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_apply_recal_settings(long param_1)

{
  (**(code **)(param_1 + 0xa70))();
  return;
}


// ===== 00258c10 nvswitch_launch_ALI_link_training =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_launch_ALI_link_training(long param_1,undefined8 param_2,undefined1 param_3)

{
  (**(code **)(param_1 + 0xcb8))(param_1,param_2,param_3);
  return;
}


// ===== 00258c30 nvswitch_setup_link_system_registers =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_setup_link_system_registers(long param_1)

{
  (**(code **)(param_1 + 0x778))();
  return;
}


// ===== 00258c40 nvswitch_load_link_disable_settings =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_load_link_disable_settings(long param_1)

{
  (**(code **)(param_1 + 0x780))();
  return;
}


// ===== 00258c50 nvswitch_get_board_id =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_get_board_id(long param_1)

{
  (**(code **)(param_1 + 0xad0))();
  return;
}


// ===== 00258c60 _nvswitch_ctrl_get_link_l1_capability =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _nvswitch_ctrl_get_link_l1_capability(undefined8 *param_1,ulong *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  ulong uVar3;
  uint uVar4;
  long local_30;
  
  uVar3 = *param_2;
  if (uVar3 == 0) {
    return 0xffffffff;
  }
  uVar4 = 0;
  do {
    if ((uVar3 & 1) != 0) {
      uVar1 = (*(code *)param_1[0xa2])(param_1);
      if (uVar1 <= uVar4) {
        nvswitch_os_assert_log("NVSwitch: Assertion failed\n");
      }
      local_30 = 0;
      nvlink_lib_get_link(*param_1,uVar4,&local_30);
      if (local_30 == 0) {
        return 0xffffffff;
      }
      uVar2 = (*(code *)param_1[0x15e])
                        (param_1,(ulong)*(uint *)(local_30 + 0x38),
                         (long)param_2 + (ulong)*(uint *)(local_30 + 0x38) + 8);
      if (((int)uVar2 != 0) || (uVar3 >> 1 == 0)) {
        return uVar2;
      }
    }
    uVar3 = uVar3 >> 1;
    uVar4 = uVar4 + 1;
  } while( true );
}


// ===== 00258d40 _nvswitch_ctrl_get_link_l1_threshold =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _nvswitch_ctrl_get_link_l1_threshold(undefined8 *param_1,ulong *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  ulong uVar3;
  uint uVar4;
  char local_41;
  long local_40 [2];
  
  if (*(int *)(param_1 + 0xb) == 0) {
    return 0xfffffff3;
  }
  uVar3 = *param_2;
  if (uVar3 == 0) {
    return 0xffffffff;
  }
  uVar4 = 0;
  do {
    if ((uVar3 & 1) != 0) {
      uVar1 = (*(code *)param_1[0xa2])(param_1);
      if (uVar1 <= uVar4) {
        nvswitch_os_assert_log("NVSwitch: Assertion failed\n");
      }
      local_40[0] = 0;
      nvlink_lib_get_link(*param_1,uVar4,local_40);
      if (local_40[0] == 0) {
        return 0xffffffff;
      }
      uVar1 = *(uint *)(local_40[0] + 0x38);
      uVar2 = (*(code *)param_1[0x15e])(param_1,uVar1,&local_41);
      if ((int)uVar2 != 0) {
        return uVar2;
      }
      if (local_41 == '\0') {
        return 0xfffffff3;
      }
      uVar2 = (*(code *)param_1[0x15f])(param_1,uVar1,(long)param_2 + (ulong)uVar1 * 4 + 8);
      if ((int)uVar2 != 0) {
        return uVar2;
      }
      if (uVar3 >> 1 == 0) {
        return uVar2;
      }
    }
    uVar3 = uVar3 >> 1;
    uVar4 = uVar4 + 1;
  } while( true );
}


// ===== 00258eb0 _nvswitch_ctrl_set_link_l1_threshold =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _nvswitch_ctrl_set_link_l1_threshold(undefined8 *param_1,ulong *param_2)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  char local_41;
  long local_40 [2];
  
  if (*(int *)(param_1 + 0xb) == 0) {
    return 0xfffffff3;
  }
  uVar6 = *param_2;
  if (uVar6 == 0) {
    return 0xffffffff;
  }
  uVar7 = 0;
  do {
    if ((uVar6 & 1) != 0) {
      uVar3 = (*(code *)param_1[0xa2])(param_1);
      if (uVar3 <= uVar7) {
        nvswitch_os_assert_log("NVSwitch: Assertion failed\n");
      }
      local_40[0] = 0;
      nvlink_lib_get_link(*param_1,uVar7,local_40);
      lVar2 = local_40[0];
      if (local_40[0] == 0) {
        return 0xffffffff;
      }
      uVar5 = (ulong)*(uint *)(local_40[0] + 0x38);
      iVar1 = *(int *)((long)param_2 + uVar5 * 4 + 8);
      uVar4 = (*(code *)param_1[0x15e])(param_1,uVar5,&local_41);
      if ((int)uVar4 != 0) {
        return uVar4;
      }
      if (local_41 == '\0') {
        return 0xfffffff3;
      }
      if ((0x1ffe < iVar1 - 1U) && (iVar1 != -1)) {
        return 0xffffffff;
      }
      uVar4 = (*(code *)param_1[0x160])(lVar2,*(undefined4 *)((long)param_2 + uVar5 * 4 + 8));
      if ((int)uVar4 != 0) {
        return uVar4;
      }
      if (uVar6 >> 1 == 0) {
        return uVar4;
      }
    }
    uVar6 = uVar6 >> 1;
    uVar7 = uVar7 + 1;
  } while( true );
}


// ===== 00259040 nvswitch_detect_tnvl_mode =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_detect_tnvl_mode(long param_1)

{
  (**(code **)(param_1 + 0xb98))();
  return;
}


// ===== 00259050 nvswitch_is_tnvl_mode_enabled =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_is_tnvl_mode_enabled(long param_1)

{
  (**(code **)(param_1 + 0xba0))();
  return;
}


// ===== 00259060 nvswitch_is_tnvl_mode_locked =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_is_tnvl_mode_locked(long param_1)

{
  (**(code **)(param_1 + 0xba8))();
  return;
}


// ===== 00259070 nvswitch_lib_is_tnvl_enabled =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_lib_is_tnvl_enabled(long param_1)

{
  (**(code **)(param_1 + 0xba0))();
  return;
}


// ===== 00259080 nvswitch_lib_ctrl_tnvl_lock_only =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
nvswitch_lib_ctrl_tnvl_lock_only
          (long *param_1,uint param_2,int *param_3,long param_4,undefined8 param_5)

{
  int iVar1;
  code *pcVar2;
  undefined8 uVar3;
  long lVar4;
  
  if ((((param_1 == (long *)0x0) || (*(long *)(*param_1 + 0xa8) != 3)) ||
      (*(long *)(*param_1 + 0x78) == 0)) || (param_3 == (int *)0x0)) {
    return 0xffffffff;
  }
  if (param_2 == 0x31) {
    if (param_4 != 0xa4) {
      return 0xffffffff;
    }
    iVar1 = nvswitch_os_is_admin();
    if ((iVar1 == 0) && (iVar1 = nvswitch_os_is_fabric_manager(param_5), iVar1 == 0)) {
      return 0xfffffff1;
    }
    uVar3 = nvswitch_inforom_bbx_get_sxid(param_1,param_3);
    return uVar3;
  }
  if (param_2 < 0x32) {
    if (param_2 == 0x21) {
      if (param_4 != 4) {
        return 0xffffffff;
      }
      iVar1 = nvswitch_os_is_admin();
      if ((iVar1 == 0) && (iVar1 = nvswitch_os_is_fabric_manager(param_5), iVar1 == 0)) {
        return 0xfffffff1;
      }
      if (*(long *)(*param_1 + 0xa8) != 3) {
        return 0xffffffff;
      }
      if (*(long *)(*param_1 + 0x78) == 0) {
        return 0xffffffff;
      }
      iVar1 = *(int *)((long)param_1 + 0x1fac);
      *(int *)((long)param_1 + 0x1fac) = *param_3;
      lVar4 = nvswitch_os_get_platform_time();
      param_1[0x3f7] = lVar4;
      if (iVar1 != *param_3) {
        nvswitch_lib_notify_client_events(param_1,4);
      }
      return 0;
    }
    if (param_2 < 0x22) {
      if (param_2 == 0x17) {
        if (param_4 != 0x2e08) {
          return 0xffffffff;
        }
        pcVar2 = (code *)param_1[0xb5];
      }
      else if (param_2 < 0x18) {
        if (param_2 == 7) {
          if (param_4 != 0xa10) {
            return 0xffffffff;
          }
          pcVar2 = (code *)param_1[0xca];
        }
        else {
          if (param_2 == 0xc) {
            if (param_4 != 0x2a20) {
              return 0xffffffff;
            }
            uVar3 = nvswitch_ctrl_get_errors(param_1,param_3);
            return uVar3;
          }
          if (param_2 != 1) goto LAB_00259508;
          if (param_4 != 0x104) {
            return 0xffffffff;
          }
          pcVar2 = (code *)param_1[0xb4];
        }
      }
      else if (param_2 == 0x1b) {
        if (param_4 != 0x84) {
          return 0xffffffff;
        }
        pcVar2 = (code *)param_1[0xd1];
      }
      else {
        if (param_2 != 0x1f) goto LAB_00259508;
        if (param_4 != 8) {
          return 0xffffffff;
        }
        pcVar2 = (code *)param_1[0x101];
      }
    }
    else {
      if (param_2 == 0x2e) {
        if (param_4 != 0xc4) {
          return 0xffffffff;
        }
        iVar1 = nvswitch_os_is_admin();
        if ((iVar1 == 0) && (iVar1 = nvswitch_os_is_fabric_manager(param_5), iVar1 == 0)) {
          return 0xfffffff1;
        }
        uVar3 = nvswitch_inforom_nvlink_get_max_correctable_error_rate(param_1,param_3);
        return uVar3;
      }
      if (0x2e < param_2) {
        if (param_2 == 0x2f) {
          if (param_4 != 0xc08) {
            return 0xffffffff;
          }
          iVar1 = nvswitch_os_is_admin();
          if ((iVar1 == 0) && (iVar1 = nvswitch_os_is_fabric_manager(param_5), iVar1 == 0)) {
            return 0xfffffff1;
          }
          uVar3 = nvswitch_inforom_nvlink_get_errors(param_1,param_3);
          return uVar3;
        }
        if (param_4 != 0xe18) {
          return 0xffffffff;
        }
        iVar1 = nvswitch_os_is_admin();
        if ((iVar1 == 0) && (iVar1 = nvswitch_os_is_fabric_manager(param_5), iVar1 == 0)) {
          return 0xfffffff1;
        }
        uVar3 = nvswitch_inforom_ecc_get_errors(param_1,param_3);
        return uVar3;
      }
      if (param_2 == 0x2b) {
        if (param_4 != 0xe08) {
          return 0xffffffff;
        }
        iVar1 = nvswitch_os_is_admin();
        if ((iVar1 == 0) && (iVar1 = nvswitch_os_is_fabric_manager(param_5), iVar1 == 0)) {
          return 0xfffffff1;
        }
        pcVar2 = (code *)param_1[0xf3];
      }
      else if (param_2 == 0x2d) {
        if (param_4 != 8) {
          return 0xffffffff;
        }
        pcVar2 = (code *)param_1[0xd2];
      }
      else {
        if (param_2 != 0x27) goto LAB_00259508;
        if (param_4 != 0x41) {
          return 0xffffffff;
        }
        pcVar2 = (code *)param_1[0x11c];
      }
    }
  }
  else {
    if (param_2 == 0x60) {
      if (param_4 != 0x14) {
        return 0xffffffff;
      }
      iVar1 = nvswitch_os_is_admin();
      if ((iVar1 == 0) && (iVar1 = nvswitch_os_is_fabric_manager(param_5), iVar1 == 0)) {
        return 0xfffffff1;
      }
      uVar3 = nvswitch_inforom_bbx_get_data(param_1,3,param_3);
      return uVar3;
    }
    if (param_2 < 0x61) {
      if (param_2 == 0x54) {
        if (param_4 != 0xc) {
          return 0xffffffff;
        }
        pcVar2 = (code *)param_1[0x157];
      }
      else if (param_2 < 0x55) {
        if (param_2 == 0x52) {
          if (param_4 != 0x308) {
            return 0xffffffff;
          }
          iVar1 = nvswitch_os_is_admin();
          if ((iVar1 == 0) && (iVar1 = nvswitch_os_is_fabric_manager(param_5), iVar1 == 0)) {
            return 0xfffffff1;
          }
          pcVar2 = (code *)param_1[0x154];
        }
        else if (param_2 == 0x53) {
          if (param_4 != 0x308) {
            return 0xffffffff;
          }
          pcVar2 = (code *)param_1[0x155];
        }
        else {
          if (param_2 != 0x4f) goto LAB_00259508;
          if (param_4 != 0x10) {
            return 0xffffffff;
          }
          pcVar2 = (code *)param_1[0x102];
        }
      }
      else {
        if (param_2 != 0x57) {
          if (param_2 == 0x59) {
            if (param_4 != 0x14) {
              return 0xffffffff;
            }
            iVar1 = nvswitch_os_is_admin();
            if ((iVar1 == 0) && (iVar1 = nvswitch_os_is_fabric_manager(param_5), iVar1 == 0)) {
              return 0xfffffff1;
            }
            uVar3 = nvswitch_inforom_bbx_get_data(param_1,2,param_3);
            return uVar3;
          }
          goto LAB_00259508;
        }
        if (param_4 != 0xc) {
          return 0xffffffff;
        }
        pcVar2 = (code *)param_1[0x159];
      }
    }
    else if (param_2 == 0x6a) {
      if (param_4 != 0x1404) {
        return 0xffffffff;
      }
      pcVar2 = (code *)param_1[0x176];
    }
    else {
      if (param_2 < 0x6b) {
        if (param_2 == 0x61) {
          if (param_4 != 0x7c4) {
            return 0xffffffff;
          }
          iVar1 = nvswitch_os_is_admin();
          if ((iVar1 == 0) && (iVar1 = nvswitch_os_is_fabric_manager(param_5), iVar1 == 0)) {
            return 0xfffffff1;
          }
          uVar3 = nvswitch_inforom_bbx_get_data(param_1,4,param_3);
          return uVar3;
        }
        if (param_2 == 0x62) {
          if (param_4 != 0x2264) {
            return 0xffffffff;
          }
          iVar1 = nvswitch_os_is_admin();
          if ((iVar1 == 0) && (iVar1 = nvswitch_os_is_fabric_manager(param_5), iVar1 == 0)) {
            return 0xfffffff1;
          }
          uVar3 = nvswitch_inforom_bbx_get_data(param_1,5,param_3);
          return uVar3;
        }
LAB_00259508:
        nvswitch_os_print(2,"ioctl %x is not permitted when TNVL is locked\n",param_2);
        return 0xfffffff1;
      }
      if (param_2 == 0x6b) {
        if (param_4 != 0x2024) {
          return 0xffffffff;
        }
        pcVar2 = (code *)param_1[0x177];
      }
      else {
        if (param_2 != 0x6c) goto LAB_00259508;
        if (param_4 != 4) {
          return 0xffffffff;
        }
        pcVar2 = (code *)param_1[0x179];
      }
    }
  }
  uVar3 = (*pcVar2)(param_1,param_3);
  return uVar3;
}


// ===== 00259730 nvswitch_lib_ctrl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

ulong nvswitch_lib_ctrl(long *param_1,uint param_2,ulong *param_3,long param_4,ulong param_5)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  code *pcVar8;
  long lVar9;
  long *plVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  undefined8 uVar14;
  undefined8 extraout_RDX;
  int *piVar15;
  undefined1 uVar16;
  ulong uVar17;
  ulong uVar18;
  byte bVar19;
  char local_48;
  undefined7 uStack_47;
  long local_40 [2];
  
  cVar2 = (*(code *)param_1[0x175])();
  if (cVar2 != '\0') {
    uVar11 = nvswitch_lib_ctrl_tnvl_lock_only(param_1,param_2,param_3,param_4,param_5);
    return uVar11;
  }
  if (((*(long *)(*param_1 + 0xa8) == 3) && (*(long *)(*param_1 + 0x78) != 0)) &&
     (param_3 != (ulong *)0x0)) {
    if (param_2 == 0x31) {
      if (param_4 == 0xa4) {
        iVar7 = nvswitch_os_is_admin();
        if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
          return 0xfffffff1;
        }
        uVar11 = nvswitch_inforom_bbx_get_sxid(param_1,param_3);
        return uVar11;
      }
    }
    else {
      if (param_2 < 0x32) {
        if (param_2 == 0x19) {
          if (param_4 != 0x2310) {
            return 0xffffffff;
          }
          iVar7 = nvswitch_os_is_admin();
          if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
            return 0xfffffff1;
          }
          pcVar8 = (code *)param_1[0xc5];
LAB_00259814:
          uVar11 = (*pcVar8)(param_1,param_3);
          return uVar11;
        }
        if (0x19 < param_2) {
          if (param_2 == 0x25) {
            if (param_4 != 8) {
              return 0xffffffff;
            }
            uVar3 = nvswitch_os_get_supported_register_events_params(&local_48,local_40);
            if (uVar3 == 0) {
              if ((char)local_40[0] != '\0') {
                param_5 = *param_3;
              }
              uVar3 = nvswitch_lib_remove_client_events(param_1,param_5);
              return (ulong)uVar3;
            }
            return (ulong)uVar3;
          }
          if (param_2 < 0x26) {
            if (param_2 == 0x1f) {
              if (param_4 != 8) {
                return 0xffffffff;
              }
              pcVar8 = (code *)param_1[0x101];
            }
            else {
              if (0x1f < param_2) {
                if (param_2 == 0x22) {
                  if (param_4 != 4) {
                    return 0xffffffff;
                  }
                  iVar7 = nvswitch_os_is_admin();
                  if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0))
                  {
                    return 0xfffffff1;
                  }
                  if (*(long *)(*param_1 + 0xa8) != 3) {
                    return 0xffffffff;
                  }
                  if (*(long *)(*param_1 + 0x78) == 0) {
                    return 0xffffffff;
                  }
                  if ((int)param_1[0x3f6] == 3) {
                    return 0xfffffff3;
                  }
                  *(int *)(param_1 + 0x3f6) = (int)*param_3;
                  lVar9 = nvswitch_os_get_platform_time();
                  param_1[0x3f7] = lVar9;
                  if (*(int *)((long)param_1 + 0x1fac) != 3) {
                    return 0;
                  }
                  *(undefined4 *)((long)param_1 + 0x1fac) = 2;
                  return 0;
                }
                if (0x22 < param_2) {
                  if (param_2 != 0x23) {
                    if (param_4 != 0x7e0) {
                      return 0xffffffff;
                    }
                    uVar3 = nvswitch_os_get_supported_register_events_params(&local_48,local_40);
                    if (uVar3 != 0) {
                      return (ulong)uVar3;
                    }
                    if ((local_48 == '\0') && (1 < (uint)param_3[0xfa])) {
                      return 0xffffffff;
                    }
                    if ((uint)param_3[0xfa] == 0) {
                      return 0xffffffff;
                    }
                    if ((char)local_40[0] != '\0') {
                      param_5 = param_3[0xfb];
                    }
                    lVar9 = 0;
                    while( true ) {
                      if (*(long *)(*param_1 + 0xa8) != 3) {
                        return 0xffffffff;
                      }
                      uVar3 = *(uint *)((long)param_3 + lVar9 * 4);
                      if (5 < uVar3) {
                        return 0xffffffff;
                      }
                      uVar4 = nvswitch_os_add_client_event(param_1[3],param_5,uVar3);
                      if (uVar4 != 0) {
                        return (ulong)uVar4;
                      }
                      plVar10 = (long *)nvswitch_os_malloc_trace(0x20,0,0);
                      if (plVar10 == (long *)0x0) break;
                      plVar10[3] = param_5;
                      lVar9 = lVar9 + 1;
                      *(uint *)(plVar10 + 2) = uVar3;
                      lVar1 = param_1[0x3fb];
                      *(long **)(lVar1 + 8) = plVar10;
                      *plVar10 = lVar1;
                      plVar10[1] = (long)(param_1 + 0x3fb);
                      param_1[0x3fb] = (long)plVar10;
                      if ((uint)param_3[0xfa] <= (uint)lVar9) {
                        return 0;
                      }
                    }
                    return 0xfffffffe;
                  }
                  if (param_4 != 4) {
                    return 0xffffffff;
                  }
                  iVar7 = nvswitch_os_is_admin();
                  if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0))
                  {
                    return 0xfffffff1;
                  }
                  if (*(long *)(*param_1 + 0xa8) != 3) {
                    return 0xffffffff;
                  }
                  if (*(long *)(*param_1 + 0x78) == 0) {
                    return 0xffffffff;
                  }
                  *(int *)(param_1 + 0x3f5) = (int)*param_3;
                  return 0;
                }
                if (param_2 == 0x20) {
                  if (param_4 != 4) {
                    return 0xffffffff;
                  }
                  iVar7 = nvswitch_os_is_admin();
                  if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0))
                  {
                    return 0xfffffff1;
                  }
                  if (*(long *)(*param_1 + 0xa8) != 3) {
                    return 0xffffffff;
                  }
                  if (*(long *)(*param_1 + 0x78) == 0) {
                    return 0xffffffff;
                  }
                  if ((int)param_1[0x3f6] != 3) {
                    uVar11 = *param_3;
                    *(undefined4 *)(param_1 + 0x3f6) = 3;
                    *(int *)((long)param_1 + 0x1fb4) = (int)uVar11;
                    (*(code *)param_1[0x104])(param_1);
                    cVar2 = (*(code *)param_1[0x175])(param_1);
                    if (cVar2 == '\0') {
                      if ((*(long *)(*param_1 + 0xa8) == 3) && (*(long *)(*param_1 + 0x78) != 0)) {
                        (*(code *)param_1[0xae])(param_1);
                      }
                      else {
                        nvswitch_os_assert_log("NVSwitch: Assertion failed\n");
                      }
                    }
                    _nvswitch_unregister_links(param_1);
                    return 0;
                  }
                  return 0xfffffff3;
                }
                if (param_4 != 4) {
                  return 0xffffffff;
                }
                iVar7 = nvswitch_os_is_admin();
                if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                  return 0xfffffff1;
                }
                if (*(long *)(*param_1 + 0xa8) != 3) {
                  return 0xffffffff;
                }
                if (*(long *)(*param_1 + 0x78) == 0) {
                  return 0xffffffff;
                }
                iVar7 = *(int *)((long)param_1 + 0x1fac);
                *(int *)((long)param_1 + 0x1fac) = (int)*param_3;
                lVar9 = nvswitch_os_get_platform_time();
                param_1[0x3f7] = lVar9;
                if (iVar7 == (int)*param_3) {
                  return 0;
                }
                nvswitch_lib_notify_client_events(param_1,4);
                return 0;
              }
              if (param_2 == 0x1c) {
                if (param_4 != 0x1018) {
                  return 0xffffffff;
                }
                iVar7 = nvswitch_os_is_admin();
                if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                  return 0xfffffff1;
                }
                pcVar8 = (code *)param_1[0xc2];
              }
              else if (param_2 < 0x1d) {
                if (param_2 == 0x1a) {
                  if (param_4 != 0x4c) {
                    return 0xffffffff;
                  }
                  iVar7 = nvswitch_os_is_admin();
                  if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0))
                  {
                    return 0xfffffff1;
                  }
                  pcVar8 = (code *)param_1[0xc6];
                }
                else {
                  if (param_4 != 0x84) {
                    return 0xffffffff;
                  }
                  pcVar8 = (code *)param_1[0xd1];
                }
              }
              else if (param_2 == 0x1d) {
                if (param_4 != 0x50) {
                  return 0xffffffff;
                }
                iVar7 = nvswitch_os_is_admin();
                if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                  return 0xfffffff1;
                }
                pcVar8 = (code *)param_1[0xc3];
              }
              else {
                if (param_4 != 0x810) {
                  return 0xffffffff;
                }
                pcVar8 = (code *)param_1[0xd3];
              }
            }
          }
          else if (param_2 == 0x2b) {
            if (param_4 != 0xe08) {
              return 0xffffffff;
            }
            iVar7 = nvswitch_os_is_admin();
            if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
              return 0xfffffff1;
            }
            pcVar8 = (code *)param_1[0xf3];
          }
          else if (param_2 < 0x2c) {
            if (param_2 == 0x28) {
              if (param_4 != 0x1ec) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              pcVar8 = (code *)param_1[0x19c];
            }
            else if (param_2 < 0x29) {
              if (param_2 == 0x26) {
                if (param_4 != 0x10) {
                  return 0xffffffff;
                }
                iVar7 = nvswitch_os_is_admin();
                if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                  return 0xfffffff1;
                }
                pcVar8 = (code *)param_1[0x11b];
              }
              else {
                if (param_4 != 0x41) {
                  return 0xffffffff;
                }
                pcVar8 = (code *)param_1[0x11c];
              }
            }
            else if (param_2 == 0x29) {
              if (param_4 != 0x1ec) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              pcVar8 = (code *)param_1[0x19d];
            }
            else {
              if (param_4 != 0x110) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              pcVar8 = (code *)param_1[0xb6];
            }
          }
          else {
            if (param_2 == 0x2e) {
              if (param_4 != 0xc4) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              uVar11 = nvswitch_inforom_nvlink_get_max_correctable_error_rate(param_1,param_3);
              return uVar11;
            }
            if (0x2e < param_2) {
              if (param_2 == 0x2f) {
                if (param_4 != 0xc08) {
                  return 0xffffffff;
                }
                iVar7 = nvswitch_os_is_admin();
                if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                  return 0xfffffff1;
                }
                uVar11 = nvswitch_inforom_nvlink_get_errors(param_1,param_3);
                return uVar11;
              }
              if (param_4 != 0xe18) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              uVar11 = nvswitch_inforom_ecc_get_errors(param_1,param_3);
              return uVar11;
            }
            if (param_2 == 0x2c) {
              if (param_4 != 0x10) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if (iVar7 != 0) {
                uVar3 = *(uint *)((long)param_3 + 4);
                uVar11 = (*(code *)param_1[0xcd])(param_1);
                uVar16 = 0;
                if (((*(int *)((long)param_1 + 0xbc) == 1) || ((uVar11 & 2) != 0)) &&
                   ((uVar11 & 1) != 0)) {
                  bVar19 = (byte)param_3[1];
                  if (bVar19 == 2) {
                    uVar16 = *(undefined1 *)((long)param_3 + 10);
                    if (*(char *)((long)param_3 + 9) == '\0') {
                      bVar19 = 3;
                    }
                    piVar15 = (int *)((long)param_3 + 0xb);
                    uVar14 = 1;
                  }
                  else if (bVar19 < 3) {
                    if (bVar19 == 0) {
                      uVar16 = 0;
                      if (*(char *)((long)param_3 + 9) == '\0') {
                        piVar15 = (int *)0x0;
                        bVar19 = 5;
                        uVar14 = 0;
                      }
                      else {
                        uVar14 = 0;
                        piVar15 = (int *)0x0;
                        bVar19 = 4;
                      }
                    }
                    else {
                      bVar19 = *(char *)((long)param_3 + 9) == '\0';
                      piVar15 = (int *)((long)param_3 + 10);
                      uVar14 = 1;
                    }
                  }
                  else {
                    if (bVar19 != 3) {
                      return 1;
                    }
                    uVar16 = *(undefined1 *)((long)param_3 + 10);
                    if (*(char *)((long)param_3 + 9) != '\0') {
                      bVar19 = 2;
                    }
                    piVar15 = (int *)((long)param_3 + 0xc);
                    uVar14 = 2;
                  }
                  uVar3 = _nvswitch_perform_i2c_transfer
                                    (param_1,2,bVar19,(short)*param_3,uVar3 & 0xff,uVar16,uVar14,
                                     piVar15);
                  return (ulong)uVar3;
                }
                return 1;
              }
              return 0xfffffff1;
            }
            if (param_4 != 8) {
              return 0xffffffff;
            }
            pcVar8 = (code *)param_1[0xd2];
          }
          goto LAB_00259814;
        }
        if (param_2 == 0xd) {
          if (param_4 != 0x1010) {
            return 0xffffffff;
          }
          iVar7 = nvswitch_os_is_admin();
          if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
            return 0xfffffff1;
          }
          pcVar8 = (code *)param_1[0xc1];
          goto LAB_00259814;
        }
        if (0xd < param_2) {
          if (param_2 == 0x13) {
            if (param_4 != 4) {
              return 0xffffffff;
            }
            iVar7 = nvswitch_os_is_admin();
            if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
              return 0xfffffff1;
            }
            local_40[0] = 0;
            nvlink_lib_get_link(*param_1,(char)*param_3,local_40);
            lVar9 = local_40[0];
            if (local_40[0] == 0) {
              return 0xffffffff;
            }
            if ((*(char *)(*param_1 + 0xb1) == '\0') &&
               (cVar2 = (*(code *)param_1[0xb2])(param_1,(int)*param_3), cVar2 != '\0')) {
              return 0xfffffff4;
            }
            nvlink_lib_unregister_link(lVar9);
            if (*(long *)(lVar9 + 0x98) != 0) {
              nvswitch_os_free();
            }
            nvswitch_os_free(lVar9);
            return 0;
          }
          if (param_2 < 0x14) {
            if (param_2 == 0x10) {
              if (param_4 != 0x1c10) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              pcVar8 = (code *)param_1[0xb9];
            }
            else if (param_2 < 0x11) {
              if (param_2 == 0xe) {
                if (param_4 != 0x220c) {
                  return 0xffffffff;
                }
                iVar7 = nvswitch_os_is_admin();
                if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                  return 0xfffffff1;
                }
                pcVar8 = (code *)param_1[0xc4];
              }
              else {
                if (param_4 != 0x220c) {
                  return 0xffffffff;
                }
                iVar7 = nvswitch_os_is_admin();
                if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                  return 0xfffffff1;
                }
                pcVar8 = (code *)param_1[199];
              }
            }
            else if (param_2 == 0x11) {
              if (param_4 != 0x1810) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              pcVar8 = (code *)param_1[0xbc];
            }
            else {
              if (param_4 != 8) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              pcVar8 = (code *)param_1[0xcc];
            }
          }
          else if (param_2 == 0x16) {
            if (param_4 != 0x4c) {
              return 0xffffffff;
            }
            iVar7 = nvswitch_os_is_admin();
            if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
              return 0xfffffff1;
            }
            pcVar8 = (code *)param_1[0xc9];
          }
          else if (param_2 < 0x17) {
            if (param_2 == 0x14) {
              if (param_4 != 8) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              uVar11 = (*(code *)param_1[0xb3])(param_1,*param_3,0);
              return uVar11;
            }
            if (param_4 != 0x2310) {
              return 0xffffffff;
            }
            iVar7 = nvswitch_os_is_admin();
            if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
              return 0xfffffff1;
            }
            pcVar8 = (code *)param_1[200];
          }
          else {
            if (param_2 != 0x17) {
              if (param_4 != 0x10) {
                return 0xffffffff;
              }
              uVar11 = nvswitch_os_acquire_fabric_mgmt_cap(param_5,*param_3);
              return uVar11;
            }
            if (param_4 != 0x2e08) {
              return 0xffffffff;
            }
            pcVar8 = (code *)param_1[0xb5];
          }
          goto LAB_00259814;
        }
        if (param_2 == 7) {
          if (param_4 != 0xa10) {
            return 0xffffffff;
          }
          pcVar8 = (code *)param_1[0xca];
          goto LAB_00259814;
        }
        if (7 < param_2) {
          if (param_2 != 10) {
            if (param_2 < 0xb) {
              if (param_2 != 8) {
                if (param_4 != 0x800) {
                  return 0xffffffff;
                }
                return 0xfffffff3;
              }
              if (param_4 != 0x60) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              pcVar8 = (code *)param_1[0xcb];
              goto LAB_00259814;
            }
            if (param_2 != 0xb) {
              if (param_4 != 0x2a20) {
                return 0xffffffff;
              }
              uVar11 = nvswitch_ctrl_get_errors(param_1,param_3);
              return uVar11;
            }
          }
          if (param_4 != 0xa8) {
            return 0xffffffff;
          }
          iVar7 = nvswitch_os_is_admin();
          if (iVar7 != 0) {
            return 0xfffffff3;
          }
          iVar7 = nvswitch_os_is_fabric_manager(param_5);
          return (ulong)((-(uint)(iVar7 == 0) & 0xfffffffe) - 0xd);
        }
        if (param_2 == 4) {
          if (param_4 != 0x10c) {
            return 0xffffffff;
          }
          iVar7 = nvswitch_os_is_admin();
          if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
            return 0xfffffff1;
          }
          pcVar8 = (code *)param_1[0xbb];
          goto LAB_00259814;
        }
        if (4 < param_2) {
          if (param_2 == 5) {
            if (param_4 != 0x140c) {
              return 0xffffffff;
            }
            iVar7 = nvswitch_os_is_admin();
            if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
              return 0xfffffff1;
            }
            pcVar8 = (code *)param_1[0xbd];
          }
          else {
            if (param_4 != 0x404) {
              return 0xffffffff;
            }
            iVar7 = nvswitch_os_is_admin();
            if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
              return 0xfffffff1;
            }
            pcVar8 = (code *)param_1[0xbe];
          }
          goto LAB_00259814;
        }
        if (param_2 == 2) {
          if (param_4 != 0x20) {
            return 0xffffffff;
          }
          iVar7 = nvswitch_os_is_admin();
          if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
            return 0xfffffff1;
          }
          pcVar8 = (code *)param_1[0xb7];
          goto LAB_00259814;
        }
        if (param_2 == 3) {
          if (param_4 != 0x180c) {
            return 0xffffffff;
          }
          iVar7 = nvswitch_os_is_admin();
          if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
            return 0xfffffff1;
          }
          pcVar8 = (code *)param_1[0xba];
          goto LAB_00259814;
        }
        if (param_2 == 1) {
          if (param_4 != 0x104) {
            return 0xffffffff;
          }
          pcVar8 = (code *)param_1[0xb4];
          goto LAB_00259814;
        }
      }
      else {
        if (param_2 == 0x4f) {
          if (param_4 != 0x10) {
            return 0xffffffff;
          }
          pcVar8 = (code *)param_1[0x102];
          goto LAB_00259814;
        }
        if (param_2 < 0x50) {
          if (param_2 == 0x3d) {
            if (param_4 != 0x14) {
              return 0xffffffff;
            }
            pcVar8 = (code *)param_1[0x1a1];
            goto LAB_00259814;
          }
          if (param_2 < 0x3e) {
            if (param_2 == 0x37) {
              if (param_4 != 0x18) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              nvswitch_os_memset(param_3,0,0x18);
              if (param_1[0x1a5] == 0) {
                return 0;
              }
              cciGetXcvrMask(param_1,param_3,(int *)((long)param_3 + 4));
              return 0;
            }
            if (0x37 < param_2) {
              if (param_2 == 0x3a) {
                if (param_4 != 0x98) {
                  return 0xffffffff;
                }
                iVar7 = nvswitch_os_is_admin();
                if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                  return 0xfffffff1;
                }
                if (param_1[0x1a5] == 0) {
                  return 0xfffffff3;
                }
                uVar14 = 0x25a804;
                cVar2 = cciCmisAccessTryLock(param_1,(char)*param_3);
                if (cVar2 == '\0') {
                  return 0xfffffff4;
                }
                uVar3 = cciCmisWrite(param_1,(char)*param_3,*(undefined1 *)((long)param_3 + 1),
                                     *(undefined1 *)((long)param_3 + 2),
                                     *(undefined1 *)((long)param_3 + 3),
                                     *(undefined1 *)((long)param_3 + 4),(long)param_3 + 5);
                cVar2 = *(char *)((long)param_3 + 0x85);
              }
              else {
                if (0x3a < param_2) {
                  if (param_2 == 0x3b) {
                    if (param_4 != 0x34) {
                      return 0xffffffff;
                    }
                    iVar7 = nvswitch_os_is_admin();
                    if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)
                       ) {
                      return 0xfffffff1;
                    }
                    if (param_1[0x1a5] == 0) {
                      return 0xfffffff3;
                    }
                    uVar11 = cciCmisCageBezelMarking(param_1,(char)*param_3,(long)param_3 + 1);
                    return uVar11;
                  }
                  if (param_4 != 0x28) {
                    return 0xffffffff;
                  }
                  iVar7 = nvswitch_os_is_admin();
                  if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0))
                  {
                    return 0xfffffff1;
                  }
                  uVar11 = nvswitch_ctrl_get_grading_values(param_1,param_3);
                  return uVar11;
                }
                if (param_2 == 0x38) {
                  if (param_4 != 0x28) {
                    return 0xffffffff;
                  }
                  iVar7 = nvswitch_os_is_admin();
                  if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0))
                  {
                    return 0xfffffff1;
                  }
                  if (param_1[0x1a5] == 0) {
                    return 0xfffffff3;
                  }
                  uVar11 = cciGetCageMapping(param_1,(char)*param_3,param_3 + 1,param_3 + 2);
                  return uVar11;
                }
                if (param_4 != 0x98) {
                  return 0xffffffff;
                }
                iVar7 = nvswitch_os_is_admin();
                if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                  return 0xfffffff1;
                }
                if (param_1[0x1a5] == 0) {
                  return 0xfffffff3;
                }
                cVar2 = cciCmisAccessTryLock(param_1,(char)*param_3);
                if (cVar2 == '\0') {
                  return 0xfffffff4;
                }
                uVar3 = cciCmisRead(param_1,(char)*param_3,*(undefined1 *)((long)param_3 + 1),
                                    *(undefined1 *)((long)param_3 + 2),
                                    *(undefined1 *)((long)param_3 + 3),
                                    *(undefined1 *)((long)param_3 + 4),(long)param_3 + 5);
                cVar2 = *(char *)((long)param_3 + 0x85);
                uVar14 = extraout_RDX;
              }
              if (cVar2 == '\0') {
                cciCmisAccessReleaseLock(param_1,(char)*param_3,uVar14);
                return (ulong)uVar3;
              }
              return (ulong)uVar3;
            }
            if (param_2 == 0x34) {
              if (param_4 != 0xc) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              pcVar8 = (code *)param_1[0x19e];
            }
            else if (param_2 < 0x35) {
              if (param_2 == 0x32) {
                if (param_4 != 0x10) {
                  return 0xffffffff;
                }
                iVar7 = nvswitch_os_is_admin();
                if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                  return 0xfffffff1;
                }
                pcVar8 = (code *)param_1[0xe3];
              }
              else {
                if (param_4 != 0x20) {
                  return 0xffffffff;
                }
                iVar7 = nvswitch_os_is_admin();
                if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                  return 0xfffffff1;
                }
                pcVar8 = (code *)param_1[0x14d];
              }
            }
            else if (param_2 == 0x35) {
              if (param_4 != 0xc10) {
                return 0xffffffff;
              }
              pcVar8 = (code *)param_1[0x19f];
            }
            else {
              if (param_4 != 0x38) {
                return 0xffffffff;
              }
              pcVar8 = (code *)param_1[0x1a0];
            }
            goto LAB_00259814;
          }
          if (param_2 == 0x47) {
            if (param_4 != 0x104) {
              return 0xffffffff;
            }
            iVar7 = nvswitch_os_is_admin();
            if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
              return 0xfffffff1;
            }
            pcVar8 = (code *)param_1[0x151];
            goto LAB_00259814;
          }
          if (param_2 < 0x48) {
            if (param_2 == 0x44) {
              if (param_4 != 0x1408) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              pcVar8 = (code *)param_1[0x199];
              goto LAB_00259814;
            }
            if (0x44 < param_2) {
              if (param_2 == 0x45) {
                if (param_4 != 8) {
                  return 0xffffffff;
                }
                iVar7 = nvswitch_os_is_admin();
                if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                  return 0xfffffff1;
                }
                if (*param_3 == 0) {
                  return 0;
                }
                _nvswitch_ctrl_inband_flush_data_part_0(param_1,param_3);
                return 0;
              }
              if (param_4 != 8) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              uVar11 = 0;
              uVar18 = 0;
              uVar17 = 0;
              uVar12 = nvswitch_get_enabled_link_mask(param_1);
              while( true ) {
                uVar3 = (*(code *)param_1[0xa2])(param_1);
                if (uVar3 <= (uint)uVar17) break;
                cVar2 = (*(code *)param_1[0xa4])(param_1,uVar17);
                if ((cVar2 != '\0') && ((uVar12 >> (uVar17 & 0x3f) & 1) != 0)) {
                  uVar13 = 1L << ((byte)uVar17 & 0x3f);
                  if ((long *)param_1[uVar17 * 8 + 0x1f0] != param_1 + (uVar17 + 0x3e) * 8) {
                    uVar18 = uVar18 | uVar13;
                  }
                  if ((long *)(param_1 + (uVar17 + 0x3e) * 8)[2] !=
                      param_1 + (uVar17 + 0x3e) * 8 + 2) {
                    uVar11 = uVar13 | uVar11;
                  }
                }
                uVar17 = (ulong)((uint)uVar17 + 1);
              }
              if (uVar18 != 0) {
                uVar11 = uVar18;
              }
              *param_3 = uVar11;
              return 0;
            }
            if (param_2 == 0x3e) {
              if (param_4 != 0x14) {
                return 0xffffffff;
              }
              pcVar8 = (code *)param_1[0x1a2];
              goto LAB_00259814;
            }
            if (param_2 == 0x43) {
              if (param_4 != 0x140c) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              pcVar8 = (code *)param_1[0x198];
              goto LAB_00259814;
            }
          }
          else {
            if (param_2 == 0x4c) {
              if (param_4 != 3) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              uVar11 = nvswitch_ctrl_set_locate_led(param_1,param_3);
              return uVar11;
            }
            if (0x4c < param_2) {
              if (param_2 == 0x4d) {
                if (param_4 != 0x10) {
                  return 0xffffffff;
                }
                iVar7 = nvswitch_os_is_admin();
                if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                  return 0xfffffff1;
                }
                pcVar8 = (code *)param_1[0xce];
              }
              else {
                if (param_4 != 0x14) {
                  return 0xffffffff;
                }
                iVar7 = nvswitch_os_is_admin();
                if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                  return 0xfffffff1;
                }
                pcVar8 = (code *)param_1[0xcf];
              }
              goto LAB_00259814;
            }
            if (param_2 == 0x4a) {
              if (param_4 != 2) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              uVar11 = nvswitch_ctrl_get_ports_cpld_info(param_1,param_3);
              return uVar11;
            }
            if (param_2 == 0x4b) {
              if (param_4 != 0x18) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              uVar11 = nvswitch_ctrl_get_cci_fw_revisions(param_1,param_3);
              return uVar11;
            }
          }
        }
        else {
          if (param_2 == 0x61) {
            if (param_4 != 0x7c4) {
              return 0xffffffff;
            }
            iVar7 = nvswitch_os_is_admin();
            if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
              return 0xfffffff1;
            }
            uVar14 = 4;
            goto LAB_0025a15f;
          }
          if (param_2 < 0x62) {
            if (param_2 == 0x55) {
              if (param_4 != 0x10) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              pcVar8 = (code *)param_1[0x193];
              goto LAB_00259814;
            }
            if (param_2 < 0x56) {
              if (param_2 == 0x52) {
                if (param_4 != 0x308) {
                  return 0xffffffff;
                }
                iVar7 = nvswitch_os_is_admin();
                if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                  return 0xfffffff1;
                }
                pcVar8 = (code *)param_1[0x154];
              }
              else if (param_2 < 0x53) {
                if (param_2 == 0x50) {
                  if (param_4 != 0xd08) {
                    return 0xffffffff;
                  }
                  iVar7 = nvswitch_os_is_admin();
                  if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0))
                  {
                    return 0xfffffff1;
                  }
                  pcVar8 = (code *)param_1[0x152];
                }
                else {
                  if (param_4 != 0x10) {
                    return 0xffffffff;
                  }
                  iVar7 = nvswitch_os_is_admin();
                  if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0))
                  {
                    return 0xfffffff1;
                  }
                  pcVar8 = (code *)param_1[0x153];
                }
              }
              else if (param_2 == 0x53) {
                if (param_4 != 0x308) {
                  return 0xffffffff;
                }
                pcVar8 = (code *)param_1[0x155];
              }
              else {
                if (param_4 != 0xc) {
                  return 0xffffffff;
                }
                pcVar8 = (code *)param_1[0x157];
              }
              goto LAB_00259814;
            }
            if (param_2 == 0x58) {
              if (param_4 != 0x418) {
                return 0xffffffff;
              }
              uVar11 = nvswitch_ctrl_get_port_events(param_1,param_3);
              return uVar11;
            }
            if (param_2 < 0x59) {
              if (param_2 == 0x56) {
                if (param_4 != 0x14) {
                  return 0xffffffff;
                }
                if (((*(char *)((long)param_1 + 0x25) != '\0') ||
                    (*(char *)((long)param_1 + 0x24) != '\0')) ||
                   (*(char *)((long)param_1 + 0x26) != '\0')) {
                  nvswitch_os_memset(param_3,0,0x14);
                  return 0;
                }
                cVar2 = (*(code *)param_1[0xe7])(param_1);
                if (cVar2 == '\0') {
                  return 0xfffffff3;
                }
                pcVar8 = (code *)param_1[0x156];
              }
              else {
                if (param_4 != 0xc) {
                  return 0xffffffff;
                }
                pcVar8 = (code *)param_1[0x159];
              }
              goto LAB_00259814;
            }
            if (param_2 == 0x59) {
              if (param_4 != 0x14) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              uVar14 = 2;
LAB_0025a15f:
              uVar11 = nvswitch_inforom_bbx_get_data(param_1,uVar14,param_3);
              return uVar11;
            }
            if (param_2 == 0x60) {
              if (param_4 != 0x14) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              uVar14 = 3;
              goto LAB_0025a15f;
            }
          }
          else {
            if (param_2 == 0x67) {
              if (param_4 != 0x108) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              uVar11 = _nvswitch_ctrl_set_link_l1_threshold(param_1,param_3);
              return uVar11;
            }
            if (param_2 < 0x68) {
              if (param_2 == 100) {
                if (param_4 != 0x10) {
                  return 0xffffffff;
                }
                iVar7 = nvswitch_os_is_admin();
                if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                  return 0xfffffff1;
                }
                if ((char)param_1[0x1eb] != '\0') {
                  return 0xfffffff8;
                }
                uVar11 = nvswitch_get_enabled_link_mask(param_1);
                uVar11 = uVar11 & param_3[1];
                param_3[1] = uVar11;
                if (uVar11 == 0) {
LAB_0025b34a:
                  nvswitch_ctrl_cci_request_ali(param_1,param_3);
                  return 0;
                }
                iVar7 = 0;
                do {
                  if ((uVar11 & 1) != 0) {
                    cVar2 = cciIsLinkManaged(param_1,iVar7);
                    if (cVar2 == '\0') {
                      local_40[0] = 0;
                      nvlink_lib_get_link(*param_1,iVar7,local_40);
                      lVar9 = local_40[0];
                      if (local_40[0] != 0) {
                        pcVar8 = (code *)param_1[0x122];
                        uVar5 = (*(code *)param_1[0x127])(param_1,iVar7,9);
                        iVar6 = (*pcVar8)(param_1,9,0,uVar5,pcVar8);
                        if ((((iVar6 != -1) &&
                             (cVar2 = (*(code *)param_1[0xa4])(param_1,iVar7), cVar2 != '\0')) &&
                            (iVar6 = (*(code *)param_1[0xd9])(lVar9,&local_48), iVar6 == 0)) &&
                           (CONCAT71(uStack_47,local_48) != 0x1d)) {
                          (*(code *)param_1[0xb3])(param_1,1L << ((byte)iVar7 & 0x3f),1);
                        }
                      }
                    }
                    if (uVar11 >> 1 == 0) goto LAB_0025b34a;
                  }
                  uVar11 = uVar11 >> 1;
                  iVar7 = iVar7 + 1;
                } while( true );
              }
              if (100 < param_2) {
                if (param_2 == 0x65) {
                  if (param_4 != 0x48) {
                    return 0xffffffff;
                  }
                  uVar11 = _nvswitch_ctrl_get_link_l1_capability(param_1,param_3);
                  return uVar11;
                }
                if (param_4 != 0x108) {
                  return 0xffffffff;
                }
                uVar11 = _nvswitch_ctrl_get_link_l1_threshold(param_1,param_3);
                return uVar11;
              }
              if (param_2 != 0x62) {
                if (param_4 != 1) {
                  return 0xffffffff;
                }
                iVar7 = nvswitch_os_is_admin();
                if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                  return 0xfffffff1;
                }
                *(char *)(param_1 + 0x1eb) = (char)*param_3;
                return 0;
              }
              if (param_4 != 0x2264) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              uVar14 = 5;
              goto LAB_0025a15f;
            }
            if (param_2 == 0x6a) {
              if (param_4 != 0x1404) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              pcVar8 = (code *)param_1[0x176];
              goto LAB_00259814;
            }
            if (param_2 < 0x6b) {
              if (param_2 != 0x68) {
                if (param_4 != 4) {
                  return 0xffffffff;
                }
                iVar7 = nvswitch_os_is_admin();
                if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                  return 0xfffffff1;
                }
                if (*(long *)(*param_1 + 0xa8) != 3) {
                  return 0xffffffff;
                }
                if (*(long *)(*param_1 + 0x78) == 0) {
                  return 0xffffffff;
                }
                cVar2 = (*(code *)param_1[0x174])(param_1);
                if (cVar2 == '\0') {
                  return 0xfffffff3;
                }
                if ((int)param_1[0x3f6] != 2) {
                  return 0xfffffff8;
                }
                (*(code *)param_1[0x17b])(param_1);
                uVar3 = (*(code *)param_1[0x17a])(param_1);
                if (uVar3 == 0) {
                  uVar3 = (*(code *)param_1[0x178])(param_1);
                  *(uint *)((long)param_1 + 0x1fec) = (uVar3 == 0) + 2;
                  return (ulong)uVar3;
                }
                return (ulong)uVar3;
              }
              if (param_4 != 0xc) {
                return 0xffffffff;
              }
              pcVar8 = (code *)param_1[0x171];
              goto LAB_00259814;
            }
            if (param_2 == 0x6b) {
              if (param_4 != 0x2024) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              pcVar8 = (code *)param_1[0x177];
              goto LAB_00259814;
            }
            if (param_2 == 0x6c) {
              if (param_4 != 4) {
                return 0xffffffff;
              }
              iVar7 = nvswitch_os_is_admin();
              if ((iVar7 == 0) && (iVar7 = nvswitch_os_is_fabric_manager(param_5), iVar7 == 0)) {
                return 0xfffffff1;
              }
              pcVar8 = (code *)param_1[0x179];
              goto LAB_00259814;
            }
          }
        }
      }
      nvswitch_os_print(2,"unknown ioctl %x\n",param_2);
    }
  }
  return 0xffffffff;
}


// ===== 0025b450 nvswitch_assert_log =====

void nvswitch_assert_log(void)

{
  nvswitch_os_assert_log("NVSwitch: Assertion failed\n");
  return;
}


// ===== 0025b470 nvswitch_i2c_init =====

void nvswitch_i2c_init(long param_1)

{
  long lVar1;
  
  lVar1 = nvswitch_os_malloc_trace(0x1a8,0,0);
  if (lVar1 != 0) {
    nvswitch_os_memset(lVar1,0,0x1a8);
  }
  *(long *)(param_1 + 0xf48) = lVar1;
  return;
}


// ===== 0025b4b0 nvswitch_i2c_destroy =====

void nvswitch_i2c_destroy(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xf48);
  if (lVar1 != 0) {
    if (*(char *)(lVar1 + 0x194) != '\0') {
      nvswitch_os_unmap_dma_region
                (*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(lVar1 + 0x198),
                 *(undefined8 *)(lVar1 + 0x1a0),0x200,2);
      nvswitch_os_free_contig_memory
                (*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(*(long *)(param_1 + 0xf48) + 0x198)
                 ,0x200);
      *(undefined8 *)(*(long *)(param_1 + 0xf48) + 0x198) = 0;
      *(undefined8 *)(*(long *)(param_1 + 0xf48) + 0x1a0) = 0;
      lVar1 = *(long *)(param_1 + 0xf48);
    }
    nvswitch_os_free(lVar1);
    *(undefined8 *)(param_1 + 0xf48) = 0;
    return;
  }
  return;
}


