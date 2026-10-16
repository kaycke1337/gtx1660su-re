// ===== 003faff0 kgmmuTranslatePdePcfFromSw_GH100 =====

undefined8 kgmmuTranslatePdePcfFromSw_GH100(undefined8 param_1,uint param_2,undefined4 *param_3)

{
  if (param_2 < 0x202) {
    if (0x1ff < param_2) {
      *param_3 = 0;
      return 0;
    }
    if (param_2 == 4) {
LAB_003fb065:
      *param_3 = 3;
      return 0;
    }
    if (param_2 < 5) {
      if (param_2 < 2) {
        *param_3 = 2;
        return 0;
      }
    }
    else if (param_2 == 0x20) goto LAB_003fb065;
  }
  else if ((param_2 == 0x204) || (param_2 == 0x220)) {
    *param_3 = 1;
    return 0;
  }
  return 0x56;
}


// ===== 003fb070 kgmmuTranslatePdePcfFromHw_GH100 =====

undefined8
kgmmuTranslatePdePcfFromHw_GH100(undefined8 param_1,uint param_2,int param_3,undefined4 *param_4)

{
  if (param_3 == 0) {
    if (param_2 == 2) {
      *param_4 = 1;
      return 0;
    }
    if (param_2 < 3) {
      if (param_2 != 0) {
        *param_4 = 0x204;
        return 0;
      }
      *param_4 = 0x201;
      return 0;
    }
    if (param_2 == 3) {
      *param_4 = 4;
      return 0;
    }
  }
  else {
    if (param_2 == 2) {
      *param_4 = 0;
      return 0;
    }
    if (param_2 < 3) {
      if (param_2 != 0) {
        *param_4 = 0x220;
        return 0;
      }
      *param_4 = 0x200;
      return 0;
    }
    if (param_2 == 3) {
      *param_4 = 0x20;
      return 0;
    }
  }
  return 0x56;
}


// ===== 003fb120 kgmmuGetGraphicsEngineId_GH100 =====

undefined8 kgmmuGetGraphicsEngineId_GH100(void)

{
  return 0x180;
}


// ===== 003fb130 kgmmuGetFaultRegisterMappings_GH100 =====

undefined8
kgmmuGetFaultRegisterMappings_GH100
          (long param_1,long param_2,uint param_3,undefined8 *param_4,long *param_5,
          undefined8 *param_6,long *param_7,long *param_8,long *param_9,int *param_10,
          undefined8 *param_11)

{
  int iVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  long *plVar5;
  undefined8 uVar6;
  
  plVar5 = (long *)gpuGetDeviceMapping_IMPL(param_1,0,0);
  if (1 < param_3) {
    nvAssertFailedNoLog("(index < NUM_FAULT_BUFFERS)",
                        "src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0x171);
    return 0x1f;
  }
  lVar2 = *plVar5;
  cVar3 = gpuIsCCFeatureEnabled_IMPL(param_1);
  if ((cVar3 != '\0') && (*(char *)(param_1 + 0x4a78) != '\0')) {
    *param_4 = 0;
    *param_6 = 0;
    *param_7 = 0;
    *param_8 = 0;
    *param_9 = 0;
    *param_10 = 0;
    *param_11 = 0;
    if (param_3 == 1) {
      uVar4 = intrGetVectorFromEngineId_IMPL(param_1,*(undefined8 *)(param_1 + 0x1c20),0xa6,0);
      uVar6 = *(undefined8 *)(*(long *)(param_2 + 0x640) + 0x60);
      iVar1 = (uVar4 >> 5) * 4;
      *param_7 = (ulong)(uint)(iVar1 + 0x1000 + *(int *)(param_1 + 0x3a64)) + lVar2;
      *param_8 = (ulong)(uint)(iVar1 + 0x1200 + *(int *)(param_1 + 0x3a64)) + lVar2;
      *param_9 = (ulong)(uint)(iVar1 + 0x1400 + *(int *)(param_1 + 0x3a64)) + lVar2;
      *param_10 = 1 << ((byte)uVar4 & 0x1f);
      *param_4 = uVar6;
      *param_5 = (ulong)(*(int *)(param_1 + 0x3a64) + 0x310c) + lVar2;
    }
    else {
      *param_5 = (ulong)(*(int *)(param_1 + 0x3a64) + 0x3108) + lVar2;
    }
    return 0;
  }
  uVar6 = kgmmuGetFaultRegisterMappings_TU102(param_1,param_2,param_3,param_4,param_5,param_6);
  return uVar6;
}


// ===== 003fb340 kgmmuFaultBufferAllocSharedMemory_GH100 =====

ulong kgmmuFaultBufferAllocSharedMemory_GH100(long param_1,long param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  long local_10;
  
  if (*(char *)(param_2 + 0x511) != '\0') {
    nvDbg_Printf("src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0x1ca,
                 "kgmmuFaultBufferAllocSharedMemory_GH100",4,
                 "NVRM: Fault-Buffer is disabled. Flush Seq memory cannot be created\n");
    nvAssertFailedNoLog(&DAT_00d65215,"src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0x1cb);
    return 0x40;
  }
  if (((param_3 == 1) && (cVar1 = gpuIsCCFeatureEnabled_IMPL(), cVar1 != '\0')) &&
     (*(char *)(param_1 + 0x4a78) != '\0')) {
    uVar3 = memdescCreate(&local_10,param_1,4,0x1000,0,1,1);
    if ((int)uVar3 != 0) {
      return uVar3;
    }
    memdescSetPageSize(local_10,1,0x200000);
    *(undefined4 *)(local_10 + 0x9c) = 0xa4;
    uVar2 = memdescAlloc();
    if (uVar2 == 0x51) {
      nvDbg_Printf("src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0x1ef,
                   "kgmmuFaultBufferAllocSharedMemory_GH100",4,
                   "NVRM: Allocation failed with big page size, retrying with default page size\n");
      memdescSetPageSize(local_10,1,0x1000);
      *(undefined4 *)(local_10 + 0x9c) = 0xa4;
      uVar2 = memdescAlloc();
    }
    if (uVar2 == 0) {
      uVar3 = memdescMap(local_10,0,*(undefined8 *)(local_10 + 0x30),1,3,param_2 + 0x720);
      uVar2 = (uint)uVar3;
      if (uVar2 == 0) {
        *(long *)(param_2 + 0x718) = local_10;
        return uVar3;
      }
      memdescFree();
    }
    memdescDestroy(local_10);
    return (ulong)uVar2;
  }
  return 0;
}


// ===== 003fb500 kgmmuFaultBufferFreeSharedMemory_GH100 =====

void kgmmuFaultBufferFreeSharedMemory_GH100(long param_1,long param_2,int param_3)

{
  undefined8 uVar1;
  char cVar2;
  
  if (param_3 != 1) {
    return;
  }
  cVar2 = gpuIsCCFeatureEnabled_IMPL();
  if ((cVar2 != '\0') && (*(char *)(param_1 + 0x4a78) != '\0')) {
    uVar1 = *(undefined8 *)(param_2 + 0x718);
    memdescUnmap(uVar1,1,*(undefined8 *)(param_2 + 0x720),*(undefined8 *)(param_2 + 0x728));
    memdescFree(uVar1);
    memdescDestroy(uVar1);
    return;
  }
  return;
}


// ===== 003fb580 kgmmuIssueReplayableFaultBufferFlush_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgmmuIssueReplayableFaultBufferFlush_GH100(long param_1,undefined8 param_2,char param_3)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  uint local_1c;
  
  lVar1 = *(long *)(param_1 + 0x1ba8);
  local_1c = (uint)(param_3 != '\0');
  cVar2 = gpuIsCCFeatureEnabled_IMPL();
  if (((cVar2 != '\0') && (*(char *)(param_1 + 0x4a78) != '\0')) &&
     (*(char *)(param_1 + 0x909) != '\0')) {
    uVar3 = (**(code **)(lVar1 + 0x9d8))(param_1,lVar1,1,&local_1c,1);
    return uVar3;
  }
  return 0x56;
}


// ===== 003fb600 kgmmuToggleFaultOnPrefetch_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgmmuToggleFaultOnPrefetch_GH100(long param_1,undefined8 param_2,char param_3)

{
  undefined8 uVar1;
  uint local_c;
  
  local_c = (uint)(param_3 != '\0');
  uVar1 = 0x56;
  if (*(char *)(param_1 + 0x909) != '\0') {
    uVar1 = (**(code **)(*(long *)(param_1 + 0x1ba8) + 0x9d8))
                      (param_1,*(long *)(param_1 + 0x1ba8),2,&local_c,1);
  }
  return uVar1;
}


// ===== 003fb650 kgmmuReadShadowBufPutIndex_GH100 =====

ulong kgmmuReadShadowBufPutIndex_GH100(long param_1,undefined8 param_2,int param_3)

{
  uint uVar1;
  ulong uVar2;
  
  if (param_3 != 1) {
    uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x3108,0);
    return (ulong)(uVar1 >> 0xc);
  }
  uVar2 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x310c,0);
  return uVar2;
}


// ===== 003fb6a0 kgmmuIsFaultEngineBar1_GH100 =====

bool kgmmuIsFaultEngineBar1_GH100(undefined8 param_1,int param_2)

{
  return param_2 == 0x100;
}


// ===== 003fb6b0 kgmmuIsFaultEngineBar2_GH100 =====

bool kgmmuIsFaultEngineBar2_GH100(undefined8 param_1,int param_2)

{
  return param_2 == 0x140;
}


// ===== 003fb6c0 kgmmuIsFaultEnginePhysical_GH100 =====

bool kgmmuIsFaultEnginePhysical_GH100(undefined8 param_1,int param_2)

{
  return param_2 == 0x38;
}


// ===== 003fb6d0 kgmmuReadClientShadowBufPutIndex_GH100 =====

undefined8 kgmmuReadClientShadowBufPutIndex_GH100(void)

{
  return 0;
}


// ===== 003fb6e0 kgmmuWriteClientShadowBufPutIndex_GH100 =====

void kgmmuWriteClientShadowBufPutIndex_GH100(void)

{
  return;
}


// ===== 003fb6f0 kgmmuCopyFaultPacketToClientShadowBuffer_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgmmuCopyFaultPacketToClientShadowBuffer_GH100
              (long param_1,long param_2,long param_3,uint param_4,int param_5,uint param_6,
              uint param_7,undefined8 param_8,undefined4 *param_9)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  char cVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  undefined1 local_59;
  undefined1 local_58 [40];
  
  uVar9 = (ulong)param_4;
  lVar1 = *(long *)(param_1 + 0x1d18);
  local_59 = 1;
  cVar4 = gpuIsCCFeatureEnabled_IMPL();
  if ((cVar4 == '\0') || (*(char *)(param_1 + 0x4a78) == '\0')) {
    iVar5 = kgmmuCopyFaultPacketToClientShadowBuffer_GV100
                      (param_1,param_2,param_3,uVar9,param_5,param_6,param_7,param_8,param_9);
  }
  else {
    *param_9 = 0;
    lVar2 = *(long *)(param_3 + 0x70 + uVar9 * 8);
    lVar8 = uVar9 * 0x30 + param_3;
    uVar6 = (**(code **)(param_2 + 0x3a8))(param_1,param_2,lVar8,param_5);
    portMemCopy(local_58,0x20,uVar6,0x20);
    if (param_4 == 1) {
      (**(code **)(param_2 + 0x3a0))(param_1,param_2,lVar8,param_5,1);
      LOCK();
      UNLOCK();
      uVar3 = (ulong)(param_5 + 1) % (ulong)param_7;
      *(int *)(param_3 + 0x58) = (int)uVar3;
      (**(code **)(param_2 + 0x2e0))(param_1,param_2,1,uVar3,param_8);
      cVar4 = (**(code **)(param_2 + 0x3b8))(param_1,param_2,lVar2,param_6,param_7);
      if (cVar4 != '\0') {
        return 0;
      }
    }
    lVar8 = (ulong)(param_6 & 0x7f) * 0x20;
    lVar10 = *(long *)(*(long *)(lVar2 + 0x48) +
                      (ulong)((param_6 >> 7) + *(int *)(lVar2 + 0x54)) * 0x10) + lVar8;
    if (*(char *)(lVar10 + 0x10) == '\0') {
      lVar2 = *(long *)(*(long *)(lVar2 + 0x48) + (ulong)(param_6 >> 7) * 0x10);
      lVar7 = kgmmuGetShadowFaultBufferCslContext_IMPL(param_1,param_2,uVar9);
      if (lVar7 != 0) {
        iVar5 = ccslEncryptWithRotationChecks_KERNEL
                          (lVar7,0x20,local_58,&local_59,1,lVar2 + lVar8,lVar10);
        if (iVar5 == 0) {
          LOCK();
          UNLOCK();
          portMemCopy(lVar10 + 0x10,1,&local_59,1);
          *param_9 = 1;
          return 0;
        }
        if (iVar5 != 0x1a) {
          nvDbg_Printf("src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0x371,
                       "kgmmuCopyFaultPacketToClientShadowBuffer_GH100",4,
                       "NVRM: Error detected in fault buffer packet encryption: 0x%x\n",iVar5);
          return iVar5;
        }
        nvDbg_Printf("src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0x36c,
                     "kgmmuCopyFaultPacketToClientShadowBuffer_GH100",4,
                     "NVRM: Fatal error detected in fault buffer packet encryption: IV overflow!\n")
        ;
        (**(code **)(lVar1 + 0x180))(param_1);
        return 0x1a;
      }
      nvDbg_Printf("src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0x35c,
                   "kgmmuCopyFaultPacketToClientShadowBuffer_GH100",4,
                   "NVRM: CSL context for type 0x%x unexpectedtly NULL\n",uVar9);
    }
    else {
      nvDbg_Printf("src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0x355,
                   "kgmmuCopyFaultPacketToClientShadowBuffer_GH100",4,
                   "NVRM: Plaintext valid bit not reset by client.\n");
    }
    iVar5 = 0x40;
  }
  return iVar5;
}


// ===== 003fba10 kgmmuIsReplayableShadowFaultBufferFull_GH100 =====

undefined8
kgmmuIsReplayableShadowFaultBufferFull_GH100
          (undefined8 param_1,undefined8 param_2,long param_3,int param_4,uint param_5)

{
  return CONCAT71((int7)((ulong)(param_4 + 1U) / (ulong)param_5 >> 8),
                  **(uint **)(param_3 + 0x60) == (param_4 + 1U) % param_5);
}


// ===== 003fba30 kgmmuSignExtendFaultAddress_GH100 =====

void kgmmuSignExtendFaultAddress_GH100(long param_1,long param_2,long *param_3)

{
  uint uVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = osGetCpuVaAddrShift();
  uVar1 = 0;
  for (uVar2 = *(ulong *)(param_2 + 0x598); (uVar2 & 1) == 0;
      uVar2 = uVar2 >> 1 | 0x8000000000000000) {
    uVar1 = uVar1 + 1;
  }
  uVar4 = 0x40;
  if (*(ulong *)(param_2 + 0x598) != 0) {
    uVar4 = uVar1;
  }
  if (uVar3 <= uVar4) {
    uVar1 = *(uint *)(param_1 + 0x884);
    if (uVar1 < 4) {
      if (uVar1 != 1) {
        *param_3 = (*param_3 << 7) >> 7;
      }
    }
    else if (uVar1 == 4) {
      nvAssertFailedNoLog("Invalid oor address mode type.",
                          "src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0x3c1);
      return;
    }
    return;
  }
  nvDbg_Printf("src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0x3c7,
               "kgmmuSignExtendFaultAddress_GH100",4,
               "NVRM: UVM has not defined what to do here, doing nothing\n");
  nvAssertFailedNoLog(&DAT_00d65215,"src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0x3c8);
  return;
}


// ===== 003fbb20 kgmmuCreateFakeSparseTablesInternal_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgmmuCreateFakeSparseTablesInternal_KERNEL(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  
  lVar1 = *(long *)(&DAT_00001b90 + param_1);
  uVar2 = *(ulong *)(*(long *)(param_2 + 0x518) + 0x170);
  uVar7 = (**(code **)(lVar1 + 0x438))(param_1,lVar1);
  lVar3 = *(long *)(lVar1 + 0x608);
  lVar4 = *(long *)(lVar1 + 0x600);
  iVar5 = (**(code **)(lVar1 + 0x430))(param_1,lVar1,-lVar3 & uVar2);
  if (iVar5 == 0) {
    iVar5 = kgmmuFillFakeSparseTables(param_2,uVar2,lVar4 + (lVar3 - 1U & uVar2));
    iVar6 = (**(code **)(lVar1 + 0x430))(param_1,lVar1,uVar7);
    if (iVar6 != 0) {
      nvAssertFailedNoLog("kbusSetBAR0WindowVidOffset_HAL(pGpu, pKernelBus, origBar0Mapping) == NV_OK"
                          ,"src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0x443);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar5,
               "kbusSetBAR0WindowVidOffset_HAL(pGpu, pKernelBus, bufferBaseOffset & ~bufBar0OffsetMask)"
               ,"src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0x43f);
  }
  return iVar5;
}


// ===== 003fbc30 kgmmuCreateFakeSparseTables_GH100 =====

ulong kgmmuCreateFakeSparseTables_GH100(undefined8 param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  
  uVar1 = memdescCreate(param_2 + 0x518,param_1,0x3000,0x1000,1,2);
  if (uVar1 != 0) {
    nvAssertOkFailedNoLog
              (uVar1,
               "memdescCreate(&pKernelGmmu->pFakeSparseBuffer, pGpu, RM_PAGE_SIZE * NV_GMMU_FAKE_SPARSE_TABLE_LEVELS, RM_PAGE_SIZE, NV_TRUE, ADDR_FBMEM, NV_MEMORY_WRITECOMBINED, MEMDESC_FLAGS_NONE)"
               ,"src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0x477);
    return (ulong)uVar1;
  }
  uVar1 = memdescAlloc(*(undefined8 *)(param_2 + 0x518));
  if (uVar1 == 0) {
    uVar2 = kgmmuCreateFakeSparseTablesInternal_KERNEL(param_1,param_2);
    uVar1 = (uint)uVar2;
    if (uVar1 == 0) {
      return uVar2;
    }
    nvAssertOkFailedNoLog
              (uVar2 & 0xffffffff,"kgmmuCreateFakeSparseTablesInternal(pGpu, pKernelGmmu)",
               "src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0x47c);
    memdescFree(*(undefined8 *)(param_2 + 0x518));
  }
  else {
    nvAssertOkFailedNoLog
              (uVar1,"memdescAlloc(pKernelGmmu->pFakeSparseBuffer)",
               "src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0x47a);
  }
  memdescDestroy(*(undefined8 *)(param_2 + 0x518));
  *(undefined8 *)(param_2 + 0x518) = 0;
  return (ulong)uVar1;
}


// ===== 003fbd50 kgmmuGetFakeSparseEntry_GH100 =====

long kgmmuGetFakeSparseEntry_GH100(undefined8 param_1,long param_2,byte *param_3)

{
  if ((*(long *)(param_2 + 0x518) != 0) && (0x25 < *param_3)) {
    return param_2 + 0x520 + ((ulong)(*param_3 - 0x26) / 9) * 8;
  }
  return 0;
}


// ===== 003fbd90 kgmmuFmtInitPdeApertures_GM10X =====

void kgmmuFmtInitPdeApertures_GM10X(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x1010001;
  *(undefined4 *)((long)param_2 + 6) = 0x2010301;
  return;
}


// ===== 003fbdb0 kgmmuFmtInitPteApertures_GM10X =====

void kgmmuFmtInitPteApertures_GM10X(undefined8 param_1,long param_2)

{
  *(undefined8 *)(param_2 + 2) = 0x201030101010001;
  return;
}


// ===== 003fbdd0 kgmmuFmtInitCaps_GM20X =====

void kgmmuFmtInitCaps_GM20X(undefined8 param_1,long param_2)

{
  *(undefined1 *)(param_2 + 0x28) = 1;
  return;
}


// ===== 003fbde0 kgmmuGetBigPageSize_GM107 =====

undefined8 kgmmuGetBigPageSize_GM107(long param_1)

{
  return *(undefined8 *)(param_1 + 0x540);
}


// ===== 003fbdf0 kgmmuCommitInvalidateTlbTest_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgmmuCommitInvalidateTlbTest_GM107(long param_1,long param_2,undefined4 *param_3)

{
  uint uVar1;
  ulong uVar2;
  undefined1 local_48 [12];
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 local_30 [24];
  
  if (*(char *)(param_3 + 1) != '\x01') {
    return 0x56;
  }
  portMemSet(local_48,0,0x30);
  local_3c = *param_3;
  timeoutSet(param_1 + 0x1af0,local_30,0,0x105);
  uVar1 = (**(code **)(param_2 + 0x1f8))(param_1,param_2,local_30);
  if (uVar1 == 0) {
    local_38 = 0x80000003;
    uVar2 = (**(code **)(param_2 + 0x200))(param_1,param_2,local_48);
  }
  else {
    nvAssertOkFailedNoLog
              (uVar1,"kgmmuCheckPendingInvalidates_HAL(pGpu, pKernelGmmu, &params.timeout)",
               "src/kernel/gpu/mmu/arch/maxwell/kern_gmmu_gm107.c",0x45);
    uVar2 = (ulong)uVar1;
  }
  return uVar2;
}


// ===== 003fbec0 kgmmuInvalidateTlb_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

int kgmmuInvalidateTlb_GM107
              (long param_1,long param_2,long param_3,ulong param_4,int param_5,undefined4 param_6,
              undefined4 param_7,char param_8)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 local_5c;
  uint local_58;
  undefined1 local_50 [32];
  
  if ((((param_1 == 0) || (*(char *)(param_1 + 0x44f) != '\0')) ||
      (*(char *)(param_1 + 0x450) != '\0')) || (*(char *)(param_1 + 0x451) != '\0')) {
    return 0;
  }
  if ((*(char *)(param_1 + 0x461) == '\0') &&
     ((*(char *)(param_1 + 0x908) == '\0' ||
      ((*(char *)(param_1 + 0x4913) != '\0' && (*(char *)(param_1 + 0x491e) == '\0')))))) {
    portMemSet(&local_68,0,0x30);
    if (((param_4 & 1) != 0) && (*(char *)(param_2 + 0x591) != '\0')) {
      nvDbg_Printf("src/kernel/gpu/mmu/arch/maxwell/kern_gmmu_gm107.c",0x91,
                   "kgmmuInvalidateTlb_GM107",1,
                   "NVRM: disable_mmu_invalidate flag, skipping hub invalidate.\n");
      return 0;
    }
    if ((((*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) == 0) ||
         (*(char *)(*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) + 0x26153) ==
          '\0')) || (lVar5 = gpuGetStaticInfo(param_1), lVar5 == 0)) ||
       ((*(byte *)(lVar5 + 0xa726) & 0x80) == 0)) {
      timeoutSet(param_1 + 0x1af0,local_50,0,0x105);
      local_5c = param_6;
      iVar2 = (**(code **)(param_2 + 0x1f8))(param_1,param_2,local_50);
      bVar1 = false;
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    else {
      bVar1 = true;
    }
    if (param_3 == 0) {
      local_58 = local_58 | 0x80000003;
      param_7 = 0;
    }
    else {
      local_58 = local_58 & 0xfffffffd | 0x80000001;
      iVar2 = memdescGetAddressSpace(param_3);
      local_60 = 0;
      if (iVar2 != 2) {
        iVar2 = memdescGetAddressSpace(param_3);
        local_60 = 1;
        if (iVar2 != 1) {
          return 0x56;
        }
      }
      uVar4 = memdescGetMemDescFromGpu(param_3,param_1);
      local_68 = memdescGetPhysAddr(uVar4,1,0);
    }
    if ((param_4 & 1) != 0) {
      local_58 = local_58 | 4;
    }
    if (((param_4 & 0x100) == 0) && (param_5 == 1)) {
      iVar2 = (**(code **)(param_2 + 0x210))(param_1,param_2,&local_68);
    }
    else {
      iVar2 = 0;
    }
    if (param_8 != '\0') {
      (**(code **)(param_2 + 0x218))(param_1,param_2,&local_68);
    }
    iVar3 = (**(code **)(param_2 + 0x228))(param_1,param_2,param_7,&local_68);
    if ((iVar3 != 0) && (iVar3 != 0x56)) {
      return iVar3;
    }
    if (bVar1) {
      lVar5 = gpuGetRpc(param_1);
      if (lVar5 == 0) {
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mmu/arch/maxwell/kern_gmmu_gm107.c",0xf5)
        ;
        return 0x1a;
      }
      if (iVar3 != 0) {
        return 0x56;
      }
      iVar3 = (**(code **)(lVar5 + 0x270))
                        (param_1,lVar5,local_68,local_58,*(code **)(lVar5 + 0x270));
    }
    else {
      iVar3 = (**(code **)(param_2 + 0x200))(param_1,param_2,&local_68);
    }
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = 0;
    do {
      if (iVar2 == 0) {
        return iVar3;
      }
      iVar2 = iVar2 + -1;
      iVar3 = kbusSendSysmembar_IMPL(param_1,*(undefined8 *)(&DAT_00001b90 + param_1));
    } while (iVar3 != 0x65);
    return 0x65;
  }
  return 0;
}


// ===== 003fc240 kgmmuDetermineMaxVASize_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgmmuDetermineMaxVASize_GM107(undefined8 param_1,long param_2)

{
  uint uVar1;
  char cVar2;
  undefined8 uVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar5 = &g_gmmuFmtVersions;
  uVar4 = 0;
  do {
    uVar1 = *puVar5;
    cVar2 = (**(code **)(param_2 + 600))(param_2,uVar1);
    if (uVar1 <= uVar4) {
      uVar1 = uVar4;
    }
    if (cVar2 != '\0') {
      uVar4 = uVar1;
    }
    puVar5 = puVar5 + 1;
  } while (puVar5 != (uint *)&DAT_00daaeb4);
  if (uVar4 != 2) {
    uVar3 = 0x200000000000000;
    if (uVar4 != 3) {
      uVar3 = 0x10000000000;
    }
    *(undefined8 *)(param_2 + 0x598) = uVar3;
    return;
  }
  *(undefined8 *)(param_2 + 0x598) = 0x2000000000000;
  return;
}


// ===== 003fc2e0 kgmmuGetMaxBigPageSize_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgmmuGetMaxBigPageSize_GM107(long param_1)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 0x590) != '\0') {
    return 0x20000;
  }
  uVar1 = (**(code **)(param_1 + 0x1d0))();
  return uVar1;
}


// ===== 003fc310 kgmmuGetHwPteApertureFromMemdesc_GM107 =====

char kgmmuGetHwPteApertureFromMemdesc_GM107(undefined8 param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = memdescGetAddressSpace(param_2);
  if (uVar1 != 2) {
    if (uVar1 < 3) {
      if (uVar1 == 1) {
        return '\x03' - (*(int *)(param_2 + 0x74) == 0);
      }
    }
    else if (uVar1 - 6 < 2) {
      return '\0';
    }
    nvAssertFailedNoLog(&DAT_00d65732,"src/kernel/gpu/mmu/arch/maxwell/kern_gmmu_gm107.c",0x172);
  }
  return '\0';
}


// ===== 003fc370 kgmmuFmtFamiliesInit_GM200 =====

undefined8 kgmmuFmtFamiliesInit_GM200(undefined8 param_1,long param_2)

{
  uint *puVar1;
  long lVar2;
  long *plVar3;
  
  plVar3 = (long *)(param_2 + 0x550);
  do {
    lVar2 = *plVar3;
    if (lVar2 != 0) {
      puVar1 = (uint *)(lVar2 + 0x4c0 + (ulong)*(ushort *)(lVar2 + 0x31e));
      *puVar1 = (uint)*(byte *)(lVar2 + 800) << ((byte)*(undefined2 *)(lVar2 + 0x31c) & 0x1f) |
                *puVar1 & *(uint *)(lVar2 + 0x318);
      puVar1 = (uint *)(lVar2 + 0x4c0 + (ulong)*(ushort *)(lVar2 + 0x416));
      *puVar1 = (uint)(*(byte *)(lVar2 + 0x418) ^ 1) <<
                ((byte)*(undefined2 *)(lVar2 + 0x414) & 0x1f) | *puVar1 & *(uint *)(lVar2 + 0x410);
      if (*(int *)(lVar2 + 0x2f0) != 0) {
        puVar1 = (uint *)(lVar2 + 0x4d0 + (ulong)*(ushort *)(lVar2 + 0x222));
        *puVar1 = (uint)*(byte *)(*(long *)(lVar2 + 0x228) + 1) <<
                  ((byte)*(undefined2 *)(lVar2 + 0x220) & 0x1f) | *puVar1 & *(uint *)(lVar2 + 0x21c)
        ;
        puVar1 = (uint *)(lVar2 + 0x4d0 + (ulong)*(ushort *)(lVar2 + 0x2fa));
        *puVar1 = (uint)(*(byte *)(lVar2 + 0x2fc) ^ 1) <<
                  ((byte)*(undefined2 *)(lVar2 + 0x2f8) & 0x1f) | *puVar1 & *(uint *)(lVar2 + 0x2f4)
        ;
      }
      if (*(int *)(lVar2 + 0xf0) != 0) {
        puVar1 = (uint *)(lVar2 + 0x4e0 + (ulong)*(ushort *)(lVar2 + 0x22));
        *puVar1 = (uint)*(byte *)(*(long *)(lVar2 + 0x28) + 1) <<
                  ((byte)*(undefined2 *)(lVar2 + 0x20) & 0x1f) | *puVar1 & *(uint *)(lVar2 + 0x1c);
        puVar1 = (uint *)(lVar2 + 0x4e0 + (ulong)*(ushort *)(lVar2 + 0xfa));
        *puVar1 = (uint)(*(byte *)(lVar2 + 0xfc) ^ 1) <<
                  ((byte)*(undefined2 *)(lVar2 + 0xf8) & 0x1f) | *puVar1 & *(uint *)(lVar2 + 0xf4);
      }
      if (*(int *)(lVar2 + 0x1f0) != 0) {
        puVar1 = (uint *)(lVar2 + 0x4e0 + (ulong)*(ushort *)(lVar2 + 0x122));
        *puVar1 = (uint)*(byte *)(*(long *)(lVar2 + 0x128) + 1) <<
                  ((byte)*(undefined2 *)(lVar2 + 0x120) & 0x1f) | *puVar1 & *(uint *)(lVar2 + 0x11c)
        ;
      }
    }
    plVar3 = plVar3 + 1;
  } while (plVar3 != (long *)(param_2 + 0x568));
  return 0;
}


// ===== 003fc520 kgmmuFmtInitLevels_GP10X =====

void kgmmuFmtInitLevels_GP10X
               (undefined8 param_1,undefined2 *param_2,uint param_3,int param_4,int param_5)

{
  if (param_4 != 2) {
    nvAssertFailedNoLog("version == GMMU_FMT_VERSION_2",
                        "src/kernel/gpu/mmu/arch/pascal/kern_gmmu_fmt_gp10x.c",0x36);
    return;
  }
  if (5 < param_3) {
    if (param_5 - 0x10U < 2) {
      *param_2 = 0x302f;
      *(undefined2 **)(param_2 + 8) = param_2 + 0xc;
      *(undefined2 **)(param_2 + 0x14) = param_2 + 0x18;
      *(undefined2 **)(param_2 + 0x20) = param_2 + 0x24;
      *(undefined1 *)(param_2 + 1) = 8;
      *(undefined1 *)(param_2 + 2) = 1;
      *(undefined4 *)(param_2 + 4) = 0;
      param_2[0xc] = 0x2e26;
      *(undefined1 *)(param_2 + 0xd) = 8;
      *(undefined1 *)(param_2 + 0xe) = 1;
      *(undefined4 *)(param_2 + 0x10) = 1;
      param_2[0x18] = 0x251d;
      *(undefined1 *)(param_2 + 0x19) = 8;
      *(undefined1 *)(param_2 + 0x1a) = 1;
      *(undefined4 *)(param_2 + 0x1c) = 2;
      *(undefined1 *)(param_2 + 0x26) = 2;
      *(undefined4 *)(param_2 + 0x24) = 0x1101c15;
      *(undefined2 **)(param_2 + 0x2c) = param_2 + 0x30;
      *(undefined4 *)(param_2 + 0x28) = 3;
      *(char *)(param_2 + 0x30) = (char)param_5;
      *(undefined1 *)((long)param_2 + 0x61) = 0x14;
      param_2[0x31] = 0x108;
      *(undefined4 *)(param_2 + 0x34) = 6;
      *(undefined4 *)(param_2 + 0x3c) = 0x108140c;
      *(undefined4 *)(param_2 + 0x40) = 5;
      return;
    }
    nvAssertFailedNoLog("bigPageShift == 16 || bigPageShift == 17",
                        "src/kernel/gpu/mmu/arch/pascal/kern_gmmu_fmt_gp10x.c",0x38);
    return;
  }
  nvAssertFailedNoLog("numLevels >= 6","src/kernel/gpu/mmu/arch/pascal/kern_gmmu_fmt_gp10x.c",0x37);
  return;
}


// ===== 003fc650 kgmmuFmtInitPdeMulti_GP10X =====

void kgmmuFmtInitPdeMulti_GP10X(undefined8 param_1,long param_2,int param_3,undefined8 param_4)

{
  if (param_3 == 2) {
    *(undefined4 *)(param_2 + 0x10) = 2;
    *(undefined8 *)(param_2 + 0x18) = 0xfffffff900000006;
    *(undefined8 *)(param_2 + 0x118) = 0xfffffff900000006;
    *(undefined8 *)(param_2 + 0x178) = 0x1ffffff00;
    *(undefined8 *)(param_2 + 0x78) = 0x1fffffff0;
    *(undefined8 *)(param_2 + 0x180) = 0x800000019;
    *(undefined8 *)(param_2 + 0x80) = 0x40000001d;
    *(undefined8 *)(param_2 + 0x38) = 0x3ffffffffffff0;
    *(undefined8 *)(param_2 + 0x138) = 0x3fffffffffff00;
    *(undefined4 *)(param_2 + 0x20) = 1;
    *(undefined1 *)(param_2 + 0x24) = 5;
    *(undefined8 *)(param_2 + 0x28) = param_4;
    *(undefined4 *)(param_2 + 0x70) = 1;
    *(undefined4 *)(param_2 + 0x88) = 0;
    *(undefined4 *)(param_2 + 0xa8) = 8;
    *(undefined4 *)(param_2 + 0x30) = 1;
    *(undefined8 *)(param_2 + 0x40) = 0x400000032;
    *(undefined4 *)(param_2 + 0x48) = 0;
    *(undefined4 *)(param_2 + 0x68) = 8;
    *(undefined8 *)(param_2 + 0xf0) = 0xfffffff700000008;
    *(undefined4 *)(param_2 + 0xf8) = 3;
    *(undefined1 *)(param_2 + 0xfc) = 0;
    *(undefined4 *)(param_2 + 0x110) = 2;
    *(undefined4 *)(param_2 + 0x120) = 0x80001;
    *(undefined1 *)(param_2 + 0x124) = 5;
    *(undefined8 *)(param_2 + 0x128) = param_4;
    *(undefined4 *)(param_2 + 0x170) = 1;
    *(undefined4 *)(param_2 + 0x188) = 8;
    *(undefined4 *)(param_2 + 0x1a8) = 0xc;
    *(undefined4 *)(param_2 + 0x130) = 1;
    *(undefined8 *)(param_2 + 0x140) = 0x80000002e;
    *(undefined4 *)(param_2 + 0x148) = 8;
    *(undefined4 *)(param_2 + 0x168) = 0xc;
    *(undefined8 *)(param_2 + 0x1f0) = 0xfffffff700000008;
    *(undefined4 *)(param_2 + 0x1f8) = 0x80003;
    *(undefined1 *)(param_2 + 0x1fc) = 0;
    return;
  }
  nvAssertFailedNoLog("version == GMMU_FMT_VERSION_2",
                      "src/kernel/gpu/mmu/arch/pascal/kern_gmmu_fmt_gp10x.c",0x73);
  return;
}


// ===== 003fc7f0 kgmmuFmtInitPde_GP10X =====

void kgmmuFmtInitPde_GP10X(undefined8 param_1,undefined4 *param_2,int param_3,undefined8 param_4)

{
  if (param_3 == 2) {
    *param_2 = 2;
    *(undefined8 *)(param_2 + 2) = 0xfffffff900000006;
    *(undefined8 *)(param_2 + 0x1a) = 0x1ffffff00;
    *(undefined8 *)(param_2 + 0x1c) = 0x800000019;
    *(undefined8 *)(param_2 + 10) = 0x3fffffffffff00;
    *(undefined8 *)(param_2 + 0xc) = 0x80000002e;
    param_2[4] = 1;
    *(undefined1 *)(param_2 + 5) = 5;
    *(undefined8 *)(param_2 + 6) = param_4;
    param_2[0x18] = 1;
    param_2[0x1e] = 0;
    param_2[0x26] = 0xc;
    param_2[8] = 1;
    param_2[0xe] = 0;
    param_2[0x16] = 0xc;
    *(undefined8 *)(param_2 + 0x38) = 0xfffffff700000008;
    param_2[0x3a] = 3;
    *(undefined1 *)(param_2 + 0x3b) = 0;
    return;
  }
  nvAssertFailedNoLog("version == GMMU_FMT_VERSION_2",
                      "src/kernel/gpu/mmu/arch/pascal/kern_gmmu_fmt_gp10x.c",0x8f);
  return;
}


// ===== 003fc8d0 kgmmuFmtInitPte_GP10X =====

void kgmmuFmtInitPte_GP10X
               (undefined8 param_1,undefined8 *param_2,int param_3,undefined8 param_4,char param_5)

{
  if (param_3 != 2) {
    nvAssertFailedNoLog("version == GMMU_FMT_VERSION_2",
                        "src/kernel/gpu/mmu/arch/pascal/kern_gmmu_fmt_gp10x.c",0xa1);
    return;
  }
  *(undefined1 *)(param_2 + 2) = 0;
  *param_2 = 0x100000002;
  param_2[1] = 0xfffffffe;
  param_2[3] = 0xfffffff900000006;
  param_2[0x1e] = 0xfffffff10000000e;
  param_2[0x1f] = 0x800040001;
  param_2[0x20] = 0x3fffffff7;
  param_2[0x22] = 0x6ffffffbf;
  param_2[0x28] = 0x5ffffffdf;
  param_2[0x2a] = 0x4ffffffef;
  param_2[0x2e] = 0x7ffffff7f;
  param_2[0x30] = 0x4001800ffffff;
  *(undefined4 *)(param_2 + 4) = 1;
  *(undefined1 *)((long)param_2 + 0x24) = 5;
  param_2[5] = param_4;
  *(undefined1 *)(param_2 + 0x21) = 0;
  *(undefined4 *)((long)param_2 + 0x10c) = 0x40;
  *(undefined1 *)(param_2 + 0x23) = 0;
  *(undefined4 *)((long)param_2 + 0x13c) = 0x20;
  *(undefined1 *)(param_2 + 0x29) = 0;
  *(undefined4 *)((long)param_2 + 0x14c) = 0x10;
  *(undefined1 *)(param_2 + 0x2b) = 0;
  *(undefined4 *)((long)param_2 + 0x16c) = 0x80;
  *(undefined1 *)(param_2 + 0x2f) = 0;
  *(undefined4 *)((long)param_2 + 0x17c) = 0xff000000;
  *(undefined4 *)(param_2 + 0xe) = 1;
  param_2[0xf] = 0x1ffffff00;
  param_2[0x10] = 0x800000019;
  *(undefined4 *)(param_2 + 0x11) = 0;
  *(undefined4 *)(param_2 + 0x15) = 0xc;
  *(undefined4 *)(param_2 + 0x16) = 1;
  param_2[0x17] = 0x1ffffff00;
  param_2[0x18] = 0x800000019;
  *(undefined4 *)(param_2 + 0x19) = 0;
  *(undefined4 *)(param_2 + 0x1d) = 0xc;
  *(undefined4 *)(param_2 + 6) = 1;
  if (param_5 != '\0') {
    param_2[7] = 0x1ffffff00;
    param_2[8] = 0x800000019;
    *(undefined4 *)(param_2 + 9) = 0;
    *(undefined4 *)(param_2 + 0xd) = 0xc;
    return;
  }
  *(undefined4 *)(param_2 + 9) = 0;
  param_2[7] = 0x3fffffffffff00;
  param_2[8] = 0x80000002e;
  *(undefined4 *)(param_2 + 0xd) = 0xc;
  return;
}


// ===== 003fcad0 kgmmuFmtIsVersionSupported_GP10X =====

bool kgmmuFmtIsVersionSupported_GP10X(undefined8 param_1,int param_2)

{
  return param_2 == 2;
}


// ===== 003fcae0 kgmmuGetPDBAllocSize_GP100 =====

int kgmmuGetPDBAllocSize_GP100(undefined8 param_1,char *param_2)

{
  return (uint)(byte)param_2[2] << ((param_2[1] - *param_2) + 1U & 0x1f);
}


// ===== 003fcb00 kgmmuInstBlkVaLimitGet_GP100 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined8
kgmmuInstBlkVaLimitGet_GP100
          (undefined8 param_1,long *param_2,int param_3,undefined8 param_4,undefined4 *param_5,
          ulong *param_6)

{
  ulong uVar1;
  
  if (param_3 != -1) {
    nvAssertFailedNoLog("subctxId == FIFO_PDB_IDX_BASE",
                        "src/kernel/gpu/mmu/arch/pascal/kern_gmmu_gp100.c",0x62);
  }
  if (param_2 == (long *)0x0) {
    nvAssertFailedNoLog(&DAT_00d6583f,"src/kernel/gpu/mmu/arch/pascal/kern_gmmu_gp100.c",99);
    return 0x1f;
  }
  uVar1 = (**(code **)(*param_2 + 0x60))(param_2);
  *param_6 = uVar1 | 0xfff;
  *param_5 = 0x208;
  return 0;
}


// ===== 003fcba0 kgmmuInstBlkPageDirBaseGet_GP100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kgmmuInstBlkPageDirBaseGet_GP100
          (long param_1,undefined8 param_2,long *param_3,char *param_4,int param_5,
          undefined4 *param_6,uint *param_7,undefined4 *param_8,undefined4 *param_9)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  int *piVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  undefined8 uVar9;
  uint uVar10;
  int local_40;
  
  if (param_5 != -1) {
    nvAssertFailedNoLog("subctxId == FIFO_PDB_IDX_BASE",
                        "src/kernel/gpu/mmu/arch/pascal/kern_gmmu_gp100.c",0x8a);
  }
  if (param_3 == (long *)0x0) {
    nvDbg_Printf("src/kernel/gpu/mmu/arch/pascal/kern_gmmu_gp100.c",0xb3,
                 "kgmmuInstBlkPageDirBaseGet_GP100",4,
                 "NVRM: A channel must have a pVAS if it does not support TSG sub context!\n");
    uVar9 = 0x3b;
  }
  else {
    uVar9 = *(undefined8 *)(param_1 + 0x1b98);
    uVar4 = __nvoc_dynamicCast(param_3,__nvoc_class_def_OBJGVASPACE);
    piVar5 = (int *)gvaspaceGetGmmuFmt_IMPL(uVar4,param_1);
    lVar6 = (**(code **)(*param_3 + 0xa0))(param_3);
    lVar7 = (**(code **)(*param_3 + 200))(param_3,param_1);
    if (lVar7 == 0) {
      nvAssertFailedNoLog("pPDB != NULL","src/kernel/gpu/mmu/arch/pascal/kern_gmmu_gp100.c",0x98);
      uVar9 = 0x40;
    }
    else {
      uVar8 = memdescGetPhysAddr(lVar7,1,0);
      uVar2 = kgmmuGetHwPteApertureFromMemdesc_GM107(uVar9,lVar7);
      *param_6 = 0x200;
      cVar1 = *param_4;
      uVar10 = 0;
      if (piVar5 != (int *)0x0) {
        uVar10 = (uint)(*piVar5 == 2) << 10;
      }
      iVar3 = memdescGetVolatility(lVar7);
      local_40 = (int)(uVar8 >> 0xc);
      *param_7 = local_40 << 0xc | (uint)(lVar6 == 0x10000) << 0xb | uVar2 & 3 |
                 -(uint)(cVar1 != '\0') & 0x30 | uVar10 | iVar3 * 4 & 4U;
      *param_8 = 0x204;
      *param_9 = (int)(uVar8 >> 0x20);
      uVar9 = 0;
    }
  }
  return uVar9;
}


// ===== 003fcd90 kgmmuGetFaultTypeString_GP100 =====

char * kgmmuGetFaultTypeString_GP100(undefined8 param_1,uint param_2)

{
  char *pcVar1;
  
  pcVar1 = "UNRECOGNIZED_FAULT";
  if (param_2 < 0x10) {
    pcVar1 = *(char **)(CSWTCH_18 + (ulong)param_2 * 8);
  }
  return pcVar1;
}


// ===== 003fcdb0 kgmmuFaultCancelIssueInvalidate_GP100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgmmuFaultCancelIssueInvalidate_GP100
                (undefined8 param_1,long param_2,uint *param_3,long param_4,char param_5)

{
  uint uVar1;
  ulong uVar2;
  
  uVar1 = 0x80000023;
  if (param_5 == '\0') {
    uVar1 = (*param_3 & 0x3f) << 9 | (param_3[1] & 0x1f) << 0xf | 0x8000001b;
  }
  *(uint *)(param_4 + 0x10) = uVar1;
  uVar1 = (**(code **)(param_2 + 0x1f8))(param_1,param_2,param_4 + 0x18);
  if (uVar1 == 0) {
    uVar2 = (**(code **)(param_2 + 0x200))(param_1,param_2,param_4);
    if ((int)uVar2 != 0) {
      nvAssertOkFailedNoLog
                (uVar2 & 0xffffffff,"kgmmuCommitTlbInvalidate_HAL(pGpu, pKernelGmmu, pParams)",
                 "src/kernel/gpu/mmu/arch/pascal/kern_gmmu_gp100.c",0x124);
      uVar2 = uVar2 & 0xffffffff;
    }
    return uVar2;
  }
  nvAssertOkFailedNoLog
            (uVar1,"kgmmuCheckPendingInvalidates_HAL(pGpu, pKernelGmmu, &pParams->timeout)",
             "src/kernel/gpu/mmu/arch/pascal/kern_gmmu_gp100.c",0x122);
  return (ulong)uVar1;
}


// ===== 003fce90 kgmmuCheckAndDecideBigPageSize_GP100 =====

undefined8 kgmmuCheckAndDecideBigPageSize_GP100(undefined8 param_1,long param_2)

{
  if ((*(ulong *)(param_2 + 0x588) & 0xfffffffffffeffff) == 0) {
    return 0;
  }
  nvAssertFailedNoLog("bigPageSizeOverride == RM_PAGE_SIZE_64K",
                      "src/kernel/gpu/mmu/arch/pascal/kern_gmmu_gp100.c",0x13d);
  return 0x56;
}


// ===== 003fced0 kgmmuFmtInitPteComptagLine_TU10X =====

void kgmmuFmtInitPteComptagLine_TU10X(undefined8 param_1,long param_2,int param_3)

{
  if (param_3 == 2) {
    *(undefined4 *)(param_2 + 400) = 0x40004;
    *(undefined8 *)(param_2 + 0x188) = 0xff00000f00fffff0;
    return;
  }
  nvAssertFailedNoLog("version == GMMU_FMT_VERSION_2",
                      "src/kernel/gpu/mmu/arch/turing/kern_gmmu_fmt_tu10x.c",0x21);
  return;
}


// ===== 003fcf10 kgmmuFmtInitPeerPteFld_TU10X =====

void kgmmuFmtInitPeerPteFld_TU10X(undefined8 param_1,long param_2,int param_3)

{
  if (param_3 == 2) {
    *(undefined4 *)(param_2 + 0xe8) = 0xc;
    *(undefined8 *)(param_2 + 0xb8) = 0x1ffffff00;
    *(undefined8 *)(param_2 + 0xc0) = 0x800000019;
    *(undefined8 *)(param_2 + 0xd0) = 0xfffff000000000;
    *(undefined4 *)(param_2 + 200) = 0;
    *(undefined8 *)(param_2 + 0xd8) = 0x2400000014;
    *(undefined4 *)(param_2 + 0xe0) = 0;
    *(undefined4 *)(param_2 + 0xb0) = 2;
    return;
  }
  nvAssertFailedNoLog("version == GMMU_FMT_VERSION_2",
                      "src/kernel/gpu/mmu/arch/turing/kern_gmmu_fmt_tu10x.c",0x27);
  return;
}


// ===== 003fcfb0 kgmmuCheckPendingInvalidates_TU102 =====

undefined8 kgmmuCheckPendingInvalidates_TU102(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((param_1 == 0) || (*(char *)(param_1 + 0x44f) != '\0')) {
    return 0x10;
  }
  while( true ) {
    if (*(char *)(param_1 + 0x450) != '\0') {
      return 0x10;
    }
    if (*(char *)(param_1 + 0x451) != '\0') {
      return 0x10;
    }
    if (*(char *)(param_1 + 0x461) != '\0') {
      return 0x10;
    }
    iVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x30b0,0);
    if (-1 < iVar1) break;
    if ((*(char *)(param_1 + 0x44c) == '\0') || (*(char *)(param_1 + 0x450) != '\0')) {
      return 0xf;
    }
    uVar2 = timeoutCheck(param_1 + 0x1af0,param_3,0x4d);
    if ((int)uVar2 != 0) {
      return uVar2;
    }
    osSpinLoop();
    if (*(char *)(param_1 + 0x44f) != '\0') {
      return 0x10;
    }
  }
  return 0;
}


// ===== 003fd0a0 kgmmuCommitTlbInvalidate_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgmmuCommitTlbInvalidate_TU102(long param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  uint uVar2;
  
  if (*(int *)(param_3 + 0xc) != 0) {
    nvAssertFailedNoLog("IS_GFID_PF(pParams->gfid)",
                        "src/kernel/gpu/mmu/arch/turing/kern_gmmu_tu102.c",0x68);
    return 0x1f;
  }
  uVar2 = *(uint *)(param_3 + 0x10);
  if (*(char *)(param_1 + 0x908) == '\0') {
    if ((uVar2 & 2) != 0) goto LAB_003fd106;
  }
  else {
    *(uint *)(param_3 + 0x10) = uVar2 & 0xfffffffd;
  }
  (**(code **)(param_2 + 0x208))(param_1,param_2,param_3);
  uVar2 = *(uint *)(param_3 + 0x10);
LAB_003fd106:
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x30b0,uVar2,0);
  uVar1 = (**(code **)(param_2 + 0x1f8))(param_1,param_2,param_3 + 0x18);
  return uVar1;
}


// ===== 003fd170 kgmmuSetPdbToInvalidate_TU102 =====

void kgmmuSetPdbToInvalidate_TU102(long param_1,undefined8 param_2,ulong *param_3)

{
  if (*(int *)((long)param_3 + 0xc) == 0) {
    regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x30a0,
                (int)(*param_3 >> 0xc) << 4 | (int)param_3[1] * 2 & 2U,0);
    regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x30a4,
                (uint)(*param_3 >> 0x28) & 0xfffff,0);
    return;
  }
  nvAssertFailedNoLog("IS_GFID_PF(pParams->gfid)","src/kernel/gpu/mmu/arch/turing/kern_gmmu_tu102.c"
                      ,0x8d);
  return;
}


// ===== 003fd220 kgmmuSetTlbInvalidateMembarWarParameters_TU102 =====

undefined8
kgmmuSetTlbInvalidateMembarWarParameters_TU102(undefined8 param_1,undefined8 param_2,long param_3)

{
  *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) & 0xfffffe7f | 0xc0;
  return 0;
}


// ===== 003fd240 kgmmuSetTlbInvalidateMembarParameters_TU102 =====

void kgmmuSetTlbInvalidateMembarParameters_TU102(undefined8 param_1,undefined8 param_2,long param_3)

{
  *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) & 0xfffffe7f | 0xc0;
  return;
}


// ===== 003fd260 kgmmuGetFaultRegisterMappings_TU102 =====

undefined8
kgmmuGetFaultRegisterMappings_TU102
          (long param_1,undefined8 param_2,uint param_3,long *param_4,long *param_5,
          undefined8 *param_6,long *param_7,long *param_8,long *param_9,int *param_10,long *param_11
          )

{
  undefined8 uVar1;
  long lVar2;
  int iVar3;
  long *plVar4;
  ulong uVar5;
  
  uVar1 = *(undefined8 *)(param_1 + 0x1c20);
  plVar4 = (long *)gpuGetDeviceMapping_IMPL(param_1,0,0);
  lVar2 = *plVar4;
  uVar5 = intrGetVectorFromEngineId_IMPL(param_1,uVar1,0x3b,0);
  if (param_3 < 2) {
    *param_4 = (ulong)(param_3 * 0x20 + 0x3008 + *(int *)(param_1 + 0x3a64)) + lVar2;
    *param_5 = (ulong)(param_3 * 0x20 + 0x300c + *(int *)(param_1 + 0x3a64)) + lVar2;
    *param_6 = 0;
    iVar3 = ((uint)(uVar5 >> 5) & 0x7ffffff) * 4;
    *param_7 = (ulong)(uint)(iVar3 + 0x1000 + *(int *)(param_1 + 0x3a64)) + lVar2;
    *param_8 = (ulong)(uint)(iVar3 + 0x1200 + *(int *)(param_1 + 0x3a64)) + lVar2;
    *param_9 = (ulong)(uint)(iVar3 + 0x1400 + *(int *)(param_1 + 0x3a64)) + lVar2;
    if (param_3 == 1) {
      *param_10 = 1 << ((byte)uVar5 & 0x1f);
      *param_11 = (ulong)(*(int *)(param_1 + 0x3a64) + 0x3070) + lVar2;
    }
    return 0;
  }
  nvAssertFailedNoLog("(index < NUM_FAULT_BUFFERS)",
                      "src/kernel/gpu/mmu/arch/turing/kern_gmmu_tu102.c",0xf1);
  return 0x1f;
}


// ===== 003fd3b0 kgmmuTestAccessCounterWriteNak_TU102 =====

uint kgmmuTestAccessCounterWriteNak_TU102(long param_1)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x311c,0);
  return uVar1 >> 0x18 & 1;
}


// ===== 003fd3e0 kgmmuServiceReplayableFault_TU102 =====

undefined1  [16] kgmmuServiceReplayableFault_TU102(long param_1,long param_2,ulong param_3)

{
  undefined1 auVar1 [16];
  ulong uVar2;
  undefined8 uVar3;
  undefined8 extraout_RDX;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined8 *local_20 [2];
  
  local_20[0] = (undefined8 *)0x0;
  if ((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) {
    auVar4 = CliGetEventNotificationList
                       (*(undefined4 *)(param_2 + 0x628),*(undefined4 *)(param_2 + 0x62c),0,local_20
                       );
    param_3 = auVar4._8_8_;
    uVar2 = auVar4._0_8_;
    if (auVar4._0_4_ == 0) {
      uVar3 = 0;
      if (local_20[0] != (undefined8 *)0x0) {
        uVar2 = notifyEvents(param_1,*local_20[0],1,0,0,0);
        uVar3 = 1;
        if ((int)uVar2 != 0) {
          nvAssertFailedNoLog("rmStatus == NV_OK","src/kernel/gpu/mmu/arch/turing/kern_gmmu_tu102.c"
                              ,0x134,0x3fd426);
          auVar4._0_8_ = uVar2 & 0xffffffff;
          auVar4._8_8_ = extraout_RDX;
          return auVar4;
        }
      }
      auVar5._8_8_ = uVar3;
      auVar5._0_8_ = uVar2;
      return auVar5;
    }
  }
  auVar1._8_8_ = 0;
  auVar1._0_8_ = param_3;
  return auVar1 << 0x40;
}


// ===== 003fd4a0 kgmmuReadMmuFaultStatus_TU102 =====

void kgmmuReadMmuFaultStatus_TU102(long param_1,undefined8 param_2,int param_3)

{
  if (param_3 != 0) {
    nvAssertFailedNoLog("IS_GFID_PF(gfid)","src/kernel/gpu/mmu/arch/turing/kern_gmmu_tu102.c",0x142)
    ;
  }
  regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x3094,0);
  return;
}


// ===== 003fd500 kgmmuWriteMmuFaultStatus_TU102 =====

void kgmmuWriteMmuFaultStatus_TU102(long param_1,undefined8 param_2,undefined4 param_3)

{
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x3094,param_3,0);
  return;
}


// ===== 003fd530 kgmmuReadMmuFaultBufferSize_TU102 =====

void kgmmuReadMmuFaultBufferSize_TU102(long param_1,undefined8 param_2,int param_3,int param_4)

{
  if (param_4 != 0) {
    nvAssertFailedNoLog("IS_GFID_PF(gfid)","src/kernel/gpu/mmu/arch/turing/kern_gmmu_tu102.c",0x15d)
    ;
  }
  regRead032(param_1 + 0x3a18,0,0,param_3 * 0x20 + 0x3010 + *(int *)(param_1 + 0x3a64),0);
  return;
}


// ===== 003fd5a0 kgmmuReadFaultBufferGetPtr_TU102 =====

undefined8
kgmmuReadFaultBufferGetPtr_TU102(long param_1,undefined8 param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  
  if (param_3 < 2) {
    uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x3008 + param_3 * 0x20);
    *param_4 = uVar1 & 0xfffff;
    return 0;
  }
  nvAssertFailedNoLog("(index < NUM_FAULT_BUFFERS)",
                      "src/kernel/gpu/mmu/arch/turing/kern_gmmu_tu102.c",0x16e);
  return 0x1f;
}


// ===== 003fd610 kgmmuWriteFaultBufferGetPtr_TU102 =====

undefined8
kgmmuWriteFaultBufferGetPtr_TU102
          (long param_1,undefined8 param_2,uint param_3,uint param_4,undefined8 param_5)

{
  uint uVar1;
  
  if (param_3 < 2) {
    uVar1 = param_4 & 0x3fffffff;
    if (param_3 == 1) {
      regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x3028,param_4);
      uVar1 = param_4 | 0xc0000000;
    }
    regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x3008 + param_3 * 0x20,uVar1,
                param_5);
    return 0;
  }
  nvAssertFailedNoLog("(index < NUM_FAULT_BUFFERS)",
                      "src/kernel/gpu/mmu/arch/turing/kern_gmmu_tu102.c",0x180);
  return 0x1f;
}


// ===== 003fd6e0 kgmmuReadFaultBufferPutPtr_TU102 =====

undefined8
kgmmuReadFaultBufferPutPtr_TU102(long param_1,undefined8 param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  
  if (param_3 < 2) {
    uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x300c + param_3 * 0x20);
    *param_4 = uVar1 & 0xfffff;
    return 0;
  }
  nvAssertFailedNoLog("(index < NUM_FAULT_BUFFERS)",
                      "src/kernel/gpu/mmu/arch/turing/kern_gmmu_tu102.c",0x1af);
  return 0x1f;
}


// ===== 003fd750 kgmmuIsNonReplayableFaultPending_TU102 =====

uint kgmmuIsNonReplayableFaultPending_TU102(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x1010,param_3);
  return uVar1 & 0x10;
}


// ===== 003fd780 kgmmuClearNonReplayableFaultIntr_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgmmuClearNonReplayableFaultIntr_TU102(long param_1,undefined8 param_2,undefined8 param_3)

{
  (**(code **)(*(long *)(param_1 + 0x1c20) + 0x1d0))
            (param_1,*(long *)(param_1 + 0x1c20),0x84,param_3);
  return;
}


// ===== 003fd7a0 kgmmuClearReplayableFaultIntr_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgmmuClearReplayableFaultIntr_TU102(long param_1,undefined8 param_2,undefined8 param_3)

{
  (**(code **)(*(long *)(param_1 + 0x1c20) + 0x1d0))
            (param_1,*(long *)(param_1 + 0x1c20),0x40,param_3);
  return;
}


// ===== 003fd7c0 kgmmuPrintFaultInfo_TU102 =====

void kgmmuPrintFaultInfo_TU102(void)

{
  kgmmuPrintFaultInfo_GV100();
  return;
}


// ===== 003fd7d0 kgmmuIsFaultEngineBar1_TU102 =====

bool kgmmuIsFaultEngineBar1_TU102(undefined8 param_1,int param_2)

{
  return param_2 == 0x80;
}


// ===== 003fd7e0 kgmmuIsFaultEngineBar2_TU102 =====

bool kgmmuIsFaultEngineBar2_TU102(undefined8 param_1,int param_2)

{
  return param_2 == 0xc0;
}


// ===== 003fd7f0 kgmmuSetAndGetDefaultFaultBufferSize_TU102 =====

int kgmmuSetAndGetDefaultFaultBufferSize_TU102
              (long param_1,undefined8 param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  
  if (param_4 != 0) {
    nvAssertFailedNoLog("IS_GFID_PF(gfid)","src/kernel/gpu/mmu/arch/turing/kern_gmmu_tu102.c",0x24c)
    ;
  }
  iVar2 = param_3 * 0x20 + 0x3010;
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + iVar2,0);
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + iVar2,uVar1 | 0x40000000,0);
  uVar1 = regRead032(param_1 + 0x3a18,0,0,iVar2 + *(int *)(param_1 + 0x3a64),0);
  return (uVar1 & 0xfffff) << 5;
}


// ===== 003fd8b0 kgmmuWriteMmuFaultBufferSize_TU102 =====

void kgmmuWriteMmuFaultBufferSize_TU102
               (long param_1,long param_2,uint param_3,int param_4,uint param_5)

{
  if (param_5 != 0) {
    nvAssertFailedNoLog("IS_GFID_PF(gfid)","src/kernel/gpu/mmu/arch/turing/kern_gmmu_tu102.c",0x261)
    ;
  }
  regWrite032(param_1 + 0x3a18,0,0,param_3 * 0x20 + 0x3010 + *(int *)(param_1 + 0x3a64),param_4,0);
  if (-1 < param_4) {
    *(undefined4 *)(param_2 + 0x5f0 + (ulong)param_3 * 0x30 + (ulong)param_5 * 0x188) = 0;
  }
  return;
}


// ===== 003fd960 kgmmuWriteMmuFaultBufferHiLo_TU102 =====

void kgmmuWriteMmuFaultBufferHiLo_TU102
               (long param_1,undefined8 param_2,int param_3,undefined4 param_4,ulong param_5,
               int param_6)

{
  if (param_6 != 0) {
    nvAssertFailedNoLog("IS_GFID_PF(gfid)","src/kernel/gpu/mmu/arch/turing/kern_gmmu_tu102.c",0x279)
    ;
    param_5 = param_5 & 0xffffffff;
  }
  regWrite032(param_1 + 0x3a18,0,0,param_3 * 0x20 + 0x3004 + *(int *)(param_1 + 0x3a64),param_5,0);
  regWrite032(param_1 + 0x3a18,0,0,param_3 * 0x20 + 0x3000 + *(int *)(param_1 + 0x3a64),param_4,0);
  return;
}


// ===== 003fda10 kgmmuReadMmuFaultInstHiLo_TU102 =====

void kgmmuReadMmuFaultInstHiLo_TU102
               (long param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_3 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pHiVal != NULL","src/kernel/gpu/mmu/arch/turing/kern_gmmu_tu102.c",0x289);
  }
  if (param_4 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pLoVal != NULL","src/kernel/gpu/mmu/arch/turing/kern_gmmu_tu102.c",0x28a);
  }
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x3088,0);
  *param_4 = uVar1;
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x308c,0);
  *param_3 = uVar1;
  return;
}


// ===== 003fdad0 kgmmuReadMmuFaultAddrHiLo_TU102 =====

void kgmmuReadMmuFaultAddrHiLo_TU102
               (long param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_3 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pHiVal != NULL","src/kernel/gpu/mmu/arch/turing/kern_gmmu_tu102.c",0x298);
  }
  if (param_4 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pLoVal != NULL","src/kernel/gpu/mmu/arch/turing/kern_gmmu_tu102.c",0x299);
  }
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x3080,0);
  *param_4 = uVar1;
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x3084,0);
  *param_3 = uVar1;
  return;
}


// ===== 003fdb90 kgmmuReadMmuFaultInfo_TU102 =====

void kgmmuReadMmuFaultInfo_TU102(long param_1)

{
  regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x3090,0);
  return;
}


// ===== 003fdbc0 kgmmuGetEccCounts_TU102 =====

int kgmmuGetEccCounts_TU102(long param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  param_1 = param_1 + 0x3a18;
  uVar1 = regRead032(param_1,0,0,&DAT_00100e78,0);
  uVar2 = regRead032(param_1,0,0,&DAT_00100e8c,0);
  uVar3 = regRead032(param_1,0,0,&DAT_00100ea0,0);
  return (uVar3 >> 0x10) + (uVar1 >> 0x10) + (uVar2 >> 0x10);
}


// ===== 003fdc30 _kgmmuCopyFaultPktInShadowBuf_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
_kgmmuCopyFaultPktInShadowBuf_GV100
          (undefined8 param_1,long param_2,uint param_3,long param_4,uint param_5,int param_6,
          uint param_7,char param_8,undefined8 param_9)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  uint uStack_64;
  int local_3c [3];
  
  local_3c[0] = 0;
  if (param_8 == '\0') {
    lVar1 = *(long *)(param_4 + 0x70 + (ulong)param_3 * 8);
    uVar3 = (**(code **)(param_2 + 0x3c0))(param_1,param_2,0,(ulong)param_3);
    uStack_64 = uVar3;
    if (lVar1 == 0) {
      return 0x3d;
    }
    do {
      while( true ) {
        uVar4 = (**(code **)(param_2 + 0x3b0))
                          (param_1,param_2,param_4,param_3,param_5,uStack_64,param_7,param_9,
                           local_3c);
        if ((int)uVar4 != 0) {
          return uVar4;
        }
        if (local_3c[0] == 0) {
          if (param_3 != 1) {
            nvAssertFailedNoLog("type == REPLAYABLE_FAULT_BUFFER",
                                "src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x334);
            return 0x40;
          }
          if (uVar3 == uStack_64) {
            return 0x10006;
          }
          goto LAB_003fddb4;
        }
        param_5 = param_5 + 1;
        param_6 = param_6 + -1;
        uStack_64 = (uStack_64 + 1) % param_7;
        if (param_5 != param_7) break;
        if (param_6 == 0) goto LAB_003fddb4;
        param_5 = 0;
      }
    } while (param_6 != 0);
  }
  else {
    lVar1 = *(long *)(param_4 + 0x68);
    if (lVar1 == 0) {
      return 0x3d;
    }
    uStack_64 = 0;
    do {
      while( true ) {
        uVar4 = (**(code **)(param_2 + 0x3a8))
                          (param_1,param_2,param_4 + (ulong)(-param_3 & 0x30),param_5);
        iVar2 = circularQueuePush_IMPL(lVar1,uVar4,1);
        if (iVar2 != 1) {
          return 0x51;
        }
        param_5 = param_5 + 1;
        param_6 = param_6 + -1;
        local_3c[0] = 1;
        if (param_7 != param_5) break;
        if (param_6 == 0) goto LAB_003fdce8;
        param_5 = 0;
      }
    } while (param_6 != 0);
LAB_003fdce8:
    local_3c[0] = 1;
    if (param_8 != '\0') {
      return 0;
    }
  }
LAB_003fddb4:
  LOCK();
  UNLOCK();
  (**(code **)(param_2 + 0x3c8))(param_1,param_2,0,param_3,uStack_64);
  return 0;
}


// ===== 003fde60 kgmmuFmtFamiliesInit_GV100 =====

void kgmmuFmtFamiliesInit_GV100(undefined8 param_1,long param_2)

{
  uint *puVar1;
  long lVar2;
  long *plVar3;
  
  plVar3 = (long *)(param_2 + 0x550);
  do {
    lVar2 = *plVar3;
    if (lVar2 != 0) {
      puVar1 = (uint *)(lVar2 + 0x4f0 + (ulong)*(ushort *)(lVar2 + 0x31e));
      *puVar1 = (uint)*(byte *)(lVar2 + 800) << ((byte)*(undefined2 *)(lVar2 + 0x31c) & 0x1f) |
                *puVar1 & *(uint *)(lVar2 + 0x318);
      puVar1 = (uint *)(lVar2 + 0x4f0 + (ulong)*(ushort *)(lVar2 + 0x416));
      *puVar1 = (uint)(*(byte *)(lVar2 + 0x418) ^ 1) <<
                ((byte)*(undefined2 *)(lVar2 + 0x414) & 0x1f) | *puVar1 & *(uint *)(lVar2 + 0x410);
      puVar1 = (uint *)(lVar2 + 0x4f0 + (ulong)*(ushort *)(lVar2 + 0x456));
      *puVar1 = (uint)(*(byte *)(lVar2 + 0x458) ^ 1) <<
                ((byte)*(undefined2 *)(lVar2 + 0x454) & 0x1f) | *puVar1 & *(uint *)(lVar2 + 0x450);
    }
    plVar3 = plVar3 + 1;
  } while (plVar3 != (long *)(param_2 + 0x568));
  kgmmuFmtFamiliesInit_GM200(param_1,param_2);
  return;
}


// ===== 003fdf30 kgmmuChangeReplayableFaultOwnership_GV100 =====

undefined8 kgmmuChangeReplayableFaultOwnership_GV100(long param_1,long param_2,char param_3)

{
  uint uVar1;
  
  if ((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) {
    uVar1 = *(uint *)(param_2 + 0x548) | 8;
    if (param_3 == '\0') {
      uVar1 = *(uint *)(param_2 + 0x548) & 0xfffffff7;
    }
    *(uint *)(param_2 + 0x548) = uVar1;
  }
  return 0;
}


// ===== 003fdf70 kgmmuClientShadowFaultBufferAlloc_GV100 =====

undefined8 kgmmuClientShadowFaultBufferAlloc_GV100(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(param_1 + 0x4913) == '\0')) {
    return 0;
  }
  if (*(char *)(param_2 + 0x511) == '\0') {
    uVar1 = kgmmuClientShadowFaultBufferAllocate_IMPL();
    return uVar1;
  }
  nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x82,
               "kgmmuClientShadowFaultBufferAlloc_GV100",4,
               "NVRM: Fault-Buffer is disabled. ShadowBuffer cannot be created\n");
  nvAssertFailedNoLog(&DAT_00d65d18,"src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x83);
  return 0x40;
}


// ===== 003fdff0 kgmmuClientShadowFaultBufferFree_GV100 =====

undefined8 kgmmuClientShadowFaultBufferFree_GV100(long param_1)

{
  undefined8 uVar1;
  
  if ((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(param_1 + 0x4913) == '\0')) {
    return 0;
  }
  uVar1 = kgmmuClientShadowFaultBufferDestroy_IMPL();
  return uVar1;
}


// ===== 003fe020 kgmmuInstBlkAtsGet_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
kgmmuInstBlkAtsGet_GV100(undefined8 param_1,long *param_2,int param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint local_2c [3];
  
  local_2c[0] = 0;
  if (param_3 == -1) {
    if (param_2 == (long *)0x0) {
      nvAssertFailedNoLog("pVAS != NULL","src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0xd3);
      return 0x40;
    }
    iVar1 = (**(code **)(*param_2 + 0xc0))(param_2,local_2c);
    if (iVar1 == 0) {
      if (0xfffff < local_2c[0]) {
        nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0xc6,
                     "kgmmuInstBlkAtsGet_GV100",4,"NVRM: Invalid PASID %d (max width %d bits)\n",
                     local_2c[0],0x14);
        return 0x59;
      }
      *param_4 = 0x21c;
      iVar1 = (**(code **)(*param_2 + 0xb8))(param_2);
      *param_5 = local_2c[0] & 0xfffff | iVar1 << 0x1f;
      return 0;
    }
    nvAssertFailedNoLog("NV_OK == vaspaceGetPasid(pVAS, &pasid)",
                        "src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0xc2);
LAB_003fe1b8:
    uVar3 = 0x25;
  }
  else {
    if (param_2 == (long *)0x0) {
      uVar2 = 0;
    }
    else {
      iVar1 = (**(code **)(*param_2 + 0xc0))(param_2,local_2c);
      if (iVar1 != 0) {
        nvAssertFailedNoLog("NV_OK == vaspaceGetPasid(pVAS, &pasid)",
                            "src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0xe1);
        goto LAB_003fe1b8;
      }
      if (0xfffff < local_2c[0]) {
        nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0xe6,
                     "kgmmuInstBlkAtsGet_GV100",4,"NVRM: Invalid PASID %d (max width %d bits)\n",
                     local_2c[0],0x14);
        return 0x59;
      }
      iVar1 = (**(code **)(*param_2 + 0xb8))(param_2);
      uVar2 = local_2c[0] & 0xfffff | iVar1 << 0x1f;
    }
    *param_5 = uVar2;
    uVar3 = 0;
    *param_4 = param_3 * 0x80 + 0x1540U >> 3;
  }
  return uVar3;
}


// ===== 003fe250 kgmmuInstBlkVaLimitGet_GV100 =====

undefined8
kgmmuInstBlkVaLimitGet_GV100
          (undefined8 param_1,undefined8 param_2,int param_3,undefined8 param_4,undefined4 *param_5,
          undefined8 *param_6)

{
  undefined8 uVar1;
  
  if (param_3 != -1) {
    *param_5 = 0;
    *param_6 = 0;
    return 0;
  }
  uVar1 = kgmmuInstBlkVaLimitGet_GP100();
  return uVar1;
}


// ===== 003fe280 kgmmuInstBlkPageDirBaseGet_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kgmmuInstBlkPageDirBaseGet_GV100
          (undefined8 param_1,undefined8 param_2,long *param_3,char *param_4,int param_5,
          uint *param_6,uint *param_7,uint *param_8,undefined4 *param_9)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  int local_60;
  
  if (param_5 == -1) {
    uVar7 = kgmmuInstBlkPageDirBaseGet_GP100();
    return uVar7;
  }
  lVar5 = gpuGetKernelFifoShared_IMPL();
  if (param_4[2] == '\0') {
    if ((param_3 == (long *)0x0) ||
       (lVar5 = (**(code **)(*param_3 + 200))(param_3,param_1), lVar5 == 0)) {
      uVar4 = 1;
      uVar8 = 1;
      goto LAB_003fe356;
    }
  }
  else {
    lVar5 = *(long *)(lVar5 + 0x4d8);
    if (lVar5 == 0) {
      nvAssertFailedNoLog("(pPDB != NULL)","src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x150);
      return 0x40;
    }
  }
  uVar6 = memdescGetPhysAddr(lVar5,1,0);
  uVar2 = kgmmuGetHwPteApertureFromMemdesc_GM107(param_2,lVar5);
  cVar1 = *param_4;
  sVar3 = memdescGetVolatility(lVar5);
  local_60 = (int)(uVar6 >> 0xc);
  uVar8 = (undefined4)(uVar6 >> 0x20);
  uVar4 = CONCAT22((short)((uint)(local_60 << 0xc) >> 0x10),
                   sVar3 * 4 & 4U | uVar2 & 3 | (ushort)(local_60 << 0xc) |
                   -(ushort)(cVar1 != '\0') & 0x30) | 0xc00;
LAB_003fe356:
  *param_7 = uVar4;
  *param_9 = uVar8;
  *param_6 = param_5 * 0x80 + 0x1500U >> 3;
  *param_8 = param_5 * 0x80 + 0x1520U >> 3;
  return 0;
}


// ===== 003fe410 kgmmuReportFaultBufferOverflow_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kgmmuReportFaultBufferOverflow_GV100(long param_1,long param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint local_38;
  uint local_34;
  undefined8 *local_30;
  
  uVar2 = (**(code **)(param_2 + 0x2f8))(param_1,param_2,0);
  local_30 = (undefined8 *)0x0;
  (**(code **)(param_2 + 0x2d8))(param_1,param_2,0,&local_38,0);
  local_38 = local_38 & 0xfffff;
  (**(code **)(param_2 + 0x2e8))(param_1,param_2,0,&local_34,0);
  local_34 = local_34 & 0xfffff;
  uVar4 = (**(code **)(param_2 + 0x2f0))(param_1,param_2,0,0);
  cVar1 = (**(code **)(param_2 + 0x308))(param_1,param_2,0);
  if (cVar1 != '\0') {
    nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x1b9,
                 "kgmmuReportFaultBufferOverflow_GV100",1,
                 "NVRM: MMU Fault: GPU %d: NON_REPLAYABLE_INTR is high when OVERFLOW is detected\n",
                 *(undefined4 *)(param_1 + 0x7a4));
  }
  if ((uVar2 & 0xc000) == 0) {
    nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x1c7,
                 "kgmmuReportFaultBufferOverflow_GV100",4,
                 "NVRM: MMU Fault: GPU %d: Buffer overflow detected due to incorrect SIZE\n",
                 *(undefined4 *)(param_1 + 0x7a4));
    nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x1cb,
                 "kgmmuReportFaultBufferOverflow_GV100",4,
                 "NVRM: MMU Fault: GPU %d: Buffer SIZE is expected to handle max faults possible in system\n"
                 ,*(undefined4 *)(param_1 + 0x7a4));
  }
  else {
    nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x1c1,
                 "kgmmuReportFaultBufferOverflow_GV100",4,
                 "NVRM: MMU Fault: GPU %d: Buffer overflow detected due to GET > SIZE\n",
                 *(undefined4 *)(param_1 + 0x7a4));
  }
  nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x1d0,
               "kgmmuReportFaultBufferOverflow_GV100",4,
               "NVRM: MMU Fault: GPU %d: STATUS - 0x%x GET - 0x%x, PUT - 0x%x  SIZE - 0x%x\n",
               *(undefined4 *)(param_1 + 0x7a4),uVar2,local_38,local_34,uVar4);
  iVar3 = CliGetEventNotificationList
                    (*(undefined4 *)(param_2 + 0x628),*(undefined4 *)(param_2 + 0x62c),0,&local_30);
  if (iVar3 == 0) {
    uVar4 = 0;
    if (local_30 != (undefined8 *)0x0) {
      uVar4 = notifyEvents(param_1,*local_30,2,0,0,0,1);
    }
  }
  else {
    uVar4 = 0;
  }
  uVar2 = (**(code **)(param_2 + 0x2f8))(param_1,param_2,0);
  (**(code **)(param_2 + 0x300))(param_1,param_2,uVar2 & 0xffffdfff);
  (**(code **)(param_1 + 0x100))(param_1);
  return uVar4;
}


// ===== 003fe670 kgmmuGetGraphicsEngineId_GV100 =====

undefined8 kgmmuGetGraphicsEngineId_GV100(void)

{
  return 0x40;
}


// ===== 003fe680 kgmmuEnableNvlinkComputePeerAddressing_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgmmuEnableNvlinkComputePeerAddressing_GV100(long param_1)

{
  undefined4 uVar1;
  char cVar2;
  long lVar3;
  
  lVar3 = 0;
  do {
    uVar1 = (&g_gmmuFmtVersions)[lVar3];
    cVar2 = (**(code **)(param_1 + 600))(param_1,uVar1);
    if (cVar2 != '\0') {
      (**(code **)(param_1 + 0x238))(param_1,*(long *)(param_1 + 0x550 + lVar3 * 8) + 0x310,uVar1);
    }
    lVar3 = lVar3 + 1;
  } while (lVar3 != 3);
  return 0;
}


// ===== 003fe6f0 kgmmuPrintFaultInfo_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgmmuPrintFaultInfo_GV100(long param_1,undefined8 param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  uint local_40;
  int local_3c [3];
  
  lVar6 = gpuGetKernelFifoShared_IMPL();
  nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x22b,"kgmmuPrintFaultInfo_GV100",4
               ,"NVRM: MMU Fault: inst:0x%x dev:0x%x subdev:0x%x\n",*(undefined4 *)(param_1 + 0x7a4)
               ,*(undefined4 *)(param_1 + 0x7b4),*(undefined4 *)(param_1 + 0x7b8));
  uVar7 = (**(code **)(lVar6 + 0x358))(param_1,lVar6,param_4[6]);
  uVar1 = param_4[6];
  uVar8 = (**(code **)(*(long *)(param_1 + 0x1b98) + 0x2a8))(*(long *)(param_1 + 0x1b98),param_4[2])
  ;
  uVar2 = param_4[2];
  uVar3 = *param_4;
  uVar4 = param_4[1];
  uVar9 = (**(code **)(lVar6 + 0x348))(param_1,lVar6,param_4);
  uVar10 = (**(code **)(lVar6 + 0x330))(param_1,lVar6,param_3);
  nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x22f,"kgmmuPrintFaultInfo_GV100",4
               ,
               "NVRM: MMU Fault: ENGINE 0x%x (%s %s) faulted @ 0x%x_%08x. Fault is of type 0x%x (%s). Access type is 0x%x (%s)"
               ,param_3,uVar10,uVar9,uVar4,uVar3,uVar2,uVar8,uVar1,uVar7);
  iVar5 = (**(code **)(lVar6 + 0x218))(param_1,lVar6,4,param_3,0,&local_40);
  if ((iVar5 == 0) && (local_40 >> 8 == 0xd334df)) {
    if (*(char *)(param_4 + 4) != '\0') {
      nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x250,
                   "kgmmuPrintFaultInfo_GV100",4," on GPC %d",param_4[5]);
    }
    iVar5 = (**(code **)(lVar6 + 0x218))(param_1,lVar6,0,local_40,4,local_3c);
    if (iVar5 == 0) {
      nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x259,
                   "kgmmuPrintFaultInfo_GV100",4," on VEID %d",param_3 - local_3c[0]);
    }
  }
  nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x263,"kgmmuPrintFaultInfo_GV100",4
               ,&DAT_00d65fe6);
  return;
}


// ===== 003fe930 kgmmuCopyMmuFaults_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgmmuCopyMmuFaults_GV100
              (long param_1,long param_2,undefined8 param_3,int *param_4,uint param_5,char param_6)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  ulong uVar9;
  long lVar10;
  char *pcVar11;
  uint uVar12;
  uint uVar13;
  byte bVar14;
  uint uVar15;
  long lVar16;
  uint uVar17;
  bool bVar18;
  uint local_a0;
  int local_94;
  byte local_6a;
  uint local_5c;
  uint local_54;
  undefined1 local_50 [32];
  
  uVar8 = gpuGetKernelFifoShared_IMPL();
  local_54 = 0;
  lVar2 = *(long *)(param_1 + 0x1c20);
  if (1 < param_5) {
    nvAssertFailedNoLog("type == REPLAYABLE_FAULT_BUFFER || type == NON_REPLAYABLE_FAULT_BUFFER",
                        "src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x380);
    return 0x1f;
  }
  *param_4 = 0;
  if (lVar2 == 0) {
    return 0;
  }
  iVar6 = intrGetIntrEn_IMPL();
  if (iVar6 == 0) {
    return 0;
  }
  if (*(char *)(param_2 + 0x511) != '\0') {
    return 0;
  }
  if (*(long *)(param_2 + 0x738) == 0) {
    return 0;
  }
  cVar4 = gpuIsCCFeatureEnabled_IMPL(param_1);
  if ((cVar4 == '\0') || (*(char *)(param_1 + 0x4a78) == '\0')) {
    if (param_5 == 1) {
      return 0;
    }
  }
  else if ((param_5 == 1) && (*(char *)(param_2 + 0x512) == '\0')) {
    (**(code **)(param_2 + 0x360))(param_1,param_2,param_3);
    return 0;
  }
  portSyncSpinlockAcquire(*(undefined8 *)(param_2 + 0x738));
  uVar9 = (ulong)param_5;
  lVar2 = *(long *)(param_2 + 0x630);
  lVar3 = *(long *)(param_2 + 0x638 + uVar9 * 8);
  lVar16 = uVar9 * 0x30 + param_2;
  uVar12 = *(uint *)(lVar16 + 0x5f4);
  if (uVar12 == 0) {
    nvAssertFailedNoLog("pHwFaultBuffer->faultBufferSize",
                        "src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x3a9);
    uVar12 = *(uint *)(lVar16 + 0x5f4);
  }
  lVar16 = uVar9 * 0x30 + param_2;
  if ((*(long *)(lVar16 + 0x5e0) == 0) && (*(long *)(lVar16 + 0x5e8) == 0)) {
    nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x3ae,"kgmmuCopyMmuFaults_GV100",
                 4,"NVRM: GPU %d HW\'s fault buffer doesn\'t have kernel mappings\n",
                 *(undefined4 *)(param_1 + 0x7a4));
  }
  else {
    if (lVar2 != 0) {
      lVar2 = param_2 + 0x5c8;
      uVar12 = uVar12 >> 5;
      if (*(char *)(param_1 + 0x4913) != '\0') {
        (**(code **)(param_2 + 0x2d8))
                  (param_1,param_2,param_5,param_2 + 0x5f0 + (ulong)(-param_5 & 0x30),param_3);
      }
      uVar17 = *(uint *)(param_2 + 0x5f0 + uVar9 * 0x30);
      if (param_6 == '\x01') {
        (**(code **)(param_2 + 0x2e8))(param_1,param_2,param_5,&local_54,param_3);
      }
      if (param_5 == 0) {
        (**(code **)(param_2 + 0x358))(param_1,param_2,param_3);
      }
      else {
        (**(code **)(param_2 + 0x360))(param_1,param_2,param_3);
      }
      if (uVar12 == 0) {
LAB_003feba4:
        (**(code **)(param_2 + 0x2e0))
                  (param_1,param_2,param_5,*(undefined4 *)(param_2 + 0x5f0 + uVar9 * 0x30),param_3);
      }
      else {
        local_6a = 0;
        local_5c = 1;
        local_94 = 0;
        lVar16 = lVar2 + (ulong)(-param_5 & 0x30);
        iVar6 = 0;
        local_a0 = uVar17;
        while (param_6 != '\x01') {
          lVar10 = (**(code **)(param_2 + 0x3a8))(param_1,param_2,lVar16,uVar17);
          uVar15 = *(uint *)(lVar10 + 0x1c);
joined_r0x003fed01:
          if (-1 < (int)uVar15) goto LAB_003feb91;
LAB_003fed10:
          LOCK();
          UNLOCK();
          lVar10 = (**(code **)(param_2 + 0x3a8))(param_1,param_2,lVar16,uVar17);
          bVar18 = false;
          uVar13 = *(uint *)(lVar10 + 0x18) & 0x1ff;
          if (*(uint *)(param_2 + 0x67c8) <= uVar13) {
            bVar18 = uVar13 <= *(uint *)(param_2 + 0x67cc);
          }
          cVar4 = kfifoIsMmuFaultEngineIdPbdma_IMPL(param_1,uVar8);
          if (((uVar15 & 0x40000000) == 0) || (lVar3 == 0)) {
            cVar4 = gpuIsCCFeatureEnabled_IMPL(param_1);
            if ((cVar4 != '\0') && (*(char *)(param_1 + 0x4a78) != '\0')) {
              uVar13 = 1;
              goto LAB_003fee1f;
            }
            if (param_5 != 0) goto LAB_003fee9f;
            uVar13 = 1;
LAB_003fee36:
            bVar14 = (byte)uVar13;
            if (local_6a == bVar14) {
              iVar7 = iVar6 + 1;
              bVar18 = iVar6 != 0;
              iVar6 = 1;
              if (bVar18) {
                iVar6 = iVar7;
              }
            }
            else if (iVar6 == 0) {
              iVar6 = 1;
              local_6a = bVar14;
            }
            else {
              iVar7 = _kgmmuCopyFaultPktInShadowBuf_GV100
                                (param_1,param_2,0,lVar2,local_a0,iVar6,uVar12,local_6a,param_3);
              if (iVar7 != 0) {
                pcVar11 = "Client";
                uVar8 = 0x3fa;
                if (local_6a != 0) {
                  pcVar11 = "RM";
                }
                uVar1 = *(undefined4 *)(param_1 + 0x7a4);
                goto LAB_003ff149;
              }
              local_a0 = (local_a0 + iVar6) % uVar12;
              iVar6 = 1;
              local_6a = bVar14;
            }
            uVar17 = uVar17 + 1;
            local_94 = local_94 + uVar13;
            if (uVar12 == uVar17) {
              *(long *)(param_2 + 0x748) = *(long *)(param_2 + 0x748) + 1;
              uVar17 = 0;
            }
          }
          else {
            cVar5 = gpuIsCCFeatureEnabled_IMPL(param_1);
            uVar13 = (uint)(cVar4 == '\0' && !bVar18);
            if ((cVar5 != '\0') && (*(char *)(param_1 + 0x4a78) != '\0')) {
LAB_003fee1f:
              uVar13 = uVar13 & (uVar15 >> 7 & 1 ^ 1);
            }
            if (param_5 == 0) goto LAB_003fee36;
            if ((char)uVar13 != '\0') {
LAB_003fee9f:
              nvAssertFailedNoLog("!bRmServiceable",
                                  "src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x411);
              return 0x40;
            }
            uVar17 = uVar17 + 1;
            local_6a = local_6a & iVar6 != 0;
            iVar6 = iVar6 + 1;
            if (uVar12 == uVar17) {
              uVar17 = 0;
            }
          }
          if (uVar12 <= local_5c) goto LAB_003fefa9;
          local_5c = local_5c + 1;
        }
        if (local_54 != uVar17) {
          timeoutSet(param_1 + 0x1af0,local_50,0,0);
          do {
            lVar10 = (**(code **)(param_2 + 0x3a8))(param_1,param_2,lVar16,uVar17);
            uVar15 = *(uint *)(lVar10 + 0x1c);
            iVar7 = timeoutCheck(param_1 + 0x1af0,local_50,0x2ac);
            if (iVar7 != 0) {
              nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x2af,
                           "_kgmmuFaultEntryRmServiceable_GV100",4,
                           "NVRM: Timed out while waiting for valid bit.\n");
              (**(code **)(param_1 + 0x100))(param_1);
              goto joined_r0x003fed01;
            }
          } while (-1 < (int)uVar15);
          goto LAB_003fed10;
        }
LAB_003feb91:
        local_5c = local_5c - 1;
        if (local_5c == 0) goto LAB_003feba4;
LAB_003fefa9:
        if (iVar6 != 0) {
          iVar7 = _kgmmuCopyFaultPktInShadowBuf_GV100
                            (param_1,param_2,param_5,lVar2,local_a0,iVar6,uVar12,local_6a,param_3);
          if (iVar7 == 0x10006) goto LAB_003febd4;
          if (iVar7 != 0) {
            pcVar11 = "Client";
            if (local_6a != 0) {
              pcVar11 = "RM";
            }
            uVar8 = 0x454;
            uVar1 = *(undefined4 *)(param_1 + 0x7a4);
LAB_003ff149:
            nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",uVar8,
                         "kgmmuCopyMmuFaults_GV100",4,
                         "NVRM: Failed to copy faults into GPU %d\'s %s shadow buffer\n",uVar1,
                         pcVar11);
            (**(code **)(param_1 + 0x100))(param_1);
            goto LAB_003febd7;
          }
        }
        iVar6 = *(int *)(param_2 + 0x5f0 + uVar9 * 0x30);
        if (uVar12 < local_5c + iVar6) {
          (**(code **)(param_2 + 0x3a0))(param_1,param_2,lVar16,iVar6,uVar12 - iVar6);
          local_5c = local_5c + (iVar6 - uVar12);
          iVar6 = 0;
        }
        (**(code **)(param_2 + 0x3a0))(param_1,param_2,lVar16,iVar6,local_5c);
        LOCK();
        UNLOCK();
        LOCK();
        *(undefined4 *)(param_2 + 0x740) = 1;
        UNLOCK();
        LOCK();
        UNLOCK();
        (**(code **)(param_2 + 0x2e0))(param_1,param_2,param_5,uVar17,param_3);
        *param_4 = local_94;
        *(uint *)(param_2 + 0x5f0 + uVar9 * 0x30) = uVar17;
      }
LAB_003febd4:
      iVar7 = 0;
      goto LAB_003febd7;
    }
    nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x3b7,"kgmmuCopyMmuFaults_GV100",
                 4,"NVRM: GPU %d RM\'s shadow buffer should be setup\n",
                 *(undefined4 *)(param_1 + 0x7a4));
  }
  iVar7 = 0x40;
LAB_003febd7:
  portSyncSpinlockRelease(*(undefined8 *)(param_2 + 0x738));
  return iVar7;
}


// ===== 003ff210 kgmmuFaultBufferClearPackets_GV100 =====

void kgmmuFaultBufferClearPackets_GV100
               (undefined8 param_1,undefined8 param_2,long param_3,uint param_4,uint param_5)

{
  ulong uVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  
  if (*(long *)(param_3 + 0x18) == 0) {
    if (param_5 != 0) {
      uVar1 = (ulong)(param_4 & 0x7f);
      uVar4 = (ulong)(param_4 >> 7);
      uVar2 = 0x80 - (param_4 & 0x7f);
      uVar3 = (ulong)uVar2;
      if (param_5 < uVar2) {
        uVar3 = (ulong)param_5;
      }
      do {
        param_5 = param_5 - (int)uVar3;
        portMemSet(uVar1 * 0x20 + *(long *)(uVar4 * 0x10 + *(long *)(param_3 + 0x20)),0,uVar3 << 5);
        uVar4 = (ulong)((int)uVar4 + 1);
        uVar3 = 0x80;
        if (param_5 < 0x81) {
          uVar3 = (ulong)param_5;
        }
        uVar1 = 0;
      } while (param_5 != 0);
    }
    return;
  }
  portMemSet(*(long *)(param_3 + 0x18) + (ulong)param_4 * 0x20,0,(ulong)param_5 << 5);
  return;
}


// ===== 003ff2d0 kgmmuFaultBufferGetFault_GV100 =====

long kgmmuFaultBufferGetFault_GV100(undefined8 param_1,undefined8 param_2,long param_3,uint param_4)

{
  if (*(long *)(param_3 + 0x18) != 0) {
    return *(long *)(param_3 + 0x18) + (ulong)param_4 * 0x20;
  }
  return (ulong)(param_4 & 0x7f) * 0x20 +
         *(long *)((ulong)(param_4 >> 7) * 0x10 + *(long *)(param_3 + 0x20));
}


// ===== 003ff310 kgmmuCopyFaultPacketToClientShadowBuffer_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

char kgmmuCopyFaultPacketToClientShadowBuffer_GV100
               (undefined8 param_1,long param_2,long param_3,ulong param_4,undefined4 param_5)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 uVar4;
  int *in_stack_00000018;
  
  lVar1 = *(long *)(param_3 + 0x70 + (param_4 & 0xffffffff) * 8);
  uVar2 = *(undefined8 *)(lVar1 + 0x10);
  uVar4 = (**(code **)(param_2 + 0x3a8))
                    (param_1,param_2,param_3 + (param_4 & 0xffffffff) * 0x30,param_5);
  iVar3 = circularQueuePushNonManaged_IMPL(uVar2,lVar1 + 0x18,uVar4,1);
  *in_stack_00000018 = iVar3;
  return (iVar3 == 0) * '\x02';
}


// ===== 003ff370 kgmmuInitCeMmuFaultIdRange_GV100 =====

undefined8 kgmmuInitCeMmuFaultIdRange_GV100(undefined8 param_1,long param_2)

{
  *(undefined8 *)(param_2 + 0x67c8) = 0x170000000f;
  nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x50c,
               "kgmmuInitCeMmuFaultIdRange_GV100",1,"NVRM: CE MMU Fault ID range [0x%x - 0x%x]\n",
               0xf,0x17);
  return 0;
}


// ===== 003ff3c0 kgmmuFaultBufferInit_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgmmuFaultBufferInit_GV100(long param_1,long param_2)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  
  if (((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) &&
     (*(char *)(param_2 + 0x511) == '\0')) {
    uVar3 = (**(code **)(param_2 + 0x418))(param_1,param_2,0,0);
    iVar4 = kgmmuFaultBufferAlloc_IMPL(param_1,param_2,0,uVar3);
    if (iVar4 != 0) {
      return iVar4;
    }
    cVar2 = portIsInitialized();
    if (cVar2 == '\0') {
      nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x52a,
                   "_kgmmuAllocShadowFaultBuffer_GV100",4,"NVRM: NvPort needed but not initaiized\n"
                  );
      nvAssertFailedNoLog(&DAT_00d65d18,"src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x52b);
    }
    if (*(char *)(param_2 + 0x511) == '\0') {
      if (*(int *)(param_2 + 0x5f4) == 0) {
        nvAssertFailedNoLog("pFaultBuffer->faultBufferSize != 0",
                            "src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x535);
        iVar4 = 0x1f;
      }
      else {
        lVar5 = portMemAllocNonPaged(0xc0);
        if (lVar5 == 0) {
          nvAssertFailedNoLog("gmmuShadowFaultBuf != NULL",
                              "src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x539);
          iVar4 = 0x51;
        }
        else {
          uVar1 = *(uint *)(param_2 + 0x5f4);
          uVar6 = portMemAllocatorGetGlobalNonPaged();
          iVar4 = circularQueueInit_IMPL(lVar5,uVar6,uVar1 >> 5,0x20);
          if (iVar4 == 0) {
            uVar6 = portMemAllocatorGetGlobalNonPaged();
            lVar7 = portSyncSpinlockCreate(uVar6);
            *(long *)(param_2 + 0x738) = lVar7;
            if (lVar7 != 0) {
              *(long *)(param_2 + 0x630) = lVar5;
              return 0;
            }
            iVar4 = 0x1a;
          }
          portMemFree(lVar5);
        }
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x530,
                   "_kgmmuAllocShadowFaultBuffer_GV100",4,
                   "NVRM: Fault-Buffer is disabled. ShadowBuffer cannot be created\n");
      nvAssertFailedNoLog(&DAT_00d65d18,"src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x531);
      iVar4 = 0x40;
    }
    kgmmuFaultBufferFree_IMPL(param_1,param_2,0);
    return iVar4;
  }
  return 0;
}


// ===== 003ff610 kgmmuFaultBufferLoad_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgmmuFaultBufferLoad_GV100(long param_1,long param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) &&
     (*(char *)(param_2 + 0x511) == '\0')) {
    if (*(int *)(param_1 + 0x4b34) != 4) {
      iVar1 = (**(code **)(param_2 + 0x3d8))();
      if (iVar1 != 0) {
        return iVar1;
      }
      (**(code **)(param_2 + 0x3c8))(param_1,param_2,param_4,param_3,0);
    }
    iVar1 = (**(code **)(param_2 + 0x408))(param_1,param_2,param_3,0,param_4);
    if (iVar1 != 0) {
      (**(code **)(param_2 + 0x3e0))(param_1,param_2,param_3,param_4);
    }
    return iVar1;
  }
  return 0;
}


// ===== 003ff6f0 kgmmuEnableFaultBuffer_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kgmmuEnableFaultBuffer_GV100(long param_1,long param_2,uint param_3,char param_4,uint param_5)

{
  ulong uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  
  if (((*(char *)(param_1 + 0x908) == '\0') ||
      ((*(char *)(param_1 + 0x4913) != '\0' && (*(char *)(param_1 + 0x491e) == '\0')))) &&
     (*(char *)(param_2 + 0x511) == '\0')) {
    if (param_3 < 2) {
      uVar1 = *(ulong *)(param_2 + 0x5c8 + (ulong)param_3 * 0x30 + (ulong)param_5 * 0x188);
      (**(code **)(param_2 + 0x440))(param_1,param_2,param_3,uVar1,uVar1 >> 0x20,param_5);
      (**(code **)(param_2 + 0x418))(param_1,param_2,param_3,param_5);
      uVar3 = (**(code **)(param_2 + 0x2f0))(param_1,param_2,param_3,param_5);
      uVar2 = uVar3 | 0xa0000000;
      if (param_3 != 0) {
        uVar2 = uVar3 & 0xdfffffff | 0x80000000;
      }
      (**(code **)(param_2 + 0x438))(param_1,param_2,param_3,uVar2,param_5);
      if (param_4 == '\0') {
        (**(code **)(param_2 + 0x448))(param_1,param_2,param_3);
        (**(code **)(param_2 + 0x458))(param_1,param_2,param_3);
      }
      uVar4 = 0;
    }
    else {
      nvAssertFailedNoLog("(index < NUM_FAULT_BUFFERS)",
                          "src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x5b5);
      uVar4 = 0x1f;
    }
    return uVar4;
  }
  return 0;
}


// ===== 003ff850 kgmmuDisableFaultBuffer_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgmmuDisableFaultBuffer_GV100
              (long param_1,long param_2,uint param_3,char param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  char *pcVar4;
  undefined1 local_50 [32];
  
  if (1 < param_3) {
    nvAssertFailedNoLog("(index < NUM_FAULT_BUFFERS)",
                        "src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x5eb);
    return 0x1f;
  }
  if ((*(char *)(param_2 + 0x511) != '\0') ||
     ((*(char *)(param_1 + 0x908) != '\0' && (*(char *)(param_1 + 0x491e) != '\0')))) {
    return 0;
  }
  iVar1 = gpuSanityCheckRegisterAccess_IMPL(param_1,0,0);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = 0;
  if (param_4 == '\0') {
    timeoutSet(param_1 + 0x1af0,local_50,0,0);
    do {
      uVar3 = (**(code **)(param_2 + 0x2f8))(param_1,param_2,param_5);
      if ((uVar3 & 0x40000000) == 0) goto LAB_003ff8c3;
      iVar1 = timeoutCheck(param_1 + 0x1af0,local_50,0x605);
    } while (iVar1 != 0x65);
    pcVar4 = "REPLAYABLE_FAULT_BUFFER";
    if (param_3 != 1) {
      pcVar4 = "NON_REPLAYABLE_FAULT_BUFFER";
    }
    nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x608,
                 "kgmmuDisableFaultBuffer_GV100",4,"NVRM: HW couldn\'t flush %s buffer.\n",pcVar4);
  }
LAB_003ff8c3:
  uVar2 = (**(code **)(param_2 + 0x2f0))(param_1,param_2,param_3,param_5);
  (**(code **)(param_2 + 0x438))(param_1,param_2,param_3,uVar2 & 0x7fffffff,param_5);
  return iVar1;
}


// ===== 003ffa20 kgmmuFaultBufferDestroy_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgmmuFaultBufferDestroy_GV100(long param_1,long param_2)

{
  int iVar1;
  
  if (((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) &&
     (*(char *)(param_2 + 0x511) == '\0')) {
    iVar1 = (**(code **)(param_2 + 0x318))(param_1,param_2,0);
    if (iVar1 == 0) {
      if (*(long *)(param_2 + 0x630) != 0) {
        circularQueueDestroy_IMPL();
        portMemFree(*(undefined8 *)(param_2 + 0x630));
        *(undefined8 *)(param_2 + 0x630) = 0;
      }
      if (*(long *)(param_2 + 0x738) != 0) {
        portSyncSpinlockDestroy();
        *(undefined8 *)(param_2 + 0x738) = 0;
      }
      kgmmuFaultBufferFree_IMPL(param_1,param_2,0);
      return 0;
    }
    return iVar1;
  }
  return 0;
}


// ===== 003ffb10 kgmmuFaultBufferUnload_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kgmmuFaultBufferUnload_GV100(long param_1,long param_2,undefined4 param_3,undefined4 param_4)

{
  if (((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) &&
     (*(char *)(param_2 + 0x511) == '\0')) {
    (**(code **)(param_2 + 0x410))();
    if (*(int *)(param_1 + 0x4b34) != 1) {
      (**(code **)(param_2 + 0x3e0))(param_1,param_2,param_3,param_4);
    }
    return 0;
  }
  return 0;
}


// ===== 003ffb90 kgmmuSignExtendFaultAddress_GV100 =====

void kgmmuSignExtendFaultAddress_GV100(long param_1,long param_2,long *param_3)

{
  uint uVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  undefined8 uVar6;
  
  uVar3 = osGetCpuVaAddrShift();
  uVar4 = 0;
  for (uVar2 = *(ulong *)(param_2 + 0x598); (uVar2 & 1) == 0;
      uVar2 = uVar2 >> 1 | 0x8000000000000000) {
    uVar4 = uVar4 + 1;
  }
  uVar1 = *(uint *)(param_1 + 0x884);
  if (*(ulong *)(param_2 + 0x598) == 0) {
    uVar4 = 0x40;
  }
  if (uVar4 < uVar3) {
    if (uVar1 < 4) {
      if (1 < uVar1) {
        *param_3 = (*param_3 << 0xf) >> 0xf;
        return;
      }
      if (uVar1 == 0) {
        *param_3 = (*param_3 << 0x10) >> 0x10;
      }
    }
    else if (uVar1 == 4) {
      uVar6 = 0x683;
      goto LAB_003ffc4a;
    }
  }
  else if (uVar1 < 4) {
    if (uVar1 != 1) {
      bVar5 = 0x40 - (char)uVar3;
      *param_3 = (*param_3 << (bVar5 & 0x3f)) >> (bVar5 & 0x3f);
      return;
    }
  }
  else if (uVar1 == 4) {
    uVar6 = 0x66f;
LAB_003ffc4a:
    nvAssertFailedNoLog("Invalid oor address mode type.",
                        "src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",uVar6);
    return;
  }
  return;
}


// ===== 003ffc90 kgmmuGetFaultType_GV100 =====

undefined8 kgmmuGetFaultType_GV100(undefined8 param_1,undefined8 param_2,uint param_3,int *param_4)

{
  if (param_4 == (int *)0x0) {
    nvAssertFailedNoLog("pMmuFaultType != NULL","src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",
                        0x69a);
    return 0x3d;
  }
  if (param_3 == 8) {
    *param_4 = 8;
  }
  else if (param_3 < 9) {
    if (param_3 == 4) {
      *param_4 = 4;
    }
    else if (param_3 < 5) {
      if (param_3 == 2) {
        *param_4 = 2;
      }
      else if (param_3 == 3) {
        *param_4 = 3;
      }
      else {
        if (param_3 == 0) {
          *param_4 = 0;
          return 0;
        }
        *param_4 = 1;
      }
    }
    else {
      if (param_3 != 6) {
        *param_4 = (param_3 == 7) + 5 + (uint)(param_3 == 7);
        return 0;
      }
      *param_4 = 6;
    }
  }
  else if (param_3 == 0xc) {
    *param_4 = 0xc;
  }
  else if (param_3 < 0xd) {
    if (param_3 != 10) {
      *param_4 = (param_3 == 0xb) + 9 + (uint)(param_3 == 0xb);
      return 0;
    }
    *param_4 = 10;
  }
  else if (param_3 == 0xe) {
    *param_4 = 0xe;
  }
  else if (param_3 == 0xf) {
    *param_4 = 0xf;
  }
  else {
    if (param_3 != 0xd) {
      return 0x1f;
    }
    *param_4 = 0xd;
  }
  return 0;
}


// ===== 003ffe20 kgmmuIsFaultEnginePhysical_GV100 =====

bool kgmmuIsFaultEnginePhysical_GV100(undefined8 param_1,int param_2)

{
  return param_2 == 0x1f;
}


// ===== 003ffe30 kgmmuParseFaultPacket_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgmmuParseFaultPacket_GV100(undefined8 param_1,long param_2,uint *param_3,long *param_4)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  
  *param_4 = ((ulong)param_3[1] * 0x100000 + (ulong)(*param_3 >> 0xc)) * 0x1000;
  uVar2 = *param_3;
  *(undefined4 *)((long)param_4 + 0xc) = 0;
  *(uint *)(param_4 + 1) = uVar2 >> 8 & 3;
  param_4[2] = ((ulong)param_3[3] * 0x100000 + (ulong)(param_3[2] >> 0xc)) * 0x1000;
  (**(code **)(param_2 + 0x460))(param_1,param_2,param_4 + 2);
  param_4[3] = *(long *)(param_3 + 4);
  iVar6 = (**(code **)(param_2 + 0x468))(param_1,param_2,param_3[7] & 0x1f,param_4 + 4);
  if (iVar6 == 0) {
    *(uint *)((long)param_4 + 0x24) = *(ushort *)((long)param_3 + 0x1e) & 0xf;
    *(uint *)(param_4 + 5) = param_3[6] & 0x1ff;
    *(uint *)((long)param_4 + 0x2c) = param_3[7] >> 8 & 0x7f;
    *(uint *)(param_4 + 6) = param_3[7] >> 0x14 & 1;
    *(uint *)((long)param_4 + 0x34) = *(byte *)((long)param_3 + 0x1f) & 0x1f;
    bVar1 = *(byte *)(param_4 + 7);
    bVar5 = (byte)(param_3[7] >> 0x18);
    bVar4 = bVar5 >> 7;
    *(byte *)(param_4 + 7) = bVar1 & 0xfe | bVar4;
    bVar3 = ((byte)(param_3[7] >> 0x1d) & 1) * '\x02';
    *(byte *)(param_4 + 7) = bVar1 & 0xfc | bVar4 | bVar3;
    bVar5 = bVar5 >> 7;
    bVar4 = ((byte)param_3[7] >> 7) << 2;
    *(byte *)(param_4 + 7) = bVar1 & 0xf8 | bVar5 | bVar3 | bVar4;
    *(byte *)(param_4 + 7) =
         bVar1 & 0xf0 | bVar5 | bVar3 | bVar4 | (byte)((param_3[7] >> 0x1e & 1) << 3);
    return 0;
  }
  nvAssertFailedNoLog("rmStatus == NV_OK","src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x72a);
  return iVar6;
}


// ===== 003fffb0 kgmmuHandleNonReplayableFaultPacket_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgmmuHandleNonReplayableFaultPacket_GV100(long param_1,long param_2,undefined8 param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  undefined1 local_b8 [16];
  undefined8 local_a8;
  int local_98;
  undefined4 uStack_90;
  int local_88;
  undefined4 local_84;
  undefined8 local_70 [2];
  undefined1 local_60 [4];
  undefined4 local_5c;
  undefined8 local_58 [8];
  ulong uVar6;
  
  uVar5 = 0;
  do {
    uVar2 = (int)uVar5 + 0x20;
    uVar6 = (ulong)uVar2;
    *(undefined8 *)((long)local_70 + uVar5) = 0;
    *(undefined8 *)((long)local_70 + uVar5 + 8) = 0;
    *(undefined8 *)((long)local_58 + (uVar5 - 8)) = 0;
    *(undefined8 *)((long)local_58 + uVar5) = 0;
    uVar5 = uVar6;
  } while (uVar2 < 0x40);
  *(undefined8 *)((long)local_70 + uVar6) = 0;
  *(undefined8 *)((long)local_70 + uVar6 + 8) = 0;
  *(undefined8 *)((long)local_58 + (uVar6 - 8)) = 0;
  iVar3 = (**(code **)(param_2 + 0x398))(param_1,param_2,param_3,local_b8);
  iVar4 = 0x25;
  if (iVar3 == 0) {
    local_70[0] = local_a8;
    local_60[0] = local_88 == 0;
    local_5c = local_84;
    (**(code **)(param_2 + 0x370))(param_1,param_2,uStack_90,local_70);
    iVar4 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,local_b8,local_70);
    if (iVar4 != 0) {
      nvAssertFailedNoLog("rmStatus == NV_OK","src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",
                          0x76a);
    }
    if (local_98 == 0xe) {
      cVar1 = (**(code **)(param_1 + 0x350))(param_1);
      if (cVar1 != '\0') {
        iVar3 = (**(code **)(param_1 + 0x3d0))(param_1,10,0);
        if (iVar3 != 0) {
          nvAssertOkFailedNoLog
                    (iVar3,
                     "gpuUpdateErrorContainmentState_HAL(pGpu, NV_ERROR_CONT_ERR_ID_E13_MMU_POISON, loc, NULL)"
                     ,"src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x776);
          iVar4 = iVar3;
        }
      }
    }
  }
  return iVar4;
}


// ===== 00400190 kgmmuNotifyNonReplayableFault_GV100 =====

ulong kgmmuNotifyNonReplayableFault_GV100(undefined8 param_1,long param_2,char param_3)

{
  ulong uVar1;
  undefined8 *local_30 [2];
  
  local_30[0] = (undefined8 *)0x0;
  uVar1 = CliGetEventNotificationList
                    (*(undefined4 *)(param_2 + 0x628),*(undefined4 *)(param_2 + 0x62c),0,local_30);
  if ((int)uVar1 == 0) {
    if ((local_30[0] != (undefined8 *)0x0) &&
       ((*(long *)(param_2 + 0x638) != 0 || (param_3 != '\0')))) {
      uVar1 = notifyEvents(param_1,*local_30[0],0,0,0,0,1);
      if ((int)uVar1 != 0) {
        nvAssertFailedNoLog("rmStatus == NV_OK","src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",
                            0x79f,0x4001c9);
        uVar1 = uVar1 & 0xffffffff;
      }
    }
    return uVar1;
  }
  return 0;
}


// ===== 00400250 kgmmuServiceNonReplayableFault_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgmmuServiceNonReplayableFault_GV100(undefined8 param_1,long param_2)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  undefined1 local_48 [32];
  
  lVar1 = *(long *)(param_2 + 0x630);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pShadowFaultBuf != NULL","src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",
                        0x7b3);
    return 0x3d;
  }
  uVar4 = 0;
  do {
    cVar2 = circularQueueIsEmpty_IMPL(lVar1);
    if (cVar2 != '\0') {
      uVar3 = (**(code **)(param_2 + 0x4c8))(param_1,param_2,uVar4);
      return uVar3;
    }
    uVar4 = 1;
    portMemSet(local_48,0,0x20);
    circularQueuePopAndCopy_IMPL(lVar1,local_48);
    uVar3 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,local_48);
  } while ((int)uVar3 == 0);
  return uVar3;
}


// ===== 0040033b kgmmuServiceMmuFault_GV100.cold =====

void kgmmuServiceMmuFault_GV100_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  undefined8 unaff_R15;
  
  *(undefined8 *)(unaff_RBP + -8) = unaff_R15;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00400370 kgmmuServiceMmuFault_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int kgmmuServiceMmuFault_GV100(long param_1,long param_2,long param_3,long param_4)

{
  undefined4 uVar1;
  undefined8 uVar2;
  long *plVar3;
  code *pcVar4;
  char cVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  long lVar11;
  long lVar12;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 uStack_90;
  undefined4 local_5c;
  long local_58;
  long local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar11 = gpuGetKernelFifoShared_IMPL();
  local_58 = 0;
  iVar8 = (**(code **)(lVar11 + 0x1d0))(param_1,lVar11,param_3,&local_58);
  if ((iVar8 != 0) || (local_58 == 0)) {
    nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x7ec,
                 "kgmmuServiceMmuFault_GV100",4,"NVRM: Could not get chid from inst addr\n");
    return iVar8;
  }
  if (*(char *)(param_1 + 0x4913) == '\0') {
    nvAssertFailed(&DAT_00d65d18,"generated/g_kern_gmmu_nvoc.h",0xb9e);
    if (local_58 == 0) {
      uVar6 = 0xffffffff;
    }
    else {
      uVar6 = *(int *)(local_58 + 0x2b0) << 0x18 | *(uint *)(local_58 + 0x2b4);
    }
    nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x87f,
                 "kgmmuServiceMmuFault_GV100",4,
                 "NVRM: Could not service MMU fault for channel 0x%08x\n",uVar6);
    return 0x56;
  }
  uVar6 = *(int *)(local_58 + 0x42c) - 1;
  if (uVar6 < 8) {
    portMemSet(&local_48,0,1);
    lVar12 = gpuGetRpc(param_1);
    if (lVar12 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x7fc);
      iVar8 = 0x1a;
    }
    else {
      if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) {
        if (local_58 == 0) {
kgmmuServiceMmuFault_GV100_cold:
                    /* WARNING: Does not return */
          pcVar4 = (code *)invalidInstructionException();
          (*pcVar4)();
        }
        plVar3 = *(long **)(*(long *)(local_58 + 0x140) + 0x48);
        iVar8 = rpcDmaControl_wrapper
                          (param_1,lVar12,*(undefined4 *)(*plVar3 + 0x48),(int)plVar3[2],0x900105,
                           &local_48,1);
      }
      else {
        if (local_58 == 0) goto kgmmuServiceMmuFault_GV100_cold;
        plVar3 = *(long **)(*(long *)(local_58 + 0x140) + 0x48);
        iVar8 = (**(code **)(param_1 + 0x3b90))
                          (param_1 + 0x3b58,*(undefined4 *)(*plVar3 + 0x48),(int)plVar3[2],0x900105,
                           &local_48,1);
      }
      if (iVar8 == 0) {
        if ((char)local_48 != '\0') {
          nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x811,
                       "kgmmuServiceMmuFault_GV100",1,"NVRM: bIsMmuDebugModeEnabled: %s\n",
                       &DAT_00d664d1);
          kchannelFillMmuExceptionInfo_IMPL(local_58,param_4);
          iVar8 = 0;
          goto LAB_004005f2;
        }
        goto LAB_00400401;
      }
    }
    nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x806,
                 "kgmmuServiceMmuFault_GV100",4,
                 "NVRM: RM control call to read MMU debug mode failed, rmStatus 0x%x\n",iVar8);
  }
LAB_00400401:
  nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x811,"kgmmuServiceMmuFault_GV100",
               1,"NVRM: bIsMmuDebugModeEnabled: %s\n","FALSE");
  local_48 = 0;
  local_40 = 0;
  if (local_58 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  lVar12 = *(long *)(*(long *)(local_58 + 0x158) + 0xe8);
  uVar2 = **(undefined8 **)(*(long *)(local_58 + 0x140) + 0x48);
  uVar7 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  if (lVar12 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  iVar8 = subdeviceGetByInstance_IMPL
                    (uVar2,*(undefined4 *)(*(long *)(*(long *)(lVar12 + 0x110) + 0x48) + 0x10),uVar7
                     ,&local_50);
  if (iVar8 != 0) {
    return iVar8;
  }
  if (local_58 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  plVar3 = *(long **)(*(long *)(local_58 + 0x140) + 0x48);
  uVar7 = (undefined4)plVar3[2];
  uVar1 = *(undefined4 *)(*plVar3 + 0x48);
  cVar5 = kfifoIsMmuFaultEngineIdPbdma_IMPL(param_1,lVar11,*(undefined4 *)(param_3 + 0x28));
  if (cVar5 == '\0') {
    iVar8 = (**(code **)(lVar11 + 0x218))
                      (param_1,lVar11,4,*(undefined4 *)(param_3 + 0x28),2,&local_5c);
    if (iVar8 != 0) {
      nvAssertFailedNoLog("rmStatus == NV_OK","src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",
                          0x834);
    }
  }
  else {
    local_5c = 0x32;
  }
  uVar9 = gpuGetNv2080EngineType_IMPL(local_5c);
  local_40 = CONCAT44(local_40._4_4_,2);
  local_48 = CONCAT44(*(undefined4 *)(local_50 + 0x334),uVar9);
  iVar8 = krcErrorSetNotifier_IMPL
                    (param_1,*(undefined8 *)(param_1 + 0x1c18),local_58,0x1f,local_5c,1);
  if (iVar8 != 0) {
    nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x843,
                 "kgmmuServiceMmuFault_GV100",4,
                 "NVRM: Failed to set error notifier, rmStatus 0x%x\n",iVar8);
  }
  uStack_90 = 0x40055f;
  lVar11 = gpuGetRpc(param_1);
  if (lVar11 == 0) {
    iVar8 = 0x1a;
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x84f);
LAB_004005ae:
    nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x859,
                 "kgmmuServiceMmuFault_GV100",4,
                 "NVRM: RM control call to reset channel failed, rmStatus 0x%x\n",iVar8);
    uStack_90 = extraout_RDX_00;
  }
  else {
    if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) {
      iVar8 = rpcDmaControl_wrapper(param_1,lVar11,uVar1,uVar7,0x906f0102,&local_48,0x10);
    }
    else {
      iVar8 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,uVar1,uVar7,0x906f0102,&local_48,0x10);
      uStack_90 = extraout_RDX;
    }
    if (iVar8 != 0) goto LAB_004005ae;
  }
  kchannelFillMmuExceptionInfo_IMPL(local_58,param_4,uStack_90);
  if (7 < uVar6) {
    return iVar8;
  }
LAB_004005f2:
  if (*(char *)(param_4 + 0x10) != '\0') {
    iVar10 = kgrctxFromKernelChannel_IMPL(local_58,&local_48);
    if (iVar10 == 0) {
      if (iVar8 == 0) {
        uVar7 = *(undefined4 *)(param_3 + 0x24);
        uVar2 = *(undefined8 *)(param_3 + 0x10);
        uVar1 = *(undefined4 *)(param_3 + 0x20);
        uVar9 = (**(code **)(param_2 + 0x4d8))(param_2,param_3);
        kgrctxRecordMmuFault_IMPL(param_1,local_48,uVar9,uVar2,uVar1,uVar7);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar10,"kgrctxFromKernelChannel(pKernelChannel, &pKernelGraphicsContext)",
                 "src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x86b);
      if (iVar8 == 0) {
        iVar8 = iVar10;
      }
    }
  }
  return iVar8;
}


// ===== 00400990 kgmmuGetFaultInfoFromFaultPckt_GV100 =====

uint kgmmuGetFaultInfoFromFaultPckt_GV100(undefined8 param_1,long param_2)

{
  byte bVar1;
  
  if (param_2 != 0) {
    bVar1 = *(byte *)(param_2 + 0x38);
    return (uint)bVar1 << 0x1f |
           (bVar1 >> 2 & 1) << 7 |
           (bVar1 >> 1 & 1) << 0x1d |
           (*(uint *)(param_2 + 0x34) & 0x1f) << 0x18 |
           (*(uint *)(param_2 + 0x2c) & 0x7f) << 8 | (*(uint *)(param_2 + 0x24) & 0xf) << 0x10 |
           *(uint *)(param_2 + 0x20) & 0x1f | (*(uint *)(param_2 + 0x30) & 1) << 0x14;
  }
  return 0;
}


// ===== 00400a10 kgmmuServicePriFaults_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

int kgmmuServicePriFaults_GV100(long param_1,long param_2)

{
  long lVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  long lVar10;
  int iVar11;
  uint uVar12;
  bool bVar13;
  uint local_fc;
  undefined8 *local_f8;
  ulong local_f0;
  long local_e8;
  ulong local_e0;
  long local_d8;
  ulong local_d0;
  long local_c8 [2];
  ulong local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  ulong local_a0;
  long local_90;
  ulong local_88;
  undefined1 local_80 [4];
  uint local_7c;
  uint local_78;
  undefined4 local_74;
  undefined8 auStack_70 [8];
  ulong uVar9;
  
  lVar10 = *(long *)(&DAT_00001b90 + param_1);
  lVar1 = *(long *)(param_1 + 0x1c18);
  uVar5 = (**(code **)(param_2 + 0x2f8))(param_1,param_2,0);
  local_f8 = (undefined8 *)0x0;
  local_d8 = 0;
  local_d0 = 0;
  local_c8[0] = 0;
  local_c8[1] = 0;
  local_b8 = 0;
  local_b0 = 0;
  local_a8 = 0;
  local_a0 = 0;
  uVar8 = 0;
  do {
    uVar6 = (int)uVar8 + 0x20;
    uVar9 = (ulong)uVar6;
    *(undefined8 *)((long)&local_90 + uVar8) = 0;
    *(undefined8 *)((long)&local_88 + uVar8) = 0;
    *(undefined8 *)(local_80 + uVar8) = 0;
    *(undefined8 *)((long)auStack_70 + (uVar8 - 8)) = 0;
    uVar8 = uVar9;
  } while (uVar6 < 0x40);
  *(undefined8 *)((long)&local_90 + uVar9) = 0;
  *(undefined8 *)((long)&local_88 + uVar9) = 0;
  iVar11 = -((int)uVar5 >> 0x1f);
  *(undefined8 *)(local_80 + uVar9) = 0;
  if (iVar11 == 0) {
    return 0;
  }
  (**(code **)(param_2 + 0x420))(param_1,param_2,&local_f0,&local_fc);
  local_d8 = ((local_f0 & 0xffffffff) * 0x100000 + (ulong)(local_fc >> 0xc)) * 0x1000;
  local_b0 = CONCAT44(local_b0._4_4_,local_fc) & 0xffffffff000001ff;
  local_d0 = (ulong)(local_fc >> 10) & 0xffffffff00000003;
  (**(code **)(param_2 + 0x428))(param_1,param_2,&local_f0,&local_fc);
  local_c8[0] = ((ulong)(local_fc >> 0xc) + (local_f0 & 0xffffffff) * 0x100000) * 0x1000;
  (**(code **)(param_2 + 0x460))(param_1,param_2,local_c8);
  local_fc = (**(code **)(param_2 + 0x430))(param_1,param_2);
  iVar7 = (**(code **)(param_2 + 0x468))(param_1,param_2,local_fc & 0x1f,&local_b8);
  if (iVar7 != 0) {
    nvAssertFailedNoLog("rmStatus == NV_OK","src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x8d3)
    ;
    nvCheckOkFailedNoLog
              (4,iVar7,
               "_kgmmuCreateExceptionDataFromPriv_GV100(pGpu, pKernelGmmu, &parsedFaultEntry, &mmuExceptionData)"
               ,"src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x99e);
    return iVar7;
  }
  bVar2 = (byte)(local_fc >> 0x18);
  uVar6 = local_fc >> 0x14 & 1;
  local_b0 = CONCAT44(local_fc >> 8,(undefined4)local_b0) & 0x7fffffffff;
  local_78 = local_fc >> 0x10 & 0xf;
  local_7c = local_fc >> 0x18 & 0x1f;
  local_b8 = CONCAT44(local_fc >> 0x10,(int)local_b8) & 0xfffffffff;
  local_a8 = CONCAT44(local_fc >> 0x18,local_fc >> 0x14) & 0x1f00000001;
  local_a0 = CONCAT71(local_a0._1_7_,
                      (bVar2 >> 5 & 1) * '\x02' | bVar2 >> 7 | (byte)((local_fc >> 7 & 1) << 2) |
                      (byte)((local_fc >> 0x1e & 1) << 3) | (byte)local_a0 & 0xf0);
  local_90 = local_c8[0];
  local_88 = CONCAT44(local_fc >> 8,(int)local_b8) & 0x7fffffffff;
  local_80[0] = uVar6 == 0;
  if (uVar6 != 0) {
    local_7c = 0;
  }
  local_74 = (undefined4)local_b0;
  cVar3 = (**(code **)(param_2 + 0x378))(param_2);
  if (cVar3 == '\0') {
    cVar3 = (**(code **)(param_2 + 0x380))(param_2,local_b0 & 0xffffffff);
    if (cVar3 != '\0') {
      cVar3 = (**(code **)(param_2 + 0x470))(param_2,local_b8 & 0xffffffff,local_b0._4_4_);
      if (cVar3 != '\0') goto LAB_00400e8d;
      nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x9b3,
                   "kgmmuServicePriFaults_GV100",4,"NVRM: BAR2 MMU Fault\n");
      (**(code **)(param_2 + 0x370))(param_1,param_2,local_b0 & 0xffffffff,&local_90);
      lVar10 = *(long *)(param_1 + 0x1cd8);
      cVar3 = (**(code **)(param_2 + 0x340))(param_1,param_2);
      cVar4 = (**(code **)(param_2 + 0x480))(param_1,param_2,uVar5);
      uVar6 = uVar5 >> 10 & 1;
      if (((uVar5 & 0xc00) != 0) &&
         (iVar11 = (**(code **)(param_2 + 0x410))(param_1,param_2,uVar6,1,0), iVar11 != 0)) {
LAB_00401121:
        nvAssertFailedNoLog("rmStatus == NV_OK","src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",
                            0x9b6);
        bVar13 = lVar1 != 0;
        if (*(char *)(param_1 + 0x4913) == '\0') goto LAB_00400f5f;
LAB_00401150:
        bVar13 = lVar1 != 0;
        iVar11 = 2;
        goto LAB_00400f47;
      }
      if ((cVar3 != '\0') && (*(int *)(lVar10 + 0x280) != 0)) {
        uVar12 = 0;
        do {
          iVar11 = (**(code **)(lVar10 + 0x1f0))(param_1,lVar10,uVar12,1);
          if (iVar11 != 0) goto LAB_00401121;
          uVar12 = uVar12 + 1;
        } while (uVar12 < *(uint *)(lVar10 + 0x280));
      }
      if (cVar4 != '\0') {
        (**(code **)(param_2 + 0x488))(param_1,param_2);
      }
      (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x480))
                (param_1,*(long *)(&DAT_00001b90 + param_1),1);
      (**(code **)(param_2 + 0x4a0))(param_1,param_2);
      if (((uVar5 & 0xc00) != 0) &&
         (iVar11 = (**(code **)(param_2 + 0x408))(param_1,param_2,uVar6,1,0), iVar11 != 0))
      goto LAB_00401121;
      if (cVar3 != '\0') {
        if (*(int *)(lVar10 + 0x280) != 0) {
          uVar6 = 0;
          do {
            iVar11 = (**(code **)(lVar10 + 0x1e8))(param_1,lVar10,uVar6,1);
            if (iVar11 != 0) goto LAB_00401121;
            uVar6 = uVar6 + 1;
          } while (uVar6 < *(uint *)(lVar10 + 0x280));
        }
        (**(code **)(param_2 + 0x498))(param_1,param_2);
      }
      if ((cVar4 != '\0') && (iVar11 = (**(code **)(param_2 + 0x490))(param_1,param_2), iVar11 != 0)
         ) goto LAB_00401121;
      bVar13 = lVar1 != 0;
      iVar11 = 0;
      if (*(char *)(param_1 + 0x4913) != '\0') goto LAB_00401150;
      goto LAB_00400f5f;
    }
LAB_00400e8d:
    cVar3 = (**(code **)(param_2 + 0x388))(param_2,local_b0 & 0xffffffff);
    if (cVar3 == '\0') {
      if ((int)local_88 == 4) {
        nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x9cb,
                     "kgmmuServicePriFaults_GV100",4,"NVRM: Unbound Instance MMU fault\n");
        (**(code **)(param_2 + 0x370))(param_1,param_2,local_b0 & 0xffffffff,&local_90);
        iVar11 = (**(code **)(param_2 + 0x4e8))(param_1,param_2,&local_d8,&local_90);
        if (iVar11 != 0) {
          nvCheckOkFailedNoLog
                    (4,iVar11,
                     "kgmmuServiceUnboundInstBlockFault_HAL(pGpu, pKernelGmmu, NV_PTR_TO_NvP64(&parsedFaultEntry), &mmuExceptionData)"
                     ,"src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x9cf);
          return iVar11;
        }
        if (*(char *)(param_1 + 0x4913) != '\0') {
          iVar11 = 4;
          goto LAB_00400f40;
        }
      }
      else {
        iVar11 = (**(code **)(param_2 + 0x2f0))(param_1,param_2,1,0);
        iVar7 = (**(code **)(param_2 + 0x2f0))(param_1,param_2,0,0);
        if ((iVar11 < 0) && (iVar7 < 0)) {
          (**(code **)(param_2 + 0x370))(param_1,param_2,local_b0 & 0xffffffff,&local_90);
        }
        else if ((local_a0 & 1) != 0) {
          if ((local_a0 & 4) == 0) {
            (**(code **)(param_2 + 0x370))(param_1,param_2,local_b0 & 0xffffffff,&local_90);
            iVar11 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,&local_d8,&local_90);
            if (iVar11 != 0) {
              nvCheckOkFailedNoLog
                        (4,iVar11,
                         "kgmmuServiceMmuFault_HAL(pGpu, pKernelGmmu, NV_PTR_TO_NvP64(&parsedFaultEntry), &mmuExceptionData)"
                         ,"src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x9ef);
              return iVar11;
            }
          }
          else {
            nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x9e7,
                         "kgmmuServicePriFaults_GV100",4,
                         "NVRM: MMU Fault : Replayable fault with fault-buffer disabled. Initiating cancel\n"
                        );
            local_f0 = CONCAT44(local_a8._4_4_,local_b0._4_4_);
            local_e0 = local_d0;
            local_e8 = local_d8;
            uVar6 = (**(code **)(param_2 + 0x2f8))(param_1,param_2,0);
            (**(code **)(param_2 + 0x300))(param_1,param_2,uVar6 | 0x80000000);
            iVar11 = (**(code **)(param_2 + 0x4a8))(param_1,param_2,&local_f0);
            if (iVar11 != 0) {
              nvCheckOkFailedNoLog
                        (4,iVar11,
                         "_kgmmuHandleReplayablePrivFault_GV100(pGpu, pKernelGmmu, &parsedFaultEntry)"
                         ,"src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x9e9);
              return iVar11;
            }
          }
        }
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x9c2,
                   "kgmmuServicePriFaults_GV100",4,"NVRM: Physical MMU fault\n");
      (**(code **)(param_2 + 0x370))(param_1,param_2,local_b0 & 0xffffffff,&local_90);
      gpuNotifySubDeviceEvent_IMPL(param_1,0x79,0,0,0,0);
      if (*(char *)(param_1 + 0x4913) != '\0') {
        bVar13 = false;
        iVar11 = 3;
        goto LAB_00400f47;
      }
    }
  }
  else {
    (**(code **)(lVar10 + 0x530))(param_1);
    nvDbg_Printf("src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0x9aa,
                 "kgmmuServicePriFaults_GV100",4,"NVRM: BAR1 MMU Fault\n");
    (**(code **)(param_2 + 0x370))(param_1,param_2,local_b0 & 0xffffffff,&local_90);
    if (*(char *)(param_1 + 0x4913) != '\0') {
LAB_00400f40:
      bVar13 = false;
LAB_00400f47:
      iVar11 = (**(code **)(param_2 + 0x478))(param_1,param_2,iVar11);
LAB_00400f5f:
      (**(code **)(param_2 + 0x300))(param_1,param_2,uVar5);
      if ((bVar13) && (*(char *)(lVar1 + 0x198) != '\0')) {
        *(undefined1 *)(param_1 + 0x4a8) = 1;
        lVar10 = gpuGetKernelFifoShared_IMPL(param_1);
        (**(code **)(lVar10 + 0x2e0))(param_1,lVar10,0,*(code **)(lVar10 + 0x2e0));
      }
      goto LAB_00400d82;
    }
  }
  (**(code **)(param_2 + 0x300))(param_1,param_2,uVar5);
  iVar11 = 0;
LAB_00400d82:
  iVar7 = CliGetEventNotificationList
                    (*(undefined4 *)(param_2 + 0x628),*(undefined4 *)(param_2 + 0x62c),0,&local_f8);
  if ((iVar7 == 0) && (local_f8 != (undefined8 *)0x0)) {
    iVar11 = notifyEvents(param_1,*local_f8,3,0,0,0,1);
  }
  if (((int)local_b8 == 0xe) && (cVar3 = (**(code **)(param_1 + 0x350))(param_1), cVar3 != '\0')) {
    local_f0 = 0;
    local_e8 = 0;
    local_e0 = 0;
    iVar7 = (**(code **)(param_1 + 0x3d0))(param_1,10,0);
    if (iVar7 != 0) {
      nvAssertOkFailedNoLog
                (iVar7,
                 "gpuUpdateErrorContainmentState_HAL(pGpu, NV_ERROR_CONT_ERR_ID_E13_MMU_POISON, loc, NULL)"
                 ,"src/kernel/gpu/mmu/arch/volta/kern_gmmu_gv100.c",0xa1a);
      iVar11 = iVar7;
    }
  }
  return iVar11;
}


// ===== 004015a0 kgmmuCheckAccessCounterBar2FaultServicingState_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgmmuCheckAccessCounterBar2FaultServicingState_GV100(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x338))();
  return;
}


// ===== 004015b0 _bar2WalkCBUpdatePdb =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8 _bar2WalkCBUpdatePdb(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  long lVar8;
  ulong uVar9;
  undefined8 uStack_40;
  uint local_2c;
  
  lVar1 = *(long *)(param_1 + 8);
  lVar2 = *(long *)(&DAT_00001b90 + lVar1);
  lVar8 = *(long *)(lVar1 + 0x1b98);
  iVar3 = vgpuGetCallingContextGfid(lVar1,&local_2c);
  if (iVar3 != 0) {
    nvAssertFailedNoLog("vgpuGetCallingContextGfid(pGpu, &gfid) == NV_OK",
                        "src/kernel/gpu/mmu/bar2_walk.c",0x3b);
    return 0;
  }
  lVar4 = (ulong)local_2c * 0xd8 + lVar2;
  if (*(char *)(lVar4 + 0x46a8) == '\0') {
    if (param_3 == 0) {
      return 1;
    }
    if (*(int *)(lVar2 + 0xad3c) != 1) {
      uVar5 = (**(code **)(lVar8 + 0x1d0))(lVar8);
      lVar8 = (ulong)local_2c * 0xd8 + lVar2;
      iVar3 = (**(code **)(lVar2 + 0x490))
                        (lVar1,lVar2,*(undefined8 *)(lVar8 + 0x4678),*(undefined8 *)(lVar8 + 0x4660)
                         ,*(undefined8 *)(lVar8 + 18000),uVar5,0);
      goto LAB_00401664;
    }
LAB_00401740:
    uStack_40 = 0x40174f;
    uVar6 = (**(code **)(lVar8 + 0x1d0))(lVar8);
    uVar9 = (ulong)local_2c;
    lVar8 = uVar9 * 0xd8 + lVar2;
    uVar5 = *(undefined8 *)(lVar8 + 18000);
    uVar7 = *(undefined8 *)(lVar8 + 0x4660);
LAB_0040176d:
    iVar3 = (**(code **)(lVar2 + 0x490))
                      (lVar1,lVar2,*(undefined8 *)(lVar2 + 0x4678 + uVar9 * 0xd8),uVar7,uVar5,uVar6,
                       0);
    if (iVar3 == 0) {
      return 1;
    }
    nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/mmu/bar2_walk.c",0x6b,uStack_40);
    return 0;
  }
  if ((*(char *)(lVar2 + 0xad08) == '\0') || (*(long *)(lVar4 + 0x4698) == 0)) {
    if (param_3 == 0) {
      return 1;
    }
    if (*(int *)(lVar2 + 0xad3c) == 1) goto LAB_00401740;
    uVar6 = (**(code **)(lVar8 + 0x1d0))(lVar8);
    lVar8 = (ulong)local_2c * 0xd8 + lVar2;
    uVar5 = *(undefined8 *)(lVar8 + 18000);
    uVar7 = *(undefined8 *)(lVar8 + 0x4660);
  }
  else {
    if (param_3 == 0) {
      return 1;
    }
    if (*(int *)(lVar2 + 0xad3c) == 1) {
      uStack_40 = 0x4017d0;
      uVar6 = (**(code **)(lVar8 + 0x1d0))(lVar8);
      uVar9 = (ulong)local_2c;
      lVar8 = uVar9 * 0xd8 + lVar2;
      uVar5 = *(undefined8 *)(lVar8 + 18000);
      uVar7 = *(undefined8 *)(lVar8 + 0x4698);
      goto LAB_0040176d;
    }
    uVar6 = (**(code **)(lVar8 + 0x1d0))(lVar8);
    lVar8 = (ulong)local_2c * 0xd8 + lVar2;
    uVar5 = *(undefined8 *)(lVar8 + 18000);
    uVar7 = *(undefined8 *)(lVar8 + 0x4698);
  }
  iVar3 = (**(code **)(lVar2 + 0x490))(lVar1,lVar2,0,uVar7,uVar5,uVar6,0);
LAB_00401664:
  if (iVar3 == 0) {
    return 1;
  }
  nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/mmu/bar2_walk.c",0x61);
  return 0;
}


// ===== 00401840 _bar2WalkCBWriteBuffer =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _bar2WalkCBWriteBuffer
               (long param_1,long param_2,undefined8 param_3,long param_4,long param_5,ulong param_6
               ,long param_7)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  uint uVar12;
  uint local_6c;
  long local_68;
  undefined8 local_60;
  undefined8 local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar8 = *(long *)(param_1 + 8);
  lVar6 = *(long *)(lVar8 + 0x1b98);
  lVar1 = *(long *)(&DAT_00001b90 + lVar8);
  iVar4 = vgpuGetCallingContextGfid(lVar8,&local_6c);
  if (iVar4 != 0) {
    nvAssertFailedNoLog("vgpuGetCallingContextGfid(pGpu, &gfid) == NV_OK",
                        "src/kernel/gpu/mmu/bar2_walk.c",0x33a);
    return;
  }
  iVar4 = memdescMapOld(param_2,0,*(undefined8 *)(param_2 + 0x30),1,3,&local_68,&local_60);
  if (iVar4 == 0) {
    lVar11 = ((param_5 + 1) - param_4) * param_7;
    uVar9 = param_7 * param_4;
    lVar10 = uVar9 % param_6 + local_68;
    if (*(char *)(lVar1 + 0xad0c) == '\0') {
      if (*(char *)(lVar1 + 0x46a8 + (ulong)local_6c * 0xd8) == '\0') {
        lVar6 = *(long *)(lVar1 + 0x7c78 + (ulong)local_6c * 0xb0);
        iVar4 = memdescGetAddressSpace(param_3);
        lVar8 = memdescGetPhysAddr(param_3,(iVar4 == 2) + '\x01',uVar9);
        lVar6 = (lVar8 - *(long *)(lVar1 + 0x4658 + (ulong)local_6c * 0xd8)) + lVar6;
      }
      else if (*(char *)(lVar1 + 0xad08) == '\0') {
        iVar4 = memdescGetAddressSpace(param_3);
        uVar9 = memdescGetPhysAddr(param_3,(iVar4 == 2) + '\x01',uVar9);
        lVar3 = *(long *)(lVar1 + 0x608);
        lVar6 = *(long *)(lVar1 + 0x600);
        uVar7 = (**(code **)(lVar1 + 0x438))(lVar8,lVar1);
        if ((uVar9 < uVar7) || (uVar7 + lVar3 <= lVar11 + uVar9)) {
          (**(code **)(lVar1 + 0x430))(lVar8,lVar1);
          portMemCopy((uVar9 - (-lVar3 & uVar9)) + lVar6,lVar11,lVar10,lVar11);
          memdescUnmapOld(param_2,1,local_68,local_60);
          (**(code **)(lVar1 + 0x430))(lVar8,lVar1,uVar7);
          return;
        }
        lVar6 = lVar6 + (uVar9 - uVar7);
      }
      else {
        lVar6 = kbusCpuOffsetInBar2WindowGet_IMPL(lVar8,lVar1,param_3);
        lVar6 = lVar6 + uVar9;
      }
      portMemCopy(lVar6,lVar11,lVar10,lVar11);
    }
    else {
      local_58 = 0;
      local_50 = 0;
      uVar2 = *(undefined8 *)(lVar8 + 0x1b78);
      local_48 = 0;
      local_40 = 0;
      if (*(long *)(lVar1 + 0x7c78 + (ulong)local_6c * 0xb0) != 0) {
        nvAssertFailedNoLog("pKernelBus->virtualBar2[gfid].pPageLevels == NULL",
                            "src/kernel/gpu/mmu/bar2_walk.c",0x34f);
        return;
      }
      uVar12 = -(uint)(*(char *)(lVar6 + 0x54c) == '\0') & 0xfffff000;
      local_58 = param_3;
      local_50 = uVar9;
      uVar5 = memmgrMemBeginTransfer_IMPL(uVar2,&local_58,lVar11,uVar12 + 0x1002);
      portMemCopy(uVar5,lVar11,lVar10,lVar11);
      memmgrMemEndTransfer_IMPL(uVar2,&local_58,lVar11,uVar12 + 0x1002);
    }
    memdescUnmapOld(param_2,1,local_68,local_60);
  }
  else {
    nvAssertFailedNoLog("memdescMapOld(pStagingBufferDesc, 0, pStagingBufferDesc->Size, NV_TRUE, NV_PROTECT_READ_WRITE, (void **)&pStagingDescMapping, &pPriv) == NV_OK"
                        ,"src/kernel/gpu/mmu/bar2_walk.c",0x33d,0x40188d);
  }
  return;
}


// ===== 00401c10 _bar2WalkCBFillEntries =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _bar2WalkCBFillEntries
               (long param_1,long param_2,long param_3,uint param_4,uint param_5,int param_6,
               int *param_7)

{
  byte bVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  long lVar13;
  undefined8 uStack_c0;
  uint local_90;
  long local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  bVar1 = *(byte *)(param_2 + 2);
  lVar2 = *(long *)(param_1 + 8);
  local_78 = 0;
  uVar8 = (ulong)*(uint *)(param_1 + 0x28);
  lVar9 = *(long *)(&DAT_00001b90 + lVar2);
  lVar13 = *(long *)(lVar2 + 0x1b98);
  local_70 = 0;
  lVar6 = kgmmuFmtGetFamily_IMPL(lVar13,**(undefined4 **)(lVar9 + 0x46c0 + uVar8 * 0xd8));
  if (param_6 == 0) {
    portMemSet(&local_68,0,0x10);
  }
  else if (param_6 == 1) {
    lVar7 = (**(code **)(lVar13 + 0x508))(lVar2,lVar13,param_2);
    if (lVar7 != 0) {
      portMemCopy(&local_68,*(undefined1 *)(param_2 + 2),lVar7,*(undefined1 *)(param_2 + 2));
      iVar4 = memdescGetAddressSpace(param_3);
      goto joined_r0x00401cc9;
    }
    if (*(char *)(param_2 + 4) == '\0') {
      local_68 = *(undefined8 *)(lVar6 + 0x4c0);
      local_60 = *(undefined8 *)(lVar6 + 0x4c8);
    }
    else if (*(char *)(param_2 + 4) == '\x01') {
      local_68 = *(undefined8 *)(lVar6 + 0x4d0);
      local_60 = *(undefined8 *)(lVar6 + 0x4d8);
    }
    else {
      local_68 = *(undefined8 *)(lVar6 + 0x4e0);
      local_60 = *(undefined8 *)(lVar6 + 0x4e8);
    }
  }
  else {
    nvAssertFailedNoLog(&DAT_00d66a6a,"src/kernel/gpu/mmu/bar2_walk.c",0xbc);
  }
  iVar4 = memdescGetAddressSpace(param_3);
joined_r0x00401cc9:
  if (iVar4 == 2) {
    if (*(char *)(lVar9 + 0xad0c) == '\0') {
      lVar13 = uVar8 * 0xd8 + lVar9;
      if (*(char *)(lVar13 + 0x46a8) == '\0') {
        lVar2 = *(long *)(lVar9 + 0x7c78 + uVar8 * 0xb0);
        if (lVar2 == 0) {
          nvAssertFailedNoLog("pKernelBus->virtualBar2[gfid].pPageLevels != NULL",
                              "src/kernel/gpu/mmu/bar2_walk.c",0x114);
          return;
        }
        lVar9 = memdescGetPhysAddr(param_3,1,0);
        local_78 = lVar2 + (lVar9 - *(long *)(lVar13 + 0x4658));
        for (uVar11 = param_4; uVar11 <= param_5; uVar11 = uVar11 + 1) {
          bVar1 = *(byte *)(param_2 + 2);
          portMemCopy(local_78 + (ulong)(bVar1 * uVar11),bVar1,&local_68,bVar1);
        }
      }
      else if (*(char *)(lVar9 + 0xad08) == '\0') {
        if (*(long *)(lVar9 + 0x7c78 + uVar8 * 0xb0) != 0) {
          nvAssertFailedNoLog("pKernelBus->virtualBar2[gfid].pPageLevels == NULL",
                              "src/kernel/gpu/mmu/bar2_walk.c",0xf8);
          return;
        }
        if (param_4 <= param_5) {
          uVar8 = (ulong)bVar1 + 3 >> 2;
          local_90 = param_4;
          do {
            bVar1 = *(byte *)(param_2 + 2);
            iVar4 = memdescGetAddressSpace(param_3);
            lVar13 = memdescGetPhysAddr(param_3,(iVar4 == 2) + '\x01',bVar1 * local_90);
            if (uVar8 != 0) {
              lVar6 = lVar13;
              do {
                iVar4 = kbusMemAccessBar0Window_GM107
                                  (lVar2,lVar9,lVar6,(long)&local_68 + (lVar6 - lVar13),4,0,2);
                if (iVar4 != 0) {
                  nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/mmu/bar2_walk.c",0x108);
                  return;
                }
                lVar6 = lVar6 + 4;
              } while (lVar13 + ((ulong)((int)uVar8 - 1) + 1) * 4 != lVar6);
            }
            local_90 = local_90 + 1;
          } while (local_90 <= param_5);
        }
      }
      else {
        local_78 = kbusCpuOffsetInBar2WindowGet_IMPL(lVar2,lVar9,param_3);
        for (uVar11 = param_4; uVar11 <= param_5; uVar11 = uVar11 + 1) {
          bVar1 = *(byte *)(param_2 + 2);
          portMemCopy(local_78 + (ulong)(bVar1 * uVar11),bVar1,&local_68,bVar1);
        }
      }
      iVar4 = (param_5 + 1) - param_4;
    }
    else {
      uVar3 = *(undefined8 *)(lVar2 + 0x1b78);
      local_58 = 0;
      local_50 = 0;
      local_48 = 0;
      local_40 = 0;
      if (*(long *)(lVar9 + 0x7c78 + uVar8 * 0xb0) != 0) {
        nvAssertFailedNoLog("pKernelBus->virtualBar2[gfid].pPageLevels == NULL",
                            "src/kernel/gpu/mmu/bar2_walk.c",200);
        return;
      }
      iVar4 = (param_5 + 1) - param_4;
      local_50 = (ulong)(*(byte *)(param_2 + 2) * param_4);
      uVar10 = 0x1002;
      if (*(char *)(lVar13 + 0x54c) == '\0') {
        uVar10 = 2;
      }
      iVar5 = (uint)*(byte *)(param_2 + 2) * iVar4;
      local_58 = param_3;
      local_78 = memmgrMemBeginTransfer_IMPL(uVar3,&local_58,iVar5);
      if (param_4 <= param_5) {
        iVar12 = 0;
        do {
          bVar1 = *(byte *)(param_2 + 2);
          uVar11 = (uint)bVar1 * iVar12;
          iVar12 = iVar12 + 1;
          portMemCopy(local_78 + (ulong)uVar11,bVar1,&local_68,bVar1);
        } while (param_4 + iVar12 <= param_5);
      }
      memmgrMemEndTransfer_IMPL(uVar3,&local_58,iVar5,uVar10);
    }
  }
  else {
    uStack_c0 = 0x401e79;
    iVar4 = memdescGetAddressSpace(param_3);
    if (iVar4 != 1) {
      uStack_c0 = 0x402198;
      nvAssertFailedNoLog("memdescGetAddressSpace(pMemDesc) == ADDR_SYSMEM",
                          "src/kernel/gpu/mmu/bar2_walk.c",0x128);
    }
    iVar4 = memdescMapOld(param_3,0,*(undefined8 *)(param_3 + 0x30),1,3,&local_78,&local_70);
    uVar11 = param_4;
    if (iVar4 != 0) {
      nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/mmu/bar2_walk.c",0x131,uStack_c0);
      return;
    }
    for (; uVar11 <= param_5; uVar11 = uVar11 + 1) {
      bVar1 = *(byte *)(param_2 + 2);
      portMemCopy((ulong)(bVar1 * uVar11) + local_78,bVar1,&local_68,bVar1);
    }
    iVar4 = (param_5 + 1) - param_4;
    memdescUnmapOld(param_3,1,local_78,local_70);
  }
  *param_7 = iVar4;
  return;
}


// ===== 004022a0 _bar2WalkCBUpdatePde =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _bar2WalkCBUpdatePde(long param_1,long param_2,ulong param_3,int param_4,long param_5)

{
  long lVar1;
  long lVar2;
  int *piVar3;
  ulong uVar4;
  byte bVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  long lVar9;
  uint *puVar10;
  undefined8 uVar11;
  ulong uVar12;
  long lVar13;
  ulong uVar14;
  ulong uVar15;
  long lVar16;
  undefined8 uStack_e0;
  uint local_7c;
  long local_78;
  undefined8 local_70;
  ulong local_68 [2];
  ulong local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar1 = *(long *)(param_1 + 8);
  lVar13 = *(long *)(lVar1 + 0x1b98);
  lVar2 = *(long *)(&DAT_00001b90 + lVar1);
  local_78 = 0;
  local_70 = 0;
  iVar7 = vgpuGetCallingContextGfid(lVar1,&local_7c);
  if (iVar7 == 0) {
    piVar3 = *(int **)(lVar2 + 0x46c0 + (ulong)local_7c * 0xd8);
    uStack_e0 = 0x402349;
    portMemSet(local_68,0,*(undefined1 *)(param_2 + 2));
    if (*(char *)(param_2 + 4) != '\0') {
      uVar14 = 0;
      do {
        lVar9 = gmmuFmtGetPde(piVar3,param_2,uVar14 & 0xffffffff);
        lVar16 = *(long *)(param_5 + uVar14 * 8);
        if (lVar16 == 0) {
          uStack_e0 = 0x4025e1;
          nvDbg_Printf("src/kernel/gpu/mmu/bar2_walk.c",0x18c,"_bar2WalkCBUpdatePde",1,
                       "NVRM:     SubLevel %u = INVALID\n",uVar14 & 0xffffffff);
        }
        else {
          uVar8 = kgmmuGetMemAperture_IMPL(lVar13,lVar16);
          puVar10 = (uint *)gmmuFmtPdePhysAddrFld(lVar9,uVar8);
          uVar11 = memdescGetPtePhysAddr(lVar16,1,0);
          if (*piVar3 == 3) {
            local_58 = local_58 & 0xffffffff00000000;
            cVar6 = memdescGetVolatility(lVar16);
            iVar7 = (**(code **)(lVar13 + 0x290))(lVar13,(ulong)(cVar6 != '\0') << 5,&local_58);
            if (iVar7 != 0) {
              nvAssertFailedNoLog("(kgmmuTranslatePdePcfFromSw_HAL(pKernelGmmu, pdePcfSw, &pdePcfHw) == NV_OK)"
                                  ,"src/kernel/gpu/mmu/bar2_walk.c",0x179);
              return 0x1f;
            }
            *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar9 + 0xfa)) =
                 (int)local_58 << ((byte)*(undefined2 *)(lVar9 + 0xf8) & 0x1f) |
                 *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar9 + 0xfa)) &
                 *(uint *)(lVar9 + 0xf4);
          }
          else {
            bVar5 = memdescGetVolatility(lVar16);
            *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar9 + 0xea)) =
                 (uint)(bVar5 ^ *(byte *)(lVar9 + 0xec)) <<
                 ((byte)*(undefined2 *)(lVar9 + 0xe8) & 0x1f) |
                 *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar9 + 0xea)) &
                 *(uint *)(lVar9 + 0xe4);
          }
          *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar9 + 0x12)) =
               (uint)*(byte *)(*(long *)(lVar9 + 0x18) + 1 + (ulong)uVar8 * 2) <<
               ((byte)*(undefined2 *)(lVar9 + 0x10) & 0x1f) |
               *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar9 + 0x12)) & *(uint *)(lVar9 + 0xc)
          ;
          uStack_e0 = 0x40246a;
          uVar12 = kgmmuEncodePhysAddr_IMPL(lVar13,(ulong)uVar8,uVar11,0xffffffffffffffff);
          if (*puVar10 != 0) {
            uVar12 = uVar12 >> ((byte)puVar10[0xe] & 0x3f);
            uVar15 = 0;
            do {
              uVar8 = (int)uVar15 + 1;
              uVar4 = *(ulong *)((long)local_68 + (ulong)puVar10[uVar15 * 6 + 6]);
              *(ulong *)((long)local_68 + (ulong)puVar10[uVar15 * 6 + 6]) =
                   (uVar12 << ((byte)puVar10[uVar15 * 6 + 5] & 0x3f) ^ uVar4) &
                   *(ulong *)(puVar10 + uVar15 * 6 + 2) ^ uVar4;
              uVar12 = uVar12 >> ((byte)puVar10[uVar15 * 6 + 4] & 0x3f);
              uVar15 = (ulong)uVar8;
            } while (uVar8 < *puVar10);
          }
          nvDbg_Printf("src/kernel/gpu/mmu/bar2_walk.c",0x187,"_bar2WalkCBUpdatePde",1,
                       "NVRM:     SubLevel %u = PA 0x%llX\n",uVar14 & 0xffffffff,uVar11);
        }
        uVar14 = uVar14 + 1;
      } while ((uint)uVar14 < (uint)*(byte *)(param_2 + 4));
    }
    uVar14 = (ulong)((uint)*(byte *)(param_2 + 2) * param_4);
    if (*(int *)(lVar2 + 0xad34) == 2) {
      if (*(char *)(lVar2 + 0xad0c) == '\0') {
        lVar13 = (ulong)local_7c * 0xd8 + lVar2;
        if (*(char *)(lVar13 + 0x46a8) == '\0') {
          if (((*(char *)(lVar13 + 0x46a9) == '\0') && (local_7c == 0)) &&
             ((*(char *)(lVar1 + 0x454) == '\0' || (*(char *)(lVar1 + 0x4915) == '\0')))) {
            nvAssertFailedNoLog(&DAT_00d66a6a,"src/kernel/gpu/mmu/bar2_walk.c",0x1d1);
            return 0;
          }
          lVar1 = *(long *)(lVar2 + 0x7c78 + (ulong)local_7c * 0xb0);
          if (lVar1 == 0) {
            nvAssertFailedNoLog("NULL != pKernelBus->virtualBar2[gfid].pPageLevels",
                                "src/kernel/gpu/mmu/bar2_walk.c",0x1c7);
            lVar1 = *(long *)(lVar2 + 0x7c78 + (ulong)local_7c * 0xb0);
            lVar13 = memdescGetPhysAddr(param_3,1,0);
            local_78 = (lVar13 - *(long *)(lVar2 + 0x4658 + (ulong)local_7c * 0xd8)) + lVar1;
            if (local_78 == 0) {
              nvAssertFailedNoLog("NULL != pMap","src/kernel/gpu/mmu/bar2_walk.c",0x1cc);
            }
          }
          else {
            lVar13 = memdescGetPhysAddr(param_3,1,0);
            local_78 = (lVar13 - *(long *)(lVar2 + 0x4658 + (ulong)local_7c * 0xd8)) + lVar1;
          }
        }
        else {
          if (*(char *)(lVar2 + 0xad08) == '\0') {
            lVar13 = memdescGetPhysAddr(param_3,2,uVar14);
            uVar14 = (ulong)*(byte *)(param_2 + 2) + 3 >> 2;
            if (uVar14 == 0) {
              return 1;
            }
            lVar16 = lVar13;
            do {
              iVar7 = kbusMemAccessBar0Window_GM107
                                (lVar1,lVar2,lVar16,(long)local_68 + (lVar16 - lVar13),4,0,2);
              if (iVar7 != 0) {
                nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/mmu/bar2_walk.c",0x1c0);
                return 0;
              }
              lVar16 = lVar16 + 4;
            } while (lVar16 != lVar13 + uVar14 * 4);
            return 1;
          }
          local_78 = kbusCpuOffsetInBar2WindowGet_IMPL(lVar1,lVar2,param_3);
        }
        portMemCopy(local_78 + uVar14,*(undefined1 *)(param_2 + 2),local_68,
                    *(undefined1 *)(param_2 + 2));
        return 1;
      }
      local_58 = 0;
      local_50 = 0;
      local_48 = 0;
      local_40 = 0;
      if (*(long *)(lVar2 + 0x7c78 + (ulong)local_7c * 0xb0) == 0) {
        local_58 = param_3;
        local_50 = uVar14;
        iVar7 = memmgrMemWrite_IMPL(*(undefined8 *)(lVar1 + 0x1b78),&local_58,local_68,
                                    *(byte *)(param_2 + 2),
                                    (ulong)(*(char *)(lVar13 + 0x54c) != '\0') << 0xc);
        if (iVar7 == 0) {
          return 1;
        }
        nvAssertFailedNoLog("memmgrMemWrite(pMemoryManager, &surf, entry.v8, pLevelFmt->entrySize, transferFlags) == NV_OK"
                            ,"src/kernel/gpu/mmu/bar2_walk.c",0x1a5);
      }
      else {
        nvAssertFailedNoLog("pKernelBus->virtualBar2[gfid].pPageLevels == NULL",
                            "src/kernel/gpu/mmu/bar2_walk.c",0x19a);
      }
    }
    else if (*(int *)(lVar2 + 0xad34) == 1) {
      iVar7 = memdescMapOld(param_3,0,*(undefined8 *)(param_3 + 0x30),1,3,&local_78,&local_70);
      if (iVar7 == 0) {
        portMemCopy(uVar14 + local_78,*(undefined1 *)(param_2 + 2),local_68,
                    *(undefined1 *)(param_2 + 2));
        memdescUnmapOld(param_3,1,local_78,local_70);
        return 1;
      }
      nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/mmu/bar2_walk.c",0x1dd,uStack_e0);
    }
    else {
      nvAssertFailedNoLog(&DAT_00d66a6a,"src/kernel/gpu/mmu/bar2_walk.c",0x1e3);
    }
  }
  else {
    nvAssertFailedNoLog("vgpuGetCallingContextGfid(pGpu, &gfid) == NV_OK",
                        "src/kernel/gpu/mmu/bar2_walk.c",0x160);
  }
  return 0;
}


// ===== 00402a00 _bar2WalkCBLevelFree =====

void _bar2WalkCBLevelFree(undefined8 param_1,long param_2,ulong param_3,undefined8 param_4)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = *(char *)(param_2 + 1);
  uVar2 = memdescGetPhysAddr(param_4,1,0);
  nvDbg_Printf("src/kernel/gpu/mmu/bar2_walk.c",0x1f7,"_bar2WalkCBLevelFree",1,
               "NVRM: PA 0x%llX for VA 0x%llX-0x%llX\n",uVar2,-(1L << (cVar1 + 1U & 0x3f)) & param_3
              );
  memdescFree(param_4);
  memdescDestroy(param_4);
  return;
}


// ===== 00402a90 _bar2WalkCBLevelAlloc =====

/* WARNING: Type propagation algorithm not settling */

int _bar2WalkCBLevelAlloc
              (long param_1,long param_2,undefined8 param_3,undefined8 param_4,char param_5,
              long *param_6,int *param_7,undefined1 *param_8)

{
  int *piVar1;
  char cVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  ulong uVar9;
  long lVar10;
  uint local_44;
  long local_40 [2];
  
  lVar3 = *(long *)(param_1 + 8);
  local_40[0] = 0;
  lVar4 = *(long *)(&DAT_00001b90 + lVar3);
  kmemsysGetStaticConfig_IMPL(lVar3,*(undefined8 *)(lVar3 + 0x1b70));
  lVar7 = vgpuGetCallingContextDevice(lVar3);
  if (lVar7 == 0) {
    local_44 = 0;
  }
  else {
    iVar5 = vgpuGetCallingContextGfid(lVar3,&local_44);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,"vgpuGetCallingContextGfid(pGpu, &gfid)","src/kernel/gpu/mmu/bar2_walk.c",
                 0x222);
      return iVar5;
    }
  }
  if (param_5 == '\0') {
    return 0;
  }
  if (*param_6 != 0) {
    return 0;
  }
  uVar9 = (ulong)local_44;
  lVar7 = uVar9 * 0xd8 + lVar4;
  cVar2 = *(char *)(lVar7 + 0x46a8);
  if (((cVar2 != '\0') || (*(char *)(lVar7 + 0x46a9) != '\0')) || (local_44 != 0)) {
LAB_00402b50:
    lVar7 = uVar9 * 0xd8 + lVar4;
    if (*(long *)(*(long *)(lVar7 + 0x46c0) + 8) == param_2) {
      *(undefined8 *)(lVar7 + 0x46dc) = 0;
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(lVar7 + 0x46e0);
    }
    lVar7 = uVar9 * 0xd8 + lVar4;
    if ((uint)(*(int *)(lVar7 + 0x46d0) + *(int *)(lVar7 + 0x46c8)) <=
        (uint)(iVar5 + *(int *)(lVar7 + 0x46dc))) {
      nvAssertFailedNoLog("pKernelBus->bar2[gfid].pageDirInit + pKernelBus->bar2[gfid].pageTblInit < pKernelBus->bar2[gfid].numPageDirs + pKernelBus->bar2[gfid].numPageTbls"
                          ,"src/kernel/gpu/mmu/bar2_walk.c",0x23a);
      return 0x40;
    }
    if ((*(char *)(lVar4 + 0xad08) == '\0') || (*(int *)(lVar4 + 0xad34) != 2)) {
      if ((cVar2 == '\0') && (local_44 == 0)) {
        if (*(char *)(lVar3 + 0x454) != '\0') goto LAB_00402f99;
        goto LAB_00402f50;
      }
      goto LAB_00402bbf;
    }
    if (cVar2 != '\0') {
      lVar10 = *(long *)(lVar7 + 0x4690);
      lVar7 = *(long *)(lVar7 + 0x46a0);
      goto LAB_00402bd7;
    }
LAB_00403150:
    lVar7 = uVar9 * 0xd8 + lVar4;
    if (*(char *)(lVar7 + 0x46a9) != '\0') goto LAB_00402bc9;
    nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/mmu/bar2_walk.c",0x24f);
LAB_0040317f:
    iVar6 = 0x38;
LAB_00403010:
    memdescFree(local_40[0]);
    memdescDestroy(local_40[0]);
    return iVar6;
  }
  if (*(char *)(lVar3 + 0x454) == '\0') {
    if (*(char *)(lVar4 + 0xad0c) != '\0') goto LAB_00402b50;
    if (*(char *)(lVar4 + 0xad08) != '\0') {
      if (*(int *)(lVar4 + 0xad34) == 2) goto LAB_00403150;
      goto LAB_00402f50;
    }
    uVar9 = 0;
    cVar2 = *(char *)(lVar4 + 0xad46);
  }
  else {
    if ((*(char *)(lVar3 + 0x4915) != '\0') || (*(char *)(lVar4 + 0xad0c) != '\0'))
    goto LAB_00402b50;
    if ((*(char *)(lVar4 + 0xad08) != '\0') && (*(int *)(lVar4 + 0xad34) == 2)) goto LAB_00403150;
LAB_00402f99:
    if (*(char *)(lVar3 + 0x4915) != '\0') goto LAB_00402bbf;
LAB_00402f50:
    if (*(char *)(lVar4 + 0xad46) != '\0') goto LAB_00402bbf;
    cVar2 = *(char *)(lVar4 + 0xad0c);
  }
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("pKernelBus->bar2[gfid].bBootstrap || IS_GFID_VF(gfid) || KBUS_BAR0_PRAMIN_DISABLED(pGpu) || kbusIsCpuVisibleBar2Disabled(pKernelBus) || kbusIsBarAccessBlocked(pKernelBus)"
                        ,"src/kernel/gpu/mmu/bar2_walk.c",0x254);
    uVar9 = (ulong)local_44;
  }
LAB_00402bbf:
  lVar7 = uVar9 * 0xd8 + lVar4;
LAB_00402bc9:
  lVar10 = *(long *)(lVar7 + 0x4658);
  lVar7 = *(long *)(lVar7 + 0x4668);
LAB_00402bd7:
  if (*(char *)(param_2 + 4) == '\0') {
    iVar5 = *(int *)(lVar4 + 0x46d4 + uVar9 * 0xd8);
    uVar8 = 0x2000000;
    uVar9 = (ulong)*(uint *)(lVar4 + 0xad30);
    iVar6 = memdescCreate(local_40,lVar3,iVar5,0x1000,1,*(undefined4 *)(lVar4 + 0xad2c));
    if (iVar6 != 0) {
      nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/mmu/bar2_walk.c",0x2c0,uVar8);
      goto LAB_00403010;
    }
    if (*(int *)(lVar4 + 0xad2c) == 1) {
      *(undefined4 *)(local_40[0] + 0x9c) = 0xb0;
      iVar6 = memdescAlloc(local_40[0],1,uVar9);
      if (iVar6 != 0) {
        nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/mmu/bar2_walk.c",0x2e1);
        goto LAB_00403010;
      }
    }
    else {
      memdescDescribe(local_40[0],*(int *)(lVar4 + 0xad2c),
                      (ulong)(uint)(iVar5 * *(int *)(lVar4 + 0x46e0 + (ulong)local_44 * 0xd8)) +
                      lVar7,iVar5);
    }
    uVar9 = (ulong)local_44;
    lVar7 = uVar9 * 0xd8 + lVar4;
    if (*(int *)(lVar7 + 0x46e0) == 0) {
      if ((*(char *)(lVar4 + 0xad08) == '\0') || (*(int *)(lVar4 + 0xad2c) != 2)) {
        if ((local_44 == 0) && (*(char *)(lVar7 + 0x46a8) == '\0')) {
          if ((((*(char *)(lVar3 + 0x454) == '\0') || (*(char *)(lVar3 + 0x4915) == '\0')) &&
              (*(char *)(lVar4 + 0xad46) == '\0')) && (*(char *)(lVar4 + 0xad0c) == '\0')) {
            nvAssertFailedNoLog("pKernelBus->bar2[gfid].bBootstrap || IS_GFID_VF(gfid) || KBUS_BAR0_PRAMIN_DISABLED(pGpu) || kbusIsCpuVisibleBar2Disabled(pKernelBus) || kbusIsBarAccessBlocked(pKernelBus)"
                                ,"src/kernel/gpu/mmu/bar2_walk.c",0x2fd);
            uVar9 = (ulong)local_44;
          }
          else {
            uVar9 = 0;
          }
        }
        uVar8 = memdescGetPhysAddr(local_40[0],1,0);
        *(undefined8 *)(lVar4 + 0x4668 + uVar9 * 0xd8) = uVar8;
      }
      else if (*(char *)(lVar7 + 0x46a8) == '\0') {
        if (*(char *)(lVar7 + 0x46a9) == '\0') {
          nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/mmu/bar2_walk.c",0x2f8);
          goto LAB_0040317f;
        }
        uVar8 = memdescGetPhysAddr(local_40[0],1,0);
        *(undefined8 *)(lVar7 + 0x4668) = uVar8;
      }
      else {
        uVar8 = memdescGetPhysAddr(local_40[0],1,0);
        *(undefined8 *)(lVar7 + 0x46a0) = uVar8;
      }
      uVar9 = (ulong)local_44;
      *(long *)(lVar4 + 0x7c90 + uVar9 * 0xb0) = local_40[0];
    }
    lVar7 = uVar9 * 0xd8 + lVar4;
    if ((((*(char *)(lVar7 + 0x46a8) != '\0') || (*(char *)(lVar7 + 0x46a9) != '\0')) ||
        ((local_44 != 0 ||
         ((*(char *)(lVar3 + 0x454) != '\0' && (*(char *)(lVar3 + 0x4915) != '\0')))))) ||
       (*(char *)(lVar4 + 0xad0c) != '\0')) {
      piVar1 = (int *)(lVar4 + 0x46e0 + uVar9 * 0xd8);
      *piVar1 = *piVar1 + 1;
    }
    goto LAB_00402cf0;
  }
  iVar5 = *(int *)(lVar4 + 0x46cc + uVar9 * 0xd8);
  iVar6 = memdescCreate(local_40,lVar3,iVar5,0x1000,1,*(undefined4 *)(lVar4 + 0xad34),
                        *(undefined4 *)(lVar4 + 0xad38),0x2000000);
  if (iVar6 != 0) {
    nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/mmu/bar2_walk.c",0x267);
    goto LAB_00403010;
  }
  if (*(int *)(lVar4 + 0xad34) == 1) {
    *(undefined4 *)(local_40[0] + 0x9c) = 0xaf;
    iVar6 = memdescAlloc();
    if (iVar6 != 0) {
      nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/mmu/bar2_walk.c",0x286);
      goto LAB_00403010;
    }
  }
  else {
    lVar7 = (ulong)local_44 * 0xd8 + lVar4;
    memdescDescribe(local_40[0],*(int *)(lVar4 + 0xad34),
                    (ulong)(uint)(*(int *)(lVar7 + 0x46dc) * *(int *)(lVar7 + 0x46cc)) + lVar10,
                    iVar5);
  }
  uVar9 = (ulong)local_44;
  lVar7 = uVar9 * 0xd8 + lVar4;
  if (*(long *)(*(long *)(lVar7 + 0x46c0) + 8) == param_2) {
    if ((*(char *)(lVar4 + 0xad08) == '\0') || (*(int *)(lVar4 + 0xad34) != 2)) {
      if ((local_44 == 0) && (*(char *)(lVar7 + 0x46a8) == '\0')) {
        if ((((*(char *)(lVar3 + 0x454) == '\0') || (*(char *)(lVar3 + 0x4915) == '\0')) &&
            (*(char *)(lVar4 + 0xad46) == '\0')) && (*(char *)(lVar4 + 0xad0c) == '\0')) {
          nvAssertFailedNoLog("pKernelBus->bar2[gfid].bBootstrap || IS_GFID_VF(gfid) || KBUS_BAR0_PRAMIN_DISABLED(pGpu) || kbusIsCpuVisibleBar2Disabled(pKernelBus) || kbusIsBarAccessBlocked(pKernelBus)"
                              ,"src/kernel/gpu/mmu/bar2_walk.c",0x2a7);
          uVar9 = (ulong)local_44;
        }
        else {
          uVar9 = 0;
        }
      }
      uVar8 = memdescGetPhysAddr(local_40[0],1,0);
      *(undefined8 *)(lVar4 + 0x4658 + uVar9 * 0xd8) = uVar8;
    }
    else {
      if (*(char *)(lVar7 + 0x46a8) != '\0') {
        uVar8 = memdescGetPhysAddr(local_40[0],1,0);
        uVar9 = (ulong)local_44;
        *(undefined8 *)(lVar7 + 0x4690) = uVar8;
        *(long *)(lVar4 + 0x4698 + uVar9 * 0xd8) = local_40[0];
        goto LAB_00402c97;
      }
      if (*(char *)(lVar7 + 0x46a9) == '\0') {
        nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/mmu/bar2_walk.c",0x2a2);
        goto LAB_0040317f;
      }
      uVar8 = memdescGetPhysAddr(local_40[0],1,0);
      *(undefined8 *)(lVar7 + 0x4658) = uVar8;
    }
    uVar9 = (ulong)local_44;
    *(long *)(lVar4 + 0x4660 + uVar9 * 0xd8) = local_40[0];
  }
LAB_00402c97:
  lVar7 = uVar9 * 0xd8 + lVar4;
  if ((((*(char *)(lVar7 + 0x46a8) != '\0') || (*(char *)(lVar7 + 0x46a9) != '\0')) ||
      ((local_44 != 0 || ((*(char *)(lVar3 + 0x454) != '\0' && (*(char *)(lVar3 + 0x4915) != '\0')))
       ))) || (*(char *)(lVar4 + 0xad0c) != '\0')) {
    piVar1 = (int *)(lVar4 + 0x46dc + uVar9 * 0xd8);
    *piVar1 = *piVar1 + 1;
  }
LAB_00402cf0:
  *param_6 = local_40[0];
  *param_7 = iVar5;
  *param_8 = 1;
  return 0;
}


// ===== 00403370 faultbufCtrlCmdFaultbufferGetSize_IMPL =====

undefined8 faultbufCtrlCmdFaultbufferGetSize_IMPL(long param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)
              (*(long *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x1b98) + 0x624);
  return 0;
}


// ===== 004033a0 faultbufCtrlCmdFaultbufferGetRegisterMappings_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void faultbufCtrlCmdFaultbufferGetRegisterMappings_IMPL(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1b98);
  (**(code **)(lVar2 + 0x2a0))
            (lVar1,lVar2,*(undefined4 *)(param_2 + 0x40),param_2,param_2 + 8,param_2 + 0x10,
             param_2 + 0x18,param_2 + 0x20,param_2 + 0x28,param_2 + 0x30,param_2 + 0x38);
  return;
}


// ===== 00403400 _gmmuGetFmtPte =====

undefined8 _gmmuGetFmtPte(long param_1)

{
  return *(undefined8 *)(param_1 + 0x20);
}


// ===== 00403410 _gmmuSwToHwLevel =====

int _gmmuSwToHwLevel(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *param_1;
  if (iVar1 == 2) {
    iVar1 = 3 - param_2;
    if (3 < param_2) {
      nvAssertFailedNoLog("level < 4","src/kernel/gpu/mmu/gmmu_trace.c",0x218);
      iVar1 = 0;
    }
  }
  else if (iVar1 == 3) {
    uVar2 = (*(char *)(*(long *)(param_1 + 2) + 1) == '8') + 4;
    iVar1 = (uVar2 - param_2) + -1;
    if (uVar2 <= param_2) {
      nvAssertFailedNoLog("level < maxV3Levels","src/kernel/gpu/mmu/gmmu_trace.c",0x215);
      iVar1 = 0;
    }
  }
  else if (iVar1 == 1) {
    iVar1 = 0;
    if (param_2 != 0) {
      nvAssertFailedNoLog("level == 0","src/kernel/gpu/mmu/gmmu_trace.c",0x21b);
      iVar1 = 0;
    }
  }
  else {
    nvAssertFailedNoLog(&DAT_00d66e81,"src/kernel/gpu/mmu/gmmu_trace.c",0x21e);
    iVar1 = 0;
  }
  return iVar1;
}


// ===== 004034f0 _gmmuPteAddrSpace =====

char _gmmuPteAddrSpace(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  
  if (*(byte *)(param_1 + 0x24) != 0) {
    lVar2 = 0;
    do {
      if ((*(char *)(*(long *)(param_1 + 0x28) + lVar2 * 2) != '\0') &&
         ((*(uint *)(param_2 + (ulong)*(ushort *)(param_1 + 0x22)) & *(uint *)(param_1 + 0x18)) >>
          ((byte)*(undefined2 *)(param_1 + 0x20) & 0x1f) ==
          (uint)*(byte *)(*(long *)(param_1 + 0x28) + 1 + lVar2 * 2))) {
        uVar1 = (uint)lVar2;
        if (uVar1 < 3) {
          return (uVar1 != 0) * '\x02';
        }
        if (uVar1 - 3 < 2) {
          return '\x01';
        }
        nvAssertFailedNoLog(&DAT_00d66e81,"src/kernel/gpu/mmu/gmmu_trace.c",0x202);
        return '\0';
      }
      lVar2 = lVar2 + 1;
    } while ((uint)lVar2 < (uint)*(byte *)(param_1 + 0x24));
  }
  return '\0';
}


// ===== 00403590 _gmmuPdeAddrSpace =====

undefined8 _gmmuPdeAddrSpace(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  
  if (*(byte *)(param_1 + 0x14) != 0) {
    lVar2 = 0;
    do {
      if ((*(char *)(*(long *)(param_1 + 0x18) + lVar2 * 2) != '\0') &&
         ((*(uint *)(param_2 + (ulong)*(ushort *)(param_1 + 0x12)) & *(uint *)(param_1 + 8)) >>
          ((byte)*(undefined2 *)(param_1 + 0x10) & 0x1f) ==
          (uint)*(byte *)(*(long *)(param_1 + 0x18) + 1 + lVar2 * 2))) {
        uVar1 = (uint)lVar2;
        if (uVar1 == 1) {
          return 2;
        }
        if (uVar1 < 2) {
          return 0;
        }
        if (1 < uVar1 - 3) {
          nvAssertFailedNoLog(&DAT_00d66e81,"src/kernel/gpu/mmu/gmmu_trace.c",0x1e8);
          return 0;
        }
        return 1;
      }
      lVar2 = lVar2 + 1;
    } while ((uint)lVar2 < (uint)*(byte *)(param_1 + 0x14));
  }
  return 0;
}


// ===== 00403620 _gmmuIsInvalidPdeOk =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

bool _gmmuIsInvalidPdeOk(long param_1,int *param_2,long param_3,long param_4,int param_5)

{
  int iVar1;
  long lVar2;
  uint local_c;
  
  if (*param_2 != 3) {
    if ((char)param_2[10] != '\0') {
      return param_5 != 0 ||
             (char)((*(uint *)(param_4 + (ulong)*(ushort *)(param_3 + 0xea)) &
                    *(uint *)(param_3 + 0xe0)) >> ((byte)*(undefined2 *)(param_3 + 0xe8) & 0x1f)) ==
             *(char *)(param_3 + 0xec);
    }
    return true;
  }
  local_c = 0;
  if (*(byte *)(param_3 + 0x14) != 0) {
    lVar2 = 0;
    do {
      if ((*(char *)(*(long *)(param_3 + 0x18) + lVar2 * 2) != '\0') &&
         ((*(uint *)(param_4 + (ulong)*(ushort *)(param_3 + 0x12)) & *(uint *)(param_3 + 8)) >>
          ((byte)*(undefined2 *)(param_3 + 0x10) & 0x1f) ==
          (uint)*(byte *)(*(long *)(param_3 + 0x18) + 1 + lVar2 * 2))) goto LAB_004036e9;
      lVar2 = lVar2 + 1;
    } while ((uint)lVar2 < (uint)*(byte *)(param_3 + 0x14));
  }
  lVar2 = 0;
LAB_004036e9:
  iVar1 = (**(code **)(*(long *)(param_1 + 0x1b98) + 0x298))
                    (*(long *)(param_1 + 0x1b98),
                     (*(uint *)(param_4 + (ulong)*(ushort *)(param_3 + 0xfa)) &
                     *(uint *)(param_3 + 0xf0)) >> ((byte)*(undefined2 *)(param_3 + 0xf8) & 0x1f),
                     lVar2,&local_c);
  if (iVar1 != 0) {
    nvAssertFailedNoLog("kgmmuTranslatePdePcfFromHw_HAL(pKernelGmmu, pdePcfHw, gmmuFieldGetAperture(&pFmtPde->fldAperture, pGmmuEntry->v8), &pdePcfSw) == NV_OK"
                        ,"src/kernel/gpu/mmu/gmmu_trace.c",0x1c3);
  }
  return (char)param_2[10] == '\0' || (param_5 != 0 || (local_c & 4) == 0);
}


// ===== 00403760 _gmmuPrintPa =====

void _gmmuPrintPa(long param_1,uint param_2,undefined4 param_3)

{
  nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0xab,"_gmmuPrintPa",1,&DAT_00d66f0f,
               *(undefined8 *)(_decodeAperture + (ulong)param_2 * 8));
  if (param_2 == 2) {
    nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0xb1,"_gmmuPrintPa",1,&DAT_00d66f12,param_3);
  }
  else if ((param_2 == 0) && (param_1 == 0)) {
    nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0xb6,"_gmmuPrintPa",1,&DAT_00d66f17);
    return;
  }
  nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0xba,"_gmmuPrintPa",1,"[0x%08llx] ",param_1);
  return;
}


// ===== 00403850 _gmmuPrintPdb =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _gmmuPrintPdb(long param_1,long *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar2 = (**(code **)(*param_2 + 200))(param_2,param_1);
  uVar1 = kgmmuGetMemAperture_IMPL(*(undefined8 *)(param_1 + 0x1b98),uVar2);
  nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0xcd,"_gmmuPrintPdb",1,
               "NVRM: MMUTRACE: VA[0x%08llx-%08llx] PDB: ",param_3,param_4);
  uVar2 = memdescGetPtePhysAddr(uVar2,param_2[10],0);
  _gmmuPrintPa(uVar2,uVar1,0);
  nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0xd1,"_gmmuPrintPdb",1,&DAT_00d66f52);
  return;
}


// ===== 00403920 _gmmuGetPtePa =====

long _gmmuGetPtePa(undefined8 param_1,long param_2,long param_3)

{
  uint *puVar1;
  ulong uVar2;
  uint *puVar3;
  long lVar4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  
  if (*(byte *)(param_2 + 0x24) != 0) {
    uVar2 = 0;
    do {
      if ((*(char *)(*(long *)(param_2 + 0x28) + uVar2 * 2) != '\0') &&
         ((*(uint *)(param_3 + (ulong)*(ushort *)(param_2 + 0x22)) & *(uint *)(param_2 + 0x18)) >>
          ((byte)*(undefined2 *)(param_2 + 0x20) & 0x1f) ==
          (uint)*(byte *)(*(long *)(param_2 + 0x28) + 1 + uVar2 * 2))) {
        if ((int)uVar2 == 0) {
          return 0xf;
        }
        puVar3 = (uint *)gmmuFmtPtePhysAddrFld(param_2,uVar2 & 0xffffffff,0);
        lVar4 = 0xf;
        if (puVar3 != (uint *)0x0) {
          uVar2 = 0;
          if (*puVar3 != 0) {
            puVar5 = puVar3;
            iVar7 = 0;
            do {
              puVar6 = puVar5 + 6;
              puVar1 = puVar5 + 4;
              uVar2 = uVar2 | ((*(ulong *)(param_3 + (ulong)puVar5[6]) & *(ulong *)(puVar5 + 2)) >>
                              ((byte)puVar5[5] & 0x3f)) << ((byte)iVar7 & 0x3f);
              puVar5 = puVar6;
              iVar7 = iVar7 + *puVar1;
            } while (puVar3 + (ulong)*puVar3 * 6 != puVar6);
          }
          lVar4 = uVar2 << ((byte)puVar3[0xe] & 0x3f);
        }
        return lVar4;
      }
      uVar2 = uVar2 + 1;
    } while ((uint)uVar2 < (uint)*(byte *)(param_2 + 0x24));
  }
  return 0xf;
}


// ===== 004039e0 _gmmuPrintPte =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _gmmuPrintPte(long param_1,byte *param_2,int *param_3,long param_4,undefined4 param_5)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  uint uVar6;
  uint local_3c [3];
  
  uVar4 = _gmmuGetPtePa(param_1,param_3,param_4);
  if (*(byte *)(param_3 + 9) != 0) {
    uVar5 = 0;
    do {
      if ((*(char *)(*(long *)(param_3 + 10) + uVar5 * 2) != '\0') &&
         ((*(uint *)(param_4 + (ulong)*(ushort *)((long)param_3 + 0x22)) & param_3[6]) >>
          ((byte)(short)param_3[8] & 0x1f) ==
          (uint)*(byte *)(*(long *)(param_3 + 10) + 1 + uVar5 * 2))) goto LAB_00403a59;
      uVar5 = uVar5 + 1;
    } while ((uint)uVar5 < (uint)*(byte *)(param_3 + 9));
  }
  uVar5 = 0;
LAB_00403a59:
  iVar3 = param_3[0x3e];
  uVar6 = *(uint *)(param_4 + (ulong)*(ushort *)((long)param_3 + 0xfa));
  uVar2 = param_3[0x3c];
  bVar1 = *param_2;
  if (bVar1 == 0x15) {
    nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x172,"_gmmuPrintPte",1,"PTE_2M");
    goto LAB_00403b20;
  }
  if ((ulong)(1L << (bVar1 & 0x3f)) < 0x200001) {
    if (bVar1 == 0x10) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x178,"_gmmuPrintPte",1,"PTE_64K");
      goto LAB_00403b20;
    }
    if (bVar1 == 0x11) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x175,"_gmmuPrintPte",1,"PTE_128K");
      goto LAB_00403b20;
    }
    if (bVar1 == 0xc) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x17b,"_gmmuPrintPte",1,"PTE_4K");
      goto LAB_00403b20;
    }
  }
  else {
    if (bVar1 == 0x1d) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x16f,"_gmmuPrintPte",1,"PTE_512M");
      goto LAB_00403b20;
    }
    if (bVar1 == 0x26) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x16c,"_gmmuPrintPte",1,"PTE_256G");
      goto LAB_00403b20;
    }
  }
  nvAssertFailedNoLog(&DAT_00d66e81,"src/kernel/gpu/mmu/gmmu_trace.c",0x17e);
LAB_00403b20:
  nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x182,"_gmmuPrintPte",1,"[0x%x]: ",param_5);
  _gmmuPrintPa(uVar4,uVar5 & 0xffffffff,(uVar6 & uVar2) >> ((byte)(short)iVar3 & 0x1f));
  uVar6 = param_3[1];
  if (*param_3 == 3) {
    local_3c[0] = 0;
    if (uVar6 != 0) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x18a,"_gmmuPrintPte",1,"Vld=%d, ",
                   (byte)((uVar6 & *(uint *)(param_4 + (ulong)*(ushort *)((long)param_3 + 0xe))) >>
                         ((byte)(short)param_3[3] & 0x1f)) ^ *(byte *)(param_3 + 4));
    }
    if (param_3[0x5f] != 0) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x18b,"_gmmuPrintPte",1,"Kind=0x%x, ",
                   (param_3[0x5f] & *(uint *)(param_4 + (ulong)*(ushort *)((long)param_3 + 0x186)))
                   >> ((byte)(short)param_3[0x61] & 0x1f));
    }
    uVar6 = 0;
    if (param_3[0x68] != 0) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x18c,"_gmmuPrintPte",1,"PtePcf=%d",
                   (param_3[0x68] & *(uint *)(param_4 + (ulong)*(ushort *)((long)param_3 + 0x1aa)))
                   >> ((byte)(short)param_3[0x6a] & 0x1f));
      uVar6 = param_3[0x68];
    }
    iVar3 = (**(code **)(*(long *)(param_1 + 0x1b98) + 0x288))
                      (*(long *)(param_1 + 0x1b98),
                       (uVar6 & *(uint *)(param_4 + (ulong)*(ushort *)((long)param_3 + 0x1aa))) >>
                       ((byte)(short)param_3[0x6a] & 0x1f),
                       (byte)((*(uint *)(param_4 + (ulong)*(ushort *)((long)param_3 + 0xe)) &
                              param_3[1]) >> ((byte)(short)param_3[3] & 0x1f)) ^
                       *(byte *)(param_3 + 4),local_3c);
    if (iVar3 != 0) {
      nvAssertFailedNoLog("kgmmuTranslatePtePcfFromHw_HAL(GPU_GET_KERNEL_GMMU(pGpu), ptePcfHw, nvFieldGetBool(&pFmt->fldValid, pGmmuEntry->v8), &ptePcfSw) == NV_OK"
                          ,"src/kernel/gpu/mmu/gmmu_trace.c",0x18e);
    }
    nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x192,"_gmmuPrintPte",1,
                 "(Vol=%d, Priv=%d, RO=%d, Atomic=%d, ACE=%d)",local_3c[0] >> 5 & 1,
                 local_3c[0] >> 8 & 1 ^ 1,local_3c[0] >> 7 & 1,local_3c[0] >> 6 & 1 ^ 1,
                 local_3c[0] >> 4 & 1);
  }
  else {
    if (uVar6 != 0) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x19c,"_gmmuPrintPte",1,"Vld=%d, ",
                   (byte)((uVar6 & *(uint *)(param_4 + (ulong)*(ushort *)((long)param_3 + 0xe))) >>
                         ((byte)(short)param_3[3] & 0x1f)) ^ *(byte *)(param_3 + 4));
    }
    if (param_3[0x4f] != 0) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x19d,"_gmmuPrintPte",1,"Priv=%d, ",
                   (byte)((param_3[0x4f] &
                          *(uint *)(param_4 + (ulong)*(ushort *)((long)param_3 + 0x146))) >>
                         ((byte)(short)param_3[0x51] & 0x1f)) ^ *(byte *)(param_3 + 0x52));
    }
    if (param_3[0x43] != 0) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x19e,"_gmmuPrintPte",1,"RO=%d, ",
                   (byte)((param_3[0x43] &
                          *(uint *)(param_4 + (ulong)*(ushort *)((long)param_3 + 0x116))) >>
                         ((byte)(short)param_3[0x45] & 0x1f)) ^ *(byte *)(param_3 + 0x46));
    }
    if (param_3[0x47] != 0) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x19f,"_gmmuPrintPte",1,"RD=%d, ",
                   (byte)((param_3[0x47] &
                          *(uint *)(param_4 + (ulong)*(ushort *)((long)param_3 + 0x126))) >>
                         ((byte)(short)param_3[0x49] & 0x1f)) ^ *(byte *)(param_3 + 0x4a));
    }
    if (param_3[0x4b] != 0) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x1a0,"_gmmuPrintPte",1,"WD=%d, ",
                   (byte)((param_3[0x4b] &
                          *(uint *)(param_4 + (ulong)*(ushort *)((long)param_3 + 0x136))) >>
                         ((byte)(short)param_3[0x4d] & 0x1f)) ^ *(byte *)(param_3 + 0x4e));
    }
    if (param_3[0x53] != 0) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x1a1,"_gmmuPrintPte",1,"Enc=%d, ",
                   (byte)((param_3[0x53] &
                          *(uint *)(param_4 + (ulong)*(ushort *)((long)param_3 + 0x156))) >>
                         ((byte)(short)param_3[0x55] & 0x1f)) ^ *(byte *)(param_3 + 0x56));
    }
    if (param_3[0x3f] != 0) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x1a2,"_gmmuPrintPte",1,"Vol=%d, ",
                   (byte)((param_3[0x3f] &
                          *(uint *)(param_4 + (ulong)*(ushort *)((long)param_3 + 0x106))) >>
                         ((byte)(short)param_3[0x41] & 0x1f)) ^ *(byte *)(param_3 + 0x42));
    }
    if (param_3[0x57] != 0) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x1a3,"_gmmuPrintPte",1,"Lock=%d, ",
                   (byte)((param_3[0x57] &
                          *(uint *)(param_4 + (ulong)*(ushort *)((long)param_3 + 0x166))) >>
                         ((byte)(short)param_3[0x59] & 0x1f)) ^ *(byte *)(param_3 + 0x5a));
    }
    if (param_3[0x5b] != 0) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x1a4,"_gmmuPrintPte",1,"AtomDis=%d, ",
                   (byte)((param_3[0x5b] &
                          *(uint *)(param_4 + (ulong)*(ushort *)((long)param_3 + 0x176))) >>
                         ((byte)(short)param_3[0x5d] & 0x1f)) ^ *(byte *)(param_3 + 0x5e));
    }
    if (param_3[0x5f] != 0) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x1a5,"_gmmuPrintPte",1,"Kind=0x%x, ",
                   (param_3[0x5f] & *(uint *)(param_4 + (ulong)*(ushort *)((long)param_3 + 0x186)))
                   >> ((byte)(short)param_3[0x61] & 0x1f));
    }
    if (param_3[0x62] != 0) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x1a6,"_gmmuPrintPte",1,"CTL=0x%x, ",
                   (param_3[0x62] & *(uint *)(param_4 + (ulong)*(ushort *)((long)param_3 + 0x192)))
                   >> ((byte)(short)param_3[100] & 0x1f));
    }
    if (param_3[0x65] != 0) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x1a7,"_gmmuPrintPte",1,"CTL_MSB=%d, ",
                   (param_3[0x65] & *(uint *)(param_4 + (ulong)*(ushort *)((long)param_3 + 0x19e)))
                   >> ((byte)(short)param_3[0x67] & 0x1f));
    }
  }
  nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x1a9,"_gmmuPrintPte",1,&DAT_00d66f52);
  return;
}


// ===== 004041f0 _gmmuGetPdePa =====

long _gmmuGetPdePa(undefined8 param_1,long param_2,long param_3)

{
  uint *puVar1;
  ulong uVar2;
  uint *puVar3;
  long lVar4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  
  if (*(byte *)(param_2 + 0x14) != 0) {
    uVar2 = 0;
    do {
      if ((*(char *)(*(long *)(param_2 + 0x18) + uVar2 * 2) != '\0') &&
         ((*(uint *)(param_3 + (ulong)*(ushort *)(param_2 + 0x12)) & *(uint *)(param_2 + 8)) >>
          ((byte)*(undefined2 *)(param_2 + 0x10) & 0x1f) ==
          (uint)*(byte *)(*(long *)(param_2 + 0x18) + 1 + uVar2 * 2))) {
        if ((int)uVar2 == 0) {
          return 0xf;
        }
        puVar3 = (uint *)gmmuFmtPdePhysAddrFld(param_2,uVar2 & 0xffffffff);
        lVar4 = 0xf;
        if (puVar3 != (uint *)0x0) {
          uVar2 = 0;
          if (*puVar3 != 0) {
            puVar5 = puVar3;
            iVar7 = 0;
            do {
              puVar6 = puVar5 + 6;
              puVar1 = puVar5 + 4;
              uVar2 = uVar2 | ((*(ulong *)(param_3 + (ulong)puVar5[6]) & *(ulong *)(puVar5 + 2)) >>
                              ((byte)puVar5[5] & 0x3f)) << ((byte)iVar7 & 0x3f);
              puVar5 = puVar6;
              iVar7 = iVar7 + *puVar1;
            } while (puVar3 + (ulong)*puVar3 * 6 != puVar6);
          }
          lVar4 = uVar2 << ((byte)puVar3[0xe] & 0x3f);
        }
        return lVar4;
      }
      uVar2 = uVar2 + 1;
    } while ((uint)uVar2 < (uint)*(byte *)(param_2 + 0x14));
  }
  return 0xf;
}


// ===== 004042b0 _gmmuPrintPt =====

void _gmmuPrintPt(undefined8 param_1,byte *param_2,long param_3,long param_4)

{
  byte bVar1;
  long lVar2;
  long lVar3;
  undefined4 uVar4;
  
  lVar2 = _gmmuGetPdePa(param_1,param_3,param_4);
  if (*(byte *)(param_3 + 0x14) != 0) {
    lVar3 = 0;
    do {
      if ((*(char *)(*(long *)(param_3 + 0x18) + lVar3 * 2) != '\0') &&
         ((*(uint *)(param_4 + (ulong)*(ushort *)(param_3 + 0x12)) & *(uint *)(param_3 + 8)) >>
          ((byte)*(undefined2 *)(param_3 + 0x10) & 0x1f) ==
          (uint)*(byte *)(*(long *)(param_3 + 0x18) + 1 + lVar3 * 2))) {
        uVar4 = (undefined4)lVar3;
        goto LAB_0040431d;
      }
      lVar3 = lVar3 + 1;
    } while ((uint)lVar3 < (uint)*(byte *)(param_3 + 0x14));
  }
  uVar4 = 0;
LAB_0040431d:
  bVar1 = *param_2;
  lVar3 = 0;
  if (lVar2 != 0xf) {
    lVar3 = lVar2;
  }
  if (bVar1 == 0x11) {
    nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x145,"_gmmuPrintPt",1,"PT_128K: ");
    goto LAB_00404380;
  }
  if ((ulong)(1L << (bVar1 & 0x3f)) < 0x20001) {
    if (bVar1 == 0xc) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x14b,"_gmmuPrintPt",1,"PT_4K:   ");
      goto LAB_00404380;
    }
    if (bVar1 == 0x10) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x148,"_gmmuPrintPt",1,"PT_64K:  ");
      goto LAB_00404380;
    }
  }
  else if (bVar1 == 0x15) goto LAB_00404380;
  nvAssertFailedNoLog(&DAT_00d66e81,"src/kernel/gpu/mmu/gmmu_trace.c",0x14e);
LAB_00404380:
  _gmmuPrintPa(lVar3,uVar4,0);
  nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x152,"_gmmuPrintPt",1,&DAT_00d66f52);
  return;
}


// ===== 00404460 _gmmuPrintPde =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _gmmuPrintPde(long param_1,int *param_2,long param_3,long param_4)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  long lVar6;
  char *pcVar7;
  uint *puVar8;
  uint local_2c;
  
  if (*(byte *)(param_3 + 4) < 2) {
    lVar6 = *(long *)(param_2 + 4);
    if (*(byte *)(lVar6 + 0x14) != 0) {
      uVar4 = 0;
      do {
        if ((*(char *)(*(long *)(lVar6 + 0x18) + uVar4 * 2) != '\0') &&
           ((*(uint *)(param_4 + (ulong)*(ushort *)(lVar6 + 0x12)) & *(uint *)(lVar6 + 8)) >>
            ((byte)*(undefined2 *)(lVar6 + 0x10) & 0x1f) ==
            (uint)*(byte *)(*(long *)(lVar6 + 0x18) + 1 + uVar4 * 2))) {
          uVar4 = uVar4 & 0xffffffff;
          goto LAB_004044de;
        }
        uVar4 = uVar4 + 1;
      } while ((uint)uVar4 < (uint)*(byte *)(lVar6 + 0x14));
    }
    uVar4 = 0;
LAB_004044de:
    uVar5 = _gmmuGetPdePa(param_1,lVar6,param_4);
    _gmmuPrintPa(uVar5,uVar4,0);
    if (*param_2 == 3) {
      local_2c = 0;
      uVar2 = 0;
      if (*(uint *)(lVar6 + 0xf0) != 0) {
        nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x113,"_gmmuPrintPde",1,"PdePcf=%d",
                     (*(uint *)(lVar6 + 0xf0) &
                     *(uint *)(param_4 + (ulong)*(ushort *)(lVar6 + 0xfa))) >>
                     ((byte)*(undefined2 *)(lVar6 + 0xf8) & 0x1f));
        uVar2 = *(uint *)(lVar6 + 0xf0);
      }
      iVar3 = (**(code **)(*(long *)(param_1 + 0x1b98) + 0x298))
                        (*(long *)(param_1 + 0x1b98),
                         (uVar2 & *(uint *)(param_4 + (ulong)*(ushort *)(lVar6 + 0xfa))) >>
                         ((byte)*(undefined2 *)(lVar6 + 0xf8) & 0x1f),uVar4,&local_2c);
      if (iVar3 != 0) {
        nvCheckFailedNoLog(1,
                           "kgmmuTranslatePdePcfFromHw_HAL(GPU_GET_KERNEL_GMMU(pGpu), pdePcfHw, aperture, &pdePcfSw) == NV_OK"
                           ,"src/kernel/gpu/mmu/gmmu_trace.c",0x115);
      }
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x11a,"_gmmuPrintPde",1,
                   "(Sparse=%d, Vol=%d, ATS=%d)",local_2c >> 2 & 1,local_2c >> 5 & 1,
                   local_2c >> 9 & 1);
    }
    else if (*(uint *)(lVar6 + 0xe0) != 0) {
      nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x123,"_gmmuPrintPde",1,"Vol=%d",
                   (byte)((*(uint *)(lVar6 + 0xe0) &
                          *(uint *)(param_4 + (ulong)*(ushort *)(lVar6 + 0xea))) >>
                         ((byte)*(undefined2 *)(lVar6 + 0xe8) & 0x1f)) ^ *(byte *)(lVar6 + 0xec));
    }
    uVar5 = 0x126;
    pcVar7 = "\n";
  }
  else {
    puVar1 = *(uint **)(param_2 + 6);
    nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0xea,"_gmmuPrintPde",1,"(Dual) ");
    if (*(byte *)(param_3 + 4) != 0) {
      puVar8 = puVar1 + 6;
      do {
        if ((byte)puVar8[3] != 0) {
          lVar6 = 0;
          do {
            if ((*(char *)(*(long *)(puVar8 + 4) + lVar6 * 2) != '\0') &&
               ((*(uint *)(param_4 + (ulong)*(ushort *)((long)puVar8 + 10)) & *puVar8) >>
                ((byte)(short)puVar8[2] & 0x1f) ==
                (uint)*(byte *)(*(long *)(puVar8 + 4) + 1 + lVar6 * 2))) {
              if ((int)lVar6 != 0) {
                if (*puVar1 != 0) {
                  nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",0x101,"_gmmuPrintPde",1,"Size=1/%c"
                               ,(int)*(char *)((long)&_decodeSize +
                                              (ulong)((*puVar1 &
                                                      *(uint *)(param_4 +
                                                               (ulong)*(ushort *)((long)puVar1 + 10)
                                                               )) >> ((byte)(short)puVar1[2] & 0x1f)
                                                     )));
                }
                pcVar7 = "\n";
                uVar5 = 0x104;
                goto LAB_00404585;
              }
              break;
            }
            lVar6 = lVar6 + 1;
          } while ((uint)lVar6 < (uint)(byte)puVar8[3]);
        }
        puVar8 = puVar8 + 0x40;
      } while (puVar1 + (ulong)(*(byte *)(param_3 + 4) - 1) * 0x40 + 0x46 != puVar8);
    }
    pcVar7 = "invalid\n";
    uVar5 = 0xf9;
  }
LAB_00404585:
  nvDbg_Printf("src/kernel/gpu/mmu/gmmu_trace.c",uVar5,"_gmmuPrintPde",1,pcVar7);
  return;
}


// ===== 004047f0 _gmmuGetFmtPde =====

void _gmmuGetFmtPde(void)

{
  gmmuFmtGetPde();
  return;
}


// ===== 00404800 _gmmuIsPte =====

undefined8 _gmmuIsPte(long param_1,undefined8 param_2,long param_3,byte *param_4)

{
  long lVar1;
  undefined8 uVar2;
  
  uVar2 = gmmuFmtEntryIsPte();
  if ((char)uVar2 == '\0') {
    return uVar2;
  }
  if (param_4 != (byte *)0x0) {
    lVar1 = *(long *)(param_1 + 0x20);
    *param_4 = (byte)((*(uint *)(param_3 + (ulong)*(ushort *)(lVar1 + 0xe)) & *(uint *)(lVar1 + 4))
                     >> ((byte)*(undefined2 *)(lVar1 + 0xc) & 0x1f)) ^ *(byte *)(lVar1 + 0x10);
  }
  return 1;
}


// ===== 00404870 _gmmuWalkCBUpdatePdb =====

undefined8 _gmmuWalkCBUpdatePdb(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  char *pcVar2;
  
  if (param_3 == 0) {
    pcVar2 = "null";
    uVar1 = 0;
  }
  else {
    uVar1 = memdescGetPtePhysAddr(param_3,1,0);
    pcVar2 = "valid";
  }
  nvDbg_Printf("src/kernel/gpu/mmu/gmmu_walk.c",0x25c,"_gmmuWalkCBUpdatePdb",1,
               "NVRM: [GPU%u]: PA 0x%llX (%s)\n",*(undefined4 *)(*(long *)(param_1 + 8) + 0x7a4),
               uVar1,pcVar2);
  return 1;
}


// ===== 004048f0 _gmmuWalkCBCopyEntries =====

void _gmmuWalkCBCopyEntries
               (long *param_1,long param_2,undefined8 param_3,undefined8 param_4,int param_5,
               int param_6,int *param_7)

{
  byte bVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  int iVar8;
  int local_80;
  undefined8 local_78;
  ulong local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_78 = 0;
  lVar2 = *(long *)(param_1[1] + 0x1b98);
  lVar5 = *(long *)(param_1[1] + 0x4a18);
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  if (lVar5 == 0) {
LAB_00404a20:
    if ((*(uint *)(*param_1 + 0xb8) & 0x80) == 0) {
      local_80 = 0;
      goto LAB_004049cf;
    }
  }
  else {
    lVar5 = __nvoc_dynamicCast(lVar5,__nvoc_class_def_FABRIC_VASPACE);
    if (lVar5 == 0) goto LAB_00404a20;
    lVar5 = __nvoc_dynamicCast(*(undefined8 *)(lVar5 + 0x98),__nvoc_class_def_OBJGVASPACE);
    if ((-1 < *(char *)(*param_1 + 0xb8)) && (*param_1 != lVar5)) {
      local_80 = 0;
      goto LAB_004049cf;
    }
  }
  local_80 = (uint)(*(char *)(lVar2 + 0x54c) != '\0') << 0xc;
LAB_004049cf:
  local_70 = (ulong)((uint)*(byte *)(param_2 + 2) * param_5);
  local_78 = param_3;
  local_58 = param_4;
  local_50 = local_70;
  cVar3 = memdescDescIsEqual(param_3,param_4);
  iVar8 = (param_6 + 1) - param_5;
  if (cVar3 == '\0') {
    lVar2 = param_1[1];
    bVar1 = *(byte *)(param_2 + 2);
    uVar6 = memdescGetPtePhysAddr(param_4,1,0);
    uVar7 = memdescGetPtePhysAddr(param_3,1,0);
    nvDbg_Printf("src/kernel/gpu/mmu/gmmu_walk.c",0x3da,"_gmmuWalkCBCopyEntries",1,
                 "NVRM: [GPU%u]: GVAS(%p) PA 0x%llX -> PA 0x%llX, Entries 0x%X-0x%X\n",
                 *(undefined4 *)(lVar2 + 0x7a4),*param_1,uVar7,uVar6,param_5,param_6);
    iVar4 = memmgrMemCopy_IMPL(*(undefined8 *)(lVar2 + 0x1b78),&local_58,&local_78,
                               (uint)bVar1 * iVar8,local_80);
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog
                (iVar4,
                 "memmgrMemCopy(GPU_GET_MEMORY_MANAGER(pGpu), &dest, &src, sizeOfEntries, transferFlags)"
                 ,"src/kernel/gpu/mmu/gmmu_walk.c",0x3e1);
    }
  }
  *param_7 = iVar8;
  return;
}


// ===== 00404b30 _gmmuWalkCBFillEntries =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _gmmuWalkCBFillEntries
               (long *param_1,char *param_2,undefined8 param_3,uint param_4,uint param_5,
               uint param_6,int *param_7)

{
  int iVar1;
  byte bVar2;
  long lVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  char cVar6;
  uint uVar7;
  long lVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  undefined8 uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int local_6c;
  undefined8 local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar10 = param_1[1];
  lVar3 = *(long *)(lVar10 + 0x1b98);
  uVar12 = *(undefined8 *)(lVar10 + 0x1b78);
  puVar4 = *(undefined4 **)param_1[2];
  iVar1 = (param_5 - param_4) + 1;
  bVar2 = param_2[2];
  iVar14 = iVar1 * (uint)bVar2;
  if (*(long *)(lVar10 + 0x4a18) == 0) {
LAB_00404d1e:
    uVar7 = (uint)bVar2;
    uVar13 = uVar7;
    if ((*(byte *)(*param_1 + 0xb8) & 0x80) == 0) {
LAB_00404d2e:
      local_6c = 2;
      goto LAB_00404c0e;
    }
  }
  else {
    lVar8 = __nvoc_dynamicCast(*(long *)(lVar10 + 0x4a18),__nvoc_class_def_FABRIC_VASPACE);
    if (lVar8 == 0) {
      bVar2 = param_2[2];
      goto LAB_00404d1e;
    }
    lVar8 = __nvoc_dynamicCast(*(undefined8 *)(lVar8 + 0x98),__nvoc_class_def_OBJGVASPACE);
    bVar2 = param_2[2];
    uVar7 = (uint)bVar2;
    uVar13 = (uint)bVar2;
    if ((-1 < *(char *)(*param_1 + 0xb8)) && (*param_1 != lVar8)) goto LAB_00404d2e;
  }
  uVar7 = uVar13;
  local_6c = (-(uint)(*(char *)(lVar3 + 0x54c) == '\0') & 0xfffff000) + 0x1002;
LAB_00404c0e:
  local_50 = (ulong)(uVar7 * param_4);
  local_48 = 0;
  local_40 = 0;
  local_58 = param_3;
  lVar8 = memmgrMemBeginTransfer_IMPL(uVar12,&local_58,iVar14,local_6c);
  if (lVar8 == 0) {
    nvAssertFailedNoLog("pEntries != NULL","src/kernel/gpu/mmu/gmmu_walk.c",0x33a);
  }
  else {
    uVar5 = *(undefined8 *)(g_gmmuFillStateStrings + (ulong)param_6 * 8);
    uVar9 = memdescGetPtePhysAddr(param_3,1,0);
    nvDbg_Printf("src/kernel/gpu/mmu/gmmu_walk.c",0x33d,"_gmmuWalkCBFillEntries",1,
                 "NVRM: [GPU%u]: PA 0x%llX, Entries 0x%X-0x%X = %s\n",
                 *(undefined4 *)(param_1[1] + 0x7a4),uVar9,param_4,param_5,uVar5);
    if (param_6 == 1) {
      lVar11 = kgmmuFmtGetFamily_IMPL(lVar3,*puVar4);
      lVar10 = (**(code **)(lVar3 + 0x508))(lVar10,lVar3,param_2);
      if (lVar10 == 0) {
        lVar10 = lVar11 + 0x4e0;
        if ((byte)param_2[4] < 2) {
          lVar10 = lVar11 + 0x4c0;
          if (param_2[4] == 1) {
            lVar10 = lVar11 + 0x4d0;
          }
        }
      }
      if (param_4 <= param_5) {
        iVar15 = 0;
        do {
          bVar2 = param_2[2];
          uVar13 = (uint)bVar2 * iVar15;
          iVar15 = iVar15 + 1;
          portMemCopy((ulong)uVar13 + lVar8,bVar2,lVar10,bVar2);
        } while (param_4 + iVar15 <= param_5);
      }
    }
    else if (param_6 == 2) {
      lVar10 = kgmmuFmtGetFamily_IMPL(lVar3,*puVar4);
      cVar6 = (**(code **)(*(long *)*param_1 + 400))();
      uVar5 = g_gmmuFillStateStrings._16_8_;
      if ((cVar6 == '\0') || (*param_2 != '\x10')) {
        uVar12 = memdescGetPtePhysAddr(param_3,1,0);
        nvDbg_Printf("src/kernel/gpu/mmu/gmmu_walk.c",899,"_gmmuWalkCBFillEntries",4,
                     "NVRM: [GPU%u]: PA 0x%llX, Entries 0x%X-0x%X = %s FAIL\n",
                     *(undefined4 *)(param_1[1] + 0x7a4),uVar12,param_4,param_5,uVar5);
        return;
      }
      if (param_4 <= param_5) {
        iVar15 = 0;
        do {
          bVar2 = param_2[2];
          uVar13 = (uint)bVar2 * iVar15;
          iVar15 = iVar15 + 1;
          portMemCopy((ulong)uVar13 + lVar8,bVar2,lVar10 + 0x4f0,bVar2);
        } while (param_4 + iVar15 <= param_5);
      }
    }
    else if (param_6 == 0) {
      portMemSet(lVar8,0,iVar14);
    }
    else {
      nvAssertFailedNoLog(&DAT_00d67427,"src/kernel/gpu/mmu/gmmu_walk.c",0x3a2);
    }
    memmgrMemEndTransfer_IMPL(uVar12,&local_58,iVar14,local_6c);
    *param_7 = iVar1;
  }
  return;
}


// ===== 00404f20 _gmmuWalkCBUpdatePde =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _gmmuWalkCBUpdatePde(long *param_1,long param_2,ulong param_3,int param_4,long param_5)

{
  char *pcVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  int *piVar5;
  int *piVar6;
  ulong uVar7;
  char cVar8;
  char cVar9;
  byte bVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  long lVar14;
  long *plVar15;
  long *plVar16;
  undefined8 uVar17;
  long lVar18;
  uint *puVar19;
  ulong uVar20;
  uint uVar21;
  ulong uVar22;
  ulong uVar23;
  uint local_b4;
  ulong *local_a8;
  ulong local_68 [2];
  ulong local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar2 = param_1[1];
  plVar3 = (long *)*param_1;
  lVar4 = *(long *)(lVar2 + 0x1b98);
  piVar5 = *(int **)param_1[2];
  piVar6 = *(int **)(piVar5 + 6);
  plVar15 = (long *)0x0;
  plVar16 = plVar3;
  if (*(long *)(lVar2 + 0x4a18) != 0) {
    lVar14 = __nvoc_dynamicCast(*(long *)(lVar2 + 0x4a18),__nvoc_class_def_FABRIC_VASPACE);
    plVar15 = (long *)0x0;
    if (lVar14 != 0) {
      plVar15 = (long *)__nvoc_dynamicCast(*(undefined8 *)(lVar14 + 0x98),
                                           __nvoc_class_def_OBJGVASPACE);
    }
    plVar16 = (long *)*param_1;
  }
  if (((char)plVar16[0x17] < '\0') || (iVar13 = 0, plVar15 == plVar3)) {
    iVar13 = (uint)(*(char *)(lVar4 + 0x54c) != '\0') << 0xc;
  }
  uVar17 = memdescGetPtePhysAddr(param_3,1,0);
  nvDbg_Printf("src/kernel/gpu/mmu/gmmu_walk.c",0x2a2,"_gmmuWalkCBUpdatePde",1,
               "NVRM: [GPU%u]: PA 0x%llX, Entry 0x%X\n",*(undefined4 *)(param_1[1] + 0x7a4),uVar17,
               param_4);
  portMemSet(local_68,0,*(undefined1 *)(param_2 + 2));
  if (*(char *)(param_2 + 4) != '\0') {
    uVar23 = 0;
    local_b4 = 0xffffffff;
    do {
      lVar18 = gmmuFmtGetPde(piVar5,param_2,uVar23 & 0xffffffff);
      lVar14 = *(long *)(param_5 + uVar23 * 8);
      if (lVar14 == 0) {
        nvDbg_Printf("src/kernel/gpu/mmu/gmmu_walk.c",0x2ed,"_gmmuWalkCBUpdatePde",1,
                     "NVRM:     SubLevel %u = INVALID\n",uVar23 & 0xffffffff);
      }
      else {
        uVar11 = kgmmuGetMemAperture_IMPL(lVar4,lVar14);
        puVar19 = (uint *)gmmuFmtPdePhysAddrFld(lVar18,uVar11);
        uVar17 = memdescGetPtePhysAddr(lVar14,1,0);
        if (*piVar5 == 3) {
          local_58 = local_58 & 0xffffffff00000000;
          cVar8 = (**(code **)(*plVar3 + 400))(plVar3);
          cVar9 = memdescGetVolatility(lVar14);
          iVar12 = (**(code **)(lVar4 + 0x290))
                             (lVar4,(uint)(cVar9 != '\0') << 5 | (uint)(cVar8 != '\0') << 9,
                              &local_58);
          if (iVar12 != 0) {
            nvAssertFailedNoLog("(kgmmuTranslatePdePcfFromSw_HAL(pKernelGmmu, pdePcfSw, &pdePcfHw) == NV_OK)"
                                ,"src/kernel/gpu/mmu/gmmu_walk.c",0x2c1);
            return 0x1f;
          }
          *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar18 + 0xfa)) =
               (int)local_58 << ((byte)*(undefined2 *)(lVar18 + 0xf8) & 0x1f) |
               *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar18 + 0xfa)) &
               *(uint *)(lVar18 + 0xf4);
        }
        else {
          bVar10 = memdescGetVolatility(lVar14);
          *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar18 + 0xea)) =
               (uint)(bVar10 ^ *(byte *)(lVar18 + 0xec)) <<
               ((byte)*(undefined2 *)(lVar18 + 0xe8) & 0x1f) |
               *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar18 + 0xea)) &
               *(uint *)(lVar18 + 0xe4);
        }
        *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar18 + 0x12)) =
             (uint)*(byte *)(*(long *)(lVar18 + 0x18) + 1 + (ulong)uVar11 * 2) <<
             ((byte)*(undefined2 *)(lVar18 + 0x10) & 0x1f) |
             *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar18 + 0x12)) & *(uint *)(lVar18 + 0xc)
        ;
        uVar20 = kgmmuEncodePhysAddr_IMPL(lVar4,(ulong)uVar11,uVar17,0xffffffffffffffff);
        if (*puVar19 != 0) {
          uVar20 = uVar20 >> ((byte)puVar19[0xe] & 0x3f);
          uVar22 = 0;
          do {
            uVar11 = (int)uVar22 + 1;
            uVar7 = *(ulong *)((long)local_68 + (ulong)puVar19[uVar22 * 6 + 6]);
            *(ulong *)((long)local_68 + (ulong)puVar19[uVar22 * 6 + 6]) =
                 (uVar20 << ((byte)puVar19[uVar22 * 6 + 5] & 0x3f) ^ uVar7) &
                 *(ulong *)(puVar19 + uVar22 * 6 + 2) ^ uVar7;
            uVar20 = uVar20 >> ((byte)puVar19[uVar22 * 6 + 4] & 0x3f);
            uVar22 = (ulong)uVar11;
          } while (uVar11 < *puVar19);
        }
        uVar11 = local_b4;
        if ((((*(byte *)(plVar3 + 0x17) & 0x10) != 0) && (1 < *(byte *)(param_2 + 4))) &&
           (*piVar6 != 0)) {
          pcVar1 = (char *)(*(long *)(param_2 + 0x10) + uVar23 * 0x18);
          uVar20 = (ulong)((uint)(byte)pcVar1[2] << ((pcVar1[1] - *pcVar1) + 1U & 0x1f)) /
                   (*(ulong *)(lVar14 + 0x30) & 0xffffffff);
          uVar21 = (uint)(0xffff < (uint)uVar20) << 4 | (uint)((uVar20 & 0xaaaaaaaa) != 0) |
                   (uint)((uVar20 & 0xff00ff00) != 0) << 3 | (uint)((uVar20 & 0xf0f0f0f0) != 0) << 2
                   | (uint)((uVar20 & 0xcccccccc) != 0) * 2;
          uVar11 = (uint)*(ulong *)(lVar14 + 0x30);
          if ((uVar11 - 1 & uVar11) != 0) {
            nvAssertFailedNoLog("ONEBITSET(curMemSize)","src/kernel/gpu/mmu/gmmu_walk.c",0x2da);
          }
          uVar11 = uVar21;
          if ((local_b4 != 0xffffffff) && (uVar11 = local_b4, local_b4 != uVar21)) {
            nvAssertFailedNoLog("recipExp == minRecipExp","src/kernel/gpu/mmu/gmmu_walk.c",0x2e4);
          }
        }
        local_b4 = uVar11;
        nvDbg_Printf("src/kernel/gpu/mmu/gmmu_walk.c",0x2e8,"_gmmuWalkCBUpdatePde",1,
                     "NVRM:     SubLevel %u = PA 0x%llX\n",(int)uVar23,uVar17);
      }
      uVar23 = uVar23 + 1;
    } while ((uint)uVar23 < (uint)*(byte *)(param_2 + 4));
    if (local_b4 != 0xffffffff) {
      *(uint *)((long)local_68 + (ulong)*(ushort *)((long)piVar6 + 10)) =
           *(uint *)((long)local_68 + (ulong)*(ushort *)((long)piVar6 + 10)) & piVar6[1] |
           local_b4 << ((byte)(short)piVar6[2] & 0x1f);
    }
  }
  local_a8 = &local_58;
  local_48 = 0;
  local_50 = (ulong)((uint)*(byte *)(param_2 + 2) * param_4);
  local_40 = 0;
  local_58 = param_3;
  iVar13 = memmgrMemWrite_IMPL(*(undefined8 *)(lVar2 + 0x1b78),local_a8,local_68,
                               *(byte *)(param_2 + 2),iVar13);
  if (iVar13 != 0) {
    nvAssertOkFailedNoLog
              (iVar13,
               "memmgrMemWrite(GPU_GET_MEMORY_MANAGER(pGpu), &dest, entry.v8, pLevelFmt->entrySize, transferFlags)"
               ,"src/kernel/gpu/mmu/gmmu_walk.c",0x2fd);
  }
  return 1;
}


// ===== 004054d0 _gmmuWalkCBLevelFree =====

void _gmmuWalkCBLevelFree(long *param_1,long param_2,ulong param_3,long param_4)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (param_4 == 0) {
    return;
  }
  lVar2 = 1L << (*(char *)(param_2 + 1) + 1U & 0x3f);
  param_3 = -lVar2 & param_3;
  uVar3 = memdescGetPtePhysAddr(param_4,1,0);
  nvDbg_Printf("src/kernel/gpu/mmu/gmmu_walk.c",0x221,"_gmmuWalkCBLevelFree",1,
               "NVRM: [GPU%u]: PA 0x%llX for VA 0x%llX-0x%llX\n",*(undefined4 *)(param_1[1] + 0x7a4)
               ,uVar3,param_3,lVar2 + -1 + param_3);
  if (*(long *)(param_4 + 200) == 0) {
    if (*(long *)(param_4 + 0xb8) != 0) goto LAB_00405579;
  }
  else {
    if (*(int *)(param_4 + 0x90) == 1) {
      listAppendExisting_IMPL(*(undefined8 *)(*(long *)(param_4 + 200) + 0xe8),param_4);
      return;
    }
    if (*(long *)(param_4 + 0xb8) == 0) goto LAB_004055ab;
LAB_00405579:
    iVar1 = listCount_IMPL();
    if ((iVar1 != 0) && (*(long *)(param_1[2] + 0x30) != 0)) {
      rmMemPoolFree(*(long *)(param_1[2] + 0x30),param_4,*(undefined4 *)(*param_1 + 0xb8));
    }
    if (*(long *)(param_4 + 200) != 0) goto LAB_004055ab;
  }
  memdescFree(param_4);
LAB_004055ab:
  memdescDestroy(param_4);
  return;
}


// ===== 00405610 _gmmuWalkCBLevelAlloc =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _gmmuWalkCBLevelAlloc
              (long *param_1,byte *param_2,ulong param_3,ulong param_4,char param_5,ulong *param_6,
              uint *param_7,undefined1 *param_8)

{
  long lVar1;
  long lVar2;
  long lVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  int *piVar10;
  undefined8 uVar11;
  long lVar12;
  long lVar13;
  byte bVar14;
  uint uVar15;
  char *pcVar16;
  ulong uVar17;
  ulong extraout_RDX;
  ulong uVar18;
  uint uVar19;
  ulong uVar20;
  uint uVar21;
  undefined4 uVar22;
  ulong uVar23;
  uint local_88;
  ulong local_70;
  int local_68 [4];
  ulong local_58 [5];
  
  uVar6 = ((int)((~(-1L << (param_2[1] + 1 & 0x3f)) & -1L << (*param_2 & 0x3f) & param_4) >>
                (*param_2 & 0x3f)) + 1) * (uint)param_2[2];
  if (*param_6 == 0) {
    if (param_5 == '\0') {
      return 0;
    }
  }
  else if (uVar6 <= *param_7) {
    return 0;
  }
  lVar12 = *param_1;
  lVar13 = param_1[1];
  lVar1 = *(long *)param_1[2];
  lVar2 = *(long *)(lVar13 + 0x1b98);
  uVar5 = *(uint *)(lVar12 + 0xb8) & 0x4000;
  if ((*(byte **)(lVar1 + 8) == param_2) || (*(uint *)(param_2 + 8) < 5)) {
    uVar6 = (**(code **)(lVar2 + 0x1c8))(lVar2,param_2,*(undefined8 *)(lVar12 + 0x140));
    uVar23 = (ulong)uVar6;
    uVar18 = (ulong)*(uint *)(lVar12 + 0xb8);
    bVar14 = 0xfff < uVar6 | (byte)(uVar5 >> 0xe);
    uVar6 = *(uint *)(lVar12 + 0xb8) & 1;
    if (uVar6 == 0) {
      local_68[0] = *(int *)(lVar2 + 0x568);
      uVar22 = *(undefined4 *)(lVar2 + 0x56c);
      if ((local_68[0] == 1) || ((~*(uint *)(lVar13 + 0x4924) & 0x3000000) == 0)) {
        local_88 = 0x1000;
        uVar6 = 1;
      }
      else {
        local_68[1] = 1;
        uVar6 = 2;
        local_88 = 0x1000;
      }
    }
    else {
      local_68[0] = *(int *)(lVar2 + 0x570);
      local_88 = 0x1000;
      uVar22 = *(undefined4 *)(lVar2 + 0x574);
    }
  }
  else {
    lVar3 = param_1[3];
    puVar4 = *(uint **)(lVar1 + 0x18);
    lVar9 = mmuFmtFindLevelParent(*(byte **)(lVar1 + 8),param_2,local_58);
    if (lVar9 == 0) {
      nvAssertFailedNoLog("NULL != pParent","src/kernel/gpu/mmu/gmmu_walk.c",0xb0);
      return 0x1f;
    }
    piVar10 = (int *)gmmuFmtGetPde(lVar1,lVar9,local_58[0] & 0xffffffff);
    if (*piVar10 == 3) {
      bVar14 = (byte)piVar10[0x36];
    }
    else {
      bVar14 = (byte)piVar10[0x16];
    }
    local_88 = 1 << (bVar14 & 0x1f);
    uVar19 = (uint)param_2[2] << ((param_2[1] - *param_2) + 1 & 0x1f);
    uVar23 = (ulong)uVar19;
    if (((((*(byte *)(lVar12 + 0xb8) & 0x10) != 0) && (1 < *(byte *)(lVar9 + 4))) &&
        (uVar21 = *puVar4, uVar21 != 0)) && (*(uint *)(lVar12 + 0xf0) != 0)) {
      lVar9 = lVar12;
      do {
        if ((*(ulong *)(lVar9 + 200) <= param_3) &&
           (param_3 <= (*(ulong *)(lVar9 + 200) - 1) + *(long *)(lVar12 + 0xc0))) {
          uVar15 = uVar6 - 1 | uVar6 - 1 >> 1;
          uVar15 = uVar15 | uVar15 >> 2;
          uVar15 = uVar15 | uVar15 >> 4;
          uVar15 = uVar15 | uVar15 >> 8;
          uVar23 = uVar23 / ((uVar15 | uVar15 >> 0x10) + 1);
          uVar21 = uVar21 >> ((byte)(short)puVar4[2] & 0x1f);
          uVar15 = (uint)((uVar23 & 0xcccccccc) != 0) * 2 |
                   (uint)(0xffff < (uint)uVar23) << 4 | (uint)((uVar23 & 0xaaaaaaaa) != 0) |
                   (uint)((uVar23 & 0xff00ff00) != 0) << 3 | (uint)((uVar23 & 0xf0f0f0f0) != 0) << 2
          ;
          if (uVar15 <= uVar21) {
            uVar21 = uVar15;
          }
          uVar23 = (ulong)(uVar19 >> ((byte)uVar21 & 0x1f));
          bVar14 = 1;
          goto LAB_00405a1c;
        }
        lVar9 = lVar9 + 8;
      } while (lVar9 != lVar12 + (ulong)*(uint *)(lVar12 + 0xf0) * 8);
    }
    bVar14 = (byte)(uVar5 >> 0xe) | 0xfff < uVar19;
LAB_00405a1c:
    if ((uint)uVar23 < uVar6) {
      nvAssertFailedNoLog("newMemSize >= minMemSize","src/kernel/gpu/mmu/gmmu_walk.c",0xdf);
    }
    if ((uint)uVar23 <= *param_7) {
      nvAssertFailedNoLog("newMemSize > *pMemSize","src/kernel/gpu/mmu/gmmu_walk.c",0xe1);
    }
    uVar6 = *(uint *)(lVar12 + 0xb8);
    uVar18 = (ulong)uVar6;
    if ((uVar6 & 1) == 0) {
      iVar7 = *(int *)(lVar2 + 0x578);
      uVar22 = *(undefined4 *)(lVar2 + 0x57c);
      if (((~*(uint *)(lVar13 + 0x4924) & 3) == 0) || ((uVar6 & 0x800) != 0)) goto LAB_00405a4f;
      if ((lVar3 == 0) || ((*(byte *)(lVar3 + 0x10) & 2) == 0)) {
        uVar20 = 1;
        iVar8 = 0;
        local_68[0] = iVar7;
      }
      else {
        iVar8 = 1;
        uVar20 = 2;
        local_68[0] = 1;
        local_68[1] = iVar7;
      }
      if ((uVar6 & 0x20) != 0) {
        local_68[uVar20] = 1;
        uVar20 = (ulong)(iVar8 + 2);
      }
    }
    else {
      iVar7 = *(int *)(lVar2 + 0x580);
      uVar22 = *(undefined4 *)(lVar2 + 0x584);
LAB_00405a4f:
      uVar20 = 1;
      local_68[0] = iVar7;
    }
    uVar6 = (uint)uVar20;
  }
  local_68[uVar6] = 0;
  uVar20 = 0x1000;
  if (bVar14 != 0) {
    uVar20 = uVar23;
  }
  iVar7 = memdescCreate(&local_70,lVar13,uVar20,local_88,1,0,uVar22);
  if (iVar7 == 0) {
    memdescSetPageSize(local_70,1,0x1000);
    uVar6 = (uint)uVar23;
    if (local_68[0] == 0) {
LAB_00405bda:
      iVar7 = memdescGetAddressSpace(local_70);
      if (((iVar7 != 2) || (0xfff < local_88)) || (uVar5 != 0)) {
        lVar12 = 1L << (param_2[1] + 1 & 0x3f);
        uVar20 = -lVar12;
        lVar12 = lVar12 + -1 + (param_4 & uVar20);
        uVar11 = memdescGetPtePhysAddr(local_70,1,0);
        pcVar16 = "Unpacked";
        uVar18 = local_70;
        goto LAB_00405c47;
      }
      lVar12 = listHead_IMPL(param_1[2] + 0x18);
      do {
        uVar20 = local_70;
        if (lVar12 == 0) {
          if (local_70 == 0) {
            nvAssertFailedNoLog("(NULL != pMemDesc)","src/kernel/gpu/mmu/gmmu_walk.c",0x1b2);
            goto LAB_00405f3c;
          }
          if (*(ulong *)(local_70 + 0x38) < uVar23) {
            nvAssertFailedNoLog("(memSize <= pMemDesc->ActualSize)","src/kernel/gpu/mmu/gmmu_walk.c"
                                ,0x1b3);
            goto LAB_00405f3c;
          }
          lVar12 = *(long *)(local_70 + 0xe8);
          if (lVar12 == 0) {
            lVar12 = portMemAllocNonPaged(0x18);
            *(long *)(uVar20 + 0xe8) = lVar12;
            if (lVar12 == 0) {
              nvAssertFailedNoLog("pMemDesc->pSubMemDescList != NULL",
                                  "src/kernel/gpu/mmu/gmmu_walk.c",0x1b8);
              goto LAB_00405f3c;
            }
          }
          listInitIntrusive_IMPL(lVar12,0xf8);
          uVar18 = extraout_RDX;
          if (*(ulong *)(uVar20 + 0x38) < uVar23) goto LAB_004060ff;
          iVar7 = 0;
          uVar17 = 0;
          goto LAB_00405ef2;
        }
        lVar13 = listNext_IMPL(param_1[2] + 0x18,lVar12);
        uVar18 = listTail_IMPL(*(undefined8 *)(lVar12 + 0xe8));
        listRemoveIntrusive_IMPL(*(undefined8 *)(lVar12 + 0xe8),uVar18);
        lVar12 = lVar13;
      } while (uVar18 == 0);
      memdescFree(local_70);
      memdescDestroy(local_70);
      goto LAB_0040600f;
    }
    iVar7 = 0;
    uVar19 = 0;
    iVar8 = local_68[0];
    do {
      *(int *)(local_70 + 0x68) = iVar8;
      if (iVar8 == 1) {
LAB_004057e2:
        *(undefined4 *)(local_70 + 0x9c) = 0xb0;
        iVar7 = memdescAlloc();
      }
      else {
        if (iVar8 != 2) {
          nvAssertFailedNoLog(&DAT_00d67427,"src/kernel/gpu/mmu/gmmu_walk.c",0x145);
          if (iVar7 == 0) {
            return 0;
          }
          goto LAB_004058c1;
        }
        if ((*(byte *)(lVar12 + 0xb9) & 0x40) == 0) goto LAB_004057e2;
        if (*(long *)(param_1[2] + 0x30) == 0) {
          nvAssertFailedNoLog("pUserCtx->pGpuState->pPageTableMemPool != NULL",
                              "src/kernel/gpu/mmu/gmmu_walk.c",0x138);
          return 0x40;
        }
        *(ulong *)(local_70 + 0x38) = (ulong)((uVar6 - 1) + local_88 & -local_88);
        iVar7 = rmMemPoolAllocate(*(undefined8 *)(param_1[2] + 0x30),local_70);
      }
      if (iVar7 == 0) {
        if (*(byte **)(lVar1 + 8) == param_2) {
          local_58[1] = 0;
          local_58[2] = 0;
          local_58[3] = 0;
          local_58[0] = local_70;
          iVar7 = memmgrMemSet_IMPL(*(undefined8 *)(lVar13 + 0x1b78),local_58,0,
                                    *(undefined4 *)(local_70 + 0x30));
          if (iVar7 != 0) {
            nvAssertOkFailedNoLog
                      (iVar7,
                       "memmgrMemSet(GPU_GET_MEMORY_MANAGER(pGpu), &dest, 0, (NvU32)memdescGetSize(pMemDesc), TRANSFER_FLAGS_NONE)"
                       ,"src/kernel/gpu/mmu/gmmu_walk.c",0x52);
          }
        }
        uVar11 = mmuFmtConvertLevelIdToSuffix(param_2);
        memdescSetName(lVar13,local_70,"rm_page_table_surface",uVar11);
        if (iVar7 == 0) goto LAB_00405bda;
        break;
      }
      uVar19 = uVar19 + 1;
      iVar8 = local_68[uVar19 & 0xff];
    } while (iVar8 != 0);
    memdescDestroy(local_70);
  }
  else {
    nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/mmu/gmmu_walk.c",0x125,
                        (uint)(uVar18 >> 6) & 0x2000000);
  }
LAB_004058c1:
  memdescFree(0);
  local_70 = 0;
LAB_004058ce:
  memdescDestroy(local_70);
  return iVar7;
  while( true ) {
    iVar7 = iVar7 + uVar6;
    listAppendExisting_IMPL(*(undefined8 *)(uVar20 + 0xe8),local_58[0]);
    uVar17 = (ulong)((int)uVar17 + 1);
    uVar18 = *(ulong *)(uVar20 + 0x38) % uVar23;
    if (*(ulong *)(uVar20 + 0x38) / uVar23 <= uVar17) break;
LAB_00405ef2:
    local_58[0] = 0;
    iVar8 = memdescCreateSubMem(local_58,uVar20,param_1[1],iVar7,uVar23);
    if (iVar8 != 0) {
      nvAssertFailedNoLog("(NV_OK == status)","src/kernel/gpu/mmu/gmmu_walk.c",0x1c7);
      goto LAB_00405f3c;
    }
  }
LAB_004060ff:
  listAppendExisting_IMPL(param_1[2] + 0x18,uVar20,uVar18);
  uVar18 = listTail_IMPL(*(undefined8 *)(uVar20 + 0xe8));
  listRemoveIntrusive_IMPL(*(undefined8 *)(uVar20 + 0xe8),uVar18);
  if (uVar18 == 0) {
LAB_00405f3c:
    iVar7 = 0;
    memdescFree(local_70);
    goto LAB_004058ce;
  }
LAB_0040600f:
  lVar12 = 1L << (param_2[1] + 1 & 0x3f);
  uVar20 = -lVar12;
  lVar12 = lVar12 + -1 + (param_4 & uVar20);
  uVar11 = memdescGetPtePhysAddr(uVar18,1,0);
  pcVar16 = "Packed";
LAB_00405c47:
  nvDbg_Printf("src/kernel/gpu/mmu/gmmu_walk.c",0x183,"_gmmuWalkCBLevelAlloc",1,
               "NVRM: [GPU%u]: [%s] PA 0x%llX (0x%X bytes) for VA 0x%llX-0x%llX\n",
               *(undefined4 *)(param_1[1] + 0x7a4),pcVar16,uVar11,uVar23,uVar20 & param_3,lVar12);
  *param_6 = uVar18;
  *param_7 = uVar6;
  *param_8 = 1;
  return 0;
}


// ===== 004061e0 gmmuMemDescCacheFree =====

void gmmuMemDescCacheFree(long param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pGpuState","src/kernel/gpu/mmu/gmmu_walk.c",499);
    return;
  }
  param_1 = param_1 + 0x18;
  iVar1 = listCount_IMPL(param_1);
  while (iVar1 != 0) {
    lVar3 = listTail_IMPL(param_1);
    iVar1 = *(int *)(lVar3 + 0x90);
    iVar2 = listCount_IMPL(*(undefined8 *)(lVar3 + 0xe8));
    if (iVar1 - iVar2 != 1) {
      nvAssertFailedNoLog("pParentMemDesc->RefCount - listCount(pParentMemDesc->pSubMemDescList) == 1"
                          ,"src/kernel/gpu/mmu/gmmu_walk.c",0x1fc);
    }
    while (iVar1 = listCount_IMPL(*(undefined8 *)(lVar3 + 0xe8)), iVar1 != 0) {
      uVar4 = listTail_IMPL(*(undefined8 *)(lVar3 + 0xe8));
      listRemoveIntrusive_IMPL(*(undefined8 *)(lVar3 + 0xe8),uVar4);
      memdescDestroy(uVar4);
    }
    listRemoveIntrusive_IMPL(param_1,lVar3);
    memdescFree(lVar3);
    memdescDestroy(lVar3);
    iVar1 = listCount_IMPL(param_1);
  }
  return;
}


// ===== 004062f0 _kgmmuClientShadowBufferQueueCopyData =====

void _kgmmuClientShadowBufferQueueCopyData
               (long param_1,long param_2,long param_3,long param_4,long param_5,char param_6)

{
  long lVar1;
  long lVar2;
  
  if (param_5 != 0) {
    lVar2 = *(long *)(*(long *)(param_3 + 8) + 0x38) + param_1 * param_2;
    lVar1 = lVar2;
    if (param_6 == '\0') {
      lVar1 = param_4;
      param_4 = lVar2;
    }
    portMemCopy(lVar1,param_5 * param_1,param_4,param_5 * param_1);
    return;
  }
  return;
}


// ===== 00406340 kgmmuStateInitLocked_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgmmuStateInitLocked_IMPL(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  int local_2c [3];
  
  local_2c[0] = 0;
  lVar4 = portMemAllocNonPaged(0x10);
  *(long *)(param_2 + 0x538) = lVar4;
  if (lVar4 == 0) {
    nvCheckFailedNoLog(4,"pKernelGmmu->pStaticInfo != NULL","src/kernel/gpu/mmu/kern_gmmu.c",0x95);
    return 0x1a;
  }
  portMemSet(lVar4,0,0x10);
  iVar2 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800a59,*(undefined8 *)(param_2 + 0x538),
                     0x10);
  if (iVar2 == 0) {
    if (*(char *)(param_1 + 0x4913) != '\0') {
      lVar4 = gpuGetStaticInfo(param_1);
      *(undefined1 *)(param_1 + 0x45b) = *(undefined1 *)(lVar4 + 0x1fe4b);
    }
    if ((*(char *)(param_2 + 0x511) == '\0') &&
       (iVar3 = (**(code **)(param_2 + 1000))(param_1,param_2), iVar3 != 0)) {
      nvAssertOkFailedNoLog
                (iVar3,"kgmmuFaultBufferInit_HAL(pGpu, pKernelGmmu)",
                 "src/kernel/gpu/mmu/kern_gmmu.c",0xc4);
      return iVar3;
    }
    if ((*(char *)(param_1 + 0x4915) != '\0') && (*(char *)(param_1 + 0x454) != '\0')) {
      cVar1 = rmcfg_IsdBLACKWELL(param_1);
      if (cVar1 == '\0') {
        iVar3 = osReadRegistryDword(param_1,"RMBug4686457War",local_2c);
        if (iVar3 != 0) {
          return 0;
        }
        if (local_2c[0] != 1) {
          return 0;
        }
      }
      *(undefined1 *)(param_2 + 0x54c) = 1;
    }
  }
  else {
    nvCheckOkFailedNoLog
              (4,iVar2,
               "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_GMMU_GET_STATIC_INFO, pKernelGmmu->pStaticInfo, sizeof(*pKernelGmmu->pStaticInfo))"
               ,"src/kernel/gpu/mmu/kern_gmmu.c",0x98);
    portMemFree(*(undefined8 *)(param_2 + 0x538));
  }
  return iVar2;
}


// ===== 00406530 kgmmuEnableComputePeerAddressing_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgmmuEnableComputePeerAddressing_IMPL(long param_1,long param_2)

{
  ulong uVar1;
  
  if ((*(char *)(g_pSys + 0x6a) == '\0') &&
     (*(char *)(*(long *)(&DAT_00001b90 + param_1) + 0xa860) == '\0')) {
    return 0;
  }
  uVar1 = (**(code **)(param_2 + 0x350))(param_2);
  if ((int)uVar1 == 0) {
    if (*(char *)(param_1 + 0x908) == '\0') {
      uVar1 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20800aad,0,0);
      return uVar1;
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/mmu/kern_gmmu.c",0x123,"kgmmuEnableComputePeerAddressing_IMPL",4,
                 "NVRM: Failed to enable GMMU property compute addressing for GPU %x , status:%x\n",
                 *(undefined4 *)(param_1 + 0x7a4),uVar1);
  }
  return uVar1 & 0xffffffff;
}


// ===== 00406600 kgmmuStatePostLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgmmuStatePostLoad_IMPL(long param_1,long param_2,uint param_3)

{
  int iVar1;
  long lVar2;
  undefined8 local_30 [2];
  
  local_30[0] = 0;
  if ((param_3 & 1) == 0) {
    lVar2 = gpumgrGetParentGPU();
    if (param_1 == lVar2) {
      lVar2 = gpumgrGetGpuGrpFromGpu(param_1);
      if (lVar2 == 0) {
        nvAssertFailedNoLog("pGpuGrp != NULL","src/kernel/gpu/mmu/kern_gmmu.c",0xf0);
        iVar1 = 0x25;
      }
      else {
        iVar1 = gpugrpCreateGlobalVASpace_IMPL(lVar2,param_1,0x90f1,0,0,0x20,local_30);
        if (iVar1 == 0) goto LAB_00406627;
        nvAssertFailedNoLog("(NV_OK == rmStatus)","src/kernel/gpu/mmu/kern_gmmu.c",0xf7,0x40668a);
      }
      nvDbg_Printf("src/kernel/gpu/mmu/kern_gmmu.c",0x145,"kgmmuStatePostLoad_IMPL",4,
                   "NVRM: Failed to create GVASpace, status:%x\n");
      return iVar1;
    }
  }
LAB_00406627:
  iVar1 = (**(code **)(param_2 + 0x240))(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(param_2 + 0x3d0))(param_1,param_2);
    if (iVar1 != 0) {
      nvAssertOkFailedNoLog
                (iVar1,"kgmmuInitCeMmuFaultIdRange_HAL(pGpu, pKernelGmmu)",
                 "src/kernel/gpu/mmu/kern_gmmu.c",0x155);
    }
    return iVar1;
  }
  nvDbg_Printf("src/kernel/gpu/mmu/kern_gmmu.c",0x14f,"kgmmuStatePostLoad_IMPL",4,
               "NVRM: Failed to enable compute peer addressing, status:%x\n",iVar1);
  return iVar1;
}


// ===== 004067c0 kgmmuStatePreUnload_IMPL =====

int kgmmuStatePreUnload_IMPL(undefined8 param_1,undefined8 param_2,uint param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((param_3 & 1) != 0) {
    return 0;
  }
  uVar2 = gpumgrGetGpuGrpFromGpu();
  iVar1 = gpugrpDestroyGlobalVASpace_IMPL(uVar2,param_1);
  if (iVar1 != 0) {
    nvDbg_Printf("src/kernel/gpu/mmu/kern_gmmu.c",0x16b,"kgmmuStatePreUnload_IMPL",4,
                 "NVRM: Failed to destory GVASpace, status:%x\n");
  }
  return iVar1;
}


// ===== 00406830 kgmmuDestruct_IMPL =====

void kgmmuDestruct_IMPL(long param_1)

{
  long *plVar1;
  
  plVar1 = (long *)(param_1 + 0x550);
  do {
    if (*plVar1 != 0) {
      portMemFree(*(undefined8 *)(*plVar1 + 0x520));
      *(undefined8 *)(*plVar1 + 0x520) = 0;
      portMemFree(*(undefined8 *)(*plVar1 + 0x528));
      *(undefined8 *)(*plVar1 + 0x528) = 0;
      portMemFree(*plVar1);
    }
    plVar1 = plVar1 + 1;
  } while (plVar1 != (long *)(param_1 + 0x568));
  return;
}


// ===== 004068a0 kgmmuStateDestroy_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgmmuStateDestroy_IMPL(undefined8 param_1,long param_2)

{
  if (*(long *)(param_2 + 0x538) != 0) {
    portMemFree();
    *(undefined8 *)(param_2 + 0x538) = 0;
  }
  if (*(long *)(param_2 + 0x5b8) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 0x5b8));
    *(undefined8 *)(param_2 + 0x5b8) = 0;
  }
  if (*(long *)(param_2 + 0x5c0) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 0x5c0));
    *(undefined8 *)(param_2 + 0x5c0) = 0;
  }
  if (*(char *)(param_2 + 0x511) == '\0') {
    (**(code **)(param_2 + 0x3f0))(param_1,param_2);
    return;
  }
  return;
}


// ===== 00406950 kgmmuStateLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgmmuStateLoad_IMPL(long param_1,long param_2)

{
  ulong uVar1;
  
  if (*(char *)(param_2 + 0x511) != '\0') {
    return 0;
  }
  uVar1 = (**(code **)(param_2 + 0x3f8))(param_1,param_2,0,0);
  if ((int)uVar1 == 0) {
    if ((*(char *)(param_2 + 0x512) != '\0') && (*(char *)(param_1 + 0x443) != '\0')) {
      uVar1 = (**(code **)(param_2 + 0x3f8))(param_1,param_2,1,0);
      return uVar1;
    }
  }
  else {
    nvAssertOkFailedNoLog(uVar1 & 0xffffffff,"status","src/kernel/gpu/mmu/kern_gmmu.c",0x1b9);
    uVar1 = uVar1 & 0xffffffff;
  }
  return uVar1;
}


// ===== 004069e0 kgmmuStateUnload_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgmmuStateUnload_IMPL(long param_1,long param_2)

{
  ulong uVar1;
  
  if (*(char *)(param_2 + 0x511) != '\0') {
    return 0;
  }
  uVar1 = (**(code **)(param_2 + 0x400))(param_1,param_2,0,0);
  if ((int)uVar1 == 0) {
    if ((*(char *)(param_2 + 0x512) != '\0') && (*(char *)(param_1 + 0x443) != '\0')) {
      uVar1 = (**(code **)(param_2 + 0x400))(param_1,param_2,1,0);
      return uVar1;
    }
  }
  else {
    nvAssertOkFailedNoLog(uVar1 & 0xffffffff,"status","src/kernel/gpu/mmu/kern_gmmu.c",0x1df);
    uVar1 = uVar1 & 0xffffffff;
  }
  return uVar1;
}


// ===== 00406a70 kgmmuGetMemAperture_IMPL =====

bool kgmmuGetMemAperture_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  
  iVar1 = memdescGetAddressSpace(param_2);
  if (iVar1 != 1) {
    if (iVar1 != 2) {
      nvAssertFailedNoLog(&DAT_00d67bc4,"src/kernel/gpu/mmu/kern_gmmu.c",0x25c);
    }
    return iVar1 == 2;
  }
  return (bool)((*(int *)(param_2 + 0x74) == 0) + '\x03');
}


// ===== 00406ae0 kgmmuFmtInit_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgmmuFmtInit_IMPL(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  undefined4 *puVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  
  lVar7 = 0;
  do {
    lVar3 = *(long *)(param_1 + 0x550 + lVar7 * 8);
    if (lVar3 != 0) {
      uVar1 = (&g_gmmuFmtVersions)[lVar7];
      lVar6 = 0;
      while( true ) {
        uVar2 = (&g_gmmuFmtBigPageShifts)[lVar6];
        lVar5 = portMemAllocNonPaged(0xd8);
        *(long *)(lVar3 + 0x520 + lVar6 * 8) = lVar5;
        if (lVar5 == 0) {
          nvAssertFailedNoLog("(pFam->pFmts[b] != NULL)","src/kernel/gpu/mmu/kern_gmmu.c",0x27c);
          return 0x51;
        }
        portMemSet(lVar5,0,0xd8);
        puVar4 = *(undefined4 **)(lVar3 + 0x520 + lVar6 * 8);
        *puVar4 = uVar1;
        puVar4 = puVar4 + 0xc;
        *(undefined4 **)(*(long *)(lVar3 + 0x520 + lVar6 * 8) + 8) = puVar4;
        *(long *)(*(long *)(lVar3 + 0x520 + lVar6 * 8) + 0x18) = lVar3;
        *(long *)(*(long *)(lVar3 + 0x520 + lVar6 * 8) + 0x10) = lVar3 + 0x210;
        *(long *)(*(long *)(lVar3 + 0x520 + lVar6 * 8) + 0x20) = lVar3 + 0x310;
        (**(code **)(param_1 + 0x260))(param_1,puVar4,7,uVar1,uVar2);
        kgmmuFmtInitCaps_GM20X(param_1);
        if (lVar6 == 1) break;
        lVar6 = 1;
      }
    }
    lVar7 = lVar7 + 1;
  } while (lVar7 != 3);
  return 0;
}


// ===== 00406c30 kgmmuConstructEngine_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgmmuConstructEngine_IMPL(long param_1,long param_2)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  uint local_3c [3];
  
  (**(code **)(param_2 + 0x270))();
  if (*(char *)(param_1 + 0x4921) != '\0') {
    *(undefined2 *)(param_2 + 0x67d0) = 0;
  }
  lVar6 = 0;
  (**(code **)(param_2 + 0x1e0))(param_2);
  (**(code **)(param_2 + 0x1d8))(param_2);
  do {
    uVar1 = (&g_gmmuFmtVersions)[lVar6];
    cVar2 = (**(code **)(param_2 + 600))(param_2,uVar1);
    if (cVar2 == '\0') {
      *(undefined8 *)(param_2 + 0x550 + lVar6 * 8) = 0;
    }
    else {
      lVar5 = portMemAllocNonPaged(0x530);
      if (lVar5 == 0) {
        nvAssertFailedNoLog("(pFam != NULL)","src/kernel/gpu/mmu/kern_gmmu.c",0x59);
        return 0x51;
      }
      portMemSet(lVar5,0,0x530);
      *(long *)(param_2 + 0x550 + lVar6 * 8) = lVar5;
      (**(code **)(param_2 + 0x268))(param_2,lVar5,uVar1,param_2 + 0x5a0);
      (**(code **)(param_2 + 0x250))(param_2,lVar5 + 0x210,uVar1,param_2 + 0x5a0);
      (**(code **)(param_2 + 0x248))
                (param_2,lVar5 + 0x310,uVar1,param_2 + 0x5aa,*(undefined1 *)(param_1 + 0x491c));
      (**(code **)(param_2 + 0x230))(param_2,lVar5 + 0x310,uVar1);
    }
    lVar6 = lVar6 + 1;
  } while (lVar6 != 3);
  iVar3 = kgmmuFmtInit_IMPL(param_2);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog(0x51,"kgmmuFmtInit(pKernelGmmu)","src/kernel/gpu/mmu/kern_gmmu.c",0x6a);
    return 0x51;
  }
  if (*(char *)(param_1 + 0x908) == '\0') {
    if (*(char *)(param_1 + 0x4913) != '\0') goto LAB_00406f58;
  }
  else {
    if (*(char *)(param_1 + 0x4913) == '\0') goto LAB_00406d2e;
LAB_00406f58:
    if (*(char *)(param_1 + 0x491e) != '\0') goto LAB_00406d2e;
  }
  iVar3 = (**(code **)(param_2 + 0x278))(param_1,param_2);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,"kgmmuFmtFamiliesInit_HAL(pGpu, pKernelGmmu)","src/kernel/gpu/mmu/kern_gmmu.c",
               0x74);
    return iVar3;
  }
LAB_00406d2e:
  portMemSet(param_2 + 0x5c8,0,0x6200);
  *(undefined8 *)(param_2 + 0x568) = 0x200000002;
  *(undefined8 *)(param_2 + 0x570) = 0x200000002;
  *(undefined8 *)(param_2 + 0x578) = 0x200000002;
  *(undefined8 *)(param_2 + 0x580) = 0x200000002;
  memdescOverrideInstLoc(*(byte *)(param_1 + 0x4927) & 3,"GMMU PDE",param_2 + 0x568,param_2 + 0x56c)
  ;
  memdescOverrideInstLoc
            (*(uint *)(param_1 + 0x4924) >> 0x1a & 3,"BAR1 PDE",param_2 + 0x570,param_2 + 0x574);
  memdescOverrideInstLoc(*(uint *)(param_1 + 0x4924) & 3,"GMMU PTE",param_2 + 0x578,param_2 + 0x57c)
  ;
  memdescOverrideInstLoc
            (*(uint *)(param_1 + 0x4924) >> 2 & 3,"BAR1 PTE",param_2 + 0x580,param_2 + 0x584);
  *(undefined1 *)(param_2 + 0x590) = 0;
  iVar3 = osReadRegistryDword(param_1,"RmDisableBigPagePerAddressSpace",local_3c);
  if (iVar3 == 0) {
    *(bool *)(param_2 + 0x590) = local_3c[0] == 0;
  }
  iVar4 = osReadRegistryDword(param_1,"RMFermiBigPageSize",local_3c);
  iVar3 = *(int *)(param_1 + 0x493c);
  if (iVar4 == 0) {
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/gpu/mmu/kern_gmmu.c",0x21b,"_kgmmuInitRegistryOverrides",4,
                   "NVRM: The %s regkey cannot be used with the %s regkey!\n","RMFermiBigPageSize",
                   "RMOptimizeComputeOrSparseTex");
      return 0;
    }
    if ((local_3c[0] - 0x10000 & 0xfffeffff) == 0) {
      *(ulong *)(param_2 + 0x588) = (ulong)local_3c[0];
    }
  }
  else if (iVar3 != 0) {
    if (iVar3 == 1) {
      *(undefined8 *)(param_2 + 0x588) = 0x20000;
    }
    else if (iVar3 == 2) {
      *(undefined8 *)(param_2 + 0x588) = 0x10000;
    }
  }
  iVar3 = osReadRegistryDword(param_1,"RmDisableHwFaultBuffer",local_3c);
  if (iVar3 == 0) {
    nvDbg_Printf("src/kernel/gpu/mmu/kern_gmmu.c",0x242,"_kgmmuInitRegistryOverrides",4,
                 "NVRM: Overriding HW Fault buffer state to 0x%x due to regkey!\n",local_3c[0]);
    *(char *)(param_2 + 0x511) = (char)local_3c[0];
  }
  return 0;
}


// ===== 004070b0 kgmmuFmtGetFamily_IMPL =====

long kgmmuFmtGetFamily_IMPL(long param_1,int param_2)

{
  long lVar1;
  undefined4 *puVar2;
  ulong uVar3;
  int iVar4;
  
  if (param_2 == 0) {
    lVar1 = *(long *)(param_1 + 0x560);
    param_1 = param_1 + 0x560;
    iVar4 = 2;
    while( true ) {
      if (lVar1 != 0) {
        return lVar1;
      }
      if (iVar4 == 0) break;
      lVar1 = *(long *)(param_1 + -8);
      param_1 = param_1 + -8;
      iVar4 = iVar4 + -1;
    }
  }
  else {
    uVar3 = 2;
    puVar2 = &g_gmmuFmtVersions;
    iVar4 = DAT_00daaeb0;
    while( true ) {
      if (iVar4 == param_2) {
        return *(long *)(param_1 + 0x550 + uVar3 * 8);
      }
      if ((int)uVar3 == 0) break;
      uVar3 = (ulong)((int)uVar3 - 1);
      iVar4 = puVar2[1];
      puVar2 = puVar2 + -1;
    }
  }
  return 0;
}


// ===== 00407120 kgmmuGetStaticInfo_IMPL =====

undefined8 kgmmuGetStaticInfo_IMPL(undefined8 param_1,long param_2)

{
  if (param_2 != 0) {
    return *(undefined8 *)(param_2 + 0x538);
  }
  nvAssertFailedNoLog("pKernelGmmu != NULL","src/kernel/gpu/mmu/kern_gmmu.c",0x2ba);
  return 0;
}


// ===== 00407160 kgmmuFmtGet_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgmmuFmtGet_IMPL(long param_1,int param_2,long param_3)

{
  undefined4 *puVar1;
  ulong uVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  
  if (param_2 == 0) {
    lVar5 = *(long *)(param_1 + 0x560);
    lVar3 = param_1 + 0x560;
    iVar4 = 2;
    if (lVar5 == 0) {
      while( true ) {
        lVar5 = *(long *)(lVar3 + -8);
        lVar3 = lVar3 + -8;
        iVar4 = iVar4 + -1;
        if (lVar5 != 0) break;
        if (iVar4 == 0) {
          return 0;
        }
      }
    }
  }
  else {
    uVar2 = 2;
    puVar1 = &g_gmmuFmtVersions;
    iVar4 = DAT_00daaeb0;
    while (param_2 != iVar4) {
      if ((int)uVar2 == 0) {
        return 0;
      }
      uVar2 = (ulong)((int)uVar2 - 1);
      iVar4 = puVar1[1];
      puVar1 = puVar1 + -1;
    }
    lVar5 = *(long *)(param_1 + 0x550 + uVar2 * 8);
    if (lVar5 == 0) {
      return 0;
    }
  }
  if (param_3 == 0) {
    lVar3 = (**(code **)(param_1 + 0x1d0))();
    param_3 = 0x10000;
    if (lVar3 != 0) {
      param_3 = lVar3;
    }
  }
  if (param_3 == 1L << ((byte)g_gmmuFmtBigPageShifts & 0x3f)) {
    lVar3 = 0;
  }
  else {
    if (param_3 != 1L << ((byte)DAT_00daaea4 & 0x3f)) {
      return 0;
    }
    lVar3 = 1;
  }
  return *(undefined8 *)(lVar5 + 0x520 + lVar3 * 8);
}


// ===== 00407260 kgmmuGetSizeOfPageTables_IMPL =====

long kgmmuGetSizeOfPageTables_IMPL
               (undefined8 param_1,undefined8 param_2,long param_3,ulong param_4,ulong param_5,
               ulong param_6)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  
  if (param_6 == 0) {
    return 0;
  }
  lVar5 = 0;
  lVar6 = 0;
  do {
    if ((param_6 & 1) != 0) {
      pbVar3 = (byte *)mmuFmtFindLevelWithPageShift(*(undefined8 *)(param_3 + 8),lVar6);
      if ((pbVar3[3] != 0) && (pbVar3[4] == 0)) {
        bVar1 = pbVar3[1];
        bVar2 = *pbVar3;
        if (param_5 >> (bVar1 + 1 & 0x3f) != 0) {
          lVar5 = lVar5 + (((1L << (bVar1 + 1 & 0x3f)) + -1 + param_5 >> (bVar1 + 1 & 0x3f)) +
                          (1 - (param_4 >> (bVar1 + 1 & 0x3f)))) *
                          (ulong)((uint)pbVar3[2] << ((bVar1 - bVar2) + 1 & 0x1f));
          if (param_6 >> 1 == 0) {
            return lVar5;
          }
          goto LAB_00407316;
        }
        uVar4 = -(1L << (bVar2 & 0x3f)) & ~(-1L << (bVar1 + 1 & 0x3f));
        lVar5 = lVar5 + (ulong)(uint)(((int)((param_5 & uVar4) >> (bVar2 & 0x3f)) + 1) -
                                     (int)((uVar4 & param_4) >> (bVar2 & 0x3f))) * (ulong)pbVar3[2];
      }
      if (param_6 >> 1 == 0) {
        return lVar5;
      }
    }
LAB_00407316:
    param_6 = param_6 >> 1;
    lVar6 = lVar6 + 1;
  } while( true );
}


// ===== 00407390 kgmmuGetSizeOfPageDirs_IMPL =====

long kgmmuGetSizeOfPageDirs_IMPL
               (undefined8 param_1,undefined8 param_2,long param_3,ulong param_4,long param_5,
               ulong param_6)

{
  byte bVar1;
  byte *pbVar2;
  ulong uVar3;
  byte *pbVar4;
  short sVar5;
  long lVar6;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pFmt != NULL","src/kernel/gpu/mmu/kern_gmmu.c",0x367);
    return 0;
  }
  sVar5 = 5;
  lVar6 = 0;
  bVar1 = **(byte **)(param_3 + 8);
  pbVar2 = *(byte **)(param_3 + 8);
  while( true ) {
    uVar3 = 1L << (bVar1 & 0x3f);
    if (uVar3 < (param_6 & -param_6)) {
      return lVar6;
    }
    pbVar4 = *(byte **)(pbVar2 + 0x10);
    if (pbVar2[4] == 1) {
      if (pbVar4 == (byte *)0x0) {
        nvAssertFailedNoLog("pLevel != NULL","src/kernel/gpu/mmu/kern_gmmu.c",0x390);
        return 0;
      }
    }
    else {
      pbVar4 = pbVar4 + 0x18;
    }
    lVar6 = lVar6 + ((((uVar3 - 1) + param_5 >> (bVar1 & 0x3f)) + (1 - (param_4 >> (bVar1 & 0x3f))))
                     * (ulong)pbVar2[2] + 0xfff & 0xfffffffffffff000);
    if ((pbVar4[3] != 0) && (pbVar4[4] == 0)) break;
    sVar5 = sVar5 + -1;
    if (sVar5 == 0) {
      return lVar6;
    }
    bVar1 = *pbVar4;
    pbVar2 = pbVar4;
  }
  return lVar6;
}


// ===== 004074a0 kgmmuFieldSetKindCompTags_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kgmmuFieldSetKindCompTags_IMPL
          (long param_1,undefined8 param_2,byte *param_3,undefined4 *param_4,undefined8 param_5,
          ulong param_6,undefined4 param_7,undefined8 param_8)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  char *pcVar5;
  undefined8 uVar6;
  char local_51;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar6 = 0;
  if (param_1 != 0) {
    uVar6 = *(undefined8 *)(param_1 + 0x160);
  }
  lVar4 = gpuEngineGetGpu(uVar6);
  local_48 = 0;
  local_40 = 0;
  local_50 = CONCAT44(*param_4,param_4[1]);
  cVar1 = (**(code **)(*(long *)(lVar4 + 0x1b78) + 0x2a8))(*(long *)(lVar4 + 0x1b78),5);
  if (cVar1 != '\0') {
    pcVar5 = (char *)kmemsysGetStaticConfig_IMPL(lVar4,*(undefined8 *)(lVar4 + 0x1b70));
    if (*(char *)(param_4 + 2) == '\0') {
      local_40 = *(undefined8 *)(param_4 + 5);
      local_48 = *(undefined8 *)(param_4 + 3);
    }
    else {
      if ((*pcVar5 == '\0') && (pcVar5[2] == '\0')) {
        nvAssertFailedNoLog("pMemorySystemConfig->bOneToOneComptagLineAllocation || pMemorySystemConfig->bUseRawModeComptaglineAllocation"
                            ,"src/kernel/gpu/mmu/kern_gmmu.c",0x3ba);
      }
      iVar2 = vgpuIsCallingContextPlugin(lVar4,&local_51);
      if (iVar2 != 0) {
        uVar6 = nvAssertFailedNoLog("vgpuIsCallingContextPlugin(pGpu, &bCallingContextPlugin) == NV_OK"
                                    ,"src/kernel/gpu/mmu/kern_gmmu.c",0x3bc);
        return uVar6;
      }
      if ((*(char *)(lVar4 + 0x4913) == '\0' && local_51 == '\0') && (pcVar5[2] == '\0')) {
        uVar3 = (**(code **)(*(long *)(lVar4 + 0x1b78) + 0x300))
                          (lVar4,*(long *)(lVar4 + 0x1b78),param_5);
      }
      else {
        uVar3 = 1;
      }
      local_40 = CONCAT44(1,uVar3);
      local_48 = CONCAT44((int)((1L << (*param_3 & 0x3f)) + -1 + param_6 >>
                               ((byte)param_4[1] & 0x3f)),
                          (int)(param_6 >> ((byte)param_4[1] & 0x3f)));
    }
  }
  gmmuFmtInitPteCompTags(param_2,param_3,&local_50,param_6,param_7,1);
  return param_8;
}


// ===== 00407680 kgmmuFaultBufferGetAddressSpace_IMPL =====

undefined8
kgmmuFaultBufferGetAddressSpace_IMPL
          (long param_1,undefined8 param_2,uint param_3,int *param_4,uint *param_5)

{
  char cVar1;
  int local_40;
  uint local_3c [3];
  
  local_40 = 0;
  local_3c[0] = 0;
  cVar1 = gpuIsCCFeatureEnabled_IMPL();
  if (param_3 < 2) {
    local_40 = (cVar1 != '\0') + 1;
    local_3c[0] = (uint)(cVar1 != '\0');
    if (param_3 == 0) {
      memdescOverrideInstLoc
                (*(uint *)(param_1 + 0x492c) >> 0x12 & 3,"UVM non-replayable fault",&local_40,
                 local_3c);
    }
    else {
      memdescOverrideInstLoc
                (*(uint *)(param_1 + 0x4930) >> 10 & 3,"UVM replayable fault",&local_40,local_3c);
    }
    if ((cVar1 == '\0') || (local_40 != 1)) {
      if (param_4 != (int *)0x0) {
        *param_4 = local_40;
      }
      if (param_5 != (uint *)0x0) {
        *param_5 = local_3c[0];
      }
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/mmu/kern_gmmu.c",0x3ff,"kgmmuFaultBufferGetAddressSpace_IMPL",4,
                 "NVRM: Fault buffers must be in CPR vidmem when HCC is enabled\n");
    nvAssertFailedNoLog(&DAT_00d67bc4,"src/kernel/gpu/mmu/kern_gmmu.c",0x400);
  }
  else {
    nvAssertFailedNoLog("(index < NUM_FAULT_BUFFERS)","src/kernel/gpu/mmu/kern_gmmu.c",1000);
  }
  return 0x1f;
}


// ===== 004077e0 kgmmuFaultBufferCreateMemDesc_IMPL =====

/* WARNING: Removing unreachable block (ram,0x00407920) */
/* WARNING: Removing unreachable block (ram,0x0040792e) */

int kgmmuFaultBufferCreateMemDesc_IMPL
              (long param_1,undefined8 param_2,uint param_3,int param_4,undefined8 param_5,
              undefined8 *param_6)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  undefined8 local_40 [2];
  
  local_40[0] = 0;
  if (param_3 < 2) {
    iVar2 = kgmmuFaultBufferGetAddressSpace_IMPL();
    if (iVar2 == 0) {
      if ((*(char *)(param_1 + 0x908) == '\0') ||
         (bVar3 = true, *(char *)(param_1 + 0x491e) == '\0')) {
        cVar1 = gpuIsCCFeatureEnabled_IMPL(param_1);
        bVar3 = cVar1 != '\0';
      }
      iVar2 = memdescCreate(local_40,param_1,param_4 + 0xfffU & 0xfffff000,0,bVar3,0,0);
      if (iVar2 == 0) {
        memdescSetPageSize(local_40[0],1,0x1000);
        *param_6 = local_40[0];
        return 0;
      }
      return iVar2;
    }
  }
  else {
    nvAssertFailedNoLog("(index < NUM_FAULT_BUFFERS)","src/kernel/gpu/mmu/kern_gmmu.c",0x422);
  }
  return 0x1f;
}


// ===== 00407970 kgmmuFaultBufferAlloc_IMPL =====

ulong kgmmuFaultBufferAlloc_IMPL(undefined8 param_1,long param_2,uint param_3,undefined4 param_4)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  char *pcVar4;
  long local_40 [2];
  
  local_40[0] = 0;
  if (param_3 == 1) {
    pcVar4 = "rm_replayable_fault_buffer_surface";
  }
  else {
    pcVar4 = "rm_non_replayable_fault_buffer_surface";
    if (1 < param_3) {
      nvAssertFailedNoLog("(index < NUM_FAULT_BUFFERS)","src/kernel/gpu/mmu/kern_gmmu.c",0x474);
      return 0x1f;
    }
  }
  uVar3 = 0;
  if ((*(char *)(param_2 + 0x511) == '\0') &&
     (uVar3 = kgmmuFaultBufferCreateMemDesc_IMPL(param_1,param_2,param_3,param_4,0,local_40),
     lVar1 = local_40[0], (int)uVar3 == 0)) {
    *(undefined4 *)(local_40[0] + 0x9c) = 0x40;
    uVar2 = memdescAlloc(local_40[0]);
    if (uVar2 == 0) {
      memdescSetName(param_1,lVar1,pcVar4,0);
      *(undefined4 *)(param_2 + 0x5f4 + (ulong)param_3 * 0x30) = param_4;
      *(long *)(param_2 + 0x5d0 + (ulong)param_3 * 0x30) = lVar1;
      return 0;
    }
    memdescDestroy(lVar1);
    uVar3 = (ulong)uVar2;
  }
  return uVar3;
}


// ===== 00407aa0 kgmmuFaultBufferFree_IMPL =====

undefined8 kgmmuFaultBufferFree_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  undefined8 uVar1;
  
  if (1 < param_3) {
    nvAssertFailedNoLog("(index < NUM_FAULT_BUFFERS)","src/kernel/gpu/mmu/kern_gmmu.c",0x49c);
    return 0x1f;
  }
  if (*(char *)(param_2 + 0x511) == '\0') {
    param_2 = param_2 + (ulong)param_3 * 0x30;
    memdescFree(*(undefined8 *)(param_2 + 0x5d0));
    uVar1 = *(undefined8 *)(param_2 + 0x5d0);
    *(undefined4 *)(param_2 + 0x5f4) = 0;
    *(undefined8 *)(param_2 + 0x5d0) = 0;
    memdescDestroy(uVar1);
  }
  return 0;
}


// ===== 00407b30 kgmmuFaultBufferReplayableAllocate_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgmmuFaultBufferReplayableAllocate_IMPL
              (long param_1,long param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("pKernelGmmu != NULL","src/kernel/gpu/mmu/kern_gmmu.c",0x2ba);
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(param_2 + 0x538);
  }
  if (((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) &&
     (*(char *)(param_2 + 0x511) == '\0')) {
    iVar2 = 0x56;
    if (*(long *)(param_2 + 0x600) == 0) {
      iVar3 = *piVar4;
      iVar2 = kgmmuFaultBufferAlloc_IMPL(param_1,param_2,1,iVar3);
      if (iVar2 == 0) {
        if (*(char *)(param_1 + 0x909) == '\0') {
          iVar3 = (**(code **)(param_2 + 0x3f8))(param_1,param_2,1,0);
          if (iVar3 != 0) {
            if (*(char *)(param_2 + 0x511) != '\0') {
              return iVar3;
            }
            memdescFree(*(undefined8 *)(param_2 + 0x600));
            uVar1 = *(undefined8 *)(param_2 + 0x600);
            *(undefined4 *)(param_2 + 0x624) = 0;
            *(undefined8 *)(param_2 + 0x600) = 0;
            memdescDestroy(uVar1);
            return iVar3;
          }
          *(undefined1 *)(param_2 + 0x512) = 1;
        }
        else {
          puVar5 = (undefined4 *)portMemAllocNonPaged(0x810);
          if (puVar5 == (undefined4 *)0x0) {
            if (*(char *)(param_2 + 0x511) == '\0') {
              memdescFree(*(undefined8 *)(param_2 + 0x600));
              uVar1 = *(undefined8 *)(param_2 + 0x600);
              *(undefined4 *)(param_2 + 0x624) = 0;
              *(undefined8 *)(param_2 + 0x600) = 0;
              memdescDestroy(uVar1);
            }
            return 0x51;
          }
          portMemSet(puVar5,0,0x810);
          if (0x100fff < iVar3 + 0xfffU) {
            portMemFree(puVar5);
            if (*(char *)(param_2 + 0x511) == '\0') {
              memdescFree(*(undefined8 *)(param_2 + 0x600));
              uVar1 = *(undefined8 *)(param_2 + 0x600);
              *(undefined4 *)(param_2 + 0x624) = 0;
              *(undefined8 *)(param_2 + 0x600) = 0;
              memdescDestroy(uVar1);
            }
            return 2;
          }
          memdescGetPtePhysAddrs
                    (*(undefined8 *)(param_2 + 0x600),1,0,0x1000,iVar3 + 0xfffU >> 0xc,puVar5 + 4);
          *puVar5 = param_3;
          puVar5[1] = param_4;
          puVar5[2] = iVar3;
          iVar3 = (**(code **)(param_1 + 0x3b90))
                            (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                             *(undefined4 *)(param_1 + 0x3b3c),0x20800a9b,puVar5,0x810);
          portMemFree(puVar5);
          if (iVar3 != 0) {
            if (*(char *)(param_2 + 0x511) != '\0') {
              return iVar3;
            }
            memdescFree(*(undefined8 *)(param_2 + 0x600));
            uVar1 = *(undefined8 *)(param_2 + 0x600);
            *(undefined4 *)(param_2 + 0x624) = 0;
            *(undefined8 *)(param_2 + 0x600) = 0;
            memdescDestroy(uVar1);
            return iVar3;
          }
        }
        *(undefined4 *)(param_2 + 0x628) = param_3;
        *(undefined4 *)(param_2 + 0x62c) = param_4;
        *(undefined8 *)(param_2 + 0x748) = 0;
      }
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ===== 00407eb0 kgmmuFaultBufferReplayableDestroy_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgmmuFaultBufferReplayableDestroy_IMPL(long param_1,long param_2)

{
  undefined8 uVar1;
  int iVar2;
  
  if ((((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) &&
      (*(char *)(param_2 + 0x511) == '\0')) && (*(long *)(param_2 + 0x600) != 0)) {
    *(undefined8 *)(param_2 + 0x628) = 0;
    if (*(char *)(param_1 + 0x909) == '\0') {
      iVar2 = (**(code **)(param_2 + 0x400))(param_1,param_2,1,0);
      if (iVar2 == 0) {
        *(undefined1 *)(param_2 + 0x512) = 0;
      }
      else {
        nvDbg_Printf("src/kernel/gpu/mmu/kern_gmmu.c",0x53d,"kgmmuFaultBufferReplayableDestroy_IMPL"
                     ,4,
                     "NVRM: Unloading Replayable Fault buffer failed (status=0x%08x), proceeding...\n"
                     ,iVar2);
      }
    }
    else {
      iVar2 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20800a9c,0,0);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/gpu/mmu/kern_gmmu.c",0x533,"kgmmuFaultBufferReplayableDestroy_IMPL"
                     ,4,
                     "NVRM: Unregistering Replayable Fault buffer failed (status=0x%08x), proceeding...\n"
                     ,iVar2);
      }
    }
    if (*(char *)(param_2 + 0x511) == '\0') {
      memdescFree(*(undefined8 *)(param_2 + 0x600));
      uVar1 = *(undefined8 *)(param_2 + 0x600);
      *(undefined4 *)(param_2 + 0x624) = 0;
      *(undefined8 *)(param_2 + 0x600) = 0;
      memdescDestroy(uVar1);
    }
    return 0;
  }
  return 0;
}


// ===== 00408020 kgmmuEncodePhysAddrs_IMPL =====

void kgmmuEncodePhysAddrs_IMPL
               (undefined8 param_1,int param_2,long *param_3,long param_4,ulong param_5)

{
  long *plVar1;
  long *plVar2;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("aperture != GMMU_APERTURE_INVALID","src/kernel/gpu/mmu/kern_gmmu.c",0x58a);
    return;
  }
  if (((param_4 != -1) && (param_2 == 2)) && (param_5 != 0)) {
    plVar1 = param_3 + param_5;
    if ((param_5 & 1) != 0) {
      *param_3 = *param_3 + param_4;
      param_3 = param_3 + 1;
      if (param_3 == plVar1) {
        return;
      }
    }
    while( true ) {
      *param_3 = *param_3 + param_4;
      param_3[1] = param_3[1] + param_4;
      plVar2 = param_3 + 2;
      if (plVar2 == plVar1) break;
      *plVar2 = *plVar2 + param_4;
      param_3[3] = param_3[3] + param_4;
      param_3 = param_3 + 4;
      if (param_3 == plVar1) {
        return;
      }
    }
  }
  return;
}


// ===== 004080b0 kgmmuEncodePhysAddr_IMPL =====

long kgmmuEncodePhysAddr_IMPL(undefined8 param_1,int param_2,long param_3,long param_4)

{
  if (param_2 == 0) {
    nvAssertFailedNoLog("aperture != GMMU_APERTURE_INVALID","src/kernel/gpu/mmu/kern_gmmu.c",0x58a);
    return param_3;
  }
  if ((param_2 == 2) && (param_4 != -1)) {
    return param_3 + param_4;
  }
  return param_3;
}


// ===== 00408110 kgmmuClientShadowFaultBufferRegister_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgmmuClientShadowFaultBufferRegister_IMPL(long param_1,long param_2,uint param_3)

{
  long lVar1;
  long lVar2;
  bool bVar3;
  char cVar4;
  uint uVar5;
  ulong uVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  ulong uVar9;
  undefined8 local_50;
  undefined8 local_40;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("pKernelGmmu != NULL","src/kernel/gpu/mmu/kern_gmmu.c",0x2ba);
    puVar7 = (undefined8 *)0x0;
  }
  else {
    puVar7 = *(undefined8 **)(param_2 + 0x538);
  }
  if (param_3 == 0) {
    local_40 = puVar7[1];
  }
  else {
    if (param_3 != 1) {
      nvAssertFailedNoLog(&DAT_00d67bc4,"src/kernel/gpu/mmu/kern_gmmu.c",0x6b6);
      return 0x1f;
    }
    local_40 = *puVar7;
  }
  cVar4 = gpuIsCCFeatureEnabled_IMPL(param_1);
  if ((cVar4 == '\0') || (*(char *)(param_1 + 0x4a78) == '\0')) {
    local_50 = *(undefined8 *)(param_2 + 0x658 + (ulong)param_3 * 0x78);
    uVar6 = circularQueueInitNonManaged_IMPL(local_50,(uint)local_40 >> 5,0x20);
    if ((int)uVar6 != 0) {
      return uVar6;
    }
    bVar3 = true;
  }
  else {
    bVar3 = false;
    local_50 = 0;
  }
  uVar6 = (ulong)param_3;
  lVar1 = param_2 + 0x648 + (ulong)(-param_3 & 0x78);
  if (*(char *)(param_1 + 0x909) != '\0') {
    puVar7 = (undefined8 *)portMemAllocNonPaged(0x5de0);
    if (puVar7 == (undefined8 *)0x0) {
      if (bVar3) {
        circularQueueDestroy_IMPL(local_50);
      }
      return 0x51;
    }
    portMemSet(puVar7,0,0x5de0);
    lVar2 = *(long *)(param_2 + 0x678 + uVar6 * 0x78);
    uVar9 = *(ulong *)(lVar2 + 0x30) >> 0xc;
    if ((uint)uVar9 < 0xbb9) {
      memdescGetPhysAddrs(lVar2,1,0,0x1000,uVar9 & 0xffffffff,puVar7 + 2);
      cVar4 = gpuIsCCFeatureEnabled_IMPL(param_1);
      if ((cVar4 == '\0') || (*(char *)(param_1 + 0x4a78) == '\0')) {
        uVar8 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0x650 + uVar6 * 0x78),1,0);
        *puVar7 = uVar8;
      }
      *(uint *)(puVar7 + 0xbba) = param_3;
      puVar7[1] = local_40;
      cVar4 = gpuIsCCFeatureEnabled_IMPL(param_1);
      if (((cVar4 != '\0') && (*(char *)(param_1 + 0x4a78) != '\0')) && ((param_3 & 1) != 0)) {
        uVar8 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0x718),1,0);
        puVar7[0xbbb] = uVar8;
      }
      uVar5 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20800a9d,puVar7,0x5de0);
      portMemFree(puVar7);
      uVar9 = (ulong)uVar5;
      if (uVar5 == 0) {
        *(long *)(param_2 + 0x638 + uVar6 * 8) = lVar1;
        return 0;
      }
      if (bVar3) {
        circularQueueDestroy_IMPL(local_50);
        uVar9 = (ulong)uVar5;
      }
    }
    else {
      portMemFree(puVar7);
      if (bVar3) {
        circularQueueDestroy_IMPL(local_50);
      }
      uVar9 = 2;
    }
    return uVar9;
  }
  portSyncSpinlockAcquire(*(undefined8 *)(param_2 + 0x738));
  uVar8 = *(undefined8 *)(param_2 + 0x738);
  if (*(long *)(param_2 + 0x638 + uVar6 * 8) != 0) {
    portSyncSpinlockRelease(uVar8);
    if (bVar3) {
      circularQueueDestroy_IMPL(local_50);
    }
    return 0x56;
  }
  *(long *)(param_2 + 0x5c8 + (uVar6 + 0xe) * 8) = lVar1;
  portSyncSpinlockRelease(uVar8);
  return 0;
}


// ===== 004084f0 kgmmuClientShadowFaultBufferUnregister_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgmmuClientShadowFaultBufferUnregister_IMPL(long param_1,long param_2,uint param_3)

{
  char cVar1;
  undefined8 uVar2;
  ulong uVar3;
  char *pcVar4;
  uint local_2c [3];
  
  uVar3 = (ulong)param_3;
  if (*(char *)(param_1 + 0x909) == '\0') {
    portSyncSpinlockAcquire(*(undefined8 *)(param_2 + 0x738));
    *(undefined8 *)(param_2 + 0x638 + uVar3 * 8) = 0;
    portSyncSpinlockRelease(*(undefined8 *)(param_2 + 0x738));
  }
  else {
    portMemSet(local_2c,0,4);
    local_2c[0] = (uint)(param_3 != 0);
    uVar2 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800a9e,local_2c,4);
    if ((int)uVar2 != 0) {
      pcVar4 = "replayable";
      if (param_3 == 0) {
        pcVar4 = "non-replayable";
      }
      nvDbg_Printf("src/kernel/gpu/mmu/kern_gmmu.c",0x74c,
                   "kgmmuClientShadowFaultBufferUnregister_IMPL",4,
                   "NVRM: Unregistering %s fault buffer failed (status=0x%08x), proceeding...\n",
                   pcVar4,uVar2);
    }
    *(undefined8 *)(param_2 + 0x638 + uVar3 * 8) = 0;
  }
  cVar1 = gpuIsCCFeatureEnabled_IMPL(param_1);
  if ((cVar1 != '\0') && (*(char *)(param_1 + 0x4a78) != '\0')) {
    return;
  }
  circularQueueDestroy_IMPL(*(undefined8 *)(param_2 + 0x658 + uVar3 * 0x78));
  return;
}


// ===== 00408630 kgmmuClientShadowFaultBufferAllocate_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgmmuClientShadowFaultBufferAllocate_IMPL(long param_1,long param_2,uint param_3)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  long lVar6;
  ulong uVar7;
  uint uVar8;
  int local_4c;
  long local_40 [2];
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("pKernelGmmu != NULL","src/kernel/gpu/mmu/kern_gmmu.c",0x2ba);
    piVar5 = (int *)0x0;
    cVar2 = cRam0000000000000511;
  }
  else {
    piVar5 = *(int **)(param_2 + 0x538);
    cVar2 = *(char *)(param_2 + 0x511);
  }
  if (cVar2 == '\0') {
    iVar4 = piVar5[2];
    if (iVar4 != 0) {
      if (param_3 == 0) {
        local_4c = piVar5[3];
      }
      else {
        if (param_3 != 1) {
          nvAssertFailedNoLog(&DAT_00d67bc4,"src/kernel/gpu/mmu/kern_gmmu.c",0x787);
          return 0x1f;
        }
        iVar4 = *piVar5;
        local_4c = piVar5[1];
      }
      cVar2 = gpuIsCCFeatureEnabled_IMPL(param_1);
      if ((cVar2 == '\0') || (*(char *)(param_1 + 0x4a78) == '\0')) {
        iVar3 = memdescCreate(local_40,param_1,0xc0,0x1000,1,1,0);
        if (iVar3 != 0) {
          return iVar3;
        }
        *(undefined4 *)(local_40[0] + 0x9c) = 0x41;
        iVar3 = memdescAlloc();
        if (iVar3 != 0) {
          memdescDestroy();
          return iVar3;
        }
        uVar7 = (ulong)(-param_3 & 0x78);
        iVar3 = memdescMap(local_40[0],0,*(undefined8 *)(local_40[0] + 0x30),1,3,
                           param_2 + 0x658 + uVar7,param_2 + 0x670 + uVar7);
        if (iVar3 != 0) {
          memdescFree();
          memdescDestroy(local_40[0]);
          return iVar3;
        }
        lVar6 = (ulong)param_3 * 0x78;
        *(code **)(param_2 + 0x660 + lVar6) = _kgmmuClientShadowBufferQueueCopyData;
        *(ulong *)(param_2 + 0x668 + lVar6) = param_2 + 0x648 + uVar7;
        *(long *)(param_2 + 0x650 + lVar6) = local_40[0];
      }
      uVar8 = iVar4 + 0xfffU & 0xfffff000;
      iVar4 = memdescCreate(local_40,param_1,(local_4c + 0xfffU & 0xfffff000) + uVar8,0x1000,0,1,0);
      if (iVar4 == 0) {
        memdescSetPageSize(local_40[0],1,0x200000);
        *(undefined4 *)(local_40[0] + 0x9c) = 0x42;
        iVar4 = memdescAlloc();
        if (iVar4 == 0x51) {
          nvDbg_Printf("src/kernel/gpu/mmu/kern_gmmu.c",0x64c,
                       "_kgmmuClientShadowFaultBufferPagesAllocate",4,
                       "NVRM: Allocation failed with big page size, retrying with default page size\n"
                      );
          memdescSetPageSize(local_40[0],1,0x1000);
          *(undefined4 *)(local_40[0] + 0x9c) = 0x42;
          iVar4 = memdescAlloc();
        }
        if (iVar4 == 0) {
          iVar4 = memdescMap(local_40[0],0,*(undefined8 *)(local_40[0] + 0x30),1,3,
                             param_2 + 0x680 + (ulong)(-param_3 & 0x78));
          if (iVar4 == 0) {
            lVar6 = (ulong)param_3 * 0x78 + param_2;
            *(long *)(lVar6 + 0x678) = local_40[0];
            *(ulong *)(lVar6 + 0x6b8) = (ulong)uVar8 + *(long *)(lVar6 + 0x680);
            iVar4 = (**(code **)(param_2 + 800))(param_1,param_2,param_3);
            if (iVar4 == 0) {
              iVar4 = kgmmuClientShadowFaultBufferRegister_IMPL(param_1,param_2,param_3);
              if (iVar4 == 0) {
                return 0;
              }
              (**(code **)(param_2 + 0x328))(param_1,param_2,param_3);
            }
            lVar6 = (ulong)param_3 * 0x78 + param_2;
            uVar1 = *(undefined8 *)(lVar6 + 0x678);
            memdescUnmap(uVar1,1,*(undefined8 *)(lVar6 + 0x680),*(undefined8 *)(lVar6 + 0x688));
            memdescFree(uVar1);
            memdescDestroy(uVar1);
          }
          else {
            memdescFree();
            memdescDestroy(local_40[0]);
          }
        }
        else {
          memdescDestroy();
        }
      }
      cVar2 = gpuIsCCFeatureEnabled_IMPL(param_1);
      if ((cVar2 != '\0') && (*(char *)(param_1 + 0x4a78) != '\0')) {
        return iVar4;
      }
      param_2 = param_2 + (ulong)param_3 * 0x78;
      uVar1 = *(undefined8 *)(param_2 + 0x650);
      *(undefined8 *)(param_2 + 0x658) = 0;
      *(undefined8 *)(param_2 + 0x650) = 0;
      *(undefined8 *)(param_2 + 0x670) = 0;
      memdescFree(uVar1);
      memdescDestroy(uVar1);
      return iVar4;
    }
    nvAssertFailedNoLog("pStaticInfo->nonReplayableFaultBufferSize != 0",
                        "src/kernel/gpu/mmu/kern_gmmu.c",0x779);
  }
  else {
    nvAssertFailedNoLog("!pKernelGmmu->getProperty(pKernelGmmu, PDB_PROP_KGMMU_FAULT_BUFFER_DISABLED)"
                        ,"src/kernel/gpu/mmu/kern_gmmu.c",0x777);
  }
  return 0x40;
}


// ===== 00408b70 kgmmuClientShadowFaultBufferDestroy_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgmmuClientShadowFaultBufferDestroy_IMPL(long param_1,long param_2,uint param_3)

{
  undefined8 uVar1;
  char cVar2;
  long lVar3;
  ulong uVar4;
  
  uVar4 = (ulong)param_3;
  if (*(long *)(param_2 + 0x638 + uVar4 * 8) != 0) {
    kgmmuClientShadowFaultBufferUnregister_IMPL();
    (**(code **)(param_2 + 0x328))(param_1,param_2,param_3);
    lVar3 = uVar4 * 0x78 + param_2;
    uVar1 = *(undefined8 *)(lVar3 + 0x678);
    memdescUnmap(uVar1,1,*(undefined8 *)(lVar3 + 0x680),*(undefined8 *)(lVar3 + 0x688));
    memdescFree(uVar1);
    memdescDestroy(uVar1);
    cVar2 = gpuIsCCFeatureEnabled_IMPL(param_1);
    if ((cVar2 == '\0') || (*(char *)(param_1 + 0x4a78) == '\0')) {
      lVar3 = uVar4 * 0x78;
      uVar1 = *(undefined8 *)(param_2 + 0x650 + lVar3);
      *(undefined8 *)(param_2 + 0x658 + lVar3) = 0;
      *(undefined8 *)(param_2 + 0x650 + lVar3) = 0;
      *(undefined8 *)(param_2 + 0x670 + lVar3) = 0;
      memdescFree(uVar1);
      memdescDestroy(uVar1);
    }
  }
  return 0;
}


// ===== 00408c80 kgmmuGetMinBigPageSize_IMPL =====

undefined8 kgmmuGetMinBigPageSize_IMPL(void)

{
  return 0x8000;
}


// ===== 00408c90 kgmmuInstBlkInit_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgmmuInstBlkInit_IMPL
              (long param_1,undefined8 param_2,long *param_3,undefined4 param_4,long param_5)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  uint local_68;
  uint local_64;
  undefined4 local_60;
  uint local_5c;
  undefined4 local_58;
  uint local_54;
  undefined4 local_50;
  undefined1 local_4c [4];
  uint local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  
  uVar7 = 0;
  if (param_1 != 0) {
    uVar7 = *(undefined8 *)(param_1 + 0x160);
  }
  lVar5 = gpuEngineGetGpu(uVar7);
  lVar1 = *(long *)(&DAT_00001b90 + lVar5);
  local_54 = 0;
  local_50 = 0;
  iVar3 = (**(code **)(param_1 + 0x1b0))(param_1,param_3,param_4,param_5,&local_68,&local_40);
  if (iVar3 != 0) {
    nvAssertFailedNoLog("(status == NV_OK)","src/kernel/gpu/mmu/kern_gmmu.c",0x819);
    return iVar3;
  }
  iVar3 = (**(code **)(param_1 + 0x1c0))
                    (lVar5,param_1,param_3,param_5,param_4,&local_5c,&local_58,&local_64,&local_60);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,
               "kgmmuInstBlkPageDirBaseGet_HAL(pGpu, pKernelGmmu, pVAS, pInstBlkParams, subctxId, &dirBaseLoOffset, &dirBaseLoData, &dirBaseHiOffset, &dirBaseHiData)"
               ,"src/kernel/gpu/mmu/kern_gmmu.c",0x81c);
    return iVar3;
  }
  if ((param_3 != (long *)0x0) && (cVar2 = (**(code **)(*param_3 + 0xb8))(param_3), cVar2 != '\0'))
  {
    iVar3 = (**(code **)(*param_3 + 0xc0))(param_3,local_4c);
    if (iVar3 == 0) {
      iVar3 = (**(code **)(param_1 + 0x1a8))(param_1,param_3,param_4,&local_54,&local_50);
      if (iVar3 != 0) {
        nvAssertFailedNoLog("(status == NV_OK)","src/kernel/gpu/mmu/kern_gmmu.c",0x82c);
        return iVar3;
      }
    }
    else if (iVar3 != 0x55) {
      nvAssertFailedNoLog("(status == NV_ERR_NOT_READY)","src/kernel/gpu/mmu/kern_gmmu.c",0x831);
      return iVar3;
    }
  }
  iVar3 = (**(code **)(param_1 + 0x1b8))(param_1,&local_48,&local_44);
  lVar6 = *(long *)(param_5 + 8);
  if (lVar6 == 0) {
    uVar7 = *(undefined8 *)(lVar5 + 0x1b78);
    lVar6 = memmgrMemDescBeginTransfer_IMPL(uVar7,param_2,2);
    if (lVar6 == 0) {
      return 0x1a;
    }
    if (local_68 != 0) {
      if (*(char *)(lVar5 + 0x490e) == '\0') {
        *(undefined8 *)((ulong)local_68 + lVar6) = CONCAT44(uStack_3c,local_40);
      }
      else {
        *(undefined4 *)((ulong)local_68 + lVar6) = local_40;
        *(undefined4 *)(lVar6 + 4 + (ulong)local_68) = uStack_3c;
      }
    }
    *(undefined4 *)(lVar6 + (ulong)local_64) = local_60;
    *(undefined4 *)(lVar6 + (ulong)local_5c) = local_58;
    if (local_54 != 0) {
      *(undefined4 *)(lVar6 + (ulong)local_54) = local_50;
    }
    if (iVar3 == 0) {
      *(undefined4 *)(lVar6 + (ulong)local_48) = local_44;
    }
    memmgrMemDescEndTransfer_IMPL(uVar7,param_2,2);
  }
  else {
    if (local_68 != 0) {
      if (*(char *)(lVar5 + 0x490e) == '\0') {
        *(undefined8 *)((ulong)local_68 + lVar6) = CONCAT44(uStack_3c,local_40);
      }
      else {
        *(undefined4 *)((ulong)local_68 + lVar6) = local_40;
        *(undefined4 *)(lVar6 + 4 + (ulong)local_68) = uStack_3c;
      }
    }
    *(undefined4 *)(lVar6 + (ulong)local_64) = local_60;
    *(undefined4 *)(lVar6 + (ulong)local_5c) = local_58;
    if (local_54 != 0) {
      *(undefined4 *)(lVar6 + (ulong)local_54) = local_50;
    }
    if (iVar3 == 0) {
      *(undefined4 *)(lVar6 + (ulong)local_48) = local_44;
      cVar2 = *(char *)(param_5 + 1);
      goto joined_r0x00408e0e;
    }
  }
  cVar2 = *(char *)(param_5 + 1);
joined_r0x00408e0e:
  if (cVar2 == '\0') {
    uVar4 = memdescGetAddressSpace(param_2);
    uVar4 = kbusGetFlushAperture_IMPL(lVar1,uVar4);
    (**(code **)(lVar1 + 0x500))(lVar5,lVar1,uVar4);
  }
  return 0;
}


// ===== 00408fd0 kgmmuGetExternalAllocAperture_IMPL =====

undefined8 kgmmuGetExternalAllocAperture_IMPL(uint param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 4) {
    return 4;
  }
  if (param_1 < 5) {
    if (param_1 == 1) {
      return 4;
    }
    uVar1 = 1;
    if (param_1 != 2) {
LAB_00408ffd:
      nvDbg_Printf("src/kernel/gpu/mmu/kern_gmmu.c",0x892,"kgmmuGetExternalAllocAperture_IMPL",4,
                   "NVRM: Unexpected addressSpace (%u) when mapping to GMMU_APERTURE.\n",param_1);
      nvAssertFailedNoLog(&DAT_00d67bc4,"src/kernel/gpu/mmu/kern_gmmu.c",0x894);
      return 4;
    }
  }
  else {
    uVar1 = 2;
    if (1 < param_1 - 6) goto LAB_00408ffd;
  }
  return uVar1;
}


// ===== 00409060 kgmmuAccessCntrChangeIntrOwnership_IMPL =====

void kgmmuAccessCntrChangeIntrOwnership_IMPL(undefined8 param_1,long param_2,char param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x548) & 0xfffffffe;
  if (param_3 != '\0') {
    uVar1 = *(uint *)(param_2 + 0x548) | 1;
  }
  *(uint *)(param_2 + 0x548) = uVar1;
  return;
}


// ===== 00409080 kgmmuRegisterIntrService_IMPL =====

void kgmmuRegisterIntrService_IMPL(long param_1,long param_2,long param_3)

{
  ushort *puVar1;
  long *plVar2;
  char cVar3;
  ushort *puVar4;
  undefined8 uVar5;
  long lVar6;
  
  if ((*(char *)(param_1 + 0x909) == '\0') || (cVar3 = gpuIsCCFeatureEnabled_IMPL(), cVar3 == '\0'))
  {
    puVar4 = &engineIdxList_5;
  }
  else {
    puVar4 = (ushort *)&engineIdxListForCC_6;
    if (*(char *)(param_1 + 0x4a78) == '\0') {
      puVar4 = &engineIdxList_5;
    }
  }
  puVar1 = puVar4 + 3;
  do {
    plVar2 = (long *)(param_3 + (ulong)*puVar4 * 0x18);
    if (*plVar2 != 0) {
      nvAssertFailedNoLog("pRecords[engineIdx].pInterruptService == NULL",
                          "src/kernel/gpu/mmu/kern_gmmu.c",0x8db);
    }
    lVar6 = 0;
    if (param_2 != 0) {
      lVar6 = *(long *)(param_2 + 0x170);
    }
    puVar4 = puVar4 + 1;
    *plVar2 = lVar6;
  } while (puVar1 != puVar4);
  if (*(char *)(param_1 + 0x909) == '\0') {
    if (*(long *)(param_3 + 0x450) != 0) {
      nvAssertFailedNoLog("pRecords[engineIdx].pInterruptService == NULL",
                          "src/kernel/gpu/mmu/kern_gmmu.c",0x8e2);
    }
    if (param_2 == 0) {
      *(undefined8 *)(param_3 + 0x450) = 0;
      if (*(long *)(param_3 + 0x458) == 0) {
        *(undefined1 *)(param_3 + 0x460) = 0;
        uVar5 = 0;
      }
      else {
        nvAssertFailedNoLog("pRecords[engineIdx].pNotificationService == NULL",
                            "src/kernel/gpu/mmu/kern_gmmu.c",0x8e5);
        uVar5 = 0;
        *(undefined1 *)(param_3 + 0x460) = 0;
      }
    }
    else {
      *(undefined8 *)(param_3 + 0x450) = *(undefined8 *)(param_2 + 0x170);
      if (*(long *)(param_3 + 0x458) != 0) {
        nvAssertFailedNoLog("pRecords[engineIdx].pNotificationService == NULL",
                            "src/kernel/gpu/mmu/kern_gmmu.c",0x8e5);
      }
      *(undefined1 *)(param_3 + 0x460) = 0;
      uVar5 = *(undefined8 *)(param_2 + 0x170);
    }
    *(undefined8 *)(param_3 + 0x458) = uVar5;
    puVar4 = &physicalEngineIdxList_4;
    do {
      plVar2 = (long *)(param_3 + (ulong)*puVar4 * 0x18);
      if (*plVar2 != 0) {
        nvAssertFailedNoLog("pRecords[engineIdx].pInterruptService == NULL",
                            "src/kernel/gpu/mmu/kern_gmmu.c",0x8f1);
      }
      lVar6 = 0;
      if (param_2 != 0) {
        lVar6 = *(long *)(param_2 + 0x170);
      }
      puVar4 = puVar4 + 1;
      *plVar2 = lVar6;
    } while (puVar4 != (ushort *)"kgmmuGetExternalAllocAperture_IMPL");
  }
  return;
}


// ===== 004092c0 kgmmuClearInterrupt_IMPL =====

undefined8 kgmmuClearInterrupt_IMPL(undefined8 param_1,long param_2,short *param_3)

{
  undefined8 uVar1;
  
  if (param_3 == (short *)0x0) {
    nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/mmu/kern_gmmu.c",0x905);
    return 0;
  }
  if (*param_3 != 0x3d) {
    uVar1 = 0;
    if (param_2 != 0) {
      uVar1 = *(undefined8 *)(param_2 + 0x170);
    }
    uVar1 = intrservClearInterrupt_IMPL(param_1,uVar1);
    return uVar1;
  }
  return 1;
}


// ===== 00409310 kgmmuServiceInterrupt_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgmmuServiceInterrupt_IMPL(long param_1,long param_2,ushort *param_3)

{
  ushort uVar1;
  int iVar2;
  bool bVar3;
  
  if (param_3 == (ushort *)0x0) {
    nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/mmu/kern_gmmu.c",0x922);
    return 0;
  }
  uVar1 = *param_3;
  if (uVar1 == 0x3f) {
    iVar2 = (**(code **)(param_2 + 0x2d0))();
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,"Failed to report non-replayable MMU fault buffer overflow error",
                 "src/kernel/gpu/mmu/kern_gmmu.c",0x94c);
    }
  }
  else if (uVar1 < 0x40) {
    if (uVar1 == 0x3d) {
      LOCK();
      bVar3 = *(int *)(param_2 + 0x740) == 1;
      if (bVar3) {
        *(int *)(param_2 + 0x740) = 0;
      }
      UNLOCK();
      if ((bVar3) && (iVar2 = (**(code **)(param_2 + 0x4b8))(), iVar2 != 0)) {
        nvAssertOkFailedNoLog
                  (iVar2,"Failed to service non-replayable MMU fault error",
                   "src/kernel/gpu/mmu/kern_gmmu.c",0x93f);
      }
    }
    else if (uVar1 == 0x3e) {
      iVar2 = (**(code **)(param_2 + 0x2d0))();
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,"Failed to report replayable MMU fault buffer overflow error",
                   "src/kernel/gpu/mmu/kern_gmmu.c",0x961);
      }
    }
    else if (uVar1 != 0x2e) {
      if (uVar1 != 0x3b) goto LAB_00409440;
      iVar2 = (**(code **)(param_2 + 0x2b8))();
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,"Failed to service replayable MMU fault error",
                   "src/kernel/gpu/mmu/kern_gmmu.c",0x957);
      }
    }
  }
  else {
    if (uVar1 == 0xa6) {
      nvDbg_Printf("src/kernel/gpu/mmu/kern_gmmu.c",0x974,"kgmmuServiceInterrupt_IMPL",4,
                   "NVRM: Unexpected replayable interrupt routed to RM. Verify UVM took ownership.\n"
                  );
      return 0;
    }
    if (uVar1 != 0xa7) {
      if (uVar1 != 0x40) {
LAB_00409440:
        nvAssertFailedNoLog("Invalid engineIdx","src/kernel/gpu/mmu/kern_gmmu.c",0x98f);
        return 0;
      }
      if ((*(char *)(param_1 + 0x909) == '\0') || (*(char *)(param_1 + 0x908) != '\0')) {
        iVar2 = (**(code **)(param_2 + 0x4e0))();
        if (iVar2 != 0) {
          nvAssertOkFailedNoLog
                    (iVar2,"Failed to service PRI fault error","src/kernel/gpu/mmu/kern_gmmu.c",
                     0x988);
        }
      }
      else {
        iVar2 = (**(code **)(*(long *)(param_1 + 0x1c20) + 0x208))
                          (param_1,*(long *)(param_1 + 0x1c20),0xf);
        if (iVar2 != 0) {
          nvAssertOkFailedNoLog
                    (iVar2,"Failed to trigger INFO_FAULT doorbell","src/kernel/gpu/mmu/kern_gmmu.c",
                     0x980);
        }
      }
    }
  }
  return 0;
}


// ===== 00409560 kgmmuExtractPteInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgmmuExtractPteInfo_IMPL(long param_1,long param_2,long param_3,long param_4,long param_5)

{
  byte bVar1;
  int *piVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  uint uVar10;
  uint uVar11;
  uint local_40;
  uint local_3c [3];
  
  uVar9 = 0;
  if (param_1 != 0) {
    uVar9 = *(undefined8 *)(param_1 + 0x160);
  }
  lVar7 = gpuEngineGetGpu(uVar9);
  piVar2 = *(int **)(param_4 + 0x20);
  lVar3 = *(long *)(lVar7 + 0x1b78);
  bVar1 = *(byte *)(piVar2 + 4);
  uVar10 = (*(uint *)(param_2 + (ulong)*(ushort *)((long)piVar2 + 0xe)) & piVar2[1]) >>
           ((byte)(short)piVar2[3] & 0x1f);
  uVar6 = *(uint *)(param_3 + 0x18);
  uVar11 = bVar1 ^ uVar10;
  *(uint *)(param_3 + 0x18) = uVar6 & 0xfffffffe | uVar11 & 1;
  if (*piVar2 != 3) {
    *(uint *)(param_3 + 0x18) =
         uVar6 & 0xfffffff8 | uVar11 & 1 |
         (uint)(byte)((byte)((*(uint *)(param_2 + (ulong)*(ushort *)((long)piVar2 + 0x156)) &
                             piVar2[0x53]) >> ((byte)(short)piVar2[0x55] & 0x1f)) ^
                     *(byte *)(piVar2 + 0x56)) * 2 & 6;
  }
  if (*(byte *)(piVar2 + 9) != 0) {
    lVar8 = 0;
    do {
      if ((*(char *)(*(long *)(piVar2 + 10) + lVar8 * 2) != '\0') &&
         ((*(uint *)(param_2 + (ulong)*(ushort *)((long)piVar2 + 0x22)) & piVar2[6]) >>
          ((byte)(short)piVar2[8] & 0x1f) == (uint)*(byte *)(*(long *)(piVar2 + 10) + 1 + lVar8 * 2)
         )) {
        uVar6 = (uint)lVar8;
        if (uVar6 == 3) {
          *(uint *)(param_3 + 0x18) = *(uint *)(param_3 + 0x18) & 0xffffff87 | 0x18;
          goto LAB_00409685;
        }
        if (uVar6 < 4) {
          if (uVar6 == 1) {
            *(uint *)(param_3 + 0x18) = *(uint *)(param_3 + 0x18) & 0xffffff87;
            goto LAB_00409685;
          }
          if (uVar6 == 2) {
            *(uint *)(param_3 + 0x18) = *(uint *)(param_3 + 0x18) & 0xffffff87 | 8;
            iVar5 = *piVar2;
            goto joined_r0x004097c4;
          }
        }
        else if (uVar6 == 4) {
          *(uint *)(param_3 + 0x18) = *(uint *)(param_3 + 0x18) & 0xffffff87 | 0x10;
          goto LAB_00409685;
        }
        break;
      }
      lVar8 = lVar8 + 1;
    } while ((uint)lVar8 < (uint)*(byte *)(piVar2 + 9));
  }
  nvAssertFailedNoLog(&DAT_00d67bc4,"src/kernel/gpu/mmu/kern_gmmu.c",0x9d2);
  uVar11 = uVar11 & 0xff;
LAB_00409685:
  iVar5 = *piVar2;
joined_r0x004097c4:
  if (iVar5 == 3) {
    lVar7 = *(long *)(lVar7 + 0x1b98);
    local_40 = 0;
    iVar5 = (**(code **)(lVar7 + 0x288))
                      (lVar7,(*(uint *)(param_2 + (ulong)*(ushort *)((long)piVar2 + 0x1aa)) &
                             piVar2[0x68]) >> ((byte)(short)piVar2[0x6a] & 0x1f),uVar11 & 0xff,
                       &local_40);
    if (iVar5 != 0) {
      nvAssertFailedNoLog("kgmmuTranslatePtePcfFromHw_HAL(pKernelGmmu, ptePcfHw, bPteValid, &ptePcfSw) == NV_OK"
                          ,"src/kernel/gpu/mmu/kern_gmmu.c",0x9de);
    }
    if (bVar1 == (byte)uVar10) {
      if (*(char *)(param_5 + 4) == '\0') {
        uVar6 = *(uint *)(param_3 + 0x18) & 0xffffe7ff;
        if ((local_40 & 4) == 0) {
          uVar6 = uVar6 | 0x800;
        }
        *(uint *)(param_3 + 0x18) = uVar6;
      }
      else {
        lVar8 = *(long *)(param_4 + 0x10);
        local_3c[0] = 0;
        iVar5 = (**(code **)(lVar7 + 0x298))
                          (lVar7,(*(uint *)(param_2 + (ulong)*(ushort *)(lVar8 + 0xfa)) &
                                 *(uint *)(lVar8 + 0xf0)) >>
                                 ((byte)*(undefined2 *)(lVar8 + 0xf8) & 0x1f),0,local_3c);
        if (iVar5 != 0) {
          nvAssertFailedNoLog("kgmmuTranslatePdePcfFromHw_HAL(pKernelGmmu, pdePcfHw, GMMU_APERTURE_INVALID, &pdePcfSw) == NV_OK"
                              ,"src/kernel/gpu/mmu/kern_gmmu.c",0xa12);
        }
        uVar6 = *(uint *)(param_3 + 0x18) & 0xffffe7ff;
        if ((local_3c[0] & 4) == 0) {
          uVar6 = uVar6 | 0x800;
        }
        *(uint *)(param_3 + 0x18) = uVar6;
      }
    }
    else {
      if ((local_40 & 0x20) == 0) {
        *(uint *)(param_3 + 0x18) = *(uint *)(param_3 + 0x18) & 0xffffe7ff | 0x800;
      }
      if ((local_40 & 0x80) != 0) {
        *(uint *)(param_3 + 0x18) = *(uint *)(param_3 + 0x18) | 0x8000;
      }
      if ((local_40 & 0x40) != 0) {
        *(uint *)(param_3 + 0x18) = *(uint *)(param_3 + 0x18) & 0xfffeffff;
      }
      if ((local_40 & 0x100) != 0) {
        *(uint *)(param_3 + 0x18) = *(uint *)(param_3 + 0x18) & 0xfffbffff;
      }
      if ((local_40 & 0x10) != 0) {
        *(uint *)(param_3 + 0x18) = *(uint *)(param_3 + 0x18) | 0x20000;
      }
    }
  }
  else {
    uVar6 = *(uint *)(param_3 + 0x18);
    uVar11 = (uint)((char)piVar2[0x42] ==
                   (char)((*(uint *)(param_2 + (ulong)*(ushort *)((long)piVar2 + 0x106)) &
                          piVar2[0x3f]) >> ((byte)(short)piVar2[0x41] & 0x1f))) << 0xb;
    uVar10 = uVar11 | uVar6 & 0xffffe7ff;
    *(uint *)(param_3 + 0x18) = uVar10;
    if ((piVar2[0x47] == 0) || (piVar2[0x4b] == 0)) {
      uVar11 = uVar10 | 0x6000;
    }
    else {
      uVar11 = uVar11 | uVar6 & 0xffff87ff;
      if ((char)piVar2[0x4e] ==
          (char)((piVar2[0x4b] & *(uint *)(param_2 + (ulong)*(ushort *)((long)piVar2 + 0x136))) >>
                ((byte)(short)piVar2[0x4d] & 0x1f))) {
        if ((char)piVar2[0x4a] !=
            (char)((piVar2[0x47] & *(uint *)(param_2 + (ulong)*(ushort *)((long)piVar2 + 0x126))) >>
                  ((byte)(short)piVar2[0x49] & 0x1f))) {
          uVar11 = uVar11 | 0x4000;
        }
      }
      else {
        uVar11 = uVar11 | 0x2000;
      }
    }
    *(uint *)(param_3 + 0x18) = uVar11;
    *(uint *)(param_3 + 0x18) =
         ((byte)((byte)((*(uint *)(param_2 + (ulong)*(ushort *)((long)piVar2 + 0x116)) &
                        piVar2[0x43]) >> ((byte)(short)piVar2[0x45] & 0x1f)) ^
                *(byte *)(piVar2 + 0x46)) & 1) << 0xf | uVar11 & 0xffff7fff;
    *(uint *)(param_3 + 0x10) =
         (*(uint *)(param_2 + (ulong)*(ushort *)((long)piVar2 + 0x192)) & piVar2[0x62]) >>
         ((byte)(short)piVar2[100] & 0x1f);
  }
  *(uint *)(param_3 + 0x14) =
       (*(uint *)(param_2 + (ulong)*(ushort *)((long)piVar2 + 0x186)) & piVar2[0x5f]) >>
       ((byte)(short)piVar2[0x61] & 0x1f);
  cVar4 = (**(code **)(lVar3 + 0x2a8))(lVar3,6);
  if (cVar4 == '\0') {
    cVar4 = (**(code **)(lVar3 + 0x2a8))(lVar3,7,*(undefined4 *)(param_3 + 0x14));
    if (cVar4 == '\0') {
      cVar4 = (**(code **)(lVar3 + 0x2a8))(lVar3,8,*(undefined4 *)(param_3 + 0x14));
      uVar6 = *(uint *)(param_3 + 0x18) & 0xfffff87f;
      if (cVar4 != '\0') {
        uVar6 = uVar6 | 0x200;
      }
    }
    else {
      uVar6 = *(uint *)(param_3 + 0x18) & 0xfffff87f | 0x100;
    }
  }
  else {
    uVar6 = *(uint *)(param_3 + 0x18) & 0xfffff87f | 0x80;
  }
  *(uint *)(param_3 + 0x18) = uVar6;
  return;
}


// ===== 00409a80 kgmmuGetFatalFaultIntrPendingState_IMPL =====

long kgmmuGetFatalFaultIntrPendingState_IMPL(long param_1,byte param_2)

{
  return param_1 + 0x740 + (ulong)param_2 * 0x188;
}


// ===== 00409aa0 kgmmuGetShadowFaultBufferCslContext_IMPL =====

undefined8 kgmmuGetShadowFaultBufferCslContext_IMPL(long param_1,undefined8 param_2,int param_3)

{
  long lVar1;
  char cVar2;
  
  lVar1 = *(long *)(param_1 + 0x1d18);
  cVar2 = gpuIsCCFeatureEnabled_IMPL();
  if (cVar2 != '\0') {
    if (param_3 == 0) {
      return *(undefined8 *)(lVar1 + 0x2d0);
    }
    if (param_3 == 1) {
      return *(undefined8 *)(lVar1 + 0x2d8);
    }
  }
  return 0;
}


// ===== 00409af0 kgmmuFaultBufferMap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgmmuFaultBufferMap_IMPL(long param_1,long param_2,uint param_3,uint param_4)

{
  long lVar1;
  char cVar2;
  ulong uVar3;
  long lVar4;
  undefined8 *puVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  uint uVar9;
  ulong uVar10;
  undefined1 auVar11 [16];
  undefined8 local_40 [2];
  
  if (*(char *)(param_2 + 0x511) != '\0') {
    return 0;
  }
  if (param_3 < 2) {
    if (*(char *)(param_1 + 0x909) == '\0') {
      uVar6 = (ulong)param_3;
      lVar8 = uVar6 * 0x30 + (ulong)param_4 * 0x188 + param_2;
      lVar1 = *(long *)(lVar8 + 0x5d0);
      (**(code **)(*(long *)(param_1 + 0x1b78) + 0x388))
                (param_1,*(long *)(param_1 + 0x1b78),lVar1,1,1);
      uVar3 = (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x218))
                        (param_1,*(long *)(&DAT_00001b90 + param_1),lVar1,local_40,
                         *(undefined8 *)(lVar1 + 0x30),0);
      if ((int)uVar3 == 0) {
        if (*(long *)(lVar8 + 0x5c8) != 0) {
          nvAssertFailedNoLog("pFaultBuffer->bar2FaultBufferAddr == 0",
                              "src/kernel/gpu/mmu/kern_gmmu.c",0xabf);
          uVar3 = uVar3 & 0xffffffff;
        }
        lVar8 = uVar6 * 0x30;
        *(undefined8 *)(param_2 + 0x5c8 + (ulong)param_4 * 0x188 + lVar8) = local_40[0];
        if (param_4 == 0) {
          if (*(int *)(lVar1 + 0x68) == 2) {
            auVar11 = memdescMapInternal(param_1,lVar1,0);
            lVar4 = auVar11._8_8_;
            *(long *)(param_2 + 0x5e0 + lVar8) = auVar11._0_8_;
            if (auVar11._0_8_ != 0) {
LAB_00409c60:
              cVar2 = memdescGetContiguity(lVar1,1,lVar4);
              if (cVar2 == '\0') {
                if (*(long *)(lVar1 + 0x30) != 0) {
                  uVar3 = 0;
                  do {
                    uVar9 = (int)uVar3 + 1;
                    portMemSet(*(undefined8 *)
                                (uVar3 * 0x10 + *(long *)(uVar6 * 0x30 + param_2 + 0x5e8)),0,0x1000)
                    ;
                    uVar3 = (ulong)uVar9;
                  } while ((ulong)(uVar9 * 0x1000) < *(ulong *)(lVar1 + 0x30));
                }
              }
              else {
                portMemSet(*(undefined8 *)(param_2 + 0x5e0 + uVar6 * 0x30),0);
              }
              return 0;
            }
            nvAssertFailedNoLog(&DAT_00d67bc4,"src/kernel/gpu/mmu/kern_gmmu.c",0xacf);
            uVar3 = 0x1e;
          }
          else {
            cVar2 = memdescGetContiguity(lVar1,1);
            if (cVar2 == '\0') {
              uVar10 = *(long *)(lVar1 + 0x30) + 0xfffU >> 0xc;
              uVar3 = uVar10 & 0xffffffff;
              auVar11 = portMemAllocNonPaged(uVar3 << 4);
              lVar4 = auVar11._8_8_;
              lVar7 = auVar11._0_8_;
              *(long *)(param_2 + lVar8 + 0x5e8) = lVar7;
              if (lVar7 == 0) {
                uVar3 = 0x51;
              }
              else {
                if ((int)uVar10 == 0) goto LAB_00409c60;
                uVar10 = 0;
                while( true ) {
                  lVar4 = lVar7 + uVar10 * 0x10 + 8;
                  uVar9 = memdescMap(lVar1,(int)uVar10 << 0xc,0x1000,1);
                  if (uVar9 != 0) break;
                  uVar10 = uVar10 + 1;
                  if (uVar3 == uVar10) goto LAB_00409c60;
                  lVar7 = *(long *)(param_2 + lVar8 + 0x5e8);
                }
                if ((int)uVar10 != 0) {
                  lVar8 = 0;
                  do {
                    puVar5 = (undefined8 *)(lVar8 + *(long *)(uVar6 * 0x30 + param_2 + 0x5e8));
                    memdescUnmap(lVar1,1,*puVar5,puVar5[1]);
                    lVar8 = lVar8 + 0x10;
                  } while (lVar8 != uVar10 * 0x10);
                }
                portMemFree(*(undefined8 *)(param_2 + 0x5e8 + uVar6 * 0x30));
                uVar3 = (ulong)uVar9;
              }
            }
            else {
              auVar11 = memdescMap(lVar1,0,*(long *)(lVar1 + 0x30),1,3,
                                   param_2 + 0x5e0 + (ulong)(-param_3 & 0x30),
                                   param_2 + 0x5d8 + (ulong)(-param_3 & 0x30));
              lVar4 = auVar11._8_8_;
              uVar3 = auVar11._0_8_;
              if (auVar11._0_4_ == 0) goto LAB_00409c60;
            }
          }
        }
      }
    }
    else {
      nvAssertFailedNoLog("!IS_GSP_CLIENT(pGpu)","src/kernel/gpu/mmu/kern_gmmu.c",0xab0);
      uVar3 = 0x40;
    }
  }
  else {
    nvAssertFailedNoLog("(index < NUM_FAULT_BUFFERS)","src/kernel/gpu/mmu/kern_gmmu.c",0xaaf);
    uVar3 = 0x1f;
  }
  return uVar3;
}


// ===== 00409f30 kgmmuFaultBufferUnmap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgmmuFaultBufferUnmap_IMPL(long param_1,long param_2,uint param_3,uint param_4)

{
  char cVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  
  if (param_3 < 2) {
    if (*(char *)(param_2 + 0x511) == '\0') {
      uVar8 = (ulong)param_4;
      uVar4 = (ulong)param_3;
      lVar2 = uVar4 * 0x30;
      lVar5 = *(long *)(param_2 + 0x5d0 + uVar8 * 0x188 + lVar2);
      if (lVar5 != 0) {
        if (param_4 == 0) {
          if (*(int *)(lVar5 + 0x68) == 2) {
            memdescUnmapInternal(param_1,lVar5,0);
            *(undefined8 *)(param_2 + 0x5e0 + lVar2) = 0;
            lVar5 = *(long *)(param_2 + 0x5d0 + lVar2);
          }
          else {
            cVar1 = memdescGetContiguity(lVar5,1);
            lVar2 = param_2 + lVar2;
            if (cVar1 == '\0') {
              lVar5 = *(long *)(lVar2 + 0x5e8);
              if (lVar5 == 0) {
                lVar5 = *(long *)(lVar2 + 0x5d0);
              }
              else {
                lVar7 = *(long *)(lVar2 + 0x5d0);
                iVar3 = (int)(*(long *)(lVar7 + 0x30) + 0xfffU >> 0xc);
                if (iVar3 != 0) {
                  lVar6 = 0;
                  while( true ) {
                    memdescUnmap(lVar7,1,*(undefined8 *)(lVar5 + lVar6),
                                 ((undefined8 *)(lVar5 + lVar6))[1]);
                    lVar5 = *(long *)(lVar2 + 0x5e8);
                    if ((ulong)(iVar3 - 1) << 4 == lVar6) break;
                    lVar7 = *(long *)(lVar2 + 0x5d0);
                    lVar6 = lVar6 + 0x10;
                  }
                }
                portMemFree();
                lVar5 = *(long *)(param_2 + 0x5d0 + uVar4 * 0x30);
              }
            }
            else {
              memdescUnmap(*(undefined8 *)(lVar2 + 0x5d0),1,*(undefined8 *)(lVar2 + 0x5e0),
                           *(undefined8 *)(lVar2 + 0x5d8));
              lVar5 = *(long *)(lVar2 + 0x5d0);
            }
          }
        }
        (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x220))
                  (param_1,*(long *)(&DAT_00001b90 + param_1),lVar5,
                   *(undefined8 *)(param_2 + 0x5c8 + uVar4 * 0x30 + uVar8 * 0x188),param_4);
      }
      lVar2 = uVar4 * 0x30 + uVar8 * 0x188;
      *(undefined8 *)(param_2 + 0x5e8 + lVar2) = 0;
      *(undefined8 *)(param_2 + 0x5e0 + lVar2) = 0;
      *(undefined8 *)(param_2 + 0x5c8 + lVar2) = 0;
    }
    return 0;
  }
  nvAssertFailedNoLog("(index < NUM_FAULT_BUFFERS)","src/kernel/gpu/mmu/kern_gmmu.c",0xb24);
  return 0x1f;
}


// ===== 0040a190 kgmmuServiceVfPriFaults_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgmmuServiceVfPriFaults_IMPL(long param_1,undefined8 param_2,int param_3)

{
  undefined8 uVar1;
  long lVar2;
  int local_1c [3];
  
  if (*(char *)(param_1 + 0x4913) == '\0') {
    nvAssertFailedNoLog("IS_VIRTUAL_WITH_SRIOV(pGpu)","src/kernel/gpu/mmu/kern_gmmu.c",0xb73);
    return 0x1f;
  }
  uVar1 = 0x3b;
  if (param_3 != 0) {
    portMemSet(local_1c,0,4);
    local_1c[0] = param_3;
    lVar2 = gpuGetRpc(param_1);
    if (lVar2 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mmu/kern_gmmu.c",0xb7b);
      return 0x1a;
    }
    if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) {
      uVar1 = rpcDmaControl_wrapper
                        (param_1,lVar2,*(undefined4 *)(param_1 + 0x3b18),
                         *(undefined4 *)(param_1 + 0x3b20),0x20800192,local_1c,4);
      return uVar1;
    }
    uVar1 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b18),
                       *(undefined4 *)(param_1 + 0x3b20),0x20800192,local_1c,4);
  }
  return uVar1;
}


// ===== 0040a2a0 kgmmuFaultCancelTargeted_VF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgmmuFaultCancelTargeted_VF(long param_1,long param_2,undefined8 param_3)

{
  undefined1 local_58 [12];
  undefined4 local_4c;
  undefined1 local_40 [32];
  
  portMemSet(local_58,0,0x30);
  timeoutSet(param_1 + 0x1af0,local_40,0,0);
  local_4c = 0;
  (**(code **)(param_2 + 0x4b0))(param_1,param_2,param_3,local_58,0);
  return;
}


// ===== 0040a310 kgmmuGetFaultBufferReservedFbSpaceSize_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgmmuGetFaultBufferReservedFbSpaceSize_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_2c;
  
  iVar3 = 0;
  if (*(char *)(param_2 + 0x511) == '\0') {
    iVar2 = 0;
    while( true ) {
      iVar1 = kgmmuFaultBufferGetAddressSpace_IMPL(param_1,param_2,iVar2,&local_2c,0);
      if (iVar1 == 0) {
        if (local_2c == 2) {
          iVar1 = (**(code **)(param_2 + 0x418))(param_1,param_2,iVar2,0);
          iVar3 = iVar3 + (iVar1 + 0xfffU & 0xfffff000);
        }
      }
      else {
        nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mmu/kern_gmmu.c",0xbaa);
      }
      if (iVar2 == 1) break;
      iVar2 = 1;
    }
  }
  return iVar3;
}


// ===== 0040a3d0 subdeviceCtrlCmdGmmuGetStaticInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdGmmuGetStaticInfo_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1b98);
  uVar4 = (**(code **)(lVar2 + 0x418))(lVar1,lVar2,1,0);
  *param_2 = uVar4;
  uVar4 = (**(code **)(lVar2 + 0x418))(lVar1,lVar2,0,0);
  param_2[2] = uVar4;
  cVar3 = gpuIsCCFeatureEnabled_IMPL(lVar1);
  if ((cVar3 != '\0') && (*(char *)(lVar1 + 0x4a78) != '\0')) {
    param_2[1] = *param_2 & 0xffffffe0;
    param_2[3] = param_2[2] & 0xffffffe0;
  }
  return 0;
}


// ===== 0040a470 kgmmuFaultBufferReplayableSetup_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgmmuFaultBufferReplayableSetup_IMPL
                (long param_1,long param_2,undefined4 param_3,undefined4 param_4,int param_5,
                undefined8 *param_6)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  undefined4 local_44;
  undefined8 local_40 [2];
  
  if (((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(param_1 + 0x4913) == '\0')) ||
     (*(char *)(param_2 + 0x511) != '\0')) {
    return 0;
  }
  if (*(long *)(param_2 + 0x600) != 0) {
    return 0x56;
  }
  local_40[0] = 0;
  local_44 = 0;
  uVar4 = kgmmuFaultBufferCreateMemDesc_IMPL(param_1,param_2,1,param_5,0x800100,local_40);
  uVar1 = local_40[0];
  if ((int)uVar4 == 0) {
    *(int *)(param_2 + 0x624) = param_5;
    *(undefined8 *)(param_2 + 0x600) = 0;
    cVar2 = memdescGetContiguity(local_40[0],1);
    if (cVar2 == '\0') {
      memdescFillPages(uVar1,0,param_6,param_5 + 0xfffU >> 0xc,0x1000);
    }
    else {
      iVar3 = kgmmuFaultBufferGetAddressSpace_IMPL(param_1,param_2,1,&local_44,0);
      if (iVar3 != 0) {
        memdescDestroy(uVar1);
        return 0x1f;
      }
      memdescDescribe(uVar1,local_44,*param_6,param_5);
    }
    *(undefined8 *)(param_2 + 0x600) = uVar1;
    uVar4 = (**(code **)(param_2 + 0x3f8))(param_1,param_2,1,0);
    if ((int)uVar4 == 0) {
      *(undefined4 *)(param_2 + 0x628) = param_3;
      *(undefined4 *)(param_2 + 0x62c) = param_4;
      *(undefined1 *)(param_2 + 0x512) = 1;
      return uVar4;
    }
    uVar1 = *(undefined8 *)(param_2 + 0x600);
    *(undefined4 *)(param_2 + 0x624) = 0;
    *(undefined8 *)(param_2 + 0x600) = 0;
    memdescDestroy(uVar1);
    uVar4 = uVar4 & 0xffffffff;
  }
  return uVar4;
}


// ===== 0040a640 subdeviceCtrlCmdInternalGmmuRegisterFaultBuffer_IMPL =====

void subdeviceCtrlCmdInternalGmmuRegisterFaultBuffer_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined8 *)(lVar1 + 0x1b98);
  nvDbg_Printf("src/kernel/gpu/mmu/kern_gmmu.c",0xc4c,
               "subdeviceCtrlCmdInternalGmmuRegisterFaultBuffer_IMPL",1,
               "NVRM: GMMU_REGISTER_FAULT_BUFFER\n");
  kgmmuFaultBufferReplayableSetup_IMPL(lVar1,uVar2,*param_2,param_2[1],param_2[2],param_2 + 4);
  return;
}


// ===== 0040a6c0 subdeviceCtrlCmdInternalGmmuUnregisterFaultBuffer_IMPL =====

undefined8 subdeviceCtrlCmdInternalGmmuUnregisterFaultBuffer_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1b98);
  nvDbg_Printf("src/kernel/gpu/mmu/kern_gmmu.c",0xc5e,
               "subdeviceCtrlCmdInternalGmmuUnregisterFaultBuffer_IMPL",1,
               "NVRM: GMMU_UNREGISTER_FAULT_BUFFER\n");
  kgmmuFaultBufferReplayableDestroy_IMPL(lVar1,lVar2);
  *(undefined1 *)(lVar2 + 0x512) = 0;
  return 0;
}


// ===== 0040a720 subdeviceCtrlCmdGmmuCommitTlbInvalidate_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdGmmuCommitTlbInvalidate_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  long lVar2;
  undefined4 local_10;
  undefined1 local_c;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  local_10 = *param_2;
  local_c = *(undefined1 *)(param_2 + 1);
  lVar2 = *(long *)(lVar1 + 0x1b98);
  (**(code **)(lVar2 + 0x1f0))(lVar1,lVar2,&local_10);
  return;
}


// ===== 0040a770 kgmmuCheckMemSubsysError_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1  [16] kgmmuCheckMemSubsysError_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined1 auVar2 [16];
  int iVar3;
  ulong extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  undefined8 extraout_RDX_02;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined8 uVar6;
  
  if (*(char *)(param_1 + 0x4b28) == '\0') {
    nvDbg_Printf("src/kernel/gpu/mmu/kern_gmmu.c",0xc8f,"kgmmuCheckMemSubsysError_IMPL",3,
                 "NVRM: Memory Subsystem Error detection disabled.\n");
    auVar2._8_8_ = 0;
    auVar2._0_8_ = extraout_RDX;
    return auVar2 << 0x40;
  }
  lVar1 = *(long *)(&DAT_00001b90 + param_1);
  iVar3 = (**(code **)(param_2 + 0x1e8))(param_1,param_2,0,0,1,0,0,0);
  if (iVar3 == 0x65) {
    nvDbg_Printf("src/kernel/gpu/mmu/kern_gmmu.c",0xc9b,"kgmmuCheckMemSubsysError_IMPL",4,
                 "NVRM: Memory Subsystem Error detected. kgmmuInvalidateTlb failed.\n");
    uVar6 = extraout_RDX_01;
  }
  else {
    iVar3 = (**(code **)(lVar1 + 0x3e0))(param_1,lVar1);
    if (iVar3 == 0x65) {
      nvDbg_Printf("src/kernel/gpu/mmu/kern_gmmu.c",0xca6,"kgmmuCheckMemSubsysError_IMPL",4,
                   "NVRM: Memory Subsystem Error detected. kbusSendSysmembarSingle failed.\n");
      uVar6 = extraout_RDX_02;
    }
    else {
      uVar6 = 0;
      auVar4._0_8_ = (**(code **)(param_2 + 0x1e8))(param_1,param_2,0,0,1,0,0,1);
      if ((int)auVar4._0_8_ != 0x65) {
        auVar4._8_8_ = uVar6;
        return auVar4;
      }
      nvDbg_Printf("src/kernel/gpu/mmu/kern_gmmu.c",0xcb6,"kgmmuCheckMemSubsysError_IMPL",4,
                   "NVRM: Memory Subsystem Error detected. kgmmuInvalidateTlb with sysmembar failed.\n"
                  );
      uVar6 = extraout_RDX_00;
    }
  }
  auVar5._8_8_ = uVar6;
  auVar5._0_8_ = 0x72;
  return auVar5;
}


// ===== 0040a8f0 faultbufConstruct_IMPL =====

int faultbufConstruct_IMPL(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  char cVar5;
  int iVar6;
  long lVar7;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar1 = *(undefined4 *)(*(long *)(param_2 + 8) + 0x48);
  lVar4 = *(long *)(lVar3 + 0x1b98);
  uVar2 = *(undefined4 *)(*(long *)(param_2 + 0x10) + 0x10);
  lVar7 = __nvoc_dynamicCast(*(long *)(param_2 + 8),__nvoc_class_def_RmClient);
  if (lVar7 == 0) {
    iVar6 = 0x23;
    nvAssertFailedNoLog("pRmClient != NULL","src/kernel/gpu/mmu/mmu_fault_buffer.c",0x30);
  }
  else {
    cVar5 = gpuIsClassSupported_IMPL(lVar3,*(undefined4 *)(param_3 + 0xc));
    if (cVar5 == '\0') {
      iVar6 = 0x22;
      nvDbg_Printf("src/kernel/gpu/mmu/mmu_fault_buffer.c",0x34,"faultbufConstruct_IMPL",4,
                   "NVRM: class %x not supported\n",*(undefined4 *)(param_3 + 0xc));
    }
    else if (lVar4 == 0) {
      iVar6 = 0x56;
      nvAssertFailedNoLog("pKernelGmmu != NULL","src/kernel/gpu/mmu/mmu_fault_buffer.c",0x39);
    }
    else {
      iVar6 = kgmmuFaultBufferReplayableAllocate_IMPL(lVar3,lVar4,uVar1,uVar2);
      if (iVar6 != 0) {
        nvDbg_Printf("src/kernel/gpu/mmu/mmu_fault_buffer.c",0x40,"faultbufConstruct_IMPL",4,
                     "NVRM: Failed to setup Replayable Fault buffer (status=0x%08x).\n",iVar6);
      }
    }
  }
  return iVar6;
}


// ===== 0040aa40 faultbufDestruct_IMPL =====

void faultbufDestruct_IMPL(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  kgmmuFaultBufferReplayableDestroy_IMPL(lVar1,*(undefined8 *)(lVar1 + 0x1b98));
  return;
}


// ===== 0040aa60 faultbufMap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 faultbufMap_IMPL(undefined8 param_1,long param_2,undefined8 param_3,long param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long *plVar3;
  long lVar4;
  undefined8 uVar5;
  undefined1 local_2a;
  undefined1 local_29;
  
  plVar3 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_2 + 8),__nvoc_class_def_RmClient);
  local_2a = 1;
  lVar4 = CliGetGpuFromContext(*(undefined8 *)(param_4 + 0x20),&local_2a);
  if (lVar4 == 0) {
    nvAssertFailedNoLog("pGpu != NULL","src/kernel/gpu/mmu/mmu_fault_buffer.c",0x67);
  }
  else {
    lVar4 = *(long *)(lVar4 + 0x1b98);
    if (lVar4 != 0) {
      uVar2 = *(undefined4 *)(param_4 + 0x10);
      uVar1 = (**(code **)(*plVar3 + 0xd8))(plVar3);
      uVar5 = rmapiValidateKernelMapping(uVar1,uVar2,&local_29);
      if ((int)uVar5 != 0) {
        return uVar5;
      }
      uVar2 = osGetCurrentProcess();
      *(undefined4 *)(param_4 + 0x48) = uVar2;
      uVar5 = memdescMap(*(long *)(lVar4 + 0x600),0,*(undefined8 *)(*(long *)(lVar4 + 0x600) + 0x30)
                         ,local_29,*(undefined4 *)(*(long *)(param_4 + 0x50) + 0x20),param_4 + 0x18,
                         *(long *)(param_4 + 0x50) + 0x18);
      *(undefined8 *)(lVar4 + 0x608) = *(undefined8 *)(*(long *)(param_4 + 0x50) + 0x18);
      return uVar5;
    }
    nvAssertFailedNoLog("pKernelGmmu != NULL","src/kernel/gpu/mmu/mmu_fault_buffer.c",0x6c);
  }
  return 0x1f;
}


// ===== 0040abb0 faultbufUnmap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int faultbufUnmap_IMPL(undefined8 param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  undefined1 local_2a;
  undefined1 local_29;
  
  plVar4 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_2 + 8),__nvoc_class_def_RmClient);
  local_2a = 1;
  lVar5 = CliGetGpuFromContext(*(undefined8 *)(param_3 + 0x20),&local_2a);
  if (lVar5 == 0) {
    nvAssertFailedNoLog("pGpu != NULL","src/kernel/gpu/mmu/mmu_fault_buffer.c",0x95);
  }
  else {
    lVar5 = *(long *)(lVar5 + 0x1b98);
    if (lVar5 != 0) {
      uVar1 = *(undefined4 *)(param_3 + 0x10);
      uVar2 = (**(code **)(*plVar4 + 0xd8))(plVar4);
      iVar3 = rmapiValidateKernelMapping(uVar2,uVar1,&local_29);
      if (iVar3 != 0) {
        return iVar3;
      }
      memdescUnmap(*(undefined8 *)(lVar5 + 0x600),local_29,*(undefined8 *)(param_3 + 0x18),
                   *(undefined8 *)(lVar5 + 0x608));
      return 0;
    }
    nvAssertFailedNoLog("pKernelGmmu != NULL","src/kernel/gpu/mmu/mmu_fault_buffer.c",0x99);
  }
  return 0x1f;
}


// ===== 0040acd0 faultbufGetMapAddrSpace_IMPL =====

ulong faultbufGetMapAddrSpace_IMPL
                (long param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  ulong uVar1;
  undefined4 local_1c;
  
  if (*(long *)(*(long *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x1b98) + 0x600) != 0) {
    uVar1 = rmapiGetEffectiveAddrSpace();
    if ((int)uVar1 == 0) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = local_1c;
      }
    }
    else {
      nvAssertOkFailedNoLog
                (uVar1 & 0xffffffff,
                 "rmapiGetEffectiveAddrSpace(pGpu, pMemDesc, mapFlags, &addrSpace)",
                 "src/kernel/gpu/mmu/mmu_fault_buffer.c",0xbc);
      uVar1 = uVar1 & 0xffffffff;
    }
    return uVar1;
  }
  return 0x31;
}


// ===== 0040ad60 faultbufCtrlCmdMmuFaultBufferRegisterNonReplayBuf_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int faultbufCtrlCmdMmuFaultBufferRegisterNonReplayBuf_IMPL(long param_1,undefined8 *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1b98);
  lVar5 = kgmmuGetStaticInfo_IMPL(lVar1,lVar2);
  if (*(long *)(lVar2 + 0x638) == 0) {
    iVar4 = (**(code **)(lVar2 + 0x310))(lVar1,lVar2,0);
    if (iVar4 == 0) {
      lVar2 = *(long *)(lVar2 + 0x638);
      cVar3 = gpuIsCCFeatureEnabled_IMPL(lVar1);
      if ((cVar3 == '\0') || (*(char *)(lVar1 + 0x4a78) == '\0')) {
        uVar6 = *(undefined8 *)(lVar2 + 0x10);
        param_2[1] = lVar2 + 0x18;
        *param_2 = uVar6;
        uVar6 = 0;
      }
      else {
        uVar6 = *(undefined8 *)(lVar2 + 0x38);
        param_2[1] = 0;
        *param_2 = uVar6;
        uVar6 = *(undefined8 *)(lVar2 + 0x70);
      }
      param_2[2] = uVar6;
      *(undefined4 *)(param_2 + 3) = *(undefined4 *)(lVar5 + 8);
    }
    else {
      nvDbg_Printf("src/kernel/gpu/mmu/mmu_fault_buffer_ctrl.c",0x3f,
                   "faultbufCtrlCmdMmuFaultBufferRegisterNonReplayBuf_IMPL",4,
                   "NVRM: Error allocating client shadow fault buffer for non-replayable faults\n");
    }
  }
  else {
    iVar4 = 0x56;
    nvDbg_Printf("src/kernel/gpu/mmu/mmu_fault_buffer_ctrl.c",0x35,
                 "faultbufCtrlCmdMmuFaultBufferRegisterNonReplayBuf_IMPL",4,
                 "NVRM: Client shadow fault buffer for non-replayable faults already allocated\n");
    nvAssertFailedNoLog(&DAT_00d68b65,"src/kernel/gpu/mmu/mmu_fault_buffer_ctrl.c",0x37);
  }
  return iVar4;
}


// ===== 0040aeb0 faultbufCtrlCmdMmuFaultBufferUnregisterNonReplayBuf_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int faultbufCtrlCmdMmuFaultBufferUnregisterNonReplayBuf_IMPL(long param_1,long *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1b98);
  if (*(long *)(lVar2 + 0x638) == 0) {
    nvDbg_Printf("src/kernel/gpu/mmu/mmu_fault_buffer_ctrl.c",0x67,
                 "faultbufCtrlCmdMmuFaultBufferUnregisterNonReplayBuf_IMPL",4,
                 "NVRM: Client shadow fault buffer for non-replayable faults does not exist\n");
  }
  else {
    if ((*param_2 == *(long *)(*(long *)(lVar2 + 0x638) + 0x10)) ||
       ((cVar3 = gpuIsCCFeatureEnabled_IMPL(lVar1), cVar3 != '\0' &&
        (*(char *)(lVar1 + 0x4a78) != '\0')))) {
      cVar3 = gpuIsCCFeatureEnabled_IMPL(lVar1);
      if ((cVar3 != '\0') &&
         ((*(char *)(lVar1 + 0x4a78) != '\0' &&
          (*param_2 != *(long *)(*(long *)(lVar2 + 0x638) + 0x38))))) {
        nvDbg_Printf("src/kernel/gpu/mmu/mmu_fault_buffer_ctrl.c",0x79,
                     "faultbufCtrlCmdMmuFaultBufferUnregisterNonReplayBuf_IMPL",4,
                     "NVRM: Given client shadow fault buffer for non-replayable faults does not match with the actual\n"
                    );
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/mmu/mmu_fault_buffer_ctrl.c",0x71,
                   "faultbufCtrlCmdMmuFaultBufferUnregisterNonReplayBuf_IMPL",4,
                   "NVRM: Given client shadow fault buffer for non-replayable faults does not match with the actual\n"
                  );
    }
    iVar4 = (**(code **)(lVar2 + 0x318))(lVar1,lVar2,0);
    if (iVar4 != 0) {
      nvDbg_Printf("src/kernel/gpu/mmu/mmu_fault_buffer_ctrl.c",0x80,
                   "faultbufCtrlCmdMmuFaultBufferUnregisterNonReplayBuf_IMPL",4,
                   "NVRM: Error freeing client shadow fault buffer for non-replayable faults\n");
      return iVar4;
    }
  }
  return 0;
}


// ===== 0040b020 faultbufCtrlCmdMmuFaultBufferRegisterReplayBuf_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int faultbufCtrlCmdMmuFaultBufferRegisterReplayBuf_IMPL(long param_1,undefined8 *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1b98);
  puVar5 = (undefined4 *)kgmmuGetStaticInfo_IMPL(lVar1,lVar2);
  cVar3 = gpuIsCCFeatureEnabled_IMPL(lVar1);
  if (cVar3 == '\0') {
    nvAssertFailedNoLog("gpuIsCCFeatureEnabled(pGpu)","src/kernel/gpu/mmu/mmu_fault_buffer_ctrl.c",
                        0x94);
  }
  else {
    if (*(long *)(lVar2 + 0x640) == 0) {
      iVar4 = (**(code **)(lVar2 + 0x310))(lVar1,lVar2,1);
      if (iVar4 == 0) {
        lVar1 = *(long *)(lVar2 + 0x640);
        *param_2 = *(undefined8 *)(lVar1 + 0x38);
        param_2[1] = *(undefined8 *)(lVar1 + 0x70);
        *(undefined4 *)(param_2 + 2) = *puVar5;
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/mmu/mmu_fault_buffer_ctrl.c",0xa6,
                   "faultbufCtrlCmdMmuFaultBufferRegisterReplayBuf_IMPL",4,
                   "NVRM: Error allocating client shadow fault buffer for replayable faults\n");
      return iVar4;
    }
    nvDbg_Printf("src/kernel/gpu/mmu/mmu_fault_buffer_ctrl.c",0x9c,
                 "faultbufCtrlCmdMmuFaultBufferRegisterReplayBuf_IMPL",4,
                 "NVRM: Client shadow fault buffer for replayable faults already allocated\n");
    nvAssertFailedNoLog(&DAT_00d68b65,"src/kernel/gpu/mmu/mmu_fault_buffer_ctrl.c",0x9e);
  }
  return 0x56;
}


// ===== 0040b170 faultbufCtrlCmdMmuFaultBufferUnregisterReplayBuf_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int faultbufCtrlCmdMmuFaultBufferUnregisterReplayBuf_IMPL(long param_1,long *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1b98);
  cVar3 = gpuIsCCFeatureEnabled_IMPL(lVar1);
  if (cVar3 == '\0') {
    nvAssertFailedNoLog("gpuIsCCFeatureEnabled(pGpu)","src/kernel/gpu/mmu/mmu_fault_buffer_ctrl.c",
                        0xc0);
    return 0x56;
  }
  if (*(long *)(lVar2 + 0x640) == 0) {
    nvDbg_Printf("src/kernel/gpu/mmu/mmu_fault_buffer_ctrl.c",0xc5,
                 "faultbufCtrlCmdMmuFaultBufferUnregisterReplayBuf_IMPL",4,
                 "NVRM: Client shadow fault buffer for replayable faults does not exist\n");
  }
  else {
    if (*param_2 != *(long *)(*(long *)(lVar2 + 0x640) + 0x38)) {
      nvDbg_Printf("src/kernel/gpu/mmu/mmu_fault_buffer_ctrl.c",0xcd,
                   "faultbufCtrlCmdMmuFaultBufferUnregisterReplayBuf_IMPL",4,
                   "NVRM: Given client shadow fault buffer for replayable faults does not match with the actual\n"
                  );
    }
    iVar4 = (**(code **)(lVar2 + 0x318))(lVar1,lVar2,1);
    if (iVar4 != 0) {
      nvDbg_Printf("src/kernel/gpu/mmu/mmu_fault_buffer_ctrl.c",0xd4,
                   "faultbufCtrlCmdMmuFaultBufferUnregisterReplayBuf_IMPL",4,
                   "NVRM: Error freeing client shadow fault buffer for replayable faults\n");
      return iVar4;
    }
  }
  return 0;
}


// ===== 0040b2b0 _mmuTraceTranslateCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
_mmuTraceTranslateCallback
          (undefined8 param_1,long param_2,byte *param_3,undefined8 param_4,undefined8 param_5,
          long *param_6,ulong param_7,char param_8,undefined8 param_9)

{
  undefined4 uVar1;
  long lVar2;
  
  if (param_8 != '\0') {
    lVar2 = (**(code **)(param_2 + 0x20))(param_1,param_4,param_5);
    *param_6 = lVar2;
    *param_6 = (~(-1L << (*param_3 & 0x3f)) & param_7) + lVar2;
    uVar1 = (**(code **)(param_2 + 0x58))(param_4,param_5);
    *(undefined1 *)((long)param_6 + 0xc) = 1;
    *(undefined4 *)(param_6 + 1) = uVar1;
  }
  *(bool *)param_9 = param_8 != '\0';
  return 0;
}


// ===== 0040b360 _mmuTracePteCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
_mmuTracePteCallback
          (undefined8 param_1,long param_2,ulong param_3,byte *param_4,undefined8 param_5,
          undefined8 param_6,long *param_7,char param_8,undefined1 *param_9)

{
  undefined4 uVar1;
  long lVar2;
  
  *param_9 = 0;
  if (param_8 != '\0') {
    lVar2 = (**(code **)(param_2 + 0x20))(param_1,param_5,param_6);
    *param_7 = lVar2;
    *param_7 = (~(-1L << (*param_4 & 0x3f)) & param_3) + lVar2;
    uVar1 = (**(code **)(param_2 + 0x58))(param_5,param_6);
    *(undefined4 *)(param_7 + 1) = uVar1;
  }
  return 0;
}


// ===== 0040b3f0 _mmuPrintPte.part.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _mmuPrintPte_part_0(undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4,
                        int param_5,undefined4 param_6,byte *param_7,undefined8 param_8,
                        undefined8 param_9,char param_10,undefined8 *param_11)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *param_7;
  param_5 = (uint)(bVar1 != 0x26 && (bVar1 & 0xf7) != 0x15) + param_5;
  if (*(char *)(param_11 + 3) == '\0') goto LAB_0040b45c;
  nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x10d,"_mmuPrintPte",1,
               "NVRM: MMUTRACE: VA[0x%08llx-%08llx]",*param_11,param_11[1]);
  if (param_5 != -1) {
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x10f,"_mmuPrintPte",1,&DAT_00d68f5f);
    } while (param_5 + 1 != iVar2);
  }
  if (bVar1 == 0x15) {
    nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x11a,"_mmuPrintPte",1,"PTE_2M");
  }
  else if ((ulong)(1L << (bVar1 & 0x3f)) < 0x200001) {
    if (bVar1 == 0x10) {
      nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x120,"_mmuPrintPte",1,"PTE_64K");
    }
    else if (bVar1 == 0x11) {
      nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x11d,"_mmuPrintPte",1,"PTE_128K");
    }
    else {
      if (bVar1 != 0xc) goto LAB_0040b708;
      nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x123,"_mmuPrintPte",1,"PTE_4K");
    }
  }
  else if (bVar1 == 0x1d) {
    nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x117,"_mmuPrintPte",1,"PTE_512M");
  }
  else if (bVar1 == 0x26) {
    nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x114,"_mmuPrintPte",1,"PTE_256G");
  }
  else {
LAB_0040b708:
    nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x126,"_mmuPrintPte",1,&DAT_00d68f93);
    nvAssertFailedNoLog(&DAT_00d68f97,"src/kernel/gpu/mmu/mmu_trace.c",0x127);
  }
  nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",299,"_mmuPrintPte",1,"[0x%x",
               *(undefined4 *)(param_11 + 2));
  if (*(int *)(param_11 + 2) != *(int *)((long)param_11 + 0x14)) {
    nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x12e,"_mmuPrintPte",1,&DAT_00d68f9f);
  }
  nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x130,"_mmuPrintPte",1,"]: invalid\n");
LAB_0040b45c:
  if (param_10 != '\0') {
    nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x135,"_mmuPrintPte",1,
                 "NVRM: MMUTRACE: VA[0x%08llx-%08llx]",param_3,param_4);
    if (param_5 != -1) {
      iVar2 = 0;
      do {
        iVar2 = iVar2 + 1;
        nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x136,"_mmuPrintPte",1,&DAT_00d68f5f);
      } while (param_5 + 1 != iVar2);
    }
    (**(code **)(param_2 + 0x40))(param_1,param_7,param_8,param_9,param_6);
    return;
  }
  return;
}


// ===== 0040b810 _mmuTraceDumpMappingCallback =====

undefined8 _mmuTraceDumpMappingCallback(void)

{
  int *piVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  long in_R9;
  int iStack0000000000000008;
  int in_stack_00000010;
  char in_stack_00000018;
  undefined1 *in_stack_00000020;
  
  *in_stack_00000020 = 0;
  if (in_stack_00000018 == '\0') {
    return 0;
  }
  lVar3 = *(long *)(in_R9 + 0x10);
  uVar2 = *(uint *)(lVar3 + 0x10);
  if (uVar2 != 0) {
    lVar4 = (ulong)(uVar2 - 1) * 0x10 + lVar3;
    if (_iStack0000000000000008 == (ulong)*(uint *)(lVar4 + 0x20) + *(long *)(lVar4 + 0x18)) {
      *(uint *)(lVar4 + 0x20) =
           ((in_stack_00000010 + 1) - iStack0000000000000008) + *(uint *)(lVar4 + 0x20);
      return 0;
    }
    if (0x3f < uVar2) {
      *in_stack_00000020 = 1;
      *(undefined4 *)(*(long *)(in_R9 + 0x10) + 0x14) = 1;
      return 0;
    }
  }
  *(long *)((ulong)uVar2 * 0x10 + 0x18 + lVar3) = _iStack0000000000000008;
  *(int *)((ulong)*(uint *)(*(long *)(in_R9 + 0x10) + 0x10) * 0x10 + 0x20 + *(long *)(in_R9 + 0x10))
       = (in_stack_00000010 + 1) - iStack0000000000000008;
  piVar1 = (int *)(*(long *)(in_R9 + 0x10) + 0x10);
  *piVar1 = *piVar1 + 1;
  return 0;
}


// ===== 0040b8c0 _mmuPrintPdeInvalid.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _mmuPrintPdeInvalid_isra_0
               (undefined8 param_1,long param_2,int param_3,undefined8 *param_4,char param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = (**(code **)(param_2 + 0x60))(param_1,param_3);
  if (param_5 == '\0') {
    return;
  }
  nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x167,"_mmuPrintPdeInvalid",1,
               "NVRM: MMUTRACE: VA[0x%08llx-%08llx]",*param_4,param_4[1]);
  if (param_3 != -1) {
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x169,"_mmuPrintPdeInvalid",1,&DAT_00d68f5f);
    } while (param_3 + 1 != iVar2);
  }
  nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x16a,"_mmuPrintPdeInvalid",1,"PDE%u[0x%x",uVar1,
               *(undefined4 *)(param_4 + 2));
  if (*(int *)(param_4 + 2) != *(int *)((long)param_4 + 0x14)) {
    nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x16d,"_mmuPrintPdeInvalid",1,"-%03x");
  }
  nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x16f,"_mmuPrintPdeInvalid",1,"]: invalid\n");
  return;
}


// ===== 0040ba20 _mmuTraceWalk.constprop.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _mmuTraceWalk_constprop_0
              (long param_1,undefined8 *param_2,undefined8 param_3,byte *param_4,long param_5,
              byte *param_6,byte *param_7,long *param_8,char *param_9,byte param_10)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  char cVar10;
  char cVar11;
  int iVar12;
  uint uVar13;
  undefined4 uVar14;
  long lVar15;
  long lVar16;
  byte *pbVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  code *pcVar20;
  uint uVar21;
  byte *pbVar22;
  byte *pbVar23;
  byte *pbVar24;
  int iVar25;
  ulong uVar26;
  int iVar27;
  int iVar28;
  byte *pbVar29;
  char *pcVar30;
  long local_350;
  uint local_334;
  byte *local_320;
  byte *local_318;
  ulong local_310;
  byte *local_308;
  byte *local_300;
  uint local_2f8;
  uint local_2f4;
  byte *local_2f0;
  byte *local_2d8;
  ulong local_2d0;
  byte local_295;
  undefined4 local_294;
  long local_290;
  byte local_288 [16];
  byte *local_278;
  byte *local_270;
  undefined8 local_268;
  ulong local_260;
  byte *local_258;
  long local_250;
  byte *local_248;
  byte *local_240;
  uint local_238;
  ulong local_230;
  int local_228;
  byte *local_220;
  byte *local_218;
  undefined8 local_210;
  ulong local_208;
  byte *local_200;
  char local_1f8;
  uint local_1f4;
  byte local_1f0;
  char local_1ef;
  long local_1e8;
  
  uVar5 = *param_2;
  bVar1 = *param_4;
  puVar6 = (undefined8 *)param_2[2];
  bVar2 = param_4[2];
  bVar3 = param_4[1];
  local_278 = (byte *)0x0;
  uVar7 = *(undefined8 *)(param_1 + 0x1b78);
  local_270 = (byte *)0x0;
  local_268 = 0;
  local_260 = 0;
  local_290 = 0;
  local_295 = 0;
  memset(&local_258,0,0x220);
  iVar12 = 0;
  if (param_5 != 0) {
    lVar15 = memmgrMemDescBeginTransfer_IMPL(uVar7,param_5,6);
    if (lVar15 == 0) {
      iVar12 = 0x1a;
    }
    else {
      lVar16 = 1L << (bVar1 & 0x3f);
      local_320 = (byte *)(lVar16 - 1U | (ulong)param_6);
      local_300 = local_320;
      if (param_7 < local_320) {
        local_300 = param_7;
      }
      if (param_6 <= param_7) {
        local_308 = (byte *)0x0;
        local_2f4 = 0;
        local_2f8 = 0;
        iVar28 = 0;
        local_2d0 = 0;
        cVar10 = '\0';
        local_2f0 = (byte *)0x0;
        uVar13 = (uint)((-lVar16 & (ulong)param_6 & ~(-1L << (bVar3 + 1 & 0x3f))) >> (bVar1 & 0x3f))
        ;
        uVar21 = bVar2 * uVar13;
        local_318 = param_6;
        goto LAB_0040bf09;
      }
      iVar28 = 0;
LAB_0040bb3b:
      iVar12 = 0;
      iVar27 = iVar28;
LAB_0040bb3e:
      if (lVar15 == 0) goto LAB_0040bb65;
LAB_0040bb43:
      memmgrMemDescEndTransfer_IMPL(uVar7,param_5,1);
LAB_0040bb65:
      if (iVar27 != 0) {
        iVar28 = iVar27 + -1;
        local_290 = param_5;
        mmuWalkGetTraceInfo(param_3,iVar28,&local_258);
        lVar15 = local_1e8;
        uVar21 = local_1f4;
        cVar10 = local_1f8;
        param_6 = local_200;
        local_310 = local_230;
        uVar13 = local_238;
        param_5 = local_250;
        param_4 = local_258;
        local_318 = local_248;
        local_268 = local_210;
        param_7 = local_240;
        local_278 = local_220;
        local_260 = local_208;
        local_270 = local_218;
        local_308 = local_218;
        local_2f0 = local_220;
        local_2f4 = (uint)local_210;
        local_2f8 = local_210._4_4_;
        local_2d0 = local_208 & 0xff;
        local_295 = local_1f0;
        if (iVar12 != 0) {
          iVar12 = local_228;
        }
        if (local_1ef != '\0') {
          memdescDestroy(local_290);
        }
        iVar27 = iVar28;
        if (*param_9 != '\0') goto LAB_0040bb3e;
        local_310 = local_310 & 0xffffffff;
LAB_0040bc9c:
        uVar26 = (ulong)(uVar21 + 1);
        if (uVar21 + 1 < (uint)param_4[4]) goto LAB_0040c0fe;
        iVar27 = iVar28;
        if (iVar12 != 0) goto LAB_0040bb3e;
LAB_0040bcb7:
        if (local_295 != 0) {
          param_6 = local_320 + 1;
          if (param_6 <= param_7) {
            bVar1 = *param_4;
            uVar13 = uVar13 + 1;
            if (uVar13 < (uint)(1 << ((param_4[1] - bVar1) + 1 & 0x1f))) {
              uVar21 = (int)local_310 + (uint)param_4[2];
              local_2d0 = 0;
LAB_0040bd2e:
              local_310 = (ulong)uVar21;
              local_2d8 = local_288;
              local_295 = 0;
              local_320 = (byte *)((1L << (bVar1 & 0x3f)) - 1U | (ulong)param_6);
              local_300 = local_320;
              if (param_7 < local_320) {
                local_300 = param_7;
              }
              if (*(ulong *)(param_5 + 0x30) < (ulong)(param_4[2] + uVar21)) {
                nvAssertFailedNoLog("(offset + pFmtLevel->entrySize) <= pMemDesc->Size",
                                    "src/kernel/gpu/mmu/mmu_trace.c",0x1e4);
              }
              if (lVar15 == 0) {
                nvAssertFailedNoLog("pBase != NULL","src/kernel/gpu/mmu/mmu_trace.c",0x1e6);
              }
              portMemCopy(local_2d8,param_4[2],local_310 + lVar15,param_4[2]);
              cVar11 = (*(code *)*puVar6)(uVar5,param_4,local_2d8,&local_295);
              if (cVar11 == '\0') {
                uVar26 = 0;
                iVar12 = 0x44;
LAB_0040c0fe:
                local_2d8 = local_288;
                local_350 = uVar26 * 0x18;
                uVar21 = (uint)uVar26;
                do {
                  local_334 = uVar21 + 1;
                  local_294 = 0;
                  uVar18 = (*(code *)puVar6[1])(uVar5,param_4,uVar21);
                  lVar16 = (*(code *)puVar6[3])(param_1,uVar18,local_2d8);
                  iVar27 = iVar28;
                  if (lVar16 == 0xf) {
                    cVar11 = (*(code *)puVar6[9])(param_1,uVar5,uVar18,local_2d8);
                    if (cVar11 == '\0') {
                      iVar12 = 0x44;
                      goto LAB_0040bb3e;
                    }
                    if (param_8[2] == 0) goto LAB_0040bc9c;
                  }
                  else {
                    iVar12 = mmuWalkGetPageLevelInfo
                                       (param_3,local_350 + *(long *)(param_4 + 0x10),param_6,
                                        &local_290,&local_294);
                    if (iVar12 != 0) {
                      nvAssertOkFailedNoLog
                                (iVar12,
                                 "mmuWalkGetPageLevelInfo(pWalk, &pFmtLevel->subLevels[subLevelIdx], entryVa, (const MMU_WALK_MEMDESC**)&pTempMemDesc, &memSize)"
                                 ,"src/kernel/gpu/mmu/mmu_trace.c",0x23e);
                      goto LAB_0040bb3e;
                    }
                    if (local_295 == 0) {
                      uVar19 = *param_2;
                      lVar16 = param_2[2];
                      uVar14 = (**(code **)(lVar16 + 0x60))(uVar19,iVar28);
                      if (param_10 != 0) {
                        if ((char)local_2d0 != '\0') {
                          local_278 = local_2f0;
                          local_270 = local_308;
                          local_268 = CONCAT44(local_2f8,local_2f4);
                          local_260 = CONCAT71(local_260._1_7_,(char)local_2d0);
                          _mmuPrintPdeInvalid_isra_0(*param_2,param_2[2],iVar28,&local_278,1);
                        }
                        nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x192,"_mmuPrintPdeValid",1,
                                     "NVRM: MMUTRACE: VA[0x%08llx-%08llx]",param_6,local_300);
                        if (iVar28 != -1) {
                          iVar25 = 0;
                          do {
                            iVar25 = iVar25 + 1;
                            nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x193,"_mmuPrintPdeValid",
                                         1,&DAT_00d68f5f);
                          } while (iVar28 + 1 != iVar25);
                        }
                        nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x194,"_mmuPrintPdeValid",1,
                                     "PDE%u[0x%x]: ",uVar14,uVar13);
                        (**(code **)(lVar16 + 0x30))(param_1,uVar19,param_4,local_2d8);
                        if (1 < param_4[4]) {
                          uVar26 = 0;
                          do {
                            lVar8 = *(long *)(param_4 + 0x10);
                            lVar9 = param_2[2];
                            lVar16 = uVar26 * 0x18;
                            uVar19 = (**(code **)(lVar9 + 8))(*param_2,param_4,uVar26 & 0xffffffff);
                            nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x14e,"_mmuPrintPt",1,
                                         "NVRM: MMUTRACE: VA[0x%08llx-%08llx]",param_6,local_300);
                            if (iVar28 != -2) {
                              iVar25 = 0;
                              do {
                                iVar25 = iVar25 + 1;
                                nvDbg_Printf("src/kernel/gpu/mmu/mmu_trace.c",0x14f,"_mmuPrintPt",1,
                                             &DAT_00d68f5f);
                              } while (iVar25 != iVar28 + 2);
                            }
                            uVar26 = uVar26 + 1;
                            (**(code **)(lVar9 + 0x38))(param_1,lVar8 + lVar16,uVar19,local_2d8);
                          } while ((uint)uVar26 < (uint)param_4[4]);
                        }
                      }
                    }
                    local_295 = 1;
                    if ((code *)param_8[3] == (code *)0x0) goto LAB_0040c3b5;
                    iVar25 = (*(code *)param_8[3])
                                       (param_1,puVar6,param_6,local_300,iVar28,uVar13,param_4,
                                        uVar18,local_2d8,1,param_9,param_8[5]);
                    if (iVar25 == 0) goto code_r0x0040c392;
                    if (*param_9 != '\0') goto LAB_0040bb3e;
                  }
                  if (param_4[4] <= local_334) goto LAB_0040bcb7;
                  iVar12 = 0;
                  local_350 = local_350 + 0x18;
                  uVar21 = local_334;
                } while( true );
              }
              pbVar29 = (byte *)param_8[4];
              pbVar17 = (byte *)(*(code *)puVar6[2])(uVar5);
              pcVar20 = (code *)param_8[1];
              pbVar22 = pbVar17;
              pbVar23 = param_4;
              pcVar30 = param_9;
              if (((pcVar20 == (code *)0x0) ||
                  (pbVar29 < (byte *)(-1L << (param_4[1] + 1 & 0x3f) & (ulong)param_6))) ||
                 (local_300 < pbVar29)) {
                pcVar20 = (code *)param_8[2];
                if (pcVar20 != (code *)0x0) {
                  pbVar17 = local_2d8;
                  local_2d8 = (byte *)param_8[5];
                  pbVar29 = param_6;
                  pbVar24 = local_300;
                  pcVar30 = (char *)(ulong)local_295;
                  goto LAB_0040c24f;
                }
                pcVar20 = (code *)*param_8;
                if (pcVar20 != (code *)0x0) {
                  pbVar24 = (byte *)(ulong)local_295;
                  if ((local_295 != 0) && ((param_10 & 1) != 0)) {
                    local_278 = local_2f0;
                    local_270 = local_308;
                    local_268 = CONCAT44(local_2f8,local_2f4);
                    local_260 = CONCAT71(local_260._1_7_,(char)local_2d0);
                    _mmuPrintPte_part_0(param_1,puVar6,param_6,local_300,iVar28,uVar13,param_4,
                                        pbVar17,local_2d8,1,&local_278);
                    pbVar24 = (byte *)(ulong)local_295;
                    pcVar20 = (code *)*param_8;
                  }
                  pbVar29 = (byte *)param_8[5];
                  pbVar22 = param_4;
                  pbVar23 = local_318;
                  goto LAB_0040c24f;
                }
              }
              else {
                pbVar17 = local_2d8;
                local_2d8 = (byte *)param_8[5];
                pbVar24 = (byte *)(ulong)local_295;
LAB_0040c24f:
                iVar12 = (*pcVar20)(param_1,puVar6,pbVar23,pbVar22,pbVar17,local_2d8,pbVar29,pbVar24
                                    ,pcVar30);
                iVar27 = iVar28;
                if (iVar12 != 0) goto LAB_0040bb3e;
              }
              if (*param_9 != '\0') goto LAB_0040bb3b;
              cVar10 = '\x01';
              goto LAB_0040bcb7;
            }
          }
          goto LAB_0040bb3b;
        }
        if ((char)local_2d0 == '\0') {
          local_2f4 = uVar13;
          local_2f0 = param_6;
        }
        param_6 = local_320 + 1;
        local_2f8 = uVar13;
        if (param_7 < param_6) {
          local_308 = local_300;
        }
        else {
          uVar21 = (int)local_310 + (uint)param_4[2];
          local_308 = local_300;
          local_2d0 = 1;
          uVar13 = uVar13 + 1;
LAB_0040bf09:
          bVar1 = *param_4;
          if (uVar13 < (uint)(1 << ((param_4[1] - bVar1) + 1 & 0x1f))) goto LAB_0040bd2e;
          if ((char)local_2d0 == '\0') goto LAB_0040bb3b;
        }
        iVar27 = iVar28;
        if (cVar10 == '\0') {
          iVar12 = 0;
          if (param_8[3] != 0) {
            local_260 = CONCAT71(local_260._1_7_,1);
            local_278 = local_2f0;
            local_270 = local_308;
            local_268 = CONCAT44(local_2f8,local_2f4);
            _mmuPrintPdeInvalid_isra_0(*param_2,param_2[2],iVar28,&local_278,param_10);
            iVar12 = (*(code *)param_8[3])
                               (param_1,puVar6,0,0,iVar28,0,param_4,0,0,0,param_9,param_8[5]);
          }
        }
        else {
          iVar12 = 0;
          pcVar20 = (code *)*param_8;
          if (pcVar20 != (code *)0x0) {
            if (param_10 != 0) {
              local_278 = local_2f0;
              local_260 = CONCAT71(local_260._1_7_,1);
              local_270 = local_308;
              local_268 = CONCAT44(local_2f8,local_2f4);
              _mmuPrintPte_part_0(param_1,puVar6,0,0,iVar28,0,param_4,0,0,0,&local_278);
              pcVar20 = (code *)*param_8;
            }
            iVar12 = (*pcVar20)(param_1,puVar6,0,0,0,0,0,0,param_9);
          }
        }
        goto LAB_0040bb3e;
      }
    }
  }
  return iVar12;
code_r0x0040c392:
  if (*param_9 != '\0') goto LAB_0040bb3b;
LAB_0040c3b5:
  portMemSet(&local_258,0,0x220);
  local_248 = local_318;
  local_240 = param_7;
  local_268 = CONCAT44(local_2f8,local_2f4);
  local_230 = local_310;
  local_260 = CONCAT71(local_260._1_7_,(char)local_2d0);
  local_270 = local_308;
  local_278 = local_2f0;
  local_220 = local_2f0;
  local_218 = local_308;
  local_210 = local_268;
  iVar27 = iVar28 + 1;
  local_208 = local_260;
  local_228 = 0;
  local_1f0 = local_295;
  local_1ef = '\0';
  local_258 = param_4;
  local_250 = param_5;
  local_238 = uVar13;
  local_200 = param_6;
  local_1f8 = cVar10;
  local_1f4 = uVar21;
  local_1e8 = lVar15;
  mmuWalkSetTraceInfo(param_3,iVar28,&local_258);
  param_5 = local_290;
  if (local_290 == 0) goto LAB_0040bb3e;
  param_4 = (byte *)(local_350 + *(long *)(param_4 + 0x10));
  bVar2 = param_4[1];
  bVar3 = *param_4;
  bVar4 = param_4[2];
  lVar15 = memmgrMemDescBeginTransfer_IMPL(uVar7,local_290,6);
  if (lVar15 == 0) {
    iVar12 = 0x1a;
    goto LAB_0040bb65;
  }
  if (local_300 < param_6) goto LAB_0040bb43;
  bVar1 = *param_4;
  uVar13 = (uint)((~(-1L << (bVar2 + 1 & 0x3f)) & -1L << (bVar3 & 0x3f) & (ulong)param_6) >>
                 (bVar3 & 0x3f));
  if ((uint)(1 << ((param_4[1] - bVar1) + 1 & 0x1f)) <= uVar13) goto LAB_0040bb3e;
  local_2f4 = 0;
  uVar21 = bVar4 * uVar13;
  param_7 = local_300;
  local_2f8 = 0;
  local_308 = (byte *)0x0;
  local_2f0 = (byte *)0x0;
  local_2d0 = 0;
  cVar10 = '\0';
  iVar28 = iVar27;
  local_318 = param_6;
  goto LAB_0040bd2e;
}


// ===== 0040cc40 mmuTrace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

ulong mmuTrace(long param_1,long *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  ulong uVar9;
  undefined1 local_81;
  long local_80;
  undefined8 local_78;
  undefined1 *local_70;
  code *local_68;
  code *local_60;
  code *local_58;
  undefined8 local_50;
  undefined8 local_48;
  long local_40;
  
  local_68 = (code *)0x0;
  local_60 = (code *)0x0;
  local_58 = (code *)0x0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  if (param_1 == 0) {
    nvAssertFailedNoLog("pGpu != NULL","src/kernel/gpu/mmu/mmu_trace.c",0x9e);
  }
  else if (param_2 == (long *)0x0) {
    nvAssertFailedNoLog("pVAS != NULL","src/kernel/gpu/mmu/mmu_trace.c",0x9f);
  }
  else if (param_3 == (int *)0x0) {
    nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/mmu/mmu_trace.c",0xa1);
  }
  else if (*(long *)(param_3 + 6) == 0) {
    nvAssertFailedNoLog("pParams->pArg != NULL","src/kernel/gpu/mmu/mmu_trace.c",0xa2);
  }
  else {
    lVar6 = (**(code **)(*param_2 + 200))(param_2,param_1);
    if (lVar6 != 0) {
      iVar1 = *param_3;
      **(undefined8 **)(param_3 + 6) = 0xf;
      *(undefined4 *)(*(long *)(param_3 + 6) + 8) = 0;
      local_40 = *(long *)(param_3 + 6);
      iVar2 = *param_3;
      if (iVar2 == 2) {
        local_48 = *(undefined8 *)(param_3 + 2);
        local_60 = _mmuTraceTranslateCallback;
        *(undefined1 *)(local_40 + 0xc) = 0;
      }
      else if (iVar2 == 3) {
        local_58 = _mmuTraceDumpMappingCallback;
        *(undefined4 *)(*(long *)(local_40 + 0x10) + 0x10) = 0;
        *(undefined4 *)(*(long *)(local_40 + 0x10) + 0x14) = 0;
      }
      else {
        if (iVar2 != 1) {
          nvAssertFailedNoLog("modeValid","src/kernel/gpu/mmu/mmu_trace.c",199);
          return 0x1f;
        }
        local_68 = _mmuTracePteCallback;
      }
      uVar3 = *(undefined8 *)(param_3 + 4);
      uVar4 = *(undefined8 *)(param_3 + 2);
      lVar6 = (**(code **)(*param_2 + 200))(param_2,param_1);
      uVar7 = __nvoc_dynamicCast(param_2,__nvoc_class_def_OBJGVASPACE);
      lVar8 = gvaspaceGetGpuState_IMPL(uVar7,param_1);
      local_81 = 0;
      uVar7 = *(undefined8 *)(lVar8 + 8);
      if (lVar6 == 0) {
        nvAssertFailedNoLog(&DAT_00d690ea,"src/kernel/gpu/mmu/mmu_trace.c",0x78);
      }
      lVar8 = __nvoc_dynamicCast(param_2,__nvoc_class_def_OBJGVASPACE);
      if (lVar8 == 0) {
        nvAssertFailedNoLog("pGVAS","src/kernel/gpu/mmu/mmu_trace.c",0xe0);
      }
      local_80 = gvaspaceGetGmmuFmt_IMPL(lVar8,param_1);
      if (local_80 == 0) {
        nvAssertFailedNoLog("pGmmuFmt","src/kernel/gpu/mmu/mmu_trace.c",0xe3);
      }
      uVar5 = *(undefined8 *)(local_80 + 8);
      local_70 = g_gmmuTraceCallbacks;
      local_78 = uVar5;
      if (iVar1 == 1) {
        (*(code *)g_gmmuTraceCallbacks._40_8_)
                  (param_1,param_2,uVar4,uVar3,g_gmmuTraceCallbacks._40_8_);
      }
      uVar9 = _mmuTraceWalk_constprop_0
                        (param_1,&local_80,uVar7,uVar5,lVar6,uVar4,uVar3,&local_68,&local_81,
                         iVar1 == 1);
      if ((iVar2 == 2) &&
         (uVar9 = uVar9 & 0xffffffff, *(char *)(*(long *)(param_3 + 6) + 0xc) == '\0')) {
        uVar9 = 0x44;
      }
      return uVar9;
    }
    nvAssertFailedNoLog("pPDB != NULL","src/kernel/gpu/mmu/mmu_trace.c",0xa5);
  }
  return 0x1f;
}


// ===== 0040d050 uvmswConstruct_IMPL =====

undefined8 uvmswConstruct_IMPL(long param_1)

{
  *(undefined1 *)(param_1 + 0x1f2) = 0;
  *(undefined2 *)(param_1 + 0x1f0) = 0;
  *(undefined8 *)(param_1 + 0x1e8) = 0;
  return 0;
}


// ===== 0040d080 uvmswDestruct_IMPL =====

void uvmswDestruct_IMPL(void)

{
  return;
}


// ===== 0040d085 nvdecctxConstructHal_KERNEL.cold =====

void nvdecctxConstructHal_KERNEL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0040d090 nvdecctxConstructHal_KERNEL =====

undefined8 nvdecctxConstructHal_KERNEL(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  undefined8 uVar5;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar1 = *(long *)(param_1 + 0x1d8);
  uVar5 = *(undefined8 *)(*(long *)(lVar1 + 0x158) + 0xe0);
  lVar4 = kflcnGetKernelFalconForEngine_IMPL(uVar5,*(undefined4 *)(lVar1 + 0x184));
  if (lVar4 != 0) {
    uVar2 = *(undefined8 *)(lVar1 + 0x178);
    nvDbg_Printf("src/kernel/gpu/nvdec/kernel_nvdec_ctx.c",0x32,"nvdecctxConstructHal_KERNEL",1,
                 "NVRM: nvdecctxConstruct for 0x%x\n",*(undefined4 *)(lVar1 + 0x184));
    uVar5 = kflcnAllocContext_IMPL
                      (uVar5,lVar4,uVar2,
                       *(undefined4 *)(*(long *)(*(long *)(lVar1 + 0x140) + 0x48) + 0x11c));
    return uVar5;
  }
  return 0x40;
}


// ===== 0040d13e nvdecctxDestructHal_KERNEL.cold =====

void nvdecctxDestructHal_KERNEL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0040d150 nvdecctxDestructHal_KERNEL =====

void nvdecctxDestructHal_KERNEL(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  lVar1 = *(long *)(param_1 + 0x1d8);
  uVar2 = *(undefined8 *)(*(long *)(lVar1 + 0x158) + 0xe0);
  uVar6 = kflcnGetKernelFalconForEngine_IMPL(uVar2,*(undefined4 *)(lVar1 + 0x184));
  uVar3 = *(undefined8 *)(lVar1 + 0x178);
  nvDbg_Printf("src/kernel/gpu/nvdec/kernel_nvdec_ctx.c",0x41,"nvdecctxDestructHal_KERNEL",1,
               "NVRM: nvdecctxDestruct for 0x%x\n",*(undefined4 *)(lVar1 + 0x184));
  iVar5 = kflcnFreeContext_IMPL
                    (uVar2,uVar6,uVar3,
                     *(undefined4 *)(*(long *)(*(long *)(lVar1 + 0x140) + 0x48) + 0x11c));
  if (iVar5 == 0) {
    return;
  }
  nvAssertOkFailedNoLog
            (iVar5,
             "kflcnFreeContext(pGpu, pKernelFalcon, pKernelChannel, RES_GET_EXT_CLASS_ID(pChannelDescendant))"
             ,"src/kernel/gpu/nvdec/kernel_nvdec_ctx.c",0x43);
  return;
}


// ===== 0040d220 deviceCtrlCmdBspGetCapsV2_VF =====

undefined8 deviceCtrlCmdBspGetCapsV2_VF(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = gpuGetStaticInfo(*(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0));
  if (lVar1 != 0) {
    if (*(uint *)(param_2 + 8) < 8) {
      lVar2 = (ulong)(*(uint *)(param_2 + 8) + 0x3e32) << 3;
    }
    else {
      nvDbg_Printf("src/kernel/gpu/nvdec/kernel_nvdec_ctx.c",0x53,"deviceCtrlCmdBspGetCapsV2_VF",4,
                   "NVRM: Requested NVDEC Id 0x%x is not present. Hence, returning capabilities of NVDEC0\n"
                  );
      *(undefined4 *)(param_2 + 8) = 0;
      lVar2 = 0x1f190;
    }
    portMemCopy(param_2,8,lVar1 + lVar2,8);
    return 0;
  }
  nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/nvdec/kernel_nvdec_ctx.c",0x4e);
  return 0x40;
}


// ===== 0040d2f0 nvdecGetEngineDescFromAllocParams =====

uint nvdecGetEngineDescFromAllocParams(long param_1,uint param_2,int *param_3)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  undefined8 uVar6;
  uint uVar7;
  int local_44;
  long local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  lVar5 = resservGetTlsCallContext();
  if (param_3 == (int *)0x0) {
    nvAssertFailedNoLog("(pNvdecAllocParams != NULL)","src/kernel/gpu/nvdec/kernel_nvdec_engdesc.c",
                        0x43);
    return 0xb33b1500;
  }
  if (*param_3 != 0xc) {
    nvDbg_Printf("src/kernel/gpu/nvdec/kernel_nvdec_engdesc.c",0x47,
                 "nvdecGetEngineDescFromAllocParams",4,
                 "NVRM: createParams size mismatch (rm = 0x%x / client = 0x%x)\n",0xc,*param_3);
    return 0xb33b1500;
  }
  if (param_2 != 0xc3b0) {
    if (0xc3b0 < param_2) {
      if (param_2 != 0xcdb0) {
        if (param_2 < 0xcdb1) {
          if (param_2 != 0xc7b0) {
            if (param_2 < 0xc7b1) {
              if ((param_2 & 0xfffffdff) != 0xc4b0) {
                return 0xb33b1500;
              }
            }
            else if (param_2 != 0xc9b0) {
              return 0xb33b1500;
            }
          }
        }
        else if (((param_2 & 0xfffffeff) != 0xceb0) && (param_2 != 0xd1b0)) {
          return 0xb33b1500;
        }
      }
LAB_0040d370:
      uVar7 = param_3[2];
      goto LAB_0040d375;
    }
    if (param_2 != 0xb6b0) {
      if (0xb6b0 < param_2) {
        uVar7 = 0;
        if ((param_2 - 0xc1b0 & 0xfffffeff) == 0) goto LAB_0040d375;
        if (param_2 != 0xb8b0) {
          return 0xb33b1500;
        }
        goto LAB_0040d370;
      }
      if ((param_2 & 0xffffefff) != 0xa0b0) {
        return 0xb33b1500;
      }
    }
  }
  uVar7 = 0;
LAB_0040d375:
  if (((param_1 == 0) || (*(long *)(param_1 + 0x1bc0) == 0)) ||
     (cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar2 == '\0')) {
    uVar4 = uVar7 | 0x8f99e100;
  }
  else {
    local_40 = 0;
    uVar1 = *(undefined8 *)(param_1 + 0x1bc0);
    iVar3 = refFindAncestorOfType(*(undefined8 *)(lVar5 + 0x10),&DAT_00e0ac20,&local_40);
    if (iVar3 != 0) {
      nvAssertOkFailedNoLog
                (iVar3,
                 "refFindAncestorOfType(pCallContext->pResourceRef, classId(Device), &pDeviceRef)",
                 "src/kernel/gpu/nvdec/kernel_nvdec_engdesc.c",0x6e);
    }
    uVar4 = 0xb33b1500;
    if (local_40 != 0) {
      uVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_40 + 8),__nvoc_class_def_Device);
      iVar3 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,uVar1,uVar6,&local_38);
      if (iVar3 != 0) {
        nvAssertOkFailedNoLog
                  (iVar3,
                   "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, dynamicCast(pDeviceRef->pResource, Device), &ref)"
                   ,"src/kernel/gpu/nvdec/kernel_nvdec_engdesc.c",0x75);
      }
      iVar3 = kmigmgrGetLocalToGlobalEngineType_IMPL
                        (param_1,uVar1,local_38,local_30,uVar7 + 0x1d,&local_44);
      if (iVar3 != 0) {
        nvAssertOkFailedNoLog
                  (iVar3,
                   "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, RM_ENGINE_TYPE_NVDEC(engineInstance), &rmEngineType)"
                   ,"src/kernel/gpu/nvdec/kernel_nvdec_engdesc.c",0x7a);
      }
      uVar4 = local_44 - 0x1dU | 0x8f99e100;
    }
  }
  return uVar4;
}


// ===== 0040d5b6 msencctxConstructHal_KERNEL.cold =====

void msencctxConstructHal_KERNEL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0040d5c0 msencctxConstructHal_KERNEL =====

undefined8 msencctxConstructHal_KERNEL(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  undefined8 uVar5;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar1 = *(long *)(param_1 + 0x1d8);
  uVar5 = *(undefined8 *)(*(long *)(lVar1 + 0x158) + 0xe0);
  lVar4 = kflcnGetKernelFalconForEngine_IMPL(uVar5,*(undefined4 *)(lVar1 + 0x184));
  if (lVar4 != 0) {
    uVar2 = *(undefined8 *)(lVar1 + 0x178);
    nvDbg_Printf("src/kernel/gpu/nvenc/kernel_nvenc_ctx.c",0x31,"msencctxConstructHal_KERNEL",1,
                 "NVRM: msencctxConstruct for 0x%x\n",*(undefined4 *)(lVar1 + 0x184));
    uVar5 = kflcnAllocContext_IMPL
                      (uVar5,lVar4,uVar2,
                       *(undefined4 *)(*(long *)(*(long *)(lVar1 + 0x140) + 0x48) + 0x11c));
    return uVar5;
  }
  return 0x40;
}


// ===== 0040d66e msencctxDestructHal_KERNEL.cold =====

void msencctxDestructHal_KERNEL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0040d680 msencctxDestructHal_KERNEL =====

void msencctxDestructHal_KERNEL(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  lVar1 = *(long *)(param_1 + 0x1d8);
  uVar2 = *(undefined8 *)(*(long *)(lVar1 + 0x158) + 0xe0);
  uVar6 = kflcnGetKernelFalconForEngine_IMPL(uVar2,*(undefined4 *)(lVar1 + 0x184));
  uVar3 = *(undefined8 *)(lVar1 + 0x178);
  nvDbg_Printf("src/kernel/gpu/nvenc/kernel_nvenc_ctx.c",0x40,"msencctxDestructHal_KERNEL",1,
               "NVRM: msencctxDestruct for 0x%x\n",*(undefined4 *)(lVar1 + 0x184));
  iVar5 = kflcnFreeContext_IMPL
                    (uVar2,uVar6,uVar3,
                     *(undefined4 *)(*(long *)(*(long *)(lVar1 + 0x140) + 0x48) + 0x11c));
  if (iVar5 == 0) {
    return;
  }
  nvAssertOkFailedNoLog
            (iVar5,
             "kflcnFreeContext(pGpu, pKernelFalcon, pKernelChannel, RES_GET_EXT_CLASS_ID(pChannelDescendant))"
             ,"src/kernel/gpu/nvenc/kernel_nvenc_ctx.c",0x42);
  return;
}


// ===== 0040d750 deviceCtrlCmdMsencGetCapsV2_VF =====

undefined8 deviceCtrlCmdMsencGetCapsV2_VF(long param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = gpuGetStaticInfo(*(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0));
  if (lVar1 != 0) {
    portMemCopy(param_2,0xc,lVar1 + 0x1f184,0xc);
    return 0;
  }
  nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/nvenc/kernel_nvenc_ctx.c",0x4d);
  return 0x40;
}


// ===== 0040d7d0 msencGetEngineDescFromAllocParams =====

uint msencGetEngineDescFromAllocParams(long param_1,uint param_2,int *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 extraout_RDX;
  ulong uVar8;
  int local_44;
  long local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  lVar6 = resservGetTlsCallContext();
  if (*param_3 == 0xc) {
    uVar1 = param_3[2];
    uVar8 = (ulong)uVar1;
    if (param_2 != 0xc9b7) {
      if (param_2 < 0xc9b8) {
        if (((param_2 - 0xb4b7 & 0xffffefff) != 0) && (param_2 != 0xc7b7)) goto LAB_0040d827;
      }
      else if (((param_2 & 0xfffffeff) != 0xceb7) && (param_2 != 0xd1b7)) {
LAB_0040d827:
        nvDbg_Printf("src/kernel/gpu/nvenc/kernel_nvenc_engdesc.c",0x4e,
                     "msencGetEngineDescFromAllocParams",4,
                     "NVRM: Not supported msenc class Id (classId = 0x%x / engineInstance = 0x%x)\n"
                     ,param_2,uVar8);
        goto LAB_0040d858;
      }
    }
    nvDbg_Printf("src/kernel/gpu/nvenc/kernel_nvenc_engdesc.c",0x49,
                 "msencGetEngineDescFromAllocParams",1,
                 "NVRM: Supported msenc class Id (classId = 0x%x / engineInstance = 0x%x)\n",param_2
                );
    if (((param_1 == 0) || (*(long *)(param_1 + 0x1bc0) == 0)) ||
       (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL
                          (param_1,*(long *)(param_1 + 0x1bc0),extraout_RDX,uVar8), cVar3 == '\0'))
    {
      return uVar1 | 0xe97b6c00;
    }
    local_40 = 0;
    uVar2 = *(undefined8 *)(param_1 + 0x1bc0);
    iVar4 = refFindAncestorOfType(*(undefined8 *)(lVar6 + 0x10),&DAT_00e0ac20,&local_40);
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog
                (iVar4,
                 "refFindAncestorOfType(pCallContext->pResourceRef, classId(Device), &pDeviceRef)",
                 "src/kernel/gpu/nvenc/kernel_nvenc_engdesc.c",0x5b);
    }
    uVar5 = 0xb33b1500;
    if (local_40 != 0) {
      uVar7 = __nvoc_dynamicCast(*(undefined8 *)(local_40 + 8),__nvoc_class_def_Device);
      iVar4 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,uVar2,uVar7,&local_38);
      if (iVar4 != 0) {
        nvAssertOkFailedNoLog
                  (iVar4,
                   "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, dynamicCast(pDeviceRef->pResource, Device), &ref)"
                   ,"src/kernel/gpu/nvenc/kernel_nvenc_engdesc.c",0x62);
      }
      iVar4 = kmigmgrGetLocalToGlobalEngineType_IMPL
                        (param_1,uVar2,local_38,local_30,uVar1 + 0x25,&local_44);
      if (iVar4 != 0) {
        nvAssertOkFailedNoLog
                  (iVar4,
                   "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, RM_ENGINE_TYPE_NVENC(engineInstance), &rmEngineType)"
                   ,"src/kernel/gpu/nvenc/kernel_nvenc_engdesc.c",0x67);
      }
      uVar5 = local_44 - 0x25U | 0xe97b6c00;
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/nvenc/kernel_nvenc_engdesc.c",0x38,
                 "msencGetEngineDescFromAllocParams",4,
                 "NVRM: createParams size mismatch (rm = 0x%x / client = 0x%x)\n",0xc,*param_3);
LAB_0040d858:
    uVar5 = 0xb33b1500;
  }
  return uVar5;
}


// ===== 0040da40 _gpuNvEncSessionDataProcessing =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1 * _gpuNvEncSessionDataProcessing(undefined1 *param_1)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  long lVar6;
  undefined1 *puVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  undefined8 extraout_RDX;
  undefined8 uVar11;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  ulong uVar12;
  uint *puVar13;
  undefined4 uVar14;
  uint uVar15;
  ulong uVar16;
  undefined4 *puVar17;
  int iVar18;
  undefined1 auVar19 [16];
  undefined8 uStack_80;
  int local_6c;
  undefined8 local_58;
  undefined8 local_50;
  ulong local_48;
  undefined8 local_40;
  
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  auVar19 = listHead_IMPL(param_1 + 0x49b8);
  puVar7 = (undefined1 *)0x0;
  if (auVar19._0_8_ != 0) {
    local_6c = 0;
    do {
      puVar17 = auVar19._0_8_;
      auVar19 = listNext_IMPL(param_1 + 0x49b8,puVar17,auVar19._8_8_);
      puVar5 = auVar19._0_8_;
      lVar2 = *(long *)(puVar17 + 2);
      puVar7 = puVar5;
      uVar11 = auVar19._8_8_;
      if (lVar2 != 0) {
        lVar8 = *(long *)(lVar2 + 0x168);
        if (lVar8 == 0) {
          nvDbg_Printf("src/kernel/gpu/nvenc/nvencsession.c",0xfe,"_gpuNvEncSessionProcessBuffer",1,
                       "NVRM: GPU : 0x%0x, NvEnc session stats buffer pointer is null.\n",
                       *(undefined4 *)(param_1 + 0x7ac));
          uVar11 = extraout_RDX_00;
        }
        else {
          lVar6 = portMemAllocNonPaged(0x3000);
          if (lVar6 == 0) {
            nvDbg_Printf("src/kernel/gpu/nvenc/nvencsession.c",0x105,"_gpuNvEncSessionProcessBuffer"
                         ,1,"NVRM: GPU : 0x%0x, Failed to allocate memory for local stats buffer.\n"
                         ,*(undefined4 *)(param_1 + 0x7ac));
            uVar11 = extraout_RDX_01;
          }
          else {
            portMemSet(lVar6,0,0x3000);
            portMemCopy(lVar6,0x3000,lVar8,0x3000);
            uVar15 = *(uint *)(lVar2 + 0x178) + 1 & 0xff;
            if (*(int *)(lVar6 + (ulong)*(uint *)(lVar2 + 0x178) * 0x10) != *(int *)(lVar2 + 0x17c))
            {
              puVar13 = (uint *)(lVar6 + 0xfe0);
              uVar15 = 0xff;
              uVar3 = *(uint *)(lVar6 + 0xff0);
              do {
                uVar1 = *puVar13;
                if (uVar3 <= uVar1) break;
                puVar13 = puVar13 + -4;
                uVar15 = uVar15 - 1;
                uVar3 = uVar1;
              } while (uVar15 != 0);
            }
            uVar10 = (ulong)uVar15;
            if (*(long *)(lVar2 + 0x180) == 0) {
              *(undefined8 *)(lVar2 + 0x180) = *(undefined8 *)(lVar6 + 0x1008 + uVar10 * 0x20);
            }
            uVar12 = (ulong)uVar15;
            iVar18 = 0x100;
            uVar16 = 0;
            uVar9 = 0;
            while( true ) {
              puVar13 = (uint *)(uVar12 * 0x10 + lVar6);
              uVar3 = *puVar13;
              if (uVar3 < *(uint *)(lVar6 + uVar10 * 0x10)) break;
              lVar8 = uVar12 * 0x20 + lVar6;
              if ((uVar3 == *(uint *)(lVar8 + 0x1000)) && (uVar3 == *(uint *)(lVar8 + 0x1010))) {
                uVar10 = *(ulong *)(puVar13 + 2);
                if ((uVar10 <= *(ulong *)(lVar8 + 0x1008)) &&
                   (*(ulong *)(lVar8 + 0x1008) <= *(ulong *)(lVar8 + 0x1018))) {
                  uVar9 = uVar9 + 1;
                  uVar16 = (uVar16 + *(ulong *)(lVar8 + 0x1018)) - uVar10;
                  uVar15 = (uint)uVar12;
                }
              }
              uVar12 = (ulong)((uint)uVar12 + 1 & 0xff);
              iVar18 = iVar18 + -1;
              if (iVar18 == 0) break;
              uVar10 = (ulong)uVar15;
            }
            if (uVar9 == 0) {
              *(undefined8 *)(lVar2 + 0x154) = 0;
              uVar10 = 0;
            }
            else {
              uVar14 = 0xffffffff;
              uVar10 = 0x3e7fffffc17;
              iVar18 = *(int *)(lVar6 + (ulong)uVar15 * 0x10);
              uVar12 = CONCAT44(iVar18,uVar15);
              lVar8 = *(long *)(lVar6 + 0x1018 + (ulong)uVar15 * 0x20);
              if (uVar16 / uVar9 < 0x3e7fffffc18) {
                uVar10 = (uVar16 / uVar9) / 1000;
                uVar14 = (undefined4)uVar10;
              }
              uVar16 = lVar8 - *(long *)(lVar2 + 0x180);
              if ((long)uVar16 < 1) {
                uVar14 = 0;
                uVar4 = 0;
              }
              else {
                uVar10 = (ulong)(uint)(iVar18 - *(int *)(lVar2 + 0x17c)) * 1000000000;
                uVar4 = (undefined4)(uVar10 / uVar16);
                uVar10 = uVar10 % uVar16;
              }
              *(undefined4 *)(lVar2 + 0x158) = uVar14;
              *(undefined4 *)(lVar2 + 0x154) = uVar4;
              *(ulong *)(lVar2 + 0x178) = uVar12;
              *(long *)(lVar2 + 0x180) = lVar8;
            }
            portMemFree(lVar6,uVar12,uVar10);
            uVar11 = extraout_RDX;
          }
        }
        puVar7 = param_1;
        if ((param_1[0x908] != '\0') && (*(int *)(param_1 + 0x49e0) == 1)) {
          local_58 = *(undefined8 *)(*(long *)(puVar17 + 2) + 0x14c);
          local_48 = local_48 & 0xffffffff00000000;
          local_50 = CONCAT44(*(undefined4 *)(*(long *)(puVar17 + 2) + 0x154),
                              *(undefined4 *)(*(long *)(puVar17 + 2) + 0x158));
          uStack_80 = 0x40ddcf;
          auVar19 = gpuGetRpc(param_1);
          puVar7 = auVar19._0_8_;
          if (puVar7 == (undefined1 *)0x0) {
            auVar19 = nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/nvenc/nvencsession.c",0x198
                                         );
            uVar11 = auVar19._8_8_;
            puVar7 = auVar19._0_8_;
            local_6c = 0x1a;
          }
          else {
            uVar11 = auVar19._8_8_;
            if (local_6c == 0) {
              if ((param_1[0x909] == '\0') && (param_1[0x90a] == '\0')) {
                local_6c = rpcDmaControl_wrapper
                                     (param_1,puVar7,*puVar17,
                                      *(undefined4 *)(*(long *)(puVar17 + 2) + 0x138),0xa0bc0101,
                                      &local_58);
                puVar7 = &DAT_00000020;
                uVar11 = uStack_80;
              }
              else {
                auVar19 = (**(code **)(param_1 + 0x3b90))
                                    (param_1 + 0x3b58,*puVar17,
                                     *(undefined4 *)(*(long *)(puVar17 + 2) + 0x138),0xa0bc0101,
                                     &local_58,0x20);
                puVar7 = auVar19._0_8_;
                local_6c = auVar19._0_4_;
                uVar11 = auVar19._8_8_;
              }
            }
          }
        }
      }
      auVar19._8_8_ = uVar11;
      auVar19._0_8_ = puVar5;
    } while (puVar5 != (undefined1 *)0x0);
  }
  return puVar7;
}


// ===== 0040de90 _gpuNvEncSessionDataProcessingCallback =====

void _gpuNvEncSessionDataProcessingCallback(long param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x49e4) != '\0') {
    return;
  }
  iVar1 = osQueueWorkItem(param_1,_gpuNvEncSessionDataProcessingWorkItem,0,0x88);
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 0x49e4) = 1;
    return;
  }
  nvDbg_Printf("src/kernel/gpu/nvenc/nvencsession.c",0x1c2,"_gpuNvEncSessionDataProcessingCallback",
               4,"NVRM: NVENC session queuing async callback failed, status=%x\n",iVar1);
  _gpuNvEncSessionDataProcessing(param_1);
  return;
}


// ===== 0040df10 _gpuNvEncSessionDataProcessingWorkItem =====

void _gpuNvEncSessionDataProcessingWorkItem(void)

{
  long lVar1;
  
  lVar1 = gpumgrGetGpu();
  if (lVar1 != 0) {
    _gpuNvEncSessionDataProcessing(lVar1);
    *(undefined1 *)(lVar1 + 0x49e4) = 0;
    return;
  }
  nvDbg_Printf("src/kernel/gpu/nvenc/nvencsession.c",0x1ab,"_gpuNvEncSessionDataProcessingWorkItem",
               4,"NVRM: NVENC Sessions GPU instance is invalid\n");
  return;
}


// ===== 0040df70 nvencsessionConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */

int nvencsessionConstruct_IMPL(long param_1,long param_2,undefined4 *param_3)

{
  long lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  long lVar5;
  long lVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  long lVar10;
  undefined4 *puVar11;
  long lVar12;
  
  puVar4 = *(undefined4 **)(param_3 + 0x10);
  uVar2 = *(undefined4 *)(*(long *)(param_2 + 0x10) + 0x10);
  lVar5 = *(long *)(param_2 + 8);
  lVar6 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  uVar3 = *(undefined4 *)(lVar5 + 0x48);
  lVar10 = __nvoc_dynamicCast(lVar5,__nvoc_class_def_RmClient);
  lVar1 = lVar6 + 0x49b8;
  uVar8 = listCount_IMPL(lVar1);
  if (0x1ff < uVar8) {
    nvDbg_Printf("src/kernel/gpu/nvenc/nvencsession.c",0x3a,"nvencsessionConstruct_IMPL",3,
                 "NVRM: Creating NVENC session above max copyout limit.\n");
  }
  if (lVar10 == 0) {
    return 0x23;
  }
  if (*(char *)(lVar6 + 0x908) == '\0') {
LAB_0040dff8:
    if (puVar4[3] == 1) goto LAB_0040e194;
LAB_0040e004:
    *(undefined4 *)(param_1 + 0x15c) = 0;
  }
  else {
    lVar12 = gpuGetRpc(lVar6);
    if (lVar12 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/nvenc/nvencsession.c",0x45);
      goto LAB_0040dff8;
    }
    if ((*(char *)(lVar6 + 0x909) == '\0') && (*(char *)(lVar6 + 0x90a) == '\0')) {
      iVar9 = (**(code **)(lVar12 + 0x348))
                        (lVar6,lVar12,*param_3,param_3[1],param_3[2],param_3[3],puVar4);
    }
    else {
      iVar9 = (**(code **)(lVar6 + 0x3b60))(lVar6 + 0x3b58);
    }
    if (iVar9 != 0) {
      return iVar9;
    }
    if (puVar4[3] != 1) goto LAB_0040e004;
LAB_0040e194:
    *(undefined4 *)(param_1 + 0x15c) = 1;
    cVar7 = hypervisorIsVgxHyper_IMPL();
    if (cVar7 == '\0') {
      iVar9 = memGetByHandle_IMPL(lVar5,puVar4[4],param_1 + 0x160);
      if (iVar9 != 0) {
        nvDbg_Printf("src/kernel/gpu/nvenc/nvencsession.c",99,"nvencsessionConstruct_IMPL",4,
                     "NVRM: Unable to find mem corresponding to handle : 0x%0x.\n",puVar4[4]);
        *(undefined8 *)(param_1 + 0x160) = 0;
        return iVar9;
      }
      iVar9 = memdescMap(*(undefined8 *)(*(long *)(param_1 + 0x160) + 0x118),0,0x3000,1,1,
                         param_1 + 0x168,param_1 + 0x170);
      if (iVar9 != 0) {
        nvDbg_Printf("src/kernel/gpu/nvenc/nvencsession.c",0x73,"nvencsessionConstruct_IMPL",4,
                     "NVRM: Error mapping memory to CPU VA space, error : 0x%0x.\n",iVar9);
        *(undefined8 *)(param_1 + 0x160) = 0;
        return iVar9;
      }
      goto LAB_0040e030;
    }
  }
  *(undefined8 *)(param_1 + 0x160) = 0;
  *(undefined8 *)(param_1 + 0x168) = 0;
  *(undefined8 *)(param_1 + 0x170) = 0;
LAB_0040e030:
  puVar11 = (undefined4 *)listAppendNew_IMPL(lVar1);
  if (puVar11 == (undefined4 *)0x0) {
    iVar9 = 0x51;
  }
  else {
    portMemSet(puVar11,0,0x10);
    *(undefined4 *)(param_1 + 0x138) = uVar2;
    *(int *)(param_1 + 0x144) = sessionCounter;
    sessionCounter = sessionCounter + 1;
    *(undefined4 *)(param_1 + 0x13c) = *(undefined4 *)(lVar10 + 0x118);
    *(undefined4 *)(param_1 + 0x140) = *(undefined4 *)(lVar10 + 0x11c);
    *(undefined4 *)(param_1 + 0x148) = *puVar4;
    *(undefined4 *)(param_1 + 0x14c) = puVar4[1];
    uVar2 = puVar4[2];
    *(undefined8 *)(param_1 + 0x154) = 0;
    *(undefined4 *)(param_1 + 0x150) = uVar2;
    *(long *)(puVar11 + 2) = param_1;
    *puVar11 = uVar3;
    if (((*(int *)(param_1 + 0x15c) == 1) && (cVar7 = hypervisorIsVgxHyper_IMPL(), cVar7 == '\0'))
       && (iVar9 = listCount_IMPL(lVar1), iVar9 == 1)) {
      *(undefined1 *)(lVar6 + 0x49e4) = 0;
      osSchedule1HzCallback(lVar6,_gpuNvEncSessionDataProcessingCallback,0,1);
    }
    iVar9 = 0;
  }
  return iVar9;
}


// ===== 0040e350 nvencsessionDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void nvencsessionDestruct_IMPL(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long local_48;
  long local_40 [2];
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  resGetFreeParams_IMPL(*(undefined8 *)(param_1 + 0x110),local_40,&local_48);
  uVar1 = *(undefined4 *)(*(long *)(local_40[0] + 8) + 0x48);
  uVar2 = *(undefined4 *)(*(long *)(local_40[0] + 0x10) + 0x10);
  uVar3 = *(undefined4 *)(*(long *)(*(long *)(local_40[0] + 0x10) + 0x18) + 0x10);
  if (*(long *)(param_1 + 0x160) != 0) {
    memdescUnmap(*(undefined8 *)(*(long *)(param_1 + 0x160) + 0x118),1,
                 *(undefined8 *)(param_1 + 0x168),*(undefined8 *)(param_1 + 0x170));
  }
  iVar6 = 0;
  if (*(char *)(lVar4 + 0x908) != '\0') {
    lVar10 = gpuGetRpc(lVar4);
    if (lVar10 == 0) {
      iVar6 = 0x1a;
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/nvenc/nvencsession.c",0xce);
    }
    else {
      if ((*(char *)(lVar4 + 0x909) == '\0') && (*(char *)(lVar4 + 0x90a) == '\0')) {
        iVar6 = (**(code **)(lVar10 + 0xf0))
                          (lVar4,lVar10,uVar1,uVar3,uVar2,*(code **)(lVar10 + 0xf0));
      }
      else {
        iVar6 = (**(code **)(lVar4 + 0x3b70))(lVar4 + 0x3b58,uVar1,uVar2);
      }
      if (iVar6 == 0) goto LAB_0040e3e1;
    }
    nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/nvenc/nvencsession.c",0xcf);
  }
LAB_0040e3e1:
  lVar10 = lVar4 + 0x49b8;
  lVar8 = listHead_IMPL(lVar10);
  while (lVar9 = lVar8, lVar8 != 0) {
    while (lVar8 = listNext_IMPL(lVar10,lVar9), *(long *)(lVar9 + 8) == param_1) {
      listRemove_IMPL(lVar10,lVar9);
      lVar9 = lVar8;
      if (lVar8 == 0) goto LAB_0040e440;
    }
  }
LAB_0040e440:
  if (((*(int *)(param_1 + 0x15c) == 1) && (cVar5 = hypervisorIsVgxHyper_IMPL(), cVar5 == '\0')) &&
     (iVar7 = listCount_IMPL(lVar10), iVar7 == 0)) {
    osRemove1HzCallback(lVar4,_gpuNvEncSessionDataProcessingCallback,0);
  }
  *(int *)(local_48 + 0x30) = iVar6;
  return;
}


// ===== 0040e580 _nvencsessionCtrlCmdNvencSwSessionUpdateInfo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
_nvencsessionCtrlCmdNvencSwSessionUpdateInfo
          (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          uint param_6,ulong *param_7,long param_8)

{
  ulong uVar1;
  ulong uVar2;
  undefined4 *puVar3;
  char cVar4;
  undefined4 uVar5;
  long lVar6;
  ulong uVar7;
  ulong *puVar8;
  uint uVar9;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  nvDbg_Printf("src/kernel/gpu/nvenc/nvencsessionctrl.c",0x30,
               "_nvencsessionCtrlCmdNvencSwSessionUpdateInfo",1,"NVRM: \n");
  *(undefined4 *)(param_8 + 0x14c) = param_2;
  *(undefined4 *)(param_8 + 0x150) = param_3;
  if (*(int *)(param_8 + 0x15c) == 0) {
    if ((param_6 == 0) || (param_7 == (ulong *)0x0)) {
      *(undefined4 *)(param_8 + 0x158) = param_4;
      *(undefined4 *)(param_8 + 0x154) = param_5;
    }
    else {
      uVar9 = 0;
      uVar7 = 0;
      puVar8 = param_7;
      do {
        uVar1 = puVar8[1];
        uVar2 = *puVar8;
        lVar6 = (uVar1 - 1) + uVar7;
        uVar7 = (uVar7 + uVar1) - uVar2;
        if (uVar1 < uVar2) {
          uVar7 = lVar6 - uVar2;
        }
        uVar9 = uVar9 + 1;
        puVar8 = puVar8 + 2;
      } while (uVar9 < param_6);
      *(int *)(param_8 + 0x158) = (int)(uVar7 / param_6);
      uVar7 = param_7[(ulong)(param_6 - 1) * 2 + 1] - *param_7;
      if ((*param_7 < param_7[(ulong)(param_6 - 1) * 2 + 1]) || (uVar7 = uVar7 - 1, uVar7 != 0)) {
        *(int *)(param_8 + 0x154) = (int)((param_6 * 1000000) / uVar7);
      }
    }
    uVar5 = 0;
    if ((*(char *)(param_1 + 0x908) != '\0') && (*(int *)(param_1 + 0x49e0) == 1)) {
      lVar6 = resservGetTlsCallContext();
      local_58 = 0;
      puVar3 = *(undefined4 **)(lVar6 + 0x48);
      local_50 = 0;
      local_48 = 0;
      local_40 = 0;
      if (puVar3[2] + 0x5f43feff < 2) {
        local_58 = CONCAT44(param_3,param_2);
        local_50 = CONCAT44(*(undefined4 *)(param_8 + 0x154),*(undefined4 *)(param_8 + 0x158));
        lVar6 = gpuGetRpc(param_1);
        if (lVar6 == 0) {
          nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/nvenc/nvencsessionctrl.c",0x6f);
          uVar5 = 0x1a;
        }
        else if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) {
          uVar5 = rpcDmaControl_wrapper
                            (param_1,lVar6,*puVar3,puVar3[1],puVar3[2],&local_58,puVar3[6]);
        }
        else {
          uVar5 = (**(code **)(param_1 + 0x3b90))(param_1 + 0x3b58);
        }
      }
      else {
        nvAssertFailedNoLog("pRmCtrlParams->cmd == NVA0BC_CTRL_CMD_NVENC_SW_SESSION_UPDATE_INFO || pRmCtrlParams->cmd == NVA0BC_CTRL_CMD_NVENC_SW_SESSION_UPDATE_INFO_V2"
                            ,"src/kernel/gpu/nvenc/nvencsessionctrl.c",0x65);
        uVar5 = 0x40;
      }
    }
  }
  else {
    if ((*(int *)(param_8 + 0x15c) == 1) && (cVar4 = hypervisorIsVgxHyper_IMPL(), cVar4 != '\0')) {
      *(undefined4 *)(param_8 + 0x158) = param_4;
      *(undefined4 *)(param_8 + 0x154) = param_5;
    }
    uVar5 = 0;
  }
  return uVar5;
}


// ===== 0040e850 nvencsessionCtrlCmdNvencSwSessionUpdateInfo_IMPL =====

undefined8 nvencsessionCtrlCmdNvencSwSessionUpdateInfo_IMPL(long param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0);
  nvDbg_Printf("src/kernel/gpu/nvenc/nvencsessionctrl.c",0x8a,
               "nvencsessionCtrlCmdNvencSwSessionUpdateInfo_IMPL",1,"NVRM: \n");
  if (param_2 != (undefined4 *)0x0) {
    uVar1 = param_2[4];
    uVar3 = 0x1f;
    if (uVar1 < 0x3d) {
      if ((*(int *)(param_1 + 0x15c) == 0) && (uVar1 != 0)) {
        uVar3 = *(undefined8 *)(param_2 + 6);
      }
      else {
        uVar3 = 0;
      }
      uVar3 = _nvencsessionCtrlCmdNvencSwSessionUpdateInfo
                        (uVar2,*param_2,param_2[1],param_2[2],param_2[3],uVar1,uVar3,param_1);
    }
    return uVar3;
  }
  nvAssertFailedNoLog("(pParams != NULL)","src/kernel/gpu/nvenc/nvencsessionctrl.c",0x8c);
  return 0x3d;
}


// ===== 0040e930 nvencsessionCtrlCmdNvencSwSessionUpdateInfoV2_IMPL =====

undefined8 nvencsessionCtrlCmdNvencSwSessionUpdateInfoV2_IMPL(long param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0);
  nvDbg_Printf("src/kernel/gpu/nvenc/nvencsessionctrl.c",0xac,
               "nvencsessionCtrlCmdNvencSwSessionUpdateInfoV2_IMPL",1,"NVRM: \n");
  if (param_2 != (undefined4 *)0x0) {
    uVar1 = param_2[4];
    uVar3 = 0x1f;
    if (uVar1 < 0x3d) {
      if ((*(int *)(param_1 + 0x15c) != 0) || (puVar4 = param_2 + 6, uVar1 == 0)) {
        puVar4 = (undefined4 *)0x0;
      }
      uVar3 = _nvencsessionCtrlCmdNvencSwSessionUpdateInfo
                        (uVar2,*param_2,param_2[1],param_2[2],param_2[3],uVar1,puVar4,param_1);
    }
    return uVar3;
  }
  nvAssertFailedNoLog("(pParams != NULL)","src/kernel/gpu/nvenc/nvencsessionctrl.c",0xae);
  return 0x3d;
}


// ===== 0040e9f8 nvjpgctxConstructHal_KERNEL.cold =====

void nvjpgctxConstructHal_KERNEL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0040ea10 nvjpgctxConstructHal_KERNEL =====

undefined8 nvjpgctxConstructHal_KERNEL(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  undefined8 uVar5;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar1 = *(long *)(param_1 + 0x1d8);
  uVar5 = *(undefined8 *)(*(long *)(lVar1 + 0x158) + 0xe0);
  lVar4 = kflcnGetKernelFalconForEngine_IMPL(uVar5,*(undefined4 *)(lVar1 + 0x184));
  if (lVar4 != 0) {
    uVar2 = *(undefined8 *)(lVar1 + 0x178);
    nvDbg_Printf("src/kernel/gpu/nvjpg/kernel_nvjpg_ctx.c",0x32,"nvjpgctxConstructHal_KERNEL",1,
                 "NVRM: nvjpgctxConstruct for 0x%x\n",*(undefined4 *)(lVar1 + 0x184));
    uVar5 = kflcnAllocContext_IMPL
                      (uVar5,lVar4,uVar2,
                       *(undefined4 *)(*(long *)(*(long *)(lVar1 + 0x140) + 0x48) + 0x11c));
    return uVar5;
  }
  return 0x40;
}


// ===== 0040eabe nvjpgctxDestructHal_KERNEL.cold =====

void nvjpgctxDestructHal_KERNEL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0040ead0 nvjpgctxDestructHal_KERNEL =====

void nvjpgctxDestructHal_KERNEL(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  lVar1 = *(long *)(param_1 + 0x1d8);
  uVar2 = *(undefined8 *)(*(long *)(lVar1 + 0x158) + 0xe0);
  uVar6 = kflcnGetKernelFalconForEngine_IMPL(uVar2,*(undefined4 *)(lVar1 + 0x184));
  uVar3 = *(undefined8 *)(lVar1 + 0x178);
  nvDbg_Printf("src/kernel/gpu/nvjpg/kernel_nvjpg_ctx.c",0x41,"nvjpgctxDestructHal_KERNEL",1,
               "NVRM: nvjpgctxDestruct for 0x%x\n",*(undefined4 *)(lVar1 + 0x184));
  iVar5 = kflcnFreeContext_IMPL
                    (uVar2,uVar6,uVar3,
                     *(undefined4 *)(*(long *)(*(long *)(lVar1 + 0x140) + 0x48) + 0x11c));
  if (iVar5 == 0) {
    return;
  }
  nvAssertOkFailedNoLog
            (iVar5,
             "kflcnFreeContext(pGpu, pKernelFalcon, pKernelChannel, RES_GET_EXT_CLASS_ID(pChannelDescendant))"
             ,"src/kernel/gpu/nvjpg/kernel_nvjpg_ctx.c",0x43);
  return;
}


// ===== 0040eba0 deviceCtrlCmdNvjpgGetCapsV2_VF =====

undefined8 deviceCtrlCmdNvjpgGetCapsV2_VF(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = gpuGetStaticInfo(*(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0));
  if (lVar1 != 0) {
    if (*(uint *)(param_2 + 0xc) < 8) {
      lVar2 = (ulong)*(uint *)(param_2 + 0xc) * 0x10 + 0x1f104;
    }
    else {
      nvDbg_Printf("src/kernel/gpu/nvjpg/kernel_nvjpg_ctx.c",0x53,"deviceCtrlCmdNvjpgGetCapsV2_VF",4
                   ,
                   "NVRM: Requested NVJPGS Id 0x%x is not present. Hence, returning capabilities of NVJPGS0\n"
                  );
      *(undefined4 *)(param_2 + 0xc) = 0;
      lVar2 = 0x1f104;
    }
    portMemCopy(param_2,9,lVar1 + lVar2,9);
    return 0;
  }
  nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/nvjpg/kernel_nvjpg_ctx.c",0x4e);
  return 0x40;
}


// ===== 0040ec70 nvjpgGetEngineDescFromAllocParams =====

uint nvjpgGetEngineDescFromAllocParams(long param_1,uint param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined8 uVar7;
  char *pcVar8;
  int local_44;
  long local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  lVar4 = resservGetTlsCallContext();
  if (param_3 == (int *)0x0) {
    nvAssertFailedNoLog("(pNvjpgAllocParms != NULL)","src/kernel/gpu/nvjpg/kernel_nvjpg_engdesc.c",
                        0x3b);
    return 0xb33b1500;
  }
  iVar2 = *param_3;
  if (iVar2 != 0xc) {
    param_2 = 0xc;
    pcVar8 = "NVRM: createParams size mismatch (rm = 0x%x / client = 0x%x)\n";
    uVar7 = 0x3f;
    goto LAB_0040ed07;
  }
  if (param_2 == 0xc4d1) {
    uVar6 = 0;
    goto LAB_0040ed32;
  }
  if (param_2 < 0xc4d2) {
    if (param_2 != 0xb8d1) goto LAB_0040ece4;
  }
  else if (param_2 != 0xced0) {
    if (param_2 < 0xced1) {
      if ((param_2 & 0xfffffbff) != 0xc9d1) {
LAB_0040ece4:
        iVar2 = param_3[2];
        pcVar8 = "NVRM: Not supported nvjpg class Id (classId = 0x%x / engineInstance = 0x%x)\n";
        uVar7 = 0x58;
LAB_0040ed07:
        nvDbg_Printf("src/kernel/gpu/nvjpg/kernel_nvjpg_engdesc.c",uVar7,
                     "nvjpgGetEngineDescFromAllocParams",4,pcVar8,param_2,iVar2);
        return 0xb33b1500;
      }
    }
    else if (param_2 != 0xcfd1) goto LAB_0040ece4;
  }
  uVar6 = param_3[2];
  nvDbg_Printf("src/kernel/gpu/nvjpg/kernel_nvjpg_engdesc.c",0x51,
               "nvjpgGetEngineDescFromAllocParams",1,
               "NVRM: Supported nvjpg class Id (classId = 0x%x / engineInstance = 0x%x)\n",param_2,
               uVar6);
LAB_0040ed32:
  if (((param_1 == 0) || (*(long *)(param_1 + 0x1bc0) == 0)) ||
     (cVar1 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar1 == '\0')) {
    uVar3 = uVar6 | 0x2b3a5400;
  }
  else {
    local_40 = 0;
    uVar7 = *(undefined8 *)(param_1 + 0x1bc0);
    iVar2 = refFindAncestorOfType(*(undefined8 *)(lVar4 + 0x10),&DAT_00e0ac20,&local_40);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,
                 "refFindAncestorOfType(pCallContext->pResourceRef, classId(Device), &pDeviceRef)",
                 "src/kernel/gpu/nvjpg/kernel_nvjpg_engdesc.c",0x65);
    }
    uVar3 = 0xb33b1500;
    if (local_40 != 0) {
      uVar5 = __nvoc_dynamicCast(*(undefined8 *)(local_40 + 8),__nvoc_class_def_Device);
      iVar2 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,uVar7,uVar5,&local_38);
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,
                   "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, dynamicCast(pDeviceRef->pResource, Device), &ref)"
                   ,"src/kernel/gpu/nvjpg/kernel_nvjpg_engdesc.c",0x6c);
      }
      iVar2 = kmigmgrGetLocalToGlobalEngineType_IMPL
                        (param_1,uVar7,local_38,local_30,uVar6 + 0x36,&local_44);
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,
                   "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, RM_ENGINE_TYPE_NVJPEG(engineInstance), &rmEngineType)"
                   ,"src/kernel/gpu/nvjpg/kernel_nvjpg_engdesc.c",0x71);
      }
      uVar3 = local_44 - 0x36U | 0x2b3a5400;
    }
  }
  return uVar3;
}


// ===== 0040ef30 __pfx_knvlinkOverrideConfig_GA100 =====

int __pfx_knvlinkOverrideConfig_GA100(undefined8 param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined1 uStack_120;
  undefined1 uStack_11f;
  undefined1 auStack_118 [256];
  
  lVar3 = portMemAllocNonPaged((ulong)*(uint *)(param_2 + 0x3c0) << 2);
  *(long *)(param_2 + 0x330) = lVar3;
  if (lVar3 == 0) {
    return 0x51;
  }
  portMemSet(lVar3,0,(ulong)*(uint *)(param_2 + 0x3c0) << 2);
  uVar1 = 0;
  if (*(int *)(param_2 + 0x3c0) != 0) {
    lVar3 = 0;
    do {
      *(uint *)(*(long *)(param_2 + 0x330) + lVar3 * 4) = ((uint)lVar3 & 0x3f) << 0x10;
      uVar1 = *(uint *)(param_2 + 0x3c0);
      lVar3 = lVar3 + 1;
    } while ((uint)lVar3 < uVar1);
  }
  iVar2 = osGetForcedNVLinkConnection(param_1,uVar1,*(undefined8 *)(param_2 + 0x330));
  if ((iVar2 == 0) && (*(char *)(param_2 + 0x15fb) == '\0')) {
    portMemSet(&uStack_120,0,0x108);
    uStack_120 = 0;
    lVar3 = (ulong)*(uint *)(param_2 + 0x3c0) << 2;
    portMemCopy(auStack_118,lVar3,*(undefined8 *)(param_2 + 0x330),lVar3);
    iVar2 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a95,&uStack_120,0x108);
    if (iVar2 == 0) {
      *(undefined1 *)(param_2 + 0x348) = uStack_11f;
      iVar2 = knvlinkSetupTopologyForForcedConfig_IMPL(param_1,param_2);
      return iVar2;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/arch/ampere/kernel_nvlink_ga100.c",100,
                 "knvlinkOverrideConfig_GA100",4,
                 "NVRM: Failed to process forced NVLink configurations !\n");
    portMemFree(*(undefined8 *)(param_2 + 0x330));
    *(undefined8 *)(param_2 + 0x330) = 0;
    return iVar2;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/arch/ampere/kernel_nvlink_ga100.c",0x4c,
               "knvlinkOverrideConfig_GA100",1,"NVRM: Not using forced config!\n");
  portMemFree(*(undefined8 *)(param_2 + 0x330));
  *(undefined8 *)(param_2 + 0x330) = 0;
  return 0;
}


// ===== 0040ef40 knvlinkOverrideConfig_GA100 =====

int knvlinkOverrideConfig_GA100(undefined8 param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined1 local_120;
  undefined1 local_11f;
  undefined1 local_118 [256];
  
  lVar3 = portMemAllocNonPaged((ulong)*(uint *)(param_2 + 0x3c0) << 2);
  *(long *)(param_2 + 0x330) = lVar3;
  if (lVar3 == 0) {
    return 0x51;
  }
  portMemSet(lVar3,0,(ulong)*(uint *)(param_2 + 0x3c0) << 2);
  uVar1 = 0;
  if (*(int *)(param_2 + 0x3c0) != 0) {
    lVar3 = 0;
    do {
      *(uint *)(*(long *)(param_2 + 0x330) + lVar3 * 4) = ((uint)lVar3 & 0x3f) << 0x10;
      uVar1 = *(uint *)(param_2 + 0x3c0);
      lVar3 = lVar3 + 1;
    } while ((uint)lVar3 < uVar1);
  }
  iVar2 = osGetForcedNVLinkConnection(param_1,uVar1,*(undefined8 *)(param_2 + 0x330));
  if ((iVar2 == 0) && (*(char *)(param_2 + 0x15fb) == '\0')) {
    portMemSet(&local_120,0,0x108);
    local_120 = 0;
    lVar3 = (ulong)*(uint *)(param_2 + 0x3c0) << 2;
    portMemCopy(local_118,lVar3,*(undefined8 *)(param_2 + 0x330),lVar3);
    iVar2 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a95,&local_120,0x108);
    if (iVar2 == 0) {
      *(undefined1 *)(param_2 + 0x348) = local_11f;
      iVar2 = knvlinkSetupTopologyForForcedConfig_IMPL(param_1,param_2);
      return iVar2;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/arch/ampere/kernel_nvlink_ga100.c",100,
                 "knvlinkOverrideConfig_GA100",4,
                 "NVRM: Failed to process forced NVLink configurations !\n");
    portMemFree(*(undefined8 *)(param_2 + 0x330));
    *(undefined8 *)(param_2 + 0x330) = 0;
    return iVar2;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/arch/ampere/kernel_nvlink_ga100.c",0x4c,
               "knvlinkOverrideConfig_GA100",1,"NVRM: Not using forced config!\n");
  portMemFree(*(undefined8 *)(param_2 + 0x330));
  *(undefined8 *)(param_2 + 0x330) = 0;
  return 0;
}


// ===== 0040f150 knvlinkRemoveMapping_GA100 =====

void knvlinkRemoveMapping_GA100
               (undefined8 param_1,long param_2,char param_3,uint param_4,undefined1 param_5)

{
  int iVar1;
  uint *puVar2;
  int local_44;
  uint local_40;
  undefined1 local_3c;
  
  portMemSet(&local_44,0,0xc);
  local_44 = 3 - (uint)(param_3 == '\0');
  local_40 = 0xff;
  if (param_3 == '\0') {
    local_40 = param_4;
  }
  local_3c = param_5;
  iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a5f,&local_44,0xc);
  if ((iVar1 != 0) || (iVar1 = knvlinkSyncLinkMasksAndVbiosInfo_IMPL(param_1,param_2), iVar1 != 0))
  {
    return;
  }
  if ((*(char *)(param_2 + 0x2e4) != '\0') && (param_4 != 0)) {
    puVar2 = (uint *)(param_2 + 0x14c8);
    do {
      if ((param_4 & 1) != 0) {
        if ((*puVar2 & (uint)*(undefined8 *)(param_2 + 0x3b8)) != 0) {
          return;
        }
        if (param_4 >> 1 == 0) break;
      }
      param_4 = param_4 >> 1;
      puVar2 = puVar2 + 2;
    } while( true );
  }
  knvlinkUpdateCurrentConfig_IMPL(param_1,param_2);
  return;
}


// ===== 0040f240 knvlinkValidateFabricBaseAddress_GA100 =====

undefined8 knvlinkValidateFabricBaseAddress_GA100(long param_1,undefined8 param_2,ulong param_3)

{
  ulong uVar1;
  
  if ((((param_3 & 0xfffffffff) == 0) &&
      (uVar1 = *(long *)(*(long *)(param_1 + 0x1b78) + 0x830) * 0x100000 + 0xfffffffffU &
               0xfffffff000000000, param_3 + uVar1 < 0x800000000001)) && (!CARRY8(param_3,uVar1))) {
    return 0;
  }
  return 0x1f;
}


// ===== 0040f2b0 knvlinkIsGpuReducedNvlinkConfig_GA100 =====

undefined1 knvlinkIsGpuReducedNvlinkConfig_GA100(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 local_19;
  
  portMemSet(&local_19,0,1);
  iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20803046,&local_19,1);
  if (iVar1 == 0) {
    return local_19;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/arch/ampere/kernel_nvlink_ga100.c",0x11a,
               "knvlinkIsGpuReducedNvlinkConfig_GA100",4,
               "NVRM: Failed to execute GSP-RM GPC to get if the gpu has a reduced Nvlink config\n")
  ;
  return 0;
}


// ===== 0040f340 knvlinkEncryptionGetUpdateGpuIdentifiers_GB100 =====

int knvlinkEncryptionGetUpdateGpuIdentifiers_GB100(long param_1,long param_2,char param_3)

{
  uint uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  undefined1 local_12c [4];
  undefined4 local_128;
  undefined4 uStack_124;
  undefined4 auStack_120 [64];
  int local_20;
  undefined1 local_1c;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("(pKernelNvlink != NULL)",
                        "src/kernel/gpu/nvlink/arch/blackwell/kernel_nvle_gb100.c",0x36);
    return 0x1f;
  }
  if (*(char *)(param_1 + 0x4cc) == '\x01') {
    if (*(long *)(param_1 + 0x4c0) == 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/arch/blackwell/kernel_nvle_gb100.c",0x43,
                   "knvlinkEncryptionGetUpdateGpuIdentifiers_GB100",4,
                   "NVRM: %s: pGpuFabricProbeInfoKernel is NULL\n");
      return 0x1f;
    }
    lVar2 = *(long *)(g_pSys + 0x1e0);
    cVar3 = gpuFabricProbeIsReceived();
    if (cVar3 == '\0') {
      nvDbg_Printf("src/kernel/gpu/nvlink/arch/blackwell/kernel_nvle_gb100.c",0x49,
                   "knvlinkEncryptionGetUpdateGpuIdentifiers_GB100",4,
                   "NVRM: %s: Fabric probe has not been received\n");
      return 0x82;
    }
    portMemSet(local_12c,0,0x114);
    local_12c[0] = param_3 != '\0';
    if ((bool)local_12c[0]) {
      iVar4 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x2080308d,local_12c,0x114);
      uVar6 = 0x52;
      if (iVar4 != 0) goto LAB_0040f606;
      *(ulong *)(param_2 + 0x1724) = CONCAT44(uStack_124,local_128);
      *(undefined1 *)(param_2 + 0x172c) = local_1c;
      cVar3 = gpuMgrIsNvleAlidPresent(lVar2,local_128);
      if (cVar3 == '\0') {
        cVar3 = gpuMgrCacheNvleAlidClid
                          (lVar2,*(undefined4 *)(param_2 + 0x1724),*(undefined4 *)(param_2 + 0x1728)
                          );
        if (cVar3 != '\x01') {
          nvCheckFailedNoLog(4,
                             "(gpuMgrCacheNvleAlidClid(pGpuMgr, pKernelNvlink->alid, pKernelNvlink->clid) == NV_TRUE)"
                             ,"src/kernel/gpu/nvlink/arch/blackwell/kernel_nvle_gb100.c",0x5f);
          return 0x40;
        }
      }
    }
    else {
      uVar1 = *(uint *)(lVar2 + 0x3f274);
      if (uVar1 != 0) {
        lVar5 = 0;
        do {
          *(undefined4 *)((long)auStack_120 + lVar5) = *(undefined4 *)(lVar2 + 0x3f174 + lVar5);
          *(undefined4 *)((long)auStack_120 + lVar5 + 4) = *(undefined4 *)(lVar2 + 0x3f178 + lVar5);
          lVar5 = lVar5 + 8;
        } while (lVar5 != (ulong)uVar1 << 3);
        local_20 = local_20 + uVar1;
      }
      iVar4 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x2080308d,local_12c,0x114);
      if (iVar4 != 0) {
        uVar6 = 0x70;
LAB_0040f606:
        nvCheckOkFailedNoLog
                  (4,iVar4,
                   "knvlinkExecGspRmRpc(pGpu, pKernelNvlink, NV2080_CTRL_NVLINK_GET_UPDATE_NVLE_LIDS, (void *)&lidParams, sizeof(lidParams))"
                   ,"src/kernel/gpu/nvlink/arch/blackwell/kernel_nvle_gb100.c",uVar6);
        return iVar4;
      }
      *(ulong *)(param_2 + 0x1724) = CONCAT44(uStack_124,local_128);
      *(undefined1 *)(param_2 + 0x172c) = local_1c;
    }
  }
  else {
    *(uint *)(param_2 + 0x1724) = (uint)*(ushort *)(param_1 + 0x7ac);
    *(undefined4 *)(param_2 + 0x1728) = *(undefined4 *)(param_1 + 0x7ac);
  }
  return 0;
}


// ===== 0040f640 _knvlinkHandlePostSchedulingEnableCallback_GB100 =====

ulong _knvlinkHandlePostSchedulingEnableCallback_GB100(long param_1)

{
  ulong uVar1;
  
  uVar1 = knvlinkExecGspRmRpc_IMPL(param_1,*(undefined8 *)(param_1 + 0x1ce8),0x20800b01,0,0);
  if ((int)uVar1 == 0) {
    return uVar1;
  }
  nvCheckOkFailedNoLog
            (4,uVar1 & 0xffffffff,
             "knvlinkExecGspRmRpc(pGpu, pKernelNvlink, NV2080_CTRL_CMD_INTERNAL_NVLINK_REPLAY_SUPPRESSED_ERRORS, NULL, 0)"
             ,"src/kernel/gpu/nvlink/arch/blackwell/kernel_nvlink_gb100.c",0x2a3);
  return uVar1 & 0xffffffff;
}


// ===== 0040f6a0 knvlinkABMIdle_WORKITEM =====

void knvlinkABMIdle_WORKITEM(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  long lVar2;
  
  lVar2 = gpumgrGetGpu();
  cVar1 = knvlinkIsP2PActive_IMPL(lVar2,*(undefined8 *)(lVar2 + 0x1ce8));
  if (cVar1 == '\0') {
    nvDbg_Printf("src/kernel/gpu/nvlink/arch/blackwell/kernel_nvlink_gb100.c",0x1df,
                 "knvlinkABMIdle_WORKITEM",1,
                 "NVRM: Detected fabric idle. Setting requested adaptive bandwidth mode.\n");
    *(undefined1 *)(lVar2 + 0x4b9) = 1;
    gpuUnmarkDeviceForDrainP2P_KERNEL(lVar2);
    *(undefined1 *)(lVar2 + 0x4b9) = 0;
    osRemove1HzCallback(lVar2,knvlinkABM_WORKITEM,param_2);
    return;
  }
  *(undefined1 *)(lVar2 + 0x4b9) = 1;
  gpuSetRecoveryDrainP2P_KERNEL(lVar2,1);
  *(undefined1 *)(lVar2 + 0x4b9) = 0;
  return;
}


// ===== 0040f740 knvlinkP2PIdleCheck_WORKITEM =====

void knvlinkP2PIdleCheck_WORKITEM(void)

{
  char cVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = gpumgrGetGpu();
  cVar1 = knvlinkIsP2PActive_IMPL(lVar3,*(undefined8 *)(lVar3 + 0x1ce8));
  if (cVar1 == '\0') {
    gpuFabricProbeSuspend(*(undefined8 *)(lVar3 + 0x4c0));
    gpuFabricProbeInvalidate(*(undefined8 *)(lVar3 + 0x4c0));
    *(undefined1 *)(lVar3 + 0x4b9) = 1;
    gpuUnmarkDeviceForDrainP2P_KERNEL(lVar3);
    *(undefined1 *)(lVar3 + 0x4b9) = 0;
    iVar2 = gpuFabricProbeResume(*(undefined8 *)(lVar3 + 0x4c0));
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,"gpuFabricProbeResume(pGpu->pGpuFabricProbeInfoKernel)",
                 "src/kernel/gpu/nvlink/arch/blackwell/kernel_nvlink_gb100.c",0x2f9);
    }
    osRemove1HzCallback(lVar3,_knvlinkP2PIdleCallback,0);
    return;
  }
  *(undefined1 *)(lVar3 + 0x4b9) = 1;
  gpuSetRecoveryDrainP2P_KERNEL(lVar3,1);
  *(undefined1 *)(lVar3 + 0x4b9) = 0;
  return;
}


// ===== 0040f810 knvlinkABM_WORKITEM =====

void knvlinkABM_WORKITEM(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = osQueueWorkItem(param_1,knvlinkABMIdle_WORKITEM,0,0x68);
  if (iVar1 == 0) {
    return;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/arch/blackwell/kernel_nvlink_gb100.c",0x1fb,
               "knvlinkABM_WORKITEM",4,"NVRM: Failed to queue P2P idle check.\n");
  return;
}


// ===== 0040f860 _knvlinkP2PIdleCallback =====

void _knvlinkP2PIdleCallback(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = osQueueWorkItem(param_1,knvlinkP2PIdleCheck_WORKITEM,0,0x68);
  if (iVar1 == 0) {
    return;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/arch/blackwell/kernel_nvlink_gb100.c",0x311,
               "_knvlinkP2PIdleCallback",4,"NVRM: Failed to queue P2P idle check.\n");
  return;
}


// ===== 0040f8b0 knvlinkGetSupportedCounters_GB100 =====

undefined8 knvlinkGetSupportedCounters_GB100(undefined8 param_1,undefined8 param_2,ulong *param_3)

{
  portMemSet(param_3,0,0x10);
  *param_3 = *param_3 | 0xfbffffffffc00000;
  param_3[1] = param_3[1] | 0x7ffffffffff;
  return 0;
}


// ===== 0040f900 knvlinkLogAliDebugMessages_GB100 =====

int knvlinkLogAliDebugMessages_GB100(long param_1,long param_2,char param_3)

{
  long lVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  undefined8 local_68;
  undefined1 local_60 [12];
  undefined4 local_54 [9];
  
  lVar6 = portMemAllocNonPaged(0x1c38);
  if (lVar6 != 0) {
    portMemSet(lVar6,0,0x1c38);
    *(byte *)(lVar6 + 0x1c34) = *(byte *)(lVar6 + 0x1c34) | 2;
    iVar4 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20803003,lVar6,0x1c38);
    if (iVar4 == 0) {
      uVar9 = 0;
      bitVectorClrAll_IMPL(&local_68,0x40);
      portMemSet(local_54,0,0x1c);
      bitVectorCopy_IMPL(local_60,0x40,param_2 + 0x14b0,0x40);
      uVar5 = bitVectorCountTrailingZeros_IMPL(local_60,0x40);
      while( true ) {
        uVar8 = (ulong)uVar5;
        cVar3 = bitVectorTestAllCleared_IMPL(local_60,0x40);
        if (cVar3 != '\0') break;
        lVar1 = lVar6 + uVar8 * 0x70;
        uVar2 = *(undefined4 *)(lVar1 + 0x78);
        if ((short)uVar2 != 0) {
          nvDbg_Printf("src/kernel/gpu/nvlink/arch/blackwell/kernel_nvlink_gb100.c",0xb6,
                       "knvlinkLogAliDebugMessages_GB100",4,
                       "NVRM: ALI Error for GPU %d::linkId %d: 0x%x\n",
                       *(undefined4 *)(param_1 + 0x7a4),uVar8,uVar2);
          if (uVar9 != 7) {
            uVar7 = (ulong)uVar9;
            uVar9 = uVar9 + 1;
            local_54[uVar7] = *(undefined4 *)(lVar1 + 0x78);
          }
          bitVectorSet_IMPL(&local_68,0x40,uVar8);
        }
        bitVectorClr_IMPL(local_60,0x40,uVar8);
        uVar5 = bitVectorCountTrailingZeros_IMPL(local_60,0x40);
      }
      if (param_3 != '\0') {
        nvErrorLog_va(param_1,0x88,
                      "NVLink: Link training failed for links 0x%llx(0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x)\n"
                      ,local_68,local_54[0],local_54[1],local_54[2],local_54[3],local_54[4],
                      local_54[5],local_54[6]);
        gpuNotifySubDeviceEvent_IMPL(param_1,0x7b,0,0,0,0x88);
      }
      portMemFree(lVar6);
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar4,
                 "knvlinkExecGspRmRpc(pGpu, pKernelNvlink, NV2080_CTRL_CMD_NVLINK_GET_ERR_INFO, (void *)pParams, sizeof(*pParams))"
                 ,"src/kernel/gpu/nvlink/arch/blackwell/kernel_nvlink_gb100.c",0xa6);
      portMemFree(lVar6);
    }
    return iVar4;
  }
  return 0x51;
}


// ===== 0040fb50 knvlinkDumpCallbackRegister_GB100 =====

void knvlinkDumpCallbackRegister_GB100(long param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  long local_20;
  
  lVar1 = *(long *)(param_1 + 0x1ce0);
  local_20 = 0;
  if ((lVar1 != 0) &&
     ((iVar2 = nvdFindEngine_IMPL(param_1,lVar1,0x15,&local_20), iVar2 != 0 || (local_20 == 0)))) {
    nvdEngineSignUp_IMPL(param_1,lVar1,0,0x15,9,param_2);
    return;
  }
  return;
}


// ===== 0040fbe0 knvlinkIsBwModeSupported_GB100 =====

undefined8 knvlinkIsBwModeSupported_GB100(undefined8 param_1,long param_2,uint param_3)

{
  ushort *puVar1;
  ushort uVar2;
  
  if ((0x21UL >> (param_3 & 7) & 1) == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/arch/blackwell/kernel_nvlink_gb100.c",0x118,
                 "knvlinkIsBwModeSupported_GB100",4,
                 "NVRM: Legacy BW modes are not supported on this platform.\n");
  }
  else {
    if ((param_3 & 7) == 0) {
      return 1;
    }
    uVar2 = (ushort)param_3 >> 3;
    if (*(ushort *)(param_2 + 0x16d0) < (uVar2 & 0xff)) {
      nvDbg_Printf("src/kernel/gpu/nvlink/arch/blackwell/kernel_nvlink_gb100.c",0x125,
                   "knvlinkIsBwModeSupported_GB100",4,
                   "NVRM: RBM not supported by GFM. LinkCount: %d; MaxLinkCount: %d\n",(char)uVar2,
                   *(ushort *)(param_2 + 0x16d0));
    }
    else {
      if (*(byte *)(param_2 + 0x171a) != 0) {
        puVar1 = (ushort *)(param_2 + 0x16d2);
        do {
          if (*puVar1 == (ushort)param_3) {
            return 1;
          }
          puVar1 = puVar1 + 1;
        } while (puVar1 != (ushort *)
                           (param_2 + 0x16d4 + (ulong)(*(byte *)(param_2 + 0x171a) - 1) * 2));
      }
      nvDbg_Printf("src/kernel/gpu/nvlink/arch/blackwell/kernel_nvlink_gb100.c",0x134,
                   "knvlinkIsBwModeSupported_GB100",4,
                   "NVRM: RBM requested is not supported. LinkCount: %d\n");
    }
  }
  return 0;
}


// ===== 0040fd00 knvlinkGetHshubSupportedRbmModes_GB100 =====

undefined8 knvlinkGetHshubSupportedRbmModes_GB100(undefined8 param_1,long param_2)

{
  long lVar1;
  byte local_10 [8];
  
  local_10[0] = 5;
  local_10[1] = 0x15;
  local_10[2] = 0x25;
  local_10[3] = 0x35;
  local_10[4] = 0x45;
  local_10[5] = 0x65;
  lVar1 = 0;
  do {
    *(ushort *)(param_2 + 0x16d2 + lVar1 * 2) = (ushort)local_10[lVar1];
    lVar1 = lVar1 + 1;
  } while (lVar1 != 6);
  *(undefined1 *)(param_2 + 0x171a) = 6;
  return 0;
}


// ===== 0040fd70 knvlinkGetEffectivePeerLinkMask_GB100 =====

undefined8
knvlinkGetEffectivePeerLinkMask_GB100
          (long param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_2c;
  undefined8 local_28;
  undefined1 local_20 [8];
  
  uVar2 = knvlinkIsGpuConnectedToNvswitch_IMPL();
  if ((char)uVar2 != '\0') {
    uVar2 = gpuFabricProbeGetlinkMaskToBeReduced(*(undefined8 *)(param_1 + 0x4c0),&local_2c);
    if ((int)uVar2 == 0) {
      iVar1 = convertMaskToBitVector(local_2c,&local_28);
      if (iVar1 == 0) {
        iVar1 = bitVectorComplement_IMPL(local_20,0x40,&local_28,0x40);
        if (iVar1 == 0) {
          iVar1 = bitVectorAnd_IMPL(param_4,0x40,param_4,0x40,local_20,0x40);
          if (iVar1 == 0) {
            uVar2 = *param_4;
            nvDbg_Printf("src/kernel/gpu/nvlink/arch/blackwell/kernel_nvlink_gb100.c",0x181,
                         "knvlinkGetEffectivePeerLinkMask_GB100",1,
                         "NVRM: Reducing nvlinkMask from 0x%llx to updated 0x%llx\n",local_28);
          }
          else {
            uVar2 = nvCheckOkFailedNoLog
                              (4,iVar1,
                               "bitVectorAnd(pPeerLinkMask, pPeerLinkMask, &complementLinkMaskToBeReducedVec)"
                               ,"src/kernel/gpu/nvlink/arch/blackwell/kernel_nvlink_gb100.c",0x17e);
          }
        }
        else {
          uVar2 = nvCheckOkFailedNoLog
                            (4,iVar1,
                             "bitVectorComplement(&complementLinkMaskToBeReducedVec, &linkMaskToBeReducedVec)"
                             ,"src/kernel/gpu/nvlink/arch/blackwell/kernel_nvlink_gb100.c",0x17b);
        }
      }
      else {
        uVar2 = nvCheckOkFailedNoLog
                          (4,iVar1,
                           "convertMaskToBitVector(linkMaskToBeReduced, &linkMaskToBeReducedVec)",
                           "src/kernel/gpu/nvlink/arch/blackwell/kernel_nvlink_gb100.c",0x178);
      }
    }
  }
  return uVar2;
}


// ===== 0040fec0 knvlinkGetSupportedBwMode_GB100 =====

undefined8 knvlinkGetSupportedBwMode_GB100(undefined8 param_1,long param_2,long param_3)

{
  ushort uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar3 = (ulong)*(byte *)(param_2 + 0x171a);
  if (*(byte *)(param_2 + 0x171a) != 0) {
    uVar2 = 0;
    while (uVar3 = uVar2, uVar1 = *(ushort *)(param_2 + 0x16d2 + uVar3 * 2),
          uVar1 <= (*(short *)(param_2 + 0x16d0) * 8 + 5U & 0xff)) {
      *(ushort *)(param_3 + uVar3 * 2) = uVar1;
      uVar2 = uVar3 + 1;
      if ((uint)*(byte *)(param_2 + 0x171a) <= (uint)(uVar3 + 1)) {
        *(char *)(param_3 + 0x2e) = (char)uVar3 + '\x01';
        return 0;
      }
    }
  }
  *(char *)(param_3 + 0x2e) = (char)uVar3;
  return 0;
}


// ===== 0040ff50 knvlinkSetDirectConnectBaseAddress_GB100 =====

undefined8 knvlinkSetDirectConnectBaseAddress_GB100(long param_1,long param_2)

{
  if (*(char *)(param_1 + 0x4915) != '\0') {
    *(undefined8 *)(param_2 + 0x16b8) = 0x40000000000;
  }
  return 0;
}


// ===== 0040ff80 knvlinkValidateFabricBaseAddress_GB100 =====

byte knvlinkValidateFabricBaseAddress_GB100(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  return -((param_3 & 0x3ffffffffff) != 0) & 0x1f;
}


// ===== 0040ffa0 knvlinkABMLinkMaskUpdate_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int knvlinkABMLinkMaskUpdate_GB100(long param_1,undefined8 param_2,char param_3)

{
  int iVar1;
  
  if ((param_3 != '\0') &&
     (iVar1 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20800b08,0,0), iVar1 != 0)) {
    nvCheckOkFailedNoLog
              (4,iVar1,
               "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_NVLINK_RC_USER_MODE_CHANNELS, NULL, 0)"
               ,"src/kernel/gpu/nvlink/arch/blackwell/kernel_nvlink_gb100.c",0x20d);
    return iVar1;
  }
  osSchedule1HzCallback(param_1,knvlinkABM_WORKITEM,0,1);
  return 0;
}


// ===== 00410030 knvlinkValidateFabricEgmBaseAddress_GB100 =====

undefined8
knvlinkValidateFabricEgmBaseAddress_GB100(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  if ((param_3 & 0xffff8fffffffffff) == 0) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/arch/blackwell/kernel_nvlink_gb100.c",0x231,
               "knvlinkValidateFabricEgmBaseAddress_GB100",4,
               "NVRM: Invalid EGM fabric address: 0x%llx\n",param_3);
  return 0x1f;
}


// ===== 00410090 knvlinkGetEncryptionBits_GB100 =====

int knvlinkGetEncryptionBits_GB100(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined2 local_1a;
  
  portMemSet(&local_1a,0,2);
  iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x2080308b,&local_1a,2);
  if (iVar1 == 0) {
    *(undefined2 *)(param_2 + 0x1720) = local_1a;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/arch/blackwell/kernel_nvlink_gb100.c",0x250,
               "knvlinkGetEncryptionBits_GB100",4,
               "NVRM: Failed to execute RPC to get Nvlink Encrypt Enable Info\n");
  return iVar1;
}


// ===== 00410130 knvlinkIsNvleEnabled_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1 knvlinkIsNvleEnabled_GB100(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  char local_19 [9];
  
  local_19[0] = *(char *)(param_2 + 0x2f3);
  if (local_19[0] == '\0') goto LAB_00410160;
  if (*(char *)(param_2 + 0x1721) == '\0') {
LAB_004101cf:
    nvDbg_Printf("src/kernel/gpu/nvlink/arch/blackwell/kernel_nvlink_gb100.c",0x27e,
                 "knvlinkIsNvleEnabled_GB100",4,
                 "NVRM: Disabling Nvlink encryption, since, either TLW Encrypt Enable bit is not set OR CC is disabled\n"
                );
    *(undefined1 *)(param_2 + 0x2f3) = 0;
    local_19[0] = '\0';
  }
  else {
    if (*(char *)(param_2 + 0x2f2) == '\0') goto LAB_00410160;
    cVar1 = (**(code **)(param_1 + 0x3b8))();
    if (cVar1 == '\0') {
      cVar1 = (**(code **)(param_1 + 0x390))(param_1);
      if (cVar1 == '\0') goto LAB_004101cf;
    }
    local_19[0] = *(char *)(param_2 + 0x2f3);
  }
LAB_00410160:
  iVar2 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20803092,local_19,1);
  if (iVar2 == 0) {
    return *(undefined1 *)(param_2 + 0x2f3);
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/arch/blackwell/kernel_nvlink_gb100.c",0x28f,
               "knvlinkIsNvleEnabled_GB100",4,
               "NVRM: Failed to execute RPC to set Nvlink Enablement Status\n");
  return 0;
}


// ===== 00410250 knvlinkPostSchedulingEnableCallbackRegister_GB100 =====

void knvlinkPostSchedulingEnableCallbackRegister_GB100(undefined8 param_1)

{
  undefined8 uVar1;
  int iVar2;
  
  uVar1 = gpuGetKernelFifoShared_IMPL();
  iVar2 = kfifoAddSchedulingHandler_IMPL
                    (param_1,uVar1,_knvlinkHandlePostSchedulingEnableCallback_GB100,0,0,0);
  if (iVar2 == 0) {
    return;
  }
  nvAssertOkFailedNoLog
            (iVar2,
             "kfifoAddSchedulingHandler(pGpu, GPU_GET_KERNEL_FIFO(pGpu), _knvlinkHandlePostSchedulingEnableCallback_GB100, NULL, NULL, NULL)"
             ,"src/kernel/gpu/nvlink/arch/blackwell/kernel_nvlink_gb100.c",0x2b5);
  return;
}


// ===== 004102b0 knvlinkPostSchedulingEnableCallbackUnregister_GB100 =====

void knvlinkPostSchedulingEnableCallbackUnregister_GB100(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = gpuGetKernelFifoShared_IMPL();
  kfifoRemoveSchedulingHandler_IMPL
            (param_1,uVar1,_knvlinkHandlePostSchedulingEnableCallback_GB100,0,0,0);
  return;
}


// ===== 004102f0 knvlinkGetSupportedCoreLinkStateMask_GB100 =====

undefined8 knvlinkGetSupportedCoreLinkStateMask_GB100(void)

{
  return 0x1000044b;
}


// ===== 00410300 knvlinkTriggerProbeRequest_GB100 =====

undefined8 knvlinkTriggerProbeRequest_GB100(undefined8 param_1)

{
  osSchedule1HzCallback(param_1,_knvlinkP2PIdleCallback,0,1);
  return 0;
}


// ===== 00410320 knvlinkIsAliSupported_GH100 =====

int knvlinkIsAliSupported_GH100(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined1 local_19;
  
  portMemSet(&local_19,0,1);
  local_19 = 0;
  iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a29,&local_19,1);
  if (iVar1 == 0) {
    *(undefined1 *)(param_2 + 0x15ff) = local_19;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x40,
               "knvlinkIsAliSupported_GH100",4,"NVRM: Failed to get ALI enablement status!\n");
  return iVar1;
}


// ===== 004103c0 knvlinkValidateFabricBaseAddress_GH100 =====

byte knvlinkValidateFabricBaseAddress_GH100(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  return -((param_3 & 0x7fffffffff) != 0) & 0x1f;
}


// ===== 004103e0 knvlinkValidateFabricEgmBaseAddress_GH100 =====

byte knvlinkValidateFabricEgmBaseAddress_GH100(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  return -((param_3 & 0x7fffffffff) != 0) & 0x1f;
}


// ===== 00410400 knvlinkPostSetupNvlinkPeer_GH100 =====

int knvlinkPostSetupNvlinkPeer_GH100(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 local_1c;
  
  portMemSet(&local_1c,0,4);
  local_1c = 0xff;
  iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a50,&local_1c,4);
  if (iVar1 == 0) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0xa5,
               "knvlinkPostSetupNvlinkPeer_GH100",4,
               "NVRM: Failed to program post active settings and bufferready!\n");
  return iVar1;
}


// ===== 004104a0 knvlinkDiscoverPostRxDetLinks_GH100 =====

undefined8 knvlinkDiscoverPostRxDetLinks_GH100(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  
  if (param_3 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0xca,
                 "knvlinkDiscoverPostRxDetLinks_GH100",4,"NVRM: Invalid pPeerGpu.\n");
    return 0x1f;
  }
  if ((param_1 == param_3) && (*(char *)(param_1 + 0x4a6) != '\0')) {
    nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0xd2,
                 "knvlinkDiscoverPostRxDetLinks_GH100",1,
                 "NVRM: loopback P2P on GPU%u disabled by regkey\n",*(undefined4 *)(param_1 + 0x7a4)
                );
  }
  else {
    lVar1 = *(long *)(param_3 + 0x1ce8);
    if (lVar1 == 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0xde,
                   "knvlinkDiscoverPostRxDetLinks_GH100",4,
                   "NVRM: Input mask contains a GPU on which NVLink is disabled.\n");
      return 0x1f;
    }
    lVar2 = *(long *)(param_1 + 0x1ce8);
    if (((((*(char *)(param_1 + 0x4911) == '\0') || (*(char *)(lVar2 + 0x15fc) != '\0')) &&
         (*(long *)(lVar2 + 0x15d0) != 0)) &&
        ((*(char *)(lVar2 + 0x15ff) != '\0' && (*(long *)(lVar1 + 0x15d0) != 0)))) &&
       (*(char *)(lVar1 + 0x15ff) != '\0')) {
      bitVectorClrAll_IMPL(lVar2 + 0x14b0,0x40);
      iVar4 = knvlinkUpdatePostRxDetectLinkMask_IMPL(param_1,lVar2);
      if (iVar4 != 0) {
        nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0xf7,
                     "knvlinkDiscoverPostRxDetLinks_GH100",4,
                     "NVRM: Getting peer0\'s postRxDetLinkMask failed!\n");
        return 0x40;
      }
      if (lVar1 != lVar2) {
        bitVectorClrAll_IMPL(lVar1 + 0x14b0,0x40);
        iVar4 = knvlinkUpdatePostRxDetectLinkMask_IMPL(param_3,lVar1);
        if (iVar4 != 0) {
          nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x103,
                       "knvlinkDiscoverPostRxDetLinks_GH100",4,
                       "NVRM: Getting peer1\'s postRxDetLinkMask failed!\n");
          return 0x40;
        }
      }
      cVar3 = bitVectorTestAllCleared_IMPL(lVar2 + 0x14b0,0x40);
      if ((cVar3 == '\0') &&
         (cVar3 = bitVectorTestAllCleared_IMPL(lVar1 + 0x14b0,0x40), cVar3 == '\0')) {
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x113,
                   "knvlinkDiscoverPostRxDetLinks_GH100",1,
                   "NVRM: Got 0 post RxDet Links on GPU %d or GPU %d!\n",
                   *(undefined4 *)(param_1 + 0x7a4),*(undefined4 *)(param_3 + 0x7a4));
      return 0x55;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0xea,
                 "knvlinkDiscoverPostRxDetLinks_GH100",1,
                 "NVRM: Not in ALI, checking PostRxDetLinks not supported.\n");
  }
  return 0x56;
}


// ===== 004107b0 ioctrlFaultUpTmrHandler =====

int ioctrlFaultUpTmrHandler(long param_1)

{
  long lVar1;
  int iVar2;
  uint *puVar3;
  byte *pbVar4;
  
  lVar1 = *(long *)(param_1 + 0x1ce8);
  puVar3 = (uint *)portMemAllocNonPaged(4);
  pbVar4 = (byte *)listHead_IMPL(lVar1 + 0x390);
  if (puVar3 != (uint *)0x0) {
    *puVar3 = (uint)*pbVar4;
    iVar2 = knvlinkExecGspRmRpc_IMPL(param_1,lVar1,0x20803043,puVar3,4);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x137,
                   "ioctrlFaultUpTmrHandler",4,"NVRM: Failed to send Faultup RPC\n");
    }
    listRemove_IMPL(lVar1 + 0x390,pbVar4);
    portMemFree(puVar3);
    return iVar2;
  }
  nvAssertFailedNoLog("nvlinkPostFaultUpParams != NULL",
                      "src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x12d);
  return 0x51;
}


// ===== 004108b0 knvlinkHandleFaultUpInterrupt_GH100 =====

undefined8 knvlinkHandleFaultUpInterrupt_GH100(long param_1,long param_2,ulong param_3)

{
  undefined1 *puVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(param_1 + 0x1b88);
  param_3 = param_3 & 0xffffffff;
  puVar1 = (undefined1 *)listAppendNew_IMPL(param_2 + 0x390);
  if (puVar1 == (undefined1 *)0x0) {
    nvAssertFailedNoLog("pFaultLink != NULL",
                        "src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x14d);
  }
  else {
    *puVar1 = (char)param_3;
    uVar2 = tmrEventScheduleRel_IMPL
                      (uVar2,*(undefined8 *)(param_2 + 0x438 + param_3 * 0x78),10000000000);
    if ((int)uVar2 == 0) {
      return uVar2;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x153,
                 "knvlinkHandleFaultUpInterrupt_GH100",4,
                 "NVRM: GPU (ID: %d) tmrEventScheduleRel failed for linkid %d\n",
                 *(undefined4 *)(param_1 + 0x7a4),param_3);
  }
  return 0xffff;
}


// ===== 00410990 knvlinkLogAliDebugMessages_GH100 =====

int knvlinkLogAliDebugMessages_GH100(long param_1,long param_2,char param_3)

{
  long lVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  int local_4c;
  undefined1 local_40 [16];
  
  local_4c = 0;
  if (param_3 == '\0') {
    lVar5 = portMemAllocNonPaged(0x1c38);
    if (lVar5 != 0) {
      portMemSet(lVar5,0,0x1c38);
      *(byte *)(lVar5 + 0x1c34) = *(byte *)(lVar5 + 0x1c34) | 2;
      iVar3 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20803003,lVar5,0x1c38);
      if (iVar3 == 0) {
        bitVectorCopy_IMPL(local_40,0x40,param_2 + 0x14b0,0x40);
        uVar4 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
        while( true ) {
          uVar6 = (ulong)uVar4;
          cVar2 = bitVectorTestAllCleared_IMPL(local_40,0x40);
          if (cVar2 != '\0') break;
          lVar1 = lVar5 + uVar6 * 0x70;
          nvErrorLog_va(param_1,0x88,
                        "NVLink: Link training failed for link %u(0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x)"
                        ,uVar6,*(undefined4 *)(lVar1 + 0x60),*(undefined4 *)(lVar1 + 0x6c),
                        *(undefined4 *)(lVar1 + 0x70),*(undefined4 *)(lVar1 + 0x74),
                        *(undefined4 *)(lVar1 + 0x78),*(undefined4 *)(lVar1 + 0x7c),
                        *(undefined4 *)(lVar1 + 0x80));
          if (*(char *)(param_2 + 0x1608) != '\0') {
            nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x18c,
                         "knvlinkLogAliDebugMessages_GH100",4,
                         "NVRM: ALI Error for GPU %d::linkId %d:\nNVLIPT:\n\tCTRL_LINK_STATE_REQUEST_STATUS = %X\n\nNVLDL :\n\tNV_NVLDL_RXSLSM_ERR_CNTL = %X\n\n\tNV_NVLDL_TOP_LINK_STATE = %X\n\n\tNV_NVLDL_TOP_INTR = %X\n\nMINION DLSTAT:\n\tDLSTAT MN00 = %X\n\n\tDLSTAT UC01 = %X\n\n\tNV_MINION_NVLINK_LINK_INTR = %X\n"
                         ,*(undefined4 *)(param_1 + 0x7a4),uVar6,*(undefined4 *)(lVar1 + 0x60),
                         *(undefined4 *)(lVar1 + 0x6c),*(undefined4 *)(lVar1 + 0x70),
                         *(undefined4 *)(lVar1 + 0x74),*(undefined4 *)(lVar1 + 0x78),
                         *(undefined4 *)(lVar1 + 0x7c),*(undefined4 *)(lVar1 + 0x80));
          }
          bitVectorClr_IMPL(local_40,0x40,uVar6);
          uVar4 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
        }
        portMemFree(lVar5);
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x178,
                   "knvlinkLogAliDebugMessages_GH100",4,
                   "NVRM: Error getting debug info for link training!\n");
      portMemFree(lVar5);
      return iVar3;
    }
    nvAssertFailedNoLog("nvlinkErrInfoParams != NULL",
                        "src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x16d);
    local_4c = 0x51;
  }
  return local_4c;
}


// ===== 00410be0 knvlinkIsBandwidthModeOff_GH100 =====

bool knvlinkIsBandwidthModeOff_GH100(void)

{
  short sVar1;
  
  sVar1 = gpumgrGetGpuNvlinkBwMode_IMPL();
  return sVar1 == 1;
}


// ===== 00410c00 knvlinkGetNumLinksToBeReducedPerIoctrl_GH100 =====

uint knvlinkGetNumLinksToBeReducedPerIoctrl_GH100(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = knvlinkGetNumActiveLinksPerIoctrl_IMPL();
  uVar3 = 0;
  if (uVar2 != 0) {
    bVar1 = gpumgrGetGpuNvlinkBwMode_IMPL();
    if (bVar1 == 3) {
      uVar3 = uVar2 >> 1;
    }
    else {
      if ((bVar1 & 0xfc) == 0) {
        if (bVar1 == 1) {
          nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x1ca,
                       "knvlinkGetNumLinksToBeReducedPerIoctrl_GH100",4,
                       "NVRM: Cannot reach here %s %d mode=%d\n",
                       "knvlinkGetNumLinksToBeReducedPerIoctrl_GH100",0x1ca,1);
          nvAssertFailedNoLog(&DAT_00d6b0bf,
                              "src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x1cc);
          return uVar2;
        }
        if (bVar1 == 2) {
          return uVar2 - 1;
        }
      }
      else if (bVar1 == 4) {
        return uVar2 >> 2;
      }
      uVar3 = 0;
    }
  }
  return uVar3;
}


// ===== 00410cd0 knvlinkGetEffectivePeerLinkMask_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void knvlinkGetEffectivePeerLinkMask_GH100
               (long param_1,long param_2,long param_3,undefined8 param_4)

{
  ulong uVar1;
  long lVar2;
  char cVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  ulong uVar9;
  char *pcVar10;
  ulong uVar11;
  undefined4 *puVar12;
  undefined8 uVar13;
  uint uVar14;
  uint uVar15;
  byte bVar16;
  int iVar17;
  undefined4 local_4c;
  undefined1 local_48 [8];
  undefined1 local_40 [16];
  
  uVar15 = *(uint *)(param_3 + 0x7a4);
  uVar5 = *(uint *)(param_1 + 0x7a4);
  cVar3 = knvlinkIsGpuConnectedToNvswitch_IMPL();
  if (cVar3 != '\0') {
    iVar6 = gpuFabricProbeGetlinkMaskToBeReduced(*(undefined8 *)(param_1 + 0x4c0),&local_4c);
    if (iVar6 != 0) {
      return;
    }
    iVar6 = convertMaskToBitVector(local_4c,local_48);
    if (iVar6 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar6,"convertMaskToBitVector(linkMaskToBeReduced, &linkMaskToBeReducedVec)",
                 "src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x205);
      return;
    }
    iVar6 = bitVectorComplement_IMPL(local_40,0x40,local_48,0x40);
    if (iVar6 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar6,
                 "bitVectorComplement(&complementLinkMaskToBeReducedVec, &linkMaskToBeReducedVec)",
                 "src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x208);
      return;
    }
    iVar6 = bitVectorAnd_IMPL(param_4,0x40,param_4,0x40,local_40,0x40);
    if (iVar6 == 0) {
      return;
    }
    nvCheckOkFailedNoLog
              (4,iVar6,
               "bitVectorAnd(pPeerLinkMask, pPeerLinkMask, &complementLinkMaskToBeReducedVec)",
               "src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x20b);
    return;
  }
  uVar1 = *(ulong *)(param_2 + 0x14c8 + (ulong)uVar15 * 8);
  uVar15 = (uint)uVar1;
  if (uVar15 == 0) {
    return;
  }
  lVar2 = *(long *)(param_3 + 0x1ce8);
  uVar11 = *(ulong *)(lVar2 + 0x14c8 + (ulong)uVar5 * 8);
  uVar14 = (uint)uVar11;
  uVar5 = uVar14 - ((uint)(uVar11 >> 1) & 0x55555555);
  uVar8 = (uVar5 & 0x33333333) + (uVar5 >> 2 & 0x33333333);
  uVar5 = uVar15 - ((uint)(uVar1 >> 1) & 0x55555555);
  uVar5 = (uVar5 >> 2 & 0x33333333) + (uVar5 & 0x33333333);
  if (((uVar5 >> 4) + uVar5 & 0xf0f0f0f) * 0x1010101 >> 0x18 !=
      ((uVar8 >> 4) + uVar8 & 0xf0f0f0f) * 0x1010101 >> 0x18) {
    nvAssertFailedNoLog("nvPopCount32(remotePeerLinkMask) == nvPopCount32(peerLinkMask)",
                        "src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x220);
  }
  iVar6 = (**(code **)(param_2 + 0x250))(param_1,param_2);
  if (iVar6 == 0) {
    return;
  }
  uVar5 = *(uint *)(param_2 + 0x310) - (*(uint *)(param_2 + 0x310) >> 1 & 0x55555555);
  uVar5 = (uVar5 >> 2 & 0x33333333) + (uVar5 & 0x33333333);
  uVar5 = ((uVar5 >> 4) + uVar5 & 0xf0f0f0f) * 0x1010101 >> 0x18;
  bVar4 = knvlinkGetTotalNumLinksPerIoctrl_IMPL(param_1,param_2);
  if (*(uint *)(param_1 + 0x7ac) < *(uint *)(param_3 + 0x7ac)) {
    if (uVar5 != 0) {
      uVar11 = uVar1 & 0xffffffff;
      bVar16 = 0;
      uVar14 = 0;
      do {
        uVar8 = (1 << (bVar4 & 0x1f)) + -1 << (bVar16 & 0x1f) & uVar15;
        uVar9 = (ulong)uVar8;
        if (uVar8 != 0) {
          iVar17 = 0;
          bVar7 = 0;
          do {
            if ((uVar9 & 1) != 0) {
              do {
                if (iVar6 == iVar17) goto LAB_00410fd8;
                uVar11 = (ulong)((uint)uVar11 & ~(1 << (bVar7 & 0x1f)));
                uVar8 = (uint)uVar9 >> 1;
                uVar9 = (ulong)uVar8;
                if (uVar8 == 0) goto LAB_00410fd8;
                iVar17 = iVar17 + 1;
                bVar7 = bVar7 + 1;
              } while ((uVar8 & 1) != 0);
            }
            bVar7 = bVar7 + 1;
            uVar9 = uVar9 >> 1;
          } while( true );
        }
LAB_00410fd8:
        uVar14 = uVar14 + 1;
        bVar16 = bVar16 + bVar4;
        uVar8 = (uint)uVar11;
      } while (uVar14 != uVar5);
LAB_00410fe8:
      uVar15 = uVar8;
      if (uVar15 == 0) {
        iVar6 = convertMaskToBitVector(uVar1 & 0xffffffff,param_4);
        if (iVar6 == 0) {
          return;
        }
        uVar13 = 0x273;
        pcVar10 = "convertMaskToBitVector(peerLinkMask, pPeerLinkMask)";
        goto LAB_00411013;
      }
    }
  }
  else if (uVar5 != 0) {
    uVar11 = uVar1 & 0xffffffff;
    bVar16 = 0;
    uVar15 = 0;
    do {
      uVar8 = (1 << (bVar4 & 0x1f)) + -1 << (bVar16 & 0x1f) & uVar14;
      uVar9 = (ulong)uVar8;
      if (uVar8 != 0) {
        puVar12 = (undefined4 *)(lVar2 + 0x3f8);
        iVar17 = 0;
        do {
          if ((uVar9 & 1) != 0) {
            do {
              if (iVar6 == iVar17) goto LAB_00411033;
              uVar11 = (ulong)((uint)uVar11 & ~(1 << ((byte)*puVar12 & 0x1f)));
              uVar8 = (uint)uVar9 >> 1;
              uVar9 = (ulong)uVar8;
              if (uVar8 == 0) goto LAB_00411033;
              iVar17 = iVar17 + 1;
              puVar12 = puVar12 + 0x1e;
            } while ((uVar8 & 1) != 0);
          }
          uVar9 = uVar9 >> 1;
          puVar12 = puVar12 + 0x1e;
        } while( true );
      }
LAB_00411033:
      uVar15 = uVar15 + 1;
      bVar16 = bVar16 + bVar4;
      uVar8 = (uint)uVar11;
    } while (uVar15 != uVar5);
    goto LAB_00410fe8;
  }
  iVar6 = convertMaskToBitVector(uVar15,param_4);
  uVar13 = 0x26d;
  pcVar10 = "convertMaskToBitVector(effectivePeerLinkMask, pPeerLinkMask)";
  if (iVar6 == 0) {
    return;
  }
LAB_00411013:
  nvCheckOkFailedNoLog
            (4,iVar6,pcVar10,"src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",uVar13);
  return;
}


// ===== 004110e0 knvlinkIsBwModeSupported_GH100 =====

undefined8 knvlinkIsBwModeSupported_GH100(undefined8 param_1,undefined8 param_2,byte param_3)

{
  char cVar1;
  
  if (4 < (param_3 & 7)) {
    return 0;
  }
  cVar1 = gpuFabricProbeIsSupported();
  if ((cVar1 != '\0') && ((param_3 & 5) != 0)) {
    nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x298,
                 "knvlinkIsBwModeSupported_GH100",4,
                 "NVRM: BW mode requested is not supported. Mode: %d\n",param_3 & 7);
    return 0;
  }
  return 1;
}


// ===== 00411160 knvlinkGetSupportedBwMode_GH100 =====

undefined8 knvlinkGetSupportedBwMode_GH100(long param_1,undefined8 param_2,undefined8 *param_3)

{
  if (*(char *)(param_1 + 0x4a4c) != '\0') {
    *(undefined4 *)param_3 = 0x20000;
    *(undefined1 *)((long)param_3 + 0x2e) = 2;
    return 0;
  }
  *param_3 = 0x3000200010000;
  *(undefined2 *)(param_3 + 1) = 4;
  *(undefined1 *)((long)param_3 + 0x2e) = 5;
  return 0;
}


// ===== 004111b0 knvlinkSetUniqueFabricBaseAddress_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int knvlinkSetUniqueFabricBaseAddress_GH100(long param_1,long param_2,long param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_2 + 0x1a0))();
  if (iVar1 != 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x2e4,
                 "knvlinkSetUniqueFabricBaseAddress_GH100",4,
                 "NVRM: Fabric addr validation failed for GPU %x\n",*(undefined4 *)(param_1 + 0x7a4)
                );
    return iVar1;
  }
  if (*(long *)(param_2 + 0x16a8) == param_3) {
    nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x2f3,
                 "knvlinkSetUniqueFabricBaseAddress_GH100",1,
                 "NVRM: The same fabric addr is being re-assigned to GPU %x\n",
                 *(undefined4 *)(param_1 + 0x7a4));
  }
  else {
    if (*(long *)(param_2 + 0x16a8) != -1) {
      nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x2fb,
                   "knvlinkSetUniqueFabricBaseAddress_GH100",4,
                   "NVRM: Fabric addr is already assigned to GPU %x\n",
                   *(undefined4 *)(param_1 + 0x7a4));
      return 99;
    }
    *(long *)(param_2 + 0x16a8) = param_3;
    nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x302,
                 "knvlinkSetUniqueFabricBaseAddress_GH100",1,
                 "NVRM: Fabric base addr %llx is assigned to GPU %x\n",param_3,
                 *(undefined4 *)(param_1 + 0x7a4));
  }
  return 0;
}


// ===== 00411310 knvlinkClearUniqueFabricBaseAddress_GH100 =====

void knvlinkClearUniqueFabricBaseAddress_GH100(undefined8 param_1,long param_2)

{
  *(undefined8 *)(param_2 + 0x16a8) = 0xffffffffffffffff;
  return;
}


// ===== 00411320 knvlinkSetUniqueFabricEgmBaseAddress_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int knvlinkSetUniqueFabricEgmBaseAddress_GH100(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  if (*(char *)(*(long *)(param_1 + 0x1b78) + 0x454) == '\0') {
    nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x32f,
                 "knvlinkSetUniqueFabricEgmBaseAddress_GH100",4,
                 "NVRM: EGM is not enabled in RM for GPU %x\n",*(undefined4 *)(param_1 + 0x7a4));
    return 0x40;
  }
  iVar2 = (**(code **)(param_2 + 0x1a8))();
  if (iVar2 == 0) {
    if (*(long *)(param_2 + 0x16b0) != param_3) {
      if (*(long *)(param_2 + 0x16b0) == -1) {
        *(long *)(param_2 + 0x16b0) = param_3;
        nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x356,
                     "knvlinkSetUniqueFabricEgmBaseAddress_GH100",1,
                     "NVRM: EGM Fabric base addr %llx is assigned to GPU %x\n",param_3,
                     *(undefined4 *)(param_1 + 0x7a4));
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x34f,
                   "knvlinkSetUniqueFabricEgmBaseAddress_GH100",4,
                   "NVRM: EGM Fabric base addr is already assigned to GPU %x\n",
                   *(undefined4 *)(param_1 + 0x7a4));
      return 99;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x7a4);
    pcVar5 = "NVRM: The same EGM fabric base addr is being re-assigned to GPU %x\n";
    uVar3 = 1;
    uVar4 = 0x347;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x7a4);
    pcVar5 = "NVRM: EGM Fabric base addr validation failed for GPU %x\n";
    uVar3 = 4;
    uVar4 = 0x338;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",uVar4,
               "knvlinkSetUniqueFabricEgmBaseAddress_GH100",uVar3,pcVar5,uVar1);
  return iVar2;
}


// ===== 004114f0 knvlinkClearUniqueFabricEgmBaseAddress_GH100 =====

void knvlinkClearUniqueFabricEgmBaseAddress_GH100(undefined8 param_1,long param_2)

{
  *(undefined8 *)(param_2 + 0x16b0) = 0xffffffffffffffff;
  return;
}


// ===== 00411500 knvlinkDirectConnectCheck_GH100 =====

void knvlinkDirectConnectCheck_GH100(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 local_14;
  undefined4 local_c;
  
  local_14 = 0;
  local_c = 0;
  iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20803042,&local_14,0xc);
  if (iVar1 == 0) {
    return;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/arch/hopper/kernel_nvlink_gh100.c",0x382,
               "knvlinkDirectConnectCheck_GH100",4,
               "NVRM: Fail to call direct conect check command\n");
  return;
}


// ===== 00411560 knvlinkIsFloorSweepingNeeded_GH100 =====

bool knvlinkIsFloorSweepingNeeded_GH100(long param_1,long param_2,uint param_3,uint param_4)

{
  bool bVar1;
  
  if (((param_3 != 0) && (param_3 < param_4)) && (*(char *)(param_2 + 0x1600) == '\0')) {
    bVar1 = false;
    if (*(char *)(param_1 + 0x446) == '\0') {
      bVar1 = *(char *)(param_1 + 0x490e) == '\0';
    }
    return bVar1;
  }
  return false;
}


// ===== 004115a0 knvlinkGetUniquePeerIdMask_GP100 =====

uint knvlinkGetUniquePeerIdMask_GP100(undefined8 param_1,long param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  uint uVar3;
  
  puVar2 = (undefined8 *)(param_2 + 0x14c8);
  uVar3 = 0;
  do {
    uVar1 = (uint)*puVar2;
    if (uVar1 != 0) {
      uVar3 = -uVar1 & uVar1 | uVar3;
    }
    puVar2 = puVar2 + 1;
  } while ((undefined8 *)(param_2 + 0x15c8) != puVar2);
  return uVar3;
}


// ===== 004115e0 knvlinkGetUniquePeerId_GP100 =====

uint knvlinkGetUniquePeerId_GP100(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0xffffffff;
  uVar2 = (uint)*(undefined8 *)(param_2 + 0x14c8 + (ulong)*(uint *)(param_3 + 0x7a4) * 8);
  if (uVar2 != 0) {
    uVar2 = -uVar2 & uVar2;
    uVar1 = (uint)((uVar2 & 0xaaaaaaaa) != 0) | (uint)(0xffff < uVar2) << 4 |
            (uint)((uVar2 & 0xff00ff00) != 0) << 3 | (uint)((uVar2 & 0xf0f0f0f0) != 0) << 2 |
            (uint)((uVar2 & 0xcccccccc) != 0) * 2;
  }
  return uVar1;
}


// ===== 00411650 knvlinkRemoveMapping_GP100 =====

void knvlinkRemoveMapping_GP100
               (undefined8 param_1,undefined8 param_2,char param_3,undefined4 param_4,
               undefined1 param_5)

{
  int local_44;
  undefined4 local_40;
  undefined1 local_3c;
  
  portMemSet(&local_44,0,0xc);
  local_44 = 3 - (uint)(param_3 == '\0');
  if (param_3 != '\0') {
    param_4 = 0xff;
  }
  local_40 = param_4;
  local_3c = param_5;
  knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a5f,&local_44,0xc);
  return;
}


// ===== 004116d0 knvlinkGetP2POptimalCEs_GP100 =====

int knvlinkGetP2POptimalCEs_GP100
              (undefined8 param_1,undefined8 param_2,undefined4 param_3,int *param_4,int *param_5,
              undefined4 *param_6,undefined4 *param_7)

{
  int iVar1;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  
  local_30 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  iVar1 = kceFindFirstInstance_IMPL(param_1,&local_30);
  if (iVar1 == 0) {
    kceGetCeFromNvlinkConfig_IMPL(param_1,local_30,param_3,&local_3c,&local_38,&local_34);
    if (param_4 != (int *)0x0) {
      *param_4 = 1 << ((byte)local_3c & 0x1f);
    }
    if (param_5 != (int *)0x0) {
      *param_5 = 1 << ((byte)local_38 & 0x1f);
    }
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = local_34;
    }
    if (param_7 != (undefined4 *)0x0) {
      *param_7 = local_34;
    }
    return 0;
  }
  nvCheckOkFailedNoLog
            (4,iVar1,"kceFindFirstInstance(pGpu, &pKCe)",
             "src/kernel/gpu/nvlink/arch/pascal/kernel_nvlink_gp100.c",0xd5);
  return iVar1;
}


// ===== 004117c0 knvlinkSetupPeerMapping_GP100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong knvlinkSetupPeerMapping_GP100(long param_1,long param_2,long param_3,uint param_4)

{
  int iVar1;
  ulong uVar2;
  int local_4c;
  undefined1 local_48 [8];
  uint local_40 [2];
  undefined1 local_38 [8];
  undefined1 local_30;
  undefined1 local_2f;
  
  uVar2 = knvlinkIsForcedConfig_IMPL();
  if ((char)uVar2 == '\0') {
    if ((param_1 == param_3) && (*(char *)(param_1 + 0x4a6) != '\0')) {
      nvDbg_Printf("src/kernel/gpu/nvlink/arch/pascal/kernel_nvlink_gp100.c",0x112,
                   "knvlinkSetupPeerMapping_GP100",4,
                   "NVRM: P2P loopback is disabled on GPU%u, aborting peer setup (0x%x)\n",
                   *(undefined4 *)(param_1 + 0x7a4));
      uVar2 = (ulong)param_4;
    }
    else {
      iVar1 = convertMaskToBitVector
                        (*(undefined8 *)(param_2 + 0x14c8 + (ulong)*(uint *)(param_3 + 0x7a4) * 8),
                         local_48);
      if (iVar1 == 0) {
        (**(code **)(param_2 + 0x248))(param_1,param_2,param_3,local_48);
        uVar2 = bitVectorTestAllCleared_IMPL(local_48,0x40);
        if ((char)uVar2 == '\0') {
          portMemSet(local_40,0,0x18);
          local_40[0] = param_4;
          iVar1 = convertBitVectorToLinkMasks(local_48,local_38,8,0);
          if (iVar1 == 0) {
            local_30 = *(undefined1 *)(*(long *)(&DAT_00001b90 + param_1) + 0xaa34 + (ulong)param_4)
            ;
            local_2f = knvlinkIsGpuConnectedToNvswitch_IMPL(param_1,param_2);
            iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a4e,local_40,0x18);
            if (iVar1 != 0) {
              nvAssertFailedNoLog("status == NV_OK",
                                  "src/kernel/gpu/nvlink/arch/pascal/kernel_nvlink_gp100.c",300);
            }
            knvlinkUpdateCurrentConfig_IMPL(param_1,param_2);
            portMemSet(&local_4c,0,4);
            local_4c = 1 << ((byte)param_4 & 0x1f);
            uVar2 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a50,&local_4c,4);
            if ((int)uVar2 != 0) {
              uVar2 = nvAssertFailedNoLog("status == NV_OK",
                                          "src/kernel/gpu/nvlink/arch/pascal/kernel_nvlink_gp100.c",
                                          0x138);
            }
          }
          else {
            uVar2 = nvCheckOkFailedNoLog
                              (4,iVar1,
                               "convertBitVectorToLinkMasks(&peerLinkMaskVec, &preSetupNvlinkPeerParams.peerLinkMask, sizeof(preSetupNvlinkPeerParams.peerLinkMask), NULL)"
                               ,"src/kernel/gpu/nvlink/arch/pascal/kernel_nvlink_gp100.c",0x122);
          }
        }
      }
      else {
        uVar2 = nvCheckOkFailedNoLog
                          (4,iVar1,"convertMaskToBitVector(peerLinkMask, &peerLinkMaskVec)",
                           "src/kernel/gpu/nvlink/arch/pascal/kernel_nvlink_gp100.c",0x119);
      }
    }
  }
  return uVar2;
}


// ===== 004119e0 knvlinkCoreGetDevicePciInfo_GP100 =====

void knvlinkCoreGetDevicePciInfo_GP100(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  *(short *)(param_3 + 2) = (short)*(undefined4 *)(param_1 + 0x87c);
  *(char *)(param_3 + 4) = (char)((ulong)*(undefined8 *)(param_1 + 0x878) >> 8);
  uVar1 = *(undefined8 *)(param_1 + 0x878);
  *(undefined1 *)(param_3 + 6) = 0;
  *(char *)(param_3 + 5) = (char)uVar1;
  return;
}


// ===== 00411a10 knvlinkGetSupportedCoreLinkStateMask_GP100 =====

undefined8 knvlinkGetSupportedCoreLinkStateMask_GP100(void)

{
  return 0xffffffff;
}


// ===== 00411a20 knvlinkFilterBridgeLinks_TU102 =====

void knvlinkFilterBridgeLinks_TU102(long param_1,long param_2)

{
  int iVar1;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  undefined8 extraout_RDX_02;
  undefined8 extraout_RDX_03;
  uint uVar2;
  uint uVar3;
  long *plVar4;
  undefined8 uStack_60;
  uint local_40 [4];
  
  bitVectorCopy_IMPL(param_2 + 0x378,0x40,param_2 + 0x350,0x40);
  if (*(char *)(param_2 + 0x339) == '\0') {
    iVar1 = bitVectorGetSlice_IMPL(param_2 + 0x350,0x40,0,0x3f,local_40);
    if (iVar1 == 0) {
      uStack_60 = extraout_RDX;
      if (local_40[0] != 0) {
        plVar4 = (long *)(param_2 + 0x3c8);
        iVar1 = 0;
        uVar2 = local_40[0];
        while( true ) {
          for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1) {
            iVar1 = iVar1 + 1;
            plVar4 = plVar4 + 0xf;
          }
          uVar3 = 1 << ((byte)iVar1 & 0x1f);
          if (*plVar4 == 0) {
            uStack_60 = 0x411bd5;
            bitVectorClr_IMPL(param_2 + 0x370,0x40,iVar1);
            *(uint *)(param_2 + 0x380) = *(uint *)(param_2 + 0x380) & ~uVar3;
            nvDbg_Printf("src/kernel/gpu/nvlink/arch/turing/kernel_nvlink_tu102.c",0x4e,
                         "knvlinkFilterBridgeLinks_TU102",1,
                         "NVRM: GPU%d: Link%d not yet registered in core lib. Connectivity will be established after RXDET\n"
                         ,*(undefined4 *)(param_1 + 0x7a4),iVar1);
          }
          else if (*(char *)(*plVar4 + 0x58) == '\0') {
            bitVectorClr_IMPL(param_2 + 0x370,0x40,iVar1);
            *(uint *)(param_2 + 0x380) = *(uint *)(param_2 + 0x380) & ~uVar3;
            uStack_60 = extraout_RDX_01;
          }
          else {
            bitVectorSet_IMPL();
            *(uint *)(param_2 + 0x380) = *(uint *)(param_2 + 0x380) | uVar3;
            uStack_60 = extraout_RDX_00;
          }
          if (uVar2 >> 1 == 0) break;
          iVar1 = iVar1 + 1;
          plVar4 = plVar4 + 0xf;
          uVar2 = uVar2 >> 1;
        }
      }
    }
    else {
      nvAssertFailedNoLog("(bitVectorGetSlice(pSrc, rangeMake(0, 63), &localMask) == NV_OK)",
                          "generated/g_kernel_nvlink_nvoc.h",0x8fd);
      uStack_60 = extraout_RDX_03;
    }
  }
  else {
    bitVectorCopy_IMPL(param_2 + 0x370,0x40,param_2 + 0x388,0x40);
    iVar1 = bitVectorGetSlice_IMPL(param_2 + 0x388,0x40,0,0x3f,local_40);
    if (iVar1 != 0) {
      nvAssertFailedNoLog("(bitVectorGetSlice(pSrc, rangeMake(0, 63), &localMask) == NV_OK)",
                          "generated/g_kernel_nvlink_nvoc.h",0x8fd);
      local_40[0] = 0;
    }
    *(uint *)(param_2 + 0x380) = local_40[0];
    nvDbg_Printf("src/kernel/gpu/nvlink/arch/turing/kernel_nvlink_tu102.c",0x3b,
                 "knvlinkFilterBridgeLinks_TU102",1,
                 "NVRM: Connections forced through chiplib. ConnectedLinksMask same as enabledLinks = 0x%llx\n"
                 ,*(undefined8 *)(param_2 + 0x370));
    uStack_60 = extraout_RDX_02;
  }
  knvlinkSyncLinkMasksAndVbiosInfo_IMPL(param_1,param_2,uStack_60);
  return;
}


// ===== 00411c70 knvlinkGetConnectedLinksMask_TU102 =====

long knvlinkGetConnectedLinksMask_TU102(undefined8 param_1,long param_2)

{
  return param_2 + 0x370;
}


// ===== 00411c80 knvlinkPoweredUpForD3_TU102 =====

bool knvlinkPoweredUpForD3_TU102(long param_1,long param_2)

{
  bool bVar1;
  
  if (((*(char *)(param_1 + 0x488) != '\0') || (bVar1 = false, *(char *)(param_1 + 0x48e) != '\0'))
     && (bVar1 = false, *(char *)(param_2 + 0x2e1) != '\0')) {
    bVar1 = *(char *)(param_2 + 0x2e8) == '\0';
  }
  return bVar1;
}


// ===== 00411cb0 kioctrlMinionConstruct_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kioctrlMinionConstruct_GV100(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint local_2c;
  
  if (*(char *)(param_2 + 0x178) != '\0') {
    lVar1 = *(long *)(param_1 + 0x1ce8);
    cVar2 = (**(code **)(param_2 + 0x168))();
    if (cVar2 == '\0') {
      nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_minion_gv100.c",0x38,
                   "kioctrlMinionConstruct_GV100",1,
                   "NVRM: NVLink MINION is not supported on this platform, disabling.\n");
    }
    local_2c = *(uint *)(lVar1 + 0x324);
    iVar3 = osReadRegistryDword(param_1,"RMNvLinkMinionControl",&local_2c);
    if (iVar3 == 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_minion_gv100.c",0x42,
                   "kioctrlMinionConstruct_GV100",1,"NVRM: %s: 0x%x\n","RMNvLinkMinionControl",
                   local_2c);
      if ((local_2c & 0xf) == 1) {
        cVar2 = '\x01';
        nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_minion_gv100.c",0x49,
                     "kioctrlMinionConstruct_GV100",1,
                     "NVRM: NVLink MINION force enable requested by command line override.\n");
        *(undefined1 *)(param_2 + 0x179) = 1;
      }
      else if ((local_2c & 0xf) == 2) {
        cVar2 = '\0';
        nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_minion_gv100.c",0x4f,
                     "kioctrlMinionConstruct_GV100",1,
                     "NVRM: NVLink MINION force disable requested by command line override.\n");
      }
      uVar4 = local_2c >> 0x14 & 0xf;
      if (uVar4 == 1) {
        nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_minion_gv100.c",0x5b,
                     "kioctrlMinionConstruct_GV100",1,
                     "NVRM: Regkey: Minion seed caching is force enabled\n");
        *(undefined1 *)(param_2 + 0x17a) = 1;
      }
      else if (uVar4 == 2) {
        nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_minion_gv100.c",0x62,
                     "kioctrlMinionConstruct_GV100",1,
                     "NVRM: Regkey: Minion seed caching is force disabled\n");
        *(undefined1 *)(param_2 + 0x17a) = 0;
      }
      uVar4 = local_2c >> 0x1c & 7;
      if (uVar4 == 1) {
        nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_minion_gv100.c",0x6d,
                     "kioctrlMinionConstruct_GV100",1,
                     "NVRM: Regkey: ALI training is force enabled\n");
        *(undefined2 *)(lVar1 + 0x2eb) = 1;
      }
      else if (uVar4 == 2) {
        nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_minion_gv100.c",0x75,
                     "kioctrlMinionConstruct_GV100",1,
                     "NVRM: Regkey: non-ALI training is force enabled\n");
        *(undefined2 *)(lVar1 + 0x2eb) = 0x100;
      }
      else {
        *(undefined2 *)(lVar1 + 0x2eb) = 0;
      }
      if ((int)local_2c < 0) {
        nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_minion_gv100.c",0x87,
                     "kioctrlMinionConstruct_GV100",1,
                     "NVRM: Regkey: Minion boot from GFW disabled\n");
        *(undefined1 *)(lVar1 + 0x2ed) = 0;
      }
      else if (*(char *)(lVar1 + 0x2ed) == '\0') {
        nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_minion_gv100.c",0x95,
                     "kioctrlMinionConstruct_GV100",1,
                     "NVRM: Regkey: Minion boot from GFW disabled by default\n");
      }
      else {
        nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_minion_gv100.c",0x90,
                     "kioctrlMinionConstruct_GV100",1,
                     "NVRM: Regkey: Minion boot from GFW enabled by default\n");
      }
    }
    *(char *)(param_2 + 0x178) = cVar2;
    return 0;
  }
  return 0;
}


// ===== 00412000 kioctrlGetMinionEnableDefault_GV100 =====

bool kioctrlGetMinionEnableDefault_GV100(long param_1)

{
  return *(char *)(param_1 + 0x4911) == '\0';
}


// ===== 00412010 knvlinkConstructHal_GV100 =====

undefined8 knvlinkConstructHal_GV100(long param_1,long param_2)

{
  if ((*(char *)(param_1 + 0x4910) != '\0') || (*(char *)(param_1 + 0x446) != '\0')) {
    *(undefined1 *)(param_2 + 0x15f8) = 1;
  }
  return 0;
}


// ===== 00412030 knvlinkEnableLinksPostTopology_GV100 =====

int knvlinkEnableLinksPostTopology_GV100(long param_1,long param_2,uint param_3)

{
  int iVar1;
  uint local_20;
  uint local_1c;
  
  iVar1 = 0;
  if ((~*(uint *)(param_2 + 0x3b8) & param_3) != 0) {
    portMemSet(&local_20,0,8);
    local_20 = param_3;
    if (*(char *)(param_1 + 0x909) != '\0') {
      threadStateResetTimeout(param_1);
    }
    iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a83,&local_20,8);
    if (iVar1 == 0) {
      *(ulong *)(param_2 + 0x3b8) = (ulong)local_1c;
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_nvlink_gv100.c",0x6f,
                 "knvlinkEnableLinksPostTopology_GV100",4,
                 "NVRM: Failed to enable Links post topology!\n");
  }
  return iVar1;
}


// ===== 00412140 knvlinkOverrideConfig_GV100 =====

int knvlinkOverrideConfig_GV100(undefined8 param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined1 local_120;
  undefined1 local_11f;
  undefined1 local_118 [256];
  
  lVar3 = portMemAllocNonPaged((ulong)*(uint *)(param_2 + 0x3c0) << 2);
  *(long *)(param_2 + 0x330) = lVar3;
  if (lVar3 == 0) {
    return 0x51;
  }
  portMemSet(lVar3,0,(ulong)*(uint *)(param_2 + 0x3c0) << 2);
  uVar1 = 0;
  if (*(int *)(param_2 + 0x3c0) != 0) {
    lVar3 = 0;
    do {
      *(uint *)(*(long *)(param_2 + 0x330) + lVar3 * 4) = ((uint)lVar3 & 0x3f) << 0x10;
      uVar1 = *(uint *)(param_2 + 0x3c0);
      lVar3 = lVar3 + 1;
    } while ((uint)lVar3 < uVar1);
  }
  iVar2 = osGetForcedNVLinkConnection(param_1,uVar1,*(undefined8 *)(param_2 + 0x330));
  if (iVar2 == 0) {
    portMemSet(&local_120,0,0x108);
    local_120 = 0;
    lVar3 = (ulong)*(uint *)(param_2 + 0x3c0) << 2;
    portMemCopy(local_118,lVar3,*(undefined8 *)(param_2 + 0x330),lVar3);
    iVar2 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a95,&local_120,0x108);
    if (iVar2 == 0) {
      *(undefined1 *)(param_2 + 0x348) = local_11f;
      iVar2 = knvlinkSetupTopologyForForcedConfig_IMPL(param_1,param_2);
      return iVar2;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_nvlink_gv100.c",0xb8,
                 "knvlinkOverrideConfig_GV100",4,
                 "NVRM: Failed to process forced NVLink configurations !\n");
    portMemFree(*(undefined8 *)(param_2 + 0x330));
    *(undefined8 *)(param_2 + 0x330) = 0;
    return iVar2;
  }
  portMemFree(*(undefined8 *)(param_2 + 0x330));
  *(undefined8 *)(param_2 + 0x330) = 0;
  return 0;
}


// ===== 00412330 knvlinkApplyNvswitchDegradedModeSettings_GV100 =====

int knvlinkApplyNvswitchDegradedModeSettings_GV100(undefined8 param_1,long param_2,ulong *param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  char *pcVar9;
  ulong uVar10;
  undefined8 uVar11;
  ulong uVar12;
  bool bVar13;
  undefined1 local_40 [16];
  
  lVar5 = portMemAllocNonPaged(*(undefined4 *)(param_2 + 0x3c0));
  if (lVar5 == 0) {
    return 0x51;
  }
  uVar10 = 0;
  portMemSet(lVar5,0,*(undefined4 *)(param_2 + 0x3c0));
  lVar7 = param_2 + 0x388;
  bitVectorCopy_IMPL(local_40,0x40,lVar7,0x40);
  uVar2 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
  while( true ) {
    uVar12 = (ulong)uVar2;
    cVar1 = bitVectorTestAllCleared_IMPL(local_40,0x40);
    if (cVar1 != '\0') break;
    if (*(long *)(param_2 + 0x3f0 + uVar12 * 0x78) == 3) {
      uVar10 = uVar10 | 1L << (uVar12 & 0x3f);
    }
    bitVectorClr_IMPL(local_40,0x40,uVar12);
    uVar2 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
  }
  iVar4 = 0;
  if (uVar10 != 0) {
    lVar6 = portMemAllocNonPaged(0xf28);
    if (lVar6 == 0) {
      iVar3 = 0x51;
    }
    else {
      portMemSet(lVar6,0,0xf28);
      iVar3 = convertBitVectorToLinkMasks(lVar7,lVar6,8,lVar6 + 8);
      uVar11 = 0x162;
      pcVar9 = 
      "convertBitVectorToLinkMasks(&pKernelNvlink->enabledLinks, &pParams->linkMask, sizeof(pParams->linkMask), &pParams->links)"
      ;
      if (iVar3 == 0) {
        *(undefined1 *)(lVar6 + 0x24) = 1;
        iVar3 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a93,lVar6,0xf28);
        if (iVar3 == 0) {
          bitVectorCopy_IMPL(local_40,0x40,lVar7,0x40);
          uVar2 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
          while( true ) {
            uVar10 = (ulong)uVar2;
            cVar1 = bitVectorTestAllCleared_IMPL(local_40,0x40);
            if (cVar1 != '\0') break;
            if (0x3f < uVar2) {
              nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_nvlink_gv100.c",0x173,
                           "_knvlinkAreLinksDisconnected",4,
                           "NVRM: Trying to access incorrect link from link mask! %d\n",uVar10);
              portMemFree(lVar6);
              goto LAB_00412590;
            }
            lVar8 = uVar10 * 0x3c + lVar6;
            if (((*(int *)(lVar8 + 0x2c) != 2) || (*(int *)(lVar8 + 0x30) != 7)) ||
               (bVar13 = true, *(int *)(lVar8 + 0x34) != 7)) {
              bVar13 = *(char *)(lVar6 + 0x2a + uVar10 * 0x3c) != '\0';
            }
            *(bool *)(lVar5 + uVar10) = bVar13;
            bitVectorClr_IMPL(local_40,0x40,uVar10);
            uVar2 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
          }
          portMemFree(lVar6);
LAB_00412590:
          bitVectorCopy_IMPL(local_40,0x40,lVar7,0x40);
          uVar2 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
          while( true ) {
            uVar10 = (ulong)uVar2;
            cVar1 = bitVectorTestAllCleared_IMPL(local_40,0x40);
            iVar4 = iVar3;
            if (cVar1 != '\0') break;
            lVar7 = uVar10 * 0x78 + param_2;
            if (*(long *)(lVar7 + 0x3f0) == 3) {
              cVar1 = *(char *)(lVar7 + 0x400);
              if (*(char *)(lVar5 + uVar10) == '\0') {
                if (cVar1 == '\x01') {
                  *param_3 = *param_3 | 1L << ((byte)uVar2 & 0x3f);
                }
              }
              else {
                *(ulong *)(param_2 + 0x14b8) =
                     1L << ((byte)uVar2 & 0x3f) | *(ulong *)(param_2 + 0x14b8);
                *(undefined1 *)(lVar7 + 0x400) = 0;
                if ((cVar1 != '\0') &&
                   (iVar4 = knvlinkUpdateLinkConnectionStatus_IMPL(param_1,param_2,uVar10),
                   iVar4 != 0)) break;
              }
            }
            bitVectorClr_IMPL(local_40,0x40,uVar10);
            uVar2 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
          }
          goto LAB_00412417;
        }
        uVar11 = 0x16a;
        pcVar9 = 
        "knvlinkExecGspRmRpc(pGpu, pKernelNvlink, NV2080_CTRL_CMD_INTERNAL_NVLINK_GET_LINK_AND_CLOCK_INFO, (void *)pParams, sizeof(*pParams))"
        ;
      }
      nvCheckOkFailedNoLog
                (4,iVar3,pcVar9,"src/kernel/gpu/nvlink/arch/volta/kernel_nvlink_gv100.c",uVar11);
      portMemFree(lVar6);
    }
    nvCheckOkFailedNoLog
              (1,iVar3,"_knvlinkAreLinksDisconnected(pGpu, pKernelNvlink, bLinkDisconnected)",
               "src/kernel/gpu/nvlink/arch/volta/kernel_nvlink_gv100.c",0x105);
    iVar4 = iVar3;
  }
LAB_00412417:
  portMemFree(lVar5);
  return iVar4;
}


// ===== 00412730 knvlinkProgramLinkSpeed_GV100 =====

int knvlinkProgramLinkSpeed_GV100(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined4 local_38;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar1 = osGetPlatformNvlinkLinerate(param_1,&local_38);
  portMemSet(local_34,0,0xc);
  local_34[0] = iVar1 == 0;
  local_30 = local_38;
  iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a8f,local_34,0xc);
  if (iVar1 == 0) {
    *(undefined4 *)(param_2 + 0x160c) = local_2c;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_nvlink_gv100.c",0x1b2,
               "knvlinkProgramLinkSpeed_GV100",4,"NVRM: Failed to program NVLink speed for links!\n"
              );
  return iVar1;
}


// ===== 004127f0 knvlinkStatePostLoadHal_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int knvlinkStatePostLoadHal_GV100(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined1 local_38 [8];
  undefined8 local_30;
  
  lVar1 = *(long *)(param_1 + 0x1b98);
  cVar2 = knvlinkIsNvswitchProxyPresent_IMPL();
  if (cVar2 != '\0') {
    portMemSet(local_38,0,0x10);
    local_38[0] = 1;
    local_30 = 0xffffffffffffffff;
    iVar3 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800aae,local_38,0x10);
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_nvlink_gv100.c",0x1db,
                   "knvlinkStatePostLoadHal_GV100",4,
                   "NVRM: Failed to get nvswitch fabric address for GPU %x\n",
                   *(undefined4 *)(param_1 + 0x7a4));
      return iVar3;
    }
    iVar3 = (**(code **)(param_2 + 0x178))(param_1,param_2,local_30);
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_nvlink_gv100.c",0x1e3,
                   "knvlinkStatePostLoadHal_GV100",4,
                   "NVRM: Failed to set unique NVSwitch fabric base address for GPU %x\n",
                   *(undefined4 *)(param_1 + 0x7a4));
      return iVar3;
    }
  }
  cVar2 = knvlinkIsNvswitchProxyPresent_IMPL(param_1,param_2);
  if (((cVar2 != '\0') || (*(char *)(param_2 + 0x348) != '\0')) ||
     (iVar3 = 0, *(char *)(param_1 + 0x4cc) == '\x01')) {
    iVar3 = (**(code **)(lVar1 + 0x350))(lVar1);
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_nvlink_gv100.c",0x1f1,
                   "knvlinkStatePostLoadHal_GV100",4,
                   "NVRM: Failed to enable compute addressing for GPU %x\n",
                   *(undefined4 *)(param_1 + 0x7a4));
      return iVar3;
    }
    iVar3 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800aad,0,0);
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_nvlink_gv100.c",0x1fb,
                   "knvlinkStatePostLoadHal_GV100",4,
                   "NVRM: Failed to enable compute peer addressing!\n");
    }
  }
  return iVar3;
}


// ===== 004129f0 knvlinkSetUniqueFabricBaseAddress_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int knvlinkSetUniqueFabricBaseAddress_GV100(long param_1,long param_2,long param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint local_38 [2];
  long local_30;
  
  cVar1 = knvlinkIsForcedConfig_IMPL();
  if (cVar1 == '\0') {
    knvlinkCoreGetRemoteDeviceInfo_IMPL(param_1,param_2);
    iVar2 = bitVectorGetSlice_IMPL(param_2 + 0x388,0x40,0,0x3f,local_38);
    uVar3 = local_38[0];
    if (iVar2 != 0) {
      nvAssertFailedNoLog("(bitVectorGetSlice(pSrc, rangeMake(0, 63), &localMask) == NV_OK)",
                          "generated/g_kernel_nvlink_nvoc.h",0x8fd);
      uVar3 = 0;
    }
    iVar2 = (**(code **)(param_2 + 0x1b8))(param_1,param_2,uVar3);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_nvlink_gv100.c",599,
                   "knvlinkSetUniqueFabricBaseAddress_GV100",4,
                   "NVRM: Nvlink post topology links setup failed on GPU %x\n",
                   *(undefined4 *)(param_1 + 0x7a4));
      return iVar2;
    }
  }
  cVar1 = knvlinkIsGpuConnectedToNvswitch_IMPL(param_1,param_2);
  if (cVar1 == '\0') {
    nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_nvlink_gv100.c",0x260,
                 "knvlinkSetUniqueFabricBaseAddress_GV100",4,
                 "NVRM: Operation failed due to no NVSwitch connectivity to the GPU  %x\n",
                 *(undefined4 *)(param_1 + 0x7a4));
    return 0x40;
  }
  iVar2 = (**(code **)(param_2 + 0x1a0))(param_1,param_2,param_3);
  if (iVar2 == 0) {
    if (*(long *)(param_2 + 0x16a8) == param_3) {
      nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_nvlink_gv100.c",0x279,
                   "knvlinkSetUniqueFabricBaseAddress_GV100",1,
                   "NVRM: The same fabric addr is being re-assigned to GPU %x\n",
                   *(undefined4 *)(param_1 + 0x7a4));
    }
    else {
      if (*(long *)(param_2 + 0x16a8) != -1) {
        nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_nvlink_gv100.c",0x281,
                     "knvlinkSetUniqueFabricBaseAddress_GV100",4,
                     "NVRM: Fabric addr is already assigned to GPU %x\n",
                     *(undefined4 *)(param_1 + 0x7a4));
        return 99;
      }
      portMemSet(local_38,0,0x10);
      local_38[0] = local_38[0] & 0xffffff00;
      local_30 = param_3;
      iVar2 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800aae,local_38,0x10);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_nvlink_gv100.c",0x297,
                     "knvlinkSetUniqueFabricBaseAddress_GV100",4,
                     "NVRM: Failed to stash fabric address for GPU %x\n",
                     *(undefined4 *)(param_1 + 0x7a4));
        return iVar2;
      }
      *(long *)(param_2 + 0x16a8) = param_3;
      nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_nvlink_gv100.c",0x29e,
                   "knvlinkSetUniqueFabricBaseAddress_GV100",4,
                   "NVRM: Fabric base addr %llx is assigned to GPU %x\n",param_3,
                   *(undefined4 *)(param_1 + 0x7a4));
    }
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/arch/volta/kernel_nvlink_gv100.c",0x26a,
               "knvlinkSetUniqueFabricBaseAddress_GV100",4,
               "NVRM: Fabric addr validation failed for GPU %x\n",*(undefined4 *)(param_1 + 0x7a4));
  return iVar2;
}


// ===== 00412cf0 convertMaskToBitVector =====

undefined8 convertMaskToBitVector(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 local_20 [2];
  
  if (param_2 == 0) {
    return 0x1f;
  }
  local_20[0] = param_1;
  uVar1 = bitVectorClrAll_IMPL(param_2,0x40);
  if ((int)uVar1 != 0) {
    return uVar1;
  }
  uVar1 = bitVectorFromRaw_IMPL(param_2,0x40,local_20,8);
  return uVar1;
}


// ===== 00412d50 convertBitVectorToLinkMasks =====

undefined8
convertBitVectorToLinkMasks(long param_1,undefined4 *param_2,int param_3,undefined1 *param_4)

{
  undefined8 uVar1;
  undefined8 local_20 [2];
  
  if (param_1 == 0) {
    return 0x1f;
  }
  if (param_2 != (undefined4 *)0x0) {
    if (param_3 == 4) {
      local_20[0] = 0;
      uVar1 = bitVectorToRaw_IMPL(param_1,0x40,local_20,8);
      if ((int)uVar1 != 0) {
        return uVar1;
      }
      *param_2 = (int)local_20[0];
    }
    else {
      if (param_3 != 8) {
        return 0x1f;
      }
      uVar1 = bitVectorToRaw_IMPL(param_1,0x40,param_2,8);
      if ((int)uVar1 != 0) {
        return uVar1;
      }
    }
  }
  uVar1 = 0;
  if ((param_4 != (undefined1 *)0x0) &&
     (uVar1 = bitVectorToRaw_IMPL(param_1,0x40,param_4 + 8,8), (int)uVar1 == 0)) {
    *param_4 = 1;
  }
  return uVar1;
}


// ===== 00412e10 convertLinkMasksToBitVector =====

undefined8 convertLinkMasksToBitVector(long param_1,int param_2,long param_3,long param_4)

{
  undefined8 uVar1;
  undefined1 local_40 [8];
  undefined1 local_38 [8];
  undefined8 local_30;
  
  if (param_4 == 0) {
    return 0x1f;
  }
  uVar1 = bitVectorClrAll_IMPL(param_4,0x40);
  if ((((int)uVar1 == 0) && (uVar1 = bitVectorClrAll_IMPL(local_40,0x40), (int)uVar1 == 0)) &&
     (uVar1 = bitVectorClrAll_IMPL(local_38,0x40), (int)uVar1 == 0)) {
    if (param_1 != 0) {
      if ((param_2 - 4U & 0xfffffffb) != 0) {
        nvCheckFailedNoLog(4,"(linkMask1Size == sizeof(NvU32) || linkMask1Size == sizeof(NvU64))",
                           "src/kernel/gpu/nvlink/bitvector_nvlink.c",0xa8);
        return 0x1f;
      }
      local_30 = 0;
      portMemCopy(&local_30,8,param_1,param_2);
      uVar1 = bitVectorFromRaw_IMPL(local_40,0x40,&local_30,8);
      if ((int)uVar1 != 0) {
        return uVar1;
      }
    }
    if ((param_3 != 0) &&
       (uVar1 = bitVectorFromRaw_IMPL(local_38,0x40,param_3 + 8,8), (int)uVar1 != 0)) {
      return uVar1;
    }
    uVar1 = bitVectorOr_IMPL(param_4,0x40,local_40,0x40,local_38,0x40);
  }
  return uVar1;
}


// ===== 00412f50 subdeviceCtrlCmdBusGetNvlinkCaps_VF =====

undefined8 subdeviceCtrlCmdBusGetNvlinkCaps_VF(long param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = gpuGetStaticInfo(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  if (lVar1 != 0) {
    portMemCopy(param_2,0x30,lVar1 + 0x8ee0,0x30);
    return 0;
  }
  nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/nvlink/common_nvlinkapi.c",0x4b);
  return 0x40;
}


// ===== 00412fd0 nvlinkCtrlCmdBusGetNvlinkCaps =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvlinkCtrlCmdBusGetNvlinkCaps(long param_1,long param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  uint uVar8;
  long lVar9;
  bool bVar10;
  undefined8 local_58;
  long local_50;
  byte local_3a;
  byte local_39;
  
  if (*(long *)(param_1 + 0x1bc0) == 0) {
    *(undefined4 *)(param_2 + 0xc) = 0;
    portMemSet(param_2 + 0x20,0,0x10);
    *(undefined4 *)(param_2 + 8) = 0;
    portMemSet(param_2 + 0x10,0,0x10);
    lVar9 = *(long *)(param_1 + 0x1ce8);
    if (lVar9 == 0) goto LAB_00413310;
    local_58 = knvlinkGetEnabledLinkMask_IMPL(param_1,lVar9);
LAB_00413187:
    uVar8 = *(uint *)(lVar9 + 0x314);
    cVar2 = *(char *)(lVar9 + 0x2e0);
    portMemSet(&local_3a,0,2);
    bVar10 = false;
    if (uVar8 == 6) {
LAB_0041311d:
      local_39 = local_39 | 5;
      uVar7 = 6;
    }
    else {
LAB_004131d0:
      if (uVar8 < 6 || bVar10) {
        if (uVar8 == 4) {
          local_39 = local_39 | 5;
          uVar7 = 4;
        }
        else if (uVar8 == 5) {
          local_39 = local_39 | 5;
          uVar7 = 5;
        }
        else {
          if (uVar8 != 2) goto LAB_00413360;
          local_39 = local_39 | 1;
          uVar7 = 2;
        }
      }
      else if (uVar8 == 7) {
        local_39 = local_39 | 3;
        uVar7 = 7;
      }
      else if (uVar8 == 8) {
        local_39 = local_39 | 7;
        uVar7 = 8;
      }
      else {
LAB_00413360:
        local_39 = local_39 | 1;
        uVar7 = 1;
      }
    }
    *(undefined1 *)(param_2 + 4) = uVar7;
    *(undefined1 *)(param_2 + 5) = uVar7;
    *(undefined1 *)(param_2 + 6) = uVar7;
    *(undefined1 *)(param_2 + 7) = uVar7;
    if (cVar2 == '\0') goto LAB_00413227;
  }
  else {
    cVar2 = kmigmgrIsMIGNvlinkP2PSupported_IMPL();
    *(undefined4 *)(param_2 + 0xc) = 0;
    portMemSet(param_2 + 0x20,0,0x10);
    *(undefined4 *)(param_2 + 8) = 0;
    portMemSet(param_2 + 0x10,0,0x10);
    lVar9 = *(long *)(param_1 + 0x1ce8);
    if (lVar9 == 0) {
LAB_00413310:
      nvDbg_Printf("src/kernel/gpu/nvlink/common_nvlinkapi.c",0x106,"nvlinkCtrlCmdBusGetNvlinkCaps",
                   1,"NVRM: Kernel NVLink is unavailable. Returning.\n");
      return 0;
    }
    local_58 = knvlinkGetEnabledLinkMask_IMPL(param_1,lVar9);
    if (cVar2 == '\0') goto LAB_00413187;
    (**(code **)(lVar9 + 0x1c8))(param_1,lVar9);
    uVar8 = *(uint *)(lVar9 + 0x314);
    cVar2 = *(char *)(lVar9 + 0x2e0);
    iVar4 = *(int *)(lVar9 + 0x380);
    cVar1 = *(char *)(lVar9 + 0x2f1);
    portMemSet(&local_3a,0,2);
    local_3a = local_3a | 0xf;
    cVar3 = bitVectorTestAllCleared_IMPL(lVar9 + 0x378,0x40);
    if (cVar3 == '\0') {
      local_3a = local_3a | 0x80;
    }
    if (iVar4 != 0) {
      local_3a = local_3a | 0x40;
    }
    bVar10 = cVar1 != '\0';
    if (uVar8 != 1) {
      local_3a = local_3a | 0x10;
      local_39 = local_39 | (cVar2 != '\0' && bVar10) << 5;
      bVar10 = uVar8 == 6;
      if (!bVar10) goto LAB_004131d0;
      goto LAB_0041311d;
    }
    if (cVar2 == '\0' || !bVar10) goto LAB_00413360;
    *(undefined4 *)(param_2 + 4) = 0x1010101;
    local_39 = local_39 | 0x21;
  }
  local_39 = local_39 | 0x10;
LAB_00413227:
  local_50 = param_2 + 0x20;
  portMemCopy(param_2,2,&local_3a,2);
  lVar5 = knvlinkGetDiscoveredLinkMask_IMPL(param_1,lVar9);
  if (lVar5 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/common_nvlinkapi.c",0x11f,"nvlinkCtrlCmdBusGetNvlinkCaps",4,
                 "NVRM: Failed to get discovered link mask!\n");
  }
  iVar4 = convertBitVectorToLinkMasks(lVar5,param_2 + 8,4,0);
  if (iVar4 == 0) {
    iVar4 = convertBitVectorToLinkMasks(lVar5,0,0,param_2 + 0x10);
    if (iVar4 == 0) {
      iVar4 = convertBitVectorToLinkMasks(local_58,param_2 + 0xc,4,0);
      if (iVar4 == 0) {
        uVar6 = knvlinkGetEnabledLinkMask_IMPL(param_1,lVar9);
        iVar4 = convertBitVectorToLinkMasks(uVar6,0,0,local_50);
        if (iVar4 != 0) {
          nvDbg_Printf("src/kernel/gpu/nvlink/common_nvlinkapi.c",0x150,
                       "nvlinkCtrlCmdBusGetNvlinkCaps",4,
                       "NVRM: Failed to convert bit vector to enabled links! 0x%x\n");
        }
      }
      else {
        nvDbg_Printf("src/kernel/gpu/nvlink/common_nvlinkapi.c",0x145,
                     "nvlinkCtrlCmdBusGetNvlinkCaps",4,
                     "NVRM: Failed to convert bit vector to enabled link mask! 0x%x\n",iVar4);
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/nvlink/common_nvlinkapi.c",0x136,"nvlinkCtrlCmdBusGetNvlinkCaps",
                   4,"NVRM: Failed to convert bit vector to discovered links! 0x%x\n",iVar4);
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/nvlink/common_nvlinkapi.c",0x12d,"nvlinkCtrlCmdBusGetNvlinkCaps",4,
                 "NVRM: Failed to convert bit vector to discovered link mask! 0x%x\n",iVar4);
  }
  return iVar4;
}


// ===== 00413490 subdeviceCtrlCmdBusGetNvlinkCaps_IMPL =====

void subdeviceCtrlCmdBusGetNvlinkCaps_IMPL(long param_1)

{
  nvlinkCtrlCmdBusGetNvlinkCaps(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  return;
}


// ===== 004134b0 subdeviceCtrlCmdBusGetNvlinkStatus_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdBusGetNvlinkStatus_IMPL(long param_1,undefined4 *param_2)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  long lVar5;
  byte bVar6;
  char cVar7;
  byte bVar8;
  undefined1 uVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  byte bVar14;
  int iVar15;
  int iVar16;
  long lVar17;
  undefined8 uVar18;
  ulong uVar19;
  long lVar20;
  long lVar21;
  long lVar22;
  uint uVar23;
  undefined4 *puVar24;
  uint uVar25;
  bool bVar26;
  undefined1 *local_60;
  byte local_52;
  byte local_51;
  undefined1 local_50 [8];
  undefined1 local_48 [8];
  undefined1 local_40 [16];
  
  lVar22 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*(long *)(lVar22 + 0x1bc0) == 0) {
    if (*(char *)(lVar22 + 0x908) == '\0') {
      *param_2 = 0;
      portMemSet(param_2 + 2,0,0x10);
LAB_00413e4e:
      nvDbg_Printf("src/kernel/gpu/nvlink/common_nvlinkapi.c",0x33b,
                   "subdeviceCtrlCmdBusGetNvlinkStatus_IMPL",1,
                   "NVRM: MIG NVLink P2P is not supported.\n");
      return 0;
    }
LAB_00413da4:
    cVar7 = rmcfg_IsPASCAL_CLASSIC_GPUSorBetter(lVar22);
    iVar15 = 0x56;
    if (cVar7 != '\0') {
      lVar17 = resservGetTlsCallContext();
      puVar24 = *(undefined4 **)(lVar17 + 0x48);
      lVar17 = gpuGetRpc(lVar22);
      if (lVar17 == 0) {
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/nvlink/common_nvlinkapi.c",0x2f5);
        iVar15 = 0x1a;
      }
      else if ((*(char *)(lVar22 + 0x909) == '\0') && (*(char *)(lVar22 + 0x90a) == '\0')) {
        iVar15 = rpcDmaControl_wrapper
                           (lVar22,lVar17,*puVar24,puVar24[1],puVar24[2],
                            *(undefined8 *)(puVar24 + 4),puVar24[6]);
      }
      else {
        iVar15 = (**(code **)(lVar22 + 0x3b90))(lVar22 + 0x3b58);
      }
      if (*(char *)(lVar22 + 0x4a4e) != '\0') {
        iVar15 = convertLinkMasksToBitVector(param_2,4,param_2 + 2,local_48);
        if (iVar15 == 0) {
          bVar8 = bitVectorCountSetBits_IMPL(local_48,0x40);
          if (bVar8 < 0x41) {
            bitVectorCopy_IMPL(local_40,0x40,local_48,0x40);
            bVar8 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
            while( true ) {
              uVar19 = (ulong)bVar8;
              cVar7 = bitVectorTestAllCleared_IMPL(local_40,0x40);
              if (cVar7 != '\0') break;
              uVar25 = (uint)bVar8;
              if (0x3f < bVar8) {
                nvDbg_Printf("src/kernel/gpu/nvlink/common_nvlinkapi.c",0x310,
                             "subdeviceCtrlCmdBusGetNvlinkStatus_IMPL",4,
                             "NVRM: Trying to access out of bounds link from link mask! %d\n",uVar25
                            );
                return 0x1f;
              }
              if (*(long *)(param_2 + (ulong)uVar25 * 0x36 + 0x26) != 3) {
                lVar22 = gpumgrGetGpuFromUuid(param_2 + uVar19 * 0x36 + 0x28,2);
                if (lVar22 == 0) {
                  portMemSet(param_2 + uVar19 * 0x36 + 8,0,0xd8);
                }
                else {
                  param_2[(ulong)uVar25 * 0x36 + 0x21] = (uint)*(ushort *)(lVar22 + 0x7ae);
                  *(ushort *)(param_2 + (ulong)uVar25 * 0x36 + 0x22) =
                       (ushort)*(byte *)(lVar22 + 0x7ad);
                  *(ushort *)((long)param_2 + (ulong)uVar25 * 0xd8 + 0x8a) =
                       (ushort)*(byte *)(lVar22 + 0x7ac);
                  portMemSet(param_2 + uVar19 * 0x36 + 0x28,0,0x10);
                }
              }
              bitVectorClr_IMPL(local_40,0x40,uVar25);
              bVar8 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
            }
          }
          else {
            nvAssertFailedNoLog("i <= NV2080_CTRL_NVLINK_MAX_LINKS",
                                "src/kernel/gpu/nvlink/common_nvlinkapi.c",0x308);
            iVar15 = 0x40;
          }
        }
        else {
          nvDbg_Printf("src/kernel/gpu/nvlink/common_nvlinkapi.c",0x302,
                       "subdeviceCtrlCmdBusGetNvlinkStatus_IMPL",4,
                       "NVRM: Failed to convert enabled link masks to bit vector! 0x%x\n",iVar15);
        }
      }
    }
    return iVar15;
  }
  cVar7 = kmigmgrIsMIGNvlinkP2PSupported_IMPL(lVar22);
  if (*(char *)(lVar22 + 0x908) != '\0') goto LAB_00413da4;
  *param_2 = 0;
  puVar24 = param_2 + 2;
  portMemSet(puVar24,0,0x10);
  if (cVar7 == '\0') goto LAB_00413e4e;
  lVar17 = portMemAllocNonPaged(0x15e8);
  if (lVar17 == 0) {
    return 0x51;
  }
  portMemSet(lVar17,0,0x15e8);
  lVar5 = *(long *)(lVar22 + 0x1ce8);
  if (lVar5 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/common_nvlinkapi.c",0x354,
                 "subdeviceCtrlCmdBusGetNvlinkStatus_IMPL",1,
                 "NVRM: Kernel NVLink is unavailable. Returning.\n");
    iVar15 = 0;
    goto LAB_0041404e;
  }
  cVar7 = knvlinkIsForcedConfig_IMPL(lVar22,lVar5);
  if ((cVar7 == '\0') &&
     ((*(char *)(lVar22 + 0x4911) == '\0' || (*(char *)(lVar5 + 0x15fc) != '\0')))) {
    iVar15 = knvlinkCoreGetRemoteDeviceInfo_IMPL(lVar22,lVar5);
    if (iVar15 != 0x55) {
      if (iVar15 != 0) goto LAB_0041404e;
      goto LAB_0041357d;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/common_nvlinkapi.c",0x366,
                 "subdeviceCtrlCmdBusGetNvlinkStatus_IMPL",1,"NVRM: Nvlink is not ready yet!\n");
    (**(code **)(lVar5 + 0x1c8))(lVar22,lVar5);
    bitVectorClrAll_IMPL(local_50,0x40);
  }
  else {
LAB_0041357d:
    (**(code **)(lVar5 + 0x1c8))(lVar22,lVar5);
    bitVectorClrAll_IMPL(local_50,0x40);
    uVar18 = knvlinkGetEnabledLinkMask_IMPL(lVar22,lVar5);
    bitVectorCopy_IMPL(local_50,0x40,uVar18,0x40);
  }
  local_60 = local_50;
  iVar15 = convertBitVectorToLinkMasks(local_60,param_2,4,puVar24);
  if (iVar15 == 0) {
    iVar15 = convertBitVectorToLinkMasks(local_60,lVar17,8,lVar17 + 8);
    if (iVar15 == 0) {
      *(undefined1 *)(lVar17 + 0x24) = 1;
      iVar15 = knvlinkExecGspRmRpc_IMPL(lVar22,lVar5,0x20800a93,lVar17,0xf28);
      if (iVar15 == 0) {
        bitVectorCopy_IMPL(local_40,0x40,local_60,0x40);
        bVar8 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
        while (cVar7 = bitVectorTestAllCleared_IMPL(local_40,0x40), cVar7 == '\0') {
          uVar19 = (ulong)bVar8;
          if (0x23 < bVar8) {
            nvDbg_Printf("src/kernel/gpu/nvlink/common_nvlinkapi.c",0x3a2,
                         "subdeviceCtrlCmdBusGetNvlinkStatus_IMPL",4,
                         "NVRM: Trying to access incorrect link from mask! %d\n",uVar19);
            goto LAB_0041404e;
          }
          lVar21 = lVar17 + uVar19 * 0x30;
          lVar20 = lVar5 + uVar19 * 0x78;
          *(undefined4 *)(lVar21 + 0xf28) = *(undefined4 *)(lVar20 + 0x430);
          *(undefined1 *)(lVar21 + 0xf2c) = *(undefined1 *)(lVar20 + 0x400);
          *(undefined4 *)(lVar21 + 0xf30) = *(undefined4 *)(lVar20 + 0x3f8);
          *(undefined8 *)(lVar21 + 0xf38) = *(undefined8 *)(lVar20 + 0x3f0);
          *(undefined8 *)(lVar21 + 0xf40) = *(undefined8 *)(lVar20 + 0x408);
          *(undefined4 *)(lVar21 + 0xf48) = *(undefined4 *)(lVar20 + 0x3d0);
          *(char *)(lVar21 + 0xf4c) = (char)*(undefined2 *)(lVar20 + 0x3d4);
          *(char *)(lVar21 + 0xf4d) = (char)*(undefined2 *)(lVar20 + 0x3d6);
          *(char *)(lVar21 + 0xf4e) = (char)*(undefined2 *)(lVar20 + 0x3d8);
          *(undefined4 *)(lVar21 + 0xf50) = *(undefined4 *)(lVar20 + 0x3dc);
          uVar9 = knvlinkIsP2pLoopbackSupportedPerLink_IMPL(lVar22,lVar5,uVar19);
          *(undefined1 *)(lVar21 + 0xf54) = uVar9;
          if (*(long *)(lVar20 + 0x3c8) != 0) {
            *(undefined8 *)(param_2 + uVar19 * 0x36 + 0x1a) =
                 *(undefined8 *)(*(long *)(lVar20 + 0x3c8) + 0x70);
          }
          bitVectorClr_IMPL(local_40,0x40,uVar19);
          bVar8 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
        }
        *(undefined1 *)((long)param_2 + 0x19) = *(undefined1 *)(lVar5 + 0x2f3);
        cVar10 = knvlinkIsUncontainedErrorRecoveryActive_IMPL(lVar22,lVar5);
        cVar11 = knvlinkGetDegradedMode_IMPL(lVar22,lVar5);
        cVar7 = *(char *)(lVar5 + 0x2f1);
        cVar12 = knvlinkIsForcedConfig_IMPL(lVar22,lVar5);
        cVar1 = *(char *)(lVar5 + 0x2e1);
        cVar2 = *(char *)(lVar5 + 0x2e0);
        uVar25 = *(uint *)(lVar5 + 0x314);
        uVar3 = *(uint *)(lVar5 + 0x380);
        iVar16 = convertLinkMasksToBitVector(param_2,4,puVar24,local_48);
        if (iVar16 != 0) {
          nvDbg_Printf("src/kernel/gpu/nvlink/common_nvlinkapi.c",0x175,"_getNvlinkStatus",4,
                       "NVRM: Failed to convert enabled link masks to bitvector\n");
        }
        bVar8 = bitVectorCountSetBits_IMPL(local_48,0x40);
        if (bVar8 < 0x41) {
          *(undefined8 *)(param_2 + 0xd88) = *(undefined8 *)(lVar17 + 0x18);
          bitVectorCopy_IMPL(local_40,0x40,local_48,0x40);
          uVar19 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
          uVar19 = uVar19 & 0xff;
          while (cVar13 = bitVectorTestAllCleared_IMPL(local_40,0x40), cVar13 == '\0') {
            bVar8 = (byte)uVar19;
            if (0x3f < bVar8) {
              nvDbg_Printf("src/kernel/gpu/nvlink/common_nvlinkapi.c",0x188,"_getNvlinkStatus",4,
                           "NVRM: Trying to access out out bounds link from link mask! %d\n",uVar19)
              ;
              break;
            }
            portMemSet(&local_52,0,2);
            if (cVar2 != '\0') {
              local_51 = local_51 | 0x10;
            }
            bVar6 = 0;
            if (*(char *)(lVar17 + 0x28 + uVar19 * 0x3c) != '\0') {
              bVar6 = 1;
              bVar14 = local_52 | 0x14;
              local_52 = local_52 | 4;
              if (uVar25 != 1) {
                local_52 = bVar14;
              }
            }
            puVar24 = (undefined4 *)(uVar19 * 0x30 + lVar17 + 0xf28);
            bVar26 = *(char *)(puVar24 + 1) != '\0';
            if (bVar26) {
              local_52 = local_52 | 10;
            }
            cVar13 = bitVectorTest_IMPL(lVar5 + 0x378,0x40,uVar19);
            if (cVar13 != '\0') {
              local_52 = local_52 | 0x80;
            }
            if ((uVar3 >> (uVar19 & 0x3f) & 1) != 0) {
              local_52 = local_52 | 0x40;
            }
            bVar14 = (cVar2 != '\0' && cVar7 != '\0') << 5 | local_51;
            local_51 = bVar14 | 1;
            if ((uVar25 - 4 < 5) && (cVar1 != '\0')) {
              local_51 = bVar14 | 5;
            }
            portMemCopy(param_2 + uVar19 * 0x36 + 8,2,&local_52,2);
            lVar21 = uVar19 * 0x3c + lVar17;
            *(undefined1 *)(param_2 + uVar19 * 0x36 + 9) = 1;
            *(undefined1 *)((long)param_2 + uVar19 * 0xd8 + 0x25) = *(undefined1 *)(lVar21 + 0x2b);
            param_2[uVar19 * 0x36 + 10] = *(undefined4 *)(lVar21 + 0x2c);
            *(char *)((long)param_2 + uVar19 * 0xd8 + 0x2d) = (char)*(undefined4 *)(lVar21 + 0x30);
            *(char *)(param_2 + uVar19 * 0x36 + 0xb) = (char)*(undefined4 *)(lVar21 + 0x34);
            param_2[uVar19 * 0x36 + 0x3c] = *(undefined4 *)(lVar21 + 0x60);
            if (uVar25 == 6) {
              cVar13 = '\x06';
            }
            else if (uVar25 < 7) {
              cVar13 = '\x04';
              if ((uVar25 != 4) && (cVar13 = '\x05', uVar25 != 5)) {
                cVar13 = (uVar25 == 2) + '\x01';
              }
            }
            else {
              cVar13 = '\a';
              if (uVar25 != 7) {
                cVar13 = '\x01';
                if (uVar25 == 8) {
                  cVar13 = '\b';
                }
              }
            }
            lVar20 = uVar19 * 0xd8;
            *(undefined1 *)((long)param_2 + lVar20 + 0x2e) = *(undefined1 *)(lVar21 + 0x38);
            *(char *)((long)param_2 + lVar20 + 0x2f) = cVar13;
            *(char *)(param_2 + uVar19 * 0x36 + 0xc) = cVar13;
            *(undefined1 *)((long)param_2 + lVar20 + 0x31) = 1;
            *(undefined1 *)(param_2 + uVar19 * 0x36 + 0x16) = 0;
            *(undefined1 *)((long)param_2 + lVar20 + 0x5a) = 0xff;
            *(undefined8 *)(param_2 + uVar19 * 0x36 + 0x26) = 0xff;
            *(byte *)((long)param_2 + lVar20 + 0x5b) = bVar8;
            param_2[uVar19 * 0x36 + 0x1c] = *puVar24;
            param_2[uVar19 * 0x36 + 0x2f] = *(undefined4 *)(lVar22 + 0x87c);
            *(ushort *)(param_2 + uVar19 * 0x36 + 0x30) = (ushort)*(byte *)(lVar22 + 0x879);
            bVar14 = *(byte *)(lVar22 + 0x878);
            *(undefined2 *)(param_2 + uVar19 * 0x36 + 0x31) = 0;
            *(ushort *)((long)param_2 + lVar20 + 0xc2) = (ushort)bVar14;
            uVar4 = *(undefined4 *)(lVar22 + 0x7f4);
            *(undefined8 *)(param_2 + uVar19 * 0x36 + 0x34) = 2;
            param_2[uVar19 * 0x36 + 0x32] = uVar4;
            if (*(int *)(lVar22 + 0x7f4) != 0) {
              param_2[uVar19 * 0x36 + 0x2e] = 1;
            }
            iVar16 = 1;
            if (cVar11 == '\0') {
              iVar16 = (uint)(cVar10 != '\0') * 2;
            }
            param_2[uVar19 * 0x36 + 0x3a] = iVar16;
            lVar21 = uVar19 * 0x3c + lVar17;
            uVar23 = *(uint *)(lVar21 + 0x3c);
            param_2[uVar19 * 0x36 + 0xd] = uVar23;
            uVar23 = uVar23 >> 4;
            uVar4 = *(undefined4 *)(lVar17 + 0x20);
            param_2[uVar19 * 0x36 + 0xe] = uVar23;
            param_2[uVar19 * 0x36 + 0xf] = uVar4;
            param_2[uVar19 * 0x36 + 0x10] = uVar23 / 1000;
            param_2[uVar19 * 0x36 + 0x11] = *(undefined4 *)(lVar21 + 0x40);
            iVar16 = *(int *)(lVar21 + 0x44);
            param_2[uVar19 * 0x36 + 0x12] = iVar16;
            param_2[uVar19 * 0x36 + 0x14] = *(undefined4 *)(lVar21 + 0x48);
            *(undefined1 *)(param_2 + uVar19 * 0x36 + 0x13) = *(undefined1 *)(lVar21 + 0x4c);
            param_2[uVar19 * 0x36 + 0x15] = *(undefined4 *)(lVar21 + 0x50);
            param_2[uVar19 * 0x36 + 0x1d] = *(undefined4 *)(lVar21 + 0x54);
            param_2[uVar19 * 0x36 + 0x1e] = *(undefined4 *)(lVar21 + 0x58);
            param_2[uVar19 * 0x36 + 0x1f] = *(undefined4 *)(lVar21 + 0x5c);
            if (*(char *)(puVar24 + 1) == '\0') {
LAB_00413ac3:
              if (cVar12 != '\0') {
                if (*(char *)(lVar22 + 0x446) == '\0') {
                  param_2[uVar19 * 0x36 + 10] = 3;
                  *(undefined2 *)(param_2 + uVar19 * 0x36 + 0xb) = 0;
                }
                *(undefined2 *)(param_2 + uVar19 * 0x36 + 0x16) = 1;
                *(byte *)((long)param_2 + uVar19 * 0xd8 + 0x5a) = bVar8;
                if (iVar16 == 0) {
                  param_2[uVar19 * 0x36 + 0x12] = *(undefined4 *)(lVar17 + 0x50 + uVar19 * 0x3c);
                }
                if ((bool)(bVar6 & !bVar26)) {
                  param_2[uVar19 * 0x36 + 0x21] = 0;
                  param_2[uVar19 * 0x36 + 0x22] = 0xe;
                  param_2[uVar19 * 0x36 + 0x20] = param_2[uVar19 * 0x36 + 0x20] | 1;
                  *(short *)(param_2 + uVar19 * 0x36 + 0x23) = (short)uVar19;
                  param_2[uVar19 * 0x36 + 0x24] = 0x10ec;
                  *(undefined8 *)(param_2 + uVar19 * 0x36 + 0x26) = 0;
                }
                else if ((bool)(bVar26 & (bVar6 ^ 1))) {
                  lVar20 = gpumgrGetGpu(*(int *)(lVar22 + 0x7a4) == 0);
                  lVar21 = lVar22;
                  if ((((lVar20 != 0) && (lVar21 = lVar20, lVar22 != lVar20)) &&
                      (lVar21 = lVar22, *(long *)(lVar20 + 0x1ce8) != 0)) &&
                     (cVar13 = bitVectorTestAllCleared_IMPL(*(long *)(lVar20 + 0x1ce8) + 0x350,0x40)
                     , lVar21 = lVar20, cVar13 != '\0')) {
                    lVar21 = lVar22;
                  }
                  param_2[uVar19 * 0x36 + 0x21] = *(undefined4 *)(lVar21 + 0x87c);
                  *(ushort *)(param_2 + uVar19 * 0x36 + 0x22) = (ushort)*(byte *)(lVar21 + 0x879);
                  *(ushort *)((long)param_2 + uVar19 * 0xd8 + 0x8a) =
                       (ushort)*(byte *)(lVar21 + 0x878);
                  *(undefined2 *)(param_2 + uVar19 * 0x36 + 0x23) = 0;
                  uVar4 = *(undefined4 *)(lVar21 + 0x7f4);
                  *(undefined8 *)(param_2 + uVar19 * 0x36 + 0x26) = 2;
                  param_2[uVar19 * 0x36 + 0x24] = uVar4;
                  if (*(long *)(lVar21 + 0x878) == *(long *)(lVar22 + 0x878)) {
                    *(undefined1 *)((long)param_2 + uVar19 * 0xd8 + 0x59) = 1;
                  }
                  param_2[uVar19 * 0x36 + 0x20] = param_2[uVar19 * 0x36 + 0x20] | 1;
                }
                if ((bool)(bVar6 & bVar26)) {
                  param_2[uVar19 * 0x36 + 0x20] = param_2[uVar19 * 0x36 + 0x20] | 1;
                  param_2[uVar19 * 0x36 + 0x21] = 0;
                  param_2[uVar19 * 0x36 + 0x22] = 0xe;
                  *(short *)(param_2 + uVar19 * 0x36 + 0x23) = (short)uVar19;
                  param_2[uVar19 * 0x36 + 0x24] = 0x10f5;
                  *(undefined8 *)(param_2 + uVar19 * 0x36 + 0x26) = 3;
                }
              }
            }
            else {
              *(undefined1 *)(param_2 + uVar19 * 0x36 + 0x16) = 1;
              uVar4 = puVar24[2];
              *(byte *)((long)param_2 + uVar19 * 0xd8 + 0x5a) = (byte)uVar4;
              *(undefined8 *)(param_2 + uVar19 * 0x36 + 0x18) = *(undefined8 *)(puVar24 + 6);
              param_2[uVar19 * 0x36 + 0x21] = puVar24[8];
              *(ushort *)(param_2 + uVar19 * 0x36 + 0x22) = (ushort)*(byte *)(puVar24 + 9);
              *(ushort *)((long)param_2 + uVar19 * 0xd8 + 0x8a) =
                   (ushort)*(byte *)((long)puVar24 + 0x25);
              *(ushort *)(param_2 + uVar19 * 0x36 + 0x23) = (ushort)*(byte *)((long)puVar24 + 0x26);
              param_2[uVar19 * 0x36 + 0x24] = puVar24[10];
              *(undefined8 *)(param_2 + uVar19 * 0x36 + 0x26) = *(undefined8 *)(puVar24 + 4);
              if (puVar24[10] == 0) {
                if ((param_2[uVar19 * 0x36 + 0x20] & 1) != 0) goto LAB_00414131;
LAB_00413aae:
                *(char *)((long)param_2 + uVar19 * 0xd8 + 0x59) = (bVar8 != (byte)uVar4) + '\x01';
                goto LAB_00413ac3;
              }
              param_2[uVar19 * 0x36 + 0x20] = param_2[uVar19 * 0x36 + 0x20] | 1;
LAB_00414131:
              if (*(char *)(puVar24 + 0xb) != '\0') goto LAB_00413aae;
              *(undefined1 *)((long)param_2 + uVar19 * 0xd8 + 0x59) = 0;
            }
            bitVectorClr_IMPL(local_40,0x40,uVar19);
            bVar8 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
            uVar19 = (ulong)bVar8;
          }
        }
        else {
          nvAssertFailedNoLog("i <= NV2080_CTRL_NVLINK_MAX_LINKS",
                              "src/kernel/gpu/nvlink/common_nvlinkapi.c",0x17a);
        }
      }
      else {
        nvDbg_Printf("src/kernel/gpu/nvlink/common_nvlinkapi.c",0x39a,
                     "subdeviceCtrlCmdBusGetNvlinkStatus_IMPL",4,
                     "NVRM: Failed to collect nvlink status info!\n");
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/nvlink/common_nvlinkapi.c",0x38e,
                   "subdeviceCtrlCmdBusGetNvlinkStatus_IMPL",4,
                   "NVRM: Failed to convert bit vector to link masks! 0x%x\n",iVar15);
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/nvlink/common_nvlinkapi.c",900,
                 "subdeviceCtrlCmdBusGetNvlinkStatus_IMPL",4,
                 "NVRM: Failed to convert bit vector to enabled link masks! 0x%x\n",iVar15);
  }
LAB_0041404e:
  portMemFree(lVar17);
  return iVar15;
}


// ===== 004144f0 kioctrlConstructEngine_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kioctrlConstructEngine_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  long lVar1;
  
  *(uint *)(param_2 + 0x17c) = param_3;
  *(undefined4 *)(param_2 + 0x188) = 1;
  lVar1 = __nvoc_dynamicCast(param_2,__nvoc_class_def_OBJENGSTATE);
  *(uint *)(lVar1 + 0x4c) = param_3 | 0x880c7d00;
  (**(code **)(param_2 + 0x170))(param_1,param_2);
  return;
}


// ===== 00414550 kioctrlDestructEngine_IMPL =====

void kioctrlDestructEngine_IMPL(void)

{
  return;
}


// ===== 00414560 knvlinkInbandMsgCallbackDispatcher_WORKITEM =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void knvlinkInbandMsgCallbackDispatcher_WORKITEM(undefined8 param_1,long param_2)

{
  short sVar1;
  code *pcVar2;
  
  sVar1 = *(short *)(param_2 + 0xe);
  if (sVar1 == 1) {
    pcVar2 = gpuFabricProbeReceiveKernelCallback;
  }
  else if (sVar1 == 3) {
    pcVar2 = memorymulticastfabricTeamSetupResponseCallback;
  }
  else {
    if (sVar1 != 6) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x319,
                   "knvlinkInbandMsgCallbackDispatcher_WORKITEM",4,
                   "NVRM: No Callback Registered for type %d. Dropping the msg\n");
      return;
    }
    pcVar2 = gpuFabricProbeReceiveUpdateKernelCallback;
  }
  (*pcVar2)(param_1,0,param_2);
  return;
}


// ===== 004145e0 _knvlinkCheckFabricCliqueId =====

undefined8 _knvlinkCheckFabricCliqueId(long param_1,long param_2)

{
  undefined8 uVar1;
  int local_20;
  int local_1c;
  
  uVar1 = gpuFabricProbeGetFabricCliqueId(*(undefined8 *)(param_1 + 0x4c0),&local_20);
  if ((int)uVar1 == 0) {
    uVar1 = gpuFabricProbeGetFabricCliqueId(*(undefined8 *)(param_2 + 0x4c0),&local_1c);
    if ((int)uVar1 == 0) {
      if (local_20 == local_1c) {
        return 1;
      }
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x11e,"_knvlinkCheckFabricCliqueId",1,
                   "NVRM: GPU %d and Peer GPU %d cliqueId doesn\'t match\n",
                   *(undefined4 *)(param_1 + 0x7a4),*(undefined4 *)(param_2 + 0x7a4));
    }
    else {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x117,"_knvlinkCheckFabricCliqueId",1,
                   "NVRM: GPU %d failed to get fabric clique Id 0x%x\n",
                   *(undefined4 *)(param_2 + 0x7a4),uVar1);
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x10e,"_knvlinkCheckFabricCliqueId",1,
                 "NVRM: GPU %d failed to get fabric clique Id: 0x%x\n",
                 *(undefined4 *)(param_1 + 0x7a4),uVar1);
  }
  return 0;
}


// ===== 00414700 knvlinkLazyErrorRecovery_WORKITEM =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

void knvlinkLazyErrorRecovery_WORKITEM(long param_1,undefined8 param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  undefined8 local_1d8;
  undefined8 local_1d0;
  undefined8 local_1c8;
  undefined8 local_1c0;
  undefined8 local_1b8;
  undefined8 local_1b0;
  undefined8 local_1a8;
  long local_1a0;
  undefined8 local_198;
  undefined1 local_188 [56];
  long local_150;
  undefined8 local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  long local_108;
  undefined8 local_100;
  long local_40;
  
  plVar4 = (long *)serverutilGetFirstClientUnderLock();
  do {
    if (plVar4 == (long *)0x0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x926,"knvlinkLazyErrorRecovery_WORKITEM"
                   ,1,
                   "NVRM: Detected fabric idle with lazy fatal error pending. Triggering fatal recovery!\n"
                  );
      iVar3 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x2080308a,0,0);
      if (iVar3 != 0) {
        nvAssertOkFailedNoLog
                  (iVar3,
                   "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_NVLINK_POST_LAZY_ERROR_RECOVERY, NULL, 0)"
                   ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0x928);
      }
      osRemove1HzCallback(param_1,knvlinkLazyErrorRecovery_WORKITEM,param_2);
      return;
    }
    plVar6 = (long *)*plVar4;
    lVar7 = 0;
    if (plVar6 != (long *)0x0) {
      lVar7 = plVar6[0x20];
    }
    uVar2 = (**(code **)(*plVar6 + 0xd8))(plVar6);
    if ((uVar2 < 2) ||
       (cVar1 = (**(code **)(*plVar6 + 0xe0))(plVar6,uVar2,*(code **)(*plVar6 + 0xe0)),
       cVar1 == '\0')) {
      clientRefIter(&local_1d8,lVar7,0,0x3982b7,0,1);
      local_140 = local_1d8;
      local_138 = local_1d0;
      local_130 = local_1c8;
      local_128 = local_1c0;
      local_120 = local_1b8;
      local_118 = local_1b0;
      local_110 = local_1a8;
      local_108 = local_1a0;
      local_100 = local_198;
      while (cVar1 = clientRefIterNext(local_120,&local_140), cVar1 != '\0') {
        lVar5 = __nvoc_dynamicCast(*(undefined8 *)(local_108 + 8),__nvoc_class_def_P2PApi);
        if ((lVar5 != 0) &&
           ((*(long *)(lVar5 + 0xd8) == param_1 || (*(long *)(lVar5 + 0xe0) == param_1)))) {
          return;
        }
      }
      clientRefIter(local_188,lVar7,0,&DAT_00e0ac20,0,1);
      while (cVar1 = clientRefIterNext(lVar7,local_188), cVar1 != '\0') {
        lVar5 = __nvoc_dynamicCast(*(undefined8 *)(local_150 + 8),__nvoc_class_def_Device);
        if ((lVar5 != 0) && (*(long *)(*(long *)(lVar5 + 0x128) + 0xe0) == param_1)) {
          kchannelGetIter(&local_140,lVar7,local_150);
          while (cVar1 = clientRefOrderedIterNext(lVar7,&local_140), cVar1 != '\0') {
            lVar5 = __nvoc_dynamicCast(*(undefined8 *)(local_40 + 8),__nvoc_class_def_KernelChannel)
            ;
            if (lVar5 != 0) {
              plVar6 = (long *)__nvoc_dynamicCast(*(undefined8 *)(lVar5 + 0x2a0),
                                                  __nvoc_class_def_OBJGVASPACE);
              cVar1 = (**(code **)(*plVar6 + 0x188))(plVar6);
              if (cVar1 != '\0') {
                return;
              }
            }
          }
        }
      }
    }
    plVar4 = (long *)serverutilGetNextClientUnderLock(plVar4);
  } while( true );
}


// ===== 00414a10 knvlinkAbortUncontainedErrorRecovery_WORKITEM =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void knvlinkAbortUncontainedErrorRecovery_WORKITEM(void)

{
  int iVar1;
  long lVar2;
  undefined1 local_19 [9];
  
  lVar2 = gpumgrGetGpu();
  local_19[0] = 0;
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x9a8,
               "knvlinkAbortUncontainedErrorRecovery_WORKITEM",4,
               "NVRM: Failed to recover from uncontained NVLINK error. Triggering Degraded Mode!\n")
  ;
  local_19[0] = 0;
  iVar1 = (**(code **)(lVar2 + 0x3b90))
                    (lVar2 + 0x3b58,*(undefined4 *)(lVar2 + 0x3b34),*(undefined4 *)(lVar2 + 0x3b3c),
                     0x20800aea,local_19,1);
  if (iVar1 == 0) {
    return;
  }
  nvAssertOkFailedNoLog
            (iVar1,
             "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_NVLINK_POST_FATAL_ERROR_RECOVERY, &params, sizeof(params))"
             ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0x9ab);
  return;
}


// ===== 00414ab0 knvlinkUncontainedErrorRecoveryUvmIdle_WORKITEM =====

ulong knvlinkUncontainedErrorRecoveryUvmIdle_WORKITEM(undefined8 param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  
  if (param_2 == 0) {
    uVar2 = nvAssertFailedNoLog("pInfo != NULL","src/kernel/gpu/nvlink/kernel_nvlink.c",0x94e);
    return uVar2;
  }
  uVar2 = osQueueDrainP2PHandler(param_2 + 0x28);
  if ((uint)uVar2 < 0x27) {
    if ((0x4000000009U >> (uVar2 & 0x3f) & 1) == 0) {
LAB_00414afd:
      uVar2 = nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x96e,
                           "knvlinkUncontainedErrorRecoveryUvmIdle_WORKITEM",4,
                           "NVRM: Failed to idle UVM peer traffic with status 0x%x. This will lead to NVLINK Degradation!\n"
                           ,uVar2 & 0xffffffff);
      return uVar2;
    }
  }
  else if ((uint)uVar2 != 0x56) goto LAB_00414afd;
  LOCK();
  uVar1 = *(uint *)(param_2 + 0x20);
  *(uint *)(param_2 + 0x20) = 1;
  UNLOCK();
  return (ulong)uVar1;
}


// ===== 00414b50 knvlinkUncontainedErrorRecoveryReadyCheck_WORKITEM =====

void knvlinkUncontainedErrorRecoveryReadyCheck_WORKITEM(long param_1,long param_2)

{
  int iVar1;
  long local_20;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("pInfo != NULL","src/kernel/gpu/nvlink/kernel_nvlink.c",0x991);
    return;
  }
  iVar1 = tmrGetCurrentTime_IMPL(*(undefined8 *)(param_1 + 0x1b88),&local_20);
  if (iVar1 == 0) {
    if ((ulong)(local_20 - *(long *)(param_2 + 0x10)) < 0x2540be401) {
      return;
    }
    LOCK();
    *(undefined4 *)(param_2 + 0x24) = 1;
    UNLOCK();
  }
  else {
    nvAssertOkFailedNoLog
              (iVar1,"tmrGetCurrentTime(pTmr, &currentTime)","src/kernel/gpu/nvlink/kernel_nvlink.c"
               ,0x993);
  }
  osRemove1HzCallback(param_1,knvlinkUncontainedErrorRecoveryReadyCheck_WORKITEM,param_2);
  return;
}


// ===== 00414c00 knvlinkUncontainedErrorRecovery_WORKITEM =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void knvlinkUncontainedErrorRecovery_WORKITEM(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  bool bVar5;
  undefined1 local_21;
  long local_20;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("pInfo != NULL","src/kernel/gpu/nvlink/kernel_nvlink.c",0x9c2);
    return;
  }
  iVar1 = tmrGetCurrentTime_IMPL(*(undefined8 *)(param_1 + 0x1b88),&local_20);
  uVar3 = 0x9c4;
  pcVar4 = "tmrGetCurrentTime(pTmr, &currentTime)";
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_2 + 0x1c);
    do {
      iVar2 = iVar1;
      LOCK();
      iVar1 = *(int *)(param_2 + 0x1c);
      bVar5 = iVar2 == iVar1;
      if (bVar5) {
        *(int *)(param_2 + 0x1c) = iVar2;
        iVar1 = iVar2;
      }
      UNLOCK();
    } while (!bVar5);
    if (iVar2 != 0) {
      iVar1 = *(int *)(param_2 + 0x20);
      do {
        iVar2 = iVar1;
        LOCK();
        iVar1 = *(int *)(param_2 + 0x20);
        bVar5 = iVar2 == iVar1;
        if (bVar5) {
          *(int *)(param_2 + 0x20) = iVar2;
          iVar1 = iVar2;
        }
        UNLOCK();
      } while (!bVar5);
      if (iVar2 != 0) {
        iVar1 = *(int *)(param_2 + 0x24);
        do {
          iVar2 = iVar1;
          LOCK();
          iVar1 = *(int *)(param_2 + 0x24);
          bVar5 = iVar2 == iVar1;
          if (bVar5) {
            *(int *)(param_2 + 0x24) = iVar2;
            iVar1 = iVar2;
          }
          UNLOCK();
        } while (!bVar5);
        if (iVar2 != 0) {
          local_21 = 1;
          iVar1 = (**(code **)(param_1 + 0x3b90))
                            (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                             *(undefined4 *)(param_1 + 0x3b3c),0x20800aea,&local_21,1);
          if (iVar1 == 0) {
            iVar1 = osQueueWorkItem(param_1,knvlinkUncontainedErrorRecoveryUvmResume_WORKITEM,
                                    param_2,1);
            uVar3 = 0x9eb;
            pcVar4 = 
            "osQueueWorkItem(pGpu, knvlinkUncontainedErrorRecoveryUvmResume_WORKITEM, pInfo, (OsQueueWorkItemFlags){.bDontFreeParams = NV_TRUE})"
            ;
            if (iVar1 == 0) {
              osRemove1HzCallback(param_1,knvlinkUncontainedErrorRecovery_WORKITEM,param_2);
              return;
            }
          }
          else {
            uVar3 = 0x9e0;
            pcVar4 = 
            "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_NVLINK_POST_FATAL_ERROR_RECOVERY, &params, sizeof(params))"
            ;
          }
          goto LAB_00414da0;
        }
      }
    }
    if ((ulong)(local_20 - *(long *)(param_2 + 0x10)) < 0x6fc23ac01) {
      return;
    }
    osRemove1HzCallback(param_1,knvlinkUncontainedErrorRecovery_WORKITEM,param_2);
  }
  else {
LAB_00414da0:
    nvAssertOkFailedNoLog(iVar1,pcVar4,"src/kernel/gpu/nvlink/kernel_nvlink.c",uVar3);
    osRemove1HzCallback(param_1,knvlinkUncontainedErrorRecovery_WORKITEM,param_2);
  }
  iVar1 = osQueueWorkItem(param_1,knvlinkAbortUncontainedErrorRecovery_WORKITEM,0,0x118);
  if (iVar1 == 0) {
    return;
  }
  nvAssertOkFailedNoLog
            (iVar1,
             "osQueueWorkItem(pGpu, knvlinkAbortUncontainedErrorRecovery_WORKITEM, NULL, (OsQueueWorkItemFlags){ .bLockSema = NV_TRUE, .apiLock = WORKITEM_FLAGS_API_LOCK_READ_WRITE, .bLockGpuGroupSubdevice = NV_TRUE})"
             ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0x9fe);
  return;
}


// ===== 00414de0 knvlinkFatalErrorRecovery_WORKITEM =====

ulong knvlinkFatalErrorRecovery_WORKITEM(undefined8 param_1,long param_2)

{
  uint uVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  uVar2 = gpumgrGetGpu();
  uVar3 = rcAndDisableOutstandingClientsWithImportedMemory(uVar2,0xffff);
  if (param_2 != 0) {
    LOCK();
    uVar1 = *(uint *)(param_2 + 0x1c);
    *(uint *)(param_2 + 0x1c) = 1;
    uVar3 = (ulong)uVar1;
    UNLOCK();
  }
  return uVar3;
}


// ===== 00414e20 knvlinkUncontainedErrorRecoveryUvmResume_WORKITEM =====

ulong knvlinkUncontainedErrorRecoveryUvmResume_WORKITEM(undefined8 param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  
  if (param_2 != 0) {
    osQueueResumeP2PHandler(param_2 + 0x28);
    LOCK();
    uVar1 = *(uint *)(param_2 + 0x18);
    *(uint *)(param_2 + 0x18) = 0;
    UNLOCK();
    return (ulong)uVar1;
  }
  uVar2 = nvAssertFailedNoLog("pInfo != NULL","src/kernel/gpu/nvlink/kernel_nvlink.c",0x97d);
  return uVar2;
}


// ===== 00414e70 knvlinkValidateRemapTableSlots_IMPL.part.0 =====

undefined8 knvlinkValidateRemapTableSlots_IMPL_part_0(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = 0;
  while( true ) {
    if (*(int *)(param_1 + 0x1730 + lVar1 * 4) != *(int *)(param_2 + 0x1730 + lVar1 * 4)) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0xc72,
                   "knvlinkValidateRemapTableSlots_IMPL",4,
                   "NVRM: FLA Remap table validation failed for table index = 0x%x\n");
      return 0x40;
    }
    if (*(int *)(param_1 + 0x17b0 + lVar1 * 4) != *(int *)(param_2 + 0x17b0 + lVar1 * 4)) break;
    lVar1 = lVar1 + 1;
    if (lVar1 == 0x20) {
      return 0;
    }
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0xc78,"knvlinkValidateRemapTableSlots_IMPL",4
               ,"NVRM: GPA Remap table validation failed for table index = 0x%x\n");
  return 0x40;
}


// ===== 00414f20 knvlinkIsForcedConfig_IMPL =====

undefined1 knvlinkIsForcedConfig_IMPL(undefined8 param_1,long param_2)

{
  return *(undefined1 *)(param_2 + 0x338);
}


// ===== 00414f30 knvlinkIsNvlinkDefaultEnabled_IMPL =====

undefined1 knvlinkIsNvlinkDefaultEnabled_IMPL(undefined8 param_1,long param_2)

{
  return *(undefined1 *)(param_2 + 0x2e0);
}


// ===== 00414f40 knvlinkIsP2pLoopbackSupportedPerLink_IMPL =====

ulong knvlinkIsP2pLoopbackSupportedPerLink_IMPL(long param_1,long param_2,uint param_3)

{
  ulong uVar1;
  long lVar2;
  
  if (((param_1 != 0) && (param_2 != 0)) && (*(char *)(param_1 + 0x4a6) == '\0')) {
    uVar1 = bitVectorTest_IMPL(param_2 + 0x388,0x40);
    if ((char)uVar1 != '\0') {
      lVar2 = (ulong)param_3 * 0x78 + param_2;
      uVar1 = (ulong)*(byte *)(lVar2 + 0x400);
      if ((*(byte *)(lVar2 + 0x400) != 0) &&
         (((uVar1 = *(ulong *)(param_1 + 0x878), *(int *)(lVar2 + 0x3d0) != (int)(uVar1 >> 0x20) ||
           (*(ushort *)(lVar2 + 0x3d4) != ((ushort)(uVar1 >> 8) & 0xff))) ||
          ((uVar1 = uVar1 & 0xff, *(short *)(lVar2 + 0x3d6) != (short)uVar1 ||
           (uVar1 = 1, *(short *)(lVar2 + 0x3d8) != 0)))))) {
        uVar1 = CONCAT71((int7)(uVar1 >> 8),*(char *)(param_2 + 0x2ef) != '\0');
      }
    }
    return uVar1;
  }
  return 0;
}


// ===== 00415000 knvlinkIsP2pLoopbackSupported_IMPL =====

undefined4 knvlinkIsP2pLoopbackSupported_IMPL(long param_1,long param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 local_30 [8];
  
  if (((param_1 != 0) && (param_2 != 0)) && (*(char *)(param_1 + 0x4a6) == '\0')) {
    bitVectorCopy_IMPL(local_30,0x40,param_2 + 0x388,0x40);
    uVar2 = bitVectorCountTrailingZeros_IMPL(local_30,0x40);
    while( true ) {
      cVar1 = bitVectorTestAllCleared_IMPL(local_30,0x40);
      if (cVar1 != '\0') {
        return 0;
      }
      uVar3 = knvlinkIsP2pLoopbackSupportedPerLink_IMPL(param_1,param_2,uVar2);
      if ((char)uVar3 != '\0') break;
      bitVectorClr_IMPL(local_30,0x40,uVar2);
      uVar2 = bitVectorCountTrailingZeros_IMPL(local_30,0x40);
    }
    return uVar3;
  }
  return 0;
}


// ===== 00415100 knvlinkCheckNvswitchP2pConfig_IMPL =====

undefined4 knvlinkCheckNvswitchP2pConfig_IMPL(long param_1,long param_2,long param_3)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  char cVar5;
  undefined4 uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined8 extraout_RDX;
  uint local_40;
  uint local_3c [3];
  
  uVar1 = *(ulong *)(param_2 + 0x16a8);
  lVar2 = *(long *)(param_1 + 0x1b78);
  lVar3 = *(long *)(lVar2 + 0x830);
  uVar4 = *(ulong *)(*(long *)(param_3 + 0x1ce8) + 0x16a8);
  uVar6 = knvlinkIsGpuConnectedToNvswitch_IMPL();
  if ((char)uVar6 == '\0') {
    if (uVar1 != 0xffffffffffffffff) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x1bf,
                   "knvlinkCheckNvswitchP2pConfig_IMPL",4,
                   "NVRM: non-NVSwitch GPU %d has a valid fabric address\n",
                   *(undefined4 *)(param_1 + 0x7a4));
      return uVar6;
    }
    goto LAB_0041518b;
  }
  if (*(char *)(param_1 + 0x491d) != '\0') {
    return 1;
  }
  cVar5 = gpuFabricProbeIsSupported(param_1);
  if ((cVar5 != '\0') && (cVar5 = gpuFabricProbeIsSupported(param_3), cVar5 != '\0')) {
    cVar5 = _knvlinkCheckFabricCliqueId(param_1,param_3);
    if (cVar5 == '\0') {
      return 0;
    }
    local_40 = 0;
    local_3c[0] = 0;
    iVar7 = gpuFabricProbeGetFabricHealthStatus(*(undefined8 *)(param_1 + 0x4c0),&local_40);
    uVar8 = 0x132;
    if (iVar7 == 0) {
      iVar7 = gpuFabricProbeGetFabricHealthStatus
                        (*(undefined8 *)(param_3 + 0x4c0),local_3c,extraout_RDX,0x132);
      if (iVar7 == 0) {
        if (local_40 != 0) {
          if ((local_40 & 0x30) == 0x10) {
            return 0;
          }
          if ((local_40 & 0xc0) == 0x40) {
            return 0;
          }
          if ((local_40 & 0xe00) != 0) {
            return 0;
          }
          if ((local_40 & 0x3000) == 0x2000) {
            return 0;
          }
        }
        if (local_3c[0] != 0) {
          if ((local_3c[0] & 0x30) == 0x10) {
            return 0;
          }
          if ((local_3c[0] & 0xc0) == 0x40) {
            return 0;
          }
          if ((local_3c[0] & 0xe00) != 0) {
            return 0;
          }
          if ((local_3c[0] & 0x3000) == 0x2000) {
            return 0;
          }
        }
        goto LAB_00415220;
      }
      uVar8 = 0x135;
    }
    nvAssertOkFailedNoLog(iVar7,"status","src/kernel/gpu/nvlink/kernel_nvlink.c",uVar8);
    if ((char)iVar7 == '\0') {
      return 0;
    }
  }
LAB_00415220:
  if (uVar1 == 0xffffffffffffffff) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x1aa,"knvlinkCheckNvswitchP2pConfig_IMPL",
                 4,"NVRM: GPU %d doesn\'t have a fabric address\n",*(undefined4 *)(param_1 + 0x7a4))
    ;
    return 0;
  }
  if (((param_1 != param_3) && (uVar4 < lVar3 * 0x100000 + uVar1)) && (uVar1 <= uVar4)) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x1b3,"knvlinkCheckNvswitchP2pConfig_IMPL",
                 4,"NVRM: GPU %d doesn\'t have a unique fabric address\n",
                 *(undefined4 *)(param_1 + 0x7a4));
    return 0;
  }
LAB_0041518b:
  if (*(char *)(lVar2 + 0x454) != '\0') {
    lVar2 = *(long *)(param_2 + 0x16b0);
    uVar6 = knvlinkIsGpuConnectedToNvswitch_IMPL(param_1,param_2);
    if ((char)uVar6 == '\0') {
      if (lVar2 != -1) {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x172,
                     "_knvlinkCheckNvswitchEgmAddressSanity",4,
                     "NVRM: non-NVSwitch GPU %d has a valid EGM fabric address\n",
                     *(undefined4 *)(param_1 + 0x7a4));
        return uVar6;
      }
    }
    else if (*(char *)(param_1 + 0x491d) == '\0') {
      cVar5 = gpuFabricProbeIsSupported(param_1);
      if (((cVar5 != '\0') && (cVar5 = gpuFabricProbeIsSupported(param_3), cVar5 != '\0')) &&
         (cVar5 = _knvlinkCheckFabricCliqueId(param_1,param_3), cVar5 == '\0')) {
        return 0;
      }
      if (lVar2 == -1) {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x167,
                     "_knvlinkCheckNvswitchEgmAddressSanity",4,
                     "NVRM: GPU %d doesn\'t have a EGM fabric address\n",
                     *(undefined4 *)(param_1 + 0x7a4));
        return 0;
      }
    }
  }
  return 1;
}


// ===== 00415490 knvlinkInbandMsgCallbackDispatcher_IMPL =====

ulong knvlinkInbandMsgCallbackDispatcher_IMPL
                (undefined8 param_1,undefined8 param_2,undefined4 param_3,long param_4)

{
  ushort uVar1;
  long lVar2;
  ulong uVar3;
  undefined1 *puVar4;
  
  uVar1 = *(ushort *)(param_4 + 0xe);
  if (8 < uVar1) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x340,
                 "knvlinkInbandMsgCallbackDispatcher_IMPL",4,
                 "NVRM: Message type received is Out of Bounds. Dropping  the msg\n");
    return 0x3f;
  }
  if (uVar1 == 1) {
    puVar4 = nvlink_inband_callbacks;
  }
  else if (uVar1 == 3) {
    puVar4 = (undefined1 *)0xd6f118;
  }
  else {
    if (uVar1 != 6) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x350,
                   "knvlinkInbandMsgCallbackDispatcher_IMPL",4,
                   "NVRM: No Callback Registered for type %d. Dropping the msg\n");
      return 0x3f;
    }
    puVar4 = (undefined1 *)0xd6f130;
  }
  lVar2 = portMemAllocNonPaged(0x1404);
  if (lVar2 != 0) {
    *(undefined4 *)(lVar2 + 0x1400) = param_3;
    portMemCopy(lVar2,param_3,param_4,param_3);
    uVar3 = osQueueWorkItem(param_1,knvlinkInbandMsgCallbackDispatcher_WORKITEM,lVar2,
                            *(undefined4 *)(puVar4 + 0x10));
    if ((int)uVar3 != 0) {
      portMemFree(lVar2);
      return uVar3 & 0xffffffff;
    }
    return uVar3;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x359,
               "knvlinkInbandMsgCallbackDispatcher_IMPL",4,"NVRM: Out of memory, Dropping message\n"
              );
  return 0x51;
}


// ===== 00415610 knvlinkGetEnabledLinkMask_IMPL =====

long knvlinkGetEnabledLinkMask_IMPL(undefined8 param_1,long param_2)

{
  return param_2 + 0x388;
}


// ===== 00415620 knvlinkGetDiscoveredLinkMask_IMPL =====

long knvlinkGetDiscoveredLinkMask_IMPL(undefined8 param_1,long param_2)

{
  return param_2 + 0x350;
}


// ===== 00415630 knvlinkGetNumLinksToSystem_IMPL =====

uint knvlinkGetNumLinksToSystem_IMPL(undefined8 param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_2 + 0x14c0);
  uVar2 = 0;
  if (uVar1 != 0) {
    uVar1 = uVar1 - (uVar1 >> 1 & 0x55555555);
    uVar1 = (uVar1 & 0x33333333) + (uVar1 >> 2 & 0x33333333);
    uVar2 = ((uVar1 >> 4) + uVar1 & 0xf0f0f0f) * 0x1010101 >> 0x18;
  }
  return uVar2;
}


// ===== 00415680 knvlinkGetNumLinksToPeer_IMPL =====

ulong knvlinkGetNumLinksToPeer_IMPL(undefined8 param_1,long param_2,long param_3)

{
  ulong uVar1;
  
  if (*(long *)(param_3 + 0x1ce8) == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x3ff,"knvlinkGetLinkMaskToPeer_IMPL",1,
                 "NVRM: on GPU%d NVLink is disabled.\n",*(undefined4 *)(param_3 + 0x7a4));
    return 0;
  }
  if ((((*(char *)(param_2 + 0x14a8) == '\0') &&
       (*(char *)(*(long *)(param_3 + 0x1ce8) + 0x14a8) == '\0')) &&
      (*(char *)(param_2 + 0x338) == '\0')) &&
     (uVar1 = *(ulong *)(param_2 + 0x14c8 + (ulong)*(uint *)(param_3 + 0x7a4) * 8), uVar1 != 0)) {
    uVar1 = uVar1 - (uVar1 >> 1 & 0x5555555555555555);
    uVar1 = (uVar1 & 0x3333333333333333) + (uVar1 >> 2 & 0x3333333333333333);
    return ((uVar1 >> 4) + uVar1 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38;
  }
  return 0;
}


// ===== 00415760 knvlinkGetP2pConnectionStatus_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int knvlinkGetP2pConnectionStatus_IMPL(long param_1,long param_2,long param_3)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined4 uVar7;
  int local_4c;
  undefined4 local_40 [4];
  
  if (param_3 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x1ea,"knvlinkGetP2pConnectionStatus_IMPL",
                 1,"NVRM: Invalid pPeerGpu.\n");
    return 0x1f;
  }
  if ((param_1 == param_3) && (*(char *)(param_1 + 0x4a6) != '\0')) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x1f2,"knvlinkGetP2pConnectionStatus_IMPL",
                 1,"NVRM: loopback P2P on GPU%u disabled by regkey\n",
                 *(undefined4 *)(param_1 + 0x7a4));
    return 0x56;
  }
  lVar1 = *(long *)(param_3 + 0x1ce8);
  if (lVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x1fe,"knvlinkGetP2pConnectionStatus_IMPL",
                 1,"NVRM: Input mask contains a GPU on which NVLink is disabled.\n");
    return 0x1f;
  }
  if (*(char *)(param_2 + 0x14a8) == '\0') {
    if (*(char *)(lVar1 + 0x14a8) == '\0') {
      if (*(char *)(param_2 + 0x338) != '\0') {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x21c,
                     "knvlinkGetP2pConnectionStatus_IMPL",1,
                     "NVRM: NVLink P2P is supported between GPU%d and GPU%d\n",
                     *(undefined4 *)(param_1 + 0x7a4),*(undefined4 *)(param_3 + 0x7a4));
        return 0;
      }
      iVar3 = knvlinkCoreGetRemoteDeviceInfo_IMPL(param_1,param_2);
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar3 = bitVectorGetSlice_IMPL(param_2 + 0x388,0x40,0,0x3f,local_40);
      uVar4 = local_40[0];
      if (iVar3 != 0) {
        nvAssertFailedNoLog("(bitVectorGetSlice(pSrc, rangeMake(0, 63), &localMask) == NV_OK)",
                            "generated/g_kernel_nvlink_nvoc.h",0x8fd);
        uVar4 = 0;
      }
      iVar3 = (**(code **)(param_2 + 0x1b8))(param_1,param_2,uVar4);
      if (iVar3 != 0) {
        return iVar3;
      }
      local_4c = knvlinkGetNumLinksToPeer_IMPL(param_1,param_2,param_3);
      if (local_4c != 0) {
LAB_00415950:
        iVar3 = knvlinkGetNumLinksToPeer_IMPL(param_3,lVar1,param_1);
        if (iVar3 != local_4c) {
          iVar3 = knvlinkCoreGetRemoteDeviceInfo_IMPL(param_3,lVar1);
          if (iVar3 != 0) {
            return iVar3;
          }
          iVar3 = bitVectorGetSlice_IMPL(lVar1 + 0x388,0x40,0,0x3f,local_40);
          if (iVar3 != 0) {
            nvAssertFailedNoLog("(bitVectorGetSlice(pSrc, rangeMake(0, 63), &localMask) == NV_OK)",
                                "generated/g_kernel_nvlink_nvoc.h",0x8fd);
            local_40[0] = 0;
          }
          iVar3 = (**(code **)(lVar1 + 0x1b8))(param_3,lVar1,local_40[0]);
          if (iVar3 != 0) {
            return iVar3;
          }
        }
        iVar3 = knvlinkGetNumLinksToPeer_IMPL(param_3,lVar1,param_1);
        if (iVar3 == local_4c) {
          if (*(char *)(param_2 + 0x16c0) == *(char *)(lVar1 + 0x16c0)) {
            cVar2 = knvlinkCheckNvswitchP2pConfig_IMPL(param_1,param_2,param_3);
            if (cVar2 == '\x01') {
              cVar2 = knvlinkCheckNvswitchP2pConfig_IMPL(param_3,lVar1,param_1);
              if (cVar2 == '\x01') {
                nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x26f,
                             "knvlinkGetP2pConnectionStatus_IMPL",1,
                             "NVRM: NVLink P2P is supported between GPU%d and GPU%d\n",
                             *(undefined4 *)(param_1 + 0x7a4),*(undefined4 *)(param_3 + 0x7a4));
                return 0;
              }
              nvCheckFailedNoLog(1,"knvlinkCheckNvswitchP2pConfig(pGpu1, pKernelNvlink1, pGpu0)",
                                 "src/kernel/gpu/nvlink/kernel_nvlink.c",0x26b);
            }
            else {
              nvCheckFailedNoLog(1,"knvlinkCheckNvswitchP2pConfig(pGpu0, pKernelNvlink0, pGpu1)",
                                 "src/kernel/gpu/nvlink/kernel_nvlink.c",0x267);
            }
          }
          else {
            nvCheckFailedNoLog(1,"(pKernelNvlink0->nvlinkBwMode == pKernelNvlink1->nvlinkBwMode)",
                               "src/kernel/gpu/nvlink/kernel_nvlink.c",0x263);
          }
        }
        else {
          nvCheckFailedNoLog(1,
                             "(knvlinkGetNumLinksToPeer(pGpu1, pKernelNvlink1, pGpu0) == numPeerLinks)"
                             ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0x25e);
        }
        return 0x40;
      }
      cVar2 = gpuFabricProbeIsSupported(param_3);
      if (cVar2 != '\0') {
        knvlinkCoreGetRemoteDeviceInfo_IMPL(param_3,lVar1);
        iVar3 = bitVectorGetSlice_IMPL(lVar1 + 0x388,0x40,0,0x3f,local_40);
        if (iVar3 == 0) {
          local_4c = local_40[0];
        }
        else {
          nvAssertFailedNoLog("(bitVectorGetSlice(pSrc, rangeMake(0, 63), &localMask) == NV_OK)",
                              "generated/g_kernel_nvlink_nvoc.h",0x8fd);
          local_4c = 0;
        }
        iVar3 = (**(code **)(lVar1 + 0x1b8))(param_3,lVar1,local_4c);
        if (iVar3 != 0) {
          return iVar3;
        }
        local_4c = knvlinkGetNumLinksToPeer_IMPL(param_1,param_2,param_3);
        if (local_4c != 0) goto LAB_00415950;
      }
      uVar4 = *(undefined4 *)(param_3 + 0x7a4);
      pcVar6 = "NVRM: NVLink P2P is NOT supported between between GPU%d and GPU%d\n";
      uVar5 = 0x276;
      uVar7 = *(undefined4 *)(param_1 + 0x7a4);
    }
    else {
      uVar4 = *(undefined4 *)(param_3 + 0x7a4);
      pcVar6 = "NVRM: NVLink P2P is NOT supported between GPU%d and GPU%d\n";
      uVar5 = 0x20f;
      uVar7 = *(undefined4 *)(param_1 + 0x7a4);
    }
  }
  else {
    uVar4 = *(undefined4 *)(param_3 + 0x7a4);
    pcVar6 = "NVRM: NVLink P2P is NOT supported between GPU%d and GPU%d\n";
    uVar5 = 0x206;
    uVar7 = *(undefined4 *)(param_1 + 0x7a4);
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",uVar5,"knvlinkGetP2pConnectionStatus_IMPL",1,
               pcVar6,uVar7,uVar4);
  return 0x56;
}


// ===== 00415cf0 knvlinkIsNvlinkP2pSupported_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

bool knvlinkIsNvlinkP2pSupported_IMPL(undefined8 param_1,long param_2,undefined8 param_3)

{
  char cVar1;
  int iVar2;
  
  if (param_2 == 0) {
    return false;
  }
  cVar1 = (**(code **)(param_2 + 600))(param_2);
  if (cVar1 != '\0') {
    return false;
  }
  iVar2 = knvlinkGetP2pConnectionStatus_IMPL(param_1,param_2,param_3);
  return iVar2 == 0;
}


// ===== 00415d60 knvlinkGetLinkMaskToPeer_IMPL =====

undefined8 knvlinkGetLinkMaskToPeer_IMPL(undefined8 param_1,long param_2,long param_3)

{
  if (*(long *)(param_3 + 0x1ce8) == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x3ff,"knvlinkGetLinkMaskToPeer_IMPL",1,
                 "NVRM: on GPU%d NVLink is disabled.\n",*(undefined4 *)(param_3 + 0x7a4));
    return 0;
  }
  if (((*(char *)(param_2 + 0x14a8) == '\0') &&
      (*(char *)(*(long *)(param_3 + 0x1ce8) + 0x14a8) == '\0')) &&
     (*(char *)(param_2 + 0x338) == '\0')) {
    return *(undefined8 *)(param_2 + 0x14c8 + (ulong)*(uint *)(param_3 + 0x7a4) * 8);
  }
  return 0;
}


// ===== 00415de0 knvlinkSetPowerFeatures_IMPL =====

void knvlinkSetPowerFeatures_IMPL(undefined8 param_1,long param_2)

{
  if (*(int *)(param_2 + 0x314) != 8) {
    return;
  }
  *(bool *)(param_2 + 0x2e1) = *(char *)(param_2 + 0x1609) == '\0';
  return;
}


// ===== 00415e00 knvlinkIsNvswitchProxyPresent_IMPL =====

undefined1 knvlinkIsNvswitchProxyPresent_IMPL(undefined8 param_1,long param_2)

{
  return *(undefined1 *)(param_2 + 0x16a0);
}


// ===== 00415e10 knvlinkIsP2PActive_IMPL =====

undefined4 knvlinkIsP2PActive_IMPL(long param_1)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  long *plVar4;
  undefined8 uVar5;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  long local_90;
  undefined8 local_88;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  undefined8 local_30;
  
  lVar3 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x4a18),__nvoc_class_def_FABRIC_VASPACE);
  if ((lVar3 == 0) || (cVar1 = fabricvaspaceIsInUse_IMPL(lVar3), cVar1 == '\0')) {
    plVar4 = (long *)serverutilGetFirstClientUnderLock();
    if (plVar4 == (long *)0x0) {
      uVar2 = 0;
    }
    else {
      do {
        uVar5 = 0;
        if (*plVar4 != 0) {
          uVar5 = *(undefined8 *)(*plVar4 + 0x100);
        }
        clientRefIter(&local_c8,uVar5,0,0x3982b7,0,1);
        local_70 = local_c8;
        local_68 = local_c0;
        local_60 = local_b8;
        local_58 = local_b0;
        local_50 = local_a8;
        local_48 = local_a0;
        local_40 = local_98;
        local_38 = local_90;
        local_30 = local_88;
        while (uVar2 = clientRefIterNext(local_50,&local_70), (char)uVar2 != '\0') {
          lVar3 = __nvoc_dynamicCast(*(undefined8 *)(local_38 + 8),__nvoc_class_def_P2PApi);
          if (((lVar3 != 0) && ((*(byte *)(lVar3 + 0x100) & 0x10) == 0)) &&
             ((*(long *)(lVar3 + 0xd8) == param_1 || (*(long *)(lVar3 + 0xe0) == param_1))))
          goto LAB_00415f4b;
        }
        plVar4 = (long *)serverutilGetNextClientUnderLock(plVar4);
      } while (plVar4 != (long *)0x0);
    }
  }
  else {
LAB_00415f4b:
    uVar2 = 1;
  }
  return uVar2;
}


// ===== 00415f90 knvlinkFatalErrorRecovery_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong knvlinkFatalErrorRecovery_IMPL(long param_1,long param_2,char param_3,char param_4)

{
  int *piVar1;
  char *pcVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  ulong uVar8;
  bool bVar9;
  int local_44;
  undefined8 local_40 [2];
  
  pcVar7 = (char *)gpumgrGetNvlinkRecoveryInfo_IMPL(*(undefined8 *)(param_1 + 0x878));
  if (param_4 != '\0') {
    osSchedule1HzCallback(param_1,knvlinkLazyErrorRecovery_WORKITEM,0,1);
    return 0;
  }
  osRemove1HzCallback(param_1,knvlinkLazyErrorRecovery_WORKITEM,0);
  if ((param_3 == '\0') || (*(char *)(param_2 + 0x2f1) == '\0')) {
    (**(code **)(param_1 + 0x100))(param_1);
    uVar8 = osQueueWorkItem(param_1,knvlinkFatalErrorRecovery_WORKITEM,0,0x118);
    return uVar8;
  }
  if ((pcVar7 != (char *)0x0) && (*pcVar7 != '\0')) {
    uVar3 = *(undefined8 *)(param_1 + 0x1b88);
    piVar1 = (int *)(pcVar7 + 0x18);
    iVar5 = *(int *)(pcVar7 + 0x18);
    do {
      iVar4 = iVar5;
      LOCK();
      iVar5 = *piVar1;
      bVar9 = iVar4 == iVar5;
      if (bVar9) {
        *piVar1 = iVar4;
        iVar5 = iVar4;
      }
      UNLOCK();
    } while (!bVar9);
    if (iVar4 == 0) {
      LOCK();
      *piVar1 = 1;
      UNLOCK();
      LOCK();
      pcVar7[0x1c] = '\0';
      pcVar7[0x1d] = '\0';
      pcVar7[0x1e] = '\0';
      pcVar7[0x1f] = '\0';
      UNLOCK();
      LOCK();
      pcVar7[0x20] = '\0';
      pcVar7[0x21] = '\0';
      pcVar7[0x22] = '\0';
      pcVar7[0x23] = '\0';
      UNLOCK();
      LOCK();
      pcVar2 = pcVar7 + 0x24;
      pcVar2[0] = '\0';
      pcVar2[1] = '\0';
      pcVar2[2] = '\0';
      pcVar2[3] = '\0';
      UNLOCK();
      uVar6 = tmrGetCurrentTime_IMPL(uVar3,pcVar7 + 0x10,*(undefined4 *)pcVar2);
      uVar8 = (ulong)uVar6;
      if (uVar6 == 0) {
        uVar6 = gpuGetGidInfo_IMPL(param_1,local_40,&local_44,2);
        uVar8 = (ulong)uVar6;
        if (uVar6 == 0) {
          if (local_44 == 0x10) {
            portMemCopy(pcVar7 + 0x28,0x10,local_40[0],0x10);
            portMemFree(local_40[0]);
            uVar6 = osQueueWorkItem(param_1,knvlinkFatalErrorRecovery_WORKITEM,pcVar7,0x119);
            uVar8 = (ulong)uVar6;
            if (uVar6 == 0) {
              uVar6 = osQueueWorkItem(param_1,knvlinkUncontainedErrorRecoveryUvmIdle_WORKITEM,pcVar7
                                      ,1);
              uVar8 = (ulong)uVar6;
              if (uVar6 == 0) {
                uVar6 = osSchedule1HzCallback
                                  (param_1,knvlinkUncontainedErrorRecoveryReadyCheck_WORKITEM,pcVar7
                                   ,1);
                uVar8 = (ulong)uVar6;
                if (uVar6 == 0) {
                  uVar6 = osSchedule1HzCallback
                                    (param_1,knvlinkUncontainedErrorRecovery_WORKITEM,pcVar7,1);
                  uVar8 = (ulong)uVar6;
                  if (uVar6 == 0) {
                    return 0;
                  }
                  nvCheckOkFailedNoLog
                            (4,uVar6,
                             "osSchedule1HzCallback(pGpu, knvlinkUncontainedErrorRecovery_WORKITEM, pInfo, NV_OS_1HZ_REPEAT)"
                             ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0xa6a);
                }
                else {
                  nvCheckOkFailedNoLog
                            (4,uVar6,
                             "osSchedule1HzCallback(pGpu, knvlinkUncontainedErrorRecoveryReadyCheck_WORKITEM, pInfo, NV_OS_1HZ_REPEAT)"
                             ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0xa65);
                }
              }
              else {
                nvCheckOkFailedNoLog
                          (4,uVar6,
                           "osQueueWorkItem(pGpu, knvlinkUncontainedErrorRecoveryUvmIdle_WORKITEM, pInfo, (OsQueueWorkItemFlags){.bDontFreeParams = NV_TRUE})"
                           ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0xa5c);
              }
            }
            else {
              nvCheckOkFailedNoLog
                        (4,uVar6,
                         "osQueueWorkItem(pGpu, knvlinkFatalErrorRecovery_WORKITEM, pInfo, (OsQueueWorkItemFlags){ .bLockSema = NV_TRUE, .apiLock = WORKITEM_FLAGS_API_LOCK_READ_WRITE, .bLockGpuGroupSubdevice = NV_TRUE, .bDontFreeParams = NV_TRUE})"
                         ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0xa4f);
            }
          }
          else {
            nvAssertFailedNoLog("uuidLength == sizeof(pInfo->uuid)",
                                "src/kernel/gpu/nvlink/kernel_nvlink.c",0xa48);
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (uVar6,"gpuGetGidInfo(pGpu, &pUuid, &uuidLength, flags)",
                     "src/kernel/gpu/nvlink/kernel_nvlink.c",0xa47);
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (uVar6,"tmrGetCurrentTime(pTmr, &pInfo->startTime)",
                   "src/kernel/gpu/nvlink/kernel_nvlink.c",0xa3e);
      }
      goto LAB_004161e6;
    }
    nvAssertFailedNoLog("NVLINK Uncontained error recovery re-triggered unexpectedly!",
                        "src/kernel/gpu/nvlink/kernel_nvlink.c",0xa34);
  }
  uVar8 = 0x40;
LAB_004161e6:
  uVar6 = osQueueWorkItem(param_1,knvlinkAbortUncontainedErrorRecovery_WORKITEM,0,0x118);
  if ((uVar6 != 0) &&
     (nvAssertOkFailedNoLog
                (uVar6,
                 "osQueueWorkItem(pGpu, knvlinkAbortUncontainedErrorRecovery_WORKITEM, NULL, (OsQueueWorkItemFlags){ .bLockSema = NV_TRUE, .apiLock = WORKITEM_FLAGS_API_LOCK_READ_WRITE, .bLockGpuGroupSubdevice = NV_TRUE})"
                 ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0xa7e), (int)uVar8 == 0)) {
    uVar8 = (ulong)uVar6;
  }
  return uVar8;
}


// ===== 00416310 knvlinkExecGspRmRpc_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int knvlinkExecGspRmRpc_IMPL
              (long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
              undefined4 param_5)

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
    iVar4 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),param_3,param_4,param_5);
  }
  else {
    iVar4 = rmGpuGroupLockAcquire(*(undefined4 *)(param_1 + 0x7a4),2,2,0x20002,local_3c);
    uVar1 = local_3c[0];
    if (iVar4 == 0) {
      iVar4 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),param_3,param_4,param_5);
      if ((uVar1 & ~uVar3) != 0) {
        rmGpuGroupLockRelease(uVar1 & ~uVar3,0);
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0xaa5,"knvlinkExecGspRmRpc_IMPL",4,
                   "NVRM: Failed to acquire locks for gpumask 0x%x\n",local_3c[0]);
    }
  }
  return iVar4;
}


// ===== 00416490 knvlinkUpdateCurrentConfig_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int knvlinkUpdateCurrentConfig_IMPL(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  bool bVar3;
  long lVar4;
  char cVar5;
  int iVar6;
  ulong uVar7;
  undefined1 local_41;
  undefined8 local_40 [2];
  
  lVar4 = g_pSys;
  local_40[0] = 0;
  iVar6 = osAcquireRmSema(*(undefined8 *)(g_pSys + 0x160));
  if (iVar6 != 0) {
    return 0;
  }
  bVar3 = false;
  cVar5 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_1 + 0x7a4));
  if (cVar5 == '\0') {
    bVar3 = true;
    iVar6 = rmDeviceGpuLocksAcquire(param_1,0,0x20002);
    if (iVar6 != 0) {
      nvAssertFailedNoLog(&DAT_00d6d7d8,"src/kernel/gpu/nvlink/kernel_nvlink.c",0x2a5);
      goto LAB_004165d8;
    }
  }
  (**(code **)(param_2 + 0x1c8))(param_1,param_2);
  portMemSet(&local_41,0,1);
  if (*(char *)(param_1 + 0x909) != '\0') {
    threadStateResetTimeout(param_1);
  }
  iVar6 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a78,&local_41,1);
  if (iVar6 == 0) {
    *(undefined1 *)(param_1 + 0x499) = local_41;
    iVar6 = kceFindFirstInstance_IMPL(param_1,local_40);
    if ((iVar6 == 0) && (uVar1 = *(uint *)(param_1 + 0x8fc), uVar1 != 0)) {
      uVar7 = 0;
      do {
        if (((uVar7 < 0x14) && (lVar2 = *(long *)(param_1 + 0x1c30 + uVar7 * 8), lVar2 != 0)) &&
           (*(char *)(lVar2 + 0x2d4) != '\0')) {
          iVar6 = kceTopLevelPceLceMappingsUpdate_IMPL(param_1);
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 != uVar1);
      if (iVar6 != 0) {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x2d5,"knvlinkUpdateCurrentConfig_IMPL"
                     ,4,"NVRM: Failed to update PCE-LCE mappings\n");
      }
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x2c4,"knvlinkUpdateCurrentConfig_IMPL",4,
                 "NVRM: Updating current NVLink config failed\n");
  }
  if (bVar3) {
    rmDeviceGpuLocksRelease(param_1,0,0);
  }
LAB_004165d8:
  osReleaseRmSema(*(undefined8 *)(lVar4 + 0x160),0);
  return iVar6;
}


// ===== 004166b0 knvlinkSendInbandData_IMPL =====

int knvlinkSendInbandData_IMPL(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  undefined1 local_40 [24];
  
  timeoutSet(param_1 + 0x1af0,local_40,4000000,0);
  iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20803040,param_3,0x1404);
  if (iVar1 == 3) {
    iVar2 = timeoutCheck(param_1 + 0x1af0,local_40,0x386);
    iVar1 = 0;
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x389,"knvlinkSendInbandData_IMPL",4,
                   "NVRM: Timed out retrying to send inband data\n");
      return iVar2;
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x382,"knvlinkSendInbandData_IMPL",4,
                 "NVRM: Failed to send inband data: %llx\n",iVar1);
  }
  return iVar1;
}


// ===== 00416790 knvlinkSetLinkMaskToPeer_IMPL =====

int knvlinkSetLinkMaskToPeer_IMPL(long param_1,long param_2,long param_3,long param_4)

{
  int iVar1;
  undefined4 local_38 [2];
  long local_30;
  
  if (*(long *)(param_2 + 0x14c8 + (ulong)*(uint *)(param_3 + 0x7a4) * 8) != param_4) {
    *(long *)(param_2 + 8 + ((ulong)*(uint *)(param_3 + 0x7a4) + 0x298) * 8) = param_4;
    portMemSet(local_38,0,0x10);
    local_38[0] = *(undefined4 *)(param_3 + 0x7a4);
    local_30 = param_4;
    if (*(char *)(param_1 + 0x909) != '\0') {
      threadStateResetTimeout(param_1);
    }
    iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a7d,local_38,0x10);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x449,"knvlinkSetLinkMaskToPeer_IMPL",4,
                   "NVRM: Failed to sync peerLinksMask from GPU%d to GPU%d\n",
                   *(undefined4 *)(param_1 + 0x7a4),*(undefined4 *)(param_3 + 0x7a4));
      return iVar1;
    }
  }
  return 0;
}


// ===== 00416890 knvlinkPrepareForXVEReset_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int knvlinkPrepareForXVEReset_IMPL(long param_1,long param_2,char param_3)

{
  ulong *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  code *pcVar7;
  undefined8 uVar8;
  long lVar9;
  int iVar10;
  ulong uVar11;
  int iVar12;
  undefined4 local_6c;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48 [2];
  undefined4 local_40;
  undefined4 local_3c;
  
  if (*(char *)(param_2 + 0x338) == '\0') {
    if ((6 < *(uint *)(param_2 + 0x314)) || (*(char *)(g_pSys + 0x6b) == '\0')) {
      iVar3 = gpumgrGetGpuAttachInfo(0,&local_4c);
      if (iVar3 == 0) {
        local_50 = 0;
        iVar10 = 0;
        iVar12 = 0;
        while (lVar6 = gpumgrGetNextGpu(local_4c,&local_50), lVar6 != 0) {
          lVar9 = *(long *)(lVar6 + 0x1ce8);
          if ((((param_1 != lVar6) && (lVar9 != 0)) &&
              (iVar4 = knvlinkGetNumLinksToPeer_IMPL(lVar6,lVar9,param_1), iVar4 != 0)) &&
             (((*(char *)(lVar6 + 0x44f) == '\0' && (*(char *)(lVar6 + 0x450) == '\0')) &&
              ((*(char *)(lVar6 + 0x451) == '\0' &&
               ((*(char *)(lVar6 + 0x461) == '\0' && (*(char *)(lVar6 + 0x455) == '\0')))))))) {
            cVar2 = rmcfg_IsAMPERE_CLASSIC_GPUSorBetter(param_1);
            if (cVar2 == '\0') {
              pcVar7 = *(code **)(lVar9 + 0x1e0);
              iVar10 = 0xff;
LAB_00416b3f:
              iVar10 = (*pcVar7)(lVar6,lVar9,0,iVar10);
            }
            else {
              iVar4 = (**(code **)(*(long *)(&DAT_00001b90 + lVar6) + 0x288))
                                (lVar6,*(long *)(&DAT_00001b90 + lVar6),param_1);
              if (iVar4 != -1) {
                pcVar7 = *(code **)(lVar9 + 0x1e0);
                iVar10 = 1 << ((byte)iVar4 & 0x1f);
                goto LAB_00416b3f;
              }
            }
            if ((iVar10 != 0) &&
               (nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x4b3,
                             "knvlinkPrepareForXVEReset_IMPL",4,
                             "NVRM: failed to reset HSHUB on GPU%u while preparing for GPU%u XVE reset (0x%x)\n"
                             ,*(undefined4 *)(lVar6 + 0x7a4),*(undefined4 *)(param_1 + 0x7a4),iVar10
                            ), iVar12 == 0)) {
              iVar12 = iVar10;
            }
          }
        }
        if (((((param_1 != 0) && (*(char *)(param_1 + 0x44f) == '\0')) &&
             (*(char *)(param_1 + 0x450) == '\0')) &&
            ((*(char *)(param_1 + 0x451) == '\0' && (*(char *)(param_1 + 0x461) == '\0')))) &&
           (*(char *)(param_1 + 0x455) == '\0')) {
          iVar10 = (**(code **)(param_2 + 0x1e0))(param_1,param_2,1,0xff,0);
        }
        if (iVar10 != 0) {
          uVar8 = nvstatusToString(iVar10);
          nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x4c2,
                       "knvlinkPrepareForXVEReset_IMPL",4,
                       "NVRM: failed to reset HSHUB on GPU%u while preparing XVE reset: %s (0x%x)\n"
                       ,*(undefined4 *)(param_1 + 0x7a4),uVar8,iVar10);
          if (iVar12 == 0) {
            iVar12 = iVar10;
          }
        }
        if ((param_3 != '\0') || (*(char *)(param_2 + 0x2ed) == '\0')) {
          iVar3 = knvlinkCoreShutdownDeviceLinks_IMPL(param_1,param_2,param_3);
          if (iVar3 != 0) {
            uVar8 = nvstatusToString(iVar3);
            nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x4d6,
                         "knvlinkPrepareForXVEReset_IMPL",4,
                         "NVRM: failed to shutdown links on GPU%u while preparing XVE reset: %s (0x%x)\n"
                         ,*(undefined4 *)(param_1 + 0x7a4),uVar8,iVar3);
            if (iVar12 == 0) {
              iVar12 = iVar3;
            }
          }
          if (*(char *)(param_2 + 0x2e7) != '\0') {
            iVar3 = knvlinkCoreResetDeviceLinks_IMPL(param_1,param_2);
            if (iVar3 == 0) {
              bitVectorCopy_IMPL(&local_40,0x40,param_2 + 0x388,0x40);
              uVar5 = bitVectorCountTrailingZeros_IMPL(&local_40,0x40);
              while( true ) {
                uVar11 = (ulong)uVar5;
                cVar2 = bitVectorTestAllCleared_IMPL(&local_40,0x40);
                if (cVar2 != '\0') break;
                *(ulong *)(param_2 + 0x14b8) =
                     *(ulong *)(param_2 + 0x14b8) | 1L << ((byte)uVar5 & 0x3f);
                bitVectorClr_IMPL(param_2 + 0x370,0x40,uVar11);
                lVar6 = uVar11 * 0x78 + param_2;
                if ((((*(long *)(lVar6 + 0x3f0) == 2) &&
                     (lVar9 = gpumgrGetGpuFromBusInfo
                                        (*(undefined4 *)(lVar6 + 0x3d0),
                                         *(undefined1 *)(lVar6 + 0x3d4),
                                         *(undefined1 *)(lVar6 + 0x3d6)), lVar9 != 0)) &&
                    (*(char *)(lVar9 + 0x44f) == '\0')) &&
                   (((*(char *)(lVar9 + 0x450) == '\0' && (*(char *)(lVar9 + 0x451) == '\0')) &&
                    (*(char *)(lVar9 + 0x461) == '\0')))) {
                  lVar9 = *(long *)(lVar9 + 0x1ce8);
                  puVar1 = (ulong *)(lVar9 + 0x14b8);
                  *puVar1 = *puVar1 | 1L << ((byte)*(undefined4 *)(lVar6 + 0x3f8) & 0x3f);
                  bitVectorClr_IMPL(lVar9 + 0x370,0x40);
                }
                bitVectorClr_IMPL(&local_40,0x40,uVar11);
                uVar5 = bitVectorCountTrailingZeros_IMPL(&local_40,0x40);
              }
            }
            else {
              uVar8 = nvstatusToString(iVar3);
              nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x4e7,
                           "knvlinkPrepareForXVEReset_IMPL",4,
                           "NVRM: failed to reset links on GPU%u while preparing XVE reset: %s (0x%x)\n"
                           ,*(undefined4 *)(param_1 + 0x7a4),uVar8,iVar3);
              if (iVar12 == 0) {
                iVar12 = iVar3;
              }
            }
            portMemSet(&local_40,0,8);
            iVar3 = bitVectorGetSlice_IMPL(param_2 + 0x388,0x40,0,0x3f,local_48);
            if (iVar3 == 0) {
              local_6c = local_48[0];
            }
            else {
              nvAssertFailedNoLog("(bitVectorGetSlice(pSrc, rangeMake(0, 63), &localMask) == NV_OK)"
                                  ,"generated/g_kernel_nvlink_nvoc.h",0x8fd);
              local_6c = 0;
            }
            local_3c = 2;
            local_40 = local_6c;
            iVar3 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a91,&local_40,8);
            if (iVar12 == 0) {
              iVar12 = iVar3;
            }
            return iVar12;
          }
          return iVar12;
        }
      }
      else {
        nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/nvlink/kernel_nvlink.c",0x47d);
      }
      return iVar3;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x477,"knvlinkPrepareForXVEReset_IMPL",1,
                 "NVRM: NVLink fabric is externally managed, skipping\n");
  }
  return 0;
}


// ===== 00416e90 knvlinkDetectNvswitchProxy_IMPL =====

void knvlinkDetectNvswitchProxy_IMPL(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined1 local_98 [8];
  long local_90;
  undefined1 local_88 [16];
  undefined1 local_78;
  char acStack_77 [87];
  
  lVar1 = g_pSys;
  *(undefined8 *)(param_2 + 0x16a8) = 0xffffffffffffffff;
  if (((*(char *)(lVar1 + 0x6a) == '\0') && (*(char *)(lVar1 + 0x6d) == '\0')) &&
     (*(char *)(param_1 + 0x4cc) != '\x01')) {
    cVar2 = bitVectorTestAllCleared_IMPL(param_2 + 0x350,0x40);
    if (cVar2 == '\0') {
      portMemSet(local_88,0,0x58);
      iVar3 = convertBitVectorToLinkMasks(param_2 + 0x388,0,0,local_88);
      if (iVar3 == 0) {
        local_78 = 0;
        if (*(char *)(param_1 + 0x909) != '\0') {
          threadStateResetTimeout(param_1);
        }
        iVar3 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a90,local_88,0x58);
        if (iVar3 == 0) {
          bitVectorCopy_IMPL(local_98,0x40,param_2 + 0x388,0x40);
          uVar4 = bitVectorCountTrailingZeros_IMPL(local_98,0x40);
          while( true ) {
            cVar2 = bitVectorTestAllCleared_IMPL(local_98,0x40);
            if (cVar2 != '\0') break;
            if (acStack_77[uVar4] == '\0') {
              return;
            }
            bitVectorClr_IMPL(local_98,0x40);
            uVar4 = bitVectorCountTrailingZeros_IMPL(local_98,0x40);
          }
          portMemSet(local_98,0,0x10);
          local_98[0] = 1;
          local_90 = -1;
          iVar3 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800aae,local_98,0x10);
          if (iVar3 == 0) {
            if (local_90 != -1) {
              *(long *)(param_2 + 0x16a8) = local_90;
              *(undefined1 *)(param_2 + 0x16a0) = 1;
            }
          }
          else {
            nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x5a1,
                         "knvlinkDetectNvswitchProxy_IMPL",4,
                         "NVRM: Failed to get fabric address for GPU %x\n",
                         *(undefined4 *)(param_1 + 0x7a4));
          }
        }
        else {
          nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x589,
                       "knvlinkDetectNvswitchProxy_IMPL",4,
                       "NVRM: Failed to get the link train status for links\n");
        }
      }
      else {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x579,"knvlinkDetectNvswitchProxy_IMPL"
                     ,4,"NVRM: Failed to convert enabled links to RMCTRL mask\n");
      }
    }
    return;
  }
  return;
}


// ===== 00417100 knvlinkSetUniqueFlaBaseAddress_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int knvlinkSetUniqueFlaBaseAddress_IMPL(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint local_48 [2];
  undefined8 local_40;
  
  lVar1 = *(long *)(&DAT_00001b90 + param_1);
  if (*(char *)(param_2 + 0x338) == '\0') {
    knvlinkCoreGetRemoteDeviceInfo_IMPL();
    iVar2 = bitVectorGetSlice_IMPL(param_2 + 0x388,0x40,0,0x3f,local_48);
    uVar3 = local_48[0];
    if (iVar2 != 0) {
      nvAssertFailedNoLog("(bitVectorGetSlice(pSrc, rangeMake(0, 63), &localMask) == NV_OK)",
                          "generated/g_kernel_nvlink_nvoc.h",0x8fd);
      uVar3 = 0;
    }
    iVar2 = (**(code **)(param_2 + 0x1b8))(param_1,param_2,uVar3);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  iVar2 = (**(code **)(lVar1 + 0x3c0))(param_1,lVar1,param_3);
  if (iVar2 == 0) {
    portMemSet(local_48,0,0x10);
    local_48[0] = local_48[0] & 0xffffff00;
    local_40 = param_3;
    iVar2 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20803038,local_48,0x10);
    if (iVar2 == 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x62a,
                   "knvlinkSetUniqueFlaBaseAddress_IMPL",1,
                   "NVRM: FLA base addr %llx is assigned to GPU %x\n",param_3,
                   *(undefined4 *)(param_1 + 0x7a4));
    }
    else {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x625,
                   "knvlinkSetUniqueFlaBaseAddress_IMPL",4,
                   "NVRM: Failed to stash fla base address for GPU %x\n");
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x60f,"knvlinkSetUniqueFlaBaseAddress_IMPL"
                 ,4,"NVRM: FLA base addr validation failed for GPU %x\n",
                 *(undefined4 *)(param_1 + 0x7a4));
  }
  return iVar2;
}


// ===== 004172c0 knvlinkSyncLinkMasksAndVbiosInfo_IMPL =====

int knvlinkSyncLinkMasksAndVbiosInfo_IMPL(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined8 uVar4;
  undefined4 local_f0;
  undefined4 uStack_ec;
  undefined8 local_e8;
  undefined1 local_e0 [16];
  undefined4 local_d0;
  undefined1 local_c8 [16];
  undefined8 local_b8;
  undefined1 local_b0 [16];
  undefined4 local_a0;
  undefined1 local_98;
  ulong local_90;
  undefined1 local_88 [8];
  undefined1 local_80 [16];
  undefined1 local_70 [8];
  undefined1 local_68 [16];
  undefined1 local_58 [8];
  undefined1 local_50 [16];
  undefined2 local_40;
  
  portMemSet(&local_e8,0,0xb0);
  iVar1 = bitVectorGetSlice_IMPL(param_2 + 0x350,0x40,0,0x3f,&local_f0);
  local_e8 = CONCAT44(uStack_ec,local_f0);
  if (iVar1 != 0) {
    nvAssertFailedNoLog("(bitVectorGetSlice(pSrc, rangeMake(0, 63), &localMask) == NV_OK)",
                        "generated/g_kernel_nvlink_nvoc.h",0x8fd);
    local_e8 = 0;
  }
  iVar1 = bitVectorGetSlice_IMPL(param_2 + 0x370,0x40,0,0x3f,&local_f0);
  local_d0 = local_f0;
  if (iVar1 != 0) {
    nvAssertFailedNoLog("(bitVectorGetSlice(pSrc, rangeMake(0, 63), &localMask) == NV_OK)",
                        "generated/g_kernel_nvlink_nvoc.h",0x8fd);
    local_d0 = 0;
  }
  iVar1 = bitVectorGetSlice_IMPL(param_2 + 0x378,0x40,0,0x3f,&local_f0);
  local_b8 = CONCAT44(uStack_ec,local_f0);
  if (iVar1 != 0) {
    nvAssertFailedNoLog("(bitVectorGetSlice(pSrc, rangeMake(0, 63), &localMask) == NV_OK)",
                        "generated/g_kernel_nvlink_nvoc.h",0x8fd);
    local_b8 = 0;
  }
  local_a0 = *(undefined4 *)(param_2 + 0x380);
  iVar1 = convertBitVectorToLinkMasks(param_2 + 0x350,0,0,local_e0);
  if (iVar1 == 0) {
    iVar1 = convertBitVectorToLinkMasks(param_2 + 0x370,0,0,local_c8);
    if (iVar1 == 0) {
      iVar1 = convertBitVectorToLinkMasks(param_2 + 0x378,0,0,local_b0);
      if (iVar1 == 0) {
        local_90 = (ulong)*(uint *)(param_2 + 0x380);
        local_98 = 1;
        if (*(char *)(param_1 + 0x909) != '\0') {
          threadStateResetTimeout(param_1);
        }
        iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20803039,&local_e8,0xb0);
        iVar2 = convertLinkMasksToBitVector(local_70,8,local_68,param_2 + 0x358);
        uVar4 = 0x661;
        pcVar3 = 
        "convertLinkMasksToBitVector(&params.vbiosDisabledLinkMask, sizeof(params.vbiosDisabledLinkMask), &params.vbiosDisabledLinks, &pKernelNvlink->vbiosDisabledLinkMask)"
        ;
        if (iVar2 == 0) {
          bitVectorClrAll_IMPL
                    (&local_f0,0x40,
                     "convertLinkMasksToBitVector(&params.vbiosDisabledLinkMask, sizeof(params.vbiosDisabledLinkMask), &params.vbiosDisabledLinks, &pKernelNvlink->vbiosDisabledLinkMask)"
                     ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0x661);
          iVar2 = convertLinkMasksToBitVector(local_58,4,local_50,&local_f0);
          uVar4 = 0x666;
          pcVar3 = 
          "convertLinkMasksToBitVector(&params.initializedLinks, sizeof(params.initializedLinks), &params.initializedLinkMasks, &localLinkMaskBitVector)"
          ;
          if (iVar2 == 0) {
            iVar2 = convertBitVectorToLinkMasks(&local_f0,param_2 + 0x3b8,8,0,0x666);
            uVar4 = 0x669;
            pcVar3 = 
            "convertBitVectorToLinkMasks(&localLinkMaskBitVector, &pKernelNvlink->initializedLinks, sizeof(pKernelNvlink->initializedLinks), NULL)"
            ;
            if (iVar2 == 0) {
              bitVectorClrAll_IMPL
                        (&local_f0,0x40,
                         "convertBitVectorToLinkMasks(&localLinkMaskBitVector, &pKernelNvlink->initializedLinks, sizeof(pKernelNvlink->initializedLinks), NULL)"
                         ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0x669);
              iVar2 = convertLinkMasksToBitVector(local_88,4,local_80,&local_f0);
              uVar4 = 0x66e;
              pcVar3 = 
              "convertLinkMasksToBitVector(&params.initDisabledLinksMask, sizeof(params.initDisabledLinksMask), &params.initDisabledLinks, &localLinkMaskBitVector)"
              ;
              if (iVar2 == 0) {
                iVar2 = convertBitVectorToLinkMasks(&local_f0,param_2 + 0x368,4,0,0x66e);
                if (iVar2 == 0) {
                  *(undefined2 *)(param_2 + 0x15fd) = local_40;
                  return iVar1;
                }
                uVar4 = 0x671;
                pcVar3 = 
                "convertBitVectorToLinkMasks(&localLinkMaskBitVector, &pKernelNvlink->initDisabledLinksMask, sizeof(pKernelNvlink->initDisabledLinksMask), NULL)"
                ;
              }
            }
          }
        }
        nvCheckOkFailedNoLog(4,iVar2,pcVar3,"src/kernel/gpu/nvlink/kernel_nvlink.c",uVar4);
        return iVar2;
      }
      nvCheckOkFailedNoLog
                (4,iVar1,
                 "convertBitVectorToLinkMasks(&pKernelNvlink->bridgeSensableLinks, NULL, 0, &params.bridgeSensableLinkMasks)"
                 ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0x651);
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar1,
                 "convertBitVectorToLinkMasks(&pKernelNvlink->connectedLinksMask, NULL, 0, &params.connectedLinks)"
                 ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0x64e);
    }
    return iVar1;
  }
  nvCheckOkFailedNoLog
            (4,iVar1,
             "convertBitVectorToLinkMasks(&pKernelNvlink->discoveredLinks, NULL, 0, &params.discoveredLinkMasks)"
             ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0x64b);
  return iVar1;
}


// ===== 004176b0 knvlinkUpdateLinkConnectionStatus_IMPL =====

int knvlinkUpdateLinkConnectionStatus_IMPL(long param_1,long param_2,uint param_3)

{
  int iVar1;
  long lVar2;
  undefined8 local_50;
  undefined8 local_48;
  uint local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  
  portMemSet(&local_50,0,0x28);
  lVar2 = (ulong)param_3 * 0x78 + param_2;
  local_29 = *(undefined1 *)(lVar2 + 0x400);
  local_50 = *(undefined8 *)(lVar2 + 0x3f0);
  local_38 = *(undefined4 *)(lVar2 + 0x3f8);
  local_48 = *(undefined8 *)(lVar2 + 0x408);
  local_30 = *(undefined4 *)(lVar2 + 0x3d0);
  local_2c = (undefined1)*(undefined2 *)(lVar2 + 0x3d4);
  local_2b = (undefined1)*(undefined2 *)(lVar2 + 0x3d6);
  local_2a = (undefined1)*(undefined2 *)(lVar2 + 0x3d8);
  local_34 = *(undefined4 *)(lVar2 + 0x3dc);
  local_3c = *(undefined4 *)(lVar2 + 0x430);
  local_40 = param_3;
  if (*(char *)(param_1 + 0x909) != '\0') {
    threadStateResetTimeout(param_1);
  }
  iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a82,&local_50,0x28);
  if (iVar1 == 0) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x6ac,
               "knvlinkUpdateLinkConnectionStatus_IMPL",4,
               "NVRM: Failed to update Link connection status!\n");
  return iVar1;
}


// ===== 004177d0 knvlinkSetupTopologyForForcedConfig_IMPL =====

int knvlinkSetupTopologyForForcedConfig_IMPL(undefined8 param_1,long param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  ulong *puVar4;
  uint uVar5;
  int *piVar6;
  ulong uVar7;
  sbyte local_5c;
  undefined1 local_40 [16];
  
  uVar7 = 0;
  puVar4 = (ulong *)(param_2 + 0x3f0);
  *(undefined2 *)(param_2 + 0x338) = 0x100;
  *(undefined8 *)(param_2 + 0x340) = 0;
  do {
    cVar2 = bitVectorTest_IMPL(param_2 + 0x350,0x40,uVar7 & 0xffffffff);
    if (cVar2 != '\0') {
      uVar1 = *(uint *)(*(long *)(param_2 + 0x330) + uVar7 * 4);
      uVar5 = uVar1 >> 0x10 & 0x3f;
      if ((uVar1 & 0x100) == 0) {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x7f5,
                     "knvlinkSetupTopologyForForcedConfig_IMPL",1,
                     "NVRM: ARCH_CONNECTION info from chiplib: DISABLED Logical link %d (Physical link %d) = 0x%X\n"
                     ,uVar7 & 0xffffffff,uVar5,uVar1);
      }
      else {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x7e5,
                     "knvlinkSetupTopologyForForcedConfig_IMPL",1,
                     "NVRM: ARCH_CONNECTION info from chiplib: ENABLED Logical link %d (Physical link %d) = 0x%X\n"
                     ,uVar7 & 0xffffffff,uVar5,uVar1);
        local_5c = (sbyte)uVar5;
        *(undefined1 *)(param_2 + 0x338) = 1;
        *(ulong *)(param_2 + 0x340) = *(ulong *)(param_2 + 0x340) | 1L << local_5c;
      }
      piVar6 = (int *)(uVar7 * 4 + *(long *)(param_2 + 0x330));
      iVar3 = *piVar6;
      if ((char)iVar3 != '\0') {
        *(undefined1 *)(puVar4 + 2) = 1;
        *puVar4 = 2;
        iVar3 = *piVar6;
      }
      if (iVar3 < 0) {
        *(undefined1 *)(puVar4 + 2) = 1;
        *puVar4 = (ulong)*(uint *)(param_2 + 0x15c8);
      }
      iVar3 = knvlinkUpdateLinkConnectionStatus_IMPL(param_1,param_2,uVar7 & 0xffffffff);
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    uVar7 = uVar7 + 1;
    puVar4 = puVar4 + 0xf;
    if (uVar7 == 0x24) {
      iVar3 = convertMaskToBitVector(*(undefined8 *)(param_2 + 0x340),local_40);
      if (iVar3 == 0) {
        bitVectorAnd_IMPL(param_2 + 0x388,0x40,param_2 + 0x350,0x40,local_40,0x40);
      }
      else {
        nvCheckOkFailedNoLog
                  (4,iVar3,
                   "convertMaskToBitVector(KNVLINK_GET_MASK(pKernelNvlink, registryLinkMask, 64), &registryLinkMaskVec)"
                   ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0x81a);
      }
      return iVar3;
    }
  } while( true );
}


// ===== 004179c0 knvlinkPreTrainLinksToActiveAli_IMPL =====

int knvlinkPreTrainLinksToActiveAli_IMPL
              (long param_1,undefined8 param_2,undefined4 param_3,undefined1 param_4)

{
  int iVar1;
  undefined4 local_30;
  undefined1 local_2c;
  
  portMemSet(&local_30,0,8);
  local_30 = param_3;
  local_2c = param_4;
  if (*(char *)(param_1 + 0x909) != '\0') {
    threadStateResetTimeout(param_1);
  }
  iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a84,&local_30,8);
  if (iVar1 == 0) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x6d9,"knvlinkPreTrainLinksToActiveAli_IMPL",
               4,"NVRM: Failed to execute Pre Link Training ALI steps!\n");
  return iVar1;
}


// ===== 00417a80 knvlinkTrainLinksToActiveAli_IMPL =====

int knvlinkTrainLinksToActiveAli_IMPL
              (long param_1,undefined8 param_2,undefined4 param_3,undefined1 param_4)

{
  int iVar1;
  undefined4 local_30;
  undefined1 local_2c;
  
  portMemSet(&local_30,0,8);
  local_30 = param_3;
  local_2c = param_4;
  if (*(char *)(param_1 + 0x909) != '\0') {
    threadStateResetTimeout(param_1);
  }
  iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a86,&local_30,8);
  if (iVar1 == 0) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x706,"knvlinkTrainLinksToActiveAli_IMPL",4,
               "NVRM: Failed to change ALI Links to active!\n");
  return iVar1;
}


// ===== 00417b40 knvlinkUpdatePostRxDetectLinkMask_IMPL =====

int knvlinkUpdatePostRxDetectLinkMask_IMPL(undefined8 param_1,long param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  undefined1 local_138 [8];
  undefined1 local_130 [8];
  undefined4 auStack_128 [66];
  
  portMemSet(local_130,0,0x108);
  iVar2 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a85,local_130,0x108);
  if (iVar2 == 0) {
    iVar2 = convertLinkMasksToBitVector(local_130,8,0,param_2 + 0x14b0);
    if (iVar2 == 0) {
      bitVectorCopy_IMPL(local_138,0x40,param_2 + 0x388,0x40);
      uVar3 = bitVectorCountTrailingZeros_IMPL(local_138,0x40);
      while( true ) {
        uVar4 = (ulong)uVar3;
        cVar1 = bitVectorTestAllCleared_IMPL(local_138,0x40);
        if ((cVar1 != '\0') || (*(uint *)(param_2 + 0x3c0) <= uVar3)) break;
        *(undefined4 *)(param_2 + 0x430 + uVar4 * 0x78) = auStack_128[uVar4];
        bitVectorClr_IMPL(local_138,0x40,uVar4);
        uVar3 = bitVectorCountTrailingZeros_IMPL(local_138,0x40);
      }
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar2,
                 "convertLinkMasksToBitVector(&params.postRxDetLinkMask, sizeof(params.postRxDetLinkMask), NULL, &pKernelNvlink->postRxDetLinkMask)"
                 ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0x72b);
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x727,
                 "knvlinkUpdatePostRxDetectLinkMask_IMPL",4,
                 "NVRM: Failed to update Rx Detect Link mask!\n");
  }
  return iVar2;
}


// ===== 00417cc0 knvlinkCopyNvlinkDeviceInfo_IMPL =====

int knvlinkCopyNvlinkDeviceInfo_IMPL(undefined8 param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined8 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  puVar4 = (undefined4 *)portMemAllocNonPaged(0x428);
  if (puVar4 == (undefined4 *)0x0) {
    iVar2 = 0x51;
  }
  else {
    portMemSet(puVar4,0,0x428);
    iVar2 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a87,puVar4,0x428);
    if (iVar2 == 0x56) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x75a,"knvlinkCopyNvlinkDeviceInfo_IMPL",
                   1,"NVRM: NVLink is unavailable\n");
    }
    else if (iVar2 == 0) {
      *(undefined4 *)(param_2 + 0x310) = *puVar4;
      *(undefined1 *)(param_2 + 0x318) = *(undefined1 *)(puVar4 + 1);
      *(undefined4 *)(param_2 + 0x31c) = puVar4[2];
      iVar3 = convertLinkMasksToBitVector(0,0,puVar4 + 4,param_2 + 0x350);
      if (iVar3 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar3,
                   "convertLinkMasksToBitVector(NULL, 0U, &pNvlinkInfoParams->discoveredLinks, &pKernelNvlink->discoveredLinks)"
                   ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0x768);
        return iVar3;
      }
      *(undefined4 *)(param_2 + 0x314) = puVar4[8];
      uVar1 = puVar4[9];
      *(uint *)(param_2 + 0x3c0) = uVar1;
      if (uVar1 != 0) {
        puVar5 = (undefined8 *)(param_2 + 0x418);
        puVar6 = puVar4;
        do {
          *puVar5 = param_1;
          puVar7 = puVar6 + 4;
          *(undefined1 *)((long)puVar5 + 9) = *(undefined1 *)(puVar6 + 10);
          *(undefined1 *)(puVar5 + 1) = *(undefined1 *)((long)puVar6 + 0x29);
          *(undefined4 *)((long)puVar5 + 0xc) = puVar6[0xb];
          *(undefined1 *)((long)puVar5 + 0x14) = *(undefined1 *)(puVar6 + 0xc);
          *(undefined1 *)((long)puVar5 + 0x15) = *(undefined1 *)((long)puVar6 + 0x31);
          *(undefined4 *)(puVar5 + 2) = puVar6[0xd];
          puVar5 = puVar5 + 0xf;
          puVar6 = puVar7;
        } while (puVar7 != puVar4 + (ulong)uVar1 * 4);
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x75f,"knvlinkCopyNvlinkDeviceInfo_IMPL",
                   4,"NVRM: Failed to retrieve all nvlink device info!\n");
    }
    portMemFree(puVar4);
  }
  return iVar2;
}


// ===== 00417ec0 knvlinkCopyIoctrlDeviceInfo_IMPL =====

int knvlinkCopyIoctrlDeviceInfo_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined4 local_38;
  undefined1 local_34;
  undefined4 local_30;
  int iStack_2c;
  
  uVar3 = *(uint *)(param_2 + 0x310);
  if (uVar3 == 0) {
    return 0;
  }
  uVar4 = 0;
  do {
    if ((uVar3 & 1) != 0) {
      portMemSet(&local_48,0,0x20);
      local_48 = (undefined4)uVar4;
      iVar2 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a8e,&local_48,0x20);
      if (iVar2 == 0x56) {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x7a3,
                     "knvlinkCopyIoctrlDeviceInfo_IMPL",3,"NVRM: NVLink is unavailable\n");
        return 0x56;
      }
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x7a8,
                     "knvlinkCopyIoctrlDeviceInfo_IMPL",4,
                     "NVRM: Failed to retrieve device info for IOCTRL %d!\n",uVar4 & 0xffffffff);
        return iVar2;
      }
      lVar1 = *(long *)(param_2 + 0x2f8 + uVar4 * 8);
      *(undefined4 *)(lVar1 + 0x17c) = local_44;
      *(undefined8 *)(lVar1 + 0x180) = local_40;
      *(undefined4 *)(lVar1 + 400) = local_38;
      *(undefined1 *)(lVar1 + 0x194) = local_34;
      *(ulong *)(lVar1 + 0x188) = CONCAT44(iStack_2c,local_30);
      if (iStack_2c == 0) {
        *(undefined1 *)(lVar1 + 0x178) = 0;
      }
      if (uVar3 >> 1 == 0) {
        return 0;
      }
    }
    uVar3 = uVar3 >> 1;
    uVar4 = uVar4 + 1;
  } while( true );
}


// ===== 00418040 knvlinkSyncLaneShutdownProps_IMPL =====

int knvlinkSyncLaneShutdownProps_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined1 local_19;
  
  portMemSet(&local_19,0,1);
  local_19 = *(undefined1 *)(param_2 + 0x2e6);
  iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a96,&local_19,1);
  if (iVar1 == 0) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x83c,"knvlinkSyncLaneShutdownProps_IMPL",4,
               "NVRM: Failed to sync NVLink shutdown properties with GSP!\n");
  return iVar1;
}


// ===== 004180e0 knvlinkGetNumActiveLinksPerIoctrl_IMPL =====

undefined4 knvlinkGetNumActiveLinksPerIoctrl_IMPL(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 local_1c;
  
  portMemSet(&local_1c,0,4);
  iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800ac7,&local_1c,4);
  if (iVar1 == 0) {
    return local_1c;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x85b,
               "knvlinkGetNumActiveLinksPerIoctrl_IMPL",4,
               "NVRM: Failed to get the number of active links per IOCTRL\n");
  return 0;
}


// ===== 00418170 knvlinkGetTotalNumLinksPerIoctrl_IMPL =====

undefined4 knvlinkGetTotalNumLinksPerIoctrl_IMPL(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 local_1c;
  
  portMemSet(&local_1c,0,4);
  iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800ac8,&local_1c,4);
  if (iVar1 == 0) {
    return local_1c;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x879,"knvlinkGetTotalNumLinksPerIoctrl_IMPL"
               ,4,"NVRM: Failed to get the total number of links per IOCTRL\n");
  return 0;
}


// ===== 00418200 knvlinkProcessInitDisabledLinks_IMPL =====

int knvlinkProcessInitDisabledLinks_IMPL(long param_1,long param_2)

{
  int iVar1;
  undefined1 local_61;
  undefined1 local_60 [8];
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  local_58 = 0;
  local_50 = 0;
  local_61 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  iVar1 = gpumgrGetGpuInitDisabledNvlinks_IMPL(*(undefined4 *)(param_1 + 0x7ac),&local_58,&local_61)
  ;
  if (iVar1 != 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x896,
                 "knvlinkProcessInitDisabledLinks_IMPL",4,
                 "NVRM: Failed to get init disabled links from gpumgr\n");
    return iVar1;
  }
  portMemSet(&local_48,0,0x20);
  local_40 = local_58;
  local_38 = local_50;
  local_30 = CONCAT71(local_30._1_7_,local_61);
  iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x2080303b,&local_48,0x20);
  if (iVar1 == 0) {
    iVar1 = convertLinkMasksToBitVector(0,0,&local_40,local_60);
    if (iVar1 == 0) {
      iVar1 = convertBitVectorToLinkMasks(local_60,param_2 + 0x368,4,0);
      if (iVar1 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar1,
                   "convertBitVectorToLinkMasks(&localLinkMask, &pKernelNvlink->initDisabledLinksMask, sizeof(pKernelNvlink->initDisabledLinksMask), NULL)"
                   ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0x8ab);
      }
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar1,
                 "convertLinkMasksToBitVector(NULL, 0, &params.initDisabledLinks, &localLinkMask)",
                 "src/kernel/gpu/nvlink/kernel_nvlink.c",0x8a8);
    }
    return iVar1;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0x8a4,"knvlinkProcessInitDisabledLinks_IMPL",
               4,"NVRM: Failed to process init disabled links in GSP\n");
  return iVar1;
}


// ===== 004183c0 knvlinkGetRemapTableInformation_IMPL.part.0 =====

ulong knvlinkGetRemapTableInformation_IMPL_part_0(undefined8 param_1,long param_2)

{
  ulong uVar1;
  long lVar2;
  undefined4 local_11c [32];
  undefined4 local_9c [32];
  uint local_1c;
  
  portMemSet(local_11c,0,0x104);
  uVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x2080309e,local_11c,0x104);
  if ((int)uVar1 == 0) {
    if (local_1c < 0x21) {
      if (local_1c != 0) {
        lVar2 = 0;
        do {
          *(undefined4 *)(param_2 + 0x1730 + lVar2) = *(undefined4 *)((long)local_11c + lVar2);
          *(undefined4 *)(param_2 + 0x17b0 + lVar2) = *(undefined4 *)((long)local_9c + lVar2);
          lVar2 = lVar2 + 4;
        } while ((ulong)local_1c << 2 != lVar2);
      }
    }
    else {
      nvAssertFailedNoLog("(params.remapTabSize <= NV2080_CTRL_NVLINK_MAX_REMAP_TABLE_ENTRIES)",
                          "src/kernel/gpu/nvlink/kernel_nvlink.c",0xc9f);
      uVar1 = 0x40;
    }
    return uVar1;
  }
  nvCheckOkFailedNoLog
            (4,uVar1 & 0xffffffff,
             "knvlinkExecGspRmRpc(pGpu, pKernelNvlink, NV2080_CTRL_CMD_NVLINK_GET_REMAP_TABLE_INFO, (void *)&params, sizeof(params))"
             ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0xc9a);
  return uVar1 & 0xffffffff;
}


// ===== 004184d0 knvlinkGetBWModeEpoch_IMPL =====

long knvlinkGetBWModeEpoch_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  long lVar2;
  bool bVar3;
  
  lVar2 = 0;
  if (param_2 != 0) {
    lVar1 = *(long *)(param_2 + 0x16c8);
    do {
      lVar2 = lVar1;
      LOCK();
      lVar1 = *(long *)(param_2 + 0x16c8);
      bVar3 = lVar2 == lVar1;
      if (bVar3) {
        *(long *)(param_2 + 0x16c8) = lVar2;
        lVar1 = lVar2;
      }
      UNLOCK();
    } while (!bVar3);
  }
  return lVar2;
}


// ===== 00418500 knvlinkSendEncryptionKeys_IMPL =====

ulong knvlinkSendEncryptionKeys_IMPL(long param_1,undefined8 param_2,long param_3,uint param_4)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  char *pcVar4;
  undefined8 uVar5;
  int local_68;
  undefined8 local_64;
  undefined8 local_5c;
  undefined8 local_54;
  undefined8 local_4c;
  undefined8 local_44;
  undefined8 local_3c;
  undefined8 local_34;
  undefined8 local_2c;
  undefined8 local_24;
  undefined4 local_1c;
  
  local_4c = 0;
  local_44 = 0;
  local_3c = 0;
  local_34 = 0;
  local_24 = 0;
  local_1c = 0;
  local_64 = 0;
  local_68 = 8;
  if ((param_1 == 0) || (param_3 == 0)) {
    return 0x1f;
  }
  lVar1 = *(long *)(param_1 + 0x1d18);
  lVar2 = *(long *)(param_1 + 0x1d10);
  if (((lVar1 != 0) && (lVar2 != 0)) && (*(char *)(lVar2 + 0x23c) != '\0')) {
    local_54 = (ulong)param_4 << 0x20;
    local_5c = 0x8000000000;
    local_2c = 0x100;
    portMemCopy(&local_4c,0x20,param_3,0x20);
    uVar3 = ccslEncrypt_KERNEL(*(undefined8 *)(lVar1 + 0x2e8),0x28,(long)&local_54 + 4,0,0,
                               (long)&local_54 + 4,(long)&local_2c + 4);
    uVar5 = 0xb08;
    pcVar4 = 
    "ccslEncrypt(pConfCompute->pNvleP2pWrappingCcslCtx, sizeof(pGspReqHdr->wrappedKeyEntries), (NvU8 *)pGspReqHdr->wrappedKeyEntries, NULL, 0, (NvU8 *)pGspReqHdr->wrappedKeyEntries, (NvU8 *)pGspReqHdr->keyEntriesTag)"
    ;
    if ((int)uVar3 == 0) {
      uVar3 = spdmSendApplicationMessage_IMPL(param_1,lVar2,&local_5c,0x44,&local_64,&local_68);
      if ((int)uVar3 == 0) {
        if (local_68 - 4U < 5) {
          if ((int)local_64 == -1) {
            if (local_68 == 8) {
              nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0xb1d,
                           "knvlinkSendEncryptionKeys_IMPL",4,
                           "NVRM: GSP returned NVLE response with error code 0x%x!\n",local_64._4_4_
                          );
              uVar3 = (ulong)local_64._4_4_;
              if (local_64._4_4_ == 0) {
                uVar3 = 0x25;
              }
              return uVar3;
            }
          }
          else if ((local_68 == 4) && ((int)local_64 == -0x80000000)) {
            return uVar3;
          }
          nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0xb23,
                       "knvlinkSendEncryptionKeys_IMPL",4,
                       "NVRM: Unexpected NVLE response from GSP! cmdType: 0x%x rspSize: 0x%x!\n",
                       local_64 & 0xffffffff,local_68);
        }
        else {
          nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0xb15,
                       "knvlinkSendEncryptionKeys_IMPL",4,
                       "NVRM: NVLE response from GSP of invalid size! rspSize: 0x%x!\n",local_68);
        }
        return 0x25;
      }
      uVar5 = 0xb10;
      pcVar4 = 
      "spdmSendApplicationMessage(pGpu, pSpdm, pNvleKeyReq, nvleKeyReqSize, (NvU8 *)&nvleKeyRsp, &nvleKeyRspSize)"
      ;
    }
    nvCheckOkFailedNoLog(4,uVar3 & 0xffffffff,pcVar4,"src/kernel/gpu/nvlink/kernel_nvlink.c",uVar5);
    return uVar3 & 0xffffffff;
  }
  return 0x40;
}


// ===== 00418780 knvlinkSetupEncryptionKeys_IMPL =====

int knvlinkSetupEncryptionKeys_IMPL(long param_1,long param_2,long param_3,long param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char cVar5;
  int iVar6;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar3 = *(undefined8 *)(param_2 + 0x1724);
  uVar4 = *(undefined8 *)(param_4 + 0x1724);
  uVar1 = *(uint *)(param_2 + 0x1728);
  local_58 = 0;
  local_50 = 0;
  uVar2 = *(uint *)(param_4 + 0x1728);
  local_48 = 0;
  local_40 = 0;
  cVar5 = libspdm_random_bytes(&local_58,0x20);
  if (cVar5 == '\0') {
    return 0x25;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0xbaa,"knvlinkSetupEncryptionKeys_IMPL",1,
               "NVRM: Setting nvle keys between GPU%d and GPU%d\n",*(undefined4 *)(param_1 + 0x7a4),
               *(undefined4 *)(param_3 + 0x7a4));
  if (*(char *)(param_2 + 0x1833 + (ulong)uVar2) == '\0') {
    portMemSet(&local_68,0,0x10);
    local_68 = uVar3;
    local_60 = uVar4;
    iVar6 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x2080308c,&local_68);
    if (iVar6 != 0) {
      nvAssertOkFailedNoLog
                (iVar6,
                 "knvlinkExecGspRmRpc(pLocalGpu, pLocalKernelNvlink, NV2080_CTRL_NVLINK_UPDATE_NVLE_TOPOLOGY, (void *)&params, sizeof(params))"
                 ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0xbbc);
      goto LAB_00418862;
    }
    iVar6 = knvlinkSendEncryptionKeys_IMPL(param_1,param_2,&local_58,uVar2);
    if (iVar6 != 0) {
      nvAssertOkFailedNoLog
                (iVar6,
                 "knvlinkSendEncryptionKeys(pLocalGpu, pLocalKernelNvlink, nvleKey, remoteCLID)",
                 "src/kernel/gpu/nvlink/kernel_nvlink.c",0xbc1);
      goto LAB_00418862;
    }
    *(undefined1 *)(param_2 + 0x1833 + (ulong)uVar2) = 1;
  }
  iVar6 = 0;
  if (*(char *)(param_4 + 0x1833 + (ulong)uVar1) == '\0') {
    portMemSet(&local_68,0,0x10);
    local_68 = uVar4;
    local_60 = uVar3;
    iVar6 = knvlinkExecGspRmRpc_IMPL(param_3,param_4,0x2080308c,&local_68,0x10);
    if (iVar6 == 0) {
      iVar6 = knvlinkSendEncryptionKeys_IMPL(param_3,param_4,&local_58,uVar1);
      if (iVar6 == 0) {
        *(undefined1 *)(param_4 + 0x1833 + (ulong)uVar1) = 1;
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar6,
                   "knvlinkSendEncryptionKeys(pRemoteGpu, pRemoteKernelNvlink, nvleKey, localCLID)",
                   "src/kernel/gpu/nvlink/kernel_nvlink.c",0xbdc);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar6,
                 "knvlinkExecGspRmRpc(pRemoteGpu, pRemoteKernelNvlink, NV2080_CTRL_NVLINK_UPDATE_NVLE_TOPOLOGY, (void *)&params, sizeof(params))"
                 ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0xbd7);
    }
  }
LAB_00418862:
  portMemSet(&local_58,0,0x20);
  return iVar6;
}


// ===== 00418a30 knvlinkClearEncryptionKeys_IMPL =====

undefined8 knvlinkClearEncryptionKeys_IMPL(undefined8 param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  
  if (*(char *)(param_2 + 0x2f3) != '\0') {
    iVar3 = 0;
    uVar1 = *(uint *)(param_2 + 0x1728);
    do {
      lVar2 = gpumgrGetGpu(iVar3);
      if ((((lVar2 != 0) && (*(char *)(lVar2 + 0x44f) == '\0')) &&
          (*(char *)(lVar2 + 0x450) == '\0')) &&
         (((*(char *)(lVar2 + 0x451) == '\0' && (*(char *)(lVar2 + 0x461) == '\0')) &&
          ((lVar2 = *(long *)(lVar2 + 0x1ce8), lVar2 != 0 && (*(char *)(lVar2 + 0x2f3) != '\0'))))))
      {
        *(undefined1 *)(param_2 + 0x1833 + (ulong)*(uint *)(lVar2 + 0x1728)) = 0;
        *(undefined1 *)(lVar2 + 0x1833 + (ulong)uVar1) = 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 0x20);
    return 0;
  }
  return 0;
}


// ===== 00418ae0 knvlinkSetupNvleRemapTables_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

int knvlinkSetupNvleRemapTables_IMPL(undefined8 param_1,long param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  char *pcVar7;
  int iVar8;
  undefined8 uVar9;
  undefined8 local_50;
  undefined8 local_48;
  char local_40;
  undefined1 local_3f;
  
  if (*(char *)(param_2 + 0x2f3) != '\0') {
    iVar8 = 0;
    do {
      lVar4 = gpumgrGetGpu(iVar8);
      if (((lVar4 != 0) &&
          (((*(char *)(lVar4 + 0x4918) != '\0' || (*(char *)(lVar4 + 0x4916) != '\0')) &&
           (*(long *)(lVar4 + 0x1ce8) != 0)))) &&
         ((*(long *)(lVar4 + 0x4c0) != 0 && (cVar1 = gpuFabricProbeIsReceived(), cVar1 == '\0')))) {
        return 0;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 != 0x20);
    if (*(char *)(param_2 + 0x172c) == '\0') {
      iVar8 = 0;
      do {
        lVar4 = gpumgrGetGpu(iVar8);
        if (((lVar4 != 0) &&
            ((*(char *)(lVar4 + 0x4918) != '\0' || (*(char *)(lVar4 + 0x4916) != '\0')))) &&
           ((lVar6 = *(long *)(lVar4 + 0x1ce8), lVar6 != 0 &&
            (iVar2 = (**(code **)(lVar6 + 0x2d8))(lVar4,lVar6,1,*(code **)(lVar6 + 0x2d8)),
            iVar2 != 0)))) {
          uVar9 = 0xcf0;
          pcVar7 = "knvlinkEncryptionGetUpdateGpuIdentifiers_HAL(pGpu0, pKernelNvlink0, NV_TRUE)";
          goto LAB_00418dc7;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 != 0x20);
      if (*(char *)(param_2 + 0x172c) == '\0') {
        iVar8 = 0;
        do {
          lVar4 = gpumgrGetGpu(iVar8);
          if ((lVar4 != 0) &&
             ((((*(char *)(lVar4 + 0x4918) != '\0' || (*(char *)(lVar4 + 0x4916) != '\0')) &&
               (lVar6 = *(long *)(lVar4 + 0x1ce8), lVar6 != 0)) &&
              (iVar2 = (**(code **)(lVar6 + 0x2d8))(lVar4,lVar6,0,*(code **)(lVar6 + 0x2d8)),
              iVar2 != 0)))) {
            uVar9 = 0xd07;
            pcVar7 = "knvlinkEncryptionGetUpdateGpuIdentifiers_HAL(pGpu0, pKernelNvlink0, NV_FALSE)"
            ;
LAB_00418dc7:
            nvCheckOkFailedNoLog(4,iVar2,pcVar7,"src/kernel/gpu/nvlink/kernel_nvlink.c",uVar9);
            return iVar2;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 != 0x20);
        iVar8 = 0;
        do {
          while( true ) {
            iVar2 = iVar8 + 1;
            lVar4 = gpumgrGetGpu(iVar8);
            iVar8 = iVar2;
            if (((lVar4 == 0) ||
                ((*(char *)(lVar4 + 0x4918) == '\0' && (*(char *)(lVar4 + 0x4916) == '\0')))) ||
               (lVar6 = *(long *)(lVar4 + 0x1ce8), lVar6 == 0)) break;
            if (iVar2 == 0x20) goto LAB_00418b68;
            do {
              lVar5 = gpumgrGetGpu(iVar2);
              if (((lVar5 != 0) &&
                  ((*(char *)(lVar5 + 0x4918) != '\0' || (*(char *)(lVar5 + 0x4916) != '\0')))) &&
                 ((*(long *)(lVar5 + 0x1ce8) != 0 &&
                  (iVar3 = knvlinkSetupEncryptionKeys_IMPL(lVar4,lVar6,lVar5), iVar3 != 0)))) {
                nvCheckOkFailedNoLog
                          (4,iVar3,
                           "knvlinkSetupEncryptionKeys(pGpu0, pKernelNvlink0, pGpu1, pKernelNvlink1)"
                           ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0xd26);
                return iVar3;
              }
              iVar2 = iVar2 + 1;
            } while (iVar2 != 0x20);
          }
        } while (iVar2 != 0x20);
      }
    }
LAB_00418b68:
    iVar8 = 0;
    do {
      lVar4 = gpumgrGetGpu(iVar8);
      if (((lVar4 != 0) &&
          (((*(char *)(lVar4 + 0x4918) != '\0' || (*(char *)(lVar4 + 0x4916) != '\0')) &&
           (lVar6 = *(long *)(lVar4 + 0x1ce8), lVar6 != 0)))) && (*(char *)(lVar6 + 0x1830) == '\0')
         ) {
        if (*(char *)(lVar6 + 0x2f3) == '\0') {
          iVar2 = 0x56;
LAB_00418de8:
          nvCheckOkFailedNoLog
                    (4,iVar2,"knvlinkGetRemapTableInformation(pGpu0, pKernelNvlink0)",
                     "src/kernel/gpu/nvlink/kernel_nvlink.c",0xd3a);
          return iVar2;
        }
        iVar2 = knvlinkGetRemapTableInformation_IMPL_part_0(lVar4);
        if (iVar2 != 0) goto LAB_00418de8;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 != 0x20);
    iVar8 = 0;
    do {
      while( true ) {
        iVar2 = iVar8 + 1;
        lVar4 = gpumgrGetGpu(iVar8);
        iVar8 = iVar2;
        if ((((lVar4 == 0) ||
             ((*(char *)(lVar4 + 0x4918) == '\0' && (*(char *)(lVar4 + 0x4916) == '\0')))) ||
            (lVar4 = *(long *)(lVar4 + 0x1ce8), lVar4 == 0)) || (*(char *)(lVar4 + 0x1830) != '\0'))
        break;
        if (iVar2 == 0x20) goto LAB_00418c33;
        do {
          lVar6 = gpumgrGetGpu(iVar2);
          if (((lVar6 != 0) &&
              (((*(char *)(lVar6 + 0x4918) != '\0' || (*(char *)(lVar6 + 0x4916) != '\0')) &&
               (lVar6 = *(long *)(lVar6 + 0x1ce8), lVar6 != 0)))) &&
             ((((*(char *)(lVar6 + 0x1830) == '\0' && (*(char *)(lVar4 + 0x2f3) != '\0')) &&
               (*(char *)(lVar6 + 0x2f3) != '\0')) &&
              (iVar3 = knvlinkValidateRemapTableSlots_IMPL_part_0(lVar4), iVar3 != 0)))) {
            nvCheckOkFailedNoLog
                      (4,0x40,
                       "knvlinkValidateRemapTableSlots(pGpu0, pKernelNvlink0, pGpu1, pKernelNvlink1)"
                       ,"src/kernel/gpu/nvlink/kernel_nvlink.c",0xd59);
            return 0x40;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 != 0x20);
      }
    } while (iVar2 != 0x20);
LAB_00418c33:
    iVar8 = 0;
    do {
      lVar4 = gpumgrGetGpu(iVar8);
      if (((lVar4 != 0) &&
          ((*(char *)(lVar4 + 0x4918) != '\0' || (*(char *)(lVar4 + 0x4916) != '\0')))) &&
         ((lVar6 = *(long *)(lVar4 + 0x1ce8), lVar6 != 0 &&
          ((*(char *)(lVar6 + 0x1830) == '\0' && (*(char *)(lVar6 + 0x1831) == '\0')))))) {
        portMemSet(&local_48,0,0x10);
        iVar2 = bitVectorGetSlice_IMPL(lVar6 + 0x388,0x40,0,0x3f,&local_50);
        uVar9 = local_50;
        if (iVar2 != 0) {
          nvAssertFailedNoLog("(bitVectorGetSlice(pSrc, rangeMake(0, 63), &localMask) == NV_OK)",
                              "generated/g_kernel_nvlink_nvoc.h",0x8fd);
          uVar9 = 0;
        }
        local_48 = uVar9;
        iVar2 = knvlinkExecGspRmRpc_IMPL(lVar4,lVar6,0x2080309d,&local_48,0x10);
        if (iVar2 != 0) {
          nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0xd75,
                       "knvlinkSetupNvleRemapTables_IMPL",4,
                       "NVRM: GPU%d Failed to lock remap table and MSE\n",
                       *(undefined4 *)(lVar4 + 0x7a4));
          return iVar2;
        }
        *(undefined1 *)(lVar6 + 0x1831) = local_3f;
        if (local_40 != '\0') {
          nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0xd7e,
                       "knvlinkSetupNvleRemapTables_IMPL",1,
                       "NVRM: GPU%d Successfully locked remap table and MSE\n",
                       *(undefined4 *)(lVar4 + 0x7a4));
          *(undefined1 *)(lVar6 + 0x1830) = 1;
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 != 0x20);
  }
  return 0;
}


// ===== 004190b0 knvlinkAssignNvleClid_IMPL =====

int knvlinkAssignNvleClid_IMPL(long param_1,long param_2)

{
  int iVar1;
  undefined4 local_1c;
  
  *(undefined4 *)(param_2 + 0x1728) = *(undefined4 *)(param_1 + 0x7a4);
  portMemSet(&local_1c,0,4);
  local_1c = *(undefined4 *)(param_2 + 0x1728);
  iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x2080309c,&local_1c,4);
  if (iVar1 == 0) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlink.c",0xda4,"knvlinkAssignNvleClid_IMPL",4,
               "NVRM: Failed to execute RPC to update CLID in physical RM\n");
  return iVar1;
}


// ===== 00419180 knvlinkUtoa =====

void knvlinkUtoa(char *param_1,ulong param_2,ulong param_3)

{
  bool bVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char local_48 [64];
  
  if (param_1 == (char *)0x0) {
    nvAssertFailedNoLog("str != NULL","src/kernel/gpu/nvlink/kernel_nvlink.c",0xdb2);
  }
  pcVar2 = local_48;
  do {
    pcVar5 = pcVar2 + 1;
    *pcVar2 = (char)param_3 + (char)(param_3 / 10) * -10 + '0';
    bVar1 = 9 < param_3;
    param_3 = param_3 / 10;
    pcVar2 = pcVar5;
  } while (bVar1);
  if (param_2 <= (ulong)((long)pcVar5 - (long)local_48)) {
    nvAssertFailedNoLog("length > (NvU64) (ptr - temp)","src/kernel/gpu/nvlink/kernel_nvlink.c",
                        0xdbb);
  }
  pcVar4 = param_1;
  if (local_48 < pcVar5) {
    do {
      pcVar3 = pcVar2 + -1;
      *pcVar4 = pcVar2[-1];
      pcVar2 = pcVar3;
      pcVar4 = pcVar4 + 1;
    } while (pcVar3 != local_48);
    param_1 = param_1 + ((long)pcVar5 - (long)pcVar3);
  }
  *param_1 = '\0';
  return;
}


// ===== 004192b0 subdeviceCtrlCmdNvlinkGetSupportedCounters_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdNvlinkGetSupportedCounters_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  undefined8 uVar4;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*(long *)(lVar1 + 0x1bc0) != 0) {
    lVar2 = *(long *)(lVar1 + 0x1ce8);
    cVar3 = kmigmgrIsMIGNvlinkP2PSupported_IMPL();
    if ((cVar3 != '\0') && (lVar2 != 0)) {
      uVar4 = (**(code **)(lVar2 + 0x2b8))(lVar1,lVar2,param_2);
      return uVar4;
    }
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkapi.c",0x123,
               "subdeviceCtrlCmdNvlinkGetSupportedCounters_IMPL",1,
               "NVRM: NVLink unavailable. Return\n");
  return 0x56;
}


// ===== 00419350 subdeviceCtrlCmdNvlinkGetSupportedBWMode_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdNvlinkGetSupportedBWMode_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  undefined8 uVar4;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*(long *)(lVar1 + 0x1bc0) != 0) {
    lVar2 = *(long *)(lVar1 + 0x1ce8);
    cVar3 = kmigmgrIsMIGNvlinkP2PSupported_IMPL();
    if ((cVar3 != '\0') && (lVar2 != 0)) {
      if (*(char *)(lVar1 + 0x4a4c) != '\0') {
        uVar4 = (**(code **)(lVar2 + 0x288))(lVar1,lVar2,param_2);
        return uVar4;
      }
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkapi.c",0x144,
                   "subdeviceCtrlCmdNvlinkGetSupportedBWMode_IMPL",4,
                   "NVRM: RBM not currently implemented on direct connect systems.\n");
      return 0x56;
    }
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkapi.c",0x13c,
               "subdeviceCtrlCmdNvlinkGetSupportedBWMode_IMPL",4,
               "NVRM: NVLink unavailable. Return\n");
  return 0x56;
}


// ===== 00419420 subdeviceCtrlCmdNvlinkSetBWMode_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdNvlinkSetBWMode_IMPL(long param_1,undefined2 *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  undefined8 uVar4;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*(long *)(lVar1 + 0x1bc0) != 0) {
    lVar2 = *(long *)(lVar1 + 0x1ce8);
    cVar3 = kmigmgrIsMIGNvlinkP2PSupported_IMPL(lVar1);
    if ((cVar3 != '\0') && (lVar2 != 0)) {
      if (*(char *)(lVar1 + 0x4a4c) == '\0') {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkapi.c",0x166,
                     "subdeviceCtrlCmdNvlinkSetBWMode_IMPL",4,
                     "NVRM: RBM not currently implemented on direct connect systems.\n");
        return 0x56;
      }
      cVar3 = (**(code **)(lVar2 + 0x260))(lVar1,lVar2,*param_2);
      if (cVar3 != '\0') {
        uVar4 = gpumgrSetGpuNvlinkBwModePerGpu_IMPL(lVar1,*param_2);
        return uVar4;
      }
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkapi.c",0x16d,
                   "subdeviceCtrlCmdNvlinkSetBWMode_IMPL",4,
                   "NVRM: Requested RBM mode is not supported by GPU.\n");
      return 0x56;
    }
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkapi.c",0x15e,
               "subdeviceCtrlCmdNvlinkSetBWMode_IMPL",1,"NVRM: NVLink unavailable. Return\n");
  return 0x56;
}


// ===== 00419560 subdeviceCtrlCmdNvlinkGetBWMode_IMPL =====

undefined8 subdeviceCtrlCmdNvlinkGetBWMode_IMPL(long param_1,ushort *param_2)

{
  long lVar1;
  char cVar2;
  ushort uVar3;
  
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x1ce8);
  if (lVar1 != 0) {
    cVar2 = gpumgrGetGpuNvlinkBwModeScope_IMPL();
    if (cVar2 == '\x01') {
      uVar3 = gpumgrGetGpuNvlinkBwMode_IMPL();
      *param_2 = uVar3;
    }
    else {
      *param_2 = (ushort)*(byte *)(lVar1 + 0x16c0);
    }
    return 0;
  }
  return 0x56;
}


// ===== 004195e0 subdeviceCtrlCmdNvlinkGetLocalDeviceInfo_IMPL =====

undefined8 subdeviceCtrlCmdNvlinkGetLocalDeviceInfo_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar3 = *(long *)(lVar2 + 0x1ce8);
  param_2[1] = *(undefined4 *)(lVar2 + 0x87c);
  *(ushort *)(param_2 + 2) = (ushort)*(byte *)(lVar2 + 0x879);
  *(ushort *)((long)param_2 + 10) = (ushort)*(byte *)(lVar2 + 0x878);
  *(undefined2 *)(param_2 + 3) = 0;
  uVar1 = *(undefined4 *)(lVar2 + 0x7f4);
  *(undefined8 *)(param_2 + 6) = 2;
  param_2[4] = uVar1;
  if (*(int *)(lVar2 + 0x7f4) != 0) {
    *param_2 = 1;
  }
  param_2[0xc] = 0;
  if (*(char *)(lVar2 + 0x908) == '\0') {
    if (lVar3 != 0) {
      cVar4 = knvlinkGetDegradedMode_IMPL(lVar2,lVar3);
      if (cVar4 == '\0') {
        cVar4 = knvlinkIsUncontainedErrorRecoveryActive_IMPL(lVar2,lVar3);
        if (cVar4 != '\0') {
          param_2[0xc] = param_2[0xc] | 2;
        }
      }
      else {
        param_2[0xc] = param_2[0xc] | 1;
      }
      return 0;
    }
    return 0x56;
  }
  return 0;
}


// ===== 004196b0 knvlinkCoreDriverLoadWar_IMPL =====

void knvlinkCoreDriverLoadWar_IMPL(void)

{
  return;
}


// ===== 004196c0 knvlinkCoreDriverUnloadWar_IMPL =====

void knvlinkCoreDriverUnloadWar_IMPL(void)

{
  return;
}


// ===== 004196d0 knvlinkCoreIsDriverSupported_IMPL =====

undefined8 knvlinkCoreIsDriverSupported_IMPL(void)

{
  char cVar1;
  
  cVar1 = nvlink_lib_is_initialized();
  if (cVar1 != '\0') {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelib.c",0x79,
               "knvlinkCoreIsDriverSupported_IMPL",1,
               "NVRM: NVLink core lib isn\'t initialized yet!\n");
  return 0x56;
}


// ===== 00419720 knvlinkCoreAddDevice_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 knvlinkCoreAddDevice_IMPL(long param_1,long param_2)

{
  undefined8 uVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  long lVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  
  if (*(long *)(param_2 + 0x15d0) != 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelib.c",0x97,"knvlinkCoreAddDevice_IMPL",1,
                 "NVRM: GPU already registered in NVLINK core!\n");
    return 0;
  }
  lVar6 = portMemAllocNonPaged(0x40);
  *(long *)(param_2 + 0x15e0) = lVar6;
  if (lVar6 != 0) {
    portMemSet(lVar6,0,0x40);
    portMemCopy(*(undefined8 *)(param_2 + 0x15e0),0x12,"NVIDIA GPU DRIVER",0x12);
    lVar6 = portMemAllocNonPaged(0x40);
    *(long *)(param_2 + 0x15e8) = lVar6;
    if (lVar6 == 0) {
      portMemFree(*(undefined8 *)(param_2 + 0x15e0));
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelib.c",0xaf,"knvlinkCoreAddDevice_IMPL",4
                   ,"NVRM: Failed to allocate memory for device name\n");
    }
    else {
      portMemSet(lVar6,0,0x40);
      portMemCopy(*(undefined8 *)(param_2 + 0x15e8),4,&DAT_00d6f704,4);
      pcVar9 = *(char **)(param_2 + 0x15e8);
      pcVar8 = pcVar9;
      if (*pcVar9 == '\0') {
        pcVar7 = (char *)0x40;
      }
      else {
        do {
          pcVar8 = pcVar8 + 1;
        } while (*pcVar8 != '\0');
        pcVar7 = pcVar9 + (0x40 - (long)pcVar8);
        pcVar9 = pcVar8;
      }
      knvlinkUtoa(pcVar9,pcVar7,*(undefined4 *)(param_1 + 0x7a4));
      lVar6 = portMemAllocNonPaged(0xd8);
      if (lVar6 != 0) {
        portMemSet(lVar6,0,0xd8);
        *(undefined8 *)(lVar6 + 0x28) = *(undefined8 *)(param_2 + 0x15e0);
        uVar1 = *(undefined8 *)(param_2 + 0x15e8);
        *(undefined8 *)(lVar6 + 0xa8) = 2;
        *(undefined8 *)(lVar6 + 0x30) = uVar1;
        *(undefined4 *)(lVar6 + 0x40) = *(undefined4 *)(param_1 + 0x87c);
        *(char *)(lVar6 + 0x44) = (char)((ulong)*(undefined8 *)(param_1 + 0x878) >> 8);
        uVar1 = *(undefined8 *)(param_1 + 0x878);
        *(undefined1 *)(lVar6 + 0x46) = 0;
        *(char *)(lVar6 + 0x45) = (char)uVar1;
        *(undefined4 *)(lVar6 + 0x48) = *(undefined4 *)(param_1 + 0x7f4);
        *(undefined8 *)(lVar6 + 0x60) = *(undefined8 *)(*(long *)(&DAT_00001b90 + param_1) + 0x560);
        uVar1 = *(undefined8 *)(*(long *)(&DAT_00001b90 + param_1) + 0x5a0);
        *(undefined1 *)(lVar6 + 0xb0) = 1;
        *(undefined8 *)(lVar6 + 0x68) = uVar1;
        *(undefined1 *)(lVar6 + 0xb1) = *(undefined1 *)(param_2 + 0x15ff);
        uVar3 = *(uint *)(param_2 + 0x310) - (*(uint *)(param_2 + 0x310) >> 1 & 0x55555555);
        uVar3 = (uVar3 >> 2 & 0x33333333) + (uVar3 & 0x33333333);
        *(uint *)(lVar6 + 0xb4) = (uVar3 + (uVar3 >> 4) & 0xf0f0f0f) * 0x1010101 >> 0x18;
        uVar4 = knvlinkGetNumActiveLinksPerIoctrl_IMPL(param_1,param_2);
        *(undefined4 *)(lVar6 + 0xbc) = uVar4;
        uVar4 = knvlinkGetTotalNumLinksPerIoctrl_IMPL(param_1,param_2);
        *(undefined4 *)(lVar6 + 0xb8) = uVar4;
        uVar2 = (**(code **)(param_2 + 0x2a0))(param_1,param_2);
        *(undefined1 *)(lVar6 + 0xc0) = uVar2;
        uVar4 = (**(code **)(param_2 + 0x2c0))(param_1,param_2);
        *(undefined4 *)(lVar6 + 0xd0) = uVar4;
        *(undefined1 *)(lVar6 + 0xd4) = *(undefined1 *)(param_2 + 0x2f5);
        iVar5 = nvlink_lib_register_device(lVar6);
        if (iVar5 == 0) {
          nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelib.c",0xe6,
                       "knvlinkCoreAddDevice_IMPL",1,
                       "NVRM: GPU registered successfully in NVLINK core\n");
          *(long *)(param_2 + 0x15d0) = lVar6;
          return 0;
        }
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelib.c",0xe1,"knvlinkCoreAddDevice_IMPL"
                     ,4,"NVRM: Failed to register GPU in NVLINK core!\n");
        portMemFree(*(undefined8 *)(param_2 + 0x15e0));
        portMemFree(*(undefined8 *)(param_2 + 0x15e8));
        portMemFree(lVar6);
        return 0;
      }
      portMemFree(*(undefined8 *)(param_2 + 0x15e0));
      portMemFree(*(undefined8 *)(param_2 + 0x15e8));
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelib.c",0xc4,"knvlinkCoreAddDevice_IMPL",4
                   ,"NVRM: Failed to create nvlink_device struct for GPU\n");
    }
  }
  return 0x51;
}


// ===== 00419af0 knvlinkCoreUpdateDeviceUUID_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int knvlinkCoreUpdateDeviceUUID_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  long lVar7;
  char *pcVar8;
  char *pcVar9;
  undefined1 local_4c [4];
  undefined8 local_48;
  undefined1 local_40 [16];
  
  iVar4 = 0;
  local_48 = 0;
  if (*(long *)(param_2 + 0x15d0) != 0) {
    if (*(char *)(param_1 + 0x7c4) == '\0') {
      iVar4 = gpuGetGidInfo_IMPL(param_1,&local_48,local_4c,2);
      if (iVar4 != 0) {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelib.c",0x125,
                     "knvlinkCoreUpdateDeviceUUID_IMPL",4,"NVRM: Failed to update GPU UUID\n");
        return iVar4;
      }
      bitVectorCopy_IMPL(local_40,0x40,param_2 + 0x388,0x40);
      uVar5 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
      while( true ) {
        cVar3 = bitVectorTestAllCleared_IMPL(local_40,0x40);
        if (cVar3 != '\0') break;
        lVar7 = (ulong)uVar5 * 0x78;
        lVar6 = param_2 + lVar7;
        if ((*(char *)(lVar6 + 0x400) != '\0') && (*(long *)(lVar6 + 0x3f0) == 2)) {
          iVar4 = 0;
          do {
            lVar6 = gpumgrGetGpu(iVar4);
            if (lVar6 != 0) {
              uVar2 = *(undefined8 *)(lVar6 + 0x878);
              lVar1 = param_2 + lVar7;
              if ((((*(int *)(lVar1 + 0x3d0) == (int)((ulong)uVar2 >> 0x20)) &&
                   (*(ushort *)(lVar1 + 0x3d4) == ((ushort)((ulong)uVar2 >> 8) & 0xff))) &&
                  (*(ushort *)(lVar1 + 0x3d6) == ((ushort)uVar2 & 0xff))) &&
                 (*(short *)(lVar1 + 0x3d8) == 0)) {
                if (*(long *)(lVar6 + 0x1ce8) != 0) {
                  portMemCopy(*(long *)(lVar6 + 0x1ce8) + 0x3e0 +
                              (ulong)*(uint *)(lVar1 + 0x3f8) * 0x78,0x10,param_1 + 0x7c5,0x10);
                }
                break;
              }
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 != 0x20);
        }
        bitVectorClr_IMPL(local_40,0x40,(ulong)uVar5);
        uVar5 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
      }
    }
    portMemSet(*(undefined8 *)(param_2 + 0x15e8),0,0x40);
    (**(code **)(param_1 + 0xa8))(param_1,*(undefined8 *)(param_2 + 0x15e8));
    pcVar9 = *(char **)(param_2 + 0x15e8);
    pcVar8 = pcVar9;
    if (*pcVar9 == '\0') {
      lVar6 = 0x40;
    }
    else {
      do {
        pcVar8 = pcVar8 + 1;
      } while (*pcVar8 != '\0');
      if ((long)pcVar8 - (long)pcVar9 < 0x40) {
        lVar6 = 0x40 - ((long)pcVar8 - (long)pcVar9);
        pcVar9 = pcVar8;
      }
      else {
        nvAssertFailedNoLog("(devIdx - pKernelNvlink->deviceName) < NVLINK_DEVICE_NAME_LENGTH",
                            "src/kernel/gpu/nvlink/kernel_nvlinkcorelib.c",0x138);
        lVar6 = 0x40 - ((long)pcVar8 - *(long *)(param_2 + 0x15e8));
        pcVar9 = pcVar8;
      }
    }
    knvlinkUtoa(pcVar9,lVar6,*(undefined4 *)(param_1 + 0x7a4));
    (**(code **)(param_2 + 0x2b0))(param_1,param_2,local_40);
    iVar4 = nvlink_lib_update_uuid_and_device_name
                      (local_40,local_48,*(undefined8 *)(param_2 + 0x15e8));
    *(undefined8 *)(param_2 + 0x15f0) = local_48;
  }
  return iVar4;
}


// ===== 00419de0 knvlinkCoreAddLink_IMPL =====

undefined4 knvlinkCoreAddLink_IMPL(long param_1,long param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  long lVar4;
  long lVar5;
  char *pcVar6;
  char *pcVar7;
  ulong uVar8;
  
  if (*(long *)(param_2 + 0x15d0) == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelib.c",0x172,"knvlinkCoreAddLink_IMPL",1,
                 "NVRM: NVLink device isn\'t available.\n");
    return 0x40;
  }
  uVar8 = (ulong)param_3;
  if ((*(char *)(param_1 + 0x4911) == '\0') || (*(char *)(param_2 + 0x15fc) != '\0')) {
    if (*(long *)(param_2 + 0x3c8 + uVar8 * 0x78) == 0) {
      pcVar3 = (char *)portMemAllocNonPaged(0x40);
      if (pcVar3 == (char *)0x0) {
        return 0x51;
      }
      portMemSet(pcVar3,0,0x40);
      portMemCopy(pcVar3,5,&DAT_00d6f8d1,5);
      pcVar7 = pcVar3;
      if (*pcVar3 == '\0') {
        pcVar6 = (char *)0x40;
      }
      else {
        do {
          pcVar7 = pcVar7 + 1;
        } while (*pcVar7 != '\0');
        pcVar6 = pcVar3 + (0x40 - (long)pcVar7);
      }
      knvlinkUtoa(pcVar7,pcVar6,uVar8);
      lVar4 = portMemAllocNonPaged(0xe0);
      if (lVar4 == 0) {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelib.c",0x19c,"knvlinkCoreAddLink_IMPL",
                     4,"NVRM: Failed to create nvlink_link struct\n");
        uVar2 = 0x51;
      }
      else {
        portMemSet(lVar4,0,0xe0);
        *(char **)(lVar4 + 0x30) = pcVar3;
        *(uint *)(lVar4 + 0x38) = param_3;
        *(undefined4 *)(lVar4 + 0x48) = 0;
        *(undefined8 *)(lVar4 + 0x50) = 0x700000007;
        *(undefined1 *)(lVar4 + 0x58) = 0;
        *(undefined1 *)(lVar4 + 0x5b) = 0;
        *(undefined4 *)(lVar4 + 0x5c) = *(undefined4 *)(param_2 + 0x314);
        *(undefined8 *)(lVar4 + 0x10) = *(undefined8 *)(param_2 + 0x15d0);
        *(ulong *)(lVar4 + 0x98) = param_2 + 0x3c8 + uVar8 * 0x78;
        lVar5 = osGetNvlinkLinkCallbacks();
        *(long *)(lVar4 + 0x90) = lVar5;
        if (lVar5 == 0) {
          nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelib.c",0x1b2,
                       "knvlinkCoreAddLink_IMPL",4,"NVRM: link handlers not found\n");
        }
        else {
          iVar1 = nvlink_lib_register_link(*(undefined8 *)(lVar4 + 0x10),lVar4);
          if (iVar1 == 0) {
            *(long *)(param_2 + 0x3c8 + uVar8 * 0x78) = lVar4;
            nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelib.c",0x1c2,
                         "knvlinkCoreAddLink_IMPL",1,
                         "NVRM: LINK%d: %s registered successfully in NVLINK core\n",uVar8,pcVar3);
            return 0;
          }
          nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelib.c",0x1ba,
                       "knvlinkCoreAddLink_IMPL",4,
                       "NVRM: Failed to register link %d in NVLINK core!\n",uVar8);
        }
        uVar2 = 0;
      }
      portMemFree(pcVar3);
      portMemFree(lVar4);
      return uVar2;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelib.c",0x183,"knvlinkCoreAddLink_IMPL",1,
                 "NVRM: Link %d already registered in NVLINK core!\n",uVar8);
  }
  else {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelib.c",0x17a,"knvlinkCoreAddLink_IMPL",1,
                 "NVRM: Skipping registration of link %d on simulation.\n",param_3);
  }
  return 0;
}


// ===== 0041a120 knvlinkCoreRemoveLink_IMPL =====

undefined8 knvlinkCoreRemoveLink_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  if (*(long *)(param_2 + 0x15d0) == 0) {
    nvAssertFailedNoLog("pKernelNvlink->pNvlinkDev != NULL",
                        "src/kernel/gpu/nvlink/kernel_nvlinkcorelib.c",0x1e9);
  }
  param_2 = (ulong)param_3 * 0x78 + param_2;
  if (*(long *)(param_2 + 0x3c8) != 0) {
    nvlink_lib_unregister_link();
    *(undefined8 *)(param_2 + 0x3c8) = 0;
    *(undefined1 *)(param_2 + 0x400) = 0;
  }
  return 0;
}


// ===== 0041a1a0 knvlinkCoreRemoveDevice_IMPL =====

undefined8 knvlinkCoreRemoveDevice_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  local_1c = 0;
  gpumgrGetGpuAttachInfo(0,&local_20);
  do {
    do {
      lVar1 = gpumgrGetNextGpu(local_20,&local_1c);
      if (lVar1 == 0) {
        lVar1 = *(long *)(param_2 + 0x15d0);
        if (lVar1 != 0) {
          nvlink_lib_unregister_device(lVar1);
          portMemFree(lVar1);
        }
        *(undefined8 *)(param_2 + 0x15d0) = 0;
        if (*(long *)(param_2 + 0x15e0) != 0) {
          portMemFree();
        }
        if (*(long *)(param_2 + 0x15e8) != 0) {
          portMemFree();
        }
        return 0;
      }
    } while ((lVar1 == param_1) || (*(long *)(lVar1 + 0x1ce8) == 0));
    uVar2 = knvlinkSetLinkMaskToPeer_IMPL(lVar1,*(long *)(lVar1 + 0x1ce8),param_1,0);
  } while ((int)uVar2 == 0);
  return uVar2;
}


// ===== 0041a270 knvlinkIsGpuConnectedToNvswitch_IMPL =====

undefined8 knvlinkIsGpuConnectedToNvswitch_IMPL(undefined8 param_1,long param_2)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined1 local_30 [16];
  
  uVar4 = 0;
  bitVectorCopy_IMPL(local_30,0x40,param_2 + 0x388,0x40);
  uVar1 = bitVectorCountTrailingZeros_IMPL(local_30,0x40);
  do {
    uVar2 = bitVectorTestAllCleared_IMPL(local_30,0x40);
    if ((char)uVar2 != '\0') {
      return uVar4;
    }
    lVar3 = (ulong)uVar1 * 0x78 + param_2;
    if (*(char *)(lVar3 + 0x400) != '\0') {
      if (*(long *)(lVar3 + 0x3f0) != 3) {
        return uVar2;
      }
      uVar4 = 1;
    }
    bitVectorClr_IMPL(local_30,0x40,(ulong)uVar1);
    uVar1 = bitVectorCountTrailingZeros_IMPL(local_30,0x40);
  } while( true );
}


// ===== 0041a340 _knvlinkCorePassiveLinkChangeCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _knvlinkCorePassiveLinkChangeCallback(undefined8 param_1,long *param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  int iVar6;
  long lVar7;
  
  lVar5 = g_pSys;
  param_2 = (long *)*param_2;
  lVar1 = *param_2;
  lVar2 = param_2[1];
  lVar3 = *(long *)(lVar1 + 0x98);
  lVar7 = gpumgrGetGpu();
  if (*(long *)(lVar3 + 0x50) != lVar7) {
    nvAssertFailedNoLog("pGpu == pNvlinkLink->pGpu",
                        "src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x161);
  }
  lVar4 = *(long *)(lVar7 + 0x1ce8);
  if (((lVar4 == 0) || (*(char *)(lVar4 + 0x15fa) == '\0')) && (*(char *)(lVar5 + 0x6b) == '\0')) {
    iVar6 = osAcquireRmSema(*(undefined8 *)(lVar5 + 0x160));
    if (iVar6 == 0) {
      iVar6 = (**(code **)(*(long *)(lVar1 + 0x90) + 0x10))(lVar1);
      if (iVar6 == 0) {
        iVar6 = (**(code **)(*(long *)(lVar2 + 0x90) + 0x10))();
        if (iVar6 == 0) {
          if (lVar4 == 0) {
            nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x187,
                         "_knvlinkCorePassiveLinkChangeCallback",4,
                         "NVRM: master GPU does not support NVLINK!\n");
          }
          else {
            knvlinkRetrainLink_IMPL(lVar7,lVar4,*(undefined1 *)(lVar3 + 0x58),(int)param_2[2] == 0);
          }
          (**(code **)(*(long *)(lVar2 + 0x90) + 0x18))();
        }
        else {
          nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",399,
                       "_knvlinkCorePassiveLinkChangeCallback",4,
                       "NVRM: failed to acquire slave lock!\n");
        }
        (**(code **)(*(long *)(lVar1 + 0x90) + 0x18))(lVar1);
      }
      else {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x195,
                     "_knvlinkCorePassiveLinkChangeCallback",4,
                     "NVRM: failed to acquire the master lock!\n");
      }
      osReleaseRmSema(*(undefined8 *)(lVar5 + 0x160),0);
      return;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x19b,
                 "_knvlinkCorePassiveLinkChangeCallback",4,
                 "NVRM: failed to acquire the RM semaphore!\n");
    return;
  }
  return;
}


// ===== 0041a560 knvlinkCoreAddLinkCallback =====

undefined8 knvlinkCoreAddLinkCallback(void)

{
  return 0;
}


// ===== 0041a570 knvlinkCoreRemoveLinkCallback =====

undefined8 knvlinkCoreRemoveLinkCallback(long param_1)

{
  portMemFree(*(undefined8 *)(param_1 + 0x30));
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(param_1 + 0x90) = 0;
  *(undefined8 *)(param_1 + 0x10) = 0;
  portMemFree(param_1);
  return 0;
}


// ===== 0041a5c0 knvlinkCoreLockLinkCallback =====

undefined8 knvlinkCoreLockLinkCallback(long param_1)

{
  long lVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  
  if (*(char *)(g_pSys + 0x6b) != '\0') {
    return 0;
  }
  lVar4 = gpumgrGetParentGPU(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x50));
  lVar1 = *(long *)(lVar4 + 0x1ce8);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pKernelNvlink != NULL",
                        "src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0xe0);
    uVar5 = 8;
  }
  else {
    cVar2 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar4 + 0x7a4));
    if (cVar2 == '\0') {
      iVar3 = rmDeviceGpuLocksAcquire(lVar4,0,0x20002);
      if (iVar3 != 0) {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x100,
                     "knvlinkCoreLockLinkCallback",1,"NVRM: failed to acquire device GPU locks!\n");
        return 7;
      }
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0xfa,
                   "knvlinkCoreLockLinkCallback",1,"NVRM: acquired device GPU locks\n");
      *(int *)(lVar1 + 0x15d8) = *(int *)(lVar1 + 0x15d8) + 1;
    }
    else if (*(int *)(lVar1 + 0x15d8) == 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0xf2,
                   "knvlinkCoreLockLinkCallback",1,
                   "NVRM: device lock acquired outside of the core library callbacks\n");
    }
    else {
      *(int *)(lVar1 + 0x15d8) = *(int *)(lVar1 + 0x15d8) + 1;
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0xed,
                   "knvlinkCoreLockLinkCallback",1,"NVRM: incremented device lock refcnt to %u\n");
    }
    uVar5 = 0;
  }
  return uVar5;
}


// ===== 0041a730 knvlinkCoreUnlockLinkCallback =====

void knvlinkCoreUnlockLinkCallback(long param_1)

{
  long lVar1;
  char cVar2;
  long lVar3;
  int iVar4;
  
  if (*(char *)(g_pSys + 0x6b) != '\0') {
    return;
  }
  lVar3 = gpumgrGetParentGPU(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x50));
  lVar1 = *(long *)(lVar3 + 0x1ce8);
  cVar2 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar3 + 0x7a4));
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(gpuGetInstance(pGpu))",
                        "src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x127);
    return;
  }
  if (lVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",299,
                 "knvlinkCoreUnlockLinkCallback",4,"NVRM: pKernelNvlink is NULL, returning early\n")
    ;
    return;
  }
  if (*(int *)(lVar1 + 0x15d8) != 0) {
    iVar4 = *(int *)(lVar1 + 0x15d8) + -1;
    *(int *)(lVar1 + 0x15d8) = iVar4;
    if (iVar4 == 0) {
      rmDeviceGpuLocksRelease(lVar3,0,0);
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x135,
                   "knvlinkCoreUnlockLinkCallback",1,"NVRM: released device GPU locks\n");
      return;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x139,
                 "knvlinkCoreUnlockLinkCallback",1,"NVRM: decremented device lock refcnt to %u\n");
    return;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x13f,
               "knvlinkCoreUnlockLinkCallback",1,
               "NVRM: device lock acquired outside of the core library callbacks\n");
  return;
}


// ===== 0041a890 knvlinkCoreQueueLinkChangeCallback =====

undefined8 knvlinkCoreQueueLinkChangeCallback(long *param_1)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  
  lVar1 = *(long *)(*(long *)(*param_1 + 0x98) + 0x50);
  if (lVar1 == 0) {
    return 8;
  }
  if (*(char *)(*param_1 + 0x28) == '\0') {
    nvAssertFailedNoLog("link_change->master->master",
                        "src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x1c4);
    uVar4 = 0x40;
  }
  else {
    puVar3 = (undefined8 *)portMemAllocNonPaged(8);
    if (puVar3 == (undefined8 *)0x0) {
      nvAssertFailedNoLog("pWorkItemData != NULL",
                          "src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x1c7);
      uVar4 = 2;
    }
    else {
      *puVar3 = param_1;
      iVar2 = osQueueWorkItem(lVar1,_knvlinkCorePassiveLinkChangeCallback,puVar3,0);
      uVar4 = 0;
      if (iVar2 != 0) {
        portMemFree(puVar3);
        uVar4 = 7;
      }
    }
  }
  return uVar4;
}


// ===== 0041a990 knvlinkCoreSetDlLinkModeCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 knvlinkCoreSetDlLinkModeCallback(long param_1,ulong param_2,int param_3)

{
  byte bVar1;
  long lVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  undefined1 *local_110;
  uint local_108 [2];
  undefined1 local_100;
  ulong local_f8;
  undefined1 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined8 local_e0;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined8 local_d0;
  undefined1 local_c8 [152];
  
  portMemSet(local_108,0,0x40);
  lVar2 = *(long *)(*(long *)(param_1 + 0x98) + 0x50);
  if (lVar2 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x1fe,
                 "knvlinkCoreSetDlLinkModeCallback",4,"NVRM: Error processing link info!\n");
    return 1;
  }
  bVar1 = *(byte *)(*(long *)(param_1 + 0x98) + 0x58);
  uVar7 = (ulong)bVar1;
  lVar9 = *(long *)(lVar2 + 0x1ce8);
  lVar8 = *(long *)(lVar9 + 0x2f8 + (ulong)*(uint *)(lVar9 + 0x424 + uVar7 * 0x78) * 8);
  if ((*(uint *)(lVar9 + 0x314) < 8) && (lVar8 == 0)) {
    return 0;
  }
  uVar4 = (**(code **)(lVar9 + 0x2c0))(lVar2,lVar9);
  if ((uVar4 >> ((uint)param_2 & 0x1f) & 1) == 0) {
    return 0;
  }
  if (*(char *)(lVar9 + 0x15fa) != '\0') {
    return 0;
  }
  local_f0 = param_3 == 1;
  uVar4 = (uint)bVar1;
  local_100 = 1;
  local_108[0] = uVar4;
  local_f8 = param_2;
  if (param_2 == 0x13) {
    local_ec = 0x13;
    if ((lVar8 != 0) && (*(char *)(lVar8 + 0x17a) != '\0')) {
      portMemCopy(&local_e8,0x1c,*(long *)(lVar9 + 0x3c8 + uVar7 * 0x78) + 0xb8,0x19);
    }
LAB_0041ac2c:
    iVar5 = knvlinkExecGspRmRpc_IMPL(lVar2,lVar9,0x20800a24,local_108,0x40);
    if (iVar5 != 0) goto LAB_0041ac4d;
  }
  else {
    if (param_2 < 0x14) {
      if (param_2 == 0) {
        local_ec = 0;
        iVar5 = knvlinkExecGspRmRpc_IMPL(lVar2,lVar9,0x20800a24,local_108,0x40);
        if (iVar5 == 0) {
          if (lVar8 == 0) {
            return 0;
          }
          if (*(char *)(lVar8 + 0x17a) == '\0') {
            return 0;
          }
          portMemCopy(*(long *)(lVar9 + 0x3c8 + uVar7 * 0x78) + 0xb8,0x1c,&local_e8,0x19);
          return 0;
        }
        goto LAB_0041ac4d;
      }
      if (param_2 == 0xe) {
        local_ec = 0xe;
        lVar8 = uVar7 * 0x78 + lVar9;
        local_e8 = (undefined4)*(undefined8 *)(lVar8 + 0x3f0);
        local_e4 = *(undefined4 *)(lVar8 + 0x3fc);
        goto LAB_0041ac2c;
      }
    }
    else {
      if (param_2 == 0x15) {
        local_ec = 0x15;
        iVar5 = knvlinkExecGspRmRpc_IMPL(lVar2,lVar9,0x20800a24,local_108,0x40);
        if (iVar5 == 0) {
          lVar9 = uVar7 * 0x78 + lVar9;
          *(char *)(*(long *)(lVar9 + 0x3c8) + 0x88) = (char)local_e8;
          *(undefined8 *)(*(long *)(lVar9 + 0x3c8) + 0x78) = local_e0;
          *(undefined4 *)(*(long *)(lVar9 + 0x3c8) + 0x84) = local_d8;
          *(undefined4 *)(*(long *)(lVar9 + 0x3c8) + 0x80) = local_d4;
          *(undefined8 *)(*(long *)(lVar9 + 0x3c8) + 0x70) = local_d0;
          return 0;
        }
        goto LAB_0041ac4d;
      }
      if (param_2 == 0x17) {
        local_110 = (undefined1 *)0x0;
        iVar5 = threadStateGetCurrent(&local_110,lVar2);
        bVar3 = false;
        if (iVar5 != 0) {
          nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x251,
                       "knvlinkCoreSetDlLinkModeCallback",1,"NVRM: Thread state not initialized!\n")
          ;
          threadStateInit(local_c8,0);
          iVar5 = threadStateGetCurrent(&local_110,lVar2);
          if (iVar5 != 0) {
            nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x260,
                         "knvlinkCoreSetDlLinkModeCallback",4,
                         "NVRM: Error getting current thread!\n");
            threadStateFree(local_c8,0);
            return 1;
          }
          bVar3 = true;
          if (local_110 != local_c8) {
            nvAssertFailedNoLog("pThreadNode == &threadNode",
                                "src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x265);
          }
        }
        threadStateSetTimeoutOverride
                  (local_110,(ulong)(uint)(*(int *)(lVar2 + 0x1b08) * 10000000) / 1000);
        local_ec = 0x17;
        do {
          iVar5 = knvlinkExecGspRmRpc_IMPL(lVar2,lVar9,0x20800a24,local_108,0x40);
          if (iVar5 != 0) {
            nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x27d,
                         "knvlinkCoreSetDlLinkModeCallback",4,
                         "NVRM: Error calling and polling for Init Optimize status! link 0x%x\n",
                         uVar4);
            uVar6 = 1;
LAB_0041ab63:
            if (bVar3) {
              threadStateFree(local_c8,0);
              return uVar6;
            }
            return uVar6;
          }
          if ((char)local_e8 != '\0') {
            uVar6 = 0;
            goto LAB_0041ab63;
          }
          osDelay(1000);
          osSpinLoop();
        } while( true );
      }
    }
    iVar5 = knvlinkExecGspRmRpc_IMPL(lVar2,lVar9,0x20800a24,local_108,0x40);
    if (iVar5 != 0) {
LAB_0041ac4d:
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x2a4,
                   "knvlinkCoreSetDlLinkModeCallback",4,
                   "NVRM: Error setting current link state: 0x%llx!\n",param_2);
      return 1;
    }
    if (param_2 == 0xb) {
      *(undefined1 *)(param_1 + 0x60) = 1;
    }
    else if ((0xb < param_2) && (param_2 == 0xc)) {
      *(undefined1 *)(param_1 + 0x60) = 0;
    }
  }
  return 0;
}


// ===== 0041af60 knvlinkCoreGetDlLinkModeCallback =====

undefined8 knvlinkCoreGetDlLinkModeCallback(long param_1,ulong *param_2)

{
  long lVar1;
  int iVar2;
  uint local_58 [2];
  undefined1 local_50;
  uint local_48;
  
  portMemSet(local_58,0,0x40);
  lVar1 = *(long *)(*(long *)(param_1 + 0x98) + 0x50);
  if (lVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x300,
                 "knvlinkCoreGetDlLinkModeCallback",4,"NVRM: Error processing link info!\n");
  }
  else {
    local_50 = 0;
    local_58[0] = (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x58);
    iVar2 = knvlinkExecGspRmRpc_IMPL(lVar1,*(undefined8 *)(lVar1 + 0x1ce8),0x20800a24,local_58,0x40)
    ;
    if (iVar2 == 0) {
      *param_2 = (ulong)local_48;
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x30e,
                 "knvlinkCoreGetDlLinkModeCallback",4,"NVRM: Error getting current link state!\n");
  }
  return 1;
}


// ===== 0041b040 knvlinkCoreSetTlLinkModeCallback =====

undefined8 knvlinkCoreSetTlLinkModeCallback(long param_1,undefined8 param_2,int param_3)

{
  long lVar1;
  int iVar2;
  uint local_68 [2];
  undefined1 local_60;
  undefined8 local_58;
  undefined1 local_50;
  
  portMemSet(local_68,0,0x40);
  lVar1 = *(long *)(*(long *)(param_1 + 0x98) + 0x50);
  if (lVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x336,
                 "knvlinkCoreSetTlLinkModeCallback",4,"NVRM: Error processing link info!\n");
    return 1;
  }
  if (*(char *)(*(long *)(lVar1 + 0x1ce8) + 0x15fa) == '\0') {
    local_50 = param_3 == 1;
    local_60 = 3;
    local_68[0] = (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x58);
    local_58 = param_2;
    iVar2 = knvlinkExecGspRmRpc_IMPL(lVar1,*(long *)(lVar1 + 0x1ce8),0x20800a24,local_68,0x40);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x34f,
                   "knvlinkCoreSetTlLinkModeCallback",4,"NVRM: Error setting current link state!\n")
      ;
      return 1;
    }
  }
  return 0;
}


// ===== 0041b130 knvlinkCoreGetTlLinkModeCallback =====

undefined8 knvlinkCoreGetTlLinkModeCallback(long param_1,ulong *param_2)

{
  long lVar1;
  int iVar2;
  uint local_58 [2];
  undefined1 local_50;
  uint local_48;
  
  portMemSet(local_58,0,0x40);
  lVar1 = *(long *)(*(long *)(param_1 + 0x98) + 0x50);
  if (lVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x372,
                 "knvlinkCoreGetTlLinkModeCallback",4,"NVRM: Error processing link info!\n");
  }
  else {
    local_50 = 2;
    local_58[0] = (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x58);
    iVar2 = knvlinkExecGspRmRpc_IMPL(lVar1,*(undefined8 *)(lVar1 + 0x1ce8),0x20800a24,local_58,0x40)
    ;
    if (iVar2 == 0) {
      *param_2 = (ulong)local_48;
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x380,
                 "knvlinkCoreGetTlLinkModeCallback",4,"NVRM: Error getting current link state!\n");
  }
  return 1;
}


// ===== 0041b210 knvlinkCoreSetTxSublinkModeCallback =====

undefined8 knvlinkCoreSetTxSublinkModeCallback(long param_1,long param_2,int param_3)

{
  long lVar1;
  int iVar2;
  uint local_68 [2];
  undefined1 local_60;
  long local_58;
  undefined1 local_50;
  
  portMemSet(local_68,0,0x40);
  lVar1 = *(long *)(*(long *)(param_1 + 0x98) + 0x50);
  if (lVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x3a7,
                 "knvlinkCoreSetTxSublinkModeCallback",4,"NVRM: Error processing link info!\n");
    return 1;
  }
  if (*(char *)(*(long *)(lVar1 + 0x1ce8) + 0x15fa) == '\0') {
    local_50 = param_3 == 1;
    local_60 = 5;
    local_68[0] = (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x58);
    local_58 = param_2;
    iVar2 = knvlinkExecGspRmRpc_IMPL(lVar1,*(long *)(lVar1 + 0x1ce8),0x20800a24,local_68,0x40);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x3c1,
                   "knvlinkCoreSetTxSublinkModeCallback",4,
                   "NVRM: Error setting TX sublink mode. mode = 0x%08llx\n",param_2);
      return 1;
    }
    if ((param_2 == 8) || (param_2 - 10U < 2)) {
      *(int *)(param_1 + 0x50) = (int)param_2;
    }
  }
  return 0;
}


// ===== 0041b330 knvlinkCoreSetRxSublinkModeCallback =====

undefined8 knvlinkCoreSetRxSublinkModeCallback(long param_1,long param_2,int param_3)

{
  long lVar1;
  int iVar2;
  uint local_48 [2];
  undefined1 local_40;
  long local_38;
  undefined1 local_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x98) + 0x50);
  if (lVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x3f1,
                 "knvlinkCoreSetRxSublinkModeCallback",4,"NVRM: Error processing link info!\n");
    return 1;
  }
  if (*(char *)(*(long *)(lVar1 + 0x1ce8) + 0x15fa) == '\0') {
    local_30 = param_3 == 1;
    local_48[0] = (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x58);
    local_40 = 7;
    local_38 = param_2;
    iVar2 = knvlinkExecGspRmRpc_IMPL(lVar1,*(long *)(lVar1 + 0x1ce8),0x20800a24,local_48,0x40);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x40c,
                   "knvlinkCoreSetRxSublinkModeCallback",4,"NVRM: Error setting RX sublink mode!\n")
      ;
      return 1;
    }
    if (param_2 - 8U < 2) {
      *(int *)(param_1 + 0x54) = (int)param_2;
    }
  }
  return 0;
}


// ===== 0041b420 knvlinkCoreGetTxSublinkModeCallback =====

undefined8 knvlinkCoreGetTxSublinkModeCallback(long param_1,ulong *param_2,undefined4 *param_3)

{
  long lVar1;
  int iVar2;
  uint local_68 [2];
  undefined1 local_60;
  undefined8 local_58;
  
  portMemSet(local_68,0,0x40);
  local_58 = 7;
  lVar1 = *(long *)(*(long *)(param_1 + 0x98) + 0x50);
  if (lVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x440,
                 "knvlinkCoreGetTxSublinkModeCallback",4,"NVRM: Error processing link info!\n");
  }
  else {
    local_60 = 4;
    local_68[0] = (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x58);
    iVar2 = knvlinkExecGspRmRpc_IMPL(lVar1,*(undefined8 *)(lVar1 + 0x1ce8),0x20800a24,local_68,0x40)
    ;
    if (iVar2 == 0) {
      *param_2 = local_58 & 0xffffffff;
      *param_3 = local_58._4_4_;
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x44f,
                 "knvlinkCoreGetTxSublinkModeCallback",4,
                 "NVRM: Error getting current TX sublink state!\n");
  }
  return 1;
}


// ===== 0041b520 knvlinkCoreGetRxSublinkModeCallback =====

undefined8 knvlinkCoreGetRxSublinkModeCallback(long param_1,ulong *param_2,undefined4 *param_3)

{
  long lVar1;
  int iVar2;
  uint local_68 [2];
  undefined1 local_60;
  undefined8 local_58;
  
  portMemSet(local_68,0,0x40);
  local_58 = 7;
  lVar1 = *(long *)(*(long *)(param_1 + 0x98) + 0x50);
  if (lVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x47b,
                 "knvlinkCoreGetRxSublinkModeCallback",4,"NVRM: Error processing link info!\n");
  }
  else {
    local_60 = 6;
    local_68[0] = (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x58);
    iVar2 = knvlinkExecGspRmRpc_IMPL(lVar1,*(undefined8 *)(lVar1 + 0x1ce8),0x20800a24,local_68,0x40)
    ;
    if (iVar2 == 0) {
      *param_2 = local_58 & 0xffffffff;
      *param_3 = local_58._4_4_;
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x48a,
                 "knvlinkCoreGetRxSublinkModeCallback",4,
                 "NVRM: Error getting current RX sublink state!\n");
  }
  return 1;
}


// ===== 0041b620 knvlinkCoreSetRxSublinkDetectCallback =====

undefined8 knvlinkCoreSetRxSublinkDetectCallback(long param_1,int param_2)

{
  long lVar1;
  int iVar2;
  uint local_58 [2];
  undefined1 local_50;
  undefined1 local_48;
  
  portMemSet(local_58,0,0x40);
  lVar1 = *(long *)(*(long *)(param_1 + 0x98) + 0x50);
  if (lVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x4b0,
                 "knvlinkCoreSetRxSublinkDetectCallback",4,"NVRM: Error processing link info!\n");
  }
  else {
    local_48 = param_2 == 1;
    local_50 = 9;
    local_58[0] = (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x58);
    iVar2 = knvlinkExecGspRmRpc_IMPL(lVar1,*(undefined8 *)(lVar1 + 0x1ce8),0x20800a24,local_58,0x40)
    ;
    if (iVar2 == 0) {
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x4c4,
                 "knvlinkCoreSetRxSublinkDetectCallback",4,
                 "NVRM: Error performing RXDET (Receiver Detect) on link!\n");
  }
  return 1;
}


// ===== 0041b700 knvlinkCoreGetRxSublinkDetectCallback =====

undefined8 knvlinkCoreGetRxSublinkDetectCallback(long param_1)

{
  byte bVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  uint local_68 [2];
  undefined1 local_60;
  undefined4 local_58;
  
  portMemSet(local_68,0,0x40);
  lVar2 = *(long *)(*(long *)(param_1 + 0x98) + 0x50);
  if (lVar2 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x4ea,
                 "knvlinkCoreGetRxSublinkDetectCallback",4,"NVRM: Error processing link info!\n");
  }
  else {
    lVar3 = *(long *)(lVar2 + 0x1ce8);
    bVar1 = *(byte *)(*(long *)(param_1 + 0x98) + 0x58);
    local_60 = 8;
    local_68[0] = (uint)bVar1;
    iVar4 = knvlinkExecGspRmRpc_IMPL(lVar2,lVar3,0x20800a24,local_68,0x40);
    *(undefined4 *)(lVar3 + 0x430 + (ulong)bVar1 * 0x78) = local_58;
    *(bool *)(param_1 + 0x58) = iVar4 == 0;
    if (iVar4 == 0) {
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x503,
                 "knvlinkCoreGetRxSublinkDetectCallback",1,
                 "NVRM: RXDET (Receiver Detect) failed on link!\n");
  }
  return 1;
}


// ===== 0041b800 knvlinkCoreWriteDiscoveryTokenCallback =====

int knvlinkCoreWriteDiscoveryTokenCallback(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  uint local_68 [2];
  undefined1 local_60;
  undefined7 uStack_5f;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  
  lVar1 = *(long *)(param_1 + 0x98);
  lVar2 = *(long *)(lVar1 + 0x50);
  if (lVar2 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x520,
                 "knvlinkCoreWriteDiscoveryTokenCallback",4,"NVRM: Error processing link info!\n");
    return 1;
  }
  uVar3 = *(undefined8 *)(lVar2 + 0x1ce8);
  if (*(uint *)(lVar1 + 0x60) < 7) {
    portMemSet(local_68,0,0x40);
    local_60 = 10;
    local_68[0] = (uint)*(byte *)(lVar1 + 0x58);
    local_58 = *(undefined4 *)(lVar1 + 0x60);
    local_50 = param_2;
    iVar4 = knvlinkExecGspRmRpc_IMPL(lVar2,uVar3,0x20800a24,local_68,0x40);
    if (iVar4 != 0) {
      if (iVar4 != 0x56) {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x55c,
                     "knvlinkCoreWriteDiscoveryTokenCallback",4,
                     "NVRM: Error writing Discovery Token!\n");
        return 1;
      }
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x560,
                   "knvlinkCoreWriteDiscoveryTokenCallback",1,
                   "NVRM: R4 Tokens not supported on the chip!\n");
      return 1;
    }
  }
  else {
    portMemSet(local_68,0,0x20);
    local_68[0] = (uint)*(byte *)(lVar1 + 0x58);
    iVar4 = knvlinkExecGspRmRpc_IMPL(lVar2,uVar3,0x20800a25,local_68,0x20);
    if (iVar4 != 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x535,
                   "knvlinkCoreWriteDiscoveryTokenCallback",4,
                   "NVRM: Error updating Local/Remote SID Info!\n");
      return iVar4;
    }
    *(ulong *)(param_1 + 0x78) = CONCAT71(uStack_5f,local_60);
    *(ulong *)(param_1 + 0x80) = CONCAT44(local_58,local_54);
    *(undefined8 *)(param_1 + 0x70) = local_50;
  }
  return 0;
}


// ===== 0041b9e0 knvlinkCoreReadDiscoveryTokenCallback =====

undefined8 knvlinkCoreReadDiscoveryTokenCallback(long param_1,undefined8 *param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  uint local_68 [2];
  undefined1 local_60;
  uint local_58;
  undefined8 local_50;
  
  lVar1 = *(long *)(param_1 + 0x98);
  lVar2 = *(long *)(lVar1 + 0x50);
  portMemSet(local_68,0,0x40);
  if (param_2 == (undefined8 *)0x0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x583,
                 "knvlinkCoreReadDiscoveryTokenCallback",4,"NVRM: Bad token address provided!\n");
  }
  else if (lVar2 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x589,
                 "knvlinkCoreReadDiscoveryTokenCallback",4,"NVRM: Error processing link info!\n");
  }
  else {
    if (*(uint *)(lVar1 + 0x60) < 7) {
      local_60 = 0xb;
      local_68[0] = (uint)*(byte *)(lVar1 + 0x58);
      local_58 = *(uint *)(lVar1 + 0x60);
      iVar3 = knvlinkExecGspRmRpc_IMPL
                        (lVar2,*(undefined8 *)(lVar2 + 0x1ce8),0x20800a24,local_68,0x40);
      if (iVar3 == 0) {
        *param_2 = local_50;
        return 0;
      }
      if (iVar3 != 0x56) {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x5a7,
                     "knvlinkCoreReadDiscoveryTokenCallback",4,
                     "NVRM: Error reading discovery token!\n");
        return 1;
      }
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x5ab,
                 "knvlinkCoreReadDiscoveryTokenCallback",1,
                 "NVRM: R4 Tokens not supported on the chip!\n");
  }
  return 1;
}


// ===== 0041bb50 knvlinkCoreTrainingCompleteCallback =====

void knvlinkCoreTrainingCompleteCallback(long param_1)

{
  long lVar1;
  int iVar2;
  uint local_58 [2];
  undefined1 local_50;
  
  portMemSet(local_58,0,0x40);
  local_50 = 0xc;
  lVar1 = *(long *)(*(long *)(param_1 + 0x98) + 0x50);
  local_58[0] = (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x58);
  iVar2 = knvlinkExecGspRmRpc_IMPL(lVar1,*(undefined8 *)(lVar1 + 0x1ce8),0x20800a24,local_58,0x40);
  if (iVar2 == 0) {
    return;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x5d6,
               "knvlinkCoreTrainingCompleteCallback",4,
               "NVRM: Error issuing NvLink Training Complete callback!\n");
  return;
}


// ===== 0041bbe0 knvlinkCoreAliTrainingCallback =====

undefined8 knvlinkCoreAliTrainingCallback(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  
  lVar1 = *(long *)(param_1 + 0x98);
  lVar2 = *(long *)(lVar1 + 0x50);
  if (lVar2 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x5f6,
                 "knvlinkCoreAliTrainingCallback",4,"NVRM: Error processing link info!\n");
  }
  else {
    lVar3 = *(long *)(lVar2 + 0x1ce8);
    if (7 < *(uint *)(lVar3 + 0x314)) {
      return 0;
    }
    iVar4 = knvlinkPreTrainLinksToActiveAli_IMPL
                      (lVar2,lVar3,1 << (*(byte *)(lVar1 + 0x58) & 0x1f),1);
    if ((iVar4 == 0) &&
       (iVar4 = knvlinkTrainLinksToActiveAli_IMPL
                          (lVar2,lVar3,1 << (*(byte *)(lVar1 + 0x58) & 0x1f),0), iVar4 == 0)) {
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x60b,
                 "knvlinkCoreAliTrainingCallback",4,
                 "NVRM: Failed to request Link %d to transition to active\n",
                 *(undefined1 *)(lVar1 + 0x58));
  }
  return 1;
}


// ===== 0041bcc0 knvlinkCoreGetUphyLoadCallback =====

void knvlinkCoreGetUphyLoadCallback(long param_1,undefined1 *param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  uint local_68 [2];
  undefined1 local_60;
  undefined1 local_58;
  
  lVar1 = *(long *)(param_1 + 0x98);
  lVar2 = *(long *)(lVar1 + 0x50);
  portMemSet(local_68,0,0x40);
  if (lVar2 != 0) {
    local_60 = 0xd;
    local_68[0] = (uint)*(byte *)(lVar1 + 0x58);
    iVar3 = knvlinkExecGspRmRpc_IMPL(lVar2,*(undefined8 *)(lVar2 + 0x1ce8),0x20800a24,local_68,0x40)
    ;
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x63f,
                   "knvlinkCoreGetUphyLoadCallback",4,
                   "NVRM: Error issuing NvLink Get Uphy Load callback!\n");
    }
    *param_2 = local_58;
    return;
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibcallback.c",0x62d,
               "knvlinkCoreGetUphyLoadCallback",4,"NVRM: Error processing link info!\n");
  return;
}


// ===== 0041bdb0 _knvlinkGetNumPortEvents =====

undefined4 _knvlinkGetNumPortEvents(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_630 [16];
  undefined4 local_620;
  
  memset(local_630,0,0x618);
  iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20803044,local_630,0x618);
  uVar2 = 0;
  if (iVar1 == 0) {
    uVar2 = local_620;
  }
  return uVar2;
}


// ===== 0041be20 _knvlinkPrintTopologySummary =====

long _knvlinkPrintTopologySummary(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  int local_1c;
  
  lVar2 = nvDbgRmMsgCheck("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x9f9,
                          "_knvlinkPrintTopologySummary",1,0,0);
  if ((int)lVar2 == 2) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x9fe,
                 "_knvlinkPrintTopologySummary",1,"NVRM: GPU%02u cached topology:\n",
                 *(undefined4 *)(param_1 + 0x7a4));
    portMemSet(&local_1c,0,4);
    iVar1 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800aab,&local_1c,4);
    if (iVar1 == 0) {
      if (local_1c != 0) {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0xa0f,
                     "_knvlinkPrintTopologySummary",1,"NVRM:     sysmem link mask : 0x%x\n");
      }
      uVar3 = 0;
      do {
        while (lVar2 = *(long *)(param_2 + 0x14c8 + uVar3 * 8), lVar2 != 0) {
          uVar4 = uVar3 & 0xffffffff;
          uVar3 = uVar3 + 1;
          nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0xa17,
                       "_knvlinkPrintTopologySummary",1,"NVRM:     GPU%02u link mask  : 0x%llx\n",
                       uVar4);
          if (uVar3 == 0x20) goto LAB_0041bf31;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 != 0x20);
LAB_0041bf31:
      if (*(long *)(param_2 + 0x14b8) != 0) {
        lVar2 = nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0xa1f,
                             "_knvlinkPrintTopologySummary",1,
                             "NVRM:     unknown link mask: 0x%llx\n");
      }
    }
    else {
      lVar2 = nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0xa08,
                           "_knvlinkPrintTopologySummary",4,
                           "NVRM: Unable to determine sysmem link mask\n");
    }
  }
  return lVar2;
}


// ===== 0041bfd0 knvlinkFloorSweep_IMPL.part.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int knvlinkFloorSweep_IMPL_part_0(long param_1,long param_2,int *param_3)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  uint uVar8;
  undefined1 local_d8 [8];
  undefined1 local_d0 [56];
  undefined1 local_98 [16];
  undefined1 local_88;
  char acStack_87 [87];
  
  lVar1 = param_2 + 0x388;
  bitVectorCopy_IMPL(local_98,0x40,lVar1,0x40);
  uVar3 = bitVectorCountTrailingZeros_IMPL(local_98,0x40);
  while( true ) {
    cVar2 = bitVectorTestAllCleared_IMPL(local_98,0x40);
    if (cVar2 != '\0') break;
    nvlink_lib_discover_and_get_remote_conn_info
              (*(undefined8 *)(param_2 + 0x3c8 + (ulong)uVar3 * 0x78),local_d0,0,0);
    bitVectorClr_IMPL(local_98,0x40,(ulong)uVar3);
    uVar3 = bitVectorCountTrailingZeros_IMPL(local_98,0x40);
  }
  (**(code **)(param_2 + 0x298))(param_1,param_2);
  nvlink_lib_powerdown_floorswept_links_to_off(*(undefined8 *)(param_2 + 0x15d0));
  portMemSet(local_98,0,0x58);
  iVar4 = convertBitVectorToLinkMasks(lVar1,0,0,local_98);
  if (iVar4 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar4,
               "convertBitVectorToLinkMasks(&pKernelNvlink->enabledLinks, NULL, 0, &linkTrainedParams.linkMask)"
               ,"src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x58b);
    return iVar4;
  }
  local_88 = 1;
  if (*(char *)(param_1 + 0x909) != '\0') {
    threadStateResetTimeout(param_1);
  }
  iVar4 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a90,local_98,0x58);
  if (iVar4 != 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x59c,"knvlinkFloorSweep_IMPL",
                 4,"NVRM: Failed to get the link train status for links\n");
    return iVar4;
  }
  uVar8 = 0;
  bitVectorCopy_IMPL(local_d8,0x40,lVar1,0x40);
  uVar5 = bitVectorCountTrailingZeros_IMPL(local_d8,0x40);
  uVar3 = 0;
  while( true ) {
    cVar2 = bitVectorTestAllCleared_IMPL(local_d8,0x40);
    if (cVar2 != '\0') break;
    uVar6 = 1 << ((byte)uVar5 & 0x1f);
    if (acStack_87[uVar5] == '\0') {
      uVar3 = uVar3 | uVar6;
    }
    else {
      uVar8 = uVar8 | uVar6;
    }
    bitVectorClr_IMPL(local_d8,0x40,(ulong)uVar5);
    uVar5 = bitVectorCountTrailingZeros_IMPL(local_d8,0x40);
  }
  iVar4 = convertMaskToBitVector((ulong)uVar8,lVar1);
  if (iVar4 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar4,
               "convertMaskToBitVector((NvU64)tmpEnabledLinkMask, &pKernelNvlink->enabledLinks)",
               "src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x5b2);
    return iVar4;
  }
  *(uint *)(param_2 + 0x368) = uVar3;
  *(ulong *)(param_2 + 0x14b8) = (ulong)uVar8;
  iVar4 = knvlinkProcessInitDisabledLinks_IMPL(param_1,param_2);
  uVar7 = 0x5c0;
  if (iVar4 == 0) {
    iVar4 = knvlinkSyncLinkMasksAndVbiosInfo_IMPL(param_1,param_2,0x5c0);
    if (iVar4 == 0) {
      uVar8 = uVar8 - (uVar8 >> 1 & 0x55555555);
      uVar3 = (uVar8 & 0x33333333) + (uVar8 >> 2 & 0x33333333);
      uVar5 = *(uint *)(param_2 + 0x310) - (*(uint *)(param_2 + 0x310) >> 1 & 0x55555555);
      uVar8 = ((uVar3 >> 4) + uVar3 & 0xf0f0f0f) * 0x1010101 >> 0x18;
      uVar3 = (uVar5 & 0x33333333) + (uVar5 >> 2 & 0x33333333);
      uVar3 = (((uVar3 >> 4) + uVar3 & 0xf0f0f0f) * 0x1010101 >> 0x18) * *param_3;
      if (uVar8 <= uVar3) {
        *(undefined1 *)(param_2 + 0x1600) = 1;
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x5d2,
                   "knvlinkFloorSweep_IMPL",1,
                   "NVRM: Floorsweeping didn\'t work! enabledMaskCount: 0x%x and numActiveLinksTotal: 0x%x. Current link info cached in SW: discoveredLinks:0x%llxenabledLinks: 0x%llx; disconnectedLinks:0x%llx; initDisabledLinksMask:0x%x\n"
                   ,uVar8,uVar3,*(undefined8 *)(param_2 + 0x350),*(undefined8 *)(param_2 + 0x388),
                   *(undefined8 *)(param_2 + 0x14b8),*(undefined4 *)(param_2 + 0x368));
      return 0x55;
    }
    uVar7 = 0x5c8;
  }
  nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",uVar7);
  return iVar4;
}


// ===== 0041c430 knvlinkTrainSysmemLinksToActive_IMPL =====

undefined8 knvlinkTrainSysmemLinksToActive_IMPL(long param_1,long param_2)

{
  ulong uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  undefined1 local_30 [8];
  
  if (*(char *)(param_1 + 0x4910) == '\0') {
    if (*(char *)(param_2 + 0x15fa) == '\0') {
      if (*(char *)(g_pSys + 0x6b) == '\0') {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x151,
                     "knvlinkTrainSysmemLinksToActive_IMPL",1,
                     "NVRM: Training sysmem links for GPU%d\n",*(undefined4 *)(param_1 + 0x7a4));
        bitVectorCopy_IMPL(local_30,0x40,param_2 + 0x388,0x40);
        uVar3 = bitVectorCountTrailingZeros_IMPL(local_30,0x40);
        while( true ) {
          uVar6 = (ulong)uVar3;
          cVar2 = bitVectorTestAllCleared_IMPL(local_30,0x40);
          if (cVar2 != '\0') break;
          lVar5 = uVar6 * 0x78 + param_2;
          if ((*(char *)(lVar5 + 0x400) != '\0') &&
             ((uVar1 = *(ulong *)(lVar5 + 0x3f0), uVar1 == 4 || (uVar1 < 2)))) {
            iVar4 = nvlink_lib_train_links_from_swcfg_to_active(param_2 + 0x3c8 + uVar6 * 0x78,1,1);
            if (iVar4 != 0) {
              param_2 = param_2 + uVar6 * 0x78;
              nvErrorLog_va(param_1,0x4a,
                            "NVLink: failed to train link %d to remote PCI:%04x:%02x:%02x",uVar6,
                            *(undefined4 *)(param_2 + 0x3d0),*(undefined2 *)(param_2 + 0x3d4),
                            *(undefined2 *)(param_2 + 0x3d6));
              gpuNotifySubDeviceEvent_IMPL(param_1,0x7b,0,0,0,0);
              return 0x56;
            }
          }
          bitVectorClr_IMPL(local_30,0x40,uVar6);
          uVar3 = bitVectorCountTrailingZeros_IMPL(local_30,0x40);
        }
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x173,
                     "knvlinkTrainSysmemLinksToActive_IMPL",1,
                     "NVRM: resetting timeout after link training\n");
        threadStateResetTimeout(param_1);
      }
      else {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x14b,
                     "knvlinkTrainSysmemLinksToActive_IMPL",1,
                     "NVRM: Fabric is externally managed, skip link training\n");
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x141,
                   "knvlinkTrainSysmemLinksToActive_IMPL",1,
                   "NVRM: Skipping link training due to regkey on GPU%d\n",
                   *(undefined4 *)(param_1 + 0x7a4));
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x137,
                 "knvlinkTrainSysmemLinksToActive_IMPL",1,
                 "NVRM: Skipping unsupported sysmem link training on GPU%d\n",
                 *(undefined4 *)(param_1 + 0x7a4));
  }
  return 0;
}


// ===== 0041c6c0 knvlinkCoreGetRemoteDeviceInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

int knvlinkCoreGetRemoteDeviceInfo_IMPL(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  ushort uVar6;
  bool bVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  long lVar14;
  long lVar15;
  ulong uVar16;
  long lVar17;
  byte bVar18;
  int iVar19;
  ulong uVar20;
  uint uVar21;
  ulong uVar22;
  ulong uVar23;
  long lVar24;
  ulong uVar25;
  undefined8 *puVar26;
  bool bVar27;
  undefined4 local_88;
  undefined4 local_84;
  ulong local_80;
  undefined2 local_78;
  undefined6 uStack_76;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar17 = g_pSys;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_88 = 0;
  cVar9 = (**(code **)(param_2 + 0x218))();
  if (cVar9 == '\0') {
    if (*(char *)(lVar17 + 0x6b) == '\0') {
      if (*(long *)(param_2 + 0x14b8) == 0) {
        if (*(uint *)(param_2 + 0x314) < 7) {
          return 0;
        }
        if (*(long *)(param_2 + 0x15d0) == 0) {
          return 0;
        }
        goto LAB_0041c788;
      }
      bVar27 = true;
      cVar9 = '\0';
LAB_0041c905:
      if (*(char *)(param_2 + 0x15ff) != '\0') {
        knvlinkUpdatePostRxDetectLinkMask_IMPL(param_1,param_2);
      }
      if ((6 < *(uint *)(param_2 + 0x314)) && (bVar27)) {
        if (*(char *)(lVar17 + 0x6b) == '\0') goto LAB_0041c8e7;
        goto LAB_0041c797;
      }
    }
    else {
      cVar9 = knvlinkIsNvswitchProxyPresent_IMPL(param_1,param_2);
      bVar27 = cVar9 == '\0';
      if (*(long *)(param_2 + 0x14b8) != 0) goto LAB_0041c905;
      if (*(uint *)(param_2 + 0x314) < 7) {
        return 0;
      }
      if (!bVar27) {
        return 0;
      }
      if (*(char *)(lVar17 + 0x6b) != '\0') {
        return 0;
      }
LAB_0041c8e7:
      if (*(long *)(param_2 + 0x15d0) != 0) {
LAB_0041c788:
        if (*(char *)(param_2 + 0x1600) == '\0') {
          uVar13 = knvlinkGetTotalNumLinksPerIoctrl_IMPL(param_1,param_2);
          local_88 = knvlinkGetNumActiveLinksPerIoctrl_IMPL(param_1,param_2);
          cVar10 = (**(code **)(param_2 + 0x2a8))
                             (param_1,param_2,local_88,uVar13,*(code **)(param_2 + 0x2a8));
          cVar9 = '\0';
          if (cVar10 != '\0') {
            iVar19 = knvlinkFloorSweep_IMPL_part_0(param_1,param_2,&local_88);
            cVar9 = '\0';
            if (iVar19 != 0) {
              nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x81,
                           "knvlinkCoreGetRemoteDeviceInfo_IMPL",4,
                           "NVRM: Failed to floorsweep valid nvlink config!\n");
              return 0x55;
            }
          }
          goto LAB_0041c7a0;
        }
      }
LAB_0041c797:
      cVar9 = '\0';
    }
LAB_0041c7a0:
    uVar23 = *(ulong *)(param_2 + 0x14b8);
    if (uVar23 == 0) {
      return 0;
    }
    cVar10 = '\0';
    lVar24 = param_2 + 0x3e0;
    iVar19 = 0;
    bVar27 = false;
    bVar18 = 1;
joined_r0x0041c7e4:
    for (; (uVar23 & 1) == 0; uVar23 = uVar23 >> 1) {
      iVar19 = iVar19 + 1;
      lVar24 = lVar24 + 0x78;
    }
    if (((*(char *)(param_2 + 0x15ff) == '\0') ||
        (cVar8 = bitVectorTest_IMPL(param_2 + 0x14b0,0x40,iVar19), cVar8 != '\0')) &&
       (*(long *)(lVar24 + -0x18) != 0)) {
      if (*(char *)(lVar17 + 0x6b) == '\0') {
        bVar18 = bVar18 & *(int *)(param_2 + 0x314) != 4;
        nvlink_lib_discover_and_get_remote_conn_info(*(long *)(lVar24 + -0x18),&local_70,bVar18,0);
        if (*(char *)(lVar24 + 0x20) == local_48._4_1_) {
          if (local_48._4_1_ == '\0') goto joined_r0x0041c872;
          bVar7 = false;
          goto LAB_0041cb1b;
        }
        *(char *)(lVar24 + 0x20) = local_48._4_1_;
        if (local_48._4_1_ != '\0') {
          bVar7 = true;
          goto LAB_0041cb1b;
        }
      }
      else {
        cVar8 = gpuFabricProbeIsSupported(param_1);
        if (cVar8 == '\0') {
          nvlink_lib_get_remote_conn_info(*(undefined8 *)(lVar24 + -0x18),&local_70);
        }
        else {
          uVar21 = _knvlinkGetNumPortEvents(param_1,param_2);
          if (*(uint *)(param_2 + 0x1604) < uVar21) {
            nvlink_lib_discover_and_get_remote_conn_info
                      (*(undefined8 *)(lVar24 + -0x18),&local_70,bVar18,1);
          }
          else {
            nvlink_lib_discover_and_get_remote_conn_info
                      (*(undefined8 *)(lVar24 + -0x18),&local_70,bVar18,cVar10);
            if (cVar10 == '\0') goto LAB_0041caf2;
          }
          *(uint *)(param_2 + 0x1604) = uVar21;
          cVar10 = '\x01';
        }
LAB_0041caf2:
        if (local_48._4_1_ == '\0') {
          if ((cVar9 == '\0') &&
             ((*(char *)(lVar17 + 0x6a) != '\0' || (*(char *)(param_1 + 0x4cc) != '\x01')))) {
            if (*(char *)(lVar24 + 0x20) != '\0') {
              *(undefined1 *)(lVar24 + 0x20) = 0;
              goto LAB_0041c856;
            }
            goto joined_r0x0041c872;
          }
          local_48._0_5_ = CONCAT14(1,(undefined4)local_48);
          local_50 = 3;
          local_68 = CONCAT44(0xffffffff,(undefined4)local_68);
          local_70 = 0xffffffffffffffff;
          local_68 = CONCAT62(local_68._2_6_,0xffff);
          bVar7 = false;
          bVar27 = true;
          if (*(char *)(lVar24 + 0x20) != '\x01') {
            *(undefined1 *)(lVar24 + 0x20) = 1;
            goto LAB_0041cb0e;
          }
        }
        else if (local_48._4_1_ == *(char *)(lVar24 + 0x20)) {
          bVar27 = true;
          bVar7 = false;
        }
        else {
          *(char *)(lVar24 + 0x20) = local_48._4_1_;
LAB_0041cb0e:
          bVar27 = true;
          bVar7 = true;
        }
LAB_0041cb1b:
        *(undefined4 *)(lVar24 + -0x10) = (undefined4)local_70;
        *(undefined4 *)(lVar24 + -0xc) = local_70._4_4_;
        *(undefined2 *)(lVar24 + -8) = (undefined2)local_68;
        *(undefined4 *)(lVar24 + -4) = local_68._4_4_;
        *(undefined8 *)(lVar24 + 0x10) = local_50;
        *(undefined4 *)(lVar24 + 0x18) = (undefined4)local_48;
        *(undefined8 *)(lVar24 + 0x28) = local_40;
        nvlink_memcpy(lVar24,&local_60,0x10);
        if (!bVar7) goto joined_r0x0041c872;
      }
LAB_0041c856:
      iVar11 = knvlinkUpdateLinkConnectionStatus_IMPL(param_1,param_2,iVar19);
      if (iVar11 != 0) {
        return iVar11;
      }
    }
joined_r0x0041c872:
    if (uVar23 >> 1 != 0) {
      uVar23 = uVar23 >> 1;
      iVar19 = iVar19 + 1;
      lVar24 = lVar24 + 0x78;
      goto joined_r0x0041c7e4;
    }
    local_80 = 0;
    uVar23 = *(ulong *)(param_2 + 0x14b8);
    if (bVar27) {
      iVar19 = (**(code **)(param_2 + 0x210))(param_1,param_2,&local_80);
      if (uVar23 == 0) {
        uVar22 = *(ulong *)(param_2 + 0x14b8);
        bVar27 = false;
LAB_0041d062:
        if (uVar22 != uVar23) {
          iVar11 = bitVectorGetSlice_IMPL(param_2 + 0x388,0x40,0,0x3f,&local_78);
          uVar23 = CONCAT62(uStack_76,local_78);
          if (iVar11 != 0) {
            nvAssertFailedNoLog("(bitVectorGetSlice(pSrc, rangeMake(0, 63), &localMask) == NV_OK)",
                                "generated/g_kernel_nvlink_nvoc.h",0x8fd);
            uVar23 = 0;
          }
          uVar25 = local_80;
          if (uVar22 == uVar23) {
            bVar18 = 0;
            iVar11 = 0;
            do {
              lVar17 = gpumgrGetGpu(iVar11);
              if ((lVar17 != 0) &&
                 ((((*(char *)(lVar17 + 0x4918) != '\0' || (*(char *)(lVar17 + 0x4916) != '\0')) &&
                   (lVar24 = *(long *)(lVar17 + 0x1ce8), lVar24 != 0)) &&
                  ((cVar9 = bitVectorTestAllCleared_IMPL(param_2 + 0x350,0x40), cVar9 == '\0' &&
                   (cVar9 = knvlinkIsGpuConnectedToNvswitch_IMPL(lVar17,lVar24), cVar9 != '\0'))))))
              {
                iVar12 = knvlinkSetLinkMaskToPeer_IMPL(param_1,param_2,lVar17,0);
                if ((iVar12 != 0) ||
                   (iVar12 = knvlinkSetLinkMaskToPeer_IMPL(lVar17,lVar24,param_1,0), iVar12 != 0))
                goto LAB_0041d189;
                bVar18 = 1;
              }
              iVar11 = iVar11 + 1;
            } while (iVar11 != 0x20);
            bVar27 = (bool)(bVar27 | bVar18);
          }
          else {
            cVar9 = knvlinkIsGpuConnectedToNvswitch_IMPL(param_1,param_2);
            if (cVar9 != '\0') {
              bVar18 = 0;
              iVar11 = 0;
              do {
                lVar17 = gpumgrGetGpu(iVar11);
                if ((((lVar17 != 0) &&
                     ((*(char *)(lVar17 + 0x4918) != '\0' || (*(char *)(lVar17 + 0x4916) != '\0'))))
                    && (lVar24 = *(long *)(lVar17 + 0x1ce8), lVar24 != 0)) &&
                   ((cVar9 = bitVectorTestAllCleared_IMPL(param_2 + 0x350,0x40), cVar9 == '\0' &&
                    (cVar9 = knvlinkIsGpuConnectedToNvswitch_IMPL(lVar17,lVar24), cVar9 != '\0'))))
                {
                  iVar12 = knvlinkSetLinkMaskToPeer_IMPL(param_1,param_2,lVar17,uVar25);
                  if ((iVar12 != 0) ||
                     (iVar12 = knvlinkSetLinkMaskToPeer_IMPL
                                         (lVar17,lVar24,param_1,
                                          *(undefined8 *)
                                           (lVar24 + 0x14c8 + (ulong)*(uint *)(lVar17 + 0x7a4) * 8))
                     , iVar12 != 0)) goto LAB_0041d189;
                  bVar18 = 1;
                }
                iVar11 = iVar11 + 1;
              } while (iVar11 != 0x20);
              bVar27 = (bool)(bVar27 | bVar18);
            }
          }
LAB_0041d189:
          _knvlinkPrintTopologySummary(param_1,param_2);
          knvlinkUpdateCurrentConfig_IMPL(param_1,param_2);
          if (bVar27) {
            uVar23 = 0;
            do {
              if (((*(long *)(param_2 + 0x14c8 + uVar23 * 8) != 0) &&
                  (lVar17 = gpumgrGetGpu(uVar23 & 0xffffffff), lVar17 != 0)) &&
                 (lVar24 = *(long *)(lVar17 + 0x1ce8), lVar24 != 0)) {
                nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x9d8,
                             "_knvlinkUpdatePeerConfigs",1,
                             "NVRM: GPU%u requesting GPU%u NVLINK config update\n",
                             *(undefined4 *)(param_1 + 0x7a4),*(undefined4 *)(lVar17 + 0x7a4));
                _knvlinkPrintTopologySummary(lVar17,lVar24);
                knvlinkUpdateCurrentConfig_IMPL(lVar17,lVar24);
              }
              uVar23 = uVar23 + 1;
            } while (uVar23 != 0x20);
          }
        }
        if (iVar19 == 0) {
          return 0;
        }
LAB_0041d246:
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x115,
                     "knvlinkCoreGetRemoteDeviceInfo_IMPL",1,
                     "NVRM: Failed to activate the discovered connections on GPU%d\n",
                     *(undefined4 *)(param_1 + 0x7a4));
        return iVar19;
      }
      goto LAB_0041c9b7;
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x108,
                 "knvlinkCoreGetRemoteDeviceInfo_IMPL",1,
                 "NVRM: L2 supported. Skip topology discovery on GPU%d in RTD3/FGC6 exit\n",
                 *(undefined4 *)(param_1 + 0x7a4));
    uVar23 = *(ulong *)(param_2 + 0x14b8);
  }
  local_80 = 0;
  iVar19 = 0;
  if (uVar23 == 0) {
    return 0;
  }
LAB_0041c9b7:
  bVar27 = false;
  puVar26 = (undefined8 *)(param_2 + 0x3c8);
  uVar22 = 0;
  uVar25 = uVar23;
  do {
    uVar21 = (uint)uVar22;
    for (; (uVar25 & 1) != 0; uVar25 = uVar25 >> 1) {
      uVar21 = (uint)uVar22;
      if (*(char *)(puVar26 + 7) != '\0') {
        bVar18 = (byte)uVar22;
        uVar20 = 1L << (bVar18 & 0x3f);
        *(ulong *)(param_2 + 0x14b8) = *(ulong *)(param_2 + 0x14b8) & ~uVar20;
        if (puVar26[5] != 2) {
          if (puVar26[5] == 3) {
            iVar19 = (**(code **)(param_2 + 0x1b8))(param_1);
            local_80 = local_80 | uVar20;
LAB_0041ca57:
            if (iVar19 == 0) goto joined_r0x0041d043;
          }
          else {
            *(uint *)(param_2 + 0x14c0) = *(uint *)(param_2 + 0x14c0) | 1 << (bVar18 & 0x1f);
            portMemSet(&local_84,0,4);
            local_84 = *(undefined4 *)(param_2 + 0x14c0);
            iVar19 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a94,&local_84,4);
            if (iVar19 == 0) {
              iVar19 = nvlink_lib_set_link_master(*puVar26);
              if (iVar19 != 0) {
                nvAssertFailedNoLog("NVL_SUCCESS == nvlink_lib_set_link_master( pKernelNvlink->nvlinkLinks[linkId].core_link)"
                                    ,"src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x780);
              }
              iVar19 = knvlinkTrainSysmemLinksToActive_IMPL(param_1,param_2);
              if (iVar19 != 0) {
                nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x787,
                             "_knvlinkActivateDiscoveredSysmemConn",4,
                             "NVRM: FAILED TO TRAIN CPU/SYSMEM LINKS TO ACTIVE on GPU%d!!!\n",
                             *(undefined4 *)(param_1 + 0x7a4));
                nvAssertFailedNoLog(&DAT_00d70bfe,
                                    "src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x78b);
              }
              portMemSet(&local_78,0,8);
              local_78 = 0x100;
              iVar19 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a42,&local_78,8);
              goto LAB_0041ca57;
            }
            nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x77b,
                         "_knvlinkActivateDiscoveredSysmemConn",4,
                         "NVRM: Failed to setup HSHUB NVLink sysmem links state\n");
          }
LAB_0041d209:
          nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x66d,
                       "_knvlinkActivateDiscoveredConns",4,
                       "NVRM: Failed to activate link%d on GPU%d!!!\n",uVar22,
                       *(undefined4 *)(param_1 + 0x7a4));
          goto LAB_0041d246;
        }
        uVar16 = 0;
        lVar24 = *(long *)(param_1 + 0x1ce8);
        lVar17 = lVar24 + uVar22 * 0x78;
        do {
          lVar14 = gpumgrGetGpu(uVar16 & 0xffffffff);
          if ((((lVar14 != 0) &&
               ((*(char *)(lVar14 + 0x4918) != '\0' || (*(char *)(lVar14 + 0x4916) != '\0')))) &&
              (*(int *)(lVar17 + 0x3d0) == (int)((ulong)*(undefined8 *)(lVar14 + 0x878) >> 0x20)))
             && (((uVar6 = (ushort)*(undefined8 *)(lVar14 + 0x878),
                  *(ushort *)(lVar17 + 0x3d4) == uVar6 >> 8 &&
                  (*(ushort *)(lVar17 + 0x3d6) == (uVar6 & 0xff))) &&
                 (*(short *)(lVar17 + 0x3d8) == 0)))) {
            lVar4 = *(long *)(lVar14 + 0x1ce8);
            iVar19 = knvlinkSetLinkMaskToPeer_IMPL
                               (param_1,lVar24,lVar14,
                                uVar20 | *(ulong *)(lVar24 + 0x14c8 + uVar16 * 8));
            if ((iVar19 != 0) ||
               (iVar19 = (**(code **)(lVar24 + 0x1b8))(param_1,lVar24,1 << (bVar18 & 0x1f)),
               iVar19 != 0)) goto LAB_0041d209;
            if (lVar4 != 0) {
              uVar1 = *(uint *)(lVar17 + 0x3f8);
              uVar20 = (ulong)uVar1;
              lVar15 = uVar20 * 0x78 + lVar4;
              cVar9 = *(char *)(lVar15 + 0x400);
              *(undefined1 *)(lVar15 + 0x400) = 1;
              *(undefined4 *)(lVar15 + 0x3d0) = *(undefined4 *)(param_1 + 0x87c);
              *(ushort *)(lVar15 + 0x3d4) = (ushort)*(byte *)(param_1 + 0x879);
              *(ushort *)(lVar15 + 0x3d6) = (ushort)*(byte *)(param_1 + 0x878);
              *(undefined2 *)(lVar15 + 0x3d8) = 0;
              uVar13 = *(undefined4 *)(param_1 + 0x7f4);
              *(undefined8 *)(lVar15 + 0x3f0) = 2;
              *(undefined4 *)(lVar15 + 0x3dc) = uVar13;
              uVar5 = *(undefined8 *)(*(long *)(lVar17 + 0x3c8) + 0x70);
              *(uint *)(lVar15 + 0x3f8) = uVar21;
              *(undefined8 *)(lVar15 + 0x408) = uVar5;
              *(undefined4 *)(lVar17 + 0x3fc) = *(undefined4 *)(lVar15 + 0x428);
              *(undefined4 *)(lVar15 + 0x3fc) = *(undefined4 *)(lVar17 + 0x428);
              if ((cVar9 == '\0') &&
                 (iVar19 = knvlinkUpdateLinkConnectionStatus_IMPL(lVar14,lVar4,uVar20), iVar19 != 0)
                 ) goto LAB_0041d209;
              uVar16 = 1L << ((byte)uVar1 & 0x3f);
              *(ulong *)(lVar4 + 0x14b8) = *(ulong *)(lVar4 + 0x14b8) & ~uVar16;
              iVar19 = knvlinkSetLinkMaskToPeer_IMPL
                                 (lVar14,lVar4,param_1,
                                  uVar16 | *(ulong *)(lVar4 + 0x14c8 +
                                                     (ulong)*(uint *)(param_1 + 0x7a4) * 8));
              if ((iVar19 != 0) ||
                 (iVar19 = (**(code **)(lVar4 + 0x1b8))(lVar14,lVar4,1 << ((byte)uVar1 & 0x1f)),
                 iVar19 != 0)) goto LAB_0041d209;
              portMemCopy(lVar4 + 0x3e0 + uVar20 * 0x78,0x10,param_1 + 0x7c5,0x10);
              uVar2 = *(uint *)(param_1 + 0x7a4);
              uVar3 = *(uint *)(lVar14 + 0x7a4);
              if ((uVar2 < uVar3) || ((uVar2 == uVar3 && (uVar21 < uVar1)))) {
                iVar11 = nvlink_lib_set_link_master(*(undefined8 *)(lVar24 + 0x3c8 + uVar22 * 0x78))
                ;
                if (iVar11 != 0) {
                  nvAssertFailedNoLog("NVL_SUCCESS == nvlink_lib_set_link_master( pKernelNvlink0->nvlinkLinks[linkId].core_link)"
                                      ,"src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x726);
                }
              }
              else if (((uVar3 < uVar2) || (uVar1 < uVar21)) &&
                      (iVar11 = nvlink_lib_set_link_master
                                          (*(undefined8 *)(lVar4 + 0x3c8 + uVar20 * 0x78)),
                      iVar11 != 0)) {
                nvAssertFailedNoLog("NVL_SUCCESS == nvlink_lib_set_link_master( pKernelNvlink1->nvlinkLinks[remoteLinkId].core_link)"
                                    ,"src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x72d);
              }
              bVar27 = true;
              goto joined_r0x0041d043;
            }
          }
          uVar16 = uVar16 + 1;
        } while (uVar16 != 0x20);
        bVar27 = true;
        iVar19 = 0;
      }
joined_r0x0041d043:
      if (uVar25 >> 1 == 0) {
        uVar22 = *(ulong *)(param_2 + 0x14b8);
        goto LAB_0041d062;
      }
      uVar21 = uVar21 + 1;
      uVar22 = (ulong)uVar21;
      puVar26 = puVar26 + 0xf;
    }
    uVar22 = (ulong)(uVar21 + 1);
    uVar25 = uVar25 >> 1;
    puVar26 = puVar26 + 0xf;
  } while( true );
}


// ===== 0041d6a0 knvlinkCheckTrainingIsComplete_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int knvlinkCheckTrainingIsComplete_IMPL(long param_1,long param_2,long param_3)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined1 local_180 [8];
  uint local_178 [2];
  undefined8 local_170;
  undefined4 local_168;
  undefined4 local_164;
  undefined8 local_160;
  undefined8 local_158 [37];
  
  lVar5 = g_pSys;
  lVar1 = *(long *)(param_2 + 0x1ce8);
  if (lVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x199,
                 "knvlinkCheckTrainingIsComplete_IMPL",4,
                 "NVRM: Input mask contains a GPU on which NVLink is disabled.\n");
    return 0x1f;
  }
  uVar3 = *(uint *)(param_3 + 0x314);
  memset(local_158,0,0x120);
  cVar2 = (**(code **)(param_3 + 0x218))(param_1,param_3);
  if (cVar2 == '\0') {
    if ((*(char *)(param_1 + 0x4911) == '\0') || (*(char *)(param_3 + 0x15fc) != '\0')) {
      if (*(char *)(param_3 + 0x15fa) == '\0') {
        cVar2 = knvlinkIsForcedConfig_IMPL(param_1,param_3);
        if (cVar2 == '\0') {
          if (*(char *)(lVar5 + 0x6b) == '\0') {
            if ((*(char *)(param_3 + 0x15ff) != '\0') || (*(char *)(lVar1 + 0x15ff) != '\0')) {
              if (uVar3 < 7) {
                nvAssertFailedNoLog("version >= NVLINK_VERSION_40",
                                    "src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x1cf);
              }
              uVar7 = 0;
              bitVectorCopy_IMPL(local_178,0x40,param_3 + 0x14b0,0x40);
              uVar3 = bitVectorCountTrailingZeros_IMPL(local_178,0x40);
              while( true ) {
                cVar2 = bitVectorTestAllCleared_IMPL(local_178,0x40);
                if (cVar2 != '\0') break;
                local_158[uVar7] = *(undefined8 *)(param_3 + 0x3c8 + (ulong)uVar3 * 0x78);
                uVar7 = uVar7 + 1;
                bitVectorClr_IMPL(local_178,0x40,(ulong)uVar3);
                uVar3 = bitVectorCountTrailingZeros_IMPL(local_178,0x40);
              }
              iVar4 = nvlink_lib_check_training_complete(local_158,uVar7 & 0xffffffff);
              if (iVar4 != 0) {
                nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x1df,
                             "knvlinkCheckTrainingIsComplete_IMPL",1,
                             "NVRM: Links aren\'t fully trained yet!\n");
                (**(code **)(param_3 + 0x238))(param_1,param_3,0);
                return 0xffff;
              }
              bitVectorCopy_IMPL(local_180,0x40,param_3 + 0x14b0,0x40);
              uVar3 = bitVectorCountTrailingZeros_IMPL(local_180,0x40);
              while( true ) {
                cVar2 = bitVectorTestAllCleared_IMPL(local_180,0x40);
                if (cVar2 != '\0') break;
                portMemSet(local_178,0,0x20);
                local_178[0] = uVar3;
                iVar4 = knvlinkExecGspRmRpc_IMPL(param_1,param_3,0x20800a25,local_178,0x20);
                if (iVar4 != 0) {
                  uVar6 = 500;
                  goto LAB_0041dbee;
                }
                lVar5 = (ulong)uVar3 * 0x78 + param_3;
                *(undefined8 *)(*(long *)(lVar5 + 0x3c8) + 0x78) = local_170;
                *(undefined4 *)(*(long *)(lVar5 + 0x3c8) + 0x84) = local_168;
                *(undefined4 *)(*(long *)(lVar5 + 0x3c8) + 0x80) = local_164;
                *(undefined8 *)(*(long *)(lVar5 + 0x3c8) + 0x70) = local_160;
                bitVectorClr_IMPL(local_180,0x40,(ulong)uVar3);
                uVar3 = bitVectorCountTrailingZeros_IMPL(local_180,0x40);
              }
              if (param_3 != lVar1) {
                uVar7 = 0;
                bitVectorCopy_IMPL(local_178,0x40,lVar1 + 0x14b0,0x40);
                uVar3 = bitVectorCountTrailingZeros_IMPL(local_178,0x40);
                while( true ) {
                  cVar2 = bitVectorTestAllCleared_IMPL(local_178,0x40);
                  if (cVar2 != '\0') break;
                  local_158[uVar7] = *(undefined8 *)(lVar1 + 0x3c8 + (ulong)uVar3 * 0x78);
                  uVar7 = uVar7 + 1;
                  bitVectorClr_IMPL(local_178,0x40,(ulong)uVar3);
                  uVar3 = bitVectorCountTrailingZeros_IMPL(local_178,0x40);
                }
                iVar4 = nvlink_lib_check_training_complete(local_158,uVar7 & 0xffffffff);
                if (iVar4 != 0) {
                  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x216,
                               "knvlinkCheckTrainingIsComplete_IMPL",1,
                               "NVRM: Links aren\'t fully trained yet!\n");
                  (**(code **)(lVar1 + 0x238))(param_2,lVar1,0);
                  return 0xffff;
                }
                bitVectorCopy_IMPL(local_180,0x40,lVar1 + 0x14b0,0x40);
                uVar3 = bitVectorCountTrailingZeros_IMPL(local_180,0x40);
                while( true ) {
                  cVar2 = bitVectorTestAllCleared_IMPL(local_180,0x40);
                  if (cVar2 != '\0') break;
                  portMemSet(local_178,0,0x20);
                  local_178[0] = uVar3;
                  iVar4 = knvlinkExecGspRmRpc_IMPL(param_2,lVar1,0x20800a25,local_178,0x20);
                  if (iVar4 != 0) {
                    uVar6 = 0x22b;
LAB_0041dbee:
                    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",uVar6,
                                 "knvlinkCheckTrainingIsComplete_IMPL",4,
                                 "NVRM: Error updating Local/Remote Sid Info!\n");
                    return iVar4;
                  }
                  lVar5 = (ulong)uVar3 * 0x78 + lVar1;
                  *(undefined8 *)(*(long *)(lVar5 + 0x3c8) + 0x78) = local_170;
                  *(undefined4 *)(*(long *)(lVar5 + 0x3c8) + 0x84) = local_168;
                  *(undefined4 *)(*(long *)(lVar5 + 0x3c8) + 0x80) = local_164;
                  *(undefined8 *)(*(long *)(lVar5 + 0x3c8) + 0x70) = local_160;
                  bitVectorClr_IMPL(local_180,0x40,(ulong)uVar3);
                  uVar3 = bitVectorCountTrailingZeros_IMPL(local_180,0x40);
                }
              }
            }
          }
          else {
            nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x1c3,
                         "knvlinkCheckTrainingIsComplete_IMPL",1,
                         "NVRM: Fabric is externally managed, skip link training\n");
          }
        }
        else {
          nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x1bc,
                       "knvlinkCheckTrainingIsComplete_IMPL",1,
                       "NVRM: Skipping link due to forced configuration\n");
        }
      }
      else {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x1b3,
                     "knvlinkCheckTrainingIsComplete_IMPL",1,
                     "NVRM: Skipping link training due to regkey on GPU%d\n",
                     *(undefined4 *)(param_1 + 0x7a4));
      }
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x1a4,
                 "knvlinkCheckTrainingIsComplete_IMPL",1,
                 "NVRM: Skip link training on GPU%d in RTD3/FGC6 exit. Links will train to ACTIVE in L2 exit path\n"
                 ,*(undefined4 *)(param_1 + 0x7a4));
  }
  return 0;
}


// ===== 0041dd40 knvlinkTrainP2pLinksToActive_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int knvlinkTrainP2pLinksToActive_IMPL(long param_1,long param_2,long param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  ulong uVar9;
  ulong local_1e8;
  ulong local_1d8;
  undefined1 local_1c0 [8];
  undefined1 local_1b8 [16];
  undefined1 local_1a8;
  char acStack_1a7 [79];
  undefined8 local_158 [37];
  
  lVar6 = g_pSys;
  lVar7 = *(long *)(param_2 + 0x1ce8);
  uVar5 = *(uint *)(param_3 + 0x314);
  memset(local_158,0,0x120);
  cVar1 = (**(code **)(param_3 + 0x218))(param_1,param_3);
  if (cVar1 == '\0') {
    if ((*(char *)(param_1 + 0x4911) == '\0') || (*(char *)(param_3 + 0x15fc) != '\0')) {
      if (*(char *)(param_3 + 0x15fa) == '\0') {
        cVar1 = knvlinkIsForcedConfig_IMPL(param_1,param_3);
        if (cVar1 == '\0') {
          if (*(char *)(lVar6 + 0x6b) == '\0') {
            cVar1 = rmcfg_IsAMPERE_CLASSIC_GPUSorBetter(param_1);
            if (cVar1 != '\0') {
              bitVectorCopy_IMPL(local_1b8,0x40,lVar7 + 0x388,0x40);
              uVar2 = bitVectorCountTrailingZeros_IMPL(local_1b8,0x40);
              local_1e8 = 0;
              local_1d8 = 0;
              while( true ) {
                cVar1 = bitVectorTestAllCleared_IMPL(local_1b8,0x40);
                if (cVar1 != '\0') break;
                lVar6 = (ulong)uVar2 * 0x78 + param_3;
                if ((((*(char *)(lVar6 + 0x400) != '\0') &&
                     (uVar8 = *(undefined8 *)(param_2 + 0x878),
                     *(int *)(lVar6 + 0x3d0) == (int)((ulong)uVar8 >> 0x20))) &&
                    (*(ushort *)(lVar6 + 0x3d4) == ((ushort)((ulong)uVar8 >> 8) & 0xff))) &&
                   ((*(ushort *)(lVar6 + 0x3d6) == ((ushort)uVar8 & 0xff) &&
                    (*(short *)(lVar6 + 0x3d8) == 0)))) {
                  local_1d8 = local_1d8 | (uint)(1 << ((byte)uVar2 & 0x1f));
                  local_1e8 = local_1e8 | (uint)(1 << ((byte)*(undefined4 *)(lVar6 + 0x3f8) & 0x1f))
                  ;
                }
                bitVectorClr_IMPL(local_1b8,0x40,(ulong)uVar2);
                uVar2 = bitVectorCountTrailingZeros_IMPL(local_1b8,0x40);
              }
              if (((*(ulong *)(param_3 + 0x3b8) & local_1d8) == local_1d8) &&
                 ((*(ulong *)(lVar7 + 0x3b8) & local_1e8) == local_1e8)) {
                nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x2a4,
                             "knvlinkTrainP2pLinksToActive_IMPL",1,
                             "NVRM: P2P links are all trained already, return\n");
                return 0;
              }
            }
            portMemSet(local_1b8,0,0x58);
            lVar7 = param_3 + 0x388;
            iVar3 = convertBitVectorToLinkMasks(lVar7,0,0,local_1b8);
            uVar8 = 0x2ae;
            if (iVar3 == 0) {
              local_1a8 = 1;
              if (*(char *)(param_1 + 0x909) != '\0') {
                threadStateResetTimeout(param_1);
              }
              iVar3 = knvlinkExecGspRmRpc_IMPL(param_1,param_3,0x20800a90,local_1b8,0x58);
              if (iVar3 != 0) {
                nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x2bf,
                             "knvlinkTrainP2pLinksToActive_IMPL",4,
                             "NVRM: Failed to get the link train status for links\n");
                return iVar3;
              }
              bitVectorCopy_IMPL(local_1c0,0x40,lVar7,0x40);
              uVar2 = bitVectorCountTrailingZeros_IMPL(local_1c0,0x40);
              while( true ) {
                uVar9 = (ulong)uVar2;
                cVar1 = bitVectorTestAllCleared_IMPL(local_1c0,0x40);
                if (cVar1 != '\0') {
                  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x2da,
                               "knvlinkTrainP2pLinksToActive_IMPL",1,
                               "NVRM: Enabled links are all trained already, return\n");
                  return 0;
                }
                lVar6 = uVar9 * 0x78 + param_3;
                if (((*(char *)(lVar6 + 0x400) != '\0') &&
                    (uVar8 = *(undefined8 *)(param_2 + 0x878),
                    *(int *)(lVar6 + 0x3d0) == (int)((ulong)uVar8 >> 0x20))) &&
                   ((*(ushort *)(lVar6 + 0x3d4) == ((ushort)((ulong)uVar8 >> 8) & 0xff) &&
                    (((*(ushort *)(lVar6 + 0x3d6) == ((ushort)uVar8 & 0xff) &&
                      (*(short *)(lVar6 + 0x3d8) == 0)) && (acStack_1a7[uVar9] == '\0')))))) break;
                bitVectorClr_IMPL(local_1c0,0x40,uVar9);
                uVar2 = bitVectorCountTrailingZeros_IMPL(local_1c0,0x40);
              }
              bitVectorCopy_IMPL(local_1c0,0x40,lVar7,0x40);
              uVar4 = bitVectorCountTrailingZeros_IMPL(local_1c0,0x40);
              uVar2 = 0;
              while( true ) {
                cVar1 = bitVectorTestAllCleared_IMPL(local_1c0,0x40);
                if (cVar1 != '\0') break;
                lVar6 = param_3 + (ulong)uVar4 * 0x78;
                if ((((*(char *)(lVar6 + 0x400) != '\0') &&
                     (uVar8 = *(undefined8 *)(param_2 + 0x878),
                     *(int *)(lVar6 + 0x3d0) == (int)((ulong)uVar8 >> 0x20))) &&
                    (*(ushort *)(lVar6 + 0x3d4) == ((ushort)((ulong)uVar8 >> 8) & 0xff))) &&
                   ((*(ushort *)(lVar6 + 0x3d6) == ((ushort)uVar8 & 0xff) &&
                    (*(short *)(lVar6 + 0x3d8) == 0)))) {
                  if (uVar5 < 4) {
                    nvlink_lib_train_links_from_swcfg_to_active
                              (param_3 + 0x3c8 + (ulong)uVar4 * 0x78,1,1);
                  }
                  else {
                    local_158[uVar2] = *(undefined8 *)(lVar6 + 0x3c8);
                    uVar2 = uVar2 + 1;
                  }
                }
                bitVectorClr_IMPL(local_1c0,0x40,uVar4);
                uVar4 = bitVectorCountTrailingZeros_IMPL(local_1c0,0x40);
              }
              if (uVar2 != 0) {
                if (uVar5 < 4) {
                  nvAssertFailedNoLog("version >= NVLINK_VERSION_22",
                                      "src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x2fe);
                }
                nvlink_lib_train_links_from_swcfg_to_active(local_158,uVar2,0);
              }
              portMemSet(local_1b8,0,0x58);
              iVar3 = convertBitVectorToLinkMasks(lVar7,0,0,local_1b8);
              if (iVar3 == 0) {
                local_1a8 = 1;
                if (*(char *)(param_1 + 0x909) != '\0') {
                  threadStateResetTimeout(param_1);
                }
                iVar3 = knvlinkExecGspRmRpc_IMPL(param_1,param_3,0x20800a90,local_1b8,0x58);
                if (iVar3 != 0) {
                  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x317,
                               "knvlinkTrainP2pLinksToActive_IMPL",4,
                               "NVRM: Failed to get the link train status for links\n");
                  return iVar3;
                }
                bitVectorCopy_IMPL(local_1c0,0x40,lVar7,0x40);
                uVar5 = bitVectorCountTrailingZeros_IMPL(local_1c0,0x40);
                iVar3 = 0;
                while( true ) {
                  uVar9 = (ulong)uVar5;
                  cVar1 = bitVectorTestAllCleared_IMPL(local_1c0,0x40);
                  if (cVar1 != '\0') break;
                  lVar7 = uVar9 * 0x78 + param_3;
                  if (*(char *)(lVar7 + 0x400) != '\0') {
                    uVar8 = *(undefined8 *)(param_2 + 0x878);
                    if (((*(int *)(lVar7 + 0x3d0) == (int)((ulong)uVar8 >> 0x20)) &&
                        (*(ushort *)(lVar7 + 0x3d4) == ((ushort)((ulong)uVar8 >> 8) & 0xff))) &&
                       ((*(ushort *)(lVar7 + 0x3d6) == ((ushort)uVar8 & 0xff) &&
                        ((*(short *)(lVar7 + 0x3d8) == 0 && (acStack_1a7[uVar9] == '\0')))))) {
                      nvErrorLog_va(param_1,0x4a,
                                    "NVLink: Failed to train link %d to remote PCI:%04x:%02x:%02x",
                                    uVar9,*(int *)(lVar7 + 0x3d0),*(ushort *)(lVar7 + 0x3d4),
                                    *(ushort *)(lVar7 + 0x3d6));
                      gpuNotifySubDeviceEvent_IMPL(param_1,0x7b,0,0,0,0);
                      iVar3 = 0x40;
                    }
                  }
                  bitVectorClr_IMPL(local_1c0,0x40,uVar9);
                  uVar5 = bitVectorCountTrailingZeros_IMPL(local_1c0,0x40);
                }
                return iVar3;
              }
              uVar8 = 0x306;
            }
            nvCheckOkFailedNoLog
                      (4,iVar3,
                       "convertBitVectorToLinkMasks(&pKernelNvlink0->enabledLinks, NULL, 0, &linkTrainedParams.linkMask)"
                       ,"src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",uVar8);
            return iVar3;
          }
          nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x286,
                       "knvlinkTrainP2pLinksToActive_IMPL",1,
                       "NVRM: Fabric is externally managed, skip link training\n");
        }
        else {
          nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x27e,
                       "knvlinkTrainP2pLinksToActive_IMPL",1,
                       "NVRM: Skipping link due to forced configuration\n");
        }
      }
      else {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x274,
                     "knvlinkTrainP2pLinksToActive_IMPL",1,
                     "NVRM: Skipping link training due to regkey on GPU%d\n",
                     *(undefined4 *)(param_1 + 0x7a4));
      }
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x264,
                 "knvlinkTrainP2pLinksToActive_IMPL",1,
                 "NVRM: Skip link training on GPU%d in RTD3/FGC6 exit. Links will train to ACTIVE in L2 exit path\n"
                 ,*(undefined4 *)(param_1 + 0x7a4));
  }
  return 0;
}


