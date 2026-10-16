// ===== 0049d720 notifyDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void notifyDestruct_IMPL(long param_1)

{
  code *pcVar1;
  long lVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  lVar2 = (**(code **)(**(long **)(param_1 + 0x18) + 0x28))();
  if (lVar2 != 0) {
    *(undefined8 *)(lVar2 + 0x98) = 0;
    serverFreeShare(g_resServ,*(undefined8 *)(lVar2 + 0x88));
    return;
  }
  return;
}


// ===== 0049d770 notifyGetNotificationListPtr_IMPL =====

long notifyGetNotificationListPtr_IMPL(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x28);
  if (lVar1 != 0) {
    lVar1 = lVar1 + 0xa8;
  }
  return lVar1;
}


// ===== 0049d790 notifyGetNotificationShare_IMPL =====

undefined8 notifyGetNotificationShare_IMPL(long param_1)

{
  return *(undefined8 *)(param_1 + 0x28);
}


// ===== 0049d7a0 notifySetNotificationShare_IMPL =====

void notifySetNotificationShare_IMPL(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x28) = param_2;
  return;
}


// ===== 0049d7b0 shrnotifConstruct_IMPL =====

undefined8 shrnotifConstruct_IMPL(void)

{
  return 0;
}


// ===== 0049d7c0 shrnotifDestruct_IMPL =====

void shrnotifDestruct_IMPL(void)

{
  return;
}


// ===== 0049d7c5 updateLockStressCounters.cold =====

void updateLockStressCounters_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0049d7d0 updateLockStressCounters =====

undefined8 updateLockStressCounters(long param_1,byte param_2)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  
  if ((param_2 & 1) != 0) {
    cVar2 = rmapiLockIsWriteOwner();
    if (cVar2 == '\0') {
      nvAssertFailedNoLog("rmapiLockIsWriteOwner()","src/kernel/rmapi/lock_stress.c",0xc6);
      return 0x2f;
    }
    iVar4 = g_LockStressCounter + -1;
    g_LockStressCounter = g_LockStressCounter + 1;
    if ((param_2 & 0x10) == 0) {
      g_LockStressCounter = iVar4;
    }
  }
  if ((param_2 & 2) == 0) {
    if (param_1 == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
  }
  else {
    cVar2 = rmGpuLockIsOwner();
    if (cVar2 == '\0') {
      nvAssertFailedNoLog("rmGpuLockIsOwner()","src/kernel/rmapi/lock_stress.c",0xd2);
      return 0x2f;
    }
    lVar5 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
    iVar4 = *(int *)(lVar5 + 0x904);
    iVar3 = iVar4 + 1;
    if ((param_2 & 0x20) == 0) {
      iVar3 = iVar4 + -1;
    }
    *(int *)(lVar5 + 0x904) = iVar3;
  }
  lVar5 = **(long **)(*(long *)(param_1 + 0x110) + 0x48);
  cVar2 = serverIsClientInternal(g_resServ,*(undefined4 *)(lVar5 + 0x48));
  if ((cVar2 == '\0') &&
     (cVar2 = serverIsClientLocked(g_resServ,*(undefined4 *)(lVar5 + 0x48)), cVar2 == '\0')) {
    nvAssertFailedNoLog("serverIsClientLocked(&g_resServ, pClient->hClient)",
                        "src/kernel/rmapi/lock_stress.c",0xe7);
    return 0x2f;
  }
  lVar5 = __nvoc_dynamicCast(lVar5,__nvoc_class_def_RmClient);
  if (lVar5 == 0) {
    return 0x40;
  }
  iVar4 = *(int *)(lVar5 + 0x268) + -1;
  if ((param_2 & 0x40) != 0) {
    iVar4 = *(int *)(lVar5 + 0x268) + 1;
  }
  *(int *)(lVar5 + 0x268) = iVar4;
  if ((param_2 & 8) != 0) {
    cVar2 = rmGpuLockIsOwner();
    if (cVar2 == '\0') {
      nvAssertFailedNoLog("rmGpuLockIsOwner()","src/kernel/rmapi/lock_stress.c",0xf9);
      return 0x2f;
    }
    lVar5 = serverutilGetClientUnderLock
                      (*(undefined4 *)(*(long *)(*(long *)(param_1 + 0x128) + 0xe0) + 0x3b40));
    if (lVar5 == 0) {
      return 0x40;
    }
    iVar4 = *(int *)(lVar5 + 0x268) + 1;
    if (-1 < (char)param_2) {
      iVar4 = *(int *)(lVar5 + 0x268) + -1;
    }
    *(int *)(lVar5 + 0x268) = iVar4;
  }
  return 0;
}


// ===== 0049d9f9 updateLockStressCountersInternal.cold =====

void updateLockStressCountersInternal_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0049da10 updateLockStressCountersInternal =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong updateLockStressCountersInternal(long param_1,long param_2,undefined4 param_3,byte *param_4)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  byte local_19;
  
  if ((*param_4 & 4) != 0) {
    if (param_1 == 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    lVar1 = **(long **)(*(long *)(param_1 + 0x110) + 0x48);
    lVar5 = __nvoc_dynamicCast(lVar1,__nvoc_class_def_RmClient);
    cVar3 = serverIsClientInternal(g_resServ,*(undefined4 *)(lVar1 + 0x48));
    if ((cVar3 == '\0') &&
       (cVar3 = serverIsClientLocked(g_resServ,*(undefined4 *)(lVar1 + 0x48)), cVar3 == '\0')) {
      nvAssertFailedNoLog("serverIsClientLocked(&g_resServ, pClient->hClient)",
                          "src/kernel/rmapi/lock_stress.c",0x187);
      return 0x2f;
    }
    if (lVar5 == 0) {
      return 0x40;
    }
    iVar4 = *(int *)(lVar5 + 0x268) + 1;
    if ((*param_4 & 0x40) == 0) {
      iVar4 = *(int *)(lVar5 + 0x268) + -1;
    }
    *(int *)(lVar5 + 0x268) = iVar4;
  }
  uVar6 = (**(code **)(param_2 + 0x38))
                    (param_2,*(undefined4 *)(param_1 + 0x138),*(undefined4 *)(param_1 + 0x144),
                     param_3,&local_19,1);
  if ((int)uVar6 == 0) {
    *param_4 = *param_4 | local_19 & 0xbb;
  }
  else {
    nvCheckOkFailedNoLog
              (4,uVar6 & 0xffffffff,
               "pRmApi->Control(pRmApi, pResource->hInternalClient, pResource->hInternalLockStressObject, internalCmd, &internalParams, sizeof(internalParams))"
               ,"src/kernel/rmapi/lock_stress.c",0x193);
    uVar6 = uVar6 & 0xffffffff;
  }
  return uVar6;
}


// ===== 0049db90 _verifyGpuLockState =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int _verifyGpuLockState(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       int param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  long lVar7;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 uVar8;
  undefined1 local_89;
  int local_88;
  int local_84;
  int local_80 [2];
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_89 = 0;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_78 = 0;
  local_88 = 0;
  local_84 = 0;
  local_80[0] = 0;
  local_80[1] = 0;
  if (param_5 == 0) {
    lVar7 = rmapiGetInterface(3);
    portMemSet(&local_89,0,1);
    local_89 = 1;
    iVar3 = (**(code **)(lVar7 + 0x38))(lVar7,param_2,param_4,0x100010b,&local_89,1);
    iVar6 = 0;
    if (iVar3 != 0) {
LAB_0049df40:
      nvDbg_Printf("src/kernel/rmapi/lock_stress.c",0x28a,"_verifyGpuLockState",4,
                   "NVRM: No GPU lock control failed with: 0x%x\n",iVar3);
      goto LAB_0049df69;
    }
  }
  else {
    uVar1 = *(uint *)(*(long *)(g_pSys + 0x1e0) + 0x958);
    lVar7 = rmapiGetInterface(4);
    portMemSet(&local_89,0,1);
    local_89 = 1;
    iVar3 = (**(code **)(lVar7 + 0x38))(lVar7,param_2,param_4,0x100010b,&local_89,1);
    if (iVar3 != 0) goto LAB_0049df40;
    iVar6 = 0;
    if ((1 < uVar1) && (param_5 == 1)) {
      iVar6 = 0x2f;
    }
  }
  iVar2 = (**(code **)(lVar7 + 0x38))(lVar7,param_2,param_4,0x100010c,&local_89,1);
  if (iVar6 == iVar2) {
    iVar3 = (**(code **)(lVar7 + 0x38))(lVar7,param_2,param_4,0x100010d,&local_89,1);
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/rmapi/lock_stress.c",0x2bf,"_verifyGpuLockState",4,
                   "NVRM: Device lock control failed with: 0x%x\n",iVar3);
      goto LAB_0049df69;
    }
    uVar8 = extraout_RDX;
    if (*(char *)(param_1 + 0x908) == '\0') {
      portMemSet(&local_70,0,0x38);
      local_70 = CONCAT44(local_70._4_4_,*(undefined4 *)(param_1 + 0x7b4));
      iVar3 = serverutilGenResourceHandle(param_2,&local_88);
      if (iVar3 != 0) {
        nvAssertOkFailedNoLog
                  (iVar3,"serverutilGenResourceHandle(hClient, &hDevice)",
                   "src/kernel/rmapi/lock_stress.c",0x2cb);
        goto LAB_0049df69;
      }
      uVar8 = 0x38;
      iVar3 = (**(code **)(lVar7 + 8))(lVar7,param_2,param_2,local_88,0x80,&local_70);
      if (iVar3 != 0) {
        local_88 = 0;
      }
      if (iVar2 != iVar3) {
        nvDbg_Printf("src/kernel/rmapi/lock_stress.c",0x2e2,"_verifyGpuLockState",4,
                     "NVRM: Failed to allocate device with: 0x%x, expected: 0x%x\n",iVar3,iVar2);
        goto LAB_0049e0b4;
      }
    }
    iVar3 = serverutilGenResourceHandle(param_2,&local_84,uVar8);
    if (iVar3 != 0) {
      nvAssertOkFailedNoLog
                (iVar3,"serverutilGenResourceHandle(hClient, &hRusd)",
                 "src/kernel/rmapi/lock_stress.c",0x2ea);
      goto LAB_0049df69;
    }
    if (*(char *)(param_1 + 0x908) == '\0') {
      iVar3 = (**(code **)(lVar7 + 8))(lVar7,param_2,param_3,local_84,0xde,&local_78,8);
      uVar8 = extraout_RDX_00;
      if (iVar3 != 0) {
        local_84 = 0;
        uVar8 = 0;
        goto LAB_0049e082;
      }
    }
    else {
      uVar8 = 8;
      iVar3 = (**(code **)(lVar7 + 8))(lVar7,param_2,param_3,local_84,0xde,&local_78);
      if ((iVar3 == 0) || (local_84 = 0, iVar3 != 0x56)) {
        uVar8 = 0x56;
LAB_0049e082:
        nvDbg_Printf("src/kernel/rmapi/lock_stress.c",0x301,"_verifyGpuLockState",4,
                     "NVRM: Failed to allocate RUSD with: 0x%x, expected: 0x%x\n",iVar3,uVar8);
        goto LAB_0049e0b4;
      }
    }
    iVar3 = serverutilGenResourceHandle(param_2,local_80,uVar8);
    if (iVar3 != 0) {
      nvAssertOkFailedNoLog
                (iVar3,"serverutilGenResourceHandle(hClient, &hRelaxedDupObj)",
                 "src/kernel/rmapi/lock_stress.c",0x311);
      goto LAB_0049df69;
    }
    iVar6 = (**(code **)(lVar7 + 8))(lVar7,param_2,param_3,local_80[0],0x101,0,0);
    if (iVar6 != 0) {
      nvDbg_Printf("src/kernel/rmapi/lock_stress.c",0x317,"_verifyGpuLockState",4,
                   "NVRM: Failed to allocate relaxed dup object with: 0x%x\n",iVar6);
      local_80[0] = 0;
      iVar3 = iVar6;
      goto LAB_0049df69;
    }
    if (local_84 != 0) {
      iVar3 = (**(code **)(lVar7 + 0x18))(lVar7,param_2);
      if (iVar3 != 0) {
        nvDbg_Printf("src/kernel/rmapi/lock_stress.c",0x32c,"_verifyGpuLockState",4,
                     "NVRM: Failed to free subdevice with: 0x%x\n",iVar3);
        goto LAB_0049df69;
      }
      local_84 = 0;
    }
    if (local_88 != 0) {
      iVar3 = (**(code **)(lVar7 + 0x18))(lVar7,param_2);
      if (iVar3 != 0) {
        nvDbg_Printf("src/kernel/rmapi/lock_stress.c",0x33e,"_verifyGpuLockState",4,
                     "NVRM: Failed to free device with: 0x%x,\n",iVar3);
        goto LAB_0049df69;
      }
      local_88 = 0;
    }
    iVar3 = 0;
    if (local_80[0] == 0) goto LAB_0049df69;
    iVar4 = (**(code **)(lVar7 + 0x18))(lVar7,param_2,local_80[0]);
    if (iVar4 == 0) {
      local_80[0] = 0;
    }
    iVar3 = iVar6;
    if (iVar2 == iVar4) goto LAB_0049df69;
    nvDbg_Printf("src/kernel/rmapi/lock_stress.c",0x356,"_verifyGpuLockState",4,
                 "NVRM: Failed to free relaxed dup object with: 0x%x, expected: 0x%x\n",iVar4,iVar2)
    ;
  }
  else {
    nvDbg_Printf("src/kernel/rmapi/lock_stress.c",0x2a7,"_verifyGpuLockState",4,
                 "NVRM: All GPUs lock control failed with: 0x%x, expected: 0x%x\n",iVar2,iVar6);
  }
LAB_0049e0b4:
  iVar3 = 0x2f;
LAB_0049df69:
  uVar5 = rmGpuLocksGetOwnedMask();
  rmGpuGroupLockRelease(uVar5,0);
  lVar7 = rmapiGetInterface(3);
  if (local_88 != 0) {
    (**(code **)(lVar7 + 0x18))(lVar7,param_2);
    local_88 = 0;
  }
  if (local_84 != 0) {
    (**(code **)(lVar7 + 0x18))(lVar7,param_2);
    local_84 = 0;
  }
  if (local_80[0] != 0) {
    (**(code **)(lVar7 + 0x18))(lVar7,param_2);
    local_80[0] = 0;
  }
  if (param_5 == 1) {
    iVar6 = rmGpuGroupLockAcquire(*(undefined4 *)(param_1 + 0x7a4),1,0,0x200,local_80 + 1);
    if (iVar6 != 0) {
      nvDbg_Printf("src/kernel/rmapi/lock_stress.c",0x37b,"_verifyGpuLockState",4,
                   "NVRM: Failed to reset to device only GPU Lock");
    }
  }
  else if ((param_5 == 2) &&
          (iVar6 = rmGpuGroupLockAcquire(*(undefined4 *)(param_1 + 0x7a4),3,0,0x200,local_80 + 1),
          iVar6 != 0)) {
    nvDbg_Printf("src/kernel/rmapi/lock_stress.c",899,"_verifyGpuLockState",4,
                 "NVRM: Failed to reset to all GPUs Lock");
  }
  return iVar3;
}


// ===== 0049e31d lockStressObjConstruct_IMPL.cold =====

void lockStressObjConstruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0049e330 lockStressObjConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int lockStressObjConstruct_IMPL(long param_1)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  undefined8 *puVar7;
  char *pcVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined4 local_64;
  undefined8 local_60 [8];
  
  if (*(char *)(g_pSys + 0x7e) == '\0') {
    return 0x7e;
  }
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  cVar5 = serverIsClientInternal
                    (g_resServ,
                     *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x110) + 0x48) + 0x48));
  if (cVar5 != '\0') {
    return 0;
  }
  puVar7 = (undefined8 *)rmapiGetInterface(4);
  lVar3 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  *(undefined4 *)(param_1 + 0x138) = 0;
  uVar10 = 4;
  iVar6 = (*(code *)puVar7[1])(puVar7,0,0,0,0,param_1 + 0x138);
  uVar9 = 0x4f;
  pcVar8 = 
  "pRmApi->AllocWithHandle(pRmApi, NV01_NULL_OBJECT, NV01_NULL_OBJECT, NV01_NULL_OBJECT, NV01_ROOT, &pResource->hInternalClient, sizeof(pResource->hInternalClient))"
  ;
  if (iVar6 == 0) {
    portMemSet(local_60,0,0x38,"src/kernel/rmapi/lock_stress.c",0x4f,uVar10);
    uVar1 = *(undefined4 *)(param_1 + 0x138);
    local_60[0] = CONCAT44(uVar1,*(undefined4 *)(lVar3 + 0x7b4));
    iVar6 = (*(code *)*puVar7)(puVar7,uVar1,uVar1,param_1 + 0x13c,0x80,local_60,0x38);
    if (iVar6 == 0) {
      portMemSet(&local_64,0,4);
      local_64 = gpumgrGetSubDeviceInstanceFromGpu(lVar3);
      iVar6 = (*(code *)*puVar7)(puVar7,*(undefined4 *)(param_1 + 0x138),
                                 *(undefined4 *)(param_1 + 0x13c),param_1 + 0x140,0x2080,&local_64,4
                                );
      uVar9 = 0x6a;
      pcVar8 = 
      "pRmApi->Alloc(pRmApi, pResource->hInternalClient, pResource->hInternalDevice, &pResource->hInternalSubdevice, NV20_SUBDEVICE_0, &nv2080AllocParams, sizeof(nv2080AllocParams))"
      ;
      if (iVar6 == 0) {
        iVar6 = (*(code *)*puVar7)(puVar7,*(undefined4 *)(param_1 + 0x138),
                                   *(undefined4 *)(param_1 + 0x140),param_1 + 0x144,0x100,0,0);
        if (iVar6 == 0) {
          return 0;
        }
        nvCheckOkFailedNoLog
                  (4,iVar6,
                   "pRmApi->Alloc(pRmApi, pResource->hInternalClient, pResource->hInternalSubdevice, &pResource->hInternalLockStressObject, LOCK_STRESS_OBJECT, NULL, 0)"
                   ,"src/kernel/rmapi/lock_stress.c",0x75);
        goto LAB_0049e547;
      }
    }
    else {
      uVar9 = 0x5d;
      pcVar8 = 
      "pRmApi->Alloc(pRmApi, pResource->hInternalClient, pResource->hInternalClient, &pResource->hInternalDevice, NV01_DEVICE_0, &nv0080AllocParams, sizeof(nv0080AllocParams))"
      ;
    }
  }
  nvCheckOkFailedNoLog(4,iVar6,pcVar8,"src/kernel/rmapi/lock_stress.c",uVar9);
LAB_0049e547:
  iVar2 = *(int *)(param_1 + 0x138);
  if (iVar2 != 0) {
    (*(code *)puVar7[3])(puVar7,iVar2,iVar2);
    return iVar6;
  }
  return iVar6;
}


// ===== 0049e5a3 lockStressObjDestruct_IMPL.cold =====

void lockStressObjDestruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0049e5b0 lockStressObjDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void lockStressObjDestruct_IMPL(long param_1)

{
  code *pcVar1;
  char cVar2;
  long lVar3;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  cVar2 = serverIsClientInternal
                    (g_resServ,
                     *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x110) + 0x48) + 0x48));
  if (cVar2 != '\0') {
    return;
  }
  lVar3 = rmapiGetInterface(4);
  (**(code **)(lVar3 + 0x18))
            (lVar3,*(undefined4 *)(param_1 + 0x138),*(undefined4 *)(param_1 + 0x138),
             *(code **)(lVar3 + 0x18));
  return;
}


// ===== 0049e613 lockStressObjCtrlCmdResetLockStressState_IMPL.cold =====

void lockStressObjCtrlCmdResetLockStressState_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0049e620 lockStressObjCtrlCmdResetLockStressState_IMPL =====

undefined8 lockStressObjCtrlCmdResetLockStressState_IMPL(long param_1)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  long lVar4;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar3 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48),
                             __nvoc_class_def_RmClient);
  if (lVar3 != 0) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
    lVar4 = serverutilGetClientUnderLock(*(undefined4 *)(lVar1 + 0x3b40));
    if (lVar4 != 0) {
      *(undefined4 *)(lVar1 + 0x904) = 0;
      g_LockStressCounter = 0;
      *(undefined4 *)(lVar3 + 0x268) = 0;
      *(undefined4 *)(lVar4 + 0x268) = 0;
      return 0;
    }
  }
  return 0x40;
}


// ===== 0049e6c0 lockStressObjCtrlCmdPerformLockStressAllRmLocks_IMPL =====

void lockStressObjCtrlCmdPerformLockStressAllRmLocks_IMPL(undefined8 param_1,byte *param_2)

{
  int iVar1;
  byte local_19;
  
  iVar1 = osGetRandomBytes(&local_19,1);
  if (iVar1 == 0) {
    *param_2 = local_19 | 0xf;
    updateLockStressCounters(param_1,local_19 | 0xf);
  }
  return;
}


// ===== 0049e710 lockStressObjCtrlCmdPerformLockStressNoGpusLock_IMPL =====

void lockStressObjCtrlCmdPerformLockStressNoGpusLock_IMPL(undefined8 param_1,byte *param_2)

{
  int iVar1;
  byte bVar2;
  byte local_19;
  
  iVar1 = osGetRandomBytes(&local_19,1);
  if (iVar1 == 0) {
    bVar2 = local_19 & 0xf0 | 5;
    *param_2 = bVar2;
    updateLockStressCounters(param_1,bVar2);
  }
  return;
}


// ===== 0049e760 lockStressObjCtrlCmdPerformLockStressApiLockReadMode_IMPL =====

void lockStressObjCtrlCmdPerformLockStressApiLockReadMode_IMPL(undefined8 param_1,byte *param_2)

{
  int iVar1;
  byte bVar2;
  byte local_19;
  
  iVar1 = osGetRandomBytes(&local_19,1);
  if (iVar1 == 0) {
    bVar2 = local_19 & 0xf0 | 0xe;
    *param_2 = bVar2;
    updateLockStressCounters(param_1,bVar2);
  }
  return;
}


// ===== 0049e7b0 lockStressObjCtrlCmdPerformLockStressNoGpusLockApiLockReadMode_IMPL =====

void lockStressObjCtrlCmdPerformLockStressNoGpusLockApiLockReadMode_IMPL
               (undefined8 param_1,byte *param_2)

{
  int iVar1;
  byte bVar2;
  byte local_19;
  
  iVar1 = osGetRandomBytes(&local_19,1);
  if (iVar1 == 0) {
    bVar2 = local_19 & 0xf0 | 4;
    *param_2 = bVar2;
    updateLockStressCounters(param_1,bVar2);
  }
  return;
}


// ===== 0049e800 lockStressObjCtrlCmdPerformLockStressInternalAllRmLocks_IMPL =====

void lockStressObjCtrlCmdPerformLockStressInternalAllRmLocks_IMPL(undefined8 param_1,byte *param_2)

{
  int iVar1;
  undefined8 uVar2;
  byte local_29 [9];
  
  iVar1 = osGetRandomBytes(local_29,1);
  if (iVar1 == 0) {
    *param_2 = local_29[0] & 0x40 | 4;
    uVar2 = rmapiGetInterface(4);
    updateLockStressCountersInternal(param_1,uVar2,(local_29[0] & 3) + 2 | 0x1000100,param_2);
  }
  return;
}


// ===== 0049e880 lockStressObjCtrlCmdPerformLockStressInternalNoGpusLock_IMPL =====

void lockStressObjCtrlCmdPerformLockStressInternalNoGpusLock_IMPL(undefined8 param_1,byte *param_2)

{
  int iVar1;
  undefined8 uVar2;
  byte local_29 [9];
  
  iVar1 = osGetRandomBytes(local_29,1);
  if (iVar1 == 0) {
    *param_2 = local_29[0] & 0x40 | 4;
    uVar2 = rmapiGetInterface(3);
    updateLockStressCountersInternal(param_1,uVar2,(local_29[0] & 3) + 2 | 0x1000100,param_2);
  }
  return;
}


// ===== 0049e900 lockStressObjCtrlCmdPerformLockStressInternalApiLockReadMode_IMPL =====

void lockStressObjCtrlCmdPerformLockStressInternalApiLockReadMode_IMPL
               (undefined8 param_1,byte *param_2)

{
  int iVar1;
  undefined8 uVar2;
  byte local_29 [9];
  
  iVar1 = osGetRandomBytes(local_29,1);
  if (iVar1 == 0) {
    *param_2 = local_29[0] & 0x40 | 4;
    uVar2 = rmapiGetInterface(4);
    updateLockStressCountersInternal(param_1,uVar2,(local_29[0] & 1) + 4 | 0x1000100,param_2);
  }
  return;
}


// ===== 0049e980 lockStressObjCtrlCmdPerformLockStressInternalNoGpusLockApiLockReadMode_IMPL =====

void lockStressObjCtrlCmdPerformLockStressInternalNoGpusLockApiLockReadMode_IMPL
               (undefined8 param_1,byte *param_2)

{
  int iVar1;
  undefined8 uVar2;
  byte local_29 [9];
  
  iVar1 = osGetRandomBytes(local_29,1);
  if (iVar1 == 0) {
    *param_2 = local_29[0] & 0x40 | 4;
    uVar2 = rmapiGetInterface(3);
    updateLockStressCountersInternal(param_1,uVar2,(local_29[0] & 1) + 4 | 0x1000100,param_2);
  }
  return;
}


// ===== 0049e9f2 lockStressObjCtrlCmdGetLockStressCounters_IMPL.cold =====

void lockStressObjCtrlCmdGetLockStressCounters_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0049ea00 lockStressObjCtrlCmdGetLockStressCounters_IMPL =====

undefined8 lockStressObjCtrlCmdGetLockStressCounters_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  long lVar4;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar3 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48),
                             __nvoc_class_def_RmClient);
  if (lVar3 != 0) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
    lVar4 = serverutilGetClientUnderLock(*(undefined4 *)(lVar1 + 0x3b40));
    if (lVar4 != 0) {
      *param_2 = g_LockStressCounter;
      param_2[1] = *(undefined4 *)(lVar1 + 0x904);
      param_2[2] = *(undefined4 *)(lVar3 + 0x268);
      param_2[3] = *(undefined4 *)(lVar4 + 0x268);
      return 0;
    }
  }
  return 0x40;
}


// ===== 0049eab0 lockStressObjCtrlCmdRecursiveGpuLockTestNoLock_IMPL =====

int lockStressObjCtrlCmdRecursiveGpuLockTestNoLock_IMPL(long param_1,char *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  long *plVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  long lVar9;
  long lVar10;
  undefined8 uVar11;
  char *pcVar12;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  plVar4 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
  uVar7 = (undefined4)plVar4[2];
  uVar1 = *(undefined4 *)(*plVar4 + 0x48);
  uVar2 = *(undefined4 *)(plVar4[3] + 0x10);
  if (*param_2 != '\0') {
    return 0;
  }
  if (*(uint *)(*(long *)(g_pSys + 0x1e0) + 0x958) < 2) goto LAB_0049ec50;
  local_3c[0] = 0;
  iVar5 = rmGpuLocksGetOwnedMask();
  if (iVar5 != 0) {
    iVar5 = 0x56;
    goto LAB_0049ebe0;
  }
  lVar9 = gpumgrGetGpu(0);
  lVar10 = gpumgrGetGpu(1);
  iVar5 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar9 + 0x7a4),1,0,0x200,local_3c);
  if (iVar5 != 0) {
    nvDbg_Printf("src/kernel/rmapi/lock_stress.c",0x3a4,"_verifyGpuLockingOrder",4,
                 "NVRM: Failed to acquire GPU0 device lock with: 0x%x\n",iVar5);
    goto LAB_0049ebe0;
  }
  iVar6 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar9 + 0x7a4),1,0,0x200,local_3c);
  if (iVar6 != 0x2f) {
    pcVar12 = "NVRM: Recursive GPU0 device lock acquisition succeeded with: 0x%x\n";
    uVar11 = 0x3b0;
    goto LAB_0049ebbe;
  }
  iVar6 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar9 + 0x7a4),1,1,0x200,local_3c);
  iVar5 = 0x2f;
  if (iVar6 != 99) {
    pcVar12 = "NVRM: Recursive GPU0 device lock acquisition succeeded with: 0x%x\n";
    uVar11 = 0x3be;
    goto LAB_0049ef40;
  }
  iVar6 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar9 + 0x7a4),1,2,0x200,local_3c);
  if (iVar6 == 0) {
    iVar6 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar10 + 0x7a4),1,0,0x200,local_3c,0);
    if (iVar6 == 0) {
      uVar8 = rmGpuLocksGetOwnedMask();
      rmGpuGroupLockRelease(uVar8,0);
      iVar6 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar10 + 0x7a4),1,0,0x200,local_3c);
      if (iVar6 == 0) {
        iVar6 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar9 + 0x7a4),1,0,0x200,local_3c);
        if (iVar6 == 0x2f) {
          iVar5 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar9 + 0x7a4),1,1,0x200,local_3c);
          if (iVar5 == 0) {
            rmGpuGroupLockRelease(1,0);
          }
          else if (iVar5 != 99) {
            pcVar12 = 
            "NVRM: Conditional lock acquisition that violates locking order should not fail. status: 0x%x\n"
            ;
            uVar11 = 0x403;
            iVar6 = iVar5;
            goto LAB_0049ef40;
          }
          iVar5 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar9 + 0x7a4),1,2,0x200,local_3c);
          if ((iVar5 == 0) || (iVar5 == 99)) {
            local_3c[0] = 0;
            iVar6 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar9 + 0x7a4),2,4,0x200,local_3c);
            if (iVar6 != 0x2f) {
              pcVar12 = 
              "NVRM: Alloc lock acquisition that violates locking order did not fail. status: 0x%x\n"
              ;
              uVar11 = 0x423;
LAB_0049ebbe:
              iVar5 = 0x2f;
              nvDbg_Printf("src/kernel/rmapi/lock_stress.c",uVar11,"_verifyGpuLockingOrder",4,
                           pcVar12,iVar6);
              uVar7 = rmGpuLocksGetOwnedMask();
              rmGpuGroupLockRelease(uVar7,0);
              goto LAB_0049ebe0;
            }
            local_3c[0] = 0;
            iVar5 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar9 + 0x7a4),2,5,0x200,local_3c);
            if ((iVar5 == 99) || (iVar5 == 0)) {
              uVar8 = rmGpuLocksGetOwnedMask();
              rmGpuGroupLockRelease(uVar8,0);
              iVar5 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar9 + 0x7a4),1,0,0x200,local_3c);
              if (iVar5 == 0) {
                local_3c[0] = 0;
                iVar5 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar9 + 0x7a4),2,6,0x200,local_3c);
                if ((iVar5 == 0) || (iVar5 == 99)) {
                  uVar8 = rmGpuLocksGetOwnedMask();
                  rmGpuGroupLockRelease(uVar8,0);
                  iVar5 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar9 + 0x7a4),3,0,0x200,local_3c);
                  if (iVar5 == 0) {
                    local_3c[0] = 0;
                    iVar6 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar9 + 0x7a4),2,4,0x200,local_3c)
                    ;
                    if (iVar6 != 0x2f) {
                      pcVar12 = 
                      "NVRM: Recursive alloc lock acquisition does not fail with invalid lock state. state: 0x%x\n"
                      ;
                      uVar11 = 0x468;
                      goto LAB_0049ebbe;
                    }
                    local_3c[0] = 0;
                    iVar5 = rmGpuGroupLockAcquire
                                      (*(undefined4 *)(lVar9 + 0x7a4),2,6,0x200,local_3c,0x2f);
                    if (iVar5 == 0) {
                      uVar8 = rmGpuLocksGetOwnedMask();
                      rmGpuGroupLockRelease(uVar8,0);
LAB_0049ec50:
                      iVar5 = _verifyGpuLockState(lVar3,uVar1,uVar2,uVar7,0);
                      if (iVar5 == 0) {
                        iVar5 = rmGpuGroupLockAcquire
                                          (*(undefined4 *)(lVar3 + 0x7a4),1,0,0x200,&local_40);
                        if (iVar5 == 0) {
                          iVar5 = _verifyGpuLockState(lVar3,uVar1,uVar2,uVar7,1);
                          if (iVar5 == 0) {
                            iVar6 = rmGpuGroupLockAcquire
                                              (*(undefined4 *)(lVar3 + 0x7a4),3,0,0x200,&local_40);
                            if (iVar6 == 0x2f) {
                              uVar8 = rmGpuLocksGetOwnedMask();
                              rmGpuGroupLockRelease(uVar8,0);
                              iVar5 = rmGpuGroupLockAcquire
                                                (*(undefined4 *)(lVar3 + 0x7a4),3,0,0x200,&local_40)
                              ;
                              if (iVar5 == 0) {
                                iVar5 = _verifyGpuLockState(lVar3,uVar1,uVar2,uVar7,2);
                                if (iVar5 == 0) {
                                  iVar6 = rmGpuGroupLockAcquire
                                                    (*(undefined4 *)(lVar3 + 0x7a4),1,0,0x200,
                                                     &local_40);
                                  if (iVar6 != 0x2f) {
                                    iVar5 = 0x2f;
                                    nvDbg_Printf("src/kernel/rmapi/lock_stress.c",0x4da,
                                                 "lockStressObjCtrlCmdRecursiveGpuLockTestNoLock_IMPL"
                                                 ,4,
                                                 "NVRM: Device lock attempt under All GPUs Lock  should be invalid, status: 0x%x\n"
                                                 ,iVar6);
                                  }
                                }
                                else {
                                  nvAssertOkFailedNoLog
                                            (iVar5,
                                             "_verifyGpuLockState(pGpu, hClient, hSubdevice, hLockStressObject, _GPU_LOCK_STATE_ALL_LOCK)"
                                             ,"src/kernel/rmapi/lock_stress.c",0x4d0);
                                }
                              }
                              else {
                                nvDbg_Printf("src/kernel/rmapi/lock_stress.c",0x4cc,
                                             "lockStressObjCtrlCmdRecursiveGpuLockTestNoLock_IMPL",4
                                             ,"NVRM: Failed to acquire all GPUs lock with: 0x%x\n",
                                             iVar5);
                              }
                            }
                            else {
                              iVar5 = 0x2f;
                              nvDbg_Printf("src/kernel/rmapi/lock_stress.c",0x4bf,
                                           "lockStressObjCtrlCmdRecursiveGpuLockTestNoLock_IMPL",4,
                                           "NVRM: All GPUs lock attempt under GPU Device Lock  should be invalid, status: 0x%x\n"
                                           ,iVar6);
                            }
                          }
                          else {
                            nvAssertOkFailedNoLog
                                      (iVar5,
                                       "_verifyGpuLockState(pGpu, hClient, hSubdevice, hLockStressObject, _GPU_LOCK_STATE_DEVICE_LOCK)"
                                       ,"src/kernel/rmapi/lock_stress.c",0x4b5);
                          }
                        }
                        else {
                          nvDbg_Printf("src/kernel/rmapi/lock_stress.c",0x4b1,
                                       "lockStressObjCtrlCmdRecursiveGpuLockTestNoLock_IMPL",4,
                                       "NVRM: Failed to acquire GPU device lock with: 0x%x\n",iVar5)
                          ;
                        }
                        uVar7 = rmGpuLocksGetOwnedMask();
                        rmGpuGroupLockRelease(uVar7,0);
                        return iVar5;
                      }
                      nvAssertOkFailedNoLog
                                (iVar5,
                                 "_verifyGpuLockState(pGpu, hClient, hSubdevice, hLockStressObject, _GPU_LOCK_STATE_NONE)"
                                 ,"src/kernel/rmapi/lock_stress.c",0x4a9);
                      return iVar5;
                    }
                    pcVar12 = "NVRM: Recursive alloc lock safe upgrade failed with 0x%x\n";
                    uVar11 = 0x478;
                    iVar6 = iVar5;
                  }
                  else {
                    pcVar12 = "NVRM: Failed to acquire all GPUs lock. status: 0x%x\n";
                    uVar11 = 0x45e;
                    iVar6 = iVar5;
                  }
                }
                else {
                  pcVar12 = 
                  "NVRM: Safe lock upgrade for alloc lock that violateslocking order failed. status: 0x%x\n"
                  ;
                  uVar11 = 0x451;
                  iVar6 = iVar5;
                }
              }
              else {
                pcVar12 = "NVRM: Failed to acquire GPU0 device lock with: 0x%x\n";
                uVar11 = 0x443;
                iVar6 = iVar5;
              }
            }
            else {
              pcVar12 = 
              "NVRM: Alloc lock acquisition that violates locking order did not fail. status: 0x%x\n"
              ;
              uVar11 = 0x430;
              iVar6 = iVar5;
            }
          }
          else {
            pcVar12 = 
            "NVRM: Safe lock upgrade that violates locking order should not fail. status: 0x%x\n";
            uVar11 = 0x415;
            iVar6 = iVar5;
          }
        }
        else {
          pcVar12 = 
          "NVRM: GPU0 lock acqusition that violates locking order does not fail. status: 0x%x\n";
          uVar11 = 0x3f5;
        }
LAB_0049ef40:
        nvDbg_Printf("src/kernel/rmapi/lock_stress.c",uVar11,"_verifyGpuLockingOrder",4,pcVar12,
                     iVar6);
        uVar7 = rmGpuLocksGetOwnedMask();
        rmGpuGroupLockRelease(uVar7,0);
        goto LAB_0049ebe0;
      }
      pcVar12 = "NVRM: Failed to acquire GPU1 device lock with: 0x%x\n";
      uVar11 = 0x3e9;
      iVar5 = iVar6;
    }
    else {
      pcVar12 = 
      "NVRM: Failed to acquire GPU1 device lock with correct locking order, status: 0x%x\n";
      uVar11 = 0x3d9;
      iVar5 = iVar6;
    }
  }
  else {
    pcVar12 = "NVRM: Safe lock upgrade for recursive GPU0 device lock failed with: 0x%x\n";
    uVar11 = 0x3cc;
    iVar5 = iVar6;
  }
  nvDbg_Printf("src/kernel/rmapi/lock_stress.c",uVar11,"_verifyGpuLockingOrder",4,pcVar12,iVar5);
  uVar7 = rmGpuLocksGetOwnedMask();
  rmGpuGroupLockRelease(uVar7,0);
LAB_0049ebe0:
  nvAssertOkFailedNoLog(iVar5,"_verifyGpuLockingOrder(pGpu)","src/kernel/rmapi/lock_stress.c",0x4a5)
  ;
  return iVar5;
}


// ===== 0049f370 lockStressObjCtrlCmdRecursiveGpuLockTestAllLock_IMPL =====

int lockStressObjCtrlCmdRecursiveGpuLockTestAllLock_IMPL(long param_1,char *param_2)

{
  long lVar1;
  long *plVar2;
  char cVar3;
  int iVar4;
  undefined4 local_1c;
  
  local_1c = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  plVar2 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
  if (*param_2 == '\0') {
    iVar4 = _verifyGpuLockState(lVar1,*(undefined4 *)(*plVar2 + 0x48),
                                *(undefined4 *)(plVar2[3] + 0x10),(int)plVar2[2],2);
    if (iVar4 == 0) {
      iVar4 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar1 + 0x7a4),3,0,0x200,&local_1c);
      if (iVar4 == 0x2f) {
        iVar4 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar1 + 0x7a4),1,0,0x200,&local_1c);
        if (iVar4 == 0x2f) {
          return 0;
        }
        nvDbg_Printf("src/kernel/rmapi/lock_stress.c",0x51e,
                     "lockStressObjCtrlCmdRecursiveGpuLockTestAllLock_IMPL",4,
                     "NVRM: Device lock attempt succeeded, status: 0x%x\n",iVar4);
      }
      else {
        nvDbg_Printf("src/kernel/rmapi/lock_stress.c",0x515,
                     "lockStressObjCtrlCmdRecursiveGpuLockTestAllLock_IMPL",4,
                     "NVRM: All GPUs lock attempt succeeded, status: 0x%x\n",iVar4);
      }
      return 0x2f;
    }
    nvAssertOkFailedNoLog
              (iVar4,
               "_verifyGpuLockState(pGpu, hClient, hSubdevice, hLockStressObject, _GPU_LOCK_STATE_ALL_LOCK)"
               ,"src/kernel/rmapi/lock_stress.c",0x50e);
  }
  else {
    iVar4 = 0;
    cVar3 = rmGpuGroupLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4),3,&local_1c);
    if (cVar3 == '\0') {
      nvDbg_Printf("src/kernel/rmapi/lock_stress.c",0x509,
                   "lockStressObjCtrlCmdRecursiveGpuLockTestAllLock_IMPL",4,
                   "NVRM: Failed to hold all GPUs lock\n");
      return 0x2f;
    }
  }
  return iVar4;
}


// ===== 0049f500 lockStressObjCtrlCmdRecursiveGpuLockTestDeviceLock_IMPL =====

int lockStressObjCtrlCmdRecursiveGpuLockTestDeviceLock_IMPL(long param_1,char *param_2)

{
  long lVar1;
  long *plVar2;
  char cVar3;
  int iVar4;
  undefined4 local_1c;
  
  local_1c = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  plVar2 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
  if (*param_2 == '\0') {
    iVar4 = _verifyGpuLockState(lVar1,*(undefined4 *)(*plVar2 + 0x48),
                                *(undefined4 *)(plVar2[3] + 0x10),(int)plVar2[2],1);
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog
                (iVar4,
                 "_verifyGpuLockState(pGpu, hClient, hSubdevice, hLockStressObject, _GPU_LOCK_STATE_DEVICE_LOCK)"
                 ,"src/kernel/rmapi/lock_stress.c",0x546);
      return iVar4;
    }
    iVar4 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar1 + 0x7a4),3,0,0x200,&local_1c);
    if (iVar4 == 0x2f) {
      iVar4 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar1 + 0x7a4),1,0,0x200,&local_1c);
      if (iVar4 == 0x2f) {
        return 0;
      }
      nvDbg_Printf("src/kernel/rmapi/lock_stress.c",0x55e,
                   "lockStressObjCtrlCmdRecursiveGpuLockTestDeviceLock_IMPL",4,
                   "NVRM: Device lock attempt succeeded, status: 0x%x\n",iVar4);
    }
    else {
      nvDbg_Printf("src/kernel/rmapi/lock_stress.c",0x54e,
                   "lockStressObjCtrlCmdRecursiveGpuLockTestDeviceLock_IMPL",4,
                   "NVRM: All GPUs lock attempt succeeded, status: 0x%x\n",iVar4);
    }
    if (iVar4 == 0) {
      rmGpuGroupLockRelease(local_1c,0);
    }
  }
  else {
    cVar3 = rmGpuGroupLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4),1,&local_1c);
    if (cVar3 != '\0') {
      return 0;
    }
    nvDbg_Printf("src/kernel/rmapi/lock_stress.c",0x541,
                 "lockStressObjCtrlCmdRecursiveGpuLockTestDeviceLock_IMPL",4,
                 "NVRM: Failed to hold the GPU device lock\n");
  }
  return 0x2f;
}


// ===== 0049f6b0 lockTestRelaxedDupObjConstruct_IMPL =====

int lockTestRelaxedDupObjConstruct_IMPL(undefined8 param_1,undefined8 param_2,long param_3)

{
  char cVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  int local_24;
  long local_20;
  
  if (*(char *)(g_pSys + 0x7e) == '\0') {
    return 0x7e;
  }
  if (*(long *)(param_3 + 0x20) == 0) {
    nvAssertFailedNoLog("pParams->pClient != NULL","src/kernel/rmapi/lock_test.c",0x38);
    return 0x3b;
  }
  iVar2 = clientGetResourceRef_IMPL
                    (*(long *)(param_3 + 0x20),*(undefined4 *)(param_3 + 4),&local_20);
  if (iVar2 != 0) {
    nvAssertOkFailedNoLog
              (iVar2,"clientGetResourceRef(pParams->pClient, pParams->hParent, &pParentRef)",
               "src/kernel/rmapi/lock_test.c",0x39);
    return iVar2;
  }
  if (local_20 == 0) {
    nvAssertFailedNoLog("pParentRef != NULL","src/kernel/rmapi/lock_test.c",0x3a);
    return 0x3b;
  }
  lVar3 = __nvoc_dynamicCast(*(undefined8 *)(local_20 + 8),__nvoc_class_def_GpuResource);
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pParentGpuRes != NULL","src/kernel/rmapi/lock_test.c",0x3e);
    return 0x3b;
  }
  if (*(long *)(param_3 + 0x58) == 0) {
    return 0;
  }
  local_24 = 0;
  lVar3 = *(long *)(*(long *)(lVar3 + 0xd0) + 0xe0);
  lVar4 = *(long *)(*(long *)(param_3 + 0x58) + 0x18);
  if (lVar4 == 0) {
    nvAssertFailedNoLog("pParams->pSrcRef->pParentRef != NULL","src/kernel/rmapi/lock_test.c",0x48);
    return 0x3b;
  }
  lVar4 = *(long *)(lVar4 + 8);
  if (lVar4 != 0) {
    lVar4 = __nvoc_dynamicCast(lVar4,__nvoc_class_def_GpuResource);
    if (lVar4 == 0) {
      nvAssertFailedNoLog("pSrcGpuRes != NULL","src/kernel/rmapi/lock_test.c",0x4c);
      return 0x3b;
    }
    if (*(long *)(*(long *)(lVar4 + 0xd0) + 0xe0) == lVar3) {
      cVar1 = rmGpuGroupLockIsOwner(*(undefined4 *)(lVar3 + 0x7a4),1,&local_24);
      if (cVar1 == '\0') {
        nvAssertFailedNoLog("rmGpuGroupLockIsOwner(pParentGpu->gpuInstance, GPU_LOCK_GRP_DEVICE, &gpuMask)"
                            ,"src/kernel/rmapi/lock_test.c",0x50);
        return 0x2f;
      }
    }
    else {
      cVar1 = rmGpuGroupLockIsOwner(0,3,&local_24);
      if (cVar1 == '\0') {
        nvAssertFailedNoLog("rmGpuGroupLockIsOwner(0, GPU_LOCK_GRP_ALL, &gpuMask)",
                            "src/kernel/rmapi/lock_test.c",0x56);
        return 0x2f;
      }
    }
    iVar2 = rmGpuLocksGetOwnedMask();
    if (iVar2 != local_24) {
      nvAssertFailedNoLog("gpuMask == rmGpuLocksGetOwnedMask()","src/kernel/rmapi/lock_test.c",0x5c)
      ;
      return 0x2f;
    }
    return 0;
  }
  nvAssertFailedNoLog("pParams->pSrcRef->pParentRef->pResource != NULL",
                      "src/kernel/rmapi/lock_test.c",0x49);
  return 0x3b;
}


// ===== 0049f940 lockTestRelaxedDupObjDestruct_IMPL =====

void lockTestRelaxedDupObjDestruct_IMPL(void)

{
  return;
}


// ===== 0049f945 serverInterMap_Prologue.cold =====

void serverInterMap_Prologue_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0049f950 serverInterMap_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

int serverInterMap_Prologue
              (undefined8 param_1,long param_2,long param_3,long param_4,undefined8 param_5)

{
  ulong uVar1;
  ulong uVar2;
  long *plVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  long *plVar11;
  long lVar12;
  long lVar13;
  undefined8 uVar14;
  undefined4 local_70;
  undefined1 local_6c;
  long local_68;
  long local_60;
  undefined1 local_58;
  long local_50;
  long local_48;
  undefined4 local_40;
  undefined1 local_3c;
  
  uVar1 = *(ulong *)(param_4 + 0x10);
  uVar2 = *(ulong *)(param_4 + 0x18);
  lVar9 = resservGetTlsCallContext();
  plVar3 = *(long **)(param_4 + 0x50);
  if (plVar3 == (long *)0x0) {
    nvAssertFailedNoLog("pPrivate != NULL","src/kernel/rmapi/mapping.c",0x4e);
  }
  else {
    lVar9 = *(long *)(lVar9 + 0x18);
    lVar10 = __nvoc_dynamicCast(*(undefined8 *)(lVar9 + 8),__nvoc_class_def_Device);
    if (lVar10 == 0) {
      lVar9 = __nvoc_dynamicCast(*(undefined8 *)(lVar9 + 8),__nvoc_class_def_Subdevice);
      if (lVar9 == 0) {
        return 0x31;
      }
      lVar13 = *(long *)(*(long *)(lVar9 + 0x158) + 0xe0);
      lVar10 = *(long *)(*(long *)(lVar9 + 0x158) + 0xe8);
      if (*(long *)(lVar9 + 0x338) == 0) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)invalidInstructionException();
        (*pcVar4)();
      }
      local_6c = 1;
      local_70 = *(undefined4 *)
                  (*(long *)(*(long *)(*(long *)(lVar9 + 0x338) + 0x110) + 0x48) + 0x10);
      iVar6 = 1 << ((byte)*(undefined4 *)(lVar13 + 0x7a4) & 0x1f);
    }
    else {
      lVar13 = *(long *)(*(long *)(lVar10 + 0x128) + 0xe0);
      local_70 = *(undefined4 *)(param_4 + 0xc);
      iVar6 = gpumgrGetGpuMask(lVar13);
      local_6c = 0;
    }
    *(int *)(plVar3 + 4) = iVar6;
    if (((*(char *)(*(long *)(lVar13 + 0x1b78) + 0x434) != '\0') &&
        (*(char *)(*(long *)(lVar13 + 0x1b78) + 0x436) != '\0')) &&
       (lVar9 = __nvoc_dynamicCast(*(undefined8 *)(param_2 + 8),__nvoc_class_def_VirtualMemory),
       lVar9 != 0)) {
      if ((*(char *)(lVar9 + 0x270) == '\0') ||
         (lVar12 = __nvoc_dynamicCast(*(undefined8 *)(param_3 + 8),__nvoc_class_def_Memory),
         lVar12 == 0)) {
        uVar14 = 0x1000;
      }
      else {
        uVar14 = memdescGetPageSize(*(undefined8 *)(lVar12 + 0x118),1);
      }
      iVar6 = virtmemReserveMempool_IMPL(lVar9,lVar13,lVar10,*(undefined8 *)(param_4 + 0x18),uVar14)
      ;
      if (iVar6 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar6,
                   "virtmemReserveMempool(pVirtualMemory, pGpu, pDevice, pParams->length, pageSize)"
                   ,"src/kernel/rmapi/mapping.c",0x7d);
        return iVar6;
      }
    }
    *plVar3 = lVar13;
    cVar5 = gpuIsGpuFullPower_IMPL(lVar13);
    if (((cVar5 == '\0') && (*(char *)(lVar13 + 0x444) == '\0')) ||
       (cVar5 = gpuCheckSysmemAccess_IMPL(lVar13), cVar5 == '\0')) {
      return 0x11;
    }
    portMemSet(&local_68,0,0x30);
    local_58 = local_6c;
    local_68 = lVar13;
    local_60 = param_3;
    plVar11 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_3 + 8),__nvoc_class_def_RmResource);
    iVar6 = (**(code **)(*plVar11 + 0x100))(plVar11,&local_68,*(code **)(*plVar11 + 0x100));
    if (iVar6 != 0) {
      return iVar6;
    }
    if (local_48 == 0) {
      nvAssertFailedNoLog("pSrcMemDesc != NULL","src/kernel/rmapi/mapping.c",0x94);
      return 0x33;
    }
    uVar7 = 0;
    if (local_68 != 0) {
      uVar7 = gpumgrGetGpuMask();
    }
    if (local_50 != 0) {
      uVar8 = gpumgrGetGpuMask();
      uVar7 = uVar7 | uVar8;
    }
    iVar6 = serverResLock_Prologue(param_1,1,*(undefined8 *)(param_4 + 0x40),param_5,uVar7);
    if (iVar6 != 0) {
      return iVar6;
    }
    plVar3[1] = local_50;
    *(undefined4 *)((long)plVar3 + 0x1c) = local_40;
    *(undefined1 *)((long)plVar3 + 0x25) = local_3c;
    if ((CARRY8(uVar1,uVar2)) || (*(ulong *)(local_48 + 0x30) < uVar1 + uVar2)) {
      nvDbg_Printf("src/kernel/rmapi/mapping.c",0xab,"serverInterMap_Prologue",2,
                   "NVRM: Mapping offset 0x%llX or length 0x%llX out of bounds!\n",uVar1,uVar2);
      return 0x2e;
    }
    uVar14 = memdescGetMemDescFromGpu(local_48,lVar13);
    cVar5 = memdescGetFlag(uVar14,0x200000000);
    if ((cVar5 == '\0') || ((*(uint *)(param_4 + 0x20) & 3) == 1)) {
      plVar3[2] = local_48;
      *(undefined4 *)(plVar3 + 3) = local_70;
      *(undefined1 *)((long)plVar3 + 0x24) = local_6c;
      return 0;
    }
    nvDbg_Printf("src/kernel/rmapi/mapping.c",0xb4,"serverInterMap_Prologue",2,
                 "NVRM: Attempting to map READ_ONLY surface as READ_WRITE / WRITE_ONLY!\n");
  }
  return 0x1f;
}


// ===== 0049fdd0 serverInterMap_Epilogue =====

void serverInterMap_Epilogue(undefined8 param_1,long param_2,undefined8 param_3)

{
  serverResLock_Epilogue(param_1,1,*(undefined8 *)(param_2 + 0x40),param_3);
  return;
}


// ===== 0049fde5 serverInterUnmap_Prologue.cold =====

void serverInterUnmap_Prologue_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0049fdf0 serverInterUnmap_Prologue =====

byte serverInterUnmap_Prologue(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  long lVar8;
  
  lVar5 = resservGetTlsCallContext();
  plVar7 = *(long **)(param_2 + 0x40);
  lVar5 = *(long *)(lVar5 + 0x18);
  if (plVar7 == (long *)0x0) {
    plVar7 = (long *)portMemAllocNonPaged(0x18);
    if (plVar7 == (long *)0x0) {
      return 0x51;
    }
    portMemSet(plVar7,0,0x18);
    *(long **)(param_2 + 0x40) = plVar7;
    *(undefined1 *)((long)plVar7 + 0x12) = 1;
  }
  lVar6 = __nvoc_dynamicCast(*(undefined8 *)(lVar5 + 8),__nvoc_class_def_Device);
  if (lVar6 == 0) {
    lVar5 = __nvoc_dynamicCast(*(undefined8 *)(lVar5 + 8),__nvoc_class_def_Subdevice);
    if (lVar5 == 0) {
      return 0x31;
    }
    lVar8 = *(long *)(*(long *)(lVar5 + 0x158) + 0xe0);
    *(undefined1 *)((long)plVar7 + 0x11) = 0;
    if (*(long *)(lVar5 + 0x338) == 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    uVar1 = *(undefined4 *)(*(long *)(*(long *)(*(long *)(lVar5 + 0x338) + 0x110) + 0x48) + 0x10);
    *(undefined1 *)(plVar7 + 2) = 1;
    *(undefined4 *)(plVar7 + 1) = uVar1;
    iVar4 = 1 << ((byte)*(undefined4 *)(lVar8 + 0x7a4) & 0x1f);
  }
  else {
    lVar8 = *(long *)(*(long *)(lVar6 + 0x128) + 0xe0);
    *(undefined1 *)((long)plVar7 + 0x11) = 0;
    uVar1 = *(undefined4 *)(*(long *)(*(long *)(lVar6 + 0x110) + 0x48) + 0x10);
    *(undefined1 *)(plVar7 + 2) = 0;
    *(undefined4 *)(plVar7 + 1) = uVar1;
    iVar4 = gpumgrGetGpuMask(lVar8);
  }
  *(int *)((long)plVar7 + 0xc) = iVar4;
  *plVar7 = lVar8;
  cVar3 = gpuIsGpuFullPower_IMPL(lVar8);
  if (((cVar3 == '\0') && (*(char *)(lVar8 + 0x444) == '\0')) &&
     ((*(char *)(lVar8 + 0x490a) == '\0' || (*(char *)(lVar8 + 0x44c) != '\0')))) {
    return 0x11;
  }
  cVar3 = gpuCheckSysmemAccess_IMPL(lVar8);
  return -(cVar3 == '\0') & 0x11;
}


// ===== 0049ff90 serverInterUnmap_Epilogue =====

void serverInterUnmap_Epilogue(undefined8 param_1,long param_2)

{
  if ((*(long *)(param_2 + 0x40) != 0) && (*(char *)(*(long *)(param_2 + 0x40) + 0x12) != '\0')) {
    portMemFree();
    *(undefined8 *)(param_2 + 0x40) = 0;
    return;
  }
  return;
}


// ===== 0049ffd0 rmapiMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 rmapiMap(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 0xd8) != '\0') {
    uVar1 = (**(code **)(param_1 + 0xa0))(param_1,param_2,param_1 + 0xb8);
    return uVar1;
  }
  return 0x56;
}


// ===== 004a0000 rmapiMapWithSecInfo =====

int rmapiMapWithSecInfo(undefined8 param_1,undefined4 *param_2,undefined8 param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_ec;
  undefined1 local_e8 [40];
  undefined1 local_c0 [40];
  uint local_98;
  uint local_94;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined1 *local_40;
  undefined8 local_38;
  undefined1 *local_30;
  
  local_ec = 0;
  nvDbg_Printf("src/kernel/rmapi/mapping.c",0x15c,"rmapiMapWithSecInfo",1,
               "NVRM: Nv04Map: client:0x%x device:0x%x context:0x%x memory:0x%x flags:0x%x flags2:0x%x\n"
               ,*param_2,param_2[1],param_2[2],param_2[3],param_2[8],param_2[9]);
  uVar3 = *(undefined8 *)(param_2 + 6);
  nvDbg_Printf("src/kernel/rmapi/mapping.c",0x15f,"rmapiMapWithSecInfo",1,
               "NVRM: Nv04Map:  offset:0x%llx length:0x%llx dmaOffset:0x%08llx\n",
               *(undefined8 *)(param_2 + 4),uVar3,*(undefined8 *)(param_2 + 0xc));
  nvDbg_Printf("src/kernel/rmapi/mapping.c",0x163,"rmapiMapWithSecInfo",1,
               "NVRM: MMU_PROFILER Nv04Map 0x%x\n",param_2[8]);
  iVar2 = rmapiPrologue(param_1,&local_ec);
  if (iVar2 != 0) {
    return iVar2;
  }
  portMemSet(local_c0,0,0x40,uVar3);
  iVar2 = rmapiInitLockInfo(param_1,*param_2,0,local_c0);
  if (iVar2 == 0) {
    local_98 = local_98 | 0xc;
    cVar1 = rmapiInRtd3PmPath();
    if (cVar1 != '\0') {
      local_98 = local_98 | 1;
      local_94 = local_94 & 0xfffffffe;
    }
    portMemSet(&local_80,0,0x58);
    local_78 = CONCAT44(param_2[1],param_2[3]);
    local_70 = *(undefined8 *)(param_2 + 4);
    local_80 = CONCAT44(param_2[2],*param_2);
    local_68 = *(undefined8 *)(param_2 + 6);
    local_60 = *(undefined8 *)(param_2 + 8);
    local_58 = param_2[10];
    local_50 = *(undefined8 *)(param_2 + 0xc);
    local_40 = local_c0;
    local_38 = param_3;
    portMemSet(local_e8,0,0x28);
    local_30 = local_e8;
    iVar2 = serverInterMap(g_resServ,&local_80);
    *(undefined8 *)(param_2 + 0xc) = local_50;
    rmapiEpilogue(param_1,&local_ec);
    if (iVar2 == 0) {
      nvDbg_Printf("src/kernel/rmapi/mapping.c",0x19c,"rmapiMapWithSecInfo",1,
                   "NVRM: Nv04Map: map complete\n");
      nvDbg_Printf("src/kernel/rmapi/mapping.c",0x19d,"rmapiMapWithSecInfo",1,
                   "NVRM: Nv04Map:  dmaOffset: 0x%08llx\n",*(undefined8 *)(param_2 + 0xc));
      return 0;
    }
    uVar3 = nvstatusToString(iVar2);
    nvDbg_Printf("src/kernel/rmapi/mapping.c",0x1a1,"rmapiMapWithSecInfo",1,
                 "NVRM: Nv04Map: map failed; status: %s (0x%08x)\n",uVar3,iVar2);
    return iVar2;
  }
  rmapiEpilogue(param_1,&local_ec);
  return iVar2;
}


// ===== 004a02c0 rmapiMapWithSecInfoTls =====

undefined4 rmapiMapWithSecInfoTls(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined1 local_a8 [144];
  
  threadStateInit(local_a8,0);
  uVar1 = rmapiMapWithSecInfo(param_1,param_2,param_3);
  threadStateFree(local_a8,0);
  return uVar1;
}


// ===== 004a0320 rmapiUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 rmapiUnmap(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 0xd8) != '\0') {
    uVar1 = (**(code **)(param_1 + 0xb0))(param_1,param_2,param_1 + 0xb8);
    return uVar1;
  }
  return 0x56;
}


// ===== 004a0350 rmapiUnmapWithSecInfo =====

int rmapiUnmapWithSecInfo(undefined8 param_1,undefined4 *param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_d4;
  undefined8 local_d0;
  undefined1 local_c8 [24];
  undefined1 local_b0 [40];
  uint local_88;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined1 *local_40;
  undefined8 local_38;
  undefined1 *local_30;
  
  local_d4 = 0;
  nvDbg_Printf("src/kernel/rmapi/mapping.c",0x1d5,"rmapiUnmapWithSecInfo",1,
               "NVRM: Nv04Unmap: client:0x%x device:0x%x context:0x%x\n",*param_2,param_2[1],
               param_2[2]);
  nvDbg_Printf("src/kernel/rmapi/mapping.c",0x1d8,"rmapiUnmapWithSecInfo",1,
               "NVRM: Nv04Unmap:  flags:0x%x dmaOffset:0x%08llx size:0x%llx\n",param_2[4],
               *(undefined8 *)(param_2 + 6),*(undefined8 *)(param_2 + 8));
  iVar1 = rmapiPrologue(param_1,&local_d4);
  if (iVar1 != 0) {
    return iVar1;
  }
  portMemSet(local_b0,0,0x40);
  iVar1 = rmapiInitLockInfo(param_1,*param_2,0,local_b0);
  if (iVar1 == 0) {
    local_88 = local_88 | 0xc;
    local_d0 = 0;
    iVar1 = serverGetClientUnderLock(g_resServ,*param_2,&local_d0);
    if (iVar1 == 0) {
      portMemSet(&local_70,0,0x48);
      local_68 = CONCAT44(param_2[4],param_2[1]);
      local_60 = *(undefined8 *)(param_2 + 6);
      local_70 = CONCAT44(param_2[2],*param_2);
      local_40 = local_b0;
      local_58 = *(undefined8 *)(param_2 + 8);
      local_38 = param_3;
      portMemSet(local_c8,0,0x18);
      local_30 = local_c8;
      iVar1 = serverInterUnmap(g_resServ,&local_70);
      rmapiEpilogue(param_1,&local_d4);
      if (iVar1 == 0) {
        nvDbg_Printf("src/kernel/rmapi/mapping.c",0x1f2,"rmapiUnmapWithSecInfo",1,
                     "NVRM: Nv04Unmap: Unmap complete\n");
        return 0;
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar1,"serverGetClientUnderLock(&g_resServ, pParms->hClient, &pRsClient)",
                 "src/kernel/rmapi/mapping.c",0x12e);
      rmapiEpilogue(param_1,&local_d4);
    }
    uVar2 = nvstatusToString(iVar1);
    nvDbg_Printf("src/kernel/rmapi/mapping.c",0x1f6,"rmapiUnmapWithSecInfo",1,
                 "NVRM: Nv04Unmap: ummap failed; status: %s (0x%08x)\n",uVar2,iVar1);
    return iVar1;
  }
  rmapiEpilogue(param_1,&local_d4);
  return iVar1;
}


// ===== 004a05d0 rmapiUnmapWithSecInfoTls =====

undefined4 rmapiUnmapWithSecInfoTls(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined1 local_a8 [144];
  
  threadStateInit(local_a8,0);
  uVar1 = rmapiUnmapWithSecInfo(param_1,param_2,param_3);
  threadStateFree(local_a8,0);
  return uVar1;
}


// ===== 004a0630 serverInterMapLookupLockFlags =====

undefined8
serverInterMapLookupLockFlags
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,uint *param_4)

{
  char cVar1;
  
  if (param_4 != (uint *)0x0) {
    cVar1 = serverSupportsReadOnlyLock(param_1,param_2,5);
    *param_4 = (uint)(cVar1 == '\0');
    return 0;
  }
  nvAssertFailedNoLog("pAccess != NULL","src/kernel/rmapi/mapping.c",0x21b);
  return 0x1f;
}


// ===== 004a0690 serverInterUnmapLookupLockFlags =====

undefined8
serverInterUnmapLookupLockFlags
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,uint *param_4)

{
  char cVar1;
  
  if (param_4 != (uint *)0x0) {
    cVar1 = serverSupportsReadOnlyLock(param_1,param_2,6);
    *param_4 = (uint)(cVar1 == '\0');
    return 0;
  }
  nvAssertFailedNoLog("pAccess != NULL","src/kernel/rmapi/mapping.c",0x22c);
  return 0x1f;
}


// ===== 004a06f0 serverUpdateLockFlagsForInterAutoUnmap =====

undefined8 serverUpdateLockFlagsForInterAutoUnmap(undefined8 param_1,long param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(*(long *)(param_2 + 0x30) + 0x28);
  *puVar1 = *puVar1 | 0xc;
  return 0;
}


// ===== 004a0700 rmapiMapGpuCommon =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1  [16]
rmapiMapGpuCommon(undefined8 param_1,long param_2,ulong *param_3,undefined8 param_4,ulong param_5,
                 ulong param_6)

{
  undefined4 uVar1;
  ulong uVar2;
  ulong uVar3;
  undefined4 uVar4;
  long *plVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  
  plVar5 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_2 + 8),__nvoc_class_def_RmClient);
  uVar7 = *param_3;
  uVar6 = 0x20;
  if (uVar7 < (param_6 & 0xffffffff)) {
    uVar2 = param_3[1];
    if (((uVar2 == 0) || (CARRY8(uVar7,uVar2))) || ((param_6 & 0xffffffff) < uVar7 + uVar2)) {
      auVar10._8_8_ = uVar7;
      auVar10._0_8_ = 0x2e;
      return auVar10;
    }
    uVar3 = param_3[10];
    lVar8 = uVar7 + (param_5 & 0xffffffff);
    uVar1 = *(undefined4 *)(uVar3 + 0x20);
    uVar4 = (**(code **)(*plVar5 + 0xd8))();
    uVar7 = uVar3 + 0x18;
    uVar6 = osMapGPU(param_4,uVar4,lVar8,uVar2,uVar1,param_3 + 3);
  }
  auVar9._8_8_ = uVar7;
  auVar9._0_8_ = uVar6;
  return auVar9;
}


// ===== 004a07e0 rmapiGetEffectiveAddrSpace =====

void rmapiGetEffectiveAddrSpace(void)

{
  kbusGetEffectiveAddressSpace_STATIC_DISPATCH();
  return;
}


// ===== 004a0800 memMap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int memMap_IMPL(undefined8 param_1,long param_2,undefined4 *param_3,long param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  code *pcVar4;
  bool bVar5;
  char cVar6;
  char cVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  long *plVar14;
  long lVar15;
  undefined8 uVar16;
  long lVar17;
  long lVar18;
  ulong uVar19;
  ulong uVar20;
  ulong uVar21;
  long lVar22;
  ulong uVar23;
  long *plVar24;
  long *plVar25;
  char *pcVar26;
  long local_d8;
  long local_d0;
  undefined8 *local_a0;
  undefined1 local_95;
  int local_94;
  long local_90;
  long local_88;
  undefined8 local_80;
  undefined8 local_78;
  int local_70;
  undefined4 uStack_6c;
  ulong local_68;
  ulong local_60;
  ulong local_58;
  long local_50;
  long local_48;
  long local_40;
  
  lVar17 = g_pSys;
  local_90 = 0;
  local_80 = 0;
  if (*(long *)(param_3 + 0xe) == 0) {
    nvAssertFailedNoLog("pMapParams->pLockInfo != NULL","src/kernel/rmapi/mapping_cpu.c",0x95);
    return 0x1f;
  }
  uVar12 = param_3[10];
  lVar18 = *(long *)(*(long *)(param_3 + 0xe) + 0x10);
  if (lVar18 == 0) {
    local_d0 = 0;
    local_d8 = 0;
    lVar18 = 0;
  }
  else {
    iVar8 = gpuGetByRef(lVar18,&local_95,&local_90);
    if (iVar8 != 0) {
      nvAssertOkFailedNoLog
                (iVar8,"gpuGetByRef(pContextRef, &bBroadcast, &pGpu)",
                 "src/kernel/rmapi/mapping_cpu.c",0x99);
      return iVar8;
    }
    local_d8 = *(long *)(local_90 + 0x1b78);
    lVar18 = *(long *)(&DAT_00001b90 + local_90);
    local_d0 = *(long *)(local_90 + 0x1b70);
  }
  plVar14 = (long *)serverutilGetClientUnderLock(*param_3);
  if (plVar14 == (long *)0x0) {
    nvAssertFailedNoLog("pClient != NULL","src/kernel/rmapi/mapping_cpu.c",0xa2);
    return 0x23;
  }
  iVar8 = clientGetResourceRef_IMPL(plVar14[0x20],param_3[2],&local_88);
  if (iVar8 != 0) {
    nvAssertOkFailedNoLog
              (iVar8,
               "clientGetResourceRef(staticCast(pClient, RsClient), pMapParams->hMemory, &pMemoryRef)"
               ,"src/kernel/rmapi/mapping_cpu.c",0xa3);
    return iVar8;
  }
  lVar15 = __nvoc_dynamicCast(*(undefined8 *)(local_88 + 8),__nvoc_class_def_Memory);
  if (lVar15 == 0) {
    nvAssertFailedNoLog("pMemoryInfo != NULL","src/kernel/rmapi/mapping_cpu.c",0xa7);
    return 0x56;
  }
  local_a0 = *(undefined8 **)(lVar15 + 0x118);
  bVar5 = false;
  if ((param_3[10] & 0x300000) == 0x200000) {
    if (*(char *)(lVar17 + 0x7e) != '\0') {
      bVar5 = true;
      iVar8 = *(int *)(lVar15 + 0xfc);
      goto joined_r0x004a0dbf;
    }
    if (*(char *)(local_90 + 0x4915) != '\0') {
      nvDbg_Printf("src/kernel/rmapi/mapping_cpu.c",0xae,"memMap_IMPL",4,
                   "NVRM: In Selfhosted system Pcie bus path cannot be enabled without enabling RM_TEST_ONLY_CODE\n"
                  );
      return 0x56;
    }
    bVar5 = true;
    if (*(int *)(lVar15 + 0xfc) == 0x71) goto LAB_004a0dd0;
LAB_004a0c2a:
    cVar6 = gpuIsCCFeatureEnabled_IMPL();
    if (((cVar6 == '\0') && ((*(byte *)(lVar15 + 0x19b) & 1) != 0)) && (param_3[0xb] != 2)) {
      return 0x56;
    }
    if (((local_90 == 0) || (cVar6 = gpuIsCCFeatureEnabled_IMPL(), cVar6 == '\0')) ||
       ((*(byte *)(lVar15 + 0x19b) & 1) == 0)) goto LAB_004a095d;
    lVar17 = *(long *)(local_90 + 0x1d18);
    if (((lVar17 != 0) && (*(char *)(lVar17 + 0x2b8) == '\0')) &&
       (*(char *)(lVar17 + 0x2b9) == '\0')) {
LAB_004a0cd0:
      nvDbg_Printf("src/kernel/rmapi/mapping_cpu.c",0xf2,"memMap_IMPL",4,
                   "NVRM: BAR1 mapping to CPR vidmem not supported\n");
      nvAssertFailedNoLog(&DAT_00d92cd1,"src/kernel/rmapi/mapping_cpu.c",0xf3);
      return 0x56;
    }
    if (*(char *)(local_90 + 0x909) == '\0') goto LAB_004a095d;
    if (*(char *)(param_3 + 0xc) == '\0') goto LAB_004a0bb8;
    if ((*(char *)(lVar18 + 0xad47) == '\0') && ((*(byte *)((long)param_3 + 0x2b) & 4) == 0))
    goto LAB_004a0cd0;
  }
  else {
    iVar8 = *(int *)(lVar15 + 0xfc);
joined_r0x004a0dbf:
    if (iVar8 == 0x71) {
LAB_004a0dd0:
      uVar10 = memdescGetAddressSpace(local_a0);
      cVar6 = memdescGetFlag(local_a0,0x20000000000000);
      if (cVar6 == '\0') {
        nvDbg_Printf("src/kernel/rmapi/mapping_cpu.c",0xc5,"memMap_IMPL",4,
                     "NVRM: CPU mapping not supported for addressSpace: 0x%x\n",uVar10);
        return 0x56;
      }
    }
    if (local_90 != 0) goto LAB_004a0c2a;
LAB_004a095d:
    if (*(char *)(param_3 + 0xc) == '\0') {
LAB_004a0bb8:
      if (((*(byte *)(lVar15 + 0x18e) & 0x40) != 0) && (param_3[0xb] != 1)) {
        return 0x1f;
      }
    }
  }
  uVar21 = *(ulong *)(param_3 + 4);
  if (*(ulong *)(lVar15 + 0x100) <= uVar21) {
    return 0x20;
  }
  uVar20 = *(ulong *)(param_3 + 6);
  if (uVar20 == 0) {
    return 0x2e;
  }
  if ((uVar12 & 0x100) == 0) {
    if (CARRY8(uVar21,uVar20)) {
      return 0x2e;
    }
    if (*(ulong *)(lVar15 + 0x100) < uVar21 + uVar20) {
      return 0x2e;
    }
  }
  else {
    if (*(uint *)(param_2 + 0x28) < 2) {
      return 0x1b;
    }
    if (CARRY8(uVar21,uVar20)) {
      return 0x2e;
    }
  }
  if (local_90 == 0) {
    local_94 = 1;
    if (local_a0 != (undefined8 *)0x0) {
      if (*(uint *)((long)local_a0 + 0x8c) < 2) goto LAB_004a0e8c;
      iVar8 = 2;
      goto LAB_004a0a39;
    }
LAB_004a13e0:
    iVar8 = memdescMap(local_a0,uVar21,uVar20,*(undefined1 *)(param_3 + 0xc),param_3[0xb],
                       *(undefined8 *)(param_3 + 8),&local_80);
    if (iVar8 != 0) {
      return iVar8;
    }
    uVar16 = 0;
    if (**(long **)(param_3 + 8) == 0) goto LAB_004a0b51;
    uVar12 = param_3[10] & 0xfffe7fff | 0x8000;
    param_3[10] = uVar12;
    if (param_4 == 0) goto LAB_004a1584;
    uVar16 = *(undefined8 *)(param_3 + 6);
    lVar17 = **(long **)(param_3 + 8);
LAB_004a0b01:
    uVar1 = local_80;
    *(undefined1 *)(*(long *)(param_4 + 0x50) + 0x24) = *(undefined1 *)(param_3 + 0xc);
    *(undefined8 *)(param_4 + 8) = uVar16;
    *(uint *)(param_4 + 0x10) = uVar12;
    uVar10 = osGetCurrentProcess();
    *(long *)(param_4 + 0x18) = lVar17;
    *(undefined4 *)(param_4 + 0x48) = uVar10;
    *(undefined8 *)(*(long *)(param_4 + 0x50) + 0x18) = uVar1;
    portMemSet(*(undefined8 *)(param_4 + 0x50),0,0x10);
    *(long *)(*(long *)(param_4 + 0x50) + 0x10) = local_90;
  }
  else {
    uVar10 = param_3[10];
    uVar16 = memdescGetMemDescFromGpu(local_a0,local_90);
    iVar8 = kbusGetEffectiveAddressSpace_STATIC_DISPATCH(local_90,uVar16,uVar10,&local_94);
    if (iVar8 != 0) {
      nvAssertOkFailedNoLog
                (iVar8,
                 "rmapiGetEffectiveAddrSpace(pGpu, memdescGetMemDescFromGpu(pMemDesc, pGpu), pMapParams->flags, &effectiveAddrSpace)"
                 ,"src/kernel/rmapi/mapping_cpu.c",0x11b);
      return iVar8;
    }
    if ((local_a0 == (undefined8 *)0x0) || (1 < *(uint *)((long)local_a0 + 0x8c))) {
      iVar8 = 2;
    }
    else {
LAB_004a0e8c:
      cVar6 = memdescGetFlag(local_a0,0x8000000000);
      iVar8 = (cVar6 == '\0') + 1;
    }
    if ((((local_90 != 0) && (*(char *)(local_90 + 0x454) != '\0')) && (!bVar5)) &&
       (iVar11 = memdescGetAddressSpace(local_a0), iVar11 == 2)) {
      if (*(char *)(local_90 + 0x45b) == '\0') {
        nvAssertFailedNoLog("pGpu->getProperty(pGpu, PDB_PROP_GPU_ATS_SUPPORTED)",
                            "src/kernel/rmapi/mapping_cpu.c",0x134);
      }
      iVar11 = memdescGetPteKindForGpu(local_a0,*local_a0);
      iVar13 = (**(code **)(local_d8 + 0x2d8))(local_90,local_d8,0x100);
      if (iVar13 != iVar11) {
LAB_004a17d9:
        nvDbg_Printf("src/kernel/rmapi/mapping_cpu.c",0x1b8,"memMap_IMPL",4,
                     "NVRM: Need BAR mapping on coherent link! FAIL!!\n");
        return 0x56;
      }
      uVar16 = memdescGetMemDescFromGpu(local_a0,local_90);
      cVar6 = memdescGetFlag(uVar16,0x800);
      if (cVar6 != '\0') goto LAB_004a17d9;
      if (*(char *)(param_3 + 0xc) == '\0') {
        lVar17 = *(long *)(local_d0 + 0x478);
        lVar18 = memdescGetPhysAddr(local_a0,0,*(undefined8 *)(param_3 + 4));
        uVar20 = lVar17 + lVar18;
        **(ulong **)(param_3 + 8) = uVar20;
        cVar6 = memdescGetContiguity(local_a0,0);
        lVar17 = memdescGetPageSize(local_a0,0);
        cVar7 = osNumaOnliningEnabled(*(undefined8 *)(local_90 + 0x4e0));
        uVar21 = *(ulong *)(param_3 + 6);
        if (((cVar7 == '\0') || (*(char *)(local_90 + 0x454) == '\0')) ||
           (*(long *)(local_d0 + 0x4b0) == 0)) {
LAB_004a18e8:
          uVar16 = *(undefined8 *)(param_3 + 4);
          memdescIteratorInit(&local_70,local_a0,0,uVar16,uVar21);
          lVar17 = 0;
          uVar23 = local_68;
          uVar20 = local_58;
          if (local_70 == 1) goto LAB_004a1a74;
          uVar19 = local_58;
          if (local_70 == 2) {
            while (uVar19 < local_60) {
              plVar14 = (long *)(uVar19 * 0x10 + uVar23);
              lVar18 = *plVar14;
              lVar15 = plVar14[1];
              uVar20 = uVar19 + 1;
              if (uVar19 != 0) goto joined_r0x004a1c02;
              if (local_60 == 1) {
LAB_004a1c93:
                lVar17 = lVar17 + 1;
                break;
              }
              lVar18 = lVar18 + local_50;
              lVar15 = lVar15 - local_50;
              do {
                plVar14 = (long *)(uVar20 * 0x10 + uVar23);
                if (*plVar14 != lVar18 + lVar15) break;
                uVar20 = uVar20 + 1;
                lVar15 = lVar15 + plVar14[1];
joined_r0x004a1c02:
              } while (uVar20 < local_60);
LAB_004a1a60:
              lVar17 = lVar17 + 1;
              uVar19 = uVar20;
              if (local_70 == 1) {
LAB_004a1a74:
                do {
                  if (uVar20 <= uVar23) goto LAB_004a192f;
                  lVar15 = *(long *)(local_60 + uVar23 * 8);
                  lVar18 = uVar23 * 8;
                  uVar19 = uVar23 + 1;
                  if (uVar23 == 0) {
                    if (uVar20 == 1) goto LAB_004a1c93;
                    lVar15 = lVar15 + local_48;
                    lVar22 = local_50 - local_48;
                  }
                  else {
                    uVar23 = uVar19;
                    lVar22 = local_50;
                    if (uVar20 <= uVar19) goto LAB_004a1a60;
                  }
                  plVar14 = (long *)(lVar18 + 8 + local_60);
                  lVar22 = lVar22 + lVar15;
                  do {
                    uVar23 = uVar19;
                    if (*plVar14 != lVar22) goto LAB_004a1a60;
                    uVar19 = uVar19 + 1;
                    plVar14 = plVar14 + 1;
                    lVar22 = lVar22 + local_50;
                  } while (uVar19 < uVar20);
                  lVar17 = lVar17 + 1;
                  uVar23 = uVar19;
                } while( true );
              }
            }
          }
LAB_004a192f:
          plVar14 = (long *)portMemAllocNonPaged(lVar17 << 4);
          if (plVar14 == (long *)0x0) {
            nvCheckFailedNoLog(1,"memArea.pRanges != NULL","src/kernel/rmapi/mapping_cpu.c",0x17e);
            return 0x51;
          }
          memdescIteratorInit(&local_70,local_a0,0,uVar16,uVar21);
          plVar24 = plVar14;
          if (local_70 == 1) {
            lVar17 = 0;
            uVar21 = local_68;
            goto LAB_004a1b6f;
          }
          lVar17 = 0;
          uVar20 = local_58;
          if (local_70 == 2) {
            while (uVar20 < local_60) {
              local_58 = uVar20 + 1;
              plVar25 = (long *)(local_68 + uVar20 * 0x10);
              lVar15 = *plVar25;
              lVar18 = plVar25[1];
              plVar25 = plVar24;
              if (uVar20 == 0) {
                lVar15 = lVar15 + local_50;
                lVar18 = lVar18 - local_50;
                if (local_60 != 1) {
LAB_004a1b13:
                  plVar24 = (long *)(local_68 + 0x10 + uVar20 * 0x10);
                  do {
                    if (*plVar24 != lVar15 + lVar18) break;
                    local_58 = local_58 + 1;
                    lVar18 = lVar18 + plVar24[1];
                    plVar24 = plVar24 + 2;
                  } while (local_58 < local_60);
                  goto LAB_004a1b3a;
                }
                local_58 = 1;
LAB_004a1c36:
                lVar18 = lVar18 - local_48;
              }
              else {
                if (local_58 < local_60) goto LAB_004a1b13;
LAB_004a1b3a:
                if (local_60 == local_58) goto LAB_004a1c36;
              }
              while( true ) {
                plVar25[1] = lVar18;
                lVar17 = lVar17 + 1;
                plVar24 = plVar25 + 2;
                *plVar25 = lVar15;
                *plVar25 = lVar15 + *(long *)(local_d0 + 0x478);
                uVar20 = local_58;
                uVar21 = local_68;
                if (local_70 != 1) break;
LAB_004a1b6f:
                if (local_58 <= uVar21) goto LAB_004a1998;
                lVar15 = *(long *)(local_60 + uVar21 * 8);
                local_68 = uVar21 + 1;
                plVar25 = plVar24;
                if (uVar21 == 0) {
                  lVar15 = lVar15 + local_48;
                  lVar18 = local_50 - local_48;
                  if (local_58 != 1) goto LAB_004a1ba4;
                  local_68 = 1;
                  goto LAB_004a1be2;
                }
                lVar18 = local_50;
                if (local_68 < local_58) {
LAB_004a1ba4:
                  plVar24 = (long *)(local_60 + 8 + uVar21 * 8);
                  do {
                    if (*plVar24 != lVar18 + lVar15) break;
                    local_68 = local_68 + 1;
                    lVar18 = lVar18 + local_50;
                    plVar24 = plVar24 + 1;
                  } while (local_68 < local_58);
                }
                if (local_58 == local_68) {
LAB_004a1be2:
                  lVar18 = lVar18 - local_40;
                }
              }
            }
          }
LAB_004a1998:
          iVar8 = osMapPciMemoryAreaUser
                            (*(undefined8 *)(local_90 + 0x4e0),plVar14,lVar17,param_3[0xb],iVar8,
                             *(undefined8 *)(param_3 + 8),&local_80);
          portMemFree(plVar14);
          goto joined_r0x004a151a;
        }
        lVar18 = *(long *)(local_d0 + 0x478);
        uVar23 = *(long *)(local_d0 + 0x4a8) + lVar18;
        if (uVar20 < uVar23) goto LAB_004a18e8;
        uVar19 = uVar21;
        if ((cVar6 == '\0') &&
           (uVar19 = (*(long *)(param_3 + 4) + lVar17 & -lVar17) - *(long *)(param_3 + 4),
           uVar21 < uVar19)) {
          uVar19 = uVar21;
        }
        if (*(long *)(local_d0 + 0x4b0) + uVar23 < uVar19 + uVar20) goto LAB_004a18e8;
      }
      else {
        iVar8 = (**(code **)(lVar18 + 0x518))
                          (local_90,lVar18,local_a0,*(undefined8 *)(param_3 + 4),
                           *(undefined8 *)(param_3 + 6),param_3[0xb],*(undefined8 *)(param_3 + 8),
                           &local_80);
joined_r0x004a151a:
        if (iVar8 != 0) {
          return iVar8;
        }
        uVar21 = *(ulong *)(param_3 + 6);
        lVar18 = *(long *)(local_d0 + 0x478);
      }
      nvDbg_Printf("src/kernel/rmapi/mapping_cpu.c",0x19c,"memMap_IMPL",1,
                   "NVRM: NVLINK mapping allocated: AtsBase=0x%llx, _pteArray[0]=0x%llx, mappedCpuAddr=0x%llx, length=%d\n"
                   ,lVar18,local_a0[0x2e],**(undefined8 **)(param_3 + 8),uVar21);
joined_r0x004a157e:
      if (param_4 == 0) {
LAB_004a1584:
                    /* WARNING: Does not return */
        pcVar4 = (code *)invalidInstructionException();
        (*pcVar4)();
      }
      uVar12 = param_3[10];
      uVar16 = *(undefined8 *)(param_3 + 6);
      lVar17 = **(long **)(param_3 + 8);
      goto LAB_004a0b01;
    }
LAB_004a0a39:
    if (local_94 != 2) {
      if (local_94 == 1) {
        uVar21 = *(ulong *)(param_3 + 4);
        uVar20 = *(ulong *)(param_3 + 6);
        goto LAB_004a13e0;
      }
      if (local_94 == 4) {
        return 0x56;
      }
      if (local_94 != 3) {
        return 0x22;
      }
      uVar10 = (**(code **)(*plVar14 + 0xd8))(plVar14);
      cVar6 = (**(code **)(*plVar14 + 0xe0))(plVar14,uVar10);
      if ((cVar6 == '\0') && (cVar6 = memdescGetFlag(local_a0,0x2000000000), cVar6 == '\0')) {
        return 0x5f;
      }
      uVar9 = 0;
      if ((*(byte *)((long)param_3 + 0x29) & 0x40) == 0) {
        uVar9 = uVar10;
      }
      iVar8 = osMapGPU(local_90,uVar9,local_a0[0x2e] + *(long *)(param_3 + 4),
                       *(undefined8 *)(param_3 + 6),param_3[0xb],*(undefined8 *)(param_3 + 8),
                       &local_80);
      if (iVar8 != 0) {
        return iVar8;
      }
      goto joined_r0x004a157e;
    }
    if (*(char *)(lVar18 + 0xad04) == '\0') {
      lVar15 = *(long *)(param_3 + 6);
      if (*(long *)(local_90 + 0x850) == 0) {
        nvAssertFailedNoLog("pGpu->busInfo.gpuPhysFbAddr","src/kernel/rmapi/mapping_cpu.c",0x1de);
      }
      local_78 = 0;
      local_a0 = (undefined8 *)memdescGetMemDescFromGpu(local_a0,local_90);
      deviceGetByHandle_IMPL(plVar14[0x20],param_3[1],&local_78);
      iVar11 = kbusMapFbAperture_GM107
                         (local_90,lVar18,local_a0,*(undefined8 *)(param_3 + 4),lVar15,&local_70);
      if (iVar11 != 0) {
        return iVar11;
      }
      lVar22 = *(long *)CONCAT44(uStack_6c,local_70);
      if (*(char *)(param_3 + 0xc) == '\0') {
        lVar17 = gpumgrGetGpuPhysFbAddr(local_90);
        if (local_68 != 0) {
          uVar21 = 0;
          do {
            uVar20 = uVar21 + 1;
            plVar14 = (long *)(uVar21 * 0x10 + CONCAT44(uStack_6c,local_70));
            *plVar14 = *plVar14 + lVar17;
            uVar21 = uVar20;
          } while (uVar20 < local_68);
        }
        iVar11 = osMapPciMemoryAreaUser
                           (*(undefined8 *)(local_90 + 0x4e0),CONCAT44(uStack_6c,local_70),local_68,
                            param_3[0xb],iVar8,*(undefined8 *)(param_3 + 8),&local_80);
        uVar21 = 0;
        if (local_68 != 0) {
          do {
            uVar20 = uVar21 + 1;
            plVar14 = (long *)(uVar21 * 0x10 + CONCAT44(uStack_6c,local_70));
            *plVar14 = *plVar14 - lVar17;
            uVar21 = uVar20;
          } while (uVar20 < local_68);
        }
        bVar5 = true;
      }
      else {
        bVar5 = true;
        lVar17 = 0;
LAB_004a11c3:
        uVar16 = *(undefined8 *)(param_3 + 8);
        uVar10 = param_3[0xb];
        uVar1 = *(undefined8 *)(param_3 + 6);
        if (*(char *)(lVar18 + 0xad04) == '\0') {
          lVar17 = gpumgrGetGpuPhysFbAddr(local_90,lVar17);
          lVar17 = lVar17 + lVar22;
        }
        iVar11 = osMapPciMemoryKernel64(local_90,lVar17,uVar1,uVar10,uVar16,iVar8);
      }
    }
    else {
      cVar6 = memdescGetContiguity(local_a0,1);
      if (cVar6 == '\0') {
        nvAssertFailedNoLog("memdescGetContiguity(pMemDesc, AT_GPU)",
                            "src/kernel/rmapi/mapping_cpu.c",0x214);
        return 0x56;
      }
      lVar15 = gpumgrGetGpuPhysFbAddr(local_90);
      lVar17 = memdescGetPte(local_a0,1,0);
      lVar17 = (ulong)*(uint *)(local_a0 + 0xc) + *(long *)(param_3 + 4) + lVar15 + lVar17;
      if (*(char *)(param_3 + 0xc) != '\0') {
        bVar5 = false;
        lVar15 = 0;
        lVar22 = 0;
        goto LAB_004a11c3;
      }
      uVar16 = *(undefined8 *)(param_3 + 8);
      uVar10 = param_3[0xb];
      uVar1 = *(undefined8 *)(param_3 + 6);
      if (*(char *)(lVar18 + 0xad04) == '\0') {
        lVar17 = gpumgrGetGpuPhysFbAddr(local_90,lVar17);
      }
      iVar11 = osMapPciMemoryUser(*(undefined8 *)(local_90 + 0x4e0),lVar17,uVar1,uVar10,uVar16,
                                  &local_80,iVar8);
      lVar22 = 0;
      lVar15 = 0;
      bVar5 = false;
    }
    uVar16 = local_80;
    uVar12 = param_3[10] & 0xfc7e7fff | iVar8 << 0x17 | 0x10000;
    param_3[10] = uVar12;
    puVar3 = _DAT_00000050;
    if (iVar11 != 0) {
LAB_004a1388:
      if (*(char *)(lVar18 + 0xad04) != '\0') {
        return iVar11;
      }
      kbusUnmapFbAperture_GM107(local_90,lVar18,local_a0,CONCAT44(uStack_6c,local_70),local_68,0x20)
      ;
      return iVar11;
    }
    if (*(char *)(lVar18 + 0xad04) != '\0') {
      lVar22 = 0;
      lVar15 = 0;
    }
    if (param_4 == 0) {
      if (bVar5) {
        *_DAT_00000050 = CONCAT44(uStack_6c,local_70);
        puVar3[1] = local_68;
        _DAT_00000050[2] = local_90;
        if (*(char *)(param_3 + 0xc) == '\0') {
          osUnmapPciMemoryUser
                    (*(undefined8 *)(local_90 + 0x4e0),**(undefined8 **)(param_3 + 8),
                     *(undefined8 *)(param_3 + 6));
        }
        else {
          osUnmapPciMemoryKernel64();
        }
        iVar11 = 0x1f;
        goto LAB_004a1388;
      }
      goto LAB_004a1584;
    }
    uVar1 = *(undefined8 *)(param_3 + 6);
    uVar2 = **(undefined8 **)(param_3 + 8);
    *(undefined1 *)(*(long *)(param_4 + 0x50) + 0x24) = *(undefined1 *)(param_3 + 0xc);
    *(undefined8 *)(param_4 + 8) = uVar1;
    *(uint *)(param_4 + 0x10) = uVar12;
    uVar10 = osGetCurrentProcess();
    *(undefined4 *)(param_4 + 0x48) = uVar10;
    *(undefined8 *)(param_4 + 0x18) = uVar2;
    *(undefined8 *)(*(long *)(param_4 + 0x50) + 0x18) = uVar16;
    if ((lVar15 == 0) || (lVar22 == 0)) {
      portMemSet(*(long *)(param_4 + 0x50),0,0x10);
      if (bVar5) goto LAB_004a12ec;
      *(long *)(*(long *)(param_4 + 0x50) + 0x10) = local_90;
    }
    else {
      *(undefined8 *)(*(long *)(param_4 + 0x50) + 8) = 1;
      **(long **)(param_4 + 0x50) = (long)(*(long **)(param_4 + 0x50) + 5);
      *(long *)(*(long *)(param_4 + 0x50) + 0x28) = lVar22;
      *(long *)(*(long *)(param_4 + 0x50) + 0x30) = lVar15;
      if (bVar5) {
LAB_004a12ec:
        puVar3 = *(undefined8 **)(param_4 + 0x50);
        *puVar3 = CONCAT44(uStack_6c,local_70);
        puVar3[1] = local_68;
        *(long *)(*(long *)(param_4 + 0x50) + 0x10) = local_90;
      }
      else {
        *(long *)(*(long *)(param_4 + 0x50) + 0x10) = local_90;
      }
    }
  }
  uVar16 = **(undefined8 **)(param_3 + 8);
LAB_004a0b51:
  pcVar26 = "Mapping";
  if ((param_3[10] & 0x18000) == 0x8000) {
    pcVar26 = "Direct mapping";
  }
  nvDbg_Printf("src/kernel/rmapi/mapping_cpu.c",0x2d0,"memMap_IMPL",1,
               "NVRM: %s created. CPU Virtual Address: %p\n",pcVar26,uVar16);
  return 0;
}


// ===== 004a1cb0 memUnmap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

undefined8 memUnmap_IMPL(long param_1,long param_2,long param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  char cVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  long *plVar10;
  undefined8 uVar11;
  long lVar12;
  long local_40;
  
  plVar10 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_2 + 8),__nvoc_class_def_RmClient);
  lVar12 = *(long *)(param_3 + 0x50);
  puVar2 = *(undefined8 **)(param_1 + 0x118);
  uVar1 = *(uint *)(param_3 + 0x10);
  lVar3 = *(long *)(lVar12 + 0x10);
  if (lVar3 == 0) {
    if (((uVar1 & 0x300000) != 0x200000) || (*(char *)(g_pSys + 0x7e) != '\0')) {
      if ((uVar1 & 0x400000) != 0) {
        return 0;
      }
      if ((uVar1 & 0x18000) != 0x8000) {
        return 0;
      }
      goto LAB_004a1d50;
    }
    local_40 = 0;
LAB_004a1d8e:
    if (*(char *)(lVar3 + 0x4915) != '\0') {
      nvDbg_Printf("src/kernel/rmapi/mapping_cpu.c",0x2f4,"memUnmap_IMPL",4,
                   "NVRM: In Selfhosted system Pcie bus path cannot be enabled without enabling RM_TEST_ONLY_CODE\n"
                  );
      return 0x56;
    }
LAB_004a1d9c:
    if ((uVar1 & 0x400000) != 0) {
      return 0;
    }
    iVar7 = memdescGetAddressSpace(puVar2);
  }
  else {
    local_40 = *(long *)(&DAT_00001b90 + lVar3);
    if ((uVar1 & 0x300000) == 0x200000) {
      if (*(char *)(g_pSys + 0x7e) == '\0') goto LAB_004a1d8e;
      goto LAB_004a1d9c;
    }
    if ((uVar1 & 0x400000) != 0) {
      return 0;
    }
    if (*(char *)(lVar3 + 0x454) != '\0') {
      lVar12 = *(long *)(lVar3 + 0x1b78);
      iVar7 = memdescGetAddressSpace(puVar2);
      if (iVar7 == 2) {
        if (*(char *)(lVar3 + 0x45b) == '\0') {
          nvAssertFailedNoLog("pGpu->getProperty(pGpu, PDB_PROP_GPU_ATS_SUPPORTED)",
                              "src/kernel/rmapi/mapping_cpu.c",0x301);
        }
        iVar7 = memdescGetPteKindForGpu(puVar2,*puVar2);
        iVar9 = (**(code **)(lVar12 + 0x2d8))(lVar3,lVar12,0x100);
        if ((iVar9 != iVar7) || (cVar6 = memdescGetFlag(puVar2,0x800), cVar6 != '\0')) {
          nvAssertFailedNoLog("(memdescGetPteKind(pMemDesc) == memmgrGetHwPteKindFromSwPteKind_HAL(pGpu, pMemoryManager, RM_DEFAULT_PTE_KIND)) && (!memdescGetFlag(pMemDesc, MEMDESC_FLAGS_ENCRYPTED))"
                              ,"src/kernel/rmapi/mapping_cpu.c",0x302);
        }
        if (*(char *)(*(long *)(param_3 + 0x50) + 0x24) == '\0') {
          cVar6 = osNumaOnliningEnabled(*(undefined8 *)(lVar3 + 0x4e0));
          if (cVar6 == '\0') {
            if (*(char *)(*(long *)(param_3 + 0x50) + 0x24) == '\0') {
              osUnmapPciMemoryUser
                        (*(undefined8 *)(lVar3 + 0x4e0),*(undefined8 *)(param_3 + 0x18),
                         *(undefined8 *)(param_3 + 8),
                         *(undefined8 *)(*(long *)(param_3 + 0x50) + 0x18));
            }
            else {
              osUnmapPciMemoryKernel64(lVar3);
            }
          }
        }
        else {
          (**(code **)(local_40 + 0x520))
                    (lVar3,local_40,puVar2,*(undefined8 *)(param_3 + 0x18),
                     *(undefined8 *)(*(long *)(param_3 + 0x50) + 0x18),*(code **)(local_40 + 0x520))
          ;
        }
        nvDbg_Printf("src/kernel/rmapi/mapping_cpu.c",0x318,"memUnmap_IMPL",1,
                     "NVRM: Unmapping from NVLINK handle = 0x%x, addr= 0x%llx\n",
                     *(undefined4 *)(*(long *)(*(long *)(param_1 + 0xb8) + 0x48) + 0x10),
                     *(undefined8 *)(param_3 + 0x18));
        return 0;
      }
    }
    iVar7 = memdescGetAddressSpace(puVar2);
  }
  if ((iVar7 != 1) || ((*(uint *)(param_3 + 0x10) & 0x18000) != 0x8000)) {
    iVar7 = memdescGetAddressSpace(puVar2);
    if ((iVar7 == 2) ||
       ((iVar7 = memdescGetAddressSpace(puVar2), iVar7 == 1 &&
        ((*(uint *)(param_3 + 0x10) & 0x18000) == 0x10000)))) {
      if (*(char *)(*(long *)(param_3 + 0x50) + 0x24) == '\0') {
        osUnmapPciMemoryUser
                  (*(undefined8 *)(lVar3 + 0x4e0),*(undefined8 *)(param_3 + 0x18),
                   *(undefined8 *)(param_3 + 8),*(undefined8 *)(*(long *)(param_3 + 0x50) + 0x18));
      }
      else {
        osUnmapPciMemoryKernel64(lVar3);
      }
      if (*(char *)(local_40 + 0xad04) != '\0') {
        return 0;
      }
      uVar11 = memdescGetMemDescFromGpu(*(undefined8 *)(param_1 + 0x118),lVar3);
      kbusUnmapFbAperture_GM107
                (lVar3,local_40,uVar11,**(undefined8 **)(param_3 + 0x50),
                 (*(undefined8 **)(param_3 + 0x50))[1],0x20);
      return 0;
    }
    iVar7 = memdescGetAddressSpace(puVar2);
    if (iVar7 == 4) {
      nvAssertFailedNoLog(&DAT_00d92cd1,"src/kernel/rmapi/mapping_cpu.c",0x346);
      return 0x40;
    }
    iVar7 = memdescGetAddressSpace(puVar2);
    if (iVar7 != 3) {
      return 0;
    }
    uVar11 = *(undefined8 *)(param_3 + 8);
    uVar4 = *(undefined8 *)(param_3 + 0x18);
    uVar5 = *(undefined8 *)(*(long *)(param_3 + 0x50) + 0x18);
    uVar8 = (**(code **)(*plVar10 + 0xd8))(plVar10);
    osUnmapGPU(*(undefined8 *)(lVar3 + 0x4e0),uVar8,uVar4,uVar11,uVar5);
    return 0;
  }
  lVar12 = *(long *)(param_3 + 0x50);
LAB_004a1d50:
  memdescUnmap(puVar2,*(undefined1 *)(lVar12 + 0x24),*(undefined8 *)(param_3 + 0x18),
               *(undefined8 *)(lVar12 + 0x18));
  return 0;
}


// ===== 004a2120 rmapiValidateKernelMapping =====

undefined4 rmapiValidateKernelMapping(uint param_1,uint param_2,byte *param_3)

{
  undefined4 uVar1;
  byte bVar2;
  
  if (param_1 < 2) {
    uVar1 = 0;
    if ((param_2 & 0x4000) != 0) {
      uVar1 = 0x29;
    }
    bVar2 = 0;
  }
  else {
    uVar1 = 0;
    bVar2 = (byte)((param_2 & 0x4000) >> 0xe) ^ 1;
  }
  if ((param_2 & 0x400000) != 0) {
    uVar1 = 0x29;
  }
  if (param_3 != (byte *)0x0) {
    *param_3 = bVar2;
  }
  return uVar1;
}


// ===== 004a2170 serverMap_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int serverMap_Prologue(undefined8 param_1,int *param_2)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  long *plVar7;
  uint uVar8;
  long local_48;
  long local_40 [2];
  
  uVar8 = param_2[10];
  if ((uVar8 & 0x10) != 0) {
    return 0x29;
  }
  iVar6 = *param_2;
  iVar1 = param_2[1];
  plVar7 = (long *)serverutilGetClientUnderLock(iVar6);
  if (plVar7 == (long *)0x0) {
    nvAssertFailedNoLog("pClient != NULL","src/kernel/rmapi/mapping_cpu.c",0x38d);
    return 0x23;
  }
  uVar3 = (**(code **)(*plVar7 + 0xd8))(plVar7);
  iVar4 = clientGetResourceRef_IMPL(plVar7[0x20],param_2[2],&local_48);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,
               "clientGetResourceRef(staticCast(pClient, RsClient), pMapParams->hMemory, &pMemoryRef)"
               ,"src/kernel/rmapi/mapping_cpu.c",0x393);
    return iVar4;
  }
  iVar4 = iVar6;
  if (*(long *)(local_48 + 0x18) != 0) {
    iVar4 = *(int *)(*(long *)(local_48 + 0x18) + 0x10);
  }
  uVar5 = uVar8 & 0x4000;
  if (uVar3 < 2) {
    if (uVar5 != 0) {
      if ((uVar8 & 0x400000) == 0) {
        *(undefined1 *)(param_2 + 0xc) = 0;
        return 0x29;
      }
      goto LAB_004a2303;
    }
    uVar2 = 0;
  }
  else {
    uVar5 = uVar5 >> 0xe ^ 1;
    uVar2 = (undefined1)uVar5;
  }
  if ((uVar8 & 0x400000) != 0) {
LAB_004a2303:
    *(char *)(param_2 + 0xc) = (char)uVar5;
    return 0x29;
  }
  *(undefined1 *)(param_2 + 0xc) = uVar2;
  *(uint *)(*(long *)(param_2 + 0xe) + 0x28) = *(uint *)(*(long *)(param_2 + 0xe) + 0x28) | 4;
  if (iVar1 == iVar6) {
    if (iVar4 != iVar1) {
      nvAssertFailedNoLog("hParent == hClient","src/kernel/rmapi/mapping_cpu.c",0x3c0);
      return 0x36;
    }
  }
  else {
    if (iVar4 == iVar6) {
      nvAssertFailedNoLog("hParent != hClient","src/kernel/rmapi/mapping_cpu.c",0x3a5);
      return 0x36;
    }
    iVar6 = clientGetResourceRef_IMPL(plVar7[0x20],param_2[1],local_40);
    if (iVar6 != 0) {
      return iVar6;
    }
    if (*(int *)(local_40[0] + 0x118) == 0xe0ac20) {
      *(uint *)(*(long *)(param_2 + 0xe) + 0x28) = *(uint *)(*(long *)(param_2 + 0xe) + 0x28) | 8;
      *(long *)(*(long *)(param_2 + 0xe) + 0x10) = local_40[0];
    }
    else {
      if (*(int *)(local_40[0] + 0x118) != 0x4b01b3) {
        return 0x36;
      }
      iVar6 = param_2[1];
      param_2[1] = *(int *)(*(long *)(local_40[0] + 0x18) + 0x10);
      *(uint *)(*(long *)(param_2 + 0xe) + 0x28) = *(uint *)(*(long *)(param_2 + 0xe) + 0x28) | 8;
      *(long *)(*(long *)(param_2 + 0xe) + 0x10) = local_40[0];
      if (iVar6 != 0) goto LAB_004a22b0;
    }
  }
  iVar6 = param_2[1];
LAB_004a22b0:
  uVar8 = uVar8 & 3;
  param_2[0xd] = iVar6;
  if (uVar8 == 1) {
    param_2[0xb] = 1;
    return 0;
  }
  if (uVar8 != 2) {
    if (uVar8 != 0) {
      return 0x29;
    }
    param_2[0xb] = 3;
    return 0;
  }
  param_2[0xb] = 2;
  return 0;
}


// ===== 004a24c0 serverUnmap_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int serverUnmap_Prologue(undefined8 param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  long *plVar9;
  code *pcVar10;
  undefined1 local_59;
  undefined8 local_58;
  long local_50;
  undefined8 local_48;
  long local_40 [2];
  
  iVar8 = *param_2;
  iVar2 = param_2[7];
  iVar6 = param_2[2];
  local_58 = 0;
  local_48 = 0;
  iVar3 = param_2[1];
  plVar9 = (long *)serverutilGetClientUnderLock(iVar8);
  if (plVar9 == (long *)0x0) {
    nvAssertFailedNoLog("pClient != NULL","src/kernel/rmapi/mapping_cpu.c",0x3f2);
    return 0x23;
  }
  uVar5 = (**(code **)(*plVar9 + 0xd8))(plVar9);
  iVar6 = clientGetResourceRef_IMPL(plVar9[0x20],iVar6,&local_50);
  if (iVar6 != 0) {
    nvAssertOkFailedNoLog
              (iVar6,"clientGetResourceRef(staticCast(pClient, RsClient), hMemory, &pMemoryRef)",
               "src/kernel/rmapi/mapping_cpu.c",0x3f8);
    return iVar6;
  }
  lVar4 = *(long *)(param_2 + 0xe);
  uVar7 = *(uint *)(lVar4 + 0x28) | 4;
  if (*(long *)(local_50 + 0x18) == 0) {
    *(uint *)(lVar4 + 0x28) = uVar7;
    if (iVar3 != iVar8) {
LAB_004a2658:
      nvAssertFailedNoLog("hParent != hClient","src/kernel/rmapi/mapping_cpu.c",0x405);
      return 0x36;
    }
  }
  else {
    iVar6 = *(int *)(*(long *)(local_50 + 0x18) + 0x10);
    *(uint *)(lVar4 + 0x28) = uVar7;
    if (iVar3 == iVar8) {
      if (iVar3 != iVar6) {
        nvAssertFailedNoLog("hParent == hClient","src/kernel/rmapi/mapping_cpu.c",0x41e);
        return 0x36;
      }
    }
    else {
      if (iVar8 == iVar6) goto LAB_004a2658;
      iVar8 = clientGetResourceRef_IMPL(plVar9[0x20],param_2[1],local_40);
      if (iVar8 != 0) {
        return iVar8;
      }
      if (*(int *)(local_40[0] + 0x118) == 0x4b01b3) {
        param_2[1] = *(int *)(*(long *)(local_40[0] + 0x18) + 0x10);
      }
      else if (*(int *)(local_40[0] + 0x118) != 0xe0ac20) {
        return 0x36;
      }
      *(uint *)(*(long *)(param_2 + 0xe) + 0x28) = *(uint *)(*(long *)(param_2 + 0xe) + 0x28) | 8;
      *(long *)(*(long *)(param_2 + 0xe) + 0x10) = local_40[0];
      iVar8 = gpuGetByRef(*(undefined8 *)(*(long *)(param_2 + 0xe) + 0x10),&local_59,&local_58);
      if (iVar8 != 0) {
        nvAssertOkFailedNoLog
                  (iVar8,"gpuGetByRef(pUnmapParams->pLockInfo->pContextRef, &bBroadcast, &pGpu)",
                   "src/kernel/rmapi/mapping_cpu.c",0x419);
        return iVar8;
      }
    }
  }
  if ((uVar5 < 2) || ((*(byte *)((long)param_2 + 0x19) & 0x40) != 0)) {
    iVar8 = osGetCurrentProcess();
    if (iVar8 == iVar2) {
      cVar1 = (char)param_2[8];
    }
    else {
      iVar8 = osAttachToProcess(&local_48,iVar2);
      cVar1 = (char)param_2[8];
      if (iVar8 != 0) {
        if (cVar1 == '\0') {
          return iVar8;
        }
        param_2[10] = 0;
        param_2[0xb] = 0;
        goto LAB_004a26cd;
      }
      *(undefined8 *)(param_2 + 10) = local_48;
    }
    if (cVar1 == '\0') {
      pcVar10 = serverutilMappingFilterCurrentUserProc;
      goto LAB_004a2605;
    }
  }
  else {
    pcVar10 = serverutilMappingFilterKernel;
    if ((char)param_2[8] == '\0') {
LAB_004a2605:
      *(code **)(param_2 + 0xc) = pcVar10;
      return 0;
    }
  }
LAB_004a26cd:
  param_2[0xc] = 0;
  param_2[0xd] = 0;
  return 0;
}


// ===== 004a27a0 serverUnmap_Epilogue =====

void serverUnmap_Epilogue(undefined8 param_1,long param_2)

{
  if (*(long *)(param_2 + 0x28) != 0) {
    osDetachFromProcess();
    *(undefined8 *)(param_2 + 0x28) = 0;
    return;
  }
  return;
}


// ===== 004a27e0 rmapiMapToCpu =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 rmapiMapToCpu(long param_1)

{
  undefined8 uVar1;
  undefined8 *in_stack_00000008;
  
  uVar1 = 0x56;
  if (*(char *)(param_1 + 0xd8) != '\0') {
    uVar1 = (**(code **)(param_1 + 0x78))();
    if (in_stack_00000008 != (undefined8 *)0x0) {
      *in_stack_00000008 = 0;
    }
  }
  return uVar1;
}


// ===== 004a2840 rmapiMapToCpuWithSecInfoV2 =====

int rmapiMapToCpuWithSecInfoV2
              (undefined8 param_1,undefined4 param_2,undefined8 param_3,ulong param_4,
              undefined8 param_5,undefined8 param_6,undefined8 *param_7,undefined4 *param_8,
              undefined8 param_9)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_c4;
  undefined1 local_c0 [40];
  uint local_98;
  uint local_94;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 *local_60;
  undefined4 local_58;
  undefined1 *local_48;
  undefined8 local_40;
  
  local_c4 = 0;
  nvDbg_Printf("src/kernel/rmapi/mapping_cpu.c",0x4aa,"rmapiMapToCpuWithSecInfoV2",1,
               "NVRM: Nv04MapMemory: client:0x%x device:0x%x memory:0x%x\n",param_2,param_3,param_4)
  ;
  nvDbg_Printf("src/kernel/rmapi/mapping_cpu.c",0x4ad,"rmapiMapToCpuWithSecInfoV2",1,
               "NVRM: Nv04MapMemory:  offset: %llx length: %llx flags:0x%x\n",param_5,param_6,
               *param_8);
  iVar2 = rmapiPrologue(param_1,&local_c4);
  if (iVar2 == 0) {
    nvDbg_Printf("src/kernel/rmapi/mapping_cpu.c",0x4b5,"rmapiMapToCpuWithSecInfoV2",1,
                 "NVRM: MMU_PROFILER Nv04MapMemory 0x%x\n",*param_8);
    portMemSet(local_c0,0,0x40);
    iVar2 = rmapiInitLockInfo(param_1,param_2,0,local_c0);
    if (iVar2 == 0) {
      cVar1 = rmapiInRtd3PmPath();
      if (cVar1 != '\0') {
        local_98 = local_98 | 1;
        local_94 = local_94 & 0xfffffffe;
      }
      portMemSet(&local_80,0,0x48);
      local_78 = (undefined4)param_4;
      local_7c = (undefined4)param_3;
      local_60 = param_7;
      local_58 = *param_8;
      local_48 = local_c0;
      local_40 = param_9;
      local_80 = param_2;
      local_70 = param_5;
      local_68 = param_6;
      iVar2 = serverMap(g_resServ,param_2,param_4 & 0xffffffff,&local_80);
      rmapiEpilogue(param_1,&local_c4);
      *param_8 = local_58;
      if (iVar2 == 0) {
        nvDbg_Printf("src/kernel/rmapi/mapping_cpu.c",0x4e2,"rmapiMapToCpuWithSecInfoV2",1,
                     "NVRM: Nv04MapMemory: complete\n");
        nvDbg_Printf("src/kernel/rmapi/mapping_cpu.c",0x4e3,"rmapiMapToCpuWithSecInfoV2",1,
                     "NVRM: Nv04MapMemory:  *ppCpuVirtAddr:%p\n",*param_7);
      }
      else {
        uVar3 = nvstatusToString(iVar2);
        nvDbg_Printf("src/kernel/rmapi/mapping_cpu.c",0x4e9,"rmapiMapToCpuWithSecInfoV2",3,
                     "NVRM: Nv04MapMemory: map failed; status: %s (0x%08x)\n",uVar3,iVar2);
      }
    }
    else {
      rmapiEpilogue(param_1,&local_c4);
    }
  }
  return iVar2;
}


// ===== 004a2ad0 rmapiMapToCpuWithSecInfo =====

void rmapiMapToCpuWithSecInfo(void)

{
  rmapiMapToCpuWithSecInfoV2();
  return;
}


// ===== 004a2af0 rmapiMapToCpuWithSecInfoTls =====

undefined4
rmapiMapToCpuWithSecInfoTls
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
          undefined8 param_9)

{
  undefined4 uVar1;
  undefined1 local_a8 [144];
  
  threadStateInit(local_a8,0);
  uVar1 = rmapiMapToCpuWithSecInfoV2
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,&param_8,param_9);
  threadStateFree(local_a8,0);
  return uVar1;
}


// ===== 004a2b90 rmapiMapToCpuWithSecInfoTlsV2 =====

undefined4
rmapiMapToCpuWithSecInfoTlsV2
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
          undefined8 param_9)

{
  undefined4 uVar1;
  undefined1 local_a8 [144];
  
  threadStateInit(local_a8,0);
  uVar1 = rmapiMapToCpuWithSecInfoV2
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  threadStateFree(local_a8,0);
  return uVar1;
}


// ===== 004a2c30 rmapiUnmapFromCpu =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1  [16] rmapiUnmapFromCpu(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined4 in_stack_00000008;
  
  if (*(char *)(param_1 + 0xd8) != '\0') {
    auVar1._0_8_ = (**(code **)(param_1 + 0x90))();
    auVar1._8_4_ = in_stack_00000008;
    auVar1._12_4_ = 0;
    return auVar1;
  }
  auVar2._8_8_ = param_3;
  auVar2._0_8_ = 0x56;
  return auVar2;
}


// ===== 004a2c70 rmapiUnmapFromCpuWithSecInfo =====

int rmapiUnmapFromCpuWithSecInfo
              (undefined8 param_1,undefined4 param_2,undefined8 param_3,ulong param_4,
              undefined8 param_5,undefined8 param_6,undefined4 param_7,undefined8 param_8)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_c4;
  undefined1 local_c0 [64];
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 *local_48;
  undefined8 local_40;
  
  local_c4 = 0;
  nvDbg_Printf("src/kernel/rmapi/mapping_cpu.c",0x569,"rmapiUnmapFromCpuWithSecInfo",1,
               "NVRM: Nv04UnmapMemory: client:0x%x device:0x%x memory:0x%x pLinearAddr:%p flags:0x%x\n"
               ,param_2,param_3,param_4,param_5,param_6);
  iVar1 = rmapiPrologue(param_1,&local_c4);
  if (iVar1 == 0) {
    portMemSet(local_c0,0,0x40);
    iVar2 = rmapiInitLockInfo(param_1,param_2,0,local_c0);
    if (iVar2 == 0) {
      portMemSet(&local_80,0,0x48);
      local_78 = (undefined4)param_4;
      local_7c = (undefined4)param_3;
      local_64 = param_7;
      local_48 = local_c0;
      local_68 = (undefined4)param_6;
      local_40 = param_8;
      local_80 = param_2;
      local_70 = param_5;
      iVar1 = serverUnmap(g_resServ,param_2,param_4 & 0xffffffff,&local_80);
      rmapiEpilogue(param_1,&local_c4);
      if (iVar1 == 0) {
        nvDbg_Printf("src/kernel/rmapi/mapping_cpu.c",0x58b,"rmapiUnmapFromCpuWithSecInfo",1,
                     "NVRM: Nv04UnmapMemory: unmap complete\n");
      }
      else {
        uVar3 = nvstatusToString(iVar1);
        nvDbg_Printf("src/kernel/rmapi/mapping_cpu.c",0x58f,"rmapiUnmapFromCpuWithSecInfo",3,
                     "NVRM: Nv04UnmapMemory: unmap failed; status: %s (0x%08x)\n",uVar3,iVar1);
      }
    }
    else {
      rmapiEpilogue(param_1,&local_c4);
    }
  }
  return iVar1;
}


// ===== 004a2e40 rmapiUnmapFromCpuWithSecInfoTls =====

undefined4
rmapiUnmapFromCpuWithSecInfoTls
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined8 param_5,undefined4 param_6,undefined4 param_7,undefined8 param_8)

{
  undefined4 uVar1;
  undefined1 local_a8 [144];
  
  threadStateInit(local_a8,0);
  uVar1 = rmapiUnmapFromCpuWithSecInfo
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  threadStateFree(local_a8,0);
  return uVar1;
}


// ===== 004a2ed0 serverMapLookupLockFlags =====

undefined8
serverMapLookupLockFlags(undefined8 param_1,undefined8 param_2,undefined8 param_3,uint *param_4)

{
  char cVar1;
  
  if (param_4 != (uint *)0x0) {
    cVar1 = serverSupportsReadOnlyLock(param_1,param_2,3);
    *param_4 = (uint)(cVar1 == '\0');
    return 0;
  }
  nvAssertFailedNoLog("pAccess != NULL","src/kernel/rmapi/mapping_cpu.c",0x5ba);
  return 0x1f;
}


// ===== 004a2f30 serverUnmapLookupLockFlags =====

undefined8
serverUnmapLookupLockFlags(undefined8 param_1,undefined8 param_2,undefined8 param_3,uint *param_4)

{
  char cVar1;
  
  if (param_4 != (uint *)0x0) {
    cVar1 = serverSupportsReadOnlyLock(param_1,param_2,4);
    *param_4 = (uint)(cVar1 == '\0');
    return 0;
  }
  nvAssertFailedNoLog("pAccess != NULL","src/kernel/rmapi/mapping_cpu.c",0x5cb);
  return 0x1f;
}


// ===== 004a2f90 refAllocCpuMappingPrivate =====

undefined8 refAllocCpuMappingPrivate(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = portMemAllocNonPaged(0x38);
  *(long *)(param_2 + 0x50) = lVar1;
  if (lVar1 != 0) {
    *(undefined4 *)(lVar1 + 0x20) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined1 *)(*(long *)(param_2 + 0x50) + 0x24) = *(undefined1 *)(param_1 + 0x30);
    return 0;
  }
  return 0x51;
}


// ===== 004a2fe0 refFreeCpuMappingPrivate =====

void refFreeCpuMappingPrivate(long param_1)

{
  portMemFree(*(undefined8 *)(param_1 + 0x50));
  return;
}


// ===== 004a2ff0 CliFindMappingInClient =====

long CliFindMappingInClient(undefined4 param_1,undefined4 param_2,ulong param_3)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 local_288 [280];
  undefined8 local_170;
  undefined8 local_168;
  long local_160 [4];
  undefined1 local_140 [256];
  long local_40;
  
  iVar3 = serverGetClientUnderLock(g_resServ,param_1,&local_170);
  if ((iVar3 == 0) && (iVar3 = clientGetResourceRef_IMPL(local_170,param_2,&local_168), iVar3 == 0))
  {
    lVar4 = resservGetTlsCallContext();
    if (lVar4 == 0) {
      nvAssertFailedNoLog("pCallContext != NULL","src/kernel/rmapi/mapping_list.c",0x44);
    }
    else {
      uVar1 = *(uint *)(lVar4 + 0x28);
      iVar3 = osGetCurrentProcess();
      clientRefOrderedIter(local_288,local_170,local_168,0x4789f2,0);
      memcpy(local_140,local_288,0x108);
      while (cVar2 = clientRefOrderedIterNext(local_170,local_140), cVar2 != '\0') {
        lVar4 = local_40 + 0x128;
        uVar5 = listTail_IMPL(lVar4);
        uVar6 = listHead_IMPL(lVar4);
        listIterRange_IMPL(local_160,lVar4,uVar6,uVar5);
        while (cVar2 = listIterNext_IMPL(local_160), cVar2 != '\0') {
          if ((((bool)*(char *)(*(long *)(local_160[0] + 0x50) + 0x24) == 1 < uVar1) &&
              (((1 < uVar1 || (*(int *)(local_160[0] + 0x48) == iVar3)) &&
               (*(long *)(*(long *)(local_160[0] + 0x50) + 8) != 0)))) &&
             ((*(ulong *)(local_160[0] + 0x18) <= param_3 &&
              (param_3 < *(ulong *)(local_160[0] + 0x18) + *(long *)(local_160[0] + 8))))) {
            return local_160[0];
          }
        }
      }
    }
  }
  return 0;
}


// ===== 004a31b0 intermapCreateDmaMapping.cold =====

void intermapCreateDmaMapping_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004a31c0 intermapCreateDmaMapping =====

undefined8
intermapCreateDmaMapping
          (undefined8 param_1,long param_2,undefined8 *param_3,undefined4 param_4,undefined4 param_5
          )

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  long local_40 [2];
  
  local_40[0] = 0;
  if ((param_2 != 0) &&
     (lVar3 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Memory), *(long *)(lVar3 + 0x118) != 0)) {
    if (*(long *)(lVar3 + 0xe0) == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    iVar2 = vaspaceGetByHandleOrDeviceDefault_IMPL
                      (param_1,*(undefined4 *)
                                (*(long *)(*(long *)(*(long *)(lVar3 + 0xe0) + 0x110) + 0x48) + 0x10
                                ),*(undefined4 *)(param_2 + 0x260),local_40);
    if (iVar2 == 0) {
      puVar4 = (undefined8 *)portMemAllocNonPaged(0x118);
      if (puVar4 == (undefined8 *)0x0) {
        return 0x1a;
      }
      portMemSet(puVar4,0,0x118);
      *puVar4 = 0;
      *(undefined1 *)(puVar4 + 0x1c) = 0;
      *(undefined4 *)(puVar4 + 0x1b) = param_4;
      *(undefined4 *)((long)puVar4 + 0xdc) = param_5;
      puVar4[0x1f] = *(undefined8 *)(local_40[0] + 0x50);
      *param_3 = puVar4;
      return 0;
    }
  }
  return 0x1f;
}


// ===== 004a3300 intermapRegisterDmaMapping =====

int intermapRegisterDmaMapping
              (undefined8 param_1,long param_2,long *param_3,ulong param_4,undefined4 param_5)

{
  uint uVar1;
  long *plVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  long *plVar6;
  uint uVar7;
  long lVar8;
  long *local_30;
  
  *(undefined4 *)((long)param_3 + 0xe4) = param_5;
  if ((*(byte *)((long)param_3 + 0xdb) & 0x20) == 0) {
    lVar8 = 1;
    if (*(long *)param_3[0x1a] != 0) {
      lVar8 = param_3[0x1f];
      uVar4 = memdescGetMemDescFromGpu();
      lVar5 = memdescGetPageSize(uVar4,lVar8);
      lVar8 = 1;
      if (lVar5 != 0) {
        lVar8 = lVar5;
      }
    }
    local_30 = (long *)portMemAllocNonPaged(0x38);
    if (local_30 == (long *)0x0) {
      iVar3 = 0x1a;
    }
    else {
      portMemSet(local_30,0,0x38);
      local_30[1] = -lVar8 & param_4;
      lVar5 = *(long *)(param_3[0x1a] + 0x30);
      *local_30 = (long)param_3;
      local_30[2] = (lVar5 + -1 + param_4 + lVar8 & -lVar8) - 1;
      iVar3 = btreeInsert(local_30,param_2 + 0x268);
      if (iVar3 != 0) {
        nvDbg_Printf("src/kernel/rmapi/mapping_list.c",0x117,"intermapRegisterDmaMapping",4,
                     "NVRM: Failed to insert new mapping node for range 0x%llX-0x%llX!\n",
                     local_30[1],local_30[2]);
        portMemFree(local_30);
      }
    }
  }
  else {
    iVar3 = btreeSearch(param_4,&local_30,*(undefined8 *)(param_2 + 0x268));
    if (iVar3 == 0) {
      plVar2 = (long *)*local_30;
      if ((*plVar2 == *param_3) &&
         (*(long *)(plVar2[0x1a] + 0x30) == *(long *)(param_3[0x1a] + 0x30))) {
        uVar7 = *(uint *)((long)plVar2 + 0xe4);
        if ((uVar7 - 1 & uVar7) == 0) {
          uVar1 = *(uint *)((long)param_3 + 0xe4);
          plVar6 = plVar2;
          if ((uVar1 - 1 & uVar1) == 0) {
            while ((uVar7 & uVar1) == 0) {
              plVar6 = (long *)plVar6[0x22];
              if (plVar6 == (long *)0x0) {
                param_3[0x22] = (long)plVar2;
                *local_30 = (long)param_3;
                return 0;
              }
              uVar7 = *(uint *)((long)plVar6 + 0xe4);
            }
            nvCheckFailedNoLog(4,"(pDmaMapping->gpuMask & pDmaMappingCurrent->gpuMask) == 0",
                               "src/kernel/rmapi/mapping_list.c",200);
          }
          else {
            nvCheckFailedNoLog(4,"(pDmaMapping->gpuMask & (pDmaMapping->gpuMask - 1)) == 0",
                               "src/kernel/rmapi/mapping_list.c",0xc4);
          }
        }
        else {
          nvCheckFailedNoLog(4,"(pDmaMappingFirst->gpuMask & (pDmaMappingFirst->gpuMask - 1)) == 0",
                             "src/kernel/rmapi/mapping_list.c",0xc3);
        }
      }
      else {
        nvCheckFailedNoLog(4,
                           "pDmaMappingFirst->DmaOffset == pDmaMapping->DmaOffset && pDmaMappingFirst->pMemDesc->Size == pDmaMapping->pMemDesc->Size"
                           ,"src/kernel/rmapi/mapping_list.c",0xbe);
      }
      iVar3 = 0x1f;
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar3,"btreeSearch(dmaOffset, &pNode, pVirtualMemory->pDmaMappingList)",
                 "src/kernel/rmapi/mapping_list.c",0xbb);
    }
  }
  return iVar3;
}


// ===== 004a35e0 intermapDelDmaMapping =====

int intermapDelDmaMapping(undefined8 param_1,long param_2,undefined8 param_3,uint param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long *local_20;
  
  iVar2 = btreeSearch(param_3,&local_20,*(undefined8 *)(param_2 + 0x268));
  if (iVar2 != 0) {
    nvAssertOkFailedNoLog
              (iVar2,"btreeSearch(dmaOffset, &pNode, pVirtualMemory->pDmaMappingList)",
               "src/kernel/rmapi/mapping_list.c",0x130);
    return iVar2;
  }
  if (*local_20 != 0) {
    lVar1 = *local_20;
    lVar4 = 0;
    do {
      lVar3 = lVar1;
      lVar1 = *(long *)(lVar3 + 0x110);
      if ((*(uint *)(lVar3 + 0xe4) & param_4) != 0) {
        if (*(uint *)(lVar3 + 0xe4) == param_4) {
          if (lVar4 == 0) {
            if (lVar1 == 0) {
              iVar2 = btreeUnlink(local_20,param_2 + 0x268);
              if (iVar2 != 0) {
                nvAssertOkFailedNoLog
                          (iVar2,"btreeUnlink(pNode, &pVirtualMemory->pDmaMappingList)",
                           "src/kernel/rmapi/mapping_list.c",0x146);
                return iVar2;
              }
              portMemFree(local_20);
            }
            else {
              *local_20 = lVar1;
            }
          }
          else {
            *(long *)(lVar4 + 0x110) = lVar1;
          }
          portMemFree(lVar3);
          iVar2 = 0;
        }
        else {
          nvAssertFailedNoLog("pDmaMapping->gpuMask == gpuMask","src/kernel/rmapi/mapping_list.c",
                              0x139);
          iVar2 = 0x1f;
        }
        return iVar2;
      }
      lVar4 = lVar3;
    } while (lVar1 != 0);
  }
  nvAssertFailedNoLog(&DAT_00d9367d,"src/kernel/rmapi/mapping_list.c",0x152);
  return 0x57;
}


// ===== 004a3780 intermapFreeDmaMapping =====

void intermapFreeDmaMapping(long param_1)

{
  if (param_1 != 0) {
    portMemFree();
    return;
  }
  nvAssertFailedNoLog("pDmaMapping != NULL","src/kernel/rmapi/mapping_list.c",0x15c);
  portMemFree(0);
  return;
}


// ===== 004a37c0 intermapGetDmaMapping =====

long intermapGetDmaMapping(long param_1,undefined8 param_2,uint param_3)

{
  long lVar1;
  int iVar2;
  long *local_20 [2];
  
  iVar2 = btreeSearch(param_2,local_20,*(undefined8 *)(param_1 + 0x268));
  if (iVar2 == 0) {
    for (lVar1 = *local_20[0]; (lVar1 != 0 && ((*(uint *)(lVar1 + 0xe4) & param_3) == 0));
        lVar1 = *(long *)(lVar1 + 0x110)) {
    }
    return lVar1;
  }
  return 0;
}


// ===== 004a3840 CliGetDmaMappingInfo =====

undefined8
CliGetDmaMappingInfo
          (long param_1,undefined4 param_2,int param_3,undefined8 param_4,uint param_5,long *param_6
          )

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long local_50;
  undefined8 *local_48;
  long *local_40 [2];
  
  if (param_3 != 0) {
    iVar2 = clientGetResourceRef_IMPL(param_1,param_3,&local_48);
    if (iVar2 != 0) {
      return 0;
    }
    lVar3 = __nvoc_dynamicCast(local_48[1],__nvoc_class_def_VirtualMemory);
    if (lVar3 != 0) {
      iVar2 = btreeSearch(param_4,local_40,*(undefined8 *)(lVar3 + 0x268));
      uVar4 = 0;
      if (iVar2 == 0) {
        lVar3 = *local_40[0];
        if (lVar3 != 0) {
          do {
            if ((*(uint *)(lVar3 + 0xe4) & param_5) != 0) {
              uVar4 = 1;
              goto LAB_004a39da;
            }
            lVar3 = *(long *)(lVar3 + 0x110);
          } while (lVar3 != 0);
          uVar4 = 0;
        }
      }
      else {
        lVar3 = 0;
      }
LAB_004a39da:
      *param_6 = lVar3;
      return uVar4;
    }
  }
  iVar2 = deviceGetByHandle_IMPL(param_1,param_2,&local_50);
  if (iVar2 == 0) {
    btreeEnumStart(0,&local_48,*(undefined8 *)(local_50 + 0x188));
    while (local_48 != (undefined8 *)0x0) {
      lVar3 = __nvoc_dynamicCast(*local_48,__nvoc_class_def_VirtualMemory);
      btreeEnumNext(&local_48,*(undefined8 *)(local_50 + 0x188));
      if ((lVar3 != 0) &&
         (cVar1 = virtmemMatchesVASpace_IMPL(lVar3,*(undefined4 *)(param_1 + 0x48),param_3),
         cVar1 != '\0')) {
        iVar2 = btreeSearch(param_4,local_40,*(undefined8 *)(lVar3 + 0x268));
        if (iVar2 == 0) {
          for (lVar3 = *local_40[0]; lVar3 != 0; lVar3 = *(long *)(lVar3 + 0x110)) {
            if ((*(uint *)(lVar3 + 0xe4) & param_5) != 0) {
              *param_6 = lVar3;
              return 1;
            }
          }
        }
        *param_6 = 0;
      }
    }
  }
  return 0;
}


// ===== 004a3a00 nvGpuOpsRmSmcPartitionDestroy =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void nvGpuOpsRmSmcPartitionDestroy(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_1 + 8);
  if (*(long *)(lVar1 + 0x50) != 0) {
    lVar2 = rmapiGetInterface(1);
    (**(code **)(lVar2 + 0x18))
              (lVar2,**(undefined4 **)(param_1 + 0x48),*(undefined4 *)(lVar1 + 0x48),
               *(code **)(lVar2 + 0x18));
    *(undefined8 *)(lVar1 + 0x50) = 0;
  }
  return;
}


// ===== 004a3a50 eccErrorCallback =====

void eccErrorCallback(long param_1)

{
  if (param_1 != 0) {
    *(undefined1 *)(param_1 + 0x72) = 1;
    return;
  }
  nvAssertFailedNoLog("rmSubDevice","src/kernel/rmapi/nv_gpu_ops.c",0x347);
  uRam0000000000000072 = 1;
  return;
}


// ===== 004a3a90 nvlinkErrorCallback =====

void nvlinkErrorCallback(long param_1)

{
  if (param_1 != 0) {
    *(undefined1 *)(param_1 + 0xa2) = 1;
    return;
  }
  nvAssertFailedNoLog("rmSubDevice","src/kernel/rmapi/nv_gpu_ops.c",0x351);
  uRam00000000000000a2 = 1;
  return;
}


// ===== 004a3ae0 nvGpuOpsAllocPhysical =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsAllocPhysical
              (long param_1,char param_2,undefined8 param_3,undefined8 *param_4,undefined8 *param_5)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined8 *puVar4;
  code *pcVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined4 local_ac;
  undefined8 local_a8;
  uint local_a0 [2];
  undefined8 uStack_98;
  uint local_90;
  uint local_8c;
  undefined8 local_68;
  undefined8 local_58;
  undefined4 local_3c;
  
  uVar2 = 0;
  do {
    uVar6 = (ulong)uVar2;
    uVar2 = uVar2 + 0x20;
    *(undefined8 *)((long)&local_a8 + uVar6) = 0;
    *(undefined8 *)((long)local_a0 + uVar6) = 0;
    *(undefined8 *)((long)&uStack_98 + uVar6) = 0;
    *(undefined8 *)((long)&local_90 + uVar6) = 0;
  } while (uVar2 < 0x80);
  puVar4 = (undefined8 *)rmapiGetInterface(1);
  local_ac = 0;
  if (param_1 == 0) {
    nvAssertFailedNoLog("device","src/kernel/rmapi/nv_gpu_ops.c",0x1320);
  }
  local_3c = 0;
  local_a8 = 0xdeaf0004;
  local_58 = 0;
  local_90 = (uint)(*(char *)(param_5 + 3) != '\0') << 0x1c |
             -(uint)(param_2 != '\0') & 0x20000000 | -(uint)(param_2 != '\0') & 0x2000000;
  uVar6 = param_5[1];
  if (uVar6 == 0x200000) {
    local_8c = local_8c | 0x100000;
    local_90 = local_90 | 0x1800000;
  }
  else if (uVar6 < 0x200001) {
    if ((uVar6 - 0x10000 & 0xfffffffffffeffff) == 0) {
      local_90 = local_90 | 0x1000000;
    }
    else if (uVar6 == 0x1000) {
      local_90 = local_90 | 0x800000;
    }
  }
  else if (uVar6 == 0x20000000) {
    local_8c = local_8c | 0x200000;
    local_90 = local_90 | 0x1800000;
  }
  else if (uVar6 == 0x4000000000) {
    local_8c = local_8c | 0x300000;
    local_90 = local_90 | 0x1800000;
  }
  if (*(char *)((long)param_5 + 0x19) != '\0') {
    local_a0[0] = local_a0[0] | 4;
  }
  if (param_2 == '\0') {
    if (*(char *)((long)param_5 + 0x1a) != '\0') {
      local_a0[0] = local_a0[0] | 0x10000;
    }
    if (*(char *)(param_5 + 4) != '\0') {
      local_8c = local_8c & 0xf9ffffff | 0x4000000;
    }
    pcVar5 = (code *)*puVar4;
    uVar1 = *(undefined4 *)(param_1 + 0x14);
    uVar7 = 0x40;
  }
  else {
    if (*(char *)(param_5 + 4) == '\0') {
      pcVar5 = (code *)*puVar4;
    }
    else {
      local_8c = local_8c & 0xf9ffffff | 0x4000000;
      pcVar5 = (code *)*puVar4;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    uVar7 = 0x3e;
  }
  local_ac = 0;
  local_68 = param_3;
  iVar3 = (*pcVar5)(puVar4,**(undefined4 **)(param_1 + 0x48),uVar1,&local_ac,uVar7,&local_a8,0x80);
  if (iVar3 == 0) {
    if (*(char *)(param_5 + 3) == '\0') {
      local_58 = *param_5;
    }
    else {
      *param_5 = local_58;
    }
    *(undefined4 *)((long)param_5 + 0x1c) = local_ac;
    *param_4 = local_58;
    return 0;
  }
  nvAssertOkFailedNoLog
            (iVar3,
             "pRmApi->Alloc(pRmApi, device->session->handle, isSystemMemory ? device->handle : device->subhandle, &physHandle, isSystemMemory ? NV01_MEMORY_SYSTEM : NV01_MEMORY_LOCAL_USER, &memAllocParams, sizeof(memAllocParams))"
             ,"src/kernel/rmapi/nv_gpu_ops.c",0x136f);
  (*(code *)puVar4[3])(puVar4,**(undefined4 **)(param_1 + 0x48),local_ac);
  return iVar3;
}


// ===== 004a3e50 gpuDeviceUnmapCpuFreeHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gpuDeviceUnmapCpuFreeHandle(long param_1,int param_2,long param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  
  lVar3 = rmapiGetInterface(1);
  puVar1 = *(undefined4 **)(param_1 + 0x48);
  if (param_3 != 0) {
    uVar4 = osGetCurrentProcess();
    iVar2 = (**(code **)(lVar3 + 0x88))
                      (lVar3,*puVar1,*(undefined4 *)(param_1 + 0x14),param_2,param_3,param_4,uVar4);
    if (iVar2 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0x1593,0x4a3e87);
    }
  }
  if (param_2 != 0) {
    (**(code **)(lVar3 + 0x18))(lVar3,*puVar1,param_2);
    return;
  }
  return;
}


// ===== 004a3f10 allocNvlinkStatus =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int allocNvlinkStatus(undefined4 param_1,undefined4 param_2,long *param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  
  lVar2 = rmapiGetInterface(1);
  *param_3 = 0;
  lVar3 = portMemAllocNonPaged(0x3628);
  if (lVar3 == 0) {
    iVar1 = 0x51;
  }
  else {
    portMemSet(lVar3,0,0x3628);
    iVar1 = (**(code **)(lVar2 + 0x38))(lVar2,param_1,param_2,0x20803002,lVar3,0x3628);
    if (iVar1 == 0x56) {
      portMemSet(lVar3,0,0x3628);
    }
    else if (iVar1 != 0) {
      portMemFree(lVar3);
      uVar4 = nvstatusToString(iVar1);
      nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0xabe,"allocNvlinkStatus",4,"NVRM: %s:%d: %s\n",
                   "allocNvlinkStatus",0xabe,uVar4);
      return iVar1;
    }
    *param_3 = lVar3;
    iVar1 = 0;
  }
  return iVar1;
}


// ===== 004a4040 rmSystemP2PCapsControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int rmSystemP2PCapsControl(long param_1,long param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  
  lVar3 = rmapiGetInterface(param_4);
  portMemSet(param_3,0,0x209c);
  *param_3 = *(undefined4 *)(param_1 + 0x20);
  uVar1 = *(undefined4 *)(param_2 + 0x20);
  param_3[0x20] = 2;
  param_3[1] = uVar1;
  iVar2 = (**(code **)(lVar3 + 0x38))
                    (lVar3,**(undefined4 **)(param_1 + 0x48),**(undefined4 **)(param_1 + 0x48),299,
                     param_3,0x209c);
  if (iVar2 == 0) {
    return 0;
  }
  uVar4 = nvstatusToString(iVar2);
  nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0xbb1,"rmSystemP2PCapsControl",4,"NVRM: %s:%d: %s\n",
               "rmSystemP2PCapsControl",0xbb1,uVar4);
  return iVar2;
}


// ===== 004a4110 getSystemP2PCaps =====

int getSystemP2PCaps(long param_1,long param_2,undefined4 *param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  
  lVar4 = portMemAllocNonPaged(0x209c);
  if (lVar4 == 0) {
    iVar2 = 0x51;
  }
  else {
    iVar2 = rmSystemP2PCapsControl(param_1,param_2,lVar4,param_4);
    if (iVar2 == 0) {
      portMemSet(param_3,0,0x1c);
      *param_3 = *(undefined4 *)(lVar4 + 0xa0);
      param_3[1] = *(undefined4 *)(lVar4 + 0xa4);
      param_3[2] = *(undefined4 *)(lVar4 + 0x10a0);
      param_3[3] = *(undefined4 *)(lVar4 + 0x10a4);
      bVar1 = *(byte *)(param_3 + 4);
      bVar5 = *(byte *)(lVar4 + 0x84) >> 2 & 2;
      *(byte *)(param_3 + 4) = bVar1 & 0xfd | bVar5;
      bVar6 = *(byte *)(lVar4 + 0x84) >> 2 & 4;
      *(byte *)(param_3 + 4) = bVar1 & 0xf9 | bVar5 | bVar6;
      bVar1 = bVar1 & 0xf1 | bVar5 | bVar6 | *(byte *)(lVar4 + 0x85) >> 2 & 8;
      *(byte *)(param_3 + 4) = bVar1;
      if ((~*(uint *)(lVar4 + 0x84) & 3) == 0) {
        *(byte *)(param_3 + 4) = bVar1 | 1;
      }
      if ((*(byte *)(param_3 + 4) & 2) != 0) {
        uVar7 = *(uint *)(lVar4 + 0x8c);
        if (param_1 == param_2) {
          uVar7 = uVar7 & -uVar7;
          *(uint *)(lVar4 + 0x8c) = uVar7;
        }
        uVar3 = uVar7 - (uVar7 >> 1 & 0x55555555);
        uVar3 = (uVar3 & 0x33333333) + (uVar3 >> 2 & 0x33333333);
        if (((uVar3 >> 4) + uVar3 & 0xf0f0f0f) * 0x1010101 >> 0x18 != 1) {
          nvAssertFailedNoLog("nvPopCount32(p2pCapsParams->p2pOptimalWriteCEs) == 1",
                              "src/kernel/rmapi/nv_gpu_ops.c",0xbee);
          uVar7 = *(uint *)(lVar4 + 0x8c);
        }
        param_3[5] = (uint)((uVar7 & 0xaaaaaaaa) != 0) | (uint)(0xffff < uVar7) << 4 |
                     (uint)((uVar7 & 0xff00ff00) != 0) << 3 | (uint)((uVar7 & 0xf0f0f0f0) != 0) << 2
                     | (uint)((uVar7 & 0xcccccccc) != 0) * 2;
        iVar2 = rmSystemP2PCapsControl(param_2,param_1,lVar4,param_4);
        if (iVar2 == 0) {
          uVar7 = *(uint *)(lVar4 + 0x8c);
          if (param_1 == param_2) {
            uVar7 = uVar7 & -uVar7;
            *(uint *)(lVar4 + 0x8c) = uVar7;
          }
          uVar3 = uVar7 - (uVar7 >> 1 & 0x55555555);
          uVar3 = (uVar3 & 0x33333333) + (uVar3 >> 2 & 0x33333333);
          if (((uVar3 >> 4) + uVar3 & 0xf0f0f0f) * 0x1010101 >> 0x18 != 1) {
            nvAssertFailedNoLog("nvPopCount32(p2pCapsParams->p2pOptimalWriteCEs) == 1",
                                "src/kernel/rmapi/nv_gpu_ops.c",0xbff);
            uVar7 = *(uint *)(lVar4 + 0x8c);
          }
          param_3[6] = (uint)((uVar7 & 0xaaaaaaaa) != 0) | (uint)(0xffff < uVar7) << 4 |
                       (uint)((uVar7 & 0xff00ff00) != 0) << 3 |
                       (uint)((uVar7 & 0xf0f0f0f0) != 0) << 2 |
                       (uint)((uVar7 & 0xcccccccc) != 0) * 2;
        }
      }
    }
  }
  portMemFree(lVar4);
  return iVar2;
}


// ===== 004a4420 _nvGpuOpsP2pObjectCreate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
_nvGpuOpsP2pObjectCreate(long param_1,long param_2,undefined4 *param_3,undefined4 param_4)

{
  uint uVar1;
  ulong uVar2;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined4 local_a0;
  undefined1 local_9c [16];
  byte local_8c;
  undefined8 local_80 [12];
  ulong uVar3;
  
  uVar2 = 0;
  do {
    uVar1 = (int)uVar2 + 0x20;
    uVar3 = (ulong)uVar1;
    *(undefined8 *)((long)local_80 + uVar2) = 0;
    *(undefined8 *)((long)local_80 + uVar2 + 8) = 0;
    *(undefined8 *)((long)local_80 + uVar2 + 0x10) = 0;
    *(undefined8 *)((long)local_80 + uVar2 + 0x18) = 0;
    uVar2 = uVar3;
  } while (uVar1 < 0x40);
  *(undefined8 *)((long)local_80 + uVar3) = 0;
  *(undefined8 *)((long)local_80 + uVar3 + 8) = 0;
  *(undefined8 *)((long)local_80 + uVar3 + 0x10) = 0;
  local_a0 = 0;
  puVar4 = (undefined8 *)rmapiGetInterface(param_4);
  uVar5 = 0x1f;
  if (((param_2 != 0 && param_3 != (undefined4 *)0x0) && (param_1 != 0)) &&
     (*(long *)(param_1 + 0x48) == *(long *)(param_2 + 0x48))) {
    uVar5 = getSystemP2PCaps(param_1,param_2,local_9c,param_4);
    if (((int)uVar5 == 0) && (uVar5 = 0x56, (local_8c & 1) != 0)) {
      local_a0 = 0;
      local_80[0] = CONCAT44(*(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_1 + 0x14));
      uVar5 = (*(code *)*puVar4)(puVar4,**(undefined4 **)(param_1 + 0x48),
                                 **(undefined4 **)(param_1 + 0x48),&local_a0,0x503b,local_80,0x58);
      if ((int)uVar5 == 0) {
        *param_3 = local_a0;
      }
    }
  }
  return uVar5;
}


// ===== 004a4570 getNvlinkConnectionToSwitch =====

char getNvlinkConnectionToSwitch(long param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char cVar5;
  undefined1 local_40 [16];
  
  iVar2 = convertLinkMasksToBitVector(param_1,4,param_1 + 8,local_40);
  if (iVar2 != 0) {
    nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0xb7c,"getNvlinkConnectionToSwitch",4,
                 "NVRM: Failed to convert enabled linkmask into bit vector! 0x%x\n",iVar2);
  }
  pcVar4 = (char *)(param_1 + 0x2f);
  cVar5 = -1;
  iVar2 = 0;
  iVar3 = 0;
  do {
    while ((((cVar1 = bitVectorTest_IMPL(local_40,0x40,iVar3), cVar1 == '\0' ||
             (pcVar4[0x29] == '\0')) || (pcVar4[0x2a] != '\0')) || (*(long *)(pcVar4 + 0x69) != 3)))
    {
LAB_004a45b8:
      iVar3 = iVar3 + 1;
      pcVar4 = pcVar4 + 0xd8;
      if (iVar3 == 0x40) goto LAB_004a4620;
    }
    if (iVar2 != 0) {
      iVar2 = iVar2 + *(int *)(pcVar4 + 0x15);
      if (*pcVar4 != cVar5) {
        nvAssertFailedNoLog("version == nvlinkStatus->linkInfo[i].nvlinkVersion",
                            "src/kernel/rmapi/nv_gpu_ops.c",0xb91);
      }
      goto LAB_004a45b8;
    }
    iVar3 = iVar3 + 1;
    cVar5 = *pcVar4;
    iVar2 = *(int *)(pcVar4 + 0x15);
    pcVar4 = pcVar4 + 0xd8;
  } while (iVar3 != 0x40);
LAB_004a4620:
  *param_2 = iVar2;
  if ((cVar5 == -1) && (iVar2 != 0)) {
    nvAssertFailedNoLog("*linkBandwidthMBps == 0","src/kernel/rmapi/nv_gpu_ops.c",0xb97);
  }
  return cVar5;
}


// ===== 004a46d0 getNvlinkConnectionToGpu =====

byte getNvlinkConnectionToGpu(long param_1,long param_2,int *param_3)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  byte *pbVar6;
  ushort local_4c;
  undefined1 local_40 [16];
  
  uVar1 = *(undefined8 *)(param_2 + 0x878);
  local_4c = (ushort)((ulong)uVar1 >> 8) & 0xff;
  iVar3 = convertLinkMasksToBitVector(param_1,4,param_1 + 8,local_40);
  if (iVar3 != 0) {
    nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0xae0,"getNvlinkConnectionToGpu",4,
                 "NVRM: Failed to convert enabled linkmask into bit vector! 0x%x\n",iVar3);
  }
  iVar3 = 0;
  pbVar6 = (byte *)(param_1 + 0x20);
  iVar4 = 0;
  bVar5 = 0xff;
  do {
    cVar2 = bitVectorTest_IMPL(local_40,0x40,iVar4);
    if ((((cVar2 != '\0') && (pbVar6[0x38] != 0)) && (pbVar6[0x39] == 0)) &&
       (*(long *)(pbVar6 + 0x78) == 2)) {
      if ((pbVar6[0x60] & 1) == 0) {
        nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0xaf4,"getNvlinkConnectionToGpu",4,
                     "NVRM: No PCI information for GPU.\n");
      }
      else if (((*(int *)(pbVar6 + 100) == (int)((ulong)uVar1 >> 0x20)) &&
               (*(ushort *)(pbVar6 + 0x68) == local_4c)) &&
              ((*(ushort *)(pbVar6 + 0x6a) == ((ushort)uVar1 & 0xff) &&
               (*(int *)(param_2 + 0x7f4) == *(int *)(pbVar6 + 0x70))))) {
        if ((*pbVar6 & 8) == 0) {
          nvAssertFailedNoLog("NV2080_CTRL_NVLINK_GET_CAP(((NvU8 *)&capsTbl), NV2080_CTRL_NVLINK_CAPS_P2P_ATOMICS)"
                              ,"src/kernel/rmapi/nv_gpu_ops.c",0xaff);
        }
        if (iVar3 == 0) {
          bVar5 = pbVar6[0xf];
          iVar3 = *(int *)(pbVar6 + 0x24);
        }
        else {
          iVar3 = iVar3 + *(int *)(pbVar6 + 0x24);
          if (bVar5 != pbVar6[0xf]) {
            nvAssertFailedNoLog("version == nvlinkStatus->linkInfo[i].nvlinkVersion",
                                "src/kernel/rmapi/nv_gpu_ops.c",0xb05);
          }
        }
      }
    }
    iVar4 = iVar4 + 1;
    pbVar6 = pbVar6 + 0xd8;
  } while (iVar4 != 0x40);
  *param_3 = iVar3;
  if ((bVar5 == 0xff) && (iVar3 != 0)) {
    nvAssertFailedNoLog("*linkBandwidthMBps == 0","src/kernel/rmapi/nv_gpu_ops.c",0xb0c);
  }
  return bVar5;
}


// ===== 004a48d0 nvGpuOpsMemGetPageSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvGpuOpsMemGetPageSize(long param_1,undefined8 param_2,long *param_3)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(param_1 + 0x1b78);
  lVar2 = memdescGetPageSize(param_2,1);
  if (lVar2 == 0) {
    uVar3 = (**(code **)(lVar1 + 0x388))(param_1,lVar1,param_2,1,0);
    if ((int)uVar3 != 0) {
      return uVar3;
    }
    lVar2 = memdescGetPageSize(param_2,1);
    if (lVar2 == 0) {
      nvAssertFailedNoLog("pageSize != 0","src/kernel/rmapi/nv_gpu_ops.c",0xef4);
    }
  }
  *param_3 = lVar2;
  return 0;
}


// ===== 004a4980 _nvGpuOpsLocksRelease =====

void _nvGpuOpsLocksRelease(char *param_1)

{
  long lVar1;
  
  lVar1 = g_pSys;
  if (*(int *)(param_1 + 4) != 0) {
    rmGpuGroupLockRelease(*(int *)(param_1 + 4),0);
    param_1[4] = '\0';
    param_1[5] = '\0';
    param_1[6] = '\0';
    param_1[7] = '\0';
  }
  if (*(long *)(param_1 + 8) != 0) {
    serverReleaseClient(g_resServ,*(undefined4 *)(param_1 + 0x10));
    param_1[8] = '\0';
    param_1[9] = '\0';
    param_1[10] = '\0';
    param_1[0xb] = '\0';
    param_1[0xc] = '\0';
    param_1[0xd] = '\0';
    param_1[0xe] = '\0';
    param_1[0xf] = '\0';
  }
  if (*param_1 == '\x01') {
    rmapiLockRelease();
    *param_1 = '\0';
  }
  if (param_1[1] != '\x01') {
    return;
  }
  osReleaseRmSema(*(undefined8 *)(lVar1 + 0x160),0);
  param_1[1] = '\0';
  return;
}


// ===== 004a4a10 fillMIGGiUUID =====

int fillMIGGiUUID(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  long local_28 [3];
  
  if (*(char *)(param_1 + 6) == '\0') {
    return 0x26;
  }
  lVar1 = *(long *)(*(long *)(param_2 + 0x128) + 0xe0);
  iVar2 = kmigmgrGetInstanceRefFromDevice_IMPL
                    (lVar1,*(undefined8 *)(lVar1 + 0x1bc0),param_2,local_28);
  if (iVar2 != 0) {
    return iVar2;
  }
  portMemCopy(param_1 + 0x28,0x10,local_28[0] + 0xa08,0x10);
  return 0;
}


// ===== 004a4a94 nvGpuOpsDisableVaSpaceChannels.cold =====

void nvGpuOpsDisableVaSpaceChannels_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004a4aa0 nvGpuOpsDisableVaSpaceChannels =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong nvGpuOpsDisableVaSpaceChannels(undefined4 *param_1)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  undefined1 local_468 [280];
  long local_350;
  long local_348;
  undefined8 local_340;
  undefined1 local_338 [256];
  long local_238;
  undefined1 local_230 [4];
  uint local_22c;
  undefined4 auStack_218 [64];
  undefined4 auStack_118 [64];
  
  local_350 = 0;
  lVar4 = rmapiGetInterface(4);
  memset(local_230,0,0x218);
  if (param_1 == (undefined4 *)0x0) {
    return 0x1f;
  }
  uVar5 = serverGetClientUnderLock
                    (g_resServ,**(undefined4 **)(*(long *)(param_1 + 2) + 0x48),&local_340);
  if (((int)uVar5 == 0) &&
     (uVar5 = deviceGetByHandle_IMPL
                        (local_340,*(undefined4 *)(*(long *)(param_1 + 2) + 0x10),&local_348),
     (int)uVar5 == 0)) {
    iVar3 = vaspaceGetByHandleOrDeviceDefault_IMPL
                      (local_340,*(undefined4 *)(*(long *)(param_1 + 2) + 0x10),*param_1,&local_350)
    ;
    if (iVar3 != 0) {
      return 0x1f;
    }
    if (local_350 == 0) {
      return 0x1f;
    }
    if (local_348 == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    kchannelGetIter(local_468,local_340,*(undefined8 *)(*(long *)(local_348 + 0x110) + 0x48));
    memcpy(local_338,local_468,0x108);
    while (cVar2 = clientRefOrderedIterNext(local_340,local_338), cVar2 != '\0') {
      lVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_238 + 8),__nvoc_class_def_KernelChannel);
      if (lVar6 == 0) {
        nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/rmapi/nv_gpu_ops.c",0x3c5);
      }
      else if (*(long *)(lVar6 + 0x2a0) == local_350) {
        if (0x3f < local_22c) {
          nvAssertFailedNoLog("disableParams.numChannels < NV2080_CTRL_FIFO_DISABLE_CHANNELS_MAX_ENTRIES"
                              ,"src/kernel/rmapi/nv_gpu_ops.c",0x3c9);
          return 0x56;
        }
        lVar6 = *(long *)(lVar6 + 0x140);
        uVar5 = (ulong)local_22c;
        local_22c = local_22c + 1;
        auStack_218[uVar5] = *(undefined4 *)(**(long **)(lVar6 + 0x48) + 0x48);
        auStack_118[uVar5] = *(undefined4 *)(*(long *)(lVar6 + 0x48) + 0x10);
      }
    }
    uVar5 = (ulong)local_22c;
    if (local_22c != 0) {
      local_230[0] = 1;
      uVar5 = (**(code **)(lVar4 + 0x38))
                        (lVar4,**(undefined4 **)(*(long *)(param_1 + 2) + 0x48),
                         *(undefined4 *)(*(long *)(param_1 + 2) + 0x14),0x2080110b,local_230,0x218);
    }
  }
  return uVar5;
}


// ===== 004a4cf0 nvGpuOpsGetChannelData =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvGpuOpsGetChannelData(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 local_50;
  int local_48;
  undefined4 local_44;
  int local_40 [2];
  undefined8 local_38;
  
  lVar1 = gpuGetKernelFifoShared_IMPL(*(undefined8 *)(param_1 + 0x20));
  kfifoFillMemInfo_IMPL(lVar1,*(undefined8 *)(param_1 + 0x28),local_40);
  if ((local_40[0] != 2) && (local_40[0] != 3)) {
    if (local_40[0] != 1) {
      return 0x21;
    }
    local_40[0] = 0;
  }
  local_44 = 0;
  local_50 = local_38;
  local_48 = local_40[0];
  uVar2 = (**(code **)(lVar1 + 0x1d0))(*(undefined8 *)(param_1 + 0x20),lVar1,&local_50,param_2);
  return uVar2;
}


// ===== 004a4d70 nvGpuOpsCreateClient =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsCreateClient(undefined8 *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined1 local_24 [4];
  uint local_20;
  undefined2 local_1c;
  undefined1 local_1a;
  
  *param_2 = 0;
  iVar1 = (*(code *)*param_1)(param_1,0,0,param_2,0,param_2,4);
  if (iVar1 == 0) {
    portMemSet(local_24,0,0xc);
    local_1c = 1;
    local_20 = local_20 | 1;
    local_1a = 1;
    iVar2 = (*(code *)param_1[0xc])(param_1,*param_2,*param_2,local_24);
    iVar1 = 0;
    if (iVar2 != 0) {
      (*(code *)param_1[3])(param_1,*param_2,*param_2);
      return iVar2;
    }
  }
  return iVar1;
}


// ===== 004a4e20 rmControlToUvmNvlinkVersion =====

undefined8 rmControlToUvmNvlinkVersion(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0xff) {
    if (param_1 == 1) {
      return 3;
    }
    uVar1 = 4;
    if ((param_1 - 2U & 0xfffffffd) != 0) {
      if (param_1 - 5U < 2) {
        return 5;
      }
      if (param_1 == 7) {
        return 6;
      }
      uVar1 = 7;
      if (param_1 != 8) {
        nvAssertFailedNoLog(&DAT_00d939aa,"src/kernel/rmapi/nv_gpu_ops.c",0x78b);
        return 0xffffffff;
      }
    }
  }
  return uVar1;
}


// ===== 004a4eb0 _nvGpuOpsLocksAcquireWithClientLockFlags =====

int _nvGpuOpsLocksAcquireWithClientLockFlags
              (undefined4 param_1,undefined4 param_2,int param_3,undefined8 *param_4,int param_5,
              undefined4 param_6,undefined4 param_7,undefined2 *param_8)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint local_3c [3];
  
  *param_8 = 0;
  *(undefined4 *)(param_8 + 2) = 0;
  lVar1 = g_pSys;
  *(undefined8 *)(param_8 + 4) = 0;
  if (lVar1 == 0) {
    return 0xffff;
  }
  iVar2 = osAcquireRmSema(*(undefined8 *)(lVar1 + 0x160));
  if (iVar2 != 0) {
    return iVar2;
  }
  *(undefined1 *)((long)param_8 + 1) = 1;
  iVar2 = rmapiLockAcquire(param_1,0x400);
  if (iVar2 != 0) goto LAB_004a4f9d;
  *(undefined1 *)param_8 = 1;
  if (param_3 != 0) {
    iVar2 = serverAcquireClient(g_resServ,param_3,param_2,param_8 + 4);
    if (iVar2 != 0) goto LAB_004a4f9d;
    *(undefined4 *)(param_8 + 8) = param_2;
    if (param_4 != (undefined8 *)0x0) {
      *param_4 = *(undefined8 *)(*(long *)(param_8 + 4) + 8);
    }
  }
  if (param_5 == 3) {
    local_3c[0] = 0xffffffff;
    iVar2 = rmGpuGroupLockAcquire(0,2,0,0x400,local_3c);
    *(uint *)(param_8 + 2) = local_3c[0];
LAB_004a4f94:
    if (iVar2 != 0) {
LAB_004a4f9d:
      _nvGpuOpsLocksRelease(param_8);
      return iVar2;
    }
  }
  else {
    if (param_5 != 0) {
      uVar3 = gpumgrGetDeviceGpuMask(param_6);
      uVar4 = gpumgrGetDeviceGpuMask(param_7);
      uVar3 = uVar3 | uVar4;
      if (uVar3 != 0) {
        local_3c[0] = uVar3;
        iVar2 = rmGpuGroupLockAcquire(0,2,0,0x400,local_3c);
        *(uint *)(param_8 + 2) = local_3c[0];
        if ((uVar3 != local_3c[0]) && (uVar3 != 0xffffffff)) {
          iVar2 = 0x2f;
          goto LAB_004a4f9d;
        }
        goto LAB_004a4f94;
      }
    }
    *(undefined4 *)(param_8 + 2) = 0;
  }
  return 0;
}


// ===== 004a50c0 _nvGpuOpsGetGpuFromDevice.constprop.0 =====

ulong _nvGpuOpsGetGpuFromDevice_constprop_0(long param_1,undefined8 *param_2)

{
  uint uVar1;
  ulong uVar2;
  undefined8 local_28;
  long local_20;
  
  uVar2 = rmapiLockAcquire(2,0x400);
  local_28 = 0;
  local_20 = 0;
  if ((int)uVar2 != 0) {
    return uVar2;
  }
  uVar1 = serverGetClientUnderLock(g_resServ,**(undefined4 **)(param_1 + 0x48),&local_28);
  if (uVar1 == 0) {
    uVar1 = deviceGetByHandle_IMPL(local_28,*(undefined4 *)(param_1 + 0x10),&local_20);
    if (uVar1 == 0) {
      *param_2 = *(undefined8 *)(*(long *)(local_20 + 0x128) + 0xe0);
    }
    else {
      nvAssertOkFailedNoLog
                (uVar1,"deviceGetByHandle(pClient, device->handle, &pDevice)",
                 "src/kernel/rmapi/nv_gpu_ops.c",0x2c5);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (uVar1,"serverGetClientUnderLock(&g_resServ, device->session->handle, &pClient)",
               "src/kernel/rmapi/nv_gpu_ops.c",0x2c1);
  }
  rmapiLockRelease();
  return (ulong)uVar1;
}


// ===== 004a51b0 findDeviceClasses.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int findDeviceClasses_isra_0
              (undefined4 param_1,undefined4 param_2,uint *param_3,uint *param_4,uint *param_5,
              uint *param_6,uint *param_7,uint *param_8,uint *param_9)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  undefined1 local_54 [8];
  int local_4c;
  ulong local_48;
  long local_40;
  
  local_48 = 0;
  local_40 = 0;
  lVar4 = rmapiGetInterface(1);
  *param_3 = 0;
  *param_4 = 0;
  *param_5 = 0;
  *param_6 = 0;
  *param_7 = 0;
  *param_8 = 0;
  iVar3 = (**(code **)(lVar4 + 0x38))(lVar4,param_1,param_2,0x800201,&local_48,0x10);
  if (iVar3 == 0) {
    lVar5 = portMemAllocNonPaged((local_48 & 0xffffffff) << 2);
    if (lVar5 == 0) {
      iVar3 = 0x1a;
    }
    else {
      local_40 = lVar5;
      iVar3 = (**(code **)(lVar4 + 0x38))(lVar4,param_1,param_2,0x800201,&local_48,0x10);
      if ((iVar3 == 0) && ((uint)local_48 != 0)) {
        lVar4 = 0;
        do {
          iVar1 = *(int *)(lVar5 + lVar4 * 4);
          if (iVar1 != 0xc572) {
            CliGetChannelClassInfo(iVar1,local_54);
            uVar2 = *(uint *)(lVar5 + lVar4 * 4);
            if (local_4c == 1) {
              uVar6 = *param_3;
              if (*param_3 < uVar2) {
                uVar6 = uVar2;
              }
              *param_3 = uVar6;
            }
            else {
              if (uVar2 != 0xc6b5) {
                if (uVar2 < 0xc6b6) {
                  if (uVar2 != 0xc1b5) {
                    if (uVar2 < 0xc1b6) {
                      if ((uVar2 - 0xb0b5 & 0xffffefff) != 0) {
                        if (uVar2 == 0xc0c0) goto LAB_004a53f0;
                        if (uVar2 < 0xc0c1) {
                          if ((uVar2 & 0xfffffeff) == 0xb0c0) goto LAB_004a53f0;
                          if (uVar2 != 0xb069) goto LAB_004a5347;
                        }
                        else {
LAB_004a5450:
                          if (uVar2 != 0xc369) {
LAB_004a541c:
                            if (uVar2 == 0xc365) {
                              uVar2 = *param_7;
                              if (*param_7 < 0xc365) {
                                uVar2 = 0xc365;
                              }
                              *param_7 = uVar2;
                            }
                            else if ((uVar2 - 0xc763 & 0xfffffeff) == 0) goto LAB_004a54a2;
                            goto LAB_004a539d;
                          }
                        }
                        uVar6 = *param_6;
                        if (*param_6 < uVar2) {
                          uVar6 = uVar2;
                        }
                        *param_6 = uVar6;
                        goto LAB_004a539d;
                      }
                    }
                    else if ((uVar2 - 0xc3b5 & 0xfffffdff) != 0) {
                      if (uVar2 != 0xc4c0) {
                        if (0xc4c0 < uVar2) goto LAB_004a5402;
                        if ((uVar2 & 0xfffffdff) != 0xc1c0) goto LAB_004a5450;
                      }
                      goto LAB_004a53f0;
                    }
                  }
                }
                else if (uVar2 != 0xc9b5) {
                  if (uVar2 < 0xc9b6) {
                    if ((uVar2 - 0xc7b5 & 0xfffffeff) != 0) {
                      if (uVar2 != 0xc7c0) {
LAB_004a5402:
                        if (0xc7c0 < uVar2) goto LAB_004a5490;
                        if ((uVar2 - 0xc5c0 & 0xfffffeff) != 0) goto LAB_004a541c;
                      }
LAB_004a53f0:
                      uVar6 = *param_5;
                      if (*param_5 < uVar2) {
                        uVar6 = uVar2;
                      }
                      *param_5 = uVar6;
                      goto LAB_004a539d;
                    }
                  }
                  else if (uVar2 != 0xcab5) {
                    if (uVar2 != 0xcbc0) {
LAB_004a5490:
                      if ((uVar2 - 0xc763 & 0xfffffeff) == 0) {
LAB_004a54a2:
                        uVar6 = *param_8;
                        if (*param_8 < uVar2) {
                          uVar6 = uVar2;
                        }
                        *param_8 = uVar6;
                      }
                      else {
LAB_004a5347:
                        if (uVar2 == 0xcba2) {
                          uVar2 = *param_9;
                          if (*param_9 < 0xcba2) {
                            uVar2 = 0xcba2;
                          }
                          *param_9 = uVar2;
                        }
                      }
                      goto LAB_004a539d;
                    }
                    goto LAB_004a53f0;
                  }
                }
              }
              uVar6 = *param_4;
              if (*param_4 < uVar2) {
                uVar6 = uVar2;
              }
              *param_4 = uVar6;
            }
          }
LAB_004a539d:
          lVar4 = lVar4 + 1;
        } while ((uint)lVar4 < (uint)local_48);
      }
      portMemFree(lVar5);
    }
  }
  return iVar3;
}


// ===== 004a54f0 destroyAllGpuMemDescriptors.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void destroyAllGpuMemDescriptors_isra_0(undefined4 param_1,long *param_2)

{
  long lVar1;
  long lVar2;
  
  lVar2 = rmapiGetInterface(1);
  if (param_2 != (long *)0x0) {
    destroyAllGpuMemDescriptors_isra_0(param_1,param_2[5]);
    destroyAllGpuMemDescriptors_isra_0(param_1,param_2[6]);
    lVar1 = *param_2;
    if (*(int *)(lVar1 + 0x50) != 0) {
      (**(code **)(lVar2 + 0x18))(lVar2,param_1);
    }
    if (*(int *)(lVar1 + 0x40) != 0) {
      (**(code **)(lVar2 + 0x18))(lVar2,param_1);
    }
    portMemFree(*param_2);
    return;
  }
  return;
}


// ===== 004a5590 nvGpuOpsDestroyPeerInfo.isra.0 =====

void nvGpuOpsDestroyPeerInfo_isra_0(long param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  int iVar2;
  long *local_30 [2];
  
  local_30[0] = (long *)0x0;
  portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0x20));
  iVar2 = btreeSearch(param_2,local_30,*(undefined8 *)(param_1 + 0x18));
  if (iVar2 == 0) {
    lVar1 = *local_30[0];
    portSyncRwLockAcquireWrite(*(undefined8 *)(lVar1 + 0x40));
    iVar2 = btreeSearch(param_3,local_30,*(undefined8 *)(lVar1 + 0x38));
    if (iVar2 == 0) {
      btreeUnlink(local_30[0],lVar1 + 0x38);
      portMemFree(*local_30[0]);
    }
    portSyncRwLockReleaseWrite(*(undefined8 *)(lVar1 + 0x40));
  }
  portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0x20));
  return;
}


// ===== 004a5630 _nvGpuOpsP2pObjectDestroy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong _nvGpuOpsP2pObjectDestroy(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  undefined4 uVar5;
  undefined4 local_4c;
  undefined8 local_48;
  long local_40 [2];
  
  lVar2 = rmapiGetInterface(param_3);
  if (param_1 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("session","src/kernel/rmapi/nv_gpu_ops.c",0x2c0d);
  }
  local_48 = 0;
  local_40[0] = 0;
  if (param_3 == 3) {
    iVar1 = serverGetClientUnderLock(g_resServ,*param_1,&local_48);
    if ((iVar1 != 0) || (iVar1 = clientGetResourceRef_IMPL(local_48,param_2,local_40), iVar1 != 0))
    goto LAB_004a5734;
  }
  else {
    iVar1 = rmapiLockAcquire(2,0x400);
    if (iVar1 != 0) goto LAB_004a5734;
    iVar1 = serverGetClientUnderLock(g_resServ,*param_1,&local_48);
    if ((iVar1 != 0) || (iVar1 = clientGetResourceRef_IMPL(local_48,param_2,local_40), iVar1 != 0))
    {
      rmapiLockRelease();
      goto LAB_004a5734;
    }
  }
  lVar3 = __nvoc_dynamicCast(*(undefined8 *)(local_40[0] + 8),__nvoc_class_def_P2PApi);
  if (lVar3 == 0) {
    if (param_3 != 3) {
      rmapiLockRelease();
    }
    local_4c = 0;
    uVar5 = 0;
  }
  else {
    local_4c = *(undefined4 *)(*(long *)(lVar3 + 0xd8) + 0x7ac);
    uVar5 = *(undefined4 *)(*(long *)(lVar3 + 0xe0) + 0x7ac);
    if (param_3 != 3) {
      rmapiLockRelease();
    }
  }
  nvGpuOpsDestroyPeerInfo_isra_0(param_1,local_4c,uVar5);
  nvGpuOpsDestroyPeerInfo_isra_0(param_1,uVar5,local_4c);
LAB_004a5734:
  uVar4 = (**(code **)(lVar2 + 0x18))(lVar2,*param_1,param_2);
  if ((int)uVar4 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0x2c13);
    uVar4 = uVar4 & 0xffffffff;
  }
  return uVar4;
}


// ===== 004a5820 getSwizzIdFromSmcPartHandle.isra.0 =====

int getSwizzIdFromSmcPartHandle_isra_0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  long lVar2;
  long local_30;
  
  iVar1 = rmapiLockAcquire(2,0x400);
  if (iVar1 == 0) {
    iVar1 = serverutilGetResourceRef(param_1,param_2,&local_30);
    rmapiLockRelease();
    if (iVar1 == 0) {
      lVar2 = __nvoc_dynamicCast(*(undefined8 *)(local_30 + 8),
                                 __nvoc_class_def_GPUInstanceSubscription);
      if (lVar2 != 0) {
        *param_3 = *(undefined4 *)(*(long *)(lVar2 + 0x138) + 0x968);
        return 0;
      }
      iVar1 = 0x31;
    }
  }
  return iVar1;
}


// ===== 004a58bf nvGpuOpsEnableVaSpaceChannels.isra.0.cold =====

void nvGpuOpsEnableVaSpaceChannels_isra_0_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004a58d0 nvGpuOpsEnableVaSpaceChannels.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvGpuOpsEnableVaSpaceChannels_isra_0(undefined4 *param_1)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  undefined1 local_468 [280];
  long local_350;
  long local_348;
  undefined8 local_340;
  undefined1 local_338 [256];
  long local_238;
  undefined1 local_230 [4];
  uint local_22c;
  undefined4 auStack_218 [64];
  undefined4 auStack_118 [64];
  
  local_350 = 0;
  memset(local_230,0,0x218);
  lVar4 = rmapiGetInterface(4);
  if ((((param_1 != (undefined4 *)0x0) &&
       (iVar3 = serverGetClientUnderLock
                          (g_resServ,**(undefined4 **)(*(long *)(param_1 + 2) + 0x48),&local_340),
       iVar3 == 0)) &&
      (iVar3 = deviceGetByHandle_IMPL
                         (local_340,*(undefined4 *)(*(long *)(param_1 + 2) + 0x10),&local_348),
      iVar3 == 0)) &&
     ((iVar3 = vaspaceGetByHandleOrDeviceDefault_IMPL
                         (local_340,*(undefined4 *)(*(long *)(param_1 + 2) + 0x10),*param_1,
                          &local_350), iVar3 == 0 && (local_350 != 0)))) {
    if (local_348 == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    kchannelGetIter(local_468,local_340,*(undefined8 *)(*(long *)(local_348 + 0x110) + 0x48));
    memcpy(local_338,local_468,0x108);
    while (cVar2 = clientRefOrderedIterNext(local_340,local_338), cVar2 != '\0') {
      lVar5 = __nvoc_dynamicCast(*(undefined8 *)(local_238 + 8),__nvoc_class_def_KernelChannel);
      if (lVar5 == 0) {
        nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/rmapi/nv_gpu_ops.c",0x3ff);
      }
      else if (*(long *)(lVar5 + 0x2a0) == local_350) {
        if (0x3f < local_22c) {
          nvAssertFailedNoLog("disableParams.numChannels < NV2080_CTRL_FIFO_DISABLE_CHANNELS_MAX_ENTRIES"
                              ,"src/kernel/rmapi/nv_gpu_ops.c",0x403);
          return;
        }
        lVar5 = *(long *)(lVar5 + 0x140);
        uVar6 = (ulong)local_22c;
        local_22c = local_22c + 1;
        auStack_218[uVar6] = *(undefined4 *)(**(long **)(lVar5 + 0x48) + 0x48);
        auStack_118[uVar6] = *(undefined4 *)(*(long *)(lVar5 + 0x48) + 0x10);
      }
    }
    if (local_22c != 0) {
      local_230[0] = 0;
      (**(code **)(lVar4 + 0x38))
                (lVar4,**(undefined4 **)(*(long *)(param_1 + 2) + 0x48),
                 *(undefined4 *)(*(long *)(param_1 + 2) + 0x14),0x2080110b,local_230,0x218);
    }
  }
  return;
}


// ===== 004a5b10 _nvGpuOpsReleaseChannel =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvGpuOpsReleaseChannel(long *param_1)

{
  uint uVar1;
  long lVar2;
  undefined4 *puVar3;
  int iVar4;
  long lVar5;
  long *plVar6;
  
  lVar5 = rmapiGetInterface(4);
  if (param_1 == (long *)0x0) {
    return;
  }
  uVar1 = *(uint *)((long)param_1 + 0x9c);
  if (uVar1 != 0) {
    plVar6 = param_1;
    do {
      lVar2 = plVar6[6];
      if (*(int *)(lVar2 + 0x90) == 1) {
        mapRemoveByKey_IMPL(*param_1 + 0x180,lVar2);
      }
      plVar6 = plVar6 + 1;
      memdescDestroy(lVar2);
    } while (plVar6 != param_1 + uVar1);
  }
  puVar3 = (undefined4 *)param_1[3];
  if (puVar3 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("session","src/kernel/rmapi/nv_gpu_ops.c",0x28db);
  }
  if ((*(int *)((long)param_1 + 0xb4) == 0) ||
     (iVar4 = (**(code **)(lVar5 + 0x18))(lVar5,*puVar3), iVar4 == 0)) {
    if ((int)param_1[0x16] != 0) goto LAB_004a5bd9;
LAB_004a5c05:
    if (*(int *)((long)param_1 + 0xac) == 0) goto LAB_004a5c22;
LAB_004a5c10:
    iVar4 = (**(code **)(lVar5 + 0x18))(lVar5,*puVar3);
    if (iVar4 == 0) goto LAB_004a5c22;
    nvAssertFailedNoLog("status == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0x28ef);
  }
  else {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0x28e0);
    if ((int)param_1[0x16] != 0) {
LAB_004a5bd9:
      if (*(int *)((long)param_1 + 0xac) == 0) {
        nvAssertFailedNoLog("retainedChannel->hDupTsg","src/kernel/rmapi/nv_gpu_ops.c",0x28e7);
      }
      iVar4 = (**(code **)(lVar5 + 0x18))(lVar5,*puVar3,(int)param_1[0x16]);
      if (iVar4 == 0) goto LAB_004a5c05;
      nvAssertFailedNoLog("status == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0x28e9);
    }
    if (*(int *)((long)param_1 + 0xac) != 0) goto LAB_004a5c10;
  }
  nvAssertFailedNoLog("status == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0x28f5);
LAB_004a5c22:
  portMemFree(param_1);
  return;
}


// ===== 004a5d10 nvGpuOpsAllocVirtual.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsAllocVirtual_isra_0
              (undefined4 *param_1,undefined8 param_2,undefined8 *param_3,int param_4,ulong *param_5
              )

{
  uint uVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  ulong uVar5;
  undefined8 local_b8;
  ulong local_b0 [12];
  undefined4 local_4c;
  
  uVar1 = 0;
  do {
    uVar5 = (ulong)uVar1;
    uVar1 = uVar1 + 0x20;
    *(undefined8 *)((long)&local_b8 + uVar5) = 0;
    *(undefined8 *)((long)local_b0 + uVar5) = 0;
    *(undefined8 *)((long)local_b0 + uVar5 + 8) = 0;
    *(undefined8 *)((long)local_b0 + uVar5 + 0x10) = 0;
  } while (uVar1 < 0x80);
  puVar3 = (undefined8 *)rmapiGetInterface(1);
  if (param_1 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("vaSpace","src/kernel/rmapi/nv_gpu_ops.c",0x1392);
  }
  if (param_3 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("vaOffset","src/kernel/rmapi/nv_gpu_ops.c",0x1393);
  }
  if (param_4 == 0) {
    nvAssertFailedNoLog("physHandle","src/kernel/rmapi/nv_gpu_ops.c",0x1394);
  }
  lVar4 = portMemAllocNonPaged(0x58);
  if (lVar4 == 0) {
    iVar2 = 0x51;
  }
  else {
    local_b0[0]._0_4_ = 0x80100;
    local_b8 = 0xdeaf0004;
    local_b0[8] = param_5[1];
    if (local_b0[8] == 0) {
      local_b0[8] = 0x1000;
    }
    uVar5 = *param_5;
    if (uVar5 == 0x200000) {
      local_b0[2] = local_b0[2] | 0x10000001800000;
    }
    else if (uVar5 < 0x200001) {
      if ((uVar5 - 0x10000 & 0xfffffffffffeffff) == 0) {
        local_b0[2] = local_b0[2] | 0x1000000;
      }
      else if (uVar5 == 0x1000) {
        local_b0[2] = local_b0[2] | 0x800000;
      }
    }
    else if (uVar5 == 0x20000000) {
      local_b0[2] = local_b0[2] | 0x20000001800000;
    }
    else if (uVar5 == 0x4000000000) {
      local_b0[2] = local_b0[2] | 0x30000001800000;
    }
    local_4c = *param_1;
    *(undefined4 *)(lVar4 + 0x40) = 0;
    local_b0[7] = param_2;
    iVar2 = (*(code *)*puVar3)(puVar3,**(undefined4 **)(*(long *)(param_1 + 2) + 0x48),
                               *(undefined4 *)(*(long *)(param_1 + 2) + 0x10),lVar4 + 0x40,0x50a0,
                               &local_b8,0x80);
    if (iVar2 == 0) {
      *(int *)(lVar4 + 0x50) = param_4;
      *(ulong *)(lVar4 + 0x38) = local_b0[9];
      *(undefined8 *)(lVar4 + 0x48) = param_2;
      portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 6));
      *(long *)lVar4 = lVar4;
      *(undefined8 *)(lVar4 + 8) = *(undefined8 *)(lVar4 + 0x38);
      *(undefined8 *)(lVar4 + 0x10) = *(undefined8 *)(lVar4 + 0x38);
      iVar2 = btreeInsert(lVar4,param_1 + 4);
      portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 6));
      if (iVar2 == 0) {
        *param_3 = *(undefined8 *)(lVar4 + 0x38);
        return 0;
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar2,
                 "pRmApi->Alloc(pRmApi, vaSpace->device->session->handle, vaSpace->device->handle, &memDesc->handle, NV50_MEMORY_VIRTUAL, &memAllocParams, sizeof(memAllocParams))"
                 ,"src/kernel/rmapi/nv_gpu_ops.c",0x13c1);
    }
    (*(code *)puVar3[3])
              (puVar3,**(undefined4 **)(*(long *)(param_1 + 2) + 0x48),*(undefined4 *)(lVar4 + 0x40)
              );
    portMemFree(lVar4);
  }
  return iVar2;
}


// ===== 004a6020 getHandleForVirtualAddr =====

int getHandleForVirtualAddr(long param_1,undefined8 param_2,char param_3,int *param_4)

{
  long lVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  long *local_30;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("vaSpace","src/kernel/rmapi/nv_gpu_ops.c",0x1989);
  }
  portSyncRwLockAcquireRead(*(undefined8 *)(param_1 + 0x18));
  local_30 = (long *)0x0;
  iVar2 = btreeSearch(param_2,&local_30,*(undefined8 *)(param_1 + 0x10));
  if (iVar2 == 0) {
    lVar1 = *local_30;
    portSyncRwLockReleaseRead(*(undefined8 *)(param_1 + 0x18));
    if (lVar1 == 0) {
      nvAssertFailedNoLog("memDesc","src/kernel/rmapi/nv_gpu_ops.c",0x1992);
    }
    piVar3 = (int *)(lVar1 + 0x40);
    if (param_3 != '\0') {
      piVar3 = (int *)(lVar1 + 0x50);
    }
    iVar2 = *piVar3;
    *param_4 = iVar2;
    iVar4 = 0;
    if (iVar2 == 0) {
      iVar4 = 0xffff;
    }
    return iVar4;
  }
  portSyncRwLockReleaseRead(*(undefined8 *)(param_1 + 0x18));
  return iVar2;
}


// ===== 004a6110 nvGpuOpsFindAndDestroyP2pInfo =====

void nvGpuOpsFindAndDestroyP2pInfo(long param_1,undefined4 param_2)

{
  long lVar1;
  int iVar2;
  long *local_38;
  undefined8 *local_30 [2];
  
  local_38 = (long *)0x0;
  portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0x20));
  iVar2 = btreeSearch(param_2,&local_38,*(undefined8 *)(param_1 + 0x18));
  if (iVar2 == 0) {
    btreeUnlink(local_38,param_1 + 0x18);
    lVar1 = *local_38;
    if (*(long *)(lVar1 + 0x38) != 0) {
      portSyncRwLockAcquireWrite(*(undefined8 *)(lVar1 + 0x40));
      btreeDestroyData(*(undefined8 *)(lVar1 + 0x38));
      portSyncRwLockReleaseWrite(*(undefined8 *)(lVar1 + 0x40));
    }
    portSyncRwLockDestroy(*(undefined8 *)(lVar1 + 0x40));
    portMemFree(lVar1);
  }
  portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0x20));
  portSyncRwLockAcquireRead(*(undefined8 *)(param_1 + 0x20));
  btreeEnumStart(0,&local_38,*(undefined8 *)(param_1 + 0x18));
  while (local_38 != (long *)0x0) {
    local_30[0] = (undefined8 *)0x0;
    lVar1 = *local_38;
    portSyncRwLockAcquireWrite(*(undefined8 *)(lVar1 + 0x40));
    iVar2 = btreeSearch(param_2,local_30,*(undefined8 *)(lVar1 + 0x38));
    if (iVar2 == 0) {
      btreeUnlink(local_30[0],lVar1 + 0x38);
      portMemFree(*local_30[0]);
    }
    portSyncRwLockReleaseWrite(*(undefined8 *)(lVar1 + 0x40));
    btreeEnumNext(&local_38,*(undefined8 *)(param_1 + 0x18));
  }
  portSyncRwLockReleaseRead(*(undefined8 *)(param_1 + 0x20));
  return;
}


// ===== 004a6250 nvGpuOpsMapGpuMemory.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong nvGpuOpsMapGpuMemory_isra_0
                (long param_1,undefined8 param_2,undefined8 param_3,long param_4,long *param_5,
                char param_6)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  long *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  undefined8 local_40;
  
  lVar4 = rmapiGetInterface(1);
  local_78 = 0;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  if ((param_1 == 0) || (param_5 == (long *)0x0)) {
    uVar5 = 0x1f;
  }
  else {
    portSyncRwLockAcquireRead(*(undefined8 *)(param_1 + 0x18));
    local_80 = (long *)0x0;
    uVar3 = btreeSearch(param_2,&local_80,*(undefined8 *)(param_1 + 0x10));
    if (uVar3 == 0) {
      lVar2 = *local_80;
      portSyncRwLockReleaseRead(*(undefined8 *)(param_1 + 0x18));
      if (lVar2 == 0) {
        nvAssertFailedNoLog("memDescVa","src/kernel/rmapi/nv_gpu_ops.c",0x13f9);
      }
      if (*(int *)(lVar2 + 0x40) == 0) {
        nvAssertFailedNoLog("memDescVa->handle","src/kernel/rmapi/nv_gpu_ops.c",0x13fa);
      }
      iVar1 = *(int *)(lVar2 + 0x50);
      if (iVar1 == 0) {
        nvAssertFailedNoLog("memDescVa->childHandle","src/kernel/rmapi/nv_gpu_ops.c",0x13fb);
        iVar1 = *(int *)(lVar2 + 0x50);
      }
      uVar3 = 0x100;
      if (param_4 != 0x1000) {
        uVar3 = (uint)(param_4 == 0x200000) << 10;
      }
      local_70 = CONCAT44(iVar1,*(undefined4 *)(lVar2 + 0x40));
      local_78 = CONCAT44(*(undefined4 *)(*(long *)(param_1 + 8) + 0x10),
                          **(undefined4 **)(*(long *)(param_1 + 8) + 0x48));
      local_58 = CONCAT44(local_58._4_4_,(uint)(param_6 != '\0') << 5 | uVar3) | 0x10;
      local_60 = param_3;
      uVar5 = (**(code **)(lVar4 + 0x98))(lVar4,&local_78);
      if ((int)uVar5 == 0) {
        if (*(long *)(lVar2 + 0x38) != local_48) {
          nvAssertFailedNoLog("memDescVa->address == mapDmaParams.dmaOffset",
                              "src/kernel/rmapi/nv_gpu_ops.c",0x141f);
          local_48 = *(long *)(lVar2 + 0x38);
          uVar5 = uVar5 & 0xffffffff;
        }
        *param_5 = local_48;
      }
    }
    else {
      portSyncRwLockReleaseRead(*(undefined8 *)(param_1 + 0x18));
      uVar5 = (ulong)uVar3;
    }
  }
  return uVar5;
}


// ===== 004a64d0 nvGpuOpsFreeVirtual =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvGpuOpsFreeVirtual(long param_1,undefined8 param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long *local_30 [2];
  
  lVar4 = rmapiGetInterface(1);
  portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0x18));
  local_30[0] = (long *)0x0;
  iVar3 = btreeSearch(param_2,local_30,*(undefined8 *)(param_1 + 0x10));
  if (iVar3 == 0) {
    lVar1 = *local_30[0];
    btreeUnlink(local_30[0],param_1 + 0x10);
    portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0x18));
    if (lVar1 != 0) {
      (**(code **)(lVar4 + 0x18))
                (lVar4,**(undefined4 **)(*(long *)(param_1 + 8) + 0x48),
                 *(undefined4 *)(lVar1 + 0x40));
      portMemFree(lVar1);
      return;
    }
  }
  else {
    portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0x18));
  }
  nvAssertFailedNoLog("memDescVa","src/kernel/rmapi/nv_gpu_ops.c",0x147d);
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 004a6590 nvGpuOpsGpuMalloc.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsGpuMalloc_isra_0
              (long param_1,undefined1 param_2,undefined8 param_3,long param_4,undefined1 param_5,
              long param_6)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  undefined8 local_58;
  undefined1 local_50 [8];
  undefined8 local_48;
  undefined8 local_40;
  
  local_58 = 0;
  local_48 = 0;
  local_40 = 0;
  lVar3 = rmapiGetInterface(1);
  if (param_1 == 0) {
    nvAssertFailedNoLog("vaSpace","src/kernel/rmapi/nv_gpu_ops.c",0x1439);
  }
  if (param_4 == 0) {
    nvAssertFailedNoLog("gpuOffset","src/kernel/rmapi/nv_gpu_ops.c",0x143a);
  }
  iVar2 = nvGpuOpsAllocPhysical(*(undefined8 *)(param_1 + 8),param_2,param_3,local_50,param_6);
  if (iVar2 == 0) {
    iVar4 = *(int *)(param_6 + 0x1c);
    if (iVar4 == 0) {
      nvAssertFailedNoLog("allocInfo->hPhysHandle","src/kernel/rmapi/nv_gpu_ops.c",0x1443);
      iVar4 = *(int *)(param_6 + 0x1c);
    }
    local_48 = *(undefined8 *)(param_6 + 8);
    local_40 = *(undefined8 *)(param_6 + 0x10);
    iVar2 = nvGpuOpsAllocVirtual_isra_0(param_1,param_3,&local_58,iVar4,&local_48);
    uVar1 = local_58;
    if (iVar2 == 0) {
      iVar2 = nvGpuOpsMapGpuMemory_isra_0
                        (param_1,local_58,param_3,*(undefined8 *)(param_6 + 8),param_4,param_5);
      if (iVar2 == 0) {
        return 0;
      }
      nvGpuOpsFreeVirtual(param_1,uVar1);
    }
    (**(code **)(lVar3 + 0x18))(lVar3,**(undefined4 **)(*(long *)(param_1 + 8) + 0x48),iVar4);
  }
  return iVar2;
}


// ===== 004a6750 gpuDeviceRmSubDeviceDeinitEcc =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gpuDeviceRmSubDeviceDeinitEcc(long *param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  
  lVar1 = param_1[1];
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  lVar2 = rmapiGetInterface(1);
  if ((*(char *)(lVar1 + 0x70) != '\0') && (*(char *)(lVar1 + 0x71) != '\0')) {
    local_40 = 0x70;
    (**(code **)(lVar2 + 0x38))
              (lVar2,*(undefined4 *)param_1[9],*(undefined4 *)((long)param_1 + 0x14),0x20800301,
               &local_40,0x14);
    lVar3 = *param_1;
    if (lVar3 == 0) {
      nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x76a);
      lVar3 = *param_1;
    }
    if (*(uint *)(lVar3 + 0x54) < 0x160) {
      gpuDeviceUnmapCpuFreeHandle
                (param_1,*(undefined4 *)(lVar1 + 0x68),*(undefined8 *)(lVar1 + 0x60),1);
    }
    *(undefined8 *)(lVar1 + 0x60) = 0;
    if (*(int *)(lVar1 + 0x6c) != 0) {
      (**(code **)(lVar2 + 0x18))(lVar2,*(undefined4 *)param_1[9]);
    }
    *(undefined2 *)(lVar1 + 0x70) = 0;
  }
  return;
}


// ===== 004a6850 gpuDeviceRmSubDeviceDeinitNvlink =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gpuDeviceRmSubDeviceDeinitNvlink(long *param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  
  lVar2 = param_1[1];
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  lVar3 = rmapiGetInterface(1);
  if ((*(char *)(lVar2 + 0xa0) != '\0') && (*(char *)(lVar2 + 0xa1) != '\0')) {
    local_40 = 0xbe;
    (**(code **)(lVar3 + 0x38))
              (lVar3,*(undefined4 *)param_1[9],*(undefined4 *)((long)param_1 + 0x14),0x20800301,
               &local_40,0x14);
    lVar4 = *param_1;
    if (lVar4 == 0) {
      nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x76a);
      lVar4 = *param_1;
    }
    if (*(uint *)(lVar4 + 0x54) < 0x160) {
      iVar1 = *(int *)(lVar2 + 0x98);
      if (iVar1 == 0) {
        iVar1 = *(int *)(lVar2 + 0x68);
      }
      gpuDeviceUnmapCpuFreeHandle(param_1,iVar1,*(undefined8 *)(lVar2 + 0x90),1);
    }
    *(undefined8 *)(lVar2 + 0x90) = 0;
    if (*(int *)(lVar2 + 0x9c) != 0) {
      (**(code **)(lVar3 + 0x18))(lVar3,*(undefined4 *)param_1[9]);
    }
    *(undefined2 *)(lVar2 + 0xa0) = 0;
  }
  return;
}


// ===== 004a6980 nvGpuOpsRmDeviceDestroy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvGpuOpsRmDeviceDestroy(long *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  long *local_30;
  
  lVar3 = rmapiGetInterface(1);
  lVar5 = *param_1;
  if (lVar5 == 0) {
    nvAssertFailedNoLog("rmDevice != NULL","src/kernel/rmapi/nv_gpu_ops.c",0x474);
  }
  if (*(int *)(lVar5 + 0x50) == 0) {
    puVar1 = (undefined4 *)param_1[9];
    uVar4 = (ulong)*(uint *)(param_1 + 3);
    if (*(char *)((long)param_1 + 0x42) != '\0') {
      uVar4 = CONCAT44(*(undefined4 *)((long)param_1 + 0x11c),*(uint *)(param_1 + 3));
    }
    portSyncRwLockAcquireWrite(*(undefined8 *)(puVar1 + 4));
    local_30 = (long *)0x0;
    iVar2 = btreeSearch(uVar4,&local_30,*(undefined8 *)(puVar1 + 2));
    if (iVar2 == 0) {
      lVar5 = *local_30;
      btreeUnlink(local_30,puVar1 + 2);
    }
    (**(code **)(lVar3 + 0x18))(lVar3,*puVar1,*(undefined4 *)(lVar5 + 0x40));
    portSyncRwLockDestroy(*(undefined8 *)(lVar5 + 0x38));
    portMemFree(lVar5);
    portSyncRwLockReleaseWrite(*(undefined8 *)(puVar1 + 4));
    return;
  }
  return;
}


// ===== 004a6aa0 channelNeedsDummyAlloc =====

bool channelNeedsDummyAlloc(long *param_1)

{
  uint uVar1;
  long *plVar2;
  
  plVar2 = *(long **)(*(long *)(*param_1 + 8) + 8);
  if ((3 < *(uint *)((long)plVar2 + 300)) || ((char)plVar2[0xc] != '\0')) {
    return false;
  }
  if (*(int *)((long)param_1 + 0x7c) != 1) {
    return false;
  }
  if (*plVar2 != 0) {
    uVar1 = *(uint *)(*plVar2 + 0x54);
    if ((0x17f < uVar1) && (uVar1 != 400)) {
      return (int)param_1[0xf] == 2;
    }
    return true;
  }
  nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x777);
  if ((0x17f < *(uint *)(*plVar2 + 0x54)) && (*(uint *)(*plVar2 + 0x54) != 400)) {
    return (int)param_1[0xf] == 2;
  }
  return true;
}


// ===== 004a6b60 getAddressSpaceInfo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int getAddressSpaceInfo(undefined4 *param_1,long param_2,ulong *param_3)

{
  undefined4 *puVar1;
  long lVar2;
  undefined1 uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  undefined8 *puVar10;
  long *plVar11;
  long *local_108;
  undefined8 local_100;
  undefined8 local_f8;
  uint local_ec;
  undefined8 auStack_e8 [18];
  undefined4 local_54;
  
  uVar5 = 0;
  do {
    uVar9 = (ulong)uVar5;
    uVar5 = uVar5 + 0x20;
    *(undefined8 *)((long)&local_f8 + uVar9) = 0;
    *(undefined8 *)(&stack0xffffffffffffff10 + uVar9) = 0;
    *(undefined8 *)((long)auStack_e8 + uVar9) = 0;
    *(undefined8 *)((long)auStack_e8 + uVar9 + 8) = 0;
  } while (uVar5 < 0xc0);
  local_108 = (long *)0x0;
  lVar7 = rmapiGetInterface(1);
  lVar8 = *(long *)(param_1 + 2);
  local_54 = *param_1;
  puVar1 = *(undefined4 **)(lVar8 + 0x48);
  lVar2 = *(long *)(lVar8 + 8);
  iVar6 = (**(code **)(lVar7 + 0x38))
                    (lVar7,*puVar1,*(undefined4 *)(lVar8 + 0x10),0x801806,&local_f8,0xc0);
  if (iVar6 != 0) {
    return iVar6;
  }
  *param_3 = (ulong)local_ec;
  iVar6 = rmapiLockAcquire(2,0x400);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = serverGetClientUnderLock(g_resServ,*puVar1,&local_100);
  if (iVar6 != 0) {
    rmapiLockRelease();
    return iVar6;
  }
  iVar6 = vaspaceGetByHandleOrDeviceDefault_IMPL
                    (local_100,*(undefined4 *)(lVar8 + 0x10),*param_1,&local_108);
  rmapiLockRelease();
  if (iVar6 != 0) {
    return iVar6;
  }
  uVar3 = (**(code **)(*local_108 + 0xb8))();
  *(undefined1 *)(param_3 + 1) = uVar3;
  plVar11 = *(long **)(param_1 + 2);
  lVar8 = *plVar11;
  if (lVar8 == 0) {
    nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x76a);
    if (*(uint *)(*plVar11 + 0x54) < 0x160) {
      plVar11 = *(long **)(param_1 + 2);
      lVar8 = *plVar11;
      if (lVar8 == 0) {
        nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x764);
        uVar5 = *(uint *)(*plVar11 + 0x54);
      }
      else {
        uVar5 = *(uint *)(lVar8 + 0x54);
      }
      goto LAB_004a6cdb;
    }
LAB_004a6da0:
    plVar11 = (long *)gpuGetDeviceMapping_IMPL(param_2,0,0);
    if (plVar11 == (long *)0x0) {
      nvAssertFailedNoLog("pMapping","src/kernel/rmapi/nv_gpu_ops.c",0x33d);
    }
    lVar8 = *plVar11;
    param_3[2] = (ulong)(*(int *)(param_2 + 0x3a64) + 0x30080) + lVar8;
    param_3[3] = lVar8 + (ulong)(*(int *)(param_2 + 0x3a64) + 0x30084);
  }
  else {
    uVar5 = *(uint *)(lVar8 + 0x54);
    if (0x15f < uVar5) goto LAB_004a6da0;
LAB_004a6cdb:
    if (uVar5 < 0x140) {
      plVar11 = (long *)gpuGetDeviceMapping_IMPL(param_2,0,0);
      if (plVar11 == (long *)0x0) {
        nvAssertFailedNoLog("pMapping","src/kernel/rmapi/nv_gpu_ops.c",0x33d);
      }
      uVar9 = *plVar11 + 0x9410;
      param_3[2] = *plVar11 + 0x9400;
    }
    else {
      lVar8 = *(long *)(lVar2 + 0xc0);
      if (lVar8 == 0) {
        nvAssertFailedNoLog("rmSubDevice->clientRegionMapping","src/kernel/rmapi/nv_gpu_ops.c",0x996
                           );
        lVar8 = *(long *)(lVar2 + 0xc0);
      }
      param_3[2] = lVar8 + 0x80;
      uVar9 = *(long *)(lVar2 + 0xc0) + 0x84;
    }
    param_3[3] = uVar9;
    if (param_2 == 0) goto LAB_004a6d20;
  }
  if ((*(long *)(param_2 + 0x1bc0) != 0) &&
     (cVar4 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_2), cVar4 != '\0')) {
    lVar8 = *(long *)(lVar2 + 0x50);
    *(undefined4 *)(param_3 + 4) = *(undefined4 *)(lVar8 + 0x94);
    *(undefined4 *)((long)param_3 + 0x2c) = *(undefined4 *)(lVar8 + 0x88);
    return 0;
  }
LAB_004a6d20:
  puVar10 = (undefined8 *)portMemAllocNonPaged(0x808);
  if (puVar10 == (undefined8 *)0x0) {
    iVar6 = 0x51;
  }
  else {
    *puVar10 = 0x300000001;
    iVar6 = (**(code **)(lVar7 + 0x38))
                      (lVar7,*puVar1,*(undefined4 *)(lVar2 + 0x38),0x20801109,puVar10,0x808);
    *(undefined4 *)(param_3 + 4) = *(undefined4 *)(puVar10 + 1);
    portMemFree(puVar10);
  }
  return iVar6;
}


// ===== 004a6fc0 nvGpuOpsCreateSession =====

int nvGpuOpsCreateSession(long *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  
  uVar2 = rmapiGetInterface(1);
  uVar3 = portMemAllocatorGetGlobalNonPaged();
  lVar4 = portMemAllocNonPaged(0x28);
  if (lVar4 == 0) {
    iVar1 = 0x51;
  }
  else {
    portMemSet(lVar4,0,0x28);
    iVar1 = nvGpuOpsCreateClient(uVar2,lVar4);
    if (iVar1 == 0) {
      *(undefined8 *)(lVar4 + 8) = 0;
      *(undefined8 *)(lVar4 + 0x18) = 0;
      uVar2 = portSyncRwLockCreate(uVar3);
      *(undefined8 *)(lVar4 + 0x10) = uVar2;
      uVar2 = portSyncRwLockCreate(uVar3);
      *(undefined8 *)(lVar4 + 0x20) = uVar2;
      *param_1 = lVar4;
    }
    else {
      portMemFree(lVar4);
    }
  }
  return iVar1;
}


// ===== 004a7090 nvGpuOpsDestroySession =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

undefined8 nvGpuOpsDestroySession(undefined4 *param_1)

{
  long lVar1;
  
  lVar1 = rmapiGetInterface(1);
  if (param_1 != (undefined4 *)0x0) {
    if (*(long *)(param_1 + 2) != 0) {
      nvAssertFailedNoLog("!session->devices","src/kernel/rmapi/nv_gpu_ops.c",0x32d);
    }
    if (*(long *)(param_1 + 6) != 0) {
      nvAssertFailedNoLog("!session->p2pInfo","src/kernel/rmapi/nv_gpu_ops.c",0x32f);
    }
    (**(code **)(lVar1 + 0x18))(lVar1,*param_1,*param_1,*(code **)(lVar1 + 0x18));
    portSyncRwLockDestroy(*(undefined8 *)(param_1 + 4));
    portSyncRwLockDestroy(*(undefined8 *)(param_1 + 8));
    portMemFree(param_1);
  }
  return 0;
}


// ===== 004a7140 calculatePCIELinkRateMBps =====

undefined8 calculatePCIELinkRateMBps(int param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  
  if (param_2 == 4) {
    uVar1 = (uint)(param_1 * 0x1f4000) / 0x410;
  }
  else if (param_2 < 5) {
    if (param_2 == 2) {
      uVar1 = (uint)(param_1 * 40000) / 0x50;
    }
    else if (param_2 == 3) {
      uVar1 = (uint)(param_1 * 0xfa000) / 0x410;
    }
    else {
      if (param_2 != 1) goto LAB_004a71a0;
      uVar1 = (uint)(param_1 * 20000) / 0x50;
    }
  }
  else if (param_2 == 5) {
    uVar1 = (uint)(param_1 * 0x3e8000) / 0x410;
  }
  else {
    if (param_2 != 6) {
LAB_004a71a0:
      nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x821,"calculatePCIELinkRateMBps",4,
                   "NVRM: Unknown PCIe speed\n");
      *param_3 = 0;
      return 0x40;
    }
    uVar1 = (uint)(param_1 * 0xec5400) >> 0xb;
  }
  *param_3 = uVar1;
  return 0;
}


// ===== 004a7260 getPCIELinkRateMBps =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int getPCIELinkRateMBps(undefined4 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 local_1d0;
  uint local_1c8;
  
  lVar2 = rmapiGetInterface(1);
  memset(&local_1d0,0,0x1a4);
  local_1d0 = 0x300000001;
  iVar1 = (**(code **)(lVar2 + 0x38))(lVar2,param_1,param_2,0x20801823,&local_1d0,0x1a4);
  if (iVar1 != 0) {
    uVar3 = nvstatusToString(iVar1);
    nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x83e,"getPCIELinkRateMBps",4,"NVRM: %s:%d: %s\n",
                 "getPCIELinkRateMBps",0x83e,uVar3);
    return iVar1;
  }
  iVar1 = calculatePCIELinkRateMBps(local_1c8 >> 4 & 0x3f,local_1c8 & 0xf,param_3);
  if (iVar1 == 0) {
    return 0;
  }
  uVar3 = nvstatusToString(0x40);
  nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x849,"getPCIELinkRateMBps",4,"NVRM: %s:%d: %s\n",
               "getPCIELinkRateMBps",0x849,uVar3);
  return 0x40;
}


// ===== 004a73b0 nvGpuOpsDeviceDestroy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvGpuOpsDeviceDestroy(long *param_1)

{
  long *plVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long local_38;
  long *local_30;
  
  lVar2 = *param_1;
  lVar5 = param_1[1];
  lVar4 = rmapiGetInterface(1);
  local_38 = 0;
  iVar3 = _nvGpuOpsGetGpuFromDevice_constprop_0(param_1,&local_38);
  if ((iVar3 == 0) && (local_38 != 0)) {
    nvGpuOpsFindAndDestroyP2pInfo(param_1[9],*(undefined4 *)(local_38 + 0x7ac));
  }
  plVar1 = (long *)(lVar5 + 0x40);
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    gpuDeviceUnmapCpuFreeHandle
              (param_1,*(undefined4 *)(param_1[1] + 0xb8),*(undefined8 *)(param_1[1] + 0xc0),0);
    gpuDeviceRmSubDeviceDeinitNvlink(param_1);
    gpuDeviceRmSubDeviceDeinitEcc(param_1);
    nvGpuOpsRmSmcPartitionDestroy(param_1);
    portSyncRwLockAcquireWrite(*(undefined8 *)(lVar2 + 0x38));
    *(int *)(lVar2 + 0x50) = *(int *)(lVar2 + 0x50) + -1;
    local_30 = (long *)0x0;
    iVar3 = btreeSearch(*(undefined4 *)((long)param_1 + 0x1c),&local_30,
                        *(undefined8 *)(lVar2 + 0x48));
    if (iVar3 == 0) {
      lVar5 = *local_30;
      btreeUnlink(local_30,lVar2 + 0x48);
    }
    (**(code **)(lVar4 + 0x18))(lVar4,*(undefined4 *)param_1[9],*(undefined4 *)(lVar5 + 0x38));
    if (*(int *)(lVar5 + 200) != 0) {
      nvAssertFailedNoLog("rmSubDevice->hP2pObject == 0","src/kernel/rmapi/nv_gpu_ops.c",0x93f);
    }
    if (*(long *)(lVar5 + 0xd0) != 0) {
      nvAssertFailedNoLog("rmSubDevice->p2pObjectRef == 0","src/kernel/rmapi/nv_gpu_ops.c",0x940);
    }
    portMemFree(lVar5);
    portSyncRwLockReleaseWrite(*(undefined8 *)(lVar2 + 0x38));
    nvGpuOpsRmDeviceDestroy(param_1);
  }
  mapDestroy_IMPL(param_1 + 0x30);
  if (param_1[0x34] != 0) {
    portSyncMutexDestroy();
  }
  portMemFree(param_1);
  return 0;
}


// ===== 004a7555 nvGpuOpsDeviceCreate.cold =====

void nvGpuOpsDeviceCreate_cold(void)

{
  code *pcVar1;
  
  nvAssertFailedNoLog("rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x723);
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004a75a0 nvGpuOpsDeviceCreate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsDeviceCreate
              (undefined4 *param_1,long param_2,undefined8 param_3,undefined8 *param_4,char param_5)

{
  undefined4 *puVar1;
  code *pcVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  long lVar7;
  long *plVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  uint *puVar11;
  ulong uVar12;
  long lVar13;
  char *pcVar14;
  char *pcVar15;
  byte *pbVar16;
  long lVar17;
  undefined8 *puVar18;
  byte *pbVar19;
  long **pplVar20;
  uint uVar21;
  ulong uVar22;
  undefined8 *local_598;
  ulong local_588;
  undefined4 local_578;
  undefined4 uStack_574;
  ulong local_570;
  long *local_568;
  long local_560;
  long local_558;
  undefined1 local_550 [256];
  undefined4 local_450;
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_444;
  undefined8 local_440;
  undefined8 local_438;
  undefined8 local_430;
  undefined8 local_428;
  undefined8 local_420;
  undefined8 local_418;
  undefined8 local_410;
  
  memset(local_550,0,0x110);
  lVar7 = rmapiGetInterface(1);
  plVar8 = (long *)portMemAllocNonPaged(0x1a8);
  if (plVar8 == (long *)0x0) {
    return 0x1a;
  }
  portMemSet(plVar8,0,0x1a8);
  plVar8[9] = (long)param_1;
  portMemCopy(local_550,0x10,param_3,0x10);
  local_450 = 2;
  iVar5 = (**(code **)(lVar7 + 0x38))(lVar7,*param_1,*param_1,0x274);
  if (iVar5 != 0) goto LAB_004a7672;
  *(undefined4 *)(plVar8 + 3) = local_448;
  *(undefined4 *)((long)plVar8 + 0x1c) = local_444;
  *(char *)((long)plVar8 + 0x42) = param_5;
  *(undefined4 *)(plVar8 + 4) = local_44c;
  portMemCopy(plVar8 + 0x12,0xf0,param_2,0xf0);
  local_440 = (long *)0x0;
  local_438 = 0;
  local_430 = 0;
  local_428 = 0;
  local_420 = 0;
  local_418 = 0;
  local_410 = 0;
  puVar1 = (undefined4 *)plVar8[9];
  puVar9 = (undefined8 *)rmapiGetInterface(1);
  uVar10 = portMemAllocatorGetGlobalNonPaged();
  local_588 = (ulong)*(uint *)(plVar8 + 3);
  if (*(char *)((long)plVar8 + 0x42) != '\0') {
    local_588 = CONCAT44(*(undefined4 *)((long)plVar8 + 0x11c),*(uint *)(plVar8 + 3));
  }
  portSyncRwLockAcquireRead(*(undefined8 *)(puVar1 + 4));
  local_568 = (long *)0x0;
  iVar5 = btreeSearch(local_588,&local_568,*(undefined8 *)(puVar1 + 2));
  if (iVar5 != 0) {
    portSyncRwLockReleaseRead(*(undefined8 *)(puVar1 + 4));
    lVar7 = portMemAllocNonPaged(0x60);
    if (lVar7 == 0) {
      iVar5 = 0x1a;
      goto LAB_004a7672;
    }
    portMemSet(lVar7,0,0x60);
    local_440 = (long *)CONCAT44(*puVar1,(int)plVar8[3]);
    *(undefined4 *)(plVar8 + 2) = 0;
    iVar5 = (*(code *)*puVar9)(puVar9,*puVar1,*puVar1,plVar8 + 2,0x80,&local_440,0x38);
    if (iVar5 == 0) {
      lVar13 = plVar8[2];
      *plVar8 = lVar7;
      *(undefined8 *)(lVar7 + 0x48) = 0;
      *(int *)(lVar7 + 0x40) = (int)lVar13;
      *(undefined4 *)(lVar7 + 0x50) = 0;
      portSyncRwLockAcquireWrite(*(undefined8 *)(puVar1 + 4));
      *(ulong *)(lVar7 + 8) = local_588;
      *(ulong *)(lVar7 + 0x10) = local_588;
      *(long *)lVar7 = lVar7;
      iVar5 = btreeInsert(lVar7,puVar1 + 2);
      portSyncRwLockReleaseWrite(*(undefined8 *)(puVar1 + 4));
      if ((iVar5 == 0) && (iVar5 = rmapiLockAcquire(2,0x400), iVar5 == 0)) {
        iVar5 = CliSetGpuContext(*puVar1,(int)plVar8[2],&local_568,0);
        rmapiLockRelease();
        if (iVar5 == 0) {
          *(int *)(lVar7 + 0x5c) = (int)plVar8[4];
          *(int *)(lVar7 + 0x54) = (int)local_568[0x101];
          *(undefined4 *)(lVar7 + 0x58) = *(undefined4 *)((long)local_568 + 0x80c);
          uVar10 = portSyncRwLockCreate(uVar10);
          *(undefined8 *)(lVar7 + 0x38) = uVar10;
          goto LAB_004a77be;
        }
      }
      (*(code *)puVar9[3])(puVar9,*puVar1,(int)plVar8[2]);
    }
    portMemFree(lVar7);
    goto LAB_004a7672;
  }
  lVar7 = *local_568;
  portSyncRwLockReleaseRead(*(undefined8 *)(puVar1 + 4));
  if (lVar7 == 0) {
    nvAssertFailedNoLog("rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x434);
  }
  *plVar8 = lVar7;
  *(undefined4 *)(plVar8 + 2) = *(undefined4 *)(lVar7 + 0x40);
LAB_004a77be:
  local_598 = &local_440;
  local_568 = (long *)((ulong)local_568 & 0xffffffff00000000);
  puVar1 = (undefined4 *)plVar8[9];
  puVar9 = (undefined8 *)rmapiGetInterface(1);
  uVar22 = (ulong)*(uint *)(plVar8 + 3);
  if (*(char *)((long)plVar8 + 0x42) != '\0') {
    uVar22 = CONCAT44(*(undefined4 *)((long)plVar8 + 0x11c),*(uint *)(plVar8 + 3));
  }
  if (puVar1 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("session","src/kernel/rmapi/nv_gpu_ops.c",0x718);
  }
  portSyncRwLockAcquireRead(*(undefined8 *)(puVar1 + 4));
  local_440 = (long *)0x0;
  iVar5 = btreeSearch(uVar22,local_598,*(undefined8 *)(puVar1 + 2));
  if (iVar5 == 0) {
    lVar7 = *local_440;
    if (lVar7 == 0) {
      nvAssertFailedNoLog("rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x723);
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    if (*(int *)(lVar7 + 0x40) != (int)plVar8[2]) {
      nvAssertFailedNoLog("rmDevice->deviceHandle == device->handle","src/kernel/rmapi/nv_gpu_ops.c"
                          ,0x724);
    }
    portSyncRwLockAcquireWrite(*(undefined8 *)(lVar7 + 0x38));
    local_440 = (long *)0x0;
    iVar5 = btreeSearch(*(undefined4 *)((long)plVar8 + 0x1c),local_598,*(undefined8 *)(lVar7 + 0x48)
                       );
    if (iVar5 == 0) {
      lVar13 = *local_440;
      if (lVar13 == 0) {
        nvAssertFailedNoLog("rmSubDevice","src/kernel/rmapi/nv_gpu_ops.c",0x72b);
        plVar8[1] = 0;
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      plVar8[1] = lVar13;
      *(undefined4 *)((long)plVar8 + 0x14) = *(undefined4 *)(lVar13 + 0x38);
      *(long *)(lVar13 + 0x40) = *(long *)(lVar13 + 0x40) + 1;
      portSyncRwLockReleaseWrite(*(undefined8 *)(lVar7 + 0x38));
      portSyncRwLockReleaseRead(*(undefined8 *)(puVar1 + 4));
LAB_004a78cb:
      if (param_5 == '\0') {
LAB_004a78d4:
        lVar7 = *plVar8;
        if (lVar7 == 0) {
          nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x764);
          lVar7 = *plVar8;
        }
        if ((*(uint *)(lVar7 + 0x54) < 0x140) ||
           ((*(char *)(param_2 + 0x88) != '\0' && (param_5 == '\0')))) {
LAB_004a7a17:
          local_568 = (long *)((ulong)local_568 & 0xffffffff00000000);
          local_440 = (long *)0x0;
          lVar7 = plVar8[1];
          puVar9 = (undefined8 *)rmapiGetInterface(1);
          iVar5 = rmapiLockAcquire(2,0x400);
          if (iVar5 == 0) {
            iVar5 = CliSetGpuContext(*(undefined4 *)plVar8[9],(int)plVar8[2],local_598);
            rmapiLockRelease();
            if (iVar5 == 0) {
              *(undefined8 *)(lVar7 + 0x58) = 0;
              *(undefined8 *)(lVar7 + 0x60) = 0;
              *(undefined4 *)(lVar7 + 0x68) = 0;
              *(undefined2 *)(lVar7 + 0x70) = 0;
              if ((((local_440 == (long *)0x0) || (local_440[0x378] == 0)) ||
                  (cVar4 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(), cVar4 == '\0')) ||
                 (*(long *)(lVar7 + 0x50) != 0)) {
                pcVar14 = (char *)portMemAllocNonPaged(0x6c8);
                if (pcVar14 == (char *)0x0) {
                  iVar5 = 0x51;
                  goto LAB_004a7a57;
                }
                portMemSet(pcVar14,0,0x6c8);
                iVar5 = (*(code *)puVar9[7])
                                  (puVar9,*(undefined4 *)plVar8[9],
                                   *(undefined4 *)((long)plVar8 + 0x14),0x2080012f,pcVar14,0x680);
                if (iVar5 == 0x56) {
                  *(undefined1 *)(lVar7 + 0x71) = 0;
                  portMemFree(pcVar14);
LAB_004a82e7:
                  *(undefined1 *)(lVar7 + 0x70) = 1;
                  goto LAB_004a82ec;
                }
                if (iVar5 != 0) goto LAB_004a8832;
                *(undefined1 *)(lVar7 + 0x71) = 1;
                bVar3 = false;
                pcVar15 = pcVar14;
                do {
                  if (pcVar15[2] != '\0') {
                    if (*pcVar15 == '\0') {
                      *(undefined1 *)(lVar7 + 0x71) = 0;
                    }
                    bVar3 = true;
                  }
                  pcVar15 = pcVar15 + 0x28;
                } while (pcVar15 != pcVar14 + 0x668);
                if (!bVar3) {
                  *(undefined1 *)(lVar7 + 0x71) = 0;
LAB_004a82db:
                  portMemFree(pcVar14);
                  goto LAB_004a82e7;
                }
                if (*(char *)(lVar7 + 0x71) == '\0') goto LAB_004a82db;
                *(undefined4 *)(lVar7 + 0x68) = 0;
                iVar5 = (*(code *)*puVar9)(puVar9,*(undefined4 *)plVar8[9],
                                           *(undefined4 *)((long)plVar8 + 0x14),lVar7 + 0x68,0x90e6,
                                           &local_568,4);
                if (iVar5 == 0) {
                  lVar13 = *plVar8;
                  if (lVar13 == 0) {
                    nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x76a);
                    lVar13 = *plVar8;
                  }
                  if (*(uint *)(lVar13 + 0x54) < 0x160) {
                    iVar5 = (*(code *)puVar9[0xe])
                                      (puVar9,*(undefined4 *)plVar8[9],
                                       *(undefined4 *)((long)plVar8 + 0x14),
                                       *(undefined4 *)(lVar7 + 0x68),0,0x1000);
                    if (iVar5 == 0) {
                      if (*(long *)(lVar7 + 0x60) == 0) {
                        nvAssertFailedNoLog("rmSubDevice->eccReadLocation",
                                            "src/kernel/rmapi/nv_gpu_ops.c",0x538);
                      }
                      iVar5 = (*(code *)puVar9[7])
                                        (puVar9,*(undefined4 *)plVar8[9],
                                         *(undefined4 *)(lVar7 + 0x68),0x90e60101,pcVar14 + 0x680,
                                         0x10);
                      if (iVar5 == 0) {
                        *(undefined4 *)(lVar7 + 0x58) = *(undefined4 *)(pcVar14 + 0x680);
                        uVar6 = *(undefined4 *)(pcVar14 + 0x684);
                        goto LAB_004a89ad;
                      }
                    }
                    goto LAB_004a8832;
                  }
                  puVar18 = (undefined8 *)gpuGetDeviceMapping_IMPL(local_440,0,0);
                  if (puVar18 == (undefined8 *)0x0) {
                    nvAssertFailedNoLog("pMapping","src/kernel/rmapi/nv_gpu_ops.c",0x33d);
                  }
                  *(undefined8 *)(lVar7 + 0x60) = *puVar18;
                  iVar5 = (*(code *)puVar9[7])
                                    (puVar9,*(undefined4 *)plVar8[9],*(undefined4 *)(lVar7 + 0x68),
                                     0x90e60102,pcVar14 + 0x690,8);
                  if (iVar5 != 0) goto LAB_004a8832;
                  *(int *)(lVar7 + 0x58) = *(int *)((long)local_440 + 0x3a64) + 0x30094;
                  uVar6 = *(undefined4 *)(pcVar14 + 0x690);
LAB_004a89ad:
                  *(undefined4 *)(lVar7 + 0x5c) = uVar6;
                  *(code **)(lVar7 + 0x78) = eccErrorCallback;
                  *(long *)(lVar7 + 0x80) = lVar7;
                  *(undefined4 *)(pcVar14 + 0x6b0) = *(undefined4 *)plVar8[9];
                  pcVar14[0x6b8] = '~';
                  pcVar14[0x6b9] = '\0';
                  pcVar14[0x6ba] = '\0';
                  pcVar14[0x6bb] = '\0';
                  pcVar14[0x6bc] = 'p';
                  pcVar14[0x6bd] = '\0';
                  pcVar14[0x6be] = '\0';
                  pcVar14[0x6bf] = '\0';
                  *(long *)(pcVar14 + 0x6c0) = lVar7 + 0x78;
                  *(undefined4 *)(lVar7 + 0x6c) = 0;
                  iVar5 = (*(code *)*puVar9)(puVar9,*(undefined4 *)plVar8[9],
                                             *(undefined4 *)((long)plVar8 + 0x14),lVar7 + 0x6c,0x7e,
                                             pcVar14 + 0x6b0,0x18);
                  if (iVar5 != 0) goto LAB_004a8832;
                  pcVar14[0x698] = 'p';
                  pcVar14[0x699] = '\0';
                  pcVar14[0x69a] = '\0';
                  pcVar14[0x69b] = '\0';
                  pcVar14[0x69c] = '\x01';
                  pcVar14[0x69d] = '\0';
                  pcVar14[0x69e] = '\0';
                  pcVar14[0x69f] = '\0';
                  iVar5 = (*(code *)puVar9[7])
                                    (puVar9,*(undefined4 *)plVar8[9],
                                     *(undefined4 *)((long)plVar8 + 0x14),0x20800301,pcVar14 + 0x698
                                     ,0x14);
                  portMemFree(pcVar14);
                  if (iVar5 == 0) goto LAB_004a82e7;
                }
                else {
LAB_004a8832:
                  portMemFree(pcVar14);
                }
              }
              else {
LAB_004a82ec:
                local_570 = local_570 & 0xffffffff00000000;
                local_440 = (long *)0x0;
                lVar7 = plVar8[1];
                puVar9 = (undefined8 *)rmapiGetInterface(1);
                local_568 = (long *)((ulong)local_568 & 0xffffffff00000000);
                iVar5 = rmapiLockAcquire(2,0x400);
                if (iVar5 == 0) {
                  iVar5 = CliSetGpuContext(*(undefined4 *)plVar8[9],(int)plVar8[2],local_598);
                  rmapiLockRelease();
                  if (iVar5 == 0) {
                    *(undefined8 *)(lVar7 + 0x88) = 0;
                    *(undefined8 *)(lVar7 + 0x90) = 0;
                    *(undefined4 *)(lVar7 + 0x98) = 0;
                    *(undefined2 *)(lVar7 + 0xa0) = 0;
                    pbVar16 = (byte *)portMemAllocNonPaged(0x78);
                    if (pbVar16 != (byte *)0x0) {
                      portMemSet(pbVar16,0,0x78);
                      iVar5 = (*(code *)puVar9[7])
                                        (puVar9,*(undefined4 *)plVar8[9],
                                         *(undefined4 *)((long)plVar8 + 0x14),0x20803001,pbVar16,
                                         0x30);
                      if (((iVar5 != 0) || ((*pbVar16 & 1) == 0)) || ((pbVar16[1] & 0x20) == 0)) {
                        *(undefined1 *)(lVar7 + 0xa1) = 0;
                        portMemFree(pbVar16);
LAB_004a8aaf:
                        *(undefined1 *)(lVar7 + 0xa0) = 1;
                        goto LAB_004a7c17;
                      }
                      if (*(char *)(lVar7 + 0x71) == '\0') {
                        *(undefined4 *)(lVar7 + 0x98) = 0;
                        iVar5 = (*(code *)*puVar9)(puVar9,*(undefined4 *)plVar8[9],
                                                   *(undefined4 *)((long)plVar8 + 0x14),&local_568,
                                                   0x90e6,&local_570,4,0);
                        if (iVar5 == 0) {
                          *(undefined4 *)(lVar7 + 0x98) = local_568._0_4_;
                          goto LAB_004a8454;
                        }
                      }
                      else {
                        local_568 = (long *)CONCAT44(local_568._4_4_,*(undefined4 *)(lVar7 + 0x68));
LAB_004a8454:
                        lVar13 = *plVar8;
                        if (lVar13 == 0) {
                          nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",
                                              0x76a);
                          lVar13 = *plVar8;
                        }
                        if (*(uint *)(lVar13 + 0x54) < 0x160) {
                          iVar5 = (*(code *)puVar9[0xe])
                                            (puVar9,*(undefined4 *)plVar8[9],
                                             *(undefined4 *)((long)plVar8 + 0x14),
                                             (ulong)local_568 & 0xffffffff,0,0x1000,lVar7 + 0x90,1);
                          if (iVar5 == 0) {
                            if (*(long *)(lVar7 + 0x90) == 0) {
                              nvAssertFailedNoLog("rmSubDevice->nvlinkReadLocation",
                                                  "src/kernel/rmapi/nv_gpu_ops.c",0x621);
                            }
                            pbVar19 = pbVar16 + 0x30;
                            iVar5 = (*(code *)puVar9[7])
                                              (puVar9,*(undefined4 *)plVar8[9],
                                               (ulong)local_568 & 0xffffffff,0x90e60101,pbVar19,0x10
                                              );
                            if (iVar5 == 0) {
                              *(undefined4 *)(lVar7 + 0x88) = *(undefined4 *)(pbVar16 + 0x30);
                              uVar6 = *(undefined4 *)(pbVar16 + 0x3c);
                              goto LAB_004a8505;
                            }
                          }
                        }
                        else {
                          puVar18 = (undefined8 *)gpuGetDeviceMapping_IMPL(local_440,0,0);
                          if (puVar18 == (undefined8 *)0x0) {
                            nvAssertFailedNoLog("pMapping","src/kernel/rmapi/nv_gpu_ops.c",0x33d);
                          }
                          *(undefined8 *)(lVar7 + 0x90) = *puVar18;
                          pbVar19 = pbVar16 + 0x40;
                          iVar5 = (*(code *)puVar9[7])
                                            (puVar9,*(undefined4 *)plVar8[9],
                                             (ulong)local_568 & 0xffffffff,0x90e60102,pbVar19,8);
                          if (iVar5 == 0) {
                            *(int *)(lVar7 + 0x88) = *(int *)((long)local_440 + 0x3a64) + 0x30094;
                            uVar6 = *(undefined4 *)(pbVar16 + 0x44);
LAB_004a8505:
                            *(undefined4 *)(lVar7 + 0x8c) = uVar6;
                            *(code **)(lVar7 + 0xa8) = nvlinkErrorCallback;
                            *(long *)(lVar7 + 0xb0) = lVar7;
                            *(undefined4 *)(pbVar16 + 0x60) = *(undefined4 *)plVar8[9];
                            pbVar16[0x68] = 0x7e;
                            pbVar16[0x69] = 0;
                            pbVar16[0x6a] = 0;
                            pbVar16[0x6b] = 0;
                            pbVar16[0x6c] = 0xbe;
                            pbVar16[0x6d] = 0;
                            pbVar16[0x6e] = 0;
                            pbVar16[0x6f] = 0;
                            *(long *)(pbVar16 + 0x70) = lVar7 + 0xa8;
                            *(undefined4 *)(lVar7 + 0x9c) = 0;
                            iVar5 = (*(code *)*puVar9)(puVar9,*(undefined4 *)plVar8[9],
                                                       *(undefined4 *)((long)plVar8 + 0x14),
                                                       lVar7 + 0x9c,0x7e,pbVar16 + 0x60,0x18,pbVar19
                                                      );
                            if (iVar5 == 0) {
                              pbVar16[0x48] = 0xbe;
                              pbVar16[0x49] = 0;
                              pbVar16[0x4a] = 0;
                              pbVar16[0x4b] = 0;
                              pbVar16[0x4c] = 2;
                              pbVar16[0x4d] = 0;
                              pbVar16[0x4e] = 0;
                              pbVar16[0x4f] = 0;
                              iVar5 = (*(code *)puVar9[7])
                                                (puVar9,*(undefined4 *)plVar8[9],
                                                 *(undefined4 *)((long)plVar8 + 0x14),0x20800301,
                                                 pbVar16 + 0x48,0x14);
                              portMemFree(pbVar16);
                              if (iVar5 == 0) goto LAB_004a8aaf;
                              goto LAB_004a85e0;
                            }
                          }
                        }
                      }
                      portMemFree(pbVar16);
                      goto LAB_004a85e0;
                    }
                    iVar5 = 0x51;
                  }
                }
              }
              goto LAB_004a85e8;
            }
          }
LAB_004a7a57:
          gpuDeviceUnmapCpuFreeHandle
                    (plVar8,*(undefined4 *)(plVar8[1] + 0xb8),*(undefined8 *)(plVar8[1] + 0xc0),0);
        }
        else {
          local_440 = (long *)((ulong)local_440 & 0xffffffff00000000);
          puVar9 = (undefined8 *)rmapiGetInterface(1);
          lVar7 = plVar8[1];
          puVar1 = (undefined4 *)plVar8[9];
          local_568 = (long *)CONCAT62(local_568._2_6_,1);
          lVar13 = *plVar8;
          if (lVar13 == 0) {
            nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x777);
            lVar13 = *plVar8;
          }
          uVar21 = *(uint *)(lVar13 + 0x54);
          if ((uVar21 < 0x180) || (uVar21 == 400)) {
            if (uVar21 < 0x140) {
              nvAssertFailedNoLog("isDeviceVoltaPlus(device)","src/kernel/rmapi/nv_gpu_ops.c",0x15bd
                                 );
            }
            pplVar20 = (long **)0x0;
            uVar6 = 0xc361;
            uVar10 = 0;
          }
          else {
            uVar10 = 2;
            pplVar20 = &local_568;
            uVar6 = 0xc661;
          }
          if ((*(int *)(lVar7 + 0xb8) != 0) || (*(long *)(lVar7 + 0xc0) != 0)) {
            nvAssertFailedNoLog("rmSubDevice->clientRegionHandle == 0 && rmSubDevice->clientRegionMapping == NULL"
                                ,"src/kernel/rmapi/nv_gpu_ops.c",0x15be);
          }
          local_440 = (long *)((ulong)local_440 & 0xffffffff00000000);
          iVar5 = (*(code *)*puVar9)(puVar9,*puVar1,*(undefined4 *)((long)plVar8 + 0x14),local_598,
                                     uVar6,pplVar20,uVar10);
          if (iVar5 == 0) {
            iVar5 = (*(code *)puVar9[0xe])
                              (puVar9,*puVar1,*(undefined4 *)((long)plVar8 + 0x14),
                               (ulong)local_440 & 0xffffffff,0,0x10000,lVar7 + 0xc0,2);
            if (iVar5 == 0) {
              *(undefined4 *)(lVar7 + 0xb8) = (undefined4)local_440;
              goto LAB_004a7a17;
            }
            (*(code *)puVar9[3])(puVar9,*(undefined4 *)plVar8[9]);
          }
        }
        nvGpuOpsRmSmcPartitionDestroy(plVar8);
      }
      else {
        lVar7 = plVar8[1];
        if (*(long *)(lVar7 + 0x50) != 0) {
LAB_004a7c17:
          lVar7 = rmapiGetInterface(1);
          local_570 = 0;
          iVar5 = _nvGpuOpsGetGpuFromDevice_constprop_0(plVar8,&local_570);
          if ((iVar5 == 0) && (local_570 != 0)) {
            if (*(char *)(*(long *)(local_570 + 0x4d8) + 0x80) == '\0') {
              puVar11 = (uint *)portMemAllocNonPaged(0x388);
              if (puVar11 == (uint *)0x0) {
LAB_004a8827:
                iVar5 = 0x51;
              }
              else {
                portMemSet(puVar11,0,0x388);
                portMemSet(local_598,0,0x404);
                portMemSet(&local_578,0,8);
                portMemSet(&local_568,0,0x18);
                local_438 = CONCAT44(0x15,(undefined4)local_438);
                local_430 = CONCAT44(0x18,(undefined4)local_430);
                local_428 = CONCAT44(0x1e,(undefined4)local_428);
                local_440 = (long *)0x900000004;
                iVar5 = (**(code **)(lVar7 + 0x38))
                                  (lVar7,*(undefined4 *)plVar8[9],
                                   *(undefined4 *)((long)plVar8 + 0x14),0x20801303,local_598,0x404);
                if (((iVar5 == 0) &&
                    (iVar5 = (**(code **)(lVar7 + 0x38))
                                       (lVar7,*(undefined4 *)plVar8[9],
                                        *(undefined4 *)((long)plVar8 + 0x14),0x20801320,puVar11,
                                        0x388), iVar5 == 0)) &&
                   (iVar5 = (**(code **)(lVar7 + 0x38))
                                      (lVar7,*(undefined4 *)plVar8[9],
                                       *(undefined4 *)((long)plVar8 + 0x14),0x20800188,&local_578,8)
                   , iVar5 == 0)) {
                  plVar8[0xb] = CONCAT44((undefined4)local_430,(undefined4)local_438);
                  *(char *)(plVar8 + 0xc) = (char)local_428;
                  *(undefined4 *)(plVar8 + 0x11) = (undefined4)local_420;
                  plVar8[10] = 0;
                  plVar8[0xd] = CONCAT44(uStack_574,local_578);
                  if (*puVar11 != 0) {
                    uVar12 = 0;
                    uVar22 = 0;
                    do {
                      if (uVar12 < *(ulong *)(puVar11 + uVar22 * 0xe + 4)) {
                        uVar12 = *(ulong *)(puVar11 + uVar22 * 0xe + 4);
                      }
                      uVar21 = (int)uVar22 + 1;
                      uVar22 = (ulong)uVar21;
                      plVar8[10] = uVar12;
                    } while (uVar21 < *puVar11);
                  }
                  iVar5 = (**(code **)(lVar7 + 0x38))
                                    (lVar7,*(undefined4 *)plVar8[9],
                                     *(undefined4 *)((long)plVar8 + 0x14),0x20801354,&local_568,0x18
                                    );
                  if (iVar5 == 0) {
                    *(undefined2 *)(plVar8 + 0xe) = local_568._0_2_;
                    plVar8[0xf] = local_560;
                    plVar8[0x10] = local_558;
                    portMemFree(puVar11);
                    goto LAB_004a8608;
                  }
                }
                portMemFree(puVar11);
              }
            }
            else {
              portMemSet(plVar8 + 10,0,0x40);
LAB_004a8608:
              *(undefined2 *)(plVar8 + 8) = 0x100;
              iVar5 = findDeviceClasses_isra_0
                                (*param_1,(int)plVar8[2],(long)plVar8 + 0x24,plVar8 + 5,plVar8 + 6,
                                 (long)plVar8 + 0x34,plVar8 + 7,(long)plVar8 + 0x3c,
                                 (long)plVar8 + 0x2c);
              if (iVar5 == 0) {
                uVar10 = portMemAllocatorGetGlobalNonPaged();
                mapInit_IMPL(plVar8 + 0x30,uVar10,8);
                iVar5 = rmapiLockAcquire(2,0x400);
                if (iVar5 == 0) {
                  iVar5 = CliSetGpuContext(*param_1,(int)plVar8[2],local_598,0);
                  rmapiLockRelease();
                  if (iVar5 == 0) {
                    if ((*(char *)((long)local_440 + 0x4913) == '\0') ||
                       (*(char *)((long)local_440 + 0x491e) == '\0')) {
LAB_004a86c1:
                      *param_4 = plVar8;
                      return 0;
                    }
                    uVar10 = portMemAllocatorGetGlobalNonPaged();
                    lVar7 = portSyncMutexCreate(uVar10);
                    plVar8[0x34] = lVar7;
                    if (lVar7 != 0) goto LAB_004a86c1;
                    goto LAB_004a8827;
                  }
                }
              }
            }
          }
          else {
            iVar5 = 0x1f;
            nvAssertFailedNoLog("(nvStatus == NV_OK) && (pGpu != NULL)",
                                "src/kernel/rmapi/nv_gpu_ops.c",0x79b);
          }
LAB_004a85e0:
          gpuDeviceRmSubDeviceDeinitNvlink(plVar8);
LAB_004a85e8:
          gpuDeviceRmSubDeviceDeinitEcc(plVar8);
          goto LAB_004a7a57;
        }
        local_568 = (long *)0x0;
        local_578 = 0;
        lVar13 = rmapiGetInterface(1);
        puVar1 = (undefined4 *)plVar8[9];
        if (*(long *)(lVar7 + 0x50) != 0) {
          nvAssertFailedNoLog("rmSubDevice->smcPartition.info == NULL",
                              "src/kernel/rmapi/nv_gpu_ops.c",0x6c4);
        }
        if (*(char *)(param_2 + 0x88) == '\0') {
          iVar5 = 0x1f;
        }
        else {
          iVar5 = rmapiLockAcquire(2,0x400);
          if (iVar5 == 0) {
            iVar5 = CliSetGpuContext(*puVar1,(int)plVar8[2],&local_568,0);
            rmapiLockRelease();
            if (iVar5 == 0) {
              if ((local_568 != (long *)0x0) && (local_568[0x378] != 0)) {
                uVar10 = 0x4a7fff;
                cVar4 = kmigmgrIsMIGGpuInstancingEnabled_IMPL();
                if (cVar4 != '\0') {
                  iVar5 = (**(code **)(lVar13 + 0x50))
                                    (lVar13,*puVar1,*(undefined4 *)(lVar7 + 0x38),&local_578,
                                     *(undefined4 *)(param_2 + 0x90));
                  if (iVar5 == 0) {
                    iVar5 = getSwizzIdFromSmcPartHandle_isra_0(*puVar1,local_578,&local_570,uVar10);
                    if (iVar5 == 0) {
                      if (*(int *)(param_2 + 0x8c) == (int)local_570) {
                        *(undefined4 *)(lVar7 + 0x48) = local_578;
                        iVar5 = rmapiLockAcquire(2,0x400);
                        if (iVar5 == 0) {
                          iVar5 = serverutilGetResourceRef
                                            (*puVar1,*(undefined4 *)(lVar7 + 0x48),local_598);
                          rmapiLockRelease();
                          if (iVar5 == 0) {
                            lVar13 = __nvoc_dynamicCast(local_440[1],
                                                        __nvoc_class_def_GPUInstanceSubscription);
                            if (lVar13 == 0) {
                              nvAssertFailedNoLog("pGPUInstanceSubscription != NULL",
                                                  "src/kernel/rmapi/nv_gpu_ops.c",0x700);
                            }
                            lVar17 = *(long *)(lVar13 + 0x138);
                            if (*(int *)(lVar17 + 0x968) != *(int *)(param_2 + 0x8c)) {
                              nvAssertFailedNoLog("gisubscriptionGetMIGGPUInstance(pGPUInstanceSubscription)->swizzId == pGpuInfo->smcSwizzId"
                                                  ,"src/kernel/rmapi/nv_gpu_ops.c",0x702);
                              lVar17 = *(long *)(lVar13 + 0x138);
                            }
                            *(long *)(lVar7 + 0x50) = lVar17;
                            goto LAB_004a78d4;
                          }
                        }
                      }
                      else {
                        iVar5 = 0x40;
                      }
                    }
                    (**(code **)(lVar13 + 0x18))(lVar13,*puVar1,local_578);
                  }
                  goto LAB_004a7a7a;
                }
              }
              iVar5 = 0x40;
            }
          }
        }
      }
LAB_004a7a7a:
      nvGpuOpsDeviceDestroy(plVar8);
      plVar8 = (long *)0x0;
      goto LAB_004a7672;
    }
    lVar13 = portMemAllocNonPaged(0xd8);
    if (lVar13 == 0) {
      iVar5 = 0x1a;
    }
    else {
      portMemSet(lVar13,0,0xd8);
      plVar8[1] = lVar13;
      *(undefined8 *)(lVar13 + 0x40) = 1;
      local_568 = (long *)CONCAT44(local_568._4_4_,*(undefined4 *)((long)plVar8 + 0x1c));
      *(undefined4 *)((long)plVar8 + 0x14) = 0;
      iVar5 = (*(code *)*puVar9)(puVar9,*puVar1,(int)plVar8[2],(long)plVar8 + 0x14,0x2080,&local_568
                                 ,4);
      if (iVar5 == 0) {
        *(undefined4 *)(lVar13 + 0x38) = *(undefined4 *)((long)plVar8 + 0x14);
        uVar21 = *(uint *)((long)plVar8 + 0x1c);
        *(long *)lVar13 = lVar13;
        *(ulong *)(lVar13 + 8) = (ulong)uVar21;
        *(ulong *)(lVar13 + 0x10) = (ulong)uVar21;
        iVar5 = btreeInsert(lVar13,lVar7 + 0x48);
        if (iVar5 == 0) {
          *(int *)(lVar7 + 0x50) = *(int *)(lVar7 + 0x50) + 1;
          portSyncRwLockReleaseWrite(*(undefined8 *)(lVar7 + 0x38));
          portSyncRwLockReleaseRead(*(undefined8 *)(puVar1 + 4));
          goto LAB_004a78cb;
        }
        (*(code *)puVar9[3])(puVar9,*puVar1,*(undefined4 *)((long)plVar8 + 0x14));
      }
      portMemFree(lVar13);
      portSyncRwLockReleaseWrite(*(undefined8 *)(lVar7 + 0x38));
      portSyncRwLockReleaseRead(*(undefined8 *)(puVar1 + 4));
    }
  }
  else {
    portSyncRwLockReleaseRead(*(undefined8 *)(puVar1 + 4));
  }
  nvGpuOpsRmDeviceDestroy(plVar8);
LAB_004a7672:
  portMemFree(plVar8);
  return iVar5;
}


// ===== 004a8e10 nvGpuOpsOwnPageFaultIntr =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

void nvGpuOpsOwnPageFaultIntr(long param_1,char param_2)

{
  long lVar1;
  undefined1 local_19;
  
  lVar1 = rmapiGetInterface(1);
  local_19 = param_2 == '\0';
  (**(code **)(lVar1 + 0x38))
            (lVar1,**(undefined4 **)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x14),0x2080170c,
             &local_19,1);
  return;
}


// ===== 004a8e70 nvGpuOpsAddressSpaceCreate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsAddressSpaceCreate
              (long param_1,undefined8 param_2,undefined8 param_3,char param_4,undefined8 *param_5,
              undefined8 param_6)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  undefined8 local_78;
  long local_70;
  long local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_78 = 0;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  puVar2 = (undefined8 *)rmapiGetInterface(1);
  uVar3 = portMemAllocatorGetGlobalNonPaged();
  puVar4 = (undefined4 *)portMemAllocNonPaged(0x68);
  if (puVar4 == (undefined4 *)0x0) {
    return 0x51;
  }
  portMemSet(puVar4,0,0x68);
  *puVar4 = 0;
  *(undefined8 *)(puVar4 + 0x10) = param_2;
  *(undefined8 *)(puVar4 + 0x12) = param_3;
  uVar5 = portSyncRwLockCreate(uVar3);
  *(undefined8 *)(puVar4 + 6) = uVar5;
  uVar5 = portSyncRwLockCreate(uVar3);
  *(undefined8 *)(puVar4 + 10) = uVar5;
  uVar3 = portSyncRwLockCreate(uVar3);
  *(undefined8 *)(puVar4 + 0xe) = uVar3;
  *param_5 = 0;
  portMemSet(param_6,0,0x30);
  local_48 = *(undefined8 *)(puVar4 + 0x10);
  local_68 = *(long *)(puVar4 + 0x12);
  if (local_68 == 0) {
    local_70 = 0;
    if (param_4 != '\0') {
      iVar1 = 0x1f;
      nvAssertOkFailedNoLog
                (0x1f,"vaParams.flags != NV_VASPACE_ALLOCATION_FLAGS_NONE",
                 "src/kernel/rmapi/nv_gpu_ops.c",0x9f6);
      goto LAB_004a9036;
    }
  }
  else {
    local_70 = (ulong)((-(uint)(param_4 == '\0') & 0xfffffff0) + 0x14) << 0x20;
  }
  iVar1 = rmapiLockAcquire(2,0x400);
  if (iVar1 == 0) {
    iVar1 = CliSetGpuContext(**(undefined4 **)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x10),
                             &local_78,0);
    rmapiLockRelease();
    if ((iVar1 == 0) &&
       (iVar1 = (*(code *)*puVar2)(puVar2,**(undefined4 **)(param_1 + 0x48),
                                   *(undefined4 *)(param_1 + 0x10),puVar4,0x90f1,&local_70,0x38),
       iVar1 == 0)) {
      *(undefined8 *)(puVar4 + 0x10) = local_48;
      *(long *)(puVar4 + 2) = param_1;
      *(long *)(puVar4 + 0x12) = local_68;
      iVar1 = getAddressSpaceInfo(puVar4,local_78,param_6);
      if (iVar1 == 0) {
        *param_5 = puVar4;
        return 0;
      }
    }
  }
  (*(code *)puVar2[3])(puVar2,**(undefined4 **)(param_1 + 0x48),*puVar4);
LAB_004a9036:
  portSyncRwLockDestroy(*(undefined8 *)(puVar4 + 6));
  portSyncRwLockDestroy(*(undefined8 *)(puVar4 + 10));
  portSyncRwLockDestroy(*(undefined8 *)(puVar4 + 0xe));
  portMemFree(puVar4);
  return iVar1;
}


// ===== 004a9100 nvGpuOpsDupAddressSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsDupAddressSpace
              (long param_1,undefined4 param_2,undefined4 param_3,undefined8 *param_4,
              undefined8 param_5)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  long *local_60;
  undefined8 local_58;
  long local_50;
  long local_48;
  undefined8 local_40 [2];
  
  puVar1 = *(undefined4 **)(param_1 + 0x48);
  local_60 = (long *)0x0;
  local_58 = 0;
  lVar4 = rmapiGetInterface(1);
  uVar5 = portMemAllocatorGetGlobalNonPaged();
  *param_4 = 0;
  portMemSet(param_5,0,0x30);
  iVar3 = rmapiLockAcquire(2,0x400);
  if (iVar3 != 0) {
    return iVar3;
  }
  iVar3 = serverutilGetResourceRef(param_2,param_3,&local_50);
  rmapiLockRelease();
  if (iVar3 != 0) {
    return iVar3;
  }
  lVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_50 + 8),__nvoc_class_def_VaSpaceApi);
  if (lVar6 == 0) {
    return 0x31;
  }
  iVar3 = rmapiLockAcquire(2,0x400);
  if (iVar3 == 0) {
    iVar3 = serverutilGetResourceRef
                      (param_2,*(undefined4 *)(*(long *)(local_50 + 0x18) + 0x10),&local_48);
    rmapiLockRelease();
    if (iVar3 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0xa54);
    }
    lVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),__nvoc_class_def_Device);
    if (lVar6 == 0) {
      nvAssertFailedNoLog("pDevice != NULL","src/kernel/rmapi/nv_gpu_ops.c",0xa57);
    }
    if (*(int *)(lVar6 + 0x180) == *(int *)(param_1 + 0x18)) {
      puVar7 = (undefined4 *)portMemAllocNonPaged(0x68);
      if (puVar7 == (undefined4 *)0x0) {
        return 0x51;
      }
      portMemSet(puVar7,0,0x68);
      *(long *)(puVar7 + 2) = param_1;
      uVar8 = portSyncRwLockCreate(uVar5);
      *(undefined8 *)(puVar7 + 6) = uVar8;
      uVar8 = portSyncRwLockCreate(uVar5);
      *(undefined8 *)(puVar7 + 10) = uVar8;
      uVar5 = portSyncRwLockCreate(uVar5);
      *puVar7 = 0;
      *(undefined8 *)(puVar7 + 0xe) = uVar5;
      iVar3 = (**(code **)(lVar4 + 0x50))
                        (lVar4,*puVar1,*(undefined4 *)(param_1 + 0x10),puVar7,param_2,param_3,1);
      if (iVar3 == 0) {
        iVar3 = rmapiLockAcquire(2,0x400,0x4a92ab);
        if (iVar3 == 0) {
          iVar3 = serverGetClientUnderLock(g_resServ,*puVar1,local_40);
          if ((iVar3 == 0) &&
             (iVar3 = CliSetGpuContext(*puVar1,*(undefined4 *)(param_1 + 0x10),&local_58,0),
             iVar3 == 0)) {
            iVar3 = vaspaceGetByHandleOrDeviceDefault_IMPL
                              (local_40[0],*(undefined4 *)(param_1 + 0x10),*puVar7,&local_60);
            rmapiLockRelease();
            if (iVar3 == 0) {
              cVar2 = (**(code **)(*local_60 + 0xb0))();
              iVar3 = 0x29;
              if ((cVar2 != '\0') &&
                 (iVar3 = getAddressSpaceInfo(puVar7,local_58,param_5), iVar3 == 0)) {
                *param_4 = puVar7;
                return 0;
              }
            }
          }
          else {
            rmapiLockRelease();
          }
        }
        (**(code **)(lVar4 + 0x18))(lVar4,*puVar1,*puVar7);
      }
      portSyncRwLockDestroy(*(undefined8 *)(puVar7 + 6));
      portSyncRwLockDestroy(*(undefined8 *)(puVar7 + 10));
      portSyncRwLockDestroy(*(undefined8 *)(puVar7 + 0xe));
      portMemFree(puVar7);
      return iVar3;
    }
    return 0x5a;
  }
  return iVar3;
}


// ===== 004a9470 _nvGpuOpsIsBar1P2pAtomicEnabled =====

bool _nvGpuOpsIsBar1P2pAtomicEnabled(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  uint uVar2;
  long *local_20;
  
  iVar1 = *(int *)(param_3 + 0x7ac);
  local_20 = (long *)0x0;
  portSyncRwLockAcquireRead(*(undefined8 *)(param_1 + 0x10));
  btreeEnumStart(0,&local_20,*(undefined8 *)(param_1 + 8));
  while( true ) {
    if (local_20 == (long *)0x0) {
      portSyncRwLockReleaseRead(*(undefined8 *)(param_1 + 0x10));
      nvAssertFailedNoLog("status == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0xc52);
      return false;
    }
    if (iVar1 == *(int *)(*local_20 + 0x5c)) break;
    btreeEnumNext(&local_20,*(undefined8 *)(param_1 + 8));
  }
  uVar2 = *(uint *)(*local_20 + 0x54);
  portSyncRwLockReleaseRead(*(undefined8 *)(param_1 + 0x10));
  return 0x19f < uVar2;
}


// ===== 004a9530 nvGpuOpsGetExternalAllocAperture =====

int nvGpuOpsGetExternalAllocAperture
              (undefined8 param_1,long *param_2,byte param_3,char param_4,char param_5,int param_6)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined8 extraout_RDX;
  
  if ((param_4 == '\0') || ((param_3 & 1) == 0)) {
    iVar3 = memdescGetAddressSpace(param_2);
    if (iVar3 == 2) {
      if (param_3 != 0) {
        return 4;
      }
      if (param_5 == '\0') {
        return 2 - (uint)(param_4 == '\0');
      }
      bVar2 = _nvGpuOpsIsBar1P2pAtomicEnabled(param_1,0,*param_2);
      return bVar2 + 3;
    }
  }
  else {
    nvAssertFailedNoLog("!(isIndirectPeerSupported && isPeerSupported)",
                        "src/kernel/rmapi/nv_gpu_ops.c",0xdfc);
    iVar3 = memdescGetAddressSpace(param_2);
    if (iVar3 == 2) {
      return 4;
    }
  }
  iVar3 = memdescGetAddressSpace(param_2);
  if (((iVar3 == 7) || (iVar3 = memdescGetAddressSpace(param_2), iVar3 == 6)) ||
     (cVar1 = memdescIsEgm(param_2), cVar1 != '\0')) {
    return 2;
  }
  if (((*(char *)(*(long *)(*param_2 + 0x1b78) + 0x447) != '\0') && ((int)param_2[0xf] != 2)) &&
     (param_6 != 1)) {
    return ((uint)(param_6 == 0) &
           (uint)CONCAT71((int7)((ulong)extraout_RDX >> 8),*(int *)((long)param_2 + 0x6c) != 0)) + 3
    ;
  }
  return 4;
}


// ===== 004a96a0 nvGpuOpsBuildExternalAllocPtes =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Type propagation algorithm not settling */

int nvGpuOpsBuildExternalAllocPtes
              (undefined8 param_1,undefined8 param_2,long param_3,long *param_4,long param_5,
              ulong param_6,ulong param_7,byte param_8,undefined1 param_9,char param_10,int param_11
              ,int *param_12)

{
  byte bVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  bool bVar7;
  undefined4 uVar8;
  char cVar9;
  byte bVar10;
  byte bVar11;
  undefined1 uVar12;
  char cVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  undefined8 uVar17;
  uint *puVar18;
  byte *pbVar19;
  ulong uVar20;
  ulong uVar21;
  long lVar22;
  ulong *puVar23;
  uint *puVar24;
  undefined8 *puVar25;
  ulong *puVar26;
  uint uVar27;
  ulong uVar28;
  ulong uVar29;
  char *pcVar30;
  uint uVar31;
  ulong uVar32;
  ulong uVar33;
  long lVar34;
  bool bVar35;
  ulong *local_118;
  char *local_110;
  bool local_f9;
  undefined8 local_e8;
  undefined8 *local_d8;
  ulong local_90;
  int local_88;
  int local_84;
  ulong local_80;
  long local_78;
  ulong local_70;
  ulong local_68 [2];
  undefined4 local_58;
  undefined4 uStack_54;
  undefined8 local_50;
  undefined4 local_48;
  
  lVar2 = *(long *)(param_3 + 0x1b78);
  lVar3 = *(long *)(param_3 + 0x1b70);
  lVar34 = *(long *)(param_3 + 0x1b98);
  local_68[0] = 0;
  uVar28 = *(ulong *)(param_12 + 8);
  local_68[1] = 0;
  if (1 < *(uint *)((long)param_4 + 0x8c)) {
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/rmapi/nv_gpu_ops.c",
                        0xf46);
  }
  iVar14 = nvGpuOpsMemGetPageSize(param_3,param_4,&local_80);
  if (iVar14 != 0) {
    return iVar14;
  }
  uVar33 = local_80;
  if (uVar28 != 0) {
    if (local_80 < uVar28) {
      return 0x1f;
    }
    uVar33 = uVar28;
    if (local_80 % uVar28 != 0) {
      return 0x1f;
    }
  }
  uVar28 = (local_80 - 1) + param_4[7] & -local_80;
  if (uVar28 <= param_6) {
    return 0x20;
  }
  if (uVar28 < param_7 + param_6) {
    return 0x2e;
  }
  if ((uVar33 - 1 & (param_7 | param_6)) != 0) {
    return 0x1f;
  }
  uVar17 = __nvoc_dynamicCast(param_1,__nvoc_class_def_OBJGVASPACE);
  puVar18 = (uint *)gvaspaceGetGmmuFmt_IMPL(uVar17,param_3);
  lVar4 = *(long *)(puVar18 + 8);
  pbVar19 = (byte *)mmuFmtFindLevelWithPageShift
                              (*(undefined8 *)(puVar18 + 2),
                               (uVar33 >> 0x20 != 0) << 5 | (uVar33 & 0xaaaaaaaaaaaaaaaa) != 0 |
                               ((uVar33 & 0xffff0000ffff0000) != 0) << 4 |
                               ((uVar33 & 0xff00ff00ff00ff00) != 0) << 3 |
                               ((uVar33 & 0xf0f0f0f0f0f0f0f0) != 0) << 2 |
                               ((uVar33 & 0xcccccccccccccccc) != 0) * '\x02');
  iVar14 = memdescGetPteKindForGpu(param_4,param_3);
  local_84 = iVar14;
  if (param_5 == 0) {
LAB_004a9a7b:
    local_d8 = (undefined8 *)&stack0xffffffffffffffa8;
    iVar14 = memmgrGetKindComprForGpu_KERNEL(lVar2,param_4,param_3,0,&local_88,local_d8);
    if (iVar14 != 0) {
      return iVar14;
    }
  }
  else {
    _local_58 = 0;
    local_50 = 0;
    local_48 = 0;
    if (param_12[4] == 1) {
      cVar9 = (**(code **)(lVar2 + 0x2a8))(lVar2,5,iVar14);
      if (cVar9 == '\0') {
        return 0x1f;
      }
      iVar16 = (**(code **)(lVar2 + 0x2a0))(param_3,lVar2,&stack0xffffffffffffffa8,3,&local_84);
      if (iVar16 != 0) {
        return iVar16;
      }
    }
    local_d8 = (undefined8 *)&stack0xffffffffffffffa8;
    iVar16 = param_12[2];
    uVar15 = param_12[3];
    if (iVar16 == 0) {
      if (1 < uVar15) {
        nvAssertFailedNoLog("(pGpuExternalMappingInfo->elementBits == UvmGpuFormatElementBitsDefault) || (pGpuExternalMappingInfo->elementBits == UvmGpuFormatElementBits8)"
                            ,"src/kernel/rmapi/nv_gpu_ops.c",0xed4);
      }
    }
    else {
      if (uVar15 == 0) {
        nvAssertFailedNoLog("pGpuExternalMappingInfo->elementBits != UvmGpuFormatElementBitsDefault"
                            ,"src/kernel/rmapi/nv_gpu_ops.c",0xe97);
        iVar16 = param_12[2];
        uVar15 = param_12[3];
      }
      _local_58 = *(ulong *)(param_5 + 0x188);
      local_50 = CONCAT44(local_50._4_4_,*(undefined4 *)(param_5 + 0x198));
      local_48 = *(undefined4 *)(param_5 + 0x194);
      uVar31 = (uint)_local_58;
      if (iVar16 == 1) {
        uVar31 = uVar31 & 0xfffcffff | 0x20000;
        _local_58 = _local_58 & 0xfffffffffffcffff | 0x20000;
      }
      if (uVar15 == 4) {
        uVar27 = uVar31 & 0xfffffff8;
        _local_58 = CONCAT44(uStack_54,uVar31) & 0xfffffffffffffff8 | 4;
      }
      else {
        uVar27 = uVar31;
        if (uVar15 < 5) {
          if (uVar15 == 1) {
            _local_58 = CONCAT44(uStack_54,uVar31) & 0xfffffffffffffff8 | 1;
            uVar27 = uVar31 & 0xfffffff8;
          }
          else if (uVar15 == 2) {
            _local_58 = CONCAT44(uStack_54,uVar31) & 0xfffffffffffffff8 | 2;
            uVar27 = uVar31 & 0xfffffff8;
          }
        }
        else if (uVar15 == 5) {
          uVar27 = uVar31 & 0xfffffff8;
          _local_58 = CONCAT44(uStack_54,uVar31) & 0xfffffffffffffff8 | 5;
        }
        else if (uVar15 == 6) {
          uVar27 = uVar31 & 0xfffffff8;
          _local_58 = CONCAT44(uStack_54,uVar31) & 0xfffffffffffffff8 | 6;
        }
      }
      iVar16 = (**(code **)(lVar2 + 0x2a0))(param_3,lVar2,local_d8,uVar27 >> 0xc & 3,&local_84);
      if (iVar16 != 0) {
        nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0xec2,"nvGpuOpsGetPteKind",4,
                     "NVRM: Invalid kind type (%x)\n",local_84);
        return iVar16;
      }
      lVar22 = param_4[0x13];
      cVar9 = (**(code **)(lVar2 + 0x2a8))(lVar2,5);
      if ((cVar9 != '\0') && ((short)lVar22 == 0)) {
        local_84 = (**(code **)(lVar2 + 0x290))(param_3,lVar2,local_84,0,*(code **)(lVar2 + 0x290));
      }
      if (local_84 == 0xff) {
        return 0x1f;
      }
    }
    local_d8 = (undefined8 *)&stack0xffffffffffffffa8;
    if (iVar14 == local_84) goto LAB_004a9a7b;
    memdescSetPteKindForGpu(param_4,param_3,local_84);
    iVar16 = memmgrGetKindComprForGpu_KERNEL(lVar2,param_4,param_3,0,&local_88,local_d8);
    if (iVar16 != 0) {
      return iVar16;
    }
    memdescSetPteKindForGpu(param_4,param_3,iVar14);
  }
  local_d8 = (undefined8 *)&stack0xffffffffffffffa8;
  uVar15 = nvGpuOpsGetExternalAllocAperture(param_2,param_4,param_8,param_9,param_10,*param_12);
  if (*param_12 == 0) {
    if ((param_10 == '\0' && (param_8 & 1) == 0) && (uVar15 != 2)) {
      local_f9 = *(int *)((long)param_4 + 0x6c) == 1;
    }
    else {
      iVar14 = memdescGetGpuP2PCacheAttrib(param_4);
      local_f9 = iVar14 == 1;
    }
  }
  else {
    local_f9 = *param_12 == 1;
  }
  uVar31 = param_12[1];
  cVar9 = memdescGetFlag(param_4,0x200000000);
  if (cVar9 == '\0') {
    bVar35 = uVar31 == 3;
    bVar7 = uVar31 < 2;
  }
  else {
    if ((uVar31 != 0) && (uVar31 != 3)) {
      return 0x1d;
    }
    bVar35 = true;
    bVar7 = false;
  }
  bVar10 = memdescGetFlag(param_4,0x800);
  bVar11 = memdescGetFlag(param_4,0x2000);
  if (param_7 != 0) {
    uVar28 = param_7;
  }
  bVar1 = pbVar19[2];
  cVar9 = (**(code **)(lVar2 + 0x2a8))(lVar2,5,local_88);
  if (((cVar9 != '\0') && (*(ulong *)(param_12 + 8) != local_80)) && (*(ulong *)(param_12 + 8) != 0)
     ) {
    return 0x56;
  }
  uVar28 = uVar28 / uVar33;
  uVar20 = *(ulong *)(param_12 + 6) / (ulong)pbVar19[2];
  if (uVar28 < *(ulong *)(param_12 + 6) / (ulong)pbVar19[2]) {
    uVar20 = uVar28;
  }
  if (uVar20 == 0) {
    return 2;
  }
  if (*puVar18 == 3) {
    local_70 = local_70 & 0xffffffff00000000;
    *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0xe)) =
         (uint)(*(byte *)(lVar4 + 0x10) ^ 1) << ((byte)*(undefined2 *)(lVar4 + 0xc) & 0x1f) |
         *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0xe)) & *(uint *)(lVar4 + 8);
    *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x22)) =
         (uint)*(byte *)(*(long *)(lVar4 + 0x28) + 1 + (ulong)uVar15 * 2) <<
         ((byte)*(undefined2 *)(lVar4 + 0x20) & 0x1f) |
         *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x22)) & *(uint *)(lVar4 + 0x1c);
    *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x186)) =
         *(uint *)(lVar4 + 0x180) & *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x186)) |
         local_88 << ((byte)*(undefined2 *)(lVar4 + 0x184) & 0x1f);
    uVar31 = (uint)(bVar11 == 0) << 8 |
             (uint)(bVar7 ^ 1) << 6 | (uint)local_f9 << 5 | (uint)bVar35 << 7;
    iVar14 = memdescGetAddressSpace(param_4);
    if (iVar14 == 7) {
      uVar31 = uVar31 | 0x10;
    }
    iVar14 = (**(code **)(lVar34 + 0x280))(lVar34,uVar31,&local_70);
    if (iVar14 != 0) {
      nvCheckFailedNoLog(4,
                         "(kgmmuTranslatePtePcfFromSw_HAL(pKernelGmmu, ptePcfSw, &ptePcfHw) == NV_OK)"
                         ,"src/kernel/rmapi/nv_gpu_ops.c",0xfd0);
      return 0x1f;
    }
    *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x1aa)) =
         (int)local_70 << ((byte)*(undefined2 *)(lVar4 + 0x1a8) & 0x1f) |
         *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x1aa)) & *(uint *)(lVar4 + 0x1a4);
  }
  else {
    if (*(int *)(lVar4 + 4) != 0) {
      *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0xe)) =
           (uint)(*(byte *)(lVar4 + 0x10) ^ 1) << ((byte)*(undefined2 *)(lVar4 + 0xc) & 0x1f) |
           *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0xe)) & *(uint *)(lVar4 + 8);
    }
    if (*(int *)(lVar4 + 0xfc) != 0) {
      *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x106)) =
           (uint)(local_f9 ^ *(byte *)(lVar4 + 0x108)) <<
           ((byte)*(undefined2 *)(lVar4 + 0x104) & 0x1f) |
           *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x106)) & *(uint *)(lVar4 + 0x100);
    }
    if (*(int *)(lVar4 + 0x13c) != 0) {
      *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x146)) =
           (uint)(bVar11 ^ *(byte *)(lVar4 + 0x148)) <<
           ((byte)*(undefined2 *)(lVar4 + 0x144) & 0x1f) |
           *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x146)) & *(uint *)(lVar4 + 0x140);
    }
    if (*(int *)(lVar4 + 0x14c) != 0) {
      *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x156)) =
           (uint)(bVar10 ^ *(byte *)(lVar4 + 0x158)) <<
           ((byte)*(undefined2 *)(lVar4 + 0x154) & 0x1f) |
           *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x156)) & *(uint *)(lVar4 + 0x150);
    }
    if (*(int *)(lVar4 + 0x10c) != 0) {
      *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x116)) =
           (uint)(bVar35 ^ *(byte *)(lVar4 + 0x118)) <<
           ((byte)*(undefined2 *)(lVar4 + 0x114) & 0x1f) |
           *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x116)) & *(uint *)(lVar4 + 0x110);
    }
    if (*(int *)(lVar4 + 300) != 0) {
      *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x136)) =
           (uint)(bVar35 ^ *(byte *)(lVar4 + 0x138)) <<
           ((byte)*(undefined2 *)(lVar4 + 0x134) & 0x1f) |
           *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x136)) & *(uint *)(lVar4 + 0x130);
    }
    if (*(int *)(lVar4 + 0x11c) != 0) {
      *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x126)) =
           (uint)*(byte *)(lVar4 + 0x128) << ((byte)*(undefined2 *)(lVar4 + 0x124) & 0x1f) |
           *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x126)) & *(uint *)(lVar4 + 0x120);
    }
    if (*(int *)(lVar4 + 0x16c) != 0) {
      *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x176)) =
           (uint)(byte)(bVar7 ^ *(byte *)(lVar4 + 0x178) ^ 1) <<
           ((byte)*(undefined2 *)(lVar4 + 0x174) & 0x1f) |
           *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x176)) & *(uint *)(lVar4 + 0x170);
    }
    *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x22)) =
         (uint)*(byte *)(*(long *)(lVar4 + 0x28) + 1 + (ulong)uVar15 * 2) <<
         ((byte)*(undefined2 *)(lVar4 + 0x20) & 0x1f) |
         *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x22)) & *(uint *)(lVar4 + 0x1c);
    if (cVar9 == '\0') {
      *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x186)) =
           local_88 << ((byte)*(undefined2 *)(lVar4 + 0x184) & 0x1f) |
           *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x186)) & *(uint *)(lVar4 + 0x180);
      puVar24 = (uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x192));
      *puVar24 = *puVar24 & *(uint *)(lVar4 + 0x18c);
      if (*(int *)(lVar4 + 0x194) != 0) {
        puVar24 = (uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x19e));
        *puVar24 = *puVar24 & *(uint *)(lVar4 + 0x198);
      }
    }
  }
  if (uVar15 == 2) {
    *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0xfa)) =
         *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0xfa)) & *(uint *)(lVar4 + 0xf4) |
         param_11 << ((byte)*(undefined2 *)(lVar4 + 0xf8) & 0x1f);
    iVar14 = memdescGetAddressSpace(param_4);
    if ((iVar14 == 7) || (iVar14 = memdescGetAddressSpace(param_4), iVar14 == 6)) goto LAB_004a9fed;
    cVar13 = memdescIsEgm(param_4);
    lVar22 = *param_4;
    if (((cVar13 != '\0') && (param_3 == lVar22)) ||
       (lVar6 = *(long *)(lVar22 + 0x1ce8), lVar6 == 0)) goto LAB_004a9fed;
    if ((*(char *)(lVar22 + 0x4cc) == '\x01') || (*(char *)(lVar22 + 0x4915) == '\0')) {
      cVar13 = memdescIsEgm(param_4);
      puVar25 = (undefined8 *)(lVar6 + 0x16a8);
      if (cVar13 != '\0') {
        puVar25 = (undefined8 *)(lVar6 + 0x16b0);
      }
      local_e8 = *puVar25;
    }
    else {
      cVar13 = memdescIsEgm(param_4);
      if (cVar13 != '\0') goto LAB_004a9fed;
      local_e8 = *(undefined8 *)(lVar6 + 0x16b8);
    }
  }
  else {
LAB_004a9fed:
    local_e8 = 0xffffffffffffffff;
  }
  uVar21 = uVar20 & 0xffffffff;
  lVar22 = uVar21 << 3;
  puVar23 = (ulong *)portMemAllocNonPaged(lVar22);
  if (puVar23 == (ulong *)0x0) {
    return 0x51;
  }
  memdescGetPtePhysAddrsForGpu(param_4,param_3,1,param_6,uVar33,uVar20,puVar23);
  if (param_10 != '\0') {
    local_70 = 0;
    local_78 = 0;
    iVar14 = (**(code **)(*(long *)(&DAT_00001b90 + *param_4) + 800))
                       (param_3,*param_4,*(long *)(&DAT_00001b90 + *param_4),&local_78,&local_70);
    if (iVar14 == 0) {
      if (local_78 == -1) {
        nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x105d,"nvGpuOpsBuildExternalAllocPtes",4,
                     "NVRM: DMA base address is not set for BAR1P2P mapping\n");
      }
      else {
        uVar29 = 0;
        if (local_70 != 0) {
          do {
            puVar23[uVar29] = puVar23[uVar29] + local_78;
            uVar29 = (ulong)((int)uVar29 + 1);
          } while (uVar29 < uVar20);
          goto LAB_004aa0e0;
        }
        nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x1064,"nvGpuOpsBuildExternalAllocPtes",4,
                     "NVRM: DMA size is not set for BAR1P2P mapping\n");
      }
      iVar14 = 0x40;
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar14,
                 "kbusGetBar1P2PDmaInfo_HAL(pMappingGpu, pRemoteGpu, GPU_GET_KERNEL_BUS(pRemoteGpu), &dmaBaseAddress, &dmaSize)"
                 ,"src/kernel/rmapi/nv_gpu_ops.c",0x1054);
    }
    local_118 = (ulong *)0x0;
    local_110 = (char *)0x0;
    goto LAB_004aa334;
  }
  kgmmuEncodePhysAddrs_IMPL(lVar34,uVar15,puVar23,local_e8,uVar20);
LAB_004aa0e0:
  if ((((*(char *)(param_3 + 0x4913) == '\0') || (*(char *)(param_3 + 0x491e) == '\0')) ||
      (cVar9 == '\0')) ||
     (cVar13 = (**(code **)(lVar2 + 0x2a8))(lVar2,10,_local_58 & 0xffffffff), cVar13 != '\0')) {
    local_118 = (ulong *)0x0;
    local_110 = (char *)0x0;
  }
  else {
    local_118 = (ulong *)portMemAllocNonPaged(lVar22);
    if (local_118 == (ulong *)0x0) {
      iVar14 = 0x51;
      local_110 = (char *)0x0;
      goto LAB_004aa334;
    }
    portMemSet(local_118,0,lVar22);
    puVar26 = local_118;
    uVar29 = param_6;
    do {
      *puVar26 = uVar29;
      puVar26 = puVar26 + 1;
      uVar29 = uVar29 + uVar33;
    } while (puVar26 != local_118 + uVar20);
    local_110 = (char *)portMemAllocNonPaged(uVar21);
    if (local_110 == (char *)0x0) {
      iVar14 = 0x51;
      goto LAB_004aa334;
    }
    portMemSet(local_110,0,uVar21);
  }
  lVar34 = 0;
  pcVar30 = local_110;
  puVar26 = puVar23;
  local_90 = param_6;
  do {
    uVar21 = *puVar26;
    puVar24 = (uint *)gmmuFmtPtePhysAddrFld(lVar4,uVar15,0);
    if (*puVar24 != 0) {
      uVar32 = uVar21 >> ((byte)puVar24[0xe] & 0x3f);
      uVar29 = 0;
      do {
        uVar31 = (int)uVar29 + 1;
        uVar5 = *(ulong *)((long)local_68 + (ulong)puVar24[uVar29 * 6 + 6]);
        *(ulong *)((long)local_68 + (ulong)puVar24[uVar29 * 6 + 6]) =
             (uVar32 << ((byte)puVar24[uVar29 * 6 + 5] & 0x3f) ^ uVar5) &
             *(ulong *)(puVar24 + uVar29 * 6 + 2) ^ uVar5;
        uVar32 = uVar32 >> ((byte)puVar24[uVar29 * 6 + 4] & 0x3f);
        uVar29 = (ulong)uVar31;
      } while (uVar31 < *puVar24);
    }
    if ((cVar9 != '\0') && (*puVar18 < 3)) {
      uVar8 = local_58;
      lVar22 = kmemsysGetStaticConfig_IMPL(param_3,lVar3);
      puVar24 = (uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x186));
      *puVar24 = *puVar24 & *(uint *)(lVar4 + 0x180);
      puVar24 = (uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x192));
      *puVar24 = *puVar24 & *(uint *)(lVar4 + 0x18c);
      if (*(int *)(lVar4 + 0x194) != 0) {
        puVar24 = (uint *)((long)local_68 + (ulong)*(ushort *)(lVar4 + 0x19e));
        *puVar24 = *puVar24 & *(uint *)(lVar4 + 0x198);
      }
      if (((*(char *)(lVar22 + 2) != '\0') && (*(char *)(lVar3 + 0x2a8) != '\0')) &&
         (cVar13 = (**(code **)(lVar2 + 0x2a8))(lVar2,10,_local_58 & 0xffffffff), cVar13 == '\0')) {
        if ((*(char *)(param_3 + 0x4913) == '\0') || (*(char *)(param_3 + 0x491e) == '\0')) {
          cVar13 = (**(code **)(lVar3 + 0x1e0))(param_3,lVar3,local_90,uVar33);
        }
        else {
          cVar13 = *pcVar30;
        }
        if (cVar13 == '\0') {
          (**(code **)(lVar2 + 0x378))(lVar2,local_d8);
          kgmmuFieldSetKindCompTags_IMPL
                    (*(undefined8 *)(param_3 + 0x1b98),puVar18,pbVar19,local_d8,uVar21,local_90,
                     (~(-1L << (pbVar19[1] + 1 & 0x3f)) & -1L << (*pbVar19 & 0x3f) & local_90) >>
                     (*pbVar19 & 0x3f),local_68);
          _local_58 = CONCAT44(uStack_54,uVar8);
          goto LAB_004aa204;
        }
      }
      kgmmuFieldSetKindCompTags_IMPL
                (*(undefined8 *)(param_3 + 0x1b98),puVar18,pbVar19,local_d8,uVar21,local_90,
                 (~(-1L << (pbVar19[1] + 1 & 0x3f)) & -1L << (*pbVar19 & 0x3f) & local_90) >>
                 (*pbVar19 & 0x3f),local_68);
    }
LAB_004aa204:
    puVar26 = puVar26 + 1;
    pcVar30 = pcVar30 + 1;
    portMemCopy(*(long *)(param_12 + 10) + lVar34,pbVar19[2],local_68,pbVar19[2]);
    lVar34 = lVar34 + (ulong)(bVar1 >> 3) * 8;
    local_90 = local_90 + uVar33;
  } while (pcVar30 != local_110 + uVar20);
  cVar9 = (**(code **)(lVar3 + 0x220))(param_3,lVar3,local_f9,uVar15);
  if (cVar9 != '\0') {
    (**(code **)(lVar3 + 0x188))(param_3,lVar3,0,(uVar15 == 2) * '\x02' + '\x01',3);
  }
  uVar12 = (**(code **)(lVar3 + 0x228))(param_3,lVar3,local_f9,uVar15);
  *(undefined1 *)(param_12 + 0x11) = uVar12;
  *(ulong *)(param_12 + 0xc) = uVar20;
  *(ulong *)(param_12 + 0xe) = uVar28 - uVar20;
  param_12[0x10] = (uint)pbVar19[2];
  iVar14 = 0;
LAB_004aa334:
  portMemFree(puVar23);
  portMemFree(local_118);
  portMemFree(local_110);
  return iVar14;
}


// ===== 004aaaf7 dupMemory.cold =====

void dupMemory_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004aab10 dupMemory =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int dupMemory(long *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             undefined4 *param_5,undefined4 *param_6)

{
  long *plVar1;
  long *plVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  code *pcVar5;
  char cVar6;
  undefined1 uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  long *plVar14;
  long lVar15;
  long lVar16;
  undefined8 uVar17;
  undefined4 local_84;
  long local_80;
  long *local_78;
  undefined8 local_70;
  long local_68;
  undefined1 local_60 [8];
  ulong local_58;
  undefined1 local_50 [32];
  
  local_80 = 0;
  local_78 = (long *)0x0;
  lVar11 = rmapiGetInterface(4);
  if ((param_1 == (long *)0x0) || (param_5 == (undefined4 *)0x0)) {
    return 0x1f;
  }
  lVar12 = threadStateAlloc(0);
  if (lVar12 == 0) {
    return 0x51;
  }
  iVar8 = _nvGpuOpsLocksAcquireWithClientLockFlags(0,1,*(undefined4 *)param_1[9],&local_70,3,0,0);
  if (iVar8 != 0) goto LAB_004aafc8;
  iVar8 = subdeviceGetByHandle_IMPL(local_70,*(undefined4 *)((long)param_1 + 0x14),&local_68);
  if (iVar8 == 0) {
    lVar16 = *(long *)(*(long *)(local_68 + 0x158) + 0xe0);
    local_58 = 0;
    iVar8 = serverGetClientUnderLock(g_resServ,param_2,&local_58);
    if (iVar8 == 0) {
      iVar8 = memGetByHandle_IMPL(local_58,param_3,&local_80);
      if (iVar8 == 0) {
        plVar2 = *(long **)(local_80 + 0x118);
        if (1 < *(uint *)((long)plVar2 + 0x8c)) {
          nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                              "src/kernel/rmapi/nv_gpu_ops.c",0x2046);
        }
        local_78 = plVar2;
        lVar13 = __nvoc_dynamicCast(*(undefined8 *)(lVar16 + 0x4a18),__nvoc_class_def_FABRIC_VASPACE
                                   );
        if ((lVar13 == 0) ||
           (iVar8 = fabricvaspaceGetGpaMemdesc_IMPL(lVar13,plVar2,lVar16,&local_78), iVar8 == 0)) {
          iVar8 = memdescGetAddressSpace(local_78);
          if ((iVar8 == 2) ||
             (((iVar8 = memdescGetAddressSpace(local_78), iVar8 == 1 ||
               (iVar8 = memdescGetAddressSpace(local_78), iVar8 == 7)) ||
              (iVar8 = memdescGetAddressSpace(local_78), iVar8 == 6)))) {
            if (((*local_78 == 0) || (cVar6 = gpumgrCheckIndirectPeer_IMPL(lVar16), cVar6 == '\0'))
               && ((plVar1 = local_78, iVar8 = memdescGetAddressSpace(local_78), iVar8 != 1 ||
                   ((cVar6 = memdescGetFlag(plVar1,0x8000000000), cVar6 != '\0' ||
                    (cVar6 = memdescIsEgm(plVar1), cVar6 != '\0')))))) {
LAB_004aad24:
              puVar3 = (undefined4 *)param_1[9];
              if (param_6 == (undefined4 *)0x0) goto LAB_004aae60;
              iVar8 = serverGetClientUnderLock(g_resServ,*puVar3,local_60);
              plVar1 = local_78;
              if (iVar8 == 0) {
                uVar4 = *(undefined8 *)(*(long *)(local_68 + 0x158) + 0xe8);
                plVar14 = (long *)memdescGetRootMemDesc(local_78,0);
                lVar15 = *plVar1;
                if (*plVar1 == 0) {
                  lVar15 = lVar16;
                }
                iVar8 = nvGpuOpsMemGetPageSize(lVar16,plVar1,param_6 + 2);
                if (iVar8 == 0) {
                  *(long *)(param_6 + 8) = plVar1[6];
                  uVar7 = memdescGetContiguity(plVar1,1);
                  *(undefined1 *)(param_6 + 4) = uVar7;
                  uVar7 = memdescIsEgm(plVar1);
                  *(undefined1 *)((long)param_6 + 5) = uVar7;
                  if (*(char *)(param_6 + 4) != '\0') {
                    uVar9 = nvGpuOpsGetExternalAllocAperture(0,plVar1,0,0,0,0);
                    memdescGetPtePhysAddrsForGpu(plVar1,lVar16,1,0,0,1,&local_58);
                    uVar17 = kgmmuEncodePhysAddr_IMPL
                                       (*(undefined8 *)(lVar15 + 0x1b98),uVar9,local_58,
                                        0xffffffffffffffff);
                    *(undefined8 *)(param_6 + 6) = uVar17;
                  }
                  uVar9 = memdescGetPteKindForGpu(plVar1,lVar16);
                  *param_6 = uVar9;
                  iVar8 = memdescGetAddressSpace(plVar1);
                  *(bool *)(param_6 + 1) = iVar8 == 1;
                  lVar16 = *plVar14;
                  *(bool *)((long)param_6 + 6) = lVar16 != 0;
                  if ((lVar16 != 0) && (iVar8 = fillMIGGiUUID(param_6,uVar4), iVar8 != 0)) {
                    iVar8 = gpuGetGidInfo_IMPL(lVar15,&local_58,&local_84,2);
                    if (iVar8 != 0) goto LAB_004aafa4;
                    portMemCopy(param_6 + 10,local_84,local_58,local_84);
                    portMemFree(local_58);
                  }
LAB_004aae60:
                  if (local_80 == 0) {
                    /* WARNING: Does not return */
                    pcVar5 = (code *)invalidInstructionException();
                    (*pcVar5)();
                  }
                  lVar16 = *(long *)(*(long *)(*(long *)(local_80 + 0xb8) + 0x48) + 0x18);
                  lVar15 = __nvoc_dynamicCast(*(undefined8 *)(lVar16 + 8),__nvoc_class_def_Subdevice
                                             );
                  if (lVar15 == 0) {
                    lVar15 = __nvoc_dynamicCast(*(undefined8 *)(lVar16 + 8),
                                                __nvoc_class_def_RsClientResource);
                    if (lVar15 == 0) {
                      lVar16 = __nvoc_dynamicCast(*(undefined8 *)(lVar16 + 8),
                                                  __nvoc_class_def_Device);
                      if (lVar16 == 0) {
                        nvAssertFailedNoLog("dynamicCast(pParentRef->pResource, Device)",
                                            "src/kernel/rmapi/nv_gpu_ops.c",0x2099);
                      }
                      uVar9 = (undefined4)param_1[2];
                    }
                    else {
                      iVar8 = memdescGetAddressSpace(local_78);
                      if ((iVar8 != 7) && (iVar8 = memdescGetAddressSpace(local_78), iVar8 != 6)) {
                        nvAssertFailedNoLog("bAssert","src/kernel/rmapi/nv_gpu_ops.c",0x2093);
                      }
                      uVar9 = *puVar3;
                    }
                  }
                  else {
                    uVar9 = *(undefined4 *)((long)param_1 + 0x14);
                  }
                  local_58 = local_58 & 0xffffffff00000000;
                  iVar8 = (**(code **)(lVar11 + 0x50))
                                    (lVar11,*puVar3,uVar9,&local_58,param_2,param_3,param_4);
                  if (iVar8 == 0) {
                    iVar10 = memdescGetAddressSpace(plVar2);
                    lVar16 = param_1[1];
                    cVar6 = rmapiLockIsWriteOwner();
                    if ((cVar6 == '\0') || (cVar6 = rmGpuLockIsOwner(), cVar6 == '\0')) {
                      iVar8 = 0x2f;
                      nvAssertFailedNoLog("rmapiLockIsWriteOwner() && rmGpuLockIsOwner()",
                                          "src/kernel/rmapi/nv_gpu_ops.c",0x1fe7);
LAB_004aaf7e:
                      (**(code **)(lVar11 + 0x18))(lVar11,*puVar3,local_58 & 0xffffffff);
                    }
                    else {
                      lVar15 = *param_1;
                      if (lVar15 == 0) {
                        nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x777
                                           );
                        lVar15 = *param_1;
                      }
                      if ((((0x17f < *(uint *)(lVar15 + 0x54)) && (*(uint *)(lVar15 + 0x54) != 400))
                          && ((char)param_1[0x29] != '\0')) && (iVar10 - 6U < 2)) {
                        plVar1 = (long *)(lVar16 + 0xd0);
                        LOCK();
                        lVar15 = *plVar1;
                        *plVar1 = *plVar1 + 1;
                        UNLOCK();
                        if ((lVar15 + 1U < 2) &&
                           (iVar10 = _nvGpuOpsP2pObjectCreate(param_1,param_1,lVar16 + 200,4),
                           iVar10 != 0)) {
                          LOCK();
                          *plVar1 = 0;
                          UNLOCK();
                          iVar8 = iVar10;
                          goto LAB_004aaf7e;
                        }
                      }
                      *param_5 = (undefined4)local_58;
                    }
                  }
                }
              }
            }
            else if (*local_78 == 0) {
              iVar8 = 0x40;
            }
            else {
              iVar8 = memdescMapIommu(local_78,*(undefined4 *)(lVar16 + 0x868));
              if (iVar8 == 0) goto LAB_004aad24;
            }
          }
          else {
            iVar8 = 0x56;
          }
LAB_004aafa4:
          if (plVar2 != local_78) {
            fabricvaspacePutGpaMemdesc_IMPL(lVar13,local_78);
          }
        }
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar8,"serverGetClientUnderLock(&g_resServ, hClient, &pRsClient)",
                 "src/kernel/rmapi/nv_gpu_ops.c",0x2d96);
    }
  }
  _nvGpuOpsLocksRelease(local_50);
LAB_004aafc8:
  threadStateFree(lVar12,0);
  return iVar8;
}


// ===== 004ab2e0 nvGpuOpsGetP2PCaps =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsGetP2PCaps(long param_1,long param_2,undefined8 *param_3)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  long lVar7;
  long lVar8;
  uint uVar9;
  undefined8 uVar10;
  uint local_70;
  uint local_6c;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  byte local_48;
  undefined4 local_44;
  undefined4 local_40;
  
  if ((((param_1 == 0) || (param_2 == 0)) ||
      (*(undefined4 **)(param_2 + 0x48) != *(undefined4 **)(param_1 + 0x48))) ||
     (param_3 == (undefined8 *)0x0)) {
    return 0x1f;
  }
  iVar2 = allocNvlinkStatus(**(undefined4 **)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x14),
                            &local_68);
  uVar10 = 0;
  if (iVar2 != 0) goto LAB_004ab346;
  iVar2 = allocNvlinkStatus(**(undefined4 **)(param_2 + 0x48),*(undefined4 *)(param_2 + 0x14),
                            &local_60);
  uVar10 = local_60;
  if (iVar2 != 0) goto LAB_004ab346;
  portMemSet(param_3,0,0x48);
  *param_3 = 0xffffffffffffffff;
  param_3[1] = 0xffffffffffffffff;
  param_3[4] = 0xffffffffffffffff;
  param_3[5] = 0xffffffffffffffff;
  param_3[6] = 0;
  param_3[7] = 0;
  *(undefined2 *)(param_3 + 8) = 0;
  *(undefined4 *)(param_3 + 2) = 0;
  iVar2 = getSystemP2PCaps(param_1,param_2,&local_58,1);
  if ((iVar2 != 0) || ((local_48 & 1) == 0)) goto LAB_004ab346;
  *param_3 = local_58;
  param_3[1] = local_50;
  if ((local_48 & 2) == 0) {
    iVar2 = getPCIELinkRateMBps(**(undefined4 **)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x14),
                                &local_70);
    if (iVar2 == 0) {
      iVar5 = getPCIELinkRateMBps(**(undefined4 **)(param_2 + 0x48),*(undefined4 *)(param_2 + 0x14),
                                  &local_6c);
      iVar2 = iVar5;
      if (iVar5 == 0) {
        uVar6 = 1;
        if ((local_48 & 8) != 0) {
          lVar7 = gpumgrGetGpuFromId(*(undefined4 *)(param_1 + 0x20));
          lVar8 = gpumgrGetGpuFromId(*(undefined4 *)(param_2 + 0x20));
          iVar2 = (**(code **)(*(long *)(&DAT_00001b90 + lVar8) + 800))
                            (lVar7,lVar8,*(long *)(&DAT_00001b90 + lVar8),param_3 + 4,param_3 + 6);
          if (iVar2 != 0) {
            nvCheckOkFailedNoLog
                      (4,iVar2,
                       "kbusGetBar1P2PDmaInfo_HAL(pLocalGpu, pRemoteGpu, GPU_GET_KERNEL_BUS(pRemoteGpu), &p2pCapsParams->bar1DmaAddress[0], &p2pCapsParams->bar1DmaSize[0])"
                       ,"src/kernel/rmapi/nv_gpu_ops.c",0xcbc);
            goto LAB_004ab346;
          }
          uVar1 = _nvGpuOpsIsBar1P2pAtomicEnabled(*(undefined8 *)(param_1 + 0x48),lVar7,lVar8);
          *(undefined1 *)(param_3 + 8) = uVar1;
          iVar2 = (**(code **)(*(long *)(&DAT_00001b90 + lVar7) + 800))
                            (lVar8,lVar7,*(long *)(&DAT_00001b90 + lVar7),param_3 + 5,param_3 + 7);
          if (iVar2 != 0) {
            nvCheckOkFailedNoLog
                      (4,iVar2,
                       "kbusGetBar1P2PDmaInfo_HAL(pRemoteGpu, pLocalGpu, GPU_GET_KERNEL_BUS(pLocalGpu), &p2pCapsParams->bar1DmaAddress[1], &p2pCapsParams->bar1DmaSize[1])"
                       ,"src/kernel/rmapi/nv_gpu_ops.c",0xcc8);
            goto LAB_004ab346;
          }
          uVar1 = _nvGpuOpsIsBar1P2pAtomicEnabled(*(undefined8 *)(param_2 + 0x48),lVar8,lVar7);
          *(undefined1 *)((long)param_3 + 0x41) = uVar1;
          uVar6 = 2;
        }
        *(undefined4 *)(param_3 + 2) = uVar6;
        if (local_70 < local_6c) {
          local_6c = local_70;
        }
        *(uint *)((long)param_3 + 0x1c) = local_6c;
        iVar2 = iVar5;
      }
    }
    goto LAB_004ab346;
  }
  if ((local_48 & 4) == 0) {
    nvAssertFailedNoLog("p2pCaps.atomicSupported","src/kernel/rmapi/nv_gpu_ops.c",0xc92);
  }
  if ((*(char *)(param_1 + 0x148) == '\0') || (*(char *)(param_2 + 0x148) == '\0')) {
    lVar7 = gpumgrGetGpuFromId(*(undefined4 *)(param_1 + 0x20));
    if (lVar7 != 0) {
      lVar8 = gpumgrGetGpuFromId(*(undefined4 *)(param_2 + 0x20));
      if (lVar8 != 0) {
        uVar3 = getNvlinkConnectionToGpu(local_68,lVar8,&local_70);
        uVar4 = getNvlinkConnectionToGpu(local_60,lVar7,&local_6c);
        goto LAB_004ab4a4;
      }
    }
    iVar2 = 0x57;
    goto LAB_004ab346;
  }
  uVar3 = getNvlinkConnectionToSwitch(local_68,&local_70);
  uVar4 = getNvlinkConnectionToSwitch(local_60,&local_6c);
LAB_004ab4a4:
  if ((uVar3 == 0xff) || (uVar4 == 0xff)) {
    iVar5 = rmControlToUvmNvlinkVersion(0xff);
    param_3[2] = CONCAT44(local_44,iVar5);
    *(undefined4 *)(param_3 + 3) = local_40;
    if (iVar5 == 0) {
      nvAssertFailedNoLog("p2pCapsParams->p2pLink != UVM_LINK_TYPE_NONE",
                          "src/kernel/rmapi/nv_gpu_ops.c",0xca1);
    }
LAB_004ab651:
    nvAssertFailedNoLog("linkBandwidthMBps != 0","src/kernel/rmapi/nv_gpu_ops.c",0xca2);
    uVar9 = 0;
  }
  else {
    if ((((uVar3 == 1) || (uVar4 == 1)) || (uVar3 - 7 < 2)) || (uVar4 - 7 < 2)) {
      if (uVar3 != uVar4) {
        nvAssertFailedNoLog("nvlinkVersion1 == nvlinkVersion2","src/kernel/rmapi/nv_gpu_ops.c",0xc40
                           );
      }
      if (local_70 != local_6c) {
        nvAssertFailedNoLog("linkBandwidthMBps1 == linkBandwidthMBps2",
                            "src/kernel/rmapi/nv_gpu_ops.c",0xc41);
      }
    }
    uVar9 = local_70;
    if (local_6c < local_70) {
      uVar9 = local_6c;
    }
    if (uVar3 <= uVar4) {
      uVar4 = uVar3;
    }
    iVar5 = rmControlToUvmNvlinkVersion(uVar4);
    param_3[2] = CONCAT44(local_44,iVar5);
    *(undefined4 *)(param_3 + 3) = local_40;
    if (iVar5 == 0) {
      nvAssertFailedNoLog("p2pCapsParams->p2pLink != UVM_LINK_TYPE_NONE",
                          "src/kernel/rmapi/nv_gpu_ops.c",0xca1);
    }
    if (uVar9 == 0) goto LAB_004ab651;
  }
  *(uint *)((long)param_3 + 0x1c) = uVar9;
LAB_004ab346:
  portMemFree(local_68);
  portMemFree(uVar10);
  return iVar2;
}


// ===== 004ab860 nvGpuOpsGetExternalAllocPtesOrPhysAddrs =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsGetExternalAllocPtesOrPhysAddrs
              (undefined4 *param_1,undefined4 param_2,ulong param_3,ulong param_4,long param_5,
              int *param_6)

{
  long *plVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  long *plVar6;
  undefined8 uVar7;
  undefined4 *puVar8;
  long lVar9;
  long lVar10;
  undefined1 uVar11;
  char cVar12;
  char cVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  long lVar17;
  ulong uVar18;
  long lVar19;
  ulong uVar20;
  long lVar21;
  undefined4 *puVar22;
  undefined8 *puVar23;
  long lVar24;
  bool bVar25;
  undefined8 uVar26;
  undefined1 *puVar27;
  char local_190;
  byte local_161;
  undefined8 local_148;
  ulong local_138;
  long *local_120;
  long local_118;
  undefined8 local_110;
  undefined8 local_108;
  long *local_100;
  ulong local_f8;
  long *local_f0;
  long *local_e8;
  undefined1 local_e0 [24];
  undefined1 local_c8 [152];
  
  cVar12 = *(char *)(g_pSys + 0x83);
  local_120 = (long *)0x0;
  local_118 = 0;
  local_110 = 0;
  local_100 = (long *)0x0;
  threadStateInit(local_c8,0);
  uVar26 = 0;
  puVar27 = local_e0;
  iVar14 = _nvGpuOpsLocksAcquireWithClientLockFlags
                     (10,cVar12 == '\0',**(undefined4 **)(*(long *)(param_1 + 2) + 0x48),&local_108,
                      3,0);
  if (iVar14 != 0) {
    threadStateFree(local_c8,0,uVar26,puVar27);
    return iVar14;
  }
  iVar14 = vaspaceGetByHandleOrDeviceDefault_IMPL
                     (local_108,*(undefined4 *)(*(long *)(param_1 + 2) + 0x10),*param_1,&local_110);
  if (iVar14 != 0) goto LAB_004ab948;
  local_e8 = (long *)0x0;
  iVar14 = serverGetClientUnderLock
                     (g_resServ,**(undefined4 **)(*(long *)(param_1 + 2) + 0x48),&local_e8);
  if (iVar14 != 0) {
    nvAssertOkFailedNoLog
              (iVar14,"serverGetClientUnderLock(&g_resServ, hClient, &pRsClient)",
               "src/kernel/rmapi/nv_gpu_ops.c",0x2d96);
    goto LAB_004ab948;
  }
  iVar14 = memGetByHandle_IMPL(local_e8,param_2,&local_120);
  if (iVar14 != 0) goto LAB_004ab948;
  plVar6 = (long *)local_120[0x23];
  if (1 < *(uint *)((long)plVar6 + 0x8c)) {
    nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/rmapi/nv_gpu_ops.c",
                        0x1207);
  }
  iVar14 = memdescGetAddressSpace(plVar6);
  if (((iVar14 != 1) && (iVar14 = memdescGetAddressSpace(plVar6), iVar14 != 2)) &&
     (iVar14 = memdescGetAddressSpace(plVar6), iVar14 != 7)) {
    iVar14 = 0x56;
    iVar15 = memdescGetAddressSpace(plVar6);
    if (iVar15 != 6) goto LAB_004ab948;
  }
  iVar15 = CliSetGpuContext(**(undefined4 **)(*(long *)(param_1 + 2) + 0x48),
                            *(undefined4 *)(*(long *)(param_1 + 2) + 0x10),&local_118,0);
  iVar14 = iVar15;
  if ((iVar15 != 0) ||
     ((local_100 = plVar6,
      lVar17 = __nvoc_dynamicCast(*(undefined8 *)(local_118 + 0x4a18),
                                  __nvoc_class_def_FABRIC_VASPACE), lVar17 != 0 &&
      (iVar14 = fabricvaspaceGetGpaMemdesc_IMPL(lVar17,plVar6,local_118,&local_100), iVar14 != 0))))
  goto LAB_004ab948;
  iVar14 = memdescGetAddressSpace(local_100);
  if ((iVar14 == 7) || (iVar14 = memdescGetAddressSpace(local_100), iVar14 == 6)) {
    lVar24 = *local_100;
    cVar12 = (**(code **)(*local_120 + 0x200))(local_120,local_118);
    if (cVar12 == '\0') {
      nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x122e,"nvGpuOpsGetExternalAllocPtesOrPhysAddrs",
                   4,"NVRM: Mapping Gpu is not attached to the given memory object\n");
    }
    else {
      if (lVar24 == 0) {
        iVar16 = (**(code **)(*(long *)(&DAT_00001b90 + local_118) + 0x298))
                           (local_118,*(long *)(&DAT_00001b90 + local_118),0);
      }
      else if ((*(char *)(local_118 + 0x4913) == '\0') || (*(char *)(local_118 + 0x491e) != '\0')) {
        if ((*(long *)(local_118 + 0x1ce8) == 0) ||
           (cVar12 = knvlinkIsNvlinkP2pSupported_IMPL
                               (local_118,*(long *)(local_118 + 0x1ce8),lVar24), cVar12 == '\0'))
        goto LAB_004ac034;
        iVar16 = (**(code **)(*(long *)(&DAT_00001b90 + local_118) + 0x288))
                           (local_118,*(long *)(&DAT_00001b90 + local_118),lVar24);
      }
      else {
        iVar16 = (**(code **)(*(long *)(&DAT_00001b90 + local_118) + 0x290))();
      }
      if (iVar16 != -1) {
        local_161 = 0;
        cVar12 = '\x01';
        uVar11 = 0;
        goto LAB_004abb31;
      }
    }
LAB_004ac034:
    iVar14 = 0x40;
    goto LAB_004abee0;
  }
  iVar14 = memdescGetAddressSpace(local_100);
  if ((iVar14 == 2) && (*(int *)(*local_100 + 0x7ac) != *(int *)(local_118 + 0x7ac))) {
    cVar12 = gpumgrCheckIndirectPeer_IMPL(*local_100);
    lVar24 = local_118;
    if (cVar12 != '\0') {
      local_161 = 0;
      iVar16 = 0;
      cVar12 = '\0';
      uVar11 = 1;
      goto LAB_004abb31;
    }
    lVar19 = *local_100;
    puVar8 = *(undefined4 **)(*(long *)(param_1 + 2) + 0x48);
    local_f0 = (long *)0x0;
    lVar21 = rmapiGetInterface(4);
    if (*(int *)(lVar24 + 0x7ac) == *(int *)(lVar19 + 0x7ac)) {
      nvAssertFailedNoLog("pGpu->gpuId != pMemOwnerGpu->gpuId","src/kernel/rmapi/nv_gpu_ops.c",0xd8f
                         );
    }
    portSyncRwLockAcquireRead(*(undefined8 *)(puVar8 + 8));
    iVar14 = btreeSearch(*(undefined4 *)(lVar19 + 0x7ac),&local_f0,*(undefined8 *)(puVar8 + 6));
    if (iVar14 == 0) {
      lVar9 = *local_f0;
      portSyncRwLockAcquireRead(*(undefined8 *)(lVar9 + 0x40));
      iVar14 = btreeSearch(*(undefined4 *)(lVar24 + 0x7ac),&local_f0,*(undefined8 *)(lVar9 + 0x38));
      if (iVar14 != 0) {
        portSyncRwLockReleaseRead(*(undefined8 *)(lVar9 + 0x40));
        portSyncRwLockReleaseRead(*(undefined8 *)(puVar8 + 8));
        goto LAB_004ac2e0;
      }
      lVar10 = *local_f0;
      cVar12 = *(char *)(lVar10 + 0x38);
      iVar16 = *(int *)(lVar10 + 0x3c);
      local_161 = *(byte *)(lVar10 + 0x41);
      portSyncRwLockReleaseRead(*(undefined8 *)(lVar9 + 0x40));
      portSyncRwLockReleaseRead(*(undefined8 *)(puVar8 + 8));
      lVar9 = *(long *)(lVar24 + 0x1ce8);
      cVar2 = *(char *)(lVar10 + 0x40);
      if (*(long *)(lVar19 + 0x1ce8) != 0) {
        local_190 = knvlinkGetDegradedMode_IMPL(lVar19);
        if (cVar2 == local_190) {
          if (lVar9 != 0) goto LAB_004ac97f;
          goto LAB_004ac550;
        }
        nvGpuOpsFindAndDestroyP2pInfo(puVar8,*(undefined4 *)(lVar19 + 0x7ac));
        cVar13 = '\0';
        if ((lVar9 != 0) && (cVar13 = knvlinkGetDegradedMode_IMPL(lVar24,lVar9), cVar2 != cVar13))
        goto LAB_004ac942;
        goto LAB_004ac2ea;
      }
      if (lVar9 != 0) {
        local_190 = '\0';
LAB_004ac97f:
        cVar13 = knvlinkGetDegradedMode_IMPL(lVar24,lVar9);
        if (cVar2 != cVar13) {
LAB_004ac942:
          nvGpuOpsFindAndDestroyP2pInfo(puVar8,*(undefined4 *)(lVar24 + 0x7ac));
          goto LAB_004ac2ea;
        }
      }
LAB_004ac550:
      uVar11 = 0;
      if (*(int *)(*local_100 + 0x7b4) == *(int *)(local_118 + 0x7b4)) {
        cVar12 = '\0';
      }
      else if (cVar12 == '\0') {
        iVar14 = 0x56;
        goto LAB_004abee0;
      }
      goto LAB_004abb31;
    }
    portSyncRwLockReleaseRead(*(undefined8 *)(puVar8 + 8));
LAB_004ac2e0:
    local_190 = '\0';
    cVar13 = '\0';
LAB_004ac2ea:
    puVar22 = (undefined4 *)portMemAllocNonPaged(0x209c);
    if (puVar22 != (undefined4 *)0x0) {
      portMemSet(puVar22,0,0x209c);
      *puVar22 = *(undefined4 *)(lVar24 + 0x7ac);
      uVar3 = *(undefined4 *)(lVar19 + 0x7ac);
      puVar22[0x20] = 2;
      puVar22[1] = uVar3;
      iVar14 = (**(code **)(lVar21 + 0x38))(lVar21,*puVar8,*puVar8,299,puVar22,0x209c);
      if (iVar14 == 0) {
        iVar16 = puVar22[0x28];
        cVar12 = (~(byte)puVar22[0x21] & 3) == 0;
        local_161 = (byte)((uint)puVar22[0x21] >> 0xd) & 1;
        uVar4 = *(uint *)(lVar19 + 0x7ac);
        bVar25 = local_190 != '\0' || cVar13 != '\0';
        uVar5 = *(uint *)(lVar24 + 0x7ac);
        local_e8 = (long *)0x0;
        if (uVar5 == uVar4) {
          nvAssertFailedNoLog("memOwnerGpuId != peerGpuId","src/kernel/rmapi/nv_gpu_ops.c",0xd3a);
        }
        portSyncRwLockAcquireWrite(*(undefined8 *)(puVar8 + 8));
        uVar18 = (ulong)uVar4;
        iVar14 = btreeSearch(uVar18,&local_e8,*(undefined8 *)(puVar8 + 6));
        if (iVar14 == 0) {
          lVar24 = *local_e8;
          portSyncRwLockAcquireWrite(*(undefined8 *)(lVar24 + 0x40));
          iVar14 = btreeSearch(uVar5,&local_e8,*(undefined8 *)(lVar24 + 0x38));
          if (iVar14 == 0) {
            lVar19 = *local_e8;
            *(char *)(lVar19 + 0x38) = cVar12;
            *(int *)(lVar19 + 0x3c) = iVar16;
            *(byte *)(lVar19 + 0x41) = local_161;
            *(bool *)(lVar19 + 0x40) = bVar25;
            portSyncRwLockReleaseWrite(*(undefined8 *)(lVar24 + 0x40));
            portSyncRwLockReleaseWrite(*(undefined8 *)(puVar8 + 8));
            portMemFree(puVar22);
            goto LAB_004ac550;
          }
LAB_004ac48d:
          lVar19 = portMemAllocNonPaged(0x48);
          if (lVar19 != 0) {
            *(int *)(lVar19 + 0x3c) = iVar16;
            *(long *)lVar19 = lVar19;
            *(char *)(lVar19 + 0x38) = cVar12;
            *(ulong *)(lVar19 + 8) = (ulong)uVar5;
            *(byte *)(lVar19 + 0x41) = local_161;
            *(ulong *)(lVar19 + 0x10) = (ulong)uVar5;
            *(bool *)(lVar19 + 0x40) = bVar25;
            iVar14 = btreeInsert(lVar19,lVar24 + 0x38);
            portSyncRwLockReleaseWrite(*(undefined8 *)(lVar24 + 0x40));
            portSyncRwLockReleaseWrite(*(undefined8 *)(puVar8 + 8));
            portMemFree(puVar22);
            if (iVar14 == 0) goto LAB_004ac550;
            goto LAB_004abee0;
          }
          portSyncRwLockReleaseWrite(*(undefined8 *)(lVar24 + 0x40));
        }
        else {
          lVar24 = portMemAllocNonPaged(0x48);
          if (lVar24 != 0) {
            *(undefined8 *)(lVar24 + 0x38) = 0;
            uVar26 = portMemAllocatorGetGlobalNonPaged();
            uVar26 = portSyncRwLockCreate(uVar26);
            *(undefined8 *)(lVar24 + 0x40) = uVar26;
            portSyncRwLockAcquireWrite(uVar26);
            *(long *)lVar24 = lVar24;
            *(ulong *)(lVar24 + 8) = uVar18;
            *(ulong *)(lVar24 + 0x10) = uVar18;
            iVar14 = btreeInsert(lVar24,puVar8 + 6);
            if (iVar14 != 0) {
              portSyncRwLockReleaseWrite(*(undefined8 *)(lVar24 + 0x40));
              if (*(long *)(lVar24 + 0x38) != 0) {
                portSyncRwLockAcquireWrite(*(undefined8 *)(lVar24 + 0x40));
                btreeDestroyData(*(undefined8 *)(lVar24 + 0x38));
                portSyncRwLockReleaseWrite(*(undefined8 *)(lVar24 + 0x40));
              }
              portSyncRwLockDestroy(*(undefined8 *)(lVar24 + 0x40));
              portMemFree(lVar24);
              portSyncRwLockReleaseWrite(*(undefined8 *)(puVar8 + 8));
              portMemFree(puVar22);
              goto LAB_004abee0;
            }
            goto LAB_004ac48d;
          }
          nvAssertOkFailedNoLog
                    (0x51,"nvGpuOpsP2pInfoCreate(&p2pInfo)","src/kernel/rmapi/nv_gpu_ops.c",0xd54);
        }
        portSyncRwLockReleaseWrite(*(undefined8 *)(puVar8 + 8));
        portMemFree(puVar22);
        goto LAB_004ac60e;
      }
      portMemFree(puVar22);
      goto LAB_004abee0;
    }
    portMemFree(0);
LAB_004ac60e:
    iVar14 = 0x51;
  }
  else {
    cVar12 = memdescIsEgm();
    if (cVar12 == '\0') {
      local_161 = 0;
      iVar16 = 0;
      cVar12 = '\0';
      uVar11 = 0;
    }
    else if (*(int *)(*local_100 + 0x7ac) == *(int *)(local_118 + 0x7ac)) {
      iVar16 = *(int *)(*(long *)(local_118 + 0x1b78) + 0x458);
      nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x12a8,"nvGpuOpsGetExternalAllocPtesOrPhysAddrs",
                   1,"NVRM: UVM GPU%d->CPU: Local EGM peer Id: %d\n",
                   *(undefined4 *)(local_118 + 0x7a4),iVar16);
      if (iVar16 == -1) {
        nvAssertOkFailedNoLog
                  (0x40,"peerId != BUS_INVALID_PEER","src/kernel/rmapi/nv_gpu_ops.c",0x12aa);
        goto LAB_004ac034;
      }
      local_161 = 0;
      cVar12 = '\0';
      uVar11 = 0;
    }
    else {
      iVar16 = (**(code **)(*(long *)(&DAT_00001b90 + local_118) + 0x280))();
      if (iVar16 == -1) {
        iVar14 = 0x1f;
        nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x129a,
                     "nvGpuOpsGetExternalAllocPtesOrPhysAddrs",4,
                     "NVRM: UVM GPU%d->GPU%d: remote EGM peer id not found\n",
                     *(undefined4 *)(local_118 + 0x7a4),*(undefined4 *)(*local_100 + 0x7a4));
        goto LAB_004abee0;
      }
      nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x12a0,"nvGpuOpsGetExternalAllocPtesOrPhysAddrs",
                   1,"NVRM: UVM GPU%d->GPU%d: peer Id: %d\n",*(undefined4 *)(local_118 + 0x7a4),
                   *(undefined4 *)(*local_100 + 0x7a4),iVar16);
      local_161 = 0;
      cVar12 = '\0';
      uVar11 = 0;
    }
LAB_004abb31:
    iVar14 = iVar15;
    if (param_5 != 0) {
      iVar14 = nvGpuOpsBuildExternalAllocPtes
                         (local_110,*(undefined8 *)(*(long *)(param_1 + 2) + 0x48),local_118,
                          local_100,local_120,param_3,param_4,uVar11,cVar12,local_161,iVar16,param_5
                         );
    }
    plVar1 = local_100;
    lVar24 = local_118;
    if (param_6 != (int *)0x0) {
      uVar26 = *(undefined8 *)(*(long *)(param_1 + 2) + 0x48);
      uVar7 = *(undefined8 *)(local_118 + 0x1b98);
      uVar18 = *(ulong *)(param_6 + 4);
      if (1 < *(uint *)((long)local_100 + 0x8c)) {
        nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/rmapi/nv_gpu_ops.c"
                            ,0x110c);
      }
      iVar14 = nvGpuOpsMemGetPageSize(lVar24,plVar1,&local_f8);
      if (iVar14 == 0) {
        local_138 = local_f8;
        if ((uVar18 == 0) || ((uVar18 <= local_f8 && (local_138 = uVar18, local_f8 % uVar18 == 0))))
        {
          uVar18 = (local_f8 - 1) + plVar1[7] & -local_f8;
          if (param_3 < uVar18) {
            if (uVar18 < param_3 + param_4) {
              iVar14 = 0x2e;
            }
            else {
              if ((local_138 - 1 & (param_3 | param_4)) != 0) goto LAB_004ac1c0;
              iVar16 = nvGpuOpsGetExternalAllocAperture(uVar26,plVar1,uVar11,cVar12,local_161,0);
              iVar15 = *param_6;
              cVar12 = memdescGetFlag(plVar1,0x200000000);
              if (((cVar12 == '\0') || (iVar15 == 0)) || (iVar15 == 3)) {
                if (param_4 == 0) {
                  param_4 = uVar18;
                }
                param_4 = param_4 / local_138;
                uVar18 = *(ulong *)(param_6 + 2);
                if (param_4 <= *(ulong *)(param_6 + 2)) {
                  uVar18 = param_4;
                }
                if (uVar18 == 0) {
                  iVar14 = 2;
                }
                else {
                  if (((iVar16 == 2) && (iVar15 = memdescGetAddressSpace(plVar1), iVar15 != 7)) &&
                     (iVar15 = memdescGetAddressSpace(plVar1), iVar15 != 6)) {
                    cVar12 = memdescIsEgm(plVar1);
                    lVar19 = *plVar1;
                    if (((cVar12 != '\0') && (lVar24 == lVar19)) ||
                       (lVar21 = *(long *)(lVar19 + 0x1ce8), lVar21 == 0)) goto LAB_004abd57;
                    if ((*(char *)(lVar19 + 0x4cc) == '\x01') ||
                       (*(char *)(lVar19 + 0x4915) == '\0')) {
                      cVar12 = memdescIsEgm(plVar1);
                      puVar23 = (undefined8 *)(lVar21 + 0x16a8);
                      if (cVar12 != '\0') {
                        puVar23 = (undefined8 *)(lVar21 + 0x16b0);
                      }
                      local_148 = *puVar23;
                    }
                    else {
                      cVar12 = memdescIsEgm(plVar1);
                      if (cVar12 != '\0') goto LAB_004abd57;
                      local_148 = *(undefined8 *)(lVar21 + 0x16b8);
                    }
                  }
                  else {
LAB_004abd57:
                    local_148 = 0xffffffffffffffff;
                  }
                  lVar19 = portMemAllocNonPaged((uVar18 & 0xffffffff) << 3);
                  if (lVar19 == 0) goto LAB_004ac60e;
                  memdescGetPhysAddrsForGpu(plVar1,lVar24,1,param_3,local_138,uVar18,lVar19);
                  if (local_161 == 0) {
                    kgmmuEncodePhysAddrs_IMPL(uVar7,iVar16,lVar19,local_148,uVar18);
LAB_004abe85:
                    lVar24 = 0;
                    do {
                      *(undefined8 *)(*(long *)(param_6 + 6) + lVar24) =
                           *(undefined8 *)(lVar19 + lVar24);
                      lVar24 = lVar24 + 8;
                    } while (lVar24 != uVar18 * 8);
                    *(ulong *)(param_6 + 8) = uVar18;
                    *(ulong *)(param_6 + 10) = param_4 - uVar18;
                  }
                  else {
                    local_f0 = (long *)0x0;
                    local_e8 = (long *)0x0;
                    iVar15 = (**(code **)(*(long *)(&DAT_00001b90 + *plVar1) + 800))
                                       (lVar24,*plVar1,*(long *)(&DAT_00001b90 + *plVar1),&local_f0,
                                        &local_e8);
                    if (iVar15 == 0) {
                      if (local_f0 == (long *)0xffffffffffffffff) {
                        nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x11ab,
                                     "nvGpuOpsBuildExternalAllocPhysAddrs",4,
                                     "NVRM: DMA base address is not set for BAR1P2P mapping\n");
                      }
                      else {
                        uVar20 = 0;
                        if (local_e8 != (long *)0x0) {
                          do {
                            plVar1 = (long *)(lVar19 + uVar20 * 8);
                            *plVar1 = *plVar1 + (long)local_f0;
                            uVar20 = (ulong)((int)uVar20 + 1);
                          } while (uVar20 < uVar18);
                          goto LAB_004abe85;
                        }
                        nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x11b2,
                                     "nvGpuOpsBuildExternalAllocPhysAddrs",4,
                                     "NVRM: DMA size is not set for BAR1P2P mapping\n");
                      }
                      iVar14 = 0x40;
                    }
                    else {
                      nvCheckOkFailedNoLog
                                (4,iVar15,
                                 "kbusGetBar1P2PDmaInfo_HAL(pMappingGpu, pRemoteGpu, GPU_GET_KERNEL_BUS(pRemoteGpu), &dmaBaseAddress, &dmaSize)"
                                 ,"src/kernel/rmapi/nv_gpu_ops.c",0x11a2);
                      iVar14 = iVar15;
                    }
                  }
                  portMemFree(lVar19);
                }
              }
              else {
                iVar14 = 0x1d;
              }
            }
          }
          else {
            iVar14 = 0x20;
          }
        }
        else {
LAB_004ac1c0:
          iVar14 = 0x1f;
        }
      }
    }
  }
LAB_004abee0:
  if (local_100 != plVar6) {
    fabricvaspacePutGpaMemdesc_IMPL(lVar17,local_100);
  }
LAB_004ab948:
  _nvGpuOpsLocksRelease(local_e0);
  threadStateFree(local_c8,0);
  return iVar14;
}


// ===== 004acd20 nvGpuOpsGetExternalAllocPtes =====

undefined8
nvGpuOpsGetExternalAllocPtes
          (long param_1,int param_2,undefined8 param_3,undefined8 param_4,long param_5)

{
  undefined8 uVar1;
  
  if ((param_2 != 0 && param_1 != 0) && (param_5 != 0)) {
    uVar1 = nvGpuOpsGetExternalAllocPtesOrPhysAddrs(param_1,param_2,param_3,param_4,param_5,0);
    return uVar1;
  }
  return 0x1f;
}


// ===== 004acd60 nvGpuOpsGetExternalAllocPhysAddrs =====

undefined8
nvGpuOpsGetExternalAllocPhysAddrs
          (long param_1,int param_2,undefined8 param_3,undefined8 param_4,long param_5)

{
  undefined8 uVar1;
  
  if ((param_2 != 0 && param_1 != 0) && (param_5 != 0)) {
    uVar1 = nvGpuOpsGetExternalAllocPtesOrPhysAddrs(param_1,param_2,param_3,param_4,0,param_5);
    return uVar1;
  }
  return 0x1f;
}


// ===== 004acda0 nvGpuOpsAddressSpaceDestroy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvGpuOpsAddressSpaceDestroy(int *param_1)

{
  long lVar1;
  
  lVar1 = rmapiGetInterface(1);
  if (*(long *)(param_1 + 0x14) != 0) {
    nvAssertFailedNoLog("vaSpace->dummyGpuAlloc.refCount == 0","src/kernel/rmapi/nv_gpu_ops.c",
                        0x12ed);
  }
  if (*(long *)(param_1 + 4) != 0) {
    portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 6));
    destroyAllGpuMemDescriptors_isra_0
              (**(undefined4 **)(*(long *)(param_1 + 2) + 0x48),*(undefined8 *)(param_1 + 4));
    portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 6));
  }
  if (*(long *)(param_1 + 0xc) != 0) {
    portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0xe));
    destroyAllGpuMemDescriptors_isra_0
              (**(undefined4 **)(*(long *)(param_1 + 2) + 0x48),*(undefined8 *)(param_1 + 0xc));
    portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0xe));
  }
  if (*(long *)(param_1 + 8) != 0) {
    portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 10));
    btreeDestroyData(*(undefined8 *)(param_1 + 8));
    portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 10));
  }
  if (*param_1 != 0) {
    (**(code **)(lVar1 + 0x18))(lVar1,**(undefined4 **)(*(long *)(param_1 + 2) + 0x48));
  }
  portSyncRwLockDestroy(*(undefined8 *)(param_1 + 6));
  portSyncRwLockDestroy(*(undefined8 *)(param_1 + 10));
  portSyncRwLockDestroy(*(undefined8 *)(param_1 + 0xe));
  portMemFree(param_1);
  return;
}


// ===== 004aceb0 nvGpuOpsMemoryAllocFb =====

undefined8 nvGpuOpsMemoryAllocFb(long param_1,undefined8 param_2,long param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  local_10 = 0;
  if ((param_1 != 0) && (param_3 != 0)) {
    if (param_4 == (undefined8 *)0x0) {
      param_4 = &local_30;
    }
    uVar1 = nvGpuOpsGpuMalloc_isra_0(param_1,0,param_2,param_3,0,param_4);
    return uVar1;
  }
  return 0x1f;
}


// ===== 004acf20 nvGpuOpsMemoryAllocSys =====

undefined8 nvGpuOpsMemoryAllocSys(long param_1,undefined8 param_2,long param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  local_10 = 0;
  if ((param_1 != 0) && (param_3 != 0)) {
    if (param_4 == (undefined8 *)0x0) {
      param_4 = &local_30;
    }
    uVar1 = nvGpuOpsGpuMalloc_isra_0(param_1,1,param_2,param_3,0,param_4);
    return uVar1;
  }
  return 0x1f;
}


// ===== 004acf90 nvGpuOpsPmaAllocPages =====

undefined4
nvGpuOpsPmaAllocPages
          (long param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,long param_5)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined1 local_b8 [152];
  
  local_f0 = 0;
  local_e8 = 0;
  local_e0 = 0;
  local_d8 = 0;
  local_d0 = 0;
  local_c8 = 0;
  local_c0 = 0;
  if ((param_1 != 0) && (param_5 != 0)) {
    threadStateInit(local_b8,0);
    puVar2 = &local_f0;
    if (param_4 != (undefined8 *)0x0) {
      puVar2 = param_4;
    }
    uVar1 = pmaAllocatePages(param_1,param_2,param_3,puVar2,param_5);
    threadStateFree(local_b8,0);
    return uVar1;
  }
  return 0x1f;
}


// ===== 004ad080 nvGpuOpsPmaPinPages =====

ulong nvGpuOpsPmaPinPages(long param_1,long param_2,undefined8 param_3,undefined8 param_4,
                         uint param_5)

{
  uint uVar1;
  ulong uVar2;
  undefined1 local_a8 [144];
  
  if ((param_1 != 0) && (param_2 != 0)) {
    if ((param_5 & 0x4000) != 0) {
      uVar2 = pmaPinPages();
      return uVar2;
    }
    threadStateInit(local_a8,0);
    uVar1 = pmaPinPages(param_1,param_2,param_3,param_4);
    threadStateFree(local_a8,0);
    return (ulong)uVar1;
  }
  return 0x1f;
}


// ===== 004ad120 nvGpuOpsPmaFreePages =====

void nvGpuOpsPmaFreePages(long param_1,long param_2,long param_3,long param_4,uint param_5)

{
  undefined1 local_a8 [152];
  
  if ((param_5 & 0x4000) == 0) {
    threadStateInit(local_a8,0);
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    if ((param_5 & 0x40) == 0) {
      pmaFreePages(param_1,param_2,param_3,param_4,param_5 & 1);
    }
    else {
      pmaFreePages(param_1,param_2,1,param_4 * param_3,param_5 & 1);
    }
    if ((param_5 & 0x4000) == 0) {
      threadStateFree(local_a8,0);
    }
  }
  return;
}


// ===== 004ad200 nvGpuOpsTsgAllocate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong nvGpuOpsTsgAllocate(undefined4 *param_1,int *param_2,undefined8 *param_3)

{
  uint uVar1;
  long *plVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  long lVar8;
  ulong uVar9;
  int iVar10;
  undefined8 local_4c;
  undefined8 local_44;
  undefined4 local_3c;
  
  puVar6 = (undefined8 *)rmapiGetInterface(1);
  local_4c = 0;
  local_44 = 0;
  local_3c = 0;
  if (((param_2 == (int *)0x0 || param_3 == (undefined8 *)0x0) || (param_1 == (undefined4 *)0x0)) ||
     (iVar4 = *param_2, 1 < iVar4 - 2U)) {
    uVar9 = 0x1f;
  }
  else {
    puVar7 = (undefined4 *)portMemAllocNonPaged(0x20);
    if (puVar7 == (undefined4 *)0x0) {
      uVar9 = 0x51;
    }
    else {
      portMemSet(puVar7,0,0x20);
      plVar2 = *(long **)(param_1 + 2);
      if (plVar2 == (long *)0x0) {
        nvAssertFailedNoLog("device","src/kernel/rmapi/nv_gpu_ops.c",0x18f4);
      }
      puVar3 = (undefined4 *)plVar2[9];
      if (puVar3 == (undefined4 *)0x0) {
        nvAssertFailedNoLog("session","src/kernel/rmapi/nv_gpu_ops.c",0x18f6);
      }
      *(undefined4 **)(puVar7 + 2) = param_1;
      puVar7[4] = iVar4;
      puVar7[5] = param_2[1];
      lVar8 = *plVar2;
      if (lVar8 == 0) {
        nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x764);
        lVar8 = *plVar2;
      }
      uVar1 = *(uint *)(lVar8 + 0x54);
      *puVar7 = 0;
      *(bool *)(puVar7 + 6) = uVar1 < 0x140;
      if (uVar1 < 0x140) {
        *param_3 = puVar7;
        return 0;
      }
      local_44 = CONCAT44(local_44._4_4_,*param_1);
      iVar4 = puVar7[4];
      if (1 < iVar4 - 2U) {
        nvAssertFailedNoLog("tsg->engineType == UVM_GPU_CHANNEL_ENGINE_TYPE_CE || tsg->engineType == UVM_GPU_CHANNEL_ENGINE_TYPE_SEC2"
                            ,"src/kernel/rmapi/nv_gpu_ops.c",0x1660);
        iVar4 = puVar7[4];
      }
      iVar10 = 0x31;
      if (iVar4 != 3) {
        iVar10 = puVar7[5] + 9;
      }
      uVar5 = gpuGetNv2080EngineType_IMPL(iVar10);
      local_44 = CONCAT44(uVar5,(undefined4)local_44);
      uVar9 = (*(code *)*puVar6)(puVar6,*puVar3,(int)plVar2[2],puVar7,0xa06c,&local_4c);
      if ((int)uVar9 == 0) {
        *param_3 = puVar7;
        return uVar9;
      }
      portMemFree(puVar7);
      uVar9 = uVar9 & 0xffffffff;
    }
  }
  return uVar9;
}


// ===== 004ad4b0 nvGpuOpsTsgDestroy =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void nvGpuOpsTsgDestroy(undefined4 *param_1)

{
  long lVar1;
  undefined4 *puVar2;
  long lVar3;
  
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  if (*(char *)(param_1 + 6) != '\0') {
    portMemFree(param_1);
    return;
  }
  lVar3 = rmapiGetInterface(1);
  lVar1 = *(long *)(param_1 + 2);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("vaSpace","src/kernel/rmapi/nv_gpu_ops.c",0x192e);
  }
  lVar1 = *(long *)(lVar1 + 8);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("device","src/kernel/rmapi/nv_gpu_ops.c",0x1930);
  }
  puVar2 = *(undefined4 **)(lVar1 + 0x48);
  if (puVar2 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("session","src/kernel/rmapi/nv_gpu_ops.c",0x1932);
  }
  (**(code **)(lVar3 + 0x18))(lVar3,*puVar2,*param_1,*(code **)(lVar3 + 0x18));
  portMemFree(param_1);
  return;
}


// ===== 004ad5d0 nvGpuOpsMemoryCpuMap =====

/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */

int nvGpuOpsMemoryCpuMap(long param_1,undefined8 param_2,long param_3,undefined8 *param_4)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long *local_40 [2];
  
  lVar4 = rmapiGetInterface(1);
  if ((param_1 == 0) || (param_4 == (undefined8 *)0x0)) {
    iVar3 = 0x1f;
  }
  else {
    lVar5 = portMemAllocNonPaged(0x48);
    if (lVar5 == 0) {
      iVar3 = 0xffff;
    }
    else {
      portSyncRwLockAcquireRead(*(undefined8 *)(param_1 + 0x18));
      local_40[0] = (long *)0x0;
      iVar3 = btreeSearch(param_2,local_40,*(undefined8 *)(param_1 + 0x10));
      if (iVar3 == 0) {
        lVar2 = *local_40[0];
        portSyncRwLockReleaseRead(*(undefined8 *)(param_1 + 0x18));
        if (lVar2 == 0) {
          nvAssertFailedNoLog("memDesc","src/kernel/rmapi/nv_gpu_ops.c",0x19ba);
        }
        iVar3 = *(int *)(lVar2 + 0x50);
        if (iVar3 == 0) {
          nvAssertFailedNoLog("memDesc->childHandle","src/kernel/rmapi/nv_gpu_ops.c",0x19bb);
          iVar3 = *(int *)(lVar2 + 0x50);
        }
        if (param_3 == 0) {
          param_3 = *(long *)(lVar2 + 0x48);
        }
        iVar3 = (**(code **)(lVar4 + 0x70))
                          (lVar4,**(undefined4 **)(*(long *)(param_1 + 8) + 0x48),
                           *(undefined4 *)(*(long *)(param_1 + 8) + 0x14),iVar3,0,param_3);
        if (iVar3 == 0) {
          *(undefined8 *)(lVar5 + 0x38) = 0;
          uVar1 = *(undefined4 *)(lVar2 + 0x50);
          *(undefined8 *)(lVar5 + 8) = 0;
          *(undefined4 *)(lVar5 + 0x40) = uVar1;
          *(undefined8 *)(lVar5 + 0x10) = 0;
          *(long *)lVar5 = lVar5;
          portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0x28));
          iVar3 = btreeInsert(lVar5,param_1 + 0x20);
          portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0x28));
          if (iVar3 == 0) {
            *param_4 = 0;
            return 0;
          }
        }
      }
      else {
        portSyncRwLockReleaseRead(*(undefined8 *)(param_1 + 0x18));
      }
      portMemFree(lVar5);
    }
  }
  return iVar3;
}


// ===== 004ad7f0 nvGpuOpsMemoryCpuUnMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvGpuOpsMemoryCpuUnMap(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long *local_30 [2];
  
  lVar3 = rmapiGetInterface(1);
  if ((param_1 != 0) && (param_2 != 0)) {
    portSyncRwLockAcquireRead(*(undefined8 *)(param_1 + 0x28));
    iVar2 = btreeSearch(param_2,local_30,*(undefined8 *)(param_1 + 0x20));
    portSyncRwLockReleaseRead(*(undefined8 *)(param_1 + 0x28));
    if (iVar2 != 0) {
      return;
    }
    lVar1 = *local_30[0];
    if (lVar1 != 0) {
      osGetCurrentProcess();
      iVar2 = (**(code **)(lVar3 + 0x88))
                        (lVar3,**(undefined4 **)(*(long *)(param_1 + 8) + 0x48),
                         *(undefined4 *)(*(long *)(param_1 + 8) + 0x14),
                         *(undefined4 *)(lVar1 + 0x40),*(undefined8 *)(lVar1 + 0x38),0);
      if (iVar2 != 0) {
        nvAssertFailedNoLog("status == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0x1a13,0x4ad86c);
      }
    }
    portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0x28));
    btreeUnlink(local_30[0],param_1 + 0x20);
    portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0x28));
    portMemFree(lVar1);
  }
  return;
}


// ===== 004ad910 nvGpuOpsMemoryFree =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvGpuOpsMemoryFree(long param_1,undefined8 param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long *local_30 [2];
  
  lVar4 = rmapiGetInterface(1);
  if (param_1 == 0) {
    nvAssertFailedNoLog("vaSpace","src/kernel/rmapi/nv_gpu_ops.c",0x1a25);
  }
  portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0x18));
  local_30[0] = (long *)0x0;
  iVar3 = btreeSearch(param_2,local_30,*(undefined8 *)(param_1 + 0x10));
  if (iVar3 == 0) {
    lVar1 = *local_30[0];
    btreeUnlink(local_30[0],param_1 + 0x10);
    portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0x18));
    if (lVar1 != 0) {
      if (*(int *)(lVar1 + 0x50) == 0) {
        nvAssertFailedNoLog("memDesc->childHandle","src/kernel/rmapi/nv_gpu_ops.c",0x1a2c);
        iVar3 = *(int *)(lVar1 + 0x40);
      }
      else {
        iVar3 = *(int *)(lVar1 + 0x40);
      }
      if (iVar3 == 0) {
        nvAssertFailedNoLog("memDesc->handle","src/kernel/rmapi/nv_gpu_ops.c",0x1a2d);
      }
      (**(code **)(lVar4 + 0x18))
                (lVar4,**(undefined4 **)(*(long *)(param_1 + 8) + 0x48),
                 *(undefined4 *)(lVar1 + 0x50));
      (**(code **)(lVar4 + 0x18))
                (lVar4,**(undefined4 **)(*(long *)(param_1 + 8) + 0x48),
                 *(undefined4 *)(lVar1 + 0x40));
      portMemFree(lVar1);
      return;
    }
  }
  else {
    portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0x18));
  }
  nvAssertFailedNoLog("memDesc","src/kernel/rmapi/nv_gpu_ops.c",0x1a2b);
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 004ada80 nvGpuOpsVaSpaceReleaseDummyAlloc =====

void nvGpuOpsVaSpaceReleaseDummyAlloc(long param_1)

{
  long lVar1;
  
  if ((*(uint *)(*(long *)(param_1 + 8) + 300) < 4) &&
     (*(char *)(*(long *)(param_1 + 8) + 0x60) == '\0')) {
    lVar1 = *(long *)(param_1 + 0x50);
  }
  else {
    nvAssertFailedNoLog("deviceNeedsDummyAlloc(vaSpace->device)","src/kernel/rmapi/nv_gpu_ops.c",
                        0x391);
    lVar1 = *(long *)(param_1 + 0x50);
  }
  if (lVar1 == 0) {
    nvAssertFailedNoLog("vaSpace->dummyGpuAlloc.refCount != 0","src/kernel/rmapi/nv_gpu_ops.c",0x392
                       );
    lVar1 = *(long *)(param_1 + 0x50);
  }
  *(long *)(param_1 + 0x50) = lVar1 + -1;
  if (lVar1 + -1 == 0) {
    if (*(long *)(param_1 + 0x60) != 0) {
      nvGpuOpsMemoryCpuUnMap(param_1);
    }
    if (*(long *)(param_1 + 0x58) != 0) {
      nvGpuOpsMemoryFree(param_1);
    }
    *(undefined8 *)(param_1 + 0x60) = 0;
    *(undefined8 *)(param_1 + 0x58) = 0;
  }
  return;
}


// ===== 004adb40 nvGpuOpsChannelDestroy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvGpuOpsChannelDestroy(long *param_1)

{
  long *plVar1;
  undefined4 *puVar2;
  long lVar3;
  code *pcVar4;
  char cVar5;
  undefined4 uVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  long *local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  long local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar6 = osGetCurrentProcess();
  lVar8 = rmapiGetInterface(1);
  if (param_1 == (long *)0x0) {
    return;
  }
  lVar9 = *param_1;
  if (lVar9 == 0) {
    nvAssertFailedNoLog("channel->tsg","src/kernel/rmapi/nv_gpu_ops.c",0x18a3);
    lVar9 = *param_1;
  }
  lVar9 = *(long *)(lVar9 + 8);
  if (lVar9 == 0) {
    nvAssertFailedNoLog("vaSpace","src/kernel/rmapi/nv_gpu_ops.c",0x18a5);
  }
  plVar1 = *(long **)(lVar9 + 8);
  if (plVar1 == (long *)0x0) {
    nvAssertFailedNoLog("device","src/kernel/rmapi/nv_gpu_ops.c",0x18a7);
  }
  puVar2 = (undefined4 *)plVar1[9];
  if (puVar2 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("session","src/kernel/rmapi/nv_gpu_ops.c",0x18a9);
  }
  if (*(int *)((long)param_1 + 0xc) != 0) {
    (**(code **)(lVar8 + 0x18))(lVar8,*puVar2);
  }
  if ((int)param_1[9] != 0) {
    (**(code **)(lVar8 + 0x18))(lVar8,*puVar2);
  }
  lVar10 = *plVar1;
  if (lVar10 == 0) {
    nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x764);
    lVar10 = *plVar1;
  }
  if (*(uint *)(lVar10 + 0x54) < 0x140) {
    (**(code **)(lVar8 + 0x88))
              (lVar8,*puVar2,*(undefined4 *)((long)plVar1 + 0x14),(int)param_1[1],param_1[8],0,uVar6
              );
  }
  else {
    nvGpuOpsMemoryCpuUnMap(lVar9,param_1[8]);
    nvGpuOpsMemoryFree(lVar9,param_1[0xe]);
  }
  if (*(char *)((long)param_1 + 0x81) == '\0') {
LAB_004adc2d:
    (**(code **)(lVar8 + 0x18))(lVar8,*puVar2,(int)param_1[1]);
    nvGpuOpsMemoryFree(lVar9,param_1[5]);
    nvGpuOpsMemoryCpuUnMap(lVar9,param_1[6]);
    nvGpuOpsMemoryFree(lVar9,param_1[3]);
    if ((char)param_1[0x10] != '\0') {
      cVar5 = channelNeedsDummyAlloc(param_1);
      if (cVar5 != '\x01') {
        nvAssertFailedNoLog("channelNeedsDummyAlloc(channel)","src/kernel/rmapi/nv_gpu_ops.c",0x1659
                           );
      }
      nvGpuOpsVaSpaceReleaseDummyAlloc(*(undefined8 *)(*param_1 + 8));
    }
    portMemFree(param_1);
    return;
  }
  lVar10 = *plVar1;
  if (lVar10 == 0) {
    nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x777);
    lVar10 = *plVar1;
  }
  if ((*(uint *)(lVar10 + 0x54) < 0x180) || (*(uint *)(lVar10 + 0x54) == 400)) {
    nvAssertFailedNoLog("isDeviceHopperPlus(device)","src/kernel/rmapi/nv_gpu_ops.c",0x18c5);
  }
  lVar10 = param_1[0x11];
  lVar11 = rmapiGetInterface(1);
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  portSyncRwLockAcquireRead(*(undefined8 *)(lVar9 + 0x18));
  local_70 = (long *)0x0;
  iVar7 = btreeSearch(lVar10,&local_70,*(undefined8 *)(lVar9 + 0x10));
  if (iVar7 == 0) {
    lVar3 = *local_70;
    portSyncRwLockReleaseRead(*(undefined8 *)(lVar9 + 0x18));
    if (lVar3 != 0) {
      if (*(int *)(lVar3 + 0x40) == 0) {
        nvAssertFailedNoLog("memDescVa->handle != 0","src/kernel/rmapi/nv_gpu_ops.c",0x146a);
      }
      if (*(int *)(lVar3 + 0x50) == 0) {
        nvAssertFailedNoLog("memDescVa->childHandle != 0","src/kernel/rmapi/nv_gpu_ops.c",0x146b);
      }
      if (lVar10 != *(long *)(lVar3 + 0x38)) {
        nvAssertFailedNoLog("memDescVa->address == gpuOffset","src/kernel/rmapi/nv_gpu_ops.c",0x146c
                           );
      }
      local_68 = CONCAT44(*(undefined4 *)(*(long *)(lVar9 + 8) + 0x10),
                          **(undefined4 **)(*(long *)(lVar9 + 8) + 0x48));
      local_60 = CONCAT44(local_60._4_4_,*(undefined4 *)(lVar3 + 0x40));
      local_50 = lVar10;
      iVar7 = (**(code **)(lVar11 + 0xa8))(lVar11,&local_68);
      if (iVar7 != 0) {
        nvAssertOkFailedNoLog
                  (iVar7,"pRmApi->Unmap(pRmApi, &unmapDmaParams)","src/kernel/rmapi/nv_gpu_ops.c",
                   0x1473);
      }
      nvGpuOpsFreeVirtual(lVar9,param_1[0x11]);
      goto LAB_004adc2d;
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar7,"findDescriptor(vaSpace->allocations, gpuOffset, (void**)&memDescVa)",
               "src/kernel/rmapi/nv_gpu_ops.c",0x1466);
    portSyncRwLockReleaseRead(*(undefined8 *)(lVar9 + 0x18));
  }
  nvAssertFailedNoLog("memDescVa != NULL","src/kernel/rmapi/nv_gpu_ops.c",0x1469);
                    /* WARNING: Does not return */
  pcVar4 = (code *)invalidInstructionException();
  (*pcVar4)();
}


// ===== 004ae000 nvGpuOpsChannelAllocate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

uint nvGpuOpsChannelAllocate(long param_1,uint *param_2,long *param_3,long *param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  long *plVar4;
  uint *puVar5;
  undefined8 uVar6;
  char cVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  int iVar13;
  undefined8 *puVar14;
  undefined4 *puVar15;
  long *plVar16;
  ulong uVar17;
  undefined4 *puVar18;
  long lVar19;
  long lVar20;
  long lVar21;
  long lVar22;
  uint uVar23;
  char *pcVar24;
  int iVar25;
  undefined8 *puVar26;
  undefined8 uVar27;
  byte bVar28;
  undefined4 local_b0;
  int local_ac;
  ulong local_a8;
  ulong local_a0;
  long local_98;
  long local_90;
  undefined8 local_88;
  long local_80;
  undefined8 local_78;
  undefined8 local_60;
  long *local_58;
  long local_50;
  
  bVar28 = 0;
  if ((((param_1 == 0) || (param_3 == (long *)0x0)) || (param_2 == (uint *)0x0)) ||
     (param_4 == (long *)0x0)) {
    return 0x1f;
  }
  iVar13 = *(int *)(param_1 + 0x10);
  uVar8 = iVar13 - 2;
  if (1 < uVar8) {
    nvAssertFailedNoLog("channelType == UVM_GPU_CHANNEL_ENGINE_TYPE_CE || channelType == UVM_GPU_CHANNEL_ENGINE_TYPE_SEC2"
                        ,"src/kernel/rmapi/nv_gpu_ops.c",0x1886);
  }
  local_a8 = 0;
  local_a0 = 0;
  local_98 = 0;
  local_90 = 0;
  uVar9 = osGetCurrentProcess();
  puVar14 = (undefined8 *)rmapiGetInterface(1);
  if (*param_2 == 0) {
    return 0x1f;
  }
  puVar3 = *(uint **)(param_1 + 8);
  plVar4 = *(long **)(puVar3 + 2);
  if (plVar4 == (long *)0x0) {
    nvAssertFailedNoLog("device","src/kernel/rmapi/nv_gpu_ops.c",0x168a);
  }
  puVar5 = (uint *)plVar4[9];
  if (puVar5 == (uint *)0x0) {
    nvAssertFailedNoLog("session","src/kernel/rmapi/nv_gpu_ops.c",0x168c);
  }
  uVar10 = ((char)plVar4[0xc] == '\0') + 1;
  lVar19 = *plVar4;
  if (lVar19 == 0) {
    nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x764);
    lVar19 = *plVar4;
  }
  uVar11 = param_2[1];
  if (*(uint *)(lVar19 + 0x54) < 0x140) {
    if (uVar11 != 0) {
      return 0x1f;
    }
    if (param_2[2] != 0) {
      return 0x1f;
    }
    uVar23 = 1;
    uVar1 = uVar10;
  }
  else {
    if (2 < uVar11) {
      return 0x1f;
    }
    uVar1 = param_2[2];
    if (2 < uVar1) {
      return 0x1f;
    }
    uVar23 = 1;
    if (uVar11 != 0) {
      uVar23 = uVar11;
    }
    if (uVar1 == 0) {
      uVar1 = uVar10;
    }
  }
  uVar10 = rmapiLockAcquire(2,0x400);
  if (uVar10 != 0) {
    return uVar10;
  }
  uVar10 = CliSetGpuContext(*puVar5,(int)plVar4[2],&local_90,0);
  rmapiLockRelease();
  if (uVar10 != 0) {
    return uVar10;
  }
  puVar15 = (undefined4 *)portMemAllocNonPaged(0x198);
  if (puVar15 == (undefined4 *)0x0) {
    return 0x51;
  }
  portMemSet(puVar15,0,0x198);
  uVar10 = gpumgrGetSubDeviceInstanceFromGpu(local_90);
  plVar16 = (long *)portMemAllocNonPaged(0x90);
  if (plVar16 == (long *)0x0) {
    uVar11 = 0x51;
    goto LAB_004aea66;
  }
  portMemSet(plVar16,0,0x90);
  *plVar16 = param_1;
  uVar11 = *param_2;
  *(uint *)((long)plVar16 + 0x7c) = uVar1;
  *(uint *)(plVar16 + 7) = uVar11;
  *(uint *)(plVar16 + 0xf) = uVar23;
  uVar2 = *param_2;
  *(undefined1 *)((long)puVar15 + 0x18a) = 1;
  cVar7 = gpuIsCCorApmFeatureEnabled_IMPL(local_90);
  if (cVar7 != '\0') {
    if ((uVar23 == 1) || (cVar7 = gpuIsApmFeatureEnabled_IMPL(local_90), cVar7 != '\0')) {
      *(undefined1 *)(puVar15 + 100) = 1;
    }
    else {
      *(undefined1 *)(puVar15 + 100) = 0;
    }
  }
  puVar18 = puVar15 + 0x5c;
  uVar11 = nvGpuOpsGpuMalloc_isra_0(puVar3,uVar23 == 1,(ulong)uVar2 * 8,plVar16 + 3,0,puVar18);
  if (uVar11 == 0) {
    cVar7 = gpuIsCCFeatureEnabled_IMPL(local_90);
    if (((cVar7 != '\0') && (uVar17 = 0, uVar23 != 1)) ||
       (uVar11 = nvGpuOpsMemoryCpuMap(puVar3,plVar16[3],(ulong)uVar2 * 8,&local_a8,0),
       uVar17 = local_a8, uVar11 == 0)) {
      plVar16[6] = uVar17;
      cVar7 = gpuIsCCorApmFeatureEnabled_IMPL(local_90);
      if (cVar7 != '\0') {
        *(undefined1 *)(puVar15 + 100) = 1;
      }
      uVar11 = nvGpuOpsGpuMalloc_isra_0(puVar3,1,0x30,plVar16 + 5,1,puVar18);
      if (uVar11 == 0) {
        lVar19 = plVar16[5];
        if (lVar19 == 0) {
          nvAssertFailedNoLog("channel->errorNotifierOffset","src/kernel/rmapi/nv_gpu_ops.c",0x1710)
          ;
          lVar19 = plVar16[5];
        }
        uVar11 = getHandleForVirtualAddr(puVar3,lVar19,0,&local_b0);
        if ((uVar11 != 0) ||
           (uVar11 = _nvGpuOpsLocksAcquireWithClientLockFlags(2,1,*puVar5,&local_88,0,0,0),
           uVar11 != 0)) goto LAB_004aed60;
        uVar12 = gpumgrGetDeviceGpuMask((int)plVar4[3]);
        uVar27 = local_88;
        cVar7 = CliGetDmaMappingInfo(local_88,(int)plVar4[2],local_b0,plVar16[5],uVar12,&local_98);
        if (cVar7 == '\0') {
          _nvGpuOpsLocksRelease(&local_78);
LAB_004aed56:
          uVar11 = 0xffff;
        }
        else {
          _nvGpuOpsLocksRelease(&local_78);
          lVar19 = *(long *)(local_98 + 8 + (ulong)uVar10 * 8);
          plVar16[4] = lVar19;
          if (lVar19 == 0) goto LAB_004aed56;
          *puVar15 = local_b0;
          uVar11 = getHandleForVirtualAddr(puVar3,plVar16[3],0,puVar15 + 1);
          if (uVar11 == 0) {
            *(long *)(puVar15 + 2) = plVar16[3];
            puVar15[4] = (int)plVar16[7];
            if (*plVar4 == 0) {
              nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x764);
            }
            if (*(uint *)(*plVar4 + 0x54) < 0x140) {
LAB_004ae55b:
              lVar19 = *plVar16;
              if (1 < *(int *)(lVar19 + 0x10) - 2U) {
                nvAssertFailedNoLog("tsg->engineType == UVM_GPU_CHANNEL_ENGINE_TYPE_CE || tsg->engineType == UVM_GPU_CHANNEL_ENGINE_TYPE_SEC2"
                                    ,"src/kernel/rmapi/nv_gpu_ops.c",0x1660);
              }
              if (*(int *)(lVar19 + 0x10) == 3) {
                iVar25 = 0x31;
              }
              else {
                iVar25 = *(int *)(lVar19 + 0x14) + 9;
              }
              uVar12 = gpuGetNv2080EngineType_IMPL(iVar25);
              puVar15[0x20] = uVar12;
              if (*(char *)(*plVar16 + 0x18) == '\0') {
                puVar15[7] = 0;
                puVar18 = (undefined4 *)*plVar16;
                uVar12 = *puVar18;
              }
              else {
                puVar18 = (undefined4 *)(ulong)*puVar3;
                puVar15[7] = *puVar3;
                uVar12 = (undefined4)plVar4[2];
              }
              puVar15[0x3d] = puVar15[0x3d] | 0x80;
              uVar11 = (*(code *)*puVar14)(puVar14,*puVar5,uVar12,plVar16 + 1,
                                           *(undefined4 *)((long)plVar4 + 0x24),puVar15,0x170);
              if (uVar11 == 0) {
                if (((local_90 == 0) || (*(long *)(local_90 + 0x1bc0) == 0)) ||
                   (cVar7 = kmigmgrIsMIGGpuInstancingEnabled_IMPL
                                      (local_90,*(long *)(local_90 + 0x1bc0),puVar18), cVar7 == '\0'
                   )) {
                  lVar19 = *plVar16;
                  if (1 < *(int *)(lVar19 + 0x10) - 2U) {
                    nvAssertFailedNoLog("tsg->engineType == UVM_GPU_CHANNEL_ENGINE_TYPE_CE || tsg->engineType == UVM_GPU_CHANNEL_ENGINE_TYPE_SEC2"
                                        ,"src/kernel/rmapi/nv_gpu_ops.c",0x1660);
                  }
                  if (*(int *)(lVar19 + 0x10) == 3) {
                    local_ac = 0x31;
                  }
                  else {
                    local_ac = *(int *)(lVar19 + 0x14) + 9;
                  }
LAB_004ae648:
                  lVar19 = gpuGetKernelFifoShared_IMPL(local_90);
                  uVar11 = (**(code **)(lVar19 + 0x218))(local_90,lVar19,2,local_ac,3,plVar16 + 2);
                  if (uVar11 == 0) {
                    puVar26 = &local_60;
                    for (lVar19 = 6; lVar19 != 0; lVar19 = lVar19 + -1) {
                      *(undefined4 *)puVar26 = 0;
                      puVar26 = (undefined8 *)((long)puVar26 + (ulong)bVar28 * -8 + 4);
                    }
                    lVar20 = rmapiGetInterface(1);
                    local_60 = CONCAT44(local_60._4_4_,1);
                    local_50 = (long)plVar16 + 0x14;
                    lVar19 = *(long *)(*(long *)(*plVar16 + 8) + 8);
                    local_58 = plVar16 + 1;
                    uVar11 = (**(code **)(lVar20 + 0x38))
                                       (lVar20,**(undefined4 **)(lVar19 + 0x48),
                                        *(undefined4 *)(lVar19 + 0x10),0x80170d,&local_60);
                    uVar17 = (ulong)uVar11;
                    if (uVar11 == 0) {
                      if (*plVar4 == 0) {
                        nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x764
                                           );
                      }
                      if (*(uint *)(*plVar4 + 0x54) < 0x140) {
                        uVar11 = (*(code *)puVar14[0xe])
                                           (puVar14,*puVar5,*(undefined4 *)((long)plVar4 + 0x14),
                                            (int)plVar16[1],0,0x200,&local_a0,0);
                        uVar17 = (ulong)uVar11;
                        if (uVar11 != 0) goto LAB_004af26e;
                      }
                      plVar16[8] = local_a0;
                      cVar7 = gpuIsCCFeatureEnabled_IMPL(local_90);
                      if (cVar7 != '\0') {
LAB_004ae83f:
                        if (*plVar4 == 0) {
                          nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",
                                              0x75e);
                        }
                        if ((0x12f < *(uint *)(*plVar4 + 0x54)) && (*(int *)(*plVar16 + 0x10) != 3))
                        {
                          pcVar24 = (char *)(ulong)*puVar5;
                          uVar11 = (*(code *)*puVar14)(puVar14,pcVar24,(int)plVar16[1],plVar16 + 9,
                                                       0xc076,0,0,uVar17);
                          if (uVar11 != 0) goto LAB_004af353;
                        }
                        portMemFree(puVar15);
                        *param_3 = (long)plVar16;
                        lVar19 = plVar16[8];
                        if (lVar19 != 0) {
                          lVar19 = lVar19 + 0x88;
                        }
                        *param_4 = lVar19;
                        lVar19 = plVar16[8];
                        if (lVar19 != 0) {
                          lVar19 = lVar19 + 0x8c;
                        }
                        param_4[1] = lVar19;
                        param_4[2] = plVar16[6];
                        *(undefined4 *)((long)param_4 + 0x1c) = *(undefined4 *)((long)plVar4 + 0x24)
                        ;
                        *(int *)(param_4 + 3) = (int)plVar16[7];
                        param_4[4] = plVar16[4];
                        *(int *)(param_4 + 6) = (int)plVar16[2];
                        *(undefined4 *)((long)param_4 + 0x34) =
                             *(undefined4 *)((long)plVar16 + 0x14);
                        param_4[0xb] = plVar16[3];
                        param_4[0xc] = plVar16[0xe] + 0x8c;
                        local_78 = 0;
                        param_4[0xd] = plVar16[0xe] + 0x88;
                        plVar4 = (long *)*param_3;
                        local_a8 = local_a8 & 0xffffffffff000000;
                        puVar14 = (undefined8 *)rmapiGetInterface(1);
                        if (plVar4 == (long *)0x0) {
                          nvAssertFailedNoLog("channel","src/kernel/rmapi/nv_gpu_ops.c",0x182d);
                        }
                        if (1 < uVar8) {
                          nvAssertFailedNoLog("engineType == UVM_GPU_CHANNEL_ENGINE_TYPE_CE || engineType == UVM_GPU_CHANNEL_ENGINE_TYPE_SEC2"
                                              ,"src/kernel/rmapi/nv_gpu_ops.c",0x182f);
                        }
                        lVar19 = *(long *)(*plVar4 + 8);
                        if (lVar19 == 0) {
                          nvAssertFailedNoLog("vaSpace","src/kernel/rmapi/nv_gpu_ops.c",0x1832);
                        }
                        plVar16 = *(long **)(lVar19 + 8);
                        if (plVar16 == (long *)0x0) {
                          nvAssertFailedNoLog("device","src/kernel/rmapi/nv_gpu_ops.c",0x1834);
                        }
                        puVar15 = (undefined4 *)plVar16[9];
                        if (puVar15 == (undefined4 *)0x0) {
                          nvAssertFailedNoLog("session","src/kernel/rmapi/nv_gpu_ops.c",0x1836);
                        }
                        if (iVar13 == 2) {
                          puVar26 = &local_78;
                          uVar9 = 8;
                          uVar8 = *(uint *)(*plVar4 + 0x14);
                          iVar13 = uVar8 + 0x2a;
                          if (uVar8 < 10) {
                            iVar13 = uVar8 + 9;
                          }
                          local_78 = CONCAT44(iVar13,1);
                          uVar12 = (undefined4)plVar16[5];
                        }
                        else {
                          uVar12 = *(undefined4 *)((long)plVar16 + 0x2c);
                          puVar26 = (undefined8 *)0x0;
                          uVar9 = 0;
                        }
                        *(undefined4 *)((long)plVar4 + 0xc) = 0;
                        uVar8 = (*(code *)*puVar14)(puVar14,*puVar15,(int)plVar4[1],
                                                    (long)plVar4 + 0xc,uVar12,puVar26,uVar9);
                        if (uVar8 != 0) goto LAB_004ae9f3;
                        lVar20 = *plVar16;
                        if (lVar20 == 0) {
                          nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",
                                              0x764);
                          lVar20 = *plVar16;
                        }
                        if (*(uint *)(lVar20 + 0x54) < 0x140) {
LAB_004aeab1:
                          local_a8 = CONCAT71(local_a8._1_7_,1);
                          uVar8 = (*(code *)puVar14[7])
                                            (puVar14,*puVar15,(int)plVar4[1],0xa06f0103,&local_a8,3)
                          ;
                          if (uVar8 == 0) {
                            return 0;
                          }
                        }
                        else {
                          local_a0 = local_a0 & 0xffffffff00000000;
                          lVar21 = rmapiGetInterface(1);
                          plVar16 = *(long **)(lVar19 + 8);
                          lVar20 = plVar16[1];
                          lVar22 = *plVar16;
                          puVar18 = (undefined4 *)plVar16[9];
                          if (lVar22 == 0) {
                            nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",
                                                0x764);
                            lVar22 = *plVar16;
                          }
                          if (*(uint *)(lVar22 + 0x54) < 0x140) {
                            nvAssertFailedNoLog("isDeviceVoltaPlus(vaSpace->device)",
                                                "src/kernel/rmapi/nv_gpu_ops.c",0x15f3);
                          }
                          uVar8 = (**(code **)(lVar21 + 0x38))
                                            (lVar21,*puVar18,(int)plVar4[1],0xc36f0108,&local_a0,4);
                          if (uVar8 == 0) {
                            plVar4[10] = *(long *)(lVar20 + 0xc0) + 0x90;
                            *(undefined4 *)(plVar4 + 0xb) = (undefined4)local_a0;
                            if (plVar4[4] == 0) {
                              nvAssertFailedNoLog("(channel->errorNotifier != NULL)",
                                                  "src/kernel/rmapi/nv_gpu_ops.c",0x1607);
                              uVar8 = 0x3d;
                            }
                            else {
                              plVar4[0xc] = plVar4[4] + 0x18;
                              uVar8 = serverGetClientUnderLock(g_resServ,*puVar18,&local_98);
                              if ((uVar8 == 0) &&
                                 (uVar8 = deviceGetByHandle_IMPL(local_98,(int)plVar16[2],&local_90)
                                 , uVar8 == 0)) {
                                cVar7 = gpuIsCCFeatureEnabled_IMPL
                                                  (*(undefined8 *)
                                                    (*(long *)(local_90 + 0x128) + 0xe0));
                                if (cVar7 == '\0') {
LAB_004aeca6:
                                  param_4[8] = plVar4[10];
                                  *(int *)(param_4 + 9) = (int)plVar4[0xb];
                                  param_4[10] = plVar4[0xc];
                                  if (*(char *)((long)plVar4 + 0x81) != '\0') {
                                    param_4[0xe] = plVar4[0x11] + 0x90;
                                  }
                                  param_4[5] = param_4[4] + 0x20;
                                  goto LAB_004aeab1;
                                }
                                local_80 = 0;
                                local_60 = 0;
                                local_58 = (long *)0x0;
                                lVar22 = *plVar16;
                                local_88 = 0;
                                if (lVar22 == 0) {
                                  nvAssertFailedNoLog("device->rmDevice",
                                                      "src/kernel/rmapi/nv_gpu_ops.c",0x777);
                                  lVar22 = *plVar16;
                                }
                                if ((*(uint *)(lVar22 + 0x54) < 0x180) ||
                                   (*(uint *)(lVar22 + 0x54) == 400)) {
                                  nvAssertFailedNoLog("isDeviceHopperPlus(device)",
                                                      "src/kernel/rmapi/nv_gpu_ops.c",0x1620);
                                }
                                uVar8 = nvGpuOpsAllocVirtual_isra_0
                                                  (lVar19,0x10000,&local_88,
                                                   *(undefined4 *)(lVar20 + 0xb8),&local_60);
                                uVar27 = local_88;
                                if (uVar8 == 0) {
                                  uVar8 = nvGpuOpsMapGpuMemory_isra_0
                                                    (lVar19,local_88,0x10000,0,&local_80,0);
                                  if (uVar8 == 0) {
                                    *(undefined1 *)((long)plVar4 + 0x81) = 1;
                                    plVar4[0x11] = local_80;
                                    goto LAB_004aeca6;
                                  }
                                  nvGpuOpsFreeVirtual(lVar19,uVar27);
                                }
                              }
                            }
                          }
                        }
                        (*(code *)puVar14[3])(puVar14,*puVar15,*(undefined4 *)((long)plVar4 + 0xc));
                        *(undefined4 *)((long)plVar4 + 0xc) = 0;
LAB_004ae9f3:
                        nvGpuOpsChannelDestroy(*param_3);
                        *param_3 = 0;
                        return uVar8;
                      }
                      lVar19 = *(long *)(*plVar16 + 8);
                      cVar7 = channelNeedsDummyAlloc(plVar16);
                      if (cVar7 == '\0') goto LAB_004ae83f;
                      puVar26 = &local_60;
                      for (lVar20 = 10; lVar20 != 0; lVar20 = lVar20 + -1) {
                        *(undefined4 *)puVar26 = 0;
                        puVar26 = (undefined8 *)((long)puVar26 + (ulong)bVar28 * -8 + 4);
                      }
                      lVar20 = *(long *)(lVar19 + 8);
                      if (lVar20 == 0) {
                        nvAssertFailedNoLog("device","src/kernel/rmapi/nv_gpu_ops.c",0x367);
                      }
                      if ((3 < *(uint *)(lVar20 + 300)) || (*(char *)(lVar20 + 0x60) != '\0')) {
                        nvAssertFailedNoLog("deviceNeedsDummyAlloc(device)",
                                            "src/kernel/rmapi/nv_gpu_ops.c",0x368);
                      }
                      if (*(long *)(lVar19 + 0x50) != 0) {
LAB_004ae814:
                        *(long *)(lVar19 + 0x50) = *(long *)(lVar19 + 0x50) + 1;
                        if (*(long *)(lVar19 + 0x58) == 0) {
                          nvAssertFailedNoLog("vaSpace->dummyGpuAlloc.gpuAddr",
                                              "src/kernel/rmapi/nv_gpu_ops.c",0x388);
                        }
                        if (*(long *)(lVar19 + 0x60) == 0) {
                          nvAssertFailedNoLog("vaSpace->dummyGpuAlloc.cpuAddr",
                                              "src/kernel/rmapi/nv_gpu_ops.c",0x389);
                        }
                        *(undefined1 *)(plVar16 + 0x10) = 1;
                        param_4[7] = *(long *)(lVar19 + 0x60);
                        goto LAB_004ae83f;
                      }
                      pcVar24 = (char *)0x0;
                      uVar11 = nvGpuOpsGpuMalloc_isra_0(lVar19,0,0x1000,lVar19 + 0x58,0);
                      uVar17 = (ulong)uVar11;
                      if (uVar11 == 0) {
                        uVar11 = nvGpuOpsMemoryCpuMap
                                           (lVar19,*(undefined8 *)(lVar19 + 0x58),0x1000,
                                            lVar19 + 0x60,0);
                        if (uVar11 == 0) goto LAB_004ae814;
                        pcVar24 = *(char **)(lVar19 + 0x58);
                        nvGpuOpsMemoryFree(lVar19);
                      }
LAB_004af353:
                      if (*plVar4 == 0) {
                        pcVar24 = "src/kernel/rmapi/nv_gpu_ops.c";
                        nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x764
                                           );
                      }
                      if ((*(uint *)(*plVar4 + 0x54) < 0x140) && (local_a0 != 0)) {
                        (*(code *)puVar14[0x11])
                                  (puVar14,*puVar5,*(undefined4 *)((long)plVar4 + 0x14),
                                   (int)plVar16[1],local_a0,0,uVar9,pcVar24);
                      }
                    }
                  }
                }
                else {
                  uVar6 = *(undefined8 *)(local_90 + 0x1bc0);
                  local_80 = 0;
                  uVar11 = deviceGetByHandle_IMPL(uVar27,(int)plVar4[2],&local_80);
                  if (uVar11 == 0) {
                    uVar11 = kmigmgrGetInstanceRefFromDevice_IMPL(local_90,uVar6,local_80,&local_60)
                    ;
                    if (uVar11 == 0) {
                      lVar19 = *plVar16;
                      if (1 < *(int *)(lVar19 + 0x10) - 2U) {
                        nvAssertFailedNoLog("tsg->engineType == UVM_GPU_CHANNEL_ENGINE_TYPE_CE || tsg->engineType == UVM_GPU_CHANNEL_ENGINE_TYPE_SEC2"
                                            ,"src/kernel/rmapi/nv_gpu_ops.c",0x1660);
                      }
                      if (*(int *)(lVar19 + 0x10) == 3) {
                        iVar25 = 0x31;
                      }
                      else {
                        iVar25 = *(int *)(lVar19 + 0x14) + 9;
                      }
                      uVar11 = kmigmgrGetLocalToGlobalEngineType_IMPL
                                         (local_90,uVar6,local_60,local_58,iVar25,&local_ac);
                      if (uVar11 == 0) goto LAB_004ae648;
                      uVar27 = 0x17af;
                      pcVar24 = 
                      "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, (NvU32)tsgEngineType(channel->tsg), &globalRmEngineId)"
                      ;
                    }
                    else {
                      uVar27 = 0x17ac;
                      pcVar24 = 
                      "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)";
                    }
                  }
                  else {
                    uVar27 = 0x17a9;
                    pcVar24 = "deviceGetByHandle(pClient, device->handle, &pDevice)";
                  }
                  nvCheckOkFailedNoLog(4,uVar11,pcVar24,"src/kernel/rmapi/nv_gpu_ops.c",uVar27);
                }
LAB_004af26e:
                (*(code *)puVar14[3])(puVar14,*puVar5,(int)plVar16[1]);
              }
            }
            else {
              cVar7 = gpuIsCCorApmFeatureEnabled_IMPL(local_90);
              if (cVar7 != '\0') {
                puVar15[5] = puVar15[5] | 4;
                if ((uVar1 == 1) || (cVar7 = gpuIsApmFeatureEnabled_IMPL(local_90), cVar7 != '\0'))
                {
                  *(undefined1 *)(puVar15 + 100) = 1;
                }
                else {
                  *(undefined1 *)(puVar15 + 100) = 0;
                }
              }
              uVar11 = nvGpuOpsGpuMalloc_isra_0(puVar3,uVar1 == 1,0x200,plVar16 + 0xe,0,puVar18);
              if (uVar11 == 0) {
                *(undefined4 *)(plVar16 + 0xd) = puVar15[99];
                uVar10 = gpumgrGetSubDeviceInstanceFromGpu(local_90);
                puVar15[(ulong)uVar10 + 8] = (int)plVar16[0xd];
                uVar10 = gpumgrGetSubDeviceInstanceFromGpu(local_90);
                *(undefined8 *)(puVar15 + (ulong)uVar10 * 2 + 0x10) = 0;
                cVar7 = gpuIsCCFeatureEnabled_IMPL(local_90);
                if (((cVar7 != '\0') && (uVar1 != 1)) ||
                   (uVar11 = nvGpuOpsMemoryCpuMap(puVar3,plVar16[0xe],0x200,&local_a0,0),
                   uVar11 == 0)) goto LAB_004ae55b;
              }
            }
          }
        }
LAB_004aed60:
        lVar19 = *plVar4;
        if (lVar19 == 0) {
          nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x764);
          lVar19 = *plVar4;
        }
        if (0x13f < *(uint *)(lVar19 + 0x54)) {
          if (local_a0 != 0) {
            nvGpuOpsMemoryCpuUnMap(puVar3);
          }
          if (plVar16[0xe] != 0) {
            nvGpuOpsMemoryFree(puVar3);
          }
        }
        nvGpuOpsMemoryFree(puVar3,plVar16[5]);
      }
      nvGpuOpsMemoryCpuUnMap(puVar3,plVar16[6]);
    }
    nvGpuOpsMemoryFree(puVar3,plVar16[3]);
  }
  if ((char)plVar16[0x10] != '\0') {
    cVar7 = channelNeedsDummyAlloc(plVar16);
    if (cVar7 != '\x01') {
      nvAssertFailedNoLog("channelNeedsDummyAlloc(channel)","src/kernel/rmapi/nv_gpu_ops.c",0x1659);
    }
    nvGpuOpsVaSpaceReleaseDummyAlloc(*(undefined8 *)(*plVar16 + 8));
  }
LAB_004aea66:
  portMemFree(plVar16);
  portMemFree(puVar15);
  return uVar11;
}


// ===== 004af510 nvGpuOpsQueryCesCaps =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsQueryCesCaps(long param_1,long param_2)

{
  ushort *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  undefined2 local_10a;
  undefined8 local_108;
  ulong local_100;
  long local_f8;
  undefined8 local_f0;
  undefined2 *local_e8;
  undefined1 local_e0 [24];
  undefined1 local_c8 [152];
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return 0x1f;
  }
  threadStateInit(local_c8,0);
  iVar4 = _nvGpuOpsLocksAcquireWithClientLockFlags
                    (2,1,**(undefined4 **)(param_1 + 0x48),0,3,0,0,local_e0);
  if (iVar4 != 0) {
    threadStateFree(local_c8,0);
    return iVar4;
  }
  local_100 = 0;
  local_f8 = 0;
  lVar6 = rmapiGetInterface(4);
  iVar4 = (**(code **)(lVar6 + 0x38))
                    (lVar6,**(undefined4 **)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x14),
                     0x20800123,&local_100,0x10);
  if (iVar4 == 0) {
    lVar7 = portMemAllocNonPaged((local_100 & 0xffffffff) << 2);
    if (lVar7 == 0) {
      iVar4 = 0x51;
    }
    else {
      local_f8 = lVar7;
      iVar4 = (**(code **)(lVar6 + 0x38))
                        (lVar6,**(undefined4 **)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x14),
                         0x20800123,&local_100,0x10);
      if (iVar4 == 0) {
        portMemSet(param_2,0,0x200);
        if ((uint)local_100 != 0) {
          lVar9 = 0;
          do {
            local_f0 = 0;
            local_e8 = (undefined2 *)0x0;
            local_108 = 0;
            uVar3 = *(uint *)(lVar7 + lVar9 * 4);
            local_10a = 0;
            if ((uVar3 - 0x34 < 10) || (uVar3 - 9 < 10)) {
              uVar2 = uVar3 - 9;
              if (0x12 < uVar3) {
                uVar2 = uVar3 - 0x2a;
              }
              local_e8 = &local_10a;
              local_f0 = CONCAT44(2,uVar3);
              iVar5 = (**(code **)(lVar6 + 0x38))
                                (lVar6,**(undefined4 **)(param_1 + 0x48),
                                 *(undefined4 *)(param_1 + 0x14),0x20802a01,&local_f0,0x10);
              if (iVar5 != 0) {
                uVar8 = nvstatusToString(iVar5);
                nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x21a1,"queryCopyEngines",4,
                             "NVRM: %s:%d: %s\n","queryCopyEngines",0x21a1,uVar8);
                iVar4 = iVar5;
                break;
              }
              local_108 = (ulong)uVar3;
              puVar1 = (ushort *)(param_2 + (ulong)uVar2 * 8);
              *puVar1 = ((byte)local_10a >> 1 & 1) << 2 | (local_10a & 1) * 2 |
                        ((byte)local_10a >> 2 & 1) << 3 | ((byte)local_10a >> 3 & 1) << 4 |
                        ((byte)local_10a >> 5 & 1) << 5 | ((byte)local_10a >> 4 & 1) << 6 |
                        ((byte)local_10a >> 6 & 1) << 7 | (local_10a._1_1_ >> 2 & 1) << 8 |
                        (local_10a._1_1_ >> 6 & 1) << 9 | *puVar1 & 0xfc01;
              iVar5 = (**(code **)(lVar6 + 0x38))
                                (lVar6,**(undefined4 **)(param_1 + 0x48),
                                 *(undefined4 *)(param_1 + 0x14),0x20802a02,&local_108,8);
              if (iVar5 != 0) {
                nvstatusToString(iVar5);
                nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x21b3,"queryCopyEngines",4,
                             "NVRM: %s:%d: %s\n","queryCopyEngines",0x21b3);
                iVar4 = iVar5;
                break;
              }
              *(byte *)puVar1 = (byte)*puVar1 | 1;
              *(undefined4 *)(puVar1 + 2) = local_108._4_4_;
            }
            lVar9 = lVar9 + 1;
          } while ((uint)lVar9 < (uint)local_100);
        }
      }
      portMemFree(lVar7);
    }
  }
  _nvGpuOpsLocksRelease(local_e0);
  threadStateFree(local_c8,0);
  return iVar4;
}


// ===== 004af950 nvGpuOpsQueryCaps =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */

int nvGpuOpsQueryCaps(long *param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  undefined1 local_138 [24];
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  ulong local_100 [7];
  undefined1 local_c8 [152];
  
  puVar2 = (undefined4 *)param_1[9];
  local_120 = 0;
  local_118 = 0;
  local_110 = 0;
  local_108 = 0;
  lVar4 = rmapiGetInterface(4);
  threadStateInit(local_c8,0);
  iVar3 = _nvGpuOpsLocksAcquireWithClientLockFlags(2,1,*(undefined4 *)param_1[9],0,3,0);
  if (iVar3 != 0) {
    threadStateFree(local_c8,0,0,local_138);
    return iVar3;
  }
  local_120 = CONCAT44(local_120._4_4_,(int)param_1[4]);
  iVar3 = (**(code **)(lVar4 + 0x38))(lVar4,*puVar2,*puVar2,0x205,&local_120,0x20);
  if (iVar3 == 0) {
    if (local_108._4_4_ != -1) {
      *param_2 = 1;
      *(int *)(param_2 + 4) = local_108._4_4_;
    }
    if ((char)param_1[0x23] == '\0') {
      lVar5 = *param_1;
      if (lVar5 == 0) {
        nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x777);
        lVar5 = *param_1;
      }
      if ((*(uint *)(lVar5 + 0x54) < 0x180) || (*(uint *)(lVar5 + 0x54) == 400)) {
        local_100[0] = local_100[0] & 0xffffffff00000000;
        uVar1 = *(undefined4 *)param_1[9];
        iVar3 = (**(code **)(lVar4 + 0x38))(lVar4,uVar1,uVar1,0x136,local_100,4);
        if (iVar3 == 0) {
          if ((uint)local_100[0] < 4) {
            if (1 < (uint)local_100[0]) {
              iVar3 = 0x81;
              goto LAB_004afa48;
            }
            if ((uint)local_100[0] == 1) goto LAB_004afa48;
          }
          else if ((uint)local_100[0] == 4) goto LAB_004afa48;
          iVar3 = 0x40;
          nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x1a65,"_convertSystemFabricStateToErrorCode"
                       ,4,"NVRM: Invalid Fabric State\n");
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar3,
                     "pRmApi->Control(pRmApi, pDevice->session->handle, pDevice->session->handle, NV0000_CTRL_CMD_SYSTEM_GET_FABRIC_STATUS, &fabricParams, sizeof(fabricParams))"
                     ,"src/kernel/rmapi/nv_gpu_ops.c",0x1a9c);
        }
      }
      else {
        local_100[0] = 0;
        local_100[1] = 0;
        local_100[2] = 0;
        local_100[3] = 0;
        local_100[4] = 0;
        local_100[5] = 0;
        local_100[6] = 0;
        iVar3 = (**(code **)(lVar4 + 0x38))
                          (lVar4,*(undefined4 *)param_1[9],*(undefined4 *)((long)param_1 + 0x14),
                           0x208001a3,local_100,0x38);
        if (iVar3 == 0) {
          if ((byte)local_100[0] < 3) {
            if ((byte)local_100[0] != 0) {
              iVar3 = 0x81;
            }
          }
          else if ((byte)local_100[0] != 3) {
            iVar3 = 0x40;
            nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x1a7a,
                         "_convertGpuFabricProbeStateToErrorCode",4,
                         "NVRM: Invalid Fabric Probe State\n");
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar3,
                     "pRmApi->Control(pRmApi, pDevice->session->handle, pDevice->subhandle, NV2080_CTRL_CMD_GET_GPU_FABRIC_PROBE_INFO, &fabricProbeParams, sizeof(fabricProbeParams))"
                     ,"src/kernel/rmapi/nv_gpu_ops.c",0x1a8f);
        }
      }
    }
  }
LAB_004afa48:
  _nvGpuOpsLocksRelease(local_138);
  threadStateFree(local_c8,0);
  return iVar3;
}


// ===== 004afc90 nvGpuOpsGetGpuInfo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int nvGpuOpsGetGpuInfo(undefined8 param_1,undefined4 *param_2,long param_3)

{
  int iVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined8 *puVar10;
  long lVar11;
  undefined8 *puVar12;
  long lVar13;
  ulong uVar14;
  long *plVar15;
  undefined8 uVar16;
  long lVar17;
  uint *puVar18;
  char *pcVar19;
  undefined4 uVar20;
  byte bVar21;
  undefined4 local_654;
  undefined4 local_650;
  undefined4 local_64c;
  uint local_648;
  undefined4 local_644;
  int local_640;
  undefined1 local_63c [4];
  undefined4 local_638;
  undefined4 local_634;
  undefined8 local_630;
  undefined8 local_628;
  undefined8 local_620;
  undefined8 local_618;
  undefined8 local_610;
  undefined8 local_608;
  undefined8 local_600;
  undefined8 local_5f8;
  undefined8 local_5f0;
  undefined8 local_5e8;
  undefined8 local_5dc;
  undefined8 local_5d4;
  undefined8 local_5cc;
  undefined8 local_5c4;
  undefined8 local_5bc;
  undefined8 local_5b4;
  undefined8 local_5ac;
  undefined8 local_5a4;
  undefined4 local_59c;
  undefined8 local_598;
  undefined8 local_590;
  undefined8 local_588;
  undefined8 local_580;
  undefined8 local_578;
  undefined8 local_570;
  ulong local_568;
  undefined8 local_560;
  undefined8 local_558;
  undefined1 local_550 [256];
  undefined4 local_450;
  undefined4 local_448;
  undefined4 local_444;
  undefined8 local_440;
  undefined4 local_438;
  
  bVar21 = 0;
  local_618 = 0;
  local_610 = 0;
  local_608 = 0;
  local_600 = 0;
  local_5f8 = 0;
  local_5f0 = 0;
  local_5e8 = 0;
  local_654 = 0;
  memset(local_550,0,0x110);
  local_628 = 0;
  local_620 = 0;
  local_5dc = 0;
  local_5d4 = 0;
  local_5cc = 0;
  local_5c4 = 0;
  local_5bc = 0;
  local_5b4 = 0;
  local_5ac = 0;
  local_5a4 = 0;
  local_59c = 0;
  memset(&local_440,0,0x404);
  local_650 = 0;
  local_64c = 1;
  local_648 = 2;
  local_644 = 0;
  local_640 = 0;
  puVar10 = (undefined8 *)rmapiGetInterface(1);
  lVar11 = gpumgrGetGpuFromUuid(param_1,2);
  if (lVar11 == 0) {
    return 0x12;
  }
  cVar5 = osIsGpuAccessible(lVar11);
  if (cVar5 == '\0') {
    return 0x1b;
  }
  iVar7 = nvGpuOpsCreateClient(puVar10,&local_650);
  if (iVar7 != 0) {
    return iVar7;
  }
  portMemCopy(local_550,0x10,param_1,0x10);
  local_450 = 2;
  iVar7 = (*(code *)puVar10[7])(puVar10,local_650,local_650,0x274,local_550,0x110);
  if (iVar7 != 0) goto LAB_004b0d3c;
  local_618 = CONCAT44(local_618._4_4_,local_448);
  iVar7 = (*(code *)*puVar10)(puVar10,local_650,local_650,&local_64c,0x80,&local_618,0x38);
  if (iVar7 != 0) goto LAB_004b0d3c;
  local_654 = local_444;
  iVar7 = (*(code *)*puVar10)(puVar10,local_650,local_64c,&local_648,0x2080,&local_654,4);
  if (iVar7 == 0) {
    portMemCopy(param_3 + 0x40,0x10,param_1,0x10);
    iVar7 = (*(code *)puVar10[7])(puVar10,local_650,local_648,0x20801701,&local_628,0x10);
    if (iVar7 == 0) {
      local_5dc = local_5dc & 0xffffffff00000000;
      *(undefined8 *)(param_3 + 0x50) = local_628;
      iVar7 = (*(code *)puVar10[7])(puVar10,local_650,local_648,0x20800110,&local_5dc,0x44);
      if (iVar7 == 0) {
        portStringCopy(param_3,0x40,(long)&local_5dc + 4,0x40);
        uVar20 = local_64c;
        uVar9 = local_650;
        *(undefined4 *)(param_3 + 0x6c) = 0;
        puVar12 = (undefined8 *)rmapiGetInterface(1);
        local_598 = 0;
        local_590 = 0;
        local_588 = 0;
        local_580 = 0;
        local_578 = 0;
        local_570 = 0;
        local_568 = 0;
        local_560 = 0;
        local_558 = 0;
        local_630 = 0;
        local_634 = 0;
        iVar7 = (*(code *)puVar12[7])(puVar12,uVar9,uVar20,0x800289,&local_630,8);
        uVar16 = 0x1b77;
        pcVar19 = 
        "pRmApi->Control(pRmApi, hClient, hDevice, NV0080_CTRL_CMD_GPU_GET_VIRTUALIZATION_MODE, &params, sizeof(params))"
        ;
        if (iVar7 == 0) {
          if ((int)local_630 == 2) {
            iVar7 = (*(code *)*puVar12)(puVar12,uVar9,uVar20,&local_634,0xa080,0,0);
            uVar16 = 0x1b81;
            pcVar19 = 
            "pRmApi->Alloc(pRmApi, hClient, hDevice, &vgpuHandle, KEPLER_DEVICE_VGPU, NULL, 0)";
            if (iVar7 != 0) goto LAB_004b0dd0;
            iVar7 = (*(code *)puVar12[7])(puVar12,uVar9,local_634,0xa0800301,&local_598,0x48);
            if (iVar7 != 0) {
              nvAssertOkFailedNoLog
                        (iVar7,
                         "pRmApi->Control(pRmApi, hClient, vgpuHandle, NVA080_CTRL_CMD_VGPU_GET_CONFIG, &cparams, sizeof(cparams))"
                         ,"src/kernel/rmapi/nv_gpu_ops.c",0x1b89);
              (*(code *)puVar12[3])(puVar12,uVar9,local_634);
              goto LAB_004b0cf0;
            }
            if ((local_568 & 0x80000000000) == 0) {
              uVar20 = 1;
            }
            else {
              uVar20 = 2;
              if ((local_568 & 0x8000000000000) == 0) {
                uVar20 = 3;
              }
            }
            *(undefined4 *)(param_3 + 0x6c) = uVar20;
            (*(code *)puVar12[3])(puVar12,uVar9,local_634);
          }
          *(undefined1 *)(param_3 + 100) = 0;
          iVar7 = findDeviceClasses_isra_0
                            (local_650,local_64c,param_3 + 0x58,param_3 + 0x5c,param_3 + 0x60,
                             local_63c,local_63c,local_63c,local_63c);
          if ((iVar7 == 0) &&
             (iVar7 = (*(code *)puVar10[7])(puVar10,local_650,local_64c,0x800280,&local_644,4),
             iVar7 == 0)) {
            *(undefined4 *)(param_3 + 0x68) = local_644;
            lVar17 = *(long *)(lVar11 + 0x1bc8);
            *(undefined8 *)(param_3 + 0x74) = 0;
            *(undefined8 *)(param_3 + 0x7c) = 0;
            if (*(char *)(lVar17 + 0x438) == '\0') {
              nvAssertFailedNoLog("kgrmgrGetLegacyKGraphicsStaticInfo(pGpu, pKernelGraphicsManager)->bInitialized"
                                  ,"src/kernel/rmapi/nv_gpu_ops.c",0x1b51);
            }
            else if (*(long *)(lVar17 + 0x430) == 0) {
              nvAssertFailedNoLog("kgrmgrGetLegacyKGraphicsStaticInfo(pGpu, pKernelGraphicsManager)->pGrInfo != NULL"
                                  ,"src/kernel/rmapi/nv_gpu_ops.c",0x1b52);
            }
            else {
              *(undefined4 *)(param_3 + 0x80) = *(undefined4 *)(*(long *)(lVar17 + 0x430) + 0xbc);
              *(undefined4 *)(param_3 + 0x78) = *(undefined4 *)(*(long *)(lVar17 + 0x430) + 0xa4);
              uVar8 = *(uint *)(lVar17 + 0x170) - (*(uint *)(lVar17 + 0x170) >> 1 & 0x55555555);
              uVar8 = (uVar8 & 0x33333333) + (uVar8 >> 2 & 0x33333333);
              *(uint *)(param_3 + 0x74) = ((uVar8 >> 4) + uVar8 & 0xf0f0f0f) * 0x1010101 >> 0x18;
              if ((*(long *)(lVar11 + 0x1bc0) == 0) ||
                 (cVar5 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar11), cVar5 == '\0')) {
                plVar15 = (long *)kgraphicsGetStaticInfo_IMPL
                                            (lVar11,*(undefined8 *)(lVar11 + 0x1bd0));
                if (plVar15 == (long *)0x0) {
                  nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL",
                                      "src/kernel/rmapi/nv_gpu_ops.c",0x1b69);
                }
                else {
                  *(undefined4 *)(param_3 + 0x7c) = *(undefined4 *)(*plVar15 + 0x4c);
                }
              }
              else {
                *(int *)(param_3 + 0x7c) = *(int *)(param_3 + 0x74) * *(int *)(param_3 + 0x80);
              }
            }
            local_440 = 0x3900000001;
            iVar7 = (*(code *)puVar10[7])(puVar10,local_650,local_648,0x20801303,&local_440,0x404);
            if (iVar7 == 0) {
              *(undefined4 *)(param_3 + 0x84) = local_438;
              if ((*(long *)(lVar11 + 0x1bc0) == 0) ||
                 (cVar5 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar11), cVar5 == '\0')) {
LAB_004b04f8:
                iVar7 = (*(code *)puVar10[7])(puVar10,local_650,local_648,0x20800119,&local_640,4);
                if (iVar7 == 0) {
                  *(bool *)(param_3 + 0x70) = local_640 != 0;
                  portMemSet(param_3 + 0x98,0,2);
                  uVar8 = local_648;
                  uVar9 = local_650;
                  local_638 = 0;
                  local_630 = local_630 & 0xffff000000000000;
                  puVar12 = (undefined8 *)rmapiGetInterface(1);
                  local_638 = uVar9;
                  local_634 = 0;
                  iVar7 = (*(code *)*puVar12)(puVar12,uVar9,uVar9,&local_634,0xcb33,&local_638,4,0);
                  if (iVar7 != 0) {
                    uVar16 = 0x1bb5;
                    pcVar19 = 
                    "pRmApi->Alloc(pRmApi, hClient, hClient, &hConfCompute, NV_CONFIDENTIAL_COMPUTE, &confComputeAllocParams, sizeof(confComputeAllocParams))"
                    ;
                    goto LAB_004b0dd0;
                  }
                  iVar7 = (*(code *)puVar12[7])(puVar12,uVar9,local_634,0xcb330101,&local_630,6);
                  if (iVar7 == 0) {
                    *(undefined1 *)(param_3 + 0x98) = 0;
                    if (local_630._3_1_ != '\x01') {
                      if ((local_630._3_1_ == '\x02') || (local_630._5_1_ == '\x01')) {
                        local_598 = (ulong)uVar8;
                        *(undefined1 *)(param_3 + 0x98) = 1;
                        iVar7 = (*(code *)puVar12[7])
                                          (puVar12,uVar9,local_634,0xcb33010c,&local_598,8);
                        if (iVar7 != 0) {
                          nvAssertOkFailedNoLog
                                    (iVar7,
                                     "pRmApi->Control(pRmApi, hClient, hConfCompute, NV_CONF_COMPUTE_CTRL_CMD_GPU_GET_KEY_ROTATION_STATE, &keyRotationParams, sizeof(keyRotationParams))"
                                     ,"src/kernel/rmapi/nv_gpu_ops.c",0x1bda);
                          goto LAB_004b0f7d;
                        }
                        if ((local_598._4_4_ & 0xfffffffd) == 1) {
                          *(undefined1 *)(param_3 + 0x99) = 1;
                        }
                      }
                      (*(code *)puVar12[3])(puVar12,uVar9,local_634);
                      uVar8 = local_648;
                      uVar9 = local_650;
                      lVar17 = rmapiGetInterface(1);
                      *(undefined4 *)(param_3 + 0x9c) = 0;
                      pcVar19 = (char *)portMemAllocNonPaged(0x1a4);
                      if (pcVar19 == (char *)0x0) goto LAB_004b0f0e;
                      portMemSet(pcVar19,0,0x1a4);
                      pcVar19[0] = '\x01';
                      pcVar19[1] = '\0';
                      pcVar19[2] = '\0';
                      pcVar19[3] = '\0';
                      pcVar19[4] = '3';
                      pcVar19[5] = '\0';
                      pcVar19[6] = '\0';
                      pcVar19[7] = '\0';
                      iVar7 = (**(code **)(lVar17 + 0x38))
                                        (lVar17,uVar9,uVar8,0x20801823,pcVar19,0x1a4);
                      iVar1 = *(int *)(pcVar19 + 8);
                      portMemFree(pcVar19);
                      if (iVar7 == 0) {
                        if (iVar1 == 1) {
                          iVar7 = allocNvlinkStatus(uVar9,uVar8,&local_630);
                          uVar14 = local_630;
                          if (iVar7 != 0) goto LAB_004b0cf0;
                          iVar7 = convertLinkMasksToBitVector(local_630,4,local_630 + 8,&local_598);
                          if (iVar7 != 0) {
                            pcVar19 = 
                            "NVRM: Failed to convert enabled linkmask into bit vector! 0x%x\n";
                            nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0xb41,
                                         "getNvlinkConnectionToNpu",4,
                                         "NVRM: Failed to convert enabled linkmask into bit vector! 0x%x\n"
                                         ,iVar7);
                          }
                          iVar7 = 0;
                          cVar5 = -1;
                          bVar21 = 0;
                          puVar18 = (uint *)(uVar14 + 0x20);
                          uVar8 = 0;
                          do {
                            cVar6 = bitVectorTest_IMPL(&local_598,0x40,iVar7);
                            if ((((cVar6 != '\0') && ((char)puVar18[0xe] != '\0')) &&
                                (*(char *)((long)puVar18 + 0x39) == '\0')) &&
                               (*(long *)(puVar18 + 0x1e) == 1)) {
                              bVar2 = (byte)(*puVar18 >> 4);
                              if (uVar8 == 0) {
                                cVar5 = *(char *)((long)puVar18 + 0xf);
                                uVar8 = puVar18[9];
                                bVar21 = bVar2 & 1;
                              }
                              else {
                                uVar8 = uVar8 + puVar18[9];
                                if (*(char *)((long)puVar18 + 0xf) != cVar5) {
                                  nvAssertFailedNoLog(
                                                  "version == nvlinkStatus->linkInfo[i].nvlinkVersion"
                                                  ,"src/kernel/rmapi/nv_gpu_ops.c",0xb5d);
                                }
                                if ((bVar2 & 1) != bVar21) {
                                  nvAssertFailedNoLog("*atomicSupported == atomicCap",
                                                      "src/kernel/rmapi/nv_gpu_ops.c",0xb5e);
                                }
                              }
                            }
                            iVar7 = iVar7 + 1;
                            puVar18 = puVar18 + 0x36;
                          } while (iVar7 != 0x40);
                          *(uint *)(param_3 + 0xa0) = uVar8;
                          if ((cVar5 == -1) && (uVar8 != 0)) {
                            nvAssertFailedNoLog("*linkBandwidthMBps == 0",
                                                "src/kernel/rmapi/nv_gpu_ops.c",0xb64);
                          }
                          uVar9 = rmControlToUvmNvlinkVersion(cVar5);
                          *(undefined4 *)(param_3 + 0x9c) = uVar9;
                          portMemFree(uVar14);
                        }
                        else if (iVar1 == 2) {
                          puVar12 = &local_598;
                          for (lVar17 = 7; lVar17 != 0; lVar17 = lVar17 + -1) {
                            *(undefined4 *)puVar12 = 0;
                            puVar12 = (undefined8 *)((long)puVar12 + (ulong)bVar21 * -8 + 4);
                          }
                          lVar17 = rmapiGetInterface(1);
                          pcVar19 = (char *)&local_598;
                          *(undefined4 *)(param_3 + 0xa0) = 0;
                          iVar7 = (**(code **)(lVar17 + 0x38))
                                            (lVar17,uVar9,uVar8,0x2080182b,pcVar19,0x1c);
                          if (iVar7 != 0) {
                            uVar16 = 0xb1c;
                            pcVar19 = 
                            "pRmApi->Control(pRmApi, hClient, hSubDevice, NV2080_CTRL_CMD_BUS_GET_C2C_INFO, &params, sizeof(params))"
                            ;
                            goto LAB_004b0dd0;
                          }
                          if (((char)local_598 != '\x01') || ((int)local_580 != 1)) {
                            nvAssertFailedNoLog(&DAT_00d939aa,"src/kernel/rmapi/nv_gpu_ops.c",0x1c2f
                                               );
                            iVar7 = 0x40;
                            goto LAB_004b0cf0;
                          }
                          *(uint *)(param_3 + 0xa0) = local_598._4_4_ * (int)local_588;
                          *(undefined4 *)(param_3 + 0x9c) = 8;
                        }
                        else if (iVar1 == 0) {
                          *(undefined4 *)(param_3 + 0x9c) = 1;
                          iVar7 = getPCIELinkRateMBps(uVar9,uVar8,param_3 + 0xa0);
                          if (iVar7 != 0) goto LAB_004b0cf0;
                        }
                        else {
                          pcVar19 = "NVRM: Unsupported sysmem connection type: %d\n";
                          nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x1c40,"getSysmemLinkInfo",4)
                          ;
                        }
                        nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x1c46,"getSysmemLinkInfo",1,
                                     "NVRM: sysmem link type: %d bw: %u\n",
                                     *(undefined4 *)(param_3 + 0x9c),*(undefined4 *)(param_3 + 0xa0)
                                     ,pcVar19);
                        if (*(int *)(param_3 + 0x9c) == 0) {
                          nvAssertFailedNoLog("pGpuInfo->sysmemLink != UVM_LINK_TYPE_NONE",
                                              "src/kernel/rmapi/nv_gpu_ops.c",0x1c47);
                        }
                        lVar17 = *(long *)(lVar11 + 0x1b70);
                        if (lVar17 == 0) {
                          iVar7 = 0x57;
                        }
                        else {
                          if (*(char *)(lVar11 + 0x45b) == '\0') {
                            *(undefined8 *)(param_3 + 0xa8) = 0;
                            lVar13 = 0;
                          }
                          else {
                            lVar13 = *(long *)(lVar17 + 0x478);
                            *(long *)(param_3 + 0xa8) = lVar13;
                            lVar13 = *(long *)(lVar17 + 0x480) - lVar13;
                          }
                          *(long *)(param_3 + 0xb0) = lVar13;
                          *(undefined1 *)(param_3 + 0xb8) = 0;
                          iVar7 = allocNvlinkStatus(local_650,local_648,&local_598);
                          uVar14 = local_598;
                          if (iVar7 == 0) {
                            uVar9 = getNvlinkConnectionToSwitch(local_598,&local_630);
                            iVar7 = rmControlToUvmNvlinkVersion(uVar9);
                            if (iVar7 != 0) {
                              lVar17 = *(long *)(lVar11 + 0x1ce8);
                              iVar7 = rmControlToUvmNvlinkVersion(uVar9);
                              if (iVar7 == 3) {
                                nvAssertFailedNoLog(
                                                  "rmControlToUvmNvlinkVersion(nvlinkVersion) != UVM_LINK_TYPE_NVLINK_1"
                                                  ,"src/kernel/rmapi/nv_gpu_ops.c",0x1d11);
                              }
                              *(undefined1 *)(param_3 + 0xb8) = 1;
                              if (lVar17 == 0) {
                                *(undefined8 *)(param_3 + 0xc0) = 0xffffffffffffffff;
                                *(undefined8 *)(param_3 + 0xd8) = 0xffffffffffffffff;
                              }
                              else {
                                *(undefined8 *)(param_3 + 0xc0) = *(undefined8 *)(lVar17 + 0x16a8);
                                *(undefined8 *)(param_3 + 0xd8) = *(undefined8 *)(lVar17 + 0x16b0);
                              }
                            }
                            portMemFree(uVar14);
                            *(undefined1 *)(param_3 + 0xe3) = 0;
                            *(undefined8 *)(param_3 + 0xe8) = 0xffffffffffffffff;
                            iVar7 = allocNvlinkStatus(local_650,local_648,&local_630);
                            uVar14 = local_630;
                            if (iVar7 == 0) {
                              iVar7 = convertLinkMasksToBitVector
                                                (local_630,4,local_630 + 8,&local_598);
                              if (iVar7 != 0) {
                                nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x1d3f,
                                             "getNvlinkDirectConnectInfo",4,
                                             "NVRM: Failed to convert enabled linkmask into bit vector! 0x%x\n"
                                             ,iVar7);
                              }
                              pcVar19 = (char *)(uVar14 + 0x2f);
                              cVar5 = -1;
                              iVar7 = 0;
                              do {
                                cVar6 = bitVectorTest_IMPL(&local_598,0x40,iVar7);
                                if ((((cVar6 != '\0') && (pcVar19[0x29] != '\0')) &&
                                    (pcVar19[0x2a] == '\0')) && (*(long *)(pcVar19 + 0x69) == 2)) {
                                  if (cVar5 == -1) {
                                    cVar5 = *pcVar19;
                                  }
                                  else if (cVar5 != *pcVar19) {
                                    cVar5 = -1;
                                    break;
                                  }
                                }
                                iVar7 = iVar7 + 1;
                                pcVar19 = pcVar19 + 0xd8;
                              } while (iVar7 != 0x40);
                              iVar7 = rmControlToUvmNvlinkVersion(cVar5);
                              if (iVar7 != 0) {
                                lVar17 = *(long *)(lVar11 + 0x1ce8);
                                iVar7 = rmControlToUvmNvlinkVersion(cVar5);
                                if (iVar7 == 3) {
                                  nvAssertFailedNoLog(
                                                  "rmControlToUvmNvlinkVersion(version) != UVM_LINK_TYPE_NVLINK_1"
                                                  ,"src/kernel/rmapi/nv_gpu_ops.c",0x1d62);
                                }
                                if (lVar17 == 0) {
                                  *(undefined8 *)(param_3 + 0xe8) = 0xffffffffffffffff;
                                }
                                else {
                                  lVar17 = *(long *)(lVar17 + 0x16b8);
                                  *(long *)(param_3 + 0xe8) = lVar17;
                                  if (lVar17 != -1) {
                                    *(undefined1 *)(param_3 + 0xe3) = 1;
                                  }
                                }
                              }
                              portMemFree(uVar14);
                              uVar8 = local_648;
                              uVar9 = local_650;
                              lVar17 = rmapiGetInterface(1);
                              puVar12 = (undefined8 *)portMemAllocNonPaged(0x234);
                              if (puVar12 == (undefined8 *)0x0) {
LAB_004b0f0e:
                                iVar7 = 0x1a;
                              }
                              else {
                                portMemSet(puVar12,0,0x234);
                                *puVar12 = 0x3a00000001;
                                iVar7 = (**(code **)(lVar17 + 0x38))
                                                  (lVar17,uVar9,uVar8,0x20800102,puVar12,0x234);
                                uVar8 = *(uint *)(puVar12 + 1);
                                portMemFree(puVar12);
                                if (iVar7 == 0) {
                                  *(byte *)(param_3 + 200) = (byte)uVar8 & 1;
                                  *(char *)(param_3 + 0xc9) = (char)(uVar8 >> 1);
                                  uVar14 = (ulong)(uVar8 >> 1 & 0xff);
                                  uVar16 = *(undefined8 *)(*(long *)(lVar11 + 0x1b78) + 0x460);
                                  *(undefined8 *)(param_3 + 0xd0) = uVar16;
                                  nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x1cde,"getEgmInfo",1
                                               ,
                                               "NVRM: EGM enabled: %u peerId: %u BaseAddr: 0x%llx\n"
                                               ,uVar8 & 1,uVar14,uVar16);
                                  uVar8 = local_648;
                                  uVar9 = local_650;
                                  lVar11 = rmapiGetInterface(1);
                                  puVar12 = (undefined8 *)portMemAllocNonPaged(0x234);
                                  if (puVar12 == (undefined8 *)0x0) goto LAB_004b0f0e;
                                  portMemSet(puVar12,0,0x234,uVar14);
                                  *puVar12 = 0x3000000001;
                                  iVar7 = (**(code **)(lVar11 + 0x38))
                                                    (lVar11,uVar9,uVar8,0x20800102,puVar12,0x234);
                                  iVar1 = *(int *)(puVar12 + 1);
                                  portMemFree(puVar12);
                                  if (iVar7 == 0) {
                                    *(bool *)(param_3 + 0xe0) = iVar1 == 1;
                                    nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x1c6b,"getAtsInfo"
                                                 ,1,"NVRM: ATS supported: %d\n",iVar1 == 1);
                                    uVar8 = local_648;
                                    uVar9 = local_650;
                                    lVar11 = rmapiGetInterface(1);
                                    puVar12 = (undefined8 *)portMemAllocNonPaged(0x234);
                                    if (puVar12 == (undefined8 *)0x0) goto LAB_004b0f0e;
                                    portMemSet(puVar12,0,0x234);
                                    *puVar12 = 0x4200000001;
                                    iVar7 = (**(code **)(lVar11 + 0x38))
                                                      (lVar11,uVar9,uVar8,0x20800102,puVar12,0x234);
                                    iVar1 = *(int *)(puVar12 + 1);
                                    portMemFree(puVar12);
                                    if (iVar7 == 0) {
                                      *(bool *)(param_3 + 0xe1) = iVar1 == 1;
                                      nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x1cb5,
                                                   "getNonPasidAtsInfo",1,
                                                   "NVRM: Non-PASID ATS supported: %d\n",iVar1 == 1)
                                      ;
                                      uVar8 = local_648;
                                      uVar9 = local_650;
                                      lVar11 = rmapiGetInterface(1);
                                      puVar12 = (undefined8 *)portMemAllocNonPaged(0x234);
                                      if (puVar12 == (undefined8 *)0x0) goto LAB_004b0f0e;
                                      portMemSet(puVar12,0,0x234);
                                      *puVar12 = 0x4400000001;
                                      iVar7 = (**(code **)(lVar11 + 0x38))
                                                        (lVar11,uVar9,uVar8,0x20800102,puVar12,0x234
                                                        );
                                      iVar1 = *(int *)(puVar12 + 1);
                                      portMemFree(puVar12);
                                      if (iVar7 == 0) {
                                        *(bool *)(param_3 + 0xe2) = iVar1 == 2;
                                        nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x1c8f,
                                                     "getCdmmInfo",1,"NVRM: CDMM Enabled: %d\n",
                                                     iVar1 == 2);
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                      goto LAB_004b0cf0;
                    }
                    nvAssertOkFailedNoLog
                              (0x56,"NV_ERR_NOT_SUPPORTED","src/kernel/rmapi/nv_gpu_ops.c",0x1bca);
                    iVar7 = 0x56;
                  }
                  else {
                    nvAssertOkFailedNoLog
                              (iVar7,
                               "pRmApi->Control(pRmApi, hClient, hConfCompute, NV_CONF_COMPUTE_CTRL_CMD_SYSTEM_GET_CAPABILITIES, &confComputeParams, sizeof(confComputeParams))"
                               ,"src/kernel/rmapi/nv_gpu_ops.c",0x1bbd);
                  }
LAB_004b0f7d:
                  (*(code *)puVar12[3])(puVar12,uVar9,local_634);
                }
              }
              else {
                puVar12 = &local_598;
                for (lVar17 = 0x39; lVar17 != 0; lVar17 = lVar17 + -1) {
                  *(undefined1 *)puVar12 = 0;
                  puVar12 = (undefined8 *)((long)puVar12 + (ulong)bVar21 * -2 + 1);
                }
                if (*(int *)(param_3 + 0x68) != 1) {
                  nvAssertFailedNoLog("pGpuInfo->subdeviceCount == 1",
                                      "src/kernel/rmapi/nv_gpu_ops.c",0x1e19);
                }
                uVar4 = local_64c;
                uVar3 = local_650;
                uVar9 = param_2[1];
                uVar20 = *param_2;
                iVar7 = rmapiLockAcquire(2,0x400);
                if (iVar7 == 0) {
                  iVar7 = serverutilGenResourceHandle(uVar3);
                  rmapiLockRelease();
                  if ((iVar7 == 0) &&
                     (iVar7 = (*(code *)puVar10[10])(puVar10,uVar3,uVar4,&local_630,uVar20,uVar9,1),
                     iVar7 == 0)) {
                    iVar7 = getSwizzIdFromSmcPartHandle_isra_0
                                      (uVar3,local_630 & 0xffffffff,&local_634);
                    (*(code *)puVar10[3])(puVar10,uVar3,local_630 & 0xffffffff);
                    if (iVar7 == 0) {
                      *(undefined1 *)(param_3 + 0x88) = 1;
                      *(undefined4 *)(param_3 + 0x8c) = local_634;
                      *(undefined4 *)(param_3 + 0x90) = *param_2;
                      uVar9 = param_2[1];
                      *(undefined4 *)(param_3 + 0x94) = uVar9;
                      iVar7 = (*(code *)puVar10[7])
                                        (puVar10,*param_2,uVar9,0xc63701aa,&local_598,0x39);
                      if (iVar7 == 0) {
                        portMemCopy(param_3 + 0x40,0x10,&local_598,0x10);
                        goto LAB_004b04f8;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else {
LAB_004b0dd0:
          nvAssertOkFailedNoLog(iVar7,pcVar19,"src/kernel/rmapi/nv_gpu_ops.c",uVar16);
        }
      }
    }
LAB_004b0cf0:
    (*(code *)puVar10[3])(puVar10,local_650,local_648);
  }
  (*(code *)puVar10[3])(puVar10,local_650,local_64c);
LAB_004b0d3c:
  (*(code *)puVar10[3])(puVar10,local_650,local_650);
  return iVar7;
}


// ===== 004b1480 nvGpuOpsServiceDeviceInterruptsRM =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsServiceDeviceInterruptsRM(long param_1)

{
  int iVar1;
  long lVar2;
  undefined4 local_d4;
  undefined1 local_d0 [24];
  undefined1 local_b8 [144];
  
  local_d4 = 0;
  lVar2 = rmapiGetInterface(4);
  threadStateInit(local_b8,0);
  iVar1 = _nvGpuOpsLocksAcquireWithClientLockFlags(0,1,**(undefined4 **)(param_1 + 0x48),0,3,0);
  if (iVar1 == 0) {
    local_d4 = 0xffffffff;
    iVar1 = (**(code **)(lVar2 + 0x38))
                      (lVar2,**(undefined4 **)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x14),
                       0x20801702,&local_d4,4);
    _nvGpuOpsLocksRelease(local_d0);
    threadStateFree(local_b8,0);
    return iVar1;
  }
  threadStateFree(local_b8,0,0,local_d0);
  return iVar1;
}


// ===== 004b1570 nvGpuOpsAccessBitsBufAlloc =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int nvGpuOpsAccessBitsBufAlloc(long param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined1 local_238 [4];
  undefined4 local_234;
  undefined1 local_230 [528];
  
  memset(local_238,0,0x210);
  puVar1 = *(undefined4 **)(param_1 + 0x48);
  puVar3 = (undefined8 *)rmapiGetInterface(1);
  *param_2 = 0;
  iVar2 = (*(code *)*puVar3)(puVar3,*puVar1,*(undefined4 *)(param_1 + 0x14),param_2,
                             *(undefined4 *)(param_1 + 0x3c),local_238);
  if (iVar2 != 0) {
    return iVar2;
  }
  *(undefined1 *)(param_2 + 1) = local_238[0];
  param_2[2] = local_234;
  portMemCopy(param_2 + 4,0x200,local_230,0x200);
  return 0;
}


// ===== 004b1640 nvGpuOpsAccessBitsBufFree =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void nvGpuOpsAccessBitsBufFree(long param_1,undefined4 *param_2)

{
  int iVar1;
  long lVar2;
  
  lVar2 = rmapiGetInterface(1);
  iVar1 = (**(code **)(lVar2 + 0x18))
                    (lVar2,**(undefined4 **)(param_1 + 0x48),*param_2,*(code **)(lVar2 + 0x18));
  if (iVar1 == 0) {
    *param_2 = 0;
  }
  return;
}


// ===== 004b1680 nvGpuOpsAccessBitsDump =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int nvGpuOpsAccessBitsDump(long param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  long lVar2;
  undefined1 local_240 [4];
  undefined4 local_23c;
  undefined1 local_238 [536];
  
  memset(local_240,0,0x218);
  if (param_3 == 1) {
    local_23c = 1;
  }
  else if (param_3 == 2) {
    local_23c = 2;
  }
  else if (param_3 != 0) {
    return 0x1f;
  }
  lVar2 = rmapiGetInterface(1);
  iVar1 = (**(code **)(lVar2 + 0x38))
                    (lVar2,**(undefined4 **)(param_1 + 0x48),*param_2,0xc7630103,local_240,0x218);
  if (iVar1 != 0) {
    return iVar1;
  }
  portMemCopy(param_2 + 0x84,0x200,local_238,0x200);
  return 0;
}


// ===== 004b1760 nvGpuOpsDupMemory =====

void nvGpuOpsDupMemory(void)

{
  dupMemory();
  return;
}


// ===== 004b1780 nvGpuOpsDupAllocation =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsDupAllocation(long param_1,long param_2,long param_3,undefined8 param_4,long *param_5)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined4 local_90;
  undefined4 local_8c;
  long local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_90 = 0;
  local_8c = 0;
  local_88 = 0;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_80 = 0;
  local_78 = 0;
  lVar3 = rmapiGetInterface(1);
  if (param_1 == 0) {
    nvCheckFailedNoLog(4,"srcVaSpace != 0","src/kernel/rmapi/nv_gpu_ops.c",0x20e0);
    return 0x1f;
  }
  if (param_3 == 0) {
    nvCheckFailedNoLog(4,"dstVaSpace != 0","src/kernel/rmapi/nv_gpu_ops.c",0x20e1);
    return 0x1f;
  }
  if (param_1 == param_3) {
    nvCheckFailedNoLog(4,"srcVaSpace != dstVaSpace","src/kernel/rmapi/nv_gpu_ops.c",0x20e3);
    return 0x1f;
  }
  if (param_2 == 0) {
    nvCheckFailedNoLog(4,"srcAddress != 0","src/kernel/rmapi/nv_gpu_ops.c",0x20e4);
    return 0x1f;
  }
  if (param_5 == (long *)0x0) {
    nvCheckFailedNoLog(4,"dstAddress != NULL","src/kernel/rmapi/nv_gpu_ops.c",0x20e5);
    return 0x1f;
  }
  iVar2 = getHandleForVirtualAddr(param_1,param_2,1,&local_8c);
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = dupMemory(*(undefined8 *)(param_3 + 8),**(undefined4 **)(*(long *)(param_1 + 8) + 0x48),
                    local_8c,0,&local_90,&local_70);
  uVar1 = local_90;
  if (iVar2 != 0) {
    return iVar2;
  }
  if (local_70._4_1_ == '\0') {
    lVar4 = *(long *)(param_3 + 8);
    iVar2 = 0x56;
    if (*(long *)(param_1 + 8) != lVar4) goto LAB_004b18e1;
  }
  local_80 = local_68;
  local_78 = param_4;
  iVar2 = nvGpuOpsAllocVirtual_isra_0(param_3,local_50,param_5,local_90,&local_80);
  if (iVar2 == 0) {
    iVar2 = nvGpuOpsMapGpuMemory_isra_0(param_3,*param_5,local_50,local_68,&local_88,0);
    if (iVar2 == 0) {
      if (*param_5 != local_88) {
        nvAssertFailedNoLog("tmpDstAddress == *dstAddress","src/kernel/rmapi/nv_gpu_ops.c",0x211b);
        return 0;
      }
      return 0;
    }
    nvGpuOpsFreeVirtual(param_3);
  }
  lVar4 = *(long *)(param_3 + 8);
LAB_004b18e1:
  (**(code **)(lVar3 + 0x18))(lVar3,**(undefined4 **)(lVar4 + 0x48),uVar1);
  return iVar2;
}


// ===== 004b1a70 nvGpuOpsSetPageDirectory =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsSetPageDirectory
              (undefined4 *param_1,undefined8 param_2,int param_3,char param_4,undefined4 param_5,
              undefined8 *param_6)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  undefined1 *extraout_RDX;
  undefined1 *puVar6;
  undefined8 local_118;
  long *local_110;
  undefined8 local_108;
  undefined1 local_100 [24];
  undefined8 local_e8;
  ulong local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined1 local_c8 [152];
  
  local_e8 = 0;
  local_e0 = 0;
  local_d8 = 0;
  local_d0 = 0;
  local_118 = 0;
  local_110 = (long *)0x0;
  lVar3 = rmapiGetInterface(4);
  if ((param_1 == (undefined4 *)0x0) || (param_3 == 0)) {
    return 0x1f;
  }
  puVar6 = local_100;
  threadStateInit(local_c8,0);
  iVar2 = _nvGpuOpsLocksAcquireWithClientLockFlags
                    (2,1,**(undefined4 **)(*(long *)(param_1 + 2) + 0x48),&local_108,3,0,0);
  if (iVar2 != 0) goto LAB_004b1caf;
  iVar2 = CliSetGpuContext(**(undefined4 **)(*(long *)(param_1 + 2) + 0x48),
                           *(undefined4 *)(*(long *)(param_1 + 2) + 0x10),&local_118,0);
  if (iVar2 == 0) {
    iVar2 = vaspaceGetByHandleOrDeviceDefault_IMPL
                      (local_108,*(undefined4 *)(*(long *)(param_1 + 2) + 0x10),*param_1,&local_110)
    ;
    if ((iVar2 != 0) || (local_110 == (long *)0x0)) {
      _nvGpuOpsLocksRelease(puVar6);
      threadStateFree(local_c8,0);
      return 0x1f;
    }
    cVar1 = (**(code **)(*local_110 + 0xb0))();
    if (cVar1 == '\0') {
LAB_004b1bd6:
      local_d8 = CONCAT44(local_d8._4_4_,*param_1);
      local_e0 = (ulong)CONCAT14(param_4 == '\0',param_3) | 0x800000000;
      lVar5 = *(long *)(param_1 + 2);
      local_d0 = CONCAT44(param_5,*(int *)(lVar5 + 0x1c) + 1);
      local_e8 = param_2;
      iVar2 = (**(code **)(lVar3 + 0x38))
                        (lVar3,**(undefined4 **)(lVar5 + 0x48),*(undefined4 *)(lVar5 + 0x10),
                         0x801813,&local_e8,0x20);
      if (iVar2 == 0) {
        uVar4 = (**(code **)(*local_110 + 200))(local_110,local_118);
        uVar4 = memdescGetPhysAddr(uVar4,1,0);
        *param_6 = uVar4;
      }
      cVar1 = (**(code **)(*local_110 + 0xb0))();
      if (cVar1 == '\0') goto LAB_004b1ca7;
    }
    else {
      lVar5 = (**(code **)(*local_110 + 200))(local_110,local_118);
      if (lVar5 != 0) {
        _nvGpuOpsLocksRelease(puVar6);
        threadStateFree(local_c8,0);
        return 0x56;
      }
      iVar2 = nvGpuOpsDisableVaSpaceChannels(param_1);
      if (iVar2 == 0) goto LAB_004b1bd6;
    }
    nvGpuOpsEnableVaSpaceChannels_isra_0(param_1);
  }
LAB_004b1ca7:
  _nvGpuOpsLocksRelease(puVar6);
  puVar6 = extraout_RDX;
LAB_004b1caf:
  threadStateFree(local_c8,0,puVar6);
  return iVar2;
}


// ===== 004b1d80 nvGpuOpsUnsetPageDirectory =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsUnsetPageDirectory(undefined4 *param_1)

{
  long lVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  undefined1 *extraout_RDX;
  undefined1 *puVar5;
  undefined1 *extraout_RDX_00;
  undefined8 local_f0;
  undefined8 local_e8;
  long *local_e0;
  undefined8 local_d8;
  undefined1 local_d0 [24];
  undefined1 local_b8 [144];
  
  local_f0 = 0;
  local_e8 = 0;
  local_e0 = (long *)0x0;
  lVar4 = rmapiGetInterface(4);
  if (param_1 == (undefined4 *)0x0) {
    return 0x1f;
  }
  puVar5 = local_d0;
  threadStateInit(local_b8,0);
  iVar3 = _nvGpuOpsLocksAcquireWithClientLockFlags
                    (2,1,**(undefined4 **)(*(long *)(param_1 + 2) + 0x48),&local_d8,3,0,0);
  if (iVar3 != 0) goto LAB_004b1f08;
  iVar3 = CliSetGpuContext(**(undefined4 **)(*(long *)(param_1 + 2) + 0x48),
                           *(undefined4 *)(*(long *)(param_1 + 2) + 0x10),&local_e8,0);
  if (iVar3 == 0) {
    iVar3 = vaspaceGetByHandleOrDeviceDefault_IMPL
                      (local_d8,*(undefined4 *)(*(long *)(param_1 + 2) + 0x10),*param_1,&local_e0);
    if ((iVar3 != 0) || (local_e0 == (long *)0x0)) {
      _nvGpuOpsLocksRelease(puVar5);
      threadStateFree(local_b8,0);
      return 0x1f;
    }
    cVar2 = (**(code **)(*local_e0 + 0xb0))();
    if ((cVar2 == '\0') || (iVar3 = nvGpuOpsDisableVaSpaceChannels(param_1), iVar3 == 0)) {
      lVar1 = *(long *)(param_1 + 2);
      local_f0 = CONCAT44(*(int *)(lVar1 + 0x1c) + 1,*param_1);
      iVar3 = (**(code **)(lVar4 + 0x38))
                        (lVar4,**(undefined4 **)(lVar1 + 0x48),*(undefined4 *)(lVar1 + 0x10),
                         0x801814,&local_f0,8);
      cVar2 = (**(code **)(*local_e0 + 0xb0))();
      if (cVar2 == '\0') goto LAB_004b1f00;
    }
    nvGpuOpsEnableVaSpaceChannels_isra_0(param_1);
    _nvGpuOpsLocksRelease(puVar5);
    puVar5 = extraout_RDX_00;
  }
  else {
LAB_004b1f00:
    _nvGpuOpsLocksRelease(puVar5);
    puVar5 = extraout_RDX;
  }
LAB_004b1f08:
  threadStateFree(local_b8,0,puVar5);
  return iVar3;
}


// ===== 004b1fa0 nvGpuOpsGetFbInfo =====

int nvGpuOpsGetFbInfo(long param_1,long param_2)

{
  int iVar1;
  undefined1 *extraout_RDX;
  undefined1 *puVar2;
  undefined1 local_d0 [24];
  undefined1 local_b8 [144];
  
  if ((param_1 != 0) && (param_2 != 0)) {
    puVar2 = local_d0;
    threadStateInit(local_b8,0);
    iVar1 = _nvGpuOpsLocksAcquireWithClientLockFlags(2,1,**(undefined4 **)(param_1 + 0x48),0,3,0,0);
    if (iVar1 == 0) {
      portMemCopy(param_2,0x40,param_1 + 0x50,0x40);
      _nvGpuOpsLocksRelease(puVar2);
      puVar2 = extraout_RDX;
    }
    threadStateFree(local_b8,0,puVar2);
    return iVar1;
  }
  return 0x1f;
}


// ===== 004b2070 nvGpuOpsGetEccInfo =====

undefined8 nvGpuOpsGetEccInfo(long param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  long lVar2;
  undefined8 uVar3;
  
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    lVar2 = *(long *)(param_1 + 8);
    uVar3 = 0x56;
    if (*(char *)(lVar2 + 0x70) != '\0') {
      *param_2 = *(undefined4 *)(lVar2 + 0x5c);
      param_2[1] = *(undefined4 *)(lVar2 + 0x58);
      *(undefined8 *)(param_2 + 2) = *(undefined8 *)(lVar2 + 0x60);
      uVar1 = *(undefined1 *)(lVar2 + 0x71);
      *(long *)(param_2 + 4) = lVar2 + 0x72;
      *(undefined1 *)(param_2 + 6) = uVar1;
      uVar3 = 0;
    }
    return uVar3;
  }
  return 0x1f;
}


// ===== 004b20c0 nvGpuOpsGetNvlinkInfo =====

undefined8 nvGpuOpsGetNvlinkInfo(long param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  long lVar2;
  undefined8 uVar3;
  
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    lVar2 = *(long *)(param_1 + 8);
    uVar3 = 0x56;
    if (*(char *)(lVar2 + 0xa0) != '\0') {
      *param_2 = *(undefined4 *)(lVar2 + 0x8c);
      param_2[1] = *(undefined4 *)(lVar2 + 0x88);
      *(undefined8 *)(param_2 + 2) = *(undefined8 *)(lVar2 + 0x90);
      uVar1 = *(undefined1 *)(lVar2 + 0xa1);
      *(long *)(param_2 + 4) = lVar2 + 0xa2;
      *(undefined1 *)(param_2 + 6) = uVar1;
      uVar3 = 0;
    }
    return uVar3;
  }
  return 0x1f;
}


// ===== 004b2120 nvGpuOpsFreeDupedHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsFreeDupedHandle(long *param_1,undefined4 param_2)

{
  long *plVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  undefined1 *extraout_RDX;
  undefined1 *puVar10;
  long local_100;
  undefined8 local_f8;
  long local_f0;
  undefined8 local_e8;
  undefined1 local_e0 [24];
  undefined1 local_c8 [152];
  
  local_100 = 0;
  lVar8 = rmapiGetInterface(4);
  if (param_1 != (long *)0x0) {
    puVar10 = local_e0;
    uVar2 = *(undefined4 *)param_1[9];
    threadStateInit(local_c8,0);
    iVar6 = _nvGpuOpsLocksAcquireWithClientLockFlags(2,1,uVar2,&local_f8,0,0,0);
    if (iVar6 == 0) {
      iVar6 = subdeviceGetByHandle_IMPL(local_f8,*(undefined4 *)((long)param_1 + 0x14),&local_f0);
      if (iVar6 == 0) {
        local_e8 = 0;
        lVar3 = *(long *)(*(long *)(local_f0 + 0x158) + 0xe0);
        iVar6 = serverGetClientUnderLock(g_resServ,*(undefined4 *)param_1[9],&local_e8);
        if (iVar6 == 0) {
          iVar6 = memGetByHandle_IMPL(local_e8,param_2,&local_100);
          if (iVar6 == 0) {
            uVar4 = *(undefined8 *)(local_100 + 0x118);
            iVar7 = memdescGetAddressSpace(uVar4);
            if (((iVar7 == 1) && (cVar5 = memdescGetFlag(uVar4,0x8000000000), cVar5 == '\0')) &&
               (cVar5 = memdescIsEgm(uVar4), cVar5 == '\0')) {
              memdescUnmapIommu(*(undefined8 *)(local_100 + 0x118),*(undefined4 *)(lVar3 + 0x868));
            }
            iVar7 = memdescGetAddressSpace(*(undefined8 *)(local_100 + 0x118));
            lVar3 = param_1[1];
            cVar5 = rmapiLockIsOwner();
            if ((cVar5 == '\0') || (cVar5 = rmGpuLockIsOwner(), cVar5 != '\0')) {
              nvAssertFailedNoLog("rmapiLockIsOwner() && !rmGpuLockIsOwner()",
                                  "src/kernel/rmapi/nv_gpu_ops.c",0x1fc3);
            }
            lVar9 = *param_1;
            if (lVar9 == 0) {
              nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x777);
              lVar9 = *param_1;
            }
            if (((0x17f < *(uint *)(lVar9 + 0x54)) && (*(uint *)(lVar9 + 0x54) != 400)) &&
               (((char)param_1[0x29] != '\0' && (iVar7 - 6U < 2)))) {
              LOCK();
              plVar1 = (long *)(lVar3 + 0xd0);
              *plVar1 = *plVar1 + -1;
              UNLOCK();
              if (*plVar1 == 0) {
                _nvGpuOpsP2pObjectDestroy(param_1[9],*(undefined4 *)(lVar3 + 200),3);
                *(undefined4 *)(lVar3 + 200) = 0;
              }
            }
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar6,"serverGetClientUnderLock(&g_resServ, hClient, &pRsClient)",
                     "src/kernel/rmapi/nv_gpu_ops.c",0x2d96);
        }
      }
      (**(code **)(lVar8 + 0x18))(lVar8,*(undefined4 *)param_1[9],param_2);
      _nvGpuOpsLocksRelease(puVar10);
      puVar10 = extraout_RDX;
    }
    threadStateFree(local_c8,0,puVar10);
    return iVar6;
  }
  return 0x1f;
}


// ===== 004b2450 nvGpuOpsInitFaultInfo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsInitFaultInfo(long *param_1,undefined8 *param_2)

{
  undefined4 *puVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  undefined8 *puVar5;
  long lVar6;
  undefined4 uVar7;
  undefined8 local_d8;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined8 local_b8;
  undefined8 local_b0;
  long local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  ulong local_40;
  
  puVar1 = (undefined4 *)param_1[9];
  local_c0 = 0;
  local_bc = 0;
  local_80 = 0;
  local_78 = 0;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_b8 = 0;
  puVar5 = (undefined8 *)rmapiGetInterface(1);
  lVar2 = param_1[2];
  iVar4 = serverGetClientUnderLock(g_resServ,*(undefined4 *)param_1[9],&local_b0);
  if (iVar4 != 0) {
    return iVar4;
  }
  iVar4 = deviceGetByHandle_IMPL(local_b0,(int)lVar2,&local_a8);
  if (iVar4 != 0) {
    return iVar4;
  }
  *(undefined4 *)(param_2 + 0x15) = 0;
  param_2[0x16] = local_a8;
  iVar4 = (*(code *)*puVar5)(puVar5,*puVar1,*(undefined4 *)((long)param_1 + 0x14),param_2 + 0x15,
                             *(undefined4 *)((long)param_1 + 0x34),&local_c0,4);
  if (iVar4 != 0) goto LAB_004b2597;
  lVar2 = *(long *)(*(long *)(local_a8 + 0x128) + 0xe0);
  cVar3 = gpuIsCCFeatureEnabled_IMPL(lVar2);
  if (((cVar3 != '\0') && (uVar7 = 0, *(char *)(lVar2 + 0x4a78) != '\0')) ||
     ((iVar4 = (*(code *)puVar5[7])
                         (puVar5,*puVar1,*(undefined4 *)(param_2 + 0x15),0xb0690105,&local_bc,4),
      uVar7 = local_bc, iVar4 == 0 &&
      (iVar4 = (*(code *)puVar5[0xe])
                         (puVar5,*puVar1,*(undefined4 *)((long)param_1 + 0x14),
                          *(undefined4 *)(param_2 + 0x15),0,*(undefined4 *)(param_2 + 9),&local_b8,0
                         ), iVar4 == 0)))) {
    lVar6 = *param_1;
    if (lVar6 == 0) {
      nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x764);
      lVar6 = *param_1;
    }
    if (0x13f < *(uint *)(lVar6 + 0x54)) {
      local_88 = 0;
      local_a0 = 0;
      local_98 = 0;
      local_90 = 0;
      iVar4 = (*(code *)puVar5[7])
                        (puVar5,*puVar1,*(undefined4 *)(param_2 + 0x15),0xc3690101,&local_a0,0x20);
      if (iVar4 != 0) goto LAB_004b2813;
      param_2[0xd] = local_a0;
      param_2[0xe] = local_98;
      *(undefined4 *)(param_2 + 0xf) = (undefined4)local_88;
      param_2[0x14] = local_90;
    }
    cVar3 = gpuIsCCFeatureEnabled_IMPL(lVar2);
    if ((cVar3 == '\0') || (*(char *)(lVar2 + 0x4a78) == '\0')) {
      local_d8 = 0;
LAB_004b285f:
      local_40 = CONCAT44(local_40._4_4_,1);
      iVar4 = (*(code *)puVar5[7])
                        (puVar5,*puVar1,*(undefined4 *)(param_2 + 0x15),0xb0690106,&local_80,0x48);
      if (iVar4 == 0) {
        *(undefined4 *)(param_2 + 9) = uVar7;
        *param_2 = local_80;
        param_2[1] = local_78;
        param_2[2] = local_70;
        param_2[3] = local_68;
        param_2[4] = local_60;
        param_2[5] = local_58;
        *(undefined4 *)(param_2 + 7) = (undefined4)local_50;
        param_2[6] = local_48;
        param_2[8] = local_b8;
        param_2[10] = local_d8;
        cVar3 = gpuIsCCFeatureEnabled_IMPL(lVar2);
        if ((cVar3 == '\0') || (*(char *)(lVar2 + 0x4a78) == '\0')) {
          return 0;
        }
        lVar6 = kgmmuGetShadowFaultBufferCslContext_IMPL(lVar2,*(undefined8 *)(lVar2 + 0x1b98),1);
        param_2[0xb] = lVar6;
        if (lVar6 != 0) {
          return 0;
        }
        nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x24e4,"nvGpuOpsInitFaultInfo",4,
                     "NVRM: Replayable buffer CSL context not allocated\n");
      }
    }
    else {
      local_a0 = 0;
      local_98 = 0;
      local_90 = 0;
      iVar4 = (*(code *)puVar5[7])
                        (puVar5,*puVar1,*(undefined4 *)(param_2 + 0x15),0xc3690103,&local_a0,0x18);
      if (iVar4 == 0) {
        local_b8 = local_a0;
        uVar7 = (undefined4)local_90;
        local_d8 = local_98;
        portMemSet(&local_80,0,0x48);
        local_40 = local_40 & 0xffffffff00000000;
        iVar4 = (*(code *)puVar5[7])
                          (puVar5,*puVar1,*(undefined4 *)(param_2 + 0x15),0xb0690106,&local_80,0x48)
        ;
        if (iVar4 == 0) {
          param_2[0x12] = local_78;
          goto LAB_004b285f;
        }
      }
    }
  }
LAB_004b2813:
  cVar3 = gpuIsCCFeatureEnabled_IMPL(lVar2);
  if ((cVar3 == '\0') || (*(char *)(lVar2 + 0x4a78) == '\0')) {
    gpuDeviceUnmapCpuFreeHandle(param_1,*(undefined4 *)(param_2 + 0x15),param_2[8],0);
  }
LAB_004b2597:
  portMemSet(param_2,0,0xb8);
  return iVar4;
}


// ===== 004b29a0 nvGpuOpsInitAccessCntrInfo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong nvGpuOpsInitAccessCntrInfo(long param_1,undefined8 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined8 *puVar3;
  ulong uVar4;
  undefined4 local_88;
  undefined4 local_84;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_40;
  
  puVar1 = *(undefined4 **)(param_1 + 0x48);
  local_88 = 0;
  local_84 = 0;
  puVar3 = (undefined8 *)rmapiGetInterface(1);
  local_78 = 0;
  uVar4 = rmapiLockAcquire(2,0x400);
  if ((int)uVar4 == 0) {
    uVar2 = CliSetGpuContext(*puVar1,*(undefined4 *)(param_1 + 0x10),&local_78,0);
    rmapiLockRelease();
    uVar4 = (ulong)uVar2;
    if (uVar2 == 0) {
      *(undefined4 *)((long)param_2 + 0x44) = 0;
      local_88 = param_3;
      uVar4 = (*(code *)*puVar3)(puVar3,*puVar1,*(undefined4 *)(param_1 + 0x14),(long)param_2 + 0x44
                                 ,*(undefined4 *)(param_1 + 0x38),&local_88,4);
      if ((int)uVar4 == 0) {
        uVar4 = (*(code *)puVar3[0xe])
                          (puVar3,*puVar1,*(undefined4 *)(param_1 + 0x14),
                           *(undefined4 *)((long)param_2 + 0x44),0,*(undefined4 *)(param_2 + 8),
                           &local_80,0);
        if ((int)uVar4 == 0) {
          param_2[7] = local_80;
          uVar4 = (*(code *)puVar3[7])
                            (puVar3,*puVar1,*(undefined4 *)((long)param_2 + 0x44),0xc3650105,
                             &local_84,4);
          if ((int)uVar4 == 0) {
            *(undefined4 *)(param_2 + 8) = local_84;
            uVar4 = (*(code *)puVar3[7])
                              (puVar3,*puVar1,*(undefined4 *)((long)param_2 + 0x44),0xc3650106,
                               &local_70,0x38);
            if ((int)uVar4 == 0) {
              *param_2 = local_70;
              param_2[1] = local_68;
              param_2[2] = local_60;
              param_2[3] = local_58;
              param_2[4] = local_50;
              param_2[5] = local_48;
              *(undefined4 *)(param_2 + 6) = local_40;
              return uVar4;
            }
          }
        }
        gpuDeviceUnmapCpuFreeHandle(param_1,*(undefined4 *)((long)param_2 + 0x44),param_2[7],0);
        uVar4 = uVar4 & 0xffffffff;
      }
      *(undefined4 *)((long)param_2 + 0x44) = 0;
      param_2[7] = 0;
      return uVar4;
    }
  }
  return uVar4;
}


// ===== 004b2b80 nvGpuOpsEnableAccessCntr =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvGpuOpsEnableAccessCntr(long param_1,long param_2,uint *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined8 local_30;
  
  puVar2 = *(undefined4 **)(param_1 + 0x48);
  local_40 = 0;
  uStack_3c = 0;
  local_38 = 0;
  uStack_34 = 0;
  local_30 = 0;
  local_48 = 0;
  lVar3 = rmapiGetInterface(1);
  local_40 = 0;
  uVar1 = *param_3;
  if (uVar1 == 3) {
    local_40 = 2;
  }
  else if (uVar1 < 4) {
    if (uVar1 != 1) {
      if (uVar1 != 2) {
        return 0x1f;
      }
      local_40 = 1;
    }
  }
  else {
    if (uVar1 != 4) {
      return 0x1f;
    }
    local_40 = 3;
  }
  uStack_34 = 0;
  uStack_3c = 0;
  local_38 = 3;
  local_30 = CONCAT44(0x1f,param_3[1]);
  uVar4 = (**(code **)(lVar3 + 0x38))
                    (lVar3,*puVar2,*(undefined4 *)(param_2 + 0x44),0xc3650109,&local_40,0x18);
  if ((int)uVar4 == 0) {
    local_48 = CONCAT35(local_48._5_3_,0x100000000);
    local_48 = CONCAT44(local_48._4_4_,2);
    uVar4 = (**(code **)(lVar3 + 0x38))
                      (lVar3,*puVar2,*(undefined4 *)(param_2 + 0x44),0xc3650104,&local_48,8);
  }
  return uVar4;
}


// ===== 004b2cc0 nvGpuOpsDisableAccessCntr =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

void nvGpuOpsDisableAccessCntr(long param_1,long param_2)

{
  long lVar1;
  undefined8 local_20;
  
  lVar1 = rmapiGetInterface(1);
  local_20 = 1;
  (**(code **)(lVar1 + 0x38))
            (lVar1,**(undefined4 **)(param_1 + 0x48),*(undefined4 *)(param_2 + 0x44),0xc3650104,
             &local_20,8);
  return;
}


// ===== 004b2d20 nvGpuOpsDestroyAccessCntrInfo =====

undefined8 nvGpuOpsDestroyAccessCntrInfo(undefined8 param_1,long param_2)

{
  gpuDeviceUnmapCpuFreeHandle
            (param_1,*(undefined4 *)(param_2 + 0x44),*(undefined8 *)(param_2 + 0x38),0);
  portMemSet(param_2,0,0x48);
  return 0;
}


// ===== 004b2d60 nvGpuOpsDestroyFaultInfo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsDestroyFaultInfo(long *param_1,long param_2)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined4 uVar4;
  int iVar5;
  long local_38;
  undefined8 local_30;
  
  lVar3 = rmapiGetInterface(1);
  iVar2 = rmapiLockAcquire(2,0x400);
  if (iVar2 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0x25c1);
  }
  iVar2 = CliSetGpuContext(*(undefined4 *)param_1[9],(int)param_1[2],&local_38,0);
  if (iVar2 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0x25c3);
  }
  rmapiLockRelease();
  iVar5 = *(int *)(param_2 + 0xa8);
  uVar4 = 0;
  if (iVar5 != 0) {
    if (*param_1 == 0) {
      nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x764);
      if (0x13f < *(uint *)(*param_1 + 0x54)) {
        iVar5 = *(int *)(param_2 + 0xa8);
        goto LAB_004b2e16;
      }
LAB_004b2e4e:
      uVar4 = 0;
      if (*(int *)(param_2 + 0xa8) == 0) goto LAB_004b2dcd;
    }
    else if (0x13f < *(uint *)(*param_1 + 0x54)) {
LAB_004b2e16:
      local_30 = *(undefined8 *)(param_2 + 0x68);
      iVar2 = (**(code **)(lVar3 + 0x38))
                        (lVar3,*(undefined4 *)param_1[9],iVar5,0xc3690102,&local_30,8);
      if (iVar2 != 0) {
        nvAssertFailedNoLog("status == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0x25d2);
      }
      goto LAB_004b2e4e;
    }
    cVar1 = gpuIsCCFeatureEnabled_IMPL(local_38);
    uVar4 = *(undefined4 *)(param_2 + 0xa8);
    if ((cVar1 != '\0') && (*(char *)(local_38 + 0x4a78) != '\0')) {
      local_30 = *(undefined8 *)(param_2 + 0x40);
      iVar2 = (**(code **)(lVar3 + 0x38))
                        (lVar3,*(undefined4 *)param_1[9],uVar4,0xc3690104,&local_30,8);
      if (iVar2 != 0) {
        nvAssertFailedNoLog("status == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0x25e1);
      }
      goto LAB_004b2ddc;
    }
  }
LAB_004b2dcd:
  gpuDeviceUnmapCpuFreeHandle(param_1,uVar4,*(undefined8 *)(param_2 + 0x40),0);
LAB_004b2ddc:
  portMemSet(param_2,0,0xb8);
  return iVar2;
}


// ===== 004b2f80 nvGpuOpsHasPendingNonReplayableFaults =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvGpuOpsHasPendingNonReplayableFaults(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  
  if ((param_2 != 0) && (*(long *)(param_1 + 0xb0) != 0)) {
    lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 0xb0) + 0x128) + 0xe0);
    cVar3 = gpuIsCCFeatureEnabled_IMPL(lVar2);
    if ((cVar3 == '\0') || (*(char *)(lVar2 + 0x4a78) == '\0')) {
      if (*(long *)(param_1 + 0x68) == 0) {
        return 0x1f;
      }
      cVar3 = circularQueueIsEmpty_IMPL();
      *(bool *)param_2 = cVar3 == '\0';
    }
    else {
      iVar1 = *(int *)(param_1 + 0x98);
      iVar4 = (**(code **)(*(long *)(lVar2 + 0x1b98) + 0x368))(lVar2,*(long *)(lVar2 + 0x1b98),0);
      *(bool *)param_2 = iVar1 != iVar4;
    }
    return 0;
  }
  return 0x1f;
}


// ===== 004b3050 nvGpuOpsGetNonReplayableFaults =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsGetNonReplayableFaults(long param_1,long param_2,int *param_3)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  long lVar10;
  uint uVar11;
  undefined1 local_58 [16];
  char local_48 [24];
  
  if (((param_2 == 0) || (param_3 == (int *)0x0)) || (*(long *)(param_1 + 0xb0) == 0)) {
    return 0x1f;
  }
  *param_3 = 0;
  lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 0xb0) + 0x128) + 0xe0);
  cVar7 = gpuIsCCFeatureEnabled_IMPL(lVar2);
  if ((cVar7 == '\0') || (*(char *)(lVar2 + 0x4a78) == '\0')) {
    lVar2 = *(long *)(param_1 + 0x68);
    if (lVar2 == 0) {
      return 0x1f;
    }
    uVar3 = *(undefined8 *)(param_1 + 0x70);
    while (cVar7 = circularQueuePopAndCopyNonManaged_IMPL(lVar2,uVar3,param_2), cVar7 != '\0') {
      *param_3 = *param_3 + 1;
      param_2 = param_2 + 0x20;
    }
  }
  else {
    lVar4 = *(long *)(lVar2 + 0x1b98);
    lVar5 = *(long *)(lVar2 + 0x1d18);
    lVar10 = kgmmuGetShadowFaultBufferCslContext_IMPL(lVar2,lVar4,0);
    if (lVar10 == 0) {
      nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x2637,"nvGpuOpsGetNonReplayableFaults",4,
                   "NVRM: Non Replayable buffer CSL context not allocated\n");
      return 0x40;
    }
    uVar11 = *(uint *)(param_1 + 0x98);
    uVar1 = *(uint *)(param_1 + 0x78);
    uVar8 = (**(code **)(lVar4 + 0x368))(lVar2,lVar4,0);
    if (uVar11 != uVar8) {
      do {
        lVar6 = *(long *)(param_1 + 0x68);
        lVar4 = *(long *)(param_1 + 0xa0);
        *param_3 = *param_3 + 1;
        lVar4 = lVar4 + (ulong)uVar11 * 0x20;
        portMemCopy(local_58,0x20,lVar4,0x20);
        if (local_48[0] != '\x01') {
          return 0x40;
        }
        LOCK();
        UNLOCK();
        iVar9 = ccslDecryptWithRotationChecks_KERNEL
                          (lVar10,0x20,lVar6 + ((ulong)uVar11 * 0x20 & 0xffffffff),0,local_48,1,
                           param_2);
        if (iVar9 != 0) {
          nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x2663,"nvGpuOpsGetNonReplayableFaults",4,
                       "NVRM: Fatal error detected in fault buffer packet decryption: 0x%x\n",iVar9)
          ;
          (**(code **)(lVar5 + 0x180))(lVar2);
          return iVar9;
        }
        param_2 = param_2 + 0x20;
        portMemSet(lVar4,0,0x20,local_58);
        uVar11 = (uVar11 + 1) % (uVar1 >> 5);
      } while (uVar11 != uVar8);
    }
    *(uint *)(param_1 + 0x98) = uVar8;
  }
  return 0;
}


// ===== 004b32e0 nvGpuOpsFlushReplayableFaultBuffer =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

undefined8 nvGpuOpsFlushReplayableFaultBuffer(long param_1,undefined1 param_2)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  if (*(long *)(param_1 + 0xb0) != 0) {
    lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0xb0) + 0x128) + 0xe0);
    lVar2 = *(long *)(lVar1 + 0x1b98);
    pcVar3 = *(code **)(lVar2 + 0x2c0);
    uVar4 = (*pcVar3)(lVar1,lVar2,param_2,pcVar3);
    return uVar4;
  }
  return 0x1f;
}


// ===== 004b3330 nvGpuOpsTogglePrefetchFaults =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

undefined8 nvGpuOpsTogglePrefetchFaults(long param_1,undefined1 param_2)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  if (*(long *)(param_1 + 0xb0) != 0) {
    lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0xb0) + 0x128) + 0xe0);
    lVar2 = *(long *)(lVar1 + 0x1b98);
    pcVar3 = *(code **)(lVar2 + 0x2c8);
    uVar4 = (*pcVar3)(lVar1,lVar2,param_2,pcVar3);
    return uVar4;
  }
  return 0x1f;
}


// ===== 004b3380 nvGpuOpsReleaseChannel =====

void nvGpuOpsReleaseChannel(long param_1)

{
  int iVar1;
  undefined1 local_c0 [24];
  undefined1 local_a8 [144];
  
  threadStateInit(local_a8,0);
  iVar1 = _nvGpuOpsLocksAcquireWithClientLockFlags(2,1,**(undefined4 **)(param_1 + 0x18),0,3,0);
  if (iVar1 == 0) {
    _nvGpuOpsReleaseChannel(param_1);
    _nvGpuOpsLocksRelease(local_c0);
  }
  threadStateFree(local_a8,0);
  return;
}


// ===== 004b3400 _memDescFindAndRetain =====

undefined8 _memDescFindAndRetain(long *param_1,long param_2,long *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  long *local_48 [4];
  
  uVar1 = mapFindLEQ_IMPL(*param_1 + 0x180,0xffffffffffffffff);
  uVar2 = mapFindGEQ_IMPL(*param_1 + 0x180,0);
  mapIterRange_IMPL(local_48,*param_1 + 0x180,uVar2,uVar1);
  do {
    uVar1 = mapIterNext_IMPL(local_48);
    if ((char)uVar1 == '\0') {
      return uVar1;
    }
  } while (*local_48[0] != param_2);
  lVar3 = mapKey_IMPL(*param_1 + 0x180);
  if (lVar3 == 0) {
    return 0;
  }
  if (*(char *)(lVar3 + 100) != '\0') {
    *(char *)(lVar3 + 100) = *(char *)(lVar3 + 100) + '\x01';
  }
  memdescAddRef(lVar3);
  *param_3 = lVar3;
  return 1;
}


// ===== 004b34d5 nvGpuOpsRetainChannel.cold =====

void nvGpuOpsRetainChannel_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004b3530 nvGpuOpsRetainChannel =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int nvGpuOpsRetainChannel
              (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined8 *param_4,
              undefined8 *param_5)

{
  ulong uVar1;
  long lVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  long *plVar10;
  long lVar11;
  undefined8 uVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  undefined8 *puVar16;
  long *plVar17;
  undefined4 *puVar18;
  ulong uVar19;
  undefined8 *puVar20;
  undefined4 *puVar21;
  undefined8 extraout_RDX;
  undefined4 *puVar22;
  long *plVar23;
  undefined4 uVar24;
  bool bVar25;
  undefined8 uVar26;
  uint local_170;
  long local_158;
  undefined4 local_13c;
  long local_138;
  long local_130;
  ulong local_128;
  long local_120;
  ulong local_118;
  ulong local_110;
  ulong local_108;
  undefined8 local_100;
  undefined1 local_f8 [24];
  undefined8 local_e0;
  undefined8 local_d8;
  undefined1 local_c8 [152];
  
  local_130 = 0;
  local_128 = 0;
  local_13c = 0;
  local_100 = 0;
  if ((param_1 == (undefined4 *)0x0) || (param_5 == (undefined8 *)0x0)) {
    return 0x1f;
  }
  threadStateInit(local_c8,0);
  iVar5 = _nvGpuOpsLocksAcquireWithClientLockFlags(2,1,param_2,&local_138,3,0,0,local_f8);
  if (iVar5 != 0) {
    threadStateFree(local_c8,0);
    return iVar5;
  }
  plVar23 = *(long **)(param_1 + 2);
  lVar11 = plVar23[1];
  local_110 = 0;
  iVar5 = serverGetClientUnderLock(g_resServ,*(undefined4 *)plVar23[9],&local_108);
  if ((iVar5 != 0) ||
     (iVar5 = vaspaceGetByHandleOrDeviceDefault_IMPL
                        (local_108,*(undefined4 *)(*(long *)(param_1 + 2) + 0x10),*param_1,
                         &local_110), iVar5 != 0)) goto LAB_004b365b;
  iVar5 = CliGetKernelChannel(local_138,param_3,&local_130);
  if (iVar5 != 0) {
    iVar5 = 0x33;
    goto LAB_004b365b;
  }
  lVar13 = *(long *)(*(long *)(local_130 + 0x158) + 0xe8);
  if (lVar13 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  iVar5 = CliSetGpuContext(*(undefined4 *)(local_138 + 0x48),
                           *(undefined4 *)(*(long *)(*(long *)(lVar13 + 0x110) + 0x48) + 0x10),
                           &local_128,0);
  if (iVar5 != 0) goto LAB_004b365b;
  lVar13 = *(long *)(param_1 + 2);
  if (*(ulong *)(local_130 + 0x2a0) != local_110) {
    iVar5 = 0x21;
    iVar6 = CliSetGpuContext(**(undefined4 **)(lVar13 + 0x48),*(undefined4 *)(lVar13 + 0x10),
                             &local_e0,0);
    if ((iVar6 == 0) && (iVar5 = 0x5a, local_128 == local_e0)) {
      iVar5 = 0x21;
    }
    goto LAB_004b365b;
  }
  iVar5 = subdeviceGetByHandle_IMPL(local_108,*(undefined4 *)(lVar13 + 0x14),&local_e0);
  if (iVar5 != 0) goto LAB_004b365b;
  local_128 = *(ulong *)(*(long *)(local_e0 + 0x158) + 0xe0);
  portMemSet(param_5,0,0x468);
  plVar10 = (long *)portMemAllocNonPaged(0xb8);
  if (plVar10 == (long *)0x0) {
    _nvGpuOpsLocksRelease(local_f8);
    threadStateFree(local_c8,0);
    return 0x51;
  }
  portMemSet(plVar10,0,0xb8);
  uVar19 = local_128;
  lVar13 = local_130;
  *plVar10 = (long)plVar23;
  plVar10[1] = *plVar23;
  plVar10[2] = lVar11;
  lVar11 = plVar23[9];
  plVar10[4] = local_128;
  plVar10[3] = lVar11;
  *(undefined4 *)((long)param_5 + 0xc) = *(undefined4 *)(local_130 + 0x2b0);
  uVar24 = *(undefined4 *)(local_130 + 0x2b4);
  *(undefined4 *)(param_5 + 2) = uVar24;
  *(undefined4 *)(plVar10 + 0x14) = uVar24;
  *(undefined4 *)((long)plVar10 + 0xa4) = *(undefined4 *)(local_130 + 0x2b0);
  lVar11 = gpuGetKernelFifoShared_IMPL(local_128);
  iVar5 = (**(code **)(lVar13 + 0x1e8))(uVar19,lVar13,&local_108);
  if ((iVar5 == 0) &&
     (iVar5 = (**(code **)(lVar11 + 0x218))(uVar19,lVar11,0,local_108 & 0xffffffff,2,&local_e0),
     iVar5 == 0)) {
    iVar5 = 1;
    if (7 < (uint)local_e0 - 1) {
      iVar5 = ((uint)local_e0 == 0x31) + 2;
    }
    *(int *)(plVar10 + 0x13) = iVar5;
    local_108 = 0;
    lVar11 = gpuGetKernelFifoShared_IMPL(plVar10[4]);
    uVar12 = kfifoGetChidMgr_IMPL(plVar10[4],lVar11,*(undefined4 *)((long)plVar10 + 0xa4));
    lVar13 = kfifoChidMgrGetKernelChannel_IMPL
                       (plVar10[4],lVar11,uVar12,*(undefined4 *)(param_5 + 2));
    if (lVar13 == 0) {
      nvCheckFailedNoLog(4,"pKernelChannel != NULL","src/kernel/rmapi/nv_gpu_ops.c",0x271a);
      iVar5 = 0x21;
    }
    else {
      iVar5 = (**(code **)(lVar11 + 0x1c0))
                        (plVar10[4],lVar11,lVar13,1,&local_108,*(code **)(lVar11 + 0x1c0));
      if (iVar5 == 0) {
        local_108 = memdescGetMemDescFromGpu(local_108,plVar10[4]);
        kfifoFillMemInfo_IMPL(lVar11,local_108,&local_e0);
        lVar11 = local_130;
        if ((uint)local_e0 == 0) {
          iVar5 = 0x33;
        }
        else {
          plVar10[5] = local_108;
          *(bool *)(param_5 + 1) = (uint)local_e0 != 1;
          *param_5 = local_d8;
          lVar13 = plVar10[4];
          lVar14 = gpuGetKernelFifoShared_IMPL(lVar13);
          lVar15 = rmapiGetInterface(4);
          if (lVar11 == 0) {
            nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/rmapi/nv_gpu_ops.c",0x273f);
LAB_004b42b8:
            iVar5 = 0x1f;
          }
          else {
            lVar2 = *(long *)(*(long *)(lVar11 + 0x2b8) + 0x138);
            if (lVar2 == 0) {
              nvAssertFailedNoLog("pKernelChannelGroup != NULL","src/kernel/rmapi/nv_gpu_ops.c",
                                  0x2741);
              iVar5 = 0x40;
            }
            else {
              cVar4 = rmGpuLockIsOwner();
              bVar25 = cVar4 != '\0';
              if (bVar25) {
                rmGpuLocksRelease(0,0);
              }
              local_e0 = (ulong)local_e0._4_4_ << 0x20;
              if (*(long *)(lVar11 + 0x2b8) == 0) {
                    /* WARNING: Does not return */
                pcVar3 = (code *)invalidInstructionException();
                (*pcVar3)();
              }
              iVar5 = (**(code **)(lVar15 + 0x50))
                                (lVar15,*(undefined4 *)plVar10[3],*(undefined4 *)(plVar10[1] + 0x40)
                                 ,&local_e0,
                                 *(undefined4 *)
                                  (**(long **)(*(long *)(lVar11 + 0x140) + 0x48) + 0x48),
                                 *(undefined4 *)
                                  (*(long *)(*(long *)(*(long *)(lVar11 + 0x2b8) + 0x110) + 0x48) +
                                  0x10));
              if (iVar5 == 0) {
                if ((bVar25) && (iVar5 = rmGpuLocksAcquire(0,0x400), iVar5 != 0)) {
                  (**(code **)(lVar15 + 0x18))
                            (lVar15,*(undefined4 *)plVar10[3],local_e0 & 0xffffffff);
                }
                else {
                  lVar13 = (**(code **)(lVar14 + 0x1f0))
                                     (lVar13,lVar14,lVar2,*(undefined1 *)(lVar2 + 0x159));
                  lVar11 = local_130;
                  *(undefined1 *)((long)param_5 + 0x1c) = 1;
                  param_5[4] = (ulong)*(uint *)(lVar2 + 0xf0) | lVar13 << 0x20;
                  *(uint *)((long)plVar10 + 0xac) = (uint)local_e0;
                  *(undefined8 *)((long)param_5 + 0x45c) = 0;
                  if (local_130 == 0) {
                    nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/rmapi/nv_gpu_ops.c",
                                        0x277e);
                    goto LAB_004b42b8;
                  }
                  if (*plVar23 == 0) {
                    nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x770);
                    lVar13 = plVar10[4];
                    if ((0x16f < *(uint *)(*plVar23 + 0x54)) && ((int)plVar10[0x13] == 1)) {
LAB_004b3ba2:
                      if ((lVar13 != 0) && (*(long *)(lVar13 + 0x1bc0) != 0)) {
                        cVar4 = kmigmgrIsMIGGpuInstancingEnabled_IMPL();
                        if (cVar4 != '\0') {
                          uVar7 = *(int *)(lVar11 + 0x42c) - 1;
                          lVar11 = gpuGetKernelFifoShared_IMPL();
                          iVar5 = (**(code **)(lVar11 + 0x218))
                                            (lVar13,lVar11,0,uVar7 | 0xd334df00,4,&local_e0);
                          if (iVar5 != 0) {
                            nvAssertOkFailedNoLog
                                      (iVar5,
                                       "kfifoEngineInfoXlate_HAL(pGpu, GPU_GET_KERNEL_FIFO(pGpu), ENGINE_INFO_TYPE_ENG_DESC, ENG_GR(grIdx), ENGINE_INFO_TYPE_MMU_FAULT_ID, &grFaultId)"
                                       ,"src/kernel/rmapi/nv_gpu_ops.c",0x278b);
                            goto LAB_004b3ac0;
                          }
                          uVar9 = (**(code **)(*(long *)(lVar13 + 0x1b98) + 0x348))();
                          if ((uint)local_e0 < uVar9) {
                            nvAssertFailedNoLog("grFaultId >= grMmuFaultEngId",
                                                "src/kernel/rmapi/nv_gpu_ops.c",0x2793);
                          }
                          *(uint *)((long)param_5 + 0x45c) = uVar7;
                          *(uint *)(param_5 + 0x8c) = (uint)local_e0 - uVar9;
                        }
                        lVar13 = plVar10[4];
                      }
                    }
                    lVar11 = local_130;
                    lVar13 = gpuGetKernelFifoShared_IMPL(lVar13);
                    local_e0 = local_e0 & 0xffffffff00000000;
                    if (lVar11 != 0) goto LAB_004b41d6;
                    nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/rmapi/nv_gpu_ops.c",
                                        0x27a8);
                  }
                  else {
                    if (*(uint *)(*plVar23 + 0x54) < 0x170) {
                      lVar13 = gpuGetKernelFifoShared_IMPL(plVar10[4]);
                      local_e0 = local_e0 & 0xffffffff00000000;
                    }
                    else {
                      lVar13 = plVar10[4];
                      if ((int)plVar10[0x13] == 1) goto LAB_004b3ba2;
                      lVar13 = gpuGetKernelFifoShared_IMPL();
                      local_e0 = local_e0 & 0xffffffff00000000;
                    }
LAB_004b41d6:
                    lVar14 = rmapiGetInterface(4);
                    if ((((*(char *)(lVar13 + 0x4b3) == '\0') || (*(long *)(lVar11 + 0x2c8) == 0))
                        || ((int)plVar10[0x13] != 1)) ||
                       ((*(int *)((long)plVar10 + 0xac) == 0 ||
                        (lVar13 = *(long *)(*(long *)(lVar11 + 0x2b8) + 0x138),
                        *(char *)(lVar13 + 0x159) != '\0')))) {
                      *(undefined4 *)(param_5 + 3) = 0;
                      *(undefined1 *)((long)param_5 + 0x14) = 0;
                    }
                    else {
                      iVar5 = (**(code **)(lVar14 + 0x50))
                                        (lVar14,*(undefined4 *)plVar10[3],
                                         *(int *)((long)plVar10 + 0xac),&local_e0,
                                         *(undefined4 *)
                                          (**(long **)(*(long *)(lVar11 + 0x140) + 0x48) + 0x48),
                                         *(undefined4 *)
                                          (*(long *)(*(long *)(*(long *)(lVar11 + 0x2c8) + 0x110) +
                                                    0x48) + 0x10),1,lVar13);
                      if (iVar5 != 0) {
                        nvAssertFailedNoLog("status == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0x27c3
                                           );
                      }
                      *(uint *)(plVar10 + 0x16) = (uint)local_e0;
                      uVar7 = *(uint *)(*(long *)(*(long *)(lVar11 + 0x2c8) + 0x138) + 0xa8);
                      *(undefined1 *)((long)param_5 + 0x14) = 1;
                      *(uint *)(param_5 + 3) = uVar7;
                      if (*(uint *)((long)param_5 + 0x24) <= uVar7) {
                        nvAssertFailedNoLog("channelInstanceInfo->subctxId < channelInstanceInfo->tsgMaxSubctxCount"
                                            ,"src/kernel/rmapi/nv_gpu_ops.c",0x27d3);
                      }
                    }
                  }
                  puVar16 = (undefined8 *)rmapiGetInterface(4);
                  if (*(char *)((long)param_5 + 0x1c) == '\0') {
                    uVar24 = *(undefined4 *)(plVar10[1] + 0x40);
                  }
                  else {
                    uVar24 = *(undefined4 *)((long)plVar10 + 0xac);
                  }
                  local_100 = CONCAT44(param_3,param_2);
                  nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x2862,"nvGpuOpsRetainChannel",1,
                               "NVRM: %s:Channel duping is not supported. Fall back to UVM_CHANNEL_RETAINER\n"
                              );
                  iVar5 = (*(code *)*puVar16)(puVar16,*(undefined4 *)plVar23[9],uVar24,
                                              (long)plVar10 + 0xb4,0xc574,&local_100,8);
                  if (iVar5 == 0) {
                    iVar5 = (*(code *)puVar16[7])(puVar16,param_2,param_3,0xc36f0108,&local_13c,4);
                    if (iVar5 == 0) {
                      *(undefined4 *)(param_5 + 0x8b) = local_13c;
                      *(undefined4 *)(param_5 + 0x88) = local_13c;
                      lVar11 = *plVar23;
                      if (lVar11 == 0) {
                        nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",0x770
                                           );
                        lVar11 = *plVar23;
                      }
                      if (0x16f < *(uint *)(lVar11 + 0x54)) {
                        plVar17 = (long *)gpuGetDeviceMapping_IMPL(local_128,0,0);
                        if (plVar17 == (long *)0x0) {
                          nvAssertFailedNoLog("pMapping","src/kernel/rmapi/nv_gpu_ops.c",0x33d);
                        }
                        lVar11 = *plVar17;
                        uVar24 = *(undefined4 *)(local_130 + 0x2b0);
                        lVar13 = gpuGetKernelFifoShared_IMPL(local_128);
                        iVar6 = (**(code **)(lVar13 + 0x218))
                                          (local_128,lVar13,3,uVar24,0xe,&local_108);
                        if (iVar6 != 0) {
                          nvAssertOkFailedNoLog
                                    (iVar6,
                                     "kfifoEngineInfoXlate_HAL(pGpu, GPU_GET_KERNEL_FIFO(pGpu), ENGINE_INFO_TYPE_RUNLIST, kchannelGetRunlistId(pKernelChannel), ENGINE_INFO_TYPE_CHRAM_PRI_BASE, &chramPri)"
                                     ,"src/kernel/rmapi/nv_gpu_ops.c",0x288e);
                          iVar5 = iVar6;
                          goto LAB_004b3ac0;
                        }
                        uVar7 = (int)local_108 + *(int *)(local_130 + 0x2b4) * 4;
                        local_108 = CONCAT44(local_108._4_4_,uVar7);
                        param_5[0x89] = (ulong)uVar7 + lVar11;
                        lVar13 = *plVar23;
                        if (lVar13 == 0) {
                          nvAssertFailedNoLog("device->rmDevice","src/kernel/rmapi/nv_gpu_ops.c",
                                              0x777);
                          lVar13 = *plVar23;
                        }
                        if ((*(uint *)(lVar13 + 0x54) < 0x180) || (*(uint *)(lVar13 + 0x54) == 400))
                        {
                          uVar24 = *(undefined4 *)(local_130 + 0x2b0);
                          lVar13 = gpuGetKernelFifoShared_IMPL();
                          iVar6 = (**(code **)(lVar13 + 0x218))
                                            (local_128,lVar13,3,uVar24,0xb,&local_e0);
                          if (iVar6 != 0) {
                            nvAssertOkFailedNoLog
                                      (iVar6,
                                       "kfifoEngineInfoXlate_HAL(pGpu, GPU_GET_KERNEL_FIFO(pGpu), ENGINE_INFO_TYPE_RUNLIST, kchannelGetRunlistId(pKernelChannel), ENGINE_INFO_TYPE_RUNLIST_PRI_BASE, &runlistPri)"
                                       ,"src/kernel/rmapi/nv_gpu_ops.c",0x28a3);
                            iVar5 = iVar6;
                            goto LAB_004b3ac0;
                          }
                          param_5[0x8a] = lVar11 + 0x90 + (local_e0 & 0xffffffff);
                          *(uint *)(param_5 + 0x8b) = *(uint *)(plVar10 + 0x14) & 0xfff;
                        }
                        else {
                          param_5[0x8a] = (ulong)(*(int *)(local_128 + 0x3a64) + 0x30090) + lVar11;
                        }
                      }
                      iVar6 = (int)plVar10[0x13];
                      if (iVar6 - 1U < 3) {
                        if (iVar6 == 2) {
                          portMemFree(0);
                          portMemFree(0);
                        }
                        else {
                          iVar8 = nvGpuOpsGetChannelData(plVar10,&local_120);
                          if (iVar8 != 0) goto LAB_004b45a6;
                          if (iVar6 != 3) goto LAB_004b3e2b;
                          local_110 = 0;
                          puVar18 = (undefined4 *)portMemAllocNonPaged(0x50);
                          if (puVar18 == (undefined4 *)0x0) goto LAB_004b4b83;
                          if (local_120 == 0) {
                    /* WARNING: Does not return */
                            pcVar3 = (code *)invalidInstructionException();
                            (*pcVar3)();
                          }
                          *puVar18 = *(undefined4 *)
                                      (**(long **)(*(long *)(local_120 + 0x140) + 0x48) + 0x48);
                          if (local_120 == 0) {
                    /* WARNING: Does not return */
                            pcVar3 = (code *)invalidInstructionException();
                            (*pcVar3)();
                          }
                          puVar18[1] = *(undefined4 *)
                                        (*(long *)(*(long *)(local_120 + 0x140) + 0x48) + 0x10);
                          lVar11 = rmapiGetInterface(4);
                          iVar8 = (**(code **)(lVar11 + 0x38))
                                            (lVar11,*(undefined4 *)plVar10[3],
                                             *(undefined4 *)(plVar10[2] + 0x38),0x20803124,puVar18,
                                             0x50);
                          if (iVar8 != 0) {
                            portMemFree(0);
                            portMemFree(puVar18);
                            goto LAB_004b45b7;
                          }
                          param_5[5] = *(undefined8 *)(puVar18 + 6);
                          param_5[7] = *(undefined8 *)(puVar18 + 2);
                          param_5[9] = (ulong)(uint)puVar18[0xe];
                          param_5[0xc] = *(undefined8 *)(puVar18 + 4);
                          *(undefined1 *)(param_5 + 10) = *(undefined1 *)(puVar18 + 0xf);
                          param_5[0xb] = *(undefined8 *)(puVar18 + 10);
                          *(undefined4 *)(param_5 + 8) = puVar18[0xd];
                          *(bool *)((long)param_5 + 0x44) = puVar18[0xc] == 1;
                          *(undefined1 *)((long)param_5 + 0x46) =
                               *(undefined1 *)((long)puVar18 + 0x3d);
                          iVar6 = fillMIGGiUUID(param_5 + 8,
                                                *(undefined8 *)(*(long *)(local_120 + 0x158) + 0xe8)
                                               );
                          if (iVar6 != 0) {
                            portMemCopy(param_5 + 0xd,0x10,(long)puVar18 + 0x3e,0x10);
                          }
                          local_108 = 0;
                          local_e0 = *(ulong *)(puVar18 + 6);
                          if (*(char *)(puVar18 + 0xf) == '\0') {
                            iVar8 = 0x40;
                            nvAssertFailedNoLog("pCtxBufferInfo->bIsContigous",
                                                "src/kernel/rmapi/nv_gpu_ops.c",0x293c);
LAB_004b4cb2:
                            portMemFree(0);
                            portMemFree(puVar18);
                            goto LAB_004b45b7;
                          }
                          cVar4 = _memDescFindAndRetain(plVar10,local_e0,&local_110);
                          if (cVar4 == '\0') {
                            uVar12 = 0;
                            iVar8 = memdescCreate(&local_108,plVar10[4],*(undefined8 *)(puVar18 + 4)
                                                  ,*(undefined8 *)(puVar18 + 2),
                                                  *(undefined1 *)(puVar18 + 0xf),puVar18[0xc],0,0);
                            if (iVar8 != 0) {
                              nvCheckOkFailedNoLog
                                        (4,iVar8,"status","src/kernel/rmapi/nv_gpu_ops.c",0x294a,
                                         uVar12);
                              goto LAB_004b4cb2;
                            }
                            memdescSetPageSize(local_108,0,puVar18[0xe]);
                            memdescDescribe(local_108,puVar18[0xc],*(undefined8 *)(puVar18 + 10),
                                            *(undefined8 *)(puVar18 + 4));
                            mapInsertValue_IMPL(*plVar10 + 0x180,local_108,&local_e0);
                            local_110 = local_108;
                          }
                          param_5[5] = local_110;
                          plVar10[6] = local_110;
                          *(undefined4 *)(param_5 + 0x87) = 1;
                          *(undefined4 *)((long)plVar10 + 0x9c) = 1;
                          portMemFree(0);
                          portMemFree(puVar18);
                        }
LAB_004b435f:
                        *(int *)((long)param_5 + 0x43c) = (int)plVar10[0x13];
                        *param_4 = plVar10;
                        goto LAB_004b365b;
                      }
                      nvAssertFailedNoLog("channelEngineType == UVM_GPU_CHANNEL_ENGINE_TYPE_CE || channelEngineType == UVM_GPU_CHANNEL_ENGINE_TYPE_GR || channelEngineType == UVM_GPU_CHANNEL_ENGINE_TYPE_SEC2"
                                          ,"src/kernel/rmapi/nv_gpu_ops.c",0x29da);
                      iVar8 = nvGpuOpsGetChannelData(plVar10,&local_120);
                      if (iVar8 == 0) {
LAB_004b3e2b:
                        puVar18 = (undefined4 *)portMemAllocNonPaged(0x1410);
                        if (puVar18 == (undefined4 *)0x0) {
LAB_004b4b83:
                          iVar8 = 0x51;
                          portMemFree(0);
                          portMemFree(0);
                        }
                        else {
                          if (local_120 == 0) {
                    /* WARNING: Does not return */
                            pcVar3 = (code *)invalidInstructionException();
                            (*pcVar3)();
                          }
                          *puVar18 = *(undefined4 *)
                                      (**(long **)(*(long *)(local_120 + 0x140) + 0x48) + 0x48);
                          if (local_120 == 0) {
                    /* WARNING: Does not return */
                            pcVar3 = (code *)invalidInstructionException();
                            (*pcVar3)();
                          }
                          puVar18[1] = *(undefined4 *)
                                        (*(long *)(*(long *)(local_120 + 0x140) + 0x48) + 0x10);
                          lVar11 = rmapiGetInterface(4);
                          iVar8 = (**(code **)(lVar11 + 0x38))
                                            (lVar11,*(undefined4 *)plVar10[3],
                                             *(undefined4 *)(plVar10[2] + 0x38),0x20801219,puVar18,
                                             0x1410);
                          if (iVar8 == 0) {
                            if (0xd < (uint)puVar18[2]) {
                              nvAssertFailedNoLog("pParams->bufferCount <= NV_ARRAY_ELEMENTS(channelInstanceInfo->resourceInfo)"
                                                  ,"src/kernel/rmapi/nv_gpu_ops.c",0x2a3b);
                            }
                            uVar7 = 0;
                            if (puVar18[2] != 0) {
                              puVar22 = puVar18 + 0x13;
                              local_158 = 0;
                              puVar16 = param_5 + 8;
                              do {
                                local_118 = 0;
                                puVar16[-3] = *(undefined8 *)(puVar22 + -0xb);
                                *(undefined4 *)(puVar16 + -2) = puVar22[-5];
                                puVar16[-1] = *(undefined8 *)(puVar22 + -0xf);
                                puVar16[1] = (ulong)(uint)puVar22[-2];
                                puVar16[4] = *(undefined8 *)(puVar22 + -0xd);
                                *(undefined1 *)(puVar16 + 2) = *(undefined1 *)(puVar22 + -1);
                                puVar16[3] = *(undefined8 *)(puVar22 + -7);
                                *(undefined4 *)puVar16 = puVar22[-3];
                                *(bool *)((long)puVar16 + 4) = puVar22[-4] == 1;
                                *(undefined1 *)((long)puVar16 + 6) =
                                     *(undefined1 *)((long)puVar22 + -1);
                                iVar6 = fillMIGGiUUID(puVar16,*(undefined8 *)
                                                               (*(long *)(local_120 + 0x158) + 0xe8)
                                                     );
                                if (iVar6 != 0) {
                                  portMemCopy(puVar16 + 5,0x10,puVar22,0x10);
                                }
                                uVar19 = (ulong)(uint)puVar22[-2];
                                lVar11 = *(long *)(puVar22 + -0xd);
                                local_110 = 0;
                                local_108 = *(ulong *)(puVar22 + -0xb);
                                cVar4 = _memDescFindAndRetain(plVar10,local_108,&local_118);
                                if (cVar4 == '\0') {
                                  uVar1 = (uVar19 - 1) + lVar11;
                                  uVar19 = (uVar1 - uVar1 % uVar19) / uVar19;
                                  puVar20 = (undefined8 *)
                                            portMemAllocNonPaged((uVar19 & 0xffffffff) << 3);
                                  if (puVar20 == (undefined8 *)0x0) {
                                    portMemFree(0);
                                    portMemFree(0);
LAB_004b4999:
                                    iVar8 = 0x51;
                                  }
                                  else {
                                    iVar8 = nvGpuOpsGetChannelData(plVar10,&local_e0);
                                    if (iVar8 == 0) {
                                      puVar21 = (undefined4 *)portMemAllocNonPaged(0x420);
                                      if (puVar21 == (undefined4 *)0x0) {
                                        portMemFree(0);
                                        portMemFree(puVar20);
                                        goto LAB_004b4999;
                                      }
                                      local_170 = (uint)uVar19;
                                      portMemSet(puVar21,0,0x420);
                                      if (local_e0 == 0) {
                    /* WARNING: Does not return */
                                        pcVar3 = (code *)invalidInstructionException();
                                        (*pcVar3)();
                                      }
                                      *puVar21 = *(undefined4 *)
                                                  (**(long **)(*(long *)(local_e0 + 0x140) + 0x48) +
                                                  0x48);
                                      if (local_e0 == 0) {
                    /* WARNING: Does not return */
                                        pcVar3 = (code *)invalidInstructionException();
                                        (*pcVar3)();
                                      }
                                      puVar21[1] = *(undefined4 *)
                                                    (*(long *)(*(long *)(local_e0 + 0x140) + 0x48) +
                                                    0x10);
                                      puVar21[2] = puVar22[-5];
                                      lVar11 = rmapiGetInterface(4);
                                      if (local_170 != 0) {
                                        uVar7 = 0;
                                        do {
                                          puVar21[3] = uVar7;
                                          iVar8 = (**(code **)(lVar11 + 0x38))
                                                            (lVar11,*(undefined4 *)plVar10[3],
                                                             *(undefined4 *)(plVar10[2] + 0x38),
                                                             0x20800a28,puVar21,0x420);
                                          if (iVar8 != 0) {
                                            portMemFree(puVar21);
                                            portMemFree(puVar20);
                                            goto LAB_004b4460;
                                          }
                                          if (local_170 < puVar21[4] + uVar7) {
                                            nvAssertFailedNoLog(
                                                  "j + pParams->numPages <= numBufferPages",
                                                  "src/kernel/rmapi/nv_gpu_ops.c",0x2996);
                                          }
                                          if (*(char *)(puVar22 + -1) != '\0') {
                                            *puVar20 = *(undefined8 *)(puVar21 + 6);
                                            break;
                                          }
                                          portMemCopy(puVar20 + uVar7,(ulong)(uint)puVar21[4] << 3,
                                                      puVar21 + 6,(ulong)(uint)puVar21[4] << 3);
                                          uVar7 = uVar7 + puVar21[4];
                                        } while (uVar7 < local_170);
                                      }
                                      if (*(char *)(puVar21 + 0x106) == '\0') {
                                        nvAssertFailedNoLog("pParams->bNoMorePages",
                                                            "src/kernel/rmapi/nv_gpu_ops.c",0x29a3);
                                      }
                                      uVar26 = 0;
                                      uVar12 = 0;
                                      iVar8 = memdescCreate(&local_110,plVar10[4],
                                                            *(undefined8 *)(puVar22 + -0xd),
                                                            *(undefined8 *)(puVar22 + -0xf),
                                                            *(undefined1 *)(puVar22 + -1),
                                                            puVar22[-4],0,0);
                                      if (iVar8 == 0) {
                                        memdescSetPageSize(local_110,0,puVar22[-2]);
                                        if (*(char *)(puVar22 + -1) == '\0') {
                                          memdescFillPages(local_110,0,puVar20,local_170,puVar22[-2]
                                                          );
                                        }
                                        else {
                                          memdescDescribe(local_110,puVar22[-4],*puVar20,
                                                          *(undefined8 *)(puVar22 + -0xd));
                                        }
                                        mapInsertValue_IMPL(*plVar10 + 0x180,local_110,&local_108);
                                        local_118 = local_110;
                                        portMemFree(puVar21);
                                        portMemFree(puVar20);
                                        goto LAB_004b42f4;
                                      }
                                      portMemFree(puVar21,uVar26,extraout_RDX,uVar12);
                                      portMemFree(puVar20);
                                    }
                                    else {
                                      portMemFree(0);
                                      portMemFree(puVar20);
                                    }
                                  }
LAB_004b4460:
                                  if ((int)local_158 != 0) {
                                    plVar23 = plVar10;
                                    do {
                                      lVar11 = plVar23[6];
                                      if (*(int *)(lVar11 + 0x90) == 1) {
                                        mapRemoveByKey_IMPL(*plVar10 + 0x180,lVar11);
                                      }
                                      plVar23 = plVar23 + 1;
                                      memdescDestroy(lVar11);
                                    } while (plVar10 + local_158 != plVar23);
                                  }
                                  portMemFree(puVar18);
                                  portMemFree(0);
                                  goto LAB_004b45b7;
                                }
                                portMemFree(0);
                                portMemFree(0);
LAB_004b42f4:
                                puVar22 = puVar22 + 0x14;
                                puVar16[-3] = local_118;
                                plVar10[local_158 + 6] = local_118;
                                local_158 = local_158 + 1;
                                uVar7 = puVar18[2];
                                puVar16 = puVar16 + 10;
                              } while ((uint)local_158 < uVar7);
                            }
                            *(uint *)(param_5 + 0x87) = uVar7;
                            *(uint *)((long)plVar10 + 0x9c) = uVar7;
                            portMemFree(puVar18);
                            portMemFree(0);
                            goto LAB_004b435f;
                          }
                          portMemFree(puVar18);
                          portMemFree(0);
                        }
                      }
                      else {
LAB_004b45a6:
                        portMemFree(0);
                        portMemFree(0);
                      }
LAB_004b45b7:
                      nvstatusToString(iVar8);
                      nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x28bc,"nvGpuOpsRetainChannel",4,
                                   "NVRM: %s:%d: %s\n","nvGpuOpsRetainChannel",0x28bc);
                      iVar5 = iVar8;
                    }
                    else {
                      uVar12 = nvstatusToString(iVar5);
                      nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x2879,"nvGpuOpsRetainChannel",4,
                                   "NVRM: %s:%d: %s\n","nvGpuOpsRetainChannel",0x2879,uVar12);
                    }
                  }
                }
              }
              else if ((bVar25) && (iVar6 = rmGpuLocksAcquire(0,0x400), iVar6 != 0)) {
                nvAssertOkFailedNoLog
                          (iVar6,"rmGpuLocksAcquire(GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_GPU_OPS)",
                           "src/kernel/rmapi/nv_gpu_ops.c",0x2759);
                iVar5 = iVar6;
              }
            }
          }
        }
      }
    }
  }
LAB_004b3ac0:
  _nvGpuOpsReleaseChannel(plVar10);
LAB_004b365b:
  _nvGpuOpsLocksRelease(local_f8);
  threadStateFree(local_c8,0);
  return iVar5;
}


// ===== 004b4cf0 nvGpuOpsGetChannelResourcePtes =====

int nvGpuOpsGetChannelResourcePtes
              (undefined4 *param_1,long *param_2,undefined8 param_3,undefined8 param_4,long param_5)

{
  long lVar1;
  int iVar2;
  undefined8 extraout_RDX;
  undefined8 uVar3;
  undefined1 *puVar4;
  undefined8 local_f8;
  undefined8 local_f0;
  long local_e8;
  undefined1 local_e0 [24];
  undefined1 local_c8 [152];
  
  local_f8 = 0;
  if ((param_2 == (long *)0x0 || param_5 == 0) || (param_1 == (undefined4 *)0x0)) {
    return 0x1f;
  }
  if (*(long *)(param_5 + 0x20) != 0) {
    return 0x56;
  }
  threadStateInit(local_c8,0);
  puVar4 = local_e0;
  uVar3 = 0;
  iVar2 = _nvGpuOpsLocksAcquireWithClientLockFlags
                    (2,1,**(undefined4 **)(*(long *)(param_1 + 2) + 0x48),&local_f0,3,0);
  if (iVar2 == 0) {
    iVar2 = subdeviceGetByHandle_IMPL
                      (local_f0,*(undefined4 *)(*(long *)(param_1 + 2) + 0x14),&local_e8,puVar4);
    if (iVar2 == 0) {
      lVar1 = *(long *)(*(long *)(local_e8 + 0x158) + 0xe0);
      if ((*param_2 != lVar1) ||
         ((iVar2 = memdescGetAddressSpace(param_2), iVar2 != 1 &&
          (iVar2 = memdescGetAddressSpace(param_2), iVar2 != 2)))) {
        _nvGpuOpsLocksRelease(local_e0);
        threadStateFree(local_c8,0);
        return 0x56;
      }
      iVar2 = vaspaceGetByHandleOrDeviceDefault_IMPL
                        (local_f0,*(undefined4 *)(*(long *)(param_1 + 2) + 0x10),*param_1,&local_f8)
      ;
      if (iVar2 == 0) {
        iVar2 = nvGpuOpsBuildExternalAllocPtes
                          (local_f8,*(undefined8 *)(*(long *)(param_1 + 2) + 0x48),lVar1,param_2,0,
                           param_3,param_4,0,0,0,0,param_5);
      }
    }
    _nvGpuOpsLocksRelease(local_e0);
    uVar3 = extraout_RDX;
  }
  threadStateFree(local_c8,0,uVar3);
  return iVar2;
}


// ===== 004b4f0b nvGpuOpsBindChannelResources.cold =====

void nvGpuOpsBindChannelResources_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004b4f40 nvGpuOpsBindChannelResources =====

/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsBindChannelResources(long param_1,undefined4 *param_2)

{
  undefined8 *puVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  long lVar7;
  undefined4 *puVar8;
  long lVar9;
  ulong uVar10;
  undefined8 extraout_RDX;
  undefined8 uVar11;
  int local_ec;
  long local_e8;
  undefined1 local_e0 [24];
  undefined1 local_c8 [152];
  
  local_e8 = 0;
  lVar7 = rmapiGetInterface(4);
  threadStateInit(local_c8,0);
  uVar11 = 0;
  iVar3 = _nvGpuOpsLocksAcquireWithClientLockFlags
                    (2,1,**(undefined4 **)(param_1 + 0x18),0,3,0,0,local_e0);
  if (iVar3 != 0) {
    threadStateFree(local_c8,0,extraout_RDX,uVar11);
    return iVar3;
  }
  iVar4 = nvGpuOpsGetChannelData(param_1,&local_e8);
  iVar3 = iVar4;
  if (iVar4 != 0) goto LAB_004b4fe5;
  if (*(int *)(param_1 + 0x9c) != 0) {
    puVar8 = (undefined4 *)portMemAllocNonPaged(0x230);
    if (puVar8 == (undefined4 *)0x0) {
      _nvGpuOpsLocksRelease(local_e0);
      threadStateFree(local_c8,0);
      return 0x1a;
    }
    portMemSet(puVar8,0,0x230);
    if (local_e8 == 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    puVar8[3] = *(undefined4 *)(**(long **)(*(long *)(local_e8 + 0x140) + 0x48) + 0x48);
    puVar8[4] = *(undefined4 *)(*(long *)(*(long *)(local_e8 + 0x140) + 0x48) + 0x10);
    puVar8[10] = *(undefined4 *)(param_1 + 0x9c);
    uVar5 = *(undefined4 *)(param_1 + 0xa4);
    lVar9 = gpuGetKernelFifoShared_IMPL(*(undefined8 *)(param_1 + 0x20));
    (**(code **)(lVar9 + 0x218))(*(undefined8 *)(param_1 + 0x20),lVar9,3,uVar5,2,&local_ec);
    uVar5 = gpuGetNv2080EngineType_IMPL(local_ec);
    *puVar8 = uVar5;
    if (*(int *)(param_1 + 0x9c) != 0) {
      uVar6 = 0;
      do {
        if (local_ec - 1U < 8) goto LAB_004b5180;
        puVar1 = (undefined8 *)(param_2 + 2);
        uVar10 = (ulong)uVar6;
        param_2 = param_2 + 4;
        uVar6 = uVar6 + 1;
        *(undefined8 *)(puVar8 + uVar10 * 8 + 0xe) = *puVar1;
      } while (uVar6 < *(uint *)(param_1 + 0x9c));
    }
    goto LAB_004b51af;
  }
LAB_004b4fd7:
  *(undefined1 *)(local_e8 + 0x2d6) = 1;
  iVar3 = iVar4;
LAB_004b4fe5:
  _nvGpuOpsLocksRelease(local_e0);
  threadStateFree(local_c8,0);
  return iVar3;
LAB_004b5180:
  do {
    uVar10 = (ulong)uVar6;
    uVar6 = uVar6 + 1;
    *(short *)(puVar8 + uVar10 * 8 + 0x13) = (short)*param_2;
    *(undefined8 *)(puVar8 + uVar10 * 8 + 0xe) = *(undefined8 *)(param_2 + 2);
    param_2 = param_2 + 4;
  } while (uVar6 < *(uint *)(param_1 + 0x9c));
LAB_004b51af:
  iVar3 = (**(code **)(lVar7 + 0x38))
                    (lVar7,**(undefined4 **)(param_1 + 0x18),
                     *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x38),0x2080012b,puVar8,0x230);
  portMemFree(puVar8);
  if (iVar3 != 0) goto LAB_004b4fe5;
  goto LAB_004b4fd7;
}


// ===== 004b5220 nvGpuOpsStopChannel.cold =====

void nvGpuOpsStopChannel_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004b5240 nvGpuOpsStopChannel =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvGpuOpsStopChannel(long param_1,undefined1 param_2)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined1 local_f9;
  long local_f8;
  undefined1 local_f0 [12];
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined1 local_d0 [24];
  undefined1 local_b8 [144];
  
  local_f8 = 0;
  lVar4 = rmapiGetInterface(4);
  local_f9 = 0;
  threadStateInit(local_b8,0);
  iVar3 = _nvGpuOpsLocksAcquireWithClientLockFlags(2,1,**(undefined4 **)(param_1 + 0x18),0,3,0);
  if (iVar3 == 0) {
    iVar3 = nvGpuOpsGetChannelData(param_1,&local_f8,0,local_d0);
    if (iVar3 == 0) {
      if (local_f8 == 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      plVar1 = *(long **)(*(long *)(local_f8 + 0x140) + 0x48);
      iVar3 = serverutilGetResourceRef(*(undefined4 *)(*plVar1 + 0x48),(int)plVar1[2],local_f0);
      if (iVar3 != 0) {
        nvAssertFailedNoLog(&DAT_00d939aa,"src/kernel/rmapi/nv_gpu_ops.c",0x2b4e);
        _nvGpuOpsLocksRelease(local_d0);
        goto LAB_004b537d;
      }
      local_f9 = param_2;
      if (local_f8 == 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      plVar1 = *(long **)(*(long *)(local_f8 + 0x140) + 0x48);
      iVar3 = (**(code **)(lVar4 + 0x38))
                        (lVar4,*(undefined4 *)(*plVar1 + 0x48),(int)plVar1[2],0xa06f0112,&local_f9,1
                        );
      if (iVar3 != 0) {
        nvAssertOkFailedNoLog
                  (iVar3,
                   "pRmApi->Control(pRmApi, RES_GET_CLIENT_HANDLE(pKernelChannel), RES_GET_HANDLE(pKernelChannel), NVA06F_CTRL_CMD_STOP_CHANNEL, &stopChannelParams, sizeof(stopChannelParams))"
                   ,"src/kernel/rmapi/nv_gpu_ops.c",0x2b55);
      }
      *(undefined1 *)(local_f8 + 0x2d6) = 0;
      if (*(int *)(param_1 + 0x98) == 1) {
        portMemSet(&local_e4,0,0x14);
        local_e4 = 1;
        local_e0 = **(undefined4 **)(param_1 + 0x18);
        if (local_f8 == 0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        plVar1 = *(long **)(*(long *)(local_f8 + 0x140) + 0x48);
        local_d4 = (undefined4)plVar1[2];
        local_d8 = *(undefined4 *)(*plVar1 + 0x48);
        iVar3 = (**(code **)(lVar4 + 0x38))
                          (lVar4,**(undefined4 **)(param_1 + 0x18),
                           *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x38),0x2080012c,&local_e4,
                           0x14);
        if (iVar3 != 0) {
          nvAssertOkFailedNoLog
                    (iVar3,
                     "pRmApi->Control(pRmApi, retainedChannel->session->handle, retainedChannel->rmSubDevice->subDeviceHandle, NV2080_CTRL_CMD_GPU_EVICT_CTX, &params, sizeof(params))"
                     ,"src/kernel/rmapi/nv_gpu_ops.c",0x2b69);
        }
      }
    }
    _nvGpuOpsLocksRelease(local_d0);
  }
LAB_004b537d:
  threadStateFree(local_b8,0);
  return;
}


// ===== 004b54a0 nvGpuOpsGetPmaObject =====

int nvGpuOpsGetPmaObject(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined4 *puVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  long local_100;
  long local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined1 local_e0 [24];
  undefined1 local_c8 [152];
  
  puVar1 = *(undefined4 **)(param_1 + 0x48);
  local_100 = 0;
  local_f8 = 0;
  threadStateInit(local_c8,0);
  uVar7 = 0;
  iVar4 = _nvGpuOpsLocksAcquireWithClientLockFlags(2,1,*puVar1,0,3,0,0,local_e0);
  if (iVar4 != 0) {
    threadStateFree(local_c8,0,uVar7);
    return iVar4;
  }
  iVar4 = CliSetGpuContext(*puVar1,*(undefined4 *)(param_1 + 0x10),&local_100,0);
  if (iVar4 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar4,"CliSetGpuContext(session->handle, device->handle, &pGpu, NULL)",
               "src/kernel/rmapi/nv_gpu_ops.c",0x2baa);
    goto LAB_004b55d1;
  }
  lVar2 = *(long *)(local_100 + 0x1b78);
  if (lVar2 == 0) {
    nvCheckFailedNoLog(4,"pMemoryManager != NULL","src/kernel/rmapi/nv_gpu_ops.c",0x2baf);
  }
  else {
    lVar6 = lVar2;
    if (*(long *)(local_100 + 0x1bc0) == 0) {
LAB_004b5593:
      local_f8 = *(long *)(lVar6 + 0x478);
    }
    else {
      cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL();
      if (cVar3 == '\0') {
        lVar6 = *(long *)(local_100 + 0x1b78);
        goto LAB_004b5593;
      }
      uVar7 = *(undefined8 *)(local_100 + 0x1bc0);
      iVar5 = serverGetClientUnderLock(g_resServ,*puVar1,&local_f0);
      if (iVar5 != 0) {
        nvAssertOkFailedNoLog
                  (iVar5,"serverGetClientUnderLock(&g_resServ, session->handle, &pClient)",
                   "src/kernel/rmapi/nv_gpu_ops.c",0x2bb9);
        iVar4 = iVar5;
        goto LAB_004b55d1;
      }
      iVar5 = deviceGetByHandle_IMPL(local_f0,*(undefined4 *)(param_1 + 0x10),&local_e8);
      if (iVar5 != 0) {
        nvAssertOkFailedNoLog
                  (iVar5,"deviceGetByHandle(pClient, device->handle, &pDevice)",
                   "src/kernel/rmapi/nv_gpu_ops.c",0x2bbd);
        iVar4 = iVar5;
        goto LAB_004b55d1;
      }
      iVar5 = kmigmgrGetMemoryPartitionHeapFromDevice_IMPL(local_100,uVar7,local_e8,&local_f8);
      if (iVar5 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar5,
                   "kmigmgrGetMemoryPartitionHeapFromDevice(pGpu, pKernelMIGManager, pDevice, &pHeap)"
                   ,"src/kernel/rmapi/nv_gpu_ops.c",0x2bc1);
        iVar4 = iVar5;
        goto LAB_004b55d1;
      }
    }
    if (local_f8 == 0) {
      nvCheckFailedNoLog(4,"pHeap != NULL","src/kernel/rmapi/nv_gpu_ops.c",0x2bc8);
    }
    else {
      if (*(char *)(lVar2 + 0x434) != '\0') {
        *param_2 = *(undefined8 *)(local_f8 + 0x128);
        uVar7 = pmaGetStats();
        *param_3 = uVar7;
        goto LAB_004b55d1;
      }
      nvCheckFailedNoLog(4,"memmgrIsPmaInitialized(pMemoryManager)","src/kernel/rmapi/nv_gpu_ops.c",
                         0x2bcc);
    }
  }
  iVar4 = 0x57;
LAB_004b55d1:
  _nvGpuOpsLocksRelease(local_e0);
  threadStateFree(local_c8,0);
  return iVar4;
}


// ===== 004b57c0 nvGpuOpsP2pObjectCreate =====

void nvGpuOpsP2pObjectCreate(void)

{
  _nvGpuOpsP2pObjectCreate();
  return;
}


// ===== 004b57d0 nvGpuOpsP2pObjectDestroy =====

void nvGpuOpsP2pObjectDestroy(undefined8 param_1,undefined8 param_2)

{
  _nvGpuOpsP2pObjectDestroy(param_1,param_2,1);
  return;
}


// ===== 004b57e0 nvGpuOpsReportNonReplayableFault =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsReportNonReplayableFault(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined1 local_48 [40];
  
  lVar2 = rmapiGetInterface(1);
  if ((param_1 != 0) && (param_2 != 0)) {
    portMemSet(local_48,0,0x20);
    portMemCopy(local_48,0x20,param_2,0x20);
    iVar1 = (**(code **)(lVar2 + 0x38))
                      (lVar2,**(undefined4 **)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x14),
                       0x20800177,local_48,0x20);
    if (iVar1 == 0) {
      return 0;
    }
    uVar3 = nvstatusToString(iVar1);
    nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x2c37,"nvGpuOpsReportNonReplayableFault",4,
                 "NVRM: %s: NV2080_CTRL_CMD_GPU_REPORT_NON_REPLAYABLE_FAULTreturned error %s!\n",
                 "nvGpuOpsReportNonReplayableFault",uVar3);
    return iVar1;
  }
  return 0x1f;
}


// ===== 004b58f0 nvGpuOpsPagingChannelAllocate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsPagingChannelAllocate(long param_1,uint *param_2,long *param_3,long *param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long *plVar7;
  undefined8 uVar8;
  long local_78;
  undefined8 local_70;
  undefined1 local_68 [8];
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  lVar6 = rmapiGetInterface(1);
  uVar3 = osGetCurrentProcess();
  if (((((param_1 == 0) || (param_2 == (uint *)0x0)) || (param_3 == (long *)0x0)) ||
      (param_4 == (long *)0x0)) ||
     ((uVar1 = *param_2, 9 < uVar1 &&
      ((uVar1 + 0x2a < 9 || ((0x12 < uVar1 + 0x2a && (9 < uVar1 - 10)))))))) {
    iVar4 = 0x1f;
  }
  else {
    iVar2 = **(int **)(param_1 + 0x48);
    if (iVar2 == 0) {
      nvAssertFailedNoLog("hClient","src/kernel/rmapi/nv_gpu_ops.c",0x2c56);
    }
    plVar7 = (long *)portMemAllocNonPaged(0x28);
    if (plVar7 == (long *)0x0) {
      iVar4 = 0x51;
    }
    else {
      portMemSet(plVar7,0,0x28);
      *plVar7 = param_1;
      iVar4 = nvGpuOpsAllocPhysical(param_1,1,0x30,local_68,&local_60);
      if (iVar4 == 0) {
        *(int *)((long)plVar7 + 0x14) = local_48._4_4_;
        iVar4 = local_48._4_4_;
        if (local_48._4_4_ == 0) {
          nvAssertFailedNoLog("channel->errorNotifierHandle","src/kernel/rmapi/nv_gpu_ops.c",0x2c6a)
          ;
          iVar4 = *(int *)((long)plVar7 + 0x14);
        }
        iVar4 = (**(code **)(lVar6 + 0x70))
                          (lVar6,iVar2,*(undefined4 *)(param_1 + 0x14),iVar4,0,0x30,plVar7 + 1,0);
        if (iVar4 == 0) {
          if (plVar7[1] == 0) {
            nvAssertFailedNoLog("channel->errorNotifier","src/kernel/rmapi/nv_gpu_ops.c",0x2c77);
          }
          uVar8 = 0x4b5a4b;
          iVar4 = rmapiLockAcquire(2,0x400);
          if (iVar4 == 0) {
            iVar4 = serverGetClientUnderLock(g_resServ,iVar2,&local_70);
            if ((iVar4 == 0) &&
               (iVar4 = deviceGetByHandle_IMPL(local_70,*(undefined4 *)(param_1 + 0x10),&local_78),
               iVar4 == 0)) {
              plVar7[4] = local_78;
              rmapiLockRelease();
              *param_3 = (long)plVar7;
              *param_4 = plVar7[1];
              return 0;
            }
            uVar8 = 0x4b5a75;
            rmapiLockRelease();
          }
          iVar5 = (**(code **)(lVar6 + 0x88))
                            (lVar6,iVar2,*(undefined4 *)(param_1 + 0x14),
                             *(undefined4 *)((long)plVar7 + 0x14),plVar7[1],0,uVar3);
          if (iVar5 != 0) {
            nvAssertFailedNoLog("status2 == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0x2cb2,uVar8);
          }
        }
        (**(code **)(lVar6 + 0x18))(lVar6,iVar2,*(undefined4 *)((long)plVar7 + 0x14));
      }
      portMemFree(plVar7);
    }
  }
  return iVar4;
}


// ===== 004b5bf0 nvGpuOpsPagingChannelDestroy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nvGpuOpsPagingChannelDestroy(long *param_1)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined1 local_48 [8];
  undefined8 local_40 [2];
  
  lVar5 = rmapiGetInterface(1);
  uVar3 = osGetCurrentProcess();
  uVar7 = (ulong)uVar3;
  if (param_1 == (long *)0x0) {
    nvAssertFailedNoLog("channel","src/kernel/rmapi/nv_gpu_ops.c",0x2cc7);
    lVar2 = _DAT_00000000;
  }
  else {
    lVar2 = *param_1;
  }
  if (lVar2 == 0) {
    nvAssertFailedNoLog("device","src/kernel/rmapi/nv_gpu_ops.c",0x2cca);
    iVar1 = *_DAT_00000048;
  }
  else {
    iVar1 = **(int **)(lVar2 + 0x48);
  }
  if (iVar1 == 0) {
    nvAssertFailedNoLog("hClient","src/kernel/rmapi/nv_gpu_ops.c",0x2ccd);
  }
  iVar4 = rmapiLockAcquire(2,0x400);
  if (iVar4 == 0) {
    iVar4 = serverGetClientUnderLock(g_resServ,iVar1,local_40);
    if (iVar4 == 0) {
      iVar4 = deviceGetByHandle_IMPL(local_40[0],*(undefined4 *)(lVar2 + 0x10),local_48);
      if (iVar4 != 0) {
        nvAssertFailedNoLog("status == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0x2ce5);
        uVar6 = nvstatusToString(iVar4);
        nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x2ce8,"nvGpuOpsPagingChannelDestroy",4,
                     "NVRM: %s: deviceGetByHandle returned error %s!\n",
                     "nvGpuOpsPagingChannelDestroy",uVar6);
      }
    }
    else {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0x2cdb);
      uVar6 = nvstatusToString(iVar4);
      nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x2cde,"nvGpuOpsPagingChannelDestroy",4,
                   "NVRM: %s: serverGetClientUnderLock returned error %s!\n",
                   "nvGpuOpsPagingChannelDestroy",uVar6);
    }
    rmapiLockRelease();
  }
  else {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0x2cd1);
    uVar6 = nvstatusToString(iVar4);
    nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x2cd4,"nvGpuOpsPagingChannelDestroy",4,
                 "NVRM: %s: rmapiLockAcquire returned error %s!\n","nvGpuOpsPagingChannelDestroy",
                 uVar6);
  }
  iVar4 = (**(code **)(lVar5 + 0x88))
                    (lVar5,iVar1,*(undefined4 *)(lVar2 + 0x14),*(undefined4 *)((long)param_1 + 0x14)
                     ,param_1[1],0);
  if (iVar4 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0x2cfb,uVar7);
    uVar6 = nvstatusToString(iVar4);
    nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x2cfe,"nvGpuOpsPagingChannelDestroy",4,
                 "NVRM: %s: UnmapFromCpu returned error %s!\n","nvGpuOpsPagingChannelDestroy",uVar6)
    ;
  }
  (**(code **)(lVar5 + 0x18))(lVar5,iVar1,*(undefined4 *)((long)param_1 + 0x14));
  portMemFree(param_1);
  return;
}


// ===== 004b5ef0 nvGpuOpsPagingChannelsMap =====

ulong nvGpuOpsPagingChannelsMap(long param_1,undefined8 param_2,long param_3,long param_4)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  undefined1 local_54 [4];
  undefined1 local_50 [8];
  undefined8 local_48;
  undefined1 local_40 [32];
  
  if ((param_3 != 0 && param_4 != 0) && (param_1 != 0)) {
    iVar1 = **(int **)(param_3 + 0x48);
    if (iVar1 == 0) {
      nvAssertFailedNoLog("hClient","src/kernel/rmapi/nv_gpu_ops.c",0x2d17);
    }
    uVar3 = getHandleForVirtualAddr(param_1,param_2,1,local_54);
    if ((int)uVar3 == 0) {
      uVar3 = _nvGpuOpsLocksAcquireWithClientLockFlags
                        (0,1,iVar1,0,2,*(undefined4 *)(param_3 + 0x18),
                         *(undefined4 *)(*(long *)(param_1 + 8) + 0x18));
      if ((int)uVar3 == 0) {
        uVar2 = serverGetClientUnderLock(g_resServ,iVar1,&local_48,local_40);
        if (uVar2 == 0) {
          uVar2 = deviceGetByHandle_IMPL(local_48,*(undefined4 *)(param_3 + 0x10),local_50);
          if (uVar2 == 0) {
            portSyncMutexAcquire(*(undefined8 *)(param_3 + 0x1a0));
            portSyncMutexRelease(*(undefined8 *)(param_3 + 0x1a0));
          }
        }
        _nvGpuOpsLocksRelease(local_40);
        return (ulong)uVar2;
      }
    }
    return uVar3;
  }
  return 0x1f;
}


// ===== 004b6030 nvGpuOpsPagingChannelsUnmap =====

void nvGpuOpsPagingChannelsUnmap(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 local_54 [4];
  undefined1 local_50 [8];
  undefined8 local_48;
  undefined1 local_40 [32];
  
  if ((param_1 != 0) && (param_3 != 0)) {
    iVar2 = **(int **)(param_3 + 0x48);
    if (iVar2 == 0) {
      nvAssertFailedNoLog("hClient","src/kernel/rmapi/nv_gpu_ops.c",0x2d47);
    }
    iVar1 = getHandleForVirtualAddr(param_1,param_2,1,local_54);
    if (iVar1 == 0) {
      iVar1 = _nvGpuOpsLocksAcquireWithClientLockFlags(0,1,iVar2,0,3,0,0,local_40);
      if (iVar1 != 0) {
        uVar3 = nvstatusToString(iVar1);
        nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x2d56,"nvGpuOpsPagingChannelsUnmap",4,
                     "NVRM: %s: _nvGpuOpsLocksAcquire returned error %s!\n",
                     "nvGpuOpsPagingChannelsUnmap",uVar3);
        return;
      }
      iVar2 = serverGetClientUnderLock(g_resServ,iVar2,&local_48);
      if (iVar2 == 0) {
        iVar2 = deviceGetByHandle_IMPL(local_48,*(undefined4 *)(param_3 + 0x10),local_50);
        if (iVar2 == 0) {
          portSyncMutexAcquire(*(undefined8 *)(param_3 + 0x1a0));
          portSyncMutexRelease(*(undefined8 *)(param_3 + 0x1a0));
        }
        else {
          nvAssertFailedNoLog("status == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0x2d67);
          uVar3 = nvstatusToString(iVar2);
          nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x2d6a,"nvGpuOpsPagingChannelsUnmap",4,
                       "NVRM: %s: deviceGetByHandle returned error %s!\n",
                       "nvGpuOpsPagingChannelsUnmap",uVar3);
        }
      }
      else {
        nvAssertFailedNoLog("status == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0x2d5d);
        uVar3 = nvstatusToString(iVar2);
        nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x2d60,"nvGpuOpsPagingChannelsUnmap",4,
                     "NVRM: %s: serverGetClientUnderLock returned error %s!\n",
                     "nvGpuOpsPagingChannelsUnmap",uVar3);
      }
      _nvGpuOpsLocksRelease(local_40);
    }
    else {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0x2d4a);
      uVar3 = nvstatusToString(iVar1);
      nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x2d4d,"nvGpuOpsPagingChannelsUnmap",4,
                   "NVRM: %s: getHandleForVirtualAddr returned error %s!\n",
                   "nvGpuOpsPagingChannelsUnmap",uVar3);
    }
    return;
  }
  nvAssertFailedNoLog("srcVaSpace && device","src/kernel/rmapi/nv_gpu_ops.c",0x2d42);
  return;
}


// ===== 004b62b0 nvGpuOpsPagingChannelPushStream =====

undefined8 nvGpuOpsPagingChannelPushStream(long *param_1,long param_2,int param_3)

{
  long lVar1;
  
  if ((param_1 != (long *)0x0) && (param_2 != 0)) {
    if (param_3 != 0) {
      lVar1 = *param_1;
      if (lVar1 == 0) {
        nvAssertFailedNoLog("device","src/kernel/rmapi/nv_gpu_ops.c",0x2d87);
      }
      portSyncMutexAcquire(*(undefined8 *)(lVar1 + 0x1a0));
      portSyncMutexRelease(*(undefined8 *)(lVar1 + 0x1a0));
      return 0;
    }
    return 0;
  }
  return 0x1f;
}


// ===== 004b6340 nvGpuOpsReportFatalError =====

void nvGpuOpsReportFatalError
               (int param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  undefined8 uVar1;
  
  uVar1 = g_pSys;
  if (param_1 == 0) {
    nvAssertFailedNoLog("error != NV_OK","src/kernel/rmapi/nv_gpu_ops.c",0x2da2,param_4,param_5,0);
  }
  nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x2da4,"nvGpuOpsReportFatalError",4,
               "NVRM: uvm encountered global fatal error 0x%x, requiring os reboot to recover.\n",
               param_1);
  sysSetRecoveryRebootRequired_IMPL(uVar1,1);
  return;
}


// ===== 004b63c0 nvGpuOpsCcslContextInit =====

undefined8 nvGpuOpsCcslContextInit(long param_1,long *param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  if ((param_1 != 0) && (param_2 != (long *)0x0)) {
    lVar1 = *(long *)(*(long *)(*param_2 + 8) + 8);
    uVar2 = ccslContextInitViaChannel_IMPL
                      (param_1,**(undefined4 **)(lVar1 + 0x48),*(undefined4 *)(lVar1 + 0x14),
                       (int)param_2[1]);
    return uVar2;
  }
  return 0x1f;
}


// ===== 004b6400 nvGpuOpsCcslContextClear =====

undefined8 nvGpuOpsCcslContextClear(long param_1)

{
  if (param_1 != 0) {
    ccslContextClear_IMPL();
    return 0;
  }
  return 0x1f;
}


// ===== 004b6430 __pfx_nvGpuOpsCcslRotateKey =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int __pfx_nvGpuOpsCcslRotateKey(undefined8 *param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  uint *puVar6;
  long lVar7;
  undefined8 uVar8;
  uint uVar9;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  long alStack_40 [2];
  
  nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x2e10,"nvGpuOpsCcslRotateKey",1,
               "NVRM: Attempting to synchronously rotate %u keys.\n",param_2);
  if ((param_1 == (undefined8 *)0x0) || (lVar5 = 0, param_2 == 0)) {
    return 0x1f;
  }
  do {
    if (param_1[lVar5] == 0) {
      return 0x1f;
    }
    lVar5 = lVar5 + 1;
  } while ((uint)lVar5 < param_2);
  cVar3 = rmGpuLockIsOwner();
  if (cVar3 == '\0') {
    iVar4 = serverGetClientUnderLock(g_resServ,**(undefined4 **)*param_1,&uStack_48);
    if (iVar4 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar4,
                 "serverGetClientUnderLock(&g_resServ, contextList[0]->ctx->hClient, &pChannelClient)"
                 ,"src/kernel/rmapi/nv_gpu_ops.c",0x2e2e);
      return iVar4;
    }
    iVar4 = CliGetKernelChannel(uStack_48,*(undefined4 *)(*(long *)*param_1 + 8),alStack_40);
    if (iVar4 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar4,
                 "CliGetKernelChannel(pChannelClient, contextList[0]->ctx->hChannel, &pKernelChannel)"
                 ,"src/kernel/rmapi/nv_gpu_ops.c",0x2e31);
      return iVar4;
    }
    uStack_4c = 0;
    iVar4 = rmGpuGroupLockAcquire
                      (*(undefined4 *)(*(long *)(*(long *)(alStack_40[0] + 0x158) + 0xe0) + 0x7a4),0
                       ,1,0x8002,&uStack_4c);
    if (iVar4 == 99) {
      nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x2e3c,"nvGpuOpsCcslRotateKey",1,
                   "NVRM: Unable to acquire GPU lock for key rotation. Returning early.\n");
      return 99;
    }
    bVar2 = true;
    if (iVar4 != 0) {
      uVar8 = nvstatusToString(iVar4);
      nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x2e41,"nvGpuOpsCcslRotateKey",1,
                   "NVRM: Converting %s to NV_ERR_GENERIC.\n",uVar8);
      return 0xffff;
    }
  }
  else {
    bVar2 = false;
  }
  cVar3 = rmGpuLockIsOwner();
  if (cVar3 == '\0') {
    nvAssertFailedNoLog("rmGpuLockIsOwner()","src/kernel/rmapi/nv_gpu_ops.c",0x2dbb);
  }
  puVar6 = (uint *)portMemAllocNonPaged(0x108);
  if (puVar6 == (uint *)0x0) {
    iVar4 = 0x51;
LAB_004b66db:
    nvCheckOkFailedNoLog
              (4,iVar4,"nvGpuOpsKeyRotationChannelDisable(contextList, contextListCount)",
               "src/kernel/rmapi/nv_gpu_ops.c",0x2e49);
  }
  else {
    uVar9 = 0;
    do {
      lVar5 = rmapiGetInterface(4);
      uVar1 = param_2 - uVar9;
      if (0x40 < param_2 - uVar9) {
        uVar1 = 0x40;
      }
      portMemSet(puVar6,0,0x108);
      *(undefined1 *)(puVar6 + 0x41) = 1;
      *puVar6 = uVar1;
      if (uVar9 < uVar9 + uVar1) {
        lVar7 = 0;
        do {
          puVar6[(ulong)uVar9 + lVar7 + 1] = *(uint *)(*(long *)param_1[(ulong)uVar9 + lVar7] + 8);
          lVar7 = lVar7 + 1;
        } while ((ulong)(uVar1 - 1) + 1 != lVar7);
      }
      iVar4 = (**(code **)(lVar5 + 0x38))
                        (lVar5,**(undefined4 **)*param_1,(*(undefined4 **)*param_1)[1],0x2080111b,
                         puVar6,0x108);
      if (iVar4 != 0) {
        portMemFree(puVar6);
        goto LAB_004b66db;
      }
      uVar9 = uVar9 + 0x40;
    } while (uVar9 < param_2);
    lVar5 = 0;
    portMemFree(puVar6);
    do {
      iVar4 = ccslContextUpdate_KERNEL(*(undefined8 *)param_1[lVar5]);
      if (iVar4 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar4,"ccslContextUpdate(contextList[index]->ctx)",
                   "src/kernel/rmapi/nv_gpu_ops.c",0x2e4f);
        break;
      }
      lVar5 = lVar5 + 1;
    } while ((uint)lVar5 < param_2);
  }
  if (bVar2) {
    rmGpuGroupLockRelease(uStack_4c,0);
  }
  return iVar4;
}


// ===== 004b6440 nvGpuOpsCcslRotateKey =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvGpuOpsCcslRotateKey(undefined8 *param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  uint *puVar6;
  long lVar7;
  undefined8 uVar8;
  uint uVar9;
  undefined4 local_4c;
  undefined8 local_48;
  long local_40 [2];
  
  nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x2e10,"nvGpuOpsCcslRotateKey",1,
               "NVRM: Attempting to synchronously rotate %u keys.\n",param_2);
  if ((param_1 == (undefined8 *)0x0) || (lVar5 = 0, param_2 == 0)) {
    return 0x1f;
  }
  do {
    if (param_1[lVar5] == 0) {
      return 0x1f;
    }
    lVar5 = lVar5 + 1;
  } while ((uint)lVar5 < param_2);
  cVar3 = rmGpuLockIsOwner();
  if (cVar3 == '\0') {
    iVar4 = serverGetClientUnderLock(g_resServ,**(undefined4 **)*param_1,&local_48);
    if (iVar4 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar4,
                 "serverGetClientUnderLock(&g_resServ, contextList[0]->ctx->hClient, &pChannelClient)"
                 ,"src/kernel/rmapi/nv_gpu_ops.c",0x2e2e);
      return iVar4;
    }
    iVar4 = CliGetKernelChannel(local_48,*(undefined4 *)(*(long *)*param_1 + 8),local_40);
    if (iVar4 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar4,
                 "CliGetKernelChannel(pChannelClient, contextList[0]->ctx->hChannel, &pKernelChannel)"
                 ,"src/kernel/rmapi/nv_gpu_ops.c",0x2e31);
      return iVar4;
    }
    local_4c = 0;
    iVar4 = rmGpuGroupLockAcquire
                      (*(undefined4 *)(*(long *)(*(long *)(local_40[0] + 0x158) + 0xe0) + 0x7a4),0,1
                       ,0x8002,&local_4c);
    if (iVar4 == 99) {
      nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x2e3c,"nvGpuOpsCcslRotateKey",1,
                   "NVRM: Unable to acquire GPU lock for key rotation. Returning early.\n");
      return 99;
    }
    bVar2 = true;
    if (iVar4 != 0) {
      uVar8 = nvstatusToString(iVar4);
      nvDbg_Printf("src/kernel/rmapi/nv_gpu_ops.c",0x2e41,"nvGpuOpsCcslRotateKey",1,
                   "NVRM: Converting %s to NV_ERR_GENERIC.\n",uVar8);
      return 0xffff;
    }
  }
  else {
    bVar2 = false;
  }
  cVar3 = rmGpuLockIsOwner();
  if (cVar3 == '\0') {
    nvAssertFailedNoLog("rmGpuLockIsOwner()","src/kernel/rmapi/nv_gpu_ops.c",0x2dbb);
  }
  puVar6 = (uint *)portMemAllocNonPaged(0x108);
  if (puVar6 == (uint *)0x0) {
    iVar4 = 0x51;
LAB_004b66db:
    nvCheckOkFailedNoLog
              (4,iVar4,"nvGpuOpsKeyRotationChannelDisable(contextList, contextListCount)",
               "src/kernel/rmapi/nv_gpu_ops.c",0x2e49);
  }
  else {
    uVar9 = 0;
    do {
      lVar5 = rmapiGetInterface(4);
      uVar1 = param_2 - uVar9;
      if (0x40 < param_2 - uVar9) {
        uVar1 = 0x40;
      }
      portMemSet(puVar6,0,0x108);
      *(undefined1 *)(puVar6 + 0x41) = 1;
      *puVar6 = uVar1;
      if (uVar9 < uVar9 + uVar1) {
        lVar7 = 0;
        do {
          puVar6[(ulong)uVar9 + lVar7 + 1] = *(uint *)(*(long *)param_1[(ulong)uVar9 + lVar7] + 8);
          lVar7 = lVar7 + 1;
        } while ((ulong)(uVar1 - 1) + 1 != lVar7);
      }
      iVar4 = (**(code **)(lVar5 + 0x38))
                        (lVar5,**(undefined4 **)*param_1,(*(undefined4 **)*param_1)[1],0x2080111b,
                         puVar6,0x108);
      if (iVar4 != 0) {
        portMemFree(puVar6);
        goto LAB_004b66db;
      }
      uVar9 = uVar9 + 0x40;
    } while (uVar9 < param_2);
    lVar5 = 0;
    portMemFree(puVar6);
    do {
      iVar4 = ccslContextUpdate_KERNEL(*(undefined8 *)param_1[lVar5]);
      if (iVar4 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar4,"ccslContextUpdate(contextList[index]->ctx)",
                   "src/kernel/rmapi/nv_gpu_ops.c",0x2e4f);
        break;
      }
      lVar5 = lVar5 + 1;
    } while ((uint)lVar5 < param_2);
  }
  if (bVar2) {
    rmGpuGroupLockRelease(local_4c,0);
  }
  return iVar4;
}


// ===== 004b67f0 nvGpuOpsCcslRotateIv =====

undefined8 nvGpuOpsCcslRotateIv(long param_1,undefined1 param_2)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    uVar1 = ccslRotateIv_IMPL(param_1,param_2);
    return uVar1;
  }
  return 0x1f;
}


// ===== 004b6810 nvGpuOpsCcslEncryptWithIv =====

undefined1  [16]
nvGpuOpsCcslEncryptWithIv
          (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  
  if (param_1 != 0) {
    auVar1._0_8_ = ccslEncryptWithIv_IMPL();
    auVar1._8_8_ = param_5;
    return auVar1;
  }
  auVar2._8_8_ = param_3;
  auVar2._0_8_ = 0x1f;
  return auVar2;
}


// ===== 004b6840 nvGpuOpsCcslEncrypt =====

undefined1  [16]
nvGpuOpsCcslEncrypt(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined8 param_5)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  
  if (param_1 != 0) {
    auVar1._0_8_ = ccslEncrypt_KERNEL();
    auVar1._8_8_ = param_5;
    return auVar1;
  }
  auVar2._8_8_ = param_3;
  auVar2._0_8_ = 0x1f;
  return auVar2;
}


// ===== 004b6870 nvGpuOpsCcslDecrypt =====

undefined8 nvGpuOpsCcslDecrypt(long param_1)

{
  undefined8 uVar1;
  undefined4 uStack0000000000000008;
  undefined4 in_stack_00000010;
  
  if (param_1 != 0) {
    uStack0000000000000008 = in_stack_00000010;
    uVar1 = ccslDecrypt_KERNEL();
    return uVar1;
  }
  return 0x1f;
}


// ===== 004b68b0 nvGpuOpsCcslSign =====

undefined8 nvGpuOpsCcslSign(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    uVar1 = ccslSign_IMPL();
    return uVar1;
  }
  return 0x1f;
}


// ===== 004b68d0 nvGpuOpsQueryMessagePool =====

undefined8 nvGpuOpsQueryMessagePool(long param_1,char param_2)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    if (param_2 == '\0') {
      uVar1 = ccslQueryMessagePool_IMPL(param_1,0);
      return uVar1;
    }
    if (param_2 == '\x01') {
      uVar1 = ccslQueryMessagePool_IMPL(param_1,1);
      return uVar1;
    }
  }
  return 0x1f;
}


// ===== 004b6910 nvGpuOpsIncrementIv =====

undefined8 nvGpuOpsIncrementIv(long param_1,char param_2)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    if (param_2 == '\0') {
      uVar1 = ccslIncrementIv_IMPL(param_1,0);
      return uVar1;
    }
    if (param_2 == '\x01') {
      uVar1 = ccslIncrementIv_IMPL(param_1,1);
      return uVar1;
    }
  }
  return 0x1f;
}


// ===== 004b6950 nvGpuOpsLogEncryption =====

undefined8 nvGpuOpsLogEncryption(long param_1,undefined1 param_2)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    uVar1 = ccslLogEncryption_IMPL(param_1,param_2);
    return uVar1;
  }
  return 0x1f;
}


// ===== 004b6970 rmapiParamsAcquire =====

ulong rmapiParamsAcquire(long *param_1,char param_2)

{
  char cVar1;
  long *plVar2;
  long lVar3;
  char *pcVar4;
  ulong uVar5;
  uint uVar6;
  ulong uVar7;
  
  uVar6 = *(uint *)(param_1 + 2);
  lVar3 = *param_1;
  cVar1 = (char)param_1[3];
  if (uVar6 == 0) {
    if (lVar3 != 0) goto LAB_004b6a90;
    if (cVar1 == '\0') goto LAB_004b6b08;
LAB_004b6a1d:
    if (*(char *)(g_pSys + 0x71) != '\0') {
      uVar6 = osIsKernelBuffer(lVar3);
      if (uVar6 != 0) {
        lVar3 = 0;
        nvDbg_Printf("src/kernel/rmapi/param_copy.c",0x43,"rmapiParamsAcquire",4,
                     "NVRM: Error validating kernel pointer. Status 0x%x\n",uVar6);
        uVar7 = (ulong)uVar6;
        goto LAB_004b69f0;
      }
      lVar3 = *param_1;
    }
    uVar6 = *(uint *)((long)param_1 + 0x14);
    *(uint *)((long)param_1 + 0x14) = uVar6 | 1;
    uVar6 = uVar6 & 8;
    uVar7 = (ulong)uVar6;
    if (uVar6 != 0) {
LAB_004b6a41:
      portMemSet(lVar3,0,(int)param_1[2]);
      plVar2 = (long *)param_1[1];
      uVar7 = 0;
      uVar6 = 0;
      goto joined_r0x004b6a58;
    }
  }
  else {
    if (lVar3 == 0) {
LAB_004b6a90:
      pcVar4 = "valid";
      if (cVar1 == '\0') {
        pcVar4 = "invalid";
      }
LAB_004b6aa4:
      nvDbg_Printf("src/kernel/rmapi/param_copy.c",0x2f,"rmapiParamsAcquire",3,
                   "NVRM: %s:  bad params from client: ptr %p size: 0x%x (%s)\n",param_1[4],lVar3,
                   uVar6,pcVar4);
    }
    else {
      if (cVar1 == '\0') {
LAB_004b6b08:
        pcVar4 = "invalid";
        goto LAB_004b6aa4;
      }
      if (param_2 == '\0') goto LAB_004b6a1d;
      if (((*(byte *)((long)param_1 + 0x14) & 0x10) != 0) || (uVar6 < 0x100001)) {
        lVar3 = portMemAllocNonPaged(uVar6);
        if (lVar3 == 0) {
          nvDbg_Printf("src/kernel/rmapi/param_copy.c",100,"rmapiParamsAcquire",3,
                       "NVRM: (%s): portMemAllocNonPaged failure: status 0x%x\n",param_1[4],0x1a);
          uVar7 = 0x1a;
        }
        else {
          uVar7 = 0;
          if (*param_1 != 0) {
            if ((*(uint *)((long)param_1 + 0x14) & 2) == 0) {
              uVar5 = portMemExCopyFromUser(*param_1,lVar3,(int)param_1[2]);
              uVar7 = uVar5 & 0xffffffff;
              if ((int)uVar5 != 0) {
                nvDbg_Printf("src/kernel/rmapi/param_copy.c",0x76,"rmapiParamsAcquire",3,
                             "NVRM: (%s): portMemExCopyFromUser failure: status 0x%x\n",param_1[4],
                             uVar5);
                portMemFree(lVar3);
                uVar7 = uVar5 & 0xffffffff;
                lVar3 = 0;
              }
            }
            else {
              if ((*(uint *)((long)param_1 + 0x14) & 8) != 0) goto LAB_004b6a41;
              uVar7 = 0;
            }
          }
        }
        goto LAB_004b69f0;
      }
      nvDbg_Printf("src/kernel/rmapi/param_copy.c",0x57,"rmapiParamsAcquire",3,
                   "NVRM: (%s): Requested size exceeds max (%ud > %ud)\n",param_1[4],uVar6,0x100000)
      ;
    }
    uVar7 = 0x1f;
    lVar3 = 0;
  }
LAB_004b69f0:
  uVar6 = (uint)uVar7;
  plVar2 = (long *)param_1[1];
joined_r0x004b6a58:
  if (plVar2 != (long *)0x0) {
    *plVar2 = lVar3;
    return uVar7;
  }
  nvAssertFailedNoLog("pParamCopy->ppKernelParams != NULL","src/kernel/rmapi/param_copy.c",0x88);
  *(long *)param_1[1] = lVar3;
  return (ulong)uVar6;
}


// ===== 004b6c30 rmapiParamsRelease =====

int rmapiParamsRelease(long *param_1)

{
  long *plVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  plVar1 = (long *)param_1[1];
  if (plVar1 == (long *)0x0) {
    return 0;
  }
  if (((*(uint *)((long)param_1 + 0x14) & 1) == 0) && (lVar4 = *plVar1, lVar4 != 0)) {
    iVar2 = 0;
    if ((*param_1 != 0) && ((*(uint *)((long)param_1 + 0x14) & 4) == 0)) {
      uVar3 = portMemExCopyToUser(lVar4,*param_1,(int)param_1[2]);
      iVar2 = (int)uVar3;
      if (iVar2 == 0) {
        lVar4 = *(long *)param_1[1];
      }
      else {
        nvDbg_Printf("src/kernel/rmapi/param_copy.c",0xad,"rmapiParamsRelease",3,
                     "NVRM: (%s): portMemExCopyToUser failure: status 0x%x\n",param_1[4],uVar3);
        lVar4 = *(long *)param_1[1];
      }
    }
    portMemFree(lVar4);
    *(undefined8 *)param_1[1] = 0;
    return iVar2;
  }
  *plVar1 = 0;
  return 0;
}


// ===== 004b6d40 rmapiParamsCopyIn =====

ulong rmapiParamsCopyIn(undefined8 param_1,long param_2,long param_3,ulong param_4,char param_5)

{
  ulong uVar1;
  ulong uVar2;
  
  if ((param_2 != 0 && param_3 != 0) && ((int)param_4 != 0)) {
    if (param_5 == '\0') {
      if (param_2 != param_3) {
        portMemCopy(param_2,param_4 & 0xffffffff,param_3,param_4 & 0xffffffff);
      }
      uVar2 = 0;
    }
    else {
      uVar1 = portMemExCopyFromUser(param_3,param_2,param_4 & 0xffffffff);
      uVar2 = uVar1 & 0xffffffff;
      if ((int)uVar1 != 0) {
        nvDbg_Printf("src/kernel/rmapi/param_copy.c",0xe9,"rmapiParamsCopyIn",3,
                     "NVRM: (%s): portMemExCopyFromUser failure: status 0x%x\n",param_1,uVar1);
        uVar2 = uVar1 & 0xffffffff;
      }
    }
    return uVar2;
  }
  nvDbg_Printf("src/kernel/rmapi/param_copy.c",0xd3,"rmapiParamsCopyIn",3,
               "NVRM: (%s):  bad params from client: ptr %p size: 0x%x\n",param_1,param_3,param_4);
  return 0x1f;
}


// ===== 004b6e20 rmapiParamsCopyOut =====

ulong rmapiParamsCopyOut(undefined8 param_1,long param_2,long param_3,ulong param_4,char param_5)

{
  ulong uVar1;
  ulong uVar2;
  
  if ((param_2 != 0 && param_3 != 0) && ((int)param_4 != 0)) {
    if (param_5 == '\0') {
      if (param_2 != param_3) {
        portMemCopy(param_3,param_4 & 0xffffffff,param_2,param_4 & 0xffffffff);
      }
      uVar2 = 0;
    }
    else {
      uVar1 = portMemExCopyToUser(param_2,param_3,param_4 & 0xffffffff);
      uVar2 = uVar1 & 0xffffffff;
      if ((int)uVar1 != 0) {
        nvDbg_Printf("src/kernel/rmapi/param_copy.c",0x11f,"rmapiParamsCopyOut",3,
                     "NVRM: (%s): portMemExCopyToUser failure: status 0x%x\n",param_1,uVar1);
        uVar2 = uVar1 & 0xffffffff;
      }
    }
    return uVar2;
  }
  nvDbg_Printf("src/kernel/rmapi/param_copy.c",0x109,"rmapiParamsCopyOut",3,
               "NVRM: (%s):  bad params from client: ptr %p size: 0x%x\n",param_1,param_3,param_4);
  return 0x1f;
}


// ===== 004b6f00 rmapiParamsCopyInit =====

undefined8 rmapiParamsCopyInit(long *param_1,undefined4 param_2)

{
  undefined8 uVar1;
  char local_19 [9];
  
  uVar1 = rmapiGetClassAllocParamSize(param_1 + 2,*param_1,local_19,param_2);
  if ((int)uVar1 == 0) {
    if ((local_19[0] == '\0') && (*param_1 == 0)) {
      uVar1 = 0x1f;
    }
    else {
      *(undefined1 *)(param_1 + 3) = 1;
    }
  }
  return uVar1;
}


// ===== 004b6f50 rmrescmnConstruct_IMPL =====

undefined8 rmrescmnConstruct_IMPL(void)

{
  return 0;
}


// ===== 004b6f60 rmresConstruct_IMPL =====

undefined8 rmresConstruct_IMPL(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  
  if (*(long *)(param_3 + 0x58) != 0) {
    lVar1 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(param_3 + 0x58) + 8),
                               __nvoc_class_def_RmResource);
    *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(lVar1 + 0xa0);
    *(undefined1 *)(param_1 + 0xa4) = *(undefined1 *)(lVar1 + 0xa4);
    return 0;
  }
  *(undefined4 *)(param_1 + 0xa0) = 0xffffffff;
  *(undefined1 *)(param_1 + 0xa4) = 0;
  return 0;
}


// ===== 004b6fd0 rmresAccessCallback_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
rmresAccessCallback_IMPL(long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  long local_30 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar1 = **(long **)(*(long *)(param_1 + 0x88) + 0x48);
  iVar4 = clientGetResourceRef_IMPL(lVar1,*(undefined4 *)(lVar1 + 0x48),local_30);
  if ((iVar4 == 0) &&
     (cVar3 = (**(code **)(**(long **)(local_30[0] + 8) + 0xa8))
                        (*(long **)(local_30[0] + 8),param_2,param_3), cVar3 != '\0')) {
    return 1;
  }
  uVar5 = resAccessCallback_IMPL(*(undefined8 *)(param_1 + 0x88),param_2,param_3,param_4);
  return uVar5;
}


// ===== 004b7080 rmresShareCallback_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 rmresShareCallback_IMPL(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  ushort uVar1;
  bool bVar2;
  code *pcVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  long *plVar7;
  undefined8 uVar8;
  long lVar9;
  long local_40 [2];
  
  uVar1 = *(ushort *)(param_4 + 8);
  if (uVar1 < 7) {
    if (uVar1 < 5) goto LAB_004b7140;
    if ((*(byte *)(param_4 + 10) & 2) == 0) {
      if (param_1 == 0) goto LAB_004b7177;
    }
    else {
      if (param_1 == 0) {
        lVar9 = __nvoc_dynamicCast(0,__nvoc_class_def_GpuResource);
        if (lVar9 == 0) {
          return 1;
        }
        goto LAB_004b7177;
      }
      lVar9 = __nvoc_dynamicCast(param_1,__nvoc_class_def_GpuResource);
      if (lVar9 == 0) {
        return 1;
      }
    }
  }
  else if (uVar1 == 7) {
    if (param_1 == 0) goto LAB_004b7224;
    bVar2 = true;
    plVar7 = (long *)__nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x88) + 0x48),
                                        __nvoc_class_def_RmClient);
    if (plVar7 != (long *)0x0) {
      uVar5 = (**(code **)(*plVar7 + 0xd8))(plVar7);
      bVar2 = uVar5 < 2;
    }
    uVar8 = __nvoc_dynamicCast(param_2,__nvoc_class_def_RmClient);
    cVar4 = rmclientIsCapable_IMPL(uVar8,0x200);
    if ((cVar4 != '\0') && (bVar2)) {
      return 1;
    }
  }
  else {
LAB_004b7140:
    if (param_1 == 0) {
LAB_004b7224:
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    lVar9 = **(long **)(*(long *)(param_1 + 0x88) + 0x48);
    iVar6 = clientGetResourceRef_IMPL(lVar9,*(undefined4 *)(lVar9 + 0x48),local_40);
    if ((iVar6 == 0) &&
       (cVar4 = (**(code **)(**(long **)(local_40[0] + 8) + 0xb0))
                          (*(long **)(local_40[0] + 8),param_2,param_3,param_4), cVar4 != '\0')) {
      return 1;
    }
  }
  param_1 = *(long *)(param_1 + 0x88);
LAB_004b7177:
  uVar8 = resShareCallback_IMPL(param_1,param_2,param_3,param_4);
  return uVar8;
}


// ===== 004b7250 serverControl_InitCookie =====

void serverControl_InitCookie(long param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x10);
  param_2[1] = *(undefined4 *)(param_1 + 8);
  param_2[3] = *(undefined4 *)(param_1 + 0xc);
  return;
}


// ===== 004b7270 rmresGetMemInterMapParams_IMPL =====

undefined8 rmresGetMemInterMapParams_IMPL(void)

{
  return 0x33;
}


// ===== 004b7280 rmresCheckMemInterUnmap_IMPL =====

undefined8 rmresCheckMemInterUnmap_IMPL(void)

{
  return 0x33;
}


// ===== 004b7290 rmresGetMemoryMappingDescriptor_IMPL =====

undefined8 rmresGetMemoryMappingDescriptor_IMPL(void)

{
  return 0x56;
}


// ===== 004b72a0 rmresControlSerialization_Prologue_IMPL =====

ulong rmresControlSerialization_Prologue_IMPL(long param_1,undefined8 param_2,long param_3)

{
  byte bVar1;
  long lVar2;
  ulong uVar3;
  
  lVar2 = gpumgrGetGpu(*(undefined4 *)(param_1 + 0xa0));
  if (lVar2 != 0) {
    if ((*(char *)(lVar2 + 0x908) == '\0') || ((*(byte *)(*(long *)(param_3 + 0x60) + 5) & 2) == 0))
    {
      if (*(char *)(lVar2 + 0x909) == '\0') {
        if (*(char *)(lVar2 + 0x90a) == '\0') goto LAB_004b72eb;
        bVar1 = *(byte *)(*(long *)(param_3 + 0x60) + 4);
      }
      else {
        bVar1 = *(byte *)(*(long *)(param_3 + 0x60) + 4);
      }
      if ((bVar1 & 0x40) == 0) goto LAB_004b72eb;
    }
    uVar3 = serverSerializeCtrlDown
                      (param_2,*(undefined4 *)(param_3 + 8),param_3 + 0x10,param_3 + 0x18,
                       param_3 + 0xc);
    return uVar3;
  }
LAB_004b72eb:
  uVar3 = serverDeserializeCtrlDown
                    (param_2,*(undefined4 *)(param_3 + 8),param_3 + 0x10,param_3 + 0x18,
                     param_3 + 0xc);
  if ((int)uVar3 != 0) {
    nvCheckOkFailedNoLog
              (4,uVar3 & 0xffffffff,
               "serverDeserializeCtrlDown(pCallContext, pParams->cmd, &pParams->pParams, &pParams->paramsSize, &pParams->flags)"
               ,"src/kernel/rmapi/resource.c",0xe2);
    uVar3 = uVar3 & 0xffffffff;
  }
  return uVar3;
}


// ===== 004b7370 rmresControlSerialization_Epilogue_IMPL =====

void rmresControlSerialization_Epilogue_IMPL(long param_1,undefined8 param_2,long param_3)

{
  byte bVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = gpumgrGetGpu(*(undefined4 *)(param_1 + 0xa0));
  if (lVar3 != 0) {
    if ((*(char *)(lVar3 + 0x908) == '\0') || ((*(byte *)(*(long *)(param_3 + 0x60) + 5) & 2) == 0))
    {
      if (*(char *)(lVar3 + 0x909) == '\0') {
        if (*(char *)(lVar3 + 0x90a) == '\0') goto LAB_004b73e1;
        bVar1 = *(byte *)(*(long *)(param_3 + 0x60) + 4);
      }
      else {
        bVar1 = *(byte *)(*(long *)(param_3 + 0x60) + 4);
      }
      if ((bVar1 & 0x40) == 0) goto LAB_004b73e1;
    }
    iVar2 = serverDeserializeCtrlUp
                      (param_2,*(undefined4 *)(param_3 + 8),param_3 + 0x10,param_3 + 0x18);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,
                 "serverDeserializeCtrlUp(pCallContext, pParams->cmd, &pParams->pParams, &pParams->paramsSize, &pParams->flags)"
                 ,"src/kernel/rmapi/resource.c",0xf6);
    }
  }
LAB_004b73e1:
  iVar2 = serverSerializeCtrlUp
                    (param_2,*(undefined4 *)(param_3 + 8),param_3 + 0x10,param_3 + 0x18,
                     param_3 + 0xc);
  if (iVar2 != 0) {
    nvAssertOkFailedNoLog
              (iVar2,
               "serverSerializeCtrlUp(pCallContext, pParams->cmd, &pParams->pParams, &pParams->paramsSize, &pParams->flags)"
               ,"src/kernel/rmapi/resource.c",0xf9);
  }
  serverFreeSerializeStructures(param_2,*(undefined8 *)(param_3 + 0x10));
  return;
}


// ===== 004b74a0 rmresControl_Prologue_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int rmresControl_Prologue_IMPL(long param_1,undefined8 param_2,undefined4 *param_3)

{
  char cVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  ulong extraout_RDX;
  ulong uVar5;
  int local_1c;
  
  lVar3 = gpumgrGetGpu(*(undefined4 *)(param_1 + 0xa0));
  if (lVar3 == 0) {
    return 0;
  }
  if ((*(char *)(lVar3 + 0x908) == '\0') || ((*(byte *)(*(long *)(param_3 + 0x18) + 5) & 2) == 0)) {
    if ((*(char *)(lVar3 + 0x909) == '\0') && (*(char *)(lVar3 + 0x90a) == '\0')) {
      return 0;
    }
    if ((*(uint *)(*(long *)(param_3 + 0x18) + 4) & 0x40) == 0) {
      return 0;
    }
  }
  local_1c = 0;
  cVar1 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar3 + 0x7a4));
  if (cVar1 == '\0') {
    if ((*(byte *)(*(long *)(param_3 + 0x18) + 4) & 1) == 0) {
      nvAssertFailedNoLog("pParams->pCookie->ctrlFlags & RMCTRL_FLAGS_NO_GPUS_LOCK",
                          "src/kernel/rmapi/resource.c",0x119);
    }
    iVar2 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar3 + 0x7a4),0,2,0x8002,&local_1c);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,
                 "rmGpuGroupLockAcquire(pGpu->gpuInstance, GPU_LOCK_GRP_SUBDEVICE, GPU_LOCK_FLAGS_SAFE_LOCK_UPGRADE, RM_LOCK_MODULES_RPC, &gpuMaskRelease)"
                 ,"src/kernel/rmapi/resource.c",0x11a);
      return iVar2;
    }
  }
  lVar4 = gpuGetRpc(lVar3);
  if (lVar4 == 0) {
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/rmapi/resource.c",0x121);
    if (local_1c != 0) {
      rmGpuGroupLockRelease(local_1c,0);
    }
    iVar2 = 0x1a;
  }
  else {
    uVar5 = (ulong)(uint)param_3[6];
    if ((*(char *)(lVar3 + 0x909) == '\0') && (*(char *)(lVar3 + 0x90a) == '\0')) {
      iVar2 = rpcDmaControl_wrapper
                        (lVar3,lVar4,*param_3,param_3[1],param_3[2],*(undefined8 *)(param_3 + 4));
    }
    else {
      iVar2 = (**(code **)(lVar3 + 0x3b90))(lVar3 + 0x3b58);
      uVar5 = extraout_RDX;
    }
    if (local_1c != 0) {
      rmGpuGroupLockRelease(local_1c,0,uVar5);
    }
    if (iVar2 == 0) {
      iVar2 = 0x10006;
    }
  }
  return iVar2;
}


// ===== 004b76c0 rmresControl_Epilogue_IMPL =====

void rmresControl_Epilogue_IMPL(void)

{
  return;
}


// ===== 004b76e0 RsResInfoInitialize =====

void RsResInfoInitialize(void)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  long lVar4;
  undefined1 local_60 [56];
  
  lVar4 = 0;
  puVar3 = &g_RsResourceDescList;
  do {
    puVar1 = puVar3 + 0xe;
    do {
      while (*puVar1 < *puVar3) {
        portMemCopy(local_60,0x38,puVar3,0x38);
        portMemCopy(puVar3,0x38,puVar1,0x38);
        puVar2 = puVar1 + 0xe;
        portMemCopy(puVar1,0x38,local_60,0x38);
        puVar1 = puVar2;
        if (puVar2 == (uint *)LOCK_TEST_RELAXED_DUP_OBJECTParentList) goto LAB_004b7783;
      }
      puVar1 = puVar1 + 0xe;
    } while (puVar1 != (uint *)LOCK_TEST_RELAXED_DUP_OBJECTParentList);
LAB_004b7783:
    lVar4 = lVar4 + 1;
    puVar3 = puVar3 + 0xe;
    if (lVar4 == 0xcf) {
      return;
    }
  } while( true );
}


// ===== 004b77b0 RsResInfoByExternalClassId =====

undefined4 * RsResInfoByExternalClassId(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = 0xd0;
  uVar4 = 0;
  while( true ) {
    uVar2 = uVar1;
    uVar3 = uVar4 + uVar2 >> 1;
    if ((&g_RsResourceDescList)[(ulong)uVar3 * 0xe] == param_1) {
      return &g_RsResourceDescList + (ulong)uVar3 * 0xe;
    }
    if ((uVar2 == uVar3) || (uVar4 == uVar3)) break;
    uVar1 = uVar3;
    if ((uint)(&g_RsResourceDescList)[(ulong)uVar3 * 0xe] <= param_1) {
      uVar1 = uVar2;
      uVar4 = uVar3;
    }
  }
  return (undefined4 *)0x0;
}


// ===== 004b7800 RsResInfoGetInternalClassId =====

undefined4 RsResInfoGetInternalClassId(long param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 4);
  }
  return uVar1;
}


// ===== 004b7810 RsResInfoGetResourceList =====

void RsResInfoGetResourceList(undefined8 *param_1,undefined4 *param_2)

{
  *param_1 = &g_RsResourceDescList;
  *param_2 = 0xd0;
  return;
}


// ===== 004b7830 rmapiGetClassAllocParamSize =====

undefined8 rmapiGetClassAllocParamSize(int *param_1,long param_2,undefined1 *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  
  *param_1 = 0;
  *param_3 = 0;
  uVar5 = 0;
  uVar3 = 0xd0;
  while( true ) {
    uVar2 = uVar3;
    uVar3 = uVar5 + uVar2 >> 1;
    lVar4 = (ulong)uVar3 * 0x38;
    if (param_4 == (&g_RsResourceDescList)[(ulong)uVar3 * 0xe]) break;
    if ((uVar2 == uVar3) || (uVar5 == uVar3)) {
      return 0x22;
    }
    if ((uint)(&g_RsResourceDescList)[(ulong)uVar3 * 0xe] <= param_4) {
      uVar5 = uVar3;
      uVar3 = uVar2;
    }
  }
  iVar1 = *(int *)(&DAT_005a0310 + lVar4);
  if ((&DAT_005a0314)[lVar4] == '\0') {
    *param_3 = 1;
    if (iVar1 == 0) {
      return 0;
    }
    if (param_2 != 0) {
      *param_1 = *(int *)(&DAT_005a0310 + lVar4);
      return 0;
    }
  }
  else {
    *param_1 = iVar1;
  }
  return 0;
}


// ===== 004b78e0 rmapiInitialize =====

int rmapiInitialize(void)

{
  int iVar1;
  undefined8 uVar2;
  int local_1c;
  
  if (g_bResServInit != '\0') {
    nvAssertFailedNoLog("!g_bResServInit","src/kernel/rmapi/rmapi.c",0x4f);
  }
  g_resServ[0x41] = 1;
  local_1c = 0;
  iVar1 = osReadRegistryDword(0,"RMLockingLowPriorityAging",&local_1c);
  if (iVar1 == 0) {
    DAT_0054e2ac = local_1c;
  }
  iVar1 = osReadRegistryDword(0,"RMParamCopyNoLock",&local_1c);
  if (iVar1 == 0) {
    g_resServ[0x41] = local_1c != 0;
  }
  portMemSet(&g_RmApiLock,0,0x548);
  DAT_0054dd88 = 0xffffffffffffffff;
  uVar2 = portMemAllocatorGetGlobalNonPaged();
  g_RmApiLock = portSyncRwLockCreate(uVar2);
  if (g_RmApiLock != 0) {
    DAT_0054e2a0 = tlsEntryAlloc();
    iVar1 = rmapiControlCacheInit();
    if (iVar1 == 0) {
      RsResInfoInitialize();
      iVar1 = serverConstruct(g_resServ,3,0);
      if (iVar1 == 0) {
        serverSetClientHandleBase(g_resServ,0xc1d00000);
        listInit_IMPL(g_clientListBehindGpusLock,g_resServ._24_8_,8);
        listInit_IMPL(g_userInfoList,g_resServ._24_8_,8);
        multimapInit_IMPL(g_osInfoList,g_resServ._24_8_,8,8,0x10);
        rmapiInitStubInterface(g_RmApiList);
        g_RmApiList._216_4_ = 0;
        g_RmApiList[0xdc] = 0;
        g_RmApiList._224_8_ = 0;
        g_RmApiList._0_8_ = rmapiAlloc;
        g_RmApiList._8_8_ = rmapiAllocWithHandle;
        g_RmApiList._16_8_ = rmapiAllocWithSecInfoTls;
        g_RmApiList._40_8_ = rmapiDisableClients;
        g_RmApiList._48_8_ = rmapiDisableClientsWithSecInfoTls;
        g_RmApiList._24_8_ = rmapiFree;
        g_RmApiList._32_8_ = rmapiFreeWithSecInfoTls;
        g_RmApiList._56_8_ = rmapiControl;
        g_RmApiList._64_8_ = rmapiControlWithSecInfoTls;
        g_RmApiList._80_8_ = rmapiDupObject;
        g_RmApiList._88_8_ = rmapiDupObjectWithSecInfoTls;
        g_RmApiList._96_8_ = rmapiShare;
        g_RmApiList._104_8_ = rmapiShareWithSecInfoTls;
        g_RmApiList._112_8_ = rmapiMapToCpu;
        g_RmApiList._120_8_ = rmapiMapToCpuWithSecInfoTls;
        g_RmApiList._128_8_ = rmapiMapToCpuWithSecInfoTlsV2;
        g_RmApiList._136_8_ = rmapiUnmapFromCpu;
        g_RmApiList._144_8_ = rmapiUnmapFromCpuWithSecInfoTls;
        g_RmApiList._152_8_ = rmapiMap;
        g_RmApiList._160_8_ = rmapiMapWithSecInfoTls;
        g_RmApiList._168_8_ = rmapiUnmap;
        g_RmApiList._176_8_ = rmapiUnmapWithSecInfoTls;
        rmapiInitStubInterface(0x54e3c8);
        g_RmApiList._424_8_ = 0;
        g_RmApiList._416_8_ = 0x100000002;
        g_RmApiList._432_8_ = 0;
        g_RmApiList._440_8_ = 0;
        g_RmApiList._448_4_ = 1;
        g_RmApiList[0x1c4] = 0;
        g_RmApiList._456_8_ = 0;
        g_RmApiList._232_8_ = rmapiAlloc;
        g_RmApiList._240_8_ = rmapiAllocWithHandle;
        g_RmApiList._248_8_ = rmapiAllocWithSecInfoTls;
        g_RmApiList._272_8_ = rmapiDisableClients;
        g_RmApiList._280_8_ = rmapiDisableClientsWithSecInfoTls;
        g_RmApiList._256_8_ = rmapiFree;
        g_RmApiList._264_8_ = rmapiFreeWithSecInfoTls;
        g_RmApiList._288_8_ = rmapiControl;
        g_RmApiList._296_8_ = rmapiControlWithSecInfoTls;
        g_RmApiList._312_8_ = rmapiDupObject;
        g_RmApiList._320_8_ = rmapiDupObjectWithSecInfoTls;
        g_RmApiList._328_8_ = rmapiShare;
        g_RmApiList._336_8_ = rmapiShareWithSecInfoTls;
        g_RmApiList._344_8_ = rmapiMapToCpu;
        g_RmApiList._352_8_ = rmapiMapToCpuWithSecInfoTls;
        g_RmApiList._360_8_ = rmapiMapToCpuWithSecInfoTlsV2;
        g_RmApiList._368_8_ = rmapiUnmapFromCpu;
        g_RmApiList._376_8_ = rmapiUnmapFromCpuWithSecInfoTls;
        g_RmApiList._384_8_ = rmapiMap;
        g_RmApiList._392_8_ = rmapiMapWithSecInfoTls;
        g_RmApiList._400_8_ = rmapiUnmap;
        g_RmApiList._408_8_ = rmapiUnmapWithSecInfoTls;
        rmapiInitStubInterface(0x54e4b0);
        g_RmApiList._648_8_ = 0x100000002;
        g_RmApiList._656_8_ = 0;
        g_RmApiList._664_8_ = 0;
        g_RmApiList._672_8_ = 0;
        g_RmApiList._680_4_ = 0x1010001;
        g_RmApiList[0x2ac] = 1;
        g_RmApiList._688_8_ = 0;
        g_RmApiList._464_8_ = rmapiAlloc;
        g_RmApiList._472_8_ = rmapiAllocWithHandle;
        g_RmApiList._480_8_ = rmapiAllocWithSecInfoTls;
        g_RmApiList._504_8_ = rmapiDisableClients;
        g_RmApiList._512_8_ = rmapiDisableClientsWithSecInfoTls;
        g_RmApiList._488_8_ = rmapiFree;
        g_RmApiList._496_8_ = rmapiFreeWithSecInfoTls;
        g_RmApiList._520_8_ = rmapiControl;
        g_RmApiList._528_8_ = rmapiControlWithSecInfoTls;
        g_RmApiList._544_8_ = rmapiDupObject;
        g_RmApiList._552_8_ = rmapiDupObjectWithSecInfoTls;
        g_RmApiList._560_8_ = rmapiShare;
        g_RmApiList._568_8_ = rmapiShareWithSecInfoTls;
        g_RmApiList._576_8_ = rmapiMapToCpu;
        g_RmApiList._584_8_ = rmapiMapToCpuWithSecInfoTls;
        g_RmApiList._592_8_ = rmapiMapToCpuWithSecInfoTlsV2;
        g_RmApiList._600_8_ = rmapiUnmapFromCpu;
        g_RmApiList._608_8_ = rmapiUnmapFromCpuWithSecInfoTls;
        g_RmApiList._616_8_ = rmapiMap;
        g_RmApiList._624_8_ = rmapiMapWithSecInfoTls;
        g_RmApiList._632_8_ = rmapiUnmap;
        g_RmApiList._640_8_ = rmapiUnmapWithSecInfoTls;
        rmapiInitStubInterface(0x54e598);
        g_RmApiList._880_8_ = 0x100000002;
        g_RmApiList._888_8_ = 0;
        g_RmApiList._896_8_ = 0;
        g_RmApiList._904_8_ = 0;
        g_RmApiList._912_4_ = 0x1010101;
        g_RmApiList[0x394] = 0;
        g_RmApiList._920_8_ = 0;
        g_RmApiList._696_8_ = rmapiAlloc;
        g_RmApiList._704_8_ = rmapiAllocWithHandle;
        g_RmApiList._712_8_ = rmapiAllocWithSecInfo;
        g_RmApiList._736_8_ = rmapiDisableClients;
        g_RmApiList._744_8_ = rmapiDisableClientsWithSecInfo;
        g_RmApiList._720_8_ = rmapiFree;
        g_RmApiList._728_8_ = rmapiFreeWithSecInfo;
        g_RmApiList._752_8_ = rmapiControl;
        g_RmApiList._760_8_ = rmapiControlWithSecInfo;
        g_RmApiList._776_8_ = rmapiDupObject;
        g_RmApiList._784_8_ = rmapiDupObjectWithSecInfo;
        g_RmApiList._792_8_ = rmapiShare;
        g_RmApiList._800_8_ = rmapiShareWithSecInfo;
        g_RmApiList._808_8_ = rmapiMapToCpu;
        g_RmApiList._816_8_ = rmapiMapToCpuWithSecInfo;
        g_RmApiList._824_8_ = rmapiMapToCpuWithSecInfoV2;
        g_RmApiList._832_8_ = rmapiUnmapFromCpu;
        g_RmApiList._840_8_ = rmapiUnmapFromCpuWithSecInfo;
        g_RmApiList._848_8_ = rmapiMap;
        g_RmApiList._856_8_ = rmapiMapWithSecInfo;
        g_RmApiList._864_8_ = rmapiUnmap;
        g_RmApiList._872_8_ = rmapiUnmapWithSecInfo;
        rmapiInitStubInterface(0x54e680);
        g_RmApiList._1112_8_ = 0x100000002;
        g_RmApiList._1120_8_ = 0;
        g_RmApiList._1128_8_ = 0;
        g_RmApiList._1136_8_ = 0;
        g_RmApiList._1144_4_ = 0x1010101;
        g_RmApiList[0x47c] = 1;
        g_RmApiList._1152_8_ = 0;
        g_RmApiList._928_8_ = rmapiAlloc;
        g_RmApiList._936_8_ = rmapiAllocWithHandle;
        g_RmApiList._944_8_ = rmapiAllocWithSecInfo;
        g_RmApiList._968_8_ = rmapiDisableClients;
        g_RmApiList._976_8_ = rmapiDisableClientsWithSecInfo;
        g_RmApiList._952_8_ = rmapiFree;
        g_RmApiList._960_8_ = rmapiFreeWithSecInfo;
        g_RmApiList._984_8_ = rmapiControl;
        g_RmApiList._992_8_ = rmapiControlWithSecInfo;
        g_RmApiList._1008_8_ = rmapiDupObject;
        g_RmApiList._1016_8_ = rmapiDupObjectWithSecInfo;
        g_RmApiList._1024_8_ = rmapiShare;
        g_RmApiList._1032_8_ = rmapiShareWithSecInfo;
        g_RmApiList._1040_8_ = rmapiMapToCpu;
        g_RmApiList._1048_8_ = rmapiMapToCpuWithSecInfo;
        g_RmApiList._1056_8_ = rmapiMapToCpuWithSecInfoV2;
        g_RmApiList._1064_8_ = rmapiUnmapFromCpu;
        g_RmApiList._1072_8_ = rmapiUnmapFromCpuWithSecInfo;
        g_RmApiList._1080_8_ = rmapiMap;
        g_RmApiList._1088_8_ = rmapiMapWithSecInfo;
        g_RmApiList._1096_8_ = rmapiUnmap;
        g_RmApiList._1104_8_ = rmapiUnmapWithSecInfo;
        rmapiInitStubInterface(0x54e768);
        g_bResServInit = 1;
        return 0;
      }
      nvDbg_Printf("src/kernel/rmapi/rmapi.c",0x65,"rmapiInitialize",4,
                   "NVRM: *** Cannot initialize resource server\n");
      rmapiControlCacheFree();
    }
    else {
      nvDbg_Printf("src/kernel/rmapi/rmapi.c",0x5c,"rmapiInitialize",4,
                   "NVRM: *** Cannot initialize rmapi cache\n");
    }
    portSyncRwLockDestroy(g_RmApiLock);
    return iVar1;
  }
  nvDbg_Printf("src/kernel/rmapi/rmapi.c",0x55,"rmapiInitialize",4,
               "NVRM: *** Cannot allocate rmapi locks\n");
  return 0x1a;
}


// ===== 004b8150 rmapiShutdown =====

void rmapiShutdown(void)

{
  if (g_bResServInit == '\0') {
    return;
  }
  serverFreeDomain(g_resServ,0);
  serverDestruct(g_resServ);
  portSyncRwLockDestroy(g_RmApiLock);
  rmapiControlCacheFree();
  g_bResServInit = 0;
  return;
}


// ===== 004b81a0 rmapiGetInterface =====

undefined1 * rmapiGetInterface(uint param_1)

{
  return g_RmApiList + (ulong)param_1 * 0xe8;
}


// ===== 004b81c0 rmapiInitLockInfo =====

undefined8 rmapiInitLockInfo(long param_1,int param_2,int param_3,long *param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  int iVar6;
  undefined8 uVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  
  lVar9 = resservGetTlsCallContext();
  if (param_4 == (long *)0x0) {
    nvAssertFailedNoLog("pLockInfo != NULL","src/kernel/rmapi/rmapi.c",0x18c);
    return 0x40;
  }
  param_4[5] = 0;
  if (((param_2 == 0) || (lVar9 == 0)) || (*(long *)(lVar9 + 0x20) == 0)) goto LAB_004b82b0;
  *(undefined4 *)((long)param_4 + 0x2c) = *(undefined4 *)(*(long *)(lVar9 + 0x20) + 0x2c);
  uVar7 = g_resServ._72_8_;
  lVar10 = portThreadGetCurrentThreadId();
  if (uVar7 == lVar10) goto LAB_004b82b0;
  plVar4 = *(long **)(lVar9 + 0x20);
  lVar10 = *plVar4;
  if (lVar10 != 0) {
    iVar2 = *(int *)(lVar10 + 0x48);
    if (param_3 == 0) {
      if ((param_2 == iVar2) ||
         ((lVar10 = plVar4[1], lVar10 != 0 && (*(int *)(lVar10 + 0x48) == param_2)))) {
LAB_004b8384:
        *param_4 = lVar10;
        goto LAB_004b82b0;
      }
    }
    else {
      lVar5 = plVar4[1];
      if (lVar5 == 0) {
        if (param_2 == iVar2) {
          *param_4 = lVar10;
          if (param_3 == param_2) {
            param_4[1] = **(long **)(lVar9 + 0x20);
          }
          goto LAB_004b82b0;
        }
        if (param_3 == iVar2) goto LAB_004b8384;
      }
      else {
        iVar3 = *(int *)(lVar5 + 0x48);
        iVar6 = param_3;
        if ((param_2 != iVar2) && (iVar6 = param_2, param_3 != iVar2)) {
          uVar8 = *(uint *)((long)param_4 + 0x2c) & 0xffffff7f;
          if ((param_3 == iVar3) || (param_2 == iVar3)) {
            *param_4 = lVar5;
            *(uint *)((long)param_4 + 0x2c) = uVar8;
          }
          else {
            *(uint *)((long)param_4 + 0x2c) = uVar8;
          }
          goto LAB_004b82b0;
        }
        if (iVar6 == iVar3) {
          *param_4 = lVar10;
          param_4[1] = *(long *)(*(long *)(lVar9 + 0x20) + 8);
          goto LAB_004b82b0;
        }
        *param_4 = lVar10;
      }
    }
  }
  *(uint *)((long)param_4 + 0x2c) = *(uint *)((long)param_4 + 0x2c) & 0xffffff7f;
LAB_004b82b0:
  if (*(char *)(param_1 + 0xdb) == '\0') {
    *(uint *)(param_4 + 5) = *(uint *)(param_4 + 5) | 0x10;
    cVar1 = *(char *)(param_1 + 0xda);
  }
  else {
    cVar1 = *(char *)(param_1 + 0xda);
  }
  if (cVar1 != '\0') {
    *(uint *)((long)param_4 + 0x2c) = *(uint *)((long)param_4 + 0x2c) | 1;
    lVar9 = tlsEntryGet(DAT_0054e2a0);
    if (lVar9 != 0) {
      *(uint *)(param_4 + 5) = *(uint *)(param_4 + 5) | 2;
    }
  }
  if (*(char *)(param_1 + 0xdc) != '\0') {
    *(uint *)((long)param_4 + 0x2c) = *(uint *)((long)param_4 + 0x2c) | 0x40;
  }
  return 0;
}


// ===== 004b83f0 rmapiLockRelease =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rmapiLockRelease(void)

{
  long lVar1;
  char cVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  bool bVar7;
  undefined8 unaff_retaddr;
  
  lVar1 = g_pSys;
  bVar7 = false;
  lVar6 = 0;
  lVar3 = portThreadGetCurrentThreadId();
  if (*(char *)(lVar1 + 0x7d) != '\0') {
    lVar6 = tlsEntryGet(DAT_0054e2a0);
    bVar7 = lVar6 != 0;
  }
  lVar4 = osGetMonotonicTimeNs();
  uVar5 = (ulong)DAT_0054e298;
  *(undefined8 *)(&DAT_0054dd98 + uVar5 * 0x28) = 2;
  *(undefined8 *)(&DAT_0054dda8 + uVar5 * 0x28) = unaff_retaddr;
  *(undefined2 *)(&DAT_0054dda0 + uVar5 * 0x28) = 0;
  *(long *)(&DAT_0054ddb0 + uVar5 * 0x28) = lVar3;
  *(long *)(&DAT_0054ddb8 + uVar5 * 0x28) = lVar4;
  cVar2 = portSyncExSafeToSleep();
  uVar5 = (ulong)DAT_0054e298;
  (&DAT_0054dda2)[uVar5 * 0x28] = cVar2 == '\0';
  DAT_0054e298 = DAT_0054e298 + 1 & 0x1f;
  (&DAT_0054dda3)[uVar5 * 0x28] = 0;
  bVar7 = (bool)(*(char *)(lVar1 + 0x7d) != '\0' & bVar7);
  if (DAT_0054dd88 == lVar3) {
    DAT_0054dd88 = -1;
    if (bVar7) {
      LOCK();
      _DAT_0054e2b8 = _DAT_0054e2b8 + (lVar4 - lVar6);
      UNLOCK();
    }
    _DAT_0054dd90 = lVar4;
    portSyncRwLockReleaseWrite(g_RmApiLock);
  }
  else {
    if (bVar7) {
      LOCK();
      _DAT_0054e2c0 = _DAT_0054e2c0 + (lVar4 - lVar6);
      UNLOCK();
    }
    portSyncRwLockReleaseRead(g_RmApiLock);
  }
  tlsEntryRelease(DAT_0054e2a0);
  return;
}


// ===== 004b8550 rmapiLockAcquire =====

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 rmapiLockAcquire(uint param_1,uint param_2)

{
  long lVar1;
  char cVar2;
  ushort uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  undefined8 unaff_retaddr;
  long local_48;
  
  lVar1 = g_pSys;
  lVar5 = portThreadGetCurrentThreadId();
  if (g_RmApiLock == 0) {
    nvCheckFailedNoLog(4,"g_RmApiLock.pLock != NULL","src/kernel/rmapi/rmapi.c",0x231);
    return 0x55;
  }
  lVar6 = tlsEntryGet(DAT_0054e2a0);
  if (lVar6 == 0) {
    iVar4 = rmGpuLocksGetOwnedMask();
    if (iVar4 == 0) {
      if ((((param_1 & 2) == 0) || (param_2 == 0)) ||
         (((param_1 & 8) != 0 && (*(char *)(lVar1 + 0x83) != '\0')))) {
        cVar2 = *(char *)(lVar1 + 0x7d);
      }
      else {
        if ((*(uint *)(lVar1 + 0x90) & param_2 >> 8) == 0) {
          param_1 = param_1 & 0xfffffffd;
        }
        cVar2 = *(char *)(lVar1 + 0x7d);
      }
      if (cVar2 == '\0') {
        local_48 = 0;
        uVar3 = osApiLockAcquireConfigureFlags(param_1);
        iVar4 = DAT_0054e2ac;
      }
      else {
        local_48 = osGetMonotonicTimeNs();
        uVar3 = osApiLockAcquireConfigureFlags(param_1);
        iVar4 = DAT_0054e2ac;
      }
      lVar6 = lVar5;
      DAT_0054e2ac = iVar4;
      if ((uVar3 & 1) == 0) {
        if ((uVar3 & 2) == 0) {
          if ((uVar3 & 4) == 0) {
            LOCK();
            DAT_0054e2a8 = DAT_0054e2a8 + 1;
            UNLOCK();
            portSyncRwLockAcquireWrite(g_RmApiLock);
            LOCK();
            DAT_0054e2a8 = DAT_0054e2a8 + -1;
            UNLOCK();
          }
          else {
            portSyncRwLockAcquireWrite(g_RmApiLock);
            for (; (DAT_0054e2a8 != 0 && (iVar4 != 0)); iVar4 = iVar4 + -1) {
              portSyncRwLockReleaseWrite(g_RmApiLock);
              osDelay(10);
              portSyncRwLockAcquireWrite(g_RmApiLock);
            }
          }
        }
        else {
          portSyncRwLockAcquireRead(g_RmApiLock);
          lVar6 = DAT_0054dd88;
        }
      }
      else {
        if ((uVar3 & 2) == 0) {
          cVar2 = portSyncRwLockAcquireWriteConditional();
        }
        else {
          cVar2 = portSyncRwLockAcquireReadConditional(g_RmApiLock);
          lVar6 = DAT_0054dd88;
        }
        if (cVar2 == '\0') {
          return 0x66;
        }
      }
      DAT_0054dd88 = lVar6;
      lVar6 = osGetMonotonicTimeNs();
      if (*(char *)(lVar1 + 0x7d) != '\0') {
        LOCK();
        _DAT_0054e2b0 = _DAT_0054e2b0 + (lVar6 - local_48);
        UNLOCK();
      }
      if (DAT_0054dd88 == lVar5) {
        _DAT_0054dd90 = lVar6;
      }
      uVar7 = (ulong)DAT_0054e298;
      *(ulong *)(&DAT_0054dd98 + uVar7 * 0x28) = (ulong)param_2 << 0x20 | 1;
      *(undefined8 *)(&DAT_0054dda8 + uVar7 * 0x28) = unaff_retaddr;
      *(ushort *)(&DAT_0054dda0 + uVar7 * 0x28) = uVar3;
      *(long *)(&DAT_0054ddb0 + uVar7 * 0x28) = lVar5;
      *(long *)(&DAT_0054ddb8 + uVar7 * 0x28) = lVar6;
      cVar2 = portSyncExSafeToSleep();
      uVar7 = (ulong)DAT_0054e298;
      (&DAT_0054dda2)[uVar7 * 0x28] = cVar2 == '\0';
      DAT_0054e298 = DAT_0054e298 + 1 & 0x1f;
      (&DAT_0054dda3)[uVar7 * 0x28] = 0;
      uVar7 = threadStateGetSetupFlags();
      if ((uVar7 & 0x80) != 0) {
        threadStateResetTimeout(0);
      }
      puVar8 = (undefined8 *)tlsEntryAcquire(DAT_0054e2a0);
      if (puVar8 != (undefined8 *)0x0) {
        uVar9 = osGetMonotonicTimeNs();
        *puVar8 = uVar9;
        return 0;
      }
      rmapiLockRelease();
      return 0x1a;
    }
    nvAssertFailedNoLog("rmGpuLocksGetOwnedMask() == 0","src/kernel/rmapi/rmapi.c",0x236);
  }
  else {
    nvAssertFailedNoLog("!rmapiLockIsOwner()","src/kernel/rmapi/rmapi.c",0x233);
  }
  return 0x2f;
}


// ===== 004b8900 rmapiPrologue =====

int rmapiPrologue(long param_1,uint *param_2)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c [3];
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pRmApi != NULL","src/kernel/rmapi/rmapi.c",0x128);
    return 0x1f;
  }
  if (param_2 == (uint *)0x0) {
    nvAssertFailedNoLog("pContext != NULL","src/kernel/rmapi/rmapi.c",0x129);
    return 0x1f;
  }
  if (*(char *)(param_1 + 0xd9) != '\0') {
    return 0;
  }
  iVar3 = osGetDynamicPowerSupportMask();
  if (iVar3 == 0) {
    return 0;
  }
  lVar4 = tlsEntryGet(DAT_0054e2a0);
  if (lVar4 == 0) {
    iVar3 = rmapiLockAcquire(2,0x200);
    if (iVar3 != 0) {
      return iVar3;
    }
    local_34 = 0;
    local_30 = 0;
    iVar3 = gpumgrGetGpuAttachInfo(0,&local_34);
    if (iVar3 != 0) goto LAB_004b8ad4;
    bVar2 = true;
  }
  else {
    local_34 = 0;
    local_30 = 0;
    iVar3 = gpumgrGetGpuAttachInfo(0,&local_34);
    if (iVar3 != 0) {
      return iVar3;
    }
    bVar2 = false;
  }
LAB_004b89b6:
  lVar4 = gpumgrGetNextGpu(local_34,&local_30);
  if (lVar4 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = osRefGpuAccessNeeded(*(undefined8 *)(lVar4 + 0x4e0));
    if (iVar3 == 0) goto code_r0x004b89a6;
    local_2c[0] = 0;
    uVar1 = *param_2;
    while (lVar4 = gpumgrGetNextGpu(uVar1,local_2c), lVar4 != 0) {
      osUnrefGpuAccessNeeded(*(undefined8 *)(lVar4 + 0x4e0));
    }
  }
  if (!bVar2) {
    return iVar3;
  }
LAB_004b8ad4:
  rmapiLockRelease();
  return iVar3;
code_r0x004b89a6:
  *param_2 = *param_2 | 1 << ((byte)*(undefined4 *)(lVar4 + 0x7a4) & 0x1f);
  goto LAB_004b89b6;
}


// ===== 004b8af0 rmapiEpilogue =====

void rmapiEpilogue(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  undefined4 local_1c;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pRmApi != NULL","src/kernel/rmapi/rmapi.c",0x15e);
    return;
  }
  if (param_2 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pContext != NULL","src/kernel/rmapi/rmapi.c",0x15f);
    return;
  }
  if (*(char *)(param_1 + 0xd9) == '\0') {
    iVar3 = osGetDynamicPowerSupportMask();
    if (iVar3 == 0) {
      return;
    }
    lVar4 = tlsEntryGet(DAT_0054e2a0);
    bVar2 = false;
    if (lVar4 == 0) {
      iVar3 = rmapiLockAcquire(2,0x200);
      if (iVar3 != 0) {
        return;
      }
      bVar2 = true;
    }
    local_1c = 0;
    uVar1 = *param_2;
    while (lVar4 = gpumgrGetNextGpu(uVar1,&local_1c), lVar4 != 0) {
      osUnrefGpuAccessNeeded(*(undefined8 *)(lVar4 + 0x4e0));
    }
    if (bVar2) {
      rmapiLockRelease();
      return;
    }
  }
  return;
}


// ===== 004b8c10 rmapiLockIsOwner =====

bool rmapiLockIsOwner(void)

{
  long lVar1;
  
  lVar1 = tlsEntryGet(DAT_0054e2a0);
  return lVar1 != 0;
}


// ===== 004b8c30 rmapiLockIsWriteOwner =====

bool rmapiLockIsWriteOwner(void)

{
  long lVar1;
  long lVar2;
  
  lVar1 = portThreadGetCurrentThreadId();
  lVar2 = tlsEntryGet(DAT_0054e2a0);
  if (lVar2 != 0) {
    return DAT_0054dd88 == lVar1;
  }
  return false;
}


// ===== 004b8c80 rmapiLockGetTimes =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rmapiLockGetTimes(undefined8 *param_1)

{
  *param_1 = _DAT_0054e2b0;
  param_1[1] = _DAT_0054e2c0;
  param_1[2] = _DAT_0054e2b8;
  return;
}


// ===== 004b8cb0 rmapiEnterRtd3PmPath =====

void rmapiEnterRtd3PmPath(void)

{
  char cVar1;
  
  cVar1 = rmGpuLockIsOwner();
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("rmGpuLockIsOwner()","src/kernel/rmapi/rmapi.c",0x318);
  }
  if (g_rtd3PmPathThreadId != -1) {
    nvAssertFailedNoLog("g_rtd3PmPathThreadId == ~0ULL","src/kernel/rmapi/rmapi.c",0x31a);
    g_rtd3PmPathThreadId = portThreadGetCurrentThreadId();
    return;
  }
  g_rtd3PmPathThreadId = portThreadGetCurrentThreadId();
  return;
}


// ===== 004b8d30 rmapiLeaveRtd3PmPath =====

void rmapiLeaveRtd3PmPath(void)

{
  long lVar1;
  
  lVar1 = portThreadGetCurrentThreadId();
  if (lVar1 == g_rtd3PmPathThreadId) {
    g_rtd3PmPathThreadId = 0xffffffffffffffff;
    return;
  }
  nvAssertFailedNoLog("rmapiInRtd3PmPath()","src/kernel/rmapi/rmapi.c",0x324);
  g_rtd3PmPathThreadId = 0xffffffffffffffff;
  return;
}


// ===== 004b8d80 rmapiInRtd3PmPath =====

bool rmapiInRtd3PmPath(void)

{
  long lVar1;
  
  lVar1 = portThreadGetCurrentThreadId();
  return g_rtd3PmPathThreadId == lVar1;
}


// ===== 004b8da0 rmapiSetDelPendingClientResourcesFromGpuMask =====

void rmapiSetDelPendingClientResourcesFromGpuMask(uint param_1)

{
  long lVar1;
  char cVar2;
  long *plVar3;
  long lVar4;
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
  
  plVar3 = (long *)serverutilGetFirstClientUnderLock();
  do {
    if (plVar3 == (long *)0x0) {
      return;
    }
    lVar1 = *plVar3;
    uVar5 = 0;
    if (lVar1 != 0) {
      uVar5 = *(undefined8 *)(lVar1 + 0x100);
    }
    clientRefIter(&local_c8,uVar5,0,&DAT_00e0ac20,0,1);
    local_70 = local_c8;
    local_68 = local_c0;
    local_60 = local_b8;
    local_58 = local_b0;
    local_50 = local_a8;
    local_48 = local_a0;
    local_40 = local_98;
    local_38 = local_90;
    local_30 = local_88;
    do {
      cVar2 = clientRefIterNext(local_50);
      if (cVar2 == '\0') goto LAB_004b8eb2;
      lVar4 = __nvoc_dynamicCast(*(undefined8 *)(local_38 + 8));
    } while ((lVar4 == 0) ||
            ((1 << ((byte)*(undefined4 *)(*(long *)(*(long *)(lVar4 + 0x128) + 0xe0) + 0x7a4) & 0x1f
                   ) & param_1) == 0));
    *(uint *)(lVar1 + 0x188) = *(uint *)(lVar1 + 0x188) | 2;
LAB_004b8eb2:
    plVar3 = (long *)serverutilGetNextClientUnderLock(plVar3);
  } while( true );
}


// ===== 004b8ee0 rmapiDelPendingDevices =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void rmapiDelPendingDevices(uint param_1)

{
  long lVar1;
  char cVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  long local_a0;
  undefined8 local_98;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  undefined8 local_40;
  
  plVar3 = (long *)serverutilGetFirstClientUnderLock();
  do {
    if (plVar3 == (long *)0x0) {
      return;
    }
LAB_004b8f2c:
    lVar1 = *plVar3;
    lVar5 = 0;
    if (lVar1 != 0) {
      lVar5 = *(long *)(lVar1 + 0x100);
    }
    if (((*(byte *)(lVar1 + 0x188) & 2) != 0) &&
       (cVar2 = serverIsClientInternal(g_resServ,*(undefined4 *)(lVar5 + 0x48)), cVar2 == '\0')) {
      do {
        clientRefIter(&local_d8,lVar5,0,&DAT_00e0ac20,0,1);
        local_80 = local_d8;
        local_78 = local_d0;
        local_70 = local_c8;
        local_68 = local_c0;
        local_60 = local_b8;
        local_58 = local_b0;
        local_50 = local_a8;
        local_48 = local_a0;
        local_40 = local_98;
        do {
          cVar2 = clientRefIterNext(lVar5,&local_80);
          lVar1 = local_48;
          if (cVar2 == '\0') {
            plVar3 = (long *)serverutilGetNextClientUnderLock(plVar3);
            if (plVar3 == (long *)0x0) {
              return;
            }
            goto LAB_004b8f2c;
          }
          lVar4 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),__nvoc_class_def_Device);
        } while ((1 << ((byte)*(undefined4 *)(*(long *)(*(long *)(lVar4 + 0x128) + 0xe0) + 0x7a4) &
                       0x1f) & param_1) == 0);
        (*(code *)g_RmApiList._952_8_)
                  (0x54e680,*(undefined4 *)(lVar5 + 0x48),*(undefined4 *)(lVar1 + 0x10));
      } while( true );
    }
    plVar3 = (long *)serverutilGetNextClientUnderLock(plVar3);
  } while( true );
}


// ===== 004b9090 rmapiReportInternalLeakedDevices =====

void rmapiReportInternalLeakedDevices(uint param_1)

{
  long lVar1;
  char cVar2;
  long *plVar3;
  undefined8 extraout_RDX;
  undefined8 uVar4;
  undefined8 extraout_RDX_00;
  long lVar5;
  undefined1 auVar6 [16];
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  long local_a0;
  undefined8 local_98;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  undefined8 local_40;
  
  for (plVar3 = (long *)serverutilGetFirstClientUnderLock(); plVar3 != (long *)0x0;
      plVar3 = (long *)serverutilGetNextClientUnderLock(plVar3)) {
    lVar5 = 0;
    if (*plVar3 != 0) {
      lVar5 = *(long *)(*plVar3 + 0x100);
    }
    clientRefIter(&local_d8,lVar5,0,&DAT_00e0ac20,0,1);
    local_80 = local_d8;
    local_78 = local_d0;
    local_70 = local_c8;
    local_68 = local_c0;
    local_60 = local_b8;
    local_58 = local_b0;
    local_50 = local_a8;
    local_48 = local_a0;
    local_40 = local_98;
    uVar4 = extraout_RDX;
    while (cVar2 = clientRefIterNext(lVar5,&local_80,uVar4), lVar1 = local_48, cVar2 != '\0') {
      auVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),__nvoc_class_def_Device);
      uVar4 = auVar6._8_8_;
      if ((1 << ((byte)*(undefined4 *)(*(long *)(*(long *)(auVar6._0_8_ + 0x128) + 0xe0) + 0x7a4) &
                0x1f) & param_1) != 0) {
        uStack_e0 = 0x4b91e7;
        cVar2 = serverIsClientInternal(g_resServ,*(undefined4 *)(lVar5 + 0x48));
        uVar4 = extraout_RDX_00;
        if (cVar2 != '\0') {
          nvDbg_Printf("src/kernel/rmapi/rmapi.c",0x3ad,"rmapiReportInternalLeakedDevices",4,
                       "NVRM: Internal device object leak: (0x%x, 0x%x). Please file a bug against RM-core.\n"
                       ,*(undefined4 *)(lVar5 + 0x48),*(undefined4 *)(lVar1 + 0x10));
          nvAssertFailedNoLog(&DAT_00d96955,"src/kernel/rmapi/rmapi.c",0x3b0);
          uVar4 = uStack_e0;
        }
      }
    }
  }
  return;
}


// ===== 004b9240 rmapiReportLeakedDevices =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void rmapiReportLeakedDevices(uint param_1)

{
  long lVar1;
  char cVar2;
  long *plVar3;
  undefined8 extraout_RDX;
  undefined8 uVar4;
  undefined8 extraout_RDX_00;
  long lVar5;
  undefined1 auVar6 [16];
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  long local_a0;
  undefined8 local_98;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  undefined8 local_40;
  
  for (plVar3 = (long *)serverutilGetFirstClientUnderLock(); plVar3 != (long *)0x0;
      plVar3 = (long *)serverutilGetNextClientUnderLock(plVar3)) {
    lVar5 = 0;
    if (*plVar3 != 0) {
      lVar5 = *(long *)(*plVar3 + 0x100);
    }
    clientRefIter(&local_d8,lVar5,0,&DAT_00e0ac20,0,1);
    local_80 = local_d8;
    local_78 = local_d0;
    local_70 = local_c8;
    local_68 = local_c0;
    local_60 = local_b8;
    local_58 = local_b0;
    local_50 = local_a8;
    local_48 = local_a0;
    local_40 = local_98;
    uVar4 = extraout_RDX;
    while (cVar2 = clientRefIterNext(lVar5,&local_80,uVar4), lVar1 = local_48, cVar2 != '\0') {
      auVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),__nvoc_class_def_Device);
      uVar4 = auVar6._8_8_;
      if ((1 << ((byte)*(undefined4 *)(*(long *)(*(long *)(auVar6._0_8_ + 0x128) + 0xe0) + 0x7a4) &
                0x1f) & param_1) != 0) {
        uStack_e0 = 0x4b9397;
        cVar2 = serverIsClientInternal(g_resServ,*(undefined4 *)(lVar5 + 0x48));
        uVar4 = extraout_RDX_00;
        if (cVar2 == '\0') {
          nvDbg_Printf("src/kernel/rmapi/rmapi.c",0x3d8,"rmapiReportLeakedDevices",4,
                       "NVRM: Device object leak: (0x%x, 0x%x). Please file a bug against RM-core.\n"
                       ,*(undefined4 *)(lVar5 + 0x48),*(undefined4 *)(lVar1 + 0x10));
          nvAssertFailedNoLog(&DAT_00d96955,"src/kernel/rmapi/rmapi.c",0x3db);
          (*(code *)g_RmApiList._952_8_)
                    (0x54e680,*(undefined4 *)(lVar5 + 0x48),*(undefined4 *)(lVar1 + 0x10));
          clientRefIter(&local_d8,lVar5,0,&DAT_00e0ac20,0,1);
          local_80 = local_d8;
          local_78 = local_d0;
          local_70 = local_c8;
          local_68 = local_c0;
          local_60 = local_b8;
          local_58 = local_b0;
          local_50 = local_a8;
          local_48 = local_a0;
          local_40 = local_98;
          uVar4 = uStack_e0;
        }
      }
    }
  }
  return;
}


// ===== 004b9490 rmapiDelPendingClients =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void rmapiDelPendingClients(void)

{
  long lVar1;
  char cVar2;
  long *plVar3;
  long lVar4;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  plVar3 = (long *)serverutilGetFirstClientUnderLock();
  while (plVar3 != (long *)0x0) {
    lVar1 = *plVar3;
    lVar4 = 0;
    if (lVar1 != 0) {
      lVar4 = *(long *)(lVar1 + 0x100);
    }
    plVar3 = (long *)serverutilGetNextClientUnderLock(plVar3);
    if ((*(byte *)(lVar1 + 0x188) & 2) != 0) {
      clientRefIter(&local_c8,lVar4,0,&DAT_00e0ac20,0,1);
      local_70 = local_c8;
      local_68 = local_c0;
      local_60 = local_b8;
      local_58 = local_b0;
      local_50 = local_a8;
      local_48 = local_a0;
      local_40 = local_98;
      local_38 = local_90;
      local_30 = local_88;
      cVar2 = clientRefIterNext(lVar4,&local_70);
      if (cVar2 == '\0') {
        (*(code *)g_RmApiList._952_8_)
                  (0x54e680,*(undefined4 *)(lVar4 + 0x48),*(undefined4 *)(lVar4 + 0x48));
      }
    }
  }
  return;
}


// ===== 004b95c0 rmapiGetClientHandlesFromOSInfo =====

undefined8 rmapiGetClientHandlesFromOSInfo(long param_1,undefined8 *param_2,uint *param_3)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined4 *puVar7;
  long lVar8;
  long *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  long *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  *param_3 = 0;
  *param_2 = 0;
  lVar3 = multimapFindSubmap_IMPL(g_osInfoList,param_1);
  if (lVar3 == 0) {
    return 0x10006;
  }
  uVar2 = mapCount_IMPL(lVar3);
  nvDbg_Printf("src/kernel/rmapi/rmapi.c",0x427,"rmapiGetClientHandlesFromOSInfo",1,
               "NVRM: *** Found %d clients for %llx\n",uVar2,param_1);
  if (uVar2 != 0) {
    puVar4 = (undefined4 *)portMemAllocNonPaged((ulong)uVar2 * 4);
    if (puVar4 == (undefined4 *)0x0) {
      return 0x51;
    }
    *param_3 = uVar2;
    *param_2 = puVar4;
    uVar5 = mapFindLEQ_IMPL(lVar3,0xffffffffffffffff);
    uVar6 = mapFindGEQ_IMPL(lVar3,0);
    multimapItemIterRange_IMPL(&local_78,g_osInfoList,uVar6,uVar5);
    local_58 = local_78;
    local_50 = local_70;
    local_48 = local_68;
    local_40 = local_60;
    puVar7 = puVar4;
    while( true ) {
      cVar1 = multimapItemIterNext_IMPL(&local_58);
      if (cVar1 == '\0') {
        return 0;
      }
      if (puVar7 == puVar4 + uVar2) break;
      lVar8 = 0;
      lVar3 = *local_58;
      if (lVar3 != 0) {
        lVar8 = *(long *)(lVar3 + 0x100);
      }
      if (*(long *)(lVar3 + 400) != param_1) {
        nvCheckFailedNoLog(4,"*** OS info mismatch","src/kernel/rmapi/rmapi.c",0x442);
      }
      *puVar7 = *(undefined4 *)(lVar8 + 0x48);
      nvDbg_Printf("src/kernel/rmapi/rmapi.c",0x445,"rmapiGetClientHandlesFromOSInfo",1,
                   "NVRM: *** Found: %x\n");
      puVar7 = puVar7 + 1;
    }
    nvAssertFailedNoLog("clientHandleListSize > k","src/kernel/rmapi/rmapi.c",0x43d);
    return 0;
  }
  nvAssertFailedNoLog("Empty client handle submap","src/kernel/rmapi/rmapi.c",0x42b);
  return 0x40;
}


// ===== 004b9800 _rmapiControlCacheGetGpuAttrForObject =====

undefined8
_rmapiControlCacheGetGpuAttrForObject
          (uint param_1,ulong param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  param_2 = param_2 & 0xffffffff;
  puVar1 = (undefined8 *)mapFind_IMPL(0x54e9b0,(ulong)param_1 << 0x20 | param_2);
  nvDbg_Printf("src/kernel/rmapi/rmapi_cache.c",0x112,"_rmapiControlCacheGetGpuAttrForObject",1,
               "NVRM: cached gpu attr lookup for 0x%x 0x%x\n",param_1,param_2);
  uVar2 = 0x57;
  if (puVar1 != (undefined8 *)0x0) {
    nvDbg_Printf("src/kernel/rmapi/rmapi_cache.c",0x116,"_rmapiControlCacheGetGpuAttrForObject",1,
                 "NVRM: cached gpu attr for 0x%x 0x%x: 0x%llx\n",param_1,param_2,*puVar1);
    *param_3 = (int)*puVar1;
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *(undefined4 *)((long)puVar1 + 4);
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 004b98d0 _setCacheEntry =====

long * _setCacheEntry(undefined8 param_1,undefined8 param_2,uint param_3,undefined4 param_4,
                     undefined1 *param_5)

{
  long *plVar1;
  long lVar2;
  ulong uVar3;
  long local_48;
  
  uVar3 = (ulong)param_3;
  plVar1 = (long *)multimapFindItem_IMPL(RmapiControlCache,param_1,param_2);
  local_48 = 0;
  if (plVar1 == (long *)0x0) {
    local_48 = 0;
    lVar2 = multimapFindSubmap_IMPL(RmapiControlCache,param_1);
    if (lVar2 == 0) {
      local_48 = multimapInsertSubmap_IMPL(RmapiControlCache,param_1);
      if (local_48 == 0) {
        return (long *)0x0;
      }
      plVar1 = (long *)multimapInsertItemNew_IMPL(RmapiControlCache,param_1,param_2);
      if (plVar1 == (long *)0x0) goto LAB_004b99fe;
    }
    else {
      plVar1 = (long *)multimapInsertItemNew_IMPL(RmapiControlCache,param_1,param_2);
      if (plVar1 == (long *)0x0) {
        return (long *)0x0;
      }
    }
  }
  if (*plVar1 != 0) {
    if (param_5 != (undefined1 *)0x0) {
      *param_5 = 0;
      return plVar1;
    }
    return plVar1;
  }
  lVar2 = portMemAllocNonPaged(uVar3);
  *plVar1 = lVar2;
  if (lVar2 != 0) {
    portMemSet(lVar2,0,uVar3);
    plVar1[1] = uVar3;
    *(undefined4 *)(plVar1 + 2) = param_4;
    if (param_5 != (undefined1 *)0x0) {
      *param_5 = 1;
      return plVar1;
    }
    return plVar1;
  }
  multimapRemoveItem_IMPL(RmapiControlCache,plVar1);
  if (local_48 == 0) {
    return (long *)0x0;
  }
LAB_004b99fe:
  multimapRemoveSubmap_IMPL(RmapiControlCache,local_48);
  return (long *)0x0;
}


// ===== 004b9a40 _rmapiControlCacheGetCacheable =====

undefined8
_rmapiControlCacheGetCacheable
          (undefined4 param_1,undefined4 param_2,uint param_3,undefined8 param_4,uint param_5)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 local_3c [3];
  
  portSyncRwLockAcquireRead(RmapiControlCache._88_8_);
  if (RmapiControlCache._80_4_ == 0) {
LAB_004b9ae0:
    uVar3 = 0x40;
  }
  else {
    uVar4 = 0x20;
    if (param_3 >> 0x10 == 0) {
LAB_004b9a81:
      plVar2 = (long *)multimapFindItem_IMPL(RmapiControlCache,uVar4,param_3);
      if ((plVar2 != (long *)0x0) && (*plVar2 != 0)) {
        if (((*(byte *)((long)plVar2 + 0x11) & 4) != 0) && (plVar2[1] != 0)) {
          uVar3 = 2;
          if ((ulong)plVar2[1] <= (ulong)param_5) {
            uVar3 = 0;
            portMemCopy(param_4);
          }
          goto LAB_004b9ac2;
        }
        goto LAB_004b9ae0;
      }
    }
    else {
      iVar1 = _rmapiControlCacheGetGpuAttrForObject(param_1,param_2,local_3c,0);
      uVar4 = local_3c[0];
      if (iVar1 == 0) goto LAB_004b9a81;
    }
    uVar3 = 0x57;
  }
LAB_004b9ac2:
  portSyncRwLockReleaseRead(RmapiControlCache._88_8_);
  return uVar3;
}


// ===== 004b9b20 _freeSubmap.constprop.0 =====

void _freeSubmap_constprop_0(undefined8 param_1,char param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  char cVar4;
  int iVar5;
  undefined8 *local_48 [5];
  
  do {
    uVar1 = mapFindLEQ_IMPL(param_1,0xffffffffffffffff);
    uVar2 = mapFindGEQ_IMPL(param_1,0);
    multimapItemIterRange_IMPL(local_48,RmapiControlCache,uVar2,uVar1);
    cVar4 = multimapItemIterNext_IMPL(local_48);
    if (cVar4 == '\0') {
      iVar5 = mapCount_IMPL(param_1);
joined_r0x004b9bd9:
      if (iVar5 != 0) {
        return;
      }
      multimapRemoveSubmap_IMPL(RmapiControlCache,param_1);
      return;
    }
    if (((*(byte *)((long)local_48[0] + 0x12) & 0x80) != 0) && (param_2 == '\0')) {
      do {
        cVar4 = multimapItemIterNext_IMPL(local_48);
        if (cVar4 == '\0') {
          iVar5 = mapCount_IMPL(param_1);
          goto joined_r0x004b9bd9;
        }
      } while ((*(byte *)((long)local_48[0] + 0x12) & 0x80) != 0);
    }
    puVar3 = local_48[0];
    portMemFree(*local_48[0]);
    multimapRemoveItem_IMPL(RmapiControlCache,puVar3);
  } while( true );
}


// ===== 004b9c00 _isGetInfoIndexCacheable.isra.0 =====

bool _isGetInfoIndexCacheable_isra_0(int param_1,uint param_2)

{
  if (param_1 == 0x20801109) {
    return param_2 < 6;
  }
  if (param_1 == 0x20801823) {
    if (param_2 < 0x2f) {
      return (0x500000099847U >> ((ulong)param_2 & 0x3f) & 1) != 0;
    }
  }
  else {
    if (param_1 == 0x20800810) {
      return param_2 < 2;
    }
    if (param_2 < 0x3e) {
      return (0x30f01aa4880c0016U >> ((ulong)param_2 & 0x3f) & 1) != 0;
    }
  }
  return false;
}


// ===== 004b9c80 _getInfoCacheHandler =====

undefined8
_getInfoCacheHandler
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint *param_5
          ,uint param_6,uint param_7,char param_8)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  long extraout_RDX;
  uint *puVar4;
  long lVar5;
  undefined8 uVar6;
  uint *local_58;
  long *local_50;
  undefined4 local_40;
  undefined1 local_3c [12];
  
  if (param_7 <= param_6 - 1) {
    return 0x3b;
  }
  if (param_8 != '\0') {
    portSyncRwLockAcquireWrite(RmapiControlCache._88_8_);
    uVar6 = 0x40;
    if (RmapiControlCache._80_4_ == 0) goto LAB_004b9d29;
    iVar3 = _rmapiControlCacheGetGpuAttrForObject(param_1,param_2,&local_40,local_3c);
    if (iVar3 != 0) {
      uVar6 = 0x57;
      goto LAB_004b9d29;
    }
    local_50 = (long *)_setCacheEntry(local_40,param_3,param_7 * 8,param_4,0);
    if (local_50 == (long *)0x0) {
      uVar6 = 0x51;
      goto LAB_004b9d29;
    }
    lVar5 = *local_50;
    if (lVar5 == 0) {
      uVar6 = 0x51;
    }
    else if ((*(byte *)((long)local_50 + 0x12) & 2) != 0) goto LAB_004b9da7;
LAB_004b9e8e:
    portMemFree(lVar5);
    multimapRemoveItem_IMPL(RmapiControlCache,local_50);
LAB_004b9d29:
    portSyncRwLockReleaseWrite(RmapiControlCache._88_8_);
    return uVar6;
  }
  portSyncRwLockAcquireRead();
  if (RmapiControlCache._80_4_ != 0) {
    iVar3 = _rmapiControlCacheGetGpuAttrForObject(param_1,param_2,&local_40,local_3c);
    if (((iVar3 != 0) ||
        (local_50 = (long *)multimapFindItem_IMPL(RmapiControlCache,local_40,param_3),
        local_50 == (long *)0x0)) || (lVar5 = *local_50, lVar5 == 0)) {
LAB_004b9e20:
      uVar6 = 0x57;
      goto LAB_004b9ce4;
    }
    if ((*(byte *)((long)local_50 + 0x12) & 2) != 0) {
LAB_004b9da7:
      puVar4 = param_5;
      do {
        if (param_7 <= *puVar4) {
          if (param_8 != '\0') {
            uVar6 = 0x1f;
            lVar5 = *local_50;
            goto LAB_004b9e8e;
          }
          uVar6 = 0x1f;
          goto LAB_004b9ce4;
        }
        cVar2 = _isGetInfoIndexCacheable_isra_0(param_3,*puVar4);
        if (param_8 == '\0') {
          if ((cVar2 == '\0') || (*(char *)(lVar5 + extraout_RDX * 8) == '\0')) goto LAB_004b9e20;
        }
        else if (cVar2 != '\0') {
          pcVar1 = (char *)(lVar5 + extraout_RDX * 8);
          if (*pcVar1 == '\0') {
            *pcVar1 = '\x01';
            *(uint *)(pcVar1 + 4) = puVar4[1];
          }
          else if (*(uint *)(pcVar1 + 4) != puVar4[1]) {
            nvAssertFailedNoLog("cachedTable[index].data == pInfo[i].data",
                                "src/kernel/rmapi/rmapi_cache.c",0x345);
          }
        }
        puVar4 = puVar4 + 2;
      } while (param_5 + (ulong)param_6 * 2 != puVar4);
      local_58 = param_5;
      if (param_8 != '\0') {
        uVar6 = 0;
        goto LAB_004b9d29;
      }
      do {
        puVar4 = local_58 + 2;
        local_58[1] = *(uint *)(lVar5 + 4 + (ulong)*local_58 * 8);
        local_58 = puVar4;
      } while (param_5 + (ulong)param_6 * 2 != puVar4);
      uVar6 = 0;
      goto LAB_004b9ce4;
    }
  }
  uVar6 = 0x40;
LAB_004b9ce4:
  portSyncRwLockReleaseRead(RmapiControlCache._88_8_);
  return uVar6;
}


// ===== 004b9f80 _getCePceMaskHandler =====

undefined4
_getCePceMaskHandler
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,int *param_5,
          char param_6)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  long *plVar4;
  undefined4 uVar5;
  ulong uVar6;
  undefined4 local_3c [3];
  
  if ((9 < param_4 - 0x34) && (9 < param_4 - 9)) {
    return 0x1f;
  }
  uVar2 = param_4 - 9;
  if (0x12 < param_4) {
    uVar2 = param_4 - 0x2a;
  }
  uVar6 = (ulong)uVar2;
  if (param_6 != '\0') {
    portSyncRwLockAcquireWrite(RmapiControlCache._88_8_);
    uVar5 = 0x40;
    if (RmapiControlCache._80_4_ != 0) {
      iVar3 = _rmapiControlCacheGetGpuAttrForObject(param_1,param_2,local_3c,0);
      if (iVar3 == 0) {
        plVar4 = (long *)_setCacheEntry(local_3c[0],0x20802a02,0x200,param_3,0);
        if (plVar4 == (long *)0x0) {
          uVar5 = 0x51;
        }
        else {
          lVar1 = *plVar4;
          if (lVar1 == 0) {
            uVar5 = 0x51;
          }
          else {
            if ((*(byte *)((long)plVar4 + 0x12) & 2) != 0) {
              uVar5 = 0;
              if (*(char *)(lVar1 + uVar6 * 8) == '\0') {
                *(undefined1 *)(lVar1 + uVar6 * 8) = 1;
                *(int *)(lVar1 + 4 + uVar6 * 8) = *param_5;
              }
              else if (*param_5 != *(int *)(lVar1 + 4 + uVar6 * 8)) {
                nvAssertFailedNoLog("*pceMask == cachedTable[ceEngineIndex].pceMask",
                                    "src/kernel/rmapi/rmapi_cache.c",0x4d5);
              }
              goto LAB_004ba028;
            }
            uVar5 = 0x40;
            portMemFree();
          }
          multimapRemoveItem_IMPL(RmapiControlCache,plVar4);
        }
      }
      else {
        uVar5 = 0x57;
      }
    }
LAB_004ba028:
    portSyncRwLockReleaseWrite(RmapiControlCache._88_8_);
    return uVar5;
  }
  portSyncRwLockAcquireRead();
  if (RmapiControlCache._80_4_ == 0) {
LAB_004b9fe5:
    uVar5 = 0x40;
  }
  else {
    iVar3 = _rmapiControlCacheGetGpuAttrForObject(param_1,param_2,local_3c,0);
    if (iVar3 == 0) {
      plVar4 = (long *)multimapFindItem_IMPL(RmapiControlCache,local_3c[0],0x20802a02);
      if ((plVar4 == (long *)0x0) || (lVar1 = *plVar4, lVar1 == 0)) {
        uVar5 = 0x51;
        goto LAB_004b9fea;
      }
      if ((*(byte *)((long)plVar4 + 0x12) & 2) == 0) goto LAB_004b9fe5;
      if (*(char *)(lVar1 + uVar6 * 8) != '\0') {
        *param_5 = *(int *)(lVar1 + 4 + uVar6 * 8);
        uVar5 = 0;
        goto LAB_004b9fea;
      }
    }
    uVar5 = 0x57;
  }
LAB_004b9fea:
  portSyncRwLockReleaseRead(RmapiControlCache._88_8_);
  return uVar5;
}


// ===== 004ba1d0 _getCePhysicalCapsHandler =====

undefined4
_getCePhysicalCapsHandler
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined8 param_5,
          char param_6)

{
  uint uVar1;
  int iVar2;
  long *plVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 local_3c [3];
  
  if ((9 < param_4 - 0x34) && (9 < param_4 - 9)) {
    return 0x1f;
  }
  uVar1 = param_4 - 9;
  if (0x12 < param_4) {
    uVar1 = param_4 - 0x2a;
  }
  if (param_6 != '\0') {
    portSyncRwLockAcquireWrite(RmapiControlCache._88_8_);
    uVar5 = 0x40;
    if (RmapiControlCache._80_4_ != 0) {
      iVar2 = _rmapiControlCacheGetGpuAttrForObject(param_1,param_2,local_3c,0);
      if (iVar2 == 0) {
        plVar3 = (long *)_setCacheEntry(local_3c[0],0x20802a07,0xc0,param_3,0);
        if (plVar3 == (long *)0x0) {
          uVar5 = 0x51;
        }
        else {
          if (*plVar3 == 0) {
            uVar5 = 0x51;
          }
          else {
            if ((*(byte *)((long)plVar3 + 0x12) & 2) != 0) {
              pcVar4 = (char *)(*plVar3 + (ulong)uVar1 * 3);
              uVar5 = 0;
              if (*pcVar4 == '\0') {
                *pcVar4 = '\x01';
                portMemCopy(pcVar4 + 1,2,param_5,2);
              }
              else {
                iVar2 = portMemCmp(param_5,pcVar4 + 1,2);
                if (iVar2 != 0) {
                  nvAssertFailedNoLog("portMemCmp(capsTbl, cachedTable[ceEngineIndex].capsTbl, NV2080_CTRL_CE_CAPS_TBL_SIZE) == 0"
                                      ,"src/kernel/rmapi/rmapi_cache.c",0x467);
                }
              }
              goto LAB_004ba278;
            }
            uVar5 = 0x40;
            portMemFree();
          }
          multimapRemoveItem_IMPL(RmapiControlCache,plVar3);
        }
      }
      else {
        uVar5 = 0x57;
      }
    }
LAB_004ba278:
    portSyncRwLockReleaseWrite(RmapiControlCache._88_8_);
    return uVar5;
  }
  portSyncRwLockAcquireRead();
  if (RmapiControlCache._80_4_ == 0) {
LAB_004ba235:
    uVar5 = 0x40;
  }
  else {
    iVar2 = _rmapiControlCacheGetGpuAttrForObject(param_1,param_2,local_3c,0);
    if (iVar2 == 0) {
      plVar3 = (long *)multimapFindItem_IMPL(RmapiControlCache,local_3c[0],0x20802a07);
      if ((plVar3 == (long *)0x0) || (*plVar3 == 0)) {
        uVar5 = 0x51;
        goto LAB_004ba23a;
      }
      if ((*(byte *)((long)plVar3 + 0x12) & 2) == 0) goto LAB_004ba235;
      pcVar4 = (char *)(*plVar3 + (ulong)uVar1 * 3);
      if (*pcVar4 != '\0') {
        portMemCopy(param_5,2,pcVar4 + 1,2);
        uVar5 = 0;
        goto LAB_004ba23a;
      }
    }
    uVar5 = 0x57;
  }
LAB_004ba23a:
  portSyncRwLockReleaseRead(RmapiControlCache._88_8_);
  return uVar5;
}


// ===== 004ba450 rmapiControlIsCacheable =====

undefined4 rmapiControlIsCacheable(ulong param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (((RmapiControlCache._80_4_ != 0) && ((param_1 & 0x20400) != 0)) && (param_2 == 0)) {
    uVar1 = 1;
    if ((param_1 & 0x80) != 0) {
      uVar1 = param_3;
    }
    return uVar1;
  }
  return 0;
}


// ===== 004ba490 rmapiControlCacheInit =====

undefined8 rmapiControlCacheInit(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_c;
  
  RmapiControlCache._80_4_ = 1;
  iVar1 = osReadRegistryDword(0,"RmEnableCacheableControls",&local_c);
  if (iVar1 == 0) {
    RmapiControlCache._80_4_ = local_c;
  }
  nvDbg_Printf("src/kernel/rmapi/rmapi_cache.c",0xc9,"rmapiControlCacheInit",1,
               "NVRM: using cache mode %d\n",RmapiControlCache._80_4_);
  uVar2 = portMemAllocatorGetGlobalNonPaged();
  multimapInit_IMPL(RmapiControlCache,uVar2,0x18,0x18,0x10);
  uVar2 = portMemAllocatorGetGlobalNonPaged();
  mapInit_IMPL(0x54e9b0,uVar2,8);
  uVar2 = portMemAllocatorGetGlobalNonPaged();
  RmapiControlCache._88_8_ = portSyncRwLockCreate(uVar2);
  uVar2 = 0;
  if (RmapiControlCache._88_8_ == 0) {
    nvDbg_Printf("src/kernel/rmapi/rmapi_cache.c",0xd0,"rmapiControlCacheInit",4,
                 "NVRM: failed to create rw lock\n");
    multimapDestroy_IMPL(RmapiControlCache);
    mapDestroy_IMPL(0x54e9b0);
    uVar2 = 0x51;
  }
  return uVar2;
}


// ===== 004ba5a0 rmapiControlCacheSetGpuAttrForObject =====

undefined8 rmapiControlCacheSetGpuAttrForObject(uint param_1,ulong param_2,long param_3)

{
  undefined8 *puVar1;
  ulong *puVar2;
  ulong uVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong uVar6;
  
  if (param_3 != 0) {
    uVar3 = param_2 & 0xffffffff;
    uVar6 = (ulong)*(uint *)(param_3 + 0x7a4);
    nvDbg_Printf("src/kernel/rmapi/rmapi_cache.c",0xe8,"rmapiControlCacheSetGpuAttrForObject",1,
                 "NVRM: gpu attr set for 0x%x 0x%x: 0x%llx\n",param_1);
    portSyncRwLockAcquireWrite(RmapiControlCache._88_8_);
    uVar5 = (ulong)param_1 << 0x20 | uVar3;
    puVar1 = (undefined8 *)mapFind_IMPL(0x54e9b0,uVar5);
    if (puVar1 == (undefined8 *)0x0) {
      puVar2 = (ulong *)mapInsertNew_IMPL(0x54e9b0,uVar5,param_2,uVar6);
      if (puVar2 == (ulong *)0x0) {
        uVar4 = 0x51;
      }
      else {
        *puVar2 = uVar6;
        uVar4 = 0;
      }
    }
    else {
      uVar4 = 0x3b;
      nvDbg_Printf("src/kernel/rmapi/rmapi_cache.c",0xf0,"rmapiControlCacheSetGpuAttrForObject",3,
                   "NVRM: set existing gpu attr 0x%x 0x%x was 0x%llx is 0x%llx\n",param_1,uVar3,
                   *puVar1,uVar6);
    }
    portSyncRwLockReleaseWrite(RmapiControlCache._88_8_);
    return uVar4;
  }
  return 0x1f;
}


// ===== 004ba6d0 _rmapiControlCacheGetByInputTemplateMethod =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _rmapiControlCacheGetByInputTemplateMethod
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined8 param_5,undefined4 param_6,code *param_7,char param_8)

{
  int iVar1;
  int iVar2;
  long *plVar3;
  char local_3d;
  undefined4 local_3c [3];
  
  if (param_8 == '\0') {
    portSyncRwLockAcquireRead(RmapiControlCache._88_8_);
    iVar2 = 0x40;
    if (RmapiControlCache._80_4_ != 0) {
      iVar2 = _rmapiControlCacheGetGpuAttrForObject(param_1,param_2,local_3c,0);
      if (((iVar2 != 0) ||
          (plVar3 = (long *)multimapFindItem_IMPL(RmapiControlCache,local_3c[0],param_3),
          plVar3 == (long *)0x0)) || (*plVar3 == 0)) {
        portSyncRwLockReleaseRead(RmapiControlCache._88_8_);
        return 0x57;
      }
      iVar2 = (*param_7)(*plVar3,param_5,0);
    }
    portSyncRwLockReleaseRead(RmapiControlCache._88_8_);
    return iVar2;
  }
  portSyncRwLockAcquireWrite();
  iVar2 = 0x40;
  if (RmapiControlCache._80_4_ == 0) goto LAB_004ba7b0;
  iVar1 = _rmapiControlCacheGetGpuAttrForObject(param_1,param_2,local_3c,0);
  iVar2 = 0x57;
  if (iVar1 != 0) goto LAB_004ba7b0;
  plVar3 = (long *)_setCacheEntry(local_3c[0],param_3,param_6,param_4,&local_3d);
  if (plVar3 == (long *)0x0) {
LAB_004ba86f:
    iVar2 = 0x51;
  }
  else {
    if (*plVar3 == 0) {
      iVar2 = 0x51;
      if (local_3d == '\0') goto LAB_004ba86f;
    }
    else {
      iVar2 = (*param_7)(*plVar3,param_5,param_8);
      if ((iVar2 == 0) || (local_3d == '\0')) goto LAB_004ba7b0;
      if (*plVar3 != 0) {
        portMemFree();
      }
    }
    multimapRemoveItem_IMPL(RmapiControlCache,plVar3);
  }
LAB_004ba7b0:
  portSyncRwLockReleaseWrite(RmapiControlCache._88_8_);
  return iVar2;
}


// ===== 004ba880 _gpuNameStringGet =====

undefined4 _gpuNameStringGet(undefined4 param_1,undefined4 param_2,long param_3)

{
  char *pcVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined4 uVar4;
  undefined4 local_2c [3];
  
  portSyncRwLockAcquireRead(RmapiControlCache._88_8_);
  if (RmapiControlCache._80_4_ == 0) {
LAB_004ba930:
    uVar4 = 0x40;
  }
  else {
    iVar2 = _rmapiControlCacheGetGpuAttrForObject(param_1,param_2,local_2c,0);
    if (iVar2 == 0) {
      puVar3 = (undefined8 *)multimapFindItem_IMPL(RmapiControlCache,local_2c[0],0x20800110);
      if ((puVar3 != (undefined8 *)0x0) && (pcVar1 = (char *)*puVar3, pcVar1 != (char *)0x0)) {
        if ((*(byte *)((long)puVar3 + 0x12) & 2) == 0) goto LAB_004ba930;
        if (*pcVar1 != '\0') {
          portMemCopy(param_3 + 4,0x40,pcVar1,0x40);
          uVar4 = 0;
          goto LAB_004ba915;
        }
      }
    }
    uVar4 = 0x57;
  }
LAB_004ba915:
  portSyncRwLockReleaseRead(RmapiControlCache._88_8_);
  return uVar4;
}


// ===== 004ba940 _rmapiControlCacheGetByInput.isra.0 =====

undefined8
_rmapiControlCacheGetByInput_isra_0
          (undefined8 param_1,undefined8 param_2,uint param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  
  if (param_3 == 0x20800110) {
    uVar1 = _gpuNameStringGet(param_1,param_2,param_4);
    return uVar1;
  }
  if (param_3 < 0x20800111) {
    if (param_3 == 0x730240) {
      uVar1 = _rmapiControlCacheGetByInputTemplateMethod
                        (param_1,param_2,0x730240,0,param_4,0x100,_dispSpecificGetTypeCacheHandler,0
                        );
      return uVar1;
    }
    if (param_3 < 0x730241) {
      if (param_3 == 0x730107) {
        uVar1 = _rmapiControlCacheGetByInputTemplateMethod
                          (param_1,param_2,0x730107,0,param_4,0xc,
                           _dispSystemGetSupportedCacheHandler,0);
        return uVar1;
      }
      if (param_3 == 0x730116) {
        uVar1 = _rmapiControlCacheGetByInputTemplateMethod
                          (param_1,param_2,0x730116,0,param_4,0xc,
                           _dispSystemGetInternalDisplaysCacheHandler,0);
        return uVar1;
      }
    }
    else {
      if (param_3 == 0x731369) {
        uVar1 = _rmapiControlCacheGetByInputTemplateMethod
                          (param_1,param_2,0x731369,0,param_4,0x800,_dispDpGetCapsCacheHandler,0);
        return uVar1;
      }
      if (param_3 == 0x20800102) {
        uVar1 = _getInfoCacheHandler(param_1,param_2,0x20800102,0,param_4 + 1,*param_4,0x46,0);
        return uVar1;
      }
    }
  }
  else {
    if (param_3 == 0x20801823) {
      uVar1 = _getInfoCacheHandler(param_1,param_2,0x20801823,0,param_4 + 1,*param_4,0x34,0);
      return uVar1;
    }
    if (param_3 < 0x20801824) {
      if (param_3 == 0x20800810) {
        uVar1 = _getInfoCacheHandler(param_1,param_2,0x20800810,0,param_4 + 1,*param_4,0xf,0);
        return uVar1;
      }
      if (param_3 == 0x20801109) {
        uVar1 = _getInfoCacheHandler(param_1,param_2,0x20801109,0,param_4 + 1,*param_4,0x100,0);
        return uVar1;
      }
    }
    else {
      if (param_3 == 0x20802a02) {
        uVar1 = _getCePceMaskHandler(param_1,param_2,0,*param_4,param_4 + 1,0);
        return uVar1;
      }
      if (param_3 == 0x20802a07) {
        uVar1 = _getCePhysicalCapsHandler(param_1,param_2,0,*param_4,param_4 + 1,0);
        return uVar1;
      }
    }
  }
  nvDbg_Printf("src/kernel/rmapi/rmapi_cache.c",0x55c,"_rmapiControlCacheGetByInput",3,
               "NVRM: No implementation for cacheable by input cmd 0x%x\n",param_3);
  return 0x57;
}


// ===== 004bab40 _gpuNameStringSet =====

undefined4 _gpuNameStringSet(undefined4 param_1,undefined4 param_2,undefined4 param_3,long param_4)

{
  char *pcVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined4 uVar4;
  undefined4 local_3c [3];
  
  uVar4 = 0x40;
  portSyncRwLockAcquireWrite(RmapiControlCache._88_8_);
  if (RmapiControlCache._80_4_ != 0) {
    iVar2 = _rmapiControlCacheGetGpuAttrForObject(param_1,param_2,local_3c,0);
    if (iVar2 == 0) {
      puVar3 = (undefined8 *)_setCacheEntry(local_3c[0],0x20800110,0x40,param_3,0);
      if (puVar3 == (undefined8 *)0x0) {
        uVar4 = 0x51;
      }
      else {
        pcVar1 = (char *)*puVar3;
        uVar4 = 0;
        if (*pcVar1 == '\0') {
          portMemCopy(pcVar1,0x40,param_4 + 4,0x40);
        }
        else {
          iVar2 = portMemCmp(param_4 + 4,pcVar1,0x40);
          if (iVar2 != 0) {
            nvAssertFailedNoLog("portMemCmp(pParams->gpuNameString.ascii, cachedParams->ascii, sizeof(pParams->gpuNameString.ascii)) == 0"
                                ,"src/kernel/rmapi/rmapi_cache.c",0x409);
          }
        }
      }
    }
    else {
      uVar4 = 0x57;
    }
  }
  portSyncRwLockReleaseWrite(RmapiControlCache._88_8_);
  return uVar4;
}


// ===== 004bac50 rmapiControlCacheFreeForControl =====

undefined8 rmapiControlCacheFreeForControl(undefined4 param_1,undefined4 param_2)

{
  long *plVar1;
  
  portSyncRwLockAcquireWrite(RmapiControlCache._88_8_);
  plVar1 = (long *)multimapFindItem_IMPL(RmapiControlCache,param_1,param_2);
  if (plVar1 != (long *)0x0) {
    if (*plVar1 != 0) {
      portMemFree();
    }
    multimapRemoveItem_IMPL(RmapiControlCache,plVar1);
  }
  portSyncRwLockReleaseWrite(RmapiControlCache._88_8_);
  return 0;
}


// ===== 004bacc0 _rmapiControlCacheSetByInput =====

undefined8
_rmapiControlCacheSetByInput
          (undefined8 param_1,undefined8 param_2,uint param_3,ulong param_4,undefined4 *param_5)

{
  undefined8 uVar1;
  
  if (param_3 == 0x20800110) {
    uVar1 = _gpuNameStringSet(param_1,param_2,param_4 & 0xffffffff,param_5);
    return uVar1;
  }
  if (param_3 < 0x20800111) {
    if (param_3 == 0x730240) {
      uVar1 = _rmapiControlCacheGetByInputTemplateMethod
                        (param_1,param_2,0x730240,param_4,param_5,0x100,
                         _dispSpecificGetTypeCacheHandler,1);
      return uVar1;
    }
    if (param_3 < 0x730241) {
      if (param_3 == 0x730107) {
        uVar1 = _rmapiControlCacheGetByInputTemplateMethod
                          (param_1,param_2,0x730107,param_4,param_5,0xc,
                           _dispSystemGetSupportedCacheHandler,1);
        return uVar1;
      }
      if (param_3 == 0x730116) {
        uVar1 = _rmapiControlCacheGetByInputTemplateMethod
                          (param_1,param_2,0x730116,param_4,param_5,0xc,
                           _dispSystemGetInternalDisplaysCacheHandler,1);
        return uVar1;
      }
    }
    else {
      if (param_3 == 0x731369) {
        uVar1 = _rmapiControlCacheGetByInputTemplateMethod
                          (param_1,param_2,0x731369,param_4,param_5,0x800,_dispDpGetCapsCacheHandler
                           ,1);
        return uVar1;
      }
      if (param_3 == 0x20800102) {
        uVar1 = _getInfoCacheHandler(param_1,param_2,0x20800102,param_4,param_5 + 1,*param_5,0x46,1)
        ;
        return uVar1;
      }
    }
  }
  else {
    if (param_3 == 0x20801823) {
      uVar1 = _getInfoCacheHandler(param_1,param_2,0x20801823,param_4,param_5 + 1,*param_5,0x34,1);
      return uVar1;
    }
    if (param_3 < 0x20801824) {
      if (param_3 == 0x20800810) {
        uVar1 = _getInfoCacheHandler(param_1,param_2,0x20800810,param_4,param_5 + 1,*param_5,0xf,1);
        return uVar1;
      }
      if (param_3 == 0x20801109) {
        uVar1 = _getInfoCacheHandler
                          (param_1,param_2,0x20801109,param_4,param_5 + 1,*param_5,0x100,1);
        return uVar1;
      }
    }
    else {
      if (param_3 == 0x20802a02) {
        uVar1 = _getCePceMaskHandler(param_1,param_2,param_4 & 0xffffffff,*param_5,param_5 + 1,1);
        return uVar1;
      }
      if (param_3 == 0x20802a07) {
        uVar1 = _getCePhysicalCapsHandler
                          (param_1,param_2,param_4 & 0xffffffff,*param_5,param_5 + 1,1);
        return uVar1;
      }
    }
  }
  nvDbg_Printf("src/kernel/rmapi/rmapi_cache.c",0x5ab,"_rmapiControlCacheSetByInput",3,
               "NVRM: No implementation for cacheable by input cmd 0x%x\n",param_3);
  return 0x57;
}


// ===== 004baed0 rmapiControlCacheGetUnchecked =====

int rmapiControlCacheGetUnchecked
              (undefined4 param_1,undefined4 param_2,uint param_3,undefined8 param_4,
              undefined4 param_5,undefined8 param_6)

{
  uint uVar1;
  int iVar2;
  long *plVar3;
  undefined4 uVar4;
  undefined4 local_3c [3];
  
  if (RmapiControlCache._80_4_ == 2) {
    return 0x57;
  }
  portSyncRwLockAcquireRead(RmapiControlCache._88_8_);
  if (RmapiControlCache._80_4_ == 0) {
    iVar2 = 0x40;
  }
  else {
    uVar4 = 0x20;
    if ((((param_3 >> 0x10 == 0) ||
         (iVar2 = _rmapiControlCacheGetGpuAttrForObject(param_1,param_2,local_3c,0),
         uVar4 = local_3c[0], iVar2 == 0)) &&
        (plVar3 = (long *)multimapFindItem_IMPL(RmapiControlCache,uVar4,param_3),
        plVar3 != (long *)0x0)) && (*plVar3 != 0)) {
      uVar1 = *(uint *)(plVar3 + 2);
      iVar2 = rmControlValidateClientPrivilegeAccess(param_1,param_2,param_3,uVar1,param_6);
      if (iVar2 == 0) {
        portSyncRwLockReleaseRead(RmapiControlCache._88_8_);
        if ((uVar1 & 0x20400) == 0x400) {
          iVar2 = _rmapiControlCacheGetCacheable(param_1,param_2,param_3,param_4,param_5);
        }
        else if ((uVar1 & 0x20400) == 0x20000) {
          iVar2 = _rmapiControlCacheGetByInput_isra_0(param_1,param_2,param_3,param_4);
        }
        else {
          iVar2 = 0x3b;
          nvDbg_Printf("src/kernel/rmapi/rmapi_cache.c",0x1d5,"_rmapiControlCacheGetAny",4,
                       "NVRM: Invalid cacheable flag 0x%x for cmd 0x%x\n",uVar1,param_3);
        }
        goto LAB_004baf9a;
      }
    }
    else {
      iVar2 = 0x57;
    }
  }
  portSyncRwLockReleaseRead(RmapiControlCache._88_8_);
LAB_004baf9a:
  nvDbg_Printf("src/kernel/rmapi/rmapi_cache.c",0x5c8,"rmapiControlCacheGetUnchecked",1,
               "NVRM: control cache get for 0x%x 0x%x 0x%x status: 0x%x\n",param_1,param_2,param_3,
               iVar2);
  return iVar2;
}


// ===== 004bb0c0 rmapiControlCacheGet =====

int rmapiControlCacheGet
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,long param_4,int param_5,
              undefined8 param_6)

{
  int iVar1;
  uint local_40;
  int local_3c [3];
  
  if (RmapiControlCache._80_4_ == 2) {
    return 0x57;
  }
  iVar1 = rmapiutilGetControlInfo(param_3,&local_40,0,local_3c);
  if (iVar1 != 0) goto LAB_004bb1a7;
  if ((param_4 == 0) || (local_3c[0] != param_5)) {
    nvCheckFailedNoLog(4,"(params != NULL && paramsSize == ctrlParamsSize)",
                       "src/kernel/rmapi/rmapi_cache.c",0x5e9);
  }
  else {
    iVar1 = rmControlValidateClientPrivilegeAccess(param_1,param_2,param_3,local_40,param_6);
    if (iVar1 != 0) goto LAB_004bb1a7;
    if ((local_40 & 0x20400) == 0x400) {
      iVar1 = _rmapiControlCacheGetCacheable(param_1,param_2,param_3,param_4,param_5);
      goto LAB_004bb1a7;
    }
    if ((local_40 & 0x20400) == 0x20000) {
      iVar1 = _rmapiControlCacheGetByInput_isra_0(param_1,param_2,param_3,param_4);
      goto LAB_004bb1a7;
    }
    nvDbg_Printf("src/kernel/rmapi/rmapi_cache.c",0x5fa,"rmapiControlCacheGet",4,
                 "NVRM: Invalid cacheable flag 0x%x for cmd 0x%x\n",local_40,param_3);
  }
  iVar1 = 0x3b;
LAB_004bb1a7:
  nvDbg_Printf("src/kernel/rmapi/rmapi_cache.c",0x600,"rmapiControlCacheGet",1,
               "NVRM: control cache get for 0x%x 0x%x 0x%x status: 0x%x\n",param_1,param_2,param_3,
               iVar1);
  return iVar1;
}


// ===== 004bb260 rmapiControlCacheSetUnchecked =====

undefined4
rmapiControlCacheSetUnchecked
          (undefined4 param_1,undefined4 param_2,ulong param_3,undefined8 param_4,undefined4 param_5
          ,undefined8 param_6)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined4 uVar5;
  char local_3d;
  undefined4 local_3c [3];
  
  uVar1 = (uint)param_6 & 0x20400;
  if (uVar1 != 0x400) {
    if (uVar1 == 0x20000) {
      uVar2 = _rmapiControlCacheSetByInput();
    }
    else {
      uVar2 = 0x3b;
      nvDbg_Printf("src/kernel/rmapi/rmapi_cache.c",0x641,"rmapiControlCacheSetUnchecked",4,
                   "NVRM: Invalid cacheable flag 0x%x for cmd 0x%x\n",param_6,param_3);
    }
    goto LAB_004bb2b3;
  }
  uVar2 = 0x40;
  portSyncRwLockAcquireWrite(RmapiControlCache._88_8_);
  if (RmapiControlCache._80_4_ != 0) {
    uVar5 = 0x20;
    if ((uint)param_3 >> 0x10 != 0) {
      iVar3 = _rmapiControlCacheGetGpuAttrForObject(param_1,param_2,local_3c,0);
      uVar2 = 0x57;
      uVar5 = local_3c[0];
      if (iVar3 != 0) goto LAB_004bb398;
    }
    puVar4 = (undefined8 *)
             _setCacheEntry(uVar5,param_3 & 0xffffffff,param_5,(uint)param_6,&local_3d);
    if (puVar4 == (undefined8 *)0x0) {
      uVar2 = 0x51;
    }
    else {
      if (local_3d == '\0') {
        if ((RmapiControlCache._80_4_ == 2) &&
           (iVar3 = portMemCmp(*puVar4,param_4,param_5), iVar3 != 0)) {
          nvAssertFailedNoLog("portMemCmp(entry->params, params, paramsSize) == 0",
                              "src/kernel/rmapi/rmapi_cache.c",0x218);
        }
      }
      else {
        portMemCopy(*puVar4,param_5,param_4,param_5);
      }
      uVar2 = 0;
    }
  }
LAB_004bb398:
  portSyncRwLockReleaseWrite(RmapiControlCache._88_8_);
LAB_004bb2b3:
  nvDbg_Printf("src/kernel/rmapi/rmapi_cache.c",0x647,"rmapiControlCacheSetUnchecked",1,
               "NVRM: control cache set for 0x%x 0x%x 0x%x status: 0x%x\n",param_1,param_2,
               param_3 & 0xffffffff,uVar2);
  return uVar2;
}


// ===== 004bb430 rmapiControlCacheSet =====

ulong rmapiControlCacheSet
                (undefined4 param_1,undefined4 param_2,undefined4 param_3,long param_4,int param_5)

{
  uint uVar1;
  ulong uVar2;
  undefined4 local_30;
  int local_2c;
  
  uVar1 = rmapiutilGetControlInfo(param_3,&local_30,0,&local_2c);
  if (uVar1 != 0) {
    nvCheckOkFailedNoLog
              (4,uVar1,"rmapiutilGetControlInfo(cmd, &flags, NULL, &ctrlParamsSize)",
               "src/kernel/rmapi/rmapi_cache.c",0x619);
    return (ulong)uVar1;
  }
  if ((param_4 != 0) && (local_2c == param_5)) {
    uVar2 = rmapiControlCacheSetUnchecked(param_1,param_2,param_3,param_4,param_5,local_30);
    return uVar2;
  }
  nvCheckFailedNoLog(4,"(params != NULL && paramsSize == ctrlParamsSize)",
                     "src/kernel/rmapi/rmapi_cache.c",0x61b);
  return 0x3b;
}


// ===== 004bb510 rmapiControlCacheFreeNonPersistentCacheForGpu =====

void rmapiControlCacheFreeNonPersistentCacheForGpu(undefined4 param_1)

{
  long lVar1;
  
  portSyncRwLockAcquireWrite(RmapiControlCache._88_8_);
  lVar1 = multimapFindSubmap_IMPL(RmapiControlCache,param_1);
  if (lVar1 != 0) {
    _freeSubmap_constprop_0(lVar1,0);
  }
  portSyncRwLockReleaseWrite(RmapiControlCache._88_8_);
  return;
}


// ===== 004bb560 rmapiControlCacheFreeAllCacheForGpu =====

void rmapiControlCacheFreeAllCacheForGpu(undefined4 param_1)

{
  long lVar1;
  
  portSyncRwLockAcquireWrite(RmapiControlCache._88_8_);
  lVar1 = multimapFindSubmap_IMPL(RmapiControlCache,param_1);
  if (lVar1 != 0) {
    _freeSubmap_constprop_0(lVar1,1);
  }
  portSyncRwLockReleaseWrite(RmapiControlCache._88_8_);
  return;
}


// ===== 004bb5b0 rmapiControlCacheFreeClientEntry =====

void rmapiControlCacheFreeClientEntry(uint param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  portSyncRwLockAcquireWrite(RmapiControlCache._88_8_);
  while( true ) {
    lVar2 = mapFindGEQ_IMPL(0x54e9b0,(ulong)param_1 << 0x20);
    if (lVar2 == 0) break;
    uVar1 = mapKey_IMPL(0x54e9b0,lVar2);
    if (param_1 != (uint)((ulong)uVar1 >> 0x20)) break;
    mapRemove_IMPL(0x54e9b0,lVar2);
    nvDbg_Printf("src/kernel/rmapi/rmapi_cache.c",0x146,"_rmapiControlCacheFreeGpuAttrForClient",1,
                 "NVRM: Gpu Inst entry with key 0x%llx freed\n",uVar1);
  }
  portSyncRwLockReleaseWrite(RmapiControlCache._88_8_);
  return;
}


// ===== 004bb660 rmapiControlCacheFreeObjectEntry =====

void rmapiControlCacheFreeObjectEntry(int param_1,int param_2)

{
  long lVar1;
  
  if (param_1 != param_2) {
    portSyncRwLockAcquireWrite(RmapiControlCache._88_8_);
    lVar1 = mapFind_IMPL(0x54e9b0,CONCAT44(param_1,param_2));
    if (lVar1 != 0) {
      mapRemove_IMPL(0x54e9b0,lVar1);
      nvDbg_Printf("src/kernel/rmapi/rmapi_cache.c",0x131,"_rmapiControlCacheFreeGpuAttrForObject",1
                   ,"NVRM: Gpu Inst entry with key 0x%llx freed\n",CONCAT44(param_1,param_2));
    }
    portSyncRwLockReleaseWrite(RmapiControlCache._88_8_);
    return;
  }
  rmapiControlCacheFreeClientEntry();
  return;
}


// ===== 004bb700 rmapiControlCacheFree =====

void rmapiControlCacheFree(void)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  uVar2 = multimapLastItem_IMPL(RmapiControlCache);
  uVar3 = multimapFirstItem_IMPL(RmapiControlCache);
  multimapItemIterRange_IMPL(&local_58,RmapiControlCache,uVar3,uVar2);
  local_38 = local_58;
  local_30 = local_50;
  local_28 = local_48;
  local_20 = local_40;
  while( true ) {
    cVar1 = multimapItemIterNext_IMPL(&local_38);
    if (cVar1 == '\0') break;
    portMemFree(*local_38);
  }
  multimapDestroy_IMPL(RmapiControlCache);
  mapDestroy_IMPL(0x54e9b0);
  portSyncRwLockDestroy(RmapiControlCache._88_8_);
  RmapiControlCache._88_8_ = 0;
  return;
}


// ===== 004bb7b0 rmapiControlCacheSetMode =====

void rmapiControlCacheSetMode(undefined4 param_1)

{
  nvDbg_Printf("src/kernel/rmapi/rmapi_cache.c",0x6b8,"rmapiControlCacheSetMode",1,
               "NVRM: Set rmapi control cache mode to 0x%x\n",param_1);
  portSyncRwLockAcquireWrite(RmapiControlCache._88_8_);
  RmapiControlCache._80_4_ = param_1;
  portSyncRwLockReleaseWrite(RmapiControlCache._88_8_);
  return;
}


// ===== 004bb810 rmapiControlCacheGetMode =====

undefined4 rmapiControlCacheGetMode(void)

{
  return RmapiControlCache._80_4_;
}


// ===== 004bb820 _dispSystemGetSupportedCacheHandler =====

undefined8 _dispSystemGetSupportedCacheHandler(char *param_1,long param_2,char param_3)

{
  undefined4 uVar1;
  
  if (param_3 != '\0') {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
    uVar1 = *(undefined4 *)(param_2 + 8);
    *param_1 = '\x01';
    *(undefined4 *)(param_1 + 8) = uVar1;
    return 0;
  }
  if (*param_1 != '\0') {
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 8);
    return 0;
  }
  return 0x57;
}


// ===== 004bb870 _dispSystemGetInternalDisplaysCacheHandler =====

undefined8 _dispSystemGetInternalDisplaysCacheHandler(char *param_1,long param_2,char param_3)

{
  undefined4 uVar1;
  
  if (param_3 != '\0') {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
    uVar1 = *(undefined4 *)(param_2 + 8);
    *param_1 = '\x01';
    *(undefined4 *)(param_1 + 8) = uVar1;
    return 0;
  }
  if (*param_1 != '\0') {
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 8);
    return 0;
  }
  return 0x57;
}


// ===== 004bb8c0 _dispDpGetCapsCacheHandler =====

undefined8 _dispDpGetCapsCacheHandler(long param_1,long param_2,char param_3)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  char *pcVar5;
  long lVar6;
  
  uVar1 = *(uint *)(param_2 + 4);
  uVar3 = (ulong)uVar1;
  lVar4 = uVar3 * 0x40;
  lVar6 = param_1 + 4 + lVar4;
  if (param_3 == '\0') {
    if (0x1f < uVar1) {
      return 0x1f;
    }
    lVar2 = param_2;
    if (*(char *)(param_1 + lVar4) == '\0') {
      return 0x57;
    }
  }
  else {
    if (0x1f < uVar1) {
      return 0x1f;
    }
    pcVar5 = (char *)(lVar4 + param_1);
    if ((*pcVar5 != '\0') &&
       (((((((*(uint *)(pcVar5 + 8) != uVar1 || (*(int *)(param_2 + 8) != *(int *)(pcVar5 + 0xc)))
            || (*(int *)(param_2 + 0xc) != *(int *)(pcVar5 + 0x10))) ||
           (((*(int *)(param_2 + 0x10) != *(int *)(pcVar5 + 0x14) ||
             (*(char *)(param_2 + 0x14) != pcVar5[0x18])) ||
            ((*(char *)(param_2 + 0x15) != pcVar5[0x19] ||
             ((*(char *)(param_2 + 0x16) != pcVar5[0x1a] ||
              (lVar4 = uVar3 * 0x40 + param_1, *(char *)(param_2 + 0x18) != *(char *)(lVar4 + 0x1c))
              ))))))) ||
          ((*(char *)(param_2 + 0x19) != *(char *)(lVar4 + 0x1d) ||
           (((*(char *)(param_2 + 0x1a) != *(char *)(lVar4 + 0x1e) ||
             (*(char *)(param_2 + 0x1b) != *(char *)(lVar4 + 0x1f))) ||
            (*(char *)(param_2 + 0x1c) != *(char *)(lVar4 + 0x20))))))) ||
         (((*(char *)(param_2 + 0x1d) != *(char *)(lVar4 + 0x21) ||
           (*(char *)(param_2 + 0x1e) != *(char *)(lVar4 + 0x22))) ||
          (((*(char *)(param_2 + 0x20) != *(char *)(lVar4 + 0x24) ||
            ((*(int *)(param_2 + 0x24) != *(int *)(lVar4 + 0x28) ||
             (*(int *)(param_2 + 0x28) != *(int *)(lVar4 + 0x2c))))) ||
           (lVar4 = uVar3 * 0x40 + param_1, *(int *)(param_2 + 0x2c) != *(int *)(lVar4 + 0x30)))))))
        || (((*(int *)(param_2 + 0x30) != *(int *)(lVar4 + 0x34) ||
             (*(int *)(param_2 + 0x34) != *(int *)(lVar4 + 0x38))) ||
            (*(int *)(param_2 + 0x38) != *(int *)(lVar4 + 0x3c))))))) {
      nvAssertFailedNoLog("(src->sorIndex == dst->sorIndex) && (src->maxLinkRate == dst->maxLinkRate) && (src->dpVersionsSupported == dst->dpVersionsSupported) && (src->UHBRSupportedByGpu == dst->UHBRSupportedByGpu) && (src->bIsMultistreamSupported == dst->bIsMultistreamSupported) && (src->bIsSCEnabled == dst->bIsSCEnabled) && (src->bHasIncreasedWatermarkLimits == dst->bHasIncreasedWatermarkLimits) && (src->isSingleHeadMSTSupported == dst->isSingleHeadMSTSupported) && (src->bFECSupported == dst->bFECSupported) && (src->bIsTrainPhyRepeater == dst->bIsTrainPhyRepeater) && (src->bOverrideLinkBw == dst->bOverrideLinkBw) && (src->bUseRgFlushSequence == dst->bUseRgFlushSequence) && (src->bSupportDPDownSpread == dst->bSupportDPDownSpread) && (src->bAvoidHBR3 == dst->bAvoidHBR3) && (src->DSC.bDscSupported == dst->DSC.bDscSupported) && (src->DSC.encoderColorFormatMask == dst->DSC.encoderColorFormatMask) && (src->DSC.lineBufferSizeKB == dst->DSC.lineBufferSizeKB) && (src->DSC.rateBufferSizeKB == dst->DSC.rateBufferSizeKB) && (src->DSC.bitsPerPixelPrecision == dst->DSC.bitsPerPixelPrecision) && (src->DSC.maxNumHztSlices == dst->DSC.maxNumHztSlices) && (src->DSC.lineBufferBitDepth == dst->DSC.lineBufferBitDepth)"
                          ,"src/kernel/rmapi/rmapi_cache_handlers.c",0x81);
      uVar3 = (ulong)*(uint *)(param_2 + 4);
    }
    *(undefined1 *)(param_1 + uVar3 * 0x40) = 1;
    lVar2 = lVar6;
    lVar6 = param_2;
  }
  portMemCopy(lVar2,0x3c,lVar6,0x3c);
  return 0;
}


// ===== 004bbab0 _dispSpecificGetTypeCacheHandler =====

undefined4 _dispSpecificGetTypeCacheHandler(long param_1,long param_2,char param_3)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 uVar4;
  
  uVar2 = *(uint *)(param_2 + 4);
  if (uVar2 != 0) {
    if ((uVar2 - 1 & uVar2) == 0) {
      uVar3 = (ulong)((uint)((uVar2 & 0xaaaaaaaa) != 0) | (uint)(0xffff < uVar2) << 4 |
                      (uint)((uVar2 & 0xff00ff00) != 0) << 3 |
                      (uint)((uVar2 & 0xf0f0f0f0) != 0) << 2 | (uint)((uVar2 & 0xcccccccc) != 0) * 2
                     );
      cVar1 = *(char *)(param_1 + uVar3 * 8);
      if (param_3 == '\0') {
        if (cVar1 == '\0') {
          uVar4 = 0x57;
        }
        else {
          *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 4 + uVar3 * 8);
          uVar4 = 0;
        }
        return uVar4;
      }
      if ((cVar1 != '\0') && (*(int *)(param_1 + 4 + uVar3 * 8) != *(int *)(param_2 + 8))) {
        nvAssertFailedNoLog("pCacheTable->cachedEntries[cacheEntryIdx].displayType == pParams->displayType"
                            ,"src/kernel/rmapi/rmapi_cache_handlers.c",0xbb);
        uVar4 = *(undefined4 *)(param_2 + 8);
        *(undefined1 *)(param_1 + uVar3 * 8) = 1;
        *(undefined4 *)(param_1 + 4 + uVar3 * 8) = uVar4;
        return 0;
      }
      *(int *)(param_1 + 4 + uVar3 * 8) = *(int *)(param_2 + 8);
      *(undefined1 *)(param_1 + uVar3 * 8) = 1;
      return 0;
    }
  }
  return 0x1f;
}


// ===== 004bbbd0 serverSerializeCtrlDown =====

uint serverSerializeCtrlDown
               (long param_1,uint param_2,undefined8 *param_3,undefined4 *param_4,uint *param_5)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  uint uVar4;
  uint local_48;
  
  if ((*param_5 & 4) != 0) {
    *(undefined8 *)(param_1 + 0x50) = *param_3;
    *(undefined4 *)(param_1 + 0x60) = *param_4;
    return 0;
  }
  local_48 = *param_5 & 4;
  uVar4 = (param_2 >> 0x10) << 8 | param_2 >> 8 & 0x3f;
  iVar1 = FinnRmApiGetSerializedSize(uVar4,param_2 & 0xff,*param_3);
  *(undefined8 *)(param_1 + 0x58) = *param_3;
  *(undefined4 *)(param_1 + 100) = *param_4;
  if (iVar1 != 0) {
    if (*(long *)(param_1 + 0x50) == 0) {
      lVar2 = portMemAllocNonPaged(iVar1);
      if (lVar2 == 0) {
        local_48 = 0x1a;
      }
      else {
        *(long *)(param_1 + 0x50) = lVar2;
        local_48 = finnSerializeInternal_FINN_RM_API(uVar4,param_2 & 0xff,*param_3,lVar2,iVar1,0);
        if (local_48 == 0) {
          *(int *)(param_1 + 0x60) = iVar1;
          *param_5 = *param_5 | 4;
          *param_3 = *(undefined8 *)(param_1 + 0x50);
          *param_4 = *(undefined4 *)(param_1 + 0x60);
          *(undefined1 *)(param_1 + 0x69) = 1;
        }
        else {
          uVar3 = nvstatusToString(local_48);
          nvDbg_Printf("src/kernel/rmapi/rmapi_finn.c",0x54,"serverSerializeCtrlDown",4,
                       "NVRM: Serialization failed for cmd 0x%06x with status %s (0x%02x)\n",param_2
                       ,uVar3,local_48);
          portMemFree(*(undefined8 *)(param_1 + 0x50));
          *(undefined8 *)(param_1 + 0x50) = 0;
        }
      }
    }
    else if (*(int *)(param_1 + 0x60) != iVar1) {
      nvAssertFailedNoLog("pCallContext->serializedSize == serializedSize",
                          "src/kernel/rmapi/rmapi_finn.c",0x44);
      local_48 = 0x40;
    }
  }
  return local_48;
}


// ===== 004bbd90 serverDeserializeCtrlDown =====

int serverDeserializeCtrlDown
              (long param_1,uint param_2,undefined8 *param_3,undefined4 *param_4,byte *param_5)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  
  if ((*param_5 & 4) == 0) {
    *(undefined8 *)(param_1 + 0x58) = *param_3;
    *(undefined4 *)(param_1 + 100) = *param_4;
  }
  else {
    iVar1 = FinnRmApiGetUnserializedSize
                      ((param_2 >> 0x10) << 8 | param_2 >> 8 & 0x3f,param_2 & 0xff);
    if (iVar1 == 0) {
      return 0x6a;
    }
    if (*(long *)(param_1 + 0x58) != 0) {
      if (*(int *)(param_1 + 100) == iVar1) {
        return 0;
      }
      nvAssertFailedNoLog("pCallContext->deserializedSize == unserializedSize",
                          "src/kernel/rmapi/rmapi_finn.c",0x91);
      return 0x40;
    }
    lVar3 = portMemAllocNonPaged(iVar1);
    if (lVar3 == 0) {
      return 0x1a;
    }
    *(long *)(param_1 + 0x58) = lVar3;
    iVar2 = finnDeserializeInternal_FINN_RM_API(*param_3,*param_4,lVar3,iVar1,0);
    if (iVar2 != 0) {
      uVar4 = nvstatusToString(iVar2);
      nvDbg_Printf("src/kernel/rmapi/rmapi_finn.c",0xa3,"serverDeserializeCtrlDown",4,
                   "NVRM: Deserialization failed for cmd 0x%06x with status %s (0x%02x)\n",param_2,
                   uVar4,iVar2);
      portMemFree(*(undefined8 *)(param_1 + 0x58));
      *(undefined8 *)(param_1 + 0x58) = 0;
      return iVar2;
    }
    *(int *)(param_1 + 100) = iVar1;
    *(undefined8 *)(param_1 + 0x50) = *param_3;
    *(undefined4 *)(param_1 + 0x60) = *param_4;
    *param_3 = *(undefined8 *)(param_1 + 0x58);
    *param_4 = *(undefined4 *)(param_1 + 100);
  }
  *(undefined1 *)(param_1 + 0x68) = 1;
  return 0;
}


// ===== 004bbf60 serverSerializeCtrlUp =====

int serverSerializeCtrlUp
              (long param_1,uint param_2,undefined8 *param_3,undefined4 *param_4,uint *param_5)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((*param_5 & 4) == 0) {
    return 0;
  }
  if (*(char *)(param_1 + 0x69) == '\0') {
    if ((*(int *)(param_1 + 0x60) == 0) || (*(long *)(param_1 + 0x50) == 0)) {
      return 0x40;
    }
    if (*(long *)(param_1 + 0x58) != 0) {
      iVar1 = finnSerializeInternal_FINN_RM_API
                        ((param_2 >> 0x10) << 8 | param_2 >> 8 & 0x3f,param_2 & 0xff,
                         *(long *)(param_1 + 0x58),*(long *)(param_1 + 0x50),
                         *(int *)(param_1 + 0x60),1);
      if (iVar1 == 0) {
        *param_3 = *(undefined8 *)(param_1 + 0x50);
        *param_4 = *(undefined4 *)(param_1 + 0x60);
      }
      else {
        uVar2 = nvstatusToString(iVar1);
        nvDbg_Printf("src/kernel/rmapi/rmapi_finn.c",0xf1,"serverSerializeCtrlUp",4,
                     "NVRM: Serialization failed for cmd 0x%06x with status %s (0x%02x)\n",param_2,
                     uVar2,iVar1);
      }
      return iVar1;
    }
  }
  else {
    *param_5 = *param_5 & 0xfffffffb;
  }
  return 0;
}


// ===== 004bc070 serverDeserializeCtrlUp =====

int serverDeserializeCtrlUp
              (long param_1,uint param_2,undefined8 *param_3,undefined4 *param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  if ((*param_5 & 4) == 0) {
    return 0;
  }
  iVar1 = FinnRmApiGetUnserializedSize((param_2 >> 0x10) << 8 | param_2 >> 8 & 0x3f,param_2 & 0xff);
  iVar2 = 0;
  if (*(char *)(param_1 + 0x69) != '\0') {
    iVar2 = 0x6a;
    *param_5 = *param_5 & 0xfffffffb;
    if (iVar1 != 0) {
      if ((*(long *)(param_1 + 0x58) == 0) || (*(long *)(param_1 + 0x50) == 0)) {
        iVar2 = 0x40;
      }
      else {
        iVar2 = finnDeserializeInternal_FINN_RM_API
                          (*(long *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x60),
                           *(long *)(param_1 + 0x58),iVar1,1);
        if (iVar2 == 0) {
          *(int *)(param_1 + 100) = iVar1;
          *param_3 = *(undefined8 *)(param_1 + 0x58);
          *param_4 = *(undefined4 *)(param_1 + 100);
        }
        else {
          uVar3 = nvstatusToString(iVar2);
          nvDbg_Printf("src/kernel/rmapi/rmapi_finn.c",0x13e,"serverDeserializeCtrlUp",4,
                       "NVRM: Deserialization failed for cmd 0x%06x with status %s (0x%02x)\n",
                       param_2,uVar3,iVar2);
        }
      }
    }
  }
  return iVar2;
}


// ===== 004bc1a0 serverSerializeAllocDown =====

uint serverSerializeAllocDown
               (long param_1,undefined4 param_2,undefined8 *param_3,int *param_4,uint *param_5)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  uint local_48;
  
  if ((*param_5 & 2) != 0) {
    *(undefined8 *)(param_1 + 0x50) = *param_3;
    *(int *)(param_1 + 0x60) = *param_4;
    return 0;
  }
  local_48 = *param_5 & 2;
  iVar1 = FinnRmApiGetSerializedSize(0xa000,param_2,*param_3);
  *(undefined8 *)(param_1 + 0x58) = *param_3;
  *(int *)(param_1 + 100) = *param_4;
  if (iVar1 != 0) {
    if (*(long *)(param_1 + 0x50) == 0) {
      lVar2 = portMemAllocNonPaged(iVar1);
      if (lVar2 == 0) {
        local_48 = 0x1a;
      }
      else {
        *(long *)(param_1 + 0x50) = lVar2;
        local_48 = finnSerializeInternal_FINN_RM_API(0xa000,param_2,*param_3,lVar2,iVar1,0);
        if (local_48 == 0) {
          *(int *)(param_1 + 0x60) = iVar1;
          *param_5 = *param_5 | 2;
          *param_3 = *(undefined8 *)(param_1 + 0x50);
          *param_4 = iVar1;
          *(undefined1 *)(param_1 + 0x69) = 1;
        }
        else {
          uVar3 = nvstatusToString(local_48);
          nvDbg_Printf("src/kernel/rmapi/rmapi_finn.c",0x179,"serverSerializeAllocDown",4,
                       "NVRM: Serialization failed for classId 0x%06x with status %s (0x%02x)\n",
                       param_2,uVar3,local_48);
          portMemFree(*(undefined8 *)(param_1 + 0x50));
          *(undefined8 *)(param_1 + 0x50) = 0;
        }
      }
    }
    else if (*(int *)(param_1 + 0x60) != iVar1) {
      nvAssertFailedNoLog("pCallContext->serializedSize == serializedSize",
                          "src/kernel/rmapi/rmapi_finn.c",0x169);
      local_48 = 0x40;
    }
  }
  return local_48;
}


// ===== 004bc350 serverDeserializeAllocDown =====

int serverDeserializeAllocDown
              (long param_1,undefined4 param_2,undefined8 *param_3,undefined4 *param_4,byte *param_5
              )

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  
  if ((*param_5 & 2) == 0) {
    *(undefined8 *)(param_1 + 0x58) = *param_3;
    *(undefined4 *)(param_1 + 100) = *param_4;
  }
  else {
    iVar1 = FinnRmApiGetUnserializedSize(0xa000,param_2);
    if (iVar1 == 0) {
      return 0x6a;
    }
    if (*(long *)(param_1 + 0x58) != 0) {
      if (*(int *)(param_1 + 100) == iVar1) {
        return 0;
      }
      nvAssertFailedNoLog("pCallContext->deserializedSize == unserializedSize",
                          "src/kernel/rmapi/rmapi_finn.c",0x1ac);
      return 0x40;
    }
    lVar3 = portMemAllocNonPaged(iVar1);
    if (lVar3 == 0) {
      return 0x1a;
    }
    *(long *)(param_1 + 0x58) = lVar3;
    iVar2 = finnDeserializeInternal_FINN_RM_API(*param_3,*param_4,lVar3,iVar1,0);
    if (iVar2 != 0) {
      uVar4 = nvstatusToString(iVar2);
      nvDbg_Printf("src/kernel/rmapi/rmapi_finn.c",0x1be,"serverDeserializeAllocDown",4,
                   "NVRM: Deserialization failed for classId 0x%06x with status %s (0x%02x)\n",
                   param_2,uVar4,iVar2);
      portMemFree(*(undefined8 *)(param_1 + 0x58));
      *(undefined8 *)(param_1 + 0x58) = 0;
      return iVar2;
    }
    *(ulong *)(param_1 + 0x60) = CONCAT44(iVar1,*param_4);
    *(undefined8 *)(param_1 + 0x50) = *param_3;
    *param_3 = *(undefined8 *)(param_1 + 0x58);
    *param_4 = *(undefined4 *)(param_1 + 100);
  }
  *(undefined1 *)(param_1 + 0x68) = 1;
  return 0;
}


// ===== 004bc510 serverSerializeAllocUp =====

int serverSerializeAllocUp
              (long param_1,undefined4 param_2,undefined8 *param_3,undefined4 *param_4,uint *param_5
              )

{
  int iVar1;
  undefined8 uVar2;
  
  if ((*param_5 & 2) == 0) {
    return 0;
  }
  if (*(char *)(param_1 + 0x69) == '\0') {
    if ((*(int *)(param_1 + 0x60) == 0) || (*(long *)(param_1 + 0x50) == 0)) {
      return 0x40;
    }
    if (*(long *)(param_1 + 0x58) != 0) {
      iVar1 = finnSerializeInternal_FINN_RM_API
                        (0xa000,param_2,*(long *)(param_1 + 0x58),*(long *)(param_1 + 0x50),
                         *(int *)(param_1 + 0x60),1);
      if (iVar1 == 0) {
        *param_3 = *(undefined8 *)(param_1 + 0x50);
        *param_4 = *(undefined4 *)(param_1 + 0x60);
      }
      else {
        uVar2 = nvstatusToString(iVar1);
        nvDbg_Printf("src/kernel/rmapi/rmapi_finn.c",0x202,"serverSerializeAllocUp",4,
                     "NVRM: Serialization failed for classId 0x%06x with status %s (0x%02x)\n",
                     param_2,uVar2,iVar1);
      }
      return iVar1;
    }
  }
  else {
    *param_5 = *param_5 & 0xfffffffd;
  }
  return 0;
}


// ===== 004bc610 serverDeserializeAllocUp =====

int serverDeserializeAllocUp
              (long param_1,undefined4 param_2,undefined8 *param_3,int *param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  if ((*param_5 & 2) == 0) {
    return 0;
  }
  iVar1 = FinnRmApiGetUnserializedSize(0xa000,param_2);
  iVar2 = 0;
  if (*(char *)(param_1 + 0x69) != '\0') {
    iVar2 = 0x6a;
    *param_5 = *param_5 & 0xfffffffd;
    if (iVar1 != 0) {
      if ((*(long *)(param_1 + 0x58) == 0) || (*(long *)(param_1 + 0x50) == 0)) {
        iVar2 = 0x40;
      }
      else {
        iVar2 = finnDeserializeInternal_FINN_RM_API
                          (*(long *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x60),
                           *(long *)(param_1 + 0x58),iVar1,1);
        if (iVar2 == 0) {
          *(int *)(param_1 + 100) = iVar1;
          *param_3 = *(undefined8 *)(param_1 + 0x58);
          *param_4 = iVar1;
        }
        else {
          uVar3 = nvstatusToString(iVar2);
          nvDbg_Printf("src/kernel/rmapi/rmapi_finn.c",0x243,"serverDeserializeAllocUp",4,
                       "NVRM: Deserialization failed for classId 0x%06x with status %s (0x%02x)\n",
                       param_2,uVar3,iVar2);
        }
      }
    }
  }
  return iVar2;
}


// ===== 004bc720 serverFreeSerializeStructures =====

void serverFreeSerializeStructures(long param_1,long param_2)

{
  if (*(long *)(param_1 + 0x50) != param_2) {
    portMemFree();
  }
  if (*(long *)(param_1 + 0x58) != param_2) {
    portMemFree();
  }
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(undefined8 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  return;
}


// ===== 004bc780 rmapiFixupAllocParams =====

undefined8 rmapiFixupAllocParams(long *param_1,int *param_2)

{
  int *piVar1;
  long lVar2;
  
  if ((*(long *)(*param_1 + 8) == 0) ||
     ((*(uint *)(*(long *)(*param_1 + 8) + 4) & 0xffffff) != 0x854293)) {
    return 0;
  }
  piVar1 = *(int **)(param_2 + 0x10);
  if (param_2[3] == 5) {
    param_2[3] = piVar1[2];
  }
  piVar1[1] = param_2[1];
  if (*piVar1 != *param_2) {
    param_2[1] = *param_2;
  }
  lVar2 = RsResInfoByExternalClassId(param_2[3]);
  if (((lVar2 != 0) && (*(long *)(lVar2 + 8) != 0)) &&
     ((*(uint *)(*(long *)(lVar2 + 8) + 4) & 0xffffff) == 0x854293)) {
    *param_1 = lVar2;
    return 0;
  }
  return 0x22;
}


// ===== 004bc820 serverAllocLookupSecondClient =====

undefined4 serverAllocLookupSecondClient(uint param_1,undefined4 *param_2,undefined4 *param_3)

{
  long lVar1;
  
  lVar1 = RsResInfoByExternalClassId();
  *param_3 = 0;
  if ((param_2 != (undefined4 *)0x0) && (lVar1 != 0)) {
    if ((*(uint *)(lVar1 + 0x24) & 0x4000) == 0) {
      return 0;
    }
    if (param_1 == 0x83de) {
      *param_3 = param_2[1];
      return 0;
    }
    if (param_1 < 0x83df) {
      if (param_1 < 0x7a) {
        if ((param_1 < 0x78) && (param_1 != 5)) {
LAB_004bc8b8:
          nvAssertFailedNoLog(&DAT_00d9791a,"src/kernel/rmapi/rmapi_specific.c",0x7e);
          return 0x40;
        }
      }
      else if (param_1 != 0x7e) goto LAB_004bc8b8;
    }
    else if (param_1 != 0xc574) goto LAB_004bc8b8;
    *param_3 = *param_2;
  }
  return 0;
}


// ===== 004bc8f0 serverControlLookupSecondClient =====

undefined8
serverControlLookupSecondClient(int param_1,undefined4 *param_2,long param_3,undefined4 *param_4)

{
  *param_4 = 0;
  if (param_2 != (undefined4 *)0x0) {
    if ((*(uint *)(param_3 + 4) & 0x80000) == 0) {
      return 0;
    }
    if (param_1 != 0x20801208) {
      nvAssertFailedNoLog(&DAT_00d9791a,"src/kernel/rmapi/rmapi_specific.c",0x9c);
      return 0x40;
    }
    *param_4 = *param_2;
  }
  return 0;
}


// ===== 004bc950 rmapiRmControlCanBeRaisedIrql =====

bool rmapiRmControlCanBeRaisedIrql(uint param_1)

{
  if (param_1 != 0x90100101) {
    if (param_1 < 0x90100102) {
      return (param_1 & 0xfffffffd) == 0x20800401;
    }
    if (param_1 != 0xc3700102) {
      return param_1 + 0x3c8ffefc < 2;
    }
  }
  return true;
}


// ===== 004bc990 rmapiRmControlCanBeBypassLock =====

bool rmapiRmControlCanBeBypassLock(uint param_1)

{
  if (param_1 != 0x90100101) {
    if (param_1 < 0x90100102) {
      if (param_1 != 0x20802204) {
        if (0x20802204 < param_1) {
          return param_1 == 0x2080240b;
        }
        if (param_1 != 0x20800403) {
          return param_1 == 0x2080182c;
        }
      }
    }
    else if (param_1 != 0xc3700102) {
      if (param_1 < 0xc3700103) {
        return param_1 == 0x906f0106;
      }
      return param_1 + 0x3c8ffefc < 2;
    }
  }
  return true;
}


// ===== 004bca00 _rmapiAlloc_STUB =====

undefined8 _rmapiAlloc_STUB(void)

{
  return 0x56;
}


// ===== 004bca10 _rmapiAllocWithHandle_STUB =====

undefined8 _rmapiAllocWithHandle_STUB(void)

{
  return 0x56;
}


// ===== 004bca20 _rmapiAllocWithSecInfo_STUB =====

undefined8 _rmapiAllocWithSecInfo_STUB(void)

{
  return 0x56;
}


// ===== 004bca30 _rmapiFree_STUB =====

undefined8 _rmapiFree_STUB(void)

{
  return 0x56;
}


// ===== 004bca40 _rmapiFreeWithSecInfo_STUB =====

undefined8 _rmapiFreeWithSecInfo_STUB(void)

{
  return 0x56;
}


// ===== 004bca50 _rmapiDisableClients_STUB =====

undefined8 _rmapiDisableClients_STUB(void)

{
  return 0x56;
}


// ===== 004bca60 _rmapiDisableClientsWithSecInfo_STUB =====

undefined8 _rmapiDisableClientsWithSecInfo_STUB(void)

{
  return 0x56;
}


// ===== 004bca70 _rmapiControl_STUB =====

undefined8 _rmapiControl_STUB(void)

{
  return 0x56;
}


// ===== 004bca80 _rmapiControlWithSecInfo_STUB =====

undefined8 _rmapiControlWithSecInfo_STUB(void)

{
  return 0x56;
}


// ===== 004bca90 _rmapiControlPrefetch_STUB =====

undefined8 _rmapiControlPrefetch_STUB(void)

{
  return 0x56;
}


// ===== 004bcaa0 _rmapiDupObject_STUB =====

undefined8 _rmapiDupObject_STUB(void)

{
  return 0x56;
}


// ===== 004bcab0 _rmapiDupObjectWithSecInfo_STUB =====

undefined8 _rmapiDupObjectWithSecInfo_STUB(void)

{
  return 0x56;
}


// ===== 004bcac0 _rmapiShare_STUB =====

undefined8 _rmapiShare_STUB(void)

{
  return 0x56;
}


// ===== 004bcad0 _rmapiShareWithSecInfo_STUB =====

undefined8 _rmapiShareWithSecInfo_STUB(void)

{
  return 0x56;
}


// ===== 004bcae0 _rmapiMapToCpu_STUB =====

undefined8 _rmapiMapToCpu_STUB(void)

{
  return 0x56;
}


// ===== 004bcaf0 _rmapiMapToCpuWithSecInfo_STUB =====

undefined8 _rmapiMapToCpuWithSecInfo_STUB(void)

{
  return 0x56;
}


// ===== 004bcb00 _rmapiUnmapFromCpu_STUB =====

undefined8 _rmapiUnmapFromCpu_STUB(void)

{
  return 0x56;
}


// ===== 004bcb10 _rmapiMap_STUB =====

undefined8 _rmapiMap_STUB(void)

{
  return 0x56;
}


// ===== 004bcb20 _rmapiMapWithSecInfo_STUB =====

undefined8 _rmapiMapWithSecInfo_STUB(void)

{
  return 0x56;
}


// ===== 004bcb30 _rmapiUnmapFromCpuWithSecInfo_STUB =====

undefined8 _rmapiUnmapFromCpuWithSecInfo_STUB(void)

{
  return 0x56;
}


// ===== 004bcb40 _rmapiUnmapWithSecInfo_STUB =====

undefined8 _rmapiUnmapWithSecInfo_STUB(void)

{
  return 0x56;
}


// ===== 004bcb50 _rmapiUnmap_STUB =====

undefined8 _rmapiUnmap_STUB(void)

{
  return 0x56;
}


// ===== 004bcb60 rmapiInitStubInterface =====

void rmapiInitStubInterface(undefined8 *param_1)

{
  portMemSet(param_1,0,0xe8);
  *param_1 = _rmapiAlloc_STUB;
  param_1[1] = _rmapiAllocWithHandle_STUB;
  param_1[2] = _rmapiAllocWithSecInfo_STUB;
  param_1[3] = _rmapiFree_STUB;
  param_1[4] = _rmapiFreeWithSecInfo_STUB;
  param_1[5] = _rmapiDisableClients_STUB;
  param_1[6] = _rmapiDisableClientsWithSecInfo_STUB;
  param_1[7] = _rmapiControl_STUB;
  param_1[8] = _rmapiControlWithSecInfo_STUB;
  param_1[9] = _rmapiControlPrefetch_STUB;
  param_1[10] = _rmapiDupObject_STUB;
  param_1[0xb] = _rmapiDupObjectWithSecInfo_STUB;
  param_1[0xc] = _rmapiShare_STUB;
  param_1[0xd] = _rmapiShareWithSecInfo_STUB;
  param_1[0xe] = _rmapiMapToCpu_STUB;
  param_1[0xf] = _rmapiMapToCpuWithSecInfo_STUB;
  param_1[0x11] = _rmapiUnmapFromCpu_STUB;
  param_1[0x12] = _rmapiUnmapFromCpuWithSecInfo_STUB;
  param_1[0x13] = _rmapiMap_STUB;
  param_1[0x14] = _rmapiMapWithSecInfo_STUB;
  param_1[0x15] = _rmapiUnmap_STUB;
  param_1[0x16] = _rmapiUnmapWithSecInfo_STUB;
  return;
}


// ===== 004bcc50 rmapiutilFreeClientAndDeviceHandles =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void rmapiutilFreeClientAndDeviceHandles(long param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    nvAssertFailedNoLog("phClient != NULL","src/kernel/rmapi/rmapi_utils.c",0x82);
    return;
  }
  iVar1 = *param_2;
  if (iVar1 != 0) {
    if ((param_4 != (int *)0x0) && (*param_4 != 0)) {
      (**(code **)(param_1 + 0x18))();
      *param_4 = 0;
      iVar1 = *param_2;
    }
    if ((param_3 != (int *)0x0) && (*param_3 != 0)) {
      (**(code **)(param_1 + 0x18))();
      *param_3 = 0;
      iVar1 = *param_2;
    }
    (**(code **)(param_1 + 0x18))(param_1,iVar1,iVar1);
    *param_2 = 0;
    return;
  }
  nvCheckFailedNoLog(4,"*phClient != NV01_NULL_OBJECT","src/kernel/rmapi/rmapi_utils.c",0x83);
  return;
}


// ===== 004bcd50 rmapiutilAllocClientAndDeviceHandles =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong rmapiutilAllocClientAndDeviceHandles
                (long param_1,long param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 *param_5)

{
  uint uVar1;
  ulong uVar2;
  char *pcVar3;
  undefined8 uVar4;
  undefined8 uStack_a0;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70 [8];
  
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  if (param_3 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("phClient != NULL","src/kernel/rmapi/rmapi_utils.c",0x3a);
    return 0x1f;
  }
  uVar1 = (**(code **)(param_1 + 8))(param_1,0,0,0,0,&local_7c);
  if (uVar1 == 0) {
    uVar1 = serverutilGenResourceHandle(local_7c,&local_78);
    uVar4 = 0x48;
    pcVar3 = "serverutilGenResourceHandle(hClient, &hDevice)";
    if (uVar1 == 0) {
      portMemSet(local_70,0,0x38,"src/kernel/rmapi/rmapi_utils.c",0x48);
      local_70[0] = CONCAT44(local_7c,*(undefined4 *)(param_2 + 0x7b4));
      uVar1 = (**(code **)(param_1 + 8))(param_1,local_7c,local_7c,local_78,0x80,local_70,0x38);
      if (uVar1 == 0) {
        uVar2 = serverutilGenResourceHandle(local_7c,&local_74);
        uVar4 = 0x5b;
        pcVar3 = "serverutilGenResourceHandle(hClient, &hSubDevice)";
        if ((int)uVar2 == 0) {
          portMemSet(&local_80,0,4,"src/kernel/rmapi/rmapi_utils.c",0x5b);
          local_80 = gpumgrGetSubDeviceInstanceFromGpu(param_2);
          uVar2 = (**(code **)(param_1 + 8))(param_1,local_7c,local_78,local_74,0x2080,&local_80,4);
          if ((int)uVar2 == 0) {
            *param_3 = local_7c;
            if (param_4 != (undefined4 *)0x0) {
              *param_4 = local_78;
            }
            if (param_5 == (undefined4 *)0x0) {
              return uVar2;
            }
            *param_5 = local_74;
            return uVar2;
          }
          uVar4 = 0x62;
          pcVar3 = 
          "pRmApi->AllocWithHandle(pRmApi, hClient, hDevice, hSubDevice, NV20_SUBDEVICE_0, &nv2080AllocParams, sizeof(nv2080AllocParams))"
          ;
        }
        uVar1 = (uint)uVar2;
        nvCheckOkFailedNoLog(4,uVar2 & 0xffffffff,pcVar3,"src/kernel/rmapi/rmapi_utils.c",uVar4);
        goto LAB_004bcf38;
      }
      uVar4 = 0x50;
      pcVar3 = 
      "pRmApi->AllocWithHandle(pRmApi, hClient, hClient, hDevice, NV01_DEVICE_0, &nv0080AllocParams, sizeof(nv0080AllocParams))"
      ;
    }
    nvCheckOkFailedNoLog(4,uVar1,pcVar3,"src/kernel/rmapi/rmapi_utils.c",uVar4);
  }
  else {
    nvCheckOkFailedNoLog
              (4,uVar1,
               "pRmApi->AllocWithHandle(pRmApi, NV01_NULL_OBJECT, NV01_NULL_OBJECT, NV01_NULL_OBJECT, NV01_ROOT, &hClient, sizeof(hClient))"
               ,"src/kernel/rmapi/rmapi_utils.c",0x3d,uStack_a0);
  }
LAB_004bcf38:
  rmapiutilFreeClientAndDeviceHandles(param_1,&local_7c,&local_78,&local_74);
  return (ulong)uVar1;
}


// ===== 004bcff0 rmapiutilIsExternalClassIdInternalOnly =====

byte rmapiutilIsExternalClassIdInternalOnly(void)

{
  long lVar1;
  
  lVar1 = RsResInfoByExternalClassId();
  if (lVar1 != 0) {
    return *(byte *)(lVar1 + 0x24) >> 7;
  }
  nvAssertFailedNoLog("pResDesc != NULL","src/kernel/rmapi/rmapi_utils.c",0x9c);
  return 0;
}


// ===== 004bd030 rmapiutilGetControlInfo =====

undefined8
rmapiutilGetControlInfo(uint param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  long lVar1;
  
  lVar1 = RsResInfoByExternalClassId(param_1 >> 0x10);
  if ((lVar1 != 0) && (*(long *)(lVar1 + 8) != 0)) {
    lVar1 = nvocGetExportedMethodDefFromMethodInfo_IMPL
                      (*(undefined8 *)(*(long *)(lVar1 + 8) + 0x28),param_1);
    if (lVar1 != 0) {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = *(undefined4 *)(lVar1 + 8);
      }
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = *(undefined4 *)(lVar1 + 0xc);
      }
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = *(undefined4 *)(lVar1 + 0x14);
      }
      return 0;
    }
  }
  return 0x57;
}


// ===== 004bd0b0 rmapiutilSkipErrorMessageForUnsupportedVgpuGuestControl =====

bool rmapiutilSkipErrorMessageForUnsupportedVgpuGuestControl(undefined8 param_1,uint param_2)

{
  char cVar1;
  
  if (param_2 == 0x90e60101) {
    cVar1 = rmcfg_IsTURING_CLASSIC_GPUSorBetter();
    return cVar1 == '\0';
  }
  if (0x90e60101 < param_2) {
    return param_2 == 0x90e70113;
  }
  if (param_2 < 0x20801345) {
    if (0x2080130b < param_2) {
      return (0x100800000400001U >> ((ulong)(param_2 + 0xdf7fecf4) & 0x3f) & 1) != 0;
    }
    if (param_2 < 0x208001af) {
      if (0x20800172 < param_2) {
        return (0x900000000000001U >> ((ulong)(param_2 + 0xdf7ffe8d) & 0x3f) & 1) != 0;
      }
      if (0x20800160 < param_2) {
        return false;
      }
      if (0x2080013e < param_2) {
        return (0x201e01001U >> ((ulong)(param_2 + 0xdf7ffec1) & 0x3f) & 1) != 0;
      }
      if (param_2 != 0x142) {
        return param_2 == 0x801306;
      }
    }
    else if (param_2 != 0x2080080b) {
      if (param_2 < 0x2080080c) {
        if (0xf < param_2 + 0xdf7ff9ff) {
          return false;
        }
        return (0x800dUL >> ((ulong)(param_2 + 0xdf7ff9ff) & 0x3f) & 1) != 0;
      }
      if (param_2 != 0x2080080e) {
        return param_2 == 0x20800aad;
      }
    }
  }
  else if (param_2 != 0x20803120) {
    if (param_2 < 0x20803121) {
      if (param_2 < 0x20801819) {
        if (param_2 < 0x20801805) {
          return param_2 == 0x20801357;
        }
        return (0xcc001UL >> ((ulong)(param_2 + 0xdf7fe7fb) & 0x3f) & 1) != 0;
      }
      if ((param_2 != 0x20802801) && (param_2 != 0x20803083)) {
        return param_2 == 0x20802609;
      }
    }
    else if (param_2 != 0x20804101) {
      if (param_2 < 0x20804102) {
        if (5 < param_2 + 0xdf7fcbff) {
          return false;
        }
        return (0x29UL >> ((ulong)(param_2 + 0xdf7fcbff) & 0x3f) & 1) != 0;
      }
      if (param_2 != 0x402c0103) {
        return param_2 + 0x6f33fcff < 2;
      }
    }
  }
  return true;
}


// ===== 004bd2b0 initRpcObject =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

long initRpcObject(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = portMemAllocNonPaged(0x2f00);
  if (lVar2 == 0) {
    nvDbg_Printf("src/kernel/rmapi/rpc_common.c",0x5a,"initRpcObject",4,
                 "NVRM: cannot allocate memory for OBJRPC (instance %d)\n",
                 *(undefined4 *)(param_1 + 0x7a4));
  }
  else {
    *(undefined8 *)(lVar2 + 0x2d24) = 0;
    *(undefined1 *)(lVar2 + 0x2d2c) = 0;
    if (*(char *)(param_1 + 0x90a) == '\0') {
      rpcSetIpVersion(param_1,lVar2,0x2d030000);
      rpcObjIfacesSetup(lVar2);
      if (*(char *)(param_1 + 0x908) == '\0') {
        if (*(char *)(param_1 + 0x90a) != '\0') goto LAB_004bd308;
        if (*(char *)(param_1 + 0x909) != '\0') {
          *(code **)(param_1 + 0x3b90) = rpcRmApiControl_GSP;
          *(code **)(param_1 + 0x3b60) = rpcRmApiAlloc_GSP;
          *(code **)(param_1 + 0x3b70) = rpcRmApiFree_GSP;
          *(code **)(param_1 + 0x3ba8) = rpcRmApiDupObject_GSP;
          return lVar2;
        }
      }
      else {
        if (*(char *)(param_1 + 0x909) != '\0') {
          return lVar2;
        }
        if (*(char *)(param_1 + 0x90a) != '\0') {
          return lVar2;
        }
      }
      iVar1 = (**(code **)(lVar2 + 8))(param_1,lVar2);
      if (iVar1 != 0) {
        nvDbg_Printf("src/kernel/rmapi/rpc_common.c",0x73,"initRpcObject",4,
                     "NVRM: rpcConstruct failed\n");
        portMemFree(lVar2);
        lVar2 = 0;
      }
    }
    else if (*(char *)(param_1 + 0x908) == '\0') {
LAB_004bd308:
      *(code **)(param_1 + 0x3b90) = rpcRmApiControl_dce;
      *(code **)(param_1 + 0x3b60) = rpcRmApiAlloc_dce;
      *(code **)(param_1 + 0x3b70) = rpcRmApiFree_dce;
      *(code **)(param_1 + 0x3ba8) = rpcRmApiDupObject_dce;
      return lVar2;
    }
  }
  return lVar2;
}


// ===== 004bd460 rpcWriteCommonHeader =====

undefined8 rpcWriteCommonHeader(long param_1,long param_2,int param_3,int param_4)

{
  char cVar1;
  long lVar2;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pGpu != NULL","src/kernel/rmapi/rpc_common.c",0x80);
    return 0x1f;
  }
  cVar1 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_1 + 0x7a4));
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(pGpu->gpuInstance)","src/kernel/rmapi/rpc_common.c",
                        0x81);
  }
  if (((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4a4e) == '\0')) ||
     (*(char *)(*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) + 0x26153) != '\0'))
  {
    if (param_2 != 0) {
      if (param_3 == 0xcc) {
        portMemSet(*(undefined8 *)(param_2 + 0x4d8),0,*(undefined4 *)(param_2 + 0x4f4));
      }
      else {
        portMemSet(*(undefined8 *)(param_2 + 0x4d8),0,*(undefined4 *)(param_2 + 0x4f0));
      }
      **(undefined4 **)(param_2 + 0x4d8) = 0x3000000;
      *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 4) = 0x43505256;
      *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x10) = 0xffffffff;
      *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x14) = 0xffffffff;
      if ((*(char *)(param_1 + 0x491d) == '\0') || (*(char *)(param_1 + 0x909) == '\0')) {
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x1c) = 0;
      }
      else {
        lVar2 = vgpuGetCallingContextDevice(param_1);
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x1c) = 0;
        if ((lVar2 != 0) && (lVar2 = *(long *)(lVar2 + 0x1d8), lVar2 != 0)) {
          if (*(char *)(lVar2 + 0x889) == '\0') {
            nvAssertFailedNoLog("pDevice->pKernelHostVgpuDevice->bGspPluginTaskInitialized",
                                "src/kernel/rmapi/rpc_common.c",0xac);
            return 0x40;
          }
          *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x1c) = *(undefined4 *)(lVar2 + 0x18);
        }
      }
      *(int *)(*(long *)(param_2 + 0x4d8) + 0xc) = param_3;
      *(int *)(*(long *)(param_2 + 0x4d8) + 8) = param_4 + 0x20;
      return 0;
    }
    nvDbg_Printf("src/kernel/rmapi/rpc_common.c",0x8f,"rpcWriteCommonHeader",4,
                 "NVRM: NVRM_RPC: called with NULL pRpc.  Function %d.\n",param_3);
    nvAssertFailedNoLog(&DAT_00d97be5,"src/kernel/rmapi/rpc_common.c",0x91);
  }
  else {
    nvDbg_Printf("src/kernel/rmapi/rpc_common.c",0x88,"rpcWriteCommonHeader",4,
                 "NVRM: NVRM_RPC: RPC buffer not initialized. Function %d\n",param_3);
  }
  return 0x40;
}


// ===== 004bd700 serverutilGetResourceRef =====

undefined8 serverutilGetResourceRef(undefined4 param_1,undefined4 param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_28;
  undefined8 local_20;
  
  *param_3 = 0;
  iVar1 = serverGetClientUnderLock(g_resServ,param_1,&local_20);
  uVar2 = 0x23;
  if (iVar1 == 0) {
    uVar2 = clientGetResourceRef_IMPL(local_20,param_2,&local_28);
    if ((int)uVar2 == 0) {
      *param_3 = local_28;
    }
  }
  return uVar2;
}


// ===== 004bd760 serverutilGetResourceRefWithType =====

undefined8
serverutilGetResourceRefWithType
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,long *param_4)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long local_38;
  undefined8 local_30 [2];
  
  *param_4 = 0;
  iVar1 = serverGetClientUnderLock(g_resServ,param_1,local_30);
  if (iVar1 == 0) {
    iVar1 = clientGetResourceRef_IMPL(local_30[0],param_2,&local_38);
    if (iVar1 == 0) {
      *param_4 = local_38;
      lVar2 = objDynamicCastById_IMPL(*(undefined8 *)(local_38 + 8),param_3);
      uVar3 = 0x33;
      if (lVar2 != 0) {
        uVar3 = 0;
      }
      return uVar3;
    }
  }
  return 0x57;
}


// ===== 004bd7f0 serverutilGetResourceRefWithParent =====

undefined8
serverutilGetResourceRefWithParent
          (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,long *param_5)

{
  int iVar1;
  long lVar2;
  long local_38;
  undefined8 local_30;
  
  *param_5 = 0;
  iVar1 = serverGetClientUnderLock(g_resServ,param_1,&local_30);
  if (iVar1 == 0) {
    iVar1 = clientGetResourceRef_IMPL(local_30,param_3,&local_38);
    if (iVar1 == 0) {
      *param_5 = local_38;
      iVar1 = 0;
      if (*(long *)(local_38 + 0x18) != 0) {
        iVar1 = *(int *)(*(long *)(local_38 + 0x18) + 0x10);
      }
      lVar2 = objDynamicCastById_IMPL(*(undefined8 *)(local_38 + 8),param_4);
      if ((iVar1 == param_2) && (lVar2 != 0)) {
        return 0;
      }
      return 0x33;
    }
  }
  return 0x57;
}


// ===== 004bd8b0 serverutilGetClientUnderLock =====

undefined8 serverutilGetClientUnderLock(undefined4 param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_10;
  
  iVar1 = serverGetClientUnderLock(g_resServ,param_1,&local_10);
  if (iVar1 == 0) {
    uVar2 = __nvoc_dynamicCast(local_10,__nvoc_class_def_RmClient);
    return uVar2;
  }
  return 0;
}


// ===== 004bd8f0 serverutilGetFirstClientUnderLock =====

void serverutilGetFirstClientUnderLock(void)

{
  listHead_IMPL(g_clientListBehindGpusLock);
  return;
}


// ===== 004bd900 serverutilGetNextClientUnderLock =====

void serverutilGetNextClientUnderLock(undefined8 param_1)

{
  listNext_IMPL(g_clientListBehindGpusLock,param_1);
  return;
}


// ===== 004bd920 serverutilFindChildRefByType =====

undefined8
serverutilFindChildRefByType
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  int iVar1;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30 [2];
  
  iVar1 = serverGetClientUnderLock(g_resServ,param_1,&local_40);
  if (iVar1 == 0) {
    iVar1 = clientGetResourceRef_IMPL(local_40,param_2,local_30);
    if (iVar1 == 0) {
      iVar1 = refFindChildOfType(local_30[0],param_3,param_4,&local_38);
      if (iVar1 == 0) {
        return local_38;
      }
    }
  }
  return 0;
}


// ===== 004bd9a0 serverutilRefIter =====

undefined8 *
serverutilRefIter(undefined8 *param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 undefined4 param_5,undefined1 param_6)

{
  int iVar1;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_88 = 0;
  portMemSet(&local_80,0,0x48);
  iVar1 = serverGetClientUnderLock(g_resServ,param_2,&local_90);
  if (iVar1 == 0) {
    if (param_3 != 0) {
      iVar1 = clientGetResourceRef_IMPL(local_90,param_3,&local_88);
      if (iVar1 != 0) goto LAB_004bda4f;
    }
    clientRefIter(param_1,local_90,local_88,param_4,param_5,param_6);
  }
  else {
LAB_004bda4f:
    *param_1 = local_80;
    param_1[1] = local_78;
    param_1[2] = local_70;
    param_1[3] = local_68;
    param_1[4] = local_60;
    param_1[5] = local_58;
    param_1[6] = local_50;
    param_1[7] = local_48;
    param_1[8] = local_40;
  }
  return param_1;
}


// ===== 004bdaa0 serverutilValidateNewResourceHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

bool serverutilValidateNewResourceHandle(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  undefined8 local_20 [2];
  
  iVar1 = serverGetClientUnderLock(g_resServ,param_1,local_20);
  if (iVar1 == 0) {
    lVar2 = __nvoc_dynamicCast(local_20[0],__nvoc_class_def_RmClient);
    if (lVar2 != 0) {
      iVar1 = (**(code **)(**(long **)(lVar2 + 0x100) + 0x78))(*(long **)(lVar2 + 0x100),param_2,1);
      return iVar1 == 0;
    }
  }
  return false;
}


// ===== 004bdb10 serverutilGenResourceHandle =====

undefined8 serverutilGenResourceHandle(undefined4 param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 local_20;
  
  cVar1 = rmapiLockIsOwner();
  if (cVar1 == '\0') {
    cVar1 = rmapiInRtd3PmPath();
    if (cVar1 == '\0') {
      nvAssertFailedNoLog("rmapiLockIsOwner() || rmapiInRtd3PmPath()","src/kernel/rmapi/rs_utils.c",
                          0xfd);
      return 0x2f;
    }
  }
  iVar2 = serverGetClientUnderLock(g_resServ,param_1,&local_20);
  if (iVar2 == 0) {
    lVar3 = __nvoc_dynamicCast(local_20,__nvoc_class_def_RmClient);
    if (lVar3 != 0) {
      uVar4 = clientGenResourceHandle_IMPL(*(undefined8 *)(lVar3 + 0x100),param_2);
      return uVar4;
    }
  }
  return 0x23;
}


// ===== 004bdbc0 serverutilShareIter =====

undefined8 serverutilShareIter(undefined8 param_1,undefined4 param_2)

{
  serverShareIter(param_1,g_resServ,param_2);
  return param_1;
}


// ===== 004bdbf0 serverutilShareIterNext =====

void serverutilShareIterNext(void)

{
  serverShareIterNext();
  return;
}


// ===== 004bdc00 serverutilMappingFilterCurrentUserProc =====

bool serverutilMappingFilterCurrentUserProc(long param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(*(long *)(param_1 + 0x50) + 0x24) != '\0') {
    return false;
  }
  iVar1 = *(int *)(param_1 + 0x48);
  iVar2 = osGetCurrentProcess();
  return iVar1 == iVar2;
}


// ===== 004bdc40 serverutilMappingFilterKernel =====

undefined1 serverutilMappingFilterKernel(long param_1)

{
  return *(undefined1 *)(*(long *)(param_1 + 0x50) + 0x24);
}


// ===== 004bdc50 serverutilAcquireClient =====

undefined8
serverutilAcquireClient(undefined4 param_1,undefined4 param_2,long *param_3,long *param_4)

{
  char cVar1;
  int iVar2;
  long lVar3;
  long local_30;
  
  cVar1 = rmapiLockIsOwner();
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/rs_utils.c",0x165);
    return 0x2f;
  }
  iVar2 = serverAcquireClient(g_resServ,param_1,param_2,&local_30);
  if (iVar2 == 0) {
    lVar3 = __nvoc_dynamicCast(*(undefined8 *)(local_30 + 8),__nvoc_class_def_RmClient);
    if (lVar3 != 0) {
      *param_3 = local_30;
      *param_4 = lVar3;
      return 0;
    }
    serverReleaseClient(g_resServ,param_2);
  }
  return 0x23;
}


// ===== 004bdd20 serverutilReleaseClient =====

void serverutilReleaseClient(undefined4 param_1,undefined8 param_2)

{
  serverReleaseClient(g_resServ,param_1,param_2);
  return;
}


// ===== 004bdd40 findParentGpu =====

undefined8 findParentGpu(long param_1)

{
  int iVar1;
  long lVar2;
  long local_20 [2];
  
  if ((param_1 == 0) || (*(long *)(param_1 + 8) == 0)) {
    return 0;
  }
  lVar2 = __nvoc_dynamicCast(*(long *)(param_1 + 8),__nvoc_class_def_GpuResource);
  if (lVar2 == 0) {
    iVar1 = refFindAncestorOfType(param_1,&DAT_00e0ac20,local_20);
    if (iVar1 != 0) {
      return 0;
    }
    lVar2 = __nvoc_dynamicCast(*(undefined8 *)(local_20[0] + 8),__nvoc_class_def_GpuResource);
    if (lVar2 == 0) {
      return 0;
    }
  }
  return *(undefined8 *)(lVar2 + 0xe0);
}


// ===== 004bddd0 rmapiDupObject =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1  [16] rmapiDupObject(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined4 in_stack_00000008;
  
  if (*(char *)(param_1 + 0xd8) != '\0') {
    auVar1._0_8_ = (**(code **)(param_1 + 0x58))();
    auVar1._8_4_ = in_stack_00000008;
    auVar1._12_4_ = 0;
    return auVar1;
  }
  auVar2._8_8_ = param_3;
  auVar2._0_8_ = 0x56;
  return auVar2;
}


// ===== 004bde10 rmapiDupObjectWithSecInfo =====

int rmapiDupObjectWithSecInfo
              (undefined8 param_1,undefined4 param_2,ulong param_3,undefined4 *param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined8 param_8)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_d4;
  undefined1 local_d0 [64];
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_70;
  undefined8 local_48;
  undefined1 *local_40;
  
  local_d4 = 0;
  nvDbg_Printf("src/kernel/rmapi/sharing.c",0x6a,"rmapiDupObjectWithSecInfo",1,
               "NVRM: Nv04DupObject: hClient:0x%x hParent:0x%x hObject:0x%x\n",param_2,param_3,
               *param_4);
  nvDbg_Printf("src/kernel/rmapi/sharing.c",0x6d,"rmapiDupObjectWithSecInfo",1,
               "NVRM: Nv04DupObject:  hClientSrc:0x%x hObjectSrc:0x%x flags:0x%x\n",param_5,param_6,
               param_7);
  iVar1 = rmapiPrologue(param_1,&local_d4);
  if (iVar1 == 0) {
    portMemSet(local_d0,0,0x40);
    iVar2 = rmapiInitLockInfo(param_1,param_2,param_5,local_d0);
    if (iVar2 == 0) {
      portMemSet(&local_90,0,0x58);
      local_80 = *param_4;
      local_70 = param_7;
      local_40 = local_d0;
      local_84 = (undefined4)param_3;
      local_48 = param_8;
      local_90 = param_5;
      local_8c = param_6;
      local_88 = param_2;
      iVar1 = serverCopyResource(g_resServ,&local_90);
      if (iVar1 == 0) {
        *param_4 = local_80;
        rmapiEpilogue(param_1,&local_d4);
        nvDbg_Printf("src/kernel/rmapi/sharing.c",0x85,"rmapiDupObjectWithSecInfo",1,
                     "NVRM: ...handle dup complete\n");
      }
      else {
        rmapiEpilogue(param_1,&local_d4);
        uVar3 = nvstatusToString(iVar1);
        nvDbg_Printf("src/kernel/rmapi/sharing.c",0x89,"rmapiDupObjectWithSecInfo",1,
                     "NVRM: Nv04DupObject: dup failed; status: %s (0x%08x)\n",uVar3,iVar1);
        nvDbg_Printf("src/kernel/rmapi/sharing.c",0x8c,"rmapiDupObjectWithSecInfo",1,
                     "NVRM: Nv04DupObject:  hClient:0x%x hParent:0x%x hObject:0x%x\n",param_2,
                     param_3 & 0xffffffff,*param_4);
        nvDbg_Printf("src/kernel/rmapi/sharing.c",0x8f,"rmapiDupObjectWithSecInfo",1,
                     "NVRM: Nv04DupObject:  hClientSrc:0x%x hObjectSrc:0x%x flags:0x%x\n",param_5,
                     param_6,param_7);
      }
    }
    else {
      rmapiEpilogue(param_1,&local_d4);
    }
  }
  return iVar1;
}


// ===== 004be0a0 rmapiDupObjectWithSecInfoTls =====

undefined4
rmapiDupObjectWithSecInfoTls
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined8 param_8)

{
  undefined4 uVar1;
  undefined1 local_a8 [144];
  
  threadStateInit(local_a8,0);
  uVar1 = rmapiDupObjectWithSecInfo(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8)
  ;
  threadStateFree(local_a8,0);
  return uVar1;
}


// ===== 004be130 rmapiShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 rmapiShare(long param_1)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 0xd8) != '\0') {
    uVar1 = (**(code **)(param_1 + 0x68))();
    return uVar1;
  }
  return 0x56;
}


// ===== 004be160 rmapiShareWithSecInfo =====

int rmapiShareWithSecInfo
              (undefined8 param_1,undefined4 param_2,ulong param_3,undefined4 *param_4,long param_5)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_b4;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 *local_90;
  long local_88;
  long *local_80;
  long local_78 [9];
  
  local_9c = 0;
  nvDbg_Printf("src/kernel/rmapi/sharing.c",0xe5,"rmapiShareWithSecInfo",1,
               "NVRM: Nv04Share: hClient:0x%x hObject:0x%x pSharePolicy:%p\n",param_2,param_3);
  iVar1 = rmapiPrologue(param_1,&local_9c);
  if (iVar1 == 0) {
    if ((*(int *)(param_5 + 4) == 1) && (*(short *)(param_4 + 2) == 3)) {
      local_b4 = *param_4;
    }
    else {
      local_b4 = 0;
    }
    portMemSet(local_78,0,0x40,param_4);
    iVar2 = rmapiInitLockInfo(param_1,param_2,local_b4,local_78);
    if (iVar2 == 0) {
      if (local_78[0] != 0) {
        nvAssertFailedNoLog("lockInfo.pClient == NULL","src/kernel/rmapi/sharing.c",0x103);
      }
      portMemSet(&local_98,0,0x20);
      local_80 = local_78;
      local_94 = (undefined4)param_3;
      local_98 = param_2;
      local_90 = param_4;
      local_88 = param_5;
      iVar1 = serverShareResourceAccess(g_resServ,&local_98);
      rmapiEpilogue(param_1,&local_9c);
      if (iVar1 == 0) {
        nvDbg_Printf("src/kernel/rmapi/sharing.c",0x10b,"rmapiShareWithSecInfo",1,
                     "NVRM: ...resource share complete\n");
      }
      else {
        uVar3 = nvstatusToString(iVar1);
        nvDbg_Printf("src/kernel/rmapi/sharing.c",0x10f,"rmapiShareWithSecInfo",1,
                     "NVRM: Nv04Share: share failed; status: %s (0x%08x)\n",uVar3,iVar1);
        nvDbg_Printf("src/kernel/rmapi/sharing.c",0x112,"rmapiShareWithSecInfo",1,
                     "NVRM: Nv04Share:  hClient:0x%x hObject:0x%x pSharePolicy:%p\n",param_2,
                     param_3 & 0xffffffff,param_4);
      }
    }
    else {
      rmapiEpilogue(param_1,&local_9c);
    }
  }
  return iVar1;
}


// ===== 004be3a0 rmapiShareWithSecInfoTls =====

undefined4
rmapiShareWithSecInfoTls
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
          undefined8 param_5)

{
  undefined4 uVar1;
  undefined1 local_a8 [144];
  
  threadStateInit(local_a8,0);
  uVar1 = rmapiShareWithSecInfo(param_1,param_2,param_3,param_4,param_5);
  threadStateFree(local_a8,0);
  return uVar1;
}


// ===== 004be420 serverCopyResourceLookupLockFlags =====

undefined8
serverCopyResourceLookupLockFlags
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,uint *param_4)

{
  char cVar1;
  
  if (param_4 != (uint *)0x0) {
    cVar1 = serverSupportsReadOnlyLock(param_1,param_2,7);
    *param_4 = (uint)(cVar1 == '\0');
    return 0;
  }
  nvAssertFailedNoLog("pAccess != NULL","src/kernel/rmapi/sharing.c",0x139);
  return 0x1f;
}


// ===== 004be480 serverShareResourceLookupLockFlags =====

undefined8
serverShareResourceLookupLockFlags
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,uint *param_4)

{
  char cVar1;
  
  if (param_4 != (uint *)0x0) {
    cVar1 = serverSupportsReadOnlyLock(param_1,param_2,8);
    *param_4 = (uint)(cVar1 == '\0');
    return 0;
  }
  nvAssertFailedNoLog("pAccess != NULL","src/kernel/rmapi/sharing.c",0x14a);
  return 0x1f;
}


// ===== 004be4e0 serverInitGlobalSharePolicies =====

byte serverInitGlobalSharePolicies(long param_1)

{
  long lVar1;
  undefined1 local_24 [4];
  uint local_20;
  undefined2 local_1c;
  undefined1 local_1a;
  
  portMemSet(local_24,0,0xc);
  local_20 = local_20 | 1;
  local_1c = 4;
  lVar1 = listAppendValue_IMPL(param_1 + 0x58,local_24);
  if (lVar1 != 0) {
    portMemSet(local_24,0,0xc);
    local_20 = local_20 | 1;
    local_1c = 5;
    local_1a = 2;
    lVar1 = listAppendValue_IMPL(param_1 + 0x80,local_24);
    if (lVar1 != 0) {
      portMemSet(local_24,0,0xc);
      local_20 = local_20 | 1;
      local_1c = 7;
      lVar1 = listAppendValue_IMPL(param_1 + 0x80,local_24);
      return -(lVar1 == 0) & 0x51;
    }
  }
  return 0x51;
}


// ===== 004be5b0 serverUpdateLockFlagsForCopy =====

undefined8 serverUpdateLockFlagsForCopy(undefined8 param_1,long param_2)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  
  if (*(long *)(param_2 + 0x38) != 0) {
    lVar1 = *(long *)(param_2 + 0x50);
    lVar4 = RsResInfoByExternalClassId(*(undefined4 *)(*(long *)(param_2 + 0x38) + 0x11c));
    if (lVar4 == 0) {
      uVar6 = 0x31;
    }
    else {
      uVar3 = *(uint *)(lVar4 + 0x24);
      if ((uVar3 & 0x8000) == 0) {
        *(uint *)(lVar1 + 0x28) = *(uint *)(lVar1 + 0x28) | 4;
        uVar3 = *(uint *)(lVar4 + 0x24);
      }
      if ((uVar3 & 0x10000) != 0) {
        *(uint *)(lVar1 + 0x28) = *(uint *)(lVar1 + 0x28) | 8;
        uVar3 = *(uint *)(lVar4 + 0x24);
      }
      if ((uVar3 & 0x40000) != 0) {
        cVar2 = rmapiLockIsOwner();
        if (cVar2 == '\0') {
          *(uint *)(lVar1 + 0x28) = *(uint *)(lVar1 + 0x28) & 0xfffffffb;
        }
        else {
          lVar4 = findParentGpu(*(undefined8 *)(param_2 + 0x38));
          lVar5 = findParentGpu(*(undefined8 *)(param_2 + 0x40));
          if ((lVar4 == 0 || lVar5 == 0) || (lVar4 != lVar5)) {
            *(uint *)(lVar1 + 0x28) = *(uint *)(lVar1 + 0x28) & 0xfffffffb;
          }
          else {
            *(uint *)(lVar1 + 0x28) = *(uint *)(lVar1 + 0x28) | 8;
          }
        }
      }
      *(undefined8 *)(lVar1 + 0x10) = *(undefined8 *)(*(long *)(param_2 + 0x38) + 0x18);
      uVar6 = 0;
    }
    return uVar6;
  }
  return 0x40;
}


// ===== 004be6c0 rpcVgpuGspWriteScratchRegister_GA102 =====

void rpcVgpuGspWriteScratchRegister_GA102(long param_1,ulong param_2)

{
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x210c,param_2 >> 0x20,0);
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x2108,param_2 & 0xffffffff,0);
  return;
}


// ===== 004be730 rpcVgpuGspRingDoorbell_GA102 =====

void rpcVgpuGspRingDoorbell_GA102(long param_1,undefined4 param_2)

{
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x2200,param_2,0);
  return;
}


// ===== 004be760 rpcGetEngineUtilizationWrapper_GM204 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void rpcGetEngineUtilizationWrapper_GM204(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x408))();
  return;
}


// ===== 004be770 vgpuCreateObject =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

int vgpuCreateObject(long param_1)

{
  char cVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  int local_2c [3];
  
  local_2c[0] = 0;
  if (0xf < *(uint *)(param_1 + 0x7a4)) {
    nvDbg_Printf("src/kernel/vgpu/objvgpu.c",0x42,"vgpuCreateObject",4,
                 "NVRM: vGPU instances more than %d are not supported\n",0x10);
    return 0x56;
  }
  if (*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) == 0) {
    cVar1 = hypervisorIsType_IMPL(2);
    if (cVar1 != '\0') {
      *(undefined1 *)(param_1 + 0x472) = 0;
    }
    lVar3 = portMemAllocNonPaged(0x26190);
    if (lVar3 == 0) {
      nvDbg_Printf("src/kernel/vgpu/objvgpu.c",0x59,"vgpuCreateObject",4,
                   "NVRM: cannot allocate memory for OBJVGPU (instance %d)\n");
      return 0x51;
    }
    *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) = lVar3;
    iVar2 = initRpcInfrastructure_VGPU(param_1);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/vgpu/objvgpu.c",100,"vgpuCreateObject",4,
                   "NVRM: NVRM_RPC: _initRpcInfrastructure: failed.\n");
      nvAssertFailedNoLog(&DAT_00d9817d,"src/kernel/vgpu/objvgpu.c",0x65);
      return iVar2;
    }
    cVar1 = rmGpuGroupLockIsOwner(*(undefined4 *)(param_1 + 0x7a4),0,local_2c);
    if (cVar1 == '\0') {
      iVar2 = rmGpuGroupLockAcquire(*(undefined4 *)(param_1 + 0x7a4),0,0,0x8002,local_2c);
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,
                   "rmGpuGroupLockAcquire(pGpu->gpuInstance, GPU_LOCK_GRP_SUBDEVICE, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_RPC, &gpuMaskRelease)"
                   ,"src/kernel/vgpu/objvgpu.c",0x6c);
        return iVar2;
      }
      lVar4 = gpuGetRpc(param_1);
      if (lVar4 == 0) {
        if (local_2c[0] != 0) {
          rmGpuGroupLockRelease(local_2c[0],0);
        }
        goto LAB_004be844;
      }
      iVar2 = (**(code **)(lVar4 + 0x2c8))(param_1,lVar4,*(code **)(lVar4 + 0x2c8));
      if (local_2c[0] != 0) {
        rmGpuGroupLockRelease(local_2c[0],0);
      }
    }
    else {
      lVar4 = gpuGetRpc(param_1);
      if (lVar4 == 0) goto LAB_004be844;
      iVar2 = (**(code **)(lVar4 + 0x2c8))(param_1,lVar4,*(code **)(lVar4 + 0x2c8));
    }
    if (iVar2 == 0) {
LAB_004be844:
      *(undefined4 *)(lVar3 + 0x2614c) = *(undefined4 *)(*(long *)(lVar3 + 0x128) + 0xc);
      return 0;
    }
    nvDbg_Printf("src/kernel/vgpu/objvgpu.c",0x7d,"vgpuCreateObject",4,
                 "NVRM: NVRM_RPC: GET_STATIC_DATA : failed.\n");
  }
  else {
    iVar2 = 0x26;
    nvDbg_Printf("src/kernel/vgpu/objvgpu.c",0x4b,"vgpuCreateObject",4,
                 "NVRM: : %d vGPU instance already allocated\n");
  }
  return iVar2;
}


// ===== 004bea70 vgpuDestructObject =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void vgpuDestructObject(long param_1)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar1 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
  if (lVar1 != 0) {
    lVar3 = gpuGetRpc();
    if (lVar3 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/vgpu/objvgpu.c",0x96);
    }
    else {
      (**(code **)(lVar3 + 0x280))(param_1,lVar3,0,0,0,*(code **)(lVar3 + 0x280));
    }
    iVar2 = freeRpcInfrastructure_VGPU(param_1);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/vgpu/objvgpu.c",0x9c,"vgpuDestructObject",4,
                   "NVRM: NVRM_RPC: _freeRpcInfrastructure: failed.\n");
      nvAssertFailedNoLog(&DAT_00d9817d,"src/kernel/vgpu/objvgpu.c",0x9e);
    }
    teardownSysmemPfnBitMap(param_1,lVar1);
    portMemFree(lVar1);
    *(undefined8 *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) = 0;
    return;
  }
  nvAssertFailedNoLog("pVGpu != NULL","src/kernel/vgpu/objvgpu.c",0x94);
  return;
}


// ===== 004beb80 vgpuInitRegistryOverWrite =====

void vgpuInitRegistryOverWrite(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 local_24 [4];
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar1 = osReadRegistryDword(param_1,"RmDisableBigPagePerAddressSpace",local_24);
  if (iVar1 == 0) {
    if (*(char *)(param_1 + 0x908) == '\0') goto LAB_004bebb3;
  }
  else {
    nvDbg_Printf("src/kernel/vgpu/objvgpu.c",0xb8,"vgpuInitRegistryOverWrite",1,
                 "NVRM: Overwriting big page size to 64K\n");
    osWriteRegistryDword(param_1,"RMFermiBigPageSize",0x10000);
    if (*(char *)(param_1 + 0x908) == '\0') goto LAB_004bebb3;
    *(undefined1 *)(param_1 + 0x49f) = 1;
  }
  iVar1 = osReadRegistryDword(param_1,"RmWatchDogTimeOut",local_24);
  if (iVar1 != 0) {
    osWriteRegistryDword(param_1,"RmWatchDogTimeOut",2);
  }
LAB_004bebb3:
  local_20 = 0;
  local_1c = 0;
  iVar1 = osReadRegistryDword(param_1,"RMSetVGPUVersionMax",&local_1c);
  uVar3 = 0x1c0001;
  if (iVar1 == 0) {
    uVar3 = local_1c;
  }
  iVar1 = osReadRegistryDword(param_1,"RMSetVGPUVersionMin",&local_20);
  uVar2 = 0x180001;
  if (iVar1 == 0) {
    uVar2 = local_20;
  }
  kvgpumgrSetHostVgpuVersion(uVar2,uVar3);
  return;
}


// ===== 004beca0 vgpuGetCallingContextDevice =====

undefined8 vgpuGetCallingContextDevice(void)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = resservGetContextRefByType(&DAT_00e0ac20,1);
  if (lVar1 != 0) {
    uVar2 = __nvoc_dynamicCast(*(undefined8 *)(lVar1 + 8),__nvoc_class_def_Device);
    return uVar2;
  }
  return 0;
}


// ===== 004bece0 vgpuGetCallingContextKernelHostVgpuDevice =====

undefined8 vgpuGetCallingContextKernelHostVgpuDevice(long param_1,long *param_2)

{
  long lVar1;
  long lVar2;
  
  *param_2 = 0;
  lVar2 = resservGetTlsCallContext();
  if (lVar2 != 0) {
    lVar2 = resservGetContextRefByType(&DAT_00e0ac20,1);
    if ((lVar2 == 0) ||
       (lVar2 = __nvoc_dynamicCast(*(undefined8 *)(lVar2 + 8),__nvoc_class_def_Device), lVar2 == 0))
    {
      if ((*(char *)(param_1 + 0x491d) != '\0') && (*(char *)(param_1 + 0x491e) == '\0')) {
        nvAssertFailedNoLog("!gpuIsSriovEnabled(pGpu) || IS_SRIOV_HEAVY(pGpu)",
                            "src/kernel/vgpu/objvgpu.c",0x159);
        return 0x57;
      }
    }
    else {
      lVar1 = *(long *)(lVar2 + 0x1d8);
      *param_2 = lVar1;
      if ((lVar1 != 0) != (bool)(*(byte *)(lVar2 + 0x1b5) >> 5 & 1)) {
        nvAssertFailedNoLog("(pDevice->pKernelHostVgpuDevice != NULL) == !!(pDevice->deviceAllocFlags & NV_DEVICE_ALLOCATION_FLAGS_HOST_VGPU_DEVICE)"
                            ,"src/kernel/vgpu/objvgpu.c",0x15f);
        return 0x40;
      }
    }
  }
  return 0;
}


// ===== 004bedb0 vgpuGetCallingContextGfid =====

ulong vgpuGetCallingContextGfid(long param_1,uint *param_2)

{
  uint uVar1;
  ulong uVar2;
  int local_20;
  undefined4 uStack_1c;
  
  *param_2 = 0;
  if (*(char *)(param_1 + 0x491d) == '\0') {
    return 0;
  }
  uVar1 = vgpuGetCallingContextKernelHostVgpuDevice(param_1,&local_20);
  if (uVar1 == 0) {
    if (CONCAT44(uStack_1c,local_20) == 0) {
      uVar1 = *param_2;
    }
    else {
      uVar1 = *(uint *)(CONCAT44(uStack_1c,local_20) + 0x18);
      *param_2 = uVar1;
    }
    uVar2 = (ulong)uVar1;
    if (uVar1 != 0) {
      uVar2 = gpuGetGfidState_IMPL(param_1,uVar2,&local_20);
      if ((int)uVar2 == 0) {
        if (local_20 == 0) {
          nvAssertFailedNoLog("(gfidState != GFID_FREE)","src/kernel/vgpu/objvgpu.c",0x19c);
          uVar2 = 0x40;
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (uVar2 & 0xffffffff,"gpuGetGfidState(pGpu, *pGfid, &gfidState)",
                   "src/kernel/vgpu/objvgpu.c",0x199);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
  }
  else {
    nvAssertOkFailedNoLog
              (uVar1,"vgpuGetCallingContextKernelHostVgpuDevice(pGpu, &pKernelHostVgpuDevice)",
               "src/kernel/vgpu/objvgpu.c",0x18e);
    uVar2 = (ulong)uVar1;
  }
  return uVar2;
}


// ===== 004beea0 vgpuIsCallingContextPlugin =====

undefined4 vgpuIsCallingContextPlugin(long param_1,undefined1 *param_2)

{
  long lVar1;
  
  *param_2 = 0;
  if (*(char *)(param_1 + 0x491d) == '\0') {
    return 0;
  }
  lVar1 = resservGetTlsCallContext();
  if (lVar1 != 0) {
    lVar1 = resservGetContextRefByType(&DAT_00e0ac20,1);
    if ((lVar1 == 0) ||
       (lVar1 = __nvoc_dynamicCast(*(undefined8 *)(lVar1 + 8),__nvoc_class_def_Device), lVar1 == 0))
    {
      if ((*(char *)(param_1 + 0x491d) != '\0') && (*(char *)(param_1 + 0x491e) == '\0')) {
        nvAssertFailedNoLog("!gpuIsSriovEnabled(pGpu) || IS_SRIOV_HEAVY(pGpu)",
                            "src/kernel/vgpu/objvgpu.c",0x1e9);
        return 0x57;
      }
    }
    else {
      if ((*(uint *)(lVar1 + 0x1b4) & 0x4000) == 0) {
        return 0;
      }
      if (*(long *)(lVar1 + 0x1d8) == 0) {
        nvAssertFailedNoLog("pDevice->pKernelHostVgpuDevice","src/kernel/vgpu/objvgpu.c",0x1f0);
        return 0x40;
      }
      *param_2 = 1;
    }
  }
  return 0;
}


// ===== 004bef80 static_data_copy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void static_data_copy(long param_1,long param_2,undefined8 param_3,undefined4 param_4,uint *param_5,
                     char param_6)

{
  int iVar1;
  
  if (param_6 == '\0') {
    iVar1 = (**(code **)(param_1 + 0x80))(param_2 + 0x1f6d4,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0xb0))(param_2,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x1a0))(param_2 + 0x1ea80,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0xe0))(param_2 + 0xa1e4,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x68))(param_2 + 0x1f898,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x60))(param_2 + 0xa738,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x10))(param_2 + 0x1f9b8,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x20))(param_2 + 0x1e1d0,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x150))(param_2 + 0x25e98,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x48))(0,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x140))(param_2 + 0x1e278,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0xe8))(param_2 + 0x3e4,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x170))(param_2 + 0xa7a8,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x100))(param_2 + 0x40c,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x90))(param_2 + 0x6870,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x118))(param_2 + 0x1f190,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x1b8))(param_2 + 0x88f0,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x1a8))(param_2 + 0x8ce0,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x160))(param_2 + 0x8ee0,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0xa8))(param_2,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x168))(param_2 + 0x8f10,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 400))(param_2 + 0xa790,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x40))(param_2 + 0xa6f0,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x198))(param_2 + 0x90b8,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x180))(param_2 + 0x90d8,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x138))(param_2 + 0x1e0,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x120))(param_2 + 0xa0d0,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x108))(param_2 + 0xa140,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x30))(param_2 + 0xa1c8,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x1b0))(param_2 + 0x1f184,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x178))(param_2 + 0x1f1d0,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x28))(&DAT_00025e78 + param_2,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x58))(param_2 + 0x1fe4c,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 0x18))(param_2 + 0x25e50,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(param_1 + 200))(param_2 + 0x25ec8,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
  }
  else {
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x80))(param_2 + 0x1f6d4,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0xb0))(param_2,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x1a0))(param_2 + 0x1ea80,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0xe0))(param_2 + 0xa1e4,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x68))(param_2 + 0x1f898,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x60))(param_2 + 0xa738,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x10))(param_2 + 0x1f9b8,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x20))(param_2 + 0x1e1d0,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x150))(param_2 + 0x25e98,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x48))(0,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x140))(param_2 + 0x1e278,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0xe8))(param_2 + 0x3e4,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x170))(param_2 + 0xa7a8,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x100))(param_2 + 0x40c,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x90))(param_2 + 0x6870,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x118))(param_2 + 0x1f190,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x1b8))(param_2 + 0x88f0,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x1a8))(param_2 + 0x8ce0,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x160))(param_2 + 0x8ee0,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0xa8))(param_2,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x168))(param_2 + 0x8f10,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 400))(param_2 + 0xa790,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x40))(param_2 + 0xa6f0,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x198))(param_2 + 0x90b8,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x180))(param_2 + 0x90d8,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x138))(param_2 + 0x1e0,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x120))(param_2 + 0xa0d0,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x108))(param_2 + 0xa140,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x30))(param_2 + 0xa1c8,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x1b0))(param_2 + 0x1f184,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x178))(param_2 + 0x1f1d0,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x28))(&DAT_00025e78 + param_2,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x58))(param_2 + 0x1fe4c,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 0x18))(param_2 + 0x25e50,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
    iVar1 = (**(code **)(param_1 + 200))(param_2 + 0x25ec8,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return;
    }
    *param_5 = *param_5 + 7 & 0xfffffff8;
  }
  iVar1 = (**(code **)(param_1 + 0x128))(param_2 + 0xa7d0,param_3,param_4,param_5);
  if ((iVar1 == 0) && (0x2512ffff < *(uint *)(param_1 + 0x1c8))) {
    if (param_6 != '\0') {
      *param_5 = *param_5 + 7 & 0xfffffff8;
    }
    iVar1 = (**(code **)(param_1 + 0x70))(param_2 + 0x25ed4,param_3,param_4,param_5);
    if ((iVar1 == 0) && (0x2600ffff < *(uint *)(param_1 + 0x1c8))) {
      if (param_6 != '\0') {
        *param_5 = *param_5 + 7 & 0xfffffff8;
      }
      iVar1 = (**(code **)(param_1 + 0x110))(param_2 + 0x25edc,param_3,param_4,param_5);
      if ((iVar1 == 0) && (0x2904ffff < *(uint *)(param_1 + 0x1c8))) {
        if (param_6 != '\0') {
          *param_5 = *param_5 + 7 & 0xfffffff8;
        }
        iVar1 = (**(code **)(param_1 + 0x78))(param_2 + 0x25f20,param_3,param_4,param_5);
        if ((iVar1 == 0) && (0x2b09ffff < *(uint *)(param_1 + 0x1c8))) {
          if (param_6 == '\0') {
            iVar1 = (**(code **)(param_1 + 0x38))(param_2 + 0x25f28,param_3,param_4,param_5);
            if ((iVar1 == 0) &&
               (iVar1 = (**(code **)(param_1 + 0x130))(param_2 + 0x98d4,param_3,param_4,param_5),
               iVar1 == 0)) {
LAB_004bfc58:
              (**(code **)(param_1 + 0xa0))(param_2,param_3,param_4,param_5);
              return;
            }
          }
          else {
            *param_5 = *param_5 + 7 & 0xfffffff8;
            iVar1 = (**(code **)(param_1 + 0x38))(param_2 + 0x25f28,param_3,param_4,param_5);
            if (iVar1 == 0) {
              *param_5 = *param_5 + 7 & 0xfffffff8;
              iVar1 = (**(code **)(param_1 + 0x130))(param_2 + 0x98d4,param_3,param_4,param_5);
              if (iVar1 == 0) {
                *param_5 = *param_5 + 7 & 0xfffffff8;
                goto LAB_004bfc58;
              }
            }
          }
        }
      }
    }
  }
  return;
}


// ===== 004bfcc0 engine_utilization_copy_params_from_rpc_buffer_v09_0C =====

undefined8
engine_utilization_copy_params_from_rpc_buffer_v09_0C(uint param_1,long param_2,long param_3)

{
  if (param_1 == 0xb03) {
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_3 + 0xc);
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_3 + 0x10);
    *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)(param_3 + 0x18);
    *(undefined8 *)(param_2 + 0x20) = *(undefined8 *)(param_3 + 0x20);
    *(undefined8 *)(param_2 + 0x28) = *(undefined8 *)(param_3 + 0x28);
    return 0;
  }
  if (param_1 < 0xb04) {
    if (param_1 != 0xb01) {
      if (param_1 != 0xb02) goto LAB_004bfd10;
      *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_3 + 8);
    }
  }
  else if (param_1 != 0xb05) {
    if (param_1 == 0x20802087) {
      *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_3 + 4);
      *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_3 + 8);
      return 0;
    }
LAB_004bfd10:
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0xb36,
                 "engine_utilization_copy_params_from_rpc_buffer_v09_0C",4,
                 "NVRM: Unknown Engine Utilization Control Command 0x%x\n",param_1);
    return 0x56;
  }
  return 0;
}


// ===== 004bfd70 vgpuGspMakeBufferAddress =====

ulong vgpuGspMakeBufferAddress(long *param_1,long param_2)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  
  iVar2 = memdescGetAddressSpace(*param_1);
  lVar1 = *(long *)(*param_1 + 0x30);
  uVar3 = param_2 << 0xc | 3;
  if ((iVar2 != 1) && (uVar3 = param_2 << 0xc | 5, iVar2 != 2)) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x4b2,"vgpuGspMakeBufferAddress",4,
                 "NVRM: RPC: Invlid address space %d\n");
    uVar3 = 0;
  }
  if (lVar1 == 0x20000) {
    return uVar3 | 8;
  }
  if (lVar1 != 0x200000) {
    if (lVar1 != 0x1000) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x4c3,"vgpuGspMakeBufferAddress",4,
                   "NVRM: RPC: Invalid buffer size %lld\n",lVar1);
      uVar3 = 0;
    }
    return uVar3;
  }
  return uVar3 | 0x10;
}


// ===== 004bfe50 getStaticDataRpcBufferSize =====

int getStaticDataRpcBufferSize(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = static_data_copy(param_2,0,0,0,param_3,*(char *)(param_1 + 0x4a4e) != '\0');
  if (iVar1 == 0) {
    return 0;
  }
  nvDbg_Printf("src/kernel/vgpu/rpc.c",0x922,"getStaticDataRpcBufferSize",4,
               "NVRM: NVRM_RPC: Get static data RPC bufferSize: failed.\n");
  nvAssertFailedNoLog("status == NV_OK","src/kernel/vgpu/rpc.c",0x924);
  return iVar1;
}


// ===== 004bfee0 copyPayloadToStaticData =====

int copyPayloadToStaticData
              (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,long param_5)

{
  int iVar1;
  undefined4 local_c;
  
  local_c = 0;
  if (param_5 == 0) {
    nvAssertFailedNoLog("pVSI != NULL","src/kernel/vgpu/rpc.c",0x931);
    return 0x1f;
  }
  iVar1 = static_data_copy(param_2,param_5,param_3,param_4,&local_c,
                           *(char *)(param_1 + 0x4a4e) != '\0');
  if (iVar1 == 0) {
    return 0;
  }
  nvDbg_Printf("src/kernel/vgpu/rpc.c",0x939,"copyPayloadToStaticData",4,
               "NVRM: NVRM_RPC: copyPayloadToStaticData: failed.\n");
  nvAssertFailedNoLog("status == NV_OK","src/kernel/vgpu/rpc.c",0x93b);
  return iVar1;
}


// ===== 004bffa0 _vgpuGspWaitForResponse =====

undefined8 _vgpuGspWaitForResponse(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined1 local_30 [24];
  
  lVar1 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
  if (*(long *)(lVar1 + 0x120) == 0) {
    return 0x40;
  }
  timeoutSet(param_1 + 0x1af0,local_30,10000000,4);
  do {
    if (**(int **)(lVar1 + 0x128) == *(int *)(lVar1 + 0x158)) {
      LOCK();
      UNLOCK();
      return 0;
    }
    uVar2 = timeoutCheck(param_1 + 0x1af0,local_30,0x4d8);
  } while ((int)uVar2 != 0x65);
  return uVar2;
}


// ===== 004c0050 _rpcRecvPoll_VGPUGSP =====

void _rpcRecvPoll_VGPUGSP(void)

{
  _vgpuGspWaitForResponse();
  return;
}


// ===== 004c0060 engine_utilization_copy_params_to_rpc_buffer_v09_0C =====

undefined8
engine_utilization_copy_params_to_rpc_buffer_v09_0C
          (uint param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 == 0xb03) {
    *param_2 = *param_3;
    param_2[1] = param_3[1];
    return 0;
  }
  if (param_1 < 0xb04) {
    if (param_1 == 0xb01) {
      param_2[2] = param_3[2];
    }
    else if (param_1 != 0xb02) goto LAB_004c00a8;
  }
  else if (param_1 != 0xb05) {
    if (param_1 == 0x20802087) {
      *param_2 = *param_3;
      return 0;
    }
LAB_004c00a8:
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0xb71,"engine_utilization_copy_params_to_rpc_buffer_v09_0C"
                 ,4,"NVRM: Unknown Engine Utilization Control Command 0x%x\n",param_1);
    return 0x56;
  }
  return 0;
}


// ===== 004c00f0 _vgpuGspSendSetupRequest =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _vgpuGspSendSetupRequest(long param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  
  lVar3 = gpuGetRpc();
  if (lVar3 != 0) {
    (**(code **)(lVar3 + 0x238))(param_1,param_2);
    lVar1 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
    if (*(long *)(lVar1 + 0x120) != 0) {
      iVar2 = *(int *)(lVar1 + 0x158) + 1;
      *(int *)(lVar1 + 0x158) = iVar2;
      *(int *)(*(long *)(lVar1 + 0x120) + 4) = iVar2;
      LOCK();
      UNLOCK();
      (**(code **)(lVar3 + 0x210))(param_1,0);
    }
    uVar4 = _vgpuGspWaitForResponse(param_1);
    return uVar4;
  }
  nvCheckFailedNoLog(4,"(pRpc != NULL)","src/kernel/vgpu/rpc.c",0x500);
  return 0x3d;
}


// ===== 004c01b0 updateSharedBufferInfoInSysmemPfnBitMap.part.0 =====

int updateSharedBufferInfoInSysmemPfnBitMap_part_0
              (undefined8 param_1,long *param_2,undefined1 param_3,char param_4)

{
  int iVar1;
  long lVar2;
  
  for (lVar2 = listHead_IMPL(&DAT_0054eac0); lVar2 != 0; lVar2 = listNext_IMPL(&DAT_0054eac0,lVar2))
  {
    if ((*(long *)(lVar2 + 0x10) != 0) && (iVar1 = memdescGetAddressSpace(), iVar1 == 1)) {
      iVar1 = vgpuUpdateSysmemPfnBitMap(param_1,*(undefined8 *)(lVar2 + 0x10),param_3);
      if (iVar1 != 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x328,"updateSharedBufferInfoInSysmemPfnBitMap",1,
                     "NVRM: Failed to update sysmemPfnMap info in PFN bitmap, error 0x%x\n",iVar1);
        return iVar1;
      }
      *(undefined1 *)(lVar2 + 0x34) = 1;
    }
  }
  if (param_4 != '\0') {
    if (((param_2[0x13] != 0) && (iVar1 = memdescGetAddressSpace(), iVar1 == 1)) &&
       (iVar1 = vgpuUpdateSysmemPfnBitMap(param_1,param_2[0x13],param_3), iVar1 != 0)) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x339,"updateSharedBufferInfoInSysmemPfnBitMap",1,
                   "NVRM: Failed to update ctrl buff sysmem info in PFN bitmap, error 0x%x\n");
      return iVar1;
    }
    if (((param_2[0x17] != 0) && (iVar1 = memdescGetAddressSpace(), iVar1 == 1)) &&
       (iVar1 = vgpuUpdateSysmemPfnBitMap(param_1,param_2[0x17],param_3), iVar1 != 0)) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x344,"updateSharedBufferInfoInSysmemPfnBitMap",1,
                   "NVRM: Failed to update response buff sysmem info in PFN bitmap, error 0x%x\n");
      return iVar1;
    }
    if (((param_2[0x1b] != 0) && (iVar1 = memdescGetAddressSpace(), iVar1 == 1)) &&
       (iVar1 = vgpuUpdateSysmemPfnBitMap(param_1,param_2[0x1b],param_3), iVar1 != 0)) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x34f,"updateSharedBufferInfoInSysmemPfnBitMap",1,
                   "NVRM: Failed to update message buff sysmem info in PFN bitmap, error 0x%x\n");
      return iVar1;
    }
    if (((*param_2 != 0) && (iVar1 = memdescGetAddressSpace(), iVar1 == 1)) &&
       (iVar1 = vgpuUpdateSysmemPfnBitMap(param_1,*param_2,param_3), iVar1 != 0)) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x35a,"updateSharedBufferInfoInSysmemPfnBitMap",1,
                   "NVRM: Failed to update event mem sysmem in PFN bitmap, error 0x%x\n");
      return iVar1;
    }
    if (((param_2[0xf] != 0) && (iVar1 = memdescGetAddressSpace(), iVar1 == 1)) &&
       (iVar1 = vgpuUpdateSysmemPfnBitMap(param_1,param_2[0xf],param_3), iVar1 != 0)) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x365,"updateSharedBufferInfoInSysmemPfnBitMap",1,
                   "NVRM: Failed to update shared mem sysmem info in PFN bitmap, error 0x%x\n");
      return iVar1;
    }
    if (((param_2[0x26] != 0) && (iVar1 = memdescGetAddressSpace(), iVar1 == 1)) &&
       (iVar1 = vgpuUpdateSysmemPfnBitMap(param_1,param_2[0x26],param_3), iVar1 != 0)) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x370,"updateSharedBufferInfoInSysmemPfnBitMap",1,
                   "NVRM: Failed to update debug memory sysmem info in PFN bitmap, error 0x%x\n");
      return iVar1;
    }
  }
  if ((DAT_0054eab8 == 0) || (iVar1 = memdescGetAddressSpace(), iVar1 != 1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = vgpuUpdateSysmemPfnBitMap(param_1,DAT_0054eab8,param_3);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x37d,"updateSharedBufferInfoInSysmemPfnBitMap",1,
                   "NVRM: Failed to update PFN bitmap sysmem info in PFN bitmap, error 0x%x\n");
    }
  }
  return iVar1;
}


// ===== 004c0570 consolidated_gr_static_info_copy.constprop.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void consolidated_gr_static_info_copy_constprop_0
               (long param_1,long param_2,undefined8 param_3,undefined4 param_4,uint *param_5,
               char param_6)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1 + 0x88))(param_2 + 0xa8dc,param_3,param_4,param_5);
  if (iVar1 == 0) {
    if (param_6 == '\0') {
      iVar1 = (**(code **)(param_1 + 0x50))(param_2 + 0xc21c,param_3,param_4,param_5);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(param_1 + 0x148))(param_2 + 0x1e030,param_3,param_4,param_5);
        if (iVar1 == 0) {
          iVar1 = (**(code **)(param_1 + 0xd8))(param_2 + 0xbe1c,param_3,param_4,param_5);
          if (iVar1 == 0) {
            iVar1 = (**(code **)(param_1 + 0x188))(param_2 + 0xb79c,param_3,param_4,param_5);
            if (iVar1 == 0) {
              iVar1 = (**(code **)(param_1 + 0x98))(param_2 + 0x1493c,param_3,param_4,param_5);
              if (iVar1 == 0) {
                iVar1 = (**(code **)(param_1 + 8))(param_2 + 0x14984,param_3,param_4,param_5);
                if (iVar1 == 0) {
                  iVar1 = (**(code **)(param_1 + 0xf0))(param_2 + 0x1c944,param_3,param_4,param_5);
                  if (iVar1 == 0) {
                    iVar1 = (**(code **)(param_1 + 0xf8))(param_2 + 0x1e090,param_3,param_4,param_5)
                    ;
                    if (iVar1 == 0) {
                      iVar1 = (**(code **)(param_1 + 0x158))
                                        (param_2 + 0x1df04,param_3,param_4,param_5);
                      if (iVar1 == 0) {
                        iVar1 = (**(code **)(param_1 + 0xd0))
                                          (param_2 + 0x1df28,param_3,param_4,param_5);
                        if (iVar1 == 0) {
                          iVar1 = (**(code **)(param_1 + 0xc0))
                                            (param_2 + 0x1e028,param_3,param_4,param_5);
                          if (iVar1 == 0) goto LAB_004c0955;
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
    else {
      *param_5 = *param_5 + 7 & 0xfffffff8;
      iVar1 = (**(code **)(param_1 + 0x50))(param_2 + 0xc21c,param_3,param_4,param_5);
      if (iVar1 == 0) {
        *param_5 = *param_5 + 7 & 0xfffffff8;
        iVar1 = (**(code **)(param_1 + 0x148))(param_2 + 0x1e030,param_3,param_4,param_5);
        if (iVar1 == 0) {
          *param_5 = *param_5 + 7 & 0xfffffff8;
          iVar1 = (**(code **)(param_1 + 0xd8))(param_2 + 0xbe1c,param_3,param_4,param_5);
          if (iVar1 == 0) {
            *param_5 = *param_5 + 7 & 0xfffffff8;
            iVar1 = (**(code **)(param_1 + 0x188))(param_2 + 0xb79c,param_3,param_4,param_5);
            if (iVar1 == 0) {
              *param_5 = *param_5 + 7 & 0xfffffff8;
              iVar1 = (**(code **)(param_1 + 0x98))(param_2 + 0x1493c,param_3,param_4,param_5);
              if (iVar1 == 0) {
                *param_5 = *param_5 + 7 & 0xfffffff8;
                iVar1 = (**(code **)(param_1 + 8))(param_2 + 0x14984,param_3,param_4,param_5);
                if (iVar1 == 0) {
                  *param_5 = *param_5 + 7 & 0xfffffff8;
                  iVar1 = (**(code **)(param_1 + 0xf0))(param_2 + 0x1c944,param_3,param_4,param_5);
                  if (iVar1 == 0) {
                    *param_5 = *param_5 + 7 & 0xfffffff8;
                    iVar1 = (**(code **)(param_1 + 0xf8))(param_2 + 0x1e090,param_3,param_4,param_5)
                    ;
                    if (iVar1 == 0) {
                      *param_5 = *param_5 + 7 & 0xfffffff8;
                      iVar1 = (**(code **)(param_1 + 0x158))
                                        (param_2 + 0x1df04,param_3,param_4,param_5);
                      if (iVar1 == 0) {
                        *param_5 = *param_5 + 7 & 0xfffffff8;
                        iVar1 = (**(code **)(param_1 + 0xd0))
                                          (param_2 + 0x1df28,param_3,param_4,param_5);
                        if (iVar1 == 0) {
                          *param_5 = *param_5 + 7 & 0xfffffff8;
                          iVar1 = (**(code **)(param_1 + 0xc0))
                                            (param_2 + 0x1e028,param_3,param_4,param_5);
                          if (iVar1 == 0) {
                            *param_5 = *param_5 + 7 & 0xfffffff8;
LAB_004c0955:
                            (**(code **)(param_1 + 0xb8))(param_2 + 0x18964,param_3,param_4,param_5)
                            ;
                            return;
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
  }
  return;
}


// ===== 004c0980 _rpcSendMessage_VGPUGSP =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _rpcSendMessage_VGPUGSP(long param_1,long param_2,int *param_3)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
  if (param_3 == (int *)0x0) {
    nvAssertFailedNoLog("pSequence != NULL","src/kernel/vgpu/rpc.c",0x71e);
  }
  iVar2 = *(int *)(lVar1 + 0x154);
  *(int *)(lVar1 + 0x154) = iVar2 + 1;
  *param_3 = iVar2;
  *(int *)(*(long *)(param_2 + 0x4d8) + 0x18) = iVar2;
  lVar1 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
  if (*(long *)(lVar1 + 0x120) != 0) {
    iVar2 = *(int *)(lVar1 + 0x158) + 1;
    *(int *)(lVar1 + 0x158) = iVar2;
    *(int *)(*(long *)(lVar1 + 0x120) + 4) = iVar2;
    LOCK();
    UNLOCK();
    (**(code **)(param_2 + 0x210))(param_1,1);
  }
  return 0;
}


// ===== 004c0a50 _issueRpcLarge =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint _issueRpcLarge(undefined8 param_1,long param_2,uint param_3,long param_4,byte param_5,
                   char param_6)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  code *pcVar8;
  uint uVar9;
  ulong uVar10;
  long lVar11;
  int local_68;
  int local_5c;
  int *local_58;
  int local_3c [3];
  
  lVar11 = *(long *)(param_2 + 0x4d8);
  uVar1 = *(undefined4 *)(lVar11 + 0xc);
  uVar9 = *(uint *)(param_2 + 0x4f0);
  if (param_3 <= *(uint *)(param_2 + 0x4f0)) {
    uVar9 = param_3;
  }
  uVar10 = (ulong)uVar9;
  iVar2 = *(int *)(param_2 + 0x2d24);
  lVar6 = param_4;
  if (lVar11 != param_4) {
    portMemCopy(lVar11,uVar10,param_4,uVar10);
    lVar6 = *(long *)(param_2 + 0x4d8);
  }
  *(uint *)(lVar6 + 8) = uVar9;
  if (*(code **)(param_2 + 0x18) == _rpcSendMessage_VGPUGSP) {
    _rpcSendMessage_VGPUGSP(param_1,param_2,local_3c);
  }
  else {
    uVar4 = (**(code **)(param_2 + 0x18))(param_1,param_2,local_3c);
    if (uVar4 != 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x828,"_issueRpcLarge",4,
                   "NVRM: rpcSendMessage failed with status 0x%08x for fn %d!\n",uVar4,uVar1);
      nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0x82a);
      if (uVar4 != 3) {
        return uVar4;
      }
      return 0xffff;
    }
  }
  local_58 = local_3c;
  uVar9 = param_3 - uVar9;
  if (uVar9 == 0) {
    local_5c = 0;
    iVar5 = iVar2;
  }
  else {
    local_5c = 0;
    lVar11 = uVar10 + param_4;
    uVar10 = (ulong)(*(int *)(param_2 + 0x4f0) - 0x20);
    do {
      if (uVar9 < (uint)uVar10) {
        uVar10 = (ulong)uVar9;
      }
      cVar3 = gpuIsCCFeatureEnabled_IMPL(param_1);
      if (cVar3 != '\0') {
        portMemSet(*(undefined8 *)(param_2 + 0x4d8),0,0x20);
      }
      portMemCopy(*(long *)(param_2 + 0x4d8) + 0x20,uVar10,lVar11,uVar10);
      *(int *)(*(long *)(param_2 + 0x4d8) + 8) = (int)uVar10 + 0x20;
      *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0xc) = 0x47;
      if (*(code **)(param_2 + 0x18) == _rpcSendMessage_VGPUGSP) {
        _rpcSendMessage_VGPUGSP();
      }
      else {
        uVar4 = (**(code **)(param_2 + 0x18))(param_1,param_2,local_58);
        if (uVar4 != 0) {
          nvDbg_Printf("src/kernel/vgpu/rpc.c",0x84c,"_issueRpcLarge",4,
                       "NVRM: rpcSendMessage failed with status 0x%08x for fn %d continuation record (remainingSize=0x%x)!\n"
                       ,uVar4,uVar1,(ulong)uVar9);
          nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0x84f);
          if (uVar4 != 3) {
            return uVar4;
          }
          return 0xffff;
        }
      }
      local_5c = local_5c + 1;
      lVar11 = lVar11 + uVar10;
      uVar9 = uVar9 - (int)uVar10;
    } while (uVar9 != 0);
    iVar5 = iVar2 + local_5c;
  }
  if (local_3c[0] != iVar5) {
    nvAssertFailedNoLog("lastSequence == (firstSequence + recordCount)","src/kernel/vgpu/rpc.c",
                        0x85e);
  }
  if (param_6 == '\0') {
    return 0;
  }
  if (*(code **)(param_2 + 0x20) == _rpcRecvPoll_VGPUGSP) {
    uVar9 = _vgpuGspWaitForResponse(param_1);
  }
  else {
    uVar9 = (**(code **)(param_2 + 0x20))(param_1,param_2,uVar1,iVar2);
  }
  if (uVar9 != 0) {
    if (uVar9 == 0x65) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x86e,"_issueRpcLarge",4,
                   "NVRM: rpcRecvPoll timedout for fn %d sequence %d!\n",uVar1,iVar2);
    }
    else {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x873,"_issueRpcLarge",4,
                   "NVRM: rpcRecvPoll failed with status 0x%08x for fn %d sequence %d!\n",uVar9,
                   uVar1,iVar2);
    }
    nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0x876);
    return uVar9;
  }
  lVar11 = *(long *)(param_2 + 0x4d8);
  uVar9 = *(uint *)(lVar11 + 8);
  if (param_3 <= *(uint *)(lVar11 + 8)) {
    uVar9 = param_3;
  }
  if (*(uint *)(param_2 + 0x4f0) < uVar9) {
    nvCheckFailedNoLog(4,"entryLength <= pRpc->maxRpcSize","src/kernel/vgpu/rpc.c",0x87d);
    return 0x40;
  }
  if (lVar11 != param_4) {
    if (param_5 == 0) goto LAB_004c0cb1;
    portMemCopy(param_4,uVar9,lVar11,uVar9);
  }
  if ((local_5c != 0) && ((param_5 & 1) != 0)) {
    param_4 = (ulong)uVar9 + param_4;
    uVar10 = (ulong)(param_3 - uVar9);
    local_68 = iVar2 + 1;
    if (param_3 - uVar9 != 0) {
      pcVar8 = *(code **)(param_2 + 0x20);
      if (pcVar8 != _rpcRecvPoll_VGPUGSP) goto LAB_004c0e79;
      do {
        uVar9 = _vgpuGspWaitForResponse(param_1);
        while( true ) {
          if (uVar9 != 0) {
            if (uVar9 == 0x65) {
              nvDbg_Printf("src/kernel/vgpu/rpc.c",0x890,"_issueRpcLarge",4,
                           "NVRM: rpcRecvPoll timedout for fn %d sequence %d continuation record (remainingSize=0x%x)!\n"
                           ,uVar1,local_68,uVar10);
            }
            else {
              nvDbg_Printf("src/kernel/vgpu/rpc.c",0x896,"_issueRpcLarge",4,
                           "NVRM: rpcRecvPoll failed with status 0x%08x for fn %d sequence %d continuation record! (remainingSize=0x%x)\n"
                           ,uVar9,uVar1,local_68,uVar10);
            }
            nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0x89a);
            return uVar9;
          }
          uVar9 = *(uint *)(*(long *)(param_2 + 0x4d8) + 8);
          if (*(uint *)(param_2 + 0x4f0) < uVar9) {
            nvCheckFailedNoLog(4,"entryLength <= pRpc->maxRpcSize","src/kernel/vgpu/rpc.c",0x89f);
            return 0x40;
          }
          if (uVar9 < 0x20) {
            nvCheckFailedNoLog(4,"entryLength >= sizeof(rpc_message_header_v)",
                               "src/kernel/vgpu/rpc.c",0x8a0);
            return 0x40;
          }
          uVar7 = (ulong)(uVar9 - 0x20);
          if ((uint)uVar10 < uVar9 - 0x20) {
            uVar7 = uVar10;
          }
          portMemCopy(param_4,uVar7,*(long *)(param_2 + 0x4d8) + 0x20);
          param_4 = param_4 + uVar7;
          uVar9 = (uint)uVar10 - (int)uVar7;
          uVar10 = (ulong)uVar9;
          if (uVar9 == 0) {
            *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0xc) = uVar1;
            if (local_5c + iVar2 == local_68) goto LAB_004c0ff6;
            goto LAB_004c10c0;
          }
          pcVar8 = *(code **)(param_2 + 0x20);
          local_68 = local_68 + 1;
          if (pcVar8 == _rpcRecvPoll_VGPUGSP) break;
LAB_004c0e79:
          uVar9 = (*pcVar8)(param_1,param_2,0x47,local_68);
        }
      } while( true );
    }
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0xc) = uVar1;
    local_68 = iVar2;
LAB_004c10c0:
    nvAssertFailedNoLog("recordCount == 0","src/kernel/vgpu/rpc.c",0x8ad);
LAB_004c0ff6:
    if (local_3c[0] != local_68) {
      nvAssertFailedNoLog("waitSequence - 1 == lastSequence","src/kernel/vgpu/rpc.c",0x8ae);
    }
  }
  lVar11 = *(long *)(param_2 + 0x4d8);
LAB_004c0cb1:
  uVar9 = 0;
  if (*(int *)(lVar11 + 0x10) != 0) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x8b4,"_issueRpcLarge",3,
                 "NVRM: RPC failed with status 0x%08x for fn %d!\n",*(int *)(lVar11 + 0x10),uVar1);
    uVar9 = *(uint *)(*(long *)(param_2 + 0x4d8) + 0x10);
    if (0xfeffffff < uVar9) {
      uVar9 = 0xffff;
    }
  }
  return uVar9;
}


// ===== 004c10f0 _issueRpcAsync =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong _issueRpcAsync(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  uint uVar2;
  ulong uVar3;
  
  if (*(code **)(param_2 + 0x18) == _rpcSendMessage_VGPUGSP) {
    uVar3 = _rpcSendMessage_VGPUGSP(param_1,param_2,0);
    return uVar3;
  }
  uVar1 = *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0xc);
  uVar2 = (**(code **)(param_2 + 0x18))(param_1,param_2,0);
  uVar3 = (ulong)uVar2;
  if (uVar2 != 0) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x7f7,"_issueRpcAsync",4,
                 "NVRM: rpcSendMessage async failed with status 0x%08x for fn %d!\n",uVar3,uVar1);
    nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0x7f9);
    uVar3 = (ulong)uVar2;
    if (uVar2 == 3) {
      uVar3 = 0xffff;
    }
  }
  return uVar3;
}


// ===== 004c1190 _issueRpcAndWait =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint _issueRpcAndWait(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  ulong uVar9;
  long lVar10;
  undefined8 uVar11;
  char *pcVar12;
  uint uVar13;
  ulong uVar14;
  ulong uVar15;
  undefined8 in_stack_ffffffffffffff58;
  ulong local_60;
  uint local_54;
  undefined1 local_50 [32];
  
  lVar1 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
  cVar2 = rmDeviceGpuLockIsOwner((ulong)*(uint *)(param_1 + 0x7a4));
  if (cVar2 == '\0') {
    nvCheckFailedNoLog(4,"rmDeviceGpuLockIsOwner(pGpu->gpuInstance)","src/kernel/vgpu/rpc.c",0x732);
  }
  lVar6 = 0;
  if (bProfileRPC != '\0') {
    lVar6 = portMemAllocNonPaged(0x28);
    if (lVar6 == 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x73a,"_issueRpcAndWait",4,
                   "NVRM: failed to allocate RPC meter memory!\n");
      nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0x73b);
      return 0x1a;
    }
    portMemSet(lVar6,0,0x28);
    lVar10 = lVar6;
    if (rpcMeterHead != 0) {
      *(long *)(DAT_0056eb18 + 0x20) = lVar6;
      lVar10 = rpcMeterHead;
    }
    rpcMeterHead = lVar10;
    DAT_0056eb18 = lVar6;
    *(ulong *)(lVar6 + 0x10) = (ulong)*(uint *)(*(long *)(param_2 + 0x4d8) + 0xc);
    if (*(int *)(*(long *)(param_2 + 0x4d8) + 0xc) == 0xcc) {
      rpcProfilerEntryCount = rpcProfilerEntryCount + 1;
      *(ulong *)(lVar6 + 0x18) = (ulong)*(uint *)(*(long *)(param_2 + 0x4d8) + 0x28);
      osGetPerformanceCounter(lVar6);
    }
    else {
      rpcProfilerEntryCount = rpcProfilerEntryCount + 1;
      osGetPerformanceCounter(lVar6);
    }
  }
  local_54 = 0;
  uVar5 = *(uint *)(*(long *)(param_2 + 0x4d8) + 0xc);
  if (*(code **)(param_2 + 0x18) == _rpcSendMessage_VGPUGSP) {
    _rpcSendMessage_VGPUGSP();
  }
  else {
    uVar3 = (**(code **)(param_2 + 0x18))(param_1,param_2,&local_54);
    if (uVar3 != 0) {
      if (*(char *)(param_2 + 0x2d2c) == '\0') {
        uVar8 = 4;
      }
      else {
        uVar8 = 1;
      }
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x761,"_issueRpcAndWait",uVar8,
                   "NVRM: rpcSendMessage failed with status 0x%08x for fn %d sequence %d!\n",uVar3,
                   uVar5,local_54);
      if (uVar3 == 3) {
        return 0xffff;
      }
      return uVar3;
    }
  }
  if ((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(lVar1 + 0x150) != '\0')) {
    if ((*(long *)(lVar1 + 0x110) != 0) && (uVar5 == 0xb5)) {
      lVar10 = *(long *)(lVar1 + 0x128);
      uVar5 = *(int *)(lVar10 + 0x14) - *(int *)(*(long *)(lVar1 + 0x120) + 0x70);
      do {
        uVar15 = (ulong)(uVar5 & 0x1fffff);
        if (uVar15 == 0) {
          if (*(int *)(lVar10 + 0x1c) == 0) goto LAB_004c1aa4;
          timeoutSet(param_1 + 0x1af0,local_50,8000000,4);
          lVar10 = *(long *)(lVar1 + 0x128);
          do {
            if (*(int *)(lVar10 + 0x1c) == 0) {
              lVar7 = *(long *)(lVar1 + 0x120);
              goto LAB_004c1873;
            }
            iVar4 = timeoutCheck(param_1 + 0x1af0,local_50,0x77a);
            if (iVar4 == 0x65) {
              pcVar12 = "NVRM: Timeout while waiting for available date in the hibernation buffer\n"
              ;
              uVar8 = 0x77c;
              goto LAB_004c19f3;
            }
            lVar7 = *(long *)(lVar1 + 0x120);
            lVar10 = *(long *)(lVar1 + 0x128);
            uVar5 = *(int *)(lVar10 + 0x14) - *(int *)(lVar7 + 0x70) & 0x1fffff;
          } while (uVar5 == 0);
          uVar15 = (ulong)uVar5;
        }
        else {
          timeoutSet(param_1 + 0x1af0,local_50,8000000,4);
          lVar7 = *(long *)(lVar1 + 0x120);
        }
        lVar10 = *(long *)(lVar1 + 0x100);
        uVar5 = *(uint *)(lVar7 + 0x70);
        uVar14 = (ulong)*(uint *)(lVar1 + 0x26184);
        if ((ulong)*(uint *)(lVar1 + 0x26180) < uVar14 + uVar15) {
          uVar3 = *(uint *)(lVar1 + 0x26180) + 0x800000;
          if (0x3000000 < uVar3) {
            nvDbg_Printf("src/kernel/vgpu/rpc.c",0x277f,"_transferDataFromGspHibernationBuf",4,
                         "NVRM: Hibernation data size is more than MAX limit\n");
LAB_004c1a6f:
            nvDbg_Printf("src/kernel/vgpu/rpc.c",0x788,"_issueRpcAndWait",4,
                         "NVRM: _transferDataFromGspHibernationBuf failed with status 0x%08x\n",0x1a
                        );
            return 0x1a;
          }
          lVar7 = portMemAllocNonPaged(uVar3);
          if (lVar7 == 0) {
            nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2787,"_transferDataFromGspHibernationBuf",4,
                         "NVRM: No memory for hibernation buffer reallocation\n");
            goto LAB_004c1a6f;
          }
          portMemCopy(lVar7,*(undefined4 *)(lVar1 + 0x26184),*(undefined8 *)(lVar1 + 0x26188),
                      *(undefined4 *)(lVar1 + 0x26184));
          portMemFree(*(undefined8 *)(lVar1 + 0x26188));
          uVar14 = (ulong)*(uint *)(lVar1 + 0x26184);
          *(int *)(lVar1 + 0x26180) = *(int *)(lVar1 + 0x26180) + 0x800000;
          *(long *)(lVar1 + 0x26188) = lVar7;
        }
        else {
          lVar7 = *(long *)(lVar1 + 0x26188);
        }
        while( true ) {
          uVar9 = (ulong)(0x200000 - uVar5);
          if (uVar15 < 0x200000 - uVar5) {
            uVar9 = uVar15;
          }
          portMemCopy(lVar7 + uVar14,uVar9,(ulong)uVar5 + lVar10,uVar9);
          *(int *)(lVar1 + 0x26184) = *(int *)(lVar1 + 0x26184) + (int)uVar9;
          uVar5 = uVar5 + (int)uVar9 & 0x1fffff;
          LOCK();
          UNLOCK();
          *(uint *)(*(long *)(lVar1 + 0x120) + 0x70) = uVar5;
          uVar15 = uVar15 - uVar9;
          if (uVar15 == 0) break;
          lVar7 = *(long *)(lVar1 + 0x26188);
          uVar14 = (ulong)*(uint *)(lVar1 + 0x26184);
        }
        lVar7 = *(long *)(lVar1 + 0x120);
        lVar10 = *(long *)(lVar1 + 0x128);
LAB_004c1873:
        uVar5 = *(int *)(lVar10 + 0x14) - *(int *)(lVar7 + 0x70);
      } while( true );
    }
    if ((*(long *)(lVar1 + 0x110) != 0) && (uVar5 == 0xb6)) {
      if (*(long *)(lVar1 + 0x26188) == 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x79b,"_issueRpcAndWait",4,
                     "NVRM: Hibernation Data Buffer is NULL\n");
        return 0x1a;
      }
      uVar5 = *(uint *)(lVar1 + 0x26184);
      local_60 = (ulong)uVar5;
      *(undefined4 *)(lVar1 + 0x26184) = 0;
      if (local_60 != 0) {
        do {
          timeoutSet(param_1 + 0x1af0,local_50,8000000,4);
          while( true ) {
            uVar3 = (*(int *)(*(long *)(lVar1 + 0x128) + 0x18) + 0x1fffff) -
                    *(int *)(*(long *)(lVar1 + 0x120) + 0x74) & 0x1fffff;
            if (uVar3 != 0) break;
            iVar4 = timeoutCheck(param_1 + 0x1af0,local_50,0x7a8);
            if (iVar4 == 0x65) {
              pcVar12 = "NVRM: Timeout while waiting for free space in the hibernation buffer\n";
              uVar8 = 0x7aa;
LAB_004c19f3:
              nvDbg_Printf("src/kernel/vgpu/rpc.c",uVar8,"_issueRpcAndWait",4,pcVar12);
              return 0x65;
            }
          }
          uVar13 = *(uint *)(*(long *)(lVar1 + 0x120) + 0x74);
          uVar15 = (ulong)uVar3;
          if (local_60 <= uVar3) {
            uVar15 = local_60;
          }
          lVar10 = *(long *)(lVar1 + 0x100);
          uVar14 = uVar15;
          do {
            uVar9 = (ulong)(0x200000 - uVar13);
            if (uVar14 < 0x200000 - uVar13) {
              uVar9 = uVar14;
            }
            portMemCopy((ulong)uVar13 + lVar10,uVar9,
                        (ulong)*(uint *)(lVar1 + 0x26184) + *(long *)(lVar1 + 0x26188));
            *(int *)(lVar1 + 0x26184) = *(int *)(lVar1 + 0x26184) + (int)uVar9;
            uVar13 = uVar13 + (int)uVar9 & 0x1fffff;
            LOCK();
            UNLOCK();
            *(uint *)(*(long *)(lVar1 + 0x120) + 0x74) = uVar13;
            uVar14 = uVar14 - uVar9;
          } while (uVar14 != 0);
          local_60 = local_60 - uVar15;
        } while (local_60 != 0);
        if (uVar5 != *(uint *)(lVar1 + 0x26184)) {
          nvDbg_Printf("src/kernel/vgpu/rpc.c",0x7bc,"_issueRpcAndWait",4,
                       "NVRM: Complete data not restored to GSP plugin\n",uVar13,
                       in_stack_ffffffffffffff58);
          return 0x25;
        }
      }
      uVar5 = 0xb6;
      *(undefined4 *)(*(long *)(lVar1 + 0x120) + 0x78) = 0;
    }
  }
LAB_004c1260:
  if (*(code **)(param_2 + 0x20) == _rpcRecvPoll_VGPUGSP) {
    uVar3 = _vgpuGspWaitForResponse(param_1);
  }
  else {
    uVar3 = (**(code **)(param_2 + 0x20))(param_1,param_2,uVar5,local_54);
  }
  if (uVar3 == 0) {
    if (bProfileRPC != '\0') {
      osGetPerformanceCounter(lVar6 + 8);
    }
    uVar3 = *(uint *)(*(long *)(param_2 + 0x4d8) + 0x10);
    if ((uVar3 != 0) && (uVar3 != 0xff100009)) {
      if (*(char *)(param_2 + 0x2d2c) == '\0') {
        uVar8 = 3;
      }
      else {
        uVar8 = 1;
      }
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x7dd,"_issueRpcAndWait",uVar8,
                   "NVRM: RPC failed with status 0x%08x for fn %d!\n",uVar3,uVar5);
      uVar3 = *(uint *)(*(long *)(param_2 + 0x4d8) + 0x10);
      if (0xfeffffff < uVar3) {
        uVar3 = 0xffff;
      }
    }
  }
  else {
    if (uVar3 == 0x65) {
      uVar13 = uVar5;
      uVar5 = local_54;
      if (*(char *)(param_2 + 0x2d2c) == '\0') {
        pcVar12 = "NVRM: rpcRecvPoll timedout for fn %d sequence %u!\n";
        uVar8 = 4;
        uVar11 = 0x7c7;
      }
      else {
        pcVar12 = "NVRM: rpcRecvPoll timedout for fn %d sequence %u!\n";
        uVar8 = 1;
        uVar11 = 0x7c7;
      }
    }
    else {
      if (*(char *)(param_2 + 0x2d2c) == '\0') {
        uVar8 = 4;
      }
      else {
        uVar8 = 1;
      }
      pcVar12 = "NVRM: rpcRecvPoll failed with status 0x%08x for fn %d sequence %u!\n";
      uVar11 = 0x7cd;
      uVar13 = uVar3;
    }
    nvDbg_Printf("src/kernel/vgpu/rpc.c",uVar11,"_issueRpcAndWait",uVar8,pcVar12,uVar13,uVar5);
  }
  return uVar3;
LAB_004c1aa4:
  uVar5 = 0xb5;
  goto LAB_004c1260;
}


// ===== 004c1b50 rpcRmApiControl_wrapper =====

int rpcRmApiControl_wrapper
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined8 param_6,uint param_7)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (*(int *)(param_2 + 0x4f4) - 0x40U < param_7) {
    return 0x56;
  }
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xcc,0x28);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    *(uint *)(lVar1 + 0x38) = param_7;
    *(undefined4 *)(lVar1 + 0x28) = param_5;
    portMemCopy(lVar1 + 0x40,param_7,param_6);
    uVar3 = _issueRpcAndWait(param_1,param_2);
    iVar2 = (int)uVar3;
    if (iVar2 == 0) {
      portMemCopy(param_6,param_7,lVar1 + 0x40);
      iVar2 = *(int *)(lVar1 + 0x3c);
    }
    else {
      if (iVar2 == -0xeffff7) {
        return 0x56;
      }
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x15b7,"rpcRmApiControl_wrapper",4,
                   "NVRM: API control 0x%x failed with status 0x%x\n",*(undefined4 *)(lVar1 + 0x28),
                   uVar3);
    }
  }
  return iVar2;
}


// ===== 004c1cc0 deserialize_NV2080_CTRL_PERF_GET_LEVEL_INFO_V2_PARAMS_v2B_0D =====

undefined4 deserialize_NV2080_CTRL_PERF_GET_LEVEL_INFO_V2_PARAMS_v2B_0D(long param_1,long param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  if (((param_2 != 0) && (param_1 != 0)) && (*(uint *)(param_2 + 8) < 0x21)) {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
    if (*(int *)(param_2 + 8) != 0) {
      uVar2 = 0;
      puVar1 = (undefined4 *)(param_2 + 0x14);
      puVar3 = (undefined4 *)(param_1 + 0x10);
      do {
        uVar2 = uVar2 + 1;
        *puVar3 = *puVar1;
        puVar3[1] = puVar1[1];
        puVar3[2] = puVar1[2];
        puVar3[3] = puVar1[3];
        puVar1 = puVar1 + 6;
        puVar3 = puVar3 + 6;
      } while (uVar2 < *(uint *)(param_2 + 8));
    }
    return 0;
  }
  return 0x1f;
}


// ===== 004c1d40 serialize_NVA06C_CTRL_INTERNAL_PROMOTE_FAULT_METHOD_BUFFERS_PARAMS_v1E_07 =====

undefined4
serialize_NVA06C_CTRL_INTERNAL_PROMOTE_FAULT_METHOD_BUFFERS_PARAMS_v1E_07
          (undefined8 *param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  long lVar3;
  undefined8 *puVar4;
  
  if (((param_1 != (undefined8 *)0x0) && (param_2 != (undefined8 *)0x0)) &&
     (uVar1 = *(uint *)(param_1 + 10), uVar1 < 3)) {
    *(uint *)(param_2 + 10) = uVar1;
    if (uVar1 != 0) {
      lVar3 = 0;
      puVar2 = param_2;
      puVar4 = param_1;
      do {
        param_2[lVar3 + 8] = param_1[lVar3 + 8];
        lVar3 = lVar3 + 1;
        *puVar2 = *puVar4;
        puVar2[1] = puVar4[1];
        puVar2[2] = puVar4[2];
        *(undefined4 *)(puVar2 + 3) = *(undefined4 *)(puVar4 + 3);
        *(undefined4 *)((long)puVar2 + 0x1c) = *(undefined4 *)((long)puVar4 + 0x1c);
        puVar2 = puVar2 + 4;
        puVar4 = puVar4 + 4;
      } while ((uint)lVar3 < *(uint *)(param_1 + 10));
    }
    return 0;
  }
  return 0x1f;
}


// ===== 004c1dc0 serialize_NVC637_CTRL_CMD_EXEC_PARTITIONS_CREATE_v24_05 =====

ulong serialize_NVC637_CTRL_CMD_EXEC_PARTITIONS_CREATE_v24_05
                (undefined1 *param_1,undefined4 *param_2)

{
  uint uVar1;
  ulong uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (((param_1 != (undefined1 *)0x0) && (param_2 != (undefined4 *)0x0)) &&
     (*(uint *)(param_1 + 8) < 9)) {
    *(undefined1 *)param_2 = *param_1;
    uVar1 = *(uint *)(param_1 + 8);
    uVar2 = (ulong)uVar1;
    param_2[1] = uVar1;
    if (uVar1 != 0) {
      puVar3 = (undefined4 *)(param_1 + 0xc);
      puVar4 = param_2;
      do {
        puVar5 = puVar4 + 0xc;
        puVar4[2] = *puVar3;
        puVar4[3] = puVar3[1];
        puVar4[4] = puVar3[2];
        puVar4[5] = puVar3[3];
        puVar4[6] = puVar3[4];
        puVar4[7] = puVar3[5];
        puVar4[8] = puVar3[6];
        puVar4[9] = puVar3[7];
        puVar4[10] = puVar3[8];
        puVar4[0xb] = puVar3[10];
        *puVar5 = puVar3[0xb];
        puVar4[0xd] = puVar3[0xc];
        puVar3 = puVar3 + 0xd;
        puVar4 = puVar5;
      } while (puVar5 != param_2 + uVar2 * 0xc);
      uVar2 = 0;
    }
    return uVar2;
  }
  return 0x1f;
}


// ===== 004c1e80 serialize_NVB0CC_CTRL_GET_HS_CREDITS_PARAMS_v21_08 =====

undefined8
serialize_NVB0CC_CTRL_GET_HS_CREDITS_PARAMS_v21_08(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  if (((param_1 != (undefined1 *)0x0) && (param_2 != (undefined1 *)0x0)) &&
     ((byte)param_1[1] < 0x40)) {
    *param_2 = *param_1;
    param_2[1] = param_1[1];
    puVar1 = param_1 + 4;
    do {
      puVar2 = puVar1 + 4;
      param_2[4] = *puVar1;
      param_2[5] = puVar1[1];
      *(undefined2 *)(param_2 + 6) = *(undefined2 *)(puVar1 + 2);
      puVar1 = puVar2;
      param_2 = param_2 + 4;
    } while (puVar2 != param_1 + 0x100);
    return 0;
  }
  return 0x1f;
}


// ===== 004c1f00 serialize_NVB0CC_CTRL_SET_HS_CREDITS_PARAMS_v21_08 =====

undefined8
serialize_NVB0CC_CTRL_SET_HS_CREDITS_PARAMS_v21_08(undefined1 *param_1,undefined1 *param_2)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  if ((param_1 != (undefined1 *)0x0) && (param_2 != (undefined1 *)0x0)) {
    *param_2 = *param_1;
    bVar1 = param_1[1];
    param_2[1] = bVar1;
    if (bVar1 < 0x40) {
      puVar2 = param_1 + 4;
      do {
        puVar3 = puVar2 + 4;
        param_2[4] = *puVar2;
        param_2[5] = puVar2[1];
        *(undefined2 *)(param_2 + 6) = *(undefined2 *)(puVar2 + 2);
        puVar2 = puVar3;
        param_2 = param_2 + 4;
      } while (puVar3 != param_1 + 0x100);
      return 0;
    }
  }
  return 0x1f;
}


// ===== 004c1f70 _allocRpcMemDesc =====

int _allocRpcMemDesc(undefined8 param_1,undefined8 param_2,undefined1 param_3,int param_4,
                    undefined4 param_5,long *param_6,long *param_7,undefined8 *param_8)

{
  undefined1 uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 extraout_RDX;
  
  *param_6 = 0;
  *param_7 = 0;
  *param_8 = 0;
  if (param_4 == 1) {
    uVar4 = 0;
    iVar2 = memdescCreate(param_6,param_1,param_2,0,param_3,1);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,
                 "memdescCreate(ppMemDesc, pGpu, size, 0, bContig, ADDR_SYSMEM, NV_MEMORY_CACHED, memdescFlag)"
                 ,"src/kernel/vgpu/rpc.c",0x102,uVar4,param_5);
      goto LAB_004c206f;
    }
    memdescSetFlag(*param_6,0x200,1);
    *(undefined4 *)(*param_6 + 0x9c) = 0x89;
    iVar2 = memdescAlloc(*param_6);
    uVar4 = 0x110;
    if (iVar2 == 0) {
      uVar1 = memdescGetFlag(*param_6,0x200,extraout_RDX,0x110);
      iVar2 = memdescMapOld(*param_6,0,param_2,uVar1,3,param_7,param_8);
      if (iVar2 == 0) {
        return 0;
      }
      nvAssertOkFailedNoLog
                (iVar2,
                 "memdescMapOld(*ppMemDesc, 0, size, memdescGetFlag(*ppMemDesc, MEMDESC_FLAGS_KERNEL_MODE), NV_PROTECT_READ_WRITE, ppMemBuffer, ppMemPriv)"
                 ,"src/kernel/vgpu/rpc.c",0x115);
      memdescFree(*param_6);
    }
    else {
LAB_004c2175:
      nvAssertOkFailedNoLog(iVar2,"status","src/kernel/vgpu/rpc.c",uVar4);
    }
  }
  else {
    if (param_4 != 2) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1a2,"_allocRpcMemDesc",4,
                   "NVRM: RPC: unknown memory address space %d\n",param_4);
      iVar2 = 0x56;
      goto LAB_004c206f;
    }
    iVar2 = memdescCreate(param_6,param_1,param_2,0x1000,param_3,2);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,
                 "memdescCreate(ppMemDesc, pGpu, size, RM_PAGE_SIZE, bContig, ADDR_FBMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_NONE)"
                 ,"src/kernel/vgpu/rpc.c",0x142);
      goto LAB_004c206f;
    }
    *(undefined4 *)(*param_6 + 0x9c) = 0x8a;
    iVar2 = memdescAlloc(*param_6);
    if (iVar2 != 0) {
      uVar4 = 0x14e;
      goto LAB_004c2175;
    }
    lVar3 = memdescMapInternal(param_1,*param_6,0);
    *param_7 = lVar3;
    if (lVar3 != 0) {
      return 0;
    }
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x156,"_allocRpcMemDescFbBar2Virtual",4,
                 "NVRM: RPC: BAR2 map failed\n");
    memdescFree(*param_6);
    iVar2 = 0x1a;
  }
  memdescDestroy(*param_6);
LAB_004c206f:
  *param_8 = 0;
  *param_7 = 0;
  *param_6 = 0;
  return iVar2;
}


// ===== 004c2250 _freeRpcMemDesc =====

void _freeRpcMemDesc(undefined8 param_1,long *param_2,undefined8 *param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  int iVar4;
  
  if (*param_2 != 0) {
    iVar4 = memdescGetAddressSpace();
    if (iVar4 == 1) {
      uVar1 = *param_3;
      uVar2 = *param_4;
      uVar3 = memdescGetFlag(*param_2,0x200);
      memdescUnmapOld(*param_2,uVar3,uVar1,uVar2);
      memdescFree(*param_2);
      memdescDestroy(*param_2);
    }
    else if (iVar4 == 2) {
      memdescUnmapInternal(param_1,*param_2,0);
      *param_3 = 0;
      memdescFree(*param_2);
      memdescDestroy(*param_2);
    }
    else {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1c8,"_freeRpcMemDesc",4,
                   "NVRM: RPC: unknown memory address space %d\n",iVar4);
    }
    *param_4 = 0;
    *param_3 = 0;
    *param_2 = 0;
    return;
  }
  return;
}


// ===== 004c2360 teardownSysmemPfnBitMap.part.0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void teardownSysmemPfnBitMap_part_0(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  iVar1 = listCount_IMPL(&DAT_0054eac0);
  if (iVar1 != 0) {
    lVar3 = listHead_IMPL(&DAT_0054eac0);
    memdescRemoveRef(*(undefined8 *)(lVar3 + 0x10));
    if (*(int *)(*(long *)(lVar3 + 0x10) + 0x90) == 1) {
      DAT_0054ea98 = 0;
      if ((DAT_0054eab8 != (long *)0x0) && (*DAT_0054eab8 != 0)) {
        _freeRpcMemDesc(param_1,&DAT_0054eab8,&DAT_0054eaa0,&DAT_0054eaa8);
      }
      lVar3 = listHead_IMPL(&DAT_0054eac0);
      while (lVar3 != 0) {
        lVar2 = listNext_IMPL(&DAT_0054eac0,lVar3);
        listRemoveIntrusive_IMPL(&DAT_0054eac0,lVar3);
        vgpuFreeSysmemPfnBitMapNode(lVar3);
        lVar3 = lVar2;
      }
      portMemFree(DAT_0054ea90);
      vgpuSysmemPfnInfo = 0;
      _DAT_0054ea88 = 0;
      return;
    }
  }
  if ((DAT_0054eab8 != (long *)0x0) && (param_1 == *DAT_0054eab8)) {
    *DAT_0054eab8 = 0;
    lVar3 = listHead_IMPL(&DAT_0054eac0);
    while (lVar2 = lVar3, lVar3 != 0) {
      while( true ) {
        lVar3 = listNext_IMPL(&DAT_0054eac0,lVar2);
        if (*(long *)(lVar2 + 0x10) == 0) break;
        *(undefined1 *)(*(long *)(lVar2 + 0x10) + 100) = 0;
        lVar2 = lVar3;
        if (lVar3 == 0) {
          return;
        }
      }
    }
  }
  return;
}


// ===== 004c24d0 teardownSysmemPfnBitMap =====

void teardownSysmemPfnBitMap(long param_1)

{
  if (*(char *)(param_1 + 0x472) == '\0') {
    return;
  }
  teardownSysmemPfnBitMap_part_0();
  return;
}


// ===== 004c24f0 rpcSetIpVersion =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void rpcSetIpVersion(long param_1,long param_2,undefined4 param_3)

{
  undefined8 *puVar1;
  long *plVar2;
  long local_78;
  long local_70;
  undefined8 local_68;
  undefined8 local_60;
  code *local_58;
  long local_50;
  long local_48;
  undefined8 local_40;
  undefined8 local_38;
  code *local_30;
  
  puVar1 = (undefined8 *)objhalGetModuleDescriptor_IMPL(*(undefined8 *)(param_1 + 0x1b50));
  *(undefined4 *)(param_2 + 0x4d0) = param_3;
  local_78 = 0;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = (code *)0x0;
  (**(code **)*puVar1)(param_2 + 0x28);
  local_78 = param_1;
  local_70 = param_2;
  (**(code **)(param_2 + 0x4c8))(&local_78);
  (*local_58)(&local_78);
  plVar2 = (long *)objhalGetModuleDescriptor_IMPL(*(undefined8 *)(param_1 + 0x1b50));
  *(undefined4 *)(param_2 + 0x2ef8) = param_3;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = (code *)0x0;
  (**(code **)(*plVar2 + 8))(param_2 + 0x2d38);
  local_50 = param_1;
  local_48 = param_2 + 0x2d30;
  (**(code **)(param_2 + 0x2ef0))(&local_50);
  (*local_30)(&local_50);
  return;
}


// ===== 004c2600 rpcConstruct_IMPL =====

undefined8 rpcConstruct_IMPL(undefined8 param_1,long param_2)

{
  *(undefined4 *)(param_2 + 0x4f0) = 0x1000;
  return 0;
}


// ===== 004c2620 rpcDestroy_IMPL =====

void rpcDestroy_IMPL(void)

{
  return;
}


// ===== 004c2630 vgpuGspTeardownBuffers =====

void vgpuGspTeardownBuffers(long param_1)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
  if (*(char *)(lVar1 + 0x150) == '\0') {
    return;
  }
  *(undefined1 *)(lVar1 + 0x26153) = 0;
  if (*(long *)(lVar1 + 0x120) != 0) {
    *(undefined8 *)(*(long *)(lVar1 + 0x120) + 0x18) = 0;
    iVar2 = _vgpuGspSendSetupRequest(param_1,0);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x517,"_vgpuGspTeardownCommunicationWithPlugin",4,
                   "NVRM: Communication teardown with GSP Plugin failed 0x%x\n",iVar2);
    }
  }
  if ((DAT_0054ea98 != '\0') && (*(char *)(param_1 + 0x472) != '\0')) {
    iVar2 = updateSharedBufferInfoInSysmemPfnBitMap_part_0(param_1,lVar1,0,0);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x5c3,"vgpuGspTeardownBuffers",4,
                   "NVRM: RPC: Sysmem PFN bitmap update failed for shared buffer sysmem pages failed: 0x%x\n"
                   ,iVar2);
    }
  }
  if (*(long *)(lVar1 + 0x110) != 0) {
    *(undefined8 *)(lVar1 + 0x110) = 0;
    _freeRpcMemDesc(param_1,lVar1 + 0xf8,lVar1 + 0x100,lVar1 + 0x108);
  }
  gpuGetStaticInfo(param_1);
  *(undefined1 *)(lVar1 + 0x26148) = 0;
  _freeRpcMemDesc(param_1,lVar1 + 0x78,lVar1 + 0x118,lVar1 + 0x88);
  _teardownGspEventInfrastructure(param_1,lVar1);
  *(undefined8 *)(lVar1 + 0xf0) = 0;
  _freeRpcMemDesc(param_1,lVar1 + 0xd8,lVar1 + 0xe0,lVar1 + 0xe8);
  *(undefined8 *)(lVar1 + 0x128) = 0;
  *(undefined8 *)(lVar1 + 0xd0) = 0;
  _freeRpcMemDesc(param_1,lVar1 + 0xb8,lVar1 + 0xc0,lVar1 + 200);
  *(undefined8 *)(lVar1 + 0x120) = 0;
  *(undefined8 *)(lVar1 + 0xb0) = 0;
  _freeRpcMemDesc(param_1,lVar1 + 0x98,lVar1 + 0xa0,lVar1 + 0xa8);
  return;
}


// ===== 004c2830 setGuestEccStatus =====

void setGuestEccStatus(long param_1)

{
  long lVar1;
  int iVar2;
  undefined1 uVar3;
  int local_1c [3];
  
  local_1c[0] = 0;
  lVar1 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
  if (*(char *)(lVar1 + 0x150) == '\0') {
    uVar3 = *(undefined1 *)(lVar1 + 0x26150);
  }
  else {
    uVar3 = *(int *)(*(long *)(lVar1 + 0x128) + 8) != 0;
    *(undefined1 *)(lVar1 + 0x26150) = uVar3;
  }
  *(undefined1 *)(lVar1 + 0x26151) = uVar3;
  iVar2 = osReadRegistryDword(param_1,"RMGuestECCState",local_1c);
  if (iVar2 == 0) {
    if (local_1c[0] == 0) {
      if (*(char *)(lVar1 + 0x26150) != '\0') {
        *(undefined1 *)(lVar1 + 0x26151) = 0;
        nv_printf(0xffffffff,"Guest explicitly disabled ECC support.\n");
      }
    }
    else if (*(char *)(lVar1 + 0x26150) == '\0') {
      nv_printf(0xffffffff,"Error: Guest trying to enable ECC on unsupported configuration.\n");
    }
  }
  if (*(char *)(lVar1 + 0x150) != '\0') {
    *(uint *)(*(long *)(lVar1 + 0x120) + 0x4c) = (uint)(*(char *)(lVar1 + 0x26151) != '\0');
  }
  return;
}


// ===== 004c2910 vgpuGspSetupBuffers =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int vgpuGspSetupBuffers(long param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined4 uVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  char cVar11;
  undefined8 *puVar12;
  
  lVar7 = gpuGetStaticInfo();
  puVar3 = *(undefined8 **)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
  if (puVar3 == (undefined8 *)0x0) {
    nvCheckFailedNoLog(4,"(pVGpu != NULL)","src/kernel/vgpu/rpc.c",0x5de);
    return 0x3d;
  }
  if (*(char *)(param_1 + 0x4a4e) == '\0') {
    return 0x56;
  }
  uVar5 = (**(code **)(*(long *)(param_1 + 0x4d8) + 0x68))();
  osDmaSetAddressSize(*(undefined8 *)(param_1 + 0x4e0),uVar5);
  if (puVar3[0x4c2b] == 0) {
    nvCheckFailedNoLog(4,"(pVGpu->pRpc != NULL)","src/kernel/vgpu/rpc.c",0x5e8);
    return 0x3d;
  }
  *(code **)(puVar3[0x4c2b] + 0x18) = _rpcSendMessage_VGPUGSP;
  puVar1 = puVar3 + 0x13;
  *(code **)(puVar3[0x4c2b] + 0x20) = _rpcRecvPoll_VGPUGSP;
  iVar6 = _allocRpcMemDesc(param_1,0x1000,1,1,0,puVar1,puVar3 + 0x14,puVar3 + 0x15);
  if (iVar6 != 0) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x42f,"_setupGspControlBuffer",4,
                 "NVRM: RPC: GSP Shared memory setup failed: 0x%x\n",iVar6);
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x5f0,"vgpuGspSetupBuffers",4,
                 "NVRM: RPC: GSP Shared memory setup failed: 0x%x\n",iVar6);
    goto LAB_004c3142;
  }
  uVar8 = memdescGetPte(puVar3[0x13],1,0);
  puVar3[0x16] = uVar8 >> 0xc;
  puVar3[0x24] = puVar3[0x14];
  portMemSet(puVar3[0x14],0,*(undefined8 *)(puVar3[0x13] + 0x30));
  puVar2 = puVar3 + 0x17;
  iVar6 = _allocRpcMemDesc(param_1,0x1000,1,1,0,puVar2,puVar3 + 0x18,puVar3 + 0x19);
  if (iVar6 != 0) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x457,"_setupGspResponseBuffer",4,
                 "NVRM: RPC: GSP Response memory setup failed: 0x%x\n",iVar6);
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x5f7,"vgpuGspSetupBuffers",4,
                 "NVRM: RPC: GSP Response memory setup failed: 0x%x\n",iVar6);
    goto LAB_004c3142;
  }
  uVar8 = memdescGetPte(puVar3[0x17],1,0);
  puVar3[0x1a] = uVar8 >> 0xc;
  puVar3[0x25] = puVar3[0x18];
  portMemSet(puVar3[0x18],0,*(undefined8 *)(puVar3[0x17] + 0x30));
  cVar11 = '\x01';
  if (*(char *)(*(long *)(&DAT_00001b90 + param_1) + 0xad05) != '\0') {
    cVar11 = (*(char *)((long)puVar3 + 0x26154) == '\0') + '\x01';
  }
  iVar6 = _allocRpcMemDesc(param_1,0x20000,1,cVar11,0,puVar3 + 0x1b,puVar3 + 0x1c);
  if (iVar6 != 0) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x48d,"_setupGspMessageBuffer",4,
                 "NVRM: RPC: GSP Message memory setup failed: 0x%x\n",iVar6);
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x5fe,"vgpuGspSetupBuffers",4,
                 "NVRM: RPC: GSP Message buffer setup failed: 0x%x\n",iVar6);
    goto LAB_004c3142;
  }
  uVar8 = memdescGetPte(puVar3[0x1b],1,0);
  puVar3[0x1e] = uVar8 >> 0xc;
  portMemSet(puVar3[0x1c],0,*(undefined8 *)(puVar3[0x1b] + 0x30));
  if ((puVar3[0x4c2b] != 0) && (*(char *)(puVar3 + 0x2a) != '\0')) {
    *(undefined8 *)(puVar3[0x4c2b] + 0x4d8) = puVar3[0x1c];
    *(undefined4 *)(puVar3[0x4c2b] + 0x4f4) = 0x20000;
  }
  iVar6 = _setupGspEventInfrastructure(param_1,puVar3);
  if (iVar6 != 0) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x60a,"vgpuGspSetupBuffers",4,
                 "NVRM: RPC: Event setup failed: 0x%x\n",iVar6);
    goto LAB_004c3142;
  }
  cVar11 = '\x01';
  if (*(char *)(*(long *)(&DAT_00001b90 + param_1) + 0xad05) != '\0') {
    cVar11 = (*(char *)((long)puVar3 + 0x26154) == '\0') + '\x01';
  }
  puVar12 = puVar3 + 0x23;
  iVar6 = _allocRpcMemDesc(param_1,0x1000,1,cVar11,0,puVar3 + 0xf,puVar12,puVar3 + 0x11);
  if (iVar6 != 0) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1e7,"_allocSharedMemory",4,
                 "NVRM: RPC: Shared memory setup failed: 0x%x\n",iVar6);
    nvAssertOkFailedNoLog
              (iVar6,"_allocSharedMemory(pGpu, pVGpu, addressSpace, memFlags)",
               "src/kernel/vgpu/rpc.c",0x201);
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x611,"vgpuGspSetupBuffers",4,
                 "NVRM: RPC: Shared memory setup failed: 0x%x\n",iVar6);
    goto LAB_004c3142;
  }
  uVar8 = memdescGetPte(puVar3[0xf],1,0,puVar12);
  *(undefined1 *)(puVar3 + 0x4c29) = 0;
  puVar3[0x12] = uVar8 >> 0xc;
  portMemSet(puVar3[0x23],0,0x1000);
  if ((*(byte *)(lVar7 + 0xa726) & 0x40) != 0) {
    iVar6 = _allocRpcMemDesc(param_1,0x200000,1,1,0,puVar3 + 0x1f,puVar3 + 0x20,puVar3 + 0x21);
    if (iVar6 != 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x25b,"_setupGspHibernateShrdBuff",4,
                   "NVRM: RPC: GSP hibernate buffer setup failed: 0x%x\n",iVar6);
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x624,"vgpuGspSetupBuffers",4,
                   "NVRM: RPC: Hibernate memory setup failed: 0x%x\n",iVar6);
      goto LAB_004c3142;
    }
    if (puVar3[0x1f] == 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x25b,"_setupGspHibernateShrdBuff",4,
                   "NVRM: RPC: GSP hibernate buffer setup failed: 0x%x\n",0);
    }
    else {
      uVar8 = memdescGetPte(puVar3[0x1f],1,0);
      puVar3[0x22] = uVar8 >> 0xc;
      portMemSet(puVar3[0x20],0,*(undefined8 *)(puVar3[0x1f] + 0x30));
    }
  }
  uVar9 = osGetPageSize();
  iVar6 = nvLogBase2(uVar9);
  if (*(char *)(param_1 + 0x4a4e) != '\0') {
    *(uint *)(puVar3[0x24] + 0x58) = (iVar6 - 0xcU & 0xff) << 8 | 10;
  }
  if ((undefined4 *)puVar3[0x24] == (undefined4 *)0x0) {
    iVar6 = 0x40;
  }
  else {
    lVar7 = *(long *)(&DAT_00001b90 + param_1);
    *(undefined4 *)(puVar3 + 0x2b) = *(undefined4 *)puVar3[0x25];
    *(undefined4 *)puVar3[0x24] = 2;
    lVar4 = puVar3[0x24];
    uVar9 = vgpuGspMakeBufferAddress(puVar2,puVar3[0x1a]);
    *(undefined8 *)(lVar4 + 8) = uVar9;
    lVar4 = puVar3[0x24];
    uVar9 = vgpuGspMakeBufferAddress(puVar3 + 0x1b,puVar3[0x1e]);
    *(undefined8 *)(lVar4 + 0x18) = uVar9;
    lVar4 = puVar3[0x24];
    uVar9 = vgpuGspMakeBufferAddress(puVar3 + 0xf,puVar3[0x12]);
    *(undefined8 *)(lVar4 + 0x28) = uVar9;
    lVar4 = puVar3[0x24];
    uVar9 = vgpuGspMakeBufferAddress(puVar3,puVar3[3]);
    *(undefined8 *)(lVar4 + 0x38) = uVar9;
    iVar6 = memdescGetAddressSpace(puVar3[0x1b]);
    if (iVar6 == 2) {
      lVar4 = puVar3[0x24];
      if (*(char *)(param_1 + 0x454) == '\0') {
        *(ulong *)(lVar4 + 0x20) =
             (puVar3[0x1c] - *(long *)(lVar7 + 0x7c98)) - (ulong)*(uint *)(puVar3[0x1b] + 0x60);
      }
      else {
        uVar9 = memdescGetPte(puVar3[0x1b],1,0);
        *(undefined8 *)(lVar4 + 0x20) = uVar9;
      }
    }
    iVar6 = memdescGetAddressSpace(puVar3[0xf]);
    if (iVar6 == 2) {
      lVar4 = puVar3[0x24];
      if (*(char *)(param_1 + 0x454) == '\0') {
        *(ulong *)(lVar4 + 0x30) =
             (puVar3[0x23] - *(long *)(lVar7 + 0x7c98)) - (ulong)*(uint *)(puVar3[0x1b] + 0x60);
      }
      else {
        uVar9 = memdescGetPte(puVar3[0xf],1,0);
        *(undefined8 *)(lVar4 + 0x30) = uVar9;
      }
    }
    iVar6 = memdescGetAddressSpace(*puVar3);
    if (iVar6 == 2) {
      lVar4 = puVar3[0x24];
      if (*(char *)(param_1 + 0x454) == '\0') {
        *(ulong *)(lVar4 + 0x40) =
             (puVar3[1] - *(long *)(lVar7 + 0x7c98)) - (ulong)*(uint *)(puVar3[0x1b] + 0x60);
      }
      else {
        uVar9 = memdescGetPte(*puVar3,1,0);
        *(undefined8 *)(lVar4 + 0x40) = uVar9;
      }
    }
    lVar7 = puVar3[0x24];
    if (DAT_0054eab8 == 0) {
      *(undefined8 *)(lVar7 + 0x50) = 0;
    }
    else {
      uVar9 = vgpuGspSysmemPfnMakeBufferAddress(DAT_0054eab8,_DAT_0054eab0);
      *(undefined8 *)(lVar7 + 0x50) = uVar9;
    }
    uVar9 = vgpuGspMakeBufferAddress(puVar1,puVar3[0x16]);
    iVar6 = _vgpuGspSendSetupRequest(param_1,uVar9);
    if (iVar6 == 0) {
      if (*(char *)(param_1 + 0x454) != '\0') {
        lVar7 = gpuGetRpc(param_1);
        if (lVar7 == 0) {
          nvCheckFailedNoLog(4,"(pRpc != NULL)","src/kernel/vgpu/rpc.c",0x58e);
          iVar6 = 0x3d;
          goto LAB_004c3476;
        }
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x590,"_vgpuGspSetupCommunicationWithPlugin",1,
                     "NVRM: RPC: Response buf addr IOVA   0x%llx\n",
                     *(undefined8 *)(puVar3[0x24] + 8));
        uVar8 = memdescGetPte(puVar3[0x17],0,0);
        lVar4 = puVar3[0x24];
        uVar10 = vgpuGspMakeBufferAddress(puVar2,uVar8 >> 0xc);
        *(undefined8 *)(lVar4 + 8) = uVar10;
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x595,"_vgpuGspSetupCommunicationWithPlugin",1,
                     "NVRM: RPC: Control  buf addr IOVA   0x%llx\n",uVar9);
        uVar8 = memdescGetPte(puVar3[0x13],0,0);
        uVar9 = vgpuGspMakeBufferAddress(puVar1,uVar8 >> 0xc);
        (**(code **)(lVar7 + 0x238))(param_1,uVar9);
      }
    }
    else {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x586,"_vgpuGspSetupCommunicationWithPlugin",4,
                   "NVRM: Communication setup with GSP plugin failed 0x%x\n",iVar6);
    }
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x59d,"_vgpuGspSetupCommunicationWithPlugin",1,
                 "NVRM: RPC: Version                   0x%x\n",*(undefined4 *)puVar3[0x24]);
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x59e,"_vgpuGspSetupCommunicationWithPlugin",1,
                 "NVRM: RPC: Requested GSP caps        0x%x\n",*(undefined4 *)(puVar3[0x24] + 0x5c))
    ;
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x59f,"_vgpuGspSetupCommunicationWithPlugin",1,
                 "NVRM: RPC: Enabled   GSP caps        0x%x\n",*(undefined4 *)(puVar3[0x25] + 0x10))
    ;
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x5a0,"_vgpuGspSetupCommunicationWithPlugin",1,
                 "NVRM: RPC: Control   buf addr        0x%llx\n",uVar9);
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x5a1,"_vgpuGspSetupCommunicationWithPlugin",1,
                 "NVRM: RPC: Response  buf addr        0x%llx\n",*(undefined8 *)(puVar3[0x24] + 8));
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x5a2,"_vgpuGspSetupCommunicationWithPlugin",1,
                 "NVRM: RPC: Message   buf addr        0x%llx\n",
                 *(undefined8 *)(puVar3[0x24] + 0x18));
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x5a3,"_vgpuGspSetupCommunicationWithPlugin",1,
                 "NVRM: RPC: Message   buf BAR2 offset 0x%llx\n",
                 *(undefined8 *)(puVar3[0x24] + 0x20));
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x5a4,"_vgpuGspSetupCommunicationWithPlugin",1,
                 "NVRM: RPC: Shared    buf addr        0x%llx\n",
                 *(undefined8 *)(puVar3[0x24] + 0x28));
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x5a5,"_vgpuGspSetupCommunicationWithPlugin",1,
                 "NVRM: RPC: Shared    buf BAR2 offset 0x%llx\n",
                 *(undefined8 *)(puVar3[0x24] + 0x30));
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x5a6,"_vgpuGspSetupCommunicationWithPlugin",1,
                 "NVRM: RPC: Event     buf addr        0x%llx\n",
                 *(undefined8 *)(puVar3[0x24] + 0x38));
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x5a7,"_vgpuGspSetupCommunicationWithPlugin",1,
                 "NVRM: RPC: Event     buf BAR2 offset 0x%llx\n",
                 *(undefined8 *)(puVar3[0x24] + 0x40));
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x5a8,"_vgpuGspSetupCommunicationWithPlugin",1,
                 "NVRM: RPC: Debug     buf addr        0x%llx\n",
                 *(undefined8 *)(puVar3[0x24] + 0x60));
    if (iVar6 == 0) {
      if (((DAT_0054ea98 == '\0') || (*(char *)(param_1 + 0x472) == '\0')) ||
         (iVar6 = updateSharedBufferInfoInSysmemPfnBitMap_part_0(param_1,puVar3,1,0), iVar6 == 0)) {
        setGuestEccStatus(param_1);
        gpuGetStaticInfo(param_1);
        *(undefined1 *)((long)puVar3 + 0x26153) = 1;
        return 0;
      }
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x63a,"vgpuGspSetupBuffers",4,
                   "NVRM: RPC: Sysmem PFN bitmap update failed for shared buffer sysmem pages failed: 0x%x\n"
                   ,iVar6);
      goto LAB_004c3142;
    }
  }
LAB_004c3476:
  nvDbg_Printf("src/kernel/vgpu/rpc.c",0x62f,"vgpuGspSetupBuffers",4,
               "NVRM: RPC: GSP Setup failed: 0x%x\n",iVar6);
LAB_004c3142:
  vgpuGspTeardownBuffers(param_1);
  return iVar6;
}


// ===== 004c3660 freeRpcInfrastructure_VGPU =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 freeRpcInfrastructure_VGPU(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
  if ((lVar1 != 0) && (*(char *)(lVar1 + 0x26152) != '\0')) {
    if (*(char *)(lVar1 + 0x150) == '\0') {
      lVar2 = *(long *)(lVar1 + 0x26158);
    }
    else {
      vgpuGspTeardownBuffers();
      lVar2 = *(long *)(lVar1 + 0x26158);
    }
    if (lVar2 != 0) {
      (**(code **)(lVar2 + 0x10))(param_1);
      portMemFree(*(undefined8 *)(lVar1 + 0x26158));
      *(undefined8 *)(lVar1 + 0x26158) = 0;
    }
    *(undefined1 *)(lVar1 + 0x26152) = 0;
    return 0;
  }
  return 0x40;
}


// ===== 004c3700 rpcSendMessage_IMPL =====

undefined8 rpcSendMessage_IMPL(void)

{
  nvDbg_Printf("src/kernel/vgpu/rpc.c",0x710,"rpcSendMessage_IMPL",4,
               "NVRM: virtual function not implemented.\n");
  return 0x56;
}


// ===== 004c3740 rpcRecvPoll_IMPL =====

undefined8 rpcRecvPoll_IMPL(void)

{
  nvDbg_Printf("src/kernel/vgpu/rpc.c",0x716,"rpcRecvPoll_IMPL",4,
               "NVRM: virtual function not implemented.\n");
  return 0x56;
}


// ===== 004c3780 _serializeClassParams_v =====

undefined8 _serializeClassParams_v(undefined8 param_1,long param_2,uint param_3,undefined8 *param_4)

{
  long lVar1;
  undefined4 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  if (param_3 == 0xb1cc) {
    *(undefined4 *)(lVar1 + 0x38) = *(undefined4 *)param_4;
    uVar2 = 4;
    lVar1 = *(long *)(param_2 + 0x4d8);
    goto LAB_004c38ed;
  }
  if (param_3 < 0xb1cd) {
    if (param_3 == 0x9072) {
      *(undefined4 *)(lVar1 + 0x38) = 0;
      *(undefined8 *)(lVar1 + 0x40) = 0;
      *(undefined4 *)(lVar1 + 0x48) = *(undefined4 *)param_4;
      *(undefined4 *)(lVar1 + 0x4c) = *(undefined4 *)((long)param_4 + 4);
      *(undefined4 *)(lVar1 + 0x50) = *(undefined4 *)(param_4 + 1);
      uVar2 = 0x20;
      lVar1 = *(long *)(param_2 + 0x4d8);
      goto LAB_004c38ed;
    }
    if (0x9072 < param_3) {
      if (param_3 != 0xa0bc) {
        if (param_3 < 0xa0bd) {
          if (param_3 == 0x90f1) {
            *(undefined4 *)(lVar1 + 0x38) = *(undefined4 *)param_4;
            *(undefined4 *)(lVar1 + 0x3c) = *(undefined4 *)((long)param_4 + 4);
            *(undefined8 *)(lVar1 + 0x40) = param_4[1];
            *(undefined4 *)(lVar1 + 0x48) = *(undefined4 *)(param_4 + 4);
            *(undefined8 *)(lVar1 + 0x50) = param_4[5];
            *(undefined4 *)(lVar1 + 0x58) = *(undefined4 *)(param_4 + 6);
            uVar2 = 0x28;
            lVar1 = *(long *)(param_2 + 0x4d8);
          }
          else {
            if (param_3 != 0xa06c) {
              return 0x22;
            }
            *(undefined4 *)(lVar1 + 0x38) = *(undefined4 *)param_4;
            *(undefined4 *)(lVar1 + 0x3c) = *(undefined4 *)(param_4 + 1);
            *(undefined4 *)(lVar1 + 0x40) = *(undefined4 *)((long)param_4 + 0xc);
            uVar2 = 0xc;
            lVar1 = *(long *)(param_2 + 0x4d8);
          }
        }
        else {
          if (param_3 != 0xa0bd) {
            return 0x22;
          }
          *(undefined4 *)(lVar1 + 0x38) = *(undefined4 *)param_4;
          *(undefined4 *)(lVar1 + 0x3c) = *(undefined4 *)((long)param_4 + 4);
          *(undefined4 *)(lVar1 + 0x40) = *(undefined4 *)(param_4 + 1);
          *(undefined4 *)(lVar1 + 0x44) = *(undefined4 *)((long)param_4 + 0xc);
          *(undefined4 *)(lVar1 + 0x48) = *(undefined4 *)(param_4 + 2);
          uVar2 = 0x14;
          lVar1 = *(long *)(param_2 + 0x4d8);
        }
        goto LAB_004c38ed;
      }
      goto LAB_004c38d0;
    }
    if (param_3 == 0x503c) {
      if (param_4 != (undefined8 *)0x0) {
        *(undefined4 *)(lVar1 + 0x38) = *(undefined4 *)param_4;
        uVar2 = 0x10;
        lVar1 = *(long *)(param_2 + 0x4d8);
        goto LAB_004c38ed;
      }
    }
    else {
      if (0x503c < param_3) {
        if (param_3 != 0x83de) {
          if (param_3 != 0x9067) {
            return 0x22;
          }
          goto LAB_004c38d0;
        }
        goto LAB_004c38d5;
      }
      if (param_3 == 0xf8) {
        if (param_4 != (undefined8 *)0x0) {
          *(undefined8 *)(lVar1 + 0x38) = *param_4;
          *(undefined8 *)(lVar1 + 0x40) = param_4[1];
          *(int *)(lVar1 + 0x48) = (int)param_4[2];
          *(undefined4 *)(lVar1 + 0x4c) = *(undefined4 *)(param_4 + 3);
          *(undefined8 *)(lVar1 + 0x50) = param_4[4];
          *(undefined4 *)(lVar1 + 0x58) = *(undefined4 *)(param_4 + 5);
          *(undefined4 *)(lVar1 + 0x5c) = *(undefined4 *)((long)param_4 + 0x2c);
          uVar2 = 0x28;
          lVar1 = *(long *)(param_2 + 0x4d8);
          goto LAB_004c38ed;
        }
      }
      else {
        if (param_3 != 0x503b) {
          return 0x22;
        }
        if (param_4 != (undefined8 *)0x0) {
          *(undefined4 *)(lVar1 + 0x38) = *(undefined4 *)param_4;
          *(undefined4 *)(lVar1 + 0x3c) = *(undefined4 *)((long)param_4 + 4);
          *(undefined4 *)(lVar1 + 0x40) = *(undefined4 *)(param_4 + 1);
          *(undefined4 *)(lVar1 + 0x44) = *(undefined4 *)((long)param_4 + 0xc);
          *(undefined8 *)(lVar1 + 0x48) = param_4[2];
          *(undefined4 *)(lVar1 + 0x50) = *(undefined4 *)(param_4 + 3);
          *(undefined4 *)(lVar1 + 0x54) = *(undefined4 *)((long)param_4 + 0x1c);
          uVar2 = 0x20;
          lVar1 = *(long *)(param_2 + 0x4d8);
          goto LAB_004c38ed;
        }
      }
    }
LAB_004c3a20:
    uVar2 = 0;
  }
  else {
    if (param_3 == 0xc997) goto LAB_004c3965;
    if (param_3 < 0xc998) {
      if (param_3 != 0xc637) {
        if (param_3 < 0xc638) {
          if (param_3 != 0xb8d1) {
            if (0xb8d1 < param_3) {
              if (param_3 != 0xb8fa) {
                if (param_3 != 0xc574) {
                  return 0x22;
                }
                if (param_4 != (undefined8 *)0x0) goto LAB_004c37db;
                goto LAB_004c3a20;
              }
              goto LAB_004c3b58;
            }
            if (param_3 == 0xb2cc) goto LAB_004c37db;
            if (param_3 != 0xb8b0) {
              return 0x22;
            }
          }
          goto LAB_004c38d0;
        }
        if (param_3 != 0xc638) {
          if (param_3 != 0xc7fa) {
            if (0xc7fa < param_3) {
              if (param_3 != 0xc8b5) {
                return 0x22;
              }
LAB_004c37db:
              *(undefined4 *)(lVar1 + 0x38) = *(undefined4 *)param_4;
              *(undefined4 *)(lVar1 + 0x3c) = *(undefined4 *)((long)param_4 + 4);
              *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x30) = 8;
              return 0;
            }
            if (param_3 != 0xc6fa) {
              if (param_3 != 0xc7b5) {
                return 0x22;
              }
              goto LAB_004c37db;
            }
          }
          goto LAB_004c3b58;
        }
      }
      *(undefined4 *)(lVar1 + 0x38) = *(undefined4 *)(param_4 + 1);
      uVar2 = 4;
      lVar1 = *(long *)(param_2 + 0x4d8);
      goto LAB_004c38ed;
    }
    if (param_3 != 0xcdb0) {
      if (param_3 < 0xcdb1) {
        if (param_3 != 0xc9d1) {
          if (0xc9d1 < param_3) {
            if (param_3 != 0xcb97) {
              if (param_3 < 0xcb98) {
                if (param_3 != 0xc9fa) {
                  if (param_3 != 0xcab5) {
                    return 0x22;
                  }
                  goto LAB_004c37db;
                }
                goto LAB_004c3b58;
              }
              if (param_3 == 0xcbc0) goto LAB_004c395c;
              if (param_3 != 0xcd97) {
                return 0x22;
              }
            }
LAB_004c3965:
            *(undefined4 *)(lVar1 + 0x38) = *(undefined4 *)param_4;
            *(undefined4 *)(lVar1 + 0x3c) = *(undefined4 *)((long)param_4 + 4);
            *(undefined4 *)(lVar1 + 0x40) = *(undefined4 *)(param_4 + 1);
            *(undefined4 *)(lVar1 + 0x44) = *(undefined4 *)((long)param_4 + 0xc);
            uVar2 = 0x10;
            lVar1 = *(long *)(param_2 + 0x4d8);
            goto LAB_004c38ed;
          }
          if (param_3 != 0xc9b7) {
            if (0xc9b7 < param_3) {
              if (param_3 != 0xc9c0) {
                return 0x22;
              }
LAB_004c395c:
              if (param_4 == (undefined8 *)0x0) goto LAB_004c3a20;
              goto LAB_004c3965;
            }
            if (param_3 != 0xc9b0) {
              if (param_3 != 0xc9b5) {
                return 0x22;
              }
              goto LAB_004c37db;
            }
          }
        }
      }
      else if (param_3 != 0xceb7) {
        if (param_3 < 0xceb8) {
          if (param_3 == 0xcdfa) goto LAB_004c3b58;
          if (param_3 < 0xcdfb) {
            if (param_3 == 0xcdc0) goto LAB_004c395c;
            if (param_3 != 0xcdd1) {
              return 0x22;
            }
          }
          else {
            if (param_3 == 0xce97) goto LAB_004c3965;
            if (param_3 != 0xceb0) {
              return 0x22;
            }
          }
        }
        else {
          if (param_3 == 0xcefa) {
LAB_004c3b58:
            if (param_4 != (undefined8 *)0x0) {
              *(undefined4 *)(lVar1 + 0x38) = *(undefined4 *)param_4;
              *(undefined4 *)(lVar1 + 0x3c) = *(undefined4 *)((long)param_4 + 4);
              uVar2 = 0xc;
              lVar1 = *(long *)(param_2 + 0x4d8);
              goto LAB_004c38ed;
            }
            goto LAB_004c3a20;
          }
          if (param_3 < 0xcefb) {
            if (param_3 == 0xcec0) goto LAB_004c395c;
            if (param_3 != 0xced0) {
              return 0x22;
            }
          }
          else if (param_3 != 0xcfd1) {
            if (param_3 == 0xcffa) goto LAB_004c3b58;
            if (param_3 != 0xcfb0) {
              return 0x22;
            }
          }
        }
      }
    }
LAB_004c38d0:
    *(undefined4 *)(lVar1 + 0x38) = *(undefined4 *)param_4;
LAB_004c38d5:
    *(undefined4 *)(lVar1 + 0x3c) = *(undefined4 *)((long)param_4 + 4);
    *(undefined4 *)(lVar1 + 0x40) = *(undefined4 *)(param_4 + 1);
    lVar1 = *(long *)(param_2 + 0x4d8);
    uVar2 = 0xc;
  }
LAB_004c38ed:
  *(undefined4 *)(lVar1 + 0x30) = uVar2;
  return 0;
}


// ===== 004c3cc0 _serializeClassParams_v27_00 =====

undefined8 _serializeClassParams_v27_00(undefined8 param_1,undefined8 param_2,int param_3)

{
  undefined8 uVar1;
  
  if (param_3 != 0xd1b7) {
    if (param_3 == 0xd1fa) {
      uVar1 = _serializeClassParams_v(param_1,param_2,0xcffa);
      return uVar1;
    }
    if (param_3 == 0xd1b0) {
      uVar1 = _serializeClassParams_v(param_1,param_2,0xcfb0);
      return uVar1;
    }
    if (param_3 != 0xcfb7) {
      if (param_3 - 0x2081U < 2) {
        return 0;
      }
      uVar1 = _serializeClassParams_v();
      return uVar1;
    }
  }
  uVar1 = _serializeClassParams_v(param_1,param_2,0xc9b7);
  return uVar1;
}


// ===== 004c3d30 rpcLog_v03_00 =====

undefined8 rpcLog_v03_00(undefined8 param_1,long param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = portStringLength(param_3);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0xb,iVar1 + 9);
  if ((int)uVar2 == 0) {
    if ((ulong)(iVar1 + 1U) <= (ulong)*(uint *)(param_2 + 0x4f0) + 8) {
      *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_4;
      *(uint *)(*(long *)(param_2 + 0x4d8) + 0x24) = iVar1 + 1U;
      portStringCopy(*(long *)(param_2 + 0x4d8) + 0x28,
                     *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24),param_3);
      uVar2 = _issueRpcAndWait(param_1,param_2);
      return uVar2;
    }
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0xbd8,"rpcLog_v03_00",4,"NVRM: LOG RPC - string too long\n"
                );
    uVar2 = 2;
  }
  return uVar2;
}


// ===== 004c3e10 rpcAllocRoot_v07_00 =====

undefined8 rpcAllocRoot_v07_00(long param_1,long param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  
  uVar2 = rpcWriteCommonHeader(param_1,param_2,2,0x6c);
  if ((int)uVar2 == 0) {
    *(undefined1 *)(*(long *)(param_2 + 0x4d8) + 0x28) = 0;
    lVar3 = serverutilGetClientUnderLock(param_3);
    if (lVar3 == 0) {
      uVar2 = 0x23;
    }
    else {
      lVar4 = resservGetTlsCallContext();
      if (lVar4 != 0) {
        iVar5 = -1;
        if (*(uint *)(lVar4 + 0x28) < 2) {
          iVar5 = *(int *)(lVar3 + 0x118);
          iVar1 = osGetCurrentProcess();
          if (iVar1 != iVar5) {
            nvAssertFailedNoLog("processID == osGetCurrentProcess()","src/kernel/vgpu/rpc.c",0xd56);
          }
          osGetCurrentProcessName(*(long *)(param_2 + 0x4d8) + 0x28,100);
        }
        if (*(char *)(param_1 + 0x908) != '\0') {
          iVar1 = clientSetHandleGenerator_IMPL(*(undefined8 *)(lVar3 + 0x100),0xcaf00000,0x3f000);
          if (iVar1 != 0) {
            nvDbg_Printf("src/kernel/vgpu/rpc.c",0xd67,"rpcAllocRoot_v07_00",4,
                         "NVRM: NVRM_RPC: Failed to set guest client resource handle range %x\n",
                         iVar1);
          }
        }
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
        *(int *)(*(long *)(param_2 + 0x4d8) + 0x24) = iVar5;
        uVar2 = _issueRpcAndWait(param_1,param_2);
        return uVar2;
      }
      nvAssertFailedNoLog("pCallContext != NULL","src/kernel/vgpu/rpc.c",0xd4c);
      uVar2 = 0x40;
    }
  }
  return uVar2;
}


// ===== 004c3fe0 rpcAllocShareDevice_v03_00 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void rpcAllocShareDevice_v03_00
               (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9,undefined8 param_10,undefined4 param_11)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = (**(code **)(param_2 + 0x3f0))(param_1,param_2,param_3);
  if (iVar2 == 0) {
    iVar2 = rpcWriteCommonHeader(param_1,param_2,0x20,0x40);
    if (iVar2 == 0) {
      *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
      *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
      *(undefined4 *)(lVar1 + 0x38) = param_5;
      *(undefined4 *)(lVar1 + 0x3c) = param_6;
      *(undefined4 *)(lVar1 + 0x40) = param_7;
      *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28) = param_8;
      *(undefined8 *)(lVar1 + 0x48) = param_10;
      *(undefined4 *)(lVar1 + 0x50) = param_11;
      *(undefined4 *)(lVar1 + 0x44) = param_9;
      _issueRpcAndWait(param_1,param_2);
      return;
    }
  }
  return;
}


// ===== 004c4100 rpcAllocMemory_v13_01 =====

int rpcAllocMemory_v13_01
              (long param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
              undefined4 param_6,undefined4 param_7,undefined8 *param_8)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  long lVar8;
  
  if (param_8 == (undefined8 *)0x0) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0xda1,"rpcAllocMemory_v13_01",4,
                 "NVRM: NVRM_RPC: AllocMemory: pMemDesc arg was NULL\n");
    return 0xffff;
  }
  iVar1 = rpcWriteCommonHeader(param_1,param_2,4,0x38);
  if (iVar1 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28) = param_5;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x2c) = param_6;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x30) = param_7;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x34) = *(undefined4 *)(param_8 + 0xc);
    lVar4 = *(long *)(param_2 + 0x4d8);
    uVar2 = memdescGetPteKindForGpu(param_8,*param_8);
    *(undefined4 *)(lVar4 + 0x38) = uVar2;
    *(undefined8 *)(*(long *)(param_2 + 0x4d8) + 0x40) = param_8[6];
    *(int *)(*(long *)(param_2 + 0x4d8) + 0x48) = (int)param_8[3];
    if (*(char *)(param_1 + 0x909) != '\0') {
      lVar4 = *(long *)(param_2 + 0x4d8);
      uVar2 = memdescGetPteArraySize(param_8,1);
      *(undefined4 *)(lVar4 + 0x48) = uVar2;
      lVar4 = memdescGetPteArrayForGpu(param_8,*param_8,1);
      uVar3 = memdescGetPteArraySize(param_8,1);
      if (lVar4 == 0) {
        nvAssertFailedNoLog("guestPages != NULL","src/kernel/vgpu/rpc.c",0x8ee);
      }
      else {
        lVar5 = *(long *)(param_2 + 0x4d8);
        if (lVar5 != 0) {
          uVar7 = uVar3 * 8 + 0x58;
          lVar6 = lVar5;
          lVar8 = 0;
          if (*(uint *)(param_2 + 0x4f0) < uVar7) {
            lVar6 = portMemAllocNonPaged(uVar7);
            if (lVar6 == 0) {
              nvDbg_Printf("src/kernel/vgpu/rpc.c",0x8fa,"_issuePteDescRpc",4,
                           "NVRM: no memory for allocated record\n");
              return 0x1a;
            }
            portMemCopy(lVar6,*(undefined4 *)(lVar5 + 8),lVar5,*(undefined4 *)(lVar5 + 8));
            lVar8 = lVar6;
          }
          *(byte *)(lVar6 + 0x50) = *(byte *)(lVar6 + 0x50) & 0xfc;
          *(short *)(lVar6 + 0x52) = (short)uVar3;
          if (uVar3 != 0) {
            lVar5 = 0;
            do {
              *(ulong *)(lVar6 + 0x58 + lVar5) = *(ulong *)(lVar4 + lVar5) >> 0xc;
              lVar5 = lVar5 + 8;
            } while (lVar5 != (ulong)uVar3 << 3);
          }
          iVar1 = _issueRpcLarge(param_1,param_2,uVar7,lVar6,0,1);
          portMemFree(lVar8);
          return iVar1;
        }
        nvAssertFailedNoLog("pHdr != NULL","src/kernel/vgpu/rpc.c",0x8ef);
      }
      iVar1 = 0x1f;
    }
  }
  return iVar1;
}


// ===== 004c4460 rpcAllocChannelDma_v1F_04 =====

undefined8
rpcAllocChannelDma_v1F_04
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 *param_7,undefined4 *param_8)

{
  long lVar1;
  undefined8 uVar2;
  
  if (param_7 == (undefined4 *)0x0) {
    nvCheckFailedNoLog(1,"pGpfifoAllocParams != NULL","src/kernel/vgpu/rpc.c",0xdcd);
  }
  else {
    if (param_8 != (undefined4 *)0x0) {
      uVar2 = rpcWriteCommonHeader(param_1,param_2,6,0xf8);
      if ((int)uVar2 == 0) {
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28) = param_5;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x2c) = param_6;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x110) = *param_8;
        lVar1 = *(long *)(param_2 + 0x4d8);
        *(undefined4 *)(lVar1 + 0x38) = *param_7;
        *(undefined4 *)(lVar1 + 0x3c) = param_7[1];
        *(undefined8 *)(lVar1 + 0x40) = *(undefined8 *)(param_7 + 2);
        *(undefined4 *)(lVar1 + 0x48) = param_7[4];
        *(undefined4 *)(lVar1 + 0x4c) = param_7[5];
        *(undefined4 *)(lVar1 + 0xd8) = param_7[0x3d];
        *(undefined4 *)(lVar1 + 0x50) = param_7[6];
        *(undefined4 *)(lVar1 + 0x54) = param_7[7];
        *(undefined4 *)(lVar1 + 0xd0) = param_7[0x3c];
        *(undefined4 *)(lVar1 + 0x58) = param_7[8];
        *(undefined8 *)(lVar1 + 0x60) = *(undefined8 *)(param_7 + 0x10);
        *(undefined4 *)(lVar1 + 0x68) = param_7[0x20];
        *(undefined4 *)(lVar1 + 0x6c) = param_7[0x23];
        *(undefined4 *)(lVar1 + 0xd4) = param_7[0x22];
        *(undefined8 *)(lVar1 + 0x70) = *(undefined8 *)(param_7 + 0x24);
        *(undefined8 *)(lVar1 + 0x78) = *(undefined8 *)(param_7 + 0x26);
        *(undefined4 *)(lVar1 + 0x80) = param_7[0x28];
        *(undefined4 *)(lVar1 + 0x84) = param_7[0x29];
        *(undefined8 *)(lVar1 + 0x88) = *(undefined8 *)(param_7 + 0x30);
        *(undefined8 *)(lVar1 + 0x90) = *(undefined8 *)(param_7 + 0x32);
        *(undefined4 *)(lVar1 + 0x98) = param_7[0x34];
        *(undefined4 *)(lVar1 + 0x9c) = param_7[0x35];
        *(undefined8 *)(lVar1 + 0xa0) = *(undefined8 *)(param_7 + 0x2a);
        *(undefined8 *)(lVar1 + 0xa8) = *(undefined8 *)(param_7 + 0x2c);
        *(undefined4 *)(lVar1 + 0xb0) = param_7[0x2e];
        *(undefined4 *)(lVar1 + 0xb4) = param_7[0x2f];
        *(undefined8 *)(lVar1 + 0xb8) = *(undefined8 *)(param_7 + 0x36);
        *(undefined8 *)(lVar1 + 0xc0) = *(undefined8 *)(param_7 + 0x38);
        *(undefined4 *)(lVar1 + 200) = param_7[0x3a];
        *(undefined4 *)(lVar1 + 0xcc) = param_7[0x3b];
        *(undefined8 *)(lVar1 + 0xe0) = *(undefined8 *)(param_7 + 0x3e);
        *(undefined8 *)(lVar1 + 0xe8) = *(undefined8 *)(param_7 + 0x40);
        *(undefined4 *)(lVar1 + 0xf0) = param_7[0x42];
        *(undefined4 *)(lVar1 + 0xf4) = param_7[0x43];
        *(undefined8 *)(lVar1 + 0xf8) = *(undefined8 *)(param_7 + 0x44);
        *(undefined8 *)(lVar1 + 0x100) = *(undefined8 *)(param_7 + 0x46);
        *(undefined4 *)(lVar1 + 0x108) = param_7[0x48];
        *(undefined4 *)(lVar1 + 0x10c) = param_7[0x49];
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x30) = 0;
        uVar2 = _issueRpcAndWait(param_1,param_2);
        if ((int)uVar2 == 0) {
          *param_8 = *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x110);
          return uVar2;
        }
      }
      return uVar2;
    }
    nvCheckFailedNoLog(1,"pChID != NULL","src/kernel/vgpu/rpc.c",0xdce);
  }
  return 0x1f;
}


