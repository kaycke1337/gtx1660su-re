// ===== 001b8610 cciResetModule =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void cciResetModule(long param_1,byte param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 1 << (param_2 & 0x1f);
  iVar1 = (**(code **)(param_1 + 0xc28))(param_1,4,uVar2 & 0xff);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(param_1 + 0xc28))(param_1,5,uVar2 >> 8 & 0xff);
    if (iVar1 == 0) {
      nvswitch_os_sleep(1);
      iVar1 = (**(code **)(param_1 + 0xc28))(param_1,4,0);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(param_1 + 0xc28))(param_1,5,0);
        if (iVar1 == 0) {
          cciSetLPMode(param_1,param_2,1);
          return;
        }
      }
    }
  }
  return;
}


// ===== 001b86d0 cciCheckLPMode =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

bool cciCheckLPMode(long param_1,byte param_2)

{
  int iVar1;
  byte local_1a;
  byte local_19;
  
  iVar1 = (**(code **)(param_1 + 0xc20))(param_1,10,&local_1a);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(param_1 + 0xc20))(param_1,0xb,&local_19);
    if (iVar1 == 0) {
      return (local_19 & (byte)((uint)(1 << (param_2 & 0x1f)) >> 8)) != 0 ||
             (local_1a >> (param_2 & 0x1f) & 1) != 0;
    }
  }
  return false;
}


// ===== 001b8760 cciGetAllLinks =====

void cciGetAllLinks(long param_1,ulong *param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  ulong uVar4;
  byte *pbVar5;
  
  uVar2 = *(uint *)(*(long *)(param_1 + 0xd28) + 0x30);
  if (uVar2 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0;
    pbVar3 = (byte *)(*(long *)(*(long *)(param_1 + 0xd28) + 0x20) + 1);
    pbVar5 = pbVar3 + (ulong)uVar2 * 3;
    do {
      bVar1 = *pbVar3;
      pbVar3 = pbVar3 + 3;
      uVar4 = uVar4 | 1L << (bVar1 & 0x3f);
    } while (pbVar3 != pbVar5);
  }
  if (param_2 != (ulong *)0x0) {
    *param_2 = uVar4;
  }
  return;
}


// ===== 001b87d0 cciCheckXcvrForLinkTraffic =====

uint cciCheckXcvrForLinkTraffic(long param_1,undefined8 param_2,ulong param_3)

{
  ulong uVar1;
  int iVar2;
  undefined2 *puVar3;
  ulong uVar4;
  long *plVar5;
  long lVar6;
  ulong uVar7;
  uint uVar8;
  
  puVar3 = (undefined2 *)nvswitch_os_malloc_trace(0x810,0,0);
  if (puVar3 != (undefined2 *)0x0) {
    *(ulong *)(puVar3 + 4) = param_3;
    *puVar3 = 3;
    iVar2 = nvswitch_ctrl_get_throughput_counters(param_1,puVar3);
    if ((iVar2 == 0) && (param_3 != 0)) {
      lVar6 = *(long *)(param_1 + 0xd28);
      plVar5 = (long *)(puVar3 + 0xc);
      uVar7 = 0;
      uVar8 = 0;
      do {
        if ((param_3 & 1) != 0) {
          uVar4 = plVar5[1] + *plVar5;
          uVar1 = *(ulong *)(lVar6 + (uVar7 + 0x16) * 8);
          *(ulong *)(lVar6 + (uVar7 + 0x16) * 8) = uVar4;
          lVar6 = *(long *)(param_1 + 0xd28);
          uVar8 = uVar8 | (uint)CONCAT71((int7)(uVar4 >> 8),uVar1 < uVar4) &
                          CONCAT31((int3)((uint)*(int *)(lVar6 + 0x68) >> 8),
                                   *(int *)(lVar6 + 0x68) != 0);
          if (param_3 >> 1 == 0) goto LAB_001b8883;
        }
        param_3 = param_3 >> 1;
        uVar7 = (ulong)((int)uVar7 + 1);
        plVar5 = plVar5 + 4;
      } while( true );
    }
  }
  uVar8 = 0;
LAB_001b8883:
  nvswitch_os_free(puVar3);
  return uVar8;
}


// ===== 001b88a0 cciGetLaneMask =====

undefined8 cciGetLaneMask(long param_1,uint param_2,undefined1 *param_3)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  
  uVar1 = *(uint *)(*(long *)(param_1 + 0xd28) + 0x30);
  if (uVar1 != 0) {
    lVar2 = *(long *)(*(long *)(param_1 + 0xd28) + 0x20);
    lVar3 = (ulong)uVar1 * 3 + lVar2;
    do {
      if (*(byte *)(lVar2 + 1) == param_2) {
        *param_3 = *(undefined1 *)(lVar2 + 2);
        return 0;
      }
      lVar2 = lVar2 + 3;
    } while (lVar2 != lVar3);
  }
  return 0xfffffffd;
}


// ===== 001b8910 cciSetModulePower =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void cciSetModulePower(long param_1,uint param_2,char param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte local_29 [9];
  
  if (param_2 < 8) {
    iVar1 = (**(code **)(param_1 + 0xc20))(param_1,0xc,local_29);
    if (iVar1 == 0) {
      uVar2 = 1 << ((byte)param_2 & 0x1f);
      uVar3 = (uint)(~(byte)uVar2 & local_29[0]);
      if (param_3 != '\0') {
        uVar3 = local_29[0] | uVar2;
      }
      local_29[0] = (byte)uVar3;
      (**(code **)(param_1 + 0xc28))(param_1,0xc,uVar3 & 0xff);
    }
  }
  else {
    iVar1 = (**(code **)(param_1 + 0xc20))(param_1,0xd,local_29);
    if (iVar1 == 0) {
      uVar2 = 1 << ((byte)param_2 - 8 & 0x1f);
      uVar3 = (uint)(~(byte)uVar2 & local_29[0]);
      if (param_3 != '\0') {
        uVar3 = local_29[0] | uVar2;
      }
      local_29[0] = (byte)uVar3;
      (**(code **)(param_1 + 0xc28))(param_1,0xd,uVar3 & 0xff);
      return;
    }
  }
  return;
}


// ===== 001b89e0 cciModuleHWGood =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint cciModuleHWGood(long param_1,uint param_2)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  
  cVar2 = _cciCheckModuleFault();
  if (cVar2 == '\0') {
    return 1;
  }
  cciSetModulePower(param_1,param_2,0);
  nvswitch_os_sleep(1);
  cciSetModulePower(param_1,param_2,1);
  if (param_2 < 8) {
    bVar1 = (byte)param_2 & 0x1f;
    (**(code **)(param_1 + 0xc28))(param_1,0x29,(-2 << bVar1 | 0xfffffffeU >> 0x20 - bVar1) & 0xff);
  }
  else {
    bVar1 = (byte)param_2 - 8 & 0x1f;
    (**(code **)(param_1 + 0xc28))(param_1,0x2a,(-2 << bVar1 | 0xfffffffeU >> 0x20 - bVar1) & 0xff);
  }
  nvswitch_os_sleep(1);
  uVar3 = _cciCheckModuleFault(param_1,param_2);
  return uVar3 ^ 1;
}


// ===== 001b8aa0 nvswitch_construct_error_log =====

int nvswitch_construct_error_log(undefined8 *param_1,uint param_2,undefined1 param_3)

{
  long lVar1;
  
  if (param_1 == (undefined8 *)0x0) {
    nvswitch_assert_log();
  }
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = 0;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 4) = param_3;
  if (param_2 == 0) {
    return 0;
  }
  lVar1 = nvswitch_os_malloc_trace((ulong)param_2 * 0xd8,0,0);
  param_1[3] = lVar1;
  if (lVar1 != 0) {
    *(uint *)(param_1 + 2) = param_2;
    nvswitch_os_memset(lVar1,0,(ulong)param_2 * 0xd8);
  }
  return ((*(uint *)(param_1 + 2) == param_2) - 2) + (uint)(*(uint *)(param_1 + 2) == param_2);
}


// ===== 001b8b60 nvswitch_destroy_error_log =====

void nvswitch_destroy_error_log(undefined8 param_1,undefined8 *param_2)

{
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
    *(undefined4 *)(param_2 + 2) = 0;
    if (param_2[3] != 0) {
      nvswitch_os_free();
      param_2[3] = 0;
      return;
    }
  }
  return;
}


// ===== 001b8bb0 nvswitch_get_error =====

void nvswitch_get_error(long param_1,int *param_2,undefined4 *param_3,uint param_4,int *param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulong uVar5;
  long lVar7;
  undefined8 *puVar8;
  ulong uVar6;
  
  if (param_2 == (int *)0x0) {
    nvswitch_assert_log();
  }
  if (param_3 != (undefined4 *)0x0) {
    if (param_4 < (uint)param_2[1]) {
      lVar7 = ((ulong)(*param_2 + param_4) % (ulong)(uint)param_2[4]) * 0xd8 +
              *(long *)(param_2 + 6);
      uVar5 = 0;
      do {
        uVar4 = (int)uVar5 + 0x20;
        uVar6 = (ulong)uVar4;
        uVar3 = *(undefined8 *)(lVar7 + 8 + uVar5);
        uVar1 = *(undefined8 *)(lVar7 + 0x10 + uVar5);
        uVar2 = *(undefined8 *)(lVar7 + 0x18 + uVar5);
        *(undefined8 *)((long)param_3 + uVar5) = *(undefined8 *)(lVar7 + uVar5);
        *(undefined8 *)((long)param_3 + uVar5 + 8) = uVar3;
        *(undefined8 *)((long)param_3 + uVar5 + 0x10) = uVar1;
        *(undefined8 *)((long)param_3 + uVar5 + 0x18) = uVar2;
        uVar5 = uVar6;
      } while (uVar4 < 0xc0);
      puVar8 = (undefined8 *)(lVar7 + uVar6);
      *(undefined8 *)((long)param_3 + uVar6) = *puVar8;
      *(undefined8 *)((long)param_3 + uVar6 + 8) = puVar8[1];
      *(undefined8 *)((long)param_3 + uVar6 + 0x10) = puVar8[2];
    }
    else {
      nvswitch_os_memset(param_3,0,0xd8);
      *param_3 = 0;
      *(undefined8 *)(param_3 + 8) = 0;
      *(undefined8 *)(param_3 + 2) = *(undefined8 *)(param_2 + 2);
      if (param_1 == 0) {
        *(undefined8 *)(param_3 + 4) = 0;
        uVar3 = 0;
        *(undefined8 *)(param_3 + 6) = 0;
        *(undefined1 *)(param_3 + 10) = 1;
        param_3[0x10] = 0;
      }
      else {
        uVar3 = *(undefined8 *)(param_1 + 0xf0);
        *(undefined1 *)(param_3 + 10) = 1;
        *(undefined8 *)(param_3 + 6) = 0;
        *(undefined8 *)(param_3 + 4) = uVar3;
        param_3[0x10] = 0;
        uVar3 = nvswitch_hw_counter_read_counter(param_1);
      }
      *(undefined8 *)(param_3 + 0xc) = uVar3;
      uVar3 = nvswitch_os_get_platform_time();
      param_3[0x11] = 0;
      *(undefined8 *)(param_3 + 0xe) = uVar3;
    }
  }
  if (param_5 != (int *)0x0) {
    *param_5 = param_2[1];
  }
  return;
}


// ===== 001b8d40 nvswitch_translate_hw_error =====

undefined8 nvswitch_translate_hw_error(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = 2;
  if (((((((0x2f < param_1 - 11000U) && (uVar1 = 3, 0x33 < param_1 - 12000U)) &&
         (uVar1 = 4, 8 < param_1 - 13000U)) &&
        ((uVar1 = 5, 0x12 < param_1 - 14000U && (uVar1 = 6, 0x14 < param_1 - 15000U)))) &&
       ((uVar1 = 7, 3 < param_1 - 16000U &&
        ((uVar1 = 8, 8 < param_1 - 17000U && (uVar1 = 9, 0x14 < param_1 - 18000U)))))) &&
      (uVar1 = 10, 0x54 < param_1 - 19000U)) &&
     (((((uVar1 = 0xb, 0x26 < param_1 - 20000U && (uVar1 = 0xc, 10 < param_1 - 21000U)) &&
        (uVar1 = 0xe, 10 < param_1 - 10000U)) &&
       (((uVar1 = 0xd, 0xd < param_1 - 22000U && (uVar1 = 0xf, 0x11 < param_1 - 23000U)) &&
        ((uVar1 = 0x10, 10 < param_1 - 24000U &&
         ((uVar1 = 25000, 10 < param_1 - 25000U && (uVar1 = 26000, 8 < param_1 - 26000U)))))))) &&
      ((uVar1 = 27000, 7 < param_1 - 27000U && (uVar1 = 28000, 5 < param_1 - 28000U)))))) {
    uVar1 = 29000;
    if (6 < param_1 - 29000U) {
      uVar1 = 30000;
      if (6 < param_1 - 30000U) {
        nvswitch_assert_log();
        return 1;
      }
    }
  }
  return uVar1;
}


// ===== 001b8ef0 nvswitch_record_error =====

void nvswitch_record_error
               (long *param_1,uint *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
               ,undefined4 param_6,undefined4 param_7,undefined1 param_8,long param_9,uint param_10,
               undefined4 param_11,long param_12)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  uint uVar8;
  long lVar9;
  undefined4 *puVar10;
  
  if (param_12 == 0) {
    uVar8 = 0;
    uVar5 = 0;
  }
  else {
    iVar6 = nvswitch_os_strlen(param_12);
    uVar8 = iVar6 - 2;
    uVar5 = 0x46;
    if (uVar8 < 0x47) {
      uVar5 = uVar8;
    }
  }
  if (param_2 == (uint *)0x0) {
    nvswitch_assert_log();
  }
  if (0x48 < param_10) {
    nvswitch_assert_log();
  }
  uVar1 = param_2[4];
  if ((uVar1 != 0) && (*(long *)(param_2 + 6) != 0)) {
    uVar2 = param_2[1];
    uVar3 = *param_2;
    if (uVar1 == uVar2) {
      if ((char)param_2[8] == '\0') {
        return;
      }
      *param_2 = (uVar3 + 1) % uVar1;
    }
    else {
      param_2[1] = uVar2 + 1;
    }
    lVar9 = ((ulong)(uVar3 + uVar2) % (ulong)uVar1) * 0xd8;
    *(undefined4 *)(*(long *)(param_2 + 6) + lVar9) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 6) + 0x20 + lVar9) = param_4;
    *(undefined4 *)(*(long *)(param_2 + 6) + 0x24 + lVar9) = param_5;
    *(undefined4 *)(*(long *)(param_2 + 6) + 0x18 + lVar9) = param_6;
    *(undefined4 *)(*(long *)(param_2 + 6) + 0x1c + lVar9) = param_7;
    *(undefined1 *)(*(long *)(param_2 + 6) + 0x28 + lVar9) = param_8;
    *(undefined4 *)(*(long *)(param_2 + 6) + 0x40 + lVar9) = param_11;
    *(uint *)(*(long *)(param_2 + 6) + 0x44 + lVar9) = param_10;
    if (uVar8 != 0) {
      nvswitch_os_memcpy(*(long *)(param_2 + 6) + 0x48 + lVar9,param_12 + 1,uVar5);
    }
    lVar4 = *(long *)(param_2 + 6);
    uVar7 = nvswitch_hw_counter_read_counter(param_1);
    *(undefined8 *)(lVar4 + lVar9 + 0x30) = uVar7;
    lVar4 = *(long *)(param_2 + 6);
    uVar7 = nvswitch_os_get_platform_time();
    *(undefined8 *)(lVar4 + lVar9 + 0x38) = uVar7;
    *(undefined8 *)(*(long *)(param_2 + 6) + 8 + lVar9) = *(undefined8 *)(param_2 + 2);
    *(long *)(*(long *)(param_2 + 6) + 0x10 + lVar9) = param_1[0x1e];
    nvswitch_os_memset(*(long *)(param_2 + 6) + 0x90 + lVar9,0,0x48);
    if ((param_9 != 0) && (param_10 != 0)) {
      nvswitch_os_memcpy(*(long *)(param_2 + 6) + 0x90 + lVar9,param_9,param_10);
    }
    puVar10 = (undefined4 *)(lVar9 + *(long *)(param_2 + 6));
    if ((puVar10 != (undefined4 *)0x0) && (puVar10[6] == 1)) {
      iVar6 = nvswitch_translate_hw_error(*puVar10);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar9 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Severity %d Engine instance %02d Sub-engine instance %02d\n"
                        ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),*(undefined1 *)(lVar9 + 0x44),
                        *(undefined1 *)(lVar9 + 0x45),*(undefined1 *)(lVar9 + 0x46),*puVar10,
                        puVar10[7],puVar10[8],puVar10[9]);
      nvswitch_os_report_error
                (param_1[3],*puVar10,"Severity %d Engine instance %02d Sub-engine instance %02d\n",
                 puVar10[7],puVar10[8],puVar10[9]);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,*puVar10,"Severity %d Engine instance %02d Sub-engine instance %02d\n",
                 puVar10[7],puVar10[8],puVar10[9]);
      iVar6 = nvswitch_translate_hw_error(*puVar10);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar9 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Data {0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x}\n"
                        ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),*(undefined1 *)(lVar9 + 0x44),
                        *(undefined1 *)(lVar9 + 0x45),*(undefined1 *)(lVar9 + 0x46),*puVar10,
                        puVar10[0x24],puVar10[0x25],puVar10[0x26],puVar10[0x27],puVar10[0x28],
                        puVar10[0x29],puVar10[0x2a],puVar10[0x2b],puVar10[0x2c]);
      nvswitch_os_report_error
                (param_1[3],*puVar10,
                 "Data {0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x}\n",
                 puVar10[0x24],puVar10[0x25],puVar10[0x26],puVar10[0x27],puVar10[0x28],puVar10[0x29]
                 ,puVar10[0x2a],puVar10[0x2b],puVar10[0x2c]);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,*puVar10,
                 "Data {0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x}\n",
                 puVar10[0x24],puVar10[0x25],puVar10[0x26],puVar10[0x27],puVar10[0x28],puVar10[0x29]
                 ,puVar10[0x2a],puVar10[0x2b],puVar10[0x2c]);
      if (((((puVar10[0x2d] != 0) || (puVar10[0x2e] != 0)) || (puVar10[0x2f] != 0)) ||
          ((puVar10[0x30] != 0 || (puVar10[0x31] != 0)))) ||
         ((puVar10[0x32] != 0 || ((puVar10[0x33] != 0 || (puVar10[0x34] != 0)))))) {
        iVar6 = nvswitch_translate_hw_error(*puVar10);
        if (iVar6 == 1) {
          nvswitch_assert_log();
        }
        lVar9 = *param_1;
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Data {0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x}\n"
                          ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),*(undefined1 *)(lVar9 + 0x44),
                          *(undefined1 *)(lVar9 + 0x45),*(undefined1 *)(lVar9 + 0x46),*puVar10,
                          puVar10[0x2d],puVar10[0x2e],puVar10[0x2f],puVar10[0x30],puVar10[0x31],
                          puVar10[0x32],puVar10[0x33],puVar10[0x34]);
        nvswitch_os_report_error
                  (param_1[3],*puVar10,
                   "Data {0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x}\n",
                   puVar10[0x2d],puVar10[0x2e],puVar10[0x2f],puVar10[0x30],puVar10[0x31],
                   puVar10[0x32],puVar10[0x33],puVar10[0x34]);
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,*puVar10,
                   "Data {0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x}\n",
                   puVar10[0x2d],puVar10[0x2e],puVar10[0x2f],puVar10[0x30],puVar10[0x31],
                   puVar10[0x32],puVar10[0x33],puVar10[0x34]);
      }
    }
  }
  *(long *)(param_2 + 2) = *(long *)(param_2 + 2) + 1;
  param_1[0x1e] = param_1[0x1e] + 1;
  return;
}


// ===== 001b9530 nvswitch_ctrl_get_errors =====

undefined8 nvswitch_ctrl_get_errors(long param_1,int *param_2)

{
  undefined8 uVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  uint uVar5;
  long lVar6;
  uint local_114;
  undefined4 local_110 [2];
  ulong local_108;
  undefined4 local_f8;
  undefined8 local_f0;
  undefined1 local_e8;
  undefined8 local_d8;
  int local_cc;
  undefined1 local_c8 [76];
  undefined1 local_7c [76];
  
  local_114 = 0;
  if (*param_2 == 0) {
    lVar6 = param_1 + 0x120;
  }
  else {
    if (*param_2 != 1) {
      return 0xffffffff;
    }
    lVar6 = param_1 + 0xf8;
  }
  nvswitch_os_memset(param_2 + 8,0,0x2a00);
  uVar1 = *(undefined8 *)(lVar6 + 8);
  param_2[6] = 0;
  *(undefined8 *)(param_2 + 4) = uVar1;
  nvswitch_get_error(param_1,lVar6,local_110,0,&local_114);
  uVar2 = local_114;
  if (local_114 != 0) {
    if (local_108 < *(ulong *)(param_2 + 2)) {
      uVar5 = (int)*(ulong *)(param_2 + 2) - (int)local_108;
      if (local_114 <= uVar5) {
        return 0;
      }
    }
    else {
      uVar5 = 0;
    }
    uVar3 = param_2[6];
    for (; (uVar3 < 0x40 && (uVar5 < uVar2)); uVar5 = uVar5 + 1) {
      nvswitch_get_error(param_1,lVar6,local_110,uVar5,0);
      uVar4 = (ulong)(uint)param_2[6];
      *(ulong *)(param_2 + uVar4 * 0x2a + 8) = CONCAT44(local_f8,local_110[0]);
      *(undefined8 *)(param_2 + uVar4 * 0x2a + 10) = local_f0;
      *(undefined8 *)(param_2 + uVar4 * 0x2a + 0xc) = local_d8;
      *(undefined1 *)(param_2 + uVar4 * 0x2a + 0xe) = local_e8;
      param_2[uVar4 * 0x2a + 0x1f] = local_cc;
      if (local_cc != 0) {
        nvswitch_os_memcpy(param_2 + uVar4 * 0x2a + 0xf,local_7c);
        uVar4 = (ulong)(uint)param_2[6];
      }
      nvswitch_os_memcpy(param_2 + uVar4 * 0x2a + 0x20,local_c8,0x46);
      uVar3 = param_2[6] + 1;
      param_2[6] = uVar3;
    }
    *(ulong *)(param_2 + 2) = local_108 + 1;
  }
  return 0;
}


// ===== 001b9720 flcnQueueReadData =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnQueueReadData(undefined8 param_1,undefined8 *param_2,undefined4 param_3,undefined8 param_4,
                      undefined1 param_5)

{
  if (*(code **)*param_2 != (code *)0x0) {
    (**(code **)*param_2)();
    return;
  }
  nvswitch_assert_log();
  (**(code **)*param_2)(param_1,param_2,param_3,param_4,param_5);
  return;
}


// ===== 001b9790 flcnQueueCmdWrite =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnQueueCmdWrite(undefined8 param_1,long *param_2,undefined4 param_3,undefined8 param_4,
                      undefined8 param_5)

{
  if (*(code **)(*param_2 + 8) != (code *)0x0) {
    (**(code **)(*param_2 + 8))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 8))(param_1,param_2,param_3,param_4,param_5);
  return;
}


// ===== 001b97f0 flcnQueueCmdPostBlocking =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int flcnQueueCmdPostBlocking
              (long *param_1,long *param_2,undefined1 *param_3,undefined8 param_4,undefined8 param_5
              ,ulong param_6,undefined4 *param_7,undefined8 param_8)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  
  pcVar5 = *(code **)(*param_2 + 0x18);
  if (pcVar5 == (code *)0x0) {
    nvswitch_assert_log();
    param_6 = param_6 & 0xffffffff;
    pcVar5 = *(code **)(*param_2 + 0x18);
  }
  iVar3 = (*pcVar5)(param_1,param_2,param_3,param_4,param_5,param_6,0,0,param_7,param_8);
  if (iVar3 == 0) {
    uVar1 = *param_7;
    pcVar5 = *(code **)(*param_2 + 0x20);
    if (pcVar5 == (code *)0x0) {
      nvswitch_assert_log();
      pcVar5 = *(code **)(*param_2 + 0x20);
    }
    iVar3 = (*pcVar5)(param_1,param_2,uVar1,param_8);
    if (iVar3 == 0x65) {
      iVar4 = nvswitch_translate_hw_error(0x6594);
      if (iVar4 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Timed out while waiting for SOE command completion. Data {0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x}\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x6594,*param_3,
                        param_3[1],param_3[2],param_3[3],*(undefined4 *)(param_3 + 4),
                        (char)*(undefined4 *)(param_3 + 4));
      nvswitch_os_report_error
                (param_1[3],0x6594,
                 "Timed out while waiting for SOE command completion. Data {0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x}\n"
                 ,*param_3,param_3[1],param_3[2],param_3[3],*(undefined4 *)(param_3 + 4),
                 (char)*(undefined4 *)(param_3 + 4));
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x6594,
                 "Timed out while waiting for SOE command completion. Data {0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x}\n"
                 ,*param_3,param_3[1],param_3[2],param_3[3],*(undefined4 *)(param_3 + 4),
                 (char)*(undefined4 *)(param_3 + 4));
      nvswitch_inforom_bbx_add_sxid(param_1,0x6594,0,0,0);
      uVar1 = *param_7;
      pcVar5 = *(code **)(*param_2 + 0x10);
      if (pcVar5 == (code *)0x0) {
        nvswitch_assert_log();
        pcVar5 = *(code **)(*param_2 + 0x10);
      }
      (*pcVar5)(param_1,param_2,uVar1);
    }
    return iVar3;
  }
  iVar4 = nvswitch_translate_hw_error(0x6593);
  if (iVar4 == 1) {
    nvswitch_assert_log();
  }
  lVar2 = *param_1;
  nvswitch_os_print(5,
                    "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Failed to post command to SOE. Data {0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x}\n"
                    ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                    *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x6593,*param_3,
                    param_3[1],param_3[2],param_3[3],*(undefined4 *)(param_3 + 4),
                    (char)*(undefined4 *)(param_3 + 4));
  nvswitch_os_report_error
            (param_1[3],0x6593,
             "Failed to post command to SOE. Data {0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x}\n"
             ,*param_3,param_3[1],param_3[2],param_3[3],*(undefined4 *)(param_3 + 4),
             (char)*(undefined4 *)(param_3 + 4));
  nvswitch_lib_smbpbi_log_sxid
            (param_1,0x6593,
             "Failed to post command to SOE. Data {0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x}\n"
             ,*param_3,param_3[1],param_3[2],param_3[3],*(undefined4 *)(param_3 + 4),
             (char)*(undefined4 *)(param_3 + 4));
  nvswitch_inforom_bbx_add_sxid(param_1,0x6593,0,0,0);
  return iVar3;
}


// ===== 001b9b00 flcnCmdQueueHeadGet =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnCmdQueueHeadGet(undefined8 param_1,long *param_2,undefined8 param_3,undefined8 param_4)

{
  if (*(code **)(*param_2 + 0x38) != (code *)0x0) {
    (**(code **)(*param_2 + 0x38))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x38))(param_1,param_2,param_3,param_4);
  return;
}


// ===== 001b9b60 flcnMsgQueueHeadGet =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnMsgQueueHeadGet(undefined8 param_1,long *param_2,undefined8 param_3,undefined8 param_4)

{
  if (*(code **)(*param_2 + 0x40) != (code *)0x0) {
    (**(code **)(*param_2 + 0x40))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x40))(param_1,param_2,param_3,param_4);
  return;
}


// ===== 001b9bc0 flcnCmdQueueTailGet =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnCmdQueueTailGet(undefined8 param_1,long *param_2,undefined8 param_3,undefined8 param_4)

{
  if (*(code **)(*param_2 + 0x48) != (code *)0x0) {
    (**(code **)(*param_2 + 0x48))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x48))(param_1,param_2,param_3,param_4);
  return;
}


// ===== 001b9c20 flcnMsgQueueTailGet =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnMsgQueueTailGet(undefined8 param_1,long *param_2,undefined8 param_3,undefined8 param_4)

{
  if (*(code **)(*param_2 + 0x50) != (code *)0x0) {
    (**(code **)(*param_2 + 0x50))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x50))(param_1,param_2,param_3,param_4);
  return;
}


// ===== 001b9c80 flcnCmdQueueHeadSet =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnCmdQueueHeadSet(undefined8 param_1,long *param_2,undefined8 param_3,undefined4 param_4)

{
  if (*(code **)(*param_2 + 0x58) != (code *)0x0) {
    (**(code **)(*param_2 + 0x58))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x58))(param_1,param_2,param_3,param_4);
  return;
}


// ===== 001b9cd0 flcnMsgQueueHeadSet =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnMsgQueueHeadSet(undefined8 param_1,long *param_2,undefined8 param_3,undefined4 param_4)

{
  if (*(code **)(*param_2 + 0x60) != (code *)0x0) {
    (**(code **)(*param_2 + 0x60))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x60))(param_1,param_2,param_3,param_4);
  return;
}


// ===== 001b9d20 flcnCmdQueueTailSet =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnCmdQueueTailSet(undefined8 param_1,long *param_2,undefined8 param_3,undefined4 param_4)

{
  if (*(code **)(*param_2 + 0x68) != (code *)0x0) {
    (**(code **)(*param_2 + 0x68))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x68))(param_1,param_2,param_3,param_4);
  return;
}


// ===== 001b9d70 flcnMsgQueueTailSet =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnMsgQueueTailSet(undefined8 param_1,long *param_2,undefined8 param_3,undefined4 param_4)

{
  if (*(code **)(*param_2 + 0x70) != (code *)0x0) {
    (**(code **)(*param_2 + 0x70))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x70))(param_1,param_2,param_3,param_4);
  return;
}


// ===== 001b9dc0 flcnQueueSeqInfoFind =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnQueueSeqInfoFind(undefined8 param_1,long *param_2,undefined4 param_3)

{
  if (*(code **)(*param_2 + 0x78) != (code *)0x0) {
    (**(code **)(*param_2 + 0x78))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x78))(param_1,param_2,param_3);
  return;
}


// ===== 001b9e10 flcnQueueSeqInfoAcq =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnQueueSeqInfoAcq(undefined8 param_1,long *param_2)

{
  if (*(code **)(*param_2 + 0x80) != (code *)0x0) {
    (**(code **)(*param_2 + 0x80))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x80))(param_1);
  return;
}


// ===== 001b9e60 flcnQueueSeqInfoRel =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnQueueSeqInfoRel(undefined8 param_1,long *param_2,undefined8 param_3)

{
  if (*(code **)(*param_2 + 0x88) != (code *)0x0) {
    (**(code **)(*param_2 + 0x88))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x88))(param_1,param_2,param_3);
  return;
}


// ===== 001b9ec0 flcnQueueSeqInfoStateInit =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnQueueSeqInfoStateInit(undefined8 param_1,long *param_2)

{
  if (*(code **)(*param_2 + 0x90) != (code *)0x0) {
    (**(code **)(*param_2 + 0x90))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x90))(param_1);
  return;
}


// ===== 001b9f10 flcnQueueSeqInfoFree =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnQueueSeqInfoFree(undefined8 param_1,long *param_2,undefined8 param_3)

{
  if (*(code **)(*param_2 + 0xa0) != (code *)0x0) {
    (**(code **)(*param_2 + 0xa0))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0xa0))(param_1,param_2,param_3);
  return;
}


// ===== 001b9f70 flcnQueueEventRegister =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnQueueEventRegister
               (undefined8 param_1,long *param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  if (*(code **)(*param_2 + 0xa8) != (code *)0x0) {
    (**(code **)(*param_2 + 0xa8))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0xa8))(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 001b9ff0 flcnQueueEventUnregister =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnQueueEventUnregister(undefined8 param_1,long *param_2,undefined4 param_3)

{
  if (*(code **)(*param_2 + 0xb0) != (code *)0x0) {
    (**(code **)(*param_2 + 0xb0))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0xb0))(param_1,param_2,param_3);
  return;
}


// ===== 001ba050 flcnQueueEventHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnQueueEventHandle(undefined8 param_1,long *param_2,undefined8 param_3,undefined4 param_4)

{
  if (*(code **)(*param_2 + 0xb8) != (code *)0x0) {
    (**(code **)(*param_2 + 0xb8))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0xb8))(param_1,param_2,param_3,param_4);
  return;
}


// ===== 001ba0b0 flcnQueueResponseHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnQueueResponseHandle(undefined8 param_1,long *param_2,undefined8 param_3)

{
  if (*(code **)(*param_2 + 0xc0) != (code *)0x0) {
    (**(code **)(*param_2 + 0xc0))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0xc0))(param_1,param_2,param_3);
  return;
}


// ===== 001ba110 flcnDmemCopyFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnDmemCopyFrom(undefined8 param_1,long *param_2,undefined4 param_3,undefined8 param_4,
                     undefined4 param_5,undefined1 param_6)

{
  if (*(code **)(*param_2 + 0xd0) != (code *)0x0) {
    (**(code **)(*param_2 + 0xd0))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0xd0))(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 001ba180 flcnDmemCopyTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnDmemCopyTo(undefined8 param_1,long *param_2,undefined4 param_3,undefined8 param_4,
                   undefined4 param_5,undefined1 param_6)

{
  if (*(code **)(*param_2 + 0xd8) != (code *)0x0) {
    (**(code **)(*param_2 + 0xd8))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0xd8))(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 001ba1f0 flcnPostDiscoveryInit =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnPostDiscoveryInit(undefined8 param_1,long *param_2)

{
  if (*(code **)(*param_2 + 0xe0) != (code *)0x0) {
    (**(code **)(*param_2 + 0xe0))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0xe0))(param_1);
  return;
}


// ===== 001ba240 flcnDbgInfoDmemOffsetSet =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnDbgInfoDmemOffsetSet(undefined8 param_1,long *param_2,undefined2 param_3)

{
  if (*(code **)(*param_2 + 0xe8) != (code *)0x0) {
    (**(code **)(*param_2 + 0xe8))(param_1,param_2,param_3);
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0xe8))(param_1,param_2,param_3);
  return;
}


// ===== 001ba2a0 flcnConstruct_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnConstruct_HAL(undefined8 param_1,long *param_2)

{
  if (*(code **)(*param_2 + 0xf0) != (code *)0x0) {
    (**(code **)(*param_2 + 0xf0))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0xf0))(param_1);
  return;
}


// ===== 001ba2f0 flcnDestruct_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnDestruct_HAL(undefined8 param_1,long *param_2)

{
  if (*(code **)(*param_2 + 0xf8) != (code *)0x0) {
    (**(code **)(*param_2 + 0xf8))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0xf8))(param_1);
  return;
}


// ===== 001ba340 flcnRegRead_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnRegRead_HAL(undefined8 param_1,long *param_2,undefined4 param_3)

{
  if (*(code **)(*param_2 + 0x100) != (code *)0x0) {
    (**(code **)(*param_2 + 0x100))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x100))(param_1,param_2,param_3);
  return;
}


// ===== 001ba3a0 flcnRegWrite_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnRegWrite_HAL(undefined8 param_1,long *param_2,undefined4 param_3,undefined4 param_4)

{
  if (*(code **)(*param_2 + 0x108) != (code *)0x0) {
    (**(code **)(*param_2 + 0x108))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x108))(param_1,param_2,param_3,param_4);
  return;
}


// ===== 001ba400 flcnReadCoreRev_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnReadCoreRev_HAL(undefined8 param_1,long *param_2)

{
  if (*(code **)(*param_2 + 0x118) != (code *)0x0) {
    (**(code **)(*param_2 + 0x118))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x118))(param_1);
  return;
}


// ===== 001ba450 flcnGetCoreInfo_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnGetCoreInfo_HAL(undefined8 param_1,long *param_2)

{
  if (*(code **)(*param_2 + 0x120) != (code *)0x0) {
    (**(code **)(*param_2 + 0x120))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x120))(param_1);
  return;
}


// ===== 001ba4a0 flcnDmemTransfer_HAL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

void flcnDmemTransfer_HAL
               (undefined8 param_1,long *param_2,undefined4 param_3,undefined8 param_4,
               undefined4 param_5,undefined1 param_6)

{
  if (*(code **)(*param_2 + 0x128) != (code *)0x0) {
    (**(code **)(*param_2 + 0x128))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x128))(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 001ba530 flcnIntrRetrigger_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnIntrRetrigger_HAL(undefined8 param_1,long *param_2)

{
  if (*(code **)(*param_2 + 0x130) != (code *)0x0) {
    (**(code **)(*param_2 + 0x130))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x130))(param_1);
  return;
}


// ===== 001ba580 flcnWaitForResetToFinish_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnWaitForResetToFinish_HAL(undefined8 param_1,long *param_2)

{
  if (*(code **)(*param_2 + 0x140) != (code *)0x0) {
    (**(code **)(*param_2 + 0x140))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x140))(param_1);
  return;
}


// ===== 001ba5d0 flcnDbgInfoCapturePcTrace_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnDbgInfoCapturePcTrace_HAL(undefined8 param_1,long *param_2)

{
  if (*(code **)(*param_2 + 0x148) != (code *)0x0) {
    (**(code **)(*param_2 + 0x148))();
    return;
  }
  nvswitch_assert_log();
  return;
}


// ===== 001ba600 flcnDbgInfoCaptureRiscvPcTrace_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnDbgInfoCaptureRiscvPcTrace_HAL(undefined8 param_1,long *param_2)

{
  if (*(code **)(*param_2 + 0x150) != (code *)0x0) {
    (**(code **)(*param_2 + 0x150))();
    return;
  }
  nvswitch_assert_log();
  return;
}


// ===== 001ba630 flcnSetDmemAddr_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 flcnSetDmemAddr_HAL(undefined8 param_1,long *param_2)

{
  undefined8 uVar1;
  
  if (*(code **)(*param_2 + 0x170) != (code *)0x0) {
    uVar1 = (**(code **)(*param_2 + 0x170))();
    return uVar1;
  }
  nvswitch_assert_log();
  return 0;
}


// ===== 001ba660 flcnRiscvRegRead_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnRiscvRegRead_HAL(undefined8 param_1,long *param_2,undefined4 param_3)

{
  if (*(code **)(*param_2 + 0x178) != (code *)0x0) {
    (**(code **)(*param_2 + 0x178))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x178))(param_1,param_2,param_3);
  return;
}


// ===== 001ba6c0 flcnRiscvRegWrite_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnRiscvRegWrite_HAL(undefined8 param_1,long *param_2,undefined4 param_3,undefined4 param_4)

{
  if (*(code **)(*param_2 + 0x180) != (code *)0x0) {
    (**(code **)(*param_2 + 0x180))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x180))(param_1,param_2,param_3,param_4);
  return;
}


// ===== 001ba720 _flcnMarkNotReady_IMPL =====

void _flcnMarkNotReady_IMPL(undefined8 param_1,long param_2)

{
  *(undefined1 *)(param_2 + 0x31) = 0;
  return;
}


// ===== 001ba730 _flcnPostDiscoveryInit_IMPL =====

void _flcnPostDiscoveryInit_IMPL(undefined8 param_1,long param_2)

{
  byte bVar1;
  
  flcnableFetchEngines_HAL(param_1,*(undefined8 *)(param_2 + 0x48),param_2 + 0x10,param_2 + 0x18);
  bVar1 = flcnableReadCoreRev(param_1,*(undefined8 *)(param_2 + 0x48));
  if (bVar1 < 0x52) {
    if (0x4f < bVar1) {
      flcnSetupHal_v05_01(param_2);
      return;
    }
    if (bVar1 == 0x30) {
      flcnSetupHal_v03_00(param_2);
      return;
    }
    if ((byte)(bVar1 - 0x40) < 2) {
      flcnSetupHal_v04_00(param_2);
      return;
    }
  }
  else if (bVar1 == 0x60) {
    flcnSetupHal_v06_00(param_2);
    return;
  }
  nvswitch_assert_log();
  return;
}


// ===== 001ba7d0 _flcnDmemCopyTo_IMPL =====

void _flcnDmemCopyTo_IMPL(void)

{
  flcnDmemTransfer_HAL();
  return;
}


// ===== 001ba7f0 _flcnDmemCopyFrom_IMPL =====

void _flcnDmemCopyFrom_IMPL(void)

{
  flcnDmemTransfer_HAL();
  return;
}


// ===== 001ba810 _flcnMsgQueueTailSet_IMPL =====

undefined8
_flcnMsgQueueTailSet_IMPL(undefined8 param_1,long param_2,long param_3,undefined4 param_4)

{
  long lVar1;
  
  lVar1 = *(long *)(param_2 + 0x58);
  if (lVar1 == 0) {
    nvswitch_assert_log();
  }
  if (*(uint *)(param_3 + 0x8c) < (uint)*(byte *)(lVar1 + 5)) {
    flcnRegWrite_HAL(param_1,param_2,
                     *(uint *)(param_3 + 0x8c) * *(int *)(lVar1 + 0x2c) + *(int *)(lVar1 + 0x28));
    return 0;
  }
  nvswitch_assert_log();
  flcnRegWrite_HAL(param_1,param_2,
                   *(int *)(param_3 + 0x8c) * *(int *)(lVar1 + 0x2c) + *(int *)(lVar1 + 0x28),
                   param_4);
  return 0;
}


// ===== 001ba8d0 _flcnCmdQueueTailSet_IMPL =====

undefined8
_flcnCmdQueueTailSet_IMPL(undefined8 param_1,long param_2,long param_3,undefined4 param_4)

{
  long lVar1;
  
  lVar1 = *(long *)(param_2 + 0x58);
  if (lVar1 == 0) {
    nvswitch_assert_log();
  }
  if (*(uint *)(param_3 + 0x8c) < (uint)*(byte *)(lVar1 + 3)) {
    flcnRegWrite_HAL(param_1,param_2,
                     *(uint *)(param_3 + 0x8c) * *(int *)(lVar1 + 0x1c) + *(int *)(lVar1 + 0x18));
    return 0;
  }
  nvswitch_assert_log();
  flcnRegWrite_HAL(param_1,param_2,
                   *(int *)(param_3 + 0x8c) * *(int *)(lVar1 + 0x1c) + *(int *)(lVar1 + 0x18),
                   param_4);
  return 0;
}


// ===== 001ba990 _flcnMsgQueueHeadSet_IMPL =====

undefined8
_flcnMsgQueueHeadSet_IMPL(undefined8 param_1,long param_2,long param_3,undefined4 param_4)

{
  long lVar1;
  
  lVar1 = *(long *)(param_2 + 0x58);
  if (lVar1 == 0) {
    nvswitch_assert_log();
  }
  if (*(uint *)(param_3 + 0x8c) < (uint)*(byte *)(lVar1 + 4)) {
    flcnRegWrite_HAL(param_1,param_2,
                     *(uint *)(param_3 + 0x8c) * *(int *)(lVar1 + 0x24) + *(int *)(lVar1 + 0x20));
    return 0;
  }
  nvswitch_assert_log();
  flcnRegWrite_HAL(param_1,param_2,
                   *(int *)(param_3 + 0x8c) * *(int *)(lVar1 + 0x24) + *(int *)(lVar1 + 0x20),
                   param_4);
  return 0;
}


// ===== 001baa50 _flcnCmdQueueHeadSet_IMPL =====

undefined8
_flcnCmdQueueHeadSet_IMPL(undefined8 param_1,long param_2,long param_3,undefined4 param_4)

{
  long lVar1;
  
  lVar1 = *(long *)(param_2 + 0x58);
  if (lVar1 == 0) {
    nvswitch_assert_log();
  }
  if (*(uint *)(param_3 + 0x8c) < (uint)*(byte *)(lVar1 + 2)) {
    flcnRegWrite_HAL(param_1,param_2,
                     *(uint *)(param_3 + 0x8c) * *(int *)(lVar1 + 0x14) + *(int *)(lVar1 + 0x10));
    return 0;
  }
  nvswitch_assert_log();
  flcnRegWrite_HAL(param_1,param_2,
                   *(int *)(param_3 + 0x8c) * *(int *)(lVar1 + 0x14) + *(int *)(lVar1 + 0x10),
                   param_4);
  return 0;
}


// ===== 001bab10 _flcnMsgQueueTailGet_IMPL =====

undefined8
_flcnMsgQueueTailGet_IMPL(undefined8 param_1,long param_2,long param_3,undefined4 *param_4)

{
  long lVar1;
  undefined4 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x58);
  if (lVar1 == 0) {
    nvswitch_assert_log();
  }
  if ((uint)*(byte *)(lVar1 + 5) <= *(uint *)(param_3 + 0x8c)) {
    nvswitch_assert_log();
  }
  if (param_4 == (undefined4 *)0x0) {
    nvswitch_assert_log();
  }
  uVar2 = flcnRegRead_HAL(param_1,param_2,
                          *(int *)(param_3 + 0x8c) * *(int *)(lVar1 + 0x2c) + *(int *)(lVar1 + 0x28)
                         );
  *param_4 = uVar2;
  return 0;
}


// ===== 001babd0 _flcnCmdQueueTailGet_IMPL =====

undefined8
_flcnCmdQueueTailGet_IMPL(undefined8 param_1,long param_2,long param_3,undefined4 *param_4)

{
  long lVar1;
  undefined4 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x58);
  if (lVar1 == 0) {
    nvswitch_assert_log();
  }
  if ((uint)*(byte *)(lVar1 + 3) <= *(uint *)(param_3 + 0x8c)) {
    nvswitch_assert_log();
  }
  if (param_4 == (undefined4 *)0x0) {
    nvswitch_assert_log();
  }
  uVar2 = flcnRegRead_HAL(param_1,param_2,
                          *(int *)(param_3 + 0x8c) * *(int *)(lVar1 + 0x1c) + *(int *)(lVar1 + 0x18)
                         );
  *param_4 = uVar2;
  return 0;
}


// ===== 001bac90 _flcnMsgQueueHeadGet_IMPL =====

undefined8
_flcnMsgQueueHeadGet_IMPL(undefined8 param_1,long param_2,long param_3,undefined4 *param_4)

{
  long lVar1;
  undefined4 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x58);
  if (lVar1 == 0) {
    nvswitch_assert_log();
  }
  if ((uint)*(byte *)(lVar1 + 4) <= *(uint *)(param_3 + 0x8c)) {
    nvswitch_assert_log();
  }
  if (param_4 == (undefined4 *)0x0) {
    nvswitch_assert_log();
  }
  uVar2 = flcnRegRead_HAL(param_1,param_2,
                          *(int *)(param_3 + 0x8c) * *(int *)(lVar1 + 0x24) + *(int *)(lVar1 + 0x20)
                         );
  *param_4 = uVar2;
  return 0;
}


// ===== 001bad50 _flcnCmdQueueHeadGet_IMPL =====

undefined8
_flcnCmdQueueHeadGet_IMPL(undefined8 param_1,long param_2,long param_3,undefined4 *param_4)

{
  long lVar1;
  undefined4 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x58);
  if (lVar1 == 0) {
    nvswitch_assert_log();
  }
  if ((uint)*(byte *)(lVar1 + 2) <= *(uint *)(param_3 + 0x8c)) {
    nvswitch_assert_log();
  }
  if (param_4 == (undefined4 *)0x0) {
    nvswitch_assert_log();
  }
  uVar2 = flcnRegRead_HAL(param_1,param_2,
                          *(int *)(param_3 + 0x8c) * *(int *)(lVar1 + 0x14) + *(int *)(lVar1 + 0x10)
                         );
  *param_4 = uVar2;
  return 0;
}


// ===== 001bae10 _flcnCoreRevisionGet_IMPL =====

char _flcnCoreRevisionGet_IMPL(undefined8 param_1,long param_2)

{
  if (*(char *)(param_2 + 0x44) != '\0') {
    return *(char *)(param_2 + 0x44);
  }
  flcnGetCoreInfo_HAL();
  return *(char *)(param_2 + 0x44);
}


// ===== 001bae40 flcnAllocNew =====

long flcnAllocNew(void)

{
  long lVar1;
  
  lVar1 = nvswitch_os_malloc_trace(0x68,0,0);
  if (lVar1 != 0) {
    nvswitch_os_memset(lVar1,0,0x68);
  }
  return lVar1;
}


// ===== 001bae80 flcnInit =====

undefined8 flcnInit(undefined8 param_1,long *param_2,undefined4 param_3)

{
  char cVar1;
  long lVar2;
  
  if (*param_2 == 0) {
    lVar2 = nvswitch_os_malloc_trace(0x1a8,0,0);
    *param_2 = lVar2;
    if (lVar2 == 0) {
      return 0xfffffffe;
    }
    nvswitch_os_memset(lVar2,0,0x1a8);
  }
  cVar1 = nvswitch_is_lr10_device_id(param_3);
  if (cVar1 == '\0') {
    cVar1 = nvswitch_is_ls10_device_id(param_3);
    if (cVar1 == '\0') {
      nvswitch_assert_log();
    }
    else {
      flcnSetupHal_LS10(param_2);
    }
  }
  else {
    flcnSetupHal_LR10(param_2);
  }
  lVar2 = *param_2;
  *(code **)(lVar2 + 0x28) = _flcnCoreRevisionGet_IMPL;
  *(code **)(lVar2 + 0x30) = _flcnMarkNotReady_IMPL;
  *(code **)(lVar2 + 0x38) = _flcnCmdQueueHeadGet_IMPL;
  *(code **)(lVar2 + 0x40) = _flcnMsgQueueHeadGet_IMPL;
  *(code **)(lVar2 + 0x48) = _flcnCmdQueueTailGet_IMPL;
  *(code **)(lVar2 + 0x50) = _flcnMsgQueueTailGet_IMPL;
  *(code **)(lVar2 + 0x58) = _flcnCmdQueueHeadSet_IMPL;
  *(code **)(lVar2 + 0x60) = _flcnMsgQueueHeadSet_IMPL;
  *(code **)(lVar2 + 0x68) = _flcnCmdQueueTailSet_IMPL;
  *(code **)(lVar2 + 0x70) = _flcnMsgQueueTailSet_IMPL;
  *(code **)(lVar2 + 0xd0) = _flcnDmemCopyFrom_IMPL;
  *(code **)(lVar2 + 0xd8) = _flcnDmemCopyTo_IMPL;
  *(code **)(lVar2 + 0xe0) = _flcnPostDiscoveryInit_IMPL;
  flcnQueueSetupHal(param_2);
  flcnRtosSetupHal(param_2);
  flcnQueueRdSetupHal(param_2);
  return 0;
}


// ===== 001bafb0 flcnDestroy =====

void flcnDestroy(undefined8 param_1,long *param_2)

{
  if (*param_2 != 0) {
    nvswitch_os_free();
    *param_2 = 0;
    return;
  }
  return;
}


// ===== 001baff0 flcnableReadCoreRev =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnableReadCoreRev(undefined8 param_1,undefined8 *param_2)

{
  if (*(code **)*param_2 != (code *)0x0) {
    (**(code **)*param_2)();
    return;
  }
  nvswitch_assert_log();
  (**(code **)*param_2)(param_1);
  return;
}


// ===== 001bb040 flcnableGetExternalConfig =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnableGetExternalConfig(undefined8 param_1,long *param_2,undefined8 param_3)

{
  if (*(code **)(*param_2 + 8) != (code *)0x0) {
    (**(code **)(*param_2 + 8))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 8))(param_1,param_2,param_3);
  return;
}


// ===== 001bb090 flcnableEmemCopyFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnableEmemCopyFrom
               (undefined8 param_1,long *param_2,undefined4 param_3,undefined8 param_4,
               undefined4 param_5,undefined1 param_6)

{
  if (*(code **)(*param_2 + 0x10) != (code *)0x0) {
    (**(code **)(*param_2 + 0x10))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x10))(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 001bb100 flcnableEmemCopyTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnableEmemCopyTo(undefined8 param_1,long *param_2,undefined4 param_3,undefined8 param_4,
                       undefined4 param_5,undefined1 param_6)

{
  if (*(code **)(*param_2 + 0x18) != (code *)0x0) {
    (**(code **)(*param_2 + 0x18))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x18))(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 001bb170 flcnableHandleInitEvent =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnableHandleInitEvent(undefined8 param_1,long *param_2,undefined8 param_3)

{
  if (*(code **)(*param_2 + 0x20) != (code *)0x0) {
    (**(code **)(*param_2 + 0x20))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x20))(param_1,param_2,param_3);
  return;
}


// ===== 001bb1c0 flcnableQueueSeqInfoGet =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnableQueueSeqInfoGet(undefined8 param_1,long *param_2,undefined4 param_3)

{
  if (*(code **)(*param_2 + 0x28) != (code *)0x0) {
    (**(code **)(*param_2 + 0x28))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x28))(param_1,param_2,param_3);
  return;
}


// ===== 001bb210 flcnableQueueSeqInfoClear =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnableQueueSeqInfoClear(undefined8 param_1,long *param_2,undefined8 param_3)

{
  if (*(code **)(*param_2 + 0x30) != (code *)0x0) {
    (**(code **)(*param_2 + 0x30))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x30))(param_1,param_2,param_3);
  return;
}


// ===== 001bb260 flcnableQueueSeqInfoFree =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnableQueueSeqInfoFree(undefined8 param_1,long *param_2,undefined8 param_3)

{
  if (*(code **)(*param_2 + 0x38) != (code *)0x0) {
    (**(code **)(*param_2 + 0x38))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x38))(param_1,param_2,param_3);
  return;
}


// ===== 001bb2b0 flcnableQueueCmdValidate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnableQueueCmdValidate
               (undefined8 param_1,long *param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 param_6)

{
  if (*(code **)(*param_2 + 0x40) != (code *)0x0) {
    (**(code **)(*param_2 + 0x40))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x40))(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 001bb320 flcnableQueueCmdPostExtension =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnableQueueCmdPostExtension
               (undefined8 param_1,long *param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  if (*(code **)(*param_2 + 0x48) != (code *)0x0) {
    (**(code **)(*param_2 + 0x48))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x48))(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 001bb3a0 flcnablePostDiscoveryInit =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnablePostDiscoveryInit(undefined8 param_1,long *param_2)

{
  if (*(code **)(*param_2 + 0x50) != (code *)0x0) {
    (**(code **)(*param_2 + 0x50))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x50))(param_1);
  return;
}


// ===== 001bb3f0 flcnableConstruct_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnableConstruct_HAL(undefined8 param_1,long *param_2)

{
  if (*(code **)(*param_2 + 0x58) != (code *)0x0) {
    (**(code **)(*param_2 + 0x58))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x58))(param_1);
  return;
}


// ===== 001bb440 flcnableDestruct_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnableDestruct_HAL(undefined8 param_1,long *param_2)

{
  if (*(code **)(*param_2 + 0x60) != (code *)0x0) {
    (**(code **)(*param_2 + 0x60))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x60))(param_1);
  return;
}


// ===== 001bb490 flcnableFetchEngines_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void flcnableFetchEngines_HAL
               (undefined8 param_1,long *param_2,undefined8 param_3,undefined8 param_4)

{
  if (*(code **)(*param_2 + 0x68) != (code *)0x0) {
    (**(code **)(*param_2 + 0x68))();
    return;
  }
  nvswitch_assert_log();
  (**(code **)(*param_2 + 0x68))(param_1,param_2,param_3,param_4);
  return;
}


// ===== 001bb4f0 _flcnableGetExternalConfig_IMPL =====

void _flcnableGetExternalConfig_IMPL(undefined8 param_1,undefined8 param_2,undefined1 *param_3)

{
  *param_3 = 0;
  *(undefined8 *)(param_3 + 8) = 0xffffffffffffffff;
  return;
}


// ===== 001bb500 _flcnableHandleInitEvent_IMPL =====

undefined8 _flcnableHandleInitEvent_IMPL(void)

{
  return 0;
}


// ===== 001bb510 _flcnableQueueSeqInfoClear_IMPL =====

void _flcnableQueueSeqInfoClear_IMPL(void)

{
  return;
}


// ===== 001bb520 _flcnableQueueCmdPostExtension_IMPL =====

undefined8 _flcnableQueueCmdPostExtension_IMPL(void)

{
  return 0;
}


// ===== 001bb530 _flcnableFetchEngines_IMPL =====

void _flcnableFetchEngines_IMPL(void)

{
  nvswitch_assert_log();
  return;
}


// ===== 001bb540 _flcnableQueueCmdValidate_IMPL =====

undefined8 _flcnableQueueCmdValidate_IMPL(void)

{
  nvswitch_assert_log();
  return 0;
}


// ===== 001bb560 _flcnableQueueSeqInfoGet_IMPL =====

undefined8 _flcnableQueueSeqInfoGet_IMPL(void)

{
  nvswitch_assert_log();
  return 0;
}


// ===== 001bb580 _flcnableEmemCopyFrom_IMPL =====

void _flcnableEmemCopyFrom_IMPL(void)

{
  nvswitch_assert_log();
  return;
}


// ===== 001bb590 _flcnablePostDiscoveryInit_IMPL =====

void _flcnablePostDiscoveryInit_IMPL(undefined8 param_1,long param_2)

{
  flcnPostDiscoveryInit(param_1,*(undefined8 *)(param_2 + 8));
  return;
}


// ===== 001bb5a0 _flcnableReadCoreRev_IMPL =====

void _flcnableReadCoreRev_IMPL(undefined8 param_1,long param_2)

{
  flcnReadCoreRev_HAL(param_1,*(undefined8 *)(param_2 + 8));
  return;
}


// ===== 001bb5b0 _flcnableEmemCopyTo_IMPL =====

void _flcnableEmemCopyTo_IMPL(void)

{
  nvswitch_assert_log();
  return;
}


// ===== 001bb5c0 _flcnableQueueSeqInfoFree_IMPL =====

void _flcnableQueueSeqInfoFree_IMPL(void)

{
  return;
}


// ===== 001bb5d0 flcnableInit =====

ulong flcnableInit(undefined8 param_1,long *param_2,undefined4 param_3)

{
  undefined8 *puVar1;
  long lVar2;
  ulong uVar3;
  
  if (*param_2 == 0) {
    lVar2 = nvswitch_os_malloc_trace(0x70,0,0);
    *param_2 = lVar2;
    if (lVar2 != 0) {
      nvswitch_os_memset(lVar2,0,0x70);
      lVar2 = flcnAllocNew();
      param_2[1] = lVar2;
      goto joined_r0x001bb709;
    }
    uVar3 = 0xfffffffe;
    if (param_2[1] == 0) {
      return 0xfffffffe;
    }
  }
  else {
    lVar2 = flcnAllocNew();
    param_2[1] = lVar2;
joined_r0x001bb709:
    if (lVar2 == 0) {
      uVar3 = 0xfffffffe;
      goto LAB_001bb640;
    }
    uVar3 = flcnInit(param_1,lVar2,param_3);
    if ((int)uVar3 == 0) {
      puVar1 = (undefined8 *)*param_2;
      *puVar1 = _flcnableReadCoreRev_IMPL;
      puVar1[1] = _flcnableGetExternalConfig_IMPL;
      puVar1[2] = _flcnableEmemCopyFrom_IMPL;
      puVar1[3] = _flcnableEmemCopyTo_IMPL;
      puVar1[4] = _flcnableHandleInitEvent_IMPL;
      puVar1[5] = _flcnableQueueSeqInfoGet_IMPL;
      puVar1[6] = _flcnableQueueSeqInfoClear_IMPL;
      puVar1[7] = _flcnableQueueSeqInfoFree_IMPL;
      puVar1[8] = _flcnableQueueCmdValidate_IMPL;
      puVar1[9] = _flcnableQueueCmdPostExtension_IMPL;
      puVar1[10] = _flcnablePostDiscoveryInit_IMPL;
      puVar1[0xd] = _flcnableFetchEngines_IMPL;
      return uVar3;
    }
    if (param_2[1] == 0) goto LAB_001bb640;
  }
  flcnDestroy(param_1);
  nvswitch_os_free(param_2[1]);
  param_2[1] = 0;
  uVar3 = uVar3 & 0xffffffff;
LAB_001bb640:
  if (*param_2 != 0) {
    nvswitch_os_free();
    *param_2 = 0;
    uVar3 = uVar3 & 0xffffffff;
  }
  return uVar3;
}


// ===== 001bb740 flcnableDestroy =====

void flcnableDestroy(undefined8 param_1,long *param_2)

{
  if (param_2[1] != 0) {
    flcnDestroy();
    nvswitch_os_free(param_2[1]);
    param_2[1] = 0;
  }
  if (*param_2 != 0) {
    nvswitch_os_free();
    *param_2 = 0;
  }
  return;
}


// ===== 001bb790 _flcnQueueHasRoom_dmem =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

byte _flcnQueueHasRoom_dmem
               (undefined8 param_1,undefined8 param_2,long param_3,int param_4,undefined1 *param_5)

{
  uint uVar1;
  undefined1 uVar2;
  uint uVar3;
  uint local_30;
  uint local_2c;
  
  uVar3 = param_4 + 3U & 0xfffffffc;
  (**(code **)(param_3 + 0x38))();
  (**(code **)(param_3 + 0x48))(param_1,param_2,param_3);
  if (local_30 < local_2c) {
    uVar2 = 0;
  }
  else {
    uVar1 = *(uint *)(param_3 + 0x84);
    if (uVar3 <= ((*(int *)(param_3 + 0x90) + uVar1) - local_30) - *(int *)(param_3 + 0x94)) {
      if (param_5 != (undefined1 *)0x0) {
        *param_5 = 0;
      }
      return 0;
    }
    if (local_2c <= uVar1) {
      if (param_5 != (undefined1 *)0x0) {
        *param_5 = 1;
      }
      return 0x1a;
    }
    uVar2 = 1;
    local_30 = uVar1;
  }
  if (param_5 != (undefined1 *)0x0) {
    *param_5 = uVar2;
  }
  return -((local_2c - 1) - local_30 < uVar3) & 0x1a;
}


// ===== 001bb870 _flcnQueueRewind_dmem =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void _flcnQueueRewind_dmem(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined4 uVar1;
  undefined1 local_44 [60];
  
  if (*(char *)(param_3 + 0xa0) == '\0') {
    nvswitch_assert_log();
    return;
  }
  if (*(int *)(param_3 + 0x9c) != 1) {
    *(undefined4 *)(param_3 + 0x80) = *(undefined4 *)(param_3 + 0x84);
    return;
  }
  uVar1 = (**(code **)(param_3 + 0x70))();
  (**(code **)(param_3 + 0x28))(param_1,param_2,param_3,local_44,uVar1,*(code **)(param_3 + 0x28));
  *(undefined4 *)(param_3 + 0x80) = *(undefined4 *)(param_3 + 0x84);
  return;
}


// ===== 001bb900 _flcnQueueOpenWrite_dmem =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Removing unreachable block (ram,0x001bb990) */

undefined8 _flcnQueueOpenWrite_dmem(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  
  if (*(char *)(param_3 + 0xa0) != '\0') {
    nvswitch_assert_log();
    return 0xffff;
  }
  iVar1 = _flcnQueueHasRoom_dmem();
  if (iVar1 != 0) {
    return 0x1a;
  }
  (**(code **)(param_3 + 0x38))(param_1,param_2,param_3,param_3 + 0x80);
  *(undefined1 *)(param_3 + 0xa0) = 1;
  *(undefined4 *)(param_3 + 0x9c) = 1;
  return 0;
}


// ===== 001bba00 _flcnQueueTailSet_dmem =====

void _flcnQueueTailSet_dmem(undefined8 param_1,long param_2,long param_3,undefined4 param_4)

{
  if (*(long *)(param_2 + 0x58) == 0) {
    nvswitch_assert_log();
    if (*(uint *)(param_3 + 0x88) <= *(uint *)(*(long *)(param_2 + 0x58) + 8)) {
      flcnCmdQueueTailSet();
      return;
    }
    flcnMsgQueueTailSet(param_1,param_2,param_3,param_4);
    return;
  }
  if (*(uint *)(param_3 + 0x88) <= *(uint *)(*(long *)(param_2 + 0x58) + 8)) {
    flcnCmdQueueTailSet();
    return;
  }
  flcnMsgQueueTailSet();
  return;
}


// ===== 001bba80 _flcnQueueTailGet_dmem =====

void _flcnQueueTailGet_dmem(undefined8 param_1,long param_2,long param_3,undefined8 param_4)

{
  if (*(long *)(param_2 + 0x58) == 0) {
    nvswitch_assert_log();
    if (*(uint *)(param_3 + 0x88) <= *(uint *)(*(long *)(param_2 + 0x58) + 8)) {
      flcnCmdQueueTailGet();
      return;
    }
    flcnMsgQueueTailGet(param_1,param_2,param_3,param_4);
    return;
  }
  if (*(uint *)(param_3 + 0x88) <= *(uint *)(*(long *)(param_2 + 0x58) + 8)) {
    flcnCmdQueueTailGet();
    return;
  }
  flcnMsgQueueTailGet();
  return;
}


// ===== 001bbb00 _flcnQueueWrite_dmem =====

void _flcnQueueWrite_dmem
               (undefined8 param_1,long param_2,undefined8 param_3,undefined4 param_4,
               undefined8 param_5,undefined4 param_6)

{
  int iVar1;
  
  if (*(char *)(param_2 + 0x60) != '\0') {
    flcnableEmemCopyTo(param_1,*(undefined8 *)(param_2 + 0x48));
    return;
  }
  iVar1 = flcnDmemCopyTo(param_1,param_2,param_4,param_5,param_6,0);
  if (iVar1 == 0) {
    return;
  }
  nvswitch_assert_log();
  return;
}


// ===== 001bbb40 _flcnQueueRead_dmem =====

void _flcnQueueRead_dmem(undefined8 param_1,long param_2,undefined8 param_3,undefined4 param_4,
                        undefined8 param_5,undefined4 param_6)

{
  int iVar1;
  
  if (*(char *)(param_2 + 0x60) != '\0') {
    flcnableEmemCopyFrom(param_1,*(undefined8 *)(param_2 + 0x48));
    return;
  }
  iVar1 = flcnDmemCopyFrom(param_1,param_2,param_4,param_5,param_6,0);
  if (iVar1 == 0) {
    return;
  }
  nvswitch_assert_log();
  return;
}


// ===== 001bbb80 _flcnQueuePush_dmem =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _flcnQueuePush_dmem(undefined8 param_1,long param_2,long param_3,undefined8 param_4,int param_5
                        )

{
  int iVar1;
  
  if ((*(char *)(param_3 + 0xa0) != '\0') && (*(int *)(param_3 + 0x9c) == 1)) {
    if (*(code **)(param_3 + 0x60) == _flcnQueueWrite_dmem) {
      if (*(char *)(param_2 + 0x60) == '\0') {
        iVar1 = flcnDmemCopyTo();
        if (iVar1 != 0) {
          nvswitch_assert_log();
        }
      }
      else {
        flcnableEmemCopyTo(param_1,*(undefined8 *)(param_2 + 0x48));
      }
    }
    else {
      (**(code **)(param_3 + 0x60))
                (param_1,param_2,param_3,*(undefined4 *)(param_3 + 0x80),param_4,param_5);
    }
    *(int *)(param_3 + 0x80) = *(int *)(param_3 + 0x80) + (param_5 + 3U & 0xfffffffc);
    return;
  }
  nvswitch_assert_log();
  return;
}


// ===== 001bbc60 _flcnQueuePop_dmem =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
_flcnQueuePop_dmem(undefined8 param_1,long param_2,long param_3,undefined8 param_4,uint param_5,
                  uint *param_6)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  uint local_3c;
  
  *param_6 = 0;
  if ((*(char *)(param_3 + 0xa0) != '\0') && (*(int *)(param_3 + 0x9c) == 0)) {
    (**(code **)(param_3 + 0x38))();
    uVar1 = *(uint *)(param_3 + 0x80);
    if (uVar1 != local_3c) {
      if (uVar1 < local_3c) {
        uVar3 = local_3c - uVar1;
      }
      else {
        uVar3 = (*(int *)(param_3 + 0x90) + *(int *)(param_3 + 0x84)) - uVar1;
      }
      if (uVar3 < param_5) {
        nvswitch_assert_log();
        pcVar2 = *(code **)(param_3 + 0x58);
        param_5 = uVar3;
      }
      else {
        pcVar2 = *(code **)(param_3 + 0x58);
      }
      if (pcVar2 == _flcnQueueRead_dmem) {
        if (*(char *)(param_2 + 0x60) == '\0') {
          iVar4 = flcnDmemCopyFrom();
          if (iVar4 != 0) {
            nvswitch_assert_log();
          }
        }
        else {
          flcnableEmemCopyFrom(param_1,*(undefined8 *)(param_2 + 0x48),uVar1,param_4,param_5,0);
        }
      }
      else {
        (*pcVar2)(param_1,param_2,param_3,uVar1,param_4,param_5);
      }
      *(int *)(param_3 + 0x80) = *(int *)(param_3 + 0x80) + (param_5 + 3 & 0xfffffffc);
      *param_6 = param_5;
      return 0;
    }
    return 0;
  }
  nvswitch_assert_log();
  return 0xffff;
}


// ===== 001bbe00 flcnQueueConstruct_dmem_nvswitch =====

ulong flcnQueueConstruct_dmem_nvswitch(undefined8 param_1,undefined8 param_2,long *param_3)

{
  long lVar1;
  ulong uVar2;
  uint in_stack_00000008;
  undefined4 in_stack_00000010;
  
  uVar2 = flcnQueueConstruct_common_nvswitch();
  if ((int)uVar2 == 0) {
    lVar1 = *param_3;
    if (lVar1 == 0) {
      nvswitch_assert_log();
      uVar2 = 0x3d;
    }
    else {
      *(code **)(lVar1 + 0x18) = _flcnQueueOpenWrite_dmem;
      *(code **)(lVar1 + 0x30) = _flcnQueueRewind_dmem;
      *(code **)(lVar1 + 0x20) = _flcnQueuePop_dmem;
      *(code **)(lVar1 + 0x28) = _flcnQueuePush_dmem;
      *(code **)(lVar1 + 0x48) = _flcnQueueTailGet_dmem;
      *(code **)(lVar1 + 0x50) = _flcnQueueTailSet_dmem;
      *(code **)(lVar1 + 0x58) = _flcnQueueRead_dmem;
      *(code **)(lVar1 + 0x60) = _flcnQueueWrite_dmem;
      *(code **)(lVar1 + 0x68) = _flcnQueueHasRoom_dmem;
      *(uint *)(lVar1 + 0x98) = in_stack_00000008 >> 1;
    }
    return uVar2;
  }
  nvswitch_assert_log(param_1,param_2,in_stack_00000008,in_stack_00000010);
  return uVar2 & 0xffffffff;
}


// ===== 001bbeb0 _flcnQueueIsEmpty =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

bool _flcnQueueIsEmpty(undefined8 param_1,undefined8 param_2,long param_3)

{
  int local_10;
  int local_c;
  
  (**(code **)(param_3 + 0x38))();
  if ((*(char *)(param_3 + 0xa0) != '\0') && (*(int *)(param_3 + 0x9c) == 0)) {
    return local_10 == *(int *)(param_3 + 0x80);
  }
  (**(code **)(param_3 + 0x48))(param_1,param_2,param_3,&local_c);
  return local_10 == local_c;
}


// ===== 001bbf20 _flcnQueuePopulateRewindCmd =====

uint _flcnQueuePopulateRewindCmd
               (undefined8 param_1,undefined8 param_2,long param_3,undefined1 *param_4)

{
  uint uVar1;
  
  *param_4 = 0;
  uVar1 = *(uint *)(param_3 + 0x94);
  param_4[1] = (char)uVar1;
  return uVar1 & 0xff;
}


// ===== 001bbf40 _flcnQueueOpenRead =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _flcnQueueOpenRead(undefined8 param_1,undefined8 param_2,long param_3)

{
  if (*(char *)(param_3 + 0xa0) == '\0') {
    (**(code **)(param_3 + 0x48))();
    *(undefined1 *)(param_3 + 0xa0) = 1;
    *(undefined4 *)(param_3 + 0x9c) = 0;
    return 0;
  }
  nvswitch_assert_log();
  return 0xffff;
}


// ===== 001bbfa0 _flcnQueueHeadSet =====

void _flcnQueueHeadSet(undefined8 param_1,long param_2,long param_3,undefined4 param_4)

{
  if (*(long *)(param_2 + 0x58) == 0) {
    nvswitch_assert_log();
    if (*(uint *)(param_3 + 0x88) <= *(uint *)(*(long *)(param_2 + 0x58) + 8)) {
      flcnCmdQueueHeadSet();
      return;
    }
    flcnMsgQueueHeadSet(param_1,param_2,param_3,param_4);
    return;
  }
  if (*(uint *)(param_3 + 0x88) <= *(uint *)(*(long *)(param_2 + 0x58) + 8)) {
    flcnCmdQueueHeadSet();
    return;
  }
  flcnMsgQueueHeadSet();
  return;
}


// ===== 001bc020 _flcnQueueHeadGet =====

void _flcnQueueHeadGet(undefined8 param_1,long param_2,long param_3,undefined8 param_4)

{
  if (*(long *)(param_2 + 0x58) == 0) {
    nvswitch_assert_log();
    if (*(uint *)(param_3 + 0x88) <= *(uint *)(*(long *)(param_2 + 0x58) + 8)) {
      flcnCmdQueueHeadGet();
      return;
    }
    flcnMsgQueueHeadGet(param_1,param_2,param_3,param_4);
    return;
  }
  if (*(uint *)(param_3 + 0x88) <= *(uint *)(*(long *)(param_2 + 0x58) + 8)) {
    flcnCmdQueueHeadGet();
    return;
  }
  flcnMsgQueueHeadGet();
  return;
}


// ===== 001bc0a0 _flcnQueueCmdPostNonBlocking_IMPL =====

int _flcnQueueCmdPostNonBlocking_IMPL
              (undefined8 param_1,long param_2,long param_3,undefined8 param_4,undefined8 param_5,
              uint param_6,undefined8 param_7,undefined8 param_8,int *param_9,undefined8 param_10)

{
  undefined1 uVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  undefined1 *puVar6;
  
  if ((param_2 == 0) || (lVar2 = *(long *)(param_2 + 0x58), lVar2 == 0)) {
    nvswitch_assert_log();
    return 0x40;
  }
  if (param_9 == (int *)0x0) {
    return 0x1f;
  }
  lVar3 = *(long *)(lVar2 + 0x30);
  iVar5 = soeWaitForInitAck_HAL(param_1,*(undefined8 *)(param_2 + 0x48));
  if (iVar5 == 0) {
    if (param_3 == 0) {
      return 0x1f;
    }
    if (*(byte *)(param_3 + 1) < 4) {
      return 0x1f;
    }
    cVar4 = flcnableQueueCmdValidate
                      (param_1,*(undefined8 *)(param_2 + 0x48),param_3,param_4,param_5,param_6);
    if (cVar4 == '\0') {
      return 0x1f;
    }
    puVar6 = (undefined1 *)flcnQueueSeqInfoAcq(param_1,param_2);
    iVar5 = 0x1a;
    if (puVar6 != (undefined1 *)0x0) {
      uVar1 = *puVar6;
      *(undefined1 *)(param_3 + 2) = 1;
      *(undefined1 *)(param_3 + 3) = uVar1;
      *(ulong *)(puVar6 + 0x20) = (ulong)param_6 * 0xa8 + lVar3;
      *(undefined8 *)(puVar6 + 0x10) = param_7;
      *(undefined8 *)(puVar6 + 0x18) = param_8;
      iVar5 = *(int *)(lVar2 + 0x44);
      *(int *)(lVar2 + 0x44) = iVar5 + 1;
      *(int *)(puVar6 + 4) = iVar5;
      *param_9 = iVar5;
      iVar5 = flcnableQueueCmdPostExtension
                        (param_1,*(undefined8 *)(param_2 + 0x48),param_3,param_4,param_5,param_10,
                         puVar6);
      if (iVar5 == 0) {
        iVar5 = flcnQueueCmdWrite(param_1,param_2,param_6,param_3,param_10);
        if (iVar5 == 0) {
          *(undefined4 *)(puVar6 + 8) = 2;
          return 0;
        }
        flcnQueueSeqInfoFree(param_1,param_2,puVar6);
        flcnQueueSeqInfoRel(param_1,param_2,puVar6);
      }
      else {
        flcnQueueSeqInfoRel(param_1,param_2,puVar6,0x1bc181);
      }
      flcnQueueSeqInfoRel(param_1,param_2,puVar6);
    }
  }
  else {
    nvswitch_assert_log();
  }
  return iVar5;
}


// ===== 001bc2c0 _flcnQueueCmdCancel_IMPL =====

undefined8 _flcnQueueCmdCancel_IMPL(void)

{
  long lVar1;
  
  lVar1 = flcnQueueSeqInfoFind();
  if (lVar1 != 0) {
    *(undefined4 *)(lVar1 + 8) = 3;
    return 0;
  }
  return 0x57;
}


// ===== 001bc2f0 _flcnQueueCmdStatus_IMPL =====

char _flcnQueueCmdStatus_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = *(long *)(param_2 + 0x58);
  if (lVar2 == 0) {
    nvswitch_assert_log();
  }
  lVar3 = flcnQueueSeqInfoFind(param_1,param_2,param_3);
  if (lVar3 != 0) {
    uVar1 = *(uint *)(lVar3 + 8);
    if (uVar1 < 3) {
      return (uVar1 == 0) + '\x01';
    }
    return (uVar1 == 3) * '\x02';
  }
  return (param_3 < *(uint *)(lVar2 + 0x44)) * '\x02';
}


// ===== 001bc380 _flcnQueueResponseHandle_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 _flcnQueueResponseHandle_IMPL(undefined8 param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  long lVar2;
  
  if (*(long *)(param_2 + 0x58) == 0) {
    nvswitch_assert_log();
  }
  if (((param_3 == 0) ||
      (lVar2 = flcnableQueueSeqInfoGet
                         (param_1,*(undefined8 *)(param_2 + 0x48),*(undefined1 *)(param_3 + 3)),
      lVar2 == 0)) || (*(int *)(lVar2 + 8) != 2)) {
    uVar1 = 0xffff;
  }
  else {
    if (*(code **)(lVar2 + 0x10) != (code *)0x0) {
      (**(code **)(lVar2 + 0x10))
                (param_1,param_3,*(undefined8 *)(lVar2 + 0x18),*(undefined4 *)(lVar2 + 4),0);
    }
    uVar1 = flcnQueueSeqInfoFree(param_1,param_2,lVar2);
    flcnQueueSeqInfoRel(param_1,param_2,lVar2);
  }
  return uVar1;
}


// ===== 001bc450 _flcnQueueSeqInfoCancelAll_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _flcnQueueSeqInfoCancelAll_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  
  if (*(int *)(param_2 + 0x34) != 0) {
    uVar2 = 0;
    do {
      lVar1 = flcnableQueueSeqInfoGet(param_1,*(undefined8 *)(param_2 + 0x48),uVar2);
      if (*(int *)(lVar1 + 8) != 0) {
        if (*(int *)(lVar1 + 8) != 3) {
          *(undefined4 *)(lVar1 + 8) = 3;
          if (*(code **)(lVar1 + 0x10) != (code *)0x0) {
            (**(code **)(lVar1 + 0x10))
                      (param_1,0,*(undefined8 *)(lVar1 + 0x18),*(undefined4 *)(lVar1 + 4),0x40);
          }
        }
        flcnQueueSeqInfoFree(param_1,param_2,lVar1);
      }
      uVar2 = uVar2 + 1;
      flcnQueueSeqInfoRel(param_1,param_2,lVar1);
    } while (uVar2 < *(uint *)(param_2 + 0x34));
    return;
  }
  return;
}


// ===== 001bc500 _flcnQueueSeqInfoStateInit_IMPL =====

void _flcnQueueSeqInfoStateInit_IMPL(undefined8 param_1,long param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  
  if (*(int *)(param_2 + 0x34) != 0) {
    uVar2 = 0;
    do {
      puVar1 = (undefined1 *)flcnableQueueSeqInfoGet(param_1,*(undefined8 *)(param_2 + 0x48),uVar2);
      *puVar1 = (char)uVar2;
      uVar2 = uVar2 + 1;
      flcnQueueSeqInfoRel(param_1,param_2,puVar1);
    } while (uVar2 < *(uint *)(param_2 + 0x34));
    return;
  }
  return;
}


// ===== 001bc560 _flcnQueueSeqInfoAcq_IMPL =====

long _flcnQueueSeqInfoAcq_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  
  lVar1 = *(long *)(param_2 + 0x58);
  uVar3 = (ulong)(*(int *)(lVar1 + 0x48) + 1) % (ulong)*(uint *)(param_2 + 0x34);
  if (*(int *)(lVar1 + 0x48) != (int)uVar3) {
    do {
      lVar2 = flcnableQueueSeqInfoGet(param_1,*(undefined8 *)(param_2 + 0x48),uVar3);
      if (*(int *)(lVar2 + 8) == 0) {
        *(undefined4 *)(lVar2 + 8) = 1;
        *(int *)(lVar1 + 0x48) = (int)uVar3;
        return lVar2;
      }
      uVar3 = (ulong)((int)uVar3 + 1) % (ulong)*(uint *)(param_2 + 0x34);
    } while (*(int *)(lVar1 + 0x48) != (int)uVar3);
  }
  return 0;
}


// ===== 001bc600 _flcnQueueSeqInfoFind_IMPL =====

long _flcnQueueSeqInfoFind_IMPL(undefined8 param_1,long param_2,int param_3)

{
  long lVar1;
  uint uVar2;
  
  if (*(int *)(param_2 + 0x34) == 0) {
    return 0;
  }
  uVar2 = 0;
  do {
    lVar1 = flcnableQueueSeqInfoGet(param_1,*(undefined8 *)(param_2 + 0x48),uVar2);
    if (*(int *)(lVar1 + 4) == param_3) {
      return lVar1;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < *(uint *)(param_2 + 0x34));
  return 0;
}


// ===== 001bc660 _flcnQueueEventHandle_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _flcnQueueEventHandle_IMPL(undefined8 param_1,long param_2,byte *param_3,undefined4 param_4)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  code *pcVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  lVar1 = *(long *)(param_2 + 0x58);
  uVar2 = *(undefined8 *)(param_2 + 0x48);
  if (lVar1 == 0) {
    nvswitch_assert_log();
  }
  if ((*param_3 == *(byte *)(lVar1 + 1)) &&
     (iVar3 = flcnableHandleInitEvent(param_1,uVar2,param_3), iVar3 != 0)) {
    nvswitch_assert_log();
    return iVar3;
  }
  puVar5 = *(undefined4 **)(lVar1 + 0x38);
  do {
    puVar6 = puVar5;
    if (puVar5 == (undefined4 *)0x0) {
      return 0;
    }
    while (puVar5 = *(undefined4 **)(puVar6 + 8), puVar6[1] == (uint)*param_3) {
      if (*(long *)(puVar6 + 2) != 0) {
        nvswitch_os_memcpy(*(long *)(puVar6 + 2),param_3,param_3[1]);
      }
      pcVar4 = *(code **)(puVar6 + 4);
      if (pcVar4 == (code *)0x0) {
        nvswitch_assert_log();
        pcVar4 = *(code **)(puVar6 + 4);
      }
      (*pcVar4)(param_1,param_3,*(undefined8 *)(puVar6 + 6),*puVar6,param_4);
      puVar6 = puVar5;
      if (puVar5 == (undefined4 *)0x0) {
        return 0;
      }
    }
  } while( true );
}


// ===== 001bc760 _flcnQueueEventUnregister_IMPL =====

undefined8 _flcnQueueEventUnregister_IMPL(undefined8 param_1,long param_2,int param_3)

{
  long lVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  lVar1 = *(long *)(param_2 + 0x58);
  if (lVar1 == 0) {
    nvswitch_assert_log();
    return 0x3d;
  }
  piVar4 = *(int **)(lVar1 + 0x38);
  piVar3 = (int *)0x0;
  while( true ) {
    piVar2 = piVar4;
    if (piVar2 == (int *)0x0) {
      return 0x57;
    }
    if (*piVar2 == param_3) break;
    piVar4 = *(int **)(piVar2 + 8);
    piVar3 = piVar2;
  }
  if (piVar3 == (int *)0x0) {
    *(undefined8 *)(lVar1 + 0x38) = *(undefined8 *)(piVar2 + 8);
  }
  else {
    *(undefined8 *)(piVar3 + 8) = *(undefined8 *)(piVar2 + 8);
  }
  piVar2[8] = 0;
  piVar2[9] = 0;
  nvswitch_os_free();
  return 0;
}


// ===== 001bc7e0 _flcnQueueSeqInfoFree_IMPL =====

undefined8 _flcnQueueSeqInfoFree_IMPL(undefined8 param_1,long param_2)

{
  flcnableQueueSeqInfoFree(param_1,*(undefined8 *)(param_2 + 0x48));
  return 0;
}


// ===== 001bc800 _flcnQueueSeqInfoRel_IMPL =====

void _flcnQueueSeqInfoRel_IMPL(undefined8 param_1,long param_2,long param_3)

{
  *(undefined8 *)(param_3 + 0x10) = 0;
  *(undefined8 *)(param_3 + 4) = 0xffffffff;
  *(undefined8 *)(param_3 + 0x18) = 0;
  flcnableQueueSeqInfoClear(param_1,*(undefined8 *)(param_2 + 0x48));
  return;
}


// ===== 001bc830 _flcnQueueClose =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _flcnQueueClose(undefined8 param_1,undefined8 param_2,long param_3,char param_4)

{
  if (*(char *)(param_3 + 0xa0) != '\0') {
    if (param_4 != '\0') {
      if (*(int *)(param_3 + 0x9c) != 0) {
        (**(code **)(param_3 + 0x40))();
        *(undefined1 *)(param_3 + 0xa0) = 0;
        return 0;
      }
      (**(code **)(param_3 + 0x50))();
      *(undefined1 *)(param_3 + 0xa0) = 0;
      return 0;
    }
    *(undefined1 *)(param_3 + 0xa0) = 0;
  }
  return 0;
}


// ===== 001bc8b0 _flcnQueueCmdWrite_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
_flcnQueueCmdWrite_IMPL(undefined8 param_1,long param_2,ulong param_3,long param_4,long param_5)

{
  long lVar1;
  char cVar2;
  char cVar3;
  undefined8 uVar4;
  uint uVar5;
  long lVar6;
  undefined8 *puVar7;
  
  lVar1 = *(long *)(param_2 + 0x58);
  if (param_5 == 0) {
    nvswitch_assert_log();
  }
  if (lVar1 == 0) {
    nvswitch_assert_log();
  }
  lVar6 = *(long *)(lVar1 + 0x30);
  if (lVar6 == 0) {
    nvswitch_assert_log();
    lVar6 = *(long *)(lVar1 + 0x30);
  }
  puVar7 = (undefined8 *)(lVar6 + (param_3 & 0xffffffff) * 0xa8);
  uVar5 = 0;
  while( true ) {
    cVar2 = nvswitch_timeout_check(param_5);
    uVar4 = (*(code *)puVar7[3])(param_1,param_2,puVar7,*(undefined1 *)(param_4 + 1));
    if ((int)uVar4 != 0x1a) break;
    cVar3 = soeIsCpuHalted_HAL(param_1,*(undefined8 *)(param_2 + 0x48));
    if (cVar3 != '\0') {
      return 0x70;
    }
    uVar5 = uVar5 + 1;
    if ((uVar5 < 4) || ((uVar5 & 0x3ff) != 0)) {
      if (cVar2 != '\0') {
        return 0x65;
      }
    }
    else {
      nvswitch_os_sleep(1);
      if (cVar2 != '\0') {
        return 0x65;
      }
    }
  }
  if ((int)uVar4 != 0) {
    return uVar4;
  }
  (*(code *)puVar7[5])(param_1,param_2,puVar7,param_4,*(undefined1 *)(param_4 + 1));
  if ((code *)*puVar7 == _flcnQueueClose) {
    uVar4 = _flcnQueueClose();
    return uVar4;
  }
  uVar4 = (*(code *)*puVar7)(param_1,param_2,puVar7,1);
  return uVar4;
}


// ===== 001bca50 _flcnQueueCmdWait_IMPL =====

undefined8
_flcnQueueCmdWait_IMPL(undefined8 param_1,long param_2,undefined4 param_3,undefined8 param_4)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar2 = _flcnQueueCmdStatus_IMPL();
  uVar3 = 0x3f;
  if (iVar2 != 0) {
    do {
      cVar1 = nvswitch_timeout_check(param_4);
      soeService_HAL(param_1,*(undefined8 *)(param_2 + 0x48));
      iVar2 = _flcnQueueCmdStatus_IMPL(param_1,param_2,param_3);
      if (iVar2 == 2) {
        return 0;
      }
    } while (cVar1 == '\0');
    uVar3 = 0x65;
  }
  return uVar3;
}


// ===== 001bcaf0 _flcnQueueEventRegister_IMPL =====

undefined8
_flcnQueueEventRegister_IMPL
          (undefined8 param_1,long param_2,uint param_3,undefined8 param_4,long param_5,
          undefined8 param_6,int *param_7)

{
  byte *pbVar1;
  long lVar2;
  int *piVar3;
  undefined8 uVar4;
  int iVar5;
  
  pbVar1 = *(byte **)(param_2 + 0x58);
  if (pbVar1 == (byte *)0x0) {
    nvswitch_assert_log();
  }
  if (((param_5 != 0) && (param_7 != (int *)0x0)) && (param_3 < *pbVar1)) {
    lVar2 = *(long *)(param_2 + 0x58);
    if (lVar2 == 0) {
      nvswitch_assert_log();
    }
    iVar5 = *(int *)(lVar2 + 0x40);
    piVar3 = *(int **)(lVar2 + 0x38);
    do {
      if (piVar3 == (int *)0x0) {
        *(int *)(lVar2 + 0x40) = iVar5 + 1;
        piVar3 = (int *)nvswitch_os_malloc_trace(0x28,0,0);
        if (piVar3 == (int *)0x0) {
          uVar4 = 0x51;
        }
        else {
          piVar3[1] = param_3;
          *(undefined8 *)(piVar3 + 2) = param_4;
          *(long *)(piVar3 + 4) = param_5;
          *(undefined8 *)(piVar3 + 6) = param_6;
          uVar4 = *(undefined8 *)(pbVar1 + 0x38);
          *piVar3 = iVar5;
          *(undefined8 *)(piVar3 + 8) = uVar4;
          *(int **)(pbVar1 + 0x38) = piVar3;
          *param_7 = iVar5;
          uVar4 = 0;
        }
        return uVar4;
      }
      while (*piVar3 == iVar5) {
        iVar5 = iVar5 + 1;
        piVar3 = *(int **)(lVar2 + 0x38);
        if (*(int *)(lVar2 + 0x40) == iVar5) {
          nvswitch_assert_log();
          nvswitch_assert_log();
          return 0xffff;
        }
      }
      piVar3 = *(int **)(piVar3 + 8);
    } while( true );
  }
  return 0x1f;
}


// ===== 001bcc60 flcnQueueConstruct_common_nvswitch =====

undefined8
flcnQueueConstruct_common_nvswitch
          (undefined8 param_1,undefined8 param_2,long *param_3,undefined4 param_4,undefined4 param_5
          ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined8 *puVar1;
  long lVar2;
  
  if (param_3 == (long *)0x0) {
    nvswitch_assert_log();
    return 0x3d;
  }
  puVar1 = (undefined8 *)*param_3;
  if (puVar1 == (undefined8 *)0x0) {
    lVar2 = nvswitch_os_malloc_trace(0xa8,0,0);
    *param_3 = lVar2;
    if (lVar2 == 0) {
      return 0x51;
    }
    nvswitch_os_memset(lVar2,0,0xa8);
    puVar1 = (undefined8 *)*param_3;
  }
  *(undefined4 *)(puVar1 + 0x11) = param_4;
  *(undefined4 *)((long)puVar1 + 0x8c) = param_5;
  *(undefined4 *)(puVar1 + 0x12) = param_7;
  *(undefined4 *)((long)puVar1 + 0x84) = param_6;
  *(undefined4 *)((long)puVar1 + 0x94) = param_8;
  *(undefined4 *)(puVar1 + 0x10) = param_6;
  *(undefined4 *)((long)puVar1 + 0x9c) = 0;
  *(undefined2 *)(puVar1 + 0x14) = 0;
  *puVar1 = _flcnQueueClose;
  puVar1[1] = _flcnQueueIsEmpty;
  puVar1[2] = _flcnQueueOpenRead;
  puVar1[7] = _flcnQueueHeadGet;
  puVar1[8] = _flcnQueueHeadSet;
  puVar1[0xe] = _flcnQueuePopulateRewindCmd;
  return 0;
}


// ===== 001bcd60 flcnQueueSetupHal =====

void flcnQueueSetupHal(long *param_1)

{
  long lVar1;
  
  lVar1 = *param_1;
  *(code **)(lVar1 + 8) = _flcnQueueCmdWrite_IMPL;
  *(code **)(lVar1 + 0x78) = _flcnQueueSeqInfoFind_IMPL;
  *(code **)(lVar1 + 0x80) = _flcnQueueSeqInfoAcq_IMPL;
  *(code **)(lVar1 + 0x88) = _flcnQueueSeqInfoRel_IMPL;
  *(code **)(lVar1 + 0x90) = _flcnQueueSeqInfoStateInit_IMPL;
  *(code **)(lVar1 + 0x98) = _flcnQueueSeqInfoCancelAll_IMPL;
  *(code **)(lVar1 + 0xa0) = _flcnQueueSeqInfoFree_IMPL;
  *(code **)(lVar1 + 0xa8) = _flcnQueueEventRegister_IMPL;
  *(code **)(lVar1 + 0xb0) = _flcnQueueEventUnregister_IMPL;
  *(code **)(lVar1 + 0xb8) = _flcnQueueEventHandle_IMPL;
  *(code **)(lVar1 + 0xc0) = _flcnQueueResponseHandle_IMPL;
  *(code **)(lVar1 + 200) = _flcnQueueCmdStatus_IMPL;
  *(code **)(lVar1 + 0x10) = _flcnQueueCmdCancel_IMPL;
  *(code **)(lVar1 + 0x18) = _flcnQueueCmdPostNonBlocking_IMPL;
  *(code **)(lVar1 + 0x20) = _flcnQueueCmdWait_IMPL;
  return;
}


// ===== 001bce00 _flcnQueueReaderReadHeader =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong _flcnQueueReaderReadHeader
                (undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  char cVar1;
  ulong uVar2;
  undefined4 local_c;
  
  cVar1 = (**(code **)(param_3 + 8))();
  if (cVar1 != '\0') {
    nvswitch_assert_log(param_1,param_2,param_3,param_4);
    return 0x40;
  }
  uVar2 = (**(code **)(param_3 + 0x20))();
  if ((int)uVar2 == 0) {
    if (local_c == 0) {
      nvswitch_assert_log();
      uVar2 = uVar2 & 0xffffffff;
    }
    if (local_c != 4) {
      nvswitch_assert_log();
      return 0xffff;
    }
  }
  return uVar2;
}


// ===== 001bce90 _flcnQueueReadData_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong _flcnQueueReadData_IMPL
                (undefined8 param_1,long param_2,ulong param_3,byte *param_4,char param_5)

{
  undefined8 *puVar1;
  long lVar2;
  char cVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  int local_3c [3];
  
  if (param_2 == 0) {
    nvswitch_assert_log();
  }
  lVar2 = *(long *)(param_2 + 0x58);
  if (lVar2 == 0) {
    nvswitch_assert_log();
    lVar8 = _DAT_00000030;
  }
  else {
    lVar8 = *(long *)(lVar2 + 0x30);
  }
  if (lVar8 == 0) {
    nvswitch_assert_log();
    lVar8 = *(long *)(lVar2 + 0x30);
  }
  puVar1 = (undefined8 *)(lVar8 + (param_3 & 0xffffffff) * 0xa8);
  cVar3 = (*(code *)puVar1[1])(param_1,param_2,puVar1);
  if (cVar3 != '\0') {
    return 0x55;
  }
  uVar5 = (*(code *)puVar1[2])(param_1,param_2,puVar1);
  if (uVar5 != 0) {
    return (ulong)uVar5;
  }
  iVar6 = _flcnQueueReaderReadHeader(param_1,param_2,puVar1,param_4,param_5);
  if (iVar6 == 0) {
    bVar4 = *param_4;
    if (param_5 == '\0') {
      if (bVar4 == 0) {
        (*(code *)puVar1[6])(param_1,param_2,puVar1);
        iVar6 = _flcnQueueReaderReadHeader(param_1,param_2,puVar1,param_4,0);
        if (iVar6 != 0) goto LAB_001bd040;
        bVar4 = *param_4;
      }
      if (bVar4 < **(byte **)(param_2 + 0x58)) {
        bVar4 = param_4[1];
LAB_001bcfa8:
        if (bVar4 < 5) {
LAB_001bcfb0:
          uVar7 = (*(code *)*puVar1)(param_1,param_2,puVar1,1);
          return uVar7;
        }
        cVar3 = (*(code *)puVar1[1])(param_1,param_2,puVar1);
        if (cVar3 != '\0') {
          nvswitch_assert_log();
        }
        bVar4 = param_4[1];
        uVar5 = (*(code *)puVar1[4])(param_1,param_2,puVar1,param_4 + 4,bVar4 - 4,local_3c);
        if (uVar5 != 0) goto LAB_001bd046;
        if (local_3c[0] == 0) {
          nvswitch_assert_log();
        }
        if (local_3c[0] == bVar4 - 4) goto LAB_001bcfb0;
LAB_001bd034:
        nvswitch_assert_log();
      }
    }
    else {
      if (bVar4 == 0) {
        (*(code *)puVar1[6])(param_1,param_2,puVar1);
        iVar6 = _flcnQueueReaderReadHeader(param_1,param_2,puVar1,param_4,param_5);
        if (iVar6 != 0) goto LAB_001bd040;
        bVar4 = *param_4;
      }
      if (bVar4 < **(byte **)(param_2 + 0x58)) {
        bVar4 = param_4[1];
        if ((uint)bVar4 <= *(uint *)(lVar2 + 0xc)) goto LAB_001bcfa8;
        goto LAB_001bd034;
      }
    }
  }
LAB_001bd040:
  uVar5 = 0xffff;
LAB_001bd046:
  (*(code *)*puVar1)(param_1,param_2,puVar1,1);
  return (ulong)uVar5;
}


// ===== 001bd130 flcnQueueRdSetupHal =====

void flcnQueueRdSetupHal(undefined8 *param_1)

{
  *(code **)*param_1 = _flcnQueueReadData_IMPL;
  return;
}


// ===== 001bd140 _flcnDbgInfoDmemOffsetSet_IMPL =====

void _flcnDbgInfoDmemOffsetSet_IMPL(undefined8 param_1,long param_2,undefined2 param_3)

{
  *(undefined2 *)(param_2 + 0x40) = param_3;
  return;
}


// ===== 001bd150 flcnRtosSetupHal =====

void flcnRtosSetupHal(long *param_1)

{
  *(code **)(*param_1 + 0xe8) = _flcnDbgInfoDmemOffsetSet_IMPL;
  return;
}


// ===== 001bd170 _flcnGetCoreInfo_v03_00 =====

void _flcnGetCoreInfo_v03_00(undefined8 param_1,long param_2)

{
  undefined1 uVar1;
  uint uVar2;
  
  uVar2 = flcnRegRead_HAL(param_1,param_2,300);
  *(byte *)(param_2 + 0x45) = (byte)(uVar2 >> 4) & 3;
  uVar1 = flcnableReadCoreRev(param_1,*(undefined8 *)(param_2 + 0x48));
  *(byte *)(param_2 + 0x46) = (byte)(uVar2 >> 0x1e) & 1;
  *(undefined1 *)(param_2 + 0x44) = uVar1;
  return;
}


// ===== 001bd1d0 flcnSetupHal_v03_00 =====

void flcnSetupHal_v03_00(long *param_1)

{
  *(code **)(*param_1 + 0x120) = _flcnGetCoreInfo_v03_00;
  return;
}


// ===== 001bd1f0 flcnSetupHal_v04_00 =====

void flcnSetupHal_v04_00(void)

{
  flcnSetupHal_v03_00();
  return;
}


// ===== 001bd200 flcnSetupHal_v05_01 =====

void flcnSetupHal_v05_01(void)

{
  flcnSetupHal_v04_00();
  return;
}


// ===== 001bd210 flcnSetupHal_v06_00 =====

void flcnSetupHal_v06_00(void)

{
  flcnSetupHal_v05_01();
  return;
}


// ===== 001bd220 nvswitch_fsp_read_message =====

int nvswitch_fsp_read_message(undefined8 param_1,long param_2,uint param_3,undefined8 param_4)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  uint uVar8;
  uint local_54;
  char local_42;
  undefined1 local_41;
  int local_40;
  int local_3c [3];
  
  local_42 = '\0';
  nvswitch_fsp_get_msgq_head_tail(param_1,&local_40,local_3c);
  iVar4 = 0;
  if (local_40 != local_3c[0]) {
    uVar2 = nvswitch_fsp_get_channel_size(param_1);
    lVar5 = nvswitch_os_malloc_trace(uVar2,0,0);
    if (lVar5 != 0) {
      if ((byte)(local_42 - 2U) < 2) {
        local_54 = 0;
      }
      else {
        local_54 = 0;
        do {
          while( true ) {
            cVar1 = nvswitch_timeout_check(param_4);
            nvswitch_fsp_get_msgq_head_tail(param_1,&local_40,local_3c);
            if (local_40 != local_3c[0]) break;
            if (cVar1 != '\0') goto LAB_001bd3e0;
            nvswitch_os_sleep(1);
          }
          nvswitch_fsp_get_msgq_head_tail(param_1,&local_40,local_3c);
          uVar7 = local_3c[0] - local_40;
          if (0xfffffffb < uVar7) {
LAB_001bd431:
            iVar4 = -8;
            goto LAB_001bd3ed;
          }
          uVar8 = uVar7 + 4;
          uVar3 = nvswitch_fsp_get_channel_size(param_1);
          if (uVar3 < uVar8) goto LAB_001bd431;
          nvswitch_fsp_read_from_emem(param_1,lVar5,uVar8);
          iVar4 = nvswitch_fsp_get_packet_info(param_1,lVar5,uVar8,&local_42,&local_41);
          if (iVar4 != 0) goto LAB_001bd3ed;
          if ((local_42 != '\0') && (local_42 != '\x03')) {
            if (param_2 != 0) {
              lVar6 = 4;
              goto LAB_001bd374;
            }
LAB_001bd3e0:
            iVar4 = -7;
            goto LAB_001bd3ed;
          }
          uVar7 = uVar7 - 3;
          lVar6 = 7;
          if (param_2 == 0) {
            if (local_42 != '\x03') goto LAB_001bd3e0;
            local_54 = local_54 + uVar7;
          }
          else {
LAB_001bd374:
            if (param_3 < local_54 + uVar7) goto LAB_001bd3e0;
            nvswitch_os_memcpy((ulong)local_54 + param_2,lVar6 + lVar5,uVar7);
            local_54 = local_54 + uVar7;
          }
          nvswitch_fsp_update_msgq_head_tail(param_1,local_40,local_40);
        } while (1 < (byte)(local_42 - 2U));
      }
      lVar6 = lVar5 + 7;
      if (param_2 != 0) {
        lVar6 = param_2;
      }
      iVar4 = nvswitch_fsp_process_nvdm_msg(param_1,lVar6,local_54);
LAB_001bd3ed:
      nvswitch_os_free(lVar5);
      return iVar4;
    }
    iVar4 = -2;
  }
  return iVar4;
}


// ===== 001bd470 nvswitch_fsp_send_packet =====

undefined8 nvswitch_fsp_send_packet(undefined8 param_1,undefined8 param_2,int param_3)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  uint uVar4;
  bool bVar5;
  int local_48;
  int local_44;
  undefined1 local_40 [16];
  
  nvswitch_timeout_create(10000000,local_40);
  while( true ) {
    cVar1 = nvswitch_timeout_check(local_40);
    nvswitch_fsp_get_msgq_head_tail(param_1,&local_48,&local_44);
    bVar5 = local_48 != local_44;
    nvswitch_fsp_get_cmdq_head_tail(param_1,&local_48,&local_44);
    if (local_48 == local_44) break;
    if (bVar5) {
      nvswitch_fsp_read_message(param_1,0,0,local_40);
      return 0xfffffff9;
    }
    if (local_48 == local_44) break;
    if (cVar1 != '\0') {
      return 0xfffffff9;
    }
    nvswitch_os_sleep(1);
  }
  uVar4 = param_3 + 3U & 0xfffffffc;
  lVar2 = nvswitch_os_malloc_trace(uVar4,0,0);
  if (lVar2 == 0) {
    uVar3 = 0xfffffffe;
  }
  else {
    nvswitch_os_memset(lVar2,0,uVar4);
    nvswitch_os_memcpy(lVar2,param_2,uVar4);
    nvswitch_fsp_write_to_emem(param_1,lVar2,uVar4);
    nvswitch_fsp_update_cmdq_head_tail(param_1,0,uVar4 - 4);
    nvswitch_os_free(lVar2);
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 001bd5a0 nvswitch_fsp_send_and_read_message =====

int nvswitch_fsp_send_and_read_message
              (undefined8 param_1,long param_2,uint param_3,undefined4 param_4,undefined8 param_5,
              undefined4 param_6,undefined8 param_7)

{
  uint uVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  ulong local_60;
  undefined1 local_4c;
  int local_40;
  int local_3c [3];
  
  iVar4 = nvswitch_fsp_get_channel_size();
  puVar7 = (undefined4 *)nvswitch_os_malloc_trace(iVar4,0,0);
  if (puVar7 == (undefined4 *)0x0) {
    iVar6 = -2;
  }
  else {
    uVar9 = iVar4 - 8;
    nvswitch_os_memset(puVar7,0,iVar4);
    local_4c = (undefined1)param_4;
    uVar2 = nvswitch_fsp_nvdm_to_seid(param_1,local_4c);
    uVar5 = nvswitch_fsp_create_mctp_header(param_1,1,param_3 <= uVar9,uVar2,0);
    *puVar7 = uVar5;
    uVar5 = nvswitch_fsp_create_nvdm_header(param_1,param_4);
    uVar8 = param_3;
    if (uVar9 <= param_3) {
      uVar8 = uVar9;
    }
    local_60 = (ulong)uVar8;
    puVar7[1] = uVar5;
    nvswitch_os_memcpy(puVar7 + 2,param_2,local_60);
    iVar6 = nvswitch_fsp_send_packet(param_1,puVar7,uVar8 + 8);
    if (iVar6 == 0) {
      if ((uVar9 < param_3) && (param_3 = param_3 - uVar8, param_3 != 0)) {
        uVar9 = iVar4 - 4;
        uVar10 = 0;
        while( true ) {
          uVar1 = uVar9;
          if (param_3 < uVar9) {
            uVar1 = param_3;
          }
          uVar10 = uVar10 + 1;
          nvswitch_os_memset(puVar7,0,iVar4);
          uVar5 = nvswitch_fsp_create_mctp_header(param_1,0,param_3 <= uVar9,uVar2,uVar10 & 3);
          *puVar7 = uVar5;
          nvswitch_os_memcpy(puVar7 + 1,local_60 + param_2,uVar1);
          iVar6 = nvswitch_fsp_send_packet(param_1,puVar7,uVar1 + 4);
          if (iVar6 != 0) goto LAB_001bd741;
          uVar8 = uVar8 + uVar1;
          param_3 = param_3 - uVar1;
          if (param_3 == 0) break;
          local_60 = (ulong)uVar8;
        }
      }
      while( true ) {
        cVar3 = nvswitch_timeout_check(param_7);
        nvswitch_fsp_get_msgq_head_tail(param_1,&local_40,local_3c);
        if (local_40 != local_3c[0]) break;
        if (cVar3 != '\0') {
          iVar6 = -7;
          goto LAB_001bd741;
        }
        nvswitch_os_sleep(1);
      }
      iVar6 = nvswitch_fsp_read_message(param_1,param_5,param_6,param_7);
    }
LAB_001bd741:
    nvswitch_os_free(puVar7);
  }
  return iVar6;
}


// ===== 001bd7e0 nvswitch_inforom_bbx_add_sxid =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_inforom_bbx_add_sxid(long param_1)

{
  (**(code **)(param_1 + 0x848))();
  return;
}


// ===== 001bd7f0 nvswitch_inforom_bbx_unload =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_inforom_bbx_unload(long param_1)

{
  (**(code **)(param_1 + 0x850))();
  return;
}


// ===== 001bd800 nvswitch_inforom_bbx_load =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_inforom_bbx_load(long param_1)

{
  undefined8 uVar1;
  uint local_24;
  uint local_20;
  uint local_1c [3];
  
  uVar1 = nvswitch_os_get_os_version(&local_24,&local_20,local_1c);
  if ((int)uVar1 == 0) {
    if (((local_24 < 0x100) && (local_20 < 0x100)) && (local_1c[0] < 0x10000)) {
      uVar1 = nvswitch_os_get_platform_time_epoch();
      uVar1 = (**(code **)(param_1 + 0x858))
                        (param_1,uVar1,5,local_20 << 8 | local_1c[0] << 0x10 | local_24);
    }
    else {
      uVar1 = 0xfffffff3;
    }
  }
  return uVar1;
}


// ===== 001bd890 nvswitch_inforom_bbx_get_sxid =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_inforom_bbx_get_sxid(long param_1)

{
  (**(code **)(param_1 + 0x860))();
  return;
}


// ===== 001bd8a0 nvswitch_inforom_bbx_get_data =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_inforom_bbx_get_data(long param_1,undefined1 param_2)

{
  (**(code **)(param_1 + 0x868))(param_1,param_2);
  return;
}


// ===== 001bd8c0 nvswitch_inforom_ecc_load =====

int nvswitch_inforom_ecc_load(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  char local_2a;
  byte local_29;
  
  lVar1 = *(long *)(param_1 + 0xf40);
  local_2a = '\0';
  local_29 = 0;
  if (lVar1 != 0) {
    iVar2 = nvswitch_inforom_get_object_version_info(param_1,&DAT_00c7f78b,&local_2a,&local_29);
    if (iVar2 != 0) {
      return 0;
    }
    if ((local_29 & 0xd0) == 0) {
      puVar3 = (undefined8 *)nvswitch_os_malloc_trace(0x20,0,0);
      if (puVar3 == (undefined8 *)0x0) {
        return -2;
      }
      nvswitch_os_memset(puVar3,0,0x20);
      iVar2 = 0;
      if (local_2a == '\x06') {
        *puVar3 = 
        "3s2bwbqqdb3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3db3d2w3d68b"
        ;
        lVar4 = nvswitch_os_malloc_trace(0xee0,0,0);
        puVar3[1] = lVar4;
        if (lVar4 != 0) {
          lVar4 = nvswitch_os_malloc_trace(0x1340,0,0);
          puVar3[2] = lVar4;
          if (lVar4 != 0) {
            iVar2 = nvswitch_inforom_read_object(param_1,&DAT_00c7f78b,*puVar3);
            if ((iVar2 == 0) && (iVar2 = nvswitch_inforom_add_object(lVar1,puVar3[2]), iVar2 == 0))
            {
              *(undefined8 **)(lVar1 + 0xf68) = puVar3;
              nvswitch_smbpbi_refresh_ecc_counts(param_1);
              return 0;
            }
            nvswitch_os_free(puVar3[1]);
            nvswitch_os_free(puVar3[2]);
            goto LAB_001bd94e;
          }
          nvswitch_os_free(puVar3[1]);
        }
        iVar2 = -2;
      }
LAB_001bd94e:
      nvswitch_os_free(puVar3);
      return iVar2;
    }
  }
  return -0xd;
}


// ===== 001bda70 nvswitch_inforom_ecc_flush =====

undefined8 nvswitch_inforom_ecc_flush(long param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  if ((*(long *)(param_1 + 0xf40) == 0) ||
     (puVar1 = *(undefined8 **)(*(long *)(param_1 + 0xf40) + 0xf68), puVar1 == (undefined8 *)0x0)) {
    return 0xfffffff3;
  }
  if (*(char *)(puVar1 + 3) == '\0') {
    return 0;
  }
  uVar2 = nvswitch_inforom_write_object(param_1,&DAT_00c7f78b,*puVar1,puVar1[2],puVar1[1]);
  if ((int)uVar2 != 0) {
    return uVar2;
  }
  *(undefined1 *)(puVar1 + 3) = 0;
  return uVar2;
}


// ===== 001bdaf0 nvswitch_inforom_ecc_unload =====

void nvswitch_inforom_ecc_unload(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_1 + 0xf40);
  if (lVar1 != 0) {
    lVar2 = *(long *)(lVar1 + 0xf68);
    if (lVar2 != 0) {
      nvswitch_inforom_ecc_flush();
      nvswitch_os_free(*(undefined8 *)(lVar2 + 8));
      nvswitch_os_free(*(undefined8 *)(lVar2 + 0x10));
      nvswitch_os_free(lVar2);
      *(undefined8 *)(lVar1 + 0xf68) = 0;
    }
    return;
  }
  return;
}


// ===== 001bdb60 nvswitch_inforom_ecc_log_err_event =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_inforom_ecc_log_err_event(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  if (*(long *)(param_1 + 0xf40) == 0) {
    return 0xfffffff3;
  }
  lVar1 = *(long *)(*(long *)(param_1 + 0xf40) + 0xf68);
  if (lVar1 == 0) {
    uVar3 = 0xfffffff3;
  }
  else if (param_2 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar2 = nvswitch_os_get_platform_time();
    *(int *)(param_2 + 0x10) = (int)(uVar2 / 1000000000);
    if (*(char *)(param_2 + 8) == '\0') {
      *(undefined4 *)(param_2 + 0xc) = 0;
    }
    uVar3 = (**(code **)(param_1 + 0x7a0))(param_1,*(undefined8 *)(lVar1 + 0x10),param_2);
    if ((int)uVar3 == 0) {
      *(undefined1 *)(lVar1 + 0x18) = 1;
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 001bdc20 nvswitch_inforom_ecc_get_errors =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_inforom_ecc_get_errors(long param_1)

{
  undefined8 uVar1;
  
  if ((*(long *)(param_1 + 0xf40) != 0) && (*(long *)(*(long *)(param_1 + 0xf40) + 0xf68) != 0)) {
    uVar1 = (**(code **)(param_1 + 0x7f0))();
    return uVar1;
  }
  return 0xfffffff3;
}


// ===== 001bdc50 _inforom_nvlink_get_correctable_error_counts =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _inforom_nvlink_get_correctable_error_counts
               (long param_1,undefined1 param_2,undefined2 *param_3)

{
  int iVar1;
  uint uVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined1 local_138 [4];
  undefined4 local_134;
  undefined8 auStack_128 [16];
  undefined2 local_a8;
  undefined2 local_60;
  undefined2 local_58;
  undefined2 local_50;
  
  memset(local_138,0,0x110);
  nvswitch_os_memset(param_3,0,0x10);
  local_134 = 0xfff0000;
  local_138[0] = param_2;
  iVar1 = (**(code **)(param_1 + 0x5b0))(param_1);
  if (iVar1 == 0) {
    *param_3 = local_a8;
    param_3[6] = local_60;
    param_3[5] = local_50;
    param_3[7] = local_58;
    puVar4 = param_3;
    do {
      uVar2 = 1 << (('\x11' - (char)param_3) + (char)puVar4 & 0x1fU);
      if ((uVar2 & 0xff00ff00) == 0) {
        uVar6 = 0x10;
        uVar5 = (uint)((uVar2 & 0xf0f0f0f0) != 0) << 2;
      }
      else {
        uVar6 = 0x18;
        uVar5 = 0;
      }
      puVar3 = (undefined2 *)((long)puVar4 + 1);
      *(char *)(puVar4 + 1) =
           (char)auStack_128
                 [(uint)((uVar2 & 0xcccccccc) != 0) * 2 | (uint)((uVar2 & 0xaaaaaaaa) != 0) | uVar6
                  | uVar5];
      puVar4 = puVar3;
    } while (puVar3 != param_3 + 4);
  }
  return;
}


// ===== 001bdd70 _nvswitch_nvlink_1hz_callback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_nvlink_1hz_callback(long param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  uint uVar5;
  byte bVar6;
  long local_60;
  byte local_51;
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  undefined8 local_48;
  undefined8 local_40;
  
  lVar1 = *(long *)(param_1 + 0xf40);
  if (((lVar1 != 0) && (lVar2 = *(long *)(lVar1 + 0xf60), lVar2 != 0)) &&
     (*(char *)(lVar2 + 0x1b) == '\0')) {
    *(undefined1 *)(lVar2 + 0x1b) = 1;
    local_60 = *(long *)(lVar1 + 0xf60);
    local_48 = 0;
    local_40 = 0;
    if (local_60 != 0) {
      uVar4 = nvswitch_get_enabled_link_mask();
      bVar6 = 0;
      if (uVar4 != 0) {
        uVar5 = 0;
        while( true ) {
          for (; (uVar4 & 1) == 0; uVar4 = uVar4 >> 1) {
            uVar5 = uVar5 + 1;
          }
          iVar3 = (**(code **)(param_1 + 0x8c8))(param_1,uVar5,local_50);
          if ((iVar3 == 0) &&
             (iVar3 = (**(code **)(param_1 + 0x8d0))(param_1,uVar5,local_4c), iVar3 == 0)) {
            _inforom_nvlink_get_correctable_error_counts(param_1,uVar5,&local_48);
            iVar3 = (**(code **)(param_1 + 0x7c0))
                              (param_1,*(undefined8 *)(local_60 + 0x10),local_60 + 0x20,uVar5 & 0xff
                               ,local_50[0],local_4c[0],&local_48,&local_51);
            if (iVar3 == 0) {
              bVar6 = local_51 | bVar6;
            }
          }
          uVar4 = uVar4 >> 1;
          if (uVar4 == 0) break;
          uVar5 = uVar5 + 1;
        }
      }
      *(byte *)(local_60 + 0x18) = *(byte *)(local_60 + 0x18) | bVar6;
      local_60 = *(long *)(lVar1 + 0xf60);
    }
    *(undefined1 *)(local_60 + 0x1b) = 0;
    return;
  }
  return;
}


// ===== 001bdef0 nvswitch_inforom_nvlink_flush =====

undefined8 nvswitch_inforom_nvlink_flush(long param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0xf40) == 0) {
    return 0xfffffff3;
  }
  puVar1 = *(undefined8 **)(*(long *)(param_1 + 0xf40) + 0xf60);
  if ((puVar1 != (undefined8 *)0x0) && (*(char *)(puVar1 + 3) != '\0')) {
    uVar2 = nvswitch_inforom_write_object(param_1,&DAT_00c7fb1d,*puVar1,puVar1[2],puVar1[1]);
    if ((int)uVar2 != 0) {
      return uVar2;
    }
    *(undefined1 *)(puVar1 + 3) = 0;
    return uVar2;
  }
  return 0;
}


// ===== 001bdf60 nvswitch_inforom_nvlink_load =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvswitch_inforom_nvlink_load(long param_1)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined1 local_2a;
  byte local_29;
  
  lVar1 = *(long *)(param_1 + 0xf40);
  local_2a = 0;
  local_29 = 0;
  if (lVar1 != 0) {
    iVar3 = nvswitch_inforom_get_object_version_info(param_1,&DAT_00c7fb1d,&local_2a,&local_29);
    if (iVar3 != 0) {
      return 0;
    }
    if ((local_29 & 0xd0) == 0) {
      puVar4 = (undefined8 *)nvswitch_os_malloc_trace(0xd20,0,0);
      if (puVar4 == (undefined8 *)0x0) {
        return -2;
      }
      nvswitch_os_memset(puVar4,0,0xd20);
      *(undefined1 *)((long)puVar4 + 0x1a) = 1;
      *(undefined2 *)(puVar4 + 3) = 0;
      iVar3 = (**(code **)(param_1 + 0x7e8))(param_1,puVar4,local_2a);
      if (iVar3 == 0) {
        iVar3 = nvswitch_inforom_read_object(param_1,&DAT_00c7fb1d,*puVar4,puVar4[1],puVar4[2]);
        if ((iVar3 == 0) && (iVar3 = nvswitch_inforom_add_object(lVar1,puVar4[2]), iVar3 == 0)) {
          *(undefined8 **)(lVar1 + 0xf60) = puVar4;
          if (*(char *)((long)puVar4 + 0x1a) != '\0') {
            return 0;
          }
          *(undefined1 *)((long)puVar4 + 0x1b) = 0;
          cVar2 = nvswitch_is_tnvl_mode_enabled(param_1);
          if (cVar2 != '\0') {
            return 0;
          }
          nvswitch_task_create(param_1,_nvswitch_nvlink_1hz_callback,1000000000,0);
          return 0;
        }
        nvswitch_os_free(puVar4[1]);
        nvswitch_os_free(puVar4[2]);
      }
      nvswitch_os_free(puVar4);
      return iVar3;
    }
  }
  return -0xd;
}


// ===== 001be110 nvswitch_inforom_nvlink_unload =====

void nvswitch_inforom_nvlink_unload(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_1 + 0xf40);
  if (lVar1 != 0) {
    lVar2 = *(long *)(lVar1 + 0xf60);
    if (lVar2 != 0) {
      nvswitch_inforom_nvlink_flush();
      nvswitch_os_free(*(undefined8 *)(lVar2 + 8));
      nvswitch_os_free(*(undefined8 *)(lVar2 + 0x10));
      nvswitch_os_free(lVar2);
      *(undefined8 *)(lVar1 + 0xf60) = 0;
    }
    return;
  }
  return;
}


// ===== 001be180 nvswitch_inforom_nvlink_log_error_event =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_inforom_nvlink_log_error_event(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  byte local_19 [9];
  
  local_19[0] = 0;
  if ((*(long *)(param_1 + 0xf40) != 0) &&
     (lVar1 = *(long *)(*(long *)(param_1 + 0xf40) + 0xf60), lVar1 != 0)) {
    uVar2 = (**(code **)(param_1 + 0x7b8))(param_1,*(undefined8 *)(lVar1 + 0x10),param_2,local_19);
    *(byte *)(lVar1 + 0x18) = *(byte *)(lVar1 + 0x18) | local_19[0];
    return uVar2;
  }
  return 0xfffffff3;
}


// ===== 001be1e0 nvswitch_inforom_nvlink_get_max_correctable_error_rate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_inforom_nvlink_get_max_correctable_error_rate(long param_1)

{
  undefined8 uVar1;
  
  if ((*(long *)(param_1 + 0xf40) != 0) && (*(long *)(*(long *)(param_1 + 0xf40) + 0xf60) != 0)) {
    uVar1 = (**(code **)(param_1 + 0x7c8))();
    return uVar1;
  }
  return 0xfffffff3;
}


// ===== 001be210 nvswitch_inforom_nvlink_get_errors =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_inforom_nvlink_get_errors(long param_1)

{
  undefined8 uVar1;
  
  if ((*(long *)(param_1 + 0xf40) != 0) && (*(long *)(*(long *)(param_1 + 0xf40) + 0xf60) != 0)) {
    uVar1 = (**(code **)(param_1 + 2000))();
    return uVar1;
  }
  return 0xfffffff3;
}


// ===== 001be240 nvswitch_inforom_oms_set_device_disable =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined8 nvswitch_inforom_oms_set_device_disable(long param_1,undefined1 param_2)

{
  long lVar1;
  
  if ((*(long *)(param_1 + 0xf40) != 0) &&
     (lVar1 = *(long *)(*(long *)(param_1 + 0xf40) + 0xf70), lVar1 != 0)) {
    (**(code **)(param_1 + 0x7a8))(lVar1,param_2,*(code **)(param_1 + 0x7a8));
    return 0;
  }
  return 0xfffffff3;
}


// ===== 001be280 nvswitch_inforom_oms_load =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvswitch_inforom_oms_load(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  char local_2a;
  byte local_29;
  
  lVar1 = *(long *)(param_1 + 0xf40);
  local_2a = '\0';
  local_29 = 0;
  if (lVar1 != 0) {
    iVar2 = nvswitch_inforom_get_object_version_info(param_1,&DAT_00c7fb21,&local_2a,&local_29);
    if (iVar2 != 0) {
      return 0;
    }
    if ((local_29 & 0xd0) == 0) {
      puVar3 = (undefined8 *)nvswitch_os_malloc_trace(0x38,0,0);
      if (puVar3 == (undefined8 *)0x0) {
        return -2;
      }
      nvswitch_os_memset(puVar3,0,0x38);
      iVar2 = 0;
      if (local_2a == '\x01') {
        *puVar3 = "3s2bwbd50w";
        lVar4 = nvswitch_os_malloc_trace(0x70,0,0);
        puVar3[1] = lVar4;
        if (lVar4 != 0) {
          lVar4 = nvswitch_os_malloc_trace(0xe8,0,0);
          puVar3[2] = lVar4;
          if (lVar4 != 0) {
            iVar2 = nvswitch_inforom_load_object(param_1,lVar1,&DAT_00c7fb21,*puVar3);
            if (iVar2 == 0) {
              *(undefined8 **)(lVar1 + 0xf70) = puVar3;
              (**(code **)(param_1 + 0x828))(param_1,puVar3);
              return 0;
            }
            nvswitch_os_free(puVar3[2]);
            nvswitch_os_free(puVar3[1]);
            goto LAB_001be30e;
          }
          nvswitch_os_free(puVar3[1]);
        }
        iVar2 = -2;
      }
LAB_001be30e:
      nvswitch_os_free(puVar3);
      return iVar2;
    }
  }
  return -0xd;
}


// ===== 001be420 nvswitch_inforom_oms_unload =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_inforom_oms_unload(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_1 + 0xf40);
  if (lVar1 != 0) {
    lVar2 = *(long *)(lVar1 + 0xf70);
    if (lVar2 == 0) {
      return;
    }
    (**(code **)(param_1 + 0x818))();
    (**(code **)(param_1 + 0x830))();
    nvswitch_os_free(*(undefined8 *)(lVar2 + 8));
    nvswitch_os_free(*(undefined8 *)(lVar2 + 0x10));
    nvswitch_os_free(lVar2);
    *(undefined8 *)(lVar1 + 0xf70) = 0;
  }
  return;
}


// ===== 001be4b0 nvswitch_inforom_read_only_objects_load =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_inforom_read_only_objects_load(long param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined8 uVar3;
  
  puVar1 = *(undefined1 **)(param_1 + 0xf40);
  if (puVar1 == (undefined1 *)0x0) {
    uVar3 = 0xfffffff3;
  }
  else {
    iVar2 = (**(code **)(param_1 + 0x840))();
    if (iVar2 == 0) {
      *puVar1 = 1;
    }
    iVar2 = nvswitch_inforom_load_object
                      (param_1,puVar1,&DAT_00c7fb3b,"3s2bwb504b",puVar1 + 0x431,puVar1 + 0x634);
    if (iVar2 == 0) {
      puVar1[0x430] = 1;
    }
    uVar3 = nvswitch_inforom_load_object
                      (param_1,puVar1,&DAT_00c7fb4e,"3s2bwb16b4w32b",puVar1 + 0xe31,puVar1 + 0xe74);
    if ((int)uVar3 != 0) {
      return 0;
    }
    puVar1[0xe30] = 1;
  }
  return uVar3;
}


// ===== 001be590 inforom_nvl_v3_map_error =====

undefined8
inforom_nvl_v3_map_error
          (uint param_1,undefined1 *param_2,undefined2 *param_3,undefined1 *param_4,
          undefined4 *param_5)

{
  undefined4 uVar1;
  long lVar2;
  
  if (param_1 < 0x50) {
    lVar2 = (ulong)param_1 * 0xc;
    *param_2 = lut_7[lVar2];
    *param_3 = *(undefined2 *)(lut_7 + lVar2 + 2);
    uVar1 = *(undefined4 *)(lut_7 + lVar2 + 8);
    *param_4 = lut_7[lVar2 + 4];
    *param_5 = uVar1;
    return 0;
  }
  return 0xffffffff;
}


// ===== 001be5e0 inforom_nvl_v3_encode_nvlipt_error_subtype =====

undefined8 inforom_nvl_v3_encode_nvlipt_error_subtype(byte param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  
  if ((param_1 < 7) && (bVar1 = *param_2, bVar1 < 0xc)) {
    bVar2 = param_1 << 5;
    if (linkIdxValidLut_6[bVar1] == '\0') {
      bVar2 = 0xe0;
    }
    *param_2 = bVar2 | bVar1;
    return 0;
  }
  return 0xffffffff;
}


// ===== 001be620 inforom_nvl_v3_should_replace_error_rate_entry =====

uint inforom_nvl_v3_should_replace_error_rate_entry(long param_1,uint param_2,long param_3)

{
  uint *puVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  
  lVar2 = 0;
  uVar3 = 0;
  uVar4 = 0;
  do {
    uVar4 = uVar4 + *(uint *)(param_3 + lVar2);
    puVar1 = (uint *)(param_1 + 8 + lVar2);
    lVar2 = lVar2 + 4;
    uVar3 = uVar3 + *puVar1;
  } while (lVar2 != 0x10);
  return (uint)(*(uint *)(param_1 + 4) < param_2) | (uint)CONCAT71((int7)(uVar4 >> 8),uVar3 < uVar4)
  ;
}


// ===== 001be660 inforom_nvl_v3_seconds_to_day_and_month =====

void inforom_nvl_v3_seconds_to_day_and_month(uint param_1,uint *param_2,uint *param_3)

{
  *param_2 = param_1 / 0x15180;
  *param_3 = param_1 / 0x278d00;
  return;
}


// ===== 001be690 inforom_nvl_v3_update_error_rate_entry =====

void inforom_nvl_v3_update_error_rate_entry
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  nvswitch_os_memcpy(param_1 + 2,param_4,0x10);
  return;
}


// ===== 001be6b0 inforom_nvl_v3_map_error_to_userspace_error =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 inforom_nvl_v3_map_error_to_userspace_error(long param_1,int *param_2,char *param_3)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  char cVar4;
  undefined8 uVar5;
  uint uVar6;
  byte bVar7;
  ulong uVar8;
  uint uVar9;
  
  cVar4 = (**(code **)(param_1 + 0x518))();
  if ((param_2 == (int *)0x0) || (param_3 == (char *)0x0)) {
    uVar5 = 0xffffffff;
  }
  else {
    uVar1 = param_2[2];
    iVar2 = param_2[1];
    *(int *)(param_3 + 8) = param_2[3];
    if (*param_2 == 1) {
      uVar8 = (ulong)(uint)param_2[5];
    }
    else {
      if (*param_2 != 2) {
        return 0xfffffff3;
      }
      uVar6 = param_2[5];
      *(ulong *)(param_3 + 0x10) = (ulong)uVar6;
      uVar8 = CONCAT44(uVar6,param_2[4]);
    }
    *(ulong *)(param_3 + 0x10) = uVar8;
    uVar6 = uVar1 & 0x1f;
    uVar8 = (ulong)uVar6;
    bVar3 = (byte)iVar2 & 0xf;
    uVar9 = param_2[1] & 0xf0;
    if (uVar9 < 0xb1) {
      bVar7 = (byte)param_2[1];
      if ((uVar9 < 0x90) && (uVar9 < 0x51)) {
        *param_3 = (bVar7 >> 4) + cVar4 * bVar3;
        uVar9 = param_2[1] & 0x300;
        if (uVar9 == 0x100) {
          if (2 < uVar6) {
            return 0xfffffff3;
          }
          *(undefined4 *)(param_3 + 4) = *(undefined4 *)(DL_NA_ERRORS_5 + uVar8 * 4);
        }
        else if (uVar9 == 0x200) {
          if ((uVar1 & 0x18) != 0) {
            return 0xfffffff3;
          }
          *(undefined4 *)(param_3 + 4) = *(undefined4 *)(DL_RX_ERRORS_4 + uVar8 * 4);
        }
        else {
          if (uVar9 != 0x300) {
            return 0xfffffff3;
          }
          if ((uVar1 & 0x1c) != 0) {
            return 0xfffffff3;
          }
          *(undefined4 *)(param_3 + 4) = *(undefined4 *)(DL_TX_ERRORS_3 + uVar8 * 4);
        }
      }
      else {
        *param_3 = ((bVar7 >> 4) - 6) + cVar4 * bVar3;
        if ((param_2[1] & 0x300U) == 0x200) {
          if (0x1c < uVar6) {
            return 0xfffffff3;
          }
          *(undefined4 *)(param_3 + 4) = *(undefined4 *)(TLC_RX_ERRORS_2 + uVar8 * 4);
        }
        else {
          if ((0x13 < uVar6) || ((param_2[1] & 0x300U) != 0x300)) {
            return 0xfffffff3;
          }
          *(undefined4 *)(param_3 + 4) = *(undefined4 *)(TLC_TX_ERRORS_1 + uVar8 * 4);
        }
      }
    }
    else {
      if (uVar9 != 0xd0) {
        return 0xfffffff3;
      }
      if (0xb < uVar6) {
        return 0xfffffff3;
      }
      bVar7 = 0;
      if ((~param_2[2] & 0xe0U) != 0) {
        bVar7 = (byte)((uint)param_2[2] >> 5) & 7;
      }
      *param_3 = cVar4 * bVar3 + bVar7;
      *(undefined4 *)(param_3 + 4) = *(undefined4 *)(LIPT_ERRORS_0 + uVar8 * 4);
    }
    uVar5 = 0;
  }
  return uVar5;
}


// ===== 001be8c0 inforom_nvl_v3_update_correctable_error_rates =====

void inforom_nvl_v3_update_correctable_error_rates(long param_1,byte param_2,ushort *param_3)

{
  uint *puVar1;
  byte bVar2;
  ushort uVar3;
  long lVar4;
  long lVar5;
  byte bVar6;
  ushort uVar7;
  
  lVar4 = (ulong)param_2 * 0x20 + param_1;
  if ((uint)*param_3 < *(uint *)(lVar4 + 0x2d0)) {
    *(undefined4 *)(lVar4 + 0x2d0) = 0;
  }
  lVar4 = 0;
  lVar5 = (ulong)param_2 * 0x20 + param_1;
  do {
    if ((uint)*(byte *)((long)param_3 + lVar4 + 2) < *(uint *)(lVar5 + 0x2d4 + lVar4 * 4)) {
      *(undefined4 *)(lVar5 + 0x2d4 + lVar4 * 4) = 0;
    }
    lVar4 = lVar4 + 1;
  } while (lVar4 != 4);
  uVar3 = *param_3;
  lVar4 = param_1 + (ulong)param_2 * 0x20;
  puVar1 = (uint *)(param_1 + (ulong)param_2 * 0x14);
  uVar7 = uVar3 - *(short *)(lVar4 + 0x2d0);
  *param_3 = uVar7;
  *puVar1 = (*puVar1 - *puVar1 / 0x3c) + (uint)uVar7;
  *(uint *)(lVar4 + 0x2d0) = (uint)uVar3;
  lVar4 = 1;
  do {
    bVar2 = *(byte *)((long)param_3 + lVar4 + 1);
    bVar6 = bVar2 - *(char *)(lVar5 + 0x2d0 + lVar4 * 4);
    *(byte *)((long)param_3 + lVar4 + 1) = bVar6;
    puVar1[lVar4] = (puVar1[lVar4] - puVar1[lVar4] / 0x3c) + (uint)bVar6;
    *(uint *)(lVar5 + 0x2d0 + lVar4 * 4) = (uint)bVar2;
    lVar4 = lVar4 + 1;
  } while (lVar4 != 5);
  uVar7 = param_3[5];
  uVar3 = uVar7 - (short)*(uint *)(lVar5 + 0x2e4);
  if ((uint)uVar7 < *(uint *)(lVar5 + 0x2e4)) {
    *(undefined4 *)(lVar5 + 0x2e4) = 0;
    uVar3 = param_3[5];
    uVar7 = uVar3;
  }
  param_3[5] = uVar3;
  *(uint *)(lVar5 + 0x2e4) = (uint)uVar7;
  uVar7 = param_3[6];
  uVar3 = uVar7 - (short)*(uint *)(lVar5 + 0x2e8);
  if ((uint)uVar7 < *(uint *)(lVar5 + 0x2e8)) {
    *(undefined4 *)(lVar5 + 0x2e8) = 0;
    uVar3 = param_3[6];
    uVar7 = uVar3;
  }
  param_3[6] = uVar3;
  *(uint *)(lVar5 + 0x2e8) = (uint)uVar7;
  uVar7 = param_3[7];
  uVar3 = uVar7 - (short)*(uint *)(lVar5 + 0x2ec);
  if ((uint)uVar7 < *(uint *)(lVar5 + 0x2ec)) {
    *(undefined4 *)(lVar5 + 0x2ec) = 0;
    uVar3 = param_3[7];
    uVar7 = uVar3;
  }
  param_3[7] = uVar3;
  *(uint *)(lVar5 + 0x2ec) = (uint)uVar7;
  return;
}


// ===== 001bea40 inforom_nvl_v4_update_correctable_error_rates =====

void inforom_nvl_v4_update_correctable_error_rates(long param_1,byte param_2,ushort *param_3)

{
  uint *puVar1;
  byte bVar2;
  uint uVar3;
  ushort uVar4;
  long lVar5;
  long lVar6;
  ushort uVar7;
  ulong uVar8;
  byte bVar9;
  
  uVar8 = (ulong)param_2;
  lVar6 = uVar8 * 0x20 + param_1;
  if ((uint)*param_3 < *(uint *)(lVar6 + 0x500)) {
    *(undefined4 *)(lVar6 + 0x500) = 0;
  }
  lVar5 = 0;
  do {
    if ((uint)*(byte *)((long)param_3 + lVar5 + 2) < *(uint *)(lVar6 + 0x504 + lVar5 * 4)) {
      *(undefined4 *)(lVar6 + 0x504 + lVar5 * 4) = 0;
    }
    lVar5 = lVar5 + 1;
  } while (lVar5 != 4);
  uVar4 = *param_3;
  puVar1 = (uint *)(param_1 + uVar8 * 0x14);
  uVar7 = uVar4 - *(short *)(lVar6 + 0x500);
  *param_3 = uVar7;
  *puVar1 = (*puVar1 - *puVar1 / 0x3c) + (uint)uVar7;
  lVar5 = 1;
  *(uint *)(lVar6 + 0x500) = (uint)uVar4;
  do {
    bVar2 = *(byte *)((long)param_3 + lVar5 + 1);
    bVar9 = bVar2 - *(char *)(lVar6 + 0x500 + lVar5 * 4);
    *(byte *)((long)param_3 + lVar5 + 1) = bVar9;
    puVar1[lVar5] = (puVar1[lVar5] - puVar1[lVar5] / 0x3c) + (uint)bVar9;
    *(uint *)(lVar6 + 0x500 + lVar5 * 4) = (uint)bVar2;
    lVar5 = lVar5 + 1;
  } while (lVar5 != 5);
  uVar7 = param_3[5];
  lVar6 = uVar8 * 0x20 + param_1;
  uVar3 = *(uint *)(lVar6 + 0x514);
  uVar4 = uVar7 - (short)uVar3;
  if (uVar7 < uVar3) {
    *(undefined4 *)(lVar6 + 0x514) = 0;
    uVar4 = param_3[5];
    uVar7 = uVar4;
  }
  param_3[5] = uVar4;
  lVar6 = uVar8 * 0x20 + param_1;
  *(uint *)(lVar6 + 0x514) = (uint)uVar7;
  uVar4 = param_3[6];
  if ((uint)uVar4 < *(uint *)(lVar6 + 0x518)) {
    *(undefined4 *)(lVar6 + 0x518) = 0;
    uVar7 = param_3[6];
    uVar4 = uVar7;
  }
  else {
    uVar7 = uVar4 - (short)*(uint *)(lVar6 + 0x518);
  }
  param_3[6] = uVar7;
  lVar6 = uVar8 * 0x20 + param_1;
  *(uint *)(lVar6 + 0x518) = (uint)uVar4;
  uVar4 = param_3[7];
  if ((uint)uVar4 < *(uint *)(lVar6 + 0x51c)) {
    *(undefined4 *)(lVar6 + 0x51c) = 0;
    uVar7 = param_3[7];
    uVar4 = uVar7;
  }
  else {
    uVar7 = uVar4 - (short)*(uint *)(lVar6 + 0x51c);
  }
  param_3[7] = uVar7;
  *(uint *)(param_1 + 0x51c + uVar8 * 0x20) = (uint)uVar4;
  return;
}


// ===== 001bec00 _nvswitch_inforom_calc_packed_object_size =====

undefined8 _nvswitch_inforom_calc_packed_object_size(char *param_1,undefined2 *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  int iVar5;
  char *pcVar6;
  
  cVar1 = *param_1;
  if (cVar1 == '\0') {
    uVar4 = 0;
  }
  else {
    iVar5 = 0;
    do {
      uVar2 = (uint)(ushort)(short)cVar1;
      param_1 = param_1 + 1;
      uVar3 = 0;
      if ((byte)(cVar1 - 0x30U) < 10) {
        do {
          pcVar6 = param_1 + 1;
          uVar3 = (uVar2 - 0x30) + uVar3 * 10;
          cVar1 = *param_1;
          uVar2 = (uint)(ushort)(short)cVar1;
          param_1 = pcVar6;
        } while ((byte)(cVar1 - 0x30U) < 10);
        if ((short)uVar3 == 0) {
          uVar3 = 1;
        }
        if (cVar1 == 's') {
LAB_001bece0:
          iVar5 = iVar5 + uVar3;
        }
        else if (cVar1 < 't') {
          if (cVar1 != 'n') goto LAB_001bec71;
          if ((uVar3 & 1) != 0) {
            return 0xfffffff8;
          }
          iVar5 = iVar5 + (uVar3 >> 1 & 0x7fff);
        }
        else {
LAB_001becc0:
          cVar1 = (char)uVar2;
          if (cVar1 == 'w') {
            iVar5 = iVar5 + uVar3 * 2;
          }
          else {
            if (cVar1 == 'x') goto LAB_001bece0;
            if (cVar1 != 't') {
              return 0xffffffff;
            }
            iVar5 = iVar5 + uVar3 * 3;
          }
        }
      }
      else if (cVar1 == 's') {
        iVar5 = iVar5 + 1;
      }
      else {
        if ('s' < cVar1) {
          uVar3 = 1;
          goto LAB_001becc0;
        }
        if (cVar1 == 'n') {
          return 0xfffffff8;
        }
        uVar3 = 1;
LAB_001bec71:
        cVar1 = (char)uVar2;
        if (cVar1 < 'o') {
          if (cVar1 == 'b') goto LAB_001bece0;
          if (cVar1 != 'd') {
            return 0xffffffff;
          }
          iVar5 = iVar5 + uVar3 * 4;
        }
        else {
          if (cVar1 != 'q') {
            return 0xffffffff;
          }
          iVar5 = iVar5 + uVar3 * 8;
        }
      }
      uVar4 = (undefined2)iVar5;
      cVar1 = *param_1;
    } while (cVar1 != '\0');
  }
  *param_2 = uVar4;
  return 0;
}


// ===== 001bed60 _nvswitch_inforom_read_file =====

int _nvswitch_inforom_read_file(long param_1,undefined8 param_2,uint param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  undefined4 local_94;
  int *local_90;
  undefined8 local_88;
  undefined1 local_80 [8];
  undefined2 local_78 [2];
  undefined1 local_74;
  undefined8 local_70;
  long local_68;
  undefined1 local_60 [48];
  
  iVar1 = param_3 + 4;
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0xd20) + 8);
  iVar3 = nvswitch_os_alloc_contig_memory
                    (*(undefined8 *)(param_1 + 0x18),&local_90,iVar1,
                     *(int *)(param_1 + 0xf38) == 0x20);
  if (iVar3 == 0) {
    iVar3 = nvswitch_os_map_dma_region(*(undefined8 *)(param_1 + 0x18),local_90,&local_88,iVar1,0);
    if (iVar3 == 0) {
      nvswitch_os_memset(local_78,0,0x3c);
      local_78[0] = 0x3c0c;
      local_74 = 0;
      local_70 = local_88;
      nvswitch_os_memcpy(local_60,param_2,3);
      local_68 = (ulong)param_3 << 0x20;
      nvswitch_os_memset(local_90,0,iVar1);
      local_94 = 0;
      nvswitch_timeout_create(4000000000,local_80);
      iVar3 = flcnQueueCmdPostBlocking(param_1,uVar2,local_78,0,0,0,&local_94,local_80);
      if (((iVar3 == 0) &&
          (iVar3 = nvswitch_os_sync_dma_region_for_cpu
                             (*(undefined8 *)(param_1 + 0x18),local_88,iVar1,0), iVar3 == 0)) &&
         (nvswitch_os_memcpy(param_4,local_90 + 1,param_3), *local_90 != 0)) {
        iVar3 = -0xb;
      }
      nvswitch_os_unmap_dma_region(*(undefined8 *)(param_1 + 0x18),local_90,local_88,iVar1,1);
    }
    nvswitch_os_free_contig_memory(*(undefined8 *)(param_1 + 0x18),local_90,iVar1);
  }
  return iVar3;
}


// ===== 001bef30 __pfx__nvswitch_inforom_unpack_object =====

undefined8 __pfx__nvswitch_inforom_unpack_object(char *param_1,uint3 *param_2,ulong *param_3)

{
  byte *pbVar1;
  uint3 uVar2;
  char cVar3;
  uint uVar4;
  long lVar5;
  byte bVar6;
  int iVar7;
  ushort uVar8;
  uint3 *puVar9;
  ushort uVar10;
  ulong uVar11;
  char *pcVar12;
  ulong *puVar13;
  
  cVar3 = *param_1;
  if (cVar3 == '\0') {
    return 0;
  }
  do {
    param_1 = param_1 + 1;
    uVar8 = 0;
    pcVar12 = param_1;
    uVar10 = 1;
    if ((byte)(cVar3 - 0x30U) < 10) {
      do {
        param_1 = pcVar12 + 1;
        uVar8 = cVar3 + -0x30 + uVar8 * 10;
        cVar3 = *pcVar12;
        pcVar12 = param_1;
      } while ((byte)(cVar3 - 0x30U) < 10);
      uVar10 = 1;
      if (uVar8 != 0) {
        uVar10 = uVar8;
      }
    }
    puVar9 = param_2;
    puVar13 = param_3;
    if (cVar3 == 's') {
      do {
        param_2 = (uint3 *)((long)puVar9 + 1);
        bVar6 = (byte)*puVar9;
        uVar4 = (uint)bVar6;
        if ((char)bVar6 < '\0') {
          uVar4 = bVar6 | 0xffffff00;
        }
        param_3 = (ulong *)((long)puVar13 + 4);
        *(uint *)puVar13 = uVar4;
        uVar10 = uVar10 - 1;
        puVar9 = param_2;
        puVar13 = param_3;
      } while (uVar10 != 0);
    }
    else if (cVar3 < 't') {
      if (cVar3 == 'n') {
LAB_001bf0a5:
        do {
          if ((uVar10 & 1) != 0) {
            return 0xfffffff8;
          }
          uVar2 = *param_2;
          param_2 = (uint3 *)((long)param_2 + 1);
          param_3 = puVar13 + 1;
          *(uint *)puVar13 = (byte)uVar2 & 0xf;
          *(uint *)((long)puVar13 + 4) = (uint)(byte)((byte)uVar2 >> 4);
          uVar10 = uVar10 - 2;
          puVar13 = param_3;
        } while (uVar10 != 0);
      }
      else {
        if (cVar3 < 'o') {
          if (cVar3 != 'b') {
            if (cVar3 != 'd') {
              return 0xffffffff;
            }
            do {
              lVar5 = 0;
              uVar11 = 0;
              do {
                pbVar1 = (byte *)((long)param_2 + lVar5);
                cVar3 = (char)lVar5;
                lVar5 = lVar5 + 1;
                uVar11 = uVar11 | (ulong)*pbVar1 << (cVar3 * '\b' & 0x3fU);
              } while (lVar5 != 4);
              *(uint *)param_3 = (uint)uVar11;
              param_2 = param_2 + 1;
              param_3 = (ulong *)((long)param_3 + 4);
              uVar10 = uVar10 - 1;
            } while (uVar10 != 0);
            goto LAB_001bf1cc;
          }
          do {
            uVar2 = *param_2;
            param_2 = (uint3 *)((long)param_2 + 1);
            *(uint *)param_3 = (uint)(byte)uVar2;
            while( true ) {
              uVar10 = uVar10 - 1;
              param_3 = (ulong *)((long)param_3 + 4);
              if (uVar10 == 0) goto LAB_001bf1cc;
              if (cVar3 < 't') break;
LAB_001bf168:
              uVar2 = *param_2;
              param_2 = (uint3 *)((long)param_2 + 2);
              *(uint *)param_3 = (uint)(ushort)uVar2;
            }
            puVar13 = param_3;
            if (cVar3 == 'n') goto LAB_001bf0a5;
          } while (cVar3 < 'o');
        }
        if (cVar3 != 'q') {
          return 0xffffffff;
        }
        do {
          iVar7 = 0;
          uVar11 = 0;
          puVar9 = param_2;
          do {
            uVar2 = *puVar9;
            puVar9 = (uint3 *)((long)puVar9 + 1);
            bVar6 = (byte)iVar7;
            iVar7 = iVar7 + 8;
            uVar11 = uVar11 | (ulong)(byte)uVar2 << (bVar6 & 0x3f);
          } while (iVar7 != 0x40);
          *param_3 = uVar11;
          param_2 = param_2 + 2;
          param_3 = param_3 + 1;
          uVar10 = uVar10 - 1;
        } while (uVar10 != 0);
      }
    }
    else {
      if (cVar3 == 'w') goto LAB_001bf168;
      if (cVar3 == 'x') {
        nvswitch_os_memcpy(param_3,param_2,(ulong)uVar10);
        param_3 = (ulong *)((long)param_3 + (ulong)(uVar10 + 3 & 0x1fffc));
        param_2 = (uint3 *)((long)param_2 + (ulong)uVar10);
      }
      else {
        if (cVar3 != 't') {
          return 0xffffffff;
        }
        do {
          uVar2 = *param_2;
          param_3 = (ulong *)((long)puVar13 + 4);
          param_2 = (uint3 *)((long)param_2 + 3);
          *(uint *)puVar13 = (uint)uVar2;
          uVar10 = uVar10 - 1;
          puVar13 = param_3;
        } while (uVar10 != 0);
      }
    }
LAB_001bf1cc:
    cVar3 = *param_1;
    if (cVar3 == '\0') {
      return 0;
    }
  } while( true );
}


// ===== 001bef40 _nvswitch_inforom_unpack_object =====

undefined8 _nvswitch_inforom_unpack_object(char *param_1,uint3 *param_2,ulong *param_3)

{
  byte *pbVar1;
  uint3 uVar2;
  char cVar3;
  uint uVar4;
  long lVar5;
  byte bVar6;
  int iVar7;
  ushort uVar8;
  uint3 *puVar9;
  ushort uVar10;
  ulong uVar11;
  char *pcVar12;
  ulong *puVar13;
  
  cVar3 = *param_1;
  if (cVar3 == '\0') {
    return 0;
  }
  do {
    param_1 = param_1 + 1;
    uVar8 = 0;
    pcVar12 = param_1;
    uVar10 = 1;
    if ((byte)(cVar3 - 0x30U) < 10) {
      do {
        param_1 = pcVar12 + 1;
        uVar8 = cVar3 + -0x30 + uVar8 * 10;
        cVar3 = *pcVar12;
        pcVar12 = param_1;
      } while ((byte)(cVar3 - 0x30U) < 10);
      uVar10 = 1;
      if (uVar8 != 0) {
        uVar10 = uVar8;
      }
    }
    puVar9 = param_2;
    puVar13 = param_3;
    if (cVar3 == 's') {
      do {
        param_2 = (uint3 *)((long)puVar9 + 1);
        bVar6 = (byte)*puVar9;
        uVar4 = (uint)bVar6;
        if ((char)bVar6 < '\0') {
          uVar4 = bVar6 | 0xffffff00;
        }
        param_3 = (ulong *)((long)puVar13 + 4);
        *(uint *)puVar13 = uVar4;
        uVar10 = uVar10 - 1;
        puVar9 = param_2;
        puVar13 = param_3;
      } while (uVar10 != 0);
    }
    else if (cVar3 < 't') {
      if (cVar3 == 'n') {
LAB_001bf0a5:
        do {
          if ((uVar10 & 1) != 0) {
            return 0xfffffff8;
          }
          uVar2 = *param_2;
          param_2 = (uint3 *)((long)param_2 + 1);
          param_3 = puVar13 + 1;
          *(uint *)puVar13 = (byte)uVar2 & 0xf;
          *(uint *)((long)puVar13 + 4) = (uint)(byte)((byte)uVar2 >> 4);
          uVar10 = uVar10 - 2;
          puVar13 = param_3;
        } while (uVar10 != 0);
      }
      else {
        if (cVar3 < 'o') {
          if (cVar3 != 'b') {
            if (cVar3 != 'd') {
              return 0xffffffff;
            }
            do {
              lVar5 = 0;
              uVar11 = 0;
              do {
                pbVar1 = (byte *)((long)param_2 + lVar5);
                cVar3 = (char)lVar5;
                lVar5 = lVar5 + 1;
                uVar11 = uVar11 | (ulong)*pbVar1 << (cVar3 * '\b' & 0x3fU);
              } while (lVar5 != 4);
              *(uint *)param_3 = (uint)uVar11;
              param_2 = param_2 + 1;
              param_3 = (ulong *)((long)param_3 + 4);
              uVar10 = uVar10 - 1;
            } while (uVar10 != 0);
            goto LAB_001bf1cc;
          }
          do {
            uVar2 = *param_2;
            param_2 = (uint3 *)((long)param_2 + 1);
            *(uint *)param_3 = (uint)(byte)uVar2;
            while( true ) {
              uVar10 = uVar10 - 1;
              param_3 = (ulong *)((long)param_3 + 4);
              if (uVar10 == 0) goto LAB_001bf1cc;
              if (cVar3 < 't') break;
LAB_001bf168:
              uVar2 = *param_2;
              param_2 = (uint3 *)((long)param_2 + 2);
              *(uint *)param_3 = (uint)(ushort)uVar2;
            }
            puVar13 = param_3;
            if (cVar3 == 'n') goto LAB_001bf0a5;
          } while (cVar3 < 'o');
        }
        if (cVar3 != 'q') {
          return 0xffffffff;
        }
        do {
          iVar7 = 0;
          uVar11 = 0;
          puVar9 = param_2;
          do {
            uVar2 = *puVar9;
            puVar9 = (uint3 *)((long)puVar9 + 1);
            bVar6 = (byte)iVar7;
            iVar7 = iVar7 + 8;
            uVar11 = uVar11 | (ulong)(byte)uVar2 << (bVar6 & 0x3f);
          } while (iVar7 != 0x40);
          *param_3 = uVar11;
          param_2 = param_2 + 2;
          param_3 = param_3 + 1;
          uVar10 = uVar10 - 1;
        } while (uVar10 != 0);
      }
    }
    else {
      if (cVar3 == 'w') goto LAB_001bf168;
      if (cVar3 == 'x') {
        nvswitch_os_memcpy(param_3,param_2,(ulong)uVar10);
        param_3 = (ulong *)((long)param_3 + (ulong)(uVar10 + 3 & 0x1fffc));
        param_2 = (uint3 *)((long)param_2 + (ulong)uVar10);
      }
      else {
        if (cVar3 != 't') {
          return 0xffffffff;
        }
        do {
          uVar2 = *param_2;
          param_3 = (ulong *)((long)puVar13 + 4);
          param_2 = (uint3 *)((long)param_2 + 3);
          *(uint *)puVar13 = (uint)uVar2;
          uVar10 = uVar10 - 1;
          puVar13 = param_3;
        } while (uVar10 != 0);
      }
    }
LAB_001bf1cc:
    cVar3 = *param_1;
    if (cVar3 == '\0') {
      return 0;
    }
  } while( true );
}


// ===== 001bf1f0 nvswitch_inforom_string_copy =====

void nvswitch_inforom_string_copy(long param_1,long param_2,uint param_3)

{
  ulong uVar1;
  
  if (param_3 != 0) {
    uVar1 = 0;
    do {
      *(char *)(param_2 + uVar1) = (char)*(undefined4 *)(param_1 + uVar1 * 4);
      uVar1 = uVar1 + 1;
    } while (param_3 != uVar1);
  }
  return;
}


// ===== 001bf210 nvswitch_inforom_read_object =====

undefined8
nvswitch_inforom_read_object
          (long param_1,char *param_2,undefined8 param_3,char *param_4,long param_5)

{
  undefined8 uVar1;
  short local_2a;
  
  if (*(long *)(param_1 + 0xf40) == 0) {
    return 0xfffffff3;
  }
  uVar1 = _nvswitch_inforom_calc_packed_object_size(param_3,&local_2a);
  if ((int)uVar1 == 0) {
    uVar1 = _nvswitch_inforom_read_file(param_1,param_2,local_2a,param_4);
    if ((int)uVar1 == 0) {
      if ((((local_2a == *(short *)(param_4 + 5)) && (*param_4 == *param_2)) &&
          (param_4[1] == param_2[1])) && (param_4[2] == param_2[2])) {
        if (param_5 != 0) {
          uVar1 = _nvswitch_inforom_unpack_object(param_3,param_4,param_5);
          return uVar1;
        }
      }
      else {
        uVar1 = 0xfffffff8;
      }
    }
  }
  return uVar1;
}


// ===== 001bf300 nvswitch_inforom_write_object =====

int nvswitch_inforom_write_object(long param_1,undefined8 param_2,char *param_3,ulong *param_4)

{
  uint *puVar1;
  undefined8 uVar2;
  ulong uVar3;
  ulong uVar4;
  char cVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte bVar9;
  ushort uVar10;
  int iVar11;
  byte *pbVar12;
  char *pcVar13;
  ushort local_96;
  undefined4 local_94;
  int *local_90;
  undefined8 local_88;
  undefined1 local_80 [12];
  undefined2 local_74 [2];
  undefined1 local_70;
  undefined8 local_6c;
  undefined4 local_64;
  uint local_60;
  undefined1 local_5c [44];
  
  if (*(long *)(param_1 + 0xf40) == 0) {
    iVar6 = -0xd;
  }
  else {
    iVar6 = _nvswitch_inforom_calc_packed_object_size(param_3,&local_96);
    if (iVar6 != 0) {
      return iVar6;
    }
    if (local_96 < 0x8001) {
      pbVar7 = (byte *)nvswitch_os_malloc_trace(local_96,0,0);
      if (pbVar7 == (byte *)0x0) {
        iVar6 = -2;
      }
      else {
        cVar5 = *param_3;
        pbVar12 = pbVar7;
        while (cVar5 != '\0') {
          param_3 = param_3 + 1;
          uVar10 = 0;
          if ((byte)(cVar5 - 0x30U) < 10) {
            do {
              pcVar13 = param_3 + 1;
              uVar10 = cVar5 + -0x30 + uVar10 * 10;
              cVar5 = *param_3;
              param_3 = pcVar13;
            } while ((byte)(cVar5 - 0x30U) < 10);
            if (uVar10 == 0) {
              uVar10 = 1;
            }
          }
          else {
            uVar10 = 1;
          }
          pbVar8 = pbVar12;
          if (cVar5 == 's') {
            do {
              uVar3 = *param_4;
              pbVar12 = pbVar8 + 1;
              param_4 = (ulong *)((long)param_4 + 4);
              *pbVar8 = (byte)(int)uVar3;
              uVar10 = uVar10 - 1;
              pbVar8 = pbVar12;
            } while (uVar10 != 0);
          }
          else if (cVar5 < 't') {
            if (cVar5 == 'n') {
              do {
                if ((uVar10 & 1) != 0) {
                  iVar6 = -8;
                  goto LAB_001bf5c6;
                }
                puVar1 = (uint *)((long)param_4 + 4);
                uVar3 = *param_4;
                pbVar12 = pbVar8 + 1;
                param_4 = param_4 + 1;
                *pbVar8 = (byte)((*puVar1 & 0xf) << 4) | (byte)(int)uVar3 & 0xf;
                uVar10 = uVar10 - 2;
                pbVar8 = pbVar12;
              } while (uVar10 != 0);
            }
            else if (cVar5 < 'o') {
              if (cVar5 == 'b') {
                do {
                  uVar3 = *param_4;
                  pbVar12 = pbVar8 + 1;
                  param_4 = (ulong *)((long)param_4 + 4);
                  *pbVar8 = (byte)(int)uVar3;
                  uVar10 = uVar10 - 1;
                  pbVar8 = pbVar12;
                } while (uVar10 != 0);
              }
              else {
                if (cVar5 != 'd') goto LAB_001bf5c0;
                do {
                  uVar3 = *param_4;
                  pbVar12 = pbVar8 + 4;
                  param_4 = (ulong *)((long)param_4 + 4);
                  *(int *)pbVar8 = (int)uVar3;
                  uVar10 = uVar10 - 1;
                  pbVar8 = pbVar12;
                } while (uVar10 != 0);
              }
            }
            else {
              if (cVar5 != 'q') {
LAB_001bf5c0:
                iVar6 = -1;
                goto LAB_001bf5c6;
              }
              do {
                uVar3 = *param_4;
                iVar6 = 0;
                pbVar8 = pbVar12;
                do {
                  bVar9 = (byte)iVar6;
                  iVar6 = iVar6 + 8;
                  *pbVar8 = (byte)(uVar3 >> (bVar9 & 0x3f));
                  pbVar8 = pbVar8 + 1;
                } while (iVar6 != 0x40);
                pbVar12 = pbVar12 + 8;
                param_4 = param_4 + 1;
                uVar10 = uVar10 - 1;
              } while (uVar10 != 0);
            }
          }
          else if (cVar5 == 'w') {
            do {
              uVar3 = *param_4;
              pbVar12 = pbVar8 + 2;
              param_4 = (ulong *)((long)param_4 + 4);
              *(short *)pbVar8 = (short)uVar3;
              uVar10 = uVar10 - 1;
              pbVar8 = pbVar12;
            } while (uVar10 != 0);
          }
          else if (cVar5 == 'x') {
            nvswitch_os_memcpy(pbVar12,param_4);
            pbVar12 = pbVar12 + uVar10;
            param_4 = (ulong *)((long)param_4 + (ulong)(uVar10 + 3 & 0x1fffc));
          }
          else {
            if (cVar5 != 't') goto LAB_001bf5c0;
            do {
              uVar3 = *param_4;
              uVar4 = *param_4;
              pbVar12 = pbVar8 + 3;
              param_4 = (ulong *)((long)param_4 + 4);
              *(short *)pbVar8 = (short)uVar4;
              pbVar8[2] = (byte)((uint)(int)uVar3 >> 0x10);
              uVar10 = uVar10 - 1;
              pbVar8 = pbVar12;
            } while (uVar10 != 0);
          }
          cVar5 = *param_3;
        }
        iVar11 = local_96 + 4;
        uVar2 = *(undefined8 *)(*(long *)(param_1 + 0xd20) + 8);
        iVar6 = nvswitch_os_alloc_contig_memory
                          (*(undefined8 *)(param_1 + 0x18),&local_90,iVar11,
                           *(int *)(param_1 + 0xf38) == 0x20);
        if (iVar6 == 0) {
          iVar6 = nvswitch_os_map_dma_region
                            (*(undefined8 *)(param_1 + 0x18),local_90,&local_88,iVar11,2);
          if (iVar6 == 0) {
            nvswitch_os_memset(local_74,0,0x3c);
            local_74[0] = 0x3c0c;
            local_70 = 1;
            local_6c = local_88;
            nvswitch_os_memcpy(local_5c,param_2,3);
            local_64 = 0;
            local_60 = (uint)local_96;
            nvswitch_os_memset(local_90,0,iVar11);
            nvswitch_os_memcpy(local_90 + 1,pbVar7,local_96);
            iVar6 = nvswitch_os_sync_dma_region_for_device
                              (*(undefined8 *)(param_1 + 0x18),local_88,iVar11,2);
            if (iVar6 == 0) {
              local_94 = 0;
              nvswitch_timeout_create(4000000000,local_80);
              iVar6 = flcnQueueCmdPostBlocking(param_1,uVar2,local_74,0,0,0,&local_94,local_80);
              if (((iVar6 == 0) &&
                  (iVar6 = nvswitch_os_sync_dma_region_for_cpu
                                     (*(undefined8 *)(param_1 + 0x18),local_88,iVar11,2), iVar6 == 0
                  )) && (*local_90 != 0)) {
                iVar6 = -0xb;
              }
            }
            nvswitch_os_unmap_dma_region
                      (*(undefined8 *)(param_1 + 0x18),local_90,local_88,(uint)local_96,1);
          }
          nvswitch_os_free_contig_memory(*(undefined8 *)(param_1 + 0x18),local_90,iVar11);
        }
LAB_001bf5c6:
        nvswitch_os_free(pbVar7);
      }
    }
    else {
      iVar6 = -8;
    }
  }
  return iVar6;
}


// ===== 001bf800 nvswitch_inforom_add_object =====

undefined8 nvswitch_inforom_add_object(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    lVar1 = nvswitch_os_malloc_trace(0x28,0,0);
    if (lVar1 == 0) {
      uVar2 = 0xfffffffe;
    }
    else {
      nvswitch_os_memset(lVar1,0,0x28);
      nvswitch_os_memcpy(lVar1,param_2,0x1c);
      *(undefined8 *)(lVar1 + 0x20) = *(undefined8 *)(param_1 + 0xf78);
      uVar2 = 0;
      *(long *)(param_1 + 0xf78) = lVar1;
    }
    return uVar2;
  }
  return 0xfffffff8;
}


// ===== 001bf890 nvswitch_inforom_get_object_version_info =====

ulong nvswitch_inforom_get_object_version_info
                (long param_1,char *param_2,undefined1 *param_3,undefined1 *param_4)

{
  uint uVar1;
  char *pcVar2;
  ulong uVar3;
  long lVar4;
  undefined1 local_5c [8];
  char local_54 [20];
  uint local_40;
  
  if (*(long *)(param_1 + 0xf40) == 0) {
    return 0xfffffff3;
  }
  pcVar2 = *(char **)(*(long *)(param_1 + 0xf40) + 0xf78);
  if (pcVar2 != (char *)0x0) {
    do {
      if (((*param_2 == *pcVar2) && (param_2[1] == pcVar2[4])) && (param_2[2] == pcVar2[8]))
      goto LAB_001bf901;
      pcVar2 = *(char **)(pcVar2 + 0x20);
    } while (pcVar2 != (char *)0x0);
  }
  uVar3 = _nvswitch_inforom_read_file(param_1,param_2,8,local_5c);
  if ((((int)uVar3 == 0) &&
      (uVar3 = _nvswitch_inforom_unpack_object("3s2bwb",local_5c,local_54), (int)uVar3 == 0)) &&
     (uVar3 = 0xfffffff8, -1 < (short)((short)local_40 + -1))) {
    lVar4 = nvswitch_os_malloc_trace(local_40 & 0xffff,0,0);
    uVar3 = 0xfffffffe;
    if (lVar4 != 0) {
      uVar1 = _nvswitch_inforom_read_file(param_1,param_2,local_40 & 0xffff);
      nvswitch_os_free(lVar4);
      uVar3 = (ulong)uVar1;
      if (uVar1 == 0) {
        pcVar2 = local_54;
LAB_001bf901:
        *param_3 = (char)*(undefined4 *)(pcVar2 + 0xc);
        *param_4 = (char)*(undefined4 *)(pcVar2 + 0x10);
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}


// ===== 001bf9e0 nvswitch_inforom_read_static_data =====

void nvswitch_inforom_read_static_data(undefined8 param_1,char *param_2,undefined1 *param_3)

{
  long lVar1;
  
  if ((*param_2 != '\0') && (param_2[0xf0] == '\x01')) {
    *param_3 = 1;
    *(undefined4 *)(param_3 + 0x44) = *(undefined4 *)(param_2 + 0x100);
    lVar1 = 0;
    do {
      param_3[lVar1 + 0x29] = (char)*(undefined4 *)(param_2 + lVar1 * 4 + 0x104);
      lVar1 = lVar1 + 1;
    } while (lVar1 != 0x18);
    lVar1 = 0;
    do {
      param_3[lVar1 + 0x19] = (char)*(undefined4 *)(param_2 + lVar1 * 4 + 0x164);
      lVar1 = lVar1 + 1;
    } while (lVar1 != 0x10);
    lVar1 = 1;
    do {
      param_3[lVar1] = (char)*(undefined4 *)(param_2 + lVar1 * 4 + 0x20c);
      lVar1 = lVar1 + 1;
    } while (lVar1 != 0x15);
    *(undefined4 *)(param_3 + 0x15) = 0;
  }
  if (param_2[0x430] != '\0') {
    param_3[0x48] = 1;
    lVar1 = 0;
    do {
      param_3[lVar1 + 0x49] = (char)*(undefined4 *)(param_2 + lVar1 * 4 + 0x650);
      lVar1 = lVar1 + 1;
    } while (lVar1 != 0x20);
  }
  if (param_2[0xe30] != '\0') {
    param_3[0x69] = 1;
    lVar1 = 0;
    do {
      param_3[lVar1 + 0x6a] = (char)*(undefined4 *)(param_2 + lVar1 * 4 + 0xe90);
      lVar1 = lVar1 + 1;
    } while (lVar1 != 0x10);
  }
  return;
}


// ===== 001bfb00 nvswitch_inforom_load_object =====

void nvswitch_inforom_load_object
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  int iVar1;
  
  iVar1 = nvswitch_inforom_read_object(param_1,param_3,param_4,param_5,param_6);
  if (iVar1 != 0) {
    return;
  }
  nvswitch_inforom_add_object(param_2,param_6);
  return;
}


// ===== 001bfb40 nvswitch_initialize_inforom =====

undefined8 nvswitch_initialize_inforom(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = nvswitch_os_malloc_trace(0xf80,0,0);
  if (lVar1 == 0) {
    uVar2 = 0xfffffffe;
  }
  else {
    nvswitch_os_memset(lVar1,0,0xf80);
    *(long *)(param_1 + 0xf40) = lVar1;
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 001bfba0 nvswitch_destroy_inforom =====

void nvswitch_destroy_inforom(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_1 + 0xf40);
  if (lVar1 != 0) {
    lVar3 = *(long *)(lVar1 + 0xf78);
    while (lVar3 != 0) {
      lVar2 = *(long *)(lVar3 + 0x20);
      nvswitch_os_free(lVar3);
      lVar3 = lVar2;
    }
    nvswitch_os_free(lVar1);
    *(undefined8 *)(param_1 + 0xf40) = 0;
  }
  return;
}


// ===== 001bfc20 nvswitch_inforom_post_init =====

void nvswitch_inforom_post_init(void)

{
  return;
}


// ===== 001bfc30 nvswitch_initialize_inforom_objects =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_initialize_inforom_objects(long param_1)

{
  if (*(long *)(param_1 + 0xf40) != 0) {
    nvswitch_inforom_read_only_objects_load();
    nvswitch_inforom_nvlink_load(param_1);
    nvswitch_inforom_ecc_load(param_1);
    nvswitch_inforom_oms_load(param_1);
    nvswitch_inforom_bbx_load(param_1);
    (**(code **)(param_1 + 0x890))(param_1);
    return 0;
  }
  return 0xfffffff3;
}


// ===== 001bfc90 nvswitch_destroy_inforom_objects =====

void nvswitch_destroy_inforom_objects(long param_1)

{
  if (*(long *)(param_1 + 0xf40) != 0) {
    nvswitch_inforom_bbx_unload();
    nvswitch_inforom_ecc_unload(param_1);
    nvswitch_inforom_nvlink_unload(param_1);
    nvswitch_inforom_oms_unload(param_1);
    return;
  }
  return;
}


// ===== 001bfce0 nvswitch_is_cci_supported_lr10 =====

undefined8 nvswitch_is_cci_supported_lr10(void)

{
  return 0;
}


// ===== 001bfcf0 nvswitch_cci_setup_gpio_pins_lr10 =====

void nvswitch_cci_setup_gpio_pins_lr10(void)

{
  return;
}


// ===== 001bfd00 nvswitch_cci_get_cci_link_mode_lr10 =====

undefined8 nvswitch_cci_get_cci_link_mode_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001bfd10 nvswitch_cci_discovery_lr10 =====

undefined8 nvswitch_cci_discovery_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001bfd20 nvswitch_cci_get_xcvrs_present_lr10 =====

void nvswitch_cci_get_xcvrs_present_lr10(void)

{
  return;
}


// ===== 001bfd30 nvswitch_cci_get_xcvrs_present_change_lr10 =====

void nvswitch_cci_get_xcvrs_present_change_lr10(void)

{
  return;
}


// ===== 001bfd40 nvswitch_cci_reset_lr10 =====

undefined8 nvswitch_cci_reset_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001bfd50 nvswitch_cci_reset_links_lr10 =====

undefined8 nvswitch_cci_reset_links_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001bfd60 nvswitch_cci_ports_cpld_read_lr10 =====

undefined8 nvswitch_cci_ports_cpld_read_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001bfd70 nvswitch_cci_ports_cpld_write_lr10 =====

undefined8 nvswitch_cci_ports_cpld_write_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001bfd80 nvswitch_cci_update_link_state_led_lr10 =====

void nvswitch_cci_update_link_state_led_lr10(void)

{
  return;
}


// ===== 001bfd90 nvswitch_cci_set_xcvr_led_state_lr10 =====

undefined8 nvswitch_cci_set_xcvr_led_state_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001bfda0 nvswitch_cci_get_xcvr_led_state_lr10 =====

undefined8 nvswitch_cci_get_xcvr_led_state_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001bfdb0 nvswitch_cci_setup_onboard_lr10 =====

undefined8 nvswitch_cci_setup_onboard_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001bfdc0 nvswitch_cci_setup_module_path_lr10 =====

undefined8 nvswitch_cci_setup_module_path_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001bfdd0 nvswitch_cci_module_access_cmd_lr10 =====

undefined8 nvswitch_cci_module_access_cmd_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001bfde0 nvswitch_cci_apply_control_set_values_lr10 =====

undefined8 nvswitch_cci_apply_control_set_values_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001bfdf0 nvswitch_cci_cmis_cage_bezel_marking_lr10 =====

undefined8 nvswitch_cci_cmis_cage_bezel_marking_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001bfe00 nvswitch_cci_get_grading_values_lr10 =====

undefined8 nvswitch_cci_get_grading_values_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001bfe10 nvswitch_cci_get_xcvr_mask_lr10 =====

undefined8 nvswitch_cci_get_xcvr_mask_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001bfe20 nvswitch_cci_set_xcvr_present_lr10 =====

void nvswitch_cci_set_xcvr_present_lr10(void)

{
  return;
}


// ===== 001bfe30 nvswitch_cci_destroy_lr10 =====

void nvswitch_cci_destroy_lr10(void)

{
  return;
}


// ===== 001bfe40 nvswitch_init_pll_config_lr10 =====

undefined8 nvswitch_init_pll_config_lr10(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined1 local_4c;
  undefined3 uStack_4b;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  uStack_48 = 100;
  uStack_44 = 100;
  uStack_40 = 0x6d6;
  uStack_3c = 0xed8;
  local_38 = 0xd;
  uStack_34 = 0x26;
  local_30 = 1;
  uStack_2c = 0xff;
  local_28 = 1;
  uStack_24 = 0xff;
  local_20 = 1;
  uStack_1c = 0x1f;
  local_70 = 0x5000186a0;
  local_68 = 0x1000000a4;
  _local_4c = CONCAT31(uStack_4b,1);
  local_60 = 0xf00000001;
  iVar1 = nvswitch_validate_pll_config(param_1,&local_70);
  if (iVar1 != 0) {
    local_70 = 0x5000186a0;
    local_68 = 0x2000000a4;
    local_60 = 0xc00000000;
    uVar2 = nvswitch_validate_pll_config(param_1,&local_70);
    if ((int)uVar2 != 0) {
      return uVar2;
    }
  }
  *(undefined8 *)(param_1 + 0x1f60) = local_70;
  *(undefined8 *)(param_1 + 0x1f68) = local_68;
  *(undefined8 *)(param_1 + 0x1f70) = local_60;
  *(undefined8 *)(param_1 + 0x1f78) = local_58;
  return 0;
}


// ===== 001bffe0 nvswitch_init_pll_lr10 =====

uint nvswitch_init_pll_lr10(long param_1)

{
  uint uVar1;
  ulong uVar2;
  
  if (((*(char *)(param_1 + 0x25) == '\0') && (*(char *)(param_1 + 0x24) == '\0')) &&
     (*(char *)(param_1 + 0x26) == '\0')) {
    uVar1 = nvswitch_reg_read_32(param_1,0x24000);
    if (((~uVar1 & 0x1020000) == 0) &&
       (uVar2 = nvswitch_reg_read_32(param_1,0x24050), (uVar2 & 0x800) != 0)) {
      uVar1 = nvswitch_reg_read_32(param_1,0x24080);
      return -(uint)((uVar1 & 0x800) == 0) & 0xfffffffb;
    }
    return 0xfffffffb;
  }
  return 0;
}


// ===== 001c0060 nvswitch_hw_counter_shutdown_lr10 =====

void nvswitch_hw_counter_shutdown_lr10(void)

{
  return;
}


// ===== 001c0070 nvswitch_hw_counter_read_counter_lr10 =====

undefined8 nvswitch_hw_counter_read_counter_lr10(void)

{
  return 0xfffffffffffffff3;
}


// ===== 001c0080 nvswitch_init_clock_gating_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

void nvswitch_init_clock_gating_lr10(long param_1)

{
  uint uVar1;
  uint uVar2;
  
  nvswitch_reg_write_32(param_1,0x1c04,0);
  nvswitch_reg_write_32(param_1,0x1200a8,0);
  nvswitch_reg_write_32(param_1,0x128250,0);
  nvswitch_reg_write_32(param_1,0x128a50,0);
  nvswitch_reg_write_32(param_1,0x129250,0);
  nvswitch_reg_write_32(param_1,0x129a50,0);
  nvswitch_reg_write_32(param_1,0x12a250,0);
  nvswitch_reg_write_32(param_1,0x12aa50,0);
  nvswitch_reg_write_32(param_1,0x12b250,0);
  nvswitch_reg_write_32(param_1,0x12ba50,0);
  nvswitch_reg_write_32(param_1,0x12c250,0);
  nvswitch_reg_write_32(param_1,0x8e000,0x4b);
  nvswitch_reg_write_32(param_1,0x8e004,0);
  (**(code **)(param_1 + 0x928))(param_1,0,0,0,0x4e8,4);
  (**(code **)(param_1 + 0x928))(param_1,0,0,0,0x4ec,0);
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x50,1);
  (**(code **)(param_1 + 0x928))(param_1,0xe,1,0,200,0);
  (**(code **)(param_1 + 0x928))(param_1,0xe,1,0,0xcc,0);
  (**(code **)(param_1 + 0x928))(param_1,0x10,1,0,200,0);
  (**(code **)(param_1 + 0x928))(param_1,0x10,1,0,0xcc,0);
  (**(code **)(param_1 + 0x928))(param_1,6,1,0,0x604,0);
  uVar2 = 0;
  while( true ) {
    uVar1 = (**(code **)(param_1 + 0x918))(param_1,7,0);
    if (uVar1 <= uVar2) break;
    uVar1 = (**(code **)(param_1 + 0x920))(param_1,7,0,uVar2,0x134);
    (**(code **)(param_1 + 0x928))(param_1,7,0,uVar2,0x134,uVar1 & 0xfffc0001 | 0x20008);
    uVar2 = uVar2 + 1;
  }
  nvswitch_reg_write_32(param_1,0x29600,0);
  uVar2 = (**(code **)(param_1 + 0x920))(param_1,2,0,0,0x674);
  (**(code **)(param_1 + 0x928))(param_1,2,0,0,0x674,uVar2 & 0xfffffff0);
  uVar2 = (**(code **)(param_1 + 0x920))(param_1,2,0,0,0x134);
  (**(code **)(param_1 + 0x928))(param_1,2,0,0,0x134,uVar2 & 0xfffc0001 | 0x20008);
  (**(code **)(param_1 + 0x920))(param_1,2,0,0,0x83c);
  (**(code **)(param_1 + 0x928))(param_1,2,0,0,0x83c,0xfe);
  (**(code **)(param_1 + 0x928))(param_1,2,0,0,0x840,2);
  return;
}


// ===== 001c03f0 _nvswitch_ptop_parse_entry_lr10 =====

void _nvswitch_ptop_parse_entry_lr10(undefined8 param_1,uint param_2,uint *param_3,byte *param_4)

{
  uint uVar1;
  
  uVar1 = param_2 & 3;
  if ((uVar1 != 2) && (uVar1 != 3)) {
    uVar1 = (uint)(uVar1 == 1);
  }
  *param_4 = (byte)(param_2 >> 0x1f);
  *param_3 = uVar1;
  return;
}


// ===== 001c0420 _nvswitch_ptop_parse_enum_lr10 =====

void _nvswitch_ptop_parse_enum_lr10
               (undefined8 param_1,uint param_2,uint *param_3,uint *param_4,uint *param_5)

{
  *param_3 = param_2 >> 2 & 0xff;
  *param_4 = param_2 >> 10 & 0xff;
  *param_5 = param_2 >> 0x14 & 0x7ff;
  return;
}


// ===== 001c0450 nvswitch_nvlw_handle_data1_lr10 =====

void nvswitch_nvlw_handle_data1_lr10
               (undefined8 param_1,uint param_2,undefined8 param_3,uint param_4,uint *param_5)

{
  if ((param_4 < 0x15) && ((0x103002UL >> ((ulong)param_4 & 0x3f) & 1) != 0)) {
    *param_5 = param_2 >> 0xc & 0x7ffff;
  }
  return;
}


// ===== 001c0480 nvswitch_nvlw_parse_enum_lr10 =====

void nvswitch_nvlw_parse_enum_lr10
               (undefined8 param_1,uint param_2,uint *param_3,uint *param_4,uint *param_5)

{
  *param_3 = param_2 >> 2 & 0x3f;
  *param_4 = param_2 >> 8 & 0xff;
  *param_5 = param_2 >> 0x14 & 0x7ff;
  if ((param_2 & 0xf0000) == 0) {
    return;
  }
  nvswitch_assert_log();
  return;
}


// ===== 001c04c0 nvswitch_nvlw_handle_data2_lr10 =====

void nvswitch_nvlw_handle_data2_lr10(undefined8 param_1,ulong param_2,long param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)param_2;
  uVar1 = (uint)(param_2 >> 0x1a) & 0x1f;
  if (uVar1 == 6) {
    *(undefined4 *)(param_3 + 0xc) = 3;
    *(uint *)(param_3 + 0x10) = uVar2 & 0x3fffffc;
    return;
  }
  if (uVar1 < 7) {
    if ((param_2 >> 0x1a & 0x1f) == 0) {
      *(undefined4 *)(param_3 + 0xc) = 0;
      return;
    }
    if (uVar1 == 5) {
      *(undefined4 *)(param_3 + 0xc) = 2;
      *(uint *)(param_3 + 0x10) = uVar2 & 0x3fffffc;
      return;
    }
  }
  else if (uVar1 - 7 < 3) {
    *(undefined4 *)(param_3 + 0xc) = 3;
    *(uint *)(param_3 + 0x14 + (ulong)(uVar1 - 7) * 4) = uVar2 & 0x3fffffc;
    return;
  }
  nvswitch_assert_log();
  return;
}


// ===== 001c0540 nvswitch_nxbar_handle_data2_lr10 =====

void nvswitch_nxbar_handle_data2_lr10(undefined8 param_1,ulong param_2,long param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)param_2;
  uVar1 = (uint)(param_2 >> 0x1a) & 0x1f;
  if (uVar1 == 6) {
    *(undefined4 *)(param_3 + 0xc) = 3;
    *(uint *)(param_3 + 0x10) = uVar2 & 0x3fffffc;
    *(undefined8 *)(param_3 + 0x14) = 0;
    *(undefined4 *)(param_3 + 0x1c) = 0;
    return;
  }
  if (uVar1 < 7) {
    if ((param_2 >> 0x1a & 0x1f) == 0) {
      *(undefined4 *)(param_3 + 0xc) = 0;
      return;
    }
    if (uVar1 == 5) {
      *(undefined4 *)(param_3 + 0xc) = 2;
      *(uint *)(param_3 + 0x10) = uVar2 & 0x3fffffc;
      return;
    }
  }
  else if (uVar1 - 7 < 3) {
    *(uint *)(param_3 + 0x14 + (ulong)(uVar1 - 7) * 4) = uVar2 & 0x3fffffc;
    nvswitch_assert_log();
    return;
  }
  nvswitch_assert_log();
  return;
}


// ===== 001c05d0 _nvswitch_ptop_handle_data2_lr10 =====

void _nvswitch_ptop_handle_data2_lr10(undefined8 param_1,ulong param_2,long param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)param_2;
  uVar1 = (uint)(param_2 >> 0x1a) & 0x1f;
  if (uVar1 == 5) {
    *(undefined4 *)(param_3 + 0xc) = 2;
    *(uint *)(param_3 + 0x10) = uVar2 & 0x3fffffc;
    return;
  }
  if (uVar1 < 6) {
    if ((param_2 >> 0x1a & 0x1f) == 0) {
      *(undefined4 *)(param_3 + 0xc) = 0;
      return;
    }
    if (uVar1 == 4) {
      *(undefined4 *)(param_3 + 0xc) = 1;
      *(uint *)(param_3 + 0x18) = uVar2 & 0x3fffffc;
      return;
    }
  }
  else {
    if (uVar1 == 6) {
      *(undefined4 *)(param_3 + 0xc) = 3;
      *(uint *)(param_3 + 0x10) = uVar2 & 0x3fffffc;
      return;
    }
    if (uVar1 - 7 < 3) {
      *(undefined4 *)(param_3 + 0xc) = 3;
      *(uint *)(param_3 + 0x14 + (ulong)(uVar1 - 7) * 4) = uVar2 & 0x3fffffc;
      return;
    }
  }
  *(undefined4 *)(param_3 + 0xc) = 0;
  nvswitch_assert_log();
  return;
}


// ===== 001c0670 nvswitch_nxbar_handle_data1_lr10 =====

void nvswitch_nxbar_handle_data1_lr10
               (undefined8 param_1,uint param_2,long param_3,int param_4,uint *param_5)

{
  if (param_4 == 1) {
    *param_5 = param_2 >> 0xc & 0x7ffff;
    return;
  }
  if (param_3 != 0) {
    if ((param_2 & 0x7ffff000) == 0) {
      return;
    }
    nvswitch_assert_log();
    return;
  }
  return;
}


// ===== 001c06b0 _nvswitch_ptop_handle_data1_lr10 =====

void _nvswitch_ptop_handle_data1_lr10
               (undefined8 param_1,ulong param_2,long param_3,int param_4,uint *param_5)

{
  if (param_4 != 1) {
    if ((param_2 & 0x7fc00000) != 0) {
      nvswitch_assert_log();
      param_2 = param_2 & 0xffffffff;
    }
    if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0xc) = 1;
      *(uint *)(param_3 + 0x14) = (uint)param_2 >> 0x11 & 0x1f;
      *(uint *)(param_3 + 0x10) = (uint)(param_2 >> 0xc) & 0x1f;
    }
    return;
  }
  *param_5 = (uint)param_2 >> 2 & 0x1fffffff;
  return;
}


// ===== 001c0720 _nvswitch_device_discovery_lr10.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_device_discovery_lr10_isra_0
               (undefined8 param_1,int param_2,long param_3,uint param_4,undefined8 *param_5)

{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  undefined1 *local_60;
  char local_4d;
  uint local_4c;
  uint local_48;
  uint local_44;
  undefined4 local_40;
  uint local_3c [3];
  
  uVar3 = 0;
  local_4c = 0;
  local_4d = '\0';
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c[0] = 2;
  local_60 = (undefined1 *)0x0;
  do {
    uVar1 = nvswitch_reg_read_32(param_1,param_2);
    (*(code *)*param_5)(param_1,uVar1,&local_4c,&local_4d);
    if (local_4c == 2) {
      (*(code *)param_5[2])(param_1,uVar1,local_60,local_48,local_3c);
    }
    else if (local_4c < 3) {
      if (local_4c != 0) {
        if (local_60 != (undefined1 *)0x0) {
          nvswitch_assert_log();
        }
        (*(code *)param_5[1])(param_1,uVar1,&local_48,&local_44,&local_40);
        puVar2 = (uint *)(param_3 + 8);
        do {
          if (puVar2[1] == local_48) {
            if (*(long *)(puVar2 + 2) == 0) {
              nvswitch_assert_log();
            }
            else if (local_44 < *puVar2) {
              local_60 = (undefined1 *)(*(long *)(puVar2 + 2) + (ulong)local_44 * 0x20);
              *local_60 = 1;
              *(undefined4 *)(local_60 + 8) = local_40;
              goto LAB_001c0850;
            }
          }
          puVar2 = puVar2 + 6;
        } while (puVar2 != (uint *)(param_3 + 8 + (ulong)param_4 * 0x18));
        if (local_60 != (undefined1 *)0x0) {
          *local_60 = 1;
          *(undefined4 *)(local_60 + 8) = local_40;
        }
      }
    }
    else if (local_4c == 3) {
      if (local_60 != (undefined1 *)0x0) {
        (*(code *)param_5[3])(param_1,uVar1,local_60,local_48);
      }
    }
    else {
      nvswitch_assert_log();
    }
LAB_001c0850:
    if (local_4d == '\0') {
      local_48 = 0;
      local_44 = 0xffffffff;
      local_40 = 0xffffffff;
      local_60 = (undefined1 *)0x0;
    }
    param_2 = param_2 + 4;
    uVar3 = uVar3 + 1;
    if (local_3c[0] <= uVar3) {
      if (local_4d == '\0') {
        return;
      }
      nvswitch_assert_log();
      return;
    }
  } while( true );
}


// ===== 001c0950 _nvswitch_npg_handle_data1_lr10 =====

void _nvswitch_npg_handle_data1_lr10
               (undefined8 param_1,uint param_2,undefined8 param_3,int param_4,uint *param_5)

{
  if (param_4 == 1) {
    *param_5 = param_2 >> 0xc & 0x7ffff;
    return;
  }
  if ((param_2 & 0x7ffff000) == 0) {
    return;
  }
  nvswitch_assert_log();
  return;
}


// ===== 001c0980 _nvswitch_npg_parse_enum_lr10 =====

void _nvswitch_npg_parse_enum_lr10
               (undefined8 param_1,uint param_2,uint *param_3,uint *param_4,uint *param_5)

{
  *param_3 = param_2 >> 2 & 0x3f;
  *param_4 = param_2 >> 8 & 0xff;
  *param_5 = param_2 >> 0x14 & 0x7ff;
  if ((param_2 & 0xf0000) == 0) {
    return;
  }
  nvswitch_assert_log();
  return;
}


// ===== 001c09c0 nvswitch_nxbar_parse_enum_lr10 =====

void nvswitch_nxbar_parse_enum_lr10
               (undefined8 param_1,uint param_2,uint *param_3,uint *param_4,uint *param_5)

{
  *param_3 = param_2 >> 2 & 0x3f;
  *param_4 = param_2 >> 8 & 0xff;
  *param_5 = param_2 >> 0x14 & 0x7ff;
  if ((param_2 & 0xf0000) == 0) {
    return;
  }
  nvswitch_assert_log();
  return;
}


// ===== 001c0a00 nvswitch_nvlw_parse_entry_lr10 =====

void nvswitch_nvlw_parse_entry_lr10(undefined8 param_1,uint param_2,uint *param_3,byte *param_4)

{
  uint uVar1;
  
  uVar1 = param_2 & 3;
  if ((uVar1 != 2) && (uVar1 != 3)) {
    uVar1 = (uint)(uVar1 == 1);
  }
  *param_4 = (byte)(param_2 >> 0x1f);
  *param_3 = uVar1;
  return;
}


// ===== 001c0a30 _nvswitch_npg_parse_entry_lr10 =====

void _nvswitch_npg_parse_entry_lr10(undefined8 param_1,uint param_2,uint *param_3,byte *param_4)

{
  uint uVar1;
  
  uVar1 = param_2 & 3;
  if ((uVar1 != 2) && (uVar1 != 3)) {
    uVar1 = (uint)(uVar1 == 1);
  }
  *param_4 = (byte)(param_2 >> 0x1f);
  *param_3 = uVar1;
  return;
}


// ===== 001c0a60 nvswitch_nxbar_parse_entry_lr10 =====

void nvswitch_nxbar_parse_entry_lr10(undefined8 param_1,uint param_2,uint *param_3,byte *param_4)

{
  uint uVar1;
  
  uVar1 = param_2 & 3;
  if ((uVar1 != 2) && (uVar1 != 3)) {
    uVar1 = (uint)(uVar1 == 1);
  }
  *param_4 = (byte)(param_2 >> 0x1f);
  *param_3 = uVar1;
  return;
}


// ===== 001c0a90 _nvswitch_npg_handle_data2_lr10 =====

void _nvswitch_npg_handle_data2_lr10(undefined8 param_1,ulong param_2,long param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)param_2;
  uVar1 = (uint)(param_2 >> 0x1a) & 0x1f;
  if (uVar1 == 6) {
    *(undefined4 *)(param_3 + 0xc) = 3;
    *(uint *)(param_3 + 0x10) = uVar2 & 0x3fffffc;
    return;
  }
  if (uVar1 < 7) {
    if ((param_2 >> 0x1a & 0x1f) == 0) {
      *(undefined4 *)(param_3 + 0xc) = 0;
      return;
    }
    if (uVar1 == 5) {
      *(undefined4 *)(param_3 + 0xc) = 2;
      *(uint *)(param_3 + 0x10) = uVar2 & 0x3fffffc;
      return;
    }
  }
  else if (uVar1 - 7 < 3) {
    *(undefined4 *)(param_3 + 0xc) = 3;
    *(uint *)(param_3 + 0x14 + (ulong)(uVar1 - 7) * 4) = uVar2 & 0x3fffffc;
    return;
  }
  nvswitch_assert_log();
  return;
}


// ===== 001c0b09 nvswitch_device_discovery_lr10.cold =====

void nvswitch_device_discovery_lr10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001c0b60 nvswitch_device_discovery_lr10 =====

undefined8 nvswitch_device_discovery_lr10(long param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined1 *puVar3;
  long lVar4;
  undefined1 *puVar5;
  long lVar6;
  ulong uVar7;
  long local_490;
  undefined1 *local_488;
  long local_480;
  long local_478;
  long local_470;
  long local_468;
  long local_460;
  undefined1 *local_458;
  long local_450;
  undefined1 *local_448;
  undefined1 *local_440;
  undefined1 *local_438;
  undefined1 *local_430;
  char *local_428;
  undefined8 local_420;
  undefined1 *local_418;
  char *local_410;
  undefined8 local_408;
  long local_400;
  char *local_3f8;
  undefined8 local_3f0;
  long local_3e8;
  char *local_3e0;
  undefined8 local_3d8;
  long local_3d0;
  char *local_3c8;
  undefined8 local_3c0;
  long local_3b8;
  char *local_3b0;
  undefined8 local_3a8;
  long local_3a0;
  char *local_398;
  undefined8 local_390;
  long local_388;
  char *local_380;
  undefined8 local_378;
  long local_370;
  char *local_368;
  undefined8 local_360;
  long local_358;
  char *local_350;
  undefined8 local_348;
  undefined1 *local_340;
  char *local_338;
  undefined8 local_330;
  long local_328;
  char *local_320;
  undefined8 local_318;
  long local_310;
  char *local_308;
  undefined8 local_300;
  long local_2f8;
  char *local_2f0;
  undefined8 local_2e8;
  long local_2e0;
  char *local_2d8;
  undefined8 local_2d0;
  long local_2c8;
  char *local_2c0;
  undefined8 local_2b8;
  long local_2b0;
  char *local_2a8;
  undefined8 local_2a0;
  long local_298;
  char *local_290;
  undefined8 local_288;
  long local_280;
  undefined *local_278;
  undefined8 local_270;
  long local_268;
  undefined *local_260;
  undefined8 local_258;
  undefined1 *local_250;
  char *local_248;
  undefined8 local_240;
  undefined1 *local_238;
  undefined *local_230;
  undefined8 local_228;
  long local_220;
  undefined *local_218;
  undefined8 local_210;
  long local_208;
  undefined *local_200;
  undefined8 local_1f8;
  long local_1f0;
  undefined *local_1e8;
  undefined8 local_1e0;
  long local_1d8;
  undefined *local_1d0;
  undefined8 local_1c8;
  long local_1c0;
  undefined *local_1b8;
  undefined8 local_1b0;
  long local_1a8;
  undefined *local_1a0;
  undefined8 local_198;
  long local_190;
  undefined *local_188;
  undefined8 local_180;
  long local_178;
  char *local_170;
  undefined8 local_168;
  undefined1 *local_160;
  char *local_158;
  undefined8 local_150;
  long local_148;
  char *local_140;
  undefined8 local_138;
  long local_130;
  char *local_128;
  undefined8 local_120;
  long local_118;
  undefined *local_110;
  undefined8 local_108;
  undefined1 *local_100;
  undefined *local_f8;
  undefined8 local_f0;
  long local_e8;
  undefined *local_e0;
  undefined8 local_d8;
  long local_d0;
  undefined *local_c8;
  undefined8 local_c0;
  long local_b8;
  undefined *local_b0;
  undefined8 local_a8;
  undefined1 *local_a0;
  char *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  char *local_80;
  undefined8 local_78;
  undefined1 *local_70;
  char *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  char *local_50;
  undefined8 local_48;
  long local_40;
  
  if (*(int *)(param_1 + 0x1f88) == 6) {
    lVar6 = *(long *)(param_1 + 0x1f90);
    local_478 = lVar6 + 0x3530;
    puVar3 = (undefined1 *)(lVar6 + 0x3a90);
    local_448 = &DAT_00003bb0 + lVar6;
    local_220 = lVar6 + 0x3550;
    local_460 = lVar6 + 0x3630;
    local_208 = lVar6 + 0x3570;
    local_458 = &DAT_00003650 + lVar6;
    local_1f0 = lVar6 + 0x3590;
    local_450 = lVar6 + 0x3670;
    local_1d8 = lVar6 + 0x35b0;
    local_480 = lVar6 + 0x3690;
    local_1c0 = lVar6 + 0x35d0;
    local_468 = lVar6 + 0x37d0;
    local_1a8 = lVar6 + 0x35f0;
    local_488 = &DAT_000037f0 + lVar6;
    local_190 = lVar6 + 0x3610;
    local_490 = lVar6 + 0x3810;
    local_b8 = lVar6 + 0x3870;
    local_470 = lVar6 + 0x3850;
    puVar5 = (undefined1 *)(lVar6 + 0x38b0);
    local_440 = &DAT_000039d0 + lVar6;
    local_40 = lVar6 + 0x3890;
    local_430 = (undefined1 *)(lVar6 + 0x39f0);
    local_438 = &DAT_00003a70 + lVar6;
  }
  else {
    local_438 = &DAT_00003a70;
    local_40 = 0x3890;
    puVar5 = (undefined1 *)0x38b0;
    local_b8 = 0x3870;
    local_430 = (undefined1 *)0x39f0;
    local_190 = 0x3610;
    local_1a8 = 0x35f0;
    local_1c0 = 0x35d0;
    local_440 = &DAT_000039d0;
    puVar3 = (undefined1 *)0x3a90;
    local_1d8 = 0x35b0;
    local_1f0 = 0x3590;
    local_470 = 0x3850;
    lVar6 = 0;
    local_208 = 0x3570;
    local_220 = 0x3550;
    local_490 = 0x3810;
    local_488 = &DAT_000037f0;
    local_468 = 0x37d0;
    local_480 = 0x3690;
    local_450 = 0x3670;
    local_458 = &DAT_00003650;
    local_460 = 0x3630;
    local_448 = &DAT_00003bb0;
    local_478 = 0x3530;
  }
  local_270 = 0x100000001;
  local_268 = local_478;
  local_258 = 0x400000009;
  local_240 = 0x500000001;
  local_238 = local_448;
  local_228 = 0x800000001;
  local_210 = 0x900000001;
  local_1f8 = 0xa00000001;
  local_1e0 = 0xb00000001;
  local_1c8 = 0xc00000001;
  local_1b0 = 0xd00000001;
  local_198 = 0xe00000001;
  local_278 = &DAT_00c800a7;
  local_260 = &DAT_00c800ac;
  local_248 = "NPG_BCAST";
  local_230 = &DAT_00c800ba;
  local_218 = &DAT_00c800bf;
  local_200 = &DAT_00c800c4;
  local_1e8 = &DAT_00c800c9;
  local_1d0 = &DAT_00c800ce;
  local_1b8 = &DAT_00c800d2;
  local_1a0 = &DAT_00c800d7;
  local_188 = &DAT_00c800db;
  local_180 = 0xf00000001;
  local_170 = "EXTDEV";
  local_178 = local_460;
  local_168 = 0x1000000001;
  local_158 = "PRIVMAIN";
  local_160 = local_458;
  local_150 = 0x1100000001;
  local_140 = "PRIVLOC";
  local_148 = local_450;
  local_138 = 0x120000000a;
  local_128 = "PTIMER";
  local_130 = local_480;
  local_120 = 0x1b00000001;
  local_110 = &DAT_00c800fe;
  local_118 = local_468;
  local_108 = 0x1d00000001;
  local_f8 = &DAT_00c80102;
  local_100 = local_488;
  local_f0 = 0x1e00000002;
  local_e0 = &DAT_00c80106;
  local_e8 = local_490;
  local_d8 = 0x1f00000001;
  local_c8 = &DAT_00c8010a;
  local_d0 = local_470;
  local_c0 = 0x2100000001;
  local_a8 = 0x1300000009;
  local_90 = 0x1400000001;
  local_88 = local_440;
  local_78 = 0x1500000004;
  uVar7 = 0;
  local_70 = local_430;
  local_60 = 0x1600000001;
  local_b0 = &DAT_00c8010d;
  local_58 = local_438;
  local_98 = "NVLW_BCAST";
  local_80 = "NXBAR";
  local_68 = "NXBAR_BCAST";
  local_50 = "THERM";
  local_48 = 0x2200000001;
  local_250 = puVar3;
  local_a0 = puVar5;
  _nvswitch_device_discovery_lr10_isra_0
            (param_1,param_2,&local_278,0x18,discovery_handlers_ptop_lr10);
  iVar2 = *(int *)(param_1 + 0x1f88);
  do {
    if (iVar2 != 6) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    lVar4 = *(long *)(param_1 + 0x1f90);
    while ((*(char *)(lVar4 + 0x38b0 + (uVar7 & 0xffffffff) * 0x20) == '\0' ||
           (iVar2 = *(int *)(lVar6 + 0x38c8 + uVar7 * 0x20), iVar2 == 0))) {
      uVar7 = uVar7 + 1;
      if (uVar7 == 9) goto LAB_001c139f;
    }
    local_428 = "MINION";
    local_420 = 0x400000009;
    local_418 = (undefined1 *)(lVar6 + 0x3bd0);
    uVar7 = uVar7 + 1;
    local_408 = 0x500000009;
    local_400 = lVar6 + 0x3d10;
    local_3f0 = 0x1200000024;
    local_3e8 = lVar6 + 0x45d0;
    local_3d8 = 0x1300000024;
    local_3d0 = lVar6 + 0x4ad0;
    local_3c0 = 0x1000000009;
    local_3b8 = lVar6 + 0x4fd0;
    local_3a8 = 0x1100000009;
    local_3a0 = lVar6 + 0x5110;
    local_390 = 0x600000024;
    local_388 = lVar6 + 0x3e50;
    local_378 = 0x900000009;
    local_370 = lVar6 + 0x4350;
    local_360 = 0xf00000009;
    local_358 = lVar6 + 0x4490;
    local_348 = 0x1400000009;
    local_330 = 0x1c00000009;
    local_328 = lVar6 + 0x5250;
    local_410 = "NVLIPT";
    local_3f8 = "TX_PERFMON";
    local_3e0 = "RX_PERFMON";
    local_3c8 = "TX_PERFMON_MULTICAST";
    local_3b0 = "RX_PERFMON_MULTICAST";
    local_398 = "NVLTLC";
    local_380 = "NVLTLC_MULTICAST";
    local_368 = "NVLIPT_SYS_PERFMON";
    local_350 = "NVLW";
    local_338 = "PLL";
    local_318 = 0x1500000009;
    local_310 = lVar6 + 0x5390;
    local_300 = 0x1700000009;
    local_2f8 = lVar6 + 0x59d0;
    local_2e8 = 0x1b00000009;
    local_2e0 = lVar6 + 0x6010;
    local_2d0 = 0x1900000009;
    local_2c8 = lVar6 + 0x6650;
    local_2b8 = 0x1600000024;
    local_2b0 = lVar6 + 0x54d0;
    local_2a0 = 0x1a00000024;
    local_298 = lVar6 + 0x5b10;
    local_288 = 0x1800000024;
    local_280 = lVar6 + 0x6150;
    local_320 = "NVLW_PERFMON";
    local_308 = "NVLDL_MULTICAST";
    local_2f0 = "NVLIPT_LNK_MULTICAST";
    local_2d8 = "SYS_PERFMON_MULTICAST";
    local_2c0 = "NVLDL";
    local_2a8 = "NVLIPT_LNK";
    local_290 = "SYS_PERFMON";
    local_340 = puVar5;
    _nvswitch_device_discovery_lr10_isra_0
              (param_1,iVar2,&local_428,0x12,discovery_handlers_nvlw_lr10);
    iVar2 = *(int *)(param_1 + 0x1f88);
  } while (uVar7 != 9);
  if (iVar2 != 6) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  lVar4 = *(long *)(param_1 + 0x1f90);
LAB_001c139f:
  iVar2 = 6;
  if (((&DAT_000039d0)[lVar4] != '\0') && (*(int *)(lVar6 + 0x39e8) != 0)) {
    local_418 = (undefined1 *)(lVar6 + 0x3cf0);
    local_428 = "MINION_BCAST";
    local_420 = 0x400000001;
    local_408 = 0x500000001;
    local_3f0 = 0x600000004;
    local_400 = lVar6 + 0x3e30;
    local_3d8 = 0x900000001;
    local_3e8 = lVar6 + 0x42d0;
    local_3c0 = 0xf00000001;
    local_3d0 = lVar6 + 0x4470;
    local_3a8 = 0x1000000001;
    local_3b8 = lVar6 + 0x45b0;
    local_390 = 0x1100000001;
    local_3a0 = lVar6 + 0x50f0;
    local_378 = 0x1200000004;
    local_388 = lVar6 + 0x5230;
    local_360 = 0x1300000004;
    local_370 = lVar6 + 0x4a50;
    local_348 = 0x1400000001;
    local_358 = lVar6 + 0x4f50;
    local_328 = lVar6 + 0x5370;
    local_340 = local_440;
    local_410 = "NVLIPT_BCAST";
    local_3f8 = "NVLTLC_BCAST";
    local_3e0 = "NVLTLC_MULTICAST_BCAST";
    local_3c8 = "NVLIPT_SYS_PERFMON_BCAST";
    local_3b0 = "TX_PERFMON_MULTICAST_BCAST";
    local_398 = "RX_PERFMON_MULTICAST_BCAST";
    local_380 = "TX_PERFMON_BCAST";
    local_368 = "RX_PERFMON_BCAST";
    local_350 = "NVLW_BCAST";
    local_338 = "PLL_BCAST";
    local_330 = 0x1c00000001;
    local_310 = lVar6 + 0x54b0;
    local_2f8 = lVar6 + 0x5af0;
    local_318 = 0x1500000001;
    local_2e0 = lVar6 + 0x6130;
    local_300 = 0x1700000001;
    local_2c8 = lVar6 + 0x6770;
    local_2e8 = 0x1b00000001;
    local_2b0 = lVar6 + 0x5950;
    local_2d0 = 0x1900000001;
    local_298 = lVar6 + 0x5f90;
    local_2b8 = 0x1600000004;
    local_280 = lVar6 + 0x65d0;
    local_2a0 = 0x1a00000004;
    local_320 = "NVLW_PERFMON_BCAST";
    local_308 = "NVLDL_MULTICAST_BCAST";
    local_2f0 = "NVLIPT_LNK_MULTICAST_BCAST";
    local_2d8 = "SYS_PERFMON_MULTICAST_BCAST";
    local_2c0 = "NVLDL_BCAST";
    local_2a8 = "NVLIPT_LNK_BCAST";
    local_290 = "SYS_PERFMON_BCAST";
    local_288 = 0x1800000004;
    _nvswitch_device_discovery_lr10_isra_0
              (param_1,*(int *)(lVar6 + 0x39e8),&local_428,0x12,discovery_handlers_nvlw_lr10);
    iVar2 = *(int *)(param_1 + 0x1f88);
  }
  uVar7 = 0;
  do {
    if (iVar2 != 6) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    lVar4 = *(long *)(param_1 + 0x1f90);
    while ((*(char *)(lVar4 + 0x3a90 + (uVar7 & 0xffffffff) * 0x20) == '\0' ||
           (iVar2 = *(int *)(lVar6 + 0x3aa8 + uVar7 * 0x20), iVar2 == 0))) {
      uVar7 = uVar7 + 1;
      if (uVar7 == 9) goto LAB_001c1547;
    }
    uVar7 = uVar7 + 1;
    local_428 = "NPG";
    local_420 = 0x100000009;
    local_408 = 0x200000024;
    local_400 = lVar6 + 0x68d0;
    local_3f0 = 0x300000009;
    local_3e8 = lVar6 + 0x6dd0;
    local_3d8 = 0x400000009;
    local_3d0 = lVar6 + 0x6790;
    local_3c0 = 0x500000024;
    local_3b8 = lVar6 + 0x6f10;
    local_3a8 = 0x600000009;
    local_3a0 = lVar6 + 0x7410;
    local_410 = "NPORT";
    local_3f8 = "NPORT_MULTICAST";
    local_3e0 = "NPG_PERFMON";
    local_3c8 = "NPORT_PERFMON";
    local_3b0 = "NPORT_PERFMON_MULTICAST";
    local_418 = puVar3;
    _nvswitch_device_discovery_lr10_isra_0(param_1,iVar2,&local_428,6,discovery_handlers_npg_lr10);
    iVar2 = *(int *)(param_1 + 0x1f88);
  } while (uVar7 != 9);
  if (iVar2 != 6) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  lVar4 = *(long *)(param_1 + 0x1f90);
LAB_001c1547:
  iVar2 = 6;
  if (((&DAT_00003bb0)[lVar4] != '\0') && (*(int *)(lVar6 + 0x3bc8) != 0)) {
    local_400 = lVar6 + 0x6d50;
    local_3e8 = lVar6 + 0x6ef0;
    local_420 = 0x100000001;
    local_3d0 = lVar6 + 0x68b0;
    local_418 = local_448;
    local_408 = 0x200000004;
    local_3f0 = 0x300000001;
    local_3b8 = lVar6 + 0x7390;
    local_3d8 = 0x400000001;
    local_3a0 = lVar6 + 30000;
    local_3c0 = 0x500000004;
    local_428 = "NPG_BCAST";
    local_410 = "NPORT_BCAST";
    local_3f8 = "NPORT_MULTICAST_BCAST";
    local_3e0 = "NPG_PERFMON_BCAST";
    local_3c8 = "NPORT_PERFMON_BCAST";
    local_3b0 = "NPORT_PERFMON_MULTICAST_BCAST";
    local_3a8 = 0x600000001;
    _nvswitch_device_discovery_lr10_isra_0
              (param_1,*(int *)(lVar6 + 0x3bc8),&local_428,6,discovery_handlers_npg_lr10);
    iVar2 = *(int *)(param_1 + 0x1f88);
  }
  uVar7 = 0;
  do {
    if (iVar2 != 6) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    lVar4 = *(long *)(param_1 + 0x1f90);
    while ((*(char *)(lVar4 + 0x39f0 + (uVar7 & 0xffffffff) * 0x20) == '\0' ||
           (iVar2 = *(int *)(lVar6 + 0x3a08 + uVar7 * 0x20), iVar2 == 0))) {
      uVar7 = uVar7 + 1;
      if (uVar7 == 4) goto LAB_001c16e6;
    }
    uVar7 = uVar7 + 1;
    local_428 = "NXBAR";
    local_420 = 0x100000004;
    local_408 = 0x200000010;
    local_400 = lVar6 + 0x75f0;
    local_3f0 = 0x300000004;
    local_3e8 = lVar6 + 0x7870;
    local_3d8 = 0x400000004;
    local_3d0 = lVar6 + 0x7550;
    local_3c0 = 0x500000010;
    local_3b8 = lVar6 + 0x7910;
    local_3a8 = 0x600000004;
    local_3a0 = lVar6 + 0x7b90;
    local_418 = local_430;
    local_410 = "TILE";
    local_3f8 = "TILE_MULTICAST";
    local_3e0 = "NXBAR_PERFMON";
    local_3c8 = "TILE_PERFMON";
    local_3b0 = "TILE_PERFMON_MULTICAST";
    _nvswitch_device_discovery_lr10_isra_0(param_1,iVar2,&local_428,6,discovery_handlers_nxbar_lr10)
    ;
    iVar2 = *(int *)(param_1 + 0x1f88);
  } while (uVar7 != 4);
  if (iVar2 != 6) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  lVar4 = *(long *)(param_1 + 0x1f90);
LAB_001c16e6:
  if (((&DAT_00003a70)[lVar4] != '\0') && (*(int *)(lVar6 + 0x3a88) != 0)) {
    local_400 = lVar6 + 0x77f0;
    local_3e8 = lVar6 + 0x78f0;
    local_420 = 0x100000001;
    local_3d0 = lVar6 + 0x75d0;
    local_418 = local_438;
    local_408 = 0x200000004;
    local_3f0 = 0x300000001;
    local_3d8 = 0x400000001;
    local_3b8 = lVar6 + 0x7b10;
    local_3c0 = 0x500000004;
    local_3a8 = 0x600000001;
    local_3a0 = lVar6 + 0x7c10;
    local_428 = "NXBAR_BCAST";
    local_410 = "TILE_BCAST";
    local_3f8 = "TILE_MULTICAST_BCAST";
    local_3e0 = "NXBAR_PERFMON_BCAST";
    local_3c8 = "TILE_PERFMON_BCAST";
    local_3b0 = "TILE_PERFMON_MULTICAST_BCAST";
    _nvswitch_device_discovery_lr10_isra_0
              (param_1,*(int *)(lVar6 + 0x3a88),&local_428,6,discovery_handlers_nxbar_lr10);
  }
  return 0;
}


// ===== 001c1db0 nvswitch_filter_discovery_lr10 =====

void nvswitch_filter_discovery_lr10(void)

{
  return;
}


// ===== 001c1db5 nvswitch_process_discovery_lr10.cold =====

void nvswitch_process_discovery_lr10_cold(void)

{
  code *pcVar1;
  
  nvswitch_get_link_eng_inst();
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001c1ec0 nvswitch_process_discovery_lr10 =====

undefined8 nvswitch_process_discovery_lr10(long param_1)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined1 *puVar8;
  ulong uVar9;
  ulong uVar10;
  bool bVar11;
  
  puVar7 = (undefined8 *)0x0;
  if (*(int *)(param_1 + 0x1f88) == 6) {
    puVar7 = *(undefined8 **)(param_1 + 0x1f90);
  }
  uVar10 = 0;
  do {
    uVar3 = nvswitch_get_link_eng_inst(param_1,uVar10 & 0xffffffff,5);
    if (uVar3 < 0x24) {
      if (*(int *)(param_1 + 0x1f88) != 6) {
        nvswitch_get_link_eng_inst(param_1,uVar10 & 0xffffffff,5);
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar1 = *(long *)(param_1 + 0x1f90);
      uVar3 = nvswitch_get_link_eng_inst(param_1,uVar10 & 0xffffffff,5);
      bVar11 = false;
      if (*(char *)(lVar1 + 0x68d0 + (ulong)uVar3 * 0x20) != '\0') {
        uVar3 = nvswitch_get_link_eng_inst(param_1,uVar10 & 0xffffffff,10);
        if (0x23 < uVar3) goto LAB_001c1f5b;
        if (*(int *)(param_1 + 0x1f88) != 6) {
          nvswitch_get_link_eng_inst(param_1,uVar10 & 0xffffffff,10);
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        lVar1 = *(long *)(param_1 + 0x1f90);
        uVar3 = nvswitch_get_link_eng_inst(param_1,uVar10 & 0xffffffff,10);
        bVar11 = false;
        if (*(char *)(lVar1 + 0x3e50 + (ulong)uVar3 * 0x20) != '\0') {
          uVar3 = nvswitch_get_link_eng_inst(param_1,uVar10 & 0xffffffff,0xb);
          if (0x23 < uVar3) goto LAB_001c1f5b;
          if (*(int *)(param_1 + 0x1f88) != 6) {
            nvswitch_get_link_eng_inst(param_1,uVar10 & 0xffffffff,0xb);
                    /* WARNING: Does not return */
            pcVar2 = (code *)invalidInstructionException();
            (*pcVar2)();
          }
          lVar1 = *(long *)(param_1 + 0x1f90);
          uVar3 = nvswitch_get_link_eng_inst(param_1,uVar10 & 0xffffffff,0xb);
          bVar11 = false;
          if (*(char *)(lVar1 + 0x54d0 + (ulong)uVar3 * 0x20) != '\0') {
            uVar3 = nvswitch_get_link_eng_inst(param_1,uVar10 & 0xffffffff,9);
            if (0x23 < uVar3) goto LAB_001c1f5b;
            if (*(int *)(param_1 + 0x1f88) != 6) {
              nvswitch_get_link_eng_inst(param_1,uVar10 & 0xffffffff,9);
                    /* WARNING: Does not return */
              pcVar2 = (code *)invalidInstructionException();
              (*pcVar2)();
            }
            lVar1 = *(long *)(param_1 + 0x1f90);
            uVar3 = nvswitch_get_link_eng_inst(param_1,uVar10 & 0xffffffff,9);
            bVar11 = false;
            if (*(char *)(lVar1 + 0x5b10 + (ulong)uVar3 * 0x20) != '\0') {
              uVar3 = nvswitch_get_link_eng_inst(param_1,uVar10 & 0xffffffff,6);
              if (8 < uVar3) goto LAB_001c1f5b;
              if (*(int *)(param_1 + 0x1f88) != 6) {
                nvswitch_get_link_eng_inst(param_1,uVar10 & 0xffffffff,6);
                    /* WARNING: Does not return */
                pcVar2 = (code *)invalidInstructionException();
                (*pcVar2)();
              }
              lVar1 = *(long *)(param_1 + 0x1f90);
              uVar3 = nvswitch_get_link_eng_inst(param_1,uVar10 & 0xffffffff,6);
              bVar11 = false;
              if (*(char *)(lVar1 + 0x38b0 + (ulong)uVar3 * 0x20) != '\0') {
                uVar3 = nvswitch_get_link_eng_inst(param_1,uVar10 & 0xffffffff,7);
                if (8 < uVar3) goto LAB_001c1f5b;
                if (*(int *)(param_1 + 0x1f88) != 6) {
                  nvswitch_get_link_eng_inst(param_1,uVar10 & 0xffffffff,7);
                    /* WARNING: Does not return */
                  pcVar2 = (code *)invalidInstructionException();
                  (*pcVar2)();
                }
                lVar1 = *(long *)(param_1 + 0x1f90);
                uVar3 = nvswitch_get_link_eng_inst(param_1,uVar10 & 0xffffffff,7);
                bVar11 = false;
                if (*(char *)(lVar1 + 0x3bd0 + (ulong)uVar3 * 0x20) != '\0') {
                  uVar3 = nvswitch_get_link_eng_inst(param_1,uVar10 & 0xffffffff,8);
                  if (8 < uVar3) goto LAB_001c1f5b;
                  if (*(int *)(param_1 + 0x1f88) != 6) {
                    nvswitch_get_link_eng_inst(param_1,uVar10 & 0xffffffff,8);
                    /* WARNING: Does not return */
                    pcVar2 = (code *)invalidInstructionException();
                    (*pcVar2)();
                  }
                  lVar1 = *(long *)(param_1 + 0x1f90);
                  uVar3 = nvswitch_get_link_eng_inst(param_1,uVar10 & 0xffffffff,8);
                  bVar11 = *(char *)(lVar1 + 0x3d10 + (ulong)uVar3 * 0x20) != '\0';
                }
              }
            }
          }
        }
      }
    }
    else {
LAB_001c1f5b:
      bVar11 = false;
    }
    uVar9 = uVar10 + 1;
    *(bool *)(param_1 + 0xf60 + uVar10 * 0x40) = bVar11;
    uVar10 = uVar9;
    if (uVar9 == 0x24) {
      uVar10 = *(ulong *)(param_1 + 0x44);
      puVar6 = puVar7 + 0x7ca;
      puVar8 = (undefined1 *)(param_1 + 0xf60);
      uVar9 = 0;
      do {
        if ((uVar10 >> (uVar9 & 0x3f) & 1) == 0) {
          *puVar8 = 0;
          *(undefined1 *)(puVar6 + 0x550) = 0;
          *(undefined1 *)(puVar6 + 0x618) = 0;
          *(undefined1 *)puVar6 = 0;
          *(undefined1 *)(puVar6 + 0xf0) = 0;
          *(undefined1 *)(puVar6 + 400) = 0;
        }
        uVar3 = (int)uVar9 + 1;
        uVar9 = (ulong)uVar3;
        puVar8 = puVar8 + 0x40;
        puVar6 = puVar6 + 4;
      } while (uVar3 != 0x24);
      puVar6 = puVar7 + 0x22;
      do {
        puVar6[-0x22] = &DAT_00c804b7;
        puVar6[-0x21] = 0x2e;
        puVar5 = puVar6 + -0x20;
        do {
          puVar4 = puVar5;
          *(undefined4 *)puVar4 = 0xffffffff;
          puVar5 = puVar4 + 1;
          *(undefined4 *)((long)puVar4 + 4) = 0xffffffff;
        } while (puVar5 != puVar6);
        puVar6 = puVar4 + 0x26;
        *puVar5 = 0xffffffffffffffff;
        puVar4[2] = 0xffffffffffffffff;
        *(undefined4 *)(puVar4 + 3) = 0;
      } while (puVar6 != puVar7 + 0x6c8);
      *puVar7 = &DAT_00c800d7;
      puVar7[1] = 0x100000000;
      if (*(char *)(puVar7 + 0x6c2) != '\0') {
        *(undefined4 *)(puVar7 + 2) = *(undefined4 *)(puVar7 + 0x6c4);
        *(undefined4 *)(puVar7 + 0x22) = *(undefined4 *)(puVar7 + 0x6c4);
      }
      *(undefined4 *)(puVar7 + 0x24) = 0;
      puVar7[0x25] = &DAT_00c800ce;
      puVar7[0x26] = 0x100000001;
      if (*(char *)(puVar7 + 0x6ba) != '\0') {
        *(undefined4 *)(puVar7 + 0x27) = *(undefined4 *)(puVar7 + 0x6bc);
        *(undefined4 *)(puVar7 + 0x47) = *(undefined4 *)(puVar7 + 0x6bc);
      }
      *(undefined4 *)(puVar7 + 0x49) = 0;
      puVar7[0x4a] = &DAT_00c800fe;
      puVar7[0x4b] = 0x100000002;
      if (*(char *)(puVar7 + 0x6fe) != '\0') {
        *(undefined4 *)(puVar7 + 0x4c) = *(undefined4 *)(puVar7 + 0x700);
        *(undefined4 *)(puVar7 + 0x6c) = *(undefined4 *)(puVar7 + 0x700);
      }
      *(undefined4 *)(puVar7 + 0x6e) = 0;
      puVar7[0x6f] = &DAT_00c80102;
      puVar7[0x70] = 0x200000003;
      if (*(char *)(puVar7 + 0x702) == '\0') {
        if (*(char *)(puVar7 + 0x706) != '\0') {
          *(undefined4 *)((long)puVar7 + 0x38c) = *(undefined4 *)(puVar7 + 0x708);
        }
      }
      else {
        *(undefined4 *)(puVar7 + 0x71) = *(undefined4 *)(puVar7 + 0x704);
        if (*(char *)(puVar7 + 0x706) != '\0') {
          *(undefined4 *)((long)puVar7 + 0x38c) = *(undefined4 *)(puVar7 + 0x708);
        }
        *(undefined4 *)(puVar7 + 0x91) = *(undefined4 *)(puVar7 + 0x704);
      }
      puVar6 = puVar7 + 0x96;
      *(undefined4 *)(puVar7 + 0x93) = 0;
      puVar7[0x95] = 0x900000004;
      puVar7[0x94] = &DAT_00c800ac;
      lVar1 = (long)puVar7 * -7;
      do {
        if (*(char *)(lVar1 + 0x1510 + (long)puVar6 * 8) != '\0') {
          *(undefined4 *)puVar6 = *(undefined4 *)(lVar1 + 0x1520 + (long)puVar6 * 8);
        }
        puVar6 = (undefined8 *)((long)puVar6 + 4);
      } while (puVar6 != (undefined8 *)((long)puVar7 + 0x4d4));
      if (*(char *)(puVar7 + 0x776) != '\0') {
        *(undefined4 *)(puVar7 + 0xb6) = *(undefined4 *)(puVar7 + 0x778);
      }
      puVar6 = puVar7 + 0xbb;
      *(undefined4 *)(puVar7 + 0xb8) = 0;
      puVar7[0xb9] = "NPORT";
      puVar7[0xba] = 0x2400000005;
      do {
        if (*(char *)(lVar1 + 0x3a10 + (long)puVar6 * 8) != '\0') {
          *(undefined4 *)puVar6 = *(undefined4 *)(lVar1 + 0x3a20 + (long)puVar6 * 8);
        }
        puVar6 = (undefined8 *)((long)puVar6 + 4);
      } while (puVar6 != puVar7 + 0xcd);
      if (*(char *)(puVar7 + 0xdde) != '\0') {
        *(undefined4 *)(puVar7 + 0xdb) = *(undefined4 *)(puVar7 + 0xde0);
      }
      puVar6 = puVar7 + 0xe0;
      *(undefined4 *)(puVar7 + 0xdd) = 0;
      puVar7[0xde] = &DAT_00c8010d;
      puVar7[0xdf] = 0x900000006;
      do {
        if (*(char *)(lVar1 + 0xb0 + (long)puVar6 * 8) != '\0') {
          *(undefined4 *)puVar6 = *(undefined4 *)(lVar1 + 0xc0 + (long)puVar6 * 8);
        }
        puVar6 = (undefined8 *)((long)puVar6 + 4);
      } while (puVar6 != (undefined8 *)((long)puVar7 + 0x724));
      if (*(char *)(puVar7 + 0x73a) != '\0') {
        *(undefined4 *)(puVar7 + 0x100) = *(undefined4 *)(puVar7 + 0x73c);
      }
      puVar6 = puVar7 + 0x105;
      *(undefined4 *)(puVar7 + 0x102) = 0;
      puVar7[0x103] = "MINION";
      puVar7[0x104] = 0x900000007;
      do {
        if (*(char *)(lVar1 + -0x570 + (long)puVar6 * 8) != '\0') {
          *(undefined4 *)puVar6 = *(undefined4 *)(lVar1 + -0x560 + (long)puVar6 * 8);
        }
        puVar6 = (undefined8 *)((long)puVar6 + 4);
      } while (puVar6 != (undefined8 *)((long)puVar7 + 0x84c));
      if (*(char *)(puVar7 + 0x79e) != '\0') {
        *(undefined4 *)(puVar7 + 0x125) = *(undefined4 *)(puVar7 + 0x7a0);
      }
      puVar6 = puVar7 + 0x12a;
      *(undefined4 *)(puVar7 + 0x127) = 0;
      puVar7[0x128] = "NVLIPT";
      puVar7[0x129] = 0x900000008;
      do {
        if (*(char *)(lVar1 + -0xd70 + (long)puVar6 * 8) != '\0') {
          *(undefined4 *)puVar6 = *(undefined4 *)(lVar1 + -0xd60 + (long)puVar6 * 8);
        }
        puVar6 = (undefined8 *)((long)puVar6 + 4);
      } while (puVar6 != (undefined8 *)((long)puVar7 + 0x974));
      if (*(char *)(puVar7 + 0x7c6) != '\0') {
        *(undefined4 *)(puVar7 + 0x14a) = *(undefined4 *)(puVar7 + 0x7c8);
      }
      puVar6 = puVar7 + 0x14f;
      *(undefined4 *)(puVar7 + 0x14c) = 0;
      puVar7[0x14d] = "NVLIPT_LNK";
      puVar7[0x14e] = 0x2400000009;
      do {
        if (*(char *)(lVar1 + 0x750 + (long)puVar6 * 8) != '\0') {
          *(undefined4 *)puVar6 = *(undefined4 *)(lVar1 + 0x760 + (long)puVar6 * 8);
        }
        puVar6 = (undefined8 *)((long)puVar6 + 4);
      } while (puVar6 != puVar7 + 0x161);
      if (*(char *)(puVar7 + 0xc26) != '\0') {
        *(undefined4 *)(puVar7 + 0x16f) = *(undefined4 *)(puVar7 + 0xc28);
      }
      puVar6 = puVar7 + 0x174;
      *(undefined4 *)(puVar7 + 0x171) = 0;
      puVar7[0x172] = "NVLTLC";
      puVar7[0x173] = 0x240000000a;
      do {
        if (*(char *)(lVar1 + -0x1eb0 + (long)puVar6 * 8) != '\0') {
          *(undefined4 *)puVar6 = *(undefined4 *)(lVar1 + -0x1ea0 + (long)puVar6 * 8);
        }
        puVar6 = (undefined8 *)((long)puVar6 + 4);
      } while (puVar6 != puVar7 + 0x186);
      if (*(char *)(puVar7 + 0x88e) != '\0') {
        *(undefined4 *)(puVar7 + 0x194) = *(undefined4 *)(puVar7 + 0x890);
      }
      puVar6 = puVar7 + 0x199;
      *(undefined4 *)(puVar7 + 0x196) = 0;
      puVar7[0x197] = "NVLDL";
      puVar7[0x198] = 0x240000000b;
      do {
        if (*(char *)(lVar1 + -0x1170 + (long)puVar6 * 8) != '\0') {
          *(undefined4 *)puVar6 = *(undefined4 *)(lVar1 + -0x1160 + (long)puVar6 * 8);
        }
        puVar6 = (undefined8 *)((long)puVar6 + 4);
      } while (puVar6 != puVar7 + 0x1ab);
      if (*(char *)(puVar7 + 0xb5e) != '\0') {
        *(undefined4 *)(puVar7 + 0x1b9) = *(undefined4 *)(puVar7 + 0xb60);
      }
      puVar6 = puVar7 + 0x1be;
      *(undefined4 *)(puVar7 + 0x1bb) = 0;
      puVar7[0x1bc] = "NXBAR";
      puVar7[0x1bd] = 0x40000000c;
      do {
        if (*(char *)(lVar1 + -0x3590 + (long)puVar6 * 8) != '\0') {
          *(undefined4 *)puVar6 = *(undefined4 *)(lVar1 + -0x3580 + (long)puVar6 * 8);
        }
        puVar6 = (undefined8 *)((long)puVar6 + 4);
      } while (puVar6 != puVar7 + 0x1c0);
      if (*(char *)(puVar7 + 0x74e) != '\0') {
        *(undefined4 *)(puVar7 + 0x1de) = *(undefined4 *)(puVar7 + 0x750);
      }
      puVar6 = puVar7 + 0x1e3;
      *(undefined4 *)(puVar7 + 0x1e0) = 0;
      puVar7[0x1e1] = &DAT_00c8040d;
      puVar7[0x1e2] = 0x100000000d;
      do {
        if (*(char *)(lVar1 + -0x2d0 + (long)puVar6 * 8) != '\0') {
          *(undefined4 *)puVar6 = *(undefined4 *)(lVar1 + -0x2c0 + (long)puVar6 * 8);
        }
        puVar6 = (undefined8 *)((long)puVar6 + 4);
      } while (puVar6 != puVar7 + 0x1eb);
      if (*(char *)(puVar7 + 0xf1e) != '\0') {
        *(undefined4 *)(puVar7 + 0x203) = *(undefined4 *)(puVar7 + 0xf20);
      }
      puVar6 = puVar7 + 0x208;
      *(undefined4 *)(puVar7 + 0x205) = 0;
      puVar7[0x206] = "NPG_PERFMON";
      puVar7[0x207] = 0x90000000e;
      do {
        if (*(char *)(lVar1 + -0x1a70 + (long)puVar6 * 8) != '\0') {
          *(undefined4 *)puVar6 = *(undefined4 *)(lVar1 + -0x1a60 + (long)puVar6 * 8);
        }
        puVar6 = (undefined8 *)((long)puVar6 + 4);
      } while ((undefined8 *)((long)puVar7 + 0x1064) != puVar6);
      if (*(char *)(puVar7 + 0xd16) != '\0') {
        *(undefined4 *)(puVar7 + 0x228) = *(undefined4 *)(puVar7 + 0xd18);
      }
      puVar6 = puVar7 + 0x22d;
      *(undefined4 *)(puVar7 + 0x22a) = 0;
      puVar7[0x22b] = "NPORT_PERFMON";
      puVar7[0x22c] = 0x240000000f;
      do {
        if (*(char *)(lVar1 + -0x1c30 + (long)puVar6 * 8) != '\0') {
          *(undefined4 *)puVar6 = *(undefined4 *)(lVar1 + -0x1c20 + (long)puVar6 * 8);
        }
        puVar6 = (undefined8 *)((long)puVar6 + 4);
      } while (puVar7 + 0x23f != puVar6);
      if (*(char *)(puVar7 + 0xea6) != '\0') {
        *(undefined4 *)(puVar7 + 0x24d) = *(undefined4 *)(puVar7 + 0xea8);
      }
      puVar6 = puVar7 + 0x252;
      *(undefined4 *)(puVar7 + 0x24f) = 0;
      puVar7[0x250] = "NVLW_PERFMON";
      puVar7[0x251] = 0x900000010;
      do {
        if (*(char *)(lVar1 + -0x40f0 + (long)puVar6 * 8) != '\0') {
          *(undefined4 *)puVar6 = *(undefined4 *)(lVar1 + -0x40e0 + (long)puVar6 * 8);
        }
        puVar6 = (undefined8 *)((long)puVar6 + 4);
      } while ((undefined8 *)((long)puVar7 + 0x12b4) != puVar6);
      if (*(char *)(puVar7 + 0xa96) != '\0') {
        *(undefined4 *)(puVar7 + 0x272) = *(undefined4 *)(puVar7 + 0xa98);
      }
      *(undefined4 *)(puVar7 + 0x274) = 0;
      return 0;
    }
  } while( true );
}


// ===== 001c2920 _flcnAreEngDescsInitialized_LR10 =====

bool _flcnAreEngDescsInitialized_LR10(undefined8 param_1,long param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if (((*(int *)(param_2 + 0x10) != 0) && (bVar1 = false, *(char *)(param_2 + 0x14) != '\0')) &&
     (bVar1 = true, *(int *)(param_2 + 0x18) != 0)) {
    return *(char *)(param_2 + 0x1c) != '\0';
  }
  return bVar1;
}


// ===== 001c2950 _flcnGetName_LR10 =====

char * _flcnGetName_LR10(undefined8 param_1,long param_2)

{
  char *pcVar1;
  
  pcVar1 = *(char **)(param_2 + 8);
  if (pcVar1 == (char *)0x0) {
    pcVar1 = "UNKNOWN";
  }
  return pcVar1;
}


// ===== 001c2970 _flcnReadCoreRev_LR10 =====

uint _flcnReadCoreRev_LR10(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = flcnRegRead_HAL(param_1,param_2,300);
  return iVar1 << 4 | CONCAT31((int3)((uint)iVar1 >> 8),(byte)iVar1 >> 6);
}


// ===== 001c2990 _flcnDbgInfoCapturePcTrace_LR10 =====

void _flcnDbgInfoCapturePcTrace_LR10(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = flcnRegRead_HAL(param_1,param_2,0x148);
  uVar2 = uVar1 >> 0x10 & 0xff;
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      uVar1 = uVar1 & 0xffffff00 | uVar3;
      uVar3 = uVar3 + 1;
      flcnRegWrite_HAL(param_1,param_2,0x148,uVar1);
    } while (uVar2 != uVar3);
  }
  return;
}


// ===== 001c2a20 _flcnIntrRetrigger_LR10 =====

void _flcnIntrRetrigger_LR10(undefined8 param_1,undefined8 param_2)

{
  flcnRegWrite_HAL(param_1,param_2,1000,1);
  return;
}


// ===== 001c2a40 _flcnConstruct_LR10 =====

undefined4 _flcnConstruct_LR10(undefined8 param_1,long param_2)

{
  byte bVar1;
  long lVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  
  lVar2 = *(long *)(param_2 + 0x48);
  *(undefined1 *)(param_2 + 0x30) = 1;
  *(undefined4 *)(param_2 + 100) = 1;
  if (*(char *)(param_2 + 0x32) == '\0') goto joined_r0x001c2b37;
  lVar4 = nvswitch_os_malloc_trace(0x50,0,0);
  *(long *)(param_2 + 0x58) = lVar4;
  if (lVar4 != 0) {
    nvswitch_os_memset(lVar4,0,0x50);
    bVar1 = *(byte *)(param_2 + 0x33);
    if (bVar1 == 0) {
      nvswitch_assert_log();
      bVar1 = *(byte *)(param_2 + 0x33);
    }
    lVar5 = nvswitch_os_malloc_trace((ulong)bVar1 * 0xa8,0,0);
    *(long *)(lVar4 + 0x30) = lVar5;
    if (lVar5 != 0) {
      nvswitch_os_memset(lVar5,0,(ulong)*(byte *)(param_2 + 0x33) * 0xa8);
      if (*(int *)(param_2 + 0x34) == 0) {
joined_r0x001c2b37:
        if (lVar2 == 0) {
          nvswitch_assert_log();
        }
        flcnableGetExternalConfig(param_1,lVar2,param_2 + 0x20);
        return 0;
      }
      if (*(int *)(param_2 + 0x34) - 1U < 0x100) {
        flcnQueueSeqInfoStateInit(param_1,param_2);
        goto joined_r0x001c2b37;
      }
      nvswitch_assert_log();
      uVar3 = 0x5b;
      goto LAB_001c2b6a;
    }
  }
  nvswitch_assert_log();
  uVar3 = 0x51;
LAB_001c2b6a:
  flcnDestruct_HAL(param_1,param_2);
  return uVar3;
}


// ===== 001c2ba0 _flcnWaitForResetToFinish_LR10 =====

undefined4 _flcnWaitForResetToFinish_LR10(long param_1,undefined8 param_2)

{
  char cVar1;
  uint uVar2;
  undefined1 local_30 [16];
  
  flcnRegWrite_HAL(param_1,param_2,0x40,0);
  if (*(char *)(param_1 + 0x24) == '\0') {
    nvswitch_timeout_create(5000000,local_30);
  }
  else {
    nvswitch_timeout_create(1000000000,local_30);
  }
  do {
    uVar2 = flcnRegRead_HAL(param_1,param_2,0x10c);
    if ((uVar2 & 6) == 0) {
      return 0;
    }
    cVar1 = nvswitch_timeout_check(local_30);
  } while (cVar1 == '\0');
  nvswitch_assert_log();
  return 0x65;
}


// ===== 001c2c30 _flcnRegWrite_LR10 =====

void _flcnRegWrite_LR10(undefined8 param_1,long param_2,int param_3,undefined4 param_4)

{
  nvswitch_reg_write_32(param_1,param_3 + *(int *)(param_2 + 0x10),param_4);
  return;
}


// ===== 001c2c40 _flcnRegRead_LR10 =====

void _flcnRegRead_LR10(undefined8 param_1,long param_2,int param_3)

{
  nvswitch_reg_read_32(param_1,param_3 + *(int *)(param_2 + 0x10));
  return;
}


// ===== 001c2c50 _flcnDestruct_LR10 =====

void _flcnDestruct_LR10(undefined8 param_1,long param_2)

{
  long lVar1;
  
  if (*(char *)(param_2 + 0x30) != '\0') {
    *(undefined1 *)(param_2 + 0x30) = 0;
    if (*(long *)(param_2 + 0x48) == 0) {
      nvswitch_assert_log();
      return;
    }
    if ((*(char *)(param_2 + 0x32) != '\0') && (lVar1 = *(long *)(param_2 + 0x58), lVar1 != 0)) {
      if (*(long *)(lVar1 + 0x30) != 0) {
        nvswitch_os_free();
        *(undefined8 *)(lVar1 + 0x30) = 0;
        lVar1 = *(long *)(param_2 + 0x58);
      }
      nvswitch_os_free(lVar1);
      *(undefined8 *)(param_2 + 0x58) = 0;
      return;
    }
  }
  return;
}


// ===== 001c2cd0 flcnSetupHal_LR10 =====

void flcnSetupHal_LR10(long *param_1)

{
  long lVar1;
  
  lVar1 = *param_1;
  *(code **)(lVar1 + 0x118) = _flcnReadCoreRev_LR10;
  *(code **)(lVar1 + 0x100) = _flcnRegRead_LR10;
  *(code **)(lVar1 + 0x108) = _flcnRegWrite_LR10;
  *(code **)(lVar1 + 0xf0) = _flcnConstruct_LR10;
  *(code **)(lVar1 + 0xf8) = _flcnDestruct_LR10;
  *(code **)(lVar1 + 0x110) = _flcnGetName_LR10;
  *(code **)(lVar1 + 0x130) = _flcnIntrRetrigger_LR10;
  *(code **)(lVar1 + 0x138) = _flcnAreEngDescsInitialized_LR10;
  *(code **)(lVar1 + 0x140) = _flcnWaitForResetToFinish_LR10;
  *(code **)(lVar1 + 0x148) = _flcnDbgInfoCapturePcTrace_LR10;
  return;
}


// ===== 001c2d50 _oms_parse.isra.0 =====

void _oms_parse_isra_0(long param_1)

{
  byte bVar1;
  uint uVar2;
  bool bVar3;
  uint *puVar4;
  long lVar5;
  
  do {
    lVar5 = *(long *)(param_1 + 0x10);
    puVar4 = (uint *)(lVar5 + 0xe4);
    do {
      *(uint **)(param_1 + 0x18) = puVar4;
      if (puVar4 == (uint *)0x0) break;
      uVar2 = *puVar4;
      if ((char)((char)uVar2 + (char)(uVar2 >> 8)) == '\0' && (uVar2 & 1) == 0) {
        *(uint *)(param_1 + 0x20) = uVar2;
        if (puVar4 < (uint *)(lVar5 + 0xe8U)) {
          puVar4 = puVar4 + 1;
          bVar3 = true;
          goto LAB_001c2d99;
        }
        *(undefined8 *)(param_1 + 0x18) = 0;
        goto LAB_001c2dbb;
      }
      puVar4 = puVar4 + -1;
    } while (puVar4 != (uint *)(lVar5 + 0x1c));
    puVar4 = (uint *)(lVar5 + 0x20);
    bVar3 = false;
LAB_001c2d99:
    *(uint **)(param_1 + 0x18) = puVar4;
    bVar1 = (byte)*puVar4;
    while( true ) {
      if ((bVar1 & 1) != 0) {
        *(uint **)(param_1 + 0x28) = puVar4;
        *puVar4 = *(uint *)(param_1 + 0x20);
        return;
      }
      if ((uint *)(lVar5 + 0xe8U) <= puVar4) break;
      puVar4 = puVar4 + 1;
      *(uint **)(param_1 + 0x18) = puVar4;
      bVar1 = (byte)*puVar4;
    }
    *(undefined8 *)(param_1 + 0x18) = 0;
    if (!bVar3) {
      nvswitch_assert_log();
      lVar5 = *(long *)(param_1 + 0x10);
    }
LAB_001c2dbb:
    nvswitch_os_memset(lVar5 + 0x20,0xff,200);
    *(int *)(lVar5 + 0x1c) = *(int *)(lVar5 + 0x1c) + 1;
  } while( true );
}


// ===== 001c2e40 nvswitch_inforom_nvl_log_error_event_lr10 =====

int nvswitch_inforom_nvl_log_error_event_lr10
              (undefined8 param_1,long param_2,byte *param_3,undefined1 *param_4)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined3 uVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  uint uVar7;
  ulong uVar8;
  uint *puVar9;
  undefined1 uVar10;
  uint uVar11;
  byte local_30;
  byte local_2f;
  ushort local_2e;
  int local_2c;
  
  local_30 = 0;
  local_2e = 0;
  if ((*param_3 < 0x10) && (param_3[1] < 0x10)) {
    uVar5 = nvswitch_os_get_platform_time_epoch();
    iVar4 = inforom_nvl_v3_map_error
                      (*(undefined4 *)(param_3 + 4),&local_30,&local_2e,&local_2f,&local_2c);
    if (iVar4 == 0) {
      uVar7 = (uint)local_2e;
      uVar11 = uVar7 & 0xfffffff0 | *param_3 & 0xf;
      local_2e = (ushort)uVar11;
      uVar3 = (undefined3)((uVar7 & 0xfffffff0) >> 8);
      uVar10 = (undefined1)uVar11;
      if (local_2c == 0) {
        local_2e = (ushort)CONCAT31(uVar3,uVar10) & 0xff0f | (param_3[1] & 0xf) << 4;
      }
      else if (local_2c == 1) {
        local_2e = (ushort)CONCAT31(uVar3,uVar10) & 0xff0f | (param_3[1] + 6 & 0xf) << 4;
      }
      else if (local_2c == 2) {
        local_2e = (ushort)CONCAT31(uVar3,uVar10) & 0xff0f | 0xd0;
        iVar4 = inforom_nvl_v3_encode_nvlipt_error_subtype(param_3[1],&local_2f);
        if (iVar4 != 0) {
          return iVar4;
        }
      }
      puVar9 = (uint *)(param_2 + 0x226c);
      uVar8 = 0;
      do {
        uVar7 = *puVar9;
        if (uVar7 == 0) {
          uVar7 = (uint)local_30;
          auVar2._8_8_ = 0;
          auVar2._0_8_ = uVar5 >> 9;
          uVar5 = SUB168(ZEXT816(0x44b82fa09b5a53) * auVar2,8);
          *(uint *)(param_2 + 0x226c + uVar8 * 0x18) = uVar7;
          *(uint *)(param_2 + 0x2270 + uVar8 * 0x18) = (uint)local_2e;
          *(uint *)(param_2 + 0x2274 + uVar8 * 0x18) = (uint)local_2f;
LAB_001c2f30:
          uVar11 = (uint)(uVar5 >> 0xb);
          if (uVar7 == 2) {
            uVar5 = *(ulong *)(param_2 + 0x227c + uVar8 * 0x18);
            if (uVar5 == 0xffffffffffffffff) {
              return 0;
            }
            lVar6 = uVar5 + *(uint *)(param_3 + 8);
            if (CARRY8(uVar5,(ulong)*(uint *)(param_3 + 8))) {
              lVar6 = -1;
            }
            *(int *)(param_2 + 0x227c + uVar8 * 0x18) = (int)lVar6;
            *(int *)(param_2 + 0x2280 + uVar8 * 0x18) = (int)((ulong)lVar6 >> 0x20);
            *(uint *)(param_2 + 0x2278 + uVar8 * 0x18) = uVar11;
          }
          else {
            if (uVar7 != 1) {
              return -8;
            }
            iVar4 = *(int *)(param_2 + 0x2280 + uVar8 * 0x18);
            if (iVar4 == -1) {
              return 0;
            }
            uVar7 = *(uint *)(param_2 + 0x2278 + uVar8 * 0x18);
            *(int *)(param_2 + 0x2280 + uVar8 * 0x18) = iVar4 + 1;
            if (uVar7 <= uVar11) {
              *(uint *)(param_2 + 0x227c + uVar8 * 0x18) =
                   (*(int *)(param_2 + 0x227c + uVar8 * 0x18) + uVar11) - uVar7 >> 1;
            }
            *(uint *)(param_2 + 0x2278 + uVar8 * 0x18) = uVar11;
          }
          *param_4 = 1;
          return 0;
        }
        if ((puVar9[1] == (uint)local_2e) && (puVar9[2] == (uint)local_2f)) {
          auVar1._8_8_ = 0;
          auVar1._0_8_ = uVar5 >> 9;
          uVar5 = SUB168(ZEXT816(0x44b82fa09b5a53) * auVar1,8);
          goto LAB_001c2f30;
        }
        uVar7 = (int)uVar8 + 1;
        uVar8 = (ulong)uVar7;
        puVar9 = puVar9 + 6;
        if (uVar7 == 0x2d1) {
          return -8;
        }
      } while( true );
    }
  }
  else {
    iVar4 = -1;
  }
  return iVar4;
}


// ===== 001c3120 nvswitch_inforom_nvl_get_max_correctable_error_rate_lr10 =====

undefined8 nvswitch_inforom_nvl_get_max_correctable_error_rate_lr10(long param_1,byte *param_2)

{
  byte bVar1;
  long lVar2;
  undefined8 uVar3;
  
  bVar1 = *param_2;
  if (bVar1 < 0x24) {
    if ((*(long *)(param_1 + 0xf40) == 0) ||
       (lVar2 = *(long *)(*(long *)(param_1 + 0xf40) + 0xf60), lVar2 == 0)) {
      uVar3 = 0xfffffff3;
    }
    else {
      nvswitch_os_memset(param_2,0,0xc4);
      *param_2 = bVar1;
      nvswitch_os_memcpy(param_2 + 4,*(long *)(lVar2 + 0x10) + 0x76c + (ulong)bVar1 * 0x18,0x78);
      nvswitch_os_memcpy(param_2 + 0x7c,*(long *)(lVar2 + 0x10) + 0x184c + (ulong)bVar1 * 0x18,0x48)
      ;
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ===== 001c31e0 nvswitch_inforom_nvl_get_errors_lr10 =====

undefined8 nvswitch_inforom_nvl_get_errors_lr10(long param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  undefined8 uVar4;
  int *piVar5;
  uint uVar6;
  uint *puVar7;
  
  if (*(long *)(param_1 + 0xf40) == 0) {
    return 0xfffffff3;
  }
  lVar2 = *(long *)(*(long *)(param_1 + 0xf40) + 0xf60);
  if (lVar2 == 0) {
    return 0xfffffff3;
  }
  uVar1 = *param_2;
  if (uVar1 < 0x2d1) {
    puVar7 = param_2 + 2;
    nvswitch_os_memset(puVar7,0,0xc00);
    piVar5 = (int *)(*(long *)(lVar2 + 0x10) + 0x226c + (ulong)uVar1 * 0x18);
    uVar3 = 0;
    do {
      if (*piVar5 == 0) {
        uVar6 = 0x80;
        if (uVar3 < 0x81) {
          uVar6 = uVar3;
        }
        param_2[1] = uVar6;
        *param_2 = uVar1 + uVar6;
        if (uVar3 == 0) {
          return 0;
        }
        goto LAB_001c32ac;
      }
      uVar3 = uVar3 + 1;
      piVar5 = piVar5 + 6;
    } while (uVar3 != 0x2d1 - uVar1);
    uVar6 = 0x80;
    if (uVar3 < 0x81) {
      uVar6 = uVar3;
    }
    param_2[1] = uVar6;
    *param_2 = uVar1 + uVar6;
LAB_001c32ac:
    uVar3 = 0;
    do {
      uVar4 = inforom_nvl_v3_map_error_to_userspace_error
                        (param_1,(long)puVar7 +
                                 *(long *)(lVar2 + 0x10) +
                                 ((ulong)uVar1 * 0x18 - (long)param_2) + 0x2264,puVar7);
      if ((int)uVar4 != 0) {
        return 0xfffffff3;
      }
      uVar3 = uVar3 + 1;
      puVar7 = puVar7 + 6;
    } while (uVar3 < uVar6);
  }
  else {
    uVar4 = 0xffffffff;
  }
  return uVar4;
}


// ===== 001c3370 nvswitch_inforom_nvl_update_link_correctable_error_info_lr10 =====

undefined8
nvswitch_inforom_nvl_update_link_correctable_error_info_lr10
          (undefined8 param_1,long param_2,long param_3,byte param_4,byte param_5,byte param_6,
          ushort *param_7,byte *param_8)

{
  long lVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  char cVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  uint *puVar9;
  uint *puVar10;
  long lVar11;
  uint *puVar12;
  long lVar13;
  byte local_55;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  byte local_44;
  byte local_43;
  int local_40;
  uint local_3c;
  
  local_55 = 0;
  if (((param_8 == (byte *)0x0) || (*param_8 = 0, 0xf < (param_5 | param_6))) || (0x23 < param_4)) {
    uVar7 = 0xffffffff;
  }
  else {
    uVar6 = nvswitch_os_get_platform_time_epoch();
    uVar8 = (undefined4)(uVar6 / 1000000000);
    inforom_nvl_v3_seconds_to_day_and_month(uVar6 / 1000000000 & 0xffffffff,&local_54,&local_50);
    inforom_nvl_v3_update_correctable_error_rates(param_3,param_4,param_7);
    uVar6 = (ulong)param_4;
    uVar3 = *(undefined4 *)(param_3 + (ulong)param_4 * 0x14);
    lVar1 = param_3 + 4 + uVar6 * 0x14;
    lVar11 = uVar6 * 0x18;
    puVar10 = (uint *)(param_2 + 0x76c + lVar11);
    puVar9 = (uint *)0x0;
    do {
      inforom_nvl_v3_seconds_to_day_and_month(*puVar10,&local_4c,&local_48);
      if ((*puVar10 == 0) || (local_4c == local_54)) {
        cVar5 = inforom_nvl_v3_should_replace_error_rate_entry(puVar10,uVar3,lVar1);
        if (cVar5 == '\0') {
          puVar12 = (uint *)0x0;
        }
        else {
          puVar12 = (uint *)0x0;
          inforom_nvl_v3_update_error_rate_entry(puVar10,uVar8,uVar3,lVar1);
          local_55 = 1;
        }
        goto LAB_001c34d3;
      }
      puVar12 = puVar10;
      if ((puVar9 != (uint *)0x0) && (puVar12 = puVar9, *puVar10 < *puVar9)) {
        puVar12 = puVar10;
      }
      puVar10 = puVar10 + 0xd8;
      puVar9 = puVar12;
    } while (puVar10 != (uint *)(param_2 + 0x184c + lVar11));
    inforom_nvl_v3_update_error_rate_entry(puVar12,uVar8,uVar3,lVar1);
    local_55 = 1;
LAB_001c34d3:
    lVar13 = 0;
    do {
      puVar10 = (uint *)(param_2 + 0x184c + uVar6 * 0x18 + lVar13);
      inforom_nvl_v3_seconds_to_day_and_month
                (*(undefined4 *)(param_2 + lVar11 + 0x184c + lVar13),&local_4c,&local_48);
      uVar4 = *(uint *)(param_2 + lVar11 + 0x184c + lVar13);
      if ((uVar4 == 0) || (local_48 == local_50)) {
        cVar5 = inforom_nvl_v3_should_replace_error_rate_entry(puVar10,uVar3,lVar1);
        if (cVar5 != '\0') goto LAB_001c3561;
        goto LAB_001c357c;
      }
      puVar9 = puVar10;
      if ((puVar12 != (uint *)0x0) && (puVar9 = puVar12, uVar4 < *puVar12)) {
        puVar9 = puVar10;
      }
      lVar13 = lVar13 + 0x360;
      puVar12 = puVar9;
    } while (lVar13 != 0xa20);
    puVar10 = puVar9;
    if (puVar9 != (uint *)0x0) {
LAB_001c3561:
      inforom_nvl_v3_update_error_rate_entry(puVar10,uVar8,uVar3,lVar1);
      local_55 = 1;
    }
LAB_001c357c:
    *param_8 = local_55;
    local_44 = param_5;
    local_43 = param_6;
    if (*param_7 != 0) {
      local_40 = 2;
      local_3c = (uint)*param_7;
      nvswitch_inforom_nvl_log_error_event_lr10(param_1,param_2,&local_44,&local_55);
      *param_8 = *param_8 | local_55;
    }
    if (param_7[5] != 0) {
      local_40 = 7;
      local_3c = (uint)param_7[5];
      local_55 = 0;
      nvswitch_inforom_nvl_log_error_event_lr10(param_1,param_2,&local_44,&local_55);
      *param_8 = *param_8 | local_55;
    }
    if (param_7[6] != 0) {
      local_40 = 0xb;
      local_3c = (uint)param_7[6];
      local_55 = 0;
      nvswitch_inforom_nvl_log_error_event_lr10(param_1,param_2,&local_44,&local_55);
      *param_8 = *param_8 | local_55;
    }
    if (param_7[7] != 0) {
      local_40 = 0xe;
      local_3c = (uint)param_7[7];
      local_55 = 0;
      nvswitch_inforom_nvl_log_error_event_lr10(param_1,param_2,&local_44,&local_55);
      *param_8 = *param_8 | local_55;
    }
    lVar11 = 0;
    do {
      bVar2 = *(byte *)((long)param_7 + lVar11 + 2);
      if (bVar2 != 0) {
        local_40 = (int)lVar11 + 3;
        local_3c = (uint)bVar2;
        local_55 = 0;
        nvswitch_inforom_nvl_log_error_event_lr10(param_1,param_2,&local_44,&local_55);
        *param_8 = *param_8 | local_55;
      }
      lVar11 = lVar11 + 1;
    } while (lVar11 != 4);
    uVar7 = 0;
  }
  return uVar7;
}


// ===== 001c3790 nvswitch_inforom_nvl_setL1Threshold_lr10 =====

undefined8 nvswitch_inforom_nvl_setL1Threshold_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001c37a0 nvswitch_inforom_nvl_getL1Threshold_lr10 =====

undefined8 nvswitch_inforom_nvl_getL1Threshold_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001c37b0 nvswitch_inforom_nvl_setup_nvlink_state_lr10 =====

undefined8
nvswitch_inforom_nvl_setup_nvlink_state_lr10(undefined8 param_1,undefined8 *param_2,char param_3)

{
  long lVar1;
  
  if (param_3 != '\x03') {
    return 0xfffffff3;
  }
  *param_2 = &DAT_00c804c0;
  lVar1 = nvswitch_os_malloc_trace(0x4590,0,0);
  param_2[1] = lVar1;
  if (lVar1 != 0) {
    lVar1 = nvswitch_os_malloc_trace(0xadb4,0,0);
    param_2[2] = lVar1;
    if (lVar1 != 0) {
      *(undefined1 *)((long)param_2 + 0x1a) = 0;
      return 0;
    }
    nvswitch_os_free(param_2[1]);
  }
  return 0xfffffffe;
}


// ===== 001c3830 nvswitch_inforom_ecc_log_error_event_lr10 =====

undefined8 nvswitch_inforom_ecc_log_error_event_lr10(undefined8 param_1,long param_2,uint *param_3)

{
  long lVar1;
  long lVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  uint uVar5;
  ulong uVar6;
  ulong uVar7;
  byte bVar8;
  ulong uVar9;
  uint *puVar10;
  ulong uVar11;
  ulong *puVar12;
  
  if ((param_3 != (uint *)0x0) && (param_2 != 0)) {
    puVar10 = (uint *)(param_2 + 0x30);
    bVar8 = 0;
    while (((((puVar10[1] != *param_3 || ((*puVar10 >> 2 & 1) != (uint)(byte)param_3[2])) ||
             (puVar10[8] != param_3[3])) || ((uint)(byte)puVar10[4] != param_3[1])) &&
           ((*puVar10 & 1) != 0))) {
      bVar8 = bVar8 + 1;
      puVar10 = puVar10 + 9;
      if (bVar8 == 0x80) {
        return 0xfffffffd;
      }
    }
    uVar6 = (ulong)bVar8;
    lVar1 = param_2 + uVar6 * 0x24;
    uVar5 = *(uint *)(lVar1 + 0x30);
    lVar2 = param_2 + 0x4c;
    if ((char)param_3[5] == '\0') {
      lVar2 = param_2 + 0x48;
    }
    puVar10 = (uint *)(lVar2 + uVar6 * 0x24);
    if ((uVar5 & 1) == 0) {
      *(uint *)(lVar1 + 0x34) = *param_3;
      *(char *)(lVar1 + 0x40) = (char)param_3[1];
      *(uint *)(lVar1 + 0x30) = ((byte)param_3[2] & 1) << 2 | uVar5 & 0xfffffffb;
      uVar5 = param_3[3];
      *(undefined4 *)(lVar1 + 0x44) = 0;
      *(uint *)(lVar1 + 0x50) = uVar5;
      *puVar10 = param_3[6];
      *(uint *)(lVar1 + 0x30) = *(uint *)(lVar1 + 0x30) | 1;
      *(undefined4 *)(lVar1 + 0x3c) = 0;
    }
    else {
      uVar9 = (ulong)(uint)(*(int *)(lVar1 + 0x48) + *(int *)(lVar1 + 0x4c));
      uVar7 = (ulong)*(uint *)(lVar1 + 0x3c) * (uVar9 - 1);
      uVar11 = (ulong)(param_3[4] - *(int *)(lVar1 + 0x38));
      if ((CARRY8(uVar7,uVar11)) ||
         (auVar3._8_8_ = 0, auVar3._0_8_ = (uVar9 - 1) + (ulong)param_3[6], auVar4._8_8_ = 0,
         auVar4._0_8_ = uVar7 + uVar11, SUB168(auVar4 / auVar3,0) >> 0x20 != 0)) {
        *(uint *)(param_2 + 0x30 + uVar6 * 0x24) = uVar5 | 2;
      }
      else {
        *(int *)(lVar1 + 0x3c) = SUB164(auVar4 / auVar3,0);
      }
      uVar5 = (uint)((ulong)*puVar10 + (ulong)param_3[6]);
      if (0xffffffff < (ulong)*puVar10 + (ulong)param_3[6]) {
        uVar5 = 0xffffffff;
      }
      *puVar10 = uVar5;
    }
    *(uint *)(param_2 + 0x38 + uVar6 * 0x24) = param_3[4];
    puVar12 = (ulong *)(param_2 + 0x24);
    if ((char)param_3[5] != '\0') {
      puVar12 = (ulong *)(param_2 + 0x1c);
    }
    uVar6 = (ulong)param_3[6] + *puVar12;
    if (CARRY8((ulong)param_3[6],*puVar12)) {
      uVar6 = 0xffffffffffffffff;
    }
    *puVar12 = uVar6;
    nvswitch_smbpbi_refresh_ecc_counts(param_1);
    return 0;
  }
  return 0xffffffff;
}


// ===== 001c39f0 nvswitch_inforom_ecc_get_total_errors_lr10 =====

void nvswitch_inforom_ecc_get_total_errors_lr10
               (undefined8 param_1,long param_2,undefined8 *param_3,undefined8 *param_4)

{
  *param_3 = *(undefined8 *)(param_2 + 0x24);
  *param_4 = *(undefined8 *)(param_2 + 0x1c);
  return;
}


// ===== 001c3a10 nvswitch_inforom_ecc_get_errors_lr10 =====

undefined8 nvswitch_inforom_ecc_get_errors_lr10(long param_1,long param_2)

{
  long lVar1;
  uint *puVar2;
  undefined8 uVar3;
  uint *puVar4;
  int iVar5;
  
  if ((*(long *)(param_1 + 0xf40) == 0) ||
     (lVar1 = *(long *)(*(long *)(param_1 + 0xf40) + 0xf68), lVar1 == 0)) {
    return 0xfffffff3;
  }
  lVar1 = *(long *)(lVar1 + 0x10);
  if (lVar1 == 0) {
    uVar3 = 0xfffffff3;
  }
  else {
    nvswitch_os_memset(param_2 + 0x14,0,0xe00);
    nvswitch_os_memcpy(param_2 + 8,lVar1 + 0x24,8);
    nvswitch_os_memcpy(param_2,lVar1 + 0x1c,8);
    iVar5 = 0;
    puVar2 = (uint *)(lVar1 + 0x30);
    puVar4 = (uint *)(param_2 + 0x14);
    do {
      if ((*puVar2 & 1) == 0) break;
      iVar5 = iVar5 + 1;
      *puVar4 = puVar2[1];
      *(char *)(puVar4 + 1) = (char)puVar2[4];
      puVar4[2] = puVar2[2];
      *(byte *)(puVar4 + 3) = (byte)(*puVar2 >> 2) & 1;
      puVar4[4] = puVar2[8];
      puVar4[5] = puVar2[6];
      puVar4[6] = puVar2[7];
      puVar2 = puVar2 + 9;
      puVar4 = puVar4 + 7;
    } while (iVar5 != 0x80);
    *(int *)(param_2 + 0x10) = iVar5;
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 001c3b00 nvswitch_oms_inforom_flush_lr10 =====

ulong nvswitch_oms_inforom_flush_lr10(long param_1)

{
  undefined8 *puVar1;
  ulong uVar2;
  
  if (*(long *)(param_1 + 0xf40) == 0) {
    return 0xfffffff3;
  }
  puVar1 = *(undefined8 **)(*(long *)(param_1 + 0xf40) + 0xf70);
  if (((puVar1 != (undefined8 *)0x0) && ((int *)puVar1[5] != (int *)0x0)) &&
     (*(int *)puVar1[5] != *(int *)(puVar1 + 4))) {
    uVar2 = nvswitch_inforom_write_object(param_1,&DAT_00c81834,*puVar1,puVar1[2],puVar1[1]);
    if ((int)uVar2 != 0) {
      return uVar2;
    }
    _oms_parse_isra_0(puVar1);
    return uVar2 & 0xffffffff;
  }
  return 0;
}


// ===== 001c3b90 nvswitch_initialize_oms_state_lr10 =====

void nvswitch_initialize_oms_state_lr10(undefined8 param_1,long param_2)

{
  *(undefined8 *)(param_2 + 0x28) = 0;
  *(undefined8 *)(param_2 + 0x18) = 0;
  *(undefined4 *)(param_2 + 0x20) = 0;
  _oms_parse_isra_0(param_2);
  return;
}


// ===== 001c3bc0 nvswitch_oms_get_device_disable_lr10 =====

byte nvswitch_oms_get_device_disable_lr10(long param_1)

{
  return **(byte **)(param_1 + 0x28) >> 1 & 1;
}


// ===== 001c3be0 nvswitch_oms_set_device_disable_lr10 =====

void nvswitch_oms_set_device_disable_lr10(long param_1,int param_2)

{
  uint uVar1;
  
  **(uint **)(param_1 + 0x28) = **(uint **)(param_1 + 0x28) & 0xfffffffd | param_2 * 2 & 2U;
  uVar1 = **(uint **)(param_1 + 0x28);
  **(uint **)(param_1 + 0x28) =
       (-(uVar1 & 0xff) & 0xff) << 8 | CONCAT22((short)(uVar1 >> 0x10),(ushort)(byte)uVar1);
  return;
}


// ===== 001c3c10 nvswitch_inforom_load_obd_lr10 =====

undefined8 nvswitch_inforom_load_obd_lr10(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0xf40);
  if (lVar1 != 0) {
    uVar2 = nvswitch_inforom_load_object
                      (param_1,lVar1,&DAT_00c81844,"3s2bwbd116b",lVar1 + 1,lVar1 + 0xe4);
    return uVar2;
  }
  return 0xfffffff3;
}


// ===== 001c3c50 nvswitch_bbx_add_sxid_lr10 =====

undefined8 nvswitch_bbx_add_sxid_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001c3c60 nvswitch_bbx_unload_lr10 =====

undefined8 nvswitch_bbx_unload_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001c3c70 nvswitch_bbx_load_lr10 =====

undefined8 nvswitch_bbx_load_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001c3c80 nvswitch_bbx_get_sxid_lr10 =====

undefined8 nvswitch_bbx_get_sxid_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001c3c90 nvswitch_bbx_get_data_lr10 =====

undefined8 nvswitch_bbx_get_data_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001c3c9a _nvswitch_service_nxbar_tile_lr10.cold =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_service_nxbar_tile_lr10_cold(void)

{
  code *pcVar1;
  undefined4 uVar2;
  long lVar3;
  long unaff_RBX;
  long unaff_RBP;
  undefined4 *puVar4;
  code *in_R9;
  
  puVar4 = (undefined4 *)(unaff_RBP + -0x40);
  for (lVar3 = 8; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  uVar2 = (*in_R9)();
  *(undefined4 *)(unaff_RBP + -0x40) = uVar2;
  uVar2 = (**(code **)(unaff_RBX + 0x920))();
  *(undefined4 *)(unaff_RBP + -0x34) = uVar2;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001c3cf0 _nvswitch_service_nxbar_tile_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _nvswitch_service_nxbar_tile_lr10(long *param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  char *pcVar6;
  undefined8 *puVar7;
  uint uVar8;
  uint local_4c;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  pcVar1 = (code *)param_1[0x124];
  if ((int)param_1[0x3f1] != 6) {
    lVar5 = 8;
    puVar7 = &local_48;
    while( true ) {
      if (lVar5 == 0) break;
      lVar5 = lVar5 + -1;
      *(undefined4 *)puVar7 = 0;
      puVar7 = (undefined8 *)((long)puVar7 + 4);
    }
    uVar2 = (*pcVar1)(param_1,0xd,0,param_2,100);
    local_48 = CONCAT44(local_48._4_4_,uVar2);
    uVar2 = (*(code *)param_1[0x124])(param_1,0xd,0,param_2,0x6c);
    local_40 = CONCAT44(uVar2,(uint)local_40);
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  lVar5 = param_1[0x3f2];
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  uVar2 = (*pcVar1)(param_1,0xd,0,param_2,100);
  local_48 = CONCAT44(local_48._4_4_,uVar2);
  uVar2 = (*(code *)param_1[0x124])(param_1,0xd,0,param_2,0x6c);
  local_48 = CONCAT44(*(uint *)(&DAT_00009ae4 + lVar5),(uint)local_48);
  uVar8 = *(uint *)(&DAT_00009ae4 + lVar5) & (uint)local_48;
  if (uVar8 == 0) {
    uVar4 = 0xfffffffd;
  }
  else {
    local_4c = uVar8;
    local_40._4_4_ = uVar2;
    uVar2 = (*(code *)param_1[0x124])(param_1,0xd,0,param_2,0x70);
    local_40 = CONCAT44(local_40._4_4_,uVar2);
    if ((uVar8 & 1) != 0) {
      iVar3 = nvswitch_translate_hw_error(0x59d9);
      if (iVar3 == 1) {
        nvswitch_assert_log();
      }
      lVar5 = *param_1;
      pcVar6 = " (First)";
      if ((local_40 & 1) == 0) {
        pcVar6 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar5 + 0x40),*(undefined1 *)(lVar5 + 0x44),
                        *(undefined1 *)(lVar5 + 0x45),*(undefined1 *)(lVar5 + 0x46),0x59d9,param_2,
                        "ingress SRC-VC buffer overflow",pcVar6);
      pcVar6 = " (First)";
      if ((local_40 & 1) == 0) {
        pcVar6 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x59d9,"Fatal, Link %02d %s%s\n",param_2,
                 "ingress SRC-VC buffer overflow",pcVar6);
      pcVar6 = " (First)";
      if ((local_40 & 1) == 0) {
        pcVar6 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x59d9,"Fatal, Link %02d %s%s\n",param_2,"ingress SRC-VC buffer overflow",
                 pcVar6);
      nvswitch_inforom_bbx_add_sxid(param_1,0x59d9,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x59d9,param_2,0,1,1,0,&local_48,0x20,0x10c2,
                 "\"ingress SRC-VC buffer overflow\"");
      nvswitch_set_fatal_error(param_1,1,param_2);
      nvswitch_lib_notify_client_events(param_1,0);
      local_4c = local_4c & 0xfffffffe;
    }
    if ((uVar8 & 2) != 0) {
      iVar3 = nvswitch_translate_hw_error(0x59da);
      if (iVar3 == 1) {
        nvswitch_assert_log();
      }
      lVar5 = *param_1;
      pcVar6 = " (First)";
      if ((local_40 & 2) == 0) {
        pcVar6 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar5 + 0x40),*(undefined1 *)(lVar5 + 0x44),
                        *(undefined1 *)(lVar5 + 0x45),*(undefined1 *)(lVar5 + 0x46),0x59da,param_2,
                        "ingress SRC-VC buffer underflow",pcVar6);
      pcVar6 = " (First)";
      if ((local_40 & 2) == 0) {
        pcVar6 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x59da,"Fatal, Link %02d %s%s\n",param_2,
                 "ingress SRC-VC buffer underflow",pcVar6);
      pcVar6 = " (First)";
      if ((local_40 & 2) == 0) {
        pcVar6 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x59da,"Fatal, Link %02d %s%s\n",param_2,"ingress SRC-VC buffer underflow",
                 pcVar6);
      nvswitch_inforom_bbx_add_sxid(param_1,0x59da,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x59da,param_2,0,1,1,0,&local_48,0x20,0x10c9,
                 "\"ingress SRC-VC buffer underflow\"");
      nvswitch_set_fatal_error(param_1,1,param_2);
      nvswitch_lib_notify_client_events(param_1,0);
      local_4c = local_4c & 0xfffffffd;
    }
    if ((uVar8 & 4) != 0) {
      iVar3 = nvswitch_translate_hw_error(0x59db);
      if (iVar3 == 1) {
        nvswitch_assert_log();
      }
      lVar5 = *param_1;
      pcVar6 = " (First)";
      if ((local_40 & 4) == 0) {
        pcVar6 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar5 + 0x40),*(undefined1 *)(lVar5 + 0x44),
                        *(undefined1 *)(lVar5 + 0x45),*(undefined1 *)(lVar5 + 0x46),0x59db,param_2,
                        "egress DST-VC credit overflow",pcVar6);
      pcVar6 = " (First)";
      if ((local_40 & 4) == 0) {
        pcVar6 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x59db,"Fatal, Link %02d %s%s\n",param_2,"egress DST-VC credit overflow"
                 ,pcVar6);
      pcVar6 = " (First)";
      if ((local_40 & 4) == 0) {
        pcVar6 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x59db,"Fatal, Link %02d %s%s\n",param_2,"egress DST-VC credit overflow",
                 pcVar6);
      nvswitch_inforom_bbx_add_sxid(param_1,0x59db,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x59db,param_2,0,1,1,0,&local_48,0x20,0x10d0,
                 "\"egress DST-VC credit overflow\"");
      nvswitch_set_fatal_error(param_1,1,param_2);
      nvswitch_lib_notify_client_events(param_1,0);
      local_4c = local_4c & 0xfffffffb;
    }
    if ((uVar8 & 8) != 0) {
      iVar3 = nvswitch_translate_hw_error(0x59dc);
      if (iVar3 == 1) {
        nvswitch_assert_log();
      }
      lVar5 = *param_1;
      pcVar6 = " (First)";
      if ((local_40 & 8) == 0) {
        pcVar6 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar5 + 0x40),*(undefined1 *)(lVar5 + 0x44),
                        *(undefined1 *)(lVar5 + 0x45),*(undefined1 *)(lVar5 + 0x46),0x59dc,param_2,
                        "egress DST-VC credit underflow",pcVar6);
      pcVar6 = " (First)";
      if ((local_40 & 8) == 0) {
        pcVar6 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x59dc,"Fatal, Link %02d %s%s\n",param_2,
                 "egress DST-VC credit underflow",pcVar6);
      pcVar6 = " (First)";
      if ((local_40 & 8) == 0) {
        pcVar6 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x59dc,"Fatal, Link %02d %s%s\n",param_2,"egress DST-VC credit underflow",
                 pcVar6);
      nvswitch_inforom_bbx_add_sxid(param_1,0x59dc,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x59dc,param_2,0,1,1,0,&local_48,0x20,0x10d7,
                 "\"egress DST-VC credit underflow\"");
      nvswitch_set_fatal_error(param_1,1,param_2);
      nvswitch_lib_notify_client_events(param_1,0);
      local_4c = local_4c & 0xfffffff7;
    }
    if ((uVar8 & 0x10) != 0) {
      iVar3 = nvswitch_translate_hw_error(0x59dd);
      if (iVar3 == 1) {
        nvswitch_assert_log();
      }
      lVar5 = *param_1;
      pcVar6 = " (First)";
      if ((local_40 & 0x10) == 0) {
        pcVar6 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar5 + 0x40),*(undefined1 *)(lVar5 + 0x44),
                        *(undefined1 *)(lVar5 + 0x45),*(undefined1 *)(lVar5 + 0x46),0x59dd,param_2,
                        "ingress packet burst error",pcVar6);
      pcVar6 = " (First)";
      if ((local_40 & 0x10) == 0) {
        pcVar6 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x59dd,"Fatal, Link %02d %s%s\n",param_2,"ingress packet burst error",
                 pcVar6);
      pcVar6 = " (First)";
      if ((local_40 & 0x10) == 0) {
        pcVar6 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x59dd,"Fatal, Link %02d %s%s\n",param_2,"ingress packet burst error",
                 pcVar6);
      nvswitch_inforom_bbx_add_sxid(param_1,0x59dd,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x59dd,param_2,0,1,1,0,&local_48,0x20,0x10de,
                 "\"ingress packet burst error\"");
      nvswitch_set_fatal_error(param_1,1,param_2);
      nvswitch_lib_notify_client_events(param_1,0);
      local_4c = local_4c & 0xffffffef;
    }
    if ((uVar8 & 0x20) != 0) {
      iVar3 = nvswitch_translate_hw_error(0x59de);
      if (iVar3 == 1) {
        nvswitch_assert_log();
      }
      lVar5 = *param_1;
      pcVar6 = " (First)";
      if ((local_40 & 0x20) == 0) {
        pcVar6 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar5 + 0x40),*(undefined1 *)(lVar5 + 0x44),
                        *(undefined1 *)(lVar5 + 0x45),*(undefined1 *)(lVar5 + 0x46),0x59de,param_2,
                        "ingress packet sticky error",pcVar6);
      pcVar6 = " (First)";
      if ((local_40 & 0x20) == 0) {
        pcVar6 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x59de,"Fatal, Link %02d %s%s\n",param_2,"ingress packet sticky error",
                 pcVar6);
      pcVar6 = " (First)";
      if ((local_40 & 0x20) == 0) {
        pcVar6 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x59de,"Fatal, Link %02d %s%s\n",param_2,"ingress packet sticky error",
                 pcVar6);
      nvswitch_inforom_bbx_add_sxid(param_1,0x59de,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x59de,param_2,0,1,1,0,&local_48,0x20,0x10e5,
                 "\"ingress packet sticky error\"");
      nvswitch_set_fatal_error(param_1,1,param_2);
      nvswitch_lib_notify_client_events(param_1,0);
      local_4c = local_4c & 0xffffffdf;
    }
    if ((uVar8 & 0x40) != 0) {
      iVar3 = nvswitch_translate_hw_error(0x59df);
      if (iVar3 == 1) {
        nvswitch_assert_log();
      }
      lVar5 = *param_1;
      pcVar6 = " (First)";
      if ((local_40 & 0x40) == 0) {
        pcVar6 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar5 + 0x40),*(undefined1 *)(lVar5 + 0x44),
                        *(undefined1 *)(lVar5 + 0x45),*(undefined1 *)(lVar5 + 0x46),0x59df,param_2,
                        "possible bubbles at ingress",pcVar6);
      pcVar6 = " (First)";
      if ((local_40 & 0x40) == 0) {
        pcVar6 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x59df,"Fatal, Link %02d %s%s\n",param_2,"possible bubbles at ingress",
                 pcVar6);
      pcVar6 = " (First)";
      if ((local_40 & 0x40) == 0) {
        pcVar6 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x59df,"Fatal, Link %02d %s%s\n",param_2,"possible bubbles at ingress",
                 pcVar6);
      nvswitch_inforom_bbx_add_sxid(param_1,0x59df,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x59df,param_2,0,1,1,0,&local_48,0x20,0x10ec,
                 "\"possible bubbles at ingress\"");
      nvswitch_set_fatal_error(param_1,1,param_2);
      nvswitch_lib_notify_client_events(param_1,0);
      local_4c = local_4c & 0xffffffbf;
    }
    if ((uVar8 & 0x80) != 0) {
      iVar3 = nvswitch_translate_hw_error(0x59e0);
      if (iVar3 == 1) {
        nvswitch_assert_log();
      }
      lVar5 = *param_1;
      pcVar6 = " (First)";
      if ((local_40 & 0x80) == 0) {
        pcVar6 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar5 + 0x40),*(undefined1 *)(lVar5 + 0x44),
                        *(undefined1 *)(lVar5 + 0x45),*(undefined1 *)(lVar5 + 0x46),0x59e0,param_2,
                        "ingress packet invalid dst error",pcVar6);
      pcVar6 = " (First)";
      if ((local_40 & 0x80) == 0) {
        pcVar6 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x59e0,"Fatal, Link %02d %s%s\n",param_2,
                 "ingress packet invalid dst error",pcVar6);
      pcVar6 = " (First)";
      if ((local_40 & 0x80) == 0) {
        pcVar6 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x59e0,"Fatal, Link %02d %s%s\n",param_2,"ingress packet invalid dst error"
                 ,pcVar6);
      nvswitch_inforom_bbx_add_sxid(param_1,0x59e0,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x59e0,param_2,0,1,1,0,&local_48,0x20,0x10f3,
                 "\"ingress packet invalid dst error\"");
      nvswitch_set_fatal_error(param_1,1,param_2);
      nvswitch_lib_notify_client_events(param_1,0);
      local_4c = local_4c & 0xffffff7f;
    }
    if ((uVar8 & 0x100) != 0) {
      iVar3 = nvswitch_translate_hw_error(0x59e1);
      if (iVar3 == 1) {
        nvswitch_assert_log();
      }
      lVar5 = *param_1;
      pcVar6 = " (First)";
      if ((local_40 & 0x100) == 0) {
        pcVar6 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar5 + 0x40),*(undefined1 *)(lVar5 + 0x44),
                        *(undefined1 *)(lVar5 + 0x45),*(undefined1 *)(lVar5 + 0x46),0x59e1,param_2,
                        "ingress packet parity error",pcVar6);
      pcVar6 = " (First)";
      if ((local_40 & 0x100) == 0) {
        pcVar6 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x59e1,"Fatal, Link %02d %s%s\n",param_2,"ingress packet parity error",
                 pcVar6);
      pcVar6 = " (First)";
      if ((local_40 & 0x100) == 0) {
        pcVar6 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x59e1,"Fatal, Link %02d %s%s\n",param_2,"ingress packet parity error",
                 pcVar6);
      nvswitch_inforom_bbx_add_sxid(param_1,0x59e1,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x59e1,param_2,0,1,1,0,&local_48,0x20,0x10fa,
                 "\"ingress packet parity error\"");
      nvswitch_set_fatal_error(param_1,1,param_2);
      nvswitch_lib_notify_client_events(param_1,0);
      local_4c = local_4c & 0xfffffeff;
    }
    if (((uint)local_40 & local_48._4_4_) != 0) {
      (*(code *)param_1[0x125])(param_1,0xd,0,param_2,0x70);
    }
    if (local_4c != 0) {
      iVar3 = nvswitch_translate_hw_error(0x2713);
      if (iVar3 == 1) {
        nvswitch_assert_log();
      }
      lVar5 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                        ,param_1 + 1,*(undefined4 *)(lVar5 + 0x40),*(undefined1 *)(lVar5 + 0x44),
                        *(undefined1 *)(lVar5 + 0x45),*(undefined1 *)(lVar5 + 0x46),0x2713,
                        "_nvswitch_service_nxbar_tile_lr10",0x1104);
      nvswitch_os_report_error
                (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_nxbar_tile_lr10",0x1104);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_nxbar_tile_lr10",0x1104);
      nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_4c,4,0x1104,&DAT_00c81851);
    }
    (*(code *)param_1[0x125])(param_1,0xd,0,param_2,0x6c,local_40._4_4_ ^ uVar8);
    (*(code *)param_1[0x125])(param_1,0xd,0,param_2,100,uVar8);
    if (local_4c == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0xfffffff6;
    }
  }
  return uVar4;
}


// ===== 001c4bb0 _nvswitch_service_pbus_lr10 =====

uint _nvswitch_service_pbus_lr10(long *param_1)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  uint local_64;
  ulong local_60;
  ulong local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  uVar4 = nvswitch_reg_read_32(param_1,0x1100);
  uVar5 = nvswitch_reg_read_32(param_1,0x1140);
  uVar4 = uVar4 & uVar5;
  if (uVar4 == 0) {
    uVar4 = 0xfffffffd;
  }
  else {
    local_64 = uVar4;
    if ((uVar4 & 0xe) != 0) {
      nvswitch_reg_write_32(param_1,0x1100,8);
      uVar5 = nvswitch_reg_read_32(param_1,0x1984);
      uVar6 = nvswitch_reg_read_32(param_1,0x1988);
      uVar7 = nvswitch_reg_read_32(param_1,0x1990);
      uVar8 = nvswitch_reg_read_32(param_1,0x198c);
      local_60 = CONCAT44(uVar6,uVar5) & 0xffffffff03fffffc;
      local_48 = CONCAT44(uVar6,uVar5);
      local_40 = CONCAT44(uVar8,uVar7);
      local_58 = CONCAT44(uVar5,uVar5 >> 1) & 0x100000001;
      local_50 = CONCAT44(uVar8,uVar7) & 0xffffffff0000000f;
      iVar9 = nvswitch_translate_hw_error(0x2712);
      if (iVar9 == 1) {
        nvswitch_assert_log();
      }
      lVar3 = *param_1;
      plVar1 = param_1 + 1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, %s, instance=%d, chiplet=%d\n"
                        ,plVar1,*(undefined4 *)(lVar3 + 0x40),*(undefined1 *)(lVar3 + 0x44),
                        *(undefined1 *)(lVar3 + 0x45),*(undefined1 *)(lVar3 + 0x46),0x2712,
                        "PBUS PRI SQUASH error",0,0);
      nvswitch_os_report_error
                (param_1[3],0x2712,"Non-fatal, %s, instance=%d, chiplet=%d\n",
                 "PBUS PRI SQUASH error",0,0);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2712,"Non-fatal, %s, instance=%d, chiplet=%d\n","PBUS PRI SQUASH error",0
                 ,0);
      nvswitch_inforom_bbx_add_sxid(param_1,0x2712,0,0,0);
      plVar2 = param_1 + 0x24;
      nvswitch_record_error
                (param_1,plVar2,0x2712,0,0,1,0,0,&local_60,0x28,0x42f,"\"PBUS PRI SQUASH error\"");
      nvswitch_lib_notify_client_events(param_1,1);
      iVar9 = nvswitch_translate_hw_error(0x2712);
      if (iVar9 == 1) {
        nvswitch_assert_log();
      }
      lVar3 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, %s, instance=%d, chiplet=%d\n"
                        ,plVar1,*(undefined4 *)(lVar3 + 0x40),*(undefined1 *)(lVar3 + 0x44),
                        *(undefined1 *)(lVar3 + 0x45),*(undefined1 *)(lVar3 + 0x46),0x2712,
                        "PBUS PRI FECSERR error",1,0);
      nvswitch_os_report_error
                (param_1[3],0x2712,"Non-fatal, %s, instance=%d, chiplet=%d\n",
                 "PBUS PRI FECSERR error",1,0);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2712,"Non-fatal, %s, instance=%d, chiplet=%d\n","PBUS PRI FECSERR error",
                 1,0);
      nvswitch_inforom_bbx_add_sxid(param_1,0x2712,0,0,0);
      nvswitch_record_error
                (param_1,plVar2,0x2712,1,0,1,0,0,&local_60,0x28,0x436,"\"PBUS PRI FECSERR error\"");
      nvswitch_lib_notify_client_events(param_1,1);
      iVar9 = nvswitch_translate_hw_error(0x2712);
      if (iVar9 == 1) {
        nvswitch_assert_log();
      }
      lVar3 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, %s, instance=%d, chiplet=%d\n"
                        ,plVar1,*(undefined4 *)(lVar3 + 0x40),*(undefined1 *)(lVar3 + 0x44),
                        *(undefined1 *)(lVar3 + 0x45),*(undefined1 *)(lVar3 + 0x46),0x2712,
                        "PBUS PRI TIMEOUT error",2,0);
      nvswitch_os_report_error
                (param_1[3],0x2712,"Non-fatal, %s, instance=%d, chiplet=%d\n",
                 "PBUS PRI TIMEOUT error",2,0);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2712,"Non-fatal, %s, instance=%d, chiplet=%d\n","PBUS PRI TIMEOUT error",
                 2,0);
      nvswitch_inforom_bbx_add_sxid(param_1,0x2712,0,0,0);
      nvswitch_record_error
                (param_1,plVar2,0x2712,2,0,1,0,0,&local_60,0x28,0x43d,"\"PBUS PRI TIMEOUT error\"");
      nvswitch_lib_notify_client_events(param_1,1);
      nvswitch_reg_write_32(param_1,0x1984,uVar5 & 0xfffffffe);
      local_64 = local_64 & 0xfffffff1;
    }
    if ((uVar4 & 0x4000000) != 0) {
      local_64 = local_64 & 0xfbffffff;
    }
    nvswitch_reg_write_32(param_1,0x1100,uVar4);
    uVar4 = 0;
    if (local_64 != 0) {
      iVar9 = nvswitch_translate_hw_error(0x2713);
      if (iVar9 == 1) {
        nvswitch_assert_log();
      }
      lVar3 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                        ,param_1 + 1,*(undefined4 *)(lVar3 + 0x40),*(undefined1 *)(lVar3 + 0x44),
                        *(undefined1 *)(lVar3 + 0x45),*(undefined1 *)(lVar3 + 0x46),0x2713,
                        "_nvswitch_service_pbus_lr10",0x453);
      nvswitch_os_report_error
                (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_pbus_lr10",0x453);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_pbus_lr10",0x453);
      nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
      nvswitch_record_error(param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_64,4,0x453,&DAT_00c81851)
      ;
      return -(uint)(local_64 != 0) & 0xfffffff6;
    }
  }
  return uVar4;
}


// ===== 001c5170 _nvswitch_service_nvldl_nonfatal_link_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */
/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */
/* WARNING: Type propagation algorithm not settling */

undefined8 _nvswitch_service_nvldl_nonfatal_link_lr10(long *param_1,ulong param_2)

{
  code *pcVar1;
  long lVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined8 uVar8;
  char *pcVar9;
  ulong uVar10;
  uint local_4c;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  uVar10 = param_2 & 0xffffffff;
  pcVar1 = (code *)param_1[0x122];
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_2,0xb);
  iVar7 = (*pcVar1)(param_1,0xb,0,uVar4);
  if ((iVar7 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,uVar10), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar1 = (code *)param_1[0x124];
  uVar4 = nvswitch_get_link_eng_inst(param_1,uVar10,0xb);
  uVar4 = (*pcVar1)(param_1,0xb,0,uVar4,0x50);
  local_48 = CONCAT44(local_48._4_4_,uVar4);
  pcVar1 = (code *)param_1[0x122];
  uVar4 = nvswitch_get_link_eng_inst(param_1,uVar10,0xb);
  iVar7 = (*pcVar1)(param_1,0xb,0,uVar4);
  if ((iVar7 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_2 & 0xffffffff), cVar3 == '\0')
     ) {
    nvswitch_assert_log();
  }
  pcVar1 = (code *)param_1[0x124];
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_2 & 0xffffffff,0xb);
  uVar5 = (*pcVar1)(param_1,0xb,0,uVar4,0x5c);
  local_40 = CONCAT44(uVar5,(undefined4)local_40);
  local_48 = CONCAT44(uVar5,(uint)local_48);
  uVar5 = uVar5 & (uint)local_48;
  if (uVar5 == 0) {
    uVar8 = 0xfffffffd;
  }
  else {
    local_4c = uVar5;
    if ((uVar5 & 1) != 0) {
      iVar7 = nvswitch_translate_hw_error(0x4e21);
      if (iVar7 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar9 = "";
      if ((local_40 & 1) != 0) {
        pcVar9 = " (First)";
      }
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4e21,uVar10,
                        "TX Replay Error",pcVar9);
      pcVar9 = "";
      if ((local_40 & 1) != 0) {
        pcVar9 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4e21,"Non-fatal, Link %02d %s%s\n",param_2 & 0xffffffff,
                 "TX Replay Error",pcVar9);
      pcVar9 = "";
      if ((local_40 & 1) != 0) {
        pcVar9 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4e21,"Non-fatal, Link %02d %s%s\n",uVar10,"TX Replay Error",pcVar9);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4e21,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x24,0x4e21,uVar10,0,1,0,0,&local_48,0x20,0xd2f,
                 "\"TX Replay Error\"");
      nvswitch_lib_notify_client_events(param_1,1);
      local_4c = local_4c & 0xfffffffe;
    }
    if ((uVar5 & 2) != 0) {
      iVar7 = nvswitch_translate_hw_error(0x4e22);
      if (iVar7 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar9 = "";
      if ((local_40 & 2) != 0) {
        pcVar9 = " (First)";
      }
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4e22,uVar10,
                        "TX Recovery Short",pcVar9);
      pcVar9 = "";
      if ((local_40 & 2) != 0) {
        pcVar9 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4e22,"Non-fatal, Link %02d %s%s\n",uVar10,"TX Recovery Short",pcVar9);
      pcVar9 = "";
      if ((local_40 & 2) != 0) {
        pcVar9 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4e22,"Non-fatal, Link %02d %s%s\n",uVar10,"TX Recovery Short",pcVar9);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4e22,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x24,0x4e22,uVar10,0,1,0,0,&local_48,0x20,0xd36,
                 "\"TX Recovery Short\"");
      nvswitch_lib_notify_client_events(param_1,1);
      local_4c = local_4c & 0xfffffffd;
    }
    if ((uVar5 & 0x200000) != 0) {
      iVar7 = nvswitch_translate_hw_error(0x4e29);
      if (iVar7 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar9 = "";
      if ((local_40 & 0x200000) != 0) {
        pcVar9 = " (First)";
      }
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4e29,uVar10,
                        "RX Short Error Rate",pcVar9);
      pcVar9 = "";
      if ((local_40 & 0x200000) != 0) {
        pcVar9 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4e29,"Non-fatal, Link %02d %s%s\n",uVar10,"RX Short Error Rate",pcVar9
                );
      pcVar9 = "";
      if ((local_40 & 0x200000) != 0) {
        pcVar9 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4e29,"Non-fatal, Link %02d %s%s\n",uVar10,"RX Short Error Rate",pcVar9);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4e29,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x24,0x4e29,uVar10,0,1,0,0,&local_48,0x20,0xd3d,
                 "\"RX Short Error Rate\"");
      nvswitch_lib_notify_client_events(param_1,1);
      local_4c = local_4c & 0xffdfffff;
    }
    if ((uVar5 & 0x400000) != 0) {
      iVar7 = nvswitch_translate_hw_error(0x4e2a);
      if (iVar7 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar9 = "";
      if ((local_40 & 0x400000) != 0) {
        pcVar9 = " (First)";
      }
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4e2a,uVar10,
                        "RX Long Error Rate",pcVar9);
      pcVar9 = "";
      if ((local_40 & 0x400000) != 0) {
        pcVar9 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4e2a,"Non-fatal, Link %02d %s%s\n",uVar10,"RX Long Error Rate",pcVar9)
      ;
      pcVar9 = "";
      if ((local_40 & 0x400000) != 0) {
        pcVar9 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4e2a,"Non-fatal, Link %02d %s%s\n",uVar10,"RX Long Error Rate",pcVar9);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4e2a,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x24,0x4e2a,uVar10,0,1,0,0,&local_48,0x20,0xd44,
                 "\"RX Long Error Rate\"");
      nvswitch_lib_notify_client_events(param_1,1);
      local_4c = local_4c & 0xffbfffff;
    }
    if ((uVar5 & 0x800000) != 0) {
      iVar7 = nvswitch_translate_hw_error(0x4e2b);
      if (iVar7 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar9 = "";
      if ((local_40 & 0x800000) != 0) {
        pcVar9 = " (First)";
      }
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4e2b,uVar10,
                        "RX ILA Trigger",pcVar9);
      pcVar9 = "";
      if ((local_40 & 0x800000) != 0) {
        pcVar9 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4e2b,"Non-fatal, Link %02d %s%s\n",uVar10,"RX ILA Trigger",pcVar9);
      pcVar9 = "";
      if ((local_40 & 0x800000) != 0) {
        pcVar9 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4e2b,"Non-fatal, Link %02d %s%s\n",uVar10,"RX ILA Trigger",pcVar9);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4e2b,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x24,0x4e2b,uVar10,0,1,0,0,&local_48,0x20,0xd4b,
                 "\"RX ILA Trigger\"");
      nvswitch_lib_notify_client_events(param_1,1);
      local_4c = local_4c & 0xff7fffff;
    }
    if ((uVar5 & 0x1000000) != 0) {
      iVar7 = nvswitch_translate_hw_error(0x4e2c);
      if (iVar7 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar9 = "";
      if ((local_40 & 0x1000000) != 0) {
        pcVar9 = " (First)";
      }
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4e2c,uVar10,
                        "RX CRC Counter",pcVar9);
      pcVar9 = "";
      if ((local_40 & 0x1000000) != 0) {
        pcVar9 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4e2c,"Non-fatal, Link %02d %s%s\n",uVar10,"RX CRC Counter",pcVar9);
      pcVar9 = "";
      if ((local_40 & 0x1000000) != 0) {
        pcVar9 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4e2c,"Non-fatal, Link %02d %s%s\n",uVar10,"RX CRC Counter",pcVar9);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4e2c,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x24,0x4e2c,uVar10,0,1,0,0,&local_48,0x20,0xd52,
                 "\"RX CRC Counter\"");
      nvswitch_lib_notify_client_events(param_1,1);
      local_4c = local_4c & 0xfeffffff;
      pcVar1 = (code *)param_1[0x122];
      local_40 = local_40 & 0xfeffffffffffffff;
      uVar4 = nvswitch_get_link_eng_inst(param_1,uVar10,0xb);
      iVar7 = (*pcVar1)(param_1,0xb,0,uVar4);
      if ((iVar7 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,uVar10), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      uVar4 = local_40._4_4_;
      pcVar1 = (code *)param_1[0x125];
      uVar6 = nvswitch_get_link_eng_inst(param_1,uVar10,0xb);
      (*pcVar1)(param_1,0xb,0,uVar6,0x5c,uVar4);
    }
    if (local_4c != 0) {
      iVar7 = nvswitch_translate_hw_error(0x2713);
      if (iVar7 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x2713,
                        "_nvswitch_service_nvldl_nonfatal_link_lr10",0xd5f);
      nvswitch_os_report_error
                (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_nvldl_nonfatal_link_lr10",0xd5f);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_nvldl_nonfatal_link_lr10",0xd5f);
      nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
      nvswitch_record_error(param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_4c,4,0xd5f,&DAT_00c81851)
      ;
    }
    pcVar1 = (code *)param_1[0x122];
    uVar4 = nvswitch_get_link_eng_inst(param_1,uVar10,0xb);
    iVar7 = (*pcVar1)(param_1,0xb,0,uVar4);
    if ((iVar7 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,uVar10), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar1 = (code *)param_1[0x125];
    uVar4 = nvswitch_get_link_eng_inst(param_1,uVar10,0xb);
    (*pcVar1)(param_1,0xb,0,uVar4,0x50,uVar5);
    if (local_4c == 0) {
      uVar8 = 0;
    }
    else {
      uVar8 = 0xfffffff6;
    }
  }
  return uVar8;
}


// ===== 001c5cf0 _nvswitch_service_nvltlc_tx_sys_fatal_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Type propagation algorithm not settling */

undefined8 _nvswitch_service_nvltlc_tx_sys_fatal_lr10(long *param_1,undefined1 param_2,uint param_3)

{
  code *pcVar1;
  long lVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  char *pcVar8;
  uint uVar9;
  uint local_68;
  undefined8 local_64;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  pcVar1 = (code *)param_1[0x122];
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_64 = 0;
  local_5c = 0;
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
  iVar6 = (*pcVar1)(param_1,10,0,uVar4);
  if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar1 = (code *)param_1[0x124];
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
  uVar4 = (*pcVar1)(param_1,10,0,uVar4,0x280);
  local_58 = CONCAT44(local_58._4_4_,uVar4);
  pcVar1 = (code *)param_1[0x122];
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
  iVar6 = (*pcVar1)(param_1,10,0,uVar4);
  if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar1 = (code *)param_1[0x124];
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
  uVar5 = (*pcVar1)(param_1,10,0,uVar4,0x288);
  local_50 = CONCAT44(uVar5,(uint)local_50);
  local_58 = CONCAT44(uVar5,(uint)local_58);
  uVar5 = uVar5 & (uint)local_58;
  local_64 = CONCAT62(local_64._2_6_,CONCAT11((char)param_3,param_2)) & 0xffffffffffff03ff;
  if (uVar5 != 0) {
    pcVar1 = (code *)param_1[0x122];
    local_68 = uVar5;
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    iVar6 = (*pcVar1)(param_1,10,0,uVar4);
    if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar1 = (code *)param_1[0x124];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    uVar4 = (*pcVar1)(param_1,10,0,uVar4,0x29c);
    local_50 = CONCAT44(local_50._4_4_,uVar4);
    pcVar1 = (code *)param_1[0x122];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    iVar6 = (*pcVar1)(param_1,10,0,uVar4);
    if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar1 = (code *)param_1[0x124];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    uVar9 = (*pcVar1)(param_1,10,0,uVar4,0x298);
    if ((uVar5 & 1) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a66);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = " (First)";
      if ((local_50 & 1) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a66,param_3,
                        "NCISOC Parity Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 1) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a66,"Fatal, Link %02d %s%s\n",param_3,"NCISOC Parity Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 1) == 0) {
        pcVar8 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a66,"Fatal, Link %02d %s%s\n",param_3,"NCISOC Parity Error",pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a66,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4a66,param_3,0,1,1,0,&local_58,0x20,0x12bd,
                 "\"NCISOC Parity Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_68 = local_68 & 0xfffffffe;
      if ((uVar9 & 1) == 0) {
        local_64 = CONCAT44(0x2b,(undefined4)local_64);
        nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
      }
    }
    if ((uVar5 & 0x100) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a67);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = " (First)";
      if ((local_50 & 0x100) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a67,param_3,
                        "NCISOC HDR ECC DBE Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x100) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a67,"Fatal, Link %02d %s%s\n",param_3,"NCISOC HDR ECC DBE Error",
                 pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x100) == 0) {
        pcVar8 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a67,"Fatal, Link %02d %s%s\n",param_3,"NCISOC HDR ECC DBE Error",pcVar8)
      ;
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a67,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4a67,param_3,0,1,1,0,&local_58,0x20,0x12ca,
                 "\"NCISOC HDR ECC DBE Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_68 = local_68 & 0xfffffeff;
      if ((uVar9 & 0x100) == 0) {
        local_64 = CONCAT44(0x2a,(undefined4)local_64);
        nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
      }
    }
    if ((uVar5 & 0x200) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a68);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = "";
      if ((local_50 & 0x200) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a68,param_3,
                        "NCISOC DAT ECC DBE Error",pcVar8);
      pcVar8 = "";
      if ((local_50 & 0x200) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a68,"Fatal, Link %02d %s%s\n",param_3,"NCISOC DAT ECC DBE Error",
                 pcVar8);
      pcVar8 = "";
      if ((local_50 & 0x200) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a68,"Fatal, Link %02d %s%s\n",param_3,"NCISOC DAT ECC DBE Error",pcVar8)
      ;
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a68,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4a68,param_3,0,1,1,0,&local_58,0x20,0x12d7,
                 "\"NCISOC DAT ECC DBE Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_68 = local_68 & 0xfffffdff;
    }
    if ((uVar5 & 0x400) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a69);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = "";
      if ((local_50 & 0x400) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a69,param_3,
                        "NCISOC ECC Limit Error",pcVar8);
      pcVar8 = "";
      if ((local_50 & 0x400) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a69,"Fatal, Link %02d %s%s\n",param_3,"NCISOC ECC Limit Error",pcVar8
                );
      pcVar8 = "";
      if ((local_50 & 0x400) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a69,"Fatal, Link %02d %s%s\n",param_3,"NCISOC ECC Limit Error",pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a69,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4a69,param_3,0,1,1,0,&local_58,0x20,0x12de,
                 "\"NCISOC ECC Limit Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_68 = local_68 & 0xfffffbff;
    }
    if ((uVar5 & 0x800000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a41);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = "";
      if ((local_50 & 0x800000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a41,param_3,
                        "Poison Error",pcVar8);
      pcVar8 = "";
      if ((local_50 & 0x800000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a41,"Fatal, Link %02d %s%s\n",param_3,"Poison Error",pcVar8);
      pcVar8 = "";
      if ((local_50 & 0x800000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a41,"Fatal, Link %02d %s%s\n",param_3,"Poison Error",pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a41,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4a41,param_3,0,1,1,0,&local_58,0x20,0x12e5,
                 "\"Poison Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_68 = local_68 & 0xff7fffff;
    }
    if ((uVar5 & 0x1000000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a6a);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = "";
      if ((local_50 & 0x1000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a6a,param_3,
                        "TX Response Status HW Error",pcVar8);
      pcVar8 = "";
      if ((local_50 & 0x1000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a6a,"Fatal, Link %02d %s%s\n",param_3,"TX Response Status HW Error",
                 pcVar8);
      pcVar8 = "";
      if ((local_50 & 0x1000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a6a,"Fatal, Link %02d %s%s\n",param_3,"TX Response Status HW Error",
                 pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a6a,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4a6a,param_3,0,1,1,0,&local_58,0x20,0x12ec,
                 "\"TX Response Status HW Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_68 = local_68 & 0xfeffffff;
    }
    if ((uVar5 & 0x2000000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a6b);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = "";
      if ((local_50 & 0x2000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a6b,param_3,
                        "TX Response Status UR Error",pcVar8);
      pcVar8 = "";
      if ((local_50 & 0x2000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a6b,"Fatal, Link %02d %s%s\n",param_3,"TX Response Status UR Error",
                 pcVar8);
      pcVar8 = "";
      if ((local_50 & 0x2000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a6b,"Fatal, Link %02d %s%s\n",param_3,"TX Response Status UR Error",
                 pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a6b,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4a6b,param_3,0,1,1,0,&local_58,0x20,0x12f3,
                 "\"TX Response Status UR Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_68 = local_68 & 0xfdffffff;
    }
    if ((uVar5 & 0x4000000) == 0) {
      local_58._4_4_ = (uint)((ulong)local_58 >> 0x20);
      uVar9 = local_58._4_4_ & (uint)local_50;
    }
    else {
      iVar6 = nvswitch_translate_hw_error(0x4a6c);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = "";
      if ((local_50 & 0x4000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a6c,param_3,
                        "TX Response Status PRIV Error",pcVar8);
      pcVar8 = "";
      if ((local_50 & 0x4000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a6c,"Fatal, Link %02d %s%s\n",param_3,"TX Response Status PRIV Error"
                 ,pcVar8);
      pcVar8 = "";
      if ((local_50 & 0x4000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a6c,"Fatal, Link %02d %s%s\n",param_3,"TX Response Status PRIV Error",
                 pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a6c,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4a6c,param_3,0,1,1,0,&local_58,0x20,0x12fa,
                 "\"TX Response Status PRIV Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_68 = local_68 & 0xfbffffff;
      uVar9 = local_58._4_4_ & (uint)local_50;
    }
    if (uVar9 != 0) {
      pcVar1 = (code *)param_1[0x122];
      uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
      iVar6 = (*pcVar1)(param_1,10,0,uVar4);
      if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar1 = (code *)param_1[0x125];
      uVar9 = (uint)local_50 & local_58._4_4_;
      uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
      (*pcVar1)(param_1,10,0,uVar4,0x29c,uVar9);
    }
    if (local_68 != 0) {
      iVar6 = nvswitch_translate_hw_error(0x2713);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x2713,
                        "_nvswitch_service_nvltlc_tx_sys_fatal_lr10",0x1304);
      nvswitch_os_report_error
                (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_nvltlc_tx_sys_fatal_lr10",0x1304);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_nvltlc_tx_sys_fatal_lr10",0x1304);
      nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_68,4,0x1304,&DAT_00c81851);
    }
    if ((char)param_1[(ulong)param_3 * 8 + 0x1ed] != '\0') {
      pcVar1 = (code *)param_1[0x122];
      uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
      iVar6 = (*pcVar1)(param_1,10,0,uVar4);
      if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar1 = (code *)param_1[0x125];
      uVar9 = local_50._4_4_ ^ uVar5;
      uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
      (*pcVar1)(param_1,10,0,uVar4,0x288,uVar9);
    }
    pcVar1 = (code *)param_1[0x122];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    iVar6 = (*pcVar1)(param_1,10,0,uVar4);
    if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar1 = (code *)param_1[0x125];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    (*pcVar1)(param_1,10,0,uVar4,0x280,uVar5);
    if (local_68 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = 0xfffffff6;
    }
    return uVar7;
  }
  return 0xfffffffd;
}


// ===== 001c6dc0 _nvswitch_service_nvltlc_rx_sys_fatal_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Type propagation algorithm not settling */

undefined8 _nvswitch_service_nvltlc_rx_sys_fatal_lr10(long *param_1,undefined1 param_2,uint param_3)

{
  code *pcVar1;
  long lVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  char *pcVar8;
  uint uVar9;
  uint local_68;
  undefined8 local_64;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  pcVar1 = (code *)param_1[0x122];
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_64 = 0;
  local_5c = 0;
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
  iVar6 = (*pcVar1)(param_1,10,0,uVar4);
  if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar1 = (code *)param_1[0x124];
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
  uVar4 = (*pcVar1)(param_1,10,0,uVar4,0xa80);
  local_58 = CONCAT44(local_58._4_4_,uVar4);
  pcVar1 = (code *)param_1[0x122];
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
  iVar6 = (*pcVar1)(param_1,10,0,uVar4);
  if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar1 = (code *)param_1[0x124];
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
  uVar5 = (*pcVar1)(param_1,10,0,uVar4,0xa88);
  local_50 = CONCAT44(uVar5,(uint)local_50);
  local_58 = CONCAT44(uVar5,(uint)local_58);
  uVar5 = uVar5 & (uint)local_58;
  local_64 = CONCAT62(local_64._2_6_,CONCAT11((char)param_3,param_2)) & 0xffffffffffff03ff;
  if (uVar5 != 0) {
    pcVar1 = (code *)param_1[0x122];
    local_68 = uVar5;
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    iVar6 = (*pcVar1)(param_1,10,0,uVar4);
    if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar1 = (code *)param_1[0x124];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    uVar4 = (*pcVar1)(param_1,10,0,uVar4,0xa9c);
    local_50 = CONCAT44(local_50._4_4_,uVar4);
    pcVar1 = (code *)param_1[0x122];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    iVar6 = (*pcVar1)(param_1,10,0,uVar4);
    if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar1 = (code *)param_1[0x124];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    uVar9 = (*pcVar1)(param_1,10,0,uVar4,0xa98);
    if ((uVar5 & 1) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a6d);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = " (First)";
      if ((local_50 & 1) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a6d,param_3,
                        "NCISOC Parity Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 1) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a6d,"Fatal, Link %02d %s%s\n",param_3,"NCISOC Parity Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 1) == 0) {
        pcVar8 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a6d,"Fatal, Link %02d %s%s\n",param_3,"NCISOC Parity Error",pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a6d,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4a6d,param_3,0,1,1,0,&local_58,0x20,0x133b,
                 "\"NCISOC Parity Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_68 = local_68 & 0xfffffffe;
    }
    if ((uVar5 & 2) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a6e);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = " (First)";
      if ((local_50 & 2) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a6e,param_3,
                        "HDR RAM ECC DBE Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 2) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a6e,"Fatal, Link %02d %s%s\n",param_3,"HDR RAM ECC DBE Error",pcVar8)
      ;
      pcVar8 = " (First)";
      if ((local_50 & 2) == 0) {
        pcVar8 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a6e,"Fatal, Link %02d %s%s\n",param_3,"HDR RAM ECC DBE Error",pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a6e,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4a6e,param_3,0,1,1,0,&local_58,0x20,0x1342,
                 "\"HDR RAM ECC DBE Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_68 = local_68 & 0xfffffffd;
      if ((uVar9 & 2) == 0) {
        local_64 = CONCAT44(0x45,(undefined4)local_64);
        nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
      }
    }
    if ((uVar5 & 4) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a6f);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = " (First)";
      if ((local_50 & 4) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a6f,param_3,
                        "HDR RAM ECC Limit Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 4) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a6f,"Fatal, Link %02d %s%s\n",param_3,"HDR RAM ECC Limit Error",
                 pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 4) == 0) {
        pcVar8 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a6f,"Fatal, Link %02d %s%s\n",param_3,"HDR RAM ECC Limit Error",pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a6f,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4a6f,param_3,0,1,1,0,&local_58,0x20,0x1350,
                 "\"HDR RAM ECC Limit Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_68 = local_68 & 0xfffffffb;
    }
    if ((uVar5 & 8) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a70);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = " (First)";
      if ((local_50 & 8) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a70,param_3,
                        "DAT0 RAM ECC DBE Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 8) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a70,"Fatal, Link %02d %s%s\n",param_3,"DAT0 RAM ECC DBE Error",pcVar8
                );
      pcVar8 = " (First)";
      if ((local_50 & 8) == 0) {
        pcVar8 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a70,"Fatal, Link %02d %s%s\n",param_3,"DAT0 RAM ECC DBE Error",pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a70,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4a70,param_3,0,1,1,0,&local_58,0x20,0x1357,
                 "\"DAT0 RAM ECC DBE Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_68 = local_68 & 0xfffffff7;
      if ((uVar9 & 8) == 0) {
        local_64 = CONCAT44(0x46,(undefined4)local_64);
        nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
      }
    }
    if ((uVar5 & 0x10) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a71);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = " (First)";
      if ((local_50 & 0x10) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a71,param_3,
                        "DAT0 RAM ECC Limit Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x10) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a71,"Fatal, Link %02d %s%s\n",param_3,"DAT0 RAM ECC Limit Error",
                 pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x10) == 0) {
        pcVar8 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a71,"Fatal, Link %02d %s%s\n",param_3,"DAT0 RAM ECC Limit Error",pcVar8)
      ;
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a71,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4a71,param_3,0,1,1,0,&local_58,0x20,0x1365,
                 "\"DAT0 RAM ECC Limit Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_68 = local_68 & 0xffffffef;
    }
    if ((uVar5 & 0x20) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a72);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = " (First)";
      if ((local_50 & 0x20) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a72,param_3,
                        "DAT1 RAM ECC DBE Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x20) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a72,"Fatal, Link %02d %s%s\n",param_3,"DAT1 RAM ECC DBE Error",pcVar8
                );
      pcVar8 = " (First)";
      if ((local_50 & 0x20) == 0) {
        pcVar8 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a72,"Fatal, Link %02d %s%s\n",param_3,"DAT1 RAM ECC DBE Error",pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a72,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4a72,param_3,0,1,1,0,&local_58,0x20,0x136c,
                 "\"DAT1 RAM ECC DBE Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_68 = local_68 & 0xffffffdf;
      if ((uVar9 & 0x20) == 0) {
        local_64 = CONCAT44(0x47,(undefined4)local_64);
        nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
      }
    }
    if ((uVar5 & 0x40) == 0) {
      local_58._4_4_ = (uint)((ulong)local_58 >> 0x20);
      uVar9 = local_58._4_4_ & (uint)local_50;
    }
    else {
      iVar6 = nvswitch_translate_hw_error(0x4a73);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = "";
      if ((local_50 & 0x40) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a73,param_3,
                        "DAT1 RAM ECC Limit Error",pcVar8);
      pcVar8 = "";
      if ((local_50 & 0x40) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a73,"Fatal, Link %02d %s%s\n",param_3,"DAT1 RAM ECC Limit Error",
                 pcVar8);
      pcVar8 = "";
      if ((local_50 & 0x40) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a73,"Fatal, Link %02d %s%s\n",param_3,"DAT1 RAM ECC Limit Error",pcVar8)
      ;
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a73,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4a73,param_3,0,1,1,0,&local_58,0x20,0x137a,
                 "\"DAT1 RAM ECC Limit Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_68 = local_68 & 0xffffffbf;
      uVar9 = local_58._4_4_ & (uint)local_50;
    }
    if (uVar9 != 0) {
      pcVar1 = (code *)param_1[0x122];
      uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
      iVar6 = (*pcVar1)(param_1,10,0,uVar4);
      if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar1 = (code *)param_1[0x125];
      uVar9 = (uint)local_50 & local_58._4_4_;
      uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
      (*pcVar1)(param_1,10,0,uVar4,0xa9c,uVar9);
    }
    if (local_68 != 0) {
      iVar6 = nvswitch_translate_hw_error(0x2713);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x2713,
                        "_nvswitch_service_nvltlc_rx_sys_fatal_lr10",0x1384);
      nvswitch_os_report_error
                (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_nvltlc_rx_sys_fatal_lr10",0x1384);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_nvltlc_rx_sys_fatal_lr10",0x1384);
      nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_68,4,0x1384,&DAT_00c81851);
    }
    if ((char)param_1[(ulong)param_3 * 8 + 0x1ed] != '\0') {
      pcVar1 = (code *)param_1[0x122];
      uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
      iVar6 = (*pcVar1)(param_1,10,0,uVar4);
      if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar1 = (code *)param_1[0x125];
      uVar9 = local_50._4_4_ ^ uVar5;
      uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
      (*pcVar1)(param_1,10,0,uVar4,0xa88,uVar9);
    }
    pcVar1 = (code *)param_1[0x122];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    iVar6 = (*pcVar1)(param_1,10,0,uVar4);
    if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar1 = (code *)param_1[0x125];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    (*pcVar1)(param_1,10,0,uVar4,0xa80,uVar5);
    if (local_68 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = 0xfffffff6;
    }
    return uVar7;
  }
  return 0xfffffffd;
}


// ===== 001c7d20 _nvswitch_service_nvltlc_tx_lnk_fatal_0_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Type propagation algorithm not settling */

undefined8
_nvswitch_service_nvltlc_tx_lnk_fatal_0_lr10(long *param_1,undefined1 param_2,uint param_3)

{
  code *pcVar1;
  long lVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  char *pcVar8;
  uint uVar9;
  uint local_68;
  undefined8 local_64;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  pcVar1 = (code *)param_1[0x122];
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_64 = 0;
  local_5c = 0;
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
  iVar6 = (*pcVar1)(param_1,10,0,uVar4);
  if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar1 = (code *)param_1[0x124];
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
  uVar4 = (*pcVar1)(param_1,10,0,uVar4,0x1280);
  local_58 = CONCAT44(local_58._4_4_,uVar4);
  pcVar1 = (code *)param_1[0x122];
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
  iVar6 = (*pcVar1)(param_1,10,0,uVar4);
  if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar1 = (code *)param_1[0x124];
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
  uVar5 = (*pcVar1)(param_1,10,0,uVar4,0x1288);
  local_50 = CONCAT44(uVar5,(uint)local_50);
  local_58 = CONCAT44(uVar5,(uint)local_58);
  uVar5 = uVar5 & (uint)local_58;
  local_64 = CONCAT62(local_64._2_6_,CONCAT11((char)param_3,param_2)) & 0xffffffffffff03ff;
  if (uVar5 == 0) {
    uVar7 = 0xfffffffd;
  }
  else {
    pcVar1 = (code *)param_1[0x122];
    local_68 = uVar5;
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    iVar6 = (*pcVar1)(param_1,10,0,uVar4);
    if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar1 = (code *)param_1[0x124];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    uVar4 = (*pcVar1)(param_1,10,0,uVar4,0x129c);
    local_50 = CONCAT44(local_50._4_4_,uVar4);
    pcVar1 = (code *)param_1[0x122];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    iVar6 = (*pcVar1)(param_1,10,0,uVar4);
    if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar1 = (code *)param_1[0x124];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    uVar9 = (*pcVar1)(param_1,10,0,uVar4,0x1298);
    if ((uVar5 & 0x20000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a3c);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = " (First)";
      if ((local_50 & 0x20000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a3c,param_3,
                        "TX DL Credit Parity Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x20000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a3c,"Fatal, Link %02d %s%s\n",param_3,"TX DL Credit Parity Error",
                 pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x20000) == 0) {
        pcVar8 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a3c,"Fatal, Link %02d %s%s\n",param_3,"TX DL Credit Parity Error",pcVar8
                );
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a3c,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4a3c,param_3,0,1,1,0,&local_58,0x20,0x13bb,
                 "\"TX DL Credit Parity Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_68 = local_68 & 0xfffdffff;
      if ((uVar9 & 0x20000) == 0) {
        local_64 = CONCAT44(0x29,(undefined4)local_64);
        nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
      }
    }
    if ((uVar5 & 0x40000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a74);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = " (First)";
      if ((local_50 & 0x40000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a74,param_3,
                        "CREQ RAM HDR ECC DBE Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x40000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a74,"Fatal, Link %02d %s%s\n",param_3,"CREQ RAM HDR ECC DBE Error",
                 pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x40000) == 0) {
        pcVar8 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a74,"Fatal, Link %02d %s%s\n",param_3,"CREQ RAM HDR ECC DBE Error",
                 pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a74,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4a74,param_3,0,1,1,0,&local_58,0x20,0x13c8,
                 "\"CREQ RAM HDR ECC DBE Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_68 = local_68 & 0xfffbffff;
    }
    if ((uVar5 & 0x200000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a77);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = " (First)";
      if ((local_50 & 0x200000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a77,param_3,
                        "Response RAM HDR ECC DBE Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x200000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a77,"Fatal, Link %02d %s%s\n",param_3,
                 "Response RAM HDR ECC DBE Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x200000) == 0) {
        pcVar8 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a77,"Fatal, Link %02d %s%s\n",param_3,"Response RAM HDR ECC DBE Error",
                 pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a77,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4a77,param_3,0,1,1,0,&local_58,0x20,0x13cf,
                 "\"Response RAM HDR ECC DBE Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_68 = local_68 & 0xffdfffff;
    }
    if ((uVar5 & 0x1000000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a7a);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = " (First)";
      if ((local_50 & 0x1000000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a7a,param_3,
                        "COM RAM HDR ECC DBE Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x1000000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a7a,"Fatal, Link %02d %s%s\n",param_3,"COM RAM HDR ECC DBE Error",
                 pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x1000000) == 0) {
        pcVar8 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a7a,"Fatal, Link %02d %s%s\n",param_3,"COM RAM HDR ECC DBE Error",pcVar8
                );
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a7a,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4a7a,param_3,0,1,1,0,&local_58,0x20,0x13d6,
                 "\"COM RAM HDR ECC DBE Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_68 = local_68 & 0xfeffffff;
    }
    if ((uVar5 & 0x8000000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a7d);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = " (First)";
      if ((local_50 & 0x8000000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a7d,param_3,
                        "RSP1 RAM HDR ECC DBE Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x8000000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a7d,"Fatal, Link %02d %s%s\n",param_3,"RSP1 RAM HDR ECC DBE Error",
                 pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x8000000) == 0) {
        pcVar8 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a7d,"Fatal, Link %02d %s%s\n",param_3,"RSP1 RAM HDR ECC DBE Error",
                 pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a7d,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4a7d,param_3,0,1,1,0,&local_58,0x20,0x13dd,
                 "\"RSP1 RAM HDR ECC DBE Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_68 = local_68 & 0xf7ffffff;
    }
    if ((uVar5 & 0x10000000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a7e);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = " (First)";
      if ((local_50 & 0x10000000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a7e,param_3,
                        "RSP1 RAM DAT ECC DBE Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x10000000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a7e,"Fatal, Link %02d %s%s\n",param_3,"RSP1 RAM DAT ECC DBE Error",
                 pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x10000000) == 0) {
        pcVar8 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a7e,"Fatal, Link %02d %s%s\n",param_3,"RSP1 RAM DAT ECC DBE Error",
                 pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a7e,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4a7e,param_3,0,1,1,0,&local_58,0x20,0x13e4,
                 "\"RSP1 RAM DAT ECC DBE Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_68 = local_68 & 0xefffffff;
      if ((uVar9 & 0x10000000) == 0) {
        local_64 = CONCAT44(0x4b,(undefined4)local_64);
        nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
      }
    }
    if (local_68 != 0) {
      iVar6 = nvswitch_translate_hw_error(0x2713);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x2713,
                        "_nvswitch_service_nvltlc_tx_lnk_fatal_0_lr10",0x13ef);
      nvswitch_os_report_error
                (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_nvltlc_tx_lnk_fatal_0_lr10",0x13ef);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_nvltlc_tx_lnk_fatal_0_lr10",0x13ef);
      nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_68,4,0x13ef,&DAT_00c81851);
    }
    if ((char)param_1[(ulong)param_3 * 8 + 0x1ed] != '\0') {
      pcVar1 = (code *)param_1[0x122];
      uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
      iVar6 = (*pcVar1)(param_1,10,0,uVar4);
      if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar1 = (code *)param_1[0x125];
      uVar9 = local_50._4_4_ ^ uVar5;
      uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
      (*pcVar1)(param_1,10,0,uVar4,0x1288,uVar9);
    }
    if ((local_58._4_4_ & (uint)local_50) != 0) {
      pcVar1 = (code *)param_1[0x122];
      uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
      iVar6 = (*pcVar1)(param_1,10,0,uVar4);
      if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar1 = (code *)param_1[0x125];
      uVar9 = (uint)local_50 & local_58._4_4_;
      uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
      (*pcVar1)(param_1,10,0,uVar4,0x129c,uVar9);
    }
    pcVar1 = (code *)param_1[0x122];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    iVar6 = (*pcVar1)(param_1,10,0,uVar4);
    if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar1 = (code *)param_1[0x125];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    (*pcVar1)(param_1,10,0,uVar4,0x1280,uVar5);
    if (local_68 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = 0xfffffff6;
    }
  }
  return uVar7;
}


// ===== 001c8b30 _nvswitch_service_nvltlc_rx_lnk_nonfatal_0_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8
_nvswitch_service_nvltlc_rx_lnk_nonfatal_0_lr10(long *param_1,undefined1 param_2,undefined4 param_3)

{
  code *pcVar1;
  long lVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  char *pcVar8;
  uint uVar9;
  uint local_68;
  undefined1 local_64;
  byte local_63;
  undefined4 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  pcVar1 = (code *)param_1[0x122];
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
  iVar6 = (*pcVar1)(param_1,10,0,uVar4);
  if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar1 = (code *)param_1[0x124];
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
  uVar4 = (*pcVar1)(param_1,10,0,uVar4,0x1a80);
  local_58 = CONCAT44(local_58._4_4_,uVar4);
  pcVar1 = (code *)param_1[0x122];
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
  iVar6 = (*pcVar1)(param_1,10,0,uVar4);
  if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar1 = (code *)param_1[0x124];
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
  uVar5 = (*pcVar1)(param_1,10,0,uVar4,0x1a8c);
  local_63 = (byte)param_3 & 3;
  local_50 = CONCAT44(uVar5,(uint)local_50);
  local_58 = CONCAT44(uVar5,(uint)local_58);
  uVar5 = uVar5 & (uint)local_58;
  if (uVar5 == 0) {
    uVar7 = 0xfffffffd;
  }
  else {
    pcVar1 = (code *)param_1[0x122];
    local_68 = uVar5;
    local_64 = param_2;
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    iVar6 = (*pcVar1)(param_1,10,0,uVar4);
    if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar1 = (code *)param_1[0x124];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    uVar4 = (*pcVar1)(param_1,10,0,uVar4,0x1a9c);
    local_50 = CONCAT44(local_50._4_4_,uVar4);
    pcVar1 = (code *)param_1[0x122];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    iVar6 = (*pcVar1)(param_1,10,0,uVar4);
    if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar1 = (code *)param_1[0x124];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    uVar9 = (*pcVar1)(param_1,10,0,uVar4,0x1a98);
    if ((uVar5 & 0x40000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a8a);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = "";
      if ((local_50 & 0x40000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a8a,param_3,
                        "RX Rsp Status PRIV Error",pcVar8);
      pcVar8 = "";
      if ((local_50 & 0x40000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a8a,"Non-fatal, Link %02d %s%s\n",param_3,"RX Rsp Status PRIV Error",
                 pcVar8);
      pcVar8 = "";
      if ((local_50 & 0x40000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a8a,"Non-fatal, Link %02d %s%s\n",param_3,"RX Rsp Status PRIV Error",
                 pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a8a,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x24,0x4a8a,param_3,0,1,0,0,&local_58,0x20,0xdbe,
                 "\"RX Rsp Status PRIV Error\"");
      nvswitch_lib_notify_client_events(param_1,1);
      local_68 = local_68 & 0xfffbffff;
      if ((uVar9 & 0x40000) == 0) {
        local_60 = 0x25;
        nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
      }
    }
    if (local_68 != 0) {
      iVar6 = nvswitch_translate_hw_error(0x2713);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x2713,
                        "_nvswitch_service_nvltlc_rx_lnk_nonfatal_0_lr10",0xdc8);
      nvswitch_os_report_error
                (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_nvltlc_rx_lnk_nonfatal_0_lr10",0xdc8);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_nvltlc_rx_lnk_nonfatal_0_lr10",0xdc8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
      nvswitch_record_error(param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_68,4,0xdc8,&DAT_00c81851)
      ;
    }
    if ((local_58._4_4_ & (uint)local_50) != 0) {
      pcVar1 = (code *)param_1[0x122];
      uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
      iVar6 = (*pcVar1)(param_1,10,0,uVar4);
      if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar1 = (code *)param_1[0x125];
      uVar9 = (uint)local_50 & local_58._4_4_;
      uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
      (*pcVar1)(param_1,10,0,uVar4,0x1a9c,uVar9);
    }
    pcVar1 = (code *)param_1[0x122];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    iVar6 = (*pcVar1)(param_1,10,0,uVar4);
    if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar1 = (code *)param_1[0x125];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    (*pcVar1)(param_1,10,0,uVar4,0x1a80,uVar5);
    if (local_68 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = 0xfffffff6;
    }
  }
  return uVar7;
}


// ===== 001c9180 _nvswitch_service_nvltlc_tx_lnk_nonfatal_0_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Type propagation algorithm not settling */

undefined8
_nvswitch_service_nvltlc_tx_lnk_nonfatal_0_lr10(long *param_1,undefined1 param_2,uint param_3)

{
  code *pcVar1;
  long lVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  char *pcVar8;
  uint uVar9;
  uint local_68;
  undefined1 local_64;
  byte local_63;
  undefined4 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  pcVar1 = (code *)param_1[0x122];
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
  iVar6 = (*pcVar1)(param_1,10,0,uVar4);
  if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar1 = (code *)param_1[0x124];
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
  uVar4 = (*pcVar1)(param_1,10,0,uVar4,0x1280);
  local_58 = CONCAT44(local_58._4_4_,uVar4);
  pcVar1 = (code *)param_1[0x122];
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
  iVar6 = (*pcVar1)(param_1,10,0,uVar4);
  if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar1 = (code *)param_1[0x124];
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
  uVar5 = (*pcVar1)(param_1,10,0,uVar4,0x128c);
  local_63 = (byte)param_3 & 3;
  local_50 = CONCAT44(uVar5,(uint)local_50);
  local_58 = CONCAT44(uVar5,(uint)local_58);
  uVar5 = uVar5 & (uint)local_58;
  if (uVar5 == 0) {
    uVar7 = 0xfffffffd;
  }
  else {
    pcVar1 = (code *)param_1[0x122];
    local_68 = uVar5;
    local_64 = param_2;
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    iVar6 = (*pcVar1)(param_1,10,0,uVar4);
    if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar1 = (code *)param_1[0x124];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    uVar4 = (*pcVar1)(param_1,10,0,uVar4,0x129c);
    local_50 = CONCAT44(local_50._4_4_,uVar4);
    pcVar1 = (code *)param_1[0x122];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    iVar6 = (*pcVar1)(param_1,10,0,uVar4);
    if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar1 = (code *)param_1[0x124];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    uVar9 = (*pcVar1)(param_1,10,0,uVar4,0x1298);
    if ((uVar5 & 0x80000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a75);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = " (First)";
      if ((local_50 & 0x80000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a75,param_3,
                        "CREQ RAM DAT ECC DBE Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x80000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a75,"Non-fatal, Link %02d %s%s\n",param_3,
                 "CREQ RAM DAT ECC DBE Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x80000) == 0) {
        pcVar8 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a75,"Non-fatal, Link %02d %s%s\n",param_3,"CREQ RAM DAT ECC DBE Error",
                 pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a75,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x24,0x4a75,param_3,0,1,0,0,&local_58,0x20,0xdfd,
                 "\"CREQ RAM DAT ECC DBE Error\"");
      nvswitch_lib_notify_client_events(param_1,1);
      local_68 = local_68 & 0xfff7ffff;
      if ((uVar9 & 0x80000) == 0) {
        local_60 = 0x48;
        nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
      }
    }
    if ((uVar5 & 0x100000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a76);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = " (First)";
      if ((local_50 & 0x100000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a76,param_3,
                        "CREQ RAM DAT ECC Limit Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x100000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a76,"Non-fatal, Link %02d %s%s\n",param_3,
                 "CREQ RAM DAT ECC Limit Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x100000) == 0) {
        pcVar8 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a76,"Non-fatal, Link %02d %s%s\n",param_3,"CREQ RAM DAT ECC Limit Error"
                 ,pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a76,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x24,0x4a76,param_3,0,1,0,0,&local_58,0x20,0xe0b,
                 "\"CREQ RAM DAT ECC Limit Error\"");
      nvswitch_lib_notify_client_events(param_1,1);
      local_68 = local_68 & 0xffefffff;
    }
    if ((uVar5 & 0x400000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a78);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = " (First)";
      if ((local_50 & 0x400000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a78,param_3,
                        "Response RAM DAT ECC DBE Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x400000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a78,"Non-fatal, Link %02d %s%s\n",param_3,
                 "Response RAM DAT ECC DBE Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x400000) == 0) {
        pcVar8 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a78,"Non-fatal, Link %02d %s%s\n",param_3,
                 "Response RAM DAT ECC DBE Error",pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a78,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x24,0x4a78,param_3,0,1,0,0,&local_58,0x20,0xe12,
                 "\"Response RAM DAT ECC DBE Error\"");
      nvswitch_lib_notify_client_events(param_1,1);
      local_68 = local_68 & 0xffbfffff;
    }
    if ((uVar5 & 0x800000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a79);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = " (First)";
      if ((local_50 & 0x800000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a79,param_3,
                        "Response RAM ECC Limit Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x800000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a79,"Non-fatal, Link %02d %s%s\n",param_3,
                 "Response RAM ECC Limit Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x800000) == 0) {
        pcVar8 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a79,"Non-fatal, Link %02d %s%s\n",param_3,"Response RAM ECC Limit Error"
                 ,pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a79,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x24,0x4a79,param_3,0,1,0,0,&local_58,0x20,0xe19,
                 "\"Response RAM ECC Limit Error\"");
      nvswitch_lib_notify_client_events(param_1,1);
      local_68 = local_68 & 0xff7fffff;
    }
    if ((uVar5 & 0x2000000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a7b);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = " (First)";
      if ((local_50 & 0x2000000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a7b,param_3,
                        "COM RAM DAT ECC DBE Error",pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x2000000) == 0) {
        pcVar8 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a7b,"Non-fatal, Link %02d %s%s\n",param_3,"COM RAM DAT ECC DBE Error"
                 ,pcVar8);
      pcVar8 = " (First)";
      if ((local_50 & 0x2000000) == 0) {
        pcVar8 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a7b,"Non-fatal, Link %02d %s%s\n",param_3,"COM RAM DAT ECC DBE Error",
                 pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a7b,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x24,0x4a7b,param_3,0,1,0,0,&local_58,0x20,0xe20,
                 "\"COM RAM DAT ECC DBE Error\"");
      nvswitch_lib_notify_client_events(param_1,1);
      local_68 = local_68 & 0xfdffffff;
      if ((uVar9 & 0x2000000) == 0) {
        local_60 = 0x4a;
        nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
      }
    }
    if ((uVar5 & 0x4000000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a7c);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = "";
      if ((local_50 & 0x4000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a7c,param_3,
                        "COM RAM ECC Limit Error",pcVar8);
      pcVar8 = "";
      if ((local_50 & 0x4000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a7c,"Non-fatal, Link %02d %s%s\n",param_3,"COM RAM ECC Limit Error",
                 pcVar8);
      pcVar8 = "";
      if ((local_50 & 0x4000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a7c,"Non-fatal, Link %02d %s%s\n",param_3,"COM RAM ECC Limit Error",
                 pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a7c,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x24,0x4a7c,param_3,0,1,0,0,&local_58,0x20,0xe2e,
                 "\"COM RAM ECC Limit Error\"");
      nvswitch_lib_notify_client_events(param_1,1);
      local_68 = local_68 & 0xfbffffff;
    }
    if ((uVar5 & 0x20000000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4a7f);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = "";
      if ((local_50 & 0x20000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4a7f,param_3,
                        "RSP1 RAM ECC Limit Error",pcVar8);
      pcVar8 = "";
      if ((local_50 & 0x20000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4a7f,"Non-fatal, Link %02d %s%s\n",param_3,"RSP1 RAM ECC Limit Error",
                 pcVar8);
      pcVar8 = "";
      if ((local_50 & 0x20000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4a7f,"Non-fatal, Link %02d %s%s\n",param_3,"RSP1 RAM ECC Limit Error",
                 pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4a7f,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x24,0x4a7f,param_3,0,1,0,0,&local_58,0x20,0xe35,
                 "\"RSP1 RAM ECC Limit Error\"");
      nvswitch_lib_notify_client_events(param_1,1);
      local_68 = local_68 & 0xdfffffff;
    }
    if (local_68 != 0) {
      iVar6 = nvswitch_translate_hw_error(0x2713);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x2713,
                        "_nvswitch_service_nvltlc_tx_lnk_nonfatal_0_lr10",0xe39);
      nvswitch_os_report_error
                (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_nvltlc_tx_lnk_nonfatal_0_lr10",0xe39);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_nvltlc_tx_lnk_nonfatal_0_lr10",0xe39);
      nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
      nvswitch_record_error(param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_68,4,0xe39,&DAT_00c81851)
      ;
    }
    if ((char)param_1[(ulong)param_3 * 8 + 0x1ed] != '\0') {
      pcVar1 = (code *)param_1[0x122];
      uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
      iVar6 = (*pcVar1)(param_1,10,0,uVar4);
      if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar1 = (code *)param_1[0x125];
      uVar9 = local_50._4_4_ ^ uVar5;
      uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
      (*pcVar1)(param_1,10,0,uVar4,0x128c,uVar9);
    }
    if ((local_58._4_4_ & (uint)local_50) != 0) {
      pcVar1 = (code *)param_1[0x122];
      uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
      iVar6 = (*pcVar1)(param_1,10,0,uVar4);
      if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar1 = (code *)param_1[0x125];
      uVar9 = (uint)local_50 & local_58._4_4_;
      uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
      (*pcVar1)(param_1,10,0,uVar4,0x129c,uVar9);
    }
    pcVar1 = (code *)param_1[0x122];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    iVar6 = (*pcVar1)(param_1,10,0,uVar4);
    if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar1 = (code *)param_1[0x125];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,10);
    (*pcVar1)(param_1,10,0,uVar4,0x1280,uVar5);
    if (local_68 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = 0xfffffff6;
    }
  }
  return uVar7;
}


// ===== 001ca0c0 _nvswitch_service_priv_ring_lr10 =====

undefined8 _nvswitch_service_priv_ring_lr10(long *param_1)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  undefined8 uVar6;
  uint uVar7;
  int iVar8;
  uint local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  
  uVar5 = nvswitch_reg_read_32(param_1,0x120058);
  local_4c = (uint)uVar5;
  if (local_4c == 0) {
    uVar6 = 0xfffffffd;
  }
  else {
    if ((uVar5 & 0x100) != 0) {
      local_48 = nvswitch_reg_read_32(param_1,0x122120);
      local_44 = nvswitch_reg_read_32(param_1,0x122124);
      local_40 = nvswitch_reg_read_32(param_1,0x122128);
      local_3c = nvswitch_reg_read_32(param_1,0x12212c);
      iVar4 = nvswitch_translate_hw_error(0x2711);
      if (iVar4 == 1) {
        nvswitch_assert_log();
      }
      lVar1 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, %s, instance=%d, chiplet=%d\n"
                        ,param_1 + 1,*(undefined4 *)(lVar1 + 0x40),*(undefined1 *)(lVar1 + 0x44),
                        *(undefined1 *)(lVar1 + 0x45),*(undefined1 *)(lVar1 + 0x46),0x2711,
                        "PRI WRITE SYS error",3,0);
      nvswitch_os_report_error
                (param_1[3],0x2711,"Non-fatal, %s, instance=%d, chiplet=%d\n","PRI WRITE SYS error",
                 3,0);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2711,"Non-fatal, %s, instance=%d, chiplet=%d\n","PRI WRITE SYS error",3,0
                );
      nvswitch_inforom_bbx_add_sxid(param_1,0x2711,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x24,0x2711,3,0,1,0,0,&local_48,0x10,0x475,
                 "\"PRI WRITE SYS error\"");
      nvswitch_lib_notify_client_events(param_1,1);
      uVar5 = (ulong)local_4c & 0xfffffffffffffeff;
      local_4c = (uint)uVar5;
    }
    iVar8 = 0x128120;
    iVar4 = 0;
    do {
      while( true ) {
        uVar3 = (uint)uVar5;
        uVar7 = 1 << ((byte)iVar4 & 0x1f);
        if (((uint)(uVar5 >> 0x10) & 0xffff & uVar7) == 0) break;
        local_48 = nvswitch_reg_read_32(param_1,iVar8);
        local_44 = nvswitch_reg_read_32(param_1,iVar8 + 4);
        local_40 = nvswitch_reg_read_32(param_1,iVar8 + 8);
        local_3c = nvswitch_reg_read_32(param_1,iVar8 + 0xc);
        iVar2 = nvswitch_translate_hw_error(0x2711);
        if (iVar2 == 1) {
          nvswitch_assert_log();
        }
        lVar1 = *param_1;
        iVar8 = iVar8 + 0x800;
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, %s, instance=%d, chiplet=%d\n"
                          ,param_1 + 1,*(undefined4 *)(lVar1 + 0x40),*(undefined1 *)(lVar1 + 0x44),
                          *(undefined1 *)(lVar1 + 0x45),*(undefined1 *)(lVar1 + 0x46),0x2711,
                          "PRI WRITE PRT error",4,iVar4);
        nvswitch_os_report_error
                  (param_1[3],0x2711,"Non-fatal, %s, instance=%d, chiplet=%d\n",
                   "PRI WRITE PRT error",4,iVar4);
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2711,"Non-fatal, %s, instance=%d, chiplet=%d\n","PRI WRITE PRT error",4
                   ,iVar4);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2711,0,0,0);
        iVar2 = iVar4 + 1;
        nvswitch_record_error
                  (param_1,param_1 + 0x24,0x2711,4,iVar4,1,0,0,&local_48,0x10,0x48a,
                   "\"PRI WRITE PRT error\"");
        nvswitch_lib_notify_client_events(param_1,1);
        uVar3 = local_4c & ~(uVar7 << 0x10);
        uVar5 = (ulong)uVar3;
        local_4c = uVar3;
        iVar4 = iVar2;
        if (iVar2 == 9) goto LAB_001ca2c7;
      }
      iVar4 = iVar4 + 1;
      iVar8 = iVar8 + 0x800;
    } while (iVar4 != 9);
LAB_001ca2c7:
    if (uVar3 == 0) {
      nvswitch_ring_master_cmd_lr10(param_1,2);
      uVar6 = 0;
    }
    else {
      iVar4 = nvswitch_translate_hw_error(0x2711);
      if (iVar4 == 1) {
        nvswitch_assert_log();
      }
      lVar1 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Unexpected PRI error\n"
                        ,param_1 + 1,*(undefined4 *)(lVar1 + 0x40),*(undefined1 *)(lVar1 + 0x44),
                        *(undefined1 *)(lVar1 + 0x45),*(undefined1 *)(lVar1 + 0x46),0x2711);
      nvswitch_os_report_error(param_1[3],0x2711,"Fatal, Unexpected PRI error\n");
      nvswitch_lib_smbpbi_log_sxid(param_1,0x2711,"Fatal, Unexpected PRI error\n");
      nvswitch_inforom_bbx_add_sxid(param_1,0x2711,0,0,0);
      nvswitch_record_error(param_1,param_1 + 0x1f,0x2711,2,0,1,1,0,&local_4c,4,0x499,&DAT_00c81851)
      ;
      uVar6 = 0xfffffff6;
    }
  }
  return uVar6;
}


// ===== 001ca560 _nvswitch_collect_error_info_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_collect_error_info_lr10(long param_1,undefined4 param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  ulong uVar2;
  uint *puVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint local_44;
  
  *param_4 = 0;
  uVar6 = param_3 & 1;
  if (uVar6 == 0) {
    (**(code **)(param_1 + 0x920))(param_1,5,0,param_2,0x544c);
    if (param_3 == 0x38) {
      uVar6 = 1;
      uVar7 = (**(code **)(param_1 + 0x920))(param_1,5,0,param_2,0x1450);
      *param_4 = *param_4 | 8;
      param_4[1] = uVar7;
    }
  }
  else {
    uVar7 = (**(code **)(param_1 + 0x920))(param_1,5,0,param_2,0x5450);
    *param_4 = *param_4 | 1;
    param_4[1] = uVar7;
    uVar2 = (**(code **)(param_1 + 0x920))(param_1,5,0,param_2,0x544c);
    if ((uVar2 & 1) != 0) {
      uVar6 = (**(code **)(param_1 + 0x920))(param_1,5,0,param_2,0x5454);
      *param_4 = *param_4 | 2;
      uVar7 = 2;
      param_4[2] = uVar6;
      iVar5 = 0x5420;
      do {
        iVar8 = iVar5 + 4;
        uVar6 = (**(code **)(param_1 + 0x920))(param_1,5,0,param_2,iVar5);
        param_4[(ulong)uVar7 + 1] = uVar6;
        uVar7 = uVar7 + 1;
        iVar5 = iVar8;
      } while (iVar8 != 0x544c);
      *param_4 = *param_4 | 4;
      uVar6 = 0xd;
    }
  }
  uVar2 = (**(code **)(param_1 + 0x920))(param_1,5,0,param_2,0x144c);
  if ((uVar2 & 1) == 0) {
LAB_001ca5ec:
    pcVar4 = *(code **)(param_1 + 0x920);
    local_44 = uVar6;
    if ((param_3 & 0x40) == 0) {
LAB_001ca5fd:
      (*pcVar4)(param_1,5,0,param_2,0x444c);
      goto LAB_001ca615;
    }
LAB_001ca7a0:
    uVar7 = uVar6 + 1;
    local_44 = uVar6;
  }
  else {
    if ((param_3 & 0x10) != 0) {
      uVar7 = (**(code **)(param_1 + 0x920))(param_1,5,0,param_2,0x1454);
      uVar2 = (ulong)uVar6;
      uVar6 = uVar6 + 1;
      param_4[uVar2 + 1] = uVar7;
      *param_4 = *param_4 | 0x10;
    }
    if ((param_3 & 0x20) == 0) goto LAB_001ca5ec;
    local_44 = uVar6 + 0xb;
    if (0x10 < local_44) {
      pcVar4 = *(code **)(param_1 + 0x920);
      local_44 = uVar6;
      if (param_3 == 0x38) goto LAB_001ca5fd;
      goto LAB_001ca7a0;
    }
    iVar5 = 0x1420;
    uVar7 = uVar6;
    do {
      uVar1 = (**(code **)(param_1 + 0x920))(param_1,5,0,param_2);
      iVar5 = iVar5 + 4;
      param_4[(ulong)uVar7 + 1] = uVar1;
      uVar7 = uVar7 + 1;
    } while (iVar5 != 0x144c);
    *param_4 = *param_4 | 0x20;
    pcVar4 = *(code **)(param_1 + 0x920);
    if (param_3 == 0x38) goto LAB_001ca5fd;
    uVar7 = uVar6 + 0xc;
  }
  uVar6 = (*pcVar4)(param_1,5,0,param_2,0x4450);
  param_4[(ulong)local_44 + 1] = uVar6;
  *param_4 = *param_4 | 0x40;
  uVar2 = (**(code **)(param_1 + 0x920))(param_1,5,0,param_2,0x444c);
  local_44 = uVar7;
  if ((uVar2 & 1) != 0) {
    local_44 = uVar7 + 1;
    uVar6 = (**(code **)(param_1 + 0x920))(param_1,5,0,param_2,0x4454);
    param_4[(ulong)uVar7 + 1] = uVar6;
    *param_4 = *param_4 | 0x80;
    if (uVar7 + 0xc < 0x11) {
      iVar5 = 0x4420;
      do {
        iVar8 = iVar5 + 4;
        uVar6 = (**(code **)(param_1 + 0x920))(param_1,5,0,param_2,iVar5);
        param_4[(ulong)local_44 + 1] = uVar6;
        local_44 = local_44 + 1;
        iVar5 = iVar8;
      } while (iVar8 != 0x444c);
      *param_4 = *param_4 | 0x100;
      local_44 = uVar7 + 0xc;
    }
  }
  if (local_44 == 0x10) {
    return;
  }
LAB_001ca615:
  puVar3 = param_4 + local_44;
  param_4 = param_4 + (ulong)(0xf - local_44) + (ulong)local_44 + 1;
  if (((int)param_4 - (int)puVar3 & 4U) != 0) {
    puVar3[1] = 0;
    puVar3 = puVar3 + 1;
    if (puVar3 == param_4) {
      return;
    }
  }
  do {
    puVar3[1] = 0;
    puVar3 = puVar3 + 2;
    *puVar3 = 0;
  } while (puVar3 != param_4);
  return;
}


// ===== 001ca983 _nvswitch_service_route_fatal_lr10.cold =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_service_route_fatal_lr10_cold(void)

{
  code *pcVar1;
  undefined4 uVar2;
  long lVar3;
  long unaff_RBX;
  long unaff_RBP;
  undefined4 *puVar4;
  code *in_R9;
  
  puVar4 = (undefined4 *)(unaff_RBP + -0x94);
  for (lVar3 = 8; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined4 *)(unaff_RBP + -0x74);
  for (lVar3 = 0x11; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined4 *)(unaff_RBP + -0xb0);
  for (lVar3 = 7; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  uVar2 = (*in_R9)();
  *(undefined4 *)(unaff_RBP + -0x94) = uVar2;
  uVar2 = (**(code **)(unaff_RBX + 0x920))();
  *(undefined4 *)(unaff_RBP + -0x88) = uVar2;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001caa00 _nvswitch_service_route_fatal_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _nvswitch_service_route_fatal_lr10(long *param_1,uint param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  long lVar7;
  char *pcVar8;
  undefined8 *puVar9;
  ulong *puVar10;
  uint uVar11;
  bool bVar12;
  undefined8 uVar13;
  long *local_f0;
  long *local_e0;
  long *local_d8;
  long *local_d0;
  uint local_bc;
  ulong local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined8 local_9c;
  undefined8 local_94;
  undefined8 local_8c;
  undefined8 local_84;
  undefined8 local_7c;
  undefined8 local_74;
  undefined8 local_6c;
  undefined8 local_64;
  undefined8 local_5c;
  undefined8 local_54;
  undefined8 local_4c;
  undefined8 local_44;
  undefined4 local_3c;
  
  pcVar1 = (code *)param_1[0x124];
  if ((int)param_1[0x3f1] == 6) {
    lVar7 = param_1[0x3f2];
    local_9c = 0;
    local_94 = 0;
    local_8c = 0;
    local_84 = 0;
    local_7c = 0;
    local_74 = 0;
    local_6c = 0;
    local_64 = 0;
    local_5c = 0;
    local_54 = 0;
    local_4c = 0;
    local_44 = 0;
    local_3c = 0;
    local_b8 = 0;
    local_b0 = 0;
    local_a8 = 0;
    local_a0 = 0;
    uVar2 = (*pcVar1)(param_1,5,0,param_2,0x5400);
    local_9c = CONCAT44(local_9c._4_4_,uVar2);
    uVar3 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x5408);
    local_9c = CONCAT44(uVar3 & *(uint *)(&DAT_00009aa8 + lVar7),(uint)local_9c);
    uVar11 = uVar3 & *(uint *)(&DAT_00009aa8 + lVar7) & (uint)local_9c;
    if (uVar11 == 0) {
      uVar13 = 0xfffffffd;
    }
    else {
      local_bc = uVar11;
      local_94._4_4_ = uVar3;
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x541c);
      local_94 = CONCAT44(local_94._4_4_,uVar2);
      uVar3 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x5414);
      _nvswitch_collect_error_info_lr10(param_1,param_2,7,&local_7c);
      if ((uVar11 & 1) != 0) {
        if ((uVar3 & 1) == 0) {
          iVar4 = nvswitch_translate_hw_error(0x3a99);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar8 = " (First)";
          if ((local_94 & 1) == 0) {
            pcVar8 = "";
          }
          lVar7 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44)
                            ,*(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x3a99,
                            param_2,"route buffer over/underflow",pcVar8);
          pcVar8 = " (First)";
          if ((local_94 & 1) == 0) {
            pcVar8 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x3a99,"Non-fatal, Link %02d %s%s\n",param_2,
                     "route buffer over/underflow",pcVar8);
          pcVar8 = " (First)";
          if ((local_94 & 1) == 0) {
            pcVar8 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x3a99,"Non-fatal, Link %02d %s%s\n",param_2,
                     "route buffer over/underflow",pcVar8);
          nvswitch_inforom_bbx_add_sxid(param_1,0x3a99,0,0,0);
          local_d0 = param_1 + 0x24;
          nvswitch_record_error
                    (param_1,local_d0,0x3a99,param_2,0,1,0,0,&local_9c,0x20,0x5e8,
                     "\"route buffer over/underflow\"");
          nvswitch_lib_notify_client_events(param_1,1);
          uVar13 = 0;
        }
        else {
          iVar4 = nvswitch_translate_hw_error(0x3a99);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar8 = " (First)";
          if ((local_94 & 1) == 0) {
            pcVar8 = "";
          }
          lVar7 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44)
                            ,*(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x3a99,
                            param_2,"route buffer over/underflow",pcVar8);
          pcVar8 = " (First)";
          if ((local_94 & 1) == 0) {
            pcVar8 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x3a99,"Fatal, Link %02d %s%s\n",param_2,
                     "route buffer over/underflow",pcVar8);
          pcVar8 = " (First)";
          if ((local_94 & 1) == 0) {
            pcVar8 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x3a99,"Fatal, Link %02d %s%s\n",param_2,"route buffer over/underflow",
                     pcVar8);
          nvswitch_inforom_bbx_add_sxid(param_1,0x3a99,0,0,0);
          local_d0 = param_1 + 0x1f;
          nvswitch_record_error
                    (param_1,local_d0,0x3a99,param_2,0,1,1,0,&local_9c,0x20,0x5e8,
                     "\"route buffer over/underflow\"");
          nvswitch_set_fatal_error(param_1,0,param_2);
          nvswitch_lib_notify_client_events(param_1,0);
          uVar13 = 1;
        }
        nvswitch_record_error
                  (param_1,local_d0,0x3a99,param_2,0,1,uVar13,0,&local_7c,0x44,0x5e9,&DAT_00c81851);
        local_bc = local_bc & 0xfffffffe;
      }
      uVar6 = (ulong)param_2;
      if ((uVar11 & 0x10) != 0) {
        uVar5 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x548c);
        bVar12 = (uVar5 & 1) != 0;
        uVar5 = uVar5 & 1;
        if (bVar12) {
          uVar5 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x5488);
        }
        if ((uVar3 & 0x10) == 0) {
          iVar4 = nvswitch_translate_hw_error(0x3aa1);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar8 = " (First)";
          if ((local_94 & 0x10) == 0) {
            pcVar8 = "";
          }
          lVar7 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44)
                            ,*(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x3aa1,
                            param_2,"route GLT DBE",pcVar8);
          pcVar8 = " (First)";
          if ((local_94 & 0x10) == 0) {
            pcVar8 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x3aa1,"Non-fatal, Link %02d %s%s\n",param_2,"route GLT DBE",pcVar8)
          ;
          pcVar8 = " (First)";
          if ((local_94 & 0x10) == 0) {
            pcVar8 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x3aa1,"Non-fatal, Link %02d %s%s\n",param_2,"route GLT DBE",pcVar8);
          nvswitch_inforom_bbx_add_sxid(param_1,0x3aa1,0,0,0);
          local_f0 = param_1 + 0x24;
          nvswitch_record_error
                    (param_1,local_f0,0x3aa1,param_2,0,1,0,0,&local_9c,0x20,0x5fd,
                     "\"route GLT DBE\"");
          nvswitch_lib_notify_client_events(param_1,1);
          uVar13 = 0;
        }
        else {
          iVar4 = nvswitch_translate_hw_error(0x3aa1);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar8 = " (First)";
          if ((local_94 & 0x10) == 0) {
            pcVar8 = "";
          }
          lVar7 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44)
                            ,*(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x3aa1,
                            param_2,"route GLT DBE",pcVar8);
          pcVar8 = " (First)";
          if ((local_94 & 0x10) == 0) {
            pcVar8 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x3aa1,"Fatal, Link %02d %s%s\n",param_2,"route GLT DBE",pcVar8);
          pcVar8 = " (First)";
          if ((local_94 & 0x10) == 0) {
            pcVar8 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x3aa1,"Fatal, Link %02d %s%s\n",param_2,"route GLT DBE",pcVar8);
          nvswitch_inforom_bbx_add_sxid(param_1,0x3aa1,0,0,0);
          local_f0 = param_1 + 0x1f;
          nvswitch_record_error
                    (param_1,local_f0,0x3aa1,param_2,0,1,1,0,&local_9c,0x20,0x5fd,
                     "\"route GLT DBE\"");
          nvswitch_set_fatal_error(param_1,0,param_2);
          nvswitch_lib_notify_client_events(param_1,0);
          uVar13 = 1;
        }
        nvswitch_record_error
                  (param_1,local_f0,0x3aa1,param_2,0,1,uVar13,0,&local_7c,0x44,0x5fe,&DAT_00c81851);
        local_bc = local_bc & 0xffffffef;
        local_a8._0_5_ = CONCAT14(1,(undefined4)local_a8);
        local_b0 = CONCAT71(local_b0._1_7_,bVar12);
        local_a0 = 1;
        local_b0 = CONCAT44(uVar5,(undefined4)local_b0);
        local_b8 = (ulong)param_2 << 0x20 | 0x3aa1;
        nvswitch_inforom_ecc_log_err_event(param_1,&local_b8);
      }
      if ((uVar11 & 0x20) != 0) {
        if ((uVar3 & 0x20) == 0) {
          iVar4 = nvswitch_translate_hw_error(0x3a9e);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar8 = " (First)";
          if ((local_94 & 0x20) == 0) {
            pcVar8 = "";
          }
          lVar7 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44)
                            ,*(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x3a9e,
                            param_2,"route transdone over/underflow",pcVar8);
          pcVar8 = " (First)";
          if ((local_94 & 0x20) == 0) {
            pcVar8 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x3a9e,"Non-fatal, Link %02d %s%s\n",param_2,
                     "route transdone over/underflow",pcVar8);
          pcVar8 = " (First)";
          if ((local_94 & 0x20) == 0) {
            pcVar8 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x3a9e,"Non-fatal, Link %02d %s%s\n",param_2,
                     "route transdone over/underflow",pcVar8);
          nvswitch_inforom_bbx_add_sxid(param_1,0x3a9e,0,0,0);
          local_d8 = param_1 + 0x24;
          nvswitch_record_error
                    (param_1,local_d8,0x3a9e,param_2,0,1,0,0,&local_9c,0x20,0x60b,
                     "\"route transdone over/underflow\"");
          nvswitch_lib_notify_client_events(param_1,1);
          uVar13 = 0;
        }
        else {
          iVar4 = nvswitch_translate_hw_error(0x3a9e);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar8 = " (First)";
          if ((local_94 & 0x20) == 0) {
            pcVar8 = "";
          }
          lVar7 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44)
                            ,*(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x3a9e,
                            param_2,"route transdone over/underflow",pcVar8);
          pcVar8 = " (First)";
          if ((local_94 & 0x20) == 0) {
            pcVar8 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x3a9e,"Fatal, Link %02d %s%s\n",param_2,
                     "route transdone over/underflow",pcVar8);
          pcVar8 = " (First)";
          if ((local_94 & 0x20) == 0) {
            pcVar8 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x3a9e,"Fatal, Link %02d %s%s\n",param_2,
                     "route transdone over/underflow",pcVar8);
          nvswitch_inforom_bbx_add_sxid(param_1,0x3a9e,0,0,0);
          local_d8 = param_1 + 0x1f;
          nvswitch_record_error
                    (param_1,local_d8,0x3a9e,param_2,0,1,1,0,&local_9c,0x20,0x60b,
                     "\"route transdone over/underflow\"");
          nvswitch_set_fatal_error(param_1,0,param_2);
          nvswitch_lib_notify_client_events(param_1,0);
          uVar13 = 1;
        }
        nvswitch_record_error
                  (param_1,local_d8,0x3a9e,param_2,0,1,uVar13,0,&local_7c,0x44,0x60c,&DAT_00c81851);
        local_bc = local_bc & 0xffffffdf;
      }
      if ((uVar11 & 0x40) != 0) {
        if ((uVar3 & 0x40) == 0) {
          iVar4 = nvswitch_translate_hw_error(0x3aa2);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar8 = " (First)";
          if ((local_94 & 0x40) == 0) {
            pcVar8 = "";
          }
          lVar7 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44)
                            ,*(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x3aa2,
                            param_2,"route parity",pcVar8);
          pcVar8 = " (First)";
          if ((local_94 & 0x40) == 0) {
            pcVar8 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x3aa2,"Non-fatal, Link %02d %s%s\n",param_2,"route parity",pcVar8);
          pcVar8 = " (First)";
          if ((local_94 & 0x40) == 0) {
            pcVar8 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x3aa2,"Non-fatal, Link %02d %s%s\n",param_2,"route parity",pcVar8);
          nvswitch_inforom_bbx_add_sxid(param_1,0x3aa2,0,0,0);
          local_d8 = param_1 + 0x24;
          nvswitch_record_error
                    (param_1,local_d8,0x3aa2,param_2,0,1,0,0,&local_9c,0x20,0x613,"\"route parity\""
                    );
          nvswitch_lib_notify_client_events(param_1,1);
          uVar13 = 0;
        }
        else {
          iVar4 = nvswitch_translate_hw_error(0x3aa2);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar8 = " (First)";
          if ((local_94 & 0x40) == 0) {
            pcVar8 = "";
          }
          lVar7 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44)
                            ,*(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x3aa2,
                            param_2,"route parity",pcVar8);
          pcVar8 = " (First)";
          if ((local_94 & 0x40) == 0) {
            pcVar8 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x3aa2,"Fatal, Link %02d %s%s\n",param_2,"route parity",pcVar8);
          pcVar8 = " (First)";
          if ((local_94 & 0x40) == 0) {
            pcVar8 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x3aa2,"Fatal, Link %02d %s%s\n",param_2,"route parity",pcVar8);
          nvswitch_inforom_bbx_add_sxid(param_1,0x3aa2,0,0,0);
          local_d8 = param_1 + 0x1f;
          nvswitch_record_error
                    (param_1,local_d8,0x3aa2,param_2,0,1,1,0,&local_9c,0x20,0x613,"\"route parity\""
                    );
          nvswitch_set_fatal_error(param_1,0,param_2);
          nvswitch_lib_notify_client_events(param_1,0);
          uVar13 = 1;
        }
        nvswitch_record_error
                  (param_1,local_d8,0x3aa2,param_2,0,1,uVar13,0,&local_7c,0x44,0x614,&DAT_00c81851);
        local_bc = local_bc & 0xffffffbf;
      }
      if ((uVar11 & 0x100) != 0) {
        if ((uVar3 & 0x100) == 0) {
          iVar4 = nvswitch_translate_hw_error(0x3aa4);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar8 = " (First)";
          if ((local_94 & 0x100) == 0) {
            pcVar8 = "";
          }
          lVar7 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44)
                            ,*(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x3aa4,
                            param_2,"route incoming DBE",pcVar8);
          pcVar8 = " (First)";
          if ((local_94 & 0x100) == 0) {
            pcVar8 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x3aa4,"Non-fatal, Link %02d %s%s\n",param_2,"route incoming DBE",
                     pcVar8);
          pcVar8 = " (First)";
          if ((local_94 & 0x100) == 0) {
            pcVar8 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x3aa4,"Non-fatal, Link %02d %s%s\n",param_2,"route incoming DBE",
                     pcVar8);
          nvswitch_inforom_bbx_add_sxid(param_1,0x3aa4,0,0,0);
          local_e0 = param_1 + 0x24;
          nvswitch_record_error
                    (param_1,local_e0,0x3aa4,param_2,0,1,0,0,&local_9c,0x20,0x61b,
                     "\"route incoming DBE\"");
          nvswitch_lib_notify_client_events(param_1,1);
          uVar13 = 0;
        }
        else {
          iVar4 = nvswitch_translate_hw_error(0x3aa4);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar8 = " (First)";
          if ((local_94 & 0x100) == 0) {
            pcVar8 = "";
          }
          lVar7 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44)
                            ,*(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x3aa4,
                            param_2,"route incoming DBE",pcVar8);
          pcVar8 = " (First)";
          if ((local_94 & 0x100) == 0) {
            pcVar8 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x3aa4,"Fatal, Link %02d %s%s\n",param_2,"route incoming DBE",pcVar8
                    );
          pcVar8 = " (First)";
          if ((local_94 & 0x100) == 0) {
            pcVar8 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x3aa4,"Fatal, Link %02d %s%s\n",param_2,"route incoming DBE",pcVar8);
          nvswitch_inforom_bbx_add_sxid(param_1,0x3aa4,0,0,0);
          local_e0 = param_1 + 0x1f;
          nvswitch_record_error
                    (param_1,local_e0,0x3aa4,param_2,0,1,1,0,&local_9c,0x20,0x61b,
                     "\"route incoming DBE\"");
          nvswitch_set_fatal_error(param_1,0,param_2);
          nvswitch_lib_notify_client_events(param_1,0);
          uVar13 = 1;
        }
        nvswitch_record_error
                  (param_1,local_e0,0x3aa4,param_2,0,1,uVar13,0,&local_7c,0x44,0x61c,&DAT_00c81851);
        local_bc = local_bc & 0xfffffeff;
        local_b0 = (local_b0 >> 8 & 0xffffff) << 8;
        local_a8._0_5_ = CONCAT14(1,(undefined4)local_a8);
        local_a0 = 1;
        local_b8 = uVar6 << 0x20 | 0x3aa4;
        nvswitch_inforom_ecc_log_err_event(param_1,&local_b8);
        if ((local_9c & 0x80) != 0) {
          (*(code *)param_1[0x125])(param_1,5,0,param_2,0x5400,0x80);
        }
      }
      if ((uVar11 & 0x200) != 0) {
        if ((uVar3 & 0x200) == 0) {
          iVar4 = nvswitch_translate_hw_error(0x3aa5);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          lVar7 = *param_1;
          pcVar8 = "";
          if ((local_94 & 0x200) != 0) {
            pcVar8 = " (First)";
          }
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44)
                            ,*(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x3aa5,
                            param_2,"route credit parity",pcVar8);
          pcVar8 = "";
          if ((local_94 & 0x200) != 0) {
            pcVar8 = " (First)";
          }
          nvswitch_os_report_error
                    (param_1[3],0x3aa5,"Non-fatal, Link %02d %s%s\n",param_2,"route credit parity",
                     pcVar8);
          pcVar8 = "";
          if ((local_94 & 0x200) != 0) {
            pcVar8 = " (First)";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x3aa5,"Non-fatal, Link %02d %s%s\n",param_2,"route credit parity",
                     pcVar8);
          nvswitch_inforom_bbx_add_sxid(param_1,0x3aa5,0,0,0);
          nvswitch_record_error
                    (param_1,param_1 + 0x24,0x3aa5,param_2,0,1,0,0,&local_9c,0x20,0x630,
                     "\"route credit parity\"");
          nvswitch_lib_notify_client_events(param_1,1);
          nvswitch_record_error
                    (param_1,param_1 + 0x24,0x3aa5,param_2,0,1,0,0,&local_7c,0x44,0x631,
                     &DAT_00c81851);
        }
        else {
          iVar4 = nvswitch_translate_hw_error(0x3aa5);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          lVar7 = *param_1;
          pcVar8 = "";
          if ((local_94 & 0x200) != 0) {
            pcVar8 = " (First)";
          }
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44)
                            ,*(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x3aa5,
                            param_2,"route credit parity",pcVar8);
          pcVar8 = "";
          if ((local_94 & 0x200) != 0) {
            pcVar8 = " (First)";
          }
          nvswitch_os_report_error
                    (param_1[3],0x3aa5,"Fatal, Link %02d %s%s\n",param_2,"route credit parity",
                     pcVar8);
          pcVar8 = "";
          if ((local_94 & 0x200) != 0) {
            pcVar8 = " (First)";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x3aa5,"Fatal, Link %02d %s%s\n",param_2,"route credit parity",pcVar8);
          nvswitch_inforom_bbx_add_sxid(param_1,0x3aa5,0,0,0);
          nvswitch_record_error
                    (param_1,param_1 + 0x1f,0x3aa5,param_2,0,1,1,0,&local_9c,0x20,0x630,
                     "\"route credit parity\"");
          nvswitch_set_fatal_error(param_1,0,param_2);
          nvswitch_lib_notify_client_events(param_1,0);
          nvswitch_record_error
                    (param_1,param_1 + 0x1f,0x3aa5,param_2,0,1,1,0,&local_7c,0x44,0x631,
                     &DAT_00c81851);
        }
        local_bc = local_bc & 0xfffffdff;
        local_b0 = (local_b0 >> 8 & 0xffffff) << 8;
        local_a8._0_5_ = CONCAT14(1,(undefined4)local_a8);
        local_a0 = 1;
        local_b8 = uVar6 << 0x20 | 0x3aa5;
        nvswitch_inforom_ecc_log_err_event(param_1,&local_b8);
      }
      if (local_bc != 0) {
        iVar4 = nvswitch_translate_hw_error(0x2713);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2713,
                          "_nvswitch_service_route_fatal_lr10",0x63b);
        nvswitch_os_report_error
                  (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                   "_nvswitch_service_route_fatal_lr10",0x63b);
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                   "_nvswitch_service_route_fatal_lr10",0x63b);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
        nvswitch_record_error
                  (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_bc,4,0x63b,&DAT_00c81851);
      }
      if ((char)param_1[uVar6 * 8 + 0x1ed] != '\0') {
        (*(code *)param_1[0x125])(param_1,5,0,param_2,0x5408,local_94._4_4_ ^ uVar11);
      }
      if (((uint)local_94 & local_9c._4_4_) != 0) {
        (*(code *)param_1[0x125])(param_1,5,0,param_2,0x541c);
      }
      (*(code *)param_1[0x125])(param_1,5,0,param_2,0x5400,uVar11);
      if (local_bc == 0) {
        uVar13 = 0;
      }
      else {
        uVar13 = 0xfffffff6;
      }
    }
    return uVar13;
  }
  puVar9 = &local_9c;
  for (lVar7 = 8; lVar7 != 0; lVar7 = lVar7 + -1) {
    *(undefined4 *)puVar9 = 0;
    puVar9 = (undefined8 *)((long)puVar9 + 4);
  }
  puVar9 = &local_7c;
  for (lVar7 = 0x11; lVar7 != 0; lVar7 = lVar7 + -1) {
    *(undefined4 *)puVar9 = 0;
    puVar9 = (undefined8 *)((long)puVar9 + 4);
  }
  puVar10 = &local_b8;
  for (lVar7 = 7; lVar7 != 0; lVar7 = lVar7 + -1) {
    *(undefined4 *)puVar10 = 0;
    puVar10 = (ulong *)((long)puVar10 + 4);
  }
  uVar2 = (*pcVar1)(param_1,5,0,param_2,0x5400);
  local_9c = CONCAT44(local_9c._4_4_,uVar2);
  uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x5408);
  local_94 = CONCAT44(uVar2,(uint)local_94);
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001cc1d2 _nvswitch_service_ingress_fatal_lr10.cold =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_service_ingress_fatal_lr10_cold(void)

{
  code *pcVar1;
  undefined4 uVar2;
  long lVar3;
  long unaff_RBX;
  long unaff_RBP;
  undefined4 *puVar4;
  code *in_R9;
  
  puVar4 = (undefined4 *)(unaff_RBP + -0x94);
  for (lVar3 = 8; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined4 *)(unaff_RBP + -0x74);
  for (lVar3 = 0x11; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined4 *)(unaff_RBP + -0xb0);
  for (lVar3 = 7; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  uVar2 = (*in_R9)();
  *(undefined4 *)(unaff_RBP + -0x94) = uVar2;
  uVar2 = (**(code **)(unaff_RBX + 0x920))();
  *(undefined4 *)(unaff_RBP + -0x88) = uVar2;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001cc250 _nvswitch_service_ingress_fatal_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _nvswitch_service_ingress_fatal_lr10(long *param_1,uint param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  char *pcVar7;
  undefined8 *puVar8;
  ulong *puVar9;
  uint uVar10;
  bool bVar11;
  undefined8 uVar12;
  long *local_f0;
  long *local_e0;
  long *local_d8;
  long *local_d0;
  uint local_bc;
  ulong local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined8 local_9c;
  undefined8 local_94;
  undefined8 local_8c;
  undefined8 local_84;
  undefined8 local_7c;
  undefined8 local_74;
  undefined8 local_6c;
  undefined8 local_64;
  undefined8 local_5c;
  undefined8 local_54;
  undefined8 local_4c;
  undefined8 local_44;
  undefined4 local_3c;
  
  pcVar1 = (code *)param_1[0x124];
  if ((int)param_1[0x3f1] == 6) {
    lVar6 = param_1[0x3f2];
    local_9c = 0;
    local_94 = 0;
    local_8c = 0;
    local_84 = 0;
    local_7c = 0;
    local_74 = 0;
    local_6c = 0;
    local_64 = 0;
    local_5c = 0;
    local_54 = 0;
    local_4c = 0;
    local_44 = 0;
    local_3c = 0;
    local_b8 = 0;
    local_b0 = 0;
    local_a8 = 0;
    local_a0 = 0;
    uVar2 = (*pcVar1)(param_1,5,0,param_2,0x1400);
    local_9c = CONCAT44(local_9c._4_4_,uVar2);
    uVar3 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x1408);
    local_9c = CONCAT44(uVar3 & *(uint *)(&DAT_00009ab4 + lVar6),(uint)local_9c);
    uVar10 = uVar3 & *(uint *)(&DAT_00009ab4 + lVar6) & (uint)local_9c;
    if (uVar10 == 0) {
      uVar12 = 0xfffffffd;
    }
    else {
      local_bc = uVar10;
      local_94._4_4_ = uVar3;
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x141c);
      local_94 = CONCAT44(local_94._4_4_,uVar2);
      uVar3 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x1414);
      _nvswitch_collect_error_info_lr10(param_1,param_2,0x38,&local_7c);
      if ((uVar10 & 1) != 0) {
        if ((uVar3 & 1) == 0) {
          iVar4 = nvswitch_translate_hw_error(0x2af9);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          lVar6 = *param_1;
          pcVar7 = "";
          if ((local_94 & 1) != 0) {
            pcVar7 = " (First)";
          }
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44)
                            ,*(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x2af9,
                            param_2,"ingress invalid command",pcVar7);
          pcVar7 = "";
          if ((local_94 & 1) != 0) {
            pcVar7 = " (First)";
          }
          nvswitch_os_report_error
                    (param_1[3],0x2af9,"Non-fatal, Link %02d %s%s\n",param_2,
                     "ingress invalid command",pcVar7);
          pcVar7 = "";
          if ((local_94 & 1) != 0) {
            pcVar7 = " (First)";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x2af9,"Non-fatal, Link %02d %s%s\n",param_2,"ingress invalid command",
                     pcVar7);
          nvswitch_inforom_bbx_add_sxid(param_1,0x2af9,0,0,0);
          nvswitch_record_error
                    (param_1,param_1 + 0x24,0x2af9,param_2,0,1,0,0,&local_9c,0x20,0x6e1,
                     "\"ingress invalid command\"");
          nvswitch_lib_notify_client_events(param_1,1);
          nvswitch_record_error
                    (param_1,param_1 + 0x24,0x2af9,param_2,0,1,0,0,&local_7c,0x44,0x6e2,
                     &DAT_00c81851);
        }
        else {
          iVar4 = nvswitch_translate_hw_error(0x2af9);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          lVar6 = *param_1;
          pcVar7 = "";
          if ((local_94 & 1) != 0) {
            pcVar7 = " (First)";
          }
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44)
                            ,*(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x2af9,
                            param_2,"ingress invalid command",pcVar7);
          pcVar7 = "";
          if ((local_94 & 1) != 0) {
            pcVar7 = " (First)";
          }
          nvswitch_os_report_error
                    (param_1[3],0x2af9,"Fatal, Link %02d %s%s\n",param_2,"ingress invalid command",
                     pcVar7);
          pcVar7 = "";
          if ((local_94 & 1) != 0) {
            pcVar7 = " (First)";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x2af9,"Fatal, Link %02d %s%s\n",param_2,"ingress invalid command",
                     pcVar7);
          nvswitch_inforom_bbx_add_sxid(param_1,0x2af9,0,0,0);
          nvswitch_record_error
                    (param_1,param_1 + 0x1f,0x2af9,param_2,0,1,1,0,&local_9c,0x20,0x6e1,
                     "\"ingress invalid command\"");
          nvswitch_set_fatal_error(param_1,0,param_2);
          nvswitch_lib_notify_client_events(param_1,0);
          nvswitch_record_error
                    (param_1,param_1 + 0x1f,0x2af9,param_2,0,1,1,0,&local_7c,0x44,0x6e2,
                     &DAT_00c81851);
        }
        local_bc = local_bc & 0xfffffffe;
      }
      if ((uVar10 & 0x20) != 0) {
        uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x14b0);
        local_8c = CONCAT44(local_8c._4_4_,uVar2);
        if ((uVar3 & 0x20) == 0) {
          iVar4 = nvswitch_translate_hw_error(0x2b05);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar7 = " (First)";
          if ((local_94 & 0x20) == 0) {
            pcVar7 = "";
          }
          lVar6 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44)
                            ,*(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x2b05,
                            param_2,"ingress header DBE",pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x20) == 0) {
            pcVar7 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x2b05,"Non-fatal, Link %02d %s%s\n",param_2,"ingress header DBE",
                     pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x20) == 0) {
            pcVar7 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x2b05,"Non-fatal, Link %02d %s%s\n",param_2,"ingress header DBE",
                     pcVar7);
          nvswitch_inforom_bbx_add_sxid(param_1,0x2b05,0,0,0);
          local_e0 = param_1 + 0x24;
          nvswitch_record_error
                    (param_1,local_e0,0x2b05,param_2,0,1,0,0,&local_9c,0x20,0x6ea,
                     "\"ingress header DBE\"");
          nvswitch_lib_notify_client_events(param_1,1);
          uVar12 = 0;
        }
        else {
          iVar4 = nvswitch_translate_hw_error(0x2b05);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar7 = " (First)";
          if ((local_94 & 0x20) == 0) {
            pcVar7 = "";
          }
          lVar6 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44)
                            ,*(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x2b05,
                            param_2,"ingress header DBE",pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x20) == 0) {
            pcVar7 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x2b05,"Fatal, Link %02d %s%s\n",param_2,"ingress header DBE",pcVar7
                    );
          pcVar7 = " (First)";
          if ((local_94 & 0x20) == 0) {
            pcVar7 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x2b05,"Fatal, Link %02d %s%s\n",param_2,"ingress header DBE",pcVar7);
          nvswitch_inforom_bbx_add_sxid(param_1,0x2b05,0,0,0);
          local_e0 = param_1 + 0x1f;
          nvswitch_record_error
                    (param_1,local_e0,0x2b05,param_2,0,1,1,0,&local_9c,0x20,0x6ea,
                     "\"ingress header DBE\"");
          nvswitch_set_fatal_error(param_1,0,param_2);
          nvswitch_lib_notify_client_events(param_1,0);
          uVar12 = 1;
        }
        nvswitch_record_error
                  (param_1,local_e0,0x2b05,param_2,0,1,uVar12,0,&local_7c,0x44,0x6eb,&DAT_00c81851);
        local_bc = local_bc & 0xffffffdf;
        local_b0 = (local_b0 >> 8 & 0xffffff) << 8;
        local_a8._0_5_ = CONCAT14(1,(undefined4)local_a8);
        local_a0 = 1;
        local_b8 = (ulong)param_2 << 0x20 | 0x2b05;
        nvswitch_inforom_ecc_log_err_event(param_1,&local_b8);
        if ((local_9c & 0x10) != 0) {
          (*(code *)param_1[0x125])(param_1,5,0,param_2,0x1400,0x10);
        }
      }
      if ((uVar10 & 0x40) != 0) {
        if ((uVar3 & 0x40) == 0) {
          iVar4 = nvswitch_translate_hw_error(0x2b01);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar7 = " (First)";
          if ((local_94 & 0x40) == 0) {
            pcVar7 = "";
          }
          lVar6 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44)
                            ,*(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x2b01,
                            param_2,"ingress invalid VCSet",pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x40) == 0) {
            pcVar7 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x2b01,"Non-fatal, Link %02d %s%s\n",param_2,"ingress invalid VCSet"
                     ,pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x40) == 0) {
            pcVar7 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x2b01,"Non-fatal, Link %02d %s%s\n",param_2,"ingress invalid VCSet",
                     pcVar7);
          nvswitch_inforom_bbx_add_sxid(param_1,0x2b01,0,0,0);
          local_d8 = param_1 + 0x24;
          nvswitch_record_error
                    (param_1,local_d8,0x2b01,param_2,0,1,0,0,&local_9c,0x20,0x6ff,
                     "\"ingress invalid VCSet\"");
          nvswitch_lib_notify_client_events(param_1,1);
          uVar12 = 0;
        }
        else {
          iVar4 = nvswitch_translate_hw_error(0x2b01);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar7 = " (First)";
          if ((local_94 & 0x40) == 0) {
            pcVar7 = "";
          }
          lVar6 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44)
                            ,*(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x2b01,
                            param_2,"ingress invalid VCSet",pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x40) == 0) {
            pcVar7 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x2b01,"Fatal, Link %02d %s%s\n",param_2,"ingress invalid VCSet",
                     pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x40) == 0) {
            pcVar7 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x2b01,"Fatal, Link %02d %s%s\n",param_2,"ingress invalid VCSet",pcVar7
                    );
          nvswitch_inforom_bbx_add_sxid(param_1,0x2b01,0,0,0);
          local_d8 = param_1 + 0x1f;
          nvswitch_record_error
                    (param_1,local_d8,0x2b01,param_2,0,1,1,0,&local_9c,0x20,0x6ff,
                     "\"ingress invalid VCSet\"");
          nvswitch_set_fatal_error(param_1,0,param_2);
          nvswitch_lib_notify_client_events(param_1,0);
          uVar12 = 1;
        }
        nvswitch_record_error
                  (param_1,local_d8,0x2b01,param_2,0,1,uVar12,0,&local_7c,0x44,0x700,&DAT_00c81851);
        local_bc = local_bc & 0xffffffbf;
      }
      if ((uVar10 & 0x400) != 0) {
        uVar5 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x1488);
        bVar11 = (uVar5 & 1) != 0;
        uVar5 = uVar5 & 1;
        if (bVar11) {
          uVar5 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x1488);
        }
        uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x1480);
        local_8c = CONCAT44(local_8c._4_4_,uVar2);
        uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x1488);
        local_8c = CONCAT44(uVar2,(undefined4)local_8c);
        uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x148c);
        local_84 = CONCAT44(local_84._4_4_,uVar2);
        if ((uVar3 & 0x400) == 0) {
          iVar4 = nvswitch_translate_hw_error(0x2b09);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar7 = " (First)";
          if ((local_94 & 0x400) == 0) {
            pcVar7 = "";
          }
          lVar6 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44)
                            ,*(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x2b09,
                            param_2,"ingress Remap DBE",pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x400) == 0) {
            pcVar7 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x2b09,"Non-fatal, Link %02d %s%s\n",param_2,"ingress Remap DBE",
                     pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x400) == 0) {
            pcVar7 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x2b09,"Non-fatal, Link %02d %s%s\n",param_2,"ingress Remap DBE",pcVar7
                    );
          nvswitch_inforom_bbx_add_sxid(param_1,0x2b09,0,0,0);
          local_f0 = param_1 + 0x24;
          nvswitch_record_error
                    (param_1,local_f0,0x2b09,param_2,0,1,0,0,&local_9c,0x20,0x717,
                     "\"ingress Remap DBE\"");
          nvswitch_lib_notify_client_events(param_1,1);
          uVar12 = 0;
        }
        else {
          iVar4 = nvswitch_translate_hw_error(0x2b09);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar7 = " (First)";
          if ((local_94 & 0x400) == 0) {
            pcVar7 = "";
          }
          lVar6 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44)
                            ,*(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x2b09,
                            param_2,"ingress Remap DBE",pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x400) == 0) {
            pcVar7 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x2b09,"Fatal, Link %02d %s%s\n",param_2,"ingress Remap DBE",pcVar7)
          ;
          pcVar7 = " (First)";
          if ((local_94 & 0x400) == 0) {
            pcVar7 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x2b09,"Fatal, Link %02d %s%s\n",param_2,"ingress Remap DBE",pcVar7);
          nvswitch_inforom_bbx_add_sxid(param_1,0x2b09,0,0,0);
          local_f0 = param_1 + 0x1f;
          nvswitch_record_error
                    (param_1,local_f0,0x2b09,param_2,0,1,1,0,&local_9c,0x20,0x717,
                     "\"ingress Remap DBE\"");
          nvswitch_set_fatal_error(param_1,0,param_2);
          nvswitch_lib_notify_client_events(param_1,0);
          uVar12 = 1;
        }
        nvswitch_record_error
                  (param_1,local_f0,0x2b09,param_2,0,1,uVar12,0,&local_7c,0x44,0x718,&DAT_00c81851);
        local_bc = local_bc & 0xfffffbff;
        local_a8._0_5_ = CONCAT14(1,(undefined4)local_a8);
        local_b0 = CONCAT71(local_b0._1_7_,bVar11);
        local_a0 = 1;
        local_b0 = CONCAT44(uVar5,(undefined4)local_b0);
        local_b8 = (ulong)param_2 << 0x20 | 0x2b09;
        nvswitch_inforom_ecc_log_err_event(param_1,&local_b8);
      }
      if ((uVar10 & 0x800) != 0) {
        uVar5 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x149c);
        bVar11 = (uVar5 & 1) != 0;
        uVar5 = uVar5 & 1;
        if (bVar11) {
          uVar5 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x1498);
        }
        uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x1490);
        local_8c = CONCAT44(local_8c._4_4_,uVar2);
        uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x1498);
        local_8c = CONCAT44(uVar2,(undefined4)local_8c);
        uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x149c);
        local_84 = CONCAT44(local_84._4_4_,uVar2);
        if ((uVar3 & 0x800) == 0) {
          iVar4 = nvswitch_translate_hw_error(0x2b0a);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar7 = " (First)";
          if ((local_94 & 0x800) == 0) {
            pcVar7 = "";
          }
          lVar6 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44)
                            ,*(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x2b0a,
                            param_2,"ingress RID DBE",pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x800) == 0) {
            pcVar7 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x2b0a,"Non-fatal, Link %02d %s%s\n",param_2,"ingress RID DBE",
                     pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x800) == 0) {
            pcVar7 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x2b0a,"Non-fatal, Link %02d %s%s\n",param_2,"ingress RID DBE",pcVar7);
          nvswitch_inforom_bbx_add_sxid(param_1,0x2b0a,0,0,0);
          local_f0 = param_1 + 0x24;
          nvswitch_record_error
                    (param_1,local_f0,0x2b0a,param_2,0,1,0,0,&local_9c,0x20,0x735,
                     "\"ingress RID DBE\"");
          nvswitch_lib_notify_client_events(param_1,1);
          uVar12 = 0;
        }
        else {
          iVar4 = nvswitch_translate_hw_error(0x2b0a);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar7 = " (First)";
          if ((local_94 & 0x800) == 0) {
            pcVar7 = "";
          }
          lVar6 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44)
                            ,*(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x2b0a,
                            param_2,"ingress RID DBE",pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x800) == 0) {
            pcVar7 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x2b0a,"Fatal, Link %02d %s%s\n",param_2,"ingress RID DBE",pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x800) == 0) {
            pcVar7 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x2b0a,"Fatal, Link %02d %s%s\n",param_2,"ingress RID DBE",pcVar7);
          nvswitch_inforom_bbx_add_sxid(param_1,0x2b0a,0,0,0);
          local_f0 = param_1 + 0x1f;
          nvswitch_record_error
                    (param_1,local_f0,0x2b0a,param_2,0,1,1,0,&local_9c,0x20,0x735,
                     "\"ingress RID DBE\"");
          nvswitch_set_fatal_error(param_1,0,param_2);
          nvswitch_lib_notify_client_events(param_1,0);
          uVar12 = 1;
        }
        nvswitch_record_error
                  (param_1,local_f0,0x2b0a,param_2,0,1,uVar12,0,&local_7c,0x44,0x736,&DAT_00c81851);
        local_bc = local_bc & 0xfffff7ff;
        local_a8._0_5_ = CONCAT14(1,(undefined4)local_a8);
        local_b0 = CONCAT71(local_b0._1_7_,bVar11);
        local_a0 = 1;
        local_b0 = CONCAT44(uVar5,(undefined4)local_b0);
        local_b8 = (ulong)param_2 << 0x20 | 0x2b0a;
        nvswitch_inforom_ecc_log_err_event(param_1,&local_b8);
      }
      if ((uVar10 & 0x1000) != 0) {
        uVar5 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x14ac);
        bVar11 = (uVar5 & 1) != 0;
        uVar5 = uVar5 & 1;
        if (bVar11) {
          uVar5 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x14a8);
        }
        uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x14a0);
        local_8c = CONCAT44(local_8c._4_4_,uVar2);
        uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x14a8);
        local_8c = CONCAT44(uVar2,(undefined4)local_8c);
        uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x14ac);
        local_84 = CONCAT44(local_84._4_4_,uVar2);
        if ((uVar3 & 0x1000) == 0) {
          iVar4 = nvswitch_translate_hw_error(0x2b0b);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar7 = " (First)";
          if ((local_94 & 0x1000) == 0) {
            pcVar7 = "";
          }
          lVar6 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44)
                            ,*(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x2b0b,
                            param_2,"ingress RLAN DBE",pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x1000) == 0) {
            pcVar7 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x2b0b,"Non-fatal, Link %02d %s%s\n",param_2,"ingress RLAN DBE",
                     pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x1000) == 0) {
            pcVar7 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x2b0b,"Non-fatal, Link %02d %s%s\n",param_2,"ingress RLAN DBE",pcVar7)
          ;
          nvswitch_inforom_bbx_add_sxid(param_1,0x2b0b,0,0,0);
          local_f0 = param_1 + 0x24;
          nvswitch_record_error
                    (param_1,local_f0,0x2b0b,param_2,0,1,0,0,&local_9c,0x20,0x753,
                     "\"ingress RLAN DBE\"");
          nvswitch_lib_notify_client_events(param_1,1);
          uVar12 = 0;
        }
        else {
          iVar4 = nvswitch_translate_hw_error(0x2b0b);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar7 = " (First)";
          if ((local_94 & 0x1000) == 0) {
            pcVar7 = "";
          }
          lVar6 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44)
                            ,*(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x2b0b,
                            param_2,"ingress RLAN DBE",pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x1000) == 0) {
            pcVar7 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x2b0b,"Fatal, Link %02d %s%s\n",param_2,"ingress RLAN DBE",pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x1000) == 0) {
            pcVar7 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x2b0b,"Fatal, Link %02d %s%s\n",param_2,"ingress RLAN DBE",pcVar7);
          nvswitch_inforom_bbx_add_sxid(param_1,0x2b0b,0,0,0);
          local_f0 = param_1 + 0x1f;
          nvswitch_record_error
                    (param_1,local_f0,0x2b0b,param_2,0,1,1,0,&local_9c,0x20,0x753,
                     "\"ingress RLAN DBE\"");
          nvswitch_set_fatal_error(param_1,0,param_2);
          nvswitch_lib_notify_client_events(param_1,0);
          uVar12 = 1;
        }
        nvswitch_record_error
                  (param_1,local_f0,0x2b0b,param_2,0,1,uVar12,0,&local_7c,0x44,0x754,&DAT_00c81851);
        local_bc = local_bc & 0xffffefff;
        local_a8._0_5_ = CONCAT14(1,(undefined4)local_a8);
        local_b0 = CONCAT71(local_b0._1_7_,bVar11);
        local_a0 = 1;
        local_b0 = CONCAT44(uVar5,(undefined4)local_b0);
        local_b8 = (ulong)param_2 << 0x20 | 0x2b0b;
        nvswitch_inforom_ecc_log_err_event(param_1,&local_b8);
      }
      if ((uVar10 & 0x2000) != 0) {
        if ((uVar3 & 0x2000) == 0) {
          iVar4 = nvswitch_translate_hw_error(0x2b0c);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar7 = " (First)";
          if ((local_94 & 0x2000) == 0) {
            pcVar7 = "";
          }
          lVar6 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44)
                            ,*(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x2b0c,
                            param_2,"ingress control parity",pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x2000) == 0) {
            pcVar7 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x2b0c,"Non-fatal, Link %02d %s%s\n",param_2,
                     "ingress control parity",pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x2000) == 0) {
            pcVar7 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x2b0c,"Non-fatal, Link %02d %s%s\n",param_2,"ingress control parity",
                     pcVar7);
          nvswitch_inforom_bbx_add_sxid(param_1,0x2b0c,0,0,0);
          local_d0 = param_1 + 0x24;
          nvswitch_record_error
                    (param_1,local_d0,0x2b0c,param_2,0,1,0,0,&local_9c,0x20,0x761,
                     "\"ingress control parity\"");
          nvswitch_lib_notify_client_events(param_1,1);
          uVar12 = 0;
        }
        else {
          iVar4 = nvswitch_translate_hw_error(0x2b0c);
          if (iVar4 == 1) {
            nvswitch_assert_log();
          }
          pcVar7 = " (First)";
          if ((local_94 & 0x2000) == 0) {
            pcVar7 = "";
          }
          lVar6 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44)
                            ,*(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x2b0c,
                            param_2,"ingress control parity",pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x2000) == 0) {
            pcVar7 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x2b0c,"Fatal, Link %02d %s%s\n",param_2,"ingress control parity",
                     pcVar7);
          pcVar7 = " (First)";
          if ((local_94 & 0x2000) == 0) {
            pcVar7 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x2b0c,"Fatal, Link %02d %s%s\n",param_2,"ingress control parity",
                     pcVar7);
          nvswitch_inforom_bbx_add_sxid(param_1,0x2b0c,0,0,0);
          local_d0 = param_1 + 0x1f;
          nvswitch_record_error
                    (param_1,local_d0,0x2b0c,param_2,0,1,1,0,&local_9c,0x20,0x761,
                     "\"ingress control parity\"");
          nvswitch_set_fatal_error(param_1,0,param_2);
          nvswitch_lib_notify_client_events(param_1,0);
          uVar12 = 1;
        }
        nvswitch_record_error
                  (param_1,local_d0,0x2b0c,param_2,0,1,uVar12,0,&local_7c,0x44,0x762,&DAT_00c81851);
        local_bc = local_bc & 0xffffdfff;
        local_b0 = (local_b0 >> 8 & 0xffffff) << 8;
        local_a8._0_5_ = CONCAT14(1,(undefined4)local_a8);
        local_a0 = 1;
        local_b8 = (ulong)param_2 << 0x20 | 0x2b0c;
        nvswitch_inforom_ecc_log_err_event(param_1,&local_b8);
      }
      if (local_bc != 0) {
        iVar4 = nvswitch_translate_hw_error(0x2713);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        lVar6 = *param_1;
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                          ,param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44),
                          *(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x2713,
                          "_nvswitch_service_ingress_fatal_lr10",0x76c);
        nvswitch_os_report_error
                  (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                   "_nvswitch_service_ingress_fatal_lr10",0x76c);
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                   "_nvswitch_service_ingress_fatal_lr10",0x76c);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
        nvswitch_record_error
                  (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_bc,4,0x76c,&DAT_00c81851);
      }
      if ((char)param_1[(ulong)param_2 * 8 + 0x1ed] != '\0') {
        (*(code *)param_1[0x125])(param_1,5,0,param_2,0x1408,local_94._4_4_ ^ uVar10);
      }
      if (((uint)local_94 & local_9c._4_4_) != 0) {
        (*(code *)param_1[0x125])(param_1,5,0,param_2,0x141c);
      }
      (*(code *)param_1[0x125])(param_1,5,0,param_2,0x1400,uVar10);
      if (local_bc == 0) {
        uVar12 = 0;
      }
      else {
        uVar12 = 0xfffffff6;
      }
    }
    return uVar12;
  }
  puVar8 = &local_9c;
  for (lVar6 = 8; lVar6 != 0; lVar6 = lVar6 + -1) {
    *(undefined4 *)puVar8 = 0;
    puVar8 = (undefined8 *)((long)puVar8 + 4);
  }
  puVar8 = &local_7c;
  for (lVar6 = 0x11; lVar6 != 0; lVar6 = lVar6 + -1) {
    *(undefined4 *)puVar8 = 0;
    puVar8 = (undefined8 *)((long)puVar8 + 4);
  }
  puVar9 = &local_b8;
  for (lVar6 = 7; lVar6 != 0; lVar6 = lVar6 + -1) {
    *(undefined4 *)puVar9 = 0;
    puVar9 = (ulong *)((long)puVar9 + 4);
  }
  uVar2 = (*pcVar1)(param_1,5,0,param_2,0x1400);
  local_9c = CONCAT44(local_9c._4_4_,uVar2);
  uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x1408);
  local_94 = CONCAT44(uVar2,(uint)local_94);
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001ce022 _nvswitch_service_egress_fatal_lr10.cold =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_service_egress_fatal_lr10_cold(void)

{
  code *pcVar1;
  undefined4 uVar2;
  long lVar3;
  long unaff_RBX;
  long unaff_RBP;
  undefined4 *puVar4;
  code *in_R9;
  
  puVar4 = (undefined4 *)(unaff_RBP + -0x11c);
  for (lVar3 = 8; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined4 *)(unaff_RBP + -0xfc);
  for (lVar3 = 0x11; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined4 *)(unaff_RBP + -0xb8);
  for (lVar3 = 0x11; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined4 *)(unaff_RBP + -0x74);
  for (lVar3 = 0x11; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined4 *)(unaff_RBP + -0x138);
  for (lVar3 = 7; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  uVar2 = (*in_R9)();
  *(undefined4 *)(unaff_RBP + -0x11c) = uVar2;
  uVar2 = (**(code **)(unaff_RBX + 0x920))();
  *(undefined4 *)(unaff_RBP + -0x110) = uVar2;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001ce0c0 _nvswitch_service_egress_fatal_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _nvswitch_service_egress_fatal_lr10(long *param_1,uint param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  long lVar7;
  char *pcVar8;
  long *plVar9;
  undefined8 *puVar10;
  ulong *puVar11;
  uint uVar12;
  bool bVar13;
  undefined8 uVar14;
  long *local_170;
  long *local_168;
  long *local_160;
  long *local_158;
  long *local_150;
  uint local_144;
  ulong local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined4 local_128;
  undefined8 local_124;
  undefined8 local_11c;
  undefined8 local_114;
  undefined8 local_10c;
  undefined8 local_104;
  undefined8 local_fc;
  undefined8 local_f4;
  undefined8 local_ec;
  undefined8 local_e4;
  undefined8 local_dc;
  undefined8 local_d4;
  undefined8 local_cc;
  undefined4 local_c4;
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
  undefined8 local_74;
  undefined8 local_6c;
  undefined8 local_64;
  undefined8 local_5c;
  undefined8 local_54;
  undefined8 local_4c;
  undefined8 local_44;
  undefined4 local_3c;
  
  pcVar1 = (code *)param_1[0x124];
  if ((int)param_1[0x3f1] != 6) {
    puVar10 = &local_124;
    for (lVar7 = 8; lVar7 != 0; lVar7 = lVar7 + -1) {
      *(undefined4 *)puVar10 = 0;
      puVar10 = (undefined8 *)((long)puVar10 + 4);
    }
    puVar10 = &local_104;
    for (lVar7 = 0x11; lVar7 != 0; lVar7 = lVar7 + -1) {
      *(undefined4 *)puVar10 = 0;
      puVar10 = (undefined8 *)((long)puVar10 + 4);
    }
    puVar10 = &local_c0;
    for (lVar7 = 0x11; lVar7 != 0; lVar7 = lVar7 + -1) {
      *(undefined4 *)puVar10 = 0;
      puVar10 = (undefined8 *)((long)puVar10 + 4);
    }
    puVar10 = &local_7c;
    for (lVar7 = 0x11; lVar7 != 0; lVar7 = lVar7 + -1) {
      *(undefined4 *)puVar10 = 0;
      puVar10 = (undefined8 *)((long)puVar10 + 4);
    }
    lVar7 = 7;
    puVar11 = &local_140;
    while( true ) {
      if (lVar7 == 0) break;
      lVar7 = lVar7 + -1;
      *(undefined4 *)puVar11 = 0;
      puVar11 = (ulong *)((long)puVar11 + 4);
    }
    uVar2 = (*pcVar1)(param_1,5,0,param_2,0x4400);
    local_124 = CONCAT44(local_124._4_4_,uVar2);
    uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4408);
    local_11c = CONCAT44(uVar2,(uint)local_11c);
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  lVar7 = param_1[0x3f2];
  local_124 = 0;
  local_11c = 0;
  local_114 = 0;
  local_10c = 0;
  local_104 = 0;
  local_fc = 0;
  local_f4 = 0;
  local_ec = 0;
  local_e4 = 0;
  local_dc = 0;
  local_d4 = 0;
  local_cc = 0;
  local_c4 = 0;
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
  local_140 = 0;
  local_138 = 0;
  local_130 = 0;
  local_128 = 0;
  uVar2 = (*pcVar1)(param_1,5,0,param_2,0x4400);
  local_124 = CONCAT44(local_124._4_4_,uVar2);
  uVar3 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4408);
  local_124 = CONCAT44(uVar3 & *(uint *)(&DAT_00009ac0 + lVar7),(uint)local_124);
  uVar12 = uVar3 & *(uint *)(&DAT_00009ac0 + lVar7) & (uint)local_124;
  if (uVar12 == 0) {
    uVar14 = 0xfffffffd;
  }
  else {
    local_144 = uVar12;
    local_11c._4_4_ = uVar3;
    uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x441c);
    local_11c = CONCAT44(local_11c._4_4_,uVar2);
    uVar3 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4414);
    _nvswitch_collect_error_info_lr10(param_1,param_2,0x1c0,&local_104);
    if ((uVar12 & 1) != 0) {
      local_150._0_4_ = uVar3 & 1;
      if ((uVar3 & 1) == 0) {
        iVar4 = nvswitch_translate_hw_error(0x2ee1);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 1) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2ee1,param_2
                          ,"egress crossbar overflow",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 1) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2ee1,"Non-fatal, Link %02d %s%s\n",param_2,
                   "egress crossbar overflow",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 1) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2ee1,"Non-fatal, Link %02d %s%s\n",param_2,"egress crossbar overflow",
                   pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2ee1,0,0,0);
        local_158 = param_1 + 0x24;
        nvswitch_record_error
                  (param_1,local_158,0x2ee1,param_2,0,1,0,0,&local_124,0x20,0x9f9,
                   "\"egress crossbar overflow\"");
        nvswitch_lib_notify_client_events(param_1,1);
        uVar14 = 0;
      }
      else {
        iVar4 = nvswitch_translate_hw_error(0x2ee1);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 1) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2ee1,param_2
                          ,"egress crossbar overflow",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 1) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2ee1,"Fatal, Link %02d %s%s\n",param_2,"egress crossbar overflow",
                   pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 1) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2ee1,"Fatal, Link %02d %s%s\n",param_2,"egress crossbar overflow",
                   pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2ee1,0,0,0);
        local_158 = param_1 + 0x1f;
        nvswitch_record_error
                  (param_1,local_158,0x2ee1,param_2,0,1,1,0,&local_124,0x20,0x9f9,
                   "\"egress crossbar overflow\"");
        nvswitch_set_fatal_error(param_1,1,param_2);
        nvswitch_lib_notify_client_events(param_1,0);
        uVar14 = 1;
      }
      nvswitch_record_error
                (param_1,local_158,0x2ee1,param_2,0,1,uVar14,0,&local_104,0x44,0x9fa,&DAT_00c81851);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4310);
      local_7c = CONCAT44(uVar2,(undefined4)local_7c);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4314);
      local_74 = CONCAT44(local_74._4_4_,uVar2);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4318);
      local_74 = CONCAT44(uVar2,(undefined4)local_74);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x431c);
      local_6c = CONCAT44(local_6c._4_4_,uVar2);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4320);
      local_6c = CONCAT44(uVar2,(undefined4)local_6c);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4324);
      local_64 = CONCAT44(local_64._4_4_,uVar2);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4328);
      local_64 = CONCAT44(uVar2,(undefined4)local_64);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x432c);
      local_5c = CONCAT44(local_5c._4_4_,uVar2);
      if ((uint)local_150 == 0) {
        plVar9 = param_1 + 0x24;
      }
      else {
        plVar9 = param_1 + 0x1f;
      }
      nvswitch_record_error
                (param_1,plVar9,0x2ee1,param_2,0,1,(uint)local_150 != 0,0,&local_7c,0x44,0xa04,
                 &DAT_00c81851);
      local_144 = local_144 & 0xfffffffe;
    }
    if ((uVar12 & 2) != 0) {
      if ((uVar3 & 2) == 0) {
        iVar4 = nvswitch_translate_hw_error(0x2ee2);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 2) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2ee2,param_2
                          ,"egress packet route",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 2) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2ee2,"Non-fatal, Link %02d %s%s\n",param_2,"egress packet route",
                   pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 2) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2ee2,"Non-fatal, Link %02d %s%s\n",param_2,"egress packet route",pcVar8
                  );
        nvswitch_inforom_bbx_add_sxid(param_1,0x2ee2,0,0,0);
        local_150 = param_1 + 0x24;
        nvswitch_record_error
                  (param_1,local_150,0x2ee2,param_2,0,1,0,0,&local_124,0x20,0xa0b,
                   "\"egress packet route\"");
        nvswitch_lib_notify_client_events(param_1,1);
        uVar14 = 0;
      }
      else {
        iVar4 = nvswitch_translate_hw_error(0x2ee2);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 2) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2ee2,param_2
                          ,"egress packet route",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 2) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2ee2,"Fatal, Link %02d %s%s\n",param_2,"egress packet route",pcVar8)
        ;
        pcVar8 = " (First)";
        if ((local_11c & 2) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2ee2,"Fatal, Link %02d %s%s\n",param_2,"egress packet route",pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2ee2,0,0,0);
        local_150 = param_1 + 0x1f;
        nvswitch_record_error
                  (param_1,local_150,0x2ee2,param_2,0,1,1,0,&local_124,0x20,0xa0b,
                   "\"egress packet route\"");
        nvswitch_set_fatal_error(param_1,1,param_2);
        nvswitch_lib_notify_client_events(param_1,0);
        uVar14 = 1;
      }
      nvswitch_record_error
                (param_1,local_150,0x2ee2,param_2,0,1,uVar14,0,&local_104,0x44,0xa0c,&DAT_00c81851);
      local_144 = local_144 & 0xfffffffd;
    }
    if ((uVar12 & 4) != 0) {
      if ((uVar3 & 4) == 0) {
        iVar4 = nvswitch_translate_hw_error(0x2ef4);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 4) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2ef4,param_2
                          ,"egress sequence ID error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 4) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2ef4,"Non-fatal, Link %02d %s%s\n",param_2,
                   "egress sequence ID error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 4) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2ef4,"Non-fatal, Link %02d %s%s\n",param_2,"egress sequence ID error",
                   pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2ef4,0,0,0);
        local_150 = param_1 + 0x24;
        nvswitch_record_error
                  (param_1,local_150,0x2ef4,param_2,0,1,0,0,&local_124,0x20,0xa13,
                   "\"egress sequence ID error\"");
        nvswitch_lib_notify_client_events(param_1,1);
        uVar14 = 0;
      }
      else {
        iVar4 = nvswitch_translate_hw_error(0x2ef4);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 4) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2ef4,param_2
                          ,"egress sequence ID error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 4) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2ef4,"Fatal, Link %02d %s%s\n",param_2,"egress sequence ID error",
                   pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 4) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2ef4,"Fatal, Link %02d %s%s\n",param_2,"egress sequence ID error",
                   pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2ef4,0,0,0);
        local_150 = param_1 + 0x1f;
        nvswitch_record_error
                  (param_1,local_150,0x2ef4,param_2,0,1,1,0,&local_124,0x20,0xa13,
                   "\"egress sequence ID error\"");
        nvswitch_set_fatal_error(param_1,1,param_2);
        nvswitch_lib_notify_client_events(param_1,0);
        uVar14 = 1;
      }
      nvswitch_record_error
                (param_1,local_150,0x2ef4,param_2,0,1,uVar14,0,&local_104,0x44,0xa14,&DAT_00c81851);
      local_144 = local_144 & 0xfffffffb;
    }
    uVar6 = (ulong)param_2;
    if ((uVar12 & 0x10) != 0) {
      if ((uVar3 & 0x10) == 0) {
        iVar4 = nvswitch_translate_hw_error(0x2ef6);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 0x10) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2ef6,param_2
                          ,"egress input ECC DBE error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x10) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2ef6,"Non-fatal, Link %02d %s%s\n",param_2,
                   "egress input ECC DBE error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x10) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2ef6,"Non-fatal, Link %02d %s%s\n",param_2,"egress input ECC DBE error"
                   ,pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2ef6,0,0,0);
        local_160 = param_1 + 0x24;
        nvswitch_record_error
                  (param_1,local_160,0x2ef6,param_2,0,1,0,0,&local_124,0x20,0xa1b,
                   "\"egress input ECC DBE error\"");
        nvswitch_lib_notify_client_events(param_1,1);
        uVar14 = 0;
      }
      else {
        iVar4 = nvswitch_translate_hw_error(0x2ef6);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 0x10) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2ef6,param_2
                          ,"egress input ECC DBE error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x10) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2ef6,"Fatal, Link %02d %s%s\n",param_2,"egress input ECC DBE error",
                   pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x10) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2ef6,"Fatal, Link %02d %s%s\n",param_2,"egress input ECC DBE error",
                   pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2ef6,0,0,0);
        local_160 = param_1 + 0x1f;
        nvswitch_record_error
                  (param_1,local_160,0x2ef6,param_2,0,1,1,0,&local_124,0x20,0xa1b,
                   "\"egress input ECC DBE error\"");
        nvswitch_set_fatal_error(param_1,0,param_2);
        nvswitch_lib_notify_client_events(param_1,0);
        uVar14 = 1;
      }
      nvswitch_record_error
                (param_1,local_160,0x2ef6,param_2,0,1,uVar14,0,&local_104,0x44,0xa1c,&DAT_00c81851);
      local_144 = local_144 & 0xffffffef;
      local_138 = (local_138 >> 8 & 0xffffff) << 8;
      local_130._0_5_ = CONCAT14(1,(undefined4)local_130);
      local_128 = 1;
      local_140 = (ulong)param_2 << 0x20 | 0x2ef6;
      nvswitch_inforom_ecc_log_err_event(param_1,&local_140);
      if ((local_124 & 8) != 0) {
        (*(code *)param_1[0x125])(param_1,5,0,param_2,0x4400,8);
      }
    }
    if ((uVar12 & 0x40) != 0) {
      uVar5 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4498);
      bVar13 = (uVar5 & 1) != 0;
      uVar5 = uVar5 & 1;
      if (bVar13) {
        uVar5 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4494);
      }
      if ((uVar3 & 0x40) == 0) {
        iVar4 = nvswitch_translate_hw_error(0x2ef8);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 0x40) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2ef8,param_2
                          ,"egress output ECC DBE error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x40) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2ef8,"Non-fatal, Link %02d %s%s\n",param_2,
                   "egress output ECC DBE error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x40) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2ef8,"Non-fatal, Link %02d %s%s\n",param_2,
                   "egress output ECC DBE error",pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2ef8,0,0,0);
        local_170 = param_1 + 0x24;
        nvswitch_record_error
                  (param_1,local_170,0x2ef8,param_2,0,1,0,0,&local_124,0x20,0xa3d,
                   "\"egress output ECC DBE error\"");
        nvswitch_lib_notify_client_events(param_1,1);
        uVar14 = 0;
      }
      else {
        iVar4 = nvswitch_translate_hw_error(0x2ef8);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 0x40) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2ef8,param_2
                          ,"egress output ECC DBE error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x40) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2ef8,"Fatal, Link %02d %s%s\n",param_2,"egress output ECC DBE error"
                   ,pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x40) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2ef8,"Fatal, Link %02d %s%s\n",param_2,"egress output ECC DBE error",
                   pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2ef8,0,0,0);
        local_170 = param_1 + 0x1f;
        nvswitch_record_error
                  (param_1,local_170,0x2ef8,param_2,0,1,1,0,&local_124,0x20,0xa3d,
                   "\"egress output ECC DBE error\"");
        nvswitch_set_fatal_error(param_1,0,param_2);
        nvswitch_lib_notify_client_events(param_1,0);
        uVar14 = 1;
      }
      nvswitch_record_error
                (param_1,local_170,0x2ef8,param_2,0,1,uVar14,0,&local_104,0x44,0xa3e,&DAT_00c81851);
      local_144 = local_144 & 0xffffffbf;
      local_130._0_5_ = CONCAT14(1,(undefined4)local_130);
      local_138 = CONCAT71(local_138._1_7_,bVar13);
      local_128 = 1;
      local_138 = CONCAT44(uVar5,(undefined4)local_138);
      local_140 = uVar6 << 0x20 | 0x2ef8;
      nvswitch_inforom_ecc_log_err_event(param_1,&local_140);
      if ((local_124 & 0x20) != 0) {
        (*(code *)param_1[0x125])(param_1,5,0,param_2,0x4400,0x20);
      }
    }
    if ((uVar12 & 0x80) != 0) {
      local_158._0_4_ = uVar3 & 0x80;
      if ((uVar3 & 0x80) == 0) {
        iVar4 = nvswitch_translate_hw_error(0x2ef9);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 0x80) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2ef9,param_2
                          ,"egress credit overflow",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x80) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2ef9,"Non-fatal, Link %02d %s%s\n",param_2,"egress credit overflow",
                   pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x80) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2ef9,"Non-fatal, Link %02d %s%s\n",param_2,"egress credit overflow",
                   pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2ef9,0,0,0);
        local_160 = param_1 + 0x24;
        nvswitch_record_error
                  (param_1,local_160,0x2ef9,param_2,0,1,0,0,&local_124,0x20,0xa52,
                   "\"egress credit overflow\"");
        nvswitch_lib_notify_client_events(param_1,1);
        uVar14 = 0;
      }
      else {
        iVar4 = nvswitch_translate_hw_error(0x2ef9);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 0x80) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2ef9,param_2
                          ,"egress credit overflow",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x80) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2ef9,"Fatal, Link %02d %s%s\n",param_2,"egress credit overflow",
                   pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x80) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2ef9,"Fatal, Link %02d %s%s\n",param_2,"egress credit overflow",pcVar8)
        ;
        nvswitch_inforom_bbx_add_sxid(param_1,0x2ef9,0,0,0);
        local_160 = param_1 + 0x1f;
        nvswitch_record_error
                  (param_1,local_160,0x2ef9,param_2,0,1,1,0,&local_124,0x20,0xa52,
                   "\"egress credit overflow\"");
        nvswitch_set_fatal_error(param_1,0,param_2);
        nvswitch_lib_notify_client_events(param_1,0);
        uVar14 = 1;
      }
      nvswitch_record_error
                (param_1,local_160,0x2ef9,param_2,0,1,uVar14,0,&local_104,0x44,0xa53,&DAT_00c81851);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4370);
      local_c0 = CONCAT44(uVar2,(undefined4)local_c0);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4374);
      local_b8 = CONCAT44(local_b8._4_4_,uVar2);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4378);
      local_b8 = CONCAT44(uVar2,(undefined4)local_b8);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x437c);
      local_b0 = CONCAT44(local_b0._4_4_,uVar2);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4380);
      local_b0 = CONCAT44(uVar2,(undefined4)local_b0);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4384);
      local_a8 = CONCAT44(local_a8._4_4_,uVar2);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4388);
      local_a8 = CONCAT44(uVar2,(undefined4)local_a8);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x438c);
      local_a0 = CONCAT44(local_a0._4_4_,uVar2);
      if ((uint)local_158 == 0) {
        plVar9 = param_1 + 0x24;
      }
      else {
        plVar9 = param_1 + 0x1f;
      }
      nvswitch_record_error
                (param_1,plVar9,0x2ef9,param_2,0,1,(uint)local_158 != 0,0,&local_c0,0x44,0xa5d,
                 &DAT_00c81851);
      local_144 = local_144 & 0xffffff7f;
    }
    if ((uVar12 & 0x100) != 0) {
      if ((uVar3 & 0x100) == 0) {
        iVar4 = nvswitch_translate_hw_error(0x2efa);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 0x100) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2efa,param_2
                          ,"egress destination request ID error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x100) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2efa,"Non-fatal, Link %02d %s%s\n",param_2,
                   "egress destination request ID error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x100) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2efa,"Non-fatal, Link %02d %s%s\n",param_2,
                   "egress destination request ID error",pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2efa,0,0,0);
        local_158 = param_1 + 0x24;
        nvswitch_record_error
                  (param_1,local_158,0x2efa,param_2,0,1,0,0,&local_124,0x20,0xa64,
                   "\"egress destination request ID error\"");
        nvswitch_lib_notify_client_events(param_1,1);
        uVar14 = 0;
      }
      else {
        iVar4 = nvswitch_translate_hw_error(0x2efa);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 0x100) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2efa,param_2
                          ,"egress destination request ID error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x100) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2efa,"Fatal, Link %02d %s%s\n",param_2,
                   "egress destination request ID error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x100) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2efa,"Fatal, Link %02d %s%s\n",param_2,
                   "egress destination request ID error",pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2efa,0,0,0);
        local_158 = param_1 + 0x1f;
        nvswitch_record_error
                  (param_1,local_158,0x2efa,param_2,0,1,1,0,&local_124,0x20,0xa64,
                   "\"egress destination request ID error\"");
        nvswitch_set_fatal_error(param_1,0,param_2);
        nvswitch_lib_notify_client_events(param_1,0);
        uVar14 = 1;
      }
      nvswitch_record_error
                (param_1,local_158,0x2efa,param_2,0,1,uVar14,0,&local_104,0x44,0xa65,&DAT_00c81851);
      local_144 = local_144 & 0xfffffeff;
    }
    if ((uVar12 & 0x200) != 0) {
      if ((uVar3 & 0x200) == 0) {
        iVar4 = nvswitch_translate_hw_error(0x2efb);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 0x200) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2efb,param_2
                          ,"egress destination response ID error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x200) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2efb,"Non-fatal, Link %02d %s%s\n",param_2,
                   "egress destination response ID error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x200) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2efb,"Non-fatal, Link %02d %s%s\n",param_2,
                   "egress destination response ID error",pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2efb,0,0,0);
        local_158 = param_1 + 0x24;
        nvswitch_record_error
                  (param_1,local_158,0x2efb,param_2,0,1,0,0,&local_124,0x20,0xa6c,
                   "\"egress destination response ID error\"");
        nvswitch_lib_notify_client_events(param_1,1);
        uVar14 = 0;
      }
      else {
        iVar4 = nvswitch_translate_hw_error(0x2efb);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 0x200) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2efb,param_2
                          ,"egress destination response ID error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x200) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2efb,"Fatal, Link %02d %s%s\n",param_2,
                   "egress destination response ID error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x200) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2efb,"Fatal, Link %02d %s%s\n",param_2,
                   "egress destination response ID error",pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2efb,0,0,0);
        local_158 = param_1 + 0x1f;
        nvswitch_record_error
                  (param_1,local_158,0x2efb,param_2,0,1,1,0,&local_124,0x20,0xa6c,
                   "\"egress destination response ID error\"");
        nvswitch_set_fatal_error(param_1,0,param_2);
        nvswitch_lib_notify_client_events(param_1,0);
        uVar14 = 1;
      }
      nvswitch_record_error
                (param_1,local_158,0x2efb,param_2,0,1,uVar14,0,&local_104,0x44,0xa6d,&DAT_00c81851);
      local_144 = local_144 & 0xfffffdff;
    }
    if ((uVar12 & 0x2000) != 0) {
      if ((uVar3 & 0x2000) == 0) {
        iVar4 = nvswitch_translate_hw_error(0x2efe);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 0x2000) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2efe,param_2
                          ,"egress control parity error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x2000) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2efe,"Non-fatal, Link %02d %s%s\n",param_2,
                   "egress control parity error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x2000) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2efe,"Non-fatal, Link %02d %s%s\n",param_2,
                   "egress control parity error",pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2efe,0,0,0);
        local_160 = param_1 + 0x24;
        nvswitch_record_error
                  (param_1,local_160,0x2efe,param_2,0,1,0,0,&local_124,0x20,0xa74,
                   "\"egress control parity error\"");
        nvswitch_lib_notify_client_events(param_1,1);
        uVar14 = 0;
      }
      else {
        iVar4 = nvswitch_translate_hw_error(0x2efe);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 0x2000) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2efe,param_2
                          ,"egress control parity error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x2000) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2efe,"Fatal, Link %02d %s%s\n",param_2,"egress control parity error"
                   ,pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x2000) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2efe,"Fatal, Link %02d %s%s\n",param_2,"egress control parity error",
                   pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2efe,0,0,0);
        local_160 = param_1 + 0x1f;
        nvswitch_record_error
                  (param_1,local_160,0x2efe,param_2,0,1,1,0,&local_124,0x20,0xa74,
                   "\"egress control parity error\"");
        nvswitch_set_fatal_error(param_1,0,param_2);
        nvswitch_lib_notify_client_events(param_1,0);
        uVar14 = 1;
      }
      nvswitch_record_error
                (param_1,local_160,0x2efe,param_2,0,1,uVar14,0,&local_104,0x44,0xa75,&DAT_00c81851);
      local_144 = local_144 & 0xffffdfff;
      local_138 = (local_138 >> 8 & 0xffffff) << 8;
      local_130._0_5_ = CONCAT14(1,(undefined4)local_130);
      local_128 = 1;
      local_140 = uVar6 << 0x20 | 0x2efe;
      nvswitch_inforom_ecc_log_err_event(param_1,&local_140);
    }
    if ((uVar12 & 0x4000) != 0) {
      local_158._0_4_ = uVar3 & 0x4000;
      if ((uVar3 & 0x4000) == 0) {
        iVar4 = nvswitch_translate_hw_error(0x2eff);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 0x4000) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2eff,param_2
                          ,"egress credit parity error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x4000) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2eff,"Non-fatal, Link %02d %s%s\n",param_2,
                   "egress credit parity error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x4000) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2eff,"Non-fatal, Link %02d %s%s\n",param_2,"egress credit parity error"
                   ,pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2eff,0,0,0);
        local_168 = param_1 + 0x24;
        nvswitch_record_error
                  (param_1,local_168,0x2eff,param_2,0,1,0,0,&local_124,0x20,0xa82,
                   "\"egress credit parity error\"");
        nvswitch_lib_notify_client_events(param_1,1);
        uVar14 = 0;
      }
      else {
        iVar4 = nvswitch_translate_hw_error(0x2eff);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 0x4000) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2eff,param_2
                          ,"egress credit parity error",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x4000) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2eff,"Fatal, Link %02d %s%s\n",param_2,"egress credit parity error",
                   pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x4000) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2eff,"Fatal, Link %02d %s%s\n",param_2,"egress credit parity error",
                   pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2eff,0,0,0);
        local_168 = param_1 + 0x1f;
        nvswitch_record_error
                  (param_1,local_168,0x2eff,param_2,0,1,1,0,&local_124,0x20,0xa82,
                   "\"egress credit parity error\"");
        nvswitch_set_fatal_error(param_1,0,param_2);
        nvswitch_lib_notify_client_events(param_1,0);
        uVar14 = 1;
      }
      nvswitch_record_error
                (param_1,local_168,0x2eff,param_2,0,1,uVar14,0,&local_104,0x44,0xa83,&DAT_00c81851);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4370);
      local_c0 = CONCAT44(uVar2,(undefined4)local_c0);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4374);
      local_b8 = CONCAT44(local_b8._4_4_,uVar2);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4378);
      local_b8 = CONCAT44(uVar2,(undefined4)local_b8);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x437c);
      local_b0 = CONCAT44(local_b0._4_4_,uVar2);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4380);
      local_b0 = CONCAT44(uVar2,(undefined4)local_b0);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4384);
      local_a8 = CONCAT44(local_a8._4_4_,uVar2);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x4388);
      local_a8 = CONCAT44(uVar2,(undefined4)local_a8);
      uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x438c);
      local_a0 = CONCAT44(local_a0._4_4_,uVar2);
      if ((uint)local_158 == 0) {
        plVar9 = param_1 + 0x24;
      }
      else {
        plVar9 = param_1 + 0x1f;
      }
      nvswitch_record_error
                (param_1,plVar9,0x2eff,param_2,0,1,(uint)local_158 != 0,0,&local_c0,0x44,0xa8d,
                 &DAT_00c81851);
      local_144 = local_144 & 0xffffbfff;
      local_138 = (local_138 >> 8 & 0xffffff) << 8;
      local_130._0_5_ = CONCAT14(1,(undefined4)local_130);
      local_128 = 1;
      local_140 = uVar6 << 0x20 | 0x2eff;
      nvswitch_inforom_ecc_log_err_event(param_1,&local_140);
    }
    if ((uVar12 & 0x8000) != 0) {
      if ((uVar3 & 0x8000) == 0) {
        iVar4 = nvswitch_translate_hw_error(0x2f00);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 0x8000) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2f00,param_2
                          ,"egress flit type mismatch",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x8000) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2f00,"Non-fatal, Link %02d %s%s\n",param_2,
                   "egress flit type mismatch",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x8000) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2f00,"Non-fatal, Link %02d %s%s\n",param_2,"egress flit type mismatch",
                   pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2f00,0,0,0);
        local_158 = param_1 + 0x24;
        nvswitch_record_error
                  (param_1,local_158,0x2f00,param_2,0,1,0,0,&local_124,0x20,0xa9a,
                   "\"egress flit type mismatch\"");
        nvswitch_lib_notify_client_events(param_1,1);
        uVar14 = 0;
      }
      else {
        iVar4 = nvswitch_translate_hw_error(0x2f00);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        pcVar8 = " (First)";
        if ((local_11c & 0x8000) == 0) {
          pcVar8 = "";
        }
        lVar7 = *param_1;
        nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2f00,param_2
                          ,"egress flit type mismatch",pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x8000) == 0) {
          pcVar8 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2f00,"Fatal, Link %02d %s%s\n",param_2,"egress flit type mismatch",
                   pcVar8);
        pcVar8 = " (First)";
        if ((local_11c & 0x8000) == 0) {
          pcVar8 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2f00,"Fatal, Link %02d %s%s\n",param_2,"egress flit type mismatch",
                   pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2f00,0,0,0);
        local_158 = param_1 + 0x1f;
        nvswitch_record_error
                  (param_1,local_158,0x2f00,param_2,0,1,1,0,&local_124,0x20,0xa9a,
                   "\"egress flit type mismatch\"");
        nvswitch_set_fatal_error(param_1,0,param_2);
        nvswitch_lib_notify_client_events(param_1,0);
        uVar14 = 1;
      }
      nvswitch_record_error
                (param_1,local_158,0x2f00,param_2,0,1,uVar14,0,&local_104,0x44,0xa9b,&DAT_00c81851);
      local_144 = local_144 & 0xffff7fff;
    }
    if ((uVar12 & 0x10000) != 0) {
      if ((uVar3 & 0x10000) == 0) {
        iVar4 = nvswitch_translate_hw_error(0x2f01);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        lVar7 = *param_1;
        pcVar8 = "";
        if ((local_11c & 0x10000) != 0) {
          pcVar8 = " (First)";
        }
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2f01,param_2
                          ,"egress credit timeout",pcVar8);
        pcVar8 = "";
        if ((local_11c & 0x10000) != 0) {
          pcVar8 = " (First)";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2f01,"Non-fatal, Link %02d %s%s\n",param_2,"egress credit timeout",
                   pcVar8);
        pcVar8 = "";
        if ((local_11c & 0x10000) != 0) {
          pcVar8 = " (First)";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2f01,"Non-fatal, Link %02d %s%s\n",param_2,"egress credit timeout",
                   pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2f01,0,0,0);
        nvswitch_record_error
                  (param_1,param_1 + 0x24,0x2f01,param_2,0,1,0,0,&local_124,0x20,0xaa2,
                   "\"egress credit timeout\"");
        nvswitch_lib_notify_client_events(param_1,1);
        nvswitch_record_error
                  (param_1,param_1 + 0x24,0x2f01,param_2,0,1,0,0,&local_104,0x44,0xaa3,&DAT_00c81851
                  );
      }
      else {
        iVar4 = nvswitch_translate_hw_error(0x2f01);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        lVar7 = *param_1;
        pcVar8 = "";
        if ((local_11c & 0x10000) != 0) {
          pcVar8 = " (First)";
        }
        nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                          *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2f01,param_2
                          ,"egress credit timeout",pcVar8);
        pcVar8 = "";
        if ((local_11c & 0x10000) != 0) {
          pcVar8 = " (First)";
        }
        nvswitch_os_report_error
                  (param_1[3],0x2f01,"Fatal, Link %02d %s%s\n",param_2,"egress credit timeout",
                   pcVar8);
        pcVar8 = "";
        if ((local_11c & 0x10000) != 0) {
          pcVar8 = " (First)";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2f01,"Fatal, Link %02d %s%s\n",param_2,"egress credit timeout",pcVar8);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2f01,0,0,0);
        nvswitch_record_error
                  (param_1,param_1 + 0x1f,0x2f01,param_2,0,1,1,0,&local_124,0x20,0xaa2,
                   "\"egress credit timeout\"");
        nvswitch_set_fatal_error(param_1,0,param_2);
        nvswitch_lib_notify_client_events(param_1,0);
        nvswitch_record_error
                  (param_1,param_1 + 0x1f,0x2f01,param_2,0,1,1,0,&local_104,0x44,0xaa3,&DAT_00c81851
                  );
      }
      local_144 = local_144 & 0xfffeffff;
    }
    if (local_144 != 0) {
      iVar4 = nvswitch_translate_hw_error(0x2713);
      if (iVar4 == 1) {
        nvswitch_assert_log();
      }
      lVar7 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                        ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),*(undefined1 *)(lVar7 + 0x44),
                        *(undefined1 *)(lVar7 + 0x45),*(undefined1 *)(lVar7 + 0x46),0x2713,
                        "_nvswitch_service_egress_fatal_lr10",0xaa7);
      nvswitch_os_report_error
                (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_egress_fatal_lr10",0xaa7);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_egress_fatal_lr10",0xaa7);
      nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_144,4,0xaa7,&DAT_00c81851);
    }
    if ((char)param_1[uVar6 * 8 + 0x1ed] != '\0') {
      (*(code *)param_1[0x125])(param_1,5,0,param_2,0x4408,local_11c._4_4_ ^ uVar12);
    }
    if (((uint)local_11c & local_124._4_4_) != 0) {
      (*(code *)param_1[0x125])(param_1,5,0,param_2,0x441c);
    }
    (*(code *)param_1[0x125])(param_1,5,0,param_2,0x4400,uVar12);
    if (local_144 == 0) {
      uVar14 = 0;
    }
    else {
      uVar14 = 0xfffffff6;
    }
  }
  return uVar14;
}


// ===== 001d11ba _nvswitch_service_npg_fatal_lr10.cold =====

void _nvswitch_service_npg_fatal_lr10_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  undefined8 unaff_R15;
  
  *(undefined8 *)(unaff_RBP + -8) = unaff_R15;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001d12b0 _nvswitch_service_npg_fatal_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

uint _nvswitch_service_npg_fatal_lr10(long *param_1,int param_2)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  long lVar13;
  char *pcVar14;
  undefined8 *puVar15;
  ulong uVar16;
  uint uVar17;
  bool bVar18;
  byte bVar19;
  int local_e8;
  uint local_e4;
  uint local_d8;
  uint local_c0;
  uint local_bc;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined8 local_9c;
  undefined8 local_94;
  undefined8 local_8c;
  ulong local_84;
  undefined8 local_7c;
  undefined8 local_74;
  undefined8 local_6c;
  undefined8 local_64;
  undefined8 local_5c;
  undefined8 local_54;
  undefined8 local_4c;
  undefined8 local_44;
  undefined4 local_3c;
  
  bVar19 = 0;
  uVar3 = (*(code *)param_1[0x124])(param_1,4,0,param_2,0x400);
  if (uVar3 == 0) {
    uVar3 = 0xfffffffd;
  }
  else {
    uVar12 = uVar3 & 0x2222;
    local_c0 = uVar12;
    if ((uVar3 & 2) != 0) {
      uVar17 = 0xffffffff;
      uVar3 = 2;
      goto LAB_001d1344;
    }
    if ((uVar3 & 0x20) != 0) {
      uVar3 = 0x20;
      uVar17 = 0;
      goto LAB_001d1344;
    }
    uVar17 = 1;
    do {
      uVar3 = *(uint *)(CSWTCH_776 + (ulong)uVar17 * 4);
      if ((uVar12 & uVar3) != 0) {
LAB_001d1344:
        uVar1 = uVar17 + 1 + param_2 * 4;
        uVar16 = (ulong)uVar1;
        if ((int)param_1[0x3f1] != 6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        if (*(char *)(uVar16 * 0x20 + param_1[0x3f2] + 0x68d0) != '\0') {
          iVar11 = _nvswitch_service_route_fatal_lr10(param_1,uVar1);
          iVar4 = _nvswitch_service_ingress_fatal_lr10(param_1,uVar1);
          iVar5 = _nvswitch_service_egress_fatal_lr10(param_1,uVar1);
          pcVar2 = (code *)param_1[0x124];
          if ((int)param_1[0x3f1] != 6) {
            puVar15 = &local_9c;
            for (lVar13 = 8; lVar13 != 0; lVar13 = lVar13 + -1) {
              *(undefined4 *)puVar15 = 0;
              puVar15 = (undefined8 *)((long)puVar15 + (ulong)bVar19 * -8 + 4);
            }
            puVar15 = &local_7c;
            for (lVar13 = 0x11; lVar13 != 0; lVar13 = lVar13 + -1) {
              *(undefined4 *)puVar15 = 0;
              puVar15 = (undefined8 *)((long)puVar15 + (ulong)bVar19 * -8 + 4);
            }
            puVar15 = &local_b8;
            for (lVar13 = 7; lVar13 != 0; lVar13 = lVar13 + -1) {
              *(undefined4 *)puVar15 = 0;
              puVar15 = (undefined8 *)((long)puVar15 + (ulong)bVar19 * -8 + 4);
            }
            uVar6 = (*pcVar2)(param_1,5,0,uVar16,0x3400);
            local_9c = CONCAT44(local_9c._4_4_,uVar6);
            uVar6 = (*(code *)param_1[0x124])(param_1,5,0,uVar16,0x3408);
            local_94 = CONCAT44(uVar6,(uint)local_94);
                    /* WARNING: Does not return */
            pcVar2 = (code *)invalidInstructionException();
            (*pcVar2)();
          }
          lVar13 = param_1[0x3f2];
          local_9c = 0;
          local_94 = 0;
          local_8c = 0;
          local_84 = 0;
          local_7c = 0;
          local_74 = 0;
          local_6c = 0;
          local_64 = 0;
          local_5c = 0;
          local_54 = 0;
          local_4c = 0;
          local_44 = 0;
          local_3c = 0;
          local_b8 = 0;
          local_b0 = 0;
          local_a8 = 0;
          local_a0 = 0;
          uVar6 = (*pcVar2)(param_1,5,0,uVar16,0x3400);
          local_9c = CONCAT44(local_9c._4_4_,uVar6);
          uVar7 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x3408);
          local_94 = CONCAT44(uVar7,(uint)local_94);
          local_9c = CONCAT44(uVar7 & *(uint *)(&DAT_00009acc + lVar13),(uint)local_9c);
          uVar6 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x3454);
          local_8c = CONCAT44(local_8c._4_4_,uVar6);
          uVar7 = (uint)local_9c & local_9c._4_4_;
          if (uVar7 == 0) {
            local_e8 = -3;
          }
          else {
            local_bc = uVar7;
            uVar6 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x341c);
            local_94 = CONCAT44(local_94._4_4_,uVar6);
            uVar8 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x3414);
            if ((uVar7 & 1) != 0) {
              if ((uVar8 & 1) == 0) {
                iVar9 = nvswitch_translate_hw_error(0x36b1);
                if (iVar9 == 1) {
                  nvswitch_assert_log();
                }
                lVar13 = *param_1;
                pcVar14 = "";
                if ((local_94 & 1) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),
                                  *(undefined1 *)(lVar13 + 0x44),*(undefined1 *)(lVar13 + 0x45),
                                  *(undefined1 *)(lVar13 + 0x46),0x36b1,uVar16,
                                  "TS pointer crossover",pcVar14);
                pcVar14 = "";
                if ((local_94 & 1) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_report_error
                          (param_1[3],0x36b1,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "TS pointer crossover",pcVar14);
                pcVar14 = "";
                if ((local_94 & 1) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x36b1,"Non-fatal, Link %02d %s%s\n",uVar1,"TS pointer crossover"
                           ,pcVar14);
                nvswitch_inforom_bbx_add_sxid(param_1,0x36b1,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x36b1,uVar1,0,1,0,0,&local_9c,0x20,0x8ae,
                           "\"TS pointer crossover\"");
                nvswitch_lib_notify_client_events(param_1,1);
                _nvswitch_collect_error_info_lr10(param_1,uVar1,0x1c0,&local_7c);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x36b1,uVar1,0,1,0,0,&local_7c,0x44,0x8b4,
                           &DAT_00c81851);
              }
              else {
                iVar9 = nvswitch_translate_hw_error(0x36b1);
                if (iVar9 == 1) {
                  nvswitch_assert_log();
                }
                lVar13 = *param_1;
                pcVar14 = "";
                if ((local_94 & 1) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),
                                  *(undefined1 *)(lVar13 + 0x44),*(undefined1 *)(lVar13 + 0x45),
                                  *(undefined1 *)(lVar13 + 0x46),0x36b1,uVar16,
                                  "TS pointer crossover",pcVar14);
                pcVar14 = "";
                if ((local_94 & 1) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_report_error
                          (param_1[3],0x36b1,"Fatal, Link %02d %s%s\n",uVar1,"TS pointer crossover",
                           pcVar14);
                pcVar14 = "";
                if ((local_94 & 1) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x36b1,"Fatal, Link %02d %s%s\n",uVar1,"TS pointer crossover",
                           pcVar14);
                nvswitch_inforom_bbx_add_sxid(param_1,0x36b1,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x1f,0x36b1,uVar1,0,1,1,0,&local_9c,0x20,0x8ae,
                           "\"TS pointer crossover\"");
                nvswitch_set_fatal_error(param_1,0,uVar1);
                nvswitch_lib_notify_client_events(param_1,0);
                _nvswitch_collect_error_info_lr10(param_1,uVar1,0x1c0,&local_7c);
                nvswitch_record_error
                          (param_1,param_1 + 0x1f,0x36b1,uVar1,0,1,1,0,&local_7c,0x44,0x8b4,
                           &DAT_00c81851);
              }
              local_bc = local_bc & 0xfffffffe;
            }
            if ((uVar7 & 4) != 0) {
              local_e4 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x349c);
              local_e4 = local_e4 & 1;
              bVar18 = local_e4 != 0;
              if (bVar18) {
                local_e4 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x3498);
              }
              uVar6 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x3490);
              local_8c = CONCAT44(uVar6,(undefined4)local_8c);
              (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x3490,0);
              if ((uVar8 & 4) == 0) {
                iVar9 = nvswitch_translate_hw_error(0x36b8);
                if (iVar9 == 1) {
                  nvswitch_assert_log();
                }
                lVar13 = *param_1;
                pcVar14 = "";
                if ((local_94 & 4) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),
                                  *(undefined1 *)(lVar13 + 0x44),*(undefined1 *)(lVar13 + 0x45),
                                  *(undefined1 *)(lVar13 + 0x46),0x36b8,uVar16,
                                  "TS tag store fatal ECC",pcVar14);
                pcVar14 = "";
                if ((local_94 & 4) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_report_error
                          (param_1[3],0x36b8,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "TS tag store fatal ECC",pcVar14);
                pcVar14 = "";
                if ((local_94 & 4) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x36b8,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "TS tag store fatal ECC",pcVar14);
                nvswitch_inforom_bbx_add_sxid(param_1,0x36b8,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x36b8,uVar1,0,1,0,0,&local_9c,0x20,0x8cb,
                           "\"TS tag store fatal ECC\"");
                nvswitch_lib_notify_client_events(param_1,1);
                _nvswitch_collect_error_info_lr10(param_1,uVar1,0x1c0,&local_7c);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x36b8,uVar1,0,1,0,0,&local_7c,0x44,0x8d1,
                           &DAT_00c81851);
              }
              else {
                iVar9 = nvswitch_translate_hw_error(0x36b8);
                if (iVar9 == 1) {
                  nvswitch_assert_log();
                }
                lVar13 = *param_1;
                pcVar14 = "";
                if ((local_94 & 4) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),
                                  *(undefined1 *)(lVar13 + 0x44),*(undefined1 *)(lVar13 + 0x45),
                                  *(undefined1 *)(lVar13 + 0x46),0x36b8,uVar16,
                                  "TS tag store fatal ECC",pcVar14);
                pcVar14 = "";
                if ((local_94 & 4) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_report_error
                          (param_1[3],0x36b8,"Fatal, Link %02d %s%s\n",uVar1,
                           "TS tag store fatal ECC",pcVar14);
                pcVar14 = "";
                if ((local_94 & 4) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x36b8,"Fatal, Link %02d %s%s\n",uVar1,"TS tag store fatal ECC",
                           pcVar14);
                nvswitch_inforom_bbx_add_sxid(param_1,0x36b8,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x1f,0x36b8,uVar1,0,1,1,0,&local_9c,0x20,0x8cb,
                           "\"TS tag store fatal ECC\"");
                nvswitch_set_fatal_error(param_1,0,uVar1);
                nvswitch_lib_notify_client_events(param_1,0);
                _nvswitch_collect_error_info_lr10(param_1,uVar1,0x1c0,&local_7c);
                nvswitch_record_error
                          (param_1,param_1 + 0x1f,0x36b8,uVar1,0,1,1,0,&local_7c,0x44,0x8d1,
                           &DAT_00c81851);
              }
              local_bc = local_bc & 0xfffffffb;
              local_b0 = CONCAT71(local_b0._1_7_,bVar18);
              local_b8 = CONCAT44(uVar1,0x36b8);
              local_b0 = CONCAT44(local_e4,(undefined4)local_b0);
              local_a8._0_5_ = CONCAT14(1,(undefined4)local_a8);
              local_a0 = 1;
              nvswitch_inforom_ecc_log_err_event(param_1,&local_b8);
              if ((local_9c & 2) != 0) {
                (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x3400,2);
              }
            }
            if ((uVar7 & 8) != 0) {
              if ((uVar8 & 8) == 0) {
                iVar9 = nvswitch_translate_hw_error(0x36b2);
                if (iVar9 == 1) {
                  nvswitch_assert_log();
                }
                lVar13 = *param_1;
                pcVar14 = "";
                if ((local_94 & 8) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),
                                  *(undefined1 *)(lVar13 + 0x44),*(undefined1 *)(lVar13 + 0x45),
                                  *(undefined1 *)(lVar13 + 0x46),0x36b2,uVar16,"TS crumbstore",
                                  pcVar14);
                pcVar14 = "";
                if ((local_94 & 8) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_report_error
                          (param_1[3],0x36b2,"Non-fatal, Link %02d %s%s\n",uVar1,"TS crumbstore",
                           pcVar14);
                pcVar14 = "";
                if ((local_94 & 8) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x36b2,"Non-fatal, Link %02d %s%s\n",uVar1,"TS crumbstore",
                           pcVar14);
                nvswitch_inforom_bbx_add_sxid(param_1,0x36b2,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x36b2,uVar1,0,1,0,0,&local_9c,0x20,0x8e5,
                           "\"TS crumbstore\"");
                nvswitch_lib_notify_client_events(param_1,1);
                _nvswitch_collect_error_info_lr10(param_1,uVar1,0x1c0,&local_7c);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x36b2,uVar1,0,1,0,0,&local_7c,0x44,0x8eb,
                           &DAT_00c81851);
              }
              else {
                iVar9 = nvswitch_translate_hw_error(0x36b2);
                if (iVar9 == 1) {
                  nvswitch_assert_log();
                }
                lVar13 = *param_1;
                pcVar14 = "";
                if ((local_94 & 8) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),
                                  *(undefined1 *)(lVar13 + 0x44),*(undefined1 *)(lVar13 + 0x45),
                                  *(undefined1 *)(lVar13 + 0x46),0x36b2,uVar16,"TS crumbstore",
                                  pcVar14);
                pcVar14 = "";
                if ((local_94 & 8) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_report_error
                          (param_1[3],0x36b2,"Fatal, Link %02d %s%s\n",uVar1,"TS crumbstore",pcVar14
                          );
                pcVar14 = "";
                if ((local_94 & 8) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x36b2,"Fatal, Link %02d %s%s\n",uVar1,"TS crumbstore",pcVar14);
                nvswitch_inforom_bbx_add_sxid(param_1,0x36b2,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x1f,0x36b2,uVar1,0,1,1,0,&local_9c,0x20,0x8e5,
                           "\"TS crumbstore\"");
                nvswitch_set_fatal_error(param_1,0,uVar1);
                nvswitch_lib_notify_client_events(param_1,0);
                _nvswitch_collect_error_info_lr10(param_1,uVar1,0x1c0,&local_7c);
                nvswitch_record_error
                          (param_1,param_1 + 0x1f,0x36b2,uVar1,0,1,1,0,&local_7c,0x44,0x8eb,
                           &DAT_00c81851);
              }
              local_bc = local_bc & 0xfffffff7;
            }
            if ((uVar7 & 0x20) != 0) {
              local_e4 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x348c);
              local_e4 = local_e4 & 1;
              bVar18 = local_e4 != 0;
              if (bVar18) {
                local_e4 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x3488);
              }
              uVar6 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x3480);
              local_8c = CONCAT44(uVar6,(undefined4)local_8c);
              (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x3480,0);
              if ((uVar8 & 0x20) == 0) {
                iVar9 = nvswitch_translate_hw_error(0x36ba);
                if (iVar9 == 1) {
                  nvswitch_assert_log();
                }
                lVar13 = *param_1;
                pcVar14 = "";
                if ((local_94 & 0x20) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),
                                  *(undefined1 *)(lVar13 + 0x44),*(undefined1 *)(lVar13 + 0x45),
                                  *(undefined1 *)(lVar13 + 0x46),0x36ba,uVar16,
                                  "TS crumbstore fatal ECC",pcVar14);
                pcVar14 = "";
                if ((local_94 & 0x20) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_report_error
                          (param_1[3],0x36ba,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "TS crumbstore fatal ECC",pcVar14);
                pcVar14 = "";
                if ((local_94 & 0x20) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x36ba,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "TS crumbstore fatal ECC",pcVar14);
                nvswitch_inforom_bbx_add_sxid(param_1,0x36ba,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x36ba,uVar1,0,1,0,0,&local_9c,0x20,0x902,
                           "\"TS crumbstore fatal ECC\"");
                nvswitch_lib_notify_client_events(param_1,1);
                _nvswitch_collect_error_info_lr10(param_1,uVar1,0x38,&local_7c);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x36ba,uVar1,0,1,0,0,&local_7c,0x44,0x908,
                           &DAT_00c81851);
              }
              else {
                iVar9 = nvswitch_translate_hw_error(0x36ba);
                if (iVar9 == 1) {
                  nvswitch_assert_log();
                }
                lVar13 = *param_1;
                pcVar14 = "";
                if ((local_94 & 0x20) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),
                                  *(undefined1 *)(lVar13 + 0x44),*(undefined1 *)(lVar13 + 0x45),
                                  *(undefined1 *)(lVar13 + 0x46),0x36ba,uVar16,
                                  "TS crumbstore fatal ECC",pcVar14);
                pcVar14 = "";
                if ((local_94 & 0x20) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_report_error
                          (param_1[3],0x36ba,"Fatal, Link %02d %s%s\n",uVar1,
                           "TS crumbstore fatal ECC",pcVar14);
                pcVar14 = "";
                if ((local_94 & 0x20) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x36ba,"Fatal, Link %02d %s%s\n",uVar1,"TS crumbstore fatal ECC",
                           pcVar14);
                nvswitch_inforom_bbx_add_sxid(param_1,0x36ba,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x1f,0x36ba,uVar1,0,1,1,0,&local_9c,0x20,0x902,
                           "\"TS crumbstore fatal ECC\"");
                nvswitch_set_fatal_error(param_1,0,uVar1);
                nvswitch_lib_notify_client_events(param_1,0);
                _nvswitch_collect_error_info_lr10(param_1,uVar1,0x38,&local_7c);
                nvswitch_record_error
                          (param_1,param_1 + 0x1f,0x36ba,uVar1,0,1,1,0,&local_7c,0x44,0x908,
                           &DAT_00c81851);
              }
              local_bc = local_bc & 0xffffffdf;
              local_b0 = CONCAT71(local_b0._1_7_,bVar18);
              local_b8 = CONCAT44(uVar1,0x36ba);
              local_b0 = CONCAT44(local_e4,(undefined4)local_b0);
              local_a8._0_5_ = CONCAT14(1,(undefined4)local_a8);
              local_a0 = 1;
              nvswitch_inforom_ecc_log_err_event(param_1,&local_b8);
              if ((local_9c & 0x10) != 0) {
                (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x3400,0x10);
              }
            }
            if ((uVar7 & 0x200) != 0) {
              if ((local_94 & 0x200) != 0) {
                uVar6 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x3420);
                local_8c = CONCAT44(uVar6,(undefined4)local_8c);
              }
              if ((uVar8 & 0x200) == 0) {
                iVar9 = nvswitch_translate_hw_error(0x36c1);
                if (iVar9 == 1) {
                  nvswitch_assert_log();
                }
                lVar13 = *param_1;
                pcVar14 = "";
                if ((local_94 & 0x200) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),
                                  *(undefined1 *)(lVar13 + 0x44),*(undefined1 *)(lVar13 + 0x45),
                                  *(undefined1 *)(lVar13 + 0x46),0x36c1,uVar16,"TS ATO timeout",
                                  pcVar14);
                pcVar14 = "";
                if ((local_94 & 0x200) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_report_error
                          (param_1[3],0x36c1,"Non-fatal, Link %02d %s%s\n",uVar1,"TS ATO timeout",
                           pcVar14);
                pcVar14 = "";
                if ((local_94 & 0x200) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x36c1,"Non-fatal, Link %02d %s%s\n",uVar1,"TS ATO timeout",
                           pcVar14);
                nvswitch_inforom_bbx_add_sxid(param_1,0x36c1,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x36c1,uVar1,0,1,0,0,&local_9c,0x20,0x920,
                           "\"TS ATO timeout\"");
                nvswitch_lib_notify_client_events(param_1,1);
              }
              else {
                iVar9 = nvswitch_translate_hw_error(0x36c1);
                if (iVar9 == 1) {
                  nvswitch_assert_log();
                }
                lVar13 = *param_1;
                pcVar14 = "";
                if ((local_94 & 0x200) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),
                                  *(undefined1 *)(lVar13 + 0x44),*(undefined1 *)(lVar13 + 0x45),
                                  *(undefined1 *)(lVar13 + 0x46),0x36c1,uVar16,"TS ATO timeout",
                                  pcVar14);
                pcVar14 = "";
                if ((local_94 & 0x200) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_report_error
                          (param_1[3],0x36c1,"Fatal, Link %02d %s%s\n",uVar1,"TS ATO timeout",
                           pcVar14);
                pcVar14 = "";
                if ((local_94 & 0x200) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x36c1,"Fatal, Link %02d %s%s\n",uVar1,"TS ATO timeout",pcVar14);
                nvswitch_inforom_bbx_add_sxid(param_1,0x36c1,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x1f,0x36c1,uVar1,0,1,1,0,&local_9c,0x20,0x920,
                           "\"TS ATO timeout\"");
                nvswitch_set_fatal_error(param_1,0,uVar1);
                nvswitch_lib_notify_client_events(param_1,0);
              }
              local_bc = local_bc & 0xfffffdff;
            }
            if ((uVar7 & 0x400) != 0) {
              if ((uVar8 & 0x400) == 0) {
                iVar9 = nvswitch_translate_hw_error(0x36c2);
                if (iVar9 == 1) {
                  nvswitch_assert_log();
                }
                lVar13 = *param_1;
                pcVar14 = "";
                if ((local_94 & 0x400) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),
                                  *(undefined1 *)(lVar13 + 0x44),*(undefined1 *)(lVar13 + 0x45),
                                  *(undefined1 *)(lVar13 + 0x46),0x36c2,uVar16,
                                  "Rsp Tag value out of range",pcVar14);
                pcVar14 = "";
                if ((local_94 & 0x400) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_report_error
                          (param_1[3],0x36c2,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "Rsp Tag value out of range",pcVar14);
                pcVar14 = "";
                if ((local_94 & 0x400) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x36c2,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "Rsp Tag value out of range",pcVar14);
                nvswitch_inforom_bbx_add_sxid(param_1,0x36c2,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x36c2,uVar1,0,1,0,0,&local_9c,0x20,0x927,
                           "\"Rsp Tag value out of range\"");
                nvswitch_lib_notify_client_events(param_1,1);
                _nvswitch_collect_error_info_lr10(param_1,uVar1,0x38,&local_7c);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x36c2,uVar1,0,1,0,0,&local_7c,0x44,0x92d,
                           &DAT_00c81851);
              }
              else {
                iVar9 = nvswitch_translate_hw_error(0x36c2);
                if (iVar9 == 1) {
                  nvswitch_assert_log();
                }
                lVar13 = *param_1;
                pcVar14 = "";
                if ((local_94 & 0x400) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),
                                  *(undefined1 *)(lVar13 + 0x44),*(undefined1 *)(lVar13 + 0x45),
                                  *(undefined1 *)(lVar13 + 0x46),0x36c2,uVar16,
                                  "Rsp Tag value out of range",pcVar14);
                pcVar14 = "";
                if ((local_94 & 0x400) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_os_report_error
                          (param_1[3],0x36c2,"Fatal, Link %02d %s%s\n",uVar1,
                           "Rsp Tag value out of range",pcVar14);
                pcVar14 = "";
                if ((local_94 & 0x400) != 0) {
                  pcVar14 = " (First)";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x36c2,"Fatal, Link %02d %s%s\n",uVar1,
                           "Rsp Tag value out of range",pcVar14);
                nvswitch_inforom_bbx_add_sxid(param_1,0x36c2,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x1f,0x36c2,uVar1,0,1,1,0,&local_9c,0x20,0x927,
                           "\"Rsp Tag value out of range\"");
                nvswitch_set_fatal_error(param_1,0,uVar1);
                nvswitch_lib_notify_client_events(param_1,0);
                _nvswitch_collect_error_info_lr10(param_1,uVar1,0x38,&local_7c);
                nvswitch_record_error
                          (param_1,param_1 + 0x1f,0x36c2,uVar1,0,1,1,0,&local_7c,0x44,0x92d,
                           &DAT_00c81851);
              }
              local_bc = local_bc & 0xfffffbff;
            }
            if (local_bc != 0) {
              iVar9 = nvswitch_translate_hw_error(0x2713);
              if (iVar9 == 1) {
                nvswitch_assert_log();
              }
              lVar13 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                                ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),
                                *(undefined1 *)(lVar13 + 0x44),*(undefined1 *)(lVar13 + 0x45),
                                *(undefined1 *)(lVar13 + 0x46),0x2713,
                                "_nvswitch_service_tstate_fatal_lr10",0x931);
              nvswitch_os_report_error
                        (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                         "_nvswitch_service_tstate_fatal_lr10",0x931);
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                         "_nvswitch_service_tstate_fatal_lr10",0x931);
              nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_bc,4,0x931,&DAT_00c81851);
            }
            if ((char)param_1[uVar16 * 8 + 0x1ed] != '\0') {
              (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x3408,uVar7 ^ local_94._4_4_);
            }
            if (((uint)local_94 & local_9c._4_4_) != 0) {
              (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x341c);
            }
            (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x3400,uVar7);
            if (local_bc == 0) {
              local_e8 = 0;
            }
            else {
              local_e8 = -10;
            }
          }
          pcVar2 = (code *)param_1[0x124];
          if ((int)param_1[0x3f1] != 6) {
            puVar15 = &local_7c;
            for (lVar13 = 8; lVar13 != 0; lVar13 = lVar13 + -1) {
              *(undefined4 *)puVar15 = 0;
              puVar15 = (undefined8 *)((long)puVar15 + (ulong)bVar19 * -8 + 4);
            }
            puVar15 = &local_9c;
            for (lVar13 = 7; lVar13 != 0; lVar13 = lVar13 + -1) {
              *(undefined4 *)puVar15 = 0;
              puVar15 = (undefined8 *)((long)puVar15 + (ulong)bVar19 * -8 + 4);
            }
            uVar6 = (*pcVar2)(param_1,5,0,uVar16,0x6400);
            local_7c = CONCAT44(local_7c._4_4_,uVar6);
            uVar6 = (*(code *)param_1[0x124])(param_1,5,0,uVar16,0x6408);
            local_74 = CONCAT44(uVar6,(uint)local_74);
                    /* WARNING: Does not return */
            pcVar2 = (code *)invalidInstructionException();
            (*pcVar2)();
          }
          lVar13 = param_1[0x3f2];
          local_7c = 0;
          local_74 = 0;
          local_6c = 0;
          local_64 = 0;
          local_9c = 0;
          local_94 = 0;
          local_8c = 0;
          local_84 = local_84 & 0xffffffff00000000;
          uVar6 = (*pcVar2)(param_1,5,0,uVar1,0x6400);
          local_7c = CONCAT44(local_7c._4_4_,uVar6);
          uVar7 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x6408);
          local_74 = CONCAT44(uVar7,(uint)local_74);
          local_7c = CONCAT44(uVar7 & *(uint *)(&DAT_00009ad8 + lVar13),(uint)local_7c);
          uVar7 = uVar7 & *(uint *)(&DAT_00009ad8 + lVar13) & (uint)local_7c;
          if (uVar7 == 0) {
LAB_001d39c2:
            if (((iVar11 != 0 && iVar4 != 0) && iVar5 != 0) && (local_e8 != 0)) goto LAB_001d1380;
          }
          else {
            local_b8 = CONCAT44(local_b8._4_4_,uVar7);
            uVar6 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x641c);
            local_74 = CONCAT44(local_74._4_4_,uVar6);
            uVar8 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x6414);
            if ((uVar7 & 0x100) != 0) {
              local_d8 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x648c);
              local_d8 = local_d8 & 1;
              bVar18 = local_d8 != 0;
              if (bVar18) {
                local_d8 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x6488);
              }
              uVar6 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x6488);
              local_6c = CONCAT44(local_6c._4_4_,uVar6);
              uVar6 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x648c);
              local_6c = CONCAT44(uVar6,(undefined4)local_6c);
              if ((uVar8 & 0x100) == 0) {
                iVar9 = nvswitch_translate_hw_error(0x5dc4);
                if (iVar9 == 1) {
                  nvswitch_assert_log();
                }
                pcVar14 = " (First)";
                if ((local_74 & 0x100) == 0) {
                  pcVar14 = "";
                }
                lVar13 = *param_1;
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),
                                  *(undefined1 *)(lVar13 + 0x44),*(undefined1 *)(lVar13 + 0x45),
                                  *(undefined1 *)(lVar13 + 0x46),0x5dc4,uVar16,
                                  "sourcetrack TCEN0 crumbstore DBE",pcVar14);
                pcVar14 = " (First)";
                if ((local_74 & 0x100) == 0) {
                  pcVar14 = "";
                }
                nvswitch_os_report_error
                          (param_1[3],0x5dc4,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "sourcetrack TCEN0 crumbstore DBE",pcVar14);
                pcVar14 = " (First)";
                if ((local_74 & 0x100) == 0) {
                  pcVar14 = "";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x5dc4,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "sourcetrack TCEN0 crumbstore DBE",pcVar14);
                nvswitch_inforom_bbx_add_sxid(param_1,0x5dc4,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x5dc4,uVar1,0,1,0,0,&local_7c,0x20,0xb76,
                           "\"sourcetrack TCEN0 crumbstore DBE\"");
                nvswitch_lib_notify_client_events(param_1,1);
              }
              else {
                iVar9 = nvswitch_translate_hw_error(0x5dc4);
                if (iVar9 == 1) {
                  nvswitch_assert_log();
                }
                pcVar14 = " (First)";
                if ((local_74 & 0x100) == 0) {
                  pcVar14 = "";
                }
                lVar13 = *param_1;
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),
                                  *(undefined1 *)(lVar13 + 0x44),*(undefined1 *)(lVar13 + 0x45),
                                  *(undefined1 *)(lVar13 + 0x46),0x5dc4,uVar16,
                                  "sourcetrack TCEN0 crumbstore DBE",pcVar14);
                pcVar14 = " (First)";
                if ((local_74 & 0x100) == 0) {
                  pcVar14 = "";
                }
                nvswitch_os_report_error
                          (param_1[3],0x5dc4,"Fatal, Link %02d %s%s\n",uVar1,
                           "sourcetrack TCEN0 crumbstore DBE",pcVar14);
                pcVar14 = " (First)";
                if ((local_74 & 0x100) == 0) {
                  pcVar14 = "";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x5dc4,"Fatal, Link %02d %s%s\n",uVar1,
                           "sourcetrack TCEN0 crumbstore DBE",pcVar14);
                nvswitch_inforom_bbx_add_sxid(param_1,0x5dc4,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x1f,0x5dc4,uVar1,0,1,1,0,&local_7c,0x20,0xb76,
                           "\"sourcetrack TCEN0 crumbstore DBE\"");
                nvswitch_set_fatal_error(param_1,0,uVar1);
                nvswitch_lib_notify_client_events(param_1,0);
              }
              local_b8 = local_b8 & 0xfffffffffffffeff;
              local_94 = CONCAT71(local_94._1_7_,bVar18);
              local_9c = CONCAT44(uVar1,0x5dc4);
              local_94 = CONCAT44(local_d8,(uint)local_94);
              local_8c._0_5_ = CONCAT14(1,(undefined4)local_8c);
              local_84 = CONCAT44(local_84._4_4_,1);
              nvswitch_inforom_ecc_log_err_event(param_1,&local_9c);
              if ((local_7c & 1) != 0) {
                (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x6400,1);
              }
            }
            if ((uVar7 & 0x8000) != 0) {
              local_d8 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x64ac);
              local_d8 = local_d8 & 1;
              bVar18 = local_d8 != 0;
              if (bVar18) {
                local_d8 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x64a8);
              }
              uVar6 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x64a8);
              local_6c = CONCAT44(local_6c._4_4_,uVar6);
              uVar6 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x64ac);
              local_6c = CONCAT44(uVar6,(undefined4)local_6c);
              if ((uVar8 & 0x8000) == 0) {
                iVar9 = nvswitch_translate_hw_error(0x5dc6);
                if (iVar9 == 1) {
                  nvswitch_assert_log();
                }
                pcVar14 = " (First)";
                if ((local_74 & 0x8000) == 0) {
                  pcVar14 = "";
                }
                lVar13 = *param_1;
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),
                                  *(undefined1 *)(lVar13 + 0x44),*(undefined1 *)(lVar13 + 0x45),
                                  *(undefined1 *)(lVar13 + 0x46),0x5dc6,uVar16,
                                  "sourcetrack TCEN1 crumbstore DBE",pcVar14);
                pcVar14 = " (First)";
                if ((local_74 & 0x8000) == 0) {
                  pcVar14 = "";
                }
                nvswitch_os_report_error
                          (param_1[3],0x5dc6,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "sourcetrack TCEN1 crumbstore DBE",pcVar14);
                pcVar14 = " (First)";
                if ((local_74 & 0x8000) == 0) {
                  pcVar14 = "";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x5dc6,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "sourcetrack TCEN1 crumbstore DBE",pcVar14);
                nvswitch_inforom_bbx_add_sxid(param_1,0x5dc6,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x5dc6,uVar1,0,1,0,0,&local_7c,0x20,0xb9c,
                           "\"sourcetrack TCEN1 crumbstore DBE\"");
                nvswitch_lib_notify_client_events(param_1,1);
              }
              else {
                iVar9 = nvswitch_translate_hw_error(0x5dc6);
                if (iVar9 == 1) {
                  nvswitch_assert_log();
                }
                pcVar14 = " (First)";
                if ((local_74 & 0x8000) == 0) {
                  pcVar14 = "";
                }
                lVar13 = *param_1;
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),
                                  *(undefined1 *)(lVar13 + 0x44),*(undefined1 *)(lVar13 + 0x45),
                                  *(undefined1 *)(lVar13 + 0x46),0x5dc6,uVar16,
                                  "sourcetrack TCEN1 crumbstore DBE",pcVar14);
                pcVar14 = " (First)";
                if ((local_74 & 0x8000) == 0) {
                  pcVar14 = "";
                }
                nvswitch_os_report_error
                          (param_1[3],0x5dc6,"Fatal, Link %02d %s%s\n",uVar1,
                           "sourcetrack TCEN1 crumbstore DBE",pcVar14);
                pcVar14 = " (First)";
                if ((local_74 & 0x8000) == 0) {
                  pcVar14 = "";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x5dc6,"Fatal, Link %02d %s%s\n",uVar1,
                           "sourcetrack TCEN1 crumbstore DBE",pcVar14);
                nvswitch_inforom_bbx_add_sxid(param_1,0x5dc6,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x1f,0x5dc6,uVar1,0,1,1,0,&local_7c,0x20,0xb9c,
                           "\"sourcetrack TCEN1 crumbstore DBE\"");
                nvswitch_set_fatal_error(param_1,0,uVar1);
                nvswitch_lib_notify_client_events(param_1,0);
              }
              local_b8 = local_b8 & 0xffffffffffff7fff;
              local_94 = CONCAT71(local_94._1_7_,bVar18);
              local_9c = CONCAT44(uVar1,0x5dc6);
              local_94 = CONCAT44(local_d8,(uint)local_94);
              local_8c._0_5_ = CONCAT14(1,(undefined4)local_8c);
              local_84 = CONCAT44(local_84._4_4_,1);
              nvswitch_inforom_ecc_log_err_event(param_1,&local_9c);
              if ((local_7c & 0x80) != 0) {
                (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x6400,0x80);
              }
            }
            uVar10 = (uint)local_b8;
            if ((uVar7 & 0x10000000) != 0) {
              if ((uVar8 & 0x10000000) == 0) {
                iVar9 = nvswitch_translate_hw_error(0x5dc7);
                if (iVar9 == 1) {
                  nvswitch_assert_log();
                }
                pcVar14 = " (First)";
                if ((local_74 & 0x10000000) == 0) {
                  pcVar14 = "";
                }
                lVar13 = *param_1;
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),
                                  *(undefined1 *)(lVar13 + 0x44),*(undefined1 *)(lVar13 + 0x45),
                                  *(undefined1 *)(lVar13 + 0x46),0x5dc7,uVar16,
                                  "sourcetrack timeout error",pcVar14);
                pcVar14 = " (First)";
                if ((local_74 & 0x10000000) == 0) {
                  pcVar14 = "";
                }
                nvswitch_os_report_error
                          (param_1[3],0x5dc7,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "sourcetrack timeout error",pcVar14);
                pcVar14 = " (First)";
                if ((local_74 & 0x10000000) == 0) {
                  pcVar14 = "";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x5dc7,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "sourcetrack timeout error",pcVar14);
                nvswitch_inforom_bbx_add_sxid(param_1,0x5dc7,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x5dc7,uVar1,0,1,0,0,&local_7c,0x20,0xbb1,
                           "\"sourcetrack timeout error\"");
                nvswitch_lib_notify_client_events(param_1,1);
              }
              else {
                iVar9 = nvswitch_translate_hw_error(0x5dc7);
                if (iVar9 == 1) {
                  nvswitch_assert_log();
                }
                pcVar14 = " (First)";
                if ((local_74 & 0x10000000) == 0) {
                  pcVar14 = "";
                }
                lVar13 = *param_1;
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),
                                  *(undefined1 *)(lVar13 + 0x44),*(undefined1 *)(lVar13 + 0x45),
                                  *(undefined1 *)(lVar13 + 0x46),0x5dc7,uVar16,
                                  "sourcetrack timeout error",pcVar14);
                pcVar14 = " (First)";
                if ((local_74 & 0x10000000) == 0) {
                  pcVar14 = "";
                }
                nvswitch_os_report_error
                          (param_1[3],0x5dc7,"Fatal, Link %02d %s%s\n",uVar1,
                           "sourcetrack timeout error",pcVar14);
                pcVar14 = " (First)";
                if ((local_74 & 0x10000000) == 0) {
                  pcVar14 = "";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x5dc7,"Fatal, Link %02d %s%s\n",uVar1,
                           "sourcetrack timeout error",pcVar14);
                nvswitch_inforom_bbx_add_sxid(param_1,0x5dc7,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x1f,0x5dc7,uVar1,0,1,1,0,&local_7c,0x20,0xbb1,
                           "\"sourcetrack timeout error\"");
                nvswitch_set_fatal_error(param_1,0,uVar1);
                nvswitch_lib_notify_client_events(param_1,0);
              }
              uVar10 = (uint)local_b8 & 0xefffffff;
              local_b8 = local_b8 & 0xffffffffefffffff;
            }
            if (uVar10 != 0) {
              iVar9 = nvswitch_translate_hw_error(0x2713);
              if (iVar9 == 1) {
                nvswitch_assert_log();
              }
              lVar13 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                                ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),
                                *(undefined1 *)(lVar13 + 0x44),*(undefined1 *)(lVar13 + 0x45),
                                *(undefined1 *)(lVar13 + 0x46),0x2713,
                                "_nvswitch_service_sourcetrack_fatal_lr10",0xbb6);
              nvswitch_os_report_error
                        (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                         "_nvswitch_service_sourcetrack_fatal_lr10",0xbb6);
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                         "_nvswitch_service_sourcetrack_fatal_lr10",0xbb6);
              nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_b8,4,0xbb6,&DAT_00c81851);
            }
            if ((char)param_1[uVar16 * 8 + 0x1ed] != '\0') {
              (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x6408,local_74._4_4_ ^ uVar7);
            }
            if (((uint)local_74 & local_7c._4_4_) != 0) {
              (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x641c);
            }
            (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x6400,uVar7);
            if ((uint)local_b8 != 0) goto LAB_001d39c2;
          }
          local_c0 = local_c0 & ~uVar3;
        }
      }
LAB_001d1380:
      uVar17 = uVar17 + 1;
    } while (uVar17 != 3);
    uVar3 = 0;
    if (local_c0 != 0) {
      iVar11 = nvswitch_translate_hw_error(0x2713);
      if (iVar11 == 1) {
        nvswitch_assert_log();
      }
      lVar13 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                        ,param_1 + 1,*(undefined4 *)(lVar13 + 0x40),*(undefined1 *)(lVar13 + 0x44),
                        *(undefined1 *)(lVar13 + 0x45),*(undefined1 *)(lVar13 + 0x46),0x2713,
                        "_nvswitch_service_npg_fatal_lr10",0xc2a);
      nvswitch_os_report_error
                (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_npg_fatal_lr10",0xc2a);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_npg_fatal_lr10",0xc2a);
      nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
      nvswitch_record_error(param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_c0,4,0xc2a,&DAT_00c81851)
      ;
      return -(uint)(local_c0 != 0) & 0xfffffff6;
    }
  }
  return uVar3;
}


// ===== 001d3af9 _nvswitch_service_route_nonfatal_lr10.cold =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_service_route_nonfatal_lr10_cold(void)

{
  code *pcVar1;
  undefined4 uVar2;
  long lVar3;
  long unaff_RBX;
  long unaff_RBP;
  undefined4 *puVar4;
  code *in_R9;
  undefined8 unaff_R15;
  
  *(undefined8 *)(unaff_RBP + -8) = unaff_R15;
  puVar4 = (undefined4 *)(unaff_RBP + -0x94);
  for (lVar3 = 8; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined4 *)(unaff_RBP + -0x74);
  for (lVar3 = 0x11; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined4 *)(unaff_RBP + -0xb0);
  for (lVar3 = 7; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  uVar2 = (*in_R9)();
  *(undefined4 *)(unaff_RBP + -0x94) = uVar2;
  uVar2 = (**(code **)(unaff_RBX + 0x920))();
  *(undefined4 *)(unaff_RBP + -0x88) = uVar2;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001d3b80 _nvswitch_service_route_nonfatal_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _nvswitch_service_route_nonfatal_lr10(long *param_1,uint param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  char *pcVar7;
  undefined8 *puVar8;
  ulong *puVar9;
  uint uVar10;
  uint local_bc;
  ulong local_b8;
  ulong local_b0;
  uint5 local_a8;
  undefined3 uStack_a3;
  undefined4 local_a0;
  undefined8 local_9c;
  undefined8 local_94;
  undefined8 local_8c;
  undefined8 local_84;
  undefined8 local_7c;
  undefined8 local_74;
  undefined8 local_6c;
  undefined8 local_64;
  undefined8 local_5c;
  undefined8 local_54;
  undefined8 local_4c;
  undefined8 local_44;
  undefined4 local_3c;
  
  pcVar1 = (code *)param_1[0x124];
  if ((int)param_1[0x3f1] != 6) {
    puVar8 = &local_9c;
    for (lVar6 = 8; lVar6 != 0; lVar6 = lVar6 + -1) {
      *(undefined4 *)puVar8 = 0;
      puVar8 = (undefined8 *)((long)puVar8 + 4);
    }
    puVar8 = &local_7c;
    for (lVar6 = 0x11; lVar6 != 0; lVar6 = lVar6 + -1) {
      *(undefined4 *)puVar8 = 0;
      puVar8 = (undefined8 *)((long)puVar8 + 4);
    }
    lVar6 = 7;
    puVar9 = &local_b8;
    while( true ) {
      if (lVar6 == 0) break;
      lVar6 = lVar6 + -1;
      *(undefined4 *)puVar9 = 0;
      puVar9 = (ulong *)((long)puVar9 + 4);
    }
    uVar2 = (*pcVar1)(param_1,5,0,param_2,0x5400);
    local_9c = CONCAT44(local_9c._4_4_,uVar2);
    uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x540c);
    local_94 = CONCAT44(uVar2,(uint)local_94);
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  lVar6 = param_1[0x3f2];
  local_9c = 0;
  local_94 = 0;
  local_8c = 0;
  local_84 = 0;
  local_7c = 0;
  local_74 = 0;
  local_6c = 0;
  local_64 = 0;
  local_5c = 0;
  local_54 = 0;
  local_4c = 0;
  local_44 = 0;
  local_3c = 0;
  local_b8 = 0;
  local_b0 = 0;
  _local_a8 = 0;
  local_a0 = 0;
  uVar2 = (*pcVar1)(param_1,5,0,param_2,0x5400);
  local_9c = CONCAT44(local_9c._4_4_,uVar2);
  uVar3 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x540c);
  local_9c = CONCAT44(uVar3 & *(uint *)(&DAT_00009aac + lVar6),(uint)local_9c);
  uVar10 = uVar3 & *(uint *)(&DAT_00009aac + lVar6) & (uint)local_9c;
  if (uVar10 == 0) {
    uVar5 = 0xfffffffd;
  }
  else {
    local_bc = uVar10;
    local_94._4_4_ = uVar3;
    uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x541c);
    local_94 = CONCAT44(local_94._4_4_,uVar2);
    _nvswitch_collect_error_info_lr10(param_1,param_2,7,&local_7c);
    if ((uVar10 & 2) != 0) {
      iVar4 = nvswitch_translate_hw_error(0x3a9a);
      if (iVar4 == 1) {
        nvswitch_assert_log();
      }
      lVar6 = *param_1;
      pcVar7 = "";
      if ((local_94 & 2) != 0) {
        pcVar7 = " (First)";
      }
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                        ,param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44),
                        *(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x3a9a,param_2,
                        "route undefined route",pcVar7);
      pcVar7 = "";
      if ((local_94 & 2) != 0) {
        pcVar7 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x3a9a,"Non-fatal, Link %02d %s%s\n",param_2,"route undefined route",
                 pcVar7);
      pcVar7 = "";
      if ((local_94 & 2) != 0) {
        pcVar7 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x3a9a,"Non-fatal, Link %02d %s%s\n",param_2,"route undefined route",pcVar7
                );
      nvswitch_inforom_bbx_add_sxid(param_1,0x3a9a,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x24,0x3a9a,param_2,0,1,0,0,&local_9c,0x20,0x676,
                 "\"route undefined route\"");
      nvswitch_lib_notify_client_events(param_1,1);
      nvswitch_record_error
                (param_1,param_1 + 0x24,0x3a9a,param_2,0,1,0,1,&local_7c,0x44,0x677,&DAT_00c81851);
      local_bc = local_bc & 0xfffffffd;
    }
    if ((uVar10 & 4) != 0) {
      iVar4 = nvswitch_translate_hw_error(0x3a9b);
      if (iVar4 == 1) {
        nvswitch_assert_log();
      }
      lVar6 = *param_1;
      pcVar7 = "";
      if ((local_94 & 4) != 0) {
        pcVar7 = " (First)";
      }
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                        ,param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44),
                        *(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x3a9b,param_2,
                        "route invalid policy",pcVar7);
      pcVar7 = "";
      if ((local_94 & 4) != 0) {
        pcVar7 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x3a9b,"Non-fatal, Link %02d %s%s\n",param_2,"route invalid policy",
                 pcVar7);
      pcVar7 = "";
      if ((local_94 & 4) != 0) {
        pcVar7 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x3a9b,"Non-fatal, Link %02d %s%s\n",param_2,"route invalid policy",pcVar7)
      ;
      nvswitch_inforom_bbx_add_sxid(param_1,0x3a9b,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x24,0x3a9b,param_2,0,1,0,0,&local_9c,0x20,0x67e,
                 "\"route invalid policy\"");
      nvswitch_lib_notify_client_events(param_1,1);
      nvswitch_record_error
                (param_1,param_1 + 0x24,0x3a9b,param_2,0,1,0,1,&local_7c,0x44,0x67f,&DAT_00c81851);
      local_bc = local_bc & 0xfffffffb;
    }
    if ((uVar10 & 0x80) != 0) {
      if ((local_9c & 0x100) == 0) {
        uVar2 = (*(code *)param_1[0x124])(param_1,5,0,param_2,0x5490);
        local_8c = CONCAT44(local_8c._4_4_,uVar2);
        iVar4 = nvswitch_translate_hw_error(0x3aa3);
        if (iVar4 == 1) {
          nvswitch_assert_log();
        }
        lVar6 = *param_1;
        pcVar7 = " (First)";
        if ((local_94 & 0x80) == 0) {
          pcVar7 = "";
        }
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44),
                          *(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x3aa3,param_2
                          ,"route incoming ECC limit",pcVar7);
        pcVar7 = " (First)";
        if ((local_94 & 0x80) == 0) {
          pcVar7 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x3aa3,"Non-fatal, Link %02d %s%s\n",param_2,
                   "route incoming ECC limit",pcVar7);
        pcVar7 = " (First)";
        if ((local_94 & 0x80) == 0) {
          pcVar7 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x3aa3,"Non-fatal, Link %02d %s%s\n",param_2,"route incoming ECC limit",
                   pcVar7);
        nvswitch_inforom_bbx_add_sxid(param_1,0x3aa3,0,0,0);
        nvswitch_record_error
                  (param_1,param_1 + 0x24,0x3aa3,param_2,0,1,0,0,&local_9c,0x20,0x68b,
                   "\"route incoming ECC limit\"");
        nvswitch_lib_notify_client_events(param_1,1);
        nvswitch_record_error
                  (param_1,param_1 + 0x24,0x3aa3,param_2,0,1,0,1,&local_7c,0x44,0x68c,&DAT_00c81851)
        ;
        local_b0 = (local_b0 >> 8 & 0xffffff) << 8;
        local_a8 = (uint5)(uint)local_a8;
        local_a0 = 1;
        local_b8 = (ulong)param_2 << 0x20 | 0x3aa3;
        nvswitch_inforom_ecc_log_err_event(param_1,&local_b8);
      }
      local_bc = local_bc & 0xffffff7f;
    }
    if (local_bc != 0) {
      iVar4 = nvswitch_translate_hw_error(0x2713);
      if (iVar4 == 1) {
        nvswitch_assert_log();
      }
      lVar6 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                        ,param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44),
                        *(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x2713,
                        "_nvswitch_service_route_nonfatal_lr10",0x698);
      nvswitch_os_report_error
                (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_route_nonfatal_lr10",0x698);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_route_nonfatal_lr10",0x698);
      nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
      nvswitch_record_error(param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_bc,4,0x698,&DAT_00c81851)
      ;
    }
    if ((char)param_1[(ulong)param_2 * 8 + 0x1ed] != '\0') {
      (*(code *)param_1[0x125])(param_1,5,0,param_2,0x540c,local_94._4_4_ ^ uVar10);
    }
    if (((uint)local_94 & local_9c._4_4_) != 0) {
      (*(code *)param_1[0x125])(param_1,5,0,param_2,0x541c);
    }
    (*(code *)param_1[0x125])(param_1,5,0,param_2,0x5400,uVar10);
    (*(code *)param_1[0x125])(param_1,5,0,param_2,0x5490,0);
    if (local_bc == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = 0xfffffff6;
    }
  }
  return uVar5;
}


// ===== 001d443a _nvswitch_service_npg_nonfatal_lr10.cold =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvswitch_service_npg_nonfatal_lr10_cold(void)

{
  code *pcVar1;
  undefined4 uVar2;
  long lVar3;
  long unaff_RBX;
  long unaff_RBP;
  undefined4 *puVar4;
  code *in_R9;
  
  puVar4 = (undefined4 *)(unaff_RBP + -0x94);
  for (lVar3 = 8; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined4 *)(unaff_RBP + -0x74);
  for (lVar3 = 0x11; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined4 *)(unaff_RBP + -0xb0);
  for (lVar3 = 7; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  uVar2 = (*in_R9)();
  *(undefined4 *)(unaff_RBP + -0x94) = uVar2;
  uVar2 = (**(code **)(unaff_RBX + 0x920))();
  *(undefined4 *)(unaff_RBP + -0x88) = uVar2;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001d4610 _nvswitch_service_npg_nonfatal_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Type propagation algorithm not settling */

uint _nvswitch_service_npg_nonfatal_lr10(long *param_1,int param_2)

{
  uint uVar1;
  code *pcVar2;
  ulong uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  long lVar9;
  uint uVar10;
  char *pcVar11;
  undefined8 *puVar12;
  ulong uVar13;
  uint uVar14;
  uint uVar15;
  bool bVar16;
  byte bVar17;
  uint local_f4;
  int local_ec;
  int local_e8;
  int local_d8;
  uint local_c0;
  uint local_bc;
  undefined8 local_b8;
  undefined8 local_b0;
  uint5 local_a8;
  undefined3 uStack_a3;
  undefined4 local_a0;
  undefined8 local_9c;
  undefined8 local_94;
  undefined8 local_8c;
  ulong local_84;
  undefined8 local_7c;
  undefined8 local_74;
  undefined8 local_6c;
  undefined8 local_64;
  undefined8 local_5c;
  undefined8 local_54;
  undefined8 local_4c;
  undefined8 local_44;
  undefined4 local_3c;
  
  bVar17 = 0;
  uVar4 = (*(code *)param_1[0x124])(param_1,4,0,param_2,0x400);
  if (uVar4 == 0) {
    uVar4 = 0xfffffffd;
  }
  else {
    uVar10 = uVar4 & 0x4444;
    local_c0 = uVar10;
    if ((uVar4 & 4) != 0) {
      uVar14 = 0xffffffff;
      uVar4 = 4;
      goto LAB_001d46a4;
    }
    if ((uVar4 & 0x40) != 0) {
      uVar4 = 0x40;
      uVar14 = 0;
      goto LAB_001d46a4;
    }
    uVar14 = 1;
    do {
      uVar4 = *(uint *)(CSWTCH_789 + (ulong)uVar14 * 4);
      if ((uVar10 & uVar4) != 0) {
LAB_001d46a4:
        uVar1 = uVar14 + 1 + param_2 * 4;
        uVar13 = (ulong)uVar1;
        if ((int)param_1[0x3f1] != 6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        if (*(char *)(uVar13 * 0x20 + param_1[0x3f2] + 0x68d0) != '\0') {
          iVar8 = _nvswitch_service_route_nonfatal_lr10(param_1,uVar1);
          pcVar2 = (code *)param_1[0x124];
          if ((int)param_1[0x3f1] != 6) {
            puVar12 = &local_9c;
            for (lVar9 = 8; lVar9 != 0; lVar9 = lVar9 + -1) {
              *(undefined4 *)puVar12 = 0;
              puVar12 = (undefined8 *)((long)puVar12 + (ulong)bVar17 * -8 + 4);
            }
            puVar12 = &local_7c;
            for (lVar9 = 0x11; lVar9 != 0; lVar9 = lVar9 + -1) {
              *(undefined4 *)puVar12 = 0;
              puVar12 = (undefined8 *)((long)puVar12 + (ulong)bVar17 * -8 + 4);
            }
            puVar12 = &local_b8;
            for (lVar9 = 7; lVar9 != 0; lVar9 = lVar9 + -1) {
              *(undefined4 *)puVar12 = 0;
              puVar12 = (undefined8 *)((long)puVar12 + (ulong)bVar17 * -8 + 4);
            }
            uVar5 = (*pcVar2)(param_1,5,0,uVar13,0x1400);
            local_9c = CONCAT44(local_9c._4_4_,uVar5);
            uVar5 = (*(code *)param_1[0x124])(param_1,5,0,uVar13,0x140c);
            local_94 = CONCAT44(uVar5,(uint)local_94);
                    /* WARNING: Does not return */
            pcVar2 = (code *)invalidInstructionException();
            (*pcVar2)();
          }
          lVar9 = param_1[0x3f2];
          local_9c = 0;
          local_94 = 0;
          local_8c = 0;
          local_84 = 0;
          local_7c = 0;
          local_74 = 0;
          local_6c = 0;
          local_64 = 0;
          local_5c = 0;
          local_54 = 0;
          local_4c = 0;
          local_44 = 0;
          local_3c = 0;
          local_b8 = 0;
          local_b0 = 0;
          _local_a8 = 0;
          local_a0 = 0;
          uVar5 = (*pcVar2)(param_1,5,0,uVar1,0x1400);
          local_9c = CONCAT44(local_9c._4_4_,uVar5);
          uVar15 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x140c);
          local_94 = CONCAT44(uVar15,(uint)local_94);
          local_9c = CONCAT44(uVar15 & *(uint *)(&DAT_00009ab8 + lVar9),(uint)local_9c);
          uVar15 = uVar15 & *(uint *)(&DAT_00009ab8 + lVar9) & (uint)local_9c;
          if (uVar15 == 0) {
            local_ec = -3;
          }
          else {
            local_bc = uVar15;
            uVar5 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x141c);
            local_94 = CONCAT44(local_94._4_4_,uVar5);
            _nvswitch_collect_error_info_lr10(param_1,uVar1,0x38,&local_7c);
            if ((uVar15 & 4) != 0) {
              iVar6 = nvswitch_translate_hw_error(0x2b03);
              if (iVar6 == 1) {
                nvswitch_assert_log();
              }
              pcVar11 = " (First)";
              if ((local_94 & 4) == 0) {
                pcVar11 = "";
              }
              lVar9 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),
                                *(undefined1 *)(lVar9 + 0x44),*(undefined1 *)(lVar9 + 0x45),
                                *(undefined1 *)(lVar9 + 0x46),0x2b03,uVar13,
                                "ingress request context mismatch",pcVar11);
              pcVar11 = " (First)";
              if ((local_94 & 4) == 0) {
                pcVar11 = "";
              }
              nvswitch_os_report_error
                        (param_1[3],0x2b03,"Non-fatal, Link %02d %s%s\n",uVar1,
                         "ingress request context mismatch",pcVar11);
              pcVar11 = " (First)";
              if ((local_94 & 4) == 0) {
                pcVar11 = "";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x2b03,"Non-fatal, Link %02d %s%s\n",uVar1,
                         "ingress request context mismatch",pcVar11);
              nvswitch_inforom_bbx_add_sxid(param_1,0x2b03,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x24,0x2b03,uVar1,0,1,0,0,&local_9c,0x20,0x7a8,
                         "\"ingress request context mismatch\"");
              nvswitch_lib_notify_client_events(param_1,1);
              nvswitch_record_error
                        (param_1,param_1 + 0x24,0x2b03,uVar1,0,1,0,1,&local_7c,0x44,0x7a9,
                         &DAT_00c81851);
              local_bc = local_bc & 0xfffffffb;
            }
            if ((uVar15 & 8) != 0) {
              iVar6 = nvswitch_translate_hw_error(0x2afc);
              if (iVar6 == 1) {
                nvswitch_assert_log();
              }
              pcVar11 = " (First)";
              if ((local_94 & 8) == 0) {
                pcVar11 = "";
              }
              lVar9 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),
                                *(undefined1 *)(lVar9 + 0x44),*(undefined1 *)(lVar9 + 0x45),
                                *(undefined1 *)(lVar9 + 0x46),0x2afc,uVar13,"ingress invalid ACL",
                                pcVar11);
              pcVar11 = " (First)";
              if ((local_94 & 8) == 0) {
                pcVar11 = "";
              }
              nvswitch_os_report_error
                        (param_1[3],0x2afc,"Non-fatal, Link %02d %s%s\n",uVar1,"ingress invalid ACL"
                         ,pcVar11);
              pcVar11 = " (First)";
              if ((local_94 & 8) == 0) {
                pcVar11 = "";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x2afc,"Non-fatal, Link %02d %s%s\n",uVar1,"ingress invalid ACL",
                         pcVar11);
              nvswitch_inforom_bbx_add_sxid(param_1,0x2afc,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x24,0x2afc,uVar1,0,1,0,0,&local_9c,0x20,0x7b0,
                         "\"ingress invalid ACL\"");
              nvswitch_lib_notify_client_events(param_1,1);
              nvswitch_record_error
                        (param_1,param_1 + 0x24,0x2afc,uVar1,0,1,0,1,&local_7c,0x44,0x7b1,
                         &DAT_00c81851);
              local_bc = local_bc & 0xfffffff7;
            }
            if ((uVar15 & 0x10) != 0) {
              if ((local_9c & 0x20) == 0) {
                uVar5 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x14b0);
                local_8c = CONCAT44(local_8c._4_4_,uVar5);
                iVar6 = nvswitch_translate_hw_error(0x2b04);
                if (iVar6 == 1) {
                  nvswitch_assert_log();
                }
                pcVar11 = " (First)";
                if ((local_94 & 0x10) == 0) {
                  pcVar11 = "";
                }
                lVar9 = *param_1;
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),
                                  *(undefined1 *)(lVar9 + 0x44),*(undefined1 *)(lVar9 + 0x45),
                                  *(undefined1 *)(lVar9 + 0x46),0x2b04,uVar13,"ingress header ECC",
                                  pcVar11);
                pcVar11 = " (First)";
                if ((local_94 & 0x10) == 0) {
                  pcVar11 = "";
                }
                nvswitch_os_report_error
                          (param_1[3],0x2b04,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "ingress header ECC",pcVar11);
                pcVar11 = " (First)";
                if ((local_94 & 0x10) == 0) {
                  pcVar11 = "";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x2b04,"Non-fatal, Link %02d %s%s\n",uVar1,"ingress header ECC",
                           pcVar11);
                nvswitch_inforom_bbx_add_sxid(param_1,0x2b04,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x2b04,uVar1,0,1,0,0,&local_9c,0x20,0x7bd,
                           "\"ingress header ECC\"");
                nvswitch_lib_notify_client_events(param_1,1);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x2b04,uVar1,0,1,0,1,&local_7c,0x44,0x7be,
                           &DAT_00c81851);
                local_b8 = CONCAT44(uVar1,0x2b04);
                local_b0 = (local_b0 >> 8 & 0xffffff) << 8;
                local_a8 = (uint5)(uint)local_a8;
                local_a0 = 1;
                nvswitch_inforom_ecc_log_err_event(param_1,&local_b8);
              }
              local_bc = local_bc & 0xffffffef;
            }
            if ((uVar15 & 0x80) != 0) {
              iVar6 = nvswitch_translate_hw_error(0x2b06);
              if (iVar6 == 1) {
                nvswitch_assert_log();
              }
              pcVar11 = " (First)";
              if ((local_94 & 0x80) == 0) {
                pcVar11 = "";
              }
              lVar9 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),
                                *(undefined1 *)(lVar9 + 0x44),*(undefined1 *)(lVar9 + 0x45),
                                *(undefined1 *)(lVar9 + 0x46),0x2b06,uVar13,"ingress address bounds"
                                ,pcVar11);
              pcVar11 = " (First)";
              if ((local_94 & 0x80) == 0) {
                pcVar11 = "";
              }
              nvswitch_os_report_error
                        (param_1[3],0x2b06,"Non-fatal, Link %02d %s%s\n",uVar1,
                         "ingress address bounds",pcVar11);
              pcVar11 = " (First)";
              if ((local_94 & 0x80) == 0) {
                pcVar11 = "";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x2b06,"Non-fatal, Link %02d %s%s\n",uVar1,"ingress address bounds"
                         ,pcVar11);
              nvswitch_inforom_bbx_add_sxid(param_1,0x2b06,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x24,0x2b06,uVar1,0,1,0,0,&local_9c,0x20,0x7cd,
                         "\"ingress address bounds\"");
              nvswitch_lib_notify_client_events(param_1,1);
              nvswitch_record_error
                        (param_1,param_1 + 0x24,0x2b06,uVar1,0,1,0,1,&local_7c,0x44,0x7ce,
                         &DAT_00c81851);
              local_bc = local_bc & 0xffffff7f;
            }
            if ((uVar15 & 0x100) != 0) {
              iVar6 = nvswitch_translate_hw_error(0x2b07);
              if (iVar6 == 1) {
                nvswitch_assert_log();
              }
              pcVar11 = " (First)";
              if ((local_94 & 0x100) == 0) {
                pcVar11 = "";
              }
              lVar9 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),
                                *(undefined1 *)(lVar9 + 0x44),*(undefined1 *)(lVar9 + 0x45),
                                *(undefined1 *)(lVar9 + 0x46),0x2b07,uVar13,"ingress RID packet",
                                pcVar11);
              pcVar11 = " (First)";
              if ((local_94 & 0x100) == 0) {
                pcVar11 = "";
              }
              nvswitch_os_report_error
                        (param_1[3],0x2b07,"Non-fatal, Link %02d %s%s\n",uVar1,"ingress RID packet",
                         pcVar11);
              pcVar11 = " (First)";
              if ((local_94 & 0x100) == 0) {
                pcVar11 = "";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x2b07,"Non-fatal, Link %02d %s%s\n",uVar1,"ingress RID packet",
                         pcVar11);
              nvswitch_inforom_bbx_add_sxid(param_1,0x2b07,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x24,0x2b07,uVar1,0,1,0,0,&local_9c,0x20,0x7d5,
                         "\"ingress RID packet\"");
              nvswitch_lib_notify_client_events(param_1,1);
              nvswitch_record_error
                        (param_1,param_1 + 0x24,0x2b07,uVar1,0,1,0,1,&local_7c,0x44,0x7d6,
                         &DAT_00c81851);
              local_bc = local_bc & 0xfffffeff;
            }
            if ((uVar15 & 0x200) != 0) {
              iVar6 = nvswitch_translate_hw_error(0x2b08);
              if (iVar6 == 1) {
                nvswitch_assert_log();
              }
              pcVar11 = " (First)";
              if ((local_94 & 0x200) == 0) {
                pcVar11 = "";
              }
              lVar9 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),
                                *(undefined1 *)(lVar9 + 0x44),*(undefined1 *)(lVar9 + 0x45),
                                *(undefined1 *)(lVar9 + 0x46),0x2b08,uVar13,"ingress RLAN packet",
                                pcVar11);
              pcVar11 = " (First)";
              if ((local_94 & 0x200) == 0) {
                pcVar11 = "";
              }
              nvswitch_os_report_error
                        (param_1[3],0x2b08,"Non-fatal, Link %02d %s%s\n",uVar1,"ingress RLAN packet"
                         ,pcVar11);
              pcVar11 = " (First)";
              if ((local_94 & 0x200) == 0) {
                pcVar11 = "";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x2b08,"Non-fatal, Link %02d %s%s\n",uVar1,"ingress RLAN packet",
                         pcVar11);
              nvswitch_inforom_bbx_add_sxid(param_1,0x2b08,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x24,0x2b08,uVar1,0,1,0,0,&local_9c,0x20,0x7dd,
                         "\"ingress RLAN packet\"");
              nvswitch_lib_notify_client_events(param_1,1);
              nvswitch_record_error
                        (param_1,param_1 + 0x24,0x2b08,uVar1,0,1,0,1,&local_7c,0x44,0x7de,
                         &DAT_00c81851);
              local_bc = local_bc & 0xfffffdff;
            }
            if ((uVar15 & 0x20000) != 0) {
              iVar6 = nvswitch_translate_hw_error(0x2b10);
              if (iVar6 == 1) {
                nvswitch_assert_log();
              }
              pcVar11 = " (First)";
              if ((local_94 & 0x20000) == 0) {
                pcVar11 = "";
              }
              lVar9 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),
                                *(undefined1 *)(lVar9 + 0x44),*(undefined1 *)(lVar9 + 0x45),
                                *(undefined1 *)(lVar9 + 0x46),0x2b10,uVar13,
                                "ingress illegal address",pcVar11);
              pcVar11 = " (First)";
              if ((local_94 & 0x20000) == 0) {
                pcVar11 = "";
              }
              nvswitch_os_report_error
                        (param_1[3],0x2b10,"Non-fatal, Link %02d %s%s\n",uVar1,
                         "ingress illegal address",pcVar11);
              pcVar11 = " (First)";
              if ((local_94 & 0x20000) == 0) {
                pcVar11 = "";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x2b10,"Non-fatal, Link %02d %s%s\n",uVar1,
                         "ingress illegal address",pcVar11);
              nvswitch_inforom_bbx_add_sxid(param_1,0x2b10,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x24,0x2b10,uVar1,0,1,0,0,&local_9c,0x20,0x7e5,
                         "\"ingress illegal address\"");
              nvswitch_lib_notify_client_events(param_1,1);
              nvswitch_record_error
                        (param_1,param_1 + 0x24,0x2b10,uVar1,0,1,0,1,&local_7c,0x44,0x7e6,
                         &DAT_00c81851);
              local_bc = local_bc & 0xfffdffff;
            }
            if (local_bc != 0) {
              iVar6 = nvswitch_translate_hw_error(0x2713);
              if (iVar6 == 1) {
                nvswitch_assert_log();
              }
              lVar9 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                                ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),
                                *(undefined1 *)(lVar9 + 0x44),*(undefined1 *)(lVar9 + 0x45),
                                *(undefined1 *)(lVar9 + 0x46),0x2713,
                                "_nvswitch_service_ingress_nonfatal_lr10",0x7ea);
              nvswitch_os_report_error
                        (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                         "_nvswitch_service_ingress_nonfatal_lr10",0x7ea);
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                         "_nvswitch_service_ingress_nonfatal_lr10",0x7ea);
              nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_bc,4,0x7ea,&DAT_00c81851);
            }
            if ((char)param_1[uVar13 * 8 + 0x1ed] != '\0') {
              (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x140c,local_94._4_4_ ^ uVar15);
            }
            if (((uint)local_94 & local_9c._4_4_) != 0) {
              (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x141c);
            }
            (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x1400,uVar15);
            if (local_bc == 0) {
              local_ec = 0;
            }
            else {
              local_ec = -10;
            }
          }
          pcVar2 = (code *)param_1[0x124];
          if ((int)param_1[0x3f1] != 6) {
            puVar12 = &local_9c;
            for (lVar9 = 8; lVar9 != 0; lVar9 = lVar9 + -1) {
              *(undefined4 *)puVar12 = 0;
              puVar12 = (undefined8 *)((long)puVar12 + (ulong)bVar17 * -8 + 4);
            }
            puVar12 = &local_7c;
            for (lVar9 = 0x11; lVar9 != 0; lVar9 = lVar9 + -1) {
              *(undefined4 *)puVar12 = 0;
              puVar12 = (undefined8 *)((long)puVar12 + (ulong)bVar17 * -8 + 4);
            }
            puVar12 = &local_b8;
            for (lVar9 = 7; lVar9 != 0; lVar9 = lVar9 + -1) {
              *(undefined4 *)puVar12 = 0;
              puVar12 = (undefined8 *)((long)puVar12 + (ulong)bVar17 * -8 + 4);
            }
            uVar5 = (*pcVar2)(param_1,5,0,uVar13,0x4400);
            local_9c = CONCAT44(local_9c._4_4_,uVar5);
            uVar5 = (*(code *)param_1[0x124])(param_1,5,0,uVar13,0x440c);
            local_94 = CONCAT44(uVar5,(uint)local_94);
                    /* WARNING: Does not return */
            pcVar2 = (code *)invalidInstructionException();
            (*pcVar2)();
          }
          lVar9 = param_1[0x3f2];
          local_9c = 0;
          local_94 = 0;
          local_8c = 0;
          local_84 = 0;
          local_7c = 0;
          local_74 = 0;
          local_6c = 0;
          local_64 = 0;
          local_5c = 0;
          local_54 = 0;
          local_4c = 0;
          local_44 = 0;
          local_3c = 0;
          local_b8 = 0;
          local_b0 = 0;
          _local_a8 = 0;
          local_a0 = 0;
          uVar5 = (*pcVar2)(param_1,5,0,uVar1,0x4400);
          local_9c = CONCAT44(local_9c._4_4_,uVar5);
          uVar15 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x440c);
          local_94 = CONCAT44(uVar15,(uint)local_94);
          local_9c = CONCAT44(uVar15 & *(uint *)(&DAT_00009ac4 + lVar9),(uint)local_9c);
          uVar15 = uVar15 & *(uint *)(&DAT_00009ac4 + lVar9) & (uint)local_9c;
          if (uVar15 == 0) {
            local_e8 = -3;
          }
          else {
            local_bc = uVar15;
            uVar5 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x441c);
            local_94 = CONCAT44(local_94._4_4_,uVar5);
            _nvswitch_collect_error_info_lr10(param_1,uVar1,0x1c0,&local_7c);
            if ((uVar15 & 8) != 0) {
              if ((local_9c & 0x10) == 0) {
                uVar5 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x4480);
                local_8c = CONCAT44(local_8c._4_4_,uVar5);
                iVar6 = nvswitch_translate_hw_error(0x2ef5);
                if (iVar6 == 1) {
                  nvswitch_assert_log();
                }
                pcVar11 = " (First)";
                if ((local_94 & 8) == 0) {
                  pcVar11 = "";
                }
                lVar9 = *param_1;
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),
                                  *(undefined1 *)(lVar9 + 0x44),*(undefined1 *)(lVar9 + 0x45),
                                  *(undefined1 *)(lVar9 + 0x46),0x2ef5,uVar13,
                                  "egress input ECC error limit",pcVar11);
                pcVar11 = " (First)";
                if ((local_94 & 8) == 0) {
                  pcVar11 = "";
                }
                nvswitch_os_report_error
                          (param_1[3],0x2ef5,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "egress input ECC error limit",pcVar11);
                pcVar11 = " (First)";
                if ((local_94 & 8) == 0) {
                  pcVar11 = "";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x2ef5,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "egress input ECC error limit",pcVar11);
                nvswitch_inforom_bbx_add_sxid(param_1,0x2ef5,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x2ef5,uVar1,0,1,0,0,&local_9c,0x20,0x972,
                           "\"egress input ECC error limit\"");
                nvswitch_lib_notify_client_events(param_1,1);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x2ef5,uVar1,0,1,0,1,&local_7c,0x44,0x973,
                           &DAT_00c81851);
                local_b8 = CONCAT44(uVar1,0x2ef5);
                local_b0 = (local_b0 >> 8 & 0xffffff) << 8;
                local_a8 = (uint5)(uint)local_a8;
                local_a0 = 1;
                nvswitch_inforom_ecc_log_err_event(param_1,&local_b8);
              }
              local_bc = local_bc & 0xfffffff7;
            }
            if ((uVar15 & 0x20) != 0) {
              if ((local_9c & 0x40) == 0) {
                uVar7 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x4498);
                bVar16 = (uVar7 & 1) != 0;
                uVar7 = uVar7 & 1;
                if (bVar16) {
                  uVar7 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x4494);
                }
                uVar5 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x448c);
                local_8c = CONCAT44(local_8c._4_4_,uVar5);
                uVar5 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x4494);
                local_8c = CONCAT44(uVar5,(uint)local_8c);
                iVar6 = nvswitch_translate_hw_error(0x2ef7);
                if (iVar6 == 1) {
                  nvswitch_assert_log();
                }
                pcVar11 = " (First)";
                if ((local_94 & 0x20) == 0) {
                  pcVar11 = "";
                }
                lVar9 = *param_1;
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),
                                  *(undefined1 *)(lVar9 + 0x44),*(undefined1 *)(lVar9 + 0x45),
                                  *(undefined1 *)(lVar9 + 0x46),0x2ef7,uVar13,
                                  "egress output ECC error limit",pcVar11);
                pcVar11 = " (First)";
                if ((local_94 & 0x20) == 0) {
                  pcVar11 = "";
                }
                nvswitch_os_report_error
                          (param_1[3],0x2ef7,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "egress output ECC error limit",pcVar11);
                pcVar11 = " (First)";
                if ((local_94 & 0x20) == 0) {
                  pcVar11 = "";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x2ef7,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "egress output ECC error limit",pcVar11);
                nvswitch_inforom_bbx_add_sxid(param_1,0x2ef7,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x2ef7,uVar1,0,1,0,0,&local_9c,0x20,0x995,
                           "\"egress output ECC error limit\"");
                nvswitch_lib_notify_client_events(param_1,1);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x2ef7,uVar1,0,1,0,1,&local_7c,0x44,0x996,
                           &DAT_00c81851);
                local_b0 = CONCAT71(local_b0._1_7_,bVar16);
                local_b8 = CONCAT44(uVar1,0x2ef7);
                local_b0 = CONCAT44(uVar7,(undefined4)local_b0);
                local_a8 = (uint5)(uint)local_a8;
                local_a0 = 1;
                nvswitch_inforom_ecc_log_err_event(param_1,&local_b8);
              }
              local_bc = local_bc & 0xffffffdf;
            }
            if ((uVar15 & 0x400) != 0) {
              iVar6 = nvswitch_translate_hw_error(0x2eee);
              if (iVar6 == 1) {
                nvswitch_assert_log();
              }
              pcVar11 = " (First)";
              if ((local_94 & 0x400) == 0) {
                pcVar11 = "";
              }
              lVar9 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),
                                *(undefined1 *)(lVar9 + 0x44),*(undefined1 *)(lVar9 + 0x45),
                                *(undefined1 *)(lVar9 + 0x46),0x2eee,uVar13,"egress non-posted UR",
                                pcVar11);
              pcVar11 = " (First)";
              if ((local_94 & 0x400) == 0) {
                pcVar11 = "";
              }
              nvswitch_os_report_error
                        (param_1[3],0x2eee,"Non-fatal, Link %02d %s%s\n",uVar1,
                         "egress non-posted UR",pcVar11);
              pcVar11 = " (First)";
              if ((local_94 & 0x400) == 0) {
                pcVar11 = "";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x2eee,"Non-fatal, Link %02d %s%s\n",uVar1,"egress non-posted UR",
                         pcVar11);
              nvswitch_inforom_bbx_add_sxid(param_1,0x2eee,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x24,0x2eee,uVar1,0,1,0,0,&local_9c,0x20,0x9a5,
                         "\"egress non-posted UR\"");
              nvswitch_lib_notify_client_events(param_1,1);
              nvswitch_record_error
                        (param_1,param_1 + 0x24,0x2eee,uVar1,0,1,0,1,&local_7c,0x44,0x9a6,
                         &DAT_00c81851);
              local_bc = local_bc & 0xfffffbff;
            }
            if ((uVar15 & 0x800) != 0) {
              iVar6 = nvswitch_translate_hw_error(0x2efc);
              if (iVar6 == 1) {
                nvswitch_assert_log();
              }
              pcVar11 = " (First)";
              if ((local_94 & 0x800) == 0) {
                pcVar11 = "";
              }
              lVar9 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),
                                *(undefined1 *)(lVar9 + 0x44),*(undefined1 *)(lVar9 + 0x45),
                                *(undefined1 *)(lVar9 + 0x46),0x2efc,uVar13,
                                "egress non-posted PRIV error",pcVar11);
              pcVar11 = " (First)";
              if ((local_94 & 0x800) == 0) {
                pcVar11 = "";
              }
              nvswitch_os_report_error
                        (param_1[3],0x2efc,"Non-fatal, Link %02d %s%s\n",uVar1,
                         "egress non-posted PRIV error",pcVar11);
              pcVar11 = " (First)";
              if ((local_94 & 0x800) == 0) {
                pcVar11 = "";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x2efc,"Non-fatal, Link %02d %s%s\n",uVar1,
                         "egress non-posted PRIV error",pcVar11);
              nvswitch_inforom_bbx_add_sxid(param_1,0x2efc,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x24,0x2efc,uVar1,0,1,0,0,&local_9c,0x20,0x9ad,
                         "\"egress non-posted PRIV error\"");
              nvswitch_lib_notify_client_events(param_1,1);
              nvswitch_record_error
                        (param_1,param_1 + 0x24,0x2efc,uVar1,0,1,0,1,&local_7c,0x44,0x9ae,
                         &DAT_00c81851);
              local_bc = local_bc & 0xfffff7ff;
            }
            if ((uVar15 & 0x1000) != 0) {
              iVar6 = nvswitch_translate_hw_error(0x2efd);
              if (iVar6 == 1) {
                nvswitch_assert_log();
              }
              pcVar11 = " (First)";
              if ((local_94 & 0x1000) == 0) {
                pcVar11 = "";
              }
              lVar9 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),
                                *(undefined1 *)(lVar9 + 0x44),*(undefined1 *)(lVar9 + 0x45),
                                *(undefined1 *)(lVar9 + 0x46),0x2efd,uVar13,
                                "egress non-posted HW error",pcVar11);
              pcVar11 = " (First)";
              if ((local_94 & 0x1000) == 0) {
                pcVar11 = "";
              }
              nvswitch_os_report_error
                        (param_1[3],0x2efd,"Non-fatal, Link %02d %s%s\n",uVar1,
                         "egress non-posted HW error",pcVar11);
              pcVar11 = " (First)";
              if ((local_94 & 0x1000) == 0) {
                pcVar11 = "";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x2efd,"Non-fatal, Link %02d %s%s\n",uVar1,
                         "egress non-posted HW error",pcVar11);
              nvswitch_inforom_bbx_add_sxid(param_1,0x2efd,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x24,0x2efd,uVar1,0,1,0,0,&local_9c,0x20,0x9b5,
                         "\"egress non-posted HW error\"");
              nvswitch_lib_notify_client_events(param_1,1);
              nvswitch_record_error
                        (param_1,param_1 + 0x24,0x2efd,uVar1,0,1,0,1,&local_7c,0x44,0x9b6,
                         &DAT_00c81851);
              local_bc = local_bc & 0xffffefff;
            }
            if (local_bc != 0) {
              iVar6 = nvswitch_translate_hw_error(0x2713);
              if (iVar6 == 1) {
                nvswitch_assert_log();
              }
              lVar9 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                                ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),
                                *(undefined1 *)(lVar9 + 0x44),*(undefined1 *)(lVar9 + 0x45),
                                *(undefined1 *)(lVar9 + 0x46),0x2713,
                                "_nvswitch_service_egress_nonfatal_lr10",0x9ba);
              nvswitch_os_report_error
                        (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                         "_nvswitch_service_egress_nonfatal_lr10",0x9ba);
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                         "_nvswitch_service_egress_nonfatal_lr10",0x9ba);
              nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_bc,4,0x9ba,&DAT_00c81851);
            }
            if ((char)param_1[uVar13 * 8 + 0x1ed] != '\0') {
              (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x440c,local_94._4_4_ ^ uVar15);
            }
            if (((uint)local_94 & local_9c._4_4_) != 0) {
              (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x441c);
            }
            (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x4400,uVar15);
            if (local_bc == 0) {
              local_e8 = 0;
            }
            else {
              local_e8 = -10;
            }
          }
          pcVar2 = (code *)param_1[0x124];
          if ((int)param_1[0x3f1] != 6) {
            puVar12 = &local_9c;
            for (lVar9 = 8; lVar9 != 0; lVar9 = lVar9 + -1) {
              *(undefined4 *)puVar12 = 0;
              puVar12 = (undefined8 *)((long)puVar12 + (ulong)bVar17 * -8 + 4);
            }
            puVar12 = &local_7c;
            for (lVar9 = 0x11; lVar9 != 0; lVar9 = lVar9 + -1) {
              *(undefined4 *)puVar12 = 0;
              puVar12 = (undefined8 *)((long)puVar12 + (ulong)bVar17 * -8 + 4);
            }
            puVar12 = &local_b8;
            for (lVar9 = 7; lVar9 != 0; lVar9 = lVar9 + -1) {
              *(undefined4 *)puVar12 = 0;
              puVar12 = (undefined8 *)((long)puVar12 + (ulong)bVar17 * -8 + 4);
            }
            uVar5 = (*pcVar2)(param_1,5,0,uVar13,0x3400);
            local_9c = CONCAT44(local_9c._4_4_,uVar5);
            uVar5 = (*(code *)param_1[0x124])(param_1,5,0,uVar13,0x340c);
            local_94 = CONCAT44(uVar5,(uint)local_94);
                    /* WARNING: Does not return */
            pcVar2 = (code *)invalidInstructionException();
            (*pcVar2)();
          }
          lVar9 = param_1[0x3f2];
          local_9c = 0;
          local_94 = 0;
          local_8c = 0;
          local_84 = 0;
          local_7c = 0;
          local_74 = 0;
          local_6c = 0;
          local_64 = 0;
          local_5c = 0;
          local_54 = 0;
          local_4c = 0;
          local_44 = 0;
          local_3c = 0;
          local_b8 = 0;
          local_b0 = 0;
          _local_a8 = 0;
          local_a0 = 0;
          uVar5 = (*pcVar2)(param_1,5,0,uVar1,0x3400);
          local_9c = CONCAT44(local_9c._4_4_,uVar5);
          uVar15 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x340c);
          local_94 = CONCAT44(uVar15,(uint)local_94);
          local_9c = CONCAT44(uVar15 & *(uint *)(&DAT_00009ad0 + lVar9),(uint)local_9c);
          uVar5 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x3454);
          local_8c = CONCAT44(local_8c._4_4_,uVar5);
          uVar15 = (uint)local_9c & local_9c._4_4_;
          if (uVar15 == 0) {
            local_d8 = -3;
          }
          else {
            local_bc = uVar15;
            uVar5 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x341c);
            local_94 = CONCAT44(local_94._4_4_,uVar5);
            if ((uVar15 & 2) != 0) {
              if ((local_9c & 4) == 0) {
                uVar7 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x349c);
                bVar16 = (uVar7 & 1) != 0;
                uVar7 = uVar7 & 1;
                if (bVar16) {
                  uVar7 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x3498);
                }
                uVar5 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x3490);
                local_8c = CONCAT44(uVar5,(uint)local_8c);
                (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x3490,0);
                iVar6 = nvswitch_translate_hw_error(0x36b7);
                if (iVar6 == 1) {
                  nvswitch_assert_log();
                }
                pcVar11 = " (First)";
                if ((local_94 & 2) == 0) {
                  pcVar11 = "";
                }
                lVar9 = *param_1;
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),
                                  *(undefined1 *)(lVar9 + 0x44),*(undefined1 *)(lVar9 + 0x45),
                                  *(undefined1 *)(lVar9 + 0x46),0x36b7,uVar13,
                                  "TS tag store single-bit threshold",pcVar11);
                pcVar11 = " (First)";
                if ((local_94 & 2) == 0) {
                  pcVar11 = "";
                }
                nvswitch_os_report_error
                          (param_1[3],0x36b7,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "TS tag store single-bit threshold",pcVar11);
                pcVar11 = " (First)";
                if ((local_94 & 2) == 0) {
                  pcVar11 = "";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x36b7,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "TS tag store single-bit threshold",pcVar11);
                nvswitch_inforom_bbx_add_sxid(param_1,0x36b7,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x36b7,uVar1,0,1,0,0,&local_9c,0x20,0x83a,
                           "\"TS tag store single-bit threshold\"");
                nvswitch_lib_notify_client_events(param_1,1);
                _nvswitch_collect_error_info_lr10(param_1,uVar1,0x1c0,&local_7c);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x36b7,uVar1,0,1,0,1,&local_7c,0x44,0x840,
                           &DAT_00c81851);
                local_b0 = CONCAT71(local_b0._1_7_,bVar16);
                local_b8 = CONCAT44(uVar1,0x36b7);
                local_b0 = CONCAT44(uVar7,(undefined4)local_b0);
                local_a8 = (uint5)(uint)local_a8;
                local_a0 = 1;
                nvswitch_inforom_ecc_log_err_event(param_1,&local_b8);
              }
              local_bc = local_bc & 0xfffffffd;
            }
            if ((uVar15 & 0x10) != 0) {
              if ((local_9c & 0x20) == 0) {
                uVar7 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x348c);
                bVar16 = (uVar7 & 1) != 0;
                uVar7 = uVar7 & 1;
                if (bVar16) {
                  uVar7 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x3488);
                }
                uVar5 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x3480);
                local_8c = CONCAT44(uVar5,(uint)local_8c);
                (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x3480,0);
                iVar6 = nvswitch_translate_hw_error(0x36b9);
                if (iVar6 == 1) {
                  nvswitch_assert_log();
                }
                pcVar11 = " (First)";
                if ((local_94 & 0x10) == 0) {
                  pcVar11 = "";
                }
                lVar9 = *param_1;
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),
                                  *(undefined1 *)(lVar9 + 0x44),*(undefined1 *)(lVar9 + 0x45),
                                  *(undefined1 *)(lVar9 + 0x46),0x36b9,uVar13,
                                  "TS crumbstore single-bit threshold",pcVar11);
                pcVar11 = " (First)";
                if ((local_94 & 0x10) == 0) {
                  pcVar11 = "";
                }
                nvswitch_os_report_error
                          (param_1[3],0x36b9,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "TS crumbstore single-bit threshold",pcVar11);
                pcVar11 = " (First)";
                if ((local_94 & 0x10) == 0) {
                  pcVar11 = "";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x36b9,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "TS crumbstore single-bit threshold",pcVar11);
                nvswitch_inforom_bbx_add_sxid(param_1,0x36b9,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x36b9,uVar1,0,1,0,0,&local_9c,0x20,0x863,
                           "\"TS crumbstore single-bit threshold\"");
                nvswitch_lib_notify_client_events(param_1,1);
                _nvswitch_collect_error_info_lr10(param_1,uVar1,0x38,&local_7c);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x36b9,uVar1,0,1,0,1,&local_7c,0x44,0x869,
                           &DAT_00c81851);
                local_b0 = CONCAT71(local_b0._1_7_,bVar16);
                local_b8 = CONCAT44(uVar1,0x36b9);
                local_b0 = CONCAT44(uVar7,(undefined4)local_b0);
                local_a8 = (uint5)(uint)local_a8;
                local_a0 = 1;
                nvswitch_inforom_ecc_log_err_event(param_1,&local_b8);
              }
              local_bc = local_bc & 0xffffffef;
            }
            if (local_bc != 0) {
              iVar6 = nvswitch_translate_hw_error(0x2713);
              if (iVar6 == 1) {
                nvswitch_assert_log();
              }
              lVar9 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                                ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),
                                *(undefined1 *)(lVar9 + 0x44),*(undefined1 *)(lVar9 + 0x45),
                                *(undefined1 *)(lVar9 + 0x46),0x2713,
                                "_nvswitch_service_tstate_nonfatal_lr10",0x875);
              nvswitch_os_report_error
                        (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                         "_nvswitch_service_tstate_nonfatal_lr10",0x875);
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                         "_nvswitch_service_tstate_nonfatal_lr10",0x875);
              nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_bc,4,0x875,&DAT_00c81851);
            }
            if ((char)param_1[uVar13 * 8 + 0x1ed] != '\0') {
              (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x340c,local_94._4_4_ ^ uVar15);
            }
            if (((uint)local_94 & local_9c._4_4_) != 0) {
              (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x341c);
            }
            (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x3400,uVar15);
            if (local_bc == 0) {
              local_d8 = 0;
            }
            else {
              local_d8 = -10;
            }
          }
          pcVar2 = (code *)param_1[0x124];
          if ((int)param_1[0x3f1] != 6) {
            puVar12 = &local_7c;
            for (lVar9 = 8; lVar9 != 0; lVar9 = lVar9 + -1) {
              *(undefined4 *)puVar12 = 0;
              puVar12 = (undefined8 *)((long)puVar12 + (ulong)bVar17 * -8 + 4);
            }
            puVar12 = &local_9c;
            for (lVar9 = 7; lVar9 != 0; lVar9 = lVar9 + -1) {
              *(undefined4 *)puVar12 = 0;
              puVar12 = (undefined8 *)((long)puVar12 + (ulong)bVar17 * -8 + 4);
            }
            uVar5 = (*pcVar2)(param_1,5,0,uVar13,0x6400);
            local_7c = CONCAT44(local_7c._4_4_,uVar5);
            uVar5 = (*(code *)param_1[0x124])(param_1,5,0,uVar13,0x640c);
            local_74 = CONCAT44(uVar5,(uint)local_74);
                    /* WARNING: Does not return */
            pcVar2 = (code *)invalidInstructionException();
            (*pcVar2)();
          }
          lVar9 = param_1[0x3f2];
          local_7c = 0;
          local_74 = 0;
          local_6c = 0;
          local_64 = 0;
          local_9c = 0;
          local_94 = 0;
          local_8c = 0;
          local_84 = local_84 & 0xffffffff00000000;
          uVar5 = (*pcVar2)(param_1,5,0,uVar1,0x6400);
          local_7c = CONCAT44(local_7c._4_4_,uVar5);
          uVar15 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x640c);
          local_74 = CONCAT44(uVar15,(uint)local_74);
          local_7c = CONCAT44(uVar15 & *(uint *)(&DAT_00009adc + lVar9),(uint)local_7c);
          uVar15 = uVar15 & *(uint *)(&DAT_00009adc + lVar9) & (uint)local_7c;
          if (uVar15 == 0) {
LAB_001d73ef:
            if (((iVar8 != 0 && local_ec != 0) && local_e8 != 0) && (local_d8 != 0))
            goto LAB_001d46e0;
          }
          else {
            local_b8 = CONCAT44(local_b8._4_4_,uVar15);
            uVar5 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x641c);
            local_74 = CONCAT44(local_74._4_4_,uVar5);
            if ((uVar15 & 1) != 0) {
              if ((local_7c & 0x100) == 0) {
                local_f4 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x648c);
                local_f4 = local_f4 & 1;
                bVar16 = local_f4 != 0;
                if (bVar16) {
                  local_f4 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x6488);
                }
                uVar5 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x6480);
                local_6c = CONCAT44(local_6c._4_4_,uVar5);
                uVar5 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x6488);
                local_6c = CONCAT44(uVar5,(undefined4)local_6c);
                uVar5 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x648c);
                local_64 = CONCAT44(local_64._4_4_,uVar5);
                iVar6 = nvswitch_translate_hw_error(0x5dc1);
                if (iVar6 == 1) {
                  nvswitch_assert_log();
                }
                pcVar11 = " (First)";
                if ((local_74 & 1) == 0) {
                  pcVar11 = "";
                }
                lVar9 = *param_1;
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),
                                  *(undefined1 *)(lVar9 + 0x44),*(undefined1 *)(lVar9 + 0x45),
                                  *(undefined1 *)(lVar9 + 0x46),0x5dc1,uVar13,
                                  "sourcetrack TCEN0 crumbstore ECC limit err",pcVar11);
                pcVar11 = " (First)";
                if ((local_74 & 1) == 0) {
                  pcVar11 = "";
                }
                nvswitch_os_report_error
                          (param_1[3],0x5dc1,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "sourcetrack TCEN0 crumbstore ECC limit err",pcVar11);
                pcVar11 = " (First)";
                if ((local_74 & 1) == 0) {
                  pcVar11 = "";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x5dc1,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "sourcetrack TCEN0 crumbstore ECC limit err",pcVar11);
                nvswitch_inforom_bbx_add_sxid(param_1,0x5dc1,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x5dc1,uVar1,0,1,0,0,&local_7c,0x20,0xaf6,
                           "\"sourcetrack TCEN0 crumbstore ECC limit err\"");
                nvswitch_lib_notify_client_events(param_1,1);
                local_94 = CONCAT71(local_94._1_7_,bVar16);
                local_9c = CONCAT44(uVar1,0x5dc1);
                local_94 = CONCAT44(local_f4,(uint)local_94);
                local_8c._0_5_ = (uint5)(uint)local_8c;
                local_84 = CONCAT44(local_84._4_4_,1);
                nvswitch_inforom_ecc_log_err_event(param_1,&local_9c);
              }
              local_b8 = local_b8 & 0xfffffffffffffffe;
            }
            if ((uVar15 & 0x80) == 0) {
              if ((int)local_b8 != 0) {
LAB_001d5978:
                iVar6 = nvswitch_translate_hw_error(0x2713);
                if (iVar6 == 1) {
                  nvswitch_assert_log();
                }
                lVar9 = *param_1;
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),
                                  *(undefined1 *)(lVar9 + 0x44),*(undefined1 *)(lVar9 + 0x45),
                                  *(undefined1 *)(lVar9 + 0x46),0x2713,
                                  "_nvswitch_service_sourcetrack_nonfatal_lr10",0xb2a);
                nvswitch_os_report_error
                          (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                           "_nvswitch_service_sourcetrack_nonfatal_lr10",0xb2a);
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                           "_nvswitch_service_sourcetrack_nonfatal_lr10",0xb2a);
                nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_b8,4,0xb2a,&DAT_00c81851);
              }
            }
            else {
              if ((local_7c & 0x8000) == 0) {
                local_f4 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x64ac);
                local_f4 = local_f4 & 1;
                bVar16 = local_f4 != 0;
                if (bVar16) {
                  local_f4 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x64a8);
                }
                uVar5 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x64a0);
                local_6c = CONCAT44(local_6c._4_4_,uVar5);
                uVar5 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x64a8);
                local_6c = CONCAT44(uVar5,(undefined4)local_6c);
                uVar5 = (*(code *)param_1[0x124])(param_1,5,0,uVar1,0x64ac);
                local_64 = CONCAT44(local_64._4_4_,uVar5);
                iVar6 = nvswitch_translate_hw_error(0x5dc3);
                if (iVar6 == 1) {
                  nvswitch_assert_log();
                }
                pcVar11 = " (First)";
                if ((local_74 & 0x80) == 0) {
                  pcVar11 = "";
                }
                lVar9 = *param_1;
                nvswitch_os_print(5,
                                  "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                  ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),
                                  *(undefined1 *)(lVar9 + 0x44),*(undefined1 *)(lVar9 + 0x45),
                                  *(undefined1 *)(lVar9 + 0x46),0x5dc3,uVar13,
                                  "sourcetrack TCEN1 crumbstore ECC limit err",pcVar11);
                pcVar11 = " (First)";
                if ((local_74 & 0x80) == 0) {
                  pcVar11 = "";
                }
                nvswitch_os_report_error
                          (param_1[3],0x5dc3,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "sourcetrack TCEN1 crumbstore ECC limit err",pcVar11);
                pcVar11 = " (First)";
                if ((local_74 & 0x80) == 0) {
                  pcVar11 = "";
                }
                nvswitch_lib_smbpbi_log_sxid
                          (param_1,0x5dc3,"Non-fatal, Link %02d %s%s\n",uVar1,
                           "sourcetrack TCEN1 crumbstore ECC limit err",pcVar11);
                nvswitch_inforom_bbx_add_sxid(param_1,0x5dc3,0,0,0);
                nvswitch_record_error
                          (param_1,param_1 + 0x24,0x5dc3,uVar1,0,1,0,0,&local_7c,0x20,0xb1d,
                           "\"sourcetrack TCEN1 crumbstore ECC limit err\"");
                nvswitch_lib_notify_client_events(param_1,1);
                local_94 = CONCAT71(local_94._1_7_,bVar16);
                local_9c = CONCAT44(uVar1,0x5dc3);
                local_94 = CONCAT44(local_f4,(uint)local_94);
                local_8c._0_5_ = (uint5)(uint)local_8c;
                local_84 = CONCAT44(local_84._4_4_,1);
                nvswitch_inforom_ecc_log_err_event(param_1,&local_9c);
              }
              uVar3 = local_b8 & 0xffffff7f;
              local_b8 = local_b8 & 0xffffffffffffff7f;
              if (uVar3 != 0) goto LAB_001d5978;
            }
            if ((char)param_1[uVar13 * 8 + 0x1ed] != '\0') {
              (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x640c,local_74._4_4_ ^ uVar15);
            }
            if (((uint)local_74 & local_7c._4_4_) != 0) {
              (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x641c);
            }
            (*(code *)param_1[0x125])(param_1,5,0,uVar1,0x6400,uVar15);
            if ((int)local_b8 != 0) goto LAB_001d73ef;
          }
          local_c0 = local_c0 & ~uVar4;
        }
      }
LAB_001d46e0:
      uVar14 = uVar14 + 1;
    } while (uVar14 != 3);
    uVar4 = 0;
    if (local_c0 != 0) {
      iVar8 = nvswitch_translate_hw_error(0x2713);
      if (iVar8 == 1) {
        nvswitch_assert_log();
      }
      lVar9 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                        ,param_1 + 1,*(undefined4 *)(lVar9 + 0x40),*(undefined1 *)(lVar9 + 0x44),
                        *(undefined1 *)(lVar9 + 0x45),*(undefined1 *)(lVar9 + 0x46),0x2713,
                        "_nvswitch_service_npg_nonfatal_lr10",0xc8b);
      nvswitch_os_report_error
                (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_npg_nonfatal_lr10",0xc8b);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_npg_nonfatal_lr10",0xc8b);
      nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
      nvswitch_record_error(param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_c0,4,0xc8b,&DAT_00c81851)
      ;
      return -(uint)(local_c0 != 0) & 0xfffffff6;
    }
  }
  return uVar4;
}


// ===== 001d755f _nvswitch_service_saw_nonfatal_lr10.cold =====

void _nvswitch_service_saw_nonfatal_lr10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001d75a0 _nvswitch_service_saw_nonfatal_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r12 replaced with injection: x86_indirect_thunk_r12 */
/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */
/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Type propagation algorithm not settling */

uint _nvswitch_service_saw_nonfatal_lr10(long *param_1)

{
  long *plVar1;
  code *pcVar2;
  ulong uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  ulong uVar11;
  long lVar12;
  byte bVar13;
  char *pcVar14;
  uint uVar15;
  ulong uVar16;
  ulong uVar17;
  uint uVar18;
  bool bVar19;
  bool bVar20;
  ulong local_88;
  int local_80;
  uint local_7c;
  uint local_6c;
  uint local_68;
  undefined8 local_64;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  if ((int)param_1[0x3f1] != 6) {
    (*(code *)param_1[0x124])(param_1,1,0,0,0x848);
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar12 = param_1[0x3f2];
  uVar5 = (*(code *)param_1[0x124])(param_1,1,0,0,0x848);
  uVar5 = uVar5 & *(uint *)(&DAT_00009aa0 + lVar12);
  if (uVar5 == 0) {
    return 0xfffffffd;
  }
  iVar6 = (int)param_1[0x3f1];
  uVar15 = 0;
  local_6c = uVar5;
  do {
    if (iVar6 != 6) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    while ((*(char *)(param_1[0x3f2] + 0x3a90 + (ulong)uVar15 * 0x20) == '\0' ||
           (uVar18 = 0x200 << ((byte)uVar15 & 0x1f), (uVar5 & uVar18) == 0))) {
      uVar15 = uVar15 + 1;
      iVar6 = 6;
      if (uVar15 == 9) goto LAB_001d766c;
    }
    iVar6 = _nvswitch_service_npg_nonfatal_lr10(param_1,uVar15);
    if (iVar6 == 0) {
      local_6c = local_6c & ~uVar18;
    }
    uVar15 = uVar15 + 1;
    iVar6 = (int)param_1[0x3f1];
  } while (uVar15 != 9);
LAB_001d766c:
  plVar1 = param_1 + 1;
  local_7c = 0;
LAB_001d76a5:
  if (iVar6 != 6) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  if (*(char *)((ulong)local_7c * 0x20 + param_1[0x3f2] + 0x3d10) != '\0') {
    bVar13 = (byte)local_7c;
    uVar15 = 1 << (bVar13 & 0x1f);
    if ((uVar5 & uVar15) == 0) goto LAB_001d7690;
    iVar6 = (*(code *)param_1[0x150])(param_1,local_7c);
    uVar11 = nvswitch_get_enabled_link_mask(param_1);
    uVar16 = 0xfL << (bVar13 * '\x04' & 0x3f);
    uVar11 = uVar11 & uVar16;
    if (uVar11 == 0) {
      bVar19 = true;
    }
    else {
      iVar9 = -10;
      uVar18 = 0;
      while( true ) {
        for (; (uVar11 & 1) == 0; uVar11 = uVar11 >> 1) {
          uVar18 = uVar18 + 1;
        }
        lVar12 = nvswitch_get_link(param_1,uVar18 & 0xff);
        if (lVar12 == 0) {
          nvswitch_assert_log();
        }
        else {
          uVar7 = nvswitch_get_link_eng_inst(param_1,uVar18,8);
          if (uVar7 != local_7c) {
            nvswitch_assert_log();
            bVar19 = iVar9 != 0;
            goto LAB_001d77ba;
          }
          cVar4 = nvswitch_is_link_in_reset(param_1,lVar12);
          if ((cVar4 == '\0') &&
             (iVar8 = _nvswitch_service_nvldl_nonfatal_link_lr10(param_1,uVar18), iVar8 == 0)) {
            iVar9 = 0;
          }
        }
        if (uVar11 >> 1 == 0) break;
        uVar11 = uVar11 >> 1;
        uVar18 = uVar18 + 1;
      }
      bVar19 = iVar9 != 0;
    }
LAB_001d77ba:
    local_88 = nvswitch_get_enabled_link_mask(param_1);
    local_88 = local_88 & uVar16;
    if (local_88 != 0) {
      local_80 = -10;
      uVar11 = 0;
      do {
        if ((local_88 & 1) != 0) {
          lVar12 = nvswitch_get_link(param_1,uVar11 & 0xff);
          if (lVar12 == 0) {
            nvswitch_assert_log();
          }
          else {
            uVar17 = uVar11 & 0xffffffff;
            uVar18 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,8);
            if (uVar18 != local_7c) {
              nvswitch_assert_log();
              bVar20 = local_80 != 0;
              goto LAB_001d7e7b;
            }
            cVar4 = nvswitch_is_link_in_reset(param_1,lVar12);
            if (cVar4 == '\0') {
              iVar9 = _nvswitch_service_nvltlc_rx_lnk_nonfatal_0_lr10
                                (param_1,local_7c,uVar11 & 0xffffffff);
              if (iVar9 == 0) {
                local_80 = 0;
              }
              iVar9 = _nvswitch_service_nvltlc_tx_lnk_nonfatal_0_lr10(param_1,local_7c,uVar17);
              local_58 = 0;
              if (iVar9 == 0) {
                local_80 = 0;
              }
              local_50 = 0;
              local_48 = 0;
              pcVar2 = (code *)param_1[0x122];
              local_40 = 0;
              uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
              iVar9 = (*pcVar2)(param_1,10,0,uVar10);
              if ((iVar9 == -1) ||
                 (cVar4 = nvswitch_is_link_valid(param_1,uVar11 & 0xffffffff), cVar4 == '\0')) {
                nvswitch_assert_log();
              }
              pcVar2 = (code *)param_1[0x124];
              uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
              uVar10 = (*pcVar2)(param_1,10,0,uVar10,0x1aa0);
              local_58 = CONCAT44(local_58._4_4_,uVar10);
              pcVar2 = (code *)param_1[0x122];
              uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
              iVar9 = (*pcVar2)(param_1,10,0,uVar10);
              if ((iVar9 == -1) ||
                 (cVar4 = nvswitch_is_link_valid(param_1,uVar11 & 0xffffffff), cVar4 == '\0')) {
                nvswitch_assert_log();
              }
              pcVar2 = (code *)param_1[0x124];
              uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
              uVar18 = (*pcVar2)(param_1,10,0,uVar10,0x1aac);
              local_50 = CONCAT44(uVar18,(uint)local_50);
              local_58 = CONCAT44(uVar18,(uint)local_58);
              uVar18 = uVar18 & (uint)local_58;
              local_64 = CONCAT62(local_64._2_6_,CONCAT11((char)uVar11,bVar13)) & 0xffffffffffff03ff
              ;
              if (uVar18 != 0) {
                pcVar2 = (code *)param_1[0x122];
                local_68 = uVar18;
                uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                iVar9 = (*pcVar2)(param_1,10,0,uVar10);
                if ((iVar9 == -1) ||
                   (cVar4 = nvswitch_is_link_valid(param_1,uVar11 & 0xffffffff), cVar4 == '\0')) {
                  nvswitch_assert_log();
                }
                pcVar2 = (code *)param_1[0x124];
                uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                uVar10 = (*pcVar2)(param_1,10,0,uVar10,0x1abc);
                local_50 = CONCAT44(local_50._4_4_,uVar10);
                pcVar2 = (code *)param_1[0x122];
                uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                iVar9 = (*pcVar2)(param_1,10,0,uVar10);
                if ((iVar9 == -1) ||
                   (cVar4 = nvswitch_is_link_valid(param_1,uVar11 & 0xffffffff), cVar4 == '\0')) {
                  nvswitch_assert_log();
                }
                pcVar2 = (code *)param_1[0x124];
                uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                uVar7 = (*pcVar2)(param_1,10,0,uVar10,0x1ab8);
                if ((uVar18 & 0x40000) != 0) {
                  iVar9 = nvswitch_translate_hw_error(0x4a8c);
                  if (iVar9 == 1) {
                    nvswitch_assert_log();
                  }
                  lVar12 = *param_1;
                  pcVar14 = "";
                  if ((local_50 & 0x40000) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_os_print(5,
                                    "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                    ,plVar1,*(undefined4 *)(lVar12 + 0x40),
                                    *(undefined1 *)(lVar12 + 0x44),*(undefined1 *)(lVar12 + 0x45),
                                    *(undefined1 *)(lVar12 + 0x46),0x4a8c,uVar17,
                                    "AN1 Heartbeat Timeout Error",pcVar14);
                  pcVar14 = "";
                  if ((local_50 & 0x40000) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_os_report_error
                            (param_1[3],0x4a8c,"Non-fatal, Link %02d %s%s\n",uVar11 & 0xffffffff,
                             "AN1 Heartbeat Timeout Error",pcVar14);
                  pcVar14 = "";
                  if ((local_50 & 0x40000) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_lib_smbpbi_log_sxid
                            (param_1,0x4a8c,"Non-fatal, Link %02d %s%s\n",uVar11 & 0xffffffff,
                             "AN1 Heartbeat Timeout Error",pcVar14);
                  nvswitch_inforom_bbx_add_sxid(param_1,0x4a8c,0,0,0);
                  nvswitch_record_error
                            (param_1,param_1 + 0x24,0x4a8c,uVar11 & 0xffffffff,0,1,0,0,&local_58,
                             0x20,0xe75,"\"AN1 Heartbeat Timeout Error\"");
                  nvswitch_lib_notify_client_events(param_1,1);
                  local_68 = local_68 & 0xfffbffff;
                  if ((uVar7 & 0x40000) == 0) {
                    local_64 = CONCAT44(0x27,(undefined4)local_64);
                    nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
                    local_50 = local_50 & 0xfffbffffffffffff;
                    pcVar2 = (code *)param_1[0x122];
                    uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                    iVar9 = (*pcVar2)(param_1,10,0,uVar10);
                    if ((iVar9 == -1) ||
                       (cVar4 = nvswitch_is_link_valid(param_1,uVar11 & 0xffffffff), cVar4 == '\0'))
                    {
                      nvswitch_assert_log();
                    }
                    uVar3 = local_50 >> 0x20;
                    pcVar2 = (code *)param_1[0x125];
                    uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                    (*pcVar2)(param_1,10,0,uVar10,0x1aac,uVar3);
                  }
                }
                if (local_68 != 0) {
                  iVar9 = nvswitch_translate_hw_error(0x2713);
                  if (iVar9 == 1) {
                    nvswitch_assert_log();
                  }
                  lVar12 = *param_1;
                  nvswitch_os_print(5,
                                    "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                                    ,plVar1,*(undefined4 *)(lVar12 + 0x40),
                                    *(undefined1 *)(lVar12 + 0x44),*(undefined1 *)(lVar12 + 0x45),
                                    *(undefined1 *)(lVar12 + 0x46),0x2713,
                                    "_nvswitch_service_nvltlc_rx_lnk_nonfatal_1_lr10",0xe8b);
                  nvswitch_os_report_error
                            (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                             "_nvswitch_service_nvltlc_rx_lnk_nonfatal_1_lr10",0xe8b);
                  nvswitch_lib_smbpbi_log_sxid
                            (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                             "_nvswitch_service_nvltlc_rx_lnk_nonfatal_1_lr10",0xe8b);
                  nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
                  nvswitch_record_error
                            (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_68,4,0xe8b,&DAT_00c81851
                            );
                }
                if ((char)param_1[uVar11 * 8 + 0x1ed] == '\0') {
                  uVar7 = local_58._4_4_ & (uint)local_50;
                }
                else {
                  pcVar2 = (code *)param_1[0x122];
                  uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                  iVar9 = (*pcVar2)(param_1,10,0,uVar10);
                  if ((iVar9 == -1) ||
                     (cVar4 = nvswitch_is_link_valid(param_1,uVar11 & 0xffffffff), cVar4 == '\0')) {
                    nvswitch_assert_log();
                  }
                  pcVar2 = (code *)param_1[0x125];
                  uVar7 = ~uVar18 & local_50._4_4_;
                  uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                  (*pcVar2)(param_1,10,0,uVar10,0x1aac,uVar7);
                  uVar7 = local_58._4_4_ & (uint)local_50;
                }
                if (uVar7 != 0) {
                  pcVar2 = (code *)param_1[0x122];
                  uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                  iVar9 = (*pcVar2)(param_1,10,0,uVar10);
                  if ((iVar9 == -1) ||
                     (cVar4 = nvswitch_is_link_valid(param_1,uVar11 & 0xffffffff), cVar4 == '\0')) {
                    nvswitch_assert_log();
                  }
                  pcVar2 = (code *)param_1[0x125];
                  uVar7 = (uint)local_50 & local_58._4_4_;
                  uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                  (*pcVar2)(param_1,10,0,uVar10,0x1abc,uVar7);
                }
                pcVar2 = (code *)param_1[0x122];
                uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                iVar9 = (*pcVar2)(param_1,10,0,uVar10);
                if ((iVar9 == -1) ||
                   (cVar4 = nvswitch_is_link_valid(param_1,uVar11 & 0xffffffff), cVar4 == '\0')) {
                  nvswitch_assert_log();
                }
                pcVar2 = (code *)param_1[0x125];
                uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                (*pcVar2)(param_1,10,0,uVar10,0x1aa0,uVar18);
                if (local_68 == 0) {
                  local_80 = 0;
                }
              }
              local_58 = 0;
              local_50 = 0;
              pcVar2 = (code *)param_1[0x122];
              local_48 = 0;
              local_40 = 0;
              local_64 = 0;
              local_5c = 0;
              uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
              iVar9 = (*pcVar2)(param_1,10,0,uVar10);
              if ((iVar9 == -1) ||
                 (cVar4 = nvswitch_is_link_valid(param_1,uVar11 & 0xffffffff), cVar4 == '\0')) {
                nvswitch_assert_log();
              }
              pcVar2 = (code *)param_1[0x124];
              uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
              uVar10 = (*pcVar2)(param_1,10,0,uVar10,0x12a0);
              local_58 = CONCAT44(local_58._4_4_,uVar10);
              pcVar2 = (code *)param_1[0x122];
              uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
              iVar9 = (*pcVar2)(param_1,10,0,uVar10);
              if ((iVar9 == -1) ||
                 (cVar4 = nvswitch_is_link_valid(param_1,uVar11 & 0xffffffff), cVar4 == '\0')) {
                nvswitch_assert_log();
              }
              pcVar2 = (code *)param_1[0x124];
              uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
              uVar18 = (*pcVar2)(param_1,10,0,uVar10,0x12ac);
              local_50 = CONCAT44(uVar18,(uint)local_50);
              local_58 = CONCAT44(uVar18,(uint)local_58);
              uVar18 = uVar18 & (uint)local_58;
              local_64 = CONCAT62(local_64._2_6_,CONCAT11((char)uVar11,bVar13)) & 0xffffffffffff03ff
              ;
              if (uVar18 != 0) {
                pcVar2 = (code *)param_1[0x122];
                local_68 = uVar18;
                uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                iVar9 = (*pcVar2)(param_1,10,0,uVar10);
                if ((iVar9 == -1) ||
                   (cVar4 = nvswitch_is_link_valid(param_1,uVar11 & 0xffffffff), cVar4 == '\0')) {
                  nvswitch_assert_log();
                }
                pcVar2 = (code *)param_1[0x124];
                uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                uVar10 = (*pcVar2)(param_1,10,0,uVar10,0x12bc);
                local_50 = CONCAT44(local_50._4_4_,uVar10);
                pcVar2 = (code *)param_1[0x122];
                uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                iVar9 = (*pcVar2)(param_1,10,0,uVar10);
                if ((iVar9 == -1) ||
                   (cVar4 = nvswitch_is_link_valid(param_1,uVar11 & 0xffffffff), cVar4 == '\0')) {
                  nvswitch_assert_log();
                }
                pcVar2 = (code *)param_1[0x124];
                uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                uVar7 = (*pcVar2)(param_1,10,0,uVar10,0x12b8);
                if ((uVar18 & 1) != 0) {
                  iVar9 = nvswitch_translate_hw_error(0x4a80);
                  if (iVar9 == 1) {
                    nvswitch_assert_log();
                  }
                  lVar12 = *param_1;
                  pcVar14 = "";
                  if ((local_50 & 1) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_os_print(5,
                                    "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                    ,plVar1,*(undefined4 *)(lVar12 + 0x40),
                                    *(undefined1 *)(lVar12 + 0x44),*(undefined1 *)(lVar12 + 0x45),
                                    *(undefined1 *)(lVar12 + 0x46),0x4a80,uVar17,"AN1 Timeout VC0",
                                    pcVar14);
                  pcVar14 = "";
                  if ((local_50 & 1) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_os_report_error
                            (param_1[3],0x4a80,"Non-fatal, Link %02d %s%s\n",uVar11 & 0xffffffff,
                             "AN1 Timeout VC0",pcVar14);
                  pcVar14 = "";
                  if ((local_50 & 1) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_lib_smbpbi_log_sxid
                            (param_1,0x4a80,"Non-fatal, Link %02d %s%s\n",uVar11 & 0xffffffff,
                             "AN1 Timeout VC0",pcVar14);
                  nvswitch_inforom_bbx_add_sxid(param_1,0x4a80,0,0,0);
                  nvswitch_record_error
                            (param_1,param_1 + 0x24,0x4a80,uVar11 & 0xffffffff,0,1,0,0,&local_58,
                             0x20,0xec7,"\"AN1 Timeout VC0\"");
                  nvswitch_lib_notify_client_events(param_1,1);
                  local_68 = local_68 & 0xfffffffe;
                  if ((uVar7 & 1) == 0) {
                    local_64 = CONCAT44(0x2d,(undefined4)local_64);
                    nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
                  }
                }
                if ((uVar18 & 2) != 0) {
                  iVar9 = nvswitch_translate_hw_error(0x4a81);
                  if (iVar9 == 1) {
                    nvswitch_assert_log();
                  }
                  lVar12 = *param_1;
                  pcVar14 = "";
                  if ((local_50 & 2) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_os_print(5,
                                    "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                    ,plVar1,*(undefined4 *)(lVar12 + 0x40),
                                    *(undefined1 *)(lVar12 + 0x44),*(undefined1 *)(lVar12 + 0x45),
                                    *(undefined1 *)(lVar12 + 0x46),0x4a81,uVar17,"AN1 Timeout VC1",
                                    pcVar14);
                  pcVar14 = "";
                  if ((local_50 & 2) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_os_report_error
                            (param_1[3],0x4a81,"Non-fatal, Link %02d %s%s\n",uVar11 & 0xffffffff,
                             "AN1 Timeout VC1",pcVar14);
                  pcVar14 = "";
                  if ((local_50 & 2) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_lib_smbpbi_log_sxid
                            (param_1,0x4a81,"Non-fatal, Link %02d %s%s\n",uVar11 & 0xffffffff,
                             "AN1 Timeout VC1",pcVar14);
                  nvswitch_inforom_bbx_add_sxid(param_1,0x4a81,0,0,0);
                  nvswitch_record_error
                            (param_1,param_1 + 0x24,0x4a81,uVar11 & 0xffffffff,0,1,0,0,&local_58,
                             0x20,0xed4,"\"AN1 Timeout VC1\"");
                  nvswitch_lib_notify_client_events(param_1,1);
                  local_68 = local_68 & 0xfffffffd;
                  if ((uVar7 & 2) == 0) {
                    local_64 = CONCAT44(0x2e,(undefined4)local_64);
                    nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
                  }
                }
                if ((uVar18 & 4) != 0) {
                  iVar9 = nvswitch_translate_hw_error(0x4a82);
                  if (iVar9 == 1) {
                    nvswitch_assert_log();
                  }
                  lVar12 = *param_1;
                  pcVar14 = "";
                  if ((local_50 & 4) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_os_print(5,
                                    "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                    ,plVar1,*(undefined4 *)(lVar12 + 0x40),
                                    *(undefined1 *)(lVar12 + 0x44),*(undefined1 *)(lVar12 + 0x45),
                                    *(undefined1 *)(lVar12 + 0x46),0x4a82,uVar17,"AN1 Timeout VC2",
                                    pcVar14);
                  pcVar14 = "";
                  if ((local_50 & 4) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_os_report_error
                            (param_1[3],0x4a82,"Non-fatal, Link %02d %s%s\n",uVar11 & 0xffffffff,
                             "AN1 Timeout VC2",pcVar14);
                  pcVar14 = "";
                  if ((local_50 & 4) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_lib_smbpbi_log_sxid
                            (param_1,0x4a82,"Non-fatal, Link %02d %s%s\n",uVar11 & 0xffffffff,
                             "AN1 Timeout VC2",pcVar14);
                  nvswitch_inforom_bbx_add_sxid(param_1,0x4a82,0,0,0);
                  nvswitch_record_error
                            (param_1,param_1 + 0x24,0x4a82,uVar11 & 0xffffffff,0,1,0,0,&local_58,
                             0x20,0xee1,"\"AN1 Timeout VC2\"");
                  nvswitch_lib_notify_client_events(param_1,1);
                  local_68 = local_68 & 0xfffffffb;
                  if ((uVar7 & 4) == 0) {
                    local_64 = CONCAT44(0x2f,(undefined4)local_64);
                    nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
                  }
                }
                if ((uVar18 & 8) != 0) {
                  iVar9 = nvswitch_translate_hw_error(0x4a83);
                  if (iVar9 == 1) {
                    nvswitch_assert_log();
                  }
                  lVar12 = *param_1;
                  pcVar14 = "";
                  if ((local_50 & 8) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_os_print(5,
                                    "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                    ,plVar1,*(undefined4 *)(lVar12 + 0x40),
                                    *(undefined1 *)(lVar12 + 0x44),*(undefined1 *)(lVar12 + 0x45),
                                    *(undefined1 *)(lVar12 + 0x46),0x4a83,uVar17,"AN1 Timeout VC3",
                                    pcVar14);
                  pcVar14 = "";
                  if ((local_50 & 8) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_os_report_error
                            (param_1[3],0x4a83,"Non-fatal, Link %02d %s%s\n",uVar11 & 0xffffffff,
                             "AN1 Timeout VC3",pcVar14);
                  pcVar14 = "";
                  if ((local_50 & 8) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_lib_smbpbi_log_sxid
                            (param_1,0x4a83,"Non-fatal, Link %02d %s%s\n",uVar11 & 0xffffffff,
                             "AN1 Timeout VC3",pcVar14);
                  nvswitch_inforom_bbx_add_sxid(param_1,0x4a83,0,0,0);
                  nvswitch_record_error
                            (param_1,param_1 + 0x24,0x4a83,uVar11 & 0xffffffff,0,1,0,0,&local_58,
                             0x20,0xeee,"\"AN1 Timeout VC3\"");
                  nvswitch_lib_notify_client_events(param_1,1);
                  local_68 = local_68 & 0xfffffff7;
                  if ((uVar7 & 8) == 0) {
                    local_64 = CONCAT44(0x30,(undefined4)local_64);
                    nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
                  }
                }
                if ((uVar18 & 0x10) != 0) {
                  iVar9 = nvswitch_translate_hw_error(0x4a84);
                  if (iVar9 == 1) {
                    nvswitch_assert_log();
                  }
                  lVar12 = *param_1;
                  pcVar14 = "";
                  if ((local_50 & 0x10) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_os_print(5,
                                    "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                    ,plVar1,*(undefined4 *)(lVar12 + 0x40),
                                    *(undefined1 *)(lVar12 + 0x44),*(undefined1 *)(lVar12 + 0x45),
                                    *(undefined1 *)(lVar12 + 0x46),0x4a84,uVar17,"AN1 Timeout VC4",
                                    pcVar14);
                  pcVar14 = "";
                  if ((local_50 & 0x10) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_os_report_error
                            (param_1[3],0x4a84,"Non-fatal, Link %02d %s%s\n",uVar11 & 0xffffffff,
                             "AN1 Timeout VC4",pcVar14);
                  pcVar14 = "";
                  if ((local_50 & 0x10) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_lib_smbpbi_log_sxid
                            (param_1,0x4a84,"Non-fatal, Link %02d %s%s\n",uVar11 & 0xffffffff,
                             "AN1 Timeout VC4",pcVar14);
                  nvswitch_inforom_bbx_add_sxid(param_1,0x4a84,0,0,0);
                  nvswitch_record_error
                            (param_1,param_1 + 0x24,0x4a84,uVar11 & 0xffffffff,0,1,0,0,&local_58,
                             0x20,0xefb,"\"AN1 Timeout VC4\"");
                  nvswitch_lib_notify_client_events(param_1,1);
                  local_68 = local_68 & 0xffffffef;
                  if ((uVar7 & 0x10) == 0) {
                    local_64 = CONCAT44(0x31,(undefined4)local_64);
                    nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
                  }
                }
                if ((uVar18 & 0x20) != 0) {
                  iVar9 = nvswitch_translate_hw_error(0x4a85);
                  if (iVar9 == 1) {
                    nvswitch_assert_log();
                  }
                  lVar12 = *param_1;
                  pcVar14 = "";
                  if ((local_50 & 0x20) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_os_print(5,
                                    "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                    ,plVar1,*(undefined4 *)(lVar12 + 0x40),
                                    *(undefined1 *)(lVar12 + 0x44),*(undefined1 *)(lVar12 + 0x45),
                                    *(undefined1 *)(lVar12 + 0x46),0x4a85,uVar17,"AN1 Timeout VC5",
                                    pcVar14);
                  pcVar14 = "";
                  if ((local_50 & 0x20) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_os_report_error
                            (param_1[3],0x4a85,"Non-fatal, Link %02d %s%s\n",uVar11 & 0xffffffff,
                             "AN1 Timeout VC5",pcVar14);
                  pcVar14 = "";
                  if ((local_50 & 0x20) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_lib_smbpbi_log_sxid
                            (param_1,0x4a85,"Non-fatal, Link %02d %s%s\n",uVar11 & 0xffffffff,
                             "AN1 Timeout VC5",pcVar14);
                  nvswitch_inforom_bbx_add_sxid(param_1,0x4a85,0,0,0);
                  nvswitch_record_error
                            (param_1,param_1 + 0x24,0x4a85,uVar11 & 0xffffffff,0,1,0,0,&local_58,
                             0x20,0xf08,"\"AN1 Timeout VC5\"");
                  nvswitch_lib_notify_client_events(param_1,1);
                  local_68 = local_68 & 0xffffffdf;
                  if ((uVar7 & 0x20) == 0) {
                    local_64 = CONCAT44(0x32,(undefined4)local_64);
                    nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
                  }
                }
                if ((uVar18 & 0x40) != 0) {
                  iVar9 = nvswitch_translate_hw_error(0x4a86);
                  if (iVar9 == 1) {
                    nvswitch_assert_log();
                  }
                  lVar12 = *param_1;
                  pcVar14 = "";
                  if ((local_50 & 0x40) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_os_print(5,
                                    "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                    ,plVar1,*(undefined4 *)(lVar12 + 0x40),
                                    *(undefined1 *)(lVar12 + 0x44),*(undefined1 *)(lVar12 + 0x45),
                                    *(undefined1 *)(lVar12 + 0x46),0x4a86,uVar17,"AN1 Timeout VC6",
                                    pcVar14);
                  pcVar14 = "";
                  if ((local_50 & 0x40) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_os_report_error
                            (param_1[3],0x4a86,"Non-fatal, Link %02d %s%s\n",uVar11 & 0xffffffff,
                             "AN1 Timeout VC6",pcVar14);
                  pcVar14 = "";
                  if ((local_50 & 0x40) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_lib_smbpbi_log_sxid
                            (param_1,0x4a86,"Non-fatal, Link %02d %s%s\n",uVar11 & 0xffffffff,
                             "AN1 Timeout VC6",pcVar14);
                  nvswitch_inforom_bbx_add_sxid(param_1,0x4a86,0,0,0);
                  nvswitch_record_error
                            (param_1,param_1 + 0x24,0x4a86,uVar11 & 0xffffffff,0,1,0,0,&local_58,
                             0x20,0xf15,"\"AN1 Timeout VC6\"");
                  nvswitch_lib_notify_client_events(param_1,1);
                  local_68 = local_68 & 0xffffffbf;
                  if ((uVar7 & 0x40) == 0) {
                    local_64 = CONCAT44(0x33,(undefined4)local_64);
                    nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
                  }
                }
                if ((uVar18 & 0x80) != 0) {
                  iVar9 = nvswitch_translate_hw_error(0x4a87);
                  if (iVar9 == 1) {
                    nvswitch_assert_log();
                  }
                  lVar12 = *param_1;
                  pcVar14 = "";
                  if ((local_50 & 0x80) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_os_print(5,
                                    "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                    ,plVar1,*(undefined4 *)(lVar12 + 0x40),
                                    *(undefined1 *)(lVar12 + 0x44),*(undefined1 *)(lVar12 + 0x45),
                                    *(undefined1 *)(lVar12 + 0x46),0x4a87,uVar17,"AN1 Timeout VC7",
                                    pcVar14);
                  pcVar14 = "";
                  if ((local_50 & 0x80) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_os_report_error
                            (param_1[3],0x4a87,"Non-fatal, Link %02d %s%s\n",uVar11 & 0xffffffff,
                             "AN1 Timeout VC7",pcVar14);
                  pcVar14 = "";
                  if ((local_50 & 0x80) != 0) {
                    pcVar14 = " (First)";
                  }
                  nvswitch_lib_smbpbi_log_sxid
                            (param_1,0x4a87,"Non-fatal, Link %02d %s%s\n",uVar11 & 0xffffffff,
                             "AN1 Timeout VC7",pcVar14);
                  nvswitch_inforom_bbx_add_sxid(param_1,0x4a87,0,0,0);
                  nvswitch_record_error
                            (param_1,param_1 + 0x24,0x4a87,uVar11 & 0xffffffff,0,1,0,0,&local_58,
                             0x20,0xf22,"\"AN1 Timeout VC7\"");
                  nvswitch_lib_notify_client_events(param_1,1);
                  local_68 = local_68 & 0xffffff7f;
                  if ((uVar7 & 0x80) == 0) {
                    local_64 = CONCAT44(0x34,(undefined4)local_64);
                    nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
                  }
                }
                if (local_68 != 0) {
                  iVar9 = nvswitch_translate_hw_error(0x2713);
                  if (iVar9 == 1) {
                    nvswitch_assert_log();
                  }
                  lVar12 = *param_1;
                  nvswitch_os_print(5,
                                    "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                                    ,plVar1,*(undefined4 *)(lVar12 + 0x40),
                                    *(undefined1 *)(lVar12 + 0x44),*(undefined1 *)(lVar12 + 0x45),
                                    *(undefined1 *)(lVar12 + 0x46),0x2713,
                                    "_nvswitch_service_nvltlc_tx_lnk_nonfatal_1_lr10",0xf2c);
                  nvswitch_os_report_error
                            (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                             "_nvswitch_service_nvltlc_tx_lnk_nonfatal_1_lr10",0xf2c);
                  nvswitch_lib_smbpbi_log_sxid
                            (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                             "_nvswitch_service_nvltlc_tx_lnk_nonfatal_1_lr10",0xf2c);
                  nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
                  nvswitch_record_error
                            (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_68,4,0xf2c,&DAT_00c81851
                            );
                }
                if ((char)param_1[uVar11 * 8 + 0x1ed] != '\0') {
                  pcVar2 = (code *)param_1[0x122];
                  uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                  iVar9 = (*pcVar2)(param_1,10,0,uVar10);
                  if ((iVar9 == -1) ||
                     (cVar4 = nvswitch_is_link_valid(param_1,uVar11 & 0xffffffff), cVar4 == '\0')) {
                    nvswitch_assert_log();
                  }
                  pcVar2 = (code *)param_1[0x125];
                  uVar7 = local_50._4_4_ ^ uVar18;
                  uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                  (*pcVar2)(param_1,10,0,uVar10,0x12ac,uVar7);
                }
                if ((local_58._4_4_ & (uint)local_50) != 0) {
                  pcVar2 = (code *)param_1[0x122];
                  uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                  iVar9 = (*pcVar2)(param_1,10,0,uVar10);
                  if ((iVar9 == -1) ||
                     (cVar4 = nvswitch_is_link_valid(param_1,uVar11 & 0xffffffff), cVar4 == '\0')) {
                    nvswitch_assert_log();
                  }
                  pcVar2 = (code *)param_1[0x125];
                  uVar7 = (uint)local_50 & local_58._4_4_;
                  uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                  (*pcVar2)(param_1,10,0,uVar10,0x12bc,uVar7);
                }
                pcVar2 = (code *)param_1[0x122];
                uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                iVar9 = (*pcVar2)(param_1,10,0,uVar10);
                if ((iVar9 == -1) ||
                   (cVar4 = nvswitch_is_link_valid(param_1,uVar11 & 0xffffffff), cVar4 == '\0')) {
                  nvswitch_assert_log();
                }
                pcVar2 = (code *)param_1[0x125];
                uVar10 = nvswitch_get_link_eng_inst(param_1,uVar11 & 0xffffffff,10);
                (*pcVar2)(param_1,10,0,uVar10,0x12a0,uVar18);
                if (local_68 == 0) {
                  local_80 = 0;
                }
              }
            }
          }
          if (local_88 >> 1 == 0) goto LAB_001d7e70;
        }
        local_88 = local_88 >> 1;
        uVar11 = uVar11 + 1;
      } while( true );
    }
    bVar20 = true;
    goto LAB_001d7e7b;
  }
  goto LAB_001d7690;
LAB_001d7e70:
  bVar20 = local_80 != 0;
LAB_001d7e7b:
  uVar11 = nvswitch_get_enabled_link_mask(param_1);
  uVar16 = uVar16 & uVar11;
  if (uVar16 == 0) {
LAB_001d9f03:
    if (((bool)(bVar19 & iVar6 != 0)) && (bVar20)) goto LAB_001d7690;
  }
  else {
    uVar11 = 0;
    iVar9 = 0;
    while( true ) {
      for (; (uVar16 & 1) == 0; uVar16 = uVar16 >> 1) {
        iVar9 = iVar9 + 1;
      }
      pcVar2 = (code *)param_1[0x122];
      uVar10 = nvswitch_get_link_eng_inst(param_1,iVar9,9);
      iVar8 = (*pcVar2)(param_1,9,0,uVar10);
      if ((iVar8 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,iVar9), cVar4 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = (code *)param_1[0x124];
      uVar10 = nvswitch_get_link_eng_inst(param_1,iVar9,9);
      iVar8 = (*pcVar2)(param_1,9,0,uVar10,0x280);
      if (iVar8 != 0) {
        uVar11 = (uint)(1 << ((byte)iVar9 & 0x1f)) | uVar11;
      }
      uVar16 = uVar16 >> 1;
      if (uVar16 == 0) break;
      iVar9 = iVar9 + 1;
    }
    if (uVar11 == 0) goto LAB_001d9f03;
    iVar9 = 0;
    while( true ) {
      for (; (uVar11 & 1) == 0; uVar11 = uVar11 >> 1) {
        iVar9 = iVar9 + 1;
      }
      local_58 = 0;
      local_50 = 0;
      pcVar2 = (code *)param_1[0x122];
      local_48 = 0;
      local_40 = 0;
      local_64 = 0;
      local_5c = 0;
      uVar10 = nvswitch_get_link_eng_inst(param_1,iVar9,9);
      iVar8 = (*pcVar2)(param_1,9,0,uVar10);
      if ((iVar8 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,iVar9), cVar4 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = (code *)param_1[0x124];
      uVar10 = nvswitch_get_link_eng_inst(param_1,iVar9,9);
      uVar10 = (*pcVar2)(param_1,9,0,uVar10,0x280);
      local_58 = CONCAT44(local_58._4_4_,uVar10);
      pcVar2 = (code *)param_1[0x122];
      uVar10 = nvswitch_get_link_eng_inst(param_1,iVar9,9);
      iVar8 = (*pcVar2)(param_1,9,0,uVar10);
      if ((iVar8 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,iVar9), cVar4 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = (code *)param_1[0x124];
      uVar10 = nvswitch_get_link_eng_inst(param_1,iVar9,9);
      uVar18 = (*pcVar2)(param_1,9,0,uVar10,0x28c);
      local_50 = CONCAT44(uVar18,(uint)local_50);
      local_58 = CONCAT44(uVar18,(uint)local_58);
      uVar18 = uVar18 & (uint)local_58;
      local_64 = CONCAT62(local_64._2_6_,CONCAT11((char)iVar9,bVar13)) & 0xffffffffffff03ff;
      if (uVar18 == 0) break;
      pcVar2 = (code *)param_1[0x122];
      local_68 = uVar18;
      uVar10 = nvswitch_get_link_eng_inst(param_1,iVar9,9);
      iVar8 = (*pcVar2)(param_1,9,0,uVar10);
      if ((iVar8 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,iVar9), cVar4 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = (code *)param_1[0x124];
      uVar10 = nvswitch_get_link_eng_inst(param_1,iVar9,9);
      uVar10 = (*pcVar2)(param_1,9,0,uVar10,0x29c);
      local_50 = CONCAT44(local_50._4_4_,uVar10);
      pcVar2 = (code *)param_1[0x122];
      uVar10 = nvswitch_get_link_eng_inst(param_1,iVar9,9);
      iVar8 = (*pcVar2)(param_1,9,0,uVar10);
      if ((iVar8 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,iVar9), cVar4 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = (code *)param_1[0x124];
      uVar10 = nvswitch_get_link_eng_inst(param_1,iVar9,9);
      uVar7 = (*pcVar2)(param_1,9,0,uVar10,0x298);
      if ((uVar18 & 2) != 0) {
        iVar8 = nvswitch_translate_hw_error(0x61a9);
        if (iVar8 == 1) {
          nvswitch_assert_log();
        }
        lVar12 = *param_1;
        pcVar14 = "";
        if ((local_50 & 2) != 0) {
          pcVar14 = " (First)";
        }
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                          ,plVar1,*(undefined4 *)(lVar12 + 0x40),*(undefined1 *)(lVar12 + 0x44),
                          *(undefined1 *)(lVar12 + 0x45),*(undefined1 *)(lVar12 + 0x46),0x61a9,iVar9
                          ,"_HW_NVLIPT_LNK_ILLEGALLINKSTATEREQUEST",pcVar14);
        pcVar14 = "";
        if ((local_50 & 2) != 0) {
          pcVar14 = " (First)";
        }
        nvswitch_os_report_error
                  (param_1[3],0x61a9,"Non-fatal, Link %02d %s%s\n",iVar9,
                   "_HW_NVLIPT_LNK_ILLEGALLINKSTATEREQUEST",pcVar14);
        pcVar14 = "";
        if ((local_50 & 2) != 0) {
          pcVar14 = " (First)";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x61a9,"Non-fatal, Link %02d %s%s\n",iVar9,
                   "_HW_NVLIPT_LNK_ILLEGALLINKSTATEREQUEST",pcVar14);
        nvswitch_inforom_bbx_add_sxid(param_1,0x61a9,0,0,0);
        nvswitch_record_error
                  (param_1,param_1 + 0x24,0x61a9,iVar9,0,1,0,0,&local_58,0x20,0xfa6,
                   "\"_HW_NVLIPT_LNK_ILLEGALLINKSTATEREQUEST\"");
        nvswitch_lib_notify_client_events(param_1,1);
        local_68 = local_68 & 0xfffffffd;
        if ((uVar7 & 2) == 0) {
          local_64 = CONCAT44(0x3f,(undefined4)local_64);
          nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
        }
      }
      if ((uVar18 & 4) != 0) {
        iVar8 = nvswitch_translate_hw_error(0x61aa);
        if (iVar8 == 1) {
          nvswitch_assert_log();
        }
        lVar12 = *param_1;
        pcVar14 = "";
        if ((local_50 & 4) != 0) {
          pcVar14 = " (First)";
        }
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                          ,plVar1,*(undefined4 *)(lVar12 + 0x40),*(undefined1 *)(lVar12 + 0x44),
                          *(undefined1 *)(lVar12 + 0x45),*(undefined1 *)(lVar12 + 0x46),0x61aa,iVar9
                          ,"_FAILEDMINIONREQUEST",pcVar14);
        pcVar14 = "";
        if ((local_50 & 4) != 0) {
          pcVar14 = " (First)";
        }
        nvswitch_os_report_error
                  (param_1[3],0x61aa,"Non-fatal, Link %02d %s%s\n",iVar9,"_FAILEDMINIONREQUEST",
                   pcVar14);
        pcVar14 = "";
        if ((local_50 & 4) != 0) {
          pcVar14 = " (First)";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x61aa,"Non-fatal, Link %02d %s%s\n",iVar9,"_FAILEDMINIONREQUEST",pcVar14
                  );
        nvswitch_inforom_bbx_add_sxid(param_1,0x61aa,0,0,0);
        nvswitch_record_error
                  (param_1,param_1 + 0x24,0x61aa,iVar9,0,1,0,0,&local_58,0x20,0xfb3,
                   "\"_FAILEDMINIONREQUEST\"");
        nvswitch_lib_notify_client_events(param_1,1);
        local_68 = local_68 & 0xfffffffb;
        if ((uVar7 & 4) == 0) {
          local_64 = CONCAT44(0x40,(undefined4)local_64);
          nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
        }
      }
      if ((uVar18 & 8) != 0) {
        iVar8 = nvswitch_translate_hw_error(0x61ab);
        if (iVar8 == 1) {
          nvswitch_assert_log();
        }
        lVar12 = *param_1;
        pcVar14 = "";
        if ((local_50 & 8) != 0) {
          pcVar14 = " (First)";
        }
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                          ,plVar1,*(undefined4 *)(lVar12 + 0x40),*(undefined1 *)(lVar12 + 0x44),
                          *(undefined1 *)(lVar12 + 0x45),*(undefined1 *)(lVar12 + 0x46),0x61ab,iVar9
                          ,"_RESERVEDREQUESTVALUE",pcVar14);
        pcVar14 = "";
        if ((local_50 & 8) != 0) {
          pcVar14 = " (First)";
        }
        nvswitch_os_report_error
                  (param_1[3],0x61ab,"Non-fatal, Link %02d %s%s\n",iVar9,"_RESERVEDREQUESTVALUE",
                   pcVar14);
        pcVar14 = "";
        if ((local_50 & 8) != 0) {
          pcVar14 = " (First)";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x61ab,"Non-fatal, Link %02d %s%s\n",iVar9,"_RESERVEDREQUESTVALUE",
                   pcVar14);
        nvswitch_inforom_bbx_add_sxid(param_1,0x61ab,0,0,0);
        nvswitch_record_error
                  (param_1,param_1 + 0x24,0x61ab,iVar9,0,1,0,0,&local_58,0x20,0xfc0,
                   "\"_RESERVEDREQUESTVALUE\"");
        nvswitch_lib_notify_client_events(param_1,1);
        local_68 = local_68 & 0xfffffff7;
        if ((uVar7 & 8) == 0) {
          local_64 = CONCAT44(0x41,(undefined4)local_64);
          nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
        }
      }
      if ((uVar18 & 0x10) != 0) {
        iVar8 = nvswitch_translate_hw_error(0x61ac);
        if (iVar8 == 1) {
          nvswitch_assert_log();
        }
        lVar12 = *param_1;
        pcVar14 = "";
        if ((local_50 & 0x10) != 0) {
          pcVar14 = " (First)";
        }
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                          ,plVar1,*(undefined4 *)(lVar12 + 0x40),*(undefined1 *)(lVar12 + 0x44),
                          *(undefined1 *)(lVar12 + 0x45),*(undefined1 *)(lVar12 + 0x46),0x61ac,iVar9
                          ,"_LINKSTATEWRITEWHILEBUSY",pcVar14);
        pcVar14 = "";
        if ((local_50 & 0x10) != 0) {
          pcVar14 = " (First)";
        }
        nvswitch_os_report_error
                  (param_1[3],0x61ac,"Non-fatal, Link %02d %s%s\n",iVar9,"_LINKSTATEWRITEWHILEBUSY",
                   pcVar14);
        pcVar14 = "";
        if ((local_50 & 0x10) != 0) {
          pcVar14 = " (First)";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x61ac,"Non-fatal, Link %02d %s%s\n",iVar9,"_LINKSTATEWRITEWHILEBUSY",
                   pcVar14);
        nvswitch_inforom_bbx_add_sxid(param_1,0x61ac,0,0,0);
        nvswitch_record_error
                  (param_1,param_1 + 0x24,0x61ac,iVar9,0,1,0,0,&local_58,0x20,0xfcd,
                   "\"_LINKSTATEWRITEWHILEBUSY\"");
        nvswitch_lib_notify_client_events(param_1,1);
        local_68 = local_68 & 0xffffffef;
        if ((uVar7 & 0x10) == 0) {
          local_64 = CONCAT44(0x42,(undefined4)local_64);
          nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
        }
      }
      if ((uVar18 & 0x20) != 0) {
        iVar8 = nvswitch_translate_hw_error(0x61ad);
        if (iVar8 == 1) {
          nvswitch_assert_log();
        }
        lVar12 = *param_1;
        pcVar14 = "";
        if ((local_50 & 0x20) != 0) {
          pcVar14 = " (First)";
        }
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                          ,plVar1,*(undefined4 *)(lVar12 + 0x40),*(undefined1 *)(lVar12 + 0x44),
                          *(undefined1 *)(lVar12 + 0x45),*(undefined1 *)(lVar12 + 0x46),0x61ad,iVar9
                          ,"_LINK_STATE_REQUEST_TIMEOUT",pcVar14);
        pcVar14 = "";
        if ((local_50 & 0x20) != 0) {
          pcVar14 = " (First)";
        }
        nvswitch_os_report_error
                  (param_1[3],0x61ad,"Non-fatal, Link %02d %s%s\n",iVar9,
                   "_LINK_STATE_REQUEST_TIMEOUT",pcVar14);
        pcVar14 = "";
        if ((local_50 & 0x20) != 0) {
          pcVar14 = " (First)";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x61ad,"Non-fatal, Link %02d %s%s\n",iVar9,"_LINK_STATE_REQUEST_TIMEOUT",
                   pcVar14);
        nvswitch_inforom_bbx_add_sxid(param_1,0x61ad,0,0,0);
        nvswitch_record_error
                  (param_1,param_1 + 0x24,0x61ad,iVar9,0,1,0,0,&local_58,0x20,0xfda,
                   "\"_LINK_STATE_REQUEST_TIMEOUT\"");
        nvswitch_lib_notify_client_events(param_1,1);
        local_68 = local_68 & 0xffffffdf;
        if ((uVar7 & 0x20) == 0) {
          local_64 = CONCAT44(0x44,(undefined4)local_64);
          nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
        }
      }
      if ((uVar18 & 0x40) != 0) {
        iVar8 = nvswitch_translate_hw_error(0x61ae);
        if (iVar8 == 1) {
          nvswitch_assert_log();
        }
        lVar12 = *param_1;
        pcVar14 = "";
        if ((local_50 & 0x40) != 0) {
          pcVar14 = " (First)";
        }
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                          ,plVar1,*(undefined4 *)(lVar12 + 0x40),*(undefined1 *)(lVar12 + 0x44),
                          *(undefined1 *)(lVar12 + 0x45),*(undefined1 *)(lVar12 + 0x46),0x61ae,iVar9
                          ,"_WRITE_TO_LOCKED_SYSTEM_REG_ERR",pcVar14);
        pcVar14 = "";
        if ((local_50 & 0x40) != 0) {
          pcVar14 = " (First)";
        }
        nvswitch_os_report_error
                  (param_1[3],0x61ae,"Non-fatal, Link %02d %s%s\n",iVar9,
                   "_WRITE_TO_LOCKED_SYSTEM_REG_ERR",pcVar14);
        pcVar14 = "";
        if ((local_50 & 0x40) != 0) {
          pcVar14 = " (First)";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x61ae,"Non-fatal, Link %02d %s%s\n",iVar9,
                   "_WRITE_TO_LOCKED_SYSTEM_REG_ERR",pcVar14);
        nvswitch_inforom_bbx_add_sxid(param_1,0x61ae,0,0,0);
        nvswitch_record_error
                  (param_1,param_1 + 0x24,0x61ae,iVar9,0,1,0,0,&local_58,0x20,0xfe7,
                   "\"_WRITE_TO_LOCKED_SYSTEM_REG_ERR\"");
        nvswitch_lib_notify_client_events(param_1,1);
        local_68 = local_68 & 0xffffffbf;
        if ((uVar7 & 0x40) == 0) {
          local_64 = CONCAT44(0x43,(undefined4)local_64);
          nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
        }
      }
      if (local_68 != 0) {
        iVar8 = nvswitch_translate_hw_error(0x2713);
        if (iVar8 == 1) {
          nvswitch_assert_log();
        }
        lVar12 = *param_1;
        nvswitch_os_print(5,
                          "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                          ,plVar1,*(undefined4 *)(lVar12 + 0x40),*(undefined1 *)(lVar12 + 0x44),
                          *(undefined1 *)(lVar12 + 0x45),*(undefined1 *)(lVar12 + 0x46),0x2713,
                          "_nvswitch_service_nvlipt_lnk_nonfatal_lr10",0xff1);
        nvswitch_os_report_error
                  (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                   "_nvswitch_service_nvlipt_lnk_nonfatal_lr10",0xff1);
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                   "_nvswitch_service_nvlipt_lnk_nonfatal_lr10",0xff1);
        nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
        nvswitch_record_error
                  (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_68,4,0xff1,&DAT_00c81851);
      }
      if ((local_58._4_4_ & (uint)local_50) != 0) {
        pcVar2 = (code *)param_1[0x122];
        uVar10 = nvswitch_get_link_eng_inst(param_1,iVar9,9);
        iVar8 = (*pcVar2)(param_1,9,0,uVar10);
        if ((iVar8 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,iVar9), cVar4 == '\0')) {
          nvswitch_assert_log();
        }
        pcVar2 = (code *)param_1[0x125];
        uVar7 = (uint)local_50 & local_58._4_4_;
        uVar10 = nvswitch_get_link_eng_inst(param_1,iVar9,9);
        (*pcVar2)(param_1,9,0,uVar10,0x29c,uVar7);
      }
      pcVar2 = (code *)param_1[0x122];
      uVar10 = nvswitch_get_link_eng_inst(param_1,iVar9,9);
      iVar8 = (*pcVar2)(param_1,9,0,uVar10);
      if ((iVar8 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,iVar9), cVar4 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = (code *)param_1[0x125];
      uVar10 = nvswitch_get_link_eng_inst(param_1,iVar9,9);
      (*pcVar2)(param_1,9,0,uVar10,0x280,uVar18);
      if (local_68 != 0) break;
      uVar11 = uVar11 >> 1;
      if (uVar11 == 0) goto LAB_001d9c72;
      iVar9 = iVar9 + 1;
    }
    if ((bool)(bVar20 & iVar6 != 0 & bVar19)) goto LAB_001d7690;
  }
LAB_001d9c72:
  local_6c = local_6c & ~uVar15;
LAB_001d7690:
  local_7c = local_7c + 1;
  if (local_7c == 9) {
    if (local_6c == 0) {
      return 0;
    }
    iVar6 = nvswitch_translate_hw_error(0x2713);
    if (iVar6 == 1) {
      nvswitch_assert_log();
    }
    lVar12 = *param_1;
    nvswitch_os_print(5,
                      "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                      ,param_1 + 1,*(undefined4 *)(lVar12 + 0x40),*(undefined1 *)(lVar12 + 0x44),
                      *(undefined1 *)(lVar12 + 0x45),*(undefined1 *)(lVar12 + 0x46),0x2713,
                      "_nvswitch_service_saw_nonfatal_lr10",0x109d);
    nvswitch_os_report_error
              (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
               "_nvswitch_service_saw_nonfatal_lr10",0x109d);
    nvswitch_lib_smbpbi_log_sxid
              (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
               "_nvswitch_service_saw_nonfatal_lr10",0x109d);
    nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
    nvswitch_record_error(param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_6c,4,0x109d,&DAT_00c81851);
    return -(uint)(local_6c != 0) & 0xfffffff6;
  }
  iVar6 = (int)param_1[0x3f1];
  goto LAB_001d76a5;
}


// ===== 001d9f29 nvswitch_lib_enable_interrupts_lr10.cold =====

void nvswitch_lib_enable_interrupts_lr10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001d9f40 nvswitch_lib_enable_interrupts_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_lib_enable_interrupts_lr10(long param_1)

{
  code *pcVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x1f88) == 6) {
    uVar2 = -(uint)((*(uint *)(&DAT_00009a94 + *(long *)(param_1 + 0x1f90)) & 0x100000) != 0) &
            0x300000;
    if ((*(uint *)(&DAT_00009a94 + *(long *)(param_1 + 0x1f90)) & 0x200000) != 0) {
      uVar2 = uVar2 | 0xc00000;
    }
    nvswitch_reg_write_32(param_1,0x160);
    (**(code **)(param_1 + 0x928))(param_1,1,0,0,0x864,uVar2);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001d9fc0 nvswitch_lib_disable_interrupts_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_lib_disable_interrupts_lr10(long param_1)

{
  if ((*(int *)(param_1 + 0x1f88) == 6) && (*(long *)(param_1 + 0x1f90) != 0)) {
    nvswitch_reg_write_32(param_1,0x180,0xffffffff);
    if (*(char *)(param_1 + 0x25) != '\0') {
      (**(code **)(param_1 + 0x920))(param_1,1,0,0,0x880);
      return;
    }
    return;
  }
  return;
}


// ===== 001da022 _nvswitch_initialize_nport_interrupts.cold =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _nvswitch_initialize_nport_interrupts_cold(void)

{
  code *pcVar1;
  code *in_RAX;
  long unaff_RBX;
  
  (*in_RAX)();
  (**(code **)(unaff_RBX + 0x928))();
  (**(code **)(unaff_RBX + 0x928))();
  (**(code **)(unaff_RBX + 0x928))();
  (**(code **)(unaff_RBX + 0x928))();
  _DAT_00009aa8 = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001da400 _nvswitch_initialize_nport_interrupts =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _nvswitch_initialize_nport_interrupts(long param_1)

{
  long lVar1;
  code *pcVar2;
  
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x470,7);
  if (*(int *)(param_1 + 0x1f88) != 6) {
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x5404,0x3d7);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x5408,0x351);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x540c,0x86);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x5410,0);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x5414,0x351);
    _DAT_00009aa8 = 0;
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar1 = *(long *)(param_1 + 0x1f90);
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x5404,0x3d7);
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x5408,0x351);
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x540c,0x86);
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x5410,0);
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x5414,0x351);
  *(undefined8 *)(&DAT_00009aa8 + lVar1) = 0x8600000351;
  if (*(int *)(param_1 + 0x1f88) != 6) {
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x1404,0x23ffd);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x1408,0x3c61);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x140c,0x2039c);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x1410,0);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x1414,0x3c61);
    _DAT_00009ab4 = 0;
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar1 = *(long *)(param_1 + 0x1f90);
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x1404,0x23ffd);
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x1408,0x3c61);
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x140c,0x2039c);
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x1410,0);
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x1414,0x3c61);
  *(undefined8 *)(&DAT_00009ab4 + lVar1) = 0x2039c00003c61;
  if (*(int *)(param_1 + 0x1f88) != 6) {
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x4404,0x1ffff);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x4408,0x1e3d7);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x440c,0x1c28);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x4410,0);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x4414,0x1f7d7);
    _DAT_00009ac0 = 0;
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar1 = *(long *)(param_1 + 0x1f90);
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x4404,0x1ffff);
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x4408,0x1e3d7);
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x440c,0x1c28);
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x4410,0);
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x4414,0x1f7d7);
  *(undefined8 *)(&DAT_00009ac0 + lVar1) = 0x1c280001e3d7;
  if (*(int *)(param_1 + 0x1f88) == 6) {
    lVar1 = *(long *)(param_1 + 0x1f90);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x3404,0x63f);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x3408,0x62d);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x340c,0x12);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x3410,0);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x3414,0x62d);
    *(undefined8 *)(&DAT_00009acc + lVar1) = 0x120000062d;
    if (*(int *)(param_1 + 0x1f88) == 6) {
      lVar1 = *(long *)(param_1 + 0x1f90);
      (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x6404,0x10008181);
      (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x6408,0x10008100);
      (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x640c,0x81);
      (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x6410,0);
      (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x6414,0x10008100);
      *(undefined8 *)(&DAT_00009ad8 + lVar1) = 0x8110008100;
      return;
    }
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x6404,0x10008181);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x6408,0x10008100);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x640c,0x81);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x6410,0);
    (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x6414,0x10008100);
    _DAT_00009ad8 = 0;
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x3404,0x63f);
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x3408,0x62d);
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x340c,0x12);
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x3410,0);
  (**(code **)(param_1 + 0x928))(param_1,5,1,0,0x3414,0x62d);
  _DAT_00009acc = 0;
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 001da8b5 nvswitch_initialize_interrupt_tree_lr10.cold =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nvswitch_initialize_interrupt_tree_lr10_cold(void)

{
  code *pcVar1;
  code *in_R10;
  
  (*in_R10)();
  _DAT_00009ae4 = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001da930 nvswitch_initialize_interrupt_tree_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nvswitch_initialize_interrupt_tree_lr10(long param_1)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  byte bVar4;
  uint uVar5;
  ulong uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  long lVar10;
  
  if (*(int *)(param_1 + 0x1f88) != 6) {
    _DAT_00009a94 = 0;
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  uVar5 = 0;
  lVar1 = *(long *)(param_1 + 0x1f90);
  *(undefined8 *)(&DAT_00009a94 + lVar1) = 0x50400000;
  *(undefined8 *)(&DAT_00009a9c + lVar1) = 0;
  iVar8 = *(int *)(param_1 + 0x1f88);
  do {
    if (iVar8 != 6) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    while (*(char *)(*(long *)(param_1 + 0x1f90) + 0x39f0 + (ulong)uVar5 * 0x20) == '\0') {
      uVar5 = uVar5 + 1;
      iVar8 = 6;
      if (uVar5 == 4) goto LAB_001da9b0;
    }
    bVar4 = (byte)uVar5;
    uVar5 = uVar5 + 1;
    *(uint *)(&DAT_00009a9c + lVar1) = *(uint *)(&DAT_00009a9c + lVar1) | 0x100000 << (bVar4 & 0x1f)
    ;
    iVar8 = *(int *)(param_1 + 0x1f88);
  } while (uVar5 != 4);
LAB_001da9b0:
  uVar5 = 0;
  do {
    if (iVar8 != 6) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    while (*(char *)(*(long *)(param_1 + 0x1f90) + 0x3a90 + (ulong)uVar5 * 0x20) == '\0') {
      uVar5 = uVar5 + 1;
      iVar8 = 6;
      if (uVar5 == 9) goto LAB_001da9f0;
    }
    uVar9 = 0x200 << ((byte)uVar5 & 0x1f);
    uVar5 = uVar5 + 1;
    *(uint *)(&DAT_00009a9c + lVar1) = *(uint *)(&DAT_00009a9c + lVar1) | uVar9;
    *(uint *)(&DAT_00009aa0 + lVar1) = *(uint *)(&DAT_00009aa0 + lVar1) | uVar9;
    iVar8 = *(int *)(param_1 + 0x1f88);
  } while (uVar5 != 9);
LAB_001da9f0:
  uVar6 = 0;
  while( true ) {
    if (iVar8 != 6) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    if (*(char *)(uVar6 * 0x20 + *(long *)(param_1 + 0x1f90) + 0x38b0) != '\0') {
      uVar5 = 1 << ((byte)uVar6 & 0x1f);
      *(uint *)(&DAT_00009a9c + lVar1) = *(uint *)(&DAT_00009a9c + lVar1) | uVar5;
      *(uint *)(&DAT_00009aa0 + lVar1) = *(uint *)(&DAT_00009aa0 + lVar1) | uVar5;
    }
    uVar5 = (int)uVar6 + 1;
    uVar6 = (ulong)uVar5;
    if (uVar5 == 9) break;
    iVar8 = *(int *)(param_1 + 0x1f88);
  }
  cVar3 = nvswitch_is_soe_supported();
  if (cVar3 != '\0') {
    *(uint *)(&DAT_00009a9c + lVar1) = *(uint *)(&DAT_00009a9c + lVar1) | 0x40000;
  }
  nvswitch_reg_write_32(param_1,0x1100,0xffffffff);
  nvswitch_reg_write_32(param_1,0x1984,0);
  nvswitch_reg_write_32(param_1,0x1140,0x400000e);
  if (*(int *)(param_1 + 0x1f88) != 6) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar1 = *(long *)(param_1 + 0x1f90);
  (**(code **)(param_1 + 0x928))(param_1,1,0,0,0x870,*(undefined4 *)(&DAT_00009a98 + lVar1));
  (**(code **)(param_1 + 0x928))(param_1,1,0,0,0x868,*(undefined4 *)(&DAT_00009a9c + lVar1));
  (**(code **)(param_1 + 0x928))(param_1,1,0,0,0x86c,*(undefined4 *)(&DAT_00009aa0 + lVar1));
  iVar8 = 0x300;
  _nvswitch_initialize_nport_interrupts(param_1);
  (**(code **)(param_1 + 0x928))(param_1,6,1,0,0x220,0x1f);
  (**(code **)(param_1 + 0x928))(param_1,6,1,0,0x228,0x1f);
  (**(code **)(param_1 + 0x928))(param_1,6,1,0,0x230,0x1f);
  do {
    (**(code **)(param_1 + 0x928))(param_1,6,1,0,iVar8,0x1f);
    (**(code **)(param_1 + 0x928))(param_1,6,1,0,iVar8 + 8,0x1f);
    iVar7 = iVar8 + 0x10;
    iVar8 = iVar8 + 0x40;
    (**(code **)(param_1 + 0x928))(param_1,6,1,0,iVar7,0x1f);
  } while (iVar8 != 0x400);
  uVar5 = 0;
  (**(code **)(param_1 + 0x928))(param_1,8,1,0,0x300,3);
  (**(code **)(param_1 + 0x928))(param_1,9,1,0,0x300,3);
  iVar8 = *(int *)(param_1 + 0x1f88);
  do {
    if (iVar8 != 6) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    uVar9 = uVar5;
    while (*(char *)(*(long *)(param_1 + 0x1f90) + 0x3bd0 + (ulong)uVar9 * 0x20) == '\0') {
      uVar9 = uVar9 + 1;
      iVar8 = 6;
      if (uVar9 == 9) goto LAB_001daca0;
    }
    (**(code **)(param_1 + 0x928))(param_1,7,0,uVar9,0x81c,0);
    iVar8 = 0;
    do {
      iVar8 = iVar8 + 1;
    } while (iVar8 != 4);
    uVar5 = uVar9 + 1;
    (**(code **)(param_1 + 0x928))(param_1,7,0,uVar9,0x818);
    iVar8 = *(int *)(param_1 + 0x1f88);
  } while (uVar5 != 9);
LAB_001daca0:
  if (iVar8 == 6) {
    lVar1 = *(long *)(param_1 + 0x1f90);
    lVar10 = 0;
    (**(code **)(param_1 + 0x928))(param_1,0xd,1,0,0x6c,0x1ff);
    *(undefined4 *)(&DAT_00009ae4 + lVar1) = 0x1ff;
    if (*(int *)(param_1 + 0x1f88) == 6) {
      lVar10 = *(long *)(param_1 + 0x1f90);
    }
    iVar8 = 0x23c;
    do {
      iVar7 = iVar8 + 0x200;
      (**(code **)(param_1 + 0x928))(param_1,0xc,1,0,iVar8,0xff);
      iVar8 = iVar7;
    } while (iVar7 != 0x143c);
    *(undefined4 *)(&DAT_00009af0 + lVar10) = 0xff;
    return;
  }
  (**(code **)(param_1 + 0x928))(param_1,0xd,1,0,0x6c,0x1ff);
  _DAT_00009ae4 = 0;
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 001dae42 nvswitch_minion_service_falcon_interrupts_lr10.cold =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void nvswitch_minion_service_falcon_interrupts_lr10_cold(void)

{
  code *pcVar1;
  undefined4 uVar2;
  long lVar3;
  long unaff_RBP;
  undefined4 *puVar4;
  code *in_R9;
  
  puVar4 = (undefined4 *)(unaff_RBP + -0x50);
  for (lVar3 = 8; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  uVar2 = (*in_R9)();
  *(undefined4 *)(unaff_RBP + -0x50) = uVar2;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001dae80 nvswitch_minion_service_falcon_interrupts_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8 nvswitch_minion_service_falcon_interrupts_lr10(long *param_1,int param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  char *pcVar7;
  uint *puVar8;
  uint uVar9;
  uint local_5c;
  uint local_58 [2];
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  ulong uVar10;
  
  pcVar1 = (code *)param_1[0x124];
  if ((int)param_1[0x3f1] != 6) {
    puVar8 = local_58;
    for (lVar6 = 8; lVar6 != 0; lVar6 = lVar6 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    local_58[0] = (*pcVar1)(param_1,7,0,param_2,8);
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  lVar6 = param_1[0x3f2];
  local_58[0] = 0;
  local_58[1] = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  uVar2 = (*pcVar1)(param_1,7,0,param_2,8);
  local_58[0] = uVar2;
  local_50 = CONCAT44(*(undefined4 *)(&DAT_00009aa4 + lVar6),(undefined4)local_50);
  uVar3 = (*(code *)param_1[0x124])(param_1,7,0,param_2,0x18);
  local_58[1] = uVar3;
  uVar3 = uVar3 & local_58[0];
  if (uVar3 == 0) {
    uVar5 = 0xfffffffd;
  }
  else {
    uVar9 = param_2 * 4;
    uVar10 = (ulong)uVar9;
    local_5c = uVar3;
    if ((uVar3 & 2) != 0) {
      iVar4 = nvswitch_translate_hw_error(0x55fa);
      if (iVar4 == 1) {
        nvswitch_assert_log();
      }
      lVar6 = *param_1;
      pcVar7 = " (First)";
      if ((local_50 & 2) == 0) {
        pcVar7 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44),
                        *(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x55fa,uVar10,
                        "MINION Watchdog timer ran out",pcVar7);
      pcVar7 = " (First)";
      if ((local_50 & 2) == 0) {
        pcVar7 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x55fa,"Fatal, Link %02d %s%s\n",uVar10,"MINION Watchdog timer ran out",
                 pcVar7);
      pcVar7 = " (First)";
      if ((local_50 & 2) == 0) {
        pcVar7 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x55fa,"Fatal, Link %02d %s%s\n",uVar10,"MINION Watchdog timer ran out",
                 pcVar7);
      nvswitch_inforom_bbx_add_sxid(param_1,0x55fa,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x55fa,uVar10,0,1,1,0,local_58,0x20,0x351,
                 "\"MINION Watchdog timer ran out\"");
      nvswitch_set_fatal_error(param_1,1,uVar10);
      nvswitch_lib_notify_client_events(param_1,0);
      local_5c = local_5c & 0xfffffffd;
    }
    if ((uVar3 & 0x10) != 0) {
      iVar4 = nvswitch_translate_hw_error(0x55f3);
      if (iVar4 == 1) {
        nvswitch_assert_log();
      }
      lVar6 = *param_1;
      pcVar7 = " (First)";
      if ((local_50 & 0x10) == 0) {
        pcVar7 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44),
                        *(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x55f3,uVar10,
                        "MINION HALT",pcVar7);
      pcVar7 = " (First)";
      if ((local_50 & 0x10) == 0) {
        pcVar7 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x55f3,"Fatal, Link %02d %s%s\n",uVar10,"MINION HALT",pcVar7);
      pcVar7 = " (First)";
      if ((local_50 & 0x10) == 0) {
        pcVar7 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x55f3,"Fatal, Link %02d %s%s\n",uVar10,"MINION HALT",pcVar7);
      nvswitch_inforom_bbx_add_sxid(param_1,0x55f3,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x55f3,uVar10,0,1,1,0,local_58,0x20,0x358,"\"MINION HALT\"")
      ;
      nvswitch_set_fatal_error(param_1,1,uVar10);
      nvswitch_lib_notify_client_events(param_1,0);
      local_5c = local_5c & 0xffffffef;
    }
    if ((uVar3 & 0x20) != 0) {
      iVar4 = nvswitch_translate_hw_error(0x55fb);
      if (iVar4 == 1) {
        nvswitch_assert_log();
      }
      lVar6 = *param_1;
      pcVar7 = " (First)";
      if ((local_50 & 0x20) == 0) {
        pcVar7 = "";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44),
                        *(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x55fb,uVar10,
                        "MINION EXTERR",pcVar7);
      pcVar7 = " (First)";
      if ((local_50 & 0x20) == 0) {
        pcVar7 = "";
      }
      nvswitch_os_report_error
                (param_1[3],0x55fb,"Fatal, Link %02d %s%s\n",uVar10,"MINION EXTERR",pcVar7);
      pcVar7 = " (First)";
      if ((local_50 & 0x20) == 0) {
        pcVar7 = "";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x55fb,"Fatal, Link %02d %s%s\n",uVar9,"MINION EXTERR",pcVar7);
      nvswitch_inforom_bbx_add_sxid(param_1,0x55fb,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x55fb,uVar10,0,1,1,0,local_58,0x20,0x35f,
                 "\"MINION EXTERR\"");
      nvswitch_set_fatal_error(param_1,1,uVar9);
      nvswitch_lib_notify_client_events(param_1,0);
      local_5c = local_5c & 0xffffffdf;
    }
    if ((uVar3 & 0x40) != 0) {
      local_5c = local_5c & 0xffffffbf;
    }
    if ((uVar3 & 0x80) != 0) {
      local_5c = local_5c & 0xffffff7f;
    }
    if (local_5c != 0) {
      iVar4 = nvswitch_translate_hw_error(0x2713);
      if (iVar4 == 1) {
        nvswitch_assert_log();
      }
      lVar6 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                        ,param_1 + 1,*(undefined4 *)(lVar6 + 0x40),*(undefined1 *)(lVar6 + 0x44),
                        *(undefined1 *)(lVar6 + 0x45),*(undefined1 *)(lVar6 + 0x46),0x2713,
                        "nvswitch_minion_service_falcon_interrupts_lr10",0x375);
      nvswitch_os_report_error
                (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "nvswitch_minion_service_falcon_interrupts_lr10",0x375);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "nvswitch_minion_service_falcon_interrupts_lr10",0x375);
      nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
      nvswitch_record_error(param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_5c,4,0x375,&DAT_00c81851)
      ;
    }
    if ((char)param_1[uVar10 * 8 + 0x1ed] != '\0') {
      uVar9 = (*(code *)param_1[0x124])(param_1,7,0,param_2,0x818);
      (*(code *)param_1[0x125])(param_1,7,0,param_2,0x818,uVar9 & 0xfffffffa);
    }
    (*(code *)param_1[0x125])(param_1,7,0,param_2,4,uVar3);
    if (local_5c == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = 0xfffffff6;
    }
  }
  return uVar5;
}


// ===== 001db530 nvswitch_lib_check_interrupts_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint nvswitch_lib_check_interrupts_lr10(long param_1)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  
  lVar2 = 0;
  if (*(int *)(param_1 + 0x1f88) == 6) {
    lVar2 = *(long *)(param_1 + 0x1f90);
  }
  if ((*(char *)(param_1 + 0x25) == '\0') && (*(char *)(param_1 + 0x26) == '\0')) {
    return 0xfffffff6;
  }
  uVar1 = nvswitch_reg_read_32(param_1,0x100);
  uVar3 = *(uint *)(&DAT_00009a94 + lVar2);
  if ((uVar3 & uVar1) != 0) {
    return 0xfffffff6;
  }
  if ((uVar3 & 0x100000) == 0) {
    if ((uVar3 & 0x200000) == 0) {
      (**(code **)(param_1 + 0x920))(param_1,1,0,0,0x840);
      goto LAB_001db5d2;
    }
    uVar3 = 0xc00000;
  }
  else {
    uVar3 = (-(uint)((uVar3 & 0x200000) == 0) & 0xff400000) + 0xf00000;
  }
  uVar1 = (**(code **)(param_1 + 0x920))(param_1,1,0,0,0x840);
  if ((uVar3 & uVar1) != 0) {
    return 0xfffffff6;
  }
LAB_001db5d2:
  uVar3 = (**(code **)(param_1 + 0x920))(param_1,1,0,0,0x844);
  if ((*(uint *)(&DAT_00009a9c + lVar2) & uVar3) != 0) {
    return 0xfffffff6;
  }
  uVar3 = (**(code **)(param_1 + 0x920))(param_1,1,0,0,0x848);
  return -(uint)((uVar3 & *(uint *)(&DAT_00009aa0 + lVar2)) != 0) & 0xfffffff6;
}


// ===== 001db6a0 nvswitch_service_minion_link_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */

uint nvswitch_service_minion_link_lr10(long *param_1,int param_2)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  char cVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  char *pcVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  undefined8 uVar15;
  uint local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  uVar5 = (*(code *)param_1[0x124])(param_1,7,0,param_2,0x810);
  local_58 = CONCAT44(local_58._4_4_,uVar5 >> 0x10);
  uVar5 = (*(code *)param_1[0x124])(param_1,7,0,param_2,0x818);
  uVar5 = uVar5 >> 0x10;
  local_50 = CONCAT44(uVar5,(uint)local_50);
  local_58 = CONCAT44(uVar5,(uint)local_58);
  uVar13 = uVar5 & (uint)local_58;
  if (uVar13 == 0) {
    return 0xfffffffd;
  }
  iVar14 = 0;
  local_5c = uVar13;
  do {
    for (; (uVar13 & 1) == 0; uVar13 = uVar13 >> 1) {
      iVar14 = iVar14 + 1;
    }
    pcVar2 = (code *)param_1[0x122];
    uVar1 = param_2 * 4 + iVar14;
    uVar6 = nvswitch_get_link_eng_inst(param_1,uVar1,7);
    iVar9 = (*pcVar2)(param_1,7,0,uVar6);
    if ((iVar9 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,uVar1), cVar4 == '\0')) {
      nvswitch_assert_log();
    }
    iVar9 = iVar14 * 4 + 0xa00;
    pcVar2 = (code *)param_1[0x124];
    uVar6 = nvswitch_get_link_eng_inst(param_1,uVar1,7);
    uVar7 = (*pcVar2)(param_1,7,0,uVar6,iVar14 * 4 + 0xa00);
    if ((int)uVar7 < 0) {
      uVar10 = uVar7 & 0xff;
      local_48 = CONCAT44(local_48._4_4_,uVar7);
      uVar12 = 1 << ((byte)iVar14 & 0x1f);
      if (uVar10 == 0x10) {
        iVar8 = nvswitch_translate_hw_error(0x55fc);
        if (iVar8 == 1) {
          nvswitch_assert_log();
        }
        pcVar11 = " (First)";
        if (((uint)local_50 & uVar12) == 0) {
          pcVar11 = "";
        }
        lVar3 = *param_1;
        nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                          ,param_1 + 1,*(undefined4 *)(lVar3 + 0x40),*(undefined1 *)(lVar3 + 0x44),
                          *(undefined1 *)(lVar3 + 0x45),*(undefined1 *)(lVar3 + 0x46),0x55fc,uVar1,
                          "Minion Link NOINIT interrupt",pcVar11);
        pcVar11 = " (First)";
        if (((uint)local_50 & uVar12) == 0) {
          pcVar11 = "";
        }
        nvswitch_os_report_error
                  (param_1[3],0x55fc,"Fatal, Link %02d %s%s\n",uVar1,"Minion Link NOINIT interrupt",
                   pcVar11);
        pcVar11 = " (First)";
        if (((uint)local_50 & uVar12) == 0) {
          pcVar11 = "";
        }
        nvswitch_lib_smbpbi_log_sxid
                  (param_1,0x55fc,"Fatal, Link %02d %s%s\n",uVar1,"Minion Link NOINIT interrupt",
                   pcVar11);
        nvswitch_inforom_bbx_add_sxid(param_1,0x55fc,0,0,0);
        pcVar11 = "\"Minion Link NOINIT interrupt\"";
        uVar15 = 0xce3;
LAB_001dba60:
        nvswitch_record_error
                  (param_1,param_1 + 0x1f,0x55fc,uVar1,0,1,1,0,&local_58,0x20,uVar15,pcVar11);
        nvswitch_set_fatal_error(param_1,0,uVar1);
        nvswitch_lib_notify_client_events(param_1,0);
      }
      else {
        if (0x10 < uVar10) {
          if (uVar10 == 0x19) {
            iVar8 = nvswitch_translate_hw_error(0x55fc);
            if (iVar8 == 1) {
              nvswitch_assert_log();
            }
            pcVar11 = " (First)";
            if (((uint)local_50 & uVar12) == 0) {
              pcVar11 = "";
            }
            lVar3 = *param_1;
            nvswitch_os_print(5,
                              "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                              ,param_1 + 1,*(undefined4 *)(lVar3 + 0x40),
                              *(undefined1 *)(lVar3 + 0x44),*(undefined1 *)(lVar3 + 0x45),
                              *(undefined1 *)(lVar3 + 0x46),0x55fc,uVar1,
                              "Minion Link Negotiation Config Err Interrupt",pcVar11);
            pcVar11 = " (First)";
            if (((uint)local_50 & uVar12) == 0) {
              pcVar11 = "";
            }
            nvswitch_os_report_error
                      (param_1[3],0x55fc,"Fatal, Link %02d %s%s\n",uVar1,
                       "Minion Link Negotiation Config Err Interrupt",pcVar11);
            pcVar11 = " (First)";
            if (((uint)local_50 & uVar12) == 0) {
              pcVar11 = "";
            }
            nvswitch_lib_smbpbi_log_sxid
                      (param_1,0x55fc,"Fatal, Link %02d %s%s\n",uVar1,
                       "Minion Link Negotiation Config Err Interrupt",pcVar11);
            nvswitch_inforom_bbx_add_sxid(param_1,0x55fc,0,0,0);
            pcVar11 = "\"Minion Link Negotiation Config Err Interrupt\"";
            uVar15 = 0xcee;
          }
          else if (uVar10 < 0x1a) {
            if (uVar10 == 0x17) goto LAB_001dba9f;
            if (uVar10 == 0x18) {
              iVar8 = nvswitch_translate_hw_error(0x55fc);
              if (iVar8 == 1) {
                nvswitch_assert_log();
              }
              pcVar11 = " (First)";
              if (((uint)local_50 & uVar12) == 0) {
                pcVar11 = "";
              }
              lVar3 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar3 + 0x40),
                                *(undefined1 *)(lVar3 + 0x44),*(undefined1 *)(lVar3 + 0x45),
                                *(undefined1 *)(lVar3 + 0x46),0x55fc,uVar1,
                                "Minion Link Local-Config-Error interrupt",pcVar11);
              pcVar11 = " (First)";
              if (((uint)local_50 & uVar12) == 0) {
                pcVar11 = "";
              }
              nvswitch_os_report_error
                        (param_1[3],0x55fc,"Fatal, Link %02d %s%s\n",uVar1,
                         "Minion Link Local-Config-Error interrupt",pcVar11);
              pcVar11 = " (First)";
              if (((uint)local_50 & uVar12) == 0) {
                pcVar11 = "";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x55fc,"Fatal, Link %02d %s%s\n",uVar1,
                         "Minion Link Local-Config-Error interrupt",pcVar11);
              nvswitch_inforom_bbx_add_sxid(param_1,0x55fc,0,0,0);
              pcVar11 = "\"Minion Link Local-Config-Error interrupt\"";
              uVar15 = 0xceb;
            }
            else {
LAB_001dbf18:
              iVar8 = nvswitch_translate_hw_error(0x55fc);
              if (iVar8 == 1) {
                nvswitch_assert_log();
              }
              pcVar11 = " (First)";
              if (((uint)local_50 & uVar12) == 0) {
                pcVar11 = "";
              }
              lVar3 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar3 + 0x40),
                                *(undefined1 *)(lVar3 + 0x44),*(undefined1 *)(lVar3 + 0x45),
                                *(undefined1 *)(lVar3 + 0x46),0x55fc,uVar1,
                                "Minion Interrupt code unknown",pcVar11);
              pcVar11 = " (First)";
              if (((uint)local_50 & uVar12) == 0) {
                pcVar11 = "";
              }
              nvswitch_os_report_error
                        (param_1[3],0x55fc,"Fatal, Link %02d %s%s\n",uVar1,
                         "Minion Interrupt code unknown",pcVar11);
              pcVar11 = " (First)";
              if (((uint)local_50 & uVar12) == 0) {
                pcVar11 = "";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x55fc,"Fatal, Link %02d %s%s\n",uVar1,
                         "Minion Interrupt code unknown",pcVar11);
              nvswitch_inforom_bbx_add_sxid(param_1,0x55fc,0,0,0);
              pcVar11 = "\"Minion Interrupt code unknown\"";
              uVar15 = 0xcf7;
            }
          }
          else if (uVar10 == 0x20) {
            iVar8 = nvswitch_translate_hw_error(0x55fc);
            if (iVar8 == 1) {
              nvswitch_assert_log();
            }
            pcVar11 = " (First)";
            if (((uint)local_50 & uVar12) == 0) {
              pcVar11 = "";
            }
            lVar3 = *param_1;
            nvswitch_os_print(5,
                              "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                              ,param_1 + 1,*(undefined4 *)(lVar3 + 0x40),
                              *(undefined1 *)(lVar3 + 0x44),*(undefined1 *)(lVar3 + 0x45),
                              *(undefined1 *)(lVar3 + 0x46),0x55fc,uVar1,
                              "Minion Link BADINIT interrupt",pcVar11);
            pcVar11 = " (First)";
            if (((uint)local_50 & uVar12) == 0) {
              pcVar11 = "";
            }
            nvswitch_os_report_error
                      (param_1[3],0x55fc,"Fatal, Link %02d %s%s\n",uVar1,
                       "Minion Link BADINIT interrupt",pcVar11);
            pcVar11 = " (First)";
            if (((uint)local_50 & uVar12) == 0) {
              pcVar11 = "";
            }
            nvswitch_lib_smbpbi_log_sxid
                      (param_1,0x55fc,"Fatal, Link %02d %s%s\n",uVar1,
                       "Minion Link BADINIT interrupt",pcVar11);
            nvswitch_inforom_bbx_add_sxid(param_1,0x55fc,0,0,0);
            pcVar11 = "\"Minion Link BADINIT interrupt\"";
            uVar15 = 0xcf1;
          }
          else {
            if (uVar10 != 0x21) goto LAB_001dbf18;
            iVar8 = nvswitch_translate_hw_error(0x55fc);
            if (iVar8 == 1) {
              nvswitch_assert_log();
            }
            pcVar11 = " (First)";
            if (((uint)local_50 & uVar12) == 0) {
              pcVar11 = "";
            }
            lVar3 = *param_1;
            nvswitch_os_print(5,
                              "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                              ,param_1 + 1,*(undefined4 *)(lVar3 + 0x40),
                              *(undefined1 *)(lVar3 + 0x44),*(undefined1 *)(lVar3 + 0x45),
                              *(undefined1 *)(lVar3 + 0x46),0x55fc,uVar1,
                              "Minion Link PMFAIL interrupt",pcVar11);
            pcVar11 = " (First)";
            if (((uint)local_50 & uVar12) == 0) {
              pcVar11 = "";
            }
            nvswitch_os_report_error
                      (param_1[3],0x55fc,"Fatal, Link %02d %s%s\n",uVar1,
                       "Minion Link PMFAIL interrupt",pcVar11);
            pcVar11 = " (First)";
            if (((uint)local_50 & uVar12) == 0) {
              pcVar11 = "";
            }
            nvswitch_lib_smbpbi_log_sxid
                      (param_1,0x55fc,"Fatal, Link %02d %s%s\n",uVar1,"Minion Link PMFAIL interrupt"
                       ,pcVar11);
            nvswitch_inforom_bbx_add_sxid(param_1,0x55fc,0,0,0);
            pcVar11 = "\"Minion Link PMFAIL interrupt\"";
            uVar15 = 0xcf4;
          }
          goto LAB_001dba60;
        }
        if (uVar10 == 3) {
          iVar8 = nvswitch_translate_hw_error(0x55fd);
          if (iVar8 == 1) {
            nvswitch_assert_log();
          }
          pcVar11 = " (First)";
          if (((uint)local_50 & uVar12) == 0) {
            pcVar11 = "";
          }
          lVar3 = *param_1;
          nvswitch_os_print(5,
                            "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                            ,param_1 + 1,*(undefined4 *)(lVar3 + 0x40),*(undefined1 *)(lVar3 + 0x44)
                            ,*(undefined1 *)(lVar3 + 0x45),*(undefined1 *)(lVar3 + 0x46),0x55fd,
                            uVar1,"Minion Link PMDISABLED interrupt",pcVar11);
          pcVar11 = " (First)";
          if (((uint)local_50 & uVar12) == 0) {
            pcVar11 = "";
          }
          nvswitch_os_report_error
                    (param_1[3],0x55fd,"Non-fatal, Link %02d %s%s\n",uVar1,
                     "Minion Link PMDISABLED interrupt",pcVar11);
          pcVar11 = " (First)";
          if (((uint)local_50 & uVar12) == 0) {
            pcVar11 = "";
          }
          nvswitch_lib_smbpbi_log_sxid
                    (param_1,0x55fd,"Non-fatal, Link %02d %s%s\n",uVar1,
                     "Minion Link PMDISABLED interrupt",pcVar11);
          nvswitch_inforom_bbx_add_sxid(param_1,0x55fd,0,0,0);
          pcVar11 = "\"Minion Link PMDISABLED interrupt\"";
          uVar15 = 0xcda;
LAB_001dbdd6:
          nvswitch_record_error
                    (param_1,param_1 + 0x24,0x55fd,uVar1,0,1,0,0,&local_58,0x20,uVar15,pcVar11);
          nvswitch_lib_notify_client_events(param_1,1);
        }
        else {
          if ((uVar7 & 0xfc) != 0) {
            if (uVar10 == 4) {
              iVar8 = nvswitch_translate_hw_error(0x55fc);
              if (iVar8 == 1) {
                nvswitch_assert_log();
              }
              pcVar11 = " (First)";
              if (((uint)local_50 & uVar12) == 0) {
                pcVar11 = "";
              }
              lVar3 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar3 + 0x40),
                                *(undefined1 *)(lVar3 + 0x44),*(undefined1 *)(lVar3 + 0x45),
                                *(undefined1 *)(lVar3 + 0x46),0x55fc,uVar1,
                                "Minion Link DLCMDFAULT interrupt",pcVar11);
              pcVar11 = " (First)";
              if (((uint)local_50 & uVar12) == 0) {
                pcVar11 = "";
              }
              nvswitch_os_report_error
                        (param_1[3],0x55fc,"Fatal, Link %02d %s%s\n",uVar1,
                         "Minion Link DLCMDFAULT interrupt",pcVar11);
              pcVar11 = " (First)";
              if (((uint)local_50 & uVar12) == 0) {
                pcVar11 = "";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x55fc,"Fatal, Link %02d %s%s\n",uVar1,
                         "Minion Link DLCMDFAULT interrupt",pcVar11);
              nvswitch_inforom_bbx_add_sxid(param_1,0x55fc,0,0,0);
              pcVar11 = "\"Minion Link DLCMDFAULT interrupt\"";
              uVar15 = 0xcdd;
              goto LAB_001dba60;
            }
            if (uVar10 != 5) goto LAB_001dbf18;
            iVar8 = nvswitch_translate_hw_error(0x55fd);
            if (iVar8 == 1) {
              nvswitch_assert_log();
            }
            pcVar11 = " (First)";
            if (((uint)local_50 & uVar12) == 0) {
              pcVar11 = "";
            }
            lVar3 = *param_1;
            nvswitch_os_print(5,
                              "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                              ,param_1 + 1,*(undefined4 *)(lVar3 + 0x40),
                              *(undefined1 *)(lVar3 + 0x44),*(undefined1 *)(lVar3 + 0x45),
                              *(undefined1 *)(lVar3 + 0x46),0x55fd,uVar1,
                              "Minion Link TLREQ interrupt",pcVar11);
            pcVar11 = " (First)";
            if (((uint)local_50 & uVar12) == 0) {
              pcVar11 = "";
            }
            nvswitch_os_report_error
                      (param_1[3],0x55fd,"Non-fatal, Link %02d %s%s\n",uVar1,
                       "Minion Link TLREQ interrupt",pcVar11);
            pcVar11 = " (First)";
            if (((uint)local_50 & uVar12) == 0) {
              pcVar11 = "";
            }
            nvswitch_lib_smbpbi_log_sxid
                      (param_1,0x55fd,"Non-fatal, Link %02d %s%s\n",uVar1,
                       "Minion Link TLREQ interrupt",pcVar11);
            nvswitch_inforom_bbx_add_sxid(param_1,0x55fd,0,0,0);
            pcVar11 = "\"Minion Link TLREQ interrupt\"";
            uVar15 = 0xce0;
            goto LAB_001dbdd6;
          }
          if (uVar10 != 1) {
            if (uVar10 != 2) {
              iVar8 = nvswitch_translate_hw_error(0x55fc);
              if (iVar8 == 1) {
                nvswitch_assert_log();
              }
              pcVar11 = " (First)";
              if (((uint)local_50 & uVar12) == 0) {
                pcVar11 = "";
              }
              lVar3 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar3 + 0x40),
                                *(undefined1 *)(lVar3 + 0x44),*(undefined1 *)(lVar3 + 0x45),
                                *(undefined1 *)(lVar3 + 0x46),0x55fc,uVar1,
                                "Minion Link NA interrupt",pcVar11);
              pcVar11 = " (First)";
              if (((uint)local_50 & uVar12) == 0) {
                pcVar11 = "";
              }
              nvswitch_os_report_error
                        (param_1[3],0x55fc,"Fatal, Link %02d %s%s\n",uVar1,
                         "Minion Link NA interrupt",pcVar11);
              pcVar11 = " (First)";
              if (((uint)local_50 & uVar12) == 0) {
                pcVar11 = "";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x55fc,"Fatal, Link %02d %s%s\n",uVar1,"Minion Link NA interrupt",
                         pcVar11);
              nvswitch_inforom_bbx_add_sxid(param_1,0x55fc,0,0,0);
              pcVar11 = "\"Minion Link NA interrupt\"";
              uVar15 = 0xccf;
              goto LAB_001dba60;
            }
            iVar8 = nvswitch_translate_hw_error(0x55fd);
            if (iVar8 == 1) {
              nvswitch_assert_log();
            }
            pcVar11 = " (First)";
            if (((uint)local_50 & uVar12) == 0) {
              pcVar11 = "";
            }
            lVar3 = *param_1;
            nvswitch_os_print(5,
                              "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                              ,param_1 + 1,*(undefined4 *)(lVar3 + 0x40),
                              *(undefined1 *)(lVar3 + 0x44),*(undefined1 *)(lVar3 + 0x45),
                              *(undefined1 *)(lVar3 + 0x46),0x55fd,uVar1,
                              "Minion Link DLREQ interrupt",pcVar11);
            pcVar11 = " (First)";
            if (((uint)local_50 & uVar12) == 0) {
              pcVar11 = "";
            }
            nvswitch_os_report_error
                      (param_1[3],0x55fd,"Non-fatal, Link %02d %s%s\n",uVar1,
                       "Minion Link DLREQ interrupt",pcVar11);
            pcVar11 = " (First)";
            if (((uint)local_50 & uVar12) == 0) {
              pcVar11 = "";
            }
            nvswitch_lib_smbpbi_log_sxid
                      (param_1,0x55fd,"Non-fatal, Link %02d %s%s\n",uVar1,
                       "Minion Link DLREQ interrupt",pcVar11);
            nvswitch_inforom_bbx_add_sxid(param_1,0x55fd,0,0,0);
            pcVar11 = "\"Minion Link DLREQ interrupt\"";
            uVar15 = 0xcd7;
            goto LAB_001dbdd6;
          }
        }
      }
LAB_001dba9f:
      local_5c = local_5c & ~uVar12;
      if ((char)param_1[(ulong)uVar1 * 8 + 0x1ed] != '\0') {
        uVar5 = uVar5 & ~uVar12;
        pcVar2 = (code *)param_1[0x122];
        iVar9 = uVar5 << 0x10;
        uVar6 = nvswitch_get_link_eng_inst(param_1,uVar1,7);
        iVar8 = (*pcVar2)(param_1,7,0,uVar6);
        if ((iVar8 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,uVar1), cVar4 == '\0')) {
          nvswitch_assert_log();
        }
        pcVar2 = (code *)param_1[0x125];
        uVar6 = nvswitch_get_link_eng_inst(param_1,uVar1,7);
        (*pcVar2)(param_1,7,0,uVar6,0x818,iVar9);
      }
      (*(code *)param_1[0x125])(param_1,7,0,param_2,iVar14 * 4 + 0xa00,0x80000000,uVar5,iVar9);
    }
    uVar13 = uVar13 >> 1;
    if (uVar13 == 0) {
      if (local_5c == 0) {
        return 0;
      }
      iVar14 = nvswitch_translate_hw_error(0x2713);
      if (iVar14 == 1) {
        nvswitch_assert_log();
      }
      lVar3 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                        ,param_1 + 1,*(undefined4 *)(lVar3 + 0x40),*(undefined1 *)(lVar3 + 0x44),
                        *(undefined1 *)(lVar3 + 0x45),*(undefined1 *)(lVar3 + 0x46),0x2713,
                        "nvswitch_service_minion_link_lr10",0xd0c);
      nvswitch_os_report_error
                (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "nvswitch_service_minion_link_lr10",0xd0c);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "nvswitch_service_minion_link_lr10",0xd0c);
      nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
      nvswitch_record_error(param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_5c,4,0xd0c,&DAT_00c81851)
      ;
      return -(uint)(local_5c != 0) & 0xfffffff6;
    }
    iVar14 = iVar14 + 1;
  } while( true );
}


// ===== 001dc6d0 _nvswitch_service_minion_fatal_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint _nvswitch_service_minion_fatal_lr10(long *param_1,undefined4 param_2)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint local_2c [3];
  
  uVar4 = (*(code *)param_1[0x124])(param_1,7,0,param_2,0x810);
  uVar2 = (*(code *)param_1[0x124])(param_1,7,0,param_2,0x818);
  local_2c[0] = uVar2 & uVar4 & 0xffff;
  if (local_2c[0] == 0) {
    uVar4 = 0xfffffffd;
  }
  else {
    if ((uVar2 & uVar4 & 4) != 0) {
      iVar3 = nvswitch_minion_service_falcon_interrupts_lr10(param_1,param_2);
      if (iVar3 == 0) {
        local_2c[0] = local_2c[0] & 0xfffffffb;
      }
      if (local_2c[0] == 0) {
        return 0;
      }
    }
    iVar3 = nvswitch_translate_hw_error(0x2713);
    if (iVar3 == 1) {
      nvswitch_assert_log();
    }
    lVar1 = *param_1;
    nvswitch_os_print(5,
                      "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                      ,param_1 + 1,*(undefined4 *)(lVar1 + 0x40),*(undefined1 *)(lVar1 + 0x44),
                      *(undefined1 *)(lVar1 + 0x45),*(undefined1 *)(lVar1 + 0x46),0x2713,
                      "_nvswitch_service_minion_fatal_lr10",0x11db);
    nvswitch_os_report_error
              (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
               "_nvswitch_service_minion_fatal_lr10",0x11db);
    nvswitch_lib_smbpbi_log_sxid
              (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
               "_nvswitch_service_minion_fatal_lr10",0x11db);
    nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
    nvswitch_record_error(param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,local_2c,4,0x11db,&DAT_00c81851);
    uVar4 = -(uint)(local_2c[0] != 0) & 0xfffffff6;
  }
  return uVar4;
}


// ===== 001dc8a0 nvswitch_service_nvldl_fatal_link_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */
/* WARNING: Type propagation algorithm not settling */

undefined8 nvswitch_service_nvldl_fatal_link_lr10(long *param_1,undefined1 param_2,uint param_3)

{
  code *pcVar1;
  long lVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  char *pcVar8;
  uint uVar9;
  uint local_58;
  undefined1 local_54;
  byte local_53;
  undefined4 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  local_48 = 0;
  pcVar1 = (code *)param_1[0x122];
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,0xb);
  iVar6 = (*pcVar1)(param_1,0xb,0,uVar4);
  if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar1 = (code *)param_1[0x124];
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,0xb);
  uVar4 = (*pcVar1)(param_1,0xb,0,uVar4,0x50);
  local_48 = CONCAT44(local_48._4_4_,uVar4);
  pcVar1 = (code *)param_1[0x122];
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,0xb);
  iVar6 = (*pcVar1)(param_1,0xb,0,uVar4);
  if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar1 = (code *)param_1[0x124];
  uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,0xb);
  uVar5 = (*pcVar1)(param_1,0xb,0,uVar4,0x58);
  local_53 = (byte)param_3 & 3;
  local_40 = CONCAT44(uVar5,(undefined4)local_40);
  local_48 = CONCAT44(uVar5,(uint)local_48);
  uVar5 = uVar5 & (uint)local_48;
  if (uVar5 == 0) {
    uVar7 = 0xfffffffd;
  }
  else {
    local_58 = uVar5;
    local_54 = param_2;
    if ((uVar5 & 0x10) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4e24);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = "";
      if ((local_40 & 0x10) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4e24,param_3,
                        "TX Fault Ram",pcVar8);
      pcVar8 = "";
      if ((local_40 & 0x10) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4e24,"Fatal, Link %02d %s%s\n",param_3,"TX Fault Ram",pcVar8);
      pcVar8 = "";
      if ((local_40 & 0x10) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4e24,"Fatal, Link %02d %s%s\n",param_3,"TX Fault Ram",pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4e24,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4e24,param_3,0,1,1,0,&local_48,0x20,0x1203,
                 "\"TX Fault Ram\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_58 = local_58 & 0xffffffef;
      local_50 = 8;
      nvswitch_inforom_nvlink_log_error_event(param_1,&local_54);
    }
    if ((uVar5 & 0x20) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4e25);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = "";
      if ((local_40 & 0x20) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4e25,param_3,
                        "TX Fault Interface",pcVar8);
      pcVar8 = "";
      if ((local_40 & 0x20) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4e25,"Fatal, Link %02d %s%s\n",param_3,"TX Fault Interface",pcVar8);
      pcVar8 = "";
      if ((local_40 & 0x20) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4e25,"Fatal, Link %02d %s%s\n",param_3,"TX Fault Interface",pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4e25,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4e25,param_3,0,1,1,0,&local_48,0x20,0x120c,
                 "\"TX Fault Interface\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_58 = local_58 & 0xffffffdf;
      local_50 = 9;
      nvswitch_inforom_nvlink_log_error_event(param_1,&local_54);
    }
    if ((uVar5 & 0x100) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4e26);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = "";
      if ((local_40 & 0x100) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4e26,param_3,
                        "TX Fault Sublink Change",pcVar8);
      pcVar8 = "";
      if ((local_40 & 0x100) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4e26,"Fatal, Link %02d %s%s\n",param_3,"TX Fault Sublink Change",
                 pcVar8);
      pcVar8 = "";
      if ((local_40 & 0x100) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4e26,"Fatal, Link %02d %s%s\n",param_3,"TX Fault Sublink Change",pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4e26,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4e26,param_3,0,1,1,0,&local_48,0x20,0x1215,
                 "\"TX Fault Sublink Change\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_58 = local_58 & 0xfffffeff;
      local_50 = 10;
      nvswitch_inforom_nvlink_log_error_event(param_1,&local_54);
    }
    if ((uVar5 & 0x10000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4e27);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = "";
      if ((local_40 & 0x10000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4e27,param_3,
                        "RX Fault Sublink Change",pcVar8);
      pcVar8 = "";
      if ((local_40 & 0x10000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4e27,"Fatal, Link %02d %s%s\n",param_3,"RX Fault Sublink Change",
                 pcVar8);
      pcVar8 = "";
      if ((local_40 & 0x10000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4e27,"Fatal, Link %02d %s%s\n",param_3,"RX Fault Sublink Change",pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4e27,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4e27,param_3,0,1,1,0,&local_48,0x20,0x121e,
                 "\"RX Fault Sublink Change\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_58 = local_58 & 0xfffeffff;
      local_50 = 1;
      nvswitch_inforom_nvlink_log_error_event(param_1,&local_54);
    }
    if ((uVar5 & 0x100000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4e28);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = "";
      if ((local_40 & 0x100000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4e28,param_3,
                        "RX Fault DL Protocol",pcVar8);
      pcVar8 = "";
      if ((local_40 & 0x100000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4e28,"Fatal, Link %02d %s%s\n",param_3,"RX Fault DL Protocol",pcVar8);
      pcVar8 = "";
      if ((local_40 & 0x100000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4e28,"Fatal, Link %02d %s%s\n",param_3,"RX Fault DL Protocol",pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4e28,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4e28,param_3,0,1,1,0,&local_48,0x20,0x1227,
                 "\"RX Fault DL Protocol\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_58 = local_58 & 0xffefffff;
      local_50 = 0;
      nvswitch_inforom_nvlink_log_error_event(param_1,&local_54);
    }
    if ((uVar5 & 0x8000000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4e43);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = "";
      if ((local_40 & 0x8000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4e43,param_3,
                        "LTSSM Fault Down",pcVar8);
      pcVar8 = "";
      if ((local_40 & 0x8000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4e43,"Fatal, Link %02d %s%s\n",param_3,"LTSSM Fault Down",pcVar8);
      pcVar8 = "";
      if ((local_40 & 0x8000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4e43,"Fatal, Link %02d %s%s\n",param_3,"LTSSM Fault Down",pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4e43,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4e43,param_3,0,1,1,0,&local_48,0x20,0x1230,
                 "\"LTSSM Fault Down\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_58 = local_58 & 0xf7ffffff;
      local_50 = 0xd;
      nvswitch_inforom_nvlink_log_error_event(param_1,&local_54);
    }
    if ((uVar5 & 0x10000000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4e42);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = "";
      if ((local_40 & 0x10000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4e42,param_3,
                        "LTSSM Fault Up",pcVar8);
      pcVar8 = "";
      if ((local_40 & 0x10000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4e42,"Fatal, Link %02d %s%s\n",param_3,"LTSSM Fault Up",pcVar8);
      pcVar8 = "";
      if ((local_40 & 0x10000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4e42,"Fatal, Link %02d %s%s\n",param_3,"LTSSM Fault Up",pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4e42,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4e42,param_3,0,1,1,0,&local_48,0x20,0x1239,
                 "\"LTSSM Fault Up\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_58 = local_58 & 0xefffffff;
      local_50 = 0xc;
      nvswitch_inforom_nvlink_log_error_event(param_1,&local_54);
    }
    if ((uVar5 & 0x20000000) != 0) {
      iVar6 = nvswitch_translate_hw_error(0x4e2e);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      pcVar8 = "";
      if ((local_40 & 0x20000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_print(5,"nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n",
                        param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x4e2e,param_3,
                        "LTSSM Protocol Error",pcVar8);
      pcVar8 = "";
      if ((local_40 & 0x20000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_os_report_error
                (param_1[3],0x4e2e,"Fatal, Link %02d %s%s\n",param_3,"LTSSM Protocol Error",pcVar8);
      pcVar8 = "";
      if ((local_40 & 0x20000000) != 0) {
        pcVar8 = " (First)";
      }
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x4e2e,"Fatal, Link %02d %s%s\n",param_3,"LTSSM Protocol Error",pcVar8);
      nvswitch_inforom_bbx_add_sxid(param_1,0x4e2e,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x4e2e,param_3,0,1,1,0,&local_48,0x20,0x1242,
                 "\"LTSSM Protocol Error\"");
      nvswitch_set_fatal_error(param_1,0,param_3);
      nvswitch_lib_notify_client_events(param_1,0);
      local_58 = local_58 & 0xdfffffff;
    }
    if (local_58 != 0) {
      iVar6 = nvswitch_translate_hw_error(0x2713);
      if (iVar6 == 1) {
        nvswitch_assert_log();
      }
      lVar2 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                        ,param_1 + 1,*(undefined4 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x44),
                        *(undefined1 *)(lVar2 + 0x45),*(undefined1 *)(lVar2 + 0x46),0x2713,
                        "nvswitch_service_nvldl_fatal_link_lr10",0x1248);
      nvswitch_os_report_error
                (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "nvswitch_service_nvldl_fatal_link_lr10",0x1248);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "nvswitch_service_nvldl_fatal_link_lr10",0x1248);
      nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_58,4,0x1248,&DAT_00c81851);
    }
    if ((char)param_1[(ulong)param_3 * 8 + 0x1ed] != '\0') {
      pcVar1 = (code *)param_1[0x122];
      uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,0xb);
      iVar6 = (*pcVar1)(param_1,0xb,0,uVar4);
      if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar1 = (code *)param_1[0x125];
      uVar9 = local_40._4_4_ ^ uVar5;
      uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,0xb);
      (*pcVar1)(param_1,0xb,0,uVar4,0x58,uVar9);
    }
    pcVar1 = (code *)param_1[0x122];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,0xb);
    iVar6 = (*pcVar1)(param_1,0xb,0,uVar4);
    if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(param_1,param_3), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar1 = (code *)param_1[0x125];
    uVar4 = nvswitch_get_link_eng_inst(param_1,param_3,0xb);
    (*pcVar1)(param_1,0xb,0,uVar4,0x50,uVar5);
    if (local_58 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = 0xfffffff6;
    }
  }
  return uVar7;
}


// ===== 001dd7d0 _nvswitch_service_nvldl_fatal_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 _nvswitch_service_nvldl_fatal_lr10(long param_1,int param_2)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  undefined4 local_70;
  undefined8 local_60;
  ulong local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_60 = 0;
  local_58 = 0;
  uVar4 = nvswitch_get_enabled_link_mask();
  uVar4 = 0xfL << ((char)param_2 * '\x04' & 0x3fU) & uVar4;
  if (uVar4 == 0) {
    local_70 = 0xfffffff6;
    uVar8 = 0;
LAB_001dd8f8:
    local_50 = local_50 & 0xffffffffffffff00;
    local_60 = CONCAT71(local_60._1_7_,1);
    local_58 = uVar8;
    nvswitch_smbpbi_set_link_error_info(param_1,&local_50,&local_60);
    return local_70;
  }
  uVar8 = 0;
  local_70 = 0xfffffff6;
  uVar7 = 0;
  do {
    uVar6 = (uint)uVar7;
    for (; (uVar4 & 1) != 0; uVar4 = uVar4 >> 1) {
      lVar5 = nvswitch_get_link(param_1,uVar7 & 0xff);
      uVar1 = local_70;
      if (lVar5 == 0) {
        nvswitch_assert_log();
      }
      else {
        iVar3 = nvswitch_get_link_eng_inst(param_1,uVar7,8);
        if (iVar3 != param_2) {
          nvswitch_assert_log();
          goto LAB_001dd8f8;
        }
        cVar2 = nvswitch_is_link_in_reset(param_1,lVar5);
        if (cVar2 == '\0') {
          iVar3 = (**(code **)(param_1 + 0xa78))(param_1,param_2,uVar7);
          if (iVar3 == 0) {
            uVar8 = uVar8 | 1L << (uVar7 & 0x3f);
          }
          uVar1 = 0;
          if (iVar3 != 0) {
            uVar1 = local_70;
          }
        }
      }
      local_70 = uVar1;
      if (uVar4 >> 1 == 0) goto LAB_001dd8f8;
      uVar6 = (int)uVar7 + 1;
      uVar7 = (ulong)uVar6;
    }
    uVar7 = (ulong)(uVar6 + 1);
    uVar4 = uVar4 >> 1;
  } while( true );
}


// ===== 001dd950 _nvswitch_service_nvltlc_fatal_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r12 replaced with injection: x86_indirect_thunk_r12 */
/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */
/* WARNING: Function: __x86_indirect_thunk_r15 replaced with injection: x86_indirect_thunk_r15 */
/* WARNING: Type propagation algorithm not settling */

undefined4 _nvswitch_service_nvltlc_fatal_lr10(long *param_1,int param_2)

{
  code *pcVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  long lVar7;
  ulong uVar8;
  char *pcVar9;
  uint uVar10;
  undefined4 local_80;
  ulong local_78;
  ulong local_70;
  uint local_68;
  undefined8 local_64;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_78 = nvswitch_get_enabled_link_mask();
  cVar2 = (char)param_2;
  local_78 = 0xfL << (cVar2 * '\x04' & 0x3fU) & local_78;
  if (local_78 == 0) {
    return 0xfffffff6;
  }
  local_70 = 0;
  local_80 = 0xfffffff6;
  do {
    if ((local_78 & 1) != 0) {
      lVar7 = nvswitch_get_link(param_1,local_70 & 0xff);
      if (lVar7 == 0) {
        nvswitch_assert_log();
      }
      else {
        uVar8 = local_70 & 0xffffffff;
        iVar4 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,8);
        if (iVar4 != param_2) {
          nvswitch_assert_log();
          return local_80;
        }
        cVar3 = nvswitch_is_link_in_reset(param_1,lVar7);
        if (cVar3 == '\0') {
          iVar4 = _nvswitch_service_nvltlc_tx_sys_fatal_lr10(param_1,param_2,local_70 & 0xffffffff);
          if (iVar4 == 0) {
            local_80 = 0;
          }
          iVar4 = _nvswitch_service_nvltlc_rx_sys_fatal_lr10(param_1,param_2,uVar8);
          if (iVar4 == 0) {
            local_80 = 0;
          }
          iVar4 = _nvswitch_service_nvltlc_tx_lnk_fatal_0_lr10
                            (param_1,param_2,local_70 & 0xffffffff);
          local_58 = 0;
          pcVar1 = (code *)param_1[0x122];
          if (iVar4 == 0) {
            local_80 = 0;
          }
          local_50 = 0;
          local_48 = 0;
          local_40 = 0;
          local_64 = 0;
          local_5c = 0;
          uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
          iVar4 = (*pcVar1)(param_1,10,0,uVar5);
          if ((iVar4 == -1) ||
             (cVar3 = nvswitch_is_link_valid(param_1,local_70 & 0xffffffff), cVar3 == '\0')) {
            nvswitch_assert_log();
          }
          pcVar1 = (code *)param_1[0x124];
          uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
          uVar5 = (*pcVar1)(param_1,10,0,uVar5,0x1a80);
          local_58 = CONCAT44(local_58._4_4_,uVar5);
          pcVar1 = (code *)param_1[0x122];
          uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
          iVar4 = (*pcVar1)(param_1,10,0,uVar5);
          if ((iVar4 == -1) ||
             (cVar3 = nvswitch_is_link_valid(param_1,local_70 & 0xffffffff), cVar3 == '\0')) {
            nvswitch_assert_log();
          }
          pcVar1 = (code *)param_1[0x124];
          uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
          uVar6 = (*pcVar1)(param_1,10,0,uVar5,0x1a88);
          local_50 = CONCAT44(uVar6,(uint)local_50);
          local_58 = CONCAT44(uVar6,(uint)local_58);
          uVar6 = uVar6 & (uint)local_58;
          local_64 = CONCAT62(local_64._2_6_,CONCAT11((char)local_70,cVar2)) & 0xffffffffffff03ff;
          if (uVar6 != 0) {
            pcVar1 = (code *)param_1[0x122];
            local_68 = uVar6;
            uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
            iVar4 = (*pcVar1)(param_1,10,0,uVar5);
            if ((iVar4 == -1) ||
               (cVar3 = nvswitch_is_link_valid(param_1,local_70 & 0xffffffff), cVar3 == '\0')) {
              nvswitch_assert_log();
            }
            pcVar1 = (code *)param_1[0x124];
            uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
            uVar5 = (*pcVar1)(param_1,10,0,uVar5,0x1a9c);
            local_50 = CONCAT44(local_50._4_4_,uVar5);
            pcVar1 = (code *)param_1[0x122];
            uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
            iVar4 = (*pcVar1)(param_1,10,0,uVar5);
            if ((iVar4 == -1) ||
               (cVar3 = nvswitch_is_link_valid(param_1,local_70 & 0xffffffff), cVar3 == '\0')) {
              nvswitch_assert_log();
            }
            pcVar1 = (code *)param_1[0x124];
            uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
            uVar10 = (*pcVar1)(param_1,10,0,uVar5,0x1a98);
            if ((uVar6 & 1) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a45);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 1) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a45,uVar8,"RX DL HDR Parity Error",
                                pcVar9);
              pcVar9 = "";
              if ((local_50 & 1) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a45,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX DL HDR Parity Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 1) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a45,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX DL HDR Parity Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a45,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a45,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x142b,"\"RX DL HDR Parity Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xfffffffe;
              if ((uVar10 & 1) == 0) {
                local_64 = CONCAT44(0xf,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar6 & 2) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a46);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 2) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a46,uVar8,"RX DL Data Parity Error"
                                ,pcVar9);
              pcVar9 = "";
              if ((local_50 & 2) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a46,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX DL Data Parity Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 2) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a46,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX DL Data Parity Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a46,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a46,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x1438,"\"RX DL Data Parity Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xfffffffd;
              if ((uVar10 & 2) == 0) {
                local_64 = CONCAT44(0x10,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar6 & 4) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a47);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 4) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a47,uVar8,"RX DL Ctrl Parity Error"
                                ,pcVar9);
              pcVar9 = "";
              if ((local_50 & 4) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a47,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX DL Ctrl Parity Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 4) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a47,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX DL Ctrl Parity Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a47,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a47,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x1445,"\"RX DL Ctrl Parity Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xfffffffb;
              if ((uVar10 & 4) == 0) {
                local_64 = CONCAT44(0x11,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar6 & 8) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a4a);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 8) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a4a,uVar8,"RX Invalid DAE Error",
                                pcVar9);
              pcVar9 = "";
              if ((local_50 & 8) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a4a,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX Invalid DAE Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 8) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a4a,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX Invalid DAE Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a4a,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a4a,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x1452,"\"RX Invalid DAE Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xfffffff7;
              if ((uVar10 & 8) == 0) {
                local_64 = CONCAT44(0x12,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar6 & 0x10) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a4b);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 0x10) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a4b,uVar8,"RX Invalid BE Error",
                                pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x10) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a4b,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX Invalid BE Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x10) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a4b,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX Invalid BE Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a4b,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a4b,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x145f,"\"RX Invalid BE Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xffffffef;
              if ((uVar10 & 0x10) == 0) {
                local_64 = CONCAT44(0x13,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar6 & 0x20) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a4c);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 0x20) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a4c,uVar8,
                                "RX Invalid Addr Align Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x20) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a4c,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX Invalid Addr Align Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x20) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a4c,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX Invalid Addr Align Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a4c,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a4c,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x146c,"\"RX Invalid Addr Align Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xffffffdf;
              if ((uVar10 & 0x20) == 0) {
                local_64 = CONCAT44(0x14,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar6 & 0x40) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a4d);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 0x40) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a4d,uVar8,"RX Packet Length Error",
                                pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x40) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a4d,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX Packet Length Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x40) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a4d,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX Packet Length Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a4d,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a4d,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x1479,"\"RX Packet Length Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xffffffbf;
              if ((uVar10 & 0x40) == 0) {
                local_64 = CONCAT44(0x15,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar6 & 0x80) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a4e);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 0x80) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a4e,uVar8,"RSV Cmd Encoding Error",
                                pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x80) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a4e,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RSV Cmd Encoding Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x80) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a4e,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RSV Cmd Encoding Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a4e,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a4e,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x1486,"\"RSV Cmd Encoding Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xffffff7f;
              if ((uVar10 & 0x80) == 0) {
                local_64 = CONCAT44(0x20,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar6 & 0x100) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a4f);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 0x100) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a4f,uVar8,
                                "RSV Data Length Encoding Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x100) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a4f,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RSV Data Length Encoding Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x100) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a4f,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RSV Data Length Encoding Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a4f,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a4f,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x1493,"\"RSV Data Length Encoding Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xfffffeff;
              if ((uVar10 & 0x100) == 0) {
                local_64 = CONCAT44(0x21,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar6 & 0x200) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a52);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 0x200) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a52,uVar8,"RSV Packet Status Error"
                                ,pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x200) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a52,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RSV Packet Status Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x200) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a52,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RSV Packet Status Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a52,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a52,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x14a0,"\"RSV Packet Status Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xfffffdff;
              if ((uVar10 & 0x200) == 0) {
                local_64 = CONCAT44(0x16,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar6 & 0x400) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a53);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 0x400) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a53,uVar8,"RSV Packet Status Error"
                                ,pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x400) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a53,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RSV Packet Status Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x400) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a53,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RSV Packet Status Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a53,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a53,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x14ad,"\"RSV Packet Status Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xfffffbff;
              if ((uVar10 & 0x400) == 0) {
                local_64 = CONCAT44(0x17,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar6 & 0x800) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a54);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 0x800) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a54,uVar8,
                                "RSV CacheAttr Probe Rsp Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x800) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a54,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RSV CacheAttr Probe Rsp Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x800) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a54,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RSV CacheAttr Probe Rsp Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a54,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a54,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x14ba,"\"RSV CacheAttr Probe Rsp Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xfffff7ff;
              if ((uVar10 & 0x800) == 0) {
                local_64 = CONCAT44(0x18,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar6 & 0x1000) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a56);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 0x1000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a56,uVar8,
                                "Data Length RMW Req Max Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x1000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a56,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "Data Length RMW Req Max Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x1000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a56,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "Data Length RMW Req Max Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a56,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a56,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x14c7,"\"Data Length RMW Req Max Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xffffefff;
              if ((uVar10 & 0x1000) == 0) {
                local_64 = CONCAT44(0x19,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar6 & 0x2000) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a57);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 0x2000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a57,uVar8,
                                "Data Len Lt ATR RSP Min Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x2000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a57,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "Data Len Lt ATR RSP Min Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x2000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a57,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "Data Len Lt ATR RSP Min Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a57,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a57,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x14d4,"\"Data Len Lt ATR RSP Min Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xffffdfff;
              if ((uVar10 & 0x2000) == 0) {
                local_64 = CONCAT44(0x1a,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar6 & 0x4000) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a58);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 0x4000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a58,uVar8,
                                "Invalid Cache Attr PO Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x4000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a58,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "Invalid Cache Attr PO Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x4000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a58,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "Invalid Cache Attr PO Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a58,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a58,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x14e1,"\"Invalid Cache Attr PO Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xffffbfff;
              if ((uVar10 & 0x4000) == 0) {
                local_64 = CONCAT44(0x22,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar6 & 0x8000) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a59);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 0x8000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a59,uVar8,"Invalid CR Error",pcVar9
                               );
              pcVar9 = "";
              if ((local_50 & 0x8000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a59,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "Invalid CR Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x8000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a59,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "Invalid CR Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a59,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a59,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x14ee,"\"Invalid CR Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xffff7fff;
              if ((uVar10 & 0x8000) == 0) {
                local_64 = CONCAT44(0x1b,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar6 & 0x10000) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a88);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 0x10000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a88,uVar8,"RX Rsp Status HW Error",
                                pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x10000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a88,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX Rsp Status HW Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x10000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a88,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX Rsp Status HW Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a88,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a88,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x14fb,"\"RX Rsp Status HW Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xfffeffff;
              if ((uVar10 & 0x10000) == 0) {
                local_64 = CONCAT44(0x23,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar6 & 0x20000) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a89);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 0x20000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a89,uVar8,"RX Rsp Status UR Error",
                                pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x20000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a89,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX Rsp Status UR Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x20000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a89,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX Rsp Status UR Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a89,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a89,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x1509,"\"RX Rsp Status UR Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xfffdffff;
              if ((uVar10 & 0x20000) == 0) {
                local_64 = CONCAT44(0x24,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar6 & 0x80000) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a8b);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 0x80000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a8b,uVar8,
                                "Invalid Collapsed Response Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x80000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a8b,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "Invalid Collapsed Response Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x80000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a8b,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "Invalid Collapsed Response Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a8b,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a8b,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x1517,"\"Invalid Collapsed Response Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xfff7ffff;
              if ((uVar10 & 0x80000) == 0) {
                local_64 = CONCAT44(0x1c,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if (local_68 != 0) {
              iVar4 = nvswitch_translate_hw_error(0x2713);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x2713,
                                "_nvswitch_service_nvltlc_rx_lnk_fatal_0_lr10",0x1521);
              nvswitch_os_report_error
                        (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                         "_nvswitch_service_nvltlc_rx_lnk_fatal_0_lr10",0x1521);
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                         "_nvswitch_service_nvltlc_rx_lnk_fatal_0_lr10",0x1521);
              nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_68,4,0x1521,&DAT_00c81851);
            }
            if ((char)param_1[local_70 * 8 + 0x1ed] == '\0') {
              uVar10 = local_58._4_4_ & (uint)local_50;
            }
            else {
              pcVar1 = (code *)param_1[0x122];
              uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
              iVar4 = (*pcVar1)(param_1,10,0,uVar5);
              if ((iVar4 == -1) ||
                 (cVar3 = nvswitch_is_link_valid(param_1,local_70 & 0xffffffff), cVar3 == '\0')) {
                nvswitch_assert_log();
              }
              uVar10 = local_50._4_4_;
              pcVar1 = (code *)param_1[0x125];
              uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
              (*pcVar1)(param_1,10,0,uVar5,0x1a88,uVar10 ^ uVar6);
              uVar10 = local_58._4_4_ & (uint)local_50;
            }
            if (uVar10 != 0) {
              pcVar1 = (code *)param_1[0x122];
              uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
              iVar4 = (*pcVar1)(param_1,10,0,uVar5);
              if ((iVar4 == -1) ||
                 (cVar3 = nvswitch_is_link_valid(param_1,local_70 & 0xffffffff), cVar3 == '\0')) {
                nvswitch_assert_log();
              }
              pcVar1 = (code *)param_1[0x125];
              uVar10 = (uint)local_50 & local_58._4_4_;
              uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
              (*pcVar1)(param_1,10,0,uVar5,0x1a9c,uVar10);
            }
            pcVar1 = (code *)param_1[0x122];
            uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
            iVar4 = (*pcVar1)(param_1,10,0,uVar5);
            if ((iVar4 == -1) ||
               (cVar3 = nvswitch_is_link_valid(param_1,local_70 & 0xffffffff), cVar3 == '\0')) {
              nvswitch_assert_log();
            }
            pcVar1 = (code *)param_1[0x125];
            uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
            (*pcVar1)(param_1,10,0,uVar5,0x1a80,uVar6);
            if (local_68 == 0) {
              local_80 = 0;
            }
          }
          local_58 = 0;
          local_50 = 0;
          pcVar1 = (code *)param_1[0x122];
          local_48 = 0;
          local_40 = 0;
          local_64 = 0;
          local_5c = 0;
          uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
          iVar4 = (*pcVar1)(param_1,10,0,uVar5);
          if ((iVar4 == -1) ||
             (cVar3 = nvswitch_is_link_valid(param_1,local_70 & 0xffffffff), cVar3 == '\0')) {
            nvswitch_assert_log();
          }
          pcVar1 = (code *)param_1[0x124];
          uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
          uVar5 = (*pcVar1)(param_1,10,0,uVar5,0x1aa0);
          local_58 = CONCAT44(local_58._4_4_,uVar5);
          pcVar1 = (code *)param_1[0x122];
          uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
          iVar4 = (*pcVar1)(param_1,10,0,uVar5);
          if ((iVar4 == -1) ||
             (cVar3 = nvswitch_is_link_valid(param_1,local_70 & 0xffffffff), cVar3 == '\0')) {
            nvswitch_assert_log();
          }
          pcVar1 = (code *)param_1[0x124];
          uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
          uVar6 = (*pcVar1)(param_1,10,0,uVar5,0x1aa8);
          local_50 = CONCAT44(uVar6,(uint)local_50);
          local_58 = CONCAT44(uVar6,(uint)local_58);
          uVar6 = uVar6 & (uint)local_58;
          local_64 = CONCAT62(local_64._2_6_,CONCAT11((char)local_70,cVar2)) & 0xffffffffffff03ff;
          if (uVar6 != 0) {
            pcVar1 = (code *)param_1[0x122];
            local_68 = uVar6;
            uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
            iVar4 = (*pcVar1)(param_1,10,0,uVar5);
            if ((iVar4 == -1) ||
               (cVar3 = nvswitch_is_link_valid(param_1,local_70 & 0xffffffff), cVar3 == '\0')) {
              nvswitch_assert_log();
            }
            pcVar1 = (code *)param_1[0x124];
            uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
            uVar5 = (*pcVar1)(param_1,10,0,uVar5,0x1abc);
            local_50 = CONCAT44(local_50._4_4_,uVar5);
            pcVar1 = (code *)param_1[0x122];
            uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
            iVar4 = (*pcVar1)(param_1,10,0,uVar5);
            if ((iVar4 == -1) ||
               (cVar3 = nvswitch_is_link_valid(param_1,local_70 & 0xffffffff), cVar3 == '\0')) {
              nvswitch_assert_log();
            }
            pcVar1 = (code *)param_1[0x124];
            uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
            uVar10 = (*pcVar1)(param_1,10,0,uVar5,0x1ab8);
            if ((uVar6 & 1) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a5c);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 1) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a5c,uVar8,"RX HDR OVF Error",pcVar9
                               );
              pcVar9 = "";
              if ((local_50 & 1) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a5c,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX HDR OVF Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 1) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a5c,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX HDR OVF Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a5c,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a5c,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x155d,"\"RX HDR OVF Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xfffffffe;
              if ((char)uVar10 == '\0') {
                local_64 = CONCAT44(0x1d,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar6 & 0x100) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a5d);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 0x100) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a5d,uVar8,"RX Data OVF Error",
                                pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x100) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a5d,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX Data OVF Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x100) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a5d,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX Data OVF Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a5d,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a5d,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x156a,"\"RX Data OVF Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xfffffeff;
              if ((uVar10 & 0xff00) == 0) {
                local_64 = CONCAT44(0x1e,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar6 & 0x10000) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a5e);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 0x10000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a5e,uVar8,"Stomp Det Error",pcVar9)
              ;
              pcVar9 = "";
              if ((local_50 & 0x10000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a5e,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "Stomp Det Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x10000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a5e,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "Stomp Det Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a5e,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a5e,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x1577,"\"Stomp Det Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xfffeffff;
              if ((uVar10 & 0x10000) == 0) {
                local_64 = CONCAT44(0x1f,(undefined4)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar6 & 0x20000) != 0) {
              iVar4 = nvswitch_translate_hw_error(0x4a5f);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              pcVar9 = "";
              if ((local_50 & 0x20000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x4a5f,uVar8,"RX Poison Error",pcVar9)
              ;
              pcVar9 = "";
              if ((local_50 & 0x20000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4a5f,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX Poison Error",pcVar9);
              pcVar9 = "";
              if ((local_50 & 0x20000) != 0) {
                pcVar9 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4a5f,"Fatal, Link %02d %s%s\n",local_70 & 0xffffffff,
                         "RX Poison Error",pcVar9);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4a5f,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4a5f,local_70 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x1584,"\"RX Poison Error\"");
              nvswitch_set_fatal_error(param_1,0,local_70 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xfffdffff;
            }
            if (local_68 != 0) {
              iVar4 = nvswitch_translate_hw_error(0x2713);
              if (iVar4 == 1) {
                nvswitch_assert_log();
              }
              lVar7 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                                ,param_1 + 1,*(undefined4 *)(lVar7 + 0x40),
                                *(undefined1 *)(lVar7 + 0x44),*(undefined1 *)(lVar7 + 0x45),
                                *(undefined1 *)(lVar7 + 0x46),0x2713,
                                "_nvswitch_service_nvltlc_rx_lnk_fatal_1_lr10",0x1588);
              nvswitch_os_report_error
                        (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                         "_nvswitch_service_nvltlc_rx_lnk_fatal_1_lr10",0x1588);
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                         "_nvswitch_service_nvltlc_rx_lnk_fatal_1_lr10",0x1588);
              nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_68,4,0x1588,&DAT_00c81851);
            }
            if ((char)param_1[local_70 * 8 + 0x1ed] != '\0') {
              pcVar1 = (code *)param_1[0x122];
              uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
              iVar4 = (*pcVar1)(param_1,10,0,uVar5);
              if ((iVar4 == -1) ||
                 (cVar3 = nvswitch_is_link_valid(param_1,local_70 & 0xffffffff), cVar3 == '\0')) {
                nvswitch_assert_log();
              }
              uVar10 = local_50._4_4_;
              pcVar1 = (code *)param_1[0x125];
              uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
              (*pcVar1)(param_1,10,0,uVar5,0x1aa8,uVar10 ^ uVar6);
            }
            if ((local_58._4_4_ & (uint)local_50) != 0) {
              pcVar1 = (code *)param_1[0x122];
              uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
              iVar4 = (*pcVar1)(param_1,10,0,uVar5);
              if ((iVar4 == -1) ||
                 (cVar3 = nvswitch_is_link_valid(param_1,local_70 & 0xffffffff), cVar3 == '\0')) {
                nvswitch_assert_log();
              }
              pcVar1 = (code *)param_1[0x125];
              uVar10 = (uint)local_50 & local_58._4_4_;
              uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
              (*pcVar1)(param_1,10,0,uVar5,0x1abc,uVar10);
            }
            pcVar1 = (code *)param_1[0x122];
            uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
            iVar4 = (*pcVar1)(param_1,10,0,uVar5);
            if ((iVar4 == -1) ||
               (cVar3 = nvswitch_is_link_valid(param_1,local_70 & 0xffffffff), cVar3 == '\0')) {
              nvswitch_assert_log();
            }
            pcVar1 = (code *)param_1[0x125];
            uVar5 = nvswitch_get_link_eng_inst(param_1,local_70 & 0xffffffff,10);
            (*pcVar1)(param_1,10,0,uVar5,0x1aa0,uVar6);
            if (local_68 == 0) {
              local_80 = 0;
            }
          }
        }
      }
      if (local_78 >> 1 == 0) {
        return local_80;
      }
    }
    local_78 = local_78 >> 1;
    local_70 = local_70 + 1;
  } while( true );
}


// ===== 001e0576 nvswitch_lib_service_interrupts_lr10.cold =====

void nvswitch_lib_service_interrupts_lr10_cold(undefined8 param_1)

{
  code *pcVar1;
  long unaff_RBP;
  undefined8 unaff_R12;
  undefined8 unaff_R13;
  undefined8 unaff_R14;
  
  *(undefined8 *)(unaff_RBP + -0x20) = unaff_R12;
  *(undefined8 *)(unaff_RBP + -0x18) = unaff_R13;
  *(undefined8 *)(unaff_RBP + -0x10) = unaff_R14;
  nvswitch_reg_read_32(param_1,0x100);
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001e0680 nvswitch_lib_service_interrupts_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_r12 replaced with injection: x86_indirect_thunk_r12 */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Type propagation algorithm not settling */

undefined8 nvswitch_lib_service_interrupts_lr10(long *param_1)

{
  long *plVar1;
  code *pcVar2;
  bool bVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  ulong uVar13;
  uint uVar14;
  long lVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  ulong uVar19;
  char *pcVar20;
  undefined8 *puVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  ulong uVar25;
  byte bVar26;
  uint local_88;
  uint local_84;
  byte local_80;
  uint local_70;
  uint local_6c;
  uint local_68;
  undefined8 local_64;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  bVar26 = 0;
  if ((int)param_1[0x3f1] != 6) {
    nvswitch_reg_read_32(param_1,0x100);
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar15 = param_1[0x3f2];
  uVar5 = nvswitch_reg_read_32(param_1,0x100);
  uVar5 = uVar5 & *(uint *)(&DAT_00009a94 + lVar15);
  if (uVar5 == 0) goto LAB_001e06ef;
  local_70 = uVar5;
  if ((uVar5 & 0x400000) != 0) {
    if ((int)param_1[0x3f1] != 6) {
      (*(code *)param_1[0x124])(param_1,1,0,0,0x844);
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    lVar15 = param_1[0x3f2];
    uVar14 = (*(code *)param_1[0x124])(param_1,1,0,0,0x844);
    uVar14 = uVar14 & *(uint *)(&DAT_00009a9c + lVar15);
    if (uVar14 != 0) {
      iVar11 = (int)param_1[0x3f1];
      uVar22 = 0;
      local_6c = uVar14;
      do {
        if (iVar11 != 6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        while ((*(char *)(param_1[0x3f2] + 0x3a90 + (ulong)uVar22 * 0x20) == '\0' ||
               (uVar24 = 0x200 << ((byte)uVar22 & 0x1f), (uVar14 & uVar24) == 0))) {
          uVar22 = uVar22 + 1;
          iVar11 = 6;
          if (uVar22 == 9) goto LAB_001e07f3;
        }
        iVar11 = _nvswitch_service_npg_fatal_lr10(param_1,uVar22);
        if (iVar11 == 0) {
          local_6c = local_6c & ~uVar24;
        }
        uVar22 = uVar22 + 1;
        iVar11 = (int)param_1[0x3f1];
      } while (uVar22 != 9);
LAB_001e07f3:
      uVar13 = 0;
      do {
        if (iVar11 != 6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        while ((iVar6 = (int)uVar13, *(char *)(param_1[0x3f2] + 0x39f0 + uVar13 * 0x20) == '\0' ||
               (uVar22 = 0x100000 << ((byte)uVar13 & 0x1f), (uVar14 & uVar22) == 0))) {
          uVar13 = (ulong)(iVar6 + 1U);
          iVar11 = 6;
          if (iVar6 + 1U == 4) goto LAB_001e0b0e;
        }
        uVar24 = (*(code *)param_1[0x124])(param_1,0xc,0,uVar13,0x90);
        if (uVar24 == 0) {
LAB_001e2e81:
          iVar11 = (int)param_1[0x3f1];
        }
        else {
          iVar11 = 0;
          local_68 = uVar24;
          do {
            uVar16 = 1 << ((byte)iVar11 & 0x1f);
            if ((uVar24 & uVar16) != 0) {
              if ((int)param_1[0x3f1] != 6) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)invalidInstructionException();
                (*pcVar2)();
              }
              if ((*(char *)((ulong)(uint)(iVar11 + iVar6 * 4) * 0x20 + param_1[0x3f2] + 0x75f0) !=
                   '\0') && (iVar17 = _nvswitch_service_nxbar_tile_lr10(param_1), iVar17 == 0)) {
                local_68 = local_68 & ~uVar16;
              }
            }
            iVar11 = iVar11 + 1;
          } while (iVar11 != 4);
          iVar11 = 0x23c;
          iVar17 = 0;
          do {
            while (uVar16 = 0x10000 << ((byte)iVar17 & 0x1f), (uVar24 & uVar16) == 0) {
LAB_001e0900:
              iVar17 = iVar17 + 1;
              iVar11 = iVar11 + 0x200;
              if (iVar17 == 9) goto LAB_001e0ada;
            }
            pcVar2 = (code *)param_1[0x124];
            iVar7 = iVar11 + -8;
            if ((int)param_1[0x3f1] != 6) {
              puVar21 = &local_58;
              for (lVar15 = 8; lVar15 != 0; lVar15 = lVar15 + -1) {
                *(undefined4 *)puVar21 = 0;
                puVar21 = (undefined8 *)((long)puVar21 + (ulong)bVar26 * -8 + 4);
              }
              uVar12 = (*pcVar2)(param_1,0xc,0,uVar13,iVar7);
              local_58 = CONCAT44(local_58._4_4_,uVar12);
              uVar12 = (*(code *)param_1[0x124])(param_1,0xc,0,uVar13,iVar11);
              local_50 = CONCAT44(uVar12,(uint)local_50);
                    /* WARNING: Does not return */
              pcVar2 = (code *)invalidInstructionException();
              (*pcVar2)();
            }
            lVar15 = param_1[0x3f2];
            local_58 = 0;
            local_50 = 0;
            local_48 = 0;
            local_40 = 0;
            uVar12 = (*pcVar2)(param_1,0xc,0,uVar13,iVar7);
            local_58 = CONCAT44(local_58._4_4_,uVar12);
            uVar12 = (*(code *)param_1[0x124])(param_1,0xc,0,uVar13,iVar11);
            local_50 = CONCAT44(uVar12,(uint)local_50);
            local_48 = CONCAT44(local_48._4_4_,iVar17);
            local_58 = CONCAT44(*(uint *)(&DAT_00009af0 + lVar15),(uint)local_58);
            uVar23 = *(uint *)(&DAT_00009af0 + lVar15) & (uint)local_58;
            if (uVar23 == 0) goto LAB_001e0900;
            local_64 = CONCAT44(local_64._4_4_,uVar23);
            uVar12 = (*(code *)param_1[0x124])(param_1,0xc,0,uVar13);
            local_50 = CONCAT44(local_50._4_4_,uVar12);
            if ((uVar23 & 1) != 0) {
              iVar10 = nvswitch_translate_hw_error(0x59e2);
              if (iVar10 == 1) {
                nvswitch_assert_log();
              }
              lVar15 = *param_1;
              pcVar20 = "";
              if ((local_50 & 1) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar15 + 0x40),
                                *(undefined1 *)(lVar15 + 0x44),*(undefined1 *)(lVar15 + 0x45),
                                *(undefined1 *)(lVar15 + 0x46),0x59e2,uVar13,
                                "ingress SRC-VC buffer overflow",pcVar20);
              pcVar20 = "";
              if ((local_50 & 1) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x59e2,"Fatal, Link %02d %s%s\n",uVar13,
                         "ingress SRC-VC buffer overflow",pcVar20);
              pcVar20 = "";
              if ((local_50 & 1) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x59e2,"Fatal, Link %02d %s%s\n",uVar13,
                         "ingress SRC-VC buffer overflow",pcVar20);
              nvswitch_inforom_bbx_add_sxid(param_1,0x59e2,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x59e2,uVar13,0,1,1,0,&local_58,0x20,0x1132,
                         "\"ingress SRC-VC buffer overflow\"");
              nvswitch_set_fatal_error(param_1,1,uVar13);
              nvswitch_lib_notify_client_events(param_1,0);
              local_64 = local_64 & 0xfffffffffffffffe;
            }
            if ((uVar23 & 2) != 0) {
              iVar10 = nvswitch_translate_hw_error(0x59e3);
              if (iVar10 == 1) {
                nvswitch_assert_log();
              }
              lVar15 = *param_1;
              pcVar20 = "";
              if ((local_50 & 2) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar15 + 0x40),
                                *(undefined1 *)(lVar15 + 0x44),*(undefined1 *)(lVar15 + 0x45),
                                *(undefined1 *)(lVar15 + 0x46),0x59e3,uVar13,
                                "ingress SRC-VC buffer underflow",pcVar20);
              pcVar20 = "";
              if ((local_50 & 2) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x59e3,"Fatal, Link %02d %s%s\n",uVar13,
                         "ingress SRC-VC buffer underflow",pcVar20);
              pcVar20 = "";
              if ((local_50 & 2) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x59e3,"Fatal, Link %02d %s%s\n",uVar13,
                         "ingress SRC-VC buffer underflow",pcVar20);
              nvswitch_inforom_bbx_add_sxid(param_1,0x59e3,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x59e3,uVar13,0,1,1,0,&local_58,0x20,0x1139,
                         "\"ingress SRC-VC buffer underflow\"");
              nvswitch_set_fatal_error(param_1,1,uVar13);
              nvswitch_lib_notify_client_events(param_1,0);
              local_64 = local_64 & 0xfffffffffffffffd;
            }
            if ((uVar23 & 4) != 0) {
              iVar10 = nvswitch_translate_hw_error(0x59e4);
              if (iVar10 == 1) {
                nvswitch_assert_log();
              }
              lVar15 = *param_1;
              pcVar20 = "";
              if ((local_50 & 4) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar15 + 0x40),
                                *(undefined1 *)(lVar15 + 0x44),*(undefined1 *)(lVar15 + 0x45),
                                *(undefined1 *)(lVar15 + 0x46),0x59e4,uVar13,
                                "egress DST-VC credit overflow",pcVar20);
              pcVar20 = "";
              if ((local_50 & 4) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x59e4,"Fatal, Link %02d %s%s\n",uVar13,
                         "egress DST-VC credit overflow",pcVar20);
              pcVar20 = "";
              if ((local_50 & 4) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x59e4,"Fatal, Link %02d %s%s\n",uVar13,
                         "egress DST-VC credit overflow",pcVar20);
              nvswitch_inforom_bbx_add_sxid(param_1,0x59e4,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x59e4,uVar13,0,1,1,0,&local_58,0x20,0x1140,
                         "\"egress DST-VC credit overflow\"");
              nvswitch_set_fatal_error(param_1,1,uVar13);
              nvswitch_lib_notify_client_events(param_1,0);
              local_64 = local_64 & 0xfffffffffffffffb;
            }
            if ((uVar23 & 8) != 0) {
              iVar10 = nvswitch_translate_hw_error(0x59e5);
              if (iVar10 == 1) {
                nvswitch_assert_log();
              }
              lVar15 = *param_1;
              pcVar20 = "";
              if ((local_50 & 8) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar15 + 0x40),
                                *(undefined1 *)(lVar15 + 0x44),*(undefined1 *)(lVar15 + 0x45),
                                *(undefined1 *)(lVar15 + 0x46),0x59e5,uVar13,
                                "egress DST-VC credit underflow",pcVar20);
              pcVar20 = "";
              if ((local_50 & 8) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x59e5,"Fatal, Link %02d %s%s\n",uVar13,
                         "egress DST-VC credit underflow",pcVar20);
              pcVar20 = "";
              if ((local_50 & 8) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x59e5,"Fatal, Link %02d %s%s\n",uVar13,
                         "egress DST-VC credit underflow",pcVar20);
              nvswitch_inforom_bbx_add_sxid(param_1,0x59e5,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x59e5,uVar13,0,1,1,0,&local_58,0x20,0x1147,
                         "\"egress DST-VC credit underflow\"");
              nvswitch_set_fatal_error(param_1,1,uVar13);
              nvswitch_lib_notify_client_events(param_1,0);
              local_64 = local_64 & 0xfffffffffffffff7;
            }
            if ((uVar23 & 0x10) != 0) {
              iVar10 = nvswitch_translate_hw_error(0x59e6);
              if (iVar10 == 1) {
                nvswitch_assert_log();
              }
              lVar15 = *param_1;
              pcVar20 = "";
              if ((local_50 & 0x10) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar15 + 0x40),
                                *(undefined1 *)(lVar15 + 0x44),*(undefined1 *)(lVar15 + 0x45),
                                *(undefined1 *)(lVar15 + 0x46),0x59e6,uVar13,
                                "ingress packet burst error",pcVar20);
              pcVar20 = "";
              if ((local_50 & 0x10) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x59e6,"Fatal, Link %02d %s%s\n",uVar13,
                         "ingress packet burst error",pcVar20);
              pcVar20 = "";
              if ((local_50 & 0x10) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x59e6,"Fatal, Link %02d %s%s\n",uVar13,
                         "ingress packet burst error",pcVar20);
              nvswitch_inforom_bbx_add_sxid(param_1,0x59e6,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x59e6,uVar13,0,1,1,0,&local_58,0x20,0x114e,
                         "\"ingress packet burst error\"");
              nvswitch_set_fatal_error(param_1,1,uVar13);
              nvswitch_lib_notify_client_events(param_1,0);
              local_64 = local_64 & 0xffffffffffffffef;
            }
            if ((uVar23 & 0x20) != 0) {
              iVar10 = nvswitch_translate_hw_error(0x59e7);
              if (iVar10 == 1) {
                nvswitch_assert_log();
              }
              lVar15 = *param_1;
              pcVar20 = "";
              if ((local_50 & 0x20) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar15 + 0x40),
                                *(undefined1 *)(lVar15 + 0x44),*(undefined1 *)(lVar15 + 0x45),
                                *(undefined1 *)(lVar15 + 0x46),0x59e7,uVar13,
                                "ingress packet sticky error",pcVar20);
              pcVar20 = "";
              if ((local_50 & 0x20) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x59e7,"Fatal, Link %02d %s%s\n",uVar13,
                         "ingress packet sticky error",pcVar20);
              pcVar20 = "";
              if ((local_50 & 0x20) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x59e7,"Fatal, Link %02d %s%s\n",uVar13,
                         "ingress packet sticky error",pcVar20);
              nvswitch_inforom_bbx_add_sxid(param_1,0x59e7,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x59e7,uVar13,0,1,1,0,&local_58,0x20,0x1155,
                         "\"ingress packet sticky error\"");
              nvswitch_set_fatal_error(param_1,1,uVar13);
              nvswitch_lib_notify_client_events(param_1,0);
              local_64 = local_64 & 0xffffffffffffffdf;
            }
            if ((uVar23 & 0x40) != 0) {
              iVar10 = nvswitch_translate_hw_error(0x59e8);
              if (iVar10 == 1) {
                nvswitch_assert_log();
              }
              lVar15 = *param_1;
              pcVar20 = "";
              if ((local_50 & 0x40) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar15 + 0x40),
                                *(undefined1 *)(lVar15 + 0x44),*(undefined1 *)(lVar15 + 0x45),
                                *(undefined1 *)(lVar15 + 0x46),0x59e8,uVar13,
                                "possible bubbles at ingress",pcVar20);
              pcVar20 = "";
              if ((local_50 & 0x40) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x59e8,"Fatal, Link %02d %s%s\n",uVar13,
                         "possible bubbles at ingress",pcVar20);
              pcVar20 = "";
              if ((local_50 & 0x40) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x59e8,"Fatal, Link %02d %s%s\n",uVar13,
                         "possible bubbles at ingress",pcVar20);
              nvswitch_inforom_bbx_add_sxid(param_1,0x59e8,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x59e8,uVar13,0,1,1,0,&local_58,0x20,0x115c,
                         "\"possible bubbles at ingress\"");
              nvswitch_set_fatal_error(param_1,1,uVar13);
              nvswitch_lib_notify_client_events(param_1,0);
              local_64 = local_64 & 0xffffffffffffffbf;
            }
            if ((uVar23 & 0x80) != 0) {
              iVar10 = nvswitch_translate_hw_error(0x59e9);
              if (iVar10 == 1) {
                nvswitch_assert_log();
              }
              lVar15 = *param_1;
              pcVar20 = "";
              if ((local_50 & 0x80) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar15 + 0x40),
                                *(undefined1 *)(lVar15 + 0x44),*(undefined1 *)(lVar15 + 0x45),
                                *(undefined1 *)(lVar15 + 0x46),0x59e9,uVar13,
                                "ingress credit parity error",pcVar20);
              pcVar20 = "";
              if ((local_50 & 0x80) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x59e9,"Fatal, Link %02d %s%s\n",uVar13,
                         "ingress credit parity error",pcVar20);
              pcVar20 = "";
              if ((local_50 & 0x80) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x59e9,"Fatal, Link %02d %s%s\n",uVar13,
                         "ingress credit parity error",pcVar20);
              nvswitch_inforom_bbx_add_sxid(param_1,0x59e9,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x59e9,uVar13,0,1,1,0,&local_58,0x20,0x1163,
                         "\"ingress credit parity error\"");
              nvswitch_set_fatal_error(param_1,1,uVar13);
              nvswitch_lib_notify_client_events(param_1,0);
              local_64 = local_64 & 0xffffffffffffff7f;
            }
            if (((uint)local_50 & local_58._4_4_) != 0) {
              (*(code *)param_1[0x125])(param_1,0xc,0,uVar13,iVar11 + 4);
            }
            if ((int)local_64 != 0) {
              iVar10 = nvswitch_translate_hw_error(0x2713);
              if (iVar10 == 1) {
                nvswitch_assert_log();
              }
              lVar15 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                                ,param_1 + 1,*(undefined4 *)(lVar15 + 0x40),
                                *(undefined1 *)(lVar15 + 0x44),*(undefined1 *)(lVar15 + 0x45),
                                *(undefined1 *)(lVar15 + 0x46),0x2713,
                                "_nvswitch_service_nxbar_tileout_lr10",0x116d);
              nvswitch_os_report_error
                        (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                         "_nvswitch_service_nxbar_tileout_lr10",0x116d);
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                         "_nvswitch_service_nxbar_tileout_lr10",0x116d);
              nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_64,4,0x116d,&DAT_00c81851);
            }
            (*(code *)param_1[0x125])(param_1,0xc,0,uVar13,iVar11,local_50._4_4_ ^ uVar23);
            (*(code *)param_1[0x125])(param_1,0xc,0,uVar13,iVar7,uVar23);
            if ((int)local_64 != 0) goto LAB_001e0900;
            iVar17 = iVar17 + 1;
            iVar11 = iVar11 + 0x200;
            local_68 = local_68 & ~uVar16;
          } while (iVar17 != 9);
LAB_001e0ada:
          if (local_68 != 0) {
            iVar11 = nvswitch_translate_hw_error(0x2713);
            if (iVar11 == 1) {
              nvswitch_assert_log();
            }
            lVar15 = *param_1;
            nvswitch_os_print(5,
                              "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                              ,param_1 + 1,*(undefined4 *)(lVar15 + 0x40),
                              *(undefined1 *)(lVar15 + 0x44),*(undefined1 *)(lVar15 + 0x45),
                              *(undefined1 *)(lVar15 + 0x46),0x2713,
                              "_nvswitch_service_nxbar_fatal_lr10",0x11af);
            nvswitch_os_report_error
                      (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                       "_nvswitch_service_nxbar_fatal_lr10",0x11af);
            nvswitch_lib_smbpbi_log_sxid
                      (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                       "_nvswitch_service_nxbar_fatal_lr10",0x11af);
            nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
            nvswitch_record_error
                      (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_68,4,0x11af,&DAT_00c81851);
            if (local_68 != 0) goto LAB_001e2e81;
          }
          local_6c = local_6c & ~uVar22;
          iVar11 = (int)param_1[0x3f1];
        }
        uVar13 = (ulong)(iVar6 + 1U);
      } while (iVar6 + 1U != 4);
LAB_001e0b0e:
      plVar1 = param_1 + 1;
      local_84 = 0;
      uVar22 = 0;
LAB_001e0b33:
      if (iVar11 != 6) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar15 = param_1[0x3f2];
      do {
        uVar13 = (ulong)local_84;
        if (*(char *)(lVar15 + 0x3d10 + uVar13 * 0x20) != '\0') {
          bVar26 = (byte)local_84;
          uVar24 = 1 << (bVar26 & 0x1f);
          if ((uVar14 & uVar24) != 0) goto code_r0x001e0b8f;
        }
        local_84 = local_84 + 1;
        if (local_84 == 9) goto LAB_001e1d29;
        uVar22 = uVar22 + 4;
      } while( true );
    }
    goto LAB_001e2ff0;
  }
  goto LAB_001e06cc;
code_r0x001e0b8f:
  iVar11 = (*(code *)param_1[0x150])(param_1,uVar13);
  iVar6 = _nvswitch_service_nvldl_fatal_lr10(param_1,uVar13);
  iVar17 = _nvswitch_service_nvltlc_fatal_lr10(param_1,uVar13);
  iVar7 = _nvswitch_service_minion_fatal_lr10(param_1,uVar13);
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_64 = 0;
  local_5c = 0;
  uVar12 = (*(code *)param_1[0x124])(param_1,8,0,uVar13,0x280);
  local_58 = CONCAT44(local_58._4_4_,uVar12);
  uVar16 = (*(code *)param_1[0x124])(param_1,8,0,uVar13,0x288);
  local_50 = CONCAT44(uVar16,(uint)local_50);
  local_58 = CONCAT44(uVar16,(uint)local_58) & 0x7ffffffff;
  uVar16 = uVar16 & 7 & (uint)local_58;
  local_80 = (byte)uVar22;
  if (uVar16 == 0) {
LAB_001e316a:
    uVar13 = nvswitch_get_enabled_link_mask(param_1);
    bVar3 = ((iVar7 != 0 && iVar17 != 0) && iVar11 != 0) && iVar6 != 0;
    uVar13 = 0xfL << (local_80 & 0x3f) & uVar13;
    if (uVar13 != 0) {
LAB_001e12cf:
      uVar25 = 0;
      iVar11 = 0;
      while( true ) {
        for (; (uVar13 & 1) == 0; uVar13 = uVar13 >> 1) {
          iVar11 = iVar11 + 1;
        }
        pcVar2 = (code *)param_1[0x122];
        uVar12 = nvswitch_get_link_eng_inst(param_1,iVar11,9);
        iVar6 = (*pcVar2)(param_1,9,0,uVar12,pcVar2);
        if ((iVar6 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,iVar11), cVar4 == '\0')) {
          nvswitch_assert_log();
        }
        pcVar2 = (code *)param_1[0x124];
        uVar12 = nvswitch_get_link_eng_inst(param_1,iVar11,9);
        iVar6 = (*pcVar2)(param_1,9,0,uVar12,0x280,pcVar2);
        if (iVar6 != 0) {
          uVar25 = (uint)(1 << ((byte)iVar11 & 0x1f)) | uVar25;
        }
        uVar13 = uVar13 >> 1;
        if (uVar13 == 0) break;
        iVar11 = iVar11 + 1;
      }
      if (uVar25 != 0) {
        uVar13 = 0;
        do {
          uVar19 = uVar13 & 0xffffffff;
          if ((uVar25 & 1) != 0) {
            local_58 = 0;
            local_50 = 0;
            pcVar2 = (code *)param_1[0x122];
            local_48 = 0;
            local_40 = 0;
            local_64 = 0;
            local_5c = 0;
            uVar12 = nvswitch_get_link_eng_inst(param_1,uVar13 & 0xffffffff,9);
            iVar11 = (*pcVar2)(param_1,9,0,uVar12);
            if ((iVar11 == -1) ||
               (cVar4 = nvswitch_is_link_valid(param_1,uVar13 & 0xffffffff), cVar4 == '\0')) {
              nvswitch_assert_log();
            }
            pcVar2 = (code *)param_1[0x124];
            uVar12 = nvswitch_get_link_eng_inst(param_1,uVar19,9);
            uVar12 = (*pcVar2)(param_1,9,0,uVar12,0x280);
            local_58 = CONCAT44(local_58._4_4_,uVar12);
            pcVar2 = (code *)param_1[0x122];
            uVar12 = nvswitch_get_link_eng_inst(param_1,uVar19,9);
            iVar11 = (*pcVar2)(param_1,9,0,uVar12);
            if ((iVar11 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,uVar19), cVar4 == '\0')) {
              nvswitch_assert_log();
            }
            pcVar2 = (code *)param_1[0x124];
            uVar12 = nvswitch_get_link_eng_inst(param_1,uVar19,9);
            uVar16 = (*pcVar2)(param_1,9,0,uVar12,0x288);
            local_50 = CONCAT44(uVar16,(uint)local_50);
            local_58 = CONCAT44(uVar16,(uint)local_58);
            uVar16 = uVar16 & (uint)local_58;
            if (uVar16 == 0) break;
            pcVar2 = (code *)param_1[0x122];
            local_64 = CONCAT62(local_64._2_6_,CONCAT11((char)uVar13,bVar26)) & 0xffffffffffff03ff;
            local_68 = uVar16;
            uVar12 = nvswitch_get_link_eng_inst(param_1,uVar19,9);
            iVar11 = (*pcVar2)(param_1,9,0,uVar12);
            if ((iVar11 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,uVar19), cVar4 == '\0')) {
              nvswitch_assert_log();
            }
            pcVar2 = (code *)param_1[0x124];
            uVar12 = nvswitch_get_link_eng_inst(param_1,uVar19,9);
            uVar12 = (*pcVar2)(param_1,9,0,uVar12,0x29c);
            local_50 = CONCAT44(local_50._4_4_,uVar12);
            pcVar2 = (code *)param_1[0x122];
            uVar12 = nvswitch_get_link_eng_inst(param_1,uVar19,9);
            iVar11 = (*pcVar2)(param_1,9,0,uVar12);
            if ((iVar11 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,uVar19), cVar4 == '\0')) {
              nvswitch_assert_log();
            }
            pcVar2 = (code *)param_1[0x124];
            uVar12 = nvswitch_get_link_eng_inst(param_1,uVar19,9);
            uVar23 = (*pcVar2)(param_1,9,0,uVar12,0x298);
            if ((uVar16 & 1) != 0) {
              iVar11 = nvswitch_translate_hw_error(0x61af);
              if (iVar11 == 1) {
                nvswitch_assert_log();
              }
              lVar15 = *param_1;
              pcVar20 = "";
              if ((local_50 & 1) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,plVar1,*(undefined4 *)(lVar15 + 0x40),
                                *(undefined1 *)(lVar15 + 0x44),*(undefined1 *)(lVar15 + 0x45),
                                *(undefined1 *)(lVar15 + 0x46),0x61af,uVar19,
                                "No non-empty link is detected",pcVar20);
              pcVar20 = "";
              if ((local_50 & 1) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x61af,"Fatal, Link %02d %s%s\n",uVar13 & 0xffffffff,
                         "No non-empty link is detected",pcVar20);
              pcVar20 = "";
              if ((local_50 & 1) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x61af,"Fatal, Link %02d %s%s\n",uVar13 & 0xffffffff,
                         "No non-empty link is detected",pcVar20);
              nvswitch_inforom_bbx_add_sxid(param_1,0x61af,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x61af,uVar13 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x168a,"\"No non-empty link is detected\"");
              nvswitch_set_fatal_error(param_1,0,uVar13 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xfffffffe;
              if ((uVar23 & 1) == 0) {
                local_64 = CONCAT44(0x39,(int)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar16 & 0x80) != 0) {
              iVar11 = nvswitch_translate_hw_error(0x61b0);
              if (iVar11 == 1) {
                nvswitch_assert_log();
              }
              lVar15 = *param_1;
              pcVar20 = "";
              if ((local_50 & 0x80) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,plVar1,*(undefined4 *)(lVar15 + 0x40),
                                *(undefined1 *)(lVar15 + 0x44),*(undefined1 *)(lVar15 + 0x45),
                                *(undefined1 *)(lVar15 + 0x46),0x61b0,uVar19,
                                "Reset sequencer timed out waiting for a handshake from PHYCTL",
                                pcVar20);
              pcVar20 = "";
              if ((local_50 & 0x80) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x61b0,"Fatal, Link %02d %s%s\n",uVar13 & 0xffffffff,
                         "Reset sequencer timed out waiting for a handshake from PHYCTL",pcVar20);
              pcVar20 = "";
              if ((local_50 & 0x80) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x61b0,"Fatal, Link %02d %s%s\n",uVar13 & 0xffffffff,
                         "Reset sequencer timed out waiting for a handshake from PHYCTL",pcVar20);
              nvswitch_inforom_bbx_add_sxid(param_1,0x61b0,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x61b0,uVar13 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x1697,"\"Reset sequencer timed out waiting for a handshake from PHYCTL\"")
              ;
              nvswitch_set_fatal_error(param_1,0,uVar13 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xffffff7f;
              if ((uVar23 & 0x80) == 0) {
                local_64 = CONCAT44(0x3a,(int)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if ((uVar16 & 0x100) != 0) {
              iVar11 = nvswitch_translate_hw_error(0x61b1);
              if (iVar11 == 1) {
                nvswitch_assert_log();
              }
              lVar15 = *param_1;
              pcVar20 = "";
              if ((local_50 & 0x100) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,plVar1,*(undefined4 *)(lVar15 + 0x40),
                                *(undefined1 *)(lVar15 + 0x44),*(undefined1 *)(lVar15 + 0x45),
                                *(undefined1 *)(lVar15 + 0x46),0x61b1,uVar19,
                                "Reset sequencer timed out waiting for a handshake from CLKCTL",
                                pcVar20);
              pcVar20 = "";
              if ((local_50 & 0x100) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x61b1,"Fatal, Link %02d %s%s\n",uVar13 & 0xffffffff,
                         "Reset sequencer timed out waiting for a handshake from CLKCTL",pcVar20);
              pcVar20 = "";
              if ((local_50 & 0x100) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x61b1,"Fatal, Link %02d %s%s\n",uVar13 & 0xffffffff,
                         "Reset sequencer timed out waiting for a handshake from CLKCTL",pcVar20);
              nvswitch_inforom_bbx_add_sxid(param_1,0x61b1,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x61b1,uVar13 & 0xffffffff,0,1,1,0,&local_58,0x20,
                         0x16a4,"\"Reset sequencer timed out waiting for a handshake from CLKCTL\"")
              ;
              nvswitch_set_fatal_error(param_1,0,uVar13 & 0xffffffff);
              nvswitch_lib_notify_client_events(param_1,0);
              local_68 = local_68 & 0xfffffeff;
              if ((uVar23 & 0x100) == 0) {
                local_64 = CONCAT44(0x3b,(int)local_64);
                nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
              }
            }
            if (local_68 != 0) {
              iVar11 = nvswitch_translate_hw_error(0x2713);
              if (iVar11 == 1) {
                nvswitch_assert_log();
              }
              lVar15 = *param_1;
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                                ,plVar1,*(undefined4 *)(lVar15 + 0x40),
                                *(undefined1 *)(lVar15 + 0x44),*(undefined1 *)(lVar15 + 0x45),
                                *(undefined1 *)(lVar15 + 0x46),0x2713,
                                "_nvswitch_service_nvlipt_lnk_fatal_lr10",0x16ae);
              nvswitch_os_report_error
                        (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                         "_nvswitch_service_nvlipt_lnk_fatal_lr10",0x16ae);
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                         "_nvswitch_service_nvlipt_lnk_fatal_lr10",0x16ae);
              nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_68,4,0x16ae,&DAT_00c81851);
            }
            if ((char)param_1[uVar13 * 8 + 0x1ed] != '\0') {
              pcVar2 = (code *)param_1[0x122];
              uVar12 = nvswitch_get_link_eng_inst(param_1,uVar13 & 0xffffffff,9);
              iVar11 = (*pcVar2)(param_1,9,0,uVar12);
              if ((iVar11 == -1) ||
                 (cVar4 = nvswitch_is_link_valid(param_1,uVar13 & 0xffffffff), cVar4 == '\0')) {
                nvswitch_assert_log();
              }
              uVar23 = uVar16 ^ local_50._4_4_;
              pcVar2 = (code *)param_1[0x125];
              uVar12 = nvswitch_get_link_eng_inst(param_1,uVar13 & 0xffffffff,9);
              (*pcVar2)(param_1,9,0,uVar12,0x288,uVar23);
            }
            if ((local_58._4_4_ & (uint)local_50) != 0) {
              pcVar2 = (code *)param_1[0x122];
              uVar12 = nvswitch_get_link_eng_inst(param_1,uVar13 & 0xffffffff,9);
              iVar11 = (*pcVar2)(param_1,9,0,uVar12);
              if ((iVar11 == -1) ||
                 (cVar4 = nvswitch_is_link_valid(param_1,uVar13 & 0xffffffff), cVar4 == '\0')) {
                nvswitch_assert_log();
              }
              pcVar2 = (code *)param_1[0x125];
              uVar23 = (uint)local_50 & local_58._4_4_;
              uVar12 = nvswitch_get_link_eng_inst(param_1,uVar13 & 0xffffffff,9);
              (*pcVar2)(param_1,9,0,uVar12,0x29c,uVar23);
            }
            pcVar2 = (code *)param_1[0x122];
            uVar12 = nvswitch_get_link_eng_inst(param_1,uVar19,9);
            iVar11 = (*pcVar2)(param_1,9,0,uVar12);
            if ((iVar11 == -1) || (cVar4 = nvswitch_is_link_valid(param_1,uVar19), cVar4 == '\0')) {
              nvswitch_assert_log();
            }
            pcVar2 = (code *)param_1[0x125];
            uVar12 = nvswitch_get_link_eng_inst(param_1,uVar19,9);
            (*pcVar2)(param_1,9,0,uVar12,0x280,uVar16);
            if (local_68 != 0) break;
            if (uVar25 >> 1 == 0) goto LAB_001e1ced;
          }
          uVar25 = uVar25 >> 1;
          uVar13 = uVar13 + 1;
        } while( true );
      }
    }
    if (bVar3) goto LAB_001e1cf8;
  }
  else {
    local_64 = CONCAT71(local_64._1_7_,bVar26);
    local_68 = uVar16;
    uVar12 = (*(code *)param_1[0x124])(param_1,8,0,uVar13,0x29c);
    local_50 = CONCAT44(local_50._4_4_,uVar12);
    uVar8 = (*(code *)param_1[0x124])(param_1,8,0,uVar13,0x294);
    uVar9 = (*(code *)param_1[0x124])(param_1,8,0,uVar13,0x298);
    uVar18 = uVar22;
    uVar23 = uVar22;
    if ((uVar16 & 1) == 0) {
      if ((uVar16 & 2) != 0) {
LAB_001e0ced:
        local_88 = uVar22 + 4;
        uVar18 = uVar22;
        do {
          cVar4 = nvswitch_is_link_valid(param_1,uVar18);
          if (cVar4 != '\0') {
            if ((uVar8 & 2) == 0) {
              iVar10 = nvswitch_translate_hw_error(0x4663);
              if (iVar10 == 1) {
                nvswitch_assert_log();
              }
              lVar15 = *param_1;
              pcVar20 = "";
              if ((local_50 & 2) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar15 + 0x40),
                                *(undefined1 *)(lVar15 + 0x44),*(undefined1 *)(lVar15 + 0x45),
                                *(undefined1 *)(lVar15 + 0x46),0x4663,uVar18,"RSTSEQ_PLL_TIMEOUT",
                                pcVar20);
              pcVar20 = "";
              if ((local_50 & 2) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4663,"Non-fatal, Link %02d %s%s\n",uVar18,"RSTSEQ_PLL_TIMEOUT"
                         ,pcVar20);
              pcVar20 = "";
              if ((local_50 & 2) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4663,"Non-fatal, Link %02d %s%s\n",uVar18,"RSTSEQ_PLL_TIMEOUT",
                         pcVar20);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4663,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x24,0x4663,uVar18,0,1,0,0,&local_58,0x20,0x1625,
                         "\"RSTSEQ_PLL_TIMEOUT\"");
              nvswitch_lib_notify_client_events(param_1,1);
            }
            else {
              iVar10 = nvswitch_translate_hw_error(0x4663);
              if (iVar10 == 1) {
                nvswitch_assert_log();
              }
              lVar15 = *param_1;
              pcVar20 = "";
              if ((local_50 & 2) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_print(5,
                                "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                                ,param_1 + 1,*(undefined4 *)(lVar15 + 0x40),
                                *(undefined1 *)(lVar15 + 0x44),*(undefined1 *)(lVar15 + 0x45),
                                *(undefined1 *)(lVar15 + 0x46),0x4663,uVar18,"RSTSEQ_PLL_TIMEOUT",
                                pcVar20);
              pcVar20 = "";
              if ((local_50 & 2) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_os_report_error
                        (param_1[3],0x4663,"Fatal, Link %02d %s%s\n",uVar18,"RSTSEQ_PLL_TIMEOUT",
                         pcVar20);
              pcVar20 = "";
              if ((local_50 & 2) != 0) {
                pcVar20 = " (First)";
              }
              nvswitch_lib_smbpbi_log_sxid
                        (param_1,0x4663,"Fatal, Link %02d %s%s\n",uVar18,"RSTSEQ_PLL_TIMEOUT",
                         pcVar20);
              nvswitch_inforom_bbx_add_sxid(param_1,0x4663,0,0,0);
              nvswitch_record_error
                        (param_1,param_1 + 0x1f,0x4663,uVar18,0,1,1,0,&local_58,0x20,0x1625,
                         "\"RSTSEQ_PLL_TIMEOUT\"");
              nvswitch_set_fatal_error(param_1,0,uVar18);
              nvswitch_lib_notify_client_events(param_1,0);
            }
          }
          uVar18 = uVar18 + 1;
        } while (local_88 != uVar18);
        local_68 = local_68 & 0xfffffffd;
        if ((uVar9 & 2) == 0) {
          local_64 = CONCAT44(0x3d,(int)local_64);
          nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
        }
        goto LAB_001e0e5c;
      }
LAB_001e10ad:
      do {
        cVar4 = nvswitch_is_link_valid(param_1,uVar23);
        if (cVar4 != '\0') {
          if ((uVar8 & 4) == 0) {
            iVar10 = nvswitch_translate_hw_error(0x4662);
            if (iVar10 == 1) {
              nvswitch_assert_log();
            }
            lVar15 = *param_1;
            pcVar20 = "";
            if ((local_50 & 4) != 0) {
              pcVar20 = " (First)";
            }
            nvswitch_os_print(5,
                              "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                              ,param_1 + 1,*(undefined4 *)(lVar15 + 0x40),
                              *(undefined1 *)(lVar15 + 0x44),*(undefined1 *)(lVar15 + 0x45),
                              *(undefined1 *)(lVar15 + 0x46),0x4662,uVar23,"RSTSEQ_PHYARB_TIMEOUT",
                              pcVar20);
            pcVar20 = "";
            if ((local_50 & 4) != 0) {
              pcVar20 = " (First)";
            }
            nvswitch_os_report_error
                      (param_1[3],0x4662,"Non-fatal, Link %02d %s%s\n",uVar23,
                       "RSTSEQ_PHYARB_TIMEOUT",pcVar20);
            pcVar20 = "";
            if ((local_50 & 4) != 0) {
              pcVar20 = " (First)";
            }
            nvswitch_lib_smbpbi_log_sxid
                      (param_1,0x4662,"Non-fatal, Link %02d %s%s\n",uVar23,"RSTSEQ_PHYARB_TIMEOUT",
                       pcVar20);
            nvswitch_inforom_bbx_add_sxid(param_1,0x4662,0,0,0);
            nvswitch_record_error
                      (param_1,param_1 + 0x24,0x4662,uVar23,0,1,0,0,&local_58,0x20,0x163a,
                       "\"RSTSEQ_PHYARB_TIMEOUT\"");
            nvswitch_lib_notify_client_events(param_1,1);
          }
          else {
            iVar10 = nvswitch_translate_hw_error(0x4662);
            if (iVar10 == 1) {
              nvswitch_assert_log();
            }
            lVar15 = *param_1;
            pcVar20 = "";
            if ((local_50 & 4) != 0) {
              pcVar20 = " (First)";
            }
            nvswitch_os_print(5,
                              "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                              ,param_1 + 1,*(undefined4 *)(lVar15 + 0x40),
                              *(undefined1 *)(lVar15 + 0x44),*(undefined1 *)(lVar15 + 0x45),
                              *(undefined1 *)(lVar15 + 0x46),0x4662,uVar23,"RSTSEQ_PHYARB_TIMEOUT",
                              pcVar20);
            pcVar20 = "";
            if ((local_50 & 4) != 0) {
              pcVar20 = " (First)";
            }
            nvswitch_os_report_error
                      (param_1[3],0x4662,"Fatal, Link %02d %s%s\n",uVar23,"RSTSEQ_PHYARB_TIMEOUT",
                       pcVar20);
            pcVar20 = "";
            if ((local_50 & 4) != 0) {
              pcVar20 = " (First)";
            }
            nvswitch_lib_smbpbi_log_sxid
                      (param_1,0x4662,"Fatal, Link %02d %s%s\n",uVar23,"RSTSEQ_PHYARB_TIMEOUT",
                       pcVar20);
            nvswitch_inforom_bbx_add_sxid(param_1,0x4662,0,0,0);
            nvswitch_record_error
                      (param_1,param_1 + 0x1f,0x4662,uVar23,0,1,1,0,&local_58,0x20,0x163a,
                       "\"RSTSEQ_PHYARB_TIMEOUT\"");
            nvswitch_set_fatal_error(param_1,0,uVar23);
            nvswitch_lib_notify_client_events(param_1,0);
          }
        }
        local_88 = uVar22 + 4;
        uVar23 = uVar23 + 1;
      } while (local_88 != uVar23);
      local_68 = local_68 & 0xfffffffb;
      if ((uVar9 & 4) == 0) {
        local_64 = CONCAT44(0x3e,(int)local_64);
        nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
      }
    }
    else {
      do {
        cVar4 = nvswitch_is_link_valid(param_1,uVar18);
        if (cVar4 != '\0') {
          if ((uVar8 & 1) == 0) {
            iVar10 = nvswitch_translate_hw_error(0x4664);
            if (iVar10 == 1) {
              nvswitch_assert_log();
            }
            lVar15 = *param_1;
            pcVar20 = "";
            if ((local_50 & 1) != 0) {
              pcVar20 = " (First)";
            }
            nvswitch_os_print(5,
                              "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Non-fatal, Link %02d %s%s\n"
                              ,param_1 + 1,*(undefined4 *)(lVar15 + 0x40),
                              *(undefined1 *)(lVar15 + 0x44),*(undefined1 *)(lVar15 + 0x45),
                              *(undefined1 *)(lVar15 + 0x46),0x4664,uVar18,"CLKCTL_ILLEGAL_REQUEST",
                              pcVar20);
            pcVar20 = "";
            if ((local_50 & 1) != 0) {
              pcVar20 = " (First)";
            }
            nvswitch_os_report_error
                      (param_1[3],0x4664,"Non-fatal, Link %02d %s%s\n",uVar18,
                       "CLKCTL_ILLEGAL_REQUEST",pcVar20);
            pcVar20 = "";
            if ((local_50 & 1) != 0) {
              pcVar20 = " (First)";
            }
            nvswitch_lib_smbpbi_log_sxid
                      (param_1,0x4664,"Non-fatal, Link %02d %s%s\n",uVar18,"CLKCTL_ILLEGAL_REQUEST",
                       pcVar20);
            nvswitch_inforom_bbx_add_sxid(param_1,0x4664,0,0,0);
            nvswitch_record_error
                      (param_1,param_1 + 0x24,0x4664,uVar18,0,1,0,0,&local_58,0x20,0x1610,
                       "\"CLKCTL_ILLEGAL_REQUEST\"");
            nvswitch_lib_notify_client_events(param_1,1);
          }
          else {
            iVar10 = nvswitch_translate_hw_error(0x4664);
            if (iVar10 == 1) {
              nvswitch_assert_log();
            }
            lVar15 = *param_1;
            pcVar20 = "";
            if ((local_50 & 1) != 0) {
              pcVar20 = " (First)";
            }
            nvswitch_os_print(5,
                              "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, Link %02d %s%s\n"
                              ,param_1 + 1,*(undefined4 *)(lVar15 + 0x40),
                              *(undefined1 *)(lVar15 + 0x44),*(undefined1 *)(lVar15 + 0x45),
                              *(undefined1 *)(lVar15 + 0x46),0x4664,uVar18,"CLKCTL_ILLEGAL_REQUEST",
                              pcVar20);
            pcVar20 = "";
            if ((local_50 & 1) != 0) {
              pcVar20 = " (First)";
            }
            nvswitch_os_report_error
                      (param_1[3],0x4664,"Fatal, Link %02d %s%s\n",uVar18,"CLKCTL_ILLEGAL_REQUEST",
                       pcVar20);
            pcVar20 = "";
            if ((local_50 & 1) != 0) {
              pcVar20 = " (First)";
            }
            nvswitch_lib_smbpbi_log_sxid
                      (param_1,0x4664,"Fatal, Link %02d %s%s\n",uVar18,"CLKCTL_ILLEGAL_REQUEST",
                       pcVar20);
            nvswitch_inforom_bbx_add_sxid(param_1,0x4664,0,0,0);
            nvswitch_record_error
                      (param_1,param_1 + 0x1f,0x4664,uVar18,0,1,1,0,&local_58,0x20,0x1610,
                       "\"CLKCTL_ILLEGAL_REQUEST\"");
            nvswitch_set_fatal_error(param_1,0,uVar18);
            nvswitch_lib_notify_client_events(param_1,0);
          }
        }
        local_88 = uVar22 + 4;
        uVar18 = uVar18 + 1;
      } while (local_88 != uVar18);
      local_68 = local_68 & 0xfffffffe;
      if ((uVar9 & 1) == 0) {
        local_64 = CONCAT44(0x3c,(int)local_64);
        nvswitch_inforom_nvlink_log_error_event(param_1,&local_64);
      }
      if ((uVar16 & 2) != 0) goto LAB_001e0ced;
LAB_001e0e5c:
      if ((uVar16 & 4) != 0) goto LAB_001e10ad;
    }
    if (local_68 != 0) {
      iVar10 = nvswitch_translate_hw_error(0x2713);
      if (iVar10 == 1) {
        nvswitch_assert_log();
      }
      lVar15 = *param_1;
      nvswitch_os_print(5,
                        "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                        ,param_1 + 1,*(undefined4 *)(lVar15 + 0x40),*(undefined1 *)(lVar15 + 0x44),
                        *(undefined1 *)(lVar15 + 0x45),*(undefined1 *)(lVar15 + 0x46),0x2713,
                        "_nvswitch_service_nvlipt_common_fatal_lr10",0x1647);
      nvswitch_os_report_error
                (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_nvlipt_common_fatal_lr10",0x1647);
      nvswitch_lib_smbpbi_log_sxid
                (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
                 "_nvswitch_service_nvlipt_common_fatal_lr10",0x1647);
      nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
      nvswitch_record_error
                (param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_68,4,0x1647,&DAT_00c81851);
    }
    local_88 = uVar22 + 4;
    uVar23 = uVar22;
    do {
      cVar4 = nvswitch_is_link_valid(param_1,(ulong)uVar23);
      if ((cVar4 != '\0') && ((char)param_1[(ulong)uVar23 * 8 + 0x1ed] != '\0')) {
        (*(code *)param_1[0x125])(param_1,8,0,local_84,0x288,local_50._4_4_ ^ uVar16);
        break;
      }
      uVar23 = uVar23 + 1;
    } while (local_88 != uVar23);
    if (((uint)local_50 & local_58._4_4_) != 0) {
      (*(code *)param_1[0x125])(param_1,8,0,local_84,0x29c);
    }
    (*(code *)param_1[0x125])(param_1,8,0,local_84,0x280,uVar16);
    if (local_68 != 0) goto LAB_001e316a;
    bVar3 = false;
    uVar13 = nvswitch_get_enabled_link_mask(param_1);
    uVar13 = 0xfL << (local_80 & 0x3f) & uVar13;
    if (uVar13 != 0) goto LAB_001e12cf;
  }
LAB_001e1ced:
  local_6c = local_6c & ~uVar24;
LAB_001e1cf8:
  local_88 = uVar22 + 4;
  local_84 = local_84 + 1;
  iVar11 = (int)param_1[0x3f1];
  uVar22 = local_88;
  if (local_84 == 9) goto code_r0x001e1d13;
  goto LAB_001e0b33;
code_r0x001e1d13:
  if (iVar11 != 6) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar15 = param_1[0x3f2];
LAB_001e1d29:
  if ((((&DAT_000037f0)[lVar15] != '\0') && ((uVar14 & 0x40000) != 0)) &&
     (iVar11 = soeService_HAL(param_1,param_1[0x1a4]), iVar11 == 0)) {
    local_6c = local_6c & 0xfffbffff;
  }
  if (local_6c == 0) {
LAB_001e1d41:
    _nvswitch_service_saw_nonfatal_lr10(param_1);
  }
  else {
    iVar11 = nvswitch_translate_hw_error(0x2713);
    if (iVar11 == 1) {
      nvswitch_assert_log();
    }
    lVar15 = *param_1;
    nvswitch_os_print(5,
                      "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                      ,param_1 + 1,*(undefined4 *)(lVar15 + 0x40),*(undefined1 *)(lVar15 + 0x44),
                      *(undefined1 *)(lVar15 + 0x45),*(undefined1 *)(lVar15 + 0x46),0x2713,
                      "_nvswitch_service_saw_fatal_lr10",0x1768);
    nvswitch_os_report_error
              (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
               "_nvswitch_service_saw_fatal_lr10",0x1768);
    nvswitch_lib_smbpbi_log_sxid
              (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
               "_nvswitch_service_saw_fatal_lr10",0x1768);
    nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
    nvswitch_record_error(param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_6c,4,0x1768,&DAT_00c81851);
    if (local_6c == 0) goto LAB_001e1d41;
LAB_001e2ff0:
    iVar11 = _nvswitch_service_saw_nonfatal_lr10(param_1);
    if (iVar11 != 0) goto LAB_001e06cc;
  }
  local_70 = local_70 & 0xffbfffff;
LAB_001e06cc:
  if (((uVar5 & 0x40000000) != 0) &&
     (iVar11 = _nvswitch_service_priv_ring_lr10(param_1), iVar11 == 0)) {
    local_70 = local_70 & 0xbfffffff;
  }
  if (((uVar5 & 0x10000000) != 0) && (iVar11 = _nvswitch_service_pbus_lr10(param_1), iVar11 == 0)) {
    local_70 = local_70 & 0xefffffff;
  }
  if (local_70 != 0) {
    iVar11 = nvswitch_translate_hw_error(0x2713);
    if (iVar11 == 1) {
      nvswitch_assert_log();
    }
    lVar15 = *param_1;
    nvswitch_os_print(5,
                      "nvidia-%s: SXid (PCI:%04x:%02x:%02x.%x): %05d, Fatal, unhandled interrupt in %s(%d)\n"
                      ,param_1 + 1,*(undefined4 *)(lVar15 + 0x40),*(undefined1 *)(lVar15 + 0x44),
                      *(undefined1 *)(lVar15 + 0x45),*(undefined1 *)(lVar15 + 0x46),0x2713,
                      "_nvswitch_service_legacy_lr10",0x17b6);
    nvswitch_os_report_error
              (param_1[3],0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
               "_nvswitch_service_legacy_lr10",0x17b6);
    nvswitch_lib_smbpbi_log_sxid
              (param_1,0x2713,"Fatal, unhandled interrupt in %s(%d)\n",
               "_nvswitch_service_legacy_lr10",0x17b6);
    nvswitch_inforom_bbx_add_sxid(param_1,0x2713,0,0,0);
    nvswitch_record_error(param_1,param_1 + 0x1f,0x2713,0,0,1,1,0,&local_70,4,0x17b6,&DAT_00c81851);
    if (local_70 != 0) {
      return 0xfffffff6;
    }
  }
LAB_001e06ef:
  (*(code *)param_1[0x125])(param_1,0,0,0,0x704,0xff);
  return 0;
}


// ===== 001e31d0 nvswitch_setup_link_loopback_mode_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */

void nvswitch_setup_link_loopback_mode_lr10(long param_1,uint param_2)

{
  code *pcVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  
  lVar5 = nvswitch_get_link(param_1,param_2 & 0xff);
  if (lVar5 != 0) {
    pcVar1 = *(code **)(param_1 + 0x910);
    uVar3 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(lVar5 + 0x38),0xb);
    iVar4 = (*pcVar1)(param_1,0xb,0,uVar3);
    if (((iVar4 != -1) &&
        (cVar2 = nvswitch_is_link_valid(param_1,*(undefined4 *)(lVar5 + 0x38)), param_2 < 0x40)) &&
       (cVar2 != '\0')) {
      uVar6 = (ulong)*(uint *)(lVar5 + 0x38);
      if (*(char *)(param_1 + 0xf6b + uVar6 * 0x40) != '\0') {
        nvswitch_minion_send_command(param_1,uVar6,0x41,0);
        uVar6 = (ulong)*(uint *)(lVar5 + 0x38);
      }
      if (*(char *)(param_1 + 0xf6c + uVar6 * 0x40) != '\0') {
        nvswitch_minion_send_command(param_1,uVar6,0x42,0);
        uVar6 = (ulong)*(uint *)(lVar5 + 0x38);
      }
      if (*(char *)(param_1 + 0xf6d + uVar6 * 0x40) != '\0') {
        nvswitch_minion_send_command(param_1,uVar6,0x43,0);
        return;
      }
    }
  }
  return;
}


// ===== 001e3300 nvswitch_is_link_in_reset_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */

uint nvswitch_is_link_in_reset_lr10(long param_1,long param_2)

{
  code *pcVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar3 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  iVar4 = (*pcVar1)(param_1,9,0,uVar3);
  if (iVar4 != -1) {
    cVar2 = nvswitch_is_link_valid(param_1,*(undefined4 *)(param_2 + 0x38));
    if (cVar2 != '\0') goto LAB_001e3357;
  }
  nvswitch_assert_log();
LAB_001e3357:
  pcVar1 = *(code **)(param_1 + 0x920);
  uVar3 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  uVar5 = (*pcVar1)(param_1,9,0,uVar3,0x380);
  return uVar5 >> 1 & 1;
}


// ===== 001e33a0 nvswitch_poll_sublink_state_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */

undefined8 nvswitch_poll_sublink_state_lr10(long param_1,long param_2)

{
  code *pcVar1;
  char cVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  undefined1 local_30 [8];
  
  if ((*(char *)(param_1 + 0x25) == '\0') && (*(char *)(param_1 + 0x24) == '\0')) {
    lVar7 = (-(ulong)(*(char *)(param_1 + 0x26) == '\0') & 0xffffffff94b62e00) + 2000000000;
  }
  else {
    lVar7 = 2000000000;
  }
  nvswitch_timeout_create(lVar7,local_30);
  do {
    cVar2 = nvswitch_timeout_check(local_30);
    pcVar1 = *(code **)(param_1 + 0x910);
    uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),0xb);
    iVar5 = (*pcVar1)(param_1,0xb,0,uVar4);
    if (iVar5 == -1) {
LAB_001e3447:
      nvswitch_assert_log();
    }
    else {
      cVar3 = nvswitch_is_link_valid(param_1,*(undefined4 *)(param_2 + 0x38));
      if (cVar3 == '\0') goto LAB_001e3447;
    }
    pcVar1 = *(code **)(param_1 + 0x920);
    uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),0xb);
    uVar6 = (*pcVar1)(param_1,0xb,0,uVar4,0x44);
    if ((uVar6 & 3) == 2) {
      return 0xfffffff8;
    }
    if ((uVar6 & 3) == 0) {
      return 0;
    }
    nvswitch_os_sleep(1);
    if (cVar2 != '\0') {
      return 0xfffffff9;
    }
  } while( true );
}


// ===== 001e34f0 nvswitch_get_sublink_width_lr10 =====

undefined8 nvswitch_get_sublink_width_lr10(void)

{
  return 4;
}


// ===== 001e3500 nvswitch_init_dlpl_interrupts_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_r15 replaced with injection: x86_indirect_thunk_r15 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_init_dlpl_interrupts_lr10(long param_1)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  
  uVar10 = *(undefined4 *)(param_1 + 0x38);
  lVar2 = *(long *)(*(long *)(param_1 + 0x10) + 200);
  uVar1 = *(uint *)(lVar2 + 200);
  iVar9 = *(int *)(lVar2 + 0xcc);
  pcVar3 = *(code **)(lVar2 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar10,0xb);
  iVar6 = (*pcVar3)(lVar2,0xb,0,uVar5);
  if (iVar6 == -1) {
LAB_001e39b0:
    nvswitch_assert_log();
  }
  else {
    cVar4 = nvswitch_is_link_valid(lVar2,uVar10);
    if (cVar4 == '\0') goto LAB_001e39b0;
  }
  pcVar3 = *(code **)(lVar2 + 0x928);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar10,0xb);
  (*pcVar3)(lVar2,0xb,0,uVar5,0x50,0xffffffff);
  pcVar3 = *(code **)(lVar2 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar10,0xb);
  iVar6 = (*pcVar3)(lVar2,0xb,0,uVar5);
  if (iVar6 == -1) {
LAB_001e39a0:
    nvswitch_assert_log();
  }
  else {
    cVar4 = nvswitch_is_link_valid(lVar2,uVar10);
    if (cVar4 == '\0') goto LAB_001e39a0;
  }
  pcVar3 = *(code **)(lVar2 + 0x928);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar10,0xb);
  (*pcVar3)(lVar2,0xb,0,uVar5,0x54,0xffffffff);
  pcVar3 = *(code **)(lVar2 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar10,0xb);
  iVar6 = (*pcVar3)(lVar2,0xb,0,uVar5);
  if (iVar6 == -1) {
LAB_001e3990:
    nvswitch_assert_log();
  }
  else {
    cVar4 = nvswitch_is_link_valid(lVar2,uVar10);
    if (cVar4 == '\0') goto LAB_001e3990;
  }
  pcVar3 = *(code **)(lVar2 + 0x928);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar10,0xb);
  (*pcVar3)(lVar2,0xb,0,uVar5,0x58,0x10100030);
  pcVar3 = *(code **)(lVar2 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar10,0xb);
  iVar6 = (*pcVar3)(lVar2,0xb,0,uVar5);
  if (iVar6 == -1) {
LAB_001e3980:
    nvswitch_assert_log();
  }
  else {
    cVar4 = nvswitch_is_link_valid(lVar2,uVar10);
    if (cVar4 == '\0') goto LAB_001e3980;
  }
  pcVar3 = *(code **)(lVar2 + 0x928);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar10,0xb);
  (*pcVar3)(lVar2,0xb,0,uVar5,0x5c,0x1000000);
  pcVar3 = *(code **)(lVar2 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar10,0xb);
  iVar6 = (*pcVar3)(lVar2,0xb,0,uVar5);
  if (iVar6 == -1) {
LAB_001e3970:
    nvswitch_assert_log();
  }
  else {
    cVar4 = nvswitch_is_link_valid(lVar2,uVar10);
    if (cVar4 == '\0') goto LAB_001e3970;
  }
  pcVar3 = *(code **)(lVar2 + 0x920);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar10,0xb);
  uVar7 = (*pcVar3)(lVar2,0xb,0,uVar5,0x5c);
  pcVar3 = *(code **)(lVar2 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar10,0xb);
  iVar6 = (*pcVar3)(lVar2,0xb,0,uVar5,pcVar3);
  if (iVar6 == -1) {
LAB_001e3960:
    nvswitch_assert_log();
  }
  else {
    cVar4 = nvswitch_is_link_valid(lVar2,uVar10);
    if (cVar4 == '\0') goto LAB_001e3960;
  }
  pcVar3 = *(code **)(lVar2 + 0x920);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar10,0xb);
  uVar8 = (*pcVar3)(lVar2,0xb,0,uVar5,0x3284,pcVar3);
  if (uVar1 != 0) {
    uVar7 = uVar7 | 0x200000;
  }
  if (uVar1 != 0) {
    uVar8 = uVar8 & 0xfffff080 | uVar1;
  }
  if (iVar9 != 0) {
    uVar7 = uVar7 | 0x400000;
  }
  pcVar3 = *(code **)(lVar2 + 0x910);
  if (iVar9 != 0) {
    uVar8 = iVar9 << 0x10 | uVar8 & 0xffffe080;
  }
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar10,0xb);
  iVar9 = (*pcVar3)(lVar2,0xb,0,uVar5);
  if (iVar9 == -1) {
LAB_001e3950:
    nvswitch_assert_log();
  }
  else {
    cVar4 = nvswitch_is_link_valid(lVar2,uVar10);
    if (cVar4 == '\0') goto LAB_001e3950;
  }
  pcVar3 = *(code **)(lVar2 + 0x928);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar10,0xb);
  (*pcVar3)(lVar2,0xb,0,uVar5,0x5c,uVar7);
  pcVar3 = *(code **)(lVar2 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar10,0xb);
  iVar9 = (*pcVar3)(lVar2,0xb,0,uVar5);
  if (iVar9 != -1) {
    cVar4 = nvswitch_is_link_valid(lVar2,uVar10);
    if (cVar4 != '\0') goto LAB_001e3907;
  }
  nvswitch_assert_log();
LAB_001e3907:
  pcVar3 = *(code **)(lVar2 + 0x928);
  uVar10 = nvswitch_get_link_eng_inst(lVar2,uVar10,0xb);
  (*pcVar3)(lVar2,0xb,0,uVar10,0x3284,uVar8);
  return;
}


// ===== 001e39c0 nvswitch_store_topology_information_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */

void nvswitch_store_topology_information_lr10(long param_1,long param_2)

{
  code *pcVar1;
  char cVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  
  *(undefined1 *)(param_2 + 0x88) = 1;
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  iVar5 = (*pcVar1)(param_1,9,0,uVar4);
  if (iVar5 == -1) {
LAB_001e3d40:
    nvswitch_assert_log();
  }
  else {
    cVar2 = nvswitch_is_link_valid(param_1,*(undefined4 *)(param_2 + 0x38));
    if (cVar2 == '\0') goto LAB_001e3d40;
  }
  pcVar1 = *(code **)(param_1 + 0x920);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  lVar7 = (*pcVar1)(param_1,9,0,uVar4,0x10c);
  *(long *)(param_2 + 0x78) = lVar7 << 0x20;
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  iVar5 = (*pcVar1)(param_1,9,0,uVar4);
  if (iVar5 == -1) {
LAB_001e3d30:
    nvswitch_assert_log();
  }
  else {
    cVar2 = nvswitch_is_link_valid(param_1,*(undefined4 *)(param_2 + 0x38));
    if (cVar2 == '\0') goto LAB_001e3d30;
  }
  pcVar1 = *(code **)(param_1 + 0x920);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  uVar6 = (*pcVar1)(param_1,9,0,uVar4,0x108);
  *(ulong *)(param_2 + 0x78) = *(ulong *)(param_2 + 0x78) | (ulong)uVar6;
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  iVar5 = (*pcVar1)(param_1,9,0,uVar4);
  if (iVar5 == -1) {
LAB_001e3d20:
    nvswitch_assert_log();
  }
  else {
    cVar2 = nvswitch_is_link_valid(param_1,*(undefined4 *)(param_2 + 0x38));
    if (cVar2 == '\0') goto LAB_001e3d20;
  }
  pcVar1 = *(code **)(param_1 + 0x920);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  bVar3 = (*pcVar1)(param_1,9,0,uVar4,0x110);
  *(uint *)(param_2 + 0x80) = (uint)bVar3;
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),8);
  iVar5 = (*pcVar1)(param_1,8,0,uVar4);
  if (iVar5 == -1) {
LAB_001e3d10:
    nvswitch_assert_log();
  }
  else {
    cVar2 = nvswitch_is_link_valid(param_1,*(undefined4 *)(param_2 + 0x38));
    if (cVar2 == '\0') goto LAB_001e3d10;
  }
  pcVar1 = *(code **)(param_1 + 0x920);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),8);
  lVar7 = (*pcVar1)(param_1,8,0,uVar4,0x10c);
  *(long *)(param_2 + 0x70) = lVar7 << 0x20;
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),8);
  iVar5 = (*pcVar1)(param_1,8,0,uVar4);
  if (iVar5 == -1) {
LAB_001e3d00:
    nvswitch_assert_log();
  }
  else {
    cVar2 = nvswitch_is_link_valid(param_1,*(undefined4 *)(param_2 + 0x38));
    if (cVar2 == '\0') goto LAB_001e3d00;
  }
  pcVar1 = *(code **)(param_1 + 0x920);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),8);
  uVar6 = (*pcVar1)(param_1,8,0,uVar4,0x108);
  *(ulong *)(param_2 + 0x70) = *(ulong *)(param_2 + 0x70) | (ulong)uVar6;
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  iVar5 = (*pcVar1)(param_1,9,0,uVar4);
  if (iVar5 != -1) {
    cVar2 = nvswitch_is_link_valid(param_1,*(undefined4 *)(param_2 + 0x38));
    if (cVar2 != '\0') goto LAB_001e3c9c;
  }
  nvswitch_assert_log();
LAB_001e3c9c:
  pcVar1 = *(code **)(param_1 + 0x920);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  iVar5 = (*pcVar1)(param_1,9,0,uVar4,0x104);
  if ((iVar5 != 2) && (iVar5 != 3)) {
    iVar5 = 0xff;
  }
  *(int *)(param_2 + 0x84) = iVar5;
  return;
}


// ===== 001e3d50 nvswitch_init_lpwr_regs_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void nvswitch_init_lpwr_regs_lr10(long param_1)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 200);
  if (((*(char *)(lVar1 + 0x25) == '\0') && (*(char *)(lVar1 + 0x24) == '\0')) &&
     (*(char *)(lVar1 + 0x26) == '\0')) {
    uVar8 = *(undefined4 *)(param_1 + 0x38);
    cVar3 = nvswitch_is_link_in_reset(lVar1,param_1);
    if ((cVar3 == '\0') && (*(int *)(lVar1 + 0x58) != 0)) {
      pcVar2 = *(code **)(lVar1 + 0x910);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      iVar5 = (*pcVar2)(lVar1,10,0,uVar4,pcVar2);
      if ((iVar5 == -1) || (cVar3 = nvswitch_is_link_valid(lVar1,uVar8), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x928);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      (*pcVar2)(lVar1,10,0,uVar4,0x1418,&DAT_00f5d1b0);
      pcVar2 = *(code **)(lVar1 + 0x910);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      iVar5 = (*pcVar2)(lVar1,10,0,uVar4,pcVar2);
      if ((iVar5 == -1) || (cVar3 = nvswitch_is_link_valid(lVar1,uVar8), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x928);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      (*pcVar2)(lVar1,10,0,uVar4,0x1c18,&DAT_00f5d1b0);
      pcVar2 = *(code **)(lVar1 + 0x910);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      iVar5 = (*pcVar2)(lVar1,10,0,uVar4,pcVar2);
      if ((iVar5 == -1) || (cVar3 = nvswitch_is_link_valid(lVar1,uVar8), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x928);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      (*pcVar2)(lVar1,10,0,uVar4,0x1408,0x10001);
      pcVar2 = *(code **)(lVar1 + 0x910);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      iVar5 = (*pcVar2)(lVar1,10,0,uVar4,pcVar2);
      if ((iVar5 == -1) || (cVar3 = nvswitch_is_link_valid(lVar1,uVar8), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x928);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      (*pcVar2)(lVar1,10,0,uVar4,0x1c08,0x10001);
      pcVar2 = *(code **)(lVar1 + 0x910);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      iVar5 = (*pcVar2)(lVar1,10,0,uVar4,pcVar2);
      if ((iVar5 == -1) || (cVar3 = nvswitch_is_link_valid(lVar1,uVar8), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x928);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      (*pcVar2)(lVar1,10,0,uVar4,0x140c,0xffff0001);
      pcVar2 = *(code **)(lVar1 + 0x910);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      iVar5 = (*pcVar2)(lVar1,10,0,uVar4,pcVar2);
      if ((iVar5 == -1) || (cVar3 = nvswitch_is_link_valid(lVar1,uVar8), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x928);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      (*pcVar2)(lVar1,10,0,uVar4,0x1c0c,0xffff0001);
      pcVar2 = *(code **)(lVar1 + 0x910);
      iVar5 = 0xf5d1b0;
      if (*(int *)(lVar1 + 0xd0) != 0) {
        iVar5 = *(int *)(lVar1 + 0xd0);
      }
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      iVar6 = (*pcVar2)(lVar1,10,0,uVar4,pcVar2);
      if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(lVar1,uVar8), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x928);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      (*pcVar2)(lVar1,10,0,uVar4,0x1410,iVar5);
      pcVar2 = *(code **)(lVar1 + 0x910);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      iVar6 = (*pcVar2)(lVar1,10,0,uVar4,pcVar2);
      if ((iVar6 == -1) || (cVar3 = nvswitch_is_link_valid(lVar1,uVar8), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x928);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      (*pcVar2)(lVar1,10,0,uVar4,0x1c10,iVar5);
      pcVar2 = *(code **)(lVar1 + 0x910);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      iVar5 = (*pcVar2)(lVar1,10,0,uVar4,pcVar2);
      if ((iVar5 == -1) || (cVar3 = nvswitch_is_link_valid(lVar1,uVar8), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x928);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      (*pcVar2)(lVar1,10,0,uVar4,0x1414,&DAT_00f4d1b1);
      pcVar2 = *(code **)(lVar1 + 0x910);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      iVar5 = (*pcVar2)(lVar1,10,0,uVar4,pcVar2);
      if ((iVar5 == -1) || (cVar3 = nvswitch_is_link_valid(lVar1,uVar8), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x928);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      (*pcVar2)(lVar1,10,0,uVar4,0x1c14,&DAT_00f4d1b1);
      pcVar2 = *(code **)(lVar1 + 0x910);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      iVar5 = (*pcVar2)(lVar1,10,0,uVar4,pcVar2);
      if ((iVar5 == -1) || (cVar3 = nvswitch_is_link_valid(lVar1,uVar8), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x920);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      uVar7 = (*pcVar2)(lVar1,10,0,uVar4,0x1400,pcVar2);
      pcVar2 = *(code **)(lVar1 + 0x910);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      iVar5 = (*pcVar2)(lVar1,10,0,uVar4,pcVar2);
      if ((iVar5 == -1) || (cVar3 = nvswitch_is_link_valid(lVar1,uVar8), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x928);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      (*pcVar2)(lVar1,10,0,uVar4,0x1400,uVar7 & 0xfffffff7 | 4);
      pcVar2 = *(code **)(lVar1 + 0x910);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      iVar5 = (*pcVar2)(lVar1,10,0,uVar4,pcVar2);
      if ((iVar5 == -1) || (cVar3 = nvswitch_is_link_valid(lVar1,uVar8), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x920);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      uVar7 = (*pcVar2)(lVar1,10,0,uVar4,0x1c00,pcVar2);
      pcVar2 = *(code **)(lVar1 + 0x910);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      iVar5 = (*pcVar2)(lVar1,10,0,uVar4,pcVar2);
      if ((iVar5 == -1) || (cVar3 = nvswitch_is_link_valid(lVar1,uVar8), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x928);
      uVar8 = nvswitch_get_link_eng_inst(lVar1,uVar8,10);
      (*pcVar2)(lVar1,10,0,uVar8,0x1c00,uVar7 & 0xfffffff7 | 4);
      return;
    }
  }
  return;
}


// ===== 001e4530 nvswitch_program_l1_scratch_reg_lr10 =====

void nvswitch_program_l1_scratch_reg_lr10(void)

{
  return;
}


// ===== 001e4540 nvswitch_init_buffer_ready_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

void nvswitch_init_buffer_ready_lr10(long param_1,long param_2,char param_3)

{
  code *pcVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = *(undefined4 *)(param_2 + 0x38);
  if ((*(byte *)(param_1 + 0x54) & 1) == 0) {
    pcVar1 = *(code **)(param_1 + 0x910);
    uVar3 = nvswitch_get_link_eng_inst(param_1,uVar5,10);
    iVar4 = (*pcVar1)(param_1,10,0,uVar3,pcVar1);
    if (iVar4 == -1) {
LAB_001e4690:
      nvswitch_assert_log();
    }
    else {
      cVar2 = nvswitch_is_link_valid(param_1,uVar5);
      if (cVar2 == '\0') goto LAB_001e4690;
    }
    pcVar1 = *(code **)(param_1 + 0x928);
    uVar3 = nvswitch_get_link_eng_inst(param_1,uVar5,10);
    (*pcVar1)(param_1,10,0,uVar3,0x924,1);
    pcVar1 = *(code **)(param_1 + 0x910);
    uVar3 = nvswitch_get_link_eng_inst(param_1,uVar5,10);
    iVar4 = (*pcVar1)(param_1,10,0,uVar3,pcVar1);
    if (iVar4 == -1) {
LAB_001e4649:
      nvswitch_assert_log();
    }
    else {
      cVar2 = nvswitch_is_link_valid(param_1,uVar5);
      if (cVar2 == '\0') goto LAB_001e4649;
    }
    pcVar1 = *(code **)(param_1 + 0x928);
    uVar3 = nvswitch_get_link_eng_inst(param_1,uVar5,10);
    (*pcVar1)(param_1,10,0,uVar3,0x124,1);
  }
  if ((param_3 == '\0') || ((*(byte *)(param_1 + 0x54) & 2) != 0)) {
    return;
  }
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar3 = nvswitch_get_link_eng_inst(param_1,uVar5,5);
  iVar4 = (*pcVar1)(param_1,5,0,uVar3);
  if (iVar4 != -1) {
    cVar2 = nvswitch_is_link_valid(param_1,uVar5);
    if (cVar2 != '\0') goto LAB_001e46e1;
  }
  nvswitch_assert_log();
LAB_001e46e1:
  pcVar1 = *(code **)(param_1 + 0x928);
  uVar5 = nvswitch_get_link_eng_inst(param_1,uVar5,5);
  (*pcVar1)(param_1,5,0,uVar5,0x44,1);
  return;
}


// ===== 001e4730 nvswitch_corelib_add_link_lr10 =====

undefined8 nvswitch_corelib_add_link_lr10(void)

{
  return 0;
}


// ===== 001e4740 nvswitch_corelib_remove_link_lr10 =====

undefined8 nvswitch_corelib_remove_link_lr10(void)

{
  return 0;
}


// ===== 001e4750 nvswitch_corelib_get_dl_link_mode_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */

undefined8 nvswitch_corelib_get_dl_link_mode_lr10(long param_1,undefined8 *param_2)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  byte bVar4;
  undefined4 uVar5;
  int iVar6;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 200);
  *param_2 = 0;
  pcVar2 = *(code **)(lVar1 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
  iVar6 = (*pcVar2)(lVar1,0xb,0,uVar5);
  if ((iVar6 == -1) ||
     (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0')) {
    return 0xfffffff7;
  }
  cVar3 = nvswitch_is_link_in_reset(lVar1,param_1);
  if (cVar3 == '\0') {
    pcVar2 = *(code **)(lVar1 + 0x910);
    uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
    iVar6 = (*pcVar2)(lVar1,0xb,0,uVar5);
    if ((iVar6 == -1) ||
       (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar2 = *(code **)(lVar1 + 0x920);
    uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
    bVar4 = (*pcVar2)(lVar1,0xb,0,uVar5,0);
    if (bVar4 == 3) {
      *param_2 = 1;
    }
    else {
      if ((bVar4 & 0xfc) == 0) {
        if (bVar4 == 1) {
          *param_2 = 6;
          return 0;
        }
        if (bVar4 == 2) {
          *param_2 = 2;
          return 0;
        }
      }
      else {
        if ((bVar4 & 0xfd) == 8) {
          *param_2 = 4;
          return 0;
        }
        if (bVar4 == 4) {
          *param_2 = 3;
          return 0;
        }
      }
      *param_2 = 0;
    }
  }
  else {
    *param_2 = 7;
  }
  return 0;
}


// ===== 001e48f0 nvswitch_corelib_get_uphy_load_lr10 =====

void nvswitch_corelib_get_uphy_load_lr10(undefined8 param_1,undefined1 *param_2)

{
  *param_2 = 0;
  return;
}


// ===== 001e4900 nvswitch_corelib_get_tl_link_mode_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */

undefined8 nvswitch_corelib_get_tl_link_mode_lr10(long param_1,undefined8 *param_2)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 200);
  *param_2 = 0;
  pcVar2 = *(code **)(lVar1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
  iVar5 = (*pcVar2)(lVar1,0xb,0,uVar4);
  if ((iVar5 != -1) &&
     (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 != '\0')) {
    cVar3 = nvswitch_is_link_in_reset(lVar1,param_1);
    if (cVar3 == '\0') {
      pcVar2 = *(code **)(lVar1 + 0x910);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
      iVar5 = (*pcVar2)(lVar1,9,0,uVar4);
      if ((iVar5 == -1) ||
         (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x920);
      uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
      uVar6 = (*pcVar2)(lVar1,9,0,uVar4,0x484);
      uVar6 = uVar6 & 0xf;
      if (uVar6 == 2) {
        *param_2 = 10;
      }
      else if (uVar6 == 0xe) {
        *param_2 = 0x19;
      }
      else {
        if (uVar6 != 1) {
          return 8;
        }
        *param_2 = 1;
      }
    }
    else {
      *param_2 = 7;
    }
    return 0;
  }
  return 0xfffffff7;
}


// ===== 001e4a70 nvswitch_corelib_set_tx_mode_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */
/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */

undefined8 nvswitch_corelib_set_tx_mode_lr10(long param_1,ulong param_2)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  ulong uVar9;
  uint uVar10;
  undefined1 local_40 [16];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 200);
  pcVar2 = *(code **)(lVar1 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
  iVar6 = (*pcVar2)(lVar1,0xb,0,uVar5);
  if ((iVar6 == -1) ||
     (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0')) {
    return 0xfffffff7;
  }
  cVar3 = nvswitch_does_link_need_termination_enabled(lVar1,param_1);
  if (cVar3 != '\0') {
    return 0;
  }
  cVar3 = nvswitch_is_link_in_reset(lVar1,param_1);
  if (cVar3 != '\0') {
    return 0xfffffff8;
  }
  pcVar2 = *(code **)(lVar1 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
  iVar6 = (*pcVar2)(lVar1,0xb,0,uVar5);
  if ((iVar6 == -1) ||
     (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar2 = *(code **)(lVar1 + 0x920);
  uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
  uVar10 = (*pcVar2)(lVar1,0xb,0,uVar5,0x2024);
  uVar8 = nvswitch_poll_sublink_state(lVar1,param_1);
  if ((int)uVar8 != 0) {
    return uVar8;
  }
  if (param_2 == 8) {
    uVar8 = *(undefined8 *)(*(long *)(param_1 + 0x10) + 200);
    iVar6 = nvswitch_minion_send_command(uVar8,*(undefined4 *)(param_1 + 0x38),7,0);
    if (iVar6 != 0) {
      nvswitch_assert_log();
      return 0x76;
    }
    uVar5 = *(undefined4 *)(param_1 + 0x38);
    lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 200);
    if (*(char *)(lVar1 + 0x24) == '\0') {
      nvswitch_timeout_create(400000000,local_40);
      while( true ) {
        cVar3 = nvswitch_timeout_check(local_40);
        pcVar2 = *(code **)(lVar1 + 0x910);
        uVar7 = nvswitch_get_link_eng_inst(lVar1,uVar5,9);
        iVar6 = (*pcVar2)(lVar1,9,0,uVar7);
        if ((iVar6 == -1) || (cVar4 = nvswitch_is_link_valid(lVar1,uVar5), cVar4 == '\0')) {
          nvswitch_assert_log();
        }
        pcVar2 = *(code **)(lVar1 + 0x920);
        uVar7 = nvswitch_get_link_eng_inst(lVar1,uVar5,9);
        uVar9 = (*pcVar2)(lVar1,9,0,uVar7,0x90);
        if ((uVar9 & 0x2000000) != 0) break;
        nvswitch_os_sleep(1);
        if (cVar3 != '\0') {
          return 0x65;
        }
      }
      iVar6 = nvswitch_minion_send_command(lVar1,uVar5,0x14,0);
      if (iVar6 != 0) {
        nvswitch_assert_log();
        return 0x76;
      }
      nvswitch_timeout_create(400000000,local_40);
      while( true ) {
        cVar3 = nvswitch_timeout_check(local_40);
        pcVar2 = *(code **)(lVar1 + 0x910);
        uVar7 = nvswitch_get_link_eng_inst(lVar1,uVar5,9);
        iVar6 = (*pcVar2)(lVar1,9,0,uVar7);
        if ((iVar6 == -1) || (cVar4 = nvswitch_is_link_valid(lVar1,uVar5), cVar4 == '\0')) {
          nvswitch_assert_log();
        }
        pcVar2 = *(code **)(lVar1 + 0x920);
        uVar7 = nvswitch_get_link_eng_inst(lVar1,uVar5,9);
        uVar9 = (*pcVar2)(lVar1,9,0,uVar7,0x90);
        if ((uVar9 & 0x180000) == 0) break;
        nvswitch_os_sleep(1);
        if (cVar3 != '\0') {
          return 0x65;
        }
      }
      uVar5 = *(undefined4 *)(param_1 + 0x38);
    }
    uVar8 = nvswitch_minion_send_command(uVar8,uVar5,1,0);
    iVar6 = (int)uVar8;
  }
  else {
    if (param_2 < 9) {
      uVar10 = uVar10 >> 4 & 0xf;
      if (param_2 == 6) {
        if (uVar10 == 6) {
          return uVar8;
        }
        pcVar2 = *(code **)(lVar1 + 0x910);
        uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
        iVar6 = (*pcVar2)(lVar1,0xb,0,uVar5);
        if ((iVar6 == -1) ||
           (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0')) {
          nvswitch_assert_log();
        }
        pcVar2 = *(code **)(lVar1 + 0x920);
        uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
        uVar10 = (*pcVar2)(lVar1,0xb,0,uVar5,0x44);
        uVar10 = uVar10 & 0xffff0f03 | 100;
      }
      else {
        if (param_2 != 7) {
          return uVar8;
        }
        if (uVar10 == 7) {
          return uVar8;
        }
        if (uVar10 == 0) {
          return 0xfffffff9;
        }
        pcVar2 = *(code **)(lVar1 + 0x910);
        uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
        iVar6 = (*pcVar2)(lVar1,0xb,0,uVar5);
        if ((iVar6 == -1) ||
           (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0')) {
          nvswitch_assert_log();
        }
        pcVar2 = *(code **)(lVar1 + 0x920);
        uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
        uVar10 = (*pcVar2)(lVar1,0xb,0,uVar5,0x44);
        uVar10 = uVar10 & 0xf0f03 | 0x74;
      }
      pcVar2 = *(code **)(lVar1 + 0x910);
      uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
      iVar6 = (*pcVar2)(lVar1,0xb,0,uVar5);
      if ((iVar6 == -1) ||
         (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x928);
      uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
      (*pcVar2)(lVar1,0xb,0,uVar5,0x44,uVar10);
      uVar8 = nvswitch_poll_sublink_state(lVar1,param_1);
      return uVar8;
    }
    if (param_2 != 10) {
      return uVar8;
    }
    iVar6 = nvswitch_minion_send_command(lVar1,*(undefined4 *)(param_1 + 0x38),4,0);
    if (iVar6 != 0) goto LAB_001e4d56;
    uVar8 = nvswitch_minion_send_command(lVar1,*(undefined4 *)(param_1 + 0x38),3,0);
    iVar6 = (int)uVar8;
  }
  if (iVar6 == 0) {
    return uVar8;
  }
LAB_001e4d56:
  nvswitch_assert_log();
  return 0x74;
}


// ===== 001e5040 nvswitch_corelib_get_tx_mode_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */

undefined8 nvswitch_corelib_get_tx_mode_lr10(long param_1,undefined8 *param_2,undefined4 *param_3)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 200);
  *param_2 = 7;
  pcVar2 = *(code **)(lVar1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
  iVar5 = (*pcVar2)(lVar1,0xb,0,uVar4);
  if ((iVar5 == -1) ||
     (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0')) {
    return 0xfffffff7;
  }
  cVar3 = nvswitch_is_link_in_reset(lVar1,param_1);
  if (cVar3 == '\0') {
    pcVar2 = *(code **)(lVar1 + 0x910);
    uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
    iVar5 = (*pcVar2)(lVar1,0xb,0,uVar4);
    if ((iVar5 == -1) ||
       (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar2 = *(code **)(lVar1 + 0x920);
    uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
    uVar6 = (*pcVar2)(lVar1,0xb,0,uVar4,0x2024);
    *param_3 = 0;
    uVar6 = uVar6 >> 4 & 0xf;
    if (uVar6 == 5) {
      *param_2 = 5;
      return 0;
    }
    if (uVar6 < 6) {
      if (uVar6 == 0) {
        *param_2 = 0;
        return 0;
      }
      if (uVar6 == 4) {
        *param_2 = 4;
        return 0;
      }
    }
    else if (uVar6 == 6) {
      *param_2 = 6;
      return 0;
    }
  }
  *param_2 = 7;
  return 0;
}


// ===== 001e51e0 nvswitch_corelib_set_rx_mode_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

ulong nvswitch_corelib_set_rx_mode_lr10(long param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  undefined1 local_40 [16];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 200);
  cVar3 = nvswitch_is_tnvl_mode_locked(lVar1);
  if (cVar3 == '\0') {
    pcVar2 = *(code **)(lVar1 + 0x910);
    uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
    iVar5 = (*pcVar2)(lVar1,0xb,0,uVar4);
    if ((iVar5 == -1) ||
       (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0')) {
      uVar8 = 0xfffffff7;
    }
    else {
      uVar8 = 0;
      cVar3 = nvswitch_does_link_need_termination_enabled(lVar1,param_1);
      if (cVar3 == '\0') {
        cVar3 = nvswitch_is_link_in_reset(lVar1,param_1);
        if (cVar3 == '\0') {
          pcVar2 = *(code **)(lVar1 + 0x910);
          uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
          iVar5 = (*pcVar2)(lVar1,0xb,0,uVar4);
          if ((iVar5 == -1) ||
             (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0'))
          {
            nvswitch_assert_log();
          }
          pcVar2 = *(code **)(lVar1 + 0x920);
          uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
          uVar7 = (*pcVar2)(lVar1,0xb,0,uVar4,0x3014);
          uVar6 = nvswitch_poll_sublink_state(lVar1,param_1);
          uVar8 = (ulong)uVar6;
          if (uVar6 == 0) {
            if (param_2 == 8) {
              pcVar2 = *(code **)(lVar1 + 0x910);
              uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
              iVar5 = (*pcVar2)(lVar1,0xb,0,uVar4,pcVar2);
              if ((iVar5 == -1) ||
                 (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)),
                 cVar3 == '\0')) {
                nvswitch_assert_log();
              }
              pcVar2 = *(code **)(lVar1 + 0x920);
              uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
              uVar7 = (*pcVar2)(lVar1,0xb,0,uVar4,0x281c,pcVar2);
              pcVar2 = *(code **)(lVar1 + 0x910);
              uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
              iVar5 = (*pcVar2)(lVar1,0xb,0,uVar4,pcVar2);
              if ((iVar5 == -1) ||
                 (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)),
                 cVar3 == '\0')) {
                nvswitch_assert_log();
              }
              pcVar2 = *(code **)(lVar1 + 0x928);
              uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
              (*pcVar2)(lVar1,0xb,0,uVar4,0x281c,uVar7 | 1);
              if (*(char *)(lVar1 + 0x26) == '\0') {
                lVar10 = 1000000000;
                if (*(char *)(lVar1 + 0x24) == '\0') {
                  lVar10 = (-(ulong)(*(char *)(lVar1 + 0x25) == '\0') & 0xffffffffc4684340) +
                           1000000000;
                }
                nvswitch_timeout_create(lVar10,local_40);
                do {
                  cVar3 = nvswitch_timeout_check(local_40);
                } while (cVar3 == '\0');
              }
              pcVar2 = *(code **)(lVar1 + 0x910);
              uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
              iVar5 = (*pcVar2)(lVar1,0xb,0,uVar4,pcVar2);
              if ((iVar5 == -1) ||
                 (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)),
                 cVar3 == '\0')) {
                nvswitch_assert_log();
              }
              pcVar2 = *(code **)(lVar1 + 0x920);
              uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
              uVar9 = (*pcVar2)(lVar1,0xb,0,uVar4,0x2838,pcVar2);
              if ((uVar9 & 4) == 0) {
                uVar8 = 0xfffffff9;
              }
            }
            else {
              if (param_2 == 9) {
                uVar8 = nvswitch_minion_set_rx_term_lr10(lVar1,*(undefined4 *)(param_1 + 0x38));
                return uVar8;
              }
              if ((param_2 == 7) && (uVar7 = uVar7 >> 4 & 0xf, uVar7 != 7)) {
                if (uVar7 != 0) {
                  pcVar2 = *(code **)(lVar1 + 0x910);
                  uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
                  iVar5 = (*pcVar2)(lVar1,0xb,0,uVar4);
                  if ((iVar5 == -1) ||
                     (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)),
                     cVar3 == '\0')) {
                    nvswitch_assert_log();
                  }
                  pcVar2 = *(code **)(lVar1 + 0x920);
                  uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
                  uVar7 = (*pcVar2)(lVar1,0xb,0,uVar4,0x44);
                  pcVar2 = *(code **)(lVar1 + 0x910);
                  uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
                  iVar5 = (*pcVar2)(lVar1,0xb,0,uVar4);
                  if ((iVar5 == -1) ||
                     (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)),
                     cVar3 == '\0')) {
                    nvswitch_assert_log();
                  }
                  pcVar2 = *(code **)(lVar1 + 0x928);
                  uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
                  (*pcVar2)(lVar1,0xb,0,uVar4,0x44,uVar7 & 0xf0f0f | 0xf107c);
                  uVar8 = nvswitch_poll_sublink_state(lVar1,param_1);
                  return uVar8;
                }
                uVar8 = 0xfffffff9;
              }
            }
          }
        }
        else {
          uVar8 = 0xfffffff8;
        }
      }
    }
  }
  else {
    uVar8 = 0xf;
  }
  return uVar8;
}


// ===== 001e5700 nvswitch_corelib_get_rx_mode_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */

undefined8 nvswitch_corelib_get_rx_mode_lr10(long param_1,undefined8 *param_2,undefined4 *param_3)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 200);
  *param_2 = 7;
  pcVar2 = *(code **)(lVar1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
  iVar5 = (*pcVar2)(lVar1,0xb,0,uVar4);
  if ((iVar5 == -1) ||
     (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0')) {
    return 0xfffffff7;
  }
  cVar3 = nvswitch_is_link_in_reset(lVar1,param_1);
  if (cVar3 == '\0') {
    pcVar2 = *(code **)(lVar1 + 0x910);
    uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
    iVar5 = (*pcVar2)(lVar1,0xb,0,uVar4);
    if ((iVar5 == -1) ||
       (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0')) {
      nvswitch_assert_log();
    }
    pcVar2 = *(code **)(lVar1 + 0x920);
    uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
    uVar6 = (*pcVar2)(lVar1,0xb,0,uVar4,0x3014);
    *param_3 = 0;
    uVar6 = uVar6 >> 4 & 0xf;
    if (uVar6 == 5) {
      *param_2 = 5;
      return 0;
    }
    if (uVar6 < 6) {
      if (uVar6 == 0) {
        *param_2 = 0;
        return 0;
      }
      if (uVar6 == 4) {
        *param_2 = 4;
        return 0;
      }
    }
    else if (uVar6 == 6) {
      *param_2 = 6;
      return 0;
    }
  }
  *param_2 = 7;
  return 0;
}


// ===== 001e58a0 nvswitch_corelib_set_rx_detect_lr10 =====

undefined8 nvswitch_corelib_set_rx_detect_lr10(long param_1)

{
  char cVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x10) + 200);
  cVar1 = nvswitch_is_tnvl_mode_locked(uVar2);
  if (cVar1 != '\0') {
    return 0xf;
  }
  cVar1 = nvswitch_does_link_need_termination_enabled(uVar2,param_1);
  if (cVar1 != '\0') {
    return 0;
  }
  uVar2 = nvswitch_minion_send_command(uVar2,*(undefined4 *)(param_1 + 0x38),0x58,0);
  return uVar2;
}


// ===== 001e5910 nvswitch_corelib_get_rx_detect_lr10 =====

void nvswitch_corelib_get_rx_detect_lr10(long param_1)

{
  nvswitch_minion_get_rxdet_status_lr10
            (*(undefined8 *)(*(long *)(param_1 + 0x10) + 200),*(undefined4 *)(param_1 + 0x38));
  return;
}


// ===== 001e5930 nvswitch_corelib_training_complete_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r15 replaced with injection: x86_indirect_thunk_r15 */

void nvswitch_corelib_training_complete_lr10(long param_1)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 200);
  nvswitch_init_dlpl_interrupts();
  uVar7 = *(undefined4 *)(param_1 + 0x38);
  lVar2 = *(long *)(*(long *)(param_1 + 0x10) + 200);
  pcVar3 = *(code **)(lVar2 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar7,10);
  iVar6 = (*pcVar3)(lVar2,10,0,uVar5);
  if (iVar6 == -1) goto LAB_001e59a4;
  cVar4 = nvswitch_is_link_valid(lVar2,*(undefined4 *)(param_1 + 0x38));
  if (cVar4 == '\0') goto LAB_001e59a4;
  pcVar3 = *(code **)(lVar2 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar7,10);
  iVar6 = (*pcVar3)(lVar2,10,0,uVar5);
  if (iVar6 == -1) {
LAB_001e5cf0:
    nvswitch_assert_log();
  }
  else {
    cVar4 = nvswitch_is_link_valid(lVar2,uVar7);
    if (cVar4 == '\0') goto LAB_001e5cf0;
  }
  pcVar3 = *(code **)(lVar2 + 0x928);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar7,10);
  (*pcVar3)(lVar2,10,0,uVar5,0x1d0c,0x344);
  pcVar3 = *(code **)(lVar2 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar7,10);
  iVar6 = (*pcVar3)(lVar2,10,0,uVar5);
  if (iVar6 == -1) {
LAB_001e5ce0:
    nvswitch_assert_log();
  }
  else {
    cVar4 = nvswitch_is_link_valid(lVar2,uVar7);
    if (cVar4 == '\0') goto LAB_001e5ce0;
  }
  pcVar3 = *(code **)(lVar2 + 0x928);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar7,10);
  (*pcVar3)(lVar2,10,0,uVar5,0x150c,0x344);
  pcVar3 = *(code **)(lVar2 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar7,10);
  iVar6 = (*pcVar3)(lVar2,10,0,uVar5);
  if (iVar6 == -1) {
LAB_001e5cd0:
    nvswitch_assert_log();
  }
  else {
    cVar4 = nvswitch_is_link_valid(lVar2,uVar7);
    if (cVar4 == '\0') goto LAB_001e5cd0;
  }
  pcVar3 = *(code **)(lVar2 + 0x928);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar7,10);
  (*pcVar3)(lVar2,10,0,uVar5,0x1db4,0x37c);
  pcVar3 = *(code **)(lVar2 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar7,10);
  iVar6 = (*pcVar3)(lVar2,10,0,uVar5);
  if (iVar6 == -1) {
LAB_001e5cc0:
    nvswitch_assert_log();
  }
  else {
    cVar4 = nvswitch_is_link_valid(lVar2,uVar7);
    if (cVar4 == '\0') goto LAB_001e5cc0;
  }
  pcVar3 = *(code **)(lVar2 + 0x928);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar7,10);
  (*pcVar3)(lVar2,10,0,uVar5,0x15b4,0x37c);
  pcVar3 = *(code **)(lVar2 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar7,10);
  iVar6 = (*pcVar3)(lVar2,10,0,uVar5);
  if (iVar6 == -1) {
LAB_001e5cb0:
    nvswitch_assert_log();
  }
  else {
    cVar4 = nvswitch_is_link_valid(lVar2,uVar7);
    if (cVar4 == '\0') goto LAB_001e5cb0;
  }
  pcVar3 = *(code **)(lVar2 + 0x928);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar7,10);
  (*pcVar3)(lVar2,10,0,uVar5,0x1d08,5);
  pcVar3 = *(code **)(lVar2 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(lVar2,uVar7,10);
  iVar6 = (*pcVar3)(lVar2,10,0,uVar5);
  if (iVar6 == -1) {
LAB_001e5c6c:
    nvswitch_assert_log();
  }
  else {
    cVar4 = nvswitch_is_link_valid(lVar2,uVar7);
    if (cVar4 == '\0') goto LAB_001e5c6c;
  }
  pcVar3 = *(code **)(lVar2 + 0x928);
  uVar7 = nvswitch_get_link_eng_inst(lVar2,uVar7,10);
  (*pcVar3)(lVar2,10,0,uVar7,0x1508,5);
LAB_001e59a4:
  nvswitch_lib_notify_client_events(lVar1,2);
  nvswitch_record_port_event(lVar1,lVar1 + 0x148,*(undefined4 *)(param_1 + 0x38),0);
  return;
}


// ===== 001e5d00 nvswitch_wait_for_tl_request_ready_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */

undefined8 nvswitch_wait_for_tl_request_ready_lr10(long param_1)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 local_30 [8];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 200);
  pcVar2 = *(code **)(lVar1 + 0x910);
  uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
  iVar6 = (*pcVar2)(lVar1,9,0,uVar5);
  if ((iVar6 != -1) &&
     (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 != '\0')) {
    nvswitch_timeout_create(400000000,local_30);
    while( true ) {
      cVar3 = nvswitch_timeout_check(local_30);
      pcVar2 = *(code **)(lVar1 + 0x910);
      uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
      iVar6 = (*pcVar2)(lVar1,9,0,uVar5);
      if ((iVar6 == -1) ||
         (cVar4 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar4 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x920);
      uVar5 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
      iVar6 = (*pcVar2)(lVar1,9,0,uVar5,0x480);
      if (iVar6 < 0) break;
      nvswitch_os_sleep(1);
      if (cVar3 != '\0') {
        return 0xfffffff9;
      }
    }
    return 0;
  }
  return 0xffffffff;
}


// ===== 001e5e50 nvswitch_request_tl_link_state_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

int nvswitch_request_tl_link_state_lr10(long param_1,uint param_2,char param_3)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 200);
  cVar3 = nvswitch_is_tnvl_mode_locked(lVar1);
  iVar7 = 0xf;
  if (cVar3 == '\0') {
    pcVar2 = *(code **)(lVar1 + 0x910);
    uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
    iVar7 = (*pcVar2)(lVar1,9,0,uVar4);
    if ((iVar7 == -1) ||
       (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0')) {
      iVar7 = -9;
    }
    else {
      iVar5 = nvswitch_wait_for_tl_request_ready_lr10(param_1);
      iVar7 = iVar5;
      if (iVar5 == 0) {
        pcVar2 = *(code **)(lVar1 + 0x910);
        uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
        iVar6 = (*pcVar2)(lVar1,9,0,uVar4,pcVar2);
        if ((iVar6 == -1) ||
           (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0')) {
          nvswitch_assert_log();
        }
        pcVar2 = *(code **)(lVar1 + 0x928);
        uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
        (*pcVar2)(lVar1,9,0,uVar4,0x480,param_2 & 0xf);
        if ((param_3 != '\0') &&
           (iVar7 = nvswitch_wait_for_tl_request_ready_lr10(param_1), iVar7 == 0)) {
          pcVar2 = *(code **)(lVar1 + 0x910);
          uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
          iVar7 = (*pcVar2)(lVar1,9,0,uVar4,pcVar2);
          if ((iVar7 == -1) ||
             (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 == '\0'))
          {
            nvswitch_assert_log();
          }
          pcVar2 = *(code **)(lVar1 + 0x920);
          uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),9);
          uVar8 = (*pcVar2)(lVar1,9,0,uVar4,0x484,pcVar2);
          iVar7 = iVar5;
          if ((uVar8 & 0xf) != param_2) {
            iVar7 = -7;
          }
        }
      }
    }
  }
  return iVar7;
}


// ===== 001e6060 nvswitch_corelib_set_dl_link_mode_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */
/* WARNING: Function: __x86_indirect_thunk_r12 replaced with injection: x86_indirect_thunk_r12 */
/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */

ulong nvswitch_corelib_set_dl_link_mode_lr10(long param_1,ulong param_2,int param_3)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  char cVar4;
  byte bVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  ulong uVar9;
  undefined8 uVar10;
  uint uVar11;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 200);
  pcVar2 = *(code **)(lVar1 + 0x910);
  uVar6 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
  iVar8 = (*pcVar2)(lVar1,0xb,0,uVar6);
  if ((iVar8 == -1) ||
     (cVar4 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar4 == '\0')) {
    return 0xfffffff7;
  }
  cVar4 = nvswitch_does_link_need_termination_enabled(lVar1,param_1);
  if (cVar4 != '\0') {
    if (param_2 != 0x13) {
      return 0;
    }
    nvswitch_link_termination_setup(lVar1,param_1);
    return 0;
  }
  if (param_2 == 0x11) {
    uVar6 = *(undefined4 *)(param_1 + 0x38);
    uVar10 = 0xc;
    goto LAB_001e6132;
  }
  if (param_2 < 0x12) {
    if (param_2 == 8) {
      if (*(int *)(lVar1 + 0x58) == 1) {
        uVar6 = *(undefined4 *)(param_1 + 0x38);
        uVar10 = 0x10;
        goto LAB_001e6132;
      }
    }
    else if (param_2 < 9) {
      if (param_2 == 1) {
        cVar4 = nvswitch_is_link_in_reset(lVar1,param_1);
        if (cVar4 != '\0') {
          return 0xfffffff8;
        }
        pcVar2 = *(code **)(lVar1 + 0x910);
        uVar6 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
        iVar8 = (*pcVar2)(lVar1,0xb,0,uVar6);
        if ((iVar8 == -1) ||
           (cVar4 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar4 == '\0')) {
          nvswitch_assert_log();
        }
        pcVar2 = *(code **)(lVar1 + 0x920);
        uVar6 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
        cVar4 = (*pcVar2)(lVar1,0xb,0,uVar6,0);
        if (cVar4 == '\x03') {
          return 0;
        }
        if (cVar4 != '\x02') {
          return 0xfffffff8;
        }
        pcVar2 = *(code **)(lVar1 + 0x910);
        uVar6 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
        iVar8 = (*pcVar2)(lVar1,0xb,0,uVar6);
        if ((iVar8 == -1) ||
           (cVar4 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar4 == '\0')) {
          nvswitch_assert_log();
        }
        pcVar2 = *(code **)(lVar1 + 0x920);
        uVar6 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
        uVar11 = (*pcVar2)(lVar1,0xb,0,uVar6,0x40);
        uVar11 = uVar11 & 0xffffff03 | 0xf0034;
      }
      else {
        if (param_2 != 2) {
          if (param_2 != 0) {
            return 0;
          }
          lVar3 = *(long *)(*(long *)(param_1 + 0x10) + 200);
          if (*(char *)(lVar3 + 0x24) == '\0') {
            nvswitch_minion_send_command(lVar3,*(undefined4 *)(param_1 + 0x38),0x15,0);
          }
          nvswitch_lib_notify_client_events(lVar1,3);
          nvswitch_record_port_event(lVar1,lVar1 + 0x148,*(undefined4 *)(param_1 + 0x38),1);
          return 0;
        }
        cVar4 = nvswitch_is_link_in_reset(lVar1,param_1);
        if (cVar4 != '\0') {
          return 8;
        }
        pcVar2 = *(code **)(lVar1 + 0x910);
        uVar6 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
        iVar8 = (*pcVar2)(lVar1,0xb,0,uVar6);
        if ((iVar8 == -1) ||
           (cVar4 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar4 == '\0')) {
          nvswitch_assert_log();
        }
        pcVar2 = *(code **)(lVar1 + 0x920);
        uVar6 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
        bVar5 = (*pcVar2)(lVar1,0xb,0,uVar6,0);
        if (bVar5 - 1 < 2) {
          return 0;
        }
        if (bVar5 == 0) {
          pcVar2 = *(code **)(lVar1 + 0x910);
          uVar6 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
          iVar8 = (*pcVar2)(lVar1,0xb,0,uVar6);
          if ((iVar8 == -1) ||
             (cVar4 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar4 == '\0'))
          {
            nvswitch_assert_log();
          }
          pcVar2 = *(code **)(lVar1 + 0x920);
          uVar6 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
          uVar11 = (*pcVar2)(lVar1,0xb,0,uVar6,0x40);
          uVar11 = uVar11 & 0xffffff03 | 0xf0014;
        }
        else {
          if (bVar5 != 3) {
            return 0xfffffff8;
          }
          pcVar2 = *(code **)(lVar1 + 0x910);
          uVar6 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
          iVar8 = (*pcVar2)(lVar1,0xb,0,uVar6);
          if ((iVar8 == -1) ||
             (cVar4 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar4 == '\0'))
          {
            nvswitch_assert_log();
          }
          pcVar2 = *(code **)(lVar1 + 0x920);
          uVar6 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
          uVar11 = (*pcVar2)(lVar1,0xb,0,uVar6,0x40);
          uVar11 = uVar11 & 0xffffff03 | 0xf0024;
        }
      }
      pcVar2 = *(code **)(lVar1 + 0x910);
      uVar6 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
      iVar8 = (*pcVar2)(lVar1,0xb,0,uVar6);
      if ((iVar8 == -1) ||
         (cVar4 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar4 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x928);
      uVar6 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
      (*pcVar2)(lVar1,0xb,0,uVar6,0x40,uVar11);
    }
    else {
      if (param_2 != 0xf) {
        if (param_2 == 0x10) {
          uVar6 = *(undefined4 *)(param_1 + 0x38);
          uVar10 = 8;
        }
        else {
          if (param_2 != 9) {
            return 0;
          }
          if (*(int *)(lVar1 + 0x58) != 1) {
            return 0;
          }
          uVar6 = *(undefined4 *)(param_1 + 0x38);
          uVar10 = 0x11;
        }
        goto LAB_001e6132;
      }
      uVar6 = *(undefined4 *)(param_1 + 0x38);
      lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 200);
      pcVar2 = *(code **)(lVar1 + 0x910);
      uVar7 = nvswitch_get_link_eng_inst(lVar1,uVar6,0xb);
      iVar8 = (*pcVar2)(lVar1,0xb,0,uVar7);
      if ((iVar8 == -1) || (cVar4 = nvswitch_is_link_valid(lVar1,uVar6), cVar4 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x928);
      uVar7 = nvswitch_get_link_eng_inst(lVar1,uVar6,0xb);
      (*pcVar2)(lVar1,0xb,0,uVar7,0x58,0);
      pcVar2 = *(code **)(lVar1 + 0x910);
      uVar7 = nvswitch_get_link_eng_inst(lVar1,uVar6,0xb);
      iVar8 = (*pcVar2)(lVar1,0xb,0,uVar7);
      if ((iVar8 == -1) || (cVar4 = nvswitch_is_link_valid(lVar1,uVar6), cVar4 == '\0')) {
        nvswitch_assert_log();
      }
      pcVar2 = *(code **)(lVar1 + 0x928);
      uVar6 = nvswitch_get_link_eng_inst(lVar1,uVar6,0xb);
      (*pcVar2)(lVar1,0xb,0,uVar6,0x5c,0);
    }
    return 0;
  }
  if (param_2 != 0x15) {
    if (param_2 < 0x16) {
      if (param_2 == 0x13) {
        iVar8 = nvswitch_minion_send_command(lVar1,*(undefined4 *)(param_1 + 0x38),0xd,0);
        if (iVar8 == 0) {
          nvswitch_setup_link_loopback_mode(lVar1,*(undefined4 *)(param_1 + 0x38));
          return 0;
        }
        goto LAB_001e6778;
      }
      if (param_2 != 0x14) {
        uVar10 = *(undefined8 *)(*(long *)(param_1 + 0x10) + 200);
        nvswitch_init_lpwr_regs(param_1);
        uVar9 = nvswitch_request_tl_link_state_lr10(param_1,1,param_3 == 1);
        if ((int)uVar9 == 0) {
          nvswitch_init_buffer_ready(uVar10,param_1,1);
          return uVar9 & 0xffffffff;
        }
        return uVar9;
      }
      uVar6 = *(undefined4 *)(param_1 + 0x38);
      uVar10 = 0xe;
    }
    else {
      if (param_2 != 0x16) {
        if (param_2 != 0x17) {
          return 0;
        }
        iVar8 = nvswitch_minion_get_initoptimize_status_lr10(lVar1,*(undefined4 *)(param_1 + 0x38));
        if ((iVar8 == 0) &&
           (uVar9 = nvswitch_minion_send_command(lVar1,*(undefined4 *)(param_1 + 0x38),6,0),
           (int)uVar9 == 0)) {
          return uVar9;
        }
        nvswitch_assert_log();
        return 0x77;
      }
      uVar6 = *(undefined4 *)(param_1 + 0x38);
      uVar10 = 0xf;
    }
LAB_001e6132:
    uVar9 = nvswitch_minion_send_command(lVar1,uVar6,uVar10,0);
    return uVar9;
  }
  iVar8 = nvswitch_minion_get_initnegotiate_status_lr10(lVar1,*(undefined4 *)(param_1 + 0x38));
  if (iVar8 == 0) {
    nvswitch_store_topology_information(lVar1,param_1);
    return 0;
  }
LAB_001e6778:
  nvswitch_assert_log();
  return 0x78;
}


// ===== 001e6820 nvswitch_corelib_set_tl_link_mode_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */

undefined8 nvswitch_corelib_set_tl_link_mode_lr10(long param_1,long param_2,int param_3)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 uVar6;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 200);
  cVar3 = nvswitch_is_tnvl_mode_locked(lVar1);
  if (cVar3 == '\0') {
    pcVar2 = *(code **)(lVar1 + 0x910);
    uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
    iVar5 = (*pcVar2)(lVar1,0xb,0,uVar4);
    if ((iVar5 != -1) &&
       (cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38)), cVar3 != '\0')) {
      cVar3 = nvswitch_does_link_need_termination_enabled(lVar1,param_1);
      if ((param_2 == 7) && (cVar3 == '\0')) {
        uVar6 = nvswitch_request_tl_link_state_lr10(param_1,9,param_3 == 1);
        return uVar6;
      }
      return 0;
    }
    uVar6 = 0xfffffff7;
  }
  else {
    uVar6 = 0xf;
  }
  return uVar6;
}


// ===== 001e6920 nvswitch_execute_unilateral_link_shutdown_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */

void nvswitch_execute_unilateral_link_shutdown_lr10(long param_1)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 200);
  pcVar2 = *(code **)(lVar1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(lVar1,*(undefined4 *)(param_1 + 0x38),0xb);
  iVar5 = (*pcVar2)(lVar1,0xb,0,uVar4);
  if (iVar5 != -1) {
    cVar3 = nvswitch_is_link_valid(lVar1,*(undefined4 *)(param_1 + 0x38));
    if (cVar3 != '\0') {
      nvswitch_corelib_set_dl_link_mode_lr10(param_1,9,0);
      nvswitch_corelib_set_dl_link_mode_lr10(param_1,0xf,0);
      nvswitch_corelib_set_dl_link_mode_lr10(param_1,0x10,0);
      nvswitch_corelib_set_dl_link_mode_lr10(param_1,0,0);
      return;
    }
  }
  return;
}


// ===== 001e69e0 nvswitch_setup_link_system_registers_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r12 replaced with injection: x86_indirect_thunk_r12 */
/* WARNING: Function: __x86_indirect_thunk_r15 replaced with injection: x86_indirect_thunk_r15 */
/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */

void nvswitch_setup_link_system_registers_lr10(long param_1,long param_2)

{
  byte bVar1;
  code *pcVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  
  pbVar7 = (byte *)nvswitch_get_bios_nvlink_config();
  if (pbVar7 != (byte *)0x0) {
    if (*(int *)(pbVar7 + 0x1e48) == 0) {
      pbVar7 = (byte *)0x0;
    }
    else {
      pbVar7 = pbVar7 + (ulong)*(uint *)(pbVar7 + 0x1e3c) * 0x280 + 0xc +
                        (ulong)*(uint *)(param_2 + 0x38) * 10;
    }
  }
  pcVar2 = *(code **)(param_1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(param_1,(ulong)*(uint *)(param_2 + 0x38),9);
  iVar5 = (*pcVar2)(param_1,9,0,uVar4);
  if ((iVar5 == -1) ||
     (cVar3 = nvswitch_is_link_valid(param_1,*(undefined4 *)(param_2 + 0x38)), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar2 = *(code **)(param_1 + 0x920);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  uVar12 = (*pcVar2)(param_1,9,0,uVar4,0x60c);
  if (*(int *)(param_1 + 0x8c) != 0) {
    uVar6 = *(int *)(param_1 + 0x8c) - 1;
    uVar8 = 0xff00;
    if (uVar6 < 0x11) {
      uVar8 = *(int *)(CSWTCH_4 + (ulong)uVar6 * 4) << 8;
    }
    uVar12 = uVar12 & 0xffff00ff | uVar8;
  }
  if (*(uint *)(param_1 + 0xe0) == 0) {
    if (pbVar7 != (byte *)0x0) {
      uVar12 = uVar12 & 0xfffffffc | pbVar7[3] & 3;
    }
  }
  else {
    uVar12 = uVar12 & 0xfffffffc | *(uint *)(param_1 + 0xe0) & 3;
  }
  pcVar2 = *(code **)(param_1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  iVar5 = (*pcVar2)(param_1,9,0,uVar4);
  if ((iVar5 == -1) ||
     (cVar3 = nvswitch_is_link_valid(param_1,*(undefined4 *)(param_2 + 0x38)), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar2 = *(code **)(param_1 + 0x928);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  (*pcVar2)(param_1,9,0,uVar4,0x60c,uVar12);
  pcVar2 = *(code **)(param_1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  iVar5 = (*pcVar2)(param_1,9,0,uVar4);
  if ((iVar5 == -1) ||
     (cVar3 = nvswitch_is_link_valid(param_1,*(undefined4 *)(param_2 + 0x38)), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar2 = *(code **)(param_1 + 0x920);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  uVar6 = (*pcVar2)(param_1,9,0,uVar4,0x618);
  uVar12 = *(uint *)(param_1 + 0x2c);
  uVar10 = uVar12 >> 3 & 0xff;
  uVar8 = uVar12 >> 0x10 & 0xf;
  uVar9 = uVar12 >> 0xb & 0x1f;
  if ((uVar12 & 7) == 0) {
    if (pbVar7 != (byte *)0x0) {
      bVar1 = pbVar7[5];
      uVar11 = (uint)(bVar1 >> 5) << 8;
      uVar13 = uVar6 & 0xfffff8ff | uVar11;
      if (uVar10 == 0) goto LAB_001e6f71;
      uVar10 = uVar10 << 0xb;
      uVar14 = uVar6 & 0xfff800ff | uVar11 | uVar10;
      if (uVar9 == 0) goto LAB_001e6ffe;
      uVar9 = uVar9 << 0x13;
      uVar15 = uVar6 & 0xff0000ff | uVar11 | uVar10 | uVar9;
      if ((uVar12 & 0xf0000) == 0) goto LAB_001e6c40;
      uVar16 = uVar6 & 0xf00000ff | uVar11 | uVar10 | uVar9 | uVar8 << 0x18;
      if ((uVar12 >> 0x14 & 0xf) == 0) goto LAB_001e70d0;
      uVar16 = uVar6 & 0xff | uVar11 | uVar10 | uVar9 | uVar8 << 0x18 | (uVar12 >> 0x14) << 0x1c;
      if (*(char *)(param_2 + 0x68) != '\0') goto LAB_001e704c;
LAB_001e6ee0:
      uVar16 = uVar16 & 0xfffffffe | *pbVar7 >> 2 & 1;
      uVar12 = *(uint *)(param_1 + 0xdc);
      goto joined_r0x001e6ef9;
    }
    if ((uVar12 & 0x7f8) == 0) {
      uVar15 = uVar6;
      if ((uVar12 & 0xf800) == 0) goto LAB_001e717d;
      uVar15 = uVar6 & 0xff07ffff | uVar9 << 0x13;
      if (uVar8 != 0) {
        uVar16 = uVar6 & 0xf007ffff | uVar9 << 0x13 | uVar8 << 0x18;
        uVar12 = uVar12 >> 0x14 & 0xf;
        if (uVar12 == 0) goto LAB_001e7199;
        goto LAB_001e7230;
      }
LAB_001e71c0:
      uVar16 = uVar15;
      if ((uVar12 >> 0x14 & 0xf) == 0) {
LAB_001e7199:
        if (*(char *)(param_2 + 0x68) != '\0') {
          uVar12 = *(uint *)(param_1 + 0xdc);
          goto joined_r0x001e71ac;
        }
      }
      else {
        uVar16 = uVar15 & 0xfffffff | (uVar12 >> 0x14) << 0x1c;
        if (*(char *)(param_2 + 0x68) != '\0') goto LAB_001e71dc;
      }
LAB_001e7160:
      uVar12 = *(uint *)(param_1 + 0xdc);
    }
    else {
      uVar15 = uVar6 & 0xfff807ff | uVar10 << 0xb;
      if (uVar9 != 0) {
        uVar15 = uVar6 & 0xff0007ff | uVar10 << 0xb | uVar9 << 0x13;
        if (uVar8 != 0) goto LAB_001e70a5;
        goto LAB_001e71c0;
      }
LAB_001e717d:
      if (uVar8 == 0) goto LAB_001e71c0;
      uVar16 = uVar15 & 0xf0ffffff | uVar8 << 0x18;
      if ((uVar12 & 0xf00000) == 0) goto LAB_001e7199;
      uVar16 = uVar15 & 0xffffff | uVar8 << 0x18 | (uVar12 >> 0x14) << 0x1c;
      if (*(char *)(param_2 + 0x68) == '\0') goto LAB_001e7160;
LAB_001e71dc:
      uVar12 = *(uint *)(param_1 + 0xdc);
joined_r0x001e71ac:
      uVar16 = uVar16 | 1;
    }
    if (uVar12 == 0) goto LAB_001e6c9d;
LAB_001e6c90:
    uVar16 = uVar16 & 0xffffff3f | (uVar12 & 3) << 6;
  }
  else {
    uVar11 = (uVar12 & 7) << 8;
    uVar13 = uVar6 & 0xfffff8ff | uVar11;
    if (uVar10 == 0) {
      if (pbVar7 != (byte *)0x0) {
LAB_001e6f71:
        uVar6 = (uint)pbVar7[4] << 0xb;
        uVar14 = uVar13 & 0xfff807ff | uVar6;
        if (uVar9 == 0) goto LAB_001e6ff9;
        uVar9 = uVar9 << 0x13;
        uVar15 = uVar13 & 0xff0007ff | uVar6 | uVar9;
        if (uVar8 == 0) goto LAB_001e6c40;
        uVar16 = uVar13 & 0xf00007ff | uVar6 | uVar9 | uVar8 << 0x18;
        if ((uVar12 & 0xf00000) == 0) goto LAB_001e70d0;
        uVar16 = uVar13 & 0x7ff | uVar6 | uVar9 | uVar8 << 0x18 | (uVar12 >> 0x14) << 0x1c;
        if (*(char *)(param_2 + 0x68) == '\0') goto LAB_001e6ee0;
        uVar12 = *(uint *)(param_1 + 0xdc);
        goto joined_r0x001e6fdb;
      }
      uVar15 = uVar13;
      if (uVar9 == 0) goto LAB_001e717d;
      uVar9 = uVar9 << 0x13;
      uVar15 = uVar6 & 0xff07f8ff | uVar11 | uVar9;
      if (uVar8 == 0) goto LAB_001e71c0;
      uVar16 = uVar6 & 0xf007f8ff | uVar11 | uVar9 | uVar8 << 0x18;
      if ((uVar12 >> 0x14 & 0xf) == 0) goto LAB_001e7199;
      uVar16 = uVar6 & 0x7f8ff | uVar11 | uVar9 | uVar8 << 0x18 | (uVar12 >> 0x14) << 0x1c;
      if (*(char *)(param_2 + 0x68) == '\0') goto LAB_001e7160;
LAB_001e704c:
      uVar12 = *(uint *)(param_1 + 0xdc);
      uVar16 = uVar16 | 1;
      if (uVar12 != 0) goto LAB_001e6c90;
      if (pbVar7 == (byte *)0x0) goto LAB_001e6c9d;
    }
    else {
      uVar14 = uVar6 & 0xfff800ff | uVar11 | uVar10 << 0xb;
      if (uVar9 == 0) {
        uVar15 = uVar14;
        if (pbVar7 == (byte *)0x0) goto LAB_001e717d;
LAB_001e6ff9:
        bVar1 = pbVar7[5];
LAB_001e6ffe:
        uVar6 = (bVar1 & 0x1f) << 0x13;
        uVar15 = uVar14 & 0xff07ffff | uVar6;
        if (uVar8 == 0) goto LAB_001e6c40;
        uVar16 = uVar14 & 0xf007ffff | uVar6 | uVar8 << 0x18;
        if ((uVar12 & 0xf00000) != 0) {
          uVar16 = uVar14 & 0x7ffff | uVar6 | uVar8 << 0x18 | (uVar12 >> 0x14) << 0x1c;
          if (*(char *)(param_2 + 0x68) == '\0') goto LAB_001e6ee0;
          goto LAB_001e704c;
        }
LAB_001e70d0:
        bVar1 = pbVar7[6];
      }
      else {
        uVar15 = uVar6 & 0xff0000ff | uVar11 | uVar10 << 0xb | uVar9 << 0x13;
        if (uVar8 != 0) {
LAB_001e70a5:
          uVar16 = uVar15 & 0xf0ffffff | uVar8 << 0x18;
          uVar12 = uVar12 >> 0x14 & 0xf;
          if (uVar12 != 0) {
LAB_001e7230:
            uVar16 = uVar16 & 0xfffffff | uVar12 << 0x1c;
            if (*(char *)(param_2 + 0x68) != '\0') goto LAB_001e704c;
            if (pbVar7 != (byte *)0x0) goto LAB_001e6ee0;
            goto LAB_001e7160;
          }
          if (pbVar7 != (byte *)0x0) goto LAB_001e70d0;
          goto LAB_001e7199;
        }
        if (pbVar7 == (byte *)0x0) goto LAB_001e71c0;
LAB_001e6c40:
        bVar1 = pbVar7[6];
        uVar6 = (bVar1 & 0xf) << 0x18;
        uVar16 = uVar15 & 0xf0ffffff | uVar6;
        if ((uVar12 >> 0x14 & 0xf) != 0) {
          uVar16 = uVar15 & 0xffffff | uVar6 | (uVar12 >> 0x14) << 0x1c;
          if (*(char *)(param_2 + 0x68) == '\0') goto LAB_001e6ee0;
          uVar12 = *(uint *)(param_1 + 0xdc);
          goto joined_r0x001e6fdb;
        }
      }
      uVar16 = uVar16 & 0xfffffff | (uint)(bVar1 >> 4) << 0x1c;
      if (*(char *)(param_2 + 0x68) == '\0') goto LAB_001e6ee0;
      uVar12 = *(uint *)(param_1 + 0xdc);
joined_r0x001e6fdb:
      uVar16 = uVar16 | 1;
joined_r0x001e6ef9:
      if (uVar12 != 0) goto LAB_001e6c90;
    }
    uVar16 = uVar16 & 0xffffff3f | (pbVar7[3] >> 4 & 3) << 6;
  }
LAB_001e6c9d:
  pcVar2 = *(code **)(param_1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  iVar5 = (*pcVar2)(param_1,9,0,uVar4);
  if ((iVar5 == -1) ||
     (cVar3 = nvswitch_is_link_valid(param_1,*(undefined4 *)(param_2 + 0x38)), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar2 = *(code **)(param_1 + 0x928);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  (*pcVar2)(param_1,9,0,uVar4,0x618,uVar16);
  pcVar2 = *(code **)(param_1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  iVar5 = (*pcVar2)(param_1,9,0,uVar4);
  if ((iVar5 == -1) ||
     (cVar3 = nvswitch_is_link_valid(param_1,*(undefined4 *)(param_2 + 0x38)), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar2 = *(code **)(param_1 + 0x920);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  uVar12 = (*pcVar2)(param_1,9,0,uVar4,0x638);
  pcVar2 = *(code **)(param_1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  iVar5 = (*pcVar2)(param_1,9,0,uVar4);
  if ((iVar5 == -1) ||
     (cVar3 = nvswitch_is_link_valid(param_1,*(undefined4 *)(param_2 + 0x38)), cVar3 == '\0')) {
    nvswitch_assert_log();
  }
  pcVar2 = *(code **)(param_1 + 0x928);
  uVar4 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  (*pcVar2)(param_1,9,0,uVar4,0x638,uVar12 & 0xfffffffb);
  nvswitch_apply_recal_settings(param_1,param_2);
  return;
}


// ===== 001e7280 nvswitch_load_link_disable_settings_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */
/* WARNING: Function: __x86_indirect_thunk_r15 replaced with injection: x86_indirect_thunk_r15 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_load_link_disable_settings_lr10(long param_1,long param_2)

{
  code *pcVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  long local_40;
  
  local_40 = 0;
  if (*(int *)(param_1 + 0x1f88) == 6) {
    local_40 = *(long *)(param_1 + 0x1f90);
  }
  pbVar6 = (byte *)nvswitch_get_bios_nvlink_config(param_1);
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar3 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  iVar5 = (*pcVar1)(param_1,9,0,uVar3);
  if (iVar5 == -1) {
LAB_001e7518:
    nvswitch_assert_log();
  }
  else {
    cVar2 = nvswitch_is_link_valid(param_1,*(undefined4 *)(param_2 + 0x38));
    if (cVar2 == '\0') goto LAB_001e7518;
  }
  pcVar1 = *(code **)(param_1 + 0x920);
  uVar3 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  uVar4 = (*pcVar1)(param_1,9,0,uVar3,0x64c);
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar3 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  iVar5 = (*pcVar1)(param_1,9,0,uVar3);
  if (iVar5 == -1) {
LAB_001e7508:
    nvswitch_assert_log();
  }
  else {
    cVar2 = nvswitch_is_link_valid(param_1,*(undefined4 *)(param_2 + 0x38));
    if (cVar2 == '\0') goto LAB_001e7508;
  }
  pcVar1 = *(code **)(param_1 + 0x928);
  uVar3 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  (*pcVar1)(param_1,9,0,uVar3,0x64c,uVar4 & 0xfffffffe);
  if (pbVar6 != (byte *)0x0) {
    pbVar6 = pbVar6 + (ulong)*(uint *)(pbVar6 + 0x1e3c) * 0x280 + 0xc +
                      (ulong)*(uint *)(param_2 + 0x38) * 10;
  }
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar3 = nvswitch_get_link_eng_inst(param_1,(ulong)*(uint *)(param_2 + 0x38),9);
  iVar5 = (*pcVar1)(param_1,9,0,uVar3);
  if (iVar5 == -1) {
LAB_001e74f8:
    nvswitch_assert_log();
  }
  else {
    cVar2 = nvswitch_is_link_valid(param_1,*(undefined4 *)(param_2 + 0x38));
    if (cVar2 == '\0') goto LAB_001e74f8;
  }
  pcVar1 = *(code **)(param_1 + 0x920);
  uVar3 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  uVar4 = (*pcVar1)(param_1,9,0,uVar3,0x600);
  if ((pbVar6 != (byte *)0x0) && ((*pbVar6 & 1) != 0)) {
    cVar2 = nvswitch_is_link_in_reset(param_1,param_2);
    if (cVar2 != '\0') {
      iVar5 = nvswitch_link_termination_setup(param_1,param_2);
      if (iVar5 == 0) {
        *(ulong *)(local_40 + 0x9b30) =
             *(ulong *)(local_40 + 0x9b30) | 1L << ((byte)*(undefined4 *)(param_2 + 0x38) & 0x3f);
      }
    }
    return;
  }
  pcVar1 = *(code **)(param_1 + 0x910);
  uVar3 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  iVar5 = (*pcVar1)(param_1,9,0,uVar3);
  if (iVar5 != -1) {
    cVar2 = nvswitch_is_link_valid(param_1,*(undefined4 *)(param_2 + 0x38));
    if (cVar2 != '\0') goto LAB_001e74b0;
  }
  nvswitch_assert_log();
LAB_001e74b0:
  pcVar1 = *(code **)(param_1 + 0x928);
  uVar3 = nvswitch_get_link_eng_inst(param_1,*(undefined4 *)(param_2 + 0x38),9);
  (*pcVar1)(param_1,9,0,uVar3,0x600,uVar4 & 0xfffffffe);
  return;
}


// ===== 001e7580 nvswitch_reset_persistent_link_hw_state_lr10 =====

void nvswitch_reset_persistent_link_hw_state_lr10(void)

{
  return;
}


// ===== 001e7590 nvswitch_apply_recal_settings_lr10 =====

void nvswitch_apply_recal_settings_lr10(void)

{
  return;
}


// ===== 001e75a0 nvswitch_launch_ALI_link_training_lr10 =====

undefined8 nvswitch_launch_ALI_link_training_lr10(void)

{
  return 0xe;
}


// ===== 001e75b0 nvswitch_reset_and_train_link_lr10 =====

undefined8 nvswitch_reset_and_train_link_lr10(void)

{
  return 0xe;
}


// ===== 001e75c0 nvswitch_does_link_need_termination_enabled_lr10 =====

undefined8 nvswitch_does_link_need_termination_enabled_lr10(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  int *piVar7;
  uint local_1c;
  
  iVar3 = nvswitch_read_physical_id();
  if ((*(int *)(param_1 + 0x1f88) != 6) || (lVar1 = *(long *)(param_1 + 0x1f90), lVar1 == 0)) {
    return 0;
  }
  if (*(char *)(lVar1 + 0x9b38) == '\0') {
    *(undefined8 *)(lVar1 + 0x9b30) = 0;
    cVar2 = nvlink_lib_is_registerd_device_with_reduced_config();
    if (cVar2 != '\0') {
      piVar7 = &nvswitchDisconnetedRemoteLinkMasks;
      uVar5 = 0;
      do {
        if (*piVar7 == iVar3) {
          *(ulong *)(lVar1 + 0x9b30) =
               *(ulong *)(lVar1 + 0x9b30) | *(ulong *)(uVar5 * 0x18 + 0x593268);
          iVar3 = nvlink_lib_return_device_count_by_type(3,&local_1c);
          uVar6 = *(ulong *)(lVar1 + 0x9b30);
          if ((iVar3 == 0) && (local_1c < 7)) {
            uVar6 = uVar6 | *(ulong *)(uVar5 * 0x18 + 0x593270);
            *(ulong *)(lVar1 + 0x9b30) = uVar6;
          }
          goto LAB_001e7667;
        }
        uVar4 = (int)uVar5 + 1;
        uVar5 = (ulong)uVar4;
        piVar7 = piVar7 + 6;
      } while (uVar4 != 0xc);
    }
    uVar6 = *(ulong *)(lVar1 + 0x9b30);
LAB_001e7667:
    *(undefined1 *)(lVar1 + 0x9b38) = 1;
  }
  else {
    uVar6 = *(ulong *)(lVar1 + 0x9b30);
  }
  return CONCAT71((int7)(uVar6 >> 8),(uVar6 >> ((ulong)*(uint *)(param_2 + 0x38) & 0x3f) & 1) != 0);
}


// ===== 001e76c0 nvswitch_link_termination_setup_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

undefined8 nvswitch_link_termination_setup_lr10(long param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar1 = *(uint *)(param_2 + 0x38);
  if (0x3f < uVar1) {
    return 1;
  }
  pcVar2 = *(code **)(param_1 + 0x910);
  uVar4 = nvswitch_get_link_eng_inst(param_1,uVar1,0xb);
  iVar5 = (*pcVar2)(param_1,0xb,0,uVar4);
  if (((iVar5 != -1) && (cVar3 = nvswitch_is_link_valid(param_1,uVar1), cVar3 != '\0')) &&
     (*(int *)(param_2 + 0x5c) == 5)) {
    iVar5 = nvswitch_minion_send_command_lr10(param_1,*(undefined4 *)(param_2 + 0x38),0xd,0);
    if (iVar5 != 0) {
      return 8;
    }
    nvswitch_minion_send_command_lr10(param_1,*(undefined4 *)(param_2 + 0x38),0x12,0);
    return 0;
  }
  return 1;
}


// ===== 001e7790 nvswitch_ctrl_get_link_l1_capability_lr10 =====

undefined8 nvswitch_ctrl_get_link_l1_capability_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001e77a0 nvswitch_ctrl_get_link_l1_threshold_lr10 =====

undefined8 nvswitch_ctrl_get_link_l1_threshold_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001e77b0 nvswitch_ctrl_set_link_l1_threshold_lr10 =====

undefined8 nvswitch_ctrl_set_link_l1_threshold_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001e77c0 nvswitch_get_remap_table_selector_lr10 =====

undefined8
nvswitch_get_remap_table_selector_lr10(undefined8 param_1,int param_2,undefined4 *param_3)

{
  if (param_2 == 0) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0;
    }
    return 0;
  }
  return 0xfffffff3;
}


// ===== 001e77f0 nvswitch_get_ingress_ram_size_lr10 =====

long nvswitch_get_ingress_ram_size_lr10(undefined8 param_1,int param_2)

{
  long lVar1;
  
  lVar1 = 0x800;
  if (param_2 != 0) {
    lVar1 = (ulong)(param_2 - 1U < 2) << 9;
  }
  return lVar1;
}


// ===== 001e7810 _nvswitch_get_engine_base_lr10 =====

uint _nvswitch_get_engine_base_lr10
               (long param_1,uint param_2,uint param_3,char param_4,uint *param_5)

{
  uint uVar1;
  long lVar2;
  char *pcVar3;
  char cVar4;
  bool bVar5;
  
  lVar2 = 0;
  if (*(int *)(param_1 + 0x1f88) == 6) {
    lVar2 = *(long *)(param_1 + 0x1f90);
  }
  if (param_2 == 0x27) {
    if (param_4 == '\0') {
      if ((param_3 < 0x24) && (*(char *)(lVar2 + 0x5b10 + (ulong)param_3 * 0x20) != '\0')) {
        pcVar3 = (char *)(lVar2 + 0x5b10 + (ulong)param_3 * 0x20);
        cVar4 = *pcVar3;
        goto LAB_001e7d50;
      }
    }
    else if ((param_3 < 4) && (*(char *)(lVar2 + 0x5f90 + (ulong)param_3 * 0x20) != '\0')) {
      pcVar3 = (char *)(lVar2 + 0x5f90 + (ulong)param_3 * 0x20);
      cVar4 = *pcVar3;
LAB_001e7ac8:
      if (cVar4 == '\0') {
LAB_001e7acc:
        uVar1 = 0xfffffff7;
        param_3 = 0;
        goto LAB_001e7867;
      }
LAB_001e7a50:
      if (*(int *)(pcVar3 + 0xc) == 3) goto LAB_001e7a58;
LAB_001e7a08:
      uVar1 = 0xfffffff5;
      param_3 = 0;
      goto LAB_001e7867;
    }
  }
  else if (param_2 < 0x28) {
    if (param_2 == 0x19) {
      if ((param_4 == '\0') && (param_3 == 0)) {
        if (*(char *)(lVar2 + 0x3870) == '\0') goto LAB_001e7be8;
        pcVar3 = (char *)(lVar2 + 0x3870);
        goto LAB_001e7a00;
      }
    }
    else if (param_2 < 0x1a) {
      if (param_2 == 0x15) {
LAB_001e7918:
        bVar5 = param_3 != 0;
        param_3 = 0;
        uVar1 = -(uint)(bVar5 || param_4 != '\0');
        goto LAB_001e7867;
      }
      if (param_2 < 0x16) {
        if (param_2 == 0x14) {
          if ((param_4 == '\0') && (param_3 == 0)) {
            if (*(char *)(lVar2 + 0x35d0) == '\0') goto LAB_001e7be8;
            pcVar3 = (char *)(lVar2 + 0x35d0);
            goto LAB_001e7a00;
          }
        }
        else if (0xe < param_2 - 1) goto LAB_001e7918;
      }
      else if (param_2 == 0x16) {
        if ((param_4 == '\0') && (param_3 == 0)) {
          if (*(char *)(lVar2 + 0x3610) == '\0') goto LAB_001e7be8;
          pcVar3 = (char *)(lVar2 + 0x3610);
          goto LAB_001e7a00;
        }
      }
      else if (((param_2 == 0x17) && (param_4 == '\0')) && (param_3 == 0)) {
        if ((&DAT_000037f0)[lVar2] == '\0') {
LAB_001e7be8:
          uVar1 = 0xffffffff;
          goto LAB_001e7867;
        }
        pcVar3 = &DAT_000037f0 + lVar2;
LAB_001e7a00:
        if (*(int *)(pcVar3 + 0xc) == 2) {
LAB_001e7a58:
          uVar1 = *(uint *)(pcVar3 + 0x10);
          *param_5 = uVar1;
          return -(uint)(uVar1 == 0) & 0xfffffff5;
        }
        goto LAB_001e7a08;
      }
    }
    else if (param_2 == 0x23) {
      if (param_4 == '\0') {
        if ((param_3 < 0x24) && (*(char *)(lVar2 + 0x3e50 + (ulong)param_3 * 0x20) != '\0')) {
          pcVar3 = (char *)(lVar2 + 0x3e50 + (ulong)param_3 * 0x20);
          cVar4 = *pcVar3;
          goto LAB_001e7d50;
        }
      }
      else if ((param_3 < 4) && (*(char *)(lVar2 + 0x42d0 + (ulong)param_3 * 0x20) != '\0')) {
        pcVar3 = (char *)(lVar2 + 0x42d0 + (ulong)param_3 * 0x20);
        cVar4 = *pcVar3;
        goto LAB_001e7ac8;
      }
    }
    else if (param_2 < 0x24) {
      if (param_2 == 0x21) {
        if (param_4 == '\0') {
          if ((param_3 < 9) && (*(char *)(lVar2 + 0x3bd0 + (ulong)param_3 * 0x20) != '\0')) {
            pcVar3 = (char *)(lVar2 + 0x3bd0 + (ulong)param_3 * 0x20);
            cVar4 = *pcVar3;
            goto LAB_001e7d50;
          }
        }
        else if (param_3 == 0) {
          if (*(char *)(lVar2 + 0x3cf0) == '\0') goto LAB_001e7be8;
          pcVar3 = (char *)(lVar2 + 0x3cf0);
          goto LAB_001e7a50;
        }
      }
      else if (param_2 == 0x22) {
        if (param_4 == '\0') {
          if ((param_3 < 9) && (*(char *)(lVar2 + 0x3d10 + (ulong)param_3 * 0x20) != '\0')) {
            pcVar3 = (char *)(lVar2 + 0x3d10 + (ulong)param_3 * 0x20);
            cVar4 = *pcVar3;
            goto LAB_001e7d50;
          }
        }
        else if (param_3 == 0) {
          if (*(char *)(lVar2 + 0x3e30) != '\0') {
            pcVar3 = (char *)(lVar2 + 0x3e30);
            goto LAB_001e7a50;
          }
          goto LAB_001e7be8;
        }
      }
    }
    else if (param_2 == 0x24) {
      if (param_4 == '\0') {
        if ((param_3 < 9) && (*(char *)(lVar2 + 0x4350 + (ulong)param_3 * 0x20) != '\0')) {
          pcVar3 = (char *)(lVar2 + 0x4350 + (ulong)param_3 * 0x20);
          cVar4 = *pcVar3;
          goto LAB_001e7d50;
        }
      }
      else if (param_3 == 0) {
        if (*(char *)(lVar2 + 0x4470) != '\0') {
          pcVar3 = (char *)(lVar2 + 0x4470);
          goto LAB_001e7a50;
        }
        goto LAB_001e7be8;
      }
    }
    else if (param_2 == 0x26) {
      if (param_4 == '\0') {
        if ((param_3 < 9) && (*(char *)(lVar2 + 0x38b0 + (ulong)param_3 * 0x20) != '\0')) {
          pcVar3 = (char *)(lVar2 + 0x38b0 + (ulong)param_3 * 0x20);
          cVar4 = *pcVar3;
          goto LAB_001e7d50;
        }
      }
      else if (param_3 == 0) {
        if ((&DAT_000039d0)[lVar2] != '\0') {
          pcVar3 = &DAT_000039d0 + lVar2;
          goto LAB_001e7a50;
        }
        goto LAB_001e7be8;
      }
    }
  }
  else if (param_2 == 0x31) {
    if (param_4 == '\0') {
      if ((param_3 < 0x24) && (*(char *)(lVar2 + 0x68d0 + (ulong)param_3 * 0x20) != '\0')) {
        pcVar3 = (char *)(lVar2 + 0x68d0 + (ulong)param_3 * 0x20);
        cVar4 = *pcVar3;
        goto LAB_001e7d50;
      }
    }
    else if ((param_3 < 4) && (*(char *)(lVar2 + 0x6d50 + (ulong)param_3 * 0x20) != '\0')) {
      pcVar3 = (char *)(lVar2 + 0x6d50 + (ulong)param_3 * 0x20);
      cVar4 = *pcVar3;
      goto LAB_001e7ac8;
    }
  }
  else if (param_2 < 0x32) {
    if (param_2 == 0x2a) {
      if (param_4 == '\0') {
        if ((param_3 < 9) && (*(char *)(lVar2 + 0x59d0 + (ulong)param_3 * 0x20) != '\0')) {
          pcVar3 = (char *)(lVar2 + 0x59d0 + (ulong)param_3 * 0x20);
          cVar4 = *pcVar3;
          goto LAB_001e7d50;
        }
      }
      else if (param_3 == 0) {
        if (*(char *)(lVar2 + 0x5af0) != '\0') {
          pcVar3 = (char *)(lVar2 + 0x5af0);
          goto LAB_001e7a50;
        }
        goto LAB_001e7be8;
      }
    }
    else if (param_2 < 0x2b) {
      if (param_2 == 0x28) {
        if (param_4 == '\0') {
          if ((param_3 < 9) && (*(char *)(lVar2 + 0x6010 + (ulong)param_3 * 0x20) != '\0')) {
            pcVar3 = (char *)(lVar2 + 0x6010 + (ulong)param_3 * 0x20);
            cVar4 = *pcVar3;
            goto LAB_001e7d50;
          }
        }
        else if (param_3 == 0) {
          if (*(char *)(lVar2 + 0x6130) != '\0') {
            pcVar3 = (char *)(lVar2 + 0x6130);
            goto LAB_001e7a50;
          }
          goto LAB_001e7be8;
        }
      }
      else if (param_4 == '\0') {
        if ((param_3 < 0x24) && (*(char *)(lVar2 + 0x54d0 + (ulong)param_3 * 0x20) != '\0')) {
          pcVar3 = (char *)(lVar2 + 0x54d0 + (ulong)param_3 * 0x20);
          cVar4 = *pcVar3;
LAB_001e7d50:
          if (cVar4 != '\0') goto LAB_001e7a00;
          goto LAB_001e7acc;
        }
      }
      else if ((param_3 < 4) && (*(char *)(lVar2 + 0x5950 + (ulong)param_3 * 0x20) != '\0')) {
        pcVar3 = (char *)(lVar2 + 0x5950 + (ulong)param_3 * 0x20);
        cVar4 = *pcVar3;
        goto LAB_001e7ac8;
      }
    }
    else if (param_2 == 0x2b) {
      if (param_4 == '\0') {
        if ((param_3 < 9) && (*(char *)(lVar2 + 0x5250 + (ulong)param_3 * 0x20) != '\0')) {
          pcVar3 = (char *)(lVar2 + 0x5250 + (ulong)param_3 * 0x20);
          cVar4 = *pcVar3;
          goto LAB_001e7d50;
        }
      }
      else if (param_3 == 0) {
        if (*(char *)(lVar2 + 0x5370) != '\0') {
          pcVar3 = (char *)(lVar2 + 0x5370);
          goto LAB_001e7a50;
        }
        goto LAB_001e7be8;
      }
    }
    else if (param_2 == 0x30) {
      if (param_4 == '\0') {
        if ((param_3 < 9) && (*(char *)(lVar2 + 0x3a90 + (ulong)param_3 * 0x20) != '\0')) {
          pcVar3 = (char *)(lVar2 + 0x3a90 + (ulong)param_3 * 0x20);
          cVar4 = *pcVar3;
          goto LAB_001e7d50;
        }
      }
      else if (param_3 == 0) {
        if ((&DAT_00003bb0)[lVar2] != '\0') {
          pcVar3 = &DAT_00003bb0 + lVar2;
          goto LAB_001e7a50;
        }
        goto LAB_001e7be8;
      }
    }
  }
  else if (param_2 == 0x43) {
    if (param_4 == '\0') {
      if ((param_3 < 0x10) && (*(char *)(lVar2 + 0x75f0 + (ulong)param_3 * 0x20) != '\0')) {
        pcVar3 = (char *)(lVar2 + 0x75f0 + (ulong)param_3 * 0x20);
        cVar4 = *pcVar3;
        goto LAB_001e7d50;
      }
    }
    else if ((param_3 < 4) && (*(char *)(lVar2 + 0x77f0 + (ulong)param_3 * 0x20) != '\0')) {
      pcVar3 = (char *)(lVar2 + 0x77f0 + (ulong)param_3 * 0x20);
      cVar4 = *pcVar3;
      goto LAB_001e7ac8;
    }
  }
  else if (param_2 < 0x44) {
    if (param_2 == 0x32) {
      if (param_4 == '\0') {
        if ((param_3 < 9) && (*(char *)(lVar2 + 0x6dd0 + (ulong)param_3 * 0x20) != '\0')) {
          pcVar3 = (char *)(lVar2 + 0x6dd0 + (ulong)param_3 * 0x20);
          cVar4 = *pcVar3;
          goto LAB_001e7d50;
        }
      }
      else if (param_3 == 0) {
        if (*(char *)(lVar2 + 0x6ef0) != '\0') {
          pcVar3 = (char *)(lVar2 + 0x6ef0);
          goto LAB_001e7a50;
        }
        goto LAB_001e7be8;
      }
    }
    else if (param_2 == 0x42) {
      if (param_4 == '\0') {
        if ((param_3 < 4) && (*(char *)(lVar2 + 0x39f0 + (ulong)param_3 * 0x20) != '\0')) {
          pcVar3 = (char *)(lVar2 + 0x39f0 + (ulong)param_3 * 0x20);
          cVar4 = *pcVar3;
          goto LAB_001e7d50;
        }
      }
      else if (param_3 == 0) {
        if ((&DAT_00003a70)[lVar2] != '\0') {
          pcVar3 = &DAT_00003a70 + lVar2;
          goto LAB_001e7a50;
        }
        goto LAB_001e7be8;
      }
    }
  }
  else if (param_2 == 0x44) {
    if (param_4 == '\0') {
      if ((param_3 < 4) && (*(char *)(lVar2 + 0x7870 + (ulong)param_3 * 0x20) != '\0')) {
        pcVar3 = (char *)(lVar2 + 0x7870 + (ulong)param_3 * 0x20);
        cVar4 = *pcVar3;
        goto LAB_001e7d50;
      }
    }
    else if (param_3 == 0) {
      if (*(char *)(lVar2 + 0x78f0) != '\0') {
        pcVar3 = (char *)(lVar2 + 0x78f0);
        goto LAB_001e7a50;
      }
      goto LAB_001e7be8;
    }
  }
  uVar1 = 0xffffffff;
  param_3 = 0;
LAB_001e7867:
  *param_5 = param_3;
  return uVar1;
}


// ===== 001e8030 nvswitch_get_num_links_lr10 =====

undefined8 nvswitch_get_num_links_lr10(void)

{
  return 0x24;
}


// ===== 001e8040 nvswitch_get_num_links_per_nvlipt_lr10 =====

undefined8 nvswitch_get_num_links_per_nvlipt_lr10(void)

{
  return 4;
}


// ===== 001e804a nvswitch_get_latency_sample_interval_msec_lr10.cold =====

void nvswitch_get_latency_sample_interval_msec_lr10_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001e8060 nvswitch_get_latency_sample_interval_msec_lr10 =====

undefined4 nvswitch_get_latency_sample_interval_msec_lr10(long param_1)

{
  code *pcVar1;
  
  if (*(int *)(param_1 + 0x1f88) == 6) {
    return **(undefined4 **)(&DAT_00009b00 + *(long *)(param_1 + 0x1f90));
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001e8090 nvswitch_get_swap_clk_default_lr10 =====

undefined8 nvswitch_get_swap_clk_default_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001e80a0 nvswitch_get_device_dma_width_lr10 =====

undefined8 nvswitch_get_device_dma_width_lr10(void)

{
  return 0x40;
}


// ===== 001e80b0 nvswitch_is_soe_supported_lr10 =====

bool nvswitch_is_soe_supported_lr10(long param_1)

{
  return *(int *)(param_1 + 0x68) != 1;
}


// ===== 001e80c0 nvswitch_get_caps_nvlink_version_lr10 =====

undefined8 nvswitch_get_caps_nvlink_version_lr10(void)

{
  return 5;
}


// ===== 001e80d0 nvswitch_get_bios_nvlink_config_lr10 =====

long nvswitch_get_bios_nvlink_config_lr10(long param_1)

{
  long lVar1;
  
  lVar1 = 0;
  if (*(int *)(param_1 + 0x1f88) == 6) {
    lVar1 = *(long *)(param_1 + 0x1f90);
    if (lVar1 != 0) {
      lVar1 = lVar1 + 0x7c30;
    }
  }
  return lVar1;
}


// ===== 001e8100 nvswitch_send_inband_nack_lr10 =====

void nvswitch_send_inband_nack_lr10(void)

{
  return;
}


// ===== 001e8110 nvswitch_get_max_persistent_message_count_lr10 =====

undefined8 nvswitch_get_max_persistent_message_count_lr10(void)

{
  return 0;
}


// ===== 001e8120 nvswitch_launch_ALI_lr10 =====

undefined8 nvswitch_launch_ALI_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001e8130 nvswitch_set_training_mode_lr10 =====

undefined8 nvswitch_set_training_mode_lr10(void)

{
  return 0;
}


// ===== 001e8140 nvswitch_ctrl_get_nvlink_lp_counters_lr10 =====

undefined8 nvswitch_ctrl_get_nvlink_lp_counters_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001e8150 nvswitch_cci_reset_and_drain_links_lr10 =====

undefined8 nvswitch_cci_reset_and_drain_links_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001e8160 nvswitch_update_link_state_led_lr10 =====

void nvswitch_update_link_state_led_lr10(void)

{
  return;
}


// ===== 001e8170 nvswitch_fsp_update_cmdq_head_tail_lr10 =====

void nvswitch_fsp_update_cmdq_head_tail_lr10(void)

{
  return;
}


// ===== 001e8180 nvswitch_fsp_get_cmdq_head_tail_lr10 =====

void nvswitch_fsp_get_cmdq_head_tail_lr10(void)

{
  return;
}


// ===== 001e8190 nvswitch_fsp_nvdm_to_seid_lr10 =====

undefined8 nvswitch_fsp_nvdm_to_seid_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001e81a0 nvswitch_fsp_create_mctp_header_lr10 =====

undefined8 nvswitch_fsp_create_mctp_header_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001e81b0 nvswitch_fsp_create_nvdm_header_lr10 =====

undefined8 nvswitch_fsp_create_nvdm_header_lr10(void)

{
  return 0;
}


// ===== 001e81c0 nvswitch_fsp_get_packet_info_lr10 =====

undefined8 nvswitch_fsp_get_packet_info_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001e81d0 nvswitch_fsp_validate_mctp_payload_header_lr10 =====

undefined8 nvswitch_fsp_validate_mctp_payload_header_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001e81e0 nvswitch_fsp_config_ememc_lr10 =====

undefined8 nvswitch_fsp_config_ememc_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001e81f0 nvswitch_fsp_error_code_to_nvlstatus_map_lr10 =====

undefined8 nvswitch_fsp_error_code_to_nvlstatus_map_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001e8200 nvswitch_is_tnvl_mode_enabled_lr10 =====

undefined8 nvswitch_is_tnvl_mode_enabled_lr10(void)

{
  return 0;
}


// ===== 001e8210 nvswitch_get_eng_base_lr10 =====

undefined4 nvswitch_get_eng_base_lr10(long param_1,uint param_2,int param_3,uint param_4)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  
  lVar3 = 0;
  if (*(int *)(param_1 + 0x1f88) == 6) {
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


// ===== 001e8300 nvswitch_is_link_valid_lr10 =====

undefined1 nvswitch_is_link_valid_lr10(long param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = nvswitch_get_num_links();
  if (param_2 < uVar1) {
    return *(undefined1 *)(param_1 + 0xf60 + (ulong)param_2 * 0x40);
  }
  return 0;
}


// ===== 001e8340 nvswitch_get_link_eng_inst_lr10 =====

uint nvswitch_get_link_eng_inst_lr10(undefined8 param_1,uint param_2,uint param_3)

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


// ===== 001e83a0 nvswitch_ctrl_register_read_lr10 =====

int nvswitch_ctrl_register_read_lr10(long *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_1c;
  
  iVar1 = _nvswitch_get_engine_base_lr10(param_1,*param_2,param_2[1],0,&local_1c);
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


// ===== 001e8400 nvswitch_ctrl_get_board_part_number_lr10 =====

undefined8 nvswitch_ctrl_get_board_part_number_lr10(long param_1,long param_2)

{
  char *pcVar1;
  long lVar2;
  undefined8 uVar3;
  
  pcVar1 = *(char **)(param_1 + 0xf40);
  if (pcVar1 == (char *)0x0) {
    uVar3 = 0xfffffff3;
  }
  else if (*pcVar1 == '\0') {
    uVar3 = 0xfffffff9;
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


// ===== 001e8470 nvswitch_ctrl_register_write_lr10 =====

ulong nvswitch_ctrl_register_write_lr10(long *param_1,undefined4 *param_2)

{
  ulong uVar1;
  int local_c;
  
  uVar1 = _nvswitch_get_engine_base_lr10
                    (param_1,*param_2,param_2[1],*(undefined1 *)(param_2 + 2),&local_c);
  if ((int)uVar1 == 0) {
    if (*(ulong *)(*param_1 + 0x68) <= (ulong)(uint)(local_c + param_2[3])) {
      return 0xfffffff5;
    }
    nvswitch_reg_write_32();
    uVar1 = uVar1 & 0xffffffff;
  }
  return uVar1;
}


// ===== 001e84d0 nvswitch_alloc_chipdevice_lr10 =====

long nvswitch_alloc_chipdevice_lr10(long param_1)

{
  long lVar1;
  
  lVar1 = nvswitch_os_malloc_trace(0x9b40,0,0);
  if (lVar1 != 0) {
    nvswitch_os_memset(lVar1,0,0x9b40);
  }
  *(undefined4 *)(param_1 + 0x1f88) = 6;
  return lVar1;
}


// ===== 001e8520 nvswitch_is_bios_supported_lr10 =====

void nvswitch_is_bios_supported_lr10(void)

{
  nvswitch_is_spi_supported();
  return;
}


// ===== 001e8530 nvswitch_destroy_device_state_lr10 =====

void nvswitch_destroy_device_state_lr10(long param_1)

{
  long lVar1;
  char cVar2;
  
  if (*(int *)(param_1 + 0x1f88) == 6) {
    lVar1 = *(long *)(param_1 + 0x1f90);
    cVar2 = nvswitch_is_soe_supported();
    if (cVar2 != '\0') {
      nvswitch_soe_unregister_events(param_1);
    }
    if (lVar1 != 0) {
      if (*(long *)(&DAT_00009b00 + lVar1) != 0) {
        nvswitch_os_free();
      }
      if (*(long *)(lVar1 + 0x9b28) != 0) {
        nvswitch_os_free();
      }
      nvswitch_free_chipdevice(param_1);
      nvswitch_i2c_destroy(param_1);
      return;
    }
  }
  else {
    cVar2 = nvswitch_is_soe_supported();
    if (cVar2 != '\0') {
      nvswitch_soe_unregister_events(param_1);
      nvswitch_i2c_destroy(param_1);
      return;
    }
  }
  nvswitch_i2c_destroy(param_1);
  return;
}


// ===== 001e8600 nvswitch_ctrl_get_fom_values_lr10 =====

undefined4 nvswitch_ctrl_get_fom_values_lr10(undefined8 param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  long lVar3;
  undefined4 local_2c [3];
  
  lVar3 = nvswitch_get_link(param_1,*(undefined1 *)param_2);
  if (lVar3 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    nvswitch_minion_get_dl_status(param_1,*param_2,0xa0,0,local_2c);
    *(undefined4 *)((long)param_2 + 6) = local_2c[0];
    uVar2 = nvswitch_minion_get_dl_status(param_1,*param_2,0xa1,0,local_2c);
    *(undefined4 *)((long)param_2 + 10) = local_2c[0];
    uVar1 = nvswitch_get_sublink_width(param_1,*param_2);
    *(undefined1 *)(param_2 + 1) = uVar1;
  }
  return uVar2;
}


// ===== 001e8680 nvswitch_ctrl_get_inforom_version_lr10 =====

undefined8 nvswitch_ctrl_get_inforom_version_lr10(long param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xf40);
  if ((lVar1 != 0) && (*(char *)(lVar1 + 0xe30) != '\0')) {
    nvswitch_inforom_string_copy(lVar1 + 0xe90,param_2,0x10);
    return 0;
  }
  return 0xfffffff3;
}


// ===== 001e86c0 nvswitch_get_bios_size_lr10 =====

void nvswitch_get_bios_size_lr10(void)

{
  nvswitch_bios_read_size();
  return;
}


// ===== 001e86d0 nvswitch_post_init_device_setup_lr10 =====

undefined8 nvswitch_post_init_device_setup_lr10(long param_1)

{
  char cVar1;
  undefined8 uVar2;
  
  if ((((*(int *)(param_1 + 100) == 0) || (*(char *)(param_1 + 0x25) != '\0')) ||
      (*(char *)(param_1 + 0x26) != '\0')) ||
     ((cVar1 = nvswitch_is_soe_supported(), cVar1 == '\0' ||
      (uVar2 = soeTestDma_HAL(param_1,*(undefined8 *)(param_1 + 0xd20)), (int)uVar2 == 0)))) {
    cVar1 = nvswitch_is_inforom_supported(param_1);
    if (cVar1 != '\0') {
      nvswitch_inforom_post_init(param_1);
    }
    nvswitch_soe_init_l2_state(param_1);
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 001e8750 nvswitch_set_training_error_info_lr10 =====

void nvswitch_set_training_error_info_lr10(undefined8 param_1,undefined8 *param_2)

{
  undefined1 local_30 [8];
  undefined8 local_28;
  undefined1 local_20 [8];
  undefined8 local_18;
  undefined8 local_10;
  
  local_18 = *param_2;
  local_20[0] = 1;
  local_10 = param_2[1];
  local_30[0] = 0;
  local_28 = 0;
  nvswitch_smbpbi_set_link_error_info(param_1,local_20,local_30);
  return;
}


// ===== 001e8790 nvswitch_reg_write_32_lr10 =====

void nvswitch_reg_write_32_lr10(long *param_1,uint param_2,undefined4 param_3)

{
  if (*(long *)(*param_1 + 0x78) != 0) {
    nvswitch_os_mem_write32(*(long *)(*param_1 + 0x78) + (ulong)param_2,param_3);
    return;
  }
  return;
}


// ===== 001e87c0 nvswitch_initialize_pmgr_lr10 =====

undefined8 nvswitch_initialize_pmgr_lr10(undefined8 param_1)

{
  nvswitch_init_pmgr_lr10();
  nvswitch_init_pmgr_devices_lr10(param_1);
  return 0;
}


// ===== 001e87f0 nvswitch_deassert_link_reset_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_deassert_link_reset_lr10(long param_1,long param_2)

{
  int iVar1;
  long local_20 [2];
  
  iVar1 = (**(code **)(param_1 + 0x6b8))(param_2,local_20);
  if ((iVar1 == 0) && (local_20[0] == 7)) {
    (**(code **)(*(long *)(param_2 + 0x90) + 0x28))(param_2,0x13,0);
    return;
  }
  return;
}


// ===== 001e8850 nvswitch_determine_platform_lr10 =====

void nvswitch_determine_platform_lr10(long param_1)

{
  uint uVar1;
  
  uVar1 = nvswitch_reg_read_32(param_1,8);
  *(byte *)(param_1 + 0x24) = (byte)(uVar1 >> 0x1f);
  if (-1 < (int)uVar1) {
    if ((uVar1 & 0x40000000) == 0) {
      *(undefined1 *)(param_1 + 0x25) = 1;
      nvswitch_os_override_platform(*(undefined8 *)(param_1 + 0x18),param_1 + 0x25);
      return;
    }
    *(undefined1 *)(param_1 + 0x26) = 1;
  }
  return;
}


// ===== 001e88b0 nvswitch_ctrl_get_sw_info_lr10 =====

undefined8 nvswitch_ctrl_get_sw_info_lr10(undefined8 param_1,uint *param_2)

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
      while (param_2[1] == 0) {
        param_2[0x21] = 1;
        param_2 = param_2 + 1;
        if (param_2 == puVar1) {
          return uVar2;
        }
      }
      if (param_2[1] == 1) {
        param_2[0x21] = 0;
      }
      else {
        uVar2 = 0xffffffff;
      }
      param_2 = param_2 + 1;
    } while (param_2 != puVar1);
    return uVar2;
  }
  return 0;
}


// ===== 001e8950 nvswitch_is_inforom_supported_lr10 =====

bool nvswitch_is_inforom_supported_lr10(long param_1)

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


// ===== 001e8990 nvswitch_ctrl_get_info_lr10 =====

undefined8 nvswitch_ctrl_get_info_lr10(long *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint extraout_var;
  uint *puVar3;
  uint *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  bool bVar8;
  undefined1 local_3c [12];
  
  if (0x20 < *param_2) {
    return 0xffffffff;
  }
  puVar3 = param_2 + 0x21;
  nvswitch_os_memset(puVar3,0,0x80);
  if (*param_2 == 0) {
    return 0;
  }
  uVar6 = 0;
  uVar7 = 0;
LAB_001e89e7:
  uVar2 = puVar3[-0x20];
  puVar4 = puVar3;
  if (uVar2 == 0x105) goto LAB_001e8bc0;
  bVar8 = false;
  do {
    puVar3 = puVar4;
    if (uVar2 < 0x105 || bVar8) {
      if (uVar2 == 6) {
        if (*(char *)((long)param_1 + 0x25) == '\0') {
          if (*(char *)((long)param_1 + 0x26) == '\0') {
            *puVar4 = (*(char *)((long)param_1 + 0x24) == '\0') + 3;
          }
          else {
            *puVar4 = 2;
          }
        }
        else {
          *puVar4 = 1;
        }
      }
      else if (uVar2 < 7) {
        if (uVar2 == 3) {
          uVar2 = nvswitch_reg_read_32(param_1);
          *puVar4 = uVar2 >> 0x10 & 0xf;
        }
        else if (uVar2 < 4) {
          if (uVar2 == 1) {
            *puVar4 = *(uint *)((long)param_1 + 0x1f84);
          }
          else {
            if (uVar2 != 2) break;
            uVar2 = nvswitch_reg_read_32(param_1);
            *puVar4 = uVar2 >> 0x14 & 0x1ff;
          }
        }
        else if (uVar2 == 4) {
          uVar2 = nvswitch_reg_read_32(param_1);
          *puVar4 = uVar2 >> 0xc & 0xf;
        }
        else {
          uVar2 = nvswitch_reg_read_32(param_1);
          *puVar4 = uVar2 >> 8 & 0xf;
        }
      }
      else if (uVar2 == 0x102) {
        nvswitch_get_enabled_link_mask(param_1);
        *puVar4 = extraout_var;
      }
      else if (uVar2 < 0x103) {
        if (uVar2 == 0x100) {
          uVar2 = nvswitch_get_num_links(param_1);
          *puVar4 = uVar2;
        }
        else if (uVar2 == 0x101) {
          uVar2 = nvswitch_get_enabled_link_mask(param_1);
          *puVar4 = uVar2;
        }
        else {
          if (uVar2 != 7) goto LAB_001e8d80;
          *puVar4 = *(uint *)(*param_1 + 0x48);
        }
      }
      else {
        if (uVar2 != 0x103) {
          uVar5 = 0;
          goto LAB_001e8be9;
        }
        *puVar4 = 8;
      }
    }
    else if (uVar2 == 0x202) {
      uVar6 = 0xfffffff3;
    }
    else if (uVar2 < 0x203) {
      if (uVar2 == 0x109) {
        uVar5 = 3;
      }
      else {
        if (0x109 < uVar2) {
          if (uVar2 == 0x200) {
            *puVar4 = *(uint *)((long)param_1 + 0x1f7c);
          }
          else {
            if (uVar2 != 0x201) goto LAB_001e8d80;
            *puVar4 = *(uint *)(param_1 + 0x3ef);
          }
          goto LAB_001e8ba0;
        }
        if (uVar2 == 0x107) {
          uVar5 = 1;
        }
        else {
          if (uVar2 != 0x108) {
            uVar2 = nvswitch_get_ingress_ram_size(param_1,2);
            *puVar4 = uVar2;
            goto LAB_001e8ba0;
          }
          uVar5 = 2;
        }
      }
LAB_001e8be9:
      iVar1 = nvswitch_get_remap_table_selector(param_1,uVar5,local_3c);
      uVar2 = 0;
      if (iVar1 == 0) {
        uVar2 = nvswitch_get_ingress_ram_size(param_1);
        *puVar4 = uVar2;
      }
      else {
LAB_001e8b6e:
        *puVar4 = uVar2;
      }
    }
    else if (uVar2 == 0x301) {
      *puVar4 = (uint)*(byte *)(*param_1 + 0x44);
    }
    else if (uVar2 < 0x302) {
      if (uVar2 == 0x203) {
        uVar2 = nvswitch_read_physical_id(param_1);
        *puVar4 = uVar2;
      }
      else if (uVar2 == 0x300) {
        *puVar4 = *(uint *)(*param_1 + 0x40);
      }
      else {
LAB_001e8d80:
        uVar6 = 0xffffffff;
      }
    }
    else {
      if (uVar2 != 0x302) {
        if (uVar2 != 0x303) goto LAB_001e8d80;
        uVar2 = (uint)*(byte *)(*param_1 + 0x46);
        goto LAB_001e8b6e;
      }
      *puVar4 = (uint)*(byte *)(*param_1 + 0x45);
    }
LAB_001e8ba0:
    while( true ) {
      uVar7 = uVar7 + 1;
      puVar4 = puVar3 + 1;
      if (*param_2 <= uVar7) {
        return uVar6;
      }
      uVar2 = puVar3[-0x1f];
      bVar8 = uVar2 == 0x105;
      if (!bVar8) break;
LAB_001e8bc0:
      uVar2 = nvswitch_get_ingress_ram_size(param_1);
      *puVar4 = uVar2;
      puVar3 = puVar4;
    }
  } while( true );
  uVar7 = uVar7 + 1;
  puVar3 = puVar4 + 1;
  *puVar4 = *(uint *)(param_1 + 0x3f0);
  if (*param_2 <= uVar7) {
    return uVar6;
  }
  goto LAB_001e89e7;
}


// ===== 001e8dd0 nvswitch_post_init_blacklist_device_setup_lr10 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_post_init_blacklist_device_setup_lr10(long param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = nvswitch_is_inforom_supported();
  if (cVar1 != '\0') {
    nvswitch_inforom_post_init(param_1);
  }
  iVar2 = nvswitch_smbpbi_post_init(param_1);
  if (iVar2 == 0) {
    (**(code **)(param_1 + 0x830))(param_1);
    return;
  }
  return;
}


// ===== 001e8e30 nvswitch_fsp_process_nvdm_msg_lr10 =====

undefined8 nvswitch_fsp_process_nvdm_msg_lr10(void)

{
  return 0xfffffff3;
}


// ===== 001e8e40 nvswitch_fsp_process_cmd_response_lr10 =====

undefined8 nvswitch_fsp_process_cmd_response_lr10(void)

{
  return 0xfffffff3;
}


