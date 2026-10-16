// ===== 00520750 serverAcquireClient =====

undefined8 serverAcquireClient(void)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 *in_RCX;
  undefined8 local_20;
  
  if (in_RCX != (undefined8 *)0x0) {
    cVar1 = _serverGetAndLockClientEntryByHandle();
    uVar2 = 0x33;
    if (cVar1 != '\0') {
      *in_RCX = local_20;
      uVar2 = 0;
    }
    return uVar2;
  }
  return 0x1f;
}


// ===== 005207a0 serverGetClientUnderLock =====

undefined8 serverGetClientUnderLock(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  char cVar1;
  long local_20 [2];
  
  cVar1 = __serverFindClientEntryByHandle(param_1,param_2,2,1,0,local_20);
  if (cVar1 == '\x01') {
    if (param_3 != (undefined8 *)0x0) {
      *param_3 = *(undefined8 *)(local_20[0] + 8);
    }
    return 0;
  }
  return 0x33;
}


// ===== 00520800 serverReleaseClient =====

void serverReleaseClient(long param_1,int param_2,undefined8 *param_3)

{
  int *piVar1;
  
  if (param_2 == 0) {
    LOCK();
    *(int *)(param_3 + 4) = *(int *)(param_3 + 4) + -1;
    UNLOCK();
    portSyncRwLockReleaseRead(*param_3);
  }
  else {
    param_3[3] = 0xffffffffffffffff;
    portSyncRwLockReleaseWrite(*param_3);
  }
  LOCK();
  piVar1 = (int *)((long)param_3 + 0x24);
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (*piVar1 != 0) {
    return;
  }
  param_3[1] = 0;
  *(undefined4 *)(param_3 + 2) = 0;
  portSyncRwLockDestroy(*param_3);
  _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x18),param_3);
  return;
}


// ===== 00520870 serverIsClientLocked =====

bool serverIsClientLocked(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  char cVar2;
  long lVar3;
  long local_20 [2];
  
  cVar2 = __serverFindClientEntryByHandle(param_1,param_2,0,1,0,local_20);
  if (cVar2 == '\x01') {
    lVar1 = *(long *)(local_20[0] + 0x18);
    lVar3 = portThreadGetCurrentThreadId();
    return lVar1 == lVar3;
  }
  return (bool)0x33;
}


// ===== 005208c0 serverIsClientInternal =====

undefined4 serverIsClientInternal(long param_1,uint param_2)

{
  return CONCAT31((int3)(*(uint *)(param_1 + 0xa8) >> 8),(~param_2 & *(uint *)(param_1 + 0xa8)) == 0
                 );
}


// ===== 005208e0 serverLockAllClients =====

undefined8 serverLockAllClients(long param_1)

{
  long lVar1;
  long lVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  uint uVar6;
  long *plVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  uint uVar11;
  uint uVar12;
  long lVar13;
  long *plVar14;
  uint uVar15;
  long lVar16;
  long *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  long *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  plVar7 = (long *)_portMemAllocatorAlloc(*(undefined8 *)(param_1 + 0x18),0x2000);
  if (plVar7 == (long *)0x0) {
LAB_00520992:
    nvAssertOkFailedNoLog
              (0x51,"_serverBuildAllClientLockList(pServer)","src/libraries/resserv/src/rs_server.c"
               ,0xb2c);
    return 0x51;
  }
  lVar1 = param_1 + 0xe8;
  uVar15 = 0;
  while( true ) {
    uVar11 = *(uint *)(param_1 + 0xb0);
    listInit_IMPL(lVar1,*(undefined8 *)(param_1 + 0x18),8);
    if (uVar15 < uVar11) {
      do {
        puVar8 = (undefined8 *)listAppendNew_IMPL(lVar1);
        if (puVar8 == (undefined8 *)0x0) {
          listDestroy_IMPL(lVar1);
          _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x18),plVar7);
          goto LAB_00520992;
        }
        uVar15 = uVar15 + 1;
        *puVar8 = 0;
      } while (uVar11 != uVar15);
    }
    portSyncSpinlockAcquire(*(undefined8 *)(param_1 + 0x20));
    if (*(uint *)(param_1 + 0xb0) <= uVar11) break;
    portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x20));
  }
  lVar16 = 0;
  plVar14 = plVar7;
  do {
    lVar13 = *(long *)(param_1 + 8) + lVar16;
    lVar16 = lVar16 + 0x18;
    lVar13 = listHead_IMPL(lVar13);
    *plVar14 = lVar13;
    plVar14 = plVar14 + 1;
  } while (lVar16 != 0x6000);
  uVar9 = listTail_IMPL(lVar1);
  uVar10 = listHead_IMPL(lVar1);
  listIterRange_IMPL(&local_78,lVar1,uVar10,uVar9);
  local_58 = local_78;
  local_50 = local_70;
  local_48 = local_68;
  local_40 = local_60;
  if (uVar11 != 0) {
    uVar15 = 0xc1d00000;
    do {
      bVar4 = false;
      lVar16 = 0;
      uVar12 = 0xffffffff;
      uVar11 = 0xffffffff;
      plVar14 = plVar7;
      do {
        lVar13 = *plVar14;
        if (lVar13 != 0) {
          uVar6 = *(uint *)(lVar13 + 0x10);
          if (uVar6 < uVar15) {
joined_r0x00520b4d:
            if (uVar6 < uVar15 + 0x400) goto LAB_00520abb;
          }
          else if (uVar6 < uVar15 + 0x400) {
            lVar2 = *(long *)(param_1 + 8);
            cVar5 = listIterNext_IMPL(&local_58);
            if (cVar5 == '\0') {
              nvAssertFailedNoLog("listIterNext(&lockedClientListIter)",
                                  "src/libraries/resserv/src/rs_server.c",0xaf3);
            }
            if ((*(long *)(lVar13 + 8) != 0) && (*(char *)(lVar13 + 0x28) == '\0')) {
              *local_58 = lVar13;
              if (*(char *)(lVar13 + 0x28) != '\0') {
                nvAssertFailedNoLog("!pClientEntry->bPendingFree",
                                    "src/libraries/resserv/src/rs_server.c",0xc7c);
              }
              LOCK();
              *(int *)(lVar13 + 0x24) = *(int *)(lVar13 + 0x24) + 1;
              UNLOCK();
            }
            lVar13 = listNext_IMPL(lVar2 + lVar16,lVar13);
            *plVar14 = lVar13;
            if (lVar13 == 0) goto LAB_00520abb;
            uVar6 = *(uint *)(lVar13 + 0x10);
            goto joined_r0x00520b4d;
          }
          uVar6 = uVar6 & 0xfffffc00;
          bVar4 = true;
          bVar3 = uVar6 < uVar11;
          uVar11 = uVar12;
          if (bVar3) {
            uVar11 = uVar6;
            uVar12 = uVar6;
          }
        }
LAB_00520abb:
        lVar16 = lVar16 + 0x18;
        plVar14 = plVar14 + 1;
      } while (lVar16 != 0x6000);
      uVar15 = uVar11;
    } while (bVar4);
  }
  portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x20));
  _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x18),plVar7);
  uVar9 = listTail_IMPL(lVar1);
  uVar10 = listHead_IMPL(lVar1);
  listIterRange_IMPL(&local_78,lVar1,uVar10,uVar9);
  local_58 = local_78;
  local_50 = local_70;
  local_48 = local_68;
  local_40 = local_60;
  while (cVar5 = listIterNext_IMPL(&local_58), cVar5 != '\0') {
    puVar8 = (undefined8 *)*local_58;
    if (puVar8 != (undefined8 *)0x0) {
      portSyncRwLockAcquireWrite(*puVar8);
      uVar9 = portThreadGetCurrentThreadId();
      puVar8[3] = uVar9;
    }
  }
  uVar9 = portThreadGetCurrentThreadId();
  *(undefined8 *)(param_1 + 0x48) = uVar9;
  return 0;
}


// ===== 00520ca0 serverUnlockAllClients =====

undefined8 serverUnlockAllClients(long param_1)

{
  int *piVar1;
  long lVar2;
  undefined8 *puVar3;
  long *plVar4;
  long lVar5;
  
  plVar4 = (long *)listTail_IMPL(param_1 + 0xe8);
  lVar2 = *(long *)(param_1 + 0x48);
  lVar5 = portThreadGetCurrentThreadId();
  if (lVar2 != lVar5) {
    nvAssertFailedNoLog("serverAllClientsLockIsOwner(pServer)",
                        "src/libraries/resserv/src/rs_server.c",0xb47);
    return 0x2f;
  }
  for (; plVar4 != (long *)0x0; plVar4 = (long *)listPrev_IMPL(param_1 + 0xe8,plVar4)) {
    puVar3 = (undefined8 *)*plVar4;
    if (puVar3 != (undefined8 *)0x0) {
      puVar3[3] = 0xffffffffffffffff;
      portSyncRwLockReleaseWrite(*puVar3);
      LOCK();
      piVar1 = (int *)((long)puVar3 + 0x24);
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (*piVar1 == 0) {
        puVar3[1] = 0;
        *(undefined4 *)(puVar3 + 2) = 0;
        portSyncRwLockDestroy(*puVar3);
        _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x18),puVar3);
      }
    }
  }
  listDestroy_IMPL(param_1 + 0xe8);
  *(undefined8 *)(param_1 + 0x48) = 0xffffffffffffffff;
  return 0;
}


// ===== 00520da0 serverGetClientCount =====

undefined4 serverGetClientCount(long param_1)

{
  return *(undefined4 *)(param_1 + 0xb0);
}


// ===== 00520db0 serverGetResourceCount =====

undefined8 serverGetResourceCount(long param_1)

{
  return *(undefined8 *)(param_1 + 0xb8);
}


// ===== 00520dc0 resservSwapTlsCallContext =====

undefined8 resservSwapTlsCallContext(long *param_1,long param_2)

{
  byte *pbVar1;
  long lVar2;
  long *plVar3;
  undefined8 uVar4;
  
  if (param_1 != (long *)0x0) {
    plVar3 = (long *)tlsEntryAcquire(1);
    if (plVar3 == (long *)0x0) {
      uVar4 = 0x40;
    }
    else {
      *param_1 = *plVar3;
      *plVar3 = param_2;
      if ((((param_2 != 0) && (*param_1 != 0)) && (*(long *)(param_2 + 0x48) != 0)) &&
         (lVar2 = *(long *)(*param_1 + 0x48), lVar2 != 0)) {
        pbVar1 = (byte *)(*(long *)(param_2 + 0x48) + 0x69);
        *pbVar1 = *pbVar1 | *(byte *)(lVar2 + 0x69);
      }
      uVar4 = 0;
    }
    return uVar4;
  }
  return 0x1f;
}


// ===== 00520e40 resservGetTlsCallContext =====

void resservGetTlsCallContext(void)

{
  tlsEntryGet(1);
  return;
}


// ===== 00520e50 resservRestoreTlsCallContext =====

undefined8 resservRestoreTlsCallContext(undefined8 param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)tlsEntryAcquire(1);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = param_1;
    tlsEntryRelease(1);
    tlsEntryRelease(1);
    return 0;
  }
  return 0x1f;
}


// ===== 00520ea0 resservGetContextRefByType =====

long resservGetContextRefByType(int param_1,char param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long local_20;
  
  lVar3 = tlsEntryGet(1);
  local_20 = 0;
  if (lVar3 != 0) {
    lVar1 = *(long *)(lVar3 + 0x10);
    if (lVar1 == 0) {
      lVar3 = *(long *)(lVar3 + 0x18);
      if (lVar3 == 0) {
        return 0;
      }
      if (*(int *)(lVar3 + 0x118) == param_1) {
        return lVar3;
      }
      if (param_2 == '\0') {
        return 0;
      }
    }
    else {
      if (*(int *)(lVar1 + 0x118) == param_1) {
        return lVar1;
      }
      if (param_2 == '\0') {
        lVar3 = *(long *)(lVar3 + 0x18);
        if (lVar3 == 0) {
          return 0;
        }
        if (param_1 == *(int *)(lVar3 + 0x118)) {
          return lVar3;
        }
        return 0;
      }
      iVar2 = refFindAncestorOfType(lVar1,param_1);
      if (iVar2 == 0) {
        return local_20;
      }
      lVar3 = *(long *)(lVar3 + 0x18);
      if (lVar3 == 0) {
        return 0;
      }
      if (param_1 == *(int *)(lVar3 + 0x118)) {
        return lVar3;
      }
    }
    iVar2 = refFindAncestorOfType(lVar3,param_1,&local_20);
    if (iVar2 == 0) {
      return local_20;
    }
  }
  return 0;
}


// ===== 00520f90 shrConstruct_IMPL =====

undefined8 shrConstruct_IMPL(void)

{
  return 0;
}


// ===== 00520fa0 shrDestruct_IMPL =====

void shrDestruct_IMPL(void)

{
  return;
}


// ===== 00520fb0 sessionConstruct_IMPL =====

undefined8 sessionConstruct_IMPL(long param_1)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)tlsEntryGet(1);
  *(undefined1 *)(param_1 + 0xa0) = 1;
  listInit_IMPL(param_1 + 0xa8,*(undefined8 *)(*plVar1 + 0x18),8);
  listInit_IMPL(param_1 + 0xd0,*(undefined8 *)(*plVar1 + 0x18),8);
  uVar2 = portSyncRwLockCreate(*(undefined8 *)(*plVar1 + 0x18));
  *(undefined8 *)(param_1 + 0x98) = uVar2;
  return 0;
}


// ===== 00521020 sessionDestruct_IMPL =====

void sessionDestruct_IMPL(long param_1)

{
  int iVar1;
  
  iVar1 = listCount_IMPL(param_1 + 0xa8);
  if (iVar1 == 0) {
    iVar1 = listCount_IMPL(param_1 + 0xd0);
  }
  else {
    nvAssertFailedNoLog("listCount(&pSession->dependencies) == 0",
                        "src/libraries/resserv/src/rs_server.c",0xf94);
    iVar1 = listCount_IMPL(param_1 + 0xd0);
  }
  if (iVar1 != 0) {
    nvAssertFailedNoLog("listCount(&pSession->dependants) == 0",
                        "src/libraries/resserv/src/rs_server.c",0xf95);
  }
  listDestroy_IMPL(param_1 + 0xa8);
  listDestroy_IMPL(param_1 + 0xd0);
  *(undefined8 *)(param_1 + 0x98) = 0;
  return;
}


// ===== 005210d0 sessionCheckLocksForAdd_IMPL =====

undefined8 sessionCheckLocksForAdd_IMPL(undefined8 param_1,long *param_2)

{
  long *plVar1;
  char cVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  
  puVar3 = (undefined8 *)tlsEntryGet(1);
  if (puVar3 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("pCallContext != NULL","src/libraries/resserv/src/rs_server.c",0xff5);
    return 0x40;
  }
  plVar1 = (long *)puVar3[4];
  if (plVar1 == (long *)0x0) {
    nvAssertFailedNoLog("(pLockInfo != NULL)","src/libraries/resserv/src/rs_server.c",0xff8);
    return 0x40;
  }
  cVar2 = serverRwApiLockIsOwner(*puVar3);
  if (cVar2 == '\0') {
    if ((*(uint *)((long)plVar1 + 0x2c) & 0x80) == 0) {
      if ((*(uint *)((long)plVar1 + 0x2c) & 1) == 0) {
        nvAssertFailedNoLog("Incorrect locks taken","src/libraries/resserv/src/rs_server.c",0x1009);
        return 0x2f;
      }
      if ((*plVar1 == 0) && (plVar1[1] == 0)) {
        return 0;
      }
      nvAssertFailedNoLog("(pLockInfo->pClient == NULL) && (pLockInfo->pSecondClient == NULL)",
                          "src/libraries/resserv/src/rs_server.c",0x1005);
    }
    else {
      if ((*plVar1 == *param_2) || (*param_2 == plVar1[1])) goto LAB_00521127;
      nvAssertFailedNoLog("(pLockInfo->pClient == pResourceRef->pClient) || (pLockInfo->pSecondClient == pResourceRef->pClient)"
                          ,"src/libraries/resserv/src/rs_server.c",0xfff);
    }
    uVar4 = 0x1f;
  }
  else {
LAB_00521127:
    uVar4 = 0;
  }
  return uVar4;
}


// ===== 00521240 sessionAddDependant_IMPL =====

int sessionAddDependant_IMPL(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  int *piVar3;
  long local_20 [2];
  
  local_20[0] = param_2;
  tlsEntryGet(1);
  iVar1 = sessionCheckLocksForAdd_IMPL(param_1,local_20[0]);
  if ((iVar1 == 0) && (*(long *)(local_20[0] + 0x1b8) != param_1)) {
    if (*(long *)(local_20[0] + 0x1b8) == 0) {
      lVar2 = listAppendValue_IMPL(param_1 + 0xd0,local_20);
      if (lVar2 == 0) {
        iVar1 = 0x1a;
      }
      else {
        piVar3 = (int *)&DAT_00000048;
        if (param_1 != 0) {
          piVar3 = (int *)(*(long *)(param_1 + 0x88) + 0x48);
        }
        LOCK();
        *piVar3 = *piVar3 + 1;
        UNLOCK();
        *(long *)(local_20[0] + 0x1b8) = param_1;
      }
    }
    else {
      nvAssertFailedNoLog("pResourceRef->pSession == NULL","src/libraries/resserv/src/rs_server.c",
                          0xfad);
      iVar1 = 0x1f;
    }
  }
  return iVar1;
}


// ===== 00521300 sessionAddDependency_IMPL =====

int sessionAddDependency_IMPL(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  int *piVar3;
  long local_20 [2];
  
  local_20[0] = param_2;
  tlsEntryGet(1);
  iVar1 = sessionCheckLocksForAdd_IMPL(param_1,local_20[0]);
  if ((iVar1 == 0) && (*(long *)(local_20[0] + 0x1c0) != param_1)) {
    if (*(long *)(local_20[0] + 0x1c0) == 0) {
      lVar2 = listAppendValue_IMPL(param_1 + 0xa8,local_20);
      if (lVar2 == 0) {
        iVar1 = 0x1a;
      }
      else {
        piVar3 = (int *)&DAT_00000048;
        if (param_1 != 0) {
          piVar3 = (int *)(*(long *)(param_1 + 0x88) + 0x48);
        }
        LOCK();
        *piVar3 = *piVar3 + 1;
        UNLOCK();
        *(long *)(local_20[0] + 0x1c0) = param_1;
      }
    }
    else {
      nvAssertFailedNoLog("pResourceRef->pDependantSession == NULL",
                          "src/libraries/resserv/src/rs_server.c",0xfcb);
      iVar1 = 0x1f;
    }
  }
  return iVar1;
}


// ===== 005213c0 serverAllocShareWithHalspecParent =====

int serverAllocShareWithHalspecParent(long param_1,long param_2,long *param_3,long param_4)

{
  char cVar1;
  int iVar2;
  long lVar3;
  long local_30;
  
  local_30 = 0;
  if (param_2 == 0) {
    return 0x22;
  }
  iVar2 = __nvoc_objCreateDynamic(&local_30,param_4,param_2,param_4 != 0);
  if (iVar2 == 0) {
    if (local_30 == 0) {
      return 0x1a;
    }
    lVar3 = __nvoc_dynamicCast(local_30,__nvoc_class_def_RsShared);
    if (lVar3 == 0) {
      iVar2 = 0x22;
    }
    else {
      LOCK();
      *(undefined4 *)(lVar3 + 0x48) = 1;
      UNLOCK();
      portSyncSpinlockAcquire(*(undefined8 *)(param_1 + 0x28));
      cVar1 = mapInsertExisting_IMPL(param_1 + 0x30,lVar3,lVar3);
      if (cVar1 == '\x01') {
        portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x28));
        if (param_3 == (long *)0x0) {
          return 0;
        }
        *param_3 = lVar3;
        return 0;
      }
      portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x28));
      iVar2 = 0x1a;
    }
    __nvoc_objDelete(lVar3);
    return iVar2;
  }
  return iVar2;
}


// ===== 00521510 serverAllocShare =====

void serverAllocShare(void)

{
  serverAllocShareWithHalspecParent();
  return;
}


// ===== 00521520 serverGetShareRefCount =====

undefined4 serverGetShareRefCount(undefined8 param_1,long param_2)

{
  return *(undefined4 *)(param_2 + 0x48);
}


// ===== 00521530 serverRefShare =====

undefined8 serverRefShare(undefined8 param_1,long param_2)

{
  LOCK();
  *(int *)(param_2 + 0x48) = *(int *)(param_2 + 0x48) + 1;
  UNLOCK();
  return 0;
}


// ===== 00521540 serverFreeShare =====

undefined8 serverFreeShare(long param_1,long param_2)

{
  int *piVar1;
  
  LOCK();
  piVar1 = (int *)(param_2 + 0x48);
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (*piVar1 != 0) {
    return 0;
  }
  portSyncSpinlockAcquire(*(undefined8 *)(param_1 + 0x28));
  mapRemoveIntrusive_IMPL(param_1 + 0x30,param_2);
  portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x28));
  __nvoc_objDelete(param_2);
  return 0;
}


// ===== 00521590 sessionCheckLocksForRemove_IMPL =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sessionCheckLocksForRemove_IMPL(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  int *piVar5;
  long lVar6;
  
  puVar4 = (undefined8 *)tlsEntryGet(1);
  if (puVar4 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("pCallContext != NULL","src/libraries/resserv/src/rs_server.c",0x1016);
    lVar2 = _DAT_00000020;
  }
  else {
    lVar2 = puVar4[4];
  }
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pLockInfo != NULL","src/libraries/resserv/src/rs_server.c",0x1019);
  }
  if ((*(byte *)(lVar2 + 0x28) & 0x40) != 0) {
    if (param_1 == 0) {
      lVar6 = 0;
      piVar5 = (int *)&DAT_00000048;
    }
    else {
      lVar6 = *(long *)(param_1 + 0x88);
      piVar5 = (int *)(lVar6 + 0x48);
    }
    uVar3 = *(undefined8 *)(param_1 + 0x98);
    iVar1 = *piVar5;
    if (((*(byte *)(lVar2 + 0x2d) & 1) == 0) || (iVar1 != 1)) {
      serverFreeShare(*puVar4,lVar6);
      *(uint *)(lVar2 + 0x28) = *(uint *)(lVar2 + 0x28) & 0xffffffbf;
      if (((*(byte *)(lVar2 + 0x2d) & 1) == 0) && (iVar1 == 1)) {
        portSyncRwLockDestroy(uVar3);
        return;
      }
    }
  }
  return;
}


// ===== 005216b0 sessionRemoveDependant_IMPL =====

void sessionRemoveDependant_IMPL(long param_1,long param_2)

{
  long local_20 [2];
  
  local_20[0] = param_2;
  listRemoveFirstByValue_IMPL(param_1 + 0xd0,local_20);
  sessionCheckLocksForRemove_IMPL(param_1,local_20[0]);
  *(undefined8 *)(local_20[0] + 0x1b8) = 0;
  return;
}


// ===== 00521700 sessionRemoveDependency_IMPL =====

void sessionRemoveDependency_IMPL(long param_1,long param_2)

{
  long local_20 [2];
  
  local_20[0] = param_2;
  listRemoveFirstByValue_IMPL(param_1 + 0xa8,local_20);
  *(undefined1 *)(param_1 + 0xa0) = 0;
  sessionCheckLocksForRemove_IMPL(param_1,local_20[0]);
  *(undefined8 *)(local_20[0] + 0x1c0) = 0;
  return;
}


// ===== 00521750 serverShareIter =====

undefined8 * serverShareIter(undefined8 *param_1,long param_2,undefined4 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined1 local_58 [32];
  undefined4 local_38;
  undefined4 uStack_34;
  undefined8 local_30;
  
  param_2 = param_2 + 0x30;
  portMemSet(local_58,0,0x30);
  local_38 = param_3;
  uVar1 = mapFindLEQ_IMPL(param_2,0xffffffffffffffff);
  uVar2 = mapFindGEQ_IMPL(param_2,0);
  mapIterRange_IMPL(&local_78,param_2,uVar2,uVar1);
  *param_1 = local_78;
  param_1[1] = local_70;
  param_1[2] = local_68;
  param_1[3] = local_60;
  param_1[4] = CONCAT44(uStack_34,local_38);
  param_1[5] = local_30;
  return param_1;
}


// ===== 005217f0 serverShareIterNext =====

undefined8 serverShareIterNext(undefined8 *param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  if (param_1 == (undefined8 *)0x0) {
    return 0;
  }
  param_1[5] = 0;
  uVar1 = mapIterNext_IMPL();
  if ((char)uVar1 != '\0') {
    while ((uVar1 = *param_1, *(int *)(param_1 + 4) != 0 &&
           (lVar2 = objDynamicCastById_IMPL(uVar1), lVar2 == 0))) {
      uVar1 = mapIterNext_IMPL(param_1);
      if ((char)uVar1 == '\0') {
        return uVar1;
      }
    }
    param_1[5] = uVar1;
    uVar1 = 1;
  }
  return uVar1;
}


// ===== 00521880 serverSessionLock_Prologue =====

undefined8 serverSessionLock_Prologue(int param_1,long param_2,long param_3,uint *param_4)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  
  lVar1 = *(long *)(param_2 + 0x1b8);
  lVar2 = *(long *)(param_2 + 0x1c0);
  if ((*(byte *)(param_3 + 0x2d) & 1) == 0) {
    if (lVar1 == 0) {
      uVar3 = *(uint *)(param_3 + 0x28);
      if (((uVar3 & 0x20) == 0) && (lVar2 != 0)) {
LAB_0052191c:
        portSyncRwLockAcquireWrite(*(undefined8 *)(lVar2 + 0x98));
        *(uint *)(param_3 + 0x2c) = *(uint *)(param_3 + 0x2c) | 0x100;
        *param_4 = *param_4 | 0x20;
        *(long *)(param_3 + 0x20) = lVar2;
        *(uint *)(param_3 + 0x28) = *(uint *)(param_3 + 0x28) & 0xffffffdf;
        return 0;
      }
      goto LAB_0052197d;
    }
    if (param_1 == 0) {
      portSyncRwLockAcquireRead(*(undefined8 *)(lVar1 + 0x98));
    }
    else {
      portSyncRwLockAcquireWrite();
    }
    *(uint *)(param_3 + 0x2c) = *(uint *)(param_3 + 0x2c) | 0x100;
    *param_4 = *param_4 | 0x20;
    uVar3 = *(uint *)(param_3 + 0x28);
    *(long *)(param_3 + 0x20) = lVar1;
    if (((uVar3 & 0x20) != 0) || (lVar2 == 0)) goto LAB_0052197d;
    if ((*(byte *)(param_3 + 0x2d) & 1) == 0) goto LAB_0052191c;
  }
  else {
    if (*(long *)(param_3 + 0x20) != lVar1) {
      nvAssertFailedNoLog("pLockInfo->pSession == pSession","src/libraries/resserv/src/rs_server.c",
                          0x1357);
      return 0x2f;
    }
    uVar3 = *(uint *)(param_3 + 0x28);
    if (((uVar3 & 0x20) != 0) || (lVar2 == 0)) goto LAB_0052197d;
  }
  if (lVar1 != lVar2) {
    nvAssertFailedNoLog("pLockInfo->pSession == pDependantSession",
                        "src/libraries/resserv/src/rs_server.c",0x1371);
    return 0x2f;
  }
LAB_0052197d:
  *(uint *)(param_3 + 0x28) = uVar3 & 0xffffffdf;
  return 0;
}


// ===== 00521a10 serverSessionLock_Epilogue =====

void serverSessionLock_Epilogue(undefined8 param_1,int param_2,long param_3,uint *param_4)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_3 + 0x20);
  if ((lVar1 == 0) || ((*param_4 & 0x20) == 0)) {
    *(uint *)(param_3 + 0x28) = *(uint *)(param_3 + 0x28) & 0xffffffbf;
    return;
  }
  if (param_2 == 0) {
    portSyncRwLockReleaseRead(*(undefined8 *)(lVar1 + 0x98));
  }
  else {
    portSyncRwLockReleaseWrite();
  }
  *(uint *)(param_3 + 0x2c) = *(uint *)(param_3 + 0x2c) & 0xfffffeff;
  *param_4 = *param_4 & 0xffffffdf;
  if ((*(uint *)(param_3 + 0x28) & 0x40) == 0) {
    *(undefined8 *)(param_3 + 0x20) = 0;
    *(uint *)(param_3 + 0x28) = *(uint *)(param_3 + 0x28) & 0xffffffbf;
    return;
  }
  uVar2 = *(undefined8 *)(lVar1 + 0x98);
  serverFreeShare(param_1,*(undefined8 *)(lVar1 + 0x88));
  portSyncRwLockDestroy(uVar2);
  *(undefined8 *)(param_3 + 0x20) = 0;
  *(uint *)(param_3 + 0x28) = *(uint *)(param_3 + 0x28) & 0xffffffbf;
  return;
}


// ===== 00521b00 serverFreeResourceTreeUnderLock =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong serverFreeResourceTreeUnderLock(undefined8 param_1,long param_2)

{
  undefined8 *puVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  undefined4 local_2c;
  
  puVar1 = *(undefined8 **)(param_2 + 0x28);
  local_2c = 0;
  lVar2 = *(long *)(param_2 + 0x18);
  if (puVar1 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("pResourceRef != NULL","src/libraries/resserv/src/rs_server.c",0xe4);
    return 0x33;
  }
  uVar5 = serverUpdateLockFlagsForFree();
  if ((int)uVar5 == 0) {
    iVar3 = serverSessionLock_Prologue(1,puVar1,lVar2,&local_2c);
    uVar5 = 0x2f;
    if (iVar3 == 0) {
      if (puVar1[1] == 0) {
        uVar4 = (**(code **)(*(long *)*puVar1 + 0x50))((long *)*puVar1,param_1,param_2);
        if (uVar4 != 0) {
          nvAssertFailedNoLog("status == NV_OK","src/libraries/resserv/src/rs_server.c",0xf6);
        }
      }
      else {
        *(uint *)(lVar2 + 0x28) = *(uint *)(lVar2 + 0x28) | 0x40;
        *(undefined8 **)(lVar2 + 0x18) = puVar1;
        *(undefined1 *)(lVar2 + 0x34) = 4;
        *(undefined4 *)(lVar2 + 0x38) = *(undefined4 *)((long)puVar1 + 0x11c);
        uVar4 = serverResLock_Prologue(param_1,1,lVar2,&local_2c,0);
        if (uVar4 == 0) {
          uVar4 = (**(code **)(*(long *)*puVar1 + 0x50))((long *)*puVar1,param_1,param_2);
          if ((uVar4 & 0xffffffef) != 0) {
            nvAssertFailedNoLog("(status == NV_OK) || (status == NV_ERR_GPU_IN_FULLCHIP_RESET)",
                                "src/libraries/resserv/src/rs_server.c",0x103);
          }
          serverResLock_Epilogue(param_1,1,lVar2,&local_2c);
        }
      }
      serverSessionLock_Epilogue(param_1,1,lVar2,&local_2c);
      return (ulong)uVar4;
    }
  }
  return uVar5;
}


// ===== 00521cc0 serverFreeResourceTree =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint serverFreeResourceTree(long param_1,int *param_2)

{
  long *plVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  long lVar8;
  int iVar9;
  undefined1 uVar10;
  long *plVar11;
  long local_198;
  uint local_18c;
  uint local_188;
  long local_178;
  undefined8 local_170;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 local_148;
  int *local_140;
  undefined8 local_138;
  char local_119;
  undefined4 local_118;
  int local_114;
  long local_110;
  long local_108;
  long local_100;
  long local_f8;
  long local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  int *local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  long *local_a0;
  int *local_98;
  long local_88;
  long local_80;
  undefined8 local_70;
  
  iVar7 = param_2[4];
  local_110 = 0;
  local_108 = 0;
  local_118 = 0;
  if (*(char *)(param_1 + 0x14) == '\0') {
    return 0x55;
  }
  lVar2 = *(long *)(param_2 + 6);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pLockInfo != NULL","src/libraries/resserv/src/rs_server.c",0x4b0);
    return 0x1f;
  }
  local_18c = *(uint *)(lVar2 + 0x2c);
  portMemSet(&local_100,0,0x10);
  param_2[10] = 0;
  param_2[0xb] = 0;
  local_188 = serverFreeResourceLookupLockFlags(param_1,1,param_2,&local_114,&local_119);
  if (local_188 != 0) goto LAB_00521e84;
  iVar9 = 0;
  if (local_119 == '\0') {
    iVar9 = local_114;
  }
  local_188 = serverFreeResourceTreeLockAndFindResource_constprop_0
                        (param_1,param_2,iVar9,&local_118,&local_110,&local_108);
  lVar4 = local_110;
  local_198 = local_110;
  uVar6 = local_188;
  if ((local_188 == 0) && (local_108 != 0)) {
    if (local_114 != iVar9) {
      *(long *)(param_2 + 10) = local_108;
      uVar6 = serverFreeResourceLookupLockFlags(param_1,1,param_2,&local_114,&local_119);
      if (uVar6 != 0) goto LAB_00521e66;
      if (local_114 != iVar9) {
        param_2[10] = 0;
        param_2[0xb] = 0;
        _serverUnlockClientWithLockInfo_constprop_0(param_1,lVar4,lVar2,&local_118);
        local_110 = 0;
        serverTopLock_Epilogue(param_1,iVar9,lVar2,&local_118);
        uVar6 = serverFreeResourceTreeLockAndFindResource_constprop_0
                          (param_1,param_2,local_114,&local_118,&local_110,&local_108);
        local_198 = local_110;
        if ((uVar6 != 0) || (local_108 == 0)) goto LAB_00521e66;
      }
    }
    local_198 = local_110;
    plVar3 = *(long **)(local_110 + 8);
    if (plVar3[0x1b] != 0) {
      local_100 = plVar3[0x1b];
    }
    lVar4 = local_100;
    plVar3[0x1b] = (long)&local_100;
    *(long *)(param_2 + 10) = local_108;
    local_f8 = local_108;
    if (*(char *)((long)param_2 + 0x11) == '\0') {
      if (((char)param_2[2] == '\0') || (*(char *)(local_108 + 0x124) == '\0')) {
        clientUpdatePendingFreeList_IMPL(plVar3,local_108,local_108,local_100 != 0);
        (**(code **)(*plVar3 + 0x80))(plVar3,&local_f0);
        plVar1 = plVar3 + 0x18;
        if (*(char *)(param_1 + 0x40) != '\0') {
          nvDbg_Printf("src/libraries/resserv/src/rs_server.c",0x528,"serverFreeResourceTree",1,
                       "NVRM: PENDING FREE LIST START (0x%x)\n",(int)plVar3[9]);
          nvDbg_Printf("src/libraries/resserv/src/rs_server.c",0x529,"serverFreeResourceTree",1,
                       "NVRM:   _HI_PRIORITY_:\n");
          for (lVar8 = listHead_IMPL(plVar1); lVar8 != 0; lVar8 = listNext_IMPL(plVar1,lVar8)) {
            if (local_f0 == lVar8) {
              nvDbg_Printf("src/libraries/resserv/src/rs_server.c",0x52e,"serverFreeResourceTree",1,
                           "NVRM:   _LO_PRIORITY_:\n");
            }
            nvDbg_Printf("src/libraries/resserv/src/rs_server.c",0x530,"serverFreeResourceTree",1,
                         "NVRM:   0x%08x [%04x]\n",*(undefined4 *)(lVar8 + 0x10),
                         *(undefined4 *)(lVar8 + 0x11c));
          }
          nvDbg_Printf("src/libraries/resserv/src/rs_server.c",0x535,"serverFreeResourceTree",1,
                       "NVRM: PENDING FREE LIST END (0x%x)\n",(int)plVar3[9]);
        }
        while (lVar8 = listHead_IMPL(plVar1), lVar8 != 0) {
          if (((char)iVar7 != '\0') && (local_f0 == lVar8)) goto LAB_00521e42;
          iVar9 = *(int *)(lVar8 + 0x10);
          if (*(char *)(param_1 + 0x40) != '\0') {
            nvDbg_Printf("src/libraries/resserv/src/rs_server.c",0x544,"serverFreeResourceTree",1,
                         "NVRM: (%08x, %08x)\n",(int)plVar3[9],iVar9);
          }
          if (param_2[1] == iVar9) {
            iVar7 = listCount_IMPL(plVar1);
            if ((iVar7 != 1) && (lVar4 == 0)) {
              nvAssertFailedNoLog("(listCount(&pClient->pendingFreeList) == 1) || bRecursive",
                                  "src/libraries/resserv/src/rs_server.c",0x54a);
            }
            local_188 = serverFreeResourceTreeUnderLock(param_1,param_2);
            break;
          }
          plVar11 = &local_100;
          do {
            cVar5 = refHasAncestor(lVar8,plVar11[1]);
            if (cVar5 != '\0') {
              uVar10 = (undefined1)param_2[2];
              goto LAB_00522012;
            }
            plVar11 = (long *)*plVar11;
          } while (plVar11 != (long *)0x0);
          uVar10 = 1;
LAB_00522012:
          serverInitFreeParams_Recursive((int)plVar3[9],iVar9,lVar2,&local_a8);
          local_70 = *(undefined8 *)(param_2 + 0xe);
          local_a0 = (long *)CONCAT71(local_a0._1_7_,uVar10);
          local_80 = lVar8;
          local_188 = serverFreeResourceTreeUnderLock(param_1,&local_a8);
          if ((local_188 & 0xffffffef) != 0) {
            nvAssertFailedNoLog("(status == NV_OK) || (status == NV_ERR_GPU_IN_FULLCHIP_RESET)",
                                "src/libraries/resserv/src/rs_server.c",0x55f);
          }
          if (*(char *)(param_1 + 0x40) != '\0') {
            nvDbg_Printf("src/libraries/resserv/src/rs_server.c",0x563,"serverFreeResourceTree",1,
                         "NVRM: (%08x, %08x) status=0x%x\n",(int)plVar3[9],iVar9,local_188);
          }
        }
        plVar3[0x1b] = local_100;
        if (*param_2 == param_2[1]) {
          *(undefined1 *)(plVar3 + 10) = 0;
        }
        _serverUnlockClientWithLockInfo_constprop_0(param_1,local_198,lVar2,&local_118);
        iVar7 = local_114;
        if (*param_2 == param_2[1]) {
          portMemSet(&local_a8,0,0x20);
          local_a8 = CONCAT44(*param_2,(undefined4)local_a8);
          local_98 = param_2;
          if (iVar7 == 1) {
            _serverFreeClient_isra_0(param_1,&local_a8);
          }
          else {
            serverTopLock_Epilogue(param_1,local_114,lVar2,&local_118);
            local_188 = serverTopLock_Prologue(param_1,1,lVar2,&local_118);
            if (local_188 != 0) {
              nvCheckOkFailedNoLog
                        (1,local_188,
                         "serverTopLock_Prologue(pServer, LOCK_ACCESS_WRITE, pLockInfo, &releaseFlags)"
                         ,"src/libraries/resserv/src/rs_server.c",0x585);
            }
            _serverFreeClient_isra_0(param_1,&local_a8);
            serverTopLock_Epilogue(param_1,1,lVar2,&local_118);
            local_18c = local_18c & 0xffffff7f;
          }
        }
        goto LAB_00521e84;
      }
LAB_005221e3:
      local_188 = 0;
    }
    else {
      local_188 = 0x40;
      if (*(char *)((long)plVar3 + 0x52) == '\0') {
        *(undefined1 *)((long)plVar3 + 0x52) = 1;
        portSyncSpinlockAcquire(*(undefined8 *)(param_1 + 0xe0));
        listAppendExisting_IMPL(param_1 + 0xc0,plVar3);
        portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0xe0));
        *(undefined1 *)(plVar3 + 10) = 0;
        portMemSet(&local_a8,0,0x70);
        local_a8 = param_1;
        local_a0 = plVar3;
        local_88 = lVar2;
        clientRefIter(&local_178,plVar3,0,0,1,1);
        local_f0 = local_178;
        local_e8 = local_170;
        local_e0 = local_168;
        local_d8 = local_160;
        local_d0 = local_158;
        local_c8 = local_150;
        local_c0 = local_148;
        local_b8 = local_140;
        local_b0 = local_138;
        while (cVar5 = clientRefIterNext(plVar3,&local_f0), cVar5 != '\0') {
          local_98 = local_b8;
          clientUnmapResourceRefMappings(plVar3,&local_a8,lVar2);
        }
        goto LAB_005221e3;
      }
    }
LAB_00521e42:
    plVar3[0x1b] = local_100;
    uVar6 = local_188;
  }
LAB_00521e66:
  local_188 = uVar6;
  if (local_198 != 0) {
    _serverUnlockClientWithLockInfo_constprop_0(param_1,local_198,lVar2,&local_118);
  }
LAB_00521e84:
  serverTopLock_Epilogue(param_1,local_114,lVar2,&local_118);
  if ((*(uint *)(lVar2 + 0x2c) != local_18c) && (*(uint *)(lVar2 + 0x2c) != (local_18c | 0x40))) {
    nvAssertFailedNoLog("(pLockInfo->state == initialLockState) || (pLockInfo->state == (initialLockState | RS_LOCK_STATE_ALLOW_RECURSIVE_RES_LOCK))"
                        ,"src/libraries/resserv/src/rs_server.c",0x5a6);
  }
  return local_188;
}


// ===== 00522670 serverDestruct =====

undefined8 serverDestruct(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  long local_98 [8];
  undefined1 local_58 [64];
  
  portMemSet(local_98,0,0x40);
  uVar1 = 0x31;
  if (*(char *)(param_1 + 0x14) != '\0') {
    lVar3 = 0;
    do {
      while( true ) {
        lVar2 = listHead_IMPL(*(long *)(param_1 + 8) + lVar3);
        if (lVar2 == 0) break;
        local_98[0] = *(long *)(lVar2 + 8);
        serverInitFreeParams_Recursive
                  (*(undefined4 *)(local_98[0] + 0x48),*(undefined4 *)(local_98[0] + 0x48),local_98,
                   local_58);
        serverFreeResourceTree(param_1,local_58);
      }
      lVar2 = *(long *)(param_1 + 8) + lVar3;
      lVar3 = lVar3 + 0x18;
      listDestroyIntrusive_IMPL(lVar2);
    } while (lVar3 != 0x6000);
    listDestroyIntrusive_IMPL(param_1 + 0xc0);
    portSyncSpinlockDestroy(*(undefined8 *)(param_1 + 0xe0));
    _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 8));
    mapDestroyIntrusive_IMPL(param_1 + 0x30);
    listDestroy_IMPL(param_1 + 0x58);
    listDestroy_IMPL(param_1 + 0x80);
    portSyncSpinlockDestroy(*(undefined8 *)(param_1 + 0x28));
    portSyncSpinlockDestroy(*(undefined8 *)(param_1 + 0x20));
    portMemAllocatorRelease(*(undefined8 *)(param_1 + 0x18));
    *(undefined1 *)(param_1 + 0x14) = 0;
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00522780 serverFreeDisabledClients =====

undefined1  [16] serverFreeDisabledClients(long param_1,undefined4 param_2,int param_3)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  bool bVar6;
  undefined1 auVar7 [16];
  undefined8 local_d8 [4];
  undefined8 local_b8 [2];
  undefined1 local_a8;
  undefined1 *local_a0;
  undefined8 *local_80;
  undefined1 local_78 [44];
  undefined4 local_4c;
  
  uVar5 = 1;
  LOCK();
  bVar6 = inProgress_4 == 0;
  if (bVar6) {
    inProgress_4 = 1;
  }
  UNLOCK();
  if (bVar6) {
    portMemSet(local_b8,0,0x40);
    portMemSet(local_d8,0,0x20);
    portMemSet(local_78,0,0x40);
    lVar1 = param_1 + 0xc0;
    local_d8[0] = 0x100000002;
    local_a0 = local_78;
    local_80 = local_d8;
    local_4c = param_2;
    do {
      portSyncSpinlockAcquire(*(undefined8 *)(param_1 + 0xe0));
      lVar3 = *(long *)(param_1 + 0xd8);
      if ((lVar3 == 0) && (lVar3 = listHead_IMPL(lVar1), lVar3 == 0)) {
        uVar4 = listHead_IMPL(lVar1);
        *(undefined8 *)(param_1 + 0xd8) = uVar4;
        portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0xe0));
        uVar4 = 0;
        goto LAB_005228e7;
      }
      uVar4 = listNext_IMPL(lVar1,lVar3);
      *(undefined8 *)(param_1 + 0xd8) = uVar4;
      portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0xe0));
      if (*(char *)(lVar3 + 0x52) == '\0') {
        nvAssertFailedNoLog("pClient->bDisabled","src/libraries/resserv/src/rs_server.c",0x439);
      }
      local_b8[0] = CONCAT44(*(undefined4 *)(lVar3 + 0x48),*(undefined4 *)(lVar3 + 0x48));
      local_a8 = *(char *)(lVar3 + 0x53) == '\0';
      if ((bool)local_a8) {
        *(undefined1 *)(lVar3 + 0x53) = 1;
      }
      serverFreeResourceTree(param_1,local_b8);
      param_3 = param_3 + -1;
    } while (param_3 != 0);
    uVar4 = 0x10005;
LAB_005228e7:
    uVar2 = inProgress_4;
    LOCK();
    inProgress_4 = 0;
    uVar5 = (ulong)uVar2;
    UNLOCK();
  }
  else {
    uVar4 = 0x17;
  }
  auVar7._8_8_ = uVar5;
  auVar7._0_8_ = uVar4;
  return auVar7;
}


// ===== 00522940 serverFreeClient =====

void serverFreeClient(undefined8 param_1,long param_2)

{
  undefined8 local_a8 [2];
  undefined2 local_98;
  undefined1 *local_90;
  undefined8 local_70;
  undefined1 local_68 [40];
  undefined4 local_40;
  undefined4 local_3c;
  
  portMemSet(local_68,0,0x40);
  portMemSet(local_a8,0,0x40);
  local_3c = *(undefined4 *)(param_2 + 0xc);
  local_40 = 0x80;
  local_a8[0] = CONCAT44(*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 4));
  local_98 = *(undefined2 *)(param_2 + 8);
  local_70 = *(undefined8 *)(param_2 + 0x18);
  local_90 = local_68;
  serverFreeResourceTree(param_1,local_a8);
  return;
}


// ===== 005229e0 serverFreeDomain =====

undefined8 serverFreeDomain(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  undefined1 local_48 [4];
  undefined4 local_44;
  
  lVar3 = 0;
  do {
    lVar1 = *(long *)(param_1 + 8);
    while( true ) {
      lVar2 = listHead_IMPL(lVar1 + lVar3);
      if (lVar2 == 0) break;
      portMemSet(local_48,0,0x20);
      local_44 = *(undefined4 *)(lVar2 + 0x10);
      serverFreeClient(param_1);
    }
    lVar3 = lVar3 + 0x18;
  } while (lVar3 != 0x6000);
  return 0;
}


// ===== 00522a60 serverMarkClientListDisabled =====

undefined8
serverMarkClientListDisabled
          (undefined8 param_1,int *param_2,uint param_3,undefined4 param_4,undefined8 param_5)

{
  int *piVar1;
  int iVar2;
  undefined1 local_58 [4];
  int local_54;
  undefined1 local_4f;
  undefined4 local_4c;
  undefined8 local_40;
  
  if (param_3 != 0) {
    piVar1 = param_2 + param_3;
    do {
      portMemSet(local_58,0,0x20);
      if (*param_2 != 0) {
        local_4f = 1;
        local_54 = *param_2;
        local_4c = param_4;
        local_40 = param_5;
        iVar2 = serverFreeClient(param_1);
        if (iVar2 != 0) {
          nvAssertOkFailedNoLog
                    (iVar2,"serverFreeClient(pServer, &params)",
                     "src/libraries/resserv/src/rs_server.c",0x3fb);
        }
      }
      param_2 = param_2 + 1;
    } while (param_2 != piVar1);
    return 0;
  }
  return 0;
}


// ===== 00522b10 serverControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int serverControl(long param_1,int *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long *plVar7;
  long *extraout_RDX;
  long *extraout_RDX_00;
  long *plVar8;
  bool bVar9;
  uint local_d0;
  undefined4 local_cc;
  int local_c8;
  int local_c4;
  long local_c0;
  long local_b8;
  long local_b0;
  long local_a8;
  long *local_a0;
  long local_98;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  int *local_60;
  
  lVar1 = *(long *)(param_2 + 0x16);
  local_c0 = 0;
  local_b8 = 0;
  local_b0 = 0;
  local_d0 = 0;
  local_cc = 1;
  local_c8 = 0;
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pLockInfo != NULL","src/libraries/resserv/src/rs_server.c",0x5c1);
    return 0x1f;
  }
  iVar4 = serverControlLookupLockFlags(param_1,1,param_2,*(undefined8 *)(param_2 + 0x18),&local_cc);
  if ((iVar4 != 0) ||
     ((*(char *)(param_1 + 0x41) != '\0' &&
      (iVar4 = serverControlApiCopyIn(param_1,param_2,*(undefined8 *)(param_2 + 0x18)), iVar4 != 0))
     )) goto LAB_00522ca0;
  iVar4 = serverTopLock_Prologue(param_1,local_cc,lVar1,&local_d0);
  if ((iVar4 != 0) ||
     (iVar4 = serverControlLookupClientLockFlags(*(undefined8 *)(param_2 + 0x18),&local_c8),
     iVar4 != 0)) goto LAB_00522ca0;
  if (local_c8 == 0) {
    iVar4 = serverControlLookupSecondClient
                      (param_2[2],*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 0x18),
                       &local_c4);
    if (iVar4 != 0) goto LAB_00522ca0;
    bVar9 = (*(byte *)(param_2 + 3) & 3) == 0;
    if (local_c4 == 0) {
      iVar4 = _serverLockClientWithLockInfo_constprop_0
                        (param_1,*param_2,bVar9,lVar1,&local_d0,&local_c0);
      if (iVar4 != 0) goto LAB_00522ca0;
      plVar8 = *(long **)(local_c0 + 8);
      cVar3 = (char)plVar8[10];
      plVar7 = extraout_RDX_00;
joined_r0x00523062:
      if (cVar3 != '\0') goto LAB_00522e1e;
    }
    else {
      plVar7 = &local_c0;
      iVar4 = _serverLockDualClientWithLockInfo_constprop_0
                        (param_1,*param_2,local_c4,bVar9,lVar1,&local_d0,plVar7,&local_b8);
      if (iVar4 != 0) goto LAB_00522ca0;
      plVar8 = *(long **)(local_c0 + 8);
      if ((char)plVar8[10] != '\0') {
        cVar3 = *(char *)(*(long *)(local_b8 + 8) + 0x50);
        goto joined_r0x00523062;
      }
    }
LAB_00522c91:
    iVar4 = 0x40;
  }
  else {
    lVar2 = *(long *)(param_1 + 0x48);
    lVar6 = portThreadGetCurrentThreadId();
    if (lVar2 != lVar6) {
      iVar4 = 0x51;
      iVar5 = serverLockAllClients(param_1);
      if (iVar5 != 0) goto LAB_00522ca0;
      local_d0 = local_d0 | 2;
    }
    cVar3 = __serverFindClientEntryByHandle(param_1,*param_2,2,1,0,&local_a8);
    if (cVar3 != '\x01') {
      iVar4 = 0x33;
      goto LAB_00522ca0;
    }
    plVar8 = *(long **)(local_a8 + 8);
    plVar7 = extraout_RDX;
LAB_00522e1e:
    iVar4 = (**(code **)(*plVar8 + 0x30))(plVar8,param_2 + 0xe,plVar7);
    if ((iVar4 != 0) || (iVar4 = clientGetResourceRef_IMPL(plVar8,param_2[1],&local_b0), iVar4 != 0)
       ) goto LAB_00522ca0;
    *(long *)(param_2 + 0xc) = local_b0;
    if ((*(char *)(local_b0 + 0x124) == '\0') && (*(long *)(local_b0 + 8) != 0)) {
      *(uint *)(lVar1 + 0x28) = *(uint *)(lVar1 + 0x28) | 0x20;
      iVar4 = 0x2f;
      iVar5 = serverSessionLock_Prologue(1,local_b0,lVar1,&local_d0);
      if (iVar5 != 0) goto LAB_00522ca0;
      if ((*(long *)(local_b0 + 0x1b8) == 0) ||
         (*(char *)(*(long *)(local_b0 + 0x1b8) + 0xa0) != '\0')) {
        portMemSet(&local_a8,0,0x70);
        local_80 = *(undefined8 *)(param_2 + 0xe);
        local_78 = *(undefined8 *)(param_2 + 0x10);
        local_98 = local_b0;
        local_70 = *(undefined8 *)(param_2 + 0x12);
        local_68 = *(undefined8 *)(param_2 + 0x14);
        *(int **)(param_2 + 0x1c) = param_2;
        local_88 = *(undefined8 *)(param_2 + 0x16);
        iVar4 = param_2[1];
        if (*param_2 != iVar4) {
          iVar4 = *(int *)(*(long *)(local_b0 + 0x18) + 0x10);
        }
        param_2[7] = iVar4;
        *(undefined8 *)(lVar1 + 0x10) = *(undefined8 *)(local_b0 + 0x18);
        local_a8 = param_1;
        local_a0 = plVar8;
        local_60 = param_2;
        plVar7 = (long *)tlsEntryAcquire(1);
        if (plVar7 != (long *)0x0) {
          lVar2 = *plVar7;
          *plVar7 = (long)&local_a8;
          if (((lVar2 != 0) && (local_60 != (int *)0x0)) && (*(long *)(lVar2 + 0x48) != 0)) {
            *(byte *)((long)local_60 + 0x69) =
                 *(byte *)((long)local_60 + 0x69) | *(byte *)(*(long *)(lVar2 + 0x48) + 0x69);
          }
          iVar4 = (**(code **)(**(long **)(local_b0 + 8) + 0x48))
                            (*(long **)(local_b0 + 8),&local_a8,param_2);
          plVar7 = (long *)tlsEntryAcquire(1);
          if (plVar7 == (long *)0x0) {
            nvAssertOkFailedNoLog
                      (0x1f,"resservRestoreTlsCallContext(pOldContext)",
                       "src/libraries/resserv/src/rs_server.c",0x643);
          }
          else {
            *plVar7 = lVar2;
            tlsEntryRelease(1);
            tlsEntryRelease(1);
          }
          goto LAB_00522ca0;
        }
        nvAssertOkFailedNoLog
                  (0x40,"resservSwapTlsCallContext(&pOldContext, &callContext)",
                   "src/libraries/resserv/src/rs_server.c",0x63f);
        goto LAB_00522c91;
      }
    }
    iVar4 = 0x6e;
  }
LAB_00522ca0:
  serverSessionLock_Epilogue(param_1,1,lVar1,&local_d0);
  if (local_c8 == 0) {
    if (local_c0 != 0) {
      if (local_b8 == 0) {
        _serverUnlockClientWithLockInfo_constprop_0(param_1,local_c0,lVar1,&local_d0);
      }
      else {
        _serverUnlockDualClientWithLockInfo_constprop_0(param_1,local_c0,local_b8,lVar1,&local_d0);
      }
    }
  }
  else if (((local_d0 & 2) != 0) && (iVar5 = serverUnlockAllClients(param_1), iVar5 == 0)) {
    local_d0 = local_d0 & 0xfffffffd;
  }
  serverTopLock_Epilogue(param_1,local_cc,lVar1,&local_d0);
  if (*(char *)(param_1 + 0x41) == '\0') {
    return iVar4;
  }
  iVar4 = serverControlApiCopyOut(param_1,param_2,*(undefined8 *)(param_2 + 0x18),iVar4);
  return iVar4;
}


// ===== 005230d0 serverControl_Prologue =====

void serverControl_Prologue(long param_1,long param_2,undefined4 *param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x58);
  iVar2 = serverControl_ValidateCookie(param_2,*(undefined8 *)(param_2 + 0x60));
  if ((iVar2 != 0) ||
     (iVar2 = serverControlLookupLockFlags
                        (param_1,2,param_2,*(undefined8 *)(param_2 + 0x60),param_3), iVar2 != 0)) {
    return;
  }
  if ((*(char *)(param_1 + 0x41) == '\0') &&
     (iVar2 = serverControlApiCopyIn(param_1,param_2,*(undefined8 *)(param_2 + 0x60)), iVar2 != 0))
  {
    return;
  }
  *(undefined1 *)(lVar1 + 0x34) = 5;
  *(undefined4 *)(lVar1 + 0x38) = *(undefined4 *)(param_2 + 8);
  serverResLock_Prologue(param_1,*param_3,*(undefined8 *)(param_2 + 0x58),param_4,0);
  return;
}


// ===== 00523180 serverControl_Epilogue =====

ulong serverControl_Epilogue
                (long param_1,long param_2,undefined4 param_3,undefined8 param_4,uint param_5)

{
  ulong uVar1;
  
  serverResLock_Epilogue(param_1,param_3,*(undefined8 *)(param_2 + 0x58));
  if (*(char *)(param_1 + 0x41) != '\0') {
    return (ulong)param_5;
  }
  uVar1 = serverControlApiCopyOut(param_1,param_2,*(undefined8 *)(param_2 + 0x60),param_5);
  return uVar1;
}


// ===== 005231e0 serverSupportsReadOnlyLock =====

bool serverSupportsReadOnlyLock(long param_1,int param_2,uint param_3)

{
  bool bVar1;
  
  if (9 < param_3) {
    nvAssertFailedNoLog("api < RS_API_MAX","src/libraries/resserv/src/rs_server.c",0x13dd);
    bVar1 = false;
    if (param_2 == 1) {
      bVar1 = (*(uint *)(param_1 + 0x50) & 1 << ((byte)param_3 & 0x1f)) != 0;
    }
    return bVar1;
  }
  if (param_2 != 1) {
    return false;
  }
  return (*(uint *)(param_1 + 0x50) & 1 << ((byte)param_3 & 0x1f)) != 0;
}


// ===== 00523260 _tlsThreadEntryGet =====

undefined8 _tlsThreadEntryGet(void)

{
  char cVar1;
  undefined8 uVar2;
  undefined1 local_20 [16];
  
  cVar1 = portUtilIsInterruptContext();
  if (cVar1 != '\0') {
    portSyncSpinlockAcquire(DAT_0056edc8);
    uVar2 = mapFindGEQ_IMPL(&DAT_0056edd0,local_20);
    portSyncSpinlockRelease(DAT_0056edc8);
    return uVar2;
  }
  uVar2 = portThreadGetCurrentThreadId();
  portSyncSpinlockAcquire(DAT_0056edb0);
  uVar2 = mapFind_IMPL(&DAT_0056edb8,uVar2);
  portSyncSpinlockRelease(DAT_0056edb0);
  return uVar2;
}


// ===== 005232f0 _tlsEntryRelease =====

int _tlsEntryRelease(long param_1,int *param_2,long param_3)

{
  char cVar1;
  long *plVar2;
  int iVar3;
  
  if (param_3 != 0) goto LAB_00523304;
  cVar1 = portUtilIsInterruptContext();
  if (cVar1 == '\0') {
    param_3 = *(long *)(param_1 + 0x48);
LAB_00523379:
    if (param_3 != 0) goto LAB_00523304;
  }
  else {
    cVar1 = portUtilIsInterruptContext();
    if (cVar1 != '\0') {
      plVar2 = (long *)_tlsThreadEntryGet();
      param_3 = *plVar2;
      goto LAB_00523379;
    }
  }
  param_3 = tlsDatabase;
LAB_00523304:
  iVar3 = *param_2 + -1;
  *param_2 = iVar3;
  if (iVar3 != 0) {
    return iVar3;
  }
  mapRemoveIntrusive_IMPL();
  _portMemAllocatorFree(param_3,param_2);
  cVar1 = portUtilIsInterruptContext();
  if ((cVar1 == '\0') && (iVar3 = mapCount_IMPL(param_1 + 8), iVar3 == 0)) {
    cVar1 = portMemExSafeForNonPagedAlloc();
    if (cVar1 == '\0') {
      nvAssertFailedNoLog("portMemExSafeForNonPagedAlloc()","src/libraries/tls/tls.c",0x27e);
    }
    portMemAllocatorRelease(*(undefined8 *)(param_1 + 0x48));
    _portMemAllocatorFree(tlsDatabase,*(undefined8 *)(param_1 + 0x40));
    mapDestroyIntrusive_IMPL(param_1 + 8);
    portSyncSpinlockAcquire(DAT_0056edb0);
    mapRemoveIntrusive_IMPL(&DAT_0056edb8,param_1);
    portSyncSpinlockRelease(DAT_0056edb0);
    _portMemAllocatorFree(tlsDatabase,param_1);
    return 0;
  }
  return 0;
}


// ===== 00523470 _tlsThreadEntryGetOrAlloc.part.0 =====

undefined8 * _tlsThreadEntryGetOrAlloc_part_0(void)

{
  char cVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  long lVar4;
  
  cVar1 = portMemExSafeForNonPagedAlloc();
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("portMemExSafeForNonPagedAlloc()","src/libraries/tls/tls.c",0x234);
  }
  puVar2 = (undefined8 *)_portMemAllocatorAlloc(tlsDatabase,0x50);
  if (puVar2 == (undefined8 *)0x0) {
    return (undefined8 *)0x0;
  }
  uVar3 = portThreadGetCurrentThreadId();
  *puVar2 = uVar3;
  lVar4 = _portMemAllocatorAlloc(tlsDatabase,0x3d0);
  puVar2[8] = lVar4;
  if (lVar4 != 0) {
    lVar4 = portMemAllocatorCreateOnExistingBlock(lVar4,0x3d0);
    puVar2[9] = lVar4;
    if (lVar4 != 0) {
      mapInitIntrusive_IMPL(puVar2 + 1,0x10);
      portSyncSpinlockAcquire(DAT_0056edb0);
      mapInsertExisting_IMPL(&DAT_0056edb8,*puVar2,puVar2);
      portSyncSpinlockRelease(DAT_0056edb0);
      return puVar2;
    }
    _portMemAllocatorFree(tlsDatabase,puVar2[8]);
    puVar2[8] = 0;
  }
  _portMemAllocatorFree(tlsDatabase,puVar2);
  return (undefined8 *)0x0;
}


// ===== 00523580 _tlsEntryAcquire =====

int * _tlsEntryAcquire(long param_1,undefined8 param_2,long param_3)

{
  char cVar1;
  int *piVar2;
  long *plVar3;
  
  if (param_3 != 0) goto LAB_0052359b;
  cVar1 = portUtilIsInterruptContext();
  if (cVar1 == '\0') {
    param_3 = *(long *)(param_1 + 0x48);
LAB_005235dd:
    if (param_3 != 0) goto LAB_0052359b;
  }
  else {
    cVar1 = portUtilIsInterruptContext();
    if (cVar1 != '\0') {
      plVar3 = (long *)_tlsThreadEntryGet();
      param_3 = *plVar3;
      goto LAB_005235dd;
    }
  }
  param_3 = tlsDatabase;
LAB_0052359b:
  piVar2 = (int *)mapFind_IMPL(param_1 + 8,param_2);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)_portMemAllocatorAlloc(param_3,0x38);
    if (piVar2 == (int *)0x0) {
      nvAssertFailedNoLog("pTlsEntry != NULL","src/libraries/tls/tls.c",0x25f);
      return (int *)0x0;
    }
    mapInsertExisting_IMPL(param_1 + 8,param_2,piVar2);
    *piVar2 = 1;
    piVar2[2] = 0;
    piVar2[3] = 0;
  }
  else {
    *piVar2 = *piVar2 + 1;
  }
  return piVar2 + 2;
}


// ===== 00523670 tlsShutdown =====

void tlsShutdown(void)

{
  LOCK();
  DAT_0056ede0 = DAT_0056ede0 + -1;
  UNLOCK();
  if (DAT_0056ede0 != 0) {
    return;
  }
  mapDestroyIntrusive_IMPL(&DAT_0056edb8);
  if (DAT_0056edb0 != 0) {
    portSyncSpinlockDestroy();
  }
  if (DAT_0056edc8 != 0) {
    portSyncSpinlockDestroy();
  }
  mapDestroyIntrusive_IMPL(&DAT_0056edd0);
  if (tlsDatabase != 0) {
    portMemAllocatorRelease();
  }
  portMemSet(&tlsDatabase,0,0x48);
  portShutdown();
  return;
}


// ===== 005236f0 tlsInitialize =====

int tlsInitialize(void)

{
  int iVar1;
  
  iVar1 = DAT_0056ede0;
  LOCK();
  DAT_0056ede0 = DAT_0056ede0 + 1;
  UNLOCK();
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = portInitialize();
  if (iVar1 == 0) {
    tlsDatabase = portMemAllocatorCreateNonPaged();
    if (tlsDatabase == 0) {
      iVar1 = 0x51;
    }
    else {
      DAT_0056edb0 = portSyncSpinlockCreate(tlsDatabase);
      if (DAT_0056edb0 != 0) {
        mapInitIntrusive_IMPL(&DAT_0056edb8,0x18);
        DAT_0056edc8 = portSyncSpinlockCreate(tlsDatabase);
        if (DAT_0056edb0 != 0) {
          mapInitIntrusive_IMPL(&DAT_0056edd0,0x18);
          LOCK();
          UNLOCK();
          DAT_0056eda8 = 6;
          return 0;
        }
      }
      iVar1 = 0x1a;
    }
    tlsShutdown();
    return iVar1;
  }
  return iVar1;
}


// ===== 005237d0 tlsIsrInit =====

void tlsIsrInit(undefined8 param_1)

{
  char cVar1;
  undefined8 *puVar2;
  undefined8 unaff_retaddr;
  
  if (DAT_0056ede0 == 0) {
    nvAssertFailedNoLog("tlsDatabase.initCount > 0","src/libraries/tls/tls.c",0x115);
    return;
  }
  cVar1 = portUtilIsInterruptContext();
  if (cVar1 == '\0') {
    if (bAlreadyPrinted_1 != '\0') {
      return;
    }
    nvDbg_Printf("src/libraries/tls/tls.c",0x121,"tlsIsrInit",3,
                 "NVRM: TLS: Unnecessary tlsIsrInit() call at %p. Will stop reporting further violations.\n"
                 ,unaff_retaddr);
    bAlreadyPrinted_1 = 1;
    return;
  }
  puVar2 = (undefined8 *)_portMemAllocatorAlloc(param_1,0x50);
  if (puVar2 != (undefined8 *)0x0) {
    *puVar2 = param_1;
    puVar2[9] = 0;
    mapInitIntrusive_IMPL(puVar2 + 1,0x10);
    portSyncSpinlockAcquire(DAT_0056edc8);
    mapInsertExisting_IMPL(&DAT_0056edd0,*puVar2,puVar2);
    portSyncSpinlockRelease(DAT_0056edc8);
    return;
  }
  nvAssertFailedNoLog("pThreadEntry != NULL","src/libraries/tls/tls.c",0x12d);
  return;
}


// ===== 005238f0 tlsIsrDestroy =====

void tlsIsrDestroy(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  
  if (DAT_0056ede0 == 0) {
    nvAssertFailedNoLog("tlsDatabase.initCount > 0","src/libraries/tls/tls.c",0x142);
    return;
  }
  cVar1 = portUtilIsInterruptContext();
  if (cVar1 == '\0') {
    return;
  }
  portSyncSpinlockAcquire(DAT_0056edc8);
  lVar2 = mapFind_IMPL(&DAT_0056edd0,param_1);
  mapRemoveIntrusive_IMPL(&DAT_0056edd0,lVar2);
  portSyncSpinlockRelease(DAT_0056edc8);
  mapDestroyIntrusive_IMPL(lVar2 + 8);
  _portMemAllocatorFree(param_1,lVar2);
  return;
}


// ===== 005239a0 tlsEntryAlloc =====

long tlsEntryAlloc(void)

{
  long lVar1;
  
  lVar1 = DAT_0056eda8;
  if (DAT_0056ede0 != 0) {
    LOCK();
    DAT_0056eda8 = DAT_0056eda8 + 1;
    UNLOCK();
    return lVar1 + 1;
  }
  nvAssertFailedNoLog("tlsDatabase.initCount > 0","src/libraries/tls/tls.c",0x169);
  return -1;
}


// ===== 005239f0 tlsEntryAcquire =====

undefined8 tlsEntryAcquire(ulong param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  if (DAT_0056ede0 == 0) {
    nvAssertFailedNoLog("tlsDatabase.initCount > 0","src/libraries/tls/tls.c",0x175);
    return 0;
  }
  if ((DAT_0056eda8 < param_1) && (param_1 < 0x100000)) {
    nvAssertFailedNoLog("entryId <= tlsDatabase.lastEntryId || entryId >= TLS_ENTRY_ID_TAG_START",
                        "src/libraries/tls/tls.c",0x178);
    return 0;
  }
  lVar1 = _tlsThreadEntryGet();
  if ((lVar1 == 0) && (lVar1 = _tlsThreadEntryGetOrAlloc_part_0(0), lVar1 == 0)) {
    nvAssertFailedNoLog("pThreadEntry != NULL","src/libraries/tls/tls.c",0x17c);
    return 0;
  }
  uVar2 = _tlsEntryAcquire(lVar1,param_1,0);
  return uVar2;
}


// ===== 00523ac0 tlsEntryRelease =====

undefined8 tlsEntryRelease(undefined8 param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (DAT_0056ede0 == 0) {
    nvAssertFailedNoLog("tlsDatabase.initCount > 0","src/libraries/tls/tls.c",0x195);
  }
  else {
    lVar1 = _tlsThreadEntryGet();
    if (lVar1 == 0) {
      nvAssertFailedNoLog("pThreadEntry != NULL","src/libraries/tls/tls.c",0x198);
    }
    else {
      lVar2 = mapFind_IMPL(lVar1 + 8,param_1);
      if (lVar2 != 0) {
        uVar3 = _tlsEntryRelease(lVar1,lVar2,0);
        return uVar3;
      }
      nvAssertFailedNoLog("pTlsEntry != NULL","src/libraries/tls/tls.c",0x19b);
    }
  }
  return 0xffffffff;
}


// ===== 00523b90 tlsEntryGet =====

undefined8 tlsEntryGet(undefined8 param_1)

{
  long lVar1;
  
  if (DAT_0056ede0 == 0) {
    nvAssertFailedNoLog("tlsDatabase.initCount > 0","src/libraries/tls/tls.c",0x1b4);
    return 0;
  }
  lVar1 = _tlsThreadEntryGet();
  if (lVar1 != 0) {
    lVar1 = mapFind_IMPL(lVar1 + 8,param_1);
    if (lVar1 != 0) {
      return *(undefined8 *)(lVar1 + 8);
    }
  }
  return 0;
}


// ===== 00523c00 nvAssertFailed =====

void nvAssertFailed(undefined8 param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  long lVar2;
  undefined8 unaff_retaddr;
  
  if (*param_2 != '\0') {
    lVar2 = 0;
    do {
      lVar2 = lVar2 + 1;
    } while (param_2[lVar2] != '\0');
    cVar1 = param_2[lVar2];
    while (cVar1 != '/') {
      lVar2 = lVar2 + -1;
      if (lVar2 == 0) goto LAB_00523c41;
      cVar1 = param_2[lVar2];
    }
    param_2 = param_2 + lVar2 + 1;
  }
LAB_00523c41:
  nvDbg_Printf("src/libraries/utils/nvassert.c",0x72,"nvAssertFailed",4,
               "NVRM: Assertion failed: %s @ %s:%d\n",param_1,param_2);
  rcdbRmAssert(param_3,unaff_retaddr,param_3);
  return;
}


// ===== 00523c80 nvAssertFailedNoLog =====

void nvAssertFailedNoLog(undefined8 param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  long lVar2;
  undefined8 unaff_retaddr;
  
  if (*param_2 != '\0') {
    lVar2 = 0;
    do {
      lVar2 = lVar2 + 1;
    } while (param_2[lVar2] != '\0');
    cVar1 = param_2[lVar2];
    while (cVar1 != '/') {
      lVar2 = lVar2 + -1;
      if (lVar2 == 0) goto LAB_00523cc1;
      cVar1 = param_2[lVar2];
    }
    param_2 = param_2 + lVar2 + 1;
  }
LAB_00523cc1:
  nvDbg_Printf("src/libraries/utils/nvassert.c",0xc1,"nvAssertFailedNoLog",4,
               "NVRM: Assertion failed: %s @ %s:%d\n",param_1,param_2);
  rcdbRmAssert(param_3,unaff_retaddr,param_3);
  return;
}


// ===== 00523d00 nvAssertOkFailedNoLog =====

void nvAssertOkFailedNoLog(undefined4 param_1,undefined8 param_2,char *param_3,undefined4 param_4)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 unaff_retaddr;
  
  if (*param_3 != '\0') {
    lVar2 = 0;
    do {
      lVar2 = lVar2 + 1;
    } while (param_3[lVar2] != '\0');
    cVar1 = param_3[lVar2];
    while (cVar1 != '/') {
      lVar2 = lVar2 + -1;
      if (lVar2 == 0) goto LAB_00523d51;
      cVar1 = param_3[lVar2];
    }
    param_3 = param_3 + lVar2 + 1;
  }
LAB_00523d51:
  uVar3 = nvstatusToString(param_1);
  nvDbg_Printf("src/libraries/utils/nvassert.c",0xd4,"nvAssertOkFailedNoLog",4,
               "NVRM: Assertion failed: %s (0x%08X) returned from %s @ %s:%d\n",uVar3,param_1,
               param_2,param_3,param_4);
  rcdbRmAssertStatus(param_1,param_4,unaff_retaddr);
  return;
}


// ===== 00523db0 nvCheckFailedNoLog =====

undefined1  [16]
nvCheckFailedNoLog(undefined4 param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  char cVar1;
  undefined1 auVar2 [16];
  long lVar3;
  
  if (*param_3 != '\0') {
    lVar3 = 0;
    do {
      lVar3 = lVar3 + 1;
    } while (param_3[lVar3] != '\0');
    cVar1 = param_3[lVar3];
    while (cVar1 != '/') {
      lVar3 = lVar3 + -1;
      if (lVar3 == 0) goto LAB_00523df1;
      cVar1 = param_3[lVar3];
    }
    param_3 = param_3 + lVar3 + 1;
  }
LAB_00523df1:
  nvDbg_Printf("src/libraries/utils/nvassert.c",0xe8,"nvCheckFailedNoLog",param_1,
               "NVRM: Check failed: %s @ %s:%d\n",param_2);
  auVar2._8_8_ = param_4;
  auVar2._0_8_ = param_3;
  return auVar2;
}


// ===== 00523e20 nvCheckOkFailedNoLog =====

void nvCheckOkFailedNoLog
               (undefined4 param_1,undefined4 param_2,undefined8 param_3,char *param_4,
               undefined4 param_5)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (*param_4 != '\0') {
    lVar2 = 0;
    do {
      lVar2 = lVar2 + 1;
    } while (param_4[lVar2] != '\0');
    cVar1 = param_4[lVar2];
    while (cVar1 != '/') {
      lVar2 = lVar2 + -1;
      if (lVar2 == 0) goto LAB_00523e71;
      cVar1 = param_4[lVar2];
    }
    param_4 = param_4 + lVar2 + 1;
  }
LAB_00523e71:
  uVar3 = nvstatusToString(param_2);
  nvDbg_Printf("src/libraries/utils/nvassert.c",0xfa,"nvCheckOkFailedNoLog",param_1,
               "NVRM: Check failed: %s (0x%08X) returned from %s @ %s:%d\n",uVar3,param_2,param_3,
               param_4,param_5);
  return;
}


// ===== 00523ec0 nvAssertInit =====

void nvAssertInit(void)

{
  return;
}


// ===== 00523ed0 nvAssertDestroy =====

void nvAssertDestroy(void)

{
  return;
}


// ===== 00523ee0 dwarfReadLeb128Generic =====

undefined8 dwarfReadLeb128Generic(long *param_1,ulong *param_2,uint param_3)

{
  byte bVar1;
  ulong uVar2;
  ulong uVar3;
  byte bVar4;
  ulong uVar5;
  ulong uVar6;
  
  uVar6 = 0;
  uVar5 = 0;
  uVar2 = param_1[1];
  while( true ) {
    uVar3 = uVar2 + 1;
    if ((ulong)param_1[2] < uVar3) {
      return 0;
    }
    bVar1 = *(byte *)(*param_1 + uVar2);
    param_1[1] = uVar3;
    bVar4 = (byte)uVar5;
    uVar5 = uVar5 + 7;
    uVar6 = uVar6 | (ulong)(bVar1 & 0x7f) << (bVar4 & 0x3f);
    if (-1 < (char)bVar1) break;
    uVar2 = uVar3;
    if (uVar5 == 0x46) {
      return 0;
    }
  }
  if (((uVar5 < 0x40) && ((param_3 & 1) != 0)) && ((bVar1 & 0x40) != 0)) {
    uVar6 = -1L << ((byte)uVar5 & 0x3f) | uVar6;
  }
  *param_2 = uVar6;
  return 1;
}


// ===== 00523f60 dwarfBuildARangeTable =====

void dwarfBuildARangeTable(long param_1)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  uint uVar14;
  long lVar15;
  bool bVar16;
  bool bVar17;
  int local_54;
  uint local_44;
  long local_40;
  long local_38;
  
  uVar14 = 0;
  lVar2 = *(long *)(param_1 + 0x10);
  uVar11 = *(long *)(param_1 + 0x18) - lVar2;
  if (3 < uVar11) {
    uVar8 = 4;
    lVar7 = 0;
    local_54 = 1;
    do {
      local_44 = 0xffffffff;
      lVar3 = 0;
      do {
        *(undefined1 *)((long)&local_44 + lVar3) = *(undefined1 *)(lVar7 + lVar2 + lVar3);
        lVar3 = lVar3 + 1;
      } while (lVar3 != 4);
      uVar6 = (ulong)local_44;
      if (((((0xffffffef < local_44) || (uVar11 - uVar8 < uVar6)) || (uVar1 = uVar6 + 4, uVar1 < 6))
          || ((*(short *)(lVar2 + uVar8) != 2 || (uVar1 < 10)))) ||
         ((0xfffffffffffffff3 < uVar6 - 8 ||
          ((lVar3 = lVar2 + -4 + uVar8, *(char *)(lVar3 + 10) != '\b' ||
           (*(char *)(lVar3 + 0xb) != '\0')))))) break;
      lVar7 = uVar6 + uVar8;
      uVar8 = 0x10;
      lVar9 = 0;
      lVar12 = 0;
      do {
        if (uVar1 < uVar8 + 8) {
LAB_0052416b:
          bVar16 = uVar6 <= uVar8;
          bVar17 = true;
          lVar13 = 0;
LAB_0052417a:
          if ((uVar6 <= uVar8) || (lVar10 = lVar9, lVar5 = lVar12, !bVar17)) {
            lVar5 = 0;
            lVar10 = lVar13;
            if (lVar9 + lVar12 != 0) goto LAB_005240dc;
LAB_00524192:
            lVar10 = lVar9 + lVar13;
            lVar5 = lVar12;
          }
        }
        else {
          lVar5 = 0;
          lVar13 = lVar3 + uVar8;
          do {
            *(undefined1 *)((long)&local_40 + lVar5) = *(undefined1 *)(lVar13 + lVar5);
            lVar5 = lVar5 + 1;
          } while (lVar5 != 8);
          uVar4 = uVar8 + 0x10;
          uVar8 = uVar8 + 8;
          if (uVar1 < uVar4) goto LAB_0052416b;
          lVar5 = 0;
          do {
            *(undefined1 *)((long)&local_38 + lVar5) = *(undefined1 *)(lVar13 + 8 + lVar5);
            lVar5 = lVar5 + 1;
          } while (lVar5 != 8);
          bVar16 = uVar6 <= uVar4;
          uVar8 = uVar4;
          lVar13 = local_38;
          if (local_40 == 0) {
            bVar17 = local_38 == 0;
            goto LAB_0052417a;
          }
          lVar5 = local_40;
          lVar10 = local_38;
          if (lVar9 + lVar12 == local_40) goto LAB_00524192;
LAB_005240dc:
          if ((lVar12 != 0) && (lVar9 != 0)) {
            lVar13 = *(long *)(param_1 + 0x50);
            if ((lVar13 != 0) && (uVar14 < *(uint *)(param_1 + 0x58))) {
              lVar15 = (ulong)uVar14 * 0x20;
              *(int *)(lVar13 + 8 + lVar15) = (int)lVar9;
              *(long *)(lVar13 + lVar15) = lVar12;
              *(int *)(lVar13 + 0xc + lVar15) = local_54;
            }
            uVar14 = uVar14 + 1;
          }
        }
        lVar9 = lVar10;
        lVar12 = lVar5;
      } while (!bVar16);
      uVar8 = lVar7 + 4;
      local_54 = local_54 + 1;
    } while (uVar8 <= uVar11);
  }
  *(uint *)(param_1 + 0x58) = uVar14;
  return;
}


// ===== 005241c0 dwarfParseUnitLines.constprop.0 =====

/* WARNING: Removing unreachable block (ram,0x00524278) */

char dwarfParseUnitLines_constprop_0
               (long param_1,ulong param_2,long *param_3,long *param_4,long *param_5,ulong *param_6,
               short *param_7,ulong param_8,ulong param_9,ulong *param_10,char param_11)

{
  char *pcVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  short sVar5;
  int iVar6;
  bool bVar7;
  short *psVar8;
  ulong uVar9;
  char cVar10;
  char cVar11;
  ushort uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  long lVar16;
  ulong uVar17;
  long lVar18;
  ulong uVar19;
  ulong uVar20;
  ulong uVar21;
  ulong *puVar22;
  ulong uVar23;
  ulong *puVar24;
  ulong uVar25;
  ulong uVar26;
  ulong uVar27;
  ulong local_a0;
  ulong local_98;
  long local_90;
  uint local_88;
  uint local_84;
  ulong local_80;
  ulong local_78;
  ulong local_70;
  ulong local_68;
  ulong local_60;
  ulong local_58;
  short *local_50;
  ulong local_48;
  ulong local_40;
  
  uVar9 = param_9;
  psVar8 = param_7;
  if (param_9 < 2) {
    return '\0';
  }
  sVar5 = *param_7;
  if (sVar5 == 2) {
    if (param_9 < 6) {
      return '\0';
    }
    lVar16 = 0;
    do {
      *(undefined1 *)((long)&local_88 + lVar16) = *(undefined1 *)((long)param_7 + lVar16 + 2);
      lVar16 = lVar16 + 1;
    } while (lVar16 != 4);
    if (param_9 == 6) {
      return '\0';
    }
    bVar2 = *(byte *)(param_7 + 3);
    uVar17 = 8;
    local_90 = 6;
    lVar16 = 7;
  }
  else {
    if (sVar5 != 5) {
      return '\0';
    }
    if (param_9 < 8) {
      return '\0';
    }
    lVar16 = 0;
    do {
      *(undefined1 *)((long)&local_88 + lVar16) = *(undefined1 *)((long)param_7 + lVar16 + 4);
      lVar16 = lVar16 + 1;
    } while (lVar16 != 4);
    if (*(long *)(param_1 + 0x20) == 0) {
      return '\0';
    }
    if (param_9 < 10) {
      return '\0';
    }
    bVar2 = *(byte *)(param_7 + 4);
    uVar17 = 0xb;
    local_90 = 8;
    lVar16 = 10;
  }
  uVar14 = (uint)bVar2;
  if (param_9 < uVar17) {
    return '\0';
  }
  if (param_9 < lVar16 + 2U) {
    return '\0';
  }
  if (param_9 < lVar16 + 3U) {
    return '\0';
  }
  local_98 = lVar16 + 4;
  if (param_9 < local_98) {
    return '\0';
  }
  bVar2 = *(byte *)((long)param_7 + lVar16 + 2);
  if (bVar2 == 0) {
    return '\0';
  }
  cVar11 = *(char *)((long)param_7 + uVar17);
  bVar3 = *(byte *)((long)param_7 + lVar16 + 3);
  if (1 < bVar3) {
    uVar17 = 1;
    param_8 = local_98;
    do {
      param_7 = psVar8;
      param_9 = uVar9;
      cVar10 = dwarfReadLeb128Generic(&param_7,&local_50,0);
      if (cVar10 == '\0') {
        return '\0';
      }
      uVar17 = uVar17 + 1;
    } while (uVar17 != bVar3);
    local_98 = param_8;
  }
  if (uVar9 - local_90 < (ulong)local_88) {
    return '\0';
  }
  uVar20 = (ulong)local_88 + local_90;
  local_80 = 0;
  uVar17 = uVar20 + 1;
  local_78 = 1;
  local_70 = 0;
  if (uVar9 < uVar17) {
    return '\0';
  }
  lVar16 = 1;
  local_a0 = 0;
  local_90 = 0;
  uVar19 = 0;
  uVar21 = 0;
  do {
    bVar4 = *(byte *)((long)psVar8 + uVar20);
    uVar20 = uVar17;
    if (bVar4 < bVar3) {
      uVar27 = uVar21;
      uVar26 = uVar19;
      if (bVar4 == 0) {
        param_7 = psVar8;
        param_8 = uVar17;
        param_9 = uVar9;
        cVar10 = dwarfReadLeb128Generic(&param_7,&local_68,0);
        if (cVar10 == '\0') {
          return '\0';
        }
        if (uVar9 - param_8 < local_68) {
          return '\0';
        }
        uVar20 = local_68 + param_8;
        uVar25 = uVar20 - uVar17;
        uVar23 = (param_8 + 1) - uVar17;
        if (uVar25 < uVar23) {
          return '\0';
        }
        bVar4 = *(byte *)((long)psVar8 + param_8);
        if (bVar4 == 3) {
          param_8 = uVar20;
          uVar17 = uVar20;
          if (uVar20 < uVar9) {
            do {
              uVar19 = uVar17 + 1;
              param_8 = uVar19;
              if (*(char *)((long)psVar8 + uVar17) == '\0') break;
              param_8 = uVar20;
              uVar17 = uVar19;
            } while (uVar9 != uVar19);
          }
          dwarfReadLeb128Generic(&param_7,&local_60,0);
          dwarfReadLeb128Generic();
          dwarfReadLeb128Generic();
          uVar20 = param_8;
        }
        else if (bVar4 < 4) {
          if (bVar4 == 1) {
            bVar7 = true;
            goto LAB_005244ca;
          }
          if (bVar4 != 2) {
            return '\0';
          }
          if (local_68 == 5) {
            if (uVar25 < uVar23 + 4) {
              return '\0';
            }
            lVar18 = 0;
            do {
              *(undefined1 *)((long)&local_50 + lVar18) =
                   *(undefined1 *)((long)psVar8 + lVar18 + uVar23 + uVar17);
              lVar18 = lVar18 + 1;
            } while (lVar18 != 4);
            local_80 = (ulong)local_50 & 0xffffffff;
          }
          else {
            if (local_68 != 9) {
              return '\0';
            }
            if (uVar25 < uVar23 + 8) {
              return '\0';
            }
            lVar18 = 0;
            do {
              *(undefined1 *)((long)&local_80 + lVar18) =
                   *(undefined1 *)((long)psVar8 + lVar18 + uVar23 + uVar17);
              lVar18 = lVar18 + 1;
            } while (lVar18 != 8);
          }
        }
        else if (bVar4 != 4) {
          return '\0';
        }
      }
      else if (bVar4 == 5) {
        puVar22 = &local_70;
LAB_00524827:
        param_7 = psVar8;
        param_8 = uVar17;
        param_9 = uVar9;
        cVar10 = dwarfReadLeb128Generic(&param_7,puVar22,0);
        uVar20 = param_8;
        if (cVar10 == '\0') {
          return '\0';
        }
      }
      else if (bVar4 < 6) {
        if (bVar4 == 3) {
          param_7 = psVar8;
          param_8 = uVar17;
          param_9 = uVar9;
          cVar10 = dwarfReadLeb128Generic(&param_7,&local_50,1);
          if (cVar10 == '\0') {
            return '\0';
          }
          uVar20 = param_8;
          lVar16 = lVar16 + (long)local_50;
        }
        else {
          if (bVar4 == 4) {
            puVar22 = &local_78;
            goto LAB_00524827;
          }
          if (bVar4 == 1) {
            bVar7 = false;
            goto LAB_005244ca;
          }
          param_7 = psVar8;
          param_8 = uVar17;
          param_9 = uVar9;
          cVar10 = dwarfReadLeb128Generic(&param_7,&local_50,0);
          if (cVar10 == '\0') {
            return '\0';
          }
          local_80 = local_80 + (ulong)uVar14 * (long)local_50;
          uVar20 = param_8;
        }
      }
      else if (bVar4 == 9) {
        if (uVar9 < uVar17 + 2) {
          uVar13 = 0;
        }
        else {
          uVar13 = (uint)*(ushort *)((long)psVar8 + uVar17);
          uVar17 = uVar17 + 2;
        }
LAB_00524608:
        local_80 = local_80 + uVar13 * uVar14;
        uVar20 = uVar17;
      }
      else if (bVar4 < 10) {
        if (bVar4 == 8) {
          uVar13 = (uint)((ulong)(byte)~bVar3 / (ulong)(long)(int)(uint)bVar2);
          goto LAB_00524608;
        }
      }
      else if (1 < (byte)(bVar4 - 10)) {
        return '\0';
      }
    }
    else {
      uVar12 = (ushort)bVar4 - (ushort)bVar3 & 0xff;
      local_80 = (byte)(uVar12 / bVar2) * uVar14 + local_80;
      bVar7 = false;
      lVar16 = lVar16 + (int)((int)cVar11 + (uint)(byte)(uVar12 % (ushort)bVar2));
LAB_005244ca:
      uVar26 = local_78;
      uVar27 = local_80;
      if (param_11 != '\0') {
        if (*(uint *)(param_1 + 0x58) == 0) {
          return '\0';
        }
        puVar22 = *(ulong **)(param_1 + 0x50);
        uVar17 = 0;
        puVar24 = puVar22;
        while ((local_80 < *puVar24 || ((ulong)(uint)puVar24[1] + *puVar24 <= local_80))) {
          uVar14 = (int)uVar17 + 1;
          uVar17 = (ulong)uVar14;
          puVar24 = puVar24 + 4;
          if (uVar14 == *(uint *)(param_1 + 0x58)) {
            return '\0';
          }
        }
        iVar6 = *(int *)((long)puVar24 + 0xc);
        if (iVar6 == 0) {
          return '\0';
        }
        while ((iVar15 = (int)uVar17, iVar15 != 0 &&
               (iVar6 == *(int *)((long)puVar22 + (ulong)(iVar15 - 1) * 0x20 + 0xc)))) {
          uVar17 = (ulong)(iVar15 - 1);
        }
        lVar16 = uVar17 * 0x20;
        puVar22 = puVar22 + uVar17 * 4;
        iVar15 = *(int *)((long)puVar22 + 0xc);
        while (iVar15 == iVar6) {
          puVar22[2] = (ulong)psVar8;
          *(int *)(*(long *)(param_1 + 0x50) + 0x18 + lVar16) = (int)uVar9;
          uVar17 = (ulong)((int)uVar17 + 1);
          lVar16 = uVar17 * 0x20;
          puVar22 = (ulong *)(*(long *)(param_1 + 0x50) + lVar16);
          iVar15 = *(int *)((long)puVar22 + 0xc);
        }
        return '\0';
      }
      if ((uVar21 - 1 < param_2) && (param_2 < local_80)) {
        if (sVar5 == 2) {
          local_68 = 0;
          *param_3 = (long)"";
          *param_4 = (long)"";
          cVar11 = '\0';
          uVar17 = local_98;
          if (uVar19 != 0) break;
          goto LAB_0052497b;
        }
        local_48 = local_98 + 1;
        if (((uVar9 < local_48) || (1 < *(byte *)((long)psVar8 + local_98))) ||
           ((*(byte *)((long)psVar8 + local_98) != 0 &&
            (((local_50 = psVar8, local_40 = uVar9,
              cVar11 = dwarfReadLeb128Generic(&local_50,&local_60,0), cVar11 == '\0' ||
              (cVar11 = dwarfReadLeb128Generic(), cVar11 == '\0')) ||
             ((local_60 != 1 || (local_58 != 0x1f)))))))) goto LAB_00524979;
        local_50 = psVar8;
        local_40 = uVar9;
        cVar10 = dwarfReadLeb128Generic(&local_50,&local_68,0);
        uVar17 = local_48;
        cVar11 = '\0';
        if (cVar10 == '\0') goto LAB_0052497b;
        uVar20 = 0;
        goto LAB_0052496b;
      }
      local_a0 = local_70;
      local_90 = lVar16;
      if (bVar7) {
        local_80 = 0;
        local_78 = 1;
        local_70 = 0;
        lVar16 = 1;
      }
    }
    uVar17 = uVar20 + 1;
    uVar19 = uVar26;
    uVar21 = uVar27;
    if (uVar9 < uVar17) {
      return '\0';
    }
  } while( true );
  while( true ) {
    while (local_48 = uVar20 + 1, *(char *)((long)psVar8 + uVar20) != '\0') {
      uVar20 = local_48;
      if (uVar9 == local_48) goto LAB_0052497b;
    }
    pcVar1 = (char *)((long)psVar8 + uVar17);
    uVar17 = local_48;
    if (*pcVar1 == '\0') break;
    uVar20 = uVar17;
    if (uVar9 <= uVar17) goto LAB_0052497b;
  }
  uVar17 = 0;
  do {
    uVar20 = local_48;
    if (uVar9 <= local_48) goto LAB_00524dd2;
    while (uVar21 = uVar20 + 1, *(char *)((long)psVar8 + uVar20) != '\0') {
      uVar20 = uVar21;
      if (uVar9 == uVar21) goto LAB_00524dd2;
    }
    *param_4 = local_48 + (long)psVar8;
    local_50 = psVar8;
    local_48 = uVar21;
    local_40 = uVar9;
    cVar11 = dwarfReadLeb128Generic(&local_50,&local_68,0);
    if (((cVar11 == '\0') || (cVar11 = dwarfReadLeb128Generic(), cVar11 == '\0')) ||
       (param_11 = dwarfReadLeb128Generic(), param_11 == '\0')) goto LAB_00524dd2;
    uVar17 = uVar17 + 1;
  } while (uVar19 != uVar17);
  for (uVar17 = 0; uVar20 = local_98, cVar11 = param_11, uVar17 != local_68; uVar17 = uVar17 + 1) {
    do {
      if (uVar9 <= uVar20) goto LAB_00524dd2;
      pcVar1 = (char *)((long)psVar8 + uVar20);
      uVar20 = uVar20 + 1;
    } while (*pcVar1 != '\0');
    *param_3 = local_98 + (long)psVar8;
    local_98 = uVar20;
  }
  goto LAB_0052497b;
LAB_00524dd2:
  param_11 = '\0';
  cVar11 = param_11;
  goto LAB_0052497b;
LAB_0052496b:
  if (uVar20 == local_68) goto LAB_005249c7;
  local_48 = local_48 + 4;
  if (uVar9 < local_48) goto LAB_00524979;
  uVar20 = uVar20 + 1;
  goto LAB_0052496b;
LAB_005249c7:
  if ((local_48 + 1 <= uVar9) && (*(char *)((long)psVar8 + local_48) == '\x02')) {
    local_48 = local_48 + 1;
    cVar11 = '\0';
    while( true ) {
      local_50 = psVar8;
      local_40 = uVar9;
      cVar10 = dwarfReadLeb128Generic(&local_50,&local_60,0);
      if ((cVar10 == '\0') || (cVar10 = dwarfReadLeb128Generic(), cVar10 == '\0'))
      goto LAB_00524979;
      if (cVar11 != '\0') break;
      if ((local_60 != 1) || (cVar11 = cVar10, local_58 != 0x1f)) goto LAB_00524979;
    }
    if ((local_60 == 2) && (local_58 == 0xf)) {
      cVar10 = dwarfReadLeb128Generic();
      cVar11 = '\0';
      if (cVar10 == '\0') goto LAB_0052497b;
      if (uVar19 < local_60) {
        uVar20 = 0;
        local_58 = 0;
        goto LAB_00524a8e;
      }
    }
  }
LAB_00524979:
  cVar11 = '\0';
  goto LAB_0052497b;
  while (uVar20 = uVar20 + 1, uVar20 <= uVar19) {
LAB_00524a8e:
    if (uVar9 < local_48 + 4) goto LAB_00524979;
    lVar16 = 0;
    do {
      *(undefined1 *)((long)&local_84 + lVar16) = *(undefined1 *)((long)psVar8 + lVar16 + local_48);
      lVar16 = lVar16 + 1;
    } while (lVar16 != 4);
    local_50 = psVar8;
    local_48 = local_48 + 4;
    local_40 = uVar9;
    cVar11 = dwarfReadLeb128Generic(&local_50,&local_58,0);
    if (cVar11 == '\0') goto LAB_00524979;
    if (uVar19 == uVar20) {
      lVar16 = *(long *)(param_1 + 0x20);
      if ((lVar16 != 0) &&
         (uVar20 = *(long *)(param_1 + 0x28) - lVar16, lVar16 = lVar16 + (ulong)local_84,
         uVar20 <= local_84)) {
        lVar16 = 0;
      }
      *param_4 = lVar16;
      break;
    }
  }
  uVar20 = 0;
  do {
    if (uVar9 < uVar17 + 4) goto LAB_00524979;
    lVar16 = 0;
    do {
      *(undefined1 *)((long)&local_84 + lVar16) = *(undefined1 *)((long)psVar8 + lVar16 + uVar17);
      lVar16 = lVar16 + 1;
    } while (lVar16 != 4);
    if (local_58 == uVar20) {
      lVar16 = *(long *)(param_1 + 0x20);
      lVar18 = lVar16;
      if ((lVar16 != 0) &&
         (lVar18 = lVar16 + (ulong)local_84,
         (ulong)(*(long *)(param_1 + 0x28) - lVar16) <= (ulong)local_84)) {
        lVar18 = 0;
      }
      *param_3 = lVar18;
    }
    uVar20 = uVar20 + 1;
    uVar17 = uVar17 + 4;
  } while (uVar20 <= local_58);
  if (*param_4 == 0) {
    cVar11 = '\0';
  }
  else {
    cVar11 = *param_3 != 0;
  }
LAB_0052497b:
  *param_5 = local_90;
  *param_6 = local_a0;
  *param_10 = param_2;
  return cVar11;
}


// ===== 00524e80 LibosDebugResolverConstruct =====

undefined8 LibosDebugResolverConstruct(long *param_1,undefined8 param_2)

{
  char cVar1;
  long lVar2;
  undefined8 *puVar3;
  long lVar4;
  uint uVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  uint local_54;
  long local_50;
  undefined8 local_48;
  ulong local_40;
  
  lVar2 = LibosElfFindSectionByName(param_2,".debug_line");
  if ((lVar2 == 0) || (cVar1 = LibosElfMapSection(param_2,lVar2,param_1,param_1 + 1), cVar1 != '\0')
     ) {
    param_1[1] = 0;
    *param_1 = 0;
  }
  param_1[5] = 0;
  param_1[4] = 0;
  lVar2 = LibosElfFindSectionByName(param_2,".debug_line_str");
  if (lVar2 != 0) {
    LibosElfMapSection(param_2,lVar2,param_1 + 4,param_1 + 5);
  }
  lVar2 = LibosElfFindSectionByName(param_2,".debug_aranges");
  if ((lVar2 == 0) ||
     (cVar1 = LibosElfMapSection(param_2,lVar2,param_1 + 2,param_1 + 3), cVar1 != '\0')) {
    param_1[3] = 0;
    param_1[2] = 0;
  }
  lVar2 = LibosElfFindSectionByName(param_2,".symtab");
  if ((lVar2 == 0) ||
     (cVar1 = LibosElfMapSection(param_2,lVar2,param_1 + 6,param_1 + 7), cVar1 != '\0')) {
    param_1[7] = 0;
    param_1[6] = 0;
  }
  lVar2 = LibosElfFindSectionByName(param_2,".strtab");
  if ((lVar2 == 0) ||
     (cVar1 = LibosElfMapSection(param_2,lVar2,param_1 + 8,param_1 + 9), cVar1 != '\0')) {
    param_1[9] = 0;
    param_1[8] = 0;
  }
  param_1[10] = 0;
  *(undefined4 *)(param_1 + 0xb) = 0;
  if ((param_1[2] != 0) && (*param_1 != 0)) {
    dwarfBuildARangeTable(param_1);
    puVar3 = (undefined8 *)portMemAllocNonPaged(((int)param_1[0xb] + 1) * 0x20);
    param_1[10] = (long)puVar3;
    if ((int)param_1[0xb] != -1) {
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      *(undefined4 *)(puVar3 + 3) = 0;
      if (1 < (int)param_1[0xb] + 1U) {
        uVar7 = 1;
        do {
          uVar5 = (int)uVar7 + 1;
          puVar3 = (undefined8 *)(uVar7 * 0x20 + param_1[10]);
          *puVar3 = 0;
          puVar3[1] = 0;
          puVar3[2] = 0;
          *(undefined4 *)(puVar3 + 3) = 0;
          uVar7 = (ulong)uVar5;
        } while (uVar5 < (int)param_1[0xb] + 1U);
      }
    }
    dwarfBuildARangeTable(param_1);
    lVar2 = *param_1;
    uVar7 = param_1[1] - lVar2;
    if (uVar7 < 4) {
      return 0;
    }
    lVar6 = 0;
    uVar8 = 4;
    do {
      lVar4 = 0;
      do {
        *(undefined1 *)((long)&local_54 + lVar4) = *(undefined1 *)(lVar2 + lVar6 + lVar4);
        lVar4 = lVar4 + 1;
      } while (lVar4 != 4);
      local_40 = (ulong)local_54;
      if (0xffffffef < local_54) {
        return 0;
      }
      if (uVar7 - uVar8 < local_40) {
        return 0;
      }
      local_50 = lVar2 + uVar8;
      lVar6 = local_40 + uVar8;
      uVar8 = lVar6 + 4;
      local_48 = 0;
      dwarfParseUnitLines_constprop_0(param_1,0,0,0,0,0,local_50,0,local_40,0,1);
    } while (uVar8 <= uVar7);
  }
  return 0;
}


// ===== 005251c0 LibosDebugResolverDestroy =====

void LibosDebugResolverDestroy(long param_1)

{
  if (*(long *)(param_1 + 0x50) != 0) {
    portMemFree(*(long *)(param_1 + 0x50));
    *(undefined8 *)(param_1 + 0x50) = 0;
    return;
  }
  return;
}


// ===== 00525200 LibosDebugResolveSymbolToName =====

bool LibosDebugResolveSymbolToName(long param_1,ulong param_2,long *param_3,long *param_4)

{
  ulong uVar1;
  uint *puVar2;
  ulong uVar3;
  
  puVar2 = *(uint **)(param_1 + 0x30);
  if (puVar2 == (uint *)0x0) {
    return false;
  }
  uVar3 = *(long *)(param_1 + 0x38) - (long)puVar2;
  if (0x17 < uVar3) {
    uVar3 = uVar3 / 0x18;
    do {
      if ((*puVar2 != 0) &&
         ((uVar1 = *(ulong *)(puVar2 + 2), uVar1 == param_2 ||
          ((uVar1 <= param_2 && (param_2 < uVar1 + *(long *)(puVar2 + 4))))))) {
        *param_3 = (ulong)*puVar2 + *(long *)(param_1 + 0x40);
        *param_4 = param_2 - *(long *)(puVar2 + 2);
        if (*(long *)(puVar2 + 4) != 0) {
          return true;
        }
      }
      puVar2 = puVar2 + 6;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return *param_3 != 0;
}


// ===== 005252b0 LibosDwarfResolveLine =====

undefined8 LibosDwarfResolveLine(long param_1,ulong param_2,undefined8 param_3)

{
  ulong *puVar1;
  ulong *puVar2;
  undefined8 uVar3;
  
  if (*(uint *)(param_1 + 0x58) == 0) {
    return 0;
  }
  puVar2 = *(ulong **)(param_1 + 0x50);
  puVar1 = puVar2 + (ulong)*(uint *)(param_1 + 0x58) * 4;
  while ((param_2 < *puVar2 || (*puVar2 + (ulong)(uint)puVar2[1] <= param_2))) {
    puVar2 = puVar2 + 4;
    if (puVar2 == puVar1) {
      return 0;
    }
  }
  if (puVar2[2] == 0) {
    return 0;
  }
  uVar3 = dwarfParseUnitLines_constprop_0(param_1,param_2,param_3);
  return uVar3;
}


// ===== 00525350 elfSimpleAccess =====

long elfSimpleAccess(long *param_1,long param_2,long param_3)

{
  long lVar1;
  
  lVar1 = 0;
  if ((ulong)(param_3 + param_2) <= (ulong)param_1[1]) {
    lVar1 = *param_1 + param_2;
  }
  return lVar1;
}


// ===== 00525370 LibosElfImageConstruct =====

undefined8 LibosElfImageConstruct(long *param_1,long param_2,ulong param_3)

{
  undefined8 uVar1;
  
  uVar1 = 4;
  if (0x3f < param_3) {
    *param_1 = param_2;
    uVar1 = 1;
    if ((byte)(*(char *)(param_2 + 4) - 1U) < 2) {
      param_1[1] = param_3;
      uVar1 = 0;
      param_1[2] = (long)elfSimpleAccess;
    }
  }
  return uVar1;
}


// ===== 005253b0 LibosElfGetClass =====

undefined1 LibosElfGetClass(long *param_1)

{
  return *(undefined1 *)(*param_1 + 4);
}


// ===== 005253c0 LibosElfProgramHeaderNext =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

long LibosElfProgramHeaderNext(long *param_1,long param_2)

{
  ushort uVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  
  lVar3 = *param_1;
  if (*(char *)(lVar3 + 4) == '\x01') {
    uVar4 = (ulong)*(uint *)(lVar3 + 0x1c);
    uVar1 = *(ushort *)(lVar3 + 0x2c);
    lVar5 = 0x20;
  }
  else {
    if (*(char *)(lVar3 + 4) != '\x02') {
      return 0;
    }
    uVar4 = *(ulong *)(lVar3 + 0x20);
    uVar1 = *(ushort *)(lVar3 + 0x38);
    lVar5 = 0x38;
  }
  if ((code *)param_1[2] == elfSimpleAccess) {
    lVar3 = lVar3 + uVar4;
    if ((ulong)param_1[1] < (ulong)uVar1 * lVar5 + uVar4) {
      lVar3 = 0;
    }
  }
  else {
    lVar3 = (*(code *)param_1[2])();
  }
  lVar2 = lVar3;
  if (param_2 != 0) {
    lVar2 = lVar5 + param_2;
  }
  if (lVar2 == (ulong)uVar1 * lVar5 + lVar3) {
    lVar2 = 0;
  }
  return lVar2;
}


// ===== 00525470 LibosElfSectionHeaderNext =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

long LibosElfSectionHeaderNext(long *param_1,long param_2)

{
  ushort uVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  
  lVar3 = *param_1;
  if (*(char *)(lVar3 + 4) == '\x01') {
    uVar4 = (ulong)*(uint *)(lVar3 + 0x20);
    uVar1 = *(ushort *)(lVar3 + 0x30);
    lVar5 = 0x28;
  }
  else {
    if (*(char *)(lVar3 + 4) != '\x02') {
      return 0;
    }
    uVar4 = *(ulong *)(lVar3 + 0x28);
    uVar1 = *(ushort *)(lVar3 + 0x3c);
    lVar5 = 0x40;
  }
  if ((code *)param_1[2] == elfSimpleAccess) {
    lVar3 = lVar3 + uVar4;
    if ((ulong)param_1[1] < (ulong)uVar1 * lVar5 + uVar4) {
      lVar3 = 0;
    }
  }
  else {
    lVar3 = (*(code *)param_1[2])();
  }
  lVar2 = lVar3;
  if (param_2 != 0) {
    lVar2 = lVar5 + param_2;
  }
  if (lVar2 == (ulong)uVar1 * lVar5 + lVar3) {
    lVar2 = 0;
  }
  return lVar2;
}


// ===== 00525520 LibosElfProgramHeaderForRange =====

long LibosElfProgramHeaderForRange(long *param_1,ulong param_2,long param_3)

{
  long lVar1;
  
  lVar1 = LibosElfProgramHeaderNext(param_1,0);
  do {
    if (lVar1 == 0) {
      return 0;
    }
    if (*(char *)(*param_1 + 4) == '\x01') {
      if ((*(uint *)(lVar1 + 8) <= param_2) &&
         (param_3 - (ulong)*(uint *)(lVar1 + 8) < (ulong)*(uint *)(lVar1 + 0x14))) {
        return lVar1;
      }
    }
    else if (((*(char *)(*param_1 + 4) == '\x02') && (*(ulong *)(lVar1 + 0x10) <= param_2)) &&
            (param_3 - *(ulong *)(lVar1 + 0x10) < *(ulong *)(lVar1 + 0x28))) {
      return lVar1;
    }
    lVar1 = LibosElfProgramHeaderNext(param_1);
  } while( true );
}


// ===== 005255c0 LibosElfFindSectionByName =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

uint * LibosElfFindSectionByName(long *param_1,undefined8 param_2)

{
  ushort uVar1;
  ushort uVar2;
  long lVar3;
  int iVar4;
  uint *puVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  uint uVar9;
  int iVar10;
  ulong uVar11;
  
  lVar6 = *param_1;
  if (*(char *)(lVar6 + 4) == '\x01') {
    uVar1 = *(ushort *)(lVar6 + 0x32);
    uVar2 = *(ushort *)(lVar6 + 0x30);
  }
  else {
    if (*(char *)(lVar6 + 4) != '\x02') {
      return (uint *)0x0;
    }
    uVar1 = *(ushort *)(lVar6 + 0x3e);
    uVar2 = *(ushort *)(lVar6 + 0x3c);
  }
  uVar9 = (uint)uVar1;
  if ((uVar9 < uVar2) &&
     (puVar5 = (uint *)LibosElfSectionHeaderNext(param_1,0), puVar5 != (uint *)0x0)) {
    iVar10 = 0;
    lVar6 = *param_1;
    if (*(char *)(lVar6 + 4) == '\x01') goto LAB_0052570d;
    iVar10 = 0;
    if (*(char *)(lVar6 + 4) == '\x02') {
      do {
        lVar3 = *(long *)(puVar5 + (ulong)*(ushort *)(lVar6 + 0x3e) * 0x10 + 6);
        if ((code *)param_1[2] == elfSimpleAccess) {
          lVar7 = 0;
          if ((ulong)(*(long *)(puVar5 + (ulong)*(ushort *)(lVar6 + 0x3e) * 0x10 + 8) + lVar3) <=
              (ulong)param_1[1]) {
            lVar7 = lVar3 + lVar6;
          }
        }
        else {
          lVar7 = (*(code *)param_1[2])
                            (param_1,lVar3,
                             *(long *)(puVar5 + (ulong)*(ushort *)(lVar6 + 0x3e) * 0x10 + 8));
        }
        uVar11 = *(ulong *)(puVar5 + (ulong)uVar9 * 0x10 + 8);
LAB_005256b0:
        do {
          uVar8 = (ulong)*puVar5;
          if (uVar11 <= uVar8) {
            return (uint *)0x0;
          }
          do {
            iVar4 = portStringCompare(uVar8 + lVar7,param_2,uVar11 - uVar8);
            if (iVar4 == 0) {
              return puVar5;
            }
            puVar5 = (uint *)LibosElfSectionHeaderNext(param_1,puVar5);
            if (puVar5 == (uint *)0x0) {
              return (uint *)0x0;
            }
            lVar6 = *param_1;
            iVar10 = iVar10 + 1;
            if (*(char *)(lVar6 + 4) == '\x01') {
              if (iVar10 == 0) {
LAB_0052570d:
                if ((code *)param_1[2] == elfSimpleAccess) {
                  lVar7 = 0;
                  if ((ulong)puVar5[(ulong)*(ushort *)(lVar6 + 0x32) * 10 + 5] +
                      (ulong)puVar5[(ulong)*(ushort *)(lVar6 + 0x32) * 10 + 4] <= (ulong)param_1[1])
                  {
                    lVar7 = (ulong)puVar5[(ulong)*(ushort *)(lVar6 + 0x32) * 10 + 4] + lVar6;
                  }
                }
                else {
                  lVar7 = (*(code *)param_1[2])(param_1);
                }
                uVar11 = (ulong)puVar5[(ulong)uVar9 * 10 + 5];
              }
              goto LAB_005256b0;
            }
            uVar8 = 0;
          } while (*(char *)(lVar6 + 4) != '\x02');
        } while (iVar10 != 0);
      } while( true );
    }
  }
  return (uint *)0x0;
}


// ===== 005257c0 LibosElfFindSectionByAddress =====

long LibosElfFindSectionByAddress(long *param_1,ulong param_2)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  
  lVar1 = LibosElfSectionHeaderNext(param_1,0);
  while( true ) {
    if (lVar1 == 0) {
      return 0;
    }
    if (*(char *)(*param_1 + 4) == '\x01') {
      uVar2 = (ulong)*(uint *)(lVar1 + 0xc);
      uVar3 = (ulong)*(uint *)(lVar1 + 0x14);
    }
    else {
      if (*(char *)(*param_1 + 4) != '\x02') {
        return 0;
      }
      uVar2 = *(ulong *)(lVar1 + 0x10);
      uVar3 = *(ulong *)(lVar1 + 0x20);
    }
    if ((uVar2 <= param_2) && (param_2 < uVar2 + uVar3)) break;
    lVar1 = LibosElfSectionHeaderNext(param_1);
  }
  return lVar1;
}


// ===== 00525840 LibosElfMapVirtual =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

long LibosElfMapVirtual(long *param_1,long param_2,ulong param_3)

{
  char cVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  
  lVar2 = LibosElfProgramHeaderForRange(param_1,param_2,param_2 + -1 + param_3);
  if (lVar2 != 0) {
    cVar1 = *(char *)(*param_1 + 4);
    if (cVar1 == '\x01') {
      uVar5 = (ulong)*(uint *)(lVar2 + 8);
      uVar4 = (ulong)*(uint *)(lVar2 + 4);
    }
    else {
      if (cVar1 != '\x02') {
        return 0;
      }
      uVar5 = *(ulong *)(lVar2 + 0x10);
      uVar4 = *(ulong *)(lVar2 + 8);
    }
    lVar2 = (uVar4 + param_2) - uVar5;
    if ((code *)param_1[2] == elfSimpleAccess) {
      if ((ulong)param_1[1] < param_3 + lVar2) {
        return 0;
      }
      return *param_1 + lVar2;
    }
    lVar2 = (*(code *)param_1[2])(param_1,lVar2,param_3);
    return lVar2;
  }
  lVar2 = LibosElfFindSectionByAddress(param_1,param_2);
  if (lVar2 == 0) {
    return 0;
  }
  cVar1 = *(char *)(*param_1 + 4);
  if (cVar1 == '\x01') {
    uVar5 = (ulong)*(uint *)(lVar2 + 0x10);
    uVar4 = (ulong)*(uint *)(lVar2 + 0x14);
    uVar3 = (ulong)*(uint *)(lVar2 + 0xc);
  }
  else {
    if (cVar1 != '\x02') {
      return 0;
    }
    uVar5 = *(ulong *)(lVar2 + 0x18);
    uVar4 = *(ulong *)(lVar2 + 0x20);
    uVar3 = *(ulong *)(lVar2 + 0x10);
  }
  uVar3 = param_2 - uVar3;
  if (CARRY8(param_3,uVar3)) {
    return 0;
  }
  if (uVar4 < param_3 + uVar3) {
    return 0;
  }
  lVar2 = uVar5 + uVar3;
  if ((code *)param_1[2] != elfSimpleAccess) {
    lVar2 = (*(code *)param_1[2])(param_1,lVar2,param_3);
    return lVar2;
  }
  if (param_3 + lVar2 <= (ulong)param_1[1]) {
    return *param_1 + lVar2;
  }
  return 0;
}


// ===== 00525980 LibosElfMapSection =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

undefined8 LibosElfMapSection(long *param_1,long param_2,long *param_3,long *param_4)

{
  char cVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  
  cVar1 = *(char *)(*param_1 + 4);
  if (cVar1 == '\x01') {
    iVar2 = *(int *)(param_2 + 4);
    uVar6 = (ulong)*(uint *)(param_2 + 0xc);
    uVar4 = (ulong)*(uint *)(param_2 + 0x14);
    uVar5 = (ulong)*(uint *)(param_2 + 0x10);
  }
  else {
    if (cVar1 != '\x02') {
      return 5;
    }
    iVar2 = *(int *)(param_2 + 4);
    uVar6 = *(ulong *)(param_2 + 0x10);
    uVar4 = *(ulong *)(param_2 + 0x20);
    uVar5 = *(ulong *)(param_2 + 0x18);
  }
  if (iVar2 != 8) {
    if ((code *)param_1[2] != elfSimpleAccess) {
      lVar3 = (*(code *)param_1[2])();
      *param_3 = lVar3;
      *param_4 = lVar3 + uVar4;
      return 0;
    }
    lVar3 = *param_1 + uVar5;
    if ((ulong)param_1[1] < uVar4 + uVar5) {
      lVar3 = 0;
    }
    *param_3 = lVar3;
    *param_4 = lVar3 + uVar4;
    return 0;
  }
  lVar3 = LibosElfMapVirtual(param_1,uVar6);
  *param_3 = lVar3;
  *param_4 = lVar3 + uVar4;
  return 0;
}


// ===== 00525a70 LibosElfMapVirtualString =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

long LibosElfMapVirtualString(long *param_1,long param_2,char param_3)

{
  long lVar1;
  long lVar2;
  
  lVar2 = 0;
  while( true ) {
    lVar1 = LibosElfProgramHeaderForRange(param_1,param_2,lVar2 + param_2);
    if (lVar1 == 0) {
      lVar1 = param_2;
      if (param_3 != '\0') {
        lVar1 = LibosElfFindSectionByAddress(param_1);
        if (lVar1 == 0) {
          return 0;
        }
        if (*(char *)(*param_1 + 4) == '\x01') {
          lVar1 = ((ulong)*(uint *)(lVar1 + 0x10) - (ulong)*(uint *)(lVar1 + 0xc)) + param_2;
        }
        else {
          if (*(char *)(*param_1 + 4) != '\x02') {
            return 0;
          }
          lVar1 = (*(long *)(lVar1 + 0x18) + param_2) - *(long *)(lVar1 + 0x10);
        }
      }
    }
    else if (*(char *)(*param_1 + 4) == '\x01') {
      lVar1 = ((ulong)*(uint *)(lVar1 + 4) - (ulong)*(uint *)(lVar1 + 8)) + param_2;
    }
    else {
      if (*(char *)(*param_1 + 4) != '\x02') {
        return 0;
      }
      lVar1 = (*(long *)(lVar1 + 8) + param_2) - *(long *)(lVar1 + 0x10);
    }
    lVar2 = lVar2 + 1;
    if ((code *)param_1[2] == elfSimpleAccess) {
      if ((ulong)param_1[1] < (ulong)(lVar2 + lVar1)) {
        return 0;
      }
      lVar1 = lVar1 + *param_1;
    }
    else {
      lVar1 = (*(code *)param_1[2])(param_1,lVar1,lVar2);
    }
    if (lVar1 == 0) break;
    if (*(char *)(lVar1 + lVar2) == '\0') {
      return lVar1;
    }
  }
  return 0;
}


// ===== 00525bc0 states_init =====

void states_init(void)

{
  states._34_2_ = 0xa11;
  states[0x34] = 0xb;
  states[0x37] = 0xb;
  states[0x17] = 0xb;
  states[2] = 10;
  states[0x12] = 9;
  states[0x20] = 0x18;
  states[0x2b] = 1;
  states._44_4_ = 0x180b0919;
  states._39_2_ = 0xa03;
  states[0xb] = 5;
  states[0x39] = 6;
  states[0x29] = 7;
  states._50_2_ = 0x609;
  states[0x62] = 0xd;
  states[0x6e] = 0xe;
  states[0x71] = 0xe;
  states[0x51] = 0xe;
  states._92_2_ = 0xd0a;
  states[0x6c] = 9;
  states._103_2_ = 0xe09;
  states[0x65] = 2;
  states[0x97] = 0x13;
  states[0x9c] = 0x13;
  states[0xa8] = 0xc;
  states[0xab] = 0xc;
  states[0x8b] = 0xc;
  states._161_2_ = 0xc09;
  states[0xd1] = 0xf;
  states[0xe2] = 0x10;
  states[0xe5] = 0x10;
  states[0xc5] = 0x10;
  states._219_2_ = 0x1009;
  states._393_2_ = 0x1409;
  states._213_2_ = 0xf04;
  states[0x10b] = 0x11;
  states[0x110] = 0x11;
  states[0x11c] = 0x12;
  states[0x11f] = 0x12;
  states[0xff] = 0x12;
  states._277_2_ = 0x1209;
  states[0x14f] = 9;
  states[0x17f] = 0x17;
  states[0x184] = 0x17;
  states[400] = 0x14;
  states[0x193] = 0x14;
  states[0x173] = 0x14;
  states[0x1b9] = 0x15;
  states[0x1be] = 0x15;
  states[0x1ca] = 0x16;
  states[0x1cd] = 0x16;
  states[0x1ad] = 0x16;
  states._451_2_ = 0x1609;
  return;
}


// ===== 00525d80 s_getSymbolDataStr =====

uint s_getSymbolDataStr(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                       byte param_5)

{
  char cVar1;
  uint uVar2;
  undefined *puVar3;
  undefined8 uVar4;
  int iVar5;
  undefined *local_70;
  undefined8 local_68;
  long local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined1 local_48 [8];
  undefined1 local_40 [16];
  
  local_60 = 0;
  local_58 = 0;
  cVar1 = LibosDebugResolveSymbolToName(param_1,param_4,&local_60,&local_58);
  if (cVar1 == '\0') {
    local_60 = 0;
  }
  uVar2 = LibosDwarfResolveLine(param_1,param_4,&local_70,&local_68,&local_50,local_48,local_40);
  if ((char)uVar2 == '\0') {
    if (local_60 == 0) {
      uVar4 = portStringCopy(param_2,param_3,&DAT_00dae542,param_3);
    }
    else {
      uVar4 = nvDbgSnprintf(param_2,(int)param_3 + -1,"%s+%lld",local_60,local_58);
    }
  }
  else {
    iVar5 = (int)param_3 + -1;
    if (local_60 == 0) {
      uVar4 = nvDbgSnprintf(param_2,iVar5,"??? (%s:%lld)",local_68);
    }
    else {
      puVar3 = &DAT_00dae513;
      if ((param_5 & local_70 != (undefined *)0x0) == 0) {
        puVar3 = &DAT_00dae515;
        local_70 = &DAT_00dae515;
      }
      uVar4 = nvDbgSnprintf(param_2,iVar5,"%s+%lld (%s%s%s:%lld)",local_60,local_58,local_70,puVar3,
                            local_68,local_50);
    }
  }
  return (uint)CONCAT71((int7)((ulong)uVar4 >> 8),local_60 != 0) | uVar2;
}


// ===== 00525ed0 _libosLogInitLogBuffer.part.0 =====

void _libosLogInitLogBuffer_part_0(long param_1)

{
  char cVar1;
  long lVar2;
  
  LibosElfImageConstruct(param_1 + 0x88);
  LibosDebugResolverConstruct(param_1 + 0xa0,param_1 + 0x88);
  lVar2 = LibosElfFindSectionByName(param_1 + 0x88,".logging_metadata");
  if (lVar2 == 0) {
    lVar2 = LibosElfFindSectionByName(param_1 + 0x88,".logging");
    if (lVar2 == 0) {
      return;
    }
  }
  cVar1 = LibosElfGetClass(param_1 + 0x88);
  if (cVar1 != '\x01') {
    *(undefined8 *)(param_1 + 0x1c8) = *(undefined8 *)(lVar2 + 0x10);
    *(undefined8 *)(param_1 + 0x1d0) = *(undefined8 *)(lVar2 + 0x20);
    return;
  }
  *(ulong *)(param_1 + 0x1c8) = (ulong)*(uint *)(lVar2 + 0xc);
  *(ulong *)(param_1 + 0x1d0) = (ulong)*(uint *)(lVar2 + 0x14);
  return;
}


// ===== 00525fa0 libosLogInitLogBuffer =====

void libosLogInitLogBuffer(long param_1,undefined8 param_2,long param_3,long param_4)

{
  long lVar1;
  long local_28;
  long local_20;
  
  if (param_3 != 0) {
    portStringCopy(param_1 + 0x2c,8,param_3,8);
  }
  if (param_4 != 0) {
    portStringCopy(param_1 + 0x34,0x20,param_4,0x20);
  }
  local_28 = 0;
  local_20 = 0;
  lVar1 = LibosElfFindSectionByName(param_2,param_1 + 0x34);
  if (lVar1 != 0) {
    LibosElfMapSection(param_2,lVar1,&local_28,&local_20);
    *(long *)(param_1 + 0x80) = local_28;
    if (local_28 != 0) {
      _libosLogInitLogBuffer_part_0(param_1,local_28,local_20 - local_28);
    }
  }
  return;
}


// ===== 00526060 libosExtractLog_ReadRecord =====

void libosExtractLog_ReadRecord(long param_1,long *param_2)

{
  long *plVar1;
  ulong uVar2;
  ulong *puVar3;
  char cVar4;
  int iVar5;
  long *plVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  
  uVar11 = param_2[2];
  uVar15 = param_2[4];
  if (uVar11 != uVar15) {
    uVar2 = ((ulong)param_2[1] >> 3) - 1;
    do {
      if (param_2[0x10] == 0) break;
      if (uVar2 + uVar11 < (ulong)param_2[3]) {
        uVar11 = param_2[3] - uVar2;
      }
      if (*(char *)(param_1 + 0xf80) == '\0') {
        if (uVar15 < uVar11 + 1) goto LAB_005262a7;
        uVar15 = uVar15 - 1;
        param_2[0x23] = *(long *)(*param_2 + 8 + (uVar15 % uVar2) * 8);
      }
      else {
        param_2[0x23] = -1;
      }
      if (uVar15 < uVar11 + 1) goto LAB_005262a7;
      uVar15 = uVar15 - 1;
      puVar3 = (ulong *)(*param_2 + 8 + (uVar15 % uVar2) * 8);
      uVar9 = param_2[0x39];
      uVar12 = *puVar3;
      if ((((*(uint *)(param_2 + 0xc) < 2) || ((*(byte *)((long)param_2 + 100) & 1) == 0)) ||
          ((uVar12 & 0xfe000000000000) == 0)) || (0x16 < (byte)(uVar12 >> 0x30))) {
        uVar10 = *puVar3;
        cVar4 = '\0';
        uVar14 = 0;
        uVar13 = 0;
        if (uVar9 <= uVar10) goto LAB_00526160;
LAB_005262f1:
        param_2[0x22] = 0;
        param_2[0x20] = (long)param_2;
        param_2[0x24] = uVar14;
LAB_0052630a:
        if ((*(char *)(param_1 + 0xf80) != '\0') || (cVar4 == '\0')) {
LAB_0052632f:
          nv_printf(3,
                    "**** Bad metadata.  Lost %lld entries from GPU %d %s-%s. putIter: 0x%llx previousPut: 0x%llx ****\n"
                    ,param_2[4] - uVar11,(int)param_2[5],param_1,(long)param_2 + 0x2c,param_2[4],
                    param_2[2]);
          goto LAB_0052635c;
        }
      }
      else {
        uVar13 = uVar12 >> 0x30 & 0xff;
        uVar14 = uVar12 >> 0x38;
        uVar10 = (uVar12 & 0xffffffffffff) + uVar9;
        cVar4 = (char)(uVar12 >> 0x38);
        if (uVar10 < uVar9) goto LAB_005262f1;
LAB_00526160:
        if (uVar9 + param_2[0x3a] <= uVar10) goto LAB_005262f1;
        plVar1 = param_2 + 0x11;
        plVar6 = (long *)LibosElfMapVirtual(plVar1,uVar10,0x18);
        if (plVar6 == (long *)0x0) goto LAB_005262f1;
        lVar7 = LibosElfMapVirtualString(plVar1,*plVar6,1);
        if (lVar7 == 0) {
          lVar7 = 0;
          if (*plVar6 == -0x8000000000000000) {
            lVar8 = LibosElfMapVirtual(plVar1,uVar10,0x28);
            if (lVar8 == 0) goto LAB_005262f1;
            plVar6 = (long *)(lVar8 + 0x10);
            lVar7 = 0;
            if (*(long *)(lVar8 + 8) != 0) {
              lVar7 = LibosElfMapVirtualString(plVar1,*(long *)(lVar8 + 8),1);
            }
          }
        }
        else {
          lVar7 = 0;
        }
        param_2[0x22] = (long)plVar6;
        param_2[0x20] = (long)param_2;
        param_2[0x24] = uVar14;
        if (0x14 < *(byte *)((long)plVar6 + 0x14)) goto LAB_0052630a;
        if ((cVar4 == '\0') || ((uint)*(byte *)((long)plVar6 + 0x14) == (int)uVar13 - 2U)) {
          param_2[0x21] = (long)param_2;
          if ((lVar7 == 0) || (*(long *)(param_1 + 8) == 0)) goto LAB_005264a9;
          uVar9 = 0;
          goto LAB_00526461;
        }
        if (*(char *)(param_1 + 0xf80) != '\0') goto LAB_0052632f;
      }
      nv_printf(3,
                "**** Bad metadata.  Lost %lld entries from GPU %d %s-%s. putIter: 0x%llx previousPut: 0x%llx ****\n"
                ,uVar13,(int)param_2[5],param_1,(long)param_2 + 0x2c,param_2[4],param_2[2]);
      uVar15 = param_2[4] - uVar13;
      param_2[4] = uVar15;
    } while (param_2[2] != uVar15);
  }
  param_2[0x23] = 0;
  return;
  while (uVar9 = (ulong)((int)uVar9 + 1), uVar9 < *(ulong *)(param_1 + 8)) {
LAB_00526461:
    iVar5 = portStringCompare(param_1 + 0x44 + uVar9 * 0x1d8,lVar7,0x20);
    if (iVar5 == 0) {
      lVar7 = param_1 + 0x10 + uVar9 * 0x1d8;
      if (*(long *)(lVar7 + 0x80) != 0) {
        param_2[0x21] = lVar7;
      }
      break;
    }
  }
LAB_005264a9:
  uVar9 = (ulong)*(byte *)(param_2[0x22] + 0x14);
  if (uVar15 < uVar11 + uVar9) {
LAB_005262a7:
    nv_printf(3,"**** Buffer wrapped. Lost %lld entries from GPU %d %s-%s ****\n",
              param_2[4] - param_2[2],(int)param_2[5],param_1,(long)param_2 + 0x2c);
LAB_0052635c:
    param_2[0x23] = 0;
  }
  else {
    uVar11 = uVar15;
    if (uVar9 != 0) {
      lVar7 = *param_2;
      uVar12 = uVar15;
      do {
        uVar10 = uVar12 - 1;
        param_2[uVar9 + ((uVar12 + 0x24) - uVar15)] = *(long *)(lVar7 + 8 + (uVar10 % uVar2) * 8);
        uVar11 = uVar15 - uVar9;
        uVar12 = uVar10;
      } while (uVar10 != uVar15 - uVar9);
    }
    param_2[4] = uVar11;
  }
  return;
}


// ===== 00526550 emit_string =====

void emit_string(char *param_1,uint param_2,long param_3)

{
  char *pcVar1;
  byte bVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  byte bVar6;
  
  if ((int)param_2 < 1) {
    return;
  }
  pcVar1 = (char *)(param_3 + 0xf00);
  pcVar5 = param_1;
  do {
    if (*pcVar5 == '\0') {
      return;
    }
    pcVar4 = *(char **)(param_3 + 0xef8);
    pcVar3 = pcVar4;
    if (((char *)(param_3 + 0xf7f) <= pcVar4) && (pcVar3 = pcVar1, pcVar4 != pcVar1)) {
      bVar2 = *(byte *)(param_3 + 0xf82);
      *pcVar4 = '\0';
      bVar6 = 6;
      if ((bVar2 < 7) && (bVar6 = bVar2, bVar2 == 2)) {
        bVar6 = 3;
      }
      nv_printf(bVar6,&DAT_00dae60f,pcVar1);
    }
    pcVar4 = pcVar5 + 1;
    *(char **)(param_3 + 0xef8) = pcVar3 + 1;
    *pcVar3 = *pcVar5;
    pcVar5 = pcVar4;
  } while (param_1 + param_2 != pcVar4);
  return;
}


// ===== 00526620 pad =====

void pad(undefined1 param_1,int param_2,int param_3,uint param_4,long param_5)

{
  undefined1 *puVar1;
  byte bVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  byte bVar5;
  
  if (((param_4 & 0x12000) == 0) && (param_3 < param_2)) {
    puVar1 = (undefined1 *)(param_5 + 0xf00);
    param_2 = param_2 - param_3;
    do {
      puVar3 = *(undefined1 **)(param_5 + 0xef8);
      puVar4 = puVar3;
      if (((undefined1 *)(param_5 + 0xf7f) <= puVar3) && (puVar4 = puVar1, puVar3 != puVar1)) {
        bVar2 = *(byte *)(param_5 + 0xf82);
        *puVar3 = 0;
        bVar5 = 6;
        if ((bVar2 < 7) && (bVar5 = bVar2, bVar2 == 2)) {
          bVar5 = 3;
        }
        nv_printf(bVar5,&DAT_00dae60f,puVar1);
      }
      *(undefined1 **)(param_5 + 0xef8) = puVar4 + 1;
      *puVar4 = param_1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    return;
  }
  return;
}


// ===== 005266e0 libosPreserveLogs =====

void libosPreserveLogs(long param_1,char param_2,char param_3)

{
  uint *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  long lVar4;
  byte *pbVar5;
  ulong uVar6;
  uint uVar7;
  
  if (*(long *)(param_1 + 8) == 0) {
    return;
  }
  pbVar5 = (byte *)(param_1 + 100);
  uVar6 = 0;
  do {
    if ((*pbVar5 & 1) == 0) {
      if ((pbVar5[0x1d] != 0) && (param_2 != '\0')) {
        if ((*(uint *)(pbVar5 + 0x14) == 0) ||
           ((&PTR__nvlogZeroBuffer_00594988)[*(uint *)(pbVar5 + 0x14)] == (undefined *)0x0))
        goto LAB_005267f0;
        puVar1 = (uint *)((&PTR__nvlogZeroBuffer_00594988)[*(uint *)(pbVar5 + 0x14)] + 0x10);
        *puVar1 = *puVar1 | 0x800;
      }
      if (((param_3 != '\0') &&
          (puVar2 = (&PTR__nvlogZeroBuffer_00594988)[*(uint *)(pbVar5 + 0x18)],
          *(uint *)(pbVar5 + 0x18) != 0)) && (puVar2 != (undefined *)0x0)) {
        uVar7 = *(uint *)(puVar2 + 0x10);
        lVar4 = 0;
        do {
          puVar3 = (&PTR__nvlogZeroBuffer_00594988)[lVar4];
          if ((puVar3 != (undefined *)0x0) && (*(int *)(puVar2 + 0xc) == *(int *)(puVar3 + 0xc))) {
            if ((uVar7 >> 0x18 == *(uint *)(puVar3 + 0x10) >> 0x18) &&
               ((*(uint *)(puVar3 + 0x10) & 0x800) != 0)) {
              nvlogDeallocBuffer(lVar4,1);
              uVar7 = *(uint *)(puVar2 + 0x10);
              break;
            }
          }
          lVar4 = lVar4 + 1;
        } while (lVar4 != 0xf00);
        *(uint *)(puVar2 + 0x10) = uVar7 | 0x800;
      }
    }
LAB_005267f0:
    uVar6 = uVar6 + 1;
    pbVar5 = pbVar5 + 0x1d8;
    if (*(ulong *)(param_1 + 8) <= uVar6) {
      return;
    }
  } while( true );
}


// ===== 00526840 libosLogCreate =====

void libosLogCreate(undefined8 param_1)

{
  states_init();
  portMemSet(param_1,0,0x21f8);
  portStringCopy(param_1,4,&DAT_00dae612,4);
  return;
}


// ===== 00526890 libosLogCreateEx =====

void libosLogCreateEx(undefined8 param_1,undefined8 param_2)

{
  states_init();
  portMemSet(param_1,0,0x21f8);
  portStringCopy(param_1,4,param_2,4);
  return;
}


// ===== 00526900 libosLogSetupMergedNvlog =====

void libosLogSetupMergedNvlog
               (byte *param_1,uint param_2,long param_3,long param_4,undefined4 param_5,
               undefined4 param_6,uint *param_7)

{
  undefined *puVar1;
  int iVar2;
  ulong uVar3;
  byte *pbVar4;
  undefined8 uVar5;
  uint uVar6;
  ulong uVar7;
  byte *pbVar8;
  long lVar9;
  uint uVar10;
  uint local_40;
  uint local_3c [3];
  
  if (param_3 == 0) {
    return;
  }
  if (*(long *)(param_1 + 0xed0) == 0) {
    uVar5 = portMemAllocNonPaged(param_3);
    *(long *)(param_1 + 0xed8) = param_3;
    *(undefined8 *)(param_1 + 0xed0) = uVar5;
  }
  local_40 = 0;
  lVar9 = *(long *)(param_1 + 8);
  local_3c[0] = 0;
  uVar7 = lVar9 * 2;
  uVar10 = (uint)param_1[1] << 0x10 | (uint)*param_1 << 8 | (int)(char)param_1[2] << 0x18;
  uVar6 = (int)lVar9 * 2 + 0x58;
  if (uVar7 < 9) {
    uVar6 = (int)lVar9 * 2 + 0x31;
  }
  uVar3 = 0;
  uVar6 = uVar6 & 0xff | uVar10;
  do {
    puVar1 = (&PTR__nvlogZeroBuffer_00594988)[uVar3];
    if ((puVar1 != (undefined *)0x0) && (uVar6 == *(uint *)(puVar1 + 0xc))) {
      if ((param_2 == *(uint *)(puVar1 + 0x10) >> 0x18) && ((*(uint *)(puVar1 + 0x10) & 0x800) != 0)
         ) {
        local_40 = (uint)uVar3;
        uVar3 = (ulong)*(uint *)((&PTR__nvlogZeroBuffer_00594988)[uVar3 & 0xffffffff] + 0x14);
        goto LAB_00526a11;
      }
    }
    uVar3 = uVar3 + 1;
    if (uVar3 == 0xf00) {
      iVar2 = nvlogAllocBuffer((int)param_3 + 0x48,param_2 << 0x18 | 0x192,uVar6,&local_40);
      if (iVar2 == 0) {
        puVar1 = (&PTR__nvlogZeroBuffer_00594988)[local_40];
        if (param_4 != 0) {
          portStringCopy(puVar1 + 0x30,8,param_4,8);
        }
        *(undefined4 *)(puVar1 + 0x28) = 2;
        *(undefined4 *)(puVar1 + 0x60) = 3;
        *(undefined4 *)(puVar1 + 0x20) = param_5;
        *(undefined4 *)(puVar1 + 0x24) = param_6;
        if (param_7 != (uint *)0x0) {
          *(uint *)(puVar1 + 0x2c) = param_7[1];
          portMemCopy(puVar1 + 0x40,0x20,(long)param_7 + (ulong)*param_7 + 0xc);
        }
        *(undefined4 *)((&PTR__nvlogZeroBuffer_00594988)[local_40] + 0x14) = 0x50;
      }
      else {
        nv_printf(4,"nvlogAllocBuffer nowrap failed\n");
      }
      uVar3 = 0;
      lVar9 = *(long *)(param_1 + 8);
      uVar7 = lVar9 * 2;
      uVar10 = (uint)param_1[1] << 0x10 | (uint)*param_1 << 8 | (int)(char)param_1[2] << 0x18;
LAB_00526a11:
      uVar6 = (int)lVar9 * 2 + 0x59;
      if (uVar7 + 1 < 9) {
        uVar6 = (int)lVar9 * 2 + 0x32;
      }
      iVar2 = nvlogAllocBuffer((int)param_3 + 0x48,param_2 << 0x18 | 400,uVar6 & 0xff | uVar10,
                               local_3c);
      if (iVar2 == 0) {
        puVar1 = (&PTR__nvlogZeroBuffer_00594988)[local_3c[0]];
        if (param_4 != 0) {
          portStringCopy(puVar1 + 0x30,8,param_4,8);
        }
        *(undefined4 *)(puVar1 + 0x28) = 2;
        *(undefined4 *)(puVar1 + 0x60) = 3;
        *(undefined4 *)(puVar1 + 0x20) = param_5;
        *(undefined4 *)(puVar1 + 0x24) = param_6;
        if (param_7 != (uint *)0x0) {
          *(uint *)(puVar1 + 0x2c) = param_7[1];
          portMemCopy(puVar1 + 0x40,0x20,(long)param_7 + (ulong)*param_7 + 0xc);
        }
        *(undefined4 *)((&PTR__nvlogZeroBuffer_00594988)[local_3c[0]] + 0x14) = 0x50;
      }
      else {
        nv_printf(4,"nvlogAllocBuffer wrap failed\n");
      }
      if (*(long *)(param_1 + 8) != 0) {
        pbVar8 = param_1 + 0x74;
        pbVar4 = pbVar8 + *(long *)(param_1 + 8) * 0x1d8;
        do {
          if ((*pbVar8 & 2) != 0) {
            *(ulong *)(pbVar8 + 4) = CONCAT44(local_3c[0],local_40);
            uVar7 = 0x50;
            if (uVar3 != 0) {
              uVar7 = uVar3;
            }
            pbVar8[0xc] = 1;
            *(ulong *)(pbVar8 + 0x14) = uVar7;
          }
          pbVar8 = pbVar8 + 0x1d8;
        } while (pbVar8 != pbVar4);
      }
      return;
    }
  } while( true );
}


// ===== 00526c80 libosLogAddLogEx =====

void libosLogAddLogEx(byte *param_1,undefined8 param_2,undefined8 param_3,uint param_4,
                     undefined4 param_5,undefined4 param_6,long param_7,long param_8,
                     undefined4 param_9,uint *param_10,uint param_11,int param_12)

{
  byte *pbVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  uint uVar6;
  long lVar7;
  uint uVar8;
  long lVar9;
  ulong uVar10;
  int local_48;
  
  uVar5 = *(ulong *)(param_1 + 8);
  if (7 < uVar5) {
    nv_printf(4,"LIBOS_LOG_DECODE::log array is too small. Increase LIBOS_LOG_MAX_LOGS.\n");
    return;
  }
  if ((param_11 < 2) && (param_12 != 0)) {
    nvAssertFailedNoLog("libosLogNvlogBufferVersion >= LIBOS_LOG_NVLOG_BUFFER_VERSION_2 || libosLogFlags == 0"
                        ,"../common/uproc/os/libos-v3.1.0/lib/liblogdecode.c",0x83f);
    uVar5 = *(ulong *)(param_1 + 8);
  }
  uVar10 = uVar5 & 0xffffffff;
  lVar9 = (uVar5 & 0xffffffff) * 0x1d8;
  *(ulong *)(param_1 + 8) = uVar5 + 1;
  *(undefined8 *)(param_1 + lVar9 + 0x10) = param_2;
  pbVar1 = param_1 + lVar9 + 0x20;
  pbVar1[0] = 0;
  pbVar1[1] = 0;
  pbVar1[2] = 0;
  pbVar1[3] = 0;
  pbVar1[4] = 0;
  pbVar1[5] = 0;
  pbVar1[6] = 0;
  pbVar1[7] = 0;
  *(undefined8 *)(param_1 + lVar9 + 0x18) = param_3;
  pbVar1 = param_1 + lVar9 + 0x28;
  pbVar1[0] = 0;
  pbVar1[1] = 0;
  pbVar1[2] = 0;
  pbVar1[3] = 0;
  pbVar1[4] = 0;
  pbVar1[5] = 0;
  pbVar1[6] = 0;
  pbVar1[7] = 0;
  pbVar1 = param_1 + lVar9 + 0x30;
  pbVar1[0] = 0;
  pbVar1[1] = 0;
  pbVar1[2] = 0;
  pbVar1[3] = 0;
  pbVar1[4] = 0;
  pbVar1[5] = 0;
  pbVar1[6] = 0;
  pbVar1[7] = 0;
  *(undefined4 *)(param_1 + lVar9 + 100) = param_9;
  *(int *)(param_1 + lVar9 + 0x74) = param_12;
  *(uint *)(param_1 + lVar9 + 0x70) = param_11;
  *(uint *)(param_1 + lVar9 + 0x38) = param_4;
  if (param_7 != 0) {
    portStringCopy(param_1 + lVar9 + 0x3c,8,param_7,8);
  }
  if (param_8 == 0) {
    portStringCopy(param_1 + lVar9 + 0x44,0x20,"default");
  }
  else {
    portStringCopy(param_1 + lVar9 + 0x44,0x20,param_8);
  }
  lVar7 = uVar10 * 0x1d8;
  if (((param_1[lVar7 + 100] & 1) == 0) && ((param_1[lVar7 + 0x74] & 2) == 0)) {
    iVar3 = (int)uVar5;
    pbVar1 = param_1 + lVar7 + 0x78;
    pbVar1[0] = 0;
    pbVar1[1] = 0;
    pbVar1[2] = 0;
    pbVar1[3] = 0;
    pbVar1[4] = 0;
    pbVar1[5] = 0;
    pbVar1[6] = 0;
    pbVar1[7] = 0;
    (param_1 + lVar7 + 0x80)[0] = 0;
    (param_1 + lVar7 + 0x80)[1] = 0;
    pbVar1 = param_1 + lVar7 + 0x88;
    pbVar1[0] = 0x50;
    pbVar1[1] = 0;
    pbVar1[2] = 0;
    pbVar1[3] = 0;
    pbVar1[4] = 0;
    pbVar1[5] = 0;
    pbVar1[6] = 0;
    pbVar1[7] = 0;
    uVar8 = (uint)param_1[1] << 0x10 | (uint)*param_1 << 8 | (int)(char)param_1[2] << 0x18;
    uVar6 = iVar3 * 2 + 0x58;
    if ((uint)(iVar3 * 2) < 9) {
      uVar6 = iVar3 * 2 + 0x31;
    }
    uVar5 = 0;
    uVar6 = uVar6 & 0xff | uVar8;
    do {
      puVar2 = (&PTR__nvlogZeroBuffer_00594988)[uVar5];
      local_48 = (int)param_3;
      if ((((puVar2 != (undefined *)0x0) && (uVar6 == *(uint *)(puVar2 + 0xc))) &&
          (param_4 == *(uint *)(puVar2 + 0x10) >> 0x18)) &&
         ((*(uint *)(puVar2 + 0x10) & 0x800) != 0)) {
        lVar7 = uVar10 * 0x1d8;
        *(int *)(param_1 + lVar7 + 0x78) = (int)uVar5;
        param_1[lVar7 + 0x80] = 1;
        *(ulong *)(param_1 + lVar7 + 0x88) =
             (ulong)*(uint *)((&PTR__nvlogZeroBuffer_00594988)[uVar5 & 0xffffffff] + 0x14);
        goto LAB_00526ea6;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 != 0xf00);
    iVar4 = nvlogAllocBuffer(local_48 + 0x48,param_4 << 0x18 | 0x192,uVar6,param_1 + lVar9 + 0x78);
    if (iVar4 == 0) {
      puVar2 = (&PTR__nvlogZeroBuffer_00594988)[*(uint *)(param_1 + uVar10 * 0x1d8 + 0x78)];
      if (param_7 != 0) {
        portStringCopy(puVar2 + 0x30,8,param_7,8);
      }
      *(undefined4 *)(puVar2 + 0x28) = 2;
      *(undefined4 *)(puVar2 + 0x20) = param_5;
      *(undefined4 *)(puVar2 + 0x24) = param_6;
      *(int *)(puVar2 + 0x60) = param_12;
      if (param_10 != (uint *)0x0) {
        *(uint *)(puVar2 + 0x2c) = param_10[1];
        portMemCopy(puVar2 + 0x40,0x20,(long)param_10 + (ulong)*param_10 + 0xc);
      }
      *(undefined4 *)
       ((&PTR__nvlogZeroBuffer_00594988)[*(uint *)(param_1 + uVar10 * 0x1d8 + 0x78)] + 0x14) = 0x50;
      param_1[uVar10 * 0x1d8 + 0x80] = 1;
      uVar8 = (uint)param_1[1] << 0x10 | (uint)*param_1 << 8 | (int)(char)param_1[2] << 0x18;
    }
    else {
      nv_printf(4,"nvlogAllocBuffer nowrap failed\n");
      uVar8 = (uint)param_1[1] << 0x10 | (uint)*param_1 << 8 | (int)(char)param_1[2] << 0x18;
    }
LAB_00526ea6:
    uVar6 = iVar3 * 2 + 0x59;
    if (iVar3 * 2 + 1U < 9) {
      uVar6 = iVar3 * 2 + 0x32;
    }
    iVar3 = nvlogAllocBuffer(local_48 + 0x48,param_4 << 0x18 | 400,uVar6 & 0xff | uVar8,
                             param_1 + lVar9 + 0x7c);
    if (iVar3 != 0) {
      nv_printf(4,"nvlogAllocBuffer wrap failed\n");
      return;
    }
    puVar2 = (&PTR__nvlogZeroBuffer_00594988)[*(uint *)(param_1 + uVar10 * 0x1d8 + 0x7c)];
    if (param_7 != 0) {
      portStringCopy(puVar2 + 0x30,8,param_7,8);
    }
    *(undefined4 *)(puVar2 + 0x28) = 2;
    *(undefined4 *)(puVar2 + 0x20) = param_5;
    *(undefined4 *)(puVar2 + 0x24) = param_6;
    *(int *)(puVar2 + 0x60) = param_12;
    if (param_10 != (uint *)0x0) {
      *(uint *)(puVar2 + 0x2c) = param_10[1];
      portMemCopy(puVar2 + 0x40,0x20,(long)param_10 + (ulong)*param_10 + 0xc);
    }
    *(undefined4 *)
     ((&PTR__nvlogZeroBuffer_00594988)[*(uint *)(param_1 + uVar10 * 0x1d8 + 0x7c)] + 0x14) = 0x50;
  }
  return;
}


// ===== 005271a0 libosLogInit =====

void libosLogInit(long param_1,long param_2,ulong param_3)

{
  char cVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  long *plVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  undefined1 local_50 [32];
  
  uVar9 = (ulong)(*(char *)(param_1 + 0xf80) == '\0') + 1;
  uVar3 = 0;
  uVar7 = param_3;
  if (*(long *)(param_1 + 8) != 0) {
    plVar6 = (long *)(param_1 + 0x18);
    lVar5 = 0;
    plVar2 = plVar6 + *(long *)(param_1 + 8) * 0x3b;
    do {
      lVar5 = lVar5 + *plVar6;
      plVar6 = plVar6 + 0x3b;
    } while (plVar6 != plVar2);
    uVar3 = (ulong)(lVar5 * 5) / uVar9;
    uVar7 = (ulong)(lVar5 * 5) % uVar9;
  }
  uVar4 = portMemAllocNonPaged(uVar3,uVar9,uVar7);
  *(ulong *)(param_1 + 0xef0) = uVar3;
  *(undefined8 *)(param_1 + 0xee8) = uVar4;
  *(long *)(param_1 + 0xef8) = param_1 + 0xf00;
  if ((param_2 == 0) || (cVar1 = LibosElfImageConstruct(local_50,param_2,param_3), cVar1 != '\0')) {
    *(undefined1 *)(param_1 + 0xee0) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0xee0) = 1;
    lVar5 = LibosElfFindSectionByName(local_50,".fwIsContainerElf");
    if (*(long *)(param_1 + 8) != 0) {
      lVar8 = param_1 + 0x10;
      if (lVar5 == 0) {
        uVar3 = 0;
        while( true ) {
          *(long *)(lVar8 + 0x80) = param_2;
          uVar3 = uVar3 + 1;
          _libosLogInitLogBuffer_part_0(lVar8,param_2,param_3);
          if (*(ulong *)(param_1 + 8) <= uVar3) break;
          lVar8 = lVar8 + 0x1d8;
        }
      }
      else {
        uVar3 = 0;
        while( true ) {
          libosLogInitLogBuffer(lVar8,local_50,0,0);
          uVar3 = uVar3 + 1;
          if (*(ulong *)(param_1 + 8) <= uVar3) break;
          lVar8 = lVar8 + 0x1d8;
        }
      }
    }
  }
  return;
}


// ===== 00527300 libosLogInitEx =====

void libosLogInitEx(long param_1,undefined8 param_2,undefined1 param_3,undefined1 param_4,
                   undefined1 param_5,undefined8 param_6)

{
  *(undefined1 *)(param_1 + 0xf80) = param_3;
  *(undefined1 *)(param_1 + 0xf81) = param_4;
  *(undefined1 *)(param_1 + 0xf83) = param_5;
  libosLogInit(param_1,param_2,param_6);
  return;
}


// ===== 00527340 libosLogUpdateTimerDelta =====

void libosLogUpdateTimerDelta(long param_1,undefined8 param_2)

{
  undefined *puVar1;
  byte *pbVar2;
  ulong uVar3;
  
  if (*(long *)(param_1 + 8) != 0) {
    pbVar2 = (byte *)(param_1 + 100);
    uVar3 = 0;
    do {
      if ((*pbVar2 & 1) == 0) {
        puVar1 = (&PTR__nvlogZeroBuffer_00594988)[*(uint *)(pbVar2 + 0x18)];
        *(undefined8 *)((&PTR__nvlogZeroBuffer_00594988)[*(uint *)(pbVar2 + 0x14)] + 0x38) = param_2
        ;
        *(undefined8 *)(puVar1 + 0x38) = param_2;
        *(undefined8 *)(pbVar2 + 4) = param_2;
      }
      uVar3 = uVar3 + 1;
      pbVar2 = pbVar2 + 0x1d8;
    } while (uVar3 < *(ulong *)(param_1 + 8));
  }
  return;
}


// ===== 005273c0 libosLogDestroy =====

void libosLogDestroy(long param_1)

{
  int iVar1;
  ulong uVar2;
  byte *pbVar3;
  ulong uVar4;
  long lVar5;
  
  if (*(long *)(param_1 + 8) == 0) {
    if (*(long *)(param_1 + 0xed0) == 0) goto LAB_0052749a;
LAB_0052744d:
    portMemFree();
    uVar2 = *(ulong *)(param_1 + 8);
    *(undefined8 *)(param_1 + 0xed0) = 0;
    *(undefined8 *)(param_1 + 0xed8) = 0;
  }
  else {
    pbVar3 = (byte *)(param_1 + 100);
    uVar4 = 0;
    do {
      if ((*pbVar3 & 1) == 0) {
        if (*(int *)(pbVar3 + 0x14) == 0) {
          iVar1 = *(int *)(pbVar3 + 0x18);
        }
        else {
          nvlogDeallocBuffer(*(int *)(pbVar3 + 0x14),0);
          iVar1 = *(int *)(pbVar3 + 0x18);
          pbVar3[0x14] = 0;
          pbVar3[0x15] = 0;
          pbVar3[0x16] = 0;
          pbVar3[0x17] = 0;
        }
        if (iVar1 != 0) {
          nvlogDeallocBuffer(iVar1,0);
          pbVar3[0x18] = 0;
          pbVar3[0x19] = 0;
          pbVar3[0x1a] = 0;
          pbVar3[0x1b] = 0;
        }
      }
      uVar2 = *(ulong *)(param_1 + 8);
      uVar4 = uVar4 + 1;
      pbVar3 = pbVar3 + 0x1d8;
    } while (uVar4 < uVar2);
    if (*(long *)(param_1 + 0xed0) != 0) goto LAB_0052744d;
  }
  if (uVar2 != 0) {
    uVar4 = 0;
    lVar5 = param_1 + 0xb0;
    do {
      uVar4 = uVar4 + 1;
      LibosDebugResolverDestroy(lVar5);
      lVar5 = lVar5 + 0x1d8;
    } while (uVar4 < *(ulong *)(param_1 + 8));
  }
LAB_0052749a:
  if (*(long *)(param_1 + 0xee8) != 0) {
    portMemFree();
    *(undefined8 *)(param_1 + 0xee8) = 0;
  }
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined1 *)(param_1 + 0xee0) = 0;
  return;
}


// ===== 00527500 libosExtractLogs =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void libosExtractLogs(long param_1,char param_2)

{
  char *pcVar1;
  byte bVar2;
  ulong uVar3;
  bool bVar4;
  bool bVar5;
  byte bVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  long *plVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  ulong uVar13;
  byte *pbVar14;
  char *pcVar15;
  byte *pbVar16;
  undefined8 uVar17;
  byte *pbVar18;
  ulong uVar19;
  char *pcVar20;
  int iVar21;
  int iVar22;
  uint uVar23;
  ulong uVar24;
  byte *pbVar25;
  char *pcVar26;
  uint uVar27;
  ulong uVar28;
  ulong uVar29;
  long lVar30;
  long lVar31;
  char *pcVar32;
  char cVar33;
  ulong uVar34;
  long *plVar35;
  long *plVar36;
  char *pcVar37;
  long lVar38;
  undefined *puVar39;
  ulong uVar40;
  uint uVar41;
  long lVar42;
  long lVar43;
  bool bVar44;
  ulong local_100;
  ulong local_f8;
  undefined *local_e0;
  byte *local_98;
  ulong local_88;
  ulong local_78;
  byte local_55;
  undefined1 local_54;
  byte local_39 [9];
  
  lVar38 = *(long *)(param_1 + 8);
  if (lVar38 == 0) {
    if (*(char *)(param_1 + 0xee0) == '\0') {
      return;
    }
    uVar34 = *(ulong *)(param_1 + 0xef0);
    uVar13 = 0;
LAB_00527cf3:
    uVar34 = uVar34 >> 3;
    plVar36 = (long *)0x0;
    uVar28 = uVar34;
    while (uVar13 != 0) {
      lVar42 = 0;
      uVar40 = 0;
      lVar38 = param_1 + 0x10;
      do {
        if (uVar40 < *(ulong *)(lVar38 + 0x118)) {
          lVar42 = lVar38;
          uVar40 = *(ulong *)(lVar38 + 0x118);
        }
        lVar38 = lVar38 + 0x1d8;
      } while (uVar13 * 0x1d8 + param_1 + 0x10 != lVar38);
      if (uVar40 == 0) break;
      uVar13 = (ulong)*(byte *)(*(long *)(lVar42 + 0x110) + 0x14) + 5;
      if (((plVar36 == (long *)0x0) || (*(int *)(*plVar36 + 0x28) != *(int *)(lVar42 + 0x28))) ||
         (iVar8 = portMemCmp(plVar36 + 2,lVar42 + 0x110,uVar13 * 8 + -0x10), iVar8 != 0)) {
        if (uVar28 < uVar13) {
          nv_printf(3,"**** scratch buffer overflow.  lost entries ****\n");
          break;
        }
        uVar28 = uVar28 - uVar13;
        portMemCopy(*(long *)(param_1 + 0xee8) + uVar28 * 8,uVar13 * 8,lVar42 + 0x100,uVar13 * 8);
        plVar36 = (long *)(uVar28 * 8 + *(long *)(param_1 + 0xee8));
      }
      libosExtractLog_ReadRecord(param_1,lVar42);
      uVar13 = *(ulong *)(param_1 + 8);
    }
    if (uVar34 != uVar28) {
      lVar38 = *(long *)(param_1 + 0xee8);
      uVar13 = 0;
LAB_00527e20:
      plVar36 = (long *)(lVar38 + (uVar28 + uVar13) * 8);
      if (plVar36[2] == 0) {
        nv_printf(3,"**** Bad metadata.  Lost %lld entries from %s ****\n",
                  (uVar34 - uVar28) - uVar13,param_1);
        lVar38 = *(long *)(param_1 + 8);
        goto LAB_0052786b;
      }
      *(undefined1 *)(param_1 + 0xf82) = *(undefined1 *)(plVar36[2] + 0x15);
      pbVar14 = (byte *)LibosElfMapVirtualString(*plVar36 + 0x88,*(undefined8 *)(plVar36[2] + 8),1);
      if (pbVar14 != (byte *)0x0) {
        pcVar15 = (char *)LibosElfMapVirtualString(*plVar36 + 0x88,*(undefined8 *)plVar36[2],1);
        pcVar32 = "unknown";
        if ((pcVar15 != (char *)0x0) && (pcVar32 = "unknown", *pcVar15 != '\0')) {
          pcVar32 = pcVar15;
        }
        lVar42 = portStringLength(pcVar32);
        do {
          lVar43 = lVar42;
          lVar42 = lVar43 + -1;
          if (lVar42 == 0) goto LAB_00527ef2;
        } while (pcVar32[lVar42] != '/');
        pcVar32 = pcVar32 + lVar43;
LAB_00527ef2:
        bVar4 = false;
        pcVar15 = (char *)(param_1 + 0xf00);
        local_78 = 0;
        pcVar1 = (char *)(param_1 + 0xf7f);
        local_98 = (byte *)0x0;
        uVar40 = (ulong)*(byte *)(plVar36[2] + 0x14);
        bVar5 = false;
LAB_00527f49:
        if (*(char **)(param_1 + 0xef8) == pcVar15) goto LAB_00528296;
LAB_00527f56:
        pbVar25 = pbVar14;
        if (*pbVar14 != 0) {
          do {
            pcVar26 = *(char **)(param_1 + 0xef8);
            if ((pcVar1 <= pcVar26) && (pcVar15 != pcVar26)) {
              bVar6 = *(byte *)(param_1 + 0xf82);
              *pcVar26 = '\0';
              bVar7 = 6;
              if ((bVar6 < 7) && (bVar7 = bVar6, bVar6 == 2)) {
                bVar7 = 3;
              }
              nv_printf(bVar7,&DAT_00dae60f,pcVar15);
              *(char **)(param_1 + 0xef8) = pcVar15;
            }
            if ((!bVar4) && (*pbVar25 == 0x25)) {
              if (pbVar25[1] != 0x25) {
                uVar27 = (uint)pbVar25[1];
                bVar6 = pbVar25[1] - 0x30;
                if (bVar6 < 10) {
                  if (pbVar25[2] == 0x24) {
                    uVar27 = (uint)pbVar25[3];
                    pbVar14 = pbVar25 + 3;
                    bVar5 = true;
                    goto LAB_0052834c;
                  }
                  bVar6 = 0xff;
                  pbVar14 = pbVar25 + 1;
                }
                else {
                  bVar6 = 0xff;
                  pbVar14 = pbVar25 + 1;
LAB_0052834c:
                  if (0x1f < (int)(char)uVar27 - 0x20U) {
                    iVar8 = -1;
                    uVar24 = 0;
                    uVar41 = 0;
                    goto LAB_005281b7;
                  }
                }
                uVar41 = 0;
                goto LAB_005280df;
              }
              pbVar25 = pbVar25 + 1;
            }
            pbVar14 = *(byte **)(param_1 + 0xef8);
            *(byte **)(param_1 + 0xef8) = pbVar14 + 1;
            bVar6 = *pbVar25;
            *pbVar14 = bVar6;
            if (bVar6 == 10) goto LAB_00528220;
            pbVar14 = pbVar25 + 1;
            pbVar25 = pbVar25 + 1;
            if (*pbVar14 == 0) break;
          } while( true );
        }
        goto LAB_005281f1;
      }
    }
LAB_00528216:
    lVar38 = *(long *)(param_1 + 8);
LAB_0052786b:
    if (lVar38 == 0) {
      return;
    }
  }
  else {
    plVar36 = (long *)(param_1 + 0x10);
    plVar10 = plVar36;
    do {
      if ((long *)*plVar10 != (long *)0x0) {
        plVar10[3] = *(long *)*plVar10;
      }
      plVar10 = plVar10 + 0x3b;
    } while (plVar36 + lVar38 * 0x3b != plVar10);
    if (*(char *)(param_1 + 0xee0) != '\0') {
      uVar34 = *(ulong *)(param_1 + 0xef0);
      uVar28 = 0;
      do {
        if (*plVar36 == 0) {
          nv_printf(4,"logDecode->physicLogBuffer is NULL\n");
          lVar38 = *(long *)(param_1 + 8);
          goto LAB_0052786b;
        }
        uVar28 = uVar28 + 1;
        plVar36[4] = plVar36[3];
        libosExtractLog_ReadRecord(param_1,plVar36);
        uVar13 = *(ulong *)(param_1 + 8);
        plVar36 = plVar36 + 0x3b;
      } while (uVar28 < uVar13);
      goto LAB_00527cf3;
    }
  }
  plVar10 = (long *)(param_1 + 0x10);
  uVar34 = 0;
  bVar4 = false;
  plVar36 = plVar10;
  do {
    if ((*(byte *)((long)plVar36 + 0x54) & 1) == 0) {
      if ((*(byte *)((long)plVar36 + 100) & 2) == 0) {
        if ((char)plVar36[0xe] == '\0') {
          puVar39 = (&PTR__nvlogZeroBuffer_00594988)[*(uint *)((long)plVar36 + 0x6c)];
          if (*(uint *)((long)plVar36 + 0x6c) == 0) {
LAB_00527748:
            nvAssertFailedNoLog("(pLog->hNvLogWrap != 0) && (pNvLogBuffer != NULL)",
                                "../common/uproc/os/libos-v3.1.0/lib/liblogdecode.c",0x5d4);
            goto joined_r0x00527764;
          }
LAB_005275b1:
          if (puVar39 == (undefined *)0x0) goto LAB_00527748;
          uVar40 = plVar36[1];
          iVar8 = (int)plVar36[3] * 8;
          uVar28 = (uVar40 >> 3) - 1;
          uVar24 = ((ulong)*(uint *)(puVar39 + 0x14) - 0x50) % (uVar28 * 8);
          uVar13 = uVar24 + 8;
          uVar28 = ((ulong)plVar36[3] % uVar28) * 8 + 8;
          if (uVar13 != uVar28) {
            if (uVar28 < uVar13) {
              lVar38 = ((ulong)*(uint *)(puVar39 + 8) - 0x48) - uVar13;
              portMemCopy(puVar39 + uVar24 + 0x70,lVar38,*plVar36 + uVar13,lVar38);
              if (8 < uVar28) {
                uVar13 = 8;
                goto LAB_00527614;
              }
            }
            else {
LAB_00527614:
              portMemCopy(puVar39 + uVar13 + 0x68,uVar28 - uVar13,*plVar36 + uVar13,uVar28 - uVar13)
              ;
            }
            *(int *)(puVar39 + 0x14) = iVar8 + 0x50;
            *(long *)(puVar39 + 0x68) = plVar36[3];
            goto joined_r0x00527764;
          }
          if (param_2 == '\0') goto LAB_0052764e;
LAB_0052779c:
          portMemCopy(puVar39 + 0x68,uVar40,*plVar36,uVar40);
          *(int *)(puVar39 + 0x14) = iVar8 + 0x50;
        }
        else {
          puVar39 = (&PTR__nvlogZeroBuffer_00594988)[*(uint *)(plVar36 + 0xd)];
          if ((*(uint *)(plVar36 + 0xd) == 0) || (puVar39 == (undefined *)0x0)) {
            nvAssertFailedNoLog("(pLog->hNvLogNoWrap != 0) && (pNvLogBuffer != NULL)",
                                "../common/uproc/os/libos-v3.1.0/lib/liblogdecode.c",0x5a1);
            *(undefined1 *)(plVar36 + 0xe) = 0;
LAB_00527735:
            puVar39 = (&PTR__nvlogZeroBuffer_00594988)[*(uint *)((long)plVar36 + 0x6c)];
            if (*(uint *)((long)plVar36 + 0x6c) != 0) goto LAB_005275b1;
            goto LAB_00527748;
          }
          uVar13 = plVar36[3] * 8 + 8;
          uVar28 = (ulong)*(uint *)(puVar39 + 0x14);
          uVar40 = (uVar28 - plVar36[0xf]) + 8;
          if (uVar13 < uVar40) {
LAB_00527731:
            *(undefined1 *)(plVar36 + 0xe) = 0;
            goto LAB_00527735;
          }
          if (uVar13 != uVar40) {
            lVar38 = uVar13 - uVar40;
            if ((ulong)*(uint *)(puVar39 + 8) <= uVar28 + lVar38) goto LAB_00527731;
            *(undefined1 *)((long)plVar36 + 0x71) = 1;
            portMemCopy(puVar39 + uVar28 + 0x20,lVar38,uVar40 + *plVar36,lVar38);
            *(int *)(puVar39 + 0x14) = (int)plVar36[0xf] + -8 + (int)uVar13;
            *(ulong *)(puVar39 + 0x68) = (plVar36[0xf] - 0x50U >> 3) + plVar36[3];
          }
          *(undefined1 *)(plVar36 + 0xe) = 1;
joined_r0x00527764:
          if (param_2 != '\0') {
            puVar39 = (&PTR__nvlogZeroBuffer_00594988)[*(uint *)((long)plVar36 + 0x6c)];
            if ((*(uint *)((long)plVar36 + 0x6c) != 0) && (puVar39 != (undefined *)0x0)) {
              uVar40 = plVar36[1];
              iVar8 = (int)plVar36[3] * 8;
              goto LAB_0052779c;
            }
            nvAssertFailedNoLog("(pLog->hNvLogWrap != 0) && (pNvLogBuffer != NULL)",
                                "../common/uproc/os/libos-v3.1.0/lib/liblogdecode.c",0x600);
          }
        }
      }
      else {
        bVar4 = true;
      }
    }
LAB_0052764e:
    uVar13 = *(ulong *)(param_1 + 8);
    uVar34 = uVar34 + 1;
    plVar36 = plVar36 + 0x3b;
  } while (uVar34 < uVar13);
  if (bVar4) {
    if (uVar13 == 0) {
      if (*(long *)(param_1 + 0xed0) == 0) {
        return;
      }
    }
    else {
      puVar12 = (undefined8 *)(param_1 + 0x28);
      uVar28 = 0;
      uVar34 = 0;
      cVar33 = '\0';
      puVar11 = puVar12 + uVar13 * 0x3b;
      do {
        if ((((*(byte *)((long)puVar12 + 0x3c) & 1) == 0) &&
            ((*(byte *)((long)puVar12 + 0x4c) & 2) != 0)) && (puVar12[1] = *puVar12, uVar34 == 0)) {
          uVar34 = (ulong)*(uint *)(puVar12 + 10);
          uVar28 = (ulong)*(uint *)((long)puVar12 + 0x54);
          cVar33 = *(char *)(puVar12 + 0xb);
        }
        puVar12 = puVar12 + 0x3b;
      } while (puVar12 != puVar11);
      if (*(long *)(param_1 + 0xed0) == 0) goto LAB_0052767b;
      local_78 = 0;
      uVar40 = *(ulong *)(param_1 + 0xed8) >> 3;
      while (uVar13 != 0) {
        plVar35 = (long *)0x0;
        uVar24 = 0;
        plVar36 = plVar10;
        do {
          if (((*(byte *)((long)plVar36 + 0x54) & 1) == 0) &&
             ((*(byte *)((long)plVar36 + 100) & 2) != 0)) {
            uVar29 = ((ulong)plVar36[1] >> 3) - 1;
            uVar19 = plVar36[2];
            if (plVar36[2] + uVar29 < (ulong)plVar36[3]) {
              uVar19 = plVar36[3] - uVar29;
            }
            if ((uVar19 < (ulong)plVar36[4]) &&
               (uVar3 = *(ulong *)(*plVar36 + 8 + ((plVar36[4] - 1U) % uVar29) * 8), uVar24 < uVar3)
               ) {
              uVar24 = uVar3;
              plVar35 = plVar36;
              local_100 = uVar29;
              local_f8 = uVar19;
            }
          }
          plVar36 = plVar36 + 0x3b;
        } while (plVar36 != plVar10 + uVar13 * 0x3b);
        if (uVar24 == 0) break;
        uVar13 = *(ulong *)(*plVar35 + 8 + ((plVar35[4] - 2U) % local_100) * 8) >> 0x30 & 0xff;
        if (0x14 < (int)uVar13 - 2U) {
          nv_printf(4,
                    "libosMergeNvlog: Invalid logEntrySize: %d, merged buffer configured incorrectly!\n"
                    ,uVar13);
          break;
        }
        if (uVar40 <= uVar13) break;
        uVar24 = plVar35[4] - uVar13;
        plVar35[4] = uVar24;
        if (local_f8 < uVar24) {
          *(undefined1 *)((long)plVar35 + 0x71) = 1;
          uVar40 = uVar40 - uVar13;
          lVar43 = uVar13 * 8;
          lVar31 = *(long *)(param_1 + 0xed0) + uVar40 * 8;
          lVar42 = (uVar24 % local_100) * 8 + 8;
          lVar38 = *plVar35 + lVar42;
          if ((ulong)plVar35[1] <= (ulong)(lVar42 + lVar43)) {
            lVar30 = plVar35[1] - lVar42;
            portMemCopy(lVar31,lVar30,lVar38,lVar30);
            lVar43 = (lVar43 - plVar35[1]) + lVar42;
            lVar38 = *plVar35 + 8;
            lVar31 = ((uVar40 * 8 + plVar35[1]) - lVar42) + *(long *)(param_1 + 0xed0);
          }
          portMemCopy(lVar31,lVar43,lVar38,lVar43);
          local_78 = local_78 + uVar13;
        }
        uVar13 = *(ulong *)(param_1 + 8);
      }
      lVar38 = local_78 * 8;
      if (cVar33 == '\0') {
        if (local_78 == 0) {
          uVar13 = *(ulong *)(param_1 + 8);
          goto LAB_00527676;
        }
LAB_00527ab1:
        puVar39 = (&PTR__nvlogZeroBuffer_00594988)[uVar28];
        uVar13 = *(ulong *)(param_1 + 0xed8) >> 3;
        uVar40 = (ulong)*(uint *)(puVar39 + 8);
        uVar28 = (ulong)*(uint *)(puVar39 + 0x14);
        uVar34 = uVar28;
        lVar42 = local_78;
        if (uVar28 + lVar38 < uVar40) {
LAB_00528893:
          portMemCopy(puVar39 + uVar28 + 0x20,lVar38,
                      *(long *)(param_1 + 0xed0) + (uVar13 - lVar42) * 8,lVar38);
          *(int *)(puVar39 + 0x14) = *(int *)(puVar39 + 0x14) + (int)lVar38;
        }
        else {
          do {
            uVar27 = (int)uVar40 - (int)uVar34;
            uVar28 = (ulong)uVar27;
            lVar38 = lVar38 - uVar28;
            portMemCopy(puVar39 + uVar34 + 0x20,uVar28,
                        *(long *)(param_1 + 0xed0) + (uVar13 - lVar42) * 8,uVar28);
            uVar40 = (ulong)*(uint *)(puVar39 + 8);
            lVar42 = lVar42 - (ulong)(uVar27 >> 3);
            *(undefined4 *)(puVar39 + 0x14) = 0x50;
            uVar28 = 0x50;
            uVar34 = 0x50;
          } while (uVar40 <= lVar38 + 0x50U);
          if (lVar42 != 0) goto LAB_00528893;
        }
        *(ulong *)(puVar39 + 0x68) = *(long *)(puVar39 + 0x68) + local_78;
      }
      else if (local_78 != 0) {
        puVar39 = (&PTR__nvlogZeroBuffer_00594988)[uVar34];
        if ((ulong)*(uint *)(puVar39 + 8) < (ulong)*(uint *)(puVar39 + 0x14) + lVar38) {
          if (*(long *)(param_1 + 8) != 0) {
            pbVar14 = (byte *)(param_1 + 100);
            pbVar25 = pbVar14 + *(long *)(param_1 + 8) * 0x1d8;
            do {
              if (((*pbVar14 & 1) == 0) && ((pbVar14[0x10] & 2) != 0)) {
                pbVar14[0x1c] = 0;
              }
              pbVar14 = pbVar14 + 0x1d8;
            } while (pbVar14 != pbVar25);
          }
          goto LAB_00527ab1;
        }
        portMemCopy(puVar39 + (ulong)*(uint *)(puVar39 + 0x14) + 0x20,lVar38,
                    *(long *)(param_1 + 0xed0) + ((*(ulong *)(param_1 + 0xed8) >> 3) - local_78) * 8
                    ,lVar38);
        *(ulong *)(puVar39 + 0x68) = *(long *)(puVar39 + 0x68) + local_78;
        *(int *)(puVar39 + 0x14) = *(int *)(puVar39 + 0x14) + (int)lVar38;
        uVar13 = *(ulong *)(param_1 + 8);
        goto LAB_00527676;
      }
      uVar13 = *(ulong *)(param_1 + 8);
    }
  }
LAB_00527676:
  if (uVar13 == 0) {
    return;
  }
LAB_0052767b:
  puVar12 = (undefined8 *)(param_1 + 0x20);
  do {
    puVar11 = puVar12 + 0x3b;
    *puVar12 = puVar12[1];
    puVar12 = puVar11;
  } while (puVar11 != (undefined8 *)(param_1 + 0x20) + uVar13 * 0x3b);
  return;
  while( true ) {
    pbVar14 = pbVar14 + 1;
    uVar41 = uVar41 | 1 << ((byte)(uVar27 - 0x20) & 0x1f);
    uVar27 = (uint)(char)*pbVar14;
    if (0x1f < uVar27 - 0x20) break;
LAB_005280df:
    if ((0x12889U >> (uVar27 - 0x20 & 0x1f) & 1) == 0) {
      if ((char)uVar27 == '*') {
        bVar7 = pbVar14[1];
        if (((byte)(bVar7 - 0x30) < 10) && (pbVar14[2] == 0x24)) {
          bVar7 = pbVar14[3];
          uVar24 = 0;
          pbVar14 = pbVar14 + 3;
          bVar5 = true;
        }
        else {
          if ((bVar5) || (uVar40 <= local_78)) goto LAB_005281f1;
          pbVar14 = pbVar14 + 1;
          iVar8 = (int)plVar36[local_78 + 5];
          if (iVar8 < 0) {
            uVar41 = uVar41 | 0x2000;
          }
          uVar24 = plVar36[local_78 + 5] & 0xffffffff;
          if (iVar8 < 0) {
            uVar24 = (ulong)(uint)-iVar8;
          }
          local_78 = local_78 + 1;
        }
        goto LAB_0052815a;
      }
      break;
    }
  }
  bVar7 = *pbVar14;
  uVar24 = 0;
  if ((byte)(bVar7 - 0x30) < 10) {
    do {
      pbVar14 = pbVar14 + 1;
      uVar27 = (int)(char)(bVar7 - 0x30) + (int)uVar24 * 10;
      uVar24 = (ulong)uVar27;
      bVar7 = *pbVar14;
    } while ((byte)(bVar7 - 0x30) < 10);
    if ((int)uVar27 < 0) goto LAB_005281f1;
  }
LAB_0052815a:
  if (bVar7 == 0x2e) {
    bVar7 = pbVar14[1];
    if (bVar7 == 0x2a) {
      if (((byte)(pbVar14[2] - 0x30) < 10) && (pbVar14[3] == 0x24)) {
        iVar8 = 0;
        pbVar14 = pbVar14 + 4;
      }
      else {
        if ((bVar5) || (uVar40 <= local_78)) goto LAB_005281f1;
        pbVar14 = pbVar14 + 2;
        iVar8 = (int)plVar36[local_78 + 5];
        local_78 = local_78 + 1;
      }
    }
    else {
      pbVar14 = pbVar14 + 1;
      if ((byte)(bVar7 - 0x30) < 10) {
        iVar8 = 0;
        do {
          pbVar14 = pbVar14 + 1;
          iVar8 = (int)(char)(bVar7 - 0x30) + iVar8 * 10;
          bVar7 = *pbVar14;
        } while ((byte)(bVar7 - 0x30) < 10);
      }
      else {
        iVar8 = 0;
      }
    }
  }
  else {
    iVar8 = -1;
  }
LAB_005281b7:
  uVar19 = 0;
  do {
    bVar7 = *pbVar14;
    iVar21 = (int)(char)bVar7;
    if (0x39 < iVar21 - 0x41U) goto LAB_005281f1;
    iVar9 = (int)uVar19;
    pbVar14 = pbVar14 + 1;
    bVar2 = states[uVar19 * 0x3a + (ulong)(iVar21 - 0x41U)];
    uVar19 = (ulong)bVar2;
  } while (bVar2 - 1 < 8);
  if (bVar2 == 0) goto LAB_005281f1;
  if (bVar2 == 0x19) {
    if (bVar6 != 0xff) goto LAB_005281f1;
  }
  else if (bVar6 == 0xff) {
    if (uVar40 <= local_78) goto LAB_005281f1;
    local_98 = (byte *)plVar36[local_78 + 5];
    local_78 = local_78 + 1;
  }
  if ((iVar9 == 0) || ((bVar7 & 0xf) != 3)) {
    if ((uVar41 & 0x2000) != 0) {
      uVar41 = uVar41 & 0xfffeffff;
    }
    if (iVar21 == 0x6e) goto LAB_00527f49;
    if (iVar21 < 0x6f) {
      if (iVar21 == 0x61) {
        s_getSymbolDataStr(plVar36[1] + 0xa0,symDecodedLine_2,0x400,local_98,0);
        pbVar25 = symDecodedLine_2;
        goto LAB_00528d57;
      }
      if (iVar21 < 0x62) goto LAB_005288e5;
      if ((0xfffffef7ffffffffU >> ((ulong)(iVar21 - 0x41) & 0x3f) & 1) != 0) {
        if (iVar21 == 99) {
          bVar44 = false;
          uVar41 = uVar41 & 0xfffeffff;
          pbVar25 = local_39;
          iVar21 = 1;
          local_88 = 1;
          local_e0 = &_LC33;
          uVar27 = 0;
          local_39[0] = (byte)local_98;
          iVar9 = 1;
          goto LAB_00528670;
        }
        goto LAB_00528a4d;
      }
      if (-1 < (long)local_98) {
        if ((uVar41 & 0x800) == 0) {
          uVar27 = uVar41 & 1;
          local_e0 = &_LC33;
          if ((uVar41 & 1) != 0) {
            local_e0 = &DAT_00dae751;
          }
        }
        else {
          uVar27 = 1;
          local_e0 = &DAT_00dae750;
        }
        goto LAB_00528ac1;
      }
      uVar27 = 1;
      local_98 = (byte *)-(long)local_98;
      local_e0 = &_LC33;
LAB_00528acf:
      pbVar25 = local_39 + 1;
      pbVar16 = local_98;
      do {
        pbVar25 = pbVar25 + -1;
        *pbVar25 = (char)pbVar16 + (char)(byte *)((ulong)pbVar16 / 10) * -10 + 0x30;
        bVar44 = (byte *)0x9 < pbVar16;
        pbVar16 = (byte *)((ulong)pbVar16 / 10);
      } while (bVar44);
LAB_00528b2b:
      bVar44 = false;
      pbVar16 = local_39 + (1 - (long)pbVar25);
      iVar22 = (int)pbVar16;
      iVar9 = iVar22;
      if (-1 < iVar8) {
        uVar41 = uVar41 & 0xfffeffff;
      }
LAB_00528486:
      if (iVar22 <= iVar8) {
        iVar22 = iVar8;
      }
      lVar42 = (long)iVar22;
      iVar8 = iVar22;
      goto LAB_00528494;
    }
    if (iVar21 != 0x73) {
      if (iVar21 < 0x74) {
        if (iVar21 != 0x6f) {
          if (iVar21 != 0x70) goto LAB_00528a4d;
          uVar41 = uVar41 | 8;
          uVar27 = 8;
          bVar6 = 0x20;
          bVar44 = *(char *)(param_1 + 0xf81) != '\0';
          iVar21 = 0x78;
          if (local_98 != (byte *)0x0) goto LAB_00528410;
          goto LAB_00528dc5;
        }
        pbVar25 = local_39 + 1;
        pbVar16 = local_98;
        if (local_98 != (byte *)0x0) {
          do {
            pbVar25 = pbVar25 + -1;
            pbVar18 = (byte *)((ulong)pbVar16 >> 3);
            *pbVar25 = ((byte)pbVar16 & 7) + 0x30;
            pbVar16 = pbVar18;
          } while (pbVar18 != (byte *)0x0);
          if ((uVar41 & 8) == 0) {
            uVar27 = 0;
            local_e0 = &_LC33;
            goto LAB_00528b2b;
          }
          pbVar16 = local_39 + (1 - (long)pbVar25);
          iVar22 = (int)pbVar16;
          iVar9 = iVar22;
          if (iVar8 < 0) {
            bVar44 = false;
            uVar27 = 1;
            local_e0 = &DAT_00dae754;
          }
          else {
            bVar44 = false;
            uVar27 = 1;
            local_e0 = &DAT_00dae754;
            uVar41 = uVar41 & 0xfffeffff;
          }
          goto LAB_00528486;
        }
        if (iVar8 < 0) {
          bVar44 = false;
          local_e0 = &_LC33;
          uVar27 = 0;
          iVar22 = 1;
          iVar21 = 0;
          goto LAB_00528dae;
        }
        bVar44 = false;
        uVar41 = uVar41 & 0xfffeffff;
        uVar27 = 0;
        local_e0 = &_LC33;
LAB_00528dee:
        if (iVar8 == 0) {
          pbVar25 = local_39 + 1;
          local_98 = (byte *)0x0;
          local_88 = (ulong)uVar27;
          iVar9 = 0;
          iVar21 = 0;
          goto LAB_00528670;
        }
        pbVar25 = local_39 + 1;
        local_98 = (byte *)0x0;
        iVar22 = 1;
        iVar21 = 0;
        if (0 < iVar8) {
          iVar22 = iVar8;
        }
      }
      else {
        uVar27 = 0;
        local_e0 = &_LC33;
        if (iVar21 != 0x75) {
          if (iVar21 != 0x78) goto LAB_00528a4d;
          goto LAB_00528cd2;
        }
LAB_00528ac1:
        if (local_98 != (byte *)0x0) goto LAB_00528acf;
        if (-1 < iVar8) {
          bVar44 = false;
          uVar41 = uVar41 & 0xfffeffff;
          goto LAB_00528dee;
        }
        bVar44 = false;
        pbVar25 = local_39 + 1;
        iVar22 = 1;
        iVar21 = 0;
      }
      goto LAB_00528dae;
    }
    pbVar16 = (byte *)LibosElfMapVirtualString
                                (*plVar36 + 0x88,local_98,*(undefined1 *)(param_1 + 0xf83));
    pbVar25 = (byte *)"(bad-pointer)";
    if (pbVar16 != (byte *)0x0) {
      pbVar25 = pbVar16;
    }
LAB_00528d57:
    uVar41 = uVar41 & 0xfffeffff;
    iVar22 = portStringLengthSafe(pbVar25,(long)iVar8);
    bVar44 = false;
    local_e0 = &_LC33;
    uVar27 = 0;
    iVar21 = iVar22;
  }
  else {
    iVar21 = (int)(char)(bVar7 & 0xdf);
    if ((uVar41 & 0x2000) == 0) {
LAB_005288e5:
      if (iVar21 != 0x43) {
        if (iVar21 != 0x58) {
LAB_00528a4d:
          lVar42 = (long)iVar8;
          bVar44 = false;
          uVar27 = 0;
          pbVar16 = local_39 + (1 - (long)pbVar25);
          local_e0 = &_LC33;
          iVar9 = (int)pbVar16;
          goto LAB_00528494;
        }
LAB_00528cd2:
        if (local_98 != (byte *)0x0) {
          bVar44 = false;
          bVar6 = (byte)iVar21 & 0x20;
          uVar27 = uVar41 & 8;
LAB_00528410:
          pbVar25 = local_39 + 1;
          pbVar16 = local_98;
          do {
            pbVar25 = pbVar25 + -1;
            uVar23 = (uint)pbVar16;
            pbVar16 = (byte *)((ulong)pbVar16 >> 4);
            *pbVar25 = xdigits_0[uVar23 & 0xf] | bVar6;
          } while (pbVar16 != (byte *)0x0);
          pbVar16 = local_39 + (1 - (long)pbVar25);
          iVar9 = (int)pbVar16;
          iVar22 = iVar9 + (uint)(local_98 == (byte *)0x0);
          if (uVar27 == 0) {
            if (iVar8 < 0) {
              uVar27 = 0;
              local_e0 = &_LC33;
            }
            else {
              uVar27 = 0;
              local_e0 = &_LC33;
              uVar41 = uVar41 & 0xfffeffff;
            }
          }
          else {
            uVar27 = 2;
            local_e0 = &_LC33 + (uint)(iVar21 >> 4);
            if (-1 < iVar8) {
              uVar41 = uVar41 & 0xfffeffff;
            }
          }
          goto LAB_00528486;
        }
        bVar44 = false;
LAB_00528dc5:
        if (-1 < iVar8) {
          uVar27 = 0;
          uVar41 = uVar41 & 0xfffeffff;
          local_e0 = &_LC33;
          goto LAB_00528dee;
        }
        pbVar25 = local_39 + 1;
        local_98 = (byte *)0x0;
        local_e0 = &_LC33;
        uVar27 = 0;
        iVar22 = 1;
        iVar21 = 0;
        goto LAB_00528dae;
      }
    }
    else {
      uVar41 = uVar41 & 0xfffeffff;
      if ((bVar7 & 0xdf) != 0x43) goto LAB_00528a4d;
    }
    local_55 = (byte)local_98;
    local_54 = 0;
    lVar42 = -1;
    pbVar16 = local_39 + (1 - (long)pbVar25);
    bVar44 = false;
    local_98 = &local_55;
    iVar9 = (int)pbVar16;
    uVar27 = 0;
    local_e0 = &_LC33;
    iVar8 = -1;
LAB_00528494:
    iVar22 = iVar8;
    iVar21 = iVar9;
    if (lVar42 < (long)pbVar16) {
      local_88 = (ulong)(uVar27 + iVar9);
      goto LAB_00528670;
    }
  }
LAB_00528dae:
  iVar9 = iVar22;
  local_88 = (ulong)(uVar27 + iVar9);
LAB_00528670:
  if ((int)uVar24 < (int)local_88) {
    uVar24 = local_88;
  }
  pad(0x20,uVar24,local_88,uVar41,param_1);
  emit_string(local_e0,uVar27,param_1);
  pad(0x30,uVar24,local_88,uVar41 ^ 0x10000,param_1);
  pad(0x30,iVar9,iVar21,0,param_1);
  emit_string(pbVar25,iVar21,param_1);
  if (bVar44) {
    portMemSet(&symDecodedLine_1,0,0x400);
    _symDecodedLine_1 = 0x3c20;
    s_getSymbolDataStr(*plVar36 + 0xa0,&DAT_0056ee02,0x3fe,local_98,0);
    uVar19 = portStringLength(&symDecodedLine_1);
    if (0x3ff < uVar19) {
      uVar19 = 0x3ff;
    }
    *(undefined2 *)(&symDecodedLine_1 + uVar19) = 0x3e;
    pcVar26 = &symDecodedLine_1;
    do {
      if (*pcVar26 == '\0') break;
      pcVar20 = *(char **)(param_1 + 0xef8);
      if ((pcVar1 <= pcVar20) && (pcVar15 != pcVar20)) {
        bVar6 = *(byte *)(param_1 + 0xf82);
        *pcVar20 = '\0';
        bVar7 = 6;
        if ((bVar6 < 7) && (bVar7 = bVar6, bVar6 == 2)) {
          bVar7 = 3;
        }
        nv_printf(bVar7,&DAT_00dae60f,pcVar15);
        pcVar20 = pcVar15;
      }
      pcVar37 = pcVar26 + 1;
      *(char **)(param_1 + 0xef8) = pcVar20 + 1;
      *pcVar20 = *pcVar26;
      pcVar26 = pcVar37;
    } while (pcVar37 != &DAT_0056f1ff);
  }
  pad(0x20,uVar24,local_88,uVar41 ^ 0x2000);
  goto LAB_00527f49;
LAB_00528220:
  if (pcVar15 != *(char **)(param_1 + 0xef8)) {
    bVar6 = *(byte *)(param_1 + 0xf82);
    **(char **)(param_1 + 0xef8) = '\0';
    bVar7 = 6;
    if ((bVar6 < 7) && (bVar7 = bVar6, bVar6 == 2)) {
      bVar7 = 3;
    }
    nv_printf(bVar7,&DAT_00dae60f,pcVar15);
    *(char **)(param_1 + 0xef8) = pcVar15;
  }
  if (pbVar25[1] == 0) goto LAB_005281f1;
  pbVar14 = pbVar25 + 1;
  if (*(char **)(param_1 + 0xef8) != pcVar15) goto LAB_00527f56;
LAB_00528296:
  uVar27 = nvDbgSnprintf(pcVar15,0x7f,"NVRM: GPU%u %s-%s: %s(%u): ",*(undefined4 *)(*plVar36 + 0x28)
                        );
  if ((int)uVar27 < 0) goto LAB_005281f1;
  if (uVar27 < 0x7f) {
    uVar24 = 0x7f - (ulong)uVar27;
    lVar43 = (ulong)uVar27 + *(long *)(param_1 + 0xef8);
    *(long *)(param_1 + 0xef8) = lVar43;
    lVar42 = plVar36[2];
    bVar6 = *(byte *)(lVar42 + 0x16);
    if (bVar6 == 3) {
      uVar27 = nvDbgSnprintf(lVar43,uVar24 & 0xffffffff,"Check failed: ",pcVar32);
    }
    else if (bVar6 < 4) {
      if (bVar6 == 1) {
        uVar27 = nvDbgSnprintf(lVar43,uVar24 & 0xffffffff,"Assertion failed: ",pcVar32);
      }
      else {
        if (bVar6 != 2) goto LAB_005285eb;
LAB_00528576:
        if (uVar40 <= local_78) goto LAB_005281fd;
        uVar17 = nvstatusToString(plVar36[local_78 + 5] & 0xffffffff);
        uVar27 = nvDbgSnprintf(*(undefined8 *)(param_1 + 0xef8),uVar24 & 0xffffffff,
                               "Assertion failed: %s (0x%08X) returned from ",uVar17);
        local_78 = local_78 + 1;
      }
    }
    else {
      if (bVar6 != 4) goto LAB_005285eb;
LAB_00528948:
      if (uVar40 <= local_78) goto LAB_005281fd;
      uVar17 = nvstatusToString(plVar36[local_78 + 5] & 0xffffffff);
      uVar27 = nvDbgSnprintf(*(undefined8 *)(param_1 + 0xef8),uVar24 & 0xffffffff,
                             "Check failed: %s (0x%08X) returned from ",uVar17);
      local_78 = local_78 + 1;
    }
    if ((int)uVar27 < 0) goto LAB_005281f1;
    if (uVar27 < uVar24) {
      lVar43 = (ulong)uVar27 + *(long *)(param_1 + 0xef8);
      bVar4 = true;
LAB_005285eb:
      *(long *)(param_1 + 0xef8) = lVar43;
      goto LAB_00527f56;
    }
  }
  else {
    *(char **)(param_1 + 0xef8) = pcVar1;
    lVar42 = plVar36[2];
    bVar6 = *(byte *)(lVar42 + 0x16);
    if (bVar6 == 3) {
      pcVar26 = "Check failed: ";
    }
    else {
      if (3 < bVar6) {
        uVar24 = 0;
        if (bVar6 != 4) goto LAB_005289a9;
        goto LAB_00528948;
      }
      if (bVar6 != 1) {
        uVar24 = 0;
        if (bVar6 != 2) goto LAB_005289a9;
        goto LAB_00528576;
      }
      pcVar26 = "Assertion failed: ";
    }
    iVar8 = nvDbgSnprintf(pcVar1,0,pcVar26,pcVar32);
    if (iVar8 < 0) goto LAB_005281f1;
  }
  bVar4 = true;
LAB_005289a9:
  *(char **)(param_1 + 0xef8) = pcVar1;
  goto LAB_00527f56;
LAB_005281f1:
  lVar42 = plVar36[2];
LAB_005281fd:
  uVar13 = uVar13 + 5 + (ulong)*(byte *)(lVar42 + 0x14);
  if (uVar34 - uVar28 <= uVar13) goto LAB_00528216;
  goto LAB_00527e20;
}


// ===== 00529100 nv_add_open_file.cold =====

void nv_add_open_file_cold(void)

{
  long unaff_RBX;
  
  __list_add_valid_or_report();
  up(unaff_RBX + 0x868);
  return;
}


// ===== 00529110 __pfx_nv_module_resources_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0052914c) */

void __pfx_nv_module_resources_exit(void)

{
  nv_kmem_cache_free_stack();
  if (nvidia_p2p_page_t_cache != 0) {
    kmem_cache_destroy();
  }
  if (nvidia_stack_t_cache != 0) {
    kmem_cache_destroy();
    return;
  }
  return;
}


// ===== 00529120 nv_module_resources_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0052914c) */

void nv_module_resources_exit(void)

{
  nv_kmem_cache_free_stack();
  if (nvidia_p2p_page_t_cache != 0) {
    kmem_cache_destroy();
  }
  if (nvidia_stack_t_cache != 0) {
    kmem_cache_destroy();
    return;
  }
  return;
}


// ===== 00529160 __pfx_nv_module_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_module_exit(undefined8 param_1)

{
  nv_teardown_pat_support();
  nv_kthread_q_stop(nv_deferred_close_kthread_q);
  nv_kthread_q_stop(nv_kthread_q);
  nv_destroy_page_pools();
  rm_destroy_event_locks(param_1,nv_ctl_device);
  rm_shutdown_rm(param_1);
  nv_destroy_rsync_info();
  nvswitch_exit();
  nvlink_core_exit();
  nv_cap_drv_exit();
  nv_module_resources_exit(param_1);
  return;
}


// ===== 00529170 nv_module_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_module_exit(undefined8 param_1)

{
  nv_teardown_pat_support();
  nv_kthread_q_stop(nv_deferred_close_kthread_q);
  nv_kthread_q_stop(nv_kthread_q);
  nv_destroy_page_pools();
  rm_destroy_event_locks(param_1,nv_ctl_device);
  rm_shutdown_rm(param_1);
  nv_destroy_rsync_info();
  nvswitch_exit();
  nvlink_core_exit();
  nv_cap_drv_exit();
  nv_module_resources_exit(param_1);
  return;
}


// ===== 005291d0 __pfx_nv_register_chrdev.constprop.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0052926c) */

int __pfx_nv_register_chrdev_constprop_0
              (uint param_1,ulong param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  
  param_1 = param_1 | 0xc300000;
  iVar1 = register_chrdev_region(param_1,param_2,param_4);
  if (iVar1 < 0) {
    nv_printf(4,"NVRM: register_chrdev_region() failed for %s!\n",param_4);
  }
  else {
    cdev_init(param_3,nvidia_fops);
    iVar1 = cdev_add(param_3,param_1,param_2 & 0xffffffff);
    if (iVar1 < 0) {
      nv_printf(4,"NVRM: cdev_add() failed for %s!\n",param_4);
      unregister_chrdev_region(param_1,param_2 & 0xffffffff);
    }
  }
  return iVar1;
}


// ===== 005291e0 nv_register_chrdev.constprop.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0052926c) */

int nv_register_chrdev_constprop_0(uint param_1,ulong param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  
  param_1 = param_1 | 0xc300000;
  iVar1 = register_chrdev_region(param_1,param_2,param_4);
  if (iVar1 < 0) {
    nv_printf(4,"NVRM: register_chrdev_region() failed for %s!\n",param_4);
  }
  else {
    cdev_init(param_3,nvidia_fops);
    iVar1 = cdev_add(param_3,param_1,param_2 & 0xffffffff);
    if (iVar1 < 0) {
      nv_printf(4,"NVRM: cdev_add() failed for %s!\n",param_4);
      unregister_chrdev_region(param_1,param_2 & 0xffffffff);
    }
  }
  return iVar1;
}


// ===== 00529271 nvidia_close_callback.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001076dc) */

void nvidia_close_callback_cold(void)

{
  long lVar1;
  char cVar2;
  long unaff_RBX;
  long unaff_RBP;
  long unaff_R12;
  
  __list_del_entry_valid_or_report();
  lVar1 = unaff_RBP + 0x730;
  *(undefined8 *)(unaff_RBX + 0x200) = 0xdead000000000100;
  *(undefined8 *)(unaff_RBX + 0x208) = 0xdead000000000122;
  up(unaff_RBP + 0x868);
  down(lVar1);
  nv_close_device();
  if ((((*(byte *)(unaff_RBP + 0x11) & 0x80) == 0) && (*(long *)(unaff_RBP + 0x3a0) == 0)) &&
     (cVar2 = rm_get_device_remove_flag(), cVar2 != '\0')) {
    nv_free_file_private();
    if ((*(long *)(unaff_RBP + 0x3a0) != 0) || (*(char *)(unaff_RBP + 0x2fc) == '\0')) {
      up(lVar1);
      pci_stop_and_remove_bus_device(*(undefined8 *)(unaff_RBP + 0x3b8));
      goto LAB_001076b7;
    }
  }
  else {
    nv_free_file_private();
    if ((*(long *)(unaff_RBP + 0x3a0) != 0) || (*(char *)(unaff_RBP + 0x2fc) == '\0')) {
      up(lVar1);
      goto LAB_001076b7;
    }
  }
  rm_destroy_event_locks();
  kfree();
LAB_001076b7:
  if ((unaff_R12 != 0) && (cVar2 = rm_is_altstack_in_use(), cVar2 != '\0')) {
    kmem_cache_free(nvidia_stack_t_cache);
    return;
  }
  return;
}


// ===== 0052927b nvidia_unlocked_ioctl.cold =====

void nvidia_unlocked_ioctl_cold(void)

{
                    /* WARNING: Subroutine does not return */
  __fortify_panic(0xf);
}


// ===== 00529288 nv_pci_tegra_devfreq_get_dev_status.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010c657) */

undefined8 nv_pci_tegra_devfreq_get_dev_status_cold(void)

{
  long in_GS_OFFSET;
  long in_stack_00000008;
  
  _dev_warn();
  if (in_stack_00000008 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return 0xfffffff4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 005292ab nv_pci_tegra_devfreq_remove.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010c9be) */

void nv_pci_tegra_devfreq_remove_cold(void)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  long *plVar4;
  long *unaff_RBX;
  long *unaff_RBP;
  long *plVar5;
  long *unaff_R12;
  long unaff_R13;
  long unaff_R14;
  
  do {
    __list_del_entry_valid_or_report();
    plVar4 = unaff_RBX;
    unaff_RBX = unaff_R12;
    while( true ) {
      plVar4[100] = unaff_R14;
      plVar4[0x65] = unaff_R13;
      plVar4[0x68] = 0;
      if (unaff_RBP == unaff_RBX) {
        plVar4 = (long *)unaff_RBP[0x66] + -0x66;
        plVar5 = unaff_RBP;
        if (unaff_RBP != plVar4) {
          plVar1 = *(long **)unaff_RBP[0x66];
          do {
            plVar5 = plVar1 + -0x66;
            if (plVar4[0x6a] != 0) {
              devm_clk_put(unaff_RBP[9]);
              plVar4[0x6a] = 0;
              device_unregister(plVar4 + 1);
            }
            plVar2 = (long *)plVar4[0x67];
            lVar3 = plVar4[0x66];
            if ((plVar4 + 0x66 == (long *)*plVar2) && (plVar4 + 0x66 == *(long **)(lVar3 + 8))) {
              *(long **)(lVar3 + 8) = plVar2;
              *plVar2 = lVar3;
            }
            else {
              __list_del_entry_valid_or_report();
            }
            plVar4[0x66] = -0x2152ffffffffff00;
            plVar4[0x67] = -0x2152fffffffffede;
            plVar4[0x69] = 0;
            plVar1 = (long *)*plVar1;
            plVar4 = plVar5;
          } while (unaff_RBP != plVar5);
        }
        if (unaff_RBP[0x6a] == 0) {
          return;
        }
        devm_clk_put(unaff_RBP[9],plVar5[0x6a]);
        unaff_RBP[0x6a] = 0;
        device_unregister(unaff_RBP + 1);
        return;
      }
      unaff_R12 = (long *)(unaff_RBX[100] + -800);
      if (unaff_RBX[0x6a] != 0) {
        devm_clk_put(unaff_RBP[9]);
        unaff_RBX[0x6a] = 0;
        device_unregister(unaff_RBX + 1);
      }
      plVar4 = (long *)unaff_RBX[0x65];
      lVar3 = unaff_RBX[100];
      if ((unaff_RBX + 100 != (long *)*plVar4) || (unaff_RBX + 100 != *(long **)(lVar3 + 8))) break;
      *(long **)(lVar3 + 8) = plVar4;
      *plVar4 = lVar3;
      plVar4 = unaff_RBX;
      unaff_RBX = unaff_R12;
    }
  } while( true );
}


// ===== 005292bf nv_pci_gb10b_register_devfreq.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010de3c) */

undefined4 nv_pci_gb10b_register_devfreq_cold(void)

{
  long unaff_RBX;
  long unaff_RBP;
  undefined4 unaff_R14D;
  
  __list_del_entry_valid_or_report();
  *(undefined8 *)(unaff_RBX + 800) = 0xdead000000000100;
  *(undefined8 *)(unaff_RBX + 0x328) = 0xdead000000000122;
  *(undefined8 *)(*(long *)(unaff_RBP + 0x5268) + 0x340) = 0;
  device_unregister(*(long *)(unaff_RBP + 0x5268) + 8);
  *(undefined8 *)(unaff_RBP + 0x5268) = 0;
  return unaff_R14D;
}


// ===== 00529308 nv_p2p_remove_dma_mapping.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00117123) */

void nv_p2p_remove_dma_mapping_cold(undefined8 *param_1)

{
  __list_del_entry_valid_or_report();
  *param_1 = 0xdead000000000100;
  param_1[1] = 0xdead000000000122;
  os_free_mem();
  up();
  return;
}


// ===== 0052931a nvidia_p2p_dma_map_pages.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011813f) */

undefined8 nvidia_p2p_dma_map_pages_cold(void)

{
  char cVar1;
  long unaff_RBX;
  long unaff_RBP;
  long unaff_R13;
  long in_GS_OFFSET;
  
  __list_add_valid_or_report();
  up(unaff_RBX + 0x38);
  if ((unaff_R13 != 0) && (cVar1 = rm_is_altstack_in_use(), cVar1 != '\0')) {
    kmem_cache_free(nvidia_stack_t_cache);
  }
  if (*(long *)(unaff_RBP + -0x38) != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}


// ===== 00529324 nv_procfs_close_registry.cold =====

void nv_procfs_close_registry_cold(void)

{
  long in_RAX;
  
                    /* WARNING: Subroutine does not return */
  __fortify_panic(2,0x200,in_RAX + 1);
}


// ===== 00529371 nv_mem_pool_free_page_list.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011b453) */

void nv_mem_pool_free_page_list_cold(void)

{
  long *plVar1;
  long lVar2;
  undefined8 *unaff_RBX;
  undefined8 *unaff_RBP;
  undefined8 *puVar3;
  undefined4 unaff_R12D;
  undefined8 unaff_R13;
  undefined8 unaff_R14;
  
  do {
    __list_del_entry_valid_or_report();
    while( true ) {
      unaff_RBX[1] = unaff_R14;
      unaff_RBX[2] = unaff_R13;
      free_pages(*unaff_RBX,unaff_R12D);
      kfree(unaff_RBX);
      if (unaff_RBP == (undefined8 *)*unaff_RBP) {
        return;
      }
      puVar3 = (undefined8 *)*unaff_RBP;
      unaff_RBX = puVar3 + -1;
      if (unaff_RBP == puVar3) {
        puVar3 = (undefined8 *)&DAT_00000008;
        unaff_RBX = (undefined8 *)0x0;
      }
      plVar1 = (long *)unaff_RBX[2];
      lVar2 = unaff_RBX[1];
      if (((undefined8 *)*plVar1 != puVar3) || (puVar3 != *(undefined8 **)(lVar2 + 8))) break;
      *(long **)(lVar2 + 8) = plVar1;
      *plVar1 = lVar2;
    }
  } while( true );
}


// ===== 0052937b nv_mem_pool_move_pages.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011b527) */
/* WARNING: Removing unreachable block (ram,0x0011b532) */

long nv_mem_pool_move_pages_cold
               (long *param_1,undefined8 param_2,undefined8 param_3,long *param_4,long param_5,
               long *param_6)

{
  long lVar1;
  long *plVar2;
  long lStack0000000000000008;
  long *plStack0000000000000010;
  long *plStack0000000000000018;
  
  plStack0000000000000010 = param_6;
  do {
    lStack0000000000000008 = param_5;
    plStack0000000000000018 = plStack0000000000000010;
    plStack0000000000000010 = param_4;
    __list_del_entry_valid_or_report();
    param_4 = plStack0000000000000010;
    plStack0000000000000010 = plStack0000000000000018;
    while( true ) {
      *param_1 = -0x2152ffffffffff00;
      param_1[1] = -0x2152fffffffffede;
      plVar2 = (long *)*param_4;
      if (((param_4 == (long *)plVar2[1]) && (param_1 != param_4)) && (param_1 != plVar2)) {
        plVar2[1] = (long)param_1;
        *param_1 = (long)plVar2;
        param_1[1] = (long)param_4;
        *param_4 = (long)param_1;
      }
      else {
        __list_add_valid_or_report(param_1,param_4);
      }
      param_5 = lStack0000000000000008 + -1;
      if (param_5 == 0) {
        return 0;
      }
      param_1 = (long *)*plStack0000000000000010;
      if ((plStack0000000000000010 == param_1) || (param_1 == (long *)&DAT_00000008)) {
        return param_5;
      }
      plVar2 = (long *)param_1[1];
      lVar1 = *param_1;
      if ((param_1 != (long *)*plVar2) || (param_1 != *(long **)(lVar1 + 8))) break;
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
      lStack0000000000000008 = param_5;
    }
  } while( true );
}


// ===== 005293fc nv_mem_pool_worker.cold =====

void nv_mem_pool_worker_cold(void)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  long extraout_RDX;
  long *unaff_RBX;
  long unaff_RBP;
  long lVar4;
  long lVar5;
  long unaff_R12;
  long *unaff_R14;
  long *unaff_R15;
  
  do {
    __list_del_entry_valid_or_report(unaff_R14);
    while( true ) {
      *unaff_R14 = unaff_R12;
      unaff_R14[1] = unaff_RBP;
      os_release_mutex(unaff_R15[0x13]);
      iVar3 = 1 << ((byte)*(undefined4 *)((long)unaff_R15 + 0x8c) & 0x1f);
      if (iVar3 != 0) {
        lVar5 = unaff_R14[-1];
        lVar4 = (ulong)(iVar3 - 1) * 0x1000 + lVar5 + 0x1000;
        do {
          __clear_pages_unrolled(lVar5);
          lVar5 = extraout_RDX;
        } while (lVar4 != extraout_RDX);
      }
      iVar3 = os_acquire_mutex(unaff_R15[0x13]);
      if (iVar3 != 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      plVar1 = (long *)*unaff_R15;
      if (((unaff_R15 == (long *)plVar1[1]) && (unaff_R15 != unaff_R14)) && (unaff_R14 != plVar1)) {
        plVar1[1] = (long)unaff_R14;
        *unaff_R14 = (long)plVar1;
        unaff_R14[1] = (long)unaff_R15;
        *unaff_R15 = (long)unaff_R14;
        unaff_R14 = (long *)unaff_R15[2];
      }
      else {
        __list_add_valid_or_report(unaff_R14);
        unaff_R14 = (long *)unaff_R15[2];
      }
      if ((unaff_R14 == unaff_RBX) || (unaff_R14 == (long *)&DAT_00000008)) {
        os_release_mutex(unaff_R15[0x13]);
        return;
      }
      plVar1 = (long *)unaff_R14[1];
      lVar5 = *unaff_R14;
      if ((unaff_R14 != (long *)*plVar1) || (unaff_R14 != *(long **)(lVar5 + 8))) break;
      *(long **)(lVar5 + 8) = plVar1;
      *plVar1 = lVar5;
    }
  } while( true );
}


// ===== 00529419 nv_mem_pool_alloc_pages.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011bb2e) */

int nv_mem_pool_alloc_pages_cold(void)

{
  long *plVar1;
  long *plVar2;
  uint uVar3;
  ulong uVar4;
  long extraout_RDX;
  long lVar5;
  long extraout_RDX_00;
  long extraout_RDX_01;
  int unaff_EBX;
  long *unaff_RBP;
  long lVar6;
  long *plVar7;
  long *unaff_R12;
  long *unaff_R13;
  long unaff_R14;
  long in_GS_OFFSET;
  int unaff_retaddr;
  long in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined4 uStack0000000000000018;
  undefined4 uStack000000000000001c;
  long *in_stack_00000020;
  long *in_stack_00000030;
  long in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  
  do {
    __list_del_entry_valid_or_report(unaff_RBP);
    while( true ) {
      *unaff_RBP = unaff_R14;
      unaff_EBX = unaff_EBX + 1;
      unaff_RBP[1] = -0x2152fffffffffede;
      kfree(unaff_R13);
      if ((in_stack_00000020 == unaff_R12) ||
         (unaff_R13 = in_stack_00000020 + -1, unaff_R13 == (long *)0x0)) {
        if ((long **)in_stack_00000030 != &stack0x00000030) goto LAB_0011bc7d;
        goto LAB_0011bd5d;
      }
      nv_alloc_set_page();
      plVar1 = (long *)in_stack_00000020[1];
      lVar5 = *in_stack_00000020;
      unaff_RBP = in_stack_00000020;
      if ((in_stack_00000020 != (long *)*plVar1) || (in_stack_00000020 != *(long **)(lVar5 + 8)))
      break;
      *(long **)(lVar5 + 8) = plVar1;
      *plVar1 = lVar5;
    }
  } while( true );
LAB_0011bc7d:
  do {
    plVar1 = in_stack_00000030;
    plVar7 = in_stack_00000030 + -1;
    if (plVar7 == (long *)0x0) break;
    lVar5 = in_stack_00000030[-1];
    uVar3 = 1 << ((byte)*(undefined4 *)(in_stack_00000008 + 0x8c) & 0x1f);
    if (uVar3 != 0) {
      uVar4 = (ulong)uVar3 * 0x1000;
      lVar6 = uVar4 + lVar5;
      if ((uVar4 & 0x1000) != 0) {
        __clear_pages_unrolled(lVar5);
        lVar5 = extraout_RDX + 0x1000;
        if (lVar6 == lVar5) goto LAB_0011bcff;
      }
      do {
        __clear_pages_unrolled(lVar5);
        __clear_pages_unrolled(extraout_RDX_00 + 0x1000);
        lVar5 = extraout_RDX_01 + 0x2000;
      } while (lVar6 != lVar5);
    }
LAB_0011bcff:
    nv_alloc_set_page();
    plVar2 = (long *)plVar1[1];
    lVar5 = *plVar1;
    if ((plVar1 == (long *)*plVar2) && (plVar1 == *(long **)(lVar5 + 8))) {
      *(long **)(lVar5 + 8) = plVar2;
      *plVar2 = lVar5;
    }
    else {
      __list_del_entry_valid_or_report(plVar1);
    }
    unaff_EBX = unaff_EBX + 1;
    *plVar1 = -0x2152ffffffffff00;
    plVar1[1] = -0x2152fffffffffede;
    kfree(plVar7);
  } while ((long **)in_stack_00000030 != &stack0x00000030);
LAB_0011bd5d:
  if (unaff_EBX != unaff_retaddr) {
    os_dbg_breakpoint();
  }
  nv_printf(0,
            "NVRM: VM: %s: node=%d order=%u: %lu/%lu pages allocated (%lu already cleared, %lu left in pool)\n"
            ,"nv_mem_pool_alloc_pages",*(undefined4 *)(in_stack_00000008 + 0x88),
            *(undefined4 *)(in_stack_00000008 + 0x8c),unaff_retaddr,uStack0000000000000018,
            uStack000000000000001c,in_stack_00000010);
  if (in_stack_00000040 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return unaff_retaddr;
}


// ===== 00529433 nv_mem_pool_free_pages.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011c277) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 nv_mem_pool_free_pages_cold(void)

{
  code *pcVar1;
  int iVar2;
  ulong *puVar3;
  ulong *puVar4;
  long lVar5;
  long unaff_RBX;
  uint unaff_EBP;
  ulong uVar6;
  ulong *unaff_R12;
  int unaff_R13D;
  int unaff_R14D;
  long unaff_R15;
  long in_GS_OFFSET;
  byte unaff_retaddr;
  ulong *in_stack_00000010;
  long *in_stack_00000018;
  long in_stack_00000020;
  
code_r0x00529433:
  __list_add_valid_or_report();
LAB_0011c134:
  unaff_EBP = unaff_EBP + 1;
  do {
    unaff_R13D = unaff_R13D + 1;
    if (unaff_R14D == unaff_R13D) {
LAB_0011c198:
      if (unaff_EBP != 0) {
        iVar2 = os_acquire_mutex(*(undefined8 *)(unaff_R15 + 0x98));
        if (iVar2 != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        uVar6 = *(ulong *)(unaff_R15 + 0x10);
        if (in_stack_00000010 != unaff_R12) {
          lVar5 = *(long *)(unaff_R15 + 0x10);
          in_stack_00000010[1] = unaff_R15 + 0x10U;
          *(ulong **)(unaff_R15 + 0x10) = in_stack_00000010;
          *in_stack_00000018 = lVar5;
          *(long **)(lVar5 + 8) = in_stack_00000018;
        }
        lVar5 = (ulong)unaff_EBP + *(long *)(unaff_R15 + 0x90);
        *(long *)(unaff_R15 + 0x90) = lVar5;
        os_release_mutex(*(undefined8 *)(unaff_R15 + 0x98));
        nv_printf(0,
                  "NVRM: VM: %s: node=%d order=%u: %lu/%lu pages added to pool (%lu now in pool)\n",
                  "nv_mem_pool_free_pages",*(undefined4 *)(unaff_R15 + 0x88),
                  *(undefined4 *)(unaff_R15 + 0x8c),unaff_EBP);
        if (unaff_R15 + 0x10U == uVar6) {
          nv_kthread_q_schedule_q_item(unaff_R15 + 0x20,unaff_R15 + 0x68,lVar5);
        }
      }
      if (in_stack_00000020 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
        return 0;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    puVar4 = (ulong *)((ulong)(uint)(unaff_R13D << (unaff_retaddr & 0x1f)) * 0x10 +
                      *(long *)(unaff_RBX + 0x30));
    uVar6 = puVar4[1];
    if (uVar6 == 0) goto LAB_0011c198;
    if (*(uint *)(unaff_R15 + 0x88) ==
        (uint)((ulong)*(undefined8 *)((*puVar4 >> 0xc) * 0x40 + _vmemmap_base) >> 0x36)) {
      puVar3 = (ulong *)__kmalloc_cache_noprof(___alloc_pages_noprof,0x2dc0,0x18);
      uVar6 = puVar4[1];
      if (puVar3 != (ulong *)0x0) break;
    }
    free_pages(uVar6,*(undefined4 *)(unaff_R15 + 0x8c));
  } while( true );
  *puVar3 = uVar6;
  puVar4 = puVar3 + 1;
  if (((ulong *)in_stack_00000010[1] != unaff_R12) || (puVar4 == in_stack_00000010))
  goto code_r0x00529433;
  in_stack_00000010[1] = (ulong)puVar4;
  puVar3[1] = (ulong)in_stack_00000010;
  puVar3[2] = (ulong)unaff_R12;
  in_stack_00000010 = puVar4;
  goto LAB_0011c134;
}


// ===== 00529440 nv_alloc_system_pages.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011c970) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong nv_alloc_system_pages_cold
                (undefined8 param_1,undefined8 param_2,int param_3,undefined8 param_4,
                undefined4 param_5,undefined8 param_6,undefined8 param_7,long param_8,long param_9)

{
  void *__s;
  int iVar1;
  long lVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  uint unaff_EBX;
  long lVar6;
  undefined4 unaff_EBP;
  undefined4 uVar7;
  uint unaff_R12D;
  byte unaff_R13B;
  int unaff_R14D;
  long unaff_R15;
  long in_GS_OFFSET;
  uint unaff_retaddr;
  
  param_7._0_4_ = param_3;
  param_7._4_4_ = param_5;
  _printk(&DAT_00db4798,&param_8);
  dump_stack();
  iVar1 = (int)param_7;
  uVar7 = param_7._4_4_;
  while (lVar2 = __alloc_pages_noprof(unaff_EBP,uVar7,iVar1,0), lVar2 != 0) {
    lVar2 = (lVar2 - _vmemmap_base >> 6) * 0x1000 + _page_offset_base;
    while( true ) {
      if (lVar2 == 0) goto LAB_0011c92d;
      unaff_EBX = unaff_EBX + 1;
      nv_alloc_set_page();
      if (unaff_R12D <= unaff_EBX) {
        uVar5 = 0;
        do {
          uVar4 = uVar5 << (unaff_R13B & 0x1f);
          __s = *(void **)((ulong)uVar4 * 0x10 + *(long *)(unaff_R15 + 0x30) + 8);
          if (((*(byte *)(unaff_R15 + 0x19) & 1) != 0) && (__s != (void *)0x0)) {
            uVar4 = *(int *)(unaff_R15 + 0x20) - uVar4;
            if (unaff_retaddr < uVar4) {
              uVar4 = unaff_retaddr;
            }
            set_memory_decrypted(__s);
            memset(__s,0,(ulong)uVar4 << 0xc);
          }
          uVar5 = uVar5 + 1;
        } while (unaff_R12D != uVar5);
        uVar3 = (ulong)*(uint *)(unaff_R15 + 0x1c);
        if (*(uint *)(unaff_R15 + 0x1c) != 0) {
          param_8 = 0;
          if ((*(byte *)(unaff_R15 + 0x18) & 1) == 0) {
            iVar1 = os_alloc_mem(&param_8,(ulong)*(uint *)(unaff_R15 + 0x20) << 3);
            if (iVar1 == 0) {
              if (param_8 != 0) {
                if (*(int *)(unaff_R15 + 0x20) == 0) {
                  uVar5 = 0;
                }
                else {
                  lVar2 = 0;
                  do {
                    *(ulong *)(param_8 + lVar2 * 8) =
                         (*(ulong *)(lVar2 * 0x10 + *(long *)(unaff_R15 + 0x30)) >> 0xc) * 0x40 +
                         _vmemmap_base;
                    uVar5 = *(uint *)(unaff_R15 + 0x20);
                    lVar2 = lVar2 + 1;
                  } while ((uint)lVar2 < uVar5);
                }
                set_pages_array_uc(param_8,uVar5);
                os_free_mem(param_8);
                uVar3 = 0;
                goto LAB_0011c94f;
              }
            }
            else {
              param_8 = 0;
            }
            lVar2 = 0;
            if (*(int *)(unaff_R15 + 0x20) != 0) {
              do {
                lVar6 = lVar2 + 1;
                set_memory_uc((*(ulong *)(lVar2 * 0x10 + *(long *)(unaff_R15 + 0x30)) &
                              0xfffffffffffff000) + _page_offset_base,1);
                lVar2 = lVar6;
              } while ((uint)lVar6 < *(uint *)(unaff_R15 + 0x20));
            }
            uVar3 = 0;
          }
          else {
            set_memory_uc((**(ulong **)(unaff_R15 + 0x30) & 0xfffffffffffff000) + _page_offset_base)
            ;
            uVar3 = 0;
          }
        }
        goto LAB_0011c94f;
      }
      uVar7 = *(undefined4 *)(unaff_R15 + 0x24);
      if ((*(byte *)(unaff_R15 + 0x18) & 0x20) != 0) break;
      lVar2 = get_free_pages_noprof(unaff_EBP,uVar7);
    }
    iVar1 = *(int *)(unaff_R15 + 0x50);
    if (*(int *)(unaff_R15 + 0x50) == -1) {
      iVar1 = *(int *)(&numa_node + in_GS_OFFSET);
    }
    param_8 = CONCAT44(param_8._4_4_,unaff_EBP);
    if ((unaff_R14D == 0x202000) &&
       (((byte)__release_region[(long)iVar1 >> 3] >> ((long)iVar1 & 7U) & 1) == 0)) {
      uVar3 = nv_alloc_system_pages_cold();
      return uVar3;
    }
  }
LAB_0011c92d:
  nv_printf(0,"NVRM: VM: %s: failed to allocate memory\n","nv_alloc_system_pages");
  nv_free_system_pages();
  uVar3 = 0x51;
LAB_0011c94f:
  if (param_9 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}


// ===== 00529470 __pfx_out_string =====

void __pfx_out_string(undefined8 param_1)

{
  _printk(&DAT_00daf6bf,param_1);
  return;
}


// ===== 00529480 out_string =====

void out_string(undefined8 param_1)

{
  _printk(&DAT_00daf6bf,param_1);
  return;
}


// ===== 00529493 nv_printf.cold =====

void nv_printf_cold(void)

{
                    /* WARNING: Subroutine does not return */
  __fortify_panic(0x11,0x20e);
}


// ===== 005294b0 __pfx_os_dump_stack =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_dump_stack(void)

{
  dump_stack();
  return;
}


// ===== 005294c0 os_dump_stack =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_dump_stack(void)

{
  dump_stack();
  return;
}


// ===== 005294d0 __pfx_os_bug_check =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_bug_check(undefined8 param_1,undefined8 param_2)

{
                    /* WARNING: Subroutine does not return */
  panic(param_2);
}


// ===== 005294e0 os_bug_check =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_bug_check(undefined8 param_1,undefined8 param_2)

{
                    /* WARNING: Subroutine does not return */
  panic(param_2);
}


// ===== 005294f1 os_alloc_pages_node.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f64f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
os_alloc_pages_node_cold
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
          undefined4 param_5)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  long *unaff_RBX;
  undefined4 unaff_EBP;
  uint unaff_R12D;
  long in_GS_OFFSET;
  undefined4 uStack000000000000000c;
  long in_stack_00000018;
  
  uStack000000000000000c = param_5;
  _printk(&DAT_00db4d38,&stack0x00000014);
  dump_stack();
  puVar1 = (undefined8 *)__alloc_pages_noprof(uStack000000000000000c,unaff_EBP,param_3,0);
  if (puVar1 == (undefined8 *)0x0) {
    nv_printf(0,"NVRM: alloc_pages_node(node = %d, order = %u) failed\n",unaff_R12D,unaff_EBP);
  }
  else {
    if (unaff_R12D == (uint)((ulong)*puVar1 >> 0x36)) {
      uVar2 = 0;
      *unaff_RBX = ((long)puVar1 - _vmemmap_base >> 6) << 0xc;
      goto LAB_0011f638;
    }
    nv_printf(4,"NVRM: alloc_pages_node(node = %d, order = %u) wrong node ID.\n",unaff_R12D,
              unaff_EBP);
    __free_pages(puVar1,unaff_EBP);
  }
  uVar2 = 0x51;
LAB_0011f638:
  if (in_stack_00000018 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0052951c _raw_q_schedule.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122051) */

undefined8 _raw_q_schedule_cold(void)

{
  undefined8 in_RCX;
  long unaff_RBX;
  
  __list_add_valid_or_report();
  _raw_spin_unlock_irqrestore(unaff_RBX + 0x10,in_RCX);
  up(unaff_RBX + 0x18);
  return 1;
}


// ===== 0052953d _main_loop.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Removing unreachable block (ram,0x0012219c) */

undefined8 _main_loop_cold(undefined8 param_1,undefined8 param_2)

{
  long *plVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long *unaff_RBX;
  long *unaff_RBP;
  long unaff_R13;
  long in_GS_OFFSET;
  
code_r0x0052953d:
  __list_del_entry_valid_or_report(unaff_RBX);
LAB_0012212a:
  *unaff_RBX = (long)unaff_RBX;
  unaff_RBX[1] = (long)unaff_RBX;
  _raw_spin_unlock_irqrestore(unaff_RBP + 2,param_2);
  if ((code *)unaff_RBX[2] != _q_flush_function) {
    (*(code *)unaff_RBX[2])(unaff_RBX[3]);
    goto LAB_001220d7;
  }
  complete();
  iVar4 = down_interruptible(unaff_RBP + 3);
  if (iVar4 == 0) goto LAB_001220e4;
  do {
    if (*(short *)(&DAT_00f79bd9 + in_GS_OFFSET) == 0) {
      __SCT__WARN_trap(&DAT_00100e90,unaff_R13 + 0xd48);
    }
    else {
      __SCT__WARN_trap(&DAT_00100e80);
    }
LAB_001220d7:
    while( true ) {
      iVar4 = down_interruptible(unaff_RBP + 3);
      if (iVar4 != 0) break;
LAB_001220e4:
      if ((int)unaff_RBP[6] != 0) {
        while( true ) {
          cVar3 = kthread_should_stop();
          if (cVar3 != '\0') break;
          schedule();
        }
        return 0;
      }
      param_2 = _raw_spin_lock_irqsave(unaff_RBP + 2);
      if (unaff_RBP != (long *)*unaff_RBP) {
        unaff_RBX = (long *)*unaff_RBP;
        plVar1 = (long *)unaff_RBX[1];
        lVar2 = *unaff_RBX;
        if ((unaff_RBX != (long *)*plVar1) || (unaff_RBX != *(long **)(lVar2 + 8)))
        goto code_r0x0052953d;
        *(long **)(lVar2 + 8) = plVar1;
        *plVar1 = lVar2;
        goto LAB_0012212a;
      }
      _raw_spin_unlock_irqrestore(unaff_RBP + 2);
      if (*(short *)(&DAT_00f79bd9 + in_GS_OFFSET) == 0) {
        __SCT__WARN_trap(&DAT_00100eb0,*(long *)(&const_current_task + in_GS_OFFSET) + 0xd48);
      }
      else {
        __SCT__WARN_trap(&DAT_00100ea0);
      }
    }
  } while( true );
}


// ===== 00529552 nv_cap_alloc.cold =====

void nv_cap_alloc_cold(void)

{
                    /* WARNING: Subroutine does not return */
  __fortify_panic(0x1f);
}


// ===== 00529598 nv_cap_init.cold =====

void nv_cap_init_cold(void)

{
  long unaff_RBX;
  long unaff_RBP;
  long unaff_R13;
  
  memcpy((void *)(unaff_RBP + unaff_RBX),&stack0x0000003a,(unaff_R13 + 0xd) - unaff_RBX);
  *(undefined1 *)(unaff_RBP + 0xd + unaff_R13) = 0;
                    /* WARNING: Subroutine does not return */
  __fortify_panic(0xb);
}


// ===== 00529612 lkca_aead_internal.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001297c1) */

int lkca_aead_internal_cold(void)

{
  int unaff_EBX;
  undefined8 *unaff_R13;
  long in_GS_OFFSET;
  long in_stack_00000048;
  undefined8 in_stack_000000a0;
  
  _printk(&DAT_00df0e18,unaff_EBX);
  if (unaff_EBX == -0x4a) {
    _printk(&DAT_00df0e48);
  }
  *unaff_R13 = in_stack_000000a0;
  if (in_stack_00000048 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return unaff_EBX;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0052963a FUN_0052963a =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001297c1) */

undefined4 FUN_0052963a(void)

{
  undefined4 unaff_EBX;
  undefined8 *unaff_R13;
  long in_GS_OFFSET;
  long in_stack_00000048;
  undefined8 in_stack_000000a0;
  
  _printk(&DAT_00df0de8,unaff_EBX);
  *unaff_R13 = in_stack_000000a0;
  if (in_stack_00000048 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return unaff_EBX;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00529671 libspdm_aead.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012a39e) */

undefined8 libspdm_aead_cold(void)

{
  long unaff_R14;
  long unaff_R15;
  long in_GS_OFFSET;
  long unaff_retaddr;
  long in_stack_00000008;
  long in_stack_00000108;
  
  _printk(&DAT_00df0ee0);
  if (unaff_retaddr != 0) {
    kfree(0);
  }
  if (in_stack_00000008 != 0) {
    kfree(0);
  }
  if (unaff_R14 != 0) {
    crypto_destroy_tfm();
  }
  if (unaff_R15 != 0) {
    kfree_sensitive();
  }
  if (in_stack_00000108 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0xfffffff4;
}


// ===== 005296c0 libspdm_aead_gcm_prealloc.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012a879) */

undefined8 libspdm_aead_gcm_prealloc_cold(void)

{
  long *unaff_RBX;
  
  unaff_RBX[1] = 0;
  _printk(&DAT_00df0ee0);
  crypto_destroy_tfm(*unaff_RBX,*unaff_RBX + 8);
  kfree();
  return 0;
}


// ===== 00529716 lkca_ecdsa_verify_crypto_sig.isra.0.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012acfc) */

bool lkca_ecdsa_verify_crypto_sig_isra_0_cold(void)

{
  int in_EAX;
  undefined8 in_R9;
  long in_GS_OFFSET;
  undefined8 uStack0000000000000008;
  long in_stack_000000c8;
  
  uStack0000000000000008 = in_R9;
  _printk(&DAT_00df0f70,-in_EAX);
  crypto_destroy_tfm(uStack0000000000000008,uStack0000000000000008);
  if (in_stack_000000c8 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return in_EAX == 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00529771 lkca_hkdf_expand_only.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012b4eb) */

undefined8 lkca_hkdf_expand_only_cold(void)

{
  long in_GS_OFFSET;
  long in_stack_000001e8;
  
  _printk(&DAT_00db04d8);
  if (in_stack_000001e8 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0052979f lkca_hash_new.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012b8f5) */

undefined8 lkca_hash_new_cold(void)

{
  _printk(&DAT_00db0507);
  return 0;
}


// ===== 005297d5 NV_PKCS1_MGF1.constprop.0.cold =====

void NV_PKCS1_MGF1_constprop_0_cold(void)

{
                    /* WARNING: Subroutine does not return */
  __fortify_panic(0x10,0x30);
}


// ===== 00529886 lkca_rsa_pss_sign.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c4cc) */

undefined4 lkca_rsa_pss_sign_cold(void)

{
  undefined4 unaff_R15D;
  long in_GS_OFFSET;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  long in_stack_00000088;
  
  _printk(&DAT_00df1300,"nvRsaPaddingAddPkcs1PssMgf1");
  mpi_free(in_stack_00000008);
  mpi_free(in_stack_00000010);
  mpi_free(unaff_retaddr);
  mpi_free();
  libspdm_sha384_free();
  if (in_stack_00000088 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return unaff_R15D;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0052999c FUN_0052999c =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c4cc) */

undefined8 FUN_0052999c(void)

{
  long in_GS_OFFSET;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  long in_stack_00000088;
  
  _printk(&DAT_00df11e0,"nvRsaPaddingAddPkcs1PssMgf1");
  mpi_free(in_stack_00000008);
  mpi_free(in_stack_00000010);
  mpi_free(unaff_retaddr);
  mpi_free();
  libspdm_sha384_free(0);
  if (in_stack_00000088 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00529a00 nvswitch_is_device_blacklisted.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ee58) */

undefined8 nvswitch_is_device_blacklisted_cold(void)

{
  long in_GS_OFFSET;
  long in_stack_00000008;
  
  _printk(&DAT_00df1628);
  if (in_stack_00000008 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00529a18 nvswitch_device_poll.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ef3f) */

undefined8 nvswitch_device_poll_cold(void)

{
  long in_GS_OFFSET;
  long in_stack_00000008;
  
  _printk(&DAT_00db0752);
  mutex_unlock();
  if (in_stack_00000008 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return 0x10;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00529a50 __pfx___list_del_entry =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00529a79) */

void __pfx___list_del_entry(long *param_1)

{
  long *plVar1;
  long lVar2;
  
  plVar1 = (long *)param_1[1];
  lVar2 = *param_1;
  if ((param_1 == (long *)*plVar1) && (param_1 == *(long **)(lVar2 + 8))) {
    *(long **)(lVar2 + 8) = plVar1;
    *plVar1 = lVar2;
    return;
  }
  __list_del_entry_valid_or_report();
  return;
}


// ===== 00529a60 __list_del_entry =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00529a79) */

void __list_del_entry(long *param_1)

{
  long *plVar1;
  long lVar2;
  
  plVar1 = (long *)param_1[1];
  lVar2 = *param_1;
  if ((param_1 == (long *)*plVar1) && (param_1 == *(long **)(lVar2 + 8))) {
    *(long **)(lVar2 + 8) = plVar1;
    *plVar1 = lVar2;
    return;
  }
  __list_del_entry_valid_or_report();
  return;
}


// ===== 00529a90 __pfx_nvswitch_deinit_background_tasks =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvswitch_deinit_background_tasks(long param_1)

{
  *(undefined4 *)(param_1 + 0xe0) = 0;
  __wake_up(param_1 + 0xe8,3,1,0);
  nv_kthread_q_stop(param_1 + 0x78);
  return;
}


// ===== 00529aa0 nvswitch_deinit_background_tasks =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvswitch_deinit_background_tasks(long param_1)

{
  *(undefined4 *)(param_1 + 0xe0) = 0;
  __wake_up(param_1 + 0xe8,3,1,0);
  nv_kthread_q_stop(param_1 + 0x78);
  return;
}


// ===== 00529ae0 __pfx___list_add =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00529b13) */

void __pfx___list_add(long *param_1,long *param_2,long *param_3)

{
  if ((((param_2 == (long *)param_3[1]) && (param_3 == (long *)*param_2)) && (param_1 != param_2))
     && (param_1 != param_3)) {
    param_3[1] = (long)param_1;
    *param_1 = (long)param_3;
    param_1[1] = (long)param_2;
    *param_2 = (long)param_1;
    return;
  }
  __list_add_valid_or_report();
  return;
}


// ===== 00529af0 __list_add =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00529b13) */

void __list_add(long *param_1,long *param_2,long *param_3)

{
  if ((((param_2 == (long *)param_3[1]) && (param_3 == (long *)*param_2)) && (param_1 != param_2))
     && (param_1 != param_3)) {
    param_3[1] = (long)param_1;
    *param_1 = (long)param_3;
    param_1[1] = (long)param_2;
    *param_2 = (long)param_1;
    return;
  }
  __list_add_valid_or_report();
  return;
}


// ===== 00529b20 __pfx_nvswitch_device_open =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00529c29) */

int __pfx_nvswitch_device_open(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  
  _printk(&DAT_00df16a8,*(uint *)(param_1 + 0x4c) & 0xfffff,*(uint *)(param_1 + 0x4c) >> 0x14);
  iVar2 = mutex_lock_interruptible(&DAT_005478a0);
  if (iVar2 == 0) {
    if ((undefined8 **)DAT_005478b8 != &DAT_005478b8) {
      puVar4 = DAT_005478b8;
      do {
        if ((*(uint *)(param_1 + 0x4c) & 0xfffff) == *(uint *)(puVar4 + -0x1e)) {
          puVar5 = puVar4 + -0x22;
          if ((puVar5 != (undefined8 *)0x0) &&
             (cVar1 = nvswitch_is_device_blacklisted(puVar5), cVar1 == '\0')) {
            puVar3 = (undefined8 *)_nvswitch_os_malloc(0x30);
            if (puVar3 == (undefined8 *)0x0) {
              iVar2 = -0xc;
            }
            else {
              *puVar3 = puVar5;
              __init_waitqueue_head(puVar3 + 1,"&private->file_event.wait_q_event",&nvswitch);
              *(undefined1 *)(puVar3 + 4) = 0;
              *(undefined4 *)(puVar3 + 5) = 0xffffffff;
              *(undefined8 **)(param_2 + 0x18) = puVar3;
              LOCK();
              *(int *)(puVar4 + -1) = *(int *)(puVar4 + -1) + 1;
              UNLOCK();
            }
            goto LAB_00529c13;
          }
          break;
        }
        puVar4 = (undefined8 *)*puVar4;
      } while ((undefined8 **)puVar4 != &DAT_005478b8);
    }
    iVar2 = -0x13;
LAB_00529c13:
    mutex_unlock(&DAT_005478a0);
  }
  return iVar2;
}


// ===== 00529b30 nvswitch_device_open =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00529c29) */

int nvswitch_device_open(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  
  _printk(&DAT_00df16a8,*(uint *)(param_1 + 0x4c) & 0xfffff,*(uint *)(param_1 + 0x4c) >> 0x14);
  iVar2 = mutex_lock_interruptible(&DAT_005478a0);
  if (iVar2 == 0) {
    if ((undefined8 **)DAT_005478b8 != &DAT_005478b8) {
      puVar4 = DAT_005478b8;
      do {
        if ((*(uint *)(param_1 + 0x4c) & 0xfffff) == *(uint *)(puVar4 + -0x1e)) {
          puVar5 = puVar4 + -0x22;
          if ((puVar5 != (undefined8 *)0x0) &&
             (cVar1 = nvswitch_is_device_blacklisted(puVar5), cVar1 == '\0')) {
            puVar3 = (undefined8 *)_nvswitch_os_malloc(0x30);
            if (puVar3 == (undefined8 *)0x0) {
              iVar2 = -0xc;
            }
            else {
              *puVar3 = puVar5;
              __init_waitqueue_head(puVar3 + 1,"&private->file_event.wait_q_event",&nvswitch);
              *(undefined1 *)(puVar3 + 4) = 0;
              *(undefined4 *)(puVar3 + 5) = 0xffffffff;
              *(undefined8 **)(param_2 + 0x18) = puVar3;
              LOCK();
              *(int *)(puVar4 + -1) = *(int *)(puVar4 + -1) + 1;
              UNLOCK();
            }
            goto LAB_00529c13;
          }
          break;
        }
        puVar4 = (undefined8 *)*puVar4;
      } while ((undefined8 **)puVar4 != &DAT_005478b8);
    }
    iVar2 = -0x13;
LAB_00529c13:
    mutex_unlock(&DAT_005478a0);
  }
  return iVar2;
}


// ===== 00529c30 __pfx_nvswitch_device_release =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00529cda) */

undefined8 __pfx_nvswitch_device_release(long param_1,long param_2)

{
  int *piVar1;
  long *plVar2;
  long lVar3;
  
  plVar2 = *(long **)(param_2 + 0x18);
  lVar3 = *plVar2;
  _printk(&DAT_00df16f8,*(uint *)(param_1 + 0x4c) & 0xfffff,*(uint *)(param_1 + 0x4c) >> 0x14);
  mutex_lock(&DAT_005478a0);
  nvswitch_lib_remove_client_events(*(undefined8 *)(lVar3 + 0x50),plVar2);
  LOCK();
  piVar1 = (int *)(lVar3 + 0x108);
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if ((*piVar1 == 0) && (*(char *)(lVar3 + 0x120) != '\0')) {
    kfree(lVar3);
  }
  if (0 < (int)plVar2[5]) {
    nvlink_cap_release();
    *(undefined4 *)(plVar2 + 5) = 0xffffffff;
  }
  _nvswitch_os_free(*(undefined8 *)(param_2 + 0x18));
  *(undefined8 *)(param_2 + 0x18) = 0;
  mutex_unlock(&DAT_005478a0);
  return 0;
}


// ===== 00529c40 nvswitch_device_release =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00529cda) */

undefined8 nvswitch_device_release(long param_1,long param_2)

{
  int *piVar1;
  long *plVar2;
  long lVar3;
  
  plVar2 = *(long **)(param_2 + 0x18);
  lVar3 = *plVar2;
  _printk(&DAT_00df16f8,*(uint *)(param_1 + 0x4c) & 0xfffff,*(uint *)(param_1 + 0x4c) >> 0x14);
  mutex_lock(&DAT_005478a0);
  nvswitch_lib_remove_client_events(*(undefined8 *)(lVar3 + 0x50),plVar2);
  LOCK();
  piVar1 = (int *)(lVar3 + 0x108);
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if ((*piVar1 == 0) && (*(char *)(lVar3 + 0x120) != '\0')) {
    kfree(lVar3);
  }
  if (0 < (int)plVar2[5]) {
    nvlink_cap_release();
    *(undefined4 *)(plVar2 + 5) = 0xffffffff;
  }
  _nvswitch_os_free(*(undefined8 *)(param_2 + 0x18));
  *(undefined8 *)(param_2 + 0x18) = 0;
  mutex_unlock(&DAT_005478a0);
  return 0;
}


// ===== 00529ce0 __pfx_nvswitch_deinit_device =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00529d9d) */

void __pfx_nvswitch_deinit_device(long param_1)

{
  long lVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  bool bVar4;
  
  puVar2 = *(undefined8 **)(param_1 + 0x140);
  if ((undefined8 *)(param_1 + 0x140) != puVar2) {
    puVar3 = (undefined8 *)*puVar2;
    do {
      nvswitch_i2c_del_adapter(puVar2[2]);
      __list_del_entry(puVar2);
      *puVar2 = 0xdead000000000100;
      puVar2[1] = 0xdead000000000122;
      _nvswitch_os_free(puVar2);
      bVar4 = puVar3 != (undefined8 *)(param_1 + 0x140);
      puVar2 = puVar3;
      puVar3 = (undefined8 *)*puVar3;
    } while (bVar4);
  }
  nvswitch_lib_disable_interrupts(*(undefined8 *)(param_1 + 0x50));
  lVar1 = *(long *)(param_1 + 0x100);
  free_irq(*(undefined4 *)(lVar1 + 0x3ec),param_1);
  if (*(char *)(param_1 + 0x138) == '\x02') {
    pci_disable_msi(lVar1);
  }
  nvswitch_lib_shutdown_device(*(undefined8 *)(param_1 + 0x50));
  nvswitch_lib_unregister_device(*(undefined8 *)(param_1 + 0x50));
  *(undefined8 *)(param_1 + 0x50) = 0;
  return;
}


// ===== 00529cf0 nvswitch_deinit_device =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00529d9d) */

void nvswitch_deinit_device(long param_1)

{
  long lVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  bool bVar4;
  
  puVar2 = *(undefined8 **)(param_1 + 0x140);
  if ((undefined8 *)(param_1 + 0x140) != puVar2) {
    puVar3 = (undefined8 *)*puVar2;
    do {
      nvswitch_i2c_del_adapter(puVar2[2]);
      __list_del_entry(puVar2);
      *puVar2 = 0xdead000000000100;
      puVar2[1] = 0xdead000000000122;
      _nvswitch_os_free(puVar2);
      bVar4 = puVar3 != (undefined8 *)(param_1 + 0x140);
      puVar2 = puVar3;
      puVar3 = (undefined8 *)*puVar3;
    } while (bVar4);
  }
  nvswitch_lib_disable_interrupts(*(undefined8 *)(param_1 + 0x50));
  lVar1 = *(long *)(param_1 + 0x100);
  free_irq(*(undefined4 *)(lVar1 + 0x3ec),param_1);
  if (*(char *)(param_1 + 0x138) == '\x02') {
    pci_disable_msi(lVar1);
  }
  nvswitch_lib_shutdown_device(*(undefined8 *)(param_1 + 0x50));
  nvswitch_lib_unregister_device(*(undefined8 *)(param_1 + 0x50));
  *(undefined8 *)(param_1 + 0x50) = 0;
  return;
}


// ===== 00529da2 nvswitch_remove.cold =====

void nvswitch_remove_cold(void)

{
  long unaff_RBX;
  long in_R10;
  
  _printk(&DAT_00df1728);
  mutex_lock();
  *(undefined1 *)(in_R10 + 0x120) = 1;
  mutex_unlock(in_R10 + 0x38);
  LOCK();
  DAT_0054789c = DAT_0054789c + -1;
  UNLOCK();
  __list_del_entry(in_R10 + 0x110);
  *(undefined8 *)(in_R10 + 0x110) = 0xdead000000000100;
  *(undefined8 *)(in_R10 + 0x118) = 0xdead000000000122;
  nvswitch_deinit_background_tasks(in_R10);
  nvswitch_deinit_device(in_R10);
  *(undefined8 *)(unaff_RBX + 0x148) = 0;
  pci_iounmap();
  pci_release_regions();
  pci_clear_master();
  pci_disable_device();
  nvswitch_procfs_device_remove(in_R10);
  if (*(int *)(in_R10 + 0x108) == 0) {
    kfree(in_R10);
  }
  mutex_unlock(&DAT_005478a0);
  return;
}


// ===== 00529ea5 nvswitch_task_dispatch.cold =====

void nvswitch_task_dispatch_cold(void)

{
  long in_GS_OFFSET;
  long in_stack_00000028;
  
  if (in_stack_00000028 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    _printk(&DAT_00df1758);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00529edb nvswitch_device_unlocked_ioctl.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012fa43) */

long nvswitch_device_unlocked_ioctl_cold(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  ulong uVar4;
  long unaff_RBX;
  uint unaff_EBP;
  long unaff_R13;
  long in_GS_OFFSET;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  long in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  
  _printk(&DAT_00df1628);
  in_stack_00000010 = 0;
  in_stack_00000018 = 0;
  iVar3 = nvswitch_ioctl_state_start(&stack0x00000010,unaff_EBP);
  uVar2 = in_stack_00000018;
  uVar1 = in_stack_00000010;
  if (iVar3 == 0) {
    iVar3 = nvswitch_lib_ctrl(*(undefined8 *)(unaff_RBX + 0x50),unaff_EBP & 0xff,in_stack_00000010,
                              in_stack_00000018,*(undefined8 *)(unaff_R13 + 0x18));
    uVar4 = 0;
    do {
      if ((iVar3 == (&nvswitch_status_map)[uVar4 * 2]) ||
         ((&nvswitch_status_map)[uVar4 * 2] == -iVar3)) {
        iVar3 = *(int *)(&DAT_005a6fa4 + (uVar4 & 0xffffffff) * 8);
        if (iVar3 == 0) {
          iVar3 = nvswitch_ioctl_state_sync_isra_0(uVar1,uVar2,unaff_EBP);
        }
        goto LAB_0012fa93;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 != 0xc);
    iVar3 = -5;
LAB_0012fa93:
    kfree(uVar1);
  }
  mutex_unlock(unaff_RBX + 0x38);
  if (in_stack_00000020 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return (long)iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00529f1c nvswitch_ctl_unlocked_ioctl.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012fba2) */

long nvswitch_ctl_unlocked_ioctl_cold(void)

{
  int iVar1;
  undefined8 in_R9;
  long in_GS_OFFSET;
  long in_stack_00000030;
  
  _printk(&DAT_00df17f8);
  iVar1 = nvswitch_ioctl_state_sync_isra_0(in_R9);
  kfree(in_R9);
  mutex_unlock(&DAT_005478a0);
  if (in_stack_00000030 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return (long)iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00529f40 nvswitch_probe.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ff52) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int nvswitch_probe_cold(void)

{
  char *__s;
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined8 *puVar6;
  char *__s_00;
  long lVar7;
  long lVar8;
  long lVar9;
  long unaff_RBX;
  undefined4 uVar10;
  ulong uVar11;
  long in_GS_OFFSET;
  undefined8 in_stack_00000010;
  uint uStack0000000000000018;
  long in_stack_00000020;
  
  _printk(&DAT_00df1840,**(undefined4 **)(*(long *)(unaff_RBX + 0x10) + 200),
          *(undefined1 *)(*(long *)(unaff_RBX + 0x10) + 0xd8),
          *(uint *)(unaff_RBX + 0x38) >> 3 & 0x1f,*(uint *)(unaff_RBX + 0x38) & 7,
          *(undefined2 *)(unaff_RBX + 0x3c),*(undefined2 *)(unaff_RBX + 0x3e),
          *(undefined4 *)(unaff_RBX + 0x44));
  mutex_lock(&DAT_005478a0);
  uVar11 = 0;
  while (iVar4 = (int)uVar11, puVar6 = DAT_005478b8, (undefined8 **)DAT_005478b8 != &DAT_005478b8) {
    while (*(int *)(puVar6 + -0x1e) != iVar4) {
      puVar6 = (undefined8 *)*puVar6;
      if ((undefined8 **)puVar6 == &DAT_005478b8) goto LAB_00529feb;
    }
    uVar11 = (ulong)(iVar4 + 1U);
    if (iVar4 + 1U == 0x40) goto code_r0x00529fbf;
  }
LAB_00529feb:
  __s_00 = (char *)__kmalloc_cache_noprof(_trace_event_buffer_reserve,0xdc0,0x150);
  if (__s_00 == (char *)0x0) {
    iVar3 = -0xc;
    goto LAB_00529fc4;
  }
  mutex_init_generic(__s_00 + 0x38);
  __init_waitqueue_head(__s_00 + 0x58,"&nvswitch_dev->wait_q_errors",&nvswitch);
  __init_waitqueue_head(__s_00 + 0xe8,"&nvswitch_dev->wait_q_shutdown",&nvswitch);
  snprintf(__s_00,0x14,"nvidia-nvswitch%d",uVar11);
  __s = __s_00 + 0x14;
  snprintf(__s,10,"nvswi%d",uVar11);
  iVar3 = pci_enable_device();
  if (iVar3 != 0) {
    _printk(&DAT_00df18c8,__s_00,iVar3);
    goto LAB_0052a0ad;
  }
  pci_set_master();
  iVar3 = pci_request_regions();
  if (iVar3 != 0) {
    _printk(&DAT_00df18f0,__s_00,iVar3);
    goto LAB_0052a0f3;
  }
  lVar7 = pci_iomap();
  *(long *)(__s_00 + 0x70) = lVar7;
  if (lVar7 == 0) {
    _printk(&DAT_00df1920,__s_00,0xfffffff4);
    iVar3 = -0xc;
    goto LAB_0052a139;
  }
  pcVar1 = __s_00 + 0x140;
  lVar7 = *(long *)(unaff_RBX + 0x10);
  *(int *)(__s_00 + 0x20) = iVar4;
  *(char **)(__s_00 + 0x140) = pcVar1;
  *(char **)(__s_00 + 0x148) = pcVar1;
  uVar5 = *(uint *)(unaff_RBX + 0x38);
  *(long *)(__s_00 + 0x100) = unaff_RBX;
  iVar4 = nvswitch_lib_register_device
                    (**(undefined2 **)(lVar7 + 200),*(undefined1 *)(lVar7 + 0xd8),uVar5 >> 3 & 0x1f,
                     uVar5 & 7);
  if (iVar4 != 0) {
    _printk(&DAT_00df1948,__s_00,iVar4);
    iVar3 = -0x13;
    goto LAB_0052a1ca;
  }
  _uStack0000000000000018 = 0;
  lVar7 = *(long *)(__s_00 + 0x100);
  in_stack_00000010._4_4_ = 0;
  nvswitch_lib_get_device_info(*(undefined8 *)(__s_00 + 0x50),&stack0x00000018);
  *(undefined4 *)(_uStack0000000000000018 + 0x30) = 0x10;
  pci_read_config_dword(lVar7,0x10,(long)&stack0x00000010 + 4);
  *(ulong *)(_uStack0000000000000018 + 0x18) = (ulong)in_stack_00000010._4_4_ & 0xfffffffffffffff0;
  if ((*(byte *)(lVar7 + 0x408) & 4) != 0) {
    pci_read_config_dword
              (lVar7,*(int *)(_uStack0000000000000018 + 0x30) + 4,(long)&stack0x00000010 + 4);
    *(ulong *)(_uStack0000000000000018 + 0x18) =
         *(ulong *)(_uStack0000000000000018 + 0x18) | (ulong)in_stack_00000010._4_4_ << 0x20;
  }
  lVar8 = *(long *)(lVar7 + 0x3f0);
  *(long *)(_uStack0000000000000018 + 0x20) = lVar8;
  lVar9 = 0;
  if (*(long *)(lVar7 + 0x3f8) != 0) {
    lVar9 = (*(long *)(lVar7 + 0x3f8) + 1) - lVar8;
  }
  *(long *)(_uStack0000000000000018 + 0x28) = lVar9;
  *(undefined8 *)(_uStack0000000000000018 + 0x38) = *(undefined8 *)(__s_00 + 0x70);
  iVar4 = nvswitch_lib_initialize_device(*(undefined8 *)(__s_00 + 0x50));
  if (iVar4 == 0) {
    nvswitch_lib_get_uuid(*(undefined8 *)(__s_00 + 0x50),__s_00 + 0x24);
    iVar4 = nvswitch_lib_get_bios_version(*(undefined8 *)(__s_00 + 0x50));
    if (iVar4 != 0) {
      __s_00[0x128] = '\0';
      __s_00[0x129] = '\0';
      __s_00[0x12a] = '\0';
      __s_00[299] = '\0';
      __s_00[300] = '\0';
      __s_00[0x12d] = '\0';
      __s_00[0x12e] = '\0';
      __s_00[0x12f] = '\0';
    }
    iVar4 = nvswitch_lib_get_physid(*(undefined8 *)(__s_00 + 0x50),__s_00 + 0x124);
    if (iVar4 != 0) {
      __s_00[0x124] = -1;
      __s_00[0x125] = -1;
      __s_00[0x126] = -1;
      __s_00[0x127] = -1;
    }
    lVar7 = *(long *)(__s_00 + 0x100);
    _uStack0000000000000018 = 0;
    cVar2 = pci_find_capability(lVar7,0x11);
    if (cVar2 != '\0') {
      LOCK();
      _uStack0000000000000018 = _uStack0000000000000018 | 2;
      UNLOCK();
    }
    cVar2 = pci_find_capability(lVar7,5);
    if (cVar2 != '\0') {
      LOCK();
      _uStack0000000000000018 = _uStack0000000000000018 | 4;
      UNLOCK();
    }
    iVar4 = nvswitch_lib_use_pin_irq(*(undefined8 *)(__s_00 + 0x50));
    if (iVar4 != 0) {
      LOCK();
      _uStack0000000000000018 = _uStack0000000000000018 | 8;
      UNLOCK();
    }
    __s_00[0x138] = '\0';
    if ((_uStack0000000000000018 & 4) == 0) {
LAB_0052a3db:
      if ((_uStack0000000000000018 & 8) != 0) {
        __s_00[0x138] = '\x03';
        _printk(&DAT_00db0801,__s_00);
        if (__s_00[0x138] != '\0') {
          uVar10 = 0x80;
          goto LAB_0052a49b;
        }
      }
      _printk(&DAT_00df1998,__s_00);
      if ((_uStack0000000000000018 & 2) != 0) {
        _printk(&DAT_00db0816,__s_00);
      }
      if ((_uStack0000000000000018 & 4) != 0) {
        _printk(&DAT_00db0823,__s_00);
      }
      if ((_uStack0000000000000018 & 8) != 0) {
        _printk(&DAT_00db082e,__s_00);
      }
      iVar3 = -0x16;
    }
    else {
      iVar4 = pci_enable_msi(*(undefined8 *)(__s_00 + 0x100));
      if (iVar4 == 0) {
        __s_00[0x138] = '\x02';
        _printk(&DAT_00db07f0,__s_00);
      }
      uVar10 = 0;
      if (__s_00[0x138] == '\0') goto LAB_0052a3db;
LAB_0052a49b:
      iVar3 = request_threaded_irq
                        (*(undefined4 *)(lVar7 + 0x3ec),nvswitch_isr_pending,nvswitch_isr_thread,
                         uVar10,__s,__s_00);
      if (iVar3 == 0) {
        cVar2 = nvswitch_is_device_blacklisted(__s_00);
        if (cVar2 == '\0') {
          nvswitch_lib_enable_interrupts(*(undefined8 *)(__s_00 + 0x50));
        }
        else {
          _printk(&DAT_00df19e8,__s_00);
        }
        cVar2 = nvswitch_is_device_blacklisted(__s_00);
        if (cVar2 != '\0') {
          nvswitch_lib_post_init_blacklist_device(*(undefined8 *)(__s_00 + 0x50));
          goto LAB_0052a520;
        }
        mutex_lock(__s_00 + 0x38);
        _uStack0000000000000018 = _uStack0000000000000018 & 0xffffffff00000000;
        cVar2 = nvswitch_lib_is_i2c_supported(*(undefined8 *)(__s_00 + 0x50));
        if (cVar2 == '\0') goto LAB_0052a5ae;
        iVar4 = nvswitch_lib_get_valid_ports_mask(*(undefined8 *)(__s_00 + 0x50),&stack0x00000018);
        if (iVar4 != 0) {
          _printk(&DAT_00df1a10);
          goto LAB_0052a5e7;
        }
        if (uStack0000000000000018 != 0) {
          iVar4 = 0;
          uVar5 = uStack0000000000000018;
          while( true ) {
            for (; (uVar5 & 1) == 0; uVar5 = uVar5 >> 1) {
              iVar4 = iVar4 + 1;
            }
            lVar7 = nvswitch_i2c_add_adapter(__s_00,iVar4);
            if (lVar7 != 0) {
              lVar8 = _nvswitch_os_malloc(0x18);
              if (lVar8 == 0) {
                _printk(&DAT_00df1a38);
                nvswitch_i2c_del_adapter(lVar7);
              }
              else {
                *(long *)(lVar8 + 0x10) = lVar7;
                __list_add(lVar8,*(undefined8 *)(__s_00 + 0x148),pcVar1);
              }
            }
            uVar5 = uVar5 >> 1;
            if (uVar5 == 0) break;
            iVar4 = iVar4 + 1;
          }
        }
LAB_0052a5ae:
        iVar4 = nvswitch_lib_post_init_device(*(undefined8 *)(__s_00 + 0x50));
        if (iVar4 == 0) {
          mutex_unlock(__s_00 + 0x38);
LAB_0052a520:
          iVar3 = nv_kthread_q_init(__s_00 + 0x78,__s);
          if (iVar3 == 0) {
            __s_00[0xe0] = '\x01';
            __s_00[0xe1] = '\0';
            __s_00[0xe2] = '\0';
            __s_00[0xe3] = '\0';
            nv_kthread_q_item_init(__s_00 + 0xc0,nvswitch_task_dispatch,__s_00);
            iVar4 = nv_kthread_q_schedule_q_item(__s_00 + 0x78,__s_00 + 0xc0);
            if (iVar4 != 0) {
              *(char **)(unaff_RBX + 0x148) = __s_00;
              nvswitch_procfs_device_add(__s_00);
              __list_add(__s_00 + 0x110,_DAT_005478c0,&DAT_005478b8);
              LOCK();
              DAT_0054789c = DAT_0054789c + 1;
              UNLOCK();
              mutex_unlock(&DAT_005478a0);
              goto LAB_0012ff38;
            }
            _printk(&DAT_00df1a88,__s_00);
            nvswitch_deinit_background_tasks(__s_00);
            iVar3 = -0x13;
          }
          else {
            _printk(&DAT_00df1a60,__s_00);
          }
          _printk(&DAT_00df1ab0,__s_00,iVar3);
        }
        else {
LAB_0052a5e7:
          mutex_unlock(__s_00 + 0x38);
          _printk(&DAT_00df1ae8,__s_00,0xffffffed);
          iVar3 = -0x13;
        }
        nvswitch_deinit_device(__s_00);
LAB_0052a1e1:
        pci_iounmap();
LAB_0052a139:
        pci_release_regions();
LAB_0052a0f3:
        pci_clear_master();
        pci_disable_device();
LAB_0052a0ad:
        kfree(__s_00);
        goto LAB_00529fc4;
      }
      if (__s_00[0x138] == '\x02') {
        pci_disable_msi(lVar7);
      }
      _printk(&DAT_00db083d,__s_00);
    }
    _printk(&DAT_00df1b18,__s_00,iVar3);
    nvswitch_lib_shutdown_device(*(undefined8 *)(__s_00 + 0x50));
  }
  else {
    _printk(&DAT_00df1970,__s_00,iVar4);
    iVar3 = -0x13;
  }
  nvswitch_lib_unregister_device(*(undefined8 *)(__s_00 + 0x50));
  __s_00[0x50] = '\0';
  __s_00[0x51] = '\0';
  __s_00[0x52] = '\0';
  __s_00[0x53] = '\0';
  __s_00[0x54] = '\0';
  __s_00[0x55] = '\0';
  __s_00[0x56] = '\0';
  __s_00[0x57] = '\0';
LAB_0052a1ca:
  _printk(&DAT_00df1970,__s_00,iVar3);
  goto LAB_0052a1e1;
code_r0x00529fbf:
  iVar3 = -0x22;
LAB_00529fc4:
  mutex_unlock(&DAT_005478a0);
LAB_0012ff38:
  if (in_stack_00000020 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}


// ===== 0052a759 nvswitch_init.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0052a770) */

undefined8 nvswitch_init_cold(void)

{
  _printk(&DAT_00df1b48);
  return 0xfffffff0;
}


// ===== 0052a805 FUN_0052a805 =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0052a770) */

undefined4 FUN_0052a805(void)

{
  undefined4 in_EAX;
  
  _printk(&DAT_00df1b80);
  return in_EAX;
}


// ===== 0052a8fb nvswitch_os_read_registry_dword.cold =====

void nvswitch_os_read_registry_dword_cold(void)

{
                    /* WARNING: Subroutine does not return */
  __fortify_panic(1,0xb);
}


// ===== 0052a90d nvswitch_os_alloc_contig_memory.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0013076a) */

undefined8 nvswitch_os_alloc_contig_memory_cold(void)

{
  _printk(&DAT_00df1c98);
  return 0xfffffffe;
}


// ===== 0052a923 nvswitch_os_map_dma_region.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001308b9) */

undefined8 nvswitch_os_map_dma_region_cold(void)

{
  _printk(&DAT_00df1d48);
  return 0xfffffff9;
}


// ===== 0052a94c nvswitch_isr_pending.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001310a5) */

undefined8 nvswitch_isr_pending_cold(void)

{
  _printk(&DAT_00df1d80);
  nvswitch_os_assert_log
            ("NVSwitch: Assertion failed in %s() at %s:%d\n","nvswitch_isr_pending",
             "nvidia/linux_nvswitch.c",0x48d);
  return 0;
}


// ===== 0052a9ac nvswitch_i2c_algo_smbus_xfer.cold =====

void nvswitch_i2c_algo_smbus_xfer_cold(void)

{
  _printk(&DAT_00db0973);
  FUN_00131deb();
  return;
}


// ===== 0052a9c0 nvswitch_i2c_algo_master_xfer.cold =====

void nvswitch_i2c_algo_master_xfer_cold(void)

{
  _printk(&DAT_00db0973);
  FUN_00131f4d();
  return;
}


// ===== 0052a9d4 nvswitch_i2c_add_adapter.cold =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00132081) */

undefined8 nvswitch_i2c_add_adapter_cold(void)

{
  _printk(&DAT_00db098e);
  return 0;
}


// ===== 00df3c10 __pfx_cleanup_module =====

void __pfx_cleanup_module(void)

{
  undefined8 uVar1;
  
  uVar1 = __nv_init_sp;
  cdev_del(nv_linux_control_device_cdev);
  unregister_chrdev_region(0xc3000ff,1);
  cdev_del(nv_linux_devices_cdev);
  unregister_chrdev_region(0xc300000,0xf8);
  nv_uvm_exit();
  nv_platform_unregister_driver();
  nv_pci_unregister_driver();
  nv_module_exit(uVar1);
  nv_caps_imex_exit();
  os_nv_cap_destroy_entry(nvidia_caps_root);
  nvidia_caps_root = 0;
  if (NVreg_UseKernelSuspendNotifiers != 0) {
    unregister_pm_notifier(nv_pm_nb);
  }
  nv_procfs_exit();
  nv_memdbg_exit();
  return;
}


// ===== 00df3c20 cleanup_module =====

void cleanup_module(void)

{
  undefined8 uVar1;
  
  uVar1 = __nv_init_sp;
  cdev_del(nv_linux_control_device_cdev);
  unregister_chrdev_region(0xc3000ff,1);
  cdev_del(nv_linux_devices_cdev);
  unregister_chrdev_region(0xc300000,0xf8);
  nv_uvm_exit();
  nv_platform_unregister_driver();
  nv_pci_unregister_driver();
  nv_module_exit(uVar1);
  nv_caps_imex_exit();
  os_nv_cap_destroy_entry(nvidia_caps_root);
  nvidia_caps_root = 0;
  if (NVreg_UseKernelSuspendNotifiers != 0) {
    unregister_pm_notifier(nv_pm_nb);
  }
  nv_procfs_exit();
  nv_memdbg_exit();
  return;
}


// ===== 00df3d60 __pfx_init_module =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00df4487) */

ulong __pfx_init_module(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  long lVar5;
  ulong uVar6;
  long in_GS_OFFSET;
  byte bVar7;
  undefined4 uStack_68;
  undefined4 auStack_64 [9];
  long lStack_40;
  
  bVar7 = 0;
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  os_is_nvswitch_present();
  nv_memdbg_init();
  uVar2 = nv_procfs_init();
  if ((int)uVar2 < 0) {
    uVar6 = (ulong)uVar2;
    nv_printf(4,"NVRM: failed to initialize procfs.\n");
    goto LAB_00df4463;
  }
  if (NVreg_UseKernelSuspendNotifiers == 0) {
LAB_00df3df2:
    nvidia_caps_root = os_nv_cap_init("driver/nvidia");
    if (nvidia_caps_root == 0) {
      uVar6 = 0xfffffffe;
      nv_printf(4,"NVRM: failed to initialize capabilities.\n");
    }
    else {
      uVar2 = nv_caps_imex_init();
      uVar6 = (ulong)uVar2;
      if ((int)uVar2 < 0) {
        nv_printf(4,"NVRM: failed to initialize IMEX channels.\n");
      }
      else {
        puVar4 = auStack_64;
        for (lVar5 = 9; lVar5 != 0; lVar5 = lVar5 + -1) {
          *puVar4 = 0;
          puVar4 = puVar4 + (ulong)bVar7 * -2 + 1;
        }
        uStack_68 = 0;
        nvidia_stack_t_cache = __kmem_cache_create_args("nvidia_stack_cache",0x3000,&uStack_68);
        if (nvidia_stack_t_cache == 0) {
          nv_printf(4,"NVRM: nvidia_stack_t cache allocation failed.\n");
LAB_00df3f2f:
          nv_kmem_cache_free_stack(0);
          if (nvidia_p2p_page_t_cache != 0) {
            kmem_cache_destroy();
          }
          if (nvidia_stack_t_cache != 0) {
            kmem_cache_destroy();
          }
          uVar6 = 0xfffffff4;
        }
        else {
          puVar4 = auStack_64;
          for (lVar5 = 9; lVar5 != 0; lVar5 = lVar5 + -1) {
            *puVar4 = 0;
            puVar4 = puVar4 + (ulong)bVar7 * -2 + 1;
          }
          uStack_68 = 0;
          nvidia_p2p_page_t_cache =
               __kmem_cache_create_args("nvidia_p2p_page_cache",0x20,&uStack_68);
          if (nvidia_p2p_page_t_cache == 0) {
            nv_printf(4,"NVRM: nvidia_p2p_page_t cache allocation failed.\n");
            goto LAB_00df3f2f;
          }
          cVar1 = rm_is_altstack_in_use();
          if (cVar1 == '\0') {
            puVar4 = (undefined4 *)0x0;
          }
          else {
            puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
            if (puVar4 == (undefined4 *)0x0) goto LAB_00df3f2f;
            *puVar4 = 0x2ff0;
            *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
          }
          uVar2 = nv_cap_drv_init();
          uVar6 = (ulong)uVar2;
          if ((int)uVar2 < 0) {
            nv_printf(4,"NVRM: nv-cap-drv init failed.\n");
          }
          else {
            uVar2 = nvlink_core_init();
            uVar6 = (ulong)uVar2;
            if ((int)uVar2 < 0) {
              nv_printf(0,"NVRM: NVLink core init failed.\n");
            }
            else {
              uVar2 = nvswitch_init();
              uVar6 = (ulong)uVar2;
              if (-1 < (int)uVar2) {
                nv_init_rsync_info();
                os_cc_sme_enabled._4_1_ = cc_platform_has(2);
                os_cc_sme_enabled._3_1_ = cc_platform_has(5);
                os_cc_sme_enabled._0_1_ = cc_platform_has(0);
                iVar3 = hv_get_isolation_type();
                if (iVar3 == 2) {
                  os_cc_sme_enabled._2_1_ = 1;
                }
                uVar6 = FUN_00df47e5();
                return uVar6;
              }
              nv_printf(0,"NVRM: NVSwitch init failed.\n");
              nvlink_core_exit();
            }
          }
          nv_cap_drv_exit();
          nv_module_resources_exit(puVar4);
        }
        nv_printf(4,"NVRM: failed to initialize module.\n");
        nv_caps_imex_exit();
      }
      os_nv_cap_destroy_entry(nvidia_caps_root);
      nvidia_caps_root = 0;
    }
    if (NVreg_UseKernelSuspendNotifiers != 0) {
      unregister_pm_notifier(nv_pm_nb);
    }
  }
  else {
    uVar2 = register_pm_notifier(nv_pm_nb);
    uVar6 = (ulong)uVar2;
    if (uVar2 == 0) goto LAB_00df3df2;
    nv_printf(4,"NVRM: Failed to register PM notifier\n");
  }
  nv_procfs_exit();
LAB_00df4463:
  if (lStack_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}


// ===== 00df3d70 init_module =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00df4487) */

ulong init_module(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  long lVar5;
  ulong uVar6;
  long in_GS_OFFSET;
  byte bVar7;
  undefined4 local_68;
  undefined4 local_64 [9];
  long local_40;
  
  bVar7 = 0;
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  os_is_nvswitch_present();
  nv_memdbg_init();
  uVar2 = nv_procfs_init();
  if ((int)uVar2 < 0) {
    uVar6 = (ulong)uVar2;
    nv_printf(4,"NVRM: failed to initialize procfs.\n");
    goto LAB_00df4463;
  }
  if (NVreg_UseKernelSuspendNotifiers == 0) {
LAB_00df3df2:
    nvidia_caps_root = os_nv_cap_init("driver/nvidia");
    if (nvidia_caps_root == 0) {
      uVar6 = 0xfffffffe;
      nv_printf(4,"NVRM: failed to initialize capabilities.\n");
    }
    else {
      uVar2 = nv_caps_imex_init();
      uVar6 = (ulong)uVar2;
      if ((int)uVar2 < 0) {
        nv_printf(4,"NVRM: failed to initialize IMEX channels.\n");
      }
      else {
        puVar4 = local_64;
        for (lVar5 = 9; lVar5 != 0; lVar5 = lVar5 + -1) {
          *puVar4 = 0;
          puVar4 = puVar4 + (ulong)bVar7 * -2 + 1;
        }
        local_68 = 0;
        nvidia_stack_t_cache = __kmem_cache_create_args("nvidia_stack_cache",0x3000,&local_68);
        if (nvidia_stack_t_cache == 0) {
          nv_printf(4,"NVRM: nvidia_stack_t cache allocation failed.\n");
LAB_00df3f2f:
          nv_kmem_cache_free_stack(0);
          if (nvidia_p2p_page_t_cache != 0) {
            kmem_cache_destroy();
          }
          if (nvidia_stack_t_cache != 0) {
            kmem_cache_destroy();
          }
          uVar6 = 0xfffffff4;
        }
        else {
          puVar4 = local_64;
          for (lVar5 = 9; lVar5 != 0; lVar5 = lVar5 + -1) {
            *puVar4 = 0;
            puVar4 = puVar4 + (ulong)bVar7 * -2 + 1;
          }
          local_68 = 0;
          nvidia_p2p_page_t_cache = __kmem_cache_create_args("nvidia_p2p_page_cache",0x20,&local_68)
          ;
          if (nvidia_p2p_page_t_cache == 0) {
            nv_printf(4,"NVRM: nvidia_p2p_page_t cache allocation failed.\n");
            goto LAB_00df3f2f;
          }
          cVar1 = rm_is_altstack_in_use();
          if (cVar1 == '\0') {
            puVar4 = (undefined4 *)0x0;
          }
          else {
            puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
            if (puVar4 == (undefined4 *)0x0) goto LAB_00df3f2f;
            *puVar4 = 0x2ff0;
            *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
          }
          uVar2 = nv_cap_drv_init();
          uVar6 = (ulong)uVar2;
          if ((int)uVar2 < 0) {
            nv_printf(4,"NVRM: nv-cap-drv init failed.\n");
          }
          else {
            uVar2 = nvlink_core_init();
            uVar6 = (ulong)uVar2;
            if ((int)uVar2 < 0) {
              nv_printf(0,"NVRM: NVLink core init failed.\n");
            }
            else {
              uVar2 = nvswitch_init();
              uVar6 = (ulong)uVar2;
              if (-1 < (int)uVar2) {
                nv_init_rsync_info();
                os_cc_sme_enabled._4_1_ = cc_platform_has(2);
                os_cc_sme_enabled._3_1_ = cc_platform_has(5);
                os_cc_sme_enabled._0_1_ = cc_platform_has(0);
                iVar3 = hv_get_isolation_type();
                if (iVar3 == 2) {
                  os_cc_sme_enabled._2_1_ = 1;
                }
                uVar6 = FUN_00df47e5();
                return uVar6;
              }
              nv_printf(0,"NVRM: NVSwitch init failed.\n");
              nvlink_core_exit();
            }
          }
          nv_cap_drv_exit();
          nv_module_resources_exit(puVar4);
        }
        nv_printf(4,"NVRM: failed to initialize module.\n");
        nv_caps_imex_exit();
      }
      os_nv_cap_destroy_entry(nvidia_caps_root);
      nvidia_caps_root = 0;
    }
    if (NVreg_UseKernelSuspendNotifiers != 0) {
      unregister_pm_notifier(nv_pm_nb);
    }
  }
  else {
    uVar2 = register_pm_notifier(nv_pm_nb);
    uVar6 = (ulong)uVar2;
    if (uVar2 == 0) goto LAB_00df3df2;
    nv_printf(4,"NVRM: Failed to register PM notifier\n");
  }
  nv_procfs_exit();
LAB_00df4463:
  if (local_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}


// ===== 00df4490 __pfx_nvlink_core_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00df46ca) */

int __pfx_nvlink_core_init(void)

{
  int iVar1;
  
  if (nvlink_drvctx[0x18] == '\x01') {
    nvlink_print("nvidia/nvlink_linux.c",0x141,"nvlink_core_init",4,
                 "nvlink core interface already initialized\n");
    return -0x10;
  }
  mutex_init_generic(nvlink_drvctx);
  iVar1 = nvlink_lib_initialize();
  if (iVar1 != 0) {
    nvlink_print("nvidia/nvlink_linux.c",0x14a,"nvlink_core_init",4,
                 "Failed to initialize driver : %d\n",iVar1);
    return -0x13;
  }
  iVar1 = alloc_chrdev_region(0x547788,0,1,"nvidia-nvlink");
  if (iVar1 < 0) {
    nvlink_print("nvidia/nvlink_linux.c",0x153,"nvlink_core_init",4,
                 "alloc_chrdev_region failed: %d\n",iVar1);
    goto LAB_00df4679;
  }
  nvlink_drvctx._144_4_ = (uint)nvlink_drvctx._136_4_ >> 0x14;
  nvlink_print("nvidia/nvlink_linux.c",0x158,"nvlink_core_init",0,
               "Nvlink Core is being initialized, major device number %d\n");
  cdev_init(0x547720,nvlink_fops);
  nvlink_drvctx._96_8_ = __this_module;
  iVar1 = cdev_add(0x547720,nvlink_drvctx._136_4_,1);
  if (iVar1 < 0) {
    nvlink_print("nvidia/nvlink_linux.c",0x160,"nvlink_core_init",4," Unable to create cdev\n");
  }
  else {
    nvlink_procfs_dir = proc_mkdir_mode("driver/nvidia-nvlink",0x416d,0);
    if (nvlink_procfs_dir == 0) {
LAB_00df4658:
      iVar1 = -0xd;
    }
    else {
      nvlink_permissions =
           proc_create_data("permissions",0x8124,nvlink_procfs_dir,nv_procfs_permissions_fops,0);
      if (nvlink_permissions == 0) {
        nvlink_procfs_exit();
        goto LAB_00df4658;
      }
      iVar1 = nvlink_cap_init("driver/nvidia-nvlink");
      if (-1 < iVar1) {
        nvlink_drvctx[0x18] = 1;
        return 0;
      }
      nvlink_print("nvidia/nvlink_linux.c",0x16d,"nvlink_core_init",4,
                   " Unable to create capability\n");
      nvlink_procfs_exit();
    }
    cdev_del(0x547720);
  }
  unregister_chrdev_region(nvlink_drvctx._136_4_,1);
LAB_00df4679:
  nvlink_lib_unload();
  return iVar1;
}


// ===== 00df44a0 nvlink_core_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00df46ca) */

int nvlink_core_init(void)

{
  int iVar1;
  
  if (nvlink_drvctx[0x18] == '\x01') {
    nvlink_print("nvidia/nvlink_linux.c",0x141,"nvlink_core_init",4,
                 "nvlink core interface already initialized\n");
    return -0x10;
  }
  mutex_init_generic(nvlink_drvctx);
  iVar1 = nvlink_lib_initialize();
  if (iVar1 != 0) {
    nvlink_print("nvidia/nvlink_linux.c",0x14a,"nvlink_core_init",4,
                 "Failed to initialize driver : %d\n",iVar1);
    return -0x13;
  }
  iVar1 = alloc_chrdev_region(0x547788,0,1,"nvidia-nvlink");
  if (iVar1 < 0) {
    nvlink_print("nvidia/nvlink_linux.c",0x153,"nvlink_core_init",4,
                 "alloc_chrdev_region failed: %d\n",iVar1);
    goto LAB_00df4679;
  }
  nvlink_drvctx._144_4_ = (uint)nvlink_drvctx._136_4_ >> 0x14;
  nvlink_print("nvidia/nvlink_linux.c",0x158,"nvlink_core_init",0,
               "Nvlink Core is being initialized, major device number %d\n");
  cdev_init(0x547720,nvlink_fops);
  nvlink_drvctx._96_8_ = __this_module;
  iVar1 = cdev_add(0x547720,nvlink_drvctx._136_4_,1);
  if (iVar1 < 0) {
    nvlink_print("nvidia/nvlink_linux.c",0x160,"nvlink_core_init",4," Unable to create cdev\n");
  }
  else {
    nvlink_procfs_dir = proc_mkdir_mode("driver/nvidia-nvlink",0x416d,0);
    if (nvlink_procfs_dir == 0) {
LAB_00df4658:
      iVar1 = -0xd;
    }
    else {
      nvlink_permissions =
           proc_create_data("permissions",0x8124,nvlink_procfs_dir,nv_procfs_permissions_fops,0);
      if (nvlink_permissions == 0) {
        nvlink_procfs_exit();
        goto LAB_00df4658;
      }
      iVar1 = nvlink_cap_init("driver/nvidia-nvlink");
      if (-1 < iVar1) {
        nvlink_drvctx[0x18] = 1;
        return 0;
      }
      nvlink_print("nvidia/nvlink_linux.c",0x16d,"nvlink_core_init",4,
                   " Unable to create capability\n");
      nvlink_procfs_exit();
    }
    cdev_del(0x547720);
  }
  unregister_chrdev_region(nvlink_drvctx._136_4_,1);
LAB_00df4679:
  nvlink_lib_unload();
  return iVar1;
}


// ===== 00df47e5 FUN_00df47e5 =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00df4487) */

int FUN_00df47e5(void)

{
  code *pcVar1;
  uint uVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  undefined8 unaff_RBP;
  undefined1 *puVar9;
  uint uVar10;
  char unaff_R13B;
  long in_GS_OFFSET;
  bool bVar11;
  byte bVar12;
  long in_stack_00000028;
  
  bVar12 = 0;
  if ((DAT_00f790e2 & 0x40) != 0) {
    os_cc_sme_enabled._1_1_ = 1;
  }
  cVar4 = rm_init_rm();
  if (cVar4 == '\0') {
    iVar6 = -5;
    nv_printf(4,"NVRM: rm_init_rm() failed!\n");
LAB_00df4054:
    nv_destroy_rsync_info();
    nvswitch_exit();
    nvlink_core_exit();
    nv_cap_drv_exit();
    nv_module_resources_exit();
    nv_printf(4,"NVRM: failed to initialize module.\n");
  }
  else {
    nv_ctl_device._8_8_ = nv_ctl_device;
    cVar4 = nv_lock_init_locks();
    if (cVar4 == '\0') {
      iVar6 = -0xc;
LAB_00df4456:
      rm_shutdown_rm();
      goto LAB_00df4054;
    }
    iVar6 = nv_kthread_q_init(nv_kthread_q,"nv_queue");
    if ((iVar6 == 0) && (iVar6 = nv_init_page_pools(), iVar6 == 0)) {
      iVar6 = nv_kthread_q_init(nv_deferred_close_kthread_q);
      if (iVar6 != 0) {
        nv_kthread_q_stop(nv_kthread_q);
        goto LAB_00df41f6;
      }
      iVar6 = nv_init_pat_support();
      if (iVar6 < 0) {
        nv_kthread_q_stop(nv_deferred_close_kthread_q);
        nv_kthread_q_stop(nv_kthread_q);
        goto LAB_00df41fe;
      }
      nv_linux_devices = 0;
      puVar9 = &nv_linux_minor_bitmap;
      for (lVar8 = 0x1f; lVar8 != 0; lVar8 = lVar8 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + (ulong)bVar12 * -2 + 1;
      }
      nv_linux_devices_lock._8_8_ = 0;
      nv_linux_devices_lock._16_8_ = 0;
      nv_linux_devices_lock._0_8_ = 0x100000000;
      __init_rwsem(nv_system_pm_lock,"&nv_system_pm_lock",&persistence_mode_notice_logged_5);
      nv_system_power_state_lock._0_8_ = 0x100000000;
      nv_system_power_state_lock._8_8_ = 0;
      nv_system_power_state_lock._16_8_ = 0;
      nv_system_power_state = 2;
      nv_system_pm_action_depth = 0;
      nv_ctl_device._20872_4_ = 0;
    }
    else {
LAB_00df41f6:
      if (iVar6 < 0) {
LAB_00df41fe:
        nv_destroy_page_pools();
        rm_destroy_event_locks();
        goto LAB_00df4456;
      }
    }
    iVar6 = nv_pci_count_devices();
    iVar5 = nv_platform_count_devices();
    bVar11 = unaff_R13B != '\0';
    uVar10 = iVar6 + iVar5;
    if ((uVar10 != 0) || (bVar11)) {
      iVar6 = nv_uvm_init();
      if (iVar6 == 0) {
        iVar7 = rm_read_registry_dword();
        if (iVar7 == 0) {
          nv_dma_remap_peer_mmio = 0;
        }
        iVar7 = nv_pci_register_driver();
        if (iVar7 < 0) {
          nv_printf(4,"NVRM: No NVIDIA PCI devices found.\n");
LAB_00df426b:
          iVar6 = -0x13;
        }
        else {
          iVar7 = nv_platform_register_driver();
          uVar2 = num_probed_nv_devices;
          if (iVar7 < 0) {
            nv_printf(4,"NVRM: SOC driver registration failed!\n");
            nv_pci_unregister_driver();
            goto LAB_00df426b;
          }
          if (uVar10 < num_probed_nv_devices) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)invalidInstructionException();
            (*pcVar1)();
          }
          if (iVar5 < 1) {
LAB_00df437b:
            if (uVar2 != uVar10) {
LAB_00df4384:
              nv_printf(4,"NVRM: The NVIDIA probe routine was not called for %d device(s).\n",
                        uVar10 - num_probed_nv_devices);
              nv_printf(4,
                        "NVRM: This can occur when another driver was loaded and \nNVRM: obtained ownership of the NVIDIA device(s).\n"
                       );
              nv_printf(4,
                        "NVRM: Try unloading the conflicting kernel module (and/or\nNVRM: reconfigure your kernel without the conflicting\nNVRM: driver(s)), then try loading the NVIDIA kernel module\nNVRM: again.\n"
                       );
            }
          }
          else {
            nv_printf(3,"NVRM: Failed to probe Tegra Display platform device.\n");
            nv_printf(3,"NVRM: This kernel is not compatible with Tegra Display.\n");
            if (uVar10 <= num_probed_nv_devices) goto LAB_00df437b;
            if (uVar10 - num_probed_nv_devices != iVar5) goto LAB_00df4384;
          }
          if ((num_probed_nv_devices != 0) || (bVar11)) {
            if (num_probed_nv_devices != num_nv_devices) {
              nv_printf(4,"NVRM: The NVIDIA probe routine failed for %d device(s).\n",
                        num_probed_nv_devices - num_nv_devices);
            }
            if ((num_nv_devices == 0) && (!bVar11)) {
              nv_printf(4,"NVRM: None of the NVIDIA devices were initialized.\n");
              goto LAB_00df4446;
            }
            nv_printf(4,"NVRM: loading %s\n",pNVRM_ID);
            iVar5 = nv_register_chrdev_constprop_0(0,0xf8,nv_linux_devices_cdev,"nvidia");
            if (-1 < iVar5) {
              iVar5 = nv_register_chrdev_constprop_0
                                (0xff,1,nv_linux_control_device_cdev,"nvidiactl");
              uVar3 = unaff_RBP;
              if (-1 < iVar5) goto LAB_00df4463;
              cdev_del(nv_linux_devices_cdev);
              unregister_chrdev_region(0xc300000,0xf8);
            }
          }
          else {
            nv_printf(4,"NVRM: No NVIDIA devices probed.\n");
LAB_00df4446:
            iVar5 = -0x13;
          }
          iVar6 = iVar5;
          nv_platform_unregister_driver();
          nv_pci_unregister_driver();
        }
        nv_uvm_exit();
      }
    }
    else {
      iVar6 = -0x13;
      nv_printf(4,"NVRM: No NVIDIA GPU found.\n");
    }
    nv_module_exit();
  }
  nv_caps_imex_exit();
  os_nv_cap_destroy_entry(nvidia_caps_root);
  nvidia_caps_root = 0;
  if (NVreg_UseKernelSuspendNotifiers != 0) {
    unregister_pm_notifier(nv_pm_nb);
  }
  nv_procfs_exit();
  uVar3 = __nv_init_sp;
LAB_00df4463:
  __nv_init_sp = uVar3;
  if (in_stack_00000028 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return iVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00df5e40 __SCT__tp_func_nvidia_dev_xid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122bdd) */

undefined8
__SCT__tp_func_nvidia_dev_xid
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  long *plVar1;
  code *pcVar2;
  long lVar3;
  long *plVar4;
  
  plVar4 = (long *)__tracepoint_nvidia_dev_xid._56_8_;
  lVar3 = __tracepoint_nvidia_dev_xid._56_8_;
  while (lVar3 != 0) {
    pcVar2 = (code *)*plVar4;
    plVar1 = plVar4 + 1;
    plVar4 = plVar4 + 3;
    (*pcVar2)(*plVar1,param_2,param_3,param_4);
    lVar3 = *plVar4;
  }
  return 0;
}


// ===== 00df5e48 __SCT__tp_func_nvswitch_dev_sxid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ed2d) */

undefined8
__SCT__tp_func_nvswitch_dev_sxid
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  long *plVar1;
  code *pcVar2;
  long lVar3;
  long *plVar4;
  
  plVar4 = (long *)__tracepoint_nvswitch_dev_sxid._56_8_;
  lVar3 = __tracepoint_nvswitch_dev_sxid._56_8_;
  while (lVar3 != 0) {
    pcVar2 = (code *)*plVar4;
    plVar1 = plVar4 + 1;
    plVar4 = plVar4 + 3;
    (*pcVar2)(*plVar1,param_2,param_3,param_4);
    lVar3 = *plVar4;
  }
  return 0;
}


// ===== 00f79008 pci_iounmap =====

/* WARNING: Control flow encountered bad instruction data */

void pci_iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79010 devm_devfreq_add_device =====

/* WARNING: Control flow encountered bad instruction data */

void devm_devfreq_add_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79020 iterate_fd =====

/* WARNING: Control flow encountered bad instruction data */

void iterate_fd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79028 free_pages =====

/* WARNING: Control flow encountered bad instruction data */

void free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79030 refcount_warn_saturate =====

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79038 cdev_init =====

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79040 __init_rwsem =====

/* WARNING: Control flow encountered bad instruction data */

void __init_rwsem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79050 single_open =====

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79058 get_dev_pagemap =====

/* WARNING: Control flow encountered bad instruction data */

void get_dev_pagemap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79060 pci_restore_state =====

/* WARNING: Control flow encountered bad instruction data */

void pci_restore_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79068 pci_enable_atomic_ops_to_root =====

/* WARNING: Control flow encountered bad instruction data */

void pci_enable_atomic_ops_to_root(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79070 release_firmware =====

/* WARNING: Control flow encountered bad instruction data */

void release_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79078 sg_alloc_table =====

/* WARNING: Control flow encountered bad instruction data */

void sg_alloc_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79080 device_destroy =====

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79088 dev_pm_opp_remove =====

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79098 __x86_indirect_thunk_r10 =====

/* WARNING: This is an inlined function */
/* WARNING: Control flow encountered bad instruction data */

void __x86_indirect_thunk_r10(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f790a0 gpiod_to_irq =====

/* WARNING: Control flow encountered bad instruction data */

void gpiod_to_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f790a8 devfreq_suspend_device =====

/* WARNING: Control flow encountered bad instruction data */

void devfreq_suspend_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f790b0 module_put =====

/* WARNING: Control flow encountered bad instruction data */

void module_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f790b8 register_chrdev_region =====

/* WARNING: Control flow encountered bad instruction data */

void register_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f790d8 dev_pm_domain_set =====

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_domain_set(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f790e8 __list_del_entry_valid_or_report =====

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid_or_report(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f790f0 hrtimer_start_range_ns =====

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_start_range_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f790f8 down_read_trylock =====

/* WARNING: Control flow encountered bad instruction data */

void down_read_trylock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79100 vmalloc_noprof =====

/* WARNING: Control flow encountered bad instruction data */

void vmalloc_noprof(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79108 ioremap_cache =====

/* WARNING: Control flow encountered bad instruction data */

void ioremap_cache(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79118 __kmem_cache_create_args =====

/* WARNING: Control flow encountered bad instruction data */

void __kmem_cache_create_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79120 iommu_sva_get_pasid =====

/* WARNING: Control flow encountered bad instruction data */

void iommu_sva_get_pasid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79128 kvasprintf =====

/* WARNING: Control flow encountered bad instruction data */

void kvasprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79130 crypto_shash_import =====

/* WARNING: Control flow encountered bad instruction data */

void crypto_shash_import(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79138 mutex_unlock =====

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79140 vmf_insert_pfn_prot =====

/* WARNING: Control flow encountered bad instruction data */

void vmf_insert_pfn_prot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79148 fput =====

/* WARNING: Control flow encountered bad instruction data */

void fput(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79150 __release_region =====

/* WARNING: Control flow encountered bad instruction data */

void __release_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79158 set_pages_array_wb =====

/* WARNING: Control flow encountered bad instruction data */

void set_pages_array_wb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79160 pci_write_config_byte =====

/* WARNING: Control flow encountered bad instruction data */

void pci_write_config_byte(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79168 __printk_ratelimit =====

/* WARNING: Control flow encountered bad instruction data */

void __printk_ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79170 mutex_init_generic =====

/* WARNING: Control flow encountered bad instruction data */

void mutex_init_generic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79178 mutex_lock_interruptible =====

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock_interruptible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79180 memcpy =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79188 pci_get_domain_bus_and_slot =====

/* WARNING: Control flow encountered bad instruction data */

void pci_get_domain_bus_and_slot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79190 vmap =====

/* WARNING: Control flow encountered bad instruction data */

void vmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79198 init_wait_entry =====

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f791a0 devm_ioremap =====

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f791a8 iounmap =====

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f791b8 platform_driver_unregister =====

/* WARNING: Control flow encountered bad instruction data */

void platform_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f791c0 __SCT__WARN_trap =====

/* WARNING: Control flow encountered bad instruction data */

void __SCT__WARN_trap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f791d0 vga_set_legacy_decoding =====

/* WARNING: Control flow encountered bad instruction data */

void vga_set_legacy_decoding(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f791d8 pci_disable_device =====

/* WARNING: Control flow encountered bad instruction data */

void pci_disable_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f791e8 __folio_put =====

/* WARNING: Control flow encountered bad instruction data */

void __folio_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f791f0 pci_rebar_get_possible_sizes =====

/* WARNING: Control flow encountered bad instruction data */

void pci_rebar_get_possible_sizes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f791f8 _raw_spin_unlock_irq =====

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79200 dma_buf_attach =====

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_attach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79210 crypto_shash_tfm_digest =====

/* WARNING: Control flow encountered bad instruction data */

void crypto_shash_tfm_digest(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79218 clk_enable =====

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79220 bpf_trace_run3 =====

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79228 cancel_delayed_work_sync =====

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79230 pcie_capability_read_word =====

/* WARNING: Control flow encountered bad instruction data */

void pcie_capability_read_word(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79238 i2c_add_adapter =====

/* WARNING: Control flow encountered bad instruction data */

void i2c_add_adapter(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79248 pci_get_class =====

/* WARNING: Control flow encountered bad instruction data */

void pci_get_class(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79250 cdev_add =====

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79258 clk_set_rate =====

/* WARNING: Control flow encountered bad instruction data */

void clk_set_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79260 __x86_indirect_thunk_r15 =====

/* WARNING: This is an inlined function */
/* WARNING: Control flow encountered bad instruction data */

void __x86_indirect_thunk_r15(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79270 __virt_addr_valid =====

/* WARNING: Control flow encountered bad instruction data */

void __virt_addr_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79278 dma_buf_detach =====

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_detach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79280 down_read =====

/* WARNING: Control flow encountered bad instruction data */

void down_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79288 timer_init_key =====

/* WARNING: Control flow encountered bad instruction data */

void timer_init_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79290 get_task_pid =====

/* WARNING: Control flow encountered bad instruction data */

void get_task_pid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79298 gpiod_direction_input =====

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_input(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f792a0 pm_vt_switch_unregister =====

/* WARNING: Control flow encountered bad instruction data */

void pm_vt_switch_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f792a8 dmi_get_system_info =====

/* WARNING: Control flow encountered bad instruction data */

void dmi_get_system_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f792b0 offline_and_remove_memory =====

/* WARNING: Control flow encountered bad instruction data */

void offline_and_remove_memory(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f792b8 __x86_indirect_thunk_rdx =====

/* WARNING: This is an inlined function */
/* WARNING: Control flow encountered bad instruction data */

void __x86_indirect_thunk_rdx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f792c0 cachemode2protval =====

/* WARNING: Control flow encountered bad instruction data */

void cachemode2protval(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f792d8 __SCT__preempt_schedule =====

/* WARNING: Control flow encountered bad instruction data */

void __SCT__preempt_schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f792e0 strcasecmp =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcasecmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f792e8 dma_set_mask =====

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f792f8 __alloc_pages_noprof =====

/* WARNING: Control flow encountered bad instruction data */

void __alloc_pages_noprof(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79300 capable =====

/* WARNING: Control flow encountered bad instruction data */

void capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79308 __init_swait_queue_head =====

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79310 crypto_aead_setkey =====

/* WARNING: Control flow encountered bad instruction data */

void crypto_aead_setkey(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79318 trace_event_buffer_reserve =====

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79320 devm_clk_bulk_get_all =====

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_bulk_get_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79328 __pci_register_driver =====

/* WARNING: Control flow encountered bad instruction data */

void __pci_register_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79330 prepare_to_wait_event =====

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79338 seq_read =====

/* WARNING: Control flow encountered bad instruction data */

void seq_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79340 acpi_install_notify_handler =====

/* WARNING: Control flow encountered bad instruction data */

void acpi_install_notify_handler(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79350 crypto_alloc_sig =====

/* WARNING: Control flow encountered bad instruction data */

void crypto_alloc_sig(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79358 strncmp =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79360 dma_buf_unmap_attachment =====

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_unmap_attachment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79368 set_memory_uc =====

/* WARNING: Control flow encountered bad instruction data */

void set_memory_uc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79370 remove_proc_entry =====

/* WARNING: Control flow encountered bad instruction data */

void remove_proc_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79378 proc_mkdir_mode =====

/* WARNING: Control flow encountered bad instruction data */

void proc_mkdir_mode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79390 pci_write_config_dword =====

/* WARNING: Control flow encountered bad instruction data */

void pci_write_config_dword(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79398 pcie_reset_flr =====

/* WARNING: Control flow encountered bad instruction data */

void pcie_reset_flr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f793a0 __check_object_size =====

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f793a8 acpi_remove_notify_handler =====

/* WARNING: Control flow encountered bad instruction data */

void acpi_remove_notify_handler(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f793b0 drm_gem_object_free =====

/* WARNING: Control flow encountered bad instruction data */

void drm_gem_object_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f793b8 pci_read_config_dword =====

/* WARNING: Control flow encountered bad instruction data */

void pci_read_config_dword(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f793c0 strlen =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f793c8 vm_insert_page =====

/* WARNING: Control flow encountered bad instruction data */

void vm_insert_page(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f793d0 devm_clk_get =====

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f793d8 remap_pfn_range =====

/* WARNING: Control flow encountered bad instruction data */

void remap_pfn_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f793e0 crypto_destroy_tfm =====

/* WARNING: Control flow encountered bad instruction data */

void crypto_destroy_tfm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f793e8 find_vma_intersection =====

/* WARNING: Control flow encountered bad instruction data */

void find_vma_intersection(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f793f0 sg_alloc_table_from_pages_segment =====

/* WARNING: Control flow encountered bad instruction data */

void sg_alloc_table_from_pages_segment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f793f8 up_write =====

/* WARNING: Control flow encountered bad instruction data */

void up_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79400 __x86_indirect_thunk_r11 =====

/* WARNING: This is an inlined function */
/* WARNING: Control flow encountered bad instruction data */

void __x86_indirect_thunk_r11(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79408 device_create =====

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79410 __SCT__might_resched =====

/* WARNING: Control flow encountered bad instruction data */

void __SCT__might_resched(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79418 trace_handle_return =====

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79420 is_vmalloc_addr =====

/* WARNING: Control flow encountered bad instruction data */

void is_vmalloc_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79428 crypto_ecdh_shared_secret =====

/* WARNING: Control flow encountered bad instruction data */

void crypto_ecdh_shared_secret(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79430 perf_trace_buf_alloc =====

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79438 pci_enable_device =====

/* WARNING: Control flow encountered bad instruction data */

void pci_enable_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79440 crypto_alloc_aead =====

/* WARNING: Control flow encountered bad instruction data */

void crypto_alloc_aead(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79448 pci_set_master =====

/* WARNING: Control flow encountered bad instruction data */

void pci_set_master(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79450 snprintf =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79458 pci_dev_put =====

/* WARNING: Control flow encountered bad instruction data */

void pci_dev_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79460 __kmalloc_cache_noprof =====

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc_cache_noprof(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79468 single_release =====

/* WARNING: Control flow encountered bad instruction data */

void single_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79470 jiffies_to_timespec64 =====

/* WARNING: Control flow encountered bad instruction data */

void jiffies_to_timespec64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79478 set_memory_decrypted =====

/* WARNING: Control flow encountered bad instruction data */

void set_memory_decrypted(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79488 __vma_start_write =====

/* WARNING: Control flow encountered bad instruction data */

void __vma_start_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79490 __kvmalloc_node_noprof =====

/* WARNING: Control flow encountered bad instruction data */

void __kvmalloc_node_noprof(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79498 dev_pm_opp_add_dynamic =====

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_add_dynamic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f794a0 queue_delayed_work_on =====

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f794a8 proc_create_data =====

/* WARNING: Control flow encountered bad instruction data */

void proc_create_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f794b0 mpi_read_buffer =====

/* WARNING: Control flow encountered bad instruction data */

void mpi_read_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f794b8 ecc_digits_from_bytes =====

/* WARNING: Control flow encountered bad instruction data */

void ecc_digits_from_bytes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f794c0 rb_insert_color =====

/* WARNING: Control flow encountered bad instruction data */

void rb_insert_color(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f794c8 dev_set_name =====

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f794d0 set_normalized_timespec64 =====

/* WARNING: Control flow encountered bad instruction data */

void set_normalized_timespec64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f794d8 mod_timer =====

/* WARNING: Control flow encountered bad instruction data */

void mod_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f794e0 __init_waitqueue_head =====

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f794f0 pci_read_config_byte =====

/* WARNING: Control flow encountered bad instruction data */

void pci_read_config_byte(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f794f8 pci_write_config_word =====

/* WARNING: Control flow encountered bad instruction data */

void pci_write_config_word(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79500 trace_raw_output_prep =====

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79508 dma_buf_export =====

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_export(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79510 ktime_get_raw_ts64 =====

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_raw_ts64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79518 pci_assign_unassigned_bus_resources =====

/* WARNING: Control flow encountered bad instruction data */

void pci_assign_unassigned_bus_resources(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79520 cc_platform_has =====

/* WARNING: Control flow encountered bad instruction data */

void cc_platform_has(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79528 completion_done =====

/* WARNING: Control flow encountered bad instruction data */

void completion_done(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79530 shrinker_alloc =====

/* WARNING: Control flow encountered bad instruction data */

void shrinker_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79538 task_active_pid_ns =====

/* WARNING: Control flow encountered bad instruction data */

void task_active_pid_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79540 __SCT__preempt_schedule_notrace =====

/* WARNING: Control flow encountered bad instruction data */

void __SCT__preempt_schedule_notrace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79548 iov_iter_kvec =====

/* WARNING: Control flow encountered bad instruction data */

void iov_iter_kvec(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79550 kfree_sensitive =====

/* WARNING: Control flow encountered bad instruction data */

void kfree_sensitive(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79558 dev_driver_string =====

/* WARNING: Control flow encountered bad instruction data */

void dev_driver_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79560 strsep =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79568 acpi_evaluate_object =====

/* WARNING: Control flow encountered bad instruction data */

void acpi_evaluate_object(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79570 timer_delete_sync =====

/* WARNING: Control flow encountered bad instruction data */

void timer_delete_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79578 cpufreq_get =====

/* WARNING: Control flow encountered bad instruction data */

void cpufreq_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79580 hrtimer_setup =====

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_setup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79588 get_random_bytes =====

/* WARNING: Control flow encountered bad instruction data */

void get_random_bytes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79590 __fortify_panic =====

/* WARNING: Control flow encountered bad instruction data */

void __fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79598 gpio_free =====

/* WARNING: Control flow encountered bad instruction data */

void gpio_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f795a0 set_memory_wb =====

/* WARNING: Control flow encountered bad instruction data */

void set_memory_wb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f795a8 pci_request_regions =====

/* WARNING: Control flow encountered bad instruction data */

void pci_request_regions(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f795b8 update_devfreq =====

/* WARNING: Control flow encountered bad instruction data */

void update_devfreq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f795c0 strncat =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strncat(char *__dest,char *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f795c8 __request_region =====

/* WARNING: Control flow encountered bad instruction data */

void __request_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f795d0 __stack_chk_fail =====

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f795d8 device_property_read_u64_array =====

/* WARNING: Control flow encountered bad instruction data */

void device_property_read_u64_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f795e0 acpi_walk_namespace =====

/* WARNING: Control flow encountered bad instruction data */

void acpi_walk_namespace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f795e8 dump_stack =====

/* WARNING: Control flow encountered bad instruction data */

void dump_stack(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f795f0 clk_disable =====

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f795f8 shrinker_free =====

/* WARNING: Control flow encountered bad instruction data */

void shrinker_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79610 _raw_spin_unlock_irqrestore =====

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79618 kvfree =====

/* WARNING: Control flow encountered bad instruction data */

void kvfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79620 complete =====

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79628 pci_read_config_word =====

/* WARNING: Control flow encountered bad instruction data */

void pci_read_config_word(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79630 __pm_runtime_disable =====

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79638 crypto_aead_decrypt =====

/* WARNING: Control flow encountered bad instruction data */

void crypto_aead_decrypt(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79640 dev_pm_genpd_suspend =====

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_genpd_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79648 __platform_driver_register =====

/* WARNING: Control flow encountered bad instruction data */

void __platform_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79650 memory_block_size_bytes =====

/* WARNING: Control flow encountered bad instruction data */

void memory_block_size_bytes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79658 kthread_should_stop =====

/* WARNING: Control flow encountered bad instruction data */

void kthread_should_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79660 dev_pm_genpd_resume =====

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_genpd_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79668 __fentry__ =====

/* WARNING: This is an inlined function */
/* WARNING: Control flow encountered bad instruction data */

void __fentry__(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79670 ecc_is_pubkey_valid_full =====

/* WARNING: Control flow encountered bad instruction data */

void ecc_is_pubkey_valid_full(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79678 down_write_trylock =====

/* WARNING: Control flow encountered bad instruction data */

void down_write_trylock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79680 kmem_cache_destroy =====

/* WARNING: Control flow encountered bad instruction data */

void kmem_cache_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79688 _printk =====

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79690 set_page_dirty_lock =====

/* WARNING: Control flow encountered bad instruction data */

void set_page_dirty_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79698 __pm_runtime_use_autosuspend =====

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_use_autosuspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f796a0 close_fd =====

/* WARNING: Control flow encountered bad instruction data */

void close_fd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f796a8 full_name_hash =====

/* WARNING: Control flow encountered bad instruction data */

void full_name_hash(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f796b0 kernel_write =====

/* WARNING: Control flow encountered bad instruction data */

void kernel_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f796b8 ecc_make_pub_key =====

/* WARNING: Control flow encountered bad instruction data */

void ecc_make_pub_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f796c8 pid_vnr =====

/* WARNING: Control flow encountered bad instruction data */

void pid_vnr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f796d0 __dma_sync_single_for_device =====

/* WARNING: Control flow encountered bad instruction data */

void __dma_sync_single_for_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f796e0 __trace_trigger_soft_disabled =====

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f796f0 __const_udelay =====

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f796f8 class_create =====

/* WARNING: Control flow encountered bad instruction data */

void class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79700 _raw_spin_lock =====

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79708 finish_wait =====

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79710 pci_rebar_bytes_to_size =====

/* WARNING: Control flow encountered bad instruction data */

void pci_rebar_bytes_to_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79718 register_pm_notifier =====

/* WARNING: Control flow encountered bad instruction data */

void register_pm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79720 device_register =====

/* WARNING: Control flow encountered bad instruction data */

void device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79728 trace_event_buffer_commit =====

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79730 mpi_free =====

/* WARNING: Control flow encountered bad instruction data */

void mpi_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79738 pci_disable_msix =====

/* WARNING: Control flow encountered bad instruction data */

void pci_disable_msix(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79740 vfree =====

/* WARNING: Control flow encountered bad instruction data */

void vfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79748 dma_set_coherent_mask =====

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79750 __kmalloc_large_noprof =====

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc_large_noprof(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79758 clk_round_rate =====

/* WARNING: Control flow encountered bad instruction data */

void clk_round_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79760 clk_unprepare =====

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79770 public_key_verify_signature =====

/* WARNING: Control flow encountered bad instruction data */

void public_key_verify_signature(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79778 _find_next_bit =====

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79780 fd_install =====

/* WARNING: Control flow encountered bad instruction data */

void fd_install(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79788 __x86_indirect_thunk_r12 =====

/* WARNING: This is an inlined function */
/* WARNING: Control flow encountered bad instruction data */

void __x86_indirect_thunk_r12(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79798 add_memory_driver_managed =====

/* WARNING: Control flow encountered bad instruction data */

void add_memory_driver_managed(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f797a0 up =====

/* WARNING: Control flow encountered bad instruction data */

void up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f797a8 enable_irq =====

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f797b0 pci_disable_msi =====

/* WARNING: Control flow encountered bad instruction data */

void pci_disable_msi(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f797c0 __usecs_to_jiffies =====

/* WARNING: Control flow encountered bad instruction data */

void __usecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f797d0 _copy_to_user =====

/* WARNING: Control flow encountered bad instruction data */

void _copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f797d8 console_lock =====

/* WARNING: Control flow encountered bad instruction data */

void console_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f797e0 gpiod_direction_output_raw =====

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_output_raw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f797e8 sscanf =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f797f8 unregister_acpi_notifier =====

/* WARNING: Control flow encountered bad instruction data */

void unregister_acpi_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 00f79800 __udelay =====

/* WARNING: Control flow encountered bad instruction data */

void __udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


