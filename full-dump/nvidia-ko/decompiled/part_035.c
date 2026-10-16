// ===== 003a4350 memmgrGetPteKindGenericMemoryCompressible_TU102 =====

undefined8 memmgrGetPteKindGenericMemoryCompressible_TU102(void)

{
  return 8;
}


// ===== 003a4360 memmgrIsKind_TU102 =====

bool memmgrIsKind_TU102(undefined8 param_1,uint param_2,ulong param_3)

{
  uint uVar1;
  
  uVar1 = (uint)param_3;
  if (8 < param_2) {
    if (param_2 == 10) {
      return uVar1 != 8;
    }
    if (param_2 == 0xb) {
      if (uVar1 < 0x10) {
        return (0xffffffffffff7cbeU >> (param_3 & 0x3f) & 1) != 0;
      }
    }
    else {
      if (param_2 != 9) goto LAB_003a43f0;
      if ((uVar1 == 7) || (uVar1 == 0)) {
        return uVar1 != 7;
      }
      if (5 < uVar1 - 1) {
        return uVar1 - 8 < 8;
      }
    }
    return true;
  }
  if (5 < param_2) {
    return false;
  }
  if (param_2 != 1) {
    if (param_2 < 2) {
      return uVar1 - 1 < 5 || uVar1 - 10 < 5;
    }
    if (param_2 < 4) {
      return false;
    }
    if (param_2 != 5) {
LAB_003a43f0:
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/turing/mem_mgr_tu102_base.c",0x45,
                   "memmgrIsKind_TU102",4,"NVRM: Bad op (%08x) passed in\n",param_2);
      return false;
    }
  }
  return uVar1 - 8 < 7;
}


// ===== 003a4460 memmgrIsSurfaceBlockLinear_TU102 =====

undefined4 memmgrIsSurfaceBlockLinear_TU102(undefined8 param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x188) & 0x30000;
  return CONCAT31((int3)(uVar1 >> 8),uVar1 == 0x20000);
}


// ===== 003a4480 memmgrScrubMapDoorbellRegion_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrScrubMapDoorbellRegion_GV100(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = rmapiGetInterface(4);
  iVar1 = (**(code **)(lVar2 + 8))(lVar2,param_3[0x2b],param_3[3],param_3[0x55],0xc361,0,0);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(lVar2 + 0x70))
                      (lVar2,param_3[0x2b],*param_3,param_3[0x55],0,0x10000,param_3 + 0x56,2);
    if (iVar1 != 0) {
      (**(code **)(lVar2 + 0x18))(lVar2,param_3[0x2b],param_3[0x55]);
      return iVar1;
    }
    *(undefined1 *)(param_3 + 0x5a) = 1;
    *(long *)(param_3 + 0x58) = *(long *)(param_3 + 0x56) + 0x90;
    iVar1 = 0;
  }
  return iVar1;
}


// ===== 003a4560 memmgrGetMaxContextSize_GV100 =====

long memmgrGetMaxContextSize_GV100(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = memmgrGetMaxContextSize_GP100();
  cVar1 = ctxBufPoolIsSupported(param_1);
  lVar3 = lVar2 + 0x7800000;
  if (cVar1 != '\0') {
    lVar3 = lVar2;
  }
  return lVar3;
}


// ===== 003a45a0 _ceutilsSubmitPushBuffer =====

int _ceutilsSubmitPushBuffer(long param_1,undefined1 param_2,char param_3,char *param_4)

{
  long lVar1;
  long lVar2;
  bool bVar3;
  int iVar4;
  undefined8 *puVar5;
  long lVar6;
  int iVar7;
  undefined4 local_3c [3];
  
  lVar1 = *(long *)(param_1 + 0x50);
  local_3c[0] = 0;
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pChannel != NULL","src/kernel/gpu/mem_mgr/ce_utils.c",0x1df);
    return 0x1f;
  }
  lVar2 = *(long *)(*(long *)(lVar1 + 0x178) + 0x1b78);
  iVar7 = (-(uint)(*(char *)(lVar1 + 0x194) == '\0') & 0xffffffe0) + 0x26;
  nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x1eb,"_ceutilsSubmitPushBuffer",1,
               "NVRM: Actual size of copying to be pushed: %x\n",*(undefined4 *)(param_4 + 0x18));
  iVar4 = channelWaitForFreeEntry(lVar1,local_3c);
  if (iVar4 != 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x1f0,"_ceutilsSubmitPushBuffer",4,
                 "NVRM: Cannot get putIndex.\n");
    return iVar4;
  }
  if ((param_3 == '\0') || (*(long *)(param_4 + 0x40) == 0)) {
    lVar6 = *(long *)(lVar1 + 0xe8);
joined_r0x003a47ab:
    bVar3 = false;
    if (lVar6 == 0) {
      lVar6 = memmgrMemDescBeginTransfer_IMPL(lVar2,*(undefined8 *)(lVar1 + 0xd8),iVar7);
      *(long *)(lVar1 + 0xe8) = lVar6;
      if (lVar6 == 0) {
        nvAssertFailedNoLog("pChannel->pbCpuVA != NULL","src/kernel/gpu/mem_mgr/ce_utils.c",0x1ff);
        return 0xffff;
      }
      bVar3 = true;
    }
    lVar6 = *(long *)(*(long *)(lVar1 + 0x178) + 0x1b78);
    if (((((*(int *)(lVar1 + 0x150) == 1) && (*(char *)(lVar6 + 0x481) != '\0')) &&
         (*param_4 == '\0')) && (*(int *)(param_4 + 0x1c) == 0)) &&
       (((*(int *)(param_4 + 0x30) == 2 || (*(char *)(lVar6 + 0x482) != '\0')) &&
        (((*(ushort *)(param_4 + 8) & 0xfff) == 0 && ((*(ushort *)(param_4 + 0x18) & 0xfff) == 0))))
       )) {
      iVar4 = channelFillPbFastScrub(lVar1,local_3c[0],param_2,param_3,param_4);
    }
    else {
      if ((*(char *)(lVar2 + 0x486) != '\0') && (*(char *)(lVar1 + 0x5e) == '\0')) {
        nvAssertFailedNoLog("pChannel->bUseVasForCeCopy","src/kernel/gpu/mem_mgr/ce_utils.c",0x20a);
        return 0x56;
      }
      iVar4 = channelFillCePb(lVar1,local_3c[0],param_2,param_3,param_4);
    }
    if (bVar3) {
      memmgrMemDescEndTransfer_IMPL(lVar2,*(undefined8 *)(lVar1 + 0xd8),iVar7);
      *(undefined8 *)(lVar1 + 0xe8) = 0;
    }
    if (iVar4 == 0) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x218,"_ceutilsSubmitPushBuffer",4,
                   "NVRM: Cannot push methods to channel.\n");
      return 0x4f;
    }
    iVar4 = channelFillGpFifo(lVar1,local_3c[0],iVar4);
    if (iVar4 == 0) {
      *(undefined4 *)(lVar1 + 0x148) = local_3c[0];
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x223,"_ceutilsSubmitPushBuffer",4,
                 "NVRM: Channel operation failures during memcopy\n");
  }
  else {
    if (*(char *)(param_1 + 0x90) == '\0') {
      nvAssertFailedNoLog("pCeUtils->bCompletionCallbackEnabled","src/kernel/gpu/mem_mgr/ce_utils.c"
                          ,0x85);
      iVar4 = 0x1f;
    }
    else {
      puVar5 = (undefined8 *)portMemAllocNonPaged(0x28);
      if (puVar5 != (undefined8 *)0x0) {
        portSyncSpinlockAcquire(*(undefined8 *)(param_1 + 0x98));
        *puVar5 = *(undefined8 *)(param_4 + 0x40);
        puVar5[1] = *(undefined8 *)(param_4 + 0x48);
        puVar5[2] = (ulong)*(uint *)(param_4 + 0x20);
        listAppendExisting_IMPL(param_1 + 0xa0,puVar5);
        portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x98));
        nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x91,"_ceutilsInsertCallback",1,
                     "NVRM: inserted completion callback payload=%llu\n",puVar5[2]);
        lVar6 = *(long *)(lVar1 + 0xe8);
        goto joined_r0x003a47ab;
      }
      nvAssertFailedNoLog("pCallbackEntry != NULL","src/kernel/gpu/mem_mgr/ce_utils.c",0x88);
      iVar4 = 0x51;
    }
    nvAssertOkFailedNoLog
              (iVar4,"_ceutilsInsertCallback(pCeUtils, pChannelPbInfo)",
               "src/kernel/gpu/mem_mgr/ce_utils.c",0x1f6);
  }
  return iVar4;
}


// ===== 003a4a40 ceutilsGetFirstAsyncCe_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int ceutilsGetFirstAsyncCe_IMPL
              (undefined8 param_1,long param_2,undefined8 param_3,undefined4 param_4,
              undefined4 *param_5,char param_6)

{
  uint uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  ulong uVar5;
  undefined8 local_40 [2];
  
  if ((((param_2 == 0) || (*(long *)(param_2 + 0x1bc0) == 0)) ||
      (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_2), param_6 != '\0')) || (cVar3 == '\0'))
  {
    iVar4 = gpuUpdateEngineTable_IMPL(param_2);
    if (iVar4 == 0) {
      uVar1 = *(uint *)(param_2 + 0x8fc);
      uVar5 = 0;
      if (uVar1 != 0) {
        do {
          if (((uVar5 < 0x14) && (lVar2 = *(long *)(param_2 + 0x1c30 + uVar5 * 8), lVar2 != 0)) &&
             ((cVar3 = (**(code **)(param_2 + 200))(param_2,*(uint *)(lVar2 + 0x2b8) | 0x793ceb00),
              cVar3 != '\0' &&
              ((cVar3 = ceIsCeGrce(param_2,*(int *)(lVar2 + 0x2b8) + 9), cVar3 == '\0' &&
               (cVar3 = gpuCheckEngineTable_IMPL(param_2,*(int *)(lVar2 + 0x2b8) + 9), cVar3 != '\0'
               )))))) {
            *param_5 = *(undefined4 *)(lVar2 + 0x2b8);
            return 0;
          }
          uVar5 = uVar5 + 1;
        } while (uVar1 != uVar5);
      }
      iVar4 = 0x1a;
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar4,"gpuUpdateEngineTable(pGpu)","src/kernel/gpu/mem_mgr/ce_utils.c",0x44);
    }
  }
  else {
    iVar4 = deviceGetByHandle_IMPL(param_3,param_4,local_40);
    if (iVar4 == 0) {
      iVar4 = kmigmgrGetGPUInstanceScrubberCe_IMPL
                        (param_2,*(undefined8 *)(param_2 + 0x1bc0),local_40[0],param_5);
      if (iVar4 != 0) {
        nvAssertOkFailedNoLog
                  (iVar4,
                   "kmigmgrGetGPUInstanceScrubberCe(pGpu, GPU_GET_KERNEL_MIG_MANAGER(pGpu), pDevice, pCeInstance)"
                   ,"src/kernel/gpu/mem_mgr/ce_utils.c",0x3f);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar4,"deviceGetByHandle(pClient, hDevice, &pDevice)",
                 "src/kernel/gpu/mem_mgr/ce_utils.c",0x3c);
    }
  }
  return iVar4;
}


// ===== 003a4c10 ceutilsConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int ceutilsConstruct_IMPL(long param_1,long param_2,undefined8 param_3,int *param_4)

{
  ulong uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  long lVar8;
  bool bVar9;
  
  uVar1 = *(ulong *)(param_4 + 2);
  *(byte *)(param_1 + 0x80) = (byte)(uVar1 >> 4) & 1;
  *(byte *)(param_1 + 0x90) = (byte)(uVar1 >> 6) & 1;
  if (param_2 == 0) {
    nvAssertFailedNoLog(&DAT_00d49479,"src/kernel/gpu/mem_mgr/ce_utils.c",0xb0);
    return 0x40;
  }
  bVar9 = false;
  if (*(long *)(param_2 + 0x1bc0) != 0) {
    cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_2);
    bVar9 = cVar3 != '\0';
  }
  lVar2 = *(long *)(param_2 + 0x1b78);
  *(long *)(param_1 + 0x58) = param_2;
  if ((uVar1 & 4) != 0) {
    return 0x56;
  }
  lVar5 = rmapiGetInterface(4);
  puVar6 = (undefined4 *)portMemAllocNonPaged(0x198);
  if (puVar6 == (undefined4 *)0x0) {
    return 0x1a;
  }
  portMemSet(puVar6,0,0x198);
  iVar4 = *(int *)(param_1 + 0x48);
  if (iVar4 == 0) {
    iVar4 = (**(code **)(lVar5 + 8))(lVar5,0,0,0,0,param_1 + 0x48,4);
    if (iVar4 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/ce_utils.c",0xcc,0x3a4cd8);
      goto LAB_003a5031;
    }
    iVar4 = *(int *)(param_1 + 0x48);
  }
  puVar6[0x2b] = iVar4;
  iVar4 = serverGetClientUnderLock(g_resServ,iVar4,puVar6 + 0x18);
  if (iVar4 == 0) {
    if (*(char *)(param_2 + 0x908) == '\0') {
      iVar4 = clientSetHandleGenerator_IMPL(*(undefined8 *)(puVar6 + 0x18),1,0xfffffffe);
      if (iVar4 == 0) {
LAB_003a4d56:
        *(undefined1 *)(puVar6 + 0x2c) = 1;
        *(undefined8 *)(puVar6 + 0x62) = param_3;
        *(long *)(puVar6 + 0x5e) = param_2;
        puVar6[0xb] = 0;
        *(byte *)((long)puVar6 + 0x5e) = (byte)(uVar1 >> 1) & 1;
        *(byte *)(puVar6 + 0x65) = (byte)(uVar1 >> 3) & 1 ^ 1;
        *(byte *)((long)puVar6 + 0x195) = (byte)(uVar1 >> 5) & 1;
        iVar4 = (**(code **)(lVar2 + 0x1b8))(param_2,lVar2,param_1 + 0x6c);
        if (iVar4 != 0) {
          nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/ce_utils.c",0xf3);
          goto LAB_003a4fc5;
        }
        cVar3 = *(char *)((long)puVar6 + 0x5e);
        if (*(uint *)(param_1 + 0x6c) < 0xc8b5) {
          puVar6[0x54] = 0;
LAB_003a4f9b:
          if (((*(char *)(lVar2 + 0x486) != '\0') && (cVar3 == '\0')) && (puVar6[0x54] != 1)) {
            iVar4 = 0x56;
            goto LAB_003a4fc5;
          }
        }
        else {
          if (cVar3 == '\0') {
            puVar6[0x54] = 1;
            nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0xf9,"ceutilsConstruct_IMPL",1,
                         "NVRM: Enabled fast scrubber in construct.\n");
            cVar3 = *(char *)((long)puVar6 + 0x5e);
            goto LAB_003a4f9b;
          }
          puVar6[0x54] = 0;
        }
        iVar4 = channelSetupIDs(puVar6,param_2,cVar3,bVar9);
        if (iVar4 == 0) {
          channelSetupChannelBufferSizes(puVar6);
          iVar4 = channelAllocSubdevice(param_2,puVar6);
          if (iVar4 == 0) {
            if (*(char *)(param_1 + 0x80) == '\0') {
              iVar4 = ceutilsGetFirstAsyncCe_IMPL
                                (param_1,param_2,*(undefined8 *)(puVar6 + 0x18),*puVar6,
                                 puVar6 + 0x60,0);
              if (iVar4 != 0) {
                nvAssertOkFailedNoLog
                          (iVar4,
                           "ceutilsGetFirstAsyncCe(pCeUtils, pGpu, pChannel->pRsClient, pChannel->deviceId, &pChannel->ceId, NV_FALSE)"
                           ,"src/kernel/gpu/mem_mgr/ce_utils.c",0x119);
                goto LAB_003a500d;
              }
            }
            else {
              puVar6[0x60] = param_4[4];
            }
            iVar4 = (**(code **)(lVar2 + 0x1a0))(param_2,lVar2,puVar6);
            if (iVar4 == 0) {
              nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x121,"ceutilsConstruct_IMPL",1,
                           "NVRM: Channel alloc successful for ceUtils\n");
              *(undefined4 **)(param_1 + 0x50) = puVar6;
              uVar7 = portMemAllocatorGetGlobalNonPaged();
              lVar8 = portSyncSpinlockCreate(uVar7);
              *(long *)(param_1 + 0x98) = lVar8;
              if (lVar8 == 0) {
                nvAssertOkFailedNoLog
                          (0x51,"pCeUtils->pCallbackLock != NULL",
                           "src/kernel/gpu/mem_mgr/ce_utils.c",0x125);
                iVar4 = 0x51;
                goto LAB_003a500d;
              }
              listInitIntrusive_IMPL(param_1 + 0xa0,0x18);
              if (*(char *)(param_1 + 0x90) != '\0') {
                *(code **)(puVar6 + 0x42) = _ceutilsSemaphoreEventCallback;
                *(long *)(puVar6 + 0x44) = param_1;
              }
              iVar4 = (**(code **)(lVar2 + 0x1a8))(param_2,lVar2,puVar6);
              if (iVar4 == 0) {
                return 0;
              }
              nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/ce_utils.c",0x131);
            }
            else {
              nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/ce_utils.c",0x11f);
            }
LAB_003a4fc5:
            (**(code **)(lVar5 + 0x18))(lVar5,puVar6[0x2b],puVar6[2]);
            if (*param_4 != 0) {
              (**(code **)(lVar5 + 0x18))(lVar5,puVar6[0x2b],puVar6[0xb]);
            }
          }
          else {
            nvAssertOkFailedNoLog
                      (iVar4,"channelAllocSubdevice(pGpu, pChannel)",
                       "src/kernel/gpu/mem_mgr/ce_utils.c",0x111);
          }
        }
        else {
          nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/ce_utils.c",0x10d);
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar4,"clientSetHandleGenerator(pChannel->pRsClient, 1U, ~0U - 1U)",
                   "src/kernel/gpu/mem_mgr/ce_utils.c",0xde);
      }
    }
    else {
      iVar4 = clientSetHandleGenerator_IMPL(*(undefined8 *)(puVar6 + 0x18),0xcaf00000,0x3f000);
      if (iVar4 == 0) goto LAB_003a4d56;
      nvAssertOkFailedNoLog
                (iVar4,
                 "clientSetHandleGenerator(pChannel->pRsClient, RS_UNIQUE_HANDLE_BASE, RS_UNIQUE_HANDLE_RANGE/2 - VGPU_RESERVED_HANDLE_RANGE)"
                 ,"src/kernel/gpu/mem_mgr/ce_utils.c",0xd6);
    }
  }
  else {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/ce_utils.c",0xd2);
  }
LAB_003a500d:
  if ((uVar1 & 1) == 0) {
    (**(code **)(lVar5 + 0x18))(lVar5,puVar6[0x2b],puVar6[0x2b]);
  }
LAB_003a5031:
  portMemFree(puVar6);
  return iVar4;
}


// ===== 003a52a0 ceutilsServiceInterrupts_IMPL =====

void ceutilsServiceInterrupts_IMPL(long param_1)

{
  long lVar1;
  char cVar2;
  
  lVar1 = *(long *)(param_1 + 0x50);
  cVar2 = rmDeviceGpuLockIsOwner(*(undefined4 *)(*(long *)(lVar1 + 0x178) + 0x7a4));
  if (cVar2 != '\0') {
    channelServiceScrubberInterrupts(lVar1);
    return;
  }
  osSchedule();
  return;
}


// ===== 003a52f0 ceutilsMemset_IMPL =====

int ceutilsMemset_IMPL(long param_1,long *param_2)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  bool bVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  char cVar11;
  ulong uVar12;
  byte local_d0;
  undefined8 local_a0 [3];
  undefined4 local_88;
  undefined4 local_84;
  uint local_80 [4];
  undefined4 local_70;
  undefined4 local_68;
  long local_60;
  long local_58;
  
  lVar1 = *(long *)(param_1 + 0x50);
  plVar2 = (long *)*param_2;
  uVar9 = 0;
  do {
    uVar6 = (int)uVar9 + 0x20;
    *(undefined8 *)((long)local_a0 + uVar9) = 0;
    *(undefined8 *)((long)local_a0 + uVar9 + 8) = 0;
    *(undefined8 *)((long)local_a0 + uVar9 + 0x10) = 0;
    *(undefined8 *)((long)local_80 + (uVar9 - 8)) = 0;
    uVar9 = (ulong)uVar6;
  } while (uVar6 < 0x60);
  *(undefined8 *)((long)local_a0 + (ulong)uVar6) = 0;
  if (*(long *)(param_1 + 0x88) == 0) {
    if (plVar2 == (long *)0x0) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x244,"ceutilsMemset_IMPL",4,
                   "NVRM: Invalid memdesc for CeUtils memset.\n");
    }
    else if (*plVar2 == *(long *)(lVar1 + 0x178)) {
      lVar10 = param_2[4];
      uVar9 = plVar2[6];
      iVar7 = memdescGetAddressSpace(plVar2);
      cVar11 = (iVar7 == 2) + '\x01';
      cVar5 = memdescGetContiguity(plVar2,cVar11);
      if ((ulong)param_2[1] < uVar9) {
        lVar3 = param_2[2];
        nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x259,"ceutilsMemset_IMPL",1,
                     "NVRM: CeUtils Args to memset - offset: %llx, size: %llx \n");
        if ((param_2[2] != 0) && ((ulong)param_2[2] <= uVar9 - param_2[1])) {
          local_a0[0]._0_1_ = 0;
          local_80[0] = *(int *)(param_1 + 0x70) + 1;
          local_d0 = (byte)lVar10 & 4;
          *(ulong *)(param_1 + 0x70) = (ulong)local_80[0];
          local_84 = (undefined4)param_2[3];
          local_70 = memdescGetAddressSpace(plVar2,lVar3);
          uVar6 = *(uint *)(plVar2 + 0x2c);
          lVar10 = param_2[1];
          local_68 = *(undefined4 *)((long)plVar2 + 0x74);
          local_60 = param_2[6];
          uVar9 = param_2[2];
          local_58 = param_2[7];
          do {
            uVar8 = memdescGetPhysAddr(plVar2,cVar11,lVar10);
            iVar7 = *(int *)(lVar1 + 0x150);
            if (cVar5 == '\0') {
              uVar8 = (ulong)uVar6 - uVar8 % (ulong)uVar6;
              uVar12 = uVar8;
              if (uVar9 <= uVar8) {
                uVar12 = uVar9;
              }
              if (uVar12 < 0xffffffff) {
                if (uVar8 <= uVar9) goto LAB_003a5603;
                uVar12 = uVar9 & 0xffffffff;
                bVar4 = 0x1000 < (uint)uVar9;
                goto LAB_003a54e1;
              }
              uVar12 = 0xffffffff;
              if (iVar7 == 1) {
                uVar12 = 0xfffff000;
              }
              uVar8 = 0xffffffff;
              if (iVar7 == 1) {
                uVar8 = 0xfffff000;
              }
            }
            else {
              uVar8 = uVar9;
              if (uVar9 < 0xffffffff) {
LAB_003a5603:
                uVar12 = uVar8 & 0xffffffff;
                bVar4 = 0x1000 < (uint)uVar8;
              }
              else {
                bVar4 = true;
                uVar12 = 0xffffffff;
              }
LAB_003a54e1:
              uVar8 = uVar12;
              if ((iVar7 == 1) && (bVar4)) {
                uVar12 = (ulong)((uint)uVar12 & 0xfffff000);
                uVar8 = uVar12;
              }
            }
            nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x288,"ceutilsMemset_IMPL",1,
                         "NVRM: CeUtils Memset dstAddr: %llx,  size: %x\n");
            local_a0[1] = memdescGetPtePhysAddr(plVar2,cVar11,lVar10);
            local_88 = (undefined4)uVar8;
            iVar7 = _ceutilsSubmitPushBuffer(param_1,local_d0,uVar9 == uVar12,local_a0);
            if (iVar7 != 0) {
              nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x28f,"ceutilsMemset_IMPL",4,
                           "NVRM: Cannot submit push buffer for memset.\n");
              return iVar7;
            }
            lVar10 = lVar10 + uVar12;
            local_d0 = 1;
            uVar9 = uVar9 - uVar12;
            if (uVar9 == 0) {
              if ((*(byte *)(param_2 + 4) & 1) != 0) {
                nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x29c,"ceutilsMemset_IMPL",1,
                             "NVRM: Async memset payload returned: 0x%x\n");
                param_2[5] = (ulong)local_80[0];
                return 0;
              }
              iVar7 = channelWaitForFinishPayload(lVar1,local_80[0],uVar8,0x3a558f);
              if (iVar7 != 0) {
                return iVar7;
              }
              nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x2a5,"ceutilsMemset_IMPL",1,
                           "NVRM: Work was done from RM PoV lastSubmitted = 0x%x\n",local_80[0]);
              return 0;
            }
          } while( true );
        }
        nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x25e,"ceutilsMemset_IMPL",4,
                     "NVRM: Invalid memset length passed.\n");
      }
      else {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x255,"ceutilsMemset_IMPL",4,
                     "NVRM: Invalid offset passed for the memdesc.\n");
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x24a,"ceutilsMemset_IMPL",4,
                   "NVRM: Invalid memory descriptor passed.\n");
    }
    iVar7 = 0x1f;
  }
  else {
    nvAssertFailedNoLog("!ceutilsIsSubmissionPaused(pCeUtils)","src/kernel/gpu/mem_mgr/ce_utils.c",
                        0x240);
    iVar7 = 3;
  }
  return iVar7;
}


// ===== 003a5830 ceutilsMemcopy_IMPL =====

int ceutilsMemcopy_IMPL(long param_1,long *param_2)

{
  uint uVar1;
  ulong uVar2;
  long *plVar3;
  long *plVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  ulong uVar10;
  ulong uVar11;
  char cVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  ulong uVar18;
  byte local_c9;
  undefined8 local_a0 [3];
  undefined4 local_88 [2];
  uint local_80 [4];
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  long local_60;
  long local_58;
  undefined2 local_50;
  long local_48;
  long local_40;
  
  uVar2 = *(ulong *)(param_1 + 0x50);
  uVar18 = 0;
  do {
    uVar8 = (int)uVar18 + 0x20;
    *(undefined8 *)((long)local_a0 + uVar18) = 0;
    *(undefined8 *)((long)local_a0 + uVar18 + 8) = 0;
    *(undefined8 *)((long)local_a0 + uVar18 + 0x10) = 0;
    *(undefined8 *)((long)local_80 + (uVar18 - 8)) = 0;
    uVar18 = (ulong)uVar8;
  } while (uVar8 < 0x60);
  *(undefined8 *)((long)local_a0 + (ulong)uVar8) = 0;
  if (*(long *)(param_1 + 0x88) == 0) {
    plVar3 = (long *)*param_2;
    plVar4 = (long *)param_2[1];
    if ((plVar3 == (long *)0x0) || (plVar4 == (long *)0x0)) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x2c9,"ceutilsMemcopy_IMPL",4,
                   "NVRM: Src/Dst Memory descriptor should be valid.\n");
    }
    else if ((*plVar3 == *(long *)(uVar2 + 0x178)) && (*(long *)(uVar2 + 0x178) == *plVar4)) {
      uVar18 = param_2[3];
      uVar16 = param_2[2];
      if ((uVar18 < (ulong)plVar3[6]) && (uVar16 < (ulong)plVar4[6])) {
        uVar17 = param_2[4];
        if (((uVar17 != 0) && (uVar17 + uVar18 <= (ulong)plVar3[6])) &&
           (uVar17 + uVar16 <= (ulong)plVar4[6])) {
          local_c9 = *(byte *)(param_2 + 5) & 4;
          local_a0[0]._0_1_ = 1;
          local_80[0] = *(int *)(param_1 + 0x70) + 1;
          *(ulong *)(param_1 + 0x70) = (ulong)local_80[0];
          local_6c = memdescGetAddressSpace(plVar3);
          local_70 = memdescGetAddressSpace(plVar4);
          local_68 = CONCAT44(*(undefined4 *)((long)plVar3 + 0x74),
                              *(undefined4 *)((long)plVar4 + 0x74));
          local_60 = param_2[7];
          local_58 = param_2[8];
          local_50 = (undefined2)param_2[9];
          local_48 = param_2[10];
          local_40 = param_2[0xb];
          uVar8 = *(uint *)(plVar3 + 0x2c);
          uVar1 = *(uint *)(plVar4 + 0x2c);
          iVar9 = memdescGetAddressSpace(plVar3);
          cVar5 = (iVar9 == 2) + '\x01';
          iVar9 = memdescGetAddressSpace(plVar4);
          cVar12 = (iVar9 == 2) + '\x01';
          cVar6 = memdescGetContiguity(plVar3,cVar5);
          cVar7 = memdescGetContiguity(plVar4,cVar12);
          uVar11 = uVar2;
          do {
            uVar10 = memdescGetPhysAddr(plVar3,cVar5,uVar18,uVar11);
            uVar11 = memdescGetPhysAddr(plVar4,cVar12,uVar16);
            uVar15 = uVar17;
            if (cVar6 == '\0') {
              uVar15 = (ulong)uVar8 - uVar10 % (ulong)uVar8;
            }
            uVar14 = uVar17;
            if (cVar7 == '\0') {
              uVar14 = (ulong)uVar1 - uVar11 % (ulong)uVar1;
            }
            uVar11 = uVar14;
            if (uVar15 <= uVar14) {
              uVar11 = uVar15;
            }
            uVar13 = uVar17;
            if (uVar11 <= uVar17) {
              uVar13 = uVar11;
            }
            if (uVar13 < 0xffffffff) {
              if (uVar17 < uVar11) {
                uVar11 = uVar17 & 0xffffffff;
                uVar15 = uVar17 & 0xffffffff;
              }
              else if (uVar15 < uVar14) {
                uVar11 = uVar15 & 0xffffffff;
                uVar15 = uVar15 & 0xffffffff;
              }
              else {
                uVar11 = uVar14 & 0xffffffff;
                uVar15 = uVar14 & 0xffffffff;
              }
            }
            else {
              uVar15 = 0xffffffff;
              uVar11 = 0xffffffff;
            }
            nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x30e,"ceutilsMemcopy_IMPL",1,
                         "NVRM: CeUtils Memcopy dstAddr: %llx, srcAddr: %llx, size: %x\n");
            local_a0[2] = memdescGetPtePhysAddr(plVar3,cVar5,uVar18);
            local_a0[1] = memdescGetPtePhysAddr(plVar4,cVar12,uVar16);
            local_88[0] = (undefined4)uVar11;
            iVar9 = _ceutilsSubmitPushBuffer(param_1,local_c9,uVar17 == uVar15,local_a0);
            if (iVar9 != 0) {
              nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x317,"ceutilsMemcopy_IMPL",4,
                           "NVRM: Cannot submit push buffer for memcopy.\n");
              return iVar9;
            }
            local_c9 = 1;
            uVar18 = uVar18 + uVar15;
            uVar16 = uVar16 + uVar15;
            uVar17 = uVar17 - uVar15;
          } while (uVar17 != 0);
          if ((*(byte *)(param_2 + 5) & 1) != 0) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x325,"ceutilsMemcopy_IMPL",1,
                         "NVRM: Async memset payload returned: 0x%x\n");
            param_2[6] = (ulong)local_80[0];
            return 0;
          }
          iVar9 = channelWaitForFinishPayload(uVar2,local_80[0],uVar10);
          if (iVar9 != 0) {
            return iVar9;
          }
          nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x32e,"ceutilsMemcopy_IMPL",1,
                       "NVRM: Work was done from RM PoV lastSubmitted = 0x%x\n",local_80[0]);
          return 0;
        }
        nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x2e0,"ceutilsMemcopy_IMPL",4,
                     "NVRM: Invalid memcopy length.\n");
      }
      else {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x2d9,"ceutilsMemcopy_IMPL",4,
                     "NVRM: Invalid offset passed for the src/dst memdesc.\n");
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x2d0,"ceutilsMemcopy_IMPL",4,
                   "NVRM: CeUtils does not support p2p copies right now. \n");
    }
    iVar9 = 0x1f;
  }
  else {
    nvAssertFailedNoLog("!ceutilsIsSubmissionPaused(pCeUtils)","src/kernel/gpu/mem_mgr/ce_utils.c",
                        0x2c4);
    iVar9 = 3;
  }
  return iVar9;
}


// ===== 003a5e30 ceutilsUpdateProgress_IMPL =====

ulong ceutilsUpdateProgress_IMPL(long param_1)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  
  if ((param_1 == 0) || (lVar3 = *(long *)(param_1 + 0x50), lVar3 == 0)) {
    nvAssertFailedNoLog("(pCeUtils != NULL) && (pCeUtils->pChannel != NULL)",
                        "src/kernel/gpu/mem_mgr/ce_utils.c",0x33d);
    lVar3 = *(long *)(param_1 + 0x50);
  }
  uVar2 = *(ulong *)(param_1 + 0x78);
  uVar1 = channelReadChannelMemdesc(lVar3,*(undefined4 *)(lVar3 + 0x50));
  if ((uint)uVar2 != uVar1) {
    if (uVar1 < (uint)uVar2) {
      uVar2 = uVar2 + 0x100000000;
    }
    uVar2 = uVar2 & 0xffffffff00000000 | (ulong)uVar1;
    *(ulong *)(param_1 + 0x78) = uVar2;
  }
  return uVar2;
}


// ===== 003a5eb0 _ceutilsProcessCompletionCallbacks =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _ceutilsProcessCompletionCallbacks(long param_1)

{
  ulong uVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined1 local_40 [24];
  
  uVar1 = ceutilsUpdateProgress_IMPL();
  nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x5f,"_ceutilsProcessCompletionCallbacks",1,
               "NVRM: lastCompletedPayload=%llu\n",uVar1);
  listInitIntrusive_IMPL(local_40,0x18);
  portSyncSpinlockAcquire(*(undefined8 *)(param_1 + 0x98));
  while( true ) {
    lVar2 = listHead_IMPL(param_1 + 0xa0);
    if ((lVar2 == 0) || (uVar1 < *(ulong *)(lVar2 + 0x10))) break;
    listRemoveIntrusive_IMPL(param_1 + 0xa0,lVar2);
    listAppendExisting_IMPL(local_40,lVar2);
  }
  portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x98));
  while( true ) {
    puVar3 = (undefined8 *)listHead_IMPL(local_40);
    if (puVar3 == (undefined8 *)0x0) break;
    nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x70,"_ceutilsProcessCompletionCallbacks",1,
                 "NVRM: calling completion callback payload=%llu\n",puVar3[2]);
    (*(code *)*puVar3)(puVar3[1]);
    listRemoveIntrusive_IMPL(local_40,puVar3);
    portMemFree(puVar3);
  }
  listDestroyIntrusive_IMPL(local_40);
  return;
}


// ===== 003a5fe0 _ceutilsSemaphoreEventCallback =====

void _ceutilsSemaphoreEventCallback(void)

{
  _ceutilsProcessCompletionCallbacks();
  return;
}


// ===== 003a5ff0 ceutilsDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void ceutilsDestruct_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  
  lVar1 = *(long *)(param_1 + 0x58);
  lVar2 = *(long *)(param_1 + 0x50);
  uVar3 = *(undefined8 *)(lVar1 + 0x1b78);
  lVar7 = rmapiGetInterface(4);
  lVar4 = *(long *)(param_1 + 0x70);
  iVar5 = (uint)(*(char *)(lVar2 + 0x194) != '\0') << 5;
  channelWaitForFinishPayload(*(undefined8 *)(param_1 + 0x50),lVar4);
  _ceutilsProcessCompletionCallbacks(param_1);
  portSyncSpinlockAcquire(*(undefined8 *)(param_1 + 0x98));
  iVar6 = listCount_IMPL(param_1 + 0xa0);
  if (iVar6 != 0) {
    nvAssertFailedNoLog("listCount(&pCeUtils->completionCallbacks) == 0",
                        "src/kernel/gpu/mem_mgr/ce_utils.c",0x15b);
  }
  portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x98));
  if (*(long *)(param_1 + 0x78) != lVar4) {
    nvAssertFailedNoLog("pCeUtils->lastCompletedPayload == lastSubmittedPayload",
                        "src/kernel/gpu/mem_mgr/ce_utils.c",0x15e);
  }
  if ((*(char *)(lVar2 + 0x170) != '\0') && (*(long *)(lVar2 + 0xf8) != 0)) {
    if (*(char *)(*(long *)(&DAT_00001b90 + lVar1) + 0xad0c) == '\0') {
      memmgrMemDescEndTransfer_IMPL(uVar3,*(undefined8 *)(lVar2 + 0xd0),iVar5);
      *(undefined8 *)(lVar2 + 0xf8) = 0;
    }
    else {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x168,"ceutilsDestruct_IMPL",4,
                   "NVRM: Leaked USERD mapping from ceUtils!\n");
    }
  }
  if (*(long *)(lVar2 + 0xe8) != 0) {
    if (*(char *)(*(long *)(&DAT_00001b90 + lVar1) + 0xad0c) == '\0') {
      memmgrMemDescEndTransfer_IMPL(uVar3,*(undefined8 *)(lVar2 + 0xd8),iVar5);
      *(undefined8 *)(lVar2 + 0xe8) = 0;
    }
    else {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x175,"ceutilsDestruct_IMPL",4,
                   "NVRM: Leaked pushbuffer mapping!\n");
    }
  }
  if (*(long *)(lVar2 + 0x140) != 0) {
    if (*(char *)(*(long *)(&DAT_00001b90 + lVar1) + 0xad0c) == '\0') {
      memmgrMemDescEndTransfer_IMPL(uVar3,*(undefined8 *)(lVar2 + 0xe0),iVar5);
      *(undefined8 *)(lVar2 + 0x140) = 0;
    }
    else {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/ce_utils.c",0x182,"ceutilsDestruct_IMPL",4,
                   "NVRM: Leaked notifier mapping!\n");
    }
  }
  (**(code **)(lVar7 + 0x18))(lVar7,*(undefined4 *)(lVar2 + 0xac),*(undefined4 *)(lVar2 + 0xac));
  portMemFree(lVar2);
  listDestroyIntrusive_IMPL(param_1 + 0xa0);
  portSyncSpinlockDestroy(*(undefined8 *)(param_1 + 0x98));
  return;
}


// ===== 003a6280 ceutilsPauseSubmission_IMPL =====

void ceutilsPauseSubmission_IMPL(long param_1,char param_2)

{
  if (param_2 == '\0') {
    *(long *)(param_1 + 0x88) = *(long *)(param_1 + 0x88) + 1;
    return;
  }
  channelWaitForFinishPayload(*(undefined8 *)(param_1 + 0x50),*(undefined8 *)(param_1 + 0x70));
  *(long *)(param_1 + 0x88) = *(long *)(param_1 + 0x88) + 1;
  return;
}


// ===== 003a62c0 ceutilsResumeSubmission_IMPL =====

void ceutilsResumeSubmission_IMPL(long param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int local_1c [3];
  
  if (*(long *)(param_1 + 0x88) == 0) {
    nvAssertFailedNoLog("ceutilsIsSubmissionPaused(pCeUtils)","src/kernel/gpu/mem_mgr/ce_utils.c",
                        0x372);
    return;
  }
  if ((*(char *)(param_1 + 0x80) == '\0') && (*(long *)(param_1 + 0xb8) == 0)) {
    puVar1 = *(undefined4 **)(param_1 + 0x50);
    iVar2 = ceutilsGetFirstAsyncCe_IMPL
                      (param_1,*(undefined8 *)(param_1 + 0x58),*(undefined8 *)(puVar1 + 0x18),
                       *puVar1,local_1c,0);
    if (iVar2 == 0) {
      if (puVar1[0x60] == local_1c[0]) goto LAB_003a6309;
    }
    else {
      nvAssertFailedNoLog("ceutilsGetFirstAsyncCe(pCeUtils, pGpu, pChannel->pRsClient, pChannel->deviceId, &ceId, NV_FALSE) == NV_OK"
                          ,"src/kernel/gpu/mem_mgr/ce_utils.c",0x388);
    }
    nvAssertFailedNoLog("ceutilsUsesPreferredCe(pCeUtils)","src/kernel/gpu/mem_mgr/ce_utils.c",0x373
                       );
  }
  else {
    nvAssertFailedNoLog(&DAT_00d49bb1,"src/kernel/gpu/mem_mgr/ce_utils.c",0x385);
  }
LAB_003a6309:
  *(long *)(param_1 + 0x88) = *(long *)(param_1 + 0x88) + -1;
  return;
}


// ===== 003a63b0 ceutilsUsesPreferredCe_IMPL =====

bool ceutilsUsesPreferredCe_IMPL(long param_1)

{
  undefined4 *puVar1;
  int iVar2;
  bool bVar3;
  int local_c;
  
  if ((*(char *)(param_1 + 0x80) == '\0') && (*(long *)(param_1 + 0xb8) == 0)) {
    puVar1 = *(undefined4 **)(param_1 + 0x50);
    iVar2 = ceutilsGetFirstAsyncCe_IMPL
                      (param_1,*(undefined8 *)(param_1 + 0x58),*(undefined8 *)(puVar1 + 0x18),
                       *puVar1,&local_c,0);
    if (iVar2 == 0) {
      return puVar1[0x60] == local_c;
    }
    nvAssertFailedNoLog("ceutilsGetFirstAsyncCe(pCeUtils, pGpu, pChannel->pRsClient, pChannel->deviceId, &ceId, NV_FALSE) == NV_OK"
                        ,"src/kernel/gpu/mem_mgr/ce_utils.c",0x388);
    bVar3 = false;
  }
  else {
    nvAssertFailedNoLog(&DAT_00d49bb1,"src/kernel/gpu/mem_mgr/ce_utils.c",0x385);
    bVar3 = true;
  }
  return bVar3;
}


// ===== 003a6470 channelSetupIDs =====

ulong channelSetupIDs(long param_1,long param_2,char param_3,char param_4)

{
  ulong uVar1;
  char *pcVar2;
  undefined8 uVar3;
  
  uVar1 = serverutilGenResourceHandle(*(undefined4 *)(param_1 + 0xac),param_1 + 4);
  uVar3 = 0x3b;
  pcVar2 = "serverutilGenResourceHandle(pChannel->hClient, &pChannel->physMemId)";
  if ((int)uVar1 == 0) {
    uVar1 = serverutilGenResourceHandle
                      (*(undefined4 *)(param_1 + 0xac),param_1 + 8,
                       "serverutilGenResourceHandle(pChannel->hClient, &pChannel->physMemId)",
                       "src/kernel/gpu/mem_mgr/channel_utils.c",0x3b);
    uVar3 = 0x3e;
    pcVar2 = "serverutilGenResourceHandle(pChannel->hClient, &pChannel->channelId)";
    if ((int)uVar1 == 0) {
      uVar1 = serverutilGenResourceHandle
                        (*(undefined4 *)(param_1 + 0xac),param_1 + 0x10,
                         "serverutilGenResourceHandle(pChannel->hClient, &pChannel->channelId)",
                         "src/kernel/gpu/mem_mgr/channel_utils.c",0x3e);
      uVar3 = 0x41;
      pcVar2 = "serverutilGenResourceHandle(pChannel->hClient, &pChannel->errNotifierIdVirt)";
      if ((int)uVar1 == 0) {
        uVar1 = serverutilGenResourceHandle
                          (*(undefined4 *)(param_1 + 0xac),param_1 + 0x14,
                           "serverutilGenResourceHandle(pChannel->hClient, &pChannel->errNotifierIdVirt)"
                           ,"src/kernel/gpu/mem_mgr/channel_utils.c",0x41);
        uVar3 = 0x44;
        pcVar2 = "serverutilGenResourceHandle(pChannel->hClient, &pChannel->errNotifierIdPhys)";
        if ((int)uVar1 == 0) {
          uVar1 = serverutilGenResourceHandle
                            (*(undefined4 *)(param_1 + 0xac),param_1 + 0x18,
                             "serverutilGenResourceHandle(pChannel->hClient, &pChannel->errNotifierIdPhys)"
                             ,"src/kernel/gpu/mem_mgr/channel_utils.c",0x44);
          uVar3 = 0x47;
          pcVar2 = "serverutilGenResourceHandle(pChannel->hClient, &pChannel->engineObjectId)";
          if ((int)uVar1 == 0) {
            uVar1 = serverutilGenResourceHandle
                              (*(undefined4 *)(param_1 + 0xac),param_1 + 0x1c,
                               "serverutilGenResourceHandle(pChannel->hClient, &pChannel->engineObjectId)"
                               ,"src/kernel/gpu/mem_mgr/channel_utils.c",0x47);
            uVar3 = 0x4a;
            pcVar2 = "serverutilGenResourceHandle(pChannel->hClient, &pChannel->eventId)";
            if ((int)uVar1 == 0) {
              uVar1 = serverutilGenResourceHandle
                                (*(undefined4 *)(param_1 + 0xac),param_1 + 0x20,
                                 "serverutilGenResourceHandle(pChannel->hClient, &pChannel->eventId)"
                                 ,"src/kernel/gpu/mem_mgr/channel_utils.c",0x4a);
              uVar3 = 0x4d;
              pcVar2 = "serverutilGenResourceHandle(pChannel->hClient, &pChannel->pushBufferId)";
              if ((int)uVar1 == 0) {
                uVar1 = serverutilGenResourceHandle
                                  (*(undefined4 *)(param_1 + 0xac),param_1 + 0x154,
                                   "serverutilGenResourceHandle(pChannel->hClient, &pChannel->pushBufferId)"
                                   ,"src/kernel/gpu/mem_mgr/channel_utils.c",0x4d);
                uVar3 = 0x50;
                pcVar2 = 
                "serverutilGenResourceHandle(pChannel->hClient, &pChannel->doorbellRegionHandle)";
                if ((int)uVar1 == 0) {
                  uVar1 = serverutilGenResourceHandle
                                    (*(undefined4 *)(param_1 + 0xac),param_1 + 0x16c,
                                     "serverutilGenResourceHandle(pChannel->hClient, &pChannel->doorbellRegionHandle)"
                                     ,"src/kernel/gpu/mem_mgr/channel_utils.c",0x50);
                  uVar3 = 0x53;
                  pcVar2 = "serverutilGenResourceHandle(pChannel->hClient, &pChannel->hUserD)";
                  if ((int)uVar1 == 0) {
                    if (*(int *)(param_1 + 0x2c) != 0) {
                      nvAssertFailedNoLog("pChannel->hVASpaceId == NV01_NULL_OBJECT",
                                          "src/kernel/gpu/mem_mgr/channel_utils.c",0x57,
                                          "src/kernel/gpu/mem_mgr/channel_utils.c",0x53);
                      uVar1 = uVar1 & 0xffffffff;
                    }
                    if (param_3 == '\0') {
                      if (*(char *)(param_2 + 0x909) == '\0') {
                        return uVar1;
                      }
                      if (param_4 == '\0') {
                        return uVar1;
                      }
                    }
                    uVar1 = serverutilGenResourceHandle
                                      (*(undefined4 *)(param_1 + 0xac),param_1 + 0x2c);
                    if ((int)uVar1 == 0) {
                      return uVar1;
                    }
                    uVar3 = 0x5b;
                    pcVar2 = "serverutilGenResourceHandle(pChannel->hClient, &pChannel->hVASpaceId)"
                    ;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  nvCheckOkFailedNoLog(4,uVar1 & 0xffffffff,pcVar2,"src/kernel/gpu/mem_mgr/channel_utils.c",uVar3);
  return uVar1 & 0xffffffff;
}


// ===== 003a66b0 channelAllocSubdevice =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int channelAllocSubdevice(long param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  char *extraout_RDX;
  char *pcVar5;
  char *extraout_RDX_00;
  undefined8 uVar6;
  undefined1 auVar7 [16];
  undefined8 local_68;
  ulong local_60;
  ulong local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  auVar7 = rmapiGetInterface(4);
  pcVar5 = auVar7._8_8_;
  lVar4 = auVar7._0_8_;
  if ((char)param_2[0x2c] == '\0') {
    iVar2 = (**(code **)(lVar4 + 8))(lVar4,0,0,0,0,param_2 + 0x2b,4);
    if (iVar2 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar2,
                 "pRmApi->AllocWithHandle(pRmApi, NV01_NULL_OBJECT, NV01_NULL_OBJECT, NV01_NULL_OBJECT, NV01_ROOT, &pChannel->hClient, sizeof(pChannel->hClient))"
                 ,"src/kernel/gpu/mem_mgr/channel_utils.c",0x6f);
      return iVar2;
    }
    iVar2 = serverGetClientUnderLock(g_resServ,param_2[0x2b],&local_68,0x3a66d1);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,"serverGetClientUnderLock(&g_resServ, pChannel->hClient, &pRsClient)",
                 "src/kernel/gpu/mem_mgr/channel_utils.c",0x75);
      goto LAB_003a67fb;
    }
    *(undefined8 *)(param_2 + 0x18) = local_68;
    if (*(char *)(param_1 + 0x908) == '\0') {
      iVar2 = clientSetHandleGenerator_IMPL(local_68,1,0xfffffffe);
      pcVar5 = extraout_RDX_00;
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,"clientSetHandleGenerator(pRsClient, 1U, ~0U - 1U)",
                   "src/kernel/gpu/mem_mgr/channel_utils.c",0x86);
        goto LAB_003a67fb;
      }
    }
    else {
      iVar2 = clientSetHandleGenerator_IMPL(local_68,0xcaf00000,0x3f000);
      pcVar5 = extraout_RDX;
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,
                   "clientSetHandleGenerator(pRsClient, RS_UNIQUE_HANDLE_BASE, RS_UNIQUE_HANDLE_RANGE/2 - VGPU_RESERVED_HANDLE_RANGE)"
                   ,"src/kernel/gpu/mem_mgr/channel_utils.c",0x7e);
        goto LAB_003a67fb;
      }
    }
    if (*param_2 == 0) goto LAB_003a6930;
LAB_003a676b:
    if (param_2[3] == 0) {
LAB_003a677c:
      iVar2 = clientGenResourceHandle_IMPL(local_68,param_2 + 3,pcVar5);
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,"clientGenResourceHandle(pRsClient, &pChannel->subdeviceId)",
                   "src/kernel/gpu/mem_mgr/channel_utils.c",0xa7);
        goto LAB_003a67fb;
      }
      local_60 = local_60 & 0xffffffff00000000;
      uVar3 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
      local_60 = CONCAT44(local_60._4_4_,uVar3);
      iVar2 = (**(code **)(lVar4 + 8))(lVar4,param_2[0x2b],*param_2,param_2[3],0x2080,&local_60,4);
      if (iVar2 != 0) {
        uVar6 = 0xaf;
        pcVar5 = 
        "pRmApi->AllocWithHandle(pRmApi, pChannel->hClient, pChannel->deviceId, pChannel->subdeviceId, NV20_SUBDEVICE_0, &params, sizeof(params))"
        ;
        goto LAB_003a67e8;
      }
      goto LAB_003a6859;
    }
  }
  else {
    local_68 = *(undefined8 *)(param_2 + 0x18);
    if (*param_2 == 0) {
LAB_003a6930:
      iVar2 = clientGenResourceHandle_IMPL(local_68,param_2);
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,"clientGenResourceHandle(pRsClient, &pChannel->deviceId)",
                   "src/kernel/gpu/mem_mgr/channel_utils.c",0x91);
        goto LAB_003a67fb;
      }
      iVar2 = param_2[0x2b];
      local_58 = 0;
      local_50 = 0;
      local_48 = 0;
      local_40 = 0;
      local_60 = CONCAT44(iVar2,*(undefined4 *)(param_1 + 0x7b4));
      local_38 = 0;
      local_30 = 0;
      iVar2 = (**(code **)(lVar4 + 8))(lVar4,iVar2,iVar2,*param_2,0x80,&local_60,0x38);
      uVar6 = 0x9c;
      pcVar5 = 
      "pRmApi->AllocWithHandle(pRmApi, pChannel->hClient, pChannel->hClient, pChannel->deviceId, NV01_DEVICE_0, &params, sizeof(params))"
      ;
      if (iVar2 == 0) goto LAB_003a676b;
LAB_003a67e8:
      nvCheckOkFailedNoLog(4,iVar2,pcVar5,"src/kernel/gpu/mem_mgr/channel_utils.c",uVar6);
      goto LAB_003a67fb;
    }
    if (param_2[3] == 0) goto LAB_003a677c;
LAB_003a6859:
    if (param_1 == 0) {
      return 0;
    }
  }
  if (((*(long *)(param_1 + 0x1bc0) == 0) ||
      (cVar1 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar1 == '\0')) ||
     (*(long *)(param_2 + 0x62) == 0)) {
    return 0;
  }
  iVar2 = clientGenResourceHandle_IMPL(local_68,param_2 + 100);
  if (iVar2 == 0) {
    local_60 = 0;
    local_58 = (ulong)*(uint *)(*(long *)(param_2 + 0x62) + 0x968);
    iVar2 = (**(code **)(lVar4 + 8))
                      (lVar4,param_2[0x2b],param_2[3],param_2[100],0xc637,&local_60,0x10);
    if (iVar2 == 0) {
      return 0;
    }
    nvAssertOkFailedNoLog
              (iVar2,
               "pRmApi->AllocWithHandle(pRmApi, pChannel->hClient, pChannel->subdeviceId, pChannel->hPartitionRef, AMPERE_SMC_PARTITION_REF, &params, sizeof(params))"
               ,"src/kernel/gpu/mem_mgr/channel_utils.c",0xc4);
  }
  else {
    nvAssertOkFailedNoLog
              (iVar2,"clientGenResourceHandle(pRsClient, &pChannel->hPartitionRef)",
               "src/kernel/gpu/mem_mgr/channel_utils.c",0xbc);
  }
LAB_003a67fb:
  if ((char)param_2[0x2c] == '\0') {
    (**(code **)(lVar4 + 0x18))(lVar4,param_2[0x2b],param_2[0x2b]);
    return iVar2;
  }
  return iVar2;
}


// ===== 003a6b40 channelSetupChannelBufferSizes =====

void channelSetupChannelBufferSizes(long param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pChannel != NULL","src/kernel/gpu/mem_mgr/channel_utils.c",0xdf);
    return;
  }
  uVar1 = *(uint *)(param_1 + 0x150);
  if (uVar1 < 4) {
    if (uVar1 == 3) {
      uVar7 = 0x94;
      uVar6 = 0x94000;
      uVar5 = 0x9c00c;
      uVar4 = 0x9c004;
      uVar3 = 0x9c000;
      uVar2 = 0x9c008;
    }
    else if (uVar1 == 1) {
      uVar7 = 0x94;
      uVar6 = 0x94000;
      uVar5 = 0x9c008;
      uVar4 = 0x9c004;
      uVar3 = 0x9c000;
      uVar2 = 0x9c008;
    }
    else {
      uVar7 = 100;
      uVar6 = 0x64000;
      uVar5 = 0x6c008;
      uVar4 = 0x6c004;
      uVar3 = 0x6c000;
      uVar2 = 0x6c008;
    }
    *(undefined4 *)(param_1 + 0x48) = uVar7;
    *(undefined4 *)(param_1 + 0x44) = 0x30;
    *(undefined4 *)(param_1 + 0x3c) = 0x1000;
    *(undefined4 *)(param_1 + 0x40) = uVar6;
    *(undefined4 *)(param_1 + 0x38) = uVar5;
    *(undefined4 *)(param_1 + 0x4c) = uVar3;
    *(undefined4 *)(param_1 + 0x50) = uVar4;
    *(undefined4 *)(param_1 + 0x54) = uVar2;
    return;
  }
  nvAssertFailedNoLog("pChannel->type < MAX_CHANNEL_TYPE","src/kernel/gpu/mem_mgr/channel_utils.c",
                      0xe0);
  return;
}


// ===== 003a6c40 channelReadChannelMemdesc =====

undefined4 channelReadChannelMemdesc(long param_1,uint param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  long lVar4;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pChannel != NULL","src/kernel/gpu/mem_mgr/channel_utils.c",0x105);
  }
  else if (*(long *)(param_1 + 0x178) == 0) {
    nvAssertFailedNoLog("pChannel->pGpu != NULL","src/kernel/gpu/mem_mgr/channel_utils.c",0x106);
  }
  else {
    cVar1 = *(char *)(param_1 + 0x194);
    if (*(long *)(param_1 + 0xe8) != 0) {
      return *(undefined4 *)(*(long *)(param_1 + 0xe8) + (ulong)param_2);
    }
    uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x178) + 0x1b78);
    lVar4 = memmgrMemDescBeginTransfer_IMPL(uVar3,*(undefined8 *)(param_1 + 0xd8));
    *(long *)(param_1 + 0xe8) = lVar4;
    if (lVar4 != 0) {
      uVar2 = *(undefined4 *)(lVar4 + (ulong)param_2);
      memmgrMemDescEndTransfer_IMPL
                (uVar3,*(undefined8 *)(param_1 + 0xd8),(-(uint)(cVar1 == '\0') & 0xffffffe0) + 0x26)
      ;
      *(undefined8 *)(param_1 + 0xe8) = 0;
      return uVar2;
    }
    nvAssertFailedNoLog("pChannel->pbCpuVA != NULL","src/kernel/gpu/mem_mgr/channel_utils.c",0x11b);
  }
  return 0;
}


// ===== 003a6d60 channelServiceScrubberInterrupts =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void channelServiceScrubberInterrupts(long param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  int local_54;
  undefined1 local_50 [32];
  
  lVar1 = *(long *)(param_1 + 0x178);
  lVar2 = *(long *)(lVar1 + 0x1c20);
  lVar4 = gpuGetKernelFifoShared_IMPL(lVar1);
  if (*(int *)(param_1 + 0x150) == 3) {
    iVar5 = 0x31;
    iVar3 = 0x2f;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x180) + 0xf;
    iVar5 = *(int *)(param_1 + 0x180) + 9;
  }
  bitVectorClrAll_IMPL(local_50,0xb4);
  bitVectorSet_IMPL(local_50,0xb4,iVar3);
  if (*(char *)(lVar4 + 0x4b2) == '\0') {
    bitVectorSet_IMPL(local_50,0xb4,4);
  }
  else {
    iVar3 = (**(code **)(lVar4 + 0x218))(lVar1,lVar4,2,iVar5,3,&local_54);
    if (iVar3 != 0) {
      nvAssertOkFailedNoLog
                (iVar3,
                 "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_RM_ENGINE_TYPE, engineType, ENGINE_INFO_TYPE_RUNLIST, &runlistId)"
                 ,"src/kernel/gpu/mem_mgr/channel_utils.c",0x14b);
    }
    bitVectorSet_IMPL(local_50,0xb4,local_54 + 0x5c);
  }
  (**(code **)(lVar2 + 0x300))(lVar1,lVar2,local_50,0);
  return;
}


// ===== 003a6e90 channelWaitForFinishPayload =====

int channelWaitForFinishPayload(long param_1,ulong param_2)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined1 local_50 [32];
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pChannel != NULL","src/kernel/gpu/mem_mgr/channel_utils.c",0x15e);
    return 0x40;
  }
  iVar4 = 0;
  lVar1 = *(long *)(param_1 + 0x178);
  timeoutSet(lVar1 + 0x1af0,local_50,0,4);
  while( true ) {
    uVar3 = channelReadChannelMemdesc(param_1,*(undefined4 *)(param_1 + 0x50));
    if (param_2 <= uVar3) {
      return iVar4;
    }
    iVar4 = timeoutCheck(lVar1 + 0x1af0,local_50,0x16c);
    if (iVar4 == 0x65) break;
    cVar2 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4));
    if (cVar2 == '\0') {
      osSchedule();
    }
    else {
      gpuGetKernelFifoShared_IMPL(lVar1);
      channelServiceScrubberInterrupts(param_1);
    }
  }
  return 0x65;
}


// ===== 003a6f80 channelWaitForFreeEntry =====

int channelWaitForFreeEntry(long param_1,uint *param_2)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined1 local_50 [32];
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pChannel != NULL","src/kernel/gpu/mem_mgr/channel_utils.c",0x18d);
  }
  else {
    iVar4 = 0;
    lVar1 = *(long *)(param_1 + 0x178);
    uVar6 = (*(int *)(param_1 + 0x148) + 1U) % *(uint *)(param_1 + 0x3c);
    timeoutSet(lVar1 + 0x1af0,local_50,0,4);
    while( true ) {
      uVar3 = channelReadChannelMemdesc(param_1,*(undefined4 *)(param_1 + 0x4c));
      uVar5 = channelReadChannelMemdesc(param_1,*(undefined4 *)(param_1 + 0x50));
      nvDbg_Printf("src/kernel/gpu/mem_mgr/channel_utils.c",0x19d,"channelWaitForFreeEntry",1,
                   "NVRM: Get Index: %x, PayloadIndex: %x\n",uVar3,uVar5);
      if (uVar6 != uVar3) break;
      iVar4 = timeoutCheck(lVar1 + 0x1af0,local_50,0x1a5);
      if (iVar4 == 0x65) {
        return 0x65;
      }
      cVar2 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4));
      if (cVar2 == '\0') {
        osSchedule();
      }
      else {
        gpuGetKernelFifoShared_IMPL(lVar1);
        channelServiceScrubberInterrupts(param_1);
      }
    }
    if (iVar4 != 0) {
      return iVar4;
    }
    if (param_2 != (uint *)0x0) {
      *param_2 = uVar6;
      return 0;
    }
    nvAssertFailedNoLog("pPutIndex != NULL","src/kernel/gpu/mem_mgr/channel_utils.c",0x1ba);
  }
  return 0x40;
}


// ===== 003a7140 channelFillGpFifo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 channelFillGpFifo(long param_1,uint param_2,uint param_3)

{
  long lVar1;
  undefined8 uVar2;
  bool bVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  undefined4 uVar8;
  long lVar9;
  int iVar10;
  
  lVar7 = *(long *)(param_1 + 0x178);
  gpuGetKernelFifoShared_IMPL(lVar7);
  iVar10 = (-(uint)(*(char *)(param_1 + 0x194) == '\0') & 0xffffffe0) + 0x26;
  if (param_2 < *(uint *)(param_1 + 0x3c)) {
    lVar1 = *(long *)(&DAT_00001b90 + lVar7);
    bVar3 = false;
    lVar6 = *(long *)(param_1 + 0xe8);
    uVar2 = *(undefined8 *)(lVar7 + 0x1b78);
    if (lVar6 == 0) {
      lVar6 = memmgrMemDescBeginTransfer_IMPL(uVar2,*(undefined8 *)(param_1 + 0xd8),iVar10);
      *(long *)(param_1 + 0xe8) = lVar6;
      if (lVar6 != 0) {
        bVar3 = true;
        goto LAB_003a71be;
      }
      nvAssertFailedNoLog("pChannel->pbCpuVA != NULL","src/kernel/gpu/mem_mgr/channel_utils.c",0x1e7
                         );
    }
    else {
LAB_003a71be:
      lVar5 = (ulong)(param_2 * *(int *)(param_1 + 0x48)) + *(long *)(param_1 + 0xb8);
      lVar9 = (ulong)(uint)(*(int *)(param_1 + 0x148) * 8) + (ulong)*(uint *)(param_1 + 0x40);
      *(uint *)(lVar6 + lVar9) = (uint)lVar5 & 0xfffffffc;
      *(uint *)(lVar6 + 4 + lVar9) = (uint)(byte)((ulong)lVar5 >> 0x20) | (param_3 & 0x7ffffc) << 8;
      if (bVar3) {
        memmgrMemDescEndTransfer_IMPL(uVar2,*(undefined8 *)(param_1 + 0xd8),iVar10);
        *(undefined8 *)(param_1 + 0xe8) = 0;
        osFlushCpuWriteCombineBuffer();
        lVar6 = *(long *)(param_1 + 0xf8);
        if (lVar6 == 0) goto LAB_003a7300;
LAB_003a72cf:
        *(uint *)(lVar6 + 0x8c) = param_2;
        bVar3 = true;
        memmgrMemDescEndTransfer_IMPL(uVar2,*(undefined8 *)(param_1 + 0xd0),iVar10);
        *(undefined8 *)(param_1 + 0xf8) = 0;
      }
      else {
        osFlushCpuWriteCombineBuffer();
        if (*(long *)(param_1 + 0xf8) == 0) {
LAB_003a7300:
          lVar6 = memmgrMemDescBeginTransfer_IMPL(uVar2,*(undefined8 *)(param_1 + 0xd0),iVar10);
          *(long *)(param_1 + 0xf8) = lVar6;
          if (lVar6 == 0) {
            nvAssertFailedNoLog("pChannel->pControlGPFifo != NULL",
                                "src/kernel/gpu/mem_mgr/channel_utils.c",0x207);
            goto LAB_003a7408;
          }
          goto LAB_003a72cf;
        }
        *(uint *)(*(long *)(param_1 + 0xf8) + 0x8c) = param_2;
        bVar3 = false;
      }
      osFlushCpuWriteCombineBuffer();
      iVar4 = (**(code **)(lVar1 + 0x4f8))(lVar7);
      if (iVar4 == 0) {
        if (*(char *)(param_1 + 0x168) == '\0') {
          return 0;
        }
        if (*(long *)(param_1 + 0x140) != 0) {
          **(undefined4 **)(param_1 + 0x160) = *(undefined4 *)(*(long *)(param_1 + 0x140) + 8);
          if (!bVar3) {
            return 0;
          }
LAB_003a73c3:
          memmgrMemDescEndTransfer_IMPL(uVar2,*(undefined8 *)(param_1 + 0xe0),iVar10);
          *(undefined8 *)(param_1 + 0x140) = 0;
          return 0;
        }
        lVar7 = memmgrMemDescBeginTransfer_IMPL(uVar2,*(undefined8 *)(param_1 + 0xe0),iVar10);
        if (lVar7 != 0) {
          *(long *)(param_1 + 0x140) = lVar7 + 0x10;
          **(undefined4 **)(param_1 + 0x160) = *(undefined4 *)(lVar7 + 0x18);
          goto LAB_003a73c3;
        }
        nvAssertFailedNoLog("pErrNotifierCpuVA != NULL","src/kernel/gpu/mem_mgr/channel_utils.c",
                            0x23a);
        goto LAB_003a7408;
      }
      nvDbg_Printf("src/kernel/gpu/mem_mgr/channel_utils.c",0x21b,"channelFillGpFifo",4,
                   "NVRM: Busflush failed in _scrubFillGpFifo\n");
    }
    uVar8 = 0xffff;
  }
  else {
    nvAssertFailedNoLog("putIndex < pChannel->channelNumGpFifioEntries",
                        "src/kernel/gpu/mem_mgr/channel_utils.c",0x1de);
LAB_003a7408:
    uVar8 = 0x40;
  }
  return uVar8;
}


// ===== 003a7480 channelFillPbFastScrub =====

uint channelFillPbFastScrub(long param_1,int param_2,char param_3,char param_4,long param_5)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  uVar2 = *(int *)(param_1 + 0x48) * param_2;
  puVar5 = (undefined4 *)((ulong)uVar2 + *(long *)(param_1 + 0xe8));
  nvDbg_Printf("src/kernel/gpu/mem_mgr/channel_utils.c",0x265,"channelFillPbFastScrub",1,
               "NVRM: PutIndex: %x, PbOffset: %x\n",param_2,uVar2);
  *puVar5 = 0x20010000;
  puVar5[1] = *(undefined4 *)(param_1 + 0x100);
  puVar5[2] = 0x200101c0;
  puVar5[3] = *(undefined4 *)(param_5 + 0x1c);
  puVar5[4] = 0x200101c1;
  puVar5[5] = *(undefined4 *)(param_5 + 0x1c);
  puVar5[6] = 0x200101c2;
  puVar5[7] = 5;
  iVar3 = 0;
  if (*(int *)(param_5 + 0x30) != 2) {
    iVar3 = 2 - (uint)(*(int *)(param_5 + 0x38) == 0);
  }
  puVar5[8] = 0x20010099;
  puVar5[9] = iVar3;
  if (param_4 == '\0') {
    uVar6 = 0;
    uVar2 = 0;
  }
  else {
    uVar6 = 8;
    uVar2 = 4;
  }
  lVar1 = *(long *)(param_5 + 0x40);
  puVar5[10] = 0x20020102;
  puVar5[0xb] = *(undefined4 *)(param_5 + 0xc);
  puVar5[0xc] = (int)*(undefined8 *)(param_5 + 8);
  puVar5[0xd] = 0x20010106;
  puVar5[0xe] = *(undefined4 *)(param_5 + 0x18);
  puVar4 = puVar5 + 0xf;
  if (uVar6 != 0) {
    puVar5[0xf] = 0x20030090;
    puVar5[0x10] = (int)((ulong)*(uint *)(param_1 + 0x50) + *(long *)(param_1 + 0xb8) >> 0x20);
    puVar5[0x11] = *(int *)(param_1 + 0x50) + *(int *)(param_1 + 0xb8);
    puVar4 = puVar5 + 0x13;
    puVar5[0x12] = *(undefined4 *)(param_5 + 0x20);
  }
  *puVar4 = 0x200101bf;
  puVar4[1] = 0;
  puVar4[2] = 0x200100c0;
  puVar4[3] = uVar2 | uVar6 | (uint)(lVar1 != 0) << 6 | 2 - (param_3 != '\0') | 0x4803180;
  uVar2 = *(uint *)(param_1 + 0x4c);
  lVar1 = *(long *)(param_1 + 0xb8);
  puVar4[4] = 0x20040017;
  *(ulong *)(puVar4 + 5) = (ulong)uVar2 + lVar1;
  puVar4[7] = param_2;
  puVar4[8] = 0;
  puVar4[9] = 0x2001001b;
  puVar4[10] = 1;
  uVar2 = ((int)puVar4 + 0x2c) - (int)puVar5;
  if (*(uint *)(param_1 + 0x48) < uVar2) {
    nvAssertFailedNoLog("methodSize <= pChannel->methodSizePerBlock",
                        "src/kernel/gpu/mem_mgr/channel_utils.c",0x2c9);
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 003a7680 channelFillCePb =====

uint channelFillCePb(long param_1,int param_2,char param_3,char param_4,char *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  uint uVar6;
  undefined4 *puVar7;
  long lVar8;
  uint uVar9;
  uint uVar10;
  long lVar11;
  uint uVar12;
  undefined4 *puVar13;
  uint uVar14;
  undefined4 *puVar15;
  
  uVar6 = *(int *)(param_1 + 0x48) * param_2;
  puVar15 = (undefined4 *)((ulong)uVar6 + *(long *)(param_1 + 0xe8));
  nvDbg_Printf("src/kernel/gpu/mem_mgr/channel_utils.c",0x332,"channelFillCePb",1,
               "NVRM: PutIndex: %x, PbOffset: %x\n",param_2,uVar6);
  *puVar15 = 0x20010000;
  puVar15[1] = *(undefined4 *)(param_1 + 0x100);
  if (param_5[0x50] == '\0') {
    puVar7 = puVar15 + 2;
    uVar6 = 0;
  }
  else {
    cVar5 = gpuIsCCFeatureEnabled_IMPL(*(undefined8 *)(param_1 + 0x178));
    if (cVar5 == '\0') {
      nvAssertFailedNoLog("gpuIsCCFeatureEnabled(pChannel->pGpu)",
                          "src/kernel/gpu/mem_mgr/channel_utils.c",0x2ff);
      return 0;
    }
    if (*(char *)(param_1 + 0x195) == '\0') {
      nvAssertFailedNoLog("pChannel->bSecure","src/kernel/gpu/mem_mgr/channel_utils.c",0x300);
      return 0;
    }
    if (*(uint *)(param_1 + 0x11c) < 0xc8b5) {
      nvAssertFailedNoLog("pChannel->hTdCopyClass >= HOPPER_DMA_COPY_A",
                          "src/kernel/gpu/mem_mgr/channel_utils.c",0x301);
      return 0;
    }
    cVar5 = param_5[0x51];
    puVar15[2] = 0x20010140;
    if (cVar5 == '\0') {
      puVar15[3] = 1;
      uVar6 = 0x100000;
      puVar15[4] = 0x20020145;
      puVar15[5] = *(undefined4 *)(param_5 + 0x5c);
      puVar7 = puVar15 + 7;
      puVar15[6] = (int)*(undefined8 *)(param_5 + 0x58);
    }
    else {
      puVar15[3] = 0;
      uVar6 = 0x100000;
      puVar15[4] = 0x2004014c;
      puVar15[5] = *(undefined4 *)(param_5 + 0x5c);
      puVar15[6] = (int)*(undefined8 *)(param_5 + 0x58);
      puVar15[7] = *(undefined4 *)(param_5 + 100);
      puVar7 = puVar15 + 9;
      puVar15[8] = (int)*(undefined8 *)(param_5 + 0x60);
    }
  }
  iVar1 = *(int *)(param_5 + 0x30);
  iVar2 = *(int *)(param_5 + 0x38);
  lVar8 = *(long *)(param_5 + 8);
  if (*param_5 == '\0') {
    *puVar7 = 0x200101c0;
    puVar13 = puVar7 + 4;
    uVar14 = 0;
    puVar7[1] = *(undefined4 *)(param_5 + 0x1c);
    puVar7[2] = 0x200101c2;
    puVar7[3] = 4;
    *puVar13 = 0x20010099;
    if (iVar1 != 2) goto LAB_003a7750;
LAB_003a78f8:
    puVar13[1] = 0;
    if (*(char *)(param_1 + 0x5e) != '\0') {
      lVar8 = (lVar8 + *(long *)(param_1 + 0x88)) - *(long *)(param_1 + 0x78);
      goto LAB_003a7768;
    }
  }
  else {
    lVar11 = *(long *)(param_5 + 0x10);
    if (*(int *)(param_5 + 0x34) == 2) {
      *puVar7 = 0x20010098;
      puVar7[1] = 0;
      if (*(char *)(param_1 + 0x5e) == '\0') goto LAB_003a78c9;
      uVar14 = 0;
      lVar11 = (lVar11 + *(long *)(param_1 + 0x88)) - *(long *)(param_1 + 0x78);
    }
    else {
      iVar4 = *(int *)(param_5 + 0x3c);
      *puVar7 = 0x20010098;
      if (iVar4 == 0) {
        puVar7[1] = 1;
      }
      else {
        puVar7[1] = 2;
      }
LAB_003a78c9:
      uVar14 = 0x1000;
    }
    puVar7[2] = 0x20020100;
    puVar7[3] = (int)((ulong)lVar11 >> 0x20);
    puVar13 = puVar7 + 5;
    puVar7[4] = (int)lVar11;
    *puVar13 = 0x20010099;
    if (iVar1 == 2) goto LAB_003a78f8;
LAB_003a7750:
    if (iVar2 == 0) {
      puVar13[1] = 1;
    }
    else {
      puVar13[1] = 2;
    }
  }
  uVar14 = uVar14 | 0x2000;
LAB_003a7768:
  puVar13[2] = 0x20020102;
  puVar13[3] = (int)((ulong)lVar8 >> 0x20);
  puVar7 = puVar13 + 7;
  puVar13[4] = (int)lVar8;
  puVar13[5] = 0x20010106;
  puVar13[6] = *(undefined4 *)(param_5 + 0x18);
  if (param_4 == '\0') {
    cVar5 = *param_5;
    uVar10 = 0;
    uVar12 = 0;
  }
  else {
    if (*(long *)(param_5 + 0x28) != 0) {
      nvAssertFailedNoLog("pChannelPbInfo->clientSemaAddr == 0",
                          "src/kernel/gpu/mem_mgr/channel_utils.c",0x343);
    }
    puVar13[7] = 0x20030090;
    puVar13[8] = (int)((ulong)*(uint *)(param_1 + 0x50) + *(long *)(param_1 + 0xb8) >> 0x20);
    uVar10 = 8;
    puVar13[9] = *(int *)(param_1 + 0x50) + *(int *)(param_1 + 0xb8);
    puVar7 = puVar13 + 0xb;
    puVar13[10] = *(undefined4 *)(param_5 + 0x20);
    cVar5 = *param_5;
    uVar12 = 4;
  }
  if (cVar5 == '\0') {
    uVar3 = *(uint *)(param_1 + 0x11c);
    if (uVar3 == 0xc1b5) {
      uVar9 = 0x400;
    }
    else if (uVar3 < 0xc1b6) {
      uVar9 = (-(uint)((uVar3 - 0xb0b5 & 0xffffefff) == 0) & 0xfc000000) + 0x4000400;
    }
    else {
      uVar9 = 0x4000400;
      if (uVar3 == 0xc3b5) {
        uVar9 = 0x400;
      }
    }
    uVar6 = uVar6 | uVar9;
  }
  *puVar7 = 0x200100c0;
  puVar7[1] = uVar6 | uVar14 | uVar12 | uVar10 | 2 - (param_3 != '\0') | 0x180;
  lVar8 = (ulong)*(uint *)(param_1 + 0x4c) + *(long *)(param_1 + 0xb8);
  puVar7[2] = 0x20040004;
  puVar7[3] = (int)((ulong)lVar8 >> 0x20);
  puVar7[4] = (int)lVar8;
  puVar7[5] = param_2;
  puVar7[6] = 0x1100002;
  uVar6 = ((int)puVar7 + 0x1c) - (int)puVar15;
  if (*(uint *)(param_1 + 0x48) < uVar6) {
    nvAssertFailedNoLog("methodSize <= pChannel->methodSizePerBlock",
                        "src/kernel/gpu/mem_mgr/channel_utils.c",0x354);
    uVar6 = 0;
  }
  return uVar6;
}


// ===== 003a7b80 channelFillSec2Pb =====

undefined8
channelFillSec2Pb(long param_1,uint param_2,char param_3,long param_4,long param_5,long param_6,
                 long param_7,long param_8,int param_9,long param_10,int param_11,uint *param_12)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  undefined4 *puVar7;
  long lVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  undefined8 uVar13;
  uint *puVar14;
  uint uVar15;
  ulong uVar16;
  uint *puVar17;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("(pChannel != NULL)","src/kernel/gpu/mem_mgr/channel_utils.c",0x387);
  }
  else if (param_4 == 0) {
    nvAssertFailedNoLog("(pChannelPbInfo != NULL)","src/kernel/gpu/mem_mgr/channel_utils.c",0x388);
  }
  else if (param_5 == 0) {
    nvAssertFailedNoLog("(pCcslCtx != NULL)","src/kernel/gpu/mem_mgr/channel_utils.c",0x389);
  }
  else if (param_6 == 0) {
    nvAssertFailedNoLog("(pAuthTagBufMemDesc != NULL)","src/kernel/gpu/mem_mgr/channel_utils.c",
                        0x38a);
  }
  else if (param_7 == 0) {
    nvAssertFailedNoLog("(pSemaMemDesc != NULL)","src/kernel/gpu/mem_mgr/channel_utils.c",0x38b);
  }
  else {
    if (param_12 != (uint *)0x0) {
      lVar8 = *(long *)(param_1 + 0xe8);
      uVar16 = (ulong)(param_2 * *(int *)(param_1 + 0x48));
      uVar4 = *(undefined8 *)(*(long *)(param_1 + 0x178) + 0x1b78);
      nvDbg_Printf("src/kernel/gpu/mem_mgr/channel_utils.c",0x392,"channelFillSec2Pb",1,
                   "NVRM: PutIndex: %x, PbOffset: %x\n",param_2,uVar16);
      lVar5 = memmgrMemDescBeginTransfer_IMPL(uVar4,param_6,0x26);
      if (lVar5 == 0) {
        nvAssertFailedNoLog("(pScrubMethdAuthTagBuf != NULL)",
                            "src/kernel/gpu/mem_mgr/channel_utils.c",0x397);
      }
      else {
        lVar6 = memmgrMemDescBeginTransfer_IMPL(uVar4,param_7,0x26);
        if (lVar6 != 0) {
          puVar7 = (undefined4 *)portMemAllocNonPaged(0x80);
          if (puVar7 == (undefined4 *)0x0) {
            uVar13 = 0x51;
            nvAssertFailedNoLog("pMethods != NULL","src/kernel/gpu/mem_mgr/channel_utils.c",0x39d);
          }
          else {
            puVar14 = (uint *)(lVar8 + uVar16);
            uVar9 = param_9 * 0x20;
            portMemSet(puVar7,0,0x80);
            uVar1 = *(undefined4 *)(param_1 + 0x100);
            *puVar7 = 0;
            puVar7[1] = uVar1;
            uVar1 = *(undefined4 *)(param_4 + 0xc);
            puVar7[2] = 0x408;
            puVar7[3] = uVar1;
            uVar13 = *(undefined8 *)(param_4 + 8);
            puVar7[4] = 0x40c;
            puVar7[5] = (int)uVar13;
            uVar1 = *(undefined4 *)(param_4 + 0x18);
            puVar7[6] = 0x410;
            puVar7[7] = uVar1;
            puVar7[0xb] = uVar9 + (int)param_8;
            puVar7[8] = 0x41c;
            puVar7[10] = 0x420;
            puVar7[9] = (int)(param_8 + (ulong)uVar9 >> 0x20);
            uVar15 = *(uint *)(param_1 + 0x54);
            lVar8 = *(long *)(param_1 + 0xb8);
            puVar7[0xc] = 0x440;
            local_58 = 0;
            puVar7[0xd] = (int)((ulong)uVar15 + lVar8 >> 0x20);
            iVar2 = *(int *)(param_1 + 0x54);
            iVar3 = *(int *)(param_1 + 0xb8);
            puVar7[0xe] = 0x444;
            puVar7[0xf] = iVar2 + iVar3;
            puVar7[0x10] = 0x448;
            puVar7[0x11] = param_9;
            *(undefined8 *)(puVar7 + 0x12) = 0x4100000470;
            local_50 = 0;
            local_48 = 0;
            local_40 = 0;
            ccslSign_IMPL(param_5,0x50,puVar7,&local_58);
            portMemCopy((ulong)uVar9 + lVar5,0x20,&local_58,0x20);
            puVar17 = puVar14 + 0x14;
            puVar10 = puVar7 + 1;
            puVar11 = puVar14;
            do {
              *puVar11 = puVar10[-1] >> 2 & 0xfff | 0x20010000;
              puVar12 = puVar11 + 2;
              puVar11[1] = *puVar10;
              puVar10 = puVar10 + 2;
              puVar11 = puVar12;
            } while (puVar12 != puVar17);
            if (param_3 != '\0') {
              uVar9 = param_11 * 0x20;
              portMemSet(puVar7,0,0x80);
              *puVar7 = 0x41c;
              puVar7[3] = uVar9 + (int)param_10;
              puVar7[1] = (int)((ulong)uVar9 + param_10 >> 0x20);
              puVar7[2] = 0x420;
              uVar15 = *(uint *)(param_1 + 0x50);
              lVar8 = *(long *)(param_1 + 0xb8);
              puVar7[4] = 0x440;
              puVar7[5] = (int)((ulong)uVar15 + lVar8 >> 0x20);
              iVar2 = *(int *)(param_1 + 0x50);
              iVar3 = *(int *)(param_1 + 0xb8);
              puVar7[6] = 0x444;
              puVar7[7] = iVar2 + iVar3;
              uVar1 = *(undefined4 *)(param_4 + 0x20);
              puVar7[8] = 0x448;
              puVar7[9] = uVar1;
              *(undefined8 *)(puVar7 + 10) = 0x4100000450;
              portMemSet(&local_58,0,0x20);
              ccslSign_IMPL(param_5,0x30,puVar7,&local_58);
              portMemCopy(lVar6 + (ulong)uVar9,0x20,&local_58,0x20);
              puVar10 = puVar17;
              puVar11 = puVar7 + 1;
              do {
                *puVar10 = puVar11[-1] >> 2 & 0xfff | 0x20010000;
                puVar17 = puVar10 + 2;
                puVar10[1] = *puVar11;
                puVar10 = puVar17;
                puVar11 = puVar11 + 2;
              } while (puVar17 != puVar14 + 0x20);
            }
            lVar8 = (ulong)*(uint *)(param_1 + 0x4c) + *(long *)(param_1 + 0xb8);
            *puVar17 = 0x20040004;
            puVar17[1] = (uint)((ulong)lVar8 >> 0x20);
            puVar17[2] = (uint)lVar8;
            puVar17[3] = param_2;
            puVar17[4] = 0x1100002;
            uVar15 = ((int)puVar17 + 0x14) - (int)puVar14;
            *param_12 = 0;
            if (*(uint *)(param_1 + 0x48) < uVar15) {
              uVar13 = 0x40;
              nvAssertOkFailedNoLog
                        (0x40,"methodSize <= pChannel->methodSizePerBlock",
                         "src/kernel/gpu/mem_mgr/channel_utils.c",0x3de);
            }
            else {
              *param_12 = uVar15;
              uVar13 = 0;
            }
            memmgrMemDescEndTransfer_IMPL(uVar4,param_7,0x26);
            memmgrMemDescEndTransfer_IMPL(uVar4,param_6,0x26);
            portMemFree(puVar7);
          }
          return uVar13;
        }
        nvAssertFailedNoLog("(pSemaAuthTagBuf != NULL)","src/kernel/gpu/mem_mgr/channel_utils.c",
                            0x39a);
      }
      return 0x40;
    }
    nvAssertFailedNoLog("(pMethodLength != NULL)","src/kernel/gpu/mem_mgr/channel_utils.c",0x38c);
  }
  return 0x1f;
}


// ===== 003a8182 _ctxdmaDestroyFBMappings.cold =====

void _ctxdmaDestroyFBMappings_cold(void)

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


// ===== 003a81a0 _ctxdmaDestroyFBMappings =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _ctxdmaDestroyFBMappings(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  code *pcVar5;
  uint uVar6;
  ulong uVar7;
  long local_40 [2];
  
  uVar6 = gpumgrGetSubDeviceInstanceFromGpu(param_2);
  uVar7 = (ulong)uVar6;
  lVar1 = *(long *)(param_1 + (uVar7 + 0x28) * 8);
  if (lVar1 != 0) {
    local_40[0] = 0;
    if (*(long *)(param_1 + 0x208) == 0) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)invalidInstructionException();
      (*pcVar5)();
    }
    uVar2 = *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x208) + 0xb8) + 0x48);
    refFindCpuMapping(uVar2,lVar1,local_40);
    if (local_40[0] != 0) {
      lVar1 = *(long *)(&DAT_00001b90 + param_2);
      uVar3 = *(undefined8 *)(param_1 + (uVar7 + 0x28) * 8);
      if (*(char *)(param_2 + 0x454) == '\0') {
        osUnmapPciMemoryKernelOld(param_2,uVar3);
      }
      else {
        (**(code **)(lVar1 + 0x520))
                  (param_2,lVar1,*(undefined8 *)(param_1 + 0x210),uVar3,
                   *(undefined8 *)(param_1 + 0x180));
      }
      refRemoveMapping(uVar2,local_40[0]);
      if ((*(char *)(param_2 + 0x908) == '\0') && (*(char *)(param_2 + 0x909) == '\0')) {
        lVar4 = *(long *)(param_1 + 8 + (uVar7 + 0x38) * 8);
        if (lVar4 != 0) {
          kbusUnmapFbApertureSingle_IMPL
                    (param_2,lVar1,*(undefined8 *)(param_1 + 0x210),
                     *(undefined8 *)(param_1 + 8 + (uVar7 + 0x30) * 8),lVar4,0x20);
          *(undefined8 *)(param_1 + 8 + (uVar7 + 0x30) * 8) = 0xffffffffffffffff;
          *(undefined8 *)(param_1 + 8 + (uVar7 + 0x38) * 8) = 0;
        }
      }
    }
    *(undefined8 *)(param_1 + 0x140 + uVar7 * 8) = 0;
  }
  return;
}


// ===== 003a8312 _ctxdmaDestruct.isra.0.cold =====

void _ctxdmaDestruct_isra_0_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003a8320 _ctxdmaDestruct.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _ctxdmaDestruct_isra_0(long param_1,undefined4 param_2)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  int *piVar4;
  long lVar5;
  undefined8 uVar6;
  int iVar7;
  
  lVar1 = *(long *)(param_1 + 600);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pGpu != NULL","src/kernel/gpu/mem_mgr/context_dma.c",0x150);
    return;
  }
  if (*(char *)(param_1 + 0x13c) == '\0') {
    if (*(long *)(param_1 + 0x260) == 0) goto _ctxdmaDestruct_isra_0_cold;
    if (*(int *)(*(long *)(*(long *)(*(long *)(param_1 + 0xe8) + 0x48) + 0x18) + 0x10) !=
        *(int *)(*(long *)(*(long *)(*(long *)(param_1 + 0x260) + 0x110) + 0x48) + 0x10))
    goto LAB_003a8382;
  }
  if ((*(char *)(lVar1 + 0x908) != '\0') &&
     ((*(char *)(lVar1 + 0x4913) == '\0' || (*(char *)(lVar1 + 0x491e) != '\0')))) {
    lVar5 = gpuGetRpc(lVar1);
    if (lVar5 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mem_mgr/context_dma.c",0x15f);
    }
    else if ((*(char *)(lVar1 + 0x909) == '\0') && (*(char *)(lVar1 + 0x90a) == '\0')) {
      if (*(long *)(param_1 + 0x208) == 0) {
_ctxdmaDestruct_isra_0_cold:
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      (**(code **)(lVar5 + 0xf0))
                (lVar1,lVar5,param_2,
                 *(undefined4 *)
                  (*(long *)(*(long *)(*(long *)(param_1 + 0x208) + 0xb8) + 0x48) + 0x10),
                 *(undefined4 *)(*(long *)(*(long *)(param_1 + 0xe8) + 0x48) + 0x10),
                 *(code **)(lVar5 + 0xf0));
    }
    else {
      (**(code **)(lVar1 + 0x3b70))(lVar1 + 0x3b58);
    }
  }
LAB_003a8382:
  piVar4 = (int *)(param_1 + 0x238);
  iVar7 = 0;
  do {
    iVar7 = iVar7 + *piVar4;
    piVar4 = piVar4 + 1;
  } while (piVar4 != (int *)(param_1 + 600));
  if (iVar7 == 0) {
    iVar7 = *(int *)(param_1 + 0x138);
  }
  else {
    dispchnUnbindCtxFromAllChannels_IMPL(lVar1,param_1);
    iVar7 = *(int *)(param_1 + 0x138);
  }
  if (iVar7 == 1) {
    uVar6 = gpumgrGetParentGPU(lVar1);
    uVar3 = gpumgrGetSubDeviceInstanceFromGpu(uVar6);
    lVar5 = *(long *)(param_1 + ((ulong)uVar3 + 0x28) * 8);
    if (lVar5 != 0) {
      memdescUnmapOld(*(undefined8 *)(*(long *)(param_1 + 0x208) + 0x118),1,lVar5,
                      *(undefined8 *)(param_1 + 0x180));
      *(undefined8 *)(param_1 + ((ulong)uVar3 + 0x28) * 8) = 0;
      *(undefined8 *)(param_1 + 0x180) = 0;
    }
  }
  _ctxdmaDestroyFBMappings(param_1,lVar1);
  memdescFree(*(undefined8 *)(param_1 + 0x210));
  memdescDestroy(*(undefined8 *)(param_1 + 0x210));
  *(undefined8 *)(param_1 + 0x210) = 0;
  return;
}


// ===== 003a858a ctxdmaConstruct_IMPL.cold =====

void ctxdmaConstruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003a85a0 ctxdmaConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int ctxdmaConstruct_IMPL(long param_1,long param_2,long param_3)

{
  long lVar1;
  int *piVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  code *pcVar6;
  char cVar7;
  undefined1 uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined8 *puVar14;
  undefined8 *puVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  long lVar18;
  undefined8 uVar19;
  ulong uVar20;
  undefined8 uVar21;
  long lVar22;
  long local_a0;
  long local_98;
  undefined8 local_90;
  long local_88;
  undefined1 local_80 [80];
  
  piVar2 = *(int **)(param_3 + 0x40);
  lVar3 = *(long *)(param_2 + 8);
  uVar4 = *(ulong *)(piVar2 + 4);
  iVar10 = *piVar2;
  uVar12 = piVar2[1];
  uVar20 = *(ulong *)(piVar2 + 6);
  iVar9 = clientGetResourceRef_IMPL(lVar3,piVar2[2],&local_a0);
  if (iVar9 != 0) {
    return iVar9;
  }
  iVar9 = 0;
  if (*(long *)(local_a0 + 0x18) != 0) {
    iVar9 = *(int *)(*(long *)(local_a0 + 0x18) + 0x10);
  }
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)invalidInstructionException();
    (*pcVar6)();
  }
  if (*(int *)(*(long *)(*(long *)(*(long *)(param_1 + 0xe8) + 0x48) + 0x18) + 0x10) != iVar9) {
    return 0x36;
  }
  if ((uVar12 & 3) == 1) {
    uVar8 = 1;
  }
  else {
    if ((uVar12 & 1) != 0) {
      return 0x29;
    }
    uVar8 = 0;
  }
  *(undefined1 *)(param_1 + 0x120) = uVar8;
  *(uint *)(param_1 + 0x11c) = uVar12;
  *(ulong *)(param_1 + 0x130) = uVar20;
  *(undefined8 *)(param_1 + 0x140) = 0;
  *(uint *)(param_1 + 0x124) = uVar12 >> 0x1c & 1 ^ 1;
  *(undefined8 *)(param_1 + 0x148) = 0;
  *(undefined8 *)(param_1 + 0x150) = 0;
  *(undefined8 *)(param_1 + 0x158) = 0;
  *(undefined8 *)(param_1 + 0x160) = 0;
  *(undefined8 *)(param_1 + 0x168) = 0;
  *(undefined8 *)(param_1 + 0x170) = 0;
  *(undefined8 *)(param_1 + 0x178) = 0;
  *(undefined8 *)(param_1 + 0x180) = 0;
  *(uint *)(param_1 + 0x128) = uVar12 >> 0x14 & 1;
  puVar14 = (undefined8 *)(param_1 + 0x188);
  do {
    *puVar14 = 0xffffffffffffffff;
    puVar15 = puVar14 + 1;
    puVar14[8] = 0;
    puVar14 = puVar15;
  } while ((undefined8 *)(param_1 + 0x1c8) != puVar15);
  puVar16 = (undefined4 *)(param_1 + 0x218);
  do {
    *puVar16 = 0;
    puVar17 = puVar16 + 1;
    puVar16[8] = 0;
    puVar16 = puVar17;
  } while (puVar17 != (undefined4 *)(param_1 + 0x238));
  *(undefined8 *)(param_1 + 0x210) = 0;
  *(undefined4 *)(param_1 + 0x138) = 0;
  if ((uVar12 & 0x20000000) == 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/context_dma.c",0xe7,"ctxdmaConstruct_IMPL",4,
                 "NVRM: HASH_TABLE=ENABLE no longer supported!\n");
    return 0x29;
  }
  uVar13 = *(undefined4 *)(lVar3 + 0x48);
  local_98 = 0;
  local_90 = 0;
  lVar18 = __nvoc_dynamicCast(*(undefined8 *)(local_a0 + 8),__nvoc_class_def_Memory);
  if (lVar18 == 0) {
    return 0x31;
  }
  if (iVar10 == 0) {
    *(undefined1 *)(param_1 + 0x13c) = 0;
    local_98 = *(long *)(lVar18 + 0xf0);
    if (local_98 == 0) {
      return 0x36;
    }
    local_90 = *(undefined8 *)(lVar18 + 0xe0);
  }
  else {
    *(undefined1 *)(param_1 + 0x13c) = 1;
    iVar10 = gpuGetByHandle(lVar3,iVar10,0,&local_98);
    if (iVar10 != 0) {
      return iVar10;
    }
    iVar10 = deviceGetByGpu_IMPL(lVar3,local_98,1,&local_90);
    if (iVar10 != 0) {
      return 0x36;
    }
  }
  *(undefined8 *)(param_1 + 0x260) = local_90;
  cVar7 = gpuIsGpuFullPower_IMPL(local_98);
  if (((cVar7 == '\0') && (*(char *)(local_98 + 0x444) == '\0')) ||
     (cVar7 = gpuCheckSysmemAccess_IMPL(), cVar7 == '\0')) {
    return 0x11;
  }
  if ((CARRY8(uVar4,uVar20)) || (*(ulong *)(lVar18 + 0x100) <= uVar4 + uVar20)) {
    return 0x2e;
  }
  uVar21 = *(undefined8 *)(lVar18 + 0x118);
  *(long *)(param_1 + 0x208) = lVar18;
  *(long *)(param_1 + 600) = local_98;
  uVar19 = memdescGetMemDescFromGpu(uVar21);
  iVar10 = memdescGetAddressSpace(uVar19);
  *(int *)(param_1 + 0x138) = iVar10;
  if (iVar10 == 4) {
    return 0x58;
  }
  iVar10 = memdescCreateSubMem(param_1 + 0x210,uVar21,local_98,uVar4,uVar20 + 1);
  if (iVar10 != 0) {
LAB_003a8a4d:
    memdescDestroy(*(undefined8 *)(param_1 + 0x210));
    *(undefined8 *)(param_1 + 0x210) = 0;
    if (*(int *)(param_1 + 0x138) == 2) {
      _ctxdmaDestroyFBMappings(param_1,local_98);
    }
    _ctxdmaDestruct_isra_0(param_1,uVar13);
    return iVar10;
  }
  if (*(int *)(param_1 + 0x138) == 1) {
    if (*(int *)(param_1 + 0x128) != 1) goto LAB_003a88f8;
    uVar19 = gpumgrGetParentGPU(local_98);
    uVar11 = gpumgrGetSubDeviceInstanceFromGpu(uVar19);
    iVar10 = memdescMapOld(uVar21,uVar4,uVar20 + 1,1,3,param_1 + 0x140 + (ulong)uVar11 * 8,
                           param_1 + 0x180);
    if (iVar10 != 0) goto LAB_003a8a4d;
  }
  if (((uVar12 & 0xf00000) == 0x100000) && (*(int *)(param_1 + 0x138) == 2)) {
    lVar5 = *(long *)(&DAT_00001b90 + local_98);
    uVar12 = gpumgrGetSubDeviceInstanceFromGpu();
    uVar20 = (ulong)uVar12;
    lVar3 = *(long *)(param_1 + 0x130) + 1;
    lVar1 = param_1 + uVar20 * 8;
    *(long *)(lVar1 + 0x1c8) = lVar3;
    if ((*(char *)(local_98 + 0x908) == '\0') || (*(char *)(local_98 + 0x4913) != '\0')) {
      if (*(char *)(local_98 + 0x454) == '\0') {
        lVar3 = uVar20 * 8 + 0x1c8;
        iVar10 = kbusMapFbApertureSingle_IMPL
                           (local_98,lVar5,uVar21,uVar4,param_1 + -0x40 + lVar3,param_1 + lVar3,0x20
                           );
        if (iVar10 != 0) {
          *(undefined8 *)(lVar1 + 0x1c8) = 0;
          goto LAB_003a8a4d;
        }
        uVar21 = memdescGetPageSize(uVar21,1);
        memdescSetPageSize(*(undefined8 *)(param_1 + 0x210),1,uVar21);
        lVar5 = *(long *)(param_1 + 0x130);
        lVar22 = gpumgrGetGpuPhysFbAddr(local_98);
        iVar10 = osMapPciMemoryKernelOld
                           (local_98,lVar22 + *(long *)(lVar1 + 0x188),lVar5 + 1,3,
                            param_1 + -0x88 + lVar3,2);
      }
      else {
        iVar10 = (**(code **)(lVar5 + 0x518))
                           (local_98,lVar5,*(undefined8 *)(param_1 + 0x210),0,lVar3,3,
                            param_1 + 0x140 + uVar20 * 8,param_1 + 0x180);
      }
      if (iVar10 != 0) goto LAB_003a8a4d;
    }
    else {
      *(long *)(lVar1 + 0x188) = *(long *)(lVar1 + 0x188) - *(long *)(local_98 + 0x850);
    }
    lVar3 = *(long *)(*(long *)(lVar18 + 0xb8) + 0x48);
    local_88 = 0;
    portMemSet(local_80,0,0x48);
    refAddMapping(lVar3,local_80,*(undefined8 *)(lVar3 + 0x18),&local_88);
    lVar22 = local_88;
    lVar3 = *(long *)(lVar1 + 0x1c8);
    lVar18 = *(long *)(param_1 + 0x130);
    lVar5 = *(long *)(lVar1 + 0x188);
    uVar21 = *(undefined8 *)(lVar1 + 0x140);
    *(undefined1 *)(*(long *)(local_88 + 0x50) + 0x24) = 1;
    *(undefined4 *)(local_88 + 0x10) = 0;
    *(long *)(local_88 + 8) = lVar18 + 1;
    uVar13 = osGetCurrentProcess();
    *(undefined8 *)(lVar22 + 0x18) = uVar21;
    *(undefined4 *)(lVar22 + 0x48) = uVar13;
    *(undefined8 *)(*(long *)(lVar22 + 0x50) + 0x18) = 0;
    if ((lVar3 == 0) || (lVar5 == 0)) {
      portMemSet(*(long *)(lVar22 + 0x50),0,0x10);
    }
    else {
      *(undefined8 *)(*(long *)(lVar22 + 0x50) + 8) = 1;
      **(long **)(lVar22 + 0x50) = (long)(*(long **)(lVar22 + 0x50) + 5);
      *(long *)(*(long *)(lVar22 + 0x50) + 0x28) = lVar5;
      *(long *)(*(long *)(lVar22 + 0x50) + 0x30) = lVar3;
    }
    *(long *)(*(long *)(local_88 + 0x50) + 0x10) = local_98;
  }
LAB_003a88f8:
  refAddDependant(local_a0,*(undefined8 *)(*(long *)(param_1 + 0xe8) + 0x48));
  return 0;
}


// ===== 003a8d8f ctxdmaDestruct_IMPL.cold =====

void ctxdmaDestruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003a8da0 ctxdmaDestruct_IMPL =====

void ctxdmaDestruct_IMPL(long param_1)

{
  code *pcVar1;
  
  if (param_1 != 0) {
    _ctxdmaDestruct_isra_0
              (param_1,*(undefined4 *)(**(long **)(*(long *)(param_1 + 0xe8) + 0x48) + 0x48));
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003a8dc3 ctxdmaCtrlCmdUpdateContextdma_IMPL.cold =====

void ctxdmaCtrlCmdUpdateContextdma_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003a8dd0 ctxdmaCtrlCmdUpdateContextdma_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong ctxdmaCtrlCmdUpdateContextdma_IMPL(long param_1,long param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  long lVar4;
  code *pcVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  undefined8 uStack_30;
  long local_10;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)invalidInstructionException();
    (*pcVar5)();
  }
  puVar3 = *(undefined8 **)(*(long *)(param_1 + 0xe8) + 0x48);
  if ((*(int *)(param_2 + 0x14) != 0) && (*(int *)(param_2 + 0x14) != *(int *)(puVar3 + 2))) {
    nvAssertFailedNoLog("pUpdateCtxDmaParams->hCtxDma == RES_GET_HANDLE(pContextDma)",
                        "src/kernel/gpu/mem_mgr/context_dma.c",0x116);
    return 0x31;
  }
  if (*(int *)(param_2 + 0x10) == 0) {
    lVar7 = *(long *)(param_1 + 600);
  }
  else {
    uStack_30 = 0x3a8eac;
    uVar6 = subdeviceGetByHandle_IMPL(*puVar3,*(int *)(param_2 + 0x10),&local_10);
    if ((int)uVar6 != 0) {
      return uVar6;
    }
    if (*(long *)(local_10 + 0x338) != *(long *)(param_1 + 0x260)) {
      nvCheckFailedNoLog(4,"pSubdevice->pDevice == pContextDma->pDevice",
                         "src/kernel/gpu/mem_mgr/context_dma.c",0x120);
      return 0x33;
    }
    lVar7 = *(long *)(*(long *)(local_10 + 0x158) + 0xe0);
  }
  if (*(long *)(lVar7 + 0x1b80) == 0) {
    return 0xffff;
  }
  uVar1 = *(uint *)(param_2 + 0x20);
  lVar9 = 0;
  if ((uVar1 & 1) != 0) {
    lVar9 = param_2;
  }
  lVar8 = param_2 + 8;
  if ((uVar1 & 2) == 0) {
    lVar8 = 0;
  }
  uVar2 = 0;
  if ((uVar1 & 4) != 0) {
    uVar2 = *(undefined4 *)(param_2 + 0x1c);
  }
  lVar4 = *(long *)(*(long *)(lVar7 + 0x1b80) + 0x280);
  uVar6 = (**(code **)(lVar4 + 0x78))(lVar7,lVar4,param_1,lVar9,lVar8,uVar2,uVar1 >> 5 & 3);
  if ((int)uVar6 == 0) {
    return uVar6;
  }
  nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/context_dma.c",0x13e,uStack_30);
  return uVar6 & 0xffffffff;
}


// ===== 003a8f40 ctxdmaCtrlCmdBindContextdma_IMPL =====

undefined8 ctxdmaCtrlCmdBindContextdma_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  char cVar2;
  undefined8 uVar3;
  undefined1 local_20 [8];
  
  uVar1 = *param_2;
  cVar2 = osIsRaisedIRQL();
  if ((cVar2 == '\0') &&
     (uVar3 = serverutilGetResourceRefWithType
                        (*(undefined4 *)(**(long **)(*(long *)(param_1 + 0xe8) + 0x48) + 0x48),uVar1
                         ,0x5d8d70,local_20), (int)uVar3 == 0)) {
    return uVar3;
  }
  cVar2 = gpuIsGpuFullPower_IMPL(*(undefined8 *)(param_1 + 600));
  if (((cVar2 != '\0') || (*(char *)(*(long *)(param_1 + 600) + 0x444) != '\0')) &&
     (cVar2 = gpuCheckSysmemAccess_IMPL(), cVar2 != '\0')) {
    uVar3 = dispchnBindCtx_IMPL(*(undefined8 *)(param_1 + 600),param_1,uVar1);
    return uVar3;
  }
  return 0x11;
}


// ===== 003a8fe0 ctxdmaCtrlCmdUnbindContextdma_IMPL =====

undefined8 ctxdmaCtrlCmdUnbindContextdma_IMPL(long param_1,undefined4 *param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = gpuIsGpuFullPower_IMPL(*(undefined8 *)(param_1 + 600));
  if ((cVar1 != '\0') || (*(char *)(*(long *)(param_1 + 600) + 0x444) != '\0')) {
    cVar1 = gpuCheckSysmemAccess_IMPL();
    if (cVar1 != '\0') {
      uVar2 = dispchnUnbindCtx_IMPL(*(undefined8 *)(param_1 + 600),param_1,*param_2);
      return uVar2;
    }
  }
  return 0x11;
}


// ===== 003a9050 ctxdmaGetByHandle_IMPL =====

int ctxdmaGetByHandle_IMPL(undefined8 param_1,undefined8 param_2,long *param_3)

{
  int iVar1;
  long lVar2;
  long local_20;
  
  *param_3 = 0;
  iVar1 = clientGetResourceRef_IMPL(param_1,param_2,&local_20);
  if (iVar1 == 0) {
    lVar2 = __nvoc_dynamicCast(*(undefined8 *)(local_20 + 8),__nvoc_class_def_ContextDma);
    *param_3 = lVar2;
    if (lVar2 == 0) {
      iVar1 = 0x33;
    }
  }
  return iVar1;
}


// ===== 003a90b0 ctxdmaGetKernelVA_IMPL =====

undefined8 ctxdmaGetKernelVA_IMPL(long param_1,long param_2,long param_3,long *param_4,uint param_5)

{
  long lVar1;
  
  if (param_1 == 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/context_dma.c",0x2ff,"ctxdmaGetKernelVA_IMPL",4,
                 "NVRM: Invalid DMA context in ctxdmaGetKernelVA\n");
    return 0x44;
  }
  if ((ulong)(param_2 + -1 + param_3) <= *(ulong *)(param_1 + 0x130)) {
    lVar1 = *(long *)(param_1 + 0x140 + (ulong)param_5 * 8);
    if (lVar1 != 0) {
      *param_4 = lVar1 + param_2;
      return 0;
    }
    return 8;
  }
  return 0x37;
}


// ===== 003a9140 ctxdmaMapTo_IMPL =====

undefined8 ctxdmaMapTo_IMPL(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  
  uVar1 = param_2[2];
  uVar6 = *param_2;
  uVar2 = param_2[7];
  uVar5 = memdescGetMemDescFromGpu(uVar1,uVar6);
  iVar4 = memdescGetAddressSpace(uVar5);
  if (iVar4 == 2) {
    uVar6 = memdescGetMemDescFromGpu(*(undefined8 *)(param_1 + 0x210),uVar6);
    iVar4 = memdescGetAddressSpace(uVar6);
    if (iVar4 == 2) {
      cVar3 = memdescGetContiguity(uVar1,1);
      if (cVar3 != '\0') {
        lVar7 = memdescGetPhysAddr(uVar1,1,uVar2);
        lVar8 = memdescGetPhysAddr(*(undefined8 *)(param_1 + 0x210),1,0);
        *(long *)param_2[0xb] = lVar7 - lVar8;
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/mem_mgr/context_dma.c",0x327,"ctxdmaMapTo_IMPL",4,
                   "NVRM: Cannot obtain the video memory offset of a noncontiguous vidmem alloc!\n")
      ;
      return 0xffff;
    }
  }
  return 0x1f;
}


// ===== 003a9230 ctxdmaUnmapFrom_IMPL =====

undefined8 ctxdmaUnmapFrom_IMPL(void)

{
  return 0;
}


// ===== 003a9240 dmaAllocMap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong dmaAllocMap_IMPL(long param_1,long param_2,undefined8 param_3,long param_4,undefined8 param_5,
                      ulong *param_6)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 *puVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  ulong uVar8;
  uint uVar9;
  ulong local_80;
  ulong local_78;
  long local_70;
  undefined8 local_68;
  long local_60 [2];
  ulong *local_50;
  long local_48;
  undefined8 local_40;
  
  lVar2 = *(long *)(param_1 + 0x1bc0);
  if (param_4 == 0) {
    nvAssertFailedNoLog("pVirtualMemory != NULL","src/kernel/gpu/mem_mgr/dma.c",0x62);
  }
  iVar5 = memdescGetAddressSpace(param_6[0x1a]);
  if (iVar5 != 7) {
    memdescGetAddressSpace(param_6[0x1a]);
  }
  uVar1 = *(undefined4 *)((long)param_6 + 0xdc);
  uVar9 = (uint)param_6[0x1b];
  if (*(char *)(param_4 + 0x265) == '\0') {
    virtmemGetAddressAndSize_IMPL(param_4,&local_78,&local_70);
    local_80 = *param_6;
    if ((*(byte *)((long)param_6 + 0xd9) & 0x80) == 0) {
      local_80 = local_80 + local_78;
    }
    if ((uVar9 & 0x20000000) == 0) goto LAB_003a9302;
  }
  else {
    uVar9 = uVar9 | 0x20000000;
    virtmemGetAddressAndSize_IMPL(param_4,&local_78,&local_70);
    local_80 = *param_6;
    if ((*(byte *)((long)param_6 + 0xd9) & 0x80) == 0) {
      local_80 = local_80 + local_78;
    }
  }
  if (local_80 < local_78) {
    nvAssertFailedNoLog("vaddr >= baseVirtAddr","src/kernel/gpu/mem_mgr/dma.c",0x9d);
  }
  else {
    if (local_80 < local_78 + local_70) {
LAB_003a9302:
      local_50 = param_6;
      local_48 = param_4;
      local_40 = param_5;
      if ((lVar2 == 0) ||
         (cVar4 = kmigmgrIsMIGMemPartitioningEnabled_IMPL(param_1,lVar2), cVar4 == '\0')) {
        uVar6 = 0xffffffff;
      }
      else {
        puVar3 = *(undefined8 **)(*(long *)(param_4 + 0x230) + 0x48);
        uVar7 = deviceGetByHandle_IMPL(*puVar3,*(undefined4 *)(puVar3[3] + 0x10),&local_68);
        if (uVar7 != 0) {
          nvAssertOkFailedNoLog
                    (uVar7,"deviceGetByHandle(pClient, hDevice, &pDevice)",
                     "src/kernel/gpu/mem_mgr/dma.c",0xac);
          return (ulong)uVar7;
        }
        uVar7 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,lVar2,local_68,local_60);
        if (uVar7 != 0) {
          nvAssertOkFailedNoLog
                    (uVar7,"kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)"
                     ,"src/kernel/gpu/mem_mgr/dma.c",0xae);
          return (ulong)uVar7;
        }
        uVar6 = *(undefined4 *)(local_60[0] + 0x968);
      }
      uVar8 = (**(code **)(param_2 + 0x168))
                        (param_1,param_2,param_3,param_6[0x1a],&local_80,uVar9,uVar1,&local_50,uVar6
                        );
      if ((int)uVar8 == 0) {
        *param_6 = local_80;
      }
      return uVar8;
    }
    nvAssertFailedNoLog("vaddr < (baseVirtAddr + virtSize)","src/kernel/gpu/mem_mgr/dma.c",0x9e);
  }
  return 0x37;
}


// ===== 003a9520 dmaFreeMap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void dmaFreeMap_IMPL(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x170))();
  return;
}


// ===== 003a9560 deviceCtrlCmdDmaGetPteInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int deviceCtrlCmdDmaGetPteInfo_IMPL(long param_1,long param_2)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long *local_30;
  
  local_30 = (long *)0x0;
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar5 = resservGetTlsCallContext();
  lVar5 = *(long *)(*(long *)(lVar5 + 0x48) + 0x70);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 != '\0') {
    cVar2 = rmGpuLockIsOwner();
    if (cVar2 != '\0') {
      iVar3 = vaspaceGetByHandleOrDeviceDefault_IMPL
                        (**(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48),
                         *(undefined4 *)(lVar5 + 4),*(undefined4 *)(param_2 + 0xb0),&local_30);
      if (iVar3 == 0) {
        iVar4 = (**(code **)(*local_30 + 0xf0))(local_30,uVar1,param_2,0);
        iVar3 = 0;
        if (iVar4 != 0) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/dma.c",0x120,"deviceCtrlCmdDmaGetPteInfo_IMPL",4,
                       "NVRM: vaspaceGetPteInfo failed\n");
          return iVar4;
        }
      }
      else {
        nvCheckOkFailedNoLog
                  (3,iVar3,
                   "vaspaceGetByHandleOrDeviceDefault(RES_GET_CLIENT(pDevice), pRmCtrlParams->hObject, pParams->hVASpace, &pVAS)"
                   ,"src/kernel/gpu/mem_mgr/dma.c",0x119);
      }
      return iVar3;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()","src/kernel/gpu/mem_mgr/dma.c",
                      0x117);
  return 0x2f;
}


// ===== 003a96a0 deviceCtrlCmdDmaUpdatePde2_IMPL =====

ulong deviceCtrlCmdDmaUpdatePde2_IMPL(long param_1,long param_2)

{
  undefined8 *puVar1;
  char cVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  undefined8 local_30;
  
  local_30 = 0;
  lVar6 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar4 = resservGetTlsCallContext();
  cVar2 = rmapiLockIsOwner();
  if (cVar2 != '\0') {
    cVar2 = rmGpuLockIsOwner();
    if (cVar2 != '\0') {
      if (*(uint *)(lVar4 + 0x28) < 2) {
        uVar5 = 0x1b;
      }
      else if ((*(char *)(lVar6 + 0x908) == '\0') || (uVar5 = 0, *(char *)(lVar6 + 0x4913) != '\0'))
      {
        puVar1 = *(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48);
        uVar3 = vaspaceGetByHandleOrDeviceDefault_IMPL
                          (*puVar1,*(undefined4 *)(puVar1 + 2),*(undefined4 *)(param_2 + 0x28),
                           &local_30);
        if (uVar3 == 0) {
          if (*(int *)(param_2 + 0x38) != 0) {
            lVar6 = gpumgrGetGpuFromSubDeviceInst
                              (*(undefined4 *)(lVar6 + 0x7b4),*(int *)(param_2 + 0x38) + -1);
          }
          lVar4 = __nvoc_dynamicCast(local_30,__nvoc_class_def_OBJGVASPACE);
          uVar5 = 0x56;
          if (lVar4 != 0) {
            uVar5 = gvaspaceUpdatePde2_IMPL(lVar4,lVar6,param_2);
          }
        }
        else {
          nvCheckOkFailedNoLog
                    (3,uVar3,
                     "vaspaceGetByHandleOrDeviceDefault(RES_GET_CLIENT(pDevice), RES_GET_HANDLE(pDevice), pParams->hVASpace, &pVAS)"
                     ,"src/kernel/gpu/mem_mgr/dma.c",0x146);
          uVar5 = (ulong)uVar3;
        }
      }
      return uVar5;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()","src/kernel/gpu/mem_mgr/dma.c",
                      0x139);
  return 0x2f;
}


// ===== 003a9800 deviceCtrlCmdDmaSetVASpaceSize_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong deviceCtrlCmdDmaSetVASpaceSize_IMPL(long param_1,long param_2)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  uint uVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 extraout_RDX;
  undefined1 auVar10 [16];
  undefined8 local_30 [2];
  
  local_30[0] = 0;
  lVar6 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar4 = rmapiLockIsOwner();
  if ((cVar4 == '\0') || (cVar4 = rmGpuLockIsOwner(), cVar4 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()","src/kernel/gpu/mem_mgr/dma.c",
                        0x17d);
    return 0x2f;
  }
  puVar2 = *(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48);
  uVar5 = vaspaceGetByHandleOrDeviceDefault_IMPL
                    (*puVar2,*(undefined4 *)(puVar2 + 2),*(undefined4 *)(param_2 + 8),local_30);
  if (uVar5 != 0) {
    nvCheckOkFailedNoLog
              (3,uVar5,
               "vaspaceGetByHandleOrDeviceDefault(RES_GET_CLIENT(pDevice), RES_GET_HANDLE(pDevice), pParams->hVASpace, &pVAS)"
               ,"src/kernel/gpu/mem_mgr/dma.c",0x17f);
    return (ulong)uVar5;
  }
  uVar9 = extraout_RDX;
  if ((*(char *)(lVar6 + 0x908) != '\0') && (*(char *)(lVar6 + 0x4913) == '\0')) {
    lVar8 = resservGetTlsCallContext();
    puVar3 = *(undefined4 **)(*(long *)(lVar8 + 0x48) + 0x70);
    lVar8 = gpuGetRpc(lVar6);
    if (lVar8 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mem_mgr/dma.c",400);
      return 0x1a;
    }
    uVar1 = puVar3[6];
    if ((*(char *)(lVar6 + 0x909) == '\0') && (*(char *)(lVar6 + 0x90a) == '\0')) {
      uVar9 = rpcDmaControl_wrapper
                        (lVar6,lVar8,*puVar3,puVar3[1],puVar3[2],*(undefined8 *)(puVar3 + 4));
      auVar10._8_4_ = uVar1;
      auVar10._0_8_ = uVar9;
      auVar10._12_4_ = 0;
    }
    else {
      auVar10 = (**(code **)(lVar6 + 0x3b90))(lVar6 + 0x3b58);
    }
    uVar9 = auVar10._8_8_;
    if (auVar10._0_4_ != 0) {
      return auVar10._0_8_;
    }
  }
  lVar6 = __nvoc_dynamicCast(local_30[0],__nvoc_class_def_OBJGVASPACE,uVar9);
  if (lVar6 == 0) {
    nvAssertFailedNoLog("pGVAS != NULL","src/kernel/gpu/mem_mgr/dma.c",0x19e);
    uVar7 = 0x56;
  }
  else {
    uVar7 = gvaspaceResize_IMPL(lVar6,param_2);
    if ((int)uVar7 != 0) {
      nvAssertOkFailedNoLog
                (uVar7 & 0xffffffff,"gvaspaceResize(pGVAS, pParams)","src/kernel/gpu/mem_mgr/dma.c",
                 0x19f);
      uVar7 = uVar7 & 0xffffffff;
    }
  }
  return uVar7;
}


// ===== 003a9a0f deviceCtrlCmdDmaSetPageDirectory_IMPL.cold =====

void deviceCtrlCmdDmaSetPageDirectory_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003a9a20 deviceCtrlCmdDmaSetPageDirectory_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong deviceCtrlCmdDmaSetPageDirectory_IMPL(long param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long *plVar3;
  code *pcVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  undefined8 uVar11;
  ulong uVar12;
  long *local_48;
  undefined8 local_40 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  plVar3 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
  uVar1 = (undefined4)plVar3[2];
  uVar2 = *(undefined4 *)(*plVar3 + 0x48);
  lVar10 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar5 = rmapiLockIsOwner();
  if ((cVar5 == '\0') || (cVar5 = rmGpuLockIsOwner(), cVar5 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()","src/kernel/gpu/mem_mgr/dma.c",
                        0x1b9);
    return 0x2f;
  }
  if ((*(char *)(lVar10 + 0x908) != '\0') && (*(char *)(lVar10 + 0x4913) == '\0')) {
    lVar8 = gpuGetRpc(lVar10);
    if (lVar8 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mem_mgr/dma.c",0x1bd);
      return 0x1a;
    }
    if ((*(char *)(lVar10 + 0x909) != '\0') || (*(char *)(lVar10 + 0x90a) != '\0')) {
      uVar12 = (**(code **)(lVar10 + 0x3b90))(lVar10 + 0x3b58,uVar2,uVar1,0x801813,param_2,0x20);
      return uVar12;
    }
LAB_003a9c7b:
    uVar6 = rpcDmaControl_wrapper(lVar10,lVar8,uVar2,uVar1,0x801813,param_2,0x20);
    return (ulong)uVar6;
  }
  uVar6 = vaspaceGetByHandleOrDeviceDefault_IMPL
                    (**(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48),uVar1,
                     *(undefined4 *)(param_2 + 2),&local_48);
  if (uVar6 != 0) {
    nvCheckOkFailedNoLog
              (3,uVar6,
               "vaspaceGetByHandleOrDeviceDefault(RES_GET_CLIENT(pDevice), hDevice, pParams->hVASpace, &pVAS)"
               ,"src/kernel/gpu/mem_mgr/dma.c",0x1c7);
    return (ulong)uVar6;
  }
  lVar8 = __nvoc_dynamicCast(local_48,__nvoc_class_def_OBJGVASPACE);
  if (lVar8 == 0) {
    nvCheckFailedNoLog(1,"pGVAS != NULL","src/kernel/gpu/mem_mgr/dma.c",0x1cc);
    return 0x56;
  }
  if ((*(char *)(*(long *)(lVar10 + 0x4d8) + 0x80) != '\0') && (*(char *)(lVar10 + 0x909) != '\0'))
  {
    uVar6 = gvaspaceExternalRootDirCommit_IMPL(lVar8,uVar2,lVar10,param_2);
    if (uVar6 != 0) {
      nvAssertOkFailedNoLog
                (uVar6,"gvaspaceExternalRootDirCommit(pGVAS, hClient, pGpu, pParams)",
                 "src/kernel/gpu/mem_mgr/dma.c",0x1d9);
      return (ulong)uVar6;
    }
    uVar11 = (**(code **)(*local_48 + 200))(local_48,lVar10);
    iVar7 = memdescGetAddressSpace(uVar11);
    if (iVar7 != 1) {
      nvAssertFailedNoLog("memdescGetAddressSpace(vaspaceGetPageDirBase(pVAS, pGpu)) == ADDR_SYSMEM"
                          ,"src/kernel/gpu/mem_mgr/dma.c",0x1df);
      return 0x1f;
    }
    uVar11 = (**(code **)(*local_48 + 200))(local_48,lVar10);
    uVar11 = memdescGetPhysAddr(uVar11,1,0);
    *param_2 = uVar11;
    lVar8 = gpuGetRpc(lVar10);
    if (lVar8 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mem_mgr/dma.c",0x1e4);
      return 0x1a;
    }
    if ((*(char *)(lVar10 + 0x909) != '\0') || (*(char *)(lVar10 + 0x90a) != '\0')) {
      uVar6 = (**(code **)(lVar10 + 0x3b90))(lVar10 + 0x3b58,uVar2,uVar1,0x801813,param_2,0x20);
      return (ulong)uVar6;
    }
    goto LAB_003a9c7b;
  }
  if (*(int *)(param_2 + 3) != 0) {
    lVar10 = gpumgrGetGpuFromSubDeviceInst
                       (*(undefined4 *)(lVar10 + 0x7b4),*(int *)(param_2 + 3) + -1);
  }
  if ((*(char *)(lVar10 + 0x4913) != '\0') || (*(char *)(lVar10 + 0x909) != '\0')) {
    lVar9 = gpuGetRpc(lVar10);
    if (lVar9 == 0) {
      uVar12 = 0x1a;
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mem_mgr/dma.c",0x1fe);
      goto LAB_003a9b6c;
    }
    if ((*(char *)(lVar10 + 0x909) == '\0') && (*(char *)(lVar10 + 0x90a) == '\0')) {
      uVar6 = rpcDmaControl_wrapper(lVar10,lVar9,uVar2,uVar1,0x801813,param_2,0x20);
    }
    else {
      uVar6 = (**(code **)(lVar10 + 0x3b90))(lVar10 + 0x3b58,uVar2,uVar1,0x801813,param_2,0x20);
    }
    uVar12 = (ulong)uVar6;
    if (uVar6 != 0) goto LAB_003a9b6c;
  }
  uVar6 = gvaspaceExternalRootDirCommit_IMPL(lVar8,uVar2,lVar10,param_2);
  uVar12 = (ulong)uVar6;
  if (uVar6 == 0) {
    return 0;
  }
LAB_003a9b6c:
  local_40[0] = CONCAT44(*(undefined4 *)(param_2 + 3),*(undefined4 *)(param_2 + 2));
  gvaspaceExternalRootDirRevoke_IMPL(lVar8,lVar10,local_40);
  if (((*(char *)(lVar10 + 0x909) != '\0') || (*(char *)(lVar10 + 0x4913) != '\0')) &&
     (lVar10 = gpuGetRpc(lVar10), lVar10 == 0)) {
    uVar12 = 0x1a;
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mem_mgr/dma.c",0x21f);
  }
  return uVar12;
}


// ===== 003a9f00 deviceCtrlCmdDmaUnsetPageDirectory_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong deviceCtrlCmdDmaUnsetPageDirectory_IMPL(long param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 *puVar3;
  char cVar4;
  uint uVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined1 auVar10 [16];
  undefined8 uStack_50;
  undefined8 local_30;
  
  local_30 = 0;
  lVar9 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar6 = resservGetTlsCallContext();
  puVar2 = *(undefined4 **)(*(long *)(lVar6 + 0x48) + 0x70);
  cVar4 = rmapiLockIsOwner();
  if ((cVar4 == '\0') || (cVar4 = rmGpuLockIsOwner(), cVar4 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()","src/kernel/gpu/mem_mgr/dma.c",
                        0x248);
    return 0x2f;
  }
  if ((*(char *)(lVar9 + 0x908) != '\0') && (*(char *)(lVar9 + 0x4913) == '\0')) {
    lVar6 = gpuGetRpc(lVar9);
    if (lVar6 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mem_mgr/dma.c",0x24c);
      return 0x1a;
    }
    if ((*(char *)(lVar9 + 0x909) == '\0') && (*(char *)(lVar9 + 0x90a) == '\0')) {
      uVar7 = rpcDmaControl_wrapper
                        (lVar9,lVar6,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                         puVar2[6]);
      return uVar7;
    }
    uVar7 = (**(code **)(lVar9 + 0x3b90))(lVar9 + 0x3b58);
    return uVar7;
  }
  puVar3 = *(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48);
  uVar5 = vaspaceGetByHandleOrDeviceDefault_IMPL
                    (*puVar3,*(undefined4 *)(puVar3 + 2),*param_2,&local_30);
  if (uVar5 != 0) {
    nvCheckOkFailedNoLog
              (3,uVar5,
               "vaspaceGetByHandleOrDeviceDefault(RES_GET_CLIENT(pDevice), RES_GET_HANDLE(pDevice), pParams->hVASpace, &pVAS)"
               ,"src/kernel/gpu/mem_mgr/dma.c",599);
    return (ulong)uVar5;
  }
  auVar10 = __nvoc_dynamicCast(local_30,__nvoc_class_def_OBJGVASPACE);
  uStack_50 = auVar10._8_8_;
  lVar6 = auVar10._0_8_;
  if (lVar6 == 0) {
    nvAssertFailedNoLog("pGVAS != NULL","src/kernel/gpu/mem_mgr/dma.c",0x25c);
    return 0x56;
  }
  if ((*(char *)(lVar9 + 0x909) != '\0') || (*(char *)(lVar9 + 0x4913) != '\0')) {
    uStack_50 = 0x3a9ff8;
    lVar8 = gpuGetRpc(lVar9);
    if (lVar8 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mem_mgr/dma.c",0x260);
      uStack_50 = extraout_RDX_00;
    }
    else {
      if ((*(char *)(lVar9 + 0x909) != '\0') || (*(char *)(lVar9 + 0x90a) != '\0')) {
        (**(code **)(lVar9 + 0x3b90))(lVar9 + 0x3b58);
        iVar1 = param_2[1];
        uStack_50 = extraout_RDX;
        goto joined_r0x003aa03b;
      }
      rpcDmaControl_wrapper
                (lVar9,lVar8,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),puVar2[6]);
    }
  }
  iVar1 = param_2[1];
joined_r0x003aa03b:
  if (iVar1 != 0) {
    lVar9 = gpumgrGetGpuFromSubDeviceInst(*(undefined4 *)(lVar9 + 0x7b4),iVar1 + -1,uStack_50);
  }
  gvaspaceExternalRootDirRevoke_IMPL(lVar6,lVar9,param_2);
  uVar7 = gvaspaceUnregisterAllChanGrps_IMPL(lVar6,lVar9);
  return uVar7;
}


// ===== 003aa1d0 deviceCtrlCmdDmaAdvSchedGetVaCaps_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong deviceCtrlCmdDmaAdvSchedGetVaCaps_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 *puVar2;
  char cVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  char *pcVar7;
  undefined8 uVar8;
  long *local_30;
  
  local_30 = (long *)0x0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar5 = kmemsysGetStaticConfig_IMPL(lVar1,*(undefined8 *)(lVar1 + 0x1b70));
  cVar3 = rmapiLockIsOwner();
  if ((cVar3 == '\0') && (cVar3 = rmapiInRtd3PmPath(), cVar3 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() || rmapiInRtd3PmPath()","src/kernel/gpu/mem_mgr/dma.c",
                        0x2e7);
    return 0x2f;
  }
  if (((*(char *)(lVar1 + 0x909) == '\0') || (*(int *)(param_2 + 0xa4) != 0)) ||
     (*(long *)(param_1 + 0x1a0) != 0)) {
    puVar2 = *(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48);
    uVar4 = vaspaceGetByHandleOrDeviceDefault_IMPL
                      (*puVar2,*(undefined4 *)(puVar2 + 2),*(int *)(param_2 + 0xa4),&local_30);
    if (uVar4 != 0) {
      uVar8 = 0x2f2;
      pcVar7 = 
      "vaspaceGetByHandleOrDeviceDefault(RES_GET_CLIENT(pDevice), RES_GET_HANDLE(pDevice), pParams->hVASpace, &pVAS)"
      ;
      goto LAB_003aa314;
    }
  }
  else {
    uVar8 = gpumgrGetGpuGrpFromGpu(lVar1);
    uVar4 = gpugrpGetGlobalVASpace_IMPL(uVar8,&local_30);
    uVar8 = 0x2ee;
    pcVar7 = "gpugrpGetGlobalVASpace(pGpuGrp, &pVAS)";
    if (uVar4 != 0) {
LAB_003aa314:
      nvCheckOkFailedNoLog(3,uVar4,pcVar7,"src/kernel/gpu/mem_mgr/dma.c",uVar8);
      return (ulong)uVar4;
    }
  }
  uVar6 = (**(code **)(*local_30 + 0x68))(local_30,param_2);
  if ((int)uVar6 == 0) {
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(lVar5 + 0x14);
    *(undefined4 *)(param_2 + 0xb0) = *(undefined4 *)((long)local_30 + 0x5c);
  }
  else {
    nvCheckOkFailedNoLog
              (4,uVar6 & 0xffffffff,"vaspaceGetVasInfo(pVAS, pParams)",
               "src/kernel/gpu/mem_mgr/dma.c",0x2f7);
    uVar6 = uVar6 & 0xffffffff;
  }
  return uVar6;
}


// ===== 003aa360 deviceCtrlCmdDmaGetPdeInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong deviceCtrlCmdDmaGetPdeInfo_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined4 *puVar2;
  undefined8 *puVar3;
  char cVar4;
  uint uVar5;
  long lVar6;
  ulong uVar7;
  long *local_30;
  
  local_30 = (long *)0x0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar6 = resservGetTlsCallContext();
  puVar2 = *(undefined4 **)(*(long *)(lVar6 + 0x48) + 0x70);
  cVar4 = rmapiLockIsOwner();
  if (cVar4 != '\0') {
    cVar4 = rmGpuLockIsOwner();
    if (cVar4 != '\0') {
      if ((*(char *)(lVar1 + 0x908) == '\0') || (*(char *)(lVar1 + 0x4913) != '\0')) {
        puVar3 = *(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48);
        uVar5 = vaspaceGetByHandleOrDeviceDefault_IMPL
                          (*puVar3,*(undefined4 *)(puVar3 + 2),*(undefined4 *)(param_2 + 200),
                           &local_30);
        if (uVar5 == 0) {
          uVar7 = (**(code **)(*local_30 + 0xe8))(local_30,param_2);
          if ((int)uVar7 != 0) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/dma.c",0x330,"deviceCtrlCmdDmaGetPdeInfo_IMPL",4,
                         "NVRM: vaspaceGetPageTableInfo failed\n");
            nvAssertFailedNoLog(&DAT_00d4adb6,"src/kernel/gpu/mem_mgr/dma.c",0x331);
            uVar7 = 0x28;
          }
        }
        else {
          nvCheckOkFailedNoLog
                    (3,uVar5,
                     "vaspaceGetByHandleOrDeviceDefault(RES_GET_CLIENT(pDevice), RES_GET_HANDLE(pDevice), pParams->hVASpace, &pVAS)"
                     ,"src/kernel/gpu/mem_mgr/dma.c",0x329);
          uVar7 = (ulong)uVar5;
        }
      }
      else {
        lVar6 = gpuGetRpc(lVar1);
        if (lVar6 == 0) {
          nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mem_mgr/dma.c",799);
          uVar7 = 0x1a;
        }
        else if ((*(char *)(lVar1 + 0x909) == '\0') && (*(char *)(lVar1 + 0x90a) == '\0')) {
          uVar7 = rpcDmaControl_wrapper
                            (lVar1,lVar6,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                             puVar2[6]);
        }
        else {
          uVar7 = (**(code **)(lVar1 + 0x3b90))(lVar1 + 0x3b58);
        }
      }
      return uVar7;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()","src/kernel/gpu/mem_mgr/dma.c",
                      0x313);
  return 0x2f;
}


// ===== 003aa570 deviceCtrlCmdDmaSetDefaultVASpace_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong deviceCtrlCmdDmaSetDefaultVASpace_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  long lVar2;
  char cVar3;
  ulong uVar4;
  long lVar5;
  
  lVar5 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar3 = rmapiLockIsOwner();
  if ((cVar3 == '\0') || (cVar3 = rmGpuLockIsOwner(), cVar3 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()","src/kernel/gpu/mem_mgr/dma.c",
                        0x340);
    return 0x2f;
  }
  uVar4 = deviceSetDefaultVASpace_IMPL(param_1,*param_2);
  if ((int)uVar4 != 0) {
    nvAssertOkFailedNoLog
              (uVar4 & 0xffffffff,"deviceSetDefaultVASpace( pDevice, pParams->hVASpace)",
               "src/kernel/gpu/mem_mgr/dma.c",0x342);
    return uVar4 & 0xffffffff;
  }
  if ((*(char *)(lVar5 + 0x908) == '\0') && (*(char *)(lVar5 + 0x909) == '\0')) {
    return uVar4;
  }
  lVar5 = resservGetTlsCallContext();
  puVar1 = *(undefined4 **)(*(long *)(lVar5 + 0x48) + 0x70);
  lVar5 = gpuGetRpc(*(undefined8 *)(puVar1 + 8));
  if (lVar5 == 0) {
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mem_mgr/dma.c",0x34c);
    return 0x1a;
  }
  lVar2 = *(long *)(puVar1 + 8);
  if ((*(char *)(lVar2 + 0x909) == '\0') && (*(char *)(lVar2 + 0x90a) == '\0')) {
    uVar4 = rpcDmaControl_wrapper
                      (lVar2,lVar5,*puVar1,puVar1[1],puVar1[2],*(undefined8 *)(puVar1 + 4),puVar1[6]
                      );
    return uVar4;
  }
  uVar4 = (**(code **)(lVar2 + 0x3b90))(lVar2 + 0x3b58);
  return uVar4;
}


// ===== 003aa6e0 subdeviceCtrlCmdDmaInvalidateTLB_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdDmaInvalidateTLB_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  long *local_30 [2];
  
  local_30[0] = (long *)0x0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar4 = rmGpuLockIsOwner();
  if (cVar4 == '\0') {
    nvAssertFailedNoLog("rmGpuLockIsOwner()","src/kernel/gpu/mem_mgr/dma.c",0x369);
    return 0x2f;
  }
  puVar2 = *(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48);
  iVar5 = vaspaceGetByHandleOrDeviceDefault_IMPL
                    (*puVar2,*(undefined4 *)(puVar2[3] + 0x10),*(undefined4 *)(param_2 + 0xc),
                     local_30);
  if (iVar5 != 0) {
    nvCheckOkFailedNoLog
              (3,iVar5,
               "vaspaceGetByHandleOrDeviceDefault(RES_GET_CLIENT(pSubdevice), RES_GET_PARENT_HANDLE(pSubdevice), pParams->hVASpace, &pVAS)"
               ,"src/kernel/gpu/mem_mgr/dma.c",0x36b);
    return iVar5;
  }
  if (*(char *)(lVar1 + 0x908) == '\0') {
    if (*(char *)(lVar1 + 0x4913) != '\0') {
LAB_003aa78c:
      if (*(char *)(lVar1 + 0x491e) != '\0') goto LAB_003aa795;
    }
    (**(code **)(*local_30[0] + 0xe0))(local_30[0],lVar1,1,*(code **)(*local_30[0] + 0xe0));
    iVar5 = 0;
  }
  else {
    if (*(char *)(lVar1 + 0x4913) != '\0') goto LAB_003aa78c;
LAB_003aa795:
    lVar6 = resservGetTlsCallContext();
    puVar3 = *(undefined4 **)(lVar6 + 0x48);
    lVar6 = gpuGetRpc(lVar1);
    if (lVar6 == 0) {
      iVar5 = 0x1a;
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mem_mgr/dma.c",0x375);
    }
    else {
      if ((*(char *)(lVar1 + 0x909) != '\0') || (*(char *)(lVar1 + 0x90a) != '\0')) {
        iVar5 = (**(code **)(lVar1 + 0x3b90))(lVar1 + 0x3b58);
        return iVar5;
      }
      iVar5 = rpcDmaControl_wrapper
                        (lVar1,lVar6,*puVar3,puVar3[1],puVar3[2],*(undefined8 *)(puVar3 + 4),
                         puVar3[6]);
    }
  }
  return iVar5;
}


// ===== 003aa8b0 subdeviceCtrlCmdDmaGetInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 subdeviceCtrlCmdDmaGetInfo_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  ulong uVar5;
  undefined4 uVar6;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar2 = rmapiLockIsOwner();
  if ((cVar2 == '\0') || (cVar2 = rmGpuLockIsOwner(), cVar2 == '\0')) {
    uVar6 = 0x2f;
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()","src/kernel/gpu/mem_mgr/dma.c",
                        0x39a);
  }
  else if (*param_2 < 0x101) {
    uVar4 = 0;
    if (*param_2 == 0) {
      uVar6 = 0;
    }
    else {
      do {
        uVar5 = (ulong)uVar4;
        if (param_2[uVar5 * 2 + 1] != 0) {
          return 0x1f;
        }
        uVar4 = uVar4 + 1;
        uVar3 = (**(code **)(*(long *)(lVar1 + 0x4d8) + 0x68))();
        param_2[uVar5 * 2 + 2] = uVar3;
        uVar6 = 0;
      } while (uVar4 < *param_2);
    }
  }
  else {
    uVar6 = 0x3a;
  }
  return uVar6;
}


// ===== 003aa9a0 deviceCtrlCmdDmaInvalidateTLB_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int deviceCtrlCmdDmaInvalidateTLB_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  long *local_30 [2];
  
  local_30[0] = (long *)0x0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar4 = rmapiLockIsOwner();
  if ((cVar4 == '\0') || (cVar4 = rmGpuLockIsOwner(), cVar4 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()","src/kernel/gpu/mem_mgr/dma.c",
                        0x3cc);
    return 0x2f;
  }
  if (*(char *)(lVar1 + 0x908) == '\0') {
    if (*(char *)(lVar1 + 0x4913) != '\0') {
      cVar4 = *(char *)(lVar1 + 0x491e);
      goto joined_r0x003aaa6b;
    }
LAB_003aaa04:
    puVar2 = *(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48);
    iVar5 = vaspaceGetByHandleOrDeviceDefault_IMPL
                      (*puVar2,*(undefined4 *)(puVar2 + 2),*param_2,local_30);
    if (iVar5 == 0) {
      (**(code **)(*local_30[0] + 0xe0))(local_30[0],lVar1,1,*(code **)(*local_30[0] + 0xe0));
    }
    else {
      nvCheckOkFailedNoLog
                (3,iVar5,
                 "vaspaceGetByHandleOrDeviceDefault(RES_GET_CLIENT(pDevice), RES_GET_HANDLE(pDevice), pParams->hVASpace, &pVAS)"
                 ,"src/kernel/gpu/mem_mgr/dma.c",999);
    }
  }
  else {
    if (*(char *)(lVar1 + 0x4913) != '\0') {
      cVar4 = *(char *)(lVar1 + 0x491e);
joined_r0x003aaa6b:
      if (cVar4 == '\0') goto LAB_003aaa04;
    }
    lVar6 = resservGetTlsCallContext();
    puVar3 = *(undefined4 **)(*(long *)(lVar6 + 0x48) + 0x70);
    lVar6 = gpuGetRpc(lVar1);
    if (lVar6 == 0) {
      iVar5 = 0x1a;
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mem_mgr/dma.c",0x3dc);
    }
    else {
      if ((*(char *)(lVar1 + 0x909) != '\0') || (*(char *)(lVar1 + 0x90a) != '\0')) {
        iVar5 = (**(code **)(lVar1 + 0x3b90))(lVar1 + 0x3b58);
        return iVar5;
      }
      iVar5 = rpcDmaControl_wrapper
                        (lVar1,lVar6,*puVar3,puVar3[1],puVar3[2],*(undefined8 *)(puVar3 + 4),
                         puVar3[6]);
    }
  }
  return iVar5;
}


// ===== 003aab90 deviceCtrlCmdDmaGetCaps_IMPL =====

undefined8 deviceCtrlCmdDmaGetCaps_IMPL(long param_1,int *param_2)

{
  long lVar1;
  char cVar2;
  
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0x128) + 0xe0) + 0x1bb8);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/mem_mgr/dma.c",0x40a);
    return 0x2f;
  }
  if (*param_2 == 8) {
    portMemSet(param_2 + 1,0,8);
    if (*(char *)(lVar1 + 0x1c5) != '\0') {
      *(byte *)(param_2 + 1) = *(byte *)(param_2 + 1) | 1;
    }
    if (*(char *)(lVar1 + 0x1c2) != '\0') {
      *(byte *)(param_2 + 1) = *(byte *)(param_2 + 1) | 4;
    }
    if (*(char *)(lVar1 + 0x1c3) != '\0') {
      *(byte *)(param_2 + 1) = *(byte *)(param_2 + 1) | 8;
    }
    if (*(char *)(lVar1 + 0x1c7) != '\0') {
      *(byte *)(param_2 + 1) = *(byte *)(param_2 + 1) | 0x10;
    }
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/dma.c",0x40f,"deviceCtrlCmdDmaGetCaps_IMPL",4,
               "NVRM: size mismatch: client 0x%x rm 0x%x\n",*param_2,8);
  return 0x1f;
}


// ===== 003aaca0 dmaPageArrayInit =====

void dmaPageArrayInit(undefined8 *param_1,undefined8 param_2,undefined4 param_3)

{
  portMemSet(param_1,0,0x30);
  *param_1 = param_2;
  *(undefined4 *)((long)param_1 + 0xc) = param_3;
  return;
}


// ===== 003aace0 dmaPageArrayInitWithFlags =====

void dmaPageArrayInitWithFlags
               (undefined8 *param_1,undefined8 param_2,undefined4 param_3,ulong param_4,
               undefined8 param_5)

{
  portMemSet(param_1,0,0x30);
  *param_1 = param_2;
  *(undefined4 *)((long)param_1 + 0xc) = param_3;
  if ((param_4 & 1) != 0) {
    *(undefined1 *)((long)param_1 + 0x12) = 1;
    param_1[3] = param_5;
  }
  return;
}


// ===== 003aad40 dmaPageArrayInitFromMemDesc =====

void dmaPageArrayInitFromMemDesc(undefined8 *param_1,long *param_2,undefined8 param_3)

{
  long lVar1;
  char cVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  if (*param_2 != 0) {
    if (*(long *)(*param_2 + 0x1bc0) == 0) goto LAB_003aadd4;
    cVar2 = kmigmgrIsMIGMemPartitioningEnabled_IMPL();
    if (cVar2 != '\0') {
      if (*param_2 == 0) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/dma.c",0x499,"dmaPageArrayInitFromMemDesc",3,
                     "NVRM: Unable to determine memdesc localization information!\n");
      }
      uVar3 = memdescGetPteArraySize(param_2,param_3);
      uVar4 = memdescGetPteArrayForGpu(param_2,*param_2,param_3);
      portMemSet(param_1,0,0x30);
      *param_1 = uVar4;
      *(undefined4 *)((long)param_1 + 0xc) = uVar3;
      return;
    }
    if (*param_2 != 0) goto LAB_003aadd4;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/dma.c",0x499,"dmaPageArrayInitFromMemDesc",3,
               "NVRM: Unable to determine memdesc localization information!\n");
LAB_003aadd4:
  cVar2 = memdescGetFlag(param_2,0x4000000000000);
  lVar1 = param_2[0x2b];
  uVar3 = memdescGetPteArraySize(param_2,param_3);
  uVar4 = memdescGetPteArrayForGpu(param_2,*param_2,param_3);
  portMemSet(param_1,0,0x30);
  *param_1 = uVar4;
  *(undefined4 *)((long)param_1 + 0xc) = uVar3;
  if (cVar2 != '\0') {
    *(undefined1 *)((long)param_1 + 0x12) = 1;
    param_1[3] = lVar1;
  }
  return;
}


// ===== 003aaed0 dmaPageArrayGetPhysAddr =====

ulong dmaPageArrayGetPhysAddr(long *param_1,uint param_2)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  
  lVar1 = *param_1;
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pPageArray->pData","src/kernel/gpu/mem_mgr/dma.c",0x4b8);
  }
  else {
    if (param_2 < *(uint *)((long)param_1 + 0xc)) {
      uVar2 = 0;
      if (*(char *)((long)param_1 + 0x11) == '\0') {
        uVar2 = param_2;
      }
      if ((char)param_1[2] == '\0') {
        uVar3 = (ulong)*(uint *)(param_1 + 4) +
                *(long *)(lVar1 + (ulong)(uVar2 + (int)param_1[1]) * 8);
        if (*(char *)((long)param_1 + 0x12) != '\0') {
          uVar3 = uVar3 | param_1[3];
        }
        return uVar3;
      }
      uVar3 = osPageArrayGetPhysAddr(param_1[5],lVar1);
      return uVar3;
    }
    nvAssertFailedNoLog("pageIndex < pPageArray->count","src/kernel/gpu/mem_mgr/dma.c",0x4b9);
  }
  return 0xffffffffffffffff;
}


// ===== 003aaf70 fbsrObjectInit_IMPL =====

undefined8 fbsrObjectInit_IMPL(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x78) = param_2;
  *(undefined2 *)(param_1 + 0x105) = 0;
  *(undefined8 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0x100) = 0;
  return 0;
}


// ===== 003aafa0 fbsrReserveSysMemoryForPowerMgmt_IMPL =====

ulong fbsrReserveSysMemoryForPowerMgmt_IMPL(undefined8 param_1,long param_2,undefined8 param_3)

{
  ulong uVar1;
  
  if (*(int *)(param_2 + 0x78) != 4) {
    return 0xffff;
  }
  uVar1 = memdescCreate(param_2 + 0x108,param_1,param_3,0,0,1);
  if ((int)uVar1 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0x108) + 0x9c) = 0x33;
    uVar1 = memdescAlloc(*(undefined8 *)(param_2 + 0x108));
    if ((int)uVar1 != 0) {
      memdescDestroy(*(undefined8 *)(param_2 + 0x108));
      uVar1 = uVar1 & 0xffffffff;
      *(undefined8 *)(param_2 + 0x108) = 0;
    }
  }
  return uVar1;
}


// ===== 003ab030 fbsrFreeReservedSysMemoryForPowerMgmt_IMPL =====

void fbsrFreeReservedSysMemoryForPowerMgmt_IMPL(long param_1)

{
  if (*(long *)(param_1 + 0x108) != 0) {
    memdescFree(*(long *)(param_1 + 0x108));
    memdescDestroy(*(undefined8 *)(param_1 + 0x108));
    *(undefined8 *)(param_1 + 0x108) = 0;
    return;
  }
  return;
}


// ===== 003ab080 _heapUpdate =====

undefined8 _heapUpdate(long param_1,long param_2,int param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  
  if (param_3 == 0) {
    portMemSet(param_2 + 0x48,0,0x38);
    *(long *)(param_2 + 0x48) = param_2;
LAB_003ab174:
    *(undefined8 *)(param_2 + 0x50) = *(undefined8 *)(param_2 + 0x10);
    *(undefined8 *)(param_2 + 0x58) = *(undefined8 *)(param_2 + 0x28);
    uVar3 = btreeInsert(param_2 + 0x48,param_1 + 0x98);
    if ((int)uVar3 != 0) {
      nvAssertFailedNoLog("btreeInsert failed to ADD/SIZE_CHANGE block",
                          "src/kernel/gpu/mem_mgr/heap.c",0xe3f);
      return 0x40;
    }
    lVar4 = *(long *)(param_1 + 0xd0);
    if (lVar4 == 0) {
      *(long *)(param_1 + 0xd0) = param_2;
      *(undefined8 *)(param_2 + 200) = 0;
      *(undefined8 *)(param_2 + 0xd0) = 0;
      return uVar3;
    }
LAB_003ab1a8:
    lVar6 = *(long *)(param_2 + 0x28);
    lVar1 = *(long *)(param_2 + 0x10);
    if ((*(long *)(param_2 + 0xd0) != 0) || (*(long *)(param_2 + 200) != 0)) {
      nvAssertFailedNoLog("pBlock->prevFreeNoncontig == NULL && pBlock->nextFreeNoncontig == NULL",
                          "src/kernel/gpu/mem_mgr/heap.c",0xc43);
    }
    do {
      lVar5 = lVar4;
      if ((ulong)((*(long *)(lVar5 + 0x28) + 1) - *(long *)(lVar5 + 0x10)) <
          (ulong)((lVar6 + 1) - lVar1)) {
        uVar3 = *(undefined8 *)(lVar5 + 0xd0);
        *(long *)(param_2 + 200) = lVar5;
        *(undefined8 *)(param_2 + 0xd0) = uVar3;
        *(long *)(lVar5 + 0xd0) = param_2;
        if (lVar5 == *(long *)(param_1 + 0xd0)) {
          *(long *)(param_1 + 0xd0) = param_2;
        }
        else {
          *(long *)(*(long *)(param_2 + 0xd0) + 200) = param_2;
        }
        goto LAB_003ab237;
      }
      lVar4 = *(long *)(lVar5 + 200);
    } while (*(long *)(lVar5 + 200) != 0);
    *(long *)(lVar5 + 200) = param_2;
    *(long *)(param_2 + 0xd0) = lVar5;
    *(undefined8 *)(param_2 + 200) = 0;
LAB_003ab237:
    if (param_3 != 3) {
      return 0;
    }
LAB_003ab241:
    if (*(int *)(param_2 + 4) == -1) {
      return 0;
    }
  }
  else {
    if (param_3 == 2) goto LAB_003ab174;
    if (param_3 == 3) {
      if (*(int *)(param_2 + 4) != -1) goto LAB_003ab0c4;
      lVar4 = *(long *)(param_1 + 0xd0);
      if (lVar4 != 0) goto LAB_003ab1a8;
      *(long *)(param_1 + 0xd0) = param_2;
      *(undefined8 *)(param_2 + 200) = 0;
      *(undefined8 *)(param_2 + 0xd0) = 0;
      goto LAB_003ab241;
    }
    iVar2 = btreeUnlink(param_2 + 0x48,param_1 + 0x98);
    if (iVar2 != 0) {
      nvAssertFailedNoLog("btreeUnlink failed to REMOVE block","src/kernel/gpu/mem_mgr/heap.c",0xe55
                         );
      return 0x40;
    }
  }
LAB_003ab0c4:
  if (param_2 == *(long *)(param_1 + 0xd0)) {
    lVar4 = *(long *)(param_2 + 200);
LAB_003ab0d8:
    *(long *)(param_1 + 0xd0) = lVar4;
LAB_003ab0e2:
    if (lVar4 == 0) goto LAB_003ab0f5;
    uVar3 = *(undefined8 *)(param_2 + 0xd0);
  }
  else {
    lVar6 = *(long *)(param_2 + 0xd0);
    lVar4 = *(long *)(param_2 + 200);
    if (lVar6 != 0) {
LAB_003ab340:
      *(long *)(lVar6 + 200) = lVar4;
      lVar4 = *(long *)(param_2 + 200);
      goto LAB_003ab0e2;
    }
    uVar3 = 0;
    if (lVar4 == 0) {
      nvAssertFailedNoLog("pBlock == pHeap->pNoncontigFreeBlockList || pBlock->prevFreeNoncontig != NULL || pBlock->nextFreeNoncontig != NULL"
                          ,"src/kernel/gpu/mem_mgr/heap.c",0xc7a);
      lVar4 = *(long *)(param_2 + 200);
      if (param_2 == *(long *)(param_1 + 0xd0)) goto LAB_003ab0d8;
      lVar6 = *(long *)(param_2 + 0xd0);
      if (lVar6 != 0) goto LAB_003ab340;
      goto LAB_003ab0e2;
    }
  }
  *(undefined8 *)(lVar4 + 0xd0) = uVar3;
LAB_003ab0f5:
  *(undefined8 *)(param_2 + 0xd0) = 0;
  *(undefined8 *)(param_2 + 200) = 0;
  return 0;
}


// ===== 003ab3b0 _heapBlacklistSingleChunk =====

int _heapBlacklistSingleChunk(long param_1,long param_2,long *param_3)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_1 + 0x1b78);
  if (param_3 == (long *)0x0) {
    nvAssertFailedNoLog("pBlacklistChunk != NULL","src/kernel/gpu/mem_mgr/heap.c",0x484);
  }
  iVar2 = memdescCreate(param_3,param_1,param_3[2],0x1000,1,2,1);
  if (iVar2 == 0) {
    memdescSetPte(*param_3,1,0,param_3[1] & 0xfffffffffffff000,0x20010);
    if (*(int *)(param_2 + 0x4c) != 1) {
      *(undefined4 *)(*param_3 + 0x9c) = 0x6f;
      iVar2 = memdescAlloc(*param_3);
      if (iVar2 != 0) {
        memdescDestroy(*param_3);
        nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x4a4,"_heapBlacklistSingleChunk",6,
                     "NVRM: Error 0x%x creating page for blacklisting address: 0x%llx, skipping\n",
                     iVar2,param_3[1]);
        nvAssertFailedNoLog("NV_FALSE","src/kernel/gpu/mem_mgr/heap.c",0x4a7);
        return iVar2;
      }
    }
    *(undefined1 *)(param_3 + 3) = 1;
    if (*(char *)(lVar1 + 0x443) != '\0') {
      *(undefined1 *)((long)param_3 + 0x19) = 0;
    }
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x48d,"_heapBlacklistSingleChunk",6,
               "NVRM: Error 0x%x creating memdesc for blacklisted chunk for address0x%llx, skipping\n"
               ,iVar2,param_3[1]);
  nvAssertFailedNoLog("NV_FALSE","src/kernel/gpu/mem_mgr/heap.c",0x490);
  return iVar2;
}


// ===== 003ab560 _heapBlacklistChunks =====

int _heapBlacklistChunks
              (undefined8 param_1,undefined8 param_2,long *param_3,ulong param_4,long param_5)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  long lVar5;
  uint uVar6;
  
  if ((int)param_3[1] == 0) {
    return 0;
  }
  iVar4 = 0;
  uVar6 = 0;
  lVar5 = *param_3;
  do {
    while ((*(char *)(lVar5 + 0x18) == '\x01' || (uVar3 = *(ulong *)(lVar5 + 8), uVar3 < param_4)))
    {
LAB_003ab5c0:
      uVar6 = uVar6 + 1;
      lVar5 = lVar5 + 0x20;
      if (*(uint *)(param_3 + 1) <= uVar6) {
        return iVar4;
      }
    }
    uVar1 = (param_4 - 1) + param_5;
    uVar2 = *(long *)(lVar5 + 0x10) + -1 + uVar3;
    if (uVar1 < uVar2) goto LAB_003ab5c0;
    nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x521,"_heapBlacklistChunks",4,
                 "NVRM: blacklisting chunk from addr: 0x%llx to 0x%llx, new begin :0x%llx, end:0x%llx\n"
                 ,uVar3,uVar2,param_4,uVar1);
    iVar4 = _heapBlacklistSingleChunk(param_1,param_2,lVar5);
    if (iVar4 == 0) goto LAB_003ab5c0;
    uVar6 = uVar6 + 1;
    lVar5 = lVar5 + 0x20;
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/heap.c",0x525);
    if (*(uint *)(param_3 + 1) <= uVar6) {
      return iVar4;
    }
  } while( true );
}


// ===== 003ab690 heapReserveRegion.constprop.0 =====

int heapReserveRegion_constprop_0
              (long param_1,long param_2,ulong param_3,ulong param_4,undefined8 *param_5,
              char param_6,char param_7)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar7;
  long lVar8;
  int *local_130 [15];
  int local_b8;
  int local_b4;
  int local_b0 [2];
  ulong local_a8 [15];
  ulong uVar6;
  
  uVar3 = 0;
  if (param_1 != 0) {
    uVar3 = *(undefined8 *)(param_1 + 0x150);
  }
  uVar3 = gpuEngineGetGpu(uVar3);
  uVar4 = *(long *)(param_2 + 0x70) + *(long *)(param_2 + 0x68);
  uVar5 = 0;
  do {
    uVar1 = (int)uVar5 + 0x20;
    uVar6 = (ulong)uVar1;
    *(undefined8 *)((long)local_130 + uVar5) = 0;
    *(undefined8 *)((long)local_130 + uVar5 + 8) = 0;
    *(undefined8 *)((long)local_130 + uVar5 + 0x10) = 0;
    *(undefined8 *)((long)local_130 + uVar5 + 0x18) = 0;
    uVar5 = uVar6;
  } while (uVar1 < 0x60);
  *(undefined8 *)((long)local_130 + uVar6) = 0;
  *(undefined8 *)((long)local_130 + uVar6 + 8) = 0;
  *(undefined8 *)((long)local_130 + uVar6 + 0x10) = 0;
  uVar1 = 0;
  do {
    uVar5 = (ulong)uVar1;
    uVar1 = uVar1 + 0x20;
    *(undefined8 *)((long)&local_b8 + uVar5) = 0;
    *(undefined8 *)((long)local_b0 + uVar5) = 0;
    *(undefined8 *)((long)local_a8 + uVar5) = 0;
    *(undefined8 *)((long)local_a8 + uVar5 + 8) = 0;
  } while (uVar1 < 0x80);
  if (param_3 < uVar4) {
    local_130[0] = &local_b8;
    local_b8 = (-(uint)(param_6 == '\0') & 3) + 0xdeaf0002;
    local_a8[0] = 0x100000001;
    local_b4 = 0xf - (uint)(param_6 != '\0');
    local_a8[1] = 0x400010800000;
    local_a8[6] = uVar4 - param_3;
    if (param_4 < local_a8[6]) {
      local_a8[6] = param_4;
    }
    local_b0[0] = (-(uint)(param_7 == '\0') & 0xff000000) + 0x1000010;
    local_a8[8] = param_3;
    lVar7 = portMemAllocNonPaged(0xc0);
    if (lVar7 == 0) {
      lVar8 = 0;
      nvAssertOkFailedNoLog(0x51,"pFbAllocInfo != NULL","src/kernel/gpu/mem_mgr/heap.c",0x15a);
      iVar2 = 0x51;
    }
    else {
      lVar8 = portMemAllocNonPaged(0x14);
      if (lVar8 == 0) {
        nvAssertOkFailedNoLog
                  (0x51,"pFbAllocPageFormat != NULL","src/kernel/gpu/mem_mgr/heap.c",0x15d);
        iVar2 = 0x51;
      }
      else {
        portMemSet(lVar7,0,0xc0);
        portMemSet(lVar8,0,0x14);
        *(long *)(lVar7 + 0x90) = lVar8;
        memUtilsInitFBAllocInfo(&local_b8,lVar7,0,0);
        iVar2 = memmgrAllocResources_IMPL(uVar3,param_1,local_130,lVar7);
        if (iVar2 == 0) {
          iVar2 = vidmemAllocResources(uVar3,param_1,local_130,lVar7,param_2);
          if (iVar2 == 0) {
            if (param_6 == '\0') {
              nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x16d,"heapReserveRegion",1,
                           "NVRM: Reserved heap for %s %llx..%llx\n",&DAT_00d4b26c,param_3);
              *param_5 = local_130[4];
            }
            else {
              nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x16d,"heapReserveRegion",1,
                           "NVRM: Reserved heap for %s %llx..%llx\n",&DAT_00d4b269,param_3,
                           (param_3 - 1) + param_4);
              *param_5 = local_130[4];
              *(long *)(param_2 + 0x80) = *(long *)(param_2 + 0x80) + local_a8[6];
            }
          }
          else {
            nvAssertOkFailedNoLog
                      (iVar2,
                       "vidmemAllocResources(pGpu, pMemoryManager, &allocRequest, pFbAllocInfo, pHeap)"
                       ,"src/kernel/gpu/mem_mgr/heap.c",0x169);
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar2,"memmgrAllocResources(pGpu, pMemoryManager, &allocRequest, pFbAllocInfo)"
                     ,"src/kernel/gpu/mem_mgr/heap.c",0x165);
        }
      }
    }
    portMemFree(lVar8);
    portMemFree(lVar7);
  }
  else {
    nvAssertFailedNoLog("(offset < heapSize)","src/kernel/gpu/mem_mgr/heap.c",0x147);
    iVar2 = 0;
  }
  return iVar2;
}


// ===== 003abaa0 _heapProcessFreeBlock.isra.0 =====

undefined4
_heapProcessFreeBlock_isra_0
          (long param_1,long param_2,long *param_3,long *param_4,long param_5,undefined4 *param_6,
          undefined4 param_7,long param_8,long param_9,undefined8 param_10,long *param_11)

{
  ulong uVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  undefined4 uVar9;
  
  if (*(ulong *)(param_8 + 8) == *(ulong *)(param_2 + 0x10)) {
    uVar6 = *(ulong *)(param_8 + 0x18);
    uVar8 = *(ulong *)(param_2 + 0x28);
    if (uVar6 == uVar8) {
      lVar5 = *(long *)(param_2 + 0xa8);
      *(long *)(*(long *)(param_2 + 0xb0) + 0xa8) = lVar5;
      lVar4 = *(long *)(param_2 + 0xb0);
      *(long *)(lVar5 + 0xb0) = lVar4;
      if (param_2 == *(long *)(param_5 + 0x90)) {
        if (param_2 == lVar4) {
          lVar4 = 0;
        }
        *(long *)(param_5 + 0x90) = lVar4;
      }
      *(undefined4 *)(param_2 + 4) = *param_6;
      *(undefined4 *)(param_2 + 8) = param_7;
      LOCK();
      *(undefined4 *)(param_2 + 0x44) = 1;
      UNLOCK();
      *(undefined4 *)(param_2 + 0xa8) = param_6[1];
      lVar5 = 0;
      *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)(param_8 + 0x10);
      *(undefined8 *)(param_2 + 0x20) = param_10;
      *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(param_9 + 0x4c);
      goto LAB_003abd2e;
    }
LAB_003abae4:
    if (uVar6 <= uVar8) {
      lVar4 = portMemAllocNonPaged(0xe0);
      if (lVar4 == 0) {
        lVar5 = 0;
        uVar9 = 0x51;
        nvAssertFailedNoLog(&DAT_00d4b32f,"src/kernel/gpu/mem_mgr/heap.c",0xb3f);
        goto LAB_003abc4b;
      }
      portMemSet(lVar4,0,0xe0);
      *(undefined4 *)(lVar4 + 4) = *param_6;
      *(undefined4 *)(lVar4 + 8) = param_7;
      LOCK();
      *(undefined4 *)(lVar4 + 0x44) = 1;
      UNLOCK();
      *(undefined4 *)(lVar4 + 0xa8) = param_6[1];
      uVar8 = *(ulong *)(param_8 + 8);
      *(ulong *)(lVar4 + 0x10) = uVar8;
      *(undefined8 *)(lVar4 + 0x18) = *(undefined8 *)(param_8 + 0x10);
      *(undefined8 *)(lVar4 + 0x20) = param_10;
      uVar6 = *(ulong *)(param_8 + 0x18);
      *(ulong *)(lVar4 + 0x28) = uVar6;
      *(undefined4 *)(lVar4 + 0x34) = *(undefined4 *)(param_9 + 0x4c);
      if (*(char *)(param_1 + 0x4921) != '\0') {
        uVar8 = *(ulong *)(param_8 + 0x10);
        *(ulong *)(lVar4 + 0x10) = uVar8;
        uVar6 = *(long *)(param_8 + 0x20) + -1 + uVar8;
        *(ulong *)(lVar4 + 0x28) = uVar6;
      }
      uVar1 = *(ulong *)(param_2 + 0x28);
      if (*(ulong *)(param_2 + 0x10) < uVar8) {
        if (uVar6 < uVar1) {
          lVar5 = portMemAllocNonPaged(0xe0);
          if (lVar5 != 0) {
            portMemSet(lVar5,0,0xe0);
            iVar3 = _heapUpdate(param_5,param_2,1);
            if (iVar3 != 0) {
              uVar9 = 0x40;
              goto LAB_003abc4b;
            }
            *(undefined4 *)(lVar5 + 4) = 0xffffffff;
            *(undefined4 *)(lVar5 + 0x34) = 0;
            lVar7 = *(long *)(lVar4 + 0x28);
            *(undefined8 *)(lVar5 + 0x20) = 0;
            lVar7 = lVar7 + 1;
            *(long *)(lVar5 + 0x10) = lVar7;
            *(long *)(lVar5 + 0x18) = lVar7;
            *(undefined8 *)(lVar5 + 0x28) = *(undefined8 *)(param_2 + 0x28);
            *(long *)(param_2 + 0x28) = *(long *)(lVar4 + 0x10) + -1;
            lVar7 = *(long *)(param_2 + 0xb0);
            *(long *)(lVar5 + 0xa8) = param_2;
            *(long *)(lVar5 + 0xb0) = lVar7;
            *(long *)(lVar7 + 0xa8) = lVar5;
            *(long *)(param_2 + 0xb0) = lVar5;
            *(long *)(lVar4 + 0xc0) = lVar5;
            *(long *)(lVar4 + 0xb8) = param_2;
            uVar2 = *(undefined8 *)(param_2 + 0xc0);
            *(long *)(lVar5 + 0xb8) = lVar4;
            *(undefined8 *)(lVar5 + 0xc0) = uVar2;
            *(long *)(param_2 + 0xc0) = lVar4;
            *(long *)(*(long *)(lVar5 + 0xc0) + 0xb8) = lVar5;
            iVar3 = _heapUpdate(param_5,param_2,2);
            if (iVar3 == 0) {
              iVar3 = _heapUpdate(param_5,lVar4,0);
              if (iVar3 == 0) {
                iVar3 = _heapUpdate(param_5,lVar5,0);
                param_2 = lVar4;
                if (iVar3 != 0) {
                  nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xbac,"_heapProcessFreeBlock",4,
                               "NVRM: _heapUpdate failed to _ADD block\n");
                }
              }
              else {
                nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xba2,"_heapProcessFreeBlock",4,
                             "NVRM: _heapUpdate failed to _ADD block\n");
                param_2 = lVar4;
              }
            }
            else {
              nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xb96,"_heapProcessFreeBlock",4,
                           "NVRM: _heapUpdate failed to _SIZE_CHANGE block\n");
              param_2 = lVar4;
            }
            goto LAB_003abd2e;
          }
          uVar9 = 0x51;
          goto LAB_003abc4b;
        }
        if (uVar6 != uVar1) {
LAB_003abdbb:
          uVar9 = 0x51;
          lVar5 = 0;
          goto LAB_003abc4b;
        }
LAB_003abdd0:
        iVar3 = _heapUpdate(param_5,param_2,1);
        if (iVar3 != 0) {
LAB_003abfd0:
          uVar9 = 0x40;
          lVar5 = 0;
          goto LAB_003abc4b;
        }
        *(long *)(param_2 + 0x28) = *(long *)(lVar4 + 0x10) + -1;
        uVar2 = *(undefined8 *)(param_2 + 0xc0);
        *(long *)(lVar4 + 0xb8) = param_2;
        *(undefined8 *)(lVar4 + 0xc0) = uVar2;
        *(long *)(*(long *)(param_2 + 0xc0) + 0xb8) = lVar4;
        *(long *)(param_2 + 0xc0) = lVar4;
        iVar3 = _heapUpdate(param_5,param_2,2);
        if (iVar3 == 0) {
          lVar5 = 0;
          iVar3 = _heapUpdate(param_5,lVar4,0);
          param_2 = lVar4;
          if (iVar3 == 0) goto LAB_003abd2e;
          nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xbd5,"_heapProcessFreeBlock",4,
                       "NVRM: _heapUpdate failed to _ADD block\n");
        }
        else {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xbc9,"_heapProcessFreeBlock",4,
                       "NVRM: _heapUpdate failed to _SIZE_CHANGE block\n");
        }
      }
      else {
        if (uVar6 == uVar1) goto LAB_003abdd0;
        if (*(ulong *)(param_2 + 0x10) != uVar8) goto LAB_003abdbb;
        iVar3 = _heapUpdate(param_5,param_2,1);
        if (iVar3 != 0) goto LAB_003abfd0;
        lVar5 = *(long *)(lVar4 + 0x28) + 1;
        *(long *)(param_2 + 0x10) = lVar5;
        *(long *)(param_2 + 0x18) = lVar5;
        *(long *)(lVar4 + 0xc0) = param_2;
        lVar5 = *(long *)(param_2 + 0xb8);
        *(long *)(lVar4 + 0xb8) = lVar5;
        *(long *)(lVar5 + 0xc0) = lVar4;
        *(long *)(param_2 + 0xb8) = lVar4;
        if (param_2 == *(long *)(param_5 + 0x88)) {
          *(long *)(param_5 + 0x88) = lVar4;
        }
        iVar3 = _heapUpdate(param_5,param_2,2);
        if (iVar3 == 0) {
          iVar3 = _heapUpdate(param_5,lVar4,0);
          if (iVar3 != 0) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xc01,"_heapProcessFreeBlock",4,
                         "NVRM: _heapUpdate failed to _ADD block\n");
          }
        }
        else {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xbf5,"_heapProcessFreeBlock",4,
                       "NVRM: _heapUpdate failed to _SIZE_CHANGE block\n");
        }
      }
      lVar5 = 0;
      param_2 = lVar4;
LAB_003abd2e:
      *param_3 = param_2;
      *param_4 = lVar5;
      *param_11 = *(long *)(param_2 + 0x20) + *(long *)(param_2 + 0x18);
      uVar6 = (*(long *)(param_5 + 0x78) + -1 + *(long *)(param_2 + 0x10)) -
              *(long *)(param_2 + 0x28);
      *(ulong *)(param_5 + 0x78) = uVar6;
      if (*(ulong *)(param_5 + 0x70) < uVar6) {
        nvAssertFailedNoLog("pHeap->free <= pHeap->total","src/kernel/gpu/mem_mgr/heap.c",0xaf5);
      }
      if ((*(uint *)(*(long *)(param_9 + 0x90) + 4) & 0x4000) == 0) {
        return 0;
      }
      osInternalReserveAllocCallback
                (*param_11,*(undefined8 *)(param_9 + 0x18),*(undefined4 *)(param_1 + 0x7ac));
      return 0;
    }
  }
  else if (*(ulong *)(param_2 + 0x10) <= *(ulong *)(param_8 + 8)) {
    uVar6 = *(ulong *)(param_8 + 0x18);
    uVar8 = *(ulong *)(param_2 + 0x28);
    goto LAB_003abae4;
  }
  uVar9 = 0x51;
  lVar5 = 0;
  lVar4 = 0;
LAB_003abc4b:
  nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xc13,"_heapProcessFreeBlock",4,
               "NVRM: failed to allocate block\n");
  portMemFree(lVar4);
  portMemFree(lVar5);
  *param_3 = 0;
  *param_4 = 0;
  return uVar9;
}


// ===== 003ac150 _heapFreeBlacklistPages.isra.0 =====

void _heapFreeBlacklistPages_isra_0(long param_1,undefined8 *param_2,ulong param_3,long param_4)

{
  ulong uVar1;
  ulong uVar2;
  undefined8 *puVar3;
  uint uVar4;
  
  if (*(int *)(param_2 + 1) == 0) {
    return;
  }
  uVar4 = 0;
  puVar3 = (undefined8 *)*param_2;
  do {
    if (((*(char *)(puVar3 + 3) == '\x01') &&
        (((*(char *)(param_1 + 0x443) == '\0' || (*(char *)((long)puVar3 + 0x19) == '\0')) &&
         (uVar2 = puVar3[1], param_3 <= uVar2)))) &&
       (uVar1 = puVar3[2] + -1 + uVar2, uVar1 <= (param_3 - 1) + param_4)) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x4e6,"_heapFreeBlacklistPages",6,
                   "NVRM: removing from blacklist... page start %llx, page end:%llx\n",uVar2,uVar1);
      memdescFree(*puVar3);
      memdescDestroy(*puVar3);
      *(undefined1 *)(puVar3 + 3) = 0;
    }
    uVar4 = uVar4 + 1;
    puVar3 = puVar3 + 4;
  } while (uVar4 < *(uint *)(param_2 + 1));
  return;
}


// ===== 003ac240 _isAllocValidForFBRegion.isra.0 =====

ulong _isAllocValidForFBRegion_isra_0(long param_1,int *param_2,long param_3)

{
  uint uVar1;
  uint *puVar2;
  long lVar3;
  undefined8 in_R10;
  ulong uVar4;
  
  if (*(int *)(*(long *)(param_1 + 0x1b78) + 0x858) == 0) {
    return 1;
  }
  lVar3 = memmgrLookupFbRegionByOffset_IMPL
                    (param_1,*(long *)(param_1 + 0x1b78),*(undefined8 *)(param_3 + 8),
                     *(undefined8 *)(param_3 + 0x18));
  puVar2 = *(uint **)(param_2 + 0x24);
  uVar1 = puVar2[4];
  if (lVar3 == 0) {
    if (uVar1 != 0xe) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x462,"_isAllocValidForFBRegion",1,
                   "NVRM: pFbAllocInfo->type != NVOS32_TYPE_RESERVED\n");
      return 0;
    }
  }
  else {
    if (uVar1 == 0xf) {
      if (*param_2 == -0x2150fffb) {
        if (*(char *)(lVar3 + 0x23) != '\0') {
          return 0;
        }
        uVar4 = CONCAT71((int7)((ulong)in_R10 >> 8),*(char *)(lVar3 + 0x18) == '\0');
        goto LAB_003ac2d1;
      }
      if (*(char *)(lVar3 + 0x18) != '\0') goto LAB_003ac450;
      if (*(char *)(lVar3 + 0x20) == '\0') {
        uVar1 = *puVar2;
        goto joined_r0x003ac30b;
      }
    }
    else if (*(char *)(lVar3 + 0x18) == '\0') {
      if ((*(char *)(lVar3 + 0x20) == '\0') && ((*puVar2 & 0x3000) == 0x1000)) goto LAB_003ac360;
      if ((uVar1 < 0x12) &&
         (((*(char *)(lVar3 + 0x21) == '\0' && (uVar1 < 9)) &&
          ((0x128UL >> ((ulong)uVar1 & 0x3f) & 1) != 0)))) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x44c,"_isAllocValidForFBRegion",1,
                     "NVRM: ISO surface type #%d not supported.  Rejecting placement\n");
        uVar4 = 0;
        goto LAB_003ac2d1;
      }
    }
    else {
      if (uVar1 != 0xe) {
LAB_003ac450:
        nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x42e,"_isAllocValidForFBRegion",1,
                     "NVRM: Reserved region.  Rejecting placement\n");
        return 0;
      }
      if (*(char *)(lVar3 + 0x20) == '\0') {
        uVar1 = *puVar2;
joined_r0x003ac30b:
        if ((uVar1 & 0x3000) == 0x1000) {
LAB_003ac360:
          nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x43e,"_isAllocValidForFBRegion",1,
                       "NVRM: Compression not supported.  Rejecting placement\n");
          return 0;
        }
      }
    }
    if ((*(char *)(lVar3 + 0x22) != '\0') != (bool)(*(byte *)((long)puVar2 + 0xb) & 1)) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x456,"_isAllocValidForFBRegion",1,
                   "NVRM: Protection mismatch.  Rejecting placement\n");
      return 0;
    }
  }
  uVar4 = 1;
LAB_003ac2d1:
  return uVar4 & 0xffffffff;
}


// ===== 003ac4a0 _heapBlockFree =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
_heapBlockFree(long param_1,long param_2,undefined4 param_3,undefined4 param_4,long param_5)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  int *piVar9;
  
  if (*(int *)(param_5 + 4) == -1) {
    return 0x40;
  }
  lVar8 = *(long *)(param_1 + 0x1b78);
  *(undefined4 *)(param_5 + 4) = 0xffffffff;
  iVar3 = _heapUpdate(param_2,param_5,3);
  if (iVar3 != 0) {
    return 0x40;
  }
  uVar5 = (*(long *)(param_2 + 0x78) + 1 + *(long *)(param_5 + 0x28)) - *(long *)(param_5 + 0x10);
  *(ulong *)(param_2 + 0x78) = uVar5;
  if (*(ulong *)(param_2 + 0x70) < uVar5) {
    nvAssertFailedNoLog("pHeap->free <= pHeap->total","src/kernel/gpu/mem_mgr/heap.c",0xaf5);
  }
  lVar6 = portMemAllocNonPaged(0xc0);
  if (lVar6 == 0) {
    nvAssertFailedNoLog(&DAT_00d4b32f,"src/kernel/gpu/mem_mgr/heap.c",0x78e);
    return 0x51;
  }
  lVar7 = portMemAllocNonPaged(0x14);
  if (lVar7 == 0) {
    nvAssertFailedNoLog(&DAT_00d4b32f,"src/kernel/gpu/mem_mgr/heap.c",0x794);
    portMemFree(lVar6);
    return 0x51;
  }
  portMemSet(lVar6,0,0xc0);
  portMemSet(lVar7,0,0x14);
  *(long *)(lVar6 + 0x90) = lVar7;
  *(undefined4 *)(lVar7 + 0x10) = *(undefined4 *)(param_5 + 0xa8);
  uVar1 = *(undefined4 *)(param_5 + 0x98);
  *(undefined4 *)(lVar6 + 8) = 0;
  *(undefined4 *)(lVar6 + 4) = uVar1;
  *(undefined4 *)(lVar6 + 0x10) = 0;
  *(long *)(lVar6 + 0x18) = (*(long *)(param_5 + 0x28) + 1) - *(long *)(param_5 + 0x10);
  *(undefined8 *)(lVar6 + 0x20) = *(undefined8 *)(param_5 + 0x18);
  *(undefined8 *)(lVar6 + 0x28) = *(undefined8 *)(param_5 + 0x20);
  *(undefined8 *)(lVar6 + 0x38) = *(undefined8 *)(param_5 + 0x10);
  *(undefined4 *)(lVar6 + 0x4c) = *(undefined4 *)(param_5 + 0x34);
  uVar1 = *(undefined4 *)(param_5 + 0x90);
  *(undefined4 *)(lVar6 + 0x54) = 0;
  *(undefined4 *)(lVar6 + 0x50) = uVar1;
  **(undefined4 **)(lVar6 + 0x90) = *(undefined4 *)(param_5 + 0x88);
  *(undefined4 *)(*(long *)(lVar6 + 0x90) + 4) = *(undefined4 *)(param_5 + 0x8c);
  *(undefined4 *)(lVar6 + 0xa4) = *(undefined4 *)(param_5 + 0x94);
  *(undefined4 *)(lVar6 + 0x98) = param_3;
  *(undefined4 *)(lVar6 + 0x9c) = param_4;
  (**(code **)(lVar8 + 0x170))(param_1,lVar8,lVar6);
  if ((*(byte *)(*(long *)(lVar6 + 0x90) + 5) & 0x40) != 0) {
    osInternalReserveFreeCallback(*(undefined8 *)(lVar6 + 0x38),*(undefined4 *)(param_1 + 0x7ac));
  }
  portMemSet(param_5 + 0x88,0,0x1c);
  portMemFree(lVar7);
  portMemFree(lVar6);
  iVar3 = *(int *)(param_5 + 0xa8);
  if (iVar3 == 2) {
    if (*(int *)(param_5 + 0x30) != 0) {
      piVar9 = (int *)(param_2 + 0xa0);
      uVar4 = 0;
      do {
        if (*(int *)(param_5 + 0x30) == *piVar9) {
          *(undefined4 *)(param_5 + 0x30) = 0;
          piVar9 = (int *)(param_2 + 0xa4 + (ulong)uVar4 * 0xc);
          *piVar9 = *piVar9 + -1;
          if (*piVar9 == 0) {
            portMemSet(param_2 + 0xa0 + (ulong)uVar4 * 0xc,0,0xc);
          }
          iVar3 = *(int *)(param_5 + 0xa8);
          goto LAB_003ac67c;
        }
        uVar4 = uVar4 + 1;
        piVar9 = piVar9 + 3;
      } while (uVar4 != 4);
    }
  }
  else {
LAB_003ac67c:
    if ((iVar3 == 0xe) && (*(int *)(param_5 + 4) == -0x2150fffe)) {
      lVar8 = *(long *)(param_5 + 0x28);
      lVar6 = *(long *)(param_5 + 0x10);
      uVar5 = *(ulong *)(param_2 + 0x80);
      if (uVar5 < (ulong)((lVar8 + 1) - lVar6)) {
        nvAssertFailedNoLog("pHeap->reserved >= pBlock->end - pBlock->begin + 1",
                            "src/kernel/gpu/mem_mgr/heap.c",0x7d6);
        uVar5 = *(ulong *)(param_2 + 0x80);
        lVar6 = *(long *)(param_5 + 0x10);
        lVar8 = *(long *)(param_5 + 0x28);
      }
      *(ulong *)(param_2 + 0x80) = ((uVar5 - 1) + lVar6) - lVar8;
    }
  }
  if (*(int *)(*(long *)(param_5 + 0xb8) + 4) == -1) {
    if (*(long *)(param_2 + 0x88) != param_5) {
      iVar3 = _heapUpdate(param_2,param_5,1);
      if (iVar3 != 0) {
        return 0x40;
      }
      iVar3 = _heapUpdate(param_2,*(undefined8 *)(param_5 + 0xb8),1);
      if (iVar3 != 0) {
        return 0x40;
      }
      lVar8 = *(long *)(param_5 + 0xc0);
      *(long *)(*(long *)(param_5 + 0xb8) + 0xc0) = lVar8;
      lVar6 = *(long *)(param_5 + 0xb8);
      *(long *)(lVar8 + 0xb8) = lVar6;
      *(undefined8 *)(lVar6 + 0x28) = *(undefined8 *)(param_5 + 0x28);
      lVar8 = *(long *)(param_5 + 0xb8);
      portMemFree(param_5);
      iVar3 = _heapUpdate(param_2,lVar8,2);
      if (iVar3 != 0) {
        return 0x40;
      }
      if ((*(int *)(*(long *)(lVar8 + 0xc0) + 4) != -1) ||
         (*(long *)(lVar8 + 0xc0) == *(long *)(param_2 + 0x88))) goto LAB_003ac6ef;
      bVar2 = true;
      param_5 = lVar8;
      goto LAB_003ac900;
    }
    if ((*(int *)(*(long *)(param_5 + 0xc0) + 4) == -1) && (*(long *)(param_5 + 0xc0) != param_5))
    goto LAB_003ac8fd;
  }
  else if ((*(int *)(*(long *)(param_5 + 0xc0) + 4) == -1) &&
          (*(long *)(param_5 + 0xc0) != *(long *)(param_2 + 0x88))) {
LAB_003ac8fd:
    bVar2 = false;
LAB_003ac900:
    iVar3 = _heapUpdate(param_2,param_5,1);
    if ((iVar3 != 0) || (iVar3 = _heapUpdate(param_2,*(undefined8 *)(param_5 + 0xc0),1), iVar3 != 0)
       ) {
      return 0x40;
    }
    lVar8 = *(long *)(param_5 + 0xc0);
    *(long *)(*(long *)(param_5 + 0xb8) + 0xc0) = lVar8;
    *(undefined8 *)(lVar8 + 0xb8) = *(undefined8 *)(param_5 + 0xb8);
    *(undefined8 *)(*(long *)(param_5 + 0xc0) + 0x10) = *(undefined8 *)(param_5 + 0x10);
    if (*(long *)(param_2 + 0x88) == param_5) {
      *(undefined8 *)(param_2 + 0x88) = *(undefined8 *)(param_5 + 0xc0);
    }
    if (bVar2) {
      if (*(long *)(param_2 + 0x90) == param_5) {
        *(undefined8 *)(param_2 + 0x90) = *(undefined8 *)(param_5 + 0xb0);
      }
      lVar8 = *(long *)(param_5 + 0xa8);
      *(long *)(*(long *)(param_5 + 0xb0) + 0xa8) = lVar8;
      *(undefined8 *)(lVar8 + 0xb0) = *(undefined8 *)(param_5 + 0xb0);
    }
    lVar8 = *(long *)(param_5 + 0xc0);
    portMemFree(param_5);
    iVar3 = _heapUpdate(param_2,lVar8,2);
    if (iVar3 != 0) {
      return 0x40;
    }
    goto LAB_003ac6ef;
  }
  lVar6 = *(long *)(param_2 + 0x90);
  lVar8 = param_5;
  if (lVar6 == 0) {
    *(long *)(param_2 + 0x90) = param_5;
    *(long *)(param_5 + 0xb0) = param_5;
    *(long *)(param_5 + 0xa8) = param_5;
  }
  else {
    uVar5 = *(ulong *)(param_5 + 0x10);
    if (uVar5 < *(ulong *)(lVar6 + 0x10)) {
      *(long *)(param_2 + 0x90) = param_5;
    }
    else if (uVar5 < *(ulong *)(*(long *)(lVar6 + 0xa8) + 0x10)) {
      do {
        lVar6 = *(long *)(lVar6 + 0xb0);
        if (uVar5 <= *(ulong *)(lVar6 + 0x10)) break;
        lVar6 = *(long *)(lVar6 + 0xb0);
      } while (*(ulong *)(lVar6 + 0x10) < uVar5);
    }
    *(long *)(param_5 + 0xb0) = lVar6;
    lVar7 = *(long *)(lVar6 + 0xa8);
    *(long *)(param_5 + 0xa8) = lVar7;
    *(long *)(lVar7 + 0xb0) = param_5;
    *(long *)(lVar6 + 0xa8) = param_5;
  }
LAB_003ac6ef:
  *(undefined4 *)(lVar8 + 8) = 0;
  *(undefined8 *)(lVar8 + 0x20) = 0;
  *(undefined8 *)(lVar8 + 0x18) = *(undefined8 *)(lVar8 + 0x10);
  *(undefined4 *)(lVar8 + 0x34) = 0;
  return 0;
}


// ===== 003acb70 _heapFindBlockByOffset.isra.0 =====

undefined8 _heapFindBlockByOffset_isra_0(long param_1,int param_2,undefined8 param_3,long *param_4)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  long *local_30;
  
  cVar2 = osIsRaisedIRQL();
  if (cVar2 != '\0') {
    nvAssertFailedNoLog("!osIsRaisedIRQL()","src/kernel/gpu/mem_mgr/heap.c",0x8a3);
    return 0x2d;
  }
  uVar4 = btreeSearch(param_3,&local_30,*(undefined8 *)(param_1 + 0x98));
  if (((int)uVar4 == 0) && (param_2 == *(int *)(*local_30 + 4))) {
    *param_4 = *local_30;
  }
  else {
    *param_4 = 0;
    iVar3 = btreeSearch(param_3,&local_30,*(undefined8 *)(param_1 + 0x98));
    if (iVar3 == 0) {
      lVar1 = *local_30;
      *param_4 = lVar1;
      uVar4 = 0;
      if (lVar1 == 0) {
        uVar4 = 0x37;
      }
      return uVar4;
    }
    *param_4 = 0;
    uVar4 = 0x37;
  }
  return uVar4;
}


// ===== 003acc60 heapInitInternal_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int heapInitInternal_IMPL
              (long param_1,long param_2,ulong param_3,long param_4,uint param_5,long param_6)

{
  char cVar1;
  long lVar2;
  undefined1 uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  ulong *puVar7;
  uint uVar8;
  ulong uVar9;
  long local_60;
  long local_40 [2];
  
  lVar2 = *(long *)(param_1 + 0x1b78);
  nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x19e,"heapInitInternal_IMPL",1,
               "NVRM: Heap Manager: HEAP ABOUT TO BE CREATED. (Base: 0x%llx Size: 0x%llx)\n",param_3
               ,param_4);
  *(long *)(param_2 + 0x70) = param_4;
  *(long *)(param_2 + 0x78) = param_4;
  *(ulong *)(param_2 + 0x68) = param_3;
  *(undefined8 *)(param_2 + 0x80) = 0;
  *(uint *)(param_2 + 0x4c) = param_5;
  if (param_5 == 1) {
    if (param_6 == 0) {
      nvAssertFailedNoLog("pPtr != NULL","src/kernel/gpu/mem_mgr/heap.c",0x1af);
    }
    *(undefined1 *)(param_2 + 0x60) = 0;
    local_60 = *(long *)(param_6 + 8);
    *(undefined8 *)(param_2 + 0x50) = 0;
    lVar5 = portMemAllocNonPaged(0x10);
    *(long *)(param_2 + 0x50) = lVar5;
    if (lVar5 == 0) {
      return 0x59;
    }
    portMemCopy(lVar5,0x10,param_6,0x10);
  }
  else {
    if ((param_5 & 0xfffffffd) != 0) {
      return 0x1f;
    }
    *(undefined1 *)(param_2 + 0x60) = 1;
    *(undefined8 *)(param_2 + 0x50) = 0;
    local_60 = 0;
  }
  lVar5 = portMemAllocNonPaged(0xe0);
  if (lVar5 == 0) {
    return 0x59;
  }
  portMemSet(lVar5,0,0xe0);
  *(undefined4 *)(lVar5 + 4) = 0xffffffff;
  *(undefined8 *)(lVar5 + 0x18) = 0;
  *(ulong *)(lVar5 + 0x10) = param_3;
  lVar6 = (param_3 + param_4) - 1;
  *(undefined8 *)(lVar5 + 0x20) = 0;
  *(long *)(lVar5 + 0x28) = lVar6;
  *(long *)(lVar5 + 0xa8) = lVar5;
  *(long *)(lVar5 + 0xb0) = lVar5;
  *(long *)(lVar5 + 0xc0) = lVar5;
  *(long *)(lVar5 + 0xb8) = lVar5;
  *(undefined8 *)(lVar5 + 0x30) = 0;
  *(long *)(param_2 + 0x88) = lVar5;
  *(long *)(param_2 + 0x90) = lVar5;
  *(undefined8 *)(param_2 + 0x98) = 0;
  portMemSet(param_2 + 0xa0,0,0x30);
  iVar4 = (**(code **)(lVar2 + 0x1e0))(param_1,lVar2,param_2 + 0x100);
  if (iVar4 != 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x1f0,"heapInitInternal_IMPL",4,
                 "NVRM: Heap Manager unable to get bank placement policy from HAL.\n");
    nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x1f2,"heapInitInternal_IMPL",4,
                 "NVRM: Heap Manager defaulting to BAD placement policy.\n");
    *(undefined8 *)(param_2 + 0x100) = 0xffffffc0ffffff00;
    *(undefined8 *)(param_2 + 0x108) = 0xffffffc0ffffffc0;
  }
  *(undefined8 *)(param_2 + 0xd0) = 0;
  iVar4 = _heapUpdate(param_2,lVar5,0);
  if (iVar4 != 0) {
    return 0x40;
  }
  if ((*(int *)(lVar2 + 0x858) == 0) || (*(char *)(param_2 + 0x60) == '\0')) {
    if (param_5 != 2) goto LAB_003acfd2;
LAB_003ad0e2:
    if (*(char *)(lVar2 + 0x434) != '\0') {
      local_40[0] = 0;
      uVar3 = gpuIsCCFeatureEnabled_IMPL(param_1);
      iVar4 = heapReserveRegion_constprop_0(lVar2,param_2,param_3,param_4,local_40,0,uVar3);
      if ((iVar4 != 0) || (local_40[0] == 0)) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x27f,"heapInitInternal_IMPL",4,
                     "NVRM: failed to reserve %llx..%llx\n",param_3,lVar6);
        return iVar4;
      }
    }
  }
  else {
    if ((*(char *)(lVar2 + 0x433) == '\0') || (*(char *)(lVar2 + 0x432) == '\0')) {
      if (param_5 == 2) goto LAB_003ad0e2;
    }
    else {
      if (param_5 == 2) goto LAB_003ad0e2;
      *(undefined1 *)(lVar2 + 0x434) = 1;
      memmgrRegionSetupForPma_IMPL(param_1,lVar2);
      if (*(int *)(lVar2 + 0x858) == 0) goto LAB_003acfd2;
    }
    puVar7 = (ulong *)(lVar2 + 0x860);
    uVar8 = 0;
    do {
      if (((char)puVar7[3] != '\0') ||
         ((*(char *)(lVar2 + 0x434) != '\0' && (*(char *)((long)puVar7 + 0x23) == '\0')))) {
        uVar9 = *puVar7;
        local_40[0] = 0;
        if (((param_3 <= uVar9) || (param_3 <= puVar7[1])) &&
           ((*(char *)(param_1 + 0x4913) == '\0' || (uVar9 < param_3 + param_4)))) {
          if (uVar9 < param_3) {
            uVar9 = param_3;
          }
          nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x247,"heapInitInternal_IMPL",1,
                       "NVRM: Reserve at %llx of size %llx\n",uVar9,(puVar7[1] + 1) - uVar9);
          iVar4 = heapReserveRegion_constprop_0
                            (lVar2,param_2,uVar9,(puVar7[1] + 1) - uVar9,local_40,(char)puVar7[3]);
          lVar5 = local_40[0];
          if ((iVar4 != 0) || (local_40[0] == 0)) {
            lVar2 = lVar2 + (ulong)uVar8 * 0x28;
            nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x255,"heapInitInternal_IMPL",4,
                         "NVRM: failed to reserve %llx..%llx\n",*(undefined8 *)(lVar2 + 0x860),
                         *(undefined8 *)(lVar2 + 0x868));
            return iVar4;
          }
          if (*(char *)((long)puVar7 + 0x24) == '\0') {
            cVar1 = *(char *)((long)puVar7 + 0x25);
          }
          else {
            memdescSetFlag(local_40[0],4,1);
            cVar1 = *(char *)((long)puVar7 + 0x25);
          }
          if (cVar1 != '\0') {
            memdescSetFlag(lVar5,0x4000,1);
          }
        }
      }
      uVar8 = uVar8 + 1;
      puVar7 = puVar7 + 5;
    } while (uVar8 < *(uint *)(lVar2 + 0x858));
  }
LAB_003acfd2:
  if (local_60 != 0) {
    memdescAddRef(local_60);
    return 0;
  }
  return 0;
}


// ===== 003ad200 heapAlloc_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
heapAlloc_IMPL(long param_1,int param_2,long param_3,long *param_4,undefined4 param_5,ulong *param_6
              ,long param_7,long *param_8,char *param_9,char param_10,char param_11)

{
  long lVar1;
  char *pcVar2;
  bool bVar3;
  char *pcVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined8 uVar9;
  ulong uVar10;
  uint uVar11;
  ulong uVar12;
  uint uVar13;
  ulong uVar14;
  long lVar15;
  ulong uVar16;
  ulong uVar17;
  byte bVar18;
  long lVar19;
  ulong uVar20;
  ulong uVar21;
  int *piVar22;
  uint uVar23;
  long lVar24;
  ulong uVar25;
  undefined4 uVar26;
  int *piVar27;
  long lVar28;
  ulong uVar29;
  bool bVar30;
  int local_124;
  ulong local_118;
  uint local_10c;
  ulong local_f8;
  ulong local_e0;
  uint local_d8;
  char local_c6;
  char local_c5;
  char *local_c0;
  ulong local_b8;
  char *local_a8;
  ulong local_a0;
  ulong local_90;
  ulong local_88;
  ulong local_80;
  undefined8 *local_70;
  char *local_68;
  undefined8 local_60;
  undefined8 local_58;
  char *local_50;
  undefined1 local_48 [8];
  undefined8 local_40 [2];
  
  local_70 = (undefined8 *)param_4[4];
  lVar1 = *param_4;
  lVar28 = *(long *)(param_1 + 0x1b78);
  local_b8 = *(ulong *)(param_7 + 0x38);
  local_68 = (char *)0x0;
  lVar24 = *(long *)(param_7 + 0x18);
  lVar15 = *(long *)(param_7 + 0x28);
  local_60 = 0;
  local_58 = 0;
  iVar6 = memmgrAllocGetAddrSpace_IMPL
                    (lVar28,*(undefined4 *)(lVar1 + 8),*(undefined4 *)(lVar1 + 0x18));
  if ((iVar6 != 2) ||
     (uVar7 = gpumgrGetSubDeviceInstanceFromGpu(param_1), param_4[(ulong)uVar7 + 5] != 0)) {
    nvAssertFailedNoLog("(memmgrAllocGetAddrSpace(GPU_GET_MEMORY_MANAGER(pGpu), pVidHeapAlloc->flags, pVidHeapAlloc->attr) == ADDR_FBMEM) && (pAllocRequest->pPmaAllocInfo[gpumgrGetSubDeviceInstanceFromGpu(pGpu)] == NULL)"
                        ,"src/kernel/gpu/mem_mgr/heap.c",0x55f);
    return 0x1f;
  }
  uVar7 = *(uint *)(lVar1 + 8);
  uVar23 = uVar7 & 0x10;
  if (uVar23 != 0) {
    local_b8 = local_b8 - *(long *)(param_7 + 0x28);
  }
  local_c5 = *(char *)(param_1 + 0x457);
  if (local_c5 != '\0') {
    cVar5 = (**(code **)(param_1 + 0x2f0))(param_1);
    if (cVar5 == '\0') {
      uVar7 = *(uint *)(lVar1 + 8);
      uVar23 = uVar7 & 0x10;
      local_c5 = '\0';
    }
    else if ((*(byte *)(lVar1 + 0x1e) & 8) == 0) {
      uVar7 = *(uint *)(lVar1 + 8);
      local_c5 = '\0';
      uVar23 = uVar7 & 0x10;
    }
    else {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x56c,"heapAlloc_IMPL",1,
                   "NVRM: Trying to turn blacklisting pages off for this allocation of size: %llx\n"
                  );
      cVar5 = hypervisorIsVgxHyper_IMPL();
      if (cVar5 == '\0') {
        uVar9 = *(undefined8 *)(lVar1 + 0x40);
        uVar20 = local_b8;
      }
      else {
        uVar9 = *(undefined8 *)(param_3 + 0x70);
        uVar20 = *(ulong *)(param_3 + 0x68);
      }
      _heapFreeBlacklistPages_isra_0(lVar28,param_3 + 0xe8,uVar20,uVar9);
      uVar7 = *(uint *)(lVar1 + 8);
      local_c5 = '\x01';
      uVar23 = uVar7 & 0x10;
    }
  }
  uVar20 = *(ulong *)(lVar1 + 0x30);
  uVar12 = *(ulong *)(lVar1 + 0x38);
  if (uVar20 == 0 && uVar12 == 0) {
    uVar12 = (*(long *)(param_3 + 0x70) + *(long *)(param_3 + 0x68)) - 1;
    *(ulong *)(lVar1 + 0x38) = uVar12;
  }
  uVar14 = (*(long *)(param_3 + 0x70) + *(long *)(param_3 + 0x68)) - 1;
  if (uVar14 < uVar12) {
    *(ulong *)(lVar1 + 0x38) = uVar14;
    uVar12 = uVar14;
  }
  if (uVar23 == 0) {
    uVar14 = *(ulong *)(lVar28 + 0xb90);
    if (uVar14 == 0) {
      if (*(ulong *)(lVar28 + 0xb98) < uVar12) {
        uVar12 = *(ulong *)(lVar28 + 0xb98);
      }
      *(ulong *)(lVar1 + 0x38) = uVar12;
      goto LAB_003ad39f;
    }
    if (uVar14 <= uVar20) {
      uVar14 = uVar20;
    }
    *(ulong *)(lVar1 + 0x30) = uVar14;
    if (uVar14 <= uVar12) {
LAB_003ad3c5:
      uVar7 = uVar7 | 1;
      *(uint *)(lVar1 + 8) = uVar7;
      goto LAB_003ad3cd;
    }
  }
  else {
LAB_003ad39f:
    if (uVar20 <= uVar12) {
      if ((uVar20 != 0) || (uVar12 < (*(long *)(param_3 + 0x70) + *(long *)(param_3 + 0x68)) - 1U))
      goto LAB_003ad3c5;
LAB_003ad3cd:
      uVar23 = *(uint *)(lVar1 + 4);
      uVar13 = 0;
      lVar24 = lVar24 - lVar15;
      if (uVar23 != 8) {
        if (uVar23 < 0x12) {
          lVar15 = 0;
          uVar20 = 1L << ((byte)uVar23 & 0x3f);
          if ((((uVar20 & 0x22001) == 0) && (lVar15 = 1, (uVar20 & 0x10202) == 0)) &&
             (lVar15 = 3, (uVar20 & 0x1c) != 0)) {
            lVar15 = 2;
          }
        }
        else {
          lVar15 = 3;
        }
        uVar13 = *(uint *)(param_3 + 0x100 + lVar15 * 4);
      }
      if ((uVar7 & 0x40) != 0) {
        uVar13 = uVar7 & 0x200;
        uVar7 = uVar7 & 0xffffffdf;
        *(uint *)(lVar1 + 8) = uVar7;
        uVar13 = (-(uint)(uVar13 == 0) & 0xffffffc0) - 0xc0;
      }
      local_c0 = (char *)0x0;
      if ((uVar7 & 2) == 0) {
        uVar11 = uVar7;
        if ((uVar7 & 4) != 0) goto LAB_003ad70b;
        if ((uVar7 & 0x10) != 0) goto LAB_003ad473;
        if ((uVar7 & 1) != 0) goto LAB_003add22;
        if ((uVar23 == 2) && (uVar7 == 0)) {
          bVar30 = false;
          uVar23 = 0;
          local_d8 = 0xffffffff;
          uVar12 = 0;
          piVar27 = (int *)(param_3 + 0xa0);
          uVar20 = 0xffffffff;
          piVar22 = piVar27;
          uVar7 = uVar13;
          do {
            if (param_2 == *piVar22) {
              uVar7 = (uint)*(byte *)(piVar22 + 2);
              bVar30 = true;
              local_d8 = (uint)uVar12;
            }
            uVar23 = (uVar23 + 1) - (uint)(*piVar22 == 0);
            if (*(char *)((long)piVar22 + 9) == '\x01') {
              uVar20 = uVar12;
            }
            uVar11 = (uint)uVar12 + 1;
            uVar12 = (ulong)uVar11;
            piVar22 = piVar22 + 3;
          } while (uVar11 != 4);
          if (uVar23 < 2) {
            bVar3 = false;
            if (bVar30) goto LAB_003ae37a;
          }
          else {
            if (bVar30) goto LAB_003ad72c;
            bVar3 = true;
          }
          uVar12 = 0;
          do {
            iVar6 = *piVar27;
            piVar27 = piVar27 + 3;
            local_d8 = (uint)uVar12;
            iVar8 = (int)uVar20;
            if (iVar6 == 0) {
              lVar15 = param_3 + uVar12 * 0xc;
              *(int *)(lVar15 + 0xa0) = param_2;
              if (iVar8 != -1) goto LAB_003ae8d6;
              *(char *)(lVar15 + 0xa8) = (char)uVar7;
              *(undefined1 *)(lVar15 + 0xa9) = 1;
              if (bVar3) goto LAB_003ae9a3;
              uVar7 = *(uint *)(lVar1 + 8);
              goto LAB_003ad6ef;
            }
            uVar12 = (ulong)(local_d8 + 1);
          } while (local_d8 + 1 != 4);
          uVar12 = (ulong)(iVar8 + 1U & 3);
          local_d8 = iVar8 + 1U & 3;
          lVar15 = param_3 + uVar12 * 0xc;
          *(int *)(lVar15 + 0xa0) = param_2;
          *(undefined1 *)(lVar15 + 0xa9) = 1;
          *(undefined1 *)(param_3 + 0xa9 + uVar20 * 0xc) = 0;
          *(undefined4 *)(lVar15 + 0xa4) = 0;
          uVar7 = ~(uint)*(byte *)(param_3 + 0xa8 + uVar20 * 0xc) & 0xffffff80;
          *(char *)(lVar15 + 0xa8) = (char)uVar7;
          if (param_2 == 0) {
            *(undefined4 *)(lVar15 + 0xa0) = 0;
            if (iVar8 == -1) {
              *(undefined1 *)(param_3 + 0xa9) = 1;
              local_d8 = 0;
LAB_003ae9a3:
              uVar7 = uVar7 & 0xffffff80;
            }
            else {
LAB_003ae8d6:
              bVar18 = *(byte *)(param_3 + 0xa8 + uVar20 * 0xc);
              *(undefined1 *)(param_3 + 0xa9 + uVar20 * 0xc) = 0;
              *(undefined1 *)(param_3 + 0xa9 + uVar12 * 0xc) = 1;
              uVar7 = ~(uint)bVar18 & 0xffffff80;
              *(char *)(param_3 + 0xa8 + uVar12 * 0xc) = (char)uVar7;
            }
          }
        }
        else {
          local_d8 = 0xffffffff;
LAB_003ad6ef:
          if ((uVar7 & 0x20) == 0) {
LAB_003ae37a:
            uVar7 = uVar13 * 2 & 0xffffff80;
          }
          else {
            *(uint *)(lVar1 + 8) = uVar7 & 0xffffffdf;
            uVar7 = (uVar7 >> 9) << 7;
          }
        }
LAB_003ad72c:
        lVar15 = *(long *)(param_3 + 0x90);
        if (lVar15 == 0) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x62d,"heapAlloc_IMPL",4,
                       "NVRM: no free blocks\n");
          local_c0 = (char *)0x0;
          uVar9 = 0;
        }
        else {
          if (*param_9 == '\0') {
            uVar23 = 0;
            uVar20 = *(ulong *)(lVar1 + 0x30);
            uVar9 = *(undefined8 *)(lVar1 + 0x38);
LAB_003ad770:
            if ((*(char *)(lVar28 + 0x431) == '\0') || (*(char *)(param_1 + 0x4921) != '\0')) {
              bVar30 = true;
              uVar12 = uVar20;
            }
            else {
              if (*(int *)(lVar28 + 0xae0) == 0) {
                nvAssertFailedNoLog("pMemoryManager->Ram.numFBRegionPriority > 0",
                                    "src/kernel/gpu/mem_mgr/heap.c",0x64a);
                uVar7 = uVar7 & 0xff;
              }
              uVar13 = *(uint *)(*(long *)(param_7 + 0x90) + 4) & 0x3000;
              if ((uVar13 == 0x2000) || ((*(char *)(lVar28 + 0x439) != '\0' && (uVar13 != 0x1000))))
              {
                uVar13 = *(uint *)(lVar28 + 0xaf8 + (ulong)(~uVar23 + *(int *)(lVar28 + 0xae0)) * 4)
                ;
                if (*(uint *)(lVar28 + 0x858) <= uVar13) {
                  nvAssertFailedNoLog("pMemoryManager->Ram.fbRegionPriority[pMemoryManager->Ram.numFBRegionPriority-1-i] < pMemoryManager->Ram.numFBRegions"
                                      ,"src/kernel/gpu/mem_mgr/heap.c",0x650);
                  uVar7 = uVar7 & 0xff;
                  uVar13 = *(uint *)(lVar28 + 0xaf8 +
                                    (ulong)(~uVar23 + *(int *)(lVar28 + 0xae0)) * 4);
                }
                uVar12 = (ulong)uVar13;
                if (*(char *)(lVar28 + 0x878 + uVar12 * 0x28) != '\0') {
                  nvAssertFailedNoLog("!pMemoryManager->Ram.fbRegion[pMemoryManager->Ram.fbRegionPriority[pMemoryManager->Ram.numFBRegionPriority-1-i]].bRsvdRegion"
                                      ,"src/kernel/gpu/mem_mgr/heap.c",0x651);
                  uVar7 = uVar7 & 0xff;
                  uVar12 = (ulong)*(uint *)(lVar28 + 0xaf8 +
                                           (ulong)(~uVar23 + *(int *)(lVar28 + 0xae0)) * 4);
                }
                uVar12 = *(ulong *)(lVar28 + 0x860 + uVar12 * 0x28);
                if (uVar12 < *(ulong *)(lVar1 + 0x30)) {
                  uVar12 = *(ulong *)(lVar1 + 0x30);
                }
                *(ulong *)(lVar1 + 0x30) = uVar12;
                uVar13 = *(uint *)(lVar28 + 0xaf8 + (ulong)(~uVar23 + *(int *)(lVar28 + 0xae0)) * 4)
                ;
              }
              else {
                uVar14 = (ulong)uVar23;
                uVar13 = *(uint *)(lVar28 + 8 + (uVar14 + 700) * 4);
                if (*(uint *)(lVar28 + 0x858) <= uVar13) {
                  nvAssertFailedNoLog("pMemoryManager->Ram.fbRegionPriority[i] < pMemoryManager->Ram.numFBRegions"
                                      ,"src/kernel/gpu/mem_mgr/heap.c",0x65c);
                  uVar13 = *(uint *)(lVar28 + 8 + (uVar14 + 700) * 4);
                  uVar7 = uVar7 & 0xff;
                }
                uVar12 = (ulong)uVar13;
                if (*(char *)(lVar28 + 0x878 + uVar12 * 0x28) != '\0') {
                  nvAssertFailedNoLog("!pMemoryManager->Ram.fbRegion[pMemoryManager->Ram.fbRegionPriority[i]].bRsvdRegion"
                                      ,"src/kernel/gpu/mem_mgr/heap.c",0x65d);
                  uVar7 = uVar7 & 0xff;
                  uVar12 = (ulong)*(uint *)(lVar28 + 0xaf8 + uVar14 * 4);
                }
                uVar12 = *(ulong *)(lVar28 + 0x860 + uVar12 * 0x28);
                if (uVar12 < *(ulong *)(lVar1 + 0x30)) {
                  uVar12 = *(ulong *)(lVar1 + 0x30);
                }
                *(ulong *)(lVar1 + 0x30) = uVar12;
                uVar13 = *(uint *)(lVar28 + 0xaf8 + uVar14 * 4);
              }
              uVar14 = *(ulong *)(lVar28 + 0x868 + (ulong)uVar13 * 0x28);
              if (*(ulong *)(lVar1 + 0x38) < uVar14) {
                uVar14 = *(ulong *)(lVar1 + 0x38);
              }
              uVar23 = uVar23 + 1;
              *(ulong *)(lVar1 + 0x38) = uVar14;
              bVar30 = *(uint *)(lVar28 + 0xae0) <= uVar23;
            }
            if (-1 < (char)uVar7) {
              lVar15 = *(long *)(lVar15 + 0xa8);
            }
            lVar19 = lVar15;
            if ((char)uVar7 < '\0') goto LAB_003ad922;
            do {
              lVar19 = *(long *)(lVar19 + 0xb0);
              uVar14 = *(ulong *)(lVar19 + 0x28);
              if (uVar14 < uVar12) {
                do {
                  if (lVar15 == lVar19) goto LAB_003ad960;
                  lVar19 = *(long *)(lVar19 + 0xb0);
                  uVar12 = *(ulong *)(lVar1 + 0x30);
                  uVar14 = *(ulong *)(lVar19 + 0x28);
                } while (uVar14 < uVar12);
              }
              while( true ) {
                uVar21 = *(ulong *)(lVar19 + 0x10);
                uVar25 = *(ulong *)(lVar1 + 0x38);
                if (uVar21 <= uVar25) {
                  if ((char)uVar7 < '\0') {
                    if (uVar25 <= uVar14) {
                      uVar14 = uVar25;
                    }
                    uVar21 = uVar14 + (1 - param_6[4]);
                  }
                  else {
                    if (uVar21 < uVar12) {
                      uVar21 = uVar12;
                    }
                    uVar21 = (*param_6 - 1) + uVar21;
                  }
                  uVar21 = uVar21 - uVar21 % *param_6;
                  uVar12 = (uVar21 - 1) + param_6[4];
                  param_6[1] = uVar21;
                  param_6[2] = uVar21;
                  param_6[3] = uVar12;
                  if ((((*(ulong *)(lVar19 + 0x10) <= uVar21) &&
                       (uVar12 <= *(ulong *)(lVar19 + 0x28))) && (uVar21 <= uVar12)) &&
                     ((*(ulong *)(lVar1 + 0x30) <= uVar21 && (uVar12 <= *(ulong *)(lVar1 + 0x38)))))
                  {
                    cVar5 = _isAllocValidForFBRegion_isra_0(param_1,param_7,param_6);
                    uVar7 = uVar7 & 0xff;
                    if (cVar5 != '\0') {
                      *(ulong *)(lVar1 + 0x30) = uVar20;
                      *(undefined8 *)(lVar1 + 0x38) = uVar9;
                      goto LAB_003ad513;
                    }
                  }
                }
                if (lVar15 == lVar19) goto LAB_003ad960;
                uVar12 = *(ulong *)(lVar1 + 0x30);
                if (-1 < (char)uVar7) break;
LAB_003ad922:
                lVar19 = *(long *)(lVar19 + 0xa8);
                uVar14 = *(ulong *)(lVar19 + 0x28);
                if (uVar14 < uVar12) {
                  do {
                    if (lVar15 == lVar19) goto LAB_003ad960;
                    lVar19 = *(long *)(lVar19 + 0xa8);
                    uVar12 = *(ulong *)(lVar1 + 0x30);
                    uVar14 = *(ulong *)(lVar19 + 0x28);
                  } while (uVar14 < uVar12);
                }
              }
            } while( true );
          }
          nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x633,"heapAlloc_IMPL",1,
                       "NVRM: non-contig vidmem requested\n");
LAB_003ad97c:
          if (param_10 == '\0') {
LAB_003adc34:
            uVar9 = 0;
          }
          else {
            if (*param_9 == '\0') {
              nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x6c2,"heapAlloc_IMPL",1,
                           "NVRM: Contig vidmem allocation failed, running noncontig allocator\n");
              memdescDestroy(param_4[4]);
              iVar6 = memdescCreate(param_4 + 4,param_1,lVar24,0,0,2,1,0);
              if (iVar6 != 0) {
                nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x6ce,"heapAlloc_IMPL",4,
                             "NVRM: cannot alloc memDesc!\n");
                param_4[4] = 0;
                goto LAB_003adc34;
              }
              local_70 = (undefined8 *)param_4[4];
              local_70[0x14] = param_3;
              memdescSetPteKindForGpu(local_70,*local_70,*(undefined4 *)(param_7 + 0x4c));
              *(undefined4 *)(local_70 + 0x13) = *(undefined4 *)(param_7 + 4);
            }
            lVar28 = *(long *)(param_1 + 0x1b98);
            lVar24 = *param_4;
            uVar7 = dmaNvos32ToPageSizeAttr
                              (*(undefined4 *)(param_7 + 0x44),*(undefined4 *)(param_7 + 0x48));
            lVar15 = local_70[6];
            if (uVar7 == 3) {
              local_f8 = 0xffffffffffe00000;
              uVar20 = 0x800;
              local_90 = 0x200000;
              if (*(char *)(lVar28 + 0x67d0) != '\0') goto LAB_003add61;
              nvAssertFailedNoLog("kgmmuIsHugePageSupported(pKernelGmmu)",
                                  "src/kernel/gpu/mem_mgr/heap.c",0xcd7);
LAB_003adab2:
              uVar9 = 0;
            }
            else {
              if (uVar7 < 4) {
                if (uVar7 == 1) {
                  local_f8 = 0xfffffffffffff000;
                  uVar20 = 4;
                  local_90 = 0x1000;
                }
                else {
                  if (uVar7 != 2) {
LAB_003ada8c:
                    nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xccb,"_heapAllocNoncontig",4,
                                 "NVRM: Invalid page size attribute!\n");
                    goto LAB_003adab2;
                  }
                  local_90 = (**(code **)(lVar28 + 0x198))(lVar28);
                  uVar20 = local_90 >> 10;
                  local_f8 = -local_90;
                }
              }
              else if (uVar7 == 4) {
                local_f8 = 0xffffffffe0000000;
                uVar20 = 0x80000;
                local_90 = 0x20000000;
                if (*(char *)(lVar28 + 0x67d1) == '\0') {
                  nvAssertFailedNoLog("kgmmuIsPageSize512mbSupported(pKernelGmmu)",
                                      "src/kernel/gpu/mem_mgr/heap.c",0xcde);
                  goto LAB_003adab2;
                }
              }
              else {
                if (uVar7 - 5 < 2) goto LAB_003ada8c;
                local_f8 = 0;
                uVar20 = 0;
                local_90 = 0;
              }
LAB_003add61:
              if (*(char *)(g_pSys + 400) == '\0') {
                uVar7 = 0x1000;
                local_118 = lVar15 + 0xfffU & 0xfffffffffffff000;
                uVar12 = 0x1000;
              }
              else {
                uVar7 = (uint)local_90;
                local_118 = (local_90 - 1) + local_70[6] & local_f8;
                uVar12 = local_90;
              }
              local_e0 = ((local_90 - 1) + param_6[4] & local_f8) / local_90;
              nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xcf1,"_heapAllocNoncontig",1,
                           "NVRM: pageSize: 0x%llx, numPagesLeft: 0x%llx, allocSize: 0x%llx\n",
                           uVar20,local_e0);
              if ((0 < (long)local_e0) && (*(long *)(param_3 + 0xd0) != 0)) {
                uVar20 = 0;
                local_a8 = (char *)0x0;
                local_c6 = '\x01';
                local_10c = 1;
                local_124 = 0;
                lVar28 = *(long *)(param_3 + 0xd0);
                do {
                  cVar5 = local_c6;
                  uVar25 = local_e0;
                  uVar14 = *(ulong *)(lVar24 + 0x30);
                  lVar15 = *(long *)(lVar28 + 200);
                  uVar21 = *(ulong *)(lVar28 + 0x28);
                  if (uVar14 <= uVar21) {
                    uVar10 = *(ulong *)(lVar28 + 0x10);
                    uVar17 = *(ulong *)(lVar24 + 0x38);
                    if (uVar10 <= uVar17) {
                      if (uVar14 < uVar10) {
                        uVar14 = uVar10;
                      }
                      if (uVar17 < uVar21) {
                        uVar21 = uVar17;
                      }
                      if ((uVar14 < uVar21) && (local_90 <= (uVar21 + 1) - uVar14)) {
                        local_a0 = uVar21 + 1 & local_f8;
                        uVar14 = uVar14 + (local_90 - 1) & local_f8;
                        local_80 = local_a0 - 1;
                        if (uVar14 < local_80) {
                          local_88 = uVar14;
                          if (local_c6 != '\0') {
                            local_88 = (uVar14 - 1) + *param_6;
                            local_88 = local_88 - local_88 % *param_6;
                            if (local_80 < *(long *)(param_7 + 0x28) + local_88) goto LAB_003adeb0;
                            uVar14 = local_88 & local_f8;
                          }
                          local_a0 = local_a0 - uVar14;
                          if (local_90 <= local_a0) {
                            local_a0 = local_a0 / local_90;
                            if (local_e0 < local_a0) {
                              local_e0 = 0;
                              local_a0 = uVar25;
                              local_80 = (uVar14 - 1) + local_90 * uVar25;
                              uVar21 = 0;
                            }
                            else {
                              local_e0 = local_e0 - local_a0;
                              uVar21 = 0;
                              if (-1 < (long)local_e0) {
                                uVar21 = local_e0;
                              }
                            }
                            uVar25 = (local_80 - uVar14) + 1;
                            nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xd5f,"_heapAllocNoncontig"
                                         ,1,
                                         "NVRM: \tblockId: %d, blockBegin: 0x%llx, blockEnd: 0x%llx, blockSize: 0x%llx, blockSizeInPages: 0x%llx, numPagesLeft: 0x%llx\n"
                                         ,local_124,uVar14,local_80,uVar25,local_a0,uVar21);
                            param_6[3] = local_80;
                            param_6[1] = uVar14;
                            param_6[2] = local_88;
                            param_6[4] = uVar25;
                            uVar9 = 0;
                            if (local_c6 != '\0') {
                              uVar9 = *(undefined8 *)(param_7 + 0x28);
                            }
                            iVar6 = _heapProcessFreeBlock_isra_0
                                              (param_1,lVar28,&local_50,local_48,param_3,*param_4,
                                               param_5,param_6,param_7,uVar9,local_40);
                            pcVar2 = local_50;
                            if (iVar6 != 0) {
                              nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xd82,
                                           "_heapAllocNoncontig",4,
                                           "NVRM: ERROR: Could not process free block, error: 0x%x\n"
                                          );
                              goto joined_r0x003ae619;
                            }
                            local_124 = local_124 + 1;
                            _heapUpdate(param_3,local_50,3);
                            pcVar4 = pcVar2;
                            if (local_c0 != (char *)0x0) {
                              *(char **)(local_a8 + 0xd8) = pcVar2;
                              pcVar4 = local_c0;
                            }
                            local_c0 = pcVar4;
                            uVar14 = *(ulong *)(pcVar2 + 0x10);
                            pcVar2[0xd8] = '\0';
                            pcVar2[0xd9] = '\0';
                            pcVar2[0xda] = '\0';
                            pcVar2[0xdb] = '\0';
                            pcVar2[0xdc] = '\0';
                            pcVar2[0xdd] = '\0';
                            pcVar2[0xde] = '\0';
                            pcVar2[0xdf] = '\0';
                            uVar21 = (local_118 - uVar20 * uVar12) / local_90;
                            if (uVar21 <= local_a0) {
                              local_a0 = uVar21;
                            }
                            if (*(char *)(param_3 + 0x49) != '\0') {
                              uVar23 = *(uint *)(param_3 + 0x124);
                              uVar21 = (ulong)uVar23;
                              local_10c = *(uint *)(param_3 + 0x110 + uVar21 * 4);
                              if (local_a0 < local_10c) {
                                uVar25 = (ulong)local_10c;
                                do {
                                  local_10c = (uint)uVar25;
                                  if ((int)uVar21 == 0) break;
                                  uVar21 = (ulong)((int)uVar21 - 1);
                                  local_10c = *(uint *)(param_3 + 0x110 + uVar21 * 4);
                                  uVar25 = (ulong)local_10c;
                                } while (local_a0 < uVar25);
                              }
                              *(uint *)(param_3 + 0x124) = uVar23 + 1 + ((uVar23 + 1) / 5) * -5;
                            }
                            uVar21 = (ulong)local_10c;
                            if (local_10c != 0) {
                              uVar14 = uVar14 & 0xfffffffffffff000;
                              uVar25 = 0;
                              do {
                                if (uVar25 < local_a0) {
                                  uVar10 = uVar25;
                                  uVar17 = uVar14;
                                  do {
                                    if (uVar12 <= local_90) {
                                      uVar16 = 0;
                                      uVar29 = uVar17;
                                      do {
                                        uVar23 = (int)uVar20 + 1;
                                        memdescSetPte(local_70,1,uVar20,uVar29);
                                        uVar16 = (ulong)((int)uVar16 + 1);
                                        uVar20 = (ulong)uVar23;
                                        uVar29 = uVar29 + uVar12;
                                      } while (uVar16 < local_90 / uVar12);
                                      uVar20 = (ulong)uVar23;
                                    }
                                    uVar10 = uVar10 + uVar21;
                                    uVar17 = uVar17 + local_90 * uVar21;
                                  } while (uVar10 < local_a0);
                                }
                                uVar25 = uVar25 + 1;
                                uVar14 = uVar14 + local_90;
                              } while (uVar21 != uVar25);
                            }
                            if ((*(int *)(lVar24 + 4) == 2) && (local_d8 != 0xffffffff)) {
                              *(int *)(pcVar2 + 0x30) = param_2;
                              if (local_c6 != '\0') {
                                piVar27 = (int *)(param_3 + 0xa4 + (ulong)local_d8 * 0xc);
                                *piVar27 = *piVar27 + 1;
LAB_003ae78d:
                                *(undefined8 *)(param_7 + 0x38) = local_40[0];
                                *param_8 = (long)(pcVar2 + 0x88);
                              }
                            }
                            else {
                              pcVar2[0x30] = '\0';
                              pcVar2[0x31] = '\0';
                              pcVar2[0x32] = '\0';
                              pcVar2[0x33] = '\0';
                              if (local_c6 != '\0') goto LAB_003ae78d;
                            }
                            *(undefined8 **)(pcVar2 + 0x80) = local_70;
                            local_c6 = '\0';
                            *pcVar2 = cVar5;
                            local_a8 = pcVar2;
                          }
                        }
                      }
                    }
                  }
LAB_003adeb0:
                } while ((0 < (long)local_e0) && (lVar28 = lVar15, lVar15 != 0));
              }
              iVar6 = 0;
              if (0 < (long)local_e0) {
                nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xdf1,"_heapAllocNoncontig",1,
                             "NVRM: Could not satisfy request: allocSize: 0x%llx\n",param_6[4]);
                iVar6 = 0x51;
joined_r0x003ae619:
                while (local_c0 != (char *)0x0) {
                  pcVar2 = *(char **)(local_c0 + 0xd8);
                  iVar8 = _heapBlockFree(param_1,param_3,param_2,*(undefined4 *)(param_7 + 0x9c),
                                         local_c0);
                  local_c0 = pcVar2;
                  if (iVar8 != 0) {
                    nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xe03,"_heapAllocNoncontig",4,
                                 "NVRM: ERROR: Could not free block,  error 0x%x!\n",iVar8);
                  }
                }
              }
              bVar18 = 0xc;
              if (uVar7 != 0x1000) {
                cVar5 = memdescGetContiguity(local_70,0);
                if (cVar5 == '\0') {
                  bVar18 = (0xffff < uVar7) << 4 | (uVar7 & 0xaaaaaaaa) != 0 |
                           ((uVar7 & 0xff00ff00) != 0) << 3 | ((uVar7 & 0xf0f0f0f0) != 0) << 2 |
                           ((uVar7 & 0xcccccccc) != 0) * '\x02';
                }
                else {
                  uVar7 = 0x1000;
                }
              }
              if (((*(byte *)((long)local_70 + 9) & 4) == 0) &&
                 ((ulong)local_70[4] < local_118 >> bVar18)) {
                nvAssertOkFailedNoLog
                          (2,
                           "memdescSetAllocSizeFields(pMemDesc, alignedSize, pageArrayGranularity)",
                           "src/kernel/gpu/mem_mgr/heap.c",0xe0c);
                local_c0 = local_68;
                uVar9 = local_60;
              }
              else {
                local_70[3] = local_118 >> bVar18;
                *(uint *)(local_70 + 0x2c) = uVar7;
                local_70[7] = local_118;
                if (iVar6 == 0) {
                  *param_9 = '\x01';
                  uVar26 = 0;
                  goto LAB_003ad67b;
                }
                local_c0 = local_68;
                uVar9 = local_60;
              }
            }
            nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x6f2,"heapAlloc_IMPL",1,
                         "NVRM: failed to allocate block.  Heap total=0x%llx free=0x%llx\n",
                         *(undefined8 *)(param_3 + 0x70),*(undefined8 *)(param_3 + 0x78));
          }
        }
      }
      else {
        uVar13 = uVar13 & 0xffffff7f;
        uVar11 = uVar7 | 1;
        *(uint *)(lVar1 + 8) = uVar11;
        if ((uVar7 & 4) == 0) {
          if ((uVar7 & 0x10) == 0) {
LAB_003add22:
            local_d8 = 0xffffffff;
            uVar7 = uVar13;
            goto LAB_003ad72c;
          }
        }
        else {
LAB_003ad70b:
          *(uint *)(lVar1 + 8) = uVar11 | 1;
          if ((uVar11 & 0x10) == 0) {
            local_d8 = 0xffffffff;
            uVar7 = uVar13 | 0xffffff80;
            goto LAB_003ad72c;
          }
        }
LAB_003ad473:
        if (local_b8 % *param_6 != 0) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x5d9,"heapAlloc_IMPL",4,
                       "NVRM: offset 0x%llx not aligned to 0x%llx\n",local_b8,*param_6);
          goto LAB_003adc34;
        }
        lVar19 = *(long *)(param_3 + 0x90);
        if (lVar19 != 0) {
LAB_003ad4cd:
          lVar19 = *(long *)(lVar19 + 0xb0);
          if ((local_b8 < *(ulong *)(lVar19 + 0x10)) ||
             (uVar20 = (local_b8 - 1) + param_6[4], *(ulong *)(lVar19 + 0x28) < uVar20))
          goto LAB_003ad4c0;
          param_6[1] = local_b8;
          param_6[3] = uVar20;
          param_6[2] = local_b8;
          cVar5 = _isAllocValidForFBRegion_isra_0(param_1,param_7,param_6);
          if (cVar5 == '\0') goto LAB_003ad4c0;
          local_d8 = 0xffffffff;
LAB_003ad513:
          iVar6 = _heapProcessFreeBlock_isra_0
                            (param_1,lVar19,&local_68,&local_60,param_3,*param_4,param_5,param_6,
                             param_7,*(undefined8 *)(param_7 + 0x28),&local_58);
          pcVar2 = local_68;
          local_c0 = local_68;
          uVar9 = local_60;
          if ((iVar6 == 0) &&
             (iVar6 = _heapUpdate(param_3,local_68,3), uVar9 = local_60, iVar6 == 0)) {
            if ((*(int *)(lVar1 + 4) == 2) && (local_d8 != 0xffffffff)) {
              *(int *)(pcVar2 + 0x30) = param_2;
              piVar27 = (int *)(param_3 + 0xa4 + (ulong)local_d8 * 0xc);
              *piVar27 = *piVar27 + 1;
            }
            else {
              pcVar2[0x30] = '\0';
              pcVar2[0x31] = '\0';
              pcVar2[0x32] = '\0';
              pcVar2[0x33] = '\0';
            }
            *(undefined8 *)(param_7 + 0x38) = local_58;
            if (*param_9 == '\0') {
              *(undefined4 *)(pcVar2 + 0x38) = *(undefined4 *)(param_7 + 0x10);
              *(undefined4 *)(pcVar2 + 0x3c) = *(undefined4 *)(param_7 + 8);
              *(undefined4 *)(pcVar2 + 0x40) = *(undefined4 *)(param_7 + 0xc);
            }
            *param_8 = (long)(pcVar2 + 0x88);
            memdescDescribe(local_70,2,local_58,lVar24);
            *(undefined8 **)(pcVar2 + 0x80) = local_70;
            uVar26 = 0;
            *pcVar2 = param_11;
            goto LAB_003ad67b;
          }
          goto LAB_003adc37;
        }
        nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x5e3,"heapAlloc_IMPL",4,
                     "NVRM: no free blocks\n");
        local_c0 = (char *)0x0;
        uVar9 = 0;
      }
LAB_003adc37:
      nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x709,"heapAlloc_IMPL",1,
                   "NVRM: failed to allocate block.  Heap total=0x%llx free=0x%llx\n",
                   *(undefined8 *)(param_3 + 0x70),*(undefined8 *)(param_3 + 0x78));
      portMemFree(local_c0);
      portMemFree(uVar9);
      uVar26 = 0x51;
      goto LAB_003ad67b;
    }
  }
  uVar26 = 0x1f;
LAB_003ad67b:
  if (local_c5 != '\0') {
    cVar5 = hypervisorIsVgxHyper_IMPL();
    if (cVar5 == '\0') {
      _heapBlacklistChunks(param_1,param_3,param_3 + 0xe8,local_b8,*(undefined8 *)(lVar1 + 0x40));
    }
    else if (*(long *)(param_3 + 0x90) != 0) {
      lVar1 = *(long *)(*(long *)(param_3 + 0x90) + 0xa8);
      lVar28 = lVar1;
      do {
        lVar28 = *(long *)(lVar28 + 0xb0);
        _heapBlacklistChunks
                  (param_1,param_3,param_3 + 0xe8,*(long *)(lVar28 + 0x10),
                   (*(long *)(lVar28 + 0x28) + 1) - *(long *)(lVar28 + 0x10));
      } while (lVar1 != lVar28);
    }
  }
  return uVar26;
LAB_003ad960:
  *(ulong *)(lVar1 + 0x30) = uVar20;
  *(undefined8 *)(lVar1 + 0x38) = uVar9;
  if (bVar30) goto LAB_003ad97c;
  goto LAB_003ad770;
LAB_003ad4c0:
  if (*(long *)(param_3 + 0x90) == lVar19) goto LAB_003adbfb;
  goto LAB_003ad4cd;
LAB_003adbfb:
  nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x5fe,"heapAlloc_IMPL",4,
               "NVRM: failed NVOS32_ALLOC_FLAGS_FIXED_ADDRESS_ALLOCATE @%llx (%lld bytes)\n",
               local_b8,param_6[4]);
  goto LAB_003adc34;
}


// ===== 003aec30 heapReference_IMPL =====

undefined1  [16] heapReference_IMPL(undefined8 param_1,long param_2,int param_3,long param_4)

{
  uint uVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  long lStack_40;
  long *local_30 [2];
  
  uVar2 = memdescGetPhysAddr(param_4,1,0);
  lStack_40 = *(long *)(param_4 + 0xb0);
  if (lStack_40 == 0) {
    uVar3 = 0x40;
    if (param_3 != -1) {
      lStack_40 = 0x3aec9e;
      auVar6 = btreeSearch(uVar2,local_30,*(undefined8 *)(param_2 + 0x98));
      lVar4 = auVar6._8_8_;
      if ((auVar6._0_4_ != 0) || (lVar4 = *local_30[0], param_3 != *(int *)(lVar4 + 4))) {
        auVar7._8_8_ = lVar4;
        auVar7._0_8_ = 0x37;
        return auVar7;
      }
      if (*(int *)(lVar4 + 0x44) != -1) {
        LOCK();
        *(int *)(lVar4 + 0x44) = *(int *)(lVar4 + 0x44) + 1;
        UNLOCK();
        auVar6._8_8_ = lVar4;
        return auVar6;
      }
      nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x884,"heapReference_IMPL",4,
                   "NVRM: heapReference: reference count %x will exceed maximum 0x%x:\n",
                   *(undefined4 *)(lVar4 + 0x44),0xffffffffffffffff);
      uVar3 = 0xffff;
    }
  }
  else {
    uVar1 = *(uint *)(lStack_40 + 0x10);
    uVar3 = (ulong)uVar1;
    if (uVar1 != 0) {
      *(uint *)(lStack_40 + 0x10) = uVar1 + 1;
      uVar3 = 0;
    }
  }
  auVar5._8_8_ = lStack_40;
  auVar5._0_8_ = uVar3;
  return auVar5;
}


// ===== 003aed30 __pfx_heapFree_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int __pfx_heapFree_IMPL(long param_1,long param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,long param_6)

{
  int *piVar1;
  char *pcVar2;
  bool bVar3;
  char *pcVar4;
  char cVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  ulong *puVar11;
  ulong uVar12;
  char *apcStack_40 [2];
  
  uVar7 = memdescGetPhysAddr(param_6,1,0);
  if (*(long *)(param_6 + 0xa0) == param_2) {
    lVar10 = *(long *)(param_1 + 0x1b78);
    cVar5 = memdescGetContiguity(param_6,1);
    if (cVar5 == '\0') {
      uVar7 = memdescGetPte(param_6,1,0);
      iVar6 = _heapFindBlockByOffset_isra_0(param_2,param_5,uVar7,apcStack_40);
      if (iVar6 != 0) {
        return iVar6;
      }
      if (apcStack_40[0] == (char *)0x0) {
        memdescFree(param_6);
        memdescDestroy(param_6);
        return 0;
      }
      bVar3 = false;
      iVar6 = 0;
      do {
        while( true ) {
          pcVar4 = apcStack_40[0];
          pcVar2 = *(char **)(apcStack_40[0] + 0xd8);
          LOCK();
          piVar1 = (int *)(apcStack_40[0] + 0x44);
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (*piVar1 == 0) break;
          apcStack_40[0][0xd8] = '\0';
          apcStack_40[0][0xd9] = '\0';
          apcStack_40[0][0xda] = '\0';
          apcStack_40[0][0xdb] = '\0';
          apcStack_40[0][0xdc] = '\0';
          apcStack_40[0][0xdd] = '\0';
          apcStack_40[0][0xde] = '\0';
          apcStack_40[0][0xdf] = '\0';
LAB_003aee0b:
          apcStack_40[0] = pcVar2;
          if (pcVar2 == (char *)0x0) goto LAB_003aeed0;
        }
        iVar6 = _heapBlockFree(param_1,param_2,param_3,param_4,apcStack_40[0]);
        if (iVar6 != 0) {
          return iVar6;
        }
        iVar6 = 0;
        if ((*(char *)(lVar10 + 0x443) == '\0') || (*(int *)(param_2 + 0xf0) == 0))
        goto LAB_003aee0b;
        lVar8 = 0;
        puVar11 = (ulong *)(*(long *)(param_2 + 0xe8) + 8);
        do {
          if ((((*(char *)((long)puVar11 + 0x11) != '\0') && (*(ulong *)(pcVar4 + 0x10) <= *puVar11)
               ) && (*puVar11 <= *(ulong *)(pcVar4 + 0x28))) &&
             (iVar6 = _heapBlacklistSingleChunk
                                (param_1,param_2,lVar8 * 0x20 + *(long *)(param_2 + 0xe8)),
             iVar6 != 0)) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x961,"heapFree_IMPL",4,
                         "NVRM: heapBlacklistSingleChunk, status: %x!\n");
            bVar3 = true;
          }
          lVar8 = lVar8 + 1;
          puVar11 = puVar11 + 4;
        } while ((uint)lVar8 < *(uint *)(param_2 + 0xf0));
        apcStack_40[0] = pcVar2;
      } while (pcVar2 != (char *)0x0);
LAB_003aeed0:
      apcStack_40[0] = pcVar2;
      memdescFree(param_6);
      memdescDestroy(param_6);
      if (!bVar3) {
        return iVar6;
      }
      return 0x40;
    }
    iVar6 = _heapFindBlockByOffset_isra_0(param_2,param_5,uVar7,apcStack_40);
    pcVar2 = apcStack_40[0];
    if (iVar6 != 0) {
      return iVar6;
    }
    if (*apcStack_40[0] != '\0') {
      if (*(long *)(apcStack_40[0] + 0x80) != param_6) {
        nvAssertFailedNoLog("pMemDesc == pBlock->pMemDesc","src/kernel/gpu/mem_mgr/heap.c",0x8da);
        goto LAB_003af158;
      }
      if (*(int *)(param_6 + 0x90) == 1) {
        apcStack_40[0][0x80] = '\0';
        apcStack_40[0][0x81] = '\0';
        apcStack_40[0][0x82] = '\0';
        apcStack_40[0][0x83] = '\0';
        apcStack_40[0][0x84] = '\0';
        apcStack_40[0][0x85] = '\0';
        apcStack_40[0][0x86] = '\0';
        apcStack_40[0][0x87] = '\0';
      }
      memdescFree(param_6);
      memdescDestroy(param_6);
    }
    LOCK();
    piVar1 = (int *)(pcVar2 + 0x44);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    iVar6 = 0;
    if (*piVar1 == 0) {
      if (((*(char *)(param_1 + 0x457) == '\0') ||
          (cVar5 = (**(code **)(param_1 + 0x2f0))(param_1), cVar5 == '\0')) ||
         ((apcStack_40[0][0x8e] & 8U) == 0)) {
        bVar3 = false;
        uVar9 = 0;
        uVar12 = 0;
      }
      else {
        uVar12 = *(ulong *)(apcStack_40[0] + 0x10);
        uVar9 = *(ulong *)(apcStack_40[0] + 0x28);
        bVar3 = true;
      }
      if ((*apcStack_40[0] != '\0') && (*(long *)(apcStack_40[0] + 0x80) != 0)) {
        *(undefined4 *)(param_6 + 0x98) = 0;
      }
      iVar6 = _heapBlockFree(param_1,param_2,param_3,param_4);
      if (iVar6 != 0) {
        nvAssertFailedNoLog(&DAT_00d4b32f,"src/kernel/gpu/mem_mgr/heap.c",0x910);
      }
      if (bVar3) {
        iVar6 = _heapBlacklistChunks(param_1,param_2,param_2 + 0xe8,uVar12,(uVar9 + 1) - uVar12);
      }
      if ((*(char *)(lVar10 + 0x443) != '\0') && (*(int *)(param_2 + 0xf0) != 0)) {
        lVar10 = 0;
        puVar11 = (ulong *)(*(long *)(param_2 + 0xe8) + 8);
        do {
          if ((((*(char *)((long)puVar11 + 0x11) != '\0') && (uVar12 <= *puVar11)) &&
              (*puVar11 <= uVar9)) &&
             (iVar6 = _heapBlacklistSingleChunk
                                (param_1,param_2,lVar10 * 0x20 + *(long *)(param_2 + 0xe8)),
             iVar6 != 0)) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x929,"heapFree_IMPL",4,
                         "NVRM: heapBlacklistSingleChunk, status: %x!\n");
            return iVar6;
          }
          lVar10 = lVar10 + 1;
          puVar11 = puVar11 + 4;
        } while ((uint)lVar10 < *(uint *)(param_2 + 0xf0));
      }
    }
  }
  else {
    nvAssertFailedNoLog("pMemDesc->pHeap == pHeap","src/kernel/gpu/mem_mgr/heap.c",0x8ca);
LAB_003af158:
    iVar6 = 0x1f;
  }
  return iVar6;
}


// ===== 003aed40 heapFree_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int heapFree_IMPL(long param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
                 ,long param_6)

{
  int *piVar1;
  char *pcVar2;
  bool bVar3;
  char *pcVar4;
  char cVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  ulong *puVar11;
  ulong uVar12;
  char *local_40 [2];
  
  uVar7 = memdescGetPhysAddr(param_6,1,0);
  if (*(long *)(param_6 + 0xa0) == param_2) {
    lVar10 = *(long *)(param_1 + 0x1b78);
    cVar5 = memdescGetContiguity(param_6,1);
    if (cVar5 == '\0') {
      uVar7 = memdescGetPte(param_6,1,0);
      iVar6 = _heapFindBlockByOffset_isra_0(param_2,param_5,uVar7,local_40);
      if (iVar6 != 0) {
        return iVar6;
      }
      if (local_40[0] == (char *)0x0) {
        memdescFree(param_6);
        memdescDestroy(param_6);
        return 0;
      }
      bVar3 = false;
      iVar6 = 0;
      do {
        while( true ) {
          pcVar4 = local_40[0];
          pcVar2 = *(char **)(local_40[0] + 0xd8);
          LOCK();
          piVar1 = (int *)(local_40[0] + 0x44);
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (*piVar1 == 0) break;
          local_40[0][0xd8] = '\0';
          local_40[0][0xd9] = '\0';
          local_40[0][0xda] = '\0';
          local_40[0][0xdb] = '\0';
          local_40[0][0xdc] = '\0';
          local_40[0][0xdd] = '\0';
          local_40[0][0xde] = '\0';
          local_40[0][0xdf] = '\0';
LAB_003aee0b:
          local_40[0] = pcVar2;
          if (pcVar2 == (char *)0x0) goto LAB_003aeed0;
        }
        iVar6 = _heapBlockFree(param_1,param_2,param_3,param_4,local_40[0]);
        if (iVar6 != 0) {
          return iVar6;
        }
        iVar6 = 0;
        if ((*(char *)(lVar10 + 0x443) == '\0') || (*(int *)(param_2 + 0xf0) == 0))
        goto LAB_003aee0b;
        lVar8 = 0;
        puVar11 = (ulong *)(*(long *)(param_2 + 0xe8) + 8);
        do {
          if ((((*(char *)((long)puVar11 + 0x11) != '\0') && (*(ulong *)(pcVar4 + 0x10) <= *puVar11)
               ) && (*puVar11 <= *(ulong *)(pcVar4 + 0x28))) &&
             (iVar6 = _heapBlacklistSingleChunk
                                (param_1,param_2,lVar8 * 0x20 + *(long *)(param_2 + 0xe8)),
             iVar6 != 0)) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x961,"heapFree_IMPL",4,
                         "NVRM: heapBlacklistSingleChunk, status: %x!\n");
            bVar3 = true;
          }
          lVar8 = lVar8 + 1;
          puVar11 = puVar11 + 4;
        } while ((uint)lVar8 < *(uint *)(param_2 + 0xf0));
        local_40[0] = pcVar2;
      } while (pcVar2 != (char *)0x0);
LAB_003aeed0:
      local_40[0] = pcVar2;
      memdescFree(param_6);
      memdescDestroy(param_6);
      if (!bVar3) {
        return iVar6;
      }
      return 0x40;
    }
    iVar6 = _heapFindBlockByOffset_isra_0(param_2,param_5,uVar7,local_40);
    pcVar2 = local_40[0];
    if (iVar6 != 0) {
      return iVar6;
    }
    if (*local_40[0] != '\0') {
      if (*(long *)(local_40[0] + 0x80) != param_6) {
        nvAssertFailedNoLog("pMemDesc == pBlock->pMemDesc","src/kernel/gpu/mem_mgr/heap.c",0x8da);
        goto LAB_003af158;
      }
      if (*(int *)(param_6 + 0x90) == 1) {
        local_40[0][0x80] = '\0';
        local_40[0][0x81] = '\0';
        local_40[0][0x82] = '\0';
        local_40[0][0x83] = '\0';
        local_40[0][0x84] = '\0';
        local_40[0][0x85] = '\0';
        local_40[0][0x86] = '\0';
        local_40[0][0x87] = '\0';
      }
      memdescFree(param_6);
      memdescDestroy(param_6);
    }
    LOCK();
    piVar1 = (int *)(pcVar2 + 0x44);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    iVar6 = 0;
    if (*piVar1 == 0) {
      if (((*(char *)(param_1 + 0x457) == '\0') ||
          (cVar5 = (**(code **)(param_1 + 0x2f0))(param_1), cVar5 == '\0')) ||
         ((local_40[0][0x8e] & 8U) == 0)) {
        bVar3 = false;
        uVar9 = 0;
        uVar12 = 0;
      }
      else {
        uVar12 = *(ulong *)(local_40[0] + 0x10);
        uVar9 = *(ulong *)(local_40[0] + 0x28);
        bVar3 = true;
      }
      if ((*local_40[0] != '\0') && (*(long *)(local_40[0] + 0x80) != 0)) {
        *(undefined4 *)(param_6 + 0x98) = 0;
      }
      iVar6 = _heapBlockFree(param_1,param_2,param_3,param_4);
      if (iVar6 != 0) {
        nvAssertFailedNoLog(&DAT_00d4b32f,"src/kernel/gpu/mem_mgr/heap.c",0x910);
      }
      if (bVar3) {
        iVar6 = _heapBlacklistChunks(param_1,param_2,param_2 + 0xe8,uVar12,(uVar9 + 1) - uVar12);
      }
      if ((*(char *)(lVar10 + 0x443) != '\0') && (*(int *)(param_2 + 0xf0) != 0)) {
        lVar10 = 0;
        puVar11 = (ulong *)(*(long *)(param_2 + 0xe8) + 8);
        do {
          if ((((*(char *)((long)puVar11 + 0x11) != '\0') && (uVar12 <= *puVar11)) &&
              (*puVar11 <= uVar9)) &&
             (iVar6 = _heapBlacklistSingleChunk
                                (param_1,param_2,lVar10 * 0x20 + *(long *)(param_2 + 0xe8)),
             iVar6 != 0)) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x929,"heapFree_IMPL",4,
                         "NVRM: heapBlacklistSingleChunk, status: %x!\n");
            return iVar6;
          }
          lVar10 = lVar10 + 1;
          puVar11 = puVar11 + 4;
        } while ((uint)lVar10 < *(uint *)(param_2 + 0xf0));
      }
    }
  }
  else {
    nvAssertFailedNoLog("pMemDesc->pHeap == pHeap","src/kernel/gpu/mem_mgr/heap.c",0x8ca);
LAB_003af158:
    iVar6 = 0x1f;
  }
  return iVar6;
}


// ===== 003af230 heapGetSize_IMPL =====

undefined8 heapGetSize_IMPL(long param_1,undefined8 *param_2)

{
  *param_2 = *(undefined8 *)(param_1 + 0x70);
  return 0;
}


// ===== 003af240 heapGetUsableSize_IMPL =====

undefined8 heapGetUsableSize_IMPL(long param_1,long *param_2)

{
  *param_2 = *(long *)(param_1 + 0x70) - *(long *)(param_1 + 0x80);
  return 0;
}


// ===== 003af260 heapGetFree_IMPL =====

undefined8 heapGetFree_IMPL(long param_1,undefined8 *param_2)

{
  *param_2 = *(undefined8 *)(param_1 + 0x78);
  return 0;
}


// ===== 003af270 heapGetBase_IMPL =====

undefined8 heapGetBase_IMPL(long param_1,undefined8 *param_2)

{
  *param_2 = *(undefined8 *)(param_1 + 0x68);
  return 0;
}


// ===== 003af280 heapInfo_IMPL =====

undefined8
heapInfo_IMPL(long param_1,undefined8 *param_2,long *param_3,undefined8 *param_4,long *param_5,
             ulong *param_6)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  
  *param_2 = *(undefined8 *)(param_1 + 0x78);
  *param_3 = *(long *)(param_1 + 0x70) - *(long *)(param_1 + 0x80);
  *param_4 = *(undefined8 *)(param_1 + 0x68);
  *param_6 = 0;
  lVar1 = *(long *)(param_1 + 0x90);
  if (lVar1 != 0) {
    uVar4 = 0;
    lVar3 = lVar1;
    while( true ) {
      uVar2 = (*(long *)(lVar3 + 0x28) + 1) - *(long *)(lVar3 + 0x10);
      if (uVar4 < uVar2) {
        *param_5 = *(long *)(lVar3 + 0x10);
        *param_6 = uVar2;
      }
      lVar3 = *(long *)(lVar3 + 0xb0);
      if (lVar1 == lVar3) break;
      uVar4 = *param_6;
    }
  }
  return 0;
}


// ===== 003af2f0 heapGetClientAddrSpaceSize_IMPL =====

void heapGetClientAddrSpaceSize_IMPL(long param_1,long param_2,long *param_3)

{
  ulong *puVar1;
  uint uVar2;
  ulong uVar3;
  ulong *puVar4;
  long lVar5;
  ulong uVar6;
  
  uVar2 = *(uint *)(*(long *)(param_1 + 0x1b78) + 0x858);
  if (uVar2 == 0) {
    lVar5 = 1;
  }
  else {
    puVar4 = (ulong *)(*(long *)(param_1 + 0x1b78) + 0x860);
    uVar6 = 0;
    puVar1 = puVar4 + (ulong)uVar2 * 5;
    do {
      if (((char)puVar4[3] == '\0') && (*(char *)((long)puVar4 + 0x23) == '\0')) {
        uVar3 = puVar4[1];
        if (((*(ulong *)(param_2 + 0x68) <= *puVar4) || (*(ulong *)(param_2 + 0x68) <= uVar3)) &&
           (uVar6 < uVar3)) {
          uVar6 = uVar3;
        }
      }
      puVar4 = puVar4 + 5;
    } while (puVar1 != puVar4);
    lVar5 = uVar6 + 1;
    if ((uVar6 & 0xfff) != 0) {
      *param_3 = lVar5;
      return;
    }
  }
  nvAssertFailedNoLog("(highestAddr & RM_PAGE_MASK) != 0","src/kernel/gpu/mem_mgr/heap.c",0xa31);
  *param_3 = lVar5;
  return;
}


// ===== 003af3a0 heapAllocHint_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int heapAllocHint_IMPL(long param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
                      uint *param_5)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  
  if (*(long *)(param_5 + 8) == 0) {
    nvAssertFailedNoLog("(pAllocHint->pSize != NULL)","src/kernel/gpu/mem_mgr/heap.c",0xa49);
  }
  else if (*param_5 < 0x12) {
    if ((*(long *)(param_5 + 2) != 0) && (*(long *)(param_5 + 0xc) != 0)) {
      lVar8 = *(long *)(param_1 + 0x1b78);
      lVar4 = portMemAllocNonPaged(0xc0);
      if (lVar4 == 0) {
        lVar5 = 0;
        iVar3 = 0x51;
        nvAssertFailedNoLog(&DAT_00d4b32f,"src/kernel/gpu/mem_mgr/heap.c",0xa54);
      }
      else {
        lVar5 = portMemAllocNonPaged(0x14);
        if (lVar5 == 0) {
          iVar3 = 0x51;
          nvAssertFailedNoLog(&DAT_00d4b32f,"src/kernel/gpu/mem_mgr/heap.c",0xa5b);
        }
        else {
          portMemSet(lVar4,0,0xc0);
          portMemSet(lVar5,0,0x14);
          *(long *)(lVar4 + 0x90) = lVar5;
          *(uint *)(lVar5 + 0x10) = *param_5;
          *(undefined4 *)(lVar4 + 4) = 0;
          *(undefined8 *)(lVar4 + 0x30) = 0;
          *(undefined4 *)(lVar4 + 8) = **(undefined4 **)(param_5 + 2);
          *(undefined4 *)(lVar4 + 0xc) = **(undefined4 **)(param_5 + 4);
          uVar2 = 0;
          if (*(undefined4 **)(param_5 + 6) != (undefined4 *)0x0) {
            uVar2 = **(undefined4 **)(param_5 + 6);
          }
          *(undefined4 *)(lVar4 + 0x10) = uVar2;
          *(undefined8 *)(lVar4 + 0x18) = **(undefined8 **)(param_5 + 8);
          *(undefined4 *)(*(long *)(lVar4 + 0x90) + 0xc) = 0;
          *(undefined8 *)(lVar4 + 0x38) = 0xffffffffffffffff;
          *(undefined4 *)(lVar4 + 0x98) = param_3;
          *(undefined4 *)(lVar4 + 0x9c) = param_4;
          *(uint *)(*(long *)(lVar4 + 0x90) + 8) = param_5[1];
          **(undefined4 **)(lVar4 + 0x90) = **(undefined4 **)(param_5 + 0xc);
          *(undefined4 *)(lVar4 + 0x44) = **(undefined4 **)(param_5 + 0xc);
          *(undefined4 *)(*(long *)(lVar4 + 0x90) + 4) = **(undefined4 **)(param_5 + 0xe);
          uVar2 = **(undefined4 **)(param_5 + 0xe);
          *(undefined4 *)(lVar4 + 0x4c) = 0;
          *(undefined4 *)(lVar4 + 0x48) = uVar2;
          uVar6 = 0x1000;
          if ((param_5[1] & 0x180) != 0) {
            uVar6 = **(undefined8 **)(param_5 + 10);
          }
          *(undefined8 *)(lVar4 + 0x20) = uVar6;
          lVar7 = (**(code **)(lVar8 + 0x168))
                            (lVar8,*(undefined4 *)(lVar4 + 0x98),*(undefined8 *)(lVar4 + 0x18),0,
                             *(undefined4 *)(*(long *)(lVar4 + 0x90) + 8),lVar4 + 0x44,lVar4 + 0x48)
          ;
          if (lVar7 == 0) {
            iVar3 = 0x40;
            nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xa83,"heapAllocHint_IMPL",4,
                         "NVRM: memmgrDeterminePageSize failed, status: 0x%x\n",0x40);
          }
          else {
            iVar3 = (**(code **)(lVar8 + 0x1f8))
                              (param_1,lVar8,lVar4 + 0x18,lVar4 + 0x20,*(undefined8 *)(lVar4 + 0x28)
                               ,*(undefined4 *)(*(long *)(lVar4 + 0x90) + 8),
                               *(undefined4 *)(lVar4 + 0x44),*(undefined4 *)(lVar4 + 0x48),0);
            if (iVar3 == 0) {
              uVar1 = *(uint *)(*(long *)(lVar4 + 0x90) + 8);
              *(uint *)(*(long *)(lVar4 + 0x90) + 8) = uVar1 | 0x10000000;
              iVar3 = memmgrAllocHwResources_IMPL(param_1,lVar8,lVar4);
              *(uint *)(*(long *)(lVar4 + 0x90) + 8) = uVar1;
              **(undefined4 **)(param_5 + 0xc) = *(undefined4 *)(lVar4 + 0x44);
              **(undefined4 **)(param_5 + 0xe) = *(undefined4 *)(lVar4 + 0x48);
              **(undefined4 **)(param_5 + 0x10) = *(undefined4 *)(*(long *)(lVar4 + 0x90) + 0xc);
              uVar2 = *(undefined4 *)(lVar4 + 0x44);
              *(undefined8 *)(lVar4 + 0x44) = 0;
              *(undefined4 *)(lVar4 + 0xa0) = uVar2;
              if (iVar3 == 0) {
                if ((**(uint **)(param_5 + 0xc) & 0x30000) != 0x20000) {
                  **(undefined4 **)(param_5 + 2) = *(undefined4 *)(lVar4 + 8);
                  if (*(undefined4 **)(param_5 + 6) != (undefined4 *)0x0) {
                    **(undefined4 **)(param_5 + 6) = *(undefined4 *)(lVar4 + 0x10);
                  }
                }
                **(long **)(param_5 + 10) = *(long *)(lVar4 + 0x20) + 1;
                if ((param_5[1] & 8) != 0) {
                  lVar8 = *(long *)(g_pSys + 0xd0);
                  if (lVar8 == 0) {
                    lVar8 = 0x1000;
                  }
                  memUtilsLeastCommonAlignment(*(long *)(lVar4 + 0x20) + 1,lVar8);
                }
                **(undefined4 **)(param_5 + 2) = *(undefined4 *)(lVar4 + 8);
                *(undefined8 *)(param_5 + 0x12) = *(undefined8 *)(lVar4 + 0x30);
                **(undefined8 **)(param_5 + 8) = *(undefined8 *)(lVar4 + 0x18);
              }
              else {
                nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xaac,"heapAllocHint_IMPL",4,
                             "NVRM: memmgrAllocHwResources failed, status: 0x%x\n",iVar3);
              }
            }
            else {
              nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xa8d,"heapAllocHint_IMPL",4,
                           "NVRM: memmgrAllocDetermineAlignment failed, status: 0x%x\n",iVar3);
            }
          }
        }
      }
      portMemFree(lVar5);
      portMemFree(lVar4);
      return iVar3;
    }
    nvAssertFailedNoLog("((pAllocHint->pHeight != NULL) && (pAllocHint->pAttr != NULL))",
                        "src/kernel/gpu/mem_mgr/heap.c",0xa4f);
  }
  else {
    nvAssertFailedNoLog("(pAllocHint->type < NVOS32_NUM_MEM_TYPES)","src/kernel/gpu/mem_mgr/heap.c",
                        0xa4c);
  }
  return 0x1f;
}


// ===== 003af840 heapBlackListPages_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 heapBlackListPages_IMPL(long param_1,long param_2)

{
  undefined8 *puVar1;
  long lVar2;
  char cVar3;
  ushort uVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  long *plVar8;
  long lVar9;
  int iVar10;
  ulong uVar11;
  uint uVar12;
  uint uVar13;
  long lVar14;
  undefined4 local_64;
  uint local_60;
  uint local_5c;
  uint local_40;
  uint local_3c [3];
  
  lVar2 = *(long *)(param_1 + 0x1b78);
  uVar12 = *(uint *)(param_2 + 0xd8);
  uVar4 = (**(code **)(*(long *)(param_1 + 0x1b70) + 0x270))();
  if (*(int *)(param_2 + 0xf0) == 0) {
    lVar6 = portMemAllocNonPaged((ulong)uVar4 << 5);
    *(long *)(param_2 + 0xe8) = lVar6;
    if (lVar6 == 0) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xe95,"heapBlackListPages_IMPL",4,
                   "NVRM: Could not allocate memory for blackList!\n");
      local_64 = 0x51;
    }
    else {
      portMemSet(lVar6,0,(ulong)uVar4 << 5);
      if (uVar12 == 0) {
        uVar12 = 0;
        uVar13 = 0;
        iVar10 = 0;
      }
      else {
        lVar6 = (ulong)uVar12 << 4;
        lVar14 = 0;
        uVar11 = 0;
        local_60 = 0;
        local_5c = 0;
        do {
          while( true ) {
            iVar10 = (int)uVar11;
            plVar8 = (long *)(*(long *)(param_2 + 0xe0) + lVar14);
            lVar7 = *plVar8;
            if (lVar7 != -1) break;
LAB_003af9f4:
            iVar10 = (int)uVar11;
            lVar14 = lVar14 + 0x10;
            if (lVar6 == lVar14) goto LAB_003afab0;
          }
          if ((*(char *)(lVar2 + 0x434) != '\0') &&
             (*(char *)(*(long *)(param_1 + 0x1b78) + 0x434) != '\0')) {
            cVar3 = pmaIsPmaManaged(*(undefined8 *)(param_2 + 0x128),lVar7,lVar7);
            if (cVar3 != '\0') goto LAB_003af9f4;
            plVar8 = (long *)(*(long *)(param_2 + 0xe0) + lVar14);
          }
          if (((int)plVar8[1] - 2U & 0xfffffffd) == 0) {
            local_5c = local_5c + 1;
          }
          else {
            local_60 = local_60 + 1;
          }
          lVar9 = uVar11 * 0x20;
          iVar5 = memdescCreate(*(long *)(param_2 + 0xe8) + lVar9,param_1,0x1000,0x1000,1,2,1,
                                0x20010);
          lVar7 = *(long *)(param_2 + 0xe8);
          if (iVar5 == 0) {
            if (*(int *)(param_2 + 0x4c) == 1) {
              *(long *)(*(long *)(lVar7 + lVar9) + 0xa0) = param_2;
              lVar7 = *(long *)(param_2 + 0xe8);
            }
            memdescSetPte(*(undefined8 *)(lVar7 + lVar9),1,0,
                          *(ulong *)(*(long *)(param_2 + 0xe0) + lVar14) & 0xfffffffffffff000);
            if (*(int *)(param_2 + 0x4c) != 1) {
              *(undefined4 *)(*(long *)(*(long *)(param_2 + 0xe8) + lVar9) + 0x9c) = 0x70;
              iVar5 = memdescAlloc(*(undefined8 *)(*(long *)(param_2 + 0xe8) + lVar9));
              if (iVar5 != 0) {
                memdescDestroy(*(undefined8 *)(*(long *)(param_2 + 0xe8) + lVar9));
                portMemSet(*(long *)(param_2 + 0xe8) + lVar9,0,0x20);
                nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xee4,"heapBlackListPages_IMPL",4,
                             "NVRM: Error 0x%x blacklisting page at address  0x%llx, skipping\n",
                             iVar5,*(undefined8 *)(*(long *)(param_2 + 0xe0) + lVar14));
                goto LAB_003af9f4;
              }
            }
            uVar11 = (ulong)(iVar10 + 1);
            *(undefined8 *)(*(long *)(param_2 + 0xe8) + 8 + lVar9) =
                 *(undefined8 *)(*(long *)(param_2 + 0xe0) + lVar14);
            *(undefined8 *)(*(long *)(param_2 + 0xe8) + 0x10 + lVar9) = 0x1000;
            *(undefined1 *)(*(long *)(param_2 + 0xe8) + 0x18 + lVar9) = 1;
            goto LAB_003af9f4;
          }
          portMemSet((long *)(lVar7 + lVar9),0,0x20);
          puVar1 = (undefined8 *)(*(long *)(param_2 + 0xe0) + lVar14);
          lVar14 = lVar14 + 0x10;
          nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xec8,"heapBlackListPages_IMPL",4,
                       "NVRM: Error 0x%x creating blacklisted page memdesc for address 0x%llx, skipping\n"
                       ,iVar5,*puVar1);
        } while (lVar6 != lVar14);
LAB_003afab0:
        uVar13 = (local_5c & 0xfffff) << 2;
        uVar12 = (local_60 & 0xfffff) << 2;
      }
      *(int *)(param_2 + 0xf0) = iVar10;
      local_3c[0] = 0;
      local_40 = 0;
      if (*(char *)(lVar2 + 0x434) != '\0') {
        pmaGetBlacklistSize(*(undefined8 *)(param_2 + 0x128),local_3c,&local_40);
        iVar10 = *(int *)(param_2 + 0xf0);
        uVar13 = uVar13 + (local_3c[0] >> 10);
        uVar12 = uVar12 + (local_40 >> 10);
      }
      *(uint *)(param_2 + 0xf8) = uVar13;
      *(uint *)(param_2 + 0xfc) = uVar12;
      if (iVar10 == 0) {
        local_40 = uVar12;
        local_3c[0] = uVar13;
        portMemFree(*(undefined8 *)(param_2 + 0xe8));
        local_64 = 0;
        *(undefined8 *)(param_2 + 0xe8) = 0;
      }
      else {
        local_64 = 0;
      }
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xe8a,"heapBlackListPages_IMPL",4,
                 "NVRM: Error: BlackList already exists!\n");
    local_64 = 0x40;
  }
  return local_64;
}


// ===== 003afca0 heapFreeBlackListedPages_IMPL =====

undefined4 heapFreeBlackListedPages_IMPL(undefined8 param_1,long param_2)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  if (*(long *)(param_2 + 0xe0) != 0) {
    portMemFree();
    *(undefined4 *)(param_2 + 0xd8) = 0;
    *(undefined8 *)(param_2 + 0xe0) = 0;
  }
  uVar2 = 0;
  if (*(int *)(param_2 + 0xf0) != 0) {
    lVar4 = *(long *)(param_2 + 0xe8);
    if (lVar4 == 0) {
      uVar2 = 0x40;
    }
    else {
      lVar3 = 0;
      do {
        while( true ) {
          lVar5 = lVar3 * 0x20;
          puVar1 = (undefined8 *)(lVar4 + lVar5);
          if (*(char *)(puVar1 + 3) == '\0') break;
          lVar3 = lVar3 + 1;
          memdescFree(*puVar1);
          memdescDestroy(*(undefined8 *)(*(long *)(param_2 + 0xe8) + lVar5));
          lVar4 = *(long *)(param_2 + 0xe8);
          if (*(uint *)(param_2 + 0xf0) <= (uint)lVar3) goto LAB_003afd6e;
        }
        lVar3 = lVar3 + 1;
      } while ((uint)lVar3 < *(uint *)(param_2 + 0xf0));
LAB_003afd6e:
      portMemFree();
      uVar2 = 0;
      *(undefined4 *)(param_2 + 0xf0) = 0;
      *(undefined8 *)(param_2 + 0xe8) = 0;
    }
  }
  return uVar2;
}


// ===== 003afdb0 heapDestruct_IMPL =====

void heapDestruct_IMPL(long param_1)

{
  long lVar1;
  char *pcVar2;
  char *pcVar3;
  long lVar4;
  char *pcVar5;
  undefined8 uVar6;
  
  uVar6 = 0;
  if (param_1 != 0) {
    uVar6 = *(undefined8 *)(param_1 + 0x38);
  }
  lVar4 = gpuEngineGetGpu(uVar6);
  lVar1 = *(long *)(lVar4 + 0x1b78);
  nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0x29b,"heapDestruct_IMPL",1,
               "NVRM: Heap Manager: HEAP ABOUT TO BE DESTROYED.\n");
  if (*(int *)(param_1 + 0xd8) != 0) {
    heapFreeBlackListedPages_IMPL(lVar4,param_1);
  }
  pcVar5 = *(char **)(param_1 + 0x88);
  do {
    pcVar3 = pcVar5;
    pcVar5 = pcVar3;
    if (pcVar3 == (char *)0x0) {
LAB_003afeac:
      lVar4 = *(long *)(param_1 + 0x50);
      if (lVar4 != 0) {
        if (*(int *)(param_1 + 0x4c) == 1) {
          memdescDestroy(*(undefined8 *)(lVar4 + 8));
          lVar4 = *(long *)(param_1 + 0x50);
        }
        portMemFree(lVar4);
        *(undefined8 *)(param_1 + 0x50) = 0;
      }
      if (((*(char *)(param_1 + 0x60) != '\0') && (*(char *)(lVar1 + 0x434) != '\0')) &&
         (*(int *)(param_1 + 0x4c) != 2)) {
        *(undefined1 *)(lVar1 + 0x434) = 0;
      }
      return;
    }
    while( true ) {
      pcVar2 = *(char **)(pcVar5 + 0xc0);
      if ((*pcVar5 != '\0') &&
         ((*(int *)(pcVar5 + 4) == -0x2150fffe || (*(int *)(pcVar5 + 4) == -0x2150fffb)))) {
        memdescDestroy(*(undefined8 *)(pcVar5 + 0x80));
        pcVar5[0x80] = '\0';
        pcVar5[0x81] = '\0';
        pcVar5[0x82] = '\0';
        pcVar5[0x83] = '\0';
        pcVar5[0x84] = '\0';
        pcVar5[0x85] = '\0';
        pcVar5[0x86] = '\0';
        pcVar5[0x87] = '\0';
        *pcVar5 = '\0';
      }
      _heapBlockFree(lVar4,param_1,0,0);
      pcVar5 = *(char **)(param_1 + 0x88);
      if (*(char **)(param_1 + 0x88) != pcVar3) break;
      pcVar5 = pcVar2;
      if (pcVar2 == pcVar3) {
        if ((*(long *)(pcVar2 + 0x10) == *(long *)(param_1 + 0x68)) &&
           (*(long *)(pcVar2 + 0x28) == *(long *)(param_1 + 0x68) + *(long *)(param_1 + 0x70) + -1))
        {
          portMemFree(pcVar2);
        }
        goto LAB_003afeac;
      }
    }
  } while( true );
}


// ===== 003aff50 heapAddPageToBlackList_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 heapAddPageToBlackList_IMPL(long param_1,long param_2,long param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  long lVar4;
  long lVar5;
  
  uVar3 = (**(code **)(*(long *)(param_1 + 0x1b70) + 0x270))();
  uVar2 = *(uint *)(param_2 + 0xd8);
  if (uVar3 == uVar2) {
    return 0x1a;
  }
  lVar5 = *(long *)(param_2 + 0xe0);
  if (lVar5 == 0) {
    lVar5 = portMemAllocNonPaged((ulong)uVar3 << 4);
    *(long *)(param_2 + 0xe0) = lVar5;
    if (lVar5 == 0) {
      return 0x51;
    }
    portMemSet(lVar5,0,(ulong)uVar3 << 4);
    lVar5 = *(long *)(param_2 + 0xe0);
  }
  lVar4 = (ulong)uVar2 * 0x10;
  *(long *)(lVar5 + lVar4) = param_3 << 0xc;
  *(undefined4 *)(*(long *)(param_2 + 0xe0) + 8 + lVar4) = param_4;
  iVar1 = *(int *)(param_2 + 0xd8) + 1;
  *(int *)(param_2 + 0xd8) = iVar1;
  nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xfe7,"heapAddPageToBlackList_IMPL",1,
               "NVRM: Added 0x%0llx (blacklist count: %u)\n",
               *(undefined8 *)(*(long *)(param_2 + 0xe0) + lVar4),iVar1);
  return 0;
}


// ===== 003b0070 heapStorePendingBlackList_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong heapStorePendingBlackList_IMPL(long param_1,long param_2,ulong param_3,ulong param_4)

{
  long lVar1;
  long lVar2;
  char cVar3;
  ushort uVar4;
  uint uVar5;
  long lVar6;
  ulong uVar7;
  
  lVar1 = *(long *)(param_1 + 0x1b70);
  lVar2 = *(long *)(param_1 + 0x1b78);
  lVar6 = kmemsysGetStaticConfig_IMPL(param_1,lVar1);
  if (*(char *)(lVar6 + 5) == '\0') {
    param_3 = param_4;
  }
  uVar5 = heapAddPageToBlackList_IMPL(param_1,param_2,(uint)(param_3 >> 0xc) & 0xfffffff,4);
  if (uVar5 == 0) {
    if (*(char *)(lVar2 + 0x434) == '\0') {
      uVar7 = 0;
      if (*(char *)(lVar2 + 0x443) != '\0') {
        uVar5 = *(uint *)(param_2 + 0xf0);
        uVar4 = (**(code **)(lVar1 + 0x270))(param_1,lVar1);
        if (uVar5 == uVar4) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xf82,"heapStorePendingBlackList_IMPL",4,
                       "NVRM: We have blacklisted maximum number of pages possible. returning error \n"
                      );
          uVar7 = 0x1a;
        }
        else {
          portMemSet((ulong)*(uint *)(param_2 + 0xf0) * 0x20 + *(long *)(param_2 + 0xe8),0,0x20);
          uVar7 = 0;
          *(ulong *)((ulong)*(uint *)(param_2 + 0xf0) * 0x20 + *(long *)(param_2 + 0xe8) + 8) =
               param_3;
          *(undefined8 *)
           ((ulong)*(uint *)(param_2 + 0xf0) * 0x20 + *(long *)(param_2 + 0xe8) + 0x10) = 0x1000;
          *(undefined1 *)
           ((ulong)*(uint *)(param_2 + 0xf0) * 0x20 + *(long *)(param_2 + 0xe8) + 0x19) = 1;
          *(int *)(param_2 + 0xf0) = *(int *)(param_2 + 0xf0) + 1;
        }
      }
    }
    else {
      if (*(char *)(*(long *)(param_1 + 0x1b78) + 0x434) != '\0') {
        cVar3 = pmaIsPmaManaged(*(undefined8 *)(param_2 + 0x128),param_3,param_3);
        if (cVar3 != '\0') {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xf71,"heapStorePendingBlackList_IMPL",1,
                       "NVRM: Calling PMA helper function to blacklist page offset: %llx\n",param_3)
          ;
          uVar7 = pmaAddToBlacklistTracking(*(undefined8 *)(param_2 + 0x128),param_3);
          return uVar7;
        }
      }
      uVar7 = 0x62;
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/heap.c",0xf69,"heapStorePendingBlackList_IMPL",4,
                 "NVRM: No more space in blacklist, status: %x!\n");
    uVar7 = (ulong)uVar5;
  }
  return uVar7;
}


// ===== 003b02a0 heapIsPmaManaged_IMPL =====

undefined8 heapIsPmaManaged_IMPL(long param_1,long param_2,ulong param_3,ulong param_4)

{
  undefined8 uVar1;
  
  if (*(char *)(*(long *)(param_1 + 0x1b78) + 0x434) == '\0') {
    return 0;
  }
  if (param_4 < param_3) {
    nvAssertFailedNoLog("offset <= limit","src/kernel/gpu/mem_mgr/heap.c",0x1006);
  }
  uVar1 = pmaIsPmaManaged(*(undefined8 *)(param_2 + 0x128),param_3,param_4);
  return uVar1;
}


// ===== 003b0330 heapAddRef_IMPL =====

int heapAddRef_IMPL(long param_1)

{
  long *plVar1;
  long lVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_1 != 0) {
    LOCK();
    plVar1 = (long *)(param_1 + 0x58);
    lVar2 = *plVar1;
    *plVar1 = *plVar1 + 1;
    UNLOCK();
    iVar3 = (int)lVar2 + 1;
  }
  return iVar3;
}


// ===== 003b0350 heapRemoveRef_IMPL =====

long heapRemoveRef_IMPL(long param_1)

{
  long *plVar1;
  long lVar2;
  
  lVar2 = 0;
  if (param_1 != 0) {
    LOCK();
    plVar1 = (long *)(param_1 + 0x58);
    lVar2 = *plVar1;
    *plVar1 = *plVar1 + -1;
    UNLOCK();
    lVar2 = lVar2 + -1;
    if (lVar2 == 0) {
      if (*(long *)(param_1 + 0x128) != 0) {
        pmaDestroy();
      }
      __nvoc_objDelete(param_1);
      return 0;
    }
  }
  return lVar2;
}


// ===== 003b03c0 _memmgrGetSurfaceComprInfo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _memmgrGetSurfaceComprInfo
              (long *param_1,int *param_2,undefined4 *param_3,int *param_4,int *param_5)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined1 local_58 [4];
  undefined4 local_54 [3];
  int local_48;
  int local_44;
  int local_40;
  
  lVar1 = *param_1;
  if ((lVar1 != 0) && ((*(char *)(lVar1 + 0x908) == '\0' || (*(char *)(lVar1 + 0x4913) != '\0')))) {
    lVar1 = *(long *)(lVar1 + 0x1b78);
    iVar3 = memmgrGetKindComprFromMemDesc_IMPL(lVar1,param_1,0,local_58,local_54);
    if (iVar3 == 0) {
      cVar2 = (**(code **)(lVar1 + 0x2a8))(lVar1,5,local_54[0]);
      if (cVar2 != '\0') {
        *param_4 = local_40;
        *param_5 = (local_40 + local_44) - local_48;
        *param_2 = local_48;
        *param_3 = 1;
        return 0;
      }
      *param_3 = 0;
      *param_2 = 0;
      *param_4 = -1;
      *param_5 = -1;
    }
    else {
      nvAssertOkFailedNoLog
                (iVar3,
                 "memmgrGetKindComprFromMemDesc(pMemoryManager, pMemDesc, 0, &unused, &comprInfo)",
                 "src/kernel/gpu/mem_mgr/mem_ctrl.c",0x4f);
    }
    return iVar3;
  }
  *param_3 = 0;
  *param_2 = 0;
  *param_4 = 0;
  *param_5 = 0;
  return 0;
}


// ===== 003b0520 memCtrlCmdGetSurfaceCompressionCoverageLvm_IMPL =====

void memCtrlCmdGetSurfaceCompressionCoverageLvm_IMPL(long param_1,int *param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long local_30 [2];
  
  uVar3 = *(undefined8 *)(param_1 + 0x118);
  if (*param_2 != 0) {
    lVar2 = resservGetTlsCallContext();
    iVar1 = subdeviceGetByHandle_IMPL(*(undefined8 *)(lVar2 + 8),*param_2,local_30);
    if (iVar1 != 0) {
      return;
    }
    memdescGetMemDescFromGpu(uVar3,*(undefined8 *)(*(long *)(local_30[0] + 0x158) + 0xe0));
    uVar3 = *(undefined8 *)(param_1 + 0x118);
  }
  _memmgrGetSurfaceComprInfo(uVar3,local_30,param_2 + 3,param_2 + 1,param_2 + 2);
  return;
}


// ===== 003b05d0 memCtrlCmdGetSurfaceInfoLvm_IMPL =====

undefined8 memCtrlCmdGetSurfaceInfoLvm_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  char cVar4;
  undefined8 uVar5;
  uint uVar6;
  long lVar7;
  undefined1 local_3c [4];
  undefined1 local_38 [2];
  uint local_36;
  undefined8 local_30;
  
  lVar2 = *(long *)(param_2 + 2);
  if ((*param_2 != 0) && (lVar7 = 0, lVar2 != 0)) {
    do {
      uVar6 = *(uint *)(lVar2 + lVar7 * 8);
      if (uVar6 == 5) {
        if (*(uint **)(param_1 + 0x1a8) == (uint *)0x0) {
LAB_003b07c0:
          uVar6 = 0;
        }
        else {
          uVar6 = 0;
          if ((**(uint **)(param_1 + 0x1a8) & 0x1000) != 0) {
            local_30 = 0;
            uVar5 = memdescFillMemdescForPhysAttr
                              (*(undefined8 *)(param_1 + 0x118),1,&local_30,local_3c,local_3c,
                               local_3c,local_3c,local_38);
            uVar6 = local_36;
            if ((int)uVar5 != 0) {
              return uVar5;
            }
          }
        }
      }
      else if (uVar6 < 6) {
        if (uVar6 == 2) {
          uVar6 = *(uint *)(*(long *)(param_1 + 0x118) + 0x30);
        }
        else if (uVar6 == 3) {
          uVar6 = *(uint *)(*(long *)(param_1 + 0x118) + 0x34);
        }
        else {
          if (uVar6 != 1) {
            return 0x1f;
          }
          if (*(uint **)(param_1 + 0x1a8) == (uint *)0x0) goto LAB_003b07c0;
          uVar1 = **(uint **)(param_1 + 0x1a8);
          uVar6 = uVar1 >> 0xb & 2;
          if ((uVar1 & 0x400) != 0) {
            uVar6 = uVar6 | 4;
          }
        }
      }
      else if (uVar6 == 8) {
        if (*(uint **)(param_1 + 0x1a8) == (uint *)0x0) goto LAB_003b07c0;
        uVar6 = **(uint **)(param_1 + 0x1a8) & 0xe1830000;
      }
      else if (uVar6 == 9) {
        uVar6 = memdescGetAddressSpace(*(undefined8 *)(param_1 + 0x118));
        if (uVar6 == 1) {
          cVar4 = memdescGetFlag(*(undefined8 *)(param_1 + 0x118),0x8000000);
          uVar6 = 3;
          if (cVar4 == '\0') {
            cVar4 = memdescGetFlag(*(undefined8 *)(param_1 + 0x118),0x10000000);
            uVar6 = 1;
            if (cVar4 != '\0') {
              uVar6 = 2;
            }
          }
        }
        else if (uVar6 != 2) {
          uVar6 = (uint)(uVar6 == 3) + (uint)(uVar6 == 3) * 2;
        }
      }
      else {
        if (uVar6 != 7) {
          return 0x1f;
        }
        uVar3 = *(ulong *)(*(long *)(param_1 + 0x118) + 0x30);
        uVar6 = (uint)(uVar3 >> 0xc);
        if (uVar3 >> 0x2c != 0) {
          nvAssertFailedNoLog("(NvU64)data == size","src/kernel/gpu/mem_mgr/mem_ctrl.c",0xd1);
          return 0x5b;
        }
      }
      *(uint *)(lVar2 + 4 + lVar7 * 8) = uVar6;
      lVar7 = lVar7 + 1;
    } while ((uint)lVar7 < *param_2);
  }
  return 0;
}


// ===== 003b0860 memCtrlCmdGetSurfacePhysAttrLvm_IMPL =====

ulong memCtrlCmdGetSurfacePhysAttrLvm_IMPL(long param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  undefined1 local_1c [4];
  
  uVar1 = memdescFillMemdescForPhysAttr
                    (*(undefined8 *)(param_1 + 0x118),1,param_2,param_2 + 0x14,param_2 + 8,
                     param_2 + 0x18,param_2 + 0x1c,param_2 + 0x28);
  if (uVar1 == 0) {
    uVar2 = _memmgrGetSurfaceComprInfo
                      (*(undefined8 *)(param_1 + 0x118),param_2 + 0xc,param_2 + 0x10,local_1c);
    if ((int)uVar2 != 0) {
      nvAssertOkFailedNoLog
                (uVar2 & 0xffffffff,
                 "_memmgrGetSurfaceComprInfo(pMemory->pMemDesc, &pGPAP->comprOffset, &pGPAP->comprFormat, &unused, &unused)"
                 ,"src/kernel/gpu/mem_mgr/mem_ctrl.c",0x123);
      uVar2 = uVar2 & 0xffffffff;
    }
    return uVar2;
  }
  nvAssertOkFailedNoLog
            (uVar1,
             "memdescFillMemdescForPhysAttr(pMemory->pMemDesc, AT_GPU, &pGPAP->memOffset, &pGPAP->memAperture, &pGPAP->memFormat, &pGPAP->gpuCacheAttr, &pGPAP->gpuP2PCacheAttr, &pGPAP->contigSegmentSize)"
             ,"src/kernel/gpu/mem_mgr/mem_ctrl.c",0x11e);
  return (ulong)uVar1;
}


// ===== 003b0930 memCtrlCmdSurfaceFlushGpuCache_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

undefined8 memCtrlCmdSurfaceFlushGpuCache_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  uint uVar6;
  int iVar7;
  
  lVar1 = *(long *)(param_1 + 0xf0);
  if (lVar1 == 0) {
    nvCheckFailedNoLog(4,"pGpu != NULL","src/kernel/gpu/mem_mgr/mem_ctrl.c",0x136);
    return 0x56;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_ctrl.c",0x138,"memCtrlCmdSurfaceFlushGpuCache_IMPL",1,
               "NVRM: \n");
  uVar6 = *param_2 & 2;
  if ((*param_2 & 1) == 0) {
    if (uVar6 == 0) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_ctrl.c",0x151,"memCtrlCmdSurfaceFlushGpuCache_IMPL",4
                   ,"NVRM: Must specify at least one of WRITE_BACK or INVALIDATE\n");
      return 0x1f;
    }
    iVar7 = 1;
  }
  else {
    iVar7 = 3 - (uint)(uVar6 == 0);
  }
  if (*(long *)(param_1 + 0x118) != 0) {
    if (*(int *)(*(long *)(param_1 + 0x118) + 0x6c) == 0) {
      iVar3 = memdescGetAddressSpace();
      if ((iVar3 == 1) || (iVar3 == 2)) {
        pcVar2 = *(code **)(*(long *)(lVar1 + 0x1b70) + 0x188);
        uVar5 = (*pcVar2)(lVar1,*(long *)(lVar1 + 0x1b70),*(undefined8 *)(param_1 + 0x118),iVar3,
                          iVar7,pcVar2);
        return uVar5;
      }
      uVar4 = memdescGetAddressSpace(*(undefined8 *)(param_1 + 0x118));
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_ctrl.c",0x170,"memCtrlCmdSurfaceFlushGpuCache_IMPL",4
                   ,"NVRM: Cannot flush address space 0x%x\n",uVar4);
    }
    else {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_ctrl.c",0x162,"memCtrlCmdSurfaceFlushGpuCache_IMPL",4
                   ,"NVRM: Cannot flush an uncached allocation\n");
    }
    return 0x1f;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_ctrl.c",0x159,"memCtrlCmdSurfaceFlushGpuCache_IMPL",4,
               "NVRM: Memory descriptor not found for hMemory 0x%x, unable to flush!\n",
               *(undefined4 *)(*(long *)(*(long *)(param_1 + 0xb8) + 0x48) + 0x10));
  return 0x40;
}


// ===== 003b0b40 memCtrlCmdGetMemPageSize_IMPL =====

undefined8 memCtrlCmdGetMemPageSize_IMPL(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = memdescGetPageSize(*(undefined8 *)(param_1 + 0x118),1);
  *param_2 = uVar1;
  return 0;
}


// ===== 003b0b70 memCtrlCmdSetTag_IMPL =====

undefined8 memCtrlCmdSetTag_IMPL(long param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x19c) = *param_2;
  return 0;
}


// ===== 003b0b80 memCtrlCmdGetTag_IMPL =====

undefined8 memCtrlCmdGetTag_IMPL(long param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x19c);
  return 0;
}


// ===== 003b0b90 memCtrlCmdMapMemoryForGpuAccess_IMPL =====

int memCtrlCmdMapMemoryForGpuAccess_IMPL(long param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  long local_30 [2];
  
  lVar3 = resservGetTlsCallContext();
  uVar1 = *(undefined8 *)(param_1 + 0x118);
  iVar2 = memdescGetAddressSpace(uVar1);
  if (iVar2 == 1) {
    iVar2 = subdeviceGetByHandle_IMPL(*(undefined8 *)(lVar3 + 8),*param_2,local_30);
    if (iVar2 == 0) {
      iVar2 = memdescMapIommu(uVar1,*(undefined4 *)
                                     (*(long *)(*(long *)(local_30[0] + 0x158) + 0xe0) + 0x868));
      if (iVar2 == 0) {
        memdescGetPhysAddrsForGpu
                  (uVar1,*(undefined8 *)(*(long *)(local_30[0] + 0x158) + 0xe0),1,0,0,1,param_2 + 2)
        ;
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar2,
                   "memdescMapIommu(pMemDesc, GPU_RES_GET_GPU(pSubdevice)->busInfo.iovaspaceId)",
                   "src/kernel/gpu/mem_mgr/mem_ctrl.c",0x1d3);
      }
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar2,
                 "subdeviceGetByHandle(pCallContext->pClient, pParams->hSubdevice, &pSubdevice)",
                 "src/kernel/gpu/mem_mgr/mem_ctrl.c",0x1d2);
    }
    return iVar2;
  }
  nvCheckFailedNoLog(4,"memdescGetAddressSpace(pMemDesc) == ADDR_SYSMEM",
                     "src/kernel/gpu/mem_mgr/mem_ctrl.c",0x1d1);
  return 0x1f;
}


// ===== 003b0cd0 memCtrlCmdUnmapMemoryForGpuAccess_IMPL =====

int memCtrlCmdUnmapMemoryForGpuAccess_IMPL(long param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  long local_30;
  
  lVar3 = resservGetTlsCallContext();
  uVar1 = *(undefined8 *)(param_1 + 0x118);
  iVar2 = memdescGetAddressSpace(uVar1);
  if (iVar2 == 1) {
    iVar2 = subdeviceGetByHandle_IMPL(*(undefined8 *)(lVar3 + 8),*param_2,&local_30);
    if (iVar2 == 0) {
      memdescUnmapIommu(uVar1,*(undefined4 *)(*(long *)(*(long *)(local_30 + 0x158) + 0xe0) + 0x868)
                       );
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar2,
                 "subdeviceGetByHandle(pCallContext->pClient, pParams->hSubdevice, &pSubdevice)",
                 "src/kernel/gpu/mem_mgr/mem_ctrl.c",0x1e6);
    }
    return iVar2;
  }
  nvCheckFailedNoLog(4,"memdescGetAddressSpace(pMemDesc) == ADDR_SYSMEM",
                     "src/kernel/gpu/mem_mgr/mem_ctrl.c",0x1e5);
  return 0x1f;
}


// ===== 003b0db0 memdescGetMapInternalType =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

int memdescGetMapInternalType(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  char local_9;
  
  if ((*(int *)(param_2 + 0x68) == 2) && (*(char *)(param_1 + 0x454) != '\0')) {
    return 1;
  }
  lVar1 = *(long *)(&DAT_00001b90 + param_1);
  if (lVar1 == 0) {
    return 3;
  }
  local_9 = '\0';
  iVar2 = (**(code **)(lVar1 + 0x410))(param_1,lVar1,param_2,&local_9,*(code **)(lVar1 + 0x410));
  if (iVar2 == 0) {
    return 3 - (uint)(local_9 == '\0');
  }
  nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/mem_desc.c",0x7de);
  return 2;
}


// ===== 003b0e40 _memdescSetSubAllocatorFlag =====

int _memdescSetSubAllocatorFlag(long param_1,long param_2,char param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pGpu != NULL","src/kernel/gpu/mem_mgr/mem_desc.c",0x7b);
    return 0x1f;
  }
  if (param_3 == '\0') {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0x7f,"_memdescSetSubAllocatorFlag",4,
                 "NVRM: Unsetting MEMDESC_FLAGS_OWNED_BY_CURRENT_DEVICE not supported\n");
    nvAssertFailedNoLog(&DAT_00d4c747,"src/kernel/gpu/mem_mgr/mem_desc.c",0x81);
    return 0x1f;
  }
  uVar3 = *(ulong *)(param_2 + 8);
  if ((uVar3 >> 0x24 & 1) != 0) {
    nvAssertFailedNoLog("!(pMemDesc->_flags & MEMDESC_FLAGS_OWNED_BY_CTX_BUF_POOL)",
                        "src/kernel/gpu/mem_mgr/mem_desc.c",0x85);
    uVar3 = *(ulong *)(param_2 + 8);
  }
  *(ulong *)(param_2 + 8) = uVar3 | 0x2000000;
  lVar2 = *(long *)(param_2 + 0xa0);
  if (lVar2 == 0) {
    lVar2 = memmgrGetDeviceSuballocator_IMPL
                      (*(undefined8 *)(param_1 + 0x1b78),(ushort)(uVar3 >> 0x30) & 1);
    if (lVar2 == 0) {
      nvAssertFailedNoLog("pHeap != NULL","src/kernel/gpu/mem_mgr/mem_desc.c",0x98);
      return 0x40;
    }
  }
  else {
    if (*(int *)(lVar2 + 0x4c) == 1) goto LAB_003b0eca;
    nvAssertFailedNoLog("pHeap == NULL || pHeap->heapType == HEAP_TYPE_PHYS_MEM_SUBALLOCATOR",
                        "src/kernel/gpu/mem_mgr/mem_desc.c",0x8e);
  }
  if (*(int *)(lVar2 + 0x4c) != 1) {
    return 0;
  }
LAB_003b0eca:
  iVar1 = vgpuGetCallingContextGfid(param_1,param_2 + 0xa8);
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog
              (iVar1,"vgpuGetCallingContextGfid(pGpu, &pMemDesc->gfid)",
               "src/kernel/gpu/mem_mgr/mem_desc.c",0x9c);
    return iVar1;
  }
  *(undefined1 *)(param_2 + 0x66) = 1;
  return 0;
}


// ===== 003b1020 memdescIsEgm.part.0 =====

undefined4 memdescIsEgm_part_0(long *param_1)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  undefined4 uVar5;
  
  lVar4 = param_1[0xd];
  lVar2 = param_1[0x19];
  plVar3 = param_1;
  while (lVar2 != 0) {
    if (*(char *)((long)plVar3 + 100) != '\0') {
      nvAssertFailedNoLog("!pMemDesc->Allocated","src/kernel/gpu/mem_mgr/mem_desc.c",0x1030);
    }
    plVar3 = (long *)plVar3[0x19];
    lVar2 = plVar3[0x19];
  }
  if ((((*plVar3 == 0) || (lVar2 = *(long *)(*plVar3 + 0x1b78), lVar2 == 0)) ||
      (*(char *)(lVar2 + 0x454) == '\0')) ||
     (((int)lVar4 != 1 || (iVar1 = *(int *)(lVar2 + 0x45c), iVar1 == -1)))) {
    uVar5 = 0;
  }
  else {
    uVar5 = CONCAT31((int3)((uint)iVar1 >> 8),*(int *)((long)param_1 + 0x164) == iVar1);
  }
  return uVar5;
}


// ===== 003b10f0 memdescAddrSpaceListToU32 =====

long memdescAddrSpaceListToU32(undefined8 *param_1)

{
  if (param_1 == (undefined8 *)ADDRLIST_FBMEM_PREFERRED) {
    return 1;
  }
  if (param_1 != (undefined8 *)ADDRLIST_SYSMEM_PREFERRED) {
    if (param_1 != &ADDRLIST_FBMEM_ONLY) {
      return (ulong)(param_1 == &ADDRLIST_SYSMEM_ONLY) << 2;
    }
    return 3;
  }
  return 2;
}


// ===== 003b1150 memdescU32ToAddrSpaceList =====

undefined8 memdescU32ToAddrSpaceList(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 - 1U < 4) {
    uVar1 = *(undefined8 *)(CSWTCH_179 + (ulong)(param_1 - 1U) * 8);
  }
  return uVar1;
}


// ===== 003b1170 memdescCalculateActualSize =====

undefined8 memdescCalculateActualSize(long param_1,ulong param_2,ulong *param_3)

{
  long lVar1;
  ulong uVar2;
  
  if (param_2 == 0) {
    return 0x1f;
  }
  if ((*(uint *)(param_1 + 0x68) < 2) && ((*(byte *)(param_1 + 0xc) & 0x10) == 0)) {
    lVar1 = osGetPageSize();
    uVar2 = -lVar1 & (param_2 - 1) + lVar1;
    if (param_2 <= uVar2) {
      *param_3 = uVar2;
      return 0;
    }
    return 0x1f;
  }
  *param_3 = param_2;
  return 0;
}


// ===== 003b11e0 memdescCreate =====

int memdescCreate(long *param_1,long param_2,ulong param_3,long param_4,char param_5,int param_6,
                 undefined4 param_7,ulong param_8)

{
  long *plVar1;
  bool bVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  long local_48;
  
  uVar8 = param_3;
  if (param_6 == 0) {
    if (param_3 == 0) {
      return 0x1f;
    }
LAB_003b1218:
    if ((param_8 >> 0x24 & 1) == 0) {
      lVar5 = osGetPageSize();
      uVar8 = (param_3 - 1) + lVar5 & -lVar5;
      if (uVar8 < param_3) {
        return 0x1f;
      }
    }
  }
  else if (((param_8 & 0x80) == 0) ||
          ((*(char *)(param_2 + 0x44d) != '\0' && (*(char *)(param_2 + 0x4921) == '\0')))) {
    if (param_3 == 0) {
      return 0x1f;
    }
    if (param_6 == 1) goto LAB_003b1218;
  }
  else {
    param_6 = 2;
    if (param_3 == 0) {
      return 0x1f;
    }
  }
  if (param_5 == '\0') {
    uVar7 = uVar8 - 1 >> 0xc;
    uVar6 = uVar7 * 8 + 0x180;
    if (uVar6 >> 0x20 != 0) {
      nvAssertFailedNoLog("MdSize <= 0xffffffffULL","src/kernel/gpu/mem_mgr/mem_desc.c",0x16a);
      return 0x1a;
    }
    if ((param_8 & 0x1000) != 0) {
      return 0x56;
    }
    if ((param_8 & 8) != 0) {
      return 2;
    }
    local_48 = uVar7 + 2;
LAB_003b1470:
    plVar4 = (long *)portMemAllocNonPaged(uVar6);
    if (plVar4 == (long *)0x0) {
      return 0x51;
    }
    bVar2 = false;
  }
  else {
    if ((param_8 & 0x1000) != 0) {
      return 0x56;
    }
    if ((param_8 & 8) == 0) {
      local_48 = 1;
      uVar6 = 0x178;
      goto LAB_003b1470;
    }
    local_48 = 1;
    uVar6 = 0x178;
    bVar2 = true;
    plVar4 = (long *)*param_1;
    if (plVar4 == (long *)0x0) {
      nvAssertFailedNoLog("*ppMemDesc","src/kernel/gpu/mem_mgr/mem_desc.c",0x17d);
      return 0x56;
    }
  }
  portMemSet(plVar4,0,uVar6);
  *plVar4 = param_2;
  plVar4[4] = local_48;
  plVar4[0x12] = 0x100000001;
  *(undefined8 *)((long)plVar4 + 0x6c) = 0x100000001;
  *(undefined2 *)((long)plVar4 + 0x65) = 0;
  plVar4[0x2c] = -0xfffff000;
  plVar4[6] = param_3;
  *(undefined4 *)((long)plVar4 + 0x74) = param_7;
  plVar4[7] = uVar8;
  *(int *)(plVar4 + 0xd) = param_6;
  uVar8 = param_8 & 0xfffffffffffffbff | 0x200;
  if (param_5 != '\0') {
    uVar8 = param_8 | 0x600;
  }
  *(undefined4 *)((long)plVar4 + 0x8c) = 1;
  plVar4[5] = param_4;
  *(undefined4 *)(plVar4 + 0x15) = 0;
  plVar4[1] = uVar8;
  if ((param_8 >> 0x24 & 1) == 0) {
    if (((param_8 & 0x2000000) != 0) &&
       (iVar3 = _memdescSetSubAllocatorFlag(param_2,plVar4,1), iVar3 != 0)) {
      nvAssertOkFailedNoLog
                (iVar3,"_memdescSetSubAllocatorFlag(pGpu, pMemDesc, NV_TRUE)",
                 "src/kernel/gpu/mem_mgr/mem_desc.c",0x1b2);
      goto LAB_003b142d;
    }
  }
  else {
    plVar4[1] = uVar8 & 0xfffffffffdffffff | 0x1000000000;
  }
  if ((param_8 & 0x100) == 0) {
joined_r0x003b13a7:
    if ((param_8 >> 0x32 & 1) != 0) {
      lVar5 = plVar4[0x19];
      plVar1 = plVar4;
      while (lVar5 != 0) {
        if (*(char *)((long)plVar1 + 100) != '\0') {
          nvAssertFailedNoLog("!pMemDesc->Allocated","src/kernel/gpu/mem_mgr/mem_desc.c",0x1030);
        }
        plVar1 = (long *)plVar1[0x19];
        lVar5 = plVar1[0x19];
      }
      plVar4[0x2b] = *(long *)(*(long *)(*plVar1 + 0x1b78) + 0xd38);
    }
    *param_1 = (long)plVar4;
    return 0;
  }
  if (param_2 == 0) {
    nvAssertFailedNoLog("pGpu != NULL","src/kernel/gpu/mem_mgr/mem_desc.c",0xb0);
    iVar3 = 0x1f;
  }
  else {
    iVar3 = vgpuGetCallingContextGfid(param_2,plVar4 + 0x15);
    if (iVar3 == 0) {
      plVar4[1] = plVar4[1] | 0x100;
      goto joined_r0x003b13a7;
    }
    nvAssertOkFailedNoLog
              (iVar3,"vgpuGetCallingContextGfid(pGpu, &pMemDesc->gfid)",
               "src/kernel/gpu/mem_mgr/mem_desc.c",0xba);
  }
  nvAssertOkFailedNoLog
            (iVar3,"_memdescSetGuestAllocatedFlag(pGpu, pMemDesc, NV_TRUE)",
             "src/kernel/gpu/mem_mgr/mem_desc.c",0x1b8);
LAB_003b142d:
  if (!bVar2) {
    portMemFree(plVar4);
    return iVar3;
  }
  return iVar3;
}


// ===== 003b1680 memdescCreateExisting =====

void memdescCreateExisting
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 param_5,ulong param_6)

{
  int iVar1;
  undefined8 local_10;
  
  local_10 = param_1;
  iVar1 = memdescCreate(&local_10,param_2,param_3,0,1,param_4,param_5);
  if (iVar1 == 0) {
    return;
  }
  nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/mem_desc.c",0x1fb,param_6 | 0x20008)
  ;
  return;
}


// ===== 003b16e0 memdescAddRef =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void memdescAddRef(long param_1)

{
  if (param_1 != 0) {
    *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + 1;
    return;
  }
  nvAssertFailedNoLog("pMemDesc != NULL","src/kernel/gpu/mem_mgr/mem_desc.c",0x207);
  _DAT_00000090 = _DAT_00000090 + 1;
  return;
}


// ===== 003b1730 memdescRemoveRef =====

void memdescRemoveRef(long param_1)

{
  if (param_1 != 0) {
    *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + -1;
    return;
  }
  nvAssertFailedNoLog("pMemDesc != NULL","src/kernel/gpu/mem_mgr/mem_desc.c",0x213);
  return;
}


// ===== 003b1760 memdescLock =====

undefined8 memdescLock(long param_1)

{
  undefined8 uVar1;
  
  if (1 < *(uint *)(param_1 + 0x8c)) {
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c"
                        ,0x675);
    if ((*(byte *)(param_1 + 9) & 0x10) != 0) {
      uVar1 = osLockMem(param_1);
      return uVar1;
    }
    return 0x16;
  }
  if ((*(byte *)(param_1 + 9) & 0x10) != 0) {
    uVar1 = osLockMem();
    return uVar1;
  }
  return 0x16;
}


// ===== 003b17e0 memdescUnlock =====

undefined8 memdescUnlock(long param_1)

{
  undefined8 uVar1;
  
  if (1 < *(uint *)(param_1 + 0x8c)) {
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c"
                        ,0x68b);
    if ((*(byte *)(param_1 + 9) & 0x10) != 0) {
      uVar1 = osUnlockMem(param_1);
      return uVar1;
    }
    return 0x16;
  }
  if ((*(byte *)(param_1 + 9) & 0x10) != 0) {
    uVar1 = osUnlockMem();
    return uVar1;
  }
  return 0x16;
}


// ===== 003b1860 memdescUnmap =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void memdescUnmap(long *param_1,char param_2,long param_3,undefined8 *param_4)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  
  if (param_3 == 0) {
    return;
  }
  if (1 < *(uint *)((long)param_1 + 0x8c)) {
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c"
                        ,0x77f);
  }
  if ((int)param_1[0xd] != 1) {
    if ((int)param_1[0xd] == 2) {
      lVar2 = *param_1;
      uVar3 = param_4[1];
      lVar4 = *(long *)(&DAT_00001b90 + lVar2);
      cVar1 = *(char *)(lVar2 + 0x454);
      if ((*(byte *)((long)param_1 + 10) & 0x40) != 0) {
        nvAssertFailedNoLog("!(pMemDesc->_flags & MEMDESC_FLAGS_CPU_ONLY)",
                            "src/kernel/gpu/mem_mgr/mem_desc.c",0x791);
      }
      if (cVar1 == '\0') {
        kbusUnmapFbApertureSingle_IMPL(lVar2,lVar4,param_1,*param_4,uVar3,0x20);
        if (param_2 == '\0') {
          osUnmapPciMemoryUser(*(undefined8 *)(lVar2 + 0x4e0),param_3,uVar3,param_4[2]);
        }
        else {
          osUnmapPciMemoryKernel64(lVar2,param_3);
        }
      }
      else if (param_2 == '\0') {
        osUnmapPciMemoryUser(*(undefined8 *)(lVar2 + 0x4e0),param_3,uVar3);
      }
      else {
        (**(code **)(lVar4 + 0x520))
                  (lVar2,lVar4,param_1,param_3,param_4[2],*(code **)(lVar4 + 0x520));
      }
      portMemFree(param_4);
      return;
    }
    return;
  }
  osUnmapSystemMemory(param_1,param_2,param_3,param_4);
  return;
}


// ===== 003b1a60 memdescUnmapOld =====

void memdescUnmapOld(undefined8 param_1,undefined1 param_2)

{
  memdescUnmap(param_1,param_2);
  return;
}


// ===== 003b1a70 memdescFlushCpuCaches =====

void memdescFlushCpuCaches(long param_1,long param_2)

{
  short sVar1;
  
  osFlushCpuWriteCombineBuffer();
  if (*(long *)(param_1 + 7000) != 0) {
    sVar1 = kbifGetDmaCaps_IMPL(param_1);
    if ((sVar1 == 0) && (*(int *)(param_2 + 0x74) == 0)) {
      osFlushCpuCache();
      return;
    }
  }
  return;
}


// ===== 003b1ac0 memdescDescribe =====

void memdescDescribe(long *param_1,undefined4 param_2,ulong param_3,long param_4)

{
  ulong uVar1;
  char cVar2;
  uint uVar3;
  
  if ((((int)param_1[0x12] != 1) || (param_1[0x18] != 0)) || ((int)param_1[0xc] != 0)) {
    nvAssertFailedNoLog("(pMemDesc->RefCount == 1) && (memdescGetDestroyCallbackList(pMemDesc) == NULL) && (pMemDesc->PteAdjust == 0)"
                        ,"src/kernel/gpu/mem_mgr/mem_desc.c",0x8d1);
  }
  if (param_1[0x21] == 0) {
    cVar2 = *(char *)((long)param_1 + 100);
  }
  else {
    nvAssertFailedNoLog("pMemDesc->_pIommuMappings == NULL","src/kernel/gpu/mem_mgr/mem_desc.c",
                        0x8d5);
    cVar2 = *(char *)((long)param_1 + 100);
  }
  if (cVar2 == '\0') {
    uVar3 = *(uint *)((long)param_1 + 0x8c);
  }
  else {
    nvAssertFailedNoLog("pMemDesc->Allocated == 0","src/kernel/gpu/mem_mgr/mem_desc.c",0x8d6);
    uVar3 = *(uint *)((long)param_1 + 0x8c);
  }
  if (1 < uVar3) {
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c"
                        ,0x8d7);
  }
  if (*param_1 == 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0x8e5,"memdescDescribe",3,
                 "NVRM: unable to check Base 0x%016llx for DMA window\n",param_3);
  }
  if ((param_1[5] != 0) && (param_3 - param_3 % (ulong)param_1[5] != param_3)) {
    nvAssertFailedNoLog("NV_FLOOR_TO_QUANTA(Base, pMemDesc->Alignment) == Base",
                        "src/kernel/gpu/mem_mgr/mem_desc.c",0x8eb);
  }
  param_1[1] = param_1[1] | 0x400;
  uVar3 = (uint)param_3 & 0xfff;
  param_1[6] = param_4;
  *(uint *)(param_1 + 0xc) = uVar3;
  uVar1 = (ulong)uVar3 + 0xfff + param_4;
  *(undefined4 *)(param_1 + 0xd) = param_2;
  param_1[7] = uVar1 & 0xfffffffffffff000;
  param_1[0x2e] = param_3 - uVar3;
  param_1[3] = uVar1 >> 0xc;
  return;
}


// ===== 003b1c80 memdescAcquireRmExclusiveUse =====

undefined8 memdescAcquireRmExclusiveUse(long param_1)

{
  if (((*(long *)(param_1 + 200) == 0) && (*(char *)(param_1 + 0xf0) == '\0')) &&
     (*(int *)(param_1 + 0x94) == 1)) {
    *(undefined1 *)(param_1 + 0xf0) = 1;
    return 1;
  }
  nvCheckFailedNoLog(4,
                     "pMemDesc->_pParentDescriptor == NULL && !pMemDesc->bRmExclusiveUse && pMemDesc->DupCount == 1"
                     ,"src/kernel/gpu/mem_mgr/mem_desc.c",0x994);
  return 0;
}


// ===== 003b1ce0 memdescGetPteArraySize =====

undefined4 memdescGetPteArraySize(long *param_1,long param_2)

{
  ulong uVar1;
  
  uVar1 = param_1[1];
  if (((uVar1 & 0x400) != 0) &&
     ((((param_2 != 2 || ((int)param_1[0xd] != 2)) || (*(char *)(*param_1 + 0x491d) == '\0')) ||
      ((((uVar1 & 0x2000000) == 0 || (*(char *)((long)param_1 + 0x66) == '\0')) &&
       ((uVar1 & 0x100) == 0)))))) {
    return 1;
  }
  return (int)param_1[3];
}


// ===== 003b1d40 _memdescUpdateSpaArray =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _memdescUpdateSpaArray(long *param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined4 *puVar4;
  long *plVar5;
  uint uVar6;
  ulong uVar7;
  long lVar8;
  uint uVar9;
  uint uVar10;
  
  if (param_1[0x28] == 0) {
    iVar2 = 0;
    if (param_1[3] == 0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      lVar8 = *param_1;
      uVar1 = memdescGetPteArraySize(param_1,2);
      lVar3 = portMemAllocNonPaged((ulong)uVar1 << 3);
      param_1[0x28] = lVar3;
      if (lVar3 == 0) {
        lVar8 = 0;
        iVar2 = 0x51;
        puVar4 = (undefined4 *)0x0;
      }
      else {
        puVar4 = (undefined4 *)portMemAllocNonPaged(0x808);
        if (puVar4 != (undefined4 *)0x0) {
          portMemSet(puVar4,0,0x808);
          *puVar4 = (int)param_1[0x15];
          if (uVar1 != 0) {
            uVar9 = 0;
            do {
              uVar10 = uVar1 - uVar9;
              if (0x80 < uVar10) {
                uVar10 = 0x80;
              }
              puVar4[1] = uVar10;
              if ((*(byte *)((long)param_1 + 9) & 4) == 0) {
                portMemCopy(puVar4 + 2,(ulong)uVar10 << 3,param_1 + (uVar9 + 0x2e),
                            (ulong)uVar10 << 3);
              }
              else {
                plVar5 = (long *)(puVar4 + 2);
                uVar6 = uVar9;
                do {
                  uVar7 = (ulong)uVar6;
                  uVar6 = uVar6 + 1;
                  *plVar5 = *(uint *)(param_1 + 0x2c) * uVar7 + param_1[0x2e];
                  plVar5 = plVar5 + 1;
                } while (uVar9 + uVar10 != uVar6);
              }
              iVar2 = (**(code **)(lVar8 + 0x3b90))
                                (lVar8 + 0x3b58,*(undefined4 *)(*param_1 + 0x3b34),
                                 *(undefined4 *)(*param_1 + 0x3b3c),0x20800a57,puVar4,0x808);
              if (iVar2 != 0) {
                nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0xadc,"_memdescUpdateSpaArray",4,
                             "NVRM: Getting SPA for GPA failed: GFID=%u, GPA=0x%llx\n",
                             (int)param_1[0x15],param_1[(ulong)uVar9 + 0x2e]);
                lVar8 = param_1[0x28];
                goto LAB_003b1f40;
              }
              uVar7 = (ulong)uVar9;
              uVar9 = uVar9 + 0x80;
              portMemCopy(param_1[0x28] + uVar7 * 8,(ulong)uVar10 << 3,puVar4 + 0x102,
                          (ulong)uVar10 << 3);
            } while (uVar9 < uVar1);
            iVar2 = 0;
          }
          goto LAB_003b1d66;
        }
        lVar8 = param_1[0x28];
        iVar2 = 0x51;
      }
LAB_003b1f40:
      portMemFree(lVar8);
      param_1[0x28] = 0;
    }
  }
  else {
    puVar4 = (undefined4 *)0x0;
    iVar2 = 0;
  }
LAB_003b1d66:
  portMemFree(puVar4);
  return iVar2;
}


// ===== 003b2000 memdescGetPteArrayForGpu =====

long * memdescGetPteArrayForGpu(long *param_1,long param_2,long param_3)

{
  ulong uVar1;
  char cVar2;
  long lVar3;
  int *piVar4;
  
  if (1 < *(uint *)((long)param_1 + 0x8c)) {
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c"
                        ,0xc3e);
  }
  if (param_3 == 1) {
    if (param_2 == 0) goto LAB_003b209d;
    lVar3 = *param_1;
LAB_003b2040:
    if (lVar3 != 0) goto LAB_003b2045;
  }
  else {
    if ((param_3 != 2) || (param_2 == 0)) goto LAB_003b209d;
    lVar3 = *param_1;
    if ((int)param_1[0xd] != 2) goto LAB_003b2040;
    if (*(char *)(lVar3 + 0x491d) != '\0') {
      uVar1 = param_1[1];
      if ((uVar1 & 0x2000000) != 0) {
        if ((*(char *)((long)param_1 + 0x66) != '\0') || ((uVar1 & 0x100) != 0)) goto LAB_003b20f2;
        goto LAB_003b2040;
      }
      if ((uVar1 & 0x100) != 0) {
LAB_003b20f2:
        if ((long *)param_1[0x28] != (long *)0x0) {
          return (long *)param_1[0x28];
        }
        _memdescUpdateSpaArray(param_1);
        return (long *)param_1[0x28];
      }
    }
LAB_003b2045:
    cVar2 = memdescIsEgm_part_0(param_1);
    if ((cVar2 != '\0') && ((long *)param_1[0x2d] != (long *)0x0)) {
      return (long *)param_1[0x2d];
    }
  }
  piVar4 = (int *)param_1[0x21];
  if (piVar4 != (int *)0x0) {
    do {
      if (*(int *)(param_2 + 0x868) == *piVar4) {
        return (long *)(piVar4 + 10);
      }
      piVar4 = *(int **)(piVar4 + 6);
    } while (piVar4 != (int *)0x0);
  }
LAB_003b209d:
  return param_1 + 0x2e;
}


// ===== 003b2170 __pfx_memdescGetPhysAddrsForGpu =====

void __pfx_memdescGetPhysAddrsForGpu
               (long param_1,undefined8 param_2,undefined8 param_3,long param_4,long param_5,
               long param_6,long param_7)

{
  uint uVar1;
  int iVar2;
  long *plVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  
  plVar3 = (long *)memdescGetPteArrayForGpu();
  iVar2 = memdescGetPteArraySize(param_1,param_3);
  uVar1 = *(uint *)(param_1 + 0x160);
  if (1 < *(uint *)(param_1 + 0x8c)) {
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c"
                        ,0xb10);
  }
  if (param_6 != 0) {
    uVar4 = (ulong)*(uint *)(param_1 + 0x60) + param_4;
    if (iVar2 == 1) {
      lVar6 = 0;
      do {
        lVar5 = *plVar3 + uVar4;
        uVar4 = uVar4 + param_5;
        *(long *)(param_7 + lVar6 * 8) = lVar5;
        lVar6 = lVar6 + 1;
      } while (lVar6 != param_6);
    }
    else {
      lVar6 = 0;
      do {
        uVar8 = uVar4 >> (((uVar1 & 0xff00ff00) != 0) << 3 | ((uVar1 & 0xffff0000) != 0) << 4 |
                          (uVar1 & 0xaaaaaaaa) != 0 | ((uVar1 & 0xf0f0f0f0) != 0) << 2 |
                         ((uVar1 & 0xcccccccc) != 0) * '\x02');
        if (*(ulong *)(param_1 + 0x18) <= uVar8) {
          nvCheckFailedNoLog(4,"pageIndex < pMemDesc->PageCount","src/kernel/gpu/mem_mgr/mem_desc.c"
                             ,0xb1c);
          return;
        }
        uVar7 = uVar1 - 1 & uVar4;
        uVar4 = uVar4 + param_5;
        *(ulong *)(param_7 + lVar6 * 8) = uVar7 + plVar3[uVar8];
        lVar6 = lVar6 + 1;
      } while (param_6 != lVar6);
    }
  }
  return;
}


// ===== 003b2180 memdescGetPhysAddrsForGpu =====

void memdescGetPhysAddrsForGpu
               (long param_1,undefined8 param_2,undefined8 param_3,long param_4,long param_5,
               long param_6,long param_7)

{
  uint uVar1;
  int iVar2;
  long *plVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  
  plVar3 = (long *)memdescGetPteArrayForGpu();
  iVar2 = memdescGetPteArraySize(param_1,param_3);
  uVar1 = *(uint *)(param_1 + 0x160);
  if (1 < *(uint *)(param_1 + 0x8c)) {
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c"
                        ,0xb10);
  }
  if (param_6 != 0) {
    uVar4 = (ulong)*(uint *)(param_1 + 0x60) + param_4;
    if (iVar2 == 1) {
      lVar6 = 0;
      do {
        lVar5 = *plVar3 + uVar4;
        uVar4 = uVar4 + param_5;
        *(long *)(param_7 + lVar6 * 8) = lVar5;
        lVar6 = lVar6 + 1;
      } while (lVar6 != param_6);
    }
    else {
      lVar6 = 0;
      do {
        uVar8 = uVar4 >> (((uVar1 & 0xff00ff00) != 0) << 3 | ((uVar1 & 0xffff0000) != 0) << 4 |
                          (uVar1 & 0xaaaaaaaa) != 0 | ((uVar1 & 0xf0f0f0f0) != 0) << 2 |
                         ((uVar1 & 0xcccccccc) != 0) * '\x02');
        if (*(ulong *)(param_1 + 0x18) <= uVar8) {
          nvCheckFailedNoLog(4,"pageIndex < pMemDesc->PageCount","src/kernel/gpu/mem_mgr/mem_desc.c"
                             ,0xb1c);
          return;
        }
        uVar7 = uVar1 - 1 & uVar4;
        uVar4 = uVar4 + param_5;
        *(ulong *)(param_7 + lVar6 * 8) = uVar7 + plVar3[uVar8];
        lVar6 = lVar6 + 1;
      } while (param_6 != lVar6);
    }
  }
  return;
}


// ===== 003b2340 memdescGetPhysAddrs =====

undefined1  [16]
memdescGetPhysAddrs(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined8 param_5,undefined8 param_6)

{
  undefined1 auVar1 [16];
  undefined8 uStack_10;
  
  memdescGetPhysAddrsForGpu(param_1,*param_1,param_2,param_3,param_4,param_5);
  auVar1._8_8_ = uStack_10;
  auVar1._0_8_ = param_6;
  return auVar1;
}


// ===== 003b2370 memdescGetPhysAddr =====

undefined8 memdescGetPhysAddr(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_10;
  
  memdescGetPhysAddrsForGpu(param_1,*param_1,param_2,param_3,0,1,&local_10);
  return local_10;
}


// ===== 003b23a0 memdescPrintMemdesc.part.0 =====

void memdescPrintMemdesc_part_0(undefined8 *param_1,char param_2,undefined8 param_3)

{
  undefined8 uVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined8 local_40 [2];
  
  uVar1 = param_1[6];
  memdescGetPhysAddrsForGpu(param_1,*param_1,0,0,0,1,local_40);
  pcVar2 = "VIDEO MEMORY";
  if ((*(int *)(param_1 + 0xd) != 2) && (pcVar2 = "SYSTEM MEMORY", *(int *)(param_1 + 0xd) != 1)) {
    pcVar2 = (char *)0x0;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0xdff,"memdescPrintMemdesc",1,
               "NVRM: %s Aperture %s starting at 0x%llx and of size 0x%llx\n",param_3,pcVar2,
               local_40[0],uVar1);
  if (((param_2 == '\x01') && (1 < (ulong)param_1[3])) && ((*(byte *)((long)param_1 + 9) & 4) == 0))
  {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0xe0a,"memdescPrintMemdesc",1,
                 "NVRM:      contains total of %llu pages\n");
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0xe0b,"memdescPrintMemdesc",1,
                 "NVRM:      contains first page starting @0x%llx\n",param_1[0x2e]);
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0xe0d,"memdescPrintMemdesc",1,
                 "NVRM:      contains last page starting @0x%llx\n",param_1[param_1[3] + 0x2d]);
  }
  puVar3 = (undefined4 *)param_1[0x21];
  if (puVar3 != (undefined4 *)0x0) {
    if (param_1[0x19] != 0) {
      memdescGetPhysAddrsForGpu(param_1,*param_1,2,0,0,1,local_40);
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0xe22,"memdescPrintMemdesc",1,
                   "NVRM: Has additional IOMMU mapping starting @ 0x%llx\n",local_40[0]);
      return;
    }
    do {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0xe19,"memdescPrintMemdesc",1,
                   "NVRM: Has additional IOMMU mapping for IOVA space 0x%x starting @ 0x%llx\n",
                   *puVar3,*(undefined8 *)(puVar3 + 10));
      puVar3 = *(undefined4 **)(puVar3 + 6);
    } while (puVar3 != (undefined4 *)0x0);
  }
  return;
}


// ===== 003b25c0 memdescFree =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void memdescFree(long *param_1)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  int iVar7;
  long lVar8;
  
  if (param_1 == (long *)0x0) {
    return;
  }
  if (param_1[0x19] == 0) {
    cVar2 = *(char *)((long)param_1 + 100);
    if (1 < *(uint *)(param_1 + 0x12)) {
      if (cVar2 == '\x01') {
        *(undefined1 *)((long)param_1 + 0x65) = 1;
        return;
      }
      if (cVar2 == '\0') {
        return;
      }
      *(char *)((long)param_1 + 100) = cVar2 + -1;
      return;
    }
    if (cVar2 == '\0') {
      return;
    }
    *(char *)((long)param_1 + 100) = cVar2 + -1;
    if ((char)(cVar2 + -1) != '\0') {
      return;
    }
    if (param_1[0x1c] != 0) {
      memdescFree();
      if (param_1[0x1c] != 0) {
        piVar1 = (int *)(param_1[0x1c] + 0x90);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          memdescDestroy_part_0();
        }
      }
      param_1[0x1c] = 0;
    }
    if (param_1[0x24] != 0) {
      nvAssertFailedNoLog("!pMemDesc->_pInternalMapping","src/kernel/gpu/mem_mgr/mem_desc.c",0x63d);
    }
    iVar7 = (int)param_1[0xd];
    if (iVar7 == 1) {
      lVar8 = param_1[0x21];
      if (lVar8 != 0) {
        if (param_1[0x19] == 0) {
          do {
            lVar4 = *(long *)(lVar8 + 0x18);
            iovaMappingDestroy(lVar8);
            lVar8 = lVar4;
          } while (lVar4 != 0);
          param_1[0x21] = 0;
          iVar7 = (int)param_1[0xd];
        }
        else {
          iovaMappingDestroy(lVar8);
          iVar7 = (int)param_1[0xd];
        }
        goto LAB_003b2753;
      }
    }
    else {
LAB_003b2753:
      if (1 < iVar7 - 1U) {
        return;
      }
    }
    _memSubDeviceFreeAndDestroy_isra_0(*param_1,param_1[0x1b]);
    puVar6 = (undefined8 *)param_1[0x18];
    while (puVar6 != (undefined8 *)0x0) {
      puVar5 = (undefined8 *)puVar6[2];
      (*(code *)*puVar6)(*param_1,puVar6[1],param_1,(code *)*puVar6);
      puVar6 = puVar5;
    }
    if (1 < *(uint *)((long)param_1 + 0x8c)) goto LAB_003b261f;
    iVar7 = nvDbgRmMsgCheck("src/kernel/gpu/mem_mgr/mem_desc.c",0xdfa,"memdescPrintMemdesc",1,0,0);
    if (iVar7 == 2) {
      memdescPrintMemdesc_part_0(param_1,0,"memdesc being freed");
    }
    if (1 < *(uint *)((long)param_1 + 0x8c)) {
      nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                          "src/kernel/gpu/mem_mgr/mem_desc.c",0xf37);
    }
    if ((param_1[1] & 0x40000000U) != 0) goto LAB_003b261f;
    if ((int)param_1[0xd] == 1) {
      if (((char)param_1[0x10] != '\0') && (*(int *)((long)param_1 + 0x6c) == 0)) {
        lVar8 = *(long *)(*param_1 + 0x1b70);
        (**(code **)(lVar8 + 0x188))(*param_1,lVar8,param_1,0,3);
      }
      uVar3 = *(uint *)(param_1 + 0x2c);
      lVar8 = param_1[6];
      param_1[6] = param_1[7];
      param_1[3] = param_1[7] + -1 + (ulong)uVar3 >>
                   (((uVar3 & 0xff00ff00) != 0) << 3 | ((uVar3 & 0xffff0000) != 0) << 4 |
                    (uVar3 & 0xaaaaaaaa) != 0 | ((uVar3 & 0xf0f0f0f0) != 0) << 2 |
                   ((uVar3 & 0xcccccccc) != 0) * '\x02');
      osFreePagesInternal(param_1);
      uVar3 = *(uint *)(param_1 + 0x2c);
      param_1[6] = lVar8;
      param_1[3] = lVar8 + -1 + (ulong)uVar3 >>
                   (((uVar3 & 0xffff0000) != 0) << 4 | ((uVar3 & 0xff00ff00) != 0) << 3 |
                    (uVar3 & 0xaaaaaaaa) != 0 | ((uVar3 & 0xf0f0f0f0) != 0) << 2 |
                   ((uVar3 & 0xcccccccc) != 0) * '\x02');
      goto LAB_003b261f;
    }
    if ((int)param_1[0xd] != 2) goto LAB_003b261f;
    lVar8 = param_1[0x14];
    if (((ulong)param_1[1] >> 0x24 & 1) == 0) {
      if (lVar8 == 0) {
        nvAssertFailedNoLog("pHeap != NULL","src/kernel/gpu/mem_mgr/mem_desc.c",0x5d9);
        goto LAB_003b261f;
      }
      iVar7 = memmgrFree_IMPL(*param_1,*(undefined8 *)(*param_1 + 0x1b78),lVar8,0,0,0);
      if (iVar7 != 0) {
        nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/mem_desc.c",0x5e1,param_1);
        goto LAB_003b261f;
      }
LAB_003b286d:
      if (*(int *)(lVar8 + 0x4c) == 1) {
        heapRemoveRef_IMPL(lVar8);
      }
    }
    else {
      if (*(uint *)((long)param_1 + 0x8c) < 2) {
        if (param_1[0x29] != 0) {
          iVar7 = ctxBufPoolFree(param_1[0x29],param_1);
          if (iVar7 != 0) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0x5d2,"_memdescFreeInternal",4,
                         "NVRM: Failed to free memdesc from context buffer pool\n");
          }
          if (lVar8 == 0) goto LAB_003b261f;
          goto LAB_003b286d;
        }
      }
      else {
        nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                            "src/kernel/gpu/mem_mgr/mem_desc.c",0x11ab);
      }
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0x5cb,"_memdescFreeInternal",4,
                   "NVRM: ctx buf pool not found\n");
    }
    goto LAB_003b261f;
  }
  if (param_1[0x24] != 0) {
    nvAssertFailedNoLog("!pMemDesc->_pInternalMapping","src/kernel/gpu/mem_mgr/mem_desc.c",0x60d);
  }
  iVar7 = (int)param_1[0xd];
  if (iVar7 == 1) {
    lVar8 = param_1[0x21];
    if (lVar8 != 0) {
      if (param_1[0x19] == 0) {
        do {
          lVar4 = *(long *)(lVar8 + 0x18);
          iovaMappingDestroy(lVar8);
          lVar8 = lVar4;
        } while (lVar4 != 0);
        param_1[0x21] = 0;
        iVar7 = (int)param_1[0xd];
      }
      else {
        iovaMappingDestroy(lVar8);
        iVar7 = (int)param_1[0xd];
      }
      goto LAB_003b2601;
    }
  }
  else {
LAB_003b2601:
    if (1 < iVar7 - 1U) {
      return;
    }
  }
  _memSubDeviceFreeAndDestroy_isra_0(*param_1,param_1[0x1b]);
LAB_003b261f:
  lVar8 = param_1[0x19];
  param_1[0x1b] = 0;
  *(undefined4 *)((long)param_1 + 0x8c) = 1;
  if (((lVar8 != 0) && (1 < *(uint *)(lVar8 + 0x8c))) && (*(int *)(lVar8 + 0x90) == 1)) {
    *(undefined8 *)(lVar8 + 0xd8) = 0;
    *(undefined4 *)(param_1[0x19] + 0x8c) = 1;
  }
  return;
}


// ===== 003b2bd0 memdescDestroy.part.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void memdescDestroy_part_0(undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined8 *puVar5;
  long lVar6;
  
  puVar3 = (undefined8 *)param_1[0x18];
  if ((*(byte *)((long)param_1 + 9) & 0x80) != 0) {
    param_1[0x1b] = 0;
    *(undefined4 *)((long)param_1 + 0x8c) = 1;
  }
  if (*(int *)(param_1 + 0x1a) == 0) {
    iVar2 = *(int *)(param_1 + 0xd);
  }
  else {
    nvAssertFailedNoLog("pMemDesc->childDescriptorCnt == 0","src/kernel/gpu/mem_mgr/mem_desc.c",
                        0x25e);
    iVar2 = *(int *)(param_1 + 0xd);
  }
  if ((iVar2 != 2) && (param_1[0x14] != 0)) {
    nvAssertFailedNoLog("pMemDesc->_addressSpace == ADDR_FBMEM || pMemDesc->pHeap == NULL",
                        "src/kernel/gpu/mem_mgr/mem_desc.c",0x25f);
  }
  if ((param_1[8] != 0) && ((code *)param_1[9] != (code *)0x0)) {
    (*(code *)param_1[9])(param_1);
  }
  if (*(char *)((long)param_1 + 0x65) == '\0') {
    if (*(char *)((long)param_1 + 100) != '\0') {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0x274,"memdescDestroy",4,
                   "NVRM: Destroying unfreed memory %p\n",param_1);
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0x275,"memdescDestroy",4,
                   "NVRM: Please call memdescFree()\n");
      memdescFree(param_1);
      if (*(char *)((long)param_1 + 100) != '\0') {
        nvAssertFailedNoLog("!pMemDesc->Allocated","src/kernel/gpu/mem_mgr/mem_desc.c",0x277);
      }
    }
    if (1 < *(uint *)((long)param_1 + 0x8c)) goto LAB_003b2e55;
LAB_003b2c53:
    lVar6 = param_1[0x1c];
    if (lVar6 != 0) goto LAB_003b2c5f;
  }
  else {
    memdescFree(param_1);
    if (*(uint *)((long)param_1 + 0x8c) < 2) goto LAB_003b2c53;
LAB_003b2e55:
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c"
                        ,0xeda);
    lVar6 = param_1[0x1c];
    if (lVar6 != 0) {
      if (1 < *(uint *)((long)param_1 + 0x8c)) {
        nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                            "src/kernel/gpu/mem_mgr/mem_desc.c",0xeda);
        lVar6 = param_1[0x1c];
      }
LAB_003b2c5f:
      memdescFree(lVar6);
      if (*(uint *)((long)param_1 + 0x8c) < 2) {
        lVar6 = param_1[0x1c];
        if (lVar6 != 0) {
LAB_003b2c7d:
          piVar1 = (int *)(lVar6 + 0x90);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            memdescDestroy_part_0();
          }
          goto LAB_003b2c8b;
        }
      }
      else {
        nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                            "src/kernel/gpu/mem_mgr/mem_desc.c",0xeda);
        lVar6 = param_1[0x1c];
        if (lVar6 != 0) goto LAB_003b2c7d;
LAB_003b2c8b:
        if (1 < *(uint *)((long)param_1 + 0x8c)) {
          nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                              "src/kernel/gpu/mem_mgr/mem_desc.c",0xeec);
        }
      }
      param_1[0x1c] = 0;
    }
  }
  lVar6 = param_1[0x21];
  if (lVar6 != 0) {
    if (param_1[0x19] == 0) {
      do {
        lVar4 = *(long *)(lVar6 + 0x18);
        iovaMappingDestroy(lVar6);
        lVar6 = lVar4;
      } while (lVar4 != 0);
      param_1[0x21] = 0;
    }
    else {
      iovaMappingDestroy(lVar6);
    }
  }
  while (puVar3 != (undefined8 *)0x0) {
    puVar5 = (undefined8 *)puVar3[2];
    (*(code *)*puVar3)(*param_1,puVar3[1],param_1);
    puVar3 = puVar5;
  }
  portMemFree(param_1[0x28]);
  param_1[0x28] = 0;
  portMemFree(param_1[0x1d]);
  param_1[0x1d] = 0;
  if (param_1[0x2d] != 0) {
    portMemFree();
    param_1[0x2d] = 0;
  }
  lVar6 = param_1[0x19];
  if (lVar6 == 0) goto LAB_003b2d92;
  if ((*(byte *)(param_1 + 1) & 8) == 0) {
    *(int *)(lVar6 + 0xd0) = *(int *)(lVar6 + 0xd0) + -1;
    lVar6 = param_1[0x19];
    if (lVar6 != 0) goto LAB_003b2d7e;
  }
  else {
LAB_003b2d7e:
    piVar1 = (int *)(lVar6 + 0x90);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      memdescDestroy_part_0();
    }
  }
  param_1[0x19] = 0;
LAB_003b2d92:
  if (1 < *(uint *)((long)param_1 + 0x8c)) {
    nvAssertFailedNoLog("memdescHasSubDeviceMemDescs(pMemDesc) == NV_FALSE",
                        "src/kernel/gpu/mem_mgr/mem_desc.c",0x2ab);
  }
  if ((*(byte *)(param_1 + 1) & 8) == 0) {
    portMemFree(param_1);
    return;
  }
  return;
}


// ===== 003b2fa0 memdescDestroy =====

void memdescDestroy(long param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = (int *)(param_1 + 0x90);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      memdescDestroy_part_0();
      return;
    }
  }
  return;
}


// ===== 003b2fd0 _memSubDeviceFreeAndDestroy.isra.0 =====

void _memSubDeviceFreeAndDestroy_isra_0(long param_1,long param_2)

{
  int *piVar1;
  long lVar2;
  
  if (param_2 == 0) {
    return;
  }
  while (lVar2 = param_2, param_1 != 0) {
    param_1 = *(long *)(lVar2 + 0xd8);
    *(undefined8 *)(lVar2 + 0xd8) = 0;
    memdescFree(lVar2);
    piVar1 = (int *)(lVar2 + 0x90);
    *piVar1 = *piVar1 + -1;
    param_2 = param_1;
    if (*piVar1 == 0) {
      memdescDestroy_part_0(lVar2);
    }
  }
  return;
}


// ===== 003b3040 memdescMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong memdescMap(long *param_1,long param_2,long param_3,char param_4,undefined4 param_5,
                long *param_6,undefined8 *param_7)

{
  char cVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  long *plVar5;
  ulong uVar6;
  long lVar7;
  undefined8 extraout_RDX;
  undefined8 uVar8;
  undefined8 uVar9;
  long local_40 [2];
  
  if ((ulong)param_1[6] < (ulong)(param_2 + param_3)) {
    nvAssertFailedNoLog("((Offset + Size) <= memdescGetSize(pMemDesc))",
                        "src/kernel/gpu/mem_mgr/mem_desc.c",0x6d5);
    return 0x1f;
  }
  if (1 < *(uint *)((long)param_1 + 0x8c)) {
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c"
                        ,0x6d7);
    return 0x32;
  }
  if ((int)param_1[0xd] == 1) {
    uVar6 = osMapSystemMemory();
    return uVar6;
  }
  if ((int)param_1[0xd] != 2) {
    return 0xffff;
  }
  lVar2 = *param_1;
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pGpu != NULL","src/kernel/gpu/mem_mgr/mem_desc.c",0x6ef);
    return 0x1f;
  }
  lVar3 = *(long *)(&DAT_00001b90 + lVar2);
  cVar1 = *(char *)(lVar2 + 0x454);
  plVar5 = (long *)portMemAllocNonPaged(0x18);
  if (plVar5 == (long *)0x0) {
    return 0x51;
  }
  if (cVar1 != '\0') {
    if (param_4 == '\0') {
      lVar2 = *(long *)(lVar2 + 0x1b70);
      memdescGetPhysAddrsForGpu(param_1,*param_1,0,param_2,0,1,local_40);
      *param_6 = *(long *)(lVar2 + 0x478) + local_40[0];
    }
    else {
      uVar4 = (**(code **)(lVar3 + 0x518))
                        (lVar2,lVar3,param_1,param_2,param_3,param_5,param_6,plVar5 + 2);
      if (uVar4 != 0) goto LAB_003b32fc;
    }
    memdescGetPhysAddrsForGpu(param_1,*param_1,1,param_2,0,1,local_40);
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0x719,"memdescMap",1,
                 "NVRM: Allocating coherent link mapping. VA: %p PA: 0x%llx size: 0x%llx\n",*param_6
                 ,local_40[0],param_3);
    *param_7 = plVar5;
    return 0;
  }
  plVar5[1] = param_3;
  uVar9 = 0;
  uVar8 = 0x20;
  uVar4 = kbusMapFbApertureSingle_IMPL(lVar2,lVar3,param_1,param_2,plVar5,plVar5 + 1);
  if (uVar4 == 0) {
    lVar7 = gpumgrGetGpuPhysFbAddr(lVar2,uVar9,extraout_RDX,uVar8);
    if (param_4 == '\0') {
      uVar4 = osMapPciMemoryUser(*(undefined8 *)(lVar2 + 0x4e0),lVar7 + *plVar5,param_3,param_5,
                                 param_6,plVar5 + 2,2);
    }
    else {
      uVar4 = osMapPciMemoryKernel64(lVar2,lVar7 + *plVar5,param_3,param_5,param_6,2);
    }
    if (uVar4 == 0) {
      *param_7 = plVar5;
      return 0;
    }
    kbusUnmapFbApertureSingle_IMPL(lVar2,lVar3,param_1,*plVar5,plVar5[1],0x20);
  }
LAB_003b32fc:
  portMemFree(plVar5);
  return (ulong)uVar4;
}


// ===== 003b3420 memdescMapOld =====

void memdescMapOld(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 *in_R9;
  undefined8 *in_stack_00000008;
  
  uVar1 = *in_R9;
  uVar2 = *in_stack_00000008;
  memdescMap();
  *in_R9 = uVar1;
  *in_stack_00000008 = uVar2;
  return;
}


// ===== 003b3470 memdescGetPtePhysAddrsForGpu =====

void memdescGetPtePhysAddrsForGpu
               (long param_1,undefined8 param_2,undefined8 param_3,long param_4,long param_5,
               long param_6,long param_7)

{
  ulong *puVar1;
  uint uVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  
  plVar4 = (long *)memdescGetPteArrayForGpu();
  iVar3 = memdescGetPteArraySize(param_1,param_3);
  uVar2 = *(uint *)(param_1 + 0x160);
  if (1 < *(uint *)(param_1 + 0x8c)) {
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c"
                        ,0xb44);
  }
  if (param_6 != 0) {
    uVar6 = (ulong)*(uint *)(param_1 + 0x60) + param_4;
    lVar5 = 0;
    do {
      if (iVar3 == 1) {
        lVar7 = *plVar4 + uVar6;
      }
      else {
        uVar8 = uVar6 >> (((uVar2 & 0xff00ff00) != 0) << 3 | ((uVar2 & 0xffff0000) != 0) << 4 |
                          (uVar2 & 0xaaaaaaaa) != 0 | ((uVar2 & 0xf0f0f0f0) != 0) << 2 |
                         ((uVar2 & 0xcccccccc) != 0) * '\x02');
        if (*(ulong *)(param_1 + 0x18) <= uVar8) {
          nvCheckFailedNoLog(4,"pageIndex < pMemDesc->PageCount","src/kernel/gpu/mem_mgr/mem_desc.c"
                             ,0xb50);
          return;
        }
        lVar7 = (uVar6 & uVar2 - 1) + plVar4[uVar8];
      }
      *(long *)(param_7 + lVar5 * 8) = lVar7;
      if ((*(ulong *)(param_1 + 8) & 0x4000000000000) != 0) {
        puVar1 = (ulong *)(param_7 + lVar5 * 8);
        *puVar1 = *puVar1 | *(ulong *)(param_1 + 0x158);
      }
      lVar5 = lVar5 + 1;
      uVar6 = uVar6 + param_5;
    } while (param_6 != lVar5);
  }
  return;
}


// ===== 003b35f0 memdescGetPtePhysAddrs =====

undefined1  [16]
memdescGetPtePhysAddrs
          (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6)

{
  undefined1 auVar1 [16];
  undefined8 uStack_10;
  
  memdescGetPtePhysAddrsForGpu(param_1,*param_1,param_2,param_3,param_4,param_5);
  auVar1._8_8_ = uStack_10;
  auVar1._0_8_ = param_6;
  return auVar1;
}


// ===== 003b3620 memdescGetPtePhysAddr =====

undefined8 memdescGetPtePhysAddr(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_10;
  
  memdescGetPtePhysAddrsForGpu(param_1,*param_1,param_2,param_3,0,1,&local_10);
  return local_10;
}


// ===== 003b3650 memdescGetPte =====

long memdescGetPte(undefined8 *param_1,undefined8 param_2,uint param_3)

{
  long *plVar1;
  long lVar2;
  
  plVar1 = (long *)memdescGetPteArrayForGpu(param_1,*param_1,param_2);
  if (1 < *(uint *)((long)param_1 + 0x8c)) {
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c"
                        ,0xbd4);
  }
  if ((*(byte *)((long)param_1 + 9) & 4) == 0) {
    if ((ulong)param_3 < (ulong)param_1[4]) {
      return plVar1[param_3];
    }
    nvAssertFailedNoLog("PteIndex < pMemDesc->pageArraySize","src/kernel/gpu/mem_mgr/mem_desc.c",
                        0xbe1);
    lVar2 = -1;
  }
  else {
    lVar2 = (ulong)(param_3 << 0xc) + *plVar1;
  }
  return lVar2;
}


// ===== 003b3710 memdescSetPte =====

void memdescSetPte(undefined8 *param_1,undefined8 param_2,uint param_3,undefined8 param_4)

{
  long lVar1;
  undefined8 uVar2;
  char *pcVar3;
  
  lVar1 = memdescGetPteArrayForGpu(param_1,*param_1,param_2);
  if (1 < *(uint *)((long)param_1 + 0x8c)) {
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c"
                        ,0xc00);
  }
  if ((*(byte *)((long)param_1 + 9) & 4) == 0) {
    if ((ulong)param_1[4] <= (ulong)param_3) {
      uVar2 = 0xc08;
      pcVar3 = "PteIndex < pMemDesc->pageArraySize";
      goto LAB_003b37a9;
    }
  }
  else {
    uVar2 = 0xc04;
    pcVar3 = "PteIndex == 0";
    if (param_3 != 0) {
LAB_003b37a9:
      nvAssertFailedNoLog(pcVar3,"src/kernel/gpu/mem_mgr/mem_desc.c",uVar2);
      return;
    }
  }
  *(undefined8 *)(lVar1 + (ulong)param_3 * 8) = param_4;
  portMemFree(param_1[0x28]);
  param_1[0x28] = 0;
  return;
}


// ===== 003b37f0 memdescGetApertureString =====

char * memdescGetApertureString(int param_1)

{
  char *pcVar1;
  
  pcVar1 = "VIDEO MEMORY";
  if ((param_1 != 2) && (pcVar1 = "SYSTEM MEMORY", param_1 != 1)) {
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}


// ===== 003b3820 memdescDescIsEqual =====

bool memdescDescIsEqual(undefined8 *param_1,undefined8 *param_2)

{
  long lVar1;
  long local_20 [2];
  
  if (((param_1 == (undefined8 *)0x0) || (param_2 == (undefined8 *)0x0)) ||
     (*(int *)(param_1 + 0xd) != *(int *)(param_2 + 0xd))) {
    return false;
  }
  memdescGetPhysAddrsForGpu(param_1,*param_1,0,0,0,1,local_20);
  lVar1 = local_20[0];
  memdescGetPhysAddrsForGpu(param_2,*param_2,0,0,0,1,local_20);
  if (local_20[0] == lVar1) {
    memdescGetPhysAddrsForGpu(param_1,*param_1,1,0,0,1,local_20);
    lVar1 = local_20[0];
    memdescGetPhysAddrsForGpu(param_2,*param_2,1,0,0,1,local_20);
    if (((local_20[0] == lVar1) &&
        (*(int *)((long)param_1 + 0x74) == *(int *)((long)param_2 + 0x74))) &&
       ((param_1[6] == param_2[6] && (param_1[5] == param_2[5])))) {
      return param_1[2] == param_2[2];
    }
  }
  return false;
}


// ===== 003b3940 memdescAddDestroyCallback =====

void memdescAddDestroyCallback(long param_1,long param_2)

{
  if (1 < *(uint *)(param_1 + 0x8c)) {
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c"
                        ,0xcd8);
  }
  *(undefined8 *)(param_2 + 0x10) = *(undefined8 *)(param_1 + 0xc0);
  if (*(uint *)(param_1 + 0x8c) < 2) {
    *(long *)(param_1 + 0xc0) = param_2;
    return;
  }
  nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c",
                      0xefe);
  *(long *)(param_1 + 0xc0) = param_2;
  return;
}


// ===== 003b3a00 memdescRemoveDestroyCallback =====

void memdescRemoveDestroyCallback(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_1 + 0xc0);
  if (1 < *(uint *)(param_1 + 0x8c)) {
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c"
                        ,0xcef);
  }
  lVar3 = 0;
  do {
    lVar2 = lVar3;
    lVar3 = lVar1;
    if (lVar3 == 0) {
      return;
    }
    lVar1 = *(long *)(lVar3 + 0x10);
  } while (param_2 != lVar3);
  if (lVar2 != 0) {
    *(long *)(lVar2 + 0x10) = lVar1;
    return;
  }
  if (1 < *(uint *)(param_1 + 0x8c)) {
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c"
                        ,0xefe);
  }
  *(long *)(param_1 + 0xc0) = lVar1;
  return;
}


// ===== 003b3ae0 memdescGetMemDescFromIndex =====

long memdescGetMemDescFromIndex(long param_1,int param_2)

{
  long lVar1;
  
  if (*(uint *)(param_1 + 0x8c) < 2) {
    return param_1;
  }
  lVar1 = *(long *)(param_1 + 0xd8);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pSubDevMemDesc","src/kernel/gpu/mem_mgr/mem_desc.c",0xd56);
  }
  do {
    if (param_2 == 0) {
      return lVar1;
    }
    lVar1 = *(long *)(lVar1 + 0xd8);
    param_2 = param_2 + -1;
  } while (lVar1 != 0);
  nvAssertFailedNoLog(&DAT_00d4c747,"src/kernel/gpu/mem_mgr/mem_desc.c",0xd5e);
  return 0;
}


// ===== 003b3b90 memdescGetMemDescFromGpu =====

long memdescGetMemDescFromGpu(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  long lVar2;
  
  uVar1 = gpumgrGetSubDeviceInstanceFromGpu(param_2);
  if (*(uint *)(param_1 + 0x8c) < 2) {
    return param_1;
  }
  lVar2 = memdescGetMemDescFromIndex(param_1,uVar1);
  return lVar2;
}


// ===== 003b3bd0 memdescMapInternal =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

long memdescMapInternal(long param_1,long param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined8 uVar6;
  long local_38;
  undefined8 local_30 [2];
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("pMemDesc != NULL","src/kernel/gpu/mem_mgr/mem_desc.c",0x820);
    return 0;
  }
  if ((*(int *)(param_2 + 0x68) == 2) &&
     (uVar2 = gpumgrGetSubDeviceInstanceFromGpu(), 1 < *(uint *)(param_2 + 0x8c))) {
    param_2 = memdescGetMemDescFromIndex(param_2,uVar2);
  }
  iVar1 = memdescGetMapInternalType(param_1,param_2);
  if (iVar1 == 3) {
    if (*(int *)(param_2 + 0x6c) == 0) {
      (**(code **)(*(long *)(param_1 + 0x1b70) + 0x188))
                (param_1,*(long *)(param_1 + 0x1b70),param_2,0,3);
      lVar3 = *(long *)(param_2 + 0x120);
    }
    else {
      lVar3 = *(long *)(param_2 + 0x120);
    }
    if (lVar3 == 0) {
      local_30[0] = *(undefined8 *)(param_2 + 0x128);
      local_38 = 0;
      iVar1 = memdescMap(param_2,0,*(undefined8 *)(param_2 + 0x30),1,3,&local_38,local_30);
      *(long *)(param_2 + 0x120) = local_38;
      *(undefined8 *)(param_2 + 0x128) = local_30[0];
      if (iVar1 != 0) {
        nvCheckFailedNoLog(4,"status == NV_OK","src/kernel/gpu/mem_mgr/mem_desc.c",0x845);
        return 0;
      }
      goto LAB_003b3cef;
    }
    iVar1 = *(int *)(param_2 + 0x130);
    if (iVar1 != 0) goto LAB_003b3c6f;
    nvAssertFailedNoLog("pMemDesc->_internalMappingRefCount","src/kernel/gpu/mem_mgr/mem_desc.c",
                        0x830);
    lVar3 = *(long *)(param_2 + 0x120);
  }
  else {
    lVar3 = *(long *)(param_2 + 0x120);
    if (lVar3 == 0) {
      if (iVar1 == 2) {
        local_38 = (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x1c0))
                             (param_1,*(long *)(&DAT_00001b90 + param_1),param_2,param_3);
        *(long *)(param_2 + 0x120) = local_38;
        if (local_38 != 0) goto LAB_003b3cef;
        uVar4 = 0x858;
        pcVar5 = "pMemDesc->_pInternalMapping != NULL";
        uVar6 = 1;
      }
      else {
        if (*(char *)(param_1 + 0x45b) == '\0') {
          nvAssertFailedNoLog("pGpu->getProperty(pGpu, PDB_PROP_GPU_ATS_SUPPORTED)",
                              "src/kernel/gpu/mem_mgr/mem_desc.c",0x84a);
        }
        iVar1 = (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x518))
                          (param_1,*(long *)(&DAT_00001b90 + param_1),param_2,0,
                           *(undefined8 *)(param_2 + 0x30),3,param_2 + 0x120,param_2 + 0x128);
        if (iVar1 == 0) {
          local_38 = *(long *)(param_2 + 0x120);
LAB_003b3cef:
          *(undefined4 *)(param_2 + 0x130) = 1;
          return local_38;
        }
        uVar4 = 0x853;
        uVar6 = 4;
        pcVar5 = "status == NV_OK";
      }
LAB_003b3d60:
      nvCheckFailedNoLog(uVar6,pcVar5,"src/kernel/gpu/mem_mgr/mem_desc.c",uVar4);
      return 0;
    }
    if (*(int *)(param_2 + 0x130) == 0) {
      nvAssertFailedNoLog("pMemDesc->_internalMappingRefCount","src/kernel/gpu/mem_mgr/mem_desc.c",
                          0x830);
      lVar3 = *(long *)(param_2 + 0x120);
    }
    if (iVar1 == 2) {
      lVar3 = (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x1c8))
                        (param_1,*(long *)(&DAT_00001b90 + param_1),param_2,lVar3);
      *(long *)(param_2 + 0x120) = lVar3;
      if (lVar3 == 0) {
        uVar4 = 0x837;
        pcVar5 = "pMemDesc->_pInternalMapping != NULL";
        uVar6 = 4;
        goto LAB_003b3d60;
      }
    }
  }
  iVar1 = *(int *)(param_2 + 0x130);
LAB_003b3c6f:
  *(int *)(param_2 + 0x130) = iVar1 + 1;
  return lVar3;
}


// ===== 003b3f80 memdescUnmapInternal =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void memdescUnmapInternal(long param_1,long param_2,uint param_3)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 local_30;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("pMemDesc != NULL","src/kernel/gpu/mem_mgr/mem_desc.c",0x86c);
    return;
  }
  if ((*(long *)(param_2 + 0x120) == 0) || (*(int *)(param_2 + 0x130) == 0)) {
    nvAssertFailedNoLog("pMemDesc->_pInternalMapping != NULL && pMemDesc->_internalMappingRefCount != 0"
                        ,"src/kernel/gpu/mem_mgr/mem_desc.c",0x86d);
    return;
  }
  if ((*(int *)(param_2 + 0x68) == 2) &&
     (uVar4 = gpumgrGetSubDeviceInstanceFromGpu(), 1 < *(uint *)(param_2 + 0x8c))) {
    param_2 = memdescGetMemDescFromIndex(param_2,uVar4);
  }
  iVar3 = memdescGetMapInternalType(param_1,param_2);
  if (iVar3 - 2U < 2) {
    osFlushCpuWriteCombineBuffer();
    if (((*(long *)(param_1 + 7000) != 0) && (sVar2 = kbifGetDmaCaps_IMPL(param_1), sVar2 == 0)) &&
       (*(int *)(param_2 + 0x74) == 0)) {
      osFlushCpuCache();
    }
    piVar1 = (int *)(param_2 + 0x130);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 != 0) goto LAB_003b404f;
    if (iVar3 == 3) {
      memdescUnmap(param_2,1,*(undefined8 *)(param_2 + 0x120),*(undefined8 *)(param_2 + 0x128));
    }
    else {
      local_30 = *(undefined8 *)(param_2 + 0x120);
      (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x1d0))
                (param_1,*(long *)(&DAT_00001b90 + param_1),param_2,&local_30,param_3);
    }
  }
  else {
    piVar1 = (int *)(param_2 + 0x130);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 != 0) {
      return;
    }
    if ((param_3 & 0x1000) != 0) {
      osFlushGpuCoherentCpuCacheRange
                (*(undefined8 *)(param_1 + 0x4e0),*(undefined8 *)(param_2 + 0x120),
                 *(undefined8 *)(param_2 + 0x38));
    }
    (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x520))
              (param_1,*(long *)(&DAT_00001b90 + param_1),param_2,*(undefined8 *)(param_2 + 0x120),
               *(undefined8 *)(param_2 + 0x128));
  }
  *(undefined8 *)(param_2 + 0x120) = 0;
  *(undefined8 *)(param_2 + 0x128) = 0;
  *(undefined4 *)(param_2 + 0x130) = 0;
LAB_003b404f:
  if (((*(long *)(&DAT_00001b90 + param_1) != 0) && ((param_3 & 1) == 0)) && (iVar3 - 2U < 2)) {
    uVar4 = kbusGetFlushAperture_IMPL
                      (*(long *)(&DAT_00001b90 + param_1),*(undefined4 *)(param_2 + 0x68));
    (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x500))
              (param_1,*(long *)(&DAT_00001b90 + param_1),uVar4);
    return;
  }
  return;
}


// ===== 003b41e0 memdescSetGpuCacheAttrib =====

void memdescSetGpuCacheAttrib(long param_1,undefined4 param_2)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 100) == '\0') {
    uVar1 = *(uint *)(param_1 + 0x8c);
  }
  else {
    nvAssertFailedNoLog("pMemDesc->Allocated == NV_FALSE","src/kernel/gpu/mem_mgr/mem_desc.c",0xd99)
    ;
    uVar1 = *(uint *)(param_1 + 0x8c);
  }
  if (uVar1 < 2) {
    *(undefined4 *)(param_1 + 0x6c) = param_2;
    return;
  }
  nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c",
                      0xd9b);
  *(undefined4 *)(param_1 + 0x6c) = param_2;
  return;
}


// ===== 003b4270 memdescGetGpuP2PCacheAttrib =====

undefined4 memdescGetGpuP2PCacheAttrib(long param_1)

{
  if (*(uint *)(param_1 + 0x8c) < 2) {
    return *(undefined4 *)(param_1 + 0x70);
  }
  nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c",
                      0xdab);
  return *(undefined4 *)(param_1 + 0x70);
}


// ===== 003b42c0 memdescSetGpuP2PCacheAttrib =====

void memdescSetGpuP2PCacheAttrib(long param_1,undefined4 param_2)

{
  if (*(uint *)(param_1 + 0x8c) < 2) {
    *(undefined4 *)(param_1 + 0x70) = param_2;
    return;
  }
  nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c",
                      0xdbf);
  *(undefined4 *)(param_1 + 0x70) = param_2;
  return;
}


// ===== 003b4310 memdescSetCpuCacheAttrib =====

void memdescSetCpuCacheAttrib(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x74) = param_2;
  return;
}


// ===== 003b4320 memdescPrintMemdesc =====

void memdescPrintMemdesc(long param_1,undefined1 param_2,long param_3)

{
  int iVar1;
  
  iVar1 = nvDbgRmMsgCheck("src/kernel/gpu/mem_mgr/mem_desc.c",0xdfa,"memdescPrintMemdesc",1,0,0);
  if (((iVar1 == 2) && (param_3 != 0)) && (param_1 != 0)) {
    memdescPrintMemdesc_part_0(param_1,param_2,param_3);
    return;
  }
  return;
}


// ===== 003b43a0 memdescGetPteKindForGpu =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void memdescGetPteKindForGpu(long param_1,long param_2)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(long *)(param_2 + 0x1b78) + 0x2d8);
  (*pcVar1)(param_2,*(long *)(param_2 + 0x1b78),*(undefined4 *)(param_1 + 0x84),pcVar1);
  return;
}


// ===== 003b43d0 memdescSetPteKindForGpu =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void memdescSetPteKindForGpu(long param_1,long param_2,undefined4 param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (1 < *(uint *)(param_1 + 0x8c)) {
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c"
                        ,0xe61);
  }
  pcVar1 = *(code **)(*(long *)(param_2 + 0x1b78) + 0x2e0);
  uVar2 = (*pcVar1)(param_2,*(long *)(param_2 + 0x1b78),param_3,pcVar1);
  *(undefined4 *)(param_1 + 0x84) = uVar2;
  if (*(uint *)(param_1 + 0x8c) < 2) {
    *(ulong *)(param_1 + 8) = *(ulong *)(param_1 + 8) | 2;
    return;
  }
  nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c",
                      0xf52);
  *(ulong *)(param_1 + 8) = *(ulong *)(param_1 + 8) | 2;
  return;
}


// ===== 003b4480 memdescGetKernelMapping =====

undefined8 memdescGetKernelMapping(long param_1)

{
  if (*(uint *)(param_1 + 0x8c) < 2) {
    return *(undefined8 *)(param_1 + 0x110);
  }
  nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c",
                      0xe95);
  return *(undefined8 *)(param_1 + 0x110);
}


// ===== 003b44d0 memdescSetKernelMapping =====

void memdescSetKernelMapping(long param_1,undefined8 param_2)

{
  if (*(uint *)(param_1 + 0x8c) < 2) {
    *(undefined8 *)(param_1 + 0x110) = param_2;
    return;
  }
  nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c",
                      0xea7);
  *(undefined8 *)(param_1 + 0x110) = param_2;
  return;
}


// ===== 003b4530 memdescGetKernelMappingPriv =====

undefined8 memdescGetKernelMappingPriv(long param_1)

{
  if (*(uint *)(param_1 + 0x8c) < 2) {
    return *(undefined8 *)(param_1 + 0x118);
  }
  nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c",
                      0xeb7);
  return *(undefined8 *)(param_1 + 0x118);
}


// ===== 003b4580 memdescSetKernelMappingPriv =====

void memdescSetKernelMappingPriv(long param_1,undefined8 param_2)

{
  if (*(uint *)(param_1 + 0x8c) < 2) {
    *(undefined8 *)(param_1 + 0x118) = param_2;
    return;
  }
  nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c",
                      0xec9);
  *(undefined8 *)(param_1 + 0x118) = param_2;
  return;
}


// ===== 003b45e0 memdescGetStandbyBuffer =====

undefined8 memdescGetStandbyBuffer(long param_1)

{
  if (*(uint *)(param_1 + 0x8c) < 2) {
    return *(undefined8 *)(param_1 + 0xe0);
  }
  nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c",
                      0xeda);
  return *(undefined8 *)(param_1 + 0xe0);
}


// ===== 003b4630 memdescSetStandbyBuffer =====

void memdescSetStandbyBuffer(long param_1,undefined8 param_2)

{
  if (*(uint *)(param_1 + 0x8c) < 2) {
    *(undefined8 *)(param_1 + 0xe0) = param_2;
    return;
  }
  nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c",
                      0xeec);
  *(undefined8 *)(param_1 + 0xe0) = param_2;
  return;
}


// ===== 003b4690 memdescGetGuestId =====

undefined8 memdescGetGuestId(long param_1)

{
  if (*(uint *)(param_1 + 0x8c) < 2) {
    return *(undefined8 *)(param_1 + 0x50);
  }
  nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c",
                      0xf0e);
  return *(undefined8 *)(param_1 + 0x50);
}


// ===== 003b46e0 memdescSetGuestId =====

void memdescSetGuestId(long param_1,undefined8 param_2)

{
  if (*(uint *)(param_1 + 0x8c) < 2) {
    *(undefined8 *)(param_1 + 0x50) = param_2;
    return;
  }
  nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c",
                      0xf20);
  *(undefined8 *)(param_1 + 0x50) = param_2;
  return;
}


// ===== 003b4730 memdescGetFlag =====

bool memdescGetFlag(long param_1,ulong param_2)

{
  if (param_2 == 0x400) {
    nvAssertFailedNoLog("flag != MEMDESC_FLAGS_PHYSICALLY_CONTIGUOUS",
                        "src/kernel/gpu/mem_mgr/mem_desc.c",0xf33);
  }
  else if (param_2 == 0x40) goto LAB_003b475a;
  if (1 < *(uint *)(param_1 + 0x8c)) {
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c"
                        ,0xf37);
  }
LAB_003b475a:
  return (*(ulong *)(param_1 + 8) & param_2) != 0;
}


// ===== 003b47d0 memdescSetFlag =====

void memdescSetFlag(long *param_1,ulong param_2,char param_3)

{
  int iVar1;
  ulong uVar2;
  
  if (param_2 == 0x400) {
    nvAssertFailedNoLog("flag != MEMDESC_FLAGS_PHYSICALLY_CONTIGUOUS",
                        "src/kernel/gpu/mem_mgr/mem_desc.c",0xf4d);
    if (1 < *(uint *)((long)param_1 + 0x8c)) {
      nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                          "src/kernel/gpu/mem_mgr/mem_desc.c",0xf52);
    }
LAB_003b4817:
    uVar2 = param_1[1] | param_2;
    if (param_3 == '\0') {
      uVar2 = ~param_2 & param_1[1];
    }
    param_1[1] = uVar2;
    return;
  }
  if (param_2 == 0x40) goto LAB_003b4817;
  if (1 < *(uint *)((long)param_1 + 0x8c)) {
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c"
                        ,0xf52);
  }
  if (param_2 == 0x2000000) {
    iVar1 = _memdescSetSubAllocatorFlag(*param_1,param_1,param_3);
    if (iVar1 == 0) {
      return;
    }
    nvAssertOkFailedNoLog
              (iVar1,"_memdescSetSubAllocatorFlag(pMemDesc->pGpu, pMemDesc, bValue)",
               "src/kernel/gpu/mem_mgr/mem_desc.c",0xf57);
    return;
  }
  if (param_2 != 0x100) goto LAB_003b4817;
  if (*param_1 == 0) {
    nvAssertFailedNoLog("pGpu != NULL","src/kernel/gpu/mem_mgr/mem_desc.c",0xb0);
  }
  else {
    if (param_3 != '\0') {
      iVar1 = vgpuGetCallingContextGfid(*param_1,param_1 + 0x15);
      if (iVar1 == 0) {
        param_1[1] = param_1[1] | 0x100;
        return;
      }
      nvAssertOkFailedNoLog
                (iVar1,"vgpuGetCallingContextGfid(pGpu, &pMemDesc->gfid)",
                 "src/kernel/gpu/mem_mgr/mem_desc.c",0xba);
      goto LAB_003b499b;
    }
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0xb4,"_memdescSetGuestAllocatedFlag",4,
                 "NVRM: Unsetting MEMDESC_FLAGS_GUEST_ALLOCATED not supported\n");
    nvAssertFailedNoLog(&DAT_00d4c747,"src/kernel/gpu/mem_mgr/mem_desc.c",0xb6);
  }
  iVar1 = 0x1f;
LAB_003b499b:
  nvAssertOkFailedNoLog
            (iVar1,"_memdescSetGuestAllocatedFlag(pMemDesc->pGpu, pMemDesc, bValue)",
             "src/kernel/gpu/mem_mgr/mem_desc.c",0xf5c);
  return;
}


// ===== 003b4a00 memdescGetMemData =====

undefined8 memdescGetMemData(long param_1)

{
  if (*(uint *)(param_1 + 0x8c) < 2) {
    return *(undefined8 *)(param_1 + 0x40);
  }
  nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c",
                      0xf74);
  return *(undefined8 *)(param_1 + 0x40);
}


// ===== 003b4a50 memdescSetMemData =====

void memdescSetMemData(long param_1,undefined8 param_2,undefined8 param_3)

{
  if (*(uint *)(param_1 + 0x8c) < 2) {
    *(undefined8 *)(param_1 + 0x40) = param_2;
    *(undefined8 *)(param_1 + 0x48) = param_3;
    return;
  }
  nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c",
                      0xf8b);
  *(undefined8 *)(param_1 + 0x48) = param_3;
  *(undefined8 *)(param_1 + 0x40) = param_2;
  return;
}


// ===== 003b4ac0 memdescGetVolatility =====

bool memdescGetVolatility(long param_1)

{
  if (1 < *(uint *)(param_1 + 0x8c)) {
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c"
                        ,0xf9e);
  }
  if (*(int *)(param_1 + 0x68) == 1) {
    return *(int *)(param_1 + 0x6c) == 1;
  }
  if (*(int *)(param_1 + 0x68) != 2) {
    nvAssertFailedNoLog("pMemDesc->_addressSpace == ADDR_FBMEM","src/kernel/gpu/mem_mgr/mem_desc.c",
                        0xfa5);
  }
  return false;
}


// ===== 003b4b50 memdescGetContiguity =====

byte memdescGetContiguity(long param_1)

{
  return *(byte *)(param_1 + 9) >> 2 & 1;
}


// ===== 003b4b60 memdescCheckContiguity =====

undefined8 memdescCheckContiguity(long param_1,undefined8 param_2)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  
  if ((*(byte *)(param_1 + 9) & 4) != 0) {
    return 1;
  }
  uVar5 = 0;
  do {
    if (*(long *)(param_1 + 0x18) - 1U <= uVar5) {
      return 1;
    }
    uVar4 = (ulong)((int)uVar5 + 1);
    lVar2 = memdescGetPte(param_1,param_2,uVar5);
    uVar1 = *(uint *)(param_1 + 0x160);
    lVar3 = memdescGetPte(param_1,param_2,uVar4);
    uVar5 = uVar4;
  } while ((ulong)uVar1 + lVar2 == lVar3);
  return 0;
}


// ===== 003b4bf0 memdescSetContiguity =====

void memdescSetContiguity(long param_1,undefined8 param_2,char param_3)

{
  ulong uVar1;
  
  if (param_1 != 0) {
    uVar1 = *(ulong *)(param_1 + 8) | 0x400;
    if (param_3 == '\0') {
      uVar1 = *(ulong *)(param_1 + 8) & 0xfffffffffffffbff;
    }
    *(ulong *)(param_1 + 8) = uVar1;
    return;
  }
  nvAssertFailedNoLog("pMemDesc","src/kernel/gpu/mem_mgr/mem_desc.c",0xfdc);
  return;
}


// ===== 003b4c30 memdescGetAddressSpace =====

undefined4 memdescGetAddressSpace(long param_1)

{
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x68);
  }
  nvAssertFailedNoLog("pMemDesc != NULL","src/kernel/gpu/mem_mgr/mem_desc.c",0xfee);
  return 0;
}


// ===== 003b4c60 memdescGetPageSize =====

undefined8 memdescGetPageSize(long param_1)

{
  return *(undefined8 *)(param_1 + 0x10);
}


// ===== 003b4c70 memdescSetPageSize =====

void memdescSetPageSize(long param_1,undefined8 param_2,undefined8 param_3)

{
  if (*(uint *)(param_1 + 0x8c) < 2) {
    *(undefined8 *)(param_1 + 0x10) = param_3;
    return;
  }
  nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c",
                      0x1013);
  *(undefined8 *)(param_1 + 0x10) = param_3;
  return;
}


// ===== 003b4cc0 memdescGetRootMemDesc =====

void memdescGetRootMemDesc(long param_1,long *param_2)

{
  long lVar1;
  long lVar2;
  
  lVar2 = 0;
  lVar1 = *(long *)(param_1 + 200);
  while (lVar1 != 0) {
    if (*(char *)(param_1 + 100) != '\0') {
      nvAssertFailedNoLog("!pMemDesc->Allocated","src/kernel/gpu/mem_mgr/mem_desc.c",0x1030);
    }
    lVar2 = lVar2 + *(long *)(param_1 + 0x58);
    param_1 = *(long *)(param_1 + 200);
    lVar1 = *(long *)(param_1 + 200);
  }
  if (param_2 != (long *)0x0) {
    *param_2 = lVar2;
  }
  return;
}


// ===== 003b4d60 memdescSetCustomHeap =====

void memdescSetCustomHeap(long param_1,int param_2)

{
  if (param_2 != 1) {
    if (param_2 == 2) {
      *(ulong *)(param_1 + 8) = *(ulong *)(param_1 + 8) | 0x8000000000000;
    }
    return;
  }
  *(ulong *)(param_1 + 8) = *(ulong *)(param_1 + 8) | 0x40000;
  return;
}


// ===== 003b4d90 memdescGetCustomHeap =====

int memdescGetCustomHeap(long param_1)

{
  int iVar1;
  
  iVar1 = ((uint)(*(ulong *)(param_1 + 8) >> 0x33) & 1) * 2;
  if ((*(ulong *)(param_1 + 8) & 0x40000) != 0) {
    iVar1 = 1;
  }
  return iVar1;
}


// ===== 003b4dc0 memdescGetIommuMap =====

void memdescGetIommuMap(long param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x108);
  if (piVar1 == (int *)0x0) {
    return;
  }
  do {
    if (*piVar1 == param_2) {
      return;
    }
    piVar1 = *(int **)(piVar1 + 6);
  } while (piVar1 != (int *)0x0);
  return;
}


// ===== 003b4df0 memdescAddIommuMap =====

undefined8 memdescAddIommuMap(long param_1,long param_2)

{
  if (*(long *)(param_1 + 0x108) == 0) {
    if (*(long *)(param_1 + 200) != 0) {
      *(long *)(param_1 + 0x108) = param_2;
      return 0;
    }
  }
  else if (*(long *)(param_1 + 200) != 0) {
    nvAssertFailedNoLog("(pMemDesc->_pIommuMappings == NULL) || (!memdescIsSubMemoryMemDesc(pMemDesc))"
                        ,"src/kernel/gpu/mem_mgr/mem_desc.c",0x1085);
    return 0x1f;
  }
  *(long *)(param_2 + 0x18) = *(long *)(param_1 + 0x108);
  *(long *)(param_1 + 0x108) = param_2;
  return 0;
}


// ===== 003b4e60 memdescRemoveIommuMap =====

void memdescRemoveIommuMap(long param_1,long param_2)

{
  long lVar1;
  undefined8 *puVar2;
  
  lVar1 = *(long *)(param_1 + 0x108);
  if (*(long *)(param_1 + 200) == 0) {
    if (lVar1 != 0) {
      puVar2 = (undefined8 *)(param_1 + 0x108);
      do {
        if (param_2 == lVar1) {
          *puVar2 = *(undefined8 *)(param_2 + 0x18);
          return;
        }
        puVar2 = (undefined8 *)(lVar1 + 0x18);
        lVar1 = *(long *)(lVar1 + 0x18);
      } while (lVar1 != 0);
    }
    nvAssertFailedNoLog("*ppTmpIommuMap != NULL","src/kernel/gpu/mem_mgr/mem_desc.c",0x10b3);
    return;
  }
  if (lVar1 != param_2) {
    nvAssertFailedNoLog("pMemDesc->_pIommuMappings == pIommuMap","src/kernel/gpu/mem_mgr/mem_desc.c"
                        ,0x10c0);
    return;
  }
  *(undefined8 *)(param_1 + 0x108) = 0;
  return;
}


// ===== 003b4f00 memdescUnmapIommu =====

void memdescUnmapIommu(long param_1,int param_2)

{
  undefined8 uVar1;
  int *piVar2;
  
  if (param_2 == -1) {
    return;
  }
  for (piVar2 = *(int **)(param_1 + 0x108); piVar2 != (int *)0x0; piVar2 = *(int **)(piVar2 + 6)) {
    if (param_2 == *piVar2) goto LAB_003b4f2d;
  }
  piVar2 = (int *)0x0;
  nvAssertFailedNoLog("pIovaMapping","src/kernel/gpu/mem_mgr/mem_desc.c",0x111d);
LAB_003b4f2d:
  uVar1 = iovaspaceFromMapping(piVar2);
  iovaspaceReleaseMapping_IMPL(uVar1,piVar2);
  return;
}


// ===== 003b4f80 memdescMapIommu =====

int memdescMapIommu(long *param_1,int param_2)

{
  long *plVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  long local_40 [2];
  
  if (param_2 != -1) {
    if (param_1 == (long *)0x0) {
      nvAssertFailedNoLog("pMemDesc != NULL","src/kernel/gpu/mem_mgr/mem_desc.c",0xfee);
      gpumgrGetGpuFromId(param_2);
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    lVar9 = param_1[0xd];
    uVar5 = gpumgrGetGpuFromId(param_2);
    lVar6 = param_1[0x19];
    plVar1 = param_1;
    while (lVar6 != 0) {
      if (*(char *)((long)plVar1 + 100) != '\0') {
        nvAssertFailedNoLog("!pMemDesc->Allocated","src/kernel/gpu/mem_mgr/mem_desc.c",0x1030);
      }
      plVar1 = (long *)plVar1[0x19];
      lVar6 = plVar1[0x19];
    }
    if (((int)lVar9 == 1) || (cVar3 = gpumgrCheckIndirectPeer_IMPL(uVar5,*plVar1), cVar3 != '\0')) {
      lVar6 = iovaspaceFromId(param_2);
      if (lVar6 == 0) {
        nvAssertFailedNoLog("pIOVAS","src/kernel/gpu/mem_mgr/mem_desc.c",0x10d4);
        return 0x57;
      }
      iVar4 = iovaspaceAcquireMapping_IMPL(lVar6,param_1);
      if (iVar4 != 0) {
        nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/mem_desc.c",0x10d7);
        return iVar4;
      }
    }
  }
  if (*(char *)((long)param_1 + 100) == '\0') {
    if (*(uint *)((long)param_1 + 0x8c) < 2) {
      uVar7 = param_1[1];
      if ((uVar7 & 0x800000) != 0) goto LAB_003b503e;
    }
    else {
      nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                          "src/kernel/gpu/mem_mgr/mem_desc.c",0xf37);
      uVar7 = param_1[1];
      if ((uVar7 & 0x800000) != 0) goto LAB_003b503e;
      if (1 < *(uint *)((long)param_1 + 0x8c)) {
        nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                            "src/kernel/gpu/mem_mgr/mem_desc.c",0xf37);
        uVar7 = param_1[1];
      }
    }
    if ((uVar7 & 0x80000000) == 0) {
      return 0;
    }
  }
LAB_003b503e:
  if ((int)param_1[0xd] == 1) {
    lVar6 = *param_1;
    uVar7 = gpuGetDmaEndAddress_IMPL(lVar6);
    if ((*(byte *)((long)param_1 + 9) & 4) == 0) {
      uVar8 = 0;
      if (param_1[3] != 0) {
        do {
          lVar9 = memdescGetPte(param_1,1,uVar8);
          if (uVar7 < (ulong)((int)param_1[0x2c] - 1) + lVar9) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0x1102,"memdescMapIommu",4,
                         "NVRM: 0x%llx is not addressable by GPU 0x%x [0x0-0x%llx]\n",lVar9,
                         *(undefined4 *)(lVar6 + 0x7ac),uVar7);
            memdescUnmapIommu(param_1,param_2);
            return 0x1e;
          }
          uVar8 = (ulong)((int)uVar8 + 1);
        } while (uVar8 < (ulong)param_1[3]);
      }
    }
    else {
      memdescGetPhysAddrsForGpu(param_1,*param_1,1,0,0,1,local_40);
      uVar8 = local_40[0] + -1 + param_1[6];
      if (uVar7 < uVar8) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0x10f2,"memdescMapIommu",4,
                     "NVRM: 0x%llx-0x%llx is not addressable by GPU 0x%x [0x0-0x%llx]\n",local_40[0]
                     ,uVar8,*(undefined4 *)(lVar6 + 0x7ac),uVar7);
        memdescUnmapIommu(param_1,param_2);
        return 0x1e;
      }
    }
  }
  return 0;
}


// ===== 003b5300 memdescAlloc =====

int memdescAlloc(long *param_1)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar9;
  long lVar10;
  long lVar11;
  long *plVar12;
  long local_140;
  undefined8 *local_130;
  long *aplStack_128 [14];
  undefined8 local_b8;
  uint local_b0 [2];
  undefined8 uStack_a8;
  uint local_a0;
  uint local_9c;
  long local_78;
  long local_70;
  long local_68;
  ulong uVar8;
  
  if (*(char *)((long)param_1 + 100) != '\0') {
    nvAssertFailedNoLog("!pMemDesc->Allocated","src/kernel/gpu/mem_mgr/mem_desc.c",0x457);
    return 0x32;
  }
  lVar10 = *param_1;
  if ((int)param_1[0xd] == 1) {
    if (*(char *)(g_pSys + 0xa4) == '\0') {
      if (1 < *(uint *)((long)param_1 + 0x8c)) {
        nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                            "src/kernel/gpu/mem_mgr/mem_desc.c",0xf52);
      }
      uVar6 = param_1[1] & 0xffffdfffffffffff;
      param_1[1] = uVar6;
    }
    else {
      cVar3 = gpuIsCCorApmFeatureEnabled_IMPL(lVar10);
      if (cVar3 == '\0') {
LAB_003b5a60:
        if (1 < *(uint *)((long)param_1 + 0x8c)) {
          nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                              "src/kernel/gpu/mem_mgr/mem_desc.c",0xf52);
        }
        uVar6 = param_1[1];
LAB_003b5a71:
        uVar6 = uVar6 | 0x200000000000;
        param_1[1] = uVar6;
      }
      else {
        cVar3 = gpuIsApmFeatureEnabled_IMPL(lVar10);
        if (cVar3 == '\0') goto LAB_003b550b;
        if (*(uint *)((long)param_1 + 0x8c) < 2) {
          uVar6 = param_1[1];
          if ((uVar6 >> 0x2c & 1) == 0) goto LAB_003b5a71;
        }
        else {
          nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                              "src/kernel/gpu/mem_mgr/mem_desc.c",0xf37);
          uVar6 = param_1[1];
          if ((uVar6 >> 0x2c & 1) == 0) goto LAB_003b5a60;
        }
      }
    }
  }
  else {
    if ((int)param_1[0xd] != 2) {
      return 0xffff;
    }
    if (*(char *)(*(long *)(lVar10 + 0x4d8) + 0x80) == '\0') {
      cVar3 = gpuIsApmFeatureEnabled_IMPL(lVar10);
      if (cVar3 != '\0') {
        if (1 < *(uint *)((long)param_1 + 0x8c)) {
          nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                              "src/kernel/gpu/mem_mgr/mem_desc.c",0xf52);
        }
        param_1[1] = param_1[1] | 0x200000000000;
      }
      if ((*(char *)(lVar10 + 0x44d) == '\0') || (*(char *)(lVar10 + 0x4921) != '\0')) {
        iVar4 = 0;
      }
      else {
        iVar4 = 1;
        nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0x4a8,"memdescAlloc",4,
                     "NVRM: Unsupported FB bound allocation on broken FB(0FB) platform\n");
      }
      if (param_1[0x14] != 0) {
        nvAssertFailedNoLog("pMemDesc->pHeap == NULL","src/kernel/gpu/mem_mgr/mem_desc.c",0x4ac);
      }
      uVar6 = param_1[1];
      if ((uVar6 >> 0x24 & 1) == 0) {
        lVar10 = *(long *)(lVar10 + 0x1b78);
        if ((uVar6 & 0x2000000) == 0) {
          if ((lVar10 != 0) && ((int)param_1[0xd] == 2)) {
            param_1[0x14] = *(long *)(lVar10 + 0x478);
          }
        }
        else {
          lVar10 = memmgrGetDeviceSuballocator_IMPL(lVar10,(ushort)(uVar6 >> 0x30) & 1);
          param_1[0x14] = lVar10;
        }
      }
      else {
        if (1 < *(uint *)((long)param_1 + 0x8c)) {
          nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                              "src/kernel/gpu/mem_mgr/mem_desc.c",0x11ab);
LAB_003b5f61:
          nvAssertFailedNoLog("pCtxBufPool != NULL","src/kernel/gpu/mem_mgr/mem_desc.c",0x4b5);
          return 0x40;
        }
        if (param_1[0x29] == 0) goto LAB_003b5f61;
      }
      if (iVar4 != 0) {
        return iVar4;
      }
LAB_003b550b:
      uVar6 = param_1[1];
    }
    else {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0x492,"memdescAlloc",3,
                   "NVRM: WARNING FB alloc on ZERO_FB config moved to sysmem\n");
      *(undefined4 *)(param_1 + 0xd) = 1;
      uVar6 = param_1[1];
    }
  }
  if ((uVar6 & 1) != 0) {
    nvAssertFailedNoLog("!((pMemDesc->_flags & MEMDESC_FLAGS_ALLOC_PER_SUBDEVICE) && !gpumgrGetBcEnabledStatus(pGpu))"
                        ,"src/kernel/gpu/mem_mgr/mem_desc.c",0x535);
  }
  if (*(char *)((long)param_1 + 100) != '\0') {
    iVar4 = 0x32;
    nvAssertFailedNoLog("!pMemDesc->Allocated","src/kernel/gpu/mem_mgr/mem_desc.c",0x334);
    goto LAB_003b54a0;
  }
  lVar10 = *param_1;
  if ((int)param_1[0xd] == 1) {
    iVar4 = osAllocPagesInternal(param_1);
    if (iVar4 == 0) {
      if ((*param_1 != 0) && (cVar3 = memdescIsEgm_part_0(param_1), cVar3 != '\0')) {
        lVar9 = param_1[3];
        lVar1 = param_1[0x19];
        plVar12 = param_1;
        while (lVar1 != 0) {
          if (*(char *)((long)plVar12 + 100) != '\0') {
            nvAssertFailedNoLog("!pMemDesc->Allocated","src/kernel/gpu/mem_mgr/mem_desc.c",0x1030);
          }
          plVar12 = (long *)plVar12[0x19];
          lVar1 = plVar12[0x19];
        }
        lVar1 = *(long *)(*plVar12 + 0x1b78);
        plVar12 = (long *)param_1[0x2d];
        if ((*(byte *)((long)param_1 + 9) & 4) == 0) {
          if (plVar12 == (long *)0x0) {
            lVar11 = portMemAllocNonPaged(lVar9 * 8);
            param_1[0x2d] = lVar11;
            if (lVar11 == 0) goto LAB_003b6057;
          }
          if ((lVar9 != 0) &&
             (*(long *)param_1[0x2d] = param_1[0x2e] - *(long *)(lVar1 + 0x460), lVar9 != 1)) {
            lVar11 = 1;
            do {
              *(long *)(param_1[0x2d] + lVar11 * 8) =
                   param_1[lVar11 + 0x2e] - *(long *)(lVar1 + 0x460);
              lVar11 = lVar11 + 1;
            } while (lVar9 != lVar11);
          }
        }
        else {
          if (plVar12 == (long *)0x0) {
            plVar12 = (long *)portMemAllocNonPaged(8);
            param_1[0x2d] = (long)plVar12;
            if (plVar12 == (long *)0x0) {
LAB_003b6057:
              lVar9 = 0;
              nvAssertFailedNoLog("pMemDesc->pPteEgmMappings != NULL",
                                  "src/kernel/gpu/mem_mgr/mem_desc.c",0x314);
              iVar4 = 0x51;
              nvAssertOkFailedNoLog
                        (0x51,"_memdescAllocEgmArray(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c",
                         0x349);
              local_140 = 0;
              goto LAB_003b546c;
            }
          }
          *plVar12 = param_1[0x2e] - *(long *)(lVar1 + 0x460);
        }
      }
      *(undefined1 *)((long)param_1 + 100) = 1;
      if (1 < *(uint *)((long)param_1 + 0x8c)) {
        nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                            "src/kernel/gpu/mem_mgr/mem_desc.c",0xf37);
      }
      uVar6 = param_1[1];
      if ((uVar6 & 0x400000) == 0) {
        if ((*param_1 == 0) || (cVar3 = memdescIsEgm_part_0(param_1), cVar3 == '\0')) {
          if (1 < *(uint *)((long)param_1 + 0x8c)) {
            nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                                "src/kernel/gpu/mem_mgr/mem_desc.c",0xf37);
          }
          uVar6 = param_1[1];
          if ((uVar6 >> 0x2f & 1) != 0) goto LAB_003b5683;
          iVar4 = memdescMapIommu(param_1,*(undefined4 *)(lVar10 + 0x868));
          if (iVar4 != 0) {
            *(undefined1 *)((long)param_1 + 100) = 0;
            lVar9 = 0;
            osFreePagesInternal(param_1);
            local_140 = 0;
            goto LAB_003b546c;
          }
        }
        uVar6 = param_1[1];
      }
LAB_003b5683:
      local_140 = 0;
      lVar10 = 0;
      lVar9 = 0;
      if ((uVar6 & 0x10000) == 0) {
LAB_003b55d0:
        iVar4 = nvDbgRmMsgCheck("src/kernel/gpu/mem_mgr/mem_desc.c",0xdfa,"memdescPrintMemdesc",1,0,
                                0);
        if (iVar4 == 2) {
          memdescPrintMemdesc_part_0(param_1,1,"memdesc allocated");
          portMemFree(local_140);
          portMemFree(lVar10);
        }
        else {
          portMemFree(local_140);
          portMemFree(lVar10);
        }
        return 0;
      }
      iVar4 = 0x56;
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0x369,"_memdescAllocInternal",4,
                   "NVRM: SMMU mapping allocation is not supported for ARMv7.\n");
      nvAssertFailedNoLog(&DAT_00d4c747,"src/kernel/gpu/mem_mgr/mem_desc.c",0x36a);
    }
    else {
      local_140 = 0;
      lVar9 = 0;
    }
  }
  else if ((int)param_1[0xd] == 2) {
    uVar6 = param_1[1];
    lVar1 = param_1[0x14];
    if ((uVar6 >> 0x24 & 1) == 0) {
      uVar7 = 0;
      do {
        uVar5 = (int)uVar7 + 0x20;
        uVar8 = (ulong)uVar5;
        *(undefined8 *)((long)aplStack_128 + uVar7) = 0;
        *(undefined8 *)((long)aplStack_128 + uVar7 + 8) = 0;
        *(undefined8 *)((long)aplStack_128 + uVar7 + 0x10) = 0;
        *(undefined8 *)((long)aplStack_128 + uVar7 + 0x18) = 0;
        uVar7 = uVar8;
      } while (uVar5 < 0x60);
      *(undefined8 *)((long)aplStack_128 + uVar8) = 0;
      *(undefined8 *)((long)aplStack_128 + uVar8 + 8) = 0;
      uVar5 = 0;
      do {
        uVar7 = (ulong)uVar5;
        uVar5 = uVar5 + 0x20;
        *(undefined8 *)((long)&local_b8 + uVar7) = 0;
        *(undefined8 *)((long)local_b0 + uVar7) = 0;
        *(undefined8 *)((long)&uStack_a8 + uVar7) = 0;
        *(undefined8 *)((long)&local_a0 + uVar7) = 0;
      } while (uVar5 < 0x80);
      lVar11 = param_1[6];
      lVar2 = *(long *)(lVar10 + 0x1b78);
      local_130 = &local_b8;
      if ((*(char *)(lVar10 + 0x44d) == '\0') || (*(char *)(lVar10 + 0x4921) != '\0')) {
        local_70 = param_1[5];
        local_b8._0_4_ = 0xdeaf0001;
        uVar5 = ((uint)(uVar6 >> 0x14) & 1) << 0xd;
        if ((uVar6 & 0x80000) != 0) {
          uVar5 = 0x1000;
        }
        if (param_1[2] == 0x1000) {
          local_a0 = 0x800000;
        }
        else if ((param_1[2] - 0x10000U & 0xfffffffffffeffff) == 0) {
          local_a0 = 0x1000000;
        }
        local_b0[0] = (-(uint)(local_70 == 0) & 0xffffff08) + 0x100 |
                      (-(uint)(*(char *)(lVar2 + 0xd1c) == '\0') & 4) + 0x100;
        if ((uVar6 & 0x10) != 0) {
          local_b0[0] = local_b0[0] | 0x10;
          local_68 = param_1[0x2e];
        }
        local_9c = uVar5 | 8;
        if (*(int *)((long)param_1 + 0x6c) == 0) {
          local_9c = uVar5 | 4;
        }
        local_9c = local_9c | 0x4000;
        if ((uVar6 & 0x80) != 0) {
          local_b0[0] = local_b0[0] | 0x1000000;
        }
        aplStack_128[3] = param_1;
        local_78 = lVar11;
        cVar3 = gpuIsCCFeatureEnabled_IMPL(lVar10);
        if (cVar3 != '\0') {
          if ((*(byte *)((long)param_1 + 0xd) & 0x20) != 0) {
            iVar4 = 0x1f;
            nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0x3f0,"_memdescAllocInternal",4,
                         "NVRM: Non-CPR region still not created\n");
            nvAssertFailedNoLog(&DAT_00d4c747,"src/kernel/gpu/mem_mgr/mem_desc.c",0x3f1);
            goto LAB_003b54a0;
          }
          local_b0[0] = local_b0[0] | 0x1000000;
        }
        local_a0 = local_a0 | 0x10000000;
        lVar9 = portMemAllocNonPaged(0xc0);
        if (lVar9 == 0) {
          nvAssertOkFailedNoLog
                    (0x51,"pFbAllocInfo != NULL","src/kernel/gpu/mem_mgr/mem_desc.c",0x3fc);
        }
        else {
          local_140 = portMemAllocNonPaged(0x14);
          if (local_140 != 0) {
            portMemSet(lVar9,0,0xc0);
            portMemSet(local_140,0,0x14);
            *(long *)(lVar9 + 0x90) = local_140;
            memUtilsInitFBAllocInfo(&local_b8,lVar9,0,0);
            iVar4 = memmgrAllocResources_IMPL(lVar10,lVar2,&local_130,lVar9);
            if ((iVar4 == 0) &&
               (iVar4 = vidmemAllocResources(lVar10,lVar2,&local_130,lVar9,lVar1), iVar4 == 0)) {
              param_1[5] = local_70;
              param_1[6] = lVar11;
              *(uint *)((long)param_1 + 0x6c) = (uint)((local_9c & 0xc) != 4);
              uVar5 = *(uint *)(param_1 + 0x2c);
              param_1[3] = lVar11 + -1 + (ulong)*(uint *)(param_1 + 0xc) + (ulong)uVar5 >>
                           ((0xffff < uVar5) << 4 | (uVar5 & 0xaaaaaaaa) != 0 |
                            ((uVar5 & 0xff00ff00) != 0) << 3 | ((uVar5 & 0xf0f0f0f0) != 0) << 2 |
                           ((uVar5 & 0xcccccccc) != 0) * '\x02');
              goto LAB_003b55ab;
            }
            goto LAB_003b546c;
          }
          nvAssertOkFailedNoLog
                    (0x51,"pFbAllocPageFormat != NULL","src/kernel/gpu/mem_mgr/mem_desc.c",0x3ff);
        }
        iVar4 = 0x51;
        local_140 = 0;
      }
      else {
        iVar4 = 1;
        lVar9 = 0;
        local_140 = 0;
      }
    }
    else {
      if (*(uint *)((long)param_1 + 0x8c) < 2) {
        if (param_1[0x29] != 0) {
          lVar9 = 0;
          iVar4 = ctxBufPoolAllocate(param_1[0x29],param_1);
          local_140 = 0;
          if (iVar4 == 0) {
LAB_003b55ab:
            *(undefined1 *)((long)param_1 + 100) = 1;
            lVar10 = lVar9;
            if ((lVar1 != 0) && (*(int *)(lVar1 + 0x4c) == 1)) {
              heapAddRef_IMPL(lVar1);
            }
            goto LAB_003b55d0;
          }
          nvAssertOkFailedNoLog
                    (iVar4,"ctxBufPoolAllocate(pCtxBufPool, pMemDesc)",
                     "src/kernel/gpu/mem_mgr/mem_desc.c",0x391);
          goto LAB_003b546c;
        }
      }
      else {
        nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                            "src/kernel/gpu/mem_mgr/mem_desc.c",0x11ab);
      }
      nvAssertOkFailedNoLog(0x40,"pCtxBufPool != NULL","src/kernel/gpu/mem_mgr/mem_desc.c",0x38e);
      iVar4 = 0x40;
      lVar9 = 0;
      local_140 = 0;
    }
  }
  else {
    local_140 = 0;
    iVar4 = 0xffff;
    lVar9 = 0;
  }
LAB_003b546c:
  if (param_1[0x2d] != 0) {
    portMemFree();
    param_1[0x2d] = 0;
  }
  portMemFree(local_140);
  portMemFree(lVar9);
LAB_003b54a0:
  nvCheckOkFailedNoLog
            (4,iVar4,"_memdescAllocInternal(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c",0x538);
  param_1[0x14] = 0;
  return iVar4;
}


// ===== 003b60e0 memdescAllocList =====

undefined8 memdescAllocList(long *param_1,int *param_2)

{
  undefined8 uVar1;
  int iVar2;
  ulong uVar3;
  
  if (param_2 == (int *)0x0) {
    return 0x1f;
  }
  if (((*(byte *)(param_1 + 1) & 0x80) == 0) ||
     ((*(char *)(*param_1 + 0x44d) != '\0' && (*(char *)(*param_1 + 0x4921) == '\0')))) {
    iVar2 = *param_2;
    if (iVar2 == 0) {
      return 0x1f;
    }
  }
  else {
    param_2 = (int *)&ADDRLIST_FBMEM_ONLY;
    iVar2 = 2;
  }
  uVar3 = 0;
  do {
    *(int *)(param_1 + 0xd) = iVar2;
    uVar1 = memdescAlloc(param_1);
    if ((int)uVar1 == 0) {
      return uVar1;
    }
    uVar3 = (ulong)((int)uVar3 + 1);
    iVar2 = param_2[uVar3];
  } while (iVar2 != 0);
  return uVar1;
}


// ===== 003b61a0 memdescGetNvLinkGpa =====

undefined8 memdescGetNvLinkGpa(long param_1,ulong param_2,long param_3)

{
  ulong *puVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog(&DAT_00d4d556,"src/kernel/gpu/mem_mgr/mem_desc.c",0x1183);
    return 0x1f;
  }
  if (param_2 != 0) {
    uVar5 = 0;
    lVar2 = *(long *)(param_1 + 0x1b70);
    do {
      puVar1 = (ulong *)(param_3 + uVar5 * 8);
      uVar3 = *(ulong *)(lVar2 + 0x478);
      uVar4 = uVar3 + *puVar1;
      if ((CARRY8(uVar3,*puVar1)) || (*(ulong *)(lVar2 + 0x480) < uVar4)) {
        nvAssertFailedNoLog("(gpa >= pKernelMemorySystem->coherentCpuFbBase) && (gpa <= pKernelMemorySystem->coherentCpuFbEnd)"
                            ,"src/kernel/gpu/mem_mgr/mem_desc.c",0x118c);
        return 0x1f;
      }
      *puVar1 = uVar4;
      uVar5 = (ulong)((int)uVar5 + 1);
    } while (uVar5 < param_2);
  }
  return 0;
}


// ===== 003b6240 memdescSetCtxBufPool =====

undefined8 memdescSetCtxBufPool(long param_1,undefined8 param_2)

{
  if (*(char *)(param_1 + 100) != '\0') {
    nvAssertFailedNoLog("!pMemDesc->Allocated","src/kernel/gpu/mem_mgr/mem_desc.c",0x119e);
    return 0x40;
  }
  if (*(uint *)(param_1 + 0x8c) < 2) {
    *(undefined8 *)(param_1 + 0x148) = param_2;
    return 0;
  }
  nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c",
                      0x119f);
  return 0x1f;
}


// ===== 003b62b0 memdescOverrideInstLocList =====

void memdescOverrideInstLocList
               (int param_1,undefined8 param_2,undefined8 *param_3,undefined4 *param_4)

{
  if (param_1 == 2) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0x11c5,"memdescOverrideInstLocList",1,
                 "NVRM: using ncoh system memory for %s\n",param_2);
    *param_3 = &ADDRLIST_SYSMEM_ONLY;
    *param_4 = 1;
    return;
  }
  if (param_1 != 3) {
    if (param_1 == 1) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0x11c0,"memdescOverrideInstLocList",1,
                   "NVRM: using coh system memory for %s\n",param_2);
      *param_3 = &ADDRLIST_SYSMEM_ONLY;
      *param_4 = 0;
    }
    return;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0x11ca,"memdescOverrideInstLocList",1,
               "NVRM: using video memory for %s\n",param_2);
  *param_3 = &ADDRLIST_FBMEM_ONLY;
  *param_4 = 2;
  return;
}


// ===== 003b6390 memdescOverrideInstLoc =====

void memdescOverrideInstLoc(int param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_1 == 2) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0x11c5,"memdescOverrideInstLocList",1,
                 "NVRM: using ncoh system memory for %s\n",param_2);
    uVar1 = 1;
    uVar2 = 1;
  }
  else if (param_1 == 3) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0x11ca,"memdescOverrideInstLocList",1,
                 "NVRM: using video memory for %s\n",param_2);
    uVar1 = 2;
    uVar2 = 2;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_desc.c",0x11c0,"memdescOverrideInstLocList",1,
                 "NVRM: using coh system memory for %s\n",param_2);
    uVar1 = 0;
    uVar2 = 1;
  }
  *param_4 = uVar1;
  *param_3 = uVar2;
  return;
}


// ===== 003b6480 memdescOverridePhysicalAddressWidthWindowsWAR =====

void memdescOverridePhysicalAddressWidthWindowsWAR(void)

{
  return;
}


// ===== 003b6490 memdescSetName =====

void memdescSetName(void)

{
  return;
}


// ===== 003b64a0 memdescSetPageArrayGranularity =====

undefined8 memdescSetPageArrayGranularity(long param_1,ulong param_2)

{
  if (param_2 != 0x1000) {
    if ((*(byte *)(param_1 + 9) & 4) == 0) {
      if ((param_2 - 1 & param_2) != 0) {
        nvAssertFailedNoLog("(pageArrayGranularity & (pageArrayGranularity - 1)) == 0",
                            "src/kernel/gpu/mem_mgr/mem_desc.c",0x1216);
        return 0x1f;
      }
    }
    else {
      param_2 = 0x1000;
    }
  }
  if (param_2 != *(uint *)(param_1 + 0x160)) {
    if (*(long *)(param_1 + 0x170) != 0) {
      nvAssertFailedNoLog("pMemDesc->_pteArray[0] == 0","src/kernel/gpu/mem_mgr/mem_desc.c",0x121f);
      return 0x40;
    }
    *(int *)(param_1 + 0x160) = (int)param_2;
  }
  return 0;
}


// ===== 003b6540 memdescFillPages =====

void memdescFillPages(long param_1,uint param_2,long *param_3,uint param_4,ulong param_5)

{
  long *plVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  uint uVar6;
  uint uVar7;
  long *plVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  ulong uVar12;
  bool bVar13;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pMemDesc != NULL","src/kernel/gpu/mem_mgr/mem_desc.c",0x94f);
    return;
  }
  if (param_5 == 0) {
    nvAssertFailedNoLog("pageSize > 0","src/kernel/gpu/mem_mgr/mem_desc.c",0x950);
    return;
  }
  uVar5 = *(ulong *)(param_1 + 0x20);
  if (*(char *)(g_pSys + 400) == '\0') {
    iVar3 = (int)(param_5 >> 0xc);
    param_2 = param_2 * iVar3;
    if (uVar5 <= param_2) {
      nvAssertFailedNoLog("offset4k < pMemDesc->pageArraySize","src/kernel/gpu/mem_mgr/mem_desc.c",
                          0x959);
      return;
    }
    uVar10 = param_4 * iVar3;
    if (CARRY4(param_2,uVar10)) {
      nvAssertFailedNoLog("portSafeAddU32(offset4k, pageCount4k, &result4k)",
                          "src/kernel/gpu/mem_mgr/mem_desc.c",0x95a);
      return;
    }
    bVar13 = uVar5 < param_2 + uVar10;
    if (bVar13) {
      uVar10 = (int)uVar5 - param_2;
    }
    if ((param_5 & 0xfff) != 0) {
      nvAssertFailedNoLog("0 == (pageSize & (RM_PAGE_SIZE - 1))","src/kernel/gpu/mem_mgr/mem_desc.c"
                          ,0x969);
      return;
    }
    if (1 < *(uint *)(param_1 + 0x8c)) {
      nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                          "src/kernel/gpu/mem_mgr/mem_desc.c",0x96a);
      return;
    }
    if (param_4 != 0) {
      uVar9 = param_2 + 1;
      plVar1 = param_3 + param_4;
      uVar6 = param_2;
      do {
        uVar7 = uVar6 + iVar3;
        lVar2 = *param_3;
        uVar11 = uVar10;
        if (uVar7 <= uVar10) {
          uVar11 = uVar7;
        }
        *(long *)(param_1 + 0x170 + (ulong)uVar6 * 8) = lVar2;
        if (uVar9 < uVar11) {
          lVar4 = lVar2 + 0x1000;
          plVar8 = (long *)(param_1 + 0x170 + (ulong)uVar9 * 8);
          do {
            *plVar8 = lVar4;
            lVar4 = lVar4 + 0x1000;
            plVar8 = plVar8 + 1;
          } while (lVar4 != lVar2 + 0x2000 + (ulong)(uVar11 + (-2 - uVar6)) * 0x1000);
        }
        param_3 = param_3 + 1;
        uVar9 = uVar9 + iVar3;
        uVar6 = uVar7;
      } while (param_3 != plVar1);
    }
    *(undefined4 *)(param_1 + 0x160) = 0x1000;
    if (!bVar13) {
      uVar5 = (ulong)(uVar10 + param_2);
    }
    *(ulong *)(param_1 + 0x18) = uVar5;
    *(ulong *)(param_1 + 0x38) = uVar5 << 0xc;
  }
  else {
    if (uVar5 <= param_2) {
      nvAssertFailedNoLog("pageIndex < pMemDesc->pageArraySize","src/kernel/gpu/mem_mgr/mem_desc.c",
                          0x911);
      return;
    }
    if (CARRY4(param_2,param_4)) {
      nvAssertFailedNoLog("portSafeAddU32(pageIndex, pageCount, &fillLimit)",
                          "src/kernel/gpu/mem_mgr/mem_desc.c",0x912);
      return;
    }
    uVar12 = (ulong)(param_2 + param_4);
    if (uVar5 < uVar12) {
      nvAssertFailedNoLog("fillLimit <= pMemDesc->pageArraySize","src/kernel/gpu/mem_mgr/mem_desc.c"
                          ,0x913);
      return;
    }
    iVar3 = memdescSetPageArrayGranularity(param_1,param_5);
    if (iVar3 == 0) {
      if (param_4 != 0) {
        plVar1 = param_3 + param_4;
        uVar5 = (ulong)param_2;
        do {
          lVar2 = *param_3;
          param_3 = param_3 + 1;
          param_2 = param_2 + 1;
          *(long *)(param_1 + 0x170 + uVar5 * 8) = lVar2;
          uVar5 = (ulong)param_2;
        } while (plVar1 != param_3);
      }
      *(ulong *)(param_1 + 0x18) = uVar12;
      *(ulong *)(param_1 + 0x38) = param_5 * uVar12;
    }
  }
  return;
}


// ===== 003b68c0 memdescCreateSubMem =====

int memdescCreateSubMem(undefined8 *param_1,long *param_2,long param_3,ulong param_4,ulong param_5)

{
  undefined1 uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  ulong uVar7;
  undefined8 uVar8;
  long *plVar9;
  long lVar10;
  long lVar11;
  byte bVar12;
  ulong uVar13;
  uint uVar14;
  long *local_68;
  long *local_48;
  long *local_40 [2];
  
  if ((ulong)param_2[6] <= param_4) {
    nvAssertFailedNoLog("Offset < pMemDesc->Size","src/kernel/gpu/mem_mgr/mem_desc.c",0x9d9);
    return 0x1f;
  }
  if (param_5 == 0) {
    nvAssertFailedNoLog("Size != 0","src/kernel/gpu/mem_mgr/mem_desc.c",0x9da);
    return 0x1f;
  }
  if ((CARRY8(param_4,param_5)) || ((ulong)param_2[6] < param_4 + param_5)) {
    nvAssertFailedNoLog("portSafeAddU64(Offset, Size, &tmpEnd) && tmpEnd <= pMemDesc->Size",
                        "src/kernel/gpu/mem_mgr/mem_desc.c",0x9db);
    return 0x1f;
  }
  if (param_3 == 0) {
    param_3 = *param_2;
  }
  iVar4 = memdescCreate(&local_48,param_3,param_5,0,(uint)((ulong)param_2[1] >> 10) & 1,
                        (int)param_2[0xd],*(undefined4 *)((long)param_2 + 0x74),
                        param_2[1] & 0xfffffffffffdfff7U | 0x20000);
  if (iVar4 != 0) {
    return iVar4;
  }
  bVar12 = *(byte *)((long)param_2 + 9);
  local_48[6] = param_5;
  uVar13 = local_48[1] & 0xfffffffffffffdff;
  if ((bVar12 & 2) != 0) {
    uVar13 = local_48[1] | 0x200;
  }
  local_48[1] = uVar13;
  *(undefined4 *)((long)local_48 + 0x84) = *(undefined4 *)((long)param_2 + 0x84);
  *(int *)(local_48 + 0x13) = (int)param_2[0x13];
  uVar7 = uVar13 & 0xfffffffffffff7ff;
  if ((*(byte *)((long)param_2 + 9) & 8) != 0) {
    uVar7 = uVar13 | 0x800;
  }
  local_48[1] = uVar7;
  uVar13 = uVar7 & 0xfffbffffffffffff;
  if ((param_2[1] & 0x4000000000000U) != 0) {
    uVar13 = uVar7 | 0x4000000000000;
  }
  local_48[1] = uVar13;
  local_48[2] = param_2[2];
  *(int *)(local_48 + 0x2c) = (int)param_2[0x2c];
  *(undefined4 *)((long)local_48 + 0x6c) = *(undefined4 *)((long)param_2 + 0x6c);
  *(int *)(local_48 + 0xe) = (int)param_2[0xe];
  *(undefined4 *)((long)local_48 + 0x7c) = *(undefined4 *)((long)param_2 + 0x7c);
  *(int *)(local_48 + 0xf) = (int)param_2[0xf];
  *(int *)(local_48 + 0x15) = (int)param_2[0x15];
  uVar1 = *(undefined1 *)((long)param_2 + 0x66);
  local_48[0x19] = (long)param_2;
  *(undefined1 *)((long)local_48 + 0x66) = uVar1;
  *(int *)(param_2 + 0x1a) = (int)param_2[0x1a] + 1;
  *(char *)(local_48 + 0x1e) = (char)param_2[0x1e];
  *(undefined4 *)((long)local_48 + 0x164) = *(undefined4 *)((long)param_2 + 0x164);
  local_48[0xb] = param_4;
  *(int *)(param_2 + 0x12) = (int)param_2[0x12] + 1;
  uVar13 = *(uint *)(param_2 + 0xc) + param_4;
  if ((*(byte *)((long)param_2 + 9) & 4) == 0) {
    uVar14 = *(uint *)(param_2 + 0x2c);
    uVar5 = uVar14 - 1 & (uint)uVar13;
    bVar12 = ((uVar14 & 0xff00ff00) != 0) << 3 | ((uVar14 & 0xffff0000) != 0) << 4 |
             (uVar14 & 0xaaaaaaaa) != 0 | ((uVar14 & 0xf0f0f0f0) != 0) << 2 |
             ((uVar14 & 0xcccccccc) != 0) * '\x02';
    *(uint *)(local_48 + 0xc) = uVar5;
    memdescFillPages(local_48,0,param_2 + (uVar13 >> bVar12) + 0x2e,
                     ((ulong)uVar5 + ((ulong)uVar14 - 1) + param_5 & -(ulong)uVar14) >> bVar12);
    if (*param_2 == 0) goto LAB_003b6e10;
LAB_003b6aff:
    cVar3 = memdescIsEgm_part_0(param_2);
    if (cVar3 != '\0') {
      lVar11 = local_48[3];
      lVar2 = local_48[0x19];
      plVar9 = local_48;
      while (lVar2 != 0) {
        if (*(char *)((long)plVar9 + 100) != '\0') {
          nvAssertFailedNoLog("!pMemDesc->Allocated","src/kernel/gpu/mem_mgr/mem_desc.c",0x1030);
        }
        plVar9 = (long *)plVar9[0x19];
        lVar2 = plVar9[0x19];
      }
      lVar2 = *(long *)(*plVar9 + 0x1b78);
      plVar9 = (long *)local_48[0x2d];
      if ((*(byte *)((long)local_48 + 9) & 4) == 0) {
        if (plVar9 == (long *)0x0) {
          lVar10 = portMemAllocNonPaged(lVar11 * 8);
          local_48[0x2d] = lVar10;
          if (lVar10 == 0) {
LAB_003b6f42:
            nvAssertFailedNoLog("pMemDesc->pPteEgmMappings != NULL",
                                "src/kernel/gpu/mem_mgr/mem_desc.c",0x314);
            nvAssertOkFailedNoLog
                      (0x51,"_memdescAllocEgmArray(pMemDescNew)","src/kernel/gpu/mem_mgr/mem_desc.c"
                       ,0xa2c);
            plVar9 = local_48 + 0x12;
            *(int *)plVar9 = (int)*plVar9 + -1;
            if ((int)*plVar9 == 0) {
              memdescDestroy_part_0(local_48);
            }
            return 0x51;
          }
        }
        if ((lVar11 != 0) &&
           (*(long *)local_48[0x2d] = local_48[0x2e] - *(long *)(lVar2 + 0x460), lVar11 != 1)) {
          lVar10 = 1;
          do {
            *(long *)(local_48[0x2d] + lVar10 * 8) =
                 local_48[lVar10 + 0x2e] - *(long *)(lVar2 + 0x460);
            lVar10 = lVar10 + 1;
          } while (lVar11 != lVar10);
        }
      }
      else {
        if (plVar9 == (long *)0x0) {
          plVar9 = (long *)portMemAllocNonPaged(8);
          local_48[0x2d] = (long)plVar9;
          if (plVar9 == (long *)0x0) goto LAB_003b6f42;
        }
        *plVar9 = local_48[0x2e] - *(long *)(lVar2 + 0x460);
      }
    }
    if (((int)param_2[0xd] == 1) &&
       ((*param_2 == 0 || (cVar3 = memdescIsEgm_part_0(param_2), cVar3 == '\0'))))
    goto LAB_003b6c76;
  }
  else {
    memdescDescribe(local_48,(int)local_48[0xd],uVar13 + param_2[0x2e],param_5);
    if (*param_2 != 0) goto LAB_003b6aff;
LAB_003b6e10:
    if ((int)param_2[0xd] == 1) {
LAB_003b6c76:
      uVar6 = gpumgrGetSubDeviceInstanceFromGpu(param_3);
      if (*(uint *)((long)param_2 + 0x8c) < 2) {
        if ((*(byte *)((long)param_2 + 10) & 0x40) != 0) goto LAB_003b6bf4;
      }
      else {
        lVar11 = memdescGetMemDescFromIndex(param_2,uVar6);
        if (1 < *(uint *)(lVar11 + 0x8c)) {
          nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                              "src/kernel/gpu/mem_mgr/mem_desc.c",0xf37);
        }
        if ((*(byte *)(lVar11 + 10) & 0x40) != 0) goto LAB_003b6b19;
      }
      uVar6 = gpumgrGetSubDeviceInstanceFromGpu(param_3);
      if (*(uint *)((long)param_2 + 0x8c) < 2) {
        if ((*(byte *)((long)param_2 + 0xc) & 0x80) != 0) goto LAB_003b6bf4;
      }
      else {
        lVar11 = memdescGetMemDescFromIndex(param_2,uVar6);
        if (1 < *(uint *)(lVar11 + 0x8c)) {
          nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                              "src/kernel/gpu/mem_mgr/mem_desc.c",0xf37);
        }
        if ((*(byte *)(lVar11 + 0xc) & 0x80) != 0) goto LAB_003b6b19;
      }
      uVar6 = gpumgrGetSubDeviceInstanceFromGpu(param_3);
      if (*(uint *)((long)param_2 + 0x8c) < 2) {
        if ((*(byte *)((long)param_2 + 0xd) & 0x80) != 0) goto LAB_003b6bf4;
      }
      else {
        lVar11 = memdescGetMemDescFromIndex(param_2,uVar6);
        if (1 < *(uint *)(lVar11 + 0x8c)) {
          nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                              "src/kernel/gpu/mem_mgr/mem_desc.c",0xf37);
        }
        if ((*(byte *)(lVar11 + 0xd) & 0x80) != 0) goto LAB_003b6b19;
      }
      iVar4 = memdescMapIommu(local_48,*(undefined4 *)(param_3 + 0x868));
      if (iVar4 != 0) {
        plVar9 = local_48 + 0x12;
        *(int *)plVar9 = (int)*plVar9 + -1;
        if ((int)*plVar9 != 0) {
          return iVar4;
        }
        memdescDestroy_part_0(local_48);
        return iVar4;
      }
    }
  }
LAB_003b6b19:
  if (1 < *(uint *)((long)param_2 + 0x8c)) {
    uVar14 = 0;
    *(uint *)((long)local_48 + 0x8c) = *(uint *)((long)param_2 + 0x8c);
    local_68 = local_48;
    do {
      uVar8 = gpumgrGetGpuFromSubDeviceInst(*(undefined4 *)(param_3 + 0x7b4),uVar14);
      uVar6 = gpumgrGetSubDeviceInstanceFromGpu(uVar8);
      plVar9 = param_2;
      if (1 < *(uint *)((long)param_2 + 0x8c)) {
        plVar9 = (long *)memdescGetMemDescFromIndex(param_2,uVar6);
      }
      iVar4 = memdescCreateSubMem(local_40,plVar9,uVar8,param_4,param_5);
      if (iVar4 != 0) {
        do {
          plVar9 = (long *)local_48[0x1b];
          local_48 = local_48 + 0x12;
          *(int *)local_48 = (int)*local_48 + -1;
          if ((int)*local_48 == 0) {
            memdescDestroy_part_0();
          }
          local_48 = plVar9;
        } while (plVar9 != (long *)0x0);
        return iVar4;
      }
      uVar14 = uVar14 + 1;
      local_68[0x1b] = (long)local_40[0];
      local_68 = local_40[0];
    } while (uVar14 < *(uint *)((long)param_2 + 0x8c));
  }
LAB_003b6bf4:
  *param_1 = local_48;
  return 0;
}


// ===== 003b7040 memdescFillMemdescForPhysAttr =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
memdescFillMemdescForPhysAttr
          (long *param_1,undefined8 param_2,long *param_3,undefined4 *param_4,undefined4 *param_5,
          int *param_6,int *param_7,long *param_8)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  undefined4 uVar6;
  int iVar7;
  undefined8 uVar8;
  ulong uVar9;
  long local_40 [2];
  
  lVar2 = *param_3;
  memdescGetPhysAddrsForGpu(param_1,*param_1,param_2,0,0,1,local_40);
  lVar5 = local_40[0];
  lVar3 = param_1[6];
  lVar4 = *(long *)(*param_1 + 0x1b78);
  uVar6 = (**(code **)(lVar4 + 0x2d8))(*param_1,lVar4,*(undefined4 *)((long)param_1 + 0x84));
  *param_5 = uVar6;
  memdescGetPhysAddrsForGpu(param_1,*param_1,param_2,lVar2,0,1,local_40);
  *param_3 = local_40[0];
  iVar7 = (int)param_1[0xd];
  if (iVar7 == 2) {
    uVar6 = 0;
  }
  else {
    uVar6 = 1;
    if (iVar7 != 1) {
      uVar8 = 0xffff;
      if (iVar7 == 4) {
        uVar8 = 0x56;
      }
      return uVar8;
    }
  }
  uVar1 = lVar3 + -1 + lVar5;
  *param_4 = uVar6;
  iVar7 = 1;
  if (*(int *)((long)param_1 + 0x6c) != 0) {
    iVar7 = (uint)(*(int *)((long)param_1 + 0x6c) == 1) * 2;
  }
  *param_6 = iVar7;
  if (*(uint *)((long)param_1 + 0x8c) < 2) {
    iVar7 = (int)param_1[0xe];
    if (iVar7 != 0) {
LAB_003b71f0:
      iVar7 = (uint)(iVar7 == 1) * 2;
      goto LAB_003b714c;
    }
  }
  else {
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/gpu/mem_mgr/mem_desc.c"
                        ,0xdab);
    iVar7 = (int)param_1[0xe];
    if (iVar7 != 0) {
      if (1 < *(uint *)((long)param_1 + 0x8c)) {
        nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                            "src/kernel/gpu/mem_mgr/mem_desc.c",0xdab);
        iVar7 = (int)param_1[0xe];
      }
      goto LAB_003b71f0;
    }
  }
  iVar7 = 1;
LAB_003b714c:
  uVar9 = lVar5 + lVar2;
  *param_7 = iVar7;
  *param_8 = (uVar1 + 1) - uVar9;
  if (((*(byte *)((long)param_1 + 9) & 4) == 0) && ((uVar9 | 0xfff) <= uVar1)) {
    *param_8 = ((uVar9 | 0xfff) - uVar9) + 1;
  }
  return 0;
}


// ===== 003b7200 memdescIsEgm =====

undefined8 memdescIsEgm(long *param_1)

{
  undefined8 uVar1;
  
  if (*param_1 != 0) {
    uVar1 = memdescIsEgm_part_0();
    return uVar1;
  }
  return 0;
}


// ===== 003b7220 memdescGetAdjustedPageSize =====

void memdescGetAdjustedPageSize(long param_1)

{
  undefined8 uVar1;
  
  osGetPageSize();
  if (((*(byte *)(param_1 + 9) & 4) == 0) && (*(long *)(param_1 + 0x10) == 0)) {
    uVar1 = osGetPageSize();
    if (1 < *(uint *)(param_1 + 0x8c)) {
      nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                          "src/kernel/gpu/mem_mgr/mem_desc.c",0x1013);
    }
    *(undefined8 *)(param_1 + 0x10) = uVar1;
    return;
  }
  return;
}


// ===== 003b72a0 memdescIteratorInit =====

undefined8 *
memdescIteratorInit(undefined8 *param_1,undefined8 *param_2,undefined8 param_3,long param_4,
                   long param_5)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  
  lVar2 = memdescGetPteArrayForGpu(param_2,*param_2);
  uVar1 = memdescGetPteArraySize(param_2,param_3);
  uVar5 = param_2[7];
  uVar7 = uVar5;
  if (uVar1 != 1) {
    uVar7 = (ulong)*(uint *)(param_2 + 0x2c);
  }
  uVar3 = (ulong)*(uint *)(param_2 + 0xc) + param_4;
  if (param_5 + uVar3 <= uVar5) {
    uVar4 = uVar3 / uVar7;
    if (uVar4 < uVar1) {
      uVar8 = uVar1 - uVar4;
      uVar5 = uVar5 - (param_5 + uVar3);
      uVar6 = uVar5 / uVar7;
      uVar5 = uVar5 % uVar7;
      if ((uVar6 < uVar8) &&
         ((lVar9 = uVar8 - uVar6, lVar9 != 1 || (uVar3 % uVar7 < uVar7 - uVar5)))) {
        *(undefined4 *)param_1 = 1;
        param_1[1] = 0;
        param_1[2] = lVar2 + uVar4 * 8;
        param_1[3] = lVar9;
        param_1[4] = uVar7;
        param_1[5] = uVar3 % uVar7;
        param_1[6] = uVar5;
        return param_1;
      }
    }
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  return param_1;
}


// ===== 003b73c0 memmapperCheckGpuFullPowerForMemory =====

byte memmapperCheckGpuFullPowerForMemory(long param_1)

{
  char cVar1;
  
  if ((param_1 != 0) && (**(long **)(param_1 + 0x118) != 0)) {
    if (*(char *)(**(long **)(param_1 + 0x118) + 0x443) == '\0') {
      cVar1 = gpuIsGpuFullPower_IMPL();
      return -(cVar1 == '\0') & 0x55;
    }
    nvAssertFailedNoLog("!pGpu->getProperty(pGpu, PDB_PROP_GPU_IN_PM_CODEPATH)",
                        "src/kernel/gpu/mem_mgr/mem_mapper.c",0x31);
    return 0x40;
  }
  return 0;
}


// ===== 003b7420 memmapperSemaphoreEventCallback =====

void memmapperSemaphoreEventCallback(long param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*(long *)(param_1 + 0x1c8) + 8);
  *piVar1 = *piVar1 + 1;
  iVar2 = osQueueWorkItem(*(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0),memoryMapperWorker,
                          *(undefined8 *)(param_1 + 0x1c8),0x413);
  if (iVar2 == 0) {
    return;
  }
  nvAssertOkFailedNoLog
            (iVar2,
             "osQueueWorkItem(GPU_RES_GET_GPU(pMemoryMapper), memoryMapperWorker, pMemoryMapper->pWorkerParams, (OsQueueWorkItemFlags){ .bDontFreeParams = NV_TRUE, .bDropOnUnloadQueueFlush = NV_TRUE, .bFallbackToDpc = NV_TRUE, .apiLock = WORKITEM_FLAGS_API_LOCK_READ_WRITE})"
             ,"src/kernel/gpu/mem_mgr/mem_mapper.c",0x14f);
  return;
}


// ===== 003b7480 memmapperQueueWork_IMPL =====

void memmapperQueueWork_IMPL(long param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*(long *)(param_1 + 0x1c8) + 8);
  *piVar1 = *piVar1 + 1;
  iVar2 = osQueueWorkItem(*(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0),memoryMapperWorker,
                          *(undefined8 *)(param_1 + 0x1c8),0x413);
  if (iVar2 == 0) {
    return;
  }
  nvAssertOkFailedNoLog
            (iVar2,
             "osQueueWorkItem(GPU_RES_GET_GPU(pMemoryMapper), memoryMapperWorker, pMemoryMapper->pWorkerParams, (OsQueueWorkItemFlags){ .bDontFreeParams = NV_TRUE, .bDropOnUnloadQueueFlush = NV_TRUE, .bFallbackToDpc = NV_TRUE, .apiLock = WORKITEM_FLAGS_API_LOCK_READ_WRITE})"
             ,"src/kernel/gpu/mem_mgr/mem_mapper.c",0x14f);
  return;
}


// ===== 003b74db memoryMapperWorker.cold =====

void memoryMapperWorker_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003b74f0 memoryMapperWorker =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void memoryMapperWorker(undefined8 param_1,long *param_2)

{
  long lVar1;
  long *plVar2;
  code *pcVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  uint uVar11;
  char *pcVar12;
  undefined8 uVar13;
  uint *puVar14;
  long local_88;
  long local_80;
  undefined8 local_78;
  undefined8 local_70;
  ulong local_68;
  long local_60;
  ulong local_58;
  ulong local_50;
  long local_48;
  undefined8 local_40;
  
  if (param_2[2] == 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mapper.c",300,"memoryMapperWorker",4,
                 "NVRM: worker is wrongly called after all work was finished \n");
    return;
  }
  lVar1 = *param_2;
  portSyncRwLockAcquireRead();
  if (*param_2 == 0) goto LAB_003b7536;
  uVar11 = *(uint *)(param_2 + 1);
  if (1 < uVar11) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mapper.c",0xd5,"memmapperProcessWork",1,
                 "NVRM: processing MemoryMapper work\n");
    if (*(char *)(lVar1 + 0x1d8) == '\0') {
      lVar7 = *(long *)(*(long *)(lVar1 + 0x128) + 0xe0);
      if (lVar7 == 0) {
        nvCheckFailedNoLog(4,"pGpu != NULL","src/kernel/gpu/mem_mgr/mem_mapper.c",0x2e);
      }
      else if (*(char *)(lVar7 + 0x443) == '\0') {
        cVar5 = gpuIsGpuFullPower_IMPL();
        if (cVar5 != '\0') {
          iVar6 = memmapperCheckGpuFullPowerForMemory
                            (*(undefined8 *)(*(long *)(*(long *)(lVar1 + 0x1d0) + 0x138) + 0x60));
          if (iVar6 == 0) {
            iVar6 = memmapperCheckGpuFullPowerForMemory
                              (*(undefined8 *)(*(long *)(*(long *)(lVar1 + 0x1d0) + 0x138) + 0x68));
            if (iVar6 == 0) {
              iVar6 = memmapperCheckGpuFullPowerForMemory(*(undefined8 *)(lVar1 + 0x160));
              if (iVar6 == 0) {
                lVar7 = rmapiGetInterface(3);
                uVar11 = *(uint *)(lVar1 + 0x19c);
                if (*(uint *)(lVar1 + 0x198) != uVar11) {
                  bVar4 = false;
                  do {
                    puVar14 = (uint *)((ulong)uVar11 * 0x38 + *(long *)(lVar1 + 400));
                    uVar11 = *puVar14;
                    if (uVar11 - 1 < 2) {
                      if (bVar4) {
                        memmapperQueueWork_IMPL(lVar1);
                        break;
                      }
                      if (uVar11 == 2) {
                        iVar6 = clientGetResourceRef_IMPL
                                          (**(undefined8 **)(*(long *)(lVar1 + 0x110) + 0x48),
                                           puVar14[2],&local_80);
                        if (iVar6 == 0) {
                          lVar8 = __nvoc_dynamicCast(*(undefined8 *)(local_80 + 8),
                                                     __nvoc_class_def_VirtualMemory);
                          if (lVar8 == 0) {
                            uVar13 = 0x7f;
                            pcVar12 = "pVirtualMemory != NULL";
                          }
                          else {
                            plVar2 = *(long **)(*(long *)(lVar8 + 0x248) + 0x118);
                            if (*plVar2 == *(long *)(*(long *)(lVar1 + 0x128) + 0xe0)) {
                              lVar8 = memdescGetPhysAddr(plVar2,3,0);
                              nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mapper.c",0x84,
                                           "memmapperExecuteUnmap",1,
                                           "NVRM: unmap virt:(0x%x:0x%llx) size:0x%llx dmaFlags:0x%x\n"
                                           ,puVar14[2],*(undefined8 *)(puVar14 + 4),
                                           *(undefined8 *)(puVar14 + 6),puVar14[8]);
                              local_70 = 0;
                              local_68 = 0;
                              local_60 = 0;
                              local_58 = 0;
                              local_50 = 0;
                              uVar11 = *(uint *)(**(long **)(*(long *)(lVar1 + 0x110) + 0x48) + 0x48
                                                );
                              local_78 = (ulong)uVar11;
                              if (*(long *)(lVar1 + 0x158) == 0) {
                    /* WARNING: Does not return */
                                pcVar3 = (code *)invalidInstructionException();
                                (*pcVar3)();
                              }
                              local_78 = CONCAT44(*(undefined4 *)
                                                   (*(long *)(*(long *)(*(long *)(*(long *)(lVar1 + 
                                                  0x158) + 0x140) + 0x48) + 0x18) + 0x10),uVar11);
                              local_70 = (ulong)puVar14[2];
                              local_68 = (ulong)puVar14[8];
                              local_60 = *(long *)(puVar14 + 4) + lVar8;
                              local_58 = *(ulong *)(puVar14 + 6);
                              iVar6 = (**(code **)(lVar7 + 0xb0))(lVar7,&local_78,lVar1 + 0x138);
                              if (iVar6 == 0) {
LAB_003b7c60:
                                bVar4 = true;
                                goto LAB_003b76fd;
                              }
                              uVar13 = 0x90;
                              pcVar12 = 
                              "pRmApi->UnmapWithSecInfo(pRmApi, &unmapDmaParams, &pMemoryMapper->secInfo)"
                              ;
                              goto LAB_003b7d49;
                            }
                            uVar13 = 0x80;
                            pcVar12 = 
                            "staticCast(pVirtualMemory, Memory)->pMemDesc->pGpu == GPU_RES_GET_GPU(pMemoryMapper)"
                            ;
                          }
                          nvCheckFailedNoLog(4,pcVar12,"src/kernel/gpu/mem_mgr/mem_mapper.c",uVar13)
                          ;
                          nvCheckOkFailedNoLog
                                    (4,0x1f,
                                     "memmapperExecuteUnmap(pMemoryMapper, &pOperation->data.unmap, pRmApi)"
                                     ,"src/kernel/gpu/mem_mgr/mem_mapper.c",0x103);
                          goto LAB_003b7a63;
                        }
                        uVar13 = 0x7d;
                        pcVar12 = 
                        "clientGetResourceRef(pClient, pUnmap->hVirtualMemory, &pVirtualResourceRef)"
                        ;
LAB_003b7d49:
                        nvCheckOkFailedNoLog
                                  (4,iVar6,pcVar12,"src/kernel/gpu/mem_mgr/mem_mapper.c",uVar13);
                        uVar13 = 0x103;
                        pcVar12 = 
                        "memmapperExecuteUnmap(pMemoryMapper, &pOperation->data.unmap, pRmApi)";
LAB_003b79f0:
                        nvCheckOkFailedNoLog
                                  (4,iVar6,pcVar12,"src/kernel/gpu/mem_mgr/mem_mapper.c",uVar13);
                        if (iVar6 == 3) break;
                      }
                      else {
                        uVar13 = **(undefined8 **)(*(long *)(lVar1 + 0x110) + 0x48);
                        iVar6 = clientGetResourceRef_IMPL(uVar13,puVar14[2],&local_88);
                        if (iVar6 != 0) {
                          uVar13 = 0x4c;
                          pcVar12 = 
                          "clientGetResourceRef(pClient, pMap->hVirtualMemory, &pVirtualResourceRef)"
                          ;
                          goto LAB_003b79b9;
                        }
                        lVar8 = __nvoc_dynamicCast(*(undefined8 *)(local_88 + 8),
                                                   __nvoc_class_def_VirtualMemory);
                        if (lVar8 == 0) {
                          uVar13 = 0x4e;
                          pcVar12 = "pVirtualMemory != NULL";
                        }
                        else {
                          plVar2 = *(long **)(*(long *)(lVar8 + 0x248) + 0x118);
                          if (*plVar2 == *(long *)(*(long *)(lVar1 + 0x128) + 0xe0)) {
                            lVar8 = memdescGetPhysAddr(plVar2,3,0);
                            iVar6 = clientGetResourceRef_IMPL(uVar13,puVar14[6],&local_80);
                            if (iVar6 == 0) {
                              lVar9 = __nvoc_dynamicCast(*(undefined8 *)(local_80 + 8),
                                                         __nvoc_class_def_Memory);
                              if (lVar9 == 0) {
                                uVar13 = 0x56;
                                pcVar12 = "pMemory != NULL";
                                goto LAB_003b7d03;
                              }
                              iVar6 = memmapperCheckGpuFullPowerForMemory(lVar9);
                              if (iVar6 == 0) {
                                nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mapper.c",0x5b,
                                             "memmapperExecuteMap",1,
                                             "NVRM: map virt:(0x%x:0x%llx)  phys:(0x%x:0x%llx) size:0x%llx dmaFlags:0x%x\n"
                                             ,puVar14[2],*(undefined8 *)(puVar14 + 4),puVar14[6],
                                             *(undefined8 *)(puVar14 + 8),
                                             *(undefined8 *)(puVar14 + 10),puVar14[0xc]);
                                local_70 = 0;
                                local_68 = 0;
                                local_60 = 0;
                                local_58 = 0;
                                local_50 = 0;
                                local_48 = 0;
                                local_40 = 0;
                                uVar11 = *(uint *)(**(long **)(*(long *)(lVar1 + 0x110) + 0x48) +
                                                  0x48);
                                local_78 = (ulong)uVar11;
                                if (*(long *)(lVar1 + 0x158) == 0) {
                    /* WARNING: Does not return */
                                  pcVar3 = (code *)invalidInstructionException();
                                  (*pcVar3)();
                                }
                                local_78 = CONCAT44(*(undefined4 *)
                                                     (*(long *)(*(long *)(*(long *)(*(long *)(lVar1 
                                                  + 0x158) + 0x140) + 0x48) + 0x18) + 0x10),uVar11);
                                local_70 = CONCAT44(puVar14[6],puVar14[2]);
                                local_68 = *(ulong *)(puVar14 + 8);
                                local_60 = *(long *)(puVar14 + 10);
                                local_58 = (ulong)puVar14[0xc] | 0x8000;
                                local_50 = (ulong)puVar14[0xd];
                                local_48 = lVar8 + *(long *)(puVar14 + 4);
                                iVar6 = (**(code **)(lVar7 + 0xa0))(lVar7,&local_78,lVar1 + 0x138);
                                if (iVar6 == 0) goto LAB_003b7c60;
                                uVar13 = 0x6c;
                                pcVar12 = 
                                "pRmApi->MapWithSecInfo(pRmApi, &mapDmaParams, &pMemoryMapper->secInfo)"
                                ;
                                goto LAB_003b79b9;
                              }
                              nvCheckOkFailedNoLog
                                        (1,iVar6,"memmapperCheckGpuFullPowerForMemory(pMemory)",
                                         "src/kernel/gpu/mem_mgr/mem_mapper.c",0x59);
                            }
                            else {
                              uVar13 = 0x54;
                              pcVar12 = 
                              "clientGetResourceRef(pClient, pMap->hPhysicalMemory, &pResourceRef)";
LAB_003b79b9:
                              nvCheckOkFailedNoLog
                                        (4,iVar6,pcVar12,"src/kernel/gpu/mem_mgr/mem_mapper.c",
                                         uVar13);
                            }
                            uVar13 = 0x100;
                            pcVar12 = 
                            "memmapperExecuteMap(pMemoryMapper, &pOperation->data.map, pRmApi)";
                            goto LAB_003b79f0;
                          }
                          uVar13 = 0x4f;
                          pcVar12 = 
                          "staticCast(pVirtualMemory, Memory)->pMemDesc->pGpu == GPU_RES_GET_GPU(pMemoryMapper)"
                          ;
                        }
LAB_003b7d03:
                        nvCheckFailedNoLog(4,pcVar12,"src/kernel/gpu/mem_mgr/mem_mapper.c",uVar13);
                        nvCheckOkFailedNoLog
                                  (4,0x1f,
                                   "memmapperExecuteMap(pMemoryMapper, &pOperation->data.map, pRmApi)"
                                   ,"src/kernel/gpu/mem_mgr/mem_mapper.c",0x100);
LAB_003b7a63:
                        iVar6 = 0x1f;
                      }
                      if (*(char *)(lVar1 + 0x1d8) == '\0') {
                        **(int **)(lVar1 + 0x188) = iVar6;
                        *(undefined1 *)(lVar1 + 0x1d8) = 1;
                      }
                      break;
                    }
                    if (2 < uVar11) {
                      if (uVar11 == 3) {
                        uVar10 = semsurfGetValue_IMPL(*(undefined8 *)(lVar1 + 0x1d0),puVar14[2]);
                        nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mapper.c",0x9f,
                                     "memmapperExecuteSemaphoreWait",1,
                                     "NVRM: wait index:0x%x val:0x%llx cur_var:0x%llx\n",puVar14[2],
                                     *(undefined8 *)(puVar14 + 4),uVar10);
                        if (uVar10 < *(ulong *)(puVar14 + 4)) break;
                      }
                      else {
                        if (uVar11 != 4) {
                          nvCheckOkFailedNoLog
                                    (4,0x1f,"NV_ERR_INVALID_ARGUMENT",
                                     "src/kernel/gpu/mem_mgr/mem_mapper.c",0x10d);
                          goto LAB_003b7a63;
                        }
                        local_70 = *(ulong *)(puVar14 + 4);
                        local_78 = (ulong)puVar14[2];
                        nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mapper.c",0xb2,
                                     "memmapperExecuteSemaphoreSignal",1,
                                     "NVRM: signal index:0x%x val:0x%llx\n",local_78,local_70);
                        iVar6 = (**(code **)(lVar7 + 0x38))
                                          (lVar7,*(undefined4 *)(lVar1 + 0x1a4),
                                           *(undefined4 *)(lVar1 + 0x1b0),
                                           "umgrGetVgpuTypeInfo(vgpuTypeId, &existingVgpuTypeInfo)",
                                           &local_78,0x10);
                        if (iVar6 != 0) {
                          uVar13 = 0xb5;
                          pcVar12 = 
                          "pRmApi->Control(pRmApi, pMemoryMapper->hInternalClient, pMemoryMapper->hInternalSemaphoreSurface, NV_SEMAPHORE_SURFACE_CTRL_CMD_SET_VALUE, &params, sizeof(params))"
                          ;
                          goto LAB_003b79f0;
                        }
                      }
                    }
LAB_003b76fd:
                    uVar11 = (*(int *)(lVar1 + 0x19c) + 1U) % *(uint *)(lVar1 + 0x1a0);
                    *(uint *)(lVar1 + 0x19c) = uVar11;
                  } while (uVar11 != *(uint *)(lVar1 + 0x198));
                }
                nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mapper.c",0x11d,"memmapperProcessWork",1,
                             "NVRM: return from MemoryMapper worker\n");
              }
              else {
                nvCheckFailedNoLog(1,
                                   "memmapperCheckGpuFullPowerForMemory(pMemoryMapper->pNotificationMemory) == NV_OK"
                                   ,"src/kernel/gpu/mem_mgr/mem_mapper.c",0xe3);
              }
            }
            else {
              nvCheckFailedNoLog(1,
                                 "memmapperCheckGpuFullPowerForMemory(pMemoryMapper->pSemSurf->pShared->pMaxSubmittedMem) == NV_OK"
                                 ,"src/kernel/gpu/mem_mgr/mem_mapper.c",0xe1);
            }
          }
          else {
            nvCheckFailedNoLog(1,
                               "memmapperCheckGpuFullPowerForMemory(pMemoryMapper->pSemSurf->pShared->pSemaphoreMem) == NV_OK"
                               ,"src/kernel/gpu/mem_mgr/mem_mapper.c",0xdf);
          }
          goto LAB_003b778e;
        }
      }
      else {
        nvAssertFailedNoLog("!pGpu->getProperty(pGpu, PDB_PROP_GPU_IN_PM_CODEPATH)",
                            "src/kernel/gpu/mem_mgr/mem_mapper.c",0x31);
      }
      nvCheckFailedNoLog(1,"memmapperCheckGpuFullPower(GPU_RES_GET_GPU(pMemoryMapper)) == NV_OK",
                         "src/kernel/gpu/mem_mgr/mem_mapper.c",0xdd);
    }
    else {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mapper.c",0xd9,"memmapperProcessWork",1,
                   "NVRM: return from MemoryMapper worker (error)\n");
    }
LAB_003b778e:
    if (*param_2 == 0) goto LAB_003b7536;
    uVar11 = *(uint *)(param_2 + 1);
  }
  if (uVar11 == 1) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mapper.c",0x137,"memoryMapperWorker",4,
                 "NVRM: Worker is called , with reference count = 0x%x and pMemoryMapper not null \n"
                 ,1);
    portSyncRwLockReleaseRead(param_2[2]);
    return;
  }
LAB_003b7536:
  portSyncRwLockReleaseRead(param_2[2]);
  if ((((int)param_2[1] != 0) &&
      (iVar6 = (int)param_2[1] + -1, *(int *)(param_2 + 1) = iVar6, iVar6 == 0)) && (*param_2 == 0))
  {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mapper.c",0x13f,"memoryMapperWorker",4,
                 "NVRM: worker is freeing param\n");
    portSyncRwLockDestroy(param_2[2]);
    portMemFree(param_2);
    return;
  }
  return;
}


// ===== 003b7fb0 memmapperConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmapperConstruct_IMPL(long param_1,long param_2,long param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long *plVar8;
  undefined8 uVar9;
  long local_48;
  long local_40 [2];
  
  lVar7 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  uVar2 = *(undefined8 *)(lVar7 + 0x1b78);
  lVar5 = rmapiGetInterface(4);
  puVar3 = *(undefined4 **)(param_3 + 0x40);
  lVar6 = *(long *)(*(long *)(param_2 + 0x10) + 0x18);
  *(undefined8 *)(param_1 + 0x138) = *(undefined8 *)(param_2 + 0x28);
  *(undefined8 *)(param_1 + 0x140) = *(undefined8 *)(param_2 + 0x30);
  *(undefined8 *)(param_1 + 0x148) = *(undefined8 *)(param_2 + 0x38);
  uVar9 = *(undefined8 *)(param_2 + 0x40);
  *(undefined4 *)(param_1 + 0x13c) = 1;
  *(undefined8 *)(param_1 + 0x150) = uVar9;
  lVar6 = __nvoc_dynamicCast(*(undefined8 *)(lVar6 + 8),__nvoc_class_def_Subdevice);
  *(long *)(param_1 + 0x158) = lVar6;
  if (lVar6 == 0) {
    nvAssertFailedNoLog("pMemoryMapper->pSubdevice != NULL","src/kernel/gpu/mem_mgr/mem_mapper.c",
                        0x17c);
    return 0x1f;
  }
  uVar1 = puVar3[1];
  if (uVar1 == 0) {
    nvAssertFailedNoLog("pAllocParams->maxQueueSize != 0","src/kernel/gpu/mem_mgr/mem_mapper.c",
                        0x17e);
    return 0x1f;
  }
  *(uint *)(param_1 + 0x1a0) = uVar1;
  lVar6 = portMemAllocNonPaged((ulong)uVar1 * 0x38);
  *(long *)(param_1 + 400) = lVar6;
  if (lVar6 == 0) {
    nvCheckOkFailedNoLog
              (4,0x51,"pMemoryMapper->pOperationQueue != NULL","src/kernel/gpu/mem_mgr/mem_mapper.c"
               ,0x182);
  }
  else {
    iVar4 = clientGetResourceRef_IMPL(*(undefined8 *)(param_2 + 8),puVar3[2],&local_48);
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog
                (iVar4,
                 "clientGetResourceRef(pCallContext->pClient, pAllocParams->hNotificationMemory, &pNotificationMemoryRef)"
                 ,"src/kernel/gpu/mem_mgr/mem_mapper.c",0x185);
      goto LAB_003b8299;
    }
    lVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),__nvoc_class_def_Memory);
    *(long *)(param_1 + 0x160) = lVar6;
    if (lVar6 == 0) {
      nvCheckOkFailedNoLog
                (4,0x1f,"pMemoryMapper->pNotificationMemory != NULL",
                 "src/kernel/gpu/mem_mgr/mem_mapper.c",0x189);
LAB_003b8293:
      iVar4 = 0x1f;
      goto LAB_003b8299;
    }
    *(undefined8 *)(param_1 + 0x168) = *(undefined8 *)(lVar6 + 0x118);
    *(undefined8 *)(param_1 + 0x170) = *(undefined8 *)(puVar3 + 4);
    lVar6 = memmgrMemBeginTransfer_IMPL(uVar2,param_1 + 0x168,4,0x20);
    *(long *)(param_1 + 0x188) = lVar6;
    if (lVar6 == 0) {
      nvAssertOkFailedNoLog
                (0x51,"pMemoryMapper->pNotification != NULL","src/kernel/gpu/mem_mgr/mem_mapper.c",
                 400);
    }
    else {
      iVar4 = memmgrGetInternalClientHandles_IMPL
                        (lVar7,uVar2,*(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe8),
                         param_1 + 0x1a4,param_1 + 0x1a8,param_1 + 0x1ac);
      if (iVar4 != 0) {
        nvAssertOkFailedNoLog
                  (iVar4,
                   "memmgrGetInternalClientHandles(pGpu, pMemoryManager, GPU_RES_GET_DEVICE(pMemoryMapper), &pMemoryMapper->hInternalClient, &pMemoryMapper->hInternalDevice, &pMemoryMapper->hInternalSubdevice)"
                   ,"src/kernel/gpu/mem_mgr/mem_mapper.c",0x192);
        goto LAB_003b8299;
      }
      iVar4 = (**(code **)(lVar5 + 0x50))
                        (lVar5,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x1ac),
                         param_1 + 0x1b0,
                         *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x110) + 0x48) + 0x48),
                         *puVar3,0);
      if (iVar4 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar4,
                   "pRmApi->DupObject(pRmApi, pMemoryMapper->hInternalClient, pMemoryMapper->hInternalSubdevice, &pMemoryMapper->hInternalSemaphoreSurface, RES_GET_CLIENT_HANDLE(pMemoryMapper), pAllocParams->hSemaphoreSurface, NV04_DUP_HANDLE_FLAGS_NONE)"
                   ,"src/kernel/gpu/mem_mgr/mem_mapper.c",0x19b);
        goto LAB_003b8299;
      }
      lVar7 = serverutilGetClientUnderLock(*(undefined4 *)(param_1 + 0x1a4));
      if (lVar7 == 0) {
        nvAssertOkFailedNoLog
                  (0x40,"pInternalClient != NULL","src/kernel/gpu/mem_mgr/mem_mapper.c",0x1a6);
        iVar4 = 0x40;
        goto LAB_003b8299;
      }
      iVar4 = clientGetResourceRef_IMPL
                        (*(undefined8 *)(lVar7 + 0x100),*(undefined4 *)(param_1 + 0x1b0),local_40);
      if (iVar4 != 0) {
        nvAssertOkFailedNoLog
                  (iVar4,
                   "clientGetResourceRef(pInternalRsClient, pMemoryMapper->hInternalSemaphoreSurface, &pSemSurfRef)"
                   ,"src/kernel/gpu/mem_mgr/mem_mapper.c",0x1a9);
        goto LAB_003b8299;
      }
      lVar7 = __nvoc_dynamicCast(*(undefined8 *)(local_40[0] + 8),__nvoc_class_def_SemaphoreSurface)
      ;
      *(long *)(param_1 + 0x1d0) = lVar7;
      if (lVar7 == 0) {
        nvCheckOkFailedNoLog
                  (4,0x1f,"pMemoryMapper->pSemSurf != NULL","src/kernel/gpu/mem_mgr/mem_mapper.c",
                   0x1ad);
        goto LAB_003b8293;
      }
      plVar8 = (long *)portMemAllocNonPaged(0x18);
      *(long **)(param_1 + 0x1c8) = plVar8;
      *plVar8 = param_1;
      *(undefined4 *)(*(long *)(param_1 + 0x1c8) + 8) = 1;
      uVar9 = portMemAllocatorGetGlobalNonPaged();
      lVar7 = *(long *)(param_1 + 0x1c8);
      uVar9 = portSyncRwLockCreate(uVar9);
      *(undefined8 *)(lVar7 + 0x10) = uVar9;
      if (*(long *)(param_1 + 0x1c8) != 0) {
        *(long *)(param_1 + 0x1c0) = param_1;
        *(code **)(param_1 + 0x1b8) = memmapperSemaphoreEventCallback;
        iVar4 = refAddDependant(local_48,*(undefined8 *)(*(long *)(param_1 + 0x110) + 0x48));
        if (iVar4 == 0) {
          return 0;
        }
        nvAssertOkFailedNoLog
                  (iVar4,"refAddDependant(pNotificationMemoryRef, RES_GET_REF(pMemoryMapper))",
                   "src/kernel/gpu/mem_mgr/mem_mapper.c",0x1b8);
        goto LAB_003b8299;
      }
      nvCheckOkFailedNoLog
                (4,0x51,"pMemoryMapper->pWorkerParams != NULL","src/kernel/gpu/mem_mgr/mem_mapper.c"
                 ,0x1b3);
    }
  }
  iVar4 = 0x51;
LAB_003b8299:
  if (*(long *)(param_1 + 0x188) != 0) {
    memmgrMemEndTransfer_IMPL(uVar2,param_1 + 0x168,4,0x20);
  }
  if (*(int *)(param_1 + 0x1b0) != 0) {
    (**(code **)(lVar5 + 0x18))(lVar5,*(undefined4 *)(param_1 + 0x1a4));
  }
  portMemFree(*(undefined8 *)(param_1 + 400));
  portMemFree(*(undefined8 *)(param_1 + 0x1c8));
  return iVar4;
}


// ===== 003b84df memmapperDestruct_IMPL.cold =====

void memmapperDestruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003b84f0 memmapperDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void memmapperDestruct_IMPL(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  
  uVar1 = *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x128) + 0xe0) + 0x1b78);
  lVar4 = rmapiGetInterface(4);
  memmgrMemEndTransfer_IMPL(uVar1,param_1 + 0x168,4,0x20);
  if (*(long *)(param_1 + 0x160) == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  refRemoveDependant(*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x160) + 0xb8) + 0x48),
                     *(undefined8 *)(*(long *)(param_1 + 0x110) + 0x48));
  (**(code **)(lVar4 + 0x18))
            (lVar4,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x1b0));
  portMemFree(*(undefined8 *)(param_1 + 400));
  if ((*(long *)(param_1 + 0x1c8) != 0) && (*(long *)(*(long *)(param_1 + 0x1c8) + 0x10) != 0)) {
    portSyncRwLockAcquireWrite();
    **(undefined8 **)(param_1 + 0x1c8) = 0;
    portSyncRwLockReleaseWrite(*(undefined8 *)(*(long *)(param_1 + 0x1c8) + 0x10));
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mapper.c",0x1eb,"memmapperDestruct_IMPL",1,
                 "NVRM: Destructor is called , reference count = 0x%x\n",
                 *(undefined4 *)(*(long *)(param_1 + 0x1c8) + 8));
    iVar3 = *(int *)(*(long *)(param_1 + 0x1c8) + 8);
    if ((iVar3 != 0) &&
       (iVar3 = iVar3 + -1, *(int *)(*(long *)(param_1 + 0x1c8) + 8) = iVar3, iVar3 == 0)) {
      portSyncRwLockDestroy(*(undefined8 *)(*(long *)(param_1 + 0x1c8) + 0x10));
      portMemFree(*(undefined8 *)(param_1 + 0x1c8));
      *(undefined8 *)(param_1 + 0x1c8) = 0;
      return;
    }
    return;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mapper.c",0x1e3,"memmapperDestruct_IMPL",4,
               "NVRM: Destructor is called after worker freed the params \n");
  return;
}


// ===== 003b8690 memmapperCtrlCmdSubmitOperations_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rbx replaced with injection: x86_indirect_thunk_rbx */

int memmapperCtrlCmdSubmitOperations_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  uint *puVar8;
  uint uVar9;
  bool bVar10;
  ulong local_58;
  undefined8 local_50;
  undefined8 local_48;
  long local_40;
  
  lVar4 = resservGetTlsCallContext();
  if (*(int *)(lVar4 + 0x28) != *(int *)(param_1 + 0x138)) {
    nvCheckFailedNoLog(4,"pCallContext->secInfo.privLevel == pMemoryMapper->secInfo.privLevel",
                       "src/kernel/gpu/mem_mgr/mem_mapper.c",0x21a);
    return 0x40;
  }
  bVar10 = *(int *)(param_1 + 0x198) == *(int *)(param_1 + 0x19c);
  if (*param_2 == 0) {
    uVar9 = 0;
    iVar3 = 0;
  }
  else {
    uVar9 = 0;
    puVar8 = param_2 + 2;
    do {
      if (*(char *)(param_1 + 0x1d8) != '\0') {
        nvCheckFailedNoLog(4,"!pMemoryMapper->bError","src/kernel/gpu/mem_mgr/mem_mapper.c",0x222);
        return 0x40;
      }
      uVar5 = (*(uint *)(param_1 + 0x198) + 1) % *(uint *)(param_1 + 0x1a0);
      if (*(uint *)(param_1 + 0x19c) == uVar5) {
        iVar3 = 0x55;
        goto LAB_003b88eb;
      }
      puVar6 = (undefined8 *)((ulong)*(uint *)(param_1 + 0x198) * 0x38 + *(long *)(param_1 + 400));
      *puVar6 = *(undefined8 *)puVar8;
      puVar6[1] = *(undefined8 *)(puVar8 + 2);
      puVar6[2] = *(undefined8 *)(puVar8 + 4);
      puVar6[3] = *(undefined8 *)(puVar8 + 6);
      puVar6[4] = *(undefined8 *)(puVar8 + 8);
      puVar6[5] = *(undefined8 *)(puVar8 + 10);
      puVar6[6] = *(undefined8 *)(puVar8 + 0xc);
      uVar1 = *puVar8;
      if (uVar1 == 3) {
        cVar2 = semsurfValidateIndex_IMPL
                          (*(undefined8 *)(param_1 + 0x1d0),*(undefined4 *)(puVar6 + 1));
        if (cVar2 == '\0') {
          uVar7 = 0x234;
LAB_003b8986:
          nvCheckOkFailedNoLog
                    (4,0x1f,
                     "semsurfValidateIndex(pMemoryMapper->pSemSurf, pOperation->data.semaphore.index)"
                     ,"src/kernel/gpu/mem_mgr/mem_mapper.c",uVar7);
LAB_003b88d3:
          iVar3 = 0x1f;
        }
        else {
          lVar4 = rmapiGetInterface(4);
          local_48 = 0;
          local_50 = puVar6[2];
          local_58 = (ulong)*(uint *)(puVar6 + 1);
          local_40 = param_1 + 0x1b8;
          iVar3 = (**(code **)(lVar4 + 0x38))
                            (lVar4,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x1b0)
                             ,"pumgrGetVgpuTypeInfo(vgpuTypeId, &existingVgpuTypeInfo)",&local_58,
                             0x20);
          if (iVar3 == 0) {
            bVar10 = (bool)(bVar10 & *(int *)(param_1 + 0x198) != *(int *)(param_1 + 0x19c));
            goto LAB_003b8781;
          }
          if (iVar3 == 0x7b) goto LAB_003b8789;
          nvCheckFailedNoLog(4,"status == NV_OK || status == NV_ERR_ALREADY_SIGNALLED",
                             "src/kernel/gpu/mem_mgr/mem_mapper.c",0x209);
          nvCheckFailedNoLog(4,"status == NV_OK","src/kernel/gpu/mem_mgr/mem_mapper.c",0x243);
        }
        if (*(char *)(param_1 + 0x1d8) == '\0') {
          **(int **)(param_1 + 0x188) = iVar3;
          *(undefined1 *)(param_1 + 0x1d8) = 1;
        }
        goto LAB_003b88eb;
      }
      if (uVar1 < 4) {
        if (1 < uVar1 - 1) {
LAB_003b88b0:
          nvCheckOkFailedNoLog
                    (4,0x1f,"NV_ERR_INVALID_ARGUMENT","src/kernel/gpu/mem_mgr/mem_mapper.c",0x24f);
          goto LAB_003b88d3;
        }
      }
      else {
        if (uVar1 != 4) goto LAB_003b88b0;
        cVar2 = semsurfValidateIndex_IMPL
                          (*(undefined8 *)(param_1 + 0x1d0),*(undefined4 *)(puVar6 + 1));
        if (cVar2 == '\0') {
          uVar7 = 0x246;
          goto LAB_003b8986;
        }
      }
LAB_003b8781:
      *(uint *)(param_1 + 0x198) = uVar5;
LAB_003b8789:
      uVar9 = uVar9 + 1;
      puVar8 = puVar8 + 0xe;
    } while (uVar9 < *param_2);
    iVar3 = 0;
  }
LAB_003b88eb:
  param_2[0xe002] = uVar9;
  if ((bVar10) && (*(int *)(param_1 + 0x198) != *(int *)(param_1 + 0x19c))) {
    memmapperQueueWork_IMPL(param_1);
    return iVar3;
  }
  return iVar3;
}


// ===== 003b8a40 memmapperCtrlCmdResizeQueue_IMPL =====

undefined8 memmapperCtrlCmdResizeQueue_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  ulong uVar5;
  uint uVar6;
  undefined8 *puVar7;
  
  if (*param_2 <
      ((*(int *)(param_1 + 0x198) + *(uint *)(param_1 + 0x1a0)) - *(int *)(param_1 + 0x19c)) %
      *(uint *)(param_1 + 0x1a0) + 1) {
    nvCheckFailedNoLog(4,"Queue size too small","src/kernel/gpu/mem_mgr/mem_mapper.c",0x273);
    return 0x1f;
  }
  puVar2 = (undefined8 *)portMemAllocNonPaged((ulong)*param_2 * 0x38);
  if (puVar2 == (undefined8 *)0x0) {
    nvCheckFailedNoLog(4,"pNewOperationQueue != NULL","src/kernel/gpu/mem_mgr/mem_mapper.c",0x279);
    uVar3 = 0x51;
  }
  else {
    uVar5 = (ulong)*(uint *)(param_1 + 0x19c);
    uVar6 = 0;
    puVar4 = puVar2;
    do {
      if ((int)uVar5 == *(int *)(param_1 + 0x198)) {
        portMemFree();
        *(undefined8 **)(param_1 + 400) = puVar2;
        uVar1 = *param_2;
        *(uint *)(param_1 + 0x198) = uVar6;
        *(uint *)(param_1 + 0x1a0) = uVar1;
        *(undefined4 *)(param_1 + 0x19c) = 0;
        return 0;
      }
      uVar6 = uVar6 + 1;
      puVar7 = (undefined8 *)(*(long *)(param_1 + 400) + uVar5 * 0x38);
      *puVar4 = *puVar7;
      puVar4[1] = puVar7[1];
      puVar4[2] = puVar7[2];
      puVar4[3] = puVar7[3];
      puVar4[4] = puVar7[4];
      puVar4[5] = puVar7[5];
      puVar4[6] = puVar7[6];
      uVar5 = (ulong)(*(int *)(param_1 + 0x19c) + 1) % (ulong)*(uint *)(param_1 + 0x1a0);
      *(int *)(param_1 + 0x19c) = (int)uVar5;
      puVar4 = puVar4 + 7;
    } while (uVar6 < *param_2);
    nvAssertFailedNoLog("newQueuePut < pParams->maxQueueSize","src/kernel/gpu/mem_mgr/mem_mapper.c",
                        0x281);
    uVar3 = 0x40;
  }
  return uVar3;
}


// ===== 003b8be0 _memmgrFreeInternalClientObjects =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _memmgrFreeInternalClientObjects(long param_1)

{
  long lVar1;
  
  lVar1 = rmapiGetInterface(4);
  if (*(int *)(param_1 + 0xd2c) != 0) {
    (**(code **)(lVar1 + 0x18))(lVar1,*(undefined4 *)(param_1 + 0xd10));
    *(undefined4 *)(param_1 + 0xd2c) = 0;
  }
  if (*(int *)(param_1 + 0xd10) == 0) {
    return;
  }
  rmapiutilFreeClientAndDeviceHandles(lVar1,param_1 + 0xd10,param_1 + 0xd14,param_1 + 0xd18);
  return;
}


// ===== 003b8c60 memmgrSuspendResumeCallback =====

void memmgrSuspendResumeCallback(void)

{
  char cVar1;
  long *plVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 local_60 [56];
  long local_28;
  
  plVar2 = (long *)serverutilGetFirstClientUnderLock();
  cVar1 = rmapiLockIsOwner();
  if ((cVar1 == '\0') && (cVar1 = rmapiInRtd3PmPath(), cVar1 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() || rmapiInRtd3PmPath()",
                        "src/kernel/gpu/mem_mgr/mem_mgr.c",0x228);
    return;
  }
  for (; plVar2 != (long *)0x0; plVar2 = (long *)serverutilGetNextClientUnderLock(plVar2)) {
    uVar4 = 0;
    if (*plVar2 != 0) {
      uVar4 = *(undefined8 *)(*plVar2 + 0x100);
    }
    clientRefIter(local_60,uVar4,0,0xb8e4a2,1,1);
    while (cVar1 = clientRefIterNext(uVar4,local_60), cVar1 != '\0') {
      uVar3 = __nvoc_dynamicCast(*(undefined8 *)(local_28 + 8),__nvoc_class_def_MemoryMapper);
      memmapperQueueWork_IMPL(uVar3);
    }
  }
  return;
}


// ===== 003b8d40 _memmgrPmaStatsUpdateCb =====

void _memmgrPmaStatsUpdateCb(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  uint local_2c;
  
  lVar1 = *(long *)(&DAT_00001b90 + param_1);
  lVar5 = gpushareddataWriteStart_INTERNAL(param_1,0x10);
  *(long *)(lVar5 + 0x20) = param_2 * 0x10000;
  gpushareddataWriteFinish_INTERNAL(param_1,0x10);
  if (((lVar1 != 0) && (cVar3 = kbusIsStaticBar1Enabled_IMPL(param_1,lVar1), cVar3 != '\0')) &&
     (*(char *)(lVar1 + 0xad45) == '\0')) {
    iVar4 = vgpuGetCallingContextGfid(param_1,&local_2c);
    if (iVar4 == 0) {
      if ((*(long *)(param_1 + 0x1bc0) != 0) &&
         (cVar3 = kmigmgrIsMIGEnabled_IMPL(param_1), cVar3 != '\0')) {
        return;
      }
      lVar2 = *(long *)(lVar1 + 0x638 + (ulong)local_2c * 0x100);
      lVar1 = *(long *)(lVar1 + 0x708 + (ulong)local_2c * 0x100);
      lVar5 = *(long *)(lVar5 + 0x18);
      lVar6 = gpushareddataWriteStart_INTERNAL(param_1,0);
      *(int *)(lVar6 + 0xc) = (int)((ulong)((param_2 * 0x10000 + lVar2 + lVar1) - lVar5) >> 10);
      gpushareddataWriteFinish_INTERNAL(param_1,0);
    }
    else {
      nvAssertOkFailedNoLog
                (iVar4,"vgpuGetCallingContextGfid(pGpu, &gfid)","src/kernel/gpu/mem_mgr/mem_mgr.c",
                 0xc97);
    }
  }
  return;
}


// ===== 003b8e30 memmgrConstructEngine_IMPL =====

int memmgrConstructEngine_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  int local_30;
  undefined4 uStack_2c;
  
  lVar3 = 0;
  *(undefined8 *)(param_2 + 0xb90) = 0;
  *(undefined8 *)(param_2 + 0xb98) = 0xffffffffffffffff;
  *(undefined8 *)(param_2 + 0x848) = 0xffffffffffffffff;
  *(undefined8 *)(param_2 + 0x458) = 0xffffffffffffffff;
  do {
    iVar1 = __nvoc_objCreate_OBJFBSR(&local_30,param_2,0);
    if (iVar1 != 0) {
      return iVar1;
    }
    lVar4 = CONCAT44(uStack_2c,local_30);
    uVar2 = (undefined4)lVar3;
    if (lVar4 == 0) {
      nvAssertFailedNoLog("pFbsr","src/kernel/gpu/mem_mgr/mem_mgr.c",0x4ae);
      lVar4 = CONCAT44(uStack_2c,local_30);
    }
    *(long *)(param_2 + 0xbb0 + lVar3 * 8) = lVar4;
    lVar3 = lVar3 + 1;
    fbsrObjectInit_IMPL(lVar4,uVar2);
  } while (lVar3 != 8);
  *(undefined8 *)(param_2 + 0xc58) = 0;
  *(undefined4 *)(param_2 + 0xc60) = 0;
  *(undefined8 *)(param_2 + 0xc38) = 1;
  *(undefined8 *)(param_2 + 0xc40) = 0;
  iVar1 = osReadRegistryDword(param_1,"RmEnableLargePageSizeSysmemDefault",&local_30);
  if (iVar1 == 0) {
    *(bool *)(param_2 + 0x483) = local_30 == 1;
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xa4,"_memmgrInitRegistryOverridesAtConstruct",2
                 ,"NVRM: Large page sysmem default override to 0x%x via regkey.\n",local_30 == 1);
  }
  iVar1 = osReadRegistryDword(param_1,"RmForceEnableFlaSysmem",&local_30);
  if ((iVar1 == 0) && (local_30 == 1)) {
    *(undefined1 *)(param_2 + 0x470) = 1;
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xaf,"_memmgrInitRegistryOverridesAtConstruct",2
                 ,"NVRM: Enabled FLA+sysmem via regkey.\n");
  }
  return 0;
}


// ===== 003b8fe0 memmgrDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void memmgrDestruct_IMPL(long param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  long lVar4;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x150);
  }
  uVar1 = gpuEngineGetGpu(uVar1);
  (**(code **)(param_1 + 0x3f0))(uVar1,param_1);
  puVar2 = (undefined8 *)(param_1 + 0xbb0);
  do {
    puVar3 = puVar2 + 1;
    __nvoc_objDelete(*puVar2);
    *puVar2 = 0;
    puVar2 = puVar3;
  } while (puVar3 != (undefined8 *)(param_1 + 0xbf0));
  lVar4 = *(long *)(param_1 + 0x478);
  if ((lVar4 != 0) && (*(long *)(lVar4 + 0x128) != 0)) {
    pmaDestroy(*(long *)(lVar4 + 0x128));
    lVar4 = *(long *)(param_1 + 0x478);
  }
  __nvoc_objDelete(lVar4);
  *(undefined8 *)(param_1 + 0x478) = 0;
  *(undefined8 *)(param_1 + 0xc38) = 1;
  *(undefined8 *)(param_1 + 0xc40) = 0;
  return;
}


// ===== 003b90b0 memmgrStatePreInitLocked_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong memmgrStatePreInitLocked_IMPL(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  
  lVar1 = *(long *)(param_1 + 0x1b70);
  if ((((*(char *)(param_1 + 0x909) == '\0') || (*(char *)(param_1 + 0x90a) != '\0')) &&
      (*(char *)(param_1 + 0x908) == '\0')) ||
     (uVar2 = (**(code **)(param_2 + 0x180))(param_1,param_2), uVar2 == 0)) {
    uVar3 = (**(code **)(param_2 + 0x350))(param_1,param_2);
    if ((int)uVar3 == 0) {
      if ((lVar1 != 0) && (*(char *)(*(long *)(lVar1 + 0x2b0) + 3) != '\0')) {
        *(undefined1 *)(param_2 + 0xd34) = 0;
      }
    }
    else {
      nvAssertOkFailedNoLog
                (uVar3 & 0xffffffff,"memmgrPreInitReservedMemory_HAL(pGpu, pMemoryManager)",
                 "src/kernel/gpu/mem_mgr/mem_mgr.c",0x171);
      uVar3 = uVar3 & 0xffffffff;
    }
  }
  else {
    nvAssertOkFailedNoLog
              (uVar2,"memmgrInitFbRegions(pGpu, pMemoryManager)","src/kernel/gpu/mem_mgr/mem_mgr.c",
               0x16d);
    uVar3 = (ulong)uVar2;
  }
  return uVar3;
}


// ===== 003b9190 memmgrDestroyInternalChannels_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong memmgrDestroyInternalChannels_IMPL(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  ulong uVar2;
  
  nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x1ff,"memmgrDestroyInternalChannels_IMPL",1,
               "NVRM: Destroying global CeUtils instance\n");
  uVar1 = *(undefined8 *)(param_2 + 0x4a0);
  *(undefined8 *)(param_2 + 0x4a0) = 0;
  __nvoc_objDelete(uVar1);
  uVar2 = (**(code **)(param_2 + 0x198))(param_1,param_2);
  if ((int)uVar2 == 0) {
    return uVar2;
  }
  nvAssertOkFailedNoLog
            (uVar2 & 0xffffffff,"memmgrScrubHandlePreSchedulingDisable_HAL(pGpu, pMemoryManager)",
             "src/kernel/gpu/mem_mgr/mem_mgr.c",0x203);
  return uVar2 & 0xffffffff;
}


// ===== 003b9240 memmgrPreSchedulingDisableHandler =====

void memmgrPreSchedulingDisableHandler(long param_1)

{
  memmgrDestroyInternalChannels_IMPL(param_1,*(undefined8 *)(param_1 + 0x1b78));
  return;
}


// ===== 003b9250 memmgrVerifyGspDmaOps_IMPL =====

int memmgrVerifyGspDmaOps_IMPL(long param_1,undefined8 param_2)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  int local_54;
  long local_50;
  long local_48 [5];
  
  iVar1 = 0;
  local_50 = 0;
  local_54 = -0x21524111;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  if (*(char *)(*(long *)(&DAT_00001b90 + param_1) + 0xad0c) != '\0') {
    piVar2 = (int *)portMemAllocNonPaged(0x1000);
    if (piVar2 != (int *)0x0) {
      portMemSet(piVar2,0,0x1000);
      uVar3 = 1;
      iVar1 = memdescCreate(&local_50,param_1,0x1000,0x1000,1,2);
      if (iVar1 == 0) {
        *(undefined4 *)(local_50 + 0x9c) = 0x35;
        iVar1 = memdescAlloc(local_50,0);
        if (iVar1 == 0) {
          local_48[1] = 4;
          local_48[0] = local_50;
          iVar1 = memmgrMemWrite_IMPL(param_2,local_48,&local_54,4,0);
          if (iVar1 == 0) {
            iVar1 = memmgrMemRead_IMPL(param_2,local_48,piVar2,4,0);
            if (iVar1 == 0) {
              if (*piVar2 == local_54) {
                nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x33a,"memmgrVerifyGspDmaOps_IMPL",1
                             ,"NVRM: ####################################################\n");
                nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x33b,"memmgrVerifyGspDmaOps_IMPL",1
                             ,"NVRM:     Read back of data using GSP confirms write\n");
                nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x33c,"memmgrVerifyGspDmaOps_IMPL",1
                             ,"NVRM: ####################################################\n");
              }
              else {
                iVar1 = 0x40;
                nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x331,"memmgrVerifyGspDmaOps_IMPL",4
                             ,"NVRM: ####################################################\n");
                nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x332,"memmgrVerifyGspDmaOps_IMPL",4
                             ,"NVRM:     Read back of data using GSP shows mismatch\n");
                nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x333,"memmgrVerifyGspDmaOps_IMPL",4
                             ,"NVRM:     Test data: 0x%x Read Data: 0x%x\n",local_54,*piVar2);
                nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x334,"memmgrVerifyGspDmaOps_IMPL",4
                             ,"NVRM: ####################################################\n");
                nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/mem_mgr.c",0x336);
              }
            }
            else {
              nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/mem_mgr.c",0x32d);
            }
          }
          else {
            nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/mem_mgr.c",0x328);
          }
        }
        else {
          nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/mem_mgr.c",800);
        }
      }
      else {
        nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/mem_mgr.c",0x31c,uVar3);
      }
      memdescFree(local_50);
      memdescDestroy(local_50);
      portMemFree(piVar2);
      return iVar1;
    }
    iVar1 = 0x1a;
    nvAssertFailedNoLog("pTestBuffer != NULL","src/kernel/gpu/mem_mgr/mem_mgr.c",0x316);
  }
  return iVar1;
}


// ===== 003b95b0 memmgrStateLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 memmgrStateLoad_IMPL(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x210))();
  memmgrDumpFbRegions_IMPL(param_1,param_2);
  return 0;
}


// ===== 003b95f0 memmgrStatePreUnload_IMPL =====

undefined8 memmgrStatePreUnload_IMPL(long param_1,long param_2,uint param_3)

{
  long lVar1;
  undefined8 uVar2;
  char cVar3;
  int *piVar4;
  
  lVar1 = *(long *)(param_1 + 0x1b70);
  if ((param_3 & 1) == 0) {
    piVar4 = (int *)(param_2 + 0xb6c);
    do {
      if (*piVar4 != 0) {
        nvAssertFailedNoLog("(flags & GPU_STATE_FLAGS_PRESERVING) || !_memmgrIsZbcSurfaceReferenced(pGpu, pMemoryManager)"
                            ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x37e);
        break;
      }
      piVar4 = piVar4 + 1;
    } while (piVar4 != (int *)(param_2 + 0xb8c));
  }
  else {
    uVar2 = *(undefined8 *)(param_2 + 0x4a0);
    *(undefined8 *)(param_2 + 0x4a0) = 0;
    __nvoc_objDelete(uVar2);
  }
  if ((*(char *)(param_2 + 0x433) != '\0') && (*(char *)(param_2 + 0x432) != '\0')) {
    cVar3 = osNumaOnliningEnabled(*(undefined8 *)(param_1 + 0x4e0));
    if ((cVar3 != '\0') && (**(char **)(lVar1 + 0x2b8) != '\0')) {
      pmaNumaOfflined(*(undefined8 *)(*(long *)(param_2 + 0x478) + 0x128));
    }
  }
  return 0;
}


// ===== 003b96d0 memmgrStateUnload_IMPL =====

undefined8 memmgrStateUnload_IMPL(void)

{
  return 0;
}


// ===== 003b96e0 memmgrStateDestroy_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void memmgrStateDestroy_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  long *plVar3;
  
  lVar1 = *(long *)(param_2 + 0x478);
  _memmgrFreeInternalClientObjects(param_2);
  gpuDestroyRusdMemory_IMPL(param_1);
  if ((*(char *)(param_2 + 0x434) != '\0') && (*(char *)(param_2 + 0x436) != '\0')) {
    rmMemPoolDestroy(*(undefined8 *)(param_2 + 0xc30));
    *(undefined8 *)(param_2 + 0xc30) = 0;
  }
  if (lVar1 != 0) {
    if (*(long *)(lVar1 + 0x128) != 0) {
      pmaDestroy();
    }
    __nvoc_objDelete(lVar1);
    *(undefined8 *)(param_2 + 0x478) = 0;
  }
  memdescDestroy(*(undefined8 *)(param_2 + 0xb60));
  *(undefined8 *)(param_2 + 0xb60) = 0;
  if (*(long *)(param_2 + 0xc00) != 0) {
    memdescDestroy();
  }
  if (*(long *)(param_2 + 0xc08) != 0) {
    memdescDestroy();
  }
  if (*(long *)(param_2 + 0xc10) != 0) {
    memdescDestroy();
  }
  if (*(long *)(param_2 + 0xc18) != 0) {
    memdescDestroy();
  }
  *(undefined8 *)(param_2 + 0xc00) = 0;
  plVar3 = (long *)(param_2 + 0xbb0);
  *(undefined8 *)(param_2 + 0xc08) = 0;
  *(undefined8 *)(param_2 + 0xc10) = 0;
  *(undefined8 *)(param_2 + 0xc18) = 0;
  do {
    lVar1 = *plVar3;
    plVar3 = plVar3 + 1;
    (**(code **)(lVar1 + 0x50))(param_1);
  } while (plVar3 != (long *)(param_2 + 0xbf0));
  if (*(char *)(param_2 + 0x454) != '\0') {
    if (*(char *)(param_1 + 0x4913) == '\0') {
      (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x2f8))
                (param_1,*(long *)(&DAT_00001b90 + param_1),
                 1 << ((byte)*(undefined4 *)(param_2 + 0x458) & 0x1f));
    }
    *(undefined4 *)(param_2 + 0x458) = 0xffffffff;
    *(undefined1 *)(param_2 + 0x454) = 0;
  }
  lVar1 = gpuGetKernelFifoShared_IMPL(param_1);
  if (lVar1 != 0) {
    uVar2 = gpuGetKernelFifoShared_IMPL(param_1);
    kfifoRemoveSchedulingHandler_IMPL
              (param_1,uVar2,memmgrPostSchedulingEnableHandler,0,memmgrPreSchedulingDisableHandler,0
              );
    return;
  }
  return;
}


// ===== 003b98e0 memmgrGetDeviceSuballocator_IMPL =====

undefined8 memmgrGetDeviceSuballocator_IMPL(long param_1,char param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_2 == '\0') {
    uVar1 = *(undefined8 *)(param_1 + 0x478);
  }
  return uVar1;
}


// ===== 003b9900 memmgrGetUsedRamSize_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 memmgrGetUsedRamSize_IMPL(long param_1,long param_2,long *param_3)

{
  long lVar1;
  int iVar2;
  long local_48;
  long local_40;
  long local_38;
  long local_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x1b78) + 0x478);
  heapGetFree_IMPL(lVar1,&local_48);
  heapGetSize_IMPL(lVar1,&local_40);
  if (*(char *)(param_2 + 0x434) == '\0') {
    local_40 = local_40 - local_48;
  }
  else {
    pmaGetFreeMemory(*(undefined8 *)(lVar1 + 0x128),&local_38);
    local_40 = local_40 - (local_38 + local_48);
  }
  *param_3 = local_40;
  if (*(char *)(param_1 + 0x909) != '\0') {
    local_30 = 0;
    lVar1 = *(long *)(*(long *)(param_1 + 0x1ba8) + 0xa78);
    *param_3 = (((*(long *)(lVar1 + 0x68) + *(long *)(lVar1 + 0x60)) - *(long *)(lVar1 + 0x98)) -
               *(long *)(lVar1 + 0xa0)) + local_40;
    iVar2 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800aeb,&local_30,8);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x553,"memmgrGetUsedRamSize_IMPL",4,
                   "NVRM: Failed to get free heap size of GSP-RM\n");
      return 0;
    }
    *param_3 = *param_3 - local_30;
  }
  return 0;
}


// ===== 003b9a50 memmgrCheckZeroPmaUsage_IMPL =====

undefined8 memmgrCheckZeroPmaUsage_IMPL(long param_1,long param_2)

{
  long lVar1;
  long local_18;
  long local_10;
  
  if (*(char *)(param_2 + 0x434) == '\0') {
    return 0;
  }
  lVar1 = *(long *)(*(long *)(param_1 + 0x1b78) + 0x478);
  pmaGetFreeMemory(*(undefined8 *)(lVar1 + 0x128),&local_18);
  pmaGetTotalMemory(*(undefined8 *)(lVar1 + 0x128),&local_10);
  if (local_18 == local_10) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x571,"memmgrCheckZeroPmaUsage_IMPL",4,
               "NVRM: PMA usage is non-zero, freeMem = 0x%llx bytes totalMem  = 0x%llx bytes\n",
               local_18,local_10);
  return 0x40;
}


// ===== 003b9af0 memmgrAllocHwResources_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 memmgrAllocHwResources_IMPL(long param_1,undefined8 param_2,long param_3)

{
  uint *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  long lVar7;
  long lVar8;
  uint uVar9;
  ulong uVar10;
  
  uVar2 = *(uint *)(*(long *)(param_3 + 0x90) + 8);
  lVar7 = portMemAllocNonPaged(0xc0);
  if (lVar7 == 0) {
    uVar6 = 0x51;
    nvAssertFailedNoLog(&DAT_00d4ed06,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x58a);
  }
  else {
    if (*(char *)(param_1 + 0x908) != '\0') {
      lVar8 = gpuGetStaticInfo(param_1);
      if ((lVar8 == 0) || (*(char *)(lVar8 + 0x1f100) == '\0')) {
        puVar1 = (uint *)(*(long *)(param_3 + 0x90) + 8);
        *puVar1 = *puVar1 | 0x10000000;
      }
    }
    uVar10 = 0;
    do {
      uVar9 = (int)uVar10 + 0x20;
      uVar3 = *(undefined8 *)(param_3 + 8 + uVar10);
      uVar4 = *(undefined8 *)(param_3 + 0x10 + uVar10);
      uVar5 = *(undefined8 *)(param_3 + 0x18 + uVar10);
      *(undefined8 *)(lVar7 + uVar10) = *(undefined8 *)(param_3 + uVar10);
      *(undefined8 *)(lVar7 + 8 + uVar10) = uVar3;
      *(undefined8 *)(lVar7 + 0x10 + uVar10) = uVar4;
      *(undefined8 *)(lVar7 + 0x18 + uVar10) = uVar5;
      uVar10 = (ulong)uVar9;
    } while (uVar9 < 0xc0);
    uVar6 = (**(code **)(*(long *)(param_1 + 0x1b78) + 0x1d0))(param_1);
    uVar10 = 0;
    do {
      uVar9 = (int)uVar10 + 0x20;
      uVar3 = *(undefined8 *)(lVar7 + 8 + uVar10);
      uVar4 = *(undefined8 *)(lVar7 + 0x10 + uVar10);
      uVar5 = *(undefined8 *)(lVar7 + 0x18 + uVar10);
      *(undefined8 *)(param_3 + uVar10) = *(undefined8 *)(lVar7 + uVar10);
      *(undefined8 *)(param_3 + 8 + uVar10) = uVar3;
      *(undefined8 *)(param_3 + 0x10 + uVar10) = uVar4;
      *(undefined8 *)(param_3 + 0x18 + uVar10) = uVar5;
      uVar10 = (ulong)uVar9;
    } while (uVar9 < 0xc0);
    portMemFree(lVar7);
    puVar1 = (uint *)(*(long *)(param_3 + 0x90) + 8);
    *puVar1 = *puVar1 & 0xefffffff;
    puVar1 = (uint *)(*(long *)(param_3 + 0x90) + 8);
    *puVar1 = *puVar1 | uVar2 & 0x10000000;
  }
  return uVar6;
}


// ===== 003b9c60 memmgrFreeHwResources_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 memmgrFreeHwResources_IMPL(long param_1,undefined8 param_2,long param_3)

{
  uint *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  long lVar6;
  long lVar7;
  uint uVar8;
  ulong uVar9;
  undefined1 local_40 [32];
  
  lVar6 = portMemAllocNonPaged(0xc0);
  if (lVar6 != 0) {
    timeoutSet(param_1 + 0x1af0,local_40,0,0);
    if (*(char *)(param_1 + 0x908) != '\0') {
      lVar7 = gpuGetStaticInfo(param_1);
      if ((lVar7 == 0) || (*(char *)(lVar7 + 0x1f100) == '\0')) {
        puVar1 = (uint *)(*(long *)(param_3 + 0x90) + 8);
        *puVar1 = *puVar1 | 0x10000000;
      }
    }
    lVar7 = *(long *)(param_1 + 0x1b78);
    uVar9 = 0;
    do {
      uVar8 = (int)uVar9 + 0x20;
      uVar2 = *(undefined8 *)(param_3 + 8 + uVar9);
      uVar3 = *(undefined8 *)(param_3 + 0x10 + uVar9);
      uVar4 = *(undefined8 *)(param_3 + 0x18 + uVar9);
      *(undefined8 *)(lVar6 + uVar9) = *(undefined8 *)(param_3 + uVar9);
      *(undefined8 *)(lVar6 + 8 + uVar9) = uVar2;
      *(undefined8 *)(lVar6 + 0x10 + uVar9) = uVar3;
      *(undefined8 *)(lVar6 + 0x18 + uVar9) = uVar4;
      uVar9 = (ulong)uVar8;
    } while (uVar8 < 0xc0);
    uVar5 = (**(code **)(lVar7 + 0x1d8))(param_1,lVar7,lVar6,local_40);
    uVar9 = 0;
    do {
      uVar8 = (int)uVar9 + 0x20;
      uVar2 = *(undefined8 *)(lVar6 + 8 + uVar9);
      uVar3 = *(undefined8 *)(lVar6 + 0x10 + uVar9);
      uVar4 = *(undefined8 *)(lVar6 + 0x18 + uVar9);
      *(undefined8 *)(param_3 + uVar9) = *(undefined8 *)(lVar6 + uVar9);
      *(undefined8 *)(param_3 + 8 + uVar9) = uVar2;
      *(undefined8 *)(param_3 + 0x10 + uVar9) = uVar3;
      *(undefined8 *)(param_3 + 0x18 + uVar9) = uVar4;
      uVar9 = (ulong)uVar8;
    } while (uVar8 < 0xc0);
    portMemFree(lVar6);
    return uVar5;
  }
  nvAssertFailedNoLog(&DAT_00d4ed06,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x5c1);
  return 0x51;
}


// ===== 003b9dc0 memmgrComprSupported_IMPL =====

undefined1 memmgrComprSupported_IMPL(long param_1,uint param_2)

{
  long lVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  char *pcVar4;
  
  uVar3 = 0;
  if (param_1 != 0) {
    uVar3 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar1 = gpuEngineGetGpu(uVar3);
  if (*(long *)(lVar1 + 0x1b98) != 0) {
    if (param_2 < 3) {
      if (param_2 != 0) {
        if (param_2 == 2) {
          return 1;
        }
        if ((*(char *)(lVar1 + 0x491c) == '\0') || (*(char *)(param_1 + 0x43f) == '\0')) {
          uVar2 = 0;
          pcVar4 = "NV_FALSE";
        }
        else {
          uVar2 = 1;
          pcVar4 = "NV_TRUE";
        }
        nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x619,"memmgrComprSupported_IMPL",1,
                     "NVRM: isSupported=%s\n",pcVar4);
        return uVar2;
      }
    }
    else if (param_2 == 4) {
      return 1;
    }
    nvAssertFailedNoLog(&DAT_00d4ed06,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x5fb);
    if (*(char *)(param_1 + 0x43e) != '\0') {
      nvAssertFailedNoLog(&DAT_00d4ed06,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x61e);
    }
  }
  return 0;
}


// ===== 003b9ee0 memmgrAllocGetAddrSpace_IMPL =====

char memmgrAllocGetAddrSpace_IMPL(undefined8 param_1,ulong param_2,uint param_3)

{
  char cVar1;
  
  cVar1 = '\x04';
  if (((param_2 & 0x80000) == 0) && (cVar1 = '\x02', (param_3 & 0x6000000) != 0)) {
    cVar1 = ((param_2 & 0x1000000) != 0) + '\x01';
  }
  return cVar1;
}


// ===== 003b9f10 memmgrGetMappableRamSizeMb_IMPL =====

undefined8 memmgrGetMappableRamSizeMb_IMPL(long param_1)

{
  return *(undefined8 *)(param_1 + 0x840);
}


// ===== 003b9f20 memmgrDeterminePageSize_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong memmgrDeterminePageSize_IMPL
                (long param_1,int param_2,ulong param_3,int param_4,ulong param_5,uint *param_6,
                uint *param_7)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  undefined8 uVar6;
  char cVar7;
  
  uVar6 = 0;
  if (param_1 != 0) {
    uVar6 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar3 = gpuEngineGetGpu(uVar6);
  lVar1 = *(long *)(lVar3 + 0x1b98);
  if ((*(char *)(lVar3 + 0x45a) != '\0') || (lVar1 == 0)) goto LAB_003ba080;
  if ((param_6 == (uint *)0x0) || (param_7 == (uint *)0x0)) {
    nvAssertFailedNoLog(&DAT_00d4ed06,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x70f);
    return 0;
  }
  cVar7 = '\x04';
  if (((param_5 & 0x80000) == 0) && (cVar7 = '\x02', (*param_6 & 0x6000000) != 0)) {
    cVar7 = ((param_5 & 0x1000000) != 0) + '\x01';
  }
  uVar2 = dmaNvos32ToPageSizeAttr(*param_6,*param_7);
  if (*(char *)(lVar3 + 0x4921) != '\0') goto LAB_003ba080;
  if (uVar2 == 3) {
    if (*(char *)(lVar1 + 0x67d0) == '\0') {
      return 0;
    }
    goto LAB_003ba16d;
  }
  if (uVar2 < 4) {
    if (uVar2 == 1) goto LAB_003ba080;
    if (uVar2 == 2) {
      uVar4 = (**(code **)(lVar1 + 0x198))(lVar1);
LAB_003ba04d:
      if (uVar4 != 0x200000) {
        if (uVar4 < 0x200001) {
          if ((uVar4 - 0x10000 & 0xfffffffffffeffff) == 0) {
            *param_6 = *param_6 & 0xfe7fffff | 0x1000000;
            return uVar4;
          }
          if (uVar4 != 0x1000) {
            return 0;
          }
LAB_003ba080:
          *param_6 = *param_6 & 0xfe7fffff | 0x800000;
          return 0x1000;
        }
        if (uVar4 == 0x20000000) {
LAB_003ba0fc:
          *param_6 = *param_6 | 0x1800000;
          *param_7 = *param_7 & 0xffcfffff | 0x200000;
          return 0x20000000;
        }
        if (uVar4 != 0x4000000000) {
          return 0;
        }
        goto LAB_003ba139;
      }
    }
    else {
      lVar1 = *(long *)(lVar3 + 0x1b98);
      uVar2 = *param_7;
      if (cVar7 == '\x01') {
        uVar4 = osGetSupportedSysmemPageSizeMask();
        if ((*(char *)(param_1 + 0x483) != '\0') && (param_2 != 0)) {
          if ((*(char *)(lVar1 + 0x67d0) != '\0') &&
             ((0x1fffff < param_3 && ((uVar4 & 0x200000) != 0)))) goto LAB_003ba16d;
          uVar5 = kgmmuGetMinBigPageSize_IMPL();
          if (((uVar5 <= param_3) && (uVar5 = (**(code **)(lVar1 + 0x198))(), (uVar4 & uVar5) != 0))
             || ((uVar2 & 0x300) == 0x200)) goto LAB_003ba041;
        }
        uVar4 = osGetPageSize();
        goto LAB_003ba04d;
      }
      if ((*(char *)(lVar1 + 0x67d0) == '\0') || (param_3 < 0x200000)) {
        if ((param_4 == 0) &&
           (((uVar4 = kgmmuGetMinBigPageSize_IMPL(), param_3 < uVar4 && (param_2 == 0)) &&
            ((uVar2 & 0x300) != 0x200)))) goto LAB_003ba080;
LAB_003ba041:
        uVar4 = (**(code **)(lVar1 + 0x198))();
        goto LAB_003ba04d;
      }
    }
LAB_003ba16d:
    *param_6 = *param_6 | 0x1800000;
    *param_7 = *param_7 & 0xffcfffff | 0x100000;
    uVar4 = 0x200000;
  }
  else {
    if (uVar2 != 5) {
      if (uVar2 == 6) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x746,"memmgrDeterminePageSize_IMPL",4,
                     "NVRM: invalid page size attr\n");
        return 0;
      }
      if (uVar2 != 4) {
        return 0;
      }
      if (*(char *)(lVar1 + 0x67d1) == '\0') {
        return 0;
      }
      goto LAB_003ba0fc;
    }
    if (*(char *)(lVar1 + 0x67d2) == '\0') {
      return 0;
    }
LAB_003ba139:
    *param_6 = *param_6 | 0x1800000;
    *param_7 = *param_7 | 0x300000;
    uVar4 = 0x4000000000;
  }
  return uVar4;
}


// ===== 003ba2f0 memmgrGetReservedConsoleMemDesc_IMPL =====

undefined8 memmgrGetReservedConsoleMemDesc_IMPL(undefined8 param_1,long param_2)

{
  return *(undefined8 *)(param_2 + 0xb60);
}


// ===== 003ba300 memmgrReserveBar2BackingStore_IMPL =====

uint memmgrReserveBar2BackingStore_IMPL(long param_1,undefined8 param_2,ulong *param_3)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  ulong uVar5;
  
  lVar1 = *(long *)(&DAT_00001b90 + param_1);
  uVar4 = *param_3;
  uVar2 = kbusGetSizeOfBar2PageDirs_GM107(param_1,lVar1);
  uVar3 = kbusGetSizeOfBar2PageTables_GM107(param_1,lVar1);
  if (*(int *)(lVar1 + 0xad34) == 2) {
    uVar5 = uVar4 + 0xfff & 0xfffffffffffff000;
    *(ulong *)(lVar1 + 0x4658) = uVar5;
    uVar4 = uVar2 + uVar5;
  }
  else {
    uVar5 = *(ulong *)(lVar1 + 0x4658);
  }
  if (*(int *)(lVar1 + 0xad2c) == 2) {
    uVar4 = uVar4 + 0xfff & 0xfffffffffffff000;
    *(ulong *)(lVar1 + 0x4668) = uVar4;
    uVar4 = uVar4 + uVar3;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x815,"memmgrReserveBar2BackingStore_IMPL",1,
               "NVRM: Reserve space for bar2 Page dirs offset = 0x%llx size = 0x%x\n",uVar5,uVar2);
  nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x818,"memmgrReserveBar2BackingStore_IMPL",1,
               "NVRM: Reserve space for bar2 Page tables offset = 0x%llx size = 0x%x\n",
               *(undefined8 *)(lVar1 + 0x4668));
  *param_3 = uVar4 + 0xfff & 0xfffffffffffff000;
  return uVar3;
}


// ===== 003ba430 memmgrCalcReservedFbSpace_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void memmgrCalcReservedFbSpace_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  ulong uVar6;
  char cVar7;
  char cVar8;
  long *plVar9;
  uint uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  long local_50;
  long local_48;
  long local_40;
  
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  cVar8 = gpuIsCCFeatureEnabled_IMPL();
  if (*(long *)(param_2 + 0x828) != 0) {
    (**(code **)(param_2 + 800))(param_1,param_2,&local_50,&local_48);
    if (*(uint *)(param_2 + 0x858) == 0) {
      return;
    }
    plVar9 = (long *)(param_2 + 0x860);
    bVar4 = false;
    uVar11 = 0;
    uVar16 = 0;
    bVar5 = false;
    uVar12 = 0;
    uVar14 = 0;
    do {
      uVar13 = uVar12;
      uVar15 = uVar14;
      if (((char)plVar9[3] == '\0') &&
         (((cVar8 != '\0' || (*(char *)((long)plVar9 + 0x22) == '\0')) &&
          ((ulong)(local_48 + local_50 + local_40) <= (ulong)((plVar9[1] + 1) - *plVar9))))) {
        uVar13 = uVar11;
        uVar15 = uVar11;
        if (bVar4) {
          uVar10 = *(uint *)((long)plVar9 + 0x1c);
          lVar1 = param_2 + uVar12 * 0x28;
          uVar3 = *(uint *)(lVar1 + 0x87c);
          lVar2 = param_2 + uVar14 * 0x28;
          if ((*(uint *)(lVar2 + 0x87c) < uVar10) || (*(char *)(lVar2 + 0x878) != '\0')) {
            if ((uVar3 <= uVar10) &&
               (uVar6 = uVar12, cVar7 = cVar8, *(char *)(param_2 + 0x878 + uVar12 * 0x28) == '\0'))
            goto joined_r0x003ba777;
          }
          else if (cVar8 == '\0') {
            uVar6 = uVar11;
            if (*(char *)(lVar2 + 0x882) == '\0') {
              uVar15 = uVar14;
              if (uVar3 <= uVar10) {
                cVar7 = *(char *)(lVar1 + 0x878);
joined_r0x003ba777:
                uVar13 = uVar6;
                if ((cVar7 == '\0') &&
                   (uVar13 = uVar12, *(char *)(param_2 + 0x882 + uVar12 * 0x28) != '\0')) {
                  uVar13 = uVar11;
                }
              }
            }
            else if (uVar3 <= uVar10) {
              cVar7 = *(char *)(lVar1 + 0x878);
              goto joined_r0x003ba777;
            }
          }
          else {
            uVar15 = uVar14;
            if ((uVar3 <= uVar10) && (uVar13 = uVar12, *(char *)(lVar1 + 0x878) != '\0')) {
              uVar13 = uVar11;
            }
          }
        }
        bVar4 = true;
        if (*(char *)((long)plVar9 + 0x21) != '\0') {
          if (((bVar5) && (*(char *)(param_2 + 0x881 + uVar16 * 0x28) != '\0')) &&
             (*(uint *)((long)plVar9 + 0x1c) <= *(uint *)(param_2 + 0x87c + uVar16 * 0x28))) {
            if (cVar8 == '\0') {
              bVar4 = true;
              if (*(char *)(param_2 + 0x882 + uVar16 * 0x28) != '\0') {
                uVar16 = uVar11;
                bVar4 = true;
                bVar5 = true;
              }
            }
            else {
              bVar4 = true;
            }
          }
          else {
            uVar16 = uVar11;
            bVar4 = true;
            bVar5 = true;
          }
        }
      }
      uVar10 = (int)uVar11 + 1;
      uVar11 = (ulong)uVar10;
      plVar9 = plVar9 + 5;
      uVar12 = uVar13;
      uVar14 = uVar15;
    } while (*(uint *)(param_2 + 0x858) != uVar10);
    if (!bVar5 || !bVar4) {
      nvAssertFailedNoLog("bFastAssigned && bSlowAssigned && bIsoAssigned",
                          "src/kernel/gpu/mem_mgr/mem_mgr.c",0x878);
    }
    if (*(char *)(param_2 + 0x881 + uVar16 * 0x28) == '\0') {
      nvAssertFailedNoLog("pMemoryManager->Ram.fbRegion[idxISORegion].bSupportISO",
                          "src/kernel/gpu/mem_mgr/mem_mgr.c",0x87b);
    }
    if (*(char *)(param_2 + 0x878 + uVar16 * 0x28) != '\0') {
      nvAssertFailedNoLog("!pMemoryManager->Ram.fbRegion[idxISORegion].bRsvdRegion",
                          "src/kernel/gpu/mem_mgr/mem_mgr.c",0x87e);
    }
    if (*(char *)(param_2 + 0x878 + uVar15 * 0x28) != '\0') {
      nvAssertFailedNoLog("!pMemoryManager->Ram.fbRegion[idxFastRegion].bRsvdRegion",
                          "src/kernel/gpu/mem_mgr/mem_mgr.c",0x87f);
    }
    if (*(char *)(param_2 + 0x878 + uVar13 * 0x28) != '\0') {
      nvAssertFailedNoLog("!pMemoryManager->Ram.fbRegion[idxSlowRegion].bRsvdRegion",
                          "src/kernel/gpu/mem_mgr/mem_mgr.c",0x880);
    }
    if (cVar8 == '\0') {
      if (*(char *)(param_2 + 0x882 + uVar16 * 0x28) != '\0') {
        nvAssertFailedNoLog("!pMemoryManager->Ram.fbRegion[idxISORegion].bProtected",
                            "src/kernel/gpu/mem_mgr/mem_mgr.c",0x889);
      }
      if (*(char *)(param_2 + 0x882 + uVar15 * 0x28) != '\0') {
        nvAssertFailedNoLog("!pMemoryManager->Ram.fbRegion[idxFastRegion].bProtected",
                            "src/kernel/gpu/mem_mgr/mem_mgr.c",0x88a);
      }
      if (*(char *)(param_2 + 0x882 + uVar13 * 0x28) != '\0') {
        nvAssertFailedNoLog("!pMemoryManager->Ram.fbRegion[idxSlowRegion].bProtected",
                            "src/kernel/gpu/mem_mgr/mem_mgr.c",0x88b);
      }
    }
    plVar9 = (long *)(param_2 + 0x870 + uVar16 * 0x28);
    *plVar9 = *plVar9 + local_40;
    plVar9 = (long *)(param_2 + 0x870 + uVar13 * 0x28);
    *plVar9 = *plVar9 + local_48;
    plVar9 = (long *)(param_2 + 0x870 + uVar15 * 0x28);
    *plVar9 = *plVar9 + local_50;
  }
  return;
}


// ===== 003ba970 memmgrFree_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong memmgrFree_IMPL(long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 param_6,int param_7,long *param_8)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  ulong uVar5;
  long lVar6;
  long *local_48;
  undefined8 local_40 [2];
  
  cVar1 = osIsRaisedIRQL();
  if (cVar1 != '\0') {
    nvAssertFailedNoLog("!osIsRaisedIRQL()","src/kernel/gpu/mem_mgr/mem_mgr.c",0x8c6);
    return 0x2d;
  }
  if ((param_8 == (long *)0x0) || (uVar4 = memdescGetPhysAddr(param_8,1,0), param_7 == -1)) {
    return 0x1f;
  }
  iVar2 = memdescGetAddressSpace(param_8);
  if (iVar2 == 4) {
    local_48 = (long *)0x0;
    uVar5 = serverGetClientUnderLock(g_resServ,param_4,local_40);
    if ((int)uVar5 != 0) {
      return uVar5;
    }
    uVar5 = vaspaceGetByHandleOrDeviceDefault_IMPL(local_40[0],param_5,param_6,&local_48);
    if ((int)uVar5 != 0) {
      return uVar5;
    }
    uVar3 = (**(code **)(*local_48 + 0x40))(local_48,uVar4);
    memdescDestroy(param_8);
    return (ulong)uVar3;
  }
  lVar6 = param_8[0x16];
  if (lVar6 == 0) {
    uVar5 = heapFree_IMPL(param_1,param_3,param_4,param_5,param_7,param_8);
    return uVar5;
  }
  if (*param_8 != param_1) {
    cVar1 = gpumgrIsGpuPointerValid();
    if (cVar1 == '\0') {
      nvAssertFailedNoLog(&DAT_00d4ed06,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x8fb);
      goto LAB_003baa44;
    }
    lVar6 = param_8[0x16];
    param_1 = *param_8;
  }
  vidmemPmaFree(param_1,param_3,lVar6,0);
  nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x90c,"memmgrFree_IMPL",1,
               "NVRM: Freeing PMA allocation\n");
LAB_003baa44:
  memdescDestroy(param_8);
  return 0;
}


// ===== 003bab50 memmgrFillComprInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
memmgrFillComprInfo_IMPL
          (long param_1,long param_2,long param_3,uint param_4,undefined4 param_5,ulong param_6,
          int param_7,undefined4 *param_8)

{
  undefined4 uVar1;
  char cVar2;
  long lVar3;
  byte bVar4;
  
  lVar3 = kmemsysGetStaticConfig_IMPL(param_1,*(undefined8 *)(param_1 + 0x1b70));
  portMemSet(param_8,0,0x1c);
  *param_8 = param_5;
  cVar2 = (**(code **)(param_2 + 0x2a8))(param_2,5,param_5);
  if (cVar2 != '\0') {
    if (param_7 == -1) {
      nvAssertFailedNoLog("compTagStartOffset != ~(NvU32)0","src/kernel/gpu/mem_mgr/mem_mgr.c",0xa01
                         );
    }
    uVar1 = *(undefined4 *)(lVar3 + 0x18);
    param_8[6] = 1;
    param_8[5] = param_7;
    bVar4 = (byte)uVar1;
    param_8[1] = uVar1;
    param_8[3] = (int)(param_6 >> (bVar4 & 0x3f));
    param_8[4] = (int)((ulong)param_4 * param_3 + -1 + param_6 >> (bVar4 & 0x3f));
  }
  return 0;
}


// ===== 003bac20 memmgrSetMIGPartitionableMemoryRange_IMPL =====

void memmgrSetMIGPartitionableMemoryRange_IMPL
               (undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  *(undefined8 *)(param_2 + 0xc38) = param_3;
  *(undefined8 *)(param_2 + 0xc40) = param_4;
  return;
}


// ===== 003bac40 memmgrGetMIGPartitionableMemoryRange_IMPL =====

undefined1  [16] memmgrGetMIGPartitionableMemoryRange_IMPL(undefined8 param_1,long param_2)

{
  return *(undefined1 (*) [16])(param_2 + 0xc38);
}


// ===== 003bac60 memmgrSetMIGPartitionableBAR1Range_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8 memmgrSetMIGPartitionableBAR1Range_IMPL(long param_1,long param_2)

{
  ulong uVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  ulong local_38;
  long local_30;
  
  plVar2 = (long *)(**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x4e8))();
  local_38 = 0;
  local_30 = 0;
  if (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) != '\0') {
    return 0;
  }
  if (plVar2 == (long *)0x0) {
    nvAssertFailedNoLog("pBar1VAS != NULL","src/kernel/gpu/mem_mgr/mem_mgr.c",0xa73);
  }
  else {
    lVar3 = (**(code **)(*plVar2 + 0x90))(plVar2);
    (**(code **)(lVar3 + 0x18))(lVar3,0,0,&local_38,&local_30,0,0);
    lVar3 = local_30;
    uVar1 = local_38;
    uVar4 = (**(code **)(*plVar2 + 0x58))(plVar2);
    if (uVar1 < uVar4) {
      nvAssertFailedNoLog("partitionableBar1Start >= vaspaceGetVaStart(pBar1VAS)",
                          "src/kernel/gpu/mem_mgr/mem_mgr.c",0xa7f,0x3bacd8);
    }
    else {
      uVar4 = (uVar1 - 1) + lVar3;
      uVar5 = (**(code **)(*plVar2 + 0x60))(plVar2);
      if (uVar4 <= uVar5) {
        *(ulong *)(param_2 + 0xc48) = uVar1;
        *(ulong *)(param_2 + 0xc50) = uVar4;
        return 0;
      }
      nvAssertFailedNoLog("partitionableBar1End <= vaspaceGetVaLimit(pBar1VAS)",
                          "src/kernel/gpu/mem_mgr/mem_mgr.c",0xa80);
    }
  }
  return 0x40;
}


// ===== 003badd0 memmgrSetPartitionableMem_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrSetPartitionableMem_IMPL(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long *plVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  long lVar9;
  uint uVar10;
  ulong uVar11;
  uint uVar12;
  uint uVar13;
  long lVar14;
  undefined1 local_8c [4];
  ulong local_88;
  long local_80;
  uint local_78;
  undefined4 uStack_74;
  undefined1 local_70 [8];
  long *local_68;
  ulong local_60;
  long local_58;
  long local_50;
  ulong local_48;
  ulong local_40;
  
  uVar1 = *(uint *)(param_2 + 0x858);
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  if (uVar1 == 0) {
    lVar14 = 0;
    lVar9 = 0;
  }
  else {
    plVar5 = (long *)(param_2 + 0x860);
    uVar10 = 0xffffffff;
    lVar9 = 0;
    uVar13 = 0xffff;
    lVar14 = 0;
    uVar12 = 0xffff;
    uVar6 = 0;
LAB_003bae5c:
    do {
      if ((*(char *)((long)plVar5 + 0x23) != '\0') || ((char)plVar5[3] != '\0')) {
        lVar2 = *plVar5;
        lVar8 = (plVar5[1] + 1) - lVar2;
        if (lVar2 == 0) {
          lVar9 = lVar9 + lVar8;
          uVar13 = uVar6;
        }
        else {
          if ((uVar6 == 0) ||
             (((uVar11 = (ulong)uVar10, *(char *)(param_2 + 0x883 + uVar11 * 0x28) == '\0' &&
               (*(char *)(param_2 + 0x878 + uVar11 * 0x28) == '\0')) ||
              (lVar2 != *(long *)(param_2 + 0x868 + uVar11 * 0x28) + 1)))) {
            if (uVar12 != 0xffff) {
              nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x959,"memmgrSetPartitionableMem_IMPL"
                           ,4,
                           "NVRM: More than two discontigous rsvd regions found. Rsvd region base - 0x%llx, Rsvd region Size - 0x%llx\n"
                           ,lVar2,lVar8);
              nvAssertFailedNoLog(&DAT_00d4ed06,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x95d);
              return 0x40;
            }
            uVar7 = uVar6 + 1;
            lVar14 = lVar14 + lVar8;
            plVar5 = plVar5 + 5;
            uVar10 = uVar10 + 1;
            uVar12 = uVar6;
            uVar6 = uVar7;
            if (uVar1 == uVar7) break;
            goto LAB_003bae5c;
          }
          if (uVar13 == uVar10) {
            lVar9 = lVar9 + lVar8;
          }
          else {
            lVar14 = lVar14 + lVar8;
          }
        }
      }
      uVar6 = uVar6 + 1;
      plVar5 = plVar5 + 5;
      uVar10 = uVar10 + 1;
    } while (uVar1 != uVar6);
  }
  lVar2 = *(long *)(*(long *)(param_1 + 0x1b78) + 0x478);
  if (*(char *)(param_2 + 0x434) == '\0') {
    iVar4 = heapInfo_IMPL(lVar2,local_70,&local_68,&local_80,&local_78,&local_88);
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog
                (iVar4,"heapInfo(pHeap, &freeMem, &bytesTotal, &base, &offset, &size)",
                 "src/kernel/gpu/mem_mgr/mem_mgr.c",0x971);
      return iVar4;
    }
    local_80 = CONCAT44(uStack_74,local_78);
    if (0x10000000 < local_88) {
      local_88 = local_88 - 0x10000000;
      goto joined_r0x003bb0f5;
    }
  }
  else {
    local_68 = (long *)0x0;
    local_78 = 8;
    iVar4 = pmaGetRegionInfo(*(undefined8 *)(lVar2 + 0x128),local_8c,&local_68);
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog
                (iVar4,"pmaGetRegionInfo(pHeap->pPmaObject, &numPmaRegions, &pFirstPmaRegionDesc)",
                 "src/kernel/gpu/mem_mgr/mem_mgr.c",0x98b);
      return iVar4;
    }
    local_80 = *local_68;
    pmaGetFreeMemory(*(undefined8 *)(lVar2 + 0x128),local_70);
    pmaGetTotalMemory(*(undefined8 *)(lVar2 + 0x128),&local_88);
    iVar4 = pmaQueryConfigs(*(undefined8 *)(lVar2 + 0x128),&local_78);
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog
                (iVar4,"pmaQueryConfigs(pHeap->pPmaObject, &pmaConfig)",
                 "src/kernel/gpu/mem_mgr/mem_mgr.c",0x992);
    }
    cVar3 = gpuIsCCorApmFeatureEnabled_IMPL(param_1);
    if (((cVar3 == '\0') ||
        ((*(long *)(param_1 + 0x1bc0) != 0 &&
         (cVar3 = kmigmgrIsMIGEnabled_IMPL(param_1), cVar3 != '\0')))) &&
       (((local_78 & 8) == 0 && (iVar4 = memmgrCheckZeroPmaUsage_IMPL(param_1,param_2), iVar4 != 0))
       )) {
      nvAssertOkFailedNoLog
                (0x40,"memmgrCheckZeroPmaUsage(pGpu, pMemoryManager)",
                 "src/kernel/gpu/mem_mgr/mem_mgr.c",0x9aa);
      return 0x40;
    }
  }
  if (local_88 == 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x9b0,"memmgrSetPartitionableMem_IMPL",4,
                 "NVRM: No partitionable memory. MIG memory partitioning can\'t be enabled.\n");
    return 0;
  }
joined_r0x003bb0f5:
  if (local_80 != lVar9) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x9b7,"memmgrSetPartitionableMem_IMPL",4,
                 "NVRM: Partitionable memory start - 0x%llx not aligned with RM reserved region base-end - 0x%llx\n"
                 ,local_80,lVar9);
    return 0x40;
  }
  local_60 = local_88;
  local_58 = lVar9;
  local_50 = lVar14;
  iVar4 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800a51,&local_60,0x28);
  if (iVar4 == 0) {
    *(ulong *)(param_2 + 0xc40) = local_40;
    *(ulong *)(param_2 + 0xc38) = local_48;
    if (local_40 < local_48) {
      nvAssertFailedNoLog("!rangeIsEmpty(pMemoryManager->MIGMemoryPartitioningInfo.partitionableMemoryRange)"
                          ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x9d2);
    }
    else {
      if (((*(long *)(&DAT_00001b90 + param_1) != 0) &&
          (*(char *)(*(long *)(&DAT_00001b90 + param_1) + 0xad45) != '\0')) ||
         (iVar4 = memmgrSetMIGPartitionableBAR1Range_IMPL(param_1,param_2), iVar4 == 0)) {
        if (*(char *)(param_1 + 0x909) != '\0') {
          (**(code **)(*(long *)(param_1 + 0x1b70) + 0x1e8))(param_1);
          return 0;
        }
        return 0;
      }
      nvAssertOkFailedNoLog
                (0x40,"memmgrSetMIGPartitionableBAR1Range(pGpu, pMemoryManager)",
                 "src/kernel/gpu/mem_mgr/mem_mgr.c",0x9d7);
    }
    return 0x40;
  }
  nvCheckOkFailedNoLog
            (4,iVar4,
             "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_MEMSYS_SET_PARTITIONABLE_MEM, &params, sizeof(params))"
             ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x9c2);
  return iVar4;
}


// ===== 003bb2f0 memmgrGetMIGPartitionableBAR1Range_IMPL =====

undefined1  [16] memmgrGetMIGPartitionableBAR1Range_IMPL(undefined8 param_1,long param_2)

{
  return *(undefined1 (*) [16])(param_2 + 0xc48);
}


// ===== 003bb310 memmgrAllocMIGGPUInstanceMemory_VF =====

undefined8
memmgrAllocMIGGPUInstanceMemory_VF
          (long param_1,long param_2,undefined8 param_3,undefined4 *param_4,undefined8 *param_5,
          undefined8 *param_6)

{
  undefined8 uVar1;
  
  *param_4 = 0;
  uVar1 = *(undefined8 *)(param_2 + 0xc40);
  *param_5 = *(undefined8 *)(param_2 + 0xc38);
  param_5[1] = uVar1;
  *param_6 = *(undefined8 *)(*(long *)(param_1 + 0x1b78) + 0x478);
  return 0;
}


// ===== 003bb350 memmgrFreeMIGGPUInstanceMemory_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong memmgrFreeMIGGPUInstanceMemory_IMPL
                (long param_1,long param_2,undefined4 param_3,int param_4,long *param_5)

{
  long lVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  int local_3c [3];
  
  lVar5 = rmapiGetInterface(4);
  lVar6 = *(long *)(param_1 + 0x1bc0);
  lVar1 = *(long *)(param_1 + 0x1b70);
  cVar2 = osNumaOnliningEnabled(*(undefined8 *)(param_1 + 0x4e0));
  if (lVar6 == 0) {
    nvAssertFailedNoLog("pKernelMIGManager != NULL","src/kernel/gpu/mem_mgr/mem_mgr.c",0xbae);
    return 0x40;
  }
  cVar3 = (**(code **)(lVar6 + 0x228))(param_1,lVar6,param_3);
  if (cVar3 != '\0') {
    lVar8 = *param_5;
    if ((lVar8 != 0) && (*(long *)(lVar8 + 0x128) != 0)) {
      pmaDestroy(*(long *)(lVar8 + 0x128));
      lVar8 = *param_5;
    }
    __nvoc_objDelete(lVar8);
    *param_5 = 0;
    if (cVar2 == '\0') {
      if (param_4 != 0) {
        (**(code **)(lVar5 + 0x18))(lVar5,*(undefined4 *)(param_2 + 0xc58));
      }
    }
    else {
      (**(code **)(lVar1 + 0x208))(param_1,lVar1,param_3);
      lVar6 = kmigmgrGetSwizzIdInUseMask_IMPL(param_1,lVar6);
      if (lVar6 == 0) {
        uVar4 = (**(code **)(lVar1 + 0x200))
                          (param_1,lVar1,0,*(undefined8 *)(lVar1 + 0x4a8),
                           *(undefined8 *)(lVar1 + 0x4b0),local_3c);
        if (uVar4 != 0) {
          nvAssertOkFailedNoLog
                    (uVar4,
                     "kmemsysNumaAddMemory_HAL(pGpu, pKernelMemorySystem, 0, pKernelMemorySystem->numaOnlineBase, pKernelMemorySystem->numaOnlineSize, &numaNodeId)"
                     ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0xbc5);
          return (ulong)uVar4;
        }
        if (*(int *)(param_1 + 0x7bc) == local_3c[0]) {
          uVar7 = pmaNumaOnlined(*(undefined8 *)
                                  (*(long *)(*(long *)(param_1 + 0x1b78) + 0x478) + 0x128),
                                 *(int *)(param_1 + 0x7bc),*(undefined8 *)(lVar1 + 0x478),
                                 *(undefined8 *)(lVar1 + 0x4b0));
          if ((int)uVar7 == 0) {
            return uVar7;
          }
          nvAssertOkFailedNoLog
                    (uVar7 & 0xffffffff,
                     "pmaNumaOnlined(GPU_GET_HEAP(pGpu)->pPmaObject, pGpu->numaNodeId, pKernelMemorySystem->coherentCpuFbBase, pKernelMemorySystem->numaOnlineSize)"
                     ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0xbcd);
          return uVar7 & 0xffffffff;
        }
        nvAssertFailedNoLog("numaNodeId == pGpu->numaNodeId","src/kernel/gpu/mem_mgr/mem_mgr.c",
                            0xbcc);
        return 0x40;
      }
    }
  }
  return 0;
}


// ===== 003bb560 memmgrFillComprInfoUncompressed_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void memmgrFillComprInfoUncompressed_IMPL(long param_1,undefined4 param_2,undefined4 *param_3)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = (**(code **)(param_1 + 0x2a8))(param_1,5,param_2);
  if (cVar1 != '\0') {
    uVar2 = gpuEngineGetGpu(*(undefined8 *)(param_1 + 0x150));
    param_2 = (**(code **)(param_1 + 0x290))(uVar2,param_1,param_2,0);
  }
  portMemSet(param_3,0,0x1c);
  *param_3 = param_2;
  return;
}


// ===== 003bb5e0 memmgrGetKindComprForGpu_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
memmgrGetKindComprForGpu_KERNEL
          (long param_1,long *param_2,long param_3,undefined8 param_4,undefined4 *param_5,
          undefined4 *param_6)

{
  short sVar1;
  undefined4 uVar2;
  char cVar3;
  undefined4 uVar4;
  long lVar5;
  
  sVar1 = (short)param_2[0x13];
  uVar4 = memdescGetPteKindForGpu(param_2,param_3);
  if (*param_2 != 0) {
    cVar3 = (**(code **)(param_1 + 0x2a8))(param_1,5,uVar4);
    if ((cVar3 != '\0') && ((sVar1 == 0 || (sVar1 == -1)))) {
      lVar5 = kmemsysGetStaticConfig_IMPL(param_3,*(undefined8 *)(param_3 + 0x1b70));
      portMemSet(param_6,0,0x1c);
      *param_6 = uVar4;
      uVar2 = *(undefined4 *)(lVar5 + 0x18);
      *(undefined1 *)(param_6 + 2) = 1;
      param_6[1] = uVar2;
      param_6[5] = 1;
      goto LAB_003bb65d;
    }
  }
  if (sVar1 == -0x3233) {
    portMemSet(param_6,0,0x1c);
    uVar4 = (**(code **)(param_1 + 0x290))(param_3,param_1,uVar4,1);
    *param_6 = uVar4;
  }
  else {
    memmgrFillComprInfoUncompressed_IMPL(param_1,uVar4,param_6);
    uVar4 = *param_6;
  }
LAB_003bb65d:
  *param_5 = uVar4;
  return 0;
}


// ===== 003bb700 memmgrGetKindComprFromMemDesc_IMPL =====

void memmgrGetKindComprFromMemDesc_IMPL
               (undefined8 param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  memmgrGetKindComprForGpu_KERNEL(param_1,param_2,*param_2,param_3,param_4,param_5);
  return;
}


// ===== 003bb720 memmgrPageLevelPoolsCreate_IMPL =====

int memmgrPageLevelPoolsCreate_IMPL(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  
  if ((*(char *)(param_2 + 0x434) != '\0') && (*(char *)(param_2 + 0x436) != '\0')) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x1b78) + 0x478);
    piVar4 = (int *)kgmmuFmtGet_IMPL(*(undefined8 *)(param_1 + 0x1b98),0,0);
    if (piVar4 == (int *)0x0) {
      nvAssertFailedNoLog("NULL != pFmt","src/kernel/gpu/mem_mgr/mem_mgr.c",0xc0e);
      iVar3 = 0x1f;
    }
    else {
      iVar3 = rmMemPoolSetup(*(undefined8 *)(lVar1 + 0x128),param_2 + 0xc30,*piVar4 != 1);
      if (iVar3 == 0) {
        cVar2 = gpuIsCCFeatureEnabled_IMPL(param_1);
        iVar3 = 0;
        if (cVar2 != '\0') {
          rmMemPoolAllocateProtectedMemory(*(undefined8 *)(param_2 + 0xc30),1);
          iVar3 = 0;
        }
      }
      else {
        nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/mem_mgr/mem_mgr.c",0xc13);
        gpuIsCCFeatureEnabled_IMPL(param_1);
      }
    }
    return iVar3;
  }
  return 0;
}


// ===== 003bb820 memmgrStateInitLocked_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrStateInitLocked_IMPL(long param_1,long *param_2)

{
  undefined1 uVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  long *plVar11;
  bool bVar12;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined4 local_48;
  ulong local_40;
  undefined8 local_38;
  undefined1 *local_30;
  
  iVar4 = (*(code *)param_2[0x69])(param_1,param_2,param_2[0x107] << 0x14);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,
               "memmgrInitReservedMemory_HAL(pGpu, pMemoryManager, pMemoryManager->Ram.fbAddrSpaceSizeMb << 20)"
               ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x26c);
    return iVar4;
  }
  iVar4 = osReadRegistryDword(param_1,"OverrideFbSize",&local_40);
  if (iVar4 == 0) {
    if ((int)local_40 != 0) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xbe,"_memmgrInitRegistryOverrides",3,
                   "NVRM: Regkey %s = %dM\n","OverrideFbSize",local_40 & 0xffffffff);
      uVar7 = local_40 & 0xffffffff;
      goto LAB_003bb87f;
    }
  }
  uVar7 = 0xffffffffffffffff;
LAB_003bb87f:
  param_2[0x109] = uVar7;
  iVar4 = osReadRegistryDword(param_1,"RMDisableScrubOnFree",&local_40);
  if ((iVar4 == 0) && ((int)local_40 != 0)) {
    *(undefined1 *)(param_2 + 0x90) = 0;
  }
  iVar4 = osReadRegistryDword(param_1,"RMDisableFastScrubber",&local_40);
  if ((iVar4 == 0) && ((int)local_40 != 0)) {
    *(undefined1 *)((long)param_2 + 0x481) = 0;
  }
  iVar4 = osReadRegistryDword(param_1,"RMAllowSysmemLargePages",&local_40);
  bVar12 = false;
  if (iVar4 == 0) {
    bVar12 = (int)local_40 != 0;
  }
  *(bool *)((long)param_2 + 0x473) = bVar12;
  iVar4 = osReadRegistryDword(param_1,"RMIncreaseRsvdMemorySizeMB",&local_40);
  if (iVar4 == 0) {
    param_2[0x174] = (local_40 & 0xffffffff) << 0x14;
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xe6,"_memmgrInitRegistryOverrides",4,
                 "NVRM: User specified increase in reserved size = %d MBs\n",local_40 & 0xffffffff);
  }
  param_2[0x175] = 0;
  iVar4 = osReadRegistryDword(param_1,"RMOverrideMaxContextSizeRsvdMemoryMB",&local_40);
  if (iVar4 == 0) {
    if ((int)local_40 == 0) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xf4,"_memmgrInitRegistryOverrides",4,
                   "NVRM: Invalid value for RMOverrideMaxContextSizeRsvdMemoryMB: %d\n",0);
    }
    else {
      param_2[0x175] = (local_40 & 0xffffffff) << 0x14;
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xf0,"_memmgrInitRegistryOverrides",4,
                   "NVRM: User specified max context size = %d MBs\n");
    }
  }
  iVar4 = osReadRegistryDword(param_1,"RMDisableNoncontigAlloc",&local_40);
  if ((iVar4 == 0) && ((int)local_40 == 1)) {
    *(undefined1 *)(param_2 + 0x89) = 0;
  }
  iVar4 = osReadRegistryDword(param_1,"RmFbsrPagedDMA",&local_40);
  if (iVar4 == 0) {
    *(bool *)((long)param_2 + 0x43b) = (int)local_40 != 0;
  }
  iVar4 = osReadRegistryDword(param_1,"RmFbsrFileMode",&local_40);
  if ((iVar4 == 0) && ((int)local_40 != 0)) {
    *(undefined1 *)((long)param_2 + 0x442) = 1;
  }
  iVar4 = osReadRegistryDword(param_1,"RMEnablePMA",&local_40);
  if (iVar4 == 0) {
    *(bool *)((long)param_2 + 0x433) = (int)local_40 == 1;
  }
  iVar4 = osReadRegistryDword(param_1,"RmFbsrWDDMMode",&local_40);
  if (iVar4 == 0) {
    *(bool *)(param_2 + 0x86) = (int)local_40 != 0;
  }
  iVar4 = osReadRegistryDword(param_1,"RMEnablePmaManagedPtables",&local_40);
  if (iVar4 == 0 && (int)local_40 == 0) {
    *(undefined1 *)((long)param_2 + 0x436) = 0;
  }
  uVar1 = (*(code *)param_2[0x84])(param_1,param_2);
  *(undefined1 *)((long)param_2 + 0xd35) = uVar1;
  iVar4 = osReadRegistryDword(param_1,"RmEnableLocalizedMemory",&local_40);
  if (iVar4 == 0 && (int)local_40 == 0) {
    *(undefined1 *)((long)param_2 + 0xd35) = 0;
  }
  else if (*(char *)((long)param_2 + 0xd35) != '\0') {
    bVar2 = (*(code *)param_2[0x82])(param_1,param_2);
    param_2[0x1a7] = 1L << (bVar2 & 0x3f);
  }
  iVar4 = osReadRegistryDword(param_1,"RmDisableGlobalCeUtils",&local_40);
  if ((iVar4 == 0) && ((int)local_40 == 1)) {
    *(undefined1 *)(param_2 + 0x95) = 1;
    cVar3 = *(char *)((long)param_2 + 0x449);
  }
  else {
    cVar3 = *(char *)((long)param_2 + 0x449);
  }
  if ((cVar3 != '\0') &&
     (iVar4 = osReadRegistryDword(param_1,"RMEnableLocalEgmPeerId",&local_40), iVar4 == 0)) {
    *(undefined1 *)((long)param_2 + 0x44c) = 1;
    *(int *)(param_2 + 0x8a) = (int)local_40;
  }
  *(undefined1 *)((long)param_2 + 0x486) = *(undefined1 *)(param_1 + 0x4915);
  (*(code *)param_2[0x70])(param_1,param_2);
  (*(code *)param_2[0x45])(param_1,param_2);
  lVar8 = gpuGetKernelFifoShared_IMPL(param_1);
  if (lVar8 != 0) {
    uVar9 = gpuGetKernelFifoShared_IMPL(param_1);
    iVar4 = kfifoAddSchedulingHandler_IMPL
                      (param_1,uVar9,memmgrPostSchedulingEnableHandler,0,
                       memmgrPreSchedulingDisableHandler,0);
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog
                (iVar4,
                 "kfifoAddSchedulingHandler(pGpu, GPU_GET_KERNEL_FIFO(pGpu), memmgrPostSchedulingEnableHandler, NULL, memmgrPreSchedulingDisableHandler, NULL)"
                 ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x27d);
      return iVar4;
    }
  }
  iVar4 = (*(code *)param_2[0x31])(param_1,param_2);
  if (iVar4 == 0) {
    iVar4 = (*(code *)param_2[0x2f])(param_2);
    if ((iVar4 == 0) && (iVar4 = memmgrPageLevelPoolsCreate_IMPL(param_1,param_2), iVar4 == 0)) {
      uVar5 = 0;
      uVar7 = 0;
      if ((char)param_2[0x86] == '\0') {
        if (*(char *)((long)param_2 + 0x43b) == '\0') {
          if (*(char *)((long)param_2 + 0x442) == '\0') {
            uVar5 = 3;
            uVar7 = 3;
          }
          else {
            uVar5 = 6;
            uVar7 = 6;
          }
        }
        else {
          uVar5 = 2;
          uVar7 = 2;
        }
      }
      *(undefined4 *)(param_2 + 0x17f) = uVar5;
      plVar11 = param_2 + uVar7;
      do {
        cVar3 = *(char *)((long)param_2 + 0x43a);
        while( true ) {
          if ((cVar3 == '\0') && ((int)uVar7 == 3)) {
            uVar7 = 4;
            plVar11 = plVar11 + 1;
          }
          iVar4 = (int)uVar7;
          if ((*(char *)(param_1 + 0x44d) != '\0') && ((iVar4 - 2U & 0xfffffffd) == 0)) break;
          iVar6 = (**(code **)(plVar11[0x176] + 0x48))(param_1);
          if (iVar6 != 0) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x2d7,"memmgrStateInitLocked_IMPL",3,
                         "NVRM: fbsrInit failed for supported type %d suspend-resume scheme\n",uVar7
                        );
          }
          if (iVar4 == 7) {
            iVar4 = (**(code **)(param_1 + 0x3e0))(param_1);
            if (iVar4 != 0) {
              return iVar4;
            }
            if (*(char *)((long)param_2 + 0x434) != '\0') {
              local_40 = 0;
              lVar8 = *(long *)(param_1 + 0x1b70);
              pmaGetTotalMemory(*(undefined8 *)(param_2[0x8f] + 0x128),&local_40);
              local_40 = local_40 + *(long *)(lVar8 + 0x470) * -0x400;
              lVar8 = gpushareddataWriteStart_INTERNAL(param_1,0x10);
              *(ulong *)(lVar8 + 0x18) = local_40;
              *(ulong *)(lVar8 + 0x20) = local_40;
              gpushareddataWriteFinish_INTERNAL(param_1,0x10);
            }
            lVar8 = rmapiGetInterface(4);
            iVar4 = rmapiutilAllocClientAndDeviceHandles
                              (lVar8,param_1,param_2 + 0x1a2,(long)param_2 + 0xd14,param_2 + 0x1a3);
            if (iVar4 == 0) {
              *(undefined4 *)((long)param_2 + 0xd2c) = 0;
              cVar3 = gpuIsClassSupported_IMPL(param_1,0x503c);
              if (cVar3 != '\0') {
                local_40 = local_40 & 0xffffffff00000000;
                iVar4 = serverutilGenResourceHandle((int)param_2[0x1a2],&local_40);
                if (iVar4 != 0) {
                  nvAssertOkFailedNoLog
                            (iVar4,
                             "serverutilGenResourceHandle(pMemoryManager->hClient, &hThirdPartyP2P)"
                             ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x4e8);
                  goto LAB_003bbf80;
                }
                portMemSet(&local_58,0,4);
                local_58 = CONCAT44(local_58._4_4_,2 - (uint)(*(char *)(param_1 + 0x454) == '\0'));
                iVar4 = (**(code **)(lVar8 + 8))
                                  (lVar8,(int)param_2[0x1a2],(int)param_2[0x1a3],
                                   local_40 & 0xffffffff,0x503c,&local_58,4);
                if (iVar4 == 0) {
                  *(int *)((long)param_2 + 0xd2c) = (int)local_40;
                }
                else {
                  nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x4fe,
                               "_memmgrAllocInternalClientObjects",3,
                               "NVRM: Error creating internal ThirdPartyP2P object: %x\n",iVar4);
                }
              }
              puVar10 = (undefined8 *)rmapiGetInterface(4);
              local_58 = 0;
              local_50 = 0;
              local_48 = 0;
              local_40 = (ulong)*(uint *)(param_2 + 0x1a2);
              local_38 = 0xc20000007e;
              local_30 = resumeCallback_16;
              local_5c = 0;
              iVar4 = (*(code *)*puVar10)(puVar10,*(uint *)(param_2 + 0x1a2),(int)param_2[0x1a3],
                                          &local_5c,0x7e,&local_40,0x18);
              if (iVar4 == 0) {
                local_58 = 0x2000000c2;
                iVar4 = (*(code *)puVar10[7])
                                  (puVar10,(int)param_2[0x1a2],(int)param_2[0x1a3],0x20800301,
                                   &local_58,0x14);
                if (iVar4 == 0) {
                  return 0;
                }
                nvAssertOkFailedNoLog
                          (iVar4,
                           "pRmApi->Control(pRmApi, pMemoryManager->hClient, pMemoryManager->hSubdevice, NV2080_CTRL_CMD_EVENT_SET_NOTIFICATION, &eventNotificationParams, sizeof(eventNotificationParams))"
                           ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x256);
              }
              else {
                nvAssertOkFailedNoLog
                          (iVar4,
                           "pRmApi->Alloc(pRmApi, pMemoryManager->hClient, pMemoryManager->hSubdevice, &hEvent, NV01_EVENT_KERNEL_CALLBACK_EX, &eventParams, sizeof(eventParams))"
                           ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x24b);
              }
              nvAssertOkFailedNoLog
                        (iVar4,"memmgrRegisterSuspendCallbacks(pMemoryManager)",
                         "src/kernel/gpu/mem_mgr/mem_mgr.c",0x2ee);
            }
            else {
LAB_003bbf80:
              _memmgrFreeInternalClientObjects(param_2);
              nvAssertOkFailedNoLog
                        (iVar4,"_memmgrAllocInternalClientObjects(pGpu, pMemoryManager)",
                         "src/kernel/gpu/mem_mgr/mem_mgr.c",0x2ea);
            }
            (**(code **)(*param_2 + 0xf0))(param_1,param_2);
            return iVar4;
          }
          uVar7 = (ulong)(iVar4 + 1);
          plVar11 = plVar11 + 1;
          cVar3 = *(char *)((long)param_2 + 0x43a);
        }
        uVar7 = (ulong)(iVar4 + 1);
        plVar11 = plVar11 + 1;
      } while( true );
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar4,"memmgrAllocateConsoleRegion_HAL(pGpu, pMemoryManager)",
               "src/kernel/gpu/mem_mgr/mem_mgr.c",0x28b);
  }
  return iVar4;
}


// ===== 003bc1c0 memmgrPageLevelPoolsGetInfo_IMPL =====

int memmgrPageLevelPoolsGetInfo_IMPL(long param_1,long param_2,undefined8 param_3,long *param_4)

{
  char cVar1;
  int iVar2;
  long lVar3;
  bool bVar4;
  long local_38 [2];
  
  bVar4 = false;
  lVar3 = *(long *)(param_1 + 0x1bc0);
  if (lVar3 != 0) {
    cVar1 = kmigmgrIsMIGMemPartitioningEnabled_IMPL(param_1,lVar3);
    bVar4 = cVar1 != '\0';
  }
  if (param_4 == (long *)0x0) {
    nvAssertFailedNoLog("ppMemPoolInfo != NULL","src/kernel/gpu/mem_mgr/mem_mgr.c",0xc51);
    return 0x1f;
  }
  if (*(char *)(param_2 + 0x434) == '\0') {
    return 0x40;
  }
  if (*(char *)(param_2 + 0x436) != '\0') {
    if ((bVar4) &&
       (cVar1 = kmigmgrIsDeviceUsingDeviceProfiling_IMPL(param_1,lVar3,param_3), cVar1 == '\0')) {
      iVar2 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,lVar3,param_3,local_38);
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,"kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)",
                   "src/kernel/gpu/mem_mgr/mem_mgr.c",0xc5e);
        return iVar2;
      }
      lVar3 = *(long *)(local_38[0] + 0x9a0);
    }
    else {
      lVar3 = *(long *)(param_2 + 0xc30);
    }
    if (lVar3 == 0) {
      nvAssertFailedNoLog("pMemPool != NULL","src/kernel/gpu/mem_mgr/mem_mgr.c",0xc66);
      return 0x40;
    }
    *param_4 = lVar3;
    return 0;
  }
  return 0x40;
}


// ===== 003bc300 memmgrPmaInitialize_IMPL =====

int memmgrPmaInitialize_IMPL(long param_1,long param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint local_2c;
  
  cVar3 = osNumaOnliningEnabled(*(undefined8 *)(param_1 + 0x4e0));
  if ((*(char *)(param_2 + 0x433) == '\0') || (*(char *)(param_2 + 0x432) == '\0')) {
    nvAssertFailedNoLog("memmgrIsPmaEnabled(pMemoryManager) && memmgrIsPmaSupportedOnPlatform(pMemoryManager)"
                        ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0xce6);
  }
  uVar6 = (-(uint)(*(char *)(param_2 + 0x435) == '\0') & 0xfffffff0) + 0x11;
  if (*(char *)(param_2 + 0x480) != '\0') {
    uVar6 = uVar6 | 2;
  }
  if (cVar3 == '\0') {
    iVar4 = pmaInitialize(param_3,uVar6);
    if (iVar4 == 0) {
      pmaRegisterUpdateStatsCb(*param_3,_memmgrPmaStatsUpdateCb,param_1);
      return 0;
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xcfb,"memmgrPmaInitialize_IMPL",1,
                 "NVRM: Initializing PMA with NUMA flag.\n");
    uVar5 = uVar6 | 4;
    if (*(char *)(param_1 + 0x4915) != '\0') {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xd00,"memmgrPmaInitialize_IMPL",1,
                   "NVRM: Initializing PMA with NUMA_AUTO_ONLINE flag.\n");
      uVar5 = uVar6 | 0x44;
    }
    iVar4 = pmaInitialize(param_3,uVar5);
    if (iVar4 == 0) {
      uVar1 = *param_3;
      pmaRegisterUpdateStatsCb(uVar1,_memmgrPmaStatsUpdateCb,param_1);
      local_2c = 4;
      lVar2 = *(long *)(param_1 + 0x1b70);
      iVar4 = osReadRegistryDword(param_1,"RmNumaAllocSkipReclaimPercent",&local_2c);
      if ((iVar4 == 0) && (100 < local_2c)) {
        local_2c = 100;
      }
      pmaNumaSetReclaimSkipThreshold(uVar1,local_2c);
      if ((**(char **)(lVar2 + 0x2b8) != '\0') &&
         (iVar4 = pmaNumaOnlined(uVar1,*(undefined4 *)(param_1 + 0x7bc),
                                 *(undefined8 *)(lVar2 + 0x478),*(undefined8 *)(lVar2 + 0x4b0)),
         iVar4 != 0)) {
        nvAssertOkFailedNoLog
                  (iVar4,
                   "pmaNumaOnlined(pPma, pGpu->numaNodeId, pKernelMemorySystem->coherentCpuFbBase, pKernelMemorySystem->numaOnlineSize)"
                   ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0xd21);
        return iVar4;
      }
      return 0;
    }
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xd08,"memmgrPmaInitialize_IMPL",4,
               "NVRM: Failed to initialize PMA!\n");
  return iVar4;
}


// ===== 003bc560 memmgrInitFbRegions_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong memmgrInitFbRegions_IMPL(long param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  
  if (*(int *)(param_2 + 0x858) != 0) {
    nvAssertFailedNoLog("pMemoryManager->Ram.numFBRegions == 0","src/kernel/gpu/mem_mgr/mem_mgr.c",
                        0xd31);
    return 0x40;
  }
  if ((*(char *)(param_1 + 0x44d) == '\0') || (*(char *)(param_1 + 0x4921) != '\0')) {
    uVar1 = (**(code **)(param_2 + 0x370))(param_1,param_2);
    if (uVar1 != 0) {
      nvAssertOkFailedNoLog
                (uVar1,"memmgrInitBaseFbRegions_HAL(pGpu, pMemoryManager)",
                 "src/kernel/gpu/mem_mgr/mem_mgr.c",0xd54);
      return (ulong)uVar1;
    }
    memmgrRegenerateFbRegionPriority_IMPL(param_1,param_2);
    *(undefined1 *)(param_2 + 0x432) = 1;
    uVar2 = 0;
    if ((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(param_1 + 0x4913) == '\0')) {
      *(undefined1 *)(param_2 + 0x432) = 0;
    }
    if (*(char *)(param_1 + 0x4a3) != '\0') {
      if (*(char *)(param_2 + 0x444) != '\0') {
        *(undefined1 *)(param_2 + 0x436) = 0;
        return 0;
      }
      *(undefined1 *)(param_2 + 0x432) = 0;
      return 0;
    }
  }
  else {
    *(undefined8 *)(param_2 + 0x838) = 0x20;
    *(undefined8 *)(param_2 + 0x840) = 0x20;
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xd42,"memmgrInitFbRegions_IMPL",1,
                 "NVRM: Bug 594534: HACK: Report 32MB of framebuffer instead of reading registers.\n"
                );
    uVar2 = (**(code **)(param_2 + 0x3c0))(param_1,param_2);
    if ((int)uVar2 != 0) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xd4d,"memmgrInitFbRegions_IMPL",1,
                   "NVRM: Failed to setup carveout. Carevout functionality is disabled\n");
      return 0;
    }
  }
  return uVar2;
}


// ===== 003bc720 memmgrPmaRegisterRegions_IMPL =====

int memmgrPmaRegisterRegions_IMPL(long param_1,long param_2,long param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  ulong *puVar8;
  ulong *puVar9;
  ulong uVar10;
  uint uVar11;
  ulong uVar12;
  int local_94;
  long local_90;
  ulong local_88;
  ulong local_80;
  undefined4 local_78;
  undefined2 local_74;
  undefined1 local_72;
  undefined4 local_70;
  undefined8 local_6c;
  undefined4 local_64;
  undefined8 uStack_60;
  undefined4 uStack_58;
  undefined8 local_54;
  undefined8 local_4c;
  undefined8 local_44;
  undefined4 local_3c;
  
  iVar1 = *(int *)(param_3 + 0x4c);
  uVar7 = *(ulong *)(param_3 + 0x68);
  lVar6 = *(long *)(param_3 + 0x70);
  uVar2 = *(uint *)(param_3 + 0xd8);
  lVar3 = *(long *)(param_1 + 0x1b70);
  local_90 = 0;
  if ((uVar2 == 0) || (local_90 = portMemAllocNonPaged((ulong)uVar2 << 4), local_90 != 0)) {
    if (*(int *)(param_2 + 0x858) != 0) {
      local_94 = 0;
      uVar11 = 0;
      uVar12 = lVar6 + uVar7;
      puVar8 = (ulong *)(param_2 + 0x860);
      do {
        if ((((uVar7 <= puVar8[1]) && (*puVar8 < uVar12)) &&
            (*(char *)((long)puVar8 + 0x23) == '\0')) && ((char)puVar8[3] == '\0')) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xdb9,"memmgrPmaRegisterRegions_IMPL",1,
                       "NVRM: PMA: Register FB region[%d] %llx..%llx EXTERNAL\n",uVar11,*puVar8,
                       puVar8[1]);
          local_80 = puVar8[1];
          local_88 = *puVar8;
          if (*puVar8 < uVar7) {
            local_88 = uVar7;
          }
          if (uVar12 <= local_80) {
            local_80 = uVar12 - 1;
          }
          local_78 = *(undefined4 *)((long)puVar8 + 0x1c);
          local_74 = (undefined2)puVar8[4];
          local_72 = *(undefined1 *)((long)puVar8 + 0x22);
          if ((local_90 == 0) || (uVar2 == 0)) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xded,"memmgrPmaRegisterRegions_IMPL",1,
                         "NVRM: Register FB region %llx..%llx of size %llx with PMA\n",local_88,
                         local_80,(local_80 - local_88) + 1);
            uVar10 = 0;
            lVar6 = 0;
          }
          else {
            lVar6 = 0;
            uVar10 = 0;
            do {
              uVar4 = *(ulong *)(*(long *)(param_3 + 0xe0) + lVar6);
              if (((uVar4 != 0xffffffffffffffff) && (local_88 <= uVar4)) && (uVar4 <= local_80)) {
                puVar9 = (ulong *)(uVar10 * 0x10 + local_90);
                *puVar9 = uVar4;
                *(bool *)(puVar9 + 1) =
                     (*(int *)(*(long *)(param_3 + 0xe0) + 8 + lVar6) - 2U & 0xfffffffd) == 0;
                uVar10 = (ulong)((int)uVar10 + 1);
              }
              lVar6 = lVar6 + 0x10;
            } while ((ulong)uVar2 << 4 != lVar6);
            nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xded,"memmgrPmaRegisterRegions_IMPL",1,
                         "NVRM: Register FB region %llx..%llx of size %llx with PMA\n",local_88,
                         local_80,(local_80 + 1) - local_88);
            lVar6 = 0;
            if ((int)uVar10 != 0) {
              lVar6 = local_90;
            }
          }
          iVar5 = pmaRegisterRegion(param_4,local_94,0,&local_88,uVar10,lVar6);
          if (iVar5 != 0) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xdfd,"memmgrPmaRegisterRegions_IMPL",4,
                         "NVRM: failed to register FB region %llx..%llx with PMA\n",local_88,
                         local_80);
            portMemFree(local_90);
            goto LAB_003bcb23;
          }
          local_94 = local_94 + 1;
        }
        uVar11 = uVar11 + 1;
        puVar8 = puVar8 + 5;
      } while (uVar11 < *(uint *)(param_2 + 0x858));
    }
    portMemFree(local_90);
    lVar6 = *(long *)(lVar3 + 0x470);
    if (lVar6 != 0) {
      local_64 = 0;
      uVar7 = lVar6 * 0x400 + 0xffff;
      uStack_58 = 0;
      local_6c = 0;
      uStack_60 = (uVar7 & 0xffffffffffff0000) - 1;
      local_54 = 0;
      uVar7 = uVar7 >> 0x10 & 0xffffffff;
      local_4c = 0;
      local_44 = 0;
      local_3c = 0;
      local_70 = 0x48;
      lVar6 = portMemAllocNonPaged(uVar7 * 8);
      if (lVar6 != 0) {
        iVar5 = pmaAllocatePages(param_4,uVar7,0x10000,&local_70,lVar6);
        portMemFree(lVar6);
        if (iVar5 == 0) {
          return 0;
        }
        goto LAB_003bcb23;
      }
    }
    iVar5 = 0;
  }
  else {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xda3,"memmgrPmaRegisterRegions_IMPL",4,
                 "NVRM: Could not allocate memory for blackList!\n");
    portMemFree(0);
    iVar5 = 0x51;
LAB_003bcb23:
    if (*(char *)(param_2 + 0x434) != '\0') {
      if (iVar1 != 2) {
        *(undefined1 *)(param_2 + 0x434) = 0;
      }
      pmaDestroy(param_4);
    }
  }
  return iVar5;
}


// ===== 003bcbc0 memmgrAllocMIGGPUInstanceMemory_PF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrAllocMIGGPUInstanceMemory_PF
              (long param_1,long param_2,uint param_3,undefined4 *param_4,ulong *param_5,
              long *param_6)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  undefined8 *puVar9;
  long lVar10;
  undefined8 uVar11;
  long lVar12;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  char *pcVar13;
  int local_d0;
  undefined4 local_bc;
  undefined8 local_b8;
  uint local_b0;
  undefined8 local_a0;
  undefined8 local_88;
  undefined8 local_80;
  long local_78;
  ulong local_68;
  undefined8 local_4c;
  
  lVar1 = *(long *)(param_1 + 0x1b70);
  lVar10 = *(long *)(param_1 + 0x1bc0);
  local_bc = 0;
  puVar9 = (undefined8 *)rmapiGetInterface(4);
  cVar5 = osNumaOnliningEnabled(*(undefined8 *)(param_1 + 0x4e0));
  if (lVar10 == 0) {
    nvAssertFailedNoLog("pKernelMIGManager != NULL","src/kernel/gpu/mem_mgr/mem_mgr.c",0xab6);
    return 0x40;
  }
  iVar7 = kmemsysGetMIGGPUInstanceMemInfo_IMPL(param_1,lVar1,param_3,param_5);
  if (iVar7 != 0) {
    nvAssertOkFailedNoLog
              (iVar7,
               "kmemsysGetMIGGPUInstanceMemInfo(pGpu, pKernelMemorySystem, swizzId, pAddrRange)",
               "src/kernel/gpu/mem_mgr/mem_mgr.c",0xab7);
    return iVar7;
  }
  cVar6 = (**(code **)(lVar10 + 0x228))(param_1,lVar10,param_3);
  if (cVar6 != '\0') {
    if (cVar5 == '\0') {
      rmGpuLocksRelease(0,0);
      portMemSet(&local_b8,0,0x80);
      local_68 = *param_5;
      local_b8 = 0xdeaf0006;
      local_78 = (param_5[1] + 1) - local_68;
      if (param_5[1] < local_68) {
        local_78 = 0;
      }
      local_b0 = local_b0 | 0x10;
      local_a0 = 0x8000010000000;
      local_88 = 0;
      local_80 = 0;
      local_4c = 0x400000000;
      iVar7 = (*(code *)*puVar9)(puVar9,*(undefined4 *)(param_2 + 0xc58),
                                 *(undefined4 *)(param_2 + 0xc60),&local_bc,0x40,&local_b8,0x80);
      iVar8 = rmGpuLocksAcquire(0,0x2000);
      if (iVar8 != 0) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xb02,"memmgrAllocMIGGPUInstanceMemory_PF",4
                     ,"NVRM: failed to grab RM-Lock\n");
        local_d0 = 0xffff;
        goto LAB_003bd210;
      }
      if (iVar7 != 0) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xb0a,"memmgrAllocMIGGPUInstanceMemory_PF",4
                     ,"NVRM: Unable to allocate physical memory for GPU instance.\n");
        return iVar7;
      }
    }
    else {
      uVar2 = *param_5;
      lVar12 = 0;
      if (uVar2 <= param_5[1]) {
        lVar12 = (param_5[1] + 1) - uVar2;
      }
      lVar10 = kmigmgrGetSwizzIdInUseMask_IMPL(param_1,lVar10);
      if (lVar10 == 0) {
        pmaNumaOfflined(*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x1b78) + 0x478) + 0x128));
        (**(code **)(lVar1 + 0x208))(param_1,lVar1,0);
      }
      iVar7 = (**(code **)(lVar1 + 0x200))(param_1,lVar1,param_3,uVar2,lVar12,&local_b8);
      if (iVar7 != 0) {
        nvAssertOkFailedNoLog
                  (iVar7,
                   "kmemsysNumaAddMemory_HAL(pGpu, pKernelMemorySystem, swizzId, partitionBaseAddr, partitionSize, &numaNodeId)"
                   ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0xad3);
        return iVar7;
      }
    }
  }
  lVar1 = *(long *)(param_1 + 0x1bc0);
  cVar5 = osNumaOnliningEnabled(*(undefined8 *)(param_1 + 0x4e0));
  uVar2 = *param_5;
  lVar10 = 0;
  if (uVar2 <= param_5[1]) {
    lVar10 = (param_5[1] + 1) - uVar2;
  }
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pKernelMIGManager != NULL","src/kernel/gpu/mem_mgr/mem_mgr.c",0xb38);
    local_d0 = 0x40;
  }
  else {
    lVar12 = *(long *)(param_1 + 0x1b70);
    cVar6 = (**(code **)(lVar1 + 0x228))(param_1,lVar1,param_3);
    if (cVar6 == '\0') {
      *param_6 = *(long *)(param_2 + 0x478);
      goto LAB_003bce81;
    }
    *param_6 = 0;
    local_d0 = __nvoc_objCreate_Heap(param_6,param_2,0);
    if (local_d0 == 0) {
      lVar1 = *param_6;
      if ((*(char *)(param_2 + 0x433) == '\0') || (*(char *)(param_2 + 0x432) == '\0')) {
LAB_003bcdb7:
        local_d0 = heapInit_IMPL(param_1,lVar1,uVar2,lVar10,2,0,0);
        uVar11 = extraout_RDX;
        if (local_d0 == 0) {
LAB_003bcde7:
          if (((*(char *)(param_2 + 0x434) == '\0') || (*(char *)(lVar1 + 0x60) == '\0')) ||
             (local_d0 = memmgrPmaRegisterRegions_IMPL
                                   (param_1,param_2,lVar1,*(undefined8 *)(lVar1 + 0x128)),
             uVar11 = extraout_RDX_00, local_d0 == 0)) {
            if ((*(int *)(lVar1 + 0xd8) != 0) &&
               (iVar7 = heapBlackListPages_IMPL(param_1,lVar1,uVar11), iVar7 != 0)) {
              nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xb86,
                           "_memmgrInitMIGMemoryPartitionHeap",3,
                           "NVRM: Error 0x%x creating blacklist\n",iVar7);
            }
LAB_003bce81:
            nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xb17,
                         "memmgrAllocMIGGPUInstanceMemory_PF",1,
                         "NVRM: Allocated memory partition heap for swizzId - %d with StartAddr - 0x%llx, endAddr - 0x%llx.\n"
                         ,param_3,*param_5,param_5[1]);
            *param_4 = local_bc;
            return 0;
          }
          nvAssertOkFailedNoLog
                    (local_d0,
                     "memmgrPmaRegisterRegions(pGpu, pMemoryManager, pMemoryPartitionHeap, pMemoryPartitionHeap->pPmaObject)"
                     ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0xb75);
        }
        else {
          uVar11 = 0xb69;
          pcVar13 = 
          "heapInit(pGpu, pMemoryPartitionHeap, partitionBaseAddr, partitionSize, HEAP_TYPE_PARTITION_LOCAL, GPU_GFID_PF, NULL)"
          ;
LAB_003bd2eb:
          nvAssertOkFailedNoLog(local_d0,pcVar13,"src/kernel/gpu/mem_mgr/mem_mgr.c",uVar11);
          if (lVar1 == 0) goto LAB_003bd1ea;
        }
      }
      else {
        local_d0 = memmgrPmaInitialize_IMPL(param_1,param_2,lVar1 + 0x128);
        uVar11 = 0xb4d;
        pcVar13 = "memmgrPmaInitialize(pGpu, pMemoryManager, &(pMemoryPartitionHeap->pPmaObject))";
        if (local_d0 != 0) goto LAB_003bd2eb;
        if (cVar5 == '\0') goto LAB_003bcdb7;
        pcVar13 = (char *)((ulong)param_3 * 0x20 + *(long *)(lVar12 + 0x2b8));
        if (*pcVar13 == '\0') {
          nvAssertFailedNoLog("pKernelMemorySystem->memPartitionNumaInfo[swizzId].bInUse",
                              "src/kernel/gpu/mem_mgr/mem_mgr.c",0xb54);
          if (lVar1 != 0) {
            if (*(long *)(lVar1 + 0x128) == 0) {
              __nvoc_objDelete(lVar1);
              *param_6 = 0;
            }
            else {
              pmaDestroy();
              __nvoc_objDelete(lVar1);
              *param_6 = 0;
            }
          }
          goto LAB_003bce81;
        }
        uVar3 = *(undefined8 *)(pcVar13 + 8);
        uVar4 = *(undefined8 *)(pcVar13 + 0x10);
        local_d0 = pmaNumaOnlined(*(undefined8 *)(lVar1 + 0x128),*(undefined4 *)(pcVar13 + 0x18),
                                  *(undefined8 *)(lVar12 + 0x478),*(undefined8 *)(lVar12 + 0x4b0));
        if (local_d0 == 0) {
          uVar11 = 0;
          local_d0 = heapInit_IMPL(param_1,lVar1,uVar3,uVar4,2,0);
          if (local_d0 == 0) goto LAB_003bcde7;
          nvAssertOkFailedNoLog
                    (local_d0,
                     "heapInit(pGpu, pMemoryPartitionHeap, partitionBaseAddr, partitionSize, HEAP_TYPE_PARTITION_LOCAL, GPU_GFID_PF, NULL)"
                     ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0xb69);
        }
        else {
          nvAssertOkFailedNoLog
                    (local_d0,
                     "pmaNumaOnlined(pMemoryPartitionHeap->pPmaObject, pKernelMemorySystem->memPartitionNumaInfo[swizzId].numaNodeId, pKernelMemorySystem->coherentCpuFbBase, pKernelMemorySystem->numaOnlineSize)"
                     ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0xb5f);
        }
      }
      if (*(long *)(lVar1 + 0x128) != 0) {
        pmaDestroy();
      }
      __nvoc_objDelete(lVar1);
      *param_6 = 0;
    }
    else {
      nvAssertOkFailedNoLog
                (local_d0,"objCreate(ppMemoryPartitionHeap, pMemoryManager, Heap)",
                 "src/kernel/gpu/mem_mgr/mem_mgr.c",0xb43);
    }
  }
LAB_003bd1ea:
  nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xb13,"memmgrAllocMIGGPUInstanceMemory_PF",4,
               "NVRM: Unable to initialize memory partition heap\n");
LAB_003bd210:
  (*(code *)puVar9[3])(puVar9,*(undefined4 *)(param_2 + 0xc58),local_bc);
  return local_d0;
}


// ===== 003bd3e0 memmgrCreateHeap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrCreateHeap_IMPL(long param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  undefined8 uVar7;
  long lVar8;
  long local_30;
  
  uVar7 = 0;
  if (param_1 != 0) {
    uVar7 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar3 = gpuEngineGetGpu(uVar7);
  uVar7 = *(undefined8 *)(lVar3 + 0x1b70);
  if (((*(int *)(param_1 + 0x858) == 0) || (*(char *)(lVar3 + 0x4913) != '\0')) &&
     (*(char *)(param_1 + 0xd1c) == '\0')) {
    lVar8 = *(long *)(param_1 + 0x498);
  }
  else {
    lVar8 = 0;
  }
  lVar4 = (**(code **)(param_1 + 0x220))(lVar3,param_1);
  (**(code **)(param_1 + 0x208))(lVar3,param_1);
  uVar6 = *(long *)(param_1 + 0x838) * 0x100000;
  uVar5 = lVar8 + lVar4;
  if (uVar6 < (ulong)(lVar8 + lVar4)) {
    uVar5 = uVar6;
  }
  if (((uVar6 - uVar5 != 0) || (iVar1 = 0, *(char *)(param_1 + 0x437) != '\0')) &&
     (iVar1 = __nvoc_objCreate_Heap(&local_30,param_1,0), iVar1 == 0)) {
    *(long *)(param_1 + 0x478) = local_30;
    if (((*(char *)(param_1 + 0x433) == '\0') || (*(char *)(param_1 + 0x432) == '\0')) ||
       (iVar1 = memmgrPmaInitialize_IMPL(lVar3,param_1,local_30 + 0x128), iVar1 == 0)) {
      iVar1 = heapInit_IMPL(lVar3,local_30,*(long *)(param_1 + 0x488),
                            (uVar6 - uVar5) - *(long *)(param_1 + 0x488),0,0);
      if (iVar1 == 0) {
        if (((*(char *)(param_1 + 0x434) == '\0') ||
            (lVar8 = *(long *)(param_1 + 0x478), *(char *)(lVar8 + 0x60) == '\0')) ||
           (iVar1 = memmgrPmaRegisterRegions_IMPL
                              (lVar3,param_1,lVar8,*(undefined8 *)(lVar8 + 0x128)), iVar1 == 0)) {
          gpuIsInstInSysBootByAcrEnabled_IMPL(lVar3);
          iVar1 = 0;
          if ((*(int *)(local_30 + 0xd8) != 0) &&
             (iVar1 = heapBlackListPages_IMPL(lVar3), iVar1 != 0)) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x47c,"memmgrCreateHeap_IMPL",3,
                         "NVRM: Error 0x%x creating blacklist\n");
          }
          iVar2 = kmemsysPostHeapCreate_KERNEL(lVar3,uVar7);
          if (iVar2 != 0) {
            nvAssertOkFailedNoLog
                      (iVar2,"kmemsysPostHeapCreate_HAL(pGpu, pKernelMemorySystem)",
                       "src/kernel/gpu/mem_mgr/mem_mgr.c",0x482);
            iVar1 = iVar2;
          }
        }
        else {
          nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/mem_mgr.c",0x45a);
        }
      }
      else {
        nvAssertOkFailedNoLog(iVar1,"status","src/kernel/gpu/mem_mgr/mem_mgr.c",0x454);
      }
    }
    else {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/mem_mgr.c",0x44e);
    }
  }
  return iVar1;
}


// ===== 003bd6a0 memmgrGetClientFbAddrSpaceSize_IMPL =====

undefined8 memmgrGetClientFbAddrSpaceSize_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 local_10;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x1b78) + 0x478);
  if (*(char *)(param_2 + 0x434) != '\0') {
    pmaGetClientAddrSpaceSize(*(undefined8 *)(lVar1 + 0x128),&local_10);
    return local_10;
  }
  heapGetClientAddrSpaceSize_IMPL(param_1,lVar1,&local_10);
  return local_10;
}


// ===== 003bd700 memmgrAllocMIGMemoryAllocationInternalHandles_IMPL =====

ulong memmgrAllocMIGMemoryAllocationInternalHandles_IMPL(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  ulong uVar2;
  
  uVar1 = rmapiGetInterface(4);
  if (*(int *)(param_2 + 0xc58) == 0) {
    uVar2 = rmapiutilAllocClientAndDeviceHandles
                      (uVar1,param_1,param_2 + 0xc58,param_2 + 0xc5c,param_2 + 0xc60);
    if ((int)uVar2 != 0) {
      nvAssertOkFailedNoLog
                (uVar2 & 0xffffffff,
                 "rmapiutilAllocClientAndDeviceHandles(pRmApi, pGpu, &pMemoryManager->MIGMemoryPartitioningInfo.hClient, &pMemoryManager->MIGMemoryPartitioningInfo.hDevice, &pMemoryManager->MIGMemoryPartitioningInfo.hSubdevice)"
                 ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0xe63);
      uVar2 = uVar2 & 0xffffffff;
    }
    return uVar2;
  }
  nvAssertFailedNoLog("pMemoryManager->MIGMemoryPartitioningInfo.hClient == NV01_NULL_OBJECT",
                      "src/kernel/gpu/mem_mgr/mem_mgr.c",0xe62);
  return 0x40;
}


// ===== 003bd7c0 memmgrFreeMIGMemoryAllocationInternalHandles_IMPL =====

void memmgrFreeMIGMemoryAllocationInternalHandles_IMPL(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  uVar1 = rmapiGetInterface(4);
  rmapiutilFreeClientAndDeviceHandles(uVar1,param_2 + 0xc58,param_2 + 0xc5c,param_2 + 0xc60);
  return;
}


// ===== 003bd800 memmgrGetFreeMemoryForAllMIGGPUInstances_IMPL =====

void memmgrGetFreeMemoryForAllMIGGPUInstances_IMPL(long param_1,long param_2,long *param_3)

{
  undefined8 uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  long local_40 [2];
  
  iVar3 = 0;
  local_40[0] = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x1bc0);
  *param_3 = 0;
  do {
    lVar2 = kmigmgrGetMIGGpuInstanceSlot_IMPL(param_1,uVar1,iVar3);
    if ((lVar2 != 0) && (*(char *)(lVar2 + 0x988) != '\0')) {
      lVar4 = *(long *)(lVar2 + 0x980);
      if (lVar4 == 0) {
        nvAssertFailedNoLog("pKernelMIGGPUInstance->pMemoryPartitionHeap != NULL",
                            "src/kernel/gpu/mem_mgr/mem_mgr.c",0xe92);
        lVar4 = *(long *)(lVar2 + 0x980);
      }
      if (*(char *)(param_2 + 0x434) == '\0') {
        heapGetFree_IMPL(lVar4,local_40);
      }
      else {
        pmaGetFreeMemory(*(undefined8 *)(lVar4 + 0x128),local_40);
      }
      *param_3 = *param_3 + local_40[0];
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 8);
  return;
}


// ===== 003bd8e0 memmgrGetTotalMemoryForAllMIGGPUInstances_IMPL =====

void memmgrGetTotalMemoryForAllMIGGPUInstances_IMPL(long param_1,long param_2,long *param_3)

{
  undefined8 uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  long local_40 [2];
  
  iVar3 = 0;
  local_40[0] = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x1bc0);
  *param_3 = 0;
  do {
    lVar2 = kmigmgrGetMIGGpuInstanceSlot_IMPL(param_1,uVar1,iVar3);
    if ((lVar2 != 0) && (*(char *)(lVar2 + 0x988) != '\0')) {
      lVar4 = *(long *)(lVar2 + 0x980);
      if (lVar4 == 0) {
        nvAssertFailedNoLog("pKernelMIGGPUInstance->pMemoryPartitionHeap != NULL",
                            "src/kernel/gpu/mem_mgr/mem_mgr.c",0xeb8);
        lVar4 = *(long *)(lVar2 + 0x980);
      }
      if (*(char *)(param_2 + 0x434) == '\0') {
        heapGetSize_IMPL(lVar4,local_40);
      }
      else {
        pmaGetTotalMemory(*(undefined8 *)(lVar4 + 0x128),local_40);
      }
      *param_3 = *param_3 + local_40[0];
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 8);
  return;
}


// ===== 003bd9c0 memmgrGetTopLevelScrubberStatus_IMPL =====

void memmgrGetTopLevelScrubberStatus_IMPL(long param_1,long param_2,byte *param_3,byte *param_4)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  uint local_c;
  
  bVar1 = 0;
  local_c = 3;
  bVar3 = 0;
  if (*(char *)(param_2 + 0x434) != '\0') {
    iVar2 = pmaQueryConfigs(*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x1b78) + 0x478) + 0x128),
                            &local_c);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,"pmaQueryConfigs(pHeap->pPmaObject, &pmaConfigs)",
                 "src/kernel/gpu/mem_mgr/mem_mgr.c",0xed5);
    }
    bVar3 = (byte)local_c & 1;
    bVar1 = (byte)(local_c >> 1) & 1;
  }
  if (param_3 != (byte *)0x0) {
    *param_3 = bVar3;
  }
  if (param_4 != (byte *)0x0) {
    *param_4 = bVar1;
  }
  return;
}


// ===== 003bda80 memmgrDiscoverMIGPartitionableMemoryRange_VF =====

int memmgrDiscoverMIGPartitionableMemoryRange_VF(long param_1,long param_2,ulong *param_3)

{
  int iVar1;
  ulong *puVar2;
  ulong uVar3;
  ulong uVar4;
  long local_30;
  undefined1 local_28 [8];
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  ulong local_10;
  
  if (*(char *)(param_2 + 0x434) != '\0') {
    iVar1 = *(int *)(param_2 + 0x858);
    if (iVar1 != 0) {
      uVar3 = *(ulong *)(param_2 + 0x860);
      uVar4 = *(ulong *)(param_2 + 0x868);
      if (iVar1 != 1) {
        puVar2 = (ulong *)(param_2 + 0x888);
        do {
          if (*puVar2 < uVar3) {
            uVar3 = *puVar2;
          }
          if (uVar4 < puVar2[1]) {
            uVar4 = puVar2[1];
          }
          puVar2 = puVar2 + 5;
        } while (puVar2 != (ulong *)(param_2 + 0x8b0 + (ulong)(iVar1 - 2) * 0x28));
      }
      *param_3 = uVar3;
      param_3[1] = uVar4;
      return 0;
    }
    *param_3 = 0;
    param_3[1] = 0xffffffffffffffff;
    return 0;
  }
  iVar1 = heapInfo_IMPL(*(undefined8 *)(*(long *)(param_1 + 0x1b78) + 0x478),local_20,local_18,
                        local_28,&local_10,&local_30);
  if (iVar1 == 0) {
    *param_3 = local_10;
    param_3[1] = local_30 + -1 + local_10;
    return 0;
  }
  nvAssertOkFailedNoLog
            (iVar1,"heapInfo(pHeap, &freeMem, &bytesTotal, &base, &offset, &size)",
             "src/kernel/gpu/mem_mgr/mem_mgr.c",0xf25);
  return iVar1;
}


// ===== 003bdbb0 memmgrGetVgpuHostRmReservedFb_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong memmgrGetVgpuHostRmReservedFb_KERNEL(long param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  ulong local_18;
  ulong local_10;
  
  local_10 = (ulong)param_3;
  local_18 = 0;
  uVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800ac5,&local_18,0x10);
  if (uVar1 == 0) {
    return local_18;
  }
  nvAssertOkFailedNoLog
            (uVar1,
             "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_MEMMGR_GET_VGPU_CONFIG_HOST_RESERVED_FB, &params, sizeof(params))"
             ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0xf91);
  return (ulong)uVar1;
}


// ===== 003bdc30 memmgrStatePostLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrStatePostLoad_IMPL(long param_1,long param_2)

{
  int iVar1;
  undefined4 local_2c;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  if (*(char *)(param_2 + 0x449) != '\0') {
    if ((((*(char *)(param_1 + 0x4915) != '\0') &&
         (*(char *)(*(long *)(param_1 + 7000) + 0x3a8) != '\0')) &&
        (iVar1 = osGetEgmInfo(param_1,&local_28,&local_20,&local_2c), iVar1 == 0)) &&
       (CONCAT44(uStack_1c,local_20) != 0)) {
      *(long *)(param_2 + 0x468) = CONCAT44(uStack_1c,local_20);
      *(undefined1 *)(param_2 + 0x454) = 1;
      *(undefined8 *)(param_2 + 0x460) = local_28;
      *(undefined4 *)(param_2 + 0x45c) = local_2c;
      *(undefined4 *)(param_2 + 0x458) = 7;
    }
    if (*(char *)(param_2 + 0x44c) != '\0') {
      *(undefined1 *)(param_2 + 0x454) = 1;
      *(undefined4 *)(param_2 + 0x458) = *(undefined4 *)(param_2 + 0x450);
      *(undefined4 *)(param_2 + 0x45c) = *(undefined4 *)(param_1 + 0x7c0);
      goto LAB_003bdc9d;
    }
  }
  if (*(char *)(param_2 + 0x454) == '\0') {
    return 0;
  }
LAB_003bdc9d:
  iVar1 = kbusReserveP2PPeerIds_GM200
                    (param_1,*(undefined8 *)(&DAT_00001b90 + param_1),
                     1 << ((byte)*(undefined4 *)(param_2 + 0x458) & 0x1f));
  if (iVar1 == 0) {
    iVar1 = 0;
    if (*(char *)(param_1 + 0x4913) == '\0') {
      local_20 = *(undefined4 *)(param_2 + 0x458);
      iVar1 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20800a8d,&local_20,4);
      if (iVar1 != 0) {
        if (iVar1 == 0x1e) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xfed,"memmgrStatePostLoad_IMPL",4,
                       "NVRM: SBIOS allocated EGM address is incorrect.\n");
        }
        nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xfef,"memmgrStatePostLoad_IMPL",4,
                     "NVRM: HSHUB programming failed for EGM Peer ID: %u. status: %d\n",
                     *(undefined4 *)(param_2 + 0x458),iVar1);
        (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x2f8))
                  (param_1,*(long *)(&DAT_00001b90 + param_1),
                   1 << ((byte)*(undefined4 *)(param_2 + 0x458) & 0x1f));
        *(undefined1 *)(param_2 + 0x454) = 0;
        *(undefined4 *)(param_2 + 0x458) = 0xffffffff;
      }
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0xffc,"memmgrStatePostLoad_IMPL",4,
                 "NVRM: Peer ID specified for local EGM already in use!\n");
    *(undefined1 *)(param_2 + 0x454) = 0;
    iVar1 = 0x1f;
    *(undefined4 *)(param_2 + 0x458) = 0xffffffff;
  }
  return iVar1;
}


// ===== 003bdea0 memmgrInitCeUtils_IMPL =====

/* WARNING: Type propagation algorithm not settling */

int memmgrInitCeUtils_IMPL(long param_1,char param_2,char param_3)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  undefined8 uVar7;
  long lVar8;
  ulong uVar9;
  undefined8 extraout_RDX;
  bool bVar10;
  int local_a8;
  int local_a4;
  long local_a0;
  long local_98 [13];
  
  uVar7 = 0;
  if (param_1 != 0) {
    uVar7 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar5 = gpuEngineGetGpu(uVar7);
  pcVar6 = (char *)kmemsysGetStaticConfig_IMPL(lVar5,*(undefined8 *)(lVar5 + 0x1b70));
  lVar1 = *(long *)(lVar5 + 0x1bc0);
  local_98[2] = 0;
  bVar10 = false;
  local_98[1] = 0;
  local_98[3] = 0;
  if (lVar1 != 0) {
    cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar5,lVar1);
    bVar10 = cVar3 != '\0';
  }
  if (*(long *)(param_1 + 0x4a0) == 0) {
    if (param_2 == '\0') {
      cVar3 = rmcfg_IsTURING_CLASSIC_GPUSorBetter(lVar5);
      if (cVar3 != '\0') {
        local_98[2] = local_98[2] | 8;
      }
      if (*(char *)(param_1 + 0x486) != '\0') {
        local_98[2] = local_98[2] | 2;
      }
      if ((((param_3 != '\0') && (*(char *)(lVar5 + 0x446) == '\0')) &&
          (*(char *)(lVar5 + 0x490e) == '\0')) &&
         ((pcVar6[3] == '\0' && ((pcVar6[2] != '\0' || (*pcVar6 != '\0')))))) {
        local_98[2] = local_98[2] | 2;
      }
    }
    else {
      uVar9 = local_98[2] | 6;
      local_98[2] = local_98[2] | 4;
      if (*(char *)(param_1 + 0x486) != '\0') {
        local_98[2] = uVar9;
      }
    }
    lVar2 = 0;
    lVar8 = lVar2;
    if ((*(char *)(lVar5 + 0x908) != '\0') && (bVar10)) {
      iVar4 = 0;
      do {
        lVar8 = kmigmgrGetMIGGpuInstanceSlot_IMPL(lVar5,lVar1,iVar4);
        if (((lVar8 != 0) && (*(char *)(lVar8 + 0x988) != '\0')) && (*(int *)(lVar8 + 0x968) == 0))
        break;
        iVar4 = iVar4 + 1;
        lVar8 = lVar2;
      } while (iVar4 != 8);
    }
    uVar7 = gpuEngineGetGpu(*(undefined8 *)(param_1 + 0x150));
    iVar4 = __nvoc_objCreate_CeUtils(param_1 + 0x4a0,param_1,0,uVar7,lVar8,local_98 + 1);
    if (iVar4 == 0) {
      local_a0 = 0;
      local_98[0] = 0;
      local_98[4] = 0;
      local_98[5] = 0;
      local_98[6] = 0;
      local_98[7] = 0;
      local_98[8] = 0;
      local_98[9] = 0;
      local_98[10] = 0;
      local_98[0xb] = 0;
      local_a8 = -0x55443323;
      local_a4 = 0x11223345;
      if (*(char *)(lVar5 + 0x4ba) == '\0') {
        if (*(long *)(param_1 + 0x4a0) == 0) {
          iVar4 = 0x40;
          nvAssertFailedNoLog("pMemoryManager->pCeUtils != NULL","src/kernel/gpu/mem_mgr/mem_mgr.c",
                              0x192);
        }
        else {
          if (*(long *)(*(long *)(param_1 + 0x4a0) + 0xb8) != 0) {
            return 0;
          }
          uVar7 = 1;
          iVar4 = memdescCreate(&local_a0,lVar5,4,0x1000,1,
                                (*(char *)(*(long *)(lVar5 + 0x4d8) + 0x80) == '\0') + '\x01');
          if (iVar4 == 0) {
            *(undefined4 *)(local_a0 + 0x9c) = 0x34;
            iVar4 = memdescAlloc(local_a0,0,extraout_RDX,uVar7);
            if (iVar4 == 0) {
              local_98[4] = local_a0;
              iVar4 = memdescCreate(local_98,lVar5,4,0,1,1,1);
              if (iVar4 == 0) {
                *(undefined4 *)(local_98[0] + 0x9c) = 0xab;
                iVar4 = memdescAlloc();
                if (iVar4 == 0) {
                  local_98[8] = local_98[0];
                  iVar4 = memmgrMemSet_IMPL(param_1,local_98 + 4,0,4,0x40);
                  if (iVar4 == 0) {
                    iVar4 = memmgrMemWrite_IMPL(param_1,local_98 + 4,&local_a8,4,0);
                    if (iVar4 == 0) {
                      iVar4 = memmgrMemWrite_IMPL(param_1,local_98 + 8,&local_a4,4,0);
                      if (iVar4 == 0) {
                        iVar4 = memmgrMemCopy_IMPL(param_1,local_98 + 8,local_98 + 4,4,0x40);
                        if (iVar4 == 0) {
                          iVar4 = memmgrMemRead_IMPL(param_1,local_98 + 8,&local_a4,4,0);
                          if (iVar4 == 0) {
                            if (local_a4 == local_a8) {
                              memdescFree(local_a0);
                              memdescDestroy(local_a0);
                              memdescFree(local_98[0]);
                              memdescDestroy(local_98[0]);
                              return 0;
                            }
                            nvAssertOkFailedNoLog
                                      (0x40,"sysmemData == vidmemData",
                                       "src/kernel/gpu/mem_mgr/mem_mgr.c",0x1ba);
                            iVar4 = 0x40;
                          }
                          else {
                            nvAssertOkFailedNoLog
                                      (iVar4,
                                       "memmgrMemRead (pMemoryManager, &sysSurface, &sysmemData, sizeof sysmemData, TRANSFER_FLAGS_NONE)"
                                       ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x1b9);
                          }
                        }
                        else {
                          nvAssertOkFailedNoLog
                                    (iVar4,
                                     "memmgrMemCopy (pMemoryManager, &sysSurface, &vidSurface, sizeof vidmemData, TRANSFER_FLAGS_PREFER_CE)"
                                     ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x1b8);
                        }
                      }
                      else {
                        nvAssertOkFailedNoLog
                                  (iVar4,
                                   "memmgrMemWrite(pMemoryManager, &sysSurface, &sysmemData, sizeof sysmemData, TRANSFER_FLAGS_NONE)"
                                   ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x1b7);
                      }
                    }
                    else {
                      nvAssertOkFailedNoLog
                                (iVar4,
                                 "memmgrMemWrite(pMemoryManager, &vidSurface, &vidmemData, sizeof vidmemData, TRANSFER_FLAGS_NONE)"
                                 ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x1b6);
                    }
                  }
                  else {
                    nvAssertOkFailedNoLog
                              (iVar4,
                               "memmgrMemSet(pMemoryManager, &vidSurface, 0, sizeof vidmemData, TRANSFER_FLAGS_PREFER_CE)"
                               ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x1b4);
                  }
                }
                else {
                  nvAssertOkFailedNoLog(iVar4,"status","src/kernel/gpu/mem_mgr/mem_mgr.c",0x1b0);
                }
              }
              else {
                nvAssertOkFailedNoLog
                          (iVar4,
                           "memdescCreate(&pSysMemDesc, pGpu, sizeof sysmemData, 0, NV_TRUE, (RMCFG_FEATURE_PLATFORM_GSP && !pGpu->pGpuArch->bGpuArchIsZeroFb) ? ADDR_FBMEM : ADDR_SYSMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_NONE)"
                           ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x1a8);
              }
            }
            else {
              nvAssertOkFailedNoLog(iVar4,"status","src/kernel/gpu/mem_mgr/mem_mgr.c",0x1a5);
            }
          }
          else {
            nvAssertOkFailedNoLog
                      (iVar4,
                       "memdescCreate(&pVidMemDesc, pGpu, sizeof vidmemData, RM_PAGE_SIZE, NV_TRUE, pGpu->pGpuArch->bGpuArchIsZeroFb ? ADDR_SYSMEM : ADDR_FBMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_NONE)"
                       ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x19e);
          }
          memdescFree(local_a0);
          memdescDestroy(local_a0);
          memdescFree(local_98[0]);
          memdescDestroy(local_98[0]);
        }
        nvAssertOkFailedNoLog(iVar4,"status","src/kernel/gpu/mem_mgr/mem_mgr.c",0x103b);
        uVar7 = *(undefined8 *)(param_1 + 0x4a0);
        *(undefined8 *)(param_1 + 0x4a0) = 0;
        __nvoc_objDelete(uVar7);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar4,
                 "objCreate(&pMemoryManager->pCeUtils, pMemoryManager, CeUtils, ENG_GET_GPU(pMemoryManager), pKernelMIGGPUInstance, &ceUtilsParams)"
                 ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x1037);
    }
  }
  else {
    iVar4 = 0x40;
    nvAssertFailedNoLog("pMemoryManager->pCeUtils == NULL","src/kernel/gpu/mem_mgr/mem_mgr.c",0x1016
                       );
  }
  return iVar4;
}


// ===== 003be530 memmgrInitInternalChannels_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrInitInternalChannels_IMPL(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(param_2 + 400))();
  if (iVar2 != 0) {
    nvAssertOkFailedNoLog
              (iVar2,"memmgrScrubHandlePostSchedulingEnable_HAL(pGpu, pMemoryManager)",
               "src/kernel/gpu/mem_mgr/mem_mgr.c",0x1cc);
    return iVar2;
  }
  if (((*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) == '\0') &&
      (*(char *)(param_1 + 0x44d) == '\0')) && (*(char *)(param_1 + 1099) == '\0')) {
    if (((((*(char *)(param_2 + 0x4a8) == '\0') && (*(char *)(param_1 + 0x4921) == '\0')) &&
         ((*(char *)(param_1 + 0x908) == '\0' ||
          ((*(char *)(param_1 + 0x4913) != '\0' && (*(char *)(param_1 + 0x491e) == '\0')))))) &&
        (*(char *)(param_1 + 0x446) == '\0')) && (*(char *)(param_1 + 0x490e) == '\0')) {
      cVar1 = hypervisorIsVgxHyper_IMPL();
      if ((((cVar1 == '\0') &&
           ((*(char *)(param_1 + 0x4a4e) == '\0' || (*(char *)(param_1 + 0x908) != '\0')))) &&
          ((*(long *)(param_1 + 0x1bc0) == 0 ||
           (cVar1 = kmigmgrIsMIGEnabled_IMPL(param_1), cVar1 == '\0')))) &&
         ((cVar1 = gpuIsCCorApmFeatureEnabled_IMPL(param_1), cVar1 == '\0' &&
          (*(char *)(param_1 + 0x4915) == '\0')))) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x1f1,"memmgrInitInternalChannels_IMPL",1,
                     "NVRM: Initializing global CeUtils instance\n");
        iVar2 = memmgrInitCeUtils_IMPL(param_2,0,1);
        if (iVar2 == 0) {
          return 0;
        }
        nvAssertOkFailedNoLog
                  (iVar2,"memmgrInitCeUtils(pMemoryManager, NV_FALSE, NV_TRUE)",
                   "src/kernel/gpu/mem_mgr/mem_mgr.c",499);
        return iVar2;
      }
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x1ec,"memmgrInitInternalChannels_IMPL",1,
                   "NVRM: Skipping global CeUtils creation\n");
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x1df,"memmgrInitInternalChannels_IMPL",1,
                 "NVRM: Skipping global CeUtils creation (unsupported platform)\n");
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr.c",0x1d4,"memmgrInitInternalChannels_IMPL",1,
               "NVRM: Skipping global CeUtils creation (supported platform but useless)\n");
  return 0;
}


// ===== 003be770 memmgrPostSchedulingEnableHandler =====

void memmgrPostSchedulingEnableHandler(long param_1)

{
  memmgrInitInternalChannels_IMPL(param_1,*(undefined8 *)(param_1 + 0x1b78));
  return;
}


// ===== 003be780 memmgrDestroyCeUtils_IMPL =====

void memmgrDestroyCeUtils_IMPL(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 0x4a0);
  *(undefined8 *)(param_1 + 0x4a0) = 0;
  __nvoc_objDelete(uVar1);
  return;
}


// ===== 003be7a0 memmgrGetInternalClientHandles_IMPL =====

ulong memmgrGetInternalClientHandles_IMPL
                (long param_1,long param_2,undefined8 param_3,undefined4 *param_4,
                undefined4 *param_5,undefined4 *param_6)

{
  long lVar1;
  char cVar2;
  ulong uVar3;
  long local_38 [2];
  
  lVar1 = *(long *)(param_1 + 0x1bc0);
  if (((lVar1 == 0) || (cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1,lVar1), cVar2 == '\0')
      ) || (cVar2 = kmigmgrIsDeviceUsingDeviceProfiling_IMPL(param_1,lVar1,param_3), cVar2 != '\0'))
  {
    *param_4 = *(undefined4 *)(param_2 + 0xd10);
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = *(undefined4 *)(param_2 + 0xd14);
    }
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = *(undefined4 *)(param_2 + 0xd18);
    }
    uVar3 = 0;
  }
  else {
    uVar3 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,lVar1,param_3,local_38);
    if ((int)uVar3 == 0) {
      *param_4 = *(undefined4 *)(local_38[0] + 0x9c0);
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = *(undefined4 *)(local_38[0] + 0x9c4);
      }
      if (param_6 != (undefined4 *)0x0) {
        *param_6 = *(undefined4 *)(local_38[0] + 0x9c8);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (uVar3 & 0xffffffff,
                 "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pExternalDevice, &pMigInstanceRef)"
                 ,"src/kernel/gpu/mem_mgr/mem_mgr.c",0x1071);
      uVar3 = uVar3 & 0xffffffff;
    }
  }
  return uVar3;
}


// ===== 003be8e0 memmgrGetDeviceCaps.constprop.0 =====

void memmgrGetDeviceCaps_constprop_0(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  byte bVar2;
  char cVar3;
  long lVar4;
  byte local_3b;
  byte local_3a;
  byte local_39;
  
  lVar1 = *(long *)(param_1 + 0x1b70);
  if (lVar1 != 0) {
    lVar4 = kmemsysGetStaticConfig_IMPL(param_1,lVar1);
    portMemSet(&local_3b,0,3);
    bVar2 = local_3b;
    if (*(char *)(param_2 + 0x437) != '\0') {
      bVar2 = local_3b | 4;
    }
    local_3a = local_3a | 1;
    local_3b = bVar2 | 3;
    if (*(char *)(lVar1 + 0x299) != '\0') {
      local_3b = bVar2 | 0xb;
    }
    if (((*(char *)(lVar4 + 5) != '\0') && (*(char *)(param_2 + 0x471) != '\0')) &&
       (cVar3 = rmcfg_IsGP100orBetter(param_1), cVar3 == '\0')) {
      local_3a = local_3a | 0x10;
    }
    cVar3 = memmgrComprSupported_IMPL(param_2,1);
    if (cVar3 != '\0') {
      local_3b = local_3b | 0x20;
    }
    if ((*(char *)(lVar1 + 0x298) != '\0') &&
       (*(char *)(param_1 + 0x908) != '\0' || *(char *)(lVar4 + 5) != '\0')) {
      local_3a = local_3a | 0x40;
    }
    if (*(char *)(param_2 + 0xd32) != '\0') {
      local_3a = local_3a | 0x80;
    }
    if (*(char *)(param_2 + 0x480) != '\0') {
      local_39 = local_39 | 2;
    }
    if (*(char *)(lVar4 + 4) != '\0') {
      local_39 = local_39 | 4;
    }
    if (*(char *)(lVar1 + 0x2a8) != '\0') {
      local_39 = local_39 | 8;
    }
    if ((*(char *)(param_1 + 0x908) == '\0') ||
       ((*(char *)(param_1 + 0x4913) != '\0' && (*(char *)(param_1 + 0x491e) == '\0')))) {
      local_39 = local_39 | 0x10;
    }
    portMemCopy(param_3,3,&local_3b,3);
  }
  return;
}


// ===== 003bea50 deviceCtrlCmdFbGetCaps_IMPL =====

undefined8 deviceCtrlCmdFbGetCaps_IMPL(long param_1,int *param_2)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  undefined8 uVar5;
  
  uVar1 = *(undefined8 *)(param_2 + 2);
  lVar2 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar4 = rmapiLockIsOwner();
  if (cVar4 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/mem_mgr/mem_mgr_ctrl.c",0xe2);
    return 0x2f;
  }
  if (*param_2 == 3) {
    lVar3 = *(long *)(lVar2 + 0x1b78);
    uVar5 = 0x3d;
    if (lVar3 != 0) {
      memmgrGetDeviceCaps_constprop_0(lVar2,lVar3,uVar1);
      uVar5 = 0;
    }
    return uVar5;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_ctrl.c",0xe7,"deviceCtrlCmdFbGetCaps_IMPL",4,
               "NVRM: size mismatch: client 0x%x rm 0x%x\n",*param_2,3);
  return 0x1f;
}


// ===== 003beb30 deviceCtrlCmdFbGetCapsV2_IMPL =====

undefined8 deviceCtrlCmdFbGetCapsV2_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  undefined8 uVar4;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 != '\0') {
    lVar2 = *(long *)(lVar1 + 0x1b78);
    uVar4 = 0x3d;
    if (lVar2 != 0) {
      memmgrGetDeviceCaps_constprop_0(lVar1,lVar2,param_2);
      uVar4 = 0;
    }
    return uVar4;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/mem_mgr/mem_mgr_ctrl.c",0x101);
  return 0x2f;
}


// ===== 003bebb0 deviceCtrlCmdSetDefaultVidmemPhysicality_IMPL =====

undefined8 deviceCtrlCmdSetDefaultVidmemPhysicality_IMPL(long param_1,uint *param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    uVar2 = 0x1f;
    if (*param_2 < 4) {
      *(uint *)(param_1 + 0x1d4) = *param_2;
      uVar2 = 0;
    }
    return uVar2;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/mem_mgr/mem_mgr_ctrl.c",0x116);
  return 0x2f;
}


// ===== 003bec0a subdeviceCtrlCmdFbGetBar1Offset_IMPL.cold =====

void subdeviceCtrlCmdFbGetBar1Offset_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003bec20 subdeviceCtrlCmdFbGetBar1Offset_IMPL =====

undefined8 subdeviceCtrlCmdFbGetBar1Offset_IMPL(long param_1,long *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long *plVar3;
  code *pcVar4;
  char cVar5;
  long lVar6;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  plVar3 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
  uVar1 = *(undefined4 *)(*plVar3 + 0x48);
  uVar2 = *(undefined4 *)(plVar3[3] + 0x10);
  cVar5 = rmapiLockIsOwner();
  if ((cVar5 != '\0') && (cVar5 = rmGpuLockIsOwner(), cVar5 != '\0')) {
    lVar6 = CliFindMappingInClient(uVar1,uVar2,*param_2);
    if (lVar6 != 0) {
      if ((*(undefined8 **)(lVar6 + 0x50))[1] == 1) {
        param_2[1] = (*(long *)**(undefined8 **)(lVar6 + 0x50) - *(long *)(lVar6 + 0x18)) + *param_2
        ;
        return 0;
      }
      nvAssertFailedNoLog("pCpuMapping->pPrivate->memArea.numRanges == 1",
                          "src/kernel/gpu/mem_mgr/mem_mgr_ctrl.c",0x147);
    }
    return 0x1f;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/mem_mgr/mem_mgr_ctrl.c",0x141);
  return 0x2f;
}


// ===== 003bed00 subdeviceCtrlCmdFbIsKind_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdFbIsKind_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  char cVar3;
  undefined1 uVar4;
  
  lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x1b78);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/mem_mgr/mem_mgr_ctrl.c",0x161);
    return 0x2f;
  }
  uVar1 = *param_2;
  if (uVar1 == 4) {
    uVar4 = (**(code **)(lVar2 + 0x2a8))(lVar2,8,param_2[1]);
  }
  else if (uVar1 < 5) {
    if (uVar1 == 2) {
      uVar4 = (**(code **)(lVar2 + 0x2a8))(lVar2,6,param_2[1]);
    }
    else if (uVar1 == 3) {
      uVar4 = (**(code **)(lVar2 + 0x2a8))(lVar2,7,param_2[1]);
    }
    else if (uVar1 == 0) {
      uVar4 = (**(code **)(lVar2 + 0x2a8))(lVar2,9,param_2[1]);
    }
    else {
      uVar4 = (**(code **)(lVar2 + 0x2a8))(lVar2,5,param_2[1]);
    }
  }
  else if (uVar1 == 7) {
    uVar4 = (**(code **)(lVar2 + 0x2a8))(lVar2,3,param_2[1]);
  }
  else if (uVar1 < 8) {
    if (uVar1 == 5) {
      uVar4 = (**(code **)(lVar2 + 0x2a8))(lVar2,1,param_2[1]);
    }
    else {
      uVar4 = (**(code **)(lVar2 + 0x2a8))(lVar2,2,param_2[1]);
    }
  }
  else {
    if (uVar1 != 8) {
      nvAssertFailedNoLog(&DAT_00d5104e,"src/kernel/gpu/mem_mgr/mem_mgr_ctrl.c",0x184);
      return 0x1f;
    }
    uVar4 = (**(code **)(lVar2 + 0x2a8))(lVar2,4,param_2[1]);
  }
  *(undefined1 *)(param_2 + 2) = uVar4;
  return 0;
}


// ===== 003beef0 subdeviceCtrlCmdFbGetMemAlignment_IMPL =====

int subdeviceCtrlCmdFbGetMemAlignment_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long *plVar2;
  undefined8 uVar3;
  long lVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 local_88;
  ulong local_80;
  undefined8 local_78;
  undefined4 *local_70;
  undefined4 *local_68;
  undefined4 *local_60;
  undefined8 *local_58;
  ulong *local_50;
  undefined4 *local_48;
  undefined4 *local_40;
  undefined4 *local_38;
  undefined8 local_30;
  
  plVar2 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
  uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar4 = plVar2[2];
  uVar1 = *(undefined4 *)(*plVar2 + 0x48);
  uVar6 = vidmemGetHeap_IMPL(uVar3,*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8),0,0);
  local_88 = *(undefined8 *)(param_2 + 4);
  local_30 = 0;
  local_80 = (ulong)(uint)param_2[10];
  local_58 = &local_88;
  local_50 = &local_80;
  local_48 = param_2 + 1;
  local_40 = param_2 + 0xd;
  local_78 = CONCAT44(param_2[2],*param_2);
  local_70 = param_2 + 6;
  local_68 = param_2 + 7;
  local_60 = param_2 + 8;
  local_38 = param_2 + 0xb;
  iVar5 = heapAllocHint_IMPL(uVar3,uVar6,uVar1,(int)lVar4,&local_78);
  if (iVar5 == 0) {
    param_2[0xc] = 0;
    param_2[10] = (int)local_80;
    *(undefined8 *)(param_2 + 4) = local_88;
    param_2[9] = (int)local_30;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_ctrl.c",0x1b2,
               "subdeviceCtrlCmdFbGetMemAlignment_IMPL",4,"NVRM: heapAllocHint failed\n");
  return iVar5;
}


// ===== 003bf030 __pfx_subdeviceCtrlCmdFbGetFBRegionInfo_IMPL =====

byte __pfx_subdeviceCtrlCmdFbGetFBRegionInfo_IMPL(long param_1,uint *param_2)

{
  uint *puVar1;
  long lVar2;
  char cVar3;
  uint *puVar4;
  long lVar5;
  int iVar6;
  undefined8 *puVar7;
  long lVar8;
  uint uVar9;
  ulong uVar10;
  
  lVar8 = *(long *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x1b78);
  cVar3 = rmapiLockIsOwner();
  if ((cVar3 == '\0') || (cVar3 = rmGpuLockIsOwner(), cVar3 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/mem_mgr/mem_mgr_ctrl.c",0x291);
    return 0x2f;
  }
  *param_2 = 0;
  if (*(int *)(lVar8 + 0x858) == 0) {
    return 0x56;
  }
  puVar7 = (undefined8 *)(lVar8 + 0x860);
  uVar9 = 0;
  iVar6 = 0;
  do {
    if ((*(char *)(puVar7 + 3) == '\0') && (*(char *)((long)puVar7 + 0x23) == '\0')) {
      uVar10 = (ulong)uVar9;
      puVar4 = param_2 + uVar10 * 0xe;
      puVar1 = (uint *)((long)param_2 + uVar10 * 0x38 + 0x12);
      *(undefined8 *)(puVar4 + 2) = *puVar7;
      *(undefined8 *)(puVar4 + 4) = puVar7[1];
      *(undefined8 *)(puVar4 + 6) = puVar7[2];
      puVar4[8] = *(uint *)((long)puVar7 + 0x1c);
      *(undefined1 *)(puVar4 + 9) = *(undefined1 *)(puVar7 + 4);
      *(undefined1 *)((long)puVar4 + 0x25) = *(undefined1 *)((long)puVar7 + 0x21);
      *(undefined1 *)((long)puVar4 + 0x26) = *(undefined1 *)((long)puVar7 + 0x22);
      if (((int)puVar1 - (int)puVar4 & 1U) == 0) goto LAB_003bf140;
      *(undefined1 *)((long)puVar4 + 0x27) = 0;
      for (puVar4 = (uint *)((long)puVar4 + 1); puVar4 != puVar1;
          puVar4 = (uint *)((long)puVar4 + 2)) {
LAB_003bf140:
        *(undefined1 *)((long)puVar4 + 0x27) = 0;
        *(undefined1 *)(puVar4 + 10) = 0;
      }
      if (*(char *)((long)puVar7 + 0x21) == '\0') {
        *(undefined1 *)((long)param_2 + uVar10 * 0x38 + 0x2f) = 1;
        *(undefined1 *)(param_2 + uVar10 * 0xe + 0xb) = 1;
        *(undefined1 *)((long)param_2 + uVar10 * 0x38 + 0x2a) = 1;
      }
      uVar9 = uVar9 + 1;
      *param_2 = uVar9;
      if (*(uint *)(lVar8 + 0x858) <= iVar6 + 1U) {
LAB_003bf1b3:
        if (uVar9 == 0x10) {
          return 0;
        }
        lVar8 = (long)param_2 + (ulong)uVar9 * 0x38 + 0x12;
        do {
          *(undefined8 *)(lVar8 + -10) = 0;
          *(undefined8 *)(lVar8 + -2) = 0;
          *(undefined8 *)(lVar8 + 6) = 0;
          *(undefined4 *)(lVar8 + 0xe) = 0;
          *(undefined1 *)(lVar8 + 0x14) = 0;
          *(undefined2 *)(lVar8 + 0x12) = 0;
          lVar2 = lVar8 + -0x12;
          do {
            lVar5 = lVar2;
            *(undefined1 *)(lVar5 + 0x27) = 1;
            *(undefined1 *)(lVar5 + 0x28) = 1;
            lVar2 = lVar5 + 2;
          } while (lVar5 + 2 != lVar8);
          lVar8 = lVar5 + 0x3a;
        } while (lVar8 != (long)param_2 + ((ulong)(0xf - uVar9) + (ulong)uVar9) * 0x38 + 0x4a);
        return -(uVar9 == 0) & 0x56;
      }
      if (uVar9 == 0x10) {
        return 0;
      }
    }
    else if (*(uint *)(lVar8 + 0x858) <= iVar6 + 1U) goto LAB_003bf1b3;
    iVar6 = iVar6 + 1;
    puVar7 = puVar7 + 5;
  } while( true );
}


// ===== 003bf040 subdeviceCtrlCmdFbGetFBRegionInfo_IMPL =====

byte subdeviceCtrlCmdFbGetFBRegionInfo_IMPL(long param_1,uint *param_2)

{
  uint *puVar1;
  long lVar2;
  char cVar3;
  uint *puVar4;
  long lVar5;
  int iVar6;
  undefined8 *puVar7;
  long lVar8;
  uint uVar9;
  ulong uVar10;
  
  lVar8 = *(long *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x1b78);
  cVar3 = rmapiLockIsOwner();
  if ((cVar3 == '\0') || (cVar3 = rmGpuLockIsOwner(), cVar3 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/mem_mgr/mem_mgr_ctrl.c",0x291);
    return 0x2f;
  }
  *param_2 = 0;
  if (*(int *)(lVar8 + 0x858) == 0) {
    return 0x56;
  }
  puVar7 = (undefined8 *)(lVar8 + 0x860);
  uVar9 = 0;
  iVar6 = 0;
  do {
    if ((*(char *)(puVar7 + 3) == '\0') && (*(char *)((long)puVar7 + 0x23) == '\0')) {
      uVar10 = (ulong)uVar9;
      puVar4 = param_2 + uVar10 * 0xe;
      puVar1 = (uint *)((long)param_2 + uVar10 * 0x38 + 0x12);
      *(undefined8 *)(puVar4 + 2) = *puVar7;
      *(undefined8 *)(puVar4 + 4) = puVar7[1];
      *(undefined8 *)(puVar4 + 6) = puVar7[2];
      puVar4[8] = *(uint *)((long)puVar7 + 0x1c);
      *(undefined1 *)(puVar4 + 9) = *(undefined1 *)(puVar7 + 4);
      *(undefined1 *)((long)puVar4 + 0x25) = *(undefined1 *)((long)puVar7 + 0x21);
      *(undefined1 *)((long)puVar4 + 0x26) = *(undefined1 *)((long)puVar7 + 0x22);
      if (((int)puVar1 - (int)puVar4 & 1U) == 0) goto LAB_003bf140;
      *(undefined1 *)((long)puVar4 + 0x27) = 0;
      for (puVar4 = (uint *)((long)puVar4 + 1); puVar4 != puVar1;
          puVar4 = (uint *)((long)puVar4 + 2)) {
LAB_003bf140:
        *(undefined1 *)((long)puVar4 + 0x27) = 0;
        *(undefined1 *)(puVar4 + 10) = 0;
      }
      if (*(char *)((long)puVar7 + 0x21) == '\0') {
        *(undefined1 *)((long)param_2 + uVar10 * 0x38 + 0x2f) = 1;
        *(undefined1 *)(param_2 + uVar10 * 0xe + 0xb) = 1;
        *(undefined1 *)((long)param_2 + uVar10 * 0x38 + 0x2a) = 1;
      }
      uVar9 = uVar9 + 1;
      *param_2 = uVar9;
      if (*(uint *)(lVar8 + 0x858) <= iVar6 + 1U) {
LAB_003bf1b3:
        if (uVar9 == 0x10) {
          return 0;
        }
        lVar8 = (long)param_2 + (ulong)uVar9 * 0x38 + 0x12;
        do {
          *(undefined8 *)(lVar8 + -10) = 0;
          *(undefined8 *)(lVar8 + -2) = 0;
          *(undefined8 *)(lVar8 + 6) = 0;
          *(undefined4 *)(lVar8 + 0xe) = 0;
          *(undefined1 *)(lVar8 + 0x14) = 0;
          *(undefined2 *)(lVar8 + 0x12) = 0;
          lVar2 = lVar8 + -0x12;
          do {
            lVar5 = lVar2;
            *(undefined1 *)(lVar5 + 0x27) = 1;
            *(undefined1 *)(lVar5 + 0x28) = 1;
            lVar2 = lVar5 + 2;
          } while (lVar5 + 2 != lVar8);
          lVar8 = lVar5 + 0x3a;
        } while (lVar8 != (long)param_2 + ((ulong)(0xf - uVar9) + (ulong)uVar9) * 0x38 + 0x4a);
        return -(uVar9 == 0) & 0x56;
      }
      if (uVar9 == 0x10) {
        return 0;
      }
    }
    else if (*(uint *)(lVar8 + 0x858) <= iVar6 + 1U) goto LAB_003bf1b3;
    iVar6 = iVar6 + 1;
    puVar7 = puVar7 + 5;
  } while( true );
}


// ===== 003bf250 subdeviceCtrlCmdGbGetSemaphoreSurfaceLayout_IMPL =====

undefined8 subdeviceCtrlCmdGbGetSemaphoreSurfaceLayout_IMPL(long param_1,undefined8 *param_2)

{
  long lVar1;
  uint uVar2;
  
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x1b78);
  *(undefined4 *)(param_2 + 3) = 0;
  uVar2 = (uint)(*(char *)(lVar1 + 0xd30) != '\0');
  *(uint *)(param_2 + 3) = uVar2;
  if (*(char *)(lVar1 + 0xd31) != '\0') {
    *(uint *)(param_2 + 3) = uVar2 | 2;
  }
  param_2[1] = 0x10;
  *param_2 = 0x18;
  param_2[2] = 0x20;
  return 0;
}


// ===== 003bf2b0 subdeviceCtrlCmdFbGetCpuCoherentRange_IMPL =====

undefined8 subdeviceCtrlCmdFbGetCpuCoherentRange_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  if (*(char *)(g_pSys + 0x7e) != '\0') {
    lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
    uVar2 = kmemsysGetCpuCoherentFbRange_IMPL
                      (lVar1,*(undefined8 *)(lVar1 + 0x1b70),param_2,param_2 + 8);
    return uVar2;
  }
  nvCheckFailedNoLog(1,"pSys->getProperty(pSys, PDB_PROP_SYS_ENABLE_RM_TEST_ONLY_CODE)",
                     "src/kernel/gpu/mem_mgr/mem_mgr_ctrl.c",0x30d);
  return 0x56;
}


// ===== 003bf310 memmgrInitBaseFbRegions_FWCLIENT =====

undefined8 memmgrInitBaseFbRegions_FWCLIENT(undefined8 param_1,long param_2)

{
  undefined1 uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  ulong uVar8;
  uint uVar9;
  long *plVar10;
  ulong uVar11;
  uint uVar12;
  
  lVar6 = gpuGetGspStaticInfo();
  if (lVar6 == 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_gsp_client.c",0x36,
                 "memmgrInitBaseFbRegions_FWCLIENT",4,"NVRM: Missing static info.\n");
    return 0x40;
  }
  uVar12 = *(uint *)(lVar6 + 0x140);
  if (uVar12 == 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_gsp_client.c",0x3e,
                 "memmgrInitBaseFbRegions_FWCLIENT",4,
                 "NVRM: Missing FB region table in GSP Init arguments.\n");
  }
  else {
    if (uVar12 < 0x11) {
      *(undefined8 *)(param_2 + 0x850) = 0;
      *(undefined8 *)(param_2 + 0x828) = 0;
      uVar12 = 0;
      if (*(int *)(lVar6 + 0x140) != 0) {
        plVar10 = (long *)(lVar6 + 0x148);
        uVar9 = 0;
        plVar7 = (long *)(param_2 + 0x860);
        do {
          lVar2 = *plVar10;
          *plVar7 = lVar2;
          lVar3 = plVar10[1];
          plVar7[1] = lVar3;
          uVar1 = *(undefined1 *)((long)plVar10 + 0x1e);
          *(undefined1 *)((long)plVar7 + 0x23) = 0;
          *(undefined1 *)((long)plVar7 + 0x22) = uVar1;
          *(int *)((long)plVar7 + 0x1c) = (int)plVar10[3];
          *(undefined1 *)(plVar7 + 4) = *(undefined1 *)((long)plVar10 + 0x1c);
          *(undefined1 *)((long)plVar7 + 0x21) = *(undefined1 *)((long)plVar10 + 0x1d);
          lVar4 = plVar10[2];
          *(undefined1 *)((long)plVar7 + 0x24) = 1;
          plVar7[2] = lVar4;
          lVar5 = plVar10[2];
          if (lVar5 != 0) {
            *(long *)(param_2 + 0x850) = *(long *)(param_2 + 0x850) + lVar4;
          }
          else {
            *(long *)(param_2 + 0x828) = (lVar3 + 1 + *(long *)(param_2 + 0x828)) - lVar2;
          }
          *(bool *)(plVar7 + 3) = lVar5 != 0;
          uVar9 = uVar9 + 1;
          plVar10 = plVar10 + 7;
          plVar7 = plVar7 + 5;
          uVar12 = *(uint *)(lVar6 + 0x140);
        } while (uVar9 < uVar12);
      }
      *(uint *)(param_2 + 0x858) = uVar12;
      uVar8 = *(long *)(lVar6 + 0x540) + 0xfffffU >> 0x14;
      *(ulong *)(param_2 + 0x830) = uVar8;
      uVar11 = *(long *)(param_2 + 0x868 + (ulong)(*(int *)(lVar6 + 0x140) - 1) * 0x28) + 0xfffffU
               >> 0x14;
      *(ulong *)(param_2 + 0x838) = uVar11;
      if (uVar11 < uVar8) {
        nvAssertFailedNoLog("pMemoryManager->Ram.fbAddrSpaceSizeMb >= pMemoryManager->Ram.fbTotalMemSizeMb"
                            ,"src/kernel/gpu/mem_mgr/mem_mgr_gsp_client.c",0x79);
      }
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_gsp_client.c",0x7c,
                   "memmgrInitBaseFbRegions_FWCLIENT",1,"NVRM: FB Memory from Static info:\n");
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_gsp_client.c",0x7d,
                   "memmgrInitBaseFbRegions_FWCLIENT",1,
                   "NVRM: Reserved Memory=0x%llx, Usable Memory=0x%llx\n",
                   *(undefined8 *)(param_2 + 0x850),*(undefined8 *)(param_2 + 0x828));
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_gsp_client.c",0x7f,
                   "memmgrInitBaseFbRegions_FWCLIENT",1,
                   "NVRM: fbTotalMemSizeMb=0x%llx, fbAddrSpaceSizeMb=0x%llx\n",
                   *(undefined8 *)(param_2 + 0x830),*(undefined8 *)(param_2 + 0x838));
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_gsp_client.c",0x46,
                 "memmgrInitBaseFbRegions_FWCLIENT",4,
                 "NVRM: Static info struct has more FB regions (%u) than FB supports (%u).\n",uVar12
                 ,0x10);
  }
  return 0x3b;
}


// ===== 003bf5c0 _memmgrWalkHeap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _memmgrWalkHeap(long param_1,long param_2,long param_3)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  undefined8 *puVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  long *local_c0;
  long local_b8;
  undefined4 local_b0;
  undefined8 local_a0;
  long local_78;
  undefined4 local_48;
  
  lVar7 = *(long *)(&DAT_00001b90 + param_1);
  for (puVar4 = *(undefined8 **)(param_2 + 0xc20); puVar4 != (undefined8 *)0x0;
      puVar4 = (undefined8 *)*puVar4) {
    (**(code **)(param_3 + 0x68))(param_1,param_3,puVar4[2]);
  }
  iVar3 = memdescGetAddressSpace(*(undefined8 *)(lVar7 + 0x7c90));
  lVar7 = *(long *)(param_2 + 0xc00);
  if (iVar3 == 2) {
    lVar2 = *(long *)(param_2 + 0x490);
    lVar5 = *(long *)(param_2 + 0x498);
    lVar6 = *(long *)(*(long *)(&DAT_00001b90 + param_1) + 0x4668);
    uVar1 = *(uint *)(*(long *)(&DAT_00001b90 + param_1) + 0x46e4);
    if (lVar7 == 0) {
      lVar7 = lVar6 - lVar2;
      iVar3 = memdescCreate(param_2 + 0xc00,param_1,lVar7,0,1,2,1,0);
      if (iVar3 != 0) {
        nvAssertOkFailedNoLog
                  (iVar3,
                   "memdescCreate(&pMemoryManager->fbsrReservedRanges[FBSR_RESERVED_INST_MEMORY_BEFORE_BAR2PTE], pGpu, size, 0, NV_TRUE, ADDR_FBMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_NONE)"
                   ,"src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0x133);
        goto LAB_003bf9b2;
      }
      memdescDescribe(*(undefined8 *)(param_2 + 0xc00),2,*(undefined8 *)(param_2 + 0x490),lVar7);
    }
    lVar5 = lVar5 + lVar2;
    if (*(long *)(param_2 + 0xc08) == 0) {
      lVar6 = lVar6 + (ulong)uVar1;
      uVar9 = 0;
      lVar7 = lVar5 - lVar6;
      uVar8 = 1;
      iVar3 = memdescCreate(param_2 + 0xc08,param_1,lVar7,0,1,2);
      if (iVar3 != 0) {
        nvAssertOkFailedNoLog
                  (iVar3,
                   "memdescCreate(&pMemoryManager->fbsrReservedRanges[FBSR_RESERVED_INST_MEMORY_AFTER_BAR2PTE], pGpu, size, 0, NV_TRUE, ADDR_FBMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_NONE)"
                   ,"src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0x141,uVar8,uVar9);
        goto LAB_003bf9b2;
      }
      memdescDescribe(*(undefined8 *)(param_2 + 0xc08),2,lVar6,lVar7);
    }
    if ((*(int *)(param_2 + 0xd40) == 0) && (*(char *)(param_1 + 0x909) != '\0')) {
      lVar7 = *(long *)(*(long *)(param_1 + 0x1ba8) + 0xa78);
      puVar4 = (undefined8 *)rmapiGetInterface(4);
      lVar7 = ((*(long *)(lVar7 + 0x68) + *(long *)(lVar7 + 0x60)) - lVar5) +
              *(long *)(lVar7 + 0xc0);
      if (*(char *)(*(long *)(param_1 + 0x1b70) + 0x2a0) != '\0') {
        iVar3 = (**(code **)(param_1 + 0x3b90))
                          (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                           *(undefined4 *)(param_1 + 0x3b38),0x801306,&local_b8,0x50);
        lVar7 = lVar7 + local_b8;
        if (iVar3 != 0) {
          nvAssertOkFailedNoLog
                    (iVar3,
                     "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalDevice, NV0080_CTRL_CMD_FB_GET_COMPBIT_STORE_INFO, &compbitStoreInfoParams, sizeof(compbitStoreInfoParams))"
                     ,"src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0x16c);
          goto LAB_003bf9b2;
        }
      }
      local_c0 = &local_b8;
      portMemSet(local_c0,0,0x80);
      local_48 = 0;
      local_b8 = 0xdeaf0006;
      local_a0 = 0x8000000002000000;
      local_b0 = 0;
      local_78 = lVar7;
      iVar3 = (*(code *)*puVar4)(puVar4,*(undefined4 *)(param_2 + 0xd10),
                                 *(undefined4 *)(param_2 + 0xd14),param_2 + 0xd40,0x3e,local_c0,0x80
                                );
      if (iVar3 != 0) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0x18d,
                     "_memmgrAllocFbsrReservedRanges",4,
                     "NVRM: Failed to allocate FBSR memory for GSP heap: %d\n",iVar3);
LAB_003bf9b2:
        nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0x195,
                     "_memmgrAllocFbsrReservedRanges",4,
                     "NVRM: Failure during allocation of FBSR Reserved ranges: %d\n",iVar3);
        if (*(long *)(param_2 + 0xc00) != 0) {
          memdescDestroy();
        }
        if (*(long *)(param_2 + 0xc08) != 0) {
          memdescDestroy();
        }
        *(undefined8 *)(param_2 + 0xc00) = 0;
        *(undefined8 *)(param_2 + 0xc08) = 0;
        nvCheckOkFailedNoLog
                  (4,iVar3,"_memmgrAllocFbsrReservedRanges(pGpu, pMemoryManager)",
                   "src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0x1c2);
        return iVar3;
      }
    }
    (**(code **)(param_3 + 0x68))(param_1,param_3,*(undefined8 *)(param_2 + 0xc00));
    (**(code **)(param_3 + 0x68))(param_1,param_3,*(undefined8 *)(param_2 + 0xc08));
  }
  else {
    if (lVar7 == 0) {
      uVar8 = *(undefined8 *)(param_2 + 0x498);
      iVar3 = memdescCreate(param_2 + 0xc00,param_1,uVar8,0,1,2,1,0);
      if (iVar3 != 0) {
        nvAssertOkFailedNoLog
                  (iVar3,
                   "memdescCreate(&pMemoryManager->fbsrReservedRanges[FBSR_RESERVED_INST_MEMORY_BEFORE_BAR2PTE], pGpu, size, 0, NV_TRUE, ADDR_FBMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_NONE)"
                   ,"src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0x1d1);
        return iVar3;
      }
      memdescDescribe(*(undefined8 *)(param_2 + 0xc00),2,*(undefined8 *)(param_2 + 0x490),uVar8);
      lVar7 = *(long *)(param_2 + 0xc00);
    }
    (**(code **)(param_3 + 0x68))(param_1,param_3,lVar7);
  }
  return 0;
}


// ===== 003bfad0 memmgrAddMemNode_IMPL =====

undefined8 memmgrAddMemNode_IMPL(undefined8 param_1,long param_2,long param_3,undefined1 param_4)

{
  long lVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)portMemAllocNonPaged(0x18);
  if (puVar2 != (undefined8 *)0x0) {
    *puVar2 = 0;
    puVar2[2] = param_3;
    *(undefined1 *)(puVar2 + 1) = param_4;
    if (*(char *)(param_3 + 100) == '\0') {
      lVar1 = *(long *)(param_2 + 0xc20);
    }
    else {
      memdescAddRef(param_3);
      *(char *)(param_3 + 100) = *(char *)(param_3 + 100) + '\x01';
      lVar1 = *(long *)(param_2 + 0xc20);
    }
    if (lVar1 == 0) {
      *(undefined8 **)(param_2 + 0xc20) = puVar2;
      *(undefined8 **)(param_2 + 0xc28) = puVar2;
    }
    else {
      **(undefined8 **)(param_2 + 0xc28) = puVar2;
      *(undefined8 **)(param_2 + 0xc28) = puVar2;
    }
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0x1fc,"memmgrAddMemNode_IMPL",3,
               "NVRM: can\'t allocate FB_MEM_NODE, err:0x%x!\n",0x51);
  nvAssertOkFailedNoLog(0x51,"rmStatus","src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0x1fd);
  return 0x51;
}


// ===== 003bfbd0 memmgrRemoveMemNodes_IMPL =====

void memmgrRemoveMemNodes_IMPL(undefined8 param_1,long param_2)

{
  long *plVar1;
  long *plVar2;
  
  plVar2 = *(long **)(param_2 + 0xc20);
  while (plVar2 != (long *)0x0) {
    while (plVar1 = (long *)*plVar2, *(char *)(plVar2[2] + 100) != '\0') {
      memdescFree();
      memdescDestroy(plVar2[2]);
      portMemFree(plVar2);
      plVar2 = plVar1;
      if (plVar1 == (long *)0x0) goto LAB_003bfc46;
    }
    if ((char)plVar2[1] != '\0') {
      memdescDestroy();
    }
    portMemFree(plVar2);
    plVar2 = plVar1;
  }
LAB_003bfc46:
  *(undefined8 *)(param_2 + 0xc20) = 0;
  *(undefined8 *)(param_2 + 0xc28) = 0;
  return;
}


// ===== 003bfc80 memmgrAddMemNodes_IMPL =====

undefined8 memmgrAddMemNodes_IMPL(long param_1,undefined8 param_2,char param_3)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char cVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x1b78) + 0x478);
  lVar8 = *(long *)(lVar1 + 0x88);
  do {
    lVar2 = *(long *)(lVar8 + 0x80);
    iVar6 = *(int *)(lVar8 + 4);
    if ((lVar2 != 0) && (iVar6 != -1)) {
      uVar3 = *(undefined8 *)(lVar2 + 8);
      uVar4 = *(undefined8 *)(lVar2 + 0x30);
      uVar7 = memdescGetPhysAddr(lVar2,1,0);
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0x239,"memmgrAddMemNodes_IMPL",1,
                   "NVRM: pAllocMemDesc base 0x%llx (size 0x%llx) block owner 0x%X memdesc flags 0x%llx\n"
                   ,uVar7,uVar4,iVar6,uVar3);
      cVar5 = memdescGetFlag(lVar2,0x4000);
      if (cVar5 == '\0') {
        iVar6 = *(int *)(lVar8 + 4);
        if (iVar6 == -0x2150fffe) {
          if (param_3 != '\0') {
LAB_003bfe72:
            cVar5 = memdescGetFlag(lVar2,4);
            if (cVar5 == '\0') goto LAB_003bfd96;
          }
        }
        else if ((iVar6 == -0x2150ffff) || (iVar6 == -0x2150fffc)) {
          if (param_3 == '\0') goto LAB_003bfe72;
          goto LAB_003bfd96;
        }
      }
      else {
LAB_003bfd96:
        iVar6 = memdescGetAddressSpace(lVar2);
        if ((iVar6 == 2) || (iVar6 = memdescGetAddressSpace(lVar2), iVar6 == 1)) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0x254,"memmgrAddMemNodes_IMPL",1,
                       "NVRM: pAllocMemDesc being saved\n");
          iVar6 = memmgrAddMemNode_IMPL(param_1,param_2,lVar2,0);
          if (iVar6 != 0) {
            nvCheckOkFailedNoLog
                      (4,0x51,"memmgrAddMemNode(pGpu, pMemoryManager, pAllocMemDesc, NV_FALSE)",
                       "src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0x255);
            nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0x262,"memmgrAddMemNodes_IMPL",
                         4,"NVRM: Failure during memmgrAddMemNodes: %d\n",0x51);
            memmgrRemoveMemNodes_IMPL(param_1,param_2);
            return 0x51;
          }
        }
      }
    }
    lVar8 = *(long *)(lVar8 + 0xc0);
    if (*(long *)(lVar1 + 0x88) == lVar8) {
      return 0;
    }
  } while( true );
}


// ===== 003bfec0 memmgrSavePowerMgmtState_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong memmgrSavePowerMgmtState_KERNEL(long param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  int iVar3;
  ulong uVar4;
  undefined8 extraout_RDX;
  uint uVar5;
  long lVar6;
  undefined8 uVar7;
  uint local_4c;
  long *local_48;
  undefined8 local_40 [2];
  
  if ((*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) == '\0') && (*(char *)(param_1 + 0x44d) == '\0')
     ) {
    uVar5 = *(uint *)(param_2 + 0xbf8);
    if (*(long *)(param_2 + 0xbf0) != 0) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0x46,
                   "memmgrSavePowerMgmtState_KERNEL",4,
                   "NVRM: !!!!! Calling Suspend on a suspended GPU or ");
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0x47,
                   "memmgrSavePowerMgmtState_KERNEL",4,
                   "NVRM: the previous Resume call might have failed !!!!!!\n");
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0x49,
                   "memmgrSavePowerMgmtState_KERNEL",4,
                   "NVRM: !!!!! Trying a suspend anyway !!!!!!\n");
    }
    *(undefined8 *)(param_2 + 0xbf0) = 0;
    iVar3 = memmgrAddMemNodes_IMPL(param_1,param_2,*(undefined1 *)(param_1 + 0x493));
    if (iVar3 != 0) {
      local_4c = 0x51;
LAB_003c00af:
      memmgrRemoveMemNodes_IMPL(param_1,param_2);
      return (ulong)local_4c;
    }
    if (*(char *)(param_2 + 0x434) != '\0') {
      local_48 = (long *)0x0;
      lVar6 = *(long *)(*(long *)(param_1 + 0x1b78) + 0x478);
      if (*(char *)(param_1 + 0x493) == '\0') {
        local_4c = pmaBuildPersistentList();
      }
      else {
        local_4c = pmaBuildAllocatedBlocksList(*(undefined8 *)(lVar6 + 0x128),&local_48);
      }
      plVar2 = local_48;
      if (local_4c != 0) {
        if (*(char *)(param_1 + 0x493) == '\0') {
          pmaFreePersistentList(*(undefined8 *)(lVar6 + 0x128),&local_48);
        }
        else {
          pmaFreeAllocatedBlocksList();
        }
        goto LAB_003c00af;
      }
      for (; plVar2 != (long *)0x0; plVar2 = (long *)plVar2[2]) {
        uVar7 = 1;
        local_4c = memdescCreate(local_40,param_1,0x1000,0x10000,1,2,1,0);
        if (local_4c != 0) {
LAB_003c02a1:
          if (*(char *)(param_1 + 0x493) == '\0') {
            pmaFreePersistentList(*(undefined8 *)(lVar6 + 0x128),&local_48,uVar7);
          }
          else {
            pmaFreeAllocatedBlocksList();
          }
          goto LAB_003c00af;
        }
        memdescDescribe(local_40[0],2,*plVar2,(plVar2[1] + 1) - *plVar2);
        iVar3 = memmgrAddMemNode_IMPL(param_1,param_2,local_40[0],1);
        if (iVar3 != 0) {
          local_4c = 0x51;
          uVar7 = extraout_RDX;
          goto LAB_003c02a1;
        }
      }
      if (*(char *)(param_1 + 0x493) == '\0') {
        pmaFreePersistentList(*(undefined8 *)(lVar6 + 0x128),&local_48);
      }
      else {
        pmaFreeAllocatedBlocksList();
      }
    }
    lVar6 = param_2 + (ulong)uVar5 * 8;
    if (uVar5 < 8) {
      do {
        if (((((((*(uint *)(param_2 + 0xbfc) == 0) ||
                ((*(uint *)(param_2 + 0xbfc) >> (uVar5 & 0x1f) & 1) != 0)) &&
               (lVar1 = *(long *)(lVar6 + 0xbb0), lVar1 != 0)) &&
              ((*(char *)(lVar1 + 0x106) != '\0' &&
               (iVar3 = (**(code **)(lVar1 + 0x58))(param_1,lVar1,0), iVar3 == 0)))) &&
             ((iVar3 = _memmgrWalkHeap(param_1,param_2,lVar1), iVar3 == 0 &&
              ((iVar3 = (**(code **)(lVar1 + 0x60))(param_1,lVar1), iVar3 == 0 &&
               (iVar3 = (**(code **)(lVar1 + 0x58))(param_1,lVar1,1), iVar3 == 0)))))) &&
            (iVar3 = _memmgrWalkHeap(param_1,param_2,lVar1), iVar3 == 0)) &&
           (iVar3 = (**(code **)(lVar1 + 0x60))(param_1,lVar1), iVar3 == 0)) {
          *(undefined1 *)(lVar1 + 0x105) = 1;
          *(long *)(param_2 + 0xbf0) = lVar1;
          return 0;
        }
        uVar5 = uVar5 + 1;
        lVar6 = lVar6 + 8;
      } while (uVar5 != 8);
    }
  }
  else if ((*(char *)(param_1 + 0x45c) != '\0') && (*(char *)(param_1 + 0x909) != '\0')) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0x3e,"memmgrSavePowerMgmtState_KERNEL",
                 1,"NVRM: Init SC7 SR\n");
    uVar4 = (**(code **)(param_2 + 0x408))(param_1,param_2);
    return uVar4;
  }
  return 0;
}


// ===== 003c0300 memmgrFreeFbsrMemory_KERNEL =====

void memmgrFreeFbsrMemory_KERNEL(undefined8 param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_2 + 0xbf0);
  memmgrRemoveMemNodes_IMPL();
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x90) != 0)) &&
     ((*(int *)(lVar1 + 0x78) - 2U & 0xfffffffd) == 0)) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(lVar1 + 0x90));
    *(undefined8 *)(lVar1 + 0x90) = 0;
    *(undefined8 *)(param_2 + 0xbf0) = 0;
    return;
  }
  *(undefined8 *)(param_2 + 0xbf0) = 0;
  return;
}


// ===== 003c0380 memmgrRestorePowerMgmtState_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrRestorePowerMgmtState_KERNEL(long param_1,long param_2)

{
  int *piVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  
  lVar2 = *(long *)(param_2 + 0xbf0);
  lVar4 = rmapiGetInterface(4);
  if ((*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) != '\0') || (*(char *)(param_1 + 0x44d) != '\0')
     ) {
    return 0;
  }
  LOCK();
  piVar1 = (int *)(concurrentfbRestorePowerMgmtStateAccess + (ulong)*(uint *)(param_1 + 0x7a4) * 4);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (iVar3 != 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0xf4,
                 "memmgrRestorePowerMgmtState_KERNEL",1,"NVRM: Concurrent access");
    return 0;
  }
  if ((lVar2 == 0) || (*(char *)(lVar2 + 0x105) == '\0')) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0xfa,
                 "memmgrRestorePowerMgmtState_KERNEL",4,
                 "NVRM: !!!!! Calling Resume on an active GPU or the previous Suspend call might have failed !!!!!!\n"
                );
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0xfc,
                 "memmgrRestorePowerMgmtState_KERNEL",4,
                 "NVRM: !!!!! So ignoring the resume request !!!!!!\n");
    return 0x40;
  }
  if (*(char *)(param_1 + 0x455) == '\0') {
    iVar3 = (**(code **)(lVar2 + 0x58))(param_1,lVar2,2);
    if (iVar3 != 0) goto LAB_003c05d8;
    iVar3 = _memmgrWalkHeap(param_1,param_2,lVar2);
    if (iVar3 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar3,"_memmgrWalkHeap(pGpu, pMemoryManager, pFbsr)",
                 "src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0x10b);
      goto LAB_003c0461;
    }
  }
  else {
    iVar3 = (**(code **)(lVar2 + 0x58))(param_1,lVar2,3);
    if (iVar3 != 0) {
LAB_003c05d8:
      nvCheckOkFailedNoLog
                (4,iVar3,
                 "fbsrBegin_HAL(pGpu, pFbsr, bIsGpuLost ? FBSR_OP_DESTROY : FBSR_OP_RESTORE)",
                 "src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0x106);
      goto LAB_003c0461;
    }
  }
  iVar3 = (**(code **)(lVar2 + 0x60))(param_1,lVar2);
  if (iVar3 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar3,"fbsrEnd_HAL(pGpu, pFbsr)","src/kernel/gpu/mem_mgr/mem_mgr_pwr_mgmt.c",0x10e)
    ;
  }
LAB_003c0461:
  if (*(int *)(param_2 + 0xd40) != 0) {
    (**(code **)(lVar4 + 0x18))(lVar4,*(undefined4 *)(param_2 + 0xd10));
    *(undefined4 *)(param_2 + 0xd40) = 0;
  }
  memmgrFreeFbsrMemory_KERNEL(param_1,param_2);
  *(undefined1 *)(lVar2 + 0x105) = 0;
  LOCK();
  *(int *)(concurrentfbRestorePowerMgmtStateAccess + (ulong)*(uint *)(param_1 + 0x7a4) * 4) =
       *(int *)(concurrentfbRestorePowerMgmtStateAccess + (ulong)*(uint *)(param_1 + 0x7a4) * 4) +
       -1;
  UNLOCK();
  return iVar3;
}


// ===== 003c0650 memmgrLookupFbRegionByOffset_IMPL =====

ulong * memmgrLookupFbRegionByOffset_IMPL
                  (undefined8 param_1,long param_2,ulong param_3,ulong param_4)

{
  ulong *puVar1;
  ulong *puVar2;
  
  if (*(uint *)(param_2 + 0x858) != 0) {
    puVar2 = (ulong *)(param_2 + 0x860);
    puVar1 = puVar2 + (ulong)*(uint *)(param_2 + 0x858) * 5;
    do {
      if ((*puVar2 <= param_3) && (param_3 <= puVar2[1])) {
        if (param_4 <= puVar2[1]) {
          return puVar2;
        }
        nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_regions.c",0x40,
                     "memmgrLookupFbRegionByOffset_IMPL",3,"NVRM: STRADDLING REGION!\n");
        return puVar2;
      }
      puVar2 = puVar2 + 5;
    } while (puVar2 != puVar1);
  }
  return (ulong *)0x0;
}


// ===== 003c0700 memmgrRegenerateFbRegionPriority_IMPL =====

void memmgrRegenerateFbRegionPriority_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  char *pcVar5;
  long lVar6;
  ulong uVar7;
  uint uVar8;
  
  *(undefined4 *)(param_2 + 0xae0) = 0;
  iVar1 = *(int *)(param_2 + 0x858);
  if (iVar1 != 0) {
    pcVar5 = (char *)(param_2 + 0x878);
    iVar3 = 0;
    do {
      if (*pcVar5 == '\0') {
        uVar8 = *(uint *)(param_2 + 0xae0);
        *(int *)(param_2 + 0xaf8 + (ulong)uVar8 * 4) = iVar3;
        *(uint *)(param_2 + 0xae0) = uVar8 + 1;
      }
      iVar3 = iVar3 + 1;
      pcVar5 = pcVar5 + 0x28;
    } while (iVar3 != iVar1);
    uVar8 = *(uint *)(param_2 + 0xae0);
    if (uVar8 != 0) goto LAB_003c077c;
  }
  nvAssertFailedNoLog("pMemoryManager->Ram.numFBRegionPriority > 0",
                      "src/kernel/gpu/mem_mgr/mem_mgr_regions.c",0x61);
  uVar8 = *(uint *)(param_2 + 0xae0);
LAB_003c077c:
  if (1 < uVar8) {
    uVar7 = 1;
    lVar6 = param_2;
    do {
      if ((uint)uVar7 < uVar8) {
        lVar4 = lVar6;
        do {
          uVar2 = *(uint *)(lVar6 + 0xaf8);
          if (*(uint *)(param_2 + 0x87c + (ulong)uVar2 * 0x28) <
              *(uint *)(param_2 + 0x87c + (ulong)*(uint *)(lVar4 + 0xafc) * 0x28)) {
            *(uint *)(lVar6 + 0xaf8) = *(uint *)(lVar4 + 0xafc);
            *(uint *)(lVar4 + 0xafc) = uVar2;
          }
          lVar4 = lVar4 + 4;
        } while (lVar4 != param_2 + 4 + ((uVar7 - 1) + (ulong)((uVar8 - 1) - (uint)uVar7)) * 4);
      }
      uVar7 = uVar7 + 1;
      lVar6 = lVar6 + 4;
    } while (uVar7 != uVar8);
  }
  return;
}


// ===== 003c08c0 memmgrInsertFbRegion_IMPL =====

ulong memmgrInsertFbRegion_IMPL(undefined8 param_1,long param_2,ulong *param_3)

{
  long lVar1;
  long lVar2;
  ulong *puVar3;
  ulong uVar4;
  undefined8 *puVar5;
  ulong uVar6;
  undefined8 *puVar7;
  ulong uVar8;
  uint uVar9;
  ulong uVar10;
  uint uVar11;
  uint uVar12;
  
  uVar9 = *(uint *)(param_2 + 0x858);
  uVar11 = uVar9;
  if (uVar9 != 0) {
    puVar3 = (ulong *)(param_2 + 0x860);
    uVar12 = 0;
    do {
      uVar11 = uVar12;
      if ((*puVar3 <= *param_3) && (param_3[1] <= puVar3[1])) {
        if (uVar11 < uVar9) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_regions.c",0xb9,"memmgrInsertFbRegion_IMPL",1
                       ,"NVRM: New Region belongs to FB Region 0x%x\n",uVar11);
          goto LAB_003c095f;
        }
        break;
      }
      uVar12 = uVar11 + 1;
      puVar3 = puVar3 + 5;
      uVar11 = uVar9;
    } while (uVar12 != uVar9);
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_regions.c",0xb3,"memmgrInsertFbRegion_IMPL",4,
               "NVRM: New Region does not belong to any existing FB Regions\n");
  nvAssertFailedNoLog(&DAT_00d51b02,"src/kernel/gpu/mem_mgr/mem_mgr_regions.c",0xb5);
LAB_003c095f:
  uVar10 = (ulong)uVar11;
  lVar1 = param_2 + uVar10 * 0x28;
  if (*(ulong *)(lVar1 + 0x860) == *param_3) {
    uVar4 = param_3[1];
    if (*(ulong *)(lVar1 + 0x868) == uVar4) {
      *(ulong *)(lVar1 + 0x868) = uVar4;
      *(ulong *)(lVar1 + 0x870) = param_3[2];
      *(ulong *)(lVar1 + 0x878) = param_3[3];
      *(ulong *)(lVar1 + 0x880) = param_3[4];
    }
    else {
      if (*(ulong *)(lVar1 + 0x868) <= uVar4) goto LAB_003c0990;
      uVar9 = *(uint *)(param_2 + 0x858);
      if (0xf < uVar9) {
        nvAssertFailedNoLog("pMemoryManager->Ram.numFBRegions < MAX_FB_REGIONS",
                            "src/kernel/gpu/mem_mgr/mem_mgr_regions.c",0x83);
        uVar9 = *(uint *)(param_2 + 0x858);
      }
      if (uVar11 < uVar9) {
        uVar4 = (ulong)uVar9;
        uVar6 = (ulong)(uVar9 - 1);
        puVar7 = (undefined8 *)(param_2 + 0x860 + uVar4 * 0x28);
        do {
          puVar5 = puVar7 + -5;
          *puVar7 = puVar7[uVar4 * -5 + uVar6 * 5];
          puVar7[1] = puVar7[uVar4 * -5 + uVar6 * 5 + 1];
          puVar7[2] = puVar7[uVar4 * -5 + uVar6 * 5 + 2];
          puVar7[3] = puVar7[uVar4 * -5 + uVar6 * 5 + 3];
          puVar7[4] = puVar7[uVar4 * -5 + uVar6 * 5 + 4];
          puVar7 = puVar5;
        } while (puVar5 != (undefined8 *)
                           (param_2 + 0x838 + uVar4 * 0x28 + (ulong)((uVar9 - uVar11) - 1) * -0x28))
        ;
      }
      *(uint *)(param_2 + 0x858) = uVar9 + 1;
      *(ulong *)(param_2 + 0x860 + uVar10 * 0x28) = *param_3;
      *(ulong *)(param_2 + 0x868 + uVar10 * 0x28) = param_3[1];
      *(ulong *)(param_2 + 0x870 + uVar10 * 0x28) = param_3[2];
      *(ulong *)(param_2 + 0x878 + uVar10 * 0x28) = param_3[3];
      *(ulong *)(param_2 + 0x880 + uVar10 * 0x28) = param_3[4];
      *(ulong *)(param_2 + 0x860 + (ulong)(uVar11 + 1) * 0x28) = param_3[1] + 1;
    }
    uVar4 = (ulong)uVar11;
  }
  else {
    if ((*(ulong *)(lVar1 + 0x860) < *param_3) && (*(ulong *)(lVar1 + 0x868) == param_3[1])) {
      uVar9 = *(uint *)(param_2 + 0x858);
      if (0xf < uVar9) {
        nvAssertFailedNoLog("pMemoryManager->Ram.numFBRegions < MAX_FB_REGIONS",
                            "src/kernel/gpu/mem_mgr/mem_mgr_regions.c",0x83);
        uVar9 = *(uint *)(param_2 + 0x858);
      }
      if (uVar11 < uVar9) {
        uVar4 = (ulong)uVar9;
        uVar6 = (ulong)(uVar9 - 1);
        puVar7 = (undefined8 *)(param_2 + 0x860 + uVar4 * 0x28);
        do {
          puVar5 = puVar7 + -5;
          *puVar7 = puVar7[uVar4 * -5 + uVar6 * 5];
          puVar7[1] = puVar7[uVar4 * -5 + uVar6 * 5 + 1];
          puVar7[2] = puVar7[uVar4 * -5 + uVar6 * 5 + 2];
          puVar7[3] = puVar7[uVar4 * -5 + uVar6 * 5 + 3];
          puVar7[4] = puVar7[uVar4 * -5 + uVar6 * 5 + 4];
          puVar7 = puVar5;
        } while (puVar5 != (undefined8 *)
                           (param_2 + 0x838 + uVar4 * 0x28 + (ulong)((uVar9 - uVar11) - 1) * -0x28))
        ;
      }
      uVar4 = (ulong)(uVar11 + 1);
      *(uint *)(param_2 + 0x858) = uVar9 + 1;
      *(ulong *)(param_2 + 0x860 + uVar4 * 0x28) = *param_3;
      *(ulong *)(param_2 + 0x868 + uVar4 * 0x28) = param_3[1];
      *(ulong *)(param_2 + 0x870 + uVar4 * 0x28) = param_3[2];
      *(ulong *)(param_2 + 0x878 + uVar4 * 0x28) = param_3[3];
      *(ulong *)(param_2 + 0x880 + uVar4 * 0x28) = param_3[4];
      *(ulong *)(param_2 + 0x868 + uVar10 * 0x28) = *param_3 - 1;
      goto LAB_003c0bc0;
    }
LAB_003c0990:
    uVar9 = *(uint *)(param_2 + 0x858);
    if (0xf < uVar9) {
      nvAssertFailedNoLog("pMemoryManager->Ram.numFBRegions < MAX_FB_REGIONS",
                          "src/kernel/gpu/mem_mgr/mem_mgr_regions.c",0x83);
      uVar9 = *(uint *)(param_2 + 0x858);
    }
    if (uVar11 < uVar9) {
      uVar4 = (ulong)uVar9;
      uVar6 = (ulong)(uVar9 - 1);
      puVar7 = (undefined8 *)(param_2 + 0x860 + uVar4 * 0x28);
      do {
        puVar5 = puVar7 + -5;
        *puVar7 = puVar7[uVar4 * -5 + uVar6 * 5];
        puVar7[1] = puVar7[uVar4 * -5 + uVar6 * 5 + 1];
        puVar7[2] = puVar7[uVar4 * -5 + uVar6 * 5 + 2];
        puVar7[3] = puVar7[uVar4 * -5 + uVar6 * 5 + 3];
        puVar7[4] = puVar7[uVar4 * -5 + uVar6 * 5 + 4];
        puVar7 = puVar5;
      } while (puVar5 != (undefined8 *)
                         (param_2 + 0x838 + uVar4 * 0x28 + (ulong)((uVar9 - uVar11) - 1) * -0x28));
    }
    uVar9 = uVar9 + 1;
    uVar4 = (ulong)(uVar11 + 1);
    *(uint *)(param_2 + 0x858) = uVar9;
    *(ulong *)(param_2 + 0x860 + uVar4 * 0x28) = *param_3;
    *(ulong *)(param_2 + 0x868 + uVar4 * 0x28) = param_3[1];
    *(ulong *)(param_2 + 0x870 + uVar4 * 0x28) = param_3[2];
    *(ulong *)(param_2 + 0x878 + uVar4 * 0x28) = param_3[3];
    *(ulong *)(param_2 + 0x880 + uVar4 * 0x28) = param_3[4];
    if (0xf < uVar9) {
      nvAssertFailedNoLog("pMemoryManager->Ram.numFBRegions < MAX_FB_REGIONS",
                          "src/kernel/gpu/mem_mgr/mem_mgr_regions.c",0x83);
      uVar9 = *(uint *)(param_2 + 0x858);
    }
    if (uVar11 + 1 < uVar9) {
      uVar6 = (ulong)uVar9;
      uVar8 = (ulong)(uVar9 - 1);
      puVar7 = (undefined8 *)(param_2 + 0x860 + uVar6 * 0x28);
      do {
        puVar5 = puVar7 + -5;
        *puVar7 = puVar7[uVar6 * -5 + uVar8 * 5];
        puVar7[1] = puVar7[uVar6 * -5 + uVar8 * 5 + 1];
        puVar7[2] = puVar7[uVar6 * -5 + uVar8 * 5 + 2];
        puVar7[3] = puVar7[uVar6 * -5 + uVar8 * 5 + 3];
        puVar7[4] = puVar7[uVar6 * -5 + uVar8 * 5 + 4];
        puVar7 = puVar5;
      } while (puVar5 != (undefined8 *)
                         (param_2 + 0x838 + uVar6 * 0x28 + (ulong)((uVar9 - uVar11) - 2) * -0x28));
    }
    *(uint *)(param_2 + 0x858) = uVar9 + 1;
    lVar1 = param_2 + (ulong)(uVar11 + 2) * 0x28;
    lVar2 = param_2 + uVar10 * 0x28;
    *(undefined8 *)(lVar1 + 0x860) = *(undefined8 *)(lVar2 + 0x860);
    *(undefined8 *)(lVar1 + 0x868) = *(undefined8 *)(lVar2 + 0x868);
    *(undefined8 *)(lVar1 + 0x870) = *(undefined8 *)(lVar2 + 0x870);
    *(undefined8 *)(lVar1 + 0x878) = *(undefined8 *)(lVar2 + 0x878);
    *(undefined8 *)(lVar1 + 0x880) = *(undefined8 *)(lVar2 + 0x880);
    *(ulong *)(lVar1 + 0x860) = param_3[1] + 1;
    *(ulong *)(lVar2 + 0x868) = *param_3 - 1;
  }
LAB_003c0bc0:
  memmgrRegenerateFbRegionPriority_IMPL(param_1,param_2);
  return uVar4;
}


// ===== 003c0f60 memmgrRegionSetupCommon_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void memmgrRegionSetupCommon_IMPL(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  uint uVar11;
  long local_68;
  long local_60;
  long local_58;
  long local_50;
  undefined1 local_48;
  undefined4 local_44;
  undefined2 local_40;
  undefined1 local_3e;
  ushort local_3d;
  
  lVar7 = *(long *)(*(long *)(param_1 + 0x1b78) + 0x478);
  lVar2 = *(long *)(lVar7 + 0x70);
  uVar8 = *(ulong *)(lVar7 + 0x68);
  lVar7 = (**(code **)(param_2 + 0x220))();
  if (*(char *)(param_1 + 0x4913) != '\0') {
    uVar11 = *(uint *)(param_2 + 0x858);
    if (uVar11 != 0) {
      uVar6 = 0;
      do {
        while( true ) {
          lVar1 = param_2 + (ulong)uVar6 * 0x28;
          if (uVar8 <= *(ulong *)(lVar1 + 0x860)) break;
          portMemSet(&local_60,0,0x28);
          local_58 = uVar8 - 1;
          local_60 = *(long *)(lVar1 + 0x860);
LAB_003c101f:
          local_44 = *(undefined4 *)(lVar1 + 0x87c);
          local_50 = 0;
          local_48 = 1;
          local_40 = *(undefined2 *)(param_2 + 0x880 + (ulong)uVar6 * 0x28);
          local_3d = local_3d & 0xff00;
          local_3e = *(undefined1 *)(lVar1 + 0x882);
          iVar5 = memmgrInsertFbRegion_IMPL(param_1,param_2,&local_60);
          uVar11 = *(uint *)(param_2 + 0x858);
          uVar6 = iVar5 + 1;
          if (uVar11 <= uVar6) goto LAB_003c107b;
        }
        if (lVar2 - 1U < *(ulong *)(lVar1 + 0x868)) {
          portMemSet(&local_60,0,0x28);
          local_58 = *(long *)(lVar1 + 0x868);
          local_60 = lVar2;
          goto LAB_003c101f;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar11);
    }
LAB_003c107b:
    if (lVar7 != 0) {
      portMemSet(&local_60,0,0x28);
      local_48 = 1;
      local_50 = 0;
      lVar2 = param_2 + (ulong)(uVar11 - 1) * 0x28;
      local_58 = *(long *)(lVar2 + 0x868);
      local_60 = (local_58 - lVar7) + 1;
      local_44 = *(undefined4 *)(lVar2 + 0x87c);
      local_40 = *(undefined2 *)(param_2 + 0x880 + (ulong)(uVar11 - 1) * 0x28);
      local_3e = *(undefined1 *)(lVar2 + 0x882);
      local_3d = 0x100;
      memmgrInsertFbRegion_IMPL(param_1,param_2,&local_60);
    }
  }
  if (*(int *)(param_2 + 0x858) != 0) {
    uVar11 = 0;
    do {
      while( true ) {
        lVar2 = *(long *)(param_1 + 0x1b70);
        uVar10 = (ulong)uVar11;
        cVar4 = osNumaOnliningEnabled(*(undefined8 *)(param_1 + 0x4e0));
        lVar7 = param_2 + uVar10 * 0x28;
        uVar8 = *(ulong *)(lVar7 + 0x870);
        if ((cVar4 != '\0') && (*(long *)(lVar7 + 0x860) == 0)) {
          local_68 = 0;
          uVar3 = *(ulong *)(lVar2 + 0x4b0);
          uVar9 = (*(long *)(lVar7 + 0x868) + 1) - uVar8;
          if (uVar3 == 0) {
            iVar5 = osNumaMemblockSize(&local_68);
            if (iVar5 != 0) {
              nvAssertFailedNoLog("osNumaMemblockSize(&memblockSize) == NV_OK",
                                  "src/kernel/gpu/mem_mgr/mem_mgr_regions.c",399);
              return;
            }
            uVar9 = uVar9 & local_68 - 1U;
            uVar8 = *(ulong *)(lVar7 + 0x870);
          }
          else {
            if (uVar9 < uVar3) {
              nvAssertFailedNoLog("usableBlockSize >= pKernelMemorySystem->numaOnlineSize",
                                  "src/kernel/gpu/mem_mgr/mem_mgr_regions.c",0x199);
              return;
            }
            uVar9 = uVar9 - uVar3;
          }
          uVar8 = uVar8 + uVar9;
          *(ulong *)(param_2 + 0x870 + uVar10 * 0x28) = uVar8;
        }
        if (uVar8 != 0) break;
LAB_003c10f0:
        uVar6 = *(uint *)(param_2 + 0x858);
        uVar11 = uVar11 + 1;
        if (uVar6 <= uVar11) goto LAB_003c1230;
      }
      lVar7 = param_2 + uVar10 * 0x28;
      if (((ulong)((*(long *)(lVar7 + 0x868) + 1) - *(long *)(lVar7 + 0x860)) < uVar8) ||
         (*(char *)(lVar7 + 0x878) != '\0')) goto LAB_003c10f0;
      portMemSet(&local_60,0,0x28);
      local_3d = CONCAT11(local_3d._1_1_,1);
      local_58 = *(long *)(lVar7 + 0x868);
      local_50 = *(long *)(lVar7 + 0x870);
      *(undefined8 *)(lVar7 + 0x870) = 0;
      local_60 = (local_58 + 1) - local_50;
      local_48 = *(undefined1 *)(lVar7 + 0x878);
      local_44 = *(undefined4 *)(lVar7 + 0x87c);
      local_40 = *(undefined2 *)(param_2 + 0x880 + uVar10 * 0x28);
      local_3e = *(undefined1 *)(lVar7 + 0x882);
      iVar5 = memmgrInsertFbRegion_IMPL(param_1,param_2,&local_60);
      uVar6 = *(uint *)(param_2 + 0x858);
      uVar11 = iVar5 + 1;
    } while (uVar11 < uVar6);
LAB_003c1230:
    if (uVar6 != 0) {
      uVar8 = 0;
      do {
        iVar5 = (int)uVar8;
        lVar7 = param_2 + uVar8 * 0x28;
        if ((*(char *)(lVar7 + 0x878) == '\0') &&
           (*(ulong *)(param_2 + 0xb98) < *(ulong *)(lVar7 + 0x868))) {
          if (*(ulong *)(param_2 + 0xb98) < *(ulong *)(lVar7 + 0x860)) {
            *(undefined1 *)(lVar7 + 0x883) = 1;
          }
          else {
            portMemSet(&local_60,0,0x28);
            local_3d = CONCAT11(local_3d._1_1_,1);
            local_48 = 0;
            local_60 = *(long *)(param_2 + 0xb98) + 1;
            local_58 = *(long *)(lVar7 + 0x868);
            local_44 = *(undefined4 *)(lVar7 + 0x87c);
            local_40 = *(undefined2 *)(param_2 + 0x880 + uVar8 * 0x28);
            local_3e = *(undefined1 *)(lVar7 + 0x882);
            iVar5 = memmgrInsertFbRegion_IMPL(param_1,param_2,&local_60);
          }
        }
        uVar8 = (ulong)(iVar5 + 1U);
      } while (iVar5 + 1U < *(uint *)(param_2 + 0x858));
    }
  }
  return;
}


// ===== 003c1420 memmgrRegionSetupForPma_IMPL =====

void memmgrRegionSetupForPma_IMPL(undefined8 param_1,undefined8 param_2)

{
  memmgrCalcReservedFbSpace_IMPL();
  memmgrRegionSetupCommon_IMPL(param_1,param_2);
  return;
}


// ===== 003c1450 memmgrDumpFbRegions_IMPL =====

void memmgrDumpFbRegions_IMPL(undefined8 param_1,long param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  
  nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_regions.c",0x208,"memmgrDumpFbRegions_IMPL",1,
               "NVRM: FB region table: numFBRegions = %u.\n",*(undefined4 *)(param_2 + 0x858));
  if (*(int *)(param_2 + 0x858) != 0) {
    puVar1 = (undefined8 *)(param_2 + 0x860);
    uVar2 = 0;
    do {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_regions.c",0x20d,"memmgrDumpFbRegions_IMPL",1,
                   "NVRM: FB region %u - Base=0x%llx, Limit=0x%llx, RsvdSize=0x%llx\n",uVar2,*puVar1
                   ,puVar1[1],puVar1[2]);
      uVar3 = uVar2 + 1;
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_regions.c",0x212,"memmgrDumpFbRegions_IMPL",1,
                   "NVRM: FB region %u - Reserved=%d, InternalHeap=%d, Compressed=%d, ISO=%d, Protected=%d, Performance=%u, LostOnSuspend=%d, PreserveOnSuspend=%d\n"
                   ,uVar2,*(undefined1 *)(puVar1 + 3),*(undefined1 *)((long)puVar1 + 0x23),
                   *(undefined1 *)(puVar1 + 4),*(undefined1 *)((long)puVar1 + 0x21),
                   *(undefined1 *)((long)puVar1 + 0x22),*(undefined4 *)((long)puVar1 + 0x1c),
                   *(undefined1 *)((long)puVar1 + 0x24),*(undefined1 *)((long)puVar1 + 0x25));
      puVar1 = puVar1 + 5;
      uVar2 = uVar3;
    } while (uVar3 < *(uint *)(param_2 + 0x858));
  }
  return;
}


// ===== 003c1580 memmgrGetFbTaxSize_VF =====

undefined8 memmgrGetFbTaxSize_VF(void)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = gpuGetStaticInfo();
  uVar2 = 0;
  if (lVar1 != 0) {
    uVar2 = *(undefined8 *)(lVar1 + 0x1f9a8);
  }
  return uVar2;
}


// ===== 003c15a0 memmgrInitBaseFbRegions_VF =====

undefined8 memmgrInitBaseFbRegions_VF(undefined8 param_1,long param_2)

{
  ulong uVar1;
  char cVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  char *pcVar10;
  char *pcVar11;
  
  lVar7 = gpuGetStaticInfo();
  if (lVar7 == 0) {
    nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/mem_mgr/mem_mgr_vgpu.c",0x3d);
    return 0x40;
  }
  if (*(int *)(lVar7 + 0x1f9b8) == 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_vgpu.c",0x41,"memmgrInitBaseFbRegions_VF",4,
                 "NVRM: Invalid number of FB regions (%d)\n",0);
    nvAssertFailedNoLog(&DAT_00d51d00,"src/kernel/gpu/mem_mgr/mem_mgr_vgpu.c",0x43);
  }
  else {
    if (*(int *)(lVar7 + 0x1f9b8) == 1) {
      *(undefined8 *)(param_2 + 0x860) = 0;
      lVar6 = *(long *)(lVar7 + 0x1f9b0);
      *(undefined1 *)(param_2 + 0x878) = 0;
      *(undefined8 *)(param_2 + 0x870) = 0;
      uVar1 = lVar6 - 1;
      *(ulong *)(param_2 + 0x868) = uVar1;
      uVar4 = *(undefined4 *)(lVar7 + 0x1f9d8);
      *(undefined4 *)(param_2 + 0x87c) = uVar4;
      *(undefined1 *)(param_2 + 0x880) = *(undefined1 *)(lVar7 + 0x1f9dc);
      cVar2 = *(char *)(lVar7 + 0x1f9dd);
      *(char *)(param_2 + 0x881) = cVar2;
      uVar3 = *(undefined1 *)(lVar7 + 0x1f9de);
      *(long *)(param_2 + 0x828) = lVar6;
      pcVar10 = "NV_TRUE";
      *(undefined1 *)(param_2 + 0x882) = uVar3;
      pcVar11 = "NV_FALSE";
      if (*(char *)(param_2 + 0x883) != '\0') {
        pcVar11 = "NV_TRUE";
      }
      if (cVar2 == '\0') {
        pcVar10 = "NV_FALSE";
      }
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_vgpu.c",0x5d,"memmgrInitBaseFbRegions_VF",1,
                   "NVRM: FB Region 0 : %x\'%08x - %x\'%08x perf = %d rsvd = %s ISO = %s internal = %s\n"
                   ,0,0,uVar1 >> 0x20,uVar1,uVar4,"NV_FALSE",pcVar10,pcVar11);
      uVar1 = *(ulong *)(param_2 + 0x828);
      iVar5 = *(int *)(lVar7 + 0x1f9b8);
      *(int *)(param_2 + 0x858) = iVar5;
      *(ulong *)(param_2 + 0x830) = uVar1 >> 0x14;
      uVar8 = *(long *)(param_2 + 0x868 + (ulong)(iVar5 - 1) * 0x28) + 1;
      uVar9 = uVar8 >> 0x14;
      *(ulong *)(param_2 + 0x838) = uVar9;
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_vgpu.c",0x6c,"memmgrInitBaseFbRegions_VF",1,
                   "NVRM: FB Reserved Memory = %x\'%08x FB Usable Memory = %x\'%08x FB Address Space (MB) = %x\'%08x\n"
                   ,*(ulong *)(param_2 + 0x850) >> 0x20,*(ulong *)(param_2 + 0x850),uVar1 >> 0x20,
                   uVar1,uVar8 >> 0x34,uVar9);
      return 0;
    }
    nvAssertFailedNoLog(&DAT_00d51d00,"src/kernel/gpu/mem_mgr/mem_mgr_vgpu.c",0x4a);
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_mgr_vgpu.c",0x4b,"memmgrInitBaseFbRegions_VF",4,
                 "NVRM: Mixed density FB regions not supported (%d)\n",
                 *(undefined4 *)(lVar7 + 0x1f9b8));
  }
  return 0x3b;
}


// ===== 003c1820 memmgrGetGrHeapReservationSize_VF =====

undefined4 memmgrGetGrHeapReservationSize_VF(void)

{
  long lVar1;
  
  lVar1 = gpuGetStaticInfo();
  if (lVar1 != 0) {
    return *(undefined4 *)(lVar1 + 0xb834);
  }
  nvAssertFailedNoLog("(pVSI != NULL)","src/kernel/gpu/mem_mgr/mem_mgr_vgpu.c",0x84);
  return 0;
}


// ===== 003c1860 _scrubCheckProgress =====

void _scrubCheckProgress(long param_1)

{
  uint uVar1;
  ulong uVar2;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pScrubber != NULL","src/kernel/gpu/mem_mgr/mem_scrub.c",0x3ef);
  }
  if (*(char *)(param_1 + 0x60) == '\0') {
    if (*(char *)(param_1 + 0x40) == '\0') {
      uVar2 = ceutilsUpdateProgress_IMPL(*(undefined8 *)(param_1 + 0x30));
    }
    else {
      uVar2 = sec2utilsUpdateProgress_IMPL(*(undefined8 *)(param_1 + 0x38));
    }
  }
  else {
    uVar1 = *(uint *)(*(long *)(param_1 + 0x50) + 4);
    uVar2 = *(ulong *)(param_1 + 0x18);
    if ((uint)uVar2 == uVar1) {
      return;
    }
    if (uVar1 < (uint)uVar2) {
      uVar2 = uVar2 + 0x100000000;
    }
    uVar2 = uVar2 & 0xffffffff00000000 | (ulong)uVar1;
  }
  *(ulong *)(param_1 + 0x18) = uVar2;
  return;
}


// ===== 003c1900 _scrubCopyListItems =====

void _scrubCopyListItems(long param_1,long param_2,ulong param_3)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  
  uVar1 = (uint)*(undefined8 *)(param_1 + 8);
  uVar6 = (ulong)(uVar1 & 0xfff);
  uVar4 = (ulong)(uVar1 + (int)param_3 & 0xfff);
  if (param_2 == 0) {
    nvAssertFailedNoLog("pList != NULL","src/kernel/gpu/mem_mgr/mem_scrub.c",0x2a1);
  }
  if (0x1000 < param_3) {
    nvAssertFailedNoLog("itemsToSave <= MAX_SCRUB_ITEMS","src/kernel/gpu/mem_mgr/mem_scrub.c",0x2a2)
    ;
  }
  lVar5 = uVar6 * 0x18;
  lVar3 = *(long *)(param_1 + 0x28) + lVar5;
  if (uVar6 < uVar4) {
    portMemCopy(param_2,param_3 * 0x18,lVar3,param_3 * 0x18);
    portMemSet(*(long *)(param_1 + 0x28) + lVar5,0,param_3 * 0x18);
  }
  else {
    lVar2 = 0x1000 - uVar6;
    portMemCopy(param_2,lVar2 * 0x18,lVar3,lVar2 * 0x18);
    portMemSet(*(long *)(param_1 + 0x28) + lVar5,0,lVar2 * 0x18);
    portMemCopy(param_2 + lVar2 * 0x18,uVar4 * 0x18,*(undefined8 *)(param_1 + 0x28),uVar4 * 0x18);
    portMemSet(*(undefined8 *)(param_1 + 0x28),0,uVar4 * 0x18);
  }
  *(long *)(param_1 + 8) = *(long *)(param_1 + 8) + param_3;
  param_3 = *(long *)(param_1 + 0x20) - param_3;
  *(ulong *)(param_1 + 0x20) = param_3;
  if (param_3 < 0x1001) {
    return;
  }
  nvAssertFailedNoLog("_scrubGetFreeEntries(pScrubber) <= MAX_SCRUB_ITEMS",
                      "src/kernel/gpu/mem_mgr/mem_scrub.c",0x2c2);
  return;
}


// ===== 003c1ac0 _scrubCheckLocked =====

undefined8 _scrubCheckLocked(long param_1,long *param_2,ulong *param_3)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  *param_2 = 0;
  *param_3 = 0;
  lVar1 = _scrubCheckProgress();
  uVar2 = lVar1 - *(long *)(param_1 + 8);
  if (uVar2 < 0x1001) {
    lVar1 = 0;
    uVar3 = 0;
    if (uVar2 == 0) goto LAB_003c1b07;
  }
  else {
    nvAssertFailedNoLog("itemsToSave <= MAX_SCRUB_ITEMS","src/kernel/gpu/mem_mgr/mem_scrub.c",0x155)
    ;
  }
  lVar1 = portMemAllocNonPaged(uVar2 * 0x18);
  if (lVar1 == 0) {
    uVar3 = 0x1a;
  }
  else {
    portMemSet(lVar1,0,uVar2 * 0x18);
    _scrubCopyListItems(param_1,lVar1,uVar2);
    uVar3 = 0;
  }
LAB_003c1b07:
  *param_2 = lVar1;
  *param_3 = uVar2;
  return uVar3;
}


// ===== 003c1b80 _scrubCombinePages.constprop.0 =====

undefined8
_scrubCombinePages_constprop_0(long *param_1,long param_2,long param_3,long *param_4,long *param_5)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  
  lVar3 = portMemAllocNonPaged(param_3 * 0x18);
  *param_4 = lVar3;
  if (lVar3 == 0) {
    nvAssertFailedNoLog("*ppScrubList != NULL","src/kernel/gpu/mem_mgr/mem_scrub.c",0x454);
    return 0x51;
  }
  *(long *)(lVar3 + 8) = *param_1;
  *(long *)(*param_4 + 0x10) = param_2;
  lVar3 = 1;
  if (param_3 != 1) {
    plVar1 = param_1 + param_3 + -1;
    lVar3 = 0;
    do {
      while( true ) {
        lVar2 = *param_4;
        lVar4 = lVar3 * 0x18;
        uVar5 = *(long *)(lVar2 + 0x10 + lVar4) + param_2;
        if ((0xffffffff < uVar5) || (*param_1 + param_2 != param_1[1])) break;
        param_1 = param_1 + 1;
        *(ulong *)(lVar2 + 0x10 + lVar4) = uVar5;
        if (param_1 == plVar1) goto LAB_003c1c60;
      }
      *(long *)(lVar2 + 0x20 + lVar4) = param_1[1];
      param_1 = param_1 + 1;
      lVar3 = lVar3 + 1;
      *(long *)(*param_4 + 0x28 + lVar4) = param_2;
    } while (param_1 != plVar1);
LAB_003c1c60:
    lVar3 = lVar3 + 1;
  }
  *param_5 = lVar3;
  return 0;
}


// ===== 003c1cb0 _scrubWaitAndSave =====

int _scrubWaitAndSave(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined1 local_50 [32];
  
  if (param_3 != 0) {
    iVar2 = 0;
    lVar1 = *(long *)(param_1 + 0x48) + 0x1af0;
    timeoutSet(lVar1,local_50,0,0);
    do {
      uVar3 = _scrubCheckProgress(param_1);
      if ((ulong)(*(long *)(param_1 + 8) + param_3) <= uVar3) {
        _scrubCopyListItems(param_1,param_2,param_3);
        return iVar2;
      }
      if (*(char *)(param_1 + 0x40) == '\0') {
        ceutilsServiceInterrupts_IMPL(*(undefined8 *)(param_1 + 0x30));
      }
      else {
        sec2utilsServiceInterrupts_IMPL(*(undefined8 *)(param_1 + 0x38));
      }
      iVar2 = timeoutCheck(lVar1,local_50,0x36f);
    } while (iVar2 != 0x65);
    uVar3 = _scrubCheckProgress(param_1);
    if (uVar3 < (ulong)(param_3 + *(long *)(param_1 + 8))) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_scrub.c",0x376,"_scrubWaitAndSave",4,
                   "NVRM: Timed out when waiting for scrub jobs to finish.\n");
      return 0x65;
    }
  }
  return 0;
}


// ===== 003c1df0 _scrubCheckAndSubmit.part.0 =====

long _scrubCheckAndSubmit_part_0
               (long param_1,long param_2,long param_3,undefined8 param_4,undefined8 param_5,
               uint param_6)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  long *plVar6;
  ulong uVar7;
  long *plVar8;
  long local_90;
  long local_80;
  long local_78 [3];
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  iVar5 = _scrubWaitAndSave(param_1,param_4,param_5);
  if (iVar5 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar5,"_scrubWaitAndSave(pScrubber, pScrubListCopy, pagesToScrubCheck)",
               "src/kernel/gpu/mem_mgr/mem_scrub.c",0x2e5);
    return 0;
  }
  local_90 = 0;
  plVar8 = (long *)(param_3 + 8);
  if (param_2 != 0) {
    do {
      lVar1 = *(long *)(param_1 + 0x10) + 1;
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_scrub.c",0x2f0,"_scrubCheckAndSubmit",1,
                   "NVRM: Submitting work, Id: %llx, base: %llx, size: %llx\n",lVar1,*plVar8,
                   plVar8[1]);
      lVar3 = plVar8[1];
      lVar4 = *plVar8;
      local_80 = 0;
      iVar5 = memdescCreate(&local_80,*(undefined8 *)(param_1 + 0x48),lVar3,0,1,2,6,0);
      if (iVar5 != 0) {
        nvAssertOkFailedNoLog
                  (iVar5,
                   "memdescCreate(&pMemDesc, pScrubber->pGpu, size, 0, NV_TRUE, ADDR_FBMEM, dstCpuCacheAttrib, MEMDESC_FLAGS_NONE)"
                   ,"src/kernel/gpu/mem_mgr/mem_scrub.c",0x423);
LAB_003c207a:
        nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_scrub.c",0x2fb,"_scrubCheckAndSubmit",4,
                     "NVRM: Failing because the work didn\'t submit.\n");
        return 0;
      }
      memdescDescribe(local_80,2,lVar4,lVar3);
      if ((param_6 & 1) != 0) {
        memdescSetFlag(local_80,0x4000000000000,1);
        *(undefined8 *)(local_80 + 0x158) =
             *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x48) + 0x1b78) + 0xd38);
      }
      local_78[1] = 0;
      local_60 = 0;
      local_78[2] = lVar3;
      if (*(char *)(param_1 + 0x40) == '\0') {
        local_78[0] = local_80;
        local_50 = 0;
        local_48 = 0;
        local_40 = 0;
        local_58 = 5;
        iVar5 = ceutilsMemset_IMPL(*(undefined8 *)(param_1 + 0x30),local_78);
        if (iVar5 != 0) {
          nvAssertOkFailedNoLog
                    (iVar5,"ceutilsMemset(pScrubber->pCeUtils, &memsetParams)",
                     "src/kernel/gpu/mem_mgr/mem_scrub.c",0x43e);
          memdescDestroy(local_80);
          goto LAB_003c207a;
        }
        *(undefined8 *)(param_1 + 0x10) = local_50;
        memdescDestroy(local_80);
      }
      else {
        local_78[0] = local_80;
        iVar5 = sec2utilsMemset_IMPL(*(undefined8 *)(param_1 + 0x38),local_78);
        if (iVar5 != 0) {
          nvAssertOkFailedNoLog
                    (iVar5,"sec2utilsMemset(pScrubber->pSec2Utils, &memsetParams)",
                     "src/kernel/gpu/mem_mgr/mem_scrub.c",0x434);
          memdescDestroy(local_80);
          goto LAB_003c207a;
        }
        *(undefined8 *)(param_1 + 0x10) = local_60;
        memdescDestroy(local_80);
      }
      lVar4 = plVar8[1];
      lVar2 = *plVar8;
      uVar7 = (ulong)((int)lVar1 - 1U & 0xfff);
      lVar3 = uVar7 * 0x18;
      plVar6 = (long *)(*(long *)(param_1 + 0x28) + lVar3);
      if (*plVar6 != 0) {
        nvAssertFailedNoLog("pScrubber->pScrubList[idx].id == 0",
                            "src/kernel/gpu/mem_mgr/mem_scrub.c",0x3d3);
        plVar6 = (long *)(*(long *)(param_1 + 0x28) + lVar3);
      }
      plVar6[1] = lVar2;
      *(long *)(*(long *)(param_1 + 0x28) + 0x10 + lVar3) = lVar4;
      *(long *)(*(long *)(param_1 + 0x28) + uVar7 * 0x18) = lVar1;
      *(long *)(param_1 + 0x10) = lVar1;
      uVar7 = *(long *)(param_1 + 0x20) + 1;
      *(ulong *)(param_1 + 0x20) = uVar7;
      if (0x1000 < uVar7) {
        nvAssertFailedNoLog("_scrubGetFreeEntries(pScrubber) <= MAX_SCRUB_ITEMS",
                            "src/kernel/gpu/mem_mgr/mem_scrub.c",0x3da);
      }
      plVar8 = plVar8 + 3;
      _scrubCheckProgress(param_1);
      local_90 = local_90 + 1;
    } while (local_90 != param_2);
  }
  return param_2;
}


// ===== 003c21d0 scrubberConstruct =====

int scrubberConstruct(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  long lVar6;
  long *plVar7;
  long lVar8;
  bool bVar9;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  bVar9 = false;
  lVar8 = *(long *)(param_1 + 0x1b78);
  lVar1 = *(long *)(param_1 + 0x1bc0);
  if (lVar1 != 0) {
    cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1,lVar1);
    bVar9 = cVar3 != '\0';
  }
  if (param_2 == 0) {
    return 0x1f;
  }
  uVar2 = *(undefined8 *)(param_2 + 0x128);
  lVar6 = pmaGetMemScrub(uVar2);
  if (lVar6 != 0) {
    return 0;
  }
  plVar7 = (long *)portMemAllocNonPaged(0x68);
  if (plVar7 == (long *)0x0) {
    return 0x1a;
  }
  portMemSet(plVar7,0,0x68);
  lVar6 = portMemAllocNonPaged(portSyncMutexSize);
  *plVar7 = lVar6;
  if (lVar6 == 0) {
    iVar5 = 0x1a;
    goto LAB_003c2426;
  }
  iVar5 = portSyncMutexInitialize(lVar6);
  if (iVar5 == 0) {
    lVar6 = portMemAllocNonPaged(0x18000);
    plVar7[5] = lVar6;
    if (lVar6 == 0) {
      iVar5 = 0x1a;
    }
    else {
      portMemSet(lVar6,0,0x18000);
      plVar7[9] = param_1;
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_scrub.c",0x95,"scrubberConstruct",1,
                   "NVRM: Starting to init CeUtils for scrubber.\n");
      local_50 = 0;
      local_48 = 0;
      local_40 = 0;
      if (*(char *)(lVar8 + 0x485) != '\0') {
        local_48 = 2;
      }
      lVar8 = 0;
      if (bVar9) {
        iVar5 = 0;
        do {
          lVar8 = kmigmgrGetMIGGpuInstanceSlot_IMPL(param_1,lVar1,iVar5);
          if (((lVar8 != 0) && (*(char *)(lVar8 + 0x988) != '\0')) &&
             (*(long *)(lVar8 + 0x980) == param_2)) break;
          iVar5 = iVar5 + 1;
          lVar8 = 0;
        } while (iVar5 != 8);
      }
      if ((*(long *)(param_1 + 0x1d18) == 0) ||
         (*(char *)(*(long *)(param_1 + 0x1d18) + 0x2a9) == '\0')) {
        iVar5 = __nvoc_objCreate_CeUtils(plVar7 + 6,param_2,0,param_1,lVar8,&local_50);
        uVar4 = 0;
        if (iVar5 == 0) goto LAB_003c23c6;
        nvAssertOkFailedNoLog
                  (iVar5,
                   "objCreate(&pScrubber->pCeUtils, pHeap, CeUtils, pGpu, pKernelMIGGPUInstance, &ceUtilsAllocParams)"
                   ,"src/kernel/gpu/mem_mgr/mem_scrub.c",0xb5);
      }
      else {
        iVar5 = __nvoc_objCreate_Sec2Utils(plVar7 + 7,param_2,0,param_1,lVar8);
        uVar4 = 1;
        if (iVar5 == 0) {
LAB_003c23c6:
          *(undefined1 *)(plVar7 + 8) = uVar4;
          iVar5 = pmaRegMemScrub(uVar2,plVar7);
          if (iVar5 == 0) {
            return 0;
          }
          nvAssertOkFailedNoLog
                    (iVar5,"pmaRegMemScrub(pPma, pScrubber)","src/kernel/gpu/mem_mgr/mem_scrub.c",
                     0xba);
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar5,
                     "objCreate(&pScrubber->pSec2Utils, pHeap, Sec2Utils, pGpu, pKernelMIGGPUInstance)"
                     ,"src/kernel/gpu/mem_mgr/mem_scrub.c",0xaf);
        }
      }
      portMemFree(plVar7[5]);
    }
    portSyncMutexDestroy(*plVar7);
  }
  else {
    nvAssertOkFailedNoLog
              (iVar5,"portSyncMutexInitialize(pScrubber->pScrubberMutex)",
               "src/kernel/gpu/mem_mgr/mem_scrub.c",0x86);
  }
  portMemFree(*plVar7);
  *plVar7 = 0;
LAB_003c2426:
  portMemFree(plVar7);
  return iVar5;
}


// ===== 003c2560 scrubberDestruct =====

void scrubberDestruct(long param_1,long param_2)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined8 local_48;
  long local_40 [3];
  
  if (param_2 == 0) {
    return;
  }
  uVar1 = *(undefined8 *)(param_2 + 0x128);
  puVar3 = (undefined8 *)pmaGetMemScrub(uVar1);
  if (puVar3 == (undefined8 *)0x0) {
    return;
  }
  pmaUnregMemScrub(uVar1);
  portSyncMutexAcquire(*puVar3);
  if ((((param_1 != 0) && (*(char *)(param_1 + 0x44f) == '\0')) &&
      (*(char *)(param_1 + 0x450) == '\0')) &&
     ((*(char *)(param_1 + 0x451) == '\0' && (*(char *)(param_1 + 0x461) == '\0')))) {
    timeoutSet(param_1 + 0x1af0,local_40,0,0);
    do {
      if (*(char *)(puVar3 + 0xc) == '\0') {
        if (*(char *)(puVar3 + 8) == '\0') {
          lVar4 = ceutilsUpdateProgress_IMPL(puVar3[6]);
        }
        else {
          lVar4 = sec2utilsUpdateProgress_IMPL(puVar3[7]);
        }
        if (puVar3[2] == lVar4) goto LAB_003c25c3;
      }
      else if (puVar3[2] == (ulong)*(uint *)(puVar3[10] + 4)) goto LAB_003c25c3;
    } while ((*(char *)(param_1 + 0x4910) != '\0') ||
            (iVar2 = timeoutCheck(param_1 + 0x1af0,local_40,0x11c), iVar2 != 0x65));
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_scrub.c",0x11e,"scrubberDestruct",6,
                 "NVRM:  Timed out when waiting for the scrub to complete the pending work .\n");
  }
LAB_003c25c3:
  iVar2 = _scrubCheckLocked(puVar3,&local_48,local_40);
  if (iVar2 != 0) {
    nvAssertOkFailedNoLog
              (0x1a,"_scrubCheckLocked(pScrubber, &pPmaScrubList, &count)",
               "src/kernel/gpu/mem_mgr/mem_scrub.c",0x128);
  }
  if (local_40[0] != 0) {
    pmaClearScrubbedPages(uVar1,local_48);
  }
  portMemFree(local_48);
  portMemFree(puVar3[5]);
  if (*(char *)(puVar3 + 8) == '\0') {
    __nvoc_objDelete(puVar3[6]);
  }
  else {
    __nvoc_objDelete(puVar3[7]);
  }
  portSyncMutexRelease(*puVar3);
  portSyncMutexDestroy(*puVar3);
  portMemFree(*puVar3);
  portMemFree(puVar3);
  return;
}


// ===== 003c27a0 scrubCheck =====

undefined4 scrubCheck(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  
  portSyncMutexAcquire(*param_1);
  uVar1 = _scrubCheckLocked(param_1,param_2,param_3);
  portSyncMutexRelease(*param_1);
  return uVar1;
}


// ===== 003c27f0 scrubSubmitPages =====

undefined4
scrubSubmitPages(undefined8 *param_1,undefined8 param_2,undefined8 param_3,long param_4,
                long *param_5,long *param_6,undefined4 param_7)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  ulong uVar11;
  undefined4 local_64;
  long local_48;
  ulong local_40 [2];
  
  local_48 = 0;
  local_40[0] = 0;
  portSyncMutexAcquire(*param_1);
  *param_6 = 0;
  *param_5 = 0;
  if (param_4 == 0) {
    nvCheckFailedNoLog(1,"pageCount > 0","src/kernel/gpu/mem_mgr/mem_scrub.c",0x1af);
    portSyncMutexRelease(*param_1);
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_scrub.c",0x1b1,"scrubSubmitPages",1,
               "NVRM: submitting pages, pageCount = 0x%llx chunkSize = 0x%llx\n",param_4,param_2);
  lVar4 = param_1[4];
  iVar3 = _scrubCombinePages_constprop_0(param_3,param_2,param_4,&local_48,local_40);
  uVar2 = local_40[0];
  lVar1 = local_48;
  if (iVar3 == 0) {
    uVar6 = 0x1000 - lVar4;
    if (uVar6 < local_40[0]) {
      lVar4 = portMemAllocNonPaged(((local_40[0] - 0x1000) + lVar4) * 0x18,0x3c2834);
      if (lVar4 == 0) goto LAB_003c2a65;
      uVar11 = 0;
      uVar7 = uVar2;
      lVar5 = 0;
      do {
        if (uVar7 < 0x1001) {
          lVar10 = uVar7 - uVar6;
          uVar8 = uVar7;
        }
        else {
          uVar8 = 0x1000;
          lVar10 = 0x1000 - uVar6;
        }
        lVar9 = lVar5 + lVar10;
        lVar5 = _scrubCheckAndSubmit_part_0
                          (param_1,uVar8,lVar1 + uVar11 * 0x18,lVar4 + lVar5 * 0x18,lVar10,param_7);
        uVar6 = 0x1000 - param_1[4];
        uVar7 = uVar7 - lVar5;
        uVar11 = uVar11 + lVar5;
        lVar5 = lVar9;
      } while (uVar6 < uVar7);
      *param_5 = lVar4;
      *param_6 = lVar9;
      portSyncMutexRelease(*param_1);
    }
    else {
      uVar11 = _scrubCheckAndSubmit_part_0(param_1,local_40[0],local_48,0,0,param_7);
      *param_5 = 0;
      *param_6 = 0;
      portSyncMutexRelease(*param_1);
    }
    if (lVar1 != 0) {
      portMemFree(lVar1);
    }
    local_64 = 0;
    if (uVar2 != uVar11) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_scrub.c",0x1ff,"scrubSubmitPages",6,
                   "NVRM: totalSubmitted :%llx != pageCount: %llx\n",uVar11,param_4);
      local_64 = 0xffff;
    }
  }
  else {
    nvAssertOkFailedNoLog
              (0x51,"_scrubCombinePages(pPages, chunkSize, pageCount, &pScrubList, &scrubListSize)",
               "src/kernel/gpu/mem_mgr/mem_scrub.c",0x1b5);
LAB_003c2a65:
    portSyncMutexRelease(*param_1);
    if (lVar1 != 0) {
      portMemFree(lVar1);
    }
    nvCheckOkFailedNoLog(1,0x51,"status","src/kernel/gpu/mem_mgr/mem_scrub.c",0x1f7);
    local_64 = 0x51;
  }
  return local_64;
}


// ===== 003c2af0 scrubWaitPages =====

int scrubWaitPages(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  ulong *puVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  char cVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  bool bVar11;
  uint local_6c;
  long local_60;
  ulong local_58;
  undefined1 local_50 [32];
  
  local_60 = 0;
  local_58 = 0;
  iVar6 = _scrubCombinePages_constprop_0(param_3,param_2,param_4,&local_60,&local_58);
  if (iVar6 != 0) {
    nvAssertOkFailedNoLog
              (0x51,"_scrubCombinePages(pPages, chunkSize, pageCount, &pScrubList, &scrubListSize)",
               "src/kernel/gpu/mem_mgr/mem_scrub.c",0x224);
    return 0x51;
  }
  portSyncMutexAcquire(*param_1);
  uVar4 = local_58;
  lVar3 = local_60;
  uVar7 = 0;
  if (local_58 != 0) {
    local_6c = 0;
    do {
      lVar10 = param_1[9];
      bVar11 = true;
      uVar9 = *(ulong *)(lVar3 + 8 + uVar7 * 0x18);
      lVar2 = *(long *)(lVar3 + 0x10 + uVar7 * 0x18);
      cVar5 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar10 + 0x7a4));
      if (cVar5 == '\0') {
        cVar5 = rmGpuLockIsOwner();
        bVar11 = cVar5 != '\0';
      }
      lVar8 = param_1[1];
      if (lVar8 != param_1[2]) {
        uVar7 = 0;
        do {
          puVar1 = (ulong *)(param_1[5] + (ulong)((uint)lVar8 & 0xfff) * 0x18);
          if (((uVar9 <= (puVar1[2] - 1) + puVar1[1]) && (puVar1[1] <= (uVar9 - 1) + lVar2)) &&
             (uVar7 < *puVar1)) {
            uVar7 = *puVar1;
          }
          lVar8 = lVar8 + 1;
        } while (param_1[2] != lVar8);
        if (uVar7 != 0) {
          lVar10 = lVar10 + 0x1af0;
          timeoutSet(lVar10,local_50,0,0);
          do {
            uVar9 = _scrubCheckProgress(param_1);
            if (uVar7 <= uVar9) goto LAB_003c2c80;
            if (bVar11) {
              if (*(char *)(param_1 + 8) == '\0') {
                ceutilsServiceInterrupts_IMPL(param_1[6]);
              }
              else {
                sec2utilsServiceInterrupts_IMPL(param_1[7]);
              }
            }
            iVar6 = timeoutCheck(lVar10,local_50,0x3ac);
          } while (iVar6 == 0);
          if (iVar6 == 0x65) {
            uVar9 = _scrubCheckProgress(param_1);
            if (uVar7 <= uVar9) goto LAB_003c2c80;
            nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_scrub.c",0x3b3,"_waitForPayload",4,
                         "NVRM: Timed out when waiting for scrub job %llu to finish.\n",uVar7);
          }
          nvAssertOkFailedNoLog
                    (iVar6,
                     "_waitForPayload(pScrubber, pScrubList[iter].base, (pScrubList[iter].base + pScrubList[iter].size - 1))"
                     ,"src/kernel/gpu/mem_mgr/mem_scrub.c",0x22e);
          goto LAB_003c2d17;
        }
      }
LAB_003c2c80:
      local_6c = local_6c + 1;
      uVar7 = (ulong)local_6c;
    } while (uVar7 < uVar4);
  }
  iVar6 = 0;
LAB_003c2d17:
  portSyncMutexRelease(*param_1);
  if (lVar3 != 0) {
    portMemFree();
  }
  return iVar6;
}


// ===== 003c2dc0 scrubCheckAndWaitForSize =====

int scrubCheckAndWaitForSize
              (undefined8 *param_1,ulong param_2,ulong param_3,long *param_4,ulong *param_5)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  
  portSyncMutexAcquire(*param_1);
  uVar1 = param_1[4];
  *param_5 = 0;
  *param_4 = 0;
  if (uVar1 != 0) {
    uVar6 = 0;
    uVar5 = 0;
    do {
      iVar3 = (int)uVar6;
      uVar6 = uVar6 + 1;
      uVar5 = uVar5 + *(ulong *)(param_1[5] + 0x10 + (ulong)((int)param_1[1] + iVar3 & 0xfff) * 0x18
                                ) / param_3;
      if (uVar1 <= uVar6) break;
    } while (uVar5 <= param_2);
    lVar4 = portMemAllocNonPaged(uVar6 * 0x18);
    if (lVar4 == 0) {
      portSyncMutexRelease(*param_1);
      iVar2 = 0x1a;
    }
    else {
      iVar2 = _scrubWaitAndSave(param_1,lVar4,uVar6);
      iVar3 = 0;
      if (iVar2 == 0) goto LAB_003c2e93;
      nvCheckOkFailedNoLog
                (4,iVar2,"_scrubWaitAndSave(pScrubber, pList, requiredItemsToSave)",
                 "src/kernel/gpu/mem_mgr/mem_scrub.c",0x272);
      portSyncMutexRelease(*param_1);
      portMemFree(lVar4);
    }
    return iVar2;
  }
  uVar6 = 0;
  iVar3 = 0x51;
  lVar4 = 0;
LAB_003c2e93:
  *param_5 = uVar6;
  *param_4 = lVar4;
  portSyncMutexRelease(*param_1);
  return iVar3;
}


// ===== 003c2f20 memmgrCheckSurfaceBounds =====

undefined8 memmgrCheckSurfaceBounds(long *param_1,long param_2)

{
  ulong uVar1;
  
  if (param_1 == (long *)0x0) {
    nvAssertFailedNoLog("pSurface != NULL","src/kernel/gpu/mem_mgr/mem_utils.c",0x87);
  }
  else if (*param_1 == 0) {
    nvAssertFailedNoLog("pSurface->pMemDesc != NULL","src/kernel/gpu/mem_mgr/mem_utils.c",0x88);
  }
  else if (param_2 == 0) {
    nvAssertFailedNoLog("size != 0","src/kernel/gpu/mem_mgr/mem_utils.c",0x89);
  }
  else {
    uVar1 = *(ulong *)(*param_1 + 0x30);
    if (uVar1 < (ulong)param_1[1]) {
      nvAssertFailedNoLog("pSurface->offset <= pSurface->pMemDesc->Size",
                          "src/kernel/gpu/mem_mgr/mem_utils.c",0x8a);
    }
    else {
      if ((ulong)(param_1[1] + param_2) <= uVar1) {
        return 0;
      }
      nvAssertFailedNoLog("pSurface->offset + size <= pSurface->pMemDesc->Size",
                          "src/kernel/gpu/mem_mgr/mem_utils.c",0x8b);
    }
  }
  return 0x1f;
}


// ===== 003c3000 memmgrGetMemTransferType =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint memmgrGetMemTransferType(long param_1,undefined8 *param_2,undefined8 *param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  
  uVar6 = 0;
  if (param_1 != 0) {
    uVar6 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar4 = gpuEngineGetGpu(uVar6);
  lVar5 = *(long *)(&DAT_00001b90 + lVar4);
  if ((param_2 == (undefined8 *)0x0) || (iVar2 = memdescGetAddressSpace(*param_2), iVar2 == 1)) {
    if (param_3 == (undefined8 *)0x0) {
      return 0;
    }
    iVar2 = memdescGetAddressSpace(*param_3);
    if (iVar2 == 1) {
      return 0;
    }
    if ((param_4 & 0x40) == 0) goto LAB_003c31b0;
    if (*(char *)(lVar4 + 0x490e) != '\0') goto LAB_003c312e;
LAB_003c314a:
    lVar5 = *(long *)(param_1 + 0x4a0);
    if ((lVar5 == 0) || (*(long *)(lVar5 + 0x88) != 0)) goto LAB_003c31f8;
    if (param_2 != (undefined8 *)0x0) goto LAB_003c3092;
LAB_003c3172:
    if (param_3 == (undefined8 *)0x0) {
      return 2;
    }
    uVar3 = memdescGetPteKindForGpu((undefined8 *)*param_3,*(undefined8 *)*param_3);
    cVar1 = (**(code **)(param_1 + 0x2a8))(param_1,5,uVar3);
    if (cVar1 == '\0') {
      return 2;
    }
  }
  else {
    if ((param_4 & 0x40) == 0) {
LAB_003c31b0:
      if (*(char *)(lVar5 + 0xad0c) == '\0') {
        return 0;
      }
      cVar1 = gpuIsCCDevToolsModeEnabled_IMPL(lVar4);
      if (cVar1 == '\0') {
        return 1;
      }
      return param_4 >> 10 & 1 ^ 1;
    }
    if ((*(char *)(lVar4 + 0x490e) != '\0') && (param_3 != (undefined8 *)0x0)) {
LAB_003c312e:
      if ((*(char *)(lVar4 + 0x454) == '\0') || (*(char *)(lVar4 + 0x4915) == '\0')) {
        return 4;
      }
      goto LAB_003c314a;
    }
    lVar5 = *(long *)(param_1 + 0x4a0);
    if ((lVar5 == 0) || (*(long *)(lVar5 + 0x88) != 0)) goto LAB_003c31f8;
LAB_003c3092:
    uVar3 = memdescGetPteKindForGpu((undefined8 *)*param_2,*(undefined8 *)*param_2);
    cVar1 = (**(code **)(param_1 + 0x2a8))(param_1,5,uVar3);
    if (cVar1 == '\0') goto LAB_003c3172;
    if (param_3 != (undefined8 *)0x0) {
      uVar3 = memdescGetPteKindForGpu((undefined8 *)*param_3,*(undefined8 *)*param_3);
      (**(code **)(param_1 + 0x2a8))(param_1,5,uVar3);
    }
  }
  if (*(char *)(lVar5 + 0x68) != '\0') {
    return 2;
  }
LAB_003c31f8:
  if (*(char *)(lVar4 + 0x446) != '\0') {
    return 0;
  }
  cVar1 = hypervisorIsVgxHyper_IMPL();
  if (cVar1 != '\0') {
    return 0;
  }
  if ((*(char *)(lVar4 + 0x4a4e) != '\0') && (*(char *)(lVar4 + 0x908) == '\0')) {
    return 0;
  }
  if ((*(long *)(lVar4 + 0x1bc0) != 0) && (cVar1 = kmigmgrIsMIGEnabled_IMPL(lVar4), cVar1 != '\0'))
  {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_utils.c",0x74,"memmgrGetMemTransferType",3,
               "NVRM: Can\'t copy using CE, falling back to other methods\n");
  return 0;
}


// ===== 003c3280 _memmgrAllocAndMapSurface =====

int _memmgrAllocAndMapSurface
              (undefined8 param_1,undefined8 param_2,long *param_3,undefined8 *param_4,
              undefined8 *param_5)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  iVar1 = memdescCreate(param_3,param_1,param_2,0x1000,1,1,0,0x200000000000);
  if (iVar1 == 0) {
    *(undefined4 *)(*param_3 + 0x9c) = 0x6e;
    iVar1 = memdescAlloc(*param_3,uVar2);
    if (iVar1 == 0) {
      iVar1 = memdescMapOld(*param_3,0,param_2,1,3,param_4,param_5);
      if (iVar1 == 0) {
        portMemSet(*param_4,0,param_2);
        return 0;
      }
      nvAssertOkFailedNoLog
                (iVar1,
                 "memdescMapOld(*ppMemDesc, 0, size, NV_TRUE, NV_PROTECT_READ_WRITE, ppMap, ppPriv)"
                 ,"src/kernel/gpu/mem_mgr/mem_utils.c",0xab);
    }
    else {
      nvCheckOkFailedNoLog(4,iVar1,"status","src/kernel/gpu/mem_mgr/mem_utils.c",0xa9);
    }
    memdescFree(*param_3);
    memdescDestroy(*param_3);
    *param_3 = 0;
    *param_4 = 0;
    *param_5 = 0;
  }
  else {
    nvAssertOkFailedNoLog
              (iVar1,
               "memdescCreate(ppMemDesc, pGpu, size, RM_PAGE_SIZE, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_CACHED, flags)"
               ,"src/kernel/gpu/mem_mgr/mem_utils.c",0xa3);
  }
  return iVar1;
}


// ===== 003c33d0 _memmgrMemReadOrWriteWithGsp =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _memmgrMemReadOrWriteWithGsp
              (long param_1,long *param_2,undefined8 param_3,ulong param_4,char param_5)

{
  long lVar1;
  char cVar2;
  int iVar3;
  long local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  long local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined1 local_78 [16];
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulong local_48;
  undefined4 local_3c;
  
  lVar1 = *(long *)(param_1 + 0x1d18);
  local_b0 = 0;
  local_a8 = 0;
  local_a0 = 0;
  iVar3 = memdescGetAddressSpace(*param_2);
  if (iVar3 == 1) {
    return 0x56;
  }
  iVar3 = _memmgrAllocAndMapSurface(param_1,param_4,&local_b0,&local_a8,&local_a0);
  if (iVar3 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar3,
               "_memmgrAllocAndMapSurface(pGpu, size, &pStagingBuf, &pStagingBufMap, &pStagingBufPriv)"
               ,"src/kernel/gpu/mem_mgr/mem_utils.c",0xed);
    return iVar3;
  }
  portMemSet(&local_98,0,0x60);
  if (param_5 == '\0') {
    cVar2 = gpuIsCCFeatureEnabled_IMPL(param_1);
    if (cVar2 == '\0') {
      portMemCopy(local_a8,param_4,param_3,param_4);
    }
    else {
      iVar3 = ccslEncryptWithRotationChecks_KERNEL
                        (*(undefined8 *)(lVar1 + 0x2c8),param_4 & 0xffffffff,param_3,0,0,local_a8,
                         local_78);
      if (iVar3 != 0) {
        if (iVar3 == 0x1a) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_utils.c",0x101,"_memmgrMemReadOrWriteWithGsp",4,
                       "NVRM: Fatal error detected in GSP-DMA encrypt: IV Overflow!\n");
          (**(code **)(lVar1 + 0x180))(param_1);
        }
        goto LAB_003c3570;
      }
    }
    local_3c = 0;
    local_48 = param_4;
    local_98 = memdescGetPhysAddr(local_b0,1,0);
    local_88 = 0;
    local_90 = *(undefined8 *)(local_b0 + 0x30);
    local_7c = *(undefined4 *)(local_b0 + 0x74);
    local_80 = memdescGetAddressSpace();
    local_68 = memdescGetPhysAddr(*param_2,1,0);
    local_60 = *(undefined8 *)(*param_2 + 0x30);
    local_58 = param_2[1];
    local_4c = *(undefined4 *)(*param_2 + 0x74);
    local_50 = memdescGetAddressSpace();
    iVar3 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800afa,&local_98,0x60);
    if (iVar3 == 0) goto LAB_003c3570;
  }
  else {
    local_3c = 0;
    local_48 = param_4;
    local_98 = memdescGetPhysAddr(*param_2,1,0);
    local_90 = *(undefined8 *)(*param_2 + 0x30);
    local_88 = param_2[1];
    local_7c = *(undefined4 *)(*param_2 + 0x74);
    local_80 = memdescGetAddressSpace();
    local_68 = memdescGetPhysAddr(local_b0,1,0);
    local_60 = *(undefined8 *)(local_b0 + 0x30);
    local_58 = 0;
    local_4c = *(undefined4 *)(local_b0 + 0x74);
    local_50 = memdescGetAddressSpace();
    iVar3 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800afa,&local_98,0x60);
    if (iVar3 == 0) {
      cVar2 = gpuIsCCFeatureEnabled_IMPL(param_1);
      if (cVar2 == '\0') {
        portMemCopy(param_3,param_4,local_a8,param_4);
      }
      else {
        iVar3 = ccslDecryptWithRotationChecks_KERNEL
                          (*(undefined8 *)(lVar1 + 0x2c8),param_4 & 0xffffffff,local_a8,0,0,0,
                           param_3,local_78);
        if (iVar3 != 0) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_utils.c",0x146,"_memmgrMemReadOrWriteWithGsp",4,
                       "NVRM: Fatal error detected in GSP-DMA decrypt: 0x%x!\n",iVar3);
          (**(code **)(lVar1 + 0x180))(param_1);
        }
      }
      goto LAB_003c3570;
    }
  }
  nvAssertOkFailedNoLog
            (iVar3,
             "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_MEMMGR_MEMORY_TRANSFER_WITH_GSP, &gspParams, sizeof(gspParams))"
             ,"src/kernel/gpu/mem_mgr/mem_utils.c",0x132);
LAB_003c3570:
  lVar1 = local_b0;
  memdescUnmapOld(local_b0,1,local_a8,local_a0);
  memdescFree(lVar1);
  memdescDestroy(lVar1);
  return iVar3;
}


// ===== 003c3820 memUtilsLeastCommonAlignment =====

ulong memUtilsLeastCommonAlignment(ulong param_1,ulong param_2)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar4 = param_1;
  if (param_2 <= param_1) {
    uVar4 = param_2;
    param_2 = param_1;
  }
  uVar1 = param_2;
  uVar3 = uVar4;
  if (uVar4 != 0) {
    do {
      uVar2 = uVar3;
      uVar3 = uVar1 % uVar2;
      uVar1 = uVar2;
    } while (uVar3 != 0);
    uVar1 = (uVar4 / uVar2) * param_2;
    if (((uVar1 < param_2) || (uVar1 % param_2 != 0)) || (uVar1 % uVar4 != 0)) {
      nvCheckFailedNoLog(4,"Alignment limit exceeded","src/kernel/gpu/mem_mgr/mem_utils.c",0x3a1);
      return 0xffffffffffffffff;
    }
  }
  return uVar1;
}


// ===== 003c38b0 memUtilsInitFBAllocInfo =====

void memUtilsInitFBAllocInfo
               (undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  *(undefined4 *)(*(long *)(param_2 + 0x24) + 0x10) = param_1[1];
  uVar1 = *param_1;
  param_2[1] = 0;
  *param_2 = uVar1;
  *(undefined8 *)(param_2 + 0xc) = 0;
  *(undefined8 *)(param_2 + 10) = 0;
  param_2[2] = param_1[4];
  param_2[3] = param_1[3];
  param_2[4] = param_1[5];
  uVar2 = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(param_2 + 6) = uVar2;
  *(undefined8 *)(param_2 + 0x1e) = uVar2;
  uVar2 = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(param_2 + 0xe) = 0xffffffffffffffff;
  *(undefined8 *)(param_2 + 0x20) = uVar2;
  *(undefined4 *)(*(long *)(param_2 + 0x24) + 8) = param_1[2];
  uVar1 = param_1[6];
  **(undefined4 **)(param_2 + 0x24) = uVar1;
  param_2[0x11] = uVar1;
  uVar1 = param_1[7];
  *(undefined4 *)(*(long *)(param_2 + 0x24) + 4) = uVar1;
  param_2[0x12] = uVar1;
  param_2[0x13] = param_1[8];
  uVar1 = param_1[9];
  param_2[0x15] = 0;
  param_2[0x14] = uVar1;
  uVar1 = param_1[0x1a];
  param_2[0x10] = 0;
  param_2[0x29] = uVar1;
  uVar2 = 0x1000;
  param_2[0x26] = param_3;
  param_2[0x27] = param_4;
  if ((*(ushort *)(param_1 + 2) & 0x180) != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x12);
  }
  *(undefined8 *)(param_2 + 8) = uVar2;
  if ((*(byte *)(param_1 + 2) & 0x10) != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x14);
    *(undefined8 *)(param_2 + 0xe) = uVar2;
    *(undefined8 *)(param_2 + 0x22) = uVar2;
  }
  return;
}


// ===== 003c39a0 memmgrMemUtilsGetMemDescFromHandle_IMPL =====

undefined8
memmgrMemUtilsGetMemDescFromHandle_IMPL(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long local_10;
  
  iVar1 = serverutilGetResourceRef(param_2,param_3,&local_10);
  if (iVar1 == 0) {
    lVar2 = __nvoc_dynamicCast(*(undefined8 *)(local_10 + 8),__nvoc_class_def_Memory);
    uVar3 = 0;
    if (lVar2 != 0) {
      uVar3 = *(undefined8 *)(lVar2 + 0x118);
    }
    return uVar3;
  }
  return 0;
}


// ===== 003c39f0 memmgrMemEndTransfer_IMPL =====

void memmgrMemEndTransfer_IMPL(long param_1,undefined8 *param_2,undefined8 param_3,uint param_4)

{
  undefined8 uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  iVar3 = memmgrGetMemTransferType(param_1,param_2,0);
  uVar1 = *param_2;
  uVar5 = 0;
  if (param_1 != 0) {
    uVar5 = *(undefined8 *)(param_1 + 0x150);
  }
  uVar5 = gpuEngineGetGpu(uVar5);
  iVar4 = memmgrCheckSurfaceBounds(param_2,param_3);
  if (iVar4 == 0) {
    lVar2 = param_2[2];
    if (lVar2 != 0) {
      if (iVar3 - 1U < 4) {
        iVar3 = memmgrMemWrite_IMPL(param_1,param_2,lVar2,param_3,param_4);
        if (iVar3 != 0) {
          nvAssertOkFailedNoLog
                    (iVar3,
                     "memmgrMemWrite(pMemoryManager, pTransferInfo, pTransferInfo->pMapping, memSz, flags)"
                     ,"src/kernel/gpu/mem_mgr/mem_utils.c",0x580);
        }
        portMemFree(param_2[2]);
      }
      else if ((param_4 & 0x20) == 0) {
        memdescUnmapInternal(uVar5,uVar1,param_4);
      }
      else {
        memdescUnmap(uVar1,1,lVar2,param_2[3]);
      }
      param_2[2] = 0;
      param_2[3] = 0;
    }
    return;
  }
  nvAssertFailedNoLog("memmgrCheckSurfaceBounds(pTransferInfo, memSz) == NV_OK",
                      "src/kernel/gpu/mem_mgr/mem_utils.c",0x568);
  return;
}


// ===== 003c3b20 memmgrMemReadWithTransferType =====

int memmgrMemReadWithTransferType
              (long param_1,undefined8 param_2,long param_3,undefined8 param_4,int param_5,
              uint param_6)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  undefined8 uVar4;
  
  uVar4 = 0;
  if (param_1 != 0) {
    uVar4 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar2 = gpuEngineGetGpu(uVar4);
  iVar1 = memmgrCheckSurfaceBounds(param_2,param_4);
  if (iVar1 == 0) {
    if (param_3 != 0) {
      if (param_5 == 1) {
        if (*(char *)(lVar2 + 0x909) == '\0') {
          nvAssertFailedNoLog(&DAT_00d52a40,"src/kernel/gpu/mem_mgr/mem_utils.c",0x365);
          return 0x1f;
        }
        iVar1 = _memmgrMemReadOrWriteWithGsp(lVar2,param_2,param_3,param_4,1);
        uVar4 = 0x35f;
        pcVar3 = "_memmgrMemReadOrWriteWithGsp(pGpu, pSrcInfo, pBuf, size, NV_TRUE )";
        if (iVar1 == 0) {
          return 0;
        }
      }
      else {
        if (2 < param_5 - 2U) {
          lVar2 = memmgrMemBeginTransfer_IMPL(param_1,param_2,param_4,param_6 | 0x800);
          if (lVar2 == 0) {
            nvCheckFailedNoLog(1,"pSrc != NULL","src/kernel/gpu/mem_mgr/mem_utils.c",0x357);
            return 0x1a;
          }
          portMemCopy(param_3,param_4,lVar2,param_4);
          memmgrMemEndTransfer_IMPL(param_1,param_2,param_4,param_6 | 0x800);
          return 0;
        }
        iVar1 = _memmgrMemReadOrWriteUsingStagingBuffer(param_1,param_2,param_3,param_4,param_5,1);
        if (iVar1 == 0) {
          return 0;
        }
        uVar4 = 0x36b;
        pcVar3 = 
        "_memmgrMemReadOrWriteUsingStagingBuffer(pMemoryManager, pSrcInfo, pBuf, size, transferType, NV_TRUE )"
        ;
      }
      nvCheckOkFailedNoLog(4,iVar1,pcVar3,"src/kernel/gpu/mem_mgr/mem_utils.c",uVar4);
      return iVar1;
    }
    nvAssertFailedNoLog("pBuf != NULL","src/kernel/gpu/mem_mgr/mem_utils.c",0x34f);
  }
  else {
    nvAssertOkFailedNoLog
              (0x1f,"memmgrCheckSurfaceBounds(pSrcInfo, size)","src/kernel/gpu/mem_mgr/mem_utils.c",
               0x34e);
  }
  return 0x1f;
}


// ===== 003c3d40 memmgrMemReadOrWriteInBlocks.isra.0 =====

/* WARNING: Type propagation algorithm not settling */

ulong memmgrMemReadOrWriteInBlocks_isra_0
                (undefined8 param_1,undefined8 *param_2,long param_3,long param_4,undefined *param_5
                ,int param_6,uint param_7,char param_8)

{
  uint uVar1;
  undefined8 *puVar2;
  ulong uVar3;
  long lVar4;
  undefined *puVar5;
  long lVar6;
  uint uVar7;
  undefined8 *local_60;
  undefined8 *local_58;
  long local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  if (param_5 == (undefined *)0x0) {
    return 0;
  }
  lVar6 = 0;
  uVar7 = param_7 & 0x20;
  do {
    local_60 = (undefined8 *)0x0;
    local_58 = (undefined8 *)0x0;
    lVar4 = lVar6 + param_3;
    puVar5 = (undefined *)0x100000;
    if (param_5 < &DAT_00100001) {
      puVar5 = param_5;
    }
    local_50 = 0;
    local_48 = 0;
    local_40 = 0;
    puVar2 = param_2;
    if (uVar7 == 0 && param_6 == 0) {
      uVar1 = memdescCreateSubMem(&local_60,param_2,*param_2,lVar4,puVar5);
      if (uVar1 != 0) {
        nvAssertOkFailedNoLog
                  (uVar1,
                   "memdescCreateSubMem(&pSubMemDesc, pMemDesc, pMemDesc->pGpu, offset + baseOffset, copySize)"
                   ,"src/kernel/gpu/mem_mgr/mem_utils.c",0x492);
        return (ulong)uVar1;
      }
      uVar3 = memdescGetPageSize(local_60,1);
      if (0x200000 < uVar3) {
        memdescSetPageSize(local_60,1,0x200000);
      }
      lVar4 = 0;
      puVar2 = local_60;
    }
    local_58 = puVar2;
    local_50 = lVar4;
    if (param_8 == '\0') {
      uVar3 = memmgrMemWriteWithTransferType();
      if ((int)uVar3 == 0) goto LAB_003c3d8d;
LAB_003c3e28:
      nvAssertOkFailedNoLog(uVar3 & 0xffffffff,"status","src/kernel/gpu/mem_mgr/mem_utils.c",0x4b1);
      uVar3 = uVar3 & 0xffffffff;
      if (uVar7 != 0 || param_6 != 0) {
        return uVar3;
      }
LAB_003c3ea0:
      memdescFree(local_60);
      memdescDestroy(local_60);
      uVar3 = uVar3 & 0xffffffff;
    }
    else {
      uVar3 = memmgrMemReadWithTransferType
                        (param_1,&local_58,lVar6 + param_4,puVar5,param_6,param_7);
      if ((int)uVar3 != 0) goto LAB_003c3e28;
LAB_003c3d8d:
      if (uVar7 == 0 && param_6 == 0) goto LAB_003c3ea0;
    }
    lVar6 = lVar6 + (long)puVar5;
    param_5 = param_5 + -(long)puVar5;
    if (param_5 == (undefined *)0x0) {
      return uVar3;
    }
    if ((int)uVar3 != 0) {
      return uVar3;
    }
  } while( true );
}


// ===== 003c3f10 memmgrMemRead_IMPL =====

void memmgrMemRead_IMPL(undefined8 param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4
                       ,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = memmgrGetMemTransferType(param_1,0,param_2,param_5);
  iVar2 = memmgrMemReadWithTransferType(param_1,param_2,param_3,param_4,uVar1,param_5);
  if (iVar2 != 0) {
    memmgrMemReadOrWriteInBlocks_isra_0(param_1,*param_2,param_2[1],param_3,param_4,uVar1,param_5,1)
    ;
  }
  return;
}


// ===== 003c3f90 memmgrMemBeginTransfer_IMPL =====

long memmgrMemBeginTransfer_IMPL(long param_1,undefined8 *param_2,undefined8 param_3,uint param_4)

{
  undefined8 uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  char cVar7;
  long local_48;
  undefined8 local_40 [2];
  
  iVar3 = memmgrGetMemTransferType(param_1,param_2,0);
  uVar5 = 0;
  uVar1 = *param_2;
  lVar2 = param_2[1];
  if (param_1 != 0) {
    uVar5 = *(undefined8 *)(param_1 + 0x150);
  }
  uVar5 = gpuEngineGetGpu(uVar5);
  local_48 = 0;
  local_40[0] = 0;
  lVar6 = memdescGetKernelMapping(*param_2);
  iVar4 = memmgrCheckSurfaceBounds(param_2,param_3);
  if (iVar4 == 0) {
    if (param_2[2] == 0) {
      if (param_2[3] == 0) {
        if (((param_4 & 0x800) != 0) && (lVar6 != 0)) {
          return param_2[1] + lVar6;
        }
        if (iVar3 - 1U < 4) {
          if ((param_4 & 2) != 0) {
            local_48 = portMemAllocNonPaged(param_3);
            if (local_48 == 0) {
              nvAssertFailedNoLog("(pPtr = portMemAllocNonPaged(memSz))",
                                  "src/kernel/gpu/mem_mgr/mem_utils.c",0x542);
              return 0;
            }
            if (((param_4 & 4) != 0) &&
               (iVar3 = memmgrMemRead_IMPL(param_1,param_2,local_48,param_3,param_4), iVar3 != 0)) {
              nvAssertOkFailedNoLog
                        (iVar3,"memmgrMemRead(pMemoryManager, pTransferInfo, pPtr, memSz, flags)",
                         "src/kernel/gpu/mem_mgr/mem_utils.c",0x545);
            }
          }
        }
        else if ((param_4 & 0x20) == 0) {
          local_48 = memdescMapInternal(uVar5,uVar1,param_4);
          if (local_48 == 0) {
            nvCheckFailedNoLog(1,"(pPtr = memdescMapInternal(pGpu, pMemDesc, flags)) != NULL",
                               "src/kernel/gpu/mem_mgr/mem_utils.c",0x537);
            return 0;
          }
          local_48 = local_48 + lVar2;
        }
        else {
          cVar7 = '\x01';
          if ((param_4 & 0x100) == 0) {
            cVar7 = ((param_4 & 0x200) == 0) + '\x02';
          }
          iVar3 = memdescMapOld(uVar1,lVar2,param_3,1,cVar7,&local_48,local_40);
          if (iVar3 != 0) {
            nvCheckFailedNoLog(4,
                               "memdescMapOld(pMemDesc, offset, memSz, NV_TRUE, protect, &pPtr, &pPriv) == NV_OK"
                               ,"src/kernel/gpu/mem_mgr/mem_utils.c",0x532);
            return 0;
          }
        }
        param_2[2] = local_48;
        param_2[3] = local_40[0];
      }
      else {
        nvAssertFailedNoLog("pTransferInfo->pMappingPriv == NULL",
                            "src/kernel/gpu/mem_mgr/mem_utils.c",0x51a);
        local_48 = 0;
      }
      return local_48;
    }
    nvAssertFailedNoLog("pTransferInfo->pMapping == NULL","src/kernel/gpu/mem_mgr/mem_utils.c",0x519
                       );
  }
  else {
    nvAssertFailedNoLog("memmgrCheckSurfaceBounds(pTransferInfo, memSz) == NV_OK",
                        "src/kernel/gpu/mem_mgr/mem_utils.c",0x518);
  }
  return 0;
}


// ===== 003c4260 memmgrMemCopyWithTransferType =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrMemCopyWithTransferType
              (long param_1,long *param_2,long *param_3,uint param_4,int param_5,uint param_6)

{
  ulong uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  undefined8 extraout_RDX;
  undefined8 *puVar7;
  undefined8 uVar8;
  long local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  long local_a8;
  undefined8 local_a0;
  long local_98;
  long local_90;
  long local_88;
  undefined8 local_80;
  ulong local_78 [5];
  undefined8 local_50;
  ulong local_48;
  ulong local_40;
  
  uVar8 = 0;
  if (param_1 != 0) {
    uVar8 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar5 = gpuEngineGetGpu(uVar8);
  uVar1 = (ulong)param_4;
  iVar3 = memmgrCheckSurfaceBounds(param_2,uVar1);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (0x1f,"memmgrCheckSurfaceBounds(pDstInfo, size)","src/kernel/gpu/mem_mgr/mem_utils.c",
               0x244);
    return 0x1f;
  }
  iVar3 = memmgrCheckSurfaceBounds(param_3,uVar1);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (0x1f,"memmgrCheckSurfaceBounds(pSrcInfo, size)","src/kernel/gpu/mem_mgr/mem_utils.c",
               0x245);
    return 0x1f;
  }
  cVar2 = memdescDescIsEqual(*param_2,*param_3);
  if (cVar2 != '\0') {
    nvAssertFailedNoLog("!memdescDescIsEqual(pDstInfo->pMemDesc, pSrcInfo->pMemDesc)",
                        "src/kernel/gpu/mem_mgr/mem_utils.c",0x246);
    return 0x1f;
  }
  if (param_5 == 3) {
    nvAssertFailedNoLog(&DAT_00d52a40,"src/kernel/gpu/mem_mgr/mem_utils.c",0x277);
    return 0x40;
  }
  if (param_5 == 4) {
    nvAssertFailedNoLog(&DAT_00d52a40,"src/kernel/gpu/mem_mgr/mem_utils.c",0x27a);
    return 0x40;
  }
  if (param_5 != 1) {
    if (param_5 == 2) {
      if (*(long *)(param_1 + 0x4a0) == 0) {
        nvAssertFailedNoLog("pMemoryManager->pCeUtils != NULL","src/kernel/gpu/mem_mgr/mem_utils.c",
                            0x269);
        return 0x40;
      }
      local_90 = *param_2;
      local_78[1] = 0;
      local_78[2] = 0;
      local_88 = param_2[1];
      local_78[3] = 0;
      local_98 = *param_3;
      local_78[4] = 0;
      local_80 = param_3[1];
      local_50 = 0;
      local_48 = 0;
      local_40 = 0;
      local_78[0] = uVar1;
      iVar3 = ceutilsMemcopy_IMPL(*(long *)(param_1 + 0x4a0),&local_98);
      return iVar3;
    }
    param_6 = param_6 | 0x800;
    lVar5 = memmgrMemBeginTransfer_IMPL(param_1,param_2,uVar1,param_6);
    lVar6 = memmgrMemBeginTransfer_IMPL(param_1,param_3,uVar1,param_6);
    if ((lVar5 != 0) && (lVar6 != 0)) {
      portMemCopy(lVar5,uVar1,lVar6,uVar1);
      memmgrMemEndTransfer_IMPL(param_1,param_3,uVar1,param_6);
      memmgrMemEndTransfer_IMPL(param_1,param_2,uVar1,param_6);
      return 0;
    }
    memmgrMemEndTransfer_IMPL(param_1,param_3,uVar1,param_6);
    memmgrMemEndTransfer_IMPL(param_1,param_2,uVar1,param_6);
    if ((lVar5 != 0) && (lVar6 != 0)) {
      return 0;
    }
    nvCheckFailedNoLog(4,"pDst != NULL && pSrc != NULL","src/kernel/gpu/mem_mgr/mem_utils.c",0x259);
    return 0x1a;
  }
  if (*(char *)(lVar5 + 0x909) == '\0') {
    nvAssertFailedNoLog(&DAT_00d52a40,"src/kernel/gpu/mem_mgr/mem_utils.c",0x264);
    return 0x1f;
  }
  local_c0 = 0;
  local_b8 = 0;
  lVar6 = *(long *)(lVar5 + 0x1d18);
  local_b0 = 0;
  local_a8 = 0;
  local_a0 = 0;
  iVar3 = memdescGetAddressSpace(*param_3);
  if ((iVar3 == 1) && (iVar3 = memdescGetAddressSpace(*param_2), iVar3 == 1)) {
    iVar3 = 0x56;
    goto LAB_003c48d8;
  }
  iVar3 = _memmgrAllocAndMapSurface(lVar5,uVar1,&local_c0,&local_b8,&local_b0);
  if (iVar3 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar3,
               "_memmgrAllocAndMapSurface(pGpu, size, &pStagingBuf, &pStagingBufMap, &pStagingBufPriv)"
               ,"src/kernel/gpu/mem_mgr/mem_utils.c",0x17e);
    goto LAB_003c48d8;
  }
  portMemSet(&local_98,0,0x60);
  local_40 = local_40 & 0xffffffff;
  local_48 = uVar1;
  iVar3 = memdescGetAddressSpace(*param_3);
  if (iVar3 == 1) {
    iVar3 = memdescMapOld(*param_3,0,uVar1,1,3,&local_a8);
    if (iVar3 == 0) {
      uVar8 = 0x3c47c8;
      cVar2 = gpuIsCCFeatureEnabled_IMPL(lVar5);
      if (cVar2 == '\0') {
        portMemCopy(local_b8,uVar1,param_3[1] + local_a8,uVar1);
        memdescUnmapOld(*param_3,1,local_a8,local_a0);
LAB_003c4841:
        local_98 = memdescGetPhysAddr(local_c0,1,0);
        local_90 = *(undefined8 *)(local_c0 + 0x30);
        local_88 = 0;
        local_80._4_4_ = *(undefined4 *)(local_c0 + 0x74);
        uVar4 = memdescGetAddressSpace();
        local_80 = CONCAT44(local_80._4_4_,uVar4);
        goto LAB_003c4883;
      }
      iVar3 = ccslEncryptWithRotationChecks_KERNEL
                        (*(undefined8 *)(lVar6 + 0x2c8),param_4,param_3[1] + local_a8,0,0,local_b8,
                         local_78);
      if (iVar3 == 0x1a) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_utils.c",0x19b,"_memmgrMemcpyWithGsp",4,
                     "NVRM: Fatal error detected in GSP-DMA encrypt: IV Overflow!\n");
        (**(code **)(lVar6 + 0x180))(lVar5,lVar6);
        memdescUnmapOld(*param_3,1,local_a8,local_a0);
      }
      else {
        memdescUnmapOld(*param_3,1,local_a8,local_a0,uVar8);
        if (iVar3 == 0) goto LAB_003c4841;
      }
      nvAssertOkFailedNoLog(iVar3,"status","src/kernel/gpu/mem_mgr/mem_utils.c",0x1a6);
    }
    else {
      nvAssertOkFailedNoLog
                (iVar3,
                 "memdescMapOld(pSrc->pMemDesc, 0, size, NV_TRUE, NV_PROTECT_READ_WRITE, (void**)&pMap, &pPriv)"
                 ,"src/kernel/gpu/mem_mgr/mem_utils.c",0x18a);
    }
  }
  else {
    local_98 = memdescGetPhysAddr(*param_3,1,0);
    local_90 = *(undefined8 *)(*param_3 + 0x30);
    local_88 = param_3[1];
    local_80._4_4_ = *(undefined4 *)(*param_3 + 0x74);
    uVar4 = memdescGetAddressSpace();
    local_80 = CONCAT44(local_80._4_4_,uVar4);
    iVar3 = memdescGetAddressSpace(*param_2);
    if (iVar3 == 2) {
LAB_003c4883:
      local_78[2] = memdescGetPhysAddr(*param_2,1,0);
      local_78[3] = *(undefined8 *)(*param_2 + 0x30);
      local_78[4] = param_2[1];
      local_50 = CONCAT44(*(undefined4 *)(*param_2 + 0x74),(undefined4)local_50);
      uVar4 = memdescGetAddressSpace();
    }
    else {
      local_78[2] = memdescGetPhysAddr(local_c0,1,0);
      local_78[3] = *(undefined8 *)(local_c0 + 0x30);
      local_78[4] = 0;
      local_50 = CONCAT44(*(undefined4 *)(local_c0 + 0x74),(undefined4)local_50);
      uVar4 = memdescGetAddressSpace();
    }
    local_50 = CONCAT44(local_50._4_4_,uVar4);
    iVar3 = (**(code **)(lVar5 + 0x3b90))
                      (lVar5 + 0x3b58,*(undefined4 *)(lVar5 + 0x3b34),
                       *(undefined4 *)(lVar5 + 0x3b3c),0x20800afa,&local_98,0x60);
    if (iVar3 == 0) {
      uVar8 = 0x3c4652;
      iVar3 = memdescGetAddressSpace(*param_2);
      if (iVar3 != 1) goto LAB_003c4662;
      puVar7 = &local_a0;
      iVar3 = memdescMapOld(*param_2,0,uVar1,1,3,&local_a8);
      if (iVar3 == 0) {
        cVar2 = gpuIsCCFeatureEnabled_IMPL(lVar5,uVar8,extraout_RDX,puVar7);
        if (cVar2 == '\0') {
          portMemCopy(param_2[1] + local_a8,uVar1,local_b8,uVar1);
        }
        else {
          iVar3 = ccslDecryptWithRotationChecks_KERNEL
                            (*(undefined8 *)(lVar6 + 0x2c8),param_4,local_b8,0,0,0,
                             param_2[1] + local_a8,local_78);
          if (iVar3 != 0) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_utils.c",0x1f1,"_memmgrMemcpyWithGsp",4,
                         "NVRM: Fatal error detected in GSP-DMA decrypt: 0x%x!\n",iVar3);
            (**(code **)(lVar6 + 0x180))(lVar5,lVar6);
            memdescUnmapOld(*param_2,1,local_a8,local_a0);
            nvAssertOkFailedNoLog(iVar3,"status","src/kernel/gpu/mem_mgr/mem_utils.c",0x1fc);
            goto LAB_003c4aac;
          }
        }
        memdescUnmapOld(*param_2,1,local_a8,local_a0);
LAB_003c4662:
        lVar5 = local_c0;
        memdescUnmapOld(local_c0,1,local_b8,local_b0);
        memdescFree(lVar5);
        memdescDestroy(lVar5);
        return 0;
      }
      nvAssertOkFailedNoLog
                (iVar3,
                 "memdescMapOld(pDst->pMemDesc, 0, size, NV_TRUE, NV_PROTECT_READ_WRITE, (void**)&pMap, &pPriv)"
                 ,"src/kernel/gpu/mem_mgr/mem_utils.c",0x1e0);
    }
    else {
      nvAssertOkFailedNoLog
                (iVar3,
                 "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_MEMMGR_MEMORY_TRANSFER_WITH_GSP, &gspParams, sizeof(gspParams))"
                 ,"src/kernel/gpu/mem_mgr/mem_utils.c",0x1d4);
    }
  }
LAB_003c4aac:
  lVar5 = local_c0;
  memdescUnmapOld(local_c0,1,local_b8,local_b0);
  memdescFree(lVar5);
  memdescDestroy(lVar5);
LAB_003c48d8:
  nvAssertOkFailedNoLog
            (iVar3,"_memmgrMemcpyWithGsp(pGpu, pDstInfo, pSrcInfo, size)",
             "src/kernel/gpu/mem_mgr/mem_utils.c",0x25f);
  return iVar3;
}


// ===== 003c4c80 memmgrMemCopy_IMPL =====

void memmgrMemCopy_IMPL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = memmgrGetMemTransferType();
  memmgrMemCopyWithTransferType(param_1,param_2,param_3,param_4,uVar1,param_5);
  return;
}


// ===== 003c4cd0 _memmgrMemReadOrWriteUsingStagingBuffer =====

int _memmgrMemReadOrWriteUsingStagingBuffer
              (long param_1,undefined8 *param_2,undefined8 param_3,ulong param_4,undefined4 param_5,
              char param_6)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  puVar3 = &local_58;
  if (param_6 != '\0') {
    puVar3 = param_2;
    param_2 = &local_58;
  }
  uVar2 = 0;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  if (param_1 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x150);
  }
  uVar2 = gpuEngineGetGpu(uVar2);
  iVar1 = _memmgrAllocAndMapSurface(uVar2,param_4,&local_70,&local_68,&local_60);
  if (iVar1 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar1,
               "_memmgrAllocAndMapSurface(ENG_GET_GPU(pMemoryManager), size, &pStagingBuf, &pStagingBufMap, &pStagingBufPriv)"
               ,"src/kernel/gpu/mem_mgr/mem_utils.c",0x294);
    return iVar1;
  }
  local_58 = local_70;
  if (param_6 == '\0') {
    portMemCopy(local_68,param_4,param_3,param_4);
    iVar1 = memmgrMemCopyWithTransferType(param_1,param_2,puVar3,param_4 & 0xffffffff,param_5,0);
    if (iVar1 == 0) goto LAB_003c4dd3;
  }
  else {
    iVar1 = memmgrMemCopyWithTransferType(param_1,param_2,puVar3,param_4 & 0xffffffff,param_5,0);
    if (iVar1 == 0) {
      portMemCopy(param_3,param_4,local_68,param_4);
      goto LAB_003c4dd3;
    }
  }
  nvAssertOkFailedNoLog
            (iVar1,
             "memmgrMemCopyWithTransferType(pMemoryManager, pDst, pSrc, size, transferType, 0)",
             "src/kernel/gpu/mem_mgr/mem_utils.c",0x29e);
LAB_003c4dd3:
  uVar2 = local_70;
  memdescUnmapOld(local_70,1,local_68,local_60);
  memdescFree(uVar2);
  memdescDestroy(uVar2);
  return iVar1;
}


// ===== 003c4e80 memmgrMemWriteWithTransferType =====

int memmgrMemWriteWithTransferType
              (long param_1,undefined8 param_2,long param_3,undefined8 param_4,int param_5,
              uint param_6)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  undefined8 uVar4;
  
  uVar4 = 0;
  if (param_1 != 0) {
    uVar4 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar2 = gpuEngineGetGpu(uVar4);
  iVar1 = memmgrCheckSurfaceBounds(param_2,param_4);
  if (iVar1 == 0) {
    if (param_3 != 0) {
      if (param_5 == 1) {
        if (*(char *)(lVar2 + 0x909) == '\0') {
          nvAssertFailedNoLog(&DAT_00d52a40,"src/kernel/gpu/mem_mgr/mem_utils.c",0x326);
          return 0x1f;
        }
        nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_utils.c",799,"memmgrMemWriteWithTransferType",1,
                     "NVRM: Calling GSP DMA task\n");
        iVar1 = _memmgrMemReadOrWriteWithGsp(lVar2,param_2,param_3,param_4,0);
        uVar4 = 800;
        pcVar3 = "_memmgrMemReadOrWriteWithGsp(pGpu, pDstInfo, pBuf, size, NV_FALSE )";
        if (iVar1 == 0) {
          return 0;
        }
      }
      else {
        if (2 < param_5 - 2U) {
          lVar2 = memmgrMemBeginTransfer_IMPL(param_1,param_2,param_4,param_6 | 0x800);
          if (lVar2 == 0) {
            nvCheckFailedNoLog(4,"pDst != NULL","src/kernel/gpu/mem_mgr/mem_utils.c",0x317);
            return 0x1a;
          }
          portMemCopy(lVar2,param_4,param_3,param_4);
          memmgrMemEndTransfer_IMPL(param_1,param_2,param_4,param_6 | 0x800);
          return 0;
        }
        iVar1 = _memmgrMemReadOrWriteUsingStagingBuffer(param_1,param_2,param_3,param_4,param_5,0);
        if (iVar1 == 0) {
          return 0;
        }
        uVar4 = 0x32c;
        pcVar3 = 
        "_memmgrMemReadOrWriteUsingStagingBuffer(pMemoryManager, pDstInfo, pBuf, size, transferType, NV_FALSE )"
        ;
      }
      nvCheckOkFailedNoLog(4,iVar1,pcVar3,"src/kernel/gpu/mem_mgr/mem_utils.c",uVar4);
      return iVar1;
    }
    nvAssertFailedNoLog("pBuf != NULL","src/kernel/gpu/mem_mgr/mem_utils.c",0x30f);
  }
  else {
    nvAssertOkFailedNoLog
              (0x1f,"memmgrCheckSurfaceBounds(pDstInfo, size)","src/kernel/gpu/mem_mgr/mem_utils.c",
               0x30e);
  }
  return 0x1f;
}


// ===== 003c50c0 memmgrMemWrite_IMPL =====

void memmgrMemWrite_IMPL(undefined8 param_1,undefined8 *param_2,undefined8 param_3,
                        undefined8 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = memmgrGetMemTransferType(param_1,param_2,0,param_5);
  iVar2 = memmgrMemWriteWithTransferType(param_1,param_2,param_3,param_4,uVar1,param_5);
  if (iVar2 != 0) {
    memmgrMemReadOrWriteInBlocks_isra_0(param_1,*param_2,param_2[1],param_3,param_4,uVar1,param_5,0)
    ;
  }
  return;
}


// ===== 003c5140 memmgrMemSetWithTransferType =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrMemSetWithTransferType
              (long param_1,long *param_2,uint param_3,ulong param_4,int param_5,uint param_6)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined1 local_9c;
  long local_98;
  long local_90;
  ulong local_88;
  uint local_80;
  undefined8 local_7c;
  undefined8 local_74;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  long local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulong local_48;
  ulong local_40;
  
  uVar3 = 0;
  param_4 = param_4 & 0xffffffff;
  if (param_1 != 0) {
    uVar3 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar2 = gpuEngineGetGpu(uVar3);
  iVar1 = memmgrCheckSurfaceBounds(param_2,param_4);
  if (iVar1 == 0) {
    if (param_5 == 2) {
      if (*(long *)(param_1 + 0x4a0) != 0) {
        local_98 = *param_2;
        local_7c = 0;
        local_74 = 0;
        local_90 = param_2[1];
        uStack_6c = 0;
        local_68 = 0;
        uStack_64 = 0;
        local_60 = 0;
        uStack_5c = 0;
        local_88 = param_4;
        local_80 = param_3;
        iVar1 = ceutilsMemset_IMPL(*(long *)(param_1 + 0x4a0),&local_98);
        return iVar1;
      }
      nvAssertFailedNoLog("pMemoryManager->pCeUtils != NULL","src/kernel/gpu/mem_mgr/mem_utils.c",
                          0x2dd);
      return 0x40;
    }
    if (param_5 == 4) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_utils.c",0x2ed,"memmgrMemSetWithTransferType",4,
                   "NVRM: BAR0 memset unimplemented\n");
      nvAssertFailedNoLog(&DAT_00d52a40,"src/kernel/gpu/mem_mgr/mem_utils.c",0x2ee);
      return 0;
    }
    if (param_5 != 1) {
      lVar2 = memmgrMemBeginTransfer_IMPL(param_1,param_2,param_4,param_6 | 0x800);
      if (lVar2 != 0) {
        local_9c = (undefined1)param_3;
        portMemSet(lVar2,local_9c,param_4);
        memmgrMemEndTransfer_IMPL(param_1,param_2,param_4,param_6 | 0x800);
        return 0;
      }
      nvCheckFailedNoLog(4,"pDst != NULL","src/kernel/gpu/mem_mgr/mem_utils.c",0x2cb);
      return 0x1a;
    }
    if (*(char *)(lVar2 + 0x909) != '\0') {
      iVar1 = memdescGetAddressSpace(*param_2);
      if (iVar1 == 1) {
        iVar1 = 0x56;
      }
      else {
        portMemSet(&local_98,0,0x60);
        local_40 = (ulong)param_3 | 0x100000000;
        local_48 = param_4;
        uVar3 = memdescGetPhysAddr(*param_2,1,0);
        local_68 = (undefined4)uVar3;
        uStack_64 = (undefined4)((ulong)uVar3 >> 0x20);
        uVar3 = *(undefined8 *)(*param_2 + 0x30);
        local_60 = (undefined4)uVar3;
        uStack_5c = (undefined4)((ulong)uVar3 >> 0x20);
        local_58 = param_2[1];
        local_4c = *(undefined4 *)(*param_2 + 0x74);
        local_50 = memdescGetAddressSpace();
        iVar1 = (**(code **)(lVar2 + 0x3b90))
                          (lVar2 + 0x3b58,*(undefined4 *)(lVar2 + 0x3b34),
                           *(undefined4 *)(lVar2 + 0x3b3c),0x20800afa,&local_98,0x60);
        if (iVar1 == 0) {
          return 0;
        }
        nvAssertOkFailedNoLog
                  (iVar1,
                   "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_MEMMGR_MEMORY_TRANSFER_WITH_GSP, &gspParams, sizeof(gspParams))"
                   ,"src/kernel/gpu/mem_mgr/mem_utils.c",0x220);
      }
      nvAssertOkFailedNoLog
                (iVar1,"_memmgrMemsetWithGsp(pGpu, pDstInfo, value, size)",
                 "src/kernel/gpu/mem_mgr/mem_utils.c",0x2d3);
      return iVar1;
    }
    nvAssertFailedNoLog(&DAT_00d52a40,"src/kernel/gpu/mem_mgr/mem_utils.c",0x2d8);
  }
  else {
    nvAssertOkFailedNoLog
              (0x1f,"memmgrCheckSurfaceBounds(pDstInfo, size)","src/kernel/gpu/mem_mgr/mem_utils.c",
               0x2c3);
  }
  return 0x1f;
}


// ===== 003c54b0 memmgrMemSet_IMPL =====

void memmgrMemSet_IMPL(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = memmgrGetMemTransferType(param_1,param_2,0,param_5);
  memmgrMemSetWithTransferType(param_1,param_2,param_3,param_4,uVar1,param_5);
  return;
}


// ===== 003c5500 memmgrMemDescMemSet_IMPL =====

void memmgrMemDescMemSet_IMPL(undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  long local_48 [5];
  
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[0] = param_2;
  uVar1 = memmgrGetMemTransferType(param_1,local_48,0);
  memmgrMemSetWithTransferType
            (param_1,local_48,param_3,*(undefined4 *)(param_2 + 0x30),uVar1,param_4);
  return;
}


// ===== 003c5570 memmgrMemsetInBlocks_IMPL =====

int memmgrMemsetInBlocks_IMPL
              (long param_1,undefined8 param_2,undefined4 param_3,long param_4,ulong param_5,
              undefined4 param_6,uint param_7)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  long local_60;
  long local_58 [5];
  
  uVar4 = 0;
  if (param_1 != 0) {
    uVar4 = *(undefined8 *)(param_1 + 0x150);
  }
  uVar4 = gpuEngineGetGpu(uVar4);
  uVar5 = 0x100000;
  if (param_7 != 0) {
    uVar5 = (ulong)param_7;
  }
  lVar7 = 0;
  while( true ) {
    if (param_5 == 0) {
      return 0;
    }
    uVar6 = param_5;
    if (uVar5 <= param_5) {
      uVar6 = uVar5;
    }
    local_60 = 0;
    local_58[0] = 0;
    local_58[1] = 0;
    local_58[2] = 0;
    local_58[3] = 0;
    iVar2 = memdescCreateSubMem(&local_60,param_2,uVar4,lVar7 + param_4,uVar6);
    if (iVar2 != 0) break;
    local_58[1] = 0;
    uVar1 = *(undefined4 *)(local_60 + 0x30);
    local_58[0] = local_60;
    uVar3 = memmgrGetMemTransferType(param_1,local_58,0,param_6);
    iVar2 = memmgrMemSetWithTransferType(param_1,local_58,param_3,uVar1,uVar3,param_6);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,"memmgrMemSet(pMemoryManager, &surf, value, pSubMemDesc->Size, flags)",
                 "src/kernel/gpu/mem_mgr/mem_utils.c",0x41b);
      return iVar2;
    }
    lVar7 = lVar7 + uVar6;
    memdescFree(local_60);
    memdescDestroy(local_60);
    param_5 = param_5 - uVar6;
  }
  return iVar2;
}


// ===== 003c56e0 memmgrMemDescEndTransfer_IMPL =====

void memmgrMemDescEndTransfer_IMPL(undefined8 param_1,long param_2,undefined4 param_3)

{
  long local_38 [4];
  
  if (param_2 != 0) {
    local_38[1] = 0;
    local_38[2] = 0;
    local_38[3] = 0;
    local_38[0] = param_2;
    local_38[2] = memdescGetKernelMapping(param_2);
    local_38[3] = memdescGetKernelMappingPriv(param_2);
    memdescSetKernelMapping(param_2,0);
    memdescSetKernelMappingPriv(param_2,0);
    memmgrMemEndTransfer_IMPL(param_1,local_38,*(undefined8 *)(param_2 + 0x30),param_3);
    return;
  }
  return;
}


// ===== 003c5770 memmgrMemDescBeginTransfer_IMPL =====

long memmgrMemDescBeginTransfer_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  long lVar1;
  undefined8 uVar2;
  char *pcVar3;
  long local_48 [4];
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("pMemDesc != NULL","src/kernel/gpu/mem_mgr/mem_utils.c",0x5b8);
    return 0;
  }
  lVar1 = memdescGetKernelMapping(param_2);
  uVar2 = 0x5b9;
  pcVar3 = "memdescGetKernelMapping(pMemDesc) == NULL";
  if (lVar1 == 0) {
    lVar1 = memdescGetKernelMappingPriv(param_2,"src/kernel/gpu/mem_mgr/mem_utils.c",0x5b9);
    if (lVar1 != 0) {
      nvAssertFailedNoLog("memdescGetKernelMappingPriv(pMemDesc) == NULL",
                          "src/kernel/gpu/mem_mgr/mem_utils.c",0x5ba);
      return 0;
    }
    if ((param_3 & 0x800) == 0) {
      local_48[1] = 0;
      local_48[2] = 0;
      local_48[3] = 0;
      local_48[0] = param_2;
      lVar1 = memmgrMemBeginTransfer_IMPL(param_1,local_48,*(undefined8 *)(param_2 + 0x30),param_3);
      if (lVar1 == 0) {
        nvAssertFailedNoLog("pMapping != NULL","src/kernel/gpu/mem_mgr/mem_utils.c",0x5c0);
        return 0;
      }
      if (local_48[2] != lVar1) {
        nvAssertFailedNoLog("transferSurface.pMapping == pMapping",
                            "src/kernel/gpu/mem_mgr/mem_utils.c",0x5c1);
        return 0;
      }
      memdescSetKernelMapping(param_2,lVar1);
      memdescSetKernelMappingPriv(param_2,local_48[3]);
      return lVar1;
    }
    uVar2 = 0x5bb;
    pcVar3 = "!(flags & TRANSFER_FLAGS_ALLOW_MAPPING_REUSE)";
  }
  nvAssertFailedNoLog(pcVar3,"src/kernel/gpu/mem_mgr/mem_utils.c",uVar2);
  return 0;
}


// ===== 003c5940 memmgrAllocResources_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrAllocResources_IMPL(long param_1,long param_2,long *param_3,long param_4)

{
  uint uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  
  lVar2 = *param_3;
  iVar4 = memmgrAllocGetAddrSpace_IMPL
                    (param_2,*(undefined4 *)(lVar2 + 8),*(undefined4 *)(param_4 + 0x44));
  cVar3 = osIsRaisedIRQL();
  if (cVar3 != '\0') {
    nvAssertFailedNoLog("!osIsRaisedIRQL()","src/kernel/gpu/mem_mgr/mem_utils.c",0x5e4);
    return 0x2d;
  }
  if ((*(long *)(lVar2 + 0x40) == 0) || (0x11 < *(uint *)(lVar2 + 4))) {
    return 0x1f;
  }
  uVar1 = *(uint *)(param_4 + 0x44);
  if (iVar4 == 4) {
    *(uint *)(param_4 + 0x44) = uVar1 | 0x6000000;
  }
  else if ((uVar1 & 0x2000000) != 0) {
    uVar6 = uVar1 & 0xf9ffffff;
    if (iVar4 != 2) {
      uVar6 = uVar1 & 0xf9ffffff | 0x2000000;
    }
    *(uint *)(param_4 + 0x44) = uVar6;
  }
  if (*(char *)(param_1 + 0x45a) == '\0') {
    lVar7 = (**(code **)(param_2 + 0x168))
                      (param_2,*(undefined4 *)(param_4 + 0x98),*(undefined8 *)(param_4 + 0x18),
                       *(undefined4 *)(param_4 + 0x4c),
                       *(undefined4 *)(*(long *)(param_4 + 0x90) + 8),param_4 + 0x44,param_4 + 0x48)
    ;
    if (lVar7 == 0) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_utils.c",0x611,"memmgrAllocResources_IMPL",4,
                   "NVRM: memmgrDeterminePageSize failed, status: 0x%x\n",0x40);
      return 0x40;
    }
    iVar5 = (**(code **)(param_2 + 0x1f8))
                      (param_1,param_2,param_4 + 0x18,param_4 + 0x20,*(undefined8 *)(param_4 + 0x28)
                       ,*(undefined4 *)(*(long *)(param_4 + 0x90) + 8),
                       *(undefined4 *)(param_4 + 0x44),*(undefined4 *)(param_4 + 0x48),0);
    if (iVar5 != 0) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_utils.c",0x61b,"memmgrAllocResources_IMPL",4,
                   "NVRM: memmgrAllocDetermineAlignment failed, status: 0x%x\n",iVar5);
      return iVar5;
    }
    iVar5 = memmgrAllocHwResources_IMPL(param_1,param_2,param_4);
    *(undefined4 *)(lVar2 + 0x18) = *(undefined4 *)(param_4 + 0x44);
    *(undefined4 *)(lVar2 + 0x1c) = *(undefined4 *)(param_4 + 0x48);
    *(undefined4 *)(lVar2 + 0x20) = *(undefined4 *)(param_4 + 0x4c);
    *(undefined4 *)(lVar2 + 0x24) = *(undefined4 *)(param_4 + 0x50);
    *(undefined4 *)(lVar2 + 0x28) = *(undefined4 *)(param_4 + 0x54);
    if (iVar5 != 0) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_utils.c",0x635,"memmgrAllocResources_IMPL",4,
                   "NVRM: fbAlloc failure!\n");
LAB_003c5c1e:
      (**(code **)(param_2 + 0x170))(param_1,param_2,param_4);
      return iVar5;
    }
    iVar5 = (**(code **)(param_2 + 0x310))(param_1,param_2,param_4);
    if (iVar5 != 0) goto LAB_003c5c1e;
  }
  if ((*(byte *)(lVar2 + 8) & 0x10) != 0) {
    uVar8 = *(ulong *)(param_4 + 0x88) % (*(long *)(param_4 + 0x20) + 1U);
    if (uVar8 != 0) {
      *(ulong *)(param_4 + 0x28) = uVar8;
      *(ulong *)(param_4 + 0x88) = *(ulong *)(param_4 + 0x88) - uVar8;
      goto LAB_003c5ab6;
    }
  }
  uVar8 = *(ulong *)(param_4 + 0x28);
LAB_003c5ab6:
  *(ulong *)(param_4 + 0x80) = *(long *)(param_4 + 0x18) - uVar8;
  *(undefined4 *)(lVar2 + 0x10) = *(undefined4 *)(param_4 + 8);
  *(undefined4 *)(lVar2 + 0x14) = *(undefined4 *)(param_4 + 0x10);
  lVar9 = *(long *)(param_4 + 0x20);
  lVar7 = lVar9 + 1;
  *(long *)(lVar2 + 0x48) = lVar7;
  if (((*(byte *)(lVar2 + 8) & 8) != 0) && (iVar4 == 2)) {
    lVar9 = *(long *)(g_pSys + 0xd0);
    if (lVar9 == 0) {
      lVar9 = 0x1000;
    }
    lVar7 = memUtilsLeastCommonAlignment(lVar7,lVar9);
    lVar9 = lVar7 + -1;
  }
  *(long *)(lVar2 + 0x48) = lVar7;
  *(long *)(param_4 + 0x20) = lVar9;
  return 0;
}


// ===== 003c5ca0 memUtilsAllocMemDesc =====

int memUtilsAllocMemDesc
              (long param_1,long param_2,long param_3,long *param_4,undefined8 param_5,
              undefined8 param_6,undefined1 param_7,undefined1 *param_8)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  
  lVar2 = *(long *)(param_2 + 0x20);
  plVar3 = param_4;
  if (lVar2 == 0) {
    plVar3 = (long *)0x20000;
    if (*(char *)(param_1 + 0x4b2) != '\0') {
      if ((*(uint *)(param_3 + 0x48) & 0x400) != 0) {
        plVar3 = (long *)0x8000000020000;
      }
      if ((*(char *)(param_1 + 0x4bd) != '\0') && ((*(uint *)(param_3 + 0x48) & 0x40000) != 0)) {
        plVar3 = (long *)0x8000000020000;
      }
    }
    iVar1 = memdescCreate(param_2 + 0x20,param_1,*(undefined8 *)(param_3 + 0x80),0,param_7,param_6,1
                         );
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_utils.c",0x6c0,"memUtilsAllocMemDesc",4,
                   "NVRM: cannot alloc memDesc!\n");
      return iVar1;
    }
    *param_8 = 1;
    lVar2 = *(long *)(param_2 + 0x20);
  }
  *param_4 = lVar2;
  *(undefined8 *)(lVar2 + 0xa0) = param_5;
  memdescSetPteKindForGpu
            ((undefined8 *)*param_4,*(undefined8 *)*param_4,*(undefined4 *)(param_3 + 0x4c),plVar3);
  *(undefined4 *)(*param_4 + 0x98) = *(undefined4 *)(param_3 + 4);
  return 0;
}


// ===== 003c5db2 memmgrMemUtilsChannelSchedulingSetup_IMPL.cold =====

void memmgrMemUtilsChannelSchedulingSetup_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003c5dc0 memmgrMemUtilsChannelSchedulingSetup_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int memmgrMemUtilsChannelSchedulingSetup_IMPL
              (undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  undefined1 local_80 [4];
  undefined1 local_7c [4];
  long local_78;
  long local_70 [4];
  undefined4 local_50 [2];
  undefined8 local_48;
  undefined4 *local_40;
  
  lVar4 = gpuGetKernelFifoShared_IMPL();
  local_78 = 0;
  lVar5 = rmapiGetInterface(4);
  if (*(char *)((long)param_3 + 0x5e) != '\0') {
    portMemSet(local_50,0,4);
    local_50[0] = gpuGetNv2080EngineType_IMPL(param_3[0x1c]);
    iVar2 = (**(code **)(lVar5 + 0x38))(lVar5,param_3[0x2b],param_3[2],0xa06f0104,local_50,4);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_utils.c",0x7b5,
                   "_memmgrMemUtilsScrubInitScheduleChannel",4,
                   "NVRM: Unable to bind Channel, status: %x\n",iVar2);
      goto LAB_003c60cb;
    }
  }
  portMemSet(local_50,0,3);
  local_50[0] = CONCAT31(local_50[0]._1_3_,1);
  iVar2 = (**(code **)(lVar5 + 0x38))(lVar5,param_3[0x2b],param_3[2],0xa06f0103,local_50,3);
  if (iVar2 != 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_utils.c",0x7c6,
                 "_memmgrMemUtilsScrubInitScheduleChannel",4,
                 "NVRM: Unable to schedule channel, status: %x\n",iVar2);
    iVar2 = 0xffff;
LAB_003c60cb:
    nvAssertOkFailedNoLog
              (iVar2,"_memmgrMemUtilsScrubInitScheduleChannel(pGpu, pChannel)",
               "src/kernel/gpu/mem_mgr/mem_utils.c",0x7db);
    return iVar2;
  }
  iVar2 = CliGetKernelChannelWithDevice
                    (*(undefined8 *)(param_3 + 0x18),*param_3,param_3[2],&local_78);
  if (iVar2 != 0) {
    nvAssertOkFailedNoLog
              (iVar2,
               "CliGetKernelChannelWithDevice(pChannel->pRsClient, pChannel->deviceId, pChannel->channelId, &pFifoKernelChannel)"
               ,"src/kernel/gpu/mem_mgr/mem_utils.c",0x7de);
    return iVar2;
  }
  iVar2 = (**(code **)(local_78 + 0x228))
                    (param_1,local_78,param_3[6],param_3 + 0x40,local_80,local_7c);
  if (iVar2 != 0) {
    nvAssertOkFailedNoLog
              (iVar2,
               "kchannelGetClassEngineID_HAL(pGpu, pFifoKernelChannel, pChannel->engineObjectId, &pChannel->classEngineID, &classID, &engineID)"
               ,"src/kernel/gpu/mem_mgr/mem_utils.c",0x7e4);
    return iVar2;
  }
  lVar5 = rmapiGetInterface(4);
  uVar3 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  iVar2 = subdeviceGetByInstance_IMPL(*(undefined8 *)(param_3 + 0x18),*param_3,uVar3,local_70);
  if (iVar2 == 0) {
    if (local_70[0] == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    uVar3 = *(undefined4 *)(*(long *)(*(long *)(local_70[0] + 0x140) + 0x48) + 0x10);
  }
  else {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_utils.c",0x751,
                 "_memmgrMemUtilsScrubInitRegisterCallback",3,
                 "NVRM: Unable to get subdevice handle. Allocating subdevice\n");
    portMemSet(local_50,0,4);
    local_50[0] = uVar3;
    iVar2 = (**(code **)(lVar5 + 8))(lVar5,param_3[0x2b],*param_3,param_3[3],0x2080,local_50,4);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_utils.c",0x760,
                   "_memmgrMemUtilsScrubInitRegisterCallback",4,
                   "NVRM: Unable to allocate a subdevice.\n");
      goto LAB_003c6126;
    }
    uVar3 = param_3[3];
  }
  portMemSet(local_50,0,0x18);
  local_50[0] = param_3[0x2b];
  local_48 = 0x80000230000007e;
  local_40 = param_3 + 0x42;
  iVar2 = (**(code **)(lVar5 + 8))(lVar5,local_50[0],uVar3,param_3[7],0x7e,local_50,0x18);
  if (iVar2 == 0) {
    portMemSet(local_70 + 1,0,0x14,0x3c5f2b);
    local_70[1] = 0x200000023;
    iVar2 = (**(code **)(lVar5 + 0x38))(lVar5,param_3[0x2b],uVar3,0x20800301,local_70 + 1,0x14);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(lVar4 + 0x1b8))(lVar4,param_3[0x2b],param_3[2],param_3 + 0x4f);
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,
                   "kfifoRmctrlGetWorkSubmitToken_HAL(pKernelFifo, pChannel->hClient, pChannel->channelId, &pChannel->workSubmitToken)"
                   ,"src/kernel/gpu/mem_mgr/mem_utils.c",0x7ed);
        return iVar2;
      }
      param_3[0x4b] = 0;
      if (*(long *)(param_3 + 0x3a) == 0) {
        return 0;
      }
      *(undefined4 *)(*(long *)(param_3 + 0x3a) + (ulong)(uint)param_3[0x13]) = 0;
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_utils.c",0x791,
                 "_memmgrMemUtilsScrubInitRegisterCallback",4,
                 "NVRM: event notification control failed\n");
  }
  else {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/mem_utils.c",0x77f,
                 "_memmgrMemUtilsScrubInitRegisterCallback",4,"NVRM: event allocation failed\n");
  }
LAB_003c6126:
  nvAssertOkFailedNoLog
            (0xffff,"_memmgrMemUtilsScrubInitRegisterCallback(pGpu, pChannel)",
             "src/kernel/gpu/mem_mgr/mem_utils.c",0x7eb);
  return 0xffff;
}


// ===== 003c6280 notifyFillNvNotification =====

void notifyFillNvNotification
               (long param_1,undefined4 *param_2,undefined4 param_3,undefined2 param_4,
               undefined2 param_5,char param_6,undefined8 param_7)

{
  if (param_6 == '\0') {
    tmrGetCurrentTime_IMPL(*(undefined8 *)(param_1 + 0x1b88),&param_7);
  }
  *(undefined2 *)(param_2 + 3) = param_4;
  param_2[2] = param_3;
  *param_2 = (int)((ulong)param_7 >> 0x20);
  param_2[1] = (int)param_7;
  *(undefined2 *)((long)param_2 + 0xe) = param_5;
  return;
}


// ===== 003c62f0 notifyFillNotifier =====

int notifyFillNotifier(long param_1,undefined8 param_2,undefined4 param_3,undefined2 param_4,
                      undefined2 param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 *local_48;
  undefined8 local_40 [2];
  
  uVar3 = gpumgrGetParentGPU();
  uVar1 = gpumgrGetSubDeviceInstanceFromGpu(uVar3);
  iVar2 = ctxdmaGetKernelVA_IMPL(param_2,0,0x10,&local_48,uVar1);
  if (iVar2 == 0) {
    local_40[0] = 0;
    tmrGetCurrentTime_IMPL(*(undefined8 *)(param_1 + 0x1b88),local_40);
    local_48[2] = param_3;
    local_48[1] = (int)((ulong)local_40[0] >> 0x20);
    *local_48 = (int)local_40[0];
    local_48[3] = CONCAT22(param_5,param_4);
  }
  return iVar2;
}


// ===== 003c6395 notifyFillNotifierGPUVATimestamp.cold =====

void notifyFillNotifierGPUVATimestamp_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003c63a0 notifyFillNotifierGPUVATimestamp =====

undefined8
notifyFillNotifierGPUVATimestamp
          (long param_1,long param_2,undefined4 param_3,long param_4,undefined4 param_5,
          undefined2 param_6,undefined2 param_7,uint param_8,undefined8 param_9)

{
  undefined8 *puVar1;
  code *pcVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined4 *puVar7;
  long *local_40 [2];
  
  param_4 = (ulong)param_8 * 0x10 + param_4;
  uVar4 = gpumgrGetDeviceGpuMask(*(undefined4 *)(param_1 + 0x7b4));
  if (param_2 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  puVar1 = *(undefined8 **)(*(long *)(param_2 + 0x110) + 0x48);
  cVar3 = CliGetDmaMappingInfo(*puVar1,*(undefined4 *)(puVar1 + 2),param_3,param_4,uVar4,local_40);
  if (cVar3 == '\0') {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/method_notification.c",0x140,
                 "notifyFillNotifierGPUVATimestamp",4,
                 "NVRM: Can\'t find mapping; notifier not written\n");
  }
  else {
    param_4 = param_4 - *local_40[0];
    if (param_4 + 0x10U <= *(ulong *)(local_40[0][0x1a] + 0x30)) {
      uVar6 = gpumgrGetParentGPU(param_1);
      uVar5 = gpumgrGetSubDeviceInstanceFromGpu(uVar6);
      if (local_40[0][(ulong)uVar5 + 1] == 0) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/method_notification.c",0x15f,
                     "notifyFillNotifierGPUVATimestamp",4,
                     "NVRM: KernelVAddr==NULL; notifier not written\n");
      }
      else {
        puVar7 = (undefined4 *)(param_4 + local_40[0][(ulong)uVar5 + 1]);
        puVar7[2] = param_5;
        puVar7[1] = param_9._4_4_;
        *puVar7 = (undefined4)param_9;
        puVar7[3] = CONCAT22(param_7,param_6);
      }
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/mem_mgr/method_notification.c",0x147,
                 "notifyFillNotifierGPUVATimestamp",4,
                 "NVRM: offset+size doesn\'t fit into mapping; notifier not written\n");
  }
  return 0x1e;
}


// ===== 003c6520 notifyFillNotifierGPUVA =====

void notifyFillNotifierGPUVA
               (long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
               undefined4 param_5,undefined2 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined8 local_30 [2];
  
  tmrGetCurrentTime_IMPL(*(undefined8 *)(param_1 + 0x1b88),local_30);
  notifyFillNotifierGPUVATimestamp
            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,local_30[0]);
  return;
}


// ===== 003c6590 notifyFillNotifierMemoryTimestamp =====

undefined8
notifyFillNotifierMemoryTimestamp
          (long param_1,long param_2,undefined4 param_3,undefined2 param_4,undefined2 param_5,
          uint param_6,undefined8 param_7)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined8 local_58;
  long local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar1 = *(undefined8 *)(param_1 + 0x1b78);
  lVar2 = *(long *)(param_2 + 0x138);
  local_58 = 0;
  lVar3 = *(long *)(&DAT_00001b90 + param_1);
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  if (lVar2 == 0) {
    local_50 = (ulong)param_6 << 4;
    local_58 = *(undefined8 *)(param_2 + 0x118);
    puVar5 = (undefined4 *)memmgrMemBeginTransfer_IMPL(uVar1,&local_58,0x10,2);
    if (puVar5 == (undefined4 *)0x0) {
      nvAssertFailedNoLog("pDebugNotifier != NULL","src/kernel/gpu/mem_mgr/method_notification.c",
                          0x1cf);
      return 0x40;
    }
  }
  else {
    iVar4 = memdescGetAddressSpace();
    if ((iVar4 != 1) && (*(char *)(lVar3 + 0xad0c) != '\0')) {
      nvAssertFailedNoLog("memdescGetAddressSpace(pMemory->pMemDesc) == ADDR_SYSMEM || !kbusIsBarAccessBlocked(pKernelBus)"
                          ,"src/kernel/gpu/mem_mgr/method_notification.c",0x1d8);
      return 0x1f;
    }
    puVar5 = (undefined4 *)(lVar2 + (ulong)param_6 * 0x10);
  }
  *(undefined2 *)(puVar5 + 3) = param_4;
  puVar5[2] = param_3;
  *puVar5 = param_7._4_4_;
  puVar5[1] = (undefined4)param_7;
  *(undefined2 *)((long)puVar5 + 0xe) = param_5;
  if (*(long *)(param_2 + 0x138) == 0) {
    memmgrMemEndTransfer_IMPL(uVar1,&local_58,0x10,0);
  }
  return 0;
}


// ===== 003c6700 notifyFillNotifierMemory =====

void notifyFillNotifierMemory
               (long param_1,undefined8 param_2,undefined4 param_3,undefined2 param_4,
               undefined4 param_5,undefined4 param_6)

{
  undefined8 local_30 [2];
  
  tmrGetCurrentTime_IMPL(*(undefined8 *)(param_1 + 0x1b88),local_30);
  notifyFillNotifierMemoryTimestamp(param_1,param_2,param_3,param_4,param_5,param_6,local_30[0]);
  return;
}


// ===== 003c675f semaphoreFillGPUVATimestamp.cold =====

void semaphoreFillGPUVATimestamp_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003c6770 semaphoreFillGPUVATimestamp =====

undefined8
semaphoreFillGPUVATimestamp
          (long param_1,long param_2,undefined4 param_3,ulong param_4,undefined4 param_5,
          uint param_6,undefined8 param_7,undefined8 param_8)

{
  undefined8 *puVar1;
  long lVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined8 uVar6;
  long lVar7;
  long *local_40 [2];
  
  lVar7 = param_4 + (ulong)param_6 * 0x10;
  if (CARRY8(param_4,(ulong)param_6 * 0x10)) {
    return 0x1f;
  }
  uVar4 = gpumgrGetDeviceGpuMask(*(undefined4 *)(param_1 + 0x7b4));
  if (param_2 != 0) {
    puVar1 = *(undefined8 **)(*(long *)(param_2 + 0x110) + 0x48);
    cVar3 = CliGetDmaMappingInfo(*puVar1,*(undefined4 *)(puVar1 + 2),param_3,lVar7,uVar4,local_40);
    if (cVar3 == '\0') {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/method_notification.c",0x24d,
                   "semaphoreFillGPUVATimestamp",4,
                   "NVRM: Can\'t find mapping; semaphore not released\n");
    }
    else {
      lVar7 = lVar7 - *local_40[0];
      if (lVar7 + 0x10U <= *(ulong *)(local_40[0][0x1a] + 0x30)) {
        uVar6 = gpumgrGetParentGPU(param_1);
        uVar5 = gpumgrGetSubDeviceInstanceFromGpu(uVar6);
        osFlushCpuWriteCombineBuffer();
        lVar2 = local_40[0][(ulong)uVar5 + 1];
        if (lVar2 == 0) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/method_notification.c",0x272,
                       "semaphoreFillGPUVATimestamp",4,
                       "NVRM: KernelVAddr==NULL; semaphore not released\n");
        }
        else {
          *(undefined4 *)(lVar2 + 8 + lVar7) = (undefined4)param_8;
          *(undefined4 *)(lVar2 + 0xc + lVar7) = param_8._4_4_;
          *(undefined4 *)(lVar2 + lVar7) = param_5;
        }
        osFlushCpuWriteCombineBuffer();
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/mem_mgr/method_notification.c",0x254,
                   "semaphoreFillGPUVATimestamp",4,
                   "NVRM: offset+size doesn\'t fit into mapping; semaphore not released\n");
    }
    return 0x1e;
  }
  uVar6 = semaphoreFillGPUVATimestamp_cold();
  return uVar6;
}


// ===== 003c6910 semaphoreFillGPUVA =====

void semaphoreFillGPUVA(long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                       undefined4 param_5,undefined4 param_6,undefined1 param_7)

{
  undefined8 local_20;
  
  tmrGetCurrentTime_IMPL(*(undefined8 *)(param_1 + 0x1b88),&local_20);
  semaphoreFillGPUVATimestamp(param_1,param_2,param_3,param_4,param_5,param_6,param_7,local_20);
  return;
}


// ===== 003c6970 heapFilterBlackListPages_IMPL =====

void heapFilterBlackListPages_IMPL(long param_1,ulong param_2,long param_3)

{
  ulong uVar1;
  ulong uVar2;
  ulong *puVar3;
  long lVar4;
  long lVar5;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
  
  if (((param_1 != 0) && (lVar5 = *(long *)(param_1 + 0xe0), lVar5 != 0)) &&
     (*(int *)(param_1 + 0xd8) != 0)) {
    lVar4 = 0;
    uVar7 = 0;
    while( true ) {
      puVar3 = (ulong *)(lVar4 * 0x10 + lVar5);
      uVar1 = *puVar3;
      uVar8 = uVar7;
      if ((param_2 <= uVar1) && (uVar1 < param_3 + param_2)) {
        uVar2 = puVar3[1];
        uVar8 = (ulong)((int)uVar7 + 1);
        *(ulong *)(lVar5 + uVar7 * 0x10) = uVar1;
        *(int *)(*(long *)(param_1 + 0xe0) + 8 + uVar7 * 0x10) = (int)uVar2;
      }
      lVar4 = lVar4 + 1;
      if (*(uint *)(param_1 + 0xd8) <= (uint)lVar4) break;
      lVar5 = *(long *)(param_1 + 0xe0);
      uVar7 = uVar8;
    }
    iVar6 = (int)uVar8;
    if (iVar6 != 0) {
      portMemSet(uVar8 * 0x10 + *(long *)(param_1 + 0xe0),0,
                 (ulong)(*(uint *)(param_1 + 0xd8) - iVar6) << 4);
      *(int *)(param_1 + 0xd8) = iVar6;
      return;
    }
  }
  return;
}


// ===== 003c6a40 heapInit_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong heapInit_IMPL(long param_1,long param_2,long param_3,undefined8 param_4,int param_5,
                   uint param_6,undefined8 param_7)

{
  ulong uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  ulong *puVar6;
  long *plVar7;
  long lVar8;
  long lVar9;
  
  iVar3 = (**(code **)(*(long *)(param_1 + 0x1b78) + 0x3a0))
                    (param_1,*(long *)(param_1 + 0x1b78),param_2);
  if (iVar3 != 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/objheap.c",0x2c,"heapInit_IMPL",1,
                 "NVRM: Failed to read blackList pages (0x%x).\n",iVar3);
  }
  if ((param_5 == 2) || ((param_5 == 1 && (cVar2 = hypervisorIsVgxHyper_IMPL(), cVar2 != '\0')))) {
    if (param_6 != 0) {
      puVar6 = (ulong *)portMemAllocNonPaged(0x808);
      if (puVar6 == (ulong *)0x0) {
        uVar5 = 0x51;
      }
      else {
        portMemSet(puVar6,0,0x808);
        *puVar6 = (ulong)param_6 | 0x100000000;
        puVar6[1] = 0;
        uVar4 = (**(code **)(param_1 + 0x3b90))
                          (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                           *(undefined4 *)(param_1 + 0x3b3c),0x20800a57,puVar6,0x808);
        uVar1 = puVar6[0x81];
        portMemFree(puVar6);
        uVar5 = (ulong)uVar4;
        if (uVar4 == 0) {
          heapFilterBlackListPages_IMPL(param_2,param_3 + uVar1,param_4);
          if (*(int *)(param_2 + 0xd8) != 0) {
            lVar8 = 0;
            do {
              lVar9 = lVar8 + 1;
              plVar7 = (long *)(lVar8 * 0x10 + *(long *)(param_2 + 0xe0));
              *plVar7 = *plVar7 - uVar1;
              lVar8 = lVar9;
            } while ((uint)lVar9 < *(uint *)(param_2 + 0xd8));
          }
          goto LAB_003c6a97;
        }
      }
      return uVar5;
    }
    heapFilterBlackListPages_IMPL(param_2,param_3,param_4);
  }
LAB_003c6a97:
  uVar5 = heapInitInternal_IMPL(param_1,param_2,param_3,param_4,param_5,param_7);
  return uVar5;
}


// ===== 003c6c40 pmaNumaFreeInternal =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void pmaNumaFreeInternal(long param_1,ulong *param_2,ulong *param_3,ulong param_4)

{
  undefined8 uVar1;
  bool bVar2;
  uint uVar3;
  ulong *extraout_RDX;
  ulong *extraout_RDX_00;
  ulong *extraout_RDX_01;
  ulong *extraout_RDX_02;
  ulong *puVar4;
  ulong *extraout_RDX_03;
  ulong uVar5;
  ulong uVar6;
  ulong *puVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  undefined1 auVar11 [16];
  ulong local_70;
  ulong local_60;
  byte local_44;
  
  local_44 = osGetPageShift();
  if (0x10 < local_44) {
    nvAssertFailedNoLog("PMA_PAGE_SHIFT >= osPageShift",
                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x32e);
    return;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x330,"pmaNumaFreeInternal",1,
               "NVRM: Freeing pPage[0] = %llx pageCount %lld\n",*param_2);
  uVar3 = findRegionID(param_1,*param_2);
  uVar5 = (**(code **)(*(long *)(param_1 + 0x230) + 0x50))
                    (*(undefined8 *)(param_1 + 0x28 + (ulong)uVar3 * 8),
                     *param_2 - **(long **)(param_1 + 0x130 + (ulong)uVar3 * 8) >> 0x10);
  if ((uVar5 & 1) == 0) {
    if (param_3 == (ulong *)0x0) goto LAB_003c6e04;
    bVar2 = false;
    puVar4 = param_3;
    local_70 = param_4;
  }
  else {
    if (param_3 == (ulong *)0x0) goto LAB_003c6e04;
    puVar4 = param_2 + (long)param_3;
    puVar7 = param_2;
    if (((ulong)param_3 & 1) == 0) goto LAB_003c6e60;
    *param_2 = *param_2 & 0xfffffffffc000000;
    for (puVar7 = param_2 + 1; puVar4 != puVar7; puVar7 = puVar7 + 2) {
LAB_003c6e60:
      *puVar7 = *puVar7 & 0xfffffffffc000000;
      puVar7[1] = puVar7[1] & 0xfffffffffc000000;
    }
    bVar2 = true;
    local_70 = 0x4000000;
  }
  local_60 = 0;
  puVar7 = (ulong *)0x0;
  local_44 = 0x10 - local_44;
LAB_003c6d20:
  do {
    uVar5 = param_2[(long)puVar7];
    if (*(ulong *)(param_1 + 0x2f0) <= uVar5) goto LAB_003c6d63;
    while (bVar2) {
      do {
        if (local_60 <= uVar5) {
          local_60 = uVar5 + 0x4000000 & 0xfffffffffc000000;
          uVar3 = findRegionID(param_1,uVar5,puVar4);
          uVar9 = (ulong)uVar3;
          uVar1 = *(undefined8 *)(param_1 + 0x28 + uVar9 * 8);
          uVar5 = param_2[(long)puVar7] - **(long **)(param_1 + 0x130 + uVar9 * 8) >> 0x10;
          lVar8 = param_2[(long)puVar7] + *(long *)(param_1 + 0x2e8);
          (**(code **)(*(long *)(param_1 + 0x230) + 0x30))(uVar1,uVar5,0,1);
          puVar4 = extraout_RDX_01;
          goto joined_r0x003c6f07;
        }
        puVar7 = (ulong *)((long)puVar7 + 1);
        if (param_3 == puVar7) goto LAB_003c6e04;
        uVar5 = param_2[(long)puVar7];
        puVar4 = param_2;
      } while (uVar5 < *(ulong *)(param_1 + 0x2f0));
LAB_003c6d63:
      nvAssertFailedNoLog("pPages[i] < pPma->coherentCpuFbSize",
                          "src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x350);
      uVar5 = param_2[(long)puVar7];
      puVar4 = extraout_RDX;
    }
    uVar3 = findRegionID(param_1,uVar5,puVar4);
    uVar9 = (ulong)uVar3;
    uVar1 = *(undefined8 *)(param_1 + 0x28 + uVar9 * 8);
    lVar8 = param_2[(long)puVar7] + *(long *)(param_1 + 0x2e8);
    uVar5 = param_2[(long)puVar7] - **(long **)(param_1 + 0x130 + uVar9 * 8) >> 0x10;
    puVar4 = extraout_RDX_00;
joined_r0x003c6f07:
    if (local_70 >> 0x10 != 0) {
      uVar10 = (local_70 >> 0x10) + uVar5;
      do {
        while( true ) {
          auVar11 = (**(code **)(*(long *)(param_1 + 0x230) + 0x40))
                              (*(undefined8 *)(param_1 + 8 + (uVar9 + 4) * 8),uVar5,1);
          puVar4 = auVar11._8_8_;
          if ((auVar11._0_8_ & 4) == 0) break;
          if ((auVar11._0_8_ & 1) != 0) {
            (**(code **)(*(long *)(param_1 + 0x230) + 0x18))(uVar1,uVar5,0x20,0x20);
            puVar4 = extraout_RDX_02;
          }
          uVar5 = uVar5 + 1;
          lVar8 = lVar8 + 0x10000;
          if (uVar5 == uVar10) goto LAB_003c6fb7;
        }
        osAllocReleasePage(lVar8,1 << (local_44 & 0x1f));
        uVar6 = uVar5 + 1;
        (**(code **)(*(long *)(param_1 + 0x230) + 0x18))(uVar1,uVar5,0,0xfffffffb);
        puVar4 = extraout_RDX_03;
        uVar5 = uVar6;
        lVar8 = lVar8 + 0x10000;
      } while (uVar6 != uVar10);
LAB_003c6fb7:
      puVar7 = (ulong *)((long)puVar7 + 1);
      if (param_3 == puVar7) break;
      goto LAB_003c6d20;
    }
    puVar7 = (ulong *)((long)puVar7 + 1);
  } while (param_3 != puVar7);
LAB_003c6e04:
  (**(code **)(param_1 + 0x310))(*(undefined8 *)(param_1 + 0x318),*(undefined8 *)(param_1 + 0x268));
  return;
}


// ===== 003c7000 pmaNumaAllocate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int pmaNumaAllocate(undefined8 *param_1,ulong param_2,ulong param_3,uint *param_4,long *param_5)

{
  long *plVar1;
  uint uVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  bool bVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  ulong uVar17;
  undefined8 uVar18;
  char *pcVar19;
  ulong uVar20;
  char *pcVar21;
  ulong uVar22;
  long *plVar23;
  char *pcVar24;
  long lVar25;
  int iVar26;
  ulong uVar27;
  long local_158;
  byte local_146;
  byte local_144;
  ulong local_140;
  ulong local_130;
  int local_124;
  ulong local_110;
  ulong local_100;
  uint local_f8;
  uint local_f4;
  uint local_f0;
  ulong local_e8;
  long local_e0;
  long local_d8;
  ulong local_d0;
  undefined8 local_c8;
  ulong local_c0;
  uint local_b8 [34];
  
  uVar2 = *param_4;
  uVar3 = *(undefined4 *)((long)param_1 + 0x2e4);
  uVar13 = uVar2 & 1;
  local_144 = (byte)uVar13 ^ 1;
  if (*(char *)(param_1 + 0x5c) == '\0') {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x224,"pmaNumaAllocate",6,
                 "NVRM: Cannot allocate from NUMA node %d on a non-NUMA system.\n",uVar3);
    return 0x1f;
  }
  if (0x20000000 < param_3) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x22b,"pmaNumaAllocate",6,
                 "NVRM: Cannot allocate with more than 512MB contiguity.\n");
    return 0x1f;
  }
  if (*(char *)((long)param_1 + 0x2e1) != '\x01') {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x231,"pmaNumaAllocate",1,
                 "NVRM: Cannot allocate from NUMA node %d before it is onlined.\n",uVar3);
    return 0x40;
  }
  bVar10 = (byte)(uVar2 >> 0xe) & 1 ^ 1;
  uVar14 = uVar2 & 0xc000;
  local_110 = param_2;
  if (uVar14 == 0) {
    local_146 = (byte)(uVar2 >> 0xc) & 1;
    local_140 = param_3;
    if ((uVar2 & 0x40) == 0) {
      local_158 = 0;
    }
    else {
      local_158 = 0;
joined_r0x003c7393:
      if ((param_2 != 0) &&
         ((auVar7._8_8_ = 0, auVar7._0_8_ = param_2, auVar8._8_8_ = 0, auVar8._0_8_ = local_140,
          SUB168(auVar7 * auVar8,8) != 0 || (SUB168(auVar7 * auVar8,0) >> 0x20 != 0)))) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x270,"pmaNumaAllocate",6,
                     "NVRM: Cannot allocate more than 4GB contiguous memory in one call.\n");
        return 0x1f;
      }
    }
  }
  else {
    if ((uVar2 & 0x40) != 0) {
      if (0x2000000 < param_3 * param_2) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x23b,"pmaNumaAllocate",4,
                     "NVRM: Localized contig allocation size is too large\n");
        return 0x1f;
      }
      if (bVar10 != (byte)((uVar2 & 0x8000) >> 0xf)) {
LAB_003c7f45:
        nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x241,"pmaNumaAllocate",4,
                     "NVRM: Only one ugpu can be specified for localized allocations\n");
        return 0x1f;
      }
      local_158 = 1;
      local_146 = 0;
      local_140 = 0x4000000;
      goto joined_r0x003c7393;
    }
    if (bVar10 != (byte)((uVar2 & 0x8000) >> 0xf)) goto LAB_003c7f45;
    local_146 = 0;
    local_144 = 0;
    local_140 = 0x4000000;
    local_110 = param_2 * param_3 + 0x1ffffff >> 0x19;
    auVar6._8_8_ = 0;
    auVar6._0_8_ = param_3;
    local_158 = SUB168((ZEXT816(0) << 0x40 | ZEXT816(0x2000000)) / auVar6,0);
  }
  local_f0 = uVar2 & 0x40;
  iVar15 = pmaSelector(param_1,param_4,local_b8);
  if (iVar15 != 0) {
    nvCheckOkFailedNoLog
              (6,iVar15,"pmaSelector(pPma, allocationOptions, regionList)",
               "src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x276);
    return iVar15;
  }
  bVar11 = (byte)(uVar2 >> 10) & 1;
  if ((*(char *)(param_1 + 0x59) == '\0') || (bVar11 == 1)) {
    uVar16 = 0;
    bVar9 = false;
  }
  else {
    portSyncMutexAcquire(param_1[3]);
    portSyncRwLockAcquireRead(param_1[2]);
    uVar16 = 1;
    if (param_1[0x5a] != 1) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x285,"pmaNumaAllocate",3,
                   "NVRM: PMA object is not valid\n");
      portSyncRwLockReleaseRead(param_1[2]);
      portSyncMutexRelease(param_1[3]);
      return 0x40;
    }
    bVar9 = true;
  }
  param_4[0xc] = uVar16;
  portSyncSpinlockAcquire(*param_1);
  if (local_f0 == 0) {
    bVar12 = osGetPageShift();
    uVar27 = local_140;
    if (local_110 == 0) {
      nvAssertFailedNoLog("allocationCount","src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x17e
                         );
      uVar17 = osGetPageSize();
      if (uVar17 <= local_140) {
        portSyncSpinlockRelease(*param_1);
        portSyncSpinlockAcquire(*param_1);
        local_100 = 0;
        pcVar21 = "DISCONTIG";
        goto LAB_003c7dfd;
      }
    }
    else {
      uVar17 = osGetPageSize();
      if (uVar17 <= local_140) {
        lVar25 = param_1[0x4c];
        lVar4 = param_1[0x4d];
        uVar16 = *(uint *)(param_1 + 0x5f);
        portSyncSpinlockRelease(*param_1);
        plVar1 = param_5 + (param_2 - local_110);
        local_100 = 0;
        plVar23 = plVar1;
        do {
          iVar15 = osAllocPagesNode(uVar3,local_140,
                                    (ulong)(lVar4 * 100) < (ulong)uVar16 * lVar25 * 0x20,&local_d0);
          if (iVar15 != 0) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x18e,
                         "_pmaNumaAllocatePages",1,
                         "NVRM: Alloc from OS failed for i= %lld allocationCount = %lld pageSize = %lld!\n"
                         ,local_100,local_110);
LAB_003c761f:
            if ((!bVar9) || (local_100 == 0)) goto LAB_003c771f;
            goto LAB_003c7634;
          }
          if (plVar23 == (long *)0x0) {
            iVar15 = 0x1f;
            nvAssertFailedNoLog("pGpaPhysAddr != NULL",
                                "src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0xbf);
LAB_003c75cd:
            nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x197,
                         "_pmaNumaAllocatePages",4,
                         "NVRM: Alloc from OS invalid for i= %lld allocationCount = %lld pageSize = %lld!\n"
                         ,local_100,local_110);
            goto LAB_003c761f;
          }
          uVar17 = param_1[0x5d];
          if ((local_d0 < uVar17) || (param_1[0x5e] + uVar17 < local_140 + local_d0)) {
            iVar15 = 0x40;
            goto LAB_003c75cd;
          }
          *plVar23 = local_d0 - uVar17;
          iVar15 = pmaCheckRangeAgainstRegionDesc(param_1,local_d0 - uVar17,local_140);
          if (iVar15 != 0) goto LAB_003c75cd;
          local_100 = local_100 + 1;
          plVar23 = plVar23 + 1;
          osAllocAcquirePage(local_d0 + (1L << (bVar12 & 0x3f)),
                             (int)(local_140 >> (bVar12 & 0x3f)) + -1);
        } while (local_110 != local_100);
        if (bVar9) {
LAB_003c7634:
          local_c8 = 0;
          iVar15 = scrubSubmitPages(param_1[0x5b],local_140,plVar1,local_100,&local_c8,&local_c0);
          if (iVar15 == 0) {
            if (local_c0 != 0) {
              _pmaClearScrubBit(param_1,local_c8);
            }
            iVar15 = _pmaCheckScrubbedPages(param_1,local_140,plVar1,local_100 & 0xffffffff);
            if (iVar15 == 0) {
              portMemFree(local_c8);
              iVar15 = 0;
LAB_003c771f:
              portSyncSpinlockAcquire(*param_1);
              if ((local_100 < local_110) && (local_144 != 0)) {
                if (*(int *)(param_1 + 4) != 0) {
                  lVar25 = 0;
                  do {
                    if (local_b8[lVar25] != 0xffffffff) {
                      uVar18 = param_1[(ulong)local_b8[lVar25] + 5];
                      (**(code **)(param_1[0x46] + 0x70))(uVar18,&local_c0);
                      local_c0 = local_c0 >> 0x10;
                      if (local_c0 != 0) {
                        uVar17 = 0;
                        do {
                          uVar16 = (**(code **)(param_1[0x46] + 0x40))(uVar18,uVar17,1);
                          if ((uVar16 & 3) == 1) {
                            nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x68,
                                         "_pmaNumaAvailableEvictablePage",1,
                                         "NVRM: Evictable frame: FOUND\n");
                            lVar25 = 0;
                            iVar26 = (int)local_110 - (int)local_100;
                            if (*(int *)(param_1 + 4) != 0) goto LAB_003c7870;
                            goto joined_r0x003c790b;
                          }
                          uVar17 = (ulong)((int)uVar17 + 1);
                        } while (uVar17 < local_c0);
                      }
                    }
                    lVar25 = lVar25 + 1;
                  } while ((uint)lVar25 < *(uint *)(param_1 + 4));
                }
                nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x6a,
                             "_pmaNumaAvailableEvictablePage",1,"NVRM: Evictable frame: NOT FOUND\n"
                            );
                goto joined_r0x003c790b;
              }
              if ((iVar15 == 0x51) && (local_146 != 0)) goto LAB_003c7937;
LAB_003c8079:
              if (iVar15 != 0) goto LAB_003c790d;
              goto LAB_003c7941;
            }
            portMemFree(local_c8);
          }
          else {
            portMemFree(local_c8);
          }
          nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x1ba,
                       "_pmaNumaAllocatePages",4,"NVRM: ERROR: scrubber OOM!\n");
          portSyncSpinlockAcquire(*param_1);
          pcVar21 = "DISCONTIG";
          goto LAB_003c7dfd;
        }
        portSyncSpinlockAcquire(*param_1);
LAB_003c7941:
        pcVar24 = "DISCONTIG";
        if ((uVar2 & 2) == 0) {
          local_f4 = 1;
          pcVar21 = "UNPINNED";
        }
        else {
          local_f4 = 2;
          pcVar21 = "PINNED";
        }
LAB_003c796d:
        pcVar19 = "ALLOWED";
        if (uVar13 != 0) {
          pcVar19 = "NOTALLOWED";
        }
LAB_003c7989:
        nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",699,"pmaNumaAllocate",1,
                     "NVRM: SUCCESS allocCount %lld, allocsize %llx eviction? %s pinned ? %s contig? %s\n"
                     ,local_110,uVar27,pcVar19,pcVar21,pcVar24);
        if (local_100 == 0) {
          if ((uVar14 == 0) || (local_100 = param_2, local_f0 == 0)) {
            (*(code *)param_1[0x62])(param_1[99],param_1[0x4d]);
            local_130 = local_100;
          }
          else {
            *param_5 = *param_5 + (ulong)bVar10 * 0x2000000;
            (*(code *)param_1[0x62])(param_1[99],param_1[0x4d]);
            local_130 = 0;
          }
        }
        else {
LAB_003c79db:
          local_f8 = 0;
          uVar17 = 0;
          do {
            uVar16 = findRegionID(param_1);
            uVar18 = param_1[(ulong)uVar16 + 5];
            uVar17 = (ulong)(param_5[uVar17] - *(long *)param_1[(ulong)uVar16 + 0x26]) >> 0x10;
            if (uVar14 != 0) {
              (**(code **)(param_1[0x46] + 0x30))(uVar18,uVar17,1,1);
            }
            if (uVar27 >> 0x10 != 0) {
              uVar22 = 0;
              do {
                lVar25 = uVar22 + uVar17;
                uVar20 = (**(code **)(param_1[0x46] + 0x40))(uVar18,lVar25,1);
                if ((uVar20 & 4) != 0) {
                  iVar15 = 0x51;
                  if (uVar14 != 0) goto LAB_003c7af8;
                  (*(code *)param_1[0x62])(param_1[99],param_1[0x4d]);
                  pcVar21 = "DISCONTIG";
                  if (local_f0 != 0) {
                    pcVar21 = "CONTIG";
                  }
                  goto LAB_003c7dfd;
                }
                (**(code **)(param_1[0x46] + 0x18))(uVar18,lVar25,local_f4,0x7f);
                uVar22 = (ulong)((int)uVar22 + 1);
              } while (uVar22 < uVar27 >> 0x10);
            }
            local_f8 = local_f8 + 1;
            uVar17 = (ulong)local_f8;
          } while (uVar17 < local_100);
          if (uVar14 == 0) {
            (*(code *)param_1[0x62])(param_1[99],param_1[0x4d]);
          }
          else {
            iVar15 = 0;
LAB_003c7af8:
            if (local_f0 == 0) {
              uVar17 = 0;
              if (local_158 == 0) {
                do {
                  uVar17 = (ulong)((int)uVar17 + 1);
                } while (uVar17 < local_100);
              }
              else {
                uVar22 = 0;
                uVar14 = 0;
LAB_003c7ba0:
                do {
                  lVar25 = param_5[uVar17 + (param_2 - local_110)] + (ulong)bVar10 * 0x2000000;
                  uVar16 = (int)local_158 + uVar14;
                  while (uVar22 < param_2) {
                    uVar14 = uVar14 + 1;
                    param_5[uVar22] = lVar25;
                    lVar25 = lVar25 + param_3;
                    if (uVar14 == uVar16) {
                      uVar17 = (ulong)((int)uVar17 + 1);
                      if (local_100 <= uVar17) goto LAB_003c7beb;
                      uVar22 = (ulong)uVar14;
                      goto LAB_003c7ba0;
                    }
                    uVar22 = (ulong)uVar14;
                  }
                  uVar17 = (ulong)((int)uVar17 + 1);
                } while (uVar17 < local_100);
              }
LAB_003c7beb:
              (*(code *)param_1[0x62])(param_1[99],param_1[0x4d]);
              local_130 = param_2;
              if (iVar15 != 0) {
                pcVar21 = "DISCONTIG";
                local_100 = param_2;
                goto LAB_003c7dfd;
              }
              goto LAB_003c7b42;
            }
            *param_5 = *param_5 + (ulong)bVar10 * 0x2000000;
            (*(code *)param_1[0x62])(param_1[99],param_1[0x4d]);
            if (iVar15 != 0) goto LAB_003c7df6;
          }
          local_130 = local_100;
        }
LAB_003c7b42:
        *(ulong *)(param_4 + 10) = local_130;
        local_124 = 0;
        goto LAB_003c7e7e;
      }
    }
    nvAssertFailedNoLog("pageSize >= osGetPageSize()",
                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x17f);
    local_100 = 0;
    pcVar21 = "DISCONTIG";
  }
  else {
    uVar27 = local_140 * local_110;
    local_e8 = 0;
    local_e0 = 0;
    local_d8 = 0;
    local_d0 = 0;
    uVar17 = osGetPageSize();
    if (uVar27 < uVar17) {
      nvAssertFailedNoLog("actualSize >= osGetPageSize()",
                          "src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0xe4);
    }
    else {
      uVar16 = *(uint *)(param_1 + 0x5f);
      lVar25 = param_1[0x4c];
      lVar4 = param_1[0x4d];
      portSyncSpinlockRelease(*param_1);
      iVar15 = osAllocPagesNode(uVar3,uVar27,(ulong)(lVar4 * 100) < (ulong)uVar16 * lVar25 * 0x20,
                                &local_e8);
      if (iVar15 == 0) {
        bVar12 = osGetPageShift();
        osAllocAcquirePage((1L << (bVar12 & 0x3f)) + local_e8,(int)(uVar27 >> (bVar12 & 0x3f)) + -1)
        ;
        uVar17 = param_1[0x5d];
        if ((uVar17 <= local_e8) && (uVar27 + local_e8 <= param_1[0x5e] + uVar17)) {
          local_e0 = local_e8 - uVar17;
          iVar15 = pmaCheckRangeAgainstRegionDesc(param_1,local_e0,uVar27);
          if (iVar15 == 0) {
            if (bVar9) {
              local_c8 = 0;
              iVar15 = scrubSubmitPages(param_1[0x5b],uVar27 & 0xffffffff,&local_e0,1,&local_c8,
                                        &local_c0);
              if (iVar15 == 0) {
                if (local_c0 != 0) {
                  _pmaClearScrubBit(param_1,local_c8);
                }
                iVar15 = _pmaCheckScrubbedPages(param_1,uVar27,&local_e0,1);
                if (iVar15 == 0) {
                  portMemFree(local_c8);
                  goto LAB_003c72cf;
                }
                portMemFree(local_c8);
              }
              else {
                portMemFree(local_c8);
              }
              nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x11d,
                           "_pmaNumaAllocateRange",4,"NVRM: ERROR: scrubber OOM!\n");
              portSyncSpinlockAcquire(*param_1);
              local_100 = 1;
              pcVar21 = "CONTIG";
              *param_5 = local_e0;
              goto LAB_003c7dfd;
            }
LAB_003c72cf:
            portSyncSpinlockAcquire(*param_1);
            *param_5 = local_e0;
LAB_003c72f8:
            if ((uVar2 & 2) != 0) {
              pcVar24 = "CONTIG";
              pcVar21 = "PINNED";
              local_100 = 1;
              local_f4 = 2;
              goto LAB_003c796d;
            }
            if (uVar13 == 0) {
              pcVar24 = "CONTIG";
              pcVar21 = "UNPINNED";
              local_f4 = 1;
              pcVar19 = "ALLOWED";
              local_100 = 1;
              goto LAB_003c7989;
            }
            nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",699,"pmaNumaAllocate",1,
                         "NVRM: SUCCESS allocCount %lld, allocsize %llx eviction? %s pinned ? %s contig? %s\n"
                         ,local_110,uVar27,"NOTALLOWED","UNPINNED","CONTIG");
            local_100 = 1;
            local_f4 = uVar13;
            goto LAB_003c79db;
          }
        }
        nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0xfc,"_pmaNumaAllocateRange"
                     ,4,
                     "NVRM: Alloc from OS invalid for sysPhysAddr = 0x%llx actualSize = 0x%llx!\n",
                     local_e8,uVar27);
      }
      portSyncSpinlockAcquire(*param_1);
      nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x128,"_pmaNumaAllocateRange",
                   1,"NVRM: Allocate from OS failed for allocation size = %lld!\n",uVar27);
      if (local_144 == 0) {
        *param_5 = local_e0;
      }
      else {
        local_d8 = 0;
        local_d0 = 0;
        if (*(int *)(param_1 + 4) == 0) {
          pcVar21 = "CONTIG";
          local_100 = 0;
          *param_5 = local_e0;
          goto LAB_003c7dfd;
        }
        lVar25 = 0;
        do {
          uVar16 = local_b8[lVar25];
          if ((uVar16 != 0xffffffff) &&
             (iVar15 = (**(code **)(param_1[0x46] + 0x88))
                                 (param_1[(ulong)uVar16 + 5],
                                  *(undefined8 *)param_1[(ulong)uVar16 + 0x26],uVar27,local_140,
                                  &local_d8,&local_d0), iVar15 == 0)) {
            uVar17 = (local_d0 + 1) - local_d8;
            if (uVar17 < uVar27) {
              *param_5 = local_e0;
              if ((uVar2 & 2) == 0) {
                pcVar24 = "CONTIG";
                local_f4 = 1;
                pcVar21 = "UNPINNED";
                local_100 = 0;
              }
              else {
                pcVar24 = "CONTIG";
                pcVar21 = "PINNED";
                local_100 = 0;
                local_f4 = 2;
              }
              goto LAB_003c796d;
            }
            if (uVar27 - uVar17 != 0) {
              nvAssertFailedNoLog("(evictEnd - evictStart + 1) == actualSize",
                                  "src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x13a);
            }
            uVar16 = findRegionID(param_1,local_d8);
            if (param_1[(ulong)uVar16 + 5] == 0) {
              nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x15a,
                           "_pmaNumaAllocateRange",1,"NVRM: pMap NULL cannot perform eviction\n");
              *param_5 = local_e0;
              goto LAB_003c7deb;
            }
            iVar15 = _pmaEvictContiguous(param_1,param_1[(ulong)uVar16 + 5],local_d8,local_d0,
                                         *(char *)(param_1[(ulong)uVar16 + 0x26] + 0x16) != '\0');
            if (iVar15 == 0x51) {
              nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x14e,
                           "_pmaNumaAllocateRange",1,"NVRM: Eviction Failed = %llx to %llx!\n",
                           local_d8,local_d0);
              *param_5 = local_e0;
              goto LAB_003c7deb;
            }
            nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x152,
                         "_pmaNumaAllocateRange",1,
                         "NVRM: Eviction succeeded = %llx to %llx Scrub status 0x%x!\n",local_d8,
                         local_d0,iVar15);
            *param_5 = local_d8;
            if (iVar15 == 0) goto LAB_003c72f8;
            local_100 = 1;
            pcVar21 = "CONTIG";
            goto LAB_003c7dfd;
          }
          lVar25 = lVar25 + 1;
        } while ((uint)lVar25 < *(uint *)(param_1 + 4));
        *param_5 = local_e0;
      }
    }
LAB_003c7deb:
    local_100 = 0;
LAB_003c7df6:
    pcVar21 = "CONTIG";
  }
  goto LAB_003c7dfd;
LAB_003c7870:
  do {
    uVar16 = local_b8[lVar25];
    if (uVar16 != 0xffffffff) {
      puVar5 = (undefined8 *)param_1[(ulong)uVar16 + 0x26];
      uVar18 = _pmaEvictPages(param_1,param_1[(ulong)uVar16 + 5],plVar1 + local_100,iVar26,plVar1,
                              local_100,local_140,*puVar5,puVar5[1],
                              *(char *)((long)puVar5 + 0x16) != '\0');
      iVar15 = (int)uVar18;
      if (iVar15 != 0x51) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x1eb,
                     "_pmaNumaAllocatePages",1,
                     "NVRM: Frames %lld evicted in region %d of total allocationCount %lld Scrub status 0x%x!\n"
                     ,local_100,lVar25,local_110,uVar18);
        local_100 = local_110;
        goto LAB_003c8079;
      }
      nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x1f6,"_pmaNumaAllocatePages",
                   1,"NVRM: Eviction Failed %d pages !\n",iVar26);
    }
    lVar25 = lVar25 + 1;
  } while ((uint)lVar25 < *(uint *)(param_1 + 4));
joined_r0x003c790b:
  if (local_146 != 0) {
LAB_003c7937:
    if (local_100 != 0) goto LAB_003c7941;
  }
LAB_003c790d:
  pcVar21 = "DISCONTIG";
LAB_003c7dfd:
  pcVar24 = "UNPINNED";
  if ((uVar2 & 2) != 0) {
    pcVar24 = "PINNED";
  }
  pcVar19 = "ALLOWED";
  if (uVar13 != 0) {
    pcVar19 = "NOTALLOWED";
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/numa.c",0x30a,"pmaNumaAllocate",1,
               "NVRM: FAILED allocCount %lld, allocsize %lld eviction? %s pinned ? %s contig? %s\n",
               local_110,uVar27,pcVar19,pcVar24,pcVar21);
  if (local_100 != 0) {
    pmaNumaFreeInternal(param_1,param_5,local_100,local_140,0);
  }
  local_124 = 0x51;
LAB_003c7e7e:
  portSyncSpinlockRelease(*param_1);
  if ((*(char *)(param_1 + 0x59) != '\0') && (bVar11 != 1)) {
    portSyncRwLockReleaseRead(param_1[2]);
    portSyncMutexRelease(param_1[3]);
    return local_124;
  }
  return local_124;
}


// ===== 003c8880 pmaNumaSetReclaimSkipThreshold =====

void pmaNumaSetReclaimSkipThreshold(undefined8 *param_1,undefined4 param_2)

{
  portSyncSpinlockAcquire(*param_1);
  *(undefined4 *)(param_1 + 0x5f) = param_2;
  portSyncSpinlockRelease(*param_1);
  return;
}


// ===== 003c88b0 _pmaDefaultStatsCallback =====

void _pmaDefaultStatsCallback(void)

{
  return;
}


// ===== 003c88c0 pmaQueryConfigs =====

undefined8 pmaQueryConfigs(undefined8 *param_1,uint *param_2)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  
  if ((param_1 != (undefined8 *)0x0) && (param_2 != (uint *)0x0)) {
    uVar3 = 0;
    if (*(char *)(param_1 + 0x59) != '\0') {
      portSyncRwLockAcquireRead(param_1[2]);
      uVar3 = (param_1[0x5a] == 1) + 1 + (uint)(param_1[0x5a] == 1);
      portSyncRwLockReleaseRead(param_1[2]);
    }
    cVar1 = *(char *)(param_1 + 0x5c);
    portSyncSpinlockAcquire(*param_1);
    cVar2 = *(char *)((long)param_1 + 0x2e1);
    portSyncSpinlockRelease(*param_1);
    *param_2 = *param_2 & ((uint)(cVar2 != '\0') << 3 | (uint)(cVar1 != '\0') << 2 | uVar3);
    return 0;
  }
  return 0x40;
}


// ===== 003c8990 pmaIsPmaManaged =====

undefined8 pmaIsPmaManaged(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  
  lVar1 = param_1 + (ulong)*(uint *)(param_1 + 0x20) * 8;
  if (*(uint *)(param_1 + 0x20) != 0) {
    do {
      uVar2 = **(ulong **)(param_1 + 0x130);
      if ((uVar2 <= param_2) && (uVar3 = (*(ulong **)(param_1 + 0x130))[1], param_3 <= uVar3)) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x13a,
                     "pmaIsPmaManaged",1,"NVRM: range %llx..%llx resides in PMA region=%llx..%llx\n"
                     ,param_2,param_3,uVar2,uVar3);
        return 1;
      }
      param_1 = param_1 + 8;
    } while (param_1 != lVar1);
  }
  return 0;
}


// ===== 003c8a10 pmaRegMemScrub =====

undefined8 pmaRegMemScrub(long param_1,undefined8 param_2)

{
  if ((param_1 == 0) || (*(char *)(param_1 + 0x2c8) == '\0')) {
    nvAssertFailedNoLog("pPma && pPma->bScrubOnFree",
                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x157);
  }
  portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0x10));
  *(undefined8 *)(param_1 + 0x2d8) = param_2;
  LOCK();
  *(undefined8 *)(param_1 + 0x2d0) = 1;
  UNLOCK();
  portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0x10));
  return 0;
}


// ===== 003c8a80 pmaUnregMemScrub =====

void pmaUnregMemScrub(long param_1)

{
  if ((param_1 == 0) || (*(char *)(param_1 + 0x2c8) == '\0')) {
    nvAssertFailedNoLog("pPma && pPma->bScrubOnFree",
                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x163);
  }
  portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0x10));
  LOCK();
  *(undefined8 *)(param_1 + 0x2d0) = 0;
  UNLOCK();
  *(undefined8 *)(param_1 + 0x2d8) = 0;
  portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0x10));
  return;
}


// ===== 003c8af0 pmaGetMemScrub =====

undefined8 pmaGetMemScrub(long param_1)

{
  if (param_1 != 0) {
    return *(undefined8 *)(param_1 + 0x2d8);
  }
  return 0;
}


// ===== 003c8b10 pmaNumaOnlined =====

undefined8 pmaNumaOnlined(undefined8 *param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  if (((param_1 != (undefined8 *)0x0) && (*(char *)(param_1 + 0x5c) != '\0')) && (param_2 != -1)) {
    portSyncSpinlockAcquire(*param_1);
    *(undefined1 *)((long)param_1 + 0x2e1) = 1;
    *(int *)((long)param_1 + 0x2e4) = param_2;
    param_1[0x5d] = param_3;
    param_1[0x5e] = param_4;
    portSyncSpinlockRelease(*param_1);
    return 0;
  }
  nvAssertFailedNoLog(&DAT_00d5406a,"src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c"
                      ,0x17a);
  return 0x40;
}


// ===== 003c8ba0 pmaNumaOfflined =====

void pmaNumaOfflined(undefined8 *param_1)

{
  if ((param_1 != (undefined8 *)0x0) && (*(char *)(param_1 + 0x5c) != '\0')) {
    portSyncSpinlockAcquire(*param_1);
    *(undefined1 *)((long)param_1 + 0x2e1) = 0;
    *(undefined4 *)((long)param_1 + 0x2e4) = 0xffffffff;
    portSyncSpinlockRelease(*param_1);
    return;
  }
  nvAssertFailedNoLog(&DAT_00d5406a,"src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c"
                      ,0x18e);
  return;
}


// ===== 003c8c10 pmaRegisterRegion =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int pmaRegisterRegion(long param_1,uint param_2,char param_3,long *param_4,int param_5,long param_6)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  ulong uVar8;
  
  if (param_1 == 0) {
LAB_003c8fd0:
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x1f7,
                 "pmaRegisterRegion",4,"NVRM: ERROR: NULL PMA object\n");
LAB_003c8e2f:
    if (param_4 == (long *)0x0) goto LAB_003c8f10;
  }
  else {
    if (param_4 != (long *)0x0) {
      uVar8 = (ulong)*(uint *)(param_1 + 0x20);
      if (param_2 == *(uint *)(param_1 + 0x20)) {
        if (param_6 != 0 || param_5 == 0) {
          if (*(char *)(param_1 + 0x2e0) != '\0') {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x209,
                         "pmaRegisterRegion",3,
                         "NVRM: WARNING: registering regions on NUMA system.\n");
          }
          lVar2 = *param_4;
          lVar5 = param_4[1] + 1;
          if ((short)lVar5 != 0 || (short)lVar2 != 0) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x212,
                         "pmaRegisterRegion",4,"NVRM: ERROR: Region range %llx..%llx unaligned\n",
                         lVar2,param_4[1]);
            return 0x1f;
          }
          cVar3 = pmaStateCheck(param_1);
          if (cVar3 == '\0') {
            nvAssertFailedNoLog("pmaStateCheck(pPma)",
                                "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",
                                0x218);
          }
          uVar7 = lVar5 - lVar2;
          lVar5 = (**(code **)(*(long *)(param_1 + 0x230) + 8))
                            (uVar7 >> 0x10,lVar2,param_1 + 0x260,
                             *(undefined1 *)((long)param_4 + 0x16));
          if (lVar5 != 0) {
            lVar1 = param_1 + uVar8 * 8;
            *(long *)(lVar1 + 0x28) = lVar5;
            uVar6 = portMemAllocNonPaged(0x18);
            *(undefined8 *)(lVar1 + 0x130) = uVar6;
            portMemCopy(uVar6,0x18,param_4,0x18);
            *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
            if (param_3 != '\0') {
              if (*(long *)(param_1 + 0x2c0) == 2) {
                nvAssertFailedNoLog("portAtomicGetSize(&pPma->initScrubbing) != PMA_SCRUB_DONE",
                                    "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c"
                                    ,0x233);
              }
              pmaSetBlockStateAttrib(param_1,lVar2,uVar7,8,8);
              LOCK();
              if (*(long *)(param_1 + 0x2c0) == 0) {
                *(long *)(param_1 + 0x2c0) = 1;
              }
              UNLOCK();
            }
            iVar4 = pmaRegisterBlacklistInfo(param_1,lVar2,param_6,param_5);
            if (iVar4 != 0) {
              (**(code **)(*(long *)(param_1 + 0x230) + 0x10))(lVar5);
              portMemFree(*(undefined8 *)(lVar1 + 0x130));
              return iVar4;
            }
            if (*(code **)(param_1 + 0x310) != _pmaDefaultStatsCallback) {
              (**(code **)(param_1 + 0x310))
                        (*(undefined8 *)(param_1 + 0x318),*(undefined8 *)(param_1 + 0x268));
            }
            nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x24c,
                         "pmaRegisterRegion",1,"NVRM: Registered region:\n");
            pmaRegionPrint(param_1,*(undefined8 *)(lVar1 + 0x130),*(undefined8 *)(lVar1 + 0x28));
            nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x24e,
                         "pmaRegisterRegion",1,"NVRM: %d region(s) now registered\n",
                         *(undefined4 *)(param_1 + 0x20));
            return 0;
          }
          return 0x51;
        }
        goto LAB_003c8e60;
      }
LAB_003c8df6:
      nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x1fb,
                   "pmaRegisterRegion",4,
                   "NVRM: ERROR: Non-consecutive region ID %d (should be %d)\n",param_2,uVar8);
      goto LAB_003c8e2f;
    }
    if (param_1 == 0) goto LAB_003c8fd0;
    uVar8 = (ulong)*(uint *)(param_1 + 0x20);
    if (param_2 != *(uint *)(param_1 + 0x20)) goto LAB_003c8df6;
LAB_003c8f10:
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x1ff,
                 "pmaRegisterRegion",4,"NVRM: ERROR: NULL region descriptor\n");
  }
  if (param_6 != 0 || param_5 == 0) {
    return 0x1f;
  }
LAB_003c8e60:
  nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x201,
               "pmaRegisterRegion",4,
               "NVRM: ERROR: Blacklist failure.  List is NULL but count = %d\n",param_5);
  return 0x1f;
}


// ===== 003c9080 pmaAllocatePages =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

ulong pmaAllocatePages(undefined8 *param_1,ulong param_2,ulong param_3,uint *param_4,long *param_5)

{
  ulong *puVar1;
  long lVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  ulong uVar12;
  ulong uVar13;
  long lVar14;
  byte bVar15;
  uint uVar16;
  ulong uVar17;
  byte bVar18;
  undefined8 extraout_RDX;
  undefined8 uVar19;
  uint uVar20;
  code *pcVar21;
  byte bVar22;
  char *pcVar23;
  ulong uVar24;
  undefined4 uVar25;
  ulong uVar26;
  ulong uVar27;
  ulong uVar28;
  ulong uVar29;
  uint uVar30;
  bool bVar31;
  byte local_365;
  ulong local_358;
  ulong local_340;
  uint local_338;
  uint *local_330;
  uint local_324;
  ulong local_310;
  long *local_300;
  ulong local_2f0;
  undefined8 local_2e8;
  long local_2e0;
  undefined8 local_2d8;
  undefined8 local_2d0;
  undefined8 local_2c8;
  undefined8 local_2c0;
  uint local_2b8 [32];
  ulong auStack_238 [65];
  
  uVar6 = 0;
  local_2d8 = 0;
  local_2d0 = 0;
  local_2c8 = 0;
  local_2c0 = 0;
  do {
    uVar12 = (ulong)uVar6;
    uVar6 = uVar6 + 0x20;
    *(undefined8 *)((long)auStack_238 + uVar12) = 0;
    *(undefined8 *)((long)auStack_238 + uVar12 + 8) = 0;
    *(undefined8 *)((long)auStack_238 + uVar12 + 0x10) = 0;
    *(undefined8 *)((long)auStack_238 + uVar12 + 0x18) = 0;
  } while (uVar6 < 0x100);
  uVar6 = 0;
  do {
    uVar12 = (ulong)uVar6;
    uVar6 = uVar6 + 0x20;
    *(undefined8 *)((long)auStack_238 + uVar12 + 0x100) = 0;
    *(undefined8 *)((long)auStack_238 + uVar12 + 0x108) = 0;
    *(undefined8 *)((long)auStack_238 + uVar12 + 0x110) = 0;
    *(undefined8 *)((long)auStack_238 + uVar12 + 0x118) = 0;
  } while (uVar6 < 0x100);
  if (param_1 == (undefined8 *)0x0) {
LAB_003c9d48:
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x282,
                 "pmaAllocatePages",4,"NVRM: NULL PMA object\n");
    if (param_5 == (long *)0x0) {
LAB_003c9a66:
      nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x284,
                   "pmaAllocatePages",4,"NVRM: NULL page list pointer\n");
    }
    if (param_2 == 0) {
LAB_003c9cb8:
      nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x286,
                   "pmaAllocatePages",4,"NVRM: count == 0\n");
    }
    if ((((param_3 - 0x10000 & 0xfffffffffffeffff) != 0) && (param_3 != 0x200000)) &&
       (param_3 != 0x20000000)) goto LAB_003c9d10;
  }
  else {
    if (param_5 == (long *)0x0) {
      if (param_1 == (undefined8 *)0x0) goto LAB_003c9d48;
      goto LAB_003c9a66;
    }
    if (param_2 == 0) goto LAB_003c9cb8;
    if ((((param_3 - 0x10000 & 0xfffffffffffeffff) == 0) || (param_3 == 0x20000000)) ||
       (param_3 == 0x200000)) {
      if (param_4 == (uint *)0x0) goto LAB_003c9ed8;
      uVar6 = *param_4;
      uVar11 = 1;
      if (*(char *)(param_1 + 0x4b) == '\0') {
        uVar11 = uVar6 >> 7 & 1;
      }
      uVar30 = uVar6 & 0x2000;
      if (*(char *)(param_1 + 0x5c) != '\0') {
        if (uVar30 == 0) {
          uVar12 = pmaNumaAllocate(param_1,param_2,param_3,param_4,param_5);
          return uVar12;
        }
        pcVar23 = "NVRM: Reverse allocation not supported on NUMA.\n";
        uVar19 = 0x2a1;
        goto LAB_003c9f30;
      }
      uVar20 = uVar6 & 0x800;
      local_338 = uVar6 & 0x40;
      bVar15 = (byte)((uVar6 & 0x40) >> 6) ^ 1;
      bVar22 = (byte)(uVar20 >> 0xb) & bVar15;
      bVar18 = ~(byte)(uVar6 >> 10) & *(char *)(param_1 + 0x59) != '\0';
      if (bVar18 == 0) {
        param_4[0xc] = 0;
        if (bVar22 != 0) {
LAB_003ca130:
          pcVar23 = "NVRM: Blacklist can only be turned off for contiguous allocations\n";
          uVar19 = 0x2b9;
          goto LAB_003c9f30;
        }
        bVar3 = false;
        bVar18 = 0;
      }
      else {
        param_4[0xc] = 1;
        if (bVar22 != 0) goto LAB_003ca130;
        if (uVar20 != 0) {
          pcVar23 = "NVRM: Blacklist cannot be turned off when scrub on free is enabled\n";
          uVar19 = 0x2bf;
          goto LAB_003c9f30;
        }
        bVar3 = true;
      }
      uVar16 = uVar6 & 8;
      if (uVar16 != 0) {
        local_358 = *(ulong *)(param_4 + 2);
        uVar12 = *(long *)(param_4 + 4) + 1;
        if ((param_3 - 1 & (local_358 | uVar12)) != 0) {
          uVar19 = 0x2c6;
          pcVar23 = "NVRM: base [0x%llx] or limit [0x%llx] not aligned to page size 0x%llx\n";
          goto LAB_003ca112;
        }
      }
      local_358 = param_3;
      if ((uVar6 & 0x200) != 0) {
        uVar12 = *(ulong *)(param_4 + 8);
        if (((uVar12 - 1 | 0xffff) & uVar12) != 0) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x2d7,
                       "pmaAllocatePages",3,
                       "NVRM: alignment [%llx] is not aligned to 64KB or is not power of two.",
                       param_3);
          return 0x1f;
        }
        if (param_3 <= uVar12) {
          local_358 = uVar12;
        }
        if ((param_3 < uVar12) && (bVar15 != 0)) {
          pcVar23 = 
          "NVRM: alignment [%llx] larger than the pageSize [%llx] not supported for non-contiguous allocs\n"
          ;
          uVar19 = 0x2e0;
          uVar12 = param_3;
LAB_003ca112:
          nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",uVar19,
                       "pmaAllocatePages",3,pcVar23,local_358,uVar12);
          return 0x1f;
        }
      }
      uVar7 = uVar6 >> 0xe & 1 ^ 1;
      uVar8 = uVar6 & 0xc000;
      if (uVar8 != 0) {
        if ((local_338 == 0) || (param_3 * param_2 < 0x2000001)) {
          if ((byte)uVar7 == ((byte)(uVar6 >> 0xf) & 1)) goto LAB_003c9393;
          pcVar23 = "NVRM: Only one ugpu can be specified for localized allocations\n";
          uVar19 = 0x2f2;
        }
        else {
          pcVar23 = "NVRM: Localized contig allocation size is too large\n";
          uVar19 = 0x2ec;
        }
LAB_003c9f30:
        nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",uVar19,
                     "pmaAllocatePages",4,pcVar23);
        return 0x1f;
      }
LAB_003c9393:
      pcVar21 = *(code **)(param_1[0x46] + 0x68);
      if (local_338 != 0) {
        pcVar21 = *(code **)(param_1[0x46] + 0x60);
      }
      uVar9 = pmaSelector(param_1,param_4,local_2b8);
      if (uVar9 != 0) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x305,
                     "pmaAllocatePages",6,"NVRM: Region selector failed\n");
        return (ulong)uVar9;
      }
      if (bVar3) {
        portSyncMutexAcquire(param_1[3]);
        portSyncRwLockAcquireRead(param_1[2]);
        if (param_1[0x5a] != 1) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x30f,
                       "pmaAllocatePages",3,"NVRM: PMA object is not valid\n");
          portSyncRwLockReleaseRead(param_1[2]);
          portSyncMutexRelease(param_1[3]);
          return 0x40;
        }
      }
      pcVar23 = "discontiguous";
      bVar4 = true;
      local_365 = ~(byte)uVar6 & 1;
      uVar12 = param_3 >> 0x10;
      uVar25 = (undefined4)(param_3 >> 0x10);
      if (local_338 != 0) {
        pcVar23 = "contiguous";
      }
      uVar24 = 0;
      do {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",799,
                     "pmaAllocatePages",1,
                     "NVRM: Attempt %s allocation of 0x%llx pages of size 0x%llx (0x%x frames per page)\n"
                     ,pcVar23,param_2,param_3,uVar25);
        if (bVar3) {
          uVar9 = _pmaCheckScrubbedPages(param_1,0,0,0);
          uVar24 = (ulong)uVar9;
          if (uVar9 == 0) goto LAB_003c9517;
LAB_003c9c3a:
          if ((uVar20 != 0) && (*(int *)(param_1 + 4) != 0)) {
            uVar12 = 0;
            do {
              if (*(char *)((long)&local_2d8 + uVar12) != '\0') {
                _pmaReallocBlacklistPages
                          (param_1,uVar12 & 0xffffffff,auStack_238[uVar12],
                           auStack_238[uVar12 + 0x20]);
              }
              uVar12 = uVar12 + 1;
            } while ((uint)uVar12 < *(uint *)(param_1 + 4));
          }
          LOCK();
          param_1[0x5a] = 0;
          UNLOCK();
LAB_003c9c90:
          portSyncRwLockReleaseRead(param_1[2]);
          portSyncMutexRelease(param_1[3]);
          return uVar24;
        }
LAB_003c9517:
        portSyncSpinlockAcquire(*param_1);
        cVar5 = pmaStateCheck(param_1);
        if (cVar5 == '\0') {
          nvAssertFailedNoLog("pmaStateCheck(pPma)",
                              "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x333
                             );
        }
        iVar10 = _pmaPredictOutOfMemory(param_1,param_2,param_3,param_4);
        bVar15 = local_365 ^ 1;
        if ((iVar10 == 0x51) && (bVar15 != 0)) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x338,
                       "pmaAllocatePages",1,"NVRM: Returning OOM from prediction path.\n");
LAB_003ca020:
          uVar24 = 0x51;
          goto LAB_003c9860;
        }
        uVar28 = param_2;
        if (*(int *)(param_1 + 4) != 0) {
          local_330 = local_2b8;
          uVar29 = 0;
          local_324 = 1;
          local_300 = param_5;
          do {
            uVar9 = *local_330;
            if (uVar9 == 0xffffffff) goto LAB_003ca020;
            if (0x1f < (int)uVar9) {
              nvAssertFailedNoLog("regionList[regionIdx] < PMA_REGION_SIZE",
                                  "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",
                                  0x346);
              uVar9 = *local_330;
            }
            uVar26 = (ulong)uVar9;
            puVar1 = (ulong *)param_1[uVar26 + 0x26];
            uVar24 = *puVar1;
            if (uVar16 == 0) {
LAB_003c97f8:
              uVar17 = 0;
              uVar27 = 0;
            }
            else {
              uVar13 = *(ulong *)(param_4 + 4);
              if (*(ulong *)(param_4 + 2) < uVar24) {
                if (uVar13 < uVar24) goto LAB_003c97f8;
                uVar17 = uVar13 - uVar24;
                uVar27 = 0;
              }
              else {
                uVar27 = *(ulong *)(param_4 + 2) - uVar24;
                uVar17 = 0;
                if (uVar24 <= uVar13) {
                  uVar17 = uVar13 - uVar24;
                }
                if (uVar17 < uVar27) {
                  uVar24 = 0x1f;
                  goto LAB_003c9860;
                }
              }
            }
            uVar19 = param_1[uVar26 + 5];
            local_340 = puVar1[1];
            cVar5 = *(char *)((long)puVar1 + 0x16);
            if ((uVar20 != 0) && (*(char *)((long)&local_2d8 + uVar26) == '\0')) {
              if (local_340 < *(ulong *)(param_4 + 2)) {
                auStack_238[uVar26] = 0;
                auStack_238[uVar26 + 0x20] = 0;
              }
              else {
                auStack_238[uVar26] = uVar24;
                auStack_238[uVar26 + 0x20] = (local_340 + 1) - uVar24;
                _pmaFreeBlacklistPages(param_1,uVar26,uVar24);
                *(undefined1 *)((long)&local_2d8 + uVar26) = 1;
              }
            }
            if (uVar29 + uVar28 != param_2) {
              nvAssertFailedNoLog("numPagesLeftToAllocate + numPagesAllocatedSoFar == allocationCount"
                                  ,"src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",
                                  0x374);
            }
            if (uVar28 == 0) {
              nvAssertFailedNoLog("numPagesLeftToAllocate > 0",
                                  "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",
                                  0x375);
            }
            local_2f0 = 0;
            uVar9 = (*pcVar21)(uVar19,uVar24,uVar27,uVar17,uVar28,local_300,param_3,local_358,
                               uVar8 != 0,uVar7,&local_2f0,bVar15,uVar30 >> 0xd);
            if (uVar28 < local_2f0) {
              nvAssertFailedNoLog("numPagesAllocatedThisTime <= numPagesLeftToAllocate",
                                  "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",
                                  0x37b);
            }
            if (((local_338 != 0) && (local_2f0 != 0)) && (uVar28 != local_2f0)) {
              nvAssertFailedNoLog("numPagesAllocatedThisTime == 0 || numPagesAllocatedThisTime == numPagesLeftToAllocate"
                                  ,"src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",
                                  0x380);
            }
            uVar29 = uVar29 + local_2f0;
            uVar28 = uVar28 - local_2f0;
            local_300 = local_300 + local_2f0;
            if ((uVar9 == 0x17) && (bVar15 != 0)) {
              nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x393,
                           "pmaAllocatePages",3,
                           "NVRM: Memory evictable, but eviction not allowed, returning\n");
LAB_003c9756:
              if ((local_324 - 1 < *(int *)(param_1 + 4) - 1U) && (local_330[1] == 0xffffffff)) {
                nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x3a6,
                             "pmaAllocatePages",4,"NVRM: Status no_memory\n");
              }
              if ((local_338 != 0) && (local_2f0 != 0)) {
                nvAssertFailedNoLog("numPagesAllocatedThisTime == 0",
                                    "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c"
                                    ,0x3ab);
              }
              uVar24 = 0x51;
LAB_003c979b:
              if (*(uint *)(param_1 + 4) <= local_324) goto LAB_003ca3f0;
            }
            else {
              if (uVar9 == 0) {
                if (uVar28 != 0) {
                  nvAssertFailedNoLog("numPagesLeftToAllocate == 0",
                                      "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c"
                                      ,0x399);
                }
                local_300 = (long *)uVar29;
                if (param_2 != uVar29) {
                  nvAssertFailedNoLog("numPagesAllocatedSoFar == allocationCount",
                                      "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c"
                                      ,0x39a);
                }
                goto LAB_003ca1f9;
              }
              if (uVar9 == 0x51) goto LAB_003c9756;
              if (local_365 != 0) {
                bVar31 = cVar5 != '\0';
                nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x3b0,
                             "pmaAllocatePages",1,
                             "NVRM: Status evictable, region before eviction:\n");
                pmaRegionPrint(param_1,param_1[uVar26 + 0x26],uVar19);
                if (uVar28 == 0) {
                  nvAssertFailedNoLog("numPagesLeftToAllocate > 0",
                                      "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c"
                                      ,0x3b3);
                  if (local_338 != 0) {
LAB_003ca058:
                    nvAssertFailedNoLog("numPagesLeftToAllocate == allocationCount",
                                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c"
                                        ,0x3b7);
                    goto LAB_003c9984;
                  }
LAB_003c9ac0:
                  if (uVar16 == 0) {
                    uVar17 = 0;
                    uVar13 = uVar24;
                  }
                  else {
                    uVar13 = *(ulong *)(param_4 + 2);
                    if (*(ulong *)(param_4 + 2) <= uVar24) {
                      uVar13 = uVar24;
                    }
                    uVar27 = *(ulong *)(param_4 + 4);
                    if (local_340 <= *(ulong *)(param_4 + 4)) {
                      uVar27 = local_340;
                    }
                    uVar17 = uVar13 - uVar24 >> 0x10;
                    local_340 = uVar27;
                    if (uVar27 < uVar13) {
                      nvAssertFailedNoLog("evictPhysBegin <= evictPhysEnd",
                                          "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c"
                                          ,0x3d9);
                    }
                  }
                  nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",
                               0x3dc,"pmaAllocatePages",1,
                               "NVRM: Attempt %s eviction of 0x%llx pages of size 0x%llx, (0x%x frames per page), in the frame range 0x%llx..0x%llx\n"
                               ,"discontiguous",uVar28,param_3,uVar25,uVar17,
                               local_340 - uVar24 >> 0x10);
                  uVar9 = _pmaEvictPages(param_1,uVar19,local_300,uVar28,param_5,uVar29,param_3,
                                         uVar13,local_340,bVar31);
                }
                else {
                  if (local_338 == 0) goto LAB_003c9ac0;
                  if (param_2 != uVar28) goto LAB_003ca058;
LAB_003c9984:
                  if (local_2f0 != 0) {
                    nvAssertFailedNoLog("numPagesAllocatedThisTime == 0",
                                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c"
                                        ,0x3b8);
                  }
                  if (uVar29 != 0) {
                    nvAssertFailedNoLog("numPagesAllocatedSoFar == 0",
                                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c"
                                        ,0x3b9);
                  }
                  lVar2 = *local_300;
                  lVar14 = lVar2 + -1 + param_2 * uVar12 * 0x10000;
                  nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",
                               0x3be,"pmaAllocatePages",1,
                               "NVRM: Attempt %s eviction of 0x%llx pages of size 0x%llx, (0x%x frames per page) in the frame range 0x%llx..0x%llx\n"
                               ,"contiguous",uVar28,param_3,uVar25,lVar2 - uVar24 >> 0x10,
                               lVar14 - uVar24 >> 0x10);
                  uVar9 = _pmaEvictContiguous(param_1,uVar19,lVar2,lVar14,bVar31);
                }
                if (uVar9 != 0) {
                  nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",
                               0x3f0,"pmaAllocatePages",1,
                               "NVRM: Eviction/scrubbing failed, region after:\n");
                  pmaRegionPrint(param_1,param_1[uVar26 + 0x26],uVar19);
                  uVar24 = (ulong)uVar9;
                  if (uVar9 != 0x1a) goto LAB_003c979b;
                  uVar24 = 0x1a;
                  nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",
                               0x3f6,"pmaAllocatePages",4,"NVRM: ERROR: scrubber OOM\n");
                  goto LAB_003c9c3a;
                }
                uVar9 = 0;
                uVar29 = param_2;
              }
              uVar24 = (ulong)uVar9;
              if (*(uint *)(param_1 + 4) <= local_324) goto LAB_003c9838;
            }
            local_324 = local_324 + 1;
            local_330 = local_330 + 1;
          } while( true );
        }
        uVar29 = 0;
LAB_003ca3f0:
        if ((int)uVar24 != 0x51) {
LAB_003c9838:
          local_300 = (long *)uVar29;
          if ((int)uVar24 != 0) goto LAB_003c9860;
LAB_003ca1f9:
          uVar24 = 0;
          if ((bVar3) && (param_1[0x5a] != 1)) {
            uVar24 = 0x1a;
            portSyncSpinlockRelease(*param_1);
            nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x466,
                         "pmaAllocatePages",6,
                         "NVRM: Failing allocation because the scrubber is not valid.\n");
            goto LAB_003c9c3a;
          }
          uVar6 = ((uVar6 & 2) != 0) + 1 | uVar11 << 4;
          *(long **)(param_4 + 10) = local_300;
          if (local_338 == 0) {
            uVar24 = 0;
            nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x4ab,
                         "pmaAllocatePages",1,"NVRM: Successfully allocated frames:\n");
            local_310 = 0;
            uVar11 = 0;
            if (local_300 != (long *)0x0) {
              uVar28 = 0;
              uVar16 = uVar11;
              do {
                uVar11 = findRegionID(param_1,param_5[uVar28]);
                uVar19 = param_1[(ulong)uVar11 + 5];
                uVar26 = (ulong)(param_5[uVar28] - *(long *)param_1[(ulong)uVar11 + 0x26]) >> 0x10;
                uVar29 = uVar26;
                if ((uVar28 != 0) && ((uVar16 != uVar11 || (uVar29 = local_310, uVar24 != uVar26))))
                {
                  lVar14 = uVar24 - 1;
                  if (uVar30 != 0) {
                    lVar14 = (uVar12 - 1) + local_310;
                  }
                  uVar24 = uVar12 + uVar24;
                  if (uVar30 == 0) {
                    uVar24 = local_310;
                  }
                  nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",
                               0x4c0,"pmaAllocatePages",1,"NVRM: 0x%llx through 0x%llx region %d \n"
                               ,uVar24,lVar14,uVar16);
                  uVar29 = uVar26;
                }
                local_310 = uVar29;
                uVar24 = uVar12;
                if (uVar30 != 0) {
                  uVar24 = -uVar12;
                }
                uVar24 = uVar24 + uVar26;
                if (uVar8 != 0) {
                  nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",
                               0x4d2,"pmaAllocatePages",1,
                               "NVRM: Marking region containing frame 0x%llx as localized\n",uVar26)
                  ;
                  (**(code **)(param_1[0x46] + 0x30))(uVar19,uVar26,1,1);
                }
                uVar28 = uVar28 + 1;
                (**(code **)(param_1[0x46] + 0x20))(uVar19,uVar26,param_3,uVar6,0x7f);
                uVar16 = uVar11;
              } while (local_300 != (long *)uVar28);
            }
            (*(code *)param_1[0x62])(param_1[99],param_1[0x4d]);
            lVar14 = (uVar12 - 1) + local_310;
            uVar12 = uVar12 + uVar24;
            if (uVar30 == 0) {
              uVar12 = local_310;
              lVar14 = uVar24 - 1;
            }
            uVar24 = 0;
            nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x4e1,
                         "pmaAllocatePages",1,"NVRM: 0x%llx through 0x%llx region %d \n",uVar12,
                         lVar14,uVar11);
LAB_003c9860:
            if (uVar20 != 0) {
LAB_003c986a:
              if (*(int *)(param_1 + 4) != 0) {
                uVar12 = 0;
                do {
                  if (*(char *)((long)&local_2d8 + uVar12) != '\0') {
                    _pmaReallocBlacklistPages
                              (param_1,uVar12 & 0xffffffff,auStack_238[uVar12],
                               auStack_238[uVar12 + 0x20]);
                  }
                  uVar12 = uVar12 + 1;
                } while ((uint)uVar12 < *(uint *)(param_1 + 4));
              }
            }
LAB_003c98ab:
            portSyncSpinlockRelease(*param_1);
            if (!bVar3) {
              return uVar24;
            }
            goto LAB_003c9c90;
          }
          uVar11 = findRegionID(param_1,*param_5);
          uVar28 = (ulong)uVar11;
          uVar19 = param_1[uVar28 + 5];
          lVar2 = *(long *)param_1[uVar28 + 0x26];
          uVar29 = (ulong)(*param_5 - lVar2) >> 0x10;
          lVar14 = (long)local_300 * uVar12 + -1 + uVar29;
          nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x47a,
                       "pmaAllocatePages",1,
                       "NVRM: Successfully allocated frames 0x%llx through 0x%llx\n",uVar29,lVar14,
                       extraout_RDX);
          if (uVar8 != 0) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x48b,
                         "pmaAllocatePages",1,
                         "NVRM: Marking region containing frame 0x%llx as localized\n",uVar29);
            (**(code **)(param_1[0x46] + 0x30))(uVar19,uVar29,1,1);
          }
          (**(code **)(param_1[0x46] + 0x28))(uVar19,uVar29,(long)local_300 * uVar12,uVar6,0x7f);
          (*(code *)param_1[0x62])(param_1[99],param_1[0x4d]);
          if (uVar20 == 0) {
            uVar24 = 0;
            goto LAB_003c98ab;
          }
          if (*(char *)((long)&local_2d8 + uVar28) != '\0') {
            *(undefined1 *)((long)&local_2d8 + uVar28) = 0;
            uVar26 = auStack_238[uVar28];
            uVar29 = lVar2 + 0xffff + lVar14 * 0x10000;
            uVar12 = (auStack_238[uVar28 + 0x20] - 1) + uVar26;
            _pmaReallocBlacklistPages(param_1,uVar11,uVar26,(*param_5 + 1) - uVar26);
            if (uVar29 < uVar12) {
              _pmaReallocBlacklistPages(param_1,uVar11,uVar29,uVar12 - uVar29);
            }
          }
          goto LAB_003c986a;
        }
        if (param_1[0x58] == 1) {
          portSyncSpinlockRelease(*param_1);
          while (param_1[0x58] != 2) {
            pmaOsSchedule();
          }
          uVar24 = 0x51;
          nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x40e,
                       "pmaAllocatePages",1,"NVRM: Retrying after eviction/scrub\n");
        }
        else {
          if ((((uVar6 & 0x1000) != 0) && (uVar29 != 0)) && (!bVar3 || !bVar4)) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x41c,
                         "pmaAllocatePages",1,"NVRM: Succeed partial allocation\n");
            local_300 = (long *)uVar29;
            goto LAB_003ca1f9;
          }
          if (bVar18 == 0) goto LAB_003ca020;
          local_2e8 = 0;
          portSyncSpinlockRelease(*param_1);
          nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x427,
                       "pmaAllocatePages",1,"NVRM: Waiting for scrubber\n");
          uVar9 = scrubCheckAndWaitForSize(param_1[0x5b],uVar28,param_3,&local_2e8,&local_2e0);
          uVar24 = (ulong)uVar9;
          if (uVar9 == 0) {
            if (local_2e0 != 0) {
              _pmaClearScrubBit(param_1,local_2e8);
            }
            portMemFree(local_2e8);
          }
          if (!bVar4) {
            if ((uVar20 != 0) && (*(int *)(param_1 + 4) != 0)) {
              uVar12 = 0;
              do {
                if (*(char *)((long)&local_2d8 + uVar12) != '\0') {
                  _pmaReallocBlacklistPages
                            (param_1,uVar12 & 0xffffffff,auStack_238[uVar12],
                             auStack_238[uVar12 + 0x20]);
                }
                uVar12 = uVar12 + 1;
              } while ((uint)uVar12 < *(uint *)(param_1 + 4));
            }
            if (bVar3) {
              portSyncRwLockReleaseRead(param_1[2]);
              portSyncMutexRelease(param_1[3]);
            }
            nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x456,
                         "pmaAllocatePages",1,"NVRM: Returning OOM after waiting for scrubber\n");
            return 0x51;
          }
          nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x444,
                       "pmaAllocatePages",1,"NVRM: Retrying after waiting for scrubber\n");
          bVar4 = false;
          local_365 = 0;
        }
      } while( true );
    }
LAB_003c9d10:
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x288,
                 "pmaAllocatePages",4,"NVRM: pageSize=0x%llx (not 64K, 128K, 2M, or 512M)\n",param_3
                );
  }
  if (param_4 != (uint *)0x0) {
    return 0x1f;
  }
LAB_003c9ed8:
  nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x28a,
               "pmaAllocatePages",4,"NVRM: NULL allocationOptions\n");
  return 0x1f;
}


// ===== 003cab10 pmaPinPages =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint pmaPinPages(undefined8 *param_1,long *param_2,ulong param_3,long param_4)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  uint uVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  uint local_50;
  
  if (((param_3 == 0 || param_2 == (long *)0x0) || (param_1 == (undefined8 *)0x0)) ||
     (((param_4 - 0x10000U & 0xfffffffffffeffff) != 0 &&
      ((param_4 != 0x200000 && (param_4 != 0x20000000)))))) {
    return 0x1f;
  }
  portSyncSpinlockAcquire(*param_1);
  uVar7 = findRegionID(param_1,*param_2);
  uVar9 = (**(code **)(param_1[0x46] + 0x50))
                    (param_1[(ulong)uVar7 + 5],
                     (ulong)(*param_2 - *(long *)param_1[(ulong)uVar7 + 0x26]) >> 0x10);
  if ((uVar9 & 1) == 0) {
    uVar9 = 0;
    local_50 = 0;
    do {
      plVar2 = param_2 + uVar9;
      uVar8 = findRegionID(param_1,*plVar2);
      lVar5 = *plVar2;
      lVar11 = 0;
      lVar6 = *(long *)param_1[(ulong)uVar8 + 0x26];
      do {
        lVar10 = ((ulong)(lVar5 - lVar6) >> 0x10) + lVar11;
        uVar9 = (**(code **)(param_1[0x46] + 0x40))(param_1[(ulong)uVar8 + 5],lVar10,1);
        uVar7 = (uint)uVar9 & 4;
        uVar4 = (uint)((ulong)param_4 >> 0x10);
        if (((uint)uVar9 & 3) != 1) {
          if ((uVar9 & 4) != 0) goto LAB_003cae1f;
          nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x554,
                       "pmaPinPages",4,
                       "NVRM: Pin failed at page %d frame %d in region %d state %d\n",local_50,
                       lVar11,uVar8,uVar9);
          uVar7 = 0x40;
LAB_003cacb2:
          if (local_50 != 0) {
            plVar3 = param_2 + local_50;
            do {
              lVar10 = 0;
              uVar8 = findRegionID(param_1,*param_2);
              lVar5 = *param_2;
              lVar6 = *(long *)param_1[(ulong)uVar8 + 0x26];
              do {
                lVar1 = lVar10 + ((ulong)(lVar5 - lVar6) >> 0x10);
                lVar10 = lVar10 + 1;
                (**(code **)(param_1[0x46] + 0x18))(param_1[(ulong)uVar8 + 5],lVar1,1,3);
              } while ((uint)lVar10 < uVar4);
              param_2 = param_2 + 1;
            } while (param_2 != plVar3);
            if ((code *)param_1[0x62] != _pmaDefaultStatsCallback) {
              (*(code *)param_1[0x62])(param_1[99],param_1[0x4d]);
            }
          }
          if ((int)lVar11 != 0) {
            uVar8 = findRegionID(param_1,*plVar2);
            uVar12 = (ulong)(*plVar2 - *(long *)param_1[(ulong)uVar8 + 0x26]) >> 0x10;
            uVar9 = uVar12;
            do {
              uVar13 = uVar9 + 1;
              (**(code **)(param_1[0x46] + 0x18))(param_1[(ulong)uVar8 + 5],uVar9,1,3);
              uVar9 = uVar13;
            } while (uVar12 + lVar11 != uVar13);
            if ((code *)param_1[0x62] != _pmaDefaultStatsCallback) {
              (*(code *)param_1[0x62])(param_1[99],param_1[0x4d]);
            }
          }
          goto LAB_003cad7b;
        }
        if ((uVar9 & 4) != 0) {
LAB_003cae1f:
          uVar7 = 0x17;
          goto LAB_003cacb2;
        }
        lVar11 = lVar11 + 1;
        (**(code **)(param_1[0x46] + 0x18))(param_1[(ulong)uVar8 + 5],lVar10,2,3);
      } while ((uint)lVar11 < uVar4);
      local_50 = local_50 + 1;
      uVar9 = (ulong)local_50;
    } while (uVar9 < param_3);
  }
  else {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x52e,
                 "pmaPinPages",4,"NVRM: Localized allocations cannot change pin state\n");
    uVar7 = 0x1f;
  }
LAB_003cad7b:
  portSyncSpinlockRelease(*param_1);
  return uVar7;
}


// ===== 003caf30 pmaFreePages =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void pmaFreePages(undefined8 *param_1,long param_2,long param_3,ulong param_4,uint param_5)

{
  undefined8 uVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  long lVar8;
  ulong uVar9;
  long local_50;
  undefined8 local_48;
  long local_40 [2];
  
  uVar7 = (uint)*(byte *)(param_1 + 0x59);
  if (*(byte *)(param_1 + 0x59) != 0) {
    uVar7 = ~param_5 & 1;
  }
  if (param_3 == 0) {
    nvAssertFailedNoLog("pageCount != 0",
                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x57b);
    if (param_2 == 0) {
      nvAssertFailedNoLog("pPages != NULL",
                          "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x57c);
    }
LAB_003caf8c:
    if ((((param_4 - 0x10000 & 0xfffffffffffeffff) != 0) && (param_4 != 0x200000)) &&
       (param_4 != 0x20000000)) {
      nvAssertFailedNoLog("(size == _PMA_64KB) || (size == _PMA_128KB) || (size == _PMA_2MB) || (size == _PMA_512MB)"
                          ,"src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x580);
    }
  }
  else {
    if (param_2 == 0) {
      nvAssertFailedNoLog("pPages != NULL",
                          "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x57c);
    }
    if (param_3 != 1) goto LAB_003caf8c;
  }
  if (*(char *)(param_1 + 0x5c) != '\0') {
    portSyncSpinlockAcquire(*param_1);
    pmaNumaFreeInternal(param_1,param_2,param_3,param_4,param_5);
    portSyncSpinlockRelease(*param_1);
    return;
  }
  if ((char)uVar7 != '\0') {
    portSyncRwLockAcquireRead(param_1[2]);
    if (param_1[0x5a] == 1) {
      iVar4 = _pmaCheckScrubbedPages(param_1,0,0,0);
      if (iVar4 == 0) goto LAB_003cafbd;
      LOCK();
      param_1[0x5a] = 0;
      UNLOCK();
      portSyncRwLockReleaseRead(param_1[2]);
      nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x59b,
                   "pmaFreePages",3,"NVRM: Scrubber object is not valid\n");
    }
    else {
      portSyncRwLockReleaseRead(param_1[2]);
      nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x5a3,
                   "pmaFreePages",3,"NVRM: Scrubber object is not valid\n");
    }
    uVar7 = 0;
  }
LAB_003cafbd:
  portSyncSpinlockAcquire(*param_1);
  if (param_3 != 0) {
    local_50 = 0;
    lVar8 = local_50;
    do {
      local_50 = lVar8;
      uVar3 = findRegionID(param_1,*(undefined8 *)(param_2 + local_50 * 8));
      lVar8 = *(long *)(param_2 + local_50 * 8);
      uVar1 = param_1[(ulong)uVar3 + 5];
      lVar2 = *(long *)param_1[(ulong)uVar3 + 0x26];
      _pmaReallocBlacklistPages(param_1,uVar3,lVar8,param_3 * param_4);
      if (param_4 >> 0x10 != 0) {
        uVar5 = (ulong)(lVar8 - lVar2) >> 0x10;
        uVar6 = uVar5;
        do {
          uVar9 = uVar6 + 1;
          (**(code **)(param_1[0x46] + 0x18))(uVar1,uVar6,uVar7 * 8,0xffffffbb);
          uVar6 = uVar9;
        } while ((param_4 >> 0x10) + uVar5 != uVar9);
      }
      lVar8 = local_50 + 1;
    } while (param_3 != local_50 + 1);
    lVar8 = 0;
    while( true ) {
      uVar3 = findRegionID(param_1,*(undefined8 *)(param_2 + lVar8 * 8));
      uVar1 = param_1[(ulong)uVar3 + 5];
      uVar6 = (ulong)(*(long *)(param_2 + lVar8 * 8) - *(long *)param_1[(ulong)uVar3 + 0x26]) >>
              0x10;
      uVar3 = (**(code **)(param_1[0x46] + 0x48))(uVar1,uVar6);
      if (((uVar3 & 1) != 0) && (uVar3 >> 0x10 == 0)) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x5e4,
                     "pmaFreePages",1,"NVRM: Reclaiming localized region containing frame 0x%llx\n",
                     uVar6);
        (**(code **)(param_1[0x46] + 0x30))(uVar1,uVar6,0,1);
      }
      if (lVar8 == local_50) break;
      lVar8 = lVar8 + 1;
    }
  }
  if ((code *)param_1[0x62] != _pmaDefaultStatsCallback) {
    (*(code *)param_1[0x62])(param_1[99],param_1[0x4d]);
  }
  portSyncSpinlockRelease(*param_1);
  if ((char)uVar7 != '\0') {
    local_48 = 0;
    iVar4 = scrubSubmitPages(param_1[0x5b],param_4,param_2,param_3,&local_48,local_40);
    if (iVar4 == 0) {
      if (local_40[0] != 0) {
        _pmaClearScrubBit(param_1,local_48,local_40[0],0x3cb19b);
      }
    }
    else {
      LOCK();
      param_1[0x5a] = 0;
      UNLOCK();
    }
    portMemFree(local_48);
    portSyncRwLockReleaseRead(param_1[2]);
  }
  return;
}


// ===== 003cb3c0 pmaScrubComplete =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 pmaScrubComplete(long param_1)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  
  if (param_1 != 0) {
    uVar4 = 0xffff;
    if (*(long *)(param_1 + 0x2c0) == 1) {
      if (*(int *)(param_1 + 0x20) != 0) {
        lVar5 = 0;
        do {
          plVar2 = *(long **)(param_1 + 0x130 + lVar5 * 8);
          lVar5 = lVar5 + 1;
          lVar3 = *plVar2;
          pmaSetBlockStateAttrib(param_1,lVar3,(plVar2[1] + 1) - lVar3,0,8);
        } while ((uint)lVar5 < *(uint *)(param_1 + 0x20));
      }
      if (*(code **)(param_1 + 0x310) != _pmaDefaultStatsCallback) {
        (**(code **)(param_1 + 0x310))
                  (*(undefined8 *)(param_1 + 0x318),*(undefined8 *)(param_1 + 0x268));
      }
      nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x644,
                   "pmaScrubComplete",1,"NVRM: Inside\n");
      if (*(int *)(param_1 + 0x20) != 0) {
        lVar5 = 0;
        do {
          lVar3 = lVar5 * 8;
          lVar1 = lVar5 * 8;
          lVar5 = lVar5 + 1;
          pmaRegionPrint(param_1,*(undefined8 *)(param_1 + 0x130 + lVar1),
                         *(undefined8 *)(param_1 + 0x28 + lVar3));
        } while ((uint)lVar5 < *(uint *)(param_1 + 0x20));
      }
      LOCK();
      *(undefined8 *)(param_1 + 0x2c0) = 2;
      UNLOCK();
      uVar4 = 0;
    }
    return uVar4;
  }
  return 0x1f;
}


// ===== 003cb4f0 pmaDestroy.part.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void pmaDestroy_part_0(long *param_1)

{
  long lVar1;
  char cVar2;
  long lVar3;
  
  cVar2 = pmaStateCheck();
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("pmaStateCheck(pPma)",
                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x1a4);
  }
  if (param_1[0x58] == 1) {
    pmaScrubComplete(param_1);
  }
  if (((char)param_1[0x5c] != '\0') && (*(char *)((long)param_1 + 0x2e1) != '\0')) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x1b3,"pmaDestroy"
                 ,3,"NVRM: Destroying PMA before node %d is offlined\n",
                 *(undefined4 *)((long)param_1 + 0x2e4));
  }
  if ((int)param_1[4] != 0) {
    lVar3 = 0;
    do {
      (**(code **)(param_1[0x46] + 0x10))(param_1[lVar3 + 5]);
      lVar1 = lVar3 + 0x26;
      lVar3 = lVar3 + 1;
      portMemFree(param_1[lVar1]);
    } while ((uint)lVar3 < *(uint *)(param_1 + 4));
  }
  *(undefined4 *)(param_1 + 4) = 0;
  if ((int)param_1[0x61] != 0) {
    portMemFree(param_1[0x60]);
  }
  portMemFree(param_1[0x46]);
  if (param_1[3] != 0) {
    portSyncMutexDestroy();
    portMemFree(param_1[3]);
  }
  if (param_1[2] != 0) {
    portSyncRwLockDestroy();
    portMemFree(param_1[2]);
  }
  if (param_1[1] != 0) {
    portSyncMutexDestroy();
    portMemFree(param_1[1]);
  }
  if (*param_1 != 0) {
    portSyncSpinlockDestroy();
    portMemFree(*param_1);
  }
  portMemFree(param_1);
  return;
}


// ===== 003cb690 pmaDestroy =====

void pmaDestroy(long param_1)

{
  if (param_1 != 0) {
    pmaDestroy_part_0();
    return;
  }
  return;
}


// ===== 003cb6b0 pmaInitialize =====

int pmaInitialize(long *param_1,ulong param_2)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  uint uVar6;
  
  if (param_1 == (long *)0x0) {
    return 0x1f;
  }
  plVar4 = (long *)portMemAllocNonPaged(800);
  *param_1 = (long)plVar4;
  if (plVar4 == (long *)0x0) {
    return 0x51;
  }
  portMemSet(plVar4,0,800);
  *plVar4 = 0;
  uVar1 = portSyncSpinlockSize;
  plVar4[1] = 0;
  lVar5 = portMemAllocNonPaged(uVar1);
  *plVar4 = lVar5;
  if (lVar5 != 0) {
    iVar3 = portSyncSpinlockInitialize(lVar5);
    if (iVar3 != 0) {
      portMemFree(*plVar4);
      *plVar4 = 0;
      goto LAB_003cb9ce;
    }
    lVar5 = portMemAllocNonPaged(portSyncMutexSize);
    plVar4[1] = lVar5;
    if (lVar5 != 0) {
      iVar3 = portSyncMutexInitialize(lVar5);
      if (iVar3 != 0) {
        portMemFree(plVar4[1]);
        plVar4[1] = 0;
        goto LAB_003cb9ce;
      }
      lVar5 = portMemAllocNonPaged(portSyncMutexSize);
      plVar4[3] = lVar5;
      if (lVar5 != 0) {
        iVar3 = portSyncMutexInitialize(lVar5);
        if (iVar3 != 0) {
          portMemFree(plVar4[3]);
          plVar4[3] = 0;
          goto LAB_003cb9ce;
        }
        lVar5 = portMemAllocNonPaged(portSyncRwLockSize);
        plVar4[2] = lVar5;
        if ((lVar5 != 0) && (lVar5 = portMemAllocNonPaged(0xa0), lVar5 != 0)) {
          iVar3 = portSyncRwLockInitialize(plVar4[2]);
          if (iVar3 == 0) {
            *(code **)(lVar5 + 8) = pmaRegmapInit;
            *(code **)(lVar5 + 0x10) = pmaRegmapDestroy;
            *(code **)(lVar5 + 0x18) = pmaRegmapChangeStateAttrib;
            *(code **)(lVar5 + 0x20) = pmaRegmapChangePageStateAttrib;
            *(code **)(lVar5 + 0x28) = pmaRegmapChangeBlockStateAttrib;
            *(code **)(lVar5 + 0x30) = pmaRegmapChangeLocalizationState;
            *(code **)(lVar5 + 0x38) = pmaRegmapChangeBlockLocalizationState;
            *(code **)(lVar5 + 0x40) = pmaRegmapRead;
            *(code **)(lVar5 + 0x48) = pmaRegmapReadLocalizationInfo;
            *(code **)(lVar5 + 0x50) = pmaRegmapReadLocalizationStatus;
            *(code **)(lVar5 + 0x58) = pmaRegmapGetLocalizedRegionAllocationCount;
            *(code **)(lVar5 + 0x60) = pmaRegmapScanContiguous;
            *(code **)(lVar5 + 0x68) = pmaRegmapScanDiscontiguous;
            *(code **)(lVar5 + 0x70) = pmaRegmapGetSize;
            *(code **)(lVar5 + 0x78) = pmaRegmapGetLocalizableSize;
            *(code **)(lVar5 + 0x80) = pmaRegmapGetLargestFree;
            *(code **)(lVar5 + 0x88) = pmaRegMapScanContiguousNumaEviction;
            *(code **)(lVar5 + 0x90) = pmaRegmapGetEvictingFrames;
            *(code **)(lVar5 + 0x98) = pmaRegmapSetEvictingFrames;
            uVar6 = (uint)param_2;
            if (uVar6 != 1) {
              *(byte *)(plVar4 + 0x4b) = (byte)(param_2 >> 4) & 1;
              if ((param_2 & 2) != 0) {
                LOCK();
                plVar4[0x5a] = 0;
                UNLOCK();
              }
              *(char *)(plVar4 + 0x59) = (char)((uVar6 & 2) >> 1);
              if ((param_2 & 4) != 0) {
                *(undefined1 *)((long)plVar4 + 0x2e1) = 0;
              }
              *(char *)(plVar4 + 0x5c) = (char)((uVar6 & 4) >> 2);
              *(byte *)((long)plVar4 + 0x2fc) = (byte)(param_2 >> 6) & 1;
            }
            plVar4[0x46] = lVar5;
            plVar4[0x4d] = 0;
            plVar4[0x4c] = 0;
            plVar4[0x4e] = 0;
            plVar4[0x50] = 0;
            plVar4[0x4f] = 0;
            plVar4[0x51] = 0;
            plVar4[0x52] = 0;
            plVar4[0x54] = 0;
            plVar4[0x56] = 0;
            plVar4[0x53] = 0;
            plVar4[0x55] = 0;
            plVar4[0x57] = 0;
            *(undefined4 *)(plVar4 + 4) = 0;
            LOCK();
            plVar4[0x58] = 0;
            UNLOCK();
            plVar4[99] = 0;
            plVar4[0x62] = (long)_pmaDefaultStatsCallback;
            cVar2 = pmaStateCheck(plVar4);
            if (cVar2 == '\0') {
              nvAssertFailedNoLog("pmaStateCheck(pPma)",
                                  "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",
                                  0x10a);
              return 0;
            }
            return 0;
          }
          portMemFree(plVar4[2]);
          plVar4[2] = 0;
          goto LAB_003cb9ce;
        }
      }
    }
  }
  iVar3 = 0x51;
LAB_003cb9ce:
  if (*param_1 == 0) {
    return iVar3;
  }
  pmaDestroy_part_0();
  return iVar3;
}


// ===== 003cba90 pmaRegisterUpdateStatsCb =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void pmaRegisterUpdateStatsCb(long param_1,code *param_2,undefined8 param_3)

{
  *(code **)(param_1 + 0x310) = param_2;
  *(undefined8 *)(param_1 + 0x318) = param_3;
  if (param_2 != (code *)0x0) {
    (*param_2)(param_3,*(undefined8 *)(param_1 + 0x268));
    return;
  }
  return;
}


// ===== 003cbad0 pmaRegisterEvictionCb =====

undefined4 pmaRegisterEvictionCb(undefined8 *param_1,long param_2,long param_3,undefined8 param_4)

{
  undefined4 uVar1;
  
  if ((param_2 != 0 && param_3 != 0) && (param_1 != (undefined8 *)0x0)) {
    portSyncMutexAcquire(param_1[1]);
    portSyncSpinlockAcquire(*param_1);
    uVar1 = 0x40;
    if (param_1[0x48] == 0) {
      param_1[0x48] = param_2;
      uVar1 = 0;
      param_1[0x49] = param_3;
      param_1[0x47] = param_4;
    }
    portSyncSpinlockRelease(*param_1);
    portSyncMutexRelease(param_1[1]);
    return uVar1;
  }
  return 0x1f;
}


// ===== 003cbb80 pmaUnregisterEvictionCb =====

void pmaUnregisterEvictionCb(undefined8 *param_1)

{
  char cVar1;
  
  if (param_1 != (undefined8 *)0x0) {
    portSyncMutexAcquire(param_1[1]);
    portSyncSpinlockAcquire(*param_1);
    param_1[0x48] = 0;
    param_1[0x49] = 0;
    param_1[0x47] = 0;
    while( true ) {
      cVar1 = pmaIsEvictionPending(param_1);
      portSyncSpinlockRelease(*param_1);
      if (cVar1 == '\0') break;
      pmaOsSchedule();
      portSyncSpinlockAcquire(*param_1);
    }
    portSyncMutexRelease(param_1[1]);
    return;
  }
  return;
}


// ===== 003cbc10 pmaGetFreeMemory =====

void pmaGetFreeMemory(undefined8 *param_1,long *param_2)

{
  char cVar1;
  undefined1 local_30 [16];
  
  portSyncSpinlockAcquire(*param_1);
  cVar1 = *(char *)((long)param_1 + 0x2e1);
  portSyncSpinlockRelease(*param_1);
  if (cVar1 == '\0') {
    portSyncSpinlockAcquire(*param_1);
    *param_2 = param_1[0x4d] << 0x10;
    portSyncSpinlockRelease(*param_1);
    return;
  }
  osGetNumaMemoryUsage(*(undefined4 *)((long)param_1 + 0x2e4),param_2,local_30);
  return;
}


// ===== 003cbc90 pmaGetUgpuFreeMemory =====

void pmaGetUgpuFreeMemory(undefined8 *param_1,uint param_2,long *param_3)

{
  char cVar1;
  
  if (1 < param_2) {
    *param_3 = 0;
    return;
  }
  portSyncSpinlockAcquire(*param_1);
  cVar1 = *(char *)((long)param_1 + 0x2e1);
  portSyncSpinlockRelease(*param_1);
  if (cVar1 == '\0') {
    portSyncSpinlockAcquire(*param_1);
    *param_3 = param_1[(ulong)param_2 + 0x54] << 0x10;
    portSyncSpinlockRelease(*param_1);
    return;
  }
  nvAssertFailedNoLog("!nodeOnlined",
                      "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x6fe);
  return;
}


// ===== 003cbd40 pmaGetTotalMemory =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void pmaGetTotalMemory(undefined8 *param_1,long *param_2)

{
  char cVar1;
  long lVar2;
  long lVar3;
  long local_30 [2];
  
  *param_2 = 0;
  portSyncSpinlockAcquire(*param_1);
  cVar1 = *(char *)((long)param_1 + 0x2e1);
  portSyncSpinlockRelease(*param_1);
  if (cVar1 != '\0') {
    osGetNumaMemoryUsage(*(undefined4 *)((long)param_1 + 0x2e4),local_30,param_2);
    return;
  }
  lVar3 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    do {
      lVar2 = lVar3 + 5;
      lVar3 = lVar3 + 1;
      (**(code **)(param_1[0x46] + 0x70))(param_1[lVar2],local_30);
      *param_2 = *param_2 + local_30[0];
    } while ((uint)lVar3 < *(uint *)(param_1 + 4));
  }
  return;
}


// ===== 003cbdf0 pmaGetUgpuTotalMemory =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void pmaGetUgpuTotalMemory(undefined8 *param_1,uint param_2,long *param_3)

{
  char cVar1;
  long lVar2;
  long lVar3;
  long local_30;
  
  *param_3 = 0;
  if (1 < param_2) {
    return;
  }
  portSyncSpinlockAcquire(*param_1);
  cVar1 = *(char *)((long)param_1 + 0x2e1);
  portSyncSpinlockRelease(*param_1);
  if (cVar1 != '\0') {
    nvAssertFailedNoLog("!nodeOnlined",
                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x74a);
    return;
  }
  lVar3 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    do {
      lVar2 = lVar3 + 5;
      lVar3 = lVar3 + 1;
      (**(code **)(param_1[0x46] + 0x78))(param_1[lVar2],param_2,&local_30);
      *param_3 = *param_3 + local_30;
    } while ((uint)lVar3 < *(uint *)(param_1 + 4));
  }
  return;
}


// ===== 003cbec0 pmaGetClientAddrSpaceSize =====

void pmaGetClientAddrSpaceSize(long param_1,long *param_2)

{
  ulong uVar1;
  ulong uVar2;
  long lVar3;
  
  if (*(uint *)(param_1 + 0x20) == 0) {
    lVar3 = 1;
  }
  else {
    lVar3 = param_1 + (ulong)*(uint *)(param_1 + 0x20) * 8;
    uVar2 = 0;
    do {
      uVar1 = *(ulong *)(*(long *)(param_1 + 0x130) + 8);
      if (uVar2 < uVar1) {
        uVar2 = uVar1;
      }
      param_1 = param_1 + 8;
    } while (param_1 != lVar3);
    lVar3 = uVar2 + 1;
    if ((uVar2 & 0xfff) != 0) {
      *param_2 = lVar3;
      return;
    }
  }
  nvAssertFailedNoLog("(highestAddr & RM_PAGE_MASK) != 0",
                      "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x766);
  *param_2 = lVar3;
  return;
}


// ===== 003cbf50 pmaGetRegionInfo =====

undefined8 pmaGetRegionInfo(long param_1,undefined4 *param_2,undefined8 *param_3)

{
  if ((param_2 != (undefined4 *)0x0 && param_3 != (undefined8 *)0x0) && (param_1 != 0)) {
    *param_2 = *(undefined4 *)(param_1 + 0x20);
    *param_3 = *(undefined8 *)(param_1 + 0x130);
    return 0;
  }
  return 0x1f;
}


// ===== 003cbf90 pmaGetStats =====

long pmaGetStats(long param_1)

{
  long lVar1;
  
  lVar1 = param_1 + 0x260;
  if (param_1 == 0) {
    lVar1 = 0;
  }
  return lVar1;
}


// ===== 003cbfb0 pmaGetLargestFree =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void pmaGetLargestFree(undefined8 *param_1,ulong *param_2,undefined8 *param_3,undefined8 *param_4)

{
  long lVar1;
  ulong local_40 [2];
  
  *param_2 = 0;
  *param_3 = 0;
  portSyncSpinlockAcquire(*param_1);
  if (*(int *)(param_1 + 4) != 0) {
    lVar1 = 0;
    do {
      (**(code **)(param_1[0x46] + 0x80))(param_1[lVar1 + 5],local_40,param_4);
      if (*param_2 < local_40[0]) {
        *param_2 = local_40[0];
        *param_3 = *(undefined8 *)param_1[lVar1 + 0x26];
      }
      lVar1 = lVar1 + 1;
    } while ((uint)lVar1 < *(uint *)(param_1 + 4));
  }
  portSyncSpinlockRelease(*param_1);
  nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x7a7,
               "pmaGetLargestFree",1,
               "NVRM: PMA Handle = 0x%p, Largest Free Bytes = 0x%llx, base = 0x%llx, largestOffset = 0x%llx\n"
               ,param_1,*param_2,*param_3,*param_4);
  return;
}


// ===== 003cc0b0 pmaBuildPersistentList =====

void pmaBuildPersistentList(undefined8 param_1,undefined8 param_2)

{
  pmaBuildList(param_1,param_2,0x10);
  return;
}


// ===== 003cc0c0 pmaBuildAllocatedBlocksList =====

void pmaBuildAllocatedBlocksList(undefined8 param_1,undefined8 param_2)

{
  pmaBuildList(param_1,param_2,3);
  return;
}


// ===== 003cc0d0 pmaFreePersistentList =====

void pmaFreePersistentList(void)

{
  pmaFreeList();
  return;
}


// ===== 003cc0e0 pmaFreeAllocatedBlocksList =====

void pmaFreeAllocatedBlocksList(void)

{
  pmaFreeList();
  return;
}


// ===== 003cc100 pmaGetClientBlacklistedPages =====

void pmaGetClientBlacklistedPages(long param_1,long param_2,undefined8 *param_3,uint *param_4)

{
  undefined8 *puVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  char local_45;
  uint local_44;
  undefined8 *local_40 [2];
  
  local_44 = 0;
  local_45 = '\0';
  if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == (undefined8 *)0x0)) ||
     (param_4 == (uint *)0x0)) {
    nvAssertFailedNoLog("(pPma != NULL) && (pChunks != NULL) && (pPageSize != NULL) && (pNumChunks != NULL)"
                        ,"src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x81b);
    return;
  }
  uVar4 = 0;
  if (*(int *)(param_1 + 0x20) != 0) {
    uVar4 = 0;
    uVar3 = 0;
    do {
      while( true ) {
        pmaQueryBlacklistInfo(param_1,&local_44,&local_45,local_40);
        if ((local_44 == 0) || (local_45 == '\0')) break;
        puVar1 = local_40[0];
        do {
          if (*(char *)((long)puVar1 + 9) == '\0') {
            uVar2 = (ulong)uVar4;
            uVar4 = uVar4 + 1;
            *(undefined8 *)(param_2 + uVar2 * 8) = *puVar1;
          }
          puVar1 = puVar1 + 2;
        } while (local_40[0] + (ulong)local_44 * 2 != puVar1);
        uVar3 = uVar3 + 1;
        if (*(uint *)(param_1 + 0x20) <= uVar3) goto LAB_003cc1f4;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_1 + 0x20));
  }
LAB_003cc1f4:
  *param_3 = 0x10000;
  *param_4 = uVar4;
  return;
}


// ===== 003cc240 pmaGetBlacklistSize =====

void pmaGetBlacklistSize(long param_1,int *param_2,int *param_3)

{
  long lVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint local_44;
  long local_40 [2];
  
  local_44 = 0;
  if (*(int *)(param_1 + 0x20) == 0) {
    iVar4 = 0;
    iVar3 = 0;
  }
  else {
    iVar4 = 0;
    iVar3 = 0;
    uVar5 = 0;
    do {
      pmaQueryBlacklistInfo(param_1,&local_44,0,local_40);
      if (local_44 != 0) {
        lVar2 = (ulong)local_44 * 0x10 + local_40[0];
        lVar1 = local_40[0];
        do {
          while (*(char *)(lVar1 + 8) != '\0') {
            lVar1 = lVar1 + 0x10;
            iVar3 = iVar3 + 1;
            if (lVar2 == lVar1) goto LAB_003cc2e0;
          }
          lVar1 = lVar1 + 0x10;
          iVar4 = iVar4 + 1;
        } while (lVar2 != lVar1);
      }
LAB_003cc2e0:
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 0x20));
  }
  if (param_2 != (int *)0x0) {
    *param_2 = iVar3 << 0x10;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = iVar4 << 0x10;
  }
  return;
}


// ===== 003cc330 pmaClearScrubbedPages =====

void pmaClearScrubbedPages(void)

{
  _pmaClearScrubBit();
  return;
}


// ===== 003cc340 pmaAddToBlacklistTracking =====

undefined8 pmaAddToBlacklistTracking(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 local_28;
  undefined8 local_20;
  
  local_28 = 0;
  local_20 = 0;
  cVar1 = pmaIsBlacklistingAddrUnique();
  if (cVar1 == '\0') {
    return 0;
  }
  local_20 = CONCAT71(local_20._1_7_,1);
  local_28 = param_2;
  uVar2 = pmaRegisterBlacklistInfo(param_1,0,&local_28,1);
  return uVar2;
}


// ===== 003cc3b0 pmaGetTotalProtectedMemory =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void pmaGetTotalProtectedMemory(long param_1,long *param_2)

{
  long lVar1;
  long local_30 [2];
  
  *param_2 = 0;
  if (*(int *)(param_1 + 0x20) != 0) {
    lVar1 = 0;
    do {
      if (*(char *)(*(long *)(param_1 + 0x130 + lVar1 * 8) + 0x16) != '\0') {
        (**(code **)(*(long *)(param_1 + 0x230) + 0x70))
                  (*(undefined8 *)(param_1 + 0x28 + lVar1 * 8),local_30);
        *param_2 = *param_2 + local_30[0];
      }
      lVar1 = lVar1 + 1;
    } while ((uint)lVar1 < *(uint *)(param_1 + 0x20));
    return;
  }
  return;
}


// ===== 003cc440 pmaGetTotalUnprotectedMemory =====

void pmaGetTotalUnprotectedMemory(undefined8 param_1,long *param_2)

{
  ulong local_28;
  ulong local_20 [2];
  
  *param_2 = 0;
  local_28 = 0;
  local_20[0] = 0;
  pmaGetTotalMemory(param_1,local_20);
  pmaGetTotalProtectedMemory(param_1,&local_28);
  if (local_28 <= local_20[0]) {
    *param_2 = local_20[0] - local_28;
    return;
  }
  nvAssertFailedNoLog("totalBytesOverall >= totalBytesInProtectedRegion",
                      "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator.c",0x8aa);
  return;
}


// ===== 003cc4c0 pmaGetFreeProtectedMemory =====

void pmaGetFreeProtectedMemory(undefined8 *param_1,long *param_2)

{
  portSyncSpinlockAcquire(*param_1);
  *param_2 = param_1[0x50] << 0x10;
  portSyncSpinlockRelease(*param_1);
  return;
}


// ===== 003cc500 findRegionID =====

ulong findRegionID(long param_1,ulong param_2)

{
  ulong *puVar1;
  ulong uVar2;
  
  if (*(uint *)(param_1 + 0x20) != 0) {
    uVar2 = 0;
    do {
      puVar1 = *(ulong **)(param_1 + 0x130 + uVar2 * 8);
      if ((*puVar1 <= param_2) && (param_2 <= puVar1[1])) {
        return uVar2;
      }
      uVar2 = uVar2 + 1;
    } while (*(uint *)(param_1 + 0x20) != uVar2);
  }
  nvAssertFailedNoLog(&DAT_00d54f44,
                      "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x4e);
  return 0;
}


// ===== 003cc560 pmaPrintBlockStatus =====

void pmaPrintBlockStatus(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 3;
  if (uVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x58,
                 "pmaPrintBlockStatus",1,"STATE_FREE         ");
  }
  else if (uVar1 == 1) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x5b,
                 "pmaPrintBlockStatus",1,"STATE_UNPIN  ");
  }
  else if (uVar1 == 2) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x5e,
                 "pmaPrintBlockStatus",1,"STATE_PIN    ");
  }
  else {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x61,
                 "pmaPrintBlockStatus",1,"UNKNOWN STATE");
  }
  if ((param_1 & 0x10) == 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x68,
                 "pmaPrintBlockStatus",1,"             ");
  }
  else {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x65,
                 "pmaPrintBlockStatus",1," | ATTRIB_PERSISTENT");
  }
  if ((param_1 & 8) == 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x6f,
                 "pmaPrintBlockStatus",1,"             ");
  }
  else {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x6c,
                 "pmaPrintBlockStatus",1," | ATTRIB_SCRUBBING ");
  }
  if ((param_1 & 4) == 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x76,
                 "pmaPrintBlockStatus",1,"             ");
  }
  else {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x73,
                 "pmaPrintBlockStatus",1," | ATTRIB_EVICTING  ");
  }
  if ((param_1 & 0x40) == 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x7d,
                 "pmaPrintBlockStatus",1,"             ");
  }
  else {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x7a,
                 "pmaPrintBlockStatus",1," | ATTRIB_BLACKLIST ");
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x80,
               "pmaPrintBlockStatus",1,&DAT_00d54fe6);
  return;
}


// ===== 003cc7e0 pmaRegionPrint =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void pmaRegionPrint(long param_1,long *param_2,long param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  uint uVar5;
  ulong uVar6;
  ulong local_40;
  
  if (param_2 == (long *)0x0) {
    nvAssertFailedNoLog("pRegion != NULL",
                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x8a);
  }
  if (param_3 == 0) {
    nvAssertFailedNoLog("pMap != NULL",
                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x8b);
  }
  uVar4 = (ulong)((param_2[1] + 1) - *param_2) >> 0x10;
  nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x93,
               "pmaRegionPrint",1,"NVRM: Region: 0x%llx..0x%llx\n",*param_2,param_2[1]);
  nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x94,
               "pmaRegionPrint",1,"NVRM: Total frames: 0x%llx\n",uVar4);
  if (uVar4 == 0) {
    local_40 = 0;
    iVar3 = -1;
    iVar1 = 0;
  }
  else {
    iVar3 = 0;
    uVar6 = 0;
    local_40 = 0;
    iVar2 = 0;
    while( true ) {
      iVar1 = (**(code **)(*(long *)(param_1 + 0x230) + 0x40))(param_3,uVar6,1);
      if (iVar3 == 0) {
        local_40 = 0;
        uVar5 = 1;
      }
      else {
        if (iVar1 != iVar2) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0xa1,
                       "pmaRegionPrint",1,"NVRM: %8llx..%8x: ",local_40,iVar3 + -1);
          pmaPrintBlockStatus(iVar2);
          local_40 = uVar6;
        }
        uVar5 = iVar3 + 1;
      }
      uVar6 = (ulong)uVar5;
      if (uVar4 <= uVar6) break;
      iVar3 = iVar3 + 1;
      iVar2 = iVar1;
    }
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0xa8,
               "pmaRegionPrint",1,"NVRM: %8llx..%8x: ",local_40,iVar3);
  pmaPrintBlockStatus(iVar1);
  return;
}


// ===== 003cc9f0 pmaStateCheck =====

undefined8 pmaStateCheck(long param_1)

{
  long lVar1;
  uint uVar2;
  
  if (param_1 != 0) {
    uVar2 = *(uint *)(param_1 + 0x20);
    if (uVar2 < 0x20) {
      if (*(char *)(param_1 + 0x2e0) != '\0') {
        if (*(char *)(param_1 + 0x2e1) == '\0') {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0xbc,
                       "pmaStateCheck",1,"NVRM: Warning: NUMA state not onlined.\n");
        }
        else {
          if (*(int *)(param_1 + 0x2e4) == -1) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0xc1,
                         "pmaStateCheck",1,"NVRM: NUMA node ID invalid.\n");
            return 0;
          }
          if (uVar2 != 0) {
            lVar1 = param_1 + (ulong)uVar2 * 8;
            do {
              if (*(long *)(param_1 + 0x28) == 0) {
                return 0;
              }
              if (*(long *)(param_1 + 0x130) == 0) {
                return 0;
              }
              param_1 = param_1 + 8;
            } while (lVar1 != param_1);
          }
        }
        return 1;
      }
      if (uVar2 != 0) {
        lVar1 = param_1 + (ulong)uVar2 * 8;
        do {
          if (*(long *)(param_1 + 0x28) == 0) {
            return 0;
          }
          if (*(long *)(param_1 + 0x130) == 0) {
            return 0;
          }
          param_1 = param_1 + 8;
        } while (lVar1 != param_1);
      }
      return 1;
    }
  }
  return 0;
}


// ===== 003ccae0 pmaCheckRangeAgainstRegionDesc =====

long pmaCheckRangeAgainstRegionDesc(long param_1,ulong param_2,long param_3)

{
  long lVar1;
  ulong *puVar2;
  
  if (*(uint *)(param_1 + 0x20) != 0) {
    lVar1 = param_1;
    do {
      puVar2 = *(ulong **)(lVar1 + 0x130);
      if ((*puVar2 <= param_2) && (param_2 <= puVar2[1])) goto LAB_003ccb3b;
      lVar1 = lVar1 + 8;
    } while (param_1 + (ulong)*(uint *)(param_1 + 0x20) * 8 != lVar1);
  }
  nvAssertFailedNoLog(&DAT_00d54f44,
                      "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x4e);
  lVar1 = 0x40;
  puVar2 = *(ulong **)(param_1 + 0x130);
  if (*puVar2 <= param_2) {
LAB_003ccb3b:
    lVar1 = (ulong)(puVar2[1] < (param_2 - 1) + param_3) << 6;
  }
  return lVar1;
}


// ===== 003ccba0 pmaSetBlockStateAttribUnderPmaLock =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void pmaSetBlockStateAttribUnderPmaLock
               (long param_1,ulong param_2,ulong param_3,undefined4 param_4,undefined4 param_5)

{
  ulong *puVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pPma != NULL",
                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0xf4);
  }
  if ((short)param_2 != 0) {
    nvAssertFailedNoLog("NV_IS_ALIGNED(base, PMA_GRANULARITY)",
                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0xf5);
  }
  if ((short)param_3 != 0) {
    nvAssertFailedNoLog("NV_IS_ALIGNED(size, PMA_GRANULARITY)",
                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0xf6);
  }
  if (*(uint *)(param_1 + 0x20) != 0) {
    uVar4 = 0;
    do {
      puVar1 = *(ulong **)(param_1 + 0x130 + uVar4 * 8);
      if ((*puVar1 <= param_2) && (param_2 <= puVar1[1])) goto LAB_003ccc1c;
      uVar4 = uVar4 + 1;
    } while (*(uint *)(param_1 + 0x20) != uVar4);
  }
  nvAssertFailedNoLog(&DAT_00d54f44,
                      "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x4e);
  uVar4 = 0;
LAB_003ccc1c:
  plVar2 = *(long **)(param_1 + 0x130 + (uVar4 & 0xffffffff) * 8);
  if ((param_2 - 1) + param_3 <= (ulong)plVar2[1]) {
    if (param_3 >> 0x10 != 0) {
      uVar3 = *(undefined8 *)(param_1 + 0x28 + (uVar4 & 0xffffffff) * 8);
      uVar5 = param_2 - *plVar2 >> 0x10;
      uVar4 = uVar5;
      do {
        uVar6 = uVar4 + 1;
        (**(code **)(*(long *)(param_1 + 0x230) + 0x18))(uVar3,uVar4,param_4,param_5);
        uVar4 = uVar6;
      } while ((param_3 >> 0x10) + uVar5 != uVar6);
    }
    return;
  }
  nvAssertFailedNoLog("(base + size - 1) <= pPma->pRegDescriptors[regId]->limit",
                      "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0xff);
  return;
}


// ===== 003ccd60 pmaSetBlockStateAttrib =====

void pmaSetBlockStateAttrib
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5)

{
  if (param_1 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("pPma != NULL",
                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x111)
    ;
  }
  portSyncSpinlockAcquire(*param_1);
  pmaSetBlockStateAttribUnderPmaLock(param_1,param_2,param_3,param_4,param_5);
  portSyncSpinlockRelease(*param_1);
  return;
}


// ===== 003ccdf0 pmaIsEvictionPending =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 pmaIsEvictionPending(long param_1)

{
  long lVar1;
  long lVar2;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    return 0;
  }
  lVar2 = 0;
  do {
    lVar1 = (**(code **)(*(long *)(param_1 + 0x230) + 0x90))
                      (*(undefined8 *)(param_1 + 0x28 + lVar2 * 8));
    if (lVar1 != 0) {
      return 1;
    }
    lVar2 = lVar2 + 1;
  } while ((uint)lVar2 < *(uint *)(param_1 + 0x20));
  return 0;
}


// ===== 003cce60 pmaOsSchedule =====

void pmaOsSchedule(void)

{
  osSchedule();
  return;
}


// ===== 003cce80 pmaSelector =====

byte pmaSelector(long param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  ulong *puVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  ulong uVar7;
  ulong uVar8;
  uint *puVar9;
  uint *puVar10;
  
  uVar1 = *param_2;
  if (param_3 == (uint *)0x0) {
    nvAssertFailedNoLog("regionList != NULL",
                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x29e)
    ;
  }
  if (*(int *)(param_1 + 0x20) == 0) {
    return 0x51;
  }
  uVar5 = 0;
  uVar4 = 0;
  do {
    while( true ) {
      if ((uVar1 & 0x10) != 0) {
        while (param_2[6] != uVar4) {
          uVar2 = *(uint *)(param_1 + 0x20);
          uVar4 = uVar4 + 1;
          if (uVar2 <= uVar4) goto LAB_003ccfc9;
        }
      }
      uVar7 = (ulong)uVar4;
      puVar3 = *(ulong **)(param_1 + 0x130 + uVar7 * 8);
      if ((((uVar1 >> 8 & 1) == (uint)*(byte *)((long)puVar3 + 0x16)) &&
          (((uVar1 & 8) == 0 ||
           ((*puVar3 <= *(ulong *)(param_2 + 4) && (*(ulong *)(param_2 + 2) <= puVar3[1])))))) &&
         (((uVar1 & 4) == 0 || (param_2[1] <= (uint)puVar3[2])))) break;
LAB_003ccfbb:
      uVar2 = *(uint *)(param_1 + 0x20);
      uVar4 = uVar4 + 1;
      if (uVar2 <= uVar4) goto LAB_003ccfc9;
    }
    if (uVar5 != 0) {
      uVar8 = (ulong)uVar5;
      puVar6 = param_3 + uVar8;
      if ((uVar1 & 0x2000) == 0) {
        if ((uVar1 & 0x20) == 0) {
          puVar10 = puVar6 + -(ulong)(uVar5 - 1);
          for (; (puVar9 = puVar6,
                 *(uint *)(*(long *)(param_1 + 0x130 + (long)(int)puVar6[(uVar5 - 1) - uVar8] * 8) +
                          0x10) < (uint)puVar3[2] &&
                 (*puVar6 = puVar6[(uVar5 - 1) - uVar8], puVar9 = param_3, puVar10 != puVar6));
              puVar6 = puVar6 + -1) {
            puVar3 = *(ulong **)(param_1 + (uVar7 + 0x26) * 8);
          }
        }
        else {
          puVar10 = puVar6 + -(ulong)(uVar5 - 1);
          for (; (puVar9 = puVar6,
                 (uint)puVar3[2] <
                 *(uint *)(*(long *)(param_1 + 0x130 + (long)(int)puVar6[(uVar5 - 1) - uVar8] * 8) +
                          0x10) &&
                 (*puVar6 = puVar6[(uVar5 - 1) - uVar8], puVar9 = param_3, puVar10 != puVar6));
              puVar6 = puVar6 + -1) {
            puVar3 = *(ulong **)(param_1 + (uVar7 + 0x26) * 8);
          }
        }
      }
      else {
        puVar10 = puVar6 + -(ulong)(uVar5 - 1);
        for (; (puVar9 = puVar6,
               *(ulong *)(*(long *)(param_1 + 0x130 + (long)(int)puVar6[(uVar5 - 1) - uVar8] * 8) +
                         8) < puVar3[1] &&
               (*puVar6 = puVar6[(uVar5 - 1) - uVar8], puVar9 = param_3, puVar10 != puVar6));
            puVar6 = puVar6 + -1) {
          puVar3 = *(ulong **)(param_1 + (uVar7 + 0x26) * 8);
        }
      }
      *puVar9 = uVar4;
      uVar5 = uVar5 + 1;
      goto LAB_003ccfbb;
    }
    *param_3 = uVar4;
    uVar2 = *(uint *)(param_1 + 0x20);
    uVar4 = uVar4 + 1;
    uVar5 = 1;
  } while (uVar4 < uVar2);
LAB_003ccfc9:
  uVar1 = uVar5;
  if (uVar5 < uVar2) {
    do {
      uVar4 = uVar1 + 1;
      param_3[uVar1] = 0xffffffff;
      uVar1 = uVar4;
    } while (uVar4 < *(uint *)(param_1 + 0x20));
  }
  return -(uVar5 == 0) & 0x51;
}


// ===== 003cd180 _pmaClearScrubBit =====

void _pmaClearScrubBit(undefined8 *param_1,long param_2,ulong param_3)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  if (param_3 != 0) {
    uVar3 = 0;
    portSyncSpinlockAcquire(*param_1);
    do {
      lVar1 = *(long *)(param_2 + 0x10 + uVar3 * 0x18);
      uVar2 = *(undefined8 *)(param_2 + 8 + uVar3 * 0x18);
      if (lVar1 == 0) {
        nvAssertFailedNoLog("size > 0",
                            "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",
                            0x32a);
      }
      pmaSetBlockStateAttribUnderPmaLock(param_1,uVar2,lVar1,0,8);
      uVar3 = (ulong)((int)uVar3 + 1);
    } while (uVar3 < param_3);
    portSyncSpinlockRelease(*param_1);
    return;
  }
  nvAssertFailedNoLog("count > 0",
                      "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x323);
  portSyncSpinlockAcquire(*param_1);
  portSyncSpinlockRelease(*param_1);
  return;
}


