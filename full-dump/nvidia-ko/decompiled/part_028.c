// ===== 002b8780 gpuJtVersionSanityCheck_TU102 =====

undefined8 gpuJtVersionSanityCheck_TU102(long param_1)

{
  if ((*(char *)(param_1 + 0x446) == '\0') && (*(char *)(param_1 + 0x490e) == '\0')) {
    if ((*(uint *)(param_1 + 0x2268) & 1) == 0) {
      return 0;
    }
    if (*(short *)(param_1 + 0x226c) != 0x200) {
      nvDbg_Printf("src/kernel/gpu/arch/turing/kern_gpu_tu102.c",0xfd,
                   "gpuJtVersionSanityCheck_TU102",4,"NVRM: JT Version mismatch 0x%x\n");
      return 0x3b;
    }
  }
  return 0;
}


// ===== 002b8800 gpuGetRegBaseOffset_TU102 =====

undefined8 gpuGetRegBaseOffset_TU102(long param_1,int param_2,int *param_3)

{
  if (param_2 == 2) {
    *param_3 = 0x9000;
    return 0;
  }
  if (param_2 == 4) {
    *param_3 = *(int *)(param_1 + 0x3a64) + 0x30000;
    return 0;
  }
  return 0x56;
}


// ===== 002b8840 gpuSanityCheckVirtRegAccess_TU102 =====

undefined8 gpuSanityCheckVirtRegAccess_TU102(long param_1,uint param_2)

{
  if ((((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) &&
      (0xfff < param_2 - 0x88000)) && ((0xfffe < param_2 - 0x30000 && (0x2fffe < param_2)))) {
    return 0x1e;
  }
  return 0;
}


// ===== 002b8890 gpuCheckEccCounts_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gpuCheckEccCounts_TU102(long param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  int local_30;
  int local_2c [3];
  
  local_30 = 0;
  local_2c[0] = 0;
  (**(code **)(*(long *)(param_1 + 0x1b70) + 0x260))
            (param_1,*(long *)(param_1 + 0x1b70),&local_30,local_2c);
  iVar1 = (**(code **)(*(long *)(param_1 + 0x1b98) + 0x4f8))(param_1);
  iVar2 = (**(code **)(*(long *)(param_1 + 7000) + 0x368))(param_1);
  iVar3 = (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x538))(param_1);
  if ((local_30 + local_2c[0] + iVar1 + iVar2 + iVar3 == 0) &&
     (uVar4 = (**(code **)(param_1 + 0x308))(param_1), (char)uVar4 == '\0')) {
    return uVar4;
  }
  nvErrorLog_va(param_1,0x8c,
                "An uncorrectable ECC error detected (possible firmware handling failure) DRAM:%d, LTC:%d, MMU:%d, PCIE:%d"
                ,local_30,local_2c[0],iVar1,iVar2 + iVar3);
  return 1;
}


// ===== 002b8988 gpuWaitForGfwBootComplete_TU102.cold =====

void gpuWaitForGfwBootComplete_TU102_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002b89a0 gpuWaitForGfwBootComplete_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gpuWaitForGfwBootComplete_TU102(long param_1)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  
  if (*(long *)(param_1 + 0x1ba8) == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar1 = *(long *)(*(long *)(param_1 + 0x1ba8) + 2000);
  iVar4 = (**(code **)(lVar1 + 0x538))(param_1,lVar1,*(int *)(param_1 + 0x1b08) * 0x1f47d0,8);
  uVar5 = regRead032(param_1 + 0x3a18,0,0,0x118128,0);
  if ((uVar5 & 1) == 0) {
    cVar3 = '\0';
    cVar6 = '\0';
    if (iVar4 != 0) goto LAB_002b8a78;
  }
  else {
    cVar3 = regRead032(param_1 + 0x3a18,0,0,0x118234,0);
    if (iVar4 != 0) {
LAB_002b8a78:
      nvDbg_Printf("src/kernel/gpu/arch/turing/kern_gpu_tu102.c",0x1d4,
                   "gpuWaitForGfwBootComplete_TU102",4,
                   "NVRM: GSP failed to halt with GFW_BOOT: (progress 0x%x)\n",cVar3);
      return iVar4;
    }
    cVar6 = cVar3;
    if (cVar3 == -1) {
      return 0;
    }
  }
  nvDbg_Printf("src/kernel/gpu/arch/turing/kern_gpu_tu102.c",0x1da,"gpuWaitForGfwBootComplete_TU102"
               ,4,"NVRM: failed to wait for GFW_BOOT: (progress 0x%x)\n",cVar6);
  return 0x55;
}


// ===== 002b8ac0 gpuIsMsixAllowed_TU102 =====

uint gpuIsMsixAllowed_TU102(long param_1)

{
  long lVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  
  lVar1 = osMapKernelSpace(param_1 + 0x118000,0x1000,1,1);
  if (lVar1 != 0) {
    iVar4 = 0x802;
    do {
      uVar3 = 0;
      if (((*(uint *)(lVar1 + 0x128) & 1) != 0) &&
         (uVar3 = *(uint *)(lVar1 + 0x234) & 0xff, uVar3 == 0xff)) {
        osUnmapKernelSpace(lVar1,0x1000);
        puVar2 = (uint *)osMapKernelSpace(param_1 + 0x8841c,4,1,1);
        if (puVar2 == (uint *)0x0) {
          return 0;
        }
        uVar3 = *puVar2;
        osUnmapKernelSpace(puVar2,4);
        return uVar3 >> 0x1d & 1 ^ 1;
      }
      osDelayUs(1000);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    osUnmapKernelSpace(lVar1,0x1000);
    nvDbg_Printf("src/kernel/gpu/arch/turing/kern_gpu_tu102.c",0x218,"gpuIsMsixAllowed_TU102",4,
                 "NVRM: failed to wait for GFW_BOOT: (progress 0x%x)\n",uVar3);
  }
  return 0;
}


// ===== 002b8bf0 gpuReadPBusScratch_TU102 =====

void gpuReadPBusScratch_TU102(long param_1,byte param_2)

{
  regRead032(param_1 + 0x3a18,0,0,(uint)param_2 * 4 + 0x1400,0);
  return;
}


// ===== 002b8c20 gpuWritePBusScratch_TU102 =====

void gpuWritePBusScratch_TU102(long param_1,byte param_2,undefined4 param_3)

{
  regWrite032(param_1 + 0x3a18,0,0,(uint)param_2 * 4 + 0x1400,param_3,0);
  return;
}


// ===== 002b8c50 hdacodecConstruct_IMPL =====

undefined8 hdacodecConstruct_IMPL(void)

{
  return 0;
}


// ===== 002b8c60 _kbifPreOsCheckErotGrantAllowed_AD102 =====

uint _kbifPreOsCheckErotGrantAllowed_AD102(long param_1)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x1400,0);
  return uVar1 >> 5 & 1;
}


// ===== 002b8c90 kbifPreOsGlobalErotGrantRequest_AD102 =====

int kbifPreOsGlobalErotGrantRequest_AD102(long param_1)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x1400,0);
  iVar2 = 0;
  if ((uVar1 & 8) != 0) {
    uVar3 = regRead032(param_1 + 0x3a18,0,0,0x1400,0);
    iVar2 = 0;
    if ((uVar3 & 0x20) == 0) {
      regWrite032(param_1 + 0x3a18,0,0,0x1400,uVar1 | 0x10,0);
      iVar2 = timeoutCondWait(param_1 + 0x1af0,0,_kbifPreOsCheckErotGrantAllowed_AD102,0,0x49);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/gpu/bif/arch/ada/kernel_bif_ad102.c",0x4c,
                     "kbifPreOsGlobalErotGrantRequest_AD102",4,
                     "NVRM: Timed out waiting for preOs to grant access to EEPROM\n");
      }
    }
  }
  return iVar2;
}


// ===== 002b8d70 kbifInitXveRegMap_AD102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifInitXveRegMap_AD102(undefined8 param_1,long param_2,char param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (param_3 != '\0') {
    if (param_3 != '\x01') {
      nvDbg_Printf("src/kernel/gpu/bif/arch/ada/kernel_bif_ad102.c",0x80,"kbifInitXveRegMap_AD102",4
                   ,"NVRM: Invalid argument, func: %d.\n",param_3);
      nvAssertFailedNoLog(&DAT_00cf1fbb,"src/kernel/gpu/bif/arch/ada/kernel_bif_ad102.c",0x81);
      return 0x1f;
    }
    uVar2 = kbifInitXveRegMap_GM107(param_1,param_2,1);
    return uVar2;
  }
  *(long *)(param_2 + 0x2418) = param_2 + 0x3d0;
  *(undefined1 *)(param_2 + 0x2414) = 0;
  *(undefined1 **)(param_2 + 0x2400) = xveRegMapValid;
  *(undefined1 **)(param_2 + 0x2408) = xveRegMapWrite;
  *(undefined4 *)(param_2 + 0x2410) = 0x200020;
  iVar1 = (**(code **)(param_2 + 0x298))();
  if (*(long *)(param_2 + 0x2420) == 0) {
    lVar3 = portMemAllocNonPaged((ulong)(uint)(iVar1 * 4) << 2);
    *(long *)(param_2 + 0x2420) = lVar3;
    if (lVar3 == 0) {
      nvAssertFailedNoLog("pKernelBif->xveRegmapRef[0].bufMsixTable != NULL",
                          "src/kernel/gpu/bif/arch/ada/kernel_bif_ad102.c",0x77);
      return 0x51;
    }
  }
  return 0;
}


// ===== 002b8e90 kbifInitXveRegMap_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifInitXveRegMap_GA100(undefined8 param_1,long param_2,char param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (param_3 != '\0') {
    if (param_3 != '\x01') {
      nvDbg_Printf("src/kernel/gpu/bif/arch/ampere/kernel_bif_ga100.c",0x58,
                   "kbifInitXveRegMap_GA100",4,"NVRM: Invalid argument, func: %d.\n",param_3);
      nvAssertFailedNoLog(&DAT_00cf21b3,"src/kernel/gpu/bif/arch/ampere/kernel_bif_ga100.c",0x59);
      return 0x1f;
    }
    uVar2 = kbifInitXveRegMap_GM107(param_1,param_2,1);
    return uVar2;
  }
  *(long *)(param_2 + 0x2418) = param_2 + 0x3d0;
  *(undefined1 *)(param_2 + 0x2414) = 0;
  *(undefined1 **)(param_2 + 0x2400) = xveRegMapValid;
  *(undefined1 **)(param_2 + 0x2408) = xveRegMapWrite;
  *(undefined4 *)(param_2 + 0x2410) = 0x200020;
  iVar1 = (**(code **)(param_2 + 0x298))();
  if (*(long *)(param_2 + 0x2420) == 0) {
    lVar3 = portMemAllocNonPaged((ulong)(uint)(iVar1 * 4) << 2);
    *(long *)(param_2 + 0x2420) = lVar3;
    if (lVar3 == 0) {
      nvAssertFailedNoLog("pKernelBif->xveRegmapRef[0].bufMsixTable != NULL",
                          "src/kernel/gpu/bif/arch/ampere/kernel_bif_ga100.c",0x4f);
      return 0x51;
    }
  }
  return 0;
}


// ===== 002b8fb0 kbifInitRelaxedOrderingFromEmulatedConfigSpace_GA100 =====

void kbifInitRelaxedOrderingFromEmulatedConfigSpace_GA100(long param_1,long param_2)

{
  ulong uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar1 = *(ulong *)(param_1 + 0x878);
  uVar3 = osPciInitHandle(uVar1 >> 0x20,uVar1 >> 8 & 0xff,uVar1 & 0xff,0,0,0);
  uVar2 = osPciReadDword(uVar3,0xe8);
  *(byte *)(param_2 + 0x3ae) = (byte)(uVar2 >> 4) & 1;
  return;
}


// ===== 002b9000 kbifCache64bBar0Support_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifCache64bBar0Support_GA100(long param_1,long param_2)

{
  int iVar1;
  uint local_1c [3];
  
  local_1c[0] = 0;
  iVar1 = (**(code **)(param_1 + 0x178))(param_1,0x898,local_1c);
  if (iVar1 == 0) {
    if ((local_1c[0] & 0x80000) != 0) {
      *(undefined1 *)(param_2 + 0x3b1) = 1;
    }
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/ampere/kernel_bif_ga100.c",0x8b,
               "kbifCache64bBar0Support_GA100",4,"NVRM: Unable to read NV_XVE_DBG_CYA_0\n");
  return;
}


// ===== 002b9080 kbifRestoreBar0_GA100 =====

void kbifRestoreBar0_GA100(undefined8 param_1,long param_2,undefined8 param_3,long param_4)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x245c);
  osPciWriteDword(param_3,*(uint *)(param_2 + 0x2458),
                  *(undefined4 *)(param_4 + (ulong)(*(uint *)(param_2 + 0x2458) >> 2) * 4));
  if (*(char *)(param_2 + 0x3b1) == '\0') {
    return;
  }
  osPciWriteDword(param_3,uVar1,*(undefined4 *)(param_4 + (ulong)(uVar1 >> 2) * 4));
  return;
}


// ===== 002b90f0 kbifAnyBarsAreValid_GA100 =====

bool kbifAnyBarsAreValid_GA100(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ulong uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined1 local_3c [2];
  undefined1 local_3a [10];
  
  uVar1 = *(uint *)(param_2 + 0x245c);
  uVar5 = *(ulong *)(param_1 + 0x878);
  uVar2 = *(uint *)(param_2 + 0x2458);
  uVar3 = *(uint *)(param_2 + 0x2460);
  uVar4 = *(uint *)(param_2 + 0x2464);
  uVar7 = osPciInitHandle(uVar5 >> 0x20,uVar5 >> 8 & 0xff,uVar5 & 0xff,0,local_3c,local_3a);
  if (*(char *)(param_2 + 0x3b1) == '\0') {
    iVar6 = osPciReadDword(uVar7,uVar2);
    if (iVar6 == *(int *)(param_2 + 0x3d0 + (ulong)(uVar2 >> 2) * 4)) {
      return true;
    }
  }
  else {
    iVar6 = osPciReadDword(uVar7,uVar2);
    if ((iVar6 == *(int *)(param_2 + 0x3d0 + (ulong)(uVar2 >> 2) * 4)) &&
       (iVar6 = osPciReadDword(uVar7,uVar1),
       iVar6 == *(int *)(param_2 + 0x3d0 + (ulong)(uVar1 >> 2) * 4))) {
      return true;
    }
  }
  iVar6 = osPciReadDword(uVar7,uVar3);
  if (iVar6 != *(int *)(param_2 + 0x3d0 + (ulong)(uVar3 >> 2) * 4)) {
    return false;
  }
  iVar6 = osPciReadDword(uVar7,uVar4);
  return *(int *)(param_2 + 0x3d0 + (ulong)(uVar4 >> 2) * 4) == iVar6;
}


// ===== 002b9220 kbifRestoreBarsAndCommand_GA100 =====

undefined8 kbifRestoreBarsAndCommand_GA100(long param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  undefined8 uVar4;
  uint *puVar5;
  undefined1 local_3c [2];
  undefined1 local_3a [10];
  
  puVar5 = (uint *)(param_2 + 0x2458);
  uVar2 = *(ulong *)(param_1 + 0x878);
  uVar4 = osPciInitHandle(uVar2 >> 0x20,uVar2 >> 8 & 0xff,uVar2 & 0xff,0,local_3c,local_3a);
  do {
    uVar1 = *puVar5;
    if (uVar1 != 0xffff) {
      osPciWriteDword(uVar4,uVar1,*(undefined4 *)(param_2 + 0x3d0 + (ulong)(uVar1 >> 2) * 4));
    }
    puVar5 = puVar5 + 1;
  } while (puVar5 != (uint *)(param_2 + 0x2474));
  osPciWriteDword(uVar4,4,*(undefined4 *)(param_2 + 0x3d4));
  iVar3 = regRead032(param_1 + 0x3a18,0,0,0,0);
  uVar4 = 0x42;
  if (iVar3 == *(int *)(param_1 + 0x8e8)) {
    uVar4 = 0;
  }
  return uVar4;
}


// ===== 002b92f0 kbifStoreBarRegOffsets_GA100 =====

void kbifStoreBarRegOffsets_GA100(undefined8 param_1,long param_2,int param_3)

{
  long lVar1;
  int iVar2;
  
  lVar1 = 0;
  while (iVar2 = param_3, lVar1 != 6) {
    while( true ) {
      *(int *)(param_2 + 0x2458 + lVar1 * 4) = iVar2;
      lVar1 = lVar1 + 1;
      param_3 = iVar2 + 4;
      if (lVar1 != 1) break;
      if (*(char *)(param_2 + 0x3b1) == '\0') {
        *(int *)(param_2 + 0x245c) = param_3;
        lVar1 = 2;
        iVar2 = iVar2 + 8;
      }
      else {
        *(undefined4 *)(param_2 + 0x245c) = 0xffff;
        lVar1 = 2;
        iVar2 = param_3;
      }
    }
  }
  if (*(char *)(param_2 + 0x3b1) != '\0') {
    *(undefined4 *)(param_2 + 0x2470) = 0xffff;
    return;
  }
  *(int *)(param_2 + 0x2470) = param_3;
  return;
}


// ===== 002b9370 kbifPrepareForFullChipReset_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifPrepareForFullChipReset_GA100(long param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar1 = *(undefined8 *)(&DAT_00001b90 + param_1);
  uVar2 = *(undefined8 *)(param_1 + 0x1b60);
  lVar3 = *(long *)(g_pSys + 0x208);
  if ((*(char *)(param_2 + 0x3b0) != '\0') && (*(char *)(param_2 + 0x23f4) == '\0')) {
    lVar4 = *(long *)(param_1 + 0x1ce8);
    if ((lVar4 != 0) &&
       ((*(char *)(lVar4 + 0x2e0) != '\0' &&
        (iVar5 = knvlinkPrepareForXVEReset_IMPL(param_1,lVar4,0), iVar5 != 0)))) {
      nvDbg_Printf("src/kernel/gpu/bif/arch/ampere/kernel_bif_ga100.c",0x1a3,
                   "kbifPrepareForFullChipReset_GA100",4,
                   "NVRM: NVLINK prepare for fullchip reset failed.\n");
    }
    if (*(char *)(param_2 + 0x3b7) == '\0') goto LAB_002b9445;
  }
  *(undefined1 *)(param_1 + 0x4b6) = 1;
  iVar5 = kbusPrepareForXVEReset_GM107(param_1,uVar1);
  if (iVar5 != 0) {
    nvDbg_Printf("src/kernel/gpu/bif/arch/ampere/kernel_bif_ga100.c",0x1c4,
                 "kbifPrepareForFullChipReset_GA100",4,"NVRM: BUS prepare for devinit failed.\n");
  }
  iVar5 = (**(code **)(param_2 + 0x338))(param_1,param_2);
  if (iVar5 != 0) {
    nvDbg_Printf("src/kernel/gpu/bif/arch/ampere/kernel_bif_ga100.c",0x1cb,
                 "kbifPrepareForFullChipReset_GA100",4,"NVRM: BIF prepare for devinit failed.\n");
  }
  uVar6 = regRead032(param_1 + 0x3a18,0,0,0x200,0);
  uVar7 = regRead032(param_1 + 0x3a18,0,0,0x600,0);
  (**(code **)(param_2 + 0x348))(param_1,param_2,uVar2);
  if (*(char *)(lVar3 + 0x48) == '\0') {
    regWrite032(param_1 + 0x3a18,0,0,0x200,uVar6,0);
    regWrite032(param_1 + 0x3a18,0,0,0x600,uVar7,0);
  }
LAB_002b9445:
  *(undefined1 *)(param_1 + 0x4b6) = 0;
  return;
}


// ===== 002b9570 kbifResetHostEngines_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void kbifResetHostEngines_GA100(long param_1,long param_2,long param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_2 + 0x350))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(param_3 + 0x168))(param_1,param_3,iVar1,0,0,*(code **)(param_3 + 0x168));
    if (iVar1 != 0) {
      nvAssertOkFailedNoLog
                (iVar1,"kmcWritePmcEnableReg_HAL(pGpu, pKernelMc, engineMask, NV_FALSE, NV_FALSE)",
                 "src/kernel/gpu/bif/arch/ampere/kernel_bif_ga100.c",0x1f9);
    }
  }
  iVar1 = (**(code **)(param_2 + 0x358))(param_1,param_2);
  if (iVar1 != 0) {
    iVar1 = (**(code **)(param_3 + 0x168))
                      (param_1,param_3,iVar1,0,*(undefined1 *)(param_1 + 0x4a7b),
                       *(code **)(param_3 + 0x168));
    if (iVar1 != 0) {
      nvAssertOkFailedNoLog
                (iVar1,
                 "kmcWritePmcEnableReg_HAL(pGpu, pKernelMc, engineMask, NV_FALSE, gpuIsUsePmcDeviceEnableForHostEngineEnabled(pGpu))"
                 ,"src/kernel/gpu/bif/arch/ampere/kernel_bif_ga100.c",0x205);
      return;
    }
  }
  return;
}


// ===== 002b9650 kbifGetValidEnginesToReset_GA100 =====

undefined8 kbifGetValidEnginesToReset_GA100(void)

{
  return 0x50000000;
}


// ===== 002b9660 kbifGetValidDeviceEnginesToReset_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kbifGetValidDeviceEnginesToReset_GA100(undefined8 param_1)

{
  sbyte sVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  uint local_3c [3];
  
  lVar4 = gpuGetKernelFifoShared_IMPL();
  iVar2 = (**(code **)(lVar4 + 0x240))(param_1,lVar4);
  if (iVar2 == 0) {
    return 0;
  }
  uVar3 = 0;
  iVar5 = 0;
  do {
    while (iVar6 = (**(code **)(lVar4 + 0x218))(param_1,lVar4,0xf,iVar5,6,local_3c), iVar6 == 0) {
      iVar5 = iVar5 + 1;
      sVar1 = (sbyte)(local_3c[0] & 0x1f);
      uVar3 = ~((0xffffffffU >> ((~(byte)local_3c[0] & 0x1f) + sVar1 & 0x1f)) << sVar1) & uVar3 |
              1 << (local_3c[0] & 0x1f);
      if (iVar5 == iVar2) {
        return uVar3;
      }
    }
    iVar6 = iVar5 + 1;
    nvDbg_Printf("src/kernel/gpu/bif/arch/ampere/kernel_bif_ga100.c",0x242,
                 "kbifGetValidDeviceEnginesToReset_GA100",4,
                 "NVRM: Unable to get Reset index for engine ID (%u)\n",iVar5);
    iVar5 = iVar6;
  } while (iVar6 != iVar2);
  return uVar3;
}


// ===== 002b9770 kbifGetMigrationBandwidth_GA100 =====

undefined8
kbifGetMigrationBandwidth_GA100(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  *param_3 = 500;
  return 0;
}


// ===== 002b9780 kbifDoFullChipReset_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbifDoFullChipReset_GA100(long param_1,long param_2)

{
  ulong uVar1;
  
  if ((*(char *)(param_2 + 0x3b0) == '\0') || (*(char *)(param_2 + 0x23f4) != '\0')) {
    nvDbg_Printf("src/kernel/gpu/bif/arch/ampere/kernel_bif_ga100.c",0x28b,
                 "kbifDoFullChipReset_GA100",4,"NVRM: FLR is either not supported or is disabled.\n"
                );
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(param_2 + 0x288))();
    if ((int)uVar1 != 0) {
      nvAssertOkFailedNoLog
                (uVar1 & 0xffffffff,"status = kbifDoFunctionLevelReset_HAL(pGpu, pKernelBif)",
                 "src/kernel/gpu/bif/arch/ampere/kernel_bif_ga100.c",0x287);
      uVar1 = uVar1 & 0xffffffff;
    }
  }
  *(undefined1 *)(param_1 + 0x44f) = 1;
  return uVar1;
}


// ===== 002b9820 kbifClearDownstreamReadCounter_GA100 =====

uint kbifClearDownstreamReadCounter_GA100(long param_1)

{
  undefined8 uVar1;
  ulong uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined1 local_1c [2];
  undefined1 local_1a [2];
  
  uVar1 = *(undefined8 *)(g_pSys + 0x208);
  uVar2 = *(ulong *)(param_1 + 0x878);
  uVar4 = osPciInitHandle(uVar2 >> 0x20,uVar2 >> 8 & 0xff,uVar2 & 0xff,0,local_1c,local_1a);
  uVar3 = osPciReadDword(uVar4,0x84c);
  uVar2 = *(ulong *)(param_1 + 0x878);
  clPcieWriteDword_IMPL(uVar1,uVar2 >> 0x20,uVar2 >> 8 & 0xff,uVar2 & 0xff,0,0x84c);
  return uVar3 | 0x200;
}


// ===== 002b98b0 kbifInitXveRegMap_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifInitXveRegMap_GA102(undefined8 param_1,long param_2,char param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (param_3 != '\0') {
    if (param_3 != '\x01') {
      nvDbg_Printf("src/kernel/gpu/bif/arch/ampere/kernel_bif_ga102.c",0x4f,
                   "kbifInitXveRegMap_GA102",4,"NVRM: Invalid argument, func: %d.\n",param_3);
      nvAssertFailedNoLog(&DAT_00cf2653,"src/kernel/gpu/bif/arch/ampere/kernel_bif_ga102.c",0x50);
      return 0x1f;
    }
    uVar2 = kbifInitXveRegMap_GM107(param_1,param_2,1);
    return uVar2;
  }
  *(long *)(param_2 + 0x2418) = param_2 + 0x3d0;
  *(undefined1 *)(param_2 + 0x2414) = 0;
  *(undefined1 **)(param_2 + 0x2400) = xveRegMapValid;
  *(undefined1 **)(param_2 + 0x2408) = xveRegMapWrite;
  *(undefined4 *)(param_2 + 0x2410) = 0x200020;
  iVar1 = (**(code **)(param_2 + 0x298))();
  if (*(long *)(param_2 + 0x2420) == 0) {
    lVar3 = portMemAllocNonPaged((ulong)(uint)(iVar1 * 4) << 2);
    *(long *)(param_2 + 0x2420) = lVar3;
    if (lVar3 == 0) {
      nvAssertFailedNoLog("pKernelBif->xveRegmapRef[0].bufMsixTable != NULL",
                          "src/kernel/gpu/bif/arch/ampere/kernel_bif_ga102.c",0x46);
      return 0x51;
    }
  }
  return 0;
}


// ===== 002b99d0 _kbifGetBarInfo_GB100.constprop.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _kbifGetBarInfo_GB100_constprop_0(long param_1,int param_2,ulong *param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint local_40;
  undefined4 local_3c [3];
  
  iVar6 = 0;
  uVar5 = 0x324;
  local_40 = 0;
  local_3c[0] = 0;
  while( true ) {
    iVar2 = (**(code **)(param_1 + 0x1b0))(param_1,uVar5,&local_40);
    uVar1 = local_40;
    if (iVar2 != 0) {
      return iVar2;
    }
    uVar4 = local_40 & 6;
    if (param_2 == iVar6) break;
    uVar5 = uVar5 + 4 + (uint)(uVar4 == 4) * 4;
    if (0x337 < uVar5) {
      return 0x2c;
    }
    iVar6 = iVar6 + 1;
  }
  uVar3 = (ulong)(local_40 & 0xfffffff0);
  if (uVar4 == 4) {
    iVar6 = (**(code **)(param_1 + 0x1b0))(param_1,uVar5 + 4,local_3c);
    if (iVar6 != 0) {
      nvAssertFailedNoLog("(status == NV_OK)","src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c"
                          ,0x460);
      return iVar6;
    }
    uVar3 = CONCAT44(local_3c[0],uVar1) & 0xfffffffffffffff0;
  }
  *param_3 = uVar3;
  *(bool *)param_4 = uVar4 == 4;
  return 0;
}


// ===== 002b9af0 kbifIsMSIXEnabledInHW_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kbifIsMSIXEnabledInHW_GB100(long param_1)

{
  int iVar1;
  uint local_1c [3];
  
  if (*(char *)(param_1 + 0x908) != '\0') {
    return (uint)*(byte *)(param_1 + 0x4913);
  }
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x7c,local_1c);
  if (iVar1 == 0) {
    return local_1c[0] >> 0x1f;
  }
  nvAssertFailedNoLog("Unable to read NV_PF0_MSIX_CAPABILITY_HEADR_AND_CONTROL\n",
                      "src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x47);
  return 0;
}


// ===== 002b9b70 kbifIs3dController_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

bool kbifIs3dController_GB100(long param_1)

{
  int iVar1;
  undefined1 local_c [3];
  char local_9;
  
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,8,local_c);
  return local_9 == '\0' && iVar1 == 0;
}


// ===== 002b9ba0 kbifEnableExtendedTagSupport_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifEnableExtendedTagSupport_GB100(long param_1)

{
  long lVar1;
  int iVar2;
  uint local_1c;
  
  lVar1 = *(long *)(g_pSys + 0x208);
  iVar2 = (**(code **)(param_1 + 0x1b0))(param_1,0x44,&local_1c);
  if (iVar2 == 0) {
    local_1c = local_1c >> 5 & 1;
    if ((local_1c != 0) && (*(char *)(lVar1 + 0x58) == '\0')) {
      iVar2 = (**(code **)(param_1 + 0x1b0))(param_1,0x48,&local_1c);
      if (iVar2 == 0) {
        local_1c = local_1c | 0x100;
        iVar2 = (**(code **)(param_1 + 0x1b8))(param_1,0x48);
        if (iVar2 != 0) {
          nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x98,
                       "kbifEnableExtendedTagSupport_GB100",1,
                       "NVRM: Unable to write NV_EP_PCFG_GPU_DEVICE_CONTROL_STATUS\n");
        }
      }
      else {
        nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x8e,
                     "kbifEnableExtendedTagSupport_GB100",1,
                     "NVRM: Unable to read NV_PF0_DEVICE_CONTROL_AND_STATUS\n");
      }
    }
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x82,
               "kbifEnableExtendedTagSupport_GB100",4,
               "NVRM: Unable to read NV_PF0_DEVICE_CAPABILITIES\n");
  return;
}


// ===== 002b9cd0 kbifEnableNoSnoop_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbifEnableNoSnoop_GB100(long param_1,undefined8 param_2,char param_3)

{
  int iVar1;
  uint local_1c [3];
  
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x48,local_1c);
  if (iVar1 != 0) {
    nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0xbb,
                 "kbifEnableNoSnoop_GB100",1,
                 "NVRM: Failed to read NV_PF0_DEVICE_CONTROL_AND_STATUS.\n");
    return iVar1;
  }
  local_1c[0] = local_1c[0] & 0xfffff7ff | (uint)(param_3 != '\0') << 0xb;
  iVar1 = (**(code **)(param_1 + 0x1b8))(param_1,0x48);
  if (iVar1 == 0) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",199,"kbifEnableNoSnoop_GB100",
               1,"NVRM: Failed to write NV_PF0_DEVICE_CONTROL_AND_STATUS.\n");
  return iVar1;
}


// ===== 002b9dc0 kbifPcieConfigEnableRelaxedOrdering_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifPcieConfigEnableRelaxedOrdering_GB100(long param_1)

{
  int iVar1;
  uint local_c;
  
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x48,&local_c);
  if (iVar1 != 0xffff) {
    (**(code **)(param_1 + 0x1b8))(param_1,0x48,local_c | 0x10);
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0xe2,
               "kbifPcieConfigEnableRelaxedOrdering_GB100",1,
               "NVRM: Unable to read NV_PF0_DEVICE_CONTROL_AND_STATUS!\n");
  return;
}


// ===== 002b9e40 kbifPcieConfigDisableRelaxedOrdering_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifPcieConfigDisableRelaxedOrdering_GB100(long param_1)

{
  int iVar1;
  uint local_c;
  
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x48,&local_c);
  if (iVar1 != 0xffff) {
    local_c = local_c & 0xffffffef;
    (**(code **)(param_1 + 0x1b8))(param_1,0x48);
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0xff,
               "kbifPcieConfigDisableRelaxedOrdering_GB100",1,
               "NVRM: Unable to read NV_PF0_DEVICE_CONTROL_AND_STATUS!\n");
  return;
}


// ===== 002b9ec0 kbifGetXveStatusBits_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifGetXveStatusBits_GB100(long param_1,long param_2,uint *param_3,uint *param_4)

{
  int iVar1;
  uint local_2c;
  
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x48,&local_2c);
  if (iVar1 != 0) {
    nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x125,
                 "kbifGetXveStatusBits_GB100",1,
                 "NVRM: Unable to read NV_PF0_DEVICE_CONTROL_AND_STATUS!\n");
  }
  if (param_3 == (uint *)0x0) {
    return 0xffff;
  }
  *param_3 = 0;
  if (*(char *)(param_1 + 0x4910) == '\0') {
    if (param_4 != (uint *)0x0) {
      *param_4 = local_2c;
    }
    if ((local_2c & 0x10000) != 0) {
      *param_3 = *param_3 | 1;
    }
    if ((local_2c & 0x20000) != 0) {
      *param_3 = *param_3 | 2;
    }
    if ((local_2c & 0x40000) != 0) {
      *param_3 = *param_3 | 4;
    }
    if ((local_2c & 0x80000) != 0) {
      *param_3 = *param_3 | 8;
    }
    if (*(char *)(param_2 + 0x3cd) != '\0') {
      *(undefined1 *)(param_2 + 0x3cd) = 0;
      *param_3 = *param_3 | 0x10;
    }
  }
  else if (param_4 != (uint *)0x0) {
    *param_4 = 0;
  }
  return 0;
}


// ===== 002b9fe0 kbifClearXveStatus_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifClearXveStatus_GB100(long param_1,undefined8 param_2,int *param_3)

{
  int iVar1;
  int local_c;
  
  if (param_3 == (int *)0x0) {
    iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x48,&local_c);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x17c,
                   "kbifClearXveStatus_GB100",1,
                   "NVRM: Unable to read NV_PF0_DEVICE_CONTROL_AND_STATUS!\n");
    }
  }
  else {
    local_c = *param_3;
    if (local_c == 0) {
      return 0;
    }
  }
  (**(code **)(param_1 + 0x1b8))(param_1,0x48,local_c);
  return 0;
}


// ===== 002ba080 kbifGetXveAerBits_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kbifGetXveAerBits_GB100(long param_1,undefined8 param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint local_20;
  uint local_1c [3];
  
  if (param_3 == (uint *)0x0) {
    uVar2 = 0xffff;
  }
  else {
    uVar2 = 0;
    if (*(char *)(param_1 + 0x4910) == '\0') {
      *param_3 = 0;
      iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x14c,&local_20);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x158,local_1c);
        if (iVar1 == 0) {
          if ((local_20 & 0x10) != 0) {
            *param_3 = *param_3 | 2;
          }
          if ((local_20 & 0x1000) != 0) {
            *param_3 = *param_3 | 4;
          }
          if ((local_20 & 0x4000) != 0) {
            *param_3 = *param_3 | 0x10;
          }
          if ((local_20 & 0x10000) != 0) {
            *param_3 = *param_3 | 0x40;
          }
          if ((local_20 & 0x40000) != 0) {
            *param_3 = *param_3 | 0x100;
          }
          if ((local_20 & 0x100000) != 0) {
            *param_3 = *param_3 | 0x400;
          }
          if ((local_1c[0] & 1) != 0) {
            *param_3 = *param_3 | 0x10000;
          }
          if ((local_1c[0] & 0x40) != 0) {
            *param_3 = *param_3 | 0x20000;
          }
          if ((local_1c[0] & 0x80) != 0) {
            *param_3 = *param_3 | 0x40000;
          }
          if ((local_1c[0] & 0x100) != 0) {
            *param_3 = *param_3 | 0x80000;
          }
          if ((local_1c[0] & 0x1000) != 0) {
            *param_3 = *param_3 | 0x100000;
          }
          if ((local_1c[0] & 0x2000) != 0) {
            *param_3 = *param_3 | 0x200000;
          }
          return 0;
        }
        nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x1b0,
                     "kbifGetXveAerBits_GB100",1,
                     "NVRM: Unable to read NV_PF0_CORRECTABLE_ERROR_STATUS\n");
      }
      else {
        nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x1a9,
                     "kbifGetXveAerBits_GB100",1,
                     "NVRM: Unable to read NV_PF0_UNCORRECTABLE_ERROR_STATUS\n");
      }
      return 0xffff;
    }
  }
  return uVar2;
}


// ===== 002ba1f0 kbifGetIdeInfo_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kbifGetIdeInfo_GB100(long param_1,undefined8 param_2,uint param_3)

{
  int iVar1;
  uint local_c;
  
  if (param_3 == 0xc) {
    iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x154,&local_c);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x27f,
                   "kbifGetIdeInfo_GB100",3,
                   "NVRM: Unable to read NV_PF0_UNCORRECTABLE_ERROR_SEVERITY\n");
      return 0;
    }
  }
  else {
    if (0xc < param_3) {
      if (param_3 == 0x10) {
        iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x3f4,&local_c);
        if (iVar1 != 0) {
          nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x2a8,
                       "kbifGetIdeInfo_GB100",3,
                       "NVRM: Unable to read NV_PF0_LINK_IDE_STREAM_CONTROL_0\n");
          return 0;
        }
        return local_c & 1;
      }
      if (0x10 < param_3) {
        if (param_3 == 0x11) {
          iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x400,&local_c);
          if (iVar1 != 0) {
            nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x2b4,
                         "kbifGetIdeInfo_GB100",3,
                         "NVRM: Unable to read NV_PF0_SELECTIVE_IDE_STREAM_CONTROL\n");
            return 0;
          }
          return local_c & 1;
        }
        if (param_3 == 0x12) {
          iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x3f0,&local_c);
          if (iVar1 != 0) {
            nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x2c0,
                         "kbifGetIdeInfo_GB100",3,"NVRM: Unable to read NV_PF0_IDE_CONTROL\n");
            return 0;
          }
          return local_c >> 2 & 1;
        }
LAB_002ba568:
        nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x2c9,
                     "kbifGetIdeInfo_GB100",4,"NVRM: Invalid IDE counterType\n");
        return 0;
      }
      if (param_3 == 0xe) {
        iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x154,&local_c);
        if (iVar1 != 0) {
          nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x297,
                       "kbifGetIdeInfo_GB100",3,
                       "NVRM: Unable to read NV_PF0_UNCORRECTABLE_ERROR_SEVERITY\n");
          return 0;
        }
        goto LAB_002ba2bd;
      }
      if (param_3 == 0xf) {
        iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x3f4,&local_c);
        if (iVar1 != 0) {
          nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x1f8,
                       "_kbifGetTlpEncryptionStatus_GB100",3,
                       "NVRM: Unable to read NV_PF0_LINK_IDE_STREAM_CONTROL_0\n");
          return 0;
        }
        if ((local_c & 1) != 0) {
          iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x3f8,&local_c);
          if (iVar1 != 0) {
            nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x201,
                         "_kbifGetTlpEncryptionStatus_GB100",3,
                         "NVRM: Unable to read NV_PF0_LINK_IDE_STREAM_STATUS_0\n");
            return 0;
          }
          return local_c & 0xf;
        }
        iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x400,&local_c);
        if (iVar1 != 0) {
          nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x20b,
                       "_kbifGetTlpEncryptionStatus_GB100",3,
                       "NVRM: Unable to read NV_PF0_SELECTIVE_IDE_STREAM_CONTROL\n");
          return 0;
        }
        if ((local_c & 1) == 0) {
          return 0;
        }
        iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x404,&local_c);
        if (iVar1 == 0) {
          return local_c & 0xf;
        }
        nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x214,
                     "_kbifGetTlpEncryptionStatus_GB100",3,
                     "NVRM: Unable to read NV_PF0_SELECTIVE_IDE_STREAM_STATUS\n");
        return 0;
      }
      iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x154,&local_c);
      if (iVar1 != 0) {
        nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x28b,
                     "kbifGetIdeInfo_GB100",3,
                     "NVRM: Unable to read NV_PF0_UNCORRECTABLE_ERROR_SEVERITY\n");
        return 0;
      }
      goto LAB_002ba245;
    }
    if (param_3 != 9) {
      if (param_3 < 10) {
        if (param_3 != 7) {
          if (param_3 != 8) {
            if (param_3 != 6) goto LAB_002ba568;
            iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x14c,&local_c);
            if (iVar1 != 0) {
              nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x237,
                           "kbifGetIdeInfo_GB100",3,
                           "NVRM: Unable to read NV_PF0_UNCORRECTABLE_ERROR_STATUS\n");
              return 0;
            }
            goto LAB_002ba293;
          }
          iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x14c,&local_c);
          if (iVar1 != 0) {
            nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x24f,
                         "kbifGetIdeInfo_GB100",3,
                         "NVRM: Unable to read NV_PF0_UNCORRECTABLE_ERROR_STATUS\n");
            return 0;
          }
LAB_002ba2bd:
          return local_c >> 0x1e & 1;
        }
        iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x14c,&local_c);
        if (iVar1 != 0) {
          nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x243,
                       "kbifGetIdeInfo_GB100",3,
                       "NVRM: Unable to read NV_PF0_UNCORRECTABLE_ERROR_STATUS\n");
          return 0;
        }
      }
      else {
        if (param_3 != 10) {
          iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x150,&local_c);
          if (iVar1 != 0) {
            nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x273,
                         "kbifGetIdeInfo_GB100",3,
                         "NVRM: Unable to read NV_PF0_UNCORRECTABLE_ERROR_MASK\n");
            return 0;
          }
          goto LAB_002ba2bd;
        }
        iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x150,&local_c);
        if (iVar1 != 0) {
          nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x267,
                       "kbifGetIdeInfo_GB100",3,
                       "NVRM: Unable to read NV_PF0_UNCORRECTABLE_ERROR_MASK\n");
          return 0;
        }
      }
LAB_002ba245:
      return local_c >> 0x1d & 1;
    }
    iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x150,&local_c);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x25b,
                   "kbifGetIdeInfo_GB100",3,"NVRM: Unable to read NV_PF0_UNCORRECTABLE_ERROR_MASK\n"
                  );
      return 0;
    }
  }
LAB_002ba293:
  return local_c >> 0x1c & 1;
}


// ===== 002ba800 kbifClearXveAer_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifClearXveAer_GB100(long param_1,undefined8 param_2,ulong param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = ((uint)param_3 & 2) << 3;
  if ((param_3 & 4) != 0) {
    uVar2 = (uint)CONCAT11(0x10,(char)uVar2);
  }
  if ((param_3 & 0x10) != 0) {
    uVar2 = uVar2 | 0x4000;
  }
  if ((param_3 & 0x40) != 0) {
    uVar2 = uVar2 | 0x10000;
  }
  if ((param_3 & 0x100) != 0) {
    uVar2 = uVar2 | 0x40000;
  }
  if ((param_3 & 0x400) != 0) {
    uVar2 = uVar2 | 0x100000;
  }
  uVar3 = (uint)(param_3 >> 0x10) & 1;
  uVar1 = uVar3 | 0x40;
  if ((param_3 & 0x20000) == 0) {
    uVar1 = uVar3;
  }
  if ((param_3 & 0x40000) != 0) {
    uVar1 = uVar1 | 0x80;
  }
  if ((param_3 & 0x80000) != 0) {
    uVar1 = uVar1 | 0x100;
  }
  if ((param_3 & 0x100000) == 0) {
    if ((param_3 & 0x200000) == 0) {
      if (uVar2 != 0) {
        (**(code **)(param_1 + 0x1b8))(param_1,0x14c);
      }
      if (uVar1 == 0) {
        return 0;
      }
      goto LAB_002ba89c;
    }
LAB_002ba895:
    uVar1 = uVar1 | 0x2000;
  }
  else {
    uVar1 = uVar1 | 0x1000;
    if ((param_3 & 0x200000) != 0) goto LAB_002ba895;
  }
  if (uVar2 != 0) {
    (**(code **)(param_1 + 0x1b8))(param_1,0x14c);
  }
LAB_002ba89c:
  (**(code **)(param_1 + 0x1b8))(param_1,0x158,uVar1);
  return 0;
}


// ===== 002ba920 kbifGetBusOptionsAddr_GB100 =====

undefined8
kbifGetBusOptionsAddr_GB100(undefined8 param_1,undefined8 param_2,uint param_3,undefined4 *param_4)

{
  if (param_3 == 2) {
    *param_4 = 0x4c;
    return 0;
  }
  if (param_3 < 3) {
    if (param_3 != 0) {
      *param_4 = 0x50;
      return 0;
    }
    *param_4 = 0x48;
    return 0;
  }
  if (param_3 == 3) {
    *param_4 = 0x68;
    return 0;
  }
  if (param_3 == 4) {
    *param_4 = 0x348;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x34d,
               "kbifGetBusOptionsAddr_GB100",4,"NVRM: Invalid register type passed 0x%x\n",param_3);
  return 0xffff;
}


// ===== 002ba9c0 kbifEnablePcieAtomics_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifEnablePcieAtomics_GB100(long param_1)

{
  int iVar1;
  uint local_c;
  
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x68,&local_c);
  if (iVar1 != 0) {
    nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x366,
                 "kbifEnablePcieAtomics_GB100",1,"NVRM: Read of NV_PF0_DEVICE_CONTROL_2 failed.\n");
    return;
  }
  local_c = local_c | 0x40;
  iVar1 = (**(code **)(param_1 + 0x1b8))(param_1,0x68);
  if (iVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x372,
                 "kbifEnablePcieAtomics_GB100",1,"NVRM: PCIe Requester atomics enabled.\n");
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x36e,
               "kbifEnablePcieAtomics_GB100",1,"NVRM: Write of NV_PF0_DEVICE_CONTROL_2 failed.\n");
  return;
}


// ===== 002baa90 kbifRestoreBarsAndCommand_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifRestoreBarsAndCommand_GB100(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  uint *puVar4;
  
  puVar4 = (uint *)(param_2 + 0x2458);
  do {
    uVar1 = *puVar4;
    if (uVar1 != 0xffff) {
      (**(code **)(param_1 + 0x1b8))
                (param_1,uVar1,*(undefined4 *)(param_2 + 0x3d0 + (ulong)(uVar1 >> 2) * 4));
    }
    puVar4 = puVar4 + 1;
  } while (puVar4 != (uint *)(param_2 + 0x2474));
  (**(code **)(param_1 + 0x1b8))(param_1,4,*(undefined4 *)(param_2 + 0x3d4));
  iVar2 = regRead032(param_1 + 0x3a18,0,0,0xa00,0);
  uVar3 = 0x42;
  if (iVar2 == *(int *)(param_1 + 0x8e8)) {
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 002bab50 kbifCacheFlrSupport_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifCacheFlrSupport_GB100(long param_1,long param_2)

{
  int iVar1;
  uint local_1c [3];
  
  local_1c[0] = 0;
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x44,local_1c);
  if (iVar1 == 0) {
    if ((local_1c[0] & 0x10000000) != 0) {
      *(undefined1 *)(param_2 + 0x3b0) = 1;
    }
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x3b3,
               "kbifCacheFlrSupport_GB100",4,"NVRM: Unable to read NV_PF0_DEVICE_CAPABILITIES\n");
  return;
}


// ===== 002babd0 kbifCache64bBar0Support_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifCache64bBar0Support_GB100(long param_1,long param_2)

{
  int iVar1;
  uint local_1c [3];
  
  local_1c[0] = 0;
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x10,local_1c);
  if (iVar1 == 0) {
    if ((local_1c[0] & 6) == 4) {
      *(undefined1 *)(param_2 + 0x3b1) = 1;
    }
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x3d3,
               "kbifCache64bBar0Support_GB100",4,
               "NVRM: Unable to read NV_PF0_BASE_ADDRESS_REGISTERS_0\n");
  return;
}


// ===== 002bac50 kbifCacheMnocSupport_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifCacheMnocSupport_GB100(long param_1,long param_2)

{
  int iVar1;
  uint local_1c [3];
  
  local_1c[0] = 0;
  *(undefined1 *)(param_2 + 0x2450) = 0;
  if (*(char *)(param_1 + 0x4912) == '\0') {
    iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0xaf4,local_1c);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x400,
                   "kbifCacheMnocSupport_GB100",4,
                   "NVRM: Unable to read NV_PF0_DESIGNATED_VENDOR_SPECIFIC_0_HEADER_1\n");
      return;
    }
    if ((short)local_1c[0] != 0x10de) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0xaf8,local_1c);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x40f,
                   "kbifCacheMnocSupport_GB100",4,
                   "NVRM: Unable to read NV_PF0_DESIGNATED_VENDOR_SPECIFIC_0_HEADER_2_AND_GENERAL\n"
                  );
      return;
    }
    if ((local_1c[0] & 0x20000) != 0) {
      return;
    }
    if ((local_1c[0] & 0x80000) == 0) {
      return;
    }
  }
  *(undefined1 *)(param_2 + 0x2450) = 1;
  return;
}


// ===== 002bad40 kbifCacheVFInfo_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifCacheVFInfo_GB100(long param_1)

{
  int iVar1;
  undefined1 local_25;
  uint local_24;
  undefined8 local_20 [2];
  
  local_25 = 0;
  local_24 = 0;
  local_20[0] = 0;
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x30c,&local_24);
  if (iVar1 != 0) {
    nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x485,
                 "kbifCacheVFInfo_GB100",4,"NVRM: Unable to read NV_PF0_INITIAL_AND_TOTAL_VFS\n");
    return;
  }
  *(uint *)(param_1 + 0x3a58) = local_24 >> 0x10;
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x314,&local_24);
  if (iVar1 == 0) {
    *(uint *)(param_1 + 0x3a5c) = local_24 & 0xffff;
    iVar1 = _kbifGetBarInfo_GB100_constprop_0(param_1,0,local_20,&local_25);
    if (iVar1 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",
                          0x497);
    }
    *(undefined8 *)(param_1 + 0x3ab0) = local_20[0];
    *(undefined1 *)(param_1 + 0x3af0) = local_25;
    iVar1 = _kbifGetBarInfo_GB100_constprop_0(param_1,1,local_20,&local_25);
    if (iVar1 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",
                          0x49e);
    }
    *(undefined8 *)(param_1 + 0x3ab8) = local_20[0];
    *(undefined1 *)(param_1 + 0x3af1) = local_25;
    iVar1 = _kbifGetBarInfo_GB100_constprop_0(param_1,2,local_20,&local_25);
    if (iVar1 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",
                          0x4a5);
    }
    *(undefined8 *)(param_1 + 0x3ac0) = local_20[0];
    *(undefined1 *)(param_1 + 0x3af2) = local_25;
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x48f,"kbifCacheVFInfo_GB100",
               4,"NVRM: Unable to read NV_PF0_VF_STRIDE_AND_OFFSET\n");
  return;
}


// ===== 002baf10 kbifStopSysMemRequests_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbifStopSysMemRequests_GB100(long param_1,undefined8 param_2,char param_3)

{
  uint uVar1;
  ulong uVar2;
  uint local_1c [3];
  
  uVar1 = (**(code **)(param_1 + 0x1b0))(param_1,4,local_1c);
  if (uVar1 == 0) {
    uVar1 = local_1c[0] & 0xfffffffb;
    local_1c[0] = local_1c[0] | 4;
    if (param_3 != '\0') {
      local_1c[0] = uVar1;
    }
    uVar2 = (**(code **)(param_1 + 0x1b8))(param_1,4);
    if ((int)uVar2 != 0) {
      nvAssertOkFailedNoLog
                (uVar2 & 0xffffffff,"GPU_BUS_CFG_CYCLE_WR32(pGpu, NV_PF0_STATUS_COMMAND, regVal)",
                 "src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x4cb);
      uVar2 = uVar2 & 0xffffffff;
    }
    return uVar2;
  }
  nvAssertOkFailedNoLog
            (uVar1,"GPU_BUS_CFG_CYCLE_RD32(pGpu, NV_PF0_STATUS_COMMAND, &regVal)",
             "src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x4be);
  return (ulong)uVar1;
}


// ===== 002bafd0 kbifTriggerFlr_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbifTriggerFlr_GB100(long param_1)

{
  uint uVar1;
  ulong uVar2;
  uint local_c;
  
  local_c = 0;
  uVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x48,&local_c);
  if (uVar1 != 0) {
    nvAssertFailedNoLog("Config space read of device control failed\n",
                        "src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x4e7);
    return (ulong)uVar1;
  }
  local_c = local_c | 0x8000;
  uVar2 = (**(code **)(param_1 + 0x1b8))(param_1,0x48);
  if ((int)uVar2 == 0) {
    return uVar2;
  }
  nvAssertFailedNoLog("FLR trigger failed\n","src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",
                      0x4f3);
  return uVar2 & 0xffffffff;
}


// ===== 002bb070 kbifConfigAccessWait_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbifConfigAccessWait_GB100(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_2c;
  
  iVar2 = 0;
  local_2c = 0;
  while ((iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0,&local_2c), iVar1 != 0 ||
         ((short)local_2c != 0x10de))) {
    iVar2 = timeoutCheck(param_1 + 0x1af0,param_3,0x51c);
    if (iVar2 == 0x65) {
      nvAssertFailedNoLog("Timed out waiting for devinit to complete\n",
                          "src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x51f);
      return 0x65;
    }
    osDelay(1);
  }
  return iVar2;
}


// ===== 002bb110 kbifGetMSIXTableVectorControlSize_GB100 =====

undefined8 kbifGetMSIXTableVectorControlSize_GB100(void)

{
  return 0xc;
}


// ===== 002bb120 kbifProbePcieCplAtomicCaps_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifProbePcieCplAtomicCaps_GB100(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x280))(param_1,param_2,param_2 + 0x23f0);
  return;
}


// ===== 002bb140 kbifReadPcieCplCapsFromConfigSpace_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifReadPcieCplCapsFromConfigSpace_GB100(long param_1,undefined8 param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  uint local_1c [3];
  
  if (param_3 == (uint *)0x0) {
    nvAssertFailedNoLog("pBifAtomicsmask != NULL",
                        "src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x561);
    return;
  }
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,100,local_1c);
  if (iVar1 == 0) {
    uVar2 = -(uint)((local_1c[0] & 0x80) != 0) & 0x15;
    if ((local_1c[0] & 0x100) != 0) {
      uVar2 = uVar2 | 0x2a;
    }
    *param_3 = uVar2;
    if ((local_1c[0] & 0x200) != 0) {
      *param_3 = *param_3 | 0x40;
    }
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x565,
               "kbifReadPcieCplCapsFromConfigSpace_GB100",4,
               "NVRM: Unable to read NV_PF0_DEVICE_CAPABILITIES_2\n");
  return;
}


// ===== 002bb1f0 kbifGetValidEnginesToReset_GB100 =====

undefined8 kbifGetValidEnginesToReset_GB100(void)

{
  return 0x50000000;
}


// ===== 002bb200 kbifInitLtr_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifInitLtr_GB100(long param_1)

{
  int iVar1;
  uint local_c;
  
  if (*(char *)(*(long *)(g_pSys + 0x208) + 99) == '\0') {
    nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x5b6,"kbifInitLtr_GB100",3,
                 "NVRM: LTR is disabled in the hierarchy\n");
    return;
  }
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x68,&local_c);
  if (iVar1 == 0) {
    local_c = local_c | 0x400;
    iVar1 = (**(code **)(param_1 + 0x1b8))(param_1,0x68);
    if (iVar1 == 0) {
      return;
    }
    nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x5b0,"kbifInitLtr_GB100",4,
                 "NVRM: Unable to write NV_PF0_DEVICE_CONTROL_2\n");
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x5a7,"kbifInitLtr_GB100",4,
               "NVRM: Unable to read NV_PF0_DEVICE_CONTROL_2\n");
  return;
}


// ===== 002bb2f0 kbifGetLtrEnable_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifGetLtrEnable_GB100(long param_1,undefined8 param_2,byte *param_3)

{
  undefined8 uVar1;
  undefined4 local_1c;
  
  local_1c = 0;
  uVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x68,&local_1c);
  if ((int)uVar1 == 0) {
    *param_3 = local_1c._1_1_ >> 2 & 1;
    return uVar1;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x5d1,"kbifGetLtrEnable_GB100"
               ,4,"NVRM: Unable to read NV_PF0_DEVICE_CONTROL_2\n");
  *param_3 = 0;
  return 0xffff;
}


// ===== 002bb370 kbifSetLtrEnable_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifSetLtrEnable_GB100(long param_1,undefined8 param_2,char param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  uint local_1c [3];
  
  iVar2 = (**(code **)(param_1 + 0x1b0))(param_1,0x68,local_1c);
  if (iVar2 == 0) {
    uVar1 = local_1c[0] & 0xfffffbff;
    if (param_3 != '\0') {
      uVar1 = local_1c[0] | 0x400;
    }
    local_1c[0] = uVar1;
    uVar3 = (**(code **)(param_1 + 0x1b8))(param_1,0x68);
    if ((int)uVar3 == 0) {
      return uVar3;
    }
    nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x604,
                 "kbifSetLtrEnable_GB100",4,"NVRM: Unable to write NV_PF0_DEVICE_CONTROL_2\n");
  }
  else {
    nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x5f4,
                 "kbifSetLtrEnable_GB100",4,"NVRM: Unable to read NV_PF0_DEVICE_CONTROL_2\n");
  }
  return 0xffff;
}


// ===== 002bb430 kbifCacheDeviceControlStatus2Reg_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifCacheDeviceControlStatus2Reg_GB100(long param_1,long param_2)

{
  int iVar1;
  undefined4 local_1c [3];
  
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x68,local_1c);
  if (iVar1 == 0) {
    *(undefined4 *)(param_2 + 0x23e8) = local_1c[0];
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb100.c",0x61e,
               "kbifCacheDeviceControlStatus2Reg_GB100",4,
               "NVRM: Unable to read NV_PF0_DEVICE_CONTROL_2\n");
  return;
}


// ===== 002bb4a0 kbifReadPcieCplCapsFromConfigSpace_GB10B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifReadPcieCplCapsFromConfigSpace_GB10B(long param_1,undefined8 param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  uint local_1c [3];
  
  if (param_3 == (uint *)0x0) {
    nvAssertFailedNoLog("pBifAtomicsmask != NULL",
                        "src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb10b.c",0x28);
    return;
  }
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x84,local_1c);
  if (iVar1 == 0) {
    uVar2 = -(uint)((local_1c[0] & 0x80) != 0) & 0x15;
    if ((local_1c[0] & 0x100) != 0) {
      uVar2 = uVar2 | 0x2a;
    }
    *param_3 = uVar2;
    if ((local_1c[0] & 0x200) != 0) {
      *param_3 = *param_3 | 0x40;
    }
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb10b.c",0x2c,
               "kbifReadPcieCplCapsFromConfigSpace_GB10B",4,
               "NVRM: Unable to read NV_EP_PCFG_GPU_DEVICE_CAPABILITIES_2\n");
  return;
}


// ===== 002bb550 kbifConstructXtlAperture_GB10B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifConstructXtlAperture_GB10B(long param_1,long param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = (**(code **)(param_1 + 0x430))();
  iVar2 = ioaprtInit(param_2 + 0x2478,*(undefined8 *)(param_1 + 0x1a18),uVar1,0xf00);
  if (iVar2 == 0) {
    return;
  }
  nvAssertFailedNoLog("ioaprtInit(&pKernelBif->pBifXtlAperture, pGpu->pIOApertures[DEVICE_INDEX_GPU], xtlBaseAddress, DRF_SIZE(NV_XTL_EP_PRI)) == NV_OK"
                      ,"src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb10b.c",0x4d);
  return;
}


// ===== 002bb5c0 kbifSavePcieConfigRegistersFn1_GB202 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kbifSavePcieConfigRegistersFn1_GB202(long param_1,long param_2,long param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
  if (param_4 != 0) {
    uVar2 = 0;
    do {
      iVar1 = (**(code **)(param_1 + 0x1c0))
                        (param_1,uVar2 * 4,*(long *)(param_3 + 0x18) + (ulong)uVar2 * 4,1);
      if (iVar1 == 0x40) {
        nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb202.c",0x3d,
                     "kbifSavePcieConfigRegistersFn1_GB202",4,"NVRM: Config read failed.\n");
        return 0x40;
      }
      iVar1 = uVar2 * 4;
      uVar2 = uVar2 + 1;
    } while (iVar1 + 4U < param_4);
  }
  *(undefined1 *)(param_2 + 0x3b4) = 1;
  return 0;
}


// ===== 002bb6b0 kbifRestorePcieConfigRegistersFn1_GB202 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
kbifRestorePcieConfigRegistersFn1_GB202(long param_1,undefined8 param_2,long param_3,uint param_4)

{
  ulong uVar1;
  int iVar2;
  long lVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar1 = *(ulong *)(param_1 + 0x878);
  lVar3 = osPciInitHandle(uVar1 >> 0x20,uVar1 >> 8 & 0xff,uVar1 & 0xff,1,0,0);
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pHandle","src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb202.c",0x65);
    uVar4 = 0x3d;
  }
  else {
    uVar5 = 0;
    if (param_4 == 0) {
      uVar4 = 0;
    }
    else {
      do {
        iVar2 = (**(code **)(param_1 + 0x1c8))
                          (param_1,uVar5 * 4,
                           *(undefined4 *)(*(long *)(param_3 + 0x18) + (ulong)uVar5 * 4),1);
        if (iVar2 == 0x40) {
          nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb202.c",0x6d,
                       "kbifRestorePcieConfigRegistersFn1_GB202",4,"NVRM: Config write failed.\n");
          nvAssertFailedNoLog(&DAT_00cf3441,"src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb202.c",
                              0x6e);
          return 0x40;
        }
        iVar2 = uVar5 * 4;
        uVar5 = uVar5 + 1;
      } while (iVar2 + 4U < param_4);
      uVar4 = 0;
    }
  }
  return uVar4;
}


// ===== 002bb800 kbifIsPciIoAccessEnabled_GB202 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kbifIsPciIoAccessEnabled_GB202(long param_1)

{
  int iVar1;
  uint local_c;
  
  local_c = 0;
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,4,&local_c);
  if (iVar1 == 0) {
    return local_c & 1;
  }
  return 0;
}


// ===== 002bb840 kbifInitLtr_GB202 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifInitLtr_GB202(long param_1)

{
  int iVar1;
  uint local_c;
  
  if (*(char *)(*(long *)(g_pSys + 0x208) + 99) == '\0') {
    nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb202.c",0xbc,"kbifInitLtr_GB202",3,
                 "NVRM: LTR is disabled in the hierarchy\n");
    return;
  }
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x88,&local_c);
  if (iVar1 == 0) {
    local_c = local_c | 0x400;
    iVar1 = (**(code **)(param_1 + 0x1b8))(param_1,0x88);
    if (iVar1 == 0) {
      return;
    }
    nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb202.c",0xb5,"kbifInitLtr_GB202",4,
                 "NVRM: Unable to write NV_EP_PCFG_GPU_DEVICE_CONTROL_STATUS_2\n");
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb202.c",0xaa,"kbifInitLtr_GB202",4,
               "NVRM: Unable to read NV_EP_PCFG_GPU_DEVICE_CONTROL_STATUS_2\n");
  return;
}


// ===== 002bb930 kbifGetLtrEnable_GB202 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifGetLtrEnable_GB202(long param_1,undefined8 param_2,byte *param_3)

{
  undefined8 uVar1;
  undefined4 local_1c;
  
  local_1c = 0;
  uVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x88,&local_1c);
  if ((int)uVar1 == 0) {
    *param_3 = local_1c._1_1_ >> 2 & 1;
    return uVar1;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb202.c",0xd7,"kbifGetLtrEnable_GB202",
               4,"NVRM: Unable to read NV_EP_PCFG_GPU_DEVICE_CONTROL_STATUS_2\n");
  *param_3 = 0;
  return 0xffff;
}


// ===== 002bb9b0 kbifSetLtrEnable_GB202 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifSetLtrEnable_GB202(long param_1,undefined8 param_2,char param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  uint local_1c [3];
  
  iVar2 = (**(code **)(param_1 + 0x1b0))(param_1,0x88,local_1c);
  if (iVar2 == 0) {
    uVar1 = local_1c[0] & 0xfffffbff;
    if (param_3 != '\0') {
      uVar1 = local_1c[0] | 0x400;
    }
    local_1c[0] = uVar1;
    uVar3 = (**(code **)(param_1 + 0x1b8))(param_1,0x88);
    if ((int)uVar3 == 0) {
      return uVar3;
    }
    nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb202.c",0x107,
                 "kbifSetLtrEnable_GB202",4,
                 "NVRM: Unable to write NV_EP_PCFG_GPU_DEVICE_CONTROL_STATUS_2\n");
  }
  else {
    nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb202.c",0xf7,
                 "kbifSetLtrEnable_GB202",4,
                 "NVRM: Unable to read NV_EP_PCFG_GPU_DEVICE_CONTROL_STATUS_2\n");
  }
  return 0xffff;
}


// ===== 002bba70 kbifPollBarFirewallDisengage_GB202 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbifPollBarFirewallDisengage_GB202(long param_1)

{
  int iVar1;
  uint uVar2;
  uint local_44;
  undefined1 local_40 [32];
  
  uVar2 = *(int *)(param_1 + 0x1b08) * 500000;
  if (uVar2 <= *(uint *)(param_1 + 0x1af4)) {
    uVar2 = *(uint *)(param_1 + 0x1af4);
  }
  timeoutSet(param_1 + 0x1af0,local_40,uVar2,0xc);
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x2b8,&local_44);
  if (iVar1 != 0) {
    nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb202.c",0x132,
                 "kbifPollBarFirewallDisengage_GB202",4,
                 "NVRM: Unable to read NV_EP_PCFG_GPU_VSEC_DEBUG_SEC_2.\n");
    return iVar1;
  }
  while( true ) {
    if ((local_44 & 0x1000000) == 0) {
      return 0;
    }
    iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x2b8,&local_44);
    if (iVar1 != 0) break;
    iVar1 = timeoutCheck(param_1 + 0x1af0,local_40,0x141);
    if (iVar1 == 0x65) {
      nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb202.c",0x143,
                   "kbifPollBarFirewallDisengage_GB202",4,
                   "NVRM: Timeout polling CFG BAR firewall disengage.\n");
      return 0x65;
    }
    osDelayUs(100);
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb202.c",0x13c,
               "kbifPollBarFirewallDisengage_GB202",4,
               "NVRM: Unable to read NV_EP_PCFG_GPU_VSEC_DEBUG_SEC_2.\n");
  return iVar1;
}


// ===== 002bbbf0 kbifAllowGpuReqPcieAtomics_GB202 =====

bool kbifAllowGpuReqPcieAtomics_GB202(long param_1)

{
  return *(char *)(param_1 + 0x4a2f) != '\0';
}


// ===== 002bbc00 kbifConstructXtlAperture_GB202 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifConstructXtlAperture_GB202(long param_1,long param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = (**(code **)(param_1 + 0x430))();
  iVar2 = ioaprtInit(param_2 + 0x2478,*(undefined8 *)(param_1 + 0x1a18),uVar1,0x2000);
  if (iVar2 == 0) {
    return;
  }
  nvAssertFailedNoLog("ioaprtInit(&pKernelBif->pBifXtlAperture, pGpu->pIOApertures[DEVICE_INDEX_GPU], xtlBaseAddress, DRF_SIZE(NV_XTL_EP_PRI)) == NV_OK"
                      ,"src/kernel/gpu/bif/arch/blackwell/kernel_bif_gb202.c",0x16c);
  return;
}


// ===== 002bbc70 _kbifGetBarInfo_GH100.constprop.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _kbifGetBarInfo_GH100_constprop_0(long param_1,int param_2,ulong *param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint local_40;
  undefined4 local_3c [3];
  
  iVar6 = 0;
  uVar5 = 0x274;
  local_40 = 0;
  local_3c[0] = 0;
  while( true ) {
    iVar2 = (**(code **)(param_1 + 0x1b0))(param_1,uVar5,&local_40);
    uVar1 = local_40;
    if (iVar2 != 0) {
      return iVar2;
    }
    uVar4 = local_40 & 6;
    if (param_2 == iVar6) break;
    uVar5 = uVar5 + 4 + (uint)(uVar4 == 4) * 4;
    if (0x287 < uVar5) {
      return 0x2c;
    }
    iVar6 = iVar6 + 1;
  }
  uVar3 = (ulong)(local_40 & 0xfffffff0);
  if (uVar4 == 4) {
    iVar6 = (**(code **)(param_1 + 0x1b0))(param_1,uVar5 + 4,local_3c);
    if (iVar6 != 0) {
      nvAssertFailedNoLog("(status == NV_OK)","src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",
                          0x4d8);
      return iVar6;
    }
    uVar3 = CONCAT44(local_3c[0],uVar1) & 0xfffffffffffffff0;
  }
  *param_3 = uVar3;
  *(bool *)param_4 = uVar4 == 4;
  return 0;
}


// ===== 002bbd90 kbifIsMSIEnabledInHW_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

bool kbifIsMSIEnabledInHW_GH100(long param_1)

{
  int iVar1;
  undefined1 local_c [2];
  byte local_a;
  
  if (*(char *)(param_1 + 0x908) != '\0') {
    return *(char *)(param_1 + 0x4913) == '\0';
  }
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x48,local_c);
  if (iVar1 == 0) {
    return (bool)(local_a & 1);
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x55,"kbifIsMSIEnabledInHW_GH100"
               ,4,"NVRM: unable to read NV_EP_PCFG_GPU_MSI_64_HEADER\n");
  return (bool)(local_a & 1);
}


// ===== 002bbe10 kbifIsMSIXEnabledInHW_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kbifIsMSIXEnabledInHW_GH100(long param_1)

{
  int iVar1;
  uint local_1c [3];
  
  if (*(char *)(param_1 + 0x908) != '\0') {
    return (uint)*(byte *)(param_1 + 0x4913);
  }
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0xb0,local_1c);
  if (iVar1 == 0) {
    return local_1c[0] >> 0x1f;
  }
  nvAssertFailedNoLog("Unable to read NV_EP_PCFG_GPU_MSIX_CAP_HEADER\n",
                      "src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x78);
  return 0;
}


// ===== 002bbe90 kbifIs3dController_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

bool kbifIs3dController_GH100(long param_1)

{
  int iVar1;
  undefined4 local_c;
  
  local_c = 0;
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,8,&local_c);
  if (iVar1 == 0) {
    return local_c._3_1_ == '\x03';
  }
  return false;
}


// ===== 002bbed0 kbifEnableExtendedTagSupport_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifEnableExtendedTagSupport_GH100(long param_1)

{
  long lVar1;
  int iVar2;
  uint local_1c;
  
  lVar1 = *(long *)(g_pSys + 0x208);
  iVar2 = (**(code **)(param_1 + 0x1b0))(param_1,100,&local_1c);
  if (iVar2 == 0) {
    local_1c = local_1c >> 5 & 1;
    if ((local_1c != 0) && (*(char *)(lVar1 + 0x58) == '\0')) {
      iVar2 = (**(code **)(param_1 + 0x1b0))(param_1,0x68,&local_1c);
      if (iVar2 == 0) {
        local_1c = local_1c | 0x100;
        iVar2 = (**(code **)(param_1 + 0x1b8))(param_1,0x68);
        if (iVar2 != 0) {
          nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0xc9,
                       "kbifEnableExtendedTagSupport_GH100",4,
                       "NVRM: Unable to write NV_EP_PCFG_GPU_DEVICE_CONTROL_STATUS\n");
        }
      }
      else {
        nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0xbf,
                     "kbifEnableExtendedTagSupport_GH100",4,
                     "NVRM: Unable to read NV_EP_PCFG_GPU_DEVICE_CONTROL_STATUS\n");
      }
    }
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0xb2,
               "kbifEnableExtendedTagSupport_GH100",4,
               "NVRM: Unable to read NV_EP_PCFG_GPU_DEVICE_CAPABILITIES\n");
  return;
}


// ===== 002bc000 kbifEnableNoSnoop_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbifEnableNoSnoop_GH100(long param_1,undefined8 param_2,char param_3)

{
  int iVar1;
  uint local_1c [3];
  
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x68,local_1c);
  if (iVar1 != 0) {
    nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0xec,"kbifEnableNoSnoop_GH100",
                 4,"NVRM: Failed to read NV_EP_PCFG_GPU_DEVICE_CONTROL_STATUS.\n");
    return iVar1;
  }
  local_1c[0] = local_1c[0] & 0xfffff7ff | (uint)(param_3 != '\0') << 0xb;
  iVar1 = (**(code **)(param_1 + 0x1b8))(param_1,0x68);
  if (iVar1 == 0) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0xf8,"kbifEnableNoSnoop_GH100",4,
               "NVRM: Failed to write NV_EP_PCFG_GPU_DEVICE_CONTROL_STATUS.\n");
  return iVar1;
}


// ===== 002bc0f0 kbifPcieConfigEnableRelaxedOrdering_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifPcieConfigEnableRelaxedOrdering_GH100(long param_1)

{
  int iVar1;
  uint local_c;
  
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x68,&local_c);
  if (iVar1 != 0xffff) {
    (**(code **)(param_1 + 0x1b8))(param_1,0x68,local_c | 0x10);
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x114,
               "kbifPcieConfigEnableRelaxedOrdering_GH100",4,
               "NVRM: Unable to read NV_EP_PCFG_GPU_DEVICE_CONTROL_STATUS!\n");
  return;
}


// ===== 002bc170 kbifPcieConfigDisableRelaxedOrdering_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifPcieConfigDisableRelaxedOrdering_GH100(long param_1)

{
  int iVar1;
  uint local_c;
  
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x68,&local_c);
  if (iVar1 != 0xffff) {
    local_c = local_c & 0xffffffef;
    (**(code **)(param_1 + 0x1b8))(param_1,0x68);
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x130,
               "kbifPcieConfigDisableRelaxedOrdering_GH100",4,
               "NVRM: Unable to read NV_EP_PCFG_GPU_DEVICE_CONTROL_STATUS!\n");
  return;
}


// ===== 002bc1f0 kbifGetXveStatusBits_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifGetXveStatusBits_GH100(long param_1,long param_2,uint *param_3,uint *param_4)

{
  int iVar1;
  uint local_2c;
  
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x68,&local_2c);
  if (iVar1 != 0) {
    nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x157,
                 "kbifGetXveStatusBits_GH100",4,
                 "NVRM: Unable to read NV_EP_PCFG_GPU_DEVICE_CONTROL_STATUS!\n");
  }
  if (param_3 == (uint *)0x0) {
    return 0xffff;
  }
  *param_3 = 0;
  if (*(char *)(param_1 + 0x4910) == '\0') {
    if (param_4 != (uint *)0x0) {
      *param_4 = local_2c;
    }
    if ((local_2c & 0x10000) != 0) {
      *param_3 = *param_3 | 1;
    }
    if ((local_2c & 0x20000) != 0) {
      *param_3 = *param_3 | 2;
    }
    if ((local_2c & 0x40000) != 0) {
      *param_3 = *param_3 | 4;
    }
    if ((local_2c & 0x80000) != 0) {
      *param_3 = *param_3 | 8;
    }
    if (*(char *)(param_2 + 0x3cd) != '\0') {
      *(undefined1 *)(param_2 + 0x3cd) = 0;
      *param_3 = *param_3 | 0x10;
    }
  }
  else if (param_4 != (uint *)0x0) {
    *param_4 = 0;
  }
  return 0;
}


// ===== 002bc310 kbifClearXveStatus_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifClearXveStatus_GH100(long param_1,undefined8 param_2,int *param_3)

{
  int iVar1;
  int local_c;
  
  if (param_3 == (int *)0x0) {
    iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x68,&local_c);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x1ae,
                   "kbifClearXveStatus_GH100",4,
                   "NVRM: Unable to read NV_EP_PCFG_GPU_DEVICE_CONTROL_STATUS!\n");
    }
  }
  else {
    local_c = *param_3;
    if (local_c == 0) {
      return 0;
    }
  }
  (**(code **)(param_1 + 0x1b8))(param_1,0x68,local_c);
  return 0;
}


// ===== 002bc3b0 kbifGetXveAerBits_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kbifGetXveAerBits_GH100(long param_1,undefined8 param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint local_20;
  uint local_1c [3];
  
  if (param_3 == (uint *)0x0) {
    uVar2 = 0xffff;
  }
  else {
    uVar2 = 0;
    if (*(char *)(param_1 + 0x4910) == '\0') {
      *param_3 = 0;
      iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x1bc,&local_20);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x1c8,local_1c);
        if (iVar1 == 0) {
          if ((local_20 & 0x10) != 0) {
            *param_3 = *param_3 | 2;
          }
          if ((local_20 & 0x1000) != 0) {
            *param_3 = *param_3 | 4;
          }
          if ((local_20 & 0x4000) != 0) {
            *param_3 = *param_3 | 0x10;
          }
          if ((local_20 & 0x10000) != 0) {
            *param_3 = *param_3 | 0x40;
          }
          if ((local_20 & 0x40000) != 0) {
            *param_3 = *param_3 | 0x100;
          }
          if ((local_20 & 0x100000) != 0) {
            *param_3 = *param_3 | 0x400;
          }
          if ((local_1c[0] & 1) != 0) {
            *param_3 = *param_3 | 0x10000;
          }
          if ((local_1c[0] & 0x40) != 0) {
            *param_3 = *param_3 | 0x20000;
          }
          if ((local_1c[0] & 0x80) != 0) {
            *param_3 = *param_3 | 0x40000;
          }
          if ((local_1c[0] & 0x100) != 0) {
            *param_3 = *param_3 | 0x80000;
          }
          if ((local_1c[0] & 0x1000) != 0) {
            *param_3 = *param_3 | 0x100000;
          }
          if ((local_1c[0] & 0x2000) != 0) {
            *param_3 = *param_3 | 0x200000;
          }
          return 0;
        }
        nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x1e0,
                     "kbifGetXveAerBits_GH100",4,
                     "NVRM: Unable to read NV_EP_PCFG_GPU_CORRECTABLE_ERROR_STATUS\n");
      }
      else {
        nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x1da,
                     "kbifGetXveAerBits_GH100",4,
                     "NVRM: Unable to read NV_EP_PCFG_GPU_UNCORRECTABLE_ERROR_STATUS\n");
      }
      return 0xffff;
    }
  }
  return uVar2;
}


// ===== 002bc520 kbifClearXveAer_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifClearXveAer_GH100(long param_1,undefined8 param_2,ulong param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = ((uint)param_3 & 2) << 3;
  if ((param_3 & 4) != 0) {
    uVar2 = (uint)CONCAT11(0x10,(char)uVar2);
  }
  if ((param_3 & 0x10) != 0) {
    uVar2 = uVar2 | 0x4000;
  }
  if ((param_3 & 0x40) != 0) {
    uVar2 = uVar2 | 0x10000;
  }
  if ((param_3 & 0x100) != 0) {
    uVar2 = uVar2 | 0x40000;
  }
  if ((param_3 & 0x400) != 0) {
    uVar2 = uVar2 | 0x100000;
  }
  uVar3 = (uint)(param_3 >> 0x10) & 1;
  uVar1 = uVar3 | 0x40;
  if ((param_3 & 0x20000) == 0) {
    uVar1 = uVar3;
  }
  if ((param_3 & 0x40000) != 0) {
    uVar1 = uVar1 | 0x80;
  }
  if ((param_3 & 0x80000) != 0) {
    uVar1 = uVar1 | 0x100;
  }
  if ((param_3 & 0x100000) == 0) {
    if ((param_3 & 0x200000) == 0) {
      if (uVar2 != 0) {
        (**(code **)(param_1 + 0x1b8))(param_1,0x1bc);
      }
      if (uVar1 == 0) {
        return 0;
      }
      goto LAB_002bc5bc;
    }
LAB_002bc5b5:
    uVar1 = uVar1 | 0x2000;
  }
  else {
    uVar1 = uVar1 | 0x1000;
    if ((param_3 & 0x200000) != 0) goto LAB_002bc5b5;
  }
  if (uVar2 != 0) {
    (**(code **)(param_1 + 0x1b8))(param_1,0x1bc);
  }
LAB_002bc5bc:
  (**(code **)(param_1 + 0x1b8))(param_1,0x1c8,uVar1);
  return 0;
}


// ===== 002bc640 kbifGetPciConfigSpacePriMirror_GH100 =====

undefined8
kbifGetPciConfigSpacePriMirror_GH100
          (undefined8 param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  *param_3 = 0x92000;
  *param_4 = 0x1000;
  return 0;
}


// ===== 002bc660 kbifProbePcieReqAtomicCaps_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifProbePcieReqAtomicCaps_GH100(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  int local_1c;
  
  local_1c = 0;
  cVar1 = (**(code **)(param_2 + 0x370))();
  if (cVar1 == '\0') {
    nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x279,
                 "kbifProbePcieReqAtomicCaps_GH100",1,
                 "NVRM: PCIe atomics not supported in this platform!\n");
    return;
  }
  iVar2 = osConfigurePcieReqAtomics(*(undefined8 *)(param_1 + 0x4e0),&local_1c);
  if ((iVar2 == 0) && (local_1c != 0)) {
    *(int *)(param_2 + 0x23ec) = local_1c;
    (**(code **)(param_2 + 0x270))(param_1,param_2);
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x280,
               "kbifProbePcieReqAtomicCaps_GH100",1,
               "NVRM: PCIe requester atomics not enabled since completer is not capable!\n");
  return;
}


// ===== 002bc730 kbifEnablePcieAtomics_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifEnablePcieAtomics_GH100(long param_1)

{
  int iVar1;
  uint local_c;
  
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x88,&local_c);
  if (iVar1 != 0) {
    nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x29f,
                 "kbifEnablePcieAtomics_GH100",1,
                 "NVRM: Read of NV_EP_PCFG_GPU_DEVICE_CONTROL_STATUS_2 failed.\n");
    return;
  }
  local_c = local_c | 0x40;
  iVar1 = (**(code **)(param_1 + 0x1b8))(param_1,0x88);
  if (iVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x2ab,
                 "kbifEnablePcieAtomics_GH100",1,"NVRM: PCIe Requester atomics enabled.\n");
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x2a7,
               "kbifEnablePcieAtomics_GH100",1,
               "NVRM: Write of NV_EP_PCFG_GPU_DEVICE_CONTROL_STATUS_2 failed.\n");
  return;
}


// ===== 002bc800 kbifGetBusOptionsAddr_GH100 =====

undefined8
kbifGetBusOptionsAddr_GH100(undefined8 param_1,undefined8 param_2,uint param_3,undefined4 *param_4)

{
  if (param_3 == 2) {
    *param_4 = 0x6c;
    return 0;
  }
  if (param_3 < 3) {
    if (param_3 != 0) {
      *param_4 = 0x70;
      return 0;
    }
    *param_4 = 0x68;
    return 0;
  }
  if (param_3 == 3) {
    *param_4 = 0x88;
    return 0;
  }
  if (param_3 == 4) {
    *param_4 = 0x298;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x2d7,
               "kbifGetBusOptionsAddr_GH100",4,"NVRM: Invalid register type passed 0x%x\n",param_3);
  return 0xffff;
}


// ===== 002bc8a0 kbifConfigAccessWait_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbifConfigAccessWait_GH100(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_2c;
  
  iVar2 = 0;
  local_2c = 0;
  while ((iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0,&local_2c), iVar1 != 0 ||
         ((short)local_2c != 0x10de))) {
    iVar2 = timeoutCheck(param_1 + 0x1af0,param_3,0x38f);
    if (iVar2 == 0x65) {
      nvAssertFailedNoLog("Timed out waiting for devinit to complete\n",
                          "src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x393);
      return 0x65;
    }
    osDelay(1);
  }
  return iVar2;
}


// ===== 002bc940 kbifDoFunctionLevelReset_GH100 =====

ulong kbifDoFunctionLevelReset_GH100(undefined8 param_1,long param_2)

{
  ulong uVar1;
  
  *(undefined1 *)(param_2 + 0x23d5) = 1;
  uVar1 = osDoFunctionLevelReset();
  if ((int)uVar1 == 0) {
    *(undefined2 *)(param_2 + 0x23d4) = 0;
    return uVar1;
  }
  nvAssertFailedNoLog("osDoFunctionLevelReset failed!\n",
                      "src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x3c1);
  *(undefined2 *)(param_2 + 0x23d4) = 0;
  return uVar1 & 0xffffffff;
}


// ===== 002bc9a0 kbifGetMSIXTableVectorControlSize_GH100 =====

undefined8 kbifGetMSIXTableVectorControlSize_GH100(void)

{
  return 9;
}


// ===== 002bc9b0 kbifCacheFlrSupport_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifCacheFlrSupport_GH100(long param_1,long param_2)

{
  int iVar1;
  uint local_1c [3];
  
  local_1c[0] = 0;
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,100,local_1c);
  if (iVar1 == 0) {
    if ((local_1c[0] & 0x10000000) != 0) {
      *(undefined1 *)(param_2 + 0x3b0) = 1;
    }
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x46e,"kbifCacheFlrSupport_GH100"
               ,4,"NVRM: Unable to read NV_EP_PCFG_GPU_DEVICE_CAPABILITIES\n");
  return;
}


// ===== 002bca30 kbifCache64bBar0Support_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifCache64bBar0Support_GH100(long param_1,long param_2)

{
  int iVar1;
  uint local_1c [3];
  
  local_1c[0] = 0;
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x10,local_1c);
  if (iVar1 == 0) {
    if ((local_1c[0] & 6) == 4) {
      *(undefined1 *)(param_2 + 0x3b1) = 1;
    }
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x48e,
               "kbifCache64bBar0Support_GH100",4,"NVRM: Unable to read NV_EP_PCFG_GPU_BARREG0\n");
  return;
}


// ===== 002bcab0 kbifCacheVFInfo_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifCacheVFInfo_GH100(long param_1)

{
  int iVar1;
  undefined1 local_25;
  uint local_24;
  undefined8 local_20 [2];
  
  local_25 = 0;
  local_24 = 0;
  local_20[0] = 0;
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x25c,&local_24);
  if (iVar1 != 0) {
    nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x4fe,"kbifCacheVFInfo_GH100",4
                 ,"NVRM: Unable to read NV_EP_PCFG_GPU_SRIOV_INIT_TOT_VF\n");
    return;
  }
  *(uint *)(param_1 + 0x3a58) = local_24 >> 0x10;
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x264,&local_24);
  if (iVar1 == 0) {
    *(uint *)(param_1 + 0x3a5c) = local_24 & 0xffff;
    iVar1 = _kbifGetBarInfo_GH100_constprop_0(param_1,0,local_20,&local_25);
    if (iVar1 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",
                          0x510);
    }
    *(undefined8 *)(param_1 + 0x3ab0) = local_20[0];
    *(undefined1 *)(param_1 + 0x3af0) = local_25;
    iVar1 = _kbifGetBarInfo_GH100_constprop_0(param_1,1,local_20,&local_25);
    if (iVar1 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",
                          0x517);
    }
    *(undefined8 *)(param_1 + 0x3ab8) = local_20[0];
    *(undefined1 *)(param_1 + 0x3af1) = local_25;
    iVar1 = _kbifGetBarInfo_GH100_constprop_0(param_1,2,local_20,&local_25);
    if (iVar1 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",
                          0x51e);
    }
    *(undefined8 *)(param_1 + 0x3ac0) = local_20[0];
    *(undefined1 *)(param_1 + 0x3af2) = local_25;
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x508,"kbifCacheVFInfo_GH100",4,
               "NVRM: Unable to read NV_EP_PCFG_GPU_SRIOV_FIRST_VF_STRIDE\n");
  return;
}


// ===== 002bcc80 kbifStopSysMemRequests_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbifStopSysMemRequests_GH100(long param_1,undefined8 param_2,char param_3)

{
  uint uVar1;
  ulong uVar2;
  uint local_1c [3];
  
  uVar1 = (**(code **)(param_1 + 0x1b0))(param_1,4,local_1c);
  if (uVar1 == 0) {
    uVar1 = local_1c[0] & 0xfffffffb;
    local_1c[0] = local_1c[0] | 4;
    if (param_3 != '\0') {
      local_1c[0] = uVar1;
    }
    uVar2 = (**(code **)(param_1 + 0x1b8))(param_1,4);
    if ((int)uVar2 != 0) {
      nvAssertOkFailedNoLog
                (uVar2 & 0xffffffff,
                 "GPU_BUS_CFG_CYCLE_WR32(pGpu, NV_EP_PCFG_GPU_CTRL_CMD_AND_STATUS, regVal)",
                 "src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x543);
      uVar2 = uVar2 & 0xffffffff;
    }
    return uVar2;
  }
  nvAssertOkFailedNoLog
            (uVar1,"GPU_BUS_CFG_CYCLE_RD32(pGpu, NV_EP_PCFG_GPU_CTRL_CMD_AND_STATUS, &regVal)",
             "src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x537);
  return (ulong)uVar1;
}


// ===== 002bcd40 kbifSavePcieConfigRegisters_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbifSavePcieConfigRegisters_GH100(long param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  
  if (*(char *)(param_1 + 0x4910) != '\0') {
    return 0;
  }
  if (*(char *)(param_2 + 0x23d4) == '\0') {
    if ((*(char *)(param_2 + 0x3b6) == '\0') || (uVar2 = 0, *(char *)(param_2 + 0x3b5) == '\0')) {
      nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x56b,
                   "kbifSavePcieConfigRegisters_GH100",4,
                   "NVRM: Config space save has been skipped.\n");
      return 0;
    }
  }
  else {
    uVar2 = 0;
  }
  do {
    iVar1 = (**(code **)(param_1 + 0x1b0))
                      (param_1,uVar2 & 0xffffffff,*(long *)(param_2 + 0x2418) + uVar2);
    if (iVar1 == 0x40) {
      nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x2fc,
                   "_kbifSavePcieConfigRegisters_GH100",4,"NVRM: Config read failed.\n");
      nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x574,
                   "kbifSavePcieConfigRegisters_GH100",4,
                   "NVRM: Saving PCIe config space failed for gpu.\n");
      nvAssertFailedNoLog(&DAT_00cf3d9e,"src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x575);
      return 0x40;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 != 0x2fc);
  *(undefined1 *)(param_2 + 0x3b4) = 1;
  if (((*(int *)(param_1 + 0x4b34) != 1) && (*(char *)(param_2 + 0x23d4) == '\0')) &&
     (*(char *)(param_2 + 0x3b2) != '\0')) {
    if ((*(char *)(param_1 + 0x446) == '\0') && (*(char *)(param_1 + 0x490e) == '\0')) {
      iVar1 = (**(code **)(param_2 + 0x1b0))(param_1,param_2,param_2 + 0x2428,0x15c);
      if (iVar1 != 0) {
        nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x591,
                     "kbifSavePcieConfigRegisters_GH100",4,
                     "NVRM: Saving PCIe config space failed for azalia.\n");
        nvAssertFailedNoLog(&DAT_00cf3d9e,"src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x592)
        ;
        return iVar1;
      }
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x588,
                 "kbifSavePcieConfigRegisters_GH100",1,
                 "NVRM: Skipping PCIe Fn1 config space save.\n");
  }
  return 0;
}


// ===== 002bcf90 kbifRestorePcieConfigRegisters_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbifRestorePcieConfigRegisters_GH100(long param_1,long param_2)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  char *pcVar6;
  ulong uVar7;
  int local_6c;
  long local_60;
  long local_58;
  undefined1 local_50 [32];
  
  if (*(char *)(param_1 + 0x4910) != '\0') {
    return 0;
  }
  if (*(long *)(param_2 + 0x2418) == 0) {
    nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x5b4,
                 "kbifRestorePcieConfigRegisters_GH100",4,"NVRM: Config space buffer is NULL!\n");
    nvAssertFailedNoLog(&DAT_00cf3d9e,"src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x5b5);
    iVar2 = 0x57;
  }
  else {
    uVar1 = *(ulong *)(param_1 + 0x878);
    uVar7 = 0;
    lVar4 = osPciInitHandle(uVar1 >> 0x20,uVar1 >> 8 & 0xff,uVar1 & 0xff,0,0,0);
    if (lVar4 == 0) {
      nvAssertFailedNoLog("pHandle","src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x322);
      local_6c = 0x3d;
LAB_002bd11d:
      nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x5be,
                   "kbifRestorePcieConfigRegisters_GH100",4,
                   "NVRM: Restoring PCIe config space failed for gpu.\n");
      uVar5 = 0x5bf;
LAB_002bd14c:
      nvAssertFailedNoLog(&DAT_00cf3d9e,"src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",uVar5);
      return local_6c;
    }
    do {
      iVar2 = (**(code **)(param_1 + 0x1b8))
                        (param_1,uVar7 & 0xffffffff,
                         *(undefined4 *)(*(long *)(param_2 + 0x2418) + uVar7));
      if (iVar2 == 0x40) {
        nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x32b,
                     "_kbifRestorePcieConfigRegisters_GH100",4,"NVRM: Config write failed.\n");
        nvAssertFailedNoLog(&DAT_00cf3d9e,"src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x32c)
        ;
        local_6c = 0x40;
        goto LAB_002bd11d;
      }
      uVar7 = uVar7 + 4;
    } while (uVar7 != 0x2fc);
    if ((*(int *)(param_1 + 0x4b34) == 4) || (*(char *)(param_2 + 0x23d5) != '\0')) {
      if ((*(char *)(param_1 + 0x446) == '\0') && (*(char *)(param_1 + 0x490e) == '\0')) {
        osGetPerformanceCounter(&local_60);
        timeoutSet(param_1 + 0x1af0,local_50,0,0);
        iVar2 = (**(code **)(*(long *)(param_1 + 0x1b60) + 0x180))(param_1);
        while (*(int *)(param_1 + 0x8e8) != iVar2) {
          pcVar6 = "GC6 exit";
          if (*(char *)(param_2 + 0x23d5) != '\0') {
            pcVar6 = "FLR";
          }
          nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x5d5,
                       "kbifRestorePcieConfigRegisters_GH100",1,
                       "NVRM: GPU not back on the bus after %s, 0x%x != 0x%x!\n",pcVar6,iVar2,
                       *(int *)(param_1 + 0x8e8));
          iVar2 = (**(code **)(*(long *)(param_1 + 0x1b60) + 0x180))(param_1);
          nvAssertFailedNoLog(&DAT_00cf3d9e,"src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",
                              0x5d9);
          iVar3 = timeoutCheck(param_1 + 0x1af0,local_50,0x5da);
          if (iVar3 == 0x65) {
            pcVar6 = "GC6 exit";
            if (*(char *)(param_2 + 0x23d5) != '\0') {
              pcVar6 = "FLR";
            }
            nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x5dd,
                         "kbifRestorePcieConfigRegisters_GH100",4,
                         "NVRM: Timeout GPU not back on the bus after %s,\n",pcVar6);
            return 0x65;
          }
        }
        osGetPerformanceCounter(&local_58);
        iVar2 = (int)local_58 - (int)local_60;
        if (0xffffffff < (ulong)(local_58 - local_60)) {
          iVar2 = -1;
        }
        nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x5e5,
                     "kbifRestorePcieConfigRegisters_GH100",4,
                     "NVRM: Time spend on GPU back on bus is 0x%x ns,\n",iVar2);
      }
    }
    else if (*(char *)(param_2 + 0x3b2) != '\0') {
      if ((*(char *)(param_1 + 0x446) == '\0') && (*(char *)(param_1 + 0x490e) == '\0')) {
        local_6c = (**(code **)(param_2 + 0x1b8))(param_1,param_2,param_2 + 0x2428,0x15c);
        if (local_6c == 0) {
          return 0;
        }
        nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x5fe,
                     "kbifRestorePcieConfigRegisters_GH100",4,
                     "NVRM: Restoring PCIe config space failed for azalia.\n");
        uVar5 = 0x5ff;
        goto LAB_002bd14c;
      }
      nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x5f5,
                   "kbifRestorePcieConfigRegisters_GH100",1,
                   "NVRM: Skipping PCIe Fn1 config space restore.\n");
    }
    iVar2 = 0;
  }
  return iVar2;
}


// ===== 002bd3e0 kbifWaitForTransactionsComplete_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbifWaitForTransactionsComplete_GH100(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  uint local_34;
  undefined1 local_30 [24];
  
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x68,&local_34);
  uVar2 = 0x617;
  if (iVar1 == 0) {
    timeoutSet(param_1 + 0x1af0,local_30,0,0);
    do {
      if ((local_34 & 0x200000) == 0) {
        return 0;
      }
      iVar1 = timeoutCheck(param_1 + 0x1af0,local_30,0x61f);
      if (iVar1 != 0) {
        nvAssertOkFailedNoLog
                  (iVar1,"gpuCheckTimeout(pGpu, &timeout)",
                   "src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x61f);
        return iVar1;
      }
      iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x68,&local_34);
    } while (iVar1 == 0);
    uVar2 = 0x620;
  }
  nvAssertOkFailedNoLog
            (iVar1,"GPU_BUS_CFG_CYCLE_RD32( pGpu, NV_EP_PCFG_GPU_DEVICE_CONTROL_STATUS, &regVal)",
             "src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",uVar2);
  return iVar1;
}


// ===== 002bd4c0 kbifTriggerFlr_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbifTriggerFlr_GH100(long param_1)

{
  uint uVar1;
  ulong uVar2;
  uint local_c;
  
  local_c = 0;
  uVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x68,&local_c);
  if (uVar1 != 0) {
    nvAssertFailedNoLog("Config space read of device control failed\n",
                        "src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x63e);
    return (ulong)uVar1;
  }
  local_c = local_c | 0x8000;
  uVar2 = (**(code **)(param_1 + 0x1b8))(param_1,0x68);
  if ((int)uVar2 == 0) {
    return uVar2;
  }
  nvAssertFailedNoLog("FLR trigger failed\n","src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",
                      0x64a);
  return uVar2 & 0xffffffff;
}


// ===== 002bd560 kbifRestoreBarsAndCommand_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifRestoreBarsAndCommand_GH100(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  uint *puVar4;
  
  puVar4 = (uint *)(param_2 + 0x2458);
  do {
    uVar1 = *puVar4;
    if (uVar1 != 0xffff) {
      (**(code **)(param_1 + 0x1b8))
                (param_1,uVar1,*(undefined4 *)(param_2 + 0x3d0 + (ulong)(uVar1 >> 2) * 4));
    }
    puVar4 = puVar4 + 1;
  } while (puVar4 != (uint *)(param_2 + 0x2474));
  (**(code **)(param_1 + 0x1b8))(param_1,4,*(undefined4 *)(param_2 + 0x3d4));
  iVar2 = (**(code **)(*(long *)(param_1 + 0x1b60) + 0x180))(param_1);
  uVar3 = 0x42;
  if (*(int *)(param_1 + 0x8e8) == iVar2) {
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 002bd620 kbifPrepareForFullChipReset_GH100 =====

void kbifPrepareForFullChipReset_GH100(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  
  if (*(char *)(param_2 + 0x3b0) == '\0') {
    nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x694,
                 "kbifPrepareForFullChipReset_GH100",4,
                 "NVRM: FLR is NOT supported! Failing early in fullchip reset sequence\n");
    *(undefined1 *)(param_1 + 0x4b6) = 0;
    return;
  }
  if (*(char *)(param_2 + 0x23f4) == '\0') {
    lVar1 = *(long *)(param_1 + 0x1ce8);
    *(undefined1 *)(param_1 + 0x4b6) = 1;
    if ((lVar1 != 0) && (*(char *)(lVar1 + 0x2e0) != '\0')) {
      iVar2 = knvlinkPrepareForXVEReset_IMPL(param_1,lVar1,0);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x6a6,
                     "kbifPrepareForFullChipReset_GH100",4,
                     "NVRM: NVLink prepare for fullchip reset failed.\n");
      }
    }
    *(undefined1 *)(param_1 + 0x4b6) = 0;
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x699,
               "kbifPrepareForFullChipReset_GH100",4,
               "NVRM: FLR is force disabled using regkey/similar mechanism. Failing early.\n");
  *(undefined1 *)(param_1 + 0x4b6) = 0;
  return;
}


// ===== 002bd720 kbifGetEccCounts_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbifGetEccCounts_GH100(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x84a54,0);
  uVar2 = regRead032(param_1 + 0x3a18,0,0,0x84a58,0);
  iVar3 = (**(code **)(**(long **)(param_2 + 0x24c8) + 0x28))(*(long **)(param_2 + 0x24c8),0x43c);
  iVar4 = (**(code **)(**(long **)(param_2 + 0x24c8) + 0x28))(*(long **)(param_2 + 0x24c8),0x3c8);
  return ((((uVar1 >> 0x10) + (uVar2 >> 0x10)) - (uint)(iVar3 == 0)) + 2) - (uint)(iVar4 == 0);
}


// ===== 002bd7c0 kbifDoFullChipReset_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbifDoFullChipReset_GH100(long param_1,long param_2)

{
  ulong uVar1;
  
  if ((*(char *)(param_2 + 0x3b0) != '\0') && (*(char *)(param_2 + 0x23f4) == '\0')) {
    uVar1 = (**(code **)(param_2 + 0x288))();
    if ((int)uVar1 != 0) {
      nvAssertOkFailedNoLog
                (uVar1 & 0xffffffff,"status = kbifDoFunctionLevelReset_HAL(pGpu, pKernelBif)",
                 "src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x6ec);
      uVar1 = uVar1 & 0xffffffff;
    }
    *(undefined1 *)(param_1 + 0x44f) = 1;
    return uVar1;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x6f1,"kbifDoFullChipReset_GH100"
               ,4,"NVRM: FLR is either not supported or is disabled.\n");
  return 0;
}


// ===== 002bd860 kbifAllowGpuReqPcieAtomics_GH100 =====

undefined1 kbifAllowGpuReqPcieAtomics_GH100(void)

{
  return *(undefined1 *)(*(long *)(g_pSys + 0x208) + 0x6d);
}


// ===== 002bd880 kbifDoSecondaryBusHotReset_GH100 =====

void kbifDoSecondaryBusHotReset_GH100(void)

{
  kbifDoSecondaryBusHotReset_GM107();
  return;
}


// ===== 002bd890 kbifIsC2CP2PSupported_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

bool kbifIsC2CP2PSupported_GH100(long param_1,long param_2,long param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  uint local_64;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  int local_48;
  undefined8 local_44;
  undefined8 local_3c;
  undefined8 local_34;
  int local_2c;
  
  local_60 = 0;
  lVar1 = *(long *)(param_3 + 7000);
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_44 = 0;
  local_3c = 0;
  local_34 = 0;
  local_2c = 0;
  local_64 = 0;
  iVar2 = gpumgrGetGpuAttachInfo(&local_64,0);
  if (iVar2 == 0) {
    if ((param_3 == param_1) || (local_64 < 3)) {
      if ((*(char *)(param_2 + 0x3a8) == '\0') || (*(char *)(lVar1 + 0x3a8) == '\0')) {
        return false;
      }
      iVar2 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x2080182b,&local_60,0x1c);
      if (iVar2 == 0) {
        iVar2 = (**(code **)(param_3 + 0x3b90))
                          (param_3 + 0x3b58,*(undefined4 *)(param_3 + 0x3b34),
                           *(undefined4 *)(param_3 + 0x3b3c),0x2080182b,&local_44,0x1c);
        if (iVar2 == 0) {
          if (local_48 == 2) {
            return local_2c == 2;
          }
        }
        else {
          uVar3 = nvstatusToString(iVar2);
          nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x759,
                       "kbifIsC2CP2PSupported_GH100",4,
                       "NVRM: GPU1 NV2080_CTRL_CMD_BUS_GET_C2C_INFO failed %s (0x%x)\n",uVar3,iVar2)
          ;
        }
      }
      else {
        uVar3 = nvstatusToString(iVar2);
        nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x74c,
                     "kbifIsC2CP2PSupported_GH100",4,
                     "NVRM: GPU0 NV2080_CTRL_CMD_BUS_GET_C2C_INFO failed %s (0x%x)\n",uVar3,iVar2);
      }
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x732,
                 "kbifIsC2CP2PSupported_GH100",4,"NVRM: Unable to get number of GPU attached\n");
  }
  return false;
}


// ===== 002bda90 kbifConstructXtlAperture_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifConstructXtlAperture_GH100(long param_1,long param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = (**(code **)(param_1 + 0x430))();
  iVar2 = ioaprtInit(param_2 + 0x2478,*(undefined8 *)(param_1 + 0x1a18),uVar1,0x1000);
  if (iVar2 == 0) {
    return;
  }
  nvAssertFailedNoLog("ioaprtInit(&pKernelBif->pBifXtlAperture, pGpu->pIOApertures[DEVICE_INDEX_GPU], xtlBaseAddress, DRF_SIZE(NV_XTL_EP_PRI)) == NV_OK"
                      ,"src/kernel/gpu/bif/arch/hopper/kernel_bif_gh100.c",0x76f);
  return;
}


// ===== 002bdb00 _kbifSavePcieConfigRegisters_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _kbifSavePcieConfigRegisters_GM107(long param_1,long param_2,long *param_3)

{
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  int iVar4;
  uint uVar5;
  long local_40;
  
  local_40 = 0;
  if ((short)param_3[2] != 0) {
    do {
      iVar4 = 0;
      lVar1 = local_40 * 4;
      uVar5 = (int)local_40 << 5;
      do {
        uVar2 = 1 << ((byte)iVar4 & 0x1f);
        if ((*(uint *)(param_3[1] + lVar1) & uVar2) == 0) {
LAB_002bdb50:
          if ((*(uint *)(*param_3 + lVar1) & uVar2) != 0) goto LAB_002bdb5a;
        }
        else {
          if ((*(uint *)(*param_3 + lVar1) & uVar2) == 0) {
            nvAssertFailedNoLog("(pRegmapRef->xveRegMapWrite[index] & mask) == 0 || (pRegmapRef->xveRegMapValid[index] & mask) != 0"
                                ,"src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x164);
            goto LAB_002bdb50;
          }
LAB_002bdb5a:
          uVar3 = (**(code **)(param_1 + 0x188))
                            (param_1,*(undefined1 *)((long)param_3 + 0x14),(short)uVar5 * 4,
                             param_3[3] + (ulong)(uVar5 & 0xffff) * 4);
          if ((int)uVar3 != 0) {
            return uVar3;
          }
        }
        iVar4 = iVar4 + 1;
        uVar5 = uVar5 + 1;
      } while (iVar4 != 0x20);
      local_40 = local_40 + 1;
    } while ((ushort)local_40 < *(ushort *)(param_3 + 2));
  }
  *(undefined1 *)(param_2 + 0x3b4) = 1;
  return 0;
}


// ===== 002bdc40 _kbifRestorePcieConfigRegisters_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _kbifRestorePcieConfigRegisters_GM107(long param_1,long param_2,long param_3)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  int iVar7;
  ushort uVar8;
  ushort uVar9;
  ushort local_6a;
  long local_60;
  undefined1 local_54 [2];
  undefined1 local_52 [2];
  undefined1 local_50 [32];
  
  uVar5 = *(ulong *)(param_1 + 0x878);
  cVar2 = *(char *)(param_2 + 0x3b3);
  lVar4 = osPciInitHandle(uVar5 >> 0x20,uVar5 >> 8 & 0xff,uVar5 & 0xff,
                          *(undefined1 *)(param_3 + 0x14),local_54,local_52);
  if (lVar4 == 0) {
    nvAssertFailedNoLog("handle","src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x1e3);
    uVar6 = 0x3d;
  }
  else {
    if ((*(int *)(param_1 + 0x4b34) == 4) && (cVar2 != '\0')) {
      timeoutSet(param_1 + 0x1af0,local_50,0,0);
      do {
        uVar3 = osPciReadDword(lVar4,4);
        iVar7 = timeoutCheck(param_1 + 0x1af0,local_50,0x1f1);
        if (iVar7 == 0x65) {
          nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",500,
                       "_kbifRestorePcieConfigRegisters_GM107",4,
                       "NVRM: Timeout waiting for PCIE Config Space Restore from PMU, RM takes over\n"
                      );
          puVar1 = (uint *)(*(long *)(param_3 + 0x18) + 4);
          *puVar1 = *puVar1 | 2;
          osPciWriteDword(lVar4,4,*(undefined4 *)(*(long *)(param_3 + 0x18) + 4));
          osPciWriteDword(lVar4,0x10,*(undefined4 *)(*(long *)(param_3 + 0x18) + 0x10));
          break;
        }
      } while ((uVar3 & 2) == 0);
    }
    else {
      (**(code **)(param_2 + 0x300))(param_1,param_2,lVar4,*(undefined8 *)(param_3 + 0x18));
      uVar3 = osPciReadDword(lVar4,4);
      osPciWriteDword(lVar4,4,uVar3 | 6);
      uVar8 = 0;
      if (*(short *)(param_3 + 0x10) != 0) {
        local_60 = 0;
        local_6a = 0;
        do {
          uVar9 = uVar8 << 7;
          iVar7 = 0;
          do {
            if (((*(uint *)(*(long *)(param_3 + 8) + local_60) & 1 << ((byte)iVar7 & 0x1f)) != 0) &&
               (uVar9 != 4)) {
              uVar5 = (ulong)((uint)local_6a + iVar7 & 0xffff);
              osGpuWriteReg032(param_1,(-(uint)(*(char *)(param_3 + 0x14) == '\0') & 0xffffe000) +
                                       0x8a000 + (uint)uVar9,
                               *(undefined4 *)(*(long *)(param_3 + 0x18) + uVar5 * 4));
              if ((*(char *)(param_3 + 0x14) != '\0') &&
                 (uVar6 = (**(code **)(param_1 + 400))
                                    (param_1,*(char *)(param_3 + 0x14),(uint)uVar9,
                                     *(undefined4 *)(*(long *)(param_3 + 0x18) + uVar5 * 4)),
                 (int)uVar6 != 0)) {
                return uVar6;
              }
            }
            iVar7 = iVar7 + 1;
            uVar9 = uVar9 + 4;
          } while (iVar7 != 0x20);
          local_6a = local_6a + 0x20;
          local_60 = local_60 + 4;
          uVar8 = uVar8 + 1;
        } while (uVar8 < *(ushort *)(param_3 + 0x10));
      }
      if (cVar2 != '\0') {
        puVar1 = (uint *)(*(long *)(param_3 + 0x18) + 4);
        *puVar1 = *puVar1 | 2;
      }
      osPciWriteDword(lVar4,4,*(undefined4 *)(*(long *)(param_3 + 0x18) + 4));
    }
    uVar6 = 0;
  }
  return uVar6;
}


// ===== 002bdf00 kbifGetPcieConfigAccessTestRegisters_GM107 =====

void kbifGetPcieConfigAccessTestRegisters_GM107
               (undefined8 param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  *param_3 = 0;
  *param_4 = 0x100;
  return;
}


// ===== 002bdf20 kbifVerifyPcieConfigAccessTestRegisters_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbifVerifyPcieConfigAccessTestRegisters_GM107
                (long param_1,undefined8 param_2,uint param_3,uint param_4)

{
  uint uVar1;
  ulong uVar2;
  uint local_2c [3];
  
  uVar1 = (**(code **)(param_1 + 0x178))(param_1,0,local_2c);
  if (uVar1 != 0) {
    nvAssertOkFailedNoLog
              (uVar1,"GPU_BUS_CFG_RD32(pGpu, NV_XVE_ID, &data)",
               "src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x6d);
    return (ulong)uVar1;
  }
  if (((short)local_2c[0] == 0x10de) && (local_2c[0] == param_3)) {
    uVar2 = (**(code **)(param_1 + 0x178))(param_1,0x100,local_2c);
    if ((int)uVar2 != 0) {
      nvAssertOkFailedNoLog
                (uVar2 & 0xffffffff,"GPU_BUS_CFG_RD32(pGpu, NV_XVE_VCCAP_HDR, &data)",
                 "src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x74);
      return uVar2 & 0xffffffff;
    }
    if (((local_2c[0] & 0xfffff) == 0x10002) && (local_2c[0] == param_4)) {
      return uVar2;
    }
  }
  return 0x56;
}


// ===== 002be000 kbifRearmMSI_GM107 =====

void kbifRearmMSI_GM107(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = gpuSanityCheckRegisterAccess_IMPL(param_1,0,0);
  if (iVar1 != 0) {
    return;
  }
  osGpuWriteReg032(param_1,0x88704,0);
  return;
}


// ===== 002be040 kbifIsMSIEnabledInHW_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

byte kbifIsMSIEnabledInHW_GM107(long param_1)

{
  int iVar1;
  undefined1 local_c [2];
  byte local_a;
  
  if (*(char *)(param_1 + 0x4913) != '\0') {
    return 0;
  }
  iVar1 = (**(code **)(param_1 + 0x178))(param_1,0x68,local_c);
  if (iVar1 == 0) {
    return local_a & 1;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0xb1,
               "kbifIsMSIEnabledInHW_GM107",4,"NVRM: unable to read NV_XVE_MSI_CTRL\n");
  return local_a & 1;
}


// ===== 002be0c0 kbifIsPciIoAccessEnabled_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kbifIsPciIoAccessEnabled_GM107(long param_1)

{
  int iVar1;
  uint local_c;
  
  local_c = 0;
  iVar1 = (**(code **)(param_1 + 0x178))(param_1,4,&local_c);
  if (iVar1 == 0) {
    return local_c & 1;
  }
  return 0;
}


// ===== 002be100 kbifIs3dController_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbifIs3dController_GM107(long param_1)

{
  int iVar1;
  uint local_c;
  
  local_c = 0;
  iVar1 = (**(code **)(param_1 + 0x178))(param_1,8,&local_c);
  if (iVar1 == 0) {
    return (ulong)CONCAT21((short)(local_c >> 0x10),local_c >> 8 == 0x30200);
  }
  return 0;
}


// ===== 002be150 kbifEnableNoSnoop_GM107 =====

undefined8 kbifEnableNoSnoop_GM107(long param_1,undefined8 param_2,char param_3)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x88080,0);
  regWrite032(param_1 + 0x3a18,0,0,0x88080,(uint)(param_3 != '\0') << 0xb | uVar1 & 0xfffff7ff,0);
  return 0;
}


// ===== 002be1b0 kbifPcieConfigEnableRelaxedOrdering_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifPcieConfigEnableRelaxedOrdering_GM107(long param_1)

{
  int iVar1;
  uint local_c;
  
  iVar1 = (**(code **)(param_1 + 0x178))(param_1,0x80,&local_c);
  if (iVar1 == 0) {
    (**(code **)(param_1 + 0x170))(param_1,0x80,local_c | 0x10);
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x11f,
               "kbifPcieConfigEnableRelaxedOrdering_GM107",4,
               "NVRM: Unable to read NV_XVE_DEVICE_CONTROL_STATUS!\n");
  return;
}


// ===== 002be230 kbifPcieConfigDisableRelaxedOrdering_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifPcieConfigDisableRelaxedOrdering_GM107(long param_1)

{
  int iVar1;
  uint local_c;
  
  iVar1 = (**(code **)(param_1 + 0x178))(param_1,0x80,&local_c);
  if (iVar1 == 0) {
    local_c = local_c & 0xffffffef;
    (**(code **)(param_1 + 0x170))(param_1,0x80);
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x13b,
               "kbifPcieConfigDisableRelaxedOrdering_GM107",4,
               "NVRM: Unable to read NV_XVE_DEVICE_CONTROL_STATUS!\n");
  return;
}


// ===== 002be2b0 kbifSavePcieConfigRegisters_GM107 =====

int kbifSavePcieConfigRegisters_GM107(long param_1,long param_2)

{
  int iVar1;
  
  if (((*(char *)(param_2 + 0x23d4) == '\0') && (*(int *)(param_1 + 0x4b34) != 1)) &&
     ((*(char *)(param_2 + 0x3b6) == '\0' || (*(char *)(param_2 + 0x3b5) == '\0')))) {
    return 0;
  }
  iVar1 = _kbifSavePcieConfigRegisters_GM107(param_1,param_2,param_2 + 0x2400);
  if (iVar1 == 0) {
    iVar1 = 0;
    if (((*(int *)(param_1 + 0x4b34) != 1) && (*(char *)(param_2 + 0x23d4) == '\0')) &&
       (*(char *)(param_2 + 0x3b2) != '\0')) {
      iVar1 = _kbifSavePcieConfigRegisters_GM107(param_1,param_2,param_2 + 0x2428);
      if (iVar1 != 0) {
        nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x1b9,
                     "kbifSavePcieConfigRegisters_GM107",4,
                     "NVRM: Saving PCIe config space failed for azalia.\n");
        nvAssertFailedNoLog(&DAT_00cf484b,"src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x1ba
                           );
      }
    }
    return iVar1;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x1a2,
               "kbifSavePcieConfigRegisters_GM107",4,
               "NVRM: Saving PCIe config space failed for gpu.\n");
  nvAssertFailedNoLog(&DAT_00cf484b,"src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x1a3);
  return iVar1;
}


// ===== 002be3f0 kbifRestorePcieConfigRegisters_GM107 =====

int kbifRestorePcieConfigRegisters_GM107(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  long local_60;
  long local_58;
  undefined1 local_50 [32];
  
  if (*(long *)(param_2 + 0x2418) == 0) {
    nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x262,
                 "kbifRestorePcieConfigRegisters_GM107",4,"NVRM: Config space buffer is NULL!\n");
    nvAssertFailedNoLog(&DAT_00cf484b,"src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x263);
    return 0x57;
  }
  iVar1 = _kbifRestorePcieConfigRegisters_GM107(param_1,param_2,param_2 + 0x2400);
  if (iVar1 == 0) {
    if ((*(int *)(param_1 + 0x4b34) == 4) || (*(char *)(param_2 + 0x23d5) != '\0')) {
      if ((*(char *)(param_1 + 0x446) == '\0') && (*(char *)(param_1 + 0x490e) == '\0')) {
        osGetPerformanceCounter(&local_60);
        timeoutSet(param_1 + 0x1af0,local_50,0,0);
        iVar1 = regRead032(param_1 + 0x3a18,0,0,0,0);
        do {
          if (*(int *)(param_1 + 0x8e8) == iVar1) {
            osGetPerformanceCounter(&local_58);
            iVar1 = (int)local_58 - (int)local_60;
            if (0xffffffff < (ulong)(local_58 - local_60)) {
              iVar1 = -1;
            }
            nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x293,
                         "kbifRestorePcieConfigRegisters_GM107",4,
                         "NVRM: Time spend on GPU back on bus is 0x%x ns,\n",iVar1);
            return 0;
          }
          pcVar4 = "GC6 exit";
          if (*(char *)(param_2 + 0x23d5) != '\0') {
            pcVar4 = "FLR";
          }
          nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x283,
                       "kbifRestorePcieConfigRegisters_GM107",1,
                       "NVRM: GPU not back on the bus after %s, 0x%x != 0x%x!\n",pcVar4,iVar1,
                       *(int *)(param_1 + 0x8e8));
          iVar1 = regRead032(param_1 + 0x3a18,0,0,0,0);
          nvAssertFailedNoLog(&DAT_00cf484b,"src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",
                              0x287);
          iVar2 = timeoutCheck(param_1 + 0x1af0,local_50,0x288);
        } while (iVar2 != 0x65);
        pcVar4 = "GC6 exit";
        if (*(char *)(param_2 + 0x23d5) != '\0') {
          pcVar4 = "FLR";
        }
        nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x28b,
                     "kbifRestorePcieConfigRegisters_GM107",4,
                     "NVRM: Timeout GPU not back on the bus after %s,\n",pcVar4);
        return 0x65;
      }
    }
    else if ((*(char *)(param_2 + 0x3b2) != '\0') &&
            (iVar1 = _kbifRestorePcieConfigRegisters_GM107(param_1,param_2,param_2 + 0x2428),
            iVar1 != 0)) {
      nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x2a6,
                   "kbifRestorePcieConfigRegisters_GM107",4,
                   "NVRM: Restoring PCIe config space failed for azalia.\n");
      uVar3 = 0x2a7;
      goto LAB_002be653;
    }
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x26c,
               "kbifRestorePcieConfigRegisters_GM107",4,
               "NVRM: Restoring PCIe config space failed for gpu.\n");
  uVar3 = 0x26d;
LAB_002be653:
  nvAssertFailedNoLog(&DAT_00cf484b,"src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",uVar3);
  return iVar1;
}


// ===== 002be730 kbifGetXveStatusBits_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifGetXveStatusBits_GM107(long param_1,long param_2,uint *param_3,uint *param_4)

{
  int iVar1;
  uint local_2c;
  
  iVar1 = (**(code **)(param_1 + 0x178))(param_1,0x80,&local_2c);
  if (iVar1 != 0) {
    nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x2c5,
                 "kbifGetXveStatusBits_GM107",4,
                 "NVRM: Unable to read NV_XVE_DEVICE_CONTROL_STATUS!\n");
  }
  if (param_3 == (uint *)0x0) {
    return 0xffff;
  }
  *param_3 = 0;
  if (*(char *)(param_1 + 0x4910) == '\0') {
    if (param_4 != (uint *)0x0) {
      *param_4 = local_2c;
    }
    if ((local_2c & 0x10000) != 0) {
      *param_3 = *param_3 | 1;
    }
    if ((local_2c & 0x20000) != 0) {
      *param_3 = *param_3 | 2;
    }
    if ((local_2c & 0x40000) != 0) {
      *param_3 = *param_3 | 4;
    }
    if ((local_2c & 0x80000) != 0) {
      *param_3 = *param_3 | 8;
    }
    if (*(char *)(param_2 + 0x3cd) != '\0') {
      *(undefined1 *)(param_2 + 0x3cd) = 0;
      *param_3 = *param_3 | 0x10;
    }
  }
  else if (param_4 != (uint *)0x0) {
    *param_4 = 0;
  }
  return 0;
}


// ===== 002be850 kbifClearXveStatus_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifClearXveStatus_GM107(long param_1,undefined8 param_2,int *param_3)

{
  int iVar1;
  int local_c;
  
  if (param_3 == (int *)0x0) {
    iVar1 = (**(code **)(param_1 + 0x178))(param_1,0x80,&local_c);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x30b,
                   "kbifClearXveStatus_GM107",4,
                   "NVRM: Unable to read NV_XVE_DEVICE_CONTROL_STATUS!\n");
    }
  }
  else {
    local_c = *param_3;
    if (local_c == 0) {
      return 0;
    }
  }
  (**(code **)(param_1 + 0x170))(param_1,0x80,local_c);
  return 0;
}


// ===== 002be8f0 kbifGetXveAerBits_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifGetXveAerBits_GM107(long param_1,undefined8 param_2,uint *param_3)

{
  int iVar1;
  undefined8 uVar2;
  uint local_20;
  uint local_1c;
  
  if (param_3 == (uint *)0x0) {
    return 0xffff;
  }
  *param_3 = 0;
  iVar1 = (**(code **)(param_1 + 0x178))(param_1,0x424,&local_20);
  if (iVar1 == 0) {
    uVar2 = (**(code **)(param_1 + 0x178))(param_1,0x430,&local_1c);
    if ((int)uVar2 == 0) {
      if (*(char *)(param_1 + 0x4910) == '\0') {
        if ((local_20 & 0x10) != 0) {
          *param_3 = *param_3 | 2;
        }
        if ((local_20 & 0x1000) != 0) {
          *param_3 = *param_3 | 4;
        }
        if ((local_20 & 0x4000) != 0) {
          *param_3 = *param_3 | 0x10;
        }
        if ((local_20 & 0x10000) != 0) {
          *param_3 = *param_3 | 0x40;
        }
        if ((local_20 & 0x40000) != 0) {
          *param_3 = *param_3 | 0x100;
        }
        if ((local_20 & 0x100000) != 0) {
          *param_3 = *param_3 | 0x400;
        }
        if ((local_1c & 1) != 0) {
          *param_3 = *param_3 | 0x10000;
        }
        if ((local_1c & 0x40) != 0) {
          *param_3 = *param_3 | 0x20000;
        }
        if ((local_1c & 0x80) != 0) {
          *param_3 = *param_3 | 0x40000;
        }
        if ((local_1c & 0x100) != 0) {
          *param_3 = *param_3 | 0x80000;
        }
        if ((local_1c & 0x1000) != 0) {
          *param_3 = *param_3 | 0x100000;
        }
        if ((local_1c & 0x2000) == 0) {
          return 0;
        }
        *param_3 = *param_3 | 0x200000;
      }
      return uVar2;
    }
    nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x337,
                 "kbifGetXveAerBits_GM107",4,"NVRM: Unable to read NV_XVE_AER_CORR_ERR\n");
  }
  else {
    nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x332,
                 "kbifGetXveAerBits_GM107",4,"NVRM: Unable to read NV_XVE_AER_UNCORR_ERR\n");
  }
  return 0xffff;
}


// ===== 002bea80 kbifClearXveAer_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifClearXveAer_GM107(long param_1,undefined8 param_2,ulong param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = ((uint)param_3 & 2) << 3;
  if ((param_3 & 4) != 0) {
    uVar2 = (uint)CONCAT11(0x10,(char)uVar2);
  }
  if ((param_3 & 0x10) != 0) {
    uVar2 = uVar2 | 0x4000;
  }
  if ((param_3 & 0x40) != 0) {
    uVar2 = uVar2 | 0x10000;
  }
  if ((param_3 & 0x100) != 0) {
    uVar2 = uVar2 | 0x40000;
  }
  if ((param_3 & 0x400) != 0) {
    uVar2 = uVar2 | 0x100000;
  }
  uVar3 = (uint)(param_3 >> 0x10) & 1;
  uVar1 = uVar3 | 0x40;
  if ((param_3 & 0x20000) == 0) {
    uVar1 = uVar3;
  }
  if ((param_3 & 0x40000) != 0) {
    uVar1 = uVar1 | 0x80;
  }
  if ((param_3 & 0x80000) != 0) {
    uVar1 = uVar1 | 0x100;
  }
  if ((param_3 & 0x100000) == 0) {
    if ((param_3 & 0x200000) == 0) {
      if (uVar2 != 0) {
        (**(code **)(param_1 + 0x170))(param_1,0x424);
      }
      if (uVar1 == 0) {
        return 0;
      }
      goto LAB_002beb1c;
    }
LAB_002beb15:
    uVar1 = uVar1 | 0x2000;
  }
  else {
    uVar1 = uVar1 | 0x1000;
    if ((param_3 & 0x200000) != 0) goto LAB_002beb15;
  }
  if (uVar2 != 0) {
    (**(code **)(param_1 + 0x170))(param_1,0x424);
  }
LAB_002beb1c:
  (**(code **)(param_1 + 0x170))(param_1,0x430,uVar1);
  return 0;
}


// ===== 002beba0 kbifGetPciConfigSpacePriMirror_GM107 =====

undefined8
kbifGetPciConfigSpacePriMirror_GM107
          (undefined8 param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  *param_3 = 0x88000;
  *param_4 = 0x1000;
  return 0;
}


// ===== 002bebc0 kbifExecC73War_GM107 =====

void kbifExecC73War_GM107(long param_1)

{
  uint *puVar1;
  long lVar2;
  uint uVar3;
  long lVar4;
  
  lVar2 = g_pSys;
  lVar4 = sysGetOs_IMPL(g_pSys);
  if (*(int *)(*(long *)(lVar2 + 0x208) + 0xb4) != 0x102e) {
    return;
  }
  if (*(char *)(lVar4 + 0x4d) == '\0') {
    if (*(long *)(param_1 + 0x1d98) != 0) {
      puVar1 = (uint *)(*(long *)(param_1 + 0x1d98) + 0xf04);
      *puVar1 = *puVar1 | 0x800000;
      return;
    }
  }
  else if (*(char *)(param_1 + 0x1d8f) != '\0') {
    uVar3 = osPciReadDword(*(undefined8 *)(param_1 + 0x1d90),0xf04);
    osPciWriteDword(*(undefined8 *)(param_1 + 0x1d90),0xf04,uVar3 | 0x800000);
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x3da,"kbifExecC73War_GM107",4,
               "NVRM: Cannot turn off L0s on C73 chipset, suspend/resume may fail (Bug 400044).\n");
  return;
}


// ===== 002bec90 kbifGetBusOptionsAddr_GM107 =====

undefined8
kbifGetBusOptionsAddr_GM107(undefined8 param_1,undefined8 param_2,uint param_3,undefined4 *param_4)

{
  if (param_3 == 2) {
    *param_4 = 0x84;
    return 0;
  }
  if (param_3 < 3) {
    if (param_3 != 0) {
      *param_4 = 0x88;
      return 0;
    }
    *param_4 = 0x80;
    return 0;
  }
  if (param_3 == 3) {
    *param_4 = 0xa0;
    return 0;
  }
  if (param_3 == 4) {
    *param_4 = 0x260;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x3fe,
               "kbifGetBusOptionsAddr_GM107",4,"NVRM: Invalid register type passed 0x%x\n",param_3);
  return 0xffff;
}


// ===== 002bed30 kbifDisableSysmemAccess_GM107 =====

undefined8 kbifDisableSysmemAccess_GM107(void)

{
  nvAssertFailedNoLog("RMCFG_FEATURE_PLATFORM_WINDOWS",
                      "src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x413);
  return 0x56;
}


// ===== 002bed60 kbifInitXveRegMap_GM107 =====

undefined8 kbifInitXveRegMap_GM107(undefined8 param_1,long param_2,char param_3)

{
  if (param_3 == '\0') {
    *(undefined1 *)(param_2 + 0x2414) = 0;
    *(long *)(param_2 + 0x2418) = param_2 + 0x3d0;
    *(undefined1 **)(param_2 + 0x2400) = xveRegMapValid;
    *(undefined1 **)(param_2 + 0x2408) = xveRegMapWrite;
    *(undefined4 *)(param_2 + 0x2410) = 0x150015;
    *(undefined8 *)(param_2 + 0x2420) = 0;
    return 0;
  }
  if (param_3 == '\x01') {
    *(undefined1 *)(param_2 + 0x243c) = 1;
    *(long *)(param_2 + 0x2440) = param_2 + 0x13d0;
    *(undefined1 **)(param_2 + 0x2428) = xve1RegMapValid;
    *(undefined1 **)(param_2 + 0x2430) = xve1RegMapWrite;
    *(undefined4 *)(param_2 + 0x2438) = 0xf000f;
    *(undefined8 *)(param_2 + 0x2448) = 0;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x44f,"kbifInitXveRegMap_GM107",
               4,"NVRM: Invalid argument, func: %d.\n",param_3);
  nvAssertFailedNoLog(&DAT_00cf484b,"src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x450);
  return 0x1f;
}


// ===== 002bee50 kbifStopSysMemRequests_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbifStopSysMemRequests_GM107(long param_1,undefined8 param_2,char param_3)

{
  uint uVar1;
  ulong uVar2;
  uint local_1c [3];
  
  uVar1 = (**(code **)(param_1 + 0x178))(param_1,4,local_1c);
  if (uVar1 == 0) {
    uVar1 = local_1c[0] & 0xfffffffb;
    local_1c[0] = local_1c[0] | 4;
    if (param_3 != '\0') {
      local_1c[0] = uVar1;
    }
    uVar2 = (**(code **)(param_1 + 0x170))(param_1,4);
    if ((int)uVar2 != 0) {
      nvAssertOkFailedNoLog
                (uVar2 & 0xffffffff,"GPU_BUS_CFG_WR32(pGpu, NV_XVE_DEV_CTRL, regVal)",
                 "src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x475);
      uVar2 = uVar2 & 0xffffffff;
    }
    return uVar2;
  }
  nvAssertOkFailedNoLog
            (uVar1,"GPU_BUS_CFG_RD32(pGpu, NV_XVE_DEV_CTRL, &regVal)",
             "src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x46a);
  return (ulong)uVar1;
}


// ===== 002bef10 kbifRestoreBar0_GM107 =====

void kbifRestoreBar0_GM107(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  osPciWriteDword(param_3,0x10,*(undefined4 *)(param_4 + 0x10));
  return;
}


// ===== 002bef30 kbifAnyBarsAreValid_GM107 =====

bool kbifAnyBarsAreValid_GM107(long param_1,long param_2)

{
  ulong uVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  undefined1 local_1c [2];
  undefined1 local_1a [2];
  
  uVar1 = *(ulong *)(param_1 + 0x878);
  uVar4 = osPciInitHandle(uVar1 >> 0x20,uVar1 >> 8 & 0xff,uVar1 & 0xff,0,local_1c,local_1a);
  iVar3 = osPciReadDword(uVar4,0x10);
  bVar2 = true;
  if (iVar3 != *(int *)(param_2 + 0x3e0)) {
    iVar3 = osPciReadDword(uVar4,0x14);
    bVar2 = false;
    if (iVar3 == *(int *)(param_2 + 0x3e4)) {
      iVar3 = osPciReadDword(uVar4,0x18);
      return *(int *)(param_2 + 1000) == iVar3;
    }
  }
  return bVar2;
}


// ===== 002befd0 kbifRestoreBarsAndCommand_GM107 =====

undefined8 kbifRestoreBarsAndCommand_GM107(long param_1,long param_2)

{
  ulong uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 local_2c [2];
  undefined1 local_2a [10];
  
  uVar1 = *(ulong *)(param_1 + 0x878);
  uVar3 = osPciInitHandle(uVar1 >> 0x20,uVar1 >> 8 & 0xff,uVar1 & 0xff,0,local_2c,local_2a);
  osPciWriteDword(uVar3,0x10,*(undefined4 *)(param_2 + 0x3e0));
  osPciWriteDword(uVar3,0x14,*(undefined4 *)(param_2 + 0x3e4));
  osPciWriteDword(uVar3,0x18,*(undefined4 *)(param_2 + 1000));
  osPciWriteDword(uVar3,0x1c,*(undefined4 *)(param_2 + 0x3ec));
  osPciWriteDword(uVar3,0x20,*(undefined4 *)(param_2 + 0x3f0));
  osPciWriteDword(uVar3,0x24,*(undefined4 *)(param_2 + 0x3f4));
  osPciWriteDword(uVar3,4,*(undefined4 *)(param_2 + 0x3d4));
  iVar2 = regRead032(param_1 + 0x3a18,0,0,0,0);
  uVar3 = 0x42;
  if (iVar2 == *(int *)(param_1 + 0x8e8)) {
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 002bf0e0 kbifPrepareForFullChipReset_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifPrepareForFullChipReset_GM107(long param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  int iVar3;
  
  *(undefined1 *)(param_1 + 0x4b6) = 1;
  uVar1 = *(undefined8 *)(&DAT_00001b90 + param_1);
  lVar2 = *(long *)(param_1 + 0x1ce8);
  iVar3 = (**(code **)(*(long *)(param_1 + 0x1b60) + 0x170))();
  if (iVar3 != 0) {
    nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x520,
                 "kbifPrepareForFullChipReset_GM107",4,"NVRM: MC prepare for XVE reset failed.\n");
  }
  iVar3 = kbusPrepareForXVEReset_GM107(param_1,uVar1);
  if (iVar3 != 0) {
    nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x531,
                 "kbifPrepareForFullChipReset_GM107",4,"NVRM: BUS prepare for devinit failed.\n");
  }
  if ((lVar2 != 0) && (*(char *)(lVar2 + 0x2e0) != '\0')) {
    iVar3 = knvlinkPrepareForXVEReset_IMPL(param_1,lVar2,0);
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x53b,
                   "kbifPrepareForFullChipReset_GM107",4,
                   "NVRM: NVLINK prepare for fullchip reset failed.\n");
    }
  }
  iVar3 = (**(code **)(param_2 + 0x338))(param_1,param_2);
  if (iVar3 == 0) {
    *(undefined1 *)(param_1 + 0x4b6) = 0;
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x544,
               "kbifPrepareForFullChipReset_GM107",4,"NVRM: BIF prepare for devinit failed.\n");
  *(undefined1 *)(param_1 + 0x4b6) = 0;
  return;
}


// ===== 002bf250 kbifInit_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifInit_GM107(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x318))(param_1,param_2,0x10);
  return 0;
}


// ===== 002bf270 kbifGetMigrationBandwidth_GM107 =====

ulong kbifGetMigrationBandwidth_GM107(long param_1,undefined8 param_2,uint *param_3)

{
  char cVar1;
  int iVar2;
  ulong uVar3;
  char *pcVar4;
  undefined8 uVar5;
  uint local_38;
  undefined4 local_34;
  undefined8 local_30;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0x2d;
  if (*(char *)(param_1 + 0x909) == '\0') {
    cVar1 = gpuIsPciBusFamily_IMPL();
    if (cVar1 == '\0') {
      return 0x56;
    }
    uVar3 = kbifControlGetPCIEInfo_IMPL(param_1,param_2,&local_30);
    uVar5 = 0x584;
    pcVar4 = "kbifControlGetPCIEInfo(pGpu, pKernelBif, &busInfo)";
    iVar2 = (int)uVar3;
  }
  else {
    uVar3 = kbusSendBusInfo_IMPL(param_1,*(undefined8 *)(&DAT_00001b90 + param_1),&local_30);
    uVar5 = 0x57e;
    pcVar4 = "kbusSendBusInfo(pGpu, GPU_GET_KERNEL_BUS(pGpu), &busInfo)";
    iVar2 = (int)uVar3;
  }
  if (iVar2 == 0) {
    uVar3 = kbifGetPciLinkMaxSpeedByPciGenInfo_IMPL
                      (param_1,param_2,(uint)((ulong)local_30 >> 0x2c) & 0xf,&local_34,uVar5);
    uVar5 = 0x58d;
    pcVar4 = 
    "kbifGetPciLinkMaxSpeedByPciGenInfo(pGpu, pKernelBif, pciLinkGenInfo, &pciLinkMaxSpeed)";
    if ((int)uVar3 == 0) {
      local_30 = 7;
      cVar1 = gpuIsPciBusFamily_IMPL(param_1);
      if (cVar1 == '\0') {
        return 0x56;
      }
      uVar3 = kbifControlGetPCIEInfo_IMPL(param_1,param_2,&local_30);
      uVar5 = 0x594;
      pcVar4 = "kbifControlGetPCIEInfo(pGpu, pKernelBif, &busInfo)";
      if ((int)uVar3 == 0) {
        uVar3 = calculatePCIELinkRateMBps
                          (local_30._4_4_ >> 0x14 & 0x3f,local_34,&local_38,
                           "src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x594);
        if ((int)uVar3 == 0) {
          *param_3 = local_38 / 5;
          return uVar3;
        }
        uVar5 = 0x59c;
        pcVar4 = "calculatePCIELinkRateMBps(lanes, pciLinkMaxSpeed, &pcieLinkRate)";
      }
    }
  }
  nvCheckOkFailedNoLog
            (4,uVar3 & 0xffffffff,pcVar4,"src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",uVar5)
  ;
  return uVar3 & 0xffffffff;
}


// ===== 002bf420 kbifDestruct_GM107 =====

void kbifDestruct_GM107(long param_1)

{
  portMemFree(*(undefined8 *)(param_1 + 0x2420));
  *(undefined8 *)(param_1 + 0x2420) = 0;
  return;
}


// ===== 002bf450 kbifDoSecondaryBusHotReset_GM107 =====

void kbifDoSecondaryBusHotReset_GM107(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  uint uVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined4 uVar5;
  undefined1 local_2c [2];
  undefined1 local_2a [2];
  
  uVar1 = *(undefined8 *)(g_pSys + 0x208);
  uVar3 = osPciInitHandle(*(undefined4 *)(param_1 + 0x1d58),*(undefined1 *)(param_1 + 0x1d5c),
                          *(undefined1 *)(param_1 + 0x1d5d),0,local_2c,local_2a);
  uVar2 = osPciReadWord(uVar3,0x3e);
  uVar4 = (ulong)(uVar2 & 0xffff | 0x40);
  clPcieWriteWord_IMPL
            (uVar1,*(undefined4 *)(param_1 + 0x1d58),*(undefined1 *)(param_1 + 0x1d5c),
             *(undefined1 *)(param_1 + 0x1d5d),*(undefined1 *)(param_1 + 0x1d5e),0x3e,uVar4);
  uVar5 = (undefined4)(uVar4 >> 0x20);
  osDelayUs(1000);
  clPcieWriteWord_IMPL
            (uVar1,*(undefined4 *)(param_1 + 0x1d58),*(undefined1 *)(param_1 + 0x1d5c),
             *(undefined1 *)(param_1 + 0x1d5d),*(undefined1 *)(param_1 + 0x1d5e),0x3e,
             CONCAT44(uVar5,uVar2) & 0xffffffff0000ffbf);
  osDelayUs(100000);
  kbifWaitForConfigAccessAfterReset_IMPL(param_1,param_2,0x2bf4a7);
  return;
}


// ===== 002bf550 kbifSetLtrEnable_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifSetLtrEnable_GM107(long param_1,undefined8 param_2,char param_3)

{
  uint uVar1;
  int iVar2;
  uint local_1c;
  
  iVar2 = (**(code **)(param_1 + 0x178))(param_1,0xa0,&local_1c);
  if (iVar2 == 0) {
    uVar1 = local_1c & 0xfffffbff;
    if (param_3 != '\0') {
      uVar1 = local_1c | 0x400;
    }
    local_1c = uVar1;
    (**(code **)(param_1 + 0x170))(param_1,0xa0);
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x666,"kbifSetLtrEnable_GM107",4
               ,"NVRM: Unable to read NV_XVE_DEVICE_CONTROL_STATUS_2\n");
  return 0xffff;
}


// ===== 002bf5f0 kbifGetLtrEnable_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifGetLtrEnable_GM107(long param_1,undefined8 param_2,byte *param_3)

{
  undefined8 uVar1;
  undefined4 local_1c;
  
  local_1c = 0;
  uVar1 = (**(code **)(param_1 + 0x178))(param_1,0xa0,&local_1c);
  if ((int)uVar1 == 0) {
    *param_3 = local_1c._1_1_ >> 2 & 1;
    return uVar1;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/maxwell/kernel_bif_gm107.c",0x68f,"kbifGetLtrEnable_GM107",4
               ,"NVRM: Unable to read NV_XVE_DEVICE_CONTROL_STATUS_2\n");
  *param_3 = 0;
  return 0xffff;
}


// ===== 002bf670 kbifPrepareForXveReset_GP100 =====

undefined8 kbifPrepareForXveReset_GP100(void)

{
  return 0;
}


// ===== 002bf680 kbifDoFullChipReset_GP10X =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbifDoFullChipReset_GP10X(long param_1,long param_2)

{
  char cVar1;
  long lVar2;
  ulong uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  bool bVar8;
  uint local_3c [3];
  
  lVar2 = *(long *)(g_pSys + 0x208);
  if (*(char *)(param_2 + 0x3b0) == '\0') {
    lVar7 = param_1 + 0x3a18;
    uVar4 = regRead032(lVar7,0,0,0x200,0);
    uVar6 = (**(code **)(param_2 + 0x350))(param_1,param_2);
    regWrite032(lVar7,0,0,0x200,~uVar6 & uVar4,0);
    regRead032(lVar7,0,0,0x200,0);
    regRead032(lVar7,0,0,0x200,0);
    if ((lVar2 != 0) && (*(char *)(lVar2 + 0x48) == '\0')) {
      bVar8 = false;
      goto LAB_002bf963;
    }
LAB_002bf820:
    do {
      lVar7 = param_1 + 0x3a18;
      uVar6 = regRead032(lVar7,0,0,0x8c300,0);
      regWrite032(lVar7,0,0,0x8c300,uVar6 | 0x10,0);
      local_3c[0] = regRead032(lVar7,0,0,0x8c300);
    } while ((local_3c[0] & 0x10) == 0);
    iVar5 = (**(code **)(param_1 + 0x178))(param_1,0x718,local_3c);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,"GPU_BUS_CFG_RD32(pGpu, NV_XVE_SW_RESET, &tempRegVal)",
                 "src/kernel/gpu/bif/arch/pascal/kernel_bif_gp10X.c",0x8f);
      return iVar5;
    }
    uVar3 = *(ulong *)(param_1 + 0x878);
    local_3c[0] = local_3c[0] | 1;
    clPcieWriteDword_IMPL(lVar2,uVar3 >> 0x20,uVar3 >> 8 & 0xff,uVar3 & 0xff,0,0x718,local_3c[0]);
    *(undefined1 *)(param_1 + 0x44f) = 1;
    osDelay(4);
    if (lVar2 != 0) {
LAB_002bf8dc:
      if (*(char *)(lVar2 + 0x48) == '\0') goto LAB_002bf950;
    }
    iVar5 = (**(code **)(param_1 + 0x178))(param_1,0x718,local_3c);
    if (iVar5 == 0) {
      uVar3 = *(ulong *)(param_1 + 0x878);
      local_3c[0] = local_3c[0] & 0xffffff6;
      clPcieWriteDword_IMPL(lVar2,uVar3 >> 0x20,uVar3 >> 8 & 0xff,uVar3 & 0xff,0,0x718,local_3c[0]);
    }
    else {
      nvAssertOkFailedNoLog
                (iVar5,"GPU_BUS_CFG_RD32(pGpu, NV_XVE_SW_RESET, &tempRegVal)",
                 "src/kernel/gpu/bif/arch/pascal/kernel_bif_gp10X.c",0xaf);
    }
  }
  else {
    cVar1 = *(char *)(param_2 + 0x23f4);
    lVar7 = param_1 + 0x3a18;
    uVar4 = regRead032(lVar7,0,0,0x200,0);
    uVar6 = (**(code **)(param_2 + 0x350))(param_1,param_2);
    regWrite032(lVar7,0,0,0x200,~uVar6 & uVar4,0);
    regRead032(lVar7,0,0,0x200,0);
    regRead032(lVar7,0,0,0x200,0);
    if ((lVar2 == 0) || (*(char *)(lVar2 + 0x48) != '\0')) {
      if (cVar1 == '\0') {
        iVar5 = (**(code **)(param_2 + 0x288))(param_1,param_2);
        if (iVar5 == 0) {
          *(undefined1 *)(param_1 + 0x44f) = 1;
          return 0;
        }
        nvAssertOkFailedNoLog
                  (iVar5,"status = kbifDoFunctionLevelReset_HAL(pGpu, pKernelBif)",
                   "src/kernel/gpu/bif/arch/pascal/kernel_bif_gp10X.c",0x7f);
        *(undefined1 *)(param_1 + 0x44f) = 1;
        return iVar5;
      }
      goto LAB_002bf820;
    }
    bVar8 = cVar1 == '\0';
LAB_002bf963:
    regWrite032(param_1 + 0x3a18,0,0,0x200,uVar4,0);
    if (!bVar8) {
      osDelay(4);
      goto LAB_002bf8dc;
    }
LAB_002bf950:
    iVar5 = 0;
  }
  return iVar5;
}


// ===== 002bfa10 kbifIsMSIXEnabledInHW_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kbifIsMSIXEnabledInHW_TU102(long param_1)

{
  int iVar1;
  uint local_1c [3];
  
  if (*(char *)(param_1 + 0x908) != '\0') {
    return (uint)*(byte *)(param_1 + 0x4913);
  }
  iVar1 = (**(code **)(param_1 + 0x178))(param_1,200,local_1c);
  if (iVar1 == 0) {
    return local_1c[0] >> 0x1f;
  }
  nvAssertFailedNoLog("Unable to read NV_XVE_MSIX_CAP_HDR\n",
                      "src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0x4f);
  return 0;
}


// ===== 002bfa90 kbifDisableP2PTransactions_TU102 =====

void kbifDisableP2PTransactions_TU102(long param_1,long param_2)

{
  if (*(char *)(param_1 + 0x4913) != '\0') {
    *(undefined2 *)(param_2 + 0x3a9) = 0x101;
  }
  return;
}


// ===== 002bfab0 kbifGetVFSparseMmapRegions_TU102 =====

int kbifGetVFSparseMmapRegions_TU102
              (long param_1,undefined8 param_2,undefined4 *param_3,long param_4,uint *param_5,
              ulong *param_6,long *param_7)

{
  char cVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  bool bVar5;
  ulong uVar6;
  ulong *puVar7;
  long lVar8;
  ulong uVar9;
  uint local_4c;
  uint local_3c [3];
  
  if (param_3 == (undefined4 *)0x0) {
    nvCheckFailedNoLog(4,"pKernelHostVgpuDevice != NULL",
                       "src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0x7d);
    return 0x1f;
  }
  if (param_5 == (uint *)0x0) {
    nvCheckFailedNoLog(4,"pNumAreas != NULL","src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",
                       0x7e);
    return 0x1f;
  }
  iVar2 = kvgpumgrGetMaxInstanceOfVgpu(*param_3,local_3c);
  if (iVar2 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar2,"kvgpumgrGetMaxInstanceOfVgpu(pKernelHostVgpuDevice->vgpuType, &maxInstance)"
               ,"src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0x80);
    return iVar2;
  }
  bVar5 = param_6 == (ulong *)0x0 || param_7 == (long *)0x0;
  if (bVar5) {
    param_6 = (ulong *)portMemAllocNonPaged(0x50);
    param_7 = (long *)portMemAllocNonPaged(0x50);
    plVar4 = param_7;
    if (1 < local_3c[0]) goto LAB_002bfb26;
LAB_002bfba0:
    cVar1 = hypervisorIsType_IMPL(2);
    param_7 = plVar4;
    if (cVar1 != '\0') {
      local_4c = 1;
      uVar6 = 0;
      puVar7 = param_6;
      goto LAB_002bfbc1;
    }
    local_4c = 2;
    lVar3 = 8;
    lVar8 = 0x10000;
    uVar6 = 0;
    puVar7 = param_6;
LAB_002bfc73:
    *puVar7 = uVar6;
    *plVar4 = lVar8;
  }
  else {
    plVar4 = param_7;
    if (local_3c[0] < 2) goto LAB_002bfba0;
LAB_002bfb26:
    plVar4 = param_7;
    if (*(char *)(param_1 + 0x463) == '\0') goto LAB_002bfba0;
    *param_6 = 0;
    *param_7 = 0x3000;
    uVar6 = param_4 + 0x3000;
    cVar1 = hypervisorIsType_IMPL(2);
    local_4c = 2;
    plVar4 = param_7 + 1;
    puVar7 = param_6 + 1;
    if (cVar1 != '\0') goto LAB_002bfbc1;
    lVar3 = 8;
    if (uVar6 < 0x10000) {
      local_4c = 3;
      lVar3 = 0x10;
      lVar8 = 0x10000 - uVar6;
      goto LAB_002bfc73;
    }
  }
  plVar4 = (long *)((long)param_7 + lVar3);
  uVar6 = param_4 + 0x10000;
  puVar7 = (ulong *)((long)param_6 + lVar3);
LAB_002bfbc1:
  lVar3 = *(long *)(&DAT_00003a70 + param_1);
  *puVar7 = uVar6;
  *plVar4 = lVar3 - uVar6;
  if (bVar5) {
    portMemFree(param_6);
    portMemFree(param_7);
  }
  else {
    uVar6 = 0;
    if (*param_5 < local_4c) {
      nvAssertFailedNoLog("idx <= *pNumAreas","src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",
                          0xb7);
      return 0x71;
    }
    do {
      puVar7 = param_6 + uVar6;
      plVar4 = param_7 + uVar6;
      uVar9 = uVar6 & 0xffffffff;
      uVar6 = uVar6 + 1;
      nvDbg_Printf("src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0xbb,
                   "kbifGetVFSparseMmapRegions_TU102",1,
                   "NVRM: VF Sparse Mmap Region[%u] range 0x%llx - 0x%llx, size 0x%llx\n",uVar9,
                   *puVar7,*plVar4 + *puVar7,*plVar4);
    } while (uVar6 != local_4c);
  }
  *param_5 = local_4c;
  return 0;
}


// ===== 002bfdb0 kbifCacheFlrSupport_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifCacheFlrSupport_TU102(long param_1,long param_2)

{
  int iVar1;
  uint local_1c [3];
  
  local_1c[0] = 0;
  iVar1 = (**(code **)(param_1 + 0x178))(param_1,0x7c,local_1c);
  if (iVar1 == 0) {
    if ((local_1c[0] & 0x10000000) != 0) {
      *(undefined1 *)(param_2 + 0x3b0) = 1;
    }
    return;
  }
  nvDbg_Printf("src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0xd8,"kbifCacheFlrSupport_TU102",
               4,"NVRM: Unable to read NV_XVE_DEVICE_CAPABILITY\n");
  return;
}


// ===== 002bfe30 kbifCacheVFInfo_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifCacheVFInfo_TU102(long param_1)

{
  int iVar1;
  uint uVar2;
  uint local_24;
  uint local_20;
  undefined4 local_1c;
  
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  iVar1 = (**(code **)(param_1 + 0x178))(param_1,0xbd8,&local_24);
  if (iVar1 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0xf8);
  }
  *(uint *)(param_1 + 0x3a58) = local_24 >> 0x10;
  iVar1 = (**(code **)(param_1 + 0x178))(param_1,0xbe0,&local_24);
  if (iVar1 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0xfe);
  }
  *(uint *)(param_1 + 0x3a5c) = local_24 & 0xffff;
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0xbf0,&local_20);
  if (iVar1 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0x104)
    ;
  }
  *(ulong *)(param_1 + 0x3ab0) = (ulong)(local_20 & 0xfffffff0);
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0xbf4,&local_20);
  if (iVar1 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0x109)
    ;
  }
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0xbf8,&local_1c);
  if (iVar1 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0x10b)
    ;
  }
  *(ulong *)(param_1 + 0x3ab8) = CONCAT44(local_1c,local_20) & 0xfffffffffffffff0;
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0xbfc,&local_20);
  if (iVar1 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0x110)
    ;
  }
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0xc00,&local_1c);
  if (iVar1 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0x112)
    ;
  }
  *(ulong *)(param_1 + 0x3ac0) = CONCAT44(local_1c,local_20) & 0xfffffffffffffff0;
  local_24 = regRead032(param_1 + 0x3a18,0,0,0x88bf4,0);
  *(bool *)(param_1 + 0x3af1) = (local_24 & 6) == 4;
  uVar2 = regRead032(param_1 + 0x3a18,0,0,0x88bfc,0);
  *(bool *)(param_1 + 0x3af2) = (uVar2 & 6) == 4;
  return;
}


// ===== 002c00c0 kbifWaitForTransactionsComplete_TU102 =====

undefined4 kbifWaitForTransactionsComplete_TU102(long param_1)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined1 local_34 [2];
  undefined1 local_32 [2];
  undefined1 local_30 [24];
  
  uVar1 = *(ulong *)(param_1 + 0x878);
  uVar4 = osPciInitHandle(uVar1 >> 0x20,uVar1 >> 8 & 0xff,uVar1 & 0xff,0,local_34,local_32);
  timeoutSet(param_1 + 0x1af0,local_30,0,0);
  do {
    uVar3 = osPciReadDword(uVar4,0x80);
    if ((uVar3 & 0x200000) == 0) {
      return 0;
    }
    iVar2 = timeoutCheck(param_1 + 0x1af0,local_30,0x139);
  } while (iVar2 != 0x65);
  nvDbg_Printf("src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0x13b,
               "kbifWaitForTransactionsComplete_TU102",4,
               "NVRM: Timeout waiting for transactions pending to go to 0\n");
  return 0x65;
}


// ===== 002c0190 kbifTriggerFlr_TU102 =====

undefined8 kbifTriggerFlr_TU102(long param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined2 local_1c;
  undefined2 local_1a;
  
  uVar1 = *(ulong *)(param_1 + 0x878);
  local_1a = 0;
  uVar2 = *(undefined8 *)(g_pSys + 0x208);
  local_1c = 0;
  uVar4 = osPciInitHandle(uVar1 >> 0x20,uVar1 >> 8 & 0xff,uVar1 & 0xff,0,&local_1c,&local_1a);
  uVar3 = osPciReadDword(uVar4,0x80);
  uVar1 = *(ulong *)(param_1 + 0x878);
  clPcieWriteDword_IMPL(uVar2,uVar1 >> 0x20,uVar1 >> 8 & 0xff,uVar1 & 0xff,0,0x80,uVar3 | 0x8000);
  return 0;
}


// ===== 002c0230 kbifInitXveRegMap_TU102 =====

undefined8 kbifInitXveRegMap_TU102(undefined8 param_1,long param_2,char param_3)

{
  undefined8 uVar1;
  
  if (param_3 == '\0') {
    *(undefined1 *)(param_2 + 0x2414) = 0;
    *(long *)(param_2 + 0x2418) = param_2 + 0x3d0;
    *(undefined1 **)(param_2 + 0x2400) = xveRegMapValid;
    *(undefined1 **)(param_2 + 0x2408) = xveRegMapWrite;
    *(undefined4 *)(param_2 + 0x2410) = 0x1d001d;
    *(undefined8 *)(param_2 + 0x2420) = 0;
    return 0;
  }
  if (param_3 != '\x01') {
    nvDbg_Printf("src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0x192,"kbifInitXveRegMap_TU102"
                 ,4,"NVRM: Invalid argument, func: %d.\n",param_3);
    nvAssertFailedNoLog(&DAT_00cf539b,"src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0x193);
    return 0x1f;
  }
  uVar1 = kbifInitXveRegMap_GM107(param_1,param_2,1);
  return uVar1;
}


// ===== 002c02f0 kbifGetMSIXTableVectorControlSize_TU102 =====

undefined8 kbifGetMSIXTableVectorControlSize_TU102(void)

{
  return 6;
}


// ===== 002c0300 kbifDoFunctionLevelReset_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbifDoFunctionLevelReset_TU102(long param_1,long param_2)

{
  ulong uVar1;
  char cVar2;
  short sVar3;
  undefined1 uVar8;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined1 local_3c [2];
  undefined1 local_3a [10];
  
  uVar1 = *(ulong *)(param_1 + 0x878);
  uVar8 = (undefined1)(uVar1 >> 8);
  osPciInitHandle(uVar1 >> 0x20,uVar8,uVar1 & 0xff,0,local_3c,local_3a);
  *(undefined1 *)(param_2 + 0x23d4) = 1;
  iVar4 = (**(code **)(param_2 + 0x1a0))(param_1,param_2);
  if (iVar4 != 0) {
    nvDbg_Printf("src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0x227,
                 "kbifDoFunctionLevelReset_TU102",4,"NVRM: Config registers save failed!\n");
    goto LAB_002c04b3;
  }
  cVar2 = (**(code **)(param_2 + 0x210))(param_1,param_2);
  uVar9 = 0;
  if (cVar2 != '\0') {
    uVar6 = (**(code **)(param_2 + 0x298))(param_1,param_2);
    if (uVar6 < 0x20) {
      if (uVar6 == 0) goto LAB_002c0392;
    }
    else {
      nvAssertFailedNoLog("controlSize < 32","src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",
                          0x1c2);
    }
    uVar10 = 0;
    do {
      uVar5 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x1000c + uVar10 * 0x10,0
                        );
      if ((uVar5 & 1) != 0) {
        uVar9 = uVar9 | 1 << (uVar10 & 0x1f);
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < uVar6);
  }
LAB_002c0392:
  *(undefined1 *)(param_2 + 0x23d4) = 0;
  if (*(char *)(param_2 + 0x3b7) != '\0') {
    iVar4 = (**(code **)(param_2 + 0x2c0))(param_1,param_2,1);
    if (iVar4 != 0) {
      nvDbg_Printf("src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0x23e,
                   "kbifDoFunctionLevelReset_TU102",4,"NVRM: BIF Stop Sys Mem requests failed.\n");
    }
    iVar4 = (**(code **)(param_2 + 0x2d0))(param_1,param_2);
    if (iVar4 != 0) {
      nvDbg_Printf("src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0x244,
                   "kbifDoFunctionLevelReset_TU102",4,
                   "NVRM: BIF Wait for Transactions complete failed.\n");
    }
  }
  (**(code **)(param_2 + 0x2d8))(param_1,param_2);
  *(undefined1 *)(param_2 + 0x23d5) = 1;
  osDelayUs(100000);
  iVar4 = (**(code **)(param_2 + 0x1a8))(param_1,param_2);
  if (iVar4 != 0) {
    nvDbg_Printf("src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",600,
                 "kbifDoFunctionLevelReset_TU102",4,"NVRM: Config registers restore failed!\n");
    goto LAB_002c04b3;
  }
  if (*(char *)(param_1 + 0x446) != '\0') {
    nvDbg_Printf("src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0x262,
                 "kbifDoFunctionLevelReset_TU102",4,"NVRM: Entering secure boot completion wait.\n")
    ;
LAB_002c0434:
    if (*(char *)(param_1 + 0x909) == '\0') {
      iVar11 = 0x56;
    }
    else {
      iVar11 = (**(code **)(param_1 + 0x400))(param_1);
      if (iVar11 == 0) {
        if (*(char *)(param_1 + 0x446) != '\0') {
          nvDbg_Printf("src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0x275,
                       "kbifDoFunctionLevelReset_TU102",4,
                       "NVRM: Exited secure boot completion wait with status = NV_OK.\n");
        }
        goto LAB_002c0468;
      }
    }
    iVar4 = iVar11;
    nvDbg_Printf("src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0x270,
                 "kbifDoFunctionLevelReset_TU102",4,"NVRM: VBIOS boot failed!!\n");
    goto LAB_002c04b3;
  }
  if (*(char *)(param_1 + 0x490e) == '\0') goto LAB_002c0434;
LAB_002c0468:
  if (cVar2 != '\0') {
    uVar6 = (**(code **)(param_2 + 0x298))(param_1,param_2);
    iVar11 = *(int *)(param_1 + 0x3a64);
    if (uVar6 < 0x20) {
      if (uVar6 == 0) goto LAB_002c0472;
    }
    else {
      nvAssertFailedNoLog("controlSize < 32","src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",
                          0x1eb);
    }
    iVar11 = iVar11 + 0x1000c;
    uVar10 = 0;
    do {
      while ((uVar9 >> (uVar10 & 0x1f) & 1) != 0) {
        uVar10 = uVar10 + 1;
        osGpuWriteReg032(param_1,iVar11,1);
        iVar11 = iVar11 + 0x10;
        if (uVar6 <= uVar10) goto LAB_002c0472;
      }
      uVar10 = uVar10 + 1;
      osGpuWriteReg032(param_1,iVar11,0);
      iVar11 = iVar11 + 0x10;
    } while (uVar10 < uVar6);
  }
LAB_002c0472:
  (**(code **)(param_2 + 0x380))(param_1,param_2);
  uVar7 = osPciInitHandle((int)(uVar1 >> 0x20),uVar8,(int)(uVar1 & 0xff),0,local_3c,local_3a);
  sVar3 = osPciReadDword(uVar7,0);
  if (sVar3 != 0x10de) {
    iVar4 = 0xffff;
  }
LAB_002c04b3:
  *(undefined2 *)(param_2 + 0x23d4) = 0;
  return iVar4;
}


// ===== 002c07c0 kbifGetValidEnginesToReset_TU102 =====

undefined8 kbifGetValidEnginesToReset_TU102(void)

{
  return 0xd1fdffd0;
}


// ===== 002c07d0 kbifDoSecondaryBusResetOrFunctionLevelReset_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

undefined8 kbifDoSecondaryBusResetOrFunctionLevelReset_TU102(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  
  if ((*(char *)(param_2 + 0x3b0) == '\0') || (*(char *)(param_2 + 0x23f4) != '\0')) {
    *(undefined1 *)(param_1 + 0x450) = 1;
    uVar3 = (**(code **)(param_2 + 0x390))();
    return uVar3;
  }
  lVar1 = *(long *)(param_1 + 0x1b60);
  (**(code **)(param_2 + 0x328))();
  iVar2 = (**(code **)(param_2 + 0x350))(param_1,param_2);
  if (iVar2 != 0) {
    iVar2 = (**(code **)(lVar1 + 0x168))(param_1,lVar1,iVar2,0,0,*(code **)(lVar1 + 0x168));
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,"kmcWritePmcEnableReg_HAL(pGpu, pKernelMc, engineMask, NV_FALSE, NV_FALSE)",
                 "src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0x2e4);
    }
  }
  iVar2 = (**(code **)(param_2 + 0x358))(param_1,param_2);
  if (iVar2 != 0) {
    iVar2 = (**(code **)(lVar1 + 0x168))
                      (param_1,lVar1,iVar2,0,*(undefined1 *)(param_1 + 0x4a7b),
                       *(code **)(lVar1 + 0x168));
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,
                 "kmcWritePmcEnableReg_HAL(pGpu, pKernelMc, engineMask, NV_FALSE, gpuIsUsePmcDeviceEnableForHostEngineEnabled(pGpu))"
                 ,"src/kernel/gpu/bif/arch/turing/kernel_bif_tu102.c",0x2f0);
    }
  }
  iVar2 = (**(code **)(param_2 + 0x288))(param_1,param_2);
  if (iVar2 != 0) {
    *(undefined1 *)(param_1 + 0x450) = 1;
    uVar3 = (**(code **)(param_2 + 0x390))(param_1,param_2);
    return uVar3;
  }
  *(undefined1 *)(param_1 + 0x44f) = 1;
  return 0;
}


// ===== 002c0940 _kbifCheckIfGpuExists =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _kbifCheckIfGpuExists(long param_1)

{
  char cVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return;
  }
  cVar1 = gpuIsGpuFullPower_IMPL();
  if ((((cVar1 != '\0') && (*(char *)(param_1 + 0x44c) != '\0')) &&
      (*(char *)(param_1 + 0x44f) == '\0')) &&
     (((*(char *)(param_1 + 0x450) == '\0' && (*(char *)(param_1 + 0x451) == '\0')) &&
      (*(char *)(param_1 + 0x455) == '\0')))) {
    cVar1 = gpuCheckSysmemAccess_IMPL();
    if (cVar1 != '\0') {
      iVar2 = (**(code **)(param_1 + 0x328))();
      if (iVar2 != 0) {
        osRemove1HzCallback(param_1,_kbifCheckIfGpuExists,0);
        return;
      }
    }
  }
  return;
}


// ===== 002c09d0 _kbifNbsiReadRTD3RegistryDword.isra.0 =====

undefined8
_kbifNbsiReadRTD3RegistryDword_isra_0(long param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined8 uVar5;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  undefined1 local_44 [20];
  
  puVar4 = (undefined1 *)getNbsiObject();
  if (param_3 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pData != NULL","src/kernel/gpu/bif/kernel_bif.c",0x149);
    return 0x1f;
  }
  if ((param_1 != 0) && (puVar4 != (undefined1 *)0x0)) {
    if ((*(char *)(param_1 + 0x443) == '\0') || (*(char *)(param_1 + 0x483) != '\0')) {
      uVar1 = *puVar4;
      uVar2 = *(undefined2 *)(puVar4 + 0x10);
      uVar3 = nvStringLen(param_2);
      fnv1Hash20Array(param_2,uVar3,local_44,uVar1);
      local_4c = 4;
      uVar5 = getNbsiValue(param_1,2,uVar2,uVar1,local_44,&local_50,&local_4c);
      if ((int)uVar5 == 0) {
        if (local_48 == 0) {
          *param_3 = local_50;
          return 0;
        }
        if (local_48 == -2) {
          nvAssertFailedNoLog("errorCode != NV2080_CTRL_BIOS_GET_NBSI_INCOMPLETE",
                              "src/kernel/gpu/bif/kernel_bif.c",0x182,&local_48);
        }
        return 0xffff;
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x155,"_kbifNbsiReadRTD3RegistryDword",4,
                   "NVRM: osReadRegistryDword called in Sleep path can cause excessive delays!\n");
      nvAssertFailedNoLog(&DAT_00cf5848,"src/kernel/gpu/bif/kernel_bif.c",0x158);
      uVar5 = 0x3f;
    }
    return uVar5;
  }
  return 0x31;
}


// ===== 002c0bb0 kbifGetPciePowerControlValue_IMPL =====

undefined8 kbifGetPciePowerControlValue_IMPL(long param_1,long param_2,int *param_3)

{
  long lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined8 uVar5;
  byte local_a5;
  undefined4 local_a4;
  undefined4 local_a0 [4];
  undefined1 local_8d [34];
  undefined1 local_6b [59];
  
  lVar1 = *(long *)(g_pSys + 0x208);
  nvU64ToStr((ulong)*(ushort *)(lVar1 + 0xaa) << 0x30 | (ulong)*(ushort *)(lVar1 + 0xa8) << 0x20 |
             (ulong)*(ushort *)(lVar1 + 0xae) | (ulong)*(ushort *)(lVar1 + 0xac) << 0x10,local_6b,
             0x10);
  portMemSet(local_8d,0,0x22);
  uVar2 = nvStringLen("PCIEPowerControl");
  uVar3 = nvStringLen("PCIEPowerControl");
  portMemCopy(local_8d,uVar3,"PCIEPowerControl",uVar2);
  uVar4 = nvStringLen("PCIEPowerControl");
  portMemCopy(local_8d + uVar4,1,&DAT_00cf585b,1);
  uVar2 = nvStringLen(local_6b);
  uVar3 = nvStringLen(local_6b);
  portMemCopy(local_8d + (uVar4 + 1),uVar3,local_6b,uVar2);
  nvU64ToStr((ulong)*(uint *)(param_1 + 0x7f4) << 0x30 |
             (ulong)(*(uint *)(param_1 + 0x7fc) & 0xffff) |
             (ulong)(*(uint *)(param_1 + 0x7f4) >> 0x10) << 0x20 |
             (ulong)(*(uint *)(param_1 + 0x7fc) >> 0x10) << 0x10,local_a0,0x10);
  portMemSet(local_6b,0,0x33);
  uVar2 = nvStringLen(local_8d);
  uVar3 = nvStringLen(local_8d);
  portMemCopy(local_6b,uVar3,local_8d,uVar2);
  uVar4 = nvStringLen(local_8d);
  portMemCopy(local_6b + uVar4,1,&DAT_00cf585b,1);
  uVar2 = nvStringLen(local_a0);
  uVar3 = nvStringLen(local_a0);
  portMemCopy(local_6b + (uVar4 + 1),uVar3,local_a0,uVar2);
  local_a4 = 4;
  local_a0[0] = 1;
  local_a5 = 0;
  uVar5 = osReadRegistryDword(param_1,local_6b,param_3);
  if ((int)uVar5 == 0) {
    *(undefined8 *)(param_2 + 0x23d8) = 0x200000001;
  }
  else {
    uVar5 = osGetNvGlobalRegistryDword(param_1,local_6b,param_3);
    if ((int)uVar5 == 0) {
      *(undefined8 *)(param_2 + 0x23d8) = 0x100000001;
      return uVar5;
    }
    uVar5 = osGetUefiVariable(local_6b,NV_GUID_UEFI_VARIABLE,param_3,&local_a4);
    if ((int)uVar5 == 0) {
      *(undefined8 *)(param_2 + 0x23d8) = 0x300000001;
    }
    else {
      uVar5 = _kbifNbsiReadRTD3RegistryDword_isra_0(param_1,local_6b,param_3);
      if ((int)uVar5 == 0) {
        *(undefined8 *)(param_2 + 0x23d8) = 0x400000001;
      }
      else {
        uVar5 = osReadRegistryDword(param_1,local_8d,param_3);
        if ((int)uVar5 == 0) {
          *(undefined8 *)(param_2 + 0x23d8) = 0x200000003;
        }
        else {
          uVar5 = osGetNvGlobalRegistryDword(param_1,local_8d,param_3);
          if ((int)uVar5 == 0) {
            *(undefined8 *)(param_2 + 0x23d8) = 0x100000003;
          }
          else {
            uVar5 = osGetUefiVariable(local_8d,NV_GUID_UEFI_VARIABLE,param_3,&local_a4);
            if ((int)uVar5 == 0) {
              *(undefined8 *)(param_2 + 0x23d8) = 0x300000003;
            }
            else {
              uVar5 = _kbifNbsiReadRTD3RegistryDword_isra_0(param_1,local_8d,param_3);
              if ((int)uVar5 == 0) {
                *(undefined8 *)(param_2 + 0x23d8) = 0x400000003;
              }
              else {
                uVar5 = osReadRegistryDword(param_1,"PCIEPowerControl",param_3);
                if ((int)uVar5 == 0) {
                  *(undefined8 *)(param_2 + 0x23d8) = 0x200000002;
                }
                else {
                  uVar5 = osGetNvGlobalRegistryDword(param_1,"PCIEPowerControl",param_3);
                  if ((int)uVar5 == 0) {
                    *(undefined8 *)(param_2 + 0x23d8) = 0x100000002;
                  }
                  else {
                    uVar5 = osGetUefiVariable("PCIEPowerControl",NV_GUID_UEFI_VARIABLE,param_3,
                                              &local_a4);
                    if ((int)uVar5 == 0) {
                      *(undefined8 *)(param_2 + 0x23d8) = 0x300000002;
                    }
                    else {
                      uVar5 = _kbifNbsiReadRTD3RegistryDword_isra_0
                                        (param_1,"PCIEPowerControl",param_3);
                      if ((int)uVar5 == 0) {
                        *(undefined8 *)(param_2 + 0x23d8) = 0x400000002;
                      }
                      else {
                        uVar5 = nbsiReadRegistryString
                                          (param_1,"RMSbiosEnableASPMDT",&local_a5,local_a0);
                        if ((int)uVar5 == 0) {
                          *(undefined8 *)(param_2 + 0x23d8) = 0x500000002;
                          *param_3 = (local_a5 & 0xf) << 4;
                        }
                        else {
                          uVar5 = 0x56;
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
  }
  return uVar5;
}


// ===== 002c1060 deviceCtrlCmdBifGetPciePowerControlMask_IMPL =====

undefined8 deviceCtrlCmdBifGetPciePowerControlMask_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0x128) + 0xe0) + 7000);
  *param_2 = *(undefined4 *)(lVar1 + 0x23e0);
  param_2[1] = *(undefined4 *)(lVar1 + 0x23d8);
  param_2[2] = *(undefined4 *)(lVar1 + 0x23dc);
  return 0;
}


// ===== 002c10a0 kbifStatePostLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifStatePostLoad_IMPL(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_19;
  
  (**(code **)(param_2 + 0x248))();
  if (*(char *)(param_2 + 0x3ae) != '\0') {
    local_19 = 1;
    iVar1 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800ab9,&local_19,1);
    if (iVar1 != 0) {
      uVar2 = nvstatusToString(iVar1);
      nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x272,"_kbifSetPcieRelaxedOrdering",4,
                   "NVRM: NV2080_CTRL_CMD_INTERNAL_BIF_SET_PCIE_RO failed %s (0x%x)\n",uVar2,iVar1);
    }
  }
  return 0;
}


// ===== 002c1160 kbifStateUnload_IMPL =====

undefined8 kbifStateUnload_IMPL(void)

{
  return 0;
}


// ===== 002c1170 kbifCacheChipsetL1SubstatesEnable_IMPL =====

ulong kbifCacheChipsetL1SubstatesEnable_IMPL(long param_1,long param_2)

{
  int iVar1;
  ulong in_RAX;
  ulong uVar2;
  undefined1 local_28 [4];
  undefined4 local_24;
  uint local_20;
  
  if (*(char *)(param_1 + 0x1d5f) == '\0') {
    return in_RAX;
  }
  if ((*(long *)(g_pSys + 0x208) != 0) &&
     (iVar1 = clPcieReadL1SsCapability_IMPL(param_1,*(long *)(g_pSys + 0x208),local_28), iVar1 == 0)
     ) {
    uVar2 = (ulong)local_20;
    *(uint *)(param_2 + 0x2454) = local_20;
    if ((local_20 & 0xe) != 0 || (local_20 & 1) != 0) {
      nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x2d4,"kbifCacheChipsetL1SubstatesEnable_IMPL",
                   1,
                   "NVRM: Chipset supports L1 PM substates.\n      L1 PM Capabilities Register 0x%x\n      L1 PM Control 1 Register 0x%x\n      L1 PM Control 2 Register 0x%x\n"
                   ,local_24,uVar2,uVar2);
      return uVar2;
    }
    uVar2 = nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x2da,
                         "kbifCacheChipsetL1SubstatesEnable_IMPL",1,
                         "NVRM: L1 PM susbstates is not enabled in RootPort. L1 PM Control 1 Register 0x%x \n"
                        );
    return uVar2;
  }
  uVar2 = nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x2e1,
                       "kbifCacheChipsetL1SubstatesEnable_IMPL",1,
                       "NVRM: Failed to get L1 PM substates capabilites from Root Port\n");
  return uVar2;
}


// ===== 002c1260 kbifInitDmaCaps_IMPL =====

void kbifInitDmaCaps_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(g_pSys + 0x208);
  *(undefined4 *)(param_2 + 0x3bc) = 0x10000;
  *(uint *)(param_2 + 0x3bc) = 0x10001 - (uint)(*(char *)(lVar1 + 0x68) == '\0');
  return;
}


// ===== 002c1290 kbifGetDmaCaps_IMPL =====

uint kbifGetDmaCaps_IMPL(undefined8 param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x3bc);
  if (*(char *)(param_2 + 0x3ac) == '\0') {
    uVar1 = *(uint *)(param_2 + 0x3bc) & 0xffff;
  }
  return uVar1;
}


// ===== 002c12b0 kbifStaticInfoInit_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbifStaticInfoInit_IMPL(long param_1,long param_2)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)portMemAllocNonPaged(4);
  if (puVar2 == (undefined1 *)0x0) {
    iVar1 = 0x51;
    nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x32a,"kbifStaticInfoInit_IMPL",4,
                 "NVRM: Could not allocate pStaticInfo for KernelBif");
  }
  else {
    portMemSet(puVar2,0,4);
    iVar1 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800aac,puVar2,4);
    if (iVar1 == 0) {
      *(undefined1 *)(param_2 + 0x3ad) = *puVar2;
      *(undefined1 *)(param_2 + 0x3a8) = puVar2[1];
      *(undefined1 *)(param_2 + 0x3b2) = puVar2[2];
      *(undefined1 *)(param_2 + 0x3b3) = puVar2[3];
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar1,
                 "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_BIF_GET_STATIC_INFO, pStaticInfo, sizeof(*pStaticInfo))"
                 ,"src/kernel/gpu/bif/kernel_bif.c",0x331);
    }
  }
  portMemFree(puVar2);
  return iVar1;
}


// ===== 002c13d0 kbifStateInitLocked_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbifStateInitLocked_IMPL(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  
  lVar2 = g_pSys;
  lVar1 = *(long *)(g_pSys + 0x208);
  (**(code **)(param_2 + 0x290))(param_1,param_2,1);
  (**(code **)(param_2 + 0x290))(param_1,param_2,0);
  iVar3 = (**(code **)(param_2 + 800))(param_1,param_2);
  if (iVar3 == 0) {
    iVar3 = 0x54;
    if (*(char *)(lVar1 + 0x67) == '\0') {
      iVar3 = osInitMapping(param_1);
      if (iVar3 == 0) {
        kbifStaticInfoInit_IMPL(param_1,param_2);
        (**(code **)(param_2 + 0x198))(param_1,param_2);
        iVar4 = (**(code **)(param_1 + 0x168))(param_1);
        if ((iVar4 == 3) && (*(char *)(lVar2 + 0x88) != '\0')) {
          nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x95,"kbifStateInitLocked_IMPL",1,
                       "NVRM: BIF disabling noncoherent on OS w/o usable PAT support\n");
          *(undefined1 *)(param_2 + 0x3ac) = 0;
        }
      }
      else {
        nvCheckOkFailedNoLog(4,iVar3,"osInitMapping(pGpu)","src/kernel/gpu/bif/kernel_bif.c",0x89);
      }
    }
  }
  else {
    nvCheckOkFailedNoLog
              (4,iVar3,"kbifInit_HAL(pGpu, pKernelBif)","src/kernel/gpu/bif/kernel_bif.c",0x80);
  }
  return iVar3;
}


// ===== 002c1530 kbifInitPcieDeviceControlStatus_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifInitPcieDeviceControlStatus_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  char cVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  lVar1 = *(long *)(g_pSys + 0x208);
  (**(code **)(param_2 + 0x230))();
  if (*(char *)(lVar1 + 0x5a) == '\0') {
    (**(code **)(param_2 + 0x238))(param_1,param_2);
  }
  else {
    (**(code **)(param_2 + 0x240))(param_1,param_2);
  }
  cVar2 = rmcfg_IsGH100(param_1);
  if (cVar2 == '\0') {
    pcVar3 = *(code **)(param_2 + 0x250);
    if ((*(char *)(lVar1 + 0x59) == '\0') && (*(char *)(lVar1 + 0x5d) == '\0')) {
      uVar4 = 1;
      goto LAB_002c1594;
    }
  }
  else {
    *(undefined1 *)(lVar1 + 0x5d) = 1;
    pcVar3 = *(code **)(param_2 + 0x250);
  }
  uVar4 = 0;
LAB_002c1594:
  (*pcVar3)(param_1,param_2,uVar4);
  return;
}


// ===== 002c15f0 kbifIsMSIEnabled_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbifIsMSIEnabled_IMPL(long param_1,long param_2)

{
  ulong uVar1;
  
  if (*(char *)(param_2 + 0x3a2) != '\0') {
    return (ulong)*(byte *)(param_2 + 0x3a1);
  }
  uVar1 = (**(code **)(param_2 + 0x208))();
  if ((char)uVar1 == '\0') {
    *(undefined1 *)(param_2 + 0x3a1) = 0;
  }
  else {
    *(undefined1 *)(param_2 + 0x3a1) = 1;
    uVar1 = 1;
    if (*(char *)(param_1 + 0x908) != '\0') {
      nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x3c6,"kbifIsMSIEnabled_IMPL",3,
                   "NVRM: MSI is enabled for vGPU, but no need to re-ARM\n");
      uVar1 = (ulong)*(byte *)(param_2 + 0x3a1);
    }
  }
  *(undefined1 *)(param_2 + 0x3a2) = 1;
  return uVar1;
}


// ===== 002c1690 kbifCheckAndRearmMSI_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbifCheckAndRearmMSI_IMPL(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  
  lVar1 = *(long *)(param_1 + 0x1c20);
  cVar2 = kbifIsMSIEnabled_IMPL();
  if (cVar2 == '\0') {
    if (*(char *)(param_2 + 0x3a4) == '\0') {
      cVar2 = (**(code **)(param_2 + 0x210))(param_1,param_2);
      *(undefined1 *)(param_2 + 0x3a4) = 1;
      cVar2 = cVar2 != '\0';
      *(char *)(param_2 + 0x3a3) = cVar2;
    }
    else {
      cVar2 = *(char *)(param_2 + 0x3a3);
    }
    if (cVar2 == '\0') {
      return;
    }
  }
  else {
    if ((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(param_2 + 0x3a7) == '\0')) {
      return;
    }
    if (*(char *)(param_2 + 0x3a6) != '\0') {
      (**(code **)(param_2 + 0x200))(param_1,param_2);
      return;
    }
  }
  (**(code **)(lVar1 + 0x210))(param_1,lVar1);
  return;
}


// ===== 002c1790 kbifClearConfigErrors_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

void kbifClearConfigErrors_IMPL(undefined8 param_1,long param_2,char param_3,uint param_4)

{
  int iVar1;
  int local_34 [5];
  
  local_34[0] = 0;
  local_34[1] = 0;
  local_34[2] = 0;
  if (param_3 != '\0') {
    iVar1 = (**(code **)(param_2 + 0x1c8))(param_1,param_2,local_34,local_34 + 1);
    if ((iVar1 == 0) && (local_34[0] != 0)) {
      nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x40c,"kbifClearConfigErrors_IMPL",3,
                   "NVRM: PCI-E device status errors pending (%08X):\n");
      nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x420,"kbifClearConfigErrors_IMPL",3,
                   "NVRM: Clearing these errors..\n");
      (**(code **)(param_2 + 0x1d0))(param_1,param_2,local_34 + 1);
    }
  }
  if (param_4 != 0) {
    iVar1 = (**(code **)(param_2 + 0x1d8))(param_1,param_2,local_34 + 2);
    if (iVar1 == 0) {
      local_34[2] = param_4 & local_34[2];
      if (local_34[2] != 0) {
        nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x42b,"kbifClearConfigErrors_IMPL",3,
                     "NVRM: PCI-E device AER errors pending (%08X):\n",local_34[2]);
        nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x474,"kbifClearConfigErrors_IMPL",3,
                     "NVRM: Clearing these errors..\n");
        (**(code **)(param_2 + 0x1e8))(param_1,param_2,local_34[2]);
      }
    }
  }
  return;
}


// ===== 002c18f0 kbifStateLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifStateLoad_IMPL(long param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x3bc) & 0xffff;
  if (*(char *)(param_2 + 0x3ac) != '\0') {
    uVar1 = *(uint *)(param_2 + 0x3bc);
  }
  nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0xad,"kbifStateLoad_IMPL",1,
               "NVRM: BIF DMA Caps: %08x\n",uVar1);
  (**(code **)(param_2 + 0x228))(param_1,param_2);
  kbifClearConfigErrors_IMPL(param_1,param_2,1,0xffffffff);
  if (*(char *)(param_1 + 0x444) == '\0') {
    (**(code **)(param_2 + 0x1a0))(param_1,param_2);
  }
  if ((*(char *)(param_2 + 0x3a0) != '\0') && (*(char *)(param_1 + 0x908) == '\0')) {
    osSchedule1HzCallback(param_1,_kbifCheckIfGpuExists,0,1);
    return 0;
  }
  return 0;
}


// ===== 002c19c0 kbifGetGpuLinkCapabilities_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kbifGetGpuLinkCapabilities_IMPL(long param_1,long param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_30;
  undefined4 local_2c [3];
  
  local_30 = 0;
  local_2c[0] = 0;
  iVar1 = (**(code **)(param_2 + 0x2b0))(param_1,param_2,2,&local_30);
  uVar2 = 0;
  if (iVar1 == 0) {
    iVar1 = (**(code **)(param_1 + 0x178))(param_1,local_30,local_2c);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x514,"kbifGetGpuLinkCapabilities_IMPL",4,
                   "NVRM: Unable to read %x\n",local_30);
      local_2c[0] = 0;
    }
    *(undefined4 *)(param_2 + 0x2474) = local_2c[0];
    uVar2 = local_2c[0];
  }
  return uVar2;
}


// ===== 002c1a70 kbifConstructEngine_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifConstructEngine_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  uint local_1c;
  
  *(undefined4 *)(param_2 + 0x3c0) = 0xffffffff;
  iVar1 = osReadRegistryDword(param_1,"ForceP2P",&local_1c);
  if (iVar1 == 0) {
    *(uint *)(param_2 + 0x3c0) = local_1c;
    *(bool *)(param_2 + 0x3a9) = (local_1c & 3) == 0;
    *(bool *)(param_2 + 0x3aa) = (local_1c & 0x30) == 0;
  }
  *(undefined4 *)(param_2 + 0x3c4) = 0;
  iVar1 = osReadRegistryDword(param_1,"RMForceP2PType",&local_1c);
  if ((iVar1 == 0) && (local_1c < 4)) {
    *(uint *)(param_2 + 0x3c4) = local_1c;
  }
  *(undefined4 *)(param_2 + 0x3c8) = 0;
  iVar1 = osReadRegistryDword(param_1,"RMPcieP2PType",&local_1c);
  if (iVar1 == 0) {
    *(uint *)(param_2 + 0x3c8) = local_1c;
  }
  *(undefined1 *)(param_2 + 0x3cc) = 0;
  iVar1 = osReadRegistryDword(param_1,"PeerMappingOverride",&local_1c);
  if (iVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x4a4,"_kbifInitRegistryOverrides",1,
                 "NVRM: allow peermapping reg key = %d\n",local_1c);
    *(bool *)(param_2 + 0x3cc) = local_1c != 0;
  }
  iVar1 = osReadRegistryDword(param_1,"RMSecBusResetEnable",&local_1c);
  if (iVar1 == 0) {
    *(bool *)(param_2 + 0x3b5) = local_1c != 0;
  }
  iVar1 = osReadRegistryDword(param_1,"RMForcePcieConfigSave",&local_1c);
  if (iVar1 == 0) {
    *(bool *)(param_2 + 0x3b6) = local_1c != 0;
  }
  *(undefined1 *)(param_2 + 0x23f4) = 0;
  iVar1 = osReadRegistryDword(param_1,"RMPcieFLRPolicy",&local_1c);
  if (iVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x4cb,"_kbifInitRegistryOverrides",1,
                 "NVRM: Pcie FLR Policy reg key = %d\n",local_1c);
    *(bool *)(param_2 + 0x23f4) = local_1c == 1;
  }
  iVar1 = osReadRegistryDword(param_1,"RMPcieFlrDevinitTimeout",&local_1c);
  if (iVar1 == 0) {
    if (local_1c - 1 < 4) {
      *(uint *)(param_2 + 0x23f8) = local_1c;
    }
  }
  (**(code **)(param_2 + 600))(param_1,param_2);
  (**(code **)(param_2 + 0x2f0))(param_1,param_2);
  (**(code **)(param_2 + 0x2e0))(param_1,param_2);
  (**(code **)(param_2 + 0x2e8))(param_1,param_2);
  (**(code **)(param_2 + 0x2f8))(param_1,param_2);
  kbifGetGpuLinkCapabilities_IMPL(param_1,param_2);
  (**(code **)(param_2 + 0x398))(param_1,param_2);
  *(undefined1 *)(param_2 + 0x3cd) = 0;
  *(undefined4 *)(param_2 + 0x23f8) = 1;
  return 0;
}


// ===== 002c1cf0 kbifGetGpuLinkControlStatus_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kbifGetGpuLinkControlStatus_IMPL(long param_1,long param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  local_1c = 0;
  iVar1 = (**(code **)(param_2 + 0x2b0))(param_1,param_2,1,&local_20);
  uVar2 = 0;
  if ((iVar1 == 0) &&
     (iVar1 = (**(code **)(param_1 + 0x178))(param_1,local_20,&local_1c), uVar2 = local_1c,
     iVar1 != 0)) {
    nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x537,"kbifGetGpuLinkControlStatus_IMPL",1,
                 "NVRM: Unable to read %x\n",local_20);
    return 0;
  }
  return uVar2;
}


// ===== 002c1da0 kbifGetGpuDevControlStatus_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kbifGetGpuDevControlStatus_IMPL(long param_1,long param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  local_1c = 0;
  iVar1 = (**(code **)(param_2 + 0x2b0))(param_1,param_2,0,&local_20);
  uVar2 = 0;
  if ((iVar1 == 0) &&
     (iVar1 = (**(code **)(param_1 + 0x178))(param_1,local_20,&local_1c), uVar2 = local_1c,
     iVar1 != 0)) {
    nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x557,"kbifGetGpuDevControlStatus_IMPL",1,
                 "NVRM: Unable to read %x\n",local_20);
    return 0;
  }
  return uVar2;
}


// ===== 002c1e40 kbifGetGpuDevControlStatus2_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kbifGetGpuDevControlStatus2_IMPL(long param_1,long param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  local_1c = 0;
  iVar1 = (**(code **)(param_2 + 0x2b0))(param_1,param_2,3,&local_20);
  uVar2 = 0;
  if ((iVar1 == 0) &&
     (iVar1 = (**(code **)(param_1 + 0x178))(param_1,local_20,&local_1c), uVar2 = local_1c,
     iVar1 != 0)) {
    nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x577,"kbifGetGpuDevControlStatus2_IMPL",1,
                 "NVRM: Unable to read %x\n",local_20);
    return 0;
  }
  return uVar2;
}


// ===== 002c1ef0 kbifGetGpuL1PmSubstatesCtrl1_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kbifGetGpuL1PmSubstatesCtrl1_IMPL(long param_1,long param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  local_1c = 0;
  iVar1 = (**(code **)(param_2 + 0x2b0))(param_1,param_2,4,&local_20);
  uVar2 = 0;
  if ((iVar1 == 0) &&
     (iVar1 = (**(code **)(param_1 + 0x178))(param_1,local_20,&local_1c), uVar2 = local_1c,
     iVar1 != 0)) {
    nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x597,"kbifGetGpuL1PmSubstatesCtrl1_IMPL",1,
                 "NVRM: Unable to read %x\n",local_20);
    return 0;
  }
  return uVar2;
}


// ===== 002c1fa0 kbifControlGetPCIEInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbifControlGetPCIEInfo_IMPL(long param_1,long param_2,uint *param_3)

{
  undefined8 uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  long lVar7;
  uint local_44;
  undefined8 local_40;
  
  local_44 = 0;
  uVar5 = *param_3;
  uVar1 = *(undefined8 *)(g_pSys + 0x208);
  iVar4 = (**(code **)(param_1 + 0x168))();
  if (iVar4 != 3) {
    return 0;
  }
  if (uVar5 == 10) {
    if ((*(char *)(param_1 + 0x477) == '\0') && (*(char *)(param_1 + 0x478) == '\0')) {
LAB_002c23f0:
      lVar7 = param_1 + 0x1d88;
    }
    else {
      lVar7 = param_1 + 0x1de8;
    }
LAB_002c22ad:
    uVar6 = 0x110;
LAB_002c2270:
    iVar4 = clPcieReadPortConfigReg_IMPL(param_1,uVar1,lVar7,uVar6,&local_44);
joined_r0x002c227d:
    uVar3 = local_44;
    if (iVar4 == 0) goto LAB_002c2060;
  }
  else {
    uVar3 = local_44;
    if (uVar5 < 0xb) {
      if (uVar5 == 6) {
        if ((*(char *)(param_1 + 0x477) != '\0') || (*(char *)(param_1 + 0x478) != '\0')) {
          lVar7 = param_1 + 0x1de8;
          uVar6 = 0x10c;
          goto LAB_002c2270;
        }
      }
      else {
        if (6 < uVar5) {
          if (uVar5 != 8) {
            if (uVar5 == 9) goto LAB_002c231a;
LAB_002c204c:
            uVar3 = kbifGetGpuLinkControlStatus_IMPL(param_1,param_2);
            goto LAB_002c2060;
          }
          goto LAB_002c23f0;
        }
        if (uVar5 != 4) {
          if (uVar5 == 5) goto LAB_002c2360;
          if (uVar5 != 3) goto LAB_002c2060;
          goto LAB_002c2021;
        }
      }
      lVar7 = param_1 + 0x1d88;
      uVar6 = 0x10c;
      goto LAB_002c2270;
    }
    if (uVar5 == 0x16) {
LAB_002c2360:
      cVar2 = gpuIsMultiGpuBoard(param_1);
      if (((cVar2 == '\0') && (*(char *)(param_1 + 0x452) == '\0')) ||
         ((*(char *)(param_1 + 0x476) == '\0' &&
          ((*(char *)(param_1 + 0x477) == '\0' && (*(char *)(param_1 + 0x478) == '\0')))))) {
LAB_002c2021:
        uVar3 = kbifGetGpuLinkCapabilities_IMPL(param_1,param_2);
        goto LAB_002c2060;
      }
      iVar4 = clPcieReadPortConfigReg_IMPL(param_1,uVar1,param_1 + 0x1db8,0x10c,&local_44);
      goto joined_r0x002c227d;
    }
    if (uVar5 < 0x17) {
      if (uVar5 == 0x12) {
        local_40 = (ulong)local_40._4_4_ << 0x20;
        iVar4 = clPcieReadDevCtrlStatus_IMPL(param_1,uVar1,&local_44,&local_40);
        uVar3 = 0;
        if (iVar4 == 0) {
          iVar4 = clPcieClearDevCtrlStatus_IMPL(param_1,uVar1,&local_40);
          uVar3 = 0;
          if (iVar4 == 0) {
            uVar3 = local_44;
          }
        }
        goto LAB_002c2060;
      }
      if (uVar5 != 0x15) {
        if ((uVar5 == 0x11) && (local_40 = (ulong)local_40._4_4_ << 0x20, param_2 != 0)) {
          iVar4 = (**(code **)(param_2 + 0x1c8))(param_1,param_2,&local_44,&local_40);
          uVar3 = 0;
          if (iVar4 == 0) {
            iVar4 = (**(code **)(param_2 + 0x1d0))(param_1,param_2,&local_40);
            uVar3 = 0;
            if (iVar4 == 0) {
              uVar3 = local_44;
            }
          }
        }
        goto LAB_002c2060;
      }
      if (param_2 == 0) goto LAB_002c2060;
      iVar4 = (**(code **)(param_2 + 0x1d8))(param_1,param_2,&local_44);
      if (iVar4 == 0) {
        iVar4 = (**(code **)(param_2 + 0x1e8))(param_1,param_2,local_44);
        uVar3 = 0;
        if (iVar4 == 0) {
          uVar3 = local_44;
        }
        goto LAB_002c2060;
      }
    }
    else {
      if (0x30 < uVar5) {
        if (uVar5 == 0x31) {
          cVar2 = (**(code **)(param_2 + 0x208))(param_1,param_2);
          uVar3 = local_44 & 0xfffffffe;
          if (cVar2 != '\0') {
            uVar3 = local_44 | 1;
          }
        }
        goto LAB_002c2060;
      }
      if (uVar5 < 0x2f) {
        if (uVar5 != 0x17) goto LAB_002c2060;
LAB_002c231a:
        cVar2 = gpuIsMultiGpuBoard(param_1);
        if (((cVar2 == '\0') && (*(char *)(param_1 + 0x452) == '\0')) ||
           ((*(char *)(param_1 + 0x476) == '\0' &&
            ((*(char *)(param_1 + 0x477) == '\0' && (*(char *)(param_1 + 0x478) == '\0'))))))
        goto LAB_002c204c;
        lVar7 = param_1 + 0x1db8;
        goto LAB_002c22ad;
      }
      cVar2 = gpuIsMultiGpuBoard(param_1);
      if (((cVar2 == '\0') && (*(char *)(param_1 + 0x452) == '\0')) ||
         ((*(char *)(param_1 + 0x476) == '\0' &&
          ((*(char *)(param_1 + 0x477) == '\0' && (*(char *)(param_1 + 0x478) == '\0')))))) {
        if ((*(char *)(param_1 + 0x908) == '\0') &&
           (uVar3 = local_44, *(char *)(param_1 + 0x909) == '\0')) goto LAB_002c2060;
        local_40 = 0x2d;
        iVar4 = kbusSendBusInfo_IMPL(param_1,*(undefined8 *)(&DAT_00001b90 + param_1),&local_40);
        if (iVar4 == 0) {
          uVar3 = local_40._4_4_;
          goto LAB_002c2060;
        }
        nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x642,"kbifControlGetPCIEInfo_IMPL",1,
                     "NVRM: Squashing rmStatus: %x \n",iVar4);
      }
      else {
        iVar4 = clPcieReadPortConfigReg_IMPL(param_1,uVar1,param_1 + 0x1db8,0x110);
        if (iVar4 == 0) {
          uVar5 = local_40._2_2_ & 0xf;
          local_44 = local_44 & 0xfff0ffff;
          local_40 = CONCAT44(local_40._4_4_,(uint)local_40._2_2_) & 0xffffffff0000000f;
          if (uVar5 == 6) {
            local_44 = local_44 | 0x50000;
          }
          else if (uVar5 == 5) {
            local_44 = local_44 | 0x40000;
          }
          else if (uVar5 == 4) {
            local_44 = local_44 | 0x30000;
          }
          else if (uVar5 == 3) {
            local_44 = local_44 | 0x20000;
          }
          else if (uVar5 == 2) {
            local_44 = local_44 | 0x10000;
          }
          iVar4 = clPcieReadPortConfigReg_IMPL(param_1,uVar1,param_1 + 0x1db8,0x10c,&local_40);
          uVar3 = 0;
          if (iVar4 == 0) {
            local_40._0_4_ = (uint)local_40 & 0xf;
            uVar3 = local_44 & 0xffff0fff;
            if ((uint)local_40 == 6) {
              uVar3 = uVar3 | 0x5000;
            }
            else if ((uint)local_40 == 5) {
              uVar3 = uVar3 | 0x4000;
            }
            else if ((uint)local_40 == 4) {
              uVar3 = uVar3 | 0x3000;
            }
            else if ((uint)local_40 == 3) {
              uVar3 = uVar3 | 0x2000;
            }
            else if ((uint)local_40 == 2) {
              uVar3 = uVar3 | 0x1000;
            }
          }
          goto LAB_002c2060;
        }
      }
    }
  }
  uVar3 = 0;
LAB_002c2060:
  param_3[1] = uVar3;
  return 0;
}


// ===== 002c2550 kbifGetConfigRegData_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbifGetConfigRegData_IMPL(undefined8 param_1,long param_2,long param_3)

{
  long lVar1;
  uint uVar2;
  undefined4 uVar3;
  ulong uVar4;
  
  uVar4 = (ulong)*(uint *)(param_3 + 0x108);
  if (*(uint *)(param_3 + 0x108) != 0) {
    lVar1 = param_3 + uVar4 * 4;
    uVar4 = 0;
    do {
      uVar2 = *(uint *)(param_3 + 4);
      if (uVar2 == 10) {
        uVar3 = (**(code **)(param_2 + 0x1e0))(param_1,param_2,10);
        *(undefined4 *)(param_3 + 0x84) = uVar3;
      }
      else if (uVar2 < 0xb) {
        if (uVar2 == 5) {
          uVar3 = kbifGetGpuL1PmSubstatesCtrl1_IMPL(param_1,param_2);
          *(undefined4 *)(param_3 + 0x84) = uVar3;
        }
        else if (uVar2 < 6) {
          if (uVar2 == 3) {
            uVar3 = kbifGetGpuDevControlStatus2_IMPL(param_1,param_2);
            *(undefined4 *)(param_3 + 0x84) = uVar3;
          }
          else if (uVar2 == 4) {
            uVar3 = kbifGetGpuLinkCapabilities_IMPL(param_1,param_2);
            *(undefined4 *)(param_3 + 0x84) = uVar3;
          }
          else if (uVar2 == 1) {
            uVar3 = kbifGetGpuDevControlStatus_IMPL(param_1,param_2);
            *(undefined4 *)(param_3 + 0x84) = uVar3;
          }
          else {
            if (uVar2 != 2) goto LAB_002c2750;
            uVar3 = kbifGetGpuLinkControlStatus_IMPL(param_1,param_2);
            *(undefined4 *)(param_3 + 0x84) = uVar3;
          }
        }
        else if (uVar2 == 8) {
          uVar3 = (**(code **)(param_2 + 0x1e0))(param_1,param_2,8);
          *(undefined4 *)(param_3 + 0x84) = uVar3;
        }
        else if (uVar2 == 9) {
          uVar3 = (**(code **)(param_2 + 0x1e0))(param_1,param_2,9);
          *(undefined4 *)(param_3 + 0x84) = uVar3;
        }
        else if (uVar2 == 6) {
          uVar3 = (**(code **)(param_2 + 0x1e0))(param_1,param_2,6);
          *(undefined4 *)(param_3 + 0x84) = uVar3;
        }
        else {
          uVar3 = (**(code **)(param_2 + 0x1e0))(param_1,param_2,7);
          *(undefined4 *)(param_3 + 0x84) = uVar3;
        }
      }
      else if (uVar2 == 0xf) {
        uVar3 = (**(code **)(param_2 + 0x1e0))(param_1,param_2,0xf);
        *(undefined4 *)(param_3 + 0x84) = uVar3;
      }
      else if (uVar2 < 0x10) {
        if (uVar2 == 0xd) {
          uVar3 = (**(code **)(param_2 + 0x1e0))(param_1,param_2,0xd);
          *(undefined4 *)(param_3 + 0x84) = uVar3;
        }
        else if (uVar2 == 0xe) {
          uVar3 = (**(code **)(param_2 + 0x1e0))(param_1,param_2,0xe);
          *(undefined4 *)(param_3 + 0x84) = uVar3;
        }
        else if (uVar2 == 0xb) {
          uVar3 = (**(code **)(param_2 + 0x1e0))(param_1,param_2,0xb);
          *(undefined4 *)(param_3 + 0x84) = uVar3;
        }
        else {
          uVar3 = (**(code **)(param_2 + 0x1e0))(param_1,param_2,0xc);
          *(undefined4 *)(param_3 + 0x84) = uVar3;
        }
      }
      else if (uVar2 == 0x11) {
        uVar3 = (**(code **)(param_2 + 0x1e0))(param_1,param_2,0x11);
        *(undefined4 *)(param_3 + 0x84) = uVar3;
      }
      else if (uVar2 == 0x12) {
        uVar3 = (**(code **)(param_2 + 0x1e0))(param_1,param_2,0x12);
        *(undefined4 *)(param_3 + 0x84) = uVar3;
      }
      else if (uVar2 == 0x10) {
        uVar3 = (**(code **)(param_2 + 0x1e0))(param_1,param_2,0x10);
        *(undefined4 *)(param_3 + 0x84) = uVar3;
      }
      else {
LAB_002c2750:
        uVar4 = 0x3f;
        nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x771,"kbifGetConfigRegData_IMPL",1,
                     "NVRM: Invalid command.\n");
      }
      param_3 = param_3 + 4;
    } while (param_3 != lVar1);
  }
  return uVar4;
}


// ===== 002c2920 subdeviceCtrlCmdBifGetData_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong subdeviceCtrlCmdBifGetData_IMPL(long param_1,int *param_2)

{
  long lVar1;
  ulong uVar2;
  
  if ((uint)param_2[0x42] < 0x21) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
    if (*param_2 == 1) {
      uVar2 = kbifGetConfigRegData_IMPL(lVar1,*(undefined8 *)(lVar1 + 7000),param_2);
      param_2[0x41] = (int)uVar2;
      if ((int)uVar2 != 0) {
        nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x71a,"subdeviceCtrlCmdBifGetData_IMPL",1,
                     "NVRM: Call failed for feature ID = %d.\n",*param_2);
        uVar2 = 0x3f;
      }
    }
    else {
      uVar2 = (**(code **)(lVar1 + 0x3b90))
                        (lVar1 + 0x3b58,*(undefined4 *)(lVar1 + 0x3b34),
                         *(undefined4 *)(lVar1 + 0x3b3c),0x20800a00,param_2,0x10c);
      if ((int)uVar2 == 0) {
        param_2[0x41] = 0;
      }
      else {
        nvCheckOkFailedNoLog
                  (4,uVar2 & 0xffffffff,
                   "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_BIF_GET_DATA, pParams, sizeof(*pParams))"
                   ,"src/kernel/gpu/bif/kernel_bif.c",0x710);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    return uVar2;
  }
  return 0x1f;
}


// ===== 002c2a20 kbifPollDeviceOnBus_IMPL =====

undefined4 kbifPollDeviceOnBus_IMPL(long param_1)

{
  ulong uVar1;
  int iVar2;
  long lVar3;
  undefined1 local_30 [24];
  
  timeoutSet(param_1 + 0x1af0,local_30,0,0);
  while( true ) {
    uVar1 = *(ulong *)(param_1 + 0x878);
    lVar3 = osPciInitHandle(uVar1 >> 0x20,uVar1 >> 8 & 0xff,uVar1 & 0xff,0,0,0);
    if (lVar3 != 0) {
      return 0;
    }
    iVar2 = timeoutCheck(param_1 + 0x1af0,local_30,0x791);
    if (iVar2 == 0x65) break;
    osDelayUs(100);
  }
  nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",0x793,"kbifPollDeviceOnBus_IMPL",4,
               "NVRM: Timeout polling GPU back on bus\n");
  return 0x65;
}


// ===== 002c2ae0 kbifGetPciLinkMaxSpeedByPciGenInfo_IMPL =====

undefined8
kbifGetPciLinkMaxSpeedByPciGenInfo_IMPL
          (undefined8 param_1,undefined8 param_2,uint param_3,int *param_4)

{
  if (param_3 == 3) {
    *param_4 = 4;
    return 0;
  }
  if (param_3 < 4) {
    if (param_3 != 1) {
      *param_4 = (param_3 == 2) + 1 + (uint)(param_3 == 2);
      return 0;
    }
    *param_4 = 2;
    return 0;
  }
  if (param_3 == 4) {
    *param_4 = 5;
    return 0;
  }
  if (param_3 == 5) {
    *param_4 = 6;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/bif/kernel_bif.c",1999,"kbifGetPciLinkMaxSpeedByPciGenInfo_IMPL",4,
               "NVRM: Unknown PCIe Gen Info\n");
  return 0x40;
}


// ===== 002c2b90 kbifWaitForConfigAccessAfterReset_IMPL =====

undefined8 kbifWaitForConfigAccessAfterReset_IMPL(long param_1)

{
  ulong uVar1;
  int iVar2;
  undefined8 uVar3;
  int iVar4;
  undefined1 local_3c [2];
  undefined1 local_3a [10];
  
  iVar4 = 0x15;
  uVar1 = *(ulong *)(param_1 + 0x878);
  while( true ) {
    uVar3 = osPciInitHandle(uVar1 >> 0x20,uVar1 >> 8 & 0xff,uVar1 & 0xff,0,local_3c,local_3a);
    iVar2 = osPciReadDword(uVar3,0);
    if (*(int *)(param_1 + 0x7f4) == iVar2) {
      return 0;
    }
    iVar4 = iVar4 + -1;
    if (iVar4 == 0) break;
    osDelayUs(50000);
  }
  return 0xffff;
}


// ===== 002c2c40 kbifInitDmaCaps_VF =====

void kbifInitDmaCaps_VF(undefined8 param_1,long param_2)

{
  *(undefined4 *)(param_2 + 0x3bc) = 1;
  return;
}


// ===== 002c2c50 subdeviceCtrlCmdBifGetStaticInfo_VF =====

undefined8 subdeviceCtrlCmdBifGetStaticInfo_VF(long param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  long lVar2;
  
  lVar2 = gpuGetStaticInfo(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  if (lVar2 != 0) {
    uVar1 = *(undefined1 *)(lVar2 + 0xa8b8);
    *param_2 = 0;
    param_2[1] = uVar1;
    *(undefined2 *)(param_2 + 2) = 0;
    return 0;
  }
  nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/bif/kernel_bif_vgpu.c",0x48);
  return 0x40;
}


// ===== 002c2cc0 subdeviceCtrlCmdBusGetPcieReqAtomicsCaps_VF =====

undefined8 subdeviceCtrlCmdBusGetPcieReqAtomicsCaps_VF(undefined8 param_1,long param_2)

{
  *(undefined4 *)(param_2 + 8) = 0;
  return 0;
}


// ===== 002c2cd0 subdeviceCtrlCmdBusGetPcieCplAtomicsCaps_VF =====

undefined8 subdeviceCtrlCmdBusGetPcieCplAtomicsCaps_VF(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0;
  return 0;
}


// ===== 002c2ce0 kbusAllocateLegacyFlaVaspace_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int kbusAllocateLegacyFlaVaspace_GA100
              (long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined8 extraout_RDX;
  undefined8 uVar5;
  undefined4 local_b4;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  ulong local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_a8 = 0;
  local_a0 = 0;
  local_98 = 0;
  local_90 = 0;
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  local_b4 = 0;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  lVar4 = rmapiGetInterface(4);
  iVar2 = (**(code **)(lVar4 + 8))(lVar4,0,0,0,0,param_2 + 0xa810,4);
  if (iVar2 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x51);
    return iVar2;
  }
  iVar2 = serverGetClientUnderLock(g_resServ,*(undefined4 *)(param_2 + 0xa810),&local_b0);
  if (iVar2 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x54);
    goto LAB_002c3001;
  }
  iVar2 = serverutilGenResourceHandle(*(undefined4 *)(param_2 + 0xa810),param_2 + 0xa814);
  if (iVar2 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x57);
    goto LAB_002c3001;
  }
  local_a8 = CONCAT44(local_a8._4_4_,*(undefined4 *)(param_1 + 0x7b4));
  iVar2 = (**(code **)(lVar4 + 8))
                    (lVar4,*(undefined4 *)(param_2 + 0xa810),*(undefined4 *)(param_2 + 0xa810),
                     *(undefined4 *)(param_2 + 0xa814),0x80,&local_a8);
  if (iVar2 != 0) {
    nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x61,
                 "kbusAllocateLegacyFlaVaspace_GA100",4,
                 "NVRM: failed creating device, status=0x%x\n",iVar2);
    goto LAB_002c3001;
  }
  iVar2 = serverutilGenResourceHandle(*(undefined4 *)(param_2 + 0xa810),param_2 + 0xa818);
  if (iVar2 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x67);
    goto LAB_002c3001;
  }
  local_b4 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  iVar2 = (**(code **)(lVar4 + 8))
                    (lVar4,*(undefined4 *)(param_2 + 0xa810),*(undefined4 *)(param_2 + 0xa814),
                     *(undefined4 *)(param_2 + 0xa818),0x2080,&local_b4,4);
  if (iVar2 != 0) {
    nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x72,
                 "kbusAllocateLegacyFlaVaspace_GA100",4,
                 "NVRM: failed creating sub-device, status=0x%x\n",iVar2);
    goto LAB_002c3001;
  }
  local_70 = local_70 & 0xffffffff00000000 | 0x20000000000;
  local_68 = param_4;
  local_48 = param_3;
  iVar2 = serverutilGenResourceHandle(*(undefined4 *)(param_2 + 0xa810),param_2 + 0xa81c);
  if (iVar2 != 0) {
    nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x81,
                 "kbusAllocateLegacyFlaVaspace_GA100",4,
                 "NVRM: failed generating vaspace handle, status=0x%x\n",iVar2);
    goto LAB_002c3001;
  }
  cVar1 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_1 + 0x7a4));
  if (cVar1 == '\0') {
    iVar2 = (**(code **)(lVar4 + 8))
                      (lVar4,*(undefined4 *)(param_2 + 0xa810),*(undefined4 *)(param_2 + 0xa814),
                       *(undefined4 *)(param_2 + 0xa81c),0x90f1,&local_70,0x38);
LAB_002c2f5c:
    if (iVar2 == 0) {
      if ((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(param_1 + 0x491e) != '\0')) {
        return 0;
      }
      iVar2 = vaspaceGetByHandleOrDeviceDefault_IMPL
                        (local_b0,*(undefined4 *)(param_2 + 0xa814),
                         *(undefined4 *)(param_2 + 0xa81c),param_2 + 0xa820);
      if (iVar2 == 0) {
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0xa9,
                   "kbusAllocateLegacyFlaVaspace_GA100",4,
                   "NVRM: failed getting the vaspace from handle, status=0x%x\n",iVar2);
      goto LAB_002c3001;
    }
  }
  else {
    rmGpuLocksRelease(0,0);
    lVar4 = rmapiGetInterface(3);
    uVar5 = 0x38;
    iVar2 = (**(code **)(lVar4 + 8))
                      (lVar4,*(undefined4 *)(param_2 + 0xa810),*(undefined4 *)(param_2 + 0xa814),
                       *(undefined4 *)(param_2 + 0xa81c),0x90f1,&local_70);
    iVar3 = rmGpuLocksAcquire(0,0x2001);
    if (iVar3 == 0) {
      lVar4 = rmapiGetInterface(4,0x2c3143,extraout_RDX,uVar5);
      goto LAB_002c2f5c;
    }
    nvAssertOkFailedNoLog
              (iVar3,"rmGpuLocksAcquire(GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_MEM_FLA)",
               "src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x93);
    if (iVar2 == 0) {
      lVar4 = rmapiGetInterface(4);
      iVar2 = iVar3;
    }
    else {
      lVar4 = rmapiGetInterface(4);
    }
  }
  nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x9b,
               "kbusAllocateLegacyFlaVaspace_GA100",4,
               "NVRM: failed allocating vaspace, status=0x%x\n",iVar2);
LAB_002c3001:
  (**(code **)(lVar4 + 0x18))
            (lVar4,*(undefined4 *)(param_2 + 0xa810),*(undefined4 *)(param_2 + 0xa810));
  portMemSet(param_2 + 0xa810,0,0x50);
  nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0xb5,
               "kbusAllocateLegacyFlaVaspace_GA100",4,
               "NVRM: failed allocating FLA VASpace status=0x%x\n",iVar2);
  return iVar2;
}


// ===== 002c3240 kbusAllocateFlaVaspace_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusAllocateFlaVaspace_GA100(long param_1,long param_2,long param_3,long param_4)

{
  undefined8 uVar1;
  long *plVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  undefined8 extraout_RDX_02;
  undefined8 extraout_RDX_03;
  undefined1 auVar9 [16];
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  long local_50;
  long local_48;
  undefined4 local_40;
  undefined4 local_3c;
  
  local_60 = 0;
  local_58 = 0;
  uVar1 = *(undefined8 *)(g_pSys + 0x230);
  uVar7 = *(undefined8 *)(param_1 + 0x1b98);
  lVar6 = rmapiGetInterface(4);
  if (param_4 == 0) {
    nvAssertFailedNoLog("size != 0","src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0xd4);
    return 0x1f;
  }
  if (*(char *)(param_2 + 0xa830) != '\0') {
    nvAssertFailedNoLog("!pKernelBus->flaInfo.bFlaAllocated",
                        "src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0xd5);
    return 0x1f;
  }
  *(long *)(param_2 + 0xa838) = param_3;
  *(long *)(param_2 + 0xa840) = param_4;
  if (((*(char *)(param_1 + 0x491d) != '\0') && (*(long *)(param_1 + 0x1ce8) != 0)) &&
     (cVar3 = knvlinkIsGpuConnectedToNvswitch_IMPL(param_1), cVar3 != '\0')) {
    *(undefined1 *)(param_2 + 0xa832) = 1;
    return 0;
  }
  iVar5 = (**(code **)(param_2 + 0x380))(param_1,param_2,param_3,param_4);
  if (iVar5 != 0) {
    nvAssertOkFailedNoLog
              (iVar5,"kbusAllocateLegacyFlaVaspace_HAL(pGpu, pKernelBus, base, size)",
               "src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0xe6);
    return iVar5;
  }
  uVar4 = gpumgrGetGpuMask(param_1);
  iVar5 = vmmCreateVaspace_IMPL
                    (uVar1,0xfc,*(undefined4 *)(param_1 + 0x7ac),uVar4,param_3,
                     param_3 + -1 + param_4,0,0,0,0,param_1 + 0x4a18);
  if (iVar5 == 0) {
    if ((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x491e) == '\0')) {
      iVar5 = (**(code **)(**(long **)(param_2 + 0xa820) + 0xd0))
                        (*(long **)(param_2 + 0xa820),param_1);
      if (iVar5 == 0) {
        plVar2 = *(long **)(param_1 + 0x4a18);
        if ((plVar2 == (long *)0x0) ||
           (iVar5 = (**(code **)(*plVar2 + 0xd0))(plVar2,param_1), iVar5 == 0)) {
          iVar5 = (**(code **)(param_2 + 0x3b0))(param_1,param_2,0);
          if (iVar5 == 0) {
            iVar5 = kgmmuInstBlkInit_IMPL
                              (uVar7,*(undefined8 *)(param_2 + 0xa828),
                               *(undefined8 *)(param_2 + 0xa820),0xffffffff,&local_60);
            if (iVar5 == 0) goto LAB_002c33e6;
            nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x13f,
                         "kbusAllocateFlaVaspace_GA100",4,
                         "NVRM: failed instantiating instblk for FLA, status=0x%x\n",iVar5);
          }
          else {
            nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x132,
                         "kbusAllocateFlaVaspace_GA100",4,
                         "NVRM: failed constructing instblk for FLA, status=0x%x\n",iVar5);
          }
LAB_002c359d:
          (**(code **)(param_2 + 0x3b8))(param_1,param_2);
        }
        else {
          nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x128,
                       "kbusAllocateFlaVaspace_GA100",4,
                       "NVRM: failed pinning down fabric vaspace, status=0x%x\n",iVar5);
        }
      }
      else {
        nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x11d,
                     "kbusAllocateFlaVaspace_GA100",4,
                     "NVRM: failed pinning down FLAVASpace, status=0x%x\n",iVar5);
      }
      plVar2 = *(long **)(param_2 + 0xa820);
      if (plVar2 != (long *)0x0) {
        (**(code **)(*plVar2 + 0xd8))(plVar2,param_1);
      }
      plVar2 = *(long **)(param_1 + 0x4a18);
      if (plVar2 == (long *)0x0) goto LAB_002c360d;
      (**(code **)(*plVar2 + 0xd8))(plVar2,param_1);
      uVar7 = extraout_RDX_00;
    }
    else {
      local_3c = *(undefined4 *)(param_2 + 0xa81c);
      local_40 = 4;
      local_50 = param_3;
      local_48 = param_4;
      lVar8 = gpuGetRpc(param_1);
      if (lVar8 == 0) {
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x100);
        iVar5 = 0x1a;
        uVar7 = extraout_RDX_02;
      }
      else {
        if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) {
          uVar7 = 0x18;
          iVar5 = rpcDmaControl_wrapper
                            (param_1,lVar8,*(undefined4 *)(param_2 + 0xa810),
                             *(undefined4 *)(param_2 + 0xa818),0x20803501,&local_50);
        }
        else {
          iVar5 = (**(code **)(param_1 + 0x3b90))
                            (param_1 + 0x3b58,*(undefined4 *)(param_2 + 0xa810),
                             *(undefined4 *)(param_2 + 0xa818),0x20803501,&local_50,0x18);
          uVar7 = extraout_RDX;
        }
        if (iVar5 == 0) {
          serverGetClientUnderLock(g_resServ,*(undefined4 *)(param_2 + 0xa810),&local_68);
          iVar5 = vaspaceGetByHandleOrDeviceDefault_IMPL
                            (local_68,*(undefined4 *)(param_2 + 0xa814),
                             *(undefined4 *)(param_2 + 0xa81c),param_2 + 0xa820);
          if (iVar5 == 0) {
LAB_002c33e6:
            *(undefined1 *)(param_2 + 0xa830) = 1;
            *(undefined1 *)(param_2 + 0xa848) = 1;
            if (*(long *)(param_1 + 0x4a18) != 0) {
              uVar7 = __nvoc_dynamicCast(*(long *)(param_1 + 0x4a18),__nvoc_class_def_FABRIC_VASPACE
                                        );
              iVar5 = fabricvaspaceInitUCRange_IMPL(uVar7,param_1,param_3,param_4);
              if (iVar5 != 0) {
                nvAssertOkFailedNoLog
                          (iVar5,
                           "fabricvaspaceInitUCRange( dynamicCast(pGpu->pFabricVAS, FABRIC_VASPACE), pGpu, base, size)"
                           ,"src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x14a);
                goto LAB_002c359d;
              }
            }
            if ((*(char *)(param_1 + 0x491d) == '\0') && (*(char *)(param_1 + 0x908) == '\0')) {
              iVar5 = (**(code **)(param_2 + 0x3d0))(param_1,param_2,0);
            }
            else {
              cVar3 = (**(code **)(param_1 + 0x318))(param_1);
              if (cVar3 == '\0') {
                nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x15b,
                             "kbusAllocateFlaVaspace_GA100",1,
                             "NVRM: Skipping binding FLA, because no P2P GFID is validated yet\n");
                return 0;
              }
              iVar5 = (**(code **)(param_2 + 0x3d0))
                                (param_1,param_2,**(undefined4 **)(param_1 + 0x3af8));
            }
            if (iVar5 == 0) {
              return 0;
            }
            nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x166,
                         "kbusAllocateFlaVaspace_GA100",4,
                         "NVRM: failed binding instblk for FLA, status=0x%x\n",iVar5);
            goto LAB_002c359d;
          }
          nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x111,
                       "kbusAllocateFlaVaspace_GA100",4,
                       "NVRM: failed getting the vaspace from handle, status=0x%x\n",iVar5);
          auVar9 = gpuGetRpc(param_1);
          uVar7 = auVar9._8_8_;
          if (auVar9._0_8_ == 0) {
            iVar5 = 0x1a;
            nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",
                                0x170);
            uVar7 = extraout_RDX_03;
          }
        }
      }
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0xef,
                 "kbusAllocateFlaVaspace_GA100",4,
                 "NVRM: failed allocating fabric vaspace, status=0x%x\n",iVar5);
    uVar7 = extraout_RDX_01;
  }
  if (*(long *)(param_1 + 0x4a18) != 0) {
    vmmDestroyVaspace_IMPL(uVar1,*(long *)(param_1 + 0x4a18),uVar7);
    *(undefined8 *)(param_1 + 0x4a18) = 0;
  }
LAB_002c360d:
  (**(code **)(lVar6 + 0x18))
            (lVar6,*(undefined4 *)(param_2 + 0xa810),*(undefined4 *)(param_2 + 0xa810));
  *(undefined1 *)(param_2 + 0xa830) = 0;
  nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x18e,
               "kbusAllocateFlaVaspace_GA100",4,"NVRM: failed allocating FLA VASpace status=0x%x\n",
               iVar5);
  return iVar5;
}


// ===== 002c3930 kbusAllocateHostManagedFlaVaspace_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusAllocateHostManagedFlaVaspace_GA100
              (long param_1,long param_2,int param_3,int param_4,int param_5,int param_6,
              long param_7,long param_8,int param_9)

{
  undefined8 uVar1;
  long *plVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar5 = *(undefined8 *)(param_1 + 0x1b98);
  local_48 = 0;
  uVar1 = *(undefined8 *)(g_pSys + 0x230);
  local_40 = 0;
  if (param_8 == 0) {
    nvAssertFailedNoLog("size != 0","src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x1b9);
    return 0x1f;
  }
  if (param_9 == 0) {
    nvAssertFailedNoLog("IS_GFID_VF(gfid)","src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x1ba);
    return 0x1f;
  }
  if (param_3 == 0) {
    nvAssertFailedNoLog("hClient != NV01_NULL_OBJECT",
                        "src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x1bb);
    return 0x1f;
  }
  if (param_4 == 0) {
    nvAssertFailedNoLog("hDevice != NV01_NULL_OBJECT",
                        "src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x1bc);
    return 0x1f;
  }
  if (param_5 == 0) {
    nvAssertFailedNoLog("hSubdevice != NV01_NULL_OBJECT",
                        "src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x1bd);
    return 0x1f;
  }
  if (param_6 == 0) {
    nvAssertFailedNoLog("hVASpace != NV01_NULL_OBJECT",
                        "src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x1be);
    return 0x1f;
  }
  if (*(char *)(param_2 + 0xa830) != '\0') {
    nvAssertFailedNoLog("!pKernelBus->flaInfo.bFlaAllocated",
                        "src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x1bf);
    return 0x1f;
  }
  *(int *)(param_2 + 0xa810) = param_3;
  *(long *)(param_2 + 0xa838) = param_7;
  *(int *)(param_2 + 0xa814) = param_4;
  *(long *)(param_2 + 0xa840) = param_8;
  *(int *)(param_2 + 0xa818) = param_5;
  *(int *)(param_2 + 0xa81c) = param_6;
  iVar3 = serverGetClientUnderLock(g_resServ,param_3,&local_50);
  if (iVar3 == 0) {
    vaspaceGetByHandleOrDeviceDefault_IMPL
              (local_50,*(undefined4 *)(param_2 + 0xa814),*(undefined4 *)(param_2 + 0xa81c),
               param_2 + 0xa820);
    uVar4 = gpumgrGetGpuMask(param_1);
    iVar3 = vmmCreateVaspace_IMPL
                      (uVar1,0xfc,*(undefined4 *)(param_1 + 0x7ac),uVar4,param_7,
                       param_7 + -1 + param_8,0,0,0,0,param_1 + 0x4a18);
    if (iVar3 == 0) {
      iVar3 = (**(code **)(**(long **)(param_1 + 0x4a18) + 0xd0))
                        (*(long **)(param_1 + 0x4a18),param_1);
      if (iVar3 == 0) {
        iVar3 = (**(code **)(**(long **)(param_2 + 0xa820) + 0xd0))
                          (*(long **)(param_2 + 0xa820),param_1);
        if (iVar3 == 0) {
          iVar3 = (**(code **)(param_2 + 0x3b0))(param_1,param_2,param_9);
          if (iVar3 == 0) {
            iVar3 = kgmmuInstBlkInit_IMPL
                              (uVar5,*(undefined8 *)(param_2 + 0xa828),
                               *(undefined8 *)(param_2 + 0xa820),0xffffffff,&local_48);
            if (iVar3 == 0) {
              *(undefined1 *)(param_2 + 0xa830) = 1;
              *(undefined1 *)(param_2 + 0xa848) = 1;
              if (*(long *)(param_1 + 0x4a18) == 0) {
                return 0;
              }
              uVar5 = __nvoc_dynamicCast(*(long *)(param_1 + 0x4a18),__nvoc_class_def_FABRIC_VASPACE
                                        );
              iVar3 = fabricvaspaceInitUCRange_IMPL(uVar5,param_1,param_7,param_8);
              if (iVar3 == 0) {
                return 0;
              }
              nvAssertOkFailedNoLog
                        (iVar3,
                         "fabricvaspaceInitUCRange( dynamicCast(pGpu->pFabricVAS, FABRIC_VASPACE), pGpu, base, size)"
                         ,"src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x209);
            }
            else {
              nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x1fe,
                           "kbusAllocateHostManagedFlaVaspace_GA100",4,
                           "NVRM: failed instantiating instblk for FLA, status=0x%x\n",iVar3);
            }
            (**(code **)(param_2 + 0x3b8))(param_1,param_2);
          }
          else {
            nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x1f1,
                         "kbusAllocateHostManagedFlaVaspace_GA100",4,
                         "NVRM: failed constructing instblk for FLA, status=0x%x\n",iVar3);
          }
          plVar2 = *(long **)(param_2 + 0xa820);
          if (plVar2 != (long *)0x0) {
            (**(code **)(*plVar2 + 0xd8))(plVar2,param_1);
          }
        }
        else {
          nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x1e8,
                       "kbusAllocateHostManagedFlaVaspace_GA100",4,
                       "NVRM: failed pinning down legacy vaspace, status=0x%x\n",iVar3);
        }
        plVar2 = *(long **)(param_1 + 0x4a18);
        if (plVar2 == (long *)0x0) goto LAB_002c3bfc;
        (**(code **)(*plVar2 + 0xd8))(plVar2,param_1);
      }
      else {
        nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x1df,
                     "kbusAllocateHostManagedFlaVaspace_GA100",4,
                     "NVRM: failed pinning down fabric vaspace, status=0x%x\n",iVar3);
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x1d6,
                   "kbusAllocateHostManagedFlaVaspace_GA100",4,
                   "NVRM: failed allocating fabric vaspace, status=0x%x\n",iVar3);
    }
  }
  else {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x1c9);
  }
  if (*(long *)(param_1 + 0x4a18) != 0) {
    vmmDestroyVaspace_IMPL(uVar1);
    *(undefined8 *)(param_1 + 0x4a18) = 0;
  }
LAB_002c3bfc:
  *(undefined1 *)(param_2 + 0xa830) = 0;
  return iVar3;
}


// ===== 002c3e40 kbusCheckFlaSupportedAndInit_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbusCheckFlaSupportedAndInit_GA100
                (long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  char cVar2;
  ulong uVar3;
  
  lVar1 = *(long *)(param_1 + 0x1bc0);
  portMemSet(param_2 + 0xa810,0,0x50);
  if ((((lVar1 == 0) || (cVar2 = kmigmgrIsMIGNvlinkP2PSupported_IMPL(param_1,lVar1), cVar2 != '\0'))
      && (*(char *)(param_1 + 0x44d) == '\0')) && (*(char *)(param_1 + 1099) == '\0')) {
    nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x251,
                 "kbusCheckFlaSupportedAndInit_GA100",1,
                 "NVRM: Enabling FLA_SUPPORTED to TRUE, gpu: %x ...\n",
                 *(undefined4 *)(param_1 + 0x7a4));
    *(undefined1 *)(param_2 + 0xa860) = 1;
    uVar3 = (**(code **)(param_2 + 0x368))(param_1,param_2,param_3,param_4);
    if ((int)uVar3 == 0) {
      return uVar3;
    }
    nvAssertOkFailedNoLog
              (uVar3 & 0xffffffff,
               "kbusDetermineFlaRangeAndAllocate_HAL(pGpu, pKernelBus, base, size)",
               "src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x25c);
    return uVar3 & 0xffffffff;
  }
  nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x24b,
               "kbusCheckFlaSupportedAndInit_GA100",1,
               "NVRM: FLA is disabled, gpu %x is in MIG/SLI mode \n",
               *(undefined4 *)(param_1 + 0x7a4));
  *(undefined1 *)(param_2 + 0xa860) = 0;
  return 0;
}


// ===== 002c3f70 kbusDetermineFlaRangeAndAllocate_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusDetermineFlaRangeAndAllocate_GA100(long param_1,long param_2,long param_3,long param_4)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined1 local_38 [8];
  long local_30;
  
  if (*(char *)(g_pSys + 0x6b) == '\0') {
    cVar2 = hypervisorIsVgxHyper_IMPL();
    if (cVar2 == '\0') {
      local_30 = param_3;
      if (param_4 == 0) {
        param_4 = (**(code **)(param_1 + 0x340))(param_1,0);
        local_30 = (ulong)*(uint *)(param_1 + 0x7a4) * param_4;
      }
      goto LAB_002c4025;
    }
    nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x2a1,
                 "kbusDetermineFlaRangeAndAllocate_GA100",1,
                 "NVRM: Skipping the FLA initialization in Host vGPU \n");
  }
  else {
    lVar1 = *(long *)(param_1 + 0x1ce8);
    if ((lVar1 != 0) && (cVar2 = knvlinkIsNvswitchProxyPresent_IMPL(param_1,lVar1), cVar2 != '\0'))
    {
      portMemSet(local_38,0,0x10);
      local_38[0] = 1;
      iVar3 = knvlinkExecGspRmRpc_IMPL(param_1,lVar1,0x20803038,local_38,0x10);
      if (iVar3 != 0) {
        nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x288,
                     "kbusDetermineFlaRangeAndAllocate_GA100",4,
                     "NVRM: Failed to get the NVSwitch FLA address\n");
        return iVar3;
      }
      param_4 = (**(code **)(param_1 + 0x340))(param_1,1);
      iVar3 = knvlinkSetUniqueFlaBaseAddress_IMPL(param_1,lVar1,local_30);
      if (iVar3 != 0) {
        nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x292,
                     "kbusDetermineFlaRangeAndAllocate_GA100",1,
                     "NVRM: Failed to enable FLA for GPU: %x\n",*(undefined4 *)(param_1 + 0x7a4));
        return iVar3;
      }
LAB_002c4025:
      iVar3 = (**(code **)(param_2 + 0x370))(param_1,param_2,local_30,param_4);
      if (iVar3 == 0) {
        return 0;
      }
      nvAssertOkFailedNoLog
                (iVar3,"kbusAllocateFlaVaspace_HAL(pGpu, pKernelBus, base, size)",
                 "src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x2aa);
      return iVar3;
    }
  }
  return 0;
}


// ===== 002c4170 kbusDestroyFla_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbusDestroyFla_GA100(long param_1,long param_2)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  long *plVar5;
  undefined8 uStack_50;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  uVar1 = *(undefined8 *)(g_pSys + 0x230);
  lVar3 = rmapiGetInterface(4);
  plVar5 = *(long **)(param_2 + 0xa820);
  if ((plVar5 == (long *)0x0) && (*(long *)(param_1 + 0x4a18) == 0)) {
    return;
  }
  if (*(char *)(param_2 + 0xa831) == '\0') {
LAB_002c41e9:
    if (*(char *)(param_2 + 0xa830) == '\0') {
      return;
    }
    if ((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(param_1 + 0x491e) != '\0')) {
      local_40 = 0;
      local_38 = 0;
      local_30 = 8;
      uStack_50 = 0x2c4317;
      lVar4 = gpuGetRpc(param_1);
      if (lVar4 == 0) {
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x2d2);
        iVar2 = 0x1a;
      }
      else {
        if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) {
          iVar2 = rpcDmaControl_wrapper
                            (param_1,lVar4,*(undefined4 *)(param_2 + 0xa810),
                             *(undefined4 *)(param_2 + 0xa818),0x20803501,&local_40,0x18);
        }
        else {
          iVar2 = (**(code **)(param_1 + 0x3b90))
                            (param_1 + 0x3b58,*(undefined4 *)(param_2 + 0xa810),
                             *(undefined4 *)(param_2 + 0xa818),0x20803501,&local_40,0x18);
          uStack_50 = extraout_RDX_00;
        }
        if (iVar2 == 0) goto LAB_002c425f;
      }
      nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x2d8,"kbusDestroyFla_GA100",3,
                   "NVRM: RPC to host failed with status: 0x%x\n",iVar2);
      uStack_50 = extraout_RDX_01;
      goto LAB_002c425f;
    }
    plVar5 = *(long **)(param_2 + 0xa820);
  }
  else {
    if ((*(char *)(param_1 + 0x908) != '\0') || (*(char *)(param_1 + 0x909) != '\0')) {
      (**(code **)(param_2 + 0x3c8))(param_1,param_2);
      goto LAB_002c41e9;
    }
    if (*(char *)(param_2 + 0xa830) == '\0') {
      return;
    }
  }
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0xd8))(plVar5,param_1);
  }
  plVar5 = *(long **)(param_1 + 0x4a18);
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0xd8))(plVar5,param_1);
  }
  (**(code **)(param_2 + 0x3b8))(param_1,param_2);
  uStack_50 = extraout_RDX;
LAB_002c425f:
  if (*(long *)(param_1 + 0x4a18) != 0) {
    vmmDestroyVaspace_IMPL(uVar1,*(long *)(param_1 + 0x4a18),uStack_50);
    *(undefined8 *)(param_1 + 0x4a18) = 0;
  }
  (**(code **)(lVar3 + 0x18))
            (lVar3,*(undefined4 *)(param_2 + 0xa810),*(undefined4 *)(param_2 + 0xa810));
  portMemSet(param_2 + 0xa810,0,0x50);
  *(undefined1 *)(param_2 + 0xa830) = 0;
  return;
}


// ===== 002c43f0 kbusDestroyHostManagedFlaVaspace_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbusDestroyHostManagedFlaVaspace_GA100(long param_1,long param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  long *plVar3;
  long lVar4;
  ulong uVar5;
  
  uVar2 = *(undefined8 *)(g_pSys + 0x230);
  uVar1 = *(undefined4 *)(param_1 + 0x7a4);
  uVar5 = (ulong)*(uint *)(param_2 + 0xa81c);
  nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x310,
               "kbusDestroyHostManagedFlaVaspace_GA100",1,
               "NVRM: Freeing the FLA client: 0x%x FLAVASpace:%x, gpu:%x \n",
               *(undefined4 *)(param_2 + 0xa810));
  if (*(char *)(param_2 + 0xa830) != '\0') {
    plVar3 = *(long **)(param_2 + 0xa820);
    lVar4 = *(long *)(param_1 + 0x1ce8);
    if (plVar3 != (long *)0x0) {
      (**(code **)(*plVar3 + 0xd8))(plVar3,param_1,uVar1);
      *(undefined4 *)(param_2 + 0xa81c) = 0;
      *(undefined8 *)(param_2 + 0xa820) = 0;
    }
    plVar3 = *(long **)(param_1 + 0x4a18);
    if (plVar3 != (long *)0x0) {
      (**(code **)(*plVar3 + 0xd8))(plVar3,param_1);
      vmmDestroyVaspace_IMPL(uVar2,*(undefined8 *)(param_1 + 0x4a18));
      *(undefined8 *)(param_1 + 0x4a18) = 0;
    }
    uVar5 = (**(code **)(param_2 + 0x3b8))(param_1,param_2);
    *(undefined1 *)(param_2 + 0xa830) = 0;
    *(undefined8 *)(param_2 + 0xa810) = 0;
    *(undefined4 *)(param_2 + 0xa818) = 0;
    if (lVar4 != 0) {
      uVar5 = knvlinkIsGpuConnectedToNvswitch_IMPL(param_1,lVar4);
      if ((char)uVar5 != '\0') {
        return uVar5;
      }
    }
    *(undefined1 *)(param_2 + 0xa832) = 0;
    *(undefined8 *)(param_2 + 0xa838) = 0;
    *(undefined8 *)(param_2 + 0xa840) = 0;
  }
  return uVar5;
}


// ===== 002c4570 kbusGetFlaVaspace_GA100 =====

undefined8 kbusGetFlaVaspace_GA100(long param_1,long param_2,long *param_3)

{
  long lVar1;
  long lVar2;
  char cVar3;
  
  lVar1 = *(long *)(param_1 + 0x1bc0);
  lVar2 = *(long *)(param_1 + 0x1ce8);
  *param_3 = 0;
  if ((*(char *)(param_1 + 0x908) == '\0') && (lVar2 == 0)) {
    nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x34c,"kbusGetFlaVaspace_GA100",3
                 ,"NVRM: Nvlink is not supported in this GPU: %x \n",
                 *(undefined4 *)(param_1 + 0x7a4));
  }
  else {
    if ((lVar1 != 0) && (cVar3 = kmigmgrIsMIGNvlinkP2PSupported_IMPL(), cVar3 == '\0')) {
      nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x353,"kbusGetFlaVaspace_GA100"
                   ,3,"NVRM: FLA is not supported with MIG enabled, GPU: %x \n",
                   *(undefined4 *)(param_1 + 0x7a4));
      return 0x56;
    }
    if (*(char *)(param_2 + 0xa860) == '\0') {
      nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x359,"kbusGetFlaVaspace_GA100"
                   ,3,"NVRM: FLA is not supported, GPU: %x\n",*(undefined4 *)(param_1 + 0x7a4));
    }
    else {
      if (((*(char *)(param_1 + 0x908) != '\0') || (*(char *)(param_2 + 0xa861) != '\0')) ||
         (*(char *)(param_1 + 0x491d) != '\0')) {
        lVar1 = *(long *)(param_2 + 0xa820);
        *param_3 = lVar1;
        nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x36e,
                     "kbusGetFlaVaspace_GA100",1,
                     "NVRM: returning the vas: %p for GPU: %x start: 0x%llx, limit:0x%llx \n",lVar1,
                     *(undefined4 *)(param_1 + 0x7a4),*(undefined8 *)(lVar1 + 0x60),
                     *(undefined8 *)(lVar1 + 0x68));
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x361,"kbusGetFlaVaspace_GA100"
                   ,3,"NVRM: FLA is not enabled, GPU: %x\n",*(undefined4 *)(param_1 + 0x7a4));
    }
  }
  return 0x56;
}


// ===== 002c4710 kbusConstructFlaInstBlk_GA100 =====

ulong kbusConstructFlaInstBlk_GA100(long param_1,long param_2,int param_3)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  
  if (*(char *)(param_1 + 0x491e) == '\0') {
    lVar3 = (ulong)(param_3 != 0) << 0x19;
  }
  else {
    if (param_3 == 0) {
      return 0x1f;
    }
    lVar3 = 0x2000000;
  }
  uVar1 = *(undefined8 *)(param_1 + 0x1b78);
  iVar2 = memdescCreate(param_2 + 0xa828,param_1,0x1000,0,1,2);
  if (iVar2 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x39d,
                        lVar3);
  }
  *(undefined4 *)(*(long *)(param_2 + 0xa828) + 0x9c) = 0x7a;
  iVar2 = memdescAlloc(*(undefined8 *)(param_2 + 0xa828));
  if (iVar2 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x3a2);
  }
  uVar4 = memmgrMemDescMemSet_IMPL(uVar1,*(undefined8 *)(param_2 + 0xa828),0,0);
  if ((int)uVar4 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x3a9);
    uVar4 = uVar4 & 0xffffffff;
  }
  return uVar4;
}


// ===== 002c4830 kbusDestructFlaInstBlk_GA100 =====

void kbusDestructFlaInstBlk_GA100(undefined8 param_1,long param_2)

{
  if (*(long *)(param_2 + 0xa828) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 0xa828));
    *(undefined8 *)(param_2 + 0xa828) = 0;
    return;
  }
  return;
}


// ===== 002c4880 kbusIsDirectMappingAllowed_GA100 =====

undefined8
kbusIsDirectMappingAllowed_GA100
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,uint param_4,undefined1 *param_5
          )

{
  char cVar1;
  
  *param_5 = 0;
  if ((param_4 & 0x18000) == 0x10000) {
    nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x3da,
                 "kbusIsDirectMappingAllowed_GA100",3,
                 "NVRM: BAR allocation trying to request reflected mapping, by passing the map flags, failing the request \n"
                );
  }
  cVar1 = memdescGetFlag(param_3,0x800);
  if (cVar1 == '\0') {
    *param_5 = 1;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x3e0,
               "kbusIsDirectMappingAllowed_GA100",3,
               "NVRM: BAR allocation trying to request reflected mapping, by setting ENCRYPTED flag in memdesc, failing the request \n"
              );
  return 0x1f;
}


// ===== 002c4940 kbusGetNvlinkP2PPeerId_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kbusGetNvlinkP2PPeerId_GA100
          (long param_1,long param_2,long param_3,undefined8 param_4,uint *param_5,uint param_6)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  undefined8 uVar4;
  int iVar5;
  
  if (param_5 == (uint *)0x0) {
    return 0x1f;
  }
  lVar1 = *(long *)(param_1 + 0x1ce8);
  *param_5 = 0xffffffff;
  if (lVar1 == 0) {
    return 0;
  }
  param_6 = param_6 & 0x20;
  cVar2 = knvlinkIsForcedConfig_IMPL(param_1,lVar1);
  if ((cVar2 == '\0') && (*(char *)(lVar1 + 0x339) == '\0')) {
    cVar2 = knvlinkIsForcedConfig_IMPL(param_1,lVar1);
    if ((cVar2 == '\0') && (*(char *)(lVar1 + 0x339) == '\0')) {
      if (0x1f < *(uint *)(param_3 + 0x7a4)) {
        return 0;
      }
      if (*(long *)(lVar1 + 0x14c8 + (ulong)*(uint *)(param_3 + 0x7a4) * 8) == 0) {
        return 0;
      }
    }
    if (param_6 != 0) goto LAB_002c49e0;
    uVar3 = (**(code **)(param_2 + 0x288))(param_1,param_2,param_3);
    *param_5 = uVar3;
    if (uVar3 != 0xffffffff) {
      return 0;
    }
    if ((param_1 == param_3) ||
       (cVar2 = knvlinkIsGpuConnectedToNvswitch_IMPL(param_1,lVar1), cVar2 != '\0')) {
      *param_5 = 0;
      iVar5 = 1;
      goto LAB_002c4ae0;
    }
  }
  else {
    if (param_6 == 0) {
      uVar3 = kbusGetPeerIdFromTable_GM107
                        (param_1,param_2,*(undefined4 *)(param_1 + 0x7a4),
                         *(undefined4 *)(param_3 + 0x7a4));
      *param_5 = uVar3;
      uVar4 = 0x3f;
      if (uVar3 != 0xffffffff) {
        uVar4 = 0;
      }
      return uVar4;
    }
    cVar2 = knvlinkIsForcedConfig_IMPL(param_1,lVar1);
    if ((cVar2 == '\0') && (*(char *)(lVar1 + 0x339) == '\0')) {
      if (0x1f < *(uint *)(param_3 + 0x7a4)) {
        return 0;
      }
      if (*(long *)(lVar1 + 0x14c8 + (ulong)*(uint *)(param_3 + 0x7a4) * 8) == 0) {
        return 0;
      }
    }
LAB_002c49e0:
    uVar3 = (**(code **)(param_2 + 0x280))(param_1,param_2,param_3);
    *param_5 = uVar3;
    if (uVar3 != 0xffffffff) {
      return 0;
    }
    cVar2 = knvlinkIsGpuConnectedToNvswitch_IMPL(param_1,lVar1);
    if (cVar2 != '\0') {
      *param_5 = 1;
      iVar5 = 2;
      goto LAB_002c4ae0;
    }
  }
  iVar5 = 1 << ((byte)*param_5 & 0x1f);
  if (*param_5 == 0xffffffff) {
    uVar3 = kbusGetUnusedPeerId_GM107(param_1,param_2,0x80000000);
    *param_5 = uVar3;
    if (uVar3 == 0xffffffff) {
      nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x469,
                   "kbusGetNvlinkP2PPeerId_GA100",3,
                   "NVRM: GPU%d: peerID not available for NVLink P2P\n",
                   *(undefined4 *)(param_1 + 0x7a4));
      return 0xffff;
    }
    iVar5 = 1 << ((byte)uVar3 & 0x1f);
  }
LAB_002c4ae0:
  uVar4 = kbusReserveP2PPeerIds_GM200(param_1,param_2,iVar5);
  if ((int)uVar4 == 0) {
    *(char *)(param_2 + 0xaa34 + (ulong)*param_5) = (char)(param_6 >> 5);
    return uVar4;
  }
  return uVar4;
}


// ===== 002c4c10 kbusUseDirectSysmemMap_GA100 =====

undefined8
kbusUseDirectSysmemMap_GA100
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 *param_4)

{
  int iVar1;
  
  *param_4 = 0;
  iVar1 = memdescGetAddressSpace(param_3);
  if (iVar1 != 2) {
    *param_4 = 1;
  }
  return 0;
}


// ===== 002c4c40 kbusValidateFlaBaseAddress_GA100 =====

byte kbusValidateFlaBaseAddress_GA100(long param_1,undefined8 param_2,ulong param_3)

{
  byte bVar1;
  
  bVar1 = 0x1f;
  if ((param_3 & 0xfffffffff) == 0) {
    bVar1 = -(0x800000000000 <
             (*(long *)(*(long *)(param_1 + 0x1b78) + 0x830) * 0x100000 + 0xfffffffffU &
             0xfffffff000000000) + param_3) & 0x1f;
  }
  return bVar1;
}


// ===== 002c4c90 kbusVerifyFlaRange_GA100 =====

undefined1  [16]
kbusVerifyFlaRange_GA100(undefined8 param_1,long param_2,ulong param_3,long param_4)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined8 uStack_10;
  
  if ((*(ulong *)(param_2 + 0xa838) == param_3) && (*(long *)(param_2 + 0xa840) == param_4)) {
    nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x4e4,"kbusVerifyFlaRange_GA100",
                 1,"NVRM: FLA base: %llx, size: %llx is verified \n",param_3,param_4);
    auVar2._8_8_ = uStack_10;
    auVar2._0_8_ = 1;
    return auVar2;
  }
  auVar1._8_8_ = 0;
  auVar1._0_8_ = param_3;
  return auVar1 << 0x40;
}


// ===== 002c4cf0 kbusGetNvSwitchPeerId_GA100 =====

uint kbusGetNvSwitchPeerId_GA100(long param_1,long param_2)

{
  char cVar1;
  uint uVar2;
  uint *puVar3;
  
  if (((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4cc) != '\x01')) &&
     ((*(long *)(param_1 + 0x1ce8) == 0 ||
      (cVar1 = knvlinkIsGpuConnectedToNvswitch_IMPL(), cVar1 == '\0')))) {
    return 0xffffffff;
  }
  puVar3 = (uint *)(param_2 + 0xa8f4);
  do {
    uVar2 = *puVar3;
    if (uVar2 != 0) {
      uVar2 = -uVar2 & uVar2;
      return (uint)((uVar2 & 0xaaaaaaaa) != 0) | (uint)(0xffff < uVar2) << 4 |
             (uint)((uVar2 & 0xff00ff00) != 0) << 3 | (uint)((uVar2 & 0xf0f0f0f0) != 0) << 2 |
             (uint)((uVar2 & 0xcccccccc) != 0) * 2;
    }
    puVar3 = puVar3 + 1;
  } while (puVar3 != (uint *)(param_2 + 0xa974));
  return 0;
}


// ===== 002c4dc0 kbusSetupBindFla_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusSetupBindFla_GA100(long param_1,long param_2)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 local_38;
  ulong local_30;
  
  local_38 = 0;
  local_30 = 0;
  if (*(char *)(param_1 + 0x491e) == '\0') {
    uVar1 = *(undefined8 *)(param_2 + 0xa828);
    uVar4 = memdescGetPhysAddr(uVar1,1,0);
    iVar2 = memdescGetAddressSpace(uVar1);
    local_30 = (ulong)(iVar2 != 1);
    local_38 = uVar4;
  }
  lVar3 = gpuGetRpc(param_1);
  if (lVar3 == 0) {
    iVar2 = 0x1a;
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x53f);
  }
  else {
    if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) {
      iVar2 = rpcDmaControl_wrapper
                        (param_1,lVar3,*(undefined4 *)(param_2 + 0xa810),
                         *(undefined4 *)(param_2 + 0xa818),0x20803502,&local_38,0x10);
    }
    else {
      iVar2 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_2 + 0xa810),
                         *(undefined4 *)(param_2 + 0xa818),0x20803502,&local_38,0x10);
    }
    if (iVar2 == 0) {
      *(undefined1 *)(param_2 + 0xa831) = 1;
      *(undefined1 *)(param_2 + 0xa861) = 1;
      return 0;
    }
  }
  nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x546,"kbusSetupBindFla_GA100",4,
               "NVRM: FLA bind failed, status: %x \n",iVar2);
  return iVar2;
}


// ===== 002c4f50 kbusSetupUnbindFla_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbusSetupUnbindFla_GA100(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 local_28;
  undefined8 local_20;
  
  local_28 = 0;
  if (*(char *)(param_2 + 0xa831) == '\0') {
    return 0;
  }
  local_20 = 0x100000000;
  lVar1 = gpuGetRpc();
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x565);
    uVar2 = 0x1a;
  }
  else if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) {
    uVar2 = rpcDmaControl_wrapper
                      (param_1,lVar1,*(undefined4 *)(param_2 + 0xa810),
                       *(undefined4 *)(param_2 + 0xa818),0x20803502,&local_28,0x10);
  }
  else {
    uVar2 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_2 + 0xa810),
                       *(undefined4 *)(param_2 + 0xa818),0x20803502,&local_28,0x10);
  }
  *(undefined1 *)(param_2 + 0xa831) = 0;
  *(undefined1 *)(param_2 + 0xa861) = 0;
  return uVar2;
}


// ===== 002c5040 kbusGetFlaRange_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbusGetFlaRange_GA100(long param_1,long param_2,long *param_3,long *param_4,char param_5)

{
  long lVar1;
  
  if ((*(char *)(param_1 + 0x491d) != '\0') && (param_5 != '\0')) {
    if (*(char *)(param_2 + 0xa832) != '\0') {
      *param_3 = *(long *)(param_2 + 0xa838);
      *param_4 = *(long *)(param_2 + 0xa840);
    }
    return 0;
  }
  lVar1 = (**(code **)(param_1 + 0x340))(param_1,0);
  *param_4 = lVar1;
  *param_3 = (ulong)*(uint *)(param_1 + 0x7a4) * lVar1;
  return 0;
}


// ===== 002c50c0 kbusGetNvlinkPeerId_GA100 =====

uint kbusGetNvlinkPeerId_GA100(long param_1,long param_2,long param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0xa8f4 + (ulong)*(uint *)(param_3 + 0x7a4) * 4);
  if (uVar1 != 0) {
    uVar1 = -uVar1 & uVar1;
    return (uint)((uVar1 & 0xaaaaaaaa) != 0) | (uint)(0xffff < uVar1) << 4 |
           (uint)((uVar1 & 0xff00ff00) != 0) << 3 | (uint)((uVar1 & 0xf0f0f0f0) != 0) << 2 |
           (uint)((uVar1 & 0xcccccccc) != 0) * 2;
  }
  nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x5a2,"kbusGetNvlinkPeerId_GA100",1
               ,"NVRM: NVLINK P2P not set up between GPU%u and GPU%u, checking for PCIe P2P...\n",
               *(undefined4 *)(param_1 + 0x7a4),(ulong)*(uint *)(param_3 + 0x7a4));
  return 0xffffffff;
}


// ===== 002c5170 kbusCacheBAR1ResizeSize_WAR_BUG_3249028_GA100 =====

void kbusCacheBAR1ResizeSize_WAR_BUG_3249028_GA100(long param_1,long param_2)

{
  byte extraout_AH;
  
  regRead032(param_1 + 0x3a18,0,0,0x88bc0,0);
  *(byte *)(param_2 + 0xa863) = extraout_AH & 0x1f;
  return;
}


// ===== 002c51b0 kbusRestoreBAR1ResizeSize_WAR_BUG_3249028_GA100 =====

undefined8 kbusRestoreBAR1ResizeSize_WAR_BUG_3249028_GA100(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (*(char *)(param_2 + 0x559) == '\0') {
    return 0;
  }
  if (*(byte *)(param_2 + 0xa863) < 6) {
    nvAssertFailedNoLog("pKernelBus->bar1ResizeSizeIndex >= NV_XVE_RESIZE_BAR1_CTRL_BAR_SIZE_MIN",
                        "src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x5dd);
  }
  else {
    if (*(byte *)(param_2 + 0xa863) < 0x14) {
      uVar1 = regRead032(param_1 + 0x3a18,0,0,0x88bc0,0);
      uVar2 = uVar1 >> 8 & 0x1f;
      if (*(byte *)(param_2 + 0xa863) != uVar2) {
        nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x5ed,
                     "kbusRestoreBAR1ResizeSize_WAR_BUG_3249028_GA100",3,
                     "NVRM: BAR1 size mismatch: current: 0x%x, expected: 0x%x\n",uVar2,
                     *(byte *)(param_2 + 0xa863));
        nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x5ef,
                     "kbusRestoreBAR1ResizeSize_WAR_BUG_3249028_GA100",3,
                     "NVRM: Most likely SBIOS did not restore the BAR1 size\n");
        nvDbg_Printf("src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x5f0,
                     "kbusRestoreBAR1ResizeSize_WAR_BUG_3249028_GA100",3,
                     "NVRM: Please update your SBIOS!\n");
        regWrite032(param_1 + 0x3a18,0,0,0x88bc0,
                    (*(byte *)(param_2 + 0xa863) & 0x1f) << 8 | uVar1 & 0xffffe0ff,0);
      }
      return 0;
    }
    nvAssertFailedNoLog("pKernelBus->bar1ResizeSizeIndex <= NV_XVE_RESIZE_BAR1_CTRL_BAR_SIZE_MAX",
                        "src/kernel/gpu/bus/arch/ampere/kern_bus_ga100.c",0x5e0);
  }
  return 0x25;
}


// ===== 002c5340 kbusGetP2PWriteMailboxAddressSize_GB100 =====

undefined8 kbusGetP2PWriteMailboxAddressSize_GB100(void)

{
  return 0x17;
}


// ===== 002c534a kbusWriteBAR0WindowBase_GB100.cold =====

void kbusWriteBAR0WindowBase_GB100_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002c5360 kbusWriteBAR0WindowBase_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbusWriteBAR0WindowBase_GB100(undefined8 param_1,long param_2,uint param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  
  lVar3 = (**(code **)(param_2 + 0x550))(param_1,param_2,0);
  if (lVar3 != 0) {
    uVar2 = (**(code **)(**(long **)(lVar3 + 0x50) + 0x28))(*(long **)(lVar3 + 0x50),0xd40);
    (**(code **)(**(long **)(lVar3 + 0x50) + 0x40))
              (*(long **)(lVar3 + 0x50),0xd40,uVar2 & 0xff800000 | param_3 & 0x7fffff);
    return 0;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002c53ca kbusReadBAR0WindowBase_GB100.cold =====

void kbusReadBAR0WindowBase_GB100_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002c53e0 kbusReadBAR0WindowBase_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kbusReadBAR0WindowBase_GB100(undefined8 param_1,long param_2)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  
  lVar3 = (**(code **)(param_2 + 0x550))(param_1,param_2,0);
  if (lVar3 != 0) {
    uVar2 = (**(code **)(**(long **)(lVar3 + 0x50) + 0x28))(*(long **)(lVar3 + 0x50),0xd40);
    return uVar2 & 0x7fffff;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002c5420 kbusValidateBAR0WindowBase_GB100 =====

bool kbusValidateBAR0WindowBase_GB100(undefined8 param_1,undefined8 param_2,uint param_3)

{
  return param_3 < 0x800000;
}


// ===== 002c5430 kbusCacheBAR1ResizeSize_WAR_BUG_3249028_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbusCacheBAR1ResizeSize_WAR_BUG_3249028_GB100(long param_1,long param_2)

{
  int iVar1;
  int local_1c;
  
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x19c,&local_1c);
  if ((iVar1 == 0) && (local_1c != 0)) {
    iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x1a0,&local_1c);
    if (iVar1 == 0) {
      *(byte *)(param_2 + 0xa863) = (byte)((uint)local_1c >> 8) & 0x3f;
      return;
    }
    nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb100.c",0x86,
                 "kbusCacheBAR1ResizeSize_WAR_BUG_3249028_GB100",4,
                 "NVRM: Unable to read NV_PF0_PF_RESIZABLE_BAR_CONTROL\n");
  }
  else {
    nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb100.c",0x7f,
                 "kbusCacheBAR1ResizeSize_WAR_BUG_3249028_GB100",1,
                 "NVRM: Resizable bar capability is absent\n");
  }
  *(undefined1 *)(param_2 + 0x559) = 0;
  return;
}


// ===== 002c5510 kbusRestoreBAR1ResizeSize_WAR_BUG_3249028_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kbusRestoreBAR1ResizeSize_WAR_BUG_3249028_GB100(long param_1,long param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint local_1c;
  
  if (*(char *)(param_2 + 0x559) != '\0') {
    if (*(byte *)(param_2 + 0xa863) < 6) {
      nvAssertFailedNoLog("pKernelBus->bar1ResizeSizeIndex >= NV_PF0_PF_RESIZABLE_BAR_CONTROL_BAR_SIZE_MIN"
                          ,"src/kernel/gpu/bus/arch/blackwell/kern_bus_gb100.c",0xa8);
      uVar3 = 0x25;
    }
    else {
      iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x1a0,&local_1c);
      if (iVar1 == 0) {
        uVar2 = local_1c >> 8 & 0x3f;
        uVar3 = 0;
        if (*(byte *)(param_2 + 0xa863) != uVar2) {
          nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb100.c",0xba,
                       "kbusRestoreBAR1ResizeSize_WAR_BUG_3249028_GB100",3,
                       "NVRM: BAR1 size mismatch: current: 0x%x, expected: 0x%x\n",uVar2,
                       *(byte *)(param_2 + 0xa863));
          nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb100.c",0xbc,
                       "kbusRestoreBAR1ResizeSize_WAR_BUG_3249028_GB100",3,
                       "NVRM: Most likely SBIOS did not restore the BAR1 size\n");
          nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb100.c",0xbd,
                       "kbusRestoreBAR1ResizeSize_WAR_BUG_3249028_GB100",3,
                       "NVRM: Please update your SBIOS!\n");
          local_1c = (*(byte *)(param_2 + 0xa863) & 0x3f) << 8 | local_1c & 0xffffc0ff;
          (**(code **)(param_1 + 0x1b8))(param_1,0x1a0);
        }
      }
      else {
        nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb100.c",0xad,
                     "kbusRestoreBAR1ResizeSize_WAR_BUG_3249028_GB100",4,
                     "NVRM: Unable to read NV_PF0_PF_RESIZABLE_BAR_CONTROL\n");
        uVar3 = 0x56;
      }
    }
    return uVar3;
  }
  return 0;
}


// ===== 002c56a0 kbusGetPFBar1Spa_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbusGetPFBar1Spa_GB100(long param_1,undefined8 param_2,undefined8 *param_3)

{
  ulong uVar1;
  undefined8 local_20 [2];
  
  local_20[0] = 0;
  uVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800aee,local_20,8);
  if ((int)uVar1 == 0) {
    *param_3 = local_20[0];
    return uVar1;
  }
  nvAssertOkFailedNoLog
            (uVar1 & 0xffffffff,
             "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_GPU_GET_PF_BAR1_SPA, &params, sizeof(params))"
             ,"src/kernel/gpu/bus/arch/blackwell/kern_bus_gb100.c",0xdd);
  return uVar1 & 0xffffffff;
}


// ===== 002c5720 kbusCarveoutWprs_GB100 =====

void kbusCarveoutWprs_GB100(long param_1,undefined8 param_2,long *param_3)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  long local_30 [2];
  
  iVar1 = gpuGetOneDeviceEntry_IMPL(param_1,0x35,0xffffffff,0,0xffffffff,local_30);
  if (iVar1 == 0) {
    param_1 = param_1 + 0x3a18;
    uVar2 = regRead032(param_1,0,0,*(int *)(local_30[0] + 0x10) + 0xa81c,0);
    lVar4 = (ulong)(uVar2 >> 4) << 0xc;
    uVar2 = regRead032(param_1,0,0,*(int *)(local_30[0] + 0x10) + 0xa820,0);
    lVar3 = (ulong)(uVar2 >> 4) * 0x1000;
    if ((lVar4 == lVar3) || ((ulong)(uVar2 >> 4) == 0)) {
      lVar4 = 1;
      lVar3 = 0;
    }
    else {
      lVar3 = lVar3 + -1;
    }
    param_3[1] = lVar3;
    *param_3 = lVar4;
    uVar2 = regRead032(param_1,0,0,*(int *)(local_30[0] + 0x10) + 0xa824,0);
    lVar4 = (ulong)(uVar2 >> 4) << 0xc;
    uVar2 = regRead032(param_1,0,0,*(int *)(local_30[0] + 0x10) + 0xa828,0);
    lVar3 = (ulong)(uVar2 >> 4) * 0x1000;
    if ((lVar4 == lVar3) || ((ulong)(uVar2 >> 4) == 0)) {
      lVar4 = 1;
      lVar3 = 0;
    }
    else {
      lVar3 = lVar3 + -1;
    }
    param_3[2] = lVar4;
    param_3[3] = lVar3;
    return;
  }
  nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/blackwell/kern_bus_gb100.c",0xf7);
  return;
}


// ===== 002c5882 kbusWriteBAR0WindowBase_GB10B.cold =====

void kbusWriteBAR0WindowBase_GB10B_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002c5890 kbusWriteBAR0WindowBase_GB10B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbusWriteBAR0WindowBase_GB10B(undefined8 param_1,long param_2,uint param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  
  lVar3 = (**(code **)(param_2 + 0x550))(param_1,param_2,0);
  if (lVar3 != 0) {
    uVar2 = (**(code **)(**(long **)(lVar3 + 0x50) + 0x28))(*(long **)(lVar3 + 0x50),0xd40);
    (**(code **)(**(long **)(lVar3 + 0x50) + 0x40))
              (*(long **)(lVar3 + 0x50),0xd40,uVar2 & 0xffc00000 | param_3 & 0x3fffff);
    return 0;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002c58fa kbusReadBAR0WindowBase_GB10B.cold =====

void kbusReadBAR0WindowBase_GB10B_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002c5910 kbusReadBAR0WindowBase_GB10B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kbusReadBAR0WindowBase_GB10B(undefined8 param_1,long param_2)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  
  lVar3 = (**(code **)(param_2 + 0x550))(param_1,param_2,0);
  if (lVar3 != 0) {
    uVar2 = (**(code **)(**(long **)(lVar3 + 0x50) + 0x28))(*(long **)(lVar3 + 0x50),0xd40);
    return uVar2 & 0x3fffff;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002c5950 kbusValidateBAR0WindowBase_GB10B =====

bool kbusValidateBAR0WindowBase_GB10B(undefined8 param_1,undefined8 param_2,uint param_3)

{
  return param_3 < 0x400000;
}


// ===== 002c5960 kbusFlush_GB10B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbusFlush_GB10B(undefined8 param_1,long param_2,uint param_3)

{
  (**(code **)(param_2 + 0x3d8))(param_1,param_2,param_3 | 1);
  return;
}


// ===== 002c5980 kbusConstructXalApertures_GB10B =====

undefined8 kbusConstructXalApertures_GB10B(long param_1,long param_2)

{
  long lVar1;
  
  *(undefined4 *)(param_2 + 0xad68) = 1;
  lVar1 = portMemAllocNonPaged(0x88);
  *(long *)(param_2 + 0xad60) = lVar1;
  if (lVar1 != 0) {
    portMemSet(lVar1,0,(ulong)*(uint *)(param_2 + 0xad68) * 0x88);
    ioaprtInit(*(undefined8 *)(param_2 + 0xad60),*(undefined8 *)(param_1 + 0x1a18),0x10f000,0x1000);
    return 0;
  }
  nvCheckFailedNoLog(4,"pKernelBus->xalApertures != NULL",
                     "src/kernel/gpu/bus/arch/blackwell/kern_bus_gb10b.c",0x7e);
  return 0x51;
}


// ===== 002c5a20 kbusGetXalAperture_GB10B =====

undefined8 kbusGetXalAperture_GB10B(undefined8 param_1,long param_2,int param_3)

{
  if (param_3 == 0) {
    return *(undefined8 *)(param_2 + 0xad60);
  }
  nvAssertFailedNoLog("baseType == XAL_BASE","src/kernel/gpu/bus/arch/blackwell/kern_bus_gb10b.c",
                      0x8e);
  return 0;
}


// ===== 002c5a50 kbusVerifyBar2_GB202.cold =====

void kbusVerifyBar2_GB202_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002c5a60 kbusVerifyBar2_GB202 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbusVerifyBar2_GB202
                (long param_1,long param_2,undefined1 *param_3,int *param_4,long param_5,
                long param_6)

{
  long lVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  long lVar10;
  ulong uVar11;
  int *piVar12;
  undefined8 uVar13;
  long lVar14;
  char *pcVar15;
  undefined1 auVar16 [16];
  ulong uVar17;
  ulong local_1e8;
  uint local_1d8;
  ulong local_1d0;
  undefined1 local_1b0 [156];
  undefined4 local_114;
  
  if (*(char *)(param_1 + 0x454) != '\0') {
    nvAssertFailedNoLog("pGpu->getProperty(pGpu, PDB_PROP_GPU_COHERENT_CPU_MAPPING) == NV_FALSE",
                        "src/kernel/gpu/bus/arch/blackwell/kern_bus_gb202.c",0x50);
    return 0x40;
  }
  lVar1 = *(long *)(param_1 + 0x1b70);
  if ((((*(char *)(param_1 + 1099) != '\0') &&
       (cVar3 = rmcfg_IsTEGRA_TEGRA_NVDISP_GPUS(), cVar3 == '\0')) ||
      (*(char *)(param_1 + 0x4921) != '\0')) ||
     ((*(char *)(param_1 + 0x44d) != '\0' || (*(char *)(param_2 + 0xad07) != '\0')))) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb202.c",100,"kbusVerifyBar2_GB202",1,
               "NVRM: \n");
  iVar4 = (-(uint)(*(char *)(lVar1 + 0x29b) == '\0') & 0xffffffe0) + 0x31;
  if ((param_3 == (undefined1 *)0x0) || (param_4 == (int *)0x0)) {
    param_3 = local_1b0;
    if (*(char *)(param_1 + 1099) == '\0') {
      memdescCreateExisting(param_3,param_1,0x10,2,1,0);
    }
    else {
      memdescCreateExisting(param_3,param_1,0x10,1,*(undefined4 *)(param_1 + 0x1e34),0);
    }
    local_114 = 0x4c;
    iVar5 = memdescAlloc(param_3);
    if (iVar5 == 0) {
      param_4 = (int *)memdescMapInternal(param_1,param_3,0);
      if (param_4 != (int *)0x0) {
        local_1e8 = memdescGetPhysAddr(param_3,1,0);
        cVar3 = kgmmuGetHwPteApertureFromMemdesc_GM107(*(undefined8 *)(param_1 + 0x1b98),param_3);
        if (cVar3 == '\0') {
          local_1d8 = 0x10;
          bVar2 = true;
          goto LAB_002c5be0;
        }
        nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb202.c",0xa1,
                     "kbusVerifyBar2_GB202",4,
                     "NVRM: Test is not supported. NV_XAL_EP_ZB_BAR0_WINDOW only supports vidmem\n")
        ;
        uVar8 = 0x56;
        goto LAB_002c5d12;
      }
      memdescFree(0);
      memdescDestroy(0);
    }
    else {
      nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb202.c",0x8c,"kbusVerifyBar2_GB202",
                   4,"NVRM: Could not allocate vidmem to test bar2 with\n");
    }
    uVar8 = 0x1a;
  }
  else {
    if (*(ulong *)(param_3 + 0x30) < (ulong)(param_6 + param_5)) {
      nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb202.c",0x71,"kbusVerifyBar2_GB202",
                   4,"NVRM: input offset 0x%llx size 0x%llx exceeds surface size 0x%llx\n",param_5,
                   param_6,*(ulong *)(param_3 + 0x30));
      uVar8 = 0x1f;
      goto LAB_002c606e;
    }
    lVar10 = memdescGetPhysAddr(param_3,1,0);
    cVar3 = kgmmuGetHwPteApertureFromMemdesc_GM107(*(undefined8 *)(param_1 + 0x1b98),param_3);
    if (cVar3 != '\0') {
      nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb202.c",0xa1,"kbusVerifyBar2_GB202",
                   4,"NVRM: Test is not supported. NV_XAL_EP_ZB_BAR0_WINDOW only supports vidmem\n")
      ;
      uVar8 = 0x56;
      goto LAB_002c606e;
    }
    local_1e8 = lVar10 + param_5;
    local_1d8 = (uint)param_6;
    bVar2 = false;
LAB_002c5be0:
    nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb202.c",0xad,"kbusVerifyBar2_GB202",
                 (-(uint)(*(char *)(param_1 + 0x446) == '\0') & 0xfffffffd) + 4,
                 "NVRM: Testing BAR0 window...\n");
    uVar17 = (**(code **)(param_2 + 0x438))(param_1,param_2);
    uVar11 = memdescGetPhysAddr(param_3,1,0);
    (**(code **)(param_2 + 0x418))(param_1,param_2,uVar11 >> 0x10);
    lVar10 = param_1 + 0x3a18;
    iVar5 = ((uint)uVar11 & 0xffff) + 0x700000;
    uVar6 = regRead032(lVar10,0,0,iVar5,0);
    regWrite032(lVar10,0,0,iVar5,0xabcdabcd,0);
    iVar7 = regRead032(lVar10,0,0,iVar5,0);
    if (iVar7 == -0x54325433) {
      uVar8 = kmemsysSendL2InvalidateEvict_IMPL(param_1,lVar1,iVar4);
      if (uVar8 == 0) {
        iVar7 = regRead032(lVar10,0,0,iVar5,0);
        if (iVar7 != -0x54325433) {
          nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb202.c",0xd6,
                       "kbusVerifyBar2_GB202",4,
                       "NVRM: Post-L2 invalidate evict: Address 0x%llx programmed through the bar0 window with value 0x%x did not read back the last write\n"
                       ,uVar11,0xffffffffabcdabcd);
          if (*(char *)(param_1 + 0x446) != '\0') {
            nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb202.c",0xdc,
                         "kbusVerifyBar2_GB202",4,
                         "NVRM: Setup a trigger on write<Bar0+0x1700, 0x40> with a 3 quarters post trigger capture\n"
                        );
            uVar13 = 0xdf;
            pcVar15 = 
            "NVRM: and search for the last bar0 window write not returning the same value in a subsequent read\n"
            ;
LAB_002c6201:
            nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb202.c",uVar13,
                         "kbusVerifyBar2_GB202",4,pcVar15);
          }
          goto LAB_002c5cff;
        }
        nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb202.c",0xe8,
                     "kbusVerifyBar2_GB202",
                     (-(uint)(*(char *)(param_1 + 0x446) == '\0') & 0xfffffffd) + 4,
                     "NVRM: Bar0 window tests successfully\n");
        regWrite032(lVar10,0,0,iVar5,uVar6,0);
        (**(code **)(param_2 + 0x418))(param_1,param_2,uVar17 >> 0x10);
        lVar14 = (long)param_4 - *(long *)(param_2 + 0x7c98);
        nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb202.c",0xf2,
                     "kbusVerifyBar2_GB202",1,
                     "NVRM: MMUTest Writing test data through virtual BAR2 starting at bar2 offset (%p - %p) = %p and of size 0x%x\n"
                     ,param_4,*(long *)(param_2 + 0x7c98),lVar14,local_1d8);
        uVar13 = 4;
        if (*(char *)(param_1 + 0x446) == '\0') {
          uVar13 = 1;
        }
        nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb202.c",0xf8,
                     "kbusVerifyBar2_GB202",uVar13,
                     "NVRM: MMUTest The physical address being targetted is 0x%llx\n",local_1e8);
        if (local_1d8 == 0) {
          osFlushCpuWriteCombineBuffer();
          uVar8 = kmemsysSendL2InvalidateEvict_IMPL(param_1,lVar1,iVar4);
          if (uVar8 != 0) goto LAB_002c63fd;
          local_1d0 = (**(code **)(param_2 + 0x438))(param_1,param_2);
          (**(code **)(param_2 + 0x418))(param_1,param_2,local_1e8 >> 0x10);
          lVar10 = (**(code **)(param_2 + 0x550))(param_1,param_2,0);
          if (lVar10 == 0) {
            uVar11 = kbusVerifyBar2_GB202_cold();
            return uVar11;
          }
          auVar16 = (**(code **)(**(long **)(lVar10 + 0x50) + 0x28))
                              (*(long **)(lVar10 + 0x50),0xd40);
          nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb202.c",0x12f,
                       "kbusVerifyBar2_GB202",1,
                       "NVRM: bar0Window = 0x%llx, testMemoryOffset = 0x%llx, testAddrSpace = %d, _XAL_EP_BAR0_WINDOW = 0x%08x\n"
                       ,local_1d0,local_1e8,0,auVar16);
        }
        else {
          uVar8 = 0;
          do {
            uVar11 = (ulong)uVar8;
            uVar8 = uVar8 + 4;
            *(undefined4 *)((long)param_4 + uVar11) = 0xabcdabcd;
          } while (uVar8 < local_1d8);
          osFlushCpuWriteCombineBuffer();
          uVar8 = kmemsysSendL2InvalidateEvict_IMPL(param_1,lVar1,iVar4);
          uVar9 = 0;
          if (uVar8 != 0) {
LAB_002c63fd:
            uVar13 = 0x107;
            goto LAB_002c60ae;
          }
          do {
            uVar8 = *(uint *)((long)param_4 + (ulong)uVar9);
            uVar17 = (ulong)uVar8;
            if (uVar8 != 0xabcdabcd) {
              uVar11 = lVar14 + (ulong)uVar9;
              uVar13 = 0x11e;
              pcVar15 = "NVRM: MMUTest BAR2 readback VA = 0x%llx returned garbage 0x%x\n";
              goto LAB_002c5ced;
            }
            uVar9 = uVar9 + 4;
          } while (uVar9 < local_1d8);
          local_1d0 = (**(code **)(param_2 + 0x438))(param_1,param_2);
          (**(code **)(param_2 + 0x418))(param_1,param_2,local_1e8 >> 0x10);
          lVar14 = (**(code **)(param_2 + 0x550))(param_1,param_2,0);
          if (lVar14 == 0) {
            uVar11 = kbusVerifyBar2_GB202_cold();
            return uVar11;
          }
          uVar13 = (**(code **)(**(long **)(lVar14 + 0x50) + 0x28))(*(long **)(lVar14 + 0x50),0xd40)
          ;
          nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb202.c",0x12f,
                       "kbusVerifyBar2_GB202",1,
                       "NVRM: bar0Window = 0x%llx, testMemoryOffset = 0x%llx, testAddrSpace = %d, _XAL_EP_BAR0_WINDOW = 0x%08x\n"
                       ,local_1d0,local_1e8,0,uVar13);
          iVar5 = ((uint)local_1e8 & 0xffff) + 0x700000;
          uVar8 = 0;
          do {
            uVar13 = regRead032(lVar10,0,0,iVar5 + uVar8,0);
            if ((int)uVar13 != -0x54325433) {
              nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb202.c",0x13b,
                           "kbusVerifyBar2_GB202",4,
                           "NVRM: MMUTest BAR0 window offset 0x%x returned garbage 0x%x\n",
                           iVar5 + uVar8,uVar13);
              if (*(char *)(param_1 + 0x446) != '\x01') goto LAB_002c5cff;
              pcVar15 = 
              "NVRM: Setup a trigger for write<bar0 + 0x1700, 0x40> and in the waves search the last few bar2 virtual writes mixed with bar0 window reads\n"
              ;
              uVar13 = 0x140;
              goto LAB_002c6201;
            }
            iVar7 = iVar5 + uVar8;
            uVar8 = uVar8 + 4;
            regWrite032(lVar10,0,0,iVar7,0xabcdabdd,0);
          } while (uVar8 < local_1d8);
        }
        (**(code **)(param_2 + 0x418))(param_1,param_2,local_1d0 >> 0x10);
        uVar8 = (**(code **)(param_2 + 0x500))(param_1,param_2,1);
        if ((uVar8 == 0) &&
           (uVar8 = kmemsysSendL2InvalidateEvict_IMPL(param_1,lVar1,iVar4), uVar8 == 0)) {
          uVar8 = 0;
          piVar12 = param_4;
          if (local_1d8 != 0) {
            do {
              if (*piVar12 != -0x54325423) {
                nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb202.c",0x162,
                             "kbusVerifyBar2_GB202",4,
                             "NVRM: MMUTest BAR2 Read of virtual addr 0x%x returned garbage 0x%x\n",
                             uVar8 + ((int)param_4 - (int)*(undefined8 *)(param_2 + 0x7c98)),
                             *piVar12,local_1d8);
                goto LAB_002c5cff;
              }
              uVar8 = uVar8 + 4;
              piVar12 = piVar12 + 1;
            } while (uVar8 < local_1d8);
          }
          if (bVar2) {
            memdescUnmapInternal(param_1,param_3,0);
            memdescFree(param_3);
            memdescDestroy(param_3);
          }
          uVar8 = 0;
          nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb202.c",0x17a,
                       "kbusVerifyBar2_GB202",
                       (-(uint)(*(char *)(param_1 + 0x446) == '\0') & 0xfffffffd) + 4,
                       "NVRM: BAR2 virtual test passes\n");
          goto LAB_002c606e;
        }
      }
      else {
        uVar13 = 0xd0;
LAB_002c60ae:
        nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb202.c",uVar13,
                     "kbusVerifyBar2_GB202",4,"NVRM: L2 evict failed\n");
      }
      if (!bVar2) goto LAB_002c606e;
    }
    else {
      pcVar15 = 
      "NVRM: Pre-L2 invalidate evict: Address 0x%llx programmed through the bar0 window with value 0x%x did not read back the last write.\n"
      ;
      uVar17 = 0xffffffffabcdabcd;
      uVar13 = 0xc0;
LAB_002c5ced:
      nvDbg_Printf("src/kernel/gpu/bus/arch/blackwell/kern_bus_gb202.c",uVar13,
                   "kbusVerifyBar2_GB202",4,pcVar15,uVar11,uVar17);
LAB_002c5cff:
      if (!bVar2) {
        uVar8 = 0x72;
        goto LAB_002c606e;
      }
      uVar8 = 0x72;
    }
LAB_002c5d12:
    memdescUnmapInternal(param_1,param_3,0);
    memdescFree(param_3);
    memdescDestroy(param_3);
  }
LAB_002c606e:
  return (ulong)uVar8;
}


// ===== 002c6670 _kbusCreateC2CPeerMapping =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong _kbusCreateC2CPeerMapping(long param_1,long param_2,long param_3,uint param_4)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  ulong uVar4;
  uint local_c;
  
  uVar3 = *(uint *)(param_3 + 0x7a4);
  piVar1 = (int *)(param_2 + 0xacd0 + (ulong)param_4 * 4);
  *piVar1 = *piVar1 + 1;
  puVar2 = (uint *)(param_2 + 0xac50 + (ulong)uVar3 * 4);
  *puVar2 = *puVar2 | 1 << ((byte)param_4 & 0x1f);
  local_c = param_4;
  uVar4 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800a74,&local_c,4);
  if ((int)uVar4 == 0) {
    return uVar4;
  }
  nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x7b4);
  return uVar4 & 0xffffffff;
}


// ===== 002c66f0 _kbusMemoryIsInFbRegion =====

uint _kbusMemoryIsInFbRegion(long param_1,undefined8 param_2,undefined8 param_3,ulong param_4)

{
  ulong uVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  
  iVar3 = memdescGetAddressSpace(param_2);
  uVar4 = memdescGetPhysAddr(param_2,(iVar3 == 2) + '\x01',param_3);
  param_4 = param_4 & 0xff;
  if ((uint)param_4 < *(uint *)(param_1 + 0xa86c)) {
    uVar2 = *(ulong *)(param_1 + 0xa8d0 + param_4 * 8);
    uVar1 = *(long *)(param_1 + 0xa890 + param_4 * 8) + -1 + uVar2;
    return (uint)CONCAT71((int7)(uVar1 >> 8),uVar4 <= uVar1) &
           (uint)CONCAT71((int7)(uVar4 >> 8),uVar2 <= uVar4);
  }
  nvAssertFailedNoLog("region < pKernelBus->coherentCpuMapping.nrMapping",
                      "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x516);
  return 0;
}


// ===== 002c67a0 _kbusGetC2CP2PPeerId.part.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _kbusGetC2CP2PPeerId_part_0(long param_1,long param_2,long param_3,int *param_4)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  
  iVar1 = (**(code **)(param_2 + 0x288))();
  if (iVar1 == -1) {
    if (param_1 == param_3) {
      if (*(char *)(param_2 + 0xacf4) == '\0') {
        iVar3 = 1;
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(param_2 + 0xacf8);
        iVar3 = 1 << ((byte)iVar1 & 0x1f);
      }
    }
    else {
      iVar1 = *param_4;
      if ((iVar1 == -1) && (iVar1 = kbusGetUnusedPeerId_GM107(param_1,param_2), iVar1 == -1)) {
        nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x764,"_kbusGetC2CP2PPeerId",
                     4,"NVRM: GPU%d: peerID not available for C2C P2P\n",
                     *(undefined4 *)(param_1 + 0x7a4));
        return 0xffff;
      }
      iVar3 = 1 << ((byte)iVar1 & 0x1f);
    }
    uVar2 = kbusReserveP2PPeerIds_GM200(param_1,param_2,iVar3);
    if ((int)uVar2 != 0) {
      return uVar2;
    }
    iVar3 = *param_4;
  }
  else {
    iVar3 = *param_4;
  }
  if (iVar3 == -1) {
    nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x779,"_kbusGetC2CP2PPeerId",1,
                 "NVRM: - P2P: Using Default RM mapping for P2P.\n");
    *param_4 = iVar1;
  }
  else if (iVar3 != iVar1) {
    nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x780,"_kbusGetC2CP2PPeerId",4,
                 "NVRM: - P2P: Incorrect PeerId: %d passed down to RM\n");
    return 0x1f;
  }
  return 0;
}


// ===== 002c6920 _kbusCreateStaticBar1IOMMUMapping.isra.0 =====

int _kbusCreateStaticBar1IOMMUMapping_isra_0(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  uint local_24;
  ulong local_20;
  
  iVar2 = vgpuGetCallingContextGfid(param_2,&local_24);
  if (iVar2 == 0) {
    lVar1 = *(long *)(param_3 + 0x6f8 + (ulong)local_24 * 0x100);
    if (lVar1 == 0) {
      nvAssertFailedNoLog("pPeerDmaMemDesc != NULL",
                          "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x625);
      iVar2 = 0x40;
    }
    else {
      iVar2 = memdescMapIommu(lVar1,*(undefined4 *)(param_1 + 0x868));
      if (iVar2 == 0) {
        memdescGetPtePhysAddrsForGpu(lVar1,param_1,1,0,0,1,&local_20);
        if ((local_20 & 0x1fffffff) != 0) {
          nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x632,
                       "_kbusCreateStaticBar1IOMMUMapping",4,
                       "NVRM: The peer DMA address 0x%llx is not aligned at 0x%llx\n",local_20,
                       0x20000000);
          memdescUnmapIommu(lVar1,*(undefined4 *)(param_1 + 0x868));
          iVar2 = 0x1e;
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar2,"memdescMapIommu(pPeerDmaMemDesc, pSrcGpu->busInfo.iovaspaceId)",
                   "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x628);
      }
    }
    return iVar2;
  }
  nvAssertOkFailedNoLog
            (iVar2,"vgpuGetCallingContextGfid(pPeerGpu, &peerGpuGfid)",
             "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x621);
  return iVar2;
}


// ===== 002c6a90 _kbusRemoveStaticBar1IOMMUMapping.isra.0 =====

void _kbusRemoveStaticBar1IOMMUMapping_isra_0(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  uint local_1c;
  
  iVar2 = vgpuGetCallingContextGfid(param_2,&local_1c);
  if (iVar2 == 0) {
    lVar1 = *(long *)(param_3 + 0x6f8 + (ulong)local_1c * 0x100);
    if (lVar1 == 0) {
      nvAssertFailedNoLog("pPeerKernelBus->bar1[peerGfid].staticBar1.pDmaMemDesc != NULL",
                          "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x5ed);
    }
    else {
      memdescUnmapIommu(lVar1,*(undefined4 *)(param_1 + 0x868));
    }
    return;
  }
  nvCheckFailedNoLog(4,"vgpuGetCallingContextGfid(pPeerGpu, &peerGfid) == NV_OK",
                     "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x5ea);
  return;
}


// ===== 002c6b30 kbusTeardownMailbox_GH100 =====

void kbusTeardownMailbox_GH100(long param_1)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0xf60,0);
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0xf60,uVar1 & 0xfffff1ff,0);
  return;
}


// ===== 002c6b90 kbusGetP2PWriteMailboxAddressSize_GH100 =====

undefined8 kbusGetP2PWriteMailboxAddressSize_GH100(void)

{
  return 0x16;
}


// ===== 002c6b9a kbusWriteBAR0WindowBase_GH100.cold =====

void kbusWriteBAR0WindowBase_GH100_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002c6bb0 kbusWriteBAR0WindowBase_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbusWriteBAR0WindowBase_GH100(undefined8 param_1,long param_2,uint param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  
  lVar3 = (**(code **)(param_2 + 0x550))(param_1,param_2,0);
  if (lVar3 != 0) {
    uVar2 = (**(code **)(**(long **)(lVar3 + 0x50) + 0x28))(*(long **)(lVar3 + 0x50),0xd40);
    (**(code **)(**(long **)(lVar3 + 0x50) + 0x40))
              (*(long **)(lVar3 + 0x50),0xd40,uVar2 & 0xffc00000 | param_3 & 0x3fffff);
    return 0;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002c6c1a kbusReadBAR0WindowBase_GH100.cold =====

void kbusReadBAR0WindowBase_GH100_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002c6c30 kbusReadBAR0WindowBase_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kbusReadBAR0WindowBase_GH100(undefined8 param_1,long param_2)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  
  lVar3 = (**(code **)(param_2 + 0x550))(param_1,param_2,0);
  if (lVar3 != 0) {
    uVar2 = (**(code **)(**(long **)(lVar3 + 0x50) + 0x28))(*(long **)(lVar3 + 0x50),0xd40);
    return uVar2 & 0x3fffff;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002c6c70 kbusValidateBAR0WindowBase_GH100 =====

bool kbusValidateBAR0WindowBase_GH100(undefined8 param_1,undefined8 param_2,uint param_3)

{
  return param_3 < 0x400000;
}


// ===== 002c6c80 kbusSetBAR0WindowVidOffset_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbusSetBAR0WindowVidOffset_GH100(long param_1,long param_2,ulong param_3)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  if ((*(char *)(param_1 + 0x454) == '\0') || (*(char *)(param_1 + 0x4915) == '\0')) {
    if ((short)param_3 != 0) {
      nvAssertFailedNoLog("(vidOffset & 0xffff)==0",
                          "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0xbf);
    }
    cVar1 = (**(code **)(param_2 + 0x428))(param_1,param_2,param_3 >> 0x10 & 0xffffffff);
    if (cVar1 == '\0') {
      nvAssertFailedNoLog("kbusValidateBAR0WindowBase_HAL(pGpu, pKernelBus, vidOffset >> NV_XAL_EP_ZB_BAR0_WINDOW_BASE_SHIFT)"
                          ,"src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0xc0);
    }
    uVar3 = *(ulong *)(param_2 + 0x5e8);
    if (uVar3 == 0) {
      uVar2 = (**(code **)(param_2 + 0x420))(param_1,param_2);
      uVar3 = (ulong)uVar2 << 0x10;
      *(ulong *)(param_2 + 0x5e8) = uVar3;
    }
    if (uVar3 != param_3) {
      nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0xcf,
                   "kbusSetBAR0WindowVidOffset_GH100",1,
                   "NVRM: mapping BAR0_WINDOW to VID:%x\'%08x\n",param_3 >> 0x20,param_3);
      (**(code **)(param_2 + 0x418))(param_1,param_2,param_3 >> 0x10 & 0xffffffff);
      *(ulong *)(param_2 + 0x5e8) = param_3;
    }
    uVar4 = 0;
  }
  else {
    nvAssertFailedNoLog("kbusSetBAR0WindowVidOffset_HAL call in coherent path\n",
                        "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0xbb);
    uVar4 = 0x40;
  }
  return uVar4;
}


// ===== 002c6df0 kbusGetBAR0WindowVidOffset_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbusGetBAR0WindowVidOffset_GH100(undefined8 param_1,long param_2)

{
  uint uVar1;
  
  if (*(long *)(param_2 + 0x5e8) == 0) {
    uVar1 = (**(code **)(param_2 + 0x420))();
    *(ulong *)(param_2 + 0x5e8) = (ulong)uVar1 << 0x10;
    return;
  }
  return;
}


// ===== 002c6e31 kbusVerifyBar2_GH100.cold =====

void kbusVerifyBar2_GH100_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002c6e40 kbusVerifyBar2_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbusVerifyBar2_GH100
                (long param_1,long param_2,undefined1 *param_3,int *param_4,long param_5,
                long param_6)

{
  long lVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  long lVar10;
  ulong uVar11;
  undefined8 uVar12;
  int *piVar13;
  long lVar14;
  char *pcVar15;
  undefined1 auVar16 [16];
  ulong uVar17;
  ulong local_1e8;
  uint local_1d8;
  ulong local_1d0;
  undefined1 local_1b0 [156];
  undefined4 local_114;
  
  if (*(char *)(param_1 + 0x454) != '\0') {
    nvAssertFailedNoLog("pGpu->getProperty(pGpu, PDB_PROP_GPU_COHERENT_CPU_MAPPING) == NV_FALSE",
                        "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x11f);
    return 0x40;
  }
  lVar1 = *(long *)(param_1 + 0x1b70);
  if ((((*(char *)(param_1 + 1099) != '\0') &&
       (cVar3 = rmcfg_IsTEGRA_TEGRA_NVDISP_GPUS(), cVar3 == '\0')) ||
      (*(char *)(param_1 + 0x4921) != '\0')) ||
     ((*(char *)(param_1 + 0x44d) != '\0' || (*(char *)(param_2 + 0xad07) != '\0')))) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x133,"kbusVerifyBar2_GH100",1,
               "NVRM: \n");
  iVar4 = (-(uint)(*(char *)(lVar1 + 0x29b) == '\0') & 0xffffffe0) + 0x31;
  if ((param_3 == (undefined1 *)0x0) || (param_4 == (int *)0x0)) {
    param_3 = local_1b0;
    if (*(char *)(param_1 + 1099) == '\0') {
      memdescCreateExisting(param_3,param_1,0x10,2,1,0);
    }
    else {
      memdescCreateExisting(param_3,param_1,0x10,1,*(undefined4 *)(param_1 + 0x1e34),0);
    }
    local_114 = 0x80;
    iVar5 = memdescAlloc(param_3);
    if (iVar5 != 0) {
      nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x15b,"kbusVerifyBar2_GH100",4,
                   "NVRM: Could not allocate vidmem to test bar2 with\n");
      uVar8 = 0xffff;
      goto LAB_002c744e;
    }
    param_4 = (int *)memdescMapInternal(param_1,param_3,0);
    if (param_4 == (int *)0x0) {
      memdescFree(0);
      memdescDestroy(0);
      uVar8 = 0x1a;
      goto LAB_002c744e;
    }
    local_1e8 = memdescGetPhysAddr(param_3,1,0);
    cVar3 = kgmmuGetHwPteApertureFromMemdesc_GM107(*(undefined8 *)(param_1 + 0x1b98),param_3);
    if (cVar3 == '\0') {
      local_1d8 = 0x10;
      bVar2 = true;
      goto LAB_002c6fc0;
    }
    nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x170,"kbusVerifyBar2_GH100",4,
                 "NVRM: Test is not supported. NV_XAL_EP_ZB_BAR0_WINDOW only supports vidmem\n");
    uVar8 = 0x56;
  }
  else {
    if (*(ulong *)(param_3 + 0x30) < (ulong)(param_6 + param_5)) {
      nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x140,"kbusVerifyBar2_GH100",4,
                   "NVRM: input offset 0x%llx size 0x%llx exceeds surface size 0x%llx\n",param_5,
                   param_6,*(ulong *)(param_3 + 0x30));
      uVar8 = 0x1f;
      goto LAB_002c744e;
    }
    lVar10 = memdescGetPhysAddr(param_3,1,0);
    cVar3 = kgmmuGetHwPteApertureFromMemdesc_GM107(*(undefined8 *)(param_1 + 0x1b98),param_3);
    if (cVar3 != '\0') {
      nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x170,"kbusVerifyBar2_GH100",4,
                   "NVRM: Test is not supported. NV_XAL_EP_ZB_BAR0_WINDOW only supports vidmem\n");
      uVar8 = 0x56;
      goto LAB_002c744e;
    }
    local_1e8 = lVar10 + param_5;
    local_1d8 = (uint)param_6;
    bVar2 = false;
LAB_002c6fc0:
    uVar12 = 4;
    if (*(char *)(param_1 + 0x446) == '\0') {
      uVar12 = 1;
    }
    nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x17a,"kbusVerifyBar2_GH100",
                 uVar12,"NVRM: Testing BAR0 window...\n");
    uVar17 = (**(code **)(param_2 + 0x438))(param_1,param_2);
    uVar11 = memdescGetPhysAddr(param_3,1,0);
    (**(code **)(param_2 + 0x418))(param_1,param_2,uVar11 >> 0x10);
    lVar10 = param_1 + 0x3a18;
    iVar5 = ((uint)uVar11 & 0xffff) + 0x700000;
    uVar6 = regRead032(lVar10,0,0,iVar5,0);
    regWrite032(lVar10,0,0,iVar5,0xabcdabcd,0);
    iVar7 = regRead032(lVar10,0,0,iVar5,0);
    if (iVar7 == -0x54325433) {
      uVar8 = kmemsysSendL2InvalidateEvict_IMPL(param_1,lVar1,iVar4);
      if (uVar8 == 0) {
        iVar7 = regRead032(lVar10,0,0,iVar5,0);
        if (iVar7 != -0x54325433) {
          nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x1a2,
                       "kbusVerifyBar2_GH100",4,
                       "NVRM: Post-L2 invalidate evict: Address 0x%llx programmed through the bar0 window with value 0x%x did not read back the last write\n"
                       ,uVar11,0xffffffffabcdabcd);
          if (*(char *)(param_1 + 0x446) != '\0') {
            nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x1a8,
                         "kbusVerifyBar2_GH100",4,
                         "NVRM: Setup a trigger on write<Bar0+0x1700, 0x40> with a 3 quarters post trigger capture\n"
                        );
            uVar12 = 0x1ab;
            pcVar15 = 
            "NVRM: and search for the last bar0 window write not returning the same value in a subsequent read\n"
            ;
LAB_002c75e1:
            nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",uVar12,
                         "kbusVerifyBar2_GH100",4,pcVar15);
          }
          goto LAB_002c70e3;
        }
        uVar12 = 4;
        if (*(char *)(param_1 + 0x446) == '\0') {
          uVar12 = 1;
        }
        nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x1b4,"kbusVerifyBar2_GH100",
                     uVar12,"NVRM: Bar0 window tests successfully\n");
        regWrite032(lVar10,0,0,iVar5,uVar6,0);
        (**(code **)(param_2 + 0x418))(param_1,param_2,uVar17 >> 0x10);
        lVar14 = (long)param_4 - *(long *)(param_2 + 0x7c98);
        nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x1be,"kbusVerifyBar2_GH100",
                     1,
                     "NVRM: MMUTest Writing test data through virtual BAR2 starting at bar2 offset (%p - %p) = %p and of size 0x%x\n"
                     ,param_4,*(long *)(param_2 + 0x7c98),lVar14,local_1d8);
        uVar12 = 4;
        if (*(char *)(param_1 + 0x446) == '\0') {
          uVar12 = 1;
        }
        nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x1c4,"kbusVerifyBar2_GH100",
                     uVar12,"NVRM: MMUTest The physical address being targetted is 0x%llx\n",
                     local_1e8);
        if (local_1d8 == 0) {
          osFlushCpuWriteCombineBuffer();
          uVar8 = kmemsysSendL2InvalidateEvict_IMPL(param_1,lVar1,iVar4);
          if (uVar8 != 0) goto LAB_002c77e5;
          local_1d0 = (**(code **)(param_2 + 0x438))(param_1,param_2);
          (**(code **)(param_2 + 0x418))(param_1,param_2,local_1e8 >> 0x10);
          lVar10 = (**(code **)(param_2 + 0x550))(param_1,param_2,0);
          if (lVar10 == 0) {
            uVar11 = kbusVerifyBar2_GH100_cold();
            return uVar11;
          }
          auVar16 = (**(code **)(**(long **)(lVar10 + 0x50) + 0x28))
                              (*(long **)(lVar10 + 0x50),0xd40);
          nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x1fb,
                       "kbusVerifyBar2_GH100",1,
                       "NVRM: bar0Window = 0x%llx, testMemoryOffset = 0x%llx, testAddrSpace = %d, _XAL_EP_ZB_BAR0_WINDOW = 0x%08x\n"
                       ,local_1d0,local_1e8,0,auVar16);
        }
        else {
          uVar8 = 0;
          do {
            uVar11 = (ulong)uVar8;
            uVar8 = uVar8 + 4;
            *(undefined4 *)((long)param_4 + uVar11) = 0xabcdabcd;
          } while (uVar8 < local_1d8);
          osFlushCpuWriteCombineBuffer();
          uVar8 = kmemsysSendL2InvalidateEvict_IMPL(param_1,lVar1,iVar4);
          uVar9 = 0;
          if (uVar8 != 0) {
LAB_002c77e5:
            uVar12 = 0x1d3;
            goto LAB_002c748e;
          }
          do {
            uVar8 = *(uint *)((long)param_4 + (ulong)uVar9);
            uVar17 = (ulong)uVar8;
            if (uVar8 != 0xabcdabcd) {
              uVar11 = lVar14 + (ulong)uVar9;
              uVar12 = 0x1ea;
              pcVar15 = "NVRM: MMUTest BAR2 readback VA = 0x%llx returned garbage 0x%x\n";
              goto LAB_002c70d1;
            }
            uVar9 = uVar9 + 4;
          } while (uVar9 < local_1d8);
          local_1d0 = (**(code **)(param_2 + 0x438))(param_1,param_2);
          (**(code **)(param_2 + 0x418))(param_1,param_2,local_1e8 >> 0x10);
          lVar14 = (**(code **)(param_2 + 0x550))(param_1,param_2,0);
          if (lVar14 == 0) {
            uVar11 = kbusVerifyBar2_GH100_cold();
            return uVar11;
          }
          uVar12 = (**(code **)(**(long **)(lVar14 + 0x50) + 0x28))(*(long **)(lVar14 + 0x50),0xd40)
          ;
          nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x1fb,
                       "kbusVerifyBar2_GH100",1,
                       "NVRM: bar0Window = 0x%llx, testMemoryOffset = 0x%llx, testAddrSpace = %d, _XAL_EP_ZB_BAR0_WINDOW = 0x%08x\n"
                       ,local_1d0,local_1e8,0,uVar12);
          iVar5 = ((uint)local_1e8 & 0xffff) + 0x700000;
          uVar8 = 0;
          do {
            uVar12 = regRead032(lVar10,0,0,iVar5 + uVar8,0);
            if ((int)uVar12 != -0x54325433) {
              nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x207,
                           "kbusVerifyBar2_GH100",4,
                           "NVRM: MMUTest BAR0 window offset 0x%x returned garbage 0x%x\n",
                           iVar5 + uVar8,uVar12);
              if (*(char *)(param_1 + 0x446) != '\x01') goto LAB_002c70e3;
              pcVar15 = 
              "NVRM: Setup a trigger for write<bar0 + 0x1700, 0x40> and in the waves search the last few bar2 virtual writes mixed with bar0 window reads\n"
              ;
              uVar12 = 0x20c;
              goto LAB_002c75e1;
            }
            iVar7 = iVar5 + uVar8;
            uVar8 = uVar8 + 4;
            regWrite032(lVar10,0,0,iVar7,0xabcdabdd,0);
          } while (uVar8 < local_1d8);
        }
        (**(code **)(param_2 + 0x418))(param_1,param_2,local_1d0 >> 0x10);
        uVar8 = (**(code **)(param_2 + 0x500))(param_1,param_2,1);
        if ((uVar8 == 0) &&
           (uVar8 = kmemsysSendL2InvalidateEvict_IMPL(param_1,lVar1,iVar4), uVar8 == 0)) {
          uVar8 = 0;
          piVar13 = param_4;
          if (local_1d8 != 0) {
            do {
              if (*piVar13 != -0x54325423) {
                nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x22e,
                             "kbusVerifyBar2_GH100",4,
                             "NVRM: MMUTest BAR2 Read of virtual addr 0x%x returned garbage 0x%x\n",
                             uVar8 + ((int)param_4 - (int)*(undefined8 *)(param_2 + 0x7c98)),
                             *piVar13,local_1d8);
                goto LAB_002c70e3;
              }
              uVar8 = uVar8 + 4;
              piVar13 = piVar13 + 1;
            } while (uVar8 < local_1d8);
          }
          if (bVar2) {
            memdescUnmapInternal(param_1,param_3,0);
            memdescFree(param_3);
            memdescDestroy(param_3);
          }
          uVar8 = 0;
          uVar12 = 4;
          if (*(char *)(param_1 + 0x446) == '\0') {
            uVar12 = 1;
          }
          nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x245,
                       "kbusVerifyBar2_GH100",uVar12,"NVRM: BAR2 virtual test passes\n");
          goto LAB_002c744e;
        }
      }
      else {
        uVar12 = 0x19c;
LAB_002c748e:
        nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",uVar12,"kbusVerifyBar2_GH100"
                     ,4,"NVRM: L2 evict failed\n");
      }
      if (!bVar2) goto LAB_002c744e;
    }
    else {
      pcVar15 = 
      "NVRM: Pre-L2 invalidate evict: Address 0x%llx programmed through the bar0 window with value 0x%x did not read back the last write.\n"
      ;
      uVar17 = 0xffffffffabcdabcd;
      uVar12 = 0x18c;
LAB_002c70d1:
      nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",uVar12,"kbusVerifyBar2_GH100",4
                   ,pcVar15,uVar11,uVar17);
LAB_002c70e3:
      if (!bVar2) {
        uVar8 = 0x72;
        goto LAB_002c744e;
      }
      uVar8 = 0x72;
    }
  }
  memdescUnmapInternal(param_1,param_3,0);
  memdescFree(param_3);
  memdescDestroy(param_3);
LAB_002c744e:
  return (ulong)uVar8;
}


// ===== 002c7a60 kbusTeardownBar2CpuAperture_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbusTeardownBar2CpuAperture_GH100(long param_1,long param_2,int param_3)

{
  uint uVar1;
  
  if (((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(param_1 + 0x4913) == '\0')) ||
     (param_3 != 0)) {
    return 0;
  }
  if ((*(long *)(param_2 + 0x7c78) != 0) && (*(long *)(param_2 + 0x7c70) != 0)) {
    memmgrMemDescEndTransfer_IMPL(*(undefined8 *)(param_1 + 0x1b78));
    *(undefined8 *)(param_2 + 0x7c78) = 0;
  }
  (**(code **)(param_2 + 0x230))(param_1,param_2);
  kbusFlushVirtualBar2_VBAR2(param_1,param_2,0,0);
  if (*(long *)(param_2 + 0x7c98) != 0) {
    osUnmapPciMemoryKernelOld(param_1);
    *(undefined8 *)(param_2 + 0x7c98) = 0;
  }
  if (*(char *)(param_1 + 0x44d) != '\0') {
    return 0;
  }
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0xf70,0);
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0xf70,uVar1 & 0xfffffdff,0);
  regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0xf70,0);
  return 0;
}


// ===== 002c7b90 kbusAllocP2PMailboxBar1_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusAllocP2PMailboxBar1_GH100(long param_1,long param_2,ulong param_3,ulong param_4)

{
  long *plVar1;
  byte bVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  ushort local_3a;
  
  local_3a = 0;
  lVar4 = gpumgrGetParentGPU();
  lVar5 = gpumgrGetParentGPU(param_1);
  if (param_1 != lVar5) {
    local_3a = 0x80;
    *(undefined8 *)(param_2 + 0xabc0) = *(undefined8 *)(*(long *)(&DAT_00001b90 + lVar4) + 0xabc0);
  }
  *(undefined8 *)(param_2 + 0xabc8) = 0x80000;
  bVar2 = kbusGetP2PWriteMailboxAddressSize_STATIC_DISPATCH(param_1);
  if ((0x10000L << (bVar2 & 0x3f)) - 1U <= param_4) {
    bVar2 = kbusGetP2PWriteMailboxAddressSize_STATIC_DISPATCH(param_1);
    param_4 = (0x10000L << (bVar2 & 0x3f)) - 1;
  }
  plVar1 = *(long **)(param_2 + 0x630 + (param_3 & 0xffffffff) * 0x100);
  uVar6 = (ulong)local_3a;
  iVar3 = (**(code **)(*plVar1 + 0x38))
                    (plVar1,*(undefined8 *)(param_2 + 0xabc8),0x10000,0,param_4,0,uVar6,
                     param_2 + 0xabc0);
  if (iVar3 == 0) {
    lVar5 = *(long *)(param_2 + 0xabc0);
    if (*(long *)(*(long *)(&DAT_00001b90 + lVar4) + 0xabc0) != lVar5) {
      nvAssertFailedNoLog("GPU_GET_KERNEL_BUS(pParentGpu)->p2pPcie.writeMailboxBar1Addr == pKernelBus->p2pPcie.writeMailboxBar1Addr"
                          ,"src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x2b9,uVar6);
      lVar5 = *(long *)(param_2 + 0xabc0);
    }
    nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",699,
                 "kbusAllocP2PMailboxBar1_GH100",1,
                 "NVRM: [GPU%u] P2P write mailboxes allocated at BAR1 addr = 0x%llx\n",
                 *(undefined4 *)(param_1 + 0x7a4),lVar5);
  }
  else {
    nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x2b3,
                 "kbusAllocP2PMailboxBar1_GH100",4,
                 "NVRM: cannot allocate vaspace for P2P write mailboxes (0x%x)\n",iVar3);
    *(undefined8 *)(param_2 + 0xabc0) = 0xffffffffffffffff;
    *(undefined8 *)(param_2 + 0xabc8) = 0;
  }
  return iVar3;
}


// ===== 002c7d50 kbusGetP2PMailboxAttributes_GH100 =====

void kbusGetP2PMailboxAttributes_GH100
               (long param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4,
               undefined4 *param_5)

{
  long lVar1;
  byte bVar2;
  
  lVar1 = *(long *)(param_1 + 7000);
  if (param_3 == (undefined4 *)0x0) {
    if (param_4 == (undefined4 *)0x0) {
      if (param_5 == (undefined4 *)0x0) {
        return;
      }
      *param_5 = 0;
      if ((*(char *)(lVar1 + 0x3a9) != '\0') && (*(char *)(lVar1 + 0x3aa) != '\0')) {
        return;
      }
      goto LAB_002c7d9e;
    }
    *param_4 = 0;
    if (param_5 == (undefined4 *)0x0) {
      if ((*(char *)(lVar1 + 0x3a9) != '\0') && (*(char *)(lVar1 + 0x3aa) != '\0')) {
        return;
      }
      *param_4 = 0x10000;
      return;
    }
    *param_5 = 0;
    if ((*(char *)(lVar1 + 0x3a9) != '\0') && (*(char *)(lVar1 + 0x3aa) != '\0')) {
      return;
    }
  }
  else {
    *param_3 = 0;
    if (param_4 == (undefined4 *)0x0) {
      if (param_5 == (undefined4 *)0x0) {
        if ((*(char *)(lVar1 + 0x3a9) == '\0') || (*(char *)(lVar1 + 0x3aa) == '\0')) {
          *param_3 = 0x80000;
          return;
        }
      }
      else {
        *param_5 = 0;
        if ((*(char *)(lVar1 + 0x3a9) == '\0') || (*(char *)(lVar1 + 0x3aa) == '\0')) {
          *param_3 = 0x80000;
          goto LAB_002c7d9e;
        }
      }
      return;
    }
    *param_4 = 0;
    if (param_5 == (undefined4 *)0x0) {
      if ((*(char *)(lVar1 + 0x3a9) != '\0') && (*(char *)(lVar1 + 0x3aa) != '\0')) {
        return;
      }
      *param_3 = 0x80000;
      *param_4 = 0x10000;
      return;
    }
    *param_5 = 0;
    if ((*(char *)(lVar1 + 0x3a9) != '\0') && (*(char *)(lVar1 + 0x3aa) != '\0')) {
      return;
    }
    *param_3 = 0x80000;
  }
  *param_4 = 0x10000;
LAB_002c7d9e:
  bVar2 = kbusGetP2PWriteMailboxAddressSize_STATIC_DISPATCH();
  *param_5 = (int)((ulong)(0x10000L << (bVar2 & 0x3f)) >> 0x10);
  return;
}


// ===== 002c7ef0 kbusSetupP2PDomainAccess_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbusSetupP2PDomainAccess_GH100(long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  
  lVar1 = (**(code **)(param_2 + 0x550))(param_1,param_2,1);
  kbusSetupPeerBarAccess_IMPL
            (param_1,param_3,(ulong)*(uint *)(lVar1 + 0x7c) + *(long *)(param_1 + 0x848),0x2000,
             param_4);
  return;
}


// ===== 002c7f40 kbusFlushPcieForBar0Doorbell_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbusFlushPcieForBar0Doorbell_GH100(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x500))(param_1,param_2,1);
  return;
}


// ===== 002c7f60 kbusCreateP2PMapping_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kbusCreateP2PMapping_GH100
          (undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6,uint param_7)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = param_7 & 0xf;
  if (uVar1 == 5) {
    uVar2 = (**(code **)(param_2 + 0x2e8))(param_1,param_2,param_3);
    return uVar2;
  }
  if (uVar1 - 3 < 2) {
    uVar2 = kbusCreateP2PMappingForNvlink_GP100(param_1,param_2,param_3);
    return uVar2;
  }
  if (uVar1 == 2) {
    uVar2 = (**(code **)(param_2 + 0x340))(param_1,param_2,param_3,param_4,param_7);
    return uVar2;
  }
  if (uVar1 == 1) {
    uVar2 = (**(code **)(param_2 + 0x2b8))(param_1,param_2,param_3);
    return uVar2;
  }
  nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x34e,"kbusCreateP2PMapping_GH100",
               4,"NVRM: P2P type %d is not supported\n",uVar1);
  return 0x56;
}


// ===== 002c8010 kbusRemoveP2PMapping_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kbusRemoveP2PMapping_GH100
          (undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6,uint param_7)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = param_7 & 0xf;
  if (uVar1 == 5) {
    uVar2 = (**(code **)(param_2 + 0x2f0))(param_1,param_2,param_3);
    return uVar2;
  }
  if (uVar1 - 3 < 2) {
    uVar2 = kbusRemoveP2PMappingForNvlink_GP100(param_1,param_2,param_3);
    return uVar2;
  }
  if (uVar1 == 2) {
    uVar2 = (**(code **)(param_2 + 0x348))(param_1,param_2,param_3,param_4,param_7);
    return uVar2;
  }
  if (uVar1 == 1) {
    uVar2 = (**(code **)(param_2 + 0x2c0))(param_1,param_2,param_3);
    return uVar2;
  }
  nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x381,"kbusRemoveP2PMapping_GH100",
               4,"NVRM: P2P type %d is not supported\n",uVar1);
  return 0x56;
}


// ===== 002c80c0 kbusGetPeerId_GH100 =====

ulong kbusGetPeerId_GH100(long param_1,long param_2,long param_3)

{
  ulong uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_2 + 0xac50 + (ulong)*(uint *)(param_3 + 0x7a4) * 4);
  if (uVar2 != 0) {
    uVar2 = -uVar2 & uVar2;
    return (ulong)((uint)((uVar2 & 0xaaaaaaaa) != 0) | (uint)(0xffff < uVar2) << 4 |
                   (uint)((uVar2 & 0xff00ff00) != 0) << 3 | (uint)((uVar2 & 0xf0f0f0f0) != 0) << 2 |
                  (uint)((uVar2 & 0xcccccccc) != 0) * 2);
  }
  nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x39d,"kbusGetPeerId_GH100",1,
               "NVRM: C2C P2P not set up between GPU%u and GPU%u, checking for Nvlink...\n",
               *(undefined4 *)(param_1 + 0x7a4),(ulong)*(uint *)(param_3 + 0x7a4));
  uVar1 = kbusGetPeerId_GP100(param_1,param_2,param_3);
  return uVar1;
}


// ===== 002c8190 kbusIsPeerIdValid_GH100 =====

undefined8 kbusIsPeerIdValid_GH100(long param_1,long param_2,uint param_3)

{
  undefined8 uVar1;
  
  if (7 < param_3) {
    nvAssertFailedNoLog("peerId < P2P_MAX_NUM_PEERS",
                        "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x3b8);
    return 0x2c;
  }
  if ((*(uint *)(param_2 + 0xac50 + (ulong)*(uint *)(param_1 + 0x7a4) * 4) &
      1 << ((byte)param_3 & 0x1f)) != 0) {
    return 0;
  }
  uVar1 = kbusIsPeerIdValid_GP100();
  return uVar1;
}


// ===== 002c81f0 kbusCarveoutWprs_GH100 =====

void kbusCarveoutWprs_GH100(long param_1,undefined8 param_2,long *param_3)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  
  param_1 = param_1 + 0x3a18;
  uVar1 = regRead032(param_1,0,0,0x1fa81c,0);
  uVar2 = regRead032(param_1,0,0,0x1fa820,0);
  lVar4 = (ulong)(uVar1 >> 4) << 0xc;
  lVar3 = (ulong)(uVar2 >> 4) * 0x1000;
  if ((lVar4 == lVar3) || ((ulong)(uVar2 >> 4) == 0)) {
    lVar4 = 1;
    lVar3 = 0;
  }
  else {
    lVar3 = lVar3 + -1;
  }
  *param_3 = lVar4;
  param_3[1] = lVar3;
  uVar1 = regRead032(param_1,0,0,0x1fa824,0);
  uVar2 = regRead032(param_1,0,0,&DAT_001fa828,0);
  lVar4 = (ulong)(uVar1 >> 4) << 0xc;
  lVar3 = (ulong)(uVar2 >> 4) * 0x1000;
  if ((lVar4 == lVar3) || ((ulong)(uVar2 >> 4) == 0)) {
    lVar4 = 1;
    lVar3 = 0;
  }
  else {
    lVar3 = lVar3 + -1;
  }
  param_3[2] = lVar4;
  param_3[3] = lVar3;
  return;
}


// ===== 002c82e0 kbusCreateCoherentCpuMapping_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusCreateCoherentCpuMapping_GH100(long param_1,long param_2,long param_3,char param_4)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  ulong uVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  ulong *puVar9;
  ulong *puVar10;
  ulong uVar11;
  uint uVar12;
  uint uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  undefined8 local_e8;
  undefined1 local_e0 [8];
  undefined4 local_d8 [4];
  ulong local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  ulong local_a8 [8];
  ulong local_68 [7];
  
  lVar8 = *(long *)(param_1 + 0x1b78);
  lVar2 = *(long *)(param_1 + 0x1b70);
  local_e8 = 0;
  if ((*(char *)(param_1 + 0x4915) == '\0') ||
     (*(char *)(*(long *)(param_1 + 7000) + 0x3a8) == '\0')) {
    nvAssertFailedNoLog("gpuIsSelfHosted(pGpu) && pKernelBif->getProperty(pKernelBif, PDB_PROP_KBIF_IS_C2C_LINK_UP)"
                        ,"src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x40b);
    return 0x40;
  }
  lVar7 = (**(code **)(param_2 + 0x4e8))();
  if (lVar7 != 0) {
    nvAssertFailedNoLog("kbusGetBar1VASpace_HAL(pGpu, pKernelBus) == NULL",
                        "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x40e);
    return 0x40;
  }
  iVar5 = listCount_IMPL(param_2 + 0x7c58);
  if (iVar5 != 0) {
    nvAssertFailedNoLog("listCount(&pKernelBus->virtualBar2[GPU_GFID_PF].usedMapList) == 0",
                        "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x410);
    return 0x40;
  }
  lVar7 = *(long *)(lVar8 + 0x830);
  iVar5 = osNumaMemblockSize(local_e0);
  if (iVar5 != 0) {
    nvAssertOkFailedNoLog
              (iVar5,"osNumaMemblockSize(&memblockSize)",
               "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x415);
    return iVar5;
  }
  uVar3 = *(undefined8 *)(lVar8 + 0x860);
  local_d8[0] = 0;
  *(long *)(param_2 + 0xa890) = param_3;
  lVar7 = lVar7 * 0x100000;
  *(undefined8 *)(param_2 + 0xa8d0) = uVar3;
  *(undefined4 *)(param_2 + 0xa86c) = 1;
  if (lVar7 == param_3) {
    uVar13 = 1;
  }
  else {
    local_68[0] = param_3 + *(long *)(lVar8 + 0x860);
    local_68[1] = *(long *)(lVar8 + 0x860) + -1 + lVar7;
    if (*(char *)(param_1 + 0x908) == '\0') {
      uVar16 = 1;
      (**(code **)(param_2 + 0x508))(param_1,param_2,&local_c8);
      nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x42c,
                   "kbusCreateCoherentCpuMapping_GH100",1,
                   "NVRM: wpr1 0x%llx->0x%llx, wpr2 0x%llx->0x%llx\n",local_c8,local_c0,local_b8,
                   local_b0);
      puVar9 = &local_c8;
      do {
        uVar11 = *puVar9;
        uVar14 = puVar9[1];
        if ((uVar11 <= uVar14) && ((int)uVar16 != 0)) {
          puVar10 = local_68;
          do {
            if ((*puVar10 <= uVar11) && (uVar14 <= puVar10[1])) {
              local_68[uVar16 * 2 + 1] = puVar10[1];
              uVar15 = uVar11 - 1;
              if (uVar11 == *puVar10) {
                *puVar10 = 1;
                uVar15 = 0;
              }
              puVar10[1] = uVar15;
              uVar11 = uVar14 + 1;
              if (uVar14 == local_68[uVar16 * 2 + 1]) {
                local_68[uVar16 * 2 + 1] = 0;
                uVar11 = 1;
              }
              local_68[uVar16 * 2] = uVar11;
              uVar16 = (ulong)((int)uVar16 + 1);
              break;
            }
            puVar10 = puVar10 + 2;
          } while (puVar10 != local_68 + uVar16 * 2);
        }
        puVar9 = puVar9 + 2;
      } while (puVar9 != local_a8);
      uVar11 = 0;
      uVar14 = 0;
      if ((int)uVar16 != 0) {
        do {
          while( true ) {
            uVar6 = (uint)uVar16;
            puVar9 = local_68 + uVar14 * 2;
            uVar13 = (uint)uVar11;
            if (local_68[uVar14 * 2 + 1] < *puVar9) break;
            if (uVar6 <= uVar13 + 1) {
              if (3 < uVar6) goto LAB_002c8a4a;
              uVar13 = *(uint *)(param_2 + 0xa86c);
              goto LAB_002c866f;
            }
            puVar10 = local_68 + uVar14 * 2 + 2;
            do {
              if ((*puVar10 <= puVar10[1]) && (uVar11 = *puVar9, *puVar10 < uVar11)) {
                uVar15 = local_68[uVar14 * 2 + 1];
                uVar4 = puVar10[1];
                *puVar9 = *puVar10;
                local_68[uVar14 * 2 + 1] = uVar4;
                *puVar10 = uVar11;
                puVar10[1] = uVar15;
              }
              puVar10 = puVar10 + 2;
            } while (local_68 + (((uVar6 - 2) - uVar13) + uVar14) * 2 + 4 != puVar10);
            uVar14 = (ulong)(uVar13 + 1);
            uVar11 = uVar14;
          }
          uVar6 = uVar6 - 1;
          uVar16 = (ulong)uVar6;
          uVar15 = local_68[uVar16 * 2 + 1];
          *puVar9 = local_68[uVar16 * 2];
          local_68[uVar14 * 2 + 1] = uVar15;
          local_68[uVar16 * 2] = 1;
          local_68[uVar16 * 2 + 1] = 0;
        } while (uVar13 < uVar6);
        if (uVar6 < 4) {
          uVar13 = *(uint *)(param_2 + 0xa86c);
          if (uVar6 == 0) goto LAB_002c86b2;
        }
        else {
LAB_002c8a4a:
          nvAssertFailedNoLog("numReservedRegions <= COHERENT_CPU_MAPPING_TOTAL_REGIONS - 1",
                              "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x434);
          uVar13 = *(uint *)(param_2 + 0xa86c);
        }
        goto LAB_002c866f;
      }
      uVar13 = *(uint *)(param_2 + 0xa86c);
    }
    else {
      uVar13 = 1;
      uVar6 = 1;
LAB_002c866f:
      puVar9 = local_68;
      uVar12 = 0;
      do {
        uVar16 = puVar9[1];
        uVar11 = *puVar9;
        uVar1 = uVar13 + uVar12;
        *(ulong *)(param_2 + 0xa8d0 + (ulong)uVar1 * 8) = uVar11;
        lVar8 = (uVar16 + 1) - uVar11;
        if (uVar16 < uVar11) {
          lVar8 = 0;
        }
        uVar12 = uVar12 + 1;
        puVar9 = puVar9 + 2;
        *(long *)(param_2 + 0xa890 + (ulong)uVar1 * 8) = lVar8;
      } while (uVar12 < uVar6);
      uVar13 = uVar13 + uVar6;
      *(uint *)(param_2 + 0xa86c) = uVar13;
    }
LAB_002c86b2:
    if (uVar13 == 0) goto LAB_002c86ba;
  }
  lVar8 = *(long *)(lVar2 + 0x478);
  uVar16 = 0;
  do {
    local_a8[uVar16] = *(long *)(param_2 + 0xa8d0 + uVar16 * 8) + lVar8;
    local_a8[uVar16 + 4] = *(ulong *)(param_2 + 0xa890 + uVar16 * 8);
    uVar16 = uVar16 + 1;
  } while (uVar13 != uVar16);
  if (*(char *)(lVar2 + 0x2a1) == '\0') {
    if (((uVar13 != 1) && (local_d8[1] = 0, uVar13 != 2)) && (local_d8[2] = 0, uVar13 == 4)) {
      local_d8[3] = 0;
    }
  }
  else if (*(char *)(param_1 + 0x4912) == '\0') {
    if (uVar13 != 1) goto LAB_002c8860;
  }
  else if (uVar13 != 1) {
    lVar8 = *(long *)(lVar2 + 0x4a0);
    puVar9 = local_a8;
    do {
      puVar9[1] = puVar9[1] + (lVar8 - local_a8[1]);
      puVar9 = puVar9 + 1;
    } while (local_a8 + (ulong)(uVar13 - 2) + 1 != puVar9);
LAB_002c8860:
    local_d8[1] = 2;
    if ((uVar13 != 2) && (local_d8[2] = 2, uVar13 == 4)) {
      local_d8[3] = 2;
    }
  }
  uVar16 = 0;
  do {
    uVar11 = local_a8[uVar16 + 4];
    uVar14 = local_a8[uVar16];
    iVar5 = osMapPciMemoryKernel64(param_1,uVar14,uVar11,3,&local_e8,local_d8[uVar16]);
    if (iVar5 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x478)
      ;
      return 0xffff;
    }
    *(undefined8 *)(param_2 + 0xa870 + uVar16 * 8) = local_e8;
    nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x47b,
                 "kbusCreateCoherentCpuMapping_GH100",1,
                 "NVRM: coherent link mapping. i: %d base: 0x%llx size: 0x%llx \n",
                 uVar16 & 0xffffffff,uVar14,uVar11);
    if (param_4 != '\0') {
      nvAssertFailedNoLog("bFlush == NV_FALSE","src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",
                          0x47e);
      return 0x56;
    }
    *(undefined8 *)(param_2 + 0xa8b0 + uVar16 * 8) = 0;
    uVar16 = uVar16 + 1;
  } while ((uint)uVar16 < *(uint *)(param_2 + 0xa86c));
LAB_002c86ba:
  *(undefined1 *)(param_2 + 0xa868) = 1;
  nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x486,
               "kbusCreateCoherentCpuMapping_GH100",1,"NVRM: Enabling CPU->C2C->FBMEM path\n");
  return 0;
}


// ===== 002c8a80 kbusVerifyCoherentLink_GH100 =====

int kbusVerifyCoherentLink_GH100(long param_1)

{
  int *piVar1;
  long lVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  int iVar9;
  undefined1 local_1b0 [156];
  undefined4 local_114;
  
  if (*(char *)(param_1 + 1099) == '\0') {
    lVar2 = *(long *)(param_1 + 0x1b70);
    memdescCreateExisting(local_1b0,param_1,0x100,2,0,0);
    local_114 = 0x80;
    iVar3 = memdescAlloc(local_1b0);
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x4b1,
                   "kbusVerifyCoherentLink_GH100",4,
                   "NVRM: Could not allocate vidmem to test coherent link with\n");
      memdescFree(0);
      memdescDestroy(0);
      return 0x51;
    }
    piVar4 = (int *)memdescMapInternal(param_1,local_1b0,0);
    if (piVar4 == (int *)0x0) {
      iVar3 = 0x1a;
      memdescFree(0);
      memdescDestroy(0);
    }
    else {
      if (*(char *)(param_1 + 0x446) == '\0') {
        uVar7 = memdescGetPhysAddr(local_1b0,0,0);
        uVar8 = 1;
      }
      else {
        uVar7 = memdescGetPhysAddr(local_1b0,0,0);
        uVar8 = 4;
      }
      nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x4c0,
                   "kbusVerifyCoherentLink_GH100",uVar8,
                   "NVRM: Coherent link test buffer PA: 0x%llx\n",uVar7);
      piVar1 = piVar4 + 0x40;
      piVar5 = piVar4;
      do {
        *piVar5 = 0x12345678;
        piVar6 = piVar5 + 2;
        piVar5[1] = 0x12345678;
        piVar5 = piVar6;
      } while (piVar6 != piVar1);
      osFlushGpuCoherentCpuCacheRange(*(undefined8 *)(param_1 + 0x4e0),piVar4,0x100);
      iVar9 = 0;
      if ((*(char *)(param_1 + 0x908) == '\0') &&
         (iVar3 = kmemsysSendL2InvalidateEvict_IMPL
                            (param_1,lVar2,
                             (-(uint)(*(char *)(lVar2 + 0x29b) == '\0') & 0xffffffe0) + 0x31),
         iVar3 != 0)) {
        nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x4da,
                     "kbusVerifyCoherentLink_GH100",4,"NVRM: L2 evict failed\n");
        memdescUnmapInternal(param_1,local_1b0,0);
        memdescFree(local_1b0);
        memdescDestroy(local_1b0);
      }
      else {
        do {
          if (*piVar4 != 0x12345678) {
            iVar9 = 0xffff;
            nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x4e5,
                         "kbusVerifyCoherentLink_GH100",4,
                         "NVRM: Coherent Link test readback VA = 0x%llx returned garbage 0x%x\n",
                         piVar4,*piVar4);
          }
          piVar4 = piVar4 + 1;
        } while (piVar4 != piVar1);
        memdescUnmapInternal(param_1,local_1b0,0);
        memdescFree(local_1b0);
        memdescDestroy(local_1b0);
        if (iVar9 == 0) {
          uVar7 = 4;
          if (*(char *)(param_1 + 0x446) == '\0') {
            uVar7 = 1;
          }
          nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x4f8,
                       "kbusVerifyCoherentLink_GH100",uVar7,"NVRM: Coherent link test passes\n");
          return 0;
        }
        iVar3 = 0xffff;
      }
    }
  }
  else {
    uVar7 = 4;
    if (*(char *)(param_1 + 0x446) == '\0') {
      uVar7 = 1;
    }
    nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x4a7,
                 "kbusVerifyCoherentLink_GH100",uVar7,"NVRM: Skipping Coherent link test\n");
    iVar3 = 0;
  }
  return iVar3;
}


// ===== 002c8e10 kbusMapCoherentCpuMapping_GH100 =====

undefined8
kbusMapCoherentCpuMapping_GH100
          (long param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
          undefined4 param_6,long *param_7)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  byte bVar5;
  
  iVar2 = memdescGetAddressSpace(param_3);
  lVar3 = memdescGetPhysAddr(param_3,(iVar2 == 2) + '\x01',param_4);
  cVar1 = osNumaOnliningEnabled(*(undefined8 *)(param_1 + 0x4e0));
  bVar5 = 0;
  if (cVar1 != '\0') {
    cVar1 = _kbusMemoryIsInFbRegion(param_2,param_3,param_4,0);
    bVar5 = 1;
    if (cVar1 != '\0') {
      uVar4 = osMapSystemMemory(param_3,param_4,param_5,1,param_6,param_7);
      return uVar4;
    }
  }
  cVar1 = memdescGetContiguity(param_3,0);
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("memdescGetContiguity(pMemDesc, AT_CPU)",
                        "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x549);
    uVar4 = 0x56;
  }
  else {
    for (; (uint)bVar5 < *(uint *)(param_2 + 0xa86c); bVar5 = bVar5 + 1) {
      cVar1 = _kbusMemoryIsInFbRegion(param_2,param_3,param_4);
      if (cVar1 != '\0') {
        param_2 = param_2 + (ulong)bVar5 * 8;
        if (*(long *)(param_2 + 0xa870) == 0) {
          nvAssertFailedNoLog("pKernelBus->coherentCpuMapping.pCpuMapping[i] != NvP64_NULL",
                              "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x54e);
          return 0x40;
        }
        *(long *)(param_2 + 0xa8b0) = *(long *)(param_2 + 0xa8b0) + 1;
        *param_7 = (*(long *)(param_2 + 0xa870) - *(long *)(param_2 + 0xa8d0)) + lVar3;
        return 0;
      }
    }
    nvAssertFailedNoLog("No mappings found","src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x55b)
    ;
    uVar4 = 0x1f;
  }
  return uVar4;
}


// ===== 002c8fd0 kbusUnmapCoherentCpuMapping_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbusUnmapCoherentCpuMapping_GH100
               (long param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5)

{
  uint uVar1;
  long lVar2;
  char cVar3;
  undefined8 uVar4;
  char *pcVar5;
  byte bVar6;
  uint uVar7;
  
  cVar3 = osNumaOnliningEnabled(*(undefined8 *)(param_1 + 0x4e0));
  bVar6 = 0;
  if (cVar3 != '\0') {
    cVar3 = _kbusMemoryIsInFbRegion(param_2,param_3,0,0);
    bVar6 = 1;
    if (cVar3 != '\0') {
      (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x500))
                (param_1,*(long *)(&DAT_00001b90 + param_1),1);
      osUnmapSystemMemory(param_3,1,param_4,param_5);
      goto LAB_002c906c;
    }
  }
  cVar3 = memdescGetContiguity(param_3,0);
  if (cVar3 == '\0') {
    uVar4 = 0x584;
    pcVar5 = "memdescGetContiguity(pMemDesc, AT_CPU)";
LAB_002c9133:
    nvAssertFailedNoLog(pcVar5,"src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",uVar4);
    return;
  }
  while( true ) {
    uVar1 = *(uint *)(param_2 + 0xa86c);
    uVar7 = (uint)bVar6;
    if (uVar1 <= uVar7) break;
    cVar3 = _kbusMemoryIsInFbRegion(param_2,param_3,0,uVar7);
    if (cVar3 != '\0') {
      lVar2 = *(long *)(param_2 + 0x10 + ((ulong)uVar7 + 0x1514) * 8);
      if (lVar2 == 0) {
        uVar4 = 0x589;
        pcVar5 = "pKernelBus->coherentCpuMapping.refcnt[i] != 0";
        goto LAB_002c9133;
      }
      *(long *)(param_2 + 0x10 + ((ulong)uVar7 + 0x1514) * 8) = lVar2 + -1;
      uVar1 = *(uint *)(param_2 + 0xa86c);
      break;
    }
    bVar6 = bVar6 + 1;
  }
  if (uVar7 == uVar1) {
    nvAssertFailedNoLog("No mappings found","src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x591)
    ;
  }
LAB_002c906c:
  (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x500))
            (param_1,*(long *)(&DAT_00001b90 + param_1),1);
  return;
}


// ===== 002c9160 kbusIsPcieBar1P2PMappingSupported_GH100 =====

ulong kbusIsPcieBar1P2PMappingSupported_GH100(long param_1,long param_2,long param_3,long param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  
  if ((*(int *)(*(long *)(param_1 + 7000) + 0x3c8) == 1) ||
     (uVar4 = (ulong)*(byte *)(param_2 + 0x55a), *(byte *)(param_2 + 0x55a) != 0)) {
    if (param_1 != param_3) {
      uVar1 = *(uint *)(param_1 + 0x7a4);
      uVar2 = *(uint *)(param_3 + 0x7a4);
      uVar4 = kbusIsStaticBar1Enabled_IMPL();
      if ((char)uVar4 != '\0') {
        uVar4 = kbusIsStaticBar1Enabled_IMPL(param_3,param_4);
        if (((char)uVar4 != '\0') && (uVar4 = 0, *(int *)(param_2 + 0xaa40 + (ulong)uVar2 * 4) == 0)
           ) {
          iVar3 = *(int *)(param_4 + 0xaa40 + (ulong)uVar1 * 4);
          return (ulong)CONCAT31((int3)((uint)iVar3 >> 8),iVar3 == 0);
        }
      }
      return uVar4;
    }
    uVar4 = 0;
  }
  return uVar4;
}


// ===== 002c9220 kbusGetBar1P2PDmaInfo_GH100 =====

int kbusGetBar1P2PDmaInfo_GH100
              (undefined8 param_1,undefined8 param_2,long param_3,undefined8 *param_4,
              undefined8 *param_5)

{
  long lVar1;
  int iVar2;
  uint local_2c;
  
  if ((param_4 != (undefined8 *)0x0) && (param_5 != (undefined8 *)0x0)) {
    *param_4 = 0xffffffffffffffff;
    *param_5 = 0;
    iVar2 = vgpuGetCallingContextGfid(param_2,&local_2c);
    if (iVar2 == 0) {
      lVar1 = *(long *)(param_3 + 0x6f8 + (ulong)local_2c * 0x100);
      if (lVar1 == 0) {
        nvAssertFailedNoLog("pPeerDmaMemDesc != NULL",
                            "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x68d);
        return 0x56;
      }
      memdescGetPtePhysAddrsForGpu(lVar1,param_1,1,0,0,1,param_4);
      *param_5 = *(undefined8 *)(lVar1 + 0x30);
    }
    else {
      nvAssertOkFailedNoLog
                (iVar2,"vgpuGetCallingContextGfid(pPeerGpu, &peerGfid)",
                 "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x68a);
    }
    return iVar2;
  }
  nvAssertFailedNoLog("(pDmaAddress != NULL) && (pDmaSize != NULL)",
                      "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x683);
  return 0x1f;
}


// ===== 002c9360 kbusHasPcieBar1P2PMapping_GH100 =====

undefined4 kbusHasPcieBar1P2PMapping_GH100(long param_1,long param_2,long param_3,long param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (*(int *)(param_2 + 0xabd0 + (ulong)*(uint *)(param_3 + 0x7a4) * 4) != 0) {
    iVar1 = *(int *)(param_4 + 0xabd0 + (ulong)*(uint *)(param_1 + 0x7a4) * 4);
    uVar2 = CONCAT31((int3)((uint)iVar1 >> 8),iVar1 != 0);
  }
  return uVar2;
}


// ===== 002c9390 kbusCreateP2PMappingForBar1P2P_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusCreateP2PMappingForBar1P2P_GH100(long param_1,long param_2,long param_3,long param_4)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char cVar5;
  int iVar6;
  ulong uVar7;
  
  if ((*(char *)(param_1 + 0x908) != '\0') || (*(char *)(param_3 + 0x908) != '\0')) {
    return 0x56;
  }
  uVar2 = *(uint *)(param_1 + 0x7a4);
  uVar7 = (ulong)*(uint *)(param_3 + 0x7a4);
  cVar5 = (**(code **)(param_2 + 0x358))();
  if (cVar5 == '\0') {
    return 0x56;
  }
  iVar6 = *(int *)(param_2 + (uVar7 + 0x2af4) * 4);
  if ((iVar6 == 0) && (*(int *)(param_4 + 0xabd0 + (ulong)uVar2 * 4) == 0)) {
    uVar3 = *(undefined4 *)(param_1 + 0x7a4);
    uVar4 = *(undefined4 *)(param_3 + 0x7a4);
    iVar6 = _kbusCreateStaticBar1IOMMUMapping_isra_0(param_1,param_3,param_4);
    if (iVar6 == 0) {
      iVar6 = _kbusCreateStaticBar1IOMMUMapping_isra_0(param_3,param_1,param_2);
      if (iVar6 == 0) {
        iVar6 = *(int *)(param_2 + (uVar7 + 0x2af4) * 4);
        goto LAB_002c941a;
      }
      nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x661,
                   "_kbusCreateStaticBar1IOMMUMappingForGpuPair",4,
                   "NVRM: IOMMU mapping failed from GPU%u to GPU%u\n",uVar4,uVar3);
      _kbusRemoveStaticBar1IOMMUMapping_isra_0(param_1,param_3,param_4);
    }
    else {
      nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x658,
                   "_kbusCreateStaticBar1IOMMUMappingForGpuPair",4,
                   "NVRM: IOMMU mapping failed from GPU%u to GPU%u\n",uVar3,uVar4);
    }
    nvAssertOkFailedNoLog
              (iVar6,
               "_kbusCreateStaticBar1IOMMUMappingForGpuPair(pGpu0, pKernelBus0, pGpu1, pKernelBus1)"
               ,"src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x6d7);
  }
  else {
LAB_002c941a:
    *(int *)(param_2 + 0xabd0 + uVar7 * 4) = iVar6 + 1;
    piVar1 = (int *)(param_4 + 0xabd0 + (ulong)uVar2 * 4);
    *piVar1 = *piVar1 + 1;
    nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x6de,
                 "kbusCreateP2PMappingForBar1P2P_GH100",1,
                 "NVRM: added PCIe BAR1 P2P mapping between GPU%u and GPU%u\n",uVar2,uVar7);
    iVar6 = 0;
  }
  return iVar6;
}


// ===== 002c95c0 kbusRemoveP2PMappingForBar1P2P_GH100 =====

undefined1  [16]
kbusRemoveP2PMappingForBar1P2P_GH100(long param_1,long param_2,long param_3,long param_4)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  undefined1 auVar5 [16];
  int iVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  ulong uStack_40;
  
  if ((*(char *)(param_1 + 0x908) != '\0') || (*(char *)(param_3 + 0x908) != '\0')) {
    auVar8._8_8_ = param_3;
    auVar8._0_8_ = 0x56;
    return auVar8;
  }
  uVar3 = *(uint *)(param_3 + 0x7a4);
  lVar1 = param_2 + (ulong)uVar3 * 4;
  if (*(int *)(lVar1 + 0xabd0) == 0) {
    auVar7._8_8_ = param_3;
    auVar7._0_8_ = 0x40;
    return auVar7;
  }
  uVar4 = *(uint *)(param_1 + 0x7a4);
  lVar2 = param_4 + (ulong)uVar4 * 4;
  if (*(int *)(lVar2 + 0xabd0) != 0) {
    *(int *)(lVar1 + 0xabd0) = *(int *)(lVar1 + 0xabd0) + -1;
    iVar6 = *(int *)(lVar2 + 0xabd0) + -1;
    *(int *)(lVar2 + 0xabd0) = iVar6;
    if (iVar6 == 0 && *(int *)(lVar1 + 0xabd0) == 0) {
      _kbusRemoveStaticBar1IOMMUMapping_isra_0(param_1,param_3,param_4);
      uStack_40 = 0x2c96e0;
      _kbusRemoveStaticBar1IOMMUMapping_isra_0(param_3,param_1,param_2);
    }
    nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x713,
                 "kbusRemoveP2PMappingForBar1P2P_GH100",1,
                 "NVRM: removed PCIe BAR1 P2P mapping between GPU%u and GPU%u\n",uVar4,uVar3);
    auVar5._8_8_ = 0;
    auVar5._0_8_ = uStack_40;
    return auVar5 << 0x40;
  }
  auVar9._8_8_ = param_3;
  auVar9._0_8_ = 0x40;
  return auVar9;
}


// ===== 002c96f0 kbusCreateP2PMappingForC2C_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusCreateP2PMappingForC2C_GH100
              (long param_1,long param_2,long param_3,long param_4,uint *param_5,uint *param_6)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  char cVar6;
  int iVar7;
  uint local_40;
  uint local_3c [3];
  
  if ((*(char *)(param_1 + 0x908) != '\0') || (*(char *)(param_3 + 0x908) != '\0')) {
    return 0x56;
  }
  if ((((param_5 == (uint *)0x0) || (param_6 == (uint *)0x0)) ||
      (local_40 = *param_5, local_40 - 8 < 0xfffffff7)) ||
     (local_3c[0] = *param_6, local_3c[0] - 8 < 0xfffffff7)) {
    return 0x1f;
  }
  uVar2 = *(uint *)(param_1 + 0x7a4);
  uVar3 = *(uint *)(param_3 + 0x7a4);
  if ((*(long *)(param_1 + 7000) == 0) ||
     (cVar6 = (**(code **)(*(long *)(param_1 + 7000) + 0x330))(), cVar6 == '\0')) {
    local_40 = 0xffffffff;
  }
  else {
    iVar7 = _kbusGetC2CP2PPeerId_part_0(param_1,param_2,param_3,&local_40);
    if (iVar7 != 0) {
      return iVar7;
    }
  }
  lVar5 = *(long *)(param_3 + 7000);
  if ((lVar5 != 0) && (cVar6 = (**(code **)(lVar5 + 0x330))(param_3,lVar5,param_1), cVar6 != '\0'))
  {
    iVar7 = _kbusGetC2CP2PPeerId_part_0(param_3,param_4,param_1,local_3c);
    if (iVar7 != 0) {
      return iVar7;
    }
    if ((local_40 != 0xffffffff) && (local_3c[0] != 0xffffffff)) {
      *param_5 = local_40;
      *param_6 = local_3c[0];
      uVar4 = *param_5;
      if (((*(uint *)(param_2 + 0xac50 + (ulong)uVar3 * 4) & 1 << ((byte)uVar4 & 0x1f)) != 0) &&
         ((*(uint *)(param_4 + 0xac50 + (ulong)uVar2 * 4) & 1 << ((byte)local_3c[0] & 0x1f)) != 0))
      {
        piVar1 = (int *)(param_2 + 0xacd0 + (ulong)uVar4 * 4);
        *piVar1 = *piVar1 + 1;
        piVar1 = (int *)(param_4 + 0xacd0 + (ulong)*param_6 * 4);
        *piVar1 = *piVar1 + 1;
        nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x813,
                     "kbusCreateP2PMappingForC2C_GH100",1,
                     "NVRM: - P2P: Peer mapping is already in use for gpu instances %x and %x with peer id\'s %d and %d. Increasing the mapping refcounts for the peer IDs to %d and %d respectively.\n"
                     ,uVar2,uVar3,*param_5,(ulong)*param_6,
                     *(undefined4 *)(param_2 + 0xacd0 + (ulong)*param_5 * 4),
                     *(undefined4 *)(param_4 + 0xacd0 + (ulong)*param_6 * 4));
        return 0;
      }
      iVar7 = _kbusCreateC2CPeerMapping(param_1,param_2,param_3,uVar4);
      if (iVar7 != 0) {
        nvAssertOkFailedNoLog
                  (iVar7,"_kbusCreateC2CPeerMapping(pGpu0, pKernelBus0, pGpu1, *peer0)",
                   "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x823);
        return iVar7;
      }
      iVar7 = _kbusCreateC2CPeerMapping(param_3,param_4,param_1,*param_6);
      if (iVar7 == 0) {
        nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x826,
                     "kbusCreateP2PMappingForC2C_GH100",1,
                     "NVRM: added C2C P2P mapping between GPU%u (peer %u) and GPU%u (peer %u)\n",
                     uVar2,*param_5,uVar3,*param_6);
        return 0;
      }
      nvAssertOkFailedNoLog
                (iVar7,"_kbusCreateC2CPeerMapping(pGpu1, pKernelBus1, pGpu0, *peer1)",
                 "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x824);
      return iVar7;
    }
  }
  nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x7fc,
               "kbusCreateP2PMappingForC2C_GH100",4,
               "NVRM: Failed to create C2C P2P mapping between GPU%u and GPU%u\n",uVar2,uVar3);
  return 0x3f;
}


// ===== 002c9a30 kbusRemoveP2PMappingForC2C_GH100 =====

undefined8
kbusRemoveP2PMappingForC2C_GH100
          (long param_1,long param_2,long param_3,long param_4,byte param_5,byte param_6)

{
  if (((*(uint *)(param_2 + 0xac50 + (ulong)*(uint *)(param_3 + 0x7a4) * 4) & 1 << (param_5 & 0x1f))
       == 0) ||
     ((*(uint *)(param_4 + 0xac50 + (ulong)*(uint *)(param_1 + 0x7a4) * 4) & 1 << (param_6 & 0x1f))
      == 0)) {
    return 0x40;
  }
  if ((*(char *)(param_1 + 0x908) == '\0') && (*(char *)(param_3 + 0x908) == '\0')) {
    return 0;
  }
  nvAssertOkFailedNoLog
            (0x56,"_kbusRemoveC2CPeerMapping(pGpu0, pKernelBus0, pGpu1, peer0)",
             "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x86c);
  return 0x56;
}


// ===== 002c9acb kbusWriteP2PWmbTag_GH100.cold =====

void kbusWriteP2PWmbTag_GH100_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002c9ae0 kbusWriteP2PWmbTag_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbusWriteP2PWmbTag_GH100(undefined8 param_1,long param_2,int param_3,ulong param_4)

{
  code *pcVar1;
  long lVar2;
  int iVar3;
  
  iVar3 = (param_3 + 8) * 0x40;
  lVar2 = (**(code **)(param_2 + 0x550))(param_1,param_2,1);
  if (lVar2 != 0) {
    (**(code **)(**(long **)(lVar2 + 0x50) + 0x28))(*(long **)(lVar2 + 0x50),iVar3);
    (**(code **)(**(long **)(lVar2 + 0x50) + 0x40))
              (*(long **)(lVar2 + 0x50),iVar3,param_4 & 0xffffffff);
    (**(code **)(**(long **)(lVar2 + 0x50) + 0x40))
              (*(long **)(lVar2 + 0x50),iVar3 + 4,param_4 >> 0x20);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002c9b70 kbusDetermineFlaRangeAndAllocate_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbusDetermineFlaRangeAndAllocate_GH100
                (long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  ulong uVar2;
  
  if ((*(char *)(g_pSys + 0x6a) != '\0') || (*(char *)(param_1 + 0x4cc) == '\x01')) {
    cVar1 = gpuFabricProbeIsSupported();
    if (cVar1 == '\0') {
      uVar2 = kbusDetermineFlaRangeAndAllocate_GA100(param_1,param_2,param_3,param_4);
      return uVar2;
    }
  }
  uVar2 = (**(code **)(param_2 + 0x370))(param_1,param_2,0,0x10000000000000);
  if ((int)uVar2 == 0) {
    return uVar2;
  }
  nvAssertOkFailedNoLog
            (uVar2 & 0xffffffff,"kbusAllocateFlaVaspace_HAL(pGpu, pKernelBus, base, size)",
             "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x8a0);
  return uVar2 & 0xffffffff;
}


// ===== 002c9c10 kbusAllocateFlaVaspace_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusAllocateFlaVaspace_GH100(long param_1,long param_2,long param_3,long param_4)

{
  uint uVar1;
  undefined8 uVar2;
  long *plVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 local_48;
  undefined8 local_40;
  
  local_48 = 0;
  local_40 = 0;
  uVar2 = *(undefined8 *)(g_pSys + 0x230);
  uVar9 = *(undefined8 *)(param_1 + 0x1b98);
  lVar7 = rmapiGetInterface(4);
  lVar8 = g_pSys;
  if (param_4 == 0) {
    nvAssertFailedNoLog("size != 0","src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x8c0);
    return 0x1f;
  }
  if (*(char *)(param_2 + 0xa830) != '\0') {
    nvAssertFailedNoLog("!pKernelBus->flaInfo.bFlaAllocated",
                        "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x8c1);
    return 0x1f;
  }
  *(long *)(param_2 + 0xa838) = param_3;
  *(long *)(param_2 + 0xa840) = param_4;
  if (((*(char *)(lVar8 + 0x6a) != '\0') || (*(char *)(param_1 + 0x4cc) == '\x01')) &&
     (cVar4 = gpuFabricProbeIsSupported(param_1), cVar4 == '\0')) {
    iVar6 = kbusAllocateFlaVaspace_GA100(param_1,param_2,param_3,param_4);
    return iVar6;
  }
  iVar6 = (**(code **)(param_2 + 0x380))(param_1,param_2,param_3,param_4);
  if (iVar6 != 0) {
    nvAssertOkFailedNoLog
              (iVar6,"kbusAllocateLegacyFlaVaspace_HAL(pGpu, pKernelBus, base, size)",
               "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x8cf);
    return iVar6;
  }
  uVar5 = gpumgrGetGpuMask(param_1);
  iVar6 = vmmCreateVaspace_IMPL
                    (uVar2,0xfc,*(undefined4 *)(param_1 + 0x7ac),uVar5,param_3,
                     param_3 + -1 + param_4,0,0,0,0,param_1 + 0x4a18);
  if (iVar6 == 0) {
    iVar6 = (**(code **)(**(long **)(param_1 + 0x4a18) + 0xd0))
                      (*(long **)(param_1 + 0x4a18),param_1);
    if (iVar6 == 0) {
      iVar6 = (**(code **)(param_2 + 0x3b0))(param_1,param_2,0);
      if (iVar6 == 0) {
        lVar8 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x4a18),__nvoc_class_def_FABRIC_VASPACE
                                  );
        iVar6 = kgmmuInstBlkInit_IMPL
                          (uVar9,*(undefined8 *)(param_2 + 0xa828),*(undefined8 *)(lVar8 + 0x98),
                           0xffffffff,&local_48);
        if (iVar6 == 0) {
          if ((*(char *)(param_1 + 0x491d) == '\0') && (*(char *)(param_1 + 0x908) == '\0')) {
            iVar6 = (**(code **)(param_2 + 0x3d0))(param_1,param_2,0);
LAB_002c9de5:
            if (iVar6 != 0) {
              nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x916,
                           "kbusAllocateFlaVaspace_GH100",4,
                           "NVRM: failed binding instblk for FLA, status=0x%x\n",iVar6);
              goto LAB_002ca079;
            }
          }
          else {
            cVar4 = (**(code **)(param_1 + 0x318))(param_1);
            if (cVar4 != '\0') {
              iVar6 = (**(code **)(param_2 + 0x3d0))
                                (param_1,param_2,**(undefined4 **)(param_1 + 0x3af8));
              goto LAB_002c9de5;
            }
            nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x90b,
                         "kbusAllocateFlaVaspace_GH100",1,
                         "NVRM: Skipping binding FLA, because no P2P GFID is validated yet\n");
          }
          if (*(char *)(param_1 + 0x4cc) == '\x01') {
LAB_002c9e42:
            *(undefined1 *)(param_2 + 0xa830) = 1;
            return 0;
          }
          lVar8 = (**(code **)(param_1 + 0x340))(param_1,0);
          uVar1 = *(uint *)(param_1 + 0x7a4);
          uVar9 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x4a18),
                                     __nvoc_class_def_FABRIC_VASPACE);
          iVar6 = fabricvaspaceInitUCRange_IMPL(uVar9,param_1,(ulong)uVar1 * lVar8,lVar8);
          if (iVar6 == 0) goto LAB_002c9e42;
          nvAssertOkFailedNoLog
                    (iVar6,
                     "fabricvaspaceInitUCRange( dynamicCast(pGpu->pFabricVAS, FABRIC_VASPACE), pGpu, base, size)"
                     ,"src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x921);
        }
        else {
          nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x8f9,
                       "kbusAllocateFlaVaspace_GH100",4,
                       "NVRM: failed instantiating instblk for FLA, status=0x%x\n",iVar6);
        }
LAB_002ca079:
        (**(code **)(param_2 + 0x3b8))(param_1,param_2);
      }
      else {
        nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x8ea,
                     "kbusAllocateFlaVaspace_GH100",4,
                     "NVRM: failed constructing instblk for FLA, status=0x%x\n",iVar6);
      }
      plVar3 = *(long **)(param_1 + 0x4a18);
      if (plVar3 == (long *)0x0) goto LAB_002c9f09;
      (**(code **)(*plVar3 + 0xd8))(plVar3,param_1);
    }
    else {
      nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x8e1,
                   "kbusAllocateFlaVaspace_GH100",4,
                   "NVRM: failed pinning down fabric vaspace, status=0x%x\n",iVar6);
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x8d8,
                 "kbusAllocateFlaVaspace_GH100",4,
                 "NVRM: failed allocating fabric vaspace, status=0x%x\n",iVar6);
  }
  if (*(long *)(param_1 + 0x4a18) != 0) {
    vmmDestroyVaspace_IMPL(uVar2);
    *(undefined8 *)(param_1 + 0x4a18) = 0;
  }
LAB_002c9f09:
  (**(code **)(lVar7 + 0x18))
            (lVar7,*(undefined4 *)(param_2 + 0xa810),*(undefined4 *)(param_2 + 0xa810));
  *(undefined1 *)(param_2 + 0xa830) = 0;
  nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x93f,
               "kbusAllocateFlaVaspace_GH100",4,"NVRM: failed allocating FLA VASpace status=0x%x\n",
               iVar6);
  return iVar6;
}


// ===== 002ca130 kbusDestroyFla_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbusDestroyFla_GH100(long param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = *(undefined8 *)(g_pSys + 0x230);
  lVar2 = rmapiGetInterface(4);
  if (*(long *)(param_1 + 0x4a18) != 0) {
    if ((*(char *)(param_2 + 0xa831) != '\0') &&
       ((*(char *)(param_1 + 0x908) != '\0' || (*(char *)(param_1 + 0x909) != '\0')))) {
      (**(code **)(param_2 + 0x3c8))(param_1,param_2);
    }
    if (*(char *)(param_2 + 0xa830) != '\0') {
      (**(code **)(**(long **)(param_1 + 0x4a18) + 0xd8))(*(long **)(param_1 + 0x4a18),param_1);
      (**(code **)(param_2 + 0x3b8))(param_1,param_2);
      vmmDestroyVaspace_IMPL(uVar1,*(undefined8 *)(param_1 + 0x4a18));
      *(undefined8 *)(param_1 + 0x4a18) = 0;
      (**(code **)(lVar2 + 0x18))
                (lVar2,*(undefined4 *)(param_2 + 0xa810),*(undefined4 *)(param_2 + 0xa810));
      portMemSet(param_2 + 0xa810,0,0x50);
      return;
    }
  }
  return;
}


// ===== 002ca270 kbusSetupBindFla_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusSetupBindFla_GH100(long param_1,long param_2)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 local_38;
  undefined8 local_30;
  
  uVar1 = *(undefined8 *)(param_2 + 0xa828);
  local_38 = 0;
  local_30 = 0;
  iVar2 = memdescGetAddressSpace(uVar1);
  if (iVar2 == 1) {
    local_30 = (ulong)local_30._4_4_ << 0x20;
  }
  else if (iVar2 == 2) {
    local_30 = CONCAT44(local_30._4_4_,1);
  }
  local_38 = memdescGetPhysAddr(uVar1,1,0);
  local_30 = local_30 & 0xffffffff;
  iVar2 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20803502,&local_38,0x10);
  if (iVar2 == 0) {
    *(undefined1 *)(param_2 + 0xa831) = 1;
    *(undefined1 *)(param_2 + 0xa861) = 1;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x994,"kbusSetupBindFla_GH100",4,
               "NVRM: FLA bind failed, status: %x \n",iVar2);
  return iVar2;
}


// ===== 002ca390 kbusSetupUnbindFla_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbusSetupUnbindFla_GH100(long param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 local_28;
  undefined8 local_20;
  
  lVar2 = param_1 + 0x3b58;
  local_28 = 0;
  local_20 = 0;
  if (*(char *)(param_1 + 0x909) == '\0') {
    lVar2 = rmapiGetInterface(4);
  }
  uVar1 = 0;
  if (*(char *)(param_2 + 0xa831) != '\0') {
    local_20 = CONCAT44(1,(undefined4)local_20);
    uVar1 = (**(code **)(lVar2 + 0x38))
                      (lVar2,*(undefined4 *)(param_1 + 0x3b34),*(undefined4 *)(param_1 + 0x3b3c),
                       0x20803502,&local_28,0x10);
    *(undefined1 *)(param_2 + 0xa831) = 0;
    *(undefined1 *)(param_2 + 0xa861) = 0;
  }
  return uVar1;
}


// ===== 002ca430 kbusGetFlaRange_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbusGetFlaRange_GH100(long param_1,undefined8 param_2,long *param_3,long *param_4)

{
  long lVar1;
  long lVar2;
  
  if (*(char *)(param_1 + 0x4cc) == '\x01') {
    lVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x4a18),__nvoc_class_def_FABRIC_VASPACE);
    if ((lVar2 == 0) || (lVar1 = *(long *)(lVar2 + 200), lVar1 == 0)) {
      return 0x40;
    }
    lVar2 = *(long *)(lVar2 + 0xc0);
    *param_3 = lVar2;
    *param_4 = (lVar1 + 1) - lVar2;
  }
  else {
    lVar2 = (**(code **)(param_1 + 0x340))(param_1,0);
    *param_4 = lVar2;
    *param_3 = (ulong)*(uint *)(param_1 + 0x7a4) * lVar2;
  }
  return 0;
}


// ===== 002ca4e0 kbusGetEgmPeerId_GH100 =====

undefined1  [16] kbusGetEgmPeerId_GH100(long param_1,long param_2,long param_3)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined8 uStack_10;
  
  uVar2 = *(uint *)(param_2 + 0xa8f4 + (ulong)*(uint *)(param_3 + 0x7a4) * 4);
  uVar3 = (ulong)uVar2;
  lVar1 = 0;
  if (uVar2 == 0) {
    nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0x9fe,"kbusGetEgmPeerId_GH100",1,
                 "NVRM: NVLINK P2P not set up between GPU%u and GPU%u\n",
                 *(undefined4 *)(param_1 + 0x7a4),(ulong)*(uint *)(param_3 + 0x7a4));
    auVar5._8_8_ = uStack_10;
    auVar5._0_8_ = 0xffffffff;
    return auVar5;
  }
  do {
    if ((uVar3 & 1) == 0) {
      uVar3 = (ulong)((uint)uVar3 >> 1);
    }
    else {
      if (*(char *)(param_2 + 0xaa34 + lVar1) != '\0') goto LAB_002ca525;
      uVar2 = (uint)uVar3 >> 1;
      uVar3 = (ulong)uVar2;
      if (uVar2 == 0) {
        lVar1 = 0xffffffff;
LAB_002ca525:
        auVar4._8_8_ = uVar3;
        auVar4._0_8_ = lVar1;
        return auVar4;
      }
    }
    lVar1 = lVar1 + 1;
  } while( true );
}


// ===== 002ca570 kbusCacheBAR1ResizeSize_WAR_BUG_3249028_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbusCacheBAR1ResizeSize_WAR_BUG_3249028_GH100(long param_1,long param_2)

{
  int iVar1;
  int local_1c;
  
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x138,&local_1c);
  if ((iVar1 == 0) && (local_1c != 0)) {
    iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x13c,&local_1c);
    if (iVar1 == 0) {
      *(byte *)(param_2 + 0xa863) = (byte)((uint)local_1c >> 8) & 0x3f;
      return;
    }
    nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0xa29,
                 "kbusCacheBAR1ResizeSize_WAR_BUG_3249028_GH100",4,
                 "NVRM: Unable to read NV_EP_PCFG_GPU_PF_RESIZE_BAR_CTRL\n");
  }
  else {
    nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0xa22,
                 "kbusCacheBAR1ResizeSize_WAR_BUG_3249028_GH100",1,
                 "NVRM: Resizable Bar capability is absent\n");
  }
  *(undefined1 *)(param_2 + 0x559) = 0;
  return;
}


// ===== 002ca650 kbusRestoreBAR1ResizeSize_WAR_BUG_3249028_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kbusRestoreBAR1ResizeSize_WAR_BUG_3249028_GH100(long param_1,long param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint local_1c;
  
  if (*(char *)(param_2 + 0x559) != '\0') {
    if (*(byte *)(param_2 + 0xa863) < 6) {
      nvAssertFailedNoLog("pKernelBus->bar1ResizeSizeIndex >= NV_EP_PCFG_GPU_PF_RESIZE_BAR_CTRL_BAR_SIZE_MIN"
                          ,"src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0xa4c);
      uVar3 = 0x25;
    }
    else {
      iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x13c,&local_1c);
      if (iVar1 == 0) {
        uVar2 = local_1c >> 8 & 0x3f;
        uVar3 = 0;
        if (*(byte *)(param_2 + 0xa863) != uVar2) {
          nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0xa5e,
                       "kbusRestoreBAR1ResizeSize_WAR_BUG_3249028_GH100",3,
                       "NVRM: BAR1 size mismatch: current: 0x%x, expected: 0x%x\n",uVar2,
                       *(byte *)(param_2 + 0xa863));
          nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0xa60,
                       "kbusRestoreBAR1ResizeSize_WAR_BUG_3249028_GH100",3,
                       "NVRM: Most likely SBIOS did not restore the BAR1 size\n");
          nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0xa61,
                       "kbusRestoreBAR1ResizeSize_WAR_BUG_3249028_GH100",3,
                       "NVRM: Please update your SBIOS!\n");
          local_1c = (*(byte *)(param_2 + 0xa863) & 0x3f) << 8 | local_1c & 0xffffc0ff;
          (**(code **)(param_1 + 0x1b8))(param_1,0x13c);
        }
      }
      else {
        nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0xa51,
                     "kbusRestoreBAR1ResizeSize_WAR_BUG_3249028_GH100",4,
                     "NVRM: Unable to read NV_EP_PCFG_GPU_PF_RESIZE_BAR_CTRL\n");
        uVar3 = 0x56;
      }
    }
    return uVar3;
  }
  return 0;
}


// ===== 002ca7e0 kbusWriteBar2BlockRegisters_GH100 =====

undefined4 kbusWriteBar2BlockRegisters_GH100(long param_1,undefined8 param_2,ulong param_3)

{
  int iVar1;
  uint uVar2;
  undefined1 local_40 [24];
  
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0xf70,param_3 & 0xffffffff,0);
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0xf74,param_3 >> 0x20,0);
  osFlushCpuWriteCombineBuffer();
  if ((*(char *)(param_1 + 0x908) != '\0') ||
     ((((*(char *)(param_1 + 0x44f) == '\0' && (*(char *)(param_1 + 0x450) == '\0')) &&
       (*(char *)(param_1 + 0x451) == '\0')) && (*(char *)(param_1 + 0x461) == '\0')))) {
    iVar1 = 0;
    timeoutSet(param_1 + 0x1af0,local_40,0,0);
    while (uVar2 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0xf70,0),
          (uVar2 & 3) != 0) {
      if (iVar1 == 0x65) {
        nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0xaa7,
                     "kbusWriteBar2BlockRegisters_GH100",4,
                     "NVRM: timed out waiting for bar2 binding to complete\n");
        return 0x65;
      }
      iVar1 = timeoutCheck(param_1 + 0x1af0,local_40,0xaab);
      osSpinLoop();
    }
  }
  return 0;
}


// ===== 002ca940 kbusBindBar2_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbusBindBar2_GH100(long param_1,long param_2,int param_3)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  uint local_2c [3];
  
  uVar1 = vgpuGetCallingContextGfid(param_1,local_2c);
  if (uVar1 == 0) {
    lVar2 = (ulong)local_2c[0] * 0xd8 + param_2;
    if (((*(char *)(lVar2 + 0x46a8) == '\0') || (lVar2 = *(long *)(lVar2 + 0x4680), lVar2 == 0)) ||
       (*(char *)(param_2 + 0xad08) == '\0')) {
      lVar2 = *(long *)(param_2 + 0x4678 + (ulong)local_2c[0] * 0xd8);
    }
    uVar3 = 0;
    if (param_3 != 0) {
      uVar1 = kgmmuGetHwPteApertureFromMemdesc_GM107(*(undefined8 *)(param_1 + 0x1b98),lVar2,0);
      uVar3 = memdescGetPhysAddr(lVar2,1,0);
      uVar3 = (ulong)((uVar1 & 3) << 10 | (int)(uVar3 >> 0xc) << 0xc | 0x200) |
              uVar3 & 0xffffffff00000000;
    }
    uVar3 = (**(code **)(param_2 + 0x478))(param_1,param_2,uVar3);
    return uVar3;
  }
  nvAssertOkFailedNoLog
            (uVar1,"vgpuGetCallingContextGfid(pGpu, &gfid)",
             "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0xacc);
  return (ulong)uVar1;
}


// ===== 002caa70 kbusBar1InstBlkBind_GH100 =====

int kbusBar1InstBlkBind_GH100(long param_1,long param_2)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  uint uVar5;
  uint local_44;
  undefined1 local_40 [24];
  
  uVar1 = *(undefined8 *)(param_1 + 0x1b98);
  iVar2 = vgpuGetCallingContextGfid(param_1,&local_44);
  if (iVar2 != 0) {
    nvAssertOkFailedNoLog
              (iVar2,"vgpuGetCallingContextGfid(pGpu, &gfid)",
               "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0xb10);
    return iVar2;
  }
  iVar2 = 0;
  if ((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) {
    iVar3 = kgmmuGetMemAperture_IMPL
                      (uVar1,*(undefined8 *)(param_2 + 0x648 + (ulong)local_44 * 0x100));
    if (iVar3 == 3) {
      uVar5 = 0xc00;
    }
    else if (iVar3 == 4) {
      uVar5 = 0x800;
    }
    else {
      if (iVar3 != 1) {
        nvAssertFailedNoLog(&DAT_00cf8edf,"src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0xb24);
        return 0x40;
      }
      uVar5 = 0;
    }
    uVar4 = *(ulong *)(param_2 + 0x640 + (ulong)local_44 * 0x100);
    regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0xf60,
                (uint)(*(char *)(param_2 + 0xad04) == '\0') << 9 | (int)(uVar4 >> 0xc) << 0xc |
                uVar5,0);
    regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0xf64,uVar4 >> 0x20,0);
    osFlushCpuWriteCombineBuffer();
    if ((*(char *)(param_1 + 0x908) != '\0') ||
       ((((*(char *)(param_1 + 0x44f) == '\0' && (*(char *)(param_1 + 0x450) == '\0')) &&
         (*(char *)(param_1 + 0x451) == '\0')) && (*(char *)(param_1 + 0x461) == '\0')))) {
      timeoutSet(param_1 + 0x1af0,local_40,0,0);
      while (uVar4 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0xf60,0),
            (uVar4 & 3) != 0) {
        if (iVar2 == 0x65) {
          nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0xb64,
                       "kbusBar1InstBlkBind_GH100",4,
                       "NVRM: timed out waiting for bar1 binding to complete\n");
          return 0x65;
        }
        iVar2 = timeoutCheck(param_1 + 0x1af0,local_40,0xb69);
        osSpinLoop();
      }
    }
  }
  return 0;
}


// ===== 002cacef kbusGetEccCounts_GH100.cold =====

void kbusGetEccCounts_GH100_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002cad00 kbusGetEccCounts_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusGetEccCounts_GH100(undefined8 param_1,long param_2)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  
  lVar4 = (**(code **)(param_2 + 0x550))(param_1,param_2,0);
  if (lVar4 != 0) {
    uVar2 = (**(code **)(**(long **)(lVar4 + 0x50) + 0x28))(*(long **)(lVar4 + 0x50),0x364);
    uVar3 = (**(code **)(**(long **)(lVar4 + 0x50) + 0x28))(*(long **)(lVar4 + 0x50),0x37c);
    return (uVar3 >> 0x10) + (uVar2 >> 0x10);
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002cad62 kbusSendSysmembarSingle_GH100.cold =====

void kbusSendSysmembarSingle_GH100_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  undefined8 unaff_R12;
  undefined8 unaff_R14;
  undefined8 unaff_R15;
  
  *(undefined8 *)(unaff_RBP + -0x18) = unaff_R12;
  *(undefined8 *)(unaff_RBP + -0x10) = unaff_R14;
  *(undefined8 *)(unaff_RBP + -8) = unaff_R15;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002cad80 kbusSendSysmembarSingle_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbusSendSysmembarSingle_GH100(long param_1,long param_2)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  undefined1 local_40 [24];
  
  lVar5 = (**(code **)(param_2 + 0x550))(param_1,param_2,0);
  if (((((param_1 != 0) && (*(char *)(param_1 + 0x44f) == '\0')) &&
       (*(char *)(param_1 + 0x450) == '\0')) &&
      ((*(char *)(param_1 + 0x451) == '\0' && (*(char *)(param_1 + 0x461) == '\0')))) &&
     ((*(char *)(param_1 + 0x456) == '\0' && (*(char *)(param_1 + 0x44c) != '\0')))) {
    threadStateResetTimeout(param_1);
    timeoutSet(param_1 + 0x1af0,local_40,0,0);
    if (lVar5 == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    iVar6 = 0;
    uVar2 = (**(code **)(**(long **)(lVar5 + 0x50) + 0x28))(*(long **)(lVar5 + 0x50),0x800);
    iVar4 = 0;
    while( true ) {
      iVar3 = (**(code **)(**(long **)(lVar5 + 0x50) + 0x28))(*(long **)(lVar5 + 0x50),0x804);
      if (-1 < iVar3) {
        return 0;
      }
      if (0x8c < ((uVar2 & 0x7fffffff) - iVar3 & 0x7fffffff)) {
        return 0;
      }
      if (iVar4 == 0x65) {
        nvDbg_Printf("src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0xbdd,
                     "kbusSendSysmembarSingle_GH100",4,
                     "NVRM: - timeout error waiting for startToken = 0x%x cnt=%d\n",
                     uVar2 & 0x7fffffff,iVar6);
        return 0x65;
      }
      if (((*(char *)(param_1 + 0x44f) != '\0') || (*(char *)(param_1 + 0x450) != '\0')) ||
         ((*(char *)(param_1 + 0x451) != '\0' || (*(char *)(param_1 + 0x461) != '\0')))) break;
      if (*(char *)(param_1 + 0x44c) == '\0') {
        nvAssertFailedNoLog("API_GPU_ATTACHED_SANITY_CHECK(pGpu)",
                            "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0xbec);
        return 0;
      }
      iVar6 = iVar6 + 1;
      iVar4 = timeoutCheck(param_1 + 0x1af0,local_40,0xbee);
      osSpinLoop();
    }
    nvAssertFailedNoLog("!API_GPU_IN_RESET_SANITY_CHECK(pGpu)",
                        "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0xbeb);
  }
  return 0;
}


// ===== 002cafb0 kbusConstructXalApertures_GH100 =====

undefined8 kbusConstructXalApertures_GH100(long param_1,long param_2)

{
  long lVar1;
  
  *(undefined4 *)(param_2 + 0xad68) = 2;
  lVar1 = portMemAllocNonPaged(0x110);
  *(long *)(param_2 + 0xad60) = lVar1;
  if (lVar1 != 0) {
    portMemSet(lVar1,0,0x110);
    ioaprtInit(*(undefined8 *)(param_2 + 0xad60),*(undefined8 *)(param_1 + 0x1a18),0x10f000,0x1000);
    ioaprtInit(*(long *)(param_2 + 0xad60) + 0x88,*(undefined8 *)(param_1 + 0x1a18),0x826000,0x2000)
    ;
    return 0;
  }
  nvCheckFailedNoLog(4,"pKernelBus->xalApertures != NULL",
                     "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0xbff);
  return 0x51;
}


// ===== 002cb070 kbusGetXalAperture_GH100 =====

long kbusGetXalAperture_GH100(undefined8 param_1,long param_2,uint param_3)

{
  if (param_3 < *(uint *)(param_2 + 0xad68)) {
    return (ulong)param_3 * 0x88 + *(long *)(param_2 + 0xad60);
  }
  nvAssertFailedNoLog("(NvU32)baseType < pKernelBus->xalApertureCount",
                      "src/kernel/gpu/bus/arch/hopper/kern_bus_gh100.c",0xc11);
  return 0;
}


// ===== 002cb0b0 nullEHeapFree =====

undefined8 nullEHeapFree(void)

{
  return 0;
}


// ===== 002cb0c0 kbusSendMemsysDisableNvlinkPeers =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbusSendMemsysDisableNvlinkPeers(long param_1)

{
  undefined8 uVar1;
  
  if ((((param_1 != 0) && (*(char *)(param_1 + 0x44f) == '\0')) &&
      (*(char *)(param_1 + 0x450) == '\0')) &&
     ((*(char *)(param_1 + 0x451) == '\0' && (*(char *)(param_1 + 0x461) == '\0')))) {
    uVar1 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800a6e,0,0);
    return uVar1;
  }
  return 0;
}


// ===== 002cb120 _kbusInternalBar1Unmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1  [16] _kbusInternalBar1Unmap(long *param_1,undefined8 *param_2,undefined8 param_3)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = 0;
  if (param_1 + *param_1 * -0x20 != (long *)0x610) {
    lVar4 = (param_1 + *param_1 * -0x20)[-0x98];
  }
  lVar2 = gpuEngineGetGpu(lVar4);
  lVar4 = param_1[4];
  lVar1 = *(long *)(lVar2 + 0x1bb8);
  uVar3 = mapFind_IMPL(param_1 + 0x17,param_3);
  mapRemove_IMPL(param_1 + 0x17,uVar3);
  memdescFlushCpuCaches(lVar2,*param_2);
  (**(code **)(lVar1 + 0x170))(lVar2,lVar1,lVar4,param_3,*param_2,0);
  return ZEXT816(0x2cb19d) << 0x40;
}


// ===== 002cb1e0 _kbusDestroyMemdescBar1Cb =====

void _kbusDestroyMemdescBar1Cb(undefined8 param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  
  lVar1 = mapFind_IMPL(param_2 + 0x98,param_3);
  if (lVar1 != 0) {
    mapDestroy_IMPL(lVar1);
    mapRemove_IMPL(param_2 + 0x98,lVar1);
    return;
  }
  return;
}


// ===== 002cb230 _busWalkCBMapNextEntries_UpdatePhysAddr =====

void _busWalkCBMapNextEntries_UpdatePhysAddr(long param_1,long param_2,long param_3,ulong param_4)

{
  uint *puVar1;
  ulong uVar2;
  ulong uVar3;
  uint uVar4;
  ulong uVar5;
  
  uVar4 = *(uint *)(*(long *)(param_3 + 0x10) + 0xc);
  if (*(uint *)(param_3 + 0x18) < uVar4) {
    uVar3 = dmaPageArrayGetPhysAddr();
    uVar3 = -param_4 & uVar3;
  }
  else {
    if ((*(uint *)(param_3 + 0x18) == 0) || (uVar4 != 1)) {
      nvAssertFailedNoLog("(pIter->pPageArray->count == 1) && (pIter->currIdx > 0)",
                          "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x8d4);
      return;
    }
    uVar3 = *(long *)(param_3 + 0x20) + param_4;
  }
  *(ulong *)(param_3 + 0x20) = uVar3;
  uVar3 = kgmmuEncodePhysAddr_IMPL
                    (*(undefined8 *)(param_1 + 0x1b98),*(undefined4 *)(param_3 + 8),uVar3,
                     0xffffffffffffffff);
  puVar1 = *(uint **)(param_3 + 0x38);
  if (*puVar1 != 0) {
    uVar3 = uVar3 >> ((byte)puVar1[0xe] & 0x3f);
    uVar5 = 0;
    do {
      uVar4 = (int)uVar5 + 1;
      uVar2 = *(ulong *)(param_2 + (ulong)puVar1[uVar5 * 6 + 6]);
      *(ulong *)(param_2 + (ulong)puVar1[uVar5 * 6 + 6]) =
           (uVar3 << ((byte)puVar1[uVar5 * 6 + 5] & 0x3f) ^ uVar2) &
           *(ulong *)(puVar1 + uVar5 * 6 + 2) ^ uVar2;
      uVar3 = uVar3 >> ((byte)puVar1[uVar5 * 6 + 4] & 0x3f);
      uVar5 = (ulong)uVar4;
    } while (uVar4 < *puVar1);
  }
  *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + (int)(param_4 >> 0xc);
  return;
}


// ===== 002cb340 kbusTeardownBar2GpuVaSpace_GM107.part.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

int kbusTeardownBar2GpuVaSpace_GM107_part_0(long param_1,long param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  undefined8 local_70;
  undefined8 local_68;
  long local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar6 = (ulong)param_3;
  lVar7 = uVar6 * 0xd8 + param_2;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_70 = 0;
  uVar4 = mmuFmtFindLevelWithPageShift(*(undefined8 *)(*(long *)(lVar7 + 0x46c0) + 8),0xc);
  local_60 = param_1;
  iVar2 = mmuWalkSetUserCtx(*(undefined8 *)(lVar7 + 0x46b0),&local_68);
  if (iVar2 != 0) {
    nvAssertOkFailedNoLog
              (iVar2,"mmuWalkSetUserCtx(pKernelBus->bar2[gfid].pWalk, &userCtx)",
               "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x7d1);
    return iVar2;
  }
  if (((*(char *)(param_2 + 0xad08) == '\0') && (param_3 == 0)) &&
     ((*(char *)(param_1 + 0x454) == '\0' || (*(char *)(param_1 + 0x4915) == '\0')))) {
    iVar2 = (**(code **)(param_2 + 0x440))(param_1,param_2,&local_70);
    if (iVar2 != 0) {
      nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x7dc
                         );
      return iVar2;
    }
    iVar2 = 0;
    if (*(long *)(param_2 + 0x4628) != 0) {
      iVar2 = mmuWalkUnmap(*(undefined8 *)(param_2 + 0x46b0),*(undefined8 *)(param_2 + 0x4620));
      if (iVar2 != 0) {
        nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                            0x7e1);
      }
      mmuWalkReleaseEntries
                (*(undefined8 *)(param_2 + 0x46b0),uVar4,*(undefined8 *)(param_2 + 0x4620),
                 *(undefined8 *)(param_2 + 0x4628));
    }
    if (*(long *)(param_2 + 0x4638) != 0) {
      iVar2 = mmuWalkUnmap(*(undefined8 *)(param_2 + 0x46b0),*(undefined8 *)(param_2 + 0x4630));
      if (iVar2 != 0) {
        nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                            0x7e8);
      }
      mmuWalkReleaseEntries
                (*(undefined8 *)(param_2 + 0x46b0),uVar4,*(undefined8 *)(param_2 + 0x4630),
                 *(undefined8 *)(param_2 + 0x4638));
    }
    (**(code **)(param_2 + 0x448))(param_1,param_2,local_70);
  }
  else {
    mmuWalkLevelInstancesForceFree(*(undefined8 *)(param_2 + 0x46b0 + uVar6 * 0xd8));
    iVar2 = 0;
  }
  iVar3 = mmuWalkSetUserCtx(*(undefined8 *)(param_2 + 0x46b0 + uVar6 * 0xd8),0);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,"mmuWalkSetUserCtx(pKernelBus->bar2[gfid].pWalk, NULL)",
               "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x7ef);
    return iVar3;
  }
  if (*(char *)(param_2 + 0xad08) != '\0') {
    (**(code **)(param_2 + 0x4a8))(param_1,param_2,param_3);
    (**(code **)(param_2 + 0x4b8))(param_1,param_2,param_3);
  }
  lVar7 = param_2 + uVar6 * 0xd8;
  mmuWalkDestroy(*(undefined8 *)(lVar7 + 0x46b0));
  *(undefined8 *)(lVar7 + 0x46b0) = 0;
  *(undefined8 *)(lVar7 + 0x4660) = 0;
  *(undefined8 *)(lVar7 + 0x4698) = 0;
  lVar5 = uVar6 * 0xb0 + param_2;
  *(undefined8 *)(lVar5 + 0x7c90) = 0;
  memdescFree(*(undefined8 *)(lVar7 + 0x46b8));
  memdescDestroy(*(undefined8 *)(lVar7 + 0x46b8));
  *(undefined8 *)(lVar7 + 0x46b8) = 0;
  if (param_3 == 0) {
    if (*(long *)(param_2 + 0x7c70) != 0) {
      memdescFree();
      memdescDestroy(*(undefined8 *)(param_2 + 0x7c70));
      *(undefined8 *)(param_2 + 0x7c70) = 0;
    }
    if (*(char *)(param_1 + 0x909) == '\0') {
      return iVar2;
    }
  }
  else {
    lVar7 = *(long *)(lVar5 + 0x7c70);
    if (*(long *)(lVar5 + 0x7c78) != 0) {
      memdescUnmapInternal(param_1,lVar7,0);
      *(undefined8 *)(lVar5 + 0x7c78) = 0;
      lVar7 = *(long *)(lVar5 + 0x7c70);
    }
    if (lVar7 == 0) {
      cVar1 = *(char *)(param_1 + 0x909);
    }
    else {
      memdescFree(lVar7);
      lVar7 = uVar6 * 0xb0 + param_2;
      memdescDestroy(*(undefined8 *)(lVar7 + 0x7c70));
      *(undefined8 *)(lVar7 + 0x7c70) = 0;
      cVar1 = *(char *)(param_1 + 0x909);
    }
    if (cVar1 == '\0') goto LAB_002cb65a;
  }
  lVar7 = uVar6 * 0xb0 + param_2;
  if (*(long *)(lVar7 + 0x7ca8) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(lVar7 + 0x7ca8));
    *(undefined8 *)(lVar7 + 0x7ca8) = 0;
  }
  lVar7 = gpuGetRpc(param_1);
  if (lVar7 == 0) {
    iVar2 = 0x1a;
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x82a);
  }
  else if (iVar2 == 0) {
    iVar2 = (**(code **)(lVar7 + 0x490))
                      (param_1,lVar7,1,0,
                       **(undefined1 **)(*(long *)(param_2 + 0x46c0 + uVar6 * 0xd8) + 8),
                       *(code **)(lVar7 + 0x490));
  }
  if (param_3 == 0) {
    return iVar2;
  }
LAB_002cb65a:
  param_2 = uVar6 * 0xd8 + param_2;
  if (*(long *)(param_2 + 0x4678) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 0x4678));
    *(undefined8 *)(param_2 + 0x4678) = 0;
  }
  return iVar2;
}


// ===== 002cb850 _kbusGetCurrentGfid.isra.0 =====

ulong _kbusGetCurrentGfid_isra_0(long param_1)

{
  int iVar1;
  ulong uVar2;
  char local_1d;
  uint local_1c [3];
  
  iVar1 = vgpuGetCallingContextGfid(param_1,local_1c);
  if (iVar1 == 0) {
    uVar2 = vgpuIsCallingContextPlugin(param_1,&local_1d);
    if ((int)uVar2 == 0) {
      if (local_1d != '\0') {
        return uVar2;
      }
      uVar2 = uVar2 & 0xffffffff;
      if (*(char *)(param_1 + 0x491e) != '\0') {
        uVar2 = (ulong)local_1c[0];
      }
      return uVar2;
    }
    nvAssertFailedNoLog("vgpuIsCallingContextPlugin(pGpu, &bCallingContextPlugin) == NV_OK",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xae9);
  }
  else {
    nvAssertFailedNoLog("vgpuGetCallingContextGfid(pGpu, &gfid) == NV_OK",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xae8);
  }
  return 0xffffffff;
}


// ===== 002cb8f0 kbusConstructHal_GM107 =====

undefined8 kbusConstructHal_GM107(long param_1,long param_2)

{
  nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x67,"kbusConstructHal_GM107",1,
               "NVRM: Entered \n");
  *(undefined8 *)(param_2 + 0xabc0) = 0xffffffffffffffff;
  *(undefined8 *)(param_2 + 0x4658) = 0xdeadbeef;
  *(undefined8 *)(param_2 + 0x4668) = 0xdeadbeef;
  *(undefined8 *)(param_2 + 0x4630) = 0;
  *(undefined8 *)(param_2 + 0x4638) = 0;
  *(undefined8 *)(param_2 + 0x7c10) = 0;
  *(undefined8 *)(param_2 + 0x7c20) = 0;
  if ((*(char *)(param_1 + 0x44d) == '\0') && (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) == '\0')
     ) {
    if ((*(char *)(param_1 + 1099) == '\0') && (*(char *)(param_2 + 0xad11) == '\0'))
    goto LAB_002cb99b;
  }
  else {
    *(undefined1 *)(param_2 + 0xad11) = 1;
  }
  *(undefined1 *)(param_2 + 0xad28) = 0;
LAB_002cb99b:
  *(undefined8 *)(param_2 + 0x7c98) = 0;
  *(undefined8 *)(param_2 + 0xad2c) = 0x200000002;
  *(undefined8 *)(param_2 + 0xad34) = 0x200000002;
  *(undefined4 *)(param_2 + 0xacf0) = 8;
  return 0;
}


// ===== 002cb9f0 kbusStatePreInitLocked_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kbusStatePreInitLocked_GM107(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  
  nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x9e,
               "kbusStatePreInitLocked_GM107",1,"NVRM: gpu:%d\n",*(undefined4 *)(param_1 + 0x7a4));
  if ((*(byte *)(param_1 + 0x4938) & 1) != 0) {
    *(undefined1 *)(param_2 + 0xad44) = 1;
  }
  if ((*(char *)(param_1 + 0x908) == '\0') &&
     (uVar1 = (**(code **)(param_2 + 0x168))(param_1,param_2), uVar1 != 0)) {
    nvCheckOkFailedNoLog
              (4,uVar1,"kbusInitBarsSize_HAL(pGpu, pKernelBus)",
               "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xa8);
    return uVar1;
  }
  kbusDetermineBar1Force64KBMapping_IMPL(param_2);
  kbusDetermineBar1ApertureLength_IMPL(param_2,0);
  iVar2 = kbusConstructVirtualBar2_VBAR2(param_1,param_2,0);
  return -(uint)(iVar2 != 0) & 0x1a;
}


// ===== 002cbac0 kbusStateInitLockedKernel_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusStateInitLockedKernel_GM107(long param_1,long param_2)

{
  undefined1 uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  undefined4 local_2c;
  
  lVar6 = *(long *)(param_1 + 7000);
  lVar2 = *(long *)(param_1 + 0x1bb8);
  if ((lVar6 != 0) && ((*(char *)(lVar6 + 0x3a9) == '\0' || (*(char *)(lVar6 + 0x3aa) == '\0')))) {
    iVar4 = osReadRegistryDword(param_1,"RMP2PPeerId",&local_2c);
    if (iVar4 == 0) {
      *(undefined1 *)(param_2 + 0xacf4) = 1;
      *(undefined4 *)(param_2 + 0xacf8) = local_2c;
    }
    else {
      *(undefined1 *)(param_2 + 0xacf4) = 0;
    }
  }
  if ((*(char *)(param_1 + 0x454) == '\0') || (*(char *)(param_1 + 0x4915) == '\0')) {
    lVar6 = *(long *)(param_1 + 0x1b78);
    lVar5 = kmemsysGetStaticConfig_IMPL(param_1,*(undefined8 *)(param_1 + 0x1b70));
    if ((*(char *)(param_1 + 0x454) == '\0') || (*(char *)(param_1 + 0x4915) == '\0')) {
      if (*(char *)(lVar6 + 0xd1c) == '\0') {
        lVar6 = *(long *)(lVar6 + 0x838) * 0x100000 + -0x100000;
        if (*(char *)(param_1 + 0x4921) != '\0') goto LAB_002cbe1c;
LAB_002cbba5:
        if (*(char *)(lVar5 + 0x10) == '\0') goto LAB_002cbe1c;
        cVar3 = *(char *)(param_1 + 0x4913);
      }
      else {
        lVar6 = *(long *)(lVar6 + 0x490);
        if (*(char *)(param_1 + 0x4921) == '\0') goto LAB_002cbba5;
LAB_002cbe1c:
        lVar6 = 0;
        if (0xfffff < *(ulong *)(lVar5 + 8)) {
          lVar6 = *(ulong *)(lVar5 + 8) - 0x100000;
        }
        cVar3 = *(char *)(param_1 + 0x4913);
      }
      if (cVar3 == '\0') {
        plVar7 = (long *)gpuGetDeviceMapping_IMPL(param_1,0,0);
        lVar5 = *plVar7;
        *(undefined8 *)(param_2 + 0x608) = 0x100000;
        *(long *)(param_2 + 0x5f8) = lVar5 + 0x700000;
        *(long *)(param_2 + 0x600) = lVar5 + 0x700000;
        (**(code **)(param_2 + 0x430))(param_1,param_2,lVar6);
      }
    }
    else {
      nvAssertFailedNoLog("!KBUS_BAR0_PRAMIN_DISABLED(pGpu)",
                          "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xcf);
    }
    cVar3 = gpuIsCCFeatureEnabled_IMPL(param_1);
    if ((cVar3 != '\0') &&
       (iVar4 = (**(code **)(*(long *)(param_1 + 0x1b98) + 0x500))(param_1), iVar4 != 0)) {
      nvAssertOkFailedNoLog
                (iVar4,"kgmmuCreateFakeSparseTables_HAL(pGpu, GPU_GET_KERNEL_GMMU(pGpu))",
                 "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x132);
      return iVar4;
    }
  }
  if ((*(char *)(param_1 + 0x4a4e) == '\0') || (*(char *)(param_1 + 0x4913) == '\0')) {
    if ((*(char *)(param_1 + 0x909) != '\0') && (param_2 != 0)) goto LAB_002cbcd0;
  }
  else {
    vgpuGspTeardownBuffers(param_1);
    if (*(char *)(param_2 + 0xad09) == '\0') {
      cVar3 = *(char *)(param_1 + 0x909);
    }
    else {
      (**(code **)(param_2 + 0x238))(param_1,param_2,0);
      *(undefined1 *)(param_2 + 0xad09) = 0;
      cVar3 = *(char *)(param_1 + 0x909);
    }
    if (cVar3 != '\0') {
LAB_002cbcd0:
      if (*(char *)(param_2 + 0xad46) != '\0') {
        nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x148,
                     "kbusStateInitLockedKernel_GM107",1,
                     "NVRM: For GSP client with C2C enabled, skip BAR2 init\n");
        cVar3 = *(char *)(param_1 + 0x4a4e);
        goto joined_r0x002cbd0c;
      }
    }
  }
  iVar4 = (**(code **)(param_2 + 0x450))(param_1,param_2,0);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,"kbusInitBar2_HAL(pGpu, pKernelBus, GPU_GFID_PF)",
               "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x14c);
    return iVar4;
  }
  cVar3 = *(char *)(param_1 + 0x4a4e);
joined_r0x002cbd0c:
  if ((cVar3 == '\0') || (*(char *)(param_1 + 0x4913) == '\0')) {
    cVar3 = *(char *)(param_1 + 0x908);
  }
  else {
    vgpuGspSetupBuffers(param_1);
    cVar3 = *(char *)(param_1 + 0x908);
  }
  if (cVar3 != '\0') {
    lVar6 = gpuGetStaticInfo(param_1);
    uVar1 = *(undefined1 *)(lVar6 + 0xa78c);
    *(undefined1 *)(param_2 + 0xa860) = uVar1;
    nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x15a,
                 "kbusStateInitLockedKernel_GM107",1,
                 "NVRM: Enabling FLA Support in Guest RM: %x, flabase: %llx, flaSize: %llx \n",uVar1
                 ,*(undefined8 *)(lVar6 + 0xa790),*(undefined8 *)(lVar6 + 0xa798));
    if ((*(char *)(param_2 + 0xa860) != '\0') &&
       (iVar4 = (**(code **)(param_2 + 0x360))
                          (param_1,param_2,*(undefined8 *)(lVar6 + 0xa790),
                           *(undefined8 *)(lVar6 + 0xa798)), iVar4 != 0)) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x161
                         );
    }
  }
  if ((*(char *)(param_1 + 0x454) == '\0') &&
     (iVar4 = (**(code **)(param_2 + 0x468))(param_1,param_2,0,0,0,0), iVar4 != 0)) {
    nvAssertOkFailedNoLog
              (iVar4,"kbusVerifyBar2_HAL(pGpu, pKernelBus, NULL, NULL, 0, 0)",
               "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x168);
  }
  else {
    if (*(char *)(lVar2 + 0x1c4) != '\0') {
      *(undefined4 *)(param_2 + 0x7ca0) = 0x10000;
      *(code **)(*(long *)(param_2 + 0x7c10) + 0x10) = nullEHeapFree;
    }
    iVar4 = 0;
  }
  return iVar4;
}


// ===== 002cbfa0 kbusStateInitLocked_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbusStateInitLocked_IMPL(long param_1,long param_2)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  
  if ((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(param_1 + 0x4913) == '\0')) {
    return 0;
  }
  if (*(char *)(param_1 + 0x909) != '\0') {
    cVar1 = gpuIsCCFeatureEnabled_IMPL();
    if ((cVar1 != '\0') && (*(char *)(param_2 + 0xad47) == '\0')) {
      *(undefined1 *)(param_2 + 0xad0c) = 1;
      *(undefined1 *)(param_2 + 0xad07) = 1;
      nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x18a,
                   "kbusStateInitLocked_IMPL",1,"NVRM: BARs will be blocked for CC\n");
      goto LAB_002cbfe1;
    }
  }
  *(undefined1 *)(param_2 + 0xad0c) = 0;
LAB_002cbfe1:
  uVar2 = memmgrVerifyGspDmaOps_IMPL(param_1,*(undefined8 *)(param_1 + 0x1b78));
  if (uVar2 == 0) {
    if (*(char *)(param_2 + 0xad45) != '\0') {
      *(undefined8 *)(param_2 + 0x5a8) = 0;
      *(undefined8 *)(param_2 + 0x618) = 0;
      *(undefined8 *)(param_2 + 0x620) = 0;
    }
    if (*(char *)(param_2 + 0xad46) != '\0') {
      nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x19e,
                   "kbusStateInitLocked_IMPL",1,
                   "NVRM: C2C is being used, so disable CPU visible BAR2 now before they are setup\n"
                  );
      *(undefined8 *)(param_2 + 0x5b0) = 0;
      *(undefined8 *)(param_2 + 0x4610) = 0;
      *(undefined8 *)(param_2 + 0x4648) = 0;
      if (*(long *)(param_2 + 0x4620) != 0) {
        nvAssertFailedNoLog("pKernelBus->bar2[GPU_GFID_PF].cpuVisibleBase == 0",
                            "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x1af);
      }
      uVar3 = *(ulong *)(param_2 + 0x4638);
      uVar4 = *(ulong *)(param_2 + 0x4630);
      if (uVar3 < uVar4) {
        nvAssertFailedNoLog("pKernelBus->bar2[GPU_GFID_PF].cpuInvisibleLimit >= pKernelBus->bar2[GPU_GFID_PF].cpuInvisibleBase"
                            ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x1b0);
        uVar4 = *(ulong *)(param_2 + 0x4630);
        uVar3 = *(ulong *)(param_2 + 0x4638);
      }
      if (*(long *)(param_2 + 0x4628) + 1U == uVar4) {
        nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x1b3,
                     "kbusStateInitLocked_IMPL",1,
                     "NVRM: Contiguous range, update BAR2 cpuInvisibleBase: 0x%llX to 0, and cpuInvisibleLimit: 0x%llX to 0x%llX.\n"
                     ,uVar4,uVar3,uVar3 - uVar4);
        *(long *)(param_2 + 0x4638) = *(long *)(param_2 + 0x4638) - *(long *)(param_2 + 0x4630);
        *(undefined8 *)(param_2 + 0x4630) = *(undefined8 *)(param_2 + 0x4620);
      }
      else {
        nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x1bc,
                     "kbusStateInitLocked_IMPL",1,
                     "NVRM: Discontiguous range, retaining BAR2 cpuInvisibleBase: 0x%llX, and cpuInvisibleLimit: 0x%llX.\n"
                     ,uVar4,uVar3);
      }
      nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x1c1,
                   "kbusStateInitLocked_IMPL",1,"NVRM: Setting cpuVisibleLimit: 0x%llX to 0\n",
                   *(undefined8 *)(param_2 + 0x4628));
      *(undefined1 *)(param_2 + 0xad08) = 0;
      *(undefined8 *)(param_2 + 0x4628) = 0;
    }
    uVar3 = (**(code **)(param_2 + 0x188))(param_1,param_2);
    if ((int)uVar3 == 0) {
      if (*(long *)(param_2 + 0x648) != 0) {
        uVar3 = memmgrMemDescMemSet_IMPL
                          (*(undefined8 *)(param_1 + 0x1b78),*(long *)(param_2 + 0x648),0,0);
        if ((int)uVar3 != 0) {
          nvAssertOkFailedNoLog
                    (uVar3 & 0xffffffff,
                     "memmgrMemDescMemSet(GPU_GET_MEMORY_MANAGER(pGpu), pKernelBus->bar1[GPU_GFID_PF].pInstBlkMemDesc, 0, TRANSFER_FLAGS_NONE)"
                     ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x1d8);
          uVar3 = uVar3 & 0xffffffff;
        }
      }
    }
    else {
      nvAssertOkFailedNoLog
                (uVar3 & 0xffffffff,"kbusStateInitLockedKernel_HAL(pGpu, pKernelBus)",
                 "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x1d1);
      uVar3 = uVar3 & 0xffffffff;
    }
  }
  else {
    nvAssertOkFailedNoLog
              (uVar2,"memmgrVerifyGspDmaOps(pGpu, GPU_GET_MEMORY_MANAGER(pGpu))",
               "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x192);
    uVar3 = (ulong)uVar2;
  }
  return uVar3;
}


// ===== 002cc300 kbusStatePreLoad_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbusStatePreLoad_GM107(long param_1,long param_2,uint param_3)

{
  long lVar1;
  char cVar2;
  ulong uVar3;
  
  if ((param_3 & 1) != 0) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x1b78) + 0x838);
    if (lVar1 == 0) {
      cVar2 = rmcfg_IsTEGRA_TEGRA_NVDISP_GPUS();
      if (cVar2 == '\0') {
        nvAssertFailedNoLog("IsTEGRA(pGpu)","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x202
                           );
      }
    }
    else if ((*(char *)(param_1 + 0x454) == '\0') || (*(char *)(param_1 + 0x4915) == '\0')) {
      (**(code **)(param_2 + 0x430))(param_1,param_2,lVar1 * 0x100000 + -0x100000);
    }
    uVar3 = (**(code **)(param_2 + 0x458))(param_2,param_3);
    if ((int)uVar3 != 0) {
      nvAssertOkFailedNoLog
                (uVar3 & 0xffffffff,"kbusRestoreBar2_HAL(pKernelBus, flags)",
                 "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x205);
      uVar3 = uVar3 & 0xffffffff;
    }
    return uVar3;
  }
  return 0;
}


// ===== 002cc3f0 kbusStateLoad_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

ulong kbusStateLoad_GM107(long param_1,long param_2,ulong param_3)

{
  uint uVar1;
  ulong uVar2;
  
  if ((*(char *)(param_1 + 0x908) != '\0') && ((param_3 & 1) != 0)) {
    uVar1 = (**(code **)(param_2 + 0x530))();
    param_3 = param_3 & 0xffffffff;
    if (uVar1 != 0) {
      nvAssertOkFailedNoLog
                (uVar1,"kbusBar1InstBlkBind_HAL(pGpu, pKernelBus)",
                 "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x215);
      return (ulong)uVar1;
    }
  }
  if ((*(int *)(param_1 + 0x4b34) == 4) ||
     ((*(char *)(param_1 + 0x4913) != '\0' && (*(char *)(param_1 + 0x491e) == '\0')))) {
    return 0;
  }
  if ((param_3 & 4) == 0) {
    (**(code **)(param_2 + 0x3f8))(param_1,param_2,*(code **)(param_2 + 0x3f8));
    return param_3 & 4;
  }
  uVar2 = (**(code **)(param_2 + 0x400))();
  if ((int)uVar2 == 0) {
    return uVar2;
  }
  nvCheckOkFailedNoLog
            (4,uVar2 & 0xffffffff,"kbusRestoreBAR1ResizeSize_WAR_BUG_3249028_HAL(pGpu, pKernelBus)",
             "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x223);
  return uVar2 & 0xffffffff;
}


// ===== 002cc4d0 kbusStatePostLoad_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbusStatePostLoad_GM107(long param_1,long param_2,ulong param_3)

{
  uint *puVar1;
  int *piVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  long lVar11;
  ulong uVar12;
  byte local_4c;
  undefined1 local_44 [8];
  int local_3c;
  
  lVar11 = *(long *)(param_1 + 7000);
  if ((*(int *)(param_1 + 0x4b34) != 4) &&
     (((param_2 == 0 || (*(char *)(param_2 + 0xad45) == '\0')) &&
      (uVar12 = (**(code **)(param_2 + 0x4d8))(param_1,param_2,0), (int)uVar12 != 0)))) {
    return uVar12;
  }
  if (lVar11 != 0) {
    if (*(char *)(param_2 + 0xad01) == '\0') {
      cVar6 = *(char *)(lVar11 + 0x3a9);
    }
    else {
      if ((param_3 & 4) == 0) goto LAB_002cc550;
      cVar6 = *(char *)(lVar11 + 0x3a9);
    }
    if (((cVar6 == '\0') || (*(char *)(lVar11 + 0x3aa) == '\0')) &&
       (*(char *)(param_1 + 0x480) != '\0')) {
      uVar12 = 0;
      do {
        while ((*(int *)(param_2 + 0xaa40 + uVar12 * 4) == 0 &&
               (iVar8 = (**(code **)(param_2 + 0x300))(param_1,param_2,uVar12 & 0xffffffff),
               iVar8 == 0))) {
LAB_002cc6c0:
          uVar12 = uVar12 + 1;
          if (uVar12 == 0x20) goto LAB_002cc550;
        }
        lVar11 = gpumgrGetGpu(uVar12 & 0xffffffff);
        if (lVar11 == 0) {
          nvAssertFailedNoLog("pRemoteGpu != NULL",
                              "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xe06);
          cVar6 = gpuIsGpuFullPower_IMPL(0);
          if (cVar6 != '\0') goto LAB_002cc71b;
          goto LAB_002cc6c0;
        }
        cVar6 = gpuIsGpuFullPower_IMPL(lVar11);
        if ((cVar6 == '\0') && (param_1 != lVar11)) goto LAB_002cc6c0;
LAB_002cc71b:
        lVar4 = *(long *)(param_1 + 0x1ce8);
        lVar5 = *(long *)(lVar11 + 0x1ce8);
        uVar7 = (**(code **)(param_2 + 0x288))(param_1,param_2,lVar11);
        uVar9 = (**(code **)(*(long *)(&DAT_00001b90 + lVar11) + 0x288))
                          (lVar11,*(long *)(&DAT_00001b90 + lVar11),param_1);
        if (7 < uVar7) {
          nvAssertFailedNoLog("locPeerId < P2P_MAX_NUM_PEERS",
                              "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xe15);
        }
        if (7 < uVar9) {
          nvAssertFailedNoLog("remPeerId < P2P_MAX_NUM_PEERS",
                              "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xe16);
        }
        if (uVar9 != *(uint *)(param_2 + 0xaac4 + (ulong)uVar7 * 0x20)) {
          nvAssertFailedNoLog("pKernelBus->p2pPcie.busPeer[locPeerId].remotePeerId == remPeerId",
                              "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xe17);
        }
        local_4c = (byte)uVar7;
        if (((lVar4 != 0) && (lVar5 != 0)) &&
           (iVar8 = knvlinkGetP2pConnectionStatus_IMPL(param_1,lVar4,lVar11), iVar8 == 0)) {
          if ((*(char *)(param_2 + 0xad01) == '\0') && (*(char *)(param_1 + 0x443) == '\0')) {
            lVar3 = *(long *)(&DAT_00001b90 + lVar11);
            puVar1 = (uint *)(param_2 + 0xa8f4 + (ulong)*(uint *)(lVar11 + 0x7a4) * 4);
            *puVar1 = *puVar1 | 1 << (local_4c & 0x1f);
            puVar1 = (uint *)(lVar3 + 0xa8f4 + (ulong)*(uint *)(param_1 + 0x7a4) * 4);
            *puVar1 = *puVar1 | 1 << ((byte)uVar9 & 0x1f);
            piVar2 = (int *)(param_2 + 0xa974 + (ulong)*(uint *)(lVar11 + 0x7a4) * 4);
            *piVar2 = *piVar2 + 1;
            piVar2 = (int *)(lVar3 + 0xa974 + (ulong)*(uint *)(param_1 + 0x7a4) * 4);
            *piVar2 = *piVar2 + 1;
            piVar2 = (int *)(param_2 + 0xa9f4 + (ulong)uVar7 * 4);
            *piVar2 = *piVar2 + 1;
            piVar2 = (int *)(lVar3 + 0xa9f4 + (ulong)uVar9 * 4);
            *piVar2 = *piVar2 + 1;
          }
          iVar8 = knvlinkTrainP2pLinksToActive_IMPL(param_1,lVar11,lVar4);
          if (iVar8 != 0) {
            nvAssertFailedNoLog(&DAT_00cf9b47,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                                0xe33);
          }
          (**(code **)(lVar4 + 0x200))(param_1,lVar4,lVar11,uVar7);
          (**(code **)(lVar5 + 0x200))(lVar11,lVar5,param_1,(ulong)uVar9);
          goto LAB_002cc6c0;
        }
        uVar10 = *(uint *)(param_2 + 0xaa40 + uVar12 * 4);
        uVar10 = uVar10 - (uVar10 >> 1 & 0x55555555);
        uVar10 = (uVar10 & 0x33333333) + (uVar10 >> 2 & 0x33333333);
        if (((uVar10 >> 4) + uVar10 & 0xf0f0f0f) * 0x1010101 >> 0x18 != 1) {
          nvAssertFailedNoLog("nvPopCount32(pKernelBus->p2pPcie.peerNumberMask[i]) == 1",
                              "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xe43);
        }
        (**(code **)(param_2 + 0x2c8))
                  (param_1,param_2,lVar11,*(undefined8 *)(&DAT_00001b90 + lVar11),uVar7,uVar9);
        (**(code **)(*(long *)(&DAT_00001b90 + lVar11) + 0x2c8))
                  (lVar11,*(long *)(&DAT_00001b90 + lVar11),param_1,param_2,uVar9,uVar7);
        portMemSet(local_44,0,0xc);
        local_3c = 1 << (local_4c & 0x1f);
        iVar8 = (**(code **)(param_1 + 0x3b90))
                          (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                           *(undefined4 *)(param_1 + 0x3b3c),0x20800a88,local_44,0xc);
        if (iVar8 != 0) {
          nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xe57,"_kbusLinkP2P_GM107"
                       ,4,"NVRM: Error in programming the local PEER_CONNECTION_CFG registers\n");
        }
        portMemSet(local_44,0,0xc);
        local_3c = 1 << ((byte)uVar9 & 0x1f);
        iVar8 = (**(code **)(lVar11 + 0x3b90))
                          (lVar11 + 0x3b58,*(undefined4 *)(lVar11 + 0x3b34),
                           *(undefined4 *)(lVar11 + 0x3b3c),0x20800a88,local_44,0xc);
        if (iVar8 == 0) goto LAB_002cc6c0;
        uVar12 = uVar12 + 1;
        nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xe64,"_kbusLinkP2P_GM107",4
                     ,"NVRM: Error in programming the remote PEER_CONNECTION_CFG registers\n");
      } while (uVar12 != 0x20);
    }
  }
LAB_002cc550:
  if ((*(int *)(param_2 + 0xad54) == 0) ||
     (uVar7 = (**(code **)(param_2 + 0x540))(param_1,param_2,param_2 + 0xad58), uVar7 == 0)) {
    kbusUpdateRusdStatistics_IMPL(param_1);
    uVar12 = 0;
  }
  else {
    nvAssertOkFailedNoLog
              (uVar7,"kbusGetPFBar1Spa_HAL(pGpu, pKernelBus, &pKernelBus->grdmaBar1Spa)",
               "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x2cc);
    uVar12 = (ulong)uVar7;
  }
  return uVar12;
}


// ===== 002cca60 kbusTeardownMailbox_GM107 =====

void kbusTeardownMailbox_GM107(long param_1)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x1704,0);
  regWrite032(param_1 + 0x3a18,0,0,0x1704,uVar1 & 0x4fffffff,0);
  return;
}


// ===== 002ccab0 kbusStatePostUnload_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbusStatePostUnload_GM107(undefined8 param_1,long param_2,uint param_3)

{
  int iVar1;
  
  if ((param_3 & 0x21) != 1) {
    return 0;
  }
  iVar1 = (**(code **)(param_2 + 0x238))(param_1,param_2,0);
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog
              (iVar1,"kbusTeardownBar2CpuAperture_HAL(pGpu, pKernelBus, GPU_GFID_PF)",
               "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x317);
  }
  return 0;
}


// ===== 002ccb00 kbusUnmapPreservedConsole_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbusUnmapPreservedConsole_GM107(long param_1,long param_2,int param_3)

{
  long lVar1;
  
  if ((*(char *)(param_2 + 0xad0b) != '\0') && (param_3 == 0)) {
    lVar1 = memmgrGetReservedConsoleMemDesc_IMPL(param_1,*(undefined8 *)(param_1 + 0x1b78));
    if (lVar1 == 0) {
      if (*(int *)(param_1 + 0x930) == 0) {
        nvAssertFailedNoLog("pConsoleMemDesc != NULL",
                            "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x4e9);
      }
      else {
        (**(code **)(**(long **)(param_2 + 0x630) + 0x40))(*(long **)(param_2 + 0x630),0);
      }
    }
    else {
      kbusUnmapFbApertureSingle_IMPL(param_1,param_2,lVar1,0,*(undefined8 *)(lVar1 + 0x30),0xa0);
    }
    *(undefined1 *)(param_2 + 0xad0b) = 0;
    return;
  }
  return;
}


// ===== 002ccbb0 kbusDestroyBar1_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbusDestroyBar1_GM107(undefined8 param_1,long param_2,uint param_3)

{
  long *plVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  
  uVar3 = (ulong)param_3;
  plVar1 = *(long **)(param_2 + 0x630 + uVar3 * 0x100);
  if (plVar1 != (long *)0x0) {
    uVar2 = *(undefined8 *)(g_pSys + 0x230);
    if ((param_3 == 0) && (*(long *)(param_2 + 0xabc0) != -1)) {
      if (*(char *)(param_2 + 0xad01) == '\0') {
        (**(code **)(*plVar1 + 0x40))();
      }
      *(undefined8 *)(param_2 + 0xabc0) = 0xffffffffffffffff;
      *(undefined8 *)(param_2 + 0xabc8) = 0;
    }
    kbusUnmapPreservedConsole_GM107(param_1,param_2,uVar3);
    if (*(char *)(param_2 + 0x6e8 + uVar3 * 0x100) != '\0') {
      (**(code **)(param_2 + 0x318))(param_1,param_2,param_3);
    }
    lVar4 = uVar3 * 0x100;
    vmmDestroyVaspace_IMPL(uVar2,*(undefined8 *)(param_2 + 0x630 + lVar4));
    reusemappingdbDestruct(param_2 + 0x650 + lVar4);
    mapDestroy_IMPL(param_2 + 0x6a8 + lVar4);
    mapDestroy_IMPL(param_2 + 0x6c8 + lVar4);
    *(undefined8 *)(param_2 + 0x630 + lVar4) = 0;
  }
  if (param_3 != 0) {
    param_2 = param_2 + uVar3 * 0x100;
    if (*(long *)(param_2 + 0x648) != 0) {
      memdescFree();
      memdescDestroy(*(undefined8 *)(param_2 + 0x648));
      *(undefined8 *)(param_2 + 0x648) = 0;
    }
  }
  return 0;
}


// ===== 002ccd20 kbusStatePreUnload_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbusStatePreUnload_GM107(long param_1,long param_2,uint param_3)

{
  if (((param_3 & 1) == 0) && (*(int *)(param_1 + 0x4b34) != 1)) {
    kbusDestroyBar1_GM107(param_1,param_2,0);
    (**(code **)(param_2 + 0x4e0))(param_1);
    return 0;
  }
  return 0;
}


// ===== 002ccd70 kbusInitBar1_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

ulong kbusInitBar1_GM107(long param_1,long param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  long local_48;
  long local_40 [2];
  
  uVar9 = (ulong)param_3;
  lVar10 = uVar9 * 0x100;
  lVar7 = param_2 + lVar10;
  uVar5 = *(undefined8 *)(g_pSys + 0x230);
  local_48 = 0;
  if (*(long *)(lVar7 + 0x630) != 0) {
    return 0;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x7a4);
  *(ulong *)(lVar7 + 0x610) = uVar9;
  lVar11 = *(long *)(lVar7 + 0x620);
  uVar4 = vmmCreateVaspace_IMPL
                    (uVar5,0x90f1,0,1 << ((byte)uVar1 & 0x1f),0,lVar11 + -1,0,0,0,
                     (-(uint)(param_3 == 0) & 0x80000000) + 0x84080081,param_2 + 0x630 + lVar10);
  if (uVar4 != 0) {
    nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x3dd,"kbusInitBar1_GM107",4,
                 "NVRM: Could not construct BAR1 VA space object.\n");
    *(undefined8 *)(lVar7 + 0x630) = 0;
    return (ulong)uVar4;
  }
  uVar5 = portMemAllocatorGetGlobalNonPaged();
  reusemappingdbInit(param_2 + 0x650 + lVar10,uVar5,param_2 + 0x610 + lVar10,_kbusInternalBar1Map,
                     _kbusInternalBar1Unmap,0);
  uVar5 = portMemAllocatorGetGlobalNonPaged();
  mapInit_IMPL(param_2 + 0x6a8 + lVar10,uVar5,0x38);
  uVar5 = portMemAllocatorGetGlobalNonPaged();
  mapInit_IMPL(param_2 + 0x6c8 + lVar10,uVar5,8);
  lVar10 = (**(code **)(**(long **)(lVar7 + 0x630) + 0x90))();
  lVar11 = lVar11 + -0x1001;
  uVar4 = (**(code **)(lVar10 + 0x48))(lVar10,0,lVar11,*(code **)(lVar10 + 0x48));
  if (uVar4 == 0) {
    *(long *)(lVar7 + 0x628) = lVar11;
    uVar8 = *(ulong *)(lVar7 + 0x620);
    uVar6 = kbusGetPciBarSize_IMPL(param_2,1);
    if (uVar6 < uVar8) {
      nvAssertFailedNoLog("pKernelBus->bar1[gfid].apertureLength <= kbusGetPciBarSize(pKernelBus, 1)"
                          ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x40a);
    }
    if (param_3 == 0) {
      if (*(char *)(param_2 + 0xad0a) == '\0') {
        lVar7 = *(long *)(param_1 + 7000);
        iVar2 = *(int *)(lVar7 + 0x3c8);
      }
      else {
        local_40[0] = 0;
        lVar7 = memmgrGetReservedConsoleMemDesc_IMPL(param_1,*(undefined8 *)(param_1 + 0x1b78));
        if (lVar7 == 0) {
          nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x458,"kbusInitBar1_GM107"
                       ,4,"NVRM: no console memdesc available to preserve\n");
          uVar8 = 0;
          goto LAB_002cd053;
        }
        local_48 = *(long *)(lVar7 + 0x30);
        nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x432,"kbusInitBar1_GM107",1
                     ,"NVRM: preserving console BAR1 mapping (0x%llx)\n");
        uVar8 = kbusMapFbApertureSingle_IMPL(param_1,param_2,lVar7,0,local_40,&local_48,0x460,0);
        uVar4 = (uint)uVar8;
        if (uVar4 != 0) {
          nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x43c,"kbusInitBar1_GM107"
                       ,4,"NVRM: cannot preserve console mapping in BAR1 (0x%llx, 0x%x)\n",local_48,
                       uVar8);
          goto LAB_002cd03d;
        }
        if (local_40[0] != 0) {
          nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x44a,"kbusInitBar1_GM107"
                       ,4,"NVRM: expected console @ BAR1 offset 0 (0x%llx, 0x%x)\n",local_40[0],0);
          kbusUnmapFbApertureSingle_IMPL(param_1,param_2,lVar7,local_40[0],local_48,0xa0);
          uVar8 = uVar8 & 0xffffffff;
          goto LAB_002cd053;
        }
        *(undefined1 *)(param_2 + 0xad0b) = 1;
        lVar7 = *(long *)(param_1 + 7000);
        iVar2 = *(int *)(lVar7 + 0x3c8);
      }
      if (((iVar2 != 1) &&
          (((*(char *)(lVar7 + 0x3a9) == '\0' || (*(char *)(lVar7 + 0x3aa) == '\0')) &&
           (*(char *)(param_2 + 0xad01) == '\0')))) &&
         (uVar4 = (**(code **)(param_2 + 0x250))(param_1,param_2,0,lVar11), uVar4 != 0))
      goto LAB_002cd03d;
    }
    uVar4 = (**(code **)(param_2 + 0x308))
                      (param_1,param_2,uVar9,local_48,*(undefined8 *)(param_2 + 0xabc8));
    if (uVar4 == 0) {
      uVar4 = (**(code **)(param_2 + 0x310))
                        (param_1,param_2,uVar9,
                         local_48 + 0x1fffffff + *(long *)(param_2 + 0xabc8) & 0xffffffffe0000000);
      if (uVar4 == 0) goto LAB_002ccf98;
      nvAssertOkFailedNoLog
                (uVar4,"kbusEnableStaticBar1Mapping_HAL(pGpu, pKernelBus, gfid, bar1Offset)",
                 "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x48d);
    }
    else if (uVar4 == 0x56) {
LAB_002ccf98:
      uVar4 = (**(code **)(param_2 + 0x4f0))(param_1,param_2);
      if (uVar4 == 0) {
        (**(code **)(param_2 + 0x200))(param_1,param_2);
        uVar5 = *(undefined8 *)(param_2 + 0xabc0);
        uVar3 = *(undefined8 *)(param_2 + 0xabc8);
        lVar7 = gpumgrGetParentGPU(param_1);
        uVar8 = 0;
        if ((param_1 == lVar7) && (*(char *)(param_2 + 0xad01) == '\0')) {
          lVar7 = *(long *)(&DAT_00001b90 + param_1);
          *(undefined8 *)(lVar7 + 0xabc0) = uVar5;
          *(undefined8 *)(lVar7 + 0xabc8) = uVar3;
        }
        goto LAB_002cd053;
      }
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x3fc,"kbusInitBar1_GM107",4,
                 "NVRM: Unable to set BAR1 alloc range to aperture size!\n");
  }
LAB_002cd03d:
  kbusDestroyBar1_GM107(param_1,param_2,uVar9);
  uVar8 = (ulong)uVar4;
LAB_002cd053:
  *(undefined4 *)(param_1 + 0x930) = 0;
  return uVar8;
}


// ===== 002cd2c0 kbusDestroyBar2_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

short kbusDestroyBar2_GM107(long param_1,long param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  short sVar3;
  
  if (*(char *)(param_1 + 0x4a4e) == '\0') {
LAB_002cd30d:
    if (*(char *)(param_1 + 0x908) == '\0') {
      if (*(char *)(param_1 + 0x4913) == '\0') goto LAB_002cd329;
    }
    else if (*(char *)(param_1 + 0x4913) == '\0') {
      return 0;
    }
    cVar1 = *(char *)(param_1 + 0x491e);
  }
  else {
    if (*(char *)(param_1 + 0x4913) != '\0') {
      vgpuGspTeardownBuffers();
      goto LAB_002cd30d;
    }
    cVar1 = *(char *)(param_1 + 0x908);
  }
  if (cVar1 != '\0') {
    return 0;
  }
LAB_002cd329:
  iVar2 = (**(code **)(param_2 + 0x238))(param_1,param_2,param_3);
  sVar3 = -(ushort)(iVar2 != 0);
  if ((((*(char *)(param_1 + 0x908) == '\0') ||
       ((*(char *)(param_1 + 0x4913) != '\0' && (*(char *)(param_1 + 0x491e) == '\0')))) &&
      (*(long *)(param_2 + 0x46b0 + (ulong)param_3 * 0xd8) != 0)) &&
     (iVar2 = kbusTeardownBar2GpuVaSpace_GM107_part_0(param_1,param_2,param_3), iVar2 != 0)) {
    sVar3 = -1;
  }
  if (param_3 == 0) {
    *(undefined1 *)(param_2 + 0xad05) = 0;
  }
  if ((*(char *)(param_1 + 0x4921) != '\0') && (*(char *)(param_1 + 0x44d) == '\0')) {
    kbusSendSysmembar_IMPL(param_1,param_2);
    kbusSendSysmembar_IMPL(param_1,param_2);
  }
  if (*(char *)(param_1 + 0x4a4e) != '\0') {
    if (*(char *)(param_1 + 0x4913) != '\0') {
      if ((*(char *)(param_2 + 0xad08) != '\0') &&
         ((**(code **)(param_2 + 0x470))(param_1,param_2), param_3 != 0)) {
        nvAssertFailedNoLog("IS_GFID_PF(gfid)","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                            0x5b8);
      }
      vgpuGspSetupBuffers(param_1);
      return sVar3;
    }
    return sVar3;
  }
  return sVar3;
}


// ===== 002cd460 kbusSetupBar2CpuAperture_GM107 =====

undefined4 kbusSetupBar2CpuAperture_GM107(long param_1,long param_2,int param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  
  if (*(char *)(param_1 + 0x908) == '\0') {
    if (param_3 != 0) {
      return 0;
    }
    if (*(char *)(param_1 + 0x4913) == '\0') goto LAB_002cd49d;
  }
  else {
    if (*(char *)(param_1 + 0x4913) == '\0') {
      return 0;
    }
    if (param_3 != 0) {
      return 0;
    }
  }
  if (*(char *)(param_1 + 0x491e) != '\0') {
    return 0;
  }
LAB_002cd49d:
  if (*(long *)(param_2 + 0x7c98) == 0) {
    if (*(long *)(param_2 + 0x4668) != 0) {
      if ((*(char *)(param_1 + 0x44d) == '\0') || (uVar3 = 0, *(char *)(param_1 + 0x4921) != '\0'))
      {
        if (*(long *)(param_2 + 0x4610) == 0) {
          nvAssertFailedNoLog("pKernelBus->bar2[gfid].physAddr != 0",
                              "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x5ec);
          uVar3 = 0x40;
        }
        else {
          iVar1 = osMapPciMemoryKernelOld
                            (param_1,*(long *)(param_2 + 0x4610),*(long *)(param_2 + 0x4648) + 1,3,
                             param_2 + 0x7c98,2);
          if (iVar1 != 0) {
            nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x5f8,
                         "kbusSetupBar2CpuAperture_GM107",4,"NVRM: - Unable to map bar2!\n");
            return 0xffff;
          }
          if (*(char *)(param_1 + 0x446) == '\0') {
            uVar2 = 1;
          }
          else {
            uVar2 = 2;
          }
          nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x5fd,
                       "kbusSetupBar2CpuAperture_GM107",uVar2,
                       "NVRM: BAR0 Base Cpu Mapping @ 0x%p and BAR2 Base Cpu Mapping @ 0x%p\n",
                       *(undefined8 *)(param_1 + 0x938),*(undefined8 *)(param_2 + 0x7c98));
          uVar3 = 0;
        }
      }
      return uVar3;
    }
    nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x5df,
                 "kbusSetupBar2CpuAperture_GM107",4,
                 "NVRM: BAR2 pteBase not initialized by fbPreInit_FERMI!\n");
  }
  else {
    nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x5d9,
                 "kbusSetupBar2CpuAperture_GM107",4,"NVRM: BAR2 already initialized!\n");
  }
  return 0xffff;
}


// ===== 002cd670 kbusTeardownBar2CpuAperture_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbusTeardownBar2CpuAperture_GM107(long param_1,long param_2,int param_3)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 0x908) == '\0') {
    if (*(char *)(param_1 + 0x4913) == '\0') goto joined_r0x002cd73a;
  }
  else if (*(char *)(param_1 + 0x4913) == '\0') {
    return 0;
  }
  if (*(char *)(param_1 + 0x491e) != '\0') {
    return 0;
  }
joined_r0x002cd73a:
  if (param_3 != 0) {
    return 0;
  }
  if (*(long *)(param_2 + 0x7c78) != 0) {
    memmgrMemDescEndTransfer_IMPL
              (*(undefined8 *)(param_1 + 0x1b78),*(undefined8 *)(param_2 + 0x7c70));
    *(undefined8 *)(param_2 + 0x7c78) = 0;
  }
  (**(code **)(param_2 + 0x230))(param_1,param_2);
  kbusFlushVirtualBar2_VBAR2(param_1,param_2,0,0);
  if (*(long *)(param_2 + 0x7c98) != 0) {
    osUnmapPciMemoryKernelOld(param_1);
    *(undefined8 *)(param_2 + 0x7c98) = 0;
  }
  if (*(char *)(param_1 + 0x44d) == '\0') {
    uVar1 = regRead032(param_1 + 0x3a18,0,0,0x1714,0);
    regWrite032(param_1 + 0x3a18,0,0,0x1714,uVar1 & 0x7fffffff,0);
    regRead032(param_1 + 0x3a18,0,0,0x1714,0);
    return 0;
  }
  return 0;
}


// ===== 002cd7a0 kbusSetupBar0WindowBeforeBar2Bootstrap_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusSetupBar0WindowBeforeBar2Bootstrap_GM107(long param_1,long param_2,undefined8 *param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  if (*(char *)(param_2 + 0xad0c) != '\0') {
    return 0;
  }
  if ((*(char *)(param_1 + 0x454) == '\0') || (*(char *)(param_1 + 0x4915) == '\0')) {
    if (*(int *)(param_2 + 0xad34) == 2) {
      uVar3 = (**(code **)(param_2 + 0x438))(param_1,param_2);
      *param_3 = uVar3;
      iVar2 = (**(code **)(param_2 + 0x430))
                        (param_1,param_2,*(ulong *)(param_2 + 0x4658) & 0xffffffffffff0000);
      if (iVar2 != 0) {
        nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                            0x85f);
        return iVar2;
      }
      lVar1 = *(long *)(param_2 + 0x4658);
      lVar4 = (**(code **)(param_2 + 0x438))(param_1,param_2);
      *(long *)(param_2 + 0x4618) = (lVar1 + 0x700000) - lVar4;
    }
    else if (*(int *)(param_2 + 0xad2c) == 2) {
      nvAssertFailedNoLog("ADDR_FBMEM == pKernelBus->PDEBAR2Aperture",
                          "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x857);
      return 0x56;
    }
    *(undefined1 *)(param_2 + 0x46a8) = 1;
    iVar2 = 0;
  }
  else {
    nvAssertFailedNoLog("!KBUS_BAR0_PRAMIN_DISABLED(pGpu)",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x850);
    iVar2 = 0x40;
  }
  return iVar2;
}


// ===== 002cd900 kbusRestoreBar0WindowAfterBar2Bootstrap_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void kbusRestoreBar0WindowAfterBar2Bootstrap_GM107(long param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  
  if (*(char *)(param_2 + 0xad0c) != '\0') {
    return;
  }
  if ((*(char *)(param_1 + 0x454) != '\0') && (*(char *)(param_1 + 0x4915) != '\0')) {
    nvAssertFailedNoLog("!KBUS_BAR0_PRAMIN_DISABLED(pGpu)",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x882);
    return;
  }
  if (*(char *)(param_2 + 0x46a8) == '\0') {
    nvAssertFailedNoLog("pKernelBus->bar2[GPU_GFID_PF].bBootstrap",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x884);
  }
  *(undefined1 *)(param_2 + 0x46a8) = 0;
  if ((*(int *)(param_2 + 0xad34) != 2) && (*(int *)(param_2 + 0xad2c) != 2)) {
    return;
  }
  iVar1 = (**(code **)(param_2 + 0x430))
                    (param_1,param_2,param_3,param_2,param_3,*(code **)(param_2 + 0x430));
  if (iVar1 != 0) {
    nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x88c);
  }
  *(undefined8 *)(param_2 + 0x4618) = 0;
  return;
}


// ===== 002cda10 kbusUpdateRmAperture_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusUpdateRmAperture_GM107
              (long param_1,long param_2,undefined8 *param_3,ulong param_4,ulong param_5,
              uint param_6)

{
  uint *puVar1;
  int *piVar2;
  long lVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  char *pcVar13;
  ulong uVar14;
  undefined4 local_134;
  char local_109;
  uint local_108;
  int local_104;
  undefined8 local_100;
  undefined8 local_f8;
  int **local_f0;
  code *local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  long local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined1 local_a8 [48];
  int *local_78;
  ulong local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar11 = *(long *)(param_1 + 0x1b98);
  local_f8 = 0;
  local_f0 = (int **)0x0;
  local_e8 = (code *)0x0;
  local_e0 = 0;
  local_78 = (int *)0x0;
  local_70 = 0;
  local_68 = (undefined1 *)0x0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_d8 = 0;
  local_d0 = 0;
  local_c8 = 0;
  local_c0 = 0;
  local_b8 = 0;
  local_b0 = 0;
  local_100 = 0;
  if ((param_6 & 8) != 0) {
    iVar6 = vgpuGetCallingContextGfid(param_1,&local_108);
    if (iVar6 != 0) {
      nvAssertOkFailedNoLog
                (iVar6,"vgpuGetCallingContextGfid(pGpu, &gfid)",
                 "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xa20);
      return iVar6;
    }
    iVar6 = vgpuIsCallingContextPlugin(param_1,&local_109);
    if (iVar6 != 0) {
      nvAssertOkFailedNoLog
                (iVar6,"vgpuIsCallingContextPlugin(pGpu, &bCallingContextPlugin)",
                 "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xa21);
      return iVar6;
    }
    if (local_109 == '\0') goto joined_r0x002cdf0b;
  }
  local_108 = 0;
joined_r0x002cdf0b:
  if ((param_5 == 0) || (uVar14 = (ulong)((uint)param_5 & 0xfff), (param_5 & 0xfff) != 0)) {
    nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xa2b,
                 "kbusUpdateRmAperture_GM107",4,"NVRM: unsupported VA size (0x%llx)\n",param_5);
    return 0x1f;
  }
  if (((param_6 & 2) != 0) && ((param_6 & 4) == 0)) {
    return 0;
  }
  uVar9 = memdescGetMemDescFromGpu(param_3,param_1);
  cVar5 = '\x01';
  if (local_108 == 0) {
    iVar6 = memdescGetAddressSpace(uVar9,uVar9,1);
    cVar5 = (iVar6 == 2) + '\x01';
  }
  dmaPageArrayInitFromMemDesc(local_a8,uVar9,cVar5);
  local_b0 = CONCAT44(local_b0._4_4_,local_108);
  local_d0 = param_1;
  iVar6 = mmuWalkSetUserCtx(*(undefined8 *)(param_2 + 0x46b0 + (ulong)local_108 * 0xd8),&local_d8);
  uVar9 = 0xa48;
  pcVar13 = "mmuWalkSetUserCtx(pKernelBus->bar2[gfid].pWalk, &userCtx)";
  if (iVar6 == 0) {
    uVar12 = param_4 & 0xfffffffffffff000;
    lVar10 = (param_4 + 0xfff + param_5 & 0xfffffffffffff000) - 1;
    if ((param_6 & 4) == 0) {
      piVar2 = *(int **)(param_2 + 0x46c0 + (ulong)local_108 * 0xd8);
      if (piVar2 == (int *)0x0) {
        nvCheckFailedNoLog(4,"pFmt != NULL","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xa5c
                          );
        return 0x1f;
      }
      local_f8 = mmuFmtFindLevelWithPageShift
                           (*(undefined8 *)(piVar2 + 2),0xc,
                            "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c");
      local_e8 = _kbusWalkCBMapNextEntries_RmAperture;
      local_f0 = &local_78;
      local_78 = piVar2;
      uVar7 = kgmmuGetMemAperture_IMPL(lVar11,param_3);
      local_70 = CONCAT44(local_70._4_4_,uVar7);
      local_68 = local_a8;
      lVar3 = *(long *)(piVar2 + 8);
      puVar1 = (uint *)((long)&local_50 + (ulong)*(ushort *)(lVar3 + 0xe));
      *puVar1 = (uint)(*(byte *)(lVar3 + 0x10) ^ 1) << ((byte)*(undefined2 *)(lVar3 + 0xc) & 0x1f) |
                *puVar1 & *(uint *)(lVar3 + 8);
      if (*piVar2 == 3) {
        local_104 = 0;
        cVar5 = memdescGetVolatility(param_3);
        uVar9 = 0x120;
        if (cVar5 == '\0') {
          if ((int)local_70 != 1) {
            nvAssertFailedNoLog("mapIter.aperture == GMMU_APERTURE_VIDEO",
                                "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xa7d);
          }
          uVar9 = 0x100;
        }
        iVar6 = (**(code **)(lVar11 + 0x280))(lVar11,uVar9,&local_104);
        if (iVar6 != 0) {
          nvAssertFailedNoLog("kgmmuTranslatePtePcfFromSw_HAL(pKernelGmmu, ptePcfSw, &ptePcfHw) == NV_OK"
                              ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xa82);
          return 0x1f;
        }
        lVar11 = *(long *)(piVar2 + 8);
        puVar1 = (uint *)((long)&local_50 + (ulong)*(ushort *)(lVar11 + 0x1aa));
        *puVar1 = local_104 << ((byte)*(undefined2 *)(lVar11 + 0x1a8) & 0x1f) |
                  *puVar1 & *(uint *)(lVar11 + 0x1a4);
      }
      else {
        bVar4 = memdescGetVolatility(param_3);
        lVar11 = *(long *)(piVar2 + 8);
        *(uint *)((long)&local_50 + (ulong)*(ushort *)(lVar11 + 0x106)) =
             (uint)(bVar4 ^ *(byte *)(lVar11 + 0x108)) <<
             ((byte)*(undefined2 *)(lVar11 + 0x104) & 0x1f) |
             *(uint *)((long)&local_50 + (ulong)*(ushort *)(lVar11 + 0x106)) &
             *(uint *)(lVar11 + 0x100);
      }
      lVar11 = *(long *)(piVar2 + 8);
      puVar1 = (uint *)((long)&local_50 + (ulong)*(ushort *)(lVar11 + 0x22));
      *puVar1 = (uint)*(byte *)(*(long *)(lVar11 + 0x28) + 1 + (local_70 & 0xffffffff) * 2) <<
                ((byte)*(undefined2 *)(lVar11 + 0x20) & 0x1f) | *puVar1 & *(uint *)(lVar11 + 0x1c);
      lVar11 = *(long *)(piVar2 + 8);
      local_134 = 0;
      if (*(byte *)(lVar11 + 0x24) != 0) {
        do {
          if ((*(char *)(*(long *)(lVar11 + 0x28) + uVar14 * 2) != '\0') &&
             ((*(uint *)((long)&local_50 + (ulong)*(ushort *)(lVar11 + 0x22)) &
              *(uint *)(lVar11 + 0x18)) >> ((byte)*(undefined2 *)(lVar11 + 0x20) & 0x1f) ==
              (uint)*(byte *)(*(long *)(lVar11 + 0x28) + 1 + uVar14 * 2))) {
            local_134 = (undefined4)uVar14;
            break;
          }
          uVar14 = uVar14 + 1;
        } while ((uint)uVar14 < (uint)*(byte *)(lVar11 + 0x24));
      }
      local_40 = gmmuFmtPtePhysAddrFld(lVar11,local_134,0);
      iVar6 = memdescGetPteKindForGpu(param_3,*param_3);
      lVar11 = *(long *)(piVar2 + 8);
      puVar1 = (uint *)((long)&local_50 + (ulong)*(ushort *)(lVar11 + 0x186));
      *puVar1 = *puVar1 & *(uint *)(lVar11 + 0x180) |
                iVar6 << ((byte)*(undefined2 *)(lVar11 + 0x184) & 0x1f);
      if (((*(int *)(param_2 + 0xad34) == 2) || (*(int *)(param_2 + 0xad2c) == 2)) ||
         (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) != '\0')) {
        uVar14 = (ulong)local_108;
        if (((*(char *)(param_2 + 0xad08) == '\0') &&
            (*(long *)(param_2 + 0x7c78 + uVar14 * 0xb0) == 0)) && (local_108 == 0)) {
          iVar6 = (**(code **)(param_2 + 0x440))(param_1,param_2,&local_100);
          if (iVar6 != 0) {
            nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c"
                                ,0xaac);
            return iVar6;
          }
          uVar14 = (ulong)local_108;
        }
      }
      else {
        uVar14 = (ulong)local_108;
      }
      iVar8 = mmuWalkMap(*(undefined8 *)(param_2 + 0x46b0 + uVar14 * 0xd8),uVar12,lVar10,&local_f8);
      if (iVar8 != 0) {
        nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                            0xaaf);
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xa4c,
                   "kbusUpdateRmAperture_GM107",1,
                   "NVRM: mmuWalkSparsify pwalk=%p, vaLo=%llx, vaHi = %llx\n",
                   *(undefined8 *)(param_2 + 0x46b0 + (ulong)local_108 * 0xd8),uVar12,lVar10);
      iVar8 = mmuWalkSparsify(*(undefined8 *)(param_2 + 0x46b0 + (ulong)local_108 * 0xd8),uVar12,
                              lVar10,0);
      if (iVar8 != 0) {
        nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xa53,
                     "kbusUpdateRmAperture_GM107",4,
                     "NVRM: mmuWalkSparsify status=%x pwalk=%p, vaLo=%llx, vaHi = %llx\n",iVar8,
                     *(undefined8 *)(param_2 + 0x46b0 + (ulong)local_108 * 0xd8),uVar12,lVar10);
      }
    }
    iVar6 = mmuWalkSetUserCtx(*(undefined8 *)(param_2 + 0x46b0 + (ulong)local_108 * 0xd8),0);
    if (iVar6 == 0) {
      if ((*(char *)(param_2 + 0x46a8 + (ulong)local_108 * 0xd8) != '\0') &&
         (*(char *)(param_2 + 0xad08) == '\0')) {
        (**(code **)(param_2 + 0x448))(param_1,param_2,local_100);
      }
      if ((param_6 & 1) != 0) {
        osFlushCpuWriteCombineBuffer();
        if (*(long *)(param_2 + 0xad20) == 0) {
          kbusSendSysmembar_IMPL(param_1,param_2);
        }
        else {
          uVar7 = memdescGetAddressSpace
                            (*(undefined8 *)(param_2 + 0x7c90 + (ulong)local_108 * 0xb0));
          uVar7 = kbusGetFlushAperture_IMPL(param_2,uVar7);
          (**(code **)(param_2 + 0x500))(param_1,param_2,uVar7);
        }
        lVar11 = (ulong)local_108 * 0xb0 + *(long *)(&DAT_00001b90 + param_1);
        (**(code **)(*(long *)(param_1 + 0x1b98) + 0x1e8))
                  (param_1,*(long *)(param_1 + 0x1b98),*(undefined8 *)(lVar11 + 0x7ca8),
                   *(undefined4 *)(lVar11 + 0x7ca4),1,0,2,0);
        return iVar8;
      }
      return iVar8;
    }
    uVar9 = 0xab2;
    pcVar13 = "mmuWalkSetUserCtx(pKernelBus->bar2[gfid].pWalk, NULL)";
  }
  nvAssertOkFailedNoLog(iVar6,pcVar13,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",uVar9);
  return iVar6;
}


// ===== 002ce3b0 kbusGetBar1VASpace_GM107 =====

undefined8 kbusGetBar1VASpace_GM107(undefined8 param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = _kbusGetCurrentGfid_isra_0();
  if (uVar1 != 0xffffffff) {
    return *(undefined8 *)(param_2 + 0x630 + (ulong)uVar1 * 0x100);
  }
  return 0;
}


// ===== 002ce3f0 kbusUnmapFbAperture_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusUnmapFbAperture_GM107
              (long param_1,long param_2,undefined8 *param_3,undefined8 *param_4,ulong param_5,
              uint param_6)

{
  int *piVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined8 *puVar8;
  long *plVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  undefined8 *local_48;
  ulong local_40;
  
  local_48 = param_4;
  local_40 = param_5;
  uVar5 = _kbusGetCurrentGfid_isra_0();
  if (uVar5 == 0xffffffff) {
    nvAssertFailedNoLog("gfid != INVALID_P2P_GFID",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xc72);
    return 0x40;
  }
  puVar8 = (undefined8 *)memdescGetRootMemDesc(param_3,0);
  iVar6 = memdescGetPteKindForGpu(puVar8,*puVar8);
  iVar7 = memdescGetPteKindForGpu(param_3,*param_3);
  if (iVar7 != iVar6) {
    puVar8 = param_3;
  }
  iVar6 = (**(code **)(param_2 + 0x330))(param_1,param_2,puVar8,&local_48);
  if (iVar6 != 0) {
    if (iVar6 == 0x56) {
      if ((param_6 & 0x200) != 0) {
        lVar11 = *(long *)(param_1 + 0x1bb8);
        uVar4 = *(undefined8 *)(param_2 + 0x630 + (ulong)uVar5 * 0x100);
        memdescFlushCpuCaches(param_1,puVar8);
        (**(code **)(lVar11 + 0x170))(param_1,lVar11,uVar4,*local_48,puVar8,0,0);
        kbusUpdateRusdStatistics_IMPL(param_1);
        return 0;
      }
      lVar11 = (ulong)uVar5 * 0x100;
      plVar9 = (long *)mapFind_IMPL(param_2 + 0x6c8 + lVar11,*local_48);
      if (plVar9 == (long *)0x0) {
        nvAssertOkFailedNoLog
                  (0x40,"ppMappingType != NULL","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                   0xc9d);
        kbusUpdateRusdStatistics_IMPL(param_1);
      }
      else {
        lVar3 = *plVar9;
        lVar2 = param_2 + 0x6a8 + lVar11;
        lVar10 = mapFind_IMPL(lVar2,puVar8);
        if (lVar10 != 0) {
          uVar12 = 0;
          if (local_40 != 0) {
            do {
              uVar13 = uVar12 + 1;
              reusemappingdbUnmap(param_2 + 0x650 + lVar11,lVar3,local_48[uVar12 * 2],
                                  (local_48 + uVar12 * 2)[1]);
              uVar12 = uVar13;
            } while (uVar13 < local_40);
          }
          piVar1 = (int *)(lVar3 + 0x10);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            mapRemove_IMPL(lVar10,lVar3);
          }
          iVar6 = mapCount_IMPL(lVar10);
          if (iVar6 == 0) {
            memdescRemoveDestroyCallback(puVar8,lVar10 + 0x20);
            mapDestroy_IMPL(lVar10);
            mapRemove_IMPL(lVar2,lVar10);
            kbusUpdateRusdStatistics_IMPL(param_1);
            iVar6 = 0;
          }
          else {
            iVar6 = 0;
            kbusUpdateRusdStatistics_IMPL(param_1);
          }
          goto LAB_002ce557;
        }
        nvAssertOkFailedNoLog
                  (0x40,"pSubmap != NULL","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xca2);
        kbusUpdateRusdStatistics_IMPL(param_1);
      }
      iVar6 = 0x40;
      goto LAB_002ce557;
    }
    nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xc89,
                 "kbusUnmapFbAperture_GM107",4,"NVRM: static BAR1 reported error\n");
  }
  kbusUpdateRusdStatistics_IMPL(param_1);
  if ((param_6 & 0x200) != 0) {
    return iVar6;
  }
LAB_002ce557:
  portMemFree(local_48);
  return iVar6;
}


// ===== 002ce700 kbusFlush_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusFlush_GM107(long param_1)

{
  int iVar1;
  
  if ((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(param_1 + 0x4913) == '\0')) {
    return 0;
  }
  iVar1 = (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x3d8))();
  if (iVar1 != 0x65) {
    iVar1 = 0;
  }
  return iVar1;
}


// ===== 002ce750 _kbusMapAperture_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _kbusMapAperture_GM107
              (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5,undefined8 param_6,undefined8 *param_7,undefined4 param_8,
              undefined4 param_9)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 local_40 [2];
  
  uVar2 = kbusConvertBusMapFlagsToDmaFlags_IMPL(param_2,param_3,param_8);
  lVar1 = *(long *)(param_1 + 0x1bb8);
  iVar3 = memdescCreateSubMem(local_40,param_3,param_1,param_5,*param_7);
  if (iVar3 == 0) {
    iVar3 = (**(code **)(lVar1 + 0x168))
                      (param_1,lVar1,param_4,local_40[0],param_6,uVar2,0,0,param_9);
    memdescFree(local_40[0]);
    memdescDestroy(local_40[0]);
  }
  return iVar3;
}


// ===== 002ce810 _kbusInternalBar1Map =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _kbusInternalBar1Map
              (long *param_1,undefined8 *param_2,long param_3,ulong param_4,ulong param_5,
              undefined8 param_6,code *param_7)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  undefined8 *puVar7;
  long *plVar8;
  long lVar9;
  ulong uVar10;
  undefined8 local_48;
  ulong local_40 [2];
  
  lVar9 = 0;
  plVar8 = param_1 + *param_1 * -0x20;
  if (plVar8 != (long *)0x610) {
    lVar9 = plVar8[-0x98];
  }
  lVar5 = gpuEngineGetGpu(lVar9);
  lVar9 = param_1[4];
  lVar3 = *(long *)(lVar5 + 0x1bb8);
  uVar1 = *(undefined4 *)(param_2 + 1);
  uVar2 = *(undefined4 *)((long)param_2 + 0xc);
  uVar6 = osGetPageSize();
  if (param_4 == 0) {
    iVar4 = 0;
  }
  else {
    uVar10 = param_4;
    while( true ) {
      while( true ) {
        if (param_4 < uVar10) {
          uVar10 = param_4;
        }
        local_40[0] = uVar10;
        iVar4 = _kbusMapAperture_GM107
                          (lVar5,plVar8 + -0xc2,*param_2,lVar9,param_3,&local_48,local_40,uVar1,
                           uVar2);
        if (iVar4 == 0) break;
        nvCheckOkFailedNoLog
                  (1,iVar4,
                   "_kbusMapAperture_GM107(pGpu, pKernelBus, pType->pMemDesc, pVAS, physRange.start, &mapRange.start, &mapRange.size, mapFlags, swizzId)"
                   ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xb26);
        if (uVar6 == uVar10) {
          nvCheckFailedNoLog(1,"pageSize != curMappingSize",
                             "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xb2b);
          return iVar4;
        }
        if ((param_5 & 1) != 0) {
          nvCheckFailedNoLog(1,"!(cachingFlags & REUSE_MAPPING_DB_MAP_FLAGS_SINGLE_RANGE)",
                             "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xb2c);
          return iVar4;
        }
        uVar10 = -uVar6 & ((uVar10 >> 1) - 1) + uVar6;
      }
      puVar7 = (undefined8 *)mapInsertNew_IMPL(param_1 + 0x17,local_48);
      if (puVar7 == (undefined8 *)0x0) break;
      *puVar7 = param_2;
      iVar4 = (*param_7)(param_6,param_3,local_48,uVar10);
      if (iVar4 != 0) {
        nvAssertOkFailedNoLog
                  (iVar4,"pCallback(pToken, physRange.start, mapRange.start, curMappingSize)",
                   "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xb37);
        mapRemove_IMPL(param_1 + 0x17,puVar7);
        goto LAB_002ce9cd;
      }
      param_4 = param_4 - uVar10;
      if (param_4 == 0) {
        return 0;
      }
      param_3 = param_3 + uVar10;
    }
    nvAssertOkFailedNoLog
              (0x51,"ppVaToType != NULL","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xb34);
    iVar4 = 0x51;
LAB_002ce9cd:
    (**(code **)(lVar3 + 0x170))(lVar5,lVar3,lVar9,local_48,*param_2,0,0);
  }
  return iVar4;
}


// ===== 002ceaa0 kbusMapFbAperture_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusMapFbAperture_GM107
              (long param_1,long param_2,undefined8 *param_3,long param_4,undefined8 param_5,
              long *param_6,uint param_7,long param_8)

{
  undefined8 uVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined8 *puVar9;
  long lVar10;
  undefined8 uVar11;
  long lVar12;
  ulong uVar13;
  long lVar14;
  uint local_a4;
  uint local_a0;
  ulong local_88;
  long local_80;
  long local_50;
  long local_48 [3];
  
  uVar4 = _kbusGetCurrentGfid_isra_0();
  local_50 = 0;
  uVar5 = param_7 >> 8 & 1 ^ 1;
  if ((*(char *)(param_2 + 0xad49) == '\0') || (uVar6 = 1, (char)uVar5 == '\0')) {
    uVar6 = uVar5 | 2;
  }
  uVar5 = (param_7 & 0x40) << 3 | param_7;
  if ((param_7 & 0xffffc001) != 0) {
    nvAssertFailedNoLog("(flags & BUS_MAP_FB_FLAGS_FERMI_INVALID) == 0",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xbbf);
  }
  if (((param_7 & 0x40) != 0) && (param_6[1] != 1)) {
    nvAssertFailedNoLog("!(flags & BUS_MAP_FB_FLAGS_MAP_OFFSET_FIXED) || pMemArea->numRanges == 1",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xbc0);
    return 0x1f;
  }
  if (uVar4 == 0xffffffff) {
    nvAssertFailedNoLog("gfid != INVALID_P2P_GFID",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xbc2);
    return 0x40;
  }
  uVar11 = *(undefined8 *)(param_2 + 0x630 + (ulong)uVar4 * 0x100);
  puVar9 = (undefined8 *)memdescGetRootMemDesc(param_3,&local_50);
  iVar7 = memdescGetPteKindForGpu(puVar9,*puVar9);
  iVar8 = memdescGetPteKindForGpu(param_3,*param_3);
  local_80 = param_4;
  if (iVar8 == iVar7) {
    local_80 = param_4 + local_50;
    param_3 = puVar9;
  }
  iVar7 = (**(code **)(param_2 + 0x338))(param_1,param_2,param_3,local_80,param_5,param_6,uVar5);
  if (iVar7 == 0) {
    return 0;
  }
  if (iVar7 != 0x56) {
    nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xbe1,"kbusMapFbAperture_GM107",
                 4,"NVRM: static BAR1 reported error\n");
    return iVar7;
  }
  cVar3 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_1 + 0x7a4));
  if (cVar3 == '\0') {
    nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(gpuGetInstance(pGpu))",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xbe6);
    return 0x2f;
  }
  if ((*(long *)(param_1 + 0x1bc0) == 0) ||
     (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar3 == '\0')) {
LAB_002cecb0:
    local_a4 = 0xffffffff;
    local_88 = 0xffffffff00000000;
  }
  else if (param_8 == 0) {
    if (param_3[0x14] == 0) goto LAB_002cecb0;
    uVar1 = *(undefined8 *)(param_1 + 0x1bc0);
    iVar7 = 0;
    while (((lVar12 = kmigmgrGetMIGGpuInstanceSlot_IMPL(param_1,uVar1,iVar7), lVar12 == 0 ||
            (*(char *)(lVar12 + 0x988) == '\0')) || (*(long *)(lVar12 + 0x980) != param_3[0x14]))) {
      iVar7 = iVar7 + 1;
      if (iVar7 == 8) {
        nvAssertFailedNoLog("pKernelMIGGPUInstance != NULL",
                            "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xc06);
        return 0x40;
      }
    }
    local_a4 = *(uint *)(lVar12 + 0x968);
    local_88 = (ulong)local_a4 << 0x20;
  }
  else {
    iVar7 = kmigmgrGetInstanceRefFromDevice_IMPL
                      (param_1,*(undefined8 *)(param_1 + 0x1bc0),param_8,local_48);
    if (iVar7 != 0) {
      nvAssertOkFailedNoLog
                (iVar7,"kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)",
                 "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xbf2);
      return iVar7;
    }
    local_a4 = *(uint *)(local_48[0] + 0x968);
    local_88 = (ulong)local_a4 << 0x20;
  }
  if ((param_7 & 0x40) != 0 || (param_7 & 0x200) != 0) {
    param_6[1] = 1;
    *(undefined8 *)(*param_6 + 8) = param_5;
    iVar7 = _kbusMapAperture_GM107
                      (param_1,param_2,param_3,uVar11,local_80,*param_6,*param_6 + 8,uVar5,local_a4)
    ;
    goto LAB_002cedb2;
  }
  lVar14 = (ulong)uVar4 * 0x100;
  lVar12 = param_2 + 0x6a8 + lVar14;
  lVar10 = mapFind_IMPL(lVar12,param_3);
  if (lVar10 == 0) {
    lVar10 = mapInsertNew_IMPL(lVar12,param_3);
    if (lVar10 == 0) {
      nvAssertFailedNoLog("pSubmap != NULL","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xc1f
                         );
      return 0x51;
    }
    uVar11 = portMemAllocatorGetGlobalNonPaged();
    mapInit_IMPL(lVar10,uVar11,0x18);
    *(code **)(lVar10 + 0x20) = _kbusDestroyMemdescBar1Cb;
    *(long *)(lVar10 + 0x28) = param_2 + 0x610 + lVar14;
    memdescAddDestroyCallback(param_3,lVar10 + 0x20);
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  local_a0 = param_7 & 0x1f;
  uVar13 = local_88 | param_7 & 0x1f;
  puVar9 = (undefined8 *)mapFind_IMPL(lVar10,uVar13);
  if (puVar9 == (undefined8 *)0x0) {
    puVar9 = (undefined8 *)mapInsertNew_IMPL(lVar10,uVar13);
    if (puVar9 != (undefined8 *)0x0) {
      *puVar9 = param_3;
      *(undefined4 *)(puVar9 + 2) = 0;
      *(uint *)(puVar9 + 1) = local_a0;
      local_88 = 1;
      *(uint *)((long)puVar9 + 0xc) = local_a4;
      goto LAB_002ced42;
    }
    nvAssertOkFailedNoLog
              (0x51,"pMappingType != NULL","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xc2d)
    ;
    iVar7 = 0x51;
LAB_002cf048:
    if (bVar2) {
      memdescRemoveDestroyCallback(param_3,lVar10 + 0x20);
      mapDestroy_IMPL(lVar10);
      mapRemove_IMPL(lVar12,lVar10);
    }
  }
  else {
LAB_002ced42:
    lVar14 = param_2 + 0x650 + lVar14;
    if ((param_7 & 0x100) == 0) {
LAB_002ced7c:
      iVar7 = reusemappingdbMap(lVar14,puVar9,local_80,param_5,param_6,uVar6);
      if (iVar7 != 0) {
        nvAssertOkFailedNoLog
                  (iVar7,
                   "reusemappingdbMap(&pBar1VaInfo->reuseDb, pMappingType, mapRange, pMemArea, cachingFlags)"
                   ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xc45);
        if ((char)local_88 != '\0') {
          mapRemove_IMPL(lVar10,puVar9);
        }
        goto LAB_002cf048;
      }
    }
    else {
      iVar8 = reusemappingdbMap(lVar14,puVar9,local_80,param_5,param_6,1);
      iVar7 = 0;
      if (iVar8 != 0) goto LAB_002ced7c;
    }
    *(int *)(puVar9 + 2) = *(int *)(puVar9 + 2) + 1;
  }
LAB_002cedb2:
  kbusUpdateRusdStatistics_IMPL(param_1);
  return iVar7;
}


// ===== 002cf0d0 kbusUnlinkP2P_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbusUnlinkP2P_GM107(undefined8 param_1,long param_2)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  
  uVar8 = 0;
  do {
    if ((*(int *)(param_2 + 0xaa40 + uVar8 * 4) != 0) ||
       (iVar6 = (**(code **)(param_2 + 0x300))(param_1,param_2,uVar8 & 0xffffffff), iVar6 != 0)) {
      lVar7 = gpumgrGetGpu(uVar8 & 0xffffffff);
      if (lVar7 == 0) {
        nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xe96,"kbusUnlinkP2P_GM107",
                     4,"NVRM: There is a P2P mapping involving an unloaded GPU\n");
      }
      else {
        lVar1 = *(long *)(&DAT_00001b90 + lVar7);
        cVar2 = gpuIsGpuFullPower_IMPL(lVar7);
        if ((cVar2 != '\0') && (*(char *)(lVar1 + 0xad00) != '\0')) {
          if (*(int *)(param_2 + 0xaa40 + uVar8 * 4) != 0) {
            uVar3 = (**(code **)(param_2 + 0x288))(param_1,param_2,lVar7);
            uVar4 = (**(code **)(lVar1 + 0x288))(lVar7,lVar1,param_1);
            uVar5 = *(uint *)(param_2 + 0xaa40 + uVar8 * 4);
            uVar5 = uVar5 - (uVar5 >> 1 & 0x55555555);
            uVar5 = (uVar5 & 0x33333333) + (uVar5 >> 2 & 0x33333333);
            if (((uVar5 >> 4) + uVar5 & 0xf0f0f0f) * 0x1010101 >> 0x18 != 1) {
              nvAssertFailedNoLog("nvPopCount32(pKernelBus->p2pPcie.peerNumberMask[i]) == 1",
                                  "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xea9);
            }
            if (7 < uVar3) {
              nvAssertFailedNoLog("locPeerId < P2P_MAX_NUM_PEERS",
                                  "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xeab);
            }
            if (7 < uVar4) {
              nvAssertFailedNoLog("remPeerId < P2P_MAX_NUM_PEERS",
                                  "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xeac);
            }
            if (*(uint *)(param_2 + 0xaac4 + (ulong)uVar3 * 0x20) != uVar4) {
              nvAssertFailedNoLog("pKernelBus->p2pPcie.busPeer[locPeerId].remotePeerId == remPeerId"
                                  ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xead);
            }
            kbusDestroyMailbox_IMPL(param_1,param_2,lVar7,(ulong)uVar3);
            kbusDestroyMailbox_IMPL(lVar7,lVar1,param_1,uVar4);
          }
          iVar6 = kbusSendMemsysDisableNvlinkPeers(param_1);
          if (iVar6 == 0) {
            iVar6 = kbusSendMemsysDisableNvlinkPeers(lVar7);
          }
          else {
            nvAssertOkFailedNoLog
                      (iVar6,"kbusSendMemsysDisableNvlinkPeers(pGpu)",
                       "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xeb6);
            iVar6 = kbusSendMemsysDisableNvlinkPeers(lVar7);
          }
          if (iVar6 != 0) {
            nvAssertOkFailedNoLog
                      (iVar6,"kbusSendMemsysDisableNvlinkPeers(pRemoteGpu)",
                       "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xeb7);
          }
        }
      }
    }
    uVar8 = uVar8 + 1;
  } while (uVar8 != 0x20);
  return;
}


// ===== 002cf3b0 kbusStateUnload_GM107 =====

undefined8 kbusStateUnload_GM107(long param_1,long param_2,ulong param_3)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 7000);
  if (*(char *)(param_1 + 0x908) == '\0') {
    if ((lVar1 != 0) && ((*(char *)(lVar1 + 0x3a9) == '\0' || (*(char *)(lVar1 + 0x3aa) == '\0'))))
    goto LAB_002cf3df;
  }
  else {
    if ((param_3 & 1) == 0) {
      return 0;
    }
    if ((lVar1 == 0) || ((*(char *)(lVar1 + 0x3a9) != '\0' && (*(char *)(lVar1 + 0x3aa) != '\0'))))
    goto LAB_002cf411;
LAB_002cf3df:
    if (((*(char *)(param_2 + 0xad01) == '\0') || ((param_3 & 4) != 0)) &&
       (*(char *)(param_1 + 0x480) != '\0')) {
      kbusUnlinkP2P_GM107();
    }
  }
  if ((param_3 & 1) == 0) {
    *(undefined8 *)(param_2 + 0xabc0) = 0xffffffffffffffff;
    *(undefined8 *)(param_2 + 0xabc8) = 0;
  }
LAB_002cf411:
  *(undefined8 *)(param_2 + 0x5e8) = 0;
  return 0;
}


// ===== 002cf470 kbusGetSizeOfBar2PageTables_GM107 =====

int kbusGetSizeOfBar2PageTables_GM107(long param_1,long param_2)

{
  byte bVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  byte *pbVar5;
  ulong uVar6;
  byte bVar7;
  int iVar8;
  long lVar9;
  ulong uVar10;
  int iVar11;
  uint local_2c;
  
  uVar2 = *(undefined8 *)(param_1 + 0x1b98);
  iVar3 = vgpuGetCallingContextGfid(param_1,&local_2c);
  if (iVar3 == 0) {
    iVar3 = 0;
    if ((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) {
      lVar4 = kgmmuFmtGet_IMPL(uVar2,0,0);
      if (lVar4 == 0) {
        nvAssertFailedNoLog("NULL != pFmt","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xee5)
        ;
      }
      else {
        pbVar5 = (byte *)mmuFmtFindLevelWithPageShift(*(undefined8 *)(lVar4 + 8),0xc);
        uVar6 = (ulong)local_2c;
        lVar9 = uVar6 * 0xd8 + param_2;
        lVar4 = *(long *)(lVar9 + 0x4628);
        uVar10 = 0;
        if (lVar4 != 0) {
          uVar10 = (ulong)(uint)(((int)lVar4 + 1) - *(int *)(lVar9 + 0x4620));
        }
        lVar9 = uVar6 * 0xd8 + param_2;
        lVar4 = *(long *)(lVar9 + 0x4638);
        if (lVar4 != 0) {
          uVar10 = (ulong)(uint)(((int)uVar10 - *(int *)(lVar9 + 0x4630)) + 1 + (int)lVar4);
        }
        bVar1 = *pbVar5;
        bVar7 = pbVar5[1] + 1;
        iVar8 = (int)((uVar10 - 1) + (1L << (bVar7 & 0x3f)) >> (bVar7 & 0x3f));
        if (uVar10 >> (bVar7 & 0x3f) == 0) {
          iVar11 = (int)((uVar10 - 1) + (1L << (bVar1 & 0x3f)) >> (bVar1 & 0x3f)) * (uint)pbVar5[2];
          iVar3 = iVar11;
        }
        else {
          iVar11 = (uint)pbVar5[2] << ((pbVar5[1] - bVar1) + 1 & 0x1f);
          iVar3 = iVar11 * iVar8;
        }
        *(int *)(param_2 + 0x46d4 + uVar6 * 0xd8) = iVar11;
        *(int *)(param_2 + 0x46d0 + uVar6 * 0xd8) = iVar8;
      }
    }
    return iVar3;
  }
  nvAssertFailedNoLog("vgpuGetCallingContextGfid(pGpu, &gfid) == NV_OK",
                      "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xedb);
  return 0;
}


// ===== 002cf600 kbusStateDestroy_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbusStateDestroy_GM107(long param_1,long param_2)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  int *piVar11;
  int iVar12;
  
  lVar9 = *(long *)(param_1 + 0x1b78);
  lVar4 = *(long *)(param_1 + 7000);
  lVar5 = *(long *)(param_1 + 0x1b98);
  (**(code **)(param_2 + 0x460))(param_1,param_2,0);
  lVar9 = *(long *)(lVar9 + 0x838);
  if ((lVar9 != 0) &&
     ((*(char *)(param_1 + 0x454) == '\0' || (*(char *)(param_1 + 0x4915) == '\0')))) {
    (**(code **)(param_2 + 0x430))(param_1,param_2,lVar9 * 0x100000 + -0x100000);
  }
  if (*(long *)(param_2 + 0x5f0) != 0) {
    osUnmapPciMemoryKernelOld(param_1);
    *(undefined8 *)(param_2 + 0x5f0) = 0;
    *(undefined8 *)(param_2 + 0x600) = *(undefined8 *)(param_2 + 0x5f8);
  }
  uVar8 = nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xf2d,
                       "kbusStateDestroy_GM107",1,"NVRM: FLA Supported: %x \n",
                       *(undefined1 *)(param_2 + 0xa860));
  if ((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(param_2 + 0xa860) != '\0')) {
    nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xf33,"kbusStateDestroy_GM107",1
                 ,"NVRM: Trying to destroy FLA VAS\n");
    uVar8 = (**(code **)(param_2 + 0x390))(param_1,param_2);
  }
  if (lVar4 != 0) {
    if (*(char *)(lVar4 + 0x3a9) == '\0') {
      cVar2 = *(char *)(param_2 + 0xad00);
    }
    else {
      if (*(char *)(lVar4 + 0x3aa) != '\0') goto LAB_002cf710;
      cVar2 = *(char *)(param_2 + 0xad00);
    }
    if ((cVar2 != '\0') && (*(char *)(param_1 + 0x480) != '\0')) {
      uVar10 = 0;
      do {
        if (*(int *)(param_2 + 0xaa40 + uVar10 * 4) != 0) {
          lVar9 = gpumgrGetGpu(uVar10 & 0xffffffff);
          if (lVar9 == 0) {
            uVar8 = nvAssertFailedNoLog("pRemoteGpu != NULL",
                                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xdaf);
            goto LAB_002cf710;
          }
          lVar4 = *(long *)(&DAT_00001b90 + lVar9);
          uVar6 = (**(code **)(param_2 + 0x288))(param_1,param_2,lVar9);
          uVar7 = (**(code **)(lVar4 + 0x288))(lVar9,lVar4,param_1);
          if (7 < uVar6) {
            uVar8 = nvAssertFailedNoLog("locPeerId < P2P_MAX_NUM_PEERS",
                                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xdb4);
            goto LAB_002cf710;
          }
          if (7 < uVar7) {
            uVar8 = nvAssertFailedNoLog("remPeerId < P2P_MAX_NUM_PEERS",
                                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xdb6);
            goto LAB_002cf710;
          }
          lVar9 = (ulong)uVar7 * 0x20 + lVar4;
          if (uVar6 != *(uint *)(lVar9 + 0xaac4)) {
            uVar8 = nvAssertFailedNoLog("pRemoteKernelBus->p2pPcie.busPeer[remPeerId].remotePeerId == locPeerId"
                                        ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xdb8);
            goto LAB_002cf710;
          }
          piVar11 = (int *)(param_2 + 0xaac0 + (ulong)uVar6 * 0x20);
          *piVar11 = *piVar11 + -1;
          piVar11 = (int *)(lVar9 + 0xaac0);
          *piVar11 = *piVar11 + -1;
          lVar4 = lVar4 + (ulong)*(uint *)(param_1 + 0x7a4) * 4;
          puVar1 = (uint *)(param_2 + 0xaa40 + uVar10 * 4);
          *puVar1 = *puVar1 & ~(1 << ((byte)uVar6 & 0x1f));
          uVar6 = ~(1 << ((byte)uVar7 & 0x1f)) & *(uint *)(lVar4 + 0xaa40);
          *(uint *)(lVar4 + 0xaa40) = uVar6;
          if (*(int *)(param_2 + 0xaa40 + uVar10 * 4) != 0) {
            nvAssertFailedNoLog("pKernelBus->p2pPcie.peerNumberMask[i] == 0",
                                "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xdc3);
            uVar6 = *(uint *)(lVar4 + 0xaa40);
          }
          if (uVar6 != 0) {
            nvAssertFailedNoLog("pRemoteKernelBus->p2pPcie.peerNumberMask[gpuInst] == 0",
                                "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xdc4);
          }
        }
        uVar8 = (**(code **)(param_2 + 0x300))(param_1,param_2,uVar10 & 0xffffffff);
        if ((int)uVar8 != 0) {
          lVar9 = gpumgrGetGpu(uVar10 & 0xffffffff);
          if (lVar9 == 0) {
            uVar8 = nvAssertFailedNoLog("pRemoteGpu != NULL",
                                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xdcd);
            goto LAB_002cf710;
          }
          lVar4 = *(long *)(&DAT_00001b90 + lVar9);
          uVar6 = (**(code **)(param_2 + 0x288))(param_1,param_2,lVar9);
          uVar7 = (**(code **)(lVar4 + 0x288))(lVar9,lVar4,param_1);
          if (7 < uVar6) {
            uVar8 = nvAssertFailedNoLog("locPeerId < P2P_MAX_NUM_PEERS",
                                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xdd3);
            goto LAB_002cf710;
          }
          if (7 < uVar7) {
            uVar8 = nvAssertFailedNoLog("remPeerId < P2P_MAX_NUM_PEERS",
                                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xdd5);
            goto LAB_002cf710;
          }
          uVar3 = *(uint *)(param_1 + 0x7a4);
          piVar11 = (int *)(param_2 + 0xa974 + uVar10 * 4);
          *piVar11 = *piVar11 + -1;
          lVar9 = lVar4 + (ulong)uVar3 * 4;
          piVar11 = (int *)(lVar9 + 0xa974);
          *piVar11 = *piVar11 + -1;
          puVar1 = (uint *)(param_2 + 0xa8f4 + uVar10 * 4);
          *puVar1 = *puVar1 & ~(1 << ((byte)uVar6 & 0x1f));
          uVar8 = (ulong)uVar7;
          puVar1 = (uint *)(lVar9 + 0xa8f4);
          *puVar1 = *puVar1 & ~(1 << ((byte)uVar7 & 0x1f));
          piVar11 = (int *)(param_2 + 0xa9f4 + (ulong)uVar6 * 4);
          *piVar11 = *piVar11 + -1;
          piVar11 = (int *)(lVar4 + 0xa9f4 + uVar8 * 4);
          *piVar11 = *piVar11 + -1;
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 != 0x20);
      piVar11 = (int *)(param_2 + 0xaac0);
      iVar12 = 0;
      do {
        if (*piVar11 != 0) {
          uVar8 = (ulong)*(uint *)(param_1 + 0x7a4);
          nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xde5,
                       "_kbusDestroyP2P_GM107",4,
                       "NVRM: non-zero peer refcount(%d) on GPU 0x%x peer %d\n");
        }
        iVar12 = iVar12 + 1;
        *piVar11 = 0;
        piVar11 = piVar11 + 8;
      } while (iVar12 != 8);
      *(undefined1 *)(param_2 + 0xad00) = 0;
    }
  }
LAB_002cf710:
  if (*(long *)(lVar5 + 0x518) != 0) {
    memdescFree();
    uVar8 = memdescDestroy(*(undefined8 *)(lVar5 + 0x518));
    *(undefined8 *)(lVar5 + 0x518) = 0;
  }
  return uVar8;
}


// ===== 002cfb60 kbusVerifyBar2_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusVerifyBar2_GM107
              (long param_1,long param_2,undefined1 *param_3,int *param_4,long param_5,long param_6)

{
  long lVar1;
  long lVar2;
  bool bVar3;
  char cVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  uint extraout_var;
  long lVar12;
  ulong uVar13;
  undefined8 uVar14;
  int *piVar15;
  uint uVar16;
  uint uVar17;
  char *pcVar18;
  undefined8 uVar19;
  uint local_1ec;
  ushort local_1e0;
  long local_1c8;
  undefined1 local_1b0 [156];
  undefined4 local_114;
  
  lVar2 = *(long *)(param_1 + 0x1b70);
  if ((((*(char *)(param_1 + 1099) != '\0') &&
       (cVar4 = rmcfg_IsTEGRA_TEGRA_NVDISP_GPUS(), cVar4 == '\0')) ||
      (*(char *)(param_1 + 0x4921) != '\0')) ||
     ((*(char *)(param_1 + 0x44d) != '\0' || (*(char *)(param_2 + 0xad07) != '\0')))) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xf83,"kbusVerifyBar2_GM107",1,
               "NVRM: \n");
  iVar6 = (-(uint)(*(char *)(lVar2 + 0x29b) == '\0') & 0xffffffe0) + 0x31;
  if ((param_3 == (undefined1 *)0x0) || (param_4 == (int *)0x0)) {
    param_3 = local_1b0;
    if (*(char *)(param_1 + 1099) == '\0') {
      memdescCreateExisting(param_3,param_1,0x10,2,1,0);
    }
    else {
      memdescCreateExisting(param_3,param_1,0x10,1,*(undefined4 *)(param_1 + 0x1e34),0);
    }
    local_114 = 0x62;
    iVar9 = memdescAlloc(param_3);
    if (iVar9 != 0) {
      nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xfab,"kbusVerifyBar2_GM107",4
                   ,"NVRM: Could not allocate vidmem to test bar2 with\n");
      return 0x1a;
    }
    param_4 = (int *)memdescMapInternal(param_1,param_3,0);
    if (param_4 == (int *)0x0) {
      memdescFree(0);
      memdescDestroy(0);
      return 0x1a;
    }
    local_1ec = 0x10;
    bVar3 = true;
    local_1c8 = 0;
  }
  else {
    if (*(ulong *)(param_3 + 0x30) < (ulong)(param_6 + param_5)) {
      nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xf90,"kbusVerifyBar2_GM107",4
                   ,"NVRM: input offset 0x%llx size 0x%llx exceeds surface size 0x%llx\n",param_5,
                   param_6,*(ulong *)(param_3 + 0x30));
      return 0x1f;
    }
    local_1ec = (uint)param_6;
    bVar3 = false;
    local_1c8 = param_5;
  }
  lVar12 = memdescGetPhysAddr(param_3,1,0);
  bVar5 = kgmmuGetHwPteApertureFromMemdesc_GM107(*(undefined8 *)(param_1 + 0x1b98),param_3);
  uVar14 = 2;
  uVar16 = (uint)bVar5;
  if (*(char *)(param_1 + 0x446) == '\0') {
    uVar14 = 1;
  }
  lVar1 = param_1 + 0x3a18;
  nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xfc2,"kbusVerifyBar2_GM107",
               uVar14,"NVRM: Testing BAR0 window...\n");
  (**(code **)(param_2 + 0x438))(param_1,param_2);
  uVar7 = regRead032(lVar1,0,0,0x1700,0);
  uVar14 = memdescGetPhysAddr(param_3,1,0);
  uVar8 = regRead032(lVar1,0,0,0x1700,0);
  regWrite032(lVar1,0,0,0x1700,(uint)((ulong)uVar14 >> 0x10) & 0xffffff | uVar8 & 0xff000000,0);
  uVar8 = regRead032(lVar1,0,0,0x1700,0);
  uVar17 = (uVar16 & 3) << 0x18;
  regWrite032(lVar1,0,0,0x1700,uVar8 & 0xfcffffff | uVar17,0);
  local_1e0 = (ushort)uVar14;
  iVar9 = local_1e0 + 0x700000;
  uVar10 = regRead032(lVar1,0,0,iVar9,0);
  regWrite032(lVar1,0,0,iVar9,0xabcdabcd,0);
  iVar11 = regRead032(lVar1,0,0,iVar9,0);
  if (iVar11 == -0x54325433) {
    iVar11 = kmemsysSendL2InvalidateEvict_IMPL(param_1,lVar2,iVar6);
    if (iVar11 == 0) {
      uVar19 = 0x2cfec8;
      iVar11 = regRead032(lVar1,0,0,iVar9,0);
      if (iVar11 != -0x54325433) {
        nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xfea,"kbusVerifyBar2_GM107"
                     ,4,
                     "NVRM: Post-L2 invalidate evict: Address 0x%llx programmed through the bar0 window with value 0x%x did not read back the last write\n"
                     ,uVar14,0xffffffffabcdabcd);
        if (*(char *)(param_1 + 0x446) != '\0') {
          nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xff0,
                       "kbusVerifyBar2_GM107",4,
                       "NVRM: Setup a trigger on write<Bar0+0x1700, 0x40> with a 3 quarters post trigger capture\n"
                       ,uVar19);
          uVar14 = 4;
          uVar19 = 0xff3;
          pcVar18 = 
          "NVRM: and search for the last bar0 window write not returning the same value in a subsequent read\n"
          ;
LAB_002d02ee:
          nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",uVar19,
                       "kbusVerifyBar2_GM107",uVar14,pcVar18);
        }
        goto joined_r0x002d0303;
      }
      lVar12 = lVar12 + local_1c8;
      uVar14 = 2;
      if (*(char *)(param_1 + 0x446) == '\0') {
        uVar14 = 1;
      }
      nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xffc,"kbusVerifyBar2_GM107",
                   uVar14,"NVRM: Bar0 window tests successfully\n");
      regWrite032(lVar1,0,0,iVar9,uVar10,0);
      uVar8 = regRead032(lVar1,0,0,0x1700,0);
      regWrite032(lVar1,0,0,0x1700,uVar8 & 0xff000000 | extraout_var & 0xffffff,0);
      uVar8 = regRead032(lVar1,0,0,0x1700,0);
      regWrite032(lVar1,0,0,0x1700,uVar7 & 0x3000000 | uVar8 & 0xfcffffff,0);
      if (uVar16 - 2 < 2) {
        (**(code **)(param_2 + 0x500))(param_1,param_2,1);
      }
      nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x100c,"kbusVerifyBar2_GM107",
                   1,
                   "NVRM: MMUTest Writing test data through virtual BAR2 starting at bar2 offset (%p - %p) = %p and of size 0x%x\n"
                   ,param_4,*(long *)(param_2 + 0x7c98),(long)param_4 - *(long *)(param_2 + 0x7c98),
                   local_1ec);
      uVar14 = 2;
      if (*(char *)(param_1 + 0x446) == '\0') {
        uVar14 = 1;
      }
      nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x1012,"kbusVerifyBar2_GM107",
                   uVar14,"NVRM: MMUTest The physical address being targetted is 0x%llx\n",lVar12);
      uVar7 = 0;
      if (local_1ec != 0) {
        do {
          uVar13 = (ulong)uVar7;
          uVar7 = uVar7 + 4;
          *(undefined4 *)((long)param_4 + uVar13) = 0xabcdabcd;
        } while (uVar7 < local_1ec);
      }
      if (uVar16 - 2 < 2) {
        (**(code **)(param_2 + 0x500))(param_1,param_2,1);
      }
      osFlushCpuWriteCombineBuffer();
      iVar11 = kmemsysSendL2InvalidateEvict_IMPL(param_1,lVar2,iVar6);
      if (iVar11 != 0) {
        uVar14 = 0x1025;
        goto LAB_002d03de;
      }
      uVar14 = (**(code **)(param_2 + 0x438))(param_1,param_2);
      uVar7 = regRead032(lVar1,0,0,0x1700,0);
      uVar8 = regRead032(lVar1,0,0,0x1700,0);
      regWrite032(lVar1,0,0,0x1700,(uint)((ulong)lVar12 >> 0x10) & 0xffffff | uVar8 & 0xff000000,0);
      uVar8 = regRead032(lVar1,0,0,0x1700,0);
      regWrite032(lVar1,0,0,0x1700,uVar8 & 0xfcffffff | uVar17,0);
      uVar19 = regRead032(lVar1,0,0,0x1700,0);
      nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x102f,"kbusVerifyBar2_GM107",
                   1,
                   "NVRM: bar0Window = 0x%llx, testMemoryOffset = 0x%llx, testAddrSpace = %d, _PBUS_BAR0_WINDOW = 0x%08x\n"
                   ,uVar14,lVar12,uVar16,uVar19);
      if (local_1ec != 0) {
        local_1c8._0_2_ = (ushort)lVar12;
        iVar9 = (ushort)local_1c8 + 0x700000;
        uVar16 = 0;
        do {
          uVar19 = regRead032(lVar1,0,0,iVar9 + uVar16,0);
          if ((int)uVar19 != -0x54325433) {
            nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x103a,
                         "kbusVerifyBar2_GM107",4,
                         "NVRM: MMUTest BAR0 window offset 0x%x returned garbage 0x%x\n",
                         iVar9 + uVar16,uVar19);
            uVar14 = 1;
            pcVar18 = 
            "NVRM: Setup a trigger for write<bar0 + 0x1700, 0x40> and in the waves search the last few bar2 virtual writes mixed with bar0 window reads\n"
            ;
            if (*(char *)(param_1 + 0x446) != '\0') {
              uVar14 = 4;
            }
            uVar19 = 0x103d;
            goto LAB_002d02ee;
          }
          iVar11 = iVar9 + uVar16;
          uVar16 = uVar16 + 4;
          regWrite032(lVar1,0,0,iVar11,0xabcdabdd,0);
        } while (uVar16 < local_1ec);
      }
      uVar16 = regRead032(lVar1,0,0,0x1700,0);
      regWrite032(lVar1,0,0,0x1700,uVar16 & 0xff000000 | (uint)((ulong)uVar14 >> 0x10) & 0xffffff,0)
      ;
      uVar16 = regRead032(lVar1,0,0,0x1700,0);
      regWrite032(lVar1,0,0,0x1700,uVar7 & 0x3000000 | uVar16 & 0xfcffffff,0);
      iVar11 = (**(code **)(param_2 + 0x500))(param_1,param_2,1);
      if ((iVar11 == 0) &&
         (iVar11 = kmemsysSendL2InvalidateEvict_IMPL(param_1,lVar2,iVar6), iVar11 == 0)) {
        uVar16 = 0;
        piVar15 = param_4;
        if (local_1ec != 0) {
          do {
            if (*piVar15 != -0x54325423) {
              nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x105f,
                           "kbusVerifyBar2_GM107",4,
                           "NVRM: MMUTest BAR2 Read of virtual addr 0x%x returned garbage 0x%x\n",
                           uVar16 + ((int)param_4 - (int)*(undefined8 *)(param_2 + 0x7c98)),*piVar15
                          );
              goto joined_r0x002d0303;
            }
            uVar16 = uVar16 + 4;
            piVar15 = piVar15 + 1;
          } while (uVar16 < local_1ec);
        }
        if (bVar3) {
          memdescUnmapInternal(param_1,param_3,0);
          memdescFree(param_3);
          memdescDestroy(param_3);
        }
        uVar14 = 2;
        if (*(char *)(param_1 + 0x446) == '\0') {
          uVar14 = 1;
        }
        nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x1077,
                     "kbusVerifyBar2_GM107",uVar14,"NVRM: BAR2 virtual test passes\n");
        return 0;
      }
    }
    else {
      uVar14 = 0xfe4;
LAB_002d03de:
      nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",uVar14,"kbusVerifyBar2_GM107",
                   4,"NVRM: L2 evict failed\n");
    }
    if (!bVar3) {
      return iVar11;
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0xfd4,"kbusVerifyBar2_GM107",4,
                 "NVRM: Pre-L2 invalidate evict: Address 0x%llx programmed through the bar0 window with value 0x%x did not read back the last write.\n"
                 ,uVar14,0xffffffffabcdabcd);
joined_r0x002d0303:
    if (!bVar3) {
      return 0x72;
    }
    iVar11 = 0x72;
  }
  memdescUnmapInternal(param_1,param_3,0);
  memdescFree(param_3);
  memdescDestroy(param_3);
  return iVar11;
}


// ===== 002d0750 kbusInitBarsBaseInfo_GM107 =====

undefined8 kbusInitBarsBaseInfo_GM107(long param_1)

{
  *(undefined8 *)(param_1 + 0x618) = *(undefined8 *)(param_1 + 0x568);
  *(undefined8 *)(param_1 + 0x4610) = *(undefined8 *)(param_1 + 0x570);
  return 0;
}


// ===== 002d0780 kbusSetBarsApertureSize_GM107 =====

undefined8 kbusSetBarsApertureSize_GM107(long param_1,long param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  uint uVar6;
  int local_2c;
  
  uVar5 = (ulong)param_3;
  uVar6 = (-(uint)(*(char *)(param_2 + 0xad0f) == '\0') & 0xfffffff0) + 0x20;
  if (param_3 != 0) {
    kbusDetermineBar1ApertureLength_IMPL(param_2,param_3);
  }
  iVar2 = osReadRegistryDword(param_1,"RMBar2ApertureSizeMB",&local_2c);
  if (iVar2 == 0) {
    if (local_2c - 1U < uVar6) {
      uVar4 = (ulong)(local_2c * 0x100000 - 1);
      *(ulong *)(param_2 + 0x4648 + uVar5 * 0xd8) = uVar4;
      *(ulong *)(param_2 + 0x4628 + uVar5 * 0xd8) = uVar4;
      return 0;
    }
  }
  if (((*(char *)(*(long *)(param_1 + 0x1b48) + 0x4f) == '\0') ||
      (*(char *)(param_1 + 0x446) == '\0')) && (*(char *)(param_1 + 0x490e) == '\0')) {
    *(ulong *)(param_2 + 0x4648 + uVar5 * 0xd8) = (ulong)(uVar6 * 0x100000 - 1);
    *(undefined8 *)(param_2 + 0x4628 + uVar5 * 0xd8) = 0x1ffffff;
    return 0;
  }
  cVar1 = gpuIsCCFeatureEnabled_IMPL(param_1);
  lVar3 = (-(ulong)(cVar1 == '\0') & 0xffffffffff800000) + 0xffffff;
  *(long *)(param_2 + 0x4648 + uVar5 * 0xd8) = lVar3;
  *(long *)(param_2 + 0x4628 + uVar5 * 0xd8) = lVar3;
  return 0;
}


// ===== 002d08c0 kbusGetSizeOfBar2PageDirs_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusGetSizeOfBar2PageDirs_GM107(long param_1,long param_2)

{
  byte *pbVar1;
  int *piVar2;
  byte bVar3;
  byte bVar4;
  undefined8 uVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  long lVar9;
  uint uVar10;
  int iVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  long lVar15;
  ulong uVar16;
  short sVar17;
  byte *pbVar18;
  bool bVar19;
  uint local_3c [3];
  
  uVar5 = *(undefined8 *)(param_1 + 0x1b98);
  lVar8 = (**(code **)(param_2 + 0x1d8))();
  iVar6 = vgpuGetCallingContextGfid(param_1,local_3c);
  if (iVar6 == 0) {
    if ((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) {
      lVar9 = kgmmuFmtGet_IMPL(uVar5,0,0);
      uVar7 = local_3c[0];
      if (lVar9 != 0) {
        pbVar18 = *(byte **)(lVar9 + 8);
        if (pbVar18[2] == 0) {
          nvAssertFailedNoLog("0 != entrySize","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                              0x10ec);
          uVar10 = 0;
        }
        else {
          lVar9 = 1L << (*pbVar18 & 0x3f);
          uVar10 = (int)((lVar9 + -1 + lVar8) -
                         (-lVar9 & *(ulong *)(param_2 + 0x4620 + (ulong)local_3c[0] * 0xd8)) >>
                        (*pbVar18 & 0x3f)) * (uint)pbVar18[2] + 0xfff & 0xfffff000;
        }
        uVar12 = (ulong)local_3c[0];
        lVar9 = uVar12 * 0xd8 + param_2;
        *(uint *)(param_2 + 0x46cc + (ulong)uVar7 * 0xd8) = uVar10;
        bVar19 = true;
        *(undefined4 *)(lVar9 + 0x46c8) = 0;
        if (*(long *)(lVar9 + 0x4628) + 1 != *(long *)(lVar9 + 0x4630)) {
          bVar19 = *(long *)(lVar9 + 0x4638) == 0;
        }
        iVar6 = 0;
        sVar17 = 5;
        do {
          bVar3 = *pbVar18;
          bVar4 = pbVar18[2];
          lVar9 = 1L << (bVar3 & 0x3f);
          uVar7 = (uint)bVar4;
          if (bVar19) {
            if (bVar4 == 0) {
LAB_002d0ba8:
              nvAssertFailedNoLog("0 != entrySize",
                                  "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x10ec);
              uVar12 = (ulong)local_3c[0];
              uVar7 = 0;
            }
            else {
              iVar11 = uVar7 * (int)((lVar9 + -1 + lVar8) -
                                     (-lVar9 & *(ulong *)(param_2 + 0x4620 + uVar12 * 0xd8)) >>
                                    (bVar3 & 0x3f));
              uVar7 = iVar11 + 0xfffU >> 0xc;
              iVar6 = iVar6 + (iVar11 + 0xfffU & 0xfffff000);
            }
          }
          else {
            uVar13 = -lVar9;
            lVar15 = uVar12 * 0xd8 + param_2;
            uVar14 = *(ulong *)(lVar15 + 0x4628);
            if (((uVar14 ^ *(ulong *)(lVar15 + 0x4630)) & uVar13) == 0) {
              if (bVar4 == 0) goto LAB_002d0ba8;
              uVar10 = (int)((lVar9 + -1 + lVar8) - (uVar13 & *(ulong *)(lVar15 + 0x4620)) >>
                            (bVar3 & 0x3f)) * uVar7 + 0xfff;
              uVar7 = uVar10 >> 0xc;
              iVar6 = iVar6 + (uVar10 & 0xfffff000);
            }
            else {
              if (uVar7 == 0) {
                nvAssertFailedNoLog("0 != entrySize",
                                    "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x10ec);
                bVar4 = pbVar18[2];
                if (bVar4 == 0) {
                  nvAssertFailedNoLog("0 != entrySize",
                                      "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x10ec);
                  uVar12 = (ulong)local_3c[0];
                  uVar7 = 0;
                  goto LAB_002d0a75;
                }
                uVar12 = (ulong)local_3c[0];
                uVar7 = 0;
                uVar14 = *(ulong *)(param_2 + 0x4628 + uVar12 * 0xd8);
                uVar16 = *(ulong *)(param_2 + 0x4620 + uVar12 * 0xd8);
              }
              else {
                uVar16 = *(ulong *)(lVar15 + 0x4620);
                uVar7 = (int)((lVar9 + -1 + *(long *)(lVar15 + 0x4638)) -
                              (*(ulong *)(lVar15 + 0x4630) & uVar13) >> (bVar3 & 0x3f)) * uVar7 +
                        0xfff & 0xfffff000;
              }
              uVar7 = ((uint)bVar4 *
                       (int)(((uVar14 - 1) + lVar9) - (uVar13 & uVar16) >> (bVar3 & 0x3f)) + 0xfff &
                      0xfffff000) + uVar7;
              iVar6 = iVar6 + uVar7;
              uVar7 = uVar7 >> 0xc;
            }
          }
LAB_002d0a75:
          piVar2 = (int *)(param_2 + 0x46c8 + uVar12 * 0xd8);
          *piVar2 = *piVar2 + uVar7;
          pbVar1 = pbVar18 + 4;
          pbVar18 = *(byte **)(pbVar18 + 0x10);
          if (*pbVar1 == 1) {
            if (pbVar18 == (byte *)0x0) {
              nvAssertFailedNoLog("NULL != pLevel",
                                  "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x1160);
              return 0;
            }
          }
          else {
            pbVar18 = pbVar18 + 0x18;
          }
          if ((pbVar18[3] != 0) && (pbVar18[4] == 0)) {
            return iVar6;
          }
          sVar17 = sVar17 + -1;
          if (sVar17 == 0) {
            return iVar6;
          }
        } while( true );
      }
      nvAssertFailedNoLog("NULL != pFmt","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x111c);
    }
  }
  else {
    nvAssertFailedNoLog("vgpuGetCallingContextGfid(pGpu, &gfid) == NV_OK",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x1112);
  }
  return 0;
}


// ===== 002d0cc0 kbusSetupBar2GpuVaSpace_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusSetupBar2GpuVaSpace_GM107(long param_1,long param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  bool bVar11;
  long local_80;
  undefined8 local_78;
  long local_70;
  undefined8 local_68;
  long local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar9 = *(long *)(param_1 + 0x1b78);
  local_80 = 0;
  uVar6 = *(undefined8 *)(param_1 + 0x1b98);
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_78 = 0;
  local_70 = 0;
  if ((*(char *)(param_1 + 0x908) != '\0') &&
     ((*(char *)(param_1 + 0x4913) == '\0' || (*(char *)(param_1 + 0x491e) != '\0')))) {
    return 0;
  }
  if (param_3 == 0) {
    if (*(int *)(param_2 + 0xad34) == 2) {
      *(long *)(param_2 + 0x4658) = *(long *)(param_2 + 0x4658) + *(long *)(lVar9 + 0x490);
    }
    if (*(int *)(param_2 + 0xad2c) == 2) {
      *(long *)(param_2 + 0x4668) = *(long *)(param_2 + 0x4668) + *(long *)(lVar9 + 0x490);
    }
    if (*(char *)(param_2 + 0xad08) != '\0') {
      if (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) != '\0') {
LAB_002d1300:
        *(undefined1 *)(param_2 + 0x46a8 + (ulong)param_3 * 0xd8) = 1;
        iVar1 = (**(code **)(param_2 + 0x480))(param_1,param_2,0);
        uVar7 = 0x6a5;
        if (iVar1 != 0) goto LAB_002d12c4;
        iVar1 = (**(code **)(param_2 + 0x4a0))(param_1,param_2,param_3);
        if (iVar1 != 0) {
          uVar7 = 0x6a8;
          goto LAB_002d12c4;
        }
        goto LAB_002d0e90;
      }
      if (*(int *)(param_2 + 0xad34) == 2) {
LAB_002d0e68:
        if (*(int *)(param_2 + 0xad2c) == 2) goto LAB_002d1300;
        if (param_3 != 0) goto LAB_002d0e90;
      }
    }
    if ((*(char *)(param_1 + 0x454) == '\0') || (*(char *)(param_1 + 0x4915) == '\0')) {
      iVar1 = (**(code **)(param_2 + 0x440))(param_1,param_2,&local_78);
      uVar7 = 0x6ae;
      if (iVar1 != 0) {
LAB_002d12c4:
        nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                            uVar7);
        return iVar1;
      }
    }
  }
  else {
    if (*(int *)(param_2 + 0xad3c) != 2) {
      nvAssertFailedNoLog("pKernelBus->InstBlkAperture == ADDR_FBMEM",
                          "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x67b);
      return 0x1f;
    }
    iVar1 = memdescCreate(param_2 + 0x4678 + (ulong)param_3 * 0xd8,param_1,0x1000,0x1000,1,2,
                          *(undefined4 *)(param_2 + 0xad40),0x2000000);
    uVar7 = 0x686;
    if (iVar1 != 0) {
LAB_002d151d:
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",uVar7
                         );
      return iVar1;
    }
    lVar9 = (ulong)param_3 * 0xd8 + param_2;
    *(undefined4 *)(*(long *)(lVar9 + 0x4678) + 0x9c) = 0x60;
    iVar1 = memdescAlloc(*(undefined8 *)(lVar9 + 0x4678));
    if (iVar1 != 0) {
      uVar7 = 0x68b;
      goto LAB_002d151d;
    }
    uVar7 = memdescGetPhysAddr(*(undefined8 *)(lVar9 + 0x4678),1,0);
    *(undefined8 *)(lVar9 + 0x4670) = uVar7;
    if (*(char *)(param_2 + 0xad08) != '\0') {
      if (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) != '\0') goto LAB_002d1300;
      if (*(int *)(param_2 + 0xad34) == 2) goto LAB_002d0e68;
    }
  }
LAB_002d0e90:
  uVar10 = (ulong)param_3;
  uVar7 = (**(code **)(param_2 + 0x1d8))(param_1,param_2);
  lVar5 = uVar10 * 0xd8 + param_2;
  *(undefined8 *)(lVar5 + 18000) = uVar7;
  lVar9 = *(long *)(param_2 + 0x7c10 + uVar10 * 0xb0);
  if (lVar9 != 0) {
    (**(code **)(lVar9 + 0x48))
              (lVar9,*(undefined8 *)(lVar5 + 0x4640),*(long *)(lVar5 + 0x4648) + -0x1000);
  }
  iVar2 = kbusGetSizeOfBar2PageDirs_GM107(param_1,param_2);
  iVar3 = kbusGetSizeOfBar2PageTables_GM107(param_1,param_2);
  iVar1 = *(int *)(param_2 + 0xad34);
  if (iVar1 == 2) {
    if (*(int *)(param_2 + 0xad2c) != 2) {
      nvAssertFailedNoLog("pKernelBus->PDEBAR2Aperture == pKernelBus->PTEBAR2Aperture",
                          "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x6cd);
LAB_002d1670:
      iVar1 = 0;
      goto LAB_002d118a;
    }
    iVar1 = memdescCreate(&local_70,param_1,iVar2 + iVar3,0x1000,1,2,
                          *(undefined4 *)(param_2 + 0xad38),0x2000000);
    if (iVar1 != 0) {
      nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x6d7
                         );
      goto LAB_002d118a;
    }
    if (param_3 == 0) {
      iVar1 = *(int *)(param_2 + 0xad34);
      goto LAB_002d0f1f;
    }
    *(undefined4 *)(local_70 + 0x9c) = 0x61;
    iVar1 = memdescAlloc();
    if (iVar1 == 0) {
      lVar5 = memdescGetPhysAddr(local_70,1,0);
      lVar8 = uVar10 * 0xd8 + param_2;
      *(long *)(lVar8 + 0x4658) = lVar5;
      lVar9 = param_2 + uVar10 * 0xb0;
      *(long *)(lVar9 + 0x7c70) = local_70;
      uVar4 = kbusGetSizeOfBar2PageDirs_GM107(param_1,param_2);
      *(ulong *)(lVar8 + 0x4668) = (ulong)uVar4 + 0xfff + lVar5 & 0xfffffffffffff000;
      lVar5 = memdescMapInternal(param_1,*(undefined8 *)(lVar9 + 0x7c70),0);
      *(long *)(lVar9 + 0x7c78) = lVar5;
      if (lVar5 == 0) {
        nvAssertFailedNoLog("pKernelBus->virtualBar2[gfid].pPageLevels",
                            "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x6eb);
        return 0x1a;
      }
      goto LAB_002d0f61;
    }
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x6dd);
    if (*(long *)(param_2 + 0x7c78 + uVar10 * 0xb0) != 0) goto LAB_002d11ae;
    if (local_80 == 0) goto LAB_002d14b0;
LAB_002d11e5:
    mmuWalkSetUserCtx(local_80,0);
LAB_002d11ec:
    if (iVar1 != 0) goto LAB_002d14b0;
  }
  else {
    if (param_3 != 0) {
LAB_002d0f61:
      lVar9 = kgmmuFmtGet_IMPL(uVar6,0,0);
      lVar5 = uVar10 * 0xd8;
      *(long *)(param_2 + 0x46c0 + lVar5) = lVar9;
      if (lVar9 == 0) {
        nvAssertFailedNoLog("NULL != pKernelBus->bar2[gfid].pFmt",
                            "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x718);
        goto LAB_002d1670;
      }
      if ((*(long *)(param_2 + 0x46b8 + lVar5) == 0) && (*(int *)(param_2 + 0xad2c) == 2)) {
        bVar11 = *(char *)(param_2 + 0x46a8 + lVar5) != '\0';
      }
      else {
        bVar11 = false;
      }
      iVar1 = mmuWalkCreate(*(undefined8 *)(lVar9 + 8),0,g_bar2WalkCallbacks,0,&local_80);
      if (iVar1 == 0) {
        lVar9 = param_2 + uVar10 * 0xd8;
        *(long *)(lVar9 + 0x46b0) = local_80;
        uVar6 = mmuFmtFindLevelWithPageShift(*(undefined8 *)(*(long *)(lVar9 + 0x46c0) + 8),0xc);
        local_40 = CONCAT44(local_40._4_4_,param_3);
        local_60 = param_1;
        if (local_80 == 0) {
          nvAssertFailedNoLog("pWalk != NULL","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                              0x739);
          return 0x40;
        }
        iVar1 = mmuWalkSetUserCtx(local_80,&local_68);
        if (iVar1 != 0) {
          nvAssertOkFailedNoLog
                    (iVar1,"mmuWalkSetUserCtx(pWalk, &userCtx)",
                     "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x73c);
          return iVar1;
        }
        if (*(long *)(lVar9 + 0x4628) == 0) {
LAB_002d1033:
          lVar9 = uVar10 * 0xd8 + param_2;
          if (*(long *)(lVar9 + 0x4638) == 0) {
LAB_002d109f:
            lVar9 = uVar10 * 0xd8 + param_2;
            uVar6 = *(undefined8 *)(lVar9 + 18000);
            nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x759,
                         "kbusSetupBar2GpuVaSpace_GM107",1,
                         "NVRM: (BAR2 0x%llx, PDB 0x%llx): vaLimit = 0x%llx\n",
                         *(undefined8 *)(lVar9 + 0x4670),*(undefined8 *)(lVar9 + 0x4658));
            if (*(long *)(lVar9 + 0x4698) == 0) {
              memdescSetPageSize(*(undefined8 *)(lVar9 + 0x4660),1,0x1000,uVar6);
              uVar6 = *(undefined8 *)(lVar9 + 0x4660);
            }
            else {
              memdescSetPageSize(*(long *)(lVar9 + 0x4698),1,0x1000,uVar6);
              uVar6 = *(undefined8 *)(lVar9 + 0x4698);
            }
            lVar9 = uVar10 * 0xb0;
            *(undefined8 *)(param_2 + 0x7ca8 + lVar9) = uVar6;
            if ((*(char *)(param_2 + 0xad08) == '\0') || (*(long *)(param_2 + 0x7c80 + lVar9) == 0))
            {
LAB_002d1178:
              (**(code **)(param_2 + 0x208))(param_1,param_2);
              iVar1 = 0;
            }
            else {
              iVar1 = (**(code **)(param_2 + 0x228))(param_1,param_2);
              if (iVar1 == 0) {
                if ((*(long *)(param_2 + 0x7c88 + lVar9) == 0) &&
                   (iVar1 = kbusPreInitVirtualBar2_VBAR2(param_1,param_2), iVar1 != 0)) {
                  nvAssertFailedNoLog("status == NV_OK",
                                      "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x777);
                }
                else {
                  iVar1 = (**(code **)(param_2 + 0x480))(param_1,param_2,1);
                  if (iVar1 == 0) goto LAB_002d1178;
                  nvAssertFailedNoLog("status == NV_OK",
                                      "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x77c);
                }
              }
              else {
                nvAssertFailedNoLog("status == NV_OK",
                                    "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x772);
              }
            }
          }
          else {
            iVar1 = mmuWalkReserveEntries
                              (local_80,uVar6,*(undefined8 *)(lVar9 + 0x4630),
                               *(long *)(lVar9 + 0x4638),0);
            if (iVar1 == 0) {
              iVar1 = mmuWalkSparsify(local_80,*(undefined8 *)(lVar9 + 0x4630),
                                      *(undefined8 *)(lVar9 + 0x4638),bVar11);
              if (iVar1 == 0) goto LAB_002d109f;
              nvAssertFailedNoLog("NV_OK == status",
                                  "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x756);
            }
            else {
              nvAssertFailedNoLog("NV_OK == status",
                                  "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x751);
            }
          }
        }
        else {
          iVar1 = mmuWalkReserveEntries
                            (local_80,uVar6,*(undefined8 *)(lVar9 + 0x4620),
                             *(long *)(lVar9 + 0x4628),0);
          if (iVar1 == 0) {
            *(int *)(lVar9 + 0x46e4) = *(int *)(lVar9 + 0x46e0) * *(int *)(lVar9 + 0x46d4);
            iVar1 = mmuWalkSparsify(local_80,*(undefined8 *)(lVar9 + 0x4620),
                                    *(undefined8 *)(lVar9 + 0x4628),bVar11);
            if (iVar1 == 0) goto LAB_002d1033;
            nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c"
                                ,0x74a);
          }
          else {
            nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c"
                                ,0x742);
          }
        }
      }
      else {
        nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                            0x72e);
      }
LAB_002d118a:
      if (param_3 == 0) {
        if (local_80 != 0) goto LAB_002d13a1;
LAB_002d13a8:
        if (*(char *)(param_2 + 0xad08) != '\0') {
          if (iVar1 == 0) goto LAB_002d1369;
          goto LAB_002d14b0;
        }
LAB_002d13b2:
        if ((*(char *)(param_1 + 0x454) == '\0') || (*(char *)(param_1 + 0x4915) == '\0')) {
          (**(code **)(param_2 + 0x448))(param_1,param_2,local_78);
        }
      }
      else {
        if (*(long *)(param_2 + 0x7c78 + uVar10 * 0xb0) != 0) {
LAB_002d11ae:
          lVar9 = *(long *)(param_2 + 0x7c70 + uVar10 * 0xb0);
          if (lVar9 != 0) {
            memdescUnmapInternal(param_1,lVar9,0);
            *(undefined8 *)(param_2 + 0x7c78 + uVar10 * 0xb0) = 0;
          }
        }
        if (local_80 != 0) goto LAB_002d11e5;
      }
      goto LAB_002d11ec;
    }
LAB_002d0f1f:
    if (iVar1 == 1) {
      local_70 = 0;
    }
    else if (local_70 != 0) {
      memdescDescribe(local_70,iVar1,*(undefined8 *)(param_2 + 0x4658),iVar2 + iVar3);
    }
    *(long *)(param_2 + 0x7c70) = local_70;
    if (((*(char *)(param_1 + 0x454) == '\0') || (*(char *)(param_1 + 0x4915) == '\0')) ||
       (iVar1 = kbusInitVirtualBar2_VBAR2(param_1,param_2), iVar1 == 0)) goto LAB_002d0f61;
    nvAssertOkFailedNoLog
              (iVar1,"kbusInitVirtualBar2_HAL(pGpu, pKernelBus)",
               "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x712);
    if (local_80 != 0) {
LAB_002d13a1:
      mmuWalkSetUserCtx(local_80,0);
      goto LAB_002d13a8;
    }
    if (*(char *)(param_2 + 0xad08) == '\0') goto LAB_002d13b2;
LAB_002d14b0:
    if (((*(char *)(param_1 + 0x908) == '\0') ||
        ((*(char *)(param_1 + 0x4913) != '\0' && (*(char *)(param_1 + 0x491e) == '\0')))) &&
       (*(long *)(param_2 + 0x46b0 + uVar10 * 0xd8) != 0)) {
      kbusTeardownBar2GpuVaSpace_GM107_part_0(param_1,param_2,param_3);
    }
  }
  if (*(char *)(param_2 + 0xad08) == '\0') {
    return iVar1;
  }
LAB_002d1369:
  *(undefined1 *)(param_2 + 0x46a8 + uVar10 * 0xd8) = 0;
  return iVar1;
}


// ===== 002d19c0 kbusInitBar2_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusInitBar2_GM107(long param_1,long param_2,int param_3)

{
  int iVar1;
  
  if ((*(char *)(param_1 + 0x908) != '\0') &&
     ((*(char *)(param_1 + 0x4913) == '\0' || (*(char *)(param_1 + 0x491e) != '\0')))) {
    return 0;
  }
  if ((param_2 == 0) || (*(char *)(param_2 + 0xad46) == '\0')) {
    iVar1 = kbusSetupBar2CpuAperture_GM107(param_1,param_2,param_3);
    if (iVar1 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x552
                         );
      goto LAB_002d1b16;
    }
  }
  iVar1 = kbusSetupBar2GpuVaSpace_GM107(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(char *)(param_2 + 0xad08) != '\0') {
      iVar1 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,param_3);
      if (iVar1 != 0) {
        nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                            0x55b);
        goto LAB_002d1b16;
      }
    }
    iVar1 = (**(code **)(param_2 + 0x1f0))(param_1,param_2,0);
    if (iVar1 == 0) {
      if (param_3 == 0) {
        *(undefined1 *)(param_2 + 0xad05) = 1;
      }
      return 0;
    }
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x55f);
  }
  else {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x556);
  }
LAB_002d1b16:
  (**(code **)(param_2 + 0x460))(param_1,param_2,param_3);
  return iVar1;
}


// ===== 002d1b60 kbusGetUnusedPeerId_GM107 =====

int kbusGetUnusedPeerId_GM107(undefined8 param_1,long param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(param_2 + 0xaac0);
  if (*(int *)(param_2 + 0xacf0) != 0) {
    do {
      if ((*piVar2 == 0) && ((char)piVar2[2] == '\0')) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 8;
    } while (iVar1 != *(int *)(param_2 + 0xacf0));
  }
  return -1;
}


// ===== 002d1bb0 kbusGetUnusedPciePeerId_GM107 =====

int kbusGetUnusedPciePeerId_GM107(undefined8 param_1,long param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(param_2 + 0xaac0);
  if (*(int *)(param_2 + 0xacf0) != 0) {
    do {
      if ((*piVar2 == 0) && ((char)piVar2[2] == '\0')) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 8;
    } while (*(int *)(param_2 + 0xacf0) != iVar1);
  }
  return -1;
}


// ===== 002d1c00 kbusGetPeerId_GM107 =====

uint kbusGetPeerId_GM107(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_2 + 0xaa40 + (ulong)*(uint *)(param_3 + 0x7a4) * 4);
  uVar1 = 0xffffffff;
  if (uVar2 != 0) {
    uVar2 = -uVar2 & uVar2;
    uVar1 = (uint)((uVar2 & 0xaaaaaaaa) != 0) | (uint)(0xffff < uVar2) << 4 |
            (uint)((uVar2 & 0xff00ff00) != 0) << 3 | (uint)((uVar2 & 0xf0f0f0f0) != 0) << 2 |
            (uint)((uVar2 & 0xcccccccc) != 0) * 2;
  }
  return uVar1;
}


// ===== 002d1c70 kbusIsPeerIdValid_GM107 =====

byte kbusIsPeerIdValid_GM107(long param_1,long param_2,uint param_3)

{
  if (param_3 < 8) {
    return -((1 << ((byte)param_3 & 0x1f) &
             *(uint *)(param_2 + 0xaa40 + (ulong)*(uint *)(param_1 + 0x7a4) * 4)) == 0) & 0x2c;
  }
  nvAssertFailedNoLog("peerId < P2P_MAX_NUM_PEERS",
                      "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x11d2);
  return 0x2c;
}


// ===== 002d1cd0 kbusGetBar2GmmuWalker_GM107 =====

undefined8 kbusGetBar2GmmuWalker_GM107(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  uint local_1c;
  
  uVar3 = 0;
  if (param_1 != 0) {
    uVar3 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar2 = gpuEngineGetGpu(uVar3);
  iVar1 = vgpuGetCallingContextGfid(lVar2,&local_1c);
  if (iVar1 == 0) {
    if ((*(char *)(lVar2 + 0x908) == '\0') ||
       ((*(char *)(lVar2 + 0x4913) != '\0' && (*(char *)(lVar2 + 0x491e) == '\0')))) {
      return *(undefined8 *)(param_1 + 0x46b0 + (ulong)local_1c * 0xd8);
    }
  }
  else {
    nvAssertFailedNoLog("vgpuGetCallingContextGfid(pGpu, &gfid) == NV_OK",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x11e8);
  }
  return 0;
}


// ===== 002d1d70 kbusGetBar2GmmuFmt_GM107 =====

undefined8 kbusGetBar2GmmuFmt_GM107(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  uint local_1c;
  
  uVar3 = 0;
  if (param_1 != 0) {
    uVar3 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar2 = gpuEngineGetGpu(uVar3);
  iVar1 = vgpuGetCallingContextGfid(lVar2,&local_1c);
  if (iVar1 == 0) {
    if ((*(char *)(lVar2 + 0x908) == '\0') ||
       ((*(char *)(lVar2 + 0x4913) != '\0' && (*(char *)(lVar2 + 0x491e) == '\0')))) {
      return *(undefined8 *)(param_1 + 0x46c0 + (ulong)local_1c * 0xd8);
    }
  }
  else {
    nvAssertFailedNoLog("vgpuGetCallingContextGfid(pGpu, &gfid) == NV_OK",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x1202);
  }
  return 0;
}


// ===== 002d1e10 kbusRestoreBar2_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusRestoreBar2_GM107(long param_1,uint param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined8 local_70;
  undefined8 local_68;
  long local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar3 = 0;
  if (param_1 != 0) {
    uVar3 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar2 = gpuEngineGetGpu(uVar3);
  if ((~param_2 & 1) != 0) {
    nvAssertFailedNoLog("flags & GPU_STATE_FLAGS_PRESERVING",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x23a);
    return 0x40;
  }
  if ((param_2 & 0x20) != 0) {
    iVar1 = (**(code **)(param_1 + 0x1f0))(lVar2,param_1,param_2);
    if (iVar1 != 0) goto LAB_002d2150;
    goto LAB_002d1e7b;
  }
  if (((param_1 == 0) || (*(char *)(param_1 + 0xad46) == '\0')) &&
     (iVar1 = kbusSetupBar2CpuAperture_GM107(lVar2,param_1,0), iVar1 != 0)) {
    nvAssertOkFailedNoLog
              (iVar1,"kbusSetupBar2CpuAperture_HAL(pGpu, pKernelBus, GPU_GFID_PF)",
               "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x241);
    return iVar1;
  }
  if (*(char *)(param_1 + 0xad08) == '\0') {
    uVar3 = kbusGetBar2GmmuWalker_GM107(param_1);
    lVar4 = kbusGetBar2GmmuFmt_GM107(param_1);
    local_68 = 0;
    local_60 = 0;
    local_58 = 0;
    local_50 = 0;
    local_48 = 0;
    local_40 = 0;
    local_70 = 0;
    iVar1 = (**(code **)(param_1 + 0x440))(lVar2,param_1,&local_70);
    uVar5 = 600;
    pcVar6 = "kbusSetupBar0WindowBeforeBar2Bootstrap_HAL(pGpu, pKernelBus, &origVidOffset)";
    if (iVar1 != 0) goto LAB_002d2189;
    local_60 = lVar2;
    iVar1 = mmuWalkSetUserCtx(uVar3,&local_68,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",600
                             );
    if (iVar1 != 0) {
      uVar5 = 0x25c;
      pcVar6 = "mmuWalkSetUserCtx(pBar2Walk, &userCtx)";
      goto LAB_002d2189;
    }
    uVar5 = mmuFmtFindLevelWithPageShift(*(undefined8 *)(lVar4 + 8),0xc);
    if (*(long *)(param_1 + 0x4628) == 0) {
      if (*(long *)(param_1 + 0x4638) != 0) {
LAB_002d2210:
        iVar1 = mmuWalkCommitPDEs(uVar3,uVar5,*(undefined8 *)(param_1 + 0x4630));
        uVar5 = 0x266;
        pcVar6 = 
        "mmuWalkCommitPDEs(pBar2Walk, pLevelFmt, pKernelBus->bar2[GPU_GFID_PF].cpuInvisibleBase, pKernelBus->bar2[GPU_GFID_PF].cpuInvisibleLimit)"
        ;
        if (iVar1 != 0) goto LAB_002d2189;
        goto LAB_002d21cb;
      }
    }
    else {
      iVar1 = mmuWalkCommitPDEs(uVar3,uVar5,*(undefined8 *)(param_1 + 0x4620));
      if (iVar1 != 0) {
        uVar5 = 0x263;
        pcVar6 = 
        "mmuWalkCommitPDEs(pBar2Walk, pLevelFmt, pKernelBus->bar2[GPU_GFID_PF].cpuVisibleBase, pKernelBus->bar2[GPU_GFID_PF].cpuVisibleLimit)"
        ;
        goto LAB_002d2189;
      }
      if (*(long *)(param_1 + 0x4638) != 0) goto LAB_002d2210;
LAB_002d21cb:
      if (*(long *)(param_1 + 0x4628) != 0) {
        iVar1 = mmuWalkSparsify(uVar3,*(undefined8 *)(param_1 + 0x4620),*(long *)(param_1 + 0x4628),
                                0);
        uVar5 = 0x26a;
        pcVar6 = 
        "mmuWalkSparsify(pBar2Walk, pKernelBus->bar2[GPU_GFID_PF].cpuVisibleBase, pKernelBus->bar2[GPU_GFID_PF].cpuVisibleLimit, NV_FALSE)"
        ;
        if (iVar1 != 0) {
LAB_002d2189:
          nvAssertOkFailedNoLog
                    (iVar1,pcVar6,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",uVar5);
          return iVar1;
        }
      }
    }
    (**(code **)(param_1 + 0x448))(lVar2,param_1,local_70);
  }
  else {
    iVar1 = (**(code **)(param_1 + 0x480))(lVar2,param_1,0);
    if (iVar1 != 0) {
      nvAssertOkFailedNoLog
                (iVar1,"kbusBindBar2_HAL(pGpu, pKernelBus, BAR2_MODE_PHYSICAL)",
                 "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x247);
      return iVar1;
    }
    iVar1 = (**(code **)(param_1 + 0x4c8))(lVar2,param_1);
    if (iVar1 != 0) {
      nvAssertOkFailedNoLog
                (iVar1,"kbusCommitBar2PDEs_HAL(pGpu, pKernelBus)",
                 "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x248);
      return iVar1;
    }
  }
  iVar1 = (**(code **)(param_1 + 0x1f0))(lVar2,param_1,param_2);
  if (iVar1 != 0) {
LAB_002d2150:
    nvAssertOkFailedNoLog
              (iVar1,"kbusCommitBar2_HAL(pGpu, pKernelBus, flags)",
               "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x272);
    return iVar1;
  }
  timeoutSet(lVar2 + 0x1af0,&local_68,0,4);
  while (iVar1 = (**(code **)(param_1 + 0x468))(lVar2,param_1,0,0,0,0), iVar1 != 0) {
    if (iVar1 == 0x65) {
      nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x287,"kbusRestoreBar2_GM107",
                   4,"NVRM: kbusVerifyBar2_HAL() keeps failing.\n");
      break;
    }
    timeoutCheck(lVar2 + 0x1af0,&local_68,0x28c);
    osSpinLoop();
  }
LAB_002d1e7b:
  iVar1 = 0;
  if (((*(char *)(lVar2 + 0x454) == '\0') &&
      ((*(int *)(lVar2 + 0x4b34) != 4 || (*(char *)(param_1 + 0xad10) == '\0')))) &&
     (iVar1 = (**(code **)(param_1 + 0x468))(lVar2,param_1,0,0,0,0), iVar1 != 0)) {
    nvAssertOkFailedNoLog
              (iVar1,"kbusVerifyBar2_HAL(pGpu, pKernelBus, NULL, NULL, 0, 0)",
               "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x29c);
  }
  return iVar1;
}


// ===== 002d22d0 kbusGetPeerIdFromTable_GM107 =====

undefined4
kbusGetPeerIdFromTable_GM107(undefined8 param_1,undefined8 param_2,uint param_3,uint param_4)

{
  if ((param_3 | param_4) < 8) {
    return *(undefined4 *)(peerNumberTable_GM107 + ((ulong)param_4 + (ulong)param_3 * 8) * 4);
  }
  nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x1223,
               "kbusGetPeerIdFromTable_GM107",4,
               "NVRM: Peer number table doesn\'t support >%u GPUs\n",8);
  return 0xffffffff;
}


// ===== 002d2330 kbusInitPciBars_GM107 =====

void kbusInitPciBars_GM107(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (param_1 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar1 = gpuEngineGetGpu(uVar2);
  *(undefined8 *)(param_1 + 0x560) = *(undefined8 *)(lVar1 + 0x848);
  *(undefined8 *)(param_1 + 0x568) = *(undefined8 *)(lVar1 + 0x850);
  uVar2 = *(undefined8 *)(lVar1 + 0x858);
  *(undefined4 *)(param_1 + 0x55c) = 4;
  *(undefined8 *)(param_1 + 0x570) = uVar2;
  *(undefined8 *)(param_1 + 0x578) = *(undefined8 *)(lVar1 + 0x860);
  return;
}


// ===== 002d23a0 kbusSetBAR0WindowVidOffset_GM107 =====

undefined8 kbusSetBAR0WindowVidOffset_GM107(long param_1,long param_2,ulong param_3)

{
  uint uVar1;
  ulong uVar2;
  
  if ((short)param_3 != 0) {
    nvAssertFailedNoLog("(vidOffset & 0xffff)==0","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c"
                        ,0x1252);
  }
  if (0xffffff < param_3 >> 0x10) {
    nvAssertFailedNoLog("(vidOffset >> 16) <= DRF_MASK(NV_PBUS_BAR0_WINDOW_BASE)",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x1253);
  }
  uVar2 = *(ulong *)(param_2 + 0x5e8);
  if (uVar2 == 0) {
    uVar2 = regRead032(param_1 + 0x3a18,0,0,0x1700,0);
    uVar2 = (uVar2 & 0xffffff) << 0x10;
    *(ulong *)(param_2 + 0x5e8) = uVar2;
  }
  if (uVar2 != param_3) {
    nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x125f,
                 "kbusSetBAR0WindowVidOffset_GM107",1,"NVRM: mapping BAR0_WINDOW to VID:%x\'%08x\n",
                 param_3 >> 0x20,param_3);
    uVar1 = regRead032(param_1 + 0x3a18,0,0,0x1700,0);
    regWrite032(param_1 + 0x3a18,0,0,0x1700,uVar1 & 0xff000000 | (uint)(param_3 >> 0x10) & 0xffffff,
                0);
    uVar1 = regRead032(param_1 + 0x3a18,0,0,0x1700,0);
    regWrite032(param_1 + 0x3a18,0,0,0x1700,uVar1 & 0xfcffffff,0);
    *(ulong *)(param_2 + 0x5e8) = param_3;
  }
  return 0;
}


// ===== 002d2540 kbusGetBAR0WindowVidOffset_GM107 =====

void kbusGetBAR0WindowVidOffset_GM107(long param_1,long param_2)

{
  ulong uVar1;
  
  if (*(long *)(param_2 + 0x5e8) != 0) {
    return;
  }
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x1700,0);
  *(ulong *)(param_2 + 0x5e8) = (uVar1 & 0xffffff) << 0x10;
  return;
}


// ===== 002d25a0 kbusMemAccessBar0Window_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbusMemAccessBar0Window_GM107
                (long param_1,long param_2,ulong param_3,undefined4 *param_4,ulong param_5,
                char param_6,int param_7)

{
  bool bVar1;
  int iVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  
  if ((*(char *)(param_1 + 0x491c) == '\0') && (param_7 != 2)) {
    nvAssertFailedNoLog("gpuIsUnifiedMemorySpaceEnabled(pGpu) || (addrSpace == ADDR_FBMEM)",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x12a0);
  }
  if ((*(char *)(param_1 + 0x454) != '\0') && (*(char *)(param_1 + 0x4915) != '\0')) {
    nvAssertFailedNoLog("kbusMemAccessBar0Window_HAL call in coherent path\n",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x12a4);
    return 0x40;
  }
  lVar6 = (**(code **)(param_2 + 0x438))(param_1,param_2);
  lVar8 = param_3 - lVar6;
  bVar1 = 0x100000 < lVar8 + param_5;
  if (bVar1) {
    (**(code **)(param_2 + 0x430))(param_1,param_2,param_3 & 0xffffffffffff0000);
    lVar8 = (**(code **)(param_2 + 0x438))(param_1,param_2);
    lVar8 = param_3 - lVar8;
  }
  iVar2 = (int)lVar8;
  if (param_6 == '\0') {
    if (param_5 == 4) {
      regWrite032(param_1 + 0x3a18,0,0,iVar2 + 0x700000,*param_4,0);
      goto LAB_002d26c0;
    }
    if (param_5 < 5) {
      if (param_5 == 1) {
        regWrite008(param_1 + 0x3a18,0,0,iVar2 + 0x700000,*(undefined1 *)param_4);
        goto LAB_002d26c0;
      }
      if (param_5 == 2) {
        regWrite016(param_1 + 0x3a18,0,0,iVar2 + 0x700000,*(undefined2 *)param_4);
        goto LAB_002d26c0;
      }
    }
    else if (param_5 == 8) {
      regWrite032(param_1 + 0x3a18,0,0,iVar2 + 0x700000,*param_4,0);
      regWrite032(param_1 + 0x3a18,0,0,iVar2 + 0x700004,param_4[1],0);
      goto LAB_002d26c0;
    }
    nvAssertFailedNoLog(&DAT_00cf9b47,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x12e0);
  }
  else {
    if (param_5 == 4) {
      uVar5 = regRead032(param_1 + 0x3a18,0,0,iVar2 + 0x700000,0);
      *param_4 = uVar5;
      goto LAB_002d26c0;
    }
    if (param_5 < 5) {
      if (param_5 == 1) {
        uVar3 = regRead008(param_1 + 0x3a18,0,0,iVar2 + 0x700000);
        *(undefined1 *)param_4 = uVar3;
LAB_002d26c0:
        if ((bVar1) && (*(char *)(param_2 + 0x46a8) == '\0')) {
          uVar7 = (**(code **)(param_2 + 0x430))(param_1,param_2,lVar6);
          if ((int)uVar7 != 0) {
            nvAssertOkFailedNoLog
                      (uVar7 & 0xffffffff,
                       "kbusSetBAR0WindowVidOffset_HAL(pGpu, pKernelBus, bar0WindowOrig)",
                       "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x12ef);
            uVar7 = uVar7 & 0xffffffff;
          }
        }
        else {
          uVar7 = 0;
        }
        return uVar7;
      }
      if (param_5 == 2) {
        uVar4 = regRead016(param_1 + 0x3a18,0,0,iVar2 + 0x700000);
        *(undefined2 *)param_4 = uVar4;
        goto LAB_002d26c0;
      }
    }
    else if (param_5 == 8) {
      uVar5 = regRead032(param_1 + 0x3a18,0,0,iVar2 + 0x700000,0);
      *param_4 = uVar5;
      uVar5 = regRead032(param_1 + 0x3a18,0,0,iVar2 + 0x700004,0);
      param_4[1] = uVar5;
      goto LAB_002d26c0;
    }
    nvAssertFailedNoLog(&DAT_00cf9b47,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x12c7);
  }
  return 0xffff;
}


// ===== 002d29c0 _kbusWalkCBMapNextEntries_RmAperture =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _kbusWalkCBMapNextEntries_RmAperture
               (long param_1,undefined8 *param_2,ulong param_3,uint param_4,uint param_5,
               int *param_6)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  int iVar7;
  long lVar8;
  undefined8 uVar9;
  long lVar10;
  ulong uVar11;
  long lVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  long lVar16;
  long local_c8;
  uint local_c0;
  long local_80;
  undefined8 local_78;
  long local_70;
  undefined1 local_68 [16];
  ulong local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  pbVar3 = (byte *)*param_2;
  lVar4 = *(long *)(param_1 + 8);
  lVar5 = param_2[1];
  local_80 = 0;
  local_78 = 0;
  lVar16 = *(long *)(&DAT_00001b90 + lVar4);
  lVar8 = 1L << (*pbVar3 & 0x3f);
  uVar14 = *(uint *)(param_1 + 0x28);
  uVar9 = memdescGetPhysAddr(param_3,1,0);
  nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x903,
               "_kbusWalkCBMapNextEntries_RmAperture",1,
               "NVRM: [GPU%u]: PA 0x%llX, Entries 0x%X-0x%X\n",
               *(undefined4 *)(*(long *)(param_1 + 8) + 0x7a4),uVar9,param_4,param_5);
  portMemCopy(local_68,0x10,lVar5 + 0x28,0x10);
  iVar7 = memdescGetAddressSpace(param_3);
  if (iVar7 == 2) {
    uVar6 = (ulong)uVar14;
    lVar10 = uVar6 * 0xb0 + lVar16;
    lVar12 = *(long *)(lVar10 + 0x7c78);
    if (*(char *)(lVar16 + 0xad0c) == '\0') {
      if (lVar12 == 0) {
        lVar12 = uVar6 * 0xd8 + lVar16;
        if (*(char *)(lVar12 + 0x46a8) == '\0') {
          if (*(char *)(lVar12 + 0x46a9) == '\0') {
            nvAssertFailedNoLog("pKernelBus->bar2[gfid].bMigrating",
                                "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x9af);
            return;
          }
          lVar16 = *(long *)(lVar10 + 0x7c88);
          if (lVar16 == 0) {
            nvAssertFailedNoLog("NULL != pKernelBus->virtualBar2[gfid].pPageLevelsForBootstrap",
                                "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x9b1);
            return;
          }
          lVar10 = memdescGetPhysAddr(param_3,1,0);
          local_80 = lVar16 + (lVar10 - *(long *)(lVar12 + 0x4690));
          for (uVar14 = param_4; uVar14 <= param_5; uVar14 = uVar14 + 1) {
            _busWalkCBMapNextEntries_UpdatePhysAddr(lVar4,local_68,lVar5,lVar8);
            bVar1 = pbVar3[2];
            portMemCopy((ulong)(bVar1 * uVar14) + local_80,bVar1,local_68,bVar1);
          }
        }
        else if (param_4 <= param_5) {
          local_c0 = 0;
          local_c8 = 0;
          uVar14 = param_4;
          do {
            _busWalkCBMapNextEntries_UpdatePhysAddr(lVar4,local_68,lVar5,lVar8);
            uVar13 = pbVar3[2] * uVar14;
            if (*(char *)(lVar16 + 0xad08) == '\0') {
              iVar7 = memdescGetAddressSpace(param_3);
              local_c8 = memdescGetPhysAddr(param_3,(iVar7 == 2) + '\x01',(ulong)uVar13);
              if ((*(char *)(lVar4 + 0x454) == '\0') || (*(char *)(lVar4 + 0x4915) == '\0')) {
                uVar11 = (ulong)pbVar3[2] + 3 >> 2;
                if (uVar11 == 0) {
                  local_c0 = 0;
                }
                else {
                  lVar12 = 0;
                  do {
                    iVar7 = kbusMemAccessBar0Window_GM107
                                      (lVar4,lVar16,local_c8 + lVar12,local_68 + lVar12,4,0,2);
                    if (iVar7 != 0) {
                      nvAssertFailedNoLog("NV_OK == status",
                                          "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x991);
                      return;
                    }
                    lVar12 = lVar12 + 4;
                  } while (uVar11 * 4 - lVar12 != 0);
                  local_c0 = (uint)uVar11;
                }
              }
              else {
                local_58 = 0;
                local_70 = 0;
                iVar7 = (**(code **)(lVar16 + 0x518))
                                  (lVar4,lVar16,param_3,uVar13,pbVar3[2],3,&local_70,&local_58);
                if (iVar7 != 0) {
                  nvAssertFailedNoLog("status == NV_OK",
                                      "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x97d);
                  return;
                }
                if (local_70 == 0) {
                  nvAssertFailedNoLog("pMapping != NULL",
                                      "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x97e);
                  return;
                }
                portMemCopy(local_70,pbVar3[2],local_68,pbVar3[2]);
                (**(code **)(lVar16 + 0x520))(lVar4,lVar16,param_3,local_70);
              }
            }
            else {
              local_80 = kbusCpuOffsetInBar2WindowGet_IMPL(lVar4,lVar16,param_3);
              if (local_80 == 0) {
                nvAssertFailedNoLog("NULL != pMap",
                                    "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x965);
                return;
              }
              portMemCopy(local_80 + (ulong)uVar13,pbVar3[2],local_68,pbVar3[2]);
            }
            uVar14 = uVar14 + 1;
          } while (uVar14 <= param_5);
          if (((*(char *)(lVar16 + 0x46a8 + uVar6 * 0xd8) != '\0') &&
              (*(char *)(lVar16 + 0xad08) == '\0')) &&
             (local_58 = local_58 & 0xffffffff00000000, local_c0 != 0)) {
            lVar5 = local_c8 + (ulong)local_c0 * 4;
            do {
              iVar7 = kbusMemAccessBar0Window_GM107(lVar4,lVar16,local_c8,&local_58,4,1,2);
              if (iVar7 != 0) {
                nvAssertFailedNoLog("kbusMemAccessBar0Window_HAL(pGpu, pKernelBus, (entry + (sizeof(NvU32) * i)), &data, sizeof(NvU32), NV_TRUE, ADDR_FBMEM) == NV_OK"
                                    ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x9a3);
                return;
              }
              local_c8 = local_c8 + 4;
            } while (local_c8 != lVar5);
          }
        }
      }
      else {
        lVar16 = uVar6 * 0xd8 + lVar16;
        uVar14 = param_4;
        if (*(char *)(lVar16 + 0x46a9) == '\0') {
          lVar10 = memdescGetPhysAddr(param_3,1,0);
          local_80 = lVar12 + (lVar10 - *(long *)(lVar16 + 0x4658));
        }
        else {
          lVar12 = *(long *)(lVar10 + 0x7c88);
          if (lVar12 == 0) {
            nvAssertFailedNoLog("NULL != pKernelBus->virtualBar2[gfid].pPageLevelsForBootstrap",
                                "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x93a);
            return;
          }
          lVar10 = memdescGetPhysAddr(param_3,1,0);
          local_80 = lVar12 + (lVar10 - *(long *)(lVar16 + 0x4690));
        }
        for (; uVar14 <= param_5; uVar14 = uVar14 + 1) {
          _busWalkCBMapNextEntries_UpdatePhysAddr(lVar4,local_68,lVar5,lVar8);
          bVar1 = pbVar3[2];
          portMemCopy((ulong)(bVar1 * uVar14) + local_80,bVar1,local_68,bVar1);
        }
      }
      iVar7 = (param_5 + 1) - param_4;
    }
    else {
      uVar9 = *(undefined8 *)(lVar4 + 0x1b78);
      local_58 = 0;
      local_50 = 0;
      local_48 = 0;
      local_40 = 0;
      if (lVar12 != 0) {
        nvAssertFailedNoLog("pKernelBus->virtualBar2[gfid].pPageLevels == NULL",
                            "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x917);
        return;
      }
      iVar7 = (param_5 + 1) - param_4;
      local_50 = (ulong)(pbVar3[2] * param_4);
      bVar1 = pbVar3[2];
      local_58 = param_3;
      local_80 = memmgrMemBeginTransfer_IMPL(uVar9,&local_58,(uint)bVar1 * iVar7,2);
      if (param_4 <= param_5) {
        iVar15 = 0;
        do {
          _busWalkCBMapNextEntries_UpdatePhysAddr(lVar4,local_68,lVar5,lVar8);
          bVar2 = pbVar3[2];
          uVar14 = (uint)bVar2 * iVar15;
          iVar15 = iVar15 + 1;
          portMemCopy((ulong)uVar14 + local_80,bVar2,local_68,bVar2);
        } while (iVar15 + param_4 <= param_5);
      }
      memmgrMemEndTransfer_IMPL(uVar9,&local_58,(uint)bVar1 * iVar7,2);
    }
  }
  else {
    uVar9 = 0x2d2d1c;
    iVar7 = memdescGetAddressSpace(param_3);
    if ((iVar7 != 1) || (*(long *)(lVar16 + 0x7c78 + (ulong)uVar14 * 0xb0) != 0)) {
      uVar9 = 0x2d2d59;
      nvAssertFailedNoLog("memdescGetAddressSpace(pMemDesc) == ADDR_SYSMEM && pKernelBus->virtualBar2[gfid].pPageLevels == NULL"
                          ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x9c8);
    }
    iVar7 = memdescMapOld(param_3,0,*(undefined8 *)(param_3 + 0x30),1,3,&local_80,&local_78);
    uVar14 = param_4;
    if (iVar7 != 0) {
      nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x9d2
                          ,uVar9);
      return;
    }
    for (; uVar14 <= param_5; uVar14 = uVar14 + 1) {
      _busWalkCBMapNextEntries_UpdatePhysAddr(lVar4,local_68,lVar5,lVar8);
      bVar1 = pbVar3[2];
      portMemCopy((ulong)(bVar1 * uVar14) + local_80,bVar1,local_68,bVar1);
    }
    memdescUnmapOld(param_3,1,local_80,local_78);
    iVar7 = (param_5 + 1) - param_4;
  }
  *param_6 = iVar7;
  return;
}


// ===== 002d3310 kbusIsDirectMappingAllowed_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

undefined8
kbusIsDirectMappingAllowed_GM107
          (long param_1,long param_2,undefined8 *param_3,uint param_4,undefined1 *param_5)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  bool bVar6;
  
  lVar1 = *(long *)(param_1 + 0x1b78);
  uVar4 = memdescGetPteKindForGpu(param_3,*param_3);
  if (*(char *)(param_2 + 0xad0e) != '\0') {
    pcVar2 = *(code **)(lVar1 + 0x2a8);
    cVar3 = (*pcVar2)(lVar1,0,uVar4,pcVar2);
    if (cVar3 != '\0') {
      iVar5 = memdescGetCustomHeap(param_3);
      bVar6 = iVar5 == 2;
      goto LAB_002d33b5;
    }
  }
  iVar5 = memdescGetCustomHeap(param_3);
  if (iVar5 == 2) {
    bVar6 = true;
  }
  else {
    cVar3 = memdescGetFlag(param_3,0x800);
    if (cVar3 == '\0') {
      bVar6 = false;
      if (*(int *)((long)param_3 + 0x6c) != 0) {
        bVar6 = (param_4 & 0x18000) != 0x10000;
      }
    }
    else {
      bVar6 = false;
    }
  }
LAB_002d33b5:
  *param_5 = bVar6;
  return 0;
}


// ===== 002d33e0 kbusUseDirectSysmemMap_GM107 =====

undefined8
kbusUseDirectSysmemMap_GM107(undefined8 param_1,long param_2,long param_3,undefined1 *param_4)

{
  char cVar1;
  int iVar2;
  
  *param_4 = 0;
  iVar2 = memdescGetAddressSpace(param_3);
  if ((((iVar2 != 2) && (*(char *)(param_2 + 0xad06) == '\0')) &&
      ((*(char *)(param_3 + 100) != '\0' ||
       (((*(long *)(param_3 + 200) != 0 || (cVar1 = memdescGetFlag(param_3,0x800000), cVar1 != '\0')
         ) || (cVar1 = memdescGetFlag(param_3,0x80000000), cVar1 != '\0')))))) &&
     ((*(int *)(param_3 + 0x6c) == 1 ||
      (cVar1 = rmcfg_IsTEGRA_TEGRA_NVDISP_GPUS(param_1), cVar1 != '\0')))) {
    *param_4 = 1;
  }
  return 0;
}


// ===== 002d3480 kbusBar1InstBlkVasUpdate_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbusBar1InstBlkVasUpdate_GM107(long param_1,long param_2)

{
  undefined8 uVar1;
  uint uVar2;
  undefined8 uVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  uint local_4c;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar1 = *(undefined8 *)(param_1 + 0x1b98);
  uVar6 = *(undefined8 *)(param_1 + 0x1b78);
  uVar3 = (**(code **)(param_2 + 0x4e8))();
  local_48 = 0;
  local_40 = 0;
  uVar4 = vgpuGetCallingContextGfid(param_1,&local_4c);
  if ((int)uVar4 != 0) {
    nvAssertOkFailedNoLog
              (uVar4 & 0xffffffff,"vgpuGetCallingContextGfid(pGpu, &gfid)",
               "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x1374);
    return uVar4 & 0xffffffff;
  }
  if (*(char *)(param_1 + 0x908) != '\0') {
    if (*(char *)(param_1 + 0x4913) == '\0') {
      return uVar4;
    }
    if (*(char *)(param_1 + 0x491e) != '\0') {
      return uVar4;
    }
  }
  lVar5 = *(long *)(param_2 + 0x648 + (ulong)local_4c * 0x100);
  if ((local_4c != 0) && (lVar5 == 0)) {
    if (*(int *)(param_2 + 0xad3c) != 2) {
      nvAssertFailedNoLog("pKernelBus->InstBlkAperture == ADDR_FBMEM",
                          "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x1384);
      return 0x1f;
    }
    uVar2 = memdescCreate(param_2 + 0x648 + (ulong)local_4c * 0x100,param_1,0x1000,0x1000,1,2,
                          *(undefined4 *)(param_2 + 0xad40));
    if (uVar2 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                          0x138f,0x2000000);
      return (ulong)uVar2;
    }
    lVar5 = (ulong)local_4c * 0x100 + param_2;
    *(undefined4 *)(*(long *)(lVar5 + 0x648) + 0x9c) = 99;
    uVar2 = memdescAlloc(*(undefined8 *)(lVar5 + 0x648));
    if (uVar2 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                          0x1394);
      return (ulong)uVar2;
    }
    uVar2 = memmgrMemDescMemSet_IMPL
                      (uVar6,*(undefined8 *)(param_2 + 0x648 + (ulong)local_4c * 0x100),0,0);
    if (uVar2 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                          0x139a);
      return (ulong)uVar2;
    }
    lVar5 = (ulong)local_4c * 0x100 + param_2;
    uVar6 = memdescGetPhysAddr(*(undefined8 *)(lVar5 + 0x648),1,0);
    *(undefined8 *)(lVar5 + 0x640) = uVar6;
    lVar5 = *(long *)(param_2 + 0x648 + (ulong)local_4c * 0x100);
  }
  uVar2 = kgmmuInstBlkInit_IMPL(uVar1,lVar5,uVar3,0xffffffff,&local_48);
  if (uVar2 == 0) {
    (**(code **)(param_2 + 0x500))(param_1,param_2,1);
    kbusSendSysmembar_IMPL(param_1,param_2);
    uVar4 = (**(code **)(param_2 + 0x530))(param_1,param_2);
    if ((int)uVar4 != 0) {
      nvAssertOkFailedNoLog
                (uVar4 & 0xffffffff,"kbusBar1InstBlkBind_HAL(pGpu, pKernelBus)",
                 "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x13ad);
      uVar4 = uVar4 & 0xffffffff;
    }
  }
  else {
    nvAssertOkFailedNoLog
              (uVar2,
               "kgmmuInstBlkInit(pKernelGmmu, pKernelBus->bar1[gfid].pInstBlkMemDesc, pBar1VAS, FIFO_PDB_IDX_BASE, &params)"
               ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x13a2);
    uVar4 = (ulong)uVar2;
  }
  return uVar4;
}


// ===== 002d3780 kbusSetupBar2PageTablesAtBottomOfFb_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusSetupBar2PageTablesAtBottomOfFb_GM107(long param_1,long param_2,ulong param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  
  param_3 = param_3 & 0xffffffff;
  if (*(int *)(param_2 + 0xad34) == 2) {
    if (*(int *)(param_2 + 0xad2c) == 2) {
      lVar8 = *(long *)(param_1 + 0x1b98);
      if (*(char *)(param_2 + 0x46a8 + param_3 * 0xd8) == '\0') {
        nvAssertFailedNoLog("pKernelBus->bar2[gfid].bBootstrap",
                            "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x14b1);
      }
      iVar2 = kbusGetSizeOfBar2PageDirs_GM107(param_1,param_2);
      iVar3 = kbusGetSizeOfBar2PageTables_GM107(param_1,param_2);
      lVar5 = (**(code **)(lVar8 + 0x1d0))(lVar8);
      uVar9 = (ulong)(uint)(iVar2 + iVar3);
      uVar6 = (ulong)*(uint *)(param_2 + 0xad38);
      iVar2 = memdescCreate(param_2 + 0x7c80 + param_3 * 0xb0,param_1,uVar9,0x1000,1,
                            *(undefined4 *)(param_2 + 0xad34),uVar6,0);
      if (iVar2 == 0) {
        lVar1 = param_2 + param_3 * 0xb0;
        memdescDescribe(*(undefined8 *)(lVar1 + 0x7c80),*(undefined4 *)(param_2 + 0xad34),
                        lVar5 + 0x1000,uVar9);
        lVar7 = memdescGetPhysAddr(*(undefined8 *)(lVar1 + 0x7c80),1,0);
        lVar5 = param_2 + param_3 * 0xd8;
        *(long *)(lVar5 + 0x4690) = lVar7;
        uVar4 = kbusGetSizeOfBar2PageDirs_GM107(param_1,param_2);
        *(ulong *)(lVar5 + 0x46a0) = (ulong)uVar4 + 0xfff + lVar7 & 0xfffffffffffff000;
        lVar8 = (**(code **)(lVar8 + 0x1d0))(lVar8);
        uVar6 = uVar9 + 0x1000 + lVar8;
        uVar9 = *(long *)(lVar5 + 0x4648) + 1;
        if (uVar9 <= uVar6) {
          nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x14d5,
                       "kbusSetupBar2PageTablesAtBottomOfFb_GM107",4,
                       "NVRM: Init memory size (0x%x) > BAR2 window mapped to CPU (0x%llx)\n",uVar6,
                       uVar9);
          memdescDestroy(*(undefined8 *)(lVar1 + 0x7c80));
          nvAssertFailedNoLog(&DAT_00cf9b47,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                              0x14d9);
          iVar2 = 0x40;
        }
      }
      else {
        nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                            0x14c0,uVar6);
      }
      return iVar2;
    }
  }
  else if (*(int *)(param_2 + 0xad34) == *(int *)(param_2 + 0xad2c)) {
    return 0;
  }
  nvAssertFailedNoLog("pKernelBus->PDEBAR2Aperture == pKernelBus->PTEBAR2Aperture",
                      "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x14df);
  return 0;
}


// ===== 002d3a20 kbusTeardownBar2PageTablesAtBottomOfFb_GM107 =====

void kbusTeardownBar2PageTablesAtBottomOfFb_GM107(undefined8 param_1,long param_2,ulong param_3)

{
  int iVar1;
  long lVar2;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  param_3 = param_3 & 0xffffffff;
  local_58 = 0;
  lVar2 = *(long *)(param_2 + 0x4688 + param_3 * 0xd8);
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  local_50 = param_1;
  if (lVar2 != 0) {
    iVar1 = mmuWalkSetUserCtx(lVar2,&local_58);
    if (iVar1 != 0) {
      nvAssertOkFailedNoLog
                (iVar1,"mmuWalkSetUserCtx(pKernelBus->bar2[gfid].pWalkForBootstrap, &userCtx)",
                 "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x14fd);
    }
    lVar2 = param_3 * 0xd8 + param_2;
    mmuWalkLevelInstancesForceFree(*(undefined8 *)(lVar2 + 0x4688));
    iVar1 = mmuWalkSetUserCtx(*(undefined8 *)(lVar2 + 0x4688),0);
    if (iVar1 != 0) {
      nvAssertOkFailedNoLog
                (iVar1,"mmuWalkSetUserCtx(pKernelBus->bar2[gfid].pWalkForBootstrap, NULL)",
                 "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x14ff);
    }
    lVar2 = param_3 * 0xd8 + param_2;
    mmuWalkDestroy(*(undefined8 *)(lVar2 + 0x4688));
    *(undefined8 *)(lVar2 + 0x4688) = 0;
    memdescFree(*(undefined8 *)(lVar2 + 0x46b8));
    memdescDestroy(*(undefined8 *)(lVar2 + 0x46b8));
    *(undefined8 *)(lVar2 + 0x46b8) = 0;
  }
  param_2 = param_2 + param_3 * 0xb0;
  memdescDestroy(*(undefined8 *)(param_2 + 0x7c80));
  *(undefined8 *)(param_2 + 0x7c80) = 0;
  return;
}


// ===== 002d3b70 kbusSetupBar2InstBlkAtBottomOfFb_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusSetupBar2InstBlkAtBottomOfFb_GM107
              (long param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
              ulong param_6)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  
  if (*(int *)(param_2 + 0xad3c) != 2) {
    return 0;
  }
  param_6 = param_6 & 0xffffffff;
  lVar3 = *(long *)(param_1 + 0x1b98);
  if (*(char *)(param_2 + 0x46a8 + param_6 * 0xd8) == '\0') {
    nvAssertFailedNoLog("pKernelBus->bar2[gfid].bBootstrap",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x152a);
  }
  lVar1 = param_2 + param_6 * 0xd8;
  lVar5 = *(long *)(lVar1 + 0x4680);
  if (lVar5 == 0) {
    iVar2 = memdescCreate(param_2 + 0x4680 + param_6 * 0xd8,param_1,0x1000,0x1000,1,
                          *(undefined4 *)(param_2 + 0xad3c));
    if (iVar2 != 0) {
      nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                          0x1536,0);
      return iVar2;
    }
    uVar4 = (**(code **)(lVar3 + 0x1d0))(lVar3);
    memdescDescribe(*(undefined8 *)(lVar1 + 0x4680),*(undefined4 *)(param_2 + 0xad3c),uVar4,0x1000);
    lVar5 = *(long *)(lVar1 + 0x4680);
  }
  lVar3 = kbusCpuOffsetInBar2WindowGet_IMPL(param_1,param_2,lVar5);
  if (lVar3 == 0) {
    param_2 = param_2 + param_6 * 0xd8;
    memdescDestroy(*(undefined8 *)(param_2 + 0x4680));
    *(undefined8 *)(param_2 + 0x4680) = 0;
    nvAssertFailedNoLog("NULL != pMap","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x1544);
    iVar2 = 0x3d;
  }
  else {
    (**(code **)(param_2 + 0x498))(param_1,param_2,lVar3,param_3,param_4,param_5);
    iVar2 = 0;
  }
  return iVar2;
}


// ===== 002d3d50 kbusTeardownBar2InstBlkAtBottomOfFb_GM107 =====

void kbusTeardownBar2InstBlkAtBottomOfFb_GM107(undefined8 param_1,long param_2,uint param_3)

{
  param_2 = param_2 + (ulong)param_3 * 0xd8;
  memdescDestroy(*(undefined8 *)(param_2 + 0x4680));
  *(undefined8 *)(param_2 + 0x4680) = 0;
  return;
}


// ===== 002d3d90 kbusSetupBar2PageTablesAtTopOfFb_GM107 =====

int kbusSetupBar2PageTablesAtTopOfFb_GM107(undefined8 param_1,long param_2,ulong param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  if ((*(int *)(param_2 + 0xad34) != 2) || (*(int *)(param_2 + 0xad2c) != 2)) {
    return 0;
  }
  param_3 = param_3 & 0xffffffff;
  lVar3 = param_3 * 0xd8 + param_2;
  *(undefined1 *)(lVar3 + 0x46a9) = 1;
  iVar1 = kbusInitVirtualBar2_VBAR2();
  if (iVar1 != 0) {
    uVar2 = 0x158b;
LAB_002d4148:
    nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",uVar2);
    return iVar1;
  }
  iVar1 = mmuWalkCreate(*(undefined8 *)(*(long *)(lVar3 + 0x46c0) + 8),0,g_bar2WalkCallbacks,0,
                        &local_60,*(undefined8 *)(lVar3 + 0x46b8));
  if (iVar1 != 0) {
    uVar2 = 0x159f;
    goto LAB_002d4148;
  }
  uVar2 = mmuFmtFindLevelWithPageShift(*(undefined8 *)(*(long *)(lVar3 + 0x46c0) + 8),0xc);
  local_50 = param_1;
  iVar1 = mmuWalkSetUserCtx(local_60,&local_58);
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog
              (iVar1,"mmuWalkSetUserCtx(pWalk, &userCtx)",
               "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x15ab);
    goto LAB_002d4050;
  }
  if (*(long *)(lVar3 + 0x4628) != 0) {
    iVar1 = mmuWalkReserveEntries
                      (local_60,uVar2,*(undefined8 *)(lVar3 + 0x4620),*(long *)(lVar3 + 0x4628),0);
    if (iVar1 != 0) {
      nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                          0x15b1);
      goto LAB_002d4050;
    }
    iVar1 = mmuWalkSparsify(local_60,*(undefined8 *)(lVar3 + 0x4620),*(undefined8 *)(lVar3 + 0x4628)
                            ,1);
    if (iVar1 != 0) {
      nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                          0x15b3);
      goto LAB_002d4050;
    }
  }
  lVar3 = param_3 * 0xd8 + param_2;
  if (*(long *)(lVar3 + 0x4638) != 0) {
    iVar1 = mmuWalkReserveEntries
                      (local_60,uVar2,*(undefined8 *)(lVar3 + 0x4630),*(long *)(lVar3 + 0x4638),0);
    if (iVar1 != 0) {
      nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                          0x15ba);
      goto LAB_002d4050;
    }
    iVar1 = mmuWalkSparsify(local_60,*(undefined8 *)(lVar3 + 0x4630),*(undefined8 *)(lVar3 + 0x4638)
                            ,1);
    if (iVar1 != 0) {
      nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                          0x15bc);
      goto LAB_002d4050;
    }
  }
  iVar1 = mmuWalkSetUserCtx(local_60,0);
  if (iVar1 == 0) {
    lVar3 = param_3 * 0xd8 + param_2;
    uVar2 = *(undefined8 *)(lVar3 + 18000);
    nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x15c1,
                 "kbusSetupBar2PageTablesAtTopOfFb_GM107",1,
                 "NVRM: (BAR2 0x%llx, PDB 0x%llx): vaLimit = 0x%llx\n",
                 *(undefined8 *)(lVar3 + 0x4670),*(undefined8 *)(lVar3 + 0x4658));
    memdescSetPageSize(*(undefined8 *)(lVar3 + 0x4660),1,0x1000);
    lVar3 = param_3 * 0xb0 + param_2;
    if (*(long *)(lVar3 + 0x7c88) != 0) {
      memdescUnmapInternal(param_1,*(undefined8 *)(lVar3 + 0x7c80),0,uVar2);
      *(undefined8 *)(lVar3 + 0x7c88) = 0;
      kbusReleaseRmAperture_VBAR2(param_1,param_2,*(undefined8 *)(lVar3 + 0x7c80));
      *(undefined8 *)(lVar3 + 0x7c88) = 0;
    }
    lVar3 = param_3 * 0xd8;
    *(undefined1 *)(param_2 + 0x46a9 + lVar3) = 0;
    *(undefined8 *)(param_2 + 0x4688 + lVar3) = *(undefined8 *)(param_2 + 0x46b0 + lVar3);
    *(undefined8 *)(param_2 + 0x46b0 + lVar3) = local_60;
    return 0;
  }
  nvAssertOkFailedNoLog
            (iVar1,"mmuWalkSetUserCtx(pWalk, NULL)",
             "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x15bf);
LAB_002d4050:
  param_2 = param_3 * 0xd8 + param_2;
  *(undefined1 *)(param_2 + 0x46a9) = 0;
  mmuWalkLevelInstancesForceFree(local_60);
  mmuWalkSetUserCtx(local_60,0);
  mmuWalkDestroy(local_60);
  memdescFree(*(undefined8 *)(param_2 + 0x46b8));
  memdescDestroy(*(undefined8 *)(param_2 + 0x46b8));
  *(undefined8 *)(param_2 + 0x46b8) = 0;
  return iVar1;
}


// ===== 002d4220 kbusCommitBar2PDEs_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbusCommitBar2PDEs_GM107(undefined8 param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ulong uVar6;
  undefined8 uVar7;
  uint local_6c;
  uint local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  lVar1 = kbusGetBar2GmmuFmt_GM107(param_2);
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  uVar2 = vgpuGetCallingContextGfid(param_1,&local_5c);
  if ((int)uVar2 != 0) {
    nvAssertOkFailedNoLog
              (uVar2 & 0xffffffff,"vgpuGetCallingContextGfid(pGpu, &gfid)",
               "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x15fc);
    return uVar2 & 0xffffffff;
  }
  if (*(int *)(param_2 + 0xad34) == 2) {
    if (*(int *)(param_2 + 0xad2c) != 2) {
      return uVar2;
    }
    lVar3 = (ulong)local_5c * 0xd8 + param_2;
    uVar7 = *(undefined8 *)(lVar3 + 0x46b0);
    *(undefined8 *)(lVar3 + 0x46b0) = *(undefined8 *)(lVar3 + 0x4688);
    local_50 = param_1;
    uVar4 = mmuFmtFindLevelWithPageShift(*(undefined8 *)(lVar1 + 8),0xc);
    *(undefined1 *)(param_2 + 0x46a8 + (ulong)local_5c * 0xd8) = 1;
    local_6c = mmuWalkSetUserCtx(*(undefined8 *)(param_2 + 0x4688 + (ulong)local_5c * 0xd8),
                                 &local_58);
    if (local_6c == 0) {
      uVar5 = (**(code **)(param_2 + 0x1d8))(param_1,param_2);
      local_6c = mmuWalkCommitPDEs(*(undefined8 *)(param_2 + 0x4688 + (ulong)local_5c * 0xd8),uVar4,
                                   0,uVar5);
      if (local_6c == 0) {
        local_6c = mmuWalkSetUserCtx(*(undefined8 *)(param_2 + 0x4688 + (ulong)local_5c * 0xd8),0);
        if (local_6c == 0) {
          if ((*(long *)(param_2 + 0x7c88 + (ulong)local_5c * 0xb0) == 0) &&
             (local_6c = kbusPreInitVirtualBar2_VBAR2(param_1,param_2), local_6c != 0)) {
            uVar7 = 0x161e;
          }
          else {
            local_6c = (**(code **)(param_2 + 0x480))(param_1,param_2,1);
            if (local_6c == 0) {
              *(undefined2 *)(param_2 + 0x46a8 + (ulong)local_5c * 0xd8) = 0x100;
              if ((*(long *)(param_2 + 0x7c78 + (ulong)local_5c * 0xb0) == 0) &&
                 (local_6c = kbusInitVirtualBar2_VBAR2(param_1,param_2), local_6c != 0)) {
                uVar7 = 0x1636;
              }
              else {
                local_6c = mmuWalkSetUserCtx(uVar7,&local_58);
                if (local_6c == 0) {
                  uVar5 = (**(code **)(param_2 + 0x1d8))(param_1,param_2);
                  local_6c = mmuWalkCommitPDEs(uVar7,uVar4,0,uVar5);
                  if (local_6c == 0) {
                    uVar4 = (**(code **)(param_2 + 0x1d8))(param_1,param_2);
                    local_6c = mmuWalkSparsify(uVar7,0,uVar4,1);
                    if (local_6c == 0) {
                      uVar2 = mmuWalkSetUserCtx(uVar7,0);
                      local_6c = (uint)uVar2;
                      if (local_6c == 0) {
                        uVar6 = (ulong)local_5c;
                        lVar1 = uVar6 * 0xb0 + param_2;
                        if (*(long *)(lVar1 + 0x7c88) != 0) {
                          memdescUnmapInternal(param_1,*(undefined8 *)(lVar1 + 0x7c80),0);
                          *(undefined8 *)(param_2 + 0x7c88 + (ulong)local_5c * 0xb0) = 0;
                          kbusReleaseRmAperture_VBAR2
                                    (param_1,param_2,
                                     *(undefined8 *)(param_2 + 0x7c80 + (ulong)local_5c * 0xb0));
                          uVar6 = (ulong)local_5c;
                          uVar2 = uVar2 & 0xffffffff;
                          *(undefined8 *)(param_2 + 0x7c88 + uVar6 * 0xb0) = 0;
                        }
                        *(undefined1 *)(param_2 + 0x46a9 + uVar6 * 0xd8) = 0;
                        *(undefined8 *)(param_2 + 0x46b0 + uVar6 * 0xd8) = uVar7;
                        return uVar2;
                      }
                      uVar7 = 0x1644;
                    }
                    else {
                      uVar7 = 0x1641;
                    }
                  }
                  else {
                    uVar7 = 0x163e;
                  }
                }
                else {
                  uVar7 = 0x163b;
                }
              }
            }
            else {
              uVar7 = 0x1623;
            }
          }
        }
        else {
          uVar7 = 0x1618;
        }
      }
      else {
        uVar7 = 0x1616;
      }
    }
    else {
      uVar7 = 0x1613;
    }
    nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",uVar7);
    return (ulong)local_6c;
  }
  return uVar2;
}


// ===== 002d45f0 kbusCommitBar2_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbusCommitBar2_GM107(long param_1,long param_2,ulong param_3)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  uint local_2c [3];
  
  uVar2 = vgpuGetCallingContextGfid(param_1,local_2c);
  if (uVar2 != 0) {
    nvAssertOkFailedNoLog
              (uVar2,"vgpuGetCallingContextGfid(pGpu, &gfid)",
               "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x1675);
    return (ulong)uVar2;
  }
  if ((param_3 & 0x20) == 0) {
    if ((*(char *)(param_2 + 0xad08) != '\0') &&
       (*(long *)(param_2 + 0x7c70 + (ulong)local_2c[0] * 0xb0) != 0)) {
      lVar1 = *(long *)(param_1 + 0x1b98);
      uVar2 = (**(code **)(param_2 + 0x1f8))(param_1,param_2);
      if (uVar2 != 0) {
        nvAssertOkFailedNoLog
                  (uVar2,
                   "kbusRewritePTEsForExistingMapping_HAL(pGpu, pKernelBus, pKernelBus->virtualBar2[gfid].pPageLevelsMemDesc)"
                   ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x1684);
        return (ulong)uVar2;
      }
      if ((*(long *)(param_2 + 0xad18) != 0) &&
         (uVar2 = (**(code **)(param_2 + 0x1f8))(param_1,param_2), uVar2 != 0)) {
        nvAssertOkFailedNoLog
                  (uVar2,
                   "kbusRewritePTEsForExistingMapping_HAL(pGpu, pKernelBus, pKernelBus->pFlushMemDesc)"
                   ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x1689);
        return (ulong)uVar2;
      }
      osFlushCpuWriteCombineBuffer();
      (**(code **)(param_2 + 0x500))(param_1,param_2,1);
      lVar3 = (ulong)local_2c[0] * 0xb0 + param_2;
      (**(code **)(lVar1 + 0x1e8))
                (param_1,lVar1,*(undefined8 *)(lVar3 + 0x7ca8),*(undefined4 *)(lVar3 + 0x7ca4),1,0,2
                 ,0);
      *(undefined8 *)(param_2 + 0x7ca8 + (ulong)local_2c[0] * 0xb0) =
           *(undefined8 *)(param_2 + 0x4660 + (ulong)local_2c[0] * 0xd8);
    }
    uVar4 = (**(code **)(param_2 + 0x480))(param_1,param_2,1);
    if ((int)uVar4 == 0) {
      if (*(char *)(param_2 + 0xad08) != '\0') {
        return uVar4;
      }
      if ((*(char *)(param_1 + 0x454) != '\0') && (*(char *)(param_1 + 0x4915) != '\0')) {
        return uVar4;
      }
      if (local_2c[0] != 0) {
        return uVar4;
      }
      uVar2 = kbusInitVirtualBar2_VBAR2(param_1,param_2);
      if (uVar2 == 0) {
        uVar4 = (**(code **)(param_2 + 0x228))(param_1,param_2);
        if ((int)uVar4 == 0) {
          return uVar4;
        }
        nvAssertOkFailedNoLog
                  (uVar4 & 0xffffffff,"kbusSetupCpuPointerForBusFlush_HAL(pGpu, pKernelBus)",
                   "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x16a2);
        return uVar4 & 0xffffffff;
      }
      nvAssertOkFailedNoLog
                (uVar2,"kbusInitVirtualBar2_HAL(pGpu, pKernelBus)",
                 "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x16a1);
      return (ulong)uVar2;
    }
  }
  else {
    uVar4 = (**(code **)(param_2 + 0x480))(param_1,param_2,1);
    if ((int)uVar4 == 0) {
      return uVar4;
    }
  }
  nvAssertOkFailedNoLog
            (uVar4 & 0xffffffff,"kbusBindBar2_HAL(pGpu, pKernelBus, BAR2_MODE_VIRTUAL)",
             "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x1699);
  return uVar4 & 0xffffffff;
}


// ===== 002d48b0 kbusPrepareForXVEReset_GM107 =====

undefined8 kbusPrepareForXVEReset_GM107(long param_1,long param_2)

{
  if (((*(char *)(*(long *)(param_1 + 7000) + 0x3a9) == '\0') ||
      (*(char *)(*(long *)(param_1 + 7000) + 0x3aa) == '\0')) &&
     (*(char *)(param_2 + 0xad01) == '\0')) {
    kbusUnlinkP2P_GM107();
    return 0;
  }
  return 0;
}


// ===== 002d48f0 kbusGetEffectiveAddressSpace_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusGetEffectiveAddressSpace_GM107(long param_1,undefined8 param_2,uint param_3,int *param_4)

{
  long lVar1;
  char cVar2;
  int iVar3;
  char local_39 [9];
  
  lVar1 = *(long *)(&DAT_00001b90 + param_1);
  local_39[0] = '\x01';
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pKernelBus != NULL","src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",
                        0x18c6);
    return 0x40;
  }
  iVar3 = (**(code **)(lVar1 + 0x408))(param_1,lVar1,param_2,param_3,local_39);
  if (iVar3 != 0) {
    nvCheckOkFailedNoLog
              (1,iVar3,
               "kbusIsDirectMappingAllowed_HAL(pGpu, pKernelBus, pMemDesc, mapFlags, &bDirectSysMappingAllowed)"
               ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x18c7);
    return iVar3;
  }
  iVar3 = memdescGetAddressSpace(param_2);
  if ((((iVar3 == 1) && (local_39[0] == '\0')) && ((param_3 & 0x18000) != 0x8000)) &&
     (*(char *)(lVar1 + 0xad0e) == '\0')) {
    nvAssertFailedNoLog(&DAT_00cf9b47,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm107.c",0x18d6);
    return 0x56;
  }
  cVar2 = memdescGetFlag(param_2,0x8000000000);
  if (cVar2 == '\0') {
    iVar3 = memdescGetAddressSpace(param_2);
    if (((iVar3 == 1) &&
        (((iVar3 = 1, local_39[0] != '\0' || ((param_3 & 0x18000) == 0x8000)) ||
         ((*(char *)(param_1 + 0x4913) != '\0' &&
          ((*(char *)(param_1 + 0x4910) == '\0' && (*(char *)(param_1 + 0x4911) == '\0')))))))) ||
       (iVar3 = memdescGetAddressSpace(param_2), iVar3 == 2)) goto LAB_002d49ab;
    iVar3 = memdescGetAddressSpace(param_2);
    if ((iVar3 != 1) || (local_39[0] != '\0')) {
      iVar3 = memdescGetAddressSpace(param_2);
      goto LAB_002d49ab;
    }
  }
  iVar3 = 2;
LAB_002d49ab:
  if (param_4 != (int *)0x0) {
    *param_4 = iVar3;
    return 0;
  }
  return 0;
}


// ===== 002d4b10 kbusSetupMailboxes_GM200 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbusSetupMailboxes_GM200
               (long param_1,long param_2,long param_3,long param_4,uint param_5,uint param_6)

{
  char cVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  bool local_a1;
  undefined8 local_90;
  long local_88;
  long local_80;
  long local_78;
  undefined8 local_70;
  undefined8 local_68;
  long local_60;
  long local_58;
  long local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  cVar1 = (**(code **)(param_2 + 0x2e0))();
  local_a1 = true;
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(param_4 + 0x2e0))(param_3,param_4,param_1);
    local_a1 = cVar1 != '\0';
  }
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_90 = 0;
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  local_70 = 0;
  if (param_5 < 8) {
    if (param_6 < 8) {
      uVar3 = (ulong)param_6;
      if (*(uint *)(param_4 + 0xaac4 + uVar3 * 0x20) == param_5) {
        if (*(uint *)(param_2 + 0xaac4 + (ulong)param_5 * 0x20) == param_6) {
          lVar7 = (ulong)param_5 * 0x20;
          lVar4 = (**(code **)(param_4 + 0x260))
                            (param_3,param_4,param_1,param_6,param_2 + 0xaad8 + lVar7);
          if (lVar4 == -1) {
            nvAssertFailedNoLog("remoteWMBoxLocalAddr != ~0ULL",
                                "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x59);
          }
          else {
            lVar5 = (**(code **)(param_2 + 0x2d8))
                              (param_1,param_2,param_3,param_4 + 0xaad0 + uVar3 * 0x20);
            if (lVar5 == -1) {
              nvAssertFailedNoLog("localP2PDomainRemoteAddr != ~0ULL",
                                  "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x60);
            }
            else {
              lVar7 = (**(code **)(param_4 + 0x2d8))
                                (param_3,param_4,param_1,param_2 + 0xaad0 + lVar7);
              if (lVar7 == -1) {
                nvAssertFailedNoLog("remoteP2PDomainLocalAddr != ~0ULL",
                                    "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x67);
              }
              else {
                lVar6 = uVar3 * 0x10000 + *(long *)(param_4 + 0xabc0);
                if ((short)lVar6 != 0) {
                  nvAssertFailedNoLog("(remoteWMBoxAddrU64 & 0xFFFF) == 0",
                                      "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x71);
                }
                local_48 = 0;
                local_68 = CONCAT44(param_6,param_5);
                local_40 = CONCAT71(local_40._1_7_,local_a1);
                local_60 = lVar5;
                local_58 = lVar7;
                local_50 = lVar4;
                iVar2 = (**(code **)(param_1 + 0x3b90))
                                  (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                                   *(undefined4 *)(param_1 + 0x3b3c),0x20800a71,&local_68,0x30);
                if (iVar2 != 0) {
                  nvAssertFailedNoLog("status == NV_OK",
                                      "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x82);
                }
                local_90 = CONCAT44(param_6,param_5);
                local_70 = local_48;
                local_88 = lVar5;
                local_80 = lVar7;
                local_78 = lVar6;
                iVar2 = (**(code **)(param_3 + 0x3b90))
                                  (param_3 + 0x3b58,*(undefined4 *)(param_3 + 0x3b34),
                                   *(undefined4 *)(param_3 + 0x3b3c),0x20800a72,&local_90,0x28);
                if (iVar2 != 0) {
                  nvAssertFailedNoLog("status == NV_OK",
                                      "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x92);
                }
                (**(code **)(param_4 + 0x2d0))(param_3,param_4,param_6,local_48);
              }
            }
          }
        }
        else {
          nvAssertFailedNoLog("pKernelBus0->p2pPcie.busPeer[local2Remote].remotePeerId == remote2Local"
                              ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x52);
        }
      }
      else {
        nvAssertFailedNoLog("pKernelBus1->p2pPcie.busPeer[remote2Local].remotePeerId == local2Remote"
                            ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x50);
      }
    }
    else {
      nvAssertFailedNoLog("remote2Local < P2P_MAX_NUM_PEERS",
                          "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x4d);
    }
  }
  else {
    nvAssertFailedNoLog("local2Remote < P2P_MAX_NUM_PEERS",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x4c);
  }
  return;
}


// ===== 002d4f90 kbusWriteP2PWmbTag_GM200 =====

void kbusWriteP2PWmbTag_GM200(long param_1,undefined8 param_2,int param_3,ulong param_4)

{
  param_3 = param_3 * 0x40;
  param_1 = param_1 + 0x3a18;
  regRead032(param_1,0,0,param_3 + 0x139068,0);
  regWrite032(param_1,0,0,param_3 + 0x139068,param_4 & 0xffffffff,0);
  regWrite032(param_1,0,0,param_3 + 0x13906c,param_4 >> 0x20,0);
  return;
}


// ===== 002d5010 kbusSetupP2PDomainAccess_GM200 =====

void kbusSetupP2PDomainAccess_GM200
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  kbusSetupPeerBarAccess_IMPL(param_1,param_3,*(long *)(param_1 + 0x848) + 0x139000,0x2000,param_4);
  return;
}


// ===== 002d5040 kbusSetupMailboxAccess_GM200 =====

void kbusSetupMailboxAccess_GM200
               (undefined8 param_1,long param_2,undefined8 param_3,ulong param_4,undefined8 param_5)

{
  long lVar1;
  
  lVar1 = gpumgrGetGpuPhysFbAddr();
  kbusSetupPeerBarAccess_IMPL
            (param_1,param_3,(param_4 & 0xffffffff) * 0x10000 + *(long *)(param_2 + 0xabc0) + lVar1,
             0x10000,param_5);
  return;
}


// ===== 002d50a0 kbusDestroyPeerAccess_GM200 =====

void kbusDestroyPeerAccess_GM200(undefined8 param_1,long param_2,uint param_3)

{
  param_2 = param_2 + (ulong)param_3 * 0x20;
  memdescDestroy(*(undefined8 *)(param_2 + 0xaad8));
  *(undefined8 *)(param_2 + 0xaad8) = 0;
  memdescDestroy(*(undefined8 *)(param_2 + 0xaad0));
  *(undefined8 *)(param_2 + 0xaad0) = 0;
  return;
}


// ===== 002d50f0 kbusGetP2PMailboxAttributes_GM200 =====

void kbusGetP2PMailboxAttributes_GM200
               (long param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4,
               undefined4 *param_5)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 7000);
  if (param_3 == (undefined4 *)0x0) {
    if (param_4 == (undefined4 *)0x0) {
      if (param_5 == (undefined4 *)0x0) {
        return;
      }
      *param_5 = 0;
      if ((*(char *)(lVar1 + 0x3a9) != '\0') && (*(char *)(lVar1 + 0x3aa) != '\0')) {
        return;
      }
      goto LAB_002d5136;
    }
    *param_4 = 0;
    if (param_5 == (undefined4 *)0x0) {
      if ((*(char *)(lVar1 + 0x3a9) != '\0') && (*(char *)(lVar1 + 0x3aa) != '\0')) {
        return;
      }
      *param_4 = 0x10000;
      return;
    }
    *param_5 = 0;
    if ((*(char *)(lVar1 + 0x3a9) != '\0') && (*(char *)(lVar1 + 0x3aa) != '\0')) {
      return;
    }
  }
  else {
    *param_3 = 0;
    if (param_4 == (undefined4 *)0x0) {
      if (param_5 == (undefined4 *)0x0) {
        if ((*(char *)(lVar1 + 0x3a9) == '\0') || (*(char *)(lVar1 + 0x3aa) == '\0')) {
          *param_3 = 0x80000;
          return;
        }
      }
      else {
        *param_5 = 0;
        if ((*(char *)(lVar1 + 0x3a9) == '\0') || (*(char *)(lVar1 + 0x3aa) == '\0')) {
          *param_3 = 0x80000;
          *param_5 = 0x40000;
          return;
        }
      }
      return;
    }
    *param_4 = 0;
    if (param_5 == (undefined4 *)0x0) {
      if ((*(char *)(lVar1 + 0x3a9) != '\0') && (*(char *)(lVar1 + 0x3aa) != '\0')) {
        return;
      }
      *param_3 = 0x80000;
      *param_4 = 0x10000;
      return;
    }
    *param_5 = 0;
    if ((*(char *)(lVar1 + 0x3a9) != '\0') && (*(char *)(lVar1 + 0x3aa) != '\0')) {
      return;
    }
    *param_3 = 0x80000;
  }
  *param_4 = 0x10000;
LAB_002d5136:
  *param_5 = 0x40000;
  return;
}


// ===== 002d5260 kbusCreateP2PMappingForMailbox_GM200 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusCreateP2PMappingForMailbox_GM200
              (long param_1,long param_2,long param_3,long param_4,uint *param_5,uint *param_6)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  long lVar9;
  undefined8 uVar10;
  uint uVar11;
  long lVar12;
  ulong local_60;
  undefined1 local_44 [8];
  int local_3c;
  
  if ((*(char *)(param_1 + 0x908) != '\0') || (*(char *)(param_3 + 0x908) != '\0')) {
    return 0x56;
  }
  if ((param_5 == (uint *)0x0) || (param_6 == (uint *)0x0)) {
    return 0x1f;
  }
  uVar7 = *(uint *)(param_1 + 0x7a4);
  uVar11 = *param_5;
  uVar8 = (ulong)uVar11;
  uVar3 = *(uint *)(param_3 + 0x7a4);
  if ((uVar11 == 0xffffffff) || (uVar6 = *param_6, uVar6 == 0xffffffff)) {
LAB_002d5374:
    local_60 = (ulong)uVar7;
    uVar11 = *(uint *)(param_2 + 0xaa40 + (ulong)uVar3 * 4);
    iVar5 = *(int *)(param_4 + 0xaa40 + local_60 * 4);
    if (uVar11 == 0) {
      if (iVar5 != 0) goto LAB_002d5398;
    }
    else {
      if (iVar5 != 0) {
        uVar11 = -uVar11 & uVar11;
        uVar7 = (uint)(0xffff < uVar11) << 4 | (uint)((uVar11 & 0xaaaaaaaa) != 0) |
                (uint)((uVar11 & 0xff00ff00) != 0) << 3 | (uint)((uVar11 & 0xf0f0f0f0) != 0) << 2 |
                (uint)((uVar11 & 0xcccccccc) != 0) * 2;
        *param_5 = uVar7;
        if (7 < uVar7) {
          nvAssertFailedNoLog("*peer0 < P2P_MAX_NUM_PEERS",
                              "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x1b4);
          return 0x40;
        }
        uVar7 = *(uint *)(param_2 + 0xaac4 + (ulong)uVar7 * 0x20);
        *param_6 = uVar7;
        if (7 < uVar7) {
          nvAssertFailedNoLog("*peer1 < P2P_MAX_NUM_PEERS",
                              "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x1b8);
          return 0x40;
        }
        if (*(uint *)(param_4 + 0xaac4 + (ulong)uVar7 * 0x20) != *param_5) {
          nvAssertFailedNoLog("pKernelBus1->p2pPcie.busPeer[*peer1].remotePeerId == *peer0",
                              "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x1bb);
          return 0x40;
        }
        piVar2 = (int *)(param_2 + 0xaac0 + (ulong)*param_5 * 0x20);
        *piVar2 = *piVar2 + 1;
        piVar2 = (int *)(param_4 + 0xaac0 + (ulong)*param_6 * 0x20);
        *piVar2 = *piVar2 + 1;
        if (*(char *)(param_2 + 0xaac8 + (ulong)*param_5 * 0x20) != '\0') {
          nvAssertFailedNoLog("!pKernelBus0->p2pPcie.busPeer[*peer0].bReserved",
                              "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x1c1);
        }
        if (*(char *)(param_4 + 0xaac8 + (ulong)*param_6 * 0x20) != '\0') {
          nvAssertFailedNoLog("!pKernelBus1->p2pPcie.busPeer[*peer1].bReserved",
                              "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x1c2);
        }
        portMemSet(local_44,0,0xc);
        local_3c = 1 << ((byte)*param_5 & 0x1f);
        iVar5 = (**(code **)(param_1 + 0x3b90))
                          (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                           *(undefined4 *)(param_1 + 0x3b3c),0x20800a88,local_44,0xc);
        if (iVar5 == 0) {
          portMemSet(local_44,0,0xc);
          local_3c = 1 << ((byte)*param_6 & 0x1f);
          iVar5 = (**(code **)(param_3 + 0x3b90))
                            (param_3 + 0x3b58,*(undefined4 *)(param_3 + 0x3b34),
                             *(undefined4 *)(param_3 + 0x3b3c),0x20800a88,local_44,0xc);
          if (iVar5 == 0) {
            return 0;
          }
          uVar10 = 0x1d1;
LAB_002d5882:
          nvAssertOkFailedNoLog
                    (iVar5,
                     "pRmApi->Control(pRmApi, pGpu1->hInternalClient, pGpu1->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_HSHUB_PEER_CONN_CONFIG, &params, sizeof(params))"
                     ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",uVar10);
          return iVar5;
        }
        uVar10 = 0x1c7;
        goto LAB_002d5a0b;
      }
LAB_002d5398:
      nvAssertFailedNoLog("(pKernelBus0->p2pPcie.peerNumberMask[gpuInst1] == 0) && (pKernelBus1->p2pPcie.peerNumberMask[gpuInst0] == 0)"
                          ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x1dc);
    }
    *param_5 = 0xffffffff;
    *param_6 = 0xffffffff;
    if ((param_1 == param_3) && (*(char *)(param_2 + 0xacf4) != '\0')) {
      uVar11 = *(uint *)(param_2 + 0xacf8);
      lVar12 = (ulong)uVar11 * 0x20 + param_2;
      if ((*(int *)(lVar12 + 0xaac0) == 0) &&
         ((*(char *)(lVar12 + 0xaac8) == '\0' &&
          (*(int *)(param_4 + 0xaac0 + (ulong)*(uint *)(param_4 + 0xacf8) * 0x20) == 0)))) {
        *param_6 = uVar11;
        *param_5 = uVar11;
      }
      else {
        nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x1ed,
                     "kbusCreateP2PMappingForMailbox_GM200",4,
                     "NVRM: - ERROR: Peer ID %d is already in use. Default RM P2P mapping will be used.\n"
                    );
        uVar11 = *param_5;
      }
      if (uVar11 == 0xffffffff) goto LAB_002d53d7;
    }
    else {
LAB_002d53d7:
      uVar11 = (**(code **)(param_2 + 0x2a0))(param_1,param_2);
      *param_5 = uVar11;
    }
    uVar6 = *param_6;
    if (uVar6 == 0xffffffff) {
      uVar6 = (**(code **)(param_4 + 0x2a0))(param_3,param_4);
      *param_6 = uVar6;
      uVar11 = *param_5;
      uVar4 = uVar6;
      if (uVar11 == 0xffffffff) goto LAB_002d56bb;
    }
    else {
      uVar11 = *param_5;
      uVar4 = uVar11;
    }
    uVar8 = (ulong)uVar11;
    if (uVar4 == 0xffffffff) {
LAB_002d56bb:
      *param_5 = 0xffffffff;
      *param_6 = 0xffffffff;
      nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x207,
                   "kbusCreateP2PMappingForMailbox_GM200",4,"NVRM: no peer IDs available\n");
      return 0x1a;
    }
  }
  else {
    if (7 < uVar11) {
      nvAssertFailedNoLog("*peer0 < P2P_MAX_NUM_PEERS",
                          "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x178);
      return 0x1f;
    }
    if (7 < uVar6) {
      nvAssertFailedNoLog("*peer1 < P2P_MAX_NUM_PEERS",
                          "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x179);
      return 0x1f;
    }
    lVar12 = uVar8 * 0x20 + param_2;
    if ((*(char *)(lVar12 + 0xaac8) != '\0') ||
       (lVar9 = (ulong)uVar6 * 0x20 + param_4, *(char *)(lVar9 + 0xaac8) != '\0')) {
LAB_002d532d:
      nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x1a8,
                   "kbusCreateP2PMappingForMailbox_GM200",3,
                   "NVRM: explicit peer IDs %u and %u requested for GPU%u and GPU%u are not available, will assign dynamically\n"
                   ,uVar8,uVar6,uVar7,uVar3);
      goto LAB_002d5374;
    }
    if ((*(int *)(lVar12 + 0xaac0) != 0) || (*(int *)(lVar9 + 0xaac0) != 0)) {
      if (((*(uint *)(param_2 + 0xaa40 + (ulong)uVar3 * 4) & 1 << ((byte)uVar11 & 0x1f)) != 0) &&
         ((*(uint *)(param_4 + 0xaa40 + (ulong)uVar7 * 4) & 1 << ((byte)uVar6 & 0x1f)) != 0)) {
        *(int *)(lVar12 + 0xaac0) = *(int *)(lVar12 + 0xaac0) + 1;
        piVar2 = (int *)(param_4 + 0xaac0 + (ulong)*param_6 * 0x20);
        *piVar2 = *piVar2 + 1;
        uVar7 = *param_5;
        uVar11 = *param_6;
        if (*(uint *)(param_2 + 0xaac4 + (ulong)uVar7 * 0x20) != uVar11) {
          nvAssertFailedNoLog("pKernelBus0->p2pPcie.busPeer[*peer0].remotePeerId == *peer1",
                              "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x18d);
          uVar11 = *param_6;
          uVar7 = *param_5;
        }
        if (*(uint *)(param_4 + 0xaac4 + (ulong)uVar11 * 0x20) != uVar7) {
          nvAssertFailedNoLog("pKernelBus1->p2pPcie.busPeer[*peer1].remotePeerId == *peer0",
                              "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x18e);
        }
        portMemSet(local_44,0,0xc);
        local_3c = 1 << ((byte)*param_5 & 0x1f);
        iVar5 = (**(code **)(param_1 + 0x3b90))
                          (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                           *(undefined4 *)(param_1 + 0x3b3c),0x20800a88,local_44,0xc);
        uVar10 = 0x193;
        if (iVar5 == 0) {
          portMemSet(local_44,0,0xc,0x193);
          local_3c = 1 << ((byte)*param_6 & 0x1f);
          iVar5 = (**(code **)(param_3 + 0x3b90))
                            (param_3 + 0x3b58,*(undefined4 *)(param_3 + 0x3b34),
                             *(undefined4 *)(param_3 + 0x3b3c),0x20800a88,local_44,0xc);
          uVar10 = 0x19d;
          if (iVar5 == 0) {
            return 0;
          }
          goto LAB_002d5882;
        }
        goto LAB_002d5a0b;
      }
      goto LAB_002d532d;
    }
  }
  local_60 = (ulong)uVar7;
  *(uint *)(param_2 + 0xaac4 + uVar8 * 0x20) = uVar6;
  puVar1 = (uint *)(param_2 + 0xaa40 + (ulong)uVar3 * 4);
  *puVar1 = *puVar1 | 1 << ((byte)*param_5 & 0x1f);
  *(uint *)(param_4 + 0xaac4 + (ulong)*param_6 * 0x20) = *param_5;
  puVar1 = (uint *)(param_4 + 0xaa40 + local_60 * 4);
  *puVar1 = *puVar1 | 1 << ((byte)*param_6 & 0x1f);
  uVar8 = (ulong)*param_5;
  if (*(int *)(param_2 + 0xaac0 + uVar8 * 0x20) != 0) {
    nvAssertFailedNoLog("pKernelBus0->p2pPcie.busPeer[*peer0].refCount == 0",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x211);
    uVar8 = (ulong)*param_5;
  }
  if (*(char *)(param_2 + 0xaac8 + uVar8 * 0x20) != '\0') {
    nvAssertFailedNoLog("!pKernelBus0->p2pPcie.busPeer[*peer0].bReserved",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x212);
  }
  uVar8 = (ulong)*param_6;
  if (*(int *)(param_4 + 0xaac0 + uVar8 * 0x20) != 0) {
    nvAssertFailedNoLog("pKernelBus1->p2pPcie.busPeer[*peer1].refCount == 0",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x213);
    uVar8 = (ulong)*param_6;
  }
  if (*(char *)(param_4 + 0xaac8 + uVar8 * 0x20) != '\0') {
    nvAssertFailedNoLog("!pKernelBus1->p2pPcie.busPeer[*peer1].bReserved",
                        "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x214);
  }
  piVar2 = (int *)(param_2 + 0xaac0 + (ulong)*param_5 * 0x20);
  *piVar2 = *piVar2 + 1;
  piVar2 = (int *)(param_4 + 0xaac0 + (ulong)*param_6 * 0x20);
  *piVar2 = *piVar2 + 1;
  portMemSet(local_44,0,0xc);
  local_3c = 1 << ((byte)*param_5 & 0x1f);
  iVar5 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800a88,local_44,0xc);
  uVar10 = 0x220;
  if (iVar5 == 0) {
    portMemSet(local_44,0,0xc);
    local_3c = 1 << ((byte)*param_6 & 0x1f);
    iVar5 = (**(code **)(param_3 + 0x3b90))
                      (param_3 + 0x3b58,*(undefined4 *)(param_3 + 0x3b34),
                       *(undefined4 *)(param_3 + 0x3b3c),0x20800a88,local_44,0xc);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,
                 "pRmApi->Control(pRmApi, pGpu1->hInternalClient, pGpu1->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_HSHUB_PEER_CONN_CONFIG, &params, sizeof(params))"
                 ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x22a);
      return iVar5;
    }
    nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x231,
                 "kbusCreateP2PMappingForMailbox_GM200",1,
                 "NVRM: added PCIe P2P mapping between GPU%u (peer %u) and GPU%u (peer %u)\n",uVar7,
                 *param_5,uVar3,*param_6);
    (**(code **)(param_2 + 0x2c8))(param_1,param_2,param_3,param_4,*param_5,*param_6);
    (**(code **)(param_4 + 0x2c8))(param_3,param_4,param_1,param_2,*param_6,*param_5);
    return 0;
  }
LAB_002d5a0b:
  nvAssertOkFailedNoLog
            (iVar5,
             "pRmApi->Control(pRmApi, pGpu0->hInternalClient, pGpu0->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_HSHUB_PEER_CONN_CONFIG, &params, sizeof(params))"
             ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",uVar10);
  return iVar5;
}


// ===== 002d5d40 kbusNeedWarForBug999673_GM200 =====

bool kbusNeedWarForBug999673_GM200(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char local_9;
  
  local_9 = '\0';
  if (*(char *)(*(long *)(g_pSys + 0x208) + 0x62) == '\0') {
    return false;
  }
  clFindCommonDownstreamBR_IMPL(param_1,param_3,*(long *)(g_pSys + 0x208),&local_9);
  return local_9 == -1;
}


// ===== 002d5d90 kbusRemoveP2PMappingForMailbox_GM200 =====

undefined8
kbusRemoveP2PMappingForMailbox_GM200
          (long param_1,long param_2,long param_3,long param_4,uint param_5,uint param_6)

{
  uint *puVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  int iVar9;
  uint uVar10;
  
  if ((*(char *)(param_1 + 0x908) != '\0') || (*(char *)(param_3 + 0x908) != '\0')) {
    return 0x56;
  }
  if ((param_5 != 0xffffffff) && (param_6 != 0xffffffff)) {
    uVar6 = (ulong)*(uint *)(param_3 + 0x7a4);
    lVar2 = param_2 + uVar6 * 4;
    uVar10 = 1 << ((byte)param_5 & 0x1f);
    if ((*(uint *)(lVar2 + 0xaa40) & uVar10) != 0) {
      uVar8 = (ulong)*(uint *)(param_1 + 0x7a4);
      lVar3 = param_4 + uVar8 * 4;
      uVar5 = 1 << ((byte)param_6 & 0x1f);
      if ((*(uint *)(lVar3 + 0xaa40) & uVar5) != 0) {
        lVar7 = (ulong)param_5 * 0x20 + param_2;
        if (*(int *)(lVar7 + 0xaac0) == 0) {
          return 0xffff;
        }
        lVar4 = param_4 + (ulong)param_6 * 0x20;
        iVar9 = *(int *)(lVar4 + 0xaac0);
        if (*(int *)(lVar7 + 0xaac0) != iVar9) {
          return 0xffff;
        }
        if (iVar9 == 0) {
          return 0xffff;
        }
        *(int *)(lVar4 + 0xaac0) = iVar9 + -1;
        iVar9 = *(int *)(lVar7 + 0xaac0) + -1;
        *(int *)(lVar7 + 0xaac0) = iVar9;
        if (iVar9 == 0) {
          nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x2cd,
                       "kbusRemoveP2PMappingForMailbox_GM200",1,
                       "NVRM: Removing mapping GPU %d Peer %d <-> GPU %d Peer %d\n",uVar8,param_5,
                       uVar6,param_6);
          puVar1 = (uint *)(lVar2 + 0xaa40);
          *puVar1 = *puVar1 & ~uVar10;
          puVar1 = (uint *)(lVar3 + 0xaa40);
          *puVar1 = *puVar1 & ~uVar5;
          kbusDestroyMailbox_IMPL(param_1,param_2,param_3,param_5);
          kbusDestroyMailbox_IMPL(param_3,param_4,param_1,param_6);
          return 0;
        }
        nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x2d9,
                     "kbusRemoveP2PMappingForMailbox_GM200",1,
                     "NVRM: Decremented refCount for Mapping GPU %d Peer %d  <-> GPU %d Peer %d New Count: %d\n"
                     ,uVar8,param_5,uVar6,param_6,iVar9);
        return 0;
      }
    }
  }
  return 0x1f;
}


// ===== 002d5fd0 kbusReserveP2PPeerIds_GM200 =====

undefined1  [16] kbusReserveP2PPeerIds_GM200(long param_1,long param_2,ulong param_3)

{
  undefined1 auVar1 [16];
  uint uVar2;
  ulong uVar3;
  int *piVar4;
  int iVar5;
  undefined1 auVar6 [16];
  ulong uStack_30;
  
  if ((int)param_3 != 0) {
    uVar3 = param_3 & 0xffffffff;
    piVar4 = (int *)(param_2 + 0xaac0);
    iVar5 = 0;
    do {
      uVar2 = (uint)uVar3;
      if ((uVar3 & 1) != 0) {
        do {
          nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x2f7,
                       "kbusReserveP2PPeerIds_GM200",1,
                       "NVRM: reserving peer ID %u on GPU%u for NVLINK/C2C use\n",iVar5,
                       *(undefined4 *)(param_1 + 0x7a4));
          if (*piVar4 != 0) {
            auVar6._8_8_ = uStack_30;
            auVar6._0_8_ = 0x17;
            return auVar6;
          }
          uVar2 = (uint)uVar3 >> 1;
          uVar3 = (ulong)uVar2;
          *(undefined1 *)(piVar4 + 2) = 1;
          param_3 = uStack_30;
          if (uVar2 == 0) goto LAB_002d608c;
          iVar5 = iVar5 + 1;
          piVar4 = piVar4 + 8;
        } while ((uVar2 & 1) != 0);
      }
      iVar5 = iVar5 + 1;
      uVar3 = (ulong)(uVar2 >> 1);
      piVar4 = piVar4 + 8;
    } while( true );
  }
LAB_002d608c:
  auVar1._8_8_ = 0;
  auVar1._0_8_ = param_3;
  return auVar1 << 0x40;
}


// ===== 002d60c0 kbusSetP2PMailboxBar1Area_GM200 =====

/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */

undefined8
kbusSetP2PMailboxBar1Area_GM200(undefined8 param_1,long param_2,ulong param_3,uint param_4)

{
  ulong uVar1;
  uint local_14;
  int local_10;
  uint local_c;
  
  if (*(char *)(param_2 + 0xad01) == '\0') {
    return 0;
  }
  if (param_4 == 0) {
    nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x326,
                 "kbusSetP2PMailboxBar1Area_GM200",4,"NVRM: P2P mailbox area size is not set\n");
  }
  else {
    (**(code **)(param_2 + 600))(param_1,param_2,&local_14,&local_10,&local_c);
    uVar1 = (ulong)param_4;
    if (local_14 == param_4) {
      if ((local_10 - 1 & param_3) == 0) {
        if (uVar1 + param_3 < (ulong)local_c << 0x10) {
          if (*(ulong *)(param_2 + 0xabc0) == 0xffffffffffffffff) {
            *(ulong *)(param_2 + 0xabc0) = param_3;
            *(ulong *)(param_2 + 0xabc8) = uVar1;
            *(undefined1 *)(param_2 + 0xad00) = 1;
            return 0;
          }
          if (*(ulong *)(param_2 + 0xabc0) == param_3) {
            if (uVar1 == *(ulong *)(param_2 + 0xabc8)) {
              return 0;
            }
            nvAssertFailedNoLog("mailboxTotalSize == pKernelBus->p2pPcie.writeMailboxTotalSize",
                                "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x337);
          }
          else {
            nvAssertFailedNoLog("mailboxBar1Addr == pKernelBus->p2pPcie.writeMailboxBar1Addr",
                                "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x336);
          }
        }
        else {
          nvAssertFailedNoLog("(mailboxBar1Addr + mailboxTotalSize) < (((NvU64)mailboxBar1MaxOffset64KBReq) << 16)"
                              ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x331);
        }
      }
      else {
        nvAssertFailedNoLog("(mailboxBar1Addr & (mailboxAlignmentSizeReq - 1)) == 0",
                            "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x32f);
      }
    }
    else {
      nvAssertFailedNoLog("mailboxTotalSize == mailboxAreaSizeReq",
                          "src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x32d);
    }
  }
  return 0x1f;
}


// ===== 002d6260 kbusUnsetP2PMailboxBar1Area_GM200 =====

void kbusUnsetP2PMailboxBar1Area_GM200(undefined8 param_1,long param_2)

{
  int *piVar1;
  int iVar2;
  
  if (*(char *)(param_2 + 0xad01) != '\0') {
    piVar1 = (int *)(param_2 + 0xaac0);
    iVar2 = 0;
    do {
      if (*piVar1 != 0) {
        return;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 8;
    } while (iVar2 != 8);
    *(undefined8 *)(param_2 + 0xabc0) = 0xffffffffffffffff;
    *(undefined8 *)(param_2 + 0xabc8) = 0;
    *(undefined1 *)(param_2 + 0xad00) = 0;
  }
  return;
}


// ===== 002d62b0 kbusAllocP2PMailboxBar1_GM200 =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int kbusAllocP2PMailboxBar1_GM200(long param_1,long param_2,ulong param_3,ulong param_4)

{
  long *plVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  ulong uVar6;
  
  lVar3 = gpumgrGetParentGPU();
  lVar4 = gpumgrGetParentGPU(param_1);
  uVar5 = 0;
  if (param_1 != lVar4) {
    uVar5 = 0x80;
    *(undefined8 *)(param_2 + 0xabc0) = *(undefined8 *)(*(long *)(&DAT_00001b90 + lVar3) + 0xabc0);
  }
  *(undefined8 *)(param_2 + 0xabc8) = 0x80000;
  plVar1 = *(long **)(param_2 + 0x630 + (param_3 & 0xffffffff) * 0x100);
  uVar6 = 0x3ffffffff;
  if (param_4 < 0x400000000) {
    uVar6 = param_4;
  }
  iVar2 = (**(code **)(*plVar1 + 0x38))(plVar1,0x80000,0x10000,0,uVar6,0,uVar5,param_2 + 0xabc0);
  if (iVar2 == 0) {
    lVar4 = *(long *)(param_2 + 0xabc0);
    if (*(long *)(*(long *)(&DAT_00001b90 + lVar3) + 0xabc0) != lVar4) {
      nvAssertFailedNoLog("GPU_GET_KERNEL_BUS(pParentGpu)->p2pPcie.writeMailboxBar1Addr == pKernelBus->p2pPcie.writeMailboxBar1Addr"
                          ,"src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x395,uVar5);
      lVar4 = *(long *)(param_2 + 0xabc0);
    }
    nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x397,
                 "kbusAllocP2PMailboxBar1_GM200",1,
                 "NVRM: [GPU%u] P2P write mailboxes allocated at BAR1 addr = 0x%llx\n",
                 *(undefined4 *)(param_1 + 0x7a4),lVar4);
  }
  else {
    nvDbg_Printf("src/kernel/gpu/bus/arch/maxwell/kern_bus_gm200.c",0x38f,
                 "kbusAllocP2PMailboxBar1_GM200",4,
                 "NVRM: cannot allocate vaspace for P2P write mailboxes (0x%x)\n",iVar2);
    *(undefined8 *)(param_2 + 0xabc0) = 0xffffffffffffffff;
    *(undefined8 *)(param_2 + 0xabc8) = 0;
  }
  return iVar2;
}


// ===== 002d6430 _kbusExecGspRmRpcForNvlink.constprop.0.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _kbusExecGspRmRpcForNvlink_constprop_0_isra_0
               (long param_1,undefined4 param_2,undefined8 param_3)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint local_3c [3];
  
  uVar3 = rmGpuLocksGetOwnedMask();
  local_3c[0] = uVar3 | 1 << (*(uint *)(param_1 + 0x7a4) & 0x1f);
  if ((*(char *)(param_1 + 0x909) == '\0') ||
     (cVar2 = rmGpuGroupLockIsOwner(*(uint *)(param_1 + 0x7a4),2,local_3c), cVar2 != '\0')) {
    (**(code **)(param_1 + 0x3b90))
              (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),*(undefined4 *)(param_1 + 0x3b3c),
               param_2,param_3,0x20);
  }
  else {
    iVar4 = rmGpuGroupLockAcquire(*(undefined4 *)(param_1 + 0x7a4),2,2,0x20002,local_3c);
    uVar1 = local_3c[0];
    if (iVar4 == 0) {
      (**(code **)(param_1 + 0x3b90))
                (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                 *(undefined4 *)(param_1 + 0x3b3c),param_2,param_3,0x20);
      if ((uVar1 & ~uVar3) != 0) {
        rmGpuGroupLockRelease(uVar1 & ~uVar3,0);
        return;
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x71,
                   "_kbusExecGspRmRpcForNvlink",4,"NVRM: Failed to acquire locks for gpumask 0x%x\n"
                   ,local_3c[0]);
    }
  }
  return;
}


// ===== 002d6590 _kbusRemoveNvlinkPeerMapping =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _kbusRemoveNvlinkPeerMapping(long param_1,long param_2,long param_3,uint param_4,uint param_5)

{
  long lVar1;
  long lVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
  undefined8 uVar9;
  char *pcVar10;
  uint uVar11;
  ulong uVar12;
  ulong local_58;
  undefined1 local_50;
  undefined4 local_4c;
  
  uVar7 = (ulong)*(uint *)(param_3 + 0x7a4);
  uVar11 = 1 << ((byte)param_4 & 0x1f);
  lVar1 = param_2 + uVar7 * 4;
  if ((*(uint *)(lVar1 + 0xa8f4) & uVar11) == 0) {
    return 0x10006;
  }
  uVar12 = (ulong)param_4;
  lVar2 = param_2 + uVar12 * 4;
  iVar6 = *(int *)(lVar2 + 0xa9f4);
  if ((iVar6 == 0) || (*(int *)(lVar1 + 0xa974) == 0)) {
    return 0x40;
  }
  iVar5 = *(int *)(lVar1 + 0xa974) + -1;
  *(int *)(lVar2 + 0xa9f4) = iVar6 + -1;
  *(int *)(lVar1 + 0xa974) = iVar5;
  if ((param_5 & 0x10) != 0) {
    *(int *)(lVar2 + 0xa9f4) = iVar6 + -2;
  }
  if ((iVar5 == 0) || (*(int *)(lVar2 + 0xa9f4) == 0)) {
    nvDbg_Printf("src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x1ef,
                 "_kbusRemoveNvlinkPeerMapping",1,
                 "NVRM: Removing mapping for GPU%u peer %u (GPU%u)\n",
                 *(undefined4 *)(param_1 + 0x7a4),param_4,uVar7);
    *(uint *)(lVar1 + 0xa8f4) = *(uint *)(lVar1 + 0xa8f4) & ~uVar11;
    lVar1 = g_pSys;
    if (*(int *)(lVar2 + 0xa9f4) == 0) {
      uVar8 = (ulong)*(uint *)(param_1 + 0x7a4);
      nvDbg_Printf("src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x200,
                   "_kbusRemoveNvlinkPeerMapping",1,
                   "NVRM: PeerID %u is not being used for P2P from GPU%d to any other remote GPU. Can be freed\n"
                   ,param_4,uVar8,uVar7);
      if (*(char *)(param_2 + 0x558) != '\0') {
        (**(code **)(param_2 + 0x500))(param_1,param_2,1,uVar8);
        (**(code **)(*(long *)(&DAT_00001b90 + param_3) + 0x500))
                  (param_3,*(long *)(&DAT_00001b90 + param_3),1);
      }
      if (*(char *)(param_1 + 0x4a4e) != '\0') {
        iVar6 = osAcquireRmSema(*(undefined8 *)(lVar1 + 0x160));
        if (iVar6 != 0) {
          nvAssertOkFailedNoLog
                    (iVar6,"osAcquireRmSema(pSys->pSema)",
                     "src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x20f);
          return iVar6;
        }
        portMemSet(&local_58,0,0x20);
        local_58 = uVar12 << 0x20 | 1;
        local_50 = 0;
        local_4c = *(undefined4 *)(param_3 + 0x7ac);
        _kbusExecGspRmRpcForNvlink_constprop_0_isra_0(param_1,0x2080182f,&local_58);
        osReleaseRmSema(*(undefined8 *)(lVar1 + 0x160),0);
        return 0;
      }
      lVar1 = *(long *)(param_1 + 0x1ce8);
      if (lVar1 == 0) {
        nvAssertFailedNoLog("pKernelNvlink0 != NULL",
                            "src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x221);
        return 0x56;
      }
      portMemSet(&local_58,0,8);
      local_58._0_5_ = (uint5)uVar11;
      iVar6 = knvlinkExecGspRmRpc_IMPL(param_1,lVar1,0x20800a21,&local_58,8);
      if (iVar6 == 0) {
        if (((*(char *)(param_2 + 0x558) == '\0') ||
            (cVar4 = knvlinkIsForcedConfig_IMPL(param_1,lVar1), cVar4 != '\0')) ||
           (iVar6 = (**(code **)(lVar1 + 0x1e0))(param_1,lVar1,0,uVar11,0), iVar6 == 0)) {
          iVar6 = knvlinkSyncLinkMasksAndVbiosInfo_IMPL(param_1,lVar1);
          if (iVar6 != 0) {
            return iVar6;
          }
          if (((param_4 < 0x20) &&
              ((*(ulong *)(lVar1 + 0x3b8) & *(ulong *)(lVar1 + 0x14c8 + uVar12 * 8)) != 0)) &&
             (*(char *)(lVar1 + 0x2e4) != '\0')) {
            return 0;
          }
          iVar6 = knvlinkUpdateCurrentConfig_IMPL(param_1,lVar1);
          return iVar6;
        }
        pcVar10 = "NVRM: GPU%d Failed to remove hshub mapping for peer%d\n";
        uVar3 = *(undefined4 *)(param_1 + 0x7a4);
        uVar9 = 0x23d;
      }
      else {
        pcVar10 = "NVRM: GPU%d Failed to UNSET USE_NVLINK_PEER for peer%d\n";
        uVar3 = *(undefined4 *)(param_1 + 0x7a4);
        uVar9 = 0x22d;
      }
      nvDbg_Printf("src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",uVar9,
                   "_kbusRemoveNvlinkPeerMapping",4,pcVar10,uVar3,param_4);
      return iVar6;
    }
  }
  return 0;
}


// ===== 002d69f0 _kbusCreateNvlinkPeerMapping.isra.0 =====

int _kbusCreateNvlinkPeerMapping_isra_0(undefined8 param_1,long param_2,long param_3,ulong param_4)

{
  long lVar1;
  int iVar2;
  ulong local_58;
  byte local_50;
  byte local_4f;
  undefined1 local_4e;
  undefined4 local_4c;
  
  lVar1 = g_pSys;
  iVar2 = osAcquireRmSema(*(undefined8 *)(g_pSys + 0x160));
  if (iVar2 == 0) {
    portMemSet(&local_58,0,0x20);
    local_58 = param_3 << 0x20 | 1;
    local_4f = (byte)((uint)param_4 >> 4) & 1;
    local_50 = (byte)((param_4 & 0xffffffff) >> 5) & 1;
    local_4c = *(undefined4 *)(param_2 + 0x7ac);
    local_4e = 0;
    _kbusExecGspRmRpcForNvlink_constprop_0_isra_0(param_1,0x2080182e,&local_58);
    osReleaseRmSema(*(undefined8 *)(lVar1 + 0x160),0);
  }
  else {
    nvAssertOkFailedNoLog
              (iVar2,"osAcquireRmSema(pSys->pSema)",
               "src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x9f);
  }
  return iVar2;
}


// ===== 002d6ac0 kbusCreateP2PMappingForNvlink_GP100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusCreateP2PMappingForNvlink_GP100
              (long param_1,long param_2,long param_3,long param_4,uint *param_5,uint *param_6,
              uint param_7)

{
  uint *puVar1;
  long lVar2;
  long lVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  byte bVar10;
  ulong uVar11;
  int local_40;
  undefined1 local_3c;
  
  if ((param_5 == (uint *)0x0) || (param_6 == (uint *)0x0)) {
    return 0x1f;
  }
  uVar5 = *(uint *)(param_1 + 0x7a4);
  uVar6 = *(uint *)(param_3 + 0x7a4);
  if ((*param_5 == 0xffffffff) || (*param_6 == 0xffffffff)) {
    if (((param_7 & 0x20) != 0) || (param_1 != param_3)) {
      iVar8 = (**(code **)(param_2 + 0x2b0))(param_1,param_2,param_3,param_4,param_5,param_7);
      if (iVar8 != 0) {
        return iVar8;
      }
      if (param_1 == param_3) {
        *param_6 = *param_5;
      }
      else {
        iVar8 = (**(code **)(param_4 + 0x2b0))(param_3,param_4,param_1,param_2,param_6,param_7);
        if (iVar8 != 0) {
          return iVar8;
        }
      }
      if (*param_5 == 0xffffffff) {
        return 0x3f;
      }
      if (*param_6 == 0xffffffff) {
        return 0x3f;
      }
      nvDbg_Printf("src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x10e,
                   "kbusCreateP2PMappingForNvlink_GP100",1,
                   "NVRM: - P2P: Using Default RM mapping for P2P.\n");
      goto LAB_002d6b27;
    }
    if (*(char *)(param_2 + 0xacf4) == '\0') {
      *param_6 = 0;
      *param_5 = 0;
      iVar8 = kbusReserveP2PPeerIds_GM200(param_1,param_2,1);
      if (iVar8 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar8,"kbusReserveP2PPeerIds_HAL(pGpu0, pKernelBus0, NVBIT(0))",
                   "src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0xe9);
        return iVar8;
      }
    }
    else {
      uVar9 = *(uint *)(param_2 + 0xacf8);
      *param_6 = uVar9;
      *param_5 = uVar9;
    }
    nvDbg_Printf("src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x10e,
                 "kbusCreateP2PMappingForNvlink_GP100",1,
                 "NVRM: - P2P: Using Default RM mapping for P2P.\n");
    uVar11 = (ulong)*param_5;
    if ((*(uint *)(param_2 + 0xa8f4 + (ulong)uVar6 * 4) & 1 << ((byte)*param_5 & 0x1f)) != 0)
    goto LAB_002d6d9c;
LAB_002d6dc5:
    bVar10 = (byte)uVar11;
    if (*(char *)(param_2 + 0xacf4) != '\0') {
      uVar9 = *(uint *)(param_2 + 0xacf8);
      if ((*(int *)(param_2 + 0xa9f4 + (ulong)uVar9 * 4) == 0) &&
         (*(int *)(param_4 + 0xa9f4 + (ulong)*(uint *)(param_4 + 0xacf8) * 4) == 0)) {
        *param_6 = uVar9;
        uVar7 = 1 << ((byte)uVar9 & 0x1f);
        *param_5 = uVar9;
        uVar9 = *(uint *)(param_2 + 0xa8f4 + (ulong)uVar6 * 4);
      }
      else {
        nvDbg_Printf("src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x14b,
                     "kbusCreateP2PMappingForNvlink_GP100",4,
                     "NVRM: - ERROR: Peer ID %d is already in use. Default RM P2P mapping will be used for loopback connection.\n"
                    );
        uVar9 = *(uint *)(param_2 + 0xa8f4 + (ulong)uVar6 * 4);
        uVar7 = 1 << ((byte)*param_5 & 0x1f);
      }
      goto LAB_002d6b80;
    }
  }
  else {
LAB_002d6b27:
    if ((param_7 & 0x20) == 0) {
      uVar11 = (ulong)*param_5;
      if ((*(uint *)(param_2 + 0xa8f4 + (ulong)uVar6 * 4) & 1 << ((byte)*param_5 & 0x1f)) != 0)
      goto LAB_002d6d9c;
    }
    else {
      nvDbg_Printf("src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x113,
                   "kbusCreateP2PMappingForNvlink_GP100",1,"NVRM: EGM peer\n");
      uVar11 = (ulong)*param_5;
      uVar9 = *(uint *)(param_2 + 0xa8f4 + (ulong)uVar6 * 4);
      uVar7 = 1 << ((byte)*param_5 & 0x1f);
      if ((uVar9 & uVar7) == 0) goto LAB_002d6b80;
LAB_002d6d9c:
      if ((*(uint *)(param_4 + 0xa8f4 + (ulong)uVar5 * 4) & 1 << ((byte)*param_6 & 0x1f)) != 0) {
        piVar4 = (int *)(param_2 + 0xa9f4 + uVar11 * 4);
        *piVar4 = *piVar4 + 1;
        piVar4 = (int *)(param_4 + 0xa9f4 + (ulong)*param_6 * 4);
        *piVar4 = *piVar4 + 1;
        piVar4 = (int *)(param_2 + 0xa974 + (ulong)uVar6 * 4);
        *piVar4 = *piVar4 + 1;
        piVar4 = (int *)(param_4 + 0xa974 + (ulong)uVar5 * 4);
        *piVar4 = *piVar4 + 1;
        if ((param_7 & 0x10) != 0) {
          piVar4 = (int *)(param_2 + 0xa9f4 + (ulong)*param_5 * 4);
          *piVar4 = *piVar4 + 1;
          piVar4 = (int *)(param_4 + 0xa9f4 + (ulong)*param_6 * 4);
          *piVar4 = *piVar4 + 1;
        }
        nvDbg_Printf("src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x131,
                     "kbusCreateP2PMappingForNvlink_GP100",1,
                     "NVRM: - P2P: Peer mapping is already in use for gpu instances %x and %x with peer id\'s %d and %d. Increasing the mapping refcounts for the peer IDs to %d and %d respectively.\n"
                     ,uVar5,uVar6,*param_5,(ulong)*param_6,
                     *(undefined4 *)(param_2 + 0xa9f4 + (ulong)*param_5 * 4),
                     *(undefined4 *)(param_4 + 0xa9f4 + (ulong)*param_6 * 4));
        return 0;
      }
    }
    bVar10 = (byte)uVar11;
    if (((param_7 & 0x20) == 0) && (param_1 == param_3)) goto LAB_002d6dc5;
  }
  uVar9 = *(uint *)(param_2 + 0xa8f4 + (ulong)uVar6 * 4);
  uVar7 = 1 << (bVar10 & 0x1f);
LAB_002d6b80:
  lVar2 = param_2 + (ulong)uVar6 * 4;
  lVar3 = param_4 + (ulong)uVar5 * 4;
  *(uint *)(lVar2 + 0xa8f4) = uVar9 | uVar7;
  puVar1 = (uint *)(lVar3 + 0xa8f4);
  *puVar1 = *puVar1 | 1 << ((byte)*param_6 & 0x1f);
  piVar4 = (int *)(param_2 + 0xa9f4 + (ulong)*param_5 * 4);
  *piVar4 = *piVar4 + 1;
  piVar4 = (int *)(param_4 + 0xa9f4 + (ulong)*param_6 * 4);
  *piVar4 = *piVar4 + 1;
  if ((param_7 & 0x10) != 0) {
    piVar4 = (int *)(param_2 + 0xa9f4 + (ulong)*param_5 * 4);
    *piVar4 = *piVar4 + 1;
    piVar4 = (int *)(param_4 + 0xa9f4 + (ulong)*param_6 * 4);
    *piVar4 = *piVar4 + 1;
  }
  piVar4 = (int *)(lVar2 + 0xa974);
  *piVar4 = *piVar4 + 1;
  piVar4 = (int *)(lVar3 + 0xa974);
  *piVar4 = *piVar4 + 1;
  nvDbg_Printf("src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x16a,
               "kbusCreateP2PMappingForNvlink_GP100",1,
               "NVRM: added NVLink P2P mapping between GPU%u (peer %u) and GPU%u (peer %u)\n",uVar5,
               *param_5,uVar6,*param_6);
  if (*(char *)(param_1 + 0x4a4e) != '\0') {
    iVar8 = _kbusCreateNvlinkPeerMapping_isra_0(param_1,param_3,*param_5,param_7);
    if (iVar8 != 0) {
      nvAssertOkFailedNoLog
                (iVar8,"_kbusCreateNvlinkPeerMapping(pGpu0, pKernelBus0, pGpu1, *peer0, attributes)"
                 ,"src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x170);
      return iVar8;
    }
    iVar8 = _kbusCreateNvlinkPeerMapping_isra_0(param_3,param_1,*param_6,param_7);
    if (iVar8 != 0) {
      nvAssertOkFailedNoLog
                (iVar8,"_kbusCreateNvlinkPeerMapping(pGpu1, pKernelBus1, pGpu0, *peer1, attributes)"
                 ,"src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x171);
      return iVar8;
    }
    return 0;
  }
  lVar2 = *(long *)(param_1 + 0x1ce8);
  lVar3 = *(long *)(param_3 + 0x1ce8);
  if ((lVar2 == 0) || (lVar3 == 0)) {
    return 0x3f;
  }
  portMemSet(&local_40,0,8);
  local_3c = 1;
  local_40 = 1 << ((byte)*param_5 & 0x1f);
  iVar8 = knvlinkExecGspRmRpc_IMPL(param_1,lVar2,0x20800a21,&local_40,8);
  if (iVar8 != 0) {
    nvDbg_Printf("src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x18a,
                 "kbusCreateP2PMappingForNvlink_GP100",4,
                 "NVRM: GPU%d Failed to ENABLE USE_NVLINK_PEER for peer%d\n",
                 *(undefined4 *)(param_1 + 0x7a4),*param_5);
    return iVar8;
  }
  portMemSet(&local_40,0,8);
  local_3c = 1;
  local_40 = 1 << ((byte)*param_6 & 0x1f);
  iVar8 = knvlinkExecGspRmRpc_IMPL(param_3,lVar3,0x20800a21,&local_40,8);
  if (iVar8 != 0) {
    nvDbg_Printf("src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x19b,
                 "kbusCreateP2PMappingForNvlink_GP100",4,
                 "NVRM: GPU%d Failed to ENABLE USE_NVLINK_PEER for peer%d\n",
                 *(undefined4 *)(param_3 + 0x7a4),*param_6);
    return iVar8;
  }
  (**(code **)(lVar2 + 0x200))(param_1,lVar2,param_3,*param_5);
  (**(code **)(lVar3 + 0x200))(param_3,lVar3,param_1,*param_6);
  return 0;
}


// ===== 002d71c0 kbusCreateP2PMapping_GP100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbusCreateP2PMapping_GP100(undefined8 param_1,long param_2,undefined8 param_3)

{
  undefined8 uVar1;
  uint in_stack_00000008;
  
  in_stack_00000008 = in_stack_00000008 & 0xf;
  if (in_stack_00000008 - 3 < 2) {
    uVar1 = kbusCreateP2PMappingForNvlink_GP100(param_1,param_2,param_3);
    return uVar1;
  }
  if (in_stack_00000008 == 1) {
    uVar1 = (**(code **)(param_2 + 0x2b8))(param_1,param_2,param_3);
    return uVar1;
  }
  nvDbg_Printf("src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x49,"kbusCreateP2PMapping_GP100",4
               ,"NVRM: P2P type %d is not supported\n",in_stack_00000008);
  return 0x56;
}


// ===== 002d7230 kbusRemoveP2PMappingForNvlink_GP100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusRemoveP2PMappingForNvlink_GP100
              (long param_1,long param_2,long param_3,long param_4,uint param_5,uint param_6,
              undefined4 param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 1 << ((byte)param_5 & 0x1f);
  if (((*(uint *)(param_2 + 0xa8f4 + (ulong)*(uint *)(param_3 + 0x7a4) * 4) & uVar4) == 0) ||
     (uVar3 = 1 << ((byte)param_6 & 0x1f),
     (*(uint *)(param_4 + 0xa8f4 + (ulong)*(uint *)(param_1 + 0x7a4) * 4) & uVar3) == 0)) {
    iVar1 = 0x40;
  }
  else {
    iVar1 = _kbusRemoveNvlinkPeerMapping();
    if (iVar1 == 0) {
      iVar1 = _kbusRemoveNvlinkPeerMapping(param_3,param_4,param_1,param_6,param_7);
      if (iVar1 == 0) {
        if (((*(int *)(param_2 + 0xa9f4 + (ulong)param_5 * 4) == 0) &&
            (*(char *)(param_2 + 0x558) != '\0')) &&
           (iVar2 = (**(code **)(param_2 + 0x2f8))(param_1,param_2,uVar4), iVar2 != 0)) {
          nvDbg_Printf("src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x2b5,
                       "kbusRemoveP2PMappingForNvlink_GP100",4,
                       "NVRM: GPU%d: Failed to unreserve peer ID mask 0x%x\n",
                       *(undefined4 *)(param_1 + 0x7a4),uVar4);
          iVar1 = iVar2;
        }
        else if (((*(int *)(param_4 + 0xa9f4 + (ulong)param_6 * 4) == 0) &&
                 (iVar1 = 0, *(char *)(param_4 + 0x558) != '\0')) &&
                (iVar1 = (**(code **)(param_4 + 0x2f8))(param_3,param_4,uVar3), iVar1 != 0)) {
          nvDbg_Printf("src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x2c3,
                       "kbusRemoveP2PMappingForNvlink_GP100",4,
                       "NVRM: GPU%d: Failed to unreserve peer ID mask 0x%x\n",
                       *(undefined4 *)(param_3 + 0x7a4),uVar3);
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar1,
                   "_kbusRemoveNvlinkPeerMapping(pGpu1, pKernelBus1, pGpu0, peer1, attributes)",
                   "src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x2a7);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar1,"_kbusRemoveNvlinkPeerMapping(pGpu0, pKernelBus0, pGpu1, peer0, attributes)",
                 "src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x2a6);
    }
  }
  return iVar1;
}


// ===== 002d7480 kbusRemoveP2PMapping_GP100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbusRemoveP2PMapping_GP100(undefined8 param_1,long param_2,undefined8 param_3)

{
  undefined8 uVar1;
  uint in_stack_00000008;
  
  in_stack_00000008 = in_stack_00000008 & 0xf;
  if (in_stack_00000008 - 3 < 2) {
    uVar1 = kbusRemoveP2PMappingForNvlink_GP100(param_1,param_2,param_3);
    return uVar1;
  }
  if (in_stack_00000008 == 1) {
    uVar1 = (**(code **)(param_2 + 0x2c0))(param_1,param_2,param_3);
    return uVar1;
  }
  nvDbg_Printf("src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x280,"kbusRemoveP2PMapping_GP100",
               4,"NVRM: P2P type %d is not supported\n",in_stack_00000008);
  return 0x56;
}


// ===== 002d74f0 kbusGetPeerId_GP100 =====

long kbusGetPeerId_GP100(long param_1,long param_2,long param_3)

{
  long lVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_2 + 0xa8f4 + (ulong)*(uint *)(param_3 + 0x7a4) * 4);
  lVar1 = 0;
  if (uVar2 == 0) {
    nvDbg_Printf("src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x2e5,"kbusGetPeerId_GP100",1,
                 "NVRM: NVLINK P2P not set up between GPU%u and GPU%u, checking for PCIe P2P...\n",
                 *(undefined4 *)(param_1 + 0x7a4),(ulong)*(uint *)(param_3 + 0x7a4));
    lVar1 = kbusGetPeerId_GM107(param_1,param_2,param_3);
    return lVar1;
  }
  do {
    if ((uVar2 & 1) != 0) {
      if (*(char *)(param_2 + 0xaa34 + lVar1) == '\0') {
        return lVar1;
      }
      if (uVar2 >> 1 == 0) {
        return 0xffffffff;
      }
    }
    uVar2 = uVar2 >> 1;
    lVar1 = lVar1 + 1;
  } while( true );
}


// ===== 002d75b0 kbusIsPeerIdValid_GP100 =====

undefined8 kbusIsPeerIdValid_GP100(long param_1,long param_2,uint param_3)

{
  undefined8 uVar1;
  
  if (7 < param_3) {
    nvAssertFailedNoLog("peerId < P2P_MAX_NUM_PEERS",
                        "src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x30a);
    return 0x2c;
  }
  if ((*(uint *)(param_2 + 0xa8f4 + (ulong)*(uint *)(param_1 + 0x7a4) * 4) &
      1 << ((byte)param_3 & 0x1f)) != 0) {
    return 0;
  }
  uVar1 = kbusIsPeerIdValid_GM107();
  return uVar1;
}


// ===== 002d7610 kbusGetNvlinkP2PPeerId_GP100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kbusGetNvlinkP2PPeerId_GP100(long param_1,long param_2,long param_3,undefined8 param_4,int *param_5)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  
  if (param_5 == (int *)0x0) {
    return 0x1f;
  }
  lVar1 = *(long *)(param_1 + 0x1ce8);
  *param_5 = -1;
  cVar2 = knvlinkIsForcedConfig_IMPL(param_1,lVar1);
  if (cVar2 == '\0') {
    if (*(char *)(lVar1 + 0x339) != '\0') {
      iVar3 = kbusGetPeerIdFromTable_GM107
                        (param_1,param_2,*(undefined4 *)(param_1 + 0x7a4),
                         *(undefined4 *)(param_3 + 0x7a4));
      *param_5 = iVar3;
      if (iVar3 == -1) {
        return 0x3f;
      }
    }
  }
  else {
    iVar3 = kbusGetPeerIdFromTable_GM107
                      (param_1,param_2,*(undefined4 *)(param_1 + 0x7a4),
                       *(undefined4 *)(param_3 + 0x7a4));
    *param_5 = iVar3;
    if (iVar3 == -1) {
      return 0x3f;
    }
    if (lVar1 == 0) {
      return 0;
    }
  }
  uVar4 = knvlinkGetNumLinksToPeer_IMPL(param_1,lVar1,param_3);
  if ((int)uVar4 != 0) {
    iVar3 = (**(code **)(param_2 + 0x288))(param_1,param_2,param_3);
    *param_5 = iVar3;
    if (iVar3 == -1) {
      if ((*(char *)(param_2 + 0xa8f0) == '\0') &&
         (iVar3 = (**(code **)(lVar1 + 0x1d0))(param_1,lVar1), iVar3 != 0)) {
        uVar4 = kbusReserveP2PPeerIds_GM200(param_1,param_2,iVar3);
        if ((int)uVar4 != 0) {
          return uVar4;
        }
        *(undefined1 *)(param_2 + 0xa8f0) = 1;
      }
      iVar3 = (**(code **)(lVar1 + 0x1d8))(param_1,lVar1,param_3);
      *param_5 = iVar3;
    }
    uVar4 = 0;
  }
  return uVar4;
}


// ===== 002d7780 kbusUnreserveP2PPeerIds_GP100 =====

undefined1  [16] kbusUnreserveP2PPeerIds_GP100(long param_1,long param_2,ulong param_3)

{
  undefined1 auVar1 [16];
  long lVar2;
  ulong extraout_RDX;
  undefined8 uVar3;
  ulong uVar4;
  int *piVar5;
  undefined1 auVar6 [16];
  ulong uStack_40;
  
  if ((int)param_3 != 0) {
    uVar4 = param_3 & 0xffffffff;
    lVar2 = 0;
    do {
      if ((uVar4 & 1) != 0) {
        if (*(int *)(param_2 + 0xa9f4 + lVar2 * 4) != 0) {
          nvDbg_Printf("src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",900,
                       "kbusUnreserveP2PPeerIds_GP100",4,
                       "NVRM: GPU%u: Cannot unreserve peerId %u. Nvlink refcount > 0\n",
                       *(undefined4 *)(param_1 + 0x7a4),lVar2);
          uStack_40 = extraout_RDX;
          goto LAB_002d788c;
        }
        if ((uint)uVar4 >> 1 == 0) goto LAB_002d77d8;
      }
      uVar4 = (ulong)((uint)uVar4 >> 1);
      lVar2 = lVar2 + 1;
    } while( true );
  }
  uVar3 = 0;
  uStack_40 = param_3;
LAB_002d7899:
  auVar6._8_8_ = uStack_40;
  auVar6._0_8_ = uVar3;
  return auVar6;
LAB_002d77d8:
  param_3 = param_3 & 0xffffffff;
  uVar4 = 0;
  piVar5 = (int *)(param_2 + 0xaac0);
  do {
    if ((param_3 & 1) != 0) {
      nvDbg_Printf("src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x391,
                   "kbusUnreserveP2PPeerIds_GP100",1,
                   "NVRM: Unreserving peer ID %u on GPU%u reserved for NVLINK \n",uVar4 & 0xffffffff
                   ,*(undefined4 *)(param_1 + 0x7a4));
      if (*piVar5 != 0) break;
      *(undefined1 *)(param_2 + 0xaa34 + uVar4) = 0;
      *(undefined1 *)(piVar5 + 2) = 0;
      if ((uint)param_3 >> 1 == 0) {
        auVar1._8_8_ = 0;
        auVar1._0_8_ = uStack_40;
        return auVar1 << 0x40;
      }
    }
    param_3 = (ulong)((uint)param_3 >> 1);
    uVar4 = uVar4 + 1;
    piVar5 = piVar5 + 8;
  } while( true );
LAB_002d788c:
  uVar3 = 0x17;
  goto LAB_002d7899;
}


// ===== 002d78d0 kbusGetNvlinkPeerNumberMask_GP100 =====

undefined4 kbusGetNvlinkPeerNumberMask_GP100(undefined8 param_1,long param_2,uint param_3)

{
  if (param_3 < 0x20) {
    return *(undefined4 *)(param_2 + 0xa8f4 + (ulong)param_3 * 4);
  }
  nvDbg_Printf("src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x3b5,
               "kbusGetNvlinkPeerNumberMask_GP100",4,"NVRM: Invalid peerId value: %d\n",param_3);
  return 0;
}


// ===== 002d7920 kbusInstBlkWriteAddrLimit_GP100 =====

void kbusInstBlkWriteAddrLimit_GP100
               (undefined8 param_1,long param_2,char param_3,long param_4,long param_5,
               undefined8 param_6)

{
  int iVar1;
  undefined8 uStack_40;
  uint local_10;
  undefined4 local_c;
  
  local_10 = (uint)param_6 | 0xfff;
  local_c = (undefined4)((ulong)param_6 >> 0x20);
  if (param_3 == '\0') {
    *(uint *)(param_5 + 0x208) = local_10;
    *(undefined4 *)(param_5 + 0x20c) = local_c;
  }
  else {
    iVar1 = kbusMemAccessBar0Window_GM107
                      (param_1,param_2,param_4 + 0x208,&local_10,4,0,
                       *(undefined4 *)(param_2 + 0xad3c));
    if (iVar1 != 0) {
      nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x3de)
      ;
      return;
    }
    iVar1 = kbusMemAccessBar0Window_GM107
                      (param_1,param_2,param_4 + 0x20c,&local_c,4,0,
                       *(undefined4 *)(param_2 + 0xad3c));
    if (iVar1 != 0) {
      nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x3e6,
                          uStack_40);
      return;
    }
  }
  return;
}


// ===== 002d7a00 kbusInitInstBlk_GP100 =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusInitInstBlk_GP100
              (long param_1,long param_2,long param_3,undefined8 param_4,undefined8 param_5,
              long param_6)

{
  int iVar1;
  int *piVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  undefined4 extraout_var;
  ulong uVar9;
  undefined8 extraout_RDX;
  undefined4 local_44;
  uint local_40;
  uint local_3c [3];
  
  local_44 = 0;
  local_40 = 0;
  iVar5 = vgpuGetCallingContextGfid(param_1,local_3c);
  if (iVar5 == 0) {
    lVar7 = (ulong)local_3c[0] * 0xd8 + param_2;
    piVar2 = *(int **)(lVar7 + 0x46c0);
    if (piVar2 == (int *)0x0) {
      iVar5 = 0x40;
      nvAssertFailedNoLog("pKernelBus->bar2[gfid].pFmt != NULL",
                          "src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x403);
    }
    else if (param_3 == 0) {
      if (*(char *)(param_2 + 0xad08) == '\0') {
        iVar1 = *piVar2;
        (**(code **)(param_2 + 0x488))(param_1,param_2,1,*(undefined8 *)(lVar7 + 0x4670),0,param_5);
        memdescGetPhysAddr(param_4,1,0);
        uVar9 = (ulong)*(uint *)(param_2 + 0xad3c);
        local_44 = extraout_var;
        iVar5 = kbusMemAccessBar0Window_GM107
                          (param_1,param_2,
                           *(long *)(param_2 + 0x4670 + (ulong)local_3c[0] * 0xd8) + 0x204,&local_44
                           ,4,0);
        if (iVar5 == 0) {
          if (param_6 == 0x20000) {
            uVar6 = kgmmuGetHwPteApertureFromMemdesc_GM107
                              (*(undefined8 *)(param_1 + 0x1b98),param_4,extraout_RDX,uVar9);
            iVar5 = memdescGetVolatility(param_4);
            uVar9 = memdescGetPhysAddr(param_4,1,0);
            local_40 = (int)(uVar9 >> 0xc) << 0xc |
                       iVar5 * 4 & 4U | (uint)(iVar1 == 2) << 10 | uVar6 & 3;
          }
          else if (param_6 == 0x10000) {
            uVar3 = kgmmuGetHwPteApertureFromMemdesc_GM107
                              (*(undefined8 *)(param_1 + 0x1b98),param_4,extraout_RDX,uVar9);
            sVar4 = memdescGetVolatility(param_4);
            uVar9 = memdescGetPhysAddr(param_4,1,0);
            iVar5 = (int)(uVar9 >> 0xc) << 0xc;
            local_40 = CONCAT22((short)((uint)iVar5 >> 0x10),
                                (ushort)iVar5 | (ushort)(iVar1 == 2) << 10 | uVar3 & 3 |
                                sVar4 * 4 & 4U) | 0x800;
          }
          iVar5 = kbusMemAccessBar0Window_GM107
                            (param_1,param_2,
                             *(long *)(param_2 + 0x4670 + (ulong)local_3c[0] * 0xd8) + 0x200,
                             &local_40,4,0,*(undefined4 *)(param_2 + 0xad3c));
          if (iVar5 != 0) {
            nvAssertOkFailedNoLog
                      (iVar5,
                       "kbusMemAccessBar0Window_HAL(pGpu, pKernelBus, (pKernelBus->bar2[gfid].instBlockBase + SF_OFFSET(NV_RAMIN_PAGE_DIR_BASE_TARGET)), &pageDirBaseTarget, sizeof(NvU32), NV_FALSE, pKernelBus->InstBlkAperture)"
                       ,"src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x432);
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar5,
                     "kbusMemAccessBar0Window_HAL(pGpu, pKernelBus, (pKernelBus->bar2[gfid].instBlockBase + SF_OFFSET(NV_RAMIN_PAGE_DIR_BASE_HI)), &pageDirBaseHi, sizeof(NvU32), NV_FALSE, pKernelBus->InstBlkAperture)"
                     ,"src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x414);
        }
      }
      else {
        iVar5 = (**(code **)(param_2 + 0x4b0))(param_1,param_2,param_4,param_5,param_6);
      }
    }
    else {
      lVar7 = *(long *)(&DAT_00001b90 + param_1);
      lVar8 = memdescMapInternal(param_1,param_3,0);
      if (lVar8 == 0) {
        iVar5 = 0x1a;
      }
      else {
        (**(code **)(lVar7 + 0x498))(param_1,lVar7,lVar8,param_4,param_5,param_6);
        memdescUnmapInternal(param_1,param_3,0);
        if (*(char *)(lVar7 + 0x46a9 + (ulong)local_3c[0] * 0xd8) != '\0') {
          kbusReleaseRmAperture_VBAR2(param_1,lVar7,param_3);
        }
      }
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar5,"vgpuGetCallingContextGfid(pGpu, &gfid)",
               "src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x401);
  }
  return iVar5;
}


// ===== 002d7da0 kbusBar2InstBlkWrite_GP100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbusBar2InstBlkWrite_GP100
               (long param_1,long param_2,long param_3,undefined8 param_4,undefined8 param_5,
               long param_6)

{
  int iVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  undefined4 extraout_var;
  ulong uVar6;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("NULL != pMap","src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x460);
    return;
  }
  if (*(int **)(param_2 + 0x46c0) == (int *)0x0) {
    nvAssertFailedNoLog("NULL != pKernelBus->bar2[GPU_GFID_PF].pFmt",
                        "src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x461);
    return;
  }
  iVar1 = **(int **)(param_2 + 0x46c0);
  (**(code **)(param_2 + 0x488))(param_1,param_2,0,0,param_3,param_5);
  memdescGetPhysAddr(param_4,1,0);
  *(undefined4 *)(param_3 + 0x204) = extraout_var;
  if (param_6 == 0x20000) {
    uVar4 = kgmmuGetHwPteApertureFromMemdesc_GM107(*(undefined8 *)(param_1 + 0x1b98),param_4);
    iVar5 = memdescGetVolatility(param_4);
    uVar6 = memdescGetPhysAddr(param_4,1,0);
    *(uint *)(param_3 + 0x200) =
         (int)(uVar6 >> 0xc) << 0xc | iVar5 * 4 & 4U | (uint)(iVar1 == 2) << 10 | uVar4 & 3;
    return;
  }
  if (param_6 != 0x10000) {
    return;
  }
  uVar2 = kgmmuGetHwPteApertureFromMemdesc_GM107(*(undefined8 *)(param_1 + 0x1b98),param_4);
  sVar3 = memdescGetVolatility(param_4);
  uVar6 = memdescGetPhysAddr(param_4,1,0);
  iVar5 = (int)(uVar6 >> 0xc) << 0xc;
  *(uint *)(param_3 + 0x200) =
       CONCAT22((short)((uint)iVar5 >> 0x10),
                (ushort)(iVar1 == 2) << 10 | (ushort)iVar5 | uVar2 & 3 | sVar3 * 4 & 4U) | 0x800;
  return;
}


// ===== 002d7f50 kbusCalcCpuInvisibleBar2Range_GP100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbusCalcCpuInvisibleBar2Range_GP100(undefined8 param_1,long param_2,uint param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = (ulong)param_3 * 0xd8 + param_2;
  if (*(long *)(lVar2 + 0x4638) == 0) {
    iVar1 = (**(code **)(param_2 + 0x1e8))();
    if (iVar1 == 0) {
      return;
    }
    lVar3 = *(long *)(lVar2 + 0x4630);
    if ((lVar3 == 0) && (lVar3 = *(long *)(lVar2 + 0x4628), lVar3 != 0)) {
      lVar3 = lVar3 + 1;
      *(long *)(lVar2 + 0x4630) = lVar3;
    }
    nvDbg_Printf("src/kernel/gpu/bus/arch/pascal/kern_bus_gp100.c",0x4ab,
                 "kbusCalcCpuInvisibleBar2Range_GP100",1,"NVRM: base: 0x%llx size: 0x%x\n",lVar3,
                 iVar1);
    lVar2 = (ulong)param_3 * 0xd8;
    *(ulong *)(param_2 + 0x4638 + lVar2) = (ulong)(iVar1 - 1) + *(long *)(param_2 + 0x4630 + lVar2);
  }
  return;
}


// ===== 002d8030 _kbusUpdateStaticBar1VAMapping_TU102.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _kbusUpdateStaticBar1VAMapping_TU102_isra_0(long param_1,long param_2,long param_3,byte param_4)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  char cVar6;
  int iVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  ulong uVar11;
  undefined1 local_98 [4];
  uint local_94;
  long local_90;
  undefined8 local_84;
  undefined8 local_7c;
  undefined8 local_74;
  undefined4 local_6c;
  long *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar1 = *(undefined8 *)(param_1 + 0x1b78);
  lVar2 = *(long *)(param_1 + 0x1bb8);
  local_68 = (long *)0x0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_84 = 0;
  local_7c = 0;
  local_74 = 0;
  local_6c = 0;
  iVar7 = vgpuGetCallingContextGfid(param_1,&local_94);
  if (iVar7 != 0) {
    nvAssertFailedNoLog("vgpuGetCallingContextGfid(pGpu, &gfid) == NV_OK",
                        "src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x2e0);
    return 0x40;
  }
  if (param_3 == 0) {
    nvAssertFailedNoLog("pMemDesc != NULL","src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x2e3);
  }
  else {
    iVar7 = memdescGetAddressSpace(param_3);
    if (iVar7 == 2) {
      cVar6 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_1 + 0x7a4));
      if (cVar6 == '\0') {
        nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(gpuGetInstance(pGpu))",
                            "src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x2e8);
        return 0x2f;
      }
      lVar3 = *(long *)(param_2 + 0x630 + (ulong)local_94 * 0x100);
      uVar4 = *(undefined8 *)(lVar3 + 0x50);
      uVar8 = memdescGetPageSize(param_3,uVar4);
      uVar5 = *(ulong *)(param_3 + 0x30);
      uVar9 = memdescGetPhysAddr(param_3,uVar4,0);
      if ((uVar9 & uVar8 - 1) == 0) {
        if ((uVar8 - 1 & uVar5) == 0) {
          cVar6 = memdescGetContiguity(param_3,uVar4);
          uVar9 = uVar8;
          if (cVar6 != '\0') {
            uVar9 = uVar5;
          }
          iVar7 = memmgrGetKindComprFromMemDesc_IMPL(uVar1,param_3,0,local_98,&local_84);
          if (iVar7 != 0) {
            nvAssertOkFailedNoLog
                      (iVar7,
                       "memmgrGetKindComprFromMemDesc(pMemoryManager, pMemDesc, 0, &kind, &comprInfo)"
                       ,"src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x2fb);
            return iVar7;
          }
          if (((param_4 & 1) == 0) && (uVar8 < 0x200000)) {
            return 0x56;
          }
          if (param_4 == 0) {
            cVar6 = memdescGetFlag(param_3,0x4000000000000);
            if (cVar6 != '\0') {
              local_50 = *(undefined8 *)(param_3 + 0x158);
              local_58._0_3_ = CONCAT12(1,(undefined2)local_58);
            }
          }
          else {
            local_84 = CONCAT44(local_84._4_4_,*(undefined4 *)(param_2 + 0xad50));
          }
          if (uVar5 == 0) {
            return 0;
          }
          uVar11 = 0;
          do {
            local_90 = memdescGetPhysAddr(param_3,uVar4,uVar11);
            local_60 = CONCAT44(1,(undefined4)local_60);
            lVar10 = local_90 + *(long *)(param_2 + 0x700 + (ulong)local_94 * 0x100);
            local_68 = &local_90;
            iVar7 = (**(code **)(lVar2 + 400))
                              (param_1,lVar2,lVar3,param_3,0,lVar10,(uVar9 - 1) + lVar10,0x8007ff,
                               &local_68,&local_84,0,1,1,0,0xffffffffffffffff,0xffffffffffffffff,0,0
                               ,uVar8);
            uVar11 = uVar11 + uVar9;
          } while (uVar11 < uVar5);
          if (iVar7 == 0) {
            return 0;
          }
          nvDbg_Printf("src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x339,
                       "_kbusUpdateStaticBar1VAMapping_TU102",4,
                       "NVRM: Failed to update static bar1 VA space, error 0x%x.\n");
          if (iVar7 != 0x56) {
            return iVar7;
          }
          return 0x40;
        }
        nvAssertFailedNoLog("NV_IS_ALIGNED64(mapSize, pageSize)",
                            "src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x2f4);
      }
      else {
        nvAssertFailedNoLog("NV_IS_ALIGNED64( memdescGetPhysAddr(pMemDesc, addressTranslation, 0), pageSize)"
                            ,"src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x2f0);
      }
    }
    else {
      nvAssertFailedNoLog("memdescGetAddressSpace(pMemDesc) == ADDR_FBMEM",
                          "src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x2e5);
    }
  }
  return 0x1f;
}


// ===== 002d84d0 kbusGetUnusedPciePeerId_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kbusGetUnusedPciePeerId_TU102(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  
  lVar1 = *(long *)(param_1 + 0x1ce8);
  if ((lVar1 == 0) || (*(char *)(lVar1 + 0x2ea) == '\0')) {
    uVar3 = 0;
  }
  else {
    uVar3 = (**(code **)(lVar1 + 0x1d0))();
  }
  uVar2 = 0;
  piVar4 = (int *)(param_2 + 0xaac0);
  if (*(uint *)(param_2 + 0xacf0) != 0) {
    do {
      if (((*piVar4 == 0) && ((char)piVar4[2] == '\0')) && ((uVar3 >> (uVar2 & 0x1f) & 1) == 0)) {
        return uVar2;
      }
      uVar2 = uVar2 + 1;
      piVar4 = piVar4 + 8;
    } while (uVar2 != *(uint *)(param_2 + 0xacf0));
  }
  return 0xffffffff;
}


// ===== 002d8550 kbusBindBar2_TU102 =====

int kbusBindBar2_TU102(long param_1,long param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  uint local_44;
  undefined1 local_40 [24];
  
  iVar1 = vgpuGetCallingContextGfid(param_1,&local_44);
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog
              (iVar1,"vgpuGetCallingContextGfid(pGpu, &gfid)",
               "src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x70);
    return iVar1;
  }
  uVar4 = (ulong)local_44;
  lVar3 = uVar4 * 0xd8 + param_2;
  if (((*(char *)(lVar3 + 0x46a8) == '\0') || (lVar3 = *(long *)(lVar3 + 0x4680), lVar3 == 0)) ||
     (*(char *)(param_2 + 0xad08) == '\0')) {
    uVar4 = uVar4 * 0xd8;
    lVar3 = *(long *)(param_2 + 0x4678 + uVar4);
  }
  uVar2 = 0x40000000;
  if (param_3 != 0) {
    uVar2 = kgmmuGetHwPteApertureFromMemdesc_GM107
                      (*(undefined8 *)(param_1 + 0x1b98),lVar3,uVar4,lVar3,0x40000000);
    uVar4 = memdescGetPhysAddr(lVar3,1,0);
    uVar2 = (uVar2 & 3) << 0x1c | (uint)(uVar4 >> 0xc) & 0xfffffff | 0xc0000000;
  }
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0xf48,uVar2,0);
  osFlushCpuWriteCombineBuffer();
  iVar1 = 0;
  if ((*(char *)(param_1 + 0x908) != '\0') ||
     (((*(char *)(param_1 + 0x44f) == '\0' && (*(char *)(param_1 + 0x450) == '\0')) &&
      ((*(char *)(param_1 + 0x451) == '\0' && (*(char *)(param_1 + 0x461) == '\0')))))) {
    timeoutSet(param_1 + 0x1af0,local_40,0,0);
    while( true ) {
      uVar4 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0xf50,0);
      if ((uVar4 & 0xc) == 0) {
        return 0;
      }
      if (iVar1 == 0x65) break;
      iVar1 = timeoutCheck(param_1 + 0x1af0,local_40,0xc2);
      osSpinLoop();
    }
    nvDbg_Printf("src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0xbc,"kbusBindBar2_TU102",4,
                 "NVRM: timed out waiting for bar2 binding to complete\n");
    iVar1 = 0x65;
  }
  return iVar1;
}


// ===== 002d8770 kbusBar1InstBlkBind_TU102 =====

int kbusBar1InstBlkBind_TU102(long param_1,long param_2)

{
  undefined8 uVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  uint local_44;
  undefined1 local_40 [24];
  
  uVar1 = *(undefined8 *)(param_1 + 0x1b98);
  iVar2 = vgpuGetCallingContextGfid(param_1,&local_44);
  if (iVar2 != 0) {
    nvAssertOkFailedNoLog
              (iVar2,"vgpuGetCallingContextGfid(pGpu, &gfid)",
               "src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0xf8);
    return iVar2;
  }
  if ((*(char *)(param_1 + 0x908) == '\0') ||
     ((*(char *)(param_1 + 0x4913) != '\0' && (*(char *)(param_1 + 0x491e) == '\0')))) {
    iVar2 = kgmmuGetMemAperture_IMPL
                      (uVar1,*(undefined8 *)(param_2 + 0x648 + (ulong)local_44 * 0x100));
    if (iVar2 != 3) {
      if (iVar2 == 4) {
        iVar2 = 2;
      }
      else {
        if (iVar2 != 1) {
          nvAssertFailedNoLog(&DAT_00cfd286,"src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x10d)
          ;
          return 0x40;
        }
        iVar2 = 0;
      }
    }
    if (((*(char *)(param_1 + 0x44d) != '\0') || (uVar3 = 0, *(char *)(param_2 + 0xad04) == '\0'))
       && (uVar3 = iVar2 << 0x1c, *(char *)(param_2 + 0xad04) == '\0')) {
      uVar3 = uVar3 | (uint)(*(ulong *)(param_2 + 0x640 + (ulong)local_44 * 0x100) >> 0xc) &
                      0xfffffff | 0x80000000;
    }
    regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0xf40,uVar3,0);
    osFlushCpuWriteCombineBuffer();
    if ((*(char *)(param_1 + 0x908) != '\0') ||
       (((*(char *)(param_1 + 0x44f) == '\0' && (*(char *)(param_1 + 0x450) == '\0')) &&
        ((*(char *)(param_1 + 0x451) == '\0' && (*(char *)(param_1 + 0x461) == '\0')))))) {
      timeoutSet(param_1 + 0x1af0,local_40,0,0);
      iVar2 = 0;
      while (uVar4 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0xf50,0),
            (uVar4 & 3) != 0) {
        if (iVar2 == 0x65) {
          nvDbg_Printf("src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x141,
                       "kbusBar1InstBlkBind_TU102",4,
                       "NVRM: timed out waiting for bar1 binding to complete\n");
          return 0x65;
        }
        iVar2 = timeoutCheck(param_1 + 0x1af0,local_40,0x146);
        osSpinLoop();
      }
    }
  }
  return 0;
}


// ===== 002d89d0 kbusGetBar1ResvdVA_TU102 =====

undefined8 kbusGetBar1ResvdVA_TU102(void)

{
  return 0x8000000;
}


// ===== 002d89e0 kbusIsStaticBar1Supported_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

char kbusIsStaticBar1Supported_TU102
               (long param_1,long param_2,int param_3,long param_4,long param_5)

{
  char cVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  uint local_3c [3];
  
  lVar3 = kbusGetPciBarSize_IMPL(param_2,1);
  lVar5 = *(long *)(param_1 + 0x1b78);
  lVar4 = gpuGetKernelFifoShared_IMPL(param_1);
  if (((param_3 == 0) && (lVar8 = *(long *)(lVar5 + 0x838) * 0x100000, lVar8 != 0)) && (lVar3 != 0))
  {
    uVar7 = *(ulong *)(param_2 + 0x628);
    cVar1 = hypervisorIsVgxHyper_IMPL();
    if ((cVar1 == '\0') && (cVar1 = gpuIsCCFeatureEnabled_IMPL(param_1), cVar1 == '\0')) {
      iVar2 = *(int *)(param_2 + 0xad4c);
      uVar7 = uVar7 & 0xffffffffffe00000;
      if (iVar2 == 1) {
        uVar6 = memmgrGetClientFbAddrSpaceSize_IMPL(param_1,lVar5);
        lVar3 = memmgrGetClientFbAddrSpaceSize_IMPL(param_1,lVar5);
        lVar5 = memmgrGetClientFbAddrSpaceSize_IMPL(param_1,lVar5);
        uVar6 = (lVar3 + -0x200000) - lVar5 & uVar6;
        if (uVar6 <= uVar7) {
          return '\0';
        }
        nvDbg_Printf("src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x1b3,
                     "kbusIsStaticBar1Supported_TU102",4,
                     "NVRM: BAR1 size %lld is not large enough to map FB size%lld to force static BAR1\n"
                     ,uVar7,uVar6);
        return '>';
      }
      if (iVar2 == 2) {
        local_3c[0] = 0;
        iVar2 = kfifoGetMaxChannelsInSystem_IMPL(param_1,lVar4);
        (**(code **)(lVar4 + 0x2a0))(lVar4,local_3c,0);
        local_3c[0] = iVar2 * local_3c[0];
        uVar6 = (lVar8 + 0x1fffffU & 0xffffffffffe00000) + param_4 + 0x20000 + param_5 +
                (ulong)local_3c[0];
        if (param_4 != 0 || param_5 != 0) {
          uVar6 = (uVar6 - ((int)param_4 + (int)param_5 & 0x1fffffff)) + 0x20000000;
        }
        if (uVar7 < uVar6) {
          return 'V';
        }
        nvDbg_Printf("src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x1f5,
                     "kbusIsStaticBar1Supported_TU102",1,
                     "NVRM: Enabling static BAR1 automatically!\n");
        return '\0';
      }
      return (-(iVar2 == 0) & 0x18U) + 0x3e;
    }
  }
  return 'V';
}


// ===== 002d8be0 kbusEnableStaticBar1Mapping_TU102 =====

int kbusEnableStaticBar1Mapping_TU102(long param_1,long param_2,uint param_3,long param_4)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  long local_60 [2];
  undefined8 *local_50;
  undefined8 local_48;
  ulong local_40 [2];
  
  uVar6 = *(undefined8 *)(param_1 + 0x1b78);
  local_50 = (undefined8 *)0x0;
  local_48 = 0;
  local_60[0] = param_4;
  uVar3 = memmgrGetClientFbAddrSpaceSize_IMPL(param_1,uVar6);
  lVar4 = memmgrGetClientFbAddrSpaceSize_IMPL(param_1,uVar6);
  lVar5 = memmgrGetClientFbAddrSpaceSize_IMPL(param_1,uVar6);
  local_40[0] = (lVar4 + -0x200000) - lVar5 & uVar3;
  iVar1 = memdescCreate(&local_50,param_1,local_40[0],0,1,2,1,0);
  if (iVar1 == 0) {
    memdescDescribe(local_50,2,0,local_40[0]);
    memdescSetPageSize(local_50,1,0x200000);
    *(undefined4 *)(param_2 + 0xad50) = 6;
    memdescSetPteKindForGpu(local_50,*local_50,6);
    iVar1 = kbusMapFbApertureSingle_IMPL(param_1,param_2,local_50,0,local_60,local_40,0x1060,0);
    if (iVar1 == 0) {
      lVar5 = gpumgrGetGpuPhysFbAddr(param_1);
      lVar4 = local_60[0];
      uVar6 = 0;
      iVar1 = memdescCreate(&local_48,param_1,local_40[0],0,1,1,1);
      if (iVar1 == 0) {
        memdescDescribe(local_48,1,lVar5 + lVar4,local_40[0]);
        lVar4 = (ulong)param_3 * 0x100;
        *(undefined8 **)(param_2 + 0x6f0 + lVar4) = local_50;
        *(undefined1 *)(param_2 + 0x6e8 + lVar4) = 1;
        *(undefined8 *)(param_2 + 0x6f8 + lVar4) = local_48;
        *(long *)(param_2 + 0x700 + lVar4) = local_60[0];
        *(ulong *)(param_2 + 0x708 + lVar4) = local_40[0];
        nvDbg_Printf("src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x263,
                     "kbusEnableStaticBar1Mapping_TU102",1,
                     "NVRM: Static bar1 mapped offset 0x%llx size 0x%llx\n",local_60[0],local_40[0])
        ;
        return 0;
      }
      nvAssertOkFailedNoLog
                (iVar1,
                 "memdescCreate(&pDmaMemDesc, pGpu, bar1MapSize, 0, NV_MEMORY_CONTIGUOUS, ADDR_SYSMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_NONE)"
                 ,"src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x250,uVar6);
      iVar2 = kbusUnmapFbApertureSingle_IMPL(param_1,param_2,local_50,local_60[0],local_40[0],0x60);
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,
                   "kbusUnmapFbApertureSingle(pGpu, pKernelBus, pMemDesc, bar1Offset, bar1MapSize, BUS_MAP_FB_FLAGS_MAP_UNICAST | BUS_MAP_FB_FLAGS_MAP_OFFSET_FIXED)"
                   ,"src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x269);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar1,
                 "kbusMapFbApertureSingle(pGpu, pKernelBus, pMemDesc, 0, &bar1Offset, &bar1MapSize, mapFlags, NV01_NULL_OBJECT)"
                 ,"src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x242);
    }
    nvDbg_Printf("src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x26e,
                 "kbusEnableStaticBar1Mapping_TU102",4,
                 "NVRM: Failed to create the static bar1 mapping offset0x%llx size 0x%llx\n",
                 local_60[0],local_40[0]);
    lVar4 = (ulong)param_3 * 0x100;
    *(undefined1 *)(param_2 + 0x6e8 + lVar4) = 0;
    *(undefined8 *)(param_2 + 0x6f0 + lVar4) = 0;
    *(undefined8 *)(param_2 + 0x6f8 + lVar4) = 0;
    memdescDestroy(local_48);
    memdescDestroy(local_50);
  }
  else {
    nvAssertOkFailedNoLog
              (iVar1,
               "memdescCreate(&pMemDesc, pGpu, bar1MapSize, 0, NV_MEMORY_CONTIGUOUS, ADDR_FBMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_NONE)"
               ,"src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x22e);
  }
  return iVar1;
}


// ===== 002d8ed0 kbusDisableStaticBar1Mapping_TU102 =====

void kbusDisableStaticBar1Mapping_TU102(undefined8 param_1,long param_2,uint param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = (ulong)param_3 * 0x100 + param_2;
  if (*(char *)(lVar2 + 0x6e8) == '\0') {
    return;
  }
  *(undefined1 *)(lVar2 + 0x6e8) = 0;
  iVar1 = kbusUnmapFbApertureSingle_IMPL
                    (param_1,param_2,*(undefined8 *)(lVar2 + 0x6f0),*(undefined8 *)(lVar2 + 0x700),
                     *(undefined8 *)(lVar2 + 0x708),0x20);
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog
              (iVar1,
               "kbusUnmapFbApertureSingle(pGpu, pKernelBus, pKernelBus->bar1[gfid].staticBar1.pVidMemDesc, pKernelBus->bar1[gfid].staticBar1.startOffset, pKernelBus->bar1[gfid].staticBar1.size, BUS_MAP_FB_FLAGS_MAP_UNICAST)"
               ,"src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x291);
  }
  param_2 = param_2 + (ulong)param_3 * 0x100;
  memdescDestroy(*(undefined8 *)(param_2 + 0x6f0));
  *(undefined8 *)(param_2 + 0x6f0) = 0;
  memdescDestroy(*(undefined8 *)(param_2 + 0x6f8));
  *(undefined8 *)(param_2 + 0x6f8) = 0;
  return;
}


// ===== 002d8f90 kbusIncreaseStaticBar1Refcount_TU102 =====

undefined8
kbusIncreaseStaticBar1Refcount_TU102
          (undefined8 param_1,long param_2,undefined8 *param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  undefined1 local_40 [16];
  
  cVar1 = kbusIsStaticBar1Enabled_IMPL();
  if (cVar1 == '\0') {
    return 0x56;
  }
  iVar2 = memdescGetPteKindForGpu(param_3,*param_3);
  lVar4 = memdescGetRootMemDesc(param_3,local_40);
  iVar3 = kbusConvertBusMapFlagsToDmaFlags_IMPL(param_2,param_3,param_4);
  if (((*(int *)(lVar4 + 0x134) == 0) || (*(int *)(lVar4 + 0x138) == iVar2)) &&
     (*(int *)(lVar4 + 0x13c) == iVar3)) {
    if (((*(int *)(param_2 + 0xad50) == iVar2) &&
        (cVar1 = memdescGetFlag(param_3,0x4000000000000), cVar1 == '\0')) ||
       (uVar5 = _kbusUpdateStaticBar1VAMapping_TU102_isra_0(param_1,param_2,lVar4,0),
       (int)uVar5 == 0)) {
      *(int *)(lVar4 + 0x134) = *(int *)(lVar4 + 0x134) + 1;
      uVar5 = 0;
      *(int *)(lVar4 + 0x138) = iVar2;
      *(int *)(lVar4 + 0x13c) = iVar3;
    }
    return uVar5;
  }
  return 0x17;
}


// ===== 002d90c0 kbusDecreaseStaticBar1Refcount_TU102 =====

int kbusDecreaseStaticBar1Refcount_TU102
              (undefined8 param_1,long param_2,undefined8 param_3,long *param_4)

{
  ulong uVar1;
  ulong uVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  uint local_3c [3];
  
  cVar3 = kbusIsStaticBar1Enabled_IMPL();
  if (cVar3 == '\0') {
    return 0x56;
  }
  iVar4 = vgpuGetCallingContextGfid(param_1,local_3c);
  if (iVar4 != 0) {
    nvAssertFailedNoLog("vgpuGetCallingContextGfid(pGpu, &gfid) == NV_OK",
                        "src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x3b4);
    return 0x40;
  }
  memdescFlushCpuCaches(param_1,param_3);
  lVar5 = memdescGetRootMemDesc(param_3,0);
  if (param_4 == (long *)0x0) {
    if (*(int *)(lVar5 + 0x134) != 0) {
      iVar4 = *(int *)(lVar5 + 0x134) + -1;
      *(int *)(lVar5 + 0x134) = iVar4;
      goto joined_r0x002d91e8;
    }
  }
  else {
    uVar1 = *(ulong *)*param_4;
    lVar6 = (ulong)local_3c[0] * 0x100 + param_2;
    uVar2 = *(ulong *)(lVar6 + 0x700);
    if ((uVar2 <= uVar1) && (uVar1 + ((ulong *)*param_4)[1] <= uVar2 + *(long *)(lVar6 + 0x708))) {
      if (*(int *)(lVar5 + 0x134) == 0) {
        nvAssertFailedNoLog("pRootMemDesc->staticBar1MappingRefCount != 0",
                            "src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x3d7);
        return 0x40;
      }
      iVar4 = *(int *)(lVar5 + 0x134) + -1;
      *(int *)(lVar5 + 0x134) = iVar4;
joined_r0x002d91e8:
      if (iVar4 != 0) {
        return 0;
      }
      if ((*(int *)(lVar5 + 0x138) == *(int *)(param_2 + 0xad50)) &&
         (cVar3 = memdescGetFlag(param_3,0x4000000000000), cVar3 == '\0')) {
        return 0;
      }
      iVar4 = _kbusUpdateStaticBar1VAMapping_TU102_isra_0(param_1,param_2,lVar5,1);
      if (iVar4 != 0) {
        nvAssertOkFailedNoLog
                  (iVar4,
                   "_kbusUpdateStaticBar1VAMapping_TU102(pGpu, pKernelBus, pRootMemDesc, BUS_MAP_FB_FLAGS_NONE, NV_TRUE)"
                   ,"src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x3e9);
        return iVar4;
      }
      return 0;
    }
  }
  return 0x56;
}


// ===== 002d9280 kbusGetStaticFbAperture_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusGetStaticFbAperture_TU102
              (undefined8 param_1,long param_2,long param_3,long param_4,long param_5,long *param_6,
              uint param_7)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  bool bVar5;
  char cVar6;
  int iVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  long *plVar13;
  long lVar14;
  long lVar15;
  uint local_74;
  int local_70 [2];
  ulong local_68;
  ulong local_60;
  ulong local_58;
  long local_50;
  long local_48;
  long local_40;
  
  cVar6 = kbusIsStaticBar1Enabled_IMPL();
  if (cVar6 == '\0') {
    return 0x56;
  }
  iVar7 = memdescGetAddressSpace(param_3);
  if (iVar7 != 2) {
    return 0x56;
  }
  iVar7 = vgpuGetCallingContextGfid(param_1,&local_74);
  if (iVar7 != 0) {
    nvAssertFailedNoLog("vgpuGetCallingContextGfid(pGpu, &gfid) == NV_OK",
                        "src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x41e);
    return 0x40;
  }
  if (local_74 != 0) {
    nvAssertFailedNoLog("gfid == 0","src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x421);
    return 0x40;
  }
  if (param_3 == 0) {
    nvAssertFailedNoLog("pMemDesc != NULL","src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x423);
    return 0x1f;
  }
  lVar9 = *(long *)(param_2 + 0x630);
  memdescIteratorInit(local_70,param_3,*(undefined8 *)(lVar9 + 0x50),param_4,param_5);
  param_6[1] = 0;
  if (local_70[0] == 1) {
    bVar4 = 0;
    bVar1 = true;
    bVar2 = false;
    uVar10 = local_68;
    uVar12 = local_58;
    goto LAB_002d9488;
  }
  bVar4 = 0;
  bVar1 = true;
  bVar2 = false;
  uVar11 = local_68;
  uVar8 = local_58;
  bVar3 = false;
  bVar5 = true;
  if (local_70[0] == 2) {
    while (bVar1 = bVar5, bVar3 = bVar2, uVar8 < local_60) {
      uVar12 = uVar8 + 1;
      plVar13 = (long *)(uVar11 + uVar8 * 0x10);
      lVar14 = *plVar13;
      lVar15 = plVar13[1];
      if (uVar8 == 0) {
        lVar14 = lVar14 + local_50;
        lVar15 = lVar15 - local_50;
        if (local_60 != 1) {
LAB_002d940c:
          plVar13 = (long *)(uVar11 + 0x10 + uVar8 * 0x10);
          do {
            if (*plVar13 != lVar15 + lVar14) break;
            uVar12 = uVar12 + 1;
            lVar15 = lVar15 + plVar13[1];
            plVar13 = plVar13 + 2;
          } while (uVar12 < local_60);
          goto LAB_002d943a;
        }
        uVar12 = 1;
LAB_002d9580:
        lVar15 = lVar15 - local_48;
      }
      else {
        if (uVar12 < local_60) goto LAB_002d940c;
LAB_002d943a:
        if (local_60 == uVar12) goto LAB_002d9580;
      }
LAB_002d9443:
      uVar8 = lVar15 + lVar14;
      uVar10 = *(ulong *)(param_2 + 0x708 + (ulong)local_74 * 0x100);
      param_6[1] = param_6[1] + 1;
      if (uVar8 <= uVar10) {
        bVar4 = 1;
        goto LAB_002d947e;
      }
LAB_002d9463:
      bVar2 = true;
      if (bVar1) {
        bVar1 = uVar8 - uVar10 < 0x200000;
        bVar2 = true;
      }
LAB_002d947e:
      uVar10 = uVar11;
      uVar8 = uVar12;
      bVar5 = bVar1;
      if (local_70[0] == 1) {
LAB_002d9488:
        do {
          bVar3 = bVar2;
          if (uVar12 <= uVar10) goto LAB_002d9392;
          lVar14 = *(long *)(local_60 + uVar10 * 8);
          uVar11 = uVar10 + 1;
          if (uVar10 == 0) {
            lVar14 = lVar14 + local_48;
            lVar15 = local_50 - local_48;
            if (uVar12 != 1) {
LAB_002d94c4:
              plVar13 = (long *)(local_60 + 8 + uVar10 * 8);
              do {
                if (*plVar13 != lVar15 + lVar14) break;
                uVar11 = uVar11 + 1;
                lVar15 = lVar15 + local_50;
                plVar13 = plVar13 + 1;
              } while (uVar11 < uVar12);
              goto LAB_002d94f9;
            }
            uVar11 = 1;
          }
          else {
            lVar15 = local_50;
            if (uVar11 < uVar12) goto LAB_002d94c4;
LAB_002d94f9:
            if (uVar11 != uVar12) goto LAB_002d9443;
          }
          uVar8 = (lVar15 - local_40) + lVar14;
          uVar10 = *(ulong *)(param_2 + 0x708 + (ulong)local_74 * 0x100);
          param_6[1] = param_6[1] + 1;
          if (uVar10 < uVar8) goto LAB_002d9463;
          bVar4 = 1;
          uVar10 = uVar11;
        } while( true );
      }
    }
  }
LAB_002d9392:
  if (param_6[1] == 1) {
    if ((bool)(bVar4 & bVar3)) {
LAB_002d93aa:
      if (bVar1) {
        return 0x56;
      }
      nvDbg_Printf("src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x44e,
                   "kbusGetStaticFbAperture_TU102",4,
                   "NVRM: MemDesc spans both static and dynamic region,which is unsupported.\n");
      nvDbg_Printf("src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x450,
                   "kbusGetStaticFbAperture_TU102",4,"NVRM: static Bar1 map [0, 0x%llx]\n",
                   *(undefined8 *)(param_2 + 0x708 + (ulong)local_74 * 0x100));
      nvDbg_Printf("src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x452,
                   "kbusGetStaticFbAperture_TU102",4,
                   "NVRM: Requested map range 0x%llx to 0x%llx, mapGranularity 0x%llx\n",param_4,
                   param_5 + -1 + param_4,param_5);
      memdescPrintMemdesc(param_3,1,"Dumping memdesc:");
      return 0x1f;
    }
    if (bVar3) {
      return 0x56;
    }
    if ((param_7 & 0x200) != 0) goto LAB_002d95a3;
  }
  else {
    if (((param_7 & 0x100) == 0) || ((param_7 & 0x200) != 0)) {
      nvCheckFailedNoLog(1,"(pMemArea->numRanges == 1) || (bDiscontigAllowed && !bUnmanagedRange)",
                         "src/kernel/gpu/bus/arch/turing/kern_bus_tu102.c",0x43f);
      return 0x1f;
    }
    if ((bool)(bVar4 & bVar3)) goto LAB_002d93aa;
    if (bVar3) {
      return 0x56;
    }
  }
  lVar15 = portMemAllocNonPaged(param_6[1] << 4);
  *param_6 = lVar15;
  if (lVar15 == 0) {
    return 0x51;
  }
LAB_002d95a3:
  iVar7 = (**(code **)(param_2 + 0x328))(param_1,param_2,param_3,param_7);
  if ((iVar7 == 0x17) || (iVar7 == 0x56)) {
    portMemFree(*param_6);
    return 0x56;
  }
  if (iVar7 != 0) {
    portMemFree(*param_6);
    return iVar7;
  }
  memdescIteratorInit(local_70,param_3,*(undefined8 *)(lVar9 + 0x50),param_4,param_5);
  param_6[1] = 0;
  uVar12 = local_68;
  if (local_70[0] == 1) goto LAB_002d9701;
  uVar10 = local_58;
  if (local_70[0] != 2) {
    return 0;
  }
  do {
    if (local_60 <= uVar10) {
      return 0;
    }
    local_58 = uVar10 + 1;
    plVar13 = (long *)(local_68 + uVar10 * 0x10);
    lVar15 = *plVar13;
    lVar9 = plVar13[1];
    if (uVar10 == 0) {
      lVar15 = lVar15 + local_50;
      lVar9 = lVar9 - local_50;
      if (local_60 != 1) {
LAB_002d9684:
        plVar13 = (long *)(local_68 + 0x10 + uVar10 * 0x10);
        do {
          if (*plVar13 != lVar9 + lVar15) break;
          local_58 = local_58 + 1;
          lVar9 = lVar9 + plVar13[1];
          plVar13 = plVar13 + 2;
        } while (local_58 < local_60);
        goto LAB_002d96ba;
      }
      local_58 = 1;
LAB_002d98be:
      lVar9 = lVar9 - local_48;
    }
    else {
      if (local_58 < local_60) goto LAB_002d9684;
LAB_002d96ba:
      if (local_58 == local_60) goto LAB_002d98be;
    }
    while( true ) {
      plVar13 = (long *)(param_6[1] * 0x10 + *param_6);
      *plVar13 = lVar15;
      plVar13[1] = lVar9;
      plVar13 = (long *)(param_6[1] * 0x10 + *param_6);
      *plVar13 = *plVar13 + *(long *)(param_2 + 0x700 + (ulong)local_74 * 0x100);
      param_6[1] = param_6[1] + 1;
      uVar12 = local_68;
      uVar10 = local_58;
      if (local_70[0] != 1) break;
LAB_002d9701:
      if (local_58 <= uVar12) {
        return 0;
      }
      lVar15 = *(long *)(local_60 + uVar12 * 8);
      local_68 = uVar12 + 1;
      if (uVar12 == 0) {
        lVar15 = lVar15 + local_48;
        lVar9 = local_50 - local_48;
        if (local_58 != 1) goto LAB_002d9736;
        local_68 = 1;
        goto LAB_002d9762;
      }
      lVar9 = local_50;
      if (local_68 < local_58) {
LAB_002d9736:
        plVar13 = (long *)(uVar12 * 8 + 8 + local_60);
        do {
          if (*plVar13 != lVar9 + lVar15) break;
          local_68 = local_68 + 1;
          lVar9 = lVar9 + local_50;
          plVar13 = plVar13 + 1;
        } while (local_68 < local_58);
      }
      if (local_58 == local_68) {
LAB_002d9762:
        lVar9 = lVar9 - local_40;
      }
    }
  } while( true );
}


// ===== 002d9980 kbusSetupCpuPointerForBusFlush_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusSetupCpuPointerForBusFlush_GV100(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  
  if (((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) &&
     (*(char *)(param_2 + 0xad28) != '\0')) {
    if (*(char *)(param_2 + 0xad0c) != '\0') {
      nvAssertFailedNoLog("!kbusIsBarAccessBlocked(pKernelBus)",
                          "src/kernel/gpu/bus/arch/volta/kern_bus_gv100.c",0x41);
      return 0x40;
    }
    iVar1 = memdescCreate(param_2 + 0xad18,param_1,0x1000,0x1000,1,2,1);
    if (iVar1 == 0) {
      *(undefined4 *)(*(long *)(param_2 + 0xad18) + 0x9c) = 0x57;
      iVar1 = memdescAlloc(*(undefined8 *)(param_2 + 0xad18));
      if (iVar1 == 0) {
        lVar2 = memdescMapInternal(param_1,*(undefined8 *)(param_2 + 0xad18),8);
        *(long *)(param_2 + 0xad20) = lVar2;
        if (lVar2 != 0) {
          return 0;
        }
        iVar1 = 0x1a;
        nvAssertFailedNoLog("pKernelBus->pReadToFlush != NULL",
                            "src/kernel/gpu/bus/arch/volta/kern_bus_gv100.c",0x5b);
      }
      else {
        nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/volta/kern_bus_gv100.c",0x4f)
        ;
      }
    }
    else {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/arch/volta/kern_bus_gv100.c",0x4a);
    }
    (**(code **)(param_2 + 0x230))(param_1,param_2);
    return iVar1;
  }
  return 0;
}


// ===== 002d9b20 kbusDestroyCpuPointerForBusFlush_GV100 =====

void kbusDestroyCpuPointerForBusFlush_GV100(undefined8 param_1,long param_2)

{
  if (*(long *)(param_2 + 0xad20) != 0) {
    memdescUnmapInternal(param_1,*(undefined8 *)(param_2 + 0xad18),1);
    *(undefined8 *)(param_2 + 0xad20) = 0;
  }
  memdescFree(*(undefined8 *)(param_2 + 0xad18));
  memdescDestroy(*(undefined8 *)(param_2 + 0xad18));
  *(undefined8 *)(param_2 + 0xad18) = 0;
  return;
}


// ===== 002d9b80 kbusTeardownCoherentCpuMapping_GV100 =====

void kbusTeardownCoherentCpuMapping_GV100(long param_1,long param_2,char param_3)

{
  long lVar1;
  long lVar2;
  
  if (*(char *)(param_2 + 0xa868) == '\0') {
    return;
  }
  if (*(int *)(param_2 + 0xa86c) != 0) {
    lVar1 = 0;
    do {
      if (*(long *)(param_2 + 0xa8b0 + lVar1 * 8) != 0) {
        nvAssertFailedNoLog("pKernelBus->coherentCpuMapping.refcnt[i] == 0",
                            "src/kernel/gpu/bus/arch/volta/kern_bus_gv100.c",300);
        return;
      }
      lVar2 = *(long *)(param_2 + 0xa870 + lVar1 * 8);
      if (lVar2 != 0) {
        if (param_3 != '\0') {
          osFlushGpuCoherentCpuCacheRange
                    (*(undefined8 *)(param_1 + 0x4e0),lVar2,
                     *(undefined8 *)(param_2 + 0xa890 + lVar1 * 8));
          lVar2 = *(long *)(param_2 + 0xa870 + lVar1 * 8);
        }
        osUnmapPciMemoryKernel64(param_1,lVar2);
        *(undefined8 *)(param_2 + 0xa870 + lVar1 * 8) = 0;
      }
      lVar1 = lVar1 + 1;
    } while ((uint)lVar1 < *(uint *)(param_2 + 0xa86c));
  }
  *(undefined1 *)(param_2 + 0xa868) = 0;
  return;
}


// ===== 002d9c80 kbusFlushSingle_GV100 =====

uint kbusFlushSingle_GV100(long param_1,long param_2,uint param_3)

{
  char cVar1;
  
  if ((*(char *)(param_1 + 0x908) == '\0') ||
     ((*(char *)(param_1 + 0x4913) != '\0' && (*(char *)(param_1 + 0x491e) == '\0')))) {
    if (*(char *)(param_1 + 0x454) == '\0') {
      if ((param_3 & 2) == 0) {
        cVar1 = *(char *)(param_1 + 0x44f);
      }
      else {
        LOCK();
        UNLOCK();
        cVar1 = *(char *)(param_1 + 0x44f);
      }
      if (((((cVar1 == '\0') && (*(char *)(param_1 + 0x450) == '\0')) &&
           (*(char *)(param_1 + 0x451) == '\0')) &&
          ((*(char *)(param_1 + 0x461) == '\0' && (*(char *)(param_1 + 0x456) == '\0')))) &&
         ((*(char *)(param_1 + 0x44c) != '\0' && (*(char *)(param_2 + 0xad0c) == '\0')))) {
        if (((((param_3 & 1) != 0) && (*(char *)(param_2 + 0xad28) != '\0')) &&
            (*(long *)(param_2 + 0xad20) == 0)) && (*(long *)(param_2 + 0x7c98) == 0)) {
          nvAssertFailedNoLog("(pKernelBus->pReadToFlush != NULL || pKernelBus->virtualBar2[GPU_GFID_PF].pCpuMapping != NULL)"
                              ,"src/kernel/gpu/bus/arch/volta/kern_bus_gv100.c",0x184);
          return 0x40;
        }
        if ((param_3 & 4) == 0) {
          return param_3 & 4;
        }
        regRead032(param_1 + 0x3a18,0,0,0x700000,0);
        return 0;
      }
    }
    else {
      LOCK();
      UNLOCK();
    }
  }
  return 0;
}


// ===== 002d9d90 kbusCalcCpuInvisibleBar2ApertureSize_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kbusCalcCpuInvisibleBar2ApertureSize_GV100(long param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  
  lVar1 = *(long *)(param_1 + 0x1b98);
  lVar4 = gpuGetKernelFifoShared_IMPL();
  if (((*(char *)(param_1 + 0x908) == '\0') ||
      ((*(char *)(param_1 + 0x4913) != '\0' && (*(char *)(param_1 + 0x491e) == '\0')))) &&
     (lVar1 != 0)) {
    iVar5 = 0;
    iVar3 = 0;
    while( true ) {
      iVar2 = (**(code **)(lVar1 + 0x418))(param_1,lVar1,iVar3,0);
      iVar5 = iVar5 + (iVar2 + 0xfffU & 0xfffff000);
      if (iVar3 == 1) break;
      iVar3 = 1;
    }
    iVar3 = (**(code **)(lVar4 + 0x2b0))(param_1,lVar4,0);
    return iVar5 + 0xfff + iVar3 & 0xfffff000;
  }
  return 0;
}


// ===== 002d9e70 kbusConstructEngine_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbusConstructEngine_IMPL(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  ulong uVar3;
  char *pcVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint local_1c;
  
  cVar1 = rmcfg_IsAMPERE_CLASSIC_GPUSorBetter();
  if ((cVar1 != '\0') && (*(char *)(param_1 + 1099) != '\0')) {
    *(undefined1 *)(param_2 + 0xad04) = 1;
  }
  if (*(char *)(param_1 + 0x4913) != '\0') {
    *(undefined1 *)(param_2 + 0xad08) = 1;
  }
  uVar3 = (**(code **)(param_2 + 0x170))(param_1,param_2);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  uVar6 = *(uint *)(param_1 + 0x4924) >> 2 & 3;
  if (uVar6 == 2) {
    if ((*(char *)(param_1 + 0x4a21) == '\0') && (*(char *)(param_1 + 0x4a22) != '\0')) {
      nvDbg_Printf("src/kernel/gpu/bus/kern_bus.c",0x8c,"kbusInitRegistryOverrides",3,
                   "NVRM: BAR PTEs not supported in sysmem. Ignoring global override request.\n");
LAB_002d9f0d:
      uVar7 = *(undefined4 *)(param_2 + 0xad2c);
    }
    else {
      uVar7 = 1;
      *(undefined8 *)(param_2 + 0xad2c) = 0x100000001;
    }
  }
  else if (uVar6 == 3) {
    uVar7 = 2;
    *(undefined8 *)(param_2 + 0xad2c) = 0x200000002;
  }
  else {
    if (uVar6 != 1) goto LAB_002d9f0d;
    if ((*(char *)(param_1 + 0x4a21) == '\0') && (*(char *)(param_1 + 0x4a22) != '\0')) {
      nvDbg_Printf("src/kernel/gpu/bus/kern_bus.c",0x7e,"kbusInitRegistryOverrides",3,
                   "NVRM: BAR PTEs not supported in sysmem. Ignoring global override request.\n");
      uVar7 = *(undefined4 *)(param_2 + 0xad2c);
    }
    else {
      *(undefined8 *)(param_2 + 0xad2c) = 1;
      uVar7 = 1;
    }
  }
  nvDbg_Printf("src/kernel/gpu/bus/kern_bus.c",0x92,"kbusInitRegistryOverrides",1,
               "NVRM: Using aperture %d for BAR2 PTEs\n",uVar7);
  uVar6 = *(uint *)(param_1 + 0x4924) >> 0x1a & 3;
  if (uVar6 == 2) {
    if ((*(char *)(param_1 + 0x4a21) == '\0') && (*(char *)(param_1 + 0x4a22) != '\0')) {
      nvDbg_Printf("src/kernel/gpu/bus/kern_bus.c",0xb7,"kbusInitRegistryOverrides",3,
                   "NVRM: BAR PDEs not supported in sysmem. Ignoring global override request.\n");
    }
    else {
      *(undefined8 *)(param_2 + 0xad34) = 0x100000001;
    }
  }
  else if (uVar6 == 3) {
    *(undefined8 *)(param_2 + 0xad34) = 0x200000002;
  }
  else if (uVar6 == 1) {
    if ((*(char *)(param_1 + 0x4a21) == '\0') && (*(char *)(param_1 + 0x4a22) != '\0')) {
      nvDbg_Printf("src/kernel/gpu/bus/kern_bus.c",0xa9,"kbusInitRegistryOverrides",3,
                   "NVRM: BAR PDEs not supported in sysmem. Ignoring global override request.\n");
    }
    else {
      *(undefined8 *)(param_2 + 0xad34) = 1;
    }
  }
  iVar2 = osReadRegistryDword(param_1,"RMForceStaticBar1",&local_1c);
  if ((iVar2 == 0) && (local_1c < 3)) {
    *(uint *)(param_2 + 0xad4c) = local_1c;
    nvDbg_Printf("src/kernel/gpu/bus/kern_bus.c",0xc1,"kbusInitRegistryOverrides",3,
                 "NVRM: Forcing static BAR1 to type %d.\n");
  }
  else {
    *(undefined4 *)(param_2 + 0xad4c) = 2;
  }
  *(undefined4 *)(param_2 + 0xad54) = 0;
  iVar2 = osReadRegistryDword(param_1,"RmGpuDirectRdmaForceSPA",&local_1c);
  if ((iVar2 == 0) && (local_1c == 1)) {
    *(undefined4 *)(param_2 + 0xad54) = 1;
  }
  iVar2 = osReadRegistryDword(param_1,"P2PMailboxClientAllocated",&local_1c);
  if (iVar2 == 0) {
    *(bool *)(param_2 + 0xad01) = local_1c != 0;
  }
  iVar2 = osReadRegistryDword(param_1,"RMBar1RestoreSize",&local_1c);
  if (iVar2 == 0) {
    *(bool *)(param_2 + 0x559) = local_1c != 0;
  }
  iVar2 = osReadRegistryDword(param_1,"RmForceBarAccessOnHcc",&local_1c);
  if (((iVar2 == 0) && (local_1c == 1)) &&
     (cVar1 = gpuIsCCDevToolsModeEnabled_IMPL(param_1), cVar1 != '\0')) {
    *(undefined1 *)(param_2 + 0xad47) = 1;
  }
  (**(code **)(param_2 + 1000))(param_2);
  if (*(char *)(param_1 + 0x908) != '\0') {
    uVar3 = (**(code **)(param_2 + 0x168))(param_1,param_2);
    uVar5 = 0x4b;
    pcVar4 = "kbusInitBarsSize_HAL(pGpu, pKernelBus)";
    if ((int)uVar3 != 0) goto LAB_002da11b;
  }
  uVar3 = (**(code **)(param_2 + 0x3f0))(param_2);
  uVar5 = 0x4f;
  pcVar4 = "kbusInitBarsBaseInfo_HAL(pKernelBus)";
  if ((int)uVar3 == 0) {
    uVar3 = kbusSetBarsApertureSize_GM107(param_1,param_2,0,"src/kernel/gpu/bus/kern_bus.c",0x4f);
    uVar5 = 0x52;
    pcVar4 = "kbusSetBarsApertureSize_HAL(pGpu, pKernelBus, GPU_GFID_PF)";
    if ((int)uVar3 == 0) {
      uVar3 = (**(code **)(param_2 + 0x548))
                        (param_1,param_2,
                         "kbusSetBarsApertureSize_HAL(pGpu, pKernelBus, GPU_GFID_PF)",
                         "src/kernel/gpu/bus/kern_bus.c",0x52);
      if ((int)uVar3 == 0) {
        return uVar3;
      }
      uVar5 = 0x55;
      pcVar4 = "kbusConstructXalApertures_HAL(pGpu, pKernelBus)";
    }
  }
LAB_002da11b:
  nvCheckOkFailedNoLog(4,uVar3 & 0xffffffff,pcVar4,"src/kernel/gpu/bus/kern_bus.c",uVar5);
  return uVar3 & 0xffffffff;
}


// ===== 002da32e kbusGetBar1VARangeForDevice_IMPL.cold =====

void kbusGetBar1VARangeForDevice_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002da340 kbusGetBar1VARangeForDevice_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbusGetBar1VARangeForDevice_IMPL
                (long param_1,long param_2,long param_3,undefined1 (*param_4) [16])

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  long *plVar4;
  undefined8 uVar5;
  long lVar6;
  ulong uVar7;
  undefined8 uVar8;
  char *pcVar9;
  undefined1 auVar10 [16];
  long local_48 [3];
  
  lVar1 = *(long *)(param_1 + 0x1bc0);
  plVar4 = (long *)(**(code **)(param_2 + 0x4e8))();
  if (plVar4 == (long *)0x0) {
    nvAssertFailedNoLog("pBar1VAS != NULL","src/kernel/gpu/bus/kern_bus.c",0x103);
    uVar7 = 0x40;
  }
  else {
    uVar5 = (**(code **)(*plVar4 + 0x60))();
    uVar8 = (**(code **)(*plVar4 + 0x58))();
    *(undefined8 *)(*param_4 + 8) = uVar5;
    *(undefined8 *)*param_4 = uVar8;
    if (param_3 == 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    lVar6 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_3 + 0x110) + 0x48),
                               __nvoc_class_def_RmClient);
    if (lVar6 == 0) {
      nvAssertFailedNoLog("pRmClient != NULL","src/kernel/gpu/bus/kern_bus.c",0x108);
      uVar7 = 0x23;
    }
    else if ((((lVar1 == 0) ||
              (cVar3 = kmigmgrIsMIGMemPartitioningEnabled_IMPL(param_1,lVar1), cVar3 == '\0')) ||
             (cVar3 = rmclientIsCapable_IMPL(lVar6,3), cVar3 != '\0')) ||
            (cVar3 = kmigmgrIsDeviceUsingDeviceProfiling_IMPL(param_1,lVar1,param_3), cVar3 != '\0')
            ) {
      uVar7 = 0;
    }
    else {
      uVar5 = *(undefined8 *)(param_1 + 0x1b70);
      auVar10 = memmgrGetMIGPartitionableBAR1Range_IMPL(param_1,*(undefined8 *)(param_1 + 0x1b78));
      *param_4 = auVar10;
      uVar7 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,lVar1,param_3,local_48);
      uVar8 = 0x114;
      pcVar9 = "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)";
      if ((int)uVar7 == 0) {
        uVar7 = kmemsysSwizzIdToMIGMemRange_IMPL
                          (param_1,uVar5,*(undefined4 *)(local_48[0] + 0x968),
                           *(undefined8 *)*param_4,*(undefined8 *)(*param_4 + 8),param_4);
        if ((int)uVar7 == 0) {
          return uVar7;
        }
        uVar8 = 0x116;
        pcVar9 = 
        "kmemsysSwizzIdToMIGMemRange(pGpu, pKernelMemorySystem, ref.pKernelMIGGpuInstance->swizzId, *pBar1VARange, pBar1VARange)"
        ;
      }
      nvAssertOkFailedNoLog(uVar7 & 0xffffffff,pcVar9,"src/kernel/gpu/bus/kern_bus.c",uVar8);
      uVar7 = uVar7 & 0xffffffff;
    }
  }
  return uVar7;
}


// ===== 002da530 kbusSetupPeerBarAccess_IMPL =====

undefined8
kbusSetupPeerBarAccess_IMPL(long param_1,long param_2,ulong param_3,long param_4,long *param_5)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  long local_40 [2];
  
  local_40[0] = *param_5;
  if ((param_3 & 0xfff) != 0) {
    nvAssertFailedNoLog("((base & RM_PAGE_MASK) == 0)","src/kernel/gpu/bus/kern_bus.c",0x12a);
    return 0xffffffffffffffff;
  }
  if (local_40[0] == 0) {
    iVar1 = memdescCreate(local_40,param_1,param_4,0,1,1,1,0x20000);
    uVar4 = 0x131;
    if (iVar1 == 0) {
      memdescDescribe(local_40[0],1,param_3,param_4);
      goto LAB_002da596;
    }
  }
  else {
    uVar2 = memdescGetPhysAddr(local_40[0],1,0);
    if ((uVar2 != param_3) || (*(long *)(local_40[0] + 0x30) != param_4)) {
      uVar4 = 0x137;
      pcVar5 = 
      "(memdescGetPhysAddr(pMemDesc, AT_GPU, 0) == base) && (memdescGetSize(pMemDesc) == size)";
      goto LAB_002da603;
    }
LAB_002da596:
    if ((param_1 == param_2) ||
       (iVar1 = memdescMapIommu(local_40[0],*(undefined4 *)(param_2 + 0x868)), iVar1 == 0)) {
      lVar3 = memdescGetIommuMap(local_40[0],*(undefined4 *)(param_2 + 0x868));
      *param_5 = local_40[0];
      if (lVar3 == 0) {
        nvDbg_Printf("src/kernel/gpu/bus/kern_bus.c",0x14c,"kbusSetupPeerBarAccess_IMPL",1,
                     "NVRM: no IOVA mapping found for pre-existing P2P domain memdesc\n");
        uVar4 = memdescGetPhysAddr(local_40[0],1,0);
      }
      else {
        uVar4 = *(undefined8 *)(lVar3 + 0x28);
      }
      return uVar4;
    }
    memdescDestroy(local_40[0]);
    uVar4 = 0x143;
  }
  pcVar5 = "status == NV_OK";
LAB_002da603:
  nvAssertFailedNoLog(pcVar5,"src/kernel/gpu/bus/kern_bus.c",uVar4);
  return 0xffffffffffffffff;
}


// ===== 002da710 kbusGetFlushAperture_IMPL =====

char kbusGetFlushAperture_IMPL(undefined8 param_1,int param_2)

{
  return (param_2 != 2) + '\x01';
}


// ===== 002da720 kbusDestruct_IMPL =====

void kbusDestruct_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  
  uVar3 = 0;
  if (param_1 != 0) {
    uVar3 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar1 = gpuEngineGetGpu(uVar3);
  memdescFree(*(undefined8 *)(param_1 + 0x648));
  memdescDestroy(*(undefined8 *)(param_1 + 0x648));
  *(undefined8 *)(param_1 + 0x648) = 0;
  memdescFree(*(undefined8 *)(param_1 + 0x4678));
  memdescDestroy(*(undefined8 *)(param_1 + 0x4678));
  *(undefined8 *)(param_1 + 0x4678) = 0;
  if (*(int *)(param_1 + 0xad68) != 0) {
    lVar2 = 0;
    do {
      lVar4 = lVar2 * 0x88;
      lVar2 = lVar2 + 1;
      __nvoc_objDelete(lVar4 + *(long *)(param_1 + 0xad60));
    } while ((uint)lVar2 < *(uint *)(param_1 + 0xad68));
  }
  portMemFree(*(undefined8 *)(param_1 + 0xad60));
  *(undefined8 *)(param_1 + 0xad60) = 0;
  *(undefined4 *)(param_1 + 0xad68) = 0;
  kbusDestructVirtualBar2_VBAR2(lVar1,param_1,1,0);
  if (((*(char *)(lVar1 + 0x4a4e) != '\0') && (*(char *)(lVar1 + 0x4913) != '\0')) &&
     (lVar2 = *(long *)(param_1 + 0x7c98), lVar2 != 0)) {
    if (*(long *)(NvVGPU_Table + (ulong)*(uint *)(lVar1 + 0x7a4) * 8) != 0) {
      nvAssertFailedNoLog("pVGpu == NULL","src/kernel/gpu/bus/kern_bus.c",0x182);
      lVar2 = *(long *)(param_1 + 0x7c98);
    }
    osUnmapPciMemoryKernelOld(lVar1,lVar2);
    return;
  }
  return;
}


